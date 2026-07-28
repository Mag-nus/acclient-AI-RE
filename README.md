# Asheron's Call client — reverse-engineering notes

Static analysis of two retail `acclient.exe` builds: **11.4186** (September 2013)
and **11.6096** (2015, the final retail client, commonly called *End of Retail*).

Retail Asheron's Call shut down in January 2017 and the servers are long gone.
This is defect analysis and documentation of software that is no longer operated
by anyone, done against binaries the owner of this repository possesses.

---

## What is here

```
acclient/
├── 2013-09 11.4186/          the September 2013 client — the primary subject
│   ├── acclient.exe          not included — user-provided; 4,837,376 bytes, MD5 2e30cd620b26f9787b4e6a6257a9e581
│   ├── acclient.pdb          not included — user-provided; original Turbine debug symbols
│   ├── acclient.c            Hex-Rays decompilation
│   ├── acclient.h            IDA type library
│   ├── acclient 6.95.16808.c alternate decompilation, useful for cross-checking
│   ├── docs/                 subsystem reports
│   └── acclient-src/         the decompilation split into browsable files
├── 2015-10 11.6096/          the 2015 client
│   ├── acclient.exe          not included — user-provided; 4,841,472 bytes, MD5 116d9a66a70b6af449dc3a28d82f2f6d
│   ├── acclient.c            name-stripped decompilation (sub_XXXXXX == real VA)
│   ├── acclient 6.6.14.605 Diffed.c   names ported by BinDiff (imperfect)
│   └── docs/                 reports specific to this build
├── tools/                    the binary-diff tooling
└── CLAUDE.md                 working context for picking this up again
```

**The `acclient.exe` binaries and `acclient.pdb` are not included in this
repository.** They are excluded via `.gitignore` and must be user-provided. To
reproduce or extend the analysis, supply your own copies at the paths shown
above; the sizes and MD5s let you verify you have the exact builds these
documents describe. The decompilations, docs and tools are all still usable for
reading without them.

**There is no PDB for the 2015 build.** Every 11.6096 address in these documents
was derived by matching function bytes against the 11.4186 binary, which does
have symbols.

---

## Reports

Start with **[`2013-09 11.4186/docs/00-architecture.md`](2013-09%2011.4186/docs/00-architecture.md)**,
which ties the subsystem reports together.

| Document | Subject |
|---|---|
| `docs/01-physics.md` … `09-audio.md` | physics, networking, object model, combat and magic, UI, rendering, DAT resources, client core, audio |
| `docs/10-crypto-obfuscation.md` | every encryption, hash, PRNG, checksum and encoding, with reproducible formulas |
| `docs/11-memory-leak-investigation.md` | the memory-leak defect report |
| `../2015-10 11.6096/docs/12-memory-leak-2015.md` | the same defects in the 2015 build, with patch addresses |
| `../2015-10 11.6096/docs/13-client-differences-2013-vs-2015.md` | what changed between the builds |
| `../2015-10 11.6096/docs/14-command-line-arguments.md` | all 16 command-line arguments |
| `../2015-10 11.6096/docs/15-graphics-and-media-stack.md` | Direct3D 9, DirectSound, DirectInput, D3DX, Intel JPEG |

### Headline findings

- **The two builds are over 99.5% identical.** Once relocations are accounted
  for, only **46 functions changed**, and all 46 are enumerated. Cryptography,
  the DAT format, rendering, the UI framework and object maintenance have
  **zero** changed functions.
- **Four memory leaks**, ranked with per-event costs. The dominant one —
  `Palette::makeModifiedPalette` over-referencing every manufactured palette by
  one, stranding 8,264 bytes per object created — was reported publicly by
  someone else; it is independently verified here, and the obvious six-byte fix
  turns out to be **unsafe** because it exposes a latent double-free in
  `releasePalette`. The safe patch is fifteen bytes at three sites.
- **The 2015 changes are one content patch**: an Enlightenment progression stat,
  PK-damage and Overpower ratings, a "Hear PK Deaths" chat filter, two new
  network opcodes, six emote types and four motion commands — plus a set of
  raised capacity limits.
- **Command IDs at ordinal `0x10F` and above shifted by +3** between the builds.
  This is the only constant that silently changed meaning rather than being
  added, and it breaks tools built against pre-2015 references.

---

## The source tree

`2013-09 11.4186/acclient-src/` is `acclient.c` reorganised **along Turbine's
original library structure**, reconstructed from the PDB's module records — so
`CObjectMaint::DeleteObject` lives in
`acclient-src/src/PORTAL/cobject/CObjMaint.c` because that is literally where it
was compiled from. Every function keeps its original `acclient.c` line number, so
citations resolve in either copy. There is a Visual Studio browsing solution.

It does **not** compile, and cannot be made to. See its README.

---

## This work was done with AI

**These documents were produced by Claude (Anthropic) working interactively with
the repository owner**, over a single long session: reading the binaries and
decompilations, writing and running analysis scripts, and drafting the reports.
Some breadth work was delegated to parallel sub-agents whose findings were then
verified.

That has consequences you should know about before relying on any of it.

**What was done to make it trustworthy.** Findings are cited to `file:line` or to
a virtual address so they can be re-checked. Claims about the 2015 build are
grounded in the binary rather than in decompiler output, because the two
decompilations available for it disagree and one has machine-ported names that
are demonstrably wrong in places. Several conclusions were reached by two
independent methods. Where a sub-agent's finding conflicted with the binary, the
binary was followed.

**What went wrong along the way, and was corrected.** The reports themselves
record this, and the pattern is worth knowing: two fabricated identifiers, two
false universal negatives, an inverted vtable label, a wrong section-mapping
claim, three type declarations that existed only inside string literals, and a
binary-diff figure that moved from 40.2% to 0.41% across five successive
methods. Each was caught by re-checking against the binary. Assume there are
more that were not caught.

**How to treat it.** The addresses, byte patterns and disassembly excerpts are
mechanically derived and are the strongest material here. Prose interpretation —
why something was done, what a subsystem is *for* — is weaker and occasionally
speculative; where it is, the text says so. **Verify anything before you patch
against it.** The scripts in `tools/` exist so you can.

---

## Third-party references used

- `github.com/ACClientLib/ACProtocol` — community protocol definitions. Used to
  cross-check opcodes and to name recovered property IDs; **19 of 19** property
  IDs and **9 of 9** opcodes matched. Its client-side enums (`Command`,
  `EmoteType`, `EmoteCategory`, `GameEvent`) describe the 2013 client and
  disagree with 2015 in documented ways — see
  `2013-09 11.4186/acclient-src/reference/README.md`.
- `github.com/eriknihlen/ac-eor-palette-leak-fix` — the palette leak report,
  verified here and extended.

---

## Tooling

`tools/binary_diff.py` implements the relocation-exact comparison, with the four
methods that gave wrong answers documented in its header so nobody repeats them.
`tools/relnorm.py` parses the PE relocation table.
`tools/pdb_symbols_11.4186.pkl` is the parsed 11.4186 PDB — 39,948 function
symbols with addresses, lengths and owning `.obj`.

Requires `python3` and `objdump`. No third-party packages.
