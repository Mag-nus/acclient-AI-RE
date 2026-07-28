/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Panel
   Object     : ENGINE\uielement_types\UIElement_Panel.obj
   Functions  : 20
   Addresses  : 00429A00 - 006EBD70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00429A00) --------------------------------------------------------  // acclient.c:102361
HashIterator<unsigned long,unsigned long,0> *__thiscall HashSetIterator<UIListener *>::operator++(HashIterator<unsigned long,unsigned long,0> *this)
{
  HashIterator<unsigned long,unsigned long,0> *result; // eax@1
  HashTableData<unsigned long,unsigned long> *v2; // ecx@1
  HashTableData<unsigned long,unsigned long> **v3; // edx@2
  HashTableData<unsigned long,unsigned long> **v4; // ecx@3

  result = this;
  v2 = this->m_iter.m_currElement->m_hashNext;
  result->m_iter.m_currElement = v2;
  if ( !v2 )
  {
    v3 = &result->m_iter.m_currHashTable->m_buckets[result->m_iter.m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      v4 = result->m_iter.m_currBucket + 1;
      result->m_iter.m_currBucket = v4;
      if ( v4 == v3 )
        break;
      if ( *v4 )
      {
        result->m_iter.m_currElement = *v4;
        return result;
      }
    }
  }
  return result;
}

//----- (0042CBA0) --------------------------------------------------------  // acclient.c:105914
void __thiscall HashIterator<unsigned long,StringInfoData *,0>::next(HashIterator<unsigned long,unsigned long,0> *this)
{
  HashTableData<unsigned long,unsigned long> *v1; // eax@1
  HashTableData<unsigned long,unsigned long> **v2; // edx@2
  HashTableData<unsigned long,unsigned long> **v3; // eax@3

  v1 = this->m_iter.m_currElement->m_hashNext;
  this->m_iter.m_currElement = v1;
  if ( !v1 )
  {
    v2 = &this->m_iter.m_currHashTable->m_buckets[this->m_iter.m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      v3 = this->m_iter.m_currBucket + 1;
      this->m_iter.m_currBucket = v3;
      if ( v3 == v2 )
        break;
      if ( *v3 )
      {
        this->m_iter.m_currElement = *v3;
        return;
      }
    }
  }
}

//----- (004635E0) --------------------------------------------------------  // acclient.c:159754
bool __thiscall HashSet<unsigned long>::contains(HashTable<unsigned long,unsigned long,0> *this, const unsigned int *_key)
{
  HashTableData<unsigned long,unsigned long> *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == *_key )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (0046BC70) --------------------------------------------------------  // acclient.c:168385
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *v2; // esi@1
  HashTableData<unsigned long,unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
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
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);

//----- (0046BCB0) --------------------------------------------------------  // acclient.c:168406
char __thiscall UIElement_Panel::InqAvailableProperties(UIElement_Panel *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0xFu, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046BD00) --------------------------------------------------------  // acclient.c:168434
void __thiscall UIElement_Panel::Update(UIElement_Panel *this, unsigned int i_nNewOpenPageID, unsigned int i_nNewOpenTabID)
{
  UIElement_Panel *v3; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@3
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@3
  unsigned int v6; // ebp@4
  unsigned int v7; // eax@4
  UIElement *v8; // ebx@7
  UIElement *v9; // ebp@7
  int v10; // eax@12
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *iter; // [sp+8h] [bp-18h]@3
  HashTableData<unsigned long,HeritageGroup_CG> **iter_4; // [sp+Ch] [bp-14h]@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@3
  signed int page_visible; // [sp+28h] [bp+8h]@4

  v3 = this;
  if ( i_nNewOpenPageID != this->m_OpenPageToken && i_nNewOpenTabID != this->m_OpenTabToken )
  {
    this->m_OpenTabToken = i_nNewOpenTabID;
    this->m_OpenPageToken = i_nNewOpenPageID;
    v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_TabPageHash.m_intrusiveTable,
           &result);
    v5 = v4->m_currElement;
    iter = v4->m_currHashTable;
    iter_4 = v4->m_currBucket;
    if ( v5 )
    {
      do
      {
LABEL_4:
        v6 = v5->m_hashKey;
        v7 = (unsigned int)v5->m_data.vfptr;
        LOBYTE(i_nNewOpenPageID) = 0;
        page_visible = 11;
        if ( v3->m_OpenTabToken == v5->m_hashKey && v3->m_OpenPageToken == v7 )
        {
          LOBYTE(i_nNewOpenPageID) = 1;
          page_visible = 12;
        }
        v8 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v7);
        v9 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v6);
        if ( v8 )
          v8->vfptr[2].__vecDelDtor((IInputActionCallback *)v8, i_nNewOpenPageID);
        if ( v9 )
          v9->vfptr[13].__vecDelDtor((IInputActionCallback *)v9, page_visible);
        v5 = v5->m_hashNext;
      }
      while ( v5 );
      while ( 1 )
      {
        v10 = (int)(iter_4 + 1);
        ++iter_4;
        if ( iter_4 == &iter->m_buckets[iter->m_numBuckets] )
          break;
        if ( *(_DWORD *)v10 )
        {
          v5 = *(HashTableData<unsigned long,HeritageGroup_CG> **)v10;
          if ( *(_DWORD *)v10 )
            goto LABEL_4;
          break;
        }
      }
    }
    UIElement::BroadcastElementMessage((UIElement *)&v3->vfptr, 0x2Cu, 0, 0);
  }
}

//----- (0046BE20) --------------------------------------------------------  // acclient.c:168503
char __thiscall UIElement_Panel::OpenTab(UIElement_Panel *this, unsigned int _tabID)
{
  HashTableData<unsigned long,unsigned long> *v2; // eax@1
  char result; // al@4
  unsigned int v4; // esi@6
  HashTableData<unsigned long,unsigned long> *v5; // eax@6
  unsigned int v6; // eax@11

  v2 = this->m_TabPageHash.m_intrusiveTable.m_buckets[_tabID % this->m_TabPageHash.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _tabID )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
  {
    v4 = v2->m_data;
    v5 = this->m_PageTabHash.m_intrusiveTable.m_buckets[v2->m_data % this->m_PageTabHash.m_intrusiveTable.m_numBuckets];
    if ( !v5 )
      goto LABEL_9;
    while ( v5->m_hashKey != v4 )
    {
      v5 = v5->m_hashNext;
      if ( !v5 )
        goto LABEL_9;
    }
    if ( v5 && (v6 = v5->m_data, v6 == _tabID) )
    {
      UIElement_Panel::Update(this, v4, v6);
      result = 1;
    }
    else
    {
LABEL_9:
      result = 0;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0046BEB0) --------------------------------------------------------  // acclient.c:168552
char __thiscall UIElement_Panel::InqTabFromPage(UIElement_Panel *this, unsigned int _pageToken, unsigned int *_tabToken)
{
  HashTableData<unsigned long,unsigned long> *v3; // eax@1
  char result; // al@4

  v3 = this->m_PageTabHash.m_intrusiveTable.m_buckets[_pageToken % this->m_PageTabHash.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != _pageToken )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    *_tabToken = v3->m_data;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0046BF00) --------------------------------------------------------  // acclient.c:168580
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);

//----- (0046BF90) --------------------------------------------------------  // acclient.c:168613
int __thiscall UIElement_Panel::ListenToElementMessage(UIElement_Panel *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // edi@1
  UIElement_Panel *v3; // esi@1
  UIElement *v4; // ecx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *v6; // ecx@4
  HashTableData<unsigned long,unsigned long> **v7; // edx@4
  HashTableData<unsigned long,unsigned long> *v8; // eax@4
  UIElement *v9; // eax@5
  UIElement *v11; // eax@9
  UIElement *v12; // eax@17
  unsigned int v13; // ST00_4@19
  unsigned int v14; // eax@20
  HashIterator<unsigned long,unsigned long,0> iter; // [sp+8h] [bp-18h]@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@4

  v2 = i_rMsg;
  v3 = this;
  v4 = i_rMsg->pElement;
  if ( (UIElement_Panel *)v4 != v3 )
  {
    if ( (UIElement_Panel *)((int (*)(void))v4->vfptr[13].OnAction)() == v3 )
    {
      if ( v2->idMessage == 24 )
      {
        if ( HashSet<unsigned long>::contains(&v3->m_PageTabHash, &v2->idElement) )
        {
          v12 = v2->pElement;
          if ( v12 )
          {
            if ( (*((_DWORD *)&v12->0 + 41) >> 1) & 1 )
            {
              v13 = v2->idElement;
              i_rMsg = 0;
              UIElement_Panel::InqTabFromPage(v3, v13, (unsigned int *)&i_rMsg);
              UIElement_Panel::OpenTab(v3, (unsigned int)i_rMsg);
            }
            v14 = (unsigned int)UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v3->m_OpenPageToken);
            if ( v14 )
              v14 = (*(_DWORD *)(v14 + 164) >> 1) & 0xFFFFFF01;
            else
              LOBYTE(v14) = 0;
            v3->vfptr[2].__vecDelDtor((IInputActionCallback *)v3, v14);
          }
        }
      }
      else if ( v2->idMessage == 25 || v2->idMessage == 41 )
      {
        UIElement_Panel::OpenTab(v3, v2->idElement);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
      }
    }
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
  }
  if ( i_rMsg->idMessage != 24 )
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
  if ( i_rMsg->dwParam1 )
  {
    v11 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v3->m_OpenPageToken);
    if ( v11 )
    {
      v11->vfptr[2].__vecDelDtor((IInputActionCallback *)v11, 1u);
      return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
    }
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
  }
  v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_PageTabHash.m_intrusiveTable,
         &result);
  v6 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0> *)v5->m_currHashTable;
  v7 = (HashTableData<unsigned long,unsigned long> **)v5->m_currBucket;
  v8 = (HashTableData<unsigned long,unsigned long> *)v5->m_currElement;
  iter.m_iter.m_currHashTable = v6;
  iter.m_iter.m_currBucket = v7;
  iter.m_iter.m_currElement = v8;
  if ( !v8 )
    return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
  do
  {
    v9 = UIElement::GetChildRecursive((UIElement *)&v3->vfptr, v8->m_hashKey);
    if ( v9 )
      v9->vfptr[2].__vecDelDtor((IInputActionCallback *)v9, 0);
    HashIterator<unsigned long,StringInfoData *,0>::next(&iter);
    v8 = iter.m_iter.m_currElement;
  }
  while ( iter.m_iter.m_currElement );
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, v2);
}

//----- (0046C110) --------------------------------------------------------  // acclient.c:168704
HashTable<unsigned long,unsigned long,0> *__thiscall HashTable<unsigned long,unsigned long,0>::scalar_deleting_destructor(HashTable<unsigned long,unsigned long,0> *this, unsigned int a2)
{
  HashTable<unsigned long,unsigned long,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
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
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);

//----- (0046C170) --------------------------------------------------------  // acclient.c:168730
void __userpurge UIElement_Panel::UIElement_Panel(UIElement_Panel *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Panel *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Panel::vftable;
  v4->m_TabPageHash.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &v4->m_TabPageHash.m_intrusiveTable,
    0x17u);
  v4->m_PageTabHash.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &v4->m_PageTabHash.m_intrusiveTable,
    0x17u);
  v4->m_OpenPageToken = 0;
  v4->m_OpenTabToken = 0;
}
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 79C9B0: using guessed type int (__thiscall *UIElement_Panel::vftable)(void *, char);

//----- (0046C1D0) --------------------------------------------------------  // acclient.c:168752
signed int __thiscall UIElement_Panel::DynamicCast(UIElement_Panel *this, unsigned int i_eType)
{
  return i_eType != 8 ? 0 : (unsigned int)this;
}

//----- (0046C1F0) --------------------------------------------------------  // acclient.c:168758
void __thiscall UIElement_Panel::~UIElement_Panel(UIElement_Panel *this)
{
  UIElement_Panel *v1; // esi@1
  void *v2; // eax@1
  void *v3; // eax@3

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Panel::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_TabPageHash.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_PageTabHash.m_intrusiveTable);
  v1->m_OpenTabToken = 0;
  v1->m_OpenPageToken = 0;
  v1->m_PageTabHash.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_PageTabHash.m_intrusiveTable);
  v2 = v1->m_PageTabHash.m_intrusiveTable.m_buckets;
  v1->m_PageTabHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v2 != v1->m_PageTabHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_PageTabHash.m_intrusiveTable.m_buckets = 0;
  v1->m_PageTabHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_PageTabHash.m_intrusiveTable.m_numBuckets = 0;
  v1->m_PageTabHash.m_intrusiveTable.m_numElements = 0;
  v1->m_TabPageHash.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_TabPageHash.m_intrusiveTable);
  v3 = v1->m_TabPageHash.m_intrusiveTable.m_buckets;
  v1->m_TabPageHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v3 != v1->m_TabPageHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_TabPageHash.m_intrusiveTable.m_buckets = 0;
  v1->m_TabPageHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_TabPageHash.m_intrusiveTable.m_numBuckets = 0;
  v1->m_TabPageHash.m_intrusiveTable.m_numElements = 0;
  UIElement::~UIElement((UIElement *)&v1->vfptr);
}
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 79C9B0: using guessed type int (__thiscall *UIElement_Panel::vftable)(void *, char);

//----- (0046C2B0) --------------------------------------------------------  // acclient.c:168797
void __usercall UIElement_Panel::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Panel *v3; // eax@1

  v3 = (UIElement_Panel *)operator new(0x6E0u);
  if ( v3 )
    UIElement_Panel::UIElement_Panel(v3, a1, _layout, _full_desc);
}

//----- (0046C2E0) --------------------------------------------------------  // acclient.c:168807
void __thiscall UIElement_Panel::SetupTabPageHash(UIElement_Panel *this)
{
  UIElement_Panel *v1; // esi@1
  IInputActionCallbackVtbl *v2; // eax@1
  unsigned int v3; // ebp@1
  unsigned int i; // edi@4
  char v5; // al@16
  UIElement *v6; // eax@29
  BasePropertyDesc *v7; // ecx@32
  unsigned int v8; // edx@32
  BasePropertyValue *v9; // ecx@36
  unsigned int v10; // edx@36
  BasePropertyDesc *v11; // ecx@40
  unsigned int v12; // edx@40
  BasePropertyValue *v13; // ecx@44
  unsigned int v14; // edx@44
  BasePropertyDesc *v15; // ecx@48
  unsigned int v16; // edx@48
  BasePropertyValue *v17; // ecx@52
  unsigned int v18; // edx@52
  BasePropertyDesc *v19; // ecx@57
  unsigned int v20; // edx@57
  BasePropertyValue *v21; // ecx@61
  unsigned int v22; // edx@61
  int v23; // [sp+40h] [bp-3Ch]@13
  unsigned int tab_token; // [sp+44h] [bp-38h]@12
  unsigned int page_token; // [sp+48h] [bp-34h]@12
  unsigned int number; // [sp+4Ch] [bp-30h]@2
  unsigned int page_to_open; // [sp+50h] [bp-2Ch]@1
  BaseProperty strct; // [sp+54h] [bp-28h]@5
  BaseProperty page_element; // [sp+5Ch] [bp-20h]@8
  BaseProperty tab_element; // [sp+64h] [bp-18h]@8
  BaseProperty array; // [sp+6Ch] [bp-10h]@1
  BaseProperty open_page_property; // [sp+74h] [bp-8h]@23

  v1 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_TabPageHash.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_PageTabHash.m_intrusiveTable);
  v2 = v1->vfptr;
  v1->m_OpenTabToken = 0;
  v1->m_OpenPageToken = 0;
  v3 = 0;
  page_to_open = 0;
  array.m_pcPropertyDesc = 0;
  array.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__thiscall *)(UIElement_Panel *, signed int, BaseProperty *))v2[17].OnAction)(
                          v1,
                          46,
                          &array) )
  {
    number = 0;
    if ( array.m_pcPropertyValue )
    {
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int *))array.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&number) )
      {
        for ( i = 0; i < number; ++i )
        {
          strct.m_pcPropertyDesc = 0;
          strct.m_pcPropertyValue = 0;
          if ( array.m_pcPropertyValue )
          {
            if ( !(unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))array.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                                     i,
                                     &strct) )
              goto LABEL_47;
            if ( BaseProperty::GetPropertyName(&strct) != (BasePropertyDesc *)47 )
              goto LABEL_47;
            tab_element.m_pcPropertyDesc = 0;
            tab_element.m_pcPropertyValue = 0;
            page_element.m_pcPropertyDesc = 0;
            page_element.m_pcPropertyValue = 0;
            if ( !strct.m_pcPropertyValue )
              goto LABEL_47;
            if ( !(unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))strct.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                                     48,
                                     &tab_element)
              || !strct.m_pcPropertyValue
              || !(unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))strct.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                                     49,
                                     &page_element) )
              goto LABEL_31;
            tab_token = 0;
            page_token = 0;
            if ( tab_element.m_pcPropertyValue )
              BYTE3(v23) = ((int (__stdcall *)(unsigned int *))tab_element.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&tab_token);
            else
              BYTE3(v23) = 0;
            if ( page_element.m_pcPropertyValue )
              v5 = ((int (__stdcall *)(unsigned int *))page_element.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&page_token);
            else
              v5 = 0;
            if ( BYTE3(v23) && v5 )
            {
              if ( HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
                     (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_TabPageHash,
                     &tab_token,
                     (RenderVertexStreamD3D *const *)&page_token)
                && HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
                     (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&v1->m_PageTabHash,
                     &page_token,
                     (RenderVertexStreamD3D *const *)&tab_token)
                && tab_token != page_token )
              {
                open_page_property.m_pcPropertyDesc = 0;
                open_page_property.m_pcPropertyValue = 0;
                if ( strct.m_pcPropertyValue )
                {
                  if ( (unsigned __int8)((int (__stdcall *)(signed int, _DWORD))strct.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                                          50,
                                          &open_page_property) )
                  {
                    BYTE3(v23) = 0;
                    if ( open_page_property.m_pcPropertyValue )
                    {
                      if ( (unsigned __int8)((int (__stdcall *)(char *))open_page_property.m_pcPropertyValue->vfptr[28].__vecDelDtor)((char *)&v23 + 3)
                        && BYTE3(v23) )
                      {
                        v3 = tab_token;
                        page_to_open = page_token;
                      }
                    }
                  }
                }
                v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, tab_token);
                if ( !v6 )
                {
                  BaseProperty::~BaseProperty(&open_page_property);
                  BaseProperty::~BaseProperty(&page_element);
                  BaseProperty::~BaseProperty(&tab_element);
                  BaseProperty::~BaseProperty(&strct);
                  BaseProperty::~BaseProperty(&array);
                  return;
                }
                ((void (__thiscall *)(UIElement *, signed int))v6->vfptr[22].OnLoseFocus)(v6, 1);
                BaseProperty::~BaseProperty(&open_page_property);
              }
LABEL_31:
              if ( (_DWORD)page_element.m_pcPropertyDesc )
              {
                v7 = page_element.m_pcPropertyDesc;
                v8 = page_element.m_pcPropertyDesc->m_cRef - 1;
                page_element.m_pcPropertyDesc->m_cRef = v8;
                if ( !v8 )
                  ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
                page_element.m_pcPropertyDesc = 0;
              }
              if ( page_element.m_pcPropertyValue )
              {
                v9 = page_element.m_pcPropertyValue;
                v10 = page_element.m_pcPropertyValue->m_cRef - 1;
                page_element.m_pcPropertyValue->m_cRef = v10;
                if ( !v10 )
                  ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
                page_element.m_pcPropertyValue = 0;
              }
              if ( (_DWORD)tab_element.m_pcPropertyDesc )
              {
                v11 = tab_element.m_pcPropertyDesc;
                v12 = tab_element.m_pcPropertyDesc->m_cRef - 1;
                tab_element.m_pcPropertyDesc->m_cRef = v12;
                if ( !v12 )
                  ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
                tab_element.m_pcPropertyDesc = 0;
              }
              if ( tab_element.m_pcPropertyValue )
              {
                v13 = tab_element.m_pcPropertyValue;
                v14 = tab_element.m_pcPropertyValue->m_cRef - 1;
                tab_element.m_pcPropertyValue->m_cRef = v14;
                if ( !v14 )
                  ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
                tab_element.m_pcPropertyValue = 0;
              }
LABEL_47:
              if ( (_DWORD)strct.m_pcPropertyDesc )
              {
                v15 = strct.m_pcPropertyDesc;
                v16 = strct.m_pcPropertyDesc->m_cRef - 1;
                strct.m_pcPropertyDesc->m_cRef = v16;
                if ( !v16 )
                  ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
                strct.m_pcPropertyDesc = 0;
              }
              if ( strct.m_pcPropertyValue )
              {
                v17 = strct.m_pcPropertyValue;
                v18 = strct.m_pcPropertyValue->m_cRef - 1;
                strct.m_pcPropertyValue->m_cRef = v18;
                if ( !v18 )
                  ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
                strct.m_pcPropertyValue = 0;
              }
              continue;
            }
            BaseProperty::~BaseProperty(&page_element);
            BaseProperty::~BaseProperty(&tab_element);
            BaseProperty::~BaseProperty(&strct);
          }
        }
      }
    }
  }
  UIElement_Panel::Update(v1, page_to_open, v3);
  if ( (_DWORD)array.m_pcPropertyDesc )
  {
    v19 = array.m_pcPropertyDesc;
    v20 = array.m_pcPropertyDesc->m_cRef - 1;
    array.m_pcPropertyDesc->m_cRef = v20;
    if ( !v20 )
      ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
    array.m_pcPropertyDesc = 0;
  }
  if ( array.m_pcPropertyValue )
  {
    v21 = array.m_pcPropertyValue;
    v22 = array.m_pcPropertyValue->m_cRef - 1;
    array.m_pcPropertyValue->m_cRef = v22;
    if ( !v22 )
      ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
  }
}

//----- (0046C690) --------------------------------------------------------  // acclient.c:169030
UIElement_Panel *__thiscall UIElement_Panel::vector_deleting_destructor(UIElement_Panel *this, unsigned int a2)
{
  UIElement_Panel *v2; // esi@1

  v2 = this;
  UIElement_Panel::~UIElement_Panel(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0046C6B0) --------------------------------------------------------  // acclient.c:169042
void __cdecl UIElement_Panel::Register()
{
  UIElement::RegisterElementClass(8u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Panel::Create);
}

//----- (0046C6C0) --------------------------------------------------------  // acclient.c:169048
void __userpurge UIElement_Panel::OnSetAttribute(UIElement_Panel *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  UIElement_Panel *v3; // esi@1

  v3 = this;
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, _attribute);
  if ( BaseProperty::GetPropertyName(_attribute) == (BasePropertyDesc *)46 )
    UIElement_Panel::SetupTabPageHash(v3);
}

//----- (006EBD70) --------------------------------------------------------  // acclient.c:767656
int _E1_62()
{
  return atexit(_E2_62);
}

