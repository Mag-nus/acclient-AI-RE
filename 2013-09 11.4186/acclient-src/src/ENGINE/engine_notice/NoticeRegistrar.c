/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : NoticeRegistrar
   Object     : ENGINE\engine_notice\NoticeRegistrar.obj
   Functions  : 15
   Addresses  : 00431350 - 0043C980 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00431350) --------------------------------------------------------  // acclient.c:110502
char __thiscall List<NoticeHandler *>::remove(List<NoticeHandler *> *this, ListNode<NoticeHandler *> *node)
{
  ListNode<NoticeHandler *> *v2; // edx@1
  List<NoticeHandler *> *v3; // esi@1
  ListNode<NoticeHandler *> *v4; // ecx@2
  ListNode<NoticeHandler *> *v6; // ecx@5

  v2 = 0;
  v3 = this;
  if ( !node )
    return 0;
  v4 = this->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v3->_tail = node->prev;
      goto LABEL_11;
    }
    v2 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v3->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v2;
    goto LABEL_11;
  }
  v3->_tail = 0;
LABEL_11:
  operator delete(node);
  --v3->_num_elements;
  return 1;
}

//----- (0043C480) --------------------------------------------------------  // acclient.c:121091
void __thiscall NoticeRegistrar::NoticeRegistrar(NoticeRegistrar *this)
{
  this->vfptr = (NoticeRegistrarVtbl *)&NoticeRegistrar::vftable;
  this->m_handlers = 0;
}
// 798FD8: using guessed type int (__thiscall *NoticeRegistrar::vftable)(void *, char);

//----- (0043C490) --------------------------------------------------------  // acclient.c:121099
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *v1; // esi@1
  HashTableData<unsigned long,List<NoticeHandler *> *> **v2; // eax@1

  v1 = this;
  v2 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable;
  if ( v2 != this->m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_buckets = 0;
  v1->m_firstInterestingBucket = 0;
  v1->m_numBuckets = 0;
  v1->m_numElements = 0;
}
// 798FF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable[2])(void *, char);

//----- (0043C4C0) --------------------------------------------------------  // acclient.c:121117
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *v2; // esi@1
  HashTableData<unsigned long,List<NoticeHandler *> *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable;
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
// 798FF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable[2])(void *, char);

//----- (0043C500) --------------------------------------------------------  // acclient.c:121138
void __thiscall NoticeRegistrar::DestroyHandlers(NoticeRegistrar *this)
{
  NoticeRegistrar *v1; // ebp@1
  HashTable<unsigned long,List<NoticeHandler *> *,0> *v2; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@2
  HeritageGroup_CGVtbl *v7; // ecx@3
  HashTable<unsigned long,List<NoticeHandler *> *,0> *v8; // ecx@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+4h] [bp-Ch]@2

  v1 = this;
  v2 = this->m_handlers;
  if ( v2 )
  {
    v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_intrusiveTable,
           &result);
    v4 = v3->m_currElement;
    v5 = v3->m_currHashTable;
    v6 = v3->m_currBucket;
    if ( v4 )
    {
      do
      {
LABEL_3:
        v7 = v4->m_data.vfptr;
        if ( v7 )
          (*(void (__stdcall **)(_DWORD))v7->Serialize)(1);
        v4 = v4->m_hashNext;
      }
      while ( v4 );
      while ( 1 )
      {
        ++v6;
        if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
          break;
        if ( *v6 )
        {
          v4 = *v6;
          if ( *v6 )
            goto LABEL_3;
          break;
        }
      }
    }
    v8 = v1->m_handlers;
    if ( v8 )
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->m_handlers = 0;
  }
}

//----- (0043C5C0) --------------------------------------------------------  // acclient.c:121216
List<NoticeHandler *> *__thiscall List<NoticeHandler *>::vector_deleting_destructor(List<NoticeHandler *> *this, unsigned int a2)
{
  List<NoticeHandler *> *v2; // esi@1
  NoticeHandler *retval; // [sp+0h] [bp-4h]@1

  retval = (NoticeHandler *)this;
  v2 = this;
  this->vfptr = (List<NoticeHandler *>Vtbl *)List<NoticeHandler *>::vftable;
  while ( v2->_head )
    List<NoticeHandler *>::pop_front(v2, &retval);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798FEC: using guessed type int (__thiscall *List<NoticeHandler *>::vftable[3])(void *, char);

//----- (0043C600) --------------------------------------------------------  // acclient.c:121233
char __thiscall List<NoticeHandler *>::pop_front(List<NoticeHandler *> *this, NoticeHandler **retval)
{
  List<NoticeHandler *> *v2; // esi@1
  ListNode<NoticeHandler *> *v3; // ecx@1
  char result; // al@2
  ListNode<NoticeHandler *> *v5; // eax@3

  v2 = this;
  v3 = this->_head;
  if ( v3 )
  {
    v5 = v3->next;
    v2->_head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      v2->_tail = 0;
    *retval = v3->data;
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

//----- (0043C650) --------------------------------------------------------  // acclient.c:121263
void __thiscall NoticeRegistrar::~NoticeRegistrar(NoticeRegistrar *this)
{
  this->vfptr = (NoticeRegistrarVtbl *)&NoticeRegistrar::vftable;
  NoticeRegistrar::DestroyHandlers(this);
}
// 798FD8: using guessed type int (__thiscall *NoticeRegistrar::vftable)(void *, char);

//----- (0043C660) --------------------------------------------------------  // acclient.c:121271
char __thiscall NoticeRegistrar::UnRegisterNoticeHandler(NoticeRegistrar *this, unsigned int i_notice, NoticeHandler *i_pcHandler)
{
  int v3; // eax@1
  int v4; // edx@2

  v3 = ((int (__stdcall *)(unsigned int))this->vfptr->GetNoticeHandlers)(i_notice);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 4);
    if ( v4 )
    {
      while ( *(NoticeHandler **)v4 != i_pcHandler )
      {
        v4 = *(_DWORD *)(v4 + 4);
        if ( !v4 )
          return 1;
      }
      List<NoticeHandler *>::remove((List<NoticeHandler *> *)v3, (ListNode<NoticeHandler *> *)v4);
    }
  }
  return 1;
}

//----- (0043C6A0) --------------------------------------------------------  // acclient.c:121295
char __thiscall NoticeRegistrar::UnRegisterAllNoticeHandlers(NoticeRegistrar *this, NoticeHandler *i_pcHandler)
{
  HashTable<unsigned long,List<NoticeHandler *> *,0> *v2; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@2
  HeritageGroup_CGVtbl *v7; // ecx@3
  void (__thiscall *v8)(HeritageGroup_CG *, Archive *); // eax@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+4h] [bp-Ch]@2

  v2 = this->m_handlers;
  if ( v2 )
  {
    v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_intrusiveTable,
           &result);
    v4 = v3->m_currElement;
    v5 = v3->m_currHashTable;
    v6 = v3->m_currBucket;
    if ( v4 )
    {
      do
      {
LABEL_3:
        v7 = v4->m_data.vfptr;
        v8 = v7[1].Serialize;
        if ( v8 )
        {
          while ( *(NoticeHandler **)v8 != i_pcHandler )
          {
            v8 = (void (__thiscall *)(HeritageGroup_CG *, Archive *))*((_DWORD *)v8 + 1);
            if ( !v8 )
              goto LABEL_8;
          }
          List<NoticeHandler *>::remove((List<NoticeHandler *> *)v7, (ListNode<NoticeHandler *> *)v8);
        }
LABEL_8:
        v4 = v4->m_hashNext;
      }
      while ( v4 );
      while ( 1 )
      {
        ++v6;
        if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
          break;
        if ( *v6 )
        {
          v4 = *v6;
          if ( *v6 )
            goto LABEL_3;
          return 1;
        }
      }
    }
  }
  return 1;
}

//----- (0043C730) --------------------------------------------------------  // acclient.c:121355
unsigned int __thiscall NoticeRegistrar::GetNoticeHandlers(NoticeRegistrar *this, unsigned int i_notice)
{
  HashTable<unsigned long,unsigned long,0> *v2; // ecx@1
  unsigned int *v3; // eax@2
  unsigned int result; // eax@3

  v2 = (HashTable<unsigned long,unsigned long,0> *)this->m_handlers;
  if ( v2 && (v3 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(v2, &i_notice)) != 0 )
    result = *v3;
  else
    result = 0;
  return result;
}

//----- (0043C750) --------------------------------------------------------  // acclient.c:121370
NoticeRegistrar *__thiscall NoticeRegistrar::vector_deleting_destructor(NoticeRegistrar *this, unsigned int a2)
{
  NoticeRegistrar *v2; // esi@1

  v2 = this;
  this->vfptr = (NoticeRegistrarVtbl *)&NoticeRegistrar::vftable;
  NoticeRegistrar::DestroyHandlers(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798FD8: using guessed type int (__thiscall *NoticeRegistrar::vftable)(void *, char);

//----- (0043C780) --------------------------------------------------------  // acclient.c:121384
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,List<NoticeHandler *> *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,List<NoticeHandler *> *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 798FF0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable[2])(void *, char);

//----- (0043C870) --------------------------------------------------------  // acclient.c:121453
bool __thiscall NoticeRegistrar::RegisterNoticeHandler(NoticeRegistrar *this, unsigned int i_notice, NoticeHandler *i_pcHandler)
{
  NoticeRegistrar *v3; // edi@1
  void *v4; // eax@2
  HashTable<unsigned long,List<NoticeHandler *> *,0> *v5; // esi@2
  int v6; // eax@6
  int v7; // esi@6
  void *v8; // eax@7
  bool result; // al@10
  int v10; // eax@11
  NoticeHandler *v11; // edi@11
  void *v12; // eax@14
  int v13; // ecx@17
  List<NoticeHandler *> *list; // [sp+4h] [bp-4h]@1

  list = (List<NoticeHandler *> *)this;
  v3 = this;
  if ( this->m_handlers
    || ((v4 = operator new(0x74u), (v5 = (HashTable<unsigned long,List<NoticeHandler *> *,0> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &HashTable<unsigned long,List<NoticeHandler *> *,0>::vftable, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *)((char *)v4 + 4), 0x17u)),
        (v3->m_handlers = v5) != 0) )
  {
    v6 = (int)v3->vfptr->GetNoticeHandlers(v3, i_notice);
    v7 = v6;
    if ( v6 )
    {
      v10 = *(_DWORD *)(v6 + 4);
      v11 = i_pcHandler;
      if ( v10 )
      {
        while ( *(NoticeHandler **)v10 != i_pcHandler )
        {
          v10 = *(_DWORD *)(v10 + 4);
          if ( !v10 )
            goto LABEL_14;
        }
      }
      else
      {
LABEL_14:
        v12 = operator new(0xCu);
        if ( v12 )
        {
          *(_DWORD *)v12 = v11;
          *((_DWORD *)v12 + 1) = 0;
          *((_DWORD *)v12 + 2) = 0;
          if ( !*(_DWORD *)(v7 + 4) )
          {
            *(_DWORD *)(v7 + 4) = v12;
            *(_DWORD *)(v7 + 8) = v12;
            ++*(_DWORD *)(v7 + 12);
            return 1;
          }
          v13 = *(_DWORD *)(v7 + 8);
          *(_DWORD *)(v13 + 4) = v12;
          *((_DWORD *)v12 + 2) = v13;
          *(_DWORD *)(v7 + 8) = v12;
          ++*(_DWORD *)(v7 + 12);
        }
      }
      result = 1;
    }
    else
    {
      v8 = operator new(0x10u);
      if ( v8 )
      {
        *(_DWORD *)v8 = List<NoticeHandler *>::vftable;
        *((_DWORD *)v8 + 1) = 0;
        *((_DWORD *)v8 + 2) = 0;
        *((_DWORD *)v8 + 3) = 0;
      }
      else
      {
        v8 = 0;
      }
      list = (List<NoticeHandler *> *)v8;
      List<PFileNode *>::push_back((List<UIElement_UIItem *> *)v8, (UIElement_UIItem *const *)&i_pcHandler);
      HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
        (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)v3->m_handlers,
        &i_notice,
        (RenderVertexStreamD3D *const *)&list);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 798FEC: using guessed type int (__thiscall *List<NoticeHandler *>::vftable[3])(void *, char);
// 798FF4: using guessed type int (__thiscall *HashTable<unsigned long,List<NoticeHandler *> *,0>::vftable)(void *, char);

//----- (0043C980) --------------------------------------------------------  // acclient.c:121547
HashTable<unsigned long,List<NoticeHandler *> *,0> *__thiscall HashTable<unsigned long,List<NoticeHandler *> *,0>::vector_deleting_destructor(HashTable<unsigned long,List<NoticeHandler *> *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,List<NoticeHandler *> *,0> *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0> *v3; // edi@1

  v2 = this;
  v3 = &this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,List<NoticeHandler *> *,0>Vtbl *)&HashTable<unsigned long,List<NoticeHandler *> *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>(v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 798FF4: using guessed type int (__thiscall *HashTable<unsigned long,List<NoticeHandler *> *,0>::vftable)(void *, char);

