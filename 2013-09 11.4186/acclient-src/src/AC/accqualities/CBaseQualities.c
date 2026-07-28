/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBaseQualities
   Object     : AC\accqualities\CBaseQualities.obj
   Functions  : 14
   Addresses  : 00569830 - 0070ACC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00569830) --------------------------------------------------------  // acclient.c:406425
PackableHashTable<IDClass<_tagDataID,32,0>,long> *__thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, int a2)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)a2 )
  {
    PackableHashTable<unsigned long,unsigned long>::EmptyContents(this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init(v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 8);
            PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              v2,
              (IDClass<_tagDataID,32,0> *)v4,
              (const int *)(v4 + 4));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (00595C40) --------------------------------------------------------  // acclient.c:447515
void __thiscall CBaseQualities::Clear(CBaseQualities *this)
{
  CBaseQualities *v1; // esi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  PackableHashTable<unsigned long,__int64> *v3; // ecx@3
  PackableHashTable<unsigned long,int> *v4; // ecx@5
  PackableHashTable<unsigned long,double> *v5; // ecx@7
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v6; // ecx@9
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v7; // ecx@11
  PackableHashTable<unsigned long,unsigned long> *v8; // ecx@13
  PackableHashTable<unsigned long,Position> *v9; // ecx@15

  v1 = this;
  v2 = this->_intStatsTable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_intStatsTable = 0;
  }
  v3 = v1->_int64StatsTable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->_int64StatsTable = 0;
  }
  v4 = v1->_boolStatsTable;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->_boolStatsTable = 0;
  }
  v5 = v1->_floatStatsTable;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->_floatStatsTable = 0;
  }
  v6 = v1->_strStatsTable;
  if ( v6 )
  {
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v1->_strStatsTable = 0;
  }
  v7 = v1->_didStatsTable;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    v1->_didStatsTable = 0;
  }
  v8 = v1->_iidStatsTable;
  if ( v8 )
  {
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->_iidStatsTable = 0;
  }
  v9 = v1->_posStatsTable;
  if ( v9 )
  {
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v1->_posStatsTable = 0;
  }
}

//----- (00595CD0) --------------------------------------------------------  // acclient.c:447579
void __thiscall CBaseQualities::SetPackHeader(CBaseQualities *this, unsigned int *bitfield)
{
  if ( this->_intStatsTable )
    *bitfield |= 1u;
  if ( this->_int64StatsTable )
    *bitfield |= 0x80u;
  if ( this->_boolStatsTable )
    *bitfield |= 2u;
  if ( this->_floatStatsTable )
    *bitfield |= 4u;
  if ( this->_strStatsTable )
    *bitfield |= 0x10u;
  if ( this->_didStatsTable )
    *bitfield |= 8u;
  if ( this->_iidStatsTable )
    *bitfield |= 0x40u;
  if ( this->_posStatsTable )
    *bitfield |= 0x20u;
}

//----- (00595D30) --------------------------------------------------------  // acclient.c:447600
int __thiscall CBaseQualities::GetPackSize(CBaseQualities *this)
{
  CBaseQualities *v1; // edi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  int v3; // esi@1
  PackableHashTable<unsigned long,__int64> *v4; // ecx@3
  PackableHashTable<unsigned long,int> *v5; // ecx@5
  PackableHashTable<unsigned long,double> *v6; // ecx@7
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v7; // ecx@9
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v8; // ecx@11
  PackableHashTable<unsigned long,unsigned long> *v9; // ecx@13
  PackableHashTable<unsigned long,Position> *v10; // ecx@15
  void *mem; // [sp+38h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = this->_intStatsTable;
  v3 = 8;
  mem = 0;
  if ( v2 )
    v3 = ((int (__stdcall *)(void **, _DWORD))v2->vfptr->Pack)(&mem, 0) + 8;
  v4 = v1->_int64StatsTable;
  if ( v4 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v4->vfptr->Pack)(&mem, 0);
  v5 = v1->_boolStatsTable;
  if ( v5 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v5->vfptr->Pack)(&mem, 0);
  v6 = v1->_floatStatsTable;
  if ( v6 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v6->vfptr->Pack)(&mem, 0);
  v7 = v1->_strStatsTable;
  if ( v7 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v7->vfptr->Pack)(&mem, 0);
  v8 = v1->_didStatsTable;
  if ( v8 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v8->vfptr->Pack)(&mem, 0);
  v9 = v1->_iidStatsTable;
  if ( v9 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v9->vfptr->Pack)(&mem, 0);
  v10 = v1->_posStatsTable;
  if ( v10 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v10->vfptr->Pack)(&mem, 0);
  return v3;
}

//----- (00595E00) --------------------------------------------------------  // acclient.c:447646
void __thiscall CBaseQualities::CBaseQualities(CBaseQualities *this, IDClass<_tagDataID,32,0> wcid)
{
  this->vfptr = (CBaseQualitiesVtbl *)&CBaseQualities::vftable;
  this->_weenie_type = 0;
  this->_intStatsTable = 0;
  this->_int64StatsTable = 0;
  this->_boolStatsTable = 0;
  this->_floatStatsTable = 0;
  this->_strStatsTable = 0;
  this->_didStatsTable = 0;
  this->_iidStatsTable = 0;
  this->_posStatsTable = 0;
}
// 7E4768: using guessed type void *CBaseQualities::vftable;

//----- (00595E30) --------------------------------------------------------  // acclient.c:447662
void __thiscall CBaseQualities::~CBaseQualities(CBaseQualities *this)
{
  this->vfptr = (CBaseQualitiesVtbl *)&CBaseQualities::vftable;
  CBaseQualities::Clear(this);
}
// 7E4768: using guessed type void *CBaseQualities::vftable;

//----- (00595E40) --------------------------------------------------------  // acclient.c:447670
int __thiscall CBaseQualities::Pack(CBaseQualities *this, void **addr, unsigned int size)
{
  CBaseQualities *v3; // edi@1
  int v4; // eax@1
  unsigned int v5; // ebx@1
  int v6; // ebp@1
  char *v7; // edx@2
  PackableHashTable<unsigned long,long> *v8; // ecx@2
  PackableHashTable<unsigned long,__int64> *v9; // ecx@4
  PackableHashTable<unsigned long,int> *v10; // ecx@6
  PackableHashTable<unsigned long,double> *v11; // ecx@8
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v12; // ecx@10
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v13; // ecx@12
  PackableHashTable<unsigned long,unsigned long> *v14; // ecx@14
  PackableHashTable<unsigned long,Position> *v15; // ecx@16

  v3 = this;
  v4 = CBaseQualities::GetPackSize(this);
  v5 = size;
  v6 = v4;
  if ( size >= v4 )
  {
    size = 0;
    CBaseQualities::SetPackHeader(v3, &size);
    *(_DWORD *)*addr = size;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_weenie_type;
    *addr = (char *)*addr + 4;
    v8 = v3->_intStatsTable;
    if ( v8 )
      ((void (__stdcall *)(void **, unsigned int))v8->vfptr->Pack)(addr, v5);
    v9 = v3->_int64StatsTable;
    if ( v9 )
      ((void (__stdcall *)(void **, unsigned int))v9->vfptr->Pack)(addr, v5);
    v10 = v3->_boolStatsTable;
    if ( v10 )
      ((void (__stdcall *)(void **, unsigned int))v10->vfptr->Pack)(addr, v5);
    v11 = v3->_floatStatsTable;
    if ( v11 )
      ((void (__stdcall *)(void **, unsigned int))v11->vfptr->Pack)(addr, v5);
    v12 = v3->_strStatsTable;
    if ( v12 )
      ((void (__stdcall *)(void **, unsigned int))v12->vfptr->Pack)(addr, v5);
    v13 = v3->_didStatsTable;
    if ( v13 )
      ((void (__stdcall *)(void **, unsigned int))v13->vfptr->Pack)(addr, v5);
    v14 = v3->_iidStatsTable;
    if ( v14 )
      ((void (__stdcall *)(void **, unsigned int))v14->vfptr->Pack)(addr, v5);
    v15 = v3->_posStatsTable;
    if ( v15 )
      ((void (__stdcall *)(void **, unsigned int))v15->vfptr->Pack)(addr, v5);
  }
  return v6;
}

//----- (00595F10) --------------------------------------------------------  // acclient.c:447728
int __thiscall CBaseQualities::UnPack(CBaseQualities *this, void **addr, unsigned int left)
{
  void **v3; // ebx@1
  void *v4; // eax@1
  CBaseQualities *v5; // esi@1
  void **v6; // ecx@2
  int v7; // eax@2
  unsigned int v8; // ebp@3
  PackableHashTable<unsigned long,long> *v9; // eax@5
  PackableHashTable<unsigned long,long> *v10; // eax@6
  int result; // eax@7
  PackableHashTable<unsigned long,long> *v12; // ecx@12
  PackableHashTable<unsigned long,__int64> *v13; // eax@16
  PackableHashTable<unsigned long,__int64> *v14; // eax@17
  PackableHashTable<unsigned long,__int64> *v15; // ecx@22
  PackableHashTable<unsigned long,int> *v16; // eax@26
  PackableHashTable<unsigned long,int> *v17; // eax@27
  PackableHashTable<unsigned long,int> *v18; // ecx@32
  PackableHashTable<unsigned long,double> *v19; // eax@36
  PackableHashTable<unsigned long,double> *v20; // eax@37
  PackableHashTable<unsigned long,double> *v21; // ecx@42
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v22; // eax@46
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v23; // eax@47
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v24; // ecx@52
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v25; // eax@56
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v26; // eax@57
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v27; // ecx@62
  PackableHashTable<unsigned long,unsigned long> *v28; // eax@66
  PackableHashTable<unsigned long,unsigned long> *v29; // eax@67
  PackableHashTable<unsigned long,unsigned long> *v30; // ecx@72
  PackableHashTable<unsigned long,Position> *v31; // eax@76
  PackableHashTable<unsigned long,Position> *v32; // eax@77
  PackableHashTable<unsigned long,Position> *v33; // ecx@82
  void *start; // [sp+20h] [bp-4h]@1
  void **addra; // [sp+28h] [bp+4h]@2

  v3 = addr;
  v4 = *addr;
  v5 = this;
  start = *addr;
  if ( left < 4 )
    return 0;
  v6 = *(void ***)v4;
  v7 = (int)((char *)v4 + 4);
  addra = v6;
  *v3 = (void *)v7;
  if ( left - 4 < 4 )
    return 0;
  v5->_weenie_type = *(_DWORD *)v7;
  v8 = left - 8;
  *v3 = (char *)*v3 + 4;
  if ( !((unsigned __int8)v6 & 1) )
  {
    v12 = v5->_intStatsTable;
    if ( v12 )
    {
      ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      v5->_intStatsTable = 0;
    }
LABEL_14:
    if ( (char)addra >= 0 )
    {
      v15 = v5->_int64StatsTable;
      if ( v15 )
      {
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
        v5->_int64StatsTable = 0;
      }
    }
    else
    {
      if ( !v5->_int64StatsTable )
      {
        v13 = (PackableHashTable<unsigned long,__int64> *)operator new(0x14u);
        if ( v13 )
          PackableHashTable<unsigned long,__int64>::PackableHashTable<unsigned long,__int64>(v13, 0);
        else
          v14 = 0;
        v5->_int64StatsTable = v14;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_int64StatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    if ( (unsigned __int8)addra & 2 )
    {
      if ( !v5->_boolStatsTable )
      {
        v16 = (PackableHashTable<unsigned long,int> *)operator new(0x14u);
        if ( v16 )
          PackableHashTable<unsigned long,int>::PackableHashTable<unsigned long,int>(v16, 0);
        else
          v17 = 0;
        v5->_boolStatsTable = v17;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_boolStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v18 = v5->_boolStatsTable;
      if ( v18 )
      {
        ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
        v5->_boolStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 4 )
    {
      if ( !v5->_floatStatsTable )
      {
        v19 = (PackableHashTable<unsigned long,double> *)operator new(0x14u);
        if ( v19 )
          PackableHashTable<unsigned long,double>::PackableHashTable<unsigned long,double>(v19, 0);
        else
          v20 = 0;
        v5->_floatStatsTable = v20;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_floatStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v21 = v5->_floatStatsTable;
      if ( v21 )
      {
        ((void (__stdcall *)(signed int))v21->vfptr->__vecDelDtor)(1);
        v5->_floatStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x10 )
    {
      if ( !v5->_strStatsTable )
      {
        v22 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)operator new(0x14u);
        if ( v22 )
          PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>(
            v22,
            0);
        else
          v23 = 0;
        v5->_strStatsTable = v23;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_strStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v24 = v5->_strStatsTable;
      if ( v24 )
      {
        ((void (__stdcall *)(signed int))v24->vfptr->__vecDelDtor)(1);
        v5->_strStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 8 )
    {
      if ( !v5->_didStatsTable )
      {
        v25 = (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)operator new(0x14u);
        if ( v25 )
          PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>(
            v25,
            0);
        else
          v26 = 0;
        v5->_didStatsTable = v26;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_didStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v27 = v5->_didStatsTable;
      if ( v27 )
      {
        ((void (__stdcall *)(signed int))v27->vfptr->__vecDelDtor)(1);
        v5->_didStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x40 )
    {
      if ( !v5->_iidStatsTable )
      {
        v28 = (PackableHashTable<unsigned long,unsigned long> *)operator new(0x14u);
        if ( v28 )
          PackableHashTable<unsigned long,unsigned long>::PackableHashTable<unsigned long,unsigned long>(v28, 0);
        else
          v29 = 0;
        v5->_iidStatsTable = v29;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_iidStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v30 = v5->_iidStatsTable;
      if ( v30 )
      {
        ((void (__stdcall *)(signed int))v30->vfptr->__vecDelDtor)(1);
        v5->_iidStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x20 )
    {
      if ( !v5->_posStatsTable )
      {
        v31 = (PackableHashTable<unsigned long,Position> *)operator new(0x14u);
        if ( v31 )
          PackableHashTable<unsigned long,Position>::PackableHashTable<unsigned long,Position>(v31, 0);
        else
          v32 = 0;
        v5->_posStatsTable = v32;
      }
      result = ((int (__stdcall *)(void **, unsigned int))v5->_posStatsTable->vfptr->UnPack)(v3, v8);
      if ( !result )
        return result;
    }
    else
    {
      v33 = v5->_posStatsTable;
      if ( v33 )
      {
        ((void (__stdcall *)(signed int))v33->vfptr->__vecDelDtor)(1);
        v5->_posStatsTable = 0;
      }
    }
    return PackObj::VERIFY_ADDR(*v3, start, left);
  }
  if ( !v5->_intStatsTable )
  {
    v9 = (PackableHashTable<unsigned long,long> *)operator new(0x14u);
    if ( v9 )
      PackableHashTable<unsigned long,long>::PackableHashTable<unsigned long,long>(v9, 0);
    else
      v10 = 0;
    v5->_intStatsTable = v10;
  }
  result = ((int (__stdcall *)(void **, unsigned int))v5->_intStatsTable->vfptr->UnPack)(v3, v8);
  if ( result )
    goto LABEL_14;
  return result;
}

//----- (005961F0) --------------------------------------------------------  // acclient.c:447978
PackableHashTable<unsigned long,double> *__thiscall PackableHashTable<unsigned long,__int64>::operator=(PackableHashTable<unsigned long,double> *this, int a2)
{
  PackableHashTable<unsigned long,double> *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,double> *)a2 )
  {
    PackableHashTable<unsigned long,__int64>::EmptyContents(this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 16);
            PackableHashTable<unsigned long,double>::add(v2, (const unsigned int *)v4, (const long double *)(v4 + 8));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (00596270) --------------------------------------------------------  // acclient.c:448022
PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *__thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::operator=(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, int a2)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v2; // edi@1
  unsigned int v3; // ebx@2
  int v4; // eax@5
  int v5; // esi@6

  v2 = this;
  if ( this != (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)a2 )
  {
    PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::EmptyContents(this);
    v3 = 0;
    if ( v2->_buckets )
    {
      operator delete[](v2->_buckets);
      v2->_buckets = 0;
    }
    v2->_table_size = 0;
    v2->_table_size = *(_DWORD *)(a2 + 12);
    PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
    if ( *(_DWORD *)(a2 + 12) > 0u )
    {
      do
      {
        v4 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v3);
        if ( v4 )
        {
          do
          {
            v5 = *(_DWORD *)(v4 + 8);
            PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(
              v2,
              (const unsigned int *)v4,
              (AC1Legacy::PStringBase<char> *)(v4 + 4));
            v4 = v5;
          }
          while ( v5 );
        }
        ++v3;
      }
      while ( v3 < *(_DWORD *)(a2 + 12) );
    }
  }
  return v2;
}

//----- (0070AC60) --------------------------------------------------------  // acclient.c:797984
void sub_70AC60()
{
  flt_871054 = 1000.0 + 1.0;
}

//----- (0070AC80) --------------------------------------------------------  // acclient.c:797990
void sub_70AC80()
{
  flt_871058 = 24.0 * 8.0;
}

//----- (0070ACA0) --------------------------------------------------------  // acclient.c:797996
void sub_70ACA0()
{
  flt_87105C = 24.0 * 0.5;
}

//----- (0070ACC0) --------------------------------------------------------  // acclient.c:798002
int sub_70ACC0()
{
  return atexit(nullsub_1416);
}

