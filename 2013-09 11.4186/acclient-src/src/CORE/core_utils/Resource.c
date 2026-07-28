/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Resource
   Object     : CORE\core_utils\Resource.obj
   Functions  : 1
   Addresses  : 00410DC0 - 00410DC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00410DC0) --------------------------------------------------------  // acclient.c:77018
HINSTANCE__ *__fastcall GetModuleFromAddress(char *pModuleCode)
{
  _MEMORY_BASIC_INFORMATION mbi; // [sp+0h] [bp-1Ch]@1

  VirtualQuery(pModuleCode, &mbi, 0x1Cu);
  return (HINSTANCE__ *)mbi.AllocationBase;
}

