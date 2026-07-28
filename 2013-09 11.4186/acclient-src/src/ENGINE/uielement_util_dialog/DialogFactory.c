/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DialogFactory
   Object     : ENGINE\uielement_util_dialog\DialogFactory.obj
   Functions  : 43
   Addresses  : 00476D50 - 0075ED50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00476D50) --------------------------------------------------------  // acclient.c:179912
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *v2; // esi@1
  HashTableData<unsigned long,List<DialogInfo> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable;
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
// 79E084: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable[7])(void *, char);

//----- (00476D90) --------------------------------------------------------  // acclient.c:179933
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *v2; // esi@1
  HashTableData<unsigned long,DialogInfo> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable;
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
// 79E088: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable[6])(void *, char);

//----- (00476DD0) --------------------------------------------------------  // acclient.c:179954
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *v2; // esi@1
  HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable;
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
// 79E08C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable[5])(void *, char);

//----- (00476E10) --------------------------------------------------------  // acclient.c:179975
char __thiscall List<DialogInfo>::pop_front(List<DialogInfo> *this, DialogInfo *retval)
{
  List<DialogInfo> *v2; // edi@1
  ListNode<DialogInfo> *v3; // esi@1
  char result; // al@2
  ListNode<DialogInfo> *v5; // eax@3

  v2 = this;
  v3 = this->_head;
  if ( v3 )
  {
    v5 = v3->next;
    this->_head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      this->_tail = 0;
    PropertyCollection::operator=(retval, v3);
    retval->pointer = v3->data.pointer;
    retval->parent = v3->data.parent;
    retval->context = v3->data.context;
    PropertyCollection::~PropertyCollection(&v3->data.data);
    operator delete(v3);
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00476E80) --------------------------------------------------------  // acclient.c:180009
char __thiscall List<DialogInfo>::remove(List<DialogInfo> *this, ListNode<DialogInfo> *node)
{
  List<DialogInfo> *v2; // edi@1
  ListNode<DialogInfo> *v3; // ecx@1
  ListNode<DialogInfo> *v4; // eax@2
  ListNode<DialogInfo> *v6; // eax@5

  v2 = this;
  v3 = 0;
  if ( !node )
    return 0;
  v4 = v2->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v2->_tail = node->prev;
      goto LABEL_11;
    }
    v3 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v2->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v3;
    goto LABEL_11;
  }
  v2->_tail = 0;
LABEL_11:
  PropertyCollection::~PropertyCollection(&node->data.data);
  operator delete(node);
  --v2->_num_elements;
  return 1;
}

//----- (00476F10) --------------------------------------------------------  // acclient.c:180052
void __thiscall List<DialogInfo>::flush(List<DialogInfo> *this)
{
  List<DialogInfo> *v1; // edi@1
  ListNode<DialogInfo> *v2; // esi@3
  ListNode<DialogInfo> *v3; // eax@4
  PropertyCollection v4; // [sp+Ch] [bp-84h]@3
  Dialog *v5; // [sp+84h] [bp-Ch]@3
  UIFramework *v6; // [sp+88h] [bp-8h]@3
  unsigned int v7; // [sp+8Ch] [bp-4h]@3

  v1 = this;
  while ( v1->_head )
  {
    PropertyCollection::PropertyCollection(&v4);
    v2 = v1->_head;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    if ( v2 )
    {
      v3 = v2->next;
      v1->_head = v3;
      if ( v3 )
        v3->prev = 0;
      else
        v1->_tail = 0;
      PropertyCollection::operator=(&v4, v2);
      v5 = v2->data.pointer;
      v6 = v2->data.parent;
      v7 = v2->data.context;
      PropertyCollection::~PropertyCollection(&v2->data.data);
      operator delete(v2);
      --v1->_num_elements;
    }
    PropertyCollection::~PropertyCollection(&v4);
  }
}

//----- (00476FC0) --------------------------------------------------------  // acclient.c:180091
char __thiscall HashTable<unsigned long,DialogInfo,0>::find(HashTable<unsigned long,DialogInfo,0> *this, const unsigned int *_key, DialogInfo *_retval)
{
  HashTableData<unsigned long,DialogInfo> *v3; // eax@1
  char result; // al@4
  int v5; // esi@6

  v3 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    v5 = (int)&v3->m_data;
    PropertyCollection::operator=(_retval, &v3->m_data);
    _retval->pointer = *(Dialog **)(v5 + 120);
    _retval->parent = *(UIFramework **)(v5 + 124);
    _retval->context = *(_DWORD *)(v5 + 128);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00477030) --------------------------------------------------------  // acclient.c:180124
List<DialogInfo> *__thiscall List<DialogInfo>::scalar_deleting_destructor(List<DialogInfo> *this, unsigned int a2)
{
  List<DialogInfo> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
  List<DialogInfo>::flush(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (00477060) --------------------------------------------------------  // acclient.c:180138
bool __cdecl DialogFactory::IsDialogOpen(unsigned int i_queueID)
{
  bool result; // al@1
  unsigned int *v2; // eax@7

  result = DialogFactory::s_listNonQueuedInfos._num_elements != 0;
  if ( !i_queueID )
  {
    if ( !result && !stru_818E2C.m_numElements )
      return 0;
    return 1;
  }
  if ( i_queueID != 1 )
  {
    v2 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
           &DialogFactory::s_hashCurInfos,
           &i_queueID);
    if ( !v2 || !v2[30] )
      return 0;
    return 1;
  }
  return result;
}

//----- (004770B0) --------------------------------------------------------  // acclient.c:180163
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,List<DialogInfo> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,List<DialogInfo> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79E084: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable[7])(void *, char);

//----- (00477140) --------------------------------------------------------  // acclient.c:180196
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,DialogInfo> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,DialogInfo> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79E088: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable[6])(void *, char);

//----- (004771D0) --------------------------------------------------------  // acclient.c:180229
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79E08C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable[5])(void *, char);

//----- (00477260) --------------------------------------------------------  // acclient.c:180262
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,List<DialogInfo> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,List<DialogInfo> > **v5; // edx@5
  HashTableData<unsigned long,List<DialogInfo> > *v6; // edi@5
  HashTableData<unsigned long,List<DialogInfo> > *v7; // eax@7
  HashTableData<unsigned long,List<DialogInfo> > *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,List<DialogInfo> > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,List<DialogInfo> > **)v4;
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
      v6->m_data.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
      List<DialogInfo>::flush(&v6->m_data);
      operator delete(v6);
    }
  }
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (004772F0) --------------------------------------------------------  // acclient.c:180324
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,DialogInfo> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,DialogInfo> **v5; // edx@5
  HashTableData<unsigned long,DialogInfo> *v6; // edi@5
  HashTableData<unsigned long,DialogInfo> *v7; // eax@7
  HashTableData<unsigned long,DialogInfo> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,DialogInfo> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,DialogInfo> **)v4;
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
      PropertyCollection::~PropertyCollection(&v6->m_data.data);
      operator delete(v6);
    }
  }
}

//----- (00477380) --------------------------------------------------------  // acclient.c:180384
char __thiscall HashTable<unsigned long,List<DialogInfo>,0>::erase(HashTable<unsigned long,List<DialogInfo>,0> *this, const unsigned int *_key)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1
  void *v3; // esi@1
  char result; // al@2

  v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)_key);
  v3 = v2;
  if ( v2 )
  {
    v2[1].m_hashKey.id = (unsigned int)List<DialogInfo>::vftable;
    List<DialogInfo>::flush((List<DialogInfo> *)&v2[1]);
    operator delete(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (004773C0) --------------------------------------------------------  // acclient.c:180410
void __cdecl DialogFactory::DialogDone(DialogInfo *i_info)
{
  DialogInfo *v1; // esi@1
  IDClass<_tagDataID,32,0> *v2; // edi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // edx@1
  unsigned int *v4; // eax@6
  HashSetData<IDClass<_tagDataID,32,0> > *v5; // eax@6

  v1 = i_info;
  v2 = (IDClass<_tagDataID,32,0> *)&i_info->context;
  v3 = stru_818EA4.m_buckets[i_info->context % stru_818EA4.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey.id != i_info->context )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        goto LABEL_8;
    }
    if ( v3 )
    {
      v4 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
             &DialogFactory::s_hashCallbacks,
             &i_info->context);
      ((void (__cdecl *)(_DWORD))*v4)(&v1->pointer->m_cData);
      v5 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
             &stru_818EA4,
             v2);
      if ( v5 )
        operator delete(v5);
    }
  }
LABEL_8:
  ECM_UI::SendNotice_CloseDialog(v2->id, &v1->pointer->m_cData);
  i_info = (DialogInfo *)v1->pointer;
  if ( i_info )
  {
    ((void (__stdcall *)(DialogInfo **))v1->parent->vfptr[2].OnLoseFocus)(&i_info);
    ((void (__stdcall *)(_DWORD))v1->pointer->vfptr[26].__vecDelDtor)(0);
  }
}

//----- (00477470) --------------------------------------------------------  // acclient.c:180453
HashTable<unsigned long,List<DialogInfo>,0> *__thiscall HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor(HashTable<unsigned long,List<DialogInfo>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,List<DialogInfo>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,List<DialogInfo>,0>Vtbl *)HashTable<unsigned long,List<DialogInfo>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable;
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
// 79E084: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable[7])(void *, char);
// 79E090: using guessed type int (__thiscall *HashTable<unsigned long,List<DialogInfo>,0>::vftable[4])(void *, char);

//----- (004774D0) --------------------------------------------------------  // acclient.c:180479
HashTable<unsigned long,DialogInfo,0> *__thiscall HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor(HashTable<unsigned long,DialogInfo,0> *this, unsigned int a2)
{
  HashTable<unsigned long,DialogInfo,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,DialogInfo,0>Vtbl *)HashTable<unsigned long,DialogInfo,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable;
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
// 79E088: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable[6])(void *, char);
// 79E094: using guessed type int (__thiscall *HashTable<unsigned long,DialogInfo,0>::vftable[3])(void *, char);

//----- (00477530) --------------------------------------------------------  // acclient.c:180505
HashTable<unsigned long,void (__cdecl*)(PropertyCollection const &),0> *__thiscall HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor(HashTable<unsigned long,void (__cdecl*)(PropertyCollection const &),0> *this, unsigned int a2)
{
  HashTable<unsigned long,void (__cdecl*)(PropertyCollection const &),0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,void (__cdecl*)(PropertyCollection const &),0>Vtbl *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable;
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
// 79E08C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable[5])(void *, char);
// 79E098: using guessed type int (__thiscall *HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable[2])(void *, char);

//----- (00477590) --------------------------------------------------------  // acclient.c:180531
void __cdecl DialogFactory::UpdatePendingDialogDisplay_()
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v0; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v1; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v2; // ebx@1
  HashTableData<unsigned long,List<DialogInfo> > *v3; // eax@3
  int v4; // eax@8
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *hashIter; // [sp+8h] [bp-9Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-90h]@1
  DialogInfo info; // [sp+20h] [bp-84h]@2

  v0 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(&stru_818E2C, &result);
  v1 = v0->m_currElement;
  v2 = v0->m_currBucket;
  hashIter = v0->m_currHashTable;
  if ( v1 )
  {
    do
    {
LABEL_2:
      info.data.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
      info.data.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
        &info.data.m_hashProperties.m_intrusiveTable,
        0);
      info.data.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
      PropertyCollection::operator=(&info, &v1->m_data);
      info.pointer = (Dialog *)v1->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[9];
      info.parent = (UIFramework *)v1->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[10];
      info.context = (unsigned int)&v1->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[11]->m_hashKey;
      if ( info.pointer )
      {
        v3 = DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[v1->m_hashKey
                                                                        % DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets];
        if ( v3 )
        {
          while ( v3->m_hashKey != v1->m_hashKey )
          {
            v3 = v3->m_hashNext;
            if ( !v3 )
              goto LABEL_10;
          }
          if ( v3 )
          {
            v4 = (int)&v3->m_data;
            if ( v4 )
              Dialog::UpdatePendingDialogDisplay(info.pointer, *(_DWORD *)(v4 + 12));
          }
        }
      }
LABEL_10:
      PropertyCollection::~PropertyCollection(&info.data);
      v1 = v1->m_hashNext;
    }
    while ( v1 );
    while ( 1 )
    {
      ++v2;
      if ( v2 == &hashIter->m_buckets[hashIter->m_numBuckets] )
        break;
      if ( *v2 )
      {
        v1 = *v2;
        if ( *v2 )
          goto LABEL_2;
        return;
      }
    }
  }
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (004776A0) --------------------------------------------------------  // acclient.c:180605
void __thiscall HashTableData<unsigned long,DialogInfo>::HashTableData<unsigned long,DialogInfo>(HashTableData<unsigned long,DialogInfo> *this, const unsigned int *_key, DialogInfo *_data)
{
  char *v3; // esi@1

  this->m_hashKey = *_key;
  v3 = (char *)&this->m_data;
  this->m_hashNext = 0;
  *(_DWORD *)v3 = &PropertyCollection::vftable;
  *((_DWORD *)v3 + 1) = &AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &this->m_data.data.m_hashProperties.m_intrusiveTable,
    0);
  *((_DWORD *)v3 + 1) = &AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  PropertyCollection::operator=(v3, _data);
  *((_DWORD *)v3 + 30) = _data->pointer;
  *((_DWORD *)v3 + 31) = _data->parent;
  *((_DWORD *)v3 + 32) = _data->context;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00477710) --------------------------------------------------------  // acclient.c:180627
void __thiscall ListNode<DialogInfo>::ListNode<DialogInfo>(ListNode<DialogInfo> *this, DialogInfo *_data)
{
  ListNode<DialogInfo> *v2; // esi@1

  v2 = this;
  this->data.data.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
  this->data.data.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &this->data.data.m_hashProperties.m_intrusiveTable,
    0);
  v2->data.data.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  PropertyCollection::operator=(v2, _data);
  v2->data.pointer = _data->pointer;
  v2->data.parent = _data->parent;
  v2->data.context = _data->context;
  v2->next = 0;
  v2->prev = 0;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);

//----- (00477780) --------------------------------------------------------  // acclient.c:180649
char __thiscall List<DialogInfo>::insert(List<DialogInfo> *this, ListNode<DialogInfo> *node, DialogInfo *val)
{
  List<DialogInfo> *v3; // esi@1
  ListNode<DialogInfo> *v4; // eax@1
  int v5; // eax@2
  char result; // al@3
  ListNode<DialogInfo> *v7; // edx@6

  v3 = this;
  v4 = (ListNode<DialogInfo> *)operator new(0x8Cu);
  if ( v4 && (ListNode<DialogInfo>::ListNode<DialogInfo>(v4, val), v5) )
  {
    if ( v3->_head )
    {
      *(_DWORD *)(v5 + 132) = node;
      *(_DWORD *)(v5 + 136) = node->prev;
      v7 = node->prev;
      if ( v7 )
      {
        v7->next = (ListNode<DialogInfo> *)v5;
        node->prev = (ListNode<DialogInfo> *)v5;
        ++v3->_num_elements;
        result = 1;
      }
      else
      {
        v3->_head = (ListNode<DialogInfo> *)v5;
        node->prev = (ListNode<DialogInfo> *)v5;
        ++v3->_num_elements;
        result = 1;
      }
    }
    else
    {
      v3->_head = (ListNode<DialogInfo> *)v5;
      v3->_tail = (ListNode<DialogInfo> *)v5;
      ++v3->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00477810) --------------------------------------------------------  // acclient.c:180697
char __thiscall HashTable<unsigned long,DialogInfo,0>::add(HashTable<unsigned long,DialogInfo,0> *this, const unsigned int *_key, DialogInfo *_data)
{
  HashTable<unsigned long,DialogInfo,0> *v3; // edi@1
  HashTableData<unsigned long,DialogInfo> *v4; // eax@1
  int v5; // eax@2
  int v6; // esi@2
  char result; // al@7

  v3 = this;
  v4 = (HashTableData<unsigned long,DialogInfo> *)operator new(0x8Cu);
  if ( v4 )
  {
    HashTableData<unsigned long,DialogInfo>::HashTableData<unsigned long,DialogInfo>(v4, _key, _data);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v6) )
  {
    result = 1;
  }
  else
  {
    if ( v6 )
    {
      PropertyCollection::~PropertyCollection((PropertyCollection *)(v6 + 8));
      operator delete((void *)v6);
    }
    result = 0;
  }
  return result;
}

//----- (00477870) --------------------------------------------------------  // acclient.c:180735
char __thiscall List<DialogInfo>::push_back(List<DialogInfo> *this, DialogInfo *val)
{
  List<DialogInfo> *v2; // esi@1
  ListNode<DialogInfo> *v3; // eax@1
  int v4; // eax@2
  char result; // al@3
  ListNode<DialogInfo> *v6; // ecx@6

  v2 = this;
  v3 = (ListNode<DialogInfo> *)operator new(0x8Cu);
  if ( v3 && (ListNode<DialogInfo>::ListNode<DialogInfo>(v3, val), v4) )
  {
    if ( v2->_head )
    {
      v6 = v2->_tail;
      v6->next = (ListNode<DialogInfo> *)v4;
      *(_DWORD *)(v4 + 136) = v6;
      v2->_tail = (ListNode<DialogInfo> *)v4;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (ListNode<DialogInfo> *)v4;
      v2->_tail = (ListNode<DialogInfo> *)v4;
      ++v2->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004778D0) --------------------------------------------------------  // acclient.c:180772
List<DialogInfo> *__thiscall List<DialogInfo>::operator=(List<DialogInfo> *this, int a2)
{
  List<DialogInfo> *v2; // esi@1
  int i; // edi@2
  ListNode<DialogInfo> *v4; // eax@3
  int v5; // eax@4
  ListNode<DialogInfo> *v6; // ecx@7

  v2 = this;
  if ( this != (List<DialogInfo> *)a2 )
  {
    List<DialogInfo>::flush(this);
    for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 132) )
    {
      v4 = (ListNode<DialogInfo> *)operator new(0x8Cu);
      if ( v4 )
      {
        ListNode<DialogInfo>::ListNode<DialogInfo>(v4, (DialogInfo *)i);
        if ( v5 )
        {
          if ( v2->_head )
          {
            v6 = v2->_tail;
            v6->next = (ListNode<DialogInfo> *)v5;
            *(_DWORD *)(v5 + 136) = v6;
          }
          else
          {
            v2->_head = (ListNode<DialogInfo> *)v5;
          }
          v2->_tail = (ListNode<DialogInfo> *)v5;
          ++v2->_num_elements;
        }
      }
      if ( !i )
        break;
    }
  }
  return v2;
}

//----- (00477950) --------------------------------------------------------  // acclient.c:180814
void __cdecl DialogFactory::Reset()
{
  ListNode<DialogInfo> *v0; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v1; // ecx@4
  HashTableData<unsigned long,HeritageGroup_CG> **v2; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // edi@7
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // esi@9
  HashTableData<unsigned long,List<DialogInfo> > **v5; // ecx@14
  HashTableData<unsigned long,List<DialogInfo> > **v6; // eax@14
  HashTableData<unsigned long,List<DialogInfo> > *v7; // edi@17
  HashTableData<unsigned long,List<DialogInfo> > **v8; // ebx@19
  ListNode<DialogInfo> *v9; // esi@20
  List<DialogInfo> queue; // [sp+Ch] [bp-10h]@20

  v0 = DialogFactory::s_listNonQueuedInfos._head;
  if ( DialogFactory::s_listNonQueuedInfos._head )
  {
    do
    {
      DialogFactory::DialogDone(&v0->data);
      if ( !v0 )
        break;
      v0 = v0->next;
    }
    while ( v0 );
  }
  List<DialogInfo>::flush(&DialogFactory::s_listNonQueuedInfos);
  v1 = &stru_818E2C.m_buckets[stru_818E2C.m_numBuckets];
  v2 = stru_818E2C.m_firstInterestingBucket;
  if ( stru_818E2C.m_firstInterestingBucket == v1 )
  {
LABEL_7:
    v2 = 0;
    v3 = 0;
  }
  else
  {
    while ( !*v2 )
    {
      ++v2;
      stru_818E2C.m_firstInterestingBucket = v2;
      if ( v2 == v1 )
        goto LABEL_7;
    }
    v3 = *v2;
  }
  v4 = v2;
  if ( v3 )
  {
    do
    {
LABEL_10:
      DialogFactory::DialogDone((DialogInfo *)&v3->m_data);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &stru_818E2C.m_buckets[stru_818E2C.m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_10;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *)&stru_818E2C);
  v5 = &DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets];
  v6 = DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket;
  if ( DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket == v5 )
  {
LABEL_17:
    v6 = 0;
    v7 = 0;
  }
  else
  {
    while ( !*v6 )
    {
      ++v6;
      DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket = v6;
      if ( v6 == v5 )
        goto LABEL_17;
    }
    v7 = *v6;
  }
  v8 = v6;
  if ( v7 )
  {
    do
    {
LABEL_20:
      queue.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
      queue._head = 0;
      queue._tail = 0;
      queue._num_elements = 0;
      List<DialogInfo>::operator=(&queue, (int)&v7->m_data);
      v9 = queue._head;
      if ( queue._head )
      {
        do
        {
          DialogFactory::DialogDone(&v9->data);
          if ( !v9 )
            break;
          v9 = v9->next;
        }
        while ( v9 );
      }
      queue.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
      List<DialogInfo>::flush(&queue);
      v7 = v7->m_hashNext;
    }
    while ( v7 );
    while ( 1 )
    {
      ++v8;
      if ( v8 == &DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v8 )
      {
        v7 = *v8;
        if ( *v8 )
          goto LABEL_20;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::delete_contents(&DialogFactory::s_hashDialogQueues.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_818EA4);
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (00477AD0) --------------------------------------------------------  // acclient.c:180952
void __usercall DialogFactory::CreateDialog_(int a1@<esi>, DialogInfo *info, unsigned int queueID)
{
  ListNode<DialogInfo> *v3; // esi@3
  PropertyCollection *v4; // ecx@3
  HashTableData<unsigned long,BaseProperty> *v5; // eax@8
  int v6; // eax@16
  Dialog *v7; // ecx@24
  int v8; // [sp+10h] [bp-11Ch]@2
  BaseProperty p; // [sp+18h] [bp-114h]@8
  unsigned int type; // [sp+20h] [bp-10Ch]@8
  PropertyCollection v11; // [sp+24h] [bp-108h]@3
  int v12; // [sp+9Ch] [bp-90h]@3
  int v13; // [sp+A0h] [bp-8Ch]@3
  int v14; // [sp+A4h] [bp-88h]@3
  PropertyCollection v15; // [sp+A8h] [bp-84h]@5
  int v16; // [sp+120h] [bp-Ch]@5
  int v17; // [sp+124h] [bp-8h]@5
  int v18; // [sp+128h] [bp-4h]@5

  if ( !queueID )
    return;
  v8 = a1;
  if ( queueID == 1 )
  {
    PropertyCollection::PropertyCollection(&v11);
    v12 = 0;
    v13 = 0;
    v14 = 0;
    List<DialogInfo>::push_back(&DialogFactory::s_listNonQueuedInfos, (DialogInfo *)&v11);
    v3 = DialogFactory::s_listNonQueuedInfos._tail;
    v4 = &v11;
  }
  else
  {
    v3 = (ListNode<DialogInfo> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                   &DialogFactory::s_hashCurInfos,
                                   &queueID);
    if ( v3 )
      goto LABEL_7;
    PropertyCollection::PropertyCollection(&v15);
    v16 = 0;
    v17 = 0;
    v18 = 0;
    HashTable<unsigned long,DialogInfo,0>::add(
      (HashTable<unsigned long,DialogInfo,0> *)&DialogFactory::s_hashCurInfos,
      &queueID,
      (DialogInfo *)&v15);
    v3 = (ListNode<DialogInfo> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                   &DialogFactory::s_hashCurInfos,
                                   &queueID);
    v4 = &v15;
  }
  PropertyCollection::~PropertyCollection(v4);
LABEL_7:
  if ( !v3->data.pointer )
  {
    PropertyCollection::operator=(v3, info);
    v3->data.pointer = info->pointer;
    v3->data.parent = info->parent;
    v3->data.context = info->context;
    type = 0;
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    v5 = v3->data.data.m_hashProperties.m_intrusiveTable.m_buckets[0x8E
                                                                 % v3->data.data.m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( v5 )
    {
      while ( v5->m_hashKey != 142 )
      {
        v5 = v5->m_hashNext;
        if ( !v5 )
          goto LABEL_15;
      }
      if ( v5 )
      {
        BaseProperty::operator=(&p, (int)&v5->m_data);
        if ( p.m_pcPropertyValue )
          ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&type);
      }
    }
LABEL_15:
    switch ( type )
    {
      case 1u:
        v6 = ((int (__stdcall *)(signed int, signed int, int))v3->data.parent->vfptr[2].__vecDelDtor)(2, 21, v8);
        goto LABEL_23;
      case 2u:
        v6 = ((int (__stdcall *)(signed int, signed int, int))v3->data.parent->vfptr[2].__vecDelDtor)(2, 49, v8);
        goto LABEL_23;
      case 3u:
        v6 = ((int (__stdcall *)(signed int, signed int, int))v3->data.parent->vfptr[2].__vecDelDtor)(2, 36, v8);
        goto LABEL_23;
      case 6u:
        v6 = ((int (__stdcall *)(_DWORD, signed int, _DWORD))v3->data.parent->vfptr[2].__vecDelDtor)(2, 27, v8);
        goto LABEL_23;
      case 7u:
        v6 = ((int (__stdcall *)(_DWORD, signed int, _DWORD))v3->data.parent->vfptr[2].__vecDelDtor)(2, 31, v8);
        goto LABEL_23;
      case 4u:
        v6 = ((int (__stdcall *)(_DWORD, signed int, _DWORD))v3->data.parent->vfptr[2].__vecDelDtor)(2, 40, v8);
        goto LABEL_23;
      case 5u:
        v6 = ((int (__stdcall *)(_DWORD, signed int, _DWORD))v3->data.parent->vfptr[2].__vecDelDtor)(2, 44, v8);
LABEL_23:
        v3->data.pointer = (Dialog *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 148))(v6);
        break;
      default:
        break;
    }
    v7 = v3->data.pointer;
    if ( v7 )
    {
      ((void (__stdcall *)(unsigned int))v7->vfptr[26].__vecDelDtor)(v3->data.context);
      ((void (__stdcall *)(ListNode<DialogInfo> *))v3->data.pointer->vfptr[26].OnAction)(v3);
      UIRegion::BringToFront((UIRegion *)&v3->data.pointer->vfptr);
      DialogFactory::UpdatePendingDialogDisplay_();
      ECM_UI::SendNotice_OpenDialog(v3->data.context);
    }
    BaseProperty::~BaseProperty(&p);
  }
}
// 477AD0: could not find valid save-restore pair for esi

//----- (00477D30) --------------------------------------------------------  // acclient.c:181076
void __cdecl DialogFactory::OpenNextDialog(unsigned int i_queueID)
{
  unsigned int v1; // edi@1
  HashTableData<unsigned long,List<DialogInfo> > *v2; // eax@2
  int v3; // esi@7
  PropertyCollection v4; // [sp+4h] [bp-84h]@8
  int v5; // [sp+7Ch] [bp-Ch]@8
  int v6; // [sp+80h] [bp-8h]@8
  int v7; // [sp+84h] [bp-4h]@8

  v1 = i_queueID;
  if ( i_queueID != 1 )
  {
    v2 = DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[i_queueID
                                                                    % DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets];
    if ( v2 )
    {
      while ( v2->m_hashKey != i_queueID )
      {
        v2 = v2->m_hashNext;
        if ( !v2 )
          return;
      }
      if ( v2 )
      {
        v3 = (int)&v2->m_data;
        if ( v2 != (HashTableData<unsigned long,List<DialogInfo> > *)-8 )
        {
          PropertyCollection::PropertyCollection(&v4);
          v5 = 0;
          v6 = 0;
          v7 = 0;
          if ( List<DialogInfo>::pop_front((List<DialogInfo> *)v3, (DialogInfo *)&v4) && !v5 )
          {
            DialogFactory::CreateDialog_(v3, (DialogInfo *)&v4, v1);
            if ( !*(_DWORD *)(v3 + 4) )
              HashTable<unsigned long,List<DialogInfo>,0>::erase(&DialogFactory::s_hashDialogQueues, &i_queueID);
          }
          PropertyCollection::~PropertyCollection(&v4);
        }
      }
    }
  }
}

//----- (00477E10) --------------------------------------------------------  // acclient.c:181122
char __thiscall HashTable<unsigned long,List<DialogInfo>,0>::add(HashTable<unsigned long,List<DialogInfo>,0> *this, const unsigned int *_key, List<DialogInfo> *_data)
{
  HashTable<unsigned long,List<DialogInfo>,0> *v3; // ebx@1
  void *v4; // esi@1
  int v5; // ecx@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0x18u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    v5 = (int)((char *)v4 + 8);
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v5 = List<DialogInfo>::vftable;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 12) = 0;
    List<DialogInfo>::operator=((List<DialogInfo> *)((char *)v4 + 8), (int)_data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      *((_DWORD *)v4 + 2) = List<DialogInfo>::vftable;
      List<DialogInfo>::flush((List<DialogInfo> *)((char *)v4 + 8));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (00477E90) --------------------------------------------------------  // acclient.c:181167
unsigned __int32 __cdecl DialogFactory::MakeDialog(UIFramework *i_pcParent, PropertyCollection *i_rcData)
{
  unsigned int v2; // edx@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  unsigned int v5; // edx@8
  HashTableData<unsigned long,BaseProperty> **v6; // ecx@8
  HashTableData<unsigned long,BaseProperty> *v7; // eax@8
  unsigned int v8; // ecx@11
  HashTableData<unsigned long,List<DialogInfo> > *v9; // eax@11
  int v10; // esi@21
  unsigned int *v11; // eax@22
  unsigned __int32 v12; // esi@29
  BasePropertyDesc *v13; // ecx@30
  unsigned int v14; // edx@30
  BasePropertyValue *v15; // ecx@34
  unsigned int v16; // edx@34
  int v18; // [sp+8h] [bp-12Ch]@1
  unsigned int queueID; // [sp+Ch] [bp-128h]@8
  BaseProperty p; // [sp+10h] [bp-124h]@1
  UIElement *pDialog; // [sp+18h] [bp-11Ch]@26
  List<DialogInfo> _data; // [sp+1Ch] [bp-118h]@22
  PropertyCollection v23; // [sp+2Ch] [bp-108h]@1
  int v24; // [sp+A4h] [bp-90h]@1
  UIFramework *v25; // [sp+A8h] [bp-8Ch]@1
  unsigned __int32 v26; // [sp+ACh] [bp-88h]@1
  DialogInfo curInfo; // [sp+B0h] [bp-84h]@11

  ++DialogFactory::s_globalContext;
  PropertyCollection::PropertyCollection(&v23);
  v24 = 0;
  v26 = 0;
  PropertyCollection::operator=(&v23, i_rcData);
  v25 = i_pcParent;
  v2 = 0x8D % i_rcData->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v3 = i_rcData->m_hashProperties.m_intrusiveTable.m_buckets;
  v24 = 0;
  v26 = DialogFactory::s_globalContext;
  BYTE3(v18) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v4 = v3[v2];
  if ( v4 )
  {
    while ( v4->m_hashKey != 141 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        goto LABEL_8;
    }
    if ( v4 )
    {
      BaseProperty::operator=(&p, (int)&v4->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(char *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v18 + 3);
    }
  }
LABEL_8:
  v5 = 0xC3 % i_rcData->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v6 = i_rcData->m_hashProperties.m_intrusiveTable.m_buckets;
  queueID = 2;
  v7 = v6[v5];
  if ( !v7 )
    goto LABEL_11;
  while ( v7->m_hashKey != 195 )
  {
    v7 = v7->m_hashNext;
    if ( !v7 )
      goto LABEL_11;
  }
  if ( !v7 )
    goto LABEL_11;
  BaseProperty::operator=(&p, (int)&v7->m_data);
  if ( p.m_pcPropertyValue )
    ((void (__stdcall *)(unsigned int *))p.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&queueID);
  if ( queueID == 1 )
  {
    DialogFactory::CreateDialog_((int)i_rcData, (DialogInfo *)&v23, 1u);
  }
  else
  {
LABEL_11:
    PropertyCollection::PropertyCollection(&curInfo.data);
    curInfo.pointer = 0;
    curInfo.parent = 0;
    curInfo.context = 0;
    HashTable<unsigned long,DialogInfo,0>::find(
      (HashTable<unsigned long,DialogInfo,0> *)&DialogFactory::s_hashCurInfos,
      &queueID,
      &curInfo);
    v8 = queueID;
    v9 = DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[queueID
                                                                    % DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets];
    if ( !v9 )
      goto LABEL_22;
    while ( v9->m_hashKey != queueID )
    {
      v9 = v9->m_hashNext;
      if ( !v9 )
        goto LABEL_22;
    }
    if ( !v9 || (v10 = (int)&v9->m_data, v9 == (HashTableData<unsigned long,List<DialogInfo> > *)-8) )
    {
LABEL_22:
      _data.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
      _data._head = 0;
      _data._tail = 0;
      _data._num_elements = 0;
      HashTable<unsigned long,List<DialogInfo>,0>::add(&DialogFactory::s_hashDialogQueues, &queueID, &_data);
      _data.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
      List<DialogInfo>::flush(&_data);
      v11 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
              (HashTable<unsigned long,unsigned long,0> *)&DialogFactory::s_hashDialogQueues,
              &queueID);
      v8 = queueID;
      v10 = (int)v11;
    }
    if ( curInfo.pointer )
    {
      if ( BYTE3(v18) )
      {
        pDialog = (UIElement *)&curInfo.pointer->vfptr;
        ((void (__stdcall *)(UIElement **))curInfo.parent->vfptr[2].OnLoseFocus)(&pDialog);
        List<DialogInfo>::insert((List<DialogInfo> *)v10, *(ListNode<DialogInfo> **)(v10 + 4), &curInfo);
        DialogFactory::CreateDialog_(v10, (DialogInfo *)&v23, queueID);
      }
      else
      {
        List<DialogInfo>::push_back((List<DialogInfo> *)v10, (DialogInfo *)&v23);
        DialogFactory::UpdatePendingDialogDisplay_();
      }
    }
    else
    {
      DialogFactory::CreateDialog_(v10, (DialogInfo *)&v23, v8);
    }
    PropertyCollection::~PropertyCollection(&curInfo.data);
  }
  v12 = DialogFactory::s_globalContext;
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v13 = p.m_pcPropertyDesc;
    v14 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v14;
    if ( !v14 )
      ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v15 = p.m_pcPropertyValue;
    v16 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v16;
    if ( !v16 )
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&v23);
  return v12;
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);
// 83D718: using guessed type unsigned __int32 DialogFactory::s_globalContext;

//----- (00478160) --------------------------------------------------------  // acclient.c:181331
void __cdecl DialogFactory::CloseDialog(const unsigned int context)
{
  ListNode<DialogInfo> *v1; // esi@2
  HashTableData<unsigned long,HeritageGroup_CG> **v2; // ecx@5
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // eax@5
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@8
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@11
  HashTableData<unsigned long,List<DialogInfo> > **v6; // ecx@17
  HashTableData<unsigned long,List<DialogInfo> > **v7; // eax@17
  HashTableData<unsigned long,List<DialogInfo> > *v8; // edi@20
  unsigned int v9; // ebp@21
  HashTableData<unsigned long,HeritageGroup_CG> **v10; // eax@21
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // eax@24
  HashTableData<unsigned long,HeritageGroup_CG> *v12; // ecx@25
  HashTableData<unsigned long,List<DialogInfo> > **v13; // ebx@31
  ListNode<DialogInfo> *v14; // esi@32
  List<DialogInfo> queue; // [sp+4h] [bp-94h]@32
  DialogInfo info; // [sp+14h] [bp-84h]@21

  if ( context )
  {
    v1 = DialogFactory::s_listNonQueuedInfos._head;
    if ( DialogFactory::s_listNonQueuedInfos._head )
    {
      while ( context != v1->data.context )
      {
        v1 = v1->next;
        if ( !v1 )
          goto LABEL_5;
      }
      DialogFactory::DialogDone(&v1->data);
      List<DialogInfo>::remove(&DialogFactory::s_listNonQueuedInfos, v1);
    }
    else
    {
LABEL_5:
      v2 = &stru_818E2C.m_buckets[stru_818E2C.m_numBuckets];
      v3 = stru_818E2C.m_firstInterestingBucket;
      if ( stru_818E2C.m_firstInterestingBucket == v2 )
      {
LABEL_8:
        v3 = 0;
        v4 = 0;
      }
      else
      {
        while ( !*v3 )
        {
          ++v3;
          stru_818E2C.m_firstInterestingBucket = v3;
          if ( v3 == v2 )
            goto LABEL_8;
        }
        v4 = *v3;
      }
      v5 = v3;
      if ( v4 )
      {
        do
        {
LABEL_12:
          if ( (HashTableData<unsigned long,Sex_CG> *)context == v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[11] )
          {
            info.data.vfptr = (PropertyCollectionVtbl *)&PropertyCollection::vftable;
            IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
              &info.data.m_hashProperties.m_intrusiveTable,
              0);
            info.data.m_hashProperties.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
            PropertyCollection::operator=(&info, &v4->m_data);
            info.pointer = (Dialog *)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[9];
            info.parent = (UIFramework *)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[10];
            info.context = (unsigned int)&v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[11]->m_hashKey;
            v9 = v4->m_hashKey;
            v10 = v5;
            if ( !v4->m_hashNext )
            {
              do
                ++v10;
              while ( v10 != &stru_818E2C.m_buckets[stru_818E2C.m_numBuckets] && !*v10 );
            }
            v11 = *v5;
            if ( *v5 == v4 )
              goto LABEL_43;
            do
            {
              v12 = v11;
              v11 = v11->m_hashNext;
            }
            while ( v11 != v4 );
            if ( v12 )
              v12->m_hashNext = v11->m_hashNext;
            else
LABEL_43:
              *v5 = v11->m_hashNext;
            --stru_818E2C.m_numElements;
            PropertyCollection::~PropertyCollection((PropertyCollection *)&v4->m_data);
            operator delete(v4);
            DialogFactory::DialogDone(&info);
            DialogFactory::OpenNextDialog(v9);
            PropertyCollection::~PropertyCollection(&info.data);
            return;
          }
          v4 = v4->m_hashNext;
        }
        while ( v4 );
        while ( 1 )
        {
          ++v5;
          if ( v5 == v2 )
            break;
          if ( *v5 )
          {
            v4 = *v5;
            if ( *v5 )
              goto LABEL_12;
            break;
          }
        }
      }
      v6 = &DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets];
      v7 = DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket;
      if ( DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket == v6 )
      {
LABEL_20:
        v7 = 0;
        v8 = 0;
      }
      else
      {
        while ( !*v7 )
        {
          ++v7;
          DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket = v7;
          if ( v7 == v6 )
            goto LABEL_20;
        }
        v8 = *v7;
      }
      v13 = v7;
      if ( v8 )
      {
LABEL_32:
        while ( 1 )
        {
          queue._head = 0;
          queue._tail = 0;
          queue._num_elements = 0;
          queue.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
          List<DialogInfo>::operator=(&queue, (int)&v8->m_data);
          v14 = queue._head;
          if ( queue._head )
            break;
LABEL_35:
          queue.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
          List<DialogInfo>::flush(&queue);
          v8 = v8->m_hashNext;
          if ( !v8 )
          {
            while ( 1 )
            {
              ++v13;
              if ( v13 == &DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets[DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets] )
                return;
              if ( *v13 )
              {
                v8 = *v13;
                if ( *v13 )
                  goto LABEL_32;
                return;
              }
            }
          }
        }
        while ( context != v14->data.context )
        {
          v14 = v14->next;
          if ( !v14 )
            goto LABEL_35;
        }
        DialogFactory::DialogDone(&v14->data);
        List<DialogInfo>::remove(&queue, v14);
        DialogFactory::UpdatePendingDialogDisplay_();
        queue.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
        List<DialogInfo>::flush(&queue);
      }
    }
  }
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 79C058: using guessed type int (__thiscall *PropertyCollection::vftable)(void *, char);
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (00478410) --------------------------------------------------------  // acclient.c:181524
unsigned __int32 __cdecl DialogFactory::MakeDialogInCurrentUI(PropertyCollection *i_rcData)
{
  return DialogFactory::MakeDialog((UIFramework *)&UIFlow::m_instance->_curUI->vfptr, i_rcData);
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (00478430) --------------------------------------------------------  // acclient.c:181531
unsigned __int32 __cdecl DialogFactory::MakeCallbackDialogInCurrentUI(PropertyCollection *i_rcData, void (__cdecl *pFunc)(PropertyCollection *))
{
  unsigned int v2; // ecx@0
  unsigned __int32 result; // eax@1
  unsigned __int32 v4; // esi@1
  unsigned int uiContextID; // [sp+0h] [bp-4h]@1

  uiContextID = v2;
  result = DialogFactory::MakeDialog((UIFramework *)&UIFlow::m_instance->_curUI->vfptr, i_rcData);
  v4 = result;
  uiContextID = result;
  if ( result )
  {
    HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
      (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&DialogFactory::s_hashCallbacks,
      &uiContextID,
      (RenderVertexStreamD3D *const *)&pFunc);
    result = v4;
  }
  return result;
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (006EC3B0) --------------------------------------------------------  // acclient.c:768076
int _E73_78()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>(
    &DialogFactory::s_hashDialogQueues.m_intrusiveTable,
    0x17u);
  return atexit(_E74_59);
}

//----- (006EC3D0) --------------------------------------------------------  // acclient.c:768085
int _E76_45()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *)&stru_818E2C,
    0x17u);
  return atexit(_E77_73);
}

//----- (006EC3F0) --------------------------------------------------------  // acclient.c:768094
int _E79_38()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl*)(PropertyCollection const &)> *,0> *)&stru_818EA4,
    0x17u);
  return atexit(_E80_38);
}

//----- (006EC410) --------------------------------------------------------  // acclient.c:768103
int _E82_26()
{
  return atexit(_E83_26);
}

//----- (006EC420) --------------------------------------------------------  // acclient.c:768109
int _E1_84()
{
  return atexit(_E2_84);
}

//----- (0075EC90) --------------------------------------------------------  // acclient.c:886995
void __cdecl _E83_26()
{
  DialogFactory::s_listNonQueuedInfos.vfptr = (List<DialogInfo>Vtbl *)List<DialogInfo>::vftable;
  List<DialogInfo>::flush(&DialogFactory::s_listNonQueuedInfos);
}
// 79E080: using guessed type int (__thiscall *List<DialogInfo>::vftable[8])(void *, char);

//----- (0075ECB0) --------------------------------------------------------  // acclient.c:887003
void __cdecl _E74_59()
{
  DialogFactory::s_hashDialogQueues.vfptr = (HashTable<unsigned long,List<DialogInfo>,0>Vtbl *)HashTable<unsigned long,List<DialogInfo>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::delete_contents(&DialogFactory::s_hashDialogQueues.m_intrusiveTable);
  DialogFactory::s_hashDialogQueues.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable;
  if ( (HashTableData<unsigned long,List<DialogInfo> > **)DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets != DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets);
  DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_buckets = 0;
  DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_firstInterestingBucket = 0;
  DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numBuckets = 0;
  DialogFactory::s_hashDialogQueues.m_intrusiveTable.m_numElements = 0;
}
// 79E084: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable[7])(void *, char);
// 79E090: using guessed type int (__thiscall *HashTable<unsigned long,List<DialogInfo>,0>::vftable[4])(void *, char);

//----- (0075ED00) --------------------------------------------------------  // acclient.c:887019
void __cdecl _E77_73()
{
  DialogFactory::s_hashCurInfos.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,DialogInfo,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0> *)&stru_818E2C);
  stru_818E2C.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable;
  if ( (HashTableData<unsigned long,HeritageGroup_CG> **)stru_818E2C.m_buckets != stru_818E2C.m_aInplaceBuckets )
    operator delete[](stru_818E2C.m_buckets);
  stru_818E2C.m_buckets = 0;
  stru_818E2C.m_firstInterestingBucket = 0;
  stru_818E2C.m_numBuckets = 0;
  stru_818E2C.m_numElements = 0;
}
// 79E088: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable[6])(void *, char);
// 79E094: using guessed type int (__thiscall *HashTable<unsigned long,DialogInfo,0>::vftable[3])(void *, char);

//----- (0075ED50) --------------------------------------------------------  // acclient.c:887035
void __cdecl _E80_38()
{
  DialogFactory::s_hashCallbacks.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&stru_818EA4);
  stru_818EA4.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable;
  if ( (HashSetData<IDClass<_tagDataID,32,0> > **)stru_818EA4.m_buckets != stru_818EA4.m_aInplaceBuckets )
    operator delete[](stru_818EA4.m_buckets);
  stru_818EA4.m_buckets = 0;
  stru_818EA4.m_firstInterestingBucket = 0;
  stru_818EA4.m_numBuckets = 0;
  stru_818EA4.m_numElements = 0;
}
// 79E08C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable[5])(void *, char);
// 79E098: using guessed type int (__thiscall *HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable[2])(void *, char);

