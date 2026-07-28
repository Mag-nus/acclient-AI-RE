/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CContractTrackerTable
   Object     : AC\accquest\CContractTrackerTable.obj
   Functions  : 5
   Addresses  : 005992B0 - 0070AF80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005992B0) --------------------------------------------------------  // acclient.c:451448
void __thiscall CContractTrackerTable::CContractTrackerTable(CContractTrackerTable *this)
{
  CContractTrackerTable *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->_contractTrackerHash;
  v1->vfptr = (PackObjVtbl *)&CContractTrackerTable::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,CContractTracker>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 32;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
}
// 7A6930: using guessed type int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char);
// 7CC8F0: using guessed type int (__thiscall *CContractTrackerTable::vftable)(void *, char);

//----- (0070AF20) --------------------------------------------------------  // acclient.c:798140
void sub_70AF20()
{
  flt_87111C = 1000.0 + 1.0;
}

//----- (0070AF40) --------------------------------------------------------  // acclient.c:798146
void sub_70AF40()
{
  flt_871120 = 24.0 * 8.0;
}

//----- (0070AF60) --------------------------------------------------------  // acclient.c:798152
void sub_70AF60()
{
  flt_871124 = 24.0 * 0.5;
}

//----- (0070AF80) --------------------------------------------------------  // acclient.c:798158
int sub_70AF80()
{
  return atexit(nullsub_1434);
}

