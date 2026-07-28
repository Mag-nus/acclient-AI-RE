# Asheron's Call Client — 2015 Build Notes

Target: **acclient.exe, 2015, version 11.6096**

These documents cover only what is *different* about the 2015 client. **The
subsystem analysis lives in [`../../2013-09 11.4186/docs/`](../../2013-09%2011.4186/docs/)
and applies to this build almost without exception** — see below for why.

## Start here

| Document | What it is |
|---|---|
| [`13-client-differences-2013-vs-2015.md`](13-client-differences-2013-vs-2015.md) | The full 11.4186 → 11.6096 comparison: what changed, what did not, and how to translate addresses between the builds |
| [`12-memory-leak-2015.md`](12-memory-leak-2015.md) | The memory-leak defects as they exist in **this** build, with 11.6096 addresses, vtables, code cave and patch instructions. **Start at §0b** — the `Palette` refcount leak is the dominant one, and it is a six-byte fix |
| [`14-command-line-arguments.md`](14-command-line-arguments.md) | All 16 command-line arguments with verbatim help text, the `-`/`/` prefix syntax, the parsing pipeline, and why `usemem` is inert. Identical in both builds |
| [`15-graphics-and-media-stack.md`](15-graphics-and-media-stack.md) | Which libraries the client renders and plays with: dynamically loaded Direct3D 9 (fixed-function, no shaders), static D3DX9, DirectSound, WINMM, ACM, DirectShow, GDI, Intel JPEG Library, zlib |

## Why the 2013 documents apply here

Both executables are present, so the two builds were compared byte for byte,
using the PE relocation table and real instruction boundaries to mask the
operands that necessarily differ between builds.

**Over 99.5% of functions are byte-for-byte identical. Only 46 changed.**

Cryptography (27 functions), the DAT container and cache layer (292), rendering
(265), the UI framework (710), object maintenance (116) and audio (47) have
**zero** changed functions between the builds. Physics has three, all in
`CMotionInterp` and all about when a jump is permitted; the network layer has
two, one of them the message dispatcher gaining two opcodes. Where a 2013
document describes an algorithm, a structure layout, a protocol or a file format,
it is describing code that is byte-identical in this binary.

The 46 changed functions carry two themes. The first is a PvP-flavoured content
patch: a new progression stat (**Enlightenment**, property `0x186`), two new
combat ratings (**PK Damage** and **Overpower**), a "Hear PK Deaths" chat option
that defaults on, two new network opcodes, six new emote types and four new
motion commands. The second is **raised capacity limits**: friend and squelch
lists 50 → 100, house guest table 64 → 128 buckets, a new 256-character outgoing
chat cap, and an allegiance node count widened from signed 16-bit to unsigned
32-bit with a new 40,000-member ceiling — which incidentally fixes a real bug
where a hierarchy of 32,768–65,535 members unpacked as **zero**.

All 46 are listed in
[`13-client-differences-2013-vs-2015.md`](13-client-differences-2013-vs-2015.md) §5.
Three of them turn out to carry no behavioural change at all — two are pure
instruction scheduling, one is pure enum renumbering.

The only 2013 claims needing a footnote are listed in that document's §6. Two of
them are corrections to the 2013 report itself rather than differences between
the builds, and both have been applied to the 2013 document.

**One warning worth reading before you rely on any 2013 constant:** three
commands were inserted at ordinal `0x10F`, so **136 of the 407 shared command IDs
shifted by +3** — across both the `0x09xxxxxx` action namespace and the
`0x10xxxxxx` motion namespace, starting at `NextMonster` (`0x0900010F` →
`0x09000112`). That is the only constant in the entire comparison that silently
changed meaning rather than simply being added.

## Source material in this folder

| File | What it is |
|---|---|
| `../acclient.exe` | The 11.6096 binary. MD5 `116d9a66a70b6af449dc3a28d82f2f6d`, 4,841,472 bytes, linked 2015-06-12. **Not included in the repository**; user-provided. |
| `../acclient.c` | Name-stripped decompilation of that binary — every `sub_XXXXXX` name **is** the real virtual address, which makes this the authority for confirming addresses |
| `../acclient 6.6.14.605 Diffed.c` | Decompilation with names ported from the 2013 PDB by BinDiff. More readable, but **some names are mis-ported** — see the caveat below |

**There is no PDB for this build.** Every address in these documents was derived
by matching function bytes against the 11.4186 binary, which does have symbols,
and then confirmed against `../acclient.c`.

### Caveat on the BinDiff-ported names

`acclient 6.6.14.605 Diffed.c` carries names transplanted from the 2013 build,
and several landed on the wrong function. Confirmed mis-ports found so far:

- `PlayerModule::DisplayDateOfBirth` — actually the new "Hear PK Deaths" getter
  (`options2_ >> 25 & 1`); the real `DisplayDateOfBirth` is `>> 1`
- `CM_Qualities::DispatchUI_UpdateAttribute2ndLevel` — actually
  `DispatchUI_TransientString`
- `CM_Magic::DispatchUI_PurgeBadEnchantments` at `0x006A5790` — actually the new
  opcode-`0x318` string dispatcher
- `CLogonHeader::HandshakeWireData::~HandshakeWireData` — stands in for a
  `PStringBase` destructor throughout `ChannelSystem::GetChannelID`

When a name in that file implies behaviour that surprises you, check the address
against `../acclient.c` or the binary before believing it.
