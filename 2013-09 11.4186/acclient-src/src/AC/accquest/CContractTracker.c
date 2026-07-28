/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CContractTracker
   Object     : AC\accquest\CContractTracker.obj
   Functions  : 9
   Addresses  : 00599120 - 0070AF10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00599120) --------------------------------------------------------  // acclient.c:451342
int __thiscall CContractTracker::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  return result;
}

//----- (00599160) --------------------------------------------------------  // acclient.c:451360
void __thiscall CContractTracker::CContractTracker(CContractTracker *this)
{
  this->vfptr = (PackObjVtbl *)&CContractTracker::vftable;
  this->_version = 0;
  this->_contract_id = 0;
  this->_contract_stage = 0;
  *(_QWORD *)&this->_time_when_done = 0i64;
  *(_QWORD *)&this->_time_when_repeats = 0i64;
  *(_QWORD *)&this->_time_of_server_update = 0i64;
}
// 7E4F4C: using guessed type int (__thiscall *CContractTracker::vftable)(void *, char);

//----- (00599190) --------------------------------------------------------  // acclient.c:451373
void __thiscall CContractTracker::CContractTracker(CContractTracker *this, CContractTracker *_contract)
{
  this->vfptr = (PackObjVtbl *)&CContractTracker::vftable;
  this->_version = _contract->_version;
  this->_contract_id = _contract->_contract_id;
  this->_contract_stage = _contract->_contract_stage;
  this->_time_when_done = _contract->_time_when_done;
  this->_time_when_repeats = _contract->_time_when_repeats;
  this->_time_of_server_update = _contract->_time_of_server_update;
}
// 7E4F4C: using guessed type int (__thiscall *CContractTracker::vftable)(void *, char);

//----- (005991E0) --------------------------------------------------------  // acclient.c:451386
signed int __thiscall CContractTracker::Pack(CContractTracker *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2
  char *v5; // esi@2
  char *v6; // edx@2

  if ( size >= 0x1C )
  {
    *(_DWORD *)*addr = 0;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->_contract_id;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->_contract_stage;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(double *)v5 = this->_time_when_done;
    v6 = (char *)*addr + 8;
    *addr = v6;
    *(double *)v6 = this->_time_when_repeats;
    *addr = (char *)*addr + 8;
  }
  return 28;
}

//----- (00599240) --------------------------------------------------------  // acclient.c:451414
int __thiscall CContractTracker::UnPack(CContractTracker *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // esi@3
  char *v5; // edx@3
  char *v6; // esi@3
  char *v7; // edx@3

  if ( size >= 0x1C )
  {
    this->_version = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    this->_contract_id = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->_contract_stage = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_QWORD *)&this->_time_when_done = *(_QWORD *)v6;
    v7 = (char *)*addr + 8;
    *addr = v7;
    *(_QWORD *)&this->_time_when_repeats = *(_QWORD *)v7;
    *addr = (char *)*addr + 8;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070AEB0) --------------------------------------------------------  // acclient.c:798116
void sub_70AEB0()
{
  flt_8710FC = 1000.0 + 1.0;
}

//----- (0070AED0) --------------------------------------------------------  // acclient.c:798122
void sub_70AED0()
{
  flt_871100 = 24.0 * 8.0;
}

//----- (0070AEF0) --------------------------------------------------------  // acclient.c:798128
void sub_70AEF0()
{
  flt_871104 = 24.0 * 0.5;
}

//----- (0070AF10) --------------------------------------------------------  // acclient.c:798134
int sub_70AF10()
{
  return atexit(nullsub_1433);
}

