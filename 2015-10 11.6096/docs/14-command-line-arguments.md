# Command-Line Arguments

Complete reference for `acclient.exe`, derived from the binaries rather than
from documentation. **Everything here is identical in 11.4186 and 11.6096** —
every function involved compares byte-for-byte between the two builds, so no
argument was added, removed or changed in 2015.

---

## 0. Summary

**There are exactly 16 arguments, and that is provably all of them.** The whole
image contains exactly 16 call sites to
`ArgumentParser::CommandLineArgList::AddCmd`, split between two functions and no
others. There is no second registration path, no hidden or debug-only set, and
nothing registered at runtime.

Arguments are introduced with **`-` or `/`**, and both a short (single-character)
and long (full-name) form are supported. Long-form names are matched
**case-insensitively**; the short-form lookup is an exact character compare (it
falls back to the long-form lookup).

One argument, **`usemem`, does nothing at all** — see §5.

---

## 1. Core arguments — `Client::BuildCommandLineArgs`

| Argument | Takes a value | Help text (verbatim from the binary) |
|---|---|---|
| `account` | yes | `<string>: Specifies the account name to logon with.` |
| `debug` | yes | `<32 bitfield>: Controls what kinds of debug outputs are enabled.` |
| `host` | yes | `[host/IP]:Specifies where to find the server to talk to.` |
| `port` | yes | `<1-65535>: Specify the server port to contact. See 'host'` |
| `outport` | yes | `<1-65535>: Specify the outgoing network port to use.` |
| `language` | yes | `<string>: Language to run the client in.` |
| `prefs` | yes | `<string>: Specify the preferences file to use.` |
| `rodat` | no (flag) | `Opens the DAT files readonly` |
| `usemem` | no (flag) | `Enables the use of the memory manager.` — **inert, see §5** |

## 2. Game and login arguments — `gmClient::BuildCommandLineArgs`

| Argument | Takes a value | Help text (verbatim from the binary) |
|---|---|---|
| `user` | yes | `<name> : Character Name you would like to play` |
| `create` | yes | `<name> : Character Name you would like to create/play` |
| `glsticket` | no (flag) | `Tells the client to use GLS authentication.` |
| `glsticketdirect` | yes | `<ticket> : Raw GLS ticket data.` |
| `zoneticket` | yes | `<string>: Specify ticket data.` |
| `migrationurl` | yes | `<name> : Location of the account migration server` |
| `vgpassword` | yes | `<pw> : Vanguard pw.` |

---

## 3. Syntax

### Prefix characters: `-` and `/`

This is not a hardcoded comparison, which is why it takes some digging. The
`ArgumentParser` holds a **string of accepted switch characters** in its
sub-object at offset `+0x08`, and `ArgumentParser::IsCommandLineArgument`
(`0x00408A00`) tests the token's first character for membership with `strchr`:

```asm
408a2c: movzx eax,WORD PTR [eax]     ; first character of the token
408a2f: mov   ecx,[esi+0x8]          ; ArgumentParser::m_switchChars
408a3b: call  edi                    ; strchr(switchChars, firstChar)
408a40: test  eax,eax
408a42: jne   408aca                 ; found -> this token IS an argument
```

That string is built in `Client::Client`:

```asm
412b13: push 0x794c7c                ; the literal
412b18: lea  ecx,[esi+0xc]
412b1b: call PStringBase<char>::PStringBase<char>
```

and the bytes at `0x00794C7C` are `2D 2F 00` — **`"-/"`**. So both `-host` and
`/host` are accepted, and any future prefix would only require changing those two
bytes.

> The offset arithmetic is worth spelling out because it looks contradictory at
> first glance. `Client::Client` writes the shared empty string to `Client+0x08`
> and `"-/"` to `Client+0x0C`, while `IsCommandLineArgument` reads `[esi+0x08]`.
> These agree because the **`ArgumentParser` sub-object begins at `Client+0x04`**
> — its vptr is written there at `0x00412B60` — so `ArgumentParser+0x08` *is*
> `Client+0x0C`.

Confirmed at `0x00795C7C` in 11.6096, the only occurrence of that literal in
either image.

### Short and long forms

After the prefix is recognised, `ArgumentParser::ParseArgs` (`0x0040A0A0`) strips
the first character, then strips a second if it matches, and dispatches on what
remains:

- a **single character** → `CommandLineArgList::FindByShortCmd`
- **anything longer** → `CommandLineArgList::FindByLongCmd`

So `--host`-style double prefixes are tolerated as well as `-host`.

### Case-insensitivity

The argument-name lookup table is an
`IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>, …>`,
so **`-HOST`, `-Host` and `-host` are equivalent**.

### Quoting

`ConvertCommandLineToArgListTemplate<char>` (`0x00409400`) tokenises on spaces
(`0x20`) and honours double quotes (`0x22`), so values containing spaces can be
quoted. An unterminated quote is reported as `Unmatched quote`.

---

## 4. Parsing pipeline and diagnostics

```
WinMain                                       0x004013E0
  ├ GetCommandLineA
  ├ ConvertCommandLineToArgListTemplate       0x00409400   tokenise, handle quotes
  │     (called through the thunk at 0x00409640)
  └ ArgumentParser::ParseArgs (virtual, vtable slot +0x10)  0x00409850
      └ ArgumentParser::ParseArgs           0x0040A0A0
          ├ IsCommandLineArgument           0x00408A00   prefix test via "-/"
          ├ FindByShortCmd / FindByLongCmd  0x00408CD0 / 0x00409010
          └ EvaluateCommandLineArg          0x00408140   value conversion
```

`WinMain` does not call `ArgumentParser::ParseCommandLine` (`0x00409650`) —
that function has **zero callers** in `.text` and is reachable only virtually.
`WinMain` inlines the equivalent: it calls `GetCommandLineA`, then the `Convert`
thunk, then invokes `ParseArgs` through the vtable. (`ParseCommandLine` itself
does the same `Convert` + virtual-`ParseArgs` sequence, but nothing was found to
invoke it.)

`ArgumentParser::EvaluateCommandLineArg` switches on the argument's type code and
converts the supplied text with `sscanf`-style formats — `%d`, `%hu`, `%f`,
`%lf`. The type code is an enum, not a bitfield; the values that appear in this
binary are `0x01`, `0x02`, `0x03`, `0x11`, `0x22`, `0x32` and `0x3A`, of which
`0x01`, `0x03` and `0x11` are the valueless flags.

Error strings the parser can emit:

| String | Meaning |
|---|---|
| `Unrecognized argument '%ls'` | token began with `-` or `/` but matched nothing |
| `Argument '%ls' unknown` | lookup failed |
| `Argument %ls requires parameter` | a value-taking argument was given none |
| `Unmatched quote` | tokeniser hit end of line inside a quoted string |

Usage output is produced by `ArgumentParser::Usage` (`0x0040A050`) and
`DisplayUsage` (`0x00409080`), word-wrapped to a width returned by
`Client::GetCharactersToWrapUsageTo`.

---

## 5. `usemem` does nothing

Its help text ("Enables the use of the memory manager") makes it look like a
memory-tuning knob. It is inert, and the chain is short enough to state fully:

1. `Client::BuildCommandLineArgs` registers it at `0x68` past its `this`
   pointer. `ebp` is loaded once (`mov ebp,ecx` at `0x004120C7`) and modified
   exactly once, by `add ebp,0x68` at `0x00412491`. But `this` here is the
   **`ArgumentParser` sub-object at `Client+0x04`** (§3), not the `Client` base,
   so the true destination is `Client+0x6C` — not `Client+0x68`. The same +4
   this-adjustment is visible on the neighbouring fields: the `host` dest
   `ebp+0x88` is read back by `Client::GetHostName` at `this+0x8C`, the `port`
   dest `ebp+0x90` by `GetPort` at `this+0x94`, and the `account` eval-dest
   `+0x70` by `GetAccountName` at `this+0x74`.
2. `Client+0x6C` has **no reader anywhere** in the scanned code. `Client::InitUI`
   (`0x00411660`) does read `Client+0x68` at `0x00411670`, reduce it to a boolean
   with `test ecx,ecx; setne cl`, and pass it as **argument 1** of `Device::Init`
   — but `Client+0x68` is a *different* dword: a constant written once to `1` in
   `Client::Client` at `0x00412BAD`, unrelated to `usemem`. The value `usemem`
   writes, at `Client+0x6C`, is never read by anyone.
3. `Device::Init` (`0x0043B820`) **overwrites that argument slot before reading
   it**. Every access to `[esp+0x10C]`, in order:

   | Address | Access |
   |---|---|
   | `0x0043B93A` | **write** `0` |
   | `0x0043B944` | **write** `1` |
   | `0x0043B9B9`, `0x0043B9EA`, `0x0043BBA5`, `0x0043BBCB` | reads, all later |

   The value written comes from `ds:0x00817B02` — set by
   `Device::AllowFullScreenMode` — and a field of the `RenderDevicePresentation`
   populated by `Device::LoadDisplayPreferences`. The slot now carries a
   **windowed/full-screen determination** and has nothing to do with memory.

The parameter was evidently repurposed and the caller never updated.

*Scope of the claim:* `Client+0x6C` was checked against every `Client::`,
`gmClient::`, `ClientMain` and `WinMain` function and has **no reader** among
them. Nothing outside that set is expected to reach it, but that was not
exhaustively proven.

---

## 6. Address reference

All of these are byte-identical between the builds; only their addresses move.

| Symbol | 11.4186 | 11.6096 |
|---|---|---|
| `Client::BuildCommandLineArgs` | `0x004120C0` | `0x00412420` |
| `gmClient::BuildCommandLineArgs` | `0x004028B0` | `0x00402A90` |
| `Client::EvaluateCommandLineArg` | `0x004124F0` | `0x00412850` |
| `ArgumentParser::ParseCommandLine` | `0x00409650` | `0x00409900` |
| `ArgumentParser::ParseArgs` (main) | `0x0040A0A0` | `0x0040A400` |
| `ArgumentParser::ParseArgs` | `0x00409850` | `0x00409B00` |
| `ArgumentParser::IsCommandLineArgument` | `0x00408A00` | `0x00408CB0` |
| `ArgumentParser::EvaluateCommandLineArg` | `0x00408140` | `0x004083F0` |
| `ArgumentParser::CommandLineArgList::AddCmd` | `0x004024C0` | `0x00402660` |
| `ArgumentParser::Usage` | `0x0040A050` | `0x0040A3B0` |
| `ArgumentParser::DisplayUsage` | `0x00409080` | `0x00409330` |
| `Client` vtable (ArgumentParser sub-object) | `0x00794CF8` | — |
| **Switch-character literal `"-/"`** | **`0x00794C7C`** | **`0x00795C7C`** |

---

## 7. Provenance

The argument list is complete rather than sampled: a full `E8`/`E9` `rel32`
cross-reference scan of `.text` finds **16 call sites to `AddCmd`**, nine in
`Client::BuildCommandLineArgs` and seven in `gmClient::BuildCommandLineArgs`, and
`AddCmd` itself is the only caller of `CommandLineArgList::add`. Names and help
strings were read directly from the `push` operands at each site, not from the
decompiled C.

The switch-character finding was reached by locating the `Client` vtable
(`0x00794CF8`) via its `ArgumentParser::ParseArgs` entries, reading slot `+0x48`
to identify `IsCommandLineArgument` as the virtual that `ParseArgs` calls, and
then following `[esi+0x08]` back to the literal constructed in `Client::Client`.
