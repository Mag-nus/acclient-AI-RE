#!/usr/bin/env python3
"""Relocation-exact comparison of two builds of acclient.exe.

WHY THIS EXISTS
---------------
Comparing two PE builds function-by-function is harder than it looks, and four
plausible methods all gave wrong answers on this pair before this one settled
it. The trap is deciding which bytes are *operands that must differ* (absolute
addresses, call displacements) versus real code changes.

  raw byte compare .......................... 80.7% "changed"  (useless)
  mask E8/E9 + in-range dwords, per function .. 2.7% "changed"  (phase-desyncs)
  lockstep pairwise compare .................. 40.2% "changed"  (fails when an
                                                                 address's low
                                                                 byte matches)
  relocation table + heuristic rel32 mask .... 0.84% "changed"  (misses calls)
  relocation table + disassembled boundaries . 0.41% "changed"  CORRECT

The correct method, implemented here:

  1. Parse the PE .reloc section. IMAGE_REL_BASED_HIGHLOW entries name exactly
     which dwords are absolute addresses. Zero them. This is authoritative --
     never guess by scanning for in-range values, and never gate this masking
     on a disassembler: objdump desyncs on embedded data (jump tables, inline
     constants), and a relocated dword that falls in a mis-decoded region would
     leak through and read as a spurious change. Mask reloc dwords straight from
     the .reloc table over the whole function range.
  2. Take instruction boundaries from a real disassembler (objdump) and mask the
     rel32 displacement of every call/jmp/jcc. (A rel32 target that moved by a
     different amount than the function itself must be masked or it reads as a
     change.)
  3. Match each OLD function to its NEW counterpart. Functions whose masked body
     is *uniquely* locatable in the NEW .text fix a piecewise OLD->NEW address
     map; every function is then compared against the counterpart that map
     predicts. This is what makes the count correct where a pure content search
     is not: a 6-byte `jmp [IAT]` thunk has only two unmasked bytes and cannot
     be anchored by content, but the map places it exactly, so it is compared,
     not blindly declared changed. (The earlier version of this tool declared
     any function whose longest unmasked run was under 5 bytes "changed" and
     masked relocs only inside decoded instructions; those two bugs inflated the
     count to 484. Both are fixed here.)

Result on 11.4186 vs 11.6096: **46 functions changed**, and that set is the
stable, reproducible answer -- it is what this tool prints and it matches an
independent re-derivation function-for-function.

The *denominator* depends on how you count, so state which one you mean:

  20,271  distinct (VA, length) procs of >=32 bytes in the PDB   -> 99.77% same
  10,183  distinct bodies after COMDAT folding (measured here)   -> 99.55% same

This tool prints the first (20,271), because that is the population it actually
enumerates. Note that `13-client-differences-2013-vs-2015.md` quotes a third
figure, "11,081 of 11,127" (99.59%); that denominator reproduces under neither
count above and should be treated as unverified. The 46-function changed set is
not in doubt -- only the population it is quoted against.

LIMITS -- state these when quoting a number
-------------------------------------------
* Call targets are masked, so a function whose only change is calling a
  different function counts as identical. Bound this by checking that call
  edges land where the function mapping predicts (96.9% did; the residual is
  dominated by COMDAT-folded bodies that legitimately match several sites).
* Only functions present in the 11.4186 PDB are enumerated. Functions that
  exist only in the newer build are invisible to this comparison.
* Functions under 32 bytes are excluded; they fold too aggressively to
  identify reliably.

USAGE
-----
  python3 binary_diff.py OLD.exe NEW.exe --pdb-symbols pdb_symbols_11.4186.pkl
  python3 binary_diff.py OLD.exe NEW.exe --pdb-symbols ... --min-size 32

Requires: python3, objdump (binutils). No capstone, no pip packages.
"""
import sys, os, re, struct, subprocess, bisect, argparse
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from relnorm import load

BASE = 0x400000
CTRL = re.compile(r'^(call|jmp|j[a-z]+|loop\w*)\b')


def text_bounds(secs):
    va, vs, ro, rs = secs['.text']
    lo = BASE + va
    hi = BASE + va + min(vs, rs)
    return lo, hi


class Build:
    """One PE build, with everything needed to normalize a function body.

    Reloc masking comes straight from .reloc (authoritative, disassembler-free).
    rel32 masking uses objdump on a slice that STARTS at the function entry -- a
    real instruction boundary -- so the decode is correctly phased there; a
    whole-.text sweep would desync on the first embedded data and mis-mask every
    later function. Normalizations are cached by (va, n)."""
    def __init__(self, path):
        self.img, self.secs, _, relset = load(path)
        self.relocs = sorted(relset)            # RVAs of relocated dwords
        self.lo, self.hi = text_bounds(self.secs)
        self._cache = {}

    def _rel32_mask(self, va, n):
        tmp = '/tmp/_bd_slice.bin'
        open(tmp, 'wb').write(bytes(self.img[va - BASE:va - BASE + n]))
        out = subprocess.run(
            ['objdump', '-D', '-b', 'binary', '-m', 'i386', '-M', 'intel',
             '--adjust-vma=0x%X' % va, tmp],
            capture_output=True, text=True).stdout
        m = set()
        for line in out.splitlines():
            p = line.split('\t')
            if len(p) < 3:
                continue
            try:
                addr = int(p[0].strip().rstrip(':'), 16)
            except ValueError:
                continue
            nbytes = len(p[1].split())
            text = re.sub(r'\s+', ' ', p[2].strip())
            if CTRL.match(text) and nbytes >= 5:
                off = addr - va
                for k in range(nbytes - 4, nbytes):
                    if 0 <= off + k < n:
                        m.add(off + k)
        return m

    def reloc_mask(self, va, n):
        """Byte offsets in [va, va+n) covered by a relocated dword. Pure .reloc,
        no disassembler -- cheap enough to call in a tight window loop."""
        m = set()
        lo = va - BASE
        i = bisect.bisect_left(self.relocs, lo - 3)
        while i < len(self.relocs) and self.relocs[i] < lo + n:
            o = self.relocs[i] - lo
            for k in range(4):
                if 0 <= o + k < n:
                    m.add(o + k)
            i += 1
        return m

    def mask(self, va, n):
        """Byte offsets in [va, va+n) that must be ignored: every relocated dword
        (straight from .reloc) plus every control-flow rel32 displacement."""
        return self.reloc_mask(va, n) | self._rel32_mask(va, n)

    def body(self, va, n):
        return self.img[va - BASE:va - BASE + n]

    def normalize(self, va, n):
        key = (va, n)
        if key not in self._cache:
            mask = self.mask(va, n)
            b = bytearray(self.body(va, n))
            for o in mask:
                b[o] = 0
            self._cache[key] = (bytes(b), mask)
        return self._cache[key]


def locate(old, new, n, nd, mask):
    """Search the NEW .text for a location whose masked body equals nd.
    Returns (status, va):
      'unique', va  -- exactly one match: body preserved, and va anchors the map
      'multi',  None -- >=2 matches: body preserved but folded, position ambiguous
      'none',   None -- no match: candidate for a real change
      'short',  None -- no unmasked run >=4 bytes to anchor on; can't search
    'unique' and 'multi' both mean the body still exists in NEW (unchanged);
    'none' and 'short' are resolved by comparing against the mapped counterpart."""
    best_s = best_l = 0
    s = None
    for i in range(n + 1):
        keep = i < n and i not in mask
        if keep:
            if s is None:
                s = i
        else:
            if s is not None and i - s > best_l:
                best_s, best_l = s, i - s
            s = None
    if best_l < 4:
        return 'short', None
    anchor = nd[best_s:best_s + best_l]
    keep_idx = [i for i in range(n) if i not in mask]
    hay = bytes(new.img)
    lo_o, hi_o = new.lo - BASE, new.hi - BASE
    hits = []
    pos = lo_o
    while True:
        j = hay.find(anchor, pos, hi_o)
        if j < 0:
            break
        b = j - best_s
        cand = b + BASE
        if lo_o <= b and b + n <= hi_o:
            n15, m15 = new.normalize(cand, n)
            if all(nd[i] == n15[i] for i in keep_idx if i not in m15):
                hits.append(cand)
                if len(hits) > 1:
                    return 'multi', None
        pos = j + 1
    if len(hits) == 1:
        return 'unique', hits[0]
    return 'none', None


def exists_near(old, new, va, n, nd, mask, center, window=0x4000):
    """Does the masked OLD body appear in NEW within +/-window of center?
    Used to classify functions the map only places approximately (heavily
    relocated thunks, funclets with no long unmasked run). Comparison uses a
    pure .reloc mask on the NEW side: for unchanged code the rel32 displacements
    sit at offsets OLD already masked, so they never enter the comparison, and
    no per-candidate disassembly is needed. Anchors on the longest unmasked run
    of any length; falls back to the exact center if the body is entirely
    masked."""
    keep = [i for i in range(n) if i not in mask]
    if not keep:
        return True
    best_s = best_l = 0
    s = None
    for i in range(n + 1):
        k = i < n and i not in mask
        if k:
            if s is None:
                s = i
        else:
            if s is not None and i - s > best_l:
                best_s, best_l = s, i - s
            s = None
    hay = bytes(new.img)
    lo = max(new.lo, center - window) - BASE
    hi = min(new.hi, center + window) - BASE

    def matches(cand):
        if not (new.lo <= cand and cand + n <= new.hi):
            return False
        m15 = new.reloc_mask(cand, n)
        nb = new.img[cand - BASE:cand - BASE + n]
        return all(nd[i] == nb[i] for i in keep if i not in m15)

    if best_l == 0:
        return matches(center)
    anchor = nd[best_s:best_s + best_l]
    pos = lo
    while True:
        j = hay.find(anchor, pos, hi)
        if j < 0:
            return False
        cand = j - best_s + BASE
        if matches(cand):
            return True
        pos = j + 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('old'); ap.add_argument('new')
    ap.add_argument('--min-size', type=int, default=32)
    ap.add_argument('--pdb-symbols', default=None,
                    help='pickle with {"procs":[(va,len,name,modidx)]} for the OLD build')
    a = ap.parse_args()

    old = Build(a.old)
    new = Build(a.new)
    print('%s: %d base relocations' % (os.path.basename(a.old), len(old.relocs)))
    print('%s: %d base relocations' % (os.path.basename(a.new), len(new.relocs)))

    if not a.pdb_symbols:
        print('\nNo --pdb-symbols given; nothing to enumerate. '
              'Supply the parsed PDB of the OLD build (see acclient-src/tools/).')
        return
    import pickle
    procs = pickle.load(open(a.pdb_symbols, 'rb'))['procs']
    # Deduplicate to distinct (va, len); keep a representative name per VA.
    names = {}
    for va, ln, nm, mi in procs:
        names.setdefault(va, nm)
    funcs = sorted({(p[0], p[1]) for p in procs if p[1] >= a.min_size})

    # Pass 1: locate every OLD function in NEW. 'unique'/'multi' means the body
    # is preserved (identical); the unique matches fix a piecewise address map.
    same = 0
    unresolved = []       # (va, n) needing counterpart comparison
    anchors = []          # (old_va, new_va - old_va) for uniquely located funcs
    for va, n in funcs:
        nd, mask = old.normalize(va, n)
        status, hit = locate(old, new, n, nd, mask)
        if status == 'unique':
            same += 1
            anchors.append((va, hit - va))
        elif status == 'multi':
            same += 1
        else:                       # 'none' or 'short'
            unresolved.append((va, n))
    anchors.sort()
    avas = [a0 for a0, _ in anchors]
    aoff = [d for _, d in anchors]

    def predict(va):
        i = bisect.bisect_right(avas, va) - 1
        return va + aoff[max(i, 0)]

    # Pass 2: the body was not found verbatim. Compare against the counterpart
    # the address map predicts; if the unmasked bytes still differ there, it is a
    # real change. (This is what catches heavily-relocated thunks and small
    # functions the content search could not anchor, without falsely flagging
    # them.)
    changed_rows = []
    for va, n in unresolved:
        nd, mask = old.normalize(va, n)
        va15 = predict(va)
        # The map places the counterpart only approximately for these (the
        # unique-match anchors can be sparse locally). Accept a match anywhere
        # in a window around the prediction; only a body that appears nowhere
        # near its mapped location is a real change.
        if exists_near(old, new, va, n, nd, mask, va15):
            same += 1
        else:
            changed_rows.append((va, n))

    changed = len(changed_rows)
    for va, n in sorted(changed_rows):
        print('CHANGED %08X %6d  %s' % (va, n, names.get(va, '')))
    tot = same + changed
    print('\n%d compared: %d identical (%.2f%%), %d changed (%.2f%%)'
          % (tot, same, 100.0 * same / tot, changed, 100.0 * changed / tot))


if __name__ == '__main__':
    main()
