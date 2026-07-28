/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ElementDesc
   Object     : ENGINE\uielement_desc\ElementDesc.obj
   Functions  : 124
   Addresses  : 00681AF0 - 00788010 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00681AF0) --------------------------------------------------------  // acclient.c:664973
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v2; // esi@1
  char result; // al@2
  HashTableData<unsigned long,StateDesc> *v4; // ebx@3
  int v5; // ecx@4
  HashTableData<unsigned long,StateDesc> **v6; // eax@5
  int v7; // eax@6
  HashTableData<unsigned long,StateDesc> **v8; // ecx@7
  HashTableData<unsigned long,StateDesc> *v9; // edi@7
  _BYTE v10[12]; // ST00_12@9
  HashTableData<unsigned long,StateDesc> *v11; // ecx@12
  HashTableData<unsigned long,StateDesc> *v12; // edi@13
  int v13; // eax@13

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<unsigned long,StateDesc> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v2,
          *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<unsigned long,StateDesc> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v11 = v4;
    if ( v4 )
    {
      do
      {
        v12 = v11->m_hashNext;
        v13 = (int)&v2->m_buckets[v11->m_hashKey % v2->m_numBuckets];
        v11->m_hashNext = *(HashTableData<unsigned long,StateDesc> **)v13;
        *(_DWORD *)v13 = v11;
        if ( (HashTableData<unsigned long,StateDesc> **)v13 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)v13;
        ++v2->m_numElements;
        v11 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (0069A720) --------------------------------------------------------  // acclient.c:690493
int __thiscall PFileNode::MakeSubNodeAsInt32(PFileNode *this, int i_name)
{
  int result; // eax@1
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@2
  void *v5; // eax@4

  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = (PFileNode *)result;
  if ( result )
  {
    v4 = *(IFileNodeName **)(result + 8);
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_pcName = 0;
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = &FileNodeName_Int32::vftable;
      *((_DWORD *)v5 + 1) = i_name;
      v3->m_pcName = (IFileNodeName *)v5;
      result = (int)v3;
    }
    else
    {
      v3->m_pcName = 0;
      result = (int)v3;
    }
  }
  return result;
}
// 797124: using guessed type int (__thiscall *FileNodeName_Int32::vftable)(void *, char);

//----- (0069A780) --------------------------------------------------------  // acclient.c:690527
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v2; // esi@1
  HashTableData<unsigned long,StateDesc> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable;
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
// 800D30: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable)(void *, char);

//----- (0069A830) --------------------------------------------------------  // acclient.c:690585
void __thiscall ElementDesc::UpdateSizeAndPosition(ElementDesc *this, Box2D *_oldParent, Box2D *_newParent, unsigned int _leftEdge, unsigned int _topEdge, unsigned int _rightEdge, unsigned int _bottomEdge)
{
  ElementDesc *v7; // esi@1
  int v8; // ecx@1
  int v9; // edx@1
  int v10; // eax@1
  int v11; // ecx@1
  int v12; // edx@1
  int v13; // ecx@1
  int v14; // edx@1
  int v15; // eax@1
  int v16; // ecx@1
  int v17; // edx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v18; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v19; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v20; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v21; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-2Ch]@1
  Box2D new_self; // [sp+18h] [bp-20h]@1
  Box2D old_self; // [sp+28h] [bp-10h]@1

  v7 = this;
  v8 = this->m_x;
  v9 = v7->m_width;
  v10 = v7->m_y;
  old_self.m_x0 = v8;
  v11 = v9 + v8 - 1;
  v12 = v7->m_height;
  old_self.m_x1 = v11;
  old_self.m_y0 = v10;
  old_self.m_y1 = v12 + v10 - 1;
  StateDesc::UpdateSizeAndPosition(
    (StateDesc *)&v7->vfptr,
    _oldParent,
    _newParent,
    _leftEdge,
    _topEdge,
    _rightEdge,
    _bottomEdge);
  v13 = v7->m_x;
  v14 = v7->m_width;
  v15 = v7->m_y;
  new_self.m_x0 = v13;
  v16 = v14 + v13 - 1;
  v17 = v7->m_height;
  new_self.m_x1 = v16;
  new_self.m_y0 = v15;
  new_self.m_y1 = v17 + v15 - 1;
  v18 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v7->m_children.m_intrusiveTable,
          &result);
  v19 = v18->m_currElement;
  v20 = v18->m_currHashTable;
  v21 = v18->m_currBucket;
  if ( v19 )
  {
    do
    {
LABEL_2:
      ((void (__stdcall *)(Box2D *, Box2D *, _DWORD, _DWORD, _DWORD, _DWORD))v19->m_data.vfptr[8].Serialize)(
        &old_self,
        &new_self,
        v19[1].m_hashKey,
        v19[1].m_hashNext,
        v19[1].m_data.vfptr,
        v19[1].m_data.name.m_charbuffer);
      v19 = v19->m_hashNext;
    }
    while ( v19 );
    while ( 1 )
    {
      ++v21;
      if ( v21 == &v20->m_buckets[v20->m_numBuckets] )
        break;
      if ( *v21 )
      {
        v19 = *v21;
        if ( *v21 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (0069A920) --------------------------------------------------------  // acclient.c:690671
void __thiscall ElementDesc::GetSubDataIDs(ElementDesc *this, QualifiedDataIDArray *_id_array)
{
  ElementDesc *v2; // ebx@1
  QualifiedDataID *v3; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebp@1
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // edi@1
  int v8; // ecx@6
  HashTableData<unsigned long,StateDesc> **v9; // eax@7
  int v10; // eax@8
  HashTableData<unsigned long,StateDesc> **v11; // eax@9
  HashTableData<unsigned long,StateDesc> *v12; // esi@9
  HashTableData<unsigned long,StateDesc> **v13; // edi@11
  QualifiedDataID v14; // [sp+10h] [bp-Ch]@1

  v2 = this;
  StateDesc::GetSubDataIDs((StateDesc *)&this->vfptr, _id_array);
  QualifiedDataID::QualifiedDataID(&v14, v2->m_baseLayout, 0);
  QualifiedDataIDArray::AddQDID(_id_array, v3, 0);
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_children.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v14);
  v5 = v4->m_currElement;
  v6 = v4->m_currHashTable;
  v7 = v4->m_currBucket;
  if ( v5 )
  {
    do
    {
LABEL_2:
      v5->m_data.vfptr[2].Serialize(&v5->m_data, (Archive *)_id_array);
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    while ( 1 )
    {
      ++v7;
      if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
        break;
      if ( *v7 )
      {
        v5 = *v7;
        if ( *v7 )
          goto LABEL_2;
        break;
      }
    }
  }
  v8 = (int)&v2->m_states.m_intrusiveTable.m_buckets[v2->m_states.m_intrusiveTable.m_numBuckets];
  if ( v2->m_states.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,StateDesc> **)v8 )
  {
LABEL_9:
    v11 = 0;
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = v2->m_states.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v9 )
        break;
      v10 = (int)(v9 + 1);
      v2->m_states.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)v10;
      if ( v10 == v8 )
        goto LABEL_9;
    }
    v11 = v2->m_states.m_intrusiveTable.m_firstInterestingBucket;
    v12 = *v11;
  }
  v13 = v11;
  if ( v12 )
  {
    do
    {
LABEL_12:
      v12->m_data.vfptr->GetSubDataIDs(&v12->m_data, _id_array);
      v12 = v12->m_hashNext;
    }
    while ( v12 );
    while ( 1 )
    {
      ++v13;
      if ( v13 == &v2->m_states.m_intrusiveTable.m_buckets[v2->m_states.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v13 )
      {
        v12 = *v13;
        if ( *v13 )
          goto LABEL_12;
        return;
      }
    }
  }
}

//----- (0069AA40) --------------------------------------------------------  // acclient.c:690769
char __thiscall ElementDesc::PositionToFileNode(ElementDesc *this, PFileNode *_file_node)
{
  ElementDesc *v2; // edi@1
  PStringBase<char> v3; // edi@2
  volatile LONG *v4; // ebx@2
  PFileNode *v5; // ebx@2
  int v6; // edi@2
  PStringBase<char> v8; // ST04_4@10
  PFileNode *v9; // eax@10
  PStringBase<char> v10; // ST04_4@13
  PFileNode *v11; // eax@13
  PStringBase<char> v12; // ST04_4@16
  PFileNode *v13; // eax@16
  PStringBase<char> v14; // ST04_4@19
  PFileNode *v15; // eax@19
  ElementDesc *v16; // [sp+10h] [bp-4h]@1

  v2 = this;
  v16 = this;
  if ( this->m_uiIncorporationFlags & 2 )
  {
    v3.m_charbuffer = KW_X_0.m_charbuffer;
    v4 = (volatile LONG *)&KW_X_0.m_charbuffer[-1];
    InterlockedIncrement((volatile LONG *)&KW_X_0.m_charbuffer[-1]);
    InterlockedIncrement(v4);
    v5 = PFileNode::MakeSubNodeAsPString(_file_node, v3);
    v6 = (int)&v3.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    if ( !v5 || !PFileNode::MakeSubNodeAsInt32(v5, v16->m_x) )
      return 0;
    v2 = v16;
  }
  if ( v2->m_uiIncorporationFlags & 4 )
  {
    v8.m_charbuffer = KW_Y_0.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&KW_Y_0.m_charbuffer[-1]);
    v9 = PFileNode::MakeSubNode(_file_node, v8);
    if ( !v9 || !PFileNode::MakeSubNodeAsInt32(v9, v2->m_y) )
      return 0;
  }
  if ( v2->m_uiIncorporationFlags & 8 )
  {
    v10.m_charbuffer = KW_WIDTH_0.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&KW_WIDTH_0.m_charbuffer[-1]);
    v11 = PFileNode::MakeSubNode(_file_node, v10);
    if ( !v11 || !PFileNode::MakeSubNodeAsInt32(v11, v2->m_width) )
      return 0;
  }
  if ( v2->m_uiIncorporationFlags & 0x10 )
  {
    v12.m_charbuffer = KW_HEIGHT_0.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&KW_HEIGHT_0.m_charbuffer[-1]);
    v13 = PFileNode::MakeSubNode(_file_node, v12);
    if ( !v13 || !PFileNode::MakeSubNodeAsInt32(v13, v2->m_height) )
      return 0;
  }
  if ( v2->m_uiIncorporationFlags & 0x20 )
  {
    v14.m_charbuffer = KW_ZLEVEL_0.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&KW_ZLEVEL_0.m_charbuffer[-1]);
    v15 = PFileNode::MakeSubNode(_file_node, v14);
    if ( !v15 || !PFileNode::MakeSubNodeAsInt32(v15, v2->m_zLevel) )
      return 0;
  }
  return 1;
}

//----- (0069ABB0) --------------------------------------------------------  // acclient.c:690838
char __thiscall ElementDesc::CheckFFN(ElementDesc *this, PFileNode *_file_node)
{
  ElementDesc *v2; // esi@1
  unsigned int v3; // edx@1
  unsigned int v4; // ecx@1
  bool v5; // dl@1
  char result; // al@1
  PStringBase<char> v7; // [sp-4h] [bp-Ch]@7

  v2 = this;
  v3 = this->m_type;
  v4 = this->m_baseElement;
  v5 = v3 != 0;
  result = 1;
  LOBYTE(v4) = v4 || (v4 = v2->m_baseLayout.id, v4 != stru_8F90E0.id);
  if ( v5 )
  {
    if ( !(_BYTE)v4 )
      goto LABEL_11;
    v7.m_charbuffer = (PSRefBufferCharData<char> *)v4;
    PStringBase<char>::PStringBase<char>(&v7, "ElementDesc::CheckFFN, use only Typeor Base keywords, not both.");
  }
  else
  {
    if ( (_BYTE)v4 )
      goto LABEL_11;
    v7.m_charbuffer = (PSRefBufferCharData<char> *)v4;
    PStringBase<char>::PStringBase<char>(&v7, "ElementDesc::CheckFFN, use either Typeor Base keywords.");
  }
  PFileNode::ReportError((int)_file_node, _file_node, v7);
  result = 0;
LABEL_11:
  if ( v2->m_stateID )
  {
    v7.m_charbuffer = (PSRefBufferCharData<char> *)v2->m_stateID;
    PStringBase<char>::PStringBase<char>(&v7, "ElementDesc::CheckFFN, dont use the StateID keyword in Elements.");
    PFileNode::ReportError((int)_file_node, _file_node, v7);
    result = 0;
  }
  if ( !v2->m_elementID )
  {
    v7.m_charbuffer = 0;
    PStringBase<char>::PStringBase<char>(&v7, "ElementDesc::CheckFFN, you must use the ElementID keyword in Elements.");
    PFileNode::ReportError((int)_file_node, _file_node, v7);
    result = 0;
  }
  return result;
}

//----- (0069AC60) --------------------------------------------------------  // acclient.c:690888
StateDesc *__thiscall ElementDesc::AccessStateDesc(ElementDesc *this, unsigned int _stateID)
{
  HashTableData<unsigned long,StateDesc> *v2; // eax@1
  StateDesc *result; // eax@4

  v2 = this->m_states.m_intrusiveTable.m_buckets[_stateID % this->m_states.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _stateID )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = &v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (0069ACA0) --------------------------------------------------------  // acclient.c:690911
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,StateDesc> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 800D30: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable)(void *, char);

//----- (0069AD30) --------------------------------------------------------  // acclient.c:690944
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::resize(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *this, unsigned int _numBuckets)
{
  unsigned int *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v3; // edi@1
  unsigned int *v4; // eax@1

  v2 = g_bucketSizesEnd;
  v3 = this;
  v4 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v2 )
    --v4;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::resize_internal(v3, *v4);
}

//----- (0069AD80) --------------------------------------------------------  // acclient.c:690959
char __thiscall HashTable<unsigned long,StateDesc,0>::add(HashTable<unsigned long,StateDesc,0> *this, const unsigned int *_key, StateDesc *_data)
{
  HashTable<unsigned long,StateDesc,0> *v3; // edi@1
  void *v4; // esi@1
  char result; // al@7

  v3 = this;
  v4 = operator new(0xB0u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    StateDesc::StateDesc((StateDesc *)((char *)v4 + 8), _data);
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
      StateDesc::~StateDesc((StateDesc *)((char *)v4 + 8));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (0069ADF0) --------------------------------------------------------  // acclient.c:690996
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,StateDesc> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,StateDesc> **v5; // edx@5
  HashTableData<unsigned long,StateDesc> *v6; // edi@5
  HashTableData<unsigned long,StateDesc> *v7; // eax@7
  HashTableData<unsigned long,StateDesc> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,StateDesc> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)v4;
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
      StateDesc::~StateDesc(&v6->m_data);
      operator delete(v6);
    }
  }
}

//----- (0069AE80) --------------------------------------------------------  // acclient.c:691056
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>,HashTableData<unsigned long,StateDesc> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // edi@32
  unsigned int v19; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::resize(
        io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        v11->m_data.vfptr[1].Serialize(&v11->m_data, v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_43:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0xB0u);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            StateDesc::StateDesc((StateDesc *)((char *)v17 + 8));
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v19;
          }
          (*(void (__thiscall **)(int, Archive *))(*((_DWORD *)v18 + 2) + 4))((char *)v18 + 8, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_43;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (0069B0A0) --------------------------------------------------------  // acclient.c:691209
int __thiscall HashTable<unsigned long,StateDesc,0>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // ebx@1
  unsigned int *v4; // ebp@2
  unsigned int *v5; // eax@2
  void *v6; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@4
  void *v9; // esi@7
  unsigned int v10; // ebx@10
  int v11; // ecx@10
  int v12; // edx@11
  int v13; // eax@14
  HashTableData<unsigned long,HeritageGroup_CG> **v14; // ecx@18
  HashTableData<unsigned long,HeritageGroup_CG> **v15; // eax@19
  int v17; // [sp+8h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v19; // [sp+18h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v17 = this;
  if ( this == __val )
    return v3;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)(this + 4));
  v4 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v5 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v5 == v4 )
    --v5;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::resize_internal(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)(v3 + 4),
    *v5);
  v6 = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v8 = v7->m_currElement;
  v19 = v7->m_currHashTable;
  result.m_currBucket = v7->m_currBucket;
  if ( !v8 )
    return v3;
  while ( 1 )
  {
    v9 = operator new(0xB0u);
    if ( v9 )
    {
      *(_DWORD *)v9 = v8->m_hashKey;
      *((_DWORD *)v9 + 1) = 0;
      StateDesc::StateDesc((StateDesc *)((char *)v9 + 8), (StateDesc *)&v8->m_data);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)(v3 + 108);
    v11 = *(_DWORD *)v9 % v10;
    if ( !v6 )
      goto LABEL_14;
    v12 = *(_DWORD *)v6 % v10;
    if ( v11 != v12 )
    {
      if ( v11 <= (unsigned int)v12 )
        goto LABEL_17;
LABEL_14:
      v13 = *(_DWORD *)(v17 + 100) + 4 * v11;
      *(_DWORD *)v13 = v9;
      if ( !v6 )
        *(_DWORD *)(v17 + 104) = v13;
      goto LABEL_16;
    }
    *((_DWORD *)v6 + 1) = v9;
LABEL_16:
    ++*(_DWORD *)(v17 + 112);
LABEL_17:
    v8 = v8->m_hashNext;
    v6 = v9;
    if ( !v8 )
      break;
LABEL_6:
    v3 = v17;
  }
  v14 = &v19->m_buckets[v19->m_numBuckets];
  while ( 1 )
  {
    v15 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v14 )
      return v17;
    if ( *v15 )
    {
      v8 = *v15;
      if ( *v15 )
        goto LABEL_6;
      return v17;
    }
  }
}

//----- (0069B1F0) --------------------------------------------------------  // acclient.c:691310
HashTable<unsigned long,StateDesc,0> *__thiscall HashTable<unsigned long,StateDesc,0>::vector_deleting_destructor(HashTable<unsigned long,StateDesc,0> *this, unsigned int a2)
{
  HashTable<unsigned long,StateDesc,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,StateDesc,0>Vtbl *)HashTable<unsigned long,StateDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable;
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
// 800D30: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable)(void *, char);
// 800E40: using guessed type int (__thiscall *HashTable<unsigned long,StateDesc,0>::vftable[2])(void *, char);

//----- (0069B250) --------------------------------------------------------  // acclient.c:691336
void __thiscall ElementDesc::~ElementDesc(ElementDesc *this)
{
  ElementDesc *v1; // esi@1
  char *v2; // edi@1
  int v3; // edi@4
  void *v4; // eax@7

  v1 = this;
  v2 = &this->m_strName.m_charbuffer[-2].m_data[12];
  this->vfptr = (StateDescVtbl *)&ElementDesc::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_strComments.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v1->m_children.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&v1->m_children.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::~IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(&v1->m_children.m_intrusiveTable);
  v1->m_states.vfptr = (HashTable<unsigned long,StateDesc,0>Vtbl *)HashTable<unsigned long,StateDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::delete_contents(&v1->m_states.m_intrusiveTable);
  v4 = v1->m_states.m_intrusiveTable.m_buckets;
  v1->m_states.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable;
  if ( v4 != v1->m_states.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_states.m_intrusiveTable.m_buckets = 0;
  v1->m_states.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_states.m_intrusiveTable.m_numBuckets = 0;
  v1->m_states.m_intrusiveTable.m_numElements = 0;
  StateDesc::~StateDesc((StateDesc *)&v1->vfptr);
}
// 79BD34: using guessed type int (__thiscall *ElementDesc::vftable)(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 800D30: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable)(void *, char);
// 800E40: using guessed type int (__thiscall *HashTable<unsigned long,StateDesc,0>::vftable[2])(void *, char);

//----- (0069B310) --------------------------------------------------------  // acclient.c:691372
void __thiscall ElementDesc::ElementDesc(ElementDesc *this)
{
  ElementDesc *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  StateDesc::StateDesc((StateDesc *)&this->vfptr);
  v1->vfptr = (StateDescVtbl *)&ElementDesc::vftable;
  v1->m_elementID = 0;
  v1->m_type = 0;
  v1->m_engineType = 0;
  v1->m_baseElement = 0;
  v1->m_baseLayout.id = stru_8F90E0.id;
  v1->m_defaultState = 0;
  v1->m_leftEdge = 0;
  v1->m_topEdge = 0;
  v1->m_rightEdge = 0;
  v1->m_bottomEdge = 0;
  v1->m_states.vfptr = (HashTable<unsigned long,StateDesc,0>Vtbl *)HashTable<unsigned long,StateDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>(
    &v1->m_states.m_intrusiveTable,
    0x17u);
  v1->m_children.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(
    &v1->m_children.m_intrusiveTable,
    0x17u);
  v1->m_uiReadOrder = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strComments.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  PStringBase<char>::PStringBase<char>(&v1->m_strName, &name);
}
// 79BD34: using guessed type int (__thiscall *ElementDesc::vftable)(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 800E40: using guessed type int (__thiscall *HashTable<unsigned long,StateDesc,0>::vftable[2])(void *, char);

//----- (0069B3D0) --------------------------------------------------------  // acclient.c:691409
StateDesc *__thiscall ElementDesc::operator=(StateDesc *this, StateDesc *_rhs)
{
  StateDesc *v2; // esi@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@2
  int v4; // ebx@3
  HashTableData<unsigned long,BaseProperty> *v5; // eax@6
  HashTableData<unsigned long,BaseProperty> *v6; // eax@7
  int v7; // ebx@8
  HashTableData<unsigned long,BaseProperty> *v8; // edi@11

  v2 = this;
  if ( this != _rhs )
  {
    StateDesc::operator=(this, _rhs);
    v2[1].vfptr = _rhs[1].vfptr;
    v2[1].m_uiIncorporationFlags = _rhs[1].m_uiIncorporationFlags;
    v2[1].m_stateID = _rhs[1].m_stateID;
    *(_DWORD *)&v2[1].m_bIsCode = *(_DWORD *)&_rhs[1].m_bIsCode;
    v2[1].m_x = _rhs[1].m_x;
    v2[1].m_y = _rhs[1].m_y;
    v2[1].m_width = _rhs[1].m_width;
    v2[1].m_height = _rhs[1].m_height;
    v2[1].m_zLevel = _rhs[1].m_zLevel;
    v2[1].m_properties.vfptr = _rhs[1].m_properties.vfptr;
    HashTable<unsigned long,StateDesc,0>::operator=(
      (int)&v2[1].m_properties.m_hashProperties,
      (unsigned int)&_rhs[1].m_properties.m_hashProperties);
    HashTable<unsigned long,ElementDesc,0>::operator=((int)&v2[1].m_media, (unsigned int)&_rhs[1].m_media);
    v2[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[14] = _rhs[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[14];
    v3 = v2[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[15];
    if ( v3 != _rhs[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[15] )
    {
      v4 = (int)&v3[-2].m_data.m_pcPropertyValue;
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      v5 = _rhs[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[15];
      v2[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[15] = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1]);
    }
    v6 = v2[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[16];
    if ( v6 != _rhs[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[16] )
    {
      v7 = (int)&v6[-2].m_data.m_pcPropertyValue;
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = _rhs[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[16];
      v2[2].m_properties.m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[16] = v8;
      InterlockedIncrement((volatile LONG *)&v8[-1]);
    }
  }
  return v2;
}

//----- (0069B520) --------------------------------------------------------  // acclient.c:691463
void __thiscall ElementDesc::ElementDesc(ElementDesc *this, ElementDesc *_rhs)
{
  ElementDesc *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v2 = this;
  StateDesc::StateDesc((StateDesc *)&this->vfptr);
  v2->vfptr = (StateDescVtbl *)&ElementDesc::vftable;
  v2->m_states.vfptr = (HashTable<unsigned long,StateDesc,0>Vtbl *)HashTable<unsigned long,StateDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>(
    &v2->m_states.m_intrusiveTable,
    0x17u);
  v2->m_children.vfptr = (HashTable<unsigned long,ElementDesc,0>Vtbl *)HashTable<unsigned long,ElementDesc,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>(
    &v2->m_children.m_intrusiveTable,
    0x17u);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_strComments.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v2->m_strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  ElementDesc::operator=((StateDesc *)&v2->vfptr, (StateDesc *)&_rhs->vfptr);
}
// 79BD34: using guessed type int (__thiscall *ElementDesc::vftable)(void *, char);
// 800AC4: using guessed type int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char);
// 800E40: using guessed type int (__thiscall *HashTable<unsigned long,StateDesc,0>::vftable[2])(void *, char);

//----- (0069B5A0) --------------------------------------------------------  // acclient.c:691493
bool __thiscall ElementDesc::Incorporate(ElementDesc *this, ElementDesc *_desc)
{
  ElementDesc *v2; // esi@1
  int v3; // ecx@1
  int v4; // edx@1
  int v5; // eax@1
  int v6; // ecx@1
  int v7; // edx@1
  int v8; // eax@3
  int v9; // ebx@3
  int v10; // edx@3
  unsigned int v11; // eax@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v12; // eax@3
  HashTableData<unsigned long,StateDesc> *v13; // edi@3
  HashTableData<unsigned long,StateDesc> **v14; // ebp@3
  ElementDesc *v15; // ecx@4
  int v16; // edx@4
  HashTableData<unsigned long,StateDesc> **v17; // eax@4
  HashTableData<unsigned long,StateDesc> *v18; // edx@4
  int v19; // ecx@13
  HashTableData<unsigned long,ElementDesc> **v20; // eax@14
  int v21; // eax@15
  HashTableData<unsigned long,ElementDesc> **v22; // eax@16
  HashTableData<unsigned long,ElementDesc> *v23; // ecx@16
  StateDesc *v24; // edx@18
  HashTableData<unsigned long,ElementDesc> **v25; // ebp@22
  unsigned int v26; // ebx@23
  int v27; // edx@24
  HashTableData<unsigned long,ElementDesc> **v28; // edx@35
  HashTableData<unsigned long,ElementDesc> **v29; // eax@36
  HashTableData<unsigned long,ElementDesc> **v30; // eax@37
  HashTableData<unsigned long,StateDesc> **v31; // ecx@38
  HashTableData<unsigned long,StateDesc> *v32; // eax@38
  HashTableData<unsigned long,StateDesc> *v33; // edi@41
  HashTableData<unsigned long,StateDesc> **v34; // ebp@41
  unsigned int v35; // ebx@42
  HashTableData<unsigned long,ElementDesc> *v36; // edx@42
  void *v37; // eax@45
  void *v38; // edi@45
  ElementDesc *v39; // ST1C_4@46
  ElementDesc *v40; // edx@48
  int v41; // ecx@52
  int v42; // eax@52
  HashTableData<unsigned long,ElementDesc> *v43; // edx@61
  int v44; // edx@64
  HashTableData<unsigned long,ElementDesc> **v45; // eax@67
  HashTableData<unsigned long,StateDesc> *v46; // ecx@69
  int v47; // ecx@74
  HashTableData<unsigned long,StateDesc> **v48; // eax@75
  int v49; // eax@76
  HashTableData<unsigned long,StateDesc> **v50; // eax@77
  HashTableData<unsigned long,StateDesc> *v51; // edi@77
  HashTableData<unsigned long,StateDesc> **v52; // ebp@81
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v53; // ebx@82
  HashTableData<unsigned long,StateDesc> *v54; // edx@83
  int v55; // ecx@93
  HashTableData<unsigned long,ElementDesc> **v56; // eax@94
  int v57; // eax@95
  HashTableData<unsigned long,ElementDesc> **v58; // eax@96
  HashTableData<unsigned long,ElementDesc> *v59; // edi@96
  HashTableData<unsigned long,ElementDesc> **v60; // ebp@98
  HashTableData<unsigned long,ElementDesc> *v61; // edx@99
  bool retval; // [sp+31h] [bp-45h]@1
  unsigned int nInheritedChildren; // [sp+32h] [bp-44h]@13
  ElementDesc *desc; // [sp+36h] [bp-40h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *v66; // [sp+3Ah] [bp-3Ch]@3
  HashIterator<unsigned long,StateDesc,0> s_iter; // [sp+3Eh] [bp-38h]@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+4Ah] [bp-2Ch]@3
  Box2D new_size; // [sp+56h] [bp-20h]@3
  Box2D old_size; // [sp+66h] [bp-10h]@1

  v2 = this;
  v3 = this->m_x;
  v4 = v2->m_width;
  v5 = v2->m_y;
  old_size.m_x0 = v3;
  v6 = v4 + v3 - 1;
  v7 = v2->m_height;
  old_size.m_y0 = v5;
  old_size.m_x1 = v6;
  retval = 1;
  old_size.m_y1 = v7 + v5 - 1;
  if ( !StateDesc::Incorporate((StateDesc *)&v2->vfptr, (StateDesc *)&_desc->vfptr) )
    retval = 0;
  v8 = v2->m_y;
  v9 = v2->m_width + v2->m_x - 1;
  new_size.m_x0 = v2->m_x;
  v10 = v2->m_height + v8 - 1;
  new_size.m_y0 = v8;
  v2->m_elementID = _desc->m_elementID;
  v2->m_defaultState = _desc->m_defaultState;
  new_size.m_y1 = v10;
  v2->m_leftEdge = _desc->m_leftEdge;
  v2->m_topEdge = _desc->m_topEdge;
  v2->m_rightEdge = _desc->m_rightEdge;
  v2->m_bottomEdge = _desc->m_bottomEdge;
  v11 = _desc->m_uiReadOrder;
  new_size.m_x1 = v9;
  v2->m_uiReadOrder = v11;
  v66 = &_desc->m_states.m_intrusiveTable;
  v12 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&_desc->m_states.m_intrusiveTable,
          &result);
  v13 = (HashTableData<unsigned long,StateDesc> *)v12->m_currElement;
  v14 = (HashTableData<unsigned long,StateDesc> **)v12->m_currBucket;
  s_iter.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)v12->m_currHashTable;
  if ( v13 )
  {
    do
    {
LABEL_4:
      v15 = (ElementDesc *)v13->m_hashKey;
      v16 = v13->m_hashKey % v2->m_states.m_intrusiveTable.m_numBuckets;
      v17 = v2->m_states.m_intrusiveTable.m_buckets;
      desc = (ElementDesc *)v13->m_hashKey;
      v18 = v17[v16];
      if ( !v18 )
        goto LABEL_7;
      while ( (ElementDesc *)v18->m_hashKey != v15 )
      {
        v18 = v18->m_hashNext;
        if ( !v18 )
          goto LABEL_7;
      }
      if ( v18 && (v24 = &v18->m_data) != 0 )
      {
        if ( !StateDesc::Incorporate(v24, &v13->m_data) )
          retval = 0;
      }
      else
      {
LABEL_7:
        HashTable<unsigned long,StateDesc,0>::add(&v2->m_states, (const unsigned int *)&desc, &v13->m_data);
      }
      v13 = v13->m_hashNext;
    }
    while ( v13 );
    while ( 1 )
    {
      ++v14;
      if ( v14 == &s_iter.m_iter.m_currHashTable->m_buckets[s_iter.m_iter.m_currHashTable->m_numBuckets] )
        break;
      if ( *v14 )
      {
        v13 = *v14;
        if ( *v14 )
          goto LABEL_4;
        break;
      }
    }
    v9 = new_size.m_x1;
  }
  v19 = (int)&v2->m_children.m_intrusiveTable.m_buckets[v2->m_children.m_intrusiveTable.m_numBuckets];
  nInheritedChildren = 0;
  if ( v2->m_children.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,ElementDesc> **)v19 )
  {
LABEL_16:
    v22 = 0;
    v23 = 0;
  }
  else
  {
    while ( 1 )
    {
      v20 = v2->m_children.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v20 )
        break;
      v21 = (int)(v20 + 1);
      v2->m_children.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,ElementDesc> **)v21;
      if ( v21 == v19 )
        goto LABEL_16;
    }
    v22 = v2->m_children.m_intrusiveTable.m_firstInterestingBucket;
    v23 = *v22;
  }
  v25 = v22;
  if ( v23 )
  {
    v26 = _desc->m_children.m_intrusiveTable.m_numBuckets;
    desc = (ElementDesc *)_desc->m_children.m_intrusiveTable.m_buckets;
    do
    {
LABEL_24:
      v27 = *((_DWORD *)&desc->vfptr + v23->m_hashKey % v26);
      if ( !v27 )
        goto LABEL_29;
      while ( *(_DWORD *)v27 != v23->m_hashKey )
      {
        v27 = *(_DWORD *)(v27 + 4);
        if ( !v27 )
          goto LABEL_29;
      }
      if ( !v27 )
LABEL_29:
        ++nInheritedChildren;
      v23 = v23->m_hashNext;
    }
    while ( v23 );
    while ( 1 )
    {
      ++v25;
      if ( v25 == &v2->m_children.m_intrusiveTable.m_buckets[v2->m_children.m_intrusiveTable.m_numBuckets] )
        break;
      v23 = *v25;
      if ( *v25 )
      {
        if ( v23 )
          goto LABEL_24;
        break;
      }
    }
    v9 = new_size.m_x1;
  }
  v28 = &_desc->m_children.m_intrusiveTable.m_buckets[_desc->m_children.m_intrusiveTable.m_numBuckets];
  if ( _desc->m_children.m_intrusiveTable.m_firstInterestingBucket == v28 )
  {
LABEL_38:
    v31 = 0;
    v32 = 0;
  }
  else
  {
    while ( 1 )
    {
      v29 = _desc->m_children.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v29 )
        break;
      v30 = v29 + 1;
      _desc->m_children.m_intrusiveTable.m_firstInterestingBucket = v30;
      if ( v30 == v28 )
        goto LABEL_38;
    }
    v31 = (HashTableData<unsigned long,StateDesc> **)_desc->m_children.m_intrusiveTable.m_firstInterestingBucket;
    v32 = *v31;
  }
  s_iter.m_iter.m_currBucket = v31;
  s_iter.m_iter.m_currElement = v32;
  if ( v32 )
  {
    v33 = v32;
    v34 = v31;
    do
    {
LABEL_42:
      v35 = v33->m_hashKey;
      desc = (ElementDesc *)&v33->m_data;
      v36 = v2->m_children.m_intrusiveTable.m_buckets[v35 % v2->m_children.m_intrusiveTable.m_numBuckets];
      if ( !v36 )
        goto LABEL_45;
      while ( v36->m_hashKey != v35 )
      {
        v36 = v36->m_hashNext;
        if ( !v36 )
          goto LABEL_45;
      }
      if ( v36 && (v40 = &v36->m_data) != 0 )
      {
        if ( !ElementDesc::Incorporate(v40, desc) )
          retval = 0;
      }
      else
      {
LABEL_45:
        v37 = operator new(0x1CCu);
        v38 = v37;
        if ( v37 )
        {
          v39 = desc;
          *(_DWORD *)v37 = v35;
          *((_DWORD *)v37 + 1) = 0;
          ElementDesc::ElementDesc((ElementDesc *)((char *)v37 + 8), v39);
        }
        else
        {
          v38 = 0;
        }
        v41 = (int)&v2->m_children.m_intrusiveTable.m_buckets[*(_DWORD *)v38
                                                            % v2->m_children.m_intrusiveTable.m_numBuckets];
        v42 = *(_DWORD *)v41;
        if ( !*(_DWORD *)v41 )
          goto LABEL_57;
        while ( *(_DWORD *)v42 != *(_DWORD *)v38 )
        {
          v42 = *(_DWORD *)(v42 + 4);
          if ( !v42 )
            goto LABEL_57;
        }
        if ( v42 )
        {
          ElementDesc::~ElementDesc((ElementDesc *)((char *)v38 + 8));
          operator delete(v38);
        }
        else
        {
LABEL_57:
          *((_DWORD *)v38 + 1) = *(_DWORD *)v41;
          *(_DWORD *)v41 = v38;
          if ( (HashTableData<unsigned long,ElementDesc> **)v41 < v2->m_children.m_intrusiveTable.m_firstInterestingBucket )
            v2->m_children.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,ElementDesc> **)v41;
          ++v2->m_children.m_intrusiveTable.m_numElements;
        }
        v43 = v2->m_children.m_intrusiveTable.m_buckets[v35 % v2->m_children.m_intrusiveTable.m_numBuckets];
        if ( !v43 )
          goto LABEL_64;
        while ( v43->m_hashKey != v35 )
        {
          v43 = v43->m_hashNext;
          if ( !v43 )
            goto LABEL_64;
        }
        if ( v43 )
          v44 = (int)&v43->m_data;
        else
LABEL_64:
          v44 = 0;
        v33 = s_iter.m_iter.m_currElement;
        v34 = s_iter.m_iter.m_currBucket;
        *(_DWORD *)(v44 + 440) += nInheritedChildren;
      }
      v33 = v33->m_hashNext;
      s_iter.m_iter.m_currElement = v33;
    }
    while ( v33 );
    v45 = &_desc->m_children.m_intrusiveTable.m_buckets[_desc->m_children.m_intrusiveTable.m_numBuckets];
    while ( 1 )
    {
      ++v34;
      s_iter.m_iter.m_currBucket = v34;
      if ( (HashTableData<unsigned long,ElementDesc> **)v34 == v45 )
        break;
      v46 = *v34;
      if ( *v34 )
      {
        v33 = *v34;
        s_iter.m_iter.m_currElement = *v34;
        if ( v46 )
          goto LABEL_42;
        break;
      }
    }
    v9 = new_size.m_x1;
  }
  if ( old_size.m_x1 - old_size.m_x0 + 1 != v9 - new_size.m_x0 + 1
    || old_size.m_y1 - old_size.m_y0 + 1 != new_size.m_y1 - new_size.m_y0 + 1 )
  {
    v47 = (int)&v2->m_states.m_intrusiveTable.m_buckets[v2->m_states.m_intrusiveTable.m_numBuckets];
    if ( v2->m_states.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,StateDesc> **)v47 )
    {
LABEL_77:
      v50 = 0;
      v51 = 0;
    }
    else
    {
      while ( 1 )
      {
        v48 = v2->m_states.m_intrusiveTable.m_firstInterestingBucket;
        if ( *v48 )
          break;
        v49 = (int)(v48 + 1);
        v2->m_states.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,StateDesc> **)v49;
        if ( v49 == v47 )
          goto LABEL_77;
      }
      v50 = v2->m_states.m_intrusiveTable.m_firstInterestingBucket;
      v51 = *v50;
    }
    v52 = v50;
    if ( v51 )
    {
      v53 = v66;
      do
      {
LABEL_83:
        v54 = v53->m_buckets[v51->m_hashKey % v53->m_numBuckets];
        if ( !v54 )
          goto LABEL_88;
        while ( v54->m_hashKey != v51->m_hashKey )
        {
          v54 = v54->m_hashNext;
          if ( !v54 )
            goto LABEL_88;
        }
        if ( !v54 )
LABEL_88:
          v51->m_data.vfptr->UpdateSizeAndPosition(
            &v51->m_data,
            &old_size,
            &new_size,
            v2->m_leftEdge,
            v2->m_topEdge,
            v2->m_rightEdge,
            v2->m_bottomEdge);
        v51 = v51->m_hashNext;
      }
      while ( v51 );
      while ( 1 )
      {
        ++v52;
        if ( v52 == &v2->m_states.m_intrusiveTable.m_buckets[v2->m_states.m_intrusiveTable.m_numBuckets] )
          break;
        if ( *v52 )
        {
          v51 = *v52;
          if ( *v52 )
            goto LABEL_83;
          break;
        }
      }
    }
    v55 = (int)&v2->m_children.m_intrusiveTable.m_buckets[v2->m_children.m_intrusiveTable.m_numBuckets];
    if ( v2->m_children.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,ElementDesc> **)v55 )
    {
LABEL_96:
      v58 = 0;
      v59 = 0;
    }
    else
    {
      while ( 1 )
      {
        v56 = v2->m_children.m_intrusiveTable.m_firstInterestingBucket;
        if ( *v56 )
          break;
        v57 = (int)(v56 + 1);
        v2->m_children.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,ElementDesc> **)v57;
        if ( v57 == v55 )
          goto LABEL_96;
      }
      v58 = v2->m_children.m_intrusiveTable.m_firstInterestingBucket;
      v59 = *v58;
    }
    v60 = v58;
    if ( v59 )
    {
      do
      {
LABEL_99:
        v61 = _desc->m_children.m_intrusiveTable.m_buckets[v59->m_hashKey
                                                         % _desc->m_children.m_intrusiveTable.m_numBuckets];
        if ( !v61 )
          goto LABEL_104;
        while ( v61->m_hashKey != v59->m_hashKey )
        {
          v61 = v61->m_hashNext;
          if ( !v61 )
            goto LABEL_104;
        }
        if ( !v61 )
LABEL_104:
          ((void (__stdcall *)(Box2D *, Box2D *, unsigned int, unsigned int, unsigned int, unsigned int))v59->m_data.vfptr->UpdateSizeAndPosition)(
            &old_size,
            &new_size,
            v59->m_data.m_leftEdge,
            v59->m_data.m_topEdge,
            v59->m_data.m_rightEdge,
            v59->m_data.m_bottomEdge);
        v59 = v59->m_hashNext;
      }
      while ( v59 );
      while ( 1 )
      {
        ++v60;
        if ( v60 == &v2->m_children.m_intrusiveTable.m_buckets[v2->m_children.m_intrusiveTable.m_numBuckets] )
          break;
        if ( *v60 )
        {
          v59 = *v60;
          if ( *v60 )
            goto LABEL_99;
          return retval;
        }
      }
    }
  }
  return retval;
}

//----- (0069BBA0) --------------------------------------------------------  // acclient.c:691972
void __thiscall ElementDesc::Serialize(ElementDesc *this, Archive *_io_archive)
{
  Archive *v2; // esi@1
  ElementDesc *v3; // edi@1
  int v4; // ebp@1
  unsigned int v5; // eax@1
  unsigned int v6; // eax@5
  unsigned int v7; // eax@9
  unsigned int v8; // eax@13
  unsigned int v9; // eax@17
  unsigned int v10; // eax@21
  unsigned int v11; // eax@27
  unsigned int v12; // eax@32
  unsigned int v13; // eax@37
  unsigned int v14; // eax@42
  unsigned int v15; // eax@47
  unsigned int v16; // eax@51
  unsigned int v17; // eax@55
  unsigned int v18; // eax@59
  unsigned int v19; // eax@63

  v2 = _io_archive;
  v3 = this;
  v4 = Archive::GetVersionByToken(_io_archive, 0x55494C20u);
  StateDesc::Serialize((StateDesc *)&v3->vfptr, v2);
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->m_uiReadOrder;
    else
      v3->m_uiReadOrder = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v6 = v3->m_elementID;
    else
      v3->m_elementID = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(v2, 4u);
  v7 = Archive::GetBytes(v2, 4u);
  if ( v7 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v7 = v3->m_type;
    else
      v3->m_type = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v3->m_baseElement;
    else
      v3->m_baseElement = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(v2, 4u);
  v9 = Archive::GetBytes(v2, 4u);
  if ( v9 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v9 = v3->m_baseLayout.id;
    else
      v3->m_baseLayout.id = *(_DWORD *)v9;
  }
  Archive::CheckAlignment(v2, 4u);
  v10 = Archive::GetBytes(v2, 4u);
  if ( v10 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v10 = v3->m_defaultState;
    else
      v3->m_defaultState = *(_DWORD *)v10;
  }
  if ( (unsigned int)v4 >= 1 )
  {
    if ( v3->m_uiIncorporationFlags & 2 )
    {
      Archive::CheckAlignment(v2, 4u);
      v11 = Archive::GetBytes(v2, 4u);
      if ( v11 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v11 = v3->m_x;
        else
          v3->m_x = *(_DWORD *)v11;
      }
    }
    if ( v3->m_uiIncorporationFlags & 4 )
    {
      Archive::CheckAlignment(v2, 4u);
      v12 = Archive::GetBytes(v2, 4u);
      if ( v12 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v12 = v3->m_y;
        else
          v3->m_y = *(_DWORD *)v12;
      }
    }
    if ( v3->m_uiIncorporationFlags & 8 )
    {
      Archive::CheckAlignment(v2, 4u);
      v13 = Archive::GetBytes(v2, 4u);
      if ( v13 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v13 = v3->m_width;
        else
          v3->m_width = *(_DWORD *)v13;
      }
    }
    if ( v3->m_uiIncorporationFlags & 0x10 )
    {
      Archive::CheckAlignment(v2, 4u);
      v14 = Archive::GetBytes(v2, 4u);
      if ( v14 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v14 = v3->m_height;
        else
          v3->m_height = *(_DWORD *)v14;
      }
    }
    if ( v3->m_uiIncorporationFlags & 0x20 )
    {
      Archive::CheckAlignment(v2, 4u);
      v15 = Archive::GetBytes(v2, 4u);
      if ( v15 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v15 = v3->m_zLevel;
        else
          v3->m_zLevel = *(_DWORD *)v15;
      }
    }
  }
  Archive::CheckAlignment(v2, 4u);
  v16 = Archive::GetBytes(v2, 4u);
  if ( v16 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v16 = v3->m_leftEdge;
    else
      v3->m_leftEdge = *(_DWORD *)v16;
  }
  Archive::CheckAlignment(v2, 4u);
  v17 = Archive::GetBytes(v2, 4u);
  if ( v17 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v17 = v3->m_topEdge;
    else
      v3->m_topEdge = *(_DWORD *)v17;
  }
  Archive::CheckAlignment(v2, 4u);
  v18 = Archive::GetBytes(v2, 4u);
  if ( v18 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v18 = v3->m_rightEdge;
    else
      v3->m_rightEdge = *(_DWORD *)v18;
  }
  Archive::CheckAlignment(v2, 4u);
  v19 = Archive::GetBytes(v2, 4u);
  if ( v19 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v19 = v3->m_bottomEdge;
    else
      v3->m_bottomEdge = *(_DWORD *)v19;
  }
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::delete_contents(&v3->m_states.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>,HashTableData<unsigned long,StateDesc> *,SB_Default>(
    (const int *)&_io_archive,
    &v3->m_states.m_intrusiveTable,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::delete_contents(&v3->m_children.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>,HashTableData<unsigned long,ElementDesc> *,SB_Default>(
    (const int *)&_io_archive,
    &v3->m_children.m_intrusiveTable,
    v2);
}

//----- (0071BAD0) --------------------------------------------------------  // acclient.c:813955
int sub_71BAD0()
{
  KW_NULL_4.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_7876B0);
}

//----- (0071BAF0) --------------------------------------------------------  // acclient.c:813963
int sub_71BAF0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_0, "Base");
  return atexit(sub_7876E0);
}

//----- (0071BB10) --------------------------------------------------------  // acclient.c:813970
int _E79_96()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_0, "BottomEdge");
  return atexit(_E80_93);
}

//----- (0071BB30) --------------------------------------------------------  // acclient.c:813977
int _E82_61()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_0, "Child");
  return atexit(_E83_57);
}

//----- (0071BB50) --------------------------------------------------------  // acclient.c:813984
int _E85_44()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_0, "Code");
  return atexit(_E86_36);
}

//----- (0071BB70) --------------------------------------------------------  // acclient.c:813991
int _E88_33()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_0, "DefaultState");
  return atexit(_E89_46);
}

//----- (0071BB90) --------------------------------------------------------  // acclient.c:813998
int sub_71BB90()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_0, "DisplayHeight");
  return atexit(_E92_55);
}

//----- (0071BBB0) --------------------------------------------------------  // acclient.c:814005
int _E94_46()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_0, "DisplayWidth");
  return atexit(sub_787800);
}

//----- (0071BBD0) --------------------------------------------------------  // acclient.c:814012
int sub_71BBD0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_0, "DrawMode");
  return atexit(sub_787830);
}

//----- (0071BBF0) --------------------------------------------------------  // acclient.c:814019
int sub_71BBF0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_0, "Duration");
  return atexit(sub_787860);
}

//----- (0071BC10) --------------------------------------------------------  // acclient.c:814026
int sub_71BC10()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_0, "Element");
  return atexit(sub_787890);
}

//----- (0071BC30) --------------------------------------------------------  // acclient.c:814033
int sub_71BC30()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_0, "ElementHeader");
  return atexit(sub_7878C0);
}

//----- (0071BC50) --------------------------------------------------------  // acclient.c:814040
int _E109_94()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_0, "ElementWHeader");
  return atexit(sub_7878F0);
}

//----- (0071BC70) --------------------------------------------------------  // acclient.c:814047
int sub_71BC70()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_0, "ElementID");
  return atexit(_E113_79);
}

//----- (0071BC90) --------------------------------------------------------  // acclient.c:814054
int _E115_98()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_0, "EndAlpha");
  return atexit(_E116_71);
}

//----- (0071BCB0) --------------------------------------------------------  // acclient.c:814061
int _E118_89()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_0, "EngineType");
  return atexit(_E119_94);
}

//----- (0071BCD0) --------------------------------------------------------  // acclient.c:814068
int _E121_80()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_0, "EventID");
  return atexit(sub_7879B0);
}

//----- (0071BCF0) --------------------------------------------------------  // acclient.c:814075
int _E124_80()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_0, "File");
  return atexit(_E125_74);
}

//----- (0071BD10) --------------------------------------------------------  // acclient.c:814082
int _E127_67()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_0, "Frames");
  return atexit(_E128_72);
}

//----- (0071BD30) --------------------------------------------------------  // acclient.c:814089
int _E130_60()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_0, "PREPROC_HEADER");
  return atexit(_E131_61);
}

//----- (0071BD50) --------------------------------------------------------  // acclient.c:814096
int _E133_53()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_0, "Height");
  return atexit(_E134_45);
}

//----- (0071BD70) --------------------------------------------------------  // acclient.c:814103
int _E136_37()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_0, "JumpItemIndex");
  return atexit(_E137_44);
}

//----- (0071BD90) --------------------------------------------------------  // acclient.c:814110
int _E139_37()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_0, "LeftEdge");
  return atexit(_E140_38);
}

//----- (0071BDB0) --------------------------------------------------------  // acclient.c:814117
int _E142_34()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_0, "MaxDuration");
  return atexit(_E143_38);
}

//----- (0071BDD0) --------------------------------------------------------  // acclient.c:814124
int _E145_36()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_0, "Media");
  return atexit(_E146_38);
}

//----- (0071BDF0) --------------------------------------------------------  // acclient.c:814131
int _E148_35()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_0, "MediaType");
  return atexit(_E149_37);
}

//----- (0071BE10) --------------------------------------------------------  // acclient.c:814138
int _E151_33()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_0, "MinDuration");
  return atexit(_E152_38);
}

//----- (0071BE30) --------------------------------------------------------  // acclient.c:814145
int _E154_34()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_0, "NoDBFile");
  return atexit(_E155_34);
}

//----- (0071BE50) --------------------------------------------------------  // acclient.c:814152
int _E157_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_0, "StretchToFullScreen");
  return atexit(_E158_35);
}

//----- (0071BE70) --------------------------------------------------------  // acclient.c:814159
int _E160_34()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_0, "PassToChildren");
  return atexit(_E161_32);
}

//----- (0071BE90) --------------------------------------------------------  // acclient.c:814166
int _E163_27()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_0, "Probability");
  return atexit(_E164_34);
}

//----- (0071BEB0) --------------------------------------------------------  // acclient.c:814173
int _E166_29()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_1, "Properties");
  return atexit(_E167_30);
}

//----- (0071BED0) --------------------------------------------------------  // acclient.c:814180
int _E169_27()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_0, "Remove");
  return atexit(_E170_30);
}

//----- (0071BEF0) --------------------------------------------------------  // acclient.c:814187
int _E172_25()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_0, "RightEdge");
  return atexit(_E173_25);
}

//----- (0071BF10) --------------------------------------------------------  // acclient.c:814194
int _E175_22()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_0, "SoundName");
  return atexit(_E176_27);
}

//----- (0071BF30) --------------------------------------------------------  // acclient.c:814201
int _E178_22()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_0, "SoundTable");
  return atexit(_E179_26);
}

//----- (0071BF50) --------------------------------------------------------  // acclient.c:814208
int _E181_22()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_0, "StartAlpha");
  return atexit(_E182_26);
}

//----- (0071BF70) --------------------------------------------------------  // acclient.c:814215
int _E184_20()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_0, "State");
  return atexit(_E185_23);
}

//----- (0071BF90) --------------------------------------------------------  // acclient.c:814222
int _E187_19()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_0, "StateHeader");
  return atexit(_E188_24);
}

//----- (0071BFB0) --------------------------------------------------------  // acclient.c:814229
int _E190_20()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_0, "StateWHeader");
  return atexit(_E191_23);
}

//----- (0071BFD0) --------------------------------------------------------  // acclient.c:814236
int _E193_19()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_0, "StateID");
  return atexit(_E194_30);
}

//----- (0071BFF0) --------------------------------------------------------  // acclient.c:814243
int _E196_26()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_0, "TopEdge");
  return atexit(_E197_20);
}

//----- (0071C010) --------------------------------------------------------  // acclient.c:814250
int _E199_18()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_0, "Type");
  return atexit(_E200_24);
}

//----- (0071C030) --------------------------------------------------------  // acclient.c:814257
int _E202_22()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_0, "Width");
  return atexit(_E203_23);
}

//----- (0071C050) --------------------------------------------------------  // acclient.c:814264
int _E205_20()
{
  PStringBase<char>::PStringBase<char>(&KW_X_0, "X");
  return atexit(_E206_27);
}

//----- (0071C070) --------------------------------------------------------  // acclient.c:814271
int _E208_24()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_0, "XHotspot");
  return atexit(_E209_21);
}

//----- (0071C090) --------------------------------------------------------  // acclient.c:814278
int _E211_19()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_0, "Y");
  return atexit(_E212_24);
}

//----- (0071C0B0) --------------------------------------------------------  // acclient.c:814285
int _E214_21()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_0, "YHotspot");
  return atexit(_E215_21);
}

//----- (0071C0D0) --------------------------------------------------------  // acclient.c:814292
int _E217_18()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_0, "ZLevel");
  return atexit(_E218_21);
}

//----- (0071C0F0) --------------------------------------------------------  // acclient.c:814299
int _E220_18()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_0, "Comments");
  return atexit(_E221_21);
}

//----- (0071C110) --------------------------------------------------------  // acclient.c:814306
int _E223_19()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_0, "HasAlpha");
  return atexit(_E224_21);
}

//----- (0071C130) --------------------------------------------------------  // acclient.c:814313
int sub_71C130()
{
  return atexit(nullsub_311);
}

//----- (007876B0) --------------------------------------------------------  // acclient.c:927026
void __cdecl sub_7876B0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007876E0) --------------------------------------------------------  // acclient.c:927039
void __cdecl sub_7876E0()
{
  char *v0; // esi@1

  v0 = &KW_BASE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787710) --------------------------------------------------------  // acclient.c:927052
void __cdecl _E80_93()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787740) --------------------------------------------------------  // acclient.c:927065
void __cdecl _E83_57()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787770) --------------------------------------------------------  // acclient.c:927078
void __cdecl _E86_36()
{
  char *v0; // esi@1

  v0 = &KW_CODE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007877A0) --------------------------------------------------------  // acclient.c:927091
void __cdecl _E89_46()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007877D0) --------------------------------------------------------  // acclient.c:927104
void __cdecl _E92_55()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787800) --------------------------------------------------------  // acclient.c:927117
void __cdecl sub_787800()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787830) --------------------------------------------------------  // acclient.c:927130
void __cdecl sub_787830()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787860) --------------------------------------------------------  // acclient.c:927143
void __cdecl sub_787860()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787890) --------------------------------------------------------  // acclient.c:927156
void __cdecl sub_787890()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007878C0) --------------------------------------------------------  // acclient.c:927169
void __cdecl sub_7878C0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007878F0) --------------------------------------------------------  // acclient.c:927182
void __cdecl sub_7878F0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787920) --------------------------------------------------------  // acclient.c:927195
void __cdecl _E113_79()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787950) --------------------------------------------------------  // acclient.c:927208
void __cdecl _E116_71()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787980) --------------------------------------------------------  // acclient.c:927221
void __cdecl _E119_94()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007879B0) --------------------------------------------------------  // acclient.c:927234
void __cdecl sub_7879B0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007879E0) --------------------------------------------------------  // acclient.c:927247
void __cdecl _E125_74()
{
  char *v0; // esi@1

  v0 = &KW_FILE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787A10) --------------------------------------------------------  // acclient.c:927260
void __cdecl _E128_72()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787A40) --------------------------------------------------------  // acclient.c:927273
void __cdecl _E131_61()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787A70) --------------------------------------------------------  // acclient.c:927286
void __cdecl _E134_45()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787AA0) --------------------------------------------------------  // acclient.c:927299
void __cdecl _E137_44()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787AD0) --------------------------------------------------------  // acclient.c:927312
void __cdecl _E140_38()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787B00) --------------------------------------------------------  // acclient.c:927325
void __cdecl _E143_38()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787B30) --------------------------------------------------------  // acclient.c:927338
void __cdecl _E146_38()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787B60) --------------------------------------------------------  // acclient.c:927351
void __cdecl _E149_37()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787B90) --------------------------------------------------------  // acclient.c:927364
void __cdecl _E152_38()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787BC0) --------------------------------------------------------  // acclient.c:927377
void __cdecl _E155_34()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787BF0) --------------------------------------------------------  // acclient.c:927390
void __cdecl _E158_35()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787C20) --------------------------------------------------------  // acclient.c:927403
void __cdecl _E161_32()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787C50) --------------------------------------------------------  // acclient.c:927416
void __cdecl _E164_34()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787C80) --------------------------------------------------------  // acclient.c:927429
void __cdecl _E167_30()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787CB0) --------------------------------------------------------  // acclient.c:927442
void __cdecl _E170_30()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787CE0) --------------------------------------------------------  // acclient.c:927455
void __cdecl _E173_25()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787D10) --------------------------------------------------------  // acclient.c:927468
void __cdecl _E176_27()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787D40) --------------------------------------------------------  // acclient.c:927481
void __cdecl _E179_26()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787D70) --------------------------------------------------------  // acclient.c:927494
void __cdecl _E182_26()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787DA0) --------------------------------------------------------  // acclient.c:927507
void __cdecl _E185_23()
{
  char *v0; // esi@1

  v0 = &KW_STATE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787DD0) --------------------------------------------------------  // acclient.c:927520
void __cdecl _E188_24()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787E00) --------------------------------------------------------  // acclient.c:927533
void __cdecl _E191_23()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787E30) --------------------------------------------------------  // acclient.c:927546
void __cdecl _E194_30()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787E60) --------------------------------------------------------  // acclient.c:927559
void __cdecl _E197_20()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787E90) --------------------------------------------------------  // acclient.c:927572
void __cdecl _E200_24()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787EC0) --------------------------------------------------------  // acclient.c:927585
void __cdecl _E203_23()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787EF0) --------------------------------------------------------  // acclient.c:927598
void __cdecl _E206_27()
{
  char *v0; // esi@1

  v0 = &KW_X_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787F20) --------------------------------------------------------  // acclient.c:927611
void __cdecl _E209_21()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787F50) --------------------------------------------------------  // acclient.c:927624
void __cdecl _E212_24()
{
  char *v0; // esi@1

  v0 = &KW_Y_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787F80) --------------------------------------------------------  // acclient.c:927637
void __cdecl _E215_21()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787FB0) --------------------------------------------------------  // acclient.c:927650
void __cdecl _E218_21()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00787FE0) --------------------------------------------------------  // acclient.c:927663
void __cdecl _E221_21()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788010) --------------------------------------------------------  // acclient.c:927676
void __cdecl _E224_21()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_0.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_0.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

