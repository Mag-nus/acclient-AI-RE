/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CombatManeuverTable
   Object     : AC\acgameplay_misc\CombatManeuverTable.obj
   Functions  : 18
   Addresses  : 004CBAC0 - 0070FD80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CBAC0) --------------------------------------------------------  // acclient.c:253083
signed int gmExternalContainerUI::GetUIElementType()
{
  return 268435469;
}

//----- (005CA540) --------------------------------------------------------  // acclient.c:501757
void __thiscall CombatManeuver::CombatManeuver(CombatManeuver *this)
{
  this->vfptr = (PackObjVtbl *)&CombatManeuver::vftable;
  this->style = 0;
  this->attack_height = 0;
  this->attack_type = 0;
  this->min_skill_level = 0;
  this->motion = 0;
}
// 7E8038: using guessed type int (__thiscall *CombatManeuver::vftable)(void *, char);

//----- (005CA560) --------------------------------------------------------  // acclient.c:501769
void __thiscall CombatManeuverTable::~CombatManeuverTable(CombatManeuverTable *this)
{
  CombatManeuverTable *v1; // esi@1
  CombatManeuver *v2; // ecx@1

  v1 = this;
  v2 = this->_cmt;
  v1->vfptr = (InterfaceVtbl *)&CombatManeuverTable::vftable;
  v1->vfptr = (PackObjVtbl *)&CombatManeuverTable::vftable;
  if ( v2 )
  {
    if ( v2[-1].motion )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v2[-1].motion);
    v1->_cmt = 0;
    v1->_num_combat_maneuvers = 0;
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E804C: using guessed type void *CombatManeuverTable::vftable;
// 7E8060: using guessed type __int32 (__stdcall *CombatManeuverTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CA5B0) --------------------------------------------------------  // acclient.c:501795
int __thiscall CombatManeuverTable::Pack(CombatManeuverTable *this, void **addr, unsigned int size)
{
  CombatManeuverTable *v3; // esi@1
  int v4; // ecx@1
  int result; // eax@1
  unsigned int v6; // edi@2
  int v7; // ebx@3
  unsigned int packed_size; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = *(_DWORD *)&this->m_bLoaded;
  result = 20 * v4 + 4;
  packed_size = 20 * v4 + 4;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v4;
    *addr = (char *)*addr + 4;
    v6 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      v7 = 0;
      do
      {
        (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)(v7 + *((_DWORD *)&v3->m_bLoaded + 1)) + 12))(
          v7 + *((_DWORD *)&v3->m_bLoaded + 1),
          addr,
          size);
        ++v6;
        v7 += 24;
      }
      while ( v6 < *(_DWORD *)&v3->m_bLoaded );
      result = packed_size;
    }
  }
  return result;
}

//----- (005CA620) --------------------------------------------------------  // acclient.c:501833
CombatManeuverTable *__thiscall CombatManeuverTable::vector_deleting_destructor(CombatManeuverTable *this, unsigned int a2)
{
  return CombatManeuverTable::scalar_deleting_destructor((CombatManeuverTable *)((char *)this - 48), a2);
}

//----- (005CA630) --------------------------------------------------------  // acclient.c:501839
int __thiscall CombatManeuverTable::Init(CombatManeuverTable *this, unsigned int num_combat_maneuvers)
{
  CombatManeuverTable *v2; // edi@1
  CombatManeuver *v3; // ecx@1
  void *v4; // eax@7
  int v5; // ebx@8
  int result; // eax@8

  v2 = this;
  v3 = this->_cmt;
  if ( v3 )
  {
    if ( v3[-1].motion )
      ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v3[-1].motion);
    v2->_cmt = 0;
    v2->_num_combat_maneuvers = 0;
  }
  v2->_num_combat_maneuvers = num_combat_maneuvers;
  if ( num_combat_maneuvers )
  {
    v4 = operator new[](24 * num_combat_maneuvers + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = num_combat_maneuvers;
      vector_constructor_iterator(
        (char *)v4 + 4,
        0x18u,
        num_combat_maneuvers,
        (void *(__thiscall *)(void *))CombatManeuver::CombatManeuver);
      v2->_cmt = (CombatManeuver *)v5;
      result = v5 != 0;
    }
    else
    {
      v2->_cmt = 0;
      result = 0;
    }
  }
  else
  {
    result = v2->_cmt == 0;
  }
  return result;
}

//----- (005CA6D0) --------------------------------------------------------  // acclient.c:501888
void __thiscall CombatManeuverTable::CombatManeuverTable(CombatManeuverTable *this, IDClass<_tagDataID,32,0> gid)
{
  CombatManeuverTable *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->_num_combat_maneuvers = 0;
  v2->_cmt = 0;
  v2->vfptr = (InterfaceVtbl *)&CombatManeuverTable::vftable;
  v2->vfptr = (PackObjVtbl *)&CombatManeuverTable::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E804C: using guessed type void *CombatManeuverTable::vftable;
// 7E8060: using guessed type __int32 (__stdcall *CombatManeuverTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CA700) --------------------------------------------------------  // acclient.c:501905
CombatManeuverTable *__thiscall CombatManeuverTable::scalar_deleting_destructor(CombatManeuverTable *this, unsigned int a2)
{
  CombatManeuverTable *v2; // esi@1

  v2 = this;
  CombatManeuverTable::~CombatManeuverTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005CA720) --------------------------------------------------------  // acclient.c:501917
int __thiscall CombatManeuverTable::UnPack(CombatManeuverTable *this, void **addr, unsigned int size)
{
  CombatManeuverTable *v3; // esi@1
  int result; // eax@2
  unsigned int v5; // ST0C_4@3
  unsigned int v6; // edi@4
  int v7; // ebx@5

  v3 = this;
  if ( size >= 20 * *(_DWORD *)&this->m_bLoaded + 4 )
  {
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = CombatManeuverTable::Init((CombatManeuverTable *)((char *)this - 48), v5);
    if ( result )
    {
      v6 = 0;
      if ( *(_DWORD *)&v3->m_bLoaded )
      {
        v7 = 0;
        do
        {
          (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)(*((_DWORD *)&v3->m_bLoaded + 1) + v7) + 16))(
            *((_DWORD *)&v3->m_bLoaded + 1) + v7,
            addr,
            size);
          ++v6;
          v7 += 24;
        }
        while ( v6 < *(_DWORD *)&v3->m_bLoaded );
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070FCC0) --------------------------------------------------------  // acclient.c:803043
int sub_70FCC0()
{
  return atexit(nullsub_1730);
}

//----- (0070FCD0) --------------------------------------------------------  // acclient.c:803049
int _E4_21()
{
  return atexit(_E5_21);
}

//----- (0070FCE0) --------------------------------------------------------  // acclient.c:803055
int _E7_21()
{
  Outside_CellID_21.id = Invalid_CellID_21.id + 1;
  return atexit(_E8_21);
}

//----- (0070FD00) --------------------------------------------------------  // acclient.c:803062
int _E10_20()
{
  In_Limbo_CellID_20.id = Outside_CellID_21.id + 1;
  return atexit(_E11_20);
}

//----- (0070FD20) --------------------------------------------------------  // acclient.c:803069
int _E13_20()
{
  First_Interior_CellID_20.id = In_Limbo_CellID_20.id + 1;
  return atexit(_E14_20);
}

//----- (0070FD40) --------------------------------------------------------  // acclient.c:803076
int _E16_20()
{
  Last_Interior_CellID_20.id = Invalid_CellID_21.id - 1;
  return atexit(_E17_20);
}

//----- (0070FD60) --------------------------------------------------------  // acclient.c:803083
int _E21_22()
{
  return atexit(_E22_22);
}

//----- (0070FD70) --------------------------------------------------------  // acclient.c:803089
int _E40_22()
{
  return atexit(_E41_22);
}

//----- (0070FD80) --------------------------------------------------------  // acclient.c:803095
int _E43_25()
{
  return atexit(_E44_25);
}

