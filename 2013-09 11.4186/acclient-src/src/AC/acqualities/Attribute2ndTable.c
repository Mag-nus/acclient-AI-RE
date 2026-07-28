/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Attribute2ndTable
   Object     : AC\acqualities\Attribute2ndTable.obj
   Functions  : 8
   Addresses  : 004E65A0 - 0070FFF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004E65A0) --------------------------------------------------------  // acclient.c:276299
signed int Attribute2ndTable::GetDBOType()
{
  return 268435459;
}

//----- (005CB3D0) --------------------------------------------------------  // acclient.c:502862
unsigned int __thiscall Attribute2ndTable::Pack(Attribute2ndTable *this, void **addr, unsigned int size)
{
  Attribute2ndTable *v3; // esi@1
  int v4; // eax@1
  char *v5; // ebx@1
  char *v6; // ebp@1
  int v7; // edi@1
  int v8; // edi@1
  unsigned int v9; // edi@1
  int v11; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = *(_DWORD *)&this->m_bLoaded;
  v11 = 0;
  v5 = (char *)&this->_max_health._formula._y;
  v6 = (char *)&this->m_DID;
  v7 = (*(int (__thiscall **)(bool *, int *, _DWORD))(v4 + 12))(&this->m_bLoaded, &v11, 0);
  v8 = (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v5 + 12))(&v3->_max_health._formula._y, &v11, 0) + v7;
  v9 = (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v6 + 12))(&v3->m_DID, &v11, 0) + v8;
  if ( size >= v9 )
  {
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 12))(&v3->m_bLoaded, addr, size);
    (*(void (__thiscall **)(int, void **, unsigned int))(v3->m_DID.id + 12))(&v3->m_DID, addr, size);
    (*(void (__thiscall **)(int, void **, unsigned int))(v3->_max_health._formula._y + 12))(
      &v3->_max_health._formula._y,
      addr,
      size);
  }
  return v9;
}

//----- (005CB450) --------------------------------------------------------  // acclient.c:502894
int __thiscall Attribute2ndTable::UnPack(Attribute2ndTable *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  Attribute2ndTable *v4; // esi@1
  unsigned int v5; // edx@1
  char *v6; // ebx@1
  char *v7; // ebp@1
  int v8; // ST2C_4@1
  int v9; // ST2C_4@1
  int v10; // eax@1
  unsigned int v11; // ebx@1
  void *start; // [sp+30h] [bp-4h]@1

  v3 = addr;
  v4 = this;
  v5 = this->m_DID.id;
  start = *addr;
  addr = 0;
  v6 = (char *)&this->_max_health._formula._y;
  v7 = (char *)&this->m_bLoaded;
  v8 = (*(int (__thiscall **)(IDClass<_tagDataID,32,0> *, void ***, _DWORD))(v5 + 12))(&this->m_DID, &addr, 0);
  v9 = (*(int (__thiscall **)(int, void ***, _DWORD))(*(_DWORD *)v7 + 12))(&v4->m_bLoaded, &addr, 0) + v8;
  v10 = (*(int (__thiscall **)(int, void ***, _DWORD))(*(_DWORD *)v6 + 12))(&v4->_max_health._formula._y, &addr, 0);
  v11 = size;
  if ( size < v10 + v9 )
    return 0;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v4->m_bLoaded + 16))(&v4->m_bLoaded, v3, size);
  (*(void (__thiscall **)(int, void **, unsigned int))(v4->m_DID.id + 16))(&v4->m_DID, v3, v11);
  (*(void (__thiscall **)(int, void **, unsigned int))(v4->_max_health._formula._y + 16))(
    &v4->_max_health._formula._y,
    v3,
    v11);
  if ( v11 < (_BYTE *)*v3 - (_BYTE *)start )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (005CB510) --------------------------------------------------------  // acclient.c:502935
void __thiscall Attribute2ndTable::Attribute2ndTable(Attribute2ndTable *this, IDClass<_tagDataID,32,0> did)
{
  Attribute2ndTable *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&Attribute2ndTable::vftable;
  v2->vfptr = (PackObjVtbl *)&Attribute2ndTable::vftable;
  v2->_max_health.vfptr = (PackObjVtbl *)&Attribute2ndBase::vftable;
  v2->_max_health._formula._w = 0;
  v2->_max_health._formula._x = 0;
  v2->_max_health._formula._y = 0;
  v2->_max_health._formula._attr1 = 0;
  v2->_max_health._formula._attr2 = 0;
  v2->_max_health._formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v2->_max_health._formula._z = 1;
  v2->_max_stamina.vfptr = (PackObjVtbl *)&Attribute2ndBase::vftable;
  v2->_max_stamina._formula._w = 0;
  v2->_max_stamina._formula._x = 0;
  v2->_max_stamina._formula._y = 0;
  v2->_max_stamina._formula._attr1 = 0;
  v2->_max_stamina._formula._attr2 = 0;
  v2->_max_stamina._formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v2->_max_stamina._formula._z = 1;
  v2->_max_mana.vfptr = (PackObjVtbl *)&Attribute2ndBase::vftable;
  v2->_max_mana._formula._w = 0;
  v2->_max_mana._formula._x = 0;
  v2->_max_mana._formula._y = 0;
  v2->_max_mana._formula._attr1 = 0;
  v2->_max_mana._formula._attr2 = 0;
  v2->_max_mana._formula.vfptr = (PackObjVtbl *)&SkillFormula::vftable;
  v2->_max_mana._formula._z = 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A016C: using guessed type int (__thiscall *SkillFormula::vftable)(void *, char);
// 7C3FDC: using guessed type int (__thiscall *Attribute2ndBase::vftable)(void *, char);
// 7E8150: using guessed type void *Attribute2ndTable::vftable;
// 7E8168: using guessed type __int32 (__stdcall *Attribute2ndTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CB5B0) --------------------------------------------------------  // acclient.c:502976
Attribute2ndTable *__thiscall Attribute2ndTable::vector_deleting_destructor(Attribute2ndTable *this, unsigned int a2)
{
  return Attribute2ndTable::vector_deleting_destructor((Attribute2ndTable *)((char *)this - 48), a2);
}

//----- (005CB5C0) --------------------------------------------------------  // acclient.c:502982
Attribute2ndTable *__thiscall Attribute2ndTable::vector_deleting_destructor(Attribute2ndTable *this, unsigned int a2)
{
  Attribute2ndTable *v2; // esi@1

  v2 = this;
  Attribute2ndTable::~Attribute2ndTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005CB5E0) --------------------------------------------------------  // acclient.c:502994
void __thiscall Attribute2ndTable::~Attribute2ndTable(Attribute2ndTable *this)
{
  this->vfptr = (InterfaceVtbl *)&Attribute2ndTable::vftable;
  this->vfptr = (PackObjVtbl *)&Attribute2ndTable::vftable;
  this->_max_mana._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_max_mana.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_max_stamina._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_max_stamina.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_max_health._formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->_max_health.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&this->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8150: using guessed type void *Attribute2ndTable::vftable;
// 7E8168: using guessed type __int32 (__stdcall *Attribute2ndTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070FFF0) --------------------------------------------------------  // acclient.c:803271
int sub_70FFF0()
{
  return atexit(nullsub_1834);
}

