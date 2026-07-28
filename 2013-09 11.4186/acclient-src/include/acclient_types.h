/* Type definitions for the decompilation.
 *
 * IDA exports a decompiled program as TWO files: acclient.c (code) and
 * acclient.h (the local type library -- 70,719 lines, 10,992 struct/union/enum
 * /typedef definitions). acclient.c does NOT #include acclient.h; you are
 * expected to supply it yourself. Its own include block is only:
 *
 *     #include <windows.h>
 *     #include <math.h>
 *     #include <defs.h>
 *     #include <stdarg.h>
 *
 * So every program type -- PackObj, CObjectMaint, ACCWeenieObject, Palette,
 * PStringBase, the 6,936 structs and 410 enums -- is undefined unless
 * acclient.h is pulled in. That is why a name such as PackObj appears in
 * acclient_protos.h with no visible definition: it is declared at
 * acclient.h:26018 and referenced 1,063 times from acclient.c.
 *
 * This header exists to close that gap. It forwards to the real file rather
 * than copying it, so ../../acclient.h stays the single source of truth.
 *
 * Include order matters: acclient.h uses the Hex-Rays sized-integer aliases,
 * so include/defs.h (via acclient_prologue.h) must come first. The generated
 * sources already chain them in the right order:
 *
 *     acclient_prologue.h   windows.h, math.h, defs.h, stdarg.h
 *     acclient_types.h      <- this file
 *     acclient_protos.h     function prototypes
 *     acclient_data.h       globals, vtables, string literals
 *
 * Caveat: acclient.h carries no include guard of its own, hence the one here.
 * It also contains overloaded members inside __cppobj structs (several
 * GetPackSize entries in PackObj, for example), which is valid C++ but not
 * valid C -- another reason this tree browses rather than builds.
 */

#ifndef _ACCLIENT_TYPES_H
#define _ACCLIENT_TYPES_H

#include "../../acclient.h"

#endif /* _ACCLIENT_TYPES_H */
