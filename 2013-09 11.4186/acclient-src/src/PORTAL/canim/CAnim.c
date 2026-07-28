/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CAnim
   Object     : PORTAL\canim\CAnim.obj
   Functions  : 19
   Addresses  : 0051F640 - 006FD520 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051F640) --------------------------------------------------------  // acclient.c:333648
unsigned int __thiscall AnimFrame::pack_size(AnimFrame *this, unsigned int num_parts)
{
  CAnimHook *v2; // esi@1
  unsigned int i; // edi@1
  int v4; // eax@2

  v2 = this->hooks;
  for ( i = 28 * num_parts + 4; v2; i += v4 )
  {
    v4 = CAnimHook::PackSize(v2);
    v2 = v2->next_hook;
  }
  return i;
}

//----- (0051F670) --------------------------------------------------------  // acclient.c:333664
void __thiscall AFrame::AFrame(AFrame *this)
{
  LODWORD(this->m_fOrigin.x) = 0;
  LODWORD(this->m_fOrigin.y) = 0;
  LODWORD(this->m_fOrigin.z) = 0;
  LODWORD(this->qw) = 1065353216;
  LODWORD(this->qx) = 0;
  LODWORD(this->qy) = 0;
  LODWORD(this->qz) = 0;
}

//----- (0051F690) --------------------------------------------------------  // acclient.c:333676
void __thiscall CAnimation::CAnimation(CAnimation *this)
{
  CAnimation *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844470);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->pos_frames = 0;
  v1->part_frames = 0;
  v1->has_hooks = 0;
  v1->num_parts = 0;
  v1->num_frames = 0;
  v1->vfptr = (InterfaceVtbl *)&CAnimation::vftable;
  v1->vfptr = (PackObjVtbl *)&CAnimation::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A88: using guessed type void *CAnimation::vftable;
// 7C7AA0: using guessed type __int32 (__stdcall *CAnimation::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0051F6E0) --------------------------------------------------------  // acclient.c:333702
CAnimation *__thiscall CAnimation::vector_deleting_destructor(CAnimation *this, unsigned int a2)
{
  return CAnimation::scalar_deleting_destructor((CAnimation *)((char *)this - 48), a2);
}

//----- (0051F6F0) --------------------------------------------------------  // acclient.c:333708
void __thiscall CAnimation::GetSubDataIDs(CAnimation *this, QualifiedDataIDArray *id_array)
{
  CAnimation *v2; // edi@1
  unsigned int v3; // ebp@1
  int v4; // ebx@2
  CAnimHook *i; // esi@3

  v2 = this;
  v3 = 0;
  if ( this->num_frames )
  {
    v4 = 0;
    do
    {
      for ( i = v2->part_frames[v4].hooks; i; i = i->next_hook )
        i->vfptr->GetSubDataIDs(i, id_array);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->num_frames );
  }
}

//----- (0051F740) --------------------------------------------------------  // acclient.c:333732
unsigned int __thiscall CAnimation::pack_size(CAnimation *this)
{
  CAnimation *v1; // ebx@1
  int v2; // ebp@1
  unsigned int v3; // esi@2
  CAnimHook *v4; // edi@5
  int j; // esi@5
  int v6; // eax@6
  bool v7; // cf@7
  unsigned int retval; // [sp+Ch] [bp-8h]@1
  unsigned int i; // [sp+10h] [bp-4h]@4

  v1 = this;
  v2 = 0;
  retval = 12;
  if ( this->pos_frames )
  {
    v3 = this->num_frames;
    if ( v3 > 0 )
      retval = v3 * TChessPiece<CBasePiece>::GetPackSize() + 12;
  }
  i = 0;
  if ( v1->num_frames )
  {
    do
    {
      v4 = v1->part_frames[v2].hooks;
      for ( j = 28 * v1->num_parts + 4; v4; j += v6 )
      {
        v6 = CAnimHook::PackSize(v4);
        v4 = v4->next_hook;
      }
      ++v2;
      v7 = i + 1 < v1->num_frames;
      retval += j;
      ++i;
    }
    while ( v7 );
  }
  return retval;
}

//----- (0051F7E0) --------------------------------------------------------  // acclient.c:333775
void __thiscall AnimFrame::Destroy(AnimFrame *this)
{
  AnimFrame *v1; // esi@1
  CAnimHook *v2; // ecx@4
  CAnimHook *v3; // edi@4

  v1 = this;
  if ( this->frame )
  {
    operator delete[](&this->frame[-1].qz);
    v1->frame = 0;
  }
  if ( v1->hooks )
  {
    do
    {
      v2 = v1->hooks;
      v3 = v2->next_hook;
      if ( v2 )
        ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      v1->hooks = v3;
    }
    while ( v3 );
  }
  v1->hooks = 0;
}

//----- (0051F830) --------------------------------------------------------  // acclient.c:333803
unsigned int __thiscall AnimFrame::Pack(AnimFrame *this, unsigned int num_parts, void **addr, unsigned int size)
{
  unsigned int v4; // ebp@1
  AnimFrame *v5; // esi@1
  CAnimHook *v6; // edi@1
  unsigned int v7; // ebx@1
  int v8; // eax@2
  unsigned int result; // eax@5
  int v10; // ebx@7
  CAnimHook *v11; // ebx@9
  unsigned int v12; // ebp@9
  unsigned int num_partsa; // [sp+14h] [bp+4h]@1

  v4 = num_parts;
  v5 = this;
  v6 = this->hooks;
  v7 = 28 * num_parts + 4;
  num_partsa = 28 * num_parts + 4;
  if ( v6 )
  {
    do
    {
      v8 = CAnimHook::PackSize(v6);
      v6 = v6->next_hook;
      v7 += v8;
    }
    while ( v6 );
    num_partsa = v7;
  }
  if ( size >= v7 )
  {
    if ( v4 )
    {
      v10 = 0;
      do
      {
        AFrame::Pack(&v5->frame[v10], addr, size);
        ++v10;
        --v4;
      }
      while ( v4 );
    }
    *(_DWORD *)*addr = v5->num_frame_hooks;
    *addr = (char *)*addr + 4;
    v11 = v5->hooks;
    v12 = 0;
    if ( v5->num_frame_hooks )
    {
      do
      {
        CAnimHook::PackHook(v11, addr, size);
        v11 = v11->next_hook;
        ++v12;
      }
      while ( v12 < v5->num_frame_hooks );
    }
    result = num_partsa;
  }
  else
  {
    result = v7;
  }
  return result;
}

//----- (0051F8E0) --------------------------------------------------------  // acclient.c:333869
int __thiscall AnimFrame::UnPack(AnimFrame *this, unsigned int _num_parts, void **addr, unsigned int size)
{
  AnimFrame *v4; // esi@1
  void *v5; // eax@1
  unsigned int v6; // ebx@1
  int v7; // edx@2
  int v8; // eax@2
  unsigned int v9; // ecx@3
  int v10; // eax@5
  int v11; // ebp@8
  CAnimHook *v12; // eax@12

  v4 = this;
  AnimFrame::Destroy(this);
  v4->num_parts = _num_parts;
  v5 = operator new[](28 * _num_parts + 4);
  v6 = 0;
  if ( v5 )
  {
    v7 = (int)((char *)v5 + 4);
    *(_DWORD *)v5 = _num_parts;
    v8 = (int)((char *)v5 + 4);
    if ( ((_num_parts - 1) & 0x80000000) == 0 )
    {
      v9 = _num_parts;
      do
      {
        *(_DWORD *)v8 = 0;
        *(_DWORD *)(v8 + 4) = 0;
        *(_DWORD *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 12) = 1065353216;
        *(_DWORD *)(v8 + 16) = 0;
        *(_DWORD *)(v8 + 20) = 0;
        *(_DWORD *)(v8 + 24) = 0;
        v8 += 28;
        --v9;
      }
      while ( v9 );
    }
    v10 = v7;
  }
  else
  {
    v10 = 0;
  }
  v4->frame = (AFrame *)v10;
  if ( v4->num_parts > 0 )
  {
    v11 = 0;
    do
    {
      AFrame::UnPack(&v4->frame[v11], addr, size);
      ++v6;
      ++v11;
    }
    while ( v6 < v4->num_parts );
    v6 = 0;
  }
  v4->num_frame_hooks = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( v4->num_frame_hooks > 0 )
  {
    do
    {
      v12 = CAnimHook::UnPackHook(addr, size);
      CAnimHook::add_to_list(v12, &v4->hooks);
      ++v6;
    }
    while ( v6 < v4->num_frame_hooks );
  }
  return 1;
}

//----- (0051F9C0) --------------------------------------------------------  // acclient.c:333943
void *__thiscall AnimFrame::vector_deleting_destructor(AnimFrame *this, unsigned int a2)
{
  char v2; // bl@1
  AnimFrame *v3; // edi@1
  unsigned int v4; // eax@2
  char *v5; // ebp@2
  AnimFrame *v6; // esi@2
  int v7; // eax@2
  int v8; // ebx@3
  void *v9; // eax@4
  void *v10; // edi@5
  CAnimHook *v11; // ecx@7
  CAnimHook *v12; // edi@7
  void *result; // eax@14
  char *v14; // [sp+4h] [bp-4h]@2

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1].num_parts;
    v5 = (char *)&this[-1].num_parts;
    v6 = &this[v4];
    v7 = v4 - 1;
    v14 = (char *)&this[-1].num_parts;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        v9 = v6[-1].frame;
        --v6;
        if ( v9 )
        {
          v10 = (char *)v9 - 4;
          vector_destructor_iterator(
            v9,
            0x1Cu,
            *((_DWORD *)v9 - 1),
            (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
          operator delete[](v10);
          v6->frame = 0;
        }
        if ( v6->hooks )
        {
          do
          {
            v11 = v6->hooks;
            v12 = v11->next_hook;
            if ( v11 )
              ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
            v6->hooks = v12;
          }
          while ( v12 );
        }
        --v8;
        v6->hooks = 0;
      }
      while ( v8 );
      v5 = v14;
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    AnimFrame::Destroy(this);
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}

//----- (0051FA80) --------------------------------------------------------  // acclient.c:334020
unsigned int __thiscall CAnimation::Pack(CAnimation *this, void **addr, unsigned int size)
{
  CAnimation *v3; // esi@1
  unsigned int result; // eax@1
  signed int v5; // ecx@2
  char *v6; // ebp@6
  char *v7; // ebx@6
  DBObj *v8; // ebx@7
  int v9; // ebp@8
  DBObj *v10; // ebx@11
  int v11; // ebp@12
  unsigned int retval; // [sp+10h] [bp-4h]@1

  v3 = this;
  result = CAnimation::pack_size((CAnimation *)((char *)this - 48));
  retval = result;
  if ( size >= result )
  {
    v5 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
      v5 = 1;
    if ( LODWORD(v3->m_timeStamp) )
      v5 |= 2u;
    *(_DWORD *)*addr = v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = HIDWORD(v3->m_timeStamp);
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->m_pNext;
    *addr = (char *)*addr + 4;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      v8 = 0;
      if ( v3->m_pNext )
      {
        v9 = 0;
        do
        {
          AFrame::Pack((AFrame *)(v9 + *(_DWORD *)&v3->m_bLoaded), addr, size);
          v8 = (DBObj *)((char *)v8 + 1);
          v9 += 28;
        }
        while ( v8 < v3->m_pNext );
        result = retval;
      }
    }
    v10 = 0;
    if ( v3->m_pNext )
    {
      v11 = 0;
      do
      {
        AnimFrame::Pack((AnimFrame *)(v11 + *((_DWORD *)&v3->m_bLoaded + 1)), HIDWORD(v3->m_timeStamp), addr, size);
        v10 = (DBObj *)((char *)v10 + 1);
        v11 += 16;
      }
      while ( v10 < v3->m_pNext );
      result = retval;
    }
  }
  return result;
}

//----- (0051FB50) --------------------------------------------------------  // acclient.c:334085
int __thiscall CAnimation::UnPack(CAnimation *this, void **addr, unsigned int size)
{
  CAnimation *v3; // esi@1
  void **v4; // edi@1
  void **v5; // ecx@1
  char *v6; // eax@1
  char *v7; // ebx@1
  char *v8; // edx@1
  int v9; // ebx@2
  void *v10; // eax@2
  int v11; // ebp@3
  DBObj *v12; // eax@5
  DBObj *v13; // ebx@5
  int v14; // ebp@6
  DBObj *v15; // ebx@8
  unsigned int v16; // ST0C_4@8
  void *v17; // eax@8
  int v18; // ebp@8
  int v19; // ebx@9
  int v20; // edx@9
  int v21; // eax@9
  int v22; // ecx@10
  DBObj *v23; // eax@14
  DBObj *v24; // ebx@14
  void **addra; // [sp+14h] [bp+4h]@1

  v3 = this;
  ((void (__thiscall *)(DBOCache **))this[-1].m_pMaintainer->m_ObjTable.m_intrusiveTable.m_aInplaceBuckets[12])(&this[-1].m_pMaintainer);
  v4 = addr;
  v5 = *(void ***)*addr;
  v6 = (char *)*addr + 4;
  *addr = v6;
  HIDWORD(v3->m_timeStamp) = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v3->m_pNext = *(DBObj **)v7;
  v8 = (char *)*addr + 4;
  addra = v5;
  *v4 = v8;
  if ( (unsigned __int8)v5 & 1 )
  {
    v9 = (int)v3->m_pNext;
    v10 = operator new[](28 * (unsigned int)v3->m_pNext + 4);
    if ( v10 )
    {
      v11 = (int)((char *)v10 + 4);
      *(_DWORD *)v10 = v9;
      vector_constructor_iterator((char *)v10 + 4, 0x1Cu, v9, (void *(__thiscall *)(void *))AFrame::AFrame);
    }
    else
    {
      v11 = 0;
    }
    v12 = v3->m_pNext;
    v13 = 0;
    *(_DWORD *)&v3->m_bLoaded = v11;
    if ( v12 )
    {
      v14 = 0;
      do
      {
        AFrame::UnPack((AFrame *)(v14 + *(_DWORD *)&v3->m_bLoaded), v4, size);
        v13 = (DBObj *)((char *)v13 + 1);
        v14 += 28;
      }
      while ( v13 < v3->m_pNext );
    }
  }
  v15 = v3->m_pNext;
  v16 = 16 * (unsigned int)v3->m_pNext + 4;
  LODWORD(v3->m_timeStamp) = ((unsigned int)(unsigned __int8)addra >> 1) & 1;
  v17 = operator new[](v16);
  v18 = 0;
  if ( v17 )
  {
    *(_DWORD *)v17 = v15;
    v19 = (int)(&v15[-1].m_AllowedInFreeList + 3);
    v20 = (int)((char *)v17 + 4);
    v21 = (int)((char *)v17 + 4);
    if ( v19 >= 0 )
    {
      v22 = v19 + 1;
      do
      {
        *(_DWORD *)v21 = 0;
        *(_DWORD *)(v21 + 4) = 0;
        *(_DWORD *)(v21 + 8) = 0;
        *(_DWORD *)(v21 + 12) = 0;
        v21 += 16;
        --v22;
      }
      while ( v22 );
    }
  }
  else
  {
    v20 = 0;
  }
  v23 = v3->m_pNext;
  v24 = 0;
  *((_DWORD *)&v3->m_bLoaded + 1) = v20;
  if ( (unsigned int)v23 > 0 )
  {
    do
    {
      AnimFrame::UnPack((AnimFrame *)(v18 + *((_DWORD *)&v3->m_bLoaded + 1)), HIDWORD(v3->m_timeStamp), v4, size);
      v24 = (DBObj *)((char *)v24 + 1);
      v18 += 16;
    }
    while ( v24 < v3->m_pNext );
  }
  return 1;
}

//----- (0051FC70) --------------------------------------------------------  // acclient.c:334200
void __thiscall CAnimation::Destroy(CAnimation *this)
{
  CAnimation *v1; // esi@1
  AFrame *v2; // eax@1
  AnimFrame *v3; // ecx@3

  v1 = this;
  v2 = this->pos_frames;
  if ( v2 )
  {
    operator delete[](&v2[-1].qz);
    v1->pos_frames = 0;
  }
  v3 = v1->part_frames;
  if ( v3 )
  {
    AnimFrame::vector_deleting_destructor(v3, 3u);
    v1->part_frames = 0;
  }
  v1->num_frames = 0;
  v1->num_parts = 0;
}

//----- (0051FCB0) --------------------------------------------------------  // acclient.c:334224
void __thiscall CAnimation::~CAnimation(CAnimation *this)
{
  CAnimation *v1; // esi@1
  AFrame *v2; // eax@1
  AnimFrame *v3; // ecx@3

  v1 = this;
  v2 = this->pos_frames;
  this->vfptr = (InterfaceVtbl *)&CAnimation::vftable;
  this->vfptr = (PackObjVtbl *)&CAnimation::vftable;
  if ( v2 )
  {
    operator delete[](&v2[-1].qz);
    v1->pos_frames = 0;
  }
  v3 = v1->part_frames;
  if ( v3 )
  {
    AnimFrame::vector_deleting_destructor(v3, 3u);
    v1->part_frames = 0;
  }
  v1->num_frames = 0;
  v1->num_parts = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A88: using guessed type void *CAnimation::vftable;
// 7C7AA0: using guessed type __int32 (__stdcall *CAnimation::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0051FD00) --------------------------------------------------------  // acclient.c:334255
CAnimation *__thiscall CAnimation::scalar_deleting_destructor(CAnimation *this, unsigned int a2)
{
  CAnimation *v2; // esi@1

  v2 = this;
  CAnimation::~CAnimation(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006FD4F0) --------------------------------------------------------  // acclient.c:785566
int _E73_90()
{
  return atexit(_E74_67);
}

//----- (006FD500) --------------------------------------------------------  // acclient.c:785572
int _E76_53()
{
  return atexit(_E77_81);
}

//----- (006FD510) --------------------------------------------------------  // acclient.c:785578
int _E79_46()
{
  return atexit(_E80_45);
}

//----- (006FD520) --------------------------------------------------------  // acclient.c:785584
int sub_6FD520()
{
  return atexit(nullsub_1115);
}

