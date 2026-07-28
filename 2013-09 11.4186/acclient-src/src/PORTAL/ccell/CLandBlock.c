/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLandBlock
   Object     : PORTAL\ccell\CLandBlock.obj
   Functions  : 66
   Addresses  : 0052F050 - 00769500 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0052F050) --------------------------------------------------------  // acclient.c:351337
int __thiscall Plane::set_height(Plane *this, AC1Legacy::Vector3 *vc)
{
  int result; // eax@2

  if ( fabs(this->N.z) <= 0.00019999999 )
  {
    result = 0;
  }
  else
  {
    vc->z = -((vc->y * this->N.y + vc->x * this->N.x + this->d) / this->N.z);
    result = 1;
  }
  return result;
}

//----- (0052F090) --------------------------------------------------------  // acclient.c:351354
BOOL __thiscall ObjectDesc::CheckSlope(ObjectDesc *this, float z_val)
{
  return z_val >= (double)this->min_slope && z_val <= (double)this->max_slope;
}

//----- (0052F0C0) --------------------------------------------------------  // acclient.c:351360
double __thiscall ObjectDesc::ScaleObj(ObjectDesc *this, unsigned int x, unsigned int y, unsigned int k)
{
  double result; // st7@2

  if ( this->min_scale == this->max_scale )
    result = this->max_scale;
  else
    result = pow(
               this->max_scale / this->min_scale,
               (double)(1813693831 * y - (k + 32593) * (1360117743 * y * x + 1888038839) - 1109124029 * x)
             * 2.3283064e-10)
           * this->min_scale;
  return result;
}

//----- (0052F140) --------------------------------------------------------  // acclient.c:351376
void __thiscall CLandBlock::destroy_buildings(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  unsigned int v2; // edi@2
  CBuildingObj *v3; // ecx@3
  CBuildingObj *v4; // ecx@4
  void *v5; // eax@8

  v1 = this;
  if ( this->buildings )
  {
    v2 = 0;
    if ( this->num_buildings > 0 )
    {
      do
      {
        v3 = v1->buildings[v2];
        if ( v3 )
        {
          CBuildingObj::remove(v3);
          v4 = v1->buildings[v2];
          if ( v4 )
            ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
        }
        ++v2;
      }
      while ( v2 < v1->num_buildings );
    }
    operator delete[](v1->buildings);
    v1->buildings = 0;
  }
  v5 = v1->stablist;
  v1->num_buildings = 0;
  if ( v5 )
  {
    operator delete[](v5);
    v1->stablist = 0;
    v1->stab_num = 0;
  }
}

//----- (0052F1D0) --------------------------------------------------------  // acclient.c:351418
void __thiscall CLandBlock::get_land_limits(CLandBlock *this)
{
  char *v1; // esi@1
  char v2; // al@1
  char v3; // dl@1
  int v4; // esi@1
  signed int v5; // edi@1
  unsigned __int8 v6; // bl@2
  unsigned __int8 v7; // bl@6
  unsigned __int8 v8; // bl@14
  unsigned __int8 v9; // bl@18
  unsigned __int8 v10; // bl@22
  unsigned __int8 v11; // bl@26
  unsigned __int8 v12; // bl@30
  unsigned __int8 v13; // bl@34
  unsigned __int8 v14; // bl@38

  v1 = this->height;
  v2 = *v1;
  v3 = *v1;
  v4 = (int)(v1 + 3);
  v5 = 8;
  do
  {
    v6 = *(_BYTE *)(v4 - 2);
    if ( (unsigned __int8)v2 < v6 )
      v2 = *(_BYTE *)(v4 - 2);
    if ( (unsigned __int8)v3 > v6 )
      v3 = *(_BYTE *)(v4 - 2);
    v7 = *(_BYTE *)(v4 - 1);
    if ( (unsigned __int8)v2 < v7 )
      v2 = *(_BYTE *)(v4 - 1);
    if ( (unsigned __int8)v3 > v7 )
      v3 = *(_BYTE *)(v4 - 1);
    if ( (unsigned __int8)v2 < *(_BYTE *)v4 )
      v2 = *(_BYTE *)v4;
    if ( (unsigned __int8)v3 > *(_BYTE *)v4 )
      v3 = *(_BYTE *)v4;
    v8 = *(_BYTE *)(v4 + 1);
    if ( (unsigned __int8)v2 < v8 )
      v2 = *(_BYTE *)(v4 + 1);
    if ( (unsigned __int8)v3 > v8 )
      v3 = *(_BYTE *)(v4 + 1);
    v9 = *(_BYTE *)(v4 + 2);
    if ( (unsigned __int8)v2 < v9 )
      v2 = *(_BYTE *)(v4 + 2);
    if ( (unsigned __int8)v3 > v9 )
      v3 = *(_BYTE *)(v4 + 2);
    v10 = *(_BYTE *)(v4 + 3);
    if ( (unsigned __int8)v2 < v10 )
      v2 = *(_BYTE *)(v4 + 3);
    if ( (unsigned __int8)v3 > v10 )
      v3 = *(_BYTE *)(v4 + 3);
    v11 = *(_BYTE *)(v4 + 4);
    if ( (unsigned __int8)v2 < v11 )
      v2 = *(_BYTE *)(v4 + 4);
    if ( (unsigned __int8)v3 > v11 )
      v3 = *(_BYTE *)(v4 + 4);
    v12 = *(_BYTE *)(v4 + 5);
    if ( (unsigned __int8)v2 < v12 )
      v2 = *(_BYTE *)(v4 + 5);
    if ( (unsigned __int8)v3 > v12 )
      v3 = *(_BYTE *)(v4 + 5);
    v13 = *(_BYTE *)(v4 + 6);
    if ( (unsigned __int8)v2 < v13 )
      v2 = *(_BYTE *)(v4 + 6);
    if ( (unsigned __int8)v3 > v13 )
      v3 = *(_BYTE *)(v4 + 6);
    v14 = *(_BYTE *)(v4 + 7);
    if ( (unsigned __int8)v2 < v14 )
      v2 = *(_BYTE *)(v4 + 7);
    if ( (unsigned __int8)v3 > v14 )
      v3 = *(_BYTE *)(v4 + 7);
    v4 += 10;
    --v5;
  }
  while ( v5 );
  this->max_zval = *(float *)&(&LandDefs::Land_Height_Table)[(unsigned __int8)v2] + 200.0;
  this->min_zval = *(float *)&(&LandDefs::Land_Height_Table)[(unsigned __int8)v3] - 1.0;
}
// 8EDA28: using guessed type float *LandDefs::Land_Height_Table;

//----- (0052F2C0) --------------------------------------------------------  // acclient.c:351501
unsigned int __thiscall CLandBlock::Pack(CLandBlock *this, void **addr, unsigned int size)
{
  CLandBlock *v3; // edi@1
  CLandBlockStruct *v4; // ebx@1
  unsigned int v5; // esi@1

  v3 = this;
  v4 = (CLandBlockStruct *)&this->m_bLoaded;
  v5 = CLandBlockStruct::pack_size() + 4;
  if ( size >= v5 )
  {
    *(_DWORD *)*addr = LODWORD(v3->block_frame.m_fl2gv[3]);
    *addr = (char *)*addr + 4;
    CLandBlockStruct::Pack(v4, addr, size);
  }
  return v5;
}

//----- (0052F310) --------------------------------------------------------  // acclient.c:351520
int __thiscall CLandBlock::UnPack(CLandBlock *this, void **addr, unsigned int size)
{
  CLandBlock *v3; // esi@1

  v3 = this;
  ((void (__thiscall *)(CLandBlockInfo **))this[-1].lbi->object_ids)(&this[-1].lbi);
  LODWORD(v3->block_frame.m_fl2gv[3]) = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  CLandBlockStruct::UnPack((CLandBlockStruct *)&v3->m_bLoaded, addr, size);
  return 1;
}

//----- (0052F350) --------------------------------------------------------  // acclient.c:351533
void __thiscall CLandBlock::release_objs(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  int v2; // ebx@2
  int i; // edi@3

  v1 = this;
  if ( this->side_vertex_count == 9 )
  {
    v2 = 0;
    if ( this->side_cell_count > 0 )
    {
      do
      {
        for ( i = 0; i < v1->side_cell_count; ++i )
          CObjCell::release_objects((CObjCell *)&(&v1->lcell[i].vfptr)[11 * v2 * v1->side_cell_count]);
        ++v2;
      }
      while ( v2 < v1->side_cell_count );
    }
    v1->dyn_objs_init_done = 0;
  }
}

//----- (0052F3B0) --------------------------------------------------------  // acclient.c:351558
void __thiscall CLandBlock::init_dyn_objs(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  int v2; // ebx@3
  int i; // edi@4

  v1 = this;
  if ( this->side_cell_count == 8 && !this->dyn_objs_init_done )
  {
    v2 = 0;
    do
    {
      for ( i = 0; i < v1->side_cell_count; ++i )
        CObjCell::init_objects((CObjCell *)&(&v1->lcell[i].vfptr)[11 * v2 * v1->side_cell_count]);
      ++v2;
    }
    while ( v2 < v1->side_cell_count );
    v1->dyn_objs_init_done = 1;
  }
}

//----- (0052F410) --------------------------------------------------------  // acclient.c:351580
void __thiscall CLandBlock::init_lcell_ptrs(CLandBlock *this)
{
  unsigned int v1; // edx@1
  int v2; // esi@2

  v1 = 0;
  if ( this->side_cell_count * this->side_cell_count )
  {
    v2 = 0;
    do
    {
      this->lcell[v2].myLandBlock_ = this;
      ++v1;
      ++v2;
    }
    while ( v1 < this->side_cell_count * this->side_cell_count );
  }
}

//----- (0052F460) --------------------------------------------------------  // acclient.c:351600
void __thiscall CLandBlock::grab_visible_cells(CLandBlock *this)
{
  CEnvCell::grab_visible(this->stab_num, this->stablist, this);
}

//----- (0052F480) --------------------------------------------------------  // acclient.c:351606
void __thiscall CLandBlock::release_visible_cells(CLandBlock *this)
{
  CEnvCell::release_visible(this->stab_num, this->stablist);
}

//----- (0052F4A0) --------------------------------------------------------  // acclient.c:351612
int __thiscall CLandBlock::calc_sq_draw_order(CLandBlock *this, LandDefs::Direction new_dir, SqCoord *coord)
{
  CLandBlock *v3; // edi@1
  CLandCell **v4; // eax@1
  int v5; // eax@3
  void *v6; // eax@3
  unsigned int v7; // eax@4
  signed int v8; // ecx@6
  int result; // eax@7
  LandDefs::Direction v10; // ebp@8
  int v11; // ebx@8
  unsigned int v12; // esi@9
  unsigned int v13; // eax@9
  bool v14; // zf@19
  int v15; // ebp@23
  signed int v16; // ebx@27
  signed int v17; // eax@28
  signed int v18; // ecx@29
  int v19; // edx@30
  int v20; // esi@30
  int v21; // ebp@30
  int v22; // ebp@30
  int v23; // edx@35
  int v24; // esi@35
  int v25; // ebp@35
  int v26; // ebp@35
  int v27; // edx@40
  int v28; // esi@40
  int v29; // ebp@40
  int v30; // ebp@40
  int v31; // edx@45
  int v32; // esi@45
  int v33; // ebp@45
  int v34; // ebp@45
  int max_iq; // [sp+4h] [bp-Ch]@27
  unsigned int new_close; // [sp+8h] [bp-8h]@0
  unsigned int new_close_4; // [sp+Ch] [bp-4h]@0
  LandDefs::Direction new_dira; // [sp+14h] [bp+4h]@30
  LandDefs::Direction new_dirb; // [sp+14h] [bp+4h]@35
  LandDefs::Direction new_dirc; // [sp+14h] [bp+4h]@40
  LandDefs::Direction new_dird; // [sp+14h] [bp+4h]@45
  SqCoord *coorda; // [sp+18h] [bp+8h]@27

  v3 = this;
  v4 = this->draw_array;
  if ( v4 )
  {
    if ( this->draw_array_size >= this->side_cell_count * this->side_cell_count )
      goto LABEL_6;
    operator delete[](v4);
    v5 = v3->side_cell_count * v3->side_cell_count;
    v3->draw_array_size = v5;
    v6 = operator new[](4 * v5);
  }
  else
  {
    v7 = this->side_cell_count * this->side_cell_count;
    this->draw_array_size = v7;
    v6 = operator new[](4 * v7);
  }
  v3->draw_array = (CLandCell **)v6;
LABEL_6:
  v8 = v3->side_cell_count;
  if ( v8 == 1 )
  {
    *v3->draw_array = v3->lcell;
    result = 1;
  }
  else
  {
    v10 = new_dir;
    v11 = 8 / v8;
    switch ( new_dir )
    {
      case 0:
        v12 = coord->x / (unsigned int)v11;
        v13 = coord->y / (unsigned int)v11;
        v10 = new_dir;
        new_close = coord->x / (unsigned int)v11;
        new_close_4 = coord->y / (unsigned int)v11;
        break;
      case 1:
        v12 = coord->x / (unsigned int)v11;
        v13 = 0;
        new_close = coord->x / (unsigned int)v11;
        new_close_4 = 0;
        break;
      case 2:
        v12 = coord->x / (unsigned int)v11;
        v13 = v8 - 1;
        new_close = coord->x / (unsigned int)v11;
        new_close_4 = v8 - 1;
        break;
      case 3:
        v12 = 0;
        v13 = coord->y / (unsigned int)v11;
        new_close = 0;
        new_close_4 = coord->y / (unsigned int)v11;
        break;
      case 4:
        v13 = coord->y / (unsigned int)v11;
        v12 = v8 - 1;
        new_close = v8 - 1;
        new_close_4 = coord->y / (unsigned int)v11;
        break;
      case 5:
        v12 = v8 - 1;
        v13 = 0;
        new_close = v8 - 1;
        new_close_4 = 0;
        break;
      case 7:
        v12 = 0;
        v13 = 0;
        new_close = 0;
        new_close_4 = 0;
        break;
      case 6:
        v12 = v8 - 1;
        v13 = v8 - 1;
        new_close = v8 - 1;
        new_close_4 = v8 - 1;
        break;
      case 8:
        v12 = 0;
        v13 = v8 - 1;
        new_close = 0;
        new_close_4 = v8 - 1;
        break;
      default:
        v13 = new_close_4;
        v12 = new_close;
        break;
    }
    v14 = v12 == v3->closest.x;
    v3->dir = v10;
    if ( v14 && v13 == v3->closest.y )
    {
      result = 0;
    }
    else
    {
      v3->closest.x = v12;
      v3->closest.y = v13;
      if ( (signed int)v12 <= (signed int)v13 )
      {
        v15 = v8 - v12 - 1;
        if ( (signed int)v13 > v15 )
          v15 = v13;
      }
      else
      {
        v15 = v8 - v13 - 1;
        if ( (signed int)v12 > v15 )
          v15 = v12;
      }
      v16 = 1;
      max_iq = v15;
      coorda = (SqCoord *)(v8 * v8 - 1);
      for ( v3->draw_array[(_DWORD)coorda] = &v3->lcell[v13 + v12 * v8]; v16 <= v15; ++v16 )
      {
        v17 = 0;
        if ( v16 > 0 )
        {
          do
          {
            v18 = 0;
            do
            {
              v19 = v12 + xoffarr_0[v18] + v16 * ixarr_0[v18] + v17 * jxarr_0[v18];
              v20 = new_close_4 + yoffarr_0[v18] + v16 * iyarr_0[v18] + v17 * jyarr_0[v18];
              v21 = v3->side_cell_count;
              new_dira = v21;
              v22 = v21 - 1;
              if ( v19 <= v22 && v20 <= v22 && v19 >= 0 && v20 >= 0 )
              {
                coorda = (SqCoord *)((char *)coorda - 1);
                v3->draw_array[(_DWORD)coorda] = &v3->lcell[v20 + v19 * new_dira];
              }
              v23 = new_close + dword_81DFEC[v18] + v16 * dword_81E00C[v18] + v17 * dword_81E02C[v18];
              v24 = new_close_4 + dword_81DF8C[v18] + v16 * dword_81DFCC[v18] + v17 * dword_81DFAC[v18];
              v25 = v3->side_cell_count;
              new_dirb = v25;
              v26 = v25 - 1;
              if ( v23 <= v26 && v24 <= v26 && v23 >= 0 && v24 >= 0 )
              {
                coorda = (SqCoord *)((char *)coorda - 1);
                v3->draw_array[(_DWORD)coorda] = &v3->lcell[v24 + v23 * new_dirb];
              }
              v27 = new_close + dword_81DFF0[v18] + v16 * dword_81E010[v18] + v17 * dword_81E030[v18];
              v28 = new_close_4 + dword_81DF90[v18] + v16 * dword_81DFD0[v18] + v17 * dword_81DFB0[v18];
              v29 = v3->side_cell_count;
              new_dirc = v29;
              v30 = v29 - 1;
              if ( v27 <= v30 && v28 <= v30 && v27 >= 0 && v28 >= 0 )
              {
                coorda = (SqCoord *)((char *)coorda - 1);
                v3->draw_array[(_DWORD)coorda] = &v3->lcell[v28 + v27 * new_dirc];
              }
              v31 = new_close + dword_81DFF4[v18] + v16 * dword_81E014[v18] + v17 * dword_81E034[v18];
              v32 = new_close_4 + dword_81DF94[v18] + v16 * dword_81DFD4[v18] + v17 * dword_81DFB4[v18];
              v33 = v3->side_cell_count;
              new_dird = v33;
              v34 = v33 - 1;
              if ( v31 <= v34 && v32 <= v34 && v31 >= 0 && v32 >= 0 )
              {
                coorda = (SqCoord *)((char *)coorda - 1);
                v3->draw_array[(_DWORD)coorda] = &v3->lcell[v32 + v31 * new_dird];
              }
              v12 = new_close;
              v18 += 4;
            }
            while ( v18 < 8 );
            ++v17;
          }
          while ( v17 < v16 );
          v15 = max_iq;
        }
      }
      result = 1;
    }
  }
  return result;
}
// 81DF8C: using guessed type int dword_81DF8C[];
// 81DF90: using guessed type int dword_81DF90[];
// 81DF94: using guessed type int dword_81DF94[];
// 81DFAC: using guessed type int dword_81DFAC[];
// 81DFB0: using guessed type int dword_81DFB0[];
// 81DFB4: using guessed type int dword_81DFB4[];
// 81DFCC: using guessed type int dword_81DFCC[];
// 81DFD0: using guessed type int dword_81DFD0[];
// 81DFD4: using guessed type int dword_81DFD4[];
// 81DFEC: using guessed type int dword_81DFEC[];
// 81DFF0: using guessed type int dword_81DFF0[];
// 81DFF4: using guessed type int dword_81DFF4[];
// 81E00C: using guessed type int dword_81E00C[];
// 81E010: using guessed type int dword_81E010[];
// 81E014: using guessed type int dword_81E014[];
// 81E02C: using guessed type int dword_81E02C[];
// 81E030: using guessed type int dword_81E030[];
// 81E034: using guessed type int dword_81E034[];

//----- (0052F910) --------------------------------------------------------  // acclient.c:351856
void __thiscall CLandBlock::add_static_object(CLandBlock *this, CPhysicsObj *object)
{
  CLandBlock *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@3
  CPhysicsObj **v5; // edx@3

  v2 = this;
  v3 = this->static_objects.sizeOf;
  if ( this->num_static_objects >= v3 )
    DArray<CPhysicsObj *>::grow(&this->static_objects, v3 + 40);
  v4 = v2->num_static_objects;
  v5 = v2->static_objects.data;
  v2->num_static_objects = v4 + 1;
  v5[v4] = object;
}

//----- (0052F950) --------------------------------------------------------  // acclient.c:351874
void __thiscall CLandBlock::CLandBlock(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844AF4);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (InterfaceVtbl *)&SerializeUsingPackDBObj::vftable;
  v1->vfptr = (PackObjVtbl *)&SerializeUsingPackDBObj::vftable;
  CLandBlockStruct::CLandBlockStruct((CLandBlockStruct *)&v1->vertex_lighting);
  v2 = (int)&v1->block_frame;
  v1->vfptr = (InterfaceVtbl *)&CLandBlock::vftable;
  v1->vfptr = (PackObjVtbl *)&CLandBlock::vftable;
  *(_DWORD *)v2 = 1065353216;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)(v2 + 60) = 0;
  Frame::cache(&v1->block_frame);
  LODWORD(v1->max_zval) = 0;
  LODWORD(v1->min_zval) = 0;
  v1->dyn_objs_init_done = 0;
  v1->lbi_exists = 0;
  v1->in_view = 0;
  v1->lbi = 0;
  v1->num_static_objects = 0;
  v1->dir = 9;
  v1->static_objects.data = 0;
  v1->static_objects.sizeOf = 0;
  v1->static_objects.next_available = 0;
  v1->static_objects.blocksize = 128;
  v1->num_buildings = 0;
  v1->buildings = 0;
  v1->stab_num = 0;
  v1->stablist = 0;
  v1->draw_array = 0;
  v1->draw_array_size = 0;
  v1->closest.x = -1;
  v1->closest.y = -1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C58CC: using guessed type void *SerializeUsingPackDBObj::vftable;
// 7C58E0: using guessed type __int32 (__stdcall *SerializeUsingPackDBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C8FA8: using guessed type void *CLandBlock::vftable;
// 7C8FC0: using guessed type __int32 (__stdcall *CLandBlock::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0052FA40) --------------------------------------------------------  // acclient.c:351924
CLandBlock *__thiscall CLandBlock::vector_deleting_destructor(CLandBlock *this, unsigned int a2)
{
  return CLandBlock::scalar_deleting_destructor((CLandBlock *)((char *)this - 48), a2);
}

//----- (0052FA50) --------------------------------------------------------  // acclient.c:351930
void __thiscall CLandBlock::destroy_static_objects(CLandBlock *this)
{
  CLandBlock *v1; // edi@1
  unsigned int v2; // ebx@1
  CPhysicsObj **v3; // eax@2
  CPhysicsObj *v4; // esi@2

  v1 = this;
  v2 = 0;
  if ( this->num_static_objects )
  {
    do
    {
      v3 = v1->static_objects.data;
      v4 = v3[v2];
      if ( v4 )
      {
        CPhysicsObj::leave_world(v3[v2]);
        v4->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)v4, 1u);
      }
      ++v2;
    }
    while ( v2 < v1->num_static_objects );
  }
  v1->num_static_objects = 0;
}

//----- (0052FAA0) --------------------------------------------------------  // acclient.c:351958
void __thiscall CLandBlock::Destroy(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  CLandBlockInfo *v2; // ecx@1
  void *v3; // eax@3

  v1 = this;
  CLandBlock::destroy_static_objects(this);
  CLandBlock::destroy_buildings(v1);
  v2 = v1->lbi;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->lbi = 0;
  }
  v1->closest.x = -1;
  v1->closest.y = -1;
  v3 = v1->draw_array;
  v1->lbi_exists = 0;
  v1->dir = 9;
  if ( v3 )
  {
    operator delete[](v3);
    v1->draw_array = 0;
  }
  v1->draw_array_size = 0;
}

//----- (0052FB10) --------------------------------------------------------  // acclient.c:351987
void __cdecl CLandBlock::init()
{
  CLandBlockStruct::land_uvs = 0;
  dword_844CAC = 1065353216;
  dword_844CB0 = 1065353216;
  dword_844CB4 = 1065353216;
  dword_844CB8 = 1065353216;
  dword_844CBC = 0;
  dword_844CC0 = 0;
  dword_844CC4 = 0;
}
// 844CA8: using guessed type struct CVec2Duv *CLandBlockStruct::land_uvs;
// 844CAC: using guessed type int dword_844CAC;
// 844CB0: using guessed type int dword_844CB0;
// 844CB4: using guessed type int dword_844CB4;
// 844CB8: using guessed type int dword_844CB8;
// 844CBC: using guessed type int dword_844CBC;
// 844CC0: using guessed type int dword_844CC0;
// 844CC4: using guessed type int dword_844CC4;

//----- (0052FB70) --------------------------------------------------------  // acclient.c:352008
unsigned int __thiscall CLandBlock::get_terrain(CLandBlock *this, unsigned int cell_id, AC1Legacy::Vector3 *vc)
{
  CLandBlock *v3; // esi@1
  int v4; // ecx@1
  int v5; // edx@1
  double v6; // st6@1
  unsigned __int8 v8; // c0@1
  unsigned __int8 v9; // c3@1
  unsigned int result; // eax@3
  int v11; // eax@5
  unsigned __int16 *v12; // edx@5
  int x; // [sp+0h] [bp-4h]@1

  x = (int)this;
  v3 = this;
  LandDefs::gid_to_lcoord(cell_id, &x, (int *)&cell_id);
  v4 = x % 8;
  x %= 8;
  v5 = (signed int)cell_id % 8;
  cell_id = (signed int)cell_id % 8;
  v6 = vc->y;
  if ( ((double)x + (double)x + 1.0) * flt_844AF0 >= vc->x )
  {
    v11 = v5 + 8 * v4;
    v12 = v3->terrain;
    if ( v8 | v9 )
      result = ((unsigned int)LOBYTE(v12[v11 + v4]) >> 2) & 0x1F;
    else
      result = ((unsigned int)*((_BYTE *)&v12[v11 + 1] + 2 * v4) >> 2) & 0x1F;
  }
  else if ( v8 | v9 )
  {
    result = ((unsigned int)LOBYTE(v3->terrain[v5 + 8 * (v4 + 1) + v4 + 1]) >> 2) & 0x1F;
  }
  else
  {
    result = ((unsigned int)*((_BYTE *)&v3->terrain[8 * v4 + 10] + 2 * v5 + 2 * v4) >> 2) & 0x1F;
  }
  return result;
}

//----- (0052FC60) --------------------------------------------------------  // acclient.c:352050
void __thiscall CLandBlock::GetSubDataIDs(CLandBlock *this, QualifiedDataIDArray *id_array)
{
  QualifiedDataID lbi_id; // [sp+0h] [bp-8h]@2

  if ( this->lbi_exists )
  {
    QualifiedDataID::QualifiedDataID(&lbi_id, (IDClass<_tagDataID,32,0>)(this->m_DID.id & 0xFFFFFFFE | 0xFFFE), 2u);
    QualifiedDataIDArray::AddQDID(id_array, &lbi_id, 0);
  }
}

//----- (0052FCA0) --------------------------------------------------------  // acclient.c:352062
bool __thiscall CLandBlock::InitLoad(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  QualifiedDataID *v2; // eax@2
  int v3; // eax@2
  bool result; // al@2
  QualifiedDataID v5; // [sp+4h] [bp-8h]@2

  v1 = this;
  if ( this->lbi_exists )
  {
    QualifiedDataID::QualifiedDataID(&v5, (IDClass<_tagDataID,32,0>)(this->m_DID.id & 0xFFFFFFFE | 0xFFFE), 2u);
    v3 = DBObj::Get(v2);
    v1->lbi = (CLandBlockInfo *)v3;
    result = v3 != 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0052FCF0) --------------------------------------------------------  // acclient.c:352086
void __thiscall CLandBlock::release_all(CLandBlock *this)
{
  CLandBlock *v1; // esi@1

  v1 = this;
  CLandBlock::release_objs(this);
  CEnvCell::release_visible(v1->stab_num, v1->stablist);
  v1->vfptr->Release((Interface *)v1);
}

//----- (0052FD20) --------------------------------------------------------  // acclient.c:352097
signed int __thiscall CLandBlock::get_landcell(CLandBlock *this, unsigned int cell_id)
{
  unsigned int v2; // edi@1
  CLandBlock *v3; // esi@1
  unsigned int v4; // eax@1
  int y; // [sp+0h] [bp-4h]@1

  y = (int)this;
  v2 = cell_id;
  v3 = this;
  LandDefs::gid_to_lcoord(cell_id, (int *)&cell_id, &y);
  v4 = (y & 7) + (cell_id & 7) * v3->side_cell_count;
  return (signed int)(v3->lcell[v4].m_DID.id != v2 ? 0 : &v3->lcell[v4]);
}

//----- (0052FD80) --------------------------------------------------------  // acclient.c:352113
void __thiscall CLandBlock::init_buildings(CLandBlock *this)
{
  CLandBlock *v1; // esi@1
  CLandBlockInfo *v2; // eax@2
  unsigned int v3; // eax@4
  unsigned int v4; // edx@6
  unsigned int v5; // eax@6
  BuildInfo *v6; // edi@7
  CPhysicsObj *v7; // ebx@7
  int v8; // edi@8
  int v9; // eax@8
  signed int v10; // ebp@8
  unsigned int v11; // edx@11
  unsigned int cell_id; // [sp+4h] [bp-60h]@8
  unsigned int iq; // [sp+8h] [bp-5Ch]@6
  unsigned int max_stab; // [sp+Ch] [bp-58h]@4
  AC1Legacy::Vector3 loc; // [sp+10h] [bp-54h]@8
  Position p; // [sp+1Ch] [bp-48h]@8

  v1 = this;
  if ( this->side_cell_count == 8 )
  {
    v2 = this->lbi;
    if ( v2 )
    {
      if ( !this->buildings )
      {
        this->num_buildings = 0;
        this->stab_num = 0;
        max_stab = 0;
        v3 = v2->num_buildings;
        if ( v3 > 0 )
          this->buildings = (CBuildingObj **)operator new[](4 * v3);
        v4 = v1->lbi->num_buildings;
        v5 = 0;
        iq = 0;
        if ( v4 > 0 )
        {
          do
          {
            v6 = v1->lbi->buildings[v5];
            v7 = (CPhysicsObj *)CBuildingObj::makeBuilding(
                                  v6->building_id,
                                  v6->num_portals,
                                  v6->portals,
                                  v6->num_leaves);
            if ( v7 )
            {
              v8 = (int)&v6->building_frame;
              p.objcell_id = v1->m_DID.id;
              Frame::operator=((int)&p.frame, v8);
              loc.y = p.frame.m_fOrigin.y;
              loc.z = p.frame.m_fOrigin.z;
              loc.x = p.frame.m_fOrigin.x;
              cell_id = p.objcell_id;
              v9 = LandDefs::adjust_to_outside(&cell_id, &loc);
              v10 = CLandBlock::get_landcell(v1, v9 != 0 ? cell_id : 0);
              if ( v10 )
              {
                CPhysicsObj::set_initial_frame(v7, (Frame *)v8);
                CBuildingObj::add_to_cell((CBuildingObj *)v7, (CSortCell *)v10);
                v1->buildings[v1->num_buildings++] = (CBuildingObj *)v7;
                CBuildingObj::add_to_stablist((CBuildingObj *)v7, &v1->stablist, &max_stab, &v1->stab_num);
              }
              else
              {
                v7->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)v7, 1u);
              }
            }
            v11 = v1->lbi->num_buildings;
            v5 = iq++ + 1;
          }
          while ( iq < v11 );
        }
      }
    }
  }
}

//----- (0052FEF0) --------------------------------------------------------  // acclient.c:352193
void __thiscall CLandBlock::adjust_scene_obj_height(CLandBlock *this)
{
  CLandBlock *v1; // ebx@1
  CLandBlockInfo *v2; // eax@1
  unsigned int v3; // edi@2
  CPhysicsObj *v4; // esi@5
  CPolygon *walkable; // [sp+8h] [bp-50h]@6
  AC1Legacy::Vector3 obj_vector; // [sp+Ch] [bp-4Ch]@6
  Frame obj_frame; // [sp+18h] [bp-40h]@6

  v1 = this;
  v2 = this->lbi;
  if ( v2 )
    v3 = v2->num_objects;
  else
    v3 = 0;
  if ( v3 < this->num_static_objects )
  {
    do
    {
      v4 = v1->static_objects.data[v3];
      if ( v4 )
      {
        Frame::operator=((int)&obj_frame, (int)&v4->m_position.frame);
        obj_vector = obj_frame.m_fOrigin;
        if ( CLandCell::find_terrain_poly((CLandCell *)v4->cell, &obj_vector, &walkable) )
        {
          if ( fabs(walkable->plane.N.z) > 0.00019999999 )
            obj_vector.z = -((obj_vector.y * walkable->plane.N.y + obj_vector.x * walkable->plane.N.x + walkable->plane.d)
                           / walkable->plane.N.z);
          if ( fabs(obj_vector.z - obj_frame.m_fOrigin.z) > 0.00019999999 )
          {
            obj_frame.m_fOrigin = obj_vector;
            CPhysicsObj::set_initial_frame(v4, &obj_frame);
          }
        }
      }
      ++v3;
    }
    while ( v3 < v1->num_static_objects );
  }
}

//----- (0052FFF0) --------------------------------------------------------  // acclient.c:352237
int __thiscall CLandBlock::on_road(CLandBlock *this, AC1Legacy::Vector3 *obj_vector)
{
  AC1Legacy::Vector3 *v2; // edi@1
  CLandBlock *v3; // ebx@1
  unsigned __int64 v4; // rax@1
  int v5; // esi@1
  unsigned __int64 v6; // rax@1
  unsigned __int16 *v7; // ecx@1
  int v8; // eax@1
  char v9; // bl@5
  double v10; // st7@5
  __int16 v11; // fps@5
  bool v12; // zf@6
  char v13; // bl@6
  char v14; // bl@7
  bool v16; // c0@13
  char v17; // c2@13
  bool v18; // c3@13
  char v19; // ah@13
  char v20; // bl@16
  __int16 v21; // fps@20
  bool v22; // c0@20
  char v23; // c2@20
  bool v24; // c3@20
  bool v26; // c0@21
  bool v27; // c3@21
  char v28; // bl@25
  char v29; // bl@26
  char v30; // bl@35
  float rmax; // [sp+18h] [bp-Ch]@1
  int iy; // [sp+20h] [bp-4h]@1
  AC1Legacy::Vector3 *obj_vectora; // [sp+28h] [bp+4h]@1
  float obj_vectorb; // [sp+28h] [bp+4h]@5

  v2 = obj_vector;
  rmax = 24.0 - 5.0;
  v3 = this;
  v4 = (unsigned __int64)_floor(obj_vector->x / 24.0);
  v5 = v4;
  obj_vectora = (AC1Legacy::Vector3 *)v4;
  v6 = (unsigned __int64)_floor(v2->y / 24.0);
  v7 = v3->terrain;
  iy = v6;
  v8 = v5 + v6 + 8 * v5;
  if ( !(v7[v8] & 3) && !(v7[v8 + 1] & 3) && !(v7[v8 + 9] & 3) && !(v7[v8 + 10] & 3) )
    return 0;
  v9 = LOBYTE(v7[v8 + 1]);
  v10 = v2->x - (double)(signed int)obj_vectora * 24.0;
  obj_vectorb = v2->y - (double)iy * 24.0;
  if ( v7[v8] & 3 )
  {
    v12 = (v9 & 3) == 0;
    v13 = LOBYTE(v7[v8 + 9]);
    if ( !v12 )
    {
      v12 = (v13 & 3) == 0;
      v14 = LOBYTE(v7[v8 + 10]);
      if ( !v12 )
      {
        if ( v14 & 3 )
          return 1;
        if ( v10 >= 5.0 )
        {
LABEL_11:
          if ( obj_vectorb >= 5.0 )
            return 0;
        }
        return 1;
      }
      v16 = v10 < 5.0;
      v17 = 0;
      v18 = v10 == 5.0;
      v19 = HIBYTE(v11);
      if ( v14 & 3 )
      {
        if ( v10 < 5.0 )
          return 1;
LABEL_29:
        if ( obj_vectorb <= (double)rmax )
          return 0;
        return 1;
      }
      goto LABEL_41;
    }
    v12 = (v13 & 3) == 0;
    v20 = LOBYTE(v7[v8 + 10]);
    if ( !v12 )
    {
      if ( v20 & 3 )
      {
        if ( v10 <= rmax )
          goto LABEL_11;
        return 1;
      }
      v22 = obj_vectorb < 5.0;
      v23 = 0;
      v24 = obj_vectorb == 5.0;
      goto LABEL_40;
    }
    if ( v20 & 3 )
    {
LABEL_22:
      if ( !v26 && !v27 )
        return 1;
      return 0;
    }
  }
  else
  {
    v12 = (v9 & 3) == 0;
    v28 = LOBYTE(v7[v8 + 9]);
    if ( v12 )
    {
      v12 = (v28 & 3) == 0;
      v30 = LOBYTE(v7[v8 + 10]);
      if ( v12 )
      {
        if ( !(v30 & 3) )
          return 0;
        goto LABEL_40;
      }
      if ( v30 & 3 )
      {
        v26 = v10 < rmax;
        v27 = v10 == rmax;
        goto LABEL_22;
      }
    }
    else
    {
      v12 = (v28 & 3) == 0;
      v29 = LOBYTE(v7[v8 + 10]);
      if ( !v12 )
      {
        if ( v29 & 3 )
        {
          if ( v10 > rmax )
            return 1;
          goto LABEL_29;
        }
        goto LABEL_22;
      }
      if ( v29 & 3 )
      {
        v26 = obj_vectorb < (double)rmax;
        v27 = obj_vectorb == rmax;
        goto LABEL_22;
      }
    }
  }
LABEL_40:
  v19 = HIBYTE(v21);
LABEL_41:
  if ( !__SETP__(v19 & 5, 0) )
    return 1;
  return 0;
}

//----- (00530240) --------------------------------------------------------  // acclient.c:352396
int __thiscall CLandBlock::PreFetchCells(CLandBlock *this)
{
  signed int v1; // edi@1
  unsigned int v2; // esi@2
  QualifiedDataID *v3; // eax@2
  CACHE_OBJECT_CODES v4; // eax@2
  QualifiedDataID *v6; // eax@5
  int v7; // eax@5
  int v8; // esi@5
  QualifiedDataID v9; // [sp+8h] [bp-8h]@2

  v1 = 1;
  if ( this->lbi_exists )
  {
    v2 = this->m_DID.id & 0xFFFFFFFE | 0xFFFE;
    QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)v2, 2u);
    v4 = DBObj::PreFetch(v3);
    if ( v4 != 2 && v4 != 1 )
      return 0;
    QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)v2, 2u);
    v7 = DBObj::Get(v6);
    v8 = v7;
    if ( v7 )
    {
      if ( !CLandBlockInfo::PreFetchCells((CLandBlockInfo *)v7) )
        v1 = 0;
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
    }
  }
  return v1;
}

//----- (005302C0) --------------------------------------------------------  // acclient.c:352429
void __thiscall CLandBlock::notify_change_size(CLandBlock *this)
{
  CLandBlock *v1; // esi@1

  v1 = this;
  CEnvCell::release_visible(this->stab_num, this->stablist);
  CLandBlock::release_objs(v1);
  CLandBlock::destroy_static_objects(v1);
  CLandBlock::destroy_buildings(v1);
  v1->closest.x = -1;
  v1->closest.y = -1;
}

//----- (00530310) --------------------------------------------------------  // acclient.c:352443
void __thiscall CLandBlock::add_ambient_sounds(CLandBlock *this, Ambient *ambient_sounds)
{
  CLandBlock *v2; // edi@1
  int v3; // eax@1
  unsigned int v4; // ecx@1
  unsigned int v5; // ebx@3
  int v6; // eax@5
  int v7; // edx@5
  CLandCell *v8; // ecx@5
  CRegionDesc *v9; // ebp@5
  unsigned __int32 v10; // edx@5
  unsigned int v11; // edx@5
  unsigned __int16 *v12; // eax@5
  unsigned int v13; // eax@5
  int v14; // esi@5
  AmbientSTBDesc *v15; // eax@6
  int v16; // [sp+8h] [bp-58h]@4
  unsigned int ix; // [sp+Ch] [bp-54h]@1
  int v18; // [sp+10h] [bp-50h]@2
  unsigned int scene_type_id; // [sp+14h] [bp-4Ch]@5
  Position pos; // [sp+18h] [bp-48h]@1

  v2 = this;
  pos.vfptr = (PackObjVtbl *)&Position::vftable;
  pos.objcell_id = 0;
  LODWORD(pos.frame.qw) = 1065353216;
  LODWORD(pos.frame.qx) = 0;
  LODWORD(pos.frame.qy) = 0;
  LODWORD(pos.frame.qz) = 0;
  LODWORD(pos.frame.m_fOrigin.x) = 0;
  LODWORD(pos.frame.m_fOrigin.y) = 0;
  LODWORD(pos.frame.m_fOrigin.z) = 0;
  Frame::cache(&pos.frame);
  v3 = v2->side_cell_count;
  v4 = 0;
  ix = 0;
  if ( (unsigned int)v3 > 0 )
  {
    v18 = 0;
    do
    {
      v5 = 0;
      if ( v3 )
      {
        v16 = v18;
        do
        {
          v6 = v4 * v3;
          v7 = v4 * v2->side_vertex_count;
          v8 = v2->lcell;
          v9 = CRegionDesc::current_region;
          v10 = (unsigned __int32)((char *)v2->vertex_array.vertices + CVertexArray::vertex_size * (v5 + v7));
          LODWORD(pos.frame.m_fOrigin.x) = *(_DWORD *)v10;
          LODWORD(pos.frame.m_fOrigin.y) = *(_DWORD *)(v10 + 4);
          LODWORD(pos.frame.m_fOrigin.z) = *(_DWORD *)(v10 + 8);
          v11 = *(&v8[v5].m_DID.id + 66 * v6);
          v12 = v2->terrain;
          pos.objcell_id = v11;
          v13 = *(unsigned __int16 *)((char *)v12 + v16);
          v14 = (v13 >> 2) & 0x1F;
          scene_type_id = v13 >> 11;
          if ( (signed int)(v13 >> 11) < (signed int)CRegionDesc::NumSceneType(CRegionDesc::current_region, v14) )
          {
            v15 = CRegionDesc::GetSTBDesc(v9, v14, scene_type_id);
            if ( v15 )
              Ambient::AddSound(ambient_sounds, v15, &pos);
          }
          v3 = v2->side_cell_count;
          v4 = ix;
          ++v5;
          v16 += 2;
        }
        while ( v5 < v3 );
      }
      v3 = v2->side_cell_count;
      ++v4;
      ix = v4;
      v18 += 18;
    }
    while ( v4 < v3 );
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 81E700: using guessed type unsigned __int32 CVertexArray::vertex_size;

//----- (00530460) --------------------------------------------------------  // acclient.c:352529
void __thiscall CLandBlock::get_land_scenes(CLandBlock *this)
{
  CLandBlock *v1; // ebp@1
  CRegionDesc *v2; // ebx@5
  int v3; // eax@6
  unsigned int v4; // esi@10
  unsigned int v5; // edi@10
  unsigned int v6; // ST10_4@10
  unsigned int v7; // eax@11
  unsigned int v8; // edi@11
  unsigned int v9; // ebx@12
  unsigned int v10; // ebp@12
  double v11; // st7@13
  unsigned __int64 v12; // rax@13
  QualifiedDataID *v13; // eax@16
  int v14; // eax@16
  Scene *v15; // edi@16
  int v16; // ecx@18
  unsigned int v17; // eax@18
  int v18; // esi@20
  unsigned int v19; // eax@27
  Plane *v20; // edi@30
  CPhysicsObj *v21; // eax@33
  CPhysicsObj *v22; // edi@33
  float v23; // ST10_4@36
  bool v24; // cf@39
  int v25; // ecx@42
  bool v26; // sf@42
  unsigned __int8 v27; // of@42
  CLandBlock *v28; // [sp+18h] [bp-A0h]@1
  unsigned int kq; // [sp+1Ch] [bp-9Ch]@17
  AC1Legacy::Vector3 obj_vector; // [sp+20h] [bp-98h]@22
  int jq; // [sp+2Ch] [bp-8Ch]@8
  unsigned int scene_id; // [sp+30h] [bp-88h]@10
  int iq; // [sp+34h] [bp-84h]@6
  CRegionDesc *region; // [sp+38h] [bp-80h]@5
  unsigned int v35; // [sp+3Ch] [bp-7Ch]@18
  int v36; // [sp+40h] [bp-78h]@9
  int v37; // [sp+44h] [bp-74h]@7
  unsigned int v38; // [sp+48h] [bp-70h]@13
  CLandCell *cell; // [sp+4Ch] [bp-6Ch]@27
  IDClass<_tagDataID,32,0> obj_id; // [sp+50h] [bp-68h]@20
  Scene *scene; // [sp+54h] [bp-64h]@16
  CPolygon *walkable; // [sp+58h] [bp-60h]@28
  int v43; // [sp+5Ch] [bp-5Ch]@18
  unsigned int v44; // [sp+60h] [bp-58h]@18
  IDClass<_tagDataID,32,0> sid; // [sp+64h] [bp-54h]@15
  Position p; // [sp+68h] [bp-50h]@27
  QualifiedDataID v47; // [sp+B0h] [bp-8h]@16

  v1 = this;
  v28 = this;
  if ( !(_S151_8 & 1) )
  {
    _S151_8 |= 1u;
    LODWORD(obj_frame.qw) = 1065353216;
    LODWORD(obj_frame.qx) = 0;
    LODWORD(obj_frame.qy) = 0;
    LODWORD(obj_frame.qz) = 0;
    LODWORD(obj_frame.m_fOrigin.x) = 0;
    LODWORD(obj_frame.m_fOrigin.y) = 0;
    LODWORD(obj_frame.m_fOrigin.z) = 0;
    Frame::cache(&obj_frame);
    atexit(_E152_28);
  }
  if ( !(_S151_8 & 2) )
  {
    _S151_8 |= 2u;
    obj_pos.vfptr = (PackObjVtbl *)&Position::vftable;
    unk_844B84 = 0;
    LODWORD(stru_844B88.qw) = 1065353216;
    LODWORD(stru_844B88.qx) = 0;
    LODWORD(stru_844B88.qy) = 0;
    LODWORD(stru_844B88.qz) = 0;
    LODWORD(stru_844B88.m_fOrigin.x) = 0;
    LODWORD(stru_844B88.m_fOrigin.y) = 0;
    LODWORD(stru_844B88.m_fOrigin.z) = 0;
    Frame::cache(&stru_844B88);
    atexit(_E153_47);
  }
  v2 = CRegionDesc::current_region;
  region = CRegionDesc::current_region;
  if ( CRegionDesc::current_region )
  {
    v3 = v1->side_vertex_count;
    iq = 0;
    if ( v3 > 0 )
    {
      v37 = 0;
      do
      {
        jq = 0;
        if ( v3 > 0 )
        {
          v36 = v37;
          do
          {
            v4 = ((unsigned int)*(unsigned __int16 *)((char *)v1->terrain + v36) >> 2) & 0x1F;
            v6 = ((unsigned int)*(unsigned __int16 *)((char *)v1->terrain + v36) >> 2) & 0x1F;
            scene_id = (unsigned int)*(unsigned __int16 *)((char *)v1->terrain + v36) >> 11;
            v5 = scene_id;
            if ( v5 < CRegionDesc::NumSceneType(v2, v6) )
            {
              v7 = CRegionDesc::SceneCount(v2, v4, v5);
              v8 = v7;
              if ( v7 )
              {
                v9 = iq + v1->block_coord.x;
                v10 = jq + v1->block_coord.y;
                if ( v7 == 1
                  || (v38 = v10 * (712977289 * v9 + 1813693831) - 1109124029 * v9 + 2139937281,
                      v11 = (double)v38 * 2.3283064e-10,
                      v38 = v7,
                      v12 = (unsigned __int64)_floor(v11 * (double)v7),
                      (unsigned int)v12 >= v8) )
                  LODWORD(v12) = 0;
                CRegionDesc::GetScene(region, &sid, v4, scene_id, v12);
                if ( sid.id != stru_844AF4.id )
                {
                  QualifiedDataID::QualifiedDataID(&v47, sid, 0x1Bu);
                  v14 = DBObj::Get(v13);
                  v15 = (Scene *)v14;
                  scene = (Scene *)v14;
                  if ( v14 )
                  {
                    kq = 0;
                    if ( *(_DWORD *)(v14 + 60) )
                    {
                      v35 = 0;
                      v44 = 1813693831 * v10;
                      v16 = -1109124029 * v9;
                      v38 = 1360117743 * v9 * v10 + 1888038839;
                      v17 = 23399 * v38;
                      v43 = -1109124029 * v9;
                      scene_id = 23399 * v38;
                      while ( 1 )
                      {
                        v18 = (int)&v15->objects[v35 / 0x70];
                        obj_id.id = v16 + v44 - v17;
                        if ( (double)obj_id.id * 2.3283064e-10 < *(float *)(v18 + 68) && !*(_DWORD *)(v18 + 108) )
                        {
                          obj_id.id = *(_DWORD *)v18;
                          ObjectDesc::Place((ObjectDesc *)v18, v9, v10, kq, &obj_vector);
                          obj_vector.x = (double)iq * 24.0 + obj_vector.x;
                          obj_vector.y = (double)jq * 24.0 + obj_vector.y;
                          if ( obj_vector.x >= 0.0
                            && obj_vector.y >= 0.0
                            && obj_vector.x < (double)flt_844AEC
                            && obj_vector.y < (double)flt_844AEC
                            && !CLandBlock::on_road(v28, &obj_vector) )
                          {
                            p.vfptr = (PackObjVtbl *)&Position::vftable;
                            p.objcell_id = 0;
                            LODWORD(p.frame.qw) = 1065353216;
                            LODWORD(p.frame.qx) = 0;
                            LODWORD(p.frame.qy) = 0;
                            LODWORD(p.frame.qz) = 0;
                            LODWORD(p.frame.m_fOrigin.x) = 0;
                            LODWORD(p.frame.m_fOrigin.y) = 0;
                            LODWORD(p.frame.m_fOrigin.z) = 0;
                            Frame::cache(&p.frame);
                            p.objcell_id = v28->m_DID.id;
                            p.frame.m_fOrigin.y = obj_vector.y;
                            LODWORD(p.frame.m_fOrigin.x) = (_DWORD)obj_vector.x;
                            p.frame.m_fOrigin.z = obj_vector.z;
                            v19 = Position::get_outside_cell_id(&p);
                            cell = (CLandCell *)CLandBlock::get_landcell(v28, v19);
                            if ( !CSortCell::has_building((CSortCell *)&cell->vfptr)
                              && CLandCell::find_terrain_poly(cell, &obj_vector, &walkable)
                              && ObjectDesc::CheckSlope((ObjectDesc *)v18, walkable->plane.N.z) )
                            {
                              v20 = &walkable->plane;
                              Plane::set_height(&walkable->plane, &obj_vector);
                              if ( *(_DWORD *)(v18 + 100) )
                                ObjectDesc::ObjAlign((ObjectDesc *)v18, v20, &obj_vector, &obj_frame);
                              else
                                ObjectDesc::GetObjFrame((ObjectDesc *)v18, v9, v10, kq, &obj_vector, &obj_frame);
                              v21 = CPhysicsObj::makeObject(obj_id, 0, 0);
                              v22 = v21;
                              if ( v21 )
                              {
                                CPhysicsObj::set_initial_frame(v21, &obj_frame);
                                if ( CPhysicsObj::obj_within_block(v22) )
                                {
                                  CPhysicsObj::add_obj_to_cell(v22, (CObjCell *)&cell->vfptr, &obj_frame);
                                  v23 = ObjectDesc::ScaleObj((ObjectDesc *)v18, v9, v10, kq);
                                  CPhysicsObj::SetScaleStatic(v22, v23);
                                  CLandBlock::add_static_object(v28, v22);
                                }
                                else
                                {
                                  v22->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)v22, 1u);
                                }
                              }
                              v15 = scene;
                            }
                            p.vfptr = (PackObjVtbl *)&PackObj::vftable;
                          }
                        }
                        v17 = v38 + scene_id;
                        v24 = kq++ + 1 < v15->num_objects;
                        scene_id += v38;
                        v35 += 112;
                        if ( !v24 )
                          break;
                        v16 = v43;
                      }
                    }
                    v15->vfptr->Release((Interface *)v15);
                  }
                }
                v1 = v28;
                v2 = region;
              }
            }
            v25 = v1->side_vertex_count;
            v27 = __OFSUB__(jq + 1, v25);
            v26 = jq++ + 1 - v25 < 0;
            v36 += 2;
          }
          while ( v26 ^ v27 );
        }
        v3 = v1->side_vertex_count;
        v27 = __OFSUB__(iq + 1, v3);
        v26 = iq++ + 1 - v3 < 0;
        v37 += 18;
      }
      while ( v26 ^ v27 );
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005309E0) --------------------------------------------------------  // acclient.c:352764
CLandBlock *__thiscall CLandBlock::scalar_deleting_destructor(CLandBlock *this, unsigned int a2)
{
  CLandBlock *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CLandBlock::vftable;
  this->vfptr = (PackObjVtbl *)&CLandBlock::vftable;
  CLandBlock::Destroy(this);
  operator delete[](v2->static_objects.data);
  v2->static_objects.data = 0;
  CLandBlockStruct::~CLandBlockStruct((CLandBlockStruct *)&v2->vertex_lighting);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8FA8: using guessed type void *CLandBlock::vftable;
// 7C8FC0: using guessed type __int32 (__stdcall *CLandBlock::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00530A40) --------------------------------------------------------  // acclient.c:352786
void __thiscall CLandBlock::init_static_objs(CLandBlock *this, LongNIValHash<unsigned long> *hash)
{
  CLandBlock *v2; // esi@1
  unsigned int v3; // ebx@3
  CPhysicsObj **v4; // eax@4
  CPhysicsObj *v5; // edi@4
  CLandBlockInfo *v6; // eax@9
  unsigned int v7; // ebp@10
  int v8; // ebx@11
  CPhysicsObj *v9; // edi@12
  int v10; // ST08_4@13
  int v11; // eax@13
  signed int v12; // eax@13
  int v13; // ebx@18
  int v14; // ebp@18
  CLandCell *v15; // edi@19
  const unsigned int v16; // eax@19
  int v17; // edi@19
  int v18; // eax@19
  unsigned int cell_id; // [sp+4h] [bp-58h]@13
  AC1Legacy::Vector3 loc; // [sp+8h] [bp-54h]@13
  Position p; // [sp+14h] [bp-48h]@13

  v2 = this;
  if ( this->side_cell_count == 8 )
  {
    if ( this->num_static_objects )
    {
      CLandBlock::adjust_scene_obj_height(this);
      v3 = 0;
      if ( v2->num_static_objects )
      {
        do
        {
          v4 = v2->static_objects.data;
          v5 = v4[v3];
          if ( v5 && !CPhysicsObj::is_completely_visible(v4[v3]) )
            CPhysicsObj::calc_cross_cells_static(v5);
          ++v3;
        }
        while ( v3 < v2->num_static_objects );
      }
    }
    else
    {
      v6 = this->lbi;
      if ( v6 )
      {
        v7 = 0;
        if ( v6->num_objects )
        {
          v8 = 0;
          do
          {
            v9 = CPhysicsObj::makeObject(v6->object_ids[v7], 0, 0);
            if ( v9 )
            {
              v10 = (int)&v2->lbi->object_frames[v8];
              p.objcell_id = v2->m_DID.id;
              Frame::operator=((int)&p.frame, v10);
              loc.y = p.frame.m_fOrigin.y;
              loc.z = p.frame.m_fOrigin.z;
              loc.x = p.frame.m_fOrigin.x;
              cell_id = p.objcell_id;
              v11 = LandDefs::adjust_to_outside(&cell_id, &loc);
              v12 = CLandBlock::get_landcell(v2, v11 != 0 ? cell_id : 0);
              if ( v12 )
              {
                CPhysicsObj::add_obj_to_cell(v9, (CObjCell *)v12, &v2->lbi->object_frames[v8]);
                CLandBlock::add_static_object(v2, v9);
              }
              else
              {
                v9->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)v9, 1u);
              }
            }
            v6 = v2->lbi;
            ++v7;
            ++v8;
          }
          while ( v7 < v6->num_objects );
        }
        if ( v2->side_cell_count * v2->side_cell_count > 0 )
        {
          v13 = 0;
          v14 = v2->side_cell_count * v2->side_cell_count;
          do
          {
            v15 = v2->lcell;
            v16 = v15[v13].m_DID.id;
            v17 = (int)&v15[v13];
            v18 = CLandBlockInfo::GetRestrictionIID(v2->lbi, v16);
            if ( v18 )
              *(_DWORD *)(v17 + 216) = v18;
            ++v13;
            --v14;
          }
          while ( v14 );
        }
      }
      if ( use_scene_files )
        CLandBlock::get_land_scenes(v2);
    }
    if ( v2->num_static_objects < v2->static_objects.sizeOf )
      DArray<CPhysicsObj *>::shrink(&v2->static_objects, v2->num_static_objects);
  }
}
// 81DEF8: using guessed type int use_scene_files;

//----- (006FEC90) --------------------------------------------------------  // acclient.c:786889
void sub_6FEC90()
{
  flt_844AE8 = 1000.0 + 1.0;
}

//----- (006FECB0) --------------------------------------------------------  // acclient.c:786895
void sub_6FECB0()
{
  flt_844AEC = 24.0 * 8.0;
}

//----- (006FECD0) --------------------------------------------------------  // acclient.c:786901
void sub_6FECD0()
{
  flt_844AF0 = 24.0 * 0.5;
}

//----- (006FECF0) --------------------------------------------------------  // acclient.c:786907
void sub_6FECF0()
{
  flt_844AF8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FED10) --------------------------------------------------------  // acclient.c:786913
void _E99_29()
{
  dbl_844B00 = 1.0 / 30.0;
}

//----- (006FED30) --------------------------------------------------------  // acclient.c:786919
void _E101_27()
{
  dbl_844B08 = 1.0 / 5.0;
}

//----- (006FED50) --------------------------------------------------------  // acclient.c:786925
int _E107_27()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_18;
  INITIAL_MAX_DATA_RATE_88 = LOWEST_DATA_RATE_18;
  return result;
}

//----- (006FED60) --------------------------------------------------------  // acclient.c:786935
int _E109_66()
{
  return atexit(nullsub_1141);
}

//----- (006FED70) --------------------------------------------------------  // acclient.c:786941
int _E112_89()
{
  return atexit(_E113_66);
}

//----- (006FED80) --------------------------------------------------------  // acclient.c:786947
int _E115_67()
{
  return atexit(_E116_58);
}

//----- (006FED90) --------------------------------------------------------  // acclient.c:786953
void _E118_67()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844B14, PFID_A8R8G8B8);
}

//----- (006FEDA0) --------------------------------------------------------  // acclient.c:786959
int _E120_54()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_15, "Sound.SoundDisabled");
  return atexit(sub_769340);
}

//----- (006FEDC0) --------------------------------------------------------  // acclient.c:786966
int _E123_32()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_15, "Sound.SoundVolume");
  return atexit(sub_769370);
}

//----- (006FEDE0) --------------------------------------------------------  // acclient.c:786973
int _E126_38()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_15, "Sound.AmbientSoundDisabled");
  return atexit(sub_7693A0);
}

//----- (006FEE00) --------------------------------------------------------  // acclient.c:786980
int _E129_30()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_15, "Sound.AmbientSoundVolume");
  return atexit(_E130_98);
}

//----- (006FEE20) --------------------------------------------------------  // acclient.c:786987
int _E132_33()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_15, "Sound.InterfaceSoundDisabled");
  return atexit(_E133_92);
}

//----- (006FEE40) --------------------------------------------------------  // acclient.c:786994
int _E135_36()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_15, "Sound.InterfaceSoundVolume");
  return atexit(_E136_75);
}

//----- (006FEE60) --------------------------------------------------------  // acclient.c:787001
int _E138_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_15, "Sound.SoundFeatures");
  return atexit(_E139_75);
}

//----- (006FEE80) --------------------------------------------------------  // acclient.c:787008
int _E141_28()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_15, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E142_70);
}

//----- (006FEEA0) --------------------------------------------------------  // acclient.c:787015
int _E144_27()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_15, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_844B70, "Mono");
  return atexit(_E145_72);
}

//----- (006FEED0) --------------------------------------------------------  // acclient.c:787023
void _E147_25()
{
  VOL_MIN_DIST_SQ_12 = 5.0 * 5.0;
}

//----- (006FEEF0) --------------------------------------------------------  // acclient.c:787029
void _E149_4()
{
  INV_LOG_OF_2_12 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006FEF10) --------------------------------------------------------  // acclient.c:787035
int sub_6FEF10()
{
  return atexit(nullsub_1145);
}

//----- (00769340) --------------------------------------------------------  // acclient.c:896136
void __cdecl sub_769340()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769370) --------------------------------------------------------  // acclient.c:896149
void __cdecl sub_769370()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007693A0) --------------------------------------------------------  // acclient.c:896162
void __cdecl sub_7693A0()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007693D0) --------------------------------------------------------  // acclient.c:896175
void __cdecl _E130_98()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769400) --------------------------------------------------------  // acclient.c:896188
void __cdecl _E133_92()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769430) --------------------------------------------------------  // acclient.c:896201
void __cdecl _E136_75()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769460) --------------------------------------------------------  // acclient.c:896214
void __cdecl _E139_75()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00769490) --------------------------------------------------------  // acclient.c:896227
void __cdecl _E142_70()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007694C0) --------------------------------------------------------  // acclient.c:896240
void __cdecl _E145_72()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_12;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

//----- (00769500) --------------------------------------------------------  // acclient.c:896265
void __cdecl _E153_47()
{
  obj_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

