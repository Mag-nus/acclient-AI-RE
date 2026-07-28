/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GraphicsResource
   Object     : ENGINE\render_base\GraphicsResource.obj
   Functions  : 32
   Addresses  : 00446A30 - 00730CC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00446A30) --------------------------------------------------------  // acclient.c:131014
char __thiscall GraphicsResource::CopyInto(GraphicsResource *this, GraphicsResource *_Target)
{
  _Target->m_bIsLost = this->m_bIsLost;
  _Target->m_bIsThrashable = this->m_bIsThrashable;
  _Target->m_AutoRestore = this->m_AutoRestore;
  _Target->m_nResourceSize = this->m_nResourceSize;
  _Target->m_TimeUsed = this->m_TimeUsed;
  _Target->m_FrameUsed = this->m_FrameUsed;
  return 1;
}

//----- (00446A70) --------------------------------------------------------  // acclient.c:131026
void __thiscall GraphicsResource::SetResourceSize(GraphicsResource *this, const unsigned int _nNewSize)
{
  this->m_nResourceSize = _nNewSize;
}

//----- (00446A80) --------------------------------------------------------  // acclient.c:131032
void __thiscall GraphicsResource::SetResourceIsThrashable(GraphicsResource *this, const bool _b)
{
  this->m_bIsThrashable = _b;
}

//----- (00446A90) --------------------------------------------------------  // acclient.c:131038
void __thiscall GraphicsResource::SetAutoRestore(GraphicsResource *this, const bool _b)
{
  this->m_AutoRestore = _b;
}

//----- (00446AA0) --------------------------------------------------------  // acclient.c:131044
void __thiscall GraphicsResource::MarkResourceAsNotLost(GraphicsResource *this)
{
  this->m_bIsLost = 0;
}

//----- (00446AB0) --------------------------------------------------------  // acclient.c:131050
void __thiscall GraphicsResource::MarkResourceAsLost(GraphicsResource *this)
{
  this->m_bIsLost = 1;
}

//----- (00446AC0) --------------------------------------------------------  // acclient.c:131056
bool __thiscall GraphicsResource::RestoreResource(GraphicsResource *this)
{
  return this->m_bIsLost != 0;
}

//----- (00446AD0) --------------------------------------------------------  // acclient.c:131062
char __thiscall SmartArray<GraphicsResource *,1>::RemoveUnOrderedByIndex(SmartArray<GraphicsResource *,1> *this, unsigned int index)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  char result; // al@4

  v2 = this->m_num;
  if ( index >= v2 )
  {
    result = 0;
  }
  else
  {
    v3 = v2 - 1;
    this->m_num = v3;
    if ( index != v3 )
    {
      this->m_data[index] = this->m_data[v3];
      this->m_data[this->m_num] = 0;
    }
    result = 1;
  }
  return result;
}

//----- (00446B10) --------------------------------------------------------  // acclient.c:131088
void __cdecl _STL::__push_heap(GraphicsResource **__first, int __holeIndex, int __topIndex, GraphicsResource *__val)
{
  int v4; // esi@1
  int v5; // ecx@1
  GraphicsResource *v6; // edx@2
  bool v7; // zf@3
  bool v8; // sf@3
  unsigned __int8 v9; // of@3

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  if ( __holeIndex <= __topIndex )
  {
    __first[__holeIndex] = __val;
  }
  else
  {
    do
    {
      v6 = __first[v5];
      if ( v6->m_TimeUsed >= __val->m_TimeUsed )
        break;
      __first[v4] = v6;
      v4 = v5;
      v9 = __OFSUB__(v5, __topIndex);
      v7 = v5 == __topIndex;
      v8 = v5 - __topIndex < 0;
      v5 = (v5 - 1) / 2;
    }
    while ( !((unsigned __int8)(v8 ^ v9) | v7) );
    __first[v4] = __val;
  }
}

//----- (00446B70) --------------------------------------------------------  // acclient.c:131123
void __cdecl GraphicsResource::UnlinkResource(GraphicsResource *_pResource)
{
  unsigned int v1; // ecx@1
  unsigned int v2; // eax@4
  GraphicsResource *v3; // edx@5

  v1 = _pResource->m_ListIndex;
  if ( v1 != -1 && GraphicsResource::s_Resources.m_num && v1 < GraphicsResource::s_Resources.m_num )
  {
    v2 = GraphicsResource::s_Resources.m_num - 1;
    if ( v1 < GraphicsResource::s_Resources.m_num - 1 )
    {
      v3 = GraphicsResource::s_Resources.m_data[v2];
      GraphicsResource::s_Resources.m_data[v1] = v3;
      v3->m_ListIndex = v1;
    }
    _pResource->m_ListIndex = -1;
    GraphicsResource::s_Resources.m_data[v2] = 0;
    SmartArray<GraphicsResource *,1>::RemoveUnOrderedByIndex(&GraphicsResource::s_Resources, v2);
  }
}

//----- (00446BD0) --------------------------------------------------------  // acclient.c:131146
char __cdecl GraphicsResource::PurgeResources()
{
  unsigned int v0; // edi@1
  GraphicsResource *v1; // esi@2

  v0 = 0;
  if ( GraphicsResource::s_Resources.m_num )
  {
    do
    {
      v1 = GraphicsResource::s_Resources.m_data[v0];
      if ( v1 && !v1->m_bIsLost && v1->vfptr->PurgeResource(GraphicsResource::s_Resources.m_data[v0]) )
      {
        v1->m_bIsLost = 1;
        v0 = -1;
      }
      ++v0;
    }
    while ( v0 < GraphicsResource::s_Resources.m_num );
  }
  return 1;
}

//----- (00446C20) --------------------------------------------------------  // acclient.c:131170
char __cdecl GraphicsResource::RestoreLostResources()
{
  unsigned int v0; // esi@1
  GraphicsResource *v1; // ecx@2

  v0 = 0;
  if ( GraphicsResource::s_Resources.m_num )
  {
    do
    {
      v1 = GraphicsResource::s_Resources.m_data[v0];
      if ( v1->m_bIsLost && v1->m_AutoRestore && (unsigned __int8)((int (*)(void))v1->vfptr->RestoreResource)() )
        v0 = -1;
      ++v0;
    }
    while ( v0 < GraphicsResource::s_Resources.m_num );
  }
  return 1;
}

//----- (00446C60) --------------------------------------------------------  // acclient.c:131191
void __cdecl GraphicsResource::PurgeOldResources(const long double _dAge)
{
  unsigned int v1; // edi@1
  GraphicsResource *v2; // esi@2
  double dTimeNow; // [sp+4h] [bp-8h]@1

  dTimeNow = Timer::local_time;
  v1 = 0;
  if ( GraphicsResource::s_Resources.m_num )
  {
    do
    {
      v2 = GraphicsResource::s_Resources.m_data[v1];
      if ( !v2->m_bIsLost
        && v2->m_bIsThrashable
        && v2->m_FrameUsed != RenderDevice::render_device->m_nFrameStamp
        && v2->m_nResourceSize
        && dTimeNow - v2->m_TimeUsed > _dAge )
      {
        if ( v2->vfptr->PurgeResource(GraphicsResource::s_Resources.m_data[v1]) )
        {
          v2->m_bIsLost = 1;
          v1 = -1;
        }
      }
      ++v1;
    }
    while ( v1 < GraphicsResource::s_Resources.m_num );
  }
}

//----- (00446CF0) --------------------------------------------------------  // acclient.c:131223
void __cdecl _STL::__unguarded_insertion_sort_aux(GraphicsResource **__first, GraphicsResource **__last)
{
  GraphicsResource **i; // edi@1
  GraphicsResource *v3; // ebx@2
  GraphicsResource **v4; // edx@2
  int j; // ecx@2

  for ( i = __first; i != __last; *v4 = v3 )
  {
    v3 = *i;
    v4 = i;
    for ( j = (int)(i - 1); *(double *)(*(_DWORD *)j + 16) > v3->m_TimeUsed; j -= 4 )
    {
      *v4 = *(GraphicsResource **)j;
      v4 = (GraphicsResource **)j;
    }
    ++i;
  }
}

//----- (00446D30) --------------------------------------------------------  // acclient.c:131244
void __cdecl _STL::__adjust_heap(GraphicsResource **__first, int __holeIndex, int __len, GraphicsResource *__val)
{
  int v4; // edx@1
  int v5; // ecx@1
  bool i; // zf@1

  v4 = __holeIndex;
  v5 = 2 * __holeIndex + 2;
  for ( i = v5 == __len; v5 < __len; i = v5 == __len )
  {
    if ( __first[v5 - 1]->m_TimeUsed > __first[v5]->m_TimeUsed )
      --v5;
    __first[v4] = __first[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    __first[v4] = __first[v5 - 1];
    v4 = v5 - 1;
  }
  _STL::__push_heap(__first, v4, __holeIndex, __val);
}

//----- (00446DA0) --------------------------------------------------------  // acclient.c:131269
void __thiscall GraphicsResource::~GraphicsResource(GraphicsResource *this)
{
  this->vfptr = (GraphicsResourceVtbl *)&GraphicsResource::vftable;
  GraphicsResource::UnlinkResource(this);
}
// 79AF64: using guessed type int (__thiscall *GraphicsResource::vftable)(void *, char);

//----- (00446DB0) --------------------------------------------------------  // acclient.c:131277
GraphicsResource **__cdecl _STL::__unguarded_partition(GraphicsResource **__first, GraphicsResource **__last, GraphicsResource *__pivot)
{
  GraphicsResource **v3; // edx@1
  GraphicsResource **i; // ecx@1
  long double v5; // st7@4
  GraphicsResource *v6; // eax@6

  v3 = __last;
  for ( i = __first; ; ++i )
  {
    while ( (*i)->m_TimeUsed < __pivot->m_TimeUsed )
      ++i;
    do
    {
      v5 = (*(v3 - 1))->m_TimeUsed;
      --v3;
    }
    while ( v5 > __pivot->m_TimeUsed );
    if ( i >= v3 )
      break;
    v6 = *i;
    *i = *v3;
    *v3 = v6;
  }
  return i;
}

//----- (00446E00) --------------------------------------------------------  // acclient.c:131305
void __cdecl _STL::__make_heap(GraphicsResource **__first, GraphicsResource **__last)
{
  int v2; // ebx@1
  int v3; // esi@2
  GraphicsResource *v4; // ecx@3

  v2 = __last - __first;
  if ( v2 >= 2 )
  {
    v3 = (v2 - 2) / 2;
    _STL::__adjust_heap(__first, v3, __last - __first, __first[v3]);
    while ( v3 )
    {
      v4 = __first[v3-- - 1];
      _STL::__adjust_heap(__first, v3, v2, v4);
    }
  }
}

//----- (00446E60) --------------------------------------------------------  // acclient.c:131325
GraphicsResource *__thiscall GraphicsResource::scalar_deleting_destructor(GraphicsResource *this, unsigned int a2)
{
  GraphicsResource *v2; // esi@1

  v2 = this;
  this->vfptr = (GraphicsResourceVtbl *)&GraphicsResource::vftable;
  GraphicsResource::UnlinkResource(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79AF64: using guessed type int (__thiscall *GraphicsResource::vftable)(void *, char);

//----- (00446E90) --------------------------------------------------------  // acclient.c:131339
void __cdecl GraphicsResource::ShutdownResourceManager()
{
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&GraphicsResource::s_Resources);
}

//----- (00446EA0) --------------------------------------------------------  // acclient.c:131345
void __cdecl _STL::__insertion_sort(GraphicsResource **__first, GraphicsResource **__last)
{
  GraphicsResource **v2; // esi@1
  GraphicsResource **v3; // edi@2
  size_t v4; // ebx@3
  GraphicsResource *v5; // ecx@4
  GraphicsResource **v6; // edx@8
  int i; // ecx@8
  GraphicsResource *v8; // [sp+Ch] [bp-4h]@4

  v2 = __first;
  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        v5 = *v3;
        v8 = *v3;
        if ( (*v2)->m_TimeUsed <= (*v3)->m_TimeUsed )
        {
          v6 = v3;
          for ( i = (int)&v2[v4 / 4 - 1]; *(double *)(*(_DWORD *)i + 16) > v8->m_TimeUsed; i -= 4 )
          {
            *v6 = *(GraphicsResource **)i;
            v6 = (GraphicsResource **)i;
          }
          v2 = __first;
          *v6 = v8;
        }
        else
        {
          if ( (signed int)v4 > 0 )
          {
            _memmove(&v3[-v4 / 4 + 1], v2, v4);
            v5 = v8;
          }
          *v2 = v5;
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}

//----- (00446F40) --------------------------------------------------------  // acclient.c:131395
void __cdecl _STL::sort_heap(GraphicsResource **__first, GraphicsResource **__last)
{
  signed int v2; // eax@1
  GraphicsResource *v3; // ecx@2
  int v4; // edi@2

  v2 = (char *)__last - (char *)__first;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v3 = *(GraphicsResource **)((char *)__first + v2 - 4);
      v4 = v2 - 4;
      *(GraphicsResource **)((char *)__first + v2 - 4) = *__first;
      _STL::__adjust_heap(__first, 0, (v2 - 4) >> 2, v3);
      v2 = v4;
    }
    while ( (signed int)(v4 & 0xFFFFFFFC) > 4 );
  }
}

//----- (00446F90) --------------------------------------------------------  // acclient.c:131417
void __cdecl GraphicsResource::LinkResource(GraphicsResource *_pResource)
{
  unsigned int v1; // ecx@1
  unsigned int v2; // esi@1
  unsigned int v3; // eax@2

  v1 = GraphicsResource::s_Resources.m_num;
  v2 = GraphicsResource::s_Resources.m_num;
  if ( GraphicsResource::s_Resources.m_num < (GraphicsResource::s_Resources.m_sizeAndDeallocate & 0x7FFFFFFF) )
    goto LABEL_4;
  v3 = SmartArray<UIChildFramework *,1>::get_new_size((GraphicsResource::s_Resources.m_sizeAndDeallocate & 0x7FFFFFFF) + 1);
  if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&GraphicsResource::s_Resources, v3) )
  {
    v1 = GraphicsResource::s_Resources.m_num;
LABEL_4:
    GraphicsResource::s_Resources.m_data[v1] = _pResource;
    ++GraphicsResource::s_Resources.m_num;
    _pResource->m_ListIndex = v2;
    return;
  }
  _pResource->m_ListIndex = v2;
}

//----- (00446FF0) --------------------------------------------------------  // acclient.c:131441
void __cdecl _STL::__final_insertion_sort(GraphicsResource **__first, GraphicsResource **__last)
{
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) <= 64 )
  {
    _STL::__insertion_sort(__first, __last);
  }
  else
  {
    _STL::__insertion_sort(__first, __first + 16);
    _STL::__unguarded_insertion_sort_aux(__first + 16, __last);
  }
}

//----- (00447040) --------------------------------------------------------  // acclient.c:131455
void __cdecl _STL::__partial_sort(GraphicsResource **__first, GraphicsResource **__middle, GraphicsResource **__last)
{
  GraphicsResource **i; // edi@1
  GraphicsResource *v4; // ecx@2

  _STL::__make_heap(__first, __middle);
  for ( i = __middle; i < __last; ++i )
  {
    v4 = *i;
    if ( (*__first)->m_TimeUsed > (*i)->m_TimeUsed )
    {
      *i = *__first;
      _STL::__adjust_heap(__first, 0, __middle - __first, v4);
    }
  }
  _STL::sort_heap(__first, __middle);
}

//----- (004470C0) --------------------------------------------------------  // acclient.c:131474
void __thiscall GraphicsResource::GraphicsResource(GraphicsResource *this)
{
  int v1; // edx@1

  *(_QWORD *)&this->m_TimeUsed = 0i64;
  this->vfptr = (GraphicsResourceVtbl *)&GraphicsResource::vftable;
  this->m_bIsLost = 0;
  this->m_bIsThrashable = 0;
  this->m_AutoRestore = 0;
  this->m_nResourceSize = 0;
  this->m_FrameUsed = -1;
  this->m_ListIndex = -1;
  v1 = HIDWORD(Timer::local_time);
  LODWORD(this->m_TimeUsed) = LODWORD(Timer::local_time);
  HIDWORD(this->m_TimeUsed) = v1;
  if ( RenderDevice::render_device )
    this->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
  GraphicsResource::LinkResource(this);
}
// 79AF64: using guessed type int (__thiscall *GraphicsResource::vftable)(void *, char);

//----- (00447120) --------------------------------------------------------  // acclient.c:131496
void __cdecl _STL::__introsort_loop(GraphicsResource **__first, GraphicsResource **__last, GraphicsResource **__formal, int __depth_limit, MySTLSortFunction_LRU __comp)
{
  GraphicsResource **v5; // ebx@1
  GraphicsResource *v6; // ecx@3
  int v7; // eax@3
  GraphicsResource *v8; // edx@3
  int v9; // esi@3
  int v10; // eax@3
  GraphicsResource **v11; // eax@6
  GraphicsResource **v12; // esi@11
  GraphicsResource **v13; // [sp+Ch] [bp-4h]@3

  v5 = __last;
  if ( (signed int)(((char *)__last - (char *)__first) & 0xFFFFFFFC) > 64 )
  {
    do
    {
      if ( !__depth_limit )
      {
        _STL::__partial_sort(__first, v5, v5);
        return;
      }
      v6 = *__first;
      --__depth_limit;
      v7 = (v5 - __first) / 2;
      v8 = __first[v7];
      v13 = &__first[v7];
      v9 = (int)(v5 - 1);
      v10 = (int)*(v5 - 1);
      if ( (*__first)->m_TimeUsed >= v8->m_TimeUsed )
      {
        if ( v6->m_TimeUsed < *(double *)(v10 + 16) )
          goto LABEL_8;
        v11 = v5 - 1;
        if ( v8->m_TimeUsed >= *(double *)(*(_DWORD *)v9 + 16) )
        {
LABEL_10:
          v11 = v13;
          goto LABEL_11;
        }
      }
      else
      {
        if ( v8->m_TimeUsed < *(double *)(v10 + 16) )
          goto LABEL_10;
        if ( v6->m_TimeUsed >= *(double *)(*(_DWORD *)v9 + 16) )
        {
LABEL_8:
          v11 = __first;
          goto LABEL_11;
        }
        v11 = v5 - 1;
      }
LABEL_11:
      v12 = _STL::__unguarded_partition(__first, v5, *v11);
      _STL::__introsort_loop(v12, v5, 0, __depth_limit, __comp);
      v5 = v12;
    }
    while ( (signed int)(((char *)v12 - (char *)__first) & 0xFFFFFFFC) > 64 );
  }
}

//----- (00447220) --------------------------------------------------------  // acclient.c:131559
void __cdecl _STL::sort(GraphicsResource **__first, GraphicsResource **__last, MySTLSortFunction_LRU __comp)
{
  signed int v3; // eax@2
  int i; // ecx@2

  if ( __first != __last )
  {
    v3 = __last - __first;
    for ( i = 0; v3 != 1; ++i )
      v3 >>= 1;
    _STL::__introsort_loop(__first, __last, 0, 2 * i, __comp);
    _STL::__final_insertion_sort(__first, __last);
  }
}

//----- (00447270) --------------------------------------------------------  // acclient.c:131575
char __cdecl GraphicsResource::DiscardResourceBytes(const unsigned int _nBytesToDiscard)
{
  unsigned int v1; // ecx@1
  unsigned int v2; // eax@1
  const unsigned int v3; // ebx@3
  unsigned int v4; // edi@3
  GraphicsResource *v5; // esi@4
  unsigned int v6; // ebp@6
  char result; // al@13

  _STL::sort(
    GraphicsResource::s_Resources.m_data,
    &GraphicsResource::s_Resources.m_data[GraphicsResource::s_Resources.m_num],
    (MySTLSortFunction_LRU)_nBytesToDiscard);
  v1 = GraphicsResource::s_Resources.m_num;
  v2 = 0;
  if ( GraphicsResource::s_Resources.m_num )
  {
    do
    {
      GraphicsResource::s_Resources.m_data[v2]->m_ListIndex = v2;
      v1 = GraphicsResource::s_Resources.m_num;
      ++v2;
    }
    while ( v2 < GraphicsResource::s_Resources.m_num );
  }
  v3 = 0;
  v4 = 0;
  if ( v1 )
  {
    do
    {
      v5 = GraphicsResource::s_Resources.m_data[v4];
      if ( v5->m_bIsThrashable )
      {
        if ( !v5->m_bIsLost )
        {
          v6 = v5->m_nResourceSize;
          if ( v6 )
          {
            if ( v5->m_FrameUsed != RenderDevice::render_device->m_nFrameStamp
              && v5->vfptr->PurgeResource(GraphicsResource::s_Resources.m_data[v4]) )
            {
              v3 += v6;
              v5->m_bIsLost = 1;
              if ( v3 >= _nBytesToDiscard )
                goto LABEL_13;
              v4 = -1;
            }
          }
        }
      }
      ++v4;
    }
    while ( v4 < GraphicsResource::s_Resources.m_num );
  }
  if ( v3 < _nBytesToDiscard )
    result = 0;
  else
LABEL_13:
    result = 1;
  return result;
}

//----- (006CBDF0) --------------------------------------------------------  // acclient.c:739351
void _E73_38()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_13, PFID_A8R8G8B8);
}

//----- (006CBE00) --------------------------------------------------------  // acclient.c:739357
int _E91_15()
{
  return atexit(_E92_19);
}

//----- (00730CC0) --------------------------------------------------------  // acclient.c:835741
void __cdecl _E92_19()
{
  if ( (GraphicsResource::s_Resources.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](GraphicsResource::s_Resources.m_data);
}

