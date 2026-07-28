/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QualityFilter
   Object     : PORTAL\qualities\QualityFilter.obj
   Functions  : 9
   Addresses  : 006B1EC0 - 006B25C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B1EC0) --------------------------------------------------------  // acclient.c:715308
void __thiscall QualityFilter::Clear(QualityFilter *this)
{
  QualityFilter *v1; // esi@1

  v1 = this;
  if ( this->_int_stat_filter )
  {
    operator delete[](this->_int_stat_filter);
    v1->_int_stat_filter = 0;
  }
  if ( v1->_int64_stat_filter )
  {
    operator delete[](v1->_int64_stat_filter);
    v1->_int64_stat_filter = 0;
  }
  if ( v1->_bool_stat_filter )
  {
    operator delete[](v1->_bool_stat_filter);
    v1->_bool_stat_filter = 0;
  }
  if ( v1->_float_stat_filter )
  {
    operator delete[](v1->_float_stat_filter);
    v1->_float_stat_filter = 0;
  }
  if ( v1->_string_stat_filter )
  {
    operator delete[](v1->_string_stat_filter);
    v1->_string_stat_filter = 0;
  }
  if ( v1->_did_stat_filter )
  {
    operator delete[](v1->_did_stat_filter);
    v1->_did_stat_filter = 0;
  }
  if ( v1->_iid_stat_filter )
  {
    operator delete[](v1->_iid_stat_filter);
    v1->_iid_stat_filter = 0;
  }
  if ( v1->_position_stat_filter )
  {
    operator delete[](v1->_position_stat_filter);
    v1->_position_stat_filter = 0;
  }
}

//----- (006B1F70) --------------------------------------------------------  // acclient.c:715356
int __thiscall QualityFilter::QueryInt(QualityFilter *this, unsigned int stype)
{
  QualityFilter *v2; // esi@1
  int *v3; // eax@2
  int result; // eax@3

  v2 = this;
  if ( stype < ((int (*)(void))this->vfptr[3].Release)() && (v3 = v2->_int_stat_filter) != 0 )
    result = v3[stype];
  else
    result = 0;
  return result;
}

//----- (006B1FA0) --------------------------------------------------------  // acclient.c:715371
int __thiscall QualityFilter::SetInt(QualityFilter *this, unsigned int stype, const int val)
{
  QualityFilter *v3; // esi@1
  int v4; // eax@3
  void *v5; // eax@3

  v3 = this;
  if ( stype < ((int (*)(void))this->vfptr[3].Release)() )
  {
    if ( v3->_int_stat_filter )
    {
LABEL_5:
      v3->_int_stat_filter[stype] = val;
      return 1;
    }
    v4 = v3->vfptr[3].Release((Interface *)v3);
    v5 = operator new[](4 * v4);
    v3->_int_stat_filter = (int *)v5;
    if ( v5 )
    {
      memset(v3->_int_stat_filter, 0, 4 * (4 * v3->vfptr[3].Release((Interface *)v3) >> 2));
      goto LABEL_5;
    }
  }
  return 0;
}

//----- (006B2010) --------------------------------------------------------  // acclient.c:715399
int __thiscall QualityFilter::QueryFloat(QualityFilter *this, unsigned int stype)
{
  QualityFilter *v2; // esi@1
  int *v3; // eax@2
  int result; // eax@3

  v2 = this;
  if ( stype < ((int (*)(void))this->vfptr[4].IUnknown_Release)() && (v3 = v2->_float_stat_filter) != 0 )
    result = v3[stype];
  else
    result = 0;
  return result;
}

//----- (006B2050) --------------------------------------------------------  // acclient.c:715420
int __thiscall QualityFilter::pack_size(QualityFilter *this, unsigned int *num_ints, unsigned int *num_int64s, unsigned int *num_bools, unsigned int *num_floats, unsigned int *num_dids, unsigned int *num_iids, unsigned int *num_strings, unsigned int *num_positions)
{
  QualityFilter *v9; // esi@1
  signed int v10; // ebp@1
  unsigned int v11; // edi@1
  int *v12; // eax@3
  int v13; // ebp@7
  unsigned int v14; // edi@7
  int *v15; // eax@9
  int v16; // ebp@13
  unsigned int v17; // edi@13
  int *v18; // eax@15
  int v19; // ebp@19
  unsigned int v20; // edi@19
  int *v21; // eax@21
  int v22; // ebp@25
  unsigned int v23; // edi@25
  int *v24; // eax@27
  int v25; // ebp@31
  unsigned int v26; // edi@31
  int *v27; // eax@33
  int v28; // ebp@37
  unsigned int v29; // edi@37
  int *v30; // eax@39
  int v31; // ebp@43
  unsigned int v32; // edi@43
  int *v33; // eax@45

  *num_ints = 0;
  *num_int64s = 0;
  v9 = this;
  *num_bools = 0;
  *num_floats = 0;
  *num_dids = 0;
  *num_iids = 0;
  *num_strings = 0;
  *num_positions = 0;
  v10 = 4;
  v11 = 0;
  if ( ((int (*)(void))this->vfptr[3].Release)() > 0 )
  {
    do
    {
      if ( v11 < v9->vfptr[3].Release((Interface *)v9) )
      {
        v12 = v9->_int_stat_filter;
        if ( v12 )
        {
          if ( v12[v11] )
          {
            v10 += 4;
            ++*num_ints;
          }
        }
      }
      ++v11;
    }
    while ( (signed int)v11 < (int)v9->vfptr[3].Release((Interface *)v9) );
  }
  v13 = v10 + 4;
  v14 = 0;
  if ( ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_QueryInterface)(v9) > 0 )
  {
    do
    {
      if ( v14 < ((int (__thiscall *)(QualityFilter *))v9->vfptr[4].IUnknown_QueryInterface)(v9) )
      {
        v15 = v9->_int64_stat_filter;
        if ( v15 )
        {
          if ( v15[v14] )
          {
            v13 += 4;
            ++*num_int64s;
          }
        }
      }
      ++v14;
    }
    while ( (signed int)v14 < ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_QueryInterface)(v9) );
  }
  v16 = v13 + 4;
  v17 = 0;
  if ( ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_AddRef)(v9) > 0 )
  {
    do
    {
      if ( v17 < ((int (__thiscall *)(QualityFilter *))v9->vfptr[4].IUnknown_AddRef)(v9) )
      {
        v18 = v9->_bool_stat_filter;
        if ( v18 )
        {
          if ( v18[v17] )
          {
            v16 += 4;
            ++*num_bools;
          }
        }
      }
      ++v17;
    }
    while ( (signed int)v17 < ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_AddRef)(v9) );
  }
  v19 = v16 + 4;
  v20 = 0;
  if ( ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_Release)(v9) > 0 )
  {
    do
    {
      if ( v20 < ((int (__thiscall *)(QualityFilter *))v9->vfptr[4].IUnknown_Release)(v9) )
      {
        v21 = v9->_float_stat_filter;
        if ( v21 )
        {
          if ( v21[v20] )
          {
            v19 += 4;
            ++*num_floats;
          }
        }
      }
      ++v20;
    }
    while ( (signed int)v20 < ((int (__thiscall *)(_DWORD))v9->vfptr[4].IUnknown_Release)(v9) );
  }
  v22 = v19 + 4;
  v23 = 0;
  if ( ((int (__thiscall *)(_DWORD))v9->vfptr[4].QueryInterface)(v9) > 0 )
  {
    do
    {
      if ( v23 < ((int (__thiscall *)(QualityFilter *))v9->vfptr[4].QueryInterface)(v9) )
      {
        v24 = v9->_did_stat_filter;
        if ( v24 )
        {
          if ( v24[v23] )
          {
            v22 += 4;
            ++*num_dids;
          }
        }
      }
      ++v23;
    }
    while ( (signed int)v23 < ((int (__thiscall *)(_DWORD))v9->vfptr[4].QueryInterface)(v9) );
  }
  v25 = v22 + 4;
  v26 = 0;
  if ( (int)v9->vfptr[4].AddRef((Interface *)v9) > 0 )
  {
    do
    {
      if ( v26 < v9->vfptr[4].AddRef((Interface *)v9) )
      {
        v27 = v9->_iid_stat_filter;
        if ( v27 )
        {
          if ( v27[v26] )
          {
            v25 += 4;
            ++*num_iids;
          }
        }
      }
      ++v26;
    }
    while ( (signed int)v26 < (int)v9->vfptr[4].AddRef((Interface *)v9) );
  }
  v28 = v25 + 4;
  v29 = 0;
  if ( (int)v9->vfptr[4].Release((Interface *)v9) > 0 )
  {
    do
    {
      if ( v29 < v9->vfptr[4].Release((Interface *)v9) )
      {
        v30 = v9->_string_stat_filter;
        if ( v30 )
        {
          if ( v30[v29] )
          {
            v28 += 4;
            ++*num_strings;
          }
        }
      }
      ++v29;
    }
    while ( (signed int)v29 < (int)v9->vfptr[4].Release((Interface *)v9) );
  }
  v31 = v28 + 4;
  v32 = 0;
  if ( ((int (__thiscall *)(_DWORD))v9->vfptr[5].IUnknown_QueryInterface)(v9) > 0 )
  {
    do
    {
      if ( v32 < ((int (__thiscall *)(QualityFilter *))v9->vfptr[5].IUnknown_QueryInterface)(v9) )
      {
        v33 = v9->_position_stat_filter;
        if ( v33 )
        {
          if ( v33[v32] )
          {
            v31 += 4;
            ++*num_positions;
          }
        }
      }
      ++v32;
    }
    while ( (signed int)v32 < ((int (__thiscall *)(_DWORD))v9->vfptr[5].IUnknown_QueryInterface)(v9) );
  }
  return v31;
}

//----- (006B22B0) --------------------------------------------------------  // acclient.c:715637
void __thiscall QualityFilter::QualityFilter(QualityFilter *this, IDClass<_tagDataID,32,0> did)
{
  QualityFilter *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->_int_stat_filter = 0;
  v2->_int64_stat_filter = 0;
  v2->_bool_stat_filter = 0;
  v2->_float_stat_filter = 0;
  v2->_string_stat_filter = 0;
  v2->_did_stat_filter = 0;
  v2->_iid_stat_filter = 0;
  v2->_position_stat_filter = 0;
  v2->vfptr = (InterfaceVtbl *)&QualityFilter::vftable;
  v2->vfptr = (PackObjVtbl *)&QualityFilter::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E82E0: using guessed type int (__stdcall *QualityFilter::vftable)(int);
// 7E82F8: using guessed type __int32 (__stdcall *QualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006B2300) --------------------------------------------------------  // acclient.c:715660
void __thiscall QualityFilter::~QualityFilter(QualityFilter *this)
{
  QualityFilter *v1; // esi@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&QualityFilter::vftable;
  this->vfptr = (PackObjVtbl *)&QualityFilter::vftable;
  QualityFilter::Clear(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E82E0: using guessed type int (__stdcall *QualityFilter::vftable)(int);
// 7E82F8: using guessed type __int32 (__stdcall *QualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006B2330) --------------------------------------------------------  // acclient.c:715676
int __thiscall QualityFilter::Pack(QualityFilter *this, void **addr, unsigned int size)
{
  char *v3; // edi@1
  int v4; // ebp@1
  unsigned int v5; // edx@2
  char *v6; // ecx@2
  unsigned int v7; // ecx@2
  char *v8; // eax@2
  char *v9; // ebx@2
  char *v10; // edx@2
  unsigned int v11; // edx@2
  char *v12; // ecx@2
  unsigned int v13; // ecx@2
  char *v14; // eax@2
  char *v15; // ebx@2
  unsigned int v16; // ebx@2
  int v17; // eax@4
  unsigned int v18; // ebx@8
  int v19; // eax@10
  unsigned int v20; // ebx@14
  int v21; // eax@16
  unsigned int v22; // ebx@20
  int v23; // eax@22
  unsigned int v24; // ebx@26
  int v25; // eax@28
  unsigned int v26; // ebx@32
  int v27; // eax@34
  unsigned int v28; // ebx@38
  int v29; // eax@40
  unsigned int v30; // ebx@44
  int v31; // eax@46
  unsigned int num_ints; // [sp+10h] [bp-20h]@1
  unsigned int num_int64s; // [sp+14h] [bp-1Ch]@1
  unsigned int num_bools; // [sp+18h] [bp-18h]@1
  unsigned int num_floats; // [sp+1Ch] [bp-14h]@1
  unsigned int num_dids; // [sp+20h] [bp-10h]@1
  unsigned int num_iids; // [sp+24h] [bp-Ch]@1
  unsigned int num_strings; // [sp+28h] [bp-8h]@1
  unsigned int num_positions; // [sp+2Ch] [bp-4h]@1

  v3 = (char *)&this[-1].m_DID;
  v4 = QualityFilter::pack_size(
         (QualityFilter *)((char *)this - 48),
         &num_ints,
         &num_int64s,
         &num_bools,
         &num_floats,
         &num_dids,
         &num_iids,
         &num_strings,
         &num_positions);
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = num_ints;
    v5 = num_bools;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = num_int64s;
    v7 = num_floats;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v5;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v7;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = num_dids;
    v11 = num_strings;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = num_iids;
    v13 = num_positions;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(_DWORD *)v14 = v11;
    v15 = (char *)*addr + 4;
    *addr = v15;
    *(_DWORD *)v15 = v13;
    *addr = (char *)*addr + 4;
    v16 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 92))(v3) > 0 )
    {
      do
      {
        if ( v16 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 92))(v3) )
        {
          v17 = *((_DWORD *)v3 + 14);
          if ( v17 )
          {
            if ( *(_DWORD *)(v17 + 4 * v16) )
            {
              *(_DWORD *)*addr = v16;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v16;
      }
      while ( (signed int)v16 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 92))(v3) );
    }
    v18 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 96))(v3) > 0 )
    {
      do
      {
        if ( v18 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 96))(v3) )
        {
          v19 = *((_DWORD *)v3 + 15);
          if ( v19 )
          {
            if ( *(_DWORD *)(v19 + 4 * v18) )
            {
              *(_DWORD *)*addr = v18;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v18;
      }
      while ( (signed int)v18 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 96))(v3) );
    }
    v20 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 100))(v3) > 0 )
    {
      do
      {
        if ( v20 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 100))(v3) )
        {
          v21 = *((_DWORD *)v3 + 16);
          if ( v21 )
          {
            if ( *(_DWORD *)(v21 + 4 * v20) )
            {
              *(_DWORD *)*addr = v20;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v20;
      }
      while ( (signed int)v20 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 100))(v3) );
    }
    v22 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 104))(v3) > 0 )
    {
      do
      {
        if ( v22 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 104))(v3) )
        {
          v23 = *((_DWORD *)v3 + 17);
          if ( v23 )
          {
            if ( *(_DWORD *)(v23 + 4 * v22) )
            {
              *(_DWORD *)*addr = v22;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v22;
      }
      while ( (signed int)v22 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 104))(v3) );
    }
    v24 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 108))(v3) > 0 )
    {
      do
      {
        if ( v24 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 108))(v3) )
        {
          v25 = *((_DWORD *)v3 + 19);
          if ( v25 )
          {
            if ( *(_DWORD *)(v25 + 4 * v24) )
            {
              *(_DWORD *)*addr = v24;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v24;
      }
      while ( (signed int)v24 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 108))(v3) );
    }
    v26 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 112))(v3) > 0 )
    {
      do
      {
        if ( v26 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 112))(v3) )
        {
          v27 = *((_DWORD *)v3 + 20);
          if ( v27 )
          {
            if ( *(_DWORD *)(v27 + 4 * v26) )
            {
              *(_DWORD *)*addr = v26;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v26;
      }
      while ( (signed int)v26 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 112))(v3) );
    }
    v28 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 116))(v3) > 0 )
    {
      do
      {
        if ( v28 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 116))(v3) )
        {
          v29 = *((_DWORD *)v3 + 18);
          if ( v29 )
          {
            if ( *(_DWORD *)(v29 + 4 * v28) )
            {
              *(_DWORD *)*addr = v28;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v28;
      }
      while ( (signed int)v28 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 116))(v3) );
    }
    v30 = 0;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 120))(v3) > 0 )
    {
      do
      {
        if ( v30 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 120))(v3) )
        {
          v31 = *((_DWORD *)v3 + 21);
          if ( v31 )
          {
            if ( *(_DWORD *)(v31 + 4 * v30) )
            {
              *(_DWORD *)*addr = v30;
              *addr = (char *)*addr + 4;
            }
          }
        }
        ++v30;
      }
      while ( (signed int)v30 < (*(int (__thiscall **)(char *))(*(_DWORD *)v3 + 120))(v3) );
    }
  }
  return v4;
}

//----- (006B25C0) --------------------------------------------------------  // acclient.c:715929
int __thiscall QualityFilter::UnPack(QualityFilter *this, void **addr, unsigned int size)
{
  void **v4; // ebx@3
  char *v5; // esi@3
  void **v6; // ecx@3
  char *v7; // eax@3
  unsigned int v8; // edi@3
  unsigned int v9; // ebp@3
  unsigned int v10; // edx@3
  unsigned int v11; // edx@3
  unsigned int v12; // edx@3
  unsigned int v13; // edx@3
  unsigned int v14; // ST00_4@5
  unsigned int v15; // ebp@8
  int v16; // eax@10
  void *v17; // eax@10
  unsigned int v18; // ebp@17
  int v19; // eax@19
  void *v20; // eax@19
  unsigned int v21; // ebp@25
  int v22; // eax@27
  void *v23; // eax@27
  unsigned int v24; // ebp@33
  int v25; // eax@35
  void *v26; // eax@35
  unsigned int v27; // ebp@41
  int v28; // eax@43
  void *v29; // eax@43
  unsigned int v30; // ebp@49
  int v31; // eax@51
  void *v32; // eax@51
  unsigned int v33; // ebp@57
  int v34; // eax@59
  void *v35; // eax@59
  unsigned int num_bools; // [sp+0h] [bp-1Ch]@3
  unsigned int num_floats; // [sp+4h] [bp-18h]@3
  unsigned int num_dids; // [sp+8h] [bp-14h]@3
  unsigned int num_iids; // [sp+Ch] [bp-10h]@3
  unsigned int num_strings; // [sp+10h] [bp-Ch]@3
  unsigned int num_positions; // [sp+14h] [bp-8h]@3
  void *start; // [sp+18h] [bp-4h]@3
  void **addra; // [sp+20h] [bp+4h]@4
  void **addrb; // [sp+20h] [bp+4h]@7
  void **addrc; // [sp+20h] [bp+4h]@16
  void **addrd; // [sp+20h] [bp+4h]@24
  void **addre; // [sp+20h] [bp+4h]@32
  void **addrf; // [sp+20h] [bp+4h]@40
  void **addrg; // [sp+20h] [bp+4h]@48
  void **addrh; // [sp+20h] [bp+4h]@56

  if ( size < 0x1C )
    return 0;
  v4 = addr;
  v5 = (char *)&this[-1].m_DID;
  start = *addr;
  (*(void (__thiscall **)(IDClass<_tagDataID,32,0> *))(this[-1].m_DID.id + 88))(&this[-1].m_DID);
  v6 = *(void ***)*addr;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v8 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  v9 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  v10 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  num_floats = v10;
  v11 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  num_dids = v11;
  v12 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  num_iids = v12;
  v13 = *(_DWORD *)v7;
  v7 += 4;
  *addr = v7;
  num_strings = v13;
  num_bools = v9;
  num_positions = *(_DWORD *)v7;
  *addr = v7 + 4;
  if ( (signed int)v6 > 0 )
  {
    addra = v6;
    do
    {
      v14 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      QualityFilter::SetInt((QualityFilter *)v5, v14, 1);
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
  }
  if ( (signed int)v8 > 0 )
  {
    addrb = (void **)v8;
    while ( 1 )
    {
      v15 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v15 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 96))(v5) )
      {
        if ( *((_DWORD *)v5 + 15) )
          goto LABEL_12;
        v16 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 96))(v5);
        v17 = operator new[](4 * v16);
        *((_DWORD *)v5 + 15) = v17;
        if ( v17 )
          break;
      }
LABEL_13:
      addrb = (void **)((char *)addrb - 1);
      if ( !addrb )
      {
        v9 = num_bools;
        goto LABEL_15;
      }
    }
    memset(
      *((void **)v5 + 15),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 96))(v5)) >> 2));
LABEL_12:
    *(_DWORD *)(*((_DWORD *)v5 + 15) + 4 * v15) = 1;
    goto LABEL_13;
  }
LABEL_15:
  if ( (signed int)v9 > 0 )
  {
    addrc = (void **)v9;
    while ( 1 )
    {
      v18 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v18 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 100))(v5) )
      {
        if ( *((_DWORD *)v5 + 16) )
          goto LABEL_21;
        v19 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 100))(v5);
        v20 = operator new[](4 * v19);
        *((_DWORD *)v5 + 16) = v20;
        if ( v20 )
          break;
      }
LABEL_22:
      addrc = (void **)((char *)addrc - 1);
      if ( !addrc )
        goto LABEL_23;
    }
    memset(
      *((void **)v5 + 16),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 100))(v5)) >> 2));
LABEL_21:
    *(_DWORD *)(*((_DWORD *)v5 + 16) + 4 * v18) = 1;
    goto LABEL_22;
  }
LABEL_23:
  if ( (signed int)num_floats > 0 )
  {
    addrd = (void **)num_floats;
    while ( 1 )
    {
      v21 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v21 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 104))(v5) )
      {
        if ( *((_DWORD *)v5 + 17) )
          goto LABEL_29;
        v22 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 104))(v5);
        v23 = operator new[](4 * v22);
        *((_DWORD *)v5 + 17) = v23;
        if ( v23 )
          break;
      }
LABEL_30:
      addrd = (void **)((char *)addrd - 1);
      if ( !addrd )
        goto LABEL_31;
    }
    memset(
      *((void **)v5 + 17),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 104))(v5)) >> 2));
LABEL_29:
    *(_DWORD *)(*((_DWORD *)v5 + 17) + 4 * v21) = 1;
    goto LABEL_30;
  }
LABEL_31:
  if ( (signed int)num_dids > 0 )
  {
    addre = (void **)num_dids;
    while ( 1 )
    {
      v24 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v24 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 108))(v5) )
      {
        if ( *((_DWORD *)v5 + 19) )
          goto LABEL_37;
        v25 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 108))(v5);
        v26 = operator new[](4 * v25);
        *((_DWORD *)v5 + 19) = v26;
        if ( v26 )
          break;
      }
LABEL_38:
      addre = (void **)((char *)addre - 1);
      if ( !addre )
        goto LABEL_39;
    }
    memset(
      *((void **)v5 + 19),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 108))(v5)) >> 2));
LABEL_37:
    *(_DWORD *)(*((_DWORD *)v5 + 19) + 4 * v24) = 1;
    goto LABEL_38;
  }
LABEL_39:
  if ( (signed int)num_iids > 0 )
  {
    addrf = (void **)num_iids;
    while ( 1 )
    {
      v27 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v27 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 112))(v5) )
      {
        if ( *((_DWORD *)v5 + 20) )
          goto LABEL_45;
        v28 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 112))(v5);
        v29 = operator new[](4 * v28);
        *((_DWORD *)v5 + 20) = v29;
        if ( v29 )
          break;
      }
LABEL_46:
      addrf = (void **)((char *)addrf - 1);
      if ( !addrf )
        goto LABEL_47;
    }
    memset(
      *((void **)v5 + 20),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 112))(v5)) >> 2));
LABEL_45:
    *(_DWORD *)(*((_DWORD *)v5 + 20) + 4 * v27) = 1;
    goto LABEL_46;
  }
LABEL_47:
  if ( (signed int)num_strings > 0 )
  {
    addrg = (void **)num_strings;
    while ( 1 )
    {
      v30 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v30 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 116))(v5) )
      {
        if ( *((_DWORD *)v5 + 18) )
          goto LABEL_53;
        v31 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 116))(v5);
        v32 = operator new[](4 * v31);
        *((_DWORD *)v5 + 18) = v32;
        if ( v32 )
          break;
      }
LABEL_54:
      addrg = (void **)((char *)addrg - 1);
      if ( !addrg )
        goto LABEL_55;
    }
    memset(
      *((void **)v5 + 18),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 116))(v5)) >> 2));
LABEL_53:
    *(_DWORD *)(*((_DWORD *)v5 + 18) + 4 * v30) = 1;
    goto LABEL_54;
  }
LABEL_55:
  if ( (signed int)num_positions > 0 )
  {
    addrh = (void **)num_positions;
    while ( 1 )
    {
      v33 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      if ( v33 < (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 120))(v5) )
      {
        if ( *((_DWORD *)v5 + 21) )
          goto LABEL_61;
        v34 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 120))(v5);
        v35 = operator new[](4 * v34);
        *((_DWORD *)v5 + 21) = v35;
        if ( v35 )
          break;
      }
LABEL_62:
      addrh = (void **)((char *)addrh - 1);
      if ( !addrh )
        return size >= (_BYTE *)*v4 - (_BYTE *)start;
    }
    memset(
      *((void **)v5 + 21),
      0,
      4 * ((unsigned int)(4 * (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 120))(v5)) >> 2));
LABEL_61:
    *(_DWORD *)(*((_DWORD *)v5 + 21) + 4 * v33) = 1;
    goto LABEL_62;
  }
  return size >= (_BYTE *)*v4 - (_BYTE *)start;
}

