/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPalShift
   Object     : PORTAL\cregion\CPalShift.obj
   Functions  : 25
   Addresses  : 004FFA40 - 006F9720 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FFA40) --------------------------------------------------------  // acclient.c:300239
void __stdcall PalShift::CleanupSurface(CSurface *surf)
{
  if ( surf )
  {
    Palette::releasePalette(surf->base1pal);
    CSurface::releaseCustomSurface(surf);
  }
}

//----- (004FFA60) --------------------------------------------------------  // acclient.c:300249
unsigned int __stdcall PalShift::GetBeginRotIx(int x, int y, unsigned int *pcode, int minimize_pal)
{
  unsigned int v5; // ecx@1
  unsigned __int64 v6; // rax@1

  v5 = -1;
  LODWORD(v6) = 0;
  if ( minimize_pal )
  {
    if ( *pcode < 0xFFFFFFFF )
      v5 = *pcode;
    if ( pcode[1] < v5 )
    {
      v5 = pcode[1];
      LODWORD(v6) = 1;
    }
    if ( pcode[2] < v5 )
    {
      v5 = pcode[2];
      LODWORD(v6) = 2;
    }
    if ( pcode[3] < v5 )
      LODWORD(v6) = 3;
  }
  else
  {
    v6 = (unsigned __int64)((double)(unsigned int)(1813693831 * y - x * (501661475 * y + 1109124029) + 1225298869)
                          * 2.3283064e-10
                          * 4.0);
  }
  return v6;
}

//----- (004FFAF0) --------------------------------------------------------  // acclient.c:300283
int __cdecl PackObj::ALIGN_PTR(void **ptr, unsigned int *size)
{
  int v2; // ecx@1
  int v3; // eax@2

  v2 = (signed int)*ptr % 4;
  if ( v2 )
  {
    v3 = 4 - v2;
    if ( *size < 4 - v2 )
      return 0;
    *size -= v3;
    if ( 4 != v2 )
    {
      do
      {
        *(_BYTE *)*ptr = 0;
        --v3;
        *ptr = (char *)*ptr + 1;
      }
      while ( v3 );
    }
  }
  return 1;
}

//----- (004FFB40) --------------------------------------------------------  // acclient.c:300310
void __thiscall Subpalette::Subpalette(Subpalette *this)
{
  this->vfptr = (PackObjVtbl *)&Subpalette::vftable;
  this->subID.id = stru_841508.id;
  this->offset = 0;
  this->numcolors = 0;
  this->prev = 0;
  this->next = 0;
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);

//----- (004FFB60) --------------------------------------------------------  // acclient.c:300322
void __thiscall PalShift::PalShift(PalShift *this)
{
  this->land_tex.m_data = 0;
  this->land_tex.m_size = 0;
  this->land_tex.m_num = 0;
  this->sub_pals = 0;
}

//----- (004FFB80) --------------------------------------------------------  // acclient.c:300331
void __thiscall PalShift::MakeSubPal(PalShift *this, unsigned int *numsubs, Subpalette **subs, unsigned int rot_ix, IDClass<_tagDataID,32,0> *palid, unsigned int rindex)
{
  unsigned int *v6; // ebx@1
  Subpalette **v7; // ebp@1
  PalShift *v8; // esi@1
  unsigned int v9; // eax@1
  Subpalette *v10; // ecx@1
  int v11; // edi@2
  void *v12; // eax@2
  Subpalette *v13; // eax@3
  int v14; // edi@8
  void *v15; // eax@8
  unsigned int v16; // ecx@12
  unsigned int v17; // edx@12
  unsigned int v18; // eax@12
  bool v19; // zf@12
  int v20; // ecx@13
  int v21; // edx@15
  IDClass<_tagDataID,32,0> tid[5]; // [sp+10h] [bp-14h]@12
  unsigned int *numsubsa; // [sp+28h] [bp+4h]@3
  unsigned int *numsubsb; // [sp+28h] [bp+4h]@9

  v6 = numsubs;
  v7 = subs;
  v8 = this;
  v9 = this->land_tex.m_data[this->cur_tex]->sub_pal.m_num;
  *numsubs = v9;
  v10 = *subs;
  if ( *subs )
  {
    if ( v9 <= v8->maxsubs )
      goto LABEL_12;
    if ( v10[-1].next )
      ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v10[-1].next);
    v14 = *numsubs;
    v15 = operator new[](24 * *numsubs + 4);
    if ( v15 )
    {
      *(_DWORD *)v15 = v14;
      numsubsb = (unsigned int *)((char *)v15 + 4);
      vector_constructor_iterator((char *)v15 + 4, 0x18u, v14, (void *(__thiscall *)(void *))Subpalette::Subpalette);
      v13 = (Subpalette *)numsubsb;
      goto LABEL_11;
    }
LABEL_10:
    v13 = 0;
    goto LABEL_11;
  }
  v8->maxsubs = v9;
  v11 = *numsubs;
  v12 = operator new[](24 * *numsubs + 4);
  if ( !v12 )
    goto LABEL_10;
  *(_DWORD *)v12 = v11;
  numsubsa = (unsigned int *)((char *)v12 + 4);
  vector_constructor_iterator((char *)v12 + 4, 0x18u, v11, (void *(__thiscall *)(void *))Subpalette::Subpalette);
  v13 = (Subpalette *)numsubsa;
LABEL_11:
  *subs = v13;
LABEL_12:
  tid[0].id = palid[rot_ix & 3].id;
  tid[1].id = palid[((_BYTE)rot_ix + 1) & 3].id;
  v16 = palid[((_BYTE)rot_ix - 1) & 3].id;
  tid[2].id = palid[((_BYTE)rot_ix - 2) & 3].id;
  v17 = palid[4].id;
  tid[3].id = v16;
  v18 = 0;
  v19 = *v6 == 0;
  tid[4].id = v17;
  if ( !v19 )
  {
    v20 = 0;
    while ( 1 )
    {
      (*v7)[v20].subID.id = tid[v8->land_tex.m_data[v8->cur_tex]->road_code.m_data[rindex]->sub_pal_type[v18]].id;
      v21 = (int)&(*v7)[v20];
      *(_DWORD *)(v21 + 8) = v8->land_tex.m_data[v8->cur_tex]->sub_pal.m_data[v18]->sub_pal_index;
      *(_DWORD *)(v21 + 12) = v8->land_tex.m_data[v8->cur_tex]->sub_pal.m_data[v18++]->sub_pal_length;
      ++v20;
      if ( v18 >= *v6 )
        break;
      v7 = subs;
    }
  }
}

//----- (004FFD00) --------------------------------------------------------  // acclient.c:300420
int __thiscall PalShift::CheckTerrain(PalShift *this, unsigned int pcode, IDClass<_tagDataID,32,0> *palid)
{
  IDClass<_tagDataID,32,0> *v3; // ebx@1
  PalShift *v4; // edx@1
  unsigned int v5; // ebp@1
  signed int v6; // edi@1
  signed int v7; // esi@2
  unsigned int v8; // eax@2
  PalShiftTerrainPal *v9; // ecx@3
  bool v10; // zf@3
  unsigned int v11; // ecx@8
  signed int v12; // eax@8
  int v13; // eax@10
  int v14; // eax@12
  int v15; // eax@14
  signed int i; // ecx@17
  PalShiftTerrainPal *v17; // eax@18
  int iq; // [sp+10h] [bp-8h]@1

  v3 = palid;
  v4 = this;
  v5 = this->land_tex.m_data[this->cur_tex]->terrain_pal.m_num;
  v6 = (char *)dword_7C614C - (char *)palid;
  iq = 0;
  do
  {
    v7 = 0;
    v8 = (pcode >> *(unsigned int *)((char *)&v3->id + v6)) & 0x1F;
    if ( (signed int)v5 > 0 )
    {
      do
      {
        v9 = v4->land_tex.m_data[v4->cur_tex]->terrain_pal.m_data[v7];
        v10 = v8 == v9->terrain_index;
        v3->id = v9->pal_id.id;
        if ( v10 )
          break;
        ++v7;
      }
      while ( v7 < (signed int)v5 );
      v6 = (char *)dword_7C614C - (char *)palid;
    }
    if ( v7 == v5 )
      return 0;
    ++v3;
    ++iq;
  }
  while ( (unsigned int)iq < 4 );
  v11 = pcode;
  v12 = 0;
  if ( pcode & 0xC000000 )
    v12 = 1;
  v13 = 2 * v12;
  if ( pcode & 0x3000000 )
    ++v13;
  v14 = 2 * v13;
  if ( v11 & 0xC00000 )
    ++v14;
  v15 = 2 * v14;
  if ( v11 & 0x300000 )
    ++v15;
  if ( v15 )
  {
    for ( i = 0; i < (signed int)v5; ++i )
    {
      v17 = v4->land_tex.m_data[v4->cur_tex]->terrain_pal.m_data[i];
      v10 = v17->terrain_index == 32;
      palid[4].id = v17->pal_id.id;
      if ( v10 )
        break;
    }
    if ( i == v5 )
      return 0;
  }
  return 1;
}

//----- (004FFE00) --------------------------------------------------------  // acclient.c:300498
int __thiscall PalShift::CheckRot(PalShift *this, unsigned int pcode, unsigned int *rindex)
{
  unsigned int v3; // eax@1
  signed int v4; // esi@1
  int v5; // esi@3
  int v6; // esi@5
  int v7; // esi@7
  PalShiftTex *v8; // edx@9
  unsigned int v9; // ecx@9
  unsigned int v10; // eax@9
  PalShiftRoadCode **v11; // edx@10
  int result; // eax@13

  v3 = pcode;
  v4 = 0;
  if ( pcode & 0xC000000 )
    v4 = 1;
  v5 = 2 * v4;
  if ( pcode & 0x3000000 )
    ++v5;
  v6 = 2 * v5;
  if ( v3 & 0xC00000 )
    ++v6;
  v7 = 2 * v6;
  if ( v3 & 0x300000 )
    ++v7;
  v8 = this->land_tex.m_data[this->cur_tex];
  v9 = v8->road_code.m_num;
  v10 = 0;
  if ( v9 )
  {
    v11 = v8->road_code.m_data;
    while ( (*v11)->road_code != v7 )
    {
      ++v10;
      ++v11;
      if ( v10 >= v9 )
        goto LABEL_13;
    }
    *rindex = v10;
    result = 1;
  }
  else
  {
LABEL_13:
    result = 0;
  }
  return result;
}

//----- (004FFE70) --------------------------------------------------------  // acclient.c:300549
signed int __thiscall PalShift::pack_size(PalShift *this)
{
  signed int result; // eax@1
  PalShiftTex **v2; // edi@2
  unsigned int v3; // ebx@2
  PalShiftTex *v4; // ecx@3
  unsigned int v5; // edx@3
  int v6; // esi@3
  int v7; // edx@5
  unsigned int v8; // ecx@5
  int v9; // edx@5

  result = 4;
  if ( this->land_tex.m_num )
  {
    v2 = this->land_tex.m_data;
    v3 = this->land_tex.m_num;
    do
    {
      v4 = *v2;
      v5 = (*v2)->sub_pal.m_num;
      v6 = 8;
      if ( v5 )
        v6 = 8 * v5 + 8;
      v7 = v4->road_code.m_num * (v5 + 1);
      v8 = v4->terrain_pal.m_num;
      v9 = v6 + 4 * v7 + 8;
      if ( v8 )
        v9 += 8 * v8;
      result += v9;
      ++v2;
      --v3;
    }
    while ( v3 );
  }
  return result;
}

//----- (004FFEC0) --------------------------------------------------------  // acclient.c:300588
void __thiscall PalShiftTex::Destroy(PalShiftTex *this)
{
  PalShiftTex *v1; // esi@1
  unsigned int v2; // edi@1
  PalShiftSubPal *v3; // eax@2
  void *v4; // ST04_4@3
  void *v5; // ecx@5
  unsigned int i; // ebx@5
  PalShiftRoadCode *v7; // edi@6
  void *v8; // ST00_4@11
  unsigned int j; // edi@11
  PalShiftTerrainPal *v10; // eax@12
  void *v11; // ST04_4@15

  v1 = this;
  v2 = 0;
  if ( this->sub_pal.m_num )
  {
    do
    {
      v3 = v1->sub_pal.m_data[v2];
      if ( v3 )
      {
        v4 = v1->sub_pal.m_data[v2];
        v3->sub_pal_index = 0;
        v3->sub_pal_length = 0;
        operator delete(v4);
      }
      ++v2;
    }
    while ( v2 < v1->sub_pal.m_num );
  }
  v5 = v1->sub_pal.m_data;
  v1->sub_pal.m_num = 0;
  v1->sub_pal.m_size = 0;
  operator delete[](v5);
  v1->sub_pal.m_data = 0;
  for ( i = 0; i < v1->road_code.m_num; ++i )
  {
    v7 = v1->road_code.m_data[i];
    if ( v7 )
    {
      if ( v7->sub_pal_type )
        operator delete[](v7->sub_pal_type);
      v7->sub_pal_type = 0;
      v7->road_code = 0;
      operator delete(v7);
    }
  }
  v8 = v1->road_code.m_data;
  v1->road_code.m_num = 0;
  v1->road_code.m_size = 0;
  operator delete[](v8);
  v1->road_code.m_data = 0;
  for ( j = 0; j < v1->terrain_pal.m_num; ++j )
  {
    v10 = v1->terrain_pal.m_data[j];
    if ( v10 )
    {
      v10->terrain_index = 31;
      v10->pal_id.id = stru_841508.id;
      operator delete(v10);
    }
  }
  v11 = v1->terrain_pal.m_data;
  v1->terrain_pal.m_num = 0;
  v1->terrain_pal.m_size = 0;
  operator delete[](v11);
  v1->terrain_pal.m_data = 0;
}

//----- (004FFFB0) --------------------------------------------------------  // acclient.c:300660
unsigned int __thiscall PalShiftTex::Pack(PalShiftTex *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // edx@1
  unsigned int v4; // esi@3
  unsigned int v5; // ebx@5
  PalShiftSubPal *v6; // esi@6
  int v7; // edi@7
  int v8; // edi@9
  int v9; // esi@10
  unsigned int v10; // ebx@14
  unsigned int v11; // edi@16
  unsigned int v12; // esi@19
  unsigned int v13; // esi@25
  unsigned int v14; // ebx@27
  PalShiftTerrainPal *v15; // esi@28
  int v16; // edi@29
  int v17; // edi@31
  int v18; // esi@32
  unsigned int sizea; // [sp+18h] [bp+8h]@3
  unsigned int sizeb; // [sp+18h] [bp+8h]@14
  unsigned int sizec; // [sp+18h] [bp+8h]@25

  v3 = size;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->tex_gid.id;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v4 = this->sub_pal.m_num;
  sizea = this->sub_pal.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v4;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v5 = 0;
  if ( v4 )
  {
    do
    {
      v6 = this->sub_pal.m_data[v5];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v6->sub_pal_index;
        *addr = (char *)*addr + 4;
        v7 = *v3 - 4;
        *v3 = v7;
        if ( (unsigned int)v7 >= 4 )
        {
          *(_DWORD *)*addr = v6->sub_pal_length;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      v8 = (signed int)*addr % 4;
      if ( v8 )
      {
        v9 = 4 - v8;
        if ( *v3 >= 4 - v8 )
        {
          *v3 -= v9;
          if ( 4 != v8 )
          {
            do
            {
              *(_BYTE *)*addr = 0;
              --v9;
              *addr = (char *)*addr + 1;
            }
            while ( v9 );
          }
        }
      }
      ++v5;
    }
    while ( v5 < sizea );
  }
  v10 = this->road_code.m_num;
  sizeb = this->road_code.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v10;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v11 = 0;
  if ( v10 )
  {
    do
    {
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = this->road_code.m_data[v11]->road_code;
        *addr = (char *)*addr + 4;
        *v3 -= 4;
      }
      v12 = 0;
      if ( this->sub_pal.m_num )
      {
        do
        {
          if ( *v3 >= 4 )
          {
            *(_DWORD *)*addr = this->road_code.m_data[v11]->sub_pal_type[v12];
            *addr = (char *)*addr + 4;
            *v3 -= 4;
          }
          ++v12;
        }
        while ( v12 < this->sub_pal.m_num );
        v10 = sizeb;
      }
      ++v11;
    }
    while ( v11 < v10 );
  }
  v13 = this->terrain_pal.m_num;
  sizec = this->terrain_pal.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v13;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v14 = 0;
  if ( v13 )
  {
    do
    {
      v15 = this->terrain_pal.m_data[v14];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v15->terrain_index;
        *addr = (char *)*addr + 4;
        v16 = *v3 - 4;
        *v3 = v16;
        if ( (unsigned int)v16 >= 4 )
        {
          *(_DWORD *)*addr = v15->pal_id.id;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      v17 = (signed int)*addr % 4;
      if ( v17 )
      {
        v18 = 4 - v17;
        if ( *v3 >= 4 - v17 )
        {
          *v3 -= v18;
          if ( 4 != v17 )
          {
            do
            {
              *(_BYTE *)*addr = 0;
              --v18;
              *addr = (char *)*addr + 1;
            }
            while ( v18 );
          }
        }
      }
      ++v14;
    }
    while ( v14 < sizec );
  }
  return *v3;
}

//----- (00500160) --------------------------------------------------------  // acclient.c:300832
void __thiscall PalShift::GetSubDataIDs(PalShift *this, QualifiedDataIDArray *id_array)
{
  PalShiftTex *v2; // esi@4
  QualifiedDataID *v3; // eax@5
  unsigned int v4; // edi@6
  IDClass<_tagDataID,32,0> v5; // eax@7
  QualifiedDataID *v6; // eax@8
  unsigned int iq; // [sp+10h] [bp-18h]@1
  PalShift *v8; // [sp+14h] [bp-14h]@1
  QualifiedDataID v9; // [sp+18h] [bp-10h]@5
  QualifiedDataID v10; // [sp+20h] [bp-8h]@8

  v8 = this;
  iq = 0;
  if ( this->land_tex.m_num )
  {
    while ( 1 )
    {
      v2 = this->land_tex.m_data[iq];
      if ( v2->tex_gid.id != stru_841508.id )
      {
        QualifiedDataID::QualifiedDataID(&v9, v2->tex_gid, 0);
        QualifiedDataIDArray::AddQDID(id_array, v3, 8u);
      }
      v4 = 0;
      if ( v2->terrain_pal.m_num )
      {
        do
        {
          v5.id = v2->terrain_pal.m_data[v4]->pal_id.id;
          if ( v5.id != stru_841508.id )
          {
            QualifiedDataID::QualifiedDataID(&v10, v5, 0);
            QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
          }
          ++v4;
        }
        while ( v4 < v2->terrain_pal.m_num );
      }
      ++iq;
      if ( iq >= v8->land_tex.m_num )
        break;
      this = v8;
    }
  }
}

//----- (00500210) --------------------------------------------------------  // acclient.c:300880
unsigned int __thiscall PalShift::SelectRot(PalShift *this, int x, int y, LandDefs::Rotation *rot, unsigned int *pal_code, unsigned int size, IDClass<_tagDataID,32,0> *palid, unsigned int *rindex, int minimize_pal)
{
  int v9; // esi@1
  PalShift *v10; // edi@1
  unsigned int v11; // ebp@1
  unsigned int v12; // ebp@3
  int v13; // esi@3
  unsigned int tnum; // [sp+10h] [bp-8h]@1
  unsigned int first_tnum; // [sp+14h] [bp-4h]@1

  v9 = y;
  v10 = this;
  v11 = (unsigned __int64)((double)(unsigned int)(1813693831 * y - x * (1647165151 * y + 1109124029) - 2031889191)
                         * 2.3283064e-10
                         * (double)this->land_tex.m_num);
  first_tnum = (unsigned __int64)((double)(unsigned int)(1813693831 * y - x * (1647165151 * y + 1109124029) - 2031889191)
                                * 2.3283064e-10
                                * (double)this->land_tex.m_num);
  tnum = (unsigned __int64)((double)(unsigned int)(1813693831 * y - x * (1647165151 * y + 1109124029) - 2031889191)
                          * 2.3283064e-10
                          * (double)this->land_tex.m_num);
  while ( 1 )
  {
    v10->cur_tex = v11;
    if ( PalShift::CheckTerrain(v10, *pal_code, palid) )
      break;
LABEL_7:
    if ( v11 == first_tnum )
    {
      v10->cur_tex = 0;
      *rot = 0;
      return *pal_code;
    }
  }
  v12 = PalShift::GetBeginRotIx(x, v9, pal_code, minimize_pal);
  v13 = v12;
  while ( !PalShift::CheckRot(v10, pal_code[v13], rindex) )
  {
    v13 = ((_BYTE)v13 + 1) & 3;
    if ( v13 == v12 )
    {
      v9 = y;
      tnum = (tnum + 1) % v10->land_tex.m_num;
      v11 = tnum;
      goto LABEL_7;
    }
  }
  *rot = v13;
  return pal_code[v13];
}

//----- (00500320) --------------------------------------------------------  // acclient.c:300932
CSurface *__thiscall PalShift::MakeNewSurface(PalShift *this, unsigned int pcode, unsigned int rot_ix, IDClass<_tagDataID,32,0> *palid, unsigned int rindex)
{
  unsigned int v5; // ebx@1
  Subpalette **v6; // esi@1
  Palette *v7; // eax@1
  Palette *v8; // edi@1
  CSurface *v9; // eax@3
  CSurface *v10; // esi@3

  v5 = this->land_tex.m_data[this->cur_tex]->tex_gid.id;
  v6 = &this->sub_pals;
  PalShift::MakeSubPal(this, &rindex, &this->sub_pals, rot_ix, palid, rindex);
  Palette::makeModifiedPalette();
  v8 = v7;
  if ( v7 )
    Palette::Modify(v7, rindex, *v6);
  CSurface::makeCustomSurface(SH_PALSHIFT);
  v10 = v9;
  CSurface::UseTextureMap(v9, (IDClass<_tagDataID,32,0>)v5, 1);
  CSurface::UsePalette(v10, v8);
  CSurface::InitEnd(v10, 0);
  return v10;
}

//----- (005003A0) --------------------------------------------------------  // acclient.c:300957
unsigned int __thiscall PalShift::Pack(PalShift *this, void **addr, unsigned int *size)
{
  unsigned int v3; // ebx@1
  unsigned int v4; // esi@3
  PalShift *v6; // [sp+10h] [bp-4h]@1

  v3 = this->land_tex.m_num;
  v6 = this;
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = v3;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  v4 = 0;
  if ( v3 )
  {
    while ( 1 )
    {
      PalShiftTex::Pack(this->land_tex.m_data[v4++], addr, size);
      if ( v4 >= v3 )
        break;
      this = v6;
    }
  }
  return *size;
}

//----- (005003F0) --------------------------------------------------------  // acclient.c:300986
int __thiscall PalShiftTex::UnPack(PalShiftTex *this, void **addr, unsigned int *size)
{
  void **v3; // esi@1
  unsigned int *v4; // edi@1
  PalShiftTex *v5; // ebx@1
  unsigned int v6; // ecx@2
  unsigned int *v7; // ebp@3
  int v8; // ebx@7
  void *v9; // eax@8
  void *v10; // ebp@8
  int v11; // eax@11
  int v12; // ecx@13
  int v13; // eax@14
  unsigned int v14; // eax@17
  unsigned int v15; // eax@19
  unsigned int *v16; // ecx@26
  unsigned int *v17; // ebx@28
  void *v18; // eax@29
  void *v19; // ebp@29
  void *v20; // eax@33
  PalShiftTex *v21; // edx@33
  unsigned int v22; // ecx@33
  unsigned int v23; // eax@37
  unsigned int v24; // eax@39
  unsigned int *v25; // ecx@47
  int v26; // ebx@50
  void *v27; // eax@51
  void *v28; // ebp@51
  void **v29; // edx@54
  int v30; // ecx@56
  int v31; // ecx@57
  int v32; // eax@58
  unsigned int v33; // eax@61
  unsigned int v34; // eax@63
  PalShiftTex *v36; // [sp+10h] [bp-4h]@1
  unsigned int *sizea; // [sp+1Ch] [bp+8h]@50

  v3 = addr;
  v4 = size;
  v5 = this;
  v36 = this;
  if ( *size < 4 || (v6 = *(_DWORD *)*addr, *addr = (char *)*addr + 4, *size -= 4, v5->tex_gid.id = v6, *size < 4) )
  {
    v7 = size;
  }
  else
  {
    v7 = *(unsigned int **)*addr;
    *addr = (char *)*addr + 4;
    size = v7;
    *v4 -= 4;
  }
  if ( v7 )
  {
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v5->sub_pal, (unsigned int)v7);
    if ( v7 )
    {
      v8 = (int)&v5->sub_pal;
      addr = (void **)v7;
      do
      {
        v9 = operator new(8u);
        v10 = 0;
        if ( v9 )
        {
          *(_DWORD *)v9 = 0;
          *((_DWORD *)v9 + 1) = 0;
          v10 = v9;
        }
        if ( *v4 >= 4 )
        {
          *(_DWORD *)v10 = *(_DWORD *)*v3;
          *v3 = (char *)*v3 + 4;
          v11 = *v4 - 4;
          *v4 = v11;
          if ( (unsigned int)v11 >= 4 )
          {
            *((_DWORD *)v10 + 1) = *(_DWORD *)*v3;
            *v3 = (char *)*v3 + 4;
            *v4 -= 4;
          }
        }
        v12 = (signed int)*v3 % 4;
        if ( v12 )
        {
          v13 = 4 - v12;
          if ( *v4 >= 4 - v12 )
          {
            *v4 -= v13;
            if ( 4 != v12 )
            {
              do
              {
                *(_BYTE *)*v3 = 0;
                --v13;
                *v3 = (char *)*v3 + 1;
              }
              while ( v13 );
            }
          }
        }
        v14 = *(_DWORD *)(v8 + 4);
        if ( *(_DWORD *)(v8 + 8) < v14
          || (!v14 ? (v15 = 8) : (v15 = 2 * v14),
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v8, v15)) )
          *(_DWORD *)(*(_DWORD *)v8 + 4 * (*(_DWORD *)(v8 + 8))++) = v10;
        addr = (void **)((char *)addr - 1);
      }
      while ( addr );
      v5 = v36;
      v7 = size;
    }
  }
  if ( *v4 >= 4 )
  {
    v16 = *(unsigned int **)*v3;
    *v3 = (char *)*v3 + 4;
    size = v16;
    *v4 -= 4;
    v7 = v16;
  }
  AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v5->road_code, (unsigned int)v7);
  if ( v7 )
  {
    v17 = size;
    addr = (void **)v7;
    while ( 1 )
    {
      v18 = operator new(8u);
      v19 = 0;
      if ( v18 )
      {
        *(_DWORD *)v18 = 0;
        *((_DWORD *)v18 + 1) = 0;
        v19 = v18;
      }
      if ( *v4 >= 4 )
      {
        *(_DWORD *)v19 = *(_DWORD *)*v3;
        *v3 = (char *)*v3 + 4;
        *v4 -= 4;
      }
      v20 = operator new[](4 * v36->sub_pal.m_num);
      v21 = v36;
      *((_DWORD *)v19 + 1) = v20;
      v22 = 0;
      if ( v36->sub_pal.m_num )
      {
        do
        {
          if ( *v4 >= 4 )
          {
            v17 = *(unsigned int **)*v3;
            *v3 = (char *)*v3 + 4;
            *v4 -= 4;
          }
          *(_DWORD *)(*((_DWORD *)v19 + 1) + 4 * v22++) = v17;
        }
        while ( v22 < v36->sub_pal.m_num );
      }
      v23 = v36->road_code.m_size;
      if ( v36->road_code.m_num >= v23 )
      {
        if ( v23 )
          v24 = 2 * v23;
        else
          v24 = 8;
        if ( !AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v36->road_code, v24) )
          goto LABEL_44;
        v21 = v36;
      }
      v21->road_code.m_data[v21->road_code.m_num++] = (PalShiftRoadCode *)v19;
LABEL_44:
      addr = (void **)((char *)addr - 1);
      if ( !addr )
      {
        v5 = v36;
        v7 = size;
        break;
      }
    }
  }
  if ( *v4 >= 4 )
  {
    v25 = *(unsigned int **)*v3;
    *v3 = (char *)*v3 + 4;
    *v4 -= 4;
    v7 = v25;
  }
  if ( v7 )
  {
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v5->terrain_pal, (unsigned int)v7);
    if ( v7 )
    {
      v26 = (int)&v5->terrain_pal;
      sizea = v7;
      do
      {
        v27 = operator new(8u);
        v28 = 0;
        if ( v27 )
        {
          *(_DWORD *)v27 = 31;
          *((_DWORD *)v27 + 1) = 0;
          v28 = v27;
        }
        if ( *v4 >= 4 )
        {
          v29 = *(void ***)*v3;
          *v3 = (char *)*v3 + 4;
          addr = v29;
          *v4 -= 4;
        }
        *(_DWORD *)v28 = addr;
        if ( *v4 >= 4 )
        {
          v30 = *(_DWORD *)*v3;
          *v3 = (char *)*v3 + 4;
          *v4 -= 4;
          *((_DWORD *)v28 + 1) = v30;
        }
        v31 = (signed int)*v3 % 4;
        if ( v31 )
        {
          v32 = 4 - v31;
          if ( *v4 >= 4 - v31 )
          {
            *v4 -= v32;
            if ( 4 != v31 )
            {
              do
              {
                *(_BYTE *)*v3 = 0;
                --v32;
                *v3 = (char *)*v3 + 1;
              }
              while ( v32 );
            }
          }
        }
        v33 = *(_DWORD *)(v26 + 4);
        if ( *(_DWORD *)(v26 + 8) < v33
          || (!v33 ? (v34 = 8) : (v34 = 2 * v33),
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v26, v34)) )
          *(_DWORD *)(*(_DWORD *)v26 + 4 * (*(_DWORD *)(v26 + 8))++) = v28;
        sizea = (unsigned int *)((char *)sizea - 1);
      }
      while ( sizea );
    }
  }
  return 1;
}

//----- (00500700) --------------------------------------------------------  // acclient.c:301240
void __thiscall PalShift::Destroy(PalShift *this)
{
  PalShift *v1; // esi@1
  unsigned int v2; // ebx@1
  PalShiftTex **v3; // eax@2
  PalShiftTex *v4; // edi@2
  void *v5; // ST10_4@5
  Subpalette *v6; // ecx@5

  v1 = this;
  v2 = 0;
  if ( this->land_tex.m_num )
  {
    do
    {
      v3 = v1->land_tex.m_data;
      v4 = v3[v2];
      if ( v4 )
      {
        PalShiftTex::Destroy(v3[v2]);
        operator delete[](v4->terrain_pal.m_data);
        operator delete[](v4->road_code.m_data);
        operator delete[](v4->sub_pal.m_data);
        operator delete(v4);
      }
      ++v2;
    }
    while ( v2 < v1->land_tex.m_num );
  }
  v5 = v1->land_tex.m_data;
  v1->land_tex.m_num = 0;
  v1->land_tex.m_size = 0;
  operator delete[](v5);
  v1->land_tex.m_data = 0;
  v6 = v1->sub_pals;
  if ( v6 )
  {
    if ( v6[-1].next )
    {
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(3);
      v1->sub_pals = 0;
      return;
    }
    operator delete[](&v6[-1].next);
  }
  v1->sub_pals = 0;
}

//----- (005007A0) --------------------------------------------------------  // acclient.c:301289
int __thiscall PalShift::UnPack(PalShift *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  PalShift *v4; // edi@1
  unsigned int v5; // ebp@2
  int result; // eax@7
  void *v7; // eax@9
  PalShiftTex *v8; // edi@10
  unsigned int v9; // eax@13
  unsigned int v10; // eax@15
  unsigned int iq; // [sp+10h] [bp-8h]@6
  PalShift *v12; // [sp+14h] [bp-4h]@1

  v3 = size;
  v4 = this;
  v12 = this;
  if ( *size < 4 )
  {
    v5 = (unsigned int)size;
  }
  else
  {
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  PalShift::Destroy(this);
  if ( v5 )
    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v4->land_tex, v5);
  iq = 0;
  if ( v5 > 0 )
  {
    while ( 1 )
    {
      v7 = operator new(0x28u);
      if ( v7 )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = 0;
        *((_DWORD *)v7 + 5) = 0;
        *((_DWORD *)v7 + 6) = 0;
        *((_DWORD *)v7 + 7) = 0;
        *((_DWORD *)v7 + 8) = 0;
        *((_DWORD *)v7 + 9) = 0;
        v8 = (PalShiftTex *)v7;
      }
      else
      {
        v8 = 0;
      }
      if ( !PalShiftTex::UnPack(v8, addr, v3) )
        break;
      v9 = v12->land_tex.m_size;
      if ( v12->land_tex.m_num < v9
        || (v9 <= 0 ? (v10 = 8) : (v10 = 2 * v9),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v12->land_tex, v10)) )
        v12->land_tex.m_data[v12->land_tex.m_num++] = v8;
      ++iq;
      if ( iq >= v5 )
        return 1;
      v3 = size;
    }
    result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005008B0) --------------------------------------------------------  // acclient.c:301364
void __thiscall PalShift::~PalShift(PalShift *this)
{
  PalShift *v1; // esi@1

  v1 = this;
  PalShift::Destroy(this);
  operator delete[](v1->land_tex.m_data);
}

//----- (006F96A0) --------------------------------------------------------  // acclient.c:782139
void _E73_83()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8414D0, PFID_A8R8G8B8);
}

//----- (006F96B0) --------------------------------------------------------  // acclient.c:782145
void sub_6F96B0()
{
  LODWORD(dword_84150C) = 1053364187;
}

//----- (006F96C0) --------------------------------------------------------  // acclient.c:782151
void sub_6F96C0()
{
  flt_841510 = 1000.0 + 1.0;
}

//----- (006F96E0) --------------------------------------------------------  // acclient.c:782157
void sub_6F96E0()
{
  flt_841514 = 24.0 * 8.0;
}

//----- (006F9700) --------------------------------------------------------  // acclient.c:782163
void sub_6F9700()
{
  flt_841518 = 24.0 * 0.5;
}

//----- (006F9720) --------------------------------------------------------  // acclient.c:782169
int sub_6F9720()
{
  return atexit(nullsub_1040);
}

