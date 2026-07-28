/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceProfile
   Object     : AC\acallegiance\AllegianceProfile.obj
   Functions  : 16
   Addresses  : 005B6A20 - 0070E6E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B6A20) --------------------------------------------------------  // acclient.c:481511
int __thiscall AllegianceProfile::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 272) = *(_DWORD *)(a2 + 272);
    *(_DWORD *)(this + 276) = *(_DWORD *)(a2 + 276);
    AllegianceHierarchy::operator=((AllegianceHierarchy *)(this + 4), a2 + 4);
  }
  return v2;
}

//----- (005B6A60) --------------------------------------------------------  // acclient.c:481526
void __thiscall AllegianceProfile::Clear(AllegianceProfile *this)
{
  this->_total_members = 0;
  this->_total_vassals = 0;
  AllegianceHierarchy::Clear(&this->_allegiance);
}

//----- (005B6A80) --------------------------------------------------------  // acclient.c:481534
unsigned int __thiscall AllegianceProfile::GetMonarch(AllegianceProfile *this, AllegianceData *retval)
{
  AllegianceHierarchy *v2; // edi@1
  const unsigned int v3; // esi@1

  v2 = &this->_allegiance;
  v3 = AllegianceHierarchy::GetMonarchID(&this->_allegiance);
  if ( v3 )
    AllegianceHierarchy::LookUp(v2, v3, retval);
  return v3;
}

//----- (005B6AB0) --------------------------------------------------------  // acclient.c:481547
unsigned int __thiscall AllegianceProfile::GetPatron(AllegianceProfile *this, unsigned int id, AllegianceData *retval)
{
  return AllegianceHierarchy::GetPatron(&this->_allegiance, id, retval);
}

//----- (005B6AC0) --------------------------------------------------------  // acclient.c:481553
unsigned int __thiscall AllegianceProfile::GetFirstVassal(AllegianceProfile *this, unsigned int id, AllegianceData *retval)
{
  return AllegianceHierarchy::GetFirstVassal(&this->_allegiance, id, retval);
}

//----- (005B6AD0) --------------------------------------------------------  // acclient.c:481559
unsigned int __thiscall AllegianceProfile::GetNextVassal(AllegianceProfile *this, unsigned int vassal_id, AllegianceData *retval)
{
  return AllegianceHierarchy::GetNextVassal(&this->_allegiance, vassal_id, retval);
}

//----- (005B6AE0) --------------------------------------------------------  // acclient.c:481565
int __thiscall AllegianceProfile::GetData(AllegianceProfile *this, unsigned int id, AllegianceData *retval)
{
  return AllegianceHierarchy::LookUp(&this->_allegiance, id, retval);
}

//----- (005B6AF0) --------------------------------------------------------  // acclient.c:481571
int __thiscall AllegianceProfile::GetPackSize(AllegianceProfile *this)
{
  PackObjVtbl *v1; // eax@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this->_allegiance.vfptr;
  dummy = 0;
  return ((int (__thiscall *)(AllegianceHierarchy *, void **, _DWORD))v1->Pack)(&this->_allegiance, &dummy, 0) + 8;
}

//----- (005B6B10) --------------------------------------------------------  // acclient.c:481583
void __thiscall AllegianceProfile::AllegianceProfile(AllegianceProfile *this)
{
  AllegianceProfile *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AllegianceProfile::vftable;
  AllegianceHierarchy::AllegianceHierarchy(&this->_allegiance);
  v1->_total_members = 0;
  v1->_total_vassals = 0;
}
// 7E6D3C: using guessed type int (__thiscall *AllegianceProfile::vftable)(void *, char);

//----- (005B6B40) --------------------------------------------------------  // acclient.c:481596
unsigned int __thiscall AllegianceProfile::Pack(AllegianceProfile *this, void **addr, unsigned int size)
{
  AllegianceProfile *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // ebx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_total_members;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_total_vassals;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->_allegiance.vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (005B6B90) --------------------------------------------------------  // acclient.c:481617
int __thiscall AllegianceProfile::UnPack(AllegianceProfile *this, void **addr, unsigned int size)
{
  AllegianceProfile *v3; // edi@1
  char *v4; // esi@1
  int result; // eax@2
  char *v6; // ecx@3

  v3 = this;
  v4 = (char *)&this->_allegiance;
  if ( size >= ((int (__thiscall *)(AllegianceHierarchy *))this->_allegiance.vfptr[1].__vecDelDtor)(&this->_allegiance)
             + 8 )
  {
    v3->_total_members = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->_total_vassals = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
    result = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 16))(v4, addr, size);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6BF0) --------------------------------------------------------  // acclient.c:481644
AllegianceProfile *__thiscall AllegianceProfile::scalar_deleting_destructor(AllegianceProfile *this, unsigned int a2)
{
  AllegianceProfile *v2; // esi@1

  v2 = this;
  AllegianceHierarchy::~AllegianceHierarchy(&this->_allegiance);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0070E680) --------------------------------------------------------  // acclient.c:801417
void sub_70E680()
{
  flt_8EF3E8 = 1000.0 + 1.0;
}

//----- (0070E6A0) --------------------------------------------------------  // acclient.c:801423
void sub_70E6A0()
{
  flt_8EF3EC = 24.0 * 8.0;
}

//----- (0070E6C0) --------------------------------------------------------  // acclient.c:801429
void sub_70E6C0()
{
  flt_8EF3F0 = 24.0 * 0.5;
}

//----- (0070E6E0) --------------------------------------------------------  // acclient.c:801435
int sub_70E6E0()
{
  return atexit(nullsub_1553);
}

