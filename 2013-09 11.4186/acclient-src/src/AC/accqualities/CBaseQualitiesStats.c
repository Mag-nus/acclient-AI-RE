/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBaseQualitiesStats
   Object     : AC\accqualities\CBaseQualitiesStats.obj
   Functions  : 72
   Addresses  : 005692B0 - 0070AAF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005692B0) --------------------------------------------------------  // acclient.c:405979
signed int __thiscall PackableHashTable<unsigned long,long>::Pack(PackableHashTable<unsigned long,int> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,int> *v3; // edi@1
  signed int result; // eax@1
  char *v5; // esi@2
  unsigned int v6; // ebx@2
  PackableHashData<unsigned long,int> *v7; // edx@3
  char *v8; // esi@5
  char *v9; // eax@5
  unsigned int retVal; // [sp+8h] [bp-4h]@1

  v3 = this;
  result = PackableHashTable<unsigned long,int>::pack_size((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( size >= 4 )
            {
              *(_DWORD *)v5 = v7->_key;
              v8 = (char *)*addr + 4;
              *addr = v8;
              *(_DWORD *)v8 = v7->_data;
              v9 = (char *)*addr + 4;
              *addr = v9;
              v5 = v9;
            }
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
        }
        ++v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (0058FB00) --------------------------------------------------------  // acclient.c:440455
void __thiscall PackableHashTable<unsigned long,long>::PackableHashTable<unsigned long,long>(PackableHashTable<unsigned long,long> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,long>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);

//----- (0058FB30) --------------------------------------------------------  // acclient.c:440467
int __thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *this, const unsigned int *key, IDClass<_tagDataID,32,0> *retval)
{
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > **v5; // ecx@2
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > *v6; // eax@3
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > *v7; // ecx@3
  int result; // eax@6

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = 0, (v7 = v5[*key % v4]) != 0) )
  {
    while ( v7->_key != *key )
    {
      v6 = v7;
      v7 = v7->_next;
      if ( !v7 )
        goto LABEL_6;
    }
    retval->id = v7->_data.id;
    if ( v6 )
      v6->_next = v7->_next;
    else
      v3->_buckets[*key % v3->_table_size] = v7->_next;
    operator delete(v7);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0058FBC0) --------------------------------------------------------  // acclient.c:440505
void __thiscall PackableHashTable<unsigned long,__int64>::PackableHashTable<unsigned long,__int64>(PackableHashTable<unsigned long,__int64> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,__int64>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E441C: using guessed type int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char);

//----- (0058FBF0) --------------------------------------------------------  // acclient.c:440517
int __thiscall PackableHashTable<unsigned long,__int64>::remove(PackableHashTable<unsigned long,double> *this, const unsigned int *key, long double *retval)
{
  PackableHashTable<unsigned long,double> *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,double> **v5; // ecx@2
  PackableHashData<unsigned long,double> *v6; // eax@3
  PackableHashData<unsigned long,double> *v7; // ecx@3
  int result; // eax@6

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = 0, (v7 = v5[*key % v4]) != 0) )
  {
    while ( v7->_key != *key )
    {
      v6 = v7;
      v7 = v7->_next;
      if ( !v7 )
        goto LABEL_6;
    }
    *(_QWORD *)retval = *(_QWORD *)&v7->_data;
    if ( v6 )
      v6->_next = v7->_next;
    else
      v3->_buckets[*key % v3->_table_size] = v7->_next;
    operator delete(v7);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0058FC80) --------------------------------------------------------  // acclient.c:440555
void __thiscall PackableHashTable<unsigned long,int>::PackableHashTable<unsigned long,int>(PackableHashTable<unsigned long,int> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,int>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);

//----- (0058FCB0) --------------------------------------------------------  // acclient.c:440567
void __thiscall PackableHashTable<unsigned long,double>::PackableHashTable<unsigned long,double>(PackableHashTable<unsigned long,double> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,double>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);

//----- (0058FCE0) --------------------------------------------------------  // acclient.c:440579
long double *__thiscall PackableHashTable<unsigned long,double>::lookup(PackableHashTable<unsigned long,double> *this, const unsigned int *key)
{
  unsigned int v2; // edi@1
  PackableHashData<unsigned long,double> **v3; // esi@2
  PackableHashData<unsigned long,double> *v4; // edx@3
  long double *result; // eax@6

  v2 = this->_table_size;
  if ( v2 && (v3 = this->_buckets) != 0 && (v4 = v3[*key % v2]) != 0 )
  {
    while ( *key != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0058FD20) --------------------------------------------------------  // acclient.c:440606
void __thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E4458: using guessed type int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (0058FD50) --------------------------------------------------------  // acclient.c:440618
void __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (0058FD80) --------------------------------------------------------  // acclient.c:440630
void __thiscall PackableHashTable<unsigned long,Position>::PackableHashTable<unsigned long,Position>(PackableHashTable<unsigned long,Position> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Position>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7E4480: using guessed type int (__thiscall *PackableHashTable<unsigned long,Position>::vftable)(void *, char);

//----- (0058FDB0) --------------------------------------------------------  // acclient.c:440642
Position *__thiscall PackableHashTable<unsigned long,Position>::lookup(PackableHashTable<unsigned long,Position> *this, const unsigned int *key)
{
  unsigned int v2; // edi@1
  PackableHashData<unsigned long,Position> **v3; // esi@2
  PackableHashData<unsigned long,Position> *v4; // edx@3
  Position *result; // eax@6

  v2 = this->_table_size;
  if ( v2 && (v3 = this->_buckets) != 0 && (v4 = v3[*key % v2]) != 0 )
  {
    while ( *key != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (0058FDF0) --------------------------------------------------------  // acclient.c:440669
int __thiscall CBaseQualities::InqInt(CBaseQualities *this, unsigned int stype, int *retval, int raw, int allow_negative)
{
  CBaseQualities *v5; // esi@1
  PackableHashTable<unsigned long,long> *v6; // ecx@1
  int *v7; // eax@2
  int result; // eax@3
  int v9; // ecx@4
  int *v10; // eax@4

  v5 = this;
  v6 = this->_intStatsTable;
  if ( v6
    && (v7 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v6,
               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    v9 = *v7;
    v10 = retval;
    *retval = v9;
    if ( !raw )
      (*((void (__thiscall **)(CBaseQualities *, unsigned int, int *, int))&v5->vfptr->__vecDelDtor + 1))(
        v5,
        stype,
        v10,
        allow_negative);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FE40) --------------------------------------------------------  // acclient.c:440704
int __thiscall CBaseQualities::InqInt64(CBaseQualities *this, unsigned int stype, __int64 *retval)
{
  PackableHashTable<unsigned long,double> *v3; // ecx@1
  long double *v4; // eax@2
  int result; // eax@3
  __int64 *v6; // ecx@4

  v3 = (PackableHashTable<unsigned long,double> *)this->_int64StatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,double>::lookup(v3, &stype)) != 0 )
  {
    v6 = retval;
    *(_DWORD *)retval = *(_DWORD *)v4;
    *((_DWORD *)v6 + 1) = *((_DWORD *)v4 + 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FE70) --------------------------------------------------------  // acclient.c:440727
int __thiscall CBaseQualities::InqBool(CBaseQualities *this, unsigned int stype, int *retval)
{
  PackableHashTable<unsigned long,int> *v3; // ecx@1
  int *v4; // eax@2
  int result; // eax@3

  v3 = this->_boolStatsTable;
  if ( v3
    && (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    *retval = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FEA0) --------------------------------------------------------  // acclient.c:440750
int __thiscall CBaseQualities::InqFloat(CBaseQualities *this, unsigned int stype, long double *retval, int raw)
{
  CBaseQualities *v4; // esi@1
  PackableHashTable<unsigned long,double> *v5; // ecx@1
  long double *v6; // eax@2
  int result; // eax@3
  long double *v8; // ecx@4

  v4 = this;
  v5 = this->_floatStatsTable;
  if ( v5 && (v6 = PackableHashTable<unsigned long,double>::lookup(v5, &stype)) != 0 )
  {
    v8 = retval;
    *(_DWORD *)retval = *(_DWORD *)v6;
    *((_DWORD *)v8 + 1) = *((_DWORD *)v6 + 1);
    if ( !raw )
      v4->vfptr->EnchantFloat(v4, stype, v8);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FEF0) --------------------------------------------------------  // acclient.c:440777
int __thiscall CBaseQualities::InqDataID(CBaseQualities *this, unsigned int stype, IDClass<_tagDataID,32,0> *retval)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v3; // ecx@1
  unsigned int *v4; // eax@2
  int result; // eax@3

  v3 = (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this->_didStatsTable;
  if ( v3
    && (v4 = (unsigned int *)PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                               v3,
                               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    retval->id = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FF20) --------------------------------------------------------  // acclient.c:440800
int __thiscall CBaseQualities::InqInstanceID(CBaseQualities *this, unsigned int stype, unsigned int *retval)
{
  PackableHashTable<unsigned long,unsigned long> *v3; // ecx@1
  unsigned int *v4; // eax@2
  int result; // eax@3

  v3 = this->_iidStatsTable;
  if ( v3
    && (v4 = (unsigned int *)PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
                               (IDClass<_tagDataID,32,0> *)&stype)) != 0 )
  {
    *retval = *v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FF50) --------------------------------------------------------  // acclient.c:440823
int __thiscall CBaseQualities::InqPosition(CBaseQualities *this, unsigned int stype, Position *retval)
{
  PackableHashTable<unsigned long,Position> *v3; // ecx@1
  Position *v4; // eax@2
  int result; // eax@3
  Position *v6; // ecx@4

  v3 = this->_posStatsTable;
  if ( v3 && (v4 = PackableHashTable<unsigned long,Position>::lookup(v3, &stype)) != 0 )
  {
    v6 = retval;
    retval->objcell_id = v4->objcell_id;
    Frame::operator=((int)&v6->frame, (int)&v4->frame);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0058FF90) --------------------------------------------------------  // acclient.c:440846
signed int __thiscall PackableHashTable<unsigned long,__int64>::Pack(PackableHashTable<unsigned long,__int64> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,__int64> *v3; // esi@1
  signed int result; // eax@1
  unsigned int v5; // edi@2
  PackableHashData<unsigned long,__int64> *v6; // edx@3
  void *v7; // eax@7
  unsigned int retVal; // [sp+0h] [bp-4h]@1

  v3 = this;
  result = PackableHashTable<unsigned long,__int64>::pack_size((PackableHashTable<unsigned long,double> *)this);
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v5 = 0;
    if ( v3->_table_size )
    {
      do
      {
        v6 = v3->_buckets[v5];
        if ( v6 )
        {
          do
          {
            if ( size >= 4 )
            {
              *(_DWORD *)*addr = v6->_key;
              *addr = (char *)*addr + 4;
            }
            if ( size >= 8 )
            {
              v7 = *addr;
              *(_DWORD *)v7 = LODWORD(v6->_data);
              *((_DWORD *)v7 + 1) = HIDWORD(v6->_data);
              *addr = (char *)*addr + 8;
            }
            v6 = v6->_next;
          }
          while ( v6 );
          result = retVal;
        }
        ++v5;
      }
      while ( v5 < v3->_table_size );
    }
  }
  return result;
}

//----- (00590010) --------------------------------------------------------  // acclient.c:440898
int __thiscall PackableHashTable<unsigned long,__int64>::UnPack(PackableHashTable<unsigned long,__int64> *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  PackableHashTable<unsigned long,__int64> *v4; // ebx@1
  void **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  int v10; // edi@3
  unsigned int v11; // ebp@3
  int v12; // eax@11
  int v13; // ecx@12
  void *start_addr; // [sp+8h] [bp-10h]@3
  unsigned int blob_size; // [sp+Ch] [bp-Ch]@3
  __int64 tempData; // [sp+10h] [bp-8h]@12

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,__int64>::Destroy((PackableHashTable<unsigned long,double> *)this);
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = (int)((char *)*v6 + 4);
      addr = *(void ***)*v6;
      *v6 = (void *)v12;
      if ( (unsigned int)v10 < 8 )
        break;
      v13 = *(_DWORD *)(v12 + 4);
      LODWORD(tempData) = *(_DWORD *)v12;
      *v6 = (void *)(v12 + 8);
      HIDWORD(tempData) = v13;
      if ( !PackableHashTable<unsigned long,double>::add(
              (PackableHashTable<unsigned long,double> *)v4,
              (const unsigned int *)&addr,
              (const long double *)&tempData)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00590120) --------------------------------------------------------  // acclient.c:440965
void __thiscall PackableHashTable<unsigned long,__int64>::Destroy(PackableHashTable<unsigned long,double> *this)
{
  PackableHashTable<unsigned long,double> *v1; // esi@1

  v1 = this;
  PackableHashTable<unsigned long,__int64>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
}

//----- (00590150) --------------------------------------------------------  // acclient.c:440980
int __thiscall PackableHashTable<unsigned long,int>::UnPack(PackableHashTable<unsigned long,int> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,int> *v4; // edi@1
  void **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  int v10; // ebx@3
  unsigned int v11; // ebp@3
  unsigned int v12; // ecx@11
  int v13; // eax@11
  void **v14; // edx@11
  unsigned int tempKey; // [sp+8h] [bp-Ch]@11
  void *start_addr; // [sp+Ch] [bp-8h]@3
  unsigned int blob_size; // [sp+10h] [bp-4h]@3

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,unsigned long>::Destroy((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *(_DWORD *)*v6;
      v13 = (int)((char *)*v6 + 4);
      *v6 = (void *)v13;
      v14 = *(void ***)v13;
      *v6 = (void *)(v13 + 4);
      tempKey = v12;
      addr = v14;
      if ( !PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4,
              (IDClass<_tagDataID,32,0> *)&tempKey,
              (const int *)&addr)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00590280) --------------------------------------------------------  // acclient.c:441061
int __thiscall PackableHashTable<unsigned long,double>::add(PackableHashTable<unsigned long,double> *this, const unsigned int *key, const long double *data)
{
  PackableHashTable<unsigned long,double> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,double> **v5; // ebx@2
  PackableHashData<unsigned long,double> *v6; // edx@3
  void *v7; // eax@8
  unsigned int v8; // edi@9
  const unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[*key % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( *key != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<unsigned long,double> *)-8 )
  {
LABEL_8:
    v7 = operator new(0x18u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      *((_QWORD *)v7 + 1) = *(_QWORD *)data;
      *((_DWORD *)v7 + 4) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 5) = v9;
      *((_DWORD *)v7 + 4) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,double> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (00590320) --------------------------------------------------------  // acclient.c:441109
signed int __thiscall PackableHashTable<unsigned long,double>::Pack(PackableHashTable<unsigned long,double> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,double> *v3; // esi@1
  signed int result; // eax@1
  unsigned int v5; // edi@2
  PackableHashData<unsigned long,double> *v6; // edx@3
  unsigned int retVal; // [sp+0h] [bp-4h]@1

  v3 = this;
  result = PackableHashTable<unsigned long,__int64>::pack_size(this);
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v5 = 0;
    if ( v3->_table_size )
    {
      do
      {
        v6 = v3->_buckets[v5];
        if ( v6 )
        {
          do
          {
            if ( size >= 4 )
            {
              *(_DWORD *)*addr = v6->_key;
              *addr = (char *)*addr + 4;
            }
            if ( size >= 8 )
            {
              *(double *)*addr = v6->_data;
              *addr = (char *)*addr + 8;
            }
            v6 = v6->_next;
          }
          while ( v6 );
          result = retVal;
        }
        ++v5;
      }
      while ( v5 < v3->_table_size );
    }
  }
  return result;
}

//----- (005903A0) --------------------------------------------------------  // acclient.c:441158
signed int __thiscall PackableHashTable<unsigned long,__int64>::pack_size(PackableHashTable<unsigned long,double> *this)
{
  unsigned int v1; // edx@1
  signed int result; // eax@1
  PackableHashData<unsigned long,double> **v3; // esi@2
  PackableHashData<unsigned long,double> *i; // ecx@3

  v1 = this->_table_size;
  result = 4;
  if ( v1 )
  {
    v3 = this->_buckets;
    do
    {
      for ( i = *v3; i; result += 12 )
        i = i->_next;
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

//----- (005903D0) --------------------------------------------------------  // acclient.c:441183
int __thiscall PackableHashTable<unsigned long,double>::UnPack(PackableHashTable<unsigned long,double> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,double> *v3; // ebx@1
  int result; // eax@2
  unsigned int v5; // eax@3
  unsigned int v6; // ecx@3
  unsigned int v7; // eax@3
  unsigned int v8; // edi@3
  char *v9; // eax@10
  unsigned int v10; // ecx@11
  unsigned int v11; // edx@11
  unsigned int i; // [sp+Ch] [bp-1Ch]@8
  unsigned int toUnPack; // [sp+10h] [bp-18h]@3
  unsigned int tempKey; // [sp+14h] [bp-14h]@10
  void *start_addr; // [sp+18h] [bp-10h]@3
  unsigned int blob_size; // [sp+1Ch] [bp-Ch]@3
  long double tempData; // [sp+20h] [bp-8h]@11

  v3 = this;
  if ( size < 4 )
    return 0;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,__int64>::Destroy(this);
  v5 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v6 = v5 >> 16;
  v7 = (unsigned __int16)v5;
  v8 = size - 4;
  v3->_table_size = v6;
  toUnPack = v7;
  if ( v6 )
  {
    if ( v6 > 0x10000
      || v7 > 0x10000
      || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3) )
      return 0;
    i = 0;
    if ( toUnPack )
    {
      while ( v8 >= 4 )
      {
        v9 = (char *)*addr + 4;
        tempKey = *(_DWORD *)*addr;
        *addr = v9;
        if ( v8 < 8 )
          break;
        v10 = *(_DWORD *)v9;
        v11 = *((_DWORD *)v9 + 1);
        *addr = v9 + 8;
        tempData = COERCE_DOUBLE(__PAIR__(v11, v10));
        if ( !PackableHashTable<unsigned long,double>::add(v3, &tempKey, &tempData)
          && !v3->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++i;
        if ( i >= toUnPack )
          goto LABEL_14;
      }
      return 0;
    }
LABEL_14:
    result = blob_size >= (_BYTE *)*addr - (_BYTE *)start_addr;
  }
  else
  {
    result = v7 == 0;
  }
  return result;
}

//----- (005904E0) --------------------------------------------------------  // acclient.c:441254
void __thiscall PackableHashTable<unsigned long,__int64>::EmptyContents(PackableHashTable<unsigned long,double> *this)
{
  PackableHashTable<unsigned long,double> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<unsigned long,double> *v3; // eax@3
  PackableHashData<unsigned long,double> *v4; // esi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}

//----- (00590530) --------------------------------------------------------  // acclient.c:441289
signed int __thiscall PackableHashTable<unsigned long,Position>::Pack(PackableHashTable<unsigned long,Position> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,Position> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,Position> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,Position>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (005905C0) --------------------------------------------------------  // acclient.c:441340
signed int __thiscall PackableHashTable<unsigned long,Position>::pack_size(PackableHashTable<unsigned long,Position> *this)
{
  PackableHashTable<unsigned long,Position> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,Position> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (00590620) --------------------------------------------------------  // acclient.c:441372
PackableHashTable<unsigned long,__int64> *__thiscall PackableHashTable<unsigned long,__int64>::vector_deleting_destructor(PackableHashTable<unsigned long,__int64> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,__int64> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,__int64>::vftable;
  PackableHashTable<unsigned long,__int64>::Destroy((PackableHashTable<unsigned long,double> *)this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E441C: using guessed type int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char);

//----- (00590650) --------------------------------------------------------  // acclient.c:441388
PackableHashTable<unsigned long,int> *__thiscall PackableHashTable<unsigned long,int>::scalar_deleting_destructor(PackableHashTable<unsigned long,int> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,int> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,int>::vftable;
  PackableHashTable<unsigned long,unsigned long>::Destroy((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);

//----- (00590680) --------------------------------------------------------  // acclient.c:441404
PackableHashTable<unsigned long,double> *__thiscall PackableHashTable<unsigned long,double>::vector_deleting_destructor(PackableHashTable<unsigned long,double> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,double> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,double>::vftable;
  PackableHashTable<unsigned long,__int64>::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);

//----- (005906B0) --------------------------------------------------------  // acclient.c:441420
void __thiscall PackableHashData<unsigned long,Position>::PackableHashData<unsigned long,Position>(PackableHashData<unsigned long,Position> *this, const unsigned int *key, Position *data, int highbound)
{
  PackableHashData<unsigned long,Position> *v4; // esi@1

  v4 = this;
  this->_key = *key;
  this->_data.vfptr = (PackObjVtbl *)&Position::vftable;
  this->_data.objcell_id = data->objcell_id;
  Frame::operator=((int)&this->_data.frame, (int)&data->frame);
  v4->_next = 0;
  v4->_hashVal = *key % highbound;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00590700) --------------------------------------------------------  // acclient.c:441435
int __thiscall CBaseQualities::RemoveInt(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,long> *v2; // ecx@1
  int result; // eax@2
  int dummy; // [sp+0h] [bp-4h]@1

  dummy = (int)this;
  v2 = this->_intStatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(
               (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v2,
               &stype,
               (IDClass<_tagDataID,32,0> *)&dummy);
  else
    result = 0;
  return result;
}

//----- (00590730) --------------------------------------------------------  // acclient.c:441454
int __thiscall CBaseQualities::SetInt(CBaseQualities *this, unsigned int stype, const int val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,long> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,long> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,long> **v9; // edi@8
  PackableHashData<unsigned long,long> *v10; // edx@9

  v3 = this;
  if ( this->_intStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,long> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,long>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 64, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_intStatsTable = v5) != 0) )
  {
    v7 = v3->_intStatsTable;
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
        return PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 &val);
    }
    if ( v10 != (PackableHashData<unsigned long,long> *)-4 )
    {
      v10->_data = val;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 &val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);

//----- (00590800) --------------------------------------------------------  // acclient.c:441512
int __thiscall CBaseQualities::RemoveInt64(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,double> *v2; // ecx@1
  int result; // eax@2
  __int64 dummy; // [sp+0h] [bp-8h]@2

  v2 = (PackableHashTable<unsigned long,double> *)this->_int64StatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,__int64>::remove(v2, &stype, (long double *)&dummy);
  else
    result = 0;
  return result;
}

//----- (00590830) --------------------------------------------------------  // acclient.c:441527
int __thiscall CBaseQualities::SetInt64(CBaseQualities *this, unsigned int stype, const __int64 val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,__int64> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,__int64> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,__int64> **v9; // edi@8
  PackableHashData<unsigned long,__int64> *v10; // edx@9
  int v11; // eax@13
  int v12; // edx@15

  v3 = this;
  if ( this->_int64StatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,__int64> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,__int64>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 64, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_int64StatsTable = v5) != 0) )
  {
    v7 = v3->_int64StatsTable;
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
        return PackableHashTable<unsigned long,double>::add(
                 (PackableHashTable<unsigned long,double> *)v7,
                 &stype,
                 (const long double *)&val);
    }
    v11 = (int)&v10->_data;
    if ( v10 != (PackableHashData<unsigned long,__int64> *)-8 )
    {
      v12 = HIDWORD(val);
      *(_DWORD *)v11 = val;
      *(_DWORD *)(v11 + 4) = v12;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,double>::add(
                 (PackableHashTable<unsigned long,double> *)v7,
                 &stype,
                 (const long double *)&val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E441C: using guessed type int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char);

//----- (00590910) --------------------------------------------------------  // acclient.c:441590
int __thiscall CBaseQualities::RemoveBool(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,int> *v2; // ecx@1
  int result; // eax@2
  int dummy; // [sp+0h] [bp-4h]@1

  dummy = (int)this;
  v2 = this->_boolStatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(
               (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v2,
               &stype,
               (IDClass<_tagDataID,32,0> *)&dummy);
  else
    result = 0;
  return result;
}

//----- (00590940) --------------------------------------------------------  // acclient.c:441609
int __thiscall CBaseQualities::SetBool(CBaseQualities *this, unsigned int stype, const int val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,int> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,int> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,int> **v9; // edi@8
  PackableHashData<unsigned long,int> *v10; // edx@9

  v3 = this;
  if ( this->_boolStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,int> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,int>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_boolStatsTable = v5) != 0) )
  {
    v7 = v3->_boolStatsTable;
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
        return PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 &val);
    }
    if ( v10 != (PackableHashData<unsigned long,int> *)-4 )
    {
      v10->_data = val;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 &val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);

//----- (00590A10) --------------------------------------------------------  // acclient.c:441667
int __thiscall CBaseQualities::RemoveFloat(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,double> *v2; // ecx@1
  int result; // eax@2
  long double dummy; // [sp+0h] [bp-8h]@2

  v2 = this->_floatStatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,__int64>::remove(v2, &stype, &dummy);
  else
    result = 0;
  return result;
}

//----- (00590A40) --------------------------------------------------------  // acclient.c:441682
int __thiscall CBaseQualities::SetFloat(CBaseQualities *this, unsigned int stype, const long double val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,double> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,double> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,double> **v9; // edi@8
  PackableHashData<unsigned long,double> *v10; // edx@9
  int v11; // eax@13
  int v12; // edx@15

  v3 = this;
  if ( this->_floatStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,double> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,double>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_floatStatsTable = v5) != 0) )
  {
    v7 = v3->_floatStatsTable;
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
        return PackableHashTable<unsigned long,double>::add(v7, &stype, &val);
    }
    v11 = (int)&v10->_data;
    if ( v10 != (PackableHashData<unsigned long,double> *)-8 )
    {
      v12 = HIDWORD(val);
      *(_DWORD *)v11 = LODWORD(val);
      *(_DWORD *)(v11 + 4) = v12;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,double>::add(v7, &stype, &val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E4444: using guessed type int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char);

//----- (00590B20) --------------------------------------------------------  // acclient.c:441739
int __thiscall CBaseQualities::SetDataID(CBaseQualities *this, unsigned int stype, IDClass<_tagDataID,32,0> val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > **v9; // edi@8
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > *v10; // edx@9

  v3 = this;
  if ( this->_didStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_didStatsTable = v5) != 0) )
  {
    v7 = v3->_didStatsTable;
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
        return PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 (const int *)&val);
    }
    if ( v10 != (PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > *)-4 )
    {
      v10->_data.id = val.id;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 (const int *)&val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E4458: using guessed type int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (00590BF0) --------------------------------------------------------  // acclient.c:441797
int __thiscall CBaseQualities::RemoveInstanceID(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,unsigned long> *v2; // ecx@1
  int result; // eax@2
  unsigned int dummy; // [sp+0h] [bp-4h]@1

  dummy = (unsigned int)this;
  v2 = this->_iidStatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(
               (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)v2,
               &stype,
               (IDClass<_tagDataID,32,0> *)&dummy);
  else
    result = 0;
  return result;
}

//----- (00590C20) --------------------------------------------------------  // acclient.c:441816
int __thiscall CBaseQualities::SetInstanceID(CBaseQualities *this, unsigned int stype, const unsigned int val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,unsigned long> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,unsigned long> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,unsigned long> **v9; // edi@8
  PackableHashData<unsigned long,unsigned long> *v10; // edx@9

  v3 = this;
  if ( this->_iidStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,unsigned long> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,unsigned long>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 32, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_iidStatsTable = v5) != 0) )
  {
    v7 = v3->_iidStatsTable;
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
        return PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 (const int *)&val);
    }
    if ( v10 != (PackableHashData<unsigned long,unsigned long> *)-4 )
    {
      v10->_data = val;
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
                 (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v7,
                 (IDClass<_tagDataID,32,0> *)&stype,
                 (const int *)&val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7C8EE0: using guessed type int (__thiscall *PackableHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (00590CF0) --------------------------------------------------------  // acclient.c:441874
int __thiscall CBaseQualities::InqString(CBaseQualities *this, unsigned int stype, AC1Legacy::PStringBase<char> *retval)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // ecx@1
  int *v4; // eax@2
  int *v5; // edi@2
  int result; // eax@3
  AC1Legacy::PStringBase<char> *v7; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v8; // esi@4
  int v9; // edi@8

  v3 = this->_strStatsTable;
  if ( v3
    && (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3,
               (IDClass<_tagDataID,32,0> *)&stype),
        (v5 = v4) != 0) )
  {
    v7 = retval;
    v8 = retval->m_buffer;
    if ( retval->m_buffer != (AC1Legacy::PSRefBuffer<char> *)*v4 )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) )
      {
        if ( v8 )
          v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      }
      v9 = *v5;
      v7->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v9;
      InterlockedIncrement((volatile LONG *)(v9 + 4));
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00590D50) --------------------------------------------------------  // acclient.c:441914
signed int __thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::Pack(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v3; // ebx@1
  signed int v4; // edi@1
  char *v5; // esi@2
  unsigned int v6; // eax@2
  PackableHashData<unsigned long,IDClass<_tagDataID,32,0> > *v7; // edx@3
  unsigned int retVal; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = PackableHashTable<unsigned long,int>::pack_size((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  retVal = v4;
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( size >= 4 )
            {
              *(_DWORD *)v5 = v7->_key;
              v5 = (char *)*addr + 4;
              *addr = v5;
            }
            if ( size >= 4 )
            {
              *(_DWORD *)v5 = v7->_data.id;
              v5 = (char *)*addr + 4;
              *addr = v5;
            }
            v7 = v7->_next;
          }
          while ( v7 );
          v4 = retVal;
        }
        ++v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return v4;
}

//----- (00590DE0) --------------------------------------------------------  // acclient.c:441967
int __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, const unsigned int *key, AC1Legacy::PStringBase<char> *data)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > **v5; // ebx@2
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v6; // edx@3
  void *v7; // eax@8
  void *v8; // esi@8
  unsigned int v9; // ebx@9
  AC1Legacy::PSRefBuffer<char> *v10; // eax@9
  const unsigned int v11; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[*key % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( *key != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *)-4 )
  {
LABEL_8:
    v7 = operator new(0x10u);
    v8 = v7;
    if ( v7 )
    {
      v9 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      v10 = data->m_buffer;
      *((_DWORD *)v8 + 1) = data->m_buffer;
      InterlockedIncrement((volatile LONG *)&v10->m_cRef);
      *((_DWORD *)v8 + 2) = 0;
      v11 = *key % v9;
      *((_DWORD *)v8 + 3) = v11;
      *((_DWORD *)v8 + 2) = v3->_buckets[v11];
      v3->_buckets[v11] = (PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *)v8;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (00590E90) --------------------------------------------------------  // acclient.c:442020
int __thiscall PackableHashTable<unsigned long,Position>::add(PackableHashTable<unsigned long,Position> *this, const unsigned int *key, Position *data)
{
  PackableHashTable<unsigned long,Position> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,Position> **v5; // ebx@2
  PackableHashData<unsigned long,Position> *v6; // edx@3
  PackableHashData<unsigned long,Position> *v7; // eax@8
  int v8; // eax@9
  int v10; // ecx@11

  v3 = this;
  v4 = this->_table_size;
  if ( v4 )
  {
    v5 = this->_buckets;
    if ( v5 )
    {
      v6 = v5[*key % v4];
      if ( v6 )
      {
        while ( *key != v6->_key )
        {
          v6 = v6->_next;
          if ( !v6 )
            goto LABEL_8;
        }
        if ( v6 != (PackableHashData<unsigned long,Position> *)-4 )
          return 0;
      }
    }
  }
LABEL_8:
  v7 = (PackableHashData<unsigned long,Position> *)operator new(0x54u);
  if ( !v7 )
    return 0;
  PackableHashData<unsigned long,Position>::PackableHashData<unsigned long,Position>(v7, key, data, v3->_table_size);
  if ( !v8 )
    return 0;
  v10 = *(_DWORD *)(v8 + 80);
  *(_DWORD *)(v8 + 76) = v3->_buckets[v10];
  v3->_buckets[v10] = (PackableHashData<unsigned long,Position> *)v8;
  ++v3->_currNum;
  return 1;
}

//----- (00590F20) --------------------------------------------------------  // acclient.c:442066
int __thiscall PackableHashTable<unsigned long,Position>::remove(PackableHashTable<unsigned long,Position> *this, const unsigned int *key, Position *retval)
{
  PackableHashTable<unsigned long,Position> *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,Position> **v5; // esi@2
  const unsigned int v6; // edx@3
  PackableHashData<unsigned long,Position> *v7; // edi@3
  PackableHashData<unsigned long,Position> *v8; // esi@3
  int result; // eax@6

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = *key % v4, v7 = 0, (v8 = v5[v6]) != 0) )
  {
    while ( v8->_key != *key )
    {
      v7 = v8;
      v8 = v8->_next;
      if ( !v8 )
        goto LABEL_6;
    }
    retval->objcell_id = v8->_data.objcell_id;
    Frame::operator=((int)&retval->frame, (int)&v8->_data.frame);
    if ( v7 )
      v7->_next = v8->_next;
    else
      v3->_buckets[*key % v3->_table_size] = v8->_next;
    v8->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
    operator delete(v8);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00590FC0) --------------------------------------------------------  // acclient.c:442108
int __thiscall CBaseQualities::SetString(CBaseQualities *this, unsigned int stype, AC1Legacy::PStringBase<char> *val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > **v9; // edi@8
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v10; // edx@9

  v3 = this;
  if ( this->_strStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 16, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_strStatsTable = v5) != 0) )
  {
    v7 = v3->_strStatsTable;
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
        return PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(v7, &stype, val);
    }
    if ( v10 != (PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *)-4 )
    {
      AC1Legacy::PStringBase<unsigned short>::operator=(
        (AC1Legacy::PStringBase<unsigned short> *)&v10->_data,
        (AC1Legacy::PStringBase<unsigned short> *)val);
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(v7, &stype, val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (005910A0) --------------------------------------------------------  // acclient.c:442162
int __thiscall CBaseQualities::SetPosition(CBaseQualities *this, unsigned int stype, Position *val)
{
  CBaseQualities *v3; // edi@1
  void *v4; // eax@2
  PackableHashTable<unsigned long,Position> *v5; // esi@2
  int result; // eax@6
  PackableHashTable<unsigned long,Position> *v7; // ecx@7
  unsigned int v8; // esi@7
  PackableHashData<unsigned long,Position> **v9; // edi@8
  PackableHashData<unsigned long,Position> *v10; // edx@9
  int v11; // ST04_4@15

  v3 = this;
  if ( this->_posStatsTable
    || ((v4 = operator new(0x14u), (v5 = (PackableHashTable<unsigned long,Position> *)v4) == 0) ? (v5 = 0) : (*(_DWORD *)v4 = &PackableHashTable<unsigned long,Position>::vftable, *((_DWORD *)v4 + 1) = 0, *((_DWORD *)v4 + 2) = 0, *((_DWORD *)v4 + 3) = 16, *((_DWORD *)v4 + 4) = 0, PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4)),
        (v3->_posStatsTable = v5) != 0) )
  {
    v7 = v3->_posStatsTable;
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
        return PackableHashTable<unsigned long,Position>::add(v7, &stype, val);
    }
    if ( v10 != (PackableHashData<unsigned long,Position> *)-4 )
    {
      v11 = (int)&val->frame;
      v10->_data.objcell_id = val->objcell_id;
      Frame::operator=((int)&v10->_data.frame, v11);
      result = 1;
    }
    else
    {
LABEL_18:
      result = PackableHashTable<unsigned long,Position>::add(v7, &stype, val);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7E4480: using guessed type int (__thiscall *PackableHashTable<unsigned long,Position>::vftable)(void *, char);

//----- (00591180) --------------------------------------------------------  // acclient.c:442217
int __thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::UnPack(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v4; // edi@1
  void **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  int v10; // ebx@3
  unsigned int v11; // ebp@3
  unsigned int v12; // ecx@11
  int v13; // eax@11
  void **v14; // ecx@11
  unsigned int tempKey; // [sp+8h] [bp-Ch]@11
  void *start_addr; // [sp+Ch] [bp-8h]@3
  unsigned int blob_size; // [sp+10h] [bp-4h]@3

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,unsigned long>::Destroy((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *(_DWORD *)*v6;
      v13 = (int)((char *)*v6 + 4);
      *v6 = (void *)v13;
      tempKey = v12;
      v14 = *(void ***)v13;
      *v6 = (void *)(v13 + 4);
      addr = v14;
      if ( !PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
              (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4,
              (IDClass<_tagDataID,32,0> *)&tempKey,
              (const int *)&addr)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00591280) --------------------------------------------------------  // acclient.c:442283
int __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::remove(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, const unsigned int *key, AC1Legacy::PStringBase<char> *retval)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // ebp@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > **v5; // esi@2
  const unsigned int v6; // edx@3
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v7; // edi@3
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v8; // esi@3
  int result; // eax@6
  int v10; // ebx@7
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v11; // ecx@7
  int v12; // edi@10

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = *key % v4, v7 = 0, (v8 = v5[v6]) != 0) )
  {
    while ( v8->_key != *key )
    {
      v7 = v8;
      v8 = v8->_next;
      if ( !v8 )
        goto LABEL_6;
    }
    v10 = (int)&v8->_data;
    AC1Legacy::PStringBase<unsigned short>::operator=(
      (AC1Legacy::PStringBase<unsigned short> *)retval,
      (AC1Legacy::PStringBase<unsigned short> *)&v8->_data);
    v11 = v8->_next;
    if ( v7 )
      v7->_next = v11;
    else
      v3->_buckets[*key % v3->_table_size] = v11;
    v12 = *(_DWORD *)v10;
    if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v10 + 4)) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
    operator delete(v8);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00591320) --------------------------------------------------------  // acclient.c:442335
int __thiscall PackableHashTable<unsigned long,Position>::UnPack(PackableHashTable<unsigned long,Position> *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  PackableHashTable<unsigned long,Position> *v4; // ebx@1
  void **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  int v10; // edi@3
  unsigned int v11; // ebp@3
  void *v12; // eax@11
  PackObjVtbl *v13; // edx@11
  void *start_addr; // [sp+8h] [bp-50h]@3
  unsigned int blob_size; // [sp+Ch] [bp-4Ch]@3
  Position tempData; // [sp+10h] [bp-48h]@9

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,Position>::Destroy(this);
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 > 0x10000
    || v9 > 0x10000
    || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
    return 0;
  Position::Position(&tempData);
  size = 0;
  if ( v11 )
  {
    while ( (unsigned int)v10 >= 4 )
    {
      v12 = *v6;
      v13 = tempData.vfptr;
      addr = *(void ***)*v6;
      *v6 = (char *)v12 + 4;
      if ( !((int (__thiscall *)(Position *, void **, int))v13->UnPack)(&tempData, v6, v10)
        || !PackableHashTable<unsigned long,Position>::add(v4, (const unsigned int *)&addr, &tempData)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (00591430) --------------------------------------------------------  // acclient.c:442396
void __thiscall PackableHashTable<unsigned long,Position>::Destroy(PackableHashTable<unsigned long,Position> *this)
{
  PackableHashTable<unsigned long,Position> *v1; // esi@1

  v1 = this;
  PackableHashTable<unsigned long,Position>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
}

//----- (00591460) --------------------------------------------------------  // acclient.c:442411
void __thiscall PackableHashTable<unsigned long,Position>::EmptyContents(PackableHashTable<unsigned long,Position> *this)
{
  PackableHashTable<unsigned long,Position> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<unsigned long,Position> *v3; // eax@3
  PackableHashData<unsigned long,Position> *v4; // esi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005914C0) --------------------------------------------------------  // acclient.c:442448
PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *__thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vector_deleting_destructor(PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *this, unsigned int a2)
{
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable;
  PackableHashTable<unsigned long,unsigned long>::Destroy((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4458: using guessed type int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char);

//----- (005914F0) --------------------------------------------------------  // acclient.c:442464
PackableHashTable<unsigned long,Position> *__thiscall PackableHashTable<unsigned long,Position>::scalar_deleting_destructor(PackableHashTable<unsigned long,Position> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,Position> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,Position>::vftable;
  PackableHashTable<unsigned long,Position>::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4480: using guessed type int (__thiscall *PackableHashTable<unsigned long,Position>::vftable)(void *, char);

//----- (00591520) --------------------------------------------------------  // acclient.c:442480
int __thiscall CBaseQualities::RemoveDataID(CBaseQualities *this, unsigned int stype)
{
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v2; // ecx@1
  int result; // eax@2
  IDClass<_tagDataID,32,0> dummy; // [sp+0h] [bp-4h]@1

  dummy.id = (unsigned int)this;
  v2 = this->_didStatsTable;
  if ( v2 )
    result = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(v2, &stype, &dummy);
  else
    result = 0;
  return result;
}

//----- (00591550) --------------------------------------------------------  // acclient.c:442496
int __thiscall CBaseQualities::RemovePosition(CBaseQualities *this, unsigned int stype)
{
  CBaseQualities *v2; // esi@1
  PackableHashTable<unsigned long,Position> *v3; // ecx@1
  int result; // eax@2
  Position dummy; // [sp+0h] [bp-48h]@1

  v2 = this;
  dummy.vfptr = (PackObjVtbl *)&Position::vftable;
  dummy.objcell_id = 0;
  LODWORD(dummy.frame.qw) = 1065353216;
  LODWORD(dummy.frame.qx) = 0;
  LODWORD(dummy.frame.qy) = 0;
  LODWORD(dummy.frame.qz) = 0;
  LODWORD(dummy.frame.m_fOrigin.x) = 0;
  LODWORD(dummy.frame.m_fOrigin.y) = 0;
  LODWORD(dummy.frame.m_fOrigin.z) = 0;
  Frame::cache(&dummy.frame);
  v3 = v2->_posStatsTable;
  if ( v3 )
    result = PackableHashTable<unsigned long,Position>::remove(v3, &stype, &dummy);
  else
    result = 0;
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (005915E0) --------------------------------------------------------  // acclient.c:442524
signed int __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::Pack(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v3; // ebx@1
  signed int result; // eax@1
  unsigned int v5; // ebp@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            AC1Legacy::PStringBase<char>::Pack(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (00591670) --------------------------------------------------------  // acclient.c:442575
signed int __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::pack_size(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = AC1Legacy::PStringBase<char>::Pack(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (005916D0) --------------------------------------------------------  // acclient.c:442607
int __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::UnPack(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v4; // ebx@1
  unsigned int **v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // eax@3
  unsigned int v10; // edi@3
  unsigned int v11; // ebp@3
  unsigned int *v12; // eax@10
  unsigned int *v13; // ecx@14
  unsigned int tempKey; // [sp+8h] [bp-Ch]@10
  void *start_addr; // [sp+Ch] [bp-8h]@3
  unsigned int blob_size; // [sp+10h] [bp-4h]@3
  void **addra; // [sp+18h] [bp+4h]@8

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = (unsigned int **)addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::Destroy(this);
  v7 = *(_DWORD *)*addr;
  ++*v6;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&size);
    addra = 0;
    if ( v11 )
    {
      while ( v10 >= 4 )
      {
        v12 = *v6;
        tempKey = **v6;
        *v6 = v12 + 1;
        if ( !AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&size, (void **)v6, v10)
          || !PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::add(
                v4,
                &tempKey,
                (AC1Legacy::PStringBase<char> *)&size)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        addra = (void **)((char *)addra + 1);
        if ( (unsigned int)addra >= v11 )
          goto LABEL_14;
      }
      v13 = &size;
    }
    else
    {
LABEL_14:
      v13 = &size;
      if ( blob_size >= (char *)*v6 - (_BYTE *)start_addr )
      {
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
        return 1;
      }
    }
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)v13);
  }
  return 0;
}

//----- (00591800) --------------------------------------------------------  // acclient.c:442683
void __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::Destroy(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v1; // esi@1

  v1 = this;
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
}

//----- (00591830) --------------------------------------------------------  // acclient.c:442698
void __thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::EmptyContents(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v1; // ebp@1
  unsigned int v2; // eax@2
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v3; // esi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@4
  PackableHashData<unsigned long,AC1Legacy::PStringBase<char> > *v5; // ebx@4
  unsigned int i; // [sp+4h] [bp-4h]@2

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_data.m_buffer;
            v5 = v3->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
              v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
            operator delete(v3);
            v3 = v5;
          }
          while ( v5 );
          v2 = i;
        }
        v1->_buckets[v2++] = 0;
        i = v2;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}

//----- (005918C0) --------------------------------------------------------  // acclient.c:442741
PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *__thiscall PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::scalar_deleting_destructor(PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *this, unsigned int a2)
{
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable;
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E446C: using guessed type int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (005918F0) --------------------------------------------------------  // acclient.c:442757
int __thiscall CBaseQualities::RemoveString(CBaseQualities *this, unsigned int stype)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  CBaseQualities *v3; // edi@1
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v4; // ecx@1
  int v5; // eax@2
  int v6; // edi@2
  AC1Legacy::PStringBase<char> dummy; // [sp+0h] [bp-4h]@1

  v2 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v3 = this;
  dummy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v4 = v3->_strStatsTable;
  if ( v4 )
  {
    v5 = PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::remove(v4, &stype, &dummy);
    v2 = dummy.m_buffer;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return v6;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070AA90) --------------------------------------------------------  // acclient.c:797882
void sub_70AA90()
{
  flt_870FB0 = 1000.0 + 1.0;
}

//----- (0070AAB0) --------------------------------------------------------  // acclient.c:797888
void sub_70AAB0()
{
  flt_870FB4 = 24.0 * 8.0;
}

//----- (0070AAD0) --------------------------------------------------------  // acclient.c:797894
void sub_70AAD0()
{
  flt_870FB8 = 24.0 * 0.5;
}

//----- (0070AAF0) --------------------------------------------------------  // acclient.c:797900
int sub_70AAF0()
{
  return atexit(nullsub_1417);
}

