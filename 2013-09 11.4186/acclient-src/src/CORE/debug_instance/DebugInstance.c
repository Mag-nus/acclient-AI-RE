/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DebugInstance
   Object     : CORE\debug_instance\DebugInstance.obj
   Functions  : 2
   Addresses  : 006C3B40 - 00725E50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C3B40) --------------------------------------------------------  // acclient.c:732126
int _E73_7()
{
  Turbine::Debug::Debug(&g_commonDebug);
  return atexit(_E74_10);
}

//----- (00725E50) --------------------------------------------------------  // acclient.c:823687
void __cdecl _E74_10()
{
  Turbine::Debug::~Debug(&g_commonDebug);
}

