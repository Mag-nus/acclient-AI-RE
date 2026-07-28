/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : cWObjHierNode
   Object     : PORTAL\chierarchy\cWObjHierNode.obj
   Functions  : 14
   Addresses  : 004FC610 - 006F9460 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FC610) --------------------------------------------------------  // acclient.c:296285
int __cdecl PackObj::ALIGN_PTR(void **ptr)
{
  int v1; // edx@1
  int result; // eax@2
  int v3; // edx@3

  v1 = (signed int)*ptr % 4;
  if ( v1 )
  {
    result = 4 - v1;
    if ( 4 != v1 )
    {
      v3 = 4 - v1;
      do
      {
        *(_BYTE *)*ptr = 0;
        --v3;
        *ptr = (char *)*ptr + 1;
      }
      while ( v3 );
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FC650) --------------------------------------------------------  // acclient.c:296315
int __thiscall AC1Legacy::PStringBase<char>::GetPackSize(AC1Legacy::PStringBase<char> *this)
{
  unsigned int v1; // eax@1
  signed int v2; // ecx@1
  int v3; // edx@3
  int v4; // ecx@3
  int result; // eax@4

  v1 = this->m_buffer->m_len - 1;
  v2 = 0;
  if ( v1 >= 0xFFFF )
    v2 = 4;
  v3 = v2 + v1 + 2;
  v4 = ((_BYTE)v2 + (_BYTE)v1 + 2) & 3;
  if ( v4 )
    result = v3 + 4 - v4;
  else
    result = v3;
  return result;
}

//----- (004FC680) --------------------------------------------------------  // acclient.c:296337
void __thiscall cWObjHierNode::~cWObjHierNode(cWObjHierNode *this)
{
  cWObjHierNode *v1; // edi@1
  unsigned int i; // esi@1
  unsigned int v3; // eax@2
  void *v4; // ecx@2
  cWObjHierNode *v5; // ebx@2
  int v6; // eax@3
  AC1Legacy::PSRefBuffer<char> *v7; // esi@8

  v1 = this;
  for ( i = this->m_num - 1; (i & 0x80000000) == 0; --i )
  {
    v3 = v1->m_num;
    v4 = v1->m_data;
    v5 = v1->m_data[i];
    if ( i < v3 )
    {
      v6 = v3 - 1;
      v1->m_num = v6;
      if ( i != v6 )
        *((_DWORD *)v4 + i) = *((_DWORD *)v4 + v6);
    }
    if ( v5 )
    {
      cWObjHierNode::~cWObjHierNode(v5);
      operator delete(v5);
    }
  }
  v7 = v1->_menu_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
    v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
  operator delete[](v1->m_data);
}

//----- (004FC6F0) --------------------------------------------------------  // acclient.c:296373
int __thiscall AC1Legacy::PStringBase<char>::Pack(AC1Legacy::PStringBase<char> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  signed int v4; // eax@1
  int v5; // esi@3
  int v6; // eax@3
  int v7; // edx@4
  int result; // eax@6
  signed __int16 v9; // ax@7
  char *v10; // edi@9
  AC1Legacy::PSRefBuffer<char> *v11; // esi@11
  unsigned int psize; // [sp+8h] [bp-4h]@6
  unsigned int sizea; // [sp+14h] [bp+8h]@11

  v3 = this->m_buffer->m_len - 1;
  v4 = 0;
  if ( v3 >= 0xFFFF )
    v4 = 4;
  v5 = v4 + v3 + 2;
  v6 = ((_BYTE)v4 + (_BYTE)v3 + 2) & 3;
  if ( v6 )
    v7 = 4 - v6;
  else
    v7 = 0;
  result = v7 + v5;
  psize = v7 + v5;
  if ( size >= v7 + v5 )
  {
    v9 = LOWORD(this->m_buffer->m_len) - 1;
    if ( v3 >= 0xFFFF )
      v9 = -1;
    *(_WORD *)*addr = v9;
    v10 = (char *)*addr + 2;
    *addr = v10;
    if ( v9 == -1 )
    {
      *(_DWORD *)v10 = v3;
      *addr = (char *)*addr + 4;
    }
    v11 = this->m_buffer;
    sizea = (unsigned int)this->m_buffer;
    InterlockedIncrement((volatile LONG *)&this->m_buffer->m_cRef);
    qmemcpy(*addr, v11->m_data, v3);
    *addr = (char *)*addr + v3;
    PackObj::ALIGN_PTR(addr);
    if ( !InterlockedDecrement((volatile LONG *)(sizea + 4)) )
    {
      if ( sizea )
        (**(void (__stdcall ***)(_DWORD))sizea)(1);
    }
    result = psize;
  }
  return result;
}

//----- (004FC7C0) --------------------------------------------------------  // acclient.c:296429
void __thiscall cWObjHierRootNode::cWObjHierRootNode(cWObjHierRootNode *this, IDClass<_tagDataID,32,0> gid)
{
  cWObjHierRootNode *v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = this;
  this->m_data = 0;
  this->m_size = 0;
  this->m_num = 0;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_menu_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v2->_wcid.id = stru_841450.id;
  DBObj::DBObj((DBObj *)&v2->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&cWObjHierRootNode::vftable;
  v2->vfptr = (PackObjVtbl *)&cWObjHierRootNode::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5DB4: using guessed type void *cWObjHierRootNode::vftable;
// 7C5DC8: using guessed type __int32 (__stdcall *cWObjHierRootNode::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FC820) --------------------------------------------------------  // acclient.c:296453
cWObjHierRootNode *__thiscall cWObjHierRootNode::vector_deleting_destructor(cWObjHierRootNode *this, unsigned int a2)
{
  return cWObjHierRootNode::vector_deleting_destructor((cWObjHierRootNode *)((char *)this - 48), a2);
}

//----- (004FC830) --------------------------------------------------------  // acclient.c:296459
int __thiscall cWObjHierNode::Pack(cWObjHierNode *this, void **addr, unsigned int size)
{
  cWObjHierNode *v3; // edi@1
  int result; // eax@1
  char *v5; // edx@2
  unsigned int v6; // ebx@2
  int v7; // ecx@4
  int v8; // eax@5
  unsigned int psize; // [sp+8h] [bp-4h]@1

  v3 = this;
  result = cWObjHierNode::pack_size(this);
  psize = result;
  if ( size >= result )
  {
    AC1Legacy::PStringBase<char>::Pack(&v3->_menu_name, addr, size);
    *(_DWORD *)*addr = v3->_wcid.id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->m_num;
    *addr = (char *)*addr + 4;
    v6 = 0;
    if ( v3->m_num )
    {
      do
        cWObjHierNode::Pack(v3->m_data[v6++], addr, size);
      while ( v6 < v3->m_num );
    }
    v7 = (signed int)*addr % 4;
    if ( v7 )
    {
      v8 = 4 - v7;
      if ( 4 != v7 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v8;
          *addr = (char *)*addr + 1;
        }
        while ( v8 );
      }
    }
    result = psize;
  }
  return result;
}

//----- (004FC8C0) --------------------------------------------------------  // acclient.c:296508
int __thiscall AC1Legacy::PStringBase<char>::UnPack(AC1Legacy::PStringBase<char> *this, void **addr, unsigned int size)
{
  ReferenceCountTemplate<268435456,0> **v3; // edi@1
  unsigned __int16 v4; // dx@2
  char *v5; // eax@2
  unsigned int v6; // ecx@2
  unsigned int v7; // ebp@2
  unsigned int v9; // ecx@12
  int v10; // ecx@15
  AC1Legacy::PStringBase<char> *v11; // [sp+0h] [bp-4h]@1

  v3 = (ReferenceCountTemplate<268435456,0> **)this;
  v11 = this;
  if ( size < 2 )
    return 0;
  v4 = *(_WORD *)*addr;
  v5 = (char *)*addr + 2;
  v6 = size - 2;
  *addr = v5;
  v7 = v4;
  if ( v4 == -1 )
  {
    if ( v6 < 4 )
      return 0;
    v7 = *(_DWORD *)v5;
    *addr = v5 + 4;
    v6 = size - 6;
  }
  if ( v6 < v7 )
    return 0;
  if ( v7 )
  {
    if ( v7 != 1 || *(_BYTE *)*addr )
    {
      ReferenceCountTemplate<268435456,0>::Release(*v3);
      AC1Legacy::PStringBase<char>::allocate_ref_buffer((AC1Legacy::PStringBase<char> *)v3, v7);
      qmemcpy(&(*v3)[2].m_cRef, *addr, v7);
      *addr = (char *)*addr + v7;
      *((_BYTE *)&v11->m_buffer->m_hash + v11->m_buffer->m_len + 3) = 0;
      v9 = v11->m_buffer->m_len;
      if ( !*((_BYTE *)&v11->m_buffer->m_hash + v9 + 2) )
        v11->m_buffer->m_len = v9 - 1;
    }
    else
    {
      AC1Legacy::PStringBase<unsigned short>::operator=(
        (AC1Legacy::PStringBase<unsigned short> *)v3,
        (AC1Legacy::PStringBase<unsigned short> *)&AC1Legacy::PStringBase<char>::null_string);
      *addr = (char *)*addr + 1;
    }
  }
  else
  {
    AC1Legacy::PStringBase<char>::clear((AC1Legacy::PStringBase<char> *)v3);
  }
  v10 = (signed int)*addr % 4;
  if ( v10 )
    *addr = (char *)*addr + -v10 + 4;
  return 1;
}

//----- (004FC9C0) --------------------------------------------------------  // acclient.c:296570
cWObjHierRootNode *__thiscall cWObjHierRootNode::vector_deleting_destructor(cWObjHierRootNode *this, unsigned int a2)
{
  cWObjHierRootNode *v2; // esi@1
  cWObjHierNode *v3; // ecx@2

  v2 = this;
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj((SerializeUsingPackDBObj *)&this->vfptr);
  if ( v2 )
    v3 = (cWObjHierNode *)&v2->m_data;
  else
    v3 = 0;
  cWObjHierNode::~cWObjHierNode(v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004FC9F0) --------------------------------------------------------  // acclient.c:296588
int __thiscall cWObjHierNode::pack_size(cWObjHierNode *this)
{
  cWObjHierNode *v1; // edi@1
  int v2; // ebx@1
  unsigned int v3; // esi@1
  int result; // eax@4
  void *pvNull; // [sp+0h] [bp-4h]@1

  v1 = this;
  pvNull = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(&this->_menu_name, &pvNull, 0) + 8;
  v3 = 0;
  if ( v1->m_num )
  {
    do
      v2 += cWObjHierNode::Pack(v1->m_data[v3++], &pvNull, 0);
    while ( v3 < v1->m_num );
  }
  if ( v2 & 3 )
    result = v2 + 4 - (v2 & 3);
  else
    result = v2;
  return result;
}

//----- (004FCA60) --------------------------------------------------------  // acclient.c:296614
int __thiscall cWObjHierNode::UnPack(cWObjHierNode *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  void *v4; // esi@1
  cWObjHierNode *v5; // ebp@1
  unsigned int v6; // ecx@2
  void **v7; // ecx@2
  void *v8; // esi@4
  volatile LONG *v9; // ST04_4@5
  unsigned int v10; // eax@7
  unsigned int v11; // eax@9
  int v13; // eax@18
  int v14; // ecx@19
  void *start; // [sp+10h] [bp-4h]@1
  void **addra; // [sp+18h] [bp+4h]@3

  v3 = addr;
  v4 = *addr;
  v5 = this;
  start = *addr;
  if ( size < cWObjHierNode::pack_size(this) )
    return 0;
  AC1Legacy::PStringBase<char>::UnPack(&v5->_menu_name, addr, size);
  v6 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v5->_wcid.id = v6;
  v7 = *(void ***)*addr;
  *addr = (char *)*addr + 4;
  if ( (signed int)v7 > 0 )
  {
    addra = v7;
    do
    {
      v8 = operator new(0x14u);
      if ( v8 )
      {
        *(_DWORD *)v8 = 0;
        *((_DWORD *)v8 + 1) = 0;
        *((_DWORD *)v8 + 2) = 0;
        v9 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
        *((_DWORD *)v8 + 3) = AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement(v9);
        *((_DWORD *)v8 + 4) = stru_841450.id;
      }
      else
      {
        v8 = 0;
      }
      cWObjHierNode::UnPack((cWObjHierNode *)v8, v3, size);
      v10 = v5->m_size;
      if ( v5->m_num < v10
        || (!v10 ? (v11 = 8) : (v11 = 2 * v10),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v5, v11)) )
        v5->m_data[v5->m_num++] = (cWObjHierNode *)v8;
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
    v4 = start;
  }
  if ( size < (_BYTE *)*v3 - (_BYTE *)v4 )
  {
    *v3 = v4;
    return 0;
  }
  v13 = (signed int)*v3 % 4;
  if ( v13 )
  {
    v14 = 4 - v13;
    if ( 4 != v13 )
    {
      do
      {
        *(_BYTE *)*v3 = 0;
        --v14;
        *v3 = (char *)*v3 + 1;
      }
      while ( v14 );
    }
  }
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FCB80) --------------------------------------------------------  // acclient.c:296698
int __thiscall cWObjHierRootNode::Pack(cWObjHierRootNode *this, void **addr, unsigned int size)
{
  cWObjHierNode *v3; // edi@1
  int v4; // esi@1

  v3 = (cWObjHierNode *)&this->m_bLoaded;
  v4 = cWObjHierNode::pack_size((cWObjHierNode *)&this->m_bLoaded);
  if ( size >= v4 )
    cWObjHierNode::Pack(v3, addr, v4);
  return v4;
}

//----- (004FCBB0) --------------------------------------------------------  // acclient.c:296711
int __thiscall cWObjHierRootNode::UnPack(cWObjHierRootNode *this, void **addr, unsigned int size)
{
  void *v3; // ebp@1
  cWObjHierNode *v4; // edi@1

  v3 = *addr;
  v4 = (cWObjHierNode *)&this->m_bLoaded;
  if ( size < cWObjHierNode::pack_size((cWObjHierNode *)&this->m_bLoaded) )
    return 0;
  cWObjHierNode::UnPack(v4, addr, size);
  if ( size < (_BYTE *)*addr - (_BYTE *)v3 )
  {
    *addr = v3;
    return 0;
  }
  return 1;
}

//----- (006F9460) --------------------------------------------------------  // acclient.c:782003
int sub_6F9460()
{
  return atexit(nullsub_1035);
}

