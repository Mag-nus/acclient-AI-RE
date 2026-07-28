# Encryption, Decryption, and Obfuscation — Complete Catalogue

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

This document collects every transform in the client that conceals, scrambles,
authenticates, compresses, or hashes data, with reproducible formulas. Material
here is also referenced from `02-networking.md`, `04-combat-magic.md`, and
`07-dat-resources.md`; this is the authoritative version.

---

## 0. Summary

**There are exactly two concealment systems in this client**, and they protect
very different things:

| System | Purpose | Strength |
|---|---|---|
| **ISAAC-keyed checksum XOR** (§2.4) | packet integrity / casual tamper resistance | one 32-bit word per packet; effective key space **32 bits** |
| **Spell-formula obfuscation** (§3) | stop players sharing spell component lists | three stacked layers, per-account; not cryptographic |

Everything else is ordinary: arithmetic checksums, zlib, varint packing,
presence-mask serialization, PJW hashes, and an L'Ecuyer PRNG.

**Nothing protects confidentiality.** Credentials travel in cleartext (§2.6),
both ISAAC seeds are transmitted in the clear (§2.6), and the Diffie-Hellman
exchange that would have protected them is **not implemented** (§2.5). No packet
payload is ever encrypted.

Three claims in this document were independently re-derived numerically or read
directly rather than taken from a single source: the ELF-hash modulus
degeneracy (§3.2), the `vlong` method inventory (§2.5), and the `randrsl[]`
zeroing (§2.3).

---

## 1. Checksums

### 1.1 `PortalChecksum::CalcChecksum32` — acclient.c:629839

The only member of `PortalChecksum`; there is no 16-bit or other variant.

```
CalcChecksum32(data, size) -> uint32:
    if data == NULL: return 0
    sum  = size << 16                       # SEED — note the shift
    for k in 0 .. (size >> 2) - 1:
        sum += LE32(data + 4*k)             # wrapping add mod 2^32
    tail = 0
    j = 3                                   # descending
    for p in 4*(size >> 2) .. size-1:
        tail += ZEXT8(data[p]) << (8 * j)   # 24, then 16, then 8
        j -= 1
    return (sum + tail) mod 2^32
```

Two subtleties:

- The seed is `size << 16`, not `size`. For a 20-byte header that is `0x00140000`.
- **Bytes are zero-extended, not sign-extended.** The 2013 decompilation prints
  `*i++ << 8*j--` with `i` typed `const char*`, which reads as signed — that is a
  typing artifact from the imported prototype. Both other decompilations recover
  the actual `movzx`: `acclient 6.95.16808.c:622121` and
  `../../2015-10 11.6096/acclient 6.6.14.605 Diffed.c:614117`. This matters for
  any byte ≥ 0x80.

### 1.2 `SharedNet::ChecksumHeader` — the `0xBADD70DD` substitution

acclient.c:369083. `ProtoHeader` is 20 bytes (acclient.h:34520): `seqID_`,
`header_`, `checksum_`, `recID_`, `interval_`, `datalen_`, `iteration_`.

```
ChecksumHeader(H):
    tmp = copy of H                     # 20-byte stack copy
    tmp.checksum_ = 0xBADD70DD          # acclient.c:369101 (-1159892771)
    return CalcChecksum32(&tmp, 0x14)
```

Since 20 is a multiple of 4 there are no trailing bytes, so it has a closed form:

```
ChecksumHeader(H) = 0xBAF170DD                              # 0x00140000 + 0xBADD70DD
                  + H.seqID_ + H.header_
                  + (H.recID_   | (H.interval_  << 16))
                  + (H.datalen_ | (H.iteration_ << 16))     mod 2^32
```

**Why the substitution exists:** it makes the result independent of the current
value of the checksum field, which is what lets one routine be used additively on
send and subtractively on receive over the same bytes. It is a self-cancelling
delta, not a secret — `0xBADD70DD` is a fixed literal ("BAD 70 DD", a joke).

- Send (acclient.c:369247): `checksum_ += ChecksumHeader(hdr)`
- Receive (acclient.c:369987): `checksum_ -= ChecksumHeader(hdr)`

After subtraction the residual is the body-only checksum, compared at
acclient.c:370677; mismatch drops the packet.

**This is error detection, not a MAC.** Every input is attacker-visible except
the single ISAAC word of §2.4.

### 1.3 `NetPacket::ComputeChecksum` — acclient.c:376684

```
ComputeChecksum(pkt):
    pkt.checksum_ = 0
    pkt.flags_ &= ~0x1                                  # clear npfChecksumEncrypted
    for oh in pkt.specialFragList_[0 .. numSpecialFrags_-1]:   # optional headers
        pkt.checksum_ += CalcChecksum32(oh.m_pData, oh.m_cbData)
    for f in pkt.fragList_[0 .. numFrags_-1]:                  # blob fragments
        pkt.checksum_ += CalcChecksum32(f.hdrRead_, 0x10)
        pkt.checksum_ += CalcChecksum32(f.dat_, f.hdrRead_.blobFragSize - 16)
```

Optional headers contribute on equal footing with fragment data — no ordering
scramble, no per-header keying. Note `m_dwMask` and `m_Flags` are *not*
checksummed; the mask reaches the wire via `ApplySpecialFrags` OR-ing it into
`header_` (acclient.c:376737), and `header_` *is* covered by §1.2.

On receive this function is never called — the same sum is built incrementally by
`NetPacket::AddOptionalHeader` (376846) and `NetPacket::AddFrag` (376960/376961)
using identical formulas, so the two directions are symmetric by construction.

---

## 2. Network cryptography

### 2.1 What is actually encrypted

**One 32-bit word per packet: the header checksum field. Nothing else.** No
payload, no optional header, no credential, no blob fragment.

### 2.2 ISAAC-32 — the generator

`QTIsaac<8, unsigned long>` is Bob Jenkins' ISAAC, faithfully implemented, with
`RANDSIZL = 8` and `RANDSIZ = 256`. State is `randctx` (acclient.h:34768):
`{randcnt, *randrsl, *randmem, randa, randb, randc}`, with `randrsl` and
`randmem` each `operator new[](0x400)` = 256 words (acclient.c:629942–629943).

**`shuffle` (reference `mix()`)** — acclient.c:630089, byte-for-byte standard:

```
a ^= b << 11;   d += a;   b += c
b ^= c >>  2;   e += b;   c += d
c ^= d <<  8;   f += c;   d += e
d ^= e >> 16;   g += d;   e += f
e ^= f << 10;   h += e;   f += g
f ^= g >>  4;   a += f;   g += h
g ^= h <<  8;   b += g;   h += a
h ^= a >>  9;   c += h;   a += b
```

**`randinit`** — acclient.c:629964, golden ratio `0x9E3779B9` at 629989–629996:

```
randinit(ctx, bUseSeed):
    a..h = 0x9E3779B9
    if not bUseSeed: randa = randb = randc = 0
    repeat 4: mix(a..h)
    if bUseSeed:
        for i in 0,8,..,248: a+=randrsl[i+0] .. h+=randrsl[i+7]; mix(); randmem[i+0..7]=a..h
        for i in 0,8,..,248: a+=randmem[i+0] .. h+=randmem[i+7]; mix(); randmem[i+0..7]=a..h
    isaac(ctx)
    randcnt = 256
```

**`isaac`** — acclient.c:630184, standard, unrolled 4× with the barrel-shift
cycle `a<<13`, `a>>6`, `a<<2`, `a>>16` (630236, 630245, 630255, 630266), and
`ind(x) = *(uint32*)((uint8*)randmem + (x & 0x3FC))`. No altered constants, no
extra XOR.

### 2.3 The seeding collapses the key space to 32 bits

This is the most important finding in this document.

`CryptoSystem::CryptoSystem(seed)` (acclient.c:630161) constructs
`QTIsaac(seed, seed, seed)` — the same value three times. The `QTIsaac`
constructor (629933) then does, verified by direct read of
acclient.c:629945–629960:

```
randrsl = new uint32[256]; randmem = new uint32[256]
for i in 0..255: randrsl[i] = 0          # <-- SEED ARRAY ZEROED
randa = a; randb = b; randc = c          # all three == seed
randinit(&m_rc, /*bUseSeed=*/1)
```

In reference ISAAC, `randinit(true)` derives state from `randrsl[]` and never
reads `randa/randb/randc`. Here `randrsl[]` is **all zeros**, so:

- `randmem[]` after `randinit` is a **fixed universal table**, identical for every
  connection regardless of seed.
- The seed enters the generator **only** through `randa/randb/randc`, consumed by
  the single `isaac()` call at the end of `randinit` — which begins with
  `a = seed`, `c = seed + 1`, `b = 2*seed + 1`.

**Effective key space is 32 bits, not the 8192 bits ISAAC's state implies.** Two
connections sharing a seed produce identical keystreams.

`QTIsaac::srand` (629881) would have seeded properly but is **dead** — no call
sites; it exists only as vtable slot 2.

### 2.4 Keystream consumption and `EncryptData`

`GetNextCryptoSeed` — acclient.c:630355:

```
GetNextCryptoSeed(iteration):        # `iteration` is never read
    lastIter_ += 1                   # written, never read
    v = randcnt; randcnt = v - 1
    if v != 0: return randrsl[v - 1]
    else: isaac(); randcnt = 255; return randrsl[255]
```

One word per call, drawn **downward** from `randrsl[255]` to `[0]`, then the pool
refills. Exactly 256 words per `isaac()` run, no duplication or skipping across
the boundary.

`CryptoSystem::EncryptData` — acclient.c:630381:

```
EncryptData(iteration, data, size, pEncryptSeed) -> uint32:
    key = pEncryptSeed ? *pEncryptSeed          # replay a saved word
                       : GetNextCryptoSeed()    # draw and consume
    for k in 0 .. (size >> 2) - 1:
        ((uint32*)data)[k] ^= key               # SAME word for every dword
    return key
```

The same word is XORed over every dword — no per-word advance, no counter, no
whitening. Trailing `size % 4` bytes are left in cleartext. Encryption and
decryption are the same function; `ReceiverData::Encrypt` (376224) and
`Decrypt` (376230) differ only in which `CryptoSystem` they pass.

**All three call sites pass length 4:**

| Line | Caller | Data |
|---|---|---|
| 372100 | `SharedNet::ProcessNewSeqNum` (recv) | `&pkt->m_Hdr.checksum_` |
| 374455 | `FlowQueue::EncryptChecksum` (send) | local copy of `checksum_` |
| 375159 | `FlowQueue` transmit loop (send) | local copy of `checksum_` |

So the `for` loop never iterates more than once in this binary.

The `pEncryptSeed` path handles retransmits: `ReceiverData::AddNakked`
(acclient.c:376642) pre-draws and stores the key word for each missing seqID in
the `m_SeqIDsWeNAKed` AVL, handing it back when the retransmit arrives
(372090–372100). That is what keeps both endpoints' pools aligned across loss.

Wire gating is `header_ & 0x2`; internally `npfChecksumEncrypted = 0x1` in
`NetPacket::flags_` (acclient.h:4798).

### 2.5 Diffie-Hellman: parameters present, implementation absent

The parameters are real, hardcoded, and 256-bit
(`ClientNet::Init`, acclient.c:373513–373534):

```
shared_base  = 0xdd80c2e508b630998076a9f7319c930d954f2866f53932baa2938467f25ed069
shared_prime = 0xdd80c2e508b630998076a9f7319c930d954f2866f53932baa2938467f2602bfb
```

They are identical in their first 56 nibbles and differ only in the last 8. Note
the naming is inverted from convention — the "base" is nearly as large as the
"prime".

**But no exchange is ever computed.** Four independent lines of evidence:

1. **`PortalDH` has exactly one member.** `PortalDH::Init` (474887) is the only
   `PortalDH::` entry, and its whole body is two `vlong::operator=` calls storing
   base and prime. No `GenerateKey`, no `ComputeSharedSecret`.
2. **The private exponent is the literal 10.**
   `ClientNet::HandleConnectionRequest` (373283–373284) constructs
   `vlong v(0xA)` and passes it to `NetKeyExch::SetPrivateRandom`.
3. **`vlong` cannot do modular exponentiation.** Its complete method list —
   verified directly against `docs/func_index.tsv` — is `vlong`, `~vlong`,
   `operator=`, `read_from_hex_string`, `bit`, `setbit`, `load`, `store`,
   `docopy`, `Pack`, `UnPack`, `GetPackSize`, plus add/multiply/compare helpers.
   **There is no division, no modulo, no `monty`, no modular inverse.** Modular
   exponentiation is arithmetically impossible without a remainder operation.
4. **`NetKeyExch` is inert.** It is constructed (373271), given the constant, and
   stored in `ReceiverData::keyExch_` (376380). Every later reference is a
   destruction. `NetKeyExch::Pack`/`UnPack` (377099/377122) have no call sites.

**Verdict: the shared secret is never computed and never used.** The session keys
arrive in plaintext instead (§2.6).

### 2.6 Credentials and session keys travel in cleartext

`NetAuthenticator::StreamPack` — acclient.c:368098:

```
u32 m_dwAuthType
u32 m_dwAuthFlags
u32 m_dwConnectionSequenceNumber
    m_Account                      # PString + 3 expansion bools
[if m_dwAuthFlags & 0x2: m_AccountToLogonAs]
    m_CryptoData                   # CGrowBuffer — ALWAYS EMPTY
    m_ExtraData                    # CGrowBuffer — the credential, RAW
```

**The `crypto` blob is always empty.** `m_CryptoData` is written only in the
constructor, which zeroes it (367971–367973), and freed in `~Client`. Nothing
ever populates it. (An apparent read at 78491 is a Hex-Rays field
misattribution — it is the `PStringBase` release idiom.)

Auth types, from `gmClient::InitAuth` (acclient.c:62573):

| Type | Credential | Set at |
|---|---|---|
| `0x00000001` | none (account name only) | 77291 |
| `0x00000002` | VG password | 62593 |
| `0x40000002` | GLS ticket | 62604 |

`SetToAuthType` (368069) copies the credential into `m_ExtraData` with a plain
`qmemcpy` (368092). **No hash, no salt, no digest, no local encryption.**
`AUTHFLAGS_ENABLECRYPTO = 0x1` (acclient.h:3056) is declared but dead —
`m_dwAuthFlags` is written exactly once, to `0`, in the constructor (367957).

**Both ISAAC seeds also travel in plaintext.** `CConnectHeader` (mask `0x40000`,
acclient.h:41925) carries
`{double ServerTime; uint64 qwCookie; uint32 NetID; uint32 OutgoingSeed;
uint32 IncomingSeed}`. They are consumed at 373287–373297, cross-assigned, and
handed to `ReceiverData::InitCrypto` (376267) → `new CryptoSystem(seed)`
(376294, 376301).

Combined with §2.3, this means an observer who sees the connect header can
reproduce the entire keystream.

### 2.7 `ohfEncrypted` / `ohfSigned` are set but never verified

`OptionalHeaderFlags` (acclient.h:4808–4818) includes
`ohfEncrypted = 0x20000000` and `ohfSigned = 0x40000000`, and they really are
set: `m_Flags = 0x20000007` on `CConnectHeader` (468407) and `0x40000062` on the
`CReferralStruct` header (371102, 468871).

**The client never acts on either.** Every read of `m_Flags` in the file tests
only `0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40` (374873, 374967, 375044, 376847,
376849, 376851, 370784, 685221). No test of `0x20000000` or `0x40000000` exists
anywhere. Both dispatchers key exclusively on `m_dwMask`
(`SharedNet::ProcessOptionalHeader` 370720, `ClientNet::ProcessOptionalHeader`
372696), and the send path (370769) ignores the high bits too.

So the referral cookie (`CReferralStruct`, acclient.h:41941) is an
**unauthenticated bearer token**, replayed verbatim to the target world server
(371758, 372923). Enforcement, if any, is server-side.

### 2.8 `NetBlobIDUtils` — plain bit-packing, no scrambling

acclient.c:467808–467879. The 64-bit blob ID layout:

```
bits  0..31  sequence ID (plain increment)
bits 32..47  ordering stamp (wrapping uint16)
bits 48..55  server ID byte
bits 56..60  ordering type
bit  63      ephemeral flag
```

`GetOrderingType` masks `0x1F00000000000000`; `GetSequenceID` masks
`0x00FF0000FFFFFFFF`; `LHSNewerOrderingStamp` is a wrapping 16-bit comparison
with threshold `0x7FFF`. No XOR, no hash.

Two caveats, both flagged as partly inferred: the `stamp << 32` term in
`MakeNetBlobID` is not visible because IDA drops the `edx` half of the 64-bit
return; and `MakeInitialSequenceID` (467826) as decompiled returns 0 on every
path, which is either the same truncation issue or a genuine stub.

---

## 3. Spell-data obfuscation

Three layers stack: a nibble swap on strings, a hash-keyed subtraction on the
component array, and a per-account scrambler on the taper slots.

### 3.1 Layer 1 — the nibble swap

Self-inverse, byte-wise, applied in place to a private copy:

```
deobfuscate(PStringBase s):          # == obfuscate; involution
    s.break_reference()              # forces a private copy, sets m_hash = -1
    p   = s.m_buffer + 20            # &m_data[0]
    end = s.m_buffer + s.m_len + 19  # &m_data[m_len - 1]  -> excludes the NUL
    while p != end:
        *p = ((*p << 4) | ((uint8)*p >> 4)) & 0xFF
        p++
```

`m_len` includes the terminator, so the loop covers `strlen` bytes.
`break_reference` (77447) always invalidates the cached hash, which is why every
hash downstream is over the *deobfuscated* text.

**All five sites — the transform is written inline at each, never shared:**

| Line | Function | String |
|---|---|---|
| 448856 | `CSpellBase::InqDescription` | spell description (display) |
| 448899 | `CSpellBase::InqSpellFormula` | spell name (key material) |
| 448912 | `CSpellBase::InqSpellFormula` | spell description (key material) |
| 487046 | `SpellComponentBase::InqName` | component name |
| **510828** | **`QuestDef::QuestDef`** | **quest full name** — non-spell |

Two things worth knowing:

- **Quest names use the same obfuscation**, applied in the constructor right
  after `set(&_fullname, &name)`.
- **`CSpellBase::InqName` exists but is COMDAT-folded.** It lives at `0x5BBEE0`,
  identical-COMDAT-folded (ICF) with `SpellComponentBase::InqName` — same VA, same
  length. `ClientMagicSystem::GetSpellName` (403960) casts a `CSpellBase*` to
  `SpellComponentBase*` and calls `SpellComponentBase::InqName` (403970); the
  apparent "aliasing" at 247918, 248426, 248503, 248526, 248539, 248555, 248560,
  248661, 404500, 405117 is an artifact of that ICF fold, not a source-level cast.
  Both classes place `PStringBase _name` at offset 4, which is why the fold is
  safe.
- **`SpellComponentBase::_text`** (the component description) is stored
  obfuscated on disk but has **no deobfuscating accessor** — every reference is
  Pack, UnPack, Init, or copy. The client never displays it. Anyone dumping that
  field must swap it themselves.

### 3.2 Layer 2 — the hash-keyed subtraction

The hash is PJW/ELF with a `>> 24` fold. All three symbols
(`compute_str_hash<char>` 69999, `compute_str_hash` 78974,
`PStringBase<char>::compute_hash` 297666) are byte-identical:

```
hash(s) -> uint32:
    r = 0
    for c in s:                              # c is a SIGNED char
        r = (c + 16*r) & 0xFFFFFFFF
        if r & 0xF0000000:
            r = (r ^ ((r & 0xF0000000) >> 24)) & 0x0FFFFFFF
    if r == 0xFFFFFFFF: r = 0xFFFFFFFE       # -1 is the "unset" sentinel
    return r
```

The signed `char` matters for bytes ≥ 0x80, which can occur in descriptions.

Key formation — `CSpellBase::InqSpellFormula` (body 448869):

```
n = nibble_swap(copy of _name)                       # 448887-448903
d = nibble_swap(copy of _desc)                       # 448890-448916
key = (hash(n) % 0x12107680) + (hash(d) % 0xBEADCF45)   # 448932, wrapping add
Decrypt(copy of _formula, key)
```

**Both moduli are no-ops.** The `& 0x0FFFFFFF` fold caps the hash at
`0x0FFFFFFF` = 268,435,455, while the moduli are 303,068,800 and 3,199,061,829 —
both larger. Verified numerically against real spell names. **The key is simply
`hash(name) + hash(desc)` mod 2³².**

`SpellFormula::Decrypt` — acclient.c:487851:

```
Decrypt(formula, key):
    for i in 0..7:
        if formula._comps[i] != 0:
            formula._comps[i] = (formula._comps[i] - key) & 0xFFFFFFFF
```

Zero slots are left untouched — zero is the empty-slot sentinel. Fully unrolled
in the binary. **There is no `SpellFormula::Encrypt`** — the client is read-only
for this data; only the DAT authoring tool ran the forward direction. Since the
swap is an involution and `Decrypt` is a subtraction, the forward transforms are
`swap` and `+key`.

The constants are stable across versions: identical at
`acclient 6.95.16808.c:444146` and
`../../2015-10 11.6096/acclient 6.6.14.605 Diffed.c:446510`.

### 3.3 Layer 3 — per-account taper scrambling

`SpellFormula::RandomizeForName` (488270) dispatches on
`CSpellBase::_formula_version`; an unrecognised version leaves the formula as
plain `Decrypt` output.

Throughout, `TAPER = MagicSystem::GetLowestTaperID() = 63` (a bare `return 63` at
488479, called only from these three functions). Every rewritten slot is
`expr % 0xC + 63`, i.e. one of the twelve tapers, IDs **63–74**. **The scrambling
only ever changes which taper occupies an accent slot** — scarabs and the power
component are never touched. That is the design: the formula stays
castable-looking, but a shared or screenshotted component list does not transfer
between accounts.

#### Version 1 — acclient.c:487980

Slot selection is **dynamic**, driven by the count of non-zero components:

```
n = count of nonzero _comps[0..7]
h = hash(account_name); seed = h % 0x13D573

i1 = 1;  if n > 5: { i1 = 2; accent1 = 1 }
i2 = i1 + 1;  if n > 6: { i2 += 1; accent2 = 1 }
i3 = i2 + 1
i4 = i3 + 1;  if n > 7: { i4 += 1; accent3 = 1 }

A = _comps[0]; B = _comps[i1]
C = _comps[i2] if 0<=i2<8 else 0
D = _comps[i3] if 0<=i3<8 else 0
E = _comps[i4] if 0<=i4<8 else 0          # all reads happen before any write

if accent1:  if (A+B)==0: A=1
             _comps[1] = (C + 2*B + D + E + A) % 0xC + TAPER
if accent2:  S = C+D; if (A+S)==0: A=1
             _comps[3] = ((A + B + E + 2*S) * (seed / (A+S))) % 0xC + TAPER
if accent3:  if (E+A)==0: A=1
             _comps[6] = ((C + 2*E + D + B + A) * (seed / (E+A))) % 0xC + TAPER
```

| n | slots rewritten |
|---|---|
| ≤ 5 | **none — version 1 is a no-op** |
| 6 | `_comps[1]` |
| 7 | `_comps[1]`, `_comps[3]` |
| 8 | `_comps[1]`, `_comps[3]`, `_comps[6]` |

Two quirks: the `accent1` block has a div-by-zero guard but **no division** —
`_comps[1]` does not use `seed` at all (independently confirmed at
`acclient 6.95.16808.c:482372`, so not a folding artifact). And
`seed / (A+S)` is an unsigned integer division that yields 0 whenever the divisor
exceeds `seed`, zeroing the whole product — so `_comps[3]` and `_comps[6]`
frequently come out as exactly 63.

#### Version 2 — acclient.c:488093

Unconditional; always rewrites slots 3 and 6.

```
h = hash(account_name)
_comps[3] = (3*c0 + c1 + c2 + 2*c4*c5 + c7) % 0xC + TAPER
_comps[6] = ((3*c0*c2 + c4 + 2*c5 + c7)
             * ((h % 0x13D573) / (c1*c7 + 2*c4))) % 0xC + TAPER
```

Same `0x13D573` modulus as V1. **No div-by-zero guard** — `c1*c7 + 2*c4` is
assumed nonzero. All arithmetic is 32-bit wrapping; `2*c4*c5` and `c0*c2` can
overflow.

#### Version 3 — acclient.c:488138

Seven moduli, all confirmed. The six paired ones reduce the account hash and mix
with the slot **not** being rewritten:

| Local | Line | Modulus | Paired slot |
|---|---|---|---|
| `a0` | 488189 | `0x13D573` | `_comps[0]` |
| `a1` | 488198 | `0x4AEFD` | `_comps[1]` |
| `a2` | 488207 | `0x96A7F` | `_comps[2]` |
| `a4` | 488216 | `0x100A03` | `_comps[4]` |
| `a5` | 488225 | `0xEB2EF` | `_comps[5]` |
| `a7` | 488234 | `0x121E7D` | `_comps[7]` |
| — | 488258 | `0x65039` | applied to **raw** `h`, slot 6 only |

```
h = hash(account_name)
a0 = (h % 0x13D573 + _comps[0]) % 0xC
a1 = (h % 0x4AEFD  + _comps[1]) % 0xC
a2 = (h % 0x96A7F  + _comps[2]) % 0xC
a4 = (h % 0x100A03 + _comps[4]) % 0xC
a5 = (h % 0xEB2EF  + _comps[5]) % 0xC
a7 = (h % 0x121E7D + _comps[7]) % 0xC

_comps[3] = (a0 + a1 + a2 + a4 + a5
             + a2*a5 + a0*a1 + a7*(a4 + 1)) % 0xC + TAPER

_comps[6] = (a0 + a1 + a2 + a4 + a5
             + (h % 0x65039) % 0xC
             + a7 * (a4 * (a0*a1*a2*a5 + 7) + 1)
             + 5*a0*a1
             + 11*a2*a5) % 0xC + TAPER
```

All `a*` are already in [0,11], so nothing overflows here.

### 3.4 The bypass

`ClientMagicSystem::GetAppropriateSpellFormula` (acclient.c:404513) chooses
between two accessors:

```
switch (_school):                       # 404557-404575
    1 -> prop 297;  2 -> prop 296;  3 -> prop 295;  4 -> prop 294;  5 -> prop 328
if InqInt(prop) > 0:                   goto SCARAB_ONLY
elif MagicPackIsOwned(essenceWCID):    goto SCARAB_ONLY     # 404583
else: return InqCustomizedSpellFormula(sBase, account_name) # scrambled
SCARAB_ONLY: return InqScarabOnlyFormula(sBase)             # NOT scrambled
```

`InqScarabOnlyFormula` (448964) keeps only components in
`{1..6, 0x6E, 0x6F, 0x70, 0xC0, 0xC1}`, stops at the first empty slot, then
appends `k` copies of component `0xBC` where `k` derives from the power level.
Note `0x6F` is accepted here but is **absent from
`DeterminePowerLevelOfComponent`** (488433), so such a scarab scores 0 — a
genuine client bug.

**The decrypt layer is never bypassed** — both paths go through
`InqSpellFormula`.

### 3.5 Reimplementation reference

```python
def spell_formula(spell, account_name, scarab_only):
    name = nibble_swap(spell.raw_name)      # strlen bytes, terminator excluded
    desc = nibble_swap(spell.raw_desc)
    key  = (elf_hash(name) + elf_hash(desc)) & 0xFFFFFFFF
    comps = [(c - key) & 0xFFFFFFFF if c else 0 for c in spell.raw_comps]
    if scarab_only:
        return scarabs_plus_placeholder(comps)
    return randomize(comps, elf_hash(account_name), spell.formula_version)
```

---

## 4. Hashes and pseudo-random generators

None of these are cryptographic; all are load-bearing for correctness.

### 4.1 PJW/ELF string hash

See §3.2. Used for spell keys, `NetError` string IDs (every wire `NetError` is a
`{stringID, tableID}` pair whose `stringID` is this hash of a literal, e.g.
`compute_str_hash("ID_ConnectionError_BadCryptoKey")` at acclient.c:800711), and
`PStringBase`'s cached hash at buffer offset +12.

**Layout hazard:** the two `PStringBase` variants store the cached hash at
*different* buffer offsets. `PStringBase<char>` (`0x4131A0`, reads `[buffer-8]`)
has `m_hash` at +12, but `AC1Legacy::PStringBase<char>` — the class the §3 spell
path uses — has `m_hash` at +16 (`allocate_ref_buffer` writes
`*((_DWORD*)buf+4) = -1`; `InqSpellFormula` reads `[edi+0x10]`). A reimplementer
must not apply the "+12" offset on the spell path.

### 4.2 `Random::rand` — L'Ecuyer combined MRG with Bays–Durham shuffle

Numerical Recipes `ran2`, verbatim. `Random::rand` acclient.c:105458,
`Random::Seed(int)` 105431, no-arg `Random::Seed()` 105502.

State globals: `_seed` (`idum`) init 1 at acclient.c:44760; `_idum2` init
`123456789` = `0x075BCD15` at 44761; `_iv[32]` at 47272; `_iy` at 47273.
(`_iv` spans 0x836EA0–0x836F20 = 32 dwords, confirming NTAB = 32.)

```
IM1 = 2147483563 = 0x7FFFFFAB     IM2 = 2147483399 = 0x7FFFFF07
IA1 =      40014 = 0x9C4E         IA2 =      40692 = 0x9EF4
IQ1 =      53668 = 0xD1A4         IQ2 =      52774 = 0xCE26
IR1 =      12211 = 0x2FB3         IR2 =       3791 = 0x0ECF
IMM1 = IM1 - 1   = 0x7FFFFFAA
NTAB = 32        NDIV = 1 + (IM1-1)/NTAB = 67108862 = 0x03FFFFFE
AM   = 1/IM1 = 4.656613057391769e-10
RNMX = 0.99999988                 # = 1 - 1.2e-7
```

The decompiler folded `IA*(x - IQ*(x/IQ)) - IR*(x/IQ)` into `IA*x - IM*(x/IQ)`;
both are identical because `IA*IQ + IR == IM` for both generators.

```
Seed(seed):
    if seed == 0: seed = 1
    idum = _idum2 = seed
    for j in 39 down to 0:                  # NTAB+8 = 40 warm-up iterations
        k = idum / IQ1
        idum = IA1*idum - IM1*k;  if idum < 0: idum += IM1
        if j < 32: _iv[j] = idum            # only the last 32 fill the table
    _iy = _iv[0];  _seed = idum

rand():
    k  = _seed  / IQ1;  _seed  = IA1*_seed  - IM1*k;   if _seed  < 0: _seed  += IM1
    k2 = _idum2 / IQ2;  _idum2 = IA2*_idum2 - IM2*k2;  if _idum2 < 0: _idum2 += IM2
    j  = _iy / NDIV                          # 0..31
    _iy = _iv[j] - _idum2;  _iv[j] = _seed
    if _iy < 1: _iy += IMM1
    r = _iy * AM
    return (r > RNMX) ? RNMX : r
```

**Exact range is `[AM, RNMX]` = `[4.66e-10, 0.99999988]`** — never 0, never ≥ 1.
Period ≈ 2.3e18. Seeded once per process from `time(0)`, at acclient.c:78040
right after `Timer::Init()`.

`RollDice(int lo, int hi)` (105510) = `lo + trunc(rand() * (hi - lo + 1))`,
uniform over `[lo, hi]` — the `RNMX` clamp is what stops it overshooting.
`RollDice(float lo, float hi)` (105532) = `rand() * (hi - lo) + lo`, which is
**half-open and never reaches `hi`**.

Roughly 35 call sites, all cosmetic: particle emitters, ambient sound selection,
weather descriptors, scene and animation choice, idle chatter.

### 4.2b Other PRNGs

| Generator | Where | Notes |
|---|---|---|
| CRT `rand()` / `srand()` | thunks at acclient.c:38792 | MSVCRT LCG; constants live in the CRT, not decompiled here |
| `RandDouble(min,max)` | 667645 | `rand() * (1/32767) * (max-min) + min` |
| `RandInt(range)` | 667651 | `range * rand() / 0x8000` |
| `RandInt(range, exclude)` | 667657 | rejection loop over the above |
| `PerlinNoise` | 477221 / 477246 | §4.5 |
| `QTIsaac<8,unsigned long>` | 629881+ | §2.2 — network only |

`srand` seeding sites: acclient.c:373691 (`ClientNet` ctor, from
`Timer::get_real_time()`), 383423 (`SoundManager::Init`, from `time(0)`), and
477223 (`PerlinNoise::Init`, **`srand(0)`** — deliberately deterministic). Note
the last two fight each other, so `RandInt`/`RandDouble` streams are not
reproducible across runs.

The half-open range has a real consequence documented in `09-audio.md`: sound
variant selection computes `(N-1) * roll`, which can never reach `N-1`, so **the
last variant in every multi-variant sound table node is unreachable**.

This is the gameplay RNG and has no caller on the network or crypto path.

### 4.3 Coordinate hashes — deterministic procedural placement

A family of integer hashes normalised by `2.3283064e-10` = 1/2³². Client and
server must agree, so these are effectively part of the protocol.

**Landcell triangulation direction** — `CLandBlockStruct::ConstructPolygons`,
acclient.c:354046, comparison at 354050:

```
v = y*(214614067*x + 1813693831) - 1109124029*x - 1369149221
SWtoNEcut = ((double)(uint32)v * 2.3283064e-10) >= 0.5
```

In hex those constants are `0x0CCAC033`, `0x6C1AC587`, `0x421BE3BD`,
`0x519B8F25`. (Verified against the source line — an intermediate draft of this
catalogue mis-transcribed two of them.)

`x` and `y` are **global** cell coordinates (`block_x = ((id>>24)&0xFF)*8`,
`block_y = ((id>>16)&0xFF)*8`), so every landcell's diagonal is a pure function of
world position with no state. Note the float compare is exactly a test of
`H & 0x80000000` — the constant at `0x7C6170` is the exact 4-byte float
`00 00 80 2F` = exactly 2⁻³², so there is no precision loss at the 0.5 threshold;
the printed `2.3283064e-10` is decompiler rounding of the exact value.

#### The wider family

This is one member of a family sharing the "spine" constants
`0x6C1AC587` and `0x421BE3BD`. All evaluate in wrapping uint32, then scale by
2⁻³² into `[0,1)`.

**Family A** — `0x6C1AC587*y − K*(0x5111BFEF*y*x + 0x70892FB7) − 0x421BE3BD*x`:

| Use | Line | `K` |
|---|---|---|
| `CLandBlock::get_land_scenery` — object cull vs. `freq` | 352659–352669 | `23399` |
| `ObjectDesc::ScaleObj` — object scale, via `pow(max/min, H)*min` | 351370 | `k + 32593` |
| `ObjectDesc::Place` — X displacement | 462619 | `iq + 45773` |
| `ObjectDesc::Place` — Y displacement | 462626 | `iq + 72719` |
| `ObjectDesc::GetObjFrame` — heading | 462670 | `k + 63127` |

**Family B** — `0x6C1AC587*y − x*(M*y + 0x421BE3BD) + C`:

| Use | Line | `M` | `C` |
|---|---|---|---|
| `ObjectDesc::Place` — 4-way rotation quadrant | 462630 | `0x6F7BD965` | `−0x17FCEDFD` |
| `PalShift::SelectRot` — land texture index | 300893/896/899 | `0x622DBEDF` | `−0x791C2B27` |
| `PalShift::GetBeginRotIx` — start rotation index | 300276 | `0x1DE6BF23` | `+0x490893B5` |

**Family C** — `y*(M*x + 0x6C1AC587) − 0x421BE3BD*x + C`:

| Use | Line | `M` | `C` |
|---|---|---|---|
| `ConstructPolygons` — `SWtoNEcut` (above) | 354046 | `0x0CCAC033` | `−0x519B8F25` |
| `get_land_scenery` — which scene of `SceneCount` | 352640 | `0x2A7F2B89` | `+0x7F8CDA01` |

**Family D** — 1-D on the terrain pcode: `0x523AA99E*pcode − 0x51C9E74A`, then
`floor(H * 2⁻³² * count)` — `TexMerge::FindRoadAlpha` (304712) and
`FindTerrainAlpha` (304781 side maps, 304804 corner maps).

**Family E** — 1-D on the absolute game day: `SkyDesc::CalcPresentDayGroup`
(301664, expression at 301686):

```
t = current_day + days_per_year * current_year
H = (0x6A42FDB2 * t − 0x7541E9AE) mod 2^32
g = floor(H * 2^-32 * day_groups.m_num)
```

Together these generate scenery placement, texture selection, terrain
triangulation, object scale and heading, and the weather day-group — **all with
zero replication traffic**, which is why they must match the server bit for bit.

### 4.4 `EnumeratedBitfield` — bit ↔ enum mapping

acclient.c:653554 (decode) / 653738 (encode). Enum value `N` maps to bit `N-1`;
enum value 0 is reserved and round-trips to 0, i.e. is unrepresentable. Width is
32 or 64 by template instantiation, so larger enum values silently overflow.

### 4.5 `PerlinNoise` — deterministic 1-D value noise

`Init` acclient.c:477221, `Noise` 477246.

```
Init():
    srand(0)                                  # deliberately fixed
    for i in 0..255:
        p[i]  = i
        g1[i] = (rand() % 512 - 256) * (1/256)      # -> [-1, 1)
    for i in 255 down to 1:                   # Fisher-Yates with a biased index
        j = rand() % 256; swap(p[i], p[j])
    copy g1[0..257] -> g1[256..], p[0..257] -> p[256..]   # wrap tails

Noise(x):
    if start: start = 0; Init()               # lazy one-shot
    t = x + 10000.0;  i = (uint8)(int)t;  f = t - (int)t
    a = f * g1[p[i]]
    b = (f - 1.0) * g1[p[(uint8)(i+1)]]
    return (b - a) * (f*f * (3.0 - 2.0*f)) + a          # classic smoothstep
```

Uses Perlin's original cubic smoothstep, not the quintic.

### 4.6 Hash-table bucket derivation

Five distinct families, all Turbine's own.

**`IntrusiveHashTable<Key, Data*, bAutoGrow>`** — `bucket = HashOf(key) %
m_numBuckets`, a true modulo. `HashOf` depends on the key type: identity for
`unsigned long`; **`m_data1` only** (the first dword) for `Turbine_GUID`
(acclient.c:65183); memoised ELF hash for `PStringBase<char>`; recomputed
case-folded hash for `CaseInsensitiveStringBase`. The third template parameter is
auto-grow: with `1`, it grows when the load factor exceeds 2
(`if (2*m_numBuckets < m_numElements+1) grow()`, acclient.c:88354).

Table sizes come from a **23-entry prime-ish table**: `g_bucketSizesBegin`
(acclient.c:44365), `g_bucketSizesEnd` (44366), `g_numBucketSizes = 23` (39095).
Construction does `lower_bound(requested)` (65388); `grow()` steps to the next
larger entry (65410). Objects keep an in-place `m_aInplaceBuckets[23]` and only
heap-allocate above 23 buckets (65395). *The element values themselves live in
`.rdata` and are not in the decompilation — inferred, not read.*

**`LongHash<T>` / `HashBase<unsigned long>`** — power-of-two with a shift-fold:

```
bucket = table_mask & (key ^ (key >> key_shift))      # key_shift = 8 everywhere
table_mask = 2^ceil(log2(table_size)) - 1             # InternalInit, 290596
```

This is the classic AC object-ID hash — `CObjectMaint::object_table`,
`weenie_object_table`, motion tables, placement frames.

**`UI64Hash<T>`** — same formula on a 64-bit key with `key_shift = 16`; the high
dword of the fold is computed and then **discarded**, so it is effectively a
32-bit hash. `Indicator::waitingBlobs_` uses table_size 128 (acclient.c:377783).

**`LongNIHash<T>`** — a shift-fold with a true modulo:
`bucket = (key ^ (key >> 16)) % table_size`. Unlike `LongHash`, the reduction is
a division remainder, not a power-of-two mask.

**`PackableHashTable`** — `bucket = hash(key) % _table_size`, with `_table_size`
coming from the serialized data rather than a prime table. **`OldHashTable`** —
identity hash plus modulo, default 32 buckets (472752).

### 4.7 `__security_cookie` — stock MSVC

acclient.c:721590, unmodified `__security_init_cookie`:

```
c = FILETIME.low ^ FILETIME.high
c ^= GetCurrentProcessId() ^ GetCurrentThreadId() ^ GetTickCount()
QueryPerformanceCounter(&pc); c ^= pc.LowPart ^ pc.HighPart
__security_cookie = c ? c : 0xBB40E64E          # MSVC DEFAULT_SECURITY_COOKIE
```

---

## 5. Compression and encodings

Ordinary, no concealment intent, but catalogued for completeness.

### 5.1 zlib on DAT records

`DiskController::Decompress` (647367) / `AttemptToCompress` (647114). Level is
hardcoded **9** (647154). On-disk layout of a compressed record:

```
[0..3]  uint32 uncompressedSize
[4..]   raw zlib deflate stream
```

Guards are asymmetric by one byte: decompress requires payload `>= 0x10`,
compress requires `> 0x10`. `destLen` is set to `payload - 4`, so a record can
never grow — `compress2` returning `Z_BUF_ERROR` simply means "store raw".

The compression flag is `BTEntry.comp_`, bit 0 of the entry's first dword
(acclient.h:28566).

### 5.2 Variable-length integer encodings

**`Pack_AsWClassIDCompressed`** (667758):

```
id <= 0x7FFF : u16 = id
else         : u16 = (id >> 16) | 0x8000 ; u16 = id & 0xFFFF
```

**`Pack_AsDataIDOfKnownType`** (667689) — same shape, delta-coded against a class
base, 14-bit high field:

```
d = id - firstID
d <= 0x3FFF     : u16 = d
d <= 0x3FFFFFFF : u16 = (d >> 16) | 0x8000 ; u16 = d & 0xFFFF
else            : fail
```

**`SB_As32Bit_Compressed::Serialize`** (489676) — the Archive varint, with mixed
endianness:

```
v <= 0x7F       : 1 byte  v
v <= 0x3FFF     : 2 bytes (v>>8)|0x80, v&0xFF
v <= 0x3FFFFFFF : 4 bytes (v>>24)|0xC0, (v>>16)&0xFF, then u16 LE = v & 0xFFFF
```

**`PStringBase::Pack`** (296374): `u16 len` — or `0xFFFF` escape then `u32 len` —
then raw bytes, then zero-pad to a 4-byte boundary.

### 5.3 Run-length: `CMostlyConsecutiveIntSet::Serialize` — 646696

```
write: u32 count; then per run:
    runLen <= 2 : u32 = value & 0x7FFFFFFF          # single, sign bit CLEARED
    runLen >  2 : u32 = -(runLen); u32 = runStart   # start written UNMASKED
read:  v = (int32)word
    v >= 0 : if (v & 0x40000000) v |= 0x80000000    # sign-restore hack
    v <  0 : runLen = -v; start = next word; emit start, start+1, ...
```

One genuine defect worth recording: the bit-30-implies-bit-31 restore is lossy,
so values in `0x40000000..0x7FFFFFFF` cannot round-trip. The read side caps count
at `0x186A0` (100,000).

### 5.4 Presence-mask serialization — the dominant idiom

Used by `PublicWeenieDesc` (471352), `PhysicsDesc` (331865), `CACQualities`
(444513), and dozens more:

```
u32 presenceMask            # bit N set => field N present
[u32 secondaryMask]         # its own presence gated by a bit in the first
<mandatory fields>
ALIGN_PTR(4)
for each optional field in FIXED order:
    if (mask & FIELD_BIT) read field at its natural width
ALIGN_PTR(4)
verify consumed <= declaredSize, else rewind and fail
```

Bit assignments are non-contiguous and **stream order does not match bit order**,
which makes this tedious to reverse — but there is no security intent.

`PackableHashTable` (297870/297935) packs its header as
`count | (table_size << 16)` — count in the **low** 16 bits.

---

## 6. Negative findings

Each verified by exhaustive search, not assumed.

**Cryptography that is absent:** no MD5, SHA-1, SHA-256, RC4, Blowfish, AES,
3DES, TEA, or HMAC — none of the characteristic constants (`0x67452301`,
`0x5A827999`, `0x6A09E667`, `0xC6EF3720`) appear. No Windows CryptoAPI: the six `advapi32`
imports in the PE import table are all ANSI registry calls — `RegCloseKey`,
`RegSetValueExA`, `RegOpenKeyExA`, `RegQueryValueExA`, `RegDeleteValueA`,
`RegOpenKeyA`. (The `...W` names appear only as `GetProcAddress` name strings in
the MSLU/unicows shim table, which is what the decompilation's `advapi32_*_Thunk`
symbols reflect.)

**No CRC is ever computed.** A complete standard 256-entry CRC-32 table *is*
present in `.rdata` at `0x7F2218`–`0x7F2617`, and `0xEDB88320` *is* present — it
is entry 128 of that table, the file's single occurrence. `crc32.obj` *was*
linked (PDB module 113, from `d:\ac2_sdk\dxsdk\9.0\lib\x86\d3dx9.lib`). But none
of it is live: the table has **zero relocated references anywhere in the image**
and `crc32.obj` contributed **zero procedures** — it is dead COMDAT data pulled
in by `d3dx9.lib`, never called. (`0x04C11DB7` and `0x82F63B78` are genuinely
absent.) zlib is present in **raw-deflate form only** (no gzip wrapper), so no
CRC is computed on any DAT record either. What is there instead is third-party
and DAT-local: `d3dx_adler32` (567233 — stock zlib,
`BASE = 65521`, `NMAX = 5552`, 16-way unrolled) and deflate's rolling string hash
`ins_h = ((ins_h << hash_shift) ^ next_byte) & hash_mask` (556538 and four
sibling sites).

**No XOR-with-constant expressions anywhere in the file.** A sweep for
`^ 0x<const>` returns zero matches; all 33 `^=` sites are the Hex-Rays bitfield
setter idiom, equality tests, hash mixing, or `abs()`. The only XOR-over-buffer
loop in the entire binary is `CryptoSystem::EncryptData`.

**No rotate intrinsics** — zero hits for `__ROL`, `__ROR`, `_rotl`, `_rotr`.

**No base64 or armour encoding.** The uppercase-hex helpers
(`PSUtils::stringify_buffer` 72529, `get_binary_buffer_from_string` 71346) are
ordinary; the `"0123456789ABCDEF"` literal is assembled from stack immediates by
the compiler, not hidden.

**No obfuscation of any DAT record type other than spell data.** Verified three
ways: the absence of XOR constants above; every record reaching `UnPack` directly
from the block-chain plus optional-zlib buffer with no post-decompress hook; and
spot-checks of the likeliest candidates. In particular:

**The taboo/profanity list is plaintext.** `TabooTable` is a `DBObj` whose only
member is `HashTable<audience, HashTable<rejection_type, List<PStringBase<char>>>>`;
`Serialize` (665877 ctor, 666077) writes plain strings. `CheckCensors` (665437)
lowercases the subject with `_strlwr`, filters it via `CreateCheckString`
(664626 — `chkType == 2` keeps only `iswalpha`, `chkType == 3` drops
`iswspace`), then runs `StringMatchesFilter` (664669), a hand-written
backtracking glob matcher whose **only** wildcard is `*`. Patterns must therefore
be stored lowercase. No hashing of the word list.

**`NameFilterTable` holds no word list at all** (662515, 662715) — just
per-language phonotactic rules: max same characters in a row, max vowels in a
row, first-N-characters-must-contain-a-vowel, allowed extra characters, and
compound letter groups.

**String tables are plaintext UTF-16LE** (`StringTableString::Serialize` 109419
→ `Serializer::SerializeBytes` 61151, a bare `qmemcpy`).

**No compression on the network path.** zlib is linked but its only call sites
are the two DAT functions. The `pfnUncompressedSendLogger` /
`pfnUncompressedRecvLogger` hooks are set to 0 at both init sites (78864–78865,
373509–373510) and are dead.

**No credential protection of any kind.** No `CryptProtectData`, no hashing, no
salting. Credentials are ordinary refcounted `PStringBase<char>` with no zeroing
on release. The GLS ticket sits in `HKCU\Software\Turbine\ac1\GLSTicket` as a
plaintext `REG_SZ` until the client reads and deletes it (62376–62410), so
anything running before the client can read it.

**No hardware fingerprint, machine ID, or licence check** — no
`GetVolumeInformation`, `GetAdaptersInfo`, `__cpuid`, `MachineGuid`, or
`GetComputerName` in game code.

**No anti-debug, no packing, no self-modifying code.** `VirtualProtect` has zero
occurrences, so runtime unpacking is impossible. The single `IsDebuggerPresent`
(74161) gates a logging sink. See `08-client-core.md` §9 for the full sweep and
for the one thing that *does* exist — a server-driven plugin audit.

---

## 7. Provenance

**Read directly and cross-checked in at least two decompilations:** the nibble
swap and its bounds; the ELF hash and its identity across all three symbols; the
`0x12107680` / `0xBEADCF45` constants; `SpellFormula::Decrypt`; all three
`Randomize` versions including the missing `seed` term in V1's `accent1` block;
all seven V3 moduli; ISAAC's `mix`, `randinit`, and `isaac`; `EncryptData` and
all three call sites; the DH parameters.

**Verified independently by me rather than accepted from a single agent:**

- The ELF fold caps the hash below both moduli, making them no-ops — checked
  numerically against real spell names.
- `vlong` has no division, modulo, or modular exponentiation — checked by
  enumerating its method list from `docs/func_index.tsv`.
- `randrsl[]` is zeroed before `randinit(…, 1)` — read directly at
  acclient.c:629945–629960.
- The `SWtoNEcut` constants — read from the source line after an intermediate
  draft mis-transcribed two of them to hex.
- **Whether `CalcChecksum32`'s tail bytes are sign- or zero-extended.** Two
  independent sweeps disagreed. Resolved by reading all three decompilations: the
  2013 primary shows a bare `*i++` only because `i` is typed `const char*` from
  the imported prototype, while `acclient 6.95.16808.c:622122` and
  `../../2015-10 11.6096/acclient 6.6.14.605 Diffed.c:614117` both emit
  `(unsigned __int8)`. The 2015 file has no imported prototype, so its typing
  comes purely from the instruction. **Zero-extended (`movzx`).** A reproduction
  using signed bytes will diverge on any packet whose length is not a multiple of
  4 and whose tail contains a byte ≥ 0x80.

**Inferred rather than read, and flagged as such:**

- That the DAT authoring tool performed the forward spell transforms; no writer
  code exists in the client.
- That the GLS ticket registry value is written by the launcher, not the client.
  `RegSetValueExA` *is* imported (slot `0x792004`) and *is* called, but only from
  `TurbineDwExceptionFilter::...::SetRegistryKeysForWatson` (acclient.c:719366,
  719375) — a function that has no rel32 callers and sits just before the dead
  `DwExceptionFilter` code cave, so it is itself never reached. No live path in
  the client writes the GLS ticket key.
- The `stamp << 32` term in `MakeNetBlobID`, and whether
  `MakeInitialSequenceID` is a stub — both obscured by IDA dropping the `edx`
  half of a 64-bit return.
- The school-number to school-name pairing (War/Life/Item/Creature/Void); only
  the numeric `_school → property` mapping is in the decompilation.

**Unresolved:** `randinit`'s `bUseSeed == false` branch (630058–630068) performs
one `mix()` and writes only `randmem[4..11]`, which is not the reference loop.
Both other decompilations agree. The branch is dead — every call site passes 1 —
so it never executes, and I have not established whether it is a compiler
artifact or a decompiler failure to recover a loop.
