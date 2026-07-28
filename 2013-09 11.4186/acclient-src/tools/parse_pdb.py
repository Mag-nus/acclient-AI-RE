#   parse_pdb.py [acclient.pdb] [workdir]
#
# acclient.pdb is user-provided and is not in the repository; it defaults to the
# 11.4186 folder beside acclient.c.  workdir holds the intermediate dumps and
# defaults to this directory.
#
# dir.pkl and mods.pkl are INPUTS, produced by the earlier MSF-header and DBI
# module-list parsing stage.  That stage lived in a scratchpad that no longer
# exists, so it must be re-done before this script can run; the consumer of the
# whole pipeline, tools/pdb_symbols.pkl, is already checked in and split_acclient.py
# needs only that.
import struct, pickle, os, sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, os.pardir, os.pardir))   # the 11.4186 folder

PATH = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, "acclient.pdb")
SP   = sys.argv[2] if len(sys.argv) > 2 else HERE

for f in (PATH, os.path.join(SP,'dir.pkl'), os.path.join(SP,'mods.pkl')):
    if not os.path.exists(f):
        sys.exit("missing input: %s" % f)

data = open(PATH,'rb').read()
d = pickle.load(open(os.path.join(SP,'dir.pkl'),'rb'))
bs = d['bs']; streams = d['streams']
def block(i): return data[i*bs:(i+1)*bs]
def stream(i):
    if i in (0xFFFF, -1) or i >= len(streams): return b''
    s, idxs = streams[i]
    return b''.join(block(j) for j in idxs)[:s]

mods = pickle.load(open(os.path.join(SP,'mods.pkl'),'rb'))

# section headers stream 9
sh = stream(9)
sections = []
for o in range(0, len(sh), 40):
    if o+40 > len(sh): break
    name = sh[o:o+8].rstrip(b'\0').decode('latin1')
    vsize, vaddr, rawsize, rawptr = struct.unpack_from('<IIII', sh, 8+o)
    chars, = struct.unpack_from('<I', sh, o+36)
    sections.append((name, vaddr, vsize, chars))
print("SECTIONS:")
for i,s in enumerate(sections):
    print(" ", i+1, s[0], "VA=0x%x"%(0x400000+s[1]), "vsize=0x%x"%s[2], "chars=0x%x"%s[3])

def va(seg, off):
    if seg-1 < len(sections):
        return 0x400000 + sections[seg-1][1] + off
    return None

S_GPROC32=0x1110; S_LPROC32=0x1111; S_GPROC32_16t=0x0205; S_LPROC32_16t=0x0204
S_GDATA32=0x110d; S_LDATA32=0x110c; S_PUB32=0x110e
S_THUNK32=0x1102; S_LABEL32=0x1105
S_GPROC32_ST=0x1009; S_LPROC32_ST=0x100a
S_BPREL32=0x110b
S_FRAMEPROC=0x1012
S_CALLEES=0x115a; S_CALLERS=0x115b; S_CALLSITEINFO=0x1139

funcs = []   # (va, len, name, modidx, dbgstart, dbgend)
callgraph = {}
tot_c13 = 0
misc = {}
for mi, (modstream, symsz, c11sz, c13sz, mname, oname) in enumerate(mods):
    tot_c13 += c13sz
    if modstream in (0xFFFF,) or symsz <= 4: continue
    ss = stream(modstream)
    sig = struct.unpack_from('<I', ss, 0)[0]
    p = 4
    endp = min(symsz, len(ss))
    cur = None
    while p + 4 <= endp:
        ln, kind = struct.unpack_from('<HH', ss, p)
        if ln < 2: break
        rec = ss[p+4:p+2+ln]
        if kind in (S_GPROC32, S_LPROC32) and len(rec) >= 36:
            pP,pE,pN, plen, dbgs, dbge, typ, off, seg, flg = struct.unpack_from('<IIIIIIIIHB', rec, 0)
            e = rec.index(b'\0', 35)
            nm = rec[35:e].decode('latin1')
            a = va(seg, off)
            funcs.append((a, plen, nm, mi, dbgs, dbge))
            cur = a
        elif kind == S_CALLEES or kind == S_CALLERS:
            cnt, = struct.unpack_from('<I', rec, 0)
            ids = struct.unpack_from('<%dI'%cnt, rec, 4)
            callgraph.setdefault(cur, []).append((kind, ids))
        misc[kind] = misc.get(kind,0)+1
        p += ln + 2
print("total c13 line bytes:", tot_c13)
print("num funcs from modules:", len(funcs))
print("callgraph recs:", len(callgraph))
print("record kinds:", sorted(((v,hex(k)) for k,v in misc.items()), reverse=True)[:25])
pickle.dump((funcs, sections), open(os.path.join(SP,'funcs.pkl'),'wb'))
