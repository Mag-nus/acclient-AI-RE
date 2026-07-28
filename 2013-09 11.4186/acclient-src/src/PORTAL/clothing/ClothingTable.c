/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClothingTable
   Object     : PORTAL\clothing\ClothingTable.obj
   Functions  : 100
   Addresses  : 00526930 - 0070D820 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526930) --------------------------------------------------------  // acclient.c:342118
signed int WaitDialog::GetUIElementType()
{
  return 25;
}

//----- (005A7230) --------------------------------------------------------  // acclient.c:464268
unsigned int __thiscall ClothingTable::Pack(ClothingTable *this, void **addr, unsigned int size)
{
  ClothingTable *v3; // edi@1
  DBObj *v4; // eax@1
  char *v5; // ebx@1
  int v6; // esi@1
  unsigned int v7; // esi@1
  ClothingTable *v9; // [sp+8h] [bp-4h]@1

  v9 = this;
  v3 = this;
  v4 = this->m_pLast;
  v9 = 0;
  v5 = (char *)&this->m_bLoaded;
  v6 = (*((int (__thiscall **)(DBObj **, int *, _DWORD))&v4->m_bLoaded + 1))(&this->m_pLast, &v9, 0);
  v7 = (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v5 + 12))(&v3->m_bLoaded, &v9, 0) + v6;
  if ( size >= v7 )
  {
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 12))(&v3->m_bLoaded, addr, size);
    (*((void (__thiscall **)(int, void **, unsigned int))&v3->m_pLast->m_bLoaded + 1))(&v3->m_pLast, addr, size);
  }
  return v7;
}

//----- (005A7290) --------------------------------------------------------  // acclient.c:464293
int __thiscall ClothingTable::UnPack(ClothingTable *this, void **addr, unsigned int size)
{
  ClothingTable *v3; // esi@1
  DBObj *v4; // eax@1
  char *v5; // edi@1
  int v6; // ebp@1
  void *v7; // ebp@2
  int v9; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = this->m_pLast;
  v9 = 0;
  v5 = (char *)&this->m_bLoaded;
  v6 = (*((int (__thiscall **)(DBObj **, int *, _DWORD))&v4->m_bLoaded + 1))(&this->m_pLast, &v9, 0);
  if ( size < (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v5 + 12))(&v3->m_bLoaded, &v9, 0) + v6 )
    return 0;
  v7 = *addr;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 16))(&v3->m_bLoaded, addr, size);
  LODWORD(v3->m_pLast->m_timeStamp)(&v3->m_pLast, addr, size);
  if ( size < (_BYTE *)*addr - (_BYTE *)v7 )
  {
    *addr = v7;
    return 0;
  }
  return 1;
}

//----- (005A7310) --------------------------------------------------------  // acclient.c:464321
PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *__thiscall PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor(PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *this, unsigned int a2)
{
  PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>Vtbl *)PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E5A2C: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable[3])(void *, char);

//----- (005A7330) --------------------------------------------------------  // acclient.c:464334
PackableHashIterator<unsigned long,CloPaletteTemplate> *__thiscall PackableHashIterator<unsigned long,CloPaletteTemplate>::vector_deleting_destructor(PackableHashIterator<unsigned long,CloPaletteTemplate> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,CloPaletteTemplate> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,CloPaletteTemplate>Vtbl *)PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E5A30: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable[2])(void *, char);

//----- (005A7350) --------------------------------------------------------  // acclient.c:464347
PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::begin(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v4; // edi@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v5; // esi@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v6; // ecx@5
  PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> *v7; // eax@5
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>Vtbl *)PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>Vtbl *)PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E5A2C: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable[3])(void *, char);

//----- (005A73B0) --------------------------------------------------------  // acclient.c:464392
CloPaletteTemplate *__thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::lookup(PackableHashTable<unsigned long,CloPaletteTemplate> *this, const unsigned int *key)
{
  unsigned int v2; // edi@1
  PackableHashData<unsigned long,CloPaletteTemplate> **v3; // esi@2
  PackableHashData<unsigned long,CloPaletteTemplate> *v4; // edx@3
  CloPaletteTemplate *result; // eax@6

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

//----- (005A73F0) --------------------------------------------------------  // acclient.c:464419
PackableHashIterator<unsigned long,CloPaletteTemplate> *__thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::begin(PackableHashTable<unsigned long,CloPaletteTemplate> *this, PackableHashIterator<unsigned long,CloPaletteTemplate> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,CloPaletteTemplate> **v4; // edi@2
  PackableHashData<unsigned long,CloPaletteTemplate> **v5; // esi@2
  PackableHashData<unsigned long,CloPaletteTemplate> **v6; // ecx@5
  PackableHashIterator<unsigned long,CloPaletteTemplate> *v7; // eax@5
  PackableHashData<unsigned long,CloPaletteTemplate> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,CloPaletteTemplate>Vtbl *)PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,CloPaletteTemplate>Vtbl *)PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E5A30: using guessed type int (__thiscall *PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable[2])(void *, char);

//----- (005A7450) --------------------------------------------------------  // acclient.c:464464
void __thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::EmptyContents(PackableHashTable<unsigned long,CloPaletteTemplate> *this)
{
  PackableHashTable<unsigned long,CloPaletteTemplate> *v1; // ebx@1
  unsigned int v2; // ebp@2
  PackableHashData<unsigned long,CloPaletteTemplate> *v3; // esi@3
  PackableHashData<unsigned long,CloPaletteTemplate> *v4; // edi@4

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
            CloPaletteTemplate::~CloPaletteTemplate(&v3->_data);
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

//----- (005A74B0) --------------------------------------------------------  // acclient.c:464500
CloPaletteTemplate *__thiscall ClothingTable::GetCloPaletteTemplate(ClothingTable *this, const unsigned int key)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,CloPaletteTemplate> **v3; // ecx@2
  PackableHashData<unsigned long,CloPaletteTemplate> *v4; // edx@3
  CloPaletteTemplate *result; // eax@6

  v2 = this->_paletteTemplatesHash._table_size;
  if ( v2 && (v3 = this->_paletteTemplatesHash._buckets) != 0 && (v4 = v3[key % v2]) != 0 )
  {
    while ( key != v4->_key )
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

//----- (005A74F0) --------------------------------------------------------  // acclient.c:464527
ClothingBase *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::lookup(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, IDClass<_tagDataID,32,0> *key)
{
  unsigned int v2; // edi@1
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v3; // esi@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v4; // edx@3
  ClothingBase *result; // eax@6

  v2 = this->_table_size;
  if ( v2 && (v3 = this->_buckets) != 0 && (v4 = v3[key->id % v2]) != 0 )
  {
    while ( key->id != v4->_key.id )
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

//----- (005A7530) --------------------------------------------------------  // acclient.c:464554
signed int __thiscall PackableHashTable<unsigned long,PackableList<EmoteSet>>::Pack(PackableHashTable<unsigned long,CloPaletteTemplate> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,CloPaletteTemplate> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,CloPaletteTemplate> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,CloPaletteTemplate>::pack_size(this);
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

//----- (005A75C0) --------------------------------------------------------  // acclient.c:464605
signed int __thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::pack_size(PackableHashTable<unsigned long,CloPaletteTemplate> *this)
{
  PackableHashTable<unsigned long,CloPaletteTemplate> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,CloPaletteTemplate> *i; // esi@2
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

//----- (005A7620) --------------------------------------------------------  // acclient.c:464637
void __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::EmptyContents(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *v1; // ebx@1
  unsigned int v2; // ebp@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v3; // esi@3
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v4; // edi@4

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
            ClothingBase::~ClothingBase(&v3->_data);
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

//----- (005A7680) --------------------------------------------------------  // acclient.c:464673
void __thiscall ClothingTable::GetSubDataIDs(ClothingTable *this, QualifiedDataIDArray *id_array)
{
  ClothingTable *v2; // edi@1
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v3; // ebx@1
  QualifiedDataID *v4; // eax@4
  CloObjectEffect *v5; // esi@6
  QualifiedDataID *v6; // eax@6
  unsigned int v7; // edi@6
  int v8; // ebx@7
  CloTextureEffect *v9; // eax@8
  QualifiedDataID *v10; // eax@8
  QualifiedDataID *v11; // eax@8
  bool v12; // cf@10
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v13; // eax@12
  unsigned int v14; // eax@13
  unsigned int v15; // eax@18
  unsigned int v16; // ecx@18
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v17; // esi@19
  PackableHashData<unsigned long,CloPaletteTemplate> **v18; // edx@19
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v19; // ebx@22
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v20; // edi@22
  QualifiedDataID *v21; // eax@24
  unsigned int v22; // esi@24
  int v23; // edi@25
  QualifiedDataID *v24; // eax@26
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v25; // eax@28
  unsigned int v26; // eax@29
  int v27; // [sp+Ch] [bp-6Ch]@5
  unsigned int i; // [sp+10h] [bp-68h]@4
  ClothingTable *v29; // [sp+14h] [bp-64h]@1
  QualifiedDataID v30; // [sp+18h] [bp-60h]@4
  QualifiedDataID v31; // [sp+20h] [bp-58h]@6
  unsigned int v32; // [sp+28h] [bp-50h]@24
  int v33; // [sp+2Ch] [bp-4Ch]@26
  QualifiedDataID v34; // [sp+30h] [bp-48h]@8
  QualifiedDataID v35; // [sp+38h] [bp-40h]@8
  ClothingBase clobase; // [sp+40h] [bp-38h]@1
  CloTextureEffect texeff; // [sp+4Ch] [bp-2Ch]@1
  PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase> iter; // [sp+58h] [bp-20h]@1
  CloPaletteTemplate paltemp; // [sp+68h] [bp-10h]@23

  v2 = this;
  v29 = this;
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::begin(&this->_cloBaseHash, &iter);
  ClothingBase::ClothingBase(&clobase);
  CloTextureEffect::CloTextureEffect(&texeff);
  v3 = iter._current;
  if ( iter._current )
  {
    while ( 1 )
    {
      ClothingBase::operator=((int)&clobase, (int)&v3->_data);
      QualifiedDataID::QualifiedDataID(&v30, v3->_key, 0);
      QualifiedDataIDArray::AddQDID(id_array, v4, 8u);
      i = 0;
      if ( clobase.numObjectEffects > 0 )
      {
        v27 = 0;
        do
        {
          v5 = &clobase.objectEffects[v27];
          QualifiedDataID::QualifiedDataID(&v31, clobase.objectEffects[v27].objectID, 0);
          QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
          v7 = 0;
          if ( v5->numTextureEffects )
          {
            v8 = 0;
            do
            {
              v9 = v5->textureEffects;
              texeff.oldTexID.id = v9[v8].oldTexID.id;
              texeff.newTexID.id = v9[v8].newTexID.id;
              QualifiedDataID::QualifiedDataID(&v34, texeff.oldTexID, 0);
              QualifiedDataIDArray::AddQDID(id_array, v10, 8u);
              QualifiedDataID::QualifiedDataID(&v35, texeff.newTexID, 0);
              QualifiedDataIDArray::AddQDID(id_array, v11, 8u);
              ++v7;
              ++v8;
            }
            while ( v7 < v5->numTextureEffects );
            v3 = iter._current;
          }
          v12 = i++ + 1 < clobase.numObjectEffects;
          ++v27;
        }
        while ( v12 );
        v2 = v29;
      }
      v13 = v3->_next;
      if ( !v13 )
      {
        v14 = v3->_hashVal + 1;
        if ( v14 >= iter._table_size )
        {
LABEL_16:
          v13 = 0;
        }
        else
        {
          while ( !iter._buckets[v14] )
          {
            ++v14;
            if ( v14 >= iter._table_size )
              goto LABEL_16;
          }
          v13 = iter._buckets[v14];
        }
      }
      iter._current = v13;
      if ( !v13 )
        break;
      v3 = iter._current;
    }
  }
  v15 = v2->_paletteTemplatesHash._table_size;
  v16 = 0;
  if ( v15 <= 0 )
  {
LABEL_22:
    v19 = 0;
    iter._buckets = (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **)v2->_paletteTemplatesHash._buckets;
    v20 = iter._buckets;
  }
  else
  {
    v17 = (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **)v2->_paletteTemplatesHash._buckets;
    v18 = v2->_paletteTemplatesHash._buckets;
    while ( !*v18 )
    {
      ++v16;
      ++v18;
      if ( v16 >= v15 )
        goto LABEL_22;
    }
    v19 = v17[v16];
    v20 = (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **)v2->_paletteTemplatesHash._buckets;
    iter._buckets = v17;
  }
  iter._table_size = v15;
  CloPaletteTemplate::CloPaletteTemplate(&paltemp);
  if ( v19 )
  {
    do
    {
      CloPaletteTemplate::CloPaletteTemplate((CloPaletteTemplate *)&v31, (CloPaletteTemplate *)&v19->_data);
      QualifiedDataID::QualifiedDataID(&v35, v31.ID, 0);
      QualifiedDataIDArray::AddQDID(id_array, v21, 8u);
      v22 = 0;
      if ( v32 )
      {
        v23 = 0;
        do
        {
          QualifiedDataID::QualifiedDataID(&v34, *(IDClass<_tagDataID,32,0> *)(v23 + v33 + 16), 0);
          QualifiedDataIDArray::AddQDID(id_array, v24, 8u);
          ++v22;
          v23 += 20;
        }
        while ( v22 < v32 );
        v20 = iter._buckets;
      }
      CloPaletteTemplate::~CloPaletteTemplate((CloPaletteTemplate *)&v31);
      v25 = (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *)v19->_hashVal;
      if ( !v25 )
      {
        v26 = v19[1]._key.id + 1;
        if ( v26 >= iter._table_size )
        {
LABEL_32:
          v25 = 0;
        }
        else
        {
          while ( !v20[v26] )
          {
            ++v26;
            if ( v26 >= iter._table_size )
              goto LABEL_32;
          }
          v25 = v20[v26];
        }
      }
      v19 = v25;
    }
    while ( v25 );
  }
  CloPaletteTemplate::~CloPaletteTemplate(&paltemp);
  texeff.vfptr = (PackObjVtbl *)&PackObj::vftable;
  ClothingBase::~ClothingBase(&clobase);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005A7900) --------------------------------------------------------  // acclient.c:464866
int __thiscall ClothingTable::BuildObjDesc(ClothingTable *this, IDClass<_tagDataID,32,0> setup, const unsigned int pt, ShadePackage *shades, ObjDesc *od)
{
  ClothingTable *v5; // ebp@1
  char *v6; // ecx@1
  unsigned int v7; // edi@1
  int v8; // ebx@2
  int v9; // edx@3
  ClothingBase *v10; // eax@7
  unsigned int v11; // eax@35
  CloPaletteTemplate *v12; // eax@48
  CloPaletteTemplate *v13; // edi@48
  const int v14; // ebp@49
  unsigned int v15; // ebx@50
  QualifiedDataID *v16; // eax@51
  int v17; // esi@51
  long double v18; // st7@52
  CloSubpalEffect *v19; // eax@52
  unsigned int v20; // ecx@52
  int v21; // eax@52
  unsigned int v22; // esi@52
  CloSubpalEffect *v23; // eax@53
  unsigned int v24; // ecx@53
  unsigned int v25; // eax@54
  QualifiedDataID v27; // [sp+18h] [bp-20h]@51
  Subpalette subpal; // [sp+20h] [bp-18h]@52

  v5 = this;
  v6 = (char *)&this->_cloBaseHash;
  v7 = *((_DWORD *)v6 + 3);
  if ( !v7 )
    goto LABEL_8;
  v8 = *((_DWORD *)v6 + 2);
  if ( !v8 )
    goto LABEL_8;
  v9 = *(_DWORD *)(v8 + 4 * (setup.id % v7));
  if ( !v9 )
    goto LABEL_8;
  while ( setup.id != *(_DWORD *)v9 )
  {
    v9 = *(_DWORD *)(v9 + 16);
    if ( !v9 )
      goto LABEL_8;
  }
  v10 = (ClothingBase *)(v9 + 4);
  if ( v9 == -4 )
  {
LABEL_8:
    if ( setup.id == UMBRAEN_MALE_CROWN_SETUP_0.id
      || setup.id == UMBRAEN_MALE_CROWN_GEN_SETUP_0.id
      || setup.id == UMBRAEN_MALE_NOCROWN_SETUP_0.id
      || setup.id == UMBRAEN_MALE_VOID_SETUP_0.id )
    {
      v11 = UMBRAEN_MALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == UMBRAEN_FEMALE_CROWN_SETUP_0.id
           || setup.id == UMBRAEN_FEMALE_CROWN_GEN_SETUP_0.id
           || setup.id == UMBRAEN_FEMALE_NOCROWN_SETUP_0.id
           || setup.id == UMBRAEN_FEMALE_VOID_SETUP_0.id )
    {
      v11 = UMBRAEN_FEMALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == PENUMBRAEN_MALE_CROWN_SETUP_0.id
           || setup.id == PENUMBRAEN_MALE_CROWN_GEN_SETUP_0.id
           || setup.id == PENUMBRAEN_MALE_NOCROWN_SETUP_0.id
           || setup.id == PENUMBRAEN_MALE_VOID_SETUP_0.id )
    {
      v11 = PENUMBRAEN_MALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == PENUMBRAEN_FEMALE_CROWN_SETUP_0.id
           || setup.id == PENUMBRAEN_FEMALE_CROWN_GEN_SETUP_0.id
           || setup.id == PENUMBRAEN_FEMALE_NOCROWN_SETUP_0.id
           || setup.id == PENUMBRAEN_FEMALE_VOID_SETUP_0.id )
    {
      v11 = PENUMBRAEN_FEMALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == UNDEAD_MALE_UNDEAD_GEN_SETUP_0.id
           || setup.id == UNDEAD_MALE_SKELETON_SETUP_0.id
           || setup.id == UNDEAD_MALE_SKELETON_NOFLAME_SETUP_0.id
           || setup.id == UNDEAD_MALE_ZOMBIE_SETUP_0.id
           || setup.id == UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP_0.id )
    {
      v11 = UNDEAD_MALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == UNDEAD_FEMALE_UNDEAD_GEN_SETUP_0.id
           || setup.id == UNDEAD_FEMALE_SKELETON_SETUP_0.id
           || setup.id == UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP_0.id
           || setup.id == UNDEAD_FEMALE_ZOMBIE_SETUP_0.id
           || setup.id == UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP_0.id )
    {
      v11 = UNDEAD_FEMALE_CLOTHING_DEFAULT_0.id;
    }
    else if ( setup.id == ANAKSHAY_MALE_SETUP_0.id )
    {
      v11 = HUMAN_MALE_CLOTHING_DEFAULT_0.id;
    }
    else
    {
      if ( setup.id != ANAKSHAY_FEMALE_SETUP_0.id )
        return 1;
      v11 = HUMAN_FEMALE_CLOTHING_DEFAULT_0.id;
    }
    setup.id = v11;
    if ( v11 == stru_8ED9F4.id )
      return 1;
    v10 = PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::lookup(
            (PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *)v6,
            &setup);
    if ( !v10 )
      return 1;
  }
  if ( ClothingBase::ApplyPartAndTextureChanges(v10, od) )
  {
    if ( !pt )
      return 1;
    v12 = PackableHashTable<unsigned long,CloPaletteTemplate>::lookup(&v5->_paletteTemplatesHash, &pt);
    v13 = v12;
    if ( v12 )
    {
      v14 = 0;
      if ( v12->numSubpalEffects )
      {
        v15 = 0;
        while ( 1 )
        {
          QualifiedDataID::QualifiedDataID(&v27, v13->subpalEffects[v15].palSet, 0x18u);
          v17 = DBObj::Get(v16);
          if ( !v17 )
            break;
          subpal.subID.id = stru_8ED9F4.id;
          subpal.vfptr = (PackObjVtbl *)&Subpalette::vftable;
          subpal.offset = 0;
          subpal.numcolors = 0;
          subpal.prev = 0;
          subpal.next = 0;
          v18 = ShadePackage::GetVal(shades, v14);
          subpal.subID.id = PalSet::GetPaletteID((PalSet *)v17, (IDClass<_tagDataID,32,0> *)&pt, v18)->id;
          (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 20))(v17);
          v19 = v13->subpalEffects;
          v20 = v19[v15].numRanges;
          v21 = (int)&v19[v15];
          v22 = 0;
          if ( v20 )
          {
            do
            {
              subpal.offset = *(_DWORD *)(*(_DWORD *)(v21 + 8) + 4 * v22);
              subpal.numcolors = *(_DWORD *)(*(_DWORD *)(v21 + 12) + 4 * v22);
              ObjDesc::AddSubpalette(od, &subpal);
              v23 = v13->subpalEffects;
              v24 = v23[v15].numRanges;
              v21 = (int)&v23[v15];
              ++v22;
            }
            while ( v22 < v24 );
          }
          v25 = v13->numSubpalEffects;
          ++v14;
          ++v15;
          subpal.vfptr = (PackObjVtbl *)&PackObj::vftable;
          if ( v14 >= v25 )
            return 1;
        }
        return 0;
      }
      return 1;
    }
  }
  return 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);

//----- (005A7C00) --------------------------------------------------------  // acclient.c:465039
signed int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::Pack(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, void **addr, unsigned int size)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,GuestInfo>::pack_size((PackableHashTable<unsigned long,GuestInfo> *)this);
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
              *(_DWORD *)*addr = v7->_key.id;
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

//----- (005A7CF0) --------------------------------------------------------  // acclient.c:465122
int __thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::UnPack(PackableHashTable<unsigned long,CloPaletteTemplate> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<unsigned long,CloPaletteTemplate> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  CloPaletteTemplate *v14; // ecx@16
  void *start_addr; // [sp+8h] [bp-18h]@3
  unsigned int blob_size; // [sp+Ch] [bp-14h]@3
  CloPaletteTemplate tempData; // [sp+10h] [bp-10h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,CloPaletteTemplate>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
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
    CloPaletteTemplate::CloPaletteTemplate(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( (unsigned int)v10 >= 4 )
      {
        v12 = *v6;
        v13 = tempData.vfptr;
        addr = *(void ***)*v6;
        *v6 = (char *)v12 + 4;
        if ( !((int (__thiscall *)(CloPaletteTemplate *, void **, int))v13->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<unsigned long,CloPaletteTemplate>::add(v4, (const unsigned int *)&addr, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v14 = &tempData;
    }
    else
    {
LABEL_16:
      v14 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        CloPaletteTemplate::~CloPaletteTemplate(&tempData);
        return 1;
      }
    }
    CloPaletteTemplate::~CloPaletteTemplate(v14);
  }
  return 0;
}

//----- (005A7E30) --------------------------------------------------------  // acclient.c:465202
int __thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::add(PackableHashTable<unsigned long,CloPaletteTemplate> *this, const unsigned int *key, CloPaletteTemplate *data)
{
  PackableHashTable<unsigned long,CloPaletteTemplate> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<unsigned long,CloPaletteTemplate> **v5; // ebx@2
  PackableHashData<unsigned long,CloPaletteTemplate> *v6; // edx@3
  void *v7; // esi@8
  unsigned int v8; // ebx@9
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
  if ( v6 == (PackableHashData<unsigned long,CloPaletteTemplate> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x1Cu);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      CloPaletteTemplate::CloPaletteTemplate((CloPaletteTemplate *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 5) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 6) = v9;
      *((_DWORD *)v7 + 5) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,CloPaletteTemplate> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005A7ED0) --------------------------------------------------------  // acclient.c:465250
PackableHashTable<unsigned long,CloPaletteTemplate> *__thiscall PackableHashTable<unsigned long,CloPaletteTemplate>::vector_deleting_destructor(PackableHashTable<unsigned long,CloPaletteTemplate> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,CloPaletteTemplate> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CloPaletteTemplate>::vftable;
  PackableHashTable<unsigned long,CloPaletteTemplate>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5A48: using guessed type int (__thiscall *PackableHashTable<unsigned long,CloPaletteTemplate>::vftable)(void *, char);

//----- (005A7F20) --------------------------------------------------------  // acclient.c:465272
int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::UnPack(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  void **v10; // ebx@5
  unsigned int v11; // ebp@5
  ClothingBase *v12; // ecx@16
  int data_r; // [sp+8h] [bp-1Ch]@11
  IDClass<_tagDataID,32,0> tempKey; // [sp+Ch] [bp-18h]@12
  void *start_addr; // [sp+10h] [bp-14h]@3
  unsigned int blob_size; // [sp+14h] [bp-10h]@3
  ClothingBase tempData; // [sp+18h] [bp-Ch]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = (void **)(v3 - 4);
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    ClothingBase::ClothingBase(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( 1 )
      {
        addr = v10;
        if ( !PackObj::UNPACK_TYPE(&data_r, v6, (unsigned int *)&addr) )
          break;
        tempKey.id = data_r;
        if ( !((int (__thiscall *)(ClothingBase *, void **, void **))tempData.vfptr->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::add(v4, &tempKey, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        ClothingBase::~ClothingBase(&tempData);
        return 1;
      }
    }
    ClothingBase::~ClothingBase(v12);
  }
  return 0;
}

//----- (005A8070) --------------------------------------------------------  // acclient.c:465352
int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::add(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, IDClass<_tagDataID,32,0> *key, ClothingBase *data)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> **v5; // ebx@2
  PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *v6; // edx@3
  void *v7; // esi@8
  unsigned int v8; // ebx@9
  unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[key->id % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( key->id != v6->_key.id )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x18u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = key->id;
      ClothingBase::ClothingBase((ClothingBase *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 4) = 0;
      v9 = key->id % v8;
      *((_DWORD *)v7 + 5) = v9;
      *((_DWORD *)v7 + 4) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<IDClass<_tagDataID,32,0>,ClothingBase> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (005A8110) --------------------------------------------------------  // acclient.c:465400
PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor(PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *this, unsigned int a2)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5A34: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable)(void *, char);

//----- (005A8160) --------------------------------------------------------  // acclient.c:465422
void __thiscall ClothingTable::ClothingTable(ClothingTable *this, IDClass<_tagDataID,32,0> gid)
{
  ClothingTable *v2; // esi@1
  int v3; // ecx@1
  int v4; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_cloBaseHash;
  v2->vfptr = (InterfaceVtbl *)&ClothingTable::vftable;
  v2->vfptr = (PackObjVtbl *)&ClothingTable::vftable;
  *(_DWORD *)v3 = &PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 8;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_cloBaseHash);
  v4 = (int)&v2->_paletteTemplatesHash;
  *(_DWORD *)v4 = &PackableHashTable<unsigned long,CloPaletteTemplate>::vftable;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 32;
  *(_DWORD *)(v4 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_paletteTemplatesHash);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5A34: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable)(void *, char);
// 7E5A48: using guessed type int (__thiscall *PackableHashTable<unsigned long,CloPaletteTemplate>::vftable)(void *, char);
// 7E5A5C: using guessed type void *ClothingTable::vftable;
// 7E5A70: using guessed type __int32 (__stdcall *ClothingTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005A81D0) --------------------------------------------------------  // acclient.c:465455
ClothingTable *__thiscall ClothingTable::vector_deleting_destructor(ClothingTable *this, unsigned int a2)
{
  return ClothingTable::vector_deleting_destructor((ClothingTable *)((char *)this - 48), a2);
}

//----- (005A81E0) --------------------------------------------------------  // acclient.c:465461
ClothingTable *__thiscall ClothingTable::vector_deleting_destructor(ClothingTable *this, unsigned int a2)
{
  ClothingTable *v2; // esi@1

  v2 = this;
  ClothingTable::~ClothingTable(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005A8200) --------------------------------------------------------  // acclient.c:465473
void __thiscall ClothingTable::~ClothingTable(ClothingTable *this)
{
  ClothingTable *v1; // edi@1
  char *v2; // esi@1

  v1 = this;
  v2 = (char *)&this->_paletteTemplatesHash;
  this->vfptr = (InterfaceVtbl *)&ClothingTable::vftable;
  this->vfptr = (PackObjVtbl *)&ClothingTable::vftable;
  this->_paletteTemplatesHash.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,CloPaletteTemplate>::vftable;
  PackableHashTable<unsigned long,CloPaletteTemplate>::EmptyContents(&this->_paletteTemplatesHash);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->_cloBaseHash.vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable;
  PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::EmptyContents(&v1->_cloBaseHash);
  if ( v1->_cloBaseHash._buckets )
  {
    operator delete[](v1->_cloBaseHash._buckets);
    v1->_cloBaseHash._buckets = 0;
  }
  v1->_cloBaseHash._table_size = 0;
  v1->_cloBaseHash.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5A34: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable)(void *, char);
// 7E5A48: using guessed type int (__thiscall *PackableHashTable<unsigned long,CloPaletteTemplate>::vftable)(void *, char);
// 7E5A5C: using guessed type void *ClothingTable::vftable;
// 7E5A70: using guessed type __int32 (__stdcall *ClothingTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070D340) --------------------------------------------------------  // acclient.c:800029
int sub_70D340()
{
  return atexit(_E74_90);
}

//----- (0070D350) --------------------------------------------------------  // acclient.c:800035
int _E76_74()
{
  return atexit(nullsub_1459);
}

//----- (0070D360) --------------------------------------------------------  // acclient.c:800041
int _E79_68()
{
  return atexit(_E80_67);
}

//----- (0070D370) --------------------------------------------------------  // acclient.c:800047
int _E82_45()
{
  return atexit(_E83_43);
}

//----- (0070D380) --------------------------------------------------------  // acclient.c:800053
int _E85_30()
{
  return atexit(_E86_24);
}

//----- (0070D390) --------------------------------------------------------  // acclient.c:800059
int _E88_21()
{
  return atexit(_E89_34);
}

//----- (0070D3A0) --------------------------------------------------------  // acclient.c:800065
int sub_70D3A0()
{
  return atexit(_E92_39);
}

//----- (0070D3B0) --------------------------------------------------------  // acclient.c:800071
int _E94_30()
{
  return atexit(nullsub_1465);
}

//----- (0070D3C0) --------------------------------------------------------  // acclient.c:800077
int sub_70D3C0()
{
  return atexit(nullsub_1466);
}

//----- (0070D3D0) --------------------------------------------------------  // acclient.c:800083
int sub_70D3D0()
{
  return atexit(nullsub_1467);
}

//----- (0070D3E0) --------------------------------------------------------  // acclient.c:800089
int sub_70D3E0()
{
  return atexit(nullsub_1468);
}

//----- (0070D3F0) --------------------------------------------------------  // acclient.c:800095
int sub_70D3F0()
{
  return atexit(_E107_97);
}

//----- (0070D400) --------------------------------------------------------  // acclient.c:800101
int _E109_81()
{
  return atexit(nullsub_1470);
}

//----- (0070D410) --------------------------------------------------------  // acclient.c:800107
int sub_70D410()
{
  return atexit(_E113_69);
}

//----- (0070D420) --------------------------------------------------------  // acclient.c:800113
int _E115_87()
{
  return atexit(_E116_61);
}

//----- (0070D430) --------------------------------------------------------  // acclient.c:800119
int _E118_79()
{
  return atexit(_E119_87);
}

//----- (0070D440) --------------------------------------------------------  // acclient.c:800125
int _E121_73()
{
  return atexit(nullsub_1474);
}

//----- (0070D450) --------------------------------------------------------  // acclient.c:800131
int _E124_71()
{
  return atexit(_E125_68);
}

//----- (0070D460) --------------------------------------------------------  // acclient.c:800137
int _E127_60()
{
  return atexit(_E128_66);
}

//----- (0070D470) --------------------------------------------------------  // acclient.c:800143
int _E130_54()
{
  return atexit(_E131_55);
}

//----- (0070D480) --------------------------------------------------------  // acclient.c:800149
int _E133_46()
{
  return atexit(_E134_39);
}

//----- (0070D490) --------------------------------------------------------  // acclient.c:800155
int _E136_32()
{
  return atexit(_E137_39);
}

//----- (0070D4A0) --------------------------------------------------------  // acclient.c:800161
int _E139_32()
{
  return atexit(_E140_33);
}

//----- (0070D4B0) --------------------------------------------------------  // acclient.c:800167
int _E142_29()
{
  return atexit(_E143_33);
}

//----- (0070D4C0) --------------------------------------------------------  // acclient.c:800173
int _E145_31()
{
  return atexit(_E146_33);
}

//----- (0070D4D0) --------------------------------------------------------  // acclient.c:800179
int _E148_30()
{
  return atexit(_E149_32);
}

//----- (0070D4E0) --------------------------------------------------------  // acclient.c:800185
int _E151_28()
{
  return atexit(_E152_33);
}

//----- (0070D4F0) --------------------------------------------------------  // acclient.c:800191
int _E154_29()
{
  return atexit(_E155_29);
}

//----- (0070D500) --------------------------------------------------------  // acclient.c:800197
int _E157_26()
{
  return atexit(_E158_30);
}

//----- (0070D510) --------------------------------------------------------  // acclient.c:800203
int _E160_29()
{
  return atexit(_E161_27);
}

//----- (0070D520) --------------------------------------------------------  // acclient.c:800209
int _E163_22()
{
  return atexit(_E164_29);
}

//----- (0070D530) --------------------------------------------------------  // acclient.c:800215
int _E166_24()
{
  return atexit(_E167_25);
}

//----- (0070D540) --------------------------------------------------------  // acclient.c:800221
int _E169_22()
{
  return atexit(_E170_25);
}

//----- (0070D550) --------------------------------------------------------  // acclient.c:800227
int _E172_20()
{
  return atexit(_E173_20);
}

//----- (0070D560) --------------------------------------------------------  // acclient.c:800233
int _E175_17()
{
  return atexit(_E176_22);
}

//----- (0070D570) --------------------------------------------------------  // acclient.c:800239
int _E178_17()
{
  UNDEAD_MALE_CLOTHING_DEFAULT_0.id = UNDEAD_MALE_UNDEAD_SETUP_0.id;
  return atexit(_E179_21);
}

//----- (0070D590) --------------------------------------------------------  // acclient.c:800246
int _E181_17()
{
  UNDEAD_FEMALE_CLOTHING_DEFAULT_0.id = UNDEAD_FEMALE_UNDEAD_SETUP_0.id;
  return atexit(_E182_21);
}

//----- (0070D5B0) --------------------------------------------------------  // acclient.c:800253
int _E184_15()
{
  UMBRAEN_MALE_CLOTHING_DEFAULT_0.id = UMBRAEN_MALE_CROWN_SETUP_0.id;
  return atexit(_E185_18);
}

//----- (0070D5D0) --------------------------------------------------------  // acclient.c:800260
int _E187_14()
{
  UMBRAEN_FEMALE_CLOTHING_DEFAULT_0.id = UMBRAEN_FEMALE_CROWN_SETUP_0.id;
  return atexit(_E188_19);
}

//----- (0070D5F0) --------------------------------------------------------  // acclient.c:800267
int _E190_15()
{
  PENUMBRAEN_MALE_CLOTHING_DEFAULT_0.id = PENUMBRAEN_MALE_CROWN_SETUP_0.id;
  return atexit(_E191_18);
}

//----- (0070D610) --------------------------------------------------------  // acclient.c:800274
int _E193_14()
{
  PENUMBRAEN_FEMALE_CLOTHING_DEFAULT_0.id = PENUMBRAEN_FEMALE_CROWN_SETUP_0.id;
  return atexit(_E194_25);
}

//----- (0070D630) --------------------------------------------------------  // acclient.c:800281
int _E196_21()
{
  return atexit(_E197_15);
}

//----- (0070D640) --------------------------------------------------------  // acclient.c:800287
int _E199_13()
{
  return atexit(_E200_19);
}

//----- (0070D650) --------------------------------------------------------  // acclient.c:800293
int _E202_17()
{
  return atexit(_E203_18);
}

//----- (0070D660) --------------------------------------------------------  // acclient.c:800299
int _E205_14()
{
  return atexit(_E206_21);
}

//----- (0070D670) --------------------------------------------------------  // acclient.c:800305
int _E208_19()
{
  return atexit(_E209_16);
}

//----- (0070D680) --------------------------------------------------------  // acclient.c:800311
int _E211_14()
{
  return atexit(_E212_19);
}

//----- (0070D690) --------------------------------------------------------  // acclient.c:800317
int _E214_16()
{
  return atexit(_E215_16);
}

//----- (0070D6A0) --------------------------------------------------------  // acclient.c:800323
int _E217_13()
{
  return atexit(_E218_16);
}

//----- (0070D6B0) --------------------------------------------------------  // acclient.c:800329
int _E220_13()
{
  return atexit(_E221_16);
}

//----- (0070D6C0) --------------------------------------------------------  // acclient.c:800335
int _E223_14()
{
  return atexit(_E224_16);
}

//----- (0070D6D0) --------------------------------------------------------  // acclient.c:800341
int _E226_13()
{
  return atexit(_E227_16);
}

//----- (0070D6E0) --------------------------------------------------------  // acclient.c:800347
int _E229_14()
{
  return atexit(_E230_17);
}

//----- (0070D6F0) --------------------------------------------------------  // acclient.c:800353
int _E232_14()
{
  return atexit(_E233_16);
}

//----- (0070D700) --------------------------------------------------------  // acclient.c:800359
int _E235_14()
{
  return atexit(_E236_15);
}

//----- (0070D710) --------------------------------------------------------  // acclient.c:800365
int _E238_12()
{
  return atexit(_E239_15);
}

//----- (0070D720) --------------------------------------------------------  // acclient.c:800371
int _E241_12()
{
  return atexit(_E242_15);
}

//----- (0070D730) --------------------------------------------------------  // acclient.c:800377
int _E244_12()
{
  return atexit(_E245_14);
}

//----- (0070D740) --------------------------------------------------------  // acclient.c:800383
int _E247_11()
{
  return atexit(_E248_14);
}

//----- (0070D750) --------------------------------------------------------  // acclient.c:800389
int _E250_11()
{
  return atexit(_E251_13);
}

//----- (0070D760) --------------------------------------------------------  // acclient.c:800395
int _E253_11()
{
  return atexit(_E254_14);
}

//----- (0070D770) --------------------------------------------------------  // acclient.c:800401
int _E256_11()
{
  return atexit(_E257_12);
}

//----- (0070D780) --------------------------------------------------------  // acclient.c:800407
int _E259_12()
{
  return atexit(_E260_13);
}

//----- (0070D790) --------------------------------------------------------  // acclient.c:800413
int _E262_12()
{
  return atexit(_E263_12);
}

//----- (0070D7A0) --------------------------------------------------------  // acclient.c:800419
int _E265_12()
{
  return atexit(_E266_12);
}

//----- (0070D7B0) --------------------------------------------------------  // acclient.c:800425
int _E268_11()
{
  return atexit(_E269_11);
}

//----- (0070D7C0) --------------------------------------------------------  // acclient.c:800431
int _E271_10()
{
  return atexit(_E272_10);
}

//----- (0070D7D0) --------------------------------------------------------  // acclient.c:800437
int _E274_10()
{
  return atexit(_E275_10);
}

//----- (0070D7E0) --------------------------------------------------------  // acclient.c:800443
int _E277_10()
{
  return atexit(_E278_10);
}

//----- (0070D7F0) --------------------------------------------------------  // acclient.c:800449
int _E280_9()
{
  return atexit(_E281_10);
}

//----- (0070D800) --------------------------------------------------------  // acclient.c:800455
int _E283_9()
{
  return atexit(_E284_8);
}

//----- (0070D810) --------------------------------------------------------  // acclient.c:800461
int _E286_8()
{
  return atexit(_E287_9);
}

//----- (0070D820) --------------------------------------------------------  // acclient.c:800467
int sub_70D820()
{
  return atexit(nullsub_1479);
}

