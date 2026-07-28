/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEmoteTable
   Object     : AC\accqualities\CEmoteTable.obj
   Functions  : 20
   Addresses  : 00594E20 - 0070AC50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00594E20) --------------------------------------------------------  // acclient.c:446383
int __thiscall CEmoteTable::UnPack(CEmoteTable *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(void **, unsigned int))this->_emote_table.vfptr->UnPack)(addr, size);
}

//----- (00594E30) --------------------------------------------------------  // acclient.c:446389
int __thiscall PackableList<EmoteSet>::InsertTail(PackableList<EmoteSet> *this, EmoteSet *val)
{
  PackableList<EmoteSet> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<EmoteSet> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x40u);
  if ( v3 )
  {
    EmoteSet::EmoteSet((EmoteSet *)v3, val);
    *((_DWORD *)v3 + 14) = 0;
    *((_DWORD *)v3 + 15) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<EmoteSet> *)v3;
    *((_DWORD *)v3 + 15) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<EmoteSet> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<EmoteSet> *)v3;
    v2->tail = (PackableLLNode<EmoteSet> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (00594EA0) --------------------------------------------------------  // acclient.c:446432
signed int __thiscall PackableList<EmoteSet>::Pack(PackableList<EmoteSet> *this, void **addr, unsigned int size)
{
  PackableList<EmoteSet> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<EmoteSet> *i; // esi@4

  v3 = this;
  v4 = PackableList<EmoteSet>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<EmoteSet> *, void **, unsigned int))i->data.vfptr->Pack)(i, addr, size);
  }
  return v4;
}

//----- (00594EF0) --------------------------------------------------------  // acclient.c:446454
signed int __thiscall PackableList<EmoteSet>::pack_size(PackableList<EmoteSet> *this)
{
  PackableLLNode<EmoteSet> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<EmoteSet> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (00594F30) --------------------------------------------------------  // acclient.c:446473
void __thiscall PackableList<EmoteSet>::Flush(PackableList<EmoteSet> *this)
{
  PackableList<EmoteSet> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  EmoteSet dummyData; // [sp+8h] [bp-38h]@1

  v1 = this;
  EmoteSet::EmoteSet(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 56);
      v1->head = (PackableLLNode<EmoteSet> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 60) = 0;
      else
        v1->tail = 0;
      EmoteSet::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        EmoteSet::~EmoteSet((EmoteSet *)v2);
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
  EmoteSet::~EmoteSet(&dummyData);
}

//----- (00594FA0) --------------------------------------------------------  // acclient.c:446506
PackableList<EmoteSet> *__thiscall PackableList<EmoteSet>::operator=(PackableList<EmoteSet> *this, int a2)
{
  PackableList<EmoteSet> *v2; // edi@1
  int i; // ebx@1
  EmoteSet *v4; // eax@2
  EmoteSet *v5; // esi@2
  unsigned int v6; // eax@7
  int v7; // ecx@8

  v2 = this;
  PackableList<EmoteSet>::Flush(this);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 56) )
  {
    v4 = (EmoteSet *)operator new(0x40u);
    v5 = v4;
    if ( v4 )
    {
      EmoteSet::EmoteSet(v4, (EmoteSet *)i);
      v5[1].vfptr = 0;
      v5[1].category = 0;
    }
    else
    {
      v5 = 0;
    }
    if ( v2->head )
    {
      v6 = (unsigned int)v2->tail;
      *(_DWORD *)(v6 + 56) = v5;
      v5[1].category = v6;
    }
    else
    {
      v2->head = (PackableLLNode<EmoteSet> *)v5;
    }
    v7 = v2->curNum + 1;
    v2->tail = (PackableLLNode<EmoteSet> *)v5;
    v2->curNum = v7;
    if ( !i )
      break;
  }
  return v2;
}

//----- (00595010) --------------------------------------------------------  // acclient.c:446551
void __thiscall PackableList<EmoteSet>::~PackableList<EmoteSet>(PackableList<EmoteSet> *this)
{
  PackableList<EmoteSet> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
  PackableList<EmoteSet>::Flush(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E46DC: using guessed type int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char);

//----- (00595030) --------------------------------------------------------  // acclient.c:446564
int __thiscall PackableList<EmoteSet>::UnPack(PackableList<EmoteSet> *this, void **addr, unsigned int size)
{
  PackableList<EmoteSet> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  EmoteSet temp; // [sp+8h] [bp-38h]@2

  v3 = this;
  PackableList<EmoteSet>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    EmoteSet::EmoteSet(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      EmoteSet::~EmoteSet(&temp);
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(EmoteSet *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<EmoteSet>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      EmoteSet::~EmoteSet(&temp);
      result = 0;
    }
  }
  return result;
}

//----- (005950C0) --------------------------------------------------------  // acclient.c:446607
PackableList<EmoteSet> *__thiscall PackableList<EmoteSet>::vector_deleting_destructor(PackableList<EmoteSet> *this, unsigned int a2)
{
  PackableList<EmoteSet> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
  PackableList<EmoteSet>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E46DC: using guessed type int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char);

//----- (005950F0) --------------------------------------------------------  // acclient.c:446623
void __thiscall PackableHashData<unsigned long,PackableList<EmoteSet>>::PackableHashData<unsigned long,PackableList<EmoteSet>>(PackableHashData<unsigned long,PackableList<EmoteSet> > *this, const unsigned int *key, PackableList<EmoteSet> *data, int highbound)
{
  PackableHashData<unsigned long,PackableList<EmoteSet> > *v4; // esi@1
  char *v5; // ecx@1

  v4 = this;
  v5 = (char *)&this->_data;
  v4->_key = *key;
  *(_DWORD *)v5 = &PackableList<EmoteSet>::vftable;
  *((_DWORD *)v5 + 1) = 0;
  *((_DWORD *)v5 + 2) = 0;
  *((_DWORD *)v5 + 3) = 0;
  PackableList<EmoteSet>::operator=((PackableList<EmoteSet> *)v5, (int)data);
  v4->_next = 0;
  v4->_hashVal = *key % highbound;
}
// 7E46DC: using guessed type int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char);

//----- (00595140) --------------------------------------------------------  // acclient.c:446642
int __thiscall PackableHashTable<unsigned long,PackableList<EmoteSet>>::add(PackableHashTable<unsigned long,PackableList<EmoteSet> > *this, const unsigned int *key, PackableList<EmoteSet> *data)
{
  PackableHashTable<unsigned long,PackableList<EmoteSet> > *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,PackableList<EmoteSet> > **v5; // ebx@2
  PackableHashData<unsigned long,PackableList<EmoteSet> > *v6; // edx@3
  PackableHashData<unsigned long,PackableList<EmoteSet> > *v7; // eax@8
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
        if ( v6 != (PackableHashData<unsigned long,PackableList<EmoteSet> > *)-4 )
          return 0;
      }
    }
  }
LABEL_8:
  v7 = (PackableHashData<unsigned long,PackableList<EmoteSet> > *)operator new(0x1Cu);
  if ( !v7 )
    return 0;
  PackableHashData<unsigned long,PackableList<EmoteSet>>::PackableHashData<unsigned long,PackableList<EmoteSet>>(
    v7,
    key,
    data,
    v3->_table_size);
  if ( !v8 )
    return 0;
  v10 = *(_DWORD *)(v8 + 24);
  *(_DWORD *)(v8 + 20) = v3->_buckets[v10];
  v3->_buckets[v10] = (PackableHashData<unsigned long,PackableList<EmoteSet> > *)v8;
  ++v3->_currNum;
  return 1;
}

//----- (005951D0) --------------------------------------------------------  // acclient.c:446692
void __thiscall PackableHashTable<unsigned long,PackableList<EmoteSet>>::EmptyContents(PackableHashTable<unsigned long,PackableList<EmoteSet> > *this)
{
  PackableHashTable<unsigned long,PackableList<EmoteSet> > *v1; // ebp@1
  unsigned int v2; // eax@2
  PackableHashData<unsigned long,PackableList<EmoteSet> > *v3; // esi@3
  PackableHashData<unsigned long,PackableList<EmoteSet> > *v4; // ebx@4
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
            v4 = v3->_next;
            v3->_data.vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
            PackableList<EmoteSet>::Flush(&v3->_data);
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
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
// 7E46DC: using guessed type int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char);

//----- (00595250) --------------------------------------------------------  // acclient.c:446736
int __thiscall PackableHashTable<unsigned long,PackableList<EmoteSet>>::UnPack(PackableHashTable<unsigned long,PackableList<EmoteSet> > *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,PackableList<EmoteSet> > *v4; // edi@1
  void **v6; // esi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  int v14; // edx@16
  PackableList<EmoteSet> *v15; // ecx@16
  void *start_addr; // [sp+8h] [bp-18h]@3
  unsigned int blob_size; // [sp+Ch] [bp-14h]@3
  PackableList<EmoteSet> tempData; // [sp+10h] [bp-10h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,PackableList<EmoteSet>>::EmptyContents(this);
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
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  tempData.vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
  tempData.head = 0;
  tempData.tail = 0;
  tempData.curNum = 0;
  size = 0;
  if ( !v11 )
  {
LABEL_16:
    v14 = (_BYTE *)*v6 - (_BYTE *)start_addr;
    v15 = &tempData;
    tempData.vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
    if ( blob_size >= v14 )
    {
      PackableList<EmoteSet>::Flush(&tempData);
      return 1;
    }
LABEL_19:
    PackableList<EmoteSet>::Flush(v15);
    return 0;
  }
  while ( 1 )
  {
    if ( (unsigned int)v10 < 4 )
    {
      tempData.vfptr = (PackObjVtbl *)&PackableList<EmoteSet>::vftable;
      v15 = &tempData;
      goto LABEL_19;
    }
    v12 = *v6;
    v13 = tempData.vfptr;
    addr = *(void ***)*v6;
    *v6 = (char *)v12 + 4;
    if ( !((int (__thiscall *)(PackableList<EmoteSet> *, void **, int))v13->UnPack)(&tempData, v6, v10)
      || !PackableHashTable<unsigned long,PackableList<EmoteSet>>::add(v4, (const unsigned int *)&addr, &tempData)
      && !v4->m_fThrowawayDuplicateKeysOnUnPack )
      break;
    ++size;
    if ( size >= v11 )
      goto LABEL_16;
  }
  PackableList<EmoteSet>::~PackableList<EmoteSet>(&tempData);
  return 0;
}
// 7E46DC: using guessed type int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char);

//----- (005953C0) --------------------------------------------------------  // acclient.c:446827
PackableHashTable<unsigned long,PackableList<EmoteSet> > *__thiscall PackableHashTable<unsigned long,PackableList<EmoteSet>>::vector_deleting_destructor(PackableHashTable<unsigned long,PackableList<EmoteSet> > *this, unsigned int a2)
{
  PackableHashTable<unsigned long,PackableList<EmoteSet> > *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable;
  PackableHashTable<unsigned long,PackableList<EmoteSet>>::EmptyContents(this);
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
// 7E46C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable)(void *, char);

//----- (00595410) --------------------------------------------------------  // acclient.c:446849
void __thiscall CEmoteTable::CEmoteTable(CEmoteTable *this)
{
  CEmoteTable *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->_emote_table;
  v1->vfptr = (PackObjVtbl *)&CEmoteTable::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 32;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
}
// 7E46C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable)(void *, char);
// 7E46F0: using guessed type int (__thiscall *CEmoteTable::vftable)(void *, char);

//----- (00595440) --------------------------------------------------------  // acclient.c:446868
CEmoteTable *__thiscall CEmoteTable::scalar_deleting_destructor(CEmoteTable *this, unsigned int a2)
{
  CEmoteTable *v2; // edi@1
  char *v3; // esi@1

  v2 = this;
  v3 = (char *)&this->_emote_table;
  this->vfptr = (PackObjVtbl *)&CEmoteTable::vftable;
  this->_emote_table.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable;
  PackableHashTable<unsigned long,PackableList<EmoteSet>>::EmptyContents(&this->_emote_table);
  if ( *((_DWORD *)v3 + 2) )
  {
    operator delete[](*((void **)v3 + 2));
    *((_DWORD *)v3 + 2) = 0;
  }
  *((_DWORD *)v3 + 3) = 0;
  *(_DWORD *)v3 = &PackObj::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E46C8: using guessed type int (__thiscall *PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable)(void *, char);
// 7E46F0: using guessed type int (__thiscall *CEmoteTable::vftable)(void *, char);

//----- (0070ABF0) --------------------------------------------------------  // acclient.c:797960
void sub_70ABF0()
{
  flt_871034 = 1000.0 + 1.0;
}

//----- (0070AC10) --------------------------------------------------------  // acclient.c:797966
void sub_70AC10()
{
  flt_871038 = 24.0 * 8.0;
}

//----- (0070AC30) --------------------------------------------------------  // acclient.c:797972
void sub_70AC30()
{
  flt_87103C = 24.0 * 0.5;
}

//----- (0070AC50) --------------------------------------------------------  // acclient.c:797978
int sub_70AC50()
{
  return atexit(nullsub_1422);
}

