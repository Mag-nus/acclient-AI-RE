/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QualityRegistrar
   Object     : ENGINE\engine_notice\QualityRegistrar.obj
   Functions  : 34
   Addresses  : 00692C30 - 00719140 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00692C30) --------------------------------------------------------  // acclient.c:682504
IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *__thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *v2; // esi@1
  HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 8005FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable[4])(void *, char);

//----- (00692C70) --------------------------------------------------------  // acclient.c:682525
IntrusiveHashTable<unsigned long,QualityHandler *,1> *__thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v2; // esi@1
  QualityHandler **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,QualityHandler *,1>Vtbl *)IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 800600: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable[3])(void *, char);

//----- (00692CB0) --------------------------------------------------------  // acclient.c:682546
char __thiscall QualityHandler::Remove(QualityHandler *this, QualityChangeHandler *i_pcHandler)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ebx@1
  unsigned int v5; // eax@2
  unsigned int v6; // esi@2
  int v7; // edx@2
  unsigned int v8; // ecx@2
  int v9; // edx@6
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+10h] [bp-18h]@1
  HashTableData<unsigned long,HeritageGroup_CG> **iter_4; // [sp+14h] [bp-14h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_handlers.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currBucket;
  iter = v2->m_currHashTable;
  iter_4 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v5 = v3->m_data.iconImage.id;
      v6 = *(_DWORD *)v5;
      v7 = *(_DWORD *)(v5 + 8);
      v8 = *(_DWORD *)v5;
      if ( *(_DWORD *)v5 < (unsigned int)(*(_DWORD *)v5 + 4 * v7) )
      {
        while ( *(QualityChangeHandler **)v8 != i_pcHandler )
        {
          v8 += 4;
          v4 = iter_4;
          if ( v8 >= *(_DWORD *)v5 + 4 * *(_DWORD *)(v5 + 8) )
            goto LABEL_7;
        }
        v9 = v7 - 1;
        *(_DWORD *)(v5 + 8) = v9;
        *(_DWORD *)v8 = *(_DWORD *)(v6 + 4 * v9);
        *(_DWORD *)(*(_DWORD *)v5 + 4 * *(_DWORD *)(v5 + 8)) = 0;
      }
LABEL_7:
      v3 = (HashTableData<unsigned long,HeritageGroup_CG> *)v3->m_data.vfptr;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      iter_4 = v4;
      if ( v4 == &iter->m_buckets[iter->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_2;
        return 1;
      }
    }
  }
  return 1;
}

//----- (00692D60) --------------------------------------------------------  // acclient.c:682613
char __thiscall QualityRegistrar::UnRegisterAllQualityHandler(QualityRegistrar *this, QualityChangeHandler *i_pcHandler)
{
  QualityRegistrar *v2; // ebp@1
  QualityHandler *v3; // esi@1
  QualityHandler **v4; // edi@2
  IntrusiveHashIterator<unsigned long,QualityHandler *,1> iter; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_handlers,
    (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&iter);
  v3 = iter.m_currElement;
  if ( iter.m_currElement )
  {
    v4 = iter.m_currBucket;
    do
    {
LABEL_3:
      QualityHandler::Remove(v3, i_pcHandler);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &iter.m_currHashTable->m_buckets[iter.m_currHashTable->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_3;
        break;
      }
    }
  }
  QualityHandler::Remove(&v2->m_PlayerQualityHandler, i_pcHandler);
  QualityHandler::Remove(&v2->m_GlobalQualityHandler, i_pcHandler);
  return 1;
}

//----- (00692DE0) --------------------------------------------------------  // acclient.c:682655
char __thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::grow(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,QualityHandler *,1>::resize_internal(v2, *v3);
}

//----- (00692E30) --------------------------------------------------------  // acclient.c:682673
char __thiscall QualityHandler::Remove(QualityHandler *this, unsigned __int64 statCode, QualityChangeHandler *i_pcHandler)
{
  SmartArray<bool (__cdecl*)(void),1> *v3; // ecx@2
  char v4; // al@3
  unsigned __int64 _key; // [sp+0h] [bp-14h]@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@1

  _key = statCode;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_handlers.m_intrusiveTable,
    &result,
    &_key);
  if ( result.m_currElement && (v3 = (SmartArray<bool (__cdecl*)(void),1> *)LODWORD(result.m_currElement->m_data)) != 0 )
    v4 = SmartArray<UIElement *,1>::RemoveUnOrdered(v3, (bool (__cdecl *const *)())&i_pcHandler);
  else
    v4 = 0;
  return v4;
}

//----- (00692E80) --------------------------------------------------------  // acclient.c:682693
char __thiscall QualityHandler::CallChangeHandler(QualityHandler *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  unsigned int v4; // esi@1
  int v5; // edi@2
  char v6; // al@5
  unsigned __int64 _key; // [sp+10h] [bp-14h]@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+18h] [bp-Ch]@1

  v4 = 0;
  _key = __PAIR__(stype, senum);
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_handlers.m_intrusiveTable,
    &result,
    &_key);
  if ( result.m_currElement && (v5 = LODWORD(result.m_currElement->m_data)) != 0 )
  {
    if ( *(_DWORD *)(v5 + 8) )
    {
      do
        (*(void (__stdcall **)(CWeenieObject *, StatType, unsigned int))**(void (__stdcall ****)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 4 * v4++))(
          cwobj,
          stype,
          senum);
      while ( v4 < *(_DWORD *)(v5 + 8) );
    }
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}

//----- (00692F00) --------------------------------------------------------  // acclient.c:682728
char __thiscall QualityHandler::CallRemoveHandler(QualityHandler *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  unsigned int v4; // esi@1
  int v5; // edi@2
  char v6; // al@5
  unsigned __int64 _key; // [sp+10h] [bp-14h]@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+18h] [bp-Ch]@1

  v4 = 0;
  _key = __PAIR__(stype, senum);
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_handlers.m_intrusiveTable,
    &result,
    &_key);
  if ( result.m_currElement && (v5 = LODWORD(result.m_currElement->m_data)) != 0 )
  {
    if ( *(_DWORD *)(v5 + 8) )
    {
      do
        (*(void (__stdcall **)(CWeenieObject *, StatType, unsigned int))(**(_DWORD **)(*(_DWORD *)v5 + 4 * v4++) + 4))(
          cwobj,
          stype,
          senum);
      while ( v4 < *(_DWORD *)(v5 + 8) );
    }
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6;
}

//----- (00692F90) --------------------------------------------------------  // acclient.c:682763
char __thiscall QualityRegistrar::UnRegisterQualityHandler(QualityRegistrar *this, unsigned int i_iidTarget, StatType i_StatType, unsigned int i_StatCode, QualityChangeHandler *i_pcHandler)
{
  QualityHandler *i; // eax@2
  QualityHandler *v6; // ecx@5
  char result; // al@8

  if ( i_iidTarget )
  {
    for ( i = this->m_handlers.m_buckets[i_iidTarget % this->m_handlers.m_numBuckets]; i; i = i->m_hashNext )
    {
      if ( i->m_hashKey == i_iidTarget )
        break;
    }
    v6 = i;
  }
  else
  {
    v6 = &this->m_GlobalQualityHandler;
  }
  if ( v6 )
    result = QualityHandler::Remove(v6, __PAIR__(i_StatType, i_StatCode), i_pcHandler);
  else
    result = 0;
  return result;
}

//----- (00693000) --------------------------------------------------------  // acclient.c:682790
char __thiscall QualityRegistrar::UnRegisterQualityHandlerForThePlayer(QualityRegistrar *this, StatType i_StatType, unsigned int i_StatCode, QualityChangeHandler *i_pcHandler)
{
  SmartArray<bool (__cdecl*)(void),1> *v4; // ecx@2
  char v5; // al@3
  unsigned __int64 _key; // [sp+0h] [bp-14h]@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+8h] [bp-Ch]@1

  _key = __PAIR__(i_StatType, i_StatCode);
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_PlayerQualityHandler.m_handlers.m_intrusiveTable,
    &result,
    &_key);
  if ( result.m_currElement && (v4 = (SmartArray<bool (__cdecl*)(void),1> *)LODWORD(result.m_currElement->m_data)) != 0 )
    v5 = SmartArray<UIElement *,1>::RemoveUnOrdered(v4, (bool (__cdecl *const *)())&i_pcHandler);
  else
    v5 = 0;
  return v5;
}

//----- (00693070) --------------------------------------------------------  // acclient.c:682810
char __thiscall QualityRegistrar::CallChangeHandler(QualityRegistrar *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  QualityRegistrar *v4; // esi@1
  unsigned int v5; // ecx@1
  int v6; // eax@2
  bool v7; // zf@2
  unsigned int v8; // eax@11

  v4 = this;
  v5 = cwobj->id;
  if ( v5 )
  {
    v6 = (int)v4->m_handlers.m_buckets[v5 % v4->m_handlers.m_numBuckets];
    v7 = v6 == 0;
    if ( !v6 )
      goto LABEL_8;
    do
    {
      if ( *(_DWORD *)v6 == v5 )
        break;
      v6 = *(_DWORD *)(v6 + 4);
    }
    while ( v6 );
  }
  else
  {
    v6 = (int)&v4->m_GlobalQualityHandler;
  }
  v7 = v6 == 0;
LABEL_8:
  if ( !v7 )
    QualityHandler::CallChangeHandler((QualityHandler *)v6, cwobj, stype, senum);
  if ( SmartBox::smartbox )
    v8 = SmartBox::smartbox->player_id;
  else
    v8 = 0;
  if ( cwobj->id == v8 )
    QualityHandler::CallChangeHandler(&v4->m_PlayerQualityHandler, cwobj, stype, senum);
  QualityHandler::CallChangeHandler(&v4->m_GlobalQualityHandler, cwobj, stype, senum);
  return 1;
}

//----- (00693100) --------------------------------------------------------  // acclient.c:682853
char __thiscall QualityRegistrar::CallRemoveHandler(QualityRegistrar *this, CWeenieObject *cwobj, StatType stype, unsigned int senum)
{
  QualityRegistrar *v4; // esi@1
  unsigned int v5; // ecx@1
  int v6; // eax@2
  bool v7; // zf@2
  unsigned int v8; // eax@11

  v4 = this;
  v5 = cwobj->id;
  if ( v5 )
  {
    v6 = (int)v4->m_handlers.m_buckets[v5 % v4->m_handlers.m_numBuckets];
    v7 = v6 == 0;
    if ( !v6 )
      goto LABEL_8;
    do
    {
      if ( *(_DWORD *)v6 == v5 )
        break;
      v6 = *(_DWORD *)(v6 + 4);
    }
    while ( v6 );
  }
  else
  {
    v6 = (int)&v4->m_GlobalQualityHandler;
  }
  v7 = v6 == 0;
LABEL_8:
  if ( !v7 )
    QualityHandler::CallRemoveHandler((QualityHandler *)v6, cwobj, stype, senum);
  if ( SmartBox::smartbox )
    v8 = SmartBox::smartbox->player_id;
  else
    v8 = 0;
  if ( cwobj->id == v8 )
    QualityHandler::CallRemoveHandler(&v4->m_PlayerQualityHandler, cwobj, stype, senum);
  QualityHandler::CallRemoveHandler(&v4->m_GlobalQualityHandler, cwobj, stype, senum);
  return 1;
}

//----- (00693190) --------------------------------------------------------  // acclient.c:682896
void __thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::IntrusiveHashTable<unsigned long,QualityHandler *,1>(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,QualityHandler *,1>Vtbl *)IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (QualityHandler **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (QualityHandler **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 800600: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable[3])(void *, char);

//----- (00693220) --------------------------------------------------------  // acclient.c:682929
void __thiscall IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>(IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 8005FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable[4])(void *, char);

//----- (006932B0) --------------------------------------------------------  // acclient.c:682962
char __thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::resize_internal(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v3; // esi@1
  char result; // al@2
  QualityHandler *v5; // edi@3
  int v6; // ecx@4
  QualityHandler **v7; // eax@5
  int v8; // eax@6
  QualityHandler **v9; // ebx@7
  QualityHandler *v10; // ecx@7
  QualityHandler *v11; // eax@9
  QualityHandler *v12; // edx@10
  QualityHandler *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  QualityHandler **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (QualityHandler **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (QualityHandler **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (QualityHandler **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,QualityHandler *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (QualityHandler **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (QualityHandler **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (006933F0) --------------------------------------------------------  // acclient.c:683078
char __thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::add(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this, QualityHandler *data)
{
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  QualityHandler *v4; // eax@1
  unsigned int v5; // edx@6
  QualityHandler **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<unsigned long,QualityHandler *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (QualityHandler **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (QualityHandler **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00693550) --------------------------------------------------------  // acclient.c:683214
bool __thiscall QualityRegistrar::UnRegisterAllQualityHandler(QualityRegistrar *this, unsigned int i_iidTarget)
{
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
           (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_handlers,
           (IDClass<_tagDataID,32,0> *)&i_iidTarget) != 0;
}

//----- (006935D0) --------------------------------------------------------  // acclient.c:683258
char __thiscall QualityHandler::Add(QualityHandler *this, unsigned __int64 statCode, QualityChangeHandler *i_pcHandler)
{
  QualityHandler *v3; // edi@1
  SmartArray<UIElement *,1> *v4; // esi@1
  void *v5; // eax@4
  unsigned __int64 pList; // [sp+8h] [bp-14h]@1
  IntrusiveHashIterator<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> result; // [sp+10h] [bp-Ch]@1

  v3 = this;
  pList = statCode;
  v4 = 0;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::find_internal(
    (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_handlers.m_intrusiveTable,
    &result,
    &pList);
  if ( result.m_currElement )
    v4 = (SmartArray<UIElement *,1> *)LODWORD(result.m_currElement->m_data);
  if ( !v4 )
  {
    v5 = operator new(0xCu);
    if ( v5 )
    {
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      v4 = (SmartArray<UIElement *,1> *)v5;
    }
    else
    {
      v4 = 0;
    }
    LODWORD(pList) = v4;
    HashTable<unsigned __int64,DiskController *,0>::add(
      (HashTable<unsigned __int64,DiskController *,0> *)&v3->m_handlers,
      &statCode,
      (DiskController *const *)&pList);
  }
  return SmartArray<QualityChangeHandler *,1>::add_unique(v4, (UIElement *const *)&i_pcHandler);
}

//----- (00693650) --------------------------------------------------------  // acclient.c:683299
char __thiscall QualityRegistrar::RegisterQualityHandlerForThePlayer(QualityRegistrar *this, StatType i_StatType, unsigned int i_StatCode, QualityChangeHandler *i_pcHandler)
{
  return QualityHandler::Add(&this->m_PlayerQualityHandler, __PAIR__(i_StatType, i_StatCode), i_pcHandler);
}

//----- (00693680) --------------------------------------------------------  // acclient.c:683305
HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0> *__thiscall HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vector_deleting_destructor(HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0> *this, unsigned int a2)
{
  HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>Vtbl *)HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 8005FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable[4])(void *, char);
// 800604: using guessed type int (__thiscall *HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable[2])(void *, char);

//----- (006936E0) --------------------------------------------------------  // acclient.c:683331
void __thiscall QualityHandler::~QualityHandler(QualityHandler *this)
{
  QualityHandler *v1; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ecx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  unsigned int v6; // ebx@2
  void *v7; // eax@10
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v1 = this;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_handlers.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  iter = v2->m_currHashTable;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v6 = v3->m_data.iconImage.id;
      if ( v6 )
      {
        if ( (*(_DWORD *)(v6 + 4) & 0x80000000) == 0x80000000 )
          operator delete[](*(void **)v6);
        operator delete((void *)v6);
        v4 = iter;
      }
      v3 = (HashTableData<unsigned long,HeritageGroup_CG> *)v3->m_data.vfptr;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v3 = *v5;
        if ( *v5 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_handlers.m_intrusiveTable);
  v1->m_handlers.vfptr = (HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>Vtbl *)HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::delete_contents((IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0> *)&v1->m_handlers.m_intrusiveTable);
  v7 = v1->m_handlers.m_intrusiveTable.m_buckets;
  v1->m_handlers.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>Vtbl *)IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable;
  if ( v7 != v1->m_handlers.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v7);
  v1->m_handlers.m_intrusiveTable.m_buckets = 0;
  v1->m_handlers.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_handlers.m_intrusiveTable.m_numBuckets = 0;
  v1->m_handlers.m_intrusiveTable.m_numElements = 0;
}
// 8005FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable[4])(void *, char);
// 800604: using guessed type int (__thiscall *HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable[2])(void *, char);

//----- (006937B0) --------------------------------------------------------  // acclient.c:683397
void __thiscall QualityRegistrar::QualityRegistrar(QualityRegistrar *this)
{
  QualityRegistrar *v1; // esi@1

  v1 = this;
  this->vfptr = (QualityRegistrarVtbl *)&QualityRegistrar::vftable;
  IntrusiveHashTable<unsigned long,QualityHandler *,1>::IntrusiveHashTable<unsigned long,QualityHandler *,1>(
    &this->m_handlers,
    7u);
  v1->m_PlayerQualityHandler.m_hashKey = 0;
  v1->m_PlayerQualityHandler.m_hashNext = 0;
  v1->m_PlayerQualityHandler.m_handlers.vfptr = (HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>Vtbl *)HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>(
    &v1->m_PlayerQualityHandler.m_handlers.m_intrusiveTable,
    0x17u);
  v1->m_GlobalQualityHandler.m_hashKey = 0;
  v1->m_GlobalQualityHandler.m_hashNext = 0;
  v1->m_GlobalQualityHandler.m_handlers.vfptr = (HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>Vtbl *)HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable;
  IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>(
    &v1->m_GlobalQualityHandler.m_handlers.m_intrusiveTable,
    0x17u);
  QualityRegistrar::s_pQR = v1;
}
// 800604: using guessed type int (__thiscall *HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable[2])(void *, char);
// 800608: using guessed type int (__thiscall *QualityRegistrar::vftable)(void *, char);

//----- (00693810) --------------------------------------------------------  // acclient.c:683424
char __thiscall QualityRegistrar::RegisterQualityHandler(QualityRegistrar *this, unsigned int i_iidTarget, StatType i_StatType, unsigned int i_StatCode, QualityChangeHandler *i_pcHandler)
{
  QualityRegistrar *v5; // ebx@1
  StatType v6; // ecx@1
  int i; // eax@2
  QualityHandler *v8; // esi@7
  void *v9; // eax@8

  v5 = this;
  v6 = i_StatType;
  if ( i_iidTarget )
  {
    for ( i = (int)v5->m_handlers.m_buckets[i_iidTarget % v5->m_handlers.m_numBuckets]; i; i = *(_DWORD *)(i + 4) )
    {
      if ( *(_DWORD *)i == i_iidTarget )
        break;
    }
  }
  else
  {
    i = (int)&v5->m_GlobalQualityHandler;
  }
  v8 = (QualityHandler *)i;
  if ( !i )
  {
    v9 = operator new(0x7Cu);
    v8 = (QualityHandler *)v9;
    if ( v9 )
    {
      *(_DWORD *)v9 = i_iidTarget;
      *((_DWORD *)v9 + 1) = 0;
      *((_DWORD *)v9 + 2) = HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable;
      IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>(
        (IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0> *)((char *)v9 + 12),
        0x17u);
    }
    else
    {
      v8 = 0;
    }
    IntrusiveHashTable<unsigned long,QualityHandler *,1>::add(&v5->m_handlers, v8);
    v6 = i_StatType;
  }
  return QualityHandler::Add(v8, __PAIR__(v6, i_StatCode), i_pcHandler);
}
// 800604: using guessed type int (__thiscall *HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable[2])(void *, char);

//----- (006938C0) --------------------------------------------------------  // acclient.c:683472
void __thiscall IntrusiveHashTable<unsigned long,QualityHandler *,1>::delete_contents(IntrusiveHashTable<unsigned long,QualityHandler *,1> *this)
{
  IntrusiveHashTable<unsigned long,QualityHandler *,1> *v1; // esi@1
  int v2; // ecx@2
  QualityHandler **v3; // eax@3
  int v4; // eax@4
  QualityHandler **v5; // edx@5
  QualityHandler *v6; // edi@5
  QualityHandler *v7; // eax@7
  QualityHandler *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (QualityHandler **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (QualityHandler **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      QualityHandler::~QualityHandler(v6);
      operator delete(v6);
    }
  }
}

//----- (00693950) --------------------------------------------------------  // acclient.c:683532
void __thiscall QualityRegistrar::~QualityRegistrar(QualityRegistrar *this)
{
  QualityRegistrar *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1

  v1 = this;
  v2 = (char *)&this->m_handlers;
  this->vfptr = (QualityRegistrarVtbl *)&QualityRegistrar::vftable;
  QualityRegistrar::s_pQR = 0;
  IntrusiveHashTable<unsigned long,QualityHandler *,1>::delete_contents(&this->m_handlers);
  QualityHandler::~QualityHandler(&v1->m_GlobalQualityHandler);
  QualityHandler::~QualityHandler(&v1->m_PlayerQualityHandler);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
}
// 800600: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable[3])(void *, char);
// 800608: using guessed type int (__thiscall *QualityRegistrar::vftable)(void *, char);

//----- (006939B0) --------------------------------------------------------  // acclient.c:683558
QualityRegistrar *__thiscall QualityRegistrar::vector_deleting_destructor(QualityRegistrar *this, unsigned int a2)
{
  QualityRegistrar *v2; // esi@1

  v2 = this;
  QualityRegistrar::~QualityRegistrar(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00719070) --------------------------------------------------------  // acclient.c:811748
void sub_719070()
{
  flt_8F859C = 1000.0 + 1.0;
}

//----- (00719090) --------------------------------------------------------  // acclient.c:811754
void sub_719090()
{
  flt_8F85A0 = 24.0 * 8.0;
}

//----- (007190B0) --------------------------------------------------------  // acclient.c:811760
void sub_7190B0()
{
  flt_8F85A4 = 24.0 * 0.5;
}

//----- (007190D0) --------------------------------------------------------  // acclient.c:811766
void sub_7190D0()
{
  flt_8F85AC = 0.00019999999 * 3.0 + 0.1;
}

//----- (007190F0) --------------------------------------------------------  // acclient.c:811772
void _E99_44()
{
  dbl_8F85B0 = 1.0 / 30.0;
}

//----- (00719110) --------------------------------------------------------  // acclient.c:811778
void _E101_43()
{
  dbl_8F85B8 = 1.0 / 5.0;
}

//----- (00719130) --------------------------------------------------------  // acclient.c:811784
void sub_719130()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F85C0, PFID_A8R8G8B8);
}

//----- (00719140) --------------------------------------------------------  // acclient.c:811790
int sub_719140()
{
  return atexit(nullsub_242);
}

