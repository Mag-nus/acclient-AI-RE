/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HouseAccessRestrictions
   Object     : PORTAL\engine_house\HouseAccessRestrictions.obj
   Functions  : 24
   Addresses  : 005A7C90 - 005AFE30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A7C90) --------------------------------------------------------  // acclient.c:465090
signed int __thiscall PackableHashTable<unsigned long,GuestInfo>::pack_size(PackableHashTable<unsigned long,GuestInfo> *this)
{
  PackableHashTable<unsigned long,GuestInfo> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,GuestInfo> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (005AF010) --------------------------------------------------------  // acclient.c:473606
PackableHashIterator<unsigned long,GuestInfo> *__thiscall PackableHashIterator<unsigned long,GuestInfo>::vector_deleting_destructor(PackableHashIterator<unsigned long,GuestInfo> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,GuestInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,GuestInfo>Vtbl *)PackableHashIterator<unsigned long,GuestInfo>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E61C4: using guessed type int (__thiscall *PackableHashIterator<unsigned long,GuestInfo>::vftable[2])(void *, char);

//----- (005AF030) --------------------------------------------------------  // acclient.c:473619
unsigned int __thiscall HAR::Pack(HAR *this, void **addr, unsigned int size)
{
  HAR *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebp@1
  char *v6; // ebx@1
  int v7; // esi@1
  int v8; // eax@1
  int v9; // ecx@1
  int v10; // eax@1
  int v11; // edx@2
  unsigned int result; // eax@4
  char *v13; // eax@5
  char *v14; // edx@5
  int v15; // edx@6
  int v16; // ecx@7
  unsigned int retval; // [sp+20h] [bp-4h]@1

  v3 = this;
  v4 = this->_guest_table.vfptr;
  v5 = (char *)&this->_guest_table;
  retval = 0;
  v6 = (char *)&this->_roommate_list.vfptr;
  v7 = ((int (__thiscall *)(PackableHashTable<unsigned long,GuestInfo> *, unsigned int *, _DWORD))v4->Pack)(
         &this->_guest_table,
         &retval,
         0);
  v8 = (*(int (__thiscall **)(int, unsigned int *, _DWORD))(*(_DWORD *)v6 + 12))(&v3->_roommate_list.vfptr, &retval, 0);
  v9 = v7 + v8 + 12;
  v10 = ((_BYTE)v7 + (_BYTE)v8 + 12) & 3;
  if ( v10 )
    v11 = 4 - v10;
  else
    v11 = 0;
  result = v11 + v9;
  retval = v11 + v9;
  if ( size >= v11 + v9 )
  {
    *(_DWORD *)*addr = 268435458;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->_bitmask;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(_DWORD *)v14 = v3->_monarch_iid;
    *addr = (char *)*addr + 4;
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v6 + 12))(&v3->_roommate_list.vfptr, addr, size);
    result = retval;
  }
  v15 = (signed int)*addr % 4;
  if ( v15 )
  {
    v16 = 4 - v15;
    if ( 4 != v15 )
    {
      do
      {
        *(_BYTE *)*addr = 0;
        --v16;
        *addr = (char *)*addr + 1;
      }
      while ( v16 );
    }
  }
  return result;
}

//----- (005AF110) --------------------------------------------------------  // acclient.c:473688
PackableHashIterator<unsigned long,GuestInfo> *__thiscall PackableHashTable<unsigned long,GuestInfo>::begin(PackableHashTable<unsigned long,GuestInfo> *this, PackableHashIterator<unsigned long,GuestInfo> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,GuestInfo> **v4; // edi@2
  PackableHashData<unsigned long,GuestInfo> **v5; // esi@2
  PackableHashData<unsigned long,GuestInfo> **v6; // ecx@5
  PackableHashIterator<unsigned long,GuestInfo> *v7; // eax@5
  PackableHashData<unsigned long,GuestInfo> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,GuestInfo>Vtbl *)PackableHashIterator<unsigned long,GuestInfo>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,GuestInfo>Vtbl *)PackableHashIterator<unsigned long,GuestInfo>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E61C4: using guessed type int (__thiscall *PackableHashIterator<unsigned long,GuestInfo>::vftable[2])(void *, char);

//----- (005AF170) --------------------------------------------------------  // acclient.c:473733
void __thiscall GuestInfo::~GuestInfo(GuestInfo *this)
{
  GuestInfo *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1

  v1 = this;
  v2 = this->_char_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005AF1A0) --------------------------------------------------------  // acclient.c:473747
signed int __thiscall PackableHashTable<unsigned long,GuestInfo>::Pack(PackableHashTable<unsigned long,GuestInfo> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,GuestInfo> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,GuestInfo> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,GuestInfo>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (005AF230) --------------------------------------------------------  // acclient.c:473798
GuestInfo *__thiscall GuestInfo::scalar_deleting_destructor(GuestInfo *this, unsigned int a2)
{
  GuestInfo *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1

  v2 = this;
  v3 = this->_char_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005AF270) --------------------------------------------------------  // acclient.c:473815
int __thiscall GuestInfo::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // edi@2
  int v4; // ebx@6

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    v3 = *(_DWORD *)(this + 8);
    if ( v3 != *(_DWORD *)(a2 + 8) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v2 + 8) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
  }
  return v2;
}

//----- (005AF2C0) --------------------------------------------------------  // acclient.c:473839
void __thiscall GuestInfo::Clear(GuestInfo *this)
{
  GuestInfo *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  volatile LONG *v3; // ST00_4@5

  v1 = this;
  this->_item_storage_permission = 0;
  v2 = this->_char_name.m_buffer;
  if ( v2 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) )
    {
      if ( v2 )
        v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    }
    v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->_char_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v3);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AF310) --------------------------------------------------------  // acclient.c:473863
int __thiscall GuestInfo::GetPackSize(GuestInfo *this)
{
  void *addr; // [sp+0h] [bp-4h]@1

  addr = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->_char_name, &addr, 0) + 4;
}

//----- (005AF330) --------------------------------------------------------  // acclient.c:473872
unsigned int __thiscall GuestInfo::Pack(GuestInfo *this, void **addr, unsigned int size)
{
  GuestInfo *v3; // esi@1
  unsigned int v4; // edi@1

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_item_storage_permission;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_char_name, addr, size);
  }
  return v4;
}

//----- (005AF370) --------------------------------------------------------  // acclient.c:473889
void __thiscall GuestInfo::GuestInfo(GuestInfo *this)
{
  GuestInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  volatile LONG *v4; // ST00_4@5

  v1 = this;
  this->vfptr = (PackObjVtbl *)&GuestInfo::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_char_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->_item_storage_permission = 0;
  v3 = v1->_char_name.m_buffer;
  if ( v3 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->_char_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
}
// 7E61DC: using guessed type int (__thiscall *GuestInfo::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AF3E0) --------------------------------------------------------  // acclient.c:473919
int __thiscall GuestInfo::UnPack(GuestInfo *this, void **addr, unsigned int size)
{
  GuestInfo *v3; // edi@1
  int result; // eax@2
  void *v5; // edx@3
  char *v6; // ecx@3
  int v7; // ecx@3
  unsigned int v8; // esi@4

  v3 = this;
  if ( size >= 4 )
  {
    GuestInfo::Clear(this);
    v5 = *addr;
    v3->_item_storage_permission = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v7 = v6 - (_BYTE *)v5;
    if ( size <= v7 )
      v8 = 0;
    else
      v8 = size - v7;
    result = AC1Legacy::PStringBase<char>::UnPack(&v3->_char_name, addr, v8) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005AF430) --------------------------------------------------------  // acclient.c:473951
void __thiscall PackableHashTable<unsigned long,GuestInfo>::EmptyContents(PackableHashTable<unsigned long,GuestInfo> *this)
{
  PackableHashTable<unsigned long,GuestInfo> *v1; // ebp@1
  unsigned int v2; // eax@2
  PackableHashData<unsigned long,GuestInfo> *v3; // esi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@4
  PackableHashData<unsigned long,GuestInfo> *v5; // ebx@4
  unsigned int i; // [sp+4h] [bp-4h]@2

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_data._char_name.m_buffer;
            v5 = v3->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
              v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v5;
          }
          while ( v5 );
          v2 = i;
        }
        v1->_buckets[v2++] = 0;
        i = v2;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005AF4C0) --------------------------------------------------------  // acclient.c:473996
void __thiscall PackableHashData<unsigned long,GuestInfo>::PackableHashData<unsigned long,GuestInfo>(PackableHashData<unsigned long,GuestInfo> *this, const unsigned int *key, GuestInfo *data, int highbound)
{
  PackableHashData<unsigned long,GuestInfo> *v4; // esi@1
  int v5; // edi@1
  volatile LONG *v6; // ST00_4@1

  v4 = this;
  this->_key = *key;
  v5 = (int)&this->_data;
  *(_DWORD *)v5 = &GuestInfo::vftable;
  v6 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  *(_DWORD *)(v5 + 8) = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v6);
  GuestInfo::operator=(v5, (int)data);
  v4->_next = 0;
  v4->_hashVal = *key % highbound;
}
// 7E61DC: using guessed type int (__thiscall *GuestInfo::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AF520) --------------------------------------------------------  // acclient.c:474017
int __thiscall GuestInfo::Dump(GuestInfo *this, AC1Legacy::PStringBase<char> *spew)
{
  GuestInfo *v2; // edi@1
  AC1Legacy::PStringBase<char> *v3; // ST08_4@1
  AC1Legacy::PStringBase<char> *v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // eax@1
  unsigned int v6; // ecx@1
  AC1Legacy::PStringBase<char> *v7; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v8; // esi@4
  AC1Legacy::PSRefBuffer<char> *v9; // esi@7
  AC1Legacy::PStringBase<char> *v10; // esi@11
  AC1Legacy::PSRefBuffer<char> *v11; // eax@11
  AC1Legacy::PStringBase<char> *v12; // esi@16
  AC1Legacy::PSRefBuffer<char> *v13; // eax@16
  AC1Legacy::PStringBase<char> result; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> v16; // [sp+14h] [bp-4h]@1

  v2 = this;
  v3 = &this->_char_name;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v16, "  ");
  v5 = AC1Legacy::PStringBase<char>::operator+(v4, &result, v3)->m_buffer;
  v6 = v5->m_len;
  v7 = spew;
  if ( v6 != 1 && v5 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(spew, v5->m_data, v6 - 1);
  v8 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v8 )
    v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
  v9 = v16.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v16.m_buffer->m_cRef) && v9 )
    v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  if ( v2->_item_storage_permission )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&spew, " *");
    v10 = spew;
    v11 = spew[2].m_buffer;
    if ( v11 != (AC1Legacy::PSRefBuffer<char> *)1
      && spew != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v7, (const char *)&spew[5], (unsigned int)&v11[-1].m_data[3]);
    if ( !InterlockedDecrement((volatile LONG *)&v10[1]) )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v10->m_buffer->vfptr)(v10, 1);
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&spew, "\n");
  v12 = spew;
  v13 = spew[2].m_buffer;
  if ( v13 != (AC1Legacy::PSRefBuffer<char> *)1
    && spew != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v7, (const char *)&spew[5], (unsigned int)&v13[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v12[1]) )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v12->m_buffer->vfptr)(v12, 1);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AF640) --------------------------------------------------------  // acclient.c:474072
int __thiscall HAR::Dump(HAR *this, AC1Legacy::PStringBase<char> *spew, bool bIncludeRoommates)
{
  HAR *v3; // edi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  unsigned int v5; // eax@1
  AC1Legacy::PStringBase<char> *v6; // ebp@1
  LONG (__stdcall *v7)(volatile LONG *); // ebx@4
  unsigned int v8; // ebx@7
  PackableHashData<unsigned long,GuestInfo> **v9; // edi@7
  PackableHashData<unsigned long,GuestInfo> *v10; // esi@7
  int v11; // eax@11
  AC1Legacy::PStringBase<char> *v12; // esi@16
  AC1Legacy::PSRefBuffer<char> *v13; // eax@16
  int v14; // esi@23
  int v15; // eax@23
  AC1Legacy::ListNode<unsigned long> *v16; // edi@28
  int v17; // esi@30
  int v18; // eax@30
  int v19; // esi@36
  int v20; // eax@36
  int v21; // esi@44
  int v22; // eax@44
  int v23; // esi@50
  int v24; // eax@50
  int v25; // esi@56
  int v26; // eax@56
  int v27; // esi@61
  int v28; // eax@61
  int v29; // esi@67
  int v30; // eax@67
  HAR *v32; // [sp+10h] [bp-18h]@1
  AC1Legacy::PStringBase<char> v33; // [sp+14h] [bp-14h]@1
  PackableHashIterator<unsigned long,GuestInfo> iter; // [sp+18h] [bp-10h]@7

  v3 = this;
  v32 = this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v33, "Guests:\n");
  v4 = v33.m_buffer;
  v5 = v33.m_buffer->m_len;
  v6 = spew;
  if ( v5 != 1 && v33.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(spew, v33.m_buffer->m_data, v5 - 1);
  v7 = InterlockedDecrement;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  if ( v3->_guest_table._currNum )
  {
    PackableHashTable<unsigned long,GuestInfo>::begin(&v3->_guest_table, &iter);
    v8 = iter._table_size;
    v9 = iter._buckets;
    v10 = iter._current;
    while ( v10 )
    {
      GuestInfo::Dump(&v10->_data, v6);
      if ( v10->_next )
      {
        v10 = v10->_next;
      }
      else
      {
        v11 = v10->_hashVal + 1;
        if ( v11 >= v8 )
        {
LABEL_14:
          v10 = 0;
        }
        else
        {
          while ( !v9[v11] )
          {
            ++v11;
            if ( v11 >= v8 )
              goto LABEL_14;
          }
          v10 = v9[v11];
        }
      }
    }
    v7 = InterlockedDecrement;
    v3 = v32;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&spew, "  None\n");
    v12 = spew;
    v13 = spew[2].m_buffer;
    if ( v13 != (AC1Legacy::PSRefBuffer<char> *)1
      && spew != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)&spew[5], (unsigned int)&v13[-1].m_data[3]);
    if ( !InterlockedDecrement((volatile LONG *)&v12[1]) )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v12->m_buffer->vfptr)(v12, 1);
  }
  if ( bIncludeRoommates )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&bIncludeRoommates, "Roommates:\n");
    v14 = bIncludeRoommates;
    v15 = *(_DWORD *)(bIncludeRoommates + 8);
    if ( v15 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v15 - 1);
    if ( !v7((volatile LONG *)(v14 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    v16 = v3->_roommate_list._head;
    if ( v16 )
    {
      while ( v16 )
      {
        *(_DWORD *)&bIncludeRoommates = AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        AC1Legacy::PStringBase<char>::sprintf(
          (AC1Legacy::PStringBase<char> *)&bIncludeRoommates,
          "  0x%08X\n",
          v16->data);
        v17 = bIncludeRoommates;
        v18 = *(_DWORD *)(bIncludeRoommates + 8);
        if ( v18 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
          AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v18 - 1);
        if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        v16 = v16->next;
      }
      v7 = InterlockedDecrement;
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&bIncludeRoommates, "  None\n");
      v19 = bIncludeRoommates;
      v20 = *(_DWORD *)(bIncludeRoommates + 8);
      if ( v20 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v20 - 1);
      if ( !v7((volatile LONG *)(v19 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    }
    v3 = v32;
  }
  if ( v3->_bitmask & 6 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&bIncludeRoommates,
      "Allegiance Permissions: ");
    v21 = bIncludeRoommates;
    v22 = *(_DWORD *)(bIncludeRoommates + 8);
    if ( v22 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v22 - 1);
    if ( !v7((volatile LONG *)(v21 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
    if ( v3->_bitmask & 2 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        (AC1Legacy::PStringBase<char> *)&bIncludeRoommates,
        "guest access");
      v23 = bIncludeRoommates;
      v24 = *(_DWORD *)(bIncludeRoommates + 8);
      if ( v24 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v24 - 1);
      if ( !v7((volatile LONG *)(v23 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
    }
    if ( v3->_bitmask & 4 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        (AC1Legacy::PStringBase<char> *)&bIncludeRoommates,
        "storage access");
      v25 = bIncludeRoommates;
      v26 = *(_DWORD *)(bIncludeRoommates + 8);
      if ( v26 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v26 - 1);
      if ( !v7((volatile LONG *)(v25 + 4)) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&bIncludeRoommates, "\n");
    v27 = bIncludeRoommates;
    v28 = *(_DWORD *)(bIncludeRoommates + 8);
    if ( v28 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v28 - 1);
    if ( !v7((volatile LONG *)(v27 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  }
  if ( v3->_bitmask & 1 )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&bIncludeRoommates,
      "[ open house ]\n");
    v29 = bIncludeRoommates;
    v30 = *(_DWORD *)(bIncludeRoommates + 8);
    if ( v30 != 1 && bIncludeRoommates != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)(bIncludeRoommates + 20), v30 - 1);
    if ( !v7((volatile LONG *)(v29 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
  }
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AF9C0) --------------------------------------------------------  // acclient.c:474266
int __thiscall HAR::UnPack(HAR *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  HAR *v4; // edi@1
  int result; // eax@2
  void **v6; // esi@3
  void *v7; // ebp@3
  unsigned int v8; // eax@3
  signed int v9; // eax@4
  unsigned int v10; // eax@11
  unsigned int v11; // eax@12
  int v12; // eax@14
  int v13; // ebx@15
  int v14; // ecx@18
  int v15; // eax@18
  int v16; // eax@18
  int v17; // ecx@19
  unsigned int v18; // eax@23
  unsigned int dummy; // [sp+0h] [bp-4h]@3
  void **addra; // [sp+8h] [bp+4h]@10
  unsigned int sizea; // [sp+Ch] [bp+8h]@4

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  v7 = *addr;
  v8 = *(_DWORD *)*addr;
  dummy = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( v8 & 0xFFFF0000 )
  {
    sizea = v8;
    if ( v8 )
      v9 = 12;
    else
      v9 = 4;
  }
  else
  {
    sizea = 0;
    v9 = 4;
  }
  if ( v3 < v9 )
    return 0;
  this->_bitmask = 0;
  this->_monarch_iid = 0;
  addra = (void **)&this->_guest_table.vfptr;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents(&this->_guest_table);
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v4->_roommate_list);
  if ( sizea )
  {
    v4->_bitmask = *(_DWORD *)*v6;
    v14 = (int)((char *)*v6 + 4);
    *v6 = (void *)v14;
    v4->_monarch_iid = *(_DWORD *)v14;
    v15 = (int)((char *)*v6 + 4);
    *v6 = (void *)v15;
    v16 = v15 - (_DWORD)v7;
    if ( v3 <= v16 )
      v17 = 0;
    else
      v17 = v3 - v16;
    if ( !(*((int (__thiscall **)(void **, void **, int))*addra + 4))(addra, v6, v17) )
      return 0;
    if ( sizea >= 0x10000002 )
    {
      v18 = PackObj::GET_SIZE_LEFT(*v6, v7, v3);
      if ( !((int (__thiscall *)(int, void **, unsigned int))v4->_roommate_list.vfptr->UnPack)(
              &v4->_roommate_list.vfptr,
              v6,
              v18) )
        return 0;
    }
    PackObj::ALIGN_PTR(v6);
    result = 1;
  }
  else
  {
    v10 = v4->_bitmask;
    if ( dummy )
      v11 = v10 | 1;
    else
      v11 = v10 & 0xFFFFFFFE;
    v4->_bitmask = v11;
    v12 = (_BYTE *)*v6 - (_BYTE *)v7;
    if ( v3 <= v12 )
      v13 = 0;
    else
      v13 = v3 - v12;
    result = (*((int (__stdcall **)(void **, int))*addra + 4))(v6, v13) != 0;
  }
  return result;
}

//----- (005AFB10) --------------------------------------------------------  // acclient.c:474363
int __thiscall PackableHashTable<unsigned long,GuestInfo>::add(PackableHashTable<unsigned long,GuestInfo> *this, const unsigned int *key, GuestInfo *data)
{
  PackableHashTable<unsigned long,GuestInfo> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,GuestInfo> **v5; // ebx@2
  PackableHashData<unsigned long,GuestInfo> *v6; // edx@3
  PackableHashData<unsigned long,GuestInfo> *v7; // eax@8
  int v8; // eax@9
  int v10; // ecx@11

  v3 = this;
  v4 = this->_table_size;
  if ( v4 )
  {
    v5 = this->_buckets;
    if ( v5 )
    {
      v6 = v5[*key % v4];
      if ( v6 )
      {
        while ( *key != v6->_key )
        {
          v6 = v6->_next;
          if ( !v6 )
            goto LABEL_8;
        }
        if ( v6 != (PackableHashData<unsigned long,GuestInfo> *)-4 )
          return 0;
      }
    }
  }
LABEL_8:
  v7 = (PackableHashData<unsigned long,GuestInfo> *)operator new(0x18u);
  if ( !v7 )
    return 0;
  PackableHashData<unsigned long,GuestInfo>::PackableHashData<unsigned long,GuestInfo>(v7, key, data, v3->_table_size);
  if ( !v8 )
    return 0;
  v10 = *(_DWORD *)(v8 + 20);
  *(_DWORD *)(v8 + 16) = v3->_buckets[v10];
  v3->_buckets[v10] = (PackableHashData<unsigned long,GuestInfo> *)v8;
  ++v3->_currNum;
  return 1;
}

//----- (005AFBA0) --------------------------------------------------------  // acclient.c:474409
int __thiscall PackableHashTable<unsigned long,GuestInfo>::UnPack(PackableHashTable<unsigned long,GuestInfo> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,GuestInfo> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  void **v10; // ebx@5
  unsigned int v11; // ebp@5
  GuestInfo *v12; // ecx@16
  unsigned int tempKey; // [sp+8h] [bp-18h]@11
  void *start_addr; // [sp+Ch] [bp-14h]@3
  unsigned int blob_size; // [sp+10h] [bp-10h]@3
  GuestInfo tempData; // [sp+14h] [bp-Ch]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = (void **)(v3 - 4);
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    GuestInfo::GuestInfo(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( 1 )
      {
        addr = v10;
        if ( !PackObj::UNPACK_TYPE((int *)&tempKey, v6, (unsigned int *)&addr)
          || !((int (__thiscall *)(GuestInfo *, void **, void **))tempData.vfptr->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,GuestInfo>::add(v4, &tempKey, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        GuestInfo::~GuestInfo(&tempData);
        return 1;
      }
    }
    GuestInfo::~GuestInfo(v12);
  }
  return 0;
}

//----- (005AFCF0) --------------------------------------------------------  // acclient.c:474486
PackableHashTable<unsigned long,GuestInfo> *__thiscall PackableHashTable<unsigned long,GuestInfo>::scalar_deleting_destructor(PackableHashTable<unsigned long,GuestInfo> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,GuestInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,GuestInfo>::vftable;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E61C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,GuestInfo>::vftable)(void *, char);

//----- (005AFD40) --------------------------------------------------------  // acclient.c:474508
void __thiscall HAR::HAR(HAR *this)
{
  HAR *v1; // ebx@1
  char *v2; // esi@1
  int v3; // edi@1

  v1 = this;
  v2 = (char *)&this->_guest_table;
  this->vfptr = (PackObjVtbl *)&HAR::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,GuestInfo>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 64;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&this->_guest_table);
  v3 = (int)&v1->_roommate_list;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 16) = &PackObj::vftable;
  *(_DWORD *)v3 = &PList<unsigned long>::vftable;
  *(_DWORD *)(v3 + 16) = &PList<unsigned long>::vftable;
  v1->_bitmask = 0;
  v1->_monarch_iid = 0;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents((PackableHashTable<unsigned long,GuestInfo> *)v2);
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->_roommate_list);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 7E61C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,GuestInfo>::vftable)(void *, char);
// 7E626C: using guessed type int (__thiscall *HAR::vftable)(void *, char);

//----- (005AFDB0) --------------------------------------------------------  // acclient.c:474542
void __thiscall HAR::~HAR(HAR *this)
{
  HAR *v1; // edi@1
  char *v2; // esi@1

  v1 = this;
  v2 = (char *)&this->_guest_table;
  this->vfptr = (PackObjVtbl *)&HAR::vftable;
  this->_bitmask = 0;
  this->_monarch_iid = 0;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents(&this->_guest_table);
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->_roommate_list);
  v1->_roommate_list.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
  v1->_roommate_list.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->_roommate_list.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&AC1Legacy::List<unsigned long>::vftable;
  List<SkillRecord *>::flush((List<SkillRecord *> *)&v1->_roommate_list);
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,GuestInfo>::vftable;
  PackableHashTable<unsigned long,GuestInfo>::EmptyContents((PackableHashTable<unsigned long,GuestInfo> *)v2);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4110: using guessed type int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7E61C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,GuestInfo>::vftable)(void *, char);
// 7E626C: using guessed type int (__thiscall *HAR::vftable)(void *, char);

//----- (005AFE30) --------------------------------------------------------  // acclient.c:474576
HAR *__thiscall HAR::vector_deleting_destructor(HAR *this, unsigned int a2)
{
  HAR *v2; // esi@1

  v2 = this;
  HAR::~HAR(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

