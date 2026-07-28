/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACQualityFilter
   Object     : AC\acqualities\ACQualityFilter.obj
   Functions  : 19
   Addresses  : 00450470 - 00710010 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00450470) --------------------------------------------------------  // acclient.c:141635
signed int ACQualityFilter::GetNumPositionStats()
{
  return 32;
}

//----- (004CC020) --------------------------------------------------------  // acclient.c:253405
signed int ACQualityFilter::GetDBOType()
{
  return 268435468;
}

//----- (00520070) --------------------------------------------------------  // acclient.c:334443
signed int ACQualityFilter::GetNumAttribute2ndStats()
{
  return 7;
}

//----- (005CBC00) --------------------------------------------------------  // acclient.c:503437
int __thiscall ACQualityFilter::SetAttribute(ACQualityFilter *this, unsigned int stype, const int val)
{
  ACQualityFilter *v3; // esi@1
  int v4; // eax@3
  void *v5; // eax@3

  v3 = this;
  if ( stype < ((int (*)(void))this->vfptr[5].IUnknown_AddRef)() )
  {
    if ( v3->_attribute_stat_filter )
    {
LABEL_5:
      v3->_attribute_stat_filter[stype] = val;
      return 1;
    }
    v4 = ((int (__thiscall *)(ACQualityFilter *))v3->vfptr[5].IUnknown_AddRef)(v3);
    v5 = operator new[](4 * v4);
    v3->_attribute_stat_filter = (int *)v5;
    if ( v5 )
    {
      memset(
        v3->_attribute_stat_filter,
        0,
        4 * ((unsigned int)(4 * ((int (__thiscall *)(ACQualityFilter *))v3->vfptr[5].IUnknown_AddRef)(v3)) >> 2));
      goto LABEL_5;
    }
  }
  return 0;
}

//----- (005CBC70) --------------------------------------------------------  // acclient.c:503468
int __thiscall ACQualityFilter::QueryAttribute2nd(ACQualityFilter *this, unsigned int stype)
{
  ACQualityFilter *v2; // esi@1
  int *v3; // eax@2
  int result; // eax@3

  v2 = this;
  if ( stype < ((int (*)(void))this->vfptr[5].IUnknown_Release)() && (v3 = v2->_attribute2nd_stat_filter) != 0 )
    result = v3[stype];
  else
    result = 0;
  return result;
}

//----- (005CBCA0) --------------------------------------------------------  // acclient.c:503483
int __thiscall ACQualityFilter::SetAttribute2nd(ACQualityFilter *this, unsigned int stype, const int val)
{
  ACQualityFilter *v3; // esi@1
  int v4; // eax@3
  void *v5; // eax@3

  v3 = this;
  if ( stype < ((int (*)(void))this->vfptr[5].IUnknown_Release)() )
  {
    if ( v3->_attribute2nd_stat_filter )
    {
LABEL_5:
      v3->_attribute2nd_stat_filter[stype] = val;
      return 1;
    }
    v4 = ((int (__thiscall *)(ACQualityFilter *))v3->vfptr[5].IUnknown_Release)(v3);
    v5 = operator new[](4 * v4);
    v3->_attribute2nd_stat_filter = (int *)v5;
    if ( v5 )
    {
      memset(
        v3->_attribute2nd_stat_filter,
        0,
        4 * ((unsigned int)(4 * ((int (__thiscall *)(ACQualityFilter *))v3->vfptr[5].IUnknown_Release)(v3)) >> 2));
      goto LABEL_5;
    }
  }
  return 0;
}

//----- (005CBD20) --------------------------------------------------------  // acclient.c:503514
void __thiscall ACQualityFilter::Clear(ACQualityFilter *this)
{
  ACQualityFilter *v1; // esi@1

  v1 = this;
  QualityFilter::Clear((QualityFilter *)&this->vfptr);
  if ( v1->_attribute_stat_filter )
  {
    operator delete[](v1->_attribute_stat_filter);
    v1->_attribute_stat_filter = 0;
  }
  if ( v1->_attribute2nd_stat_filter )
  {
    operator delete[](v1->_attribute2nd_stat_filter);
    v1->_attribute2nd_stat_filter = 0;
  }
  if ( v1->_skill_stat_filter )
  {
    operator delete[](v1->_skill_stat_filter);
    v1->_skill_stat_filter = 0;
  }
}

//----- (005CBD70) --------------------------------------------------------  // acclient.c:503538
signed int ACQualityFilter::GetNumFloatStats()
{
  return 512;
}

//----- (005CBD80) --------------------------------------------------------  // acclient.c:503544
signed int ACQualityFilter::GetNumBoolStats()
{
  return 256;
}

//----- (005CBD90) --------------------------------------------------------  // acclient.c:503550
signed int ACQualityFilter::GetNumDIDStats()
{
  return 64;
}

//----- (005CBDA0) --------------------------------------------------------  // acclient.c:503556
int __thiscall ACQualityFilter::pack_size(ACQualityFilter *this, unsigned int *num_attributes, unsigned int *num_attribute2nds, unsigned int *num_ints, unsigned int *num_int64s, unsigned int *num_bools, unsigned int *num_floats, unsigned int *num_dids, unsigned int *num_iids, unsigned int *num_strings, unsigned int *num_positions, unsigned int *num_skills)
{
  ACQualityFilter *v12; // esi@1
  int v13; // eax@1
  int v14; // ebx@1
  unsigned int v15; // edi@1
  int *v16; // eax@3
  int v17; // ebx@7
  unsigned int v18; // edi@7
  int *v19; // eax@9
  int v20; // ebx@13
  unsigned int v21; // edi@13
  int *v22; // eax@15

  v12 = this;
  v13 = QualityFilter::pack_size(
          (QualityFilter *)&this->vfptr,
          num_ints,
          num_int64s,
          num_bools,
          num_floats,
          num_dids,
          num_iids,
          num_strings,
          num_positions);
  *num_attributes = 0;
  *num_attribute2nds = 0;
  *num_skills = 0;
  v14 = v13 + 4;
  v15 = 0;
  if ( ((int (__thiscall *)(_DWORD))v12->vfptr[5].IUnknown_AddRef)(v12) )
  {
    do
    {
      if ( v15 < ((int (__thiscall *)(ACQualityFilter *))v12->vfptr[5].IUnknown_AddRef)(v12) )
      {
        v16 = v12->_attribute_stat_filter;
        if ( v16 )
        {
          if ( v16[v15] )
          {
            v14 += 4;
            ++*num_attributes;
          }
        }
      }
      ++v15;
    }
    while ( v15 < ((int (__thiscall *)(_DWORD))v12->vfptr[5].IUnknown_AddRef)(v12) );
  }
  v17 = v14 + 4;
  v18 = 0;
  if ( ((int (__thiscall *)(_DWORD))v12->vfptr[5].IUnknown_Release)(v12) )
  {
    do
    {
      if ( v18 < ((int (__thiscall *)(ACQualityFilter *))v12->vfptr[5].IUnknown_Release)(v12) )
      {
        v19 = v12->_attribute2nd_stat_filter;
        if ( v19 )
        {
          if ( v19[v18] )
          {
            v17 += 4;
            ++*num_attribute2nds;
          }
        }
      }
      ++v18;
    }
    while ( v18 < ((int (__thiscall *)(_DWORD))v12->vfptr[5].IUnknown_Release)(v12) );
  }
  v20 = v17 + 4;
  v21 = 0;
  if ( ((int (__thiscall *)(_DWORD))v12->vfptr[5].QueryInterface)(v12) )
  {
    do
    {
      if ( v21 < ((int (__thiscall *)(ACQualityFilter *))v12->vfptr[5].QueryInterface)(v12) )
      {
        v22 = v12->_skill_stat_filter;
        if ( v22 )
        {
          if ( v22[v21] )
          {
            v20 += 4;
            ++*num_skills;
          }
        }
      }
      ++v21;
    }
    while ( v21 < ((int (__thiscall *)(_DWORD))v12->vfptr[5].QueryInterface)(v12) );
  }
  return v20;
}

//----- (005CBEE0) --------------------------------------------------------  // acclient.c:503654
void __thiscall ACQualityFilter::ACQualityFilter(ACQualityFilter *this, IDClass<_tagDataID,32,0> did)
{
  ACQualityFilter *v2; // esi@1

  v2 = this;
  QualityFilter::QualityFilter((QualityFilter *)&this->vfptr, did);
  v2->_attribute_stat_filter = 0;
  v2->_attribute2nd_stat_filter = 0;
  v2->_skill_stat_filter = 0;
  v2->vfptr = (InterfaceVtbl *)&ACQualityFilter::vftable;
  v2->vfptr = (PackObjVtbl *)&ACQualityFilter::vftable;
}
// 7E8240: using guessed type void *ACQualityFilter::vftable;
// 7E8258: using guessed type __int32 (__stdcall *ACQualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CBF10) --------------------------------------------------------  // acclient.c:503670
QualityFilter *__thiscall ACQualityFilter::vector_deleting_destructor(ACQualityFilter *this, unsigned int a2)
{
  return ACQualityFilter::scalar_deleting_destructor((ACQualityFilter *)((char *)this - 48), a2);
}

//----- (005CBF20) --------------------------------------------------------  // acclient.c:503676
int __thiscall ACQualityFilter::Pack(ACQualityFilter *this, void **addr, unsigned int size)
{
  QualityFilter *v3; // ebx@1
  char *v4; // edi@1
  int v5; // ebp@1
  unsigned int v6; // ecx@2
  unsigned int v7; // edx@2
  char *v8; // eax@2
  char *v9; // ebx@2
  unsigned int v10; // ebx@2
  int v11; // eax@4
  unsigned int v12; // ebx@8
  int v13; // eax@10
  unsigned int v14; // ebx@14
  int v15; // eax@16
  unsigned int num_attributes; // [sp+10h] [bp-2Ch]@1
  unsigned int num_attribute2nds; // [sp+14h] [bp-28h]@1
  unsigned int num_skills; // [sp+18h] [bp-24h]@1
  unsigned int num_positions; // [sp+1Ch] [bp-20h]@1
  unsigned int num_strings; // [sp+20h] [bp-1Ch]@1
  unsigned int num_iids; // [sp+24h] [bp-18h]@1
  unsigned int num_dids; // [sp+28h] [bp-14h]@1
  unsigned int num_floats; // [sp+2Ch] [bp-10h]@1
  unsigned int num_bools; // [sp+30h] [bp-Ch]@1
  unsigned int num_int64s; // [sp+34h] [bp-8h]@1
  unsigned int num_ints; // [sp+38h] [bp-4h]@1

  v3 = (QualityFilter *)this;
  v4 = (char *)&this[-1]._int_stat_filter;
  v5 = ACQualityFilter::pack_size(
         (ACQualityFilter *)((char *)this - 48),
         &num_attributes,
         &num_attribute2nds,
         &num_ints,
         &num_int64s,
         &num_bools,
         &num_floats,
         &num_dids,
         &num_iids,
         &num_strings,
         &num_positions,
         &num_skills);
  if ( size >= v5 )
  {
    QualityFilter::Pack(v3, addr, size);
    v6 = num_attribute2nds;
    *(_DWORD *)*addr = num_attributes;
    v7 = num_skills;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v6;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v7;
    *addr = (char *)*addr + 4;
    v10 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 124))(v4) )
    {
      do
      {
        if ( v10 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 124))(v4) )
        {
          v11 = *((_DWORD *)v4 + 22);
          if ( v11 )
          {
            if ( *(_DWORD *)(v11 + 4 * v10) )
            {
              *(_DWORD *)*addr = v10;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v10;
      }
      while ( v10 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 124))(v4) );
    }
    v12 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 128))(v4) )
    {
      do
      {
        if ( v12 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 128))(v4) )
        {
          v13 = *((_DWORD *)v4 + 23);
          if ( v13 )
          {
            if ( *(_DWORD *)(v13 + 4 * v12) )
            {
              *(_DWORD *)*addr = v12;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v12;
      }
      while ( v12 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 128))(v4) );
    }
    v14 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4) )
    {
      do
      {
        if ( v14 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4) )
        {
          v15 = *((_DWORD *)v4 + 24);
          if ( v15 )
          {
            if ( *(_DWORD *)(v15 + 4 * v14) )
            {
              *(_DWORD *)*addr = v14;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v14;
      }
      while ( v14 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4) );
    }
  }
  return v5;
}

//----- (005CC080) --------------------------------------------------------  // acclient.c:503799
int __thiscall ACQualityFilter::UnPack(ACQualityFilter *this, void **addr, unsigned int size)
{
  QualityFilter *v3; // edi@1
  char *v4; // ebx@1
  void **v6; // esi@3
  int v7; // ecx@3
  char *v8; // eax@3
  void **v9; // ebp@3
  int v10; // edi@4
  unsigned int v11; // ST00_4@5
  void **v12; // edi@7
  unsigned int v13; // ST00_4@8
  unsigned int v14; // ebp@10
  int v15; // eax@12
  void *v16; // eax@12
  void *start; // [sp+Ch] [bp-4h]@3
  void **addra; // [sp+14h] [bp+4h]@3

  v3 = (QualityFilter *)this;
  v4 = (char *)&this[-1]._int_stat_filter;
  if ( size < TChessPiece<CBasePiece>::GetPackSize() + 12 )
    return 0;
  v6 = addr;
  start = *addr;
  (*(void (__thiscall **)(char *))(*(_DWORD *)v4 + 88))(v4);
  QualityFilter::UnPack(v3, addr, size);
  v7 = *(_DWORD *)*addr;
  v8 = (char *)*addr + 4;
  *addr = v8;
  v9 = *(void ***)v8;
  v8 += 4;
  *addr = v8;
  addra = *(void ***)v8;
  *v6 = v8 + 4;
  if ( v7 )
  {
    v10 = v7;
    do
    {
      v11 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      ACQualityFilter::SetAttribute((ACQualityFilter *)v4, v11, 1);
      --v10;
    }
    while ( v10 );
  }
  if ( v9 )
  {
    v12 = v9;
    do
    {
      v13 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      ACQualityFilter::SetAttribute2nd((ACQualityFilter *)v4, v13, 1);
      v12 = (void **)((char *)v12 - 1);
    }
    while ( v12 );
  }
  if ( addra )
  {
    while ( 1 )
    {
      v14 = *(_DWORD *)*v6;
      *v6 = (char *)*v6 + 4;
      if ( v14 < (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4) )
      {
        if ( *((_DWORD *)v4 + 24) )
          goto LABEL_14;
        v15 = (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4);
        v16 = operator new[](4 * v15);
        *((_DWORD *)v4 + 24) = v16;
        if ( v16 )
          break;
      }
LABEL_15:
      addra = (void **)((char *)addra - 1);
      if ( !addra )
        return size >= (_BYTE *)*v6 - (_BYTE *)start;
    }
    memset(
      *((void **)v4 + 24),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v4 + 132))(v4)) >> 2));
LABEL_14:
    *(_DWORD *)(*((_DWORD *)v4 + 24) + 4 * v14) = 1;
    goto LABEL_15;
  }
  return size >= (_BYTE *)*v6 - (_BYTE *)start;
}

//----- (005CC1C0) --------------------------------------------------------  // acclient.c:503890
QualityFilter *__thiscall ACQualityFilter::scalar_deleting_destructor(ACQualityFilter *this, unsigned int a2)
{
  QualityFilter *v2; // esi@1

  v2 = (QualityFilter *)this;
  this->vfptr = (InterfaceVtbl *)&ACQualityFilter::vftable;
  this->vfptr = (PackObjVtbl *)&ACQualityFilter::vftable;
  ACQualityFilter::Clear(this);
  QualityFilter::~QualityFilter(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E8240: using guessed type void *ACQualityFilter::vftable;
// 7E8258: using guessed type __int32 (__stdcall *ACQualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CC200) --------------------------------------------------------  // acclient.c:503907
QualityFilter *__thiscall QualityFilter::vector_deleting_destructor(QualityFilter *this, unsigned int a2)
{
  QualityFilter *v2; // esi@1

  v2 = this;
  QualityFilter::~QualityFilter(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005CC220) --------------------------------------------------------  // acclient.c:503919
QualityFilter *__thiscall QualityFilter::vector_deleting_destructor(QualityFilter *this, unsigned int a2)
{
  return QualityFilter::vector_deleting_destructor((QualityFilter *)((char *)this - 48), a2);
}

//----- (00710010) --------------------------------------------------------  // acclient.c:803283
int sub_710010()
{
  return atexit(nullsub_1836);
}

