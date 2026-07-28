/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderUI
   Object     : ENGINE\render_base\RenderUI.obj
   Functions  : 95
   Addresses  : 00448630 - 007369F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00448630) --------------------------------------------------------  // acclient.c:132884
char __cdecl RenderUI::CreateUISurfaceIndexBuffer()
{
  int v0; // eax@3
  char *v1; // eax@5
  char result; // al@5

  if ( RenderUI::s_pUISurfaceIB )
    ((void (__stdcall *)(_DWORD))RenderUI::s_pUISurfaceIB->vfptr->__vecDelDtor)(1);
  RenderUI::s_pUISurfaceIB = 0;
  v0 = Render::CreateIndexBuffer();
  RenderUI::s_pUISurfaceIB = (RenderIndexBuffer *)v0;
  if ( v0
    && (unsigned __int8)(*(int (__thiscall **)(int, signed int, signed int, signed int, signed int, signed int))(*(_DWORD *)v0 + 4))(
                          v0,
                          6,
                          2,
                          1,
                          1,
                          1) )
  {
    v1 = RenderIndexBuffer::Lock(RenderUI::s_pUISurfaceIB);
    *(_WORD *)v1 = 0;
    *((_WORD *)v1 + 1) = 2;
    *((_WORD *)v1 + 2) = 1;
    *((_WORD *)v1 + 3) = 1;
    *((_WORD *)v1 + 4) = 2;
    *((_WORD *)v1 + 5) = 3;
    RenderIndexBuffer::Unlock(RenderUI::s_pUISurfaceIB);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004486B0) --------------------------------------------------------  // acclient.c:132922
bool __cdecl RenderUI::Startup()
{
  return RenderUI::CreateUISurfaceIndexBuffer() != 0;
}

//----- (004486C0) --------------------------------------------------------  // acclient.c:132928
IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *__thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vector_deleting_destructor(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable;
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
// 79B09C: using guessed type int (__thiscall *IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable)(void *, char);

//----- (00448700) --------------------------------------------------------  // acclient.c:132949
void __cdecl RenderUI::RenderObjects()
{
  int v0; // esi@1
  DiskSpace *v1; // ecx@1
  int v2; // esi@8

  v0 = 0;
  RenderUI::s_bCurrentlyRendering = 1;
  RenderUI::s_sceneID = 0;
  v1 = (DiskSpace *)&RenderUI::s_hlObjects;
  if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements )
  {
    if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_ )
      v0 = (int)&RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_[-1];
    else
      v0 = 0;
  }
  for ( ; v0; v0 = v2 - 8 )
  {
    v1 = *(DiskSpace **)(v0 + 16);
    if ( v1[8] )
      (*(void (**)(void))(*(_DWORD *)v1 + 4))();
    v2 = *(_DWORD *)(v0 + 8);
    if ( !v2 )
      break;
  }
  gmNoticeHandler::RecvNotice_PrevSpellSelection(v1);
  RenderUI::s_bCurrentlyRendering = 0;
}
// 839190: using guessed type bool RenderUI::s_bCurrentlyRendering;
// 839194: using guessed type unsigned __int32 RenderUI::s_sceneID;

//----- (00448770) --------------------------------------------------------  // acclient.c:132982
void __cdecl RenderUI::ComputeGameViewport(unsigned int *o_X, unsigned int *o_Y, unsigned int *o_Width, unsigned int *o_Height)
{
  unsigned int v4; // ebp@1
  int v5; // edi@1
  unsigned int v6; // ebx@1
  int v7; // esi@1
  DLListData *v8; // eax@1
  int v9; // edx@5
  int v10; // eax@6
  int v11; // eax@10
  int v12; // eax@14
  int v13; // eax@16

  *o_X = 0;
  *o_Y = 0;
  *o_Width = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
  *o_Height = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
  v4 = 0;
  v5 = RenderDevice::GetDisplayWidth(RenderDevice::render_device) - 1;
  v6 = 0;
  v7 = RenderDevice::GetDisplayHeight(RenderDevice::render_device) - 1;
  v8 = 0;
  if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements )
  {
    if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_ )
      v8 = RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_ - 1;
    else
      v8 = 0;
  }
  v9 = (int)v8;
  if ( v8 )
  {
    do
    {
      v10 = *(_DWORD *)(v9 + 16);
      if ( *(_BYTE *)(v10 + 8) )
      {
        switch ( *(_DWORD *)(v10 + 12) )
        {
          case 3:
            if ( *(_DWORD *)(v10 + 32) + *(_DWORD *)(v10 + 40) > v4 )
              v4 = *(_DWORD *)(v10 + 32) + *(_DWORD *)(v10 + 40);
            break;
          case 4:
            v11 = *(_DWORD *)(v10 + 32) - 1;
            if ( v11 < (unsigned int)v5 )
              v5 = v11;
            break;
          case 1:
            if ( *(_DWORD *)(v10 + 36) + *(_DWORD *)(v10 + 44) > v6 )
              v6 = *(_DWORD *)(v10 + 36) + *(_DWORD *)(v10 + 44);
            break;
          case 2:
            v12 = *(_DWORD *)(v10 + 36) - 1;
            if ( v12 < (unsigned int)v7 )
              v7 = v12;
            break;
          default:
            break;
        }
      }
      v13 = *(_DWORD *)(v9 + 8);
      if ( !v13 )
        break;
      v9 = v13 - 8;
    }
    while ( v13 != 8 );
  }
  if ( v4 >= RenderDevice::GetDisplayWidth(RenderDevice::render_device) - 2 )
    v4 = RenderDevice::GetDisplayWidth(RenderDevice::render_device) - 2;
  if ( v6 >= RenderDevice::GetDisplayHeight(RenderDevice::render_device) - 2 )
    v6 = RenderDevice::GetDisplayHeight(RenderDevice::render_device) - 2;
  if ( v5 <= v4 )
    v5 = v4 + 1;
  if ( v7 <= v6 )
    v7 = v6 + 1;
  *o_X = v4;
  *o_Y = v6;
  *o_Width = v5 - v4 + 1;
  *o_Height = v7 - v6 + 1;
}

//----- (004488E0) --------------------------------------------------------  // acclient.c:133065
void __thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashList<UIObject *,UIObject *,1>::HashListData **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashList<UIObject *,UIObject *,1>::HashListData **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79B09C: using guessed type int (__thiscall *IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable)(void *, char);

//----- (00448970) --------------------------------------------------------  // acclient.c:133098
char __thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::resize_internal(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  char result; // al@2
  HashList<UIObject *,UIObject *,1>::HashListData *v4; // ebx@3
  int v5; // ecx@4
  HashList<UIObject *,UIObject *,1>::HashListData **v6; // eax@5
  int v7; // eax@6
  HashList<UIObject *,UIObject *,1>::HashListData **v8; // edi@7
  HashList<UIObject *,UIObject *,1>::HashListData *v9; // ecx@7
  HashList<UIObject *,UIObject *,1>::HashListData *v10; // eax@9
  HashList<UIObject *,UIObject *,1>::HashListData *v11; // edx@10
  HashList<UIObject *,UIObject *,1>::HashListData *v12; // eax@17
  HashList<UIObject *,UIObject *,1>::HashListData *v13; // edi@18

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
        if ( v2->m_firstInterestingBucket == (HashList<UIObject *,UIObject *,1>::HashListData **)v5 )
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
            v2->m_firstInterestingBucket = (HashList<UIObject *,UIObject *,1>::HashListData **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_22;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_22:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashList<UIObject *,UIObject *,1>::HashListData **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add_internal(v2, v12);
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00448A40) --------------------------------------------------------  // acclient.c:133193
void __cdecl RenderUI::RecalculateClampedPosition()
{
  unsigned int v0; // esi@1
  unsigned int v1; // edi@1
  unsigned int v2; // ebx@1
  unsigned int v3; // ebp@1
  unsigned int height; // [sp+10h] [bp-10h]@1
  unsigned int width; // [sp+14h] [bp-Ch]@1
  unsigned int y; // [sp+18h] [bp-8h]@1
  unsigned int x; // [sp+1Ch] [bp-4h]@1

  RenderUI::ComputeGameViewport(&x, &y, &width, &height);
  v0 = height;
  v1 = width;
  v2 = y;
  v3 = x;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))RenderDevice::render_device->vfptr->SetViewport)(
    x,
    y,
    width,
    height,
    0);
  ECM_UI::SendNotice_UpdateGameView(v3, v2, v1, v0);
}

//----- (00448AA0) --------------------------------------------------------  // acclient.c:133219
char __thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::grow(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::resize_internal(v2, *v3);
}

//----- (00448AF0) --------------------------------------------------------  // acclient.c:133237
HashList<UIObject *,UIObject *,1>::HashListData *__thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::remove(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, UIObject *const *val)
{
  IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // edi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v3; // esi@1

  v2 = this;
  v3 = v2->m_hash.m_buckets[(unsigned int)*val % v2->m_hash.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != (UIObject *)*val )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return 0;
    }
    if ( v3 )
    {
      DLListBase::Remove(&this->m_list, (DLListData *)&v3->dllist_next);
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
        (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)v2,
        (IDClass<_tagDataID,32,0> *)val);
    }
  }
  return v3;
}

//----- (00448B50) --------------------------------------------------------  // acclient.c:133264
void __thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add_internal(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *data)
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::grow(this);
  v3 = &v2->m_buckets[(unsigned int)data->m_hashKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (00448C60) --------------------------------------------------------  // acclient.c:133375
char __thiscall IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add(IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *data)
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v4; // eax@1
  unsigned int v5; // edx@6
  HashList<UIObject *,UIObject *,1>::HashListData **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[(unsigned int)data->m_hashKey % v3];
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
      IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::grow(this);
    v5 = (unsigned int)data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashList<UIObject *,UIObject *,1>::HashListData **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashList<UIObject *,UIObject *,1>::HashListData **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00448CE0) --------------------------------------------------------  // acclient.c:133419
char __thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::place_at_head(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *pMoving)
{
  IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v3; // eax@1
  char *v4; // eax@5
  DLListData *v5; // ecx@5
  char result; // al@6

  v2 = this;
  v3 = v2->m_hash.m_buckets[(unsigned int)pMoving->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != pMoving->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
    DLListBase::Remove(&this->m_list, (DLListData *)&pMoving->dllist_next);
  else
LABEL_4:
    IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add(&this->m_hash, pMoving);
  v4 = (char *)&pMoving->dllist_next;
  pMoving->dllist_next = v2->m_list.head_;
  v5 = v2->m_list.head_;
  if ( v5 )
  {
    v5->dllist_prev = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  else
  {
    v2->m_list.tail_ = (DLListData *)v4;
    v2->m_list.head_ = (DLListData *)v4;
    pMoving->dllist_prev = 0;
    result = 1;
  }
  return result;
}

//----- (00448D60) --------------------------------------------------------  // acclient.c:133463
void __cdecl RenderUI::Shutdown()
{
  int v0; // esi@2
  int v1; // ecx@7
  bool v2; // zf@7
  int v3; // esi@9

  if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements )
  {
    v0 = 0;
    if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements )
    {
      if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_ )
        v0 = (int)&RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_[-1];
      else
        v0 = 0;
    }
    for ( ; v0; v0 = v3 - 8 )
    {
      v1 = *(_DWORD *)(v0 + 16);
      v2 = (*(_DWORD *)(v1 + 4))-- == 1;
      if ( v2 )
        (**(void (__stdcall ***)(_DWORD))v1)(1);
      v3 = *(_DWORD *)(v0 + 8);
      if ( !v3 )
        break;
    }
    HashList<ControlSpecification,unsigned long,1>::flush(&RenderUI::s_hlObjects);
  }
  if ( RenderUI::s_pUISurfaceIB )
    ((void (__stdcall *)(signed int))RenderUI::s_pUISurfaceIB->vfptr->__vecDelDtor)(1);
  RenderUI::s_pUISurfaceIB = 0;
}

//----- (00448DE0) --------------------------------------------------------  // acclient.c:133498
void __cdecl RenderUI::UnlinkObject(UIObject *object)
{
  UIObject *v1; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v2; // eax@2
  int v3; // eax@3

  v1 = object;
  if ( object )
  {
    v2 = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::remove(
           (IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *)&RenderUI::s_hlObjects,
           &object);
    if ( v2 )
    {
      operator delete(v2);
      v3 = v1->m_cRef - 1;
      v1->m_cRef = v3;
      if ( !v3 )
        v1->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v1, 1u);
    }
  }
}

//----- (00448E20) --------------------------------------------------------  // acclient.c:133522
char __thiscall HashList<UIObject *,UIObject *,1>::move_to_head(HashList<UIObject *,UIObject *,1> *this, UIObject *const *keyToMove)
{
  HashList<UIObject *,UIObject *,1>::HashListData *v2; // eax@1
  char result; // al@4

  v2 = this->m_ihlIntrusive.m_hash.m_buckets[(unsigned int)*keyToMove % this->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v2 )
    goto LABEL_10;
  while ( v2->m_hashKey != (UIObject *)*keyToMove )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      return 0;
  }
  if ( v2 )
    result = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::place_at_head(
               &this->m_ihlIntrusive,
               v2);
  else
LABEL_10:
    result = 0;
  return result;
}

//----- (00448E70) --------------------------------------------------------  // acclient.c:133547
char __thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::push_head(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *val)
{
  IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v2; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v3; // eax@1
  char *v4; // eax@4
  DLListData *v5; // ecx@4
  char result; // al@5

  v2 = this;
  v3 = v2->m_hash.m_buckets[(unsigned int)val->m_hashKey % v2->m_hash.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != val->m_hashKey )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add(&this->m_hash, val);
    v4 = (char *)&val->dllist_next;
    val->dllist_next = v2->m_list.head_;
    v5 = v2->m_list.head_;
    if ( v5 )
    {
      v5->dllist_prev = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
    else
    {
      v2->m_list.tail_ = (DLListData *)v4;
      v2->m_list.head_ = (DLListData *)v4;
      val->dllist_prev = 0;
      result = 1;
    }
  }
  return result;
}

//----- (00448EF0) --------------------------------------------------------  // acclient.c:133595
char __thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::insert_after(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *pExisting, HashList<UIObject *,UIObject *,1>::HashListData *pNew)
{
  IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v3; // edi@1
  char result; // al@2

  v3 = this;
  if ( pExisting )
  {
    if ( IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::contains(
           this,
           &pNew->m_hashKey) )
    {
      result = 0;
    }
    else
    {
      IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add(&v3->m_hash, pNew);
      if ( pNew )
      {
        DLListBase::InsertAfter(&v3->m_list, (DLListData *)&pNew->dllist_next, (DLListData *)&pExisting->dllist_next);
        result = 1;
      }
      else
      {
        DLListBase::InsertAfter(&v3->m_list, 0, (DLListData *)&pExisting->dllist_next);
        result = 1;
      }
    }
  }
  else
  {
    result = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::push_head(this, pNew);
  }
  return result;
}

//----- (00448F60) --------------------------------------------------------  // acclient.c:133632
char __thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::place_after(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, HashList<UIObject *,UIObject *,1>::HashListData *pExisting, HashList<UIObject *,UIObject *,1>::HashListData *pMoving)
{
  IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *v3; // edi@1
  char result; // al@2

  v3 = this;
  if ( pExisting )
  {
    if ( IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::contains(
           this,
           &pMoving->m_hashKey) )
    {
      if ( pMoving )
        DLListBase::Remove(&v3->m_list, (DLListData *)&pMoving->dllist_next);
      else
        DLListBase::Remove(&v3->m_list, 0);
    }
    else
    {
      IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::add(&v3->m_hash, pMoving);
    }
    if ( pMoving )
    {
      DLListBase::InsertAfter(&v3->m_list, (DLListData *)&pMoving->dllist_next, (DLListData *)&pExisting->dllist_next);
      result = 1;
    }
    else
    {
      DLListBase::InsertAfter(&v3->m_list, 0, (DLListData *)&pExisting->dllist_next);
      result = 1;
    }
  }
  else
  {
    result = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::place_at_head(
               this,
               pMoving);
  }
  return result;
}

//----- (00448FF0) --------------------------------------------------------  // acclient.c:133674
char __thiscall HashList<UIObject *,UIObject *,1>::push_head(HashList<UIObject *,UIObject *,1> *this, UIObject *const *key, UIObject *const *val)
{
  HashList<UIObject *,UIObject *,1> *v3; // edi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v4; // edx@1
  void *v5; // eax@4
  HashList<UIObject *,UIObject *,1>::HashListData *v6; // esi@5
  char result; // al@7
  char v8; // bl@9

  v3 = this;
  v4 = v3->m_ihlIntrusive.m_hash.m_buckets[(unsigned int)*key % v3->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != (UIObject *)*key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = HashList<UIObject *,UIObject *,1>::move_to_head(this, key);
  }
  else
  {
LABEL_4:
    v5 = operator new(0x14u);
    if ( v5 )
    {
      *(_DWORD *)v5 = *key;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 4) = *val;
      v6 = (HashList<UIObject *,UIObject *,1>::HashListData *)v5;
    }
    else
    {
      v6 = 0;
    }
    v8 = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::push_head(
           &v3->m_ihlIntrusive,
           v6);
    if ( !v8 )
    {
      if ( v6 )
        operator delete(v6);
    }
    result = v8;
  }
  return result;
}

//----- (00449090) --------------------------------------------------------  // acclient.c:133728
char __thiscall HashList<UIObject *,UIObject *,1>::move_to_middle(HashList<UIObject *,UIObject *,1> *this, UIObject *const *keyInsertAfter, UIObject *const *keyToMove)
{
  unsigned int v3; // edi@1
  HashList<UIObject *,UIObject *,1>::HashListData **v4; // ebp@1
  HashList<UIObject *,UIObject *,1>::HashListData *i; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *j; // eax@4
  char result; // al@9

  v3 = this->m_ihlIntrusive.m_hash.m_numBuckets;
  v4 = this->m_ihlIntrusive.m_hash.m_buckets;
  for ( i = v4[(unsigned int)*keyInsertAfter % v3]; i; i = i->m_hashNext )
  {
    if ( i->m_hashKey == (UIObject *)*keyInsertAfter )
      break;
  }
  for ( j = v4[(unsigned int)*keyToMove % v3]; j; j = j->m_hashNext )
  {
    if ( j->m_hashKey == (UIObject *)*keyToMove )
      break;
  }
  if ( i && j )
    result = IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::place_after(
               &this->m_ihlIntrusive,
               i,
               j);
  else
    result = 0;
  return result;
}

//----- (00449100) --------------------------------------------------------  // acclient.c:133759
char __thiscall HashList<UIObject *,UIObject *,1>::insert_after(HashList<UIObject *,UIObject *,1> *this, UIObject *const *keyInsertAfter, UIObject *const *keyNew, UIObject *const *valNew)
{
  HashList<UIObject *,UIObject *,1> *v4; // esi@1
  HashList<UIObject *,UIObject *,1>::HashListData *v5; // edx@1
  char result; // al@4
  void *v7; // eax@9
  void *v8; // edi@10
  HashList<UIObject *,UIObject *,1>::HashListData *v9; // edx@12

  v4 = this;
  v5 = v4->m_ihlIntrusive.m_hash.m_buckets[(unsigned int)*keyInsertAfter % v4->m_ihlIntrusive.m_hash.m_numBuckets];
  if ( !v5 )
    goto LABEL_23;
  while ( v5->m_hashKey != (UIObject *)*keyInsertAfter )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      return 0;
  }
  if ( v5 )
  {
    if ( IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::contains(
           &this->m_ihlIntrusive,
           keyNew) )
    {
      result = HashList<UIObject *,UIObject *,1>::move_to_middle(v4, keyInsertAfter, keyNew);
    }
    else
    {
      v7 = operator new(0x14u);
      if ( v7 )
      {
        *(_DWORD *)v7 = *keyNew;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = *valNew;
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      v9 = v4->m_ihlIntrusive.m_hash.m_buckets[(unsigned int)*keyInsertAfter % v4->m_ihlIntrusive.m_hash.m_numBuckets];
      if ( !v9 )
        goto LABEL_15;
      while ( v9->m_hashKey != (UIObject *)*keyInsertAfter )
      {
        v9 = v9->m_hashNext;
        if ( !v9 )
          goto LABEL_15;
      }
      if ( v9
        && IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::insert_after(
             &v4->m_ihlIntrusive,
             v9,
             (HashList<UIObject *,UIObject *,1>::HashListData *)v8) )
      {
        result = 1;
      }
      else
      {
LABEL_15:
        if ( v8 )
          operator delete(v8);
        result = 0;
      }
    }
  }
  else
  {
LABEL_23:
    result = 0;
  }
  return result;
}

//----- (004491E0) --------------------------------------------------------  // acclient.c:133837
void __cdecl RenderUI::LinkObject(UIObject *object)
{
  UIObject *v1; // edi@1
  int v2; // ecx@2
  int v3; // esi@7
  int v4; // edx@8
  int v5; // eax@8
  char v6; // al@10
  int v7; // ecx@15
  UIObject *pPrev; // [sp+8h] [bp-8h]@8
  HashList<unsigned long,ActionMapValue,1> *v9; // [sp+Ch] [bp-4h]@6

  v1 = object;
  if ( !object )
    return;
  v2 = 0;
  if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements )
  {
    if ( RenderUI::s_hlObjects.m_ihlIntrusive.m_list.tail_ )
      v2 = (int)&RenderUI::s_hlObjects.m_ihlIntrusive.m_list.tail_[-1];
    else
      v2 = 0;
  }
  v9 = &RenderUI::s_hlObjects;
  if ( !v2 )
  {
LABEL_17:
    v6 = HashList<UIObject *,UIObject *,1>::push_head(
           (HashList<UIObject *,UIObject *,1> *)&RenderUI::s_hlObjects,
           &object,
           &object);
    goto LABEL_11;
  }
  v3 = object->m_nDepth;
  while ( 1 )
  {
    v4 = *(_DWORD *)(v2 + 16);
    v5 = *(_DWORD *)(v4 + 16);
    pPrev = *(UIObject **)(v2 + 16);
    if ( v5 != v3 )
      break;
    if ( *(double *)(v4 + 24) <= object->m_tTouchTime )
      goto LABEL_10;
LABEL_15:
    v7 = *(_DWORD *)(v2 + 12);
    if ( v7 )
    {
      v2 = v7 - 8;
      if ( v2 )
        continue;
    }
    goto LABEL_17;
  }
  if ( v5 < v3 )
    goto LABEL_15;
LABEL_10:
  v6 = HashList<UIObject *,UIObject *,1>::insert_after(
         (HashList<UIObject *,UIObject *,1> *)&RenderUI::s_hlObjects,
         &pPrev,
         &object,
         &object);
LABEL_11:
  if ( v6 )
    ++v1->m_cRef;
}

//----- (00449290) --------------------------------------------------------  // acclient.c:133904
void __cdecl RenderUI::LinkObjectAfter(UIObject *object, UIObject *pExistingObjectToDrawAfter)
{
  UIObject *v2; // esi@1

  v2 = object;
  if ( object
    && (!pExistingObjectToDrawAfter
     && HashList<UIObject *,UIObject *,1>::push_head(
          (HashList<UIObject *,UIObject *,1> *)&RenderUI::s_hlObjects,
          &object,
          &object)
     || HashList<UIObject *,UIObject *,1>::insert_after(
          (HashList<UIObject *,UIObject *,1> *)&RenderUI::s_hlObjects,
          &pExistingObjectToDrawAfter,
          &object,
          &object)) )
    ++v2->m_cRef;
}

//----- (00684800) --------------------------------------------------------  // acclient.c:667964
bool __thiscall IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::contains(IntrusiveHashList<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *this, UIObject *const *val)
{
  HashList<UIObject *,UIObject *,1>::HashListData *v2; // eax@1
  bool v3; // zf@1

  v2 = this->m_hash.m_buckets[(unsigned int)*val % this->m_hash.m_numBuckets];
  v3 = v2 == 0;
  if ( v2 )
  {
    do
    {
      if ( v2->m_hashKey == (UIObject *)*val )
        break;
      v2 = v2->m_hashNext;
    }
    while ( v2 );
    v3 = v2 == 0;
  }
  return !v3;
}

//----- (006CFB80) --------------------------------------------------------  // acclient.c:742710
void _E73_41()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_16, PFID_A8R8G8B8);
}

//----- (006CFB90) --------------------------------------------------------  // acclient.c:742716
void _E91_18()
{
  LODWORD(dword_8391E8) = 1053364187;
}

//----- (006CFBA0) --------------------------------------------------------  // acclient.c:742722
void _E93_6()
{
  outside_val_13 = 1000.0 + 1.0;
}

//----- (006CFBC0) --------------------------------------------------------  // acclient.c:742728
void _E95_6()
{
  block_length_13 = 24.0 * 8.0;
}

//----- (006CFBE0) --------------------------------------------------------  // acclient.c:742734
void _E97_17()
{
  half_square_length_13 = 24.0 * 0.5;
}

//----- (006CFC00) --------------------------------------------------------  // acclient.c:742740
int _E99_2()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_8, "Render.TextureFiltering");
  return atexit(sub_7363C0);
}

//----- (006CFC20) --------------------------------------------------------  // acclient.c:742747
int _E102_6()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_8, "Render.LandscapeDetailTextures");
  return atexit(sub_7363F0);
}

//----- (006CFC40) --------------------------------------------------------  // acclient.c:742754
int _E105_2()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_8, "Render.BuildingDetailTextures");
  return atexit(sub_736420);
}

//----- (006CFC60) --------------------------------------------------------  // acclient.c:742761
int _E108_5()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_8, "Render.FieldOfView");
  return atexit(sub_736450);
}

//----- (006CFC80) --------------------------------------------------------  // acclient.c:742768
int _E111_3()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_8, "Render.LandscapeTextureDetail");
  return atexit(sub_736480);
}

//----- (006CFCA0) --------------------------------------------------------  // acclient.c:742775
int _E114_5()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_8, "Render.EnvironmentTextureDetail");
  return atexit(sub_7364B0);
}

//----- (006CFCC0) --------------------------------------------------------  // acclient.c:742782
int _E117_3()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_8, "Render.SceneryDrawDistance");
  return atexit(sub_7364E0);
}

//----- (006CFCE0) --------------------------------------------------------  // acclient.c:742789
int _E120_5()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_8, "Render.LandscapeDrawDistance");
  return atexit(sub_736510);
}

//----- (006CFD00) --------------------------------------------------------  // acclient.c:742796
int _E123_3()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_8, "Render.ScreenBrightness");
  return atexit(_E124_97);
}

//----- (006CFD20) --------------------------------------------------------  // acclient.c:742803
int _E126_6()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_8, "Render.AspectRatio");
  return atexit(_E127_87);
}

//----- (006CFD40) --------------------------------------------------------  // acclient.c:742810
int _E129_5()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_8, "Render.DisplayAdapter");
  return atexit(_E130_79);
}

//----- (006CFD60) --------------------------------------------------------  // acclient.c:742817
int _E132_6()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_8, "Render.MaxHardwareClass");
  return atexit(_E133_72);
}

//----- (006CFD80) --------------------------------------------------------  // acclient.c:742824
int _E135_5()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_8, "Render.AutomaticDegrades");
  return atexit(_E136_56);
}

//----- (006CFDA0) --------------------------------------------------------  // acclient.c:742831
int _E138_6()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_8, "Render.GraphicsPerformance");
  return atexit(_E139_57);
}

//----- (006CFDC0) --------------------------------------------------------  // acclient.c:742838
int _E141_6()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_8, "Render.DegradeDistance");
  return atexit(_E142_54);
}

//----- (006CFDE0) --------------------------------------------------------  // acclient.c:742845
int _E144_6()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_8, "Render.MultiPassAlpha");
  return atexit(_E145_56);
}

//----- (006CFE00) --------------------------------------------------------  // acclient.c:742852
int _E147_6()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_8, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_839240, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_839244, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_839248, "Anisotropic");
  return atexit(_E148_55);
}

//----- (006CFE50) --------------------------------------------------------  // acclient.c:742862
int _E150_6()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_8, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839250, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839254, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_839258, "High");
  PStringBase<char>::PStringBase<char>(&stru_83925C, "VeryHigh");
  return atexit(_E151_53);
}

//----- (006CFEB0) --------------------------------------------------------  // acclient.c:742873
int _E153_6()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_8, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839264, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839268, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83926C, "High");
  PStringBase<char>::PStringBase<char>(&stru_839270, "VeryHigh");
  return atexit(_E154_54);
}

//----- (006CFF10) --------------------------------------------------------  // acclient.c:742884
int _E156_7()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839278, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83927C, "High");
  return atexit(_E157_51);
}

//----- (006CFF50) --------------------------------------------------------  // acclient.c:742893
int _E159_6()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_8, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_839284, "Low");
  PStringBase<char>::PStringBase<char>(&stru_839288, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83928C, "High");
  PStringBase<char>::PStringBase<char>(&stru_839290, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_839294, "Extreme");
  return atexit(_E160_54);
}

//----- (006CFFC0) --------------------------------------------------------  // acclient.c:742905
int _E162_7()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_8, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83929C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8392A0, "Wide");
  return atexit(_E163_47);
}

//----- (006D0000) --------------------------------------------------------  // acclient.c:742914
int _E165_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_14, "None");
  return atexit(_E166_49);
}

//----- (006D0020) --------------------------------------------------------  // acclient.c:742921
int _E168_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_14, "Speed");
  return atexit(_E169_48);
}

//----- (006D0040) --------------------------------------------------------  // acclient.c:742928
int _E171_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_14, "Noise");
  return atexit(_E172_46);
}

//----- (006D0060) --------------------------------------------------------  // acclient.c:742935
int _E174_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_14, "Sine");
  return atexit(_E175_43);
}

//----- (006D0080) --------------------------------------------------------  // acclient.c:742942
int _E177_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_14, "Square");
  return atexit(_E178_43);
}

//----- (006D00A0) --------------------------------------------------------  // acclient.c:742949
int _E180_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_14, "Bounce");
  return atexit(_E181_43);
}

//----- (006D00C0) --------------------------------------------------------  // acclient.c:742956
int _E183_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_14, "Perlin");
  return atexit(_E184_41);
}

//----- (006D00E0) --------------------------------------------------------  // acclient.c:742963
int _E186_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_14, "Fractal");
  return atexit(_E187_40);
}

//----- (006D0100) --------------------------------------------------------  // acclient.c:742970
int _E189_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_14, "FrameLoop");
  return atexit(_E190_41);
}

//----- (006D0120) --------------------------------------------------------  // acclient.c:742977
int _E192_6()
{
  IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>(
    (IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1> *)&RenderUI::s_hlObjects,
    0);
  RenderUI::s_hlObjects.m_ihlIntrusive.m_list.head_ = 0;
  RenderUI::s_hlObjects.m_ihlIntrusive.m_list.tail_ = 0;
  return atexit(_E193_37);
}

//----- (006D0150) --------------------------------------------------------  // acclient.c:742988
int _E1_37()
{
  return atexit(_E2_37);
}

//----- (007363C0) --------------------------------------------------------  // acclient.c:841858
void __cdecl sub_7363C0()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007363F0) --------------------------------------------------------  // acclient.c:841871
void __cdecl sub_7363F0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736420) --------------------------------------------------------  // acclient.c:841884
void __cdecl sub_736420()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736450) --------------------------------------------------------  // acclient.c:841897
void __cdecl sub_736450()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736480) --------------------------------------------------------  // acclient.c:841910
void __cdecl sub_736480()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007364B0) --------------------------------------------------------  // acclient.c:841923
void __cdecl sub_7364B0()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007364E0) --------------------------------------------------------  // acclient.c:841936
void __cdecl sub_7364E0()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736510) --------------------------------------------------------  // acclient.c:841949
void __cdecl sub_736510()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736540) --------------------------------------------------------  // acclient.c:841962
void __cdecl _E124_97()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736570) --------------------------------------------------------  // acclient.c:841975
void __cdecl _E127_87()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007365A0) --------------------------------------------------------  // acclient.c:841988
void __cdecl _E130_79()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007365D0) --------------------------------------------------------  // acclient.c:842001
void __cdecl _E133_72()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736600) --------------------------------------------------------  // acclient.c:842014
void __cdecl _E136_56()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736630) --------------------------------------------------------  // acclient.c:842027
void __cdecl _E139_57()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736660) --------------------------------------------------------  // acclient.c:842040
void __cdecl _E142_54()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736690) --------------------------------------------------------  // acclient.c:842053
void __cdecl _E145_56()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007366C0) --------------------------------------------------------  // acclient.c:842066
void __cdecl _E148_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_8;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00736700) --------------------------------------------------------  // acclient.c:842091
void __cdecl _E151_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_8;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00736740) --------------------------------------------------------  // acclient.c:842116
void __cdecl _E154_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_8;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00736780) --------------------------------------------------------  // acclient.c:842141
void __cdecl _E157_51()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_8;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007367C0) --------------------------------------------------------  // acclient.c:842166
void __cdecl _E160_54()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_8;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00736800) --------------------------------------------------------  // acclient.c:842191
void __cdecl _E163_47()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_14;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00736840) --------------------------------------------------------  // acclient.c:842216
void __cdecl _E166_49()
{
  char *v0; // esi@1

  v0 = &waveform_None_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736870) --------------------------------------------------------  // acclient.c:842229
void __cdecl _E169_48()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007368A0) --------------------------------------------------------  // acclient.c:842242
void __cdecl _E172_46()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007368D0) --------------------------------------------------------  // acclient.c:842255
void __cdecl _E175_43()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736900) --------------------------------------------------------  // acclient.c:842268
void __cdecl _E178_43()
{
  char *v0; // esi@1

  v0 = &waveform_Square_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736930) --------------------------------------------------------  // acclient.c:842281
void __cdecl _E181_43()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736960) --------------------------------------------------------  // acclient.c:842294
void __cdecl _E184_41()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00736990) --------------------------------------------------------  // acclient.c:842307
void __cdecl _E187_40()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007369C0) --------------------------------------------------------  // acclient.c:842320
void __cdecl _E190_41()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007369F0) --------------------------------------------------------  // acclient.c:842333
void __cdecl _E193_37()
{
  IntrusiveHashList<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::delete_contents(&RenderUI::s_hlObjects.m_ihlIntrusive);
  RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.vfptr = (IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>Vtbl *)&IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable;
  if ( (HashList<unsigned long,ActionMapValue,1>::HashListData **)RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_buckets != RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_aInplaceBuckets )
    operator delete[](RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_buckets);
  RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_buckets = 0;
  RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_firstInterestingBucket = 0;
  RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numBuckets = 0;
  RenderUI::s_hlObjects.m_ihlIntrusive.m_hash.m_numElements = 0;
}
// 79B09C: using guessed type int (__thiscall *IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable)(void *, char);

