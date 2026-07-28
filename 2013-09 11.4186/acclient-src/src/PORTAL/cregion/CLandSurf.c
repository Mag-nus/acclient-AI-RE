/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLandSurf
   Object     : PORTAL\cregion\CLandSurf.obj
   Functions  : 21
   Addresses  : 00502A20 - 006F9E60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502A20) --------------------------------------------------------  // acclient.c:303796
void __thiscall LandSurf::GetSubDataIDs(LandSurf *this, QualifiedDataIDArray *id_array)
{
  LandSurf *v2; // eax@1
  PalShift *v3; // ecx@1

  v2 = this;
  v3 = this->pal_shift;
  if ( v3 )
    PalShift::GetSubDataIDs(v3, id_array);
  else
    TexMerge::GetSubDataIDs(v2->tex_merge, id_array);
}

//----- (00502A40) --------------------------------------------------------  // acclient.c:303810
int __thiscall LandSurf::pack_size(LandSurf *this)
{
  LandSurf *v1; // eax@1
  PalShift *v2; // ecx@1
  int result; // eax@2

  v1 = this;
  v2 = this->pal_shift;
  if ( v2 )
    result = PalShift::pack_size(v2) + 4;
  else
    result = TexMerge::pack_size(v1->tex_merge) + 4;
  return result;
}

//----- (00502A60) --------------------------------------------------------  // acclient.c:303826
unsigned int __thiscall LandSurf::NextFree(LandSurf *this)
{
  LandSurf *v1; // esi@1
  CSurface **v2; // ebx@1
  void *v3; // eax@2
  unsigned int v4; // ecx@2
  unsigned int v5; // eax@2
  unsigned int result; // eax@4
  unsigned int v7; // ebp@5
  CSurface **v8; // ecx@6
  int v9; // edi@9
  void *v10; // eax@9
  unsigned int v11; // ecx@9
  unsigned int v12; // eax@9
  unsigned int i; // eax@11

  v1 = this;
  v2 = this->lsurf;
  if ( v2 )
  {
    v7 = this->num_lsurf;
    result = 0;
    if ( v7 )
    {
      v8 = this->lsurf;
      while ( *v8 )
      {
        ++result;
        ++v8;
        if ( result >= v1->num_lsurf )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      v9 = v7 + 40;
      v10 = operator new[](4 * (v7 + 40));
      v11 = v1->num_lsurf;
      v1->lsurf = (CSurface **)v10;
      v12 = 0;
      if ( v11 )
      {
        do
        {
          v1->lsurf[v12] = v2[v12];
          ++v12;
        }
        while ( v12 < v1->num_lsurf );
      }
      for ( i = v1->num_lsurf; i < v9; ++i )
        v1->lsurf[i] = 0;
      v1->num_lsurf = v9;
      operator delete[](v2);
      result = v7;
    }
  }
  else
  {
    this->num_lsurf = 40;
    v3 = operator new[](0xA0u);
    v4 = v1->num_lsurf;
    v1->lsurf = (CSurface **)v3;
    v5 = 0;
    if ( v4 )
    {
      do
        v1->lsurf[v5++] = 0;
      while ( v5 < v1->num_lsurf );
    }
    result = 0;
  }
  return result;
}

//----- (00502B30) --------------------------------------------------------  // acclient.c:303902
unsigned int __thiscall LandSurf::GetDetailTiling(LandSurf *this, unsigned int terrain_number)
{
  TexMerge *v2; // ecx@1
  unsigned int result; // eax@2

  v2 = this->tex_merge;
  if ( v2 )
    result = TexMerge::GetDetailTiling(v2, terrain_number);
  else
    result = 0;
  return result;
}

//----- (00502B50) --------------------------------------------------------  // acclient.c:303916
void __thiscall LandSurf::Destroy(LandSurf *this)
{
  LandSurf *v1; // esi@1
  PalShift *v2; // edi@1
  void *v3; // edi@4

  v1 = this;
  v2 = this->pal_shift;
  if ( this->pal_shift )
  {
    PalShift::~PalShift(this->pal_shift);
    operator delete(v2);
    v1->pal_shift = 0;
  }
  if ( v1->tex_merge )
  {
    operator delete(TexMerge::tex_data);
    TexMerge::tex_data = 0;
    v3 = v1->tex_merge;
    if ( v3 )
    {
      TexMerge::~TexMerge(v1->tex_merge);
      operator delete(v3);
    }
    v1->tex_merge = 0;
  }
  if ( v1->lsurf )
  {
    operator delete[](v1->lsurf);
    v1->lsurf = 0;
  }
  v1->num_unique_surfaces = 0;
  v1->num_lsurf = 0;
}

//----- (00502BC0) --------------------------------------------------------  // acclient.c:303952
unsigned int __thiscall LandSurf::Pack(LandSurf *this, void **addr, unsigned int *size)
{
  LandSurf *v3; // edi@1
  int v4; // ecx@1
  unsigned int result; // eax@7

  v3 = this;
  v4 = this->pal_shift != 0;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = v4;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  if ( v4 )
    PalShift::Pack(v3->pal_shift, addr, size);
  else
    TexMerge::Pack(v3->tex_merge, addr, size);
  if ( v3->pal_shift )
  {
    PalShift::pack_size(v3->pal_shift);
    result = *size;
  }
  else
  {
    TexMerge::pack_size(v3->tex_merge);
    result = *size;
  }
  return result;
}

//----- (00502C20) --------------------------------------------------------  // acclient.c:303984
int __thiscall LandSurf::UnPack(LandSurf *this, void **addr, unsigned int *size)
{
  LandSurf *v3; // ebx@1
  unsigned int *v4; // ecx@2
  PalShift *v5; // eax@5
  PalShift *v6; // eax@6
  int result; // eax@6
  TexMerge *v8; // eax@8
  TexMerge *v9; // eax@9

  v3 = this;
  if ( *size < 4 )
  {
    v4 = size;
  }
  else
  {
    v4 = *(unsigned int **)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  if ( v4 )
  {
    v5 = (PalShift *)operator new(0x18u);
    if ( v5 )
    {
      PalShift::PalShift(v5);
      v3->pal_shift = v6;
      result = PalShift::UnPack(v6, addr, size);
    }
    else
    {
      v3->pal_shift = 0;
      result = PalShift::UnPack(0, addr, size);
    }
  }
  else
  {
    v8 = (TexMerge *)operator new(0x34u);
    if ( v8 )
    {
      TexMerge::TexMerge(v8);
      v3->tex_merge = v9;
      result = TexMerge::UnPack(v9, addr, size);
    }
    else
    {
      v3->tex_merge = 0;
      result = TexMerge::UnPack(0, addr, size);
    }
  }
  return result;
}

//----- (00502CC0) --------------------------------------------------------  // acclient.c:304039
IDClass<_tagDataID,32,0> *__thiscall LandSurf::GetDetailTex(LandSurf *this, IDClass<_tagDataID,32,0> *result, unsigned int terrain_number)
{
  TexMerge *v3; // ecx@1
  IDClass<_tagDataID,32,0> *v4; // eax@2

  v3 = this->tex_merge;
  if ( v3 )
  {
    TexMerge::GetDetailTex(v3, result, terrain_number);
    v4 = result;
  }
  else
  {
    v4 = result;
    result->id = stru_8416AC.id;
  }
  return v4;
}

//----- (00502CF0) --------------------------------------------------------  // acclient.c:304059
void __thiscall LandSurf::~LandSurf(LandSurf *this)
{
  LandSurf *v1; // esi@1
  LongNIValHash<SurfInfo *> *v2; // ecx@1

  v1 = this;
  LandSurf::Destroy(this);
  v2 = v1->surf_info;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  operator delete[](v1->block_surf_array.m_data);
}

//----- (00502D20) --------------------------------------------------------  // acclient.c:304073
void __thiscall LongNIValHash<SurfInfo *>::add(LongNIValHash<SurfInfo *> *this, SurfInfo *data, unsigned int key)
{
  LongNIValHash<SurfInfo *> *v3; // esi@1
  void *v4; // eax@1
  void *v5; // edx@1
  int v6; // eax@3

  v3 = this;
  v4 = operator new(0x10u);
  v5 = 0;
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 3) = data;
    *((_DWORD *)v4 + 2) = key;
    *(_DWORD *)v4 = LongHashData::vftable;
    v5 = v4;
  }
  v6 = v3->table_mask & (*((_DWORD *)v5 + 2) ^ (*((_DWORD *)v5 + 2) >> v3->key_shift));
  *((_DWORD *)v5 + 1) = v3->buckets[v6];
  v3->buckets[v6] = (HashBaseData<unsigned long> *)v5;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);

//----- (00502DD0) --------------------------------------------------------  // acclient.c:304124
void __thiscall LandSurf::LandSurf(LandSurf *this)
{
  LandSurf *v1; // edi@1
  void *v2; // eax@1
  void *v3; // esi@1
  signed int v4; // eax@2
  int v5; // edx@3
  unsigned int v6; // eax@4

  v1 = this;
  this->pal_shift = 0;
  this->tex_merge = 0;
  this->num_lsurf = 0;
  this->lsurf = 0;
  this->num_unique_surfaces = 0;
  this->block_surf_array.m_data = 0;
  this->block_surf_array.m_size = 0;
  this->block_surf_array.m_num = 0;
  v2 = operator new(0x18u);
  v3 = v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = LongHash<CWeenieObject>::vftable;
    *((_DWORD *)v2 + 5) = 0;
    *((_DWORD *)v2 + 3) = operator new[](0x40u);
    *((_DWORD *)v3 + 4) = 16;
    *((_DWORD *)v3 + 2) = 8;
    *((_DWORD *)v3 + 1) = 0;
    v4 = 1;
    do
    {
      v5 = v4 | *((_DWORD *)v3 + 1);
      v4 *= 2;
      *((_DWORD *)v3 + 1) = v5;
    }
    while ( (v4 | (unsigned int)v5) < *((_DWORD *)v3 + 4) );
    v6 = 0;
    do
      *(_DWORD *)(*((_DWORD *)v3 + 3) + 4 * v6++) = 0;
    while ( v6 < *((_DWORD *)v3 + 4) );
    *(_DWORD *)v3 = &LongNIValHash<SurfInfo *>::vftable;
    v1->surf_info = (LongNIValHash<SurfInfo *> *)v3;
    v1->curr_tex = 0;
    v1->num_block_surfs = 0;
  }
  else
  {
    v1->surf_info = 0;
    v1->curr_tex = 0;
    v1->num_block_surfs = 0;
  }
}
// 7C62FC: using guessed type int (__thiscall *LongNIValHash<SurfInfo *>::vftable)(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (00502E80) --------------------------------------------------------  // acclient.c:304180
int __thiscall LandSurf::AddNewSurface(LandSurf *this, CSurface *surf, unsigned int pcode, unsigned int *surf_num)
{
  LandSurf *v4; // edi@1
  void *v5; // eax@1
  void *v6; // esi@1

  v4 = this;
  v5 = operator new(0x10u);
  v6 = 0;
  if ( v5 )
  {
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 2) = 0;
    *((_DWORD *)v5 + 3) = 0;
    v6 = v5;
  }
  *((_DWORD *)v6 + 2) = surf;
  *(_DWORD *)v6 = pcode;
  *surf_num = LandSurf::NextFree(v4);
  ++*((_DWORD *)v6 + 1);
  *((_DWORD *)v6 + 3) = *surf_num;
  v4->lsurf[*surf_num] = surf;
  LongNIValHash<SurfInfo *>::add(v4->surf_info, (SurfInfo *)v6, pcode);
  ++v4->num_unique_surfaces;
  return 1;
}

//----- (00502EF0) --------------------------------------------------------  // acclient.c:304209
void __thiscall LandSurf::RemoveSurface(LandSurf *this, unsigned int surf_num)
{
  LandSurf *v2; // ebx@1
  void *v3; // edx@1
  unsigned int v4; // ecx@1
  HashBaseData<unsigned long> *v5; // eax@2
  unsigned int v6; // ebp@5
  unsigned int v7; // esi@11
  bool v8; // zf@16
  CSurface *v9; // [sp+8h] [bp-18h]@5
  LongNIValHashIter<SurfInfo *> iter; // [sp+Ch] [bp-14h]@1

  v2 = this;
  v3 = this->surf_info;
  v4 = 0;
  iter.myHash_ = (HashBase<unsigned long> *)v3;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( v3 )
  {
    v5 = (HashBaseData<unsigned long> *)**((_DWORD **)v3 + 3);
    iter.fEnd_ = 0;
    iter.curPtr_ = v5;
    if ( !v5 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
      if ( iter.fEnd_ )
        return;
      v5 = iter.curPtr_;
      v4 = iter.curBucket_;
      v3 = iter.myHash_;
    }
    v6 = surf_num;
    v9 = v2->lsurf[surf_num];
    while ( 1 )
    {
      if ( v5 )
        v6 = (unsigned int)v5[1].vfptr;
      if ( *(CSurface **)(v6 + 8) == v9 )
      {
        v8 = (*(_DWORD *)(v6 + 4))-- == 1;
        if ( v8 )
        {
          v2->lsurf[surf_num] = 0;
          HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&iter.myHash_);
          if ( v2->pal_shift )
          {
            PalShift::CleanupSurface(*(CSurface **)(v6 + 8));
          }
          else if ( v2->tex_merge )
          {
            TexMerge::CleanupSurface(*(CSurface **)(v6 + 8));
          }
          --v2->num_unique_surfaces;
          operator delete((void *)v6);
        }
        return;
      }
      if ( !v5 )
        break;
      iter.lastThisChain_ = v5;
      v5 = v5->hash_next;
      iter.curPtr_ = v5;
      if ( !v5 )
        break;
LABEL_14:
      if ( iter.fEnd_ )
        return;
    }
    v7 = *((_DWORD *)v3 + 4);
    while ( 1 )
    {
      ++v4;
      iter.lastThisChain_ = 0;
      iter.curBucket_ = v4;
      if ( v4 >= v7 )
        break;
      iter.curPtr_ = *(HashBaseData<unsigned long> **)(*((_DWORD *)v3 + 3) + 4 * v4);
      v5 = iter.curPtr_;
      if ( iter.curPtr_ )
        goto LABEL_14;
    }
  }
}

//----- (00503000) --------------------------------------------------------  // acclient.c:304295
LongNIValHash<SurfInfo *> *__thiscall LongNIValHash<SurfInfo *>::vector_deleting_destructor(LongNIValHash<SurfInfo *> *this, unsigned int a2)
{
  LongNIValHash<SurfInfo *> *v2; // esi@1

  v2 = this;
  LongNIValHash<SurfInfo *>::~LongNIValHash<SurfInfo *>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00503020) --------------------------------------------------------  // acclient.c:304307
void __thiscall LongNIValHash<SurfInfo *>::~LongNIValHash<SurfInfo *>(LongNIValHash<SurfInfo *> *this)
{
  LongNIValHash<SurfInfo *> *v1; // esi@1
  int v2; // eax@3
  LongNIValHashIter<GlobalVoyeurInfo> v3; // [sp+4h] [bp-14h]@1

  v1 = this;
  this->vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<SurfInfo *>::vftable;
  LongNIValHashIter<SurfInfo *>::LongNIValHashIter<SurfInfo *>(&v3, (LongNIValHash<GlobalVoyeurInfo> *)this);
  while ( !v3.fEnd_ )
    HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&v3.myHash_);
  v2 = v1->fPlacementNew_;
  v1->vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v2 )
    operator delete[](v1->buckets);
}
// 7C62FC: using guessed type int (__thiscall *LongNIValHash<SurfInfo *>::vftable)(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (00503070) --------------------------------------------------------  // acclient.c:304327
int __userpurge LandSurf::SelectTerrain@<eax>(LandSurf *this@<ecx>, int a2@<ebx>, int x, int y, unsigned int *surf_num, LandDefs::Rotation *rot, unsigned int *pal_code, unsigned int size, int minimize_pal)
{
  LandSurf *v9; // esi@1
  PalShift *v10; // ecx@1
  unsigned int *v11; // ebx@2
  unsigned int v12; // edi@2
  unsigned int *v13; // eax@3
  int result; // eax@3
  CSurface *v15; // eax@4
  unsigned int v16; // edi@6
  unsigned int *v17; // eax@7
  CSurface *v18; // eax@8
  int v19; // esi@8
  IDClass<_tagDataID,32,0> palid[5]; // [sp+Ch] [bp-14h]@2

  v9 = this;
  v10 = this->pal_shift;
  if ( v10 )
  {
    v11 = (unsigned int *)rot;
    v12 = PalShift::SelectRot(v10, x, y, rot, pal_code, size, palid, (unsigned int *)&rot, minimize_pal);
    if ( LongNIValHash<SurfInfo *>::lookup(
           (LongNIValHash<LongHash<MotionData> *> *)v9->surf_info,
           v12,
           (LongHash<MotionData> **)&pal_code) )
    {
      v13 = pal_code;
      ++v13[1];
      *surf_num = v13[3];
      result = 1;
    }
    else
    {
      v15 = PalShift::MakeNewSurface(v9->pal_shift, v12, *v11, palid, (unsigned int)rot);
      result = LandSurf::AddNewSurface(v9, v15, v12, surf_num);
    }
  }
  else if ( v9->tex_merge )
  {
    v16 = *pal_code;
    *rot = 0;
    if ( LongNIValHash<SurfInfo *>::lookup(
           (LongNIValHash<LongHash<MotionData> *> *)v9->surf_info,
           v16,
           (LongHash<MotionData> **)&pal_code) )
    {
      v17 = pal_code;
      ++pal_code[1];
      *surf_num = v17[3];
      vector_destructor_iterator(
        palid,
        4u,
        5,
        (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
      result = 1;
    }
    else
    {
      v18 = TexMerge::MakeNewSurface(v9->tex_merge, a2, v16, size);
      v19 = LandSurf::AddNewSurface(v9, v18, v16, surf_num);
      vector_destructor_iterator(
        palid,
        4u,
        5,
        (void (__thiscall *)(void *))gmNoticeHandler::RecvNotice_PrevSpellSelection);
      result = v19;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006F9DF0) --------------------------------------------------------  // acclient.c:782565
void sub_6F9DF0()
{
  flt_841668 = 1000.0 + 1.0;
}

//----- (006F9E10) --------------------------------------------------------  // acclient.c:782571
void sub_6F9E10()
{
  flt_84166C = 24.0 * 8.0;
}

//----- (006F9E30) --------------------------------------------------------  // acclient.c:782577
void sub_6F9E30()
{
  flt_841670 = 24.0 * 0.5;
}

//----- (006F9E50) --------------------------------------------------------  // acclient.c:782583
void sub_6F9E50()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841674, PFID_A8R8G8B8);
}

//----- (006F9E60) --------------------------------------------------------  // acclient.c:782589
int sub_6F9E60()
{
  return atexit(nullsub_1042);
}

