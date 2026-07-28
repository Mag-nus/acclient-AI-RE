/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsScript
   Object     : PORTAL\canim\CPhysicsScript.obj
   Functions  : 12
   Addresses  : 00521600 - 006FD630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00521600) --------------------------------------------------------  // acclient.c:336265
int __cdecl PhysicsScriptData::Sort(const void *a, const void *b)
{
  int result; // eax@1

  result = -1;
  if ( *(double *)*(_DWORD *)a >= *(double *)*(_DWORD *)b )
    result = 1;
  return result;
}

//----- (00521630) --------------------------------------------------------  // acclient.c:336276
int __thiscall OldSmartArray<PhysicsScriptData *>::Grow(OldSmartArray<PhysicsScriptData *> *this, int _size)
{
  OldSmartArray<PhysicsScriptData *> *v2; // esi@1
  int result; // eax@1
  int v4; // edi@1
  int i; // eax@3

  v2 = this;
  result = (int)operator new[](4 * _size);
  v4 = result;
  if ( result )
  {
    if ( v2->data )
    {
      for ( i = 0; i < v2->num_in_array; ++i )
        *(_DWORD *)(v4 + 4 * i) = v2->data[i];
      operator delete[](v2->data);
    }
    v2->data = (PhysicsScriptData **)v4;
    v2->mem_size = _size;
    result = 1;
  }
  return result;
}

//----- (00521690) --------------------------------------------------------  // acclient.c:336302
void __thiscall PhysicsScript::PhysicsScript(PhysicsScript *this)
{
  PhysicsScript *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8444C8);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&PhysicsScript::vftable;
  v1->vfptr = (PackObjVtbl *)&PhysicsScript::vftable;
  v1->script_data.data = 0;
  v1->script_data.mem_size = 0;
  v1->script_data.num_in_array = 0;
  v1->script_data.grow_size = 2;
  LODWORD(v1->length) = 0;
  HIDWORD(v1->length) = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7BEC: using guessed type void *PhysicsScript::vftable;
// 7C7C00: using guessed type __int32 (__stdcall *PhysicsScript::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005216D0) --------------------------------------------------------  // acclient.c:336323
signed int PhysicsScript::GetDBOType()
{
  return 43;
}

//----- (005216E0) --------------------------------------------------------  // acclient.c:336329
PhysicsScript *__thiscall PhysicsScript::vector_deleting_destructor(PhysicsScript *this, unsigned int a2)
{
  return PhysicsScript::scalar_deleting_destructor((PhysicsScript *)((char *)this - 48), a2);
}

//----- (005216F0) --------------------------------------------------------  // acclient.c:336335
void __thiscall PhysicsScript::Destroy(PhysicsScript *this)
{
  PhysicsScript *v1; // esi@1
  int i; // edi@1
  PhysicsScriptData *v3; // ebx@2
  CAnimHook *v4; // ecx@3
  void *v5; // ST04_4@7

  v1 = this;
  for ( i = 0; i < v1->script_data.num_in_array; ++i )
  {
    v3 = v1->script_data.data[i];
    if ( v3 )
    {
      v4 = v3->hook;
      if ( v4 )
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
      operator delete(v3);
    }
    v1->script_data.data[i] = 0;
  }
  v5 = v1->script_data.data;
  v1->script_data.mem_size = 0;
  v1->script_data.num_in_array = 0;
  operator delete[](v5);
  v1->script_data.data = 0;
}

//----- (00521760) --------------------------------------------------------  // acclient.c:336364
void __thiscall PhysicsScript::GetSubDataIDs(PhysicsScript *this, QualifiedDataIDArray *id_array)
{
  PhysicsScript *v2; // edi@1
  int i; // esi@1

  v2 = this;
  for ( i = 0; i < v2->script_data.num_in_array; ++i )
    ((void (__stdcall *)(QualifiedDataIDArray *))v2->script_data.data[i]->hook->vfptr->GetSubDataIDs)(id_array);
}

//----- (00521790) --------------------------------------------------------  // acclient.c:336375
int __thiscall PhysicsScript::pack_size(PhysicsScript *this)
{
  PhysicsScript *v1; // ebx@1
  int v2; // edi@1
  signed int i; // esi@1
  int result; // eax@4

  v1 = this;
  v2 = 0;
  for ( i = 4; v2 < v1->script_data.num_in_array; ++v2 )
    i += CAnimHook::PackSize(v1->script_data.data[v2]->hook) + 8;
  if ( i & 3 )
    result = i + 4 - (i & 3);
  else
    result = i;
  return result;
}

//----- (005217E0) --------------------------------------------------------  // acclient.c:336394
int __thiscall PhysicsScript::Pack(PhysicsScript *this, void **addr, unsigned int size)
{
  PhysicsScript *v3; // ebx@1
  int result; // eax@1
  int v5; // ebp@2
  int v6; // edi@3
  void *v7; // ecx@4
  int v8; // edx@7
  int v9; // ecx@8
  unsigned int retval; // [sp+0h] [bp-4h]@1

  v3 = this;
  result = PhysicsScript::pack_size((PhysicsScript *)((char *)this - 48));
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = HIDWORD(v3->m_timeStamp);
    *addr = (char *)*addr + 4;
    v5 = 0;
    if ( SHIDWORD(v3->m_timeStamp) > 0 )
    {
      do
      {
        v6 = *(_DWORD *)(*(_DWORD *)&v3->m_bLoaded + 4 * v5);
        if ( size >= CAnimHook::PackSize(*(CAnimHook **)(v6 + 8)) + 8 )
        {
          v7 = *addr;
          *(_DWORD *)v7 = *(_DWORD *)v6;
          *((_DWORD *)v7 + 1) = *(_DWORD *)(v6 + 4);
          *addr = (char *)*addr + 8;
          CAnimHook::PackHook(*(CAnimHook **)(v6 + 8), addr, size);
        }
        ++v5;
      }
      while ( v5 < SHIDWORD(v3->m_timeStamp) );
      result = retval;
    }
    v8 = (signed int)*addr % 4;
    if ( v8 )
    {
      v9 = 4 - v8;
      if ( 4 != v8 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v9;
          *addr = (char *)*addr + 1;
        }
        while ( v9 );
      }
    }
  }
  return result;
}

//----- (005218B0) --------------------------------------------------------  // acclient.c:336451
int __thiscall PhysicsScript::UnPack(PhysicsScript *this, void **addr, unsigned int size)
{
  PhysicsScript *v3; // edi@1
  char *v4; // ebx@1
  int v5; // edi@1
  int v6; // ST0C_4@1
  void *v7; // eax@2
  void *v8; // ebx@2
  void *v9; // ecx@4
  int v10; // eax@4
  int v11; // eax@9
  int v12; // ecx@10
  size_t v13; // eax@12
  int v14; // ecx@13
  int num_script_data; // [sp+10h] [bp-8h]@1
  char *v17; // [sp+14h] [bp-4h]@1

  v3 = this;
  v4 = (char *)&this[-1].m_pMaintainer;
  v17 = (char *)&this[-1].m_pMaintainer;
  ((void (__thiscall *)(DBOCache **))this[-1].m_pMaintainer->m_ObjTable.m_intrusiveTable.m_aInplaceBuckets[12])(&this[-1].m_pMaintainer);
  num_script_data = *(_DWORD *)*addr;
  v5 = (int)&v3->m_bLoaded;
  v6 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  OldSmartArray<PhysicsScriptData *>::Grow((OldSmartArray<PhysicsScriptData *> *)v5, v6);
  if ( num_script_data > 0 )
  {
    do
    {
      v7 = operator new(0x10u);
      v8 = 0;
      if ( v7 )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        v8 = v7;
      }
      v9 = *addr;
      *(_DWORD *)v8 = *(_DWORD *)*addr;
      *((_DWORD *)v8 + 1) = *((_DWORD *)v9 + 1);
      *addr = (char *)*addr + 8;
      *((_DWORD *)v8 + 2) = CAnimHook::UnPackHook(addr, size);
      v10 = *(_DWORD *)(v5 + 12);
      if ( v10 < *(_DWORD *)(v5 + 8)
        || OldSmartArray<PhysicsScriptData *>::Grow((OldSmartArray<PhysicsScriptData *> *)v5, v10 + *(_DWORD *)(v5 + 4)) )
        *(_DWORD *)(*(_DWORD *)v5 + 4 * (*(_DWORD *)(v5 + 12))++) = v8;
      --num_script_data;
    }
    while ( num_script_data );
    v4 = v17;
  }
  v11 = (signed int)*addr % 4;
  if ( v11 )
  {
    v12 = 4 - v11;
    if ( 4 != v11 )
    {
      do
      {
        *(_BYTE *)*addr = 0;
        --v12;
        *addr = (char *)*addr + 1;
      }
      while ( v12 );
    }
  }
  v13 = *((_DWORD *)v4 + 17);
  if ( (signed int)v13 > 0 )
  {
    _qsort(*((void **)v4 + 14), v13, 4u, PhysicsScriptData::Sort);
    v14 = *(_DWORD *)(*((_DWORD *)v4 + 14) + 4 * *((_DWORD *)v4 + 17) - 4);
    *((_DWORD *)v4 + 18) = *(_DWORD *)v14;
    *((_DWORD *)v4 + 19) = *(_DWORD *)(v14 + 4);
  }
  return 1;
}

//----- (005219D0) --------------------------------------------------------  // acclient.c:336531
PhysicsScript *__thiscall PhysicsScript::scalar_deleting_destructor(PhysicsScript *this, unsigned int a2)
{
  PhysicsScript *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&PhysicsScript::vftable;
  this->vfptr = (PackObjVtbl *)&PhysicsScript::vftable;
  PhysicsScript::Destroy(this);
  operator delete[](v2->script_data.data);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7BEC: using guessed type void *PhysicsScript::vftable;
// 7C7C00: using guessed type __int32 (__stdcall *PhysicsScript::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006FD630) --------------------------------------------------------  // acclient.c:785650
int sub_6FD630()
{
  return atexit(nullsub_1129);
}

