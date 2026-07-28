# `acclient-src` — the decompilation, split by original source module

`../acclient.c` is a single 938,010-line file. This folder is the same content
reorganised into **795 files across the original library tree**, so you can open
one subsystem instead of scrolling through all of it.

All 36,603 functions are accounted for, and bodies are identical to the monolith
apart from **one documented textual substitution** (below).

### The one change: MSVC mangled names

Hex-Rays writes compiler-generated names with backtick/apostrophe decoration —
`` `scalar deleting destructor' ``, `` `vftable' ``, `` `vector constructor iterator' ``.
That is not valid C: the backtick is not a token at all, and the apostrophe opens
a character literal that never closes, so editors and IntelliSense mis-parse the
rest of the line and frequently the lines after it. There are **14,122** of them.

They are rewritten to plain identifiers by dropping the decoration and turning
spaces into underscores:

| Original | Becomes | Count |
|---|---|---|
| `` `vftable' `` | `vftable` | 10,667 |
| `` `vector deleting destructor' `` | `vector_deleting_destructor` | 1,735 |
| `` `scalar deleting destructor' `` | `scalar_deleting_destructor` | 1,376 |
| `` `vector constructor iterator' `` | `vector_constructor_iterator` | 126 |
| `` `2' `` , `` `3' `` | `_2` , `_3` (leading digit) | 79 |
| 10 others (`` `vcall' ``, `` `local static guard' ``, …) | same rule | 139 |

The substitution only fires on a backtick with a closing apostrophe **on the same
line and no quote between**, so the five occurrences of byte `0x60` inside GUID
string literals in `acclient_data.h` are correctly left alone — they are data,
not identifiers. Those five are the only backticks left in the tree.

Verified after regeneration: four spot-checked function bodies match the
monolith exactly once the same substitution is applied to it, and all **120,807**
non-trivial lines across the tree appear verbatim in the sanitised monolith, with
zero unaccounted for.

`../acclient.c` itself is never modified and remains the source of truth.

---

## How the split was derived

Not by guessing from names. Two facts made it exact:

1. Hex-Rays emits a marker above every function containing its **virtual
   address**: `//----- (005084D0) ---…`
2. `acclient.pdb` records, for every function, the **`.obj` it was compiled
   from** — 1,091 module records carrying their original build paths, e.g.
   `d:\ac1_sep13\output\obj\PORTAL\cobject\CObjMaint.obj`

So each function is placed by address lookup into the PDB, and the directory
tree is Turbine's own `LAYER/library/module.obj` structure, recovered verbatim.
`CObjectMaint::DeleteObject` lands in `src/PORTAL/cobject/CObjMaint.c` because
that is literally where it was compiled from.

---

## Layout

```
acclient-src/
├── acclient.sln                  Visual Studio browsing solution  (see below)
├── acclient.vcxproj[.filters]
├── CppProperties.json            config for VS "Open Folder" mode
├── INDEX.md                      every file, with function count and address range
├── reference/                    third-party enum names (NOT in the include chain)
│   └── protocol_enums.tsv        5,065 constants → names; see reference/README.md
├── include/
│   ├── acclient_prologue.h       Hex-Rays preamble and #includes
│   ├── acclient_types.h          pulls in ../../acclient.h — the type library
│   ├── acclient_protos.h         all function prototypes  (lines 15–38,953)
│   ├── acclient_data.h           globals, vtables, string literals (38,955–60,792)
│   └── defs.h                    stand-in for the IDA header, for IntelliSense only
├── src/
│   ├── PORTAL/    7,552 fn   physics, geometry, animation, DAT, sound, net primitives
│   ├── ENGINE/   17,955 fn   rendering, UI framework, input, cache, property system
│   ├── GAME/      5,685 fn   client scaffolding and the gm* UI panels
│   ├── AC/        3,345 fn   AC gameplay: qualities, spells, combat, chat, housing
│   ├── CORE/        711 fn   shared Turbine utilities (separate source tree)
│   ├── _other/      130 fn   non-standard object paths
│   └── _runtime/  1,225 fn   statically linked D3DX9, MSVC 7.0 CRT, Intel JPEG
└── tools/
    └── split_acclient.py        regenerates everything from acclient.c + acclient.pdb
```

Each generated `.c` opens with the module name, its original object path, its
function count and its address range, then includes the three shared headers.

---

## Where the types come from

IDA exports a decompiled program as **two** files, and `acclient.c` does not
reference the other one. Its entire include block is:

```c
#include <windows.h>
#include <math.h>
#include <defs.h>
#include <stdarg.h>
```

Every program type — `PackObj`, `CObjectMaint`, `ACCWeenieObject`, `Palette`,
`PStringBase`, all 6,936 structs and 410 enums — lives in **`../acclient.h`**
(70,719 lines, 10,992 definitions), and nothing includes it. That is why a name
like `PackObj` can appear in `acclient_protos.h` with no definition in sight: it
is declared at `acclient.h:26018` and used 1,063 times from `acclient.c`.

`include/acclient_types.h` closes that gap. It forwards to `../../acclient.h`
rather than copying it, so the original stays the single source of truth, and it
supplies the include guard that IDA's header lacks. Every generated source chains
the four headers in dependency order:

```c
#include ".../include/acclient_prologue.h"   /* windows.h, math.h, defs.h  */
#include ".../include/acclient_types.h"      /* -> ../../acclient.h        */
#include ".../include/acclient_protos.h"     /* function prototypes        */
#include ".../include/acclient_data.h"       /* globals, vtables, strings  */
```

Order matters: `acclient.h` uses the Hex-Rays sized-integer aliases, so `defs.h`
has to come first.

Note that `acclient.h` is not valid C either — `PackObj` alone declares eleven
overloaded `GetPackSize` members inside a `__cppobj` struct, which is fine in C++
and impossible in C. Another reason this tree browses rather than builds.

### Why the template types look "undefined"

You will see errors on `HashTable`, `IntrusiveHashTable`, `HashTableData`,
`ReferenceCountTemplate`, `SmartArray` and many others. **They are not missing.**
Each has full definitions in `acclient.h`:

| Type | Definitions with bodies | Always used with arguments? |
|---|---|---|
| `HashTableData<…>` | 391 | yes — 1,491 uses, never bare |
| `IntrusiveHashTable<…>` | 219 | yes — 762 uses, never bare |
| `HashTable<…>` | 205 | yes — 576 uses, never bare |
| `ReferenceCountTemplate<…>` | 58 | yes — 77 uses, never bare |

`struct __cppobj HashTable<unsigned long,Interface *,0>` is defined at
`acclient.h:8002`, with a complete body.

The problem is that **IDA never emits a primary template declaration.** Its type
library stores each *instantiation* as an independent concrete type whose name
merely happens to contain angle brackets — to IDA the name is just a string, and
there is no template machinery behind it. A compiler sees it differently:

- In **C++**, `struct HashTable<unsigned long,Interface*,0> { … }` is only legal
  as an explicit specialisation, which requires `template<class,class,int> struct
  HashTable;` to have been declared first, and requires each definition to carry
  a `template<>` prefix. Neither exists.
- In **C**, `<` and `>` are not template syntax at all, so it is a plain syntax
  error.

This is not a niche corner: **2,194 of the 4,376 struct definitions in
`acclient.h` have template-style names**, across **137 distinct base names** —
`IntrusiveHashTable` (327), `HashTable` (236), `HashTableData` (147),
`SmartArray` (128), `IntrusiveHashIterator` (109), `IntrusiveHashData` (102),
`HashIterator` (78), `List` (75) and so on. Roughly half the type library.

Adding primary-template declarations would not fix it. It would silence the
"undeclared identifier" complaint, but every one of those 2,194 definitions would
still need a `template<>` prefix to be a legal specialisation, and `__cppobj`
would still be unknown to the compiler. Making the header parse means rewriting
it wholesale — and a mechanical rewrite of 2,194 type definitions risks silently
corrupting the layout information that makes the header worth having.

So: treat these errors as expected. The definitions are there and are correct;
IntelliSense simply cannot model them. Reading `acclient.h` directly works fine
— `HashTable<unsigned long,Interface *,0>` at line 8002 tells you the real field
layout regardless of what the squiggles say.

## Opening in Visual Studio

Two ways, both browse-only:

**Solution** — open `acclient.sln`. Solution Explorer shows the full
`LAYER/library` tree, because `acclient.vcxproj.filters` mirrors the directory
structure. 795 sources and 4 headers, 185 folders.

**Open Folder** — `File ▸ Open ▸ Folder…` on `acclient-src`. `CppProperties.json`
sets the include paths and IntelliSense mode. Often snappier on a tree this size,
and it skips project loading entirely.

### It deliberately does not build

The project is a **Makefile-type** project whose build command just echoes a
message, so Visual Studio will never try to compile 36,603 decompiled functions
and bury you in errors. Pressing Build prints one line and succeeds.

This is not a limitation that can be engineered away. Hex-Rays output is not
valid C: it contains backtick identifiers (`` `vector constructor iterator' ``),
`_UNKNOWN` placeholders, synthesised types, duplicate symbols from COMDAT
folding, and thousands of functions whose signatures were inferred rather than
known. Making even one subsystem compile would be a substantial manual project.

### What actually works well

- **Solution Explorer** — browse by layer and library
- **Find in Files** (`Ctrl+Shift+F`) — fast across the whole tree, and now
  scopable to one subsystem instead of one 938,010-line file
- **Go To File** (`Ctrl+,`) — type `CObjMaint` and land in the right module
- **Open Document / navigation bar** — per-file function dropdown

### What to expect from IntelliSense

Partial, and deliberately so in one respect.

`include/defs.h` stands in for the IDA header the code `#include`s but which is
not part of the decompilation. It declares `_BYTE`/`_WORD`/`_DWORD`/`_QWORD`, the
`LOBYTE`/`HIWORD` accessors and the `__PAIR__`/`__OFSUB__` intrinsics.

**It asserts nothing that is not evidenced, and the evidence is stated inline.**
Use counts are of *code* occurrences with comments and string literals stripped
first. Two rounds of trimming were needed: an early draft carried 36
declarations that appear nowhere at all, and a second carried three more —
`uint32`, `int64` and `MEMORY` — that survive only inside string literals such
as `"Not an int64."` and are never used as types. All removed.

The intrinsics are declared with **return types inferred from observed use** and
**deliberately empty parameter lists**, which in C means *unspecified* rather
than *none*. `__PAIR__` returns `unsigned __int64`, not `int`: of its 23
type-carrying assignments, 21 write through `*(_QWORD *)`. The parameters are
left unasserted because the operands vary in width — `__CFADD__` is applied to
both 32-bit and 64-bit values, so any fixed prototype would be wrong somewhere.

**`_UNKNOWN` is deliberately left undefined.** Hex-Rays emits it for a symbol
whose type it could not determine — 185 occurrences, 172 of them in
`acclient_data.h`. Typedef'ing it to `int` would make those lines parse, but it
would assert a size and layout that are not known and would propagate that guess
into anything read off the back of it. So `_UNKNOWN unk_907938;` does not parse,
and that is the intended signal.

Where the real type matters it is recoverable from the binary: spacing between
adjacent symbols gives array extents, and the bytes give scalar values. For
instance `SceneTool::m_oldViewMatrix`, `m_oldProjMatrix` and `m_oldWorldMatrix`
sit exactly `0x40` apart, so each is 16 floats; and
`CombatSystem::AUGMENTATION_CRITICAL_DEFENSE_PK_AVOID_CHANCE` at `0x00822C44`
holds `0x3D4CCCCD`, i.e. float `0.05`.

The same caution applies to `__usercall`/`__userpurge`, which `defs.h`
neutralises so declarations parse. That **discards information**: the real
argument passing for those 990 functions is register-based and is not
expressible in C. Do not trust their signatures.

Beyond that, expect red squiggles — qualified names like
`ACCWeenieObject::ObjectBeingDeleted` are not valid C, and thousands of types
were synthesised by the decompiler. Treat IntelliSense as a navigation aid, not
a correctness signal. For ground truth use the reports in `../docs/`, which are
grounded in the binary rather than the decompilation.

To regenerate the project files after adding or moving anything:

```
python3 tools/make_vs_project.py
```

## Cross-references still work

Every function keeps its original line number in the marker:

```c
//----- (005084D0) ------------------------------------  // acclient.c:309939
```

So the `acclient.c:NNNNN` citations used throughout `docs/` still resolve, and
you can move between the split tree and the monolith freely. You can search by
either address or original line.

---

## Finding things

- **By subsystem** — browse `src/`, or use [`INDEX.md`](INDEX.md).
- **By address** — `INDEX.md` lists each file's address range; or
  `grep -rn '//----- (005084D0)' src/`.
- **By original line number** — `grep -rn 'acclient.c:309939' src/`.
- **By class** — `docs/class_index.tsv` and `docs/func_index.tsv` still index the
  monolith and remain valid.

---

## Caveats worth knowing

**Attribution is per-object, not per-class.** A `.obj` may hold several classes,
and one class may be split across objects. `src/PORTAL/cobject/CObjMaint.c`
contains `DArray<CPhysicsObj*>` helpers alongside `CObjectMaint` because they
were compiled together.

**Some files are inflated by COMDAT folding.** The linker attributes a folded
template instantiation to whichever object emitted it first, so
`ENGINE/render_base/RenderMesh.c` (1,063 functions) and its neighbours in
`render_base` carry a great many `SmartArray<…>` and `Material*` instantiations
that are not really "RenderMesh code". This is an artifact of how the binary was
linked, not of the split.

**`_runtime/` has no module records at all.** Those 1,225 functions were placed
by public symbol name instead: `d3dx9.c` (663 functions —
`D3DXLoadSurfaceFromMemory`, `D3DXFilterTexture`, `D3DXVec2Normalize`, …),
`msvcrt.c`, `intel_jpeg.c`, and `static_libs.c` for the remainder. 122 functions
across the whole image have neither a module record nor a public symbol and land
in `static_libs.c` under their `sub_XXXXXXXX` names.

Incidentally, that D3DX9 block is direct confirmation of a claim in
`docs/15-graphics-and-media-stack.md`: D3DX is **statically linked**, which is
why there is no `d3dx9_XX.dll` dependency.

**This does not compile.** It is decompiler output, and it was not compilable as
one file either. The headers are split for navigation, not to build.

**The 2015 client is not split.** `../../2015-10 11.6096/acclient.c` has no PDB,
so its functions carry only `sub_XXXXXX` names and there is no module
information to organise by. The tool would produce one undifferentiated file.
Use this tree plus the address-translation table in
`../../2015-10 11.6096/docs/13-client-differences-2013-vs-2015.md` §4 instead —
99.59% of functions are byte-identical between the builds.

---

## Regenerating

```
python3 tools/split_acclient.py
```

Self-contained and deterministic. It reads `../acclient.c` plus
`tools/pdb_symbols.pkl` — a pre-parsed dump of the PDB's module records, function
symbols and public symbols — and rewrites `include/`, `src/` and `tools/manifest.pkl`.
`tools/parse_pdb.py` is the parser that produced that dump from `../acclient.pdb`,
if you ever need to regenerate it too — note that the PDB itself is **not
included in the repository** and must be user-provided; the split only needs
the included `pdb_symbols.pkl`.
