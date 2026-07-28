/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Profiler
   Object     : ENGINE\profiler\Profiler.obj
   Functions  : 1
   Addresses  : 005DD210 - 005DD210 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005DD210) --------------------------------------------------------  // acclient.c:519979
void __cdecl Profiler::ResetFrameStats()
{
  qmemcpy(&Profiler::CapturedStats, &Profiler::Stats, sizeof(Profiler::CapturedStats));
  memset(&unk_8F1134, 0, 0x2A8u);
  Profiler::NumActiveCategories = 1;
  Profiler::ActiveCategories = 0;
}
// 8F10C0: using guessed type enum ProfilerTypes::CategoryType *Profiler::ActiveCategories;
// 8F10D4: using guessed type unsigned __int32 Profiler::NumActiveCategories;
// 8F13E0: using guessed type struct ProfilerStats Profiler::CapturedStats;

