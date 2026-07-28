/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GenericQualitiesData
   Object     : AC\acqualities\GenericQualitiesData.obj
   Functions  : 8
   Addresses  : 006B7800 - 006B7B90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7800) --------------------------------------------------------  // acclient.c:721191
int __thiscall CEnchantmentRegistry::pack_size(GenericQualitiesData *this)
{
  GenericQualitiesData *v1; // edi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  int v3; // esi@1
  PackableHashTable<unsigned long,int> *v4; // ecx@3
  PackableHashTable<unsigned long,double> *v5; // ecx@5
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v6; // ecx@7
  void *mem; // [sp+18h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = this->m_pIntStatsTable;
  v3 = 4;
  mem = 0;
  if ( v2 )
    v3 = ((int (__stdcall *)(void **, _DWORD))v2->vfptr->Pack)(&mem, 0) + 4;
  v4 = v1->m_pBoolStatsTable;
  if ( v4 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v4->vfptr->Pack)(&mem, 0);
  v5 = v1->m_pFloatStatsTable;
  if ( v5 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v5->vfptr->Pack)(&mem, 0);
  v6 = v1->m_pStrStatsTable;
  if ( v6 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v6->vfptr->Pack)(&mem, 0);
  return v3;
}

//----- (006B7870) --------------------------------------------------------  // acclient.c:721221
void __thiscall GenericQualitiesData::GenericQualitiesData(GenericQualitiesData *this)
{
  this->vfptr = (PackObjVtbl *)&GenericQualitiesData::vftable;
  this->m_pIntStatsTable = 0;
  this->m_pBoolStatsTable = 0;
  this->m_pFloatStatsTable = 0;
  this->m_pStrStatsTable = 0;
}
// 806830: using guessed type int (__thiscall *GenericQualitiesData::vftable)(void *, char);

//----- (006B7890) --------------------------------------------------------  // acclient.c:721232
void __thiscall GenericQualitiesData::~GenericQualitiesData(GenericQualitiesData *this)
{
  GenericQualitiesData *v1; // esi@1
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  PackableHashTable<unsigned long,int> *v3; // ecx@3
  PackableHashTable<unsigned long,double> *v4; // ecx@5
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v5; // ecx@7

  v1 = this;
  v2 = this->m_pIntStatsTable;
  v1->vfptr = (PackObjVtbl *)&GenericQualitiesData::vftable;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->m_pBoolStatsTable;
  v1->m_pIntStatsTable = 0;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->m_pFloatStatsTable;
  v1->m_pBoolStatsTable = 0;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->m_pStrStatsTable;
  v1->m_pFloatStatsTable = 0;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  v1->m_pStrStatsTable = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 806830: using guessed type int (__thiscall *GenericQualitiesData::vftable)(void *, char);

//----- (006B78F0) --------------------------------------------------------  // acclient.c:721264
int __thiscall GenericQualitiesData::Pack(GenericQualitiesData *this, void **addr, unsigned int size)
{
  GenericQualitiesData *v3; // esi@1
  int result; // eax@2
  int v5; // ebp@3
  signed int v6; // eax@4
  PackableHashTable<unsigned long,long> *v7; // ecx@12
  PackableHashTable<unsigned long,int> *v8; // ecx@14
  PackableHashTable<unsigned long,double> *v9; // ecx@16
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v10; // ecx@18

  v3 = this;
  if ( *addr )
  {
    v5 = CEnchantmentRegistry::pack_size(this);
    if ( size >= v5 )
    {
      v6 = 0;
      if ( v3->m_pIntStatsTable )
        v6 = 1;
      if ( v3->m_pBoolStatsTable )
        v6 |= 2u;
      if ( v3->m_pFloatStatsTable )
        v6 |= 4u;
      if ( v3->m_pStrStatsTable )
        v6 |= 8u;
      *(_DWORD *)*addr = v6;
      *addr = (char *)*addr + 4;
      v7 = v3->m_pIntStatsTable;
      if ( v7 )
        ((void (__stdcall *)(void **, unsigned int))v7->vfptr->Pack)(addr, size);
      v8 = v3->m_pBoolStatsTable;
      if ( v8 )
        ((void (__stdcall *)(void **, unsigned int))v8->vfptr->Pack)(addr, size);
      v9 = v3->m_pFloatStatsTable;
      if ( v9 )
        ((void (__stdcall *)(void **, unsigned int))v9->vfptr->Pack)(addr, size);
      v10 = v3->m_pStrStatsTable;
      if ( v10 )
        ((void (__stdcall *)(void **, unsigned int))v10->vfptr->Pack)(addr, size);
    }
    result = v5;
  }
  else
  {
    result = CEnchantmentRegistry::pack_size(this);
  }
  return result;
}

//----- (006B7990) --------------------------------------------------------  // acclient.c:721315
GenericQualitiesData *__thiscall GenericQualitiesData::vector_deleting_destructor(GenericQualitiesData *this, unsigned int a2)
{
  GenericQualitiesData *v2; // esi@1

  v2 = this;
  GenericQualitiesData::~GenericQualitiesData(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006B79B0) --------------------------------------------------------  // acclient.c:721327
int __thiscall GenericQualitiesData::UnPack(GenericQualitiesData *this, void **addr, unsigned int size)
{
  GenericQualitiesData *v3; // edi@1
  PackableHashTable<unsigned long,long> *v4; // ecx@1
  PackableHashTable<unsigned long,int> *v5; // ecx@3
  PackableHashTable<unsigned long,double> *v6; // ecx@5
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v7; // ecx@7
  void **v8; // ebx@9
  char v9; // al@9
  char *v10; // ecx@9
  void *v11; // eax@10
  void *v12; // esi@10
  PackableHashTable<unsigned long,long> *v13; // ecx@11
  void *v14; // eax@15
  void *v15; // esi@15
  PackableHashTable<unsigned long,int> *v16; // ecx@16
  void *v17; // eax@20
  void *v18; // esi@20
  PackableHashTable<unsigned long,double> *v19; // ecx@21
  void *v20; // eax@25
  void *v21; // esi@25
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v22; // ecx@26
  int result; // eax@30
  void *v24; // [sp+30h] [bp-4h]@9
  void **addra; // [sp+38h] [bp+4h]@9

  v3 = this;
  v4 = this->m_pIntStatsTable;
  if ( v4 )
    ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
  v5 = v3->m_pBoolStatsTable;
  v3->m_pIntStatsTable = 0;
  if ( v5 )
    ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
  v6 = v3->m_pFloatStatsTable;
  v3->m_pBoolStatsTable = 0;
  if ( v6 )
    ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  v7 = v3->m_pStrStatsTable;
  v3->m_pFloatStatsTable = 0;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
  v8 = addr;
  v3->m_pStrStatsTable = 0;
  v24 = *addr;
  v10 = (char *)*addr + 4;
  addra = *(void ***)*addr;
  v9 = (char)addra;
  *v8 = v10;
  if ( (unsigned __int8)addra & 1 )
  {
    v11 = operator new(0x14u);
    v12 = v11;
    if ( v11 )
    {
      *(_DWORD *)v11 = &PackableHashTable<unsigned long,long>::vftable;
      *((_DWORD *)v11 + 1) = 0;
      *((_DWORD *)v11 + 2) = 0;
      *((_DWORD *)v11 + 3) = 16;
      *((_DWORD *)v11 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v11);
      v13 = (PackableHashTable<unsigned long,long> *)v12;
    }
    else
    {
      v13 = 0;
    }
    v3->m_pIntStatsTable = v13;
    ((void (__stdcall *)(void **, unsigned int))v13->vfptr->UnPack)(v8, size);
    v9 = (char)addra;
  }
  if ( v9 & 2 )
  {
    v14 = operator new(0x14u);
    v15 = v14;
    if ( v14 )
    {
      *(_DWORD *)v14 = &PackableHashTable<unsigned long,int>::vftable;
      *((_DWORD *)v14 + 1) = 0;
      *((_DWORD *)v14 + 2) = 0;
      *((_DWORD *)v14 + 3) = 8;
      *((_DWORD *)v14 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v14);
      v16 = (PackableHashTable<unsigned long,int> *)v15;
    }
    else
    {
      v16 = 0;
    }
    v3->m_pBoolStatsTable = v16;
    ((void (__stdcall *)(void **, unsigned int))v16->vfptr->UnPack)(v8, size);
    v9 = (char)addra;
  }
  if ( v9 & 4 )
  {
    v17 = operator new(0x14u);
    v18 = v17;
    if ( v17 )
    {
      *(_DWORD *)v17 = &PackableHashTable<unsigned long,double>::vftable;
      *((_DWORD *)v17 + 1) = 0;
      *((_DWORD *)v17 + 2) = 0;
      *((_DWORD *)v17 + 3) = 8;
      *((_DWORD *)v17 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v17);
      v19 = (PackableHashTable<unsigned long,double> *)v18;
    }
    else
    {
      v19 = 0;
    }
    v3->m_pFloatStatsTable = v19;
    ((void (__stdcall *)(void **, unsigned int))v19->vfptr->UnPack)(v8, size);
    v9 = (char)addra;
  }
  if ( v9 & 8 )
  {
    v20 = operator new(0x14u);
    v21 = v20;
    if ( v20 )
    {
      *(_DWORD *)v20 = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable;
      *((_DWORD *)v20 + 1) = 0;
      *((_DWORD *)v20 + 2) = 0;
      *((_DWORD *)v20 + 3) = 8;
      *((_DWORD *)v20 + 4) = 0;
      PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v20);
      v22 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)v21;
    }
    else
    {
      v22 = 0;
    }
    v3->m_pStrStatsTable = v22;
    ((void (__stdcall *)(void **, unsigned int))v22->vfptr->UnPack)(v8, size);
  }
  if ( size >= (_BYTE *)*v8 - (_BYTE *)v24 )
  {
    result = 1;
  }
  else
  {
    *v8 = v24;
    result = 0;
  }
  return result;
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (006B7B60) --------------------------------------------------------  // acclient.c:721480
int __thiscall GenericQualitiesData::InqString(GenericQualitiesData *this, unsigned int stype, AC1Legacy::PStringBase<char> *retval)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // ecx@1
  AC1Legacy::PStringBase<unsigned short> *v4; // eax@2
  int result; // eax@3

  v3 = this->m_pStrStatsTable;
  if ( v3
    && (v4 = (AC1Legacy::PStringBase<unsigned short> *)PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                                                         (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
                                                         (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)retval, v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B7B90) --------------------------------------------------------  // acclient.c:721503
int __thiscall GenericQualitiesData::SetString(GenericQualitiesData *this, unsigned int stype, AC1Legacy::PStringBase<char> *_value)
{
  GenericQualitiesData *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > **v9; // edi@8
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v10; // edx@9

  v3 = this;
  if ( this->m_pStrStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 8, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->m_pStrStatsTable = v5) != 0) )
  {
    v7 = v3->m_pStrStatsTable;
    v8 = v7->_table_size;
    if ( !v8 )
      goto LABEL_18;
    v9 = v7->_buckets;
    if ( !v9 )
      goto LABEL_18;
    v10 = v9[stype % v8];
    if ( !v10 )
      goto LABEL_18;
    while ( stype != v10->_key )
    {
      v10 = v10->_next;
      if ( !v10 )
        return PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(v7, &stype, _value);
    }
    if ( v10 != (PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *)-4 )
    {
      AC1Legacy::PStringBase<unsigned short>::operator=(
        (AC1Legacy::PStringBase<unsigned short> *)&v10->_data,
        (AC1Legacy::PStringBase<unsigned short> *)_value);
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(v7, &stype, _value);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

