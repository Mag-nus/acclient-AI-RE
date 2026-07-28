/* Minimal stand-in for the Hex-Rays defs.h.
 *
 * acclient.c opens with #include <defs.h>, an IDA header that is not part of
 * this decompilation. This file supplies the subset needed to browse the code.
 *
 * NAVIGATION ONLY. This tree is decompiler output and does not compile; see
 * ../README.md. Nothing here alters the extracted function bodies.
 *
 * EVIDENCE RULE
 * -------------
 * Every declaration below is justified, and the justification is stated. Use
 * counts are of CODE occurrences in acclient.c with comments and string/char
 * literals stripped first -- an earlier draft of this file counted raw text and
 * consequently carried three declarations (uint32, int64, MEMORY) that occur
 * only inside string literals such as "Not an int64." and never in code. Those
 * have been removed, along with 36 others that appear nowhere at all.
 *
 * Where a type genuinely cannot be determined, nothing is declared. See the
 * _UNKNOWN note below.
 */

#ifndef _HEXRAYS_DEFS_H
#define _HEXRAYS_DEFS_H

#include <stddef.h>

/* ---- sized integer aliases -------------------------------------------
 * These are Hex-Rays naming conventions in which the width is part of the
 * name, so the mapping is fixed by the convention rather than inferred from
 * this binary. Signedness follows Hex-Rays: the underscore-prefixed forms are
 * unsigned.
 */
typedef unsigned char       _BYTE;      /* 5,425 code uses */
typedef unsigned short      _WORD;      /* 4,160 code uses */
typedef unsigned int        _DWORD;     /* 54,614 code uses */
typedef unsigned __int64    _QWORD;     /* 1,680 code uses */

/* ---- _UNKNOWN is DELIBERATELY NOT DEFINED ----------------------------
 *
 * Hex-Rays emits _UNKNOWN for a symbol whose type it could not determine
 * (185 code uses, 172 of them declarations in acclient_data.h). Giving it a
 * concrete typedef would assert a size and layout that are not known and would
 * propagate that guess into anything read off the back of it.
 *
 * Consequence: _UNKNOWN unk_907938; will not parse. That is the intended
 * signal, not a defect to paper over.
 *
 * Recover real types from the binary instead. Spacing between adjacent symbols
 * gives array extents -- SceneTool::m_oldViewMatrix / m_oldProjMatrix /
 * m_oldWorldMatrix sit exactly 0x40 apart, so each is 16 floats. Bytes give
 * scalar values -- CombatSystem::AUGMENTATION_CRITICAL_DEFENSE_PK_AVOID_CHANCE
 * at 0x00822C44 holds 0x3D4CCCCD, i.e. float 0.05.
 */

/* ---- calling conventions ---------------------------------------------
 * acclient.c itself does #define __thiscall __cdecl (36,908 uses). __usercall
 * and __userpurge are IDA annotations for register-based conventions that have
 * no C spelling; 222 and 273 code uses respectively, so 495 functions in total.
 *
 * Neutralising them lets the declarations parse but DISCARDS the argument
 * placement, which was the whole content of the annotation. Do not trust the
 * signatures of those 495 functions.
 */
#ifndef __usercall
#define __usercall  __cdecl
#endif
#ifndef __userpurge
#define __userpurge __cdecl
#endif

/* ---- sub-register accessors ------------------------------------------
 * Hex-Rays convention: extract a sub-register from a wider value. The cast
 * widths are fixed by the macro names.
 */
#define LOBYTE(x)   (*((_BYTE  *)&(x)))     /* 1,606 */
#define LOWORD(x)   (*((_WORD  *)&(x)))     /*   365 */
#define LODWORD(x)  (*((_DWORD *)&(x)))     /* 4,341 */
#define HIBYTE(x)   (*((_BYTE  *)&(x) + 1)) /*    92 */
#define HIWORD(x)   (*((_WORD  *)&(x) + 1)) /*    19 */
#define HIDWORD(x)  (*((_DWORD *)&(x) + 1)) /*   957 */

#define BYTE1(x)    (*((_BYTE *)&(x) + 1))  /*   583 */
#define BYTE2(x)    (*((_BYTE *)&(x) + 2))  /*   205 */
#define BYTE3(x)    (*((_BYTE *)&(x) + 3))  /*   301 */
#define BYTE4(x)    (*((_BYTE *)&(x) + 4))  /*    12 */
#define BYTE5(x)    (*((_BYTE *)&(x) + 5))  /*     2 */
#define WORD2(x)    (*((_WORD *)&(x) + 2))  /*     8 */

#define SBYTE1(x)   (*((char  *)&(x) + 1))  /*    27 */
#define SLOBYTE(x)  (*((char  *)&(x)))      /*    21 */
#define SHIDWORD(x) (*((int   *)&(x) + 1))  /*    79 */

/* ---- helper intrinsics ------------------------------------------------
 * Hex-Rays generates these for CPU flag arithmetic and 64-bit pair
 * construction. In the real IDA header they are size-polymorphic, so a fixed
 * C prototype cannot be correct for every call site.
 *
 * The RETURN types below are inferred from observed use and the evidence is
 * given. The PARAMETER lists are deliberately left empty, which in C means
 * "unspecified" rather than "none" -- this file asserts nothing about the
 * arguments, because the operands vary in width (e.g. __CFADD__ is applied to
 * both 32-bit and 64-bit values). Note that under C++ semantics an empty list
 * would mean "no parameters"; these are .c files and are read as C.
 */

/* Returns 64 bits: of 23 type-carrying assignments, 21 write through
 * *(_QWORD *) and 2 through *(_DWORD *) (narrowing). 113 code uses. */
unsigned __int64 __PAIR__();

/* Flag results. __OFSUB__ 117 uses, __CFADD__ 27, __SETP__ 1. Used both in
 * boolean tests and in arithmetic, consistent with a 0/1 result. */
char __OFSUB__();
char __CFADD__();
char __SETP__();

#endif /* _HEXRAYS_DEFS_H */
