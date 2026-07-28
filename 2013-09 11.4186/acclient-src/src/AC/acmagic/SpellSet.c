/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellSet
   Object     : AC\acmagic\SpellSet.obj
   Functions  : 16
   Addresses  : 005BD0D0 - 0070EE80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BD0D0) --------------------------------------------------------  // acclient.c:488312
int __thiscall SpellSetTierList::GetPackSize(SpellSetTierList *this)
{
  PackObjVtbl *v1; // eax@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this->m_SpellList.vfptr;
  dummy = 0;
  return ((int (__thiscall *)(PackObjVtbl **, void **, _DWORD))v1->Pack)(&this->m_SpellList.vfptr, &dummy, 0) + 4;
}

//----- (005BD0F0) --------------------------------------------------------  // acclient.c:488324
unsigned int __thiscall SpellSetTierList::Pack(SpellSetTierList *this, void **addr, unsigned int size)
{
  SpellSetTierList *v3; // esi@1
  unsigned int v4; // edi@1

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->m_PieceCount;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->m_SpellList.vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (005BD130) --------------------------------------------------------  // acclient.c:488341
int __thiscall SpellSetTierList::UnPack(SpellSetTierList *this, void **addr, unsigned int size)
{
  SpellSetTierList *v3; // esi@1
  int result; // eax@2

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    v3->m_PieceCount = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->m_SpellList.vfptr->UnPack)(addr, size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BD170) --------------------------------------------------------  // acclient.c:488362
int __thiscall SpellSet::GetPackSize(SpellSet *this)
{
  PackObjVtbl *v1; // eax@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this->m_countTiers.vfptr;
  dummy = 0;
  return ((int (__thiscall *)(PackObjVtbl **, void **, _DWORD))v1->Pack)(&this->m_countTiers.vfptr, &dummy, 0);
}

//----- (005BD190) --------------------------------------------------------  // acclient.c:488374
unsigned int __thiscall SpellSet::Pack(SpellSet *this, void **addr, unsigned int size)
{
  SpellSet *v3; // esi@1
  unsigned int v4; // edi@1

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_countTiers.vfptr->Pack)(&v3->m_countTiers.vfptr, addr, size);
  return v4;
}

//----- (005BD1C0) --------------------------------------------------------  // acclient.c:488387
int __thiscall SpellSet::UnPack(SpellSet *this, void **addr, unsigned int size)
{
  SpellSet *v3; // esi@1
  int result; // eax@2

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_countTiers.vfptr->UnPack)(
      &v3->m_countTiers.vfptr,
      addr,
      size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BD1F0) --------------------------------------------------------  // acclient.c:488409
void __thiscall SpellSetTierList::SpellSetTierList(SpellSetTierList *this, SpellSetTierList *from)
{
  SpellSetTierList *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&SpellSetTierList::vftable;
  v3 = (char *)&this->m_SpellList;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 4) = &PackObj::vftable;
  *(_DWORD *)v3 = &PList<unsigned long>::vftable;
  *((_DWORD *)v3 + 4) = &PList<unsigned long>::vftable;
  v2->m_PieceCount = from->m_PieceCount;
  AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)v3, (int)&from->m_SpellList);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 7E4878: using guessed type int (__thiscall *SpellSetTierList::vftable)(void *, char);

//----- (0070EDC0) --------------------------------------------------------  // acclient.c:801887
int sub_70EDC0()
{
  return atexit(nullsub_1608);
}

//----- (0070EDD0) --------------------------------------------------------  // acclient.c:801893
int _E4_11()
{
  return atexit(_E5_11);
}

//----- (0070EDE0) --------------------------------------------------------  // acclient.c:801899
int _E7_11()
{
  Outside_CellID_11.id = Invalid_CellID_11.id + 1;
  return atexit(_E8_11);
}

//----- (0070EE00) --------------------------------------------------------  // acclient.c:801906
int _E10_10()
{
  In_Limbo_CellID_10.id = Outside_CellID_11.id + 1;
  return atexit(_E11_10);
}

//----- (0070EE20) --------------------------------------------------------  // acclient.c:801913
int _E13_10()
{
  First_Interior_CellID_10.id = In_Limbo_CellID_10.id + 1;
  return atexit(_E14_10);
}

//----- (0070EE40) --------------------------------------------------------  // acclient.c:801920
int _E16_10()
{
  Last_Interior_CellID_10.id = Invalid_CellID_11.id - 1;
  return atexit(_E17_10);
}

//----- (0070EE60) --------------------------------------------------------  // acclient.c:801927
int _E21_12()
{
  return atexit(_E22_12);
}

//----- (0070EE70) --------------------------------------------------------  // acclient.c:801933
int _E40_12()
{
  return atexit(_E41_12);
}

//----- (0070EE80) --------------------------------------------------------  // acclient.c:801939
int _E43_15()
{
  return atexit(_E44_15);
}

