/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCharGenData
   Object     : AC\accharacter\ACCharGenData.obj
   Functions  : 195
   Addresses  : 004169B0 - 0070F4D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004169B0) --------------------------------------------------------  // acclient.c:83247
IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this, IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *result)
{
  HashTableData<unsigned long,HeritageGroup_CG> **v2; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // eax@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edx@5

  v2 = &this->m_buckets[this->m_numBuckets];
  if ( this->m_firstInterestingBucket == v2 )
  {
LABEL_4:
    v5 = result;
    result->m_currBucket = 0;
    result->m_currElement = 0;
    result->m_currHashTable = this;
  }
  else
  {
    while ( 1 )
    {
      v3 = this->m_firstInterestingBucket;
      if ( *v3 )
        break;
      v4 = v3 + 1;
      this->m_firstInterestingBucket = v4;
      if ( v4 == v2 )
        goto LABEL_4;
    }
    v6 = this->m_firstInterestingBucket;
    v5 = result;
    result->m_currElement = *v6;
    result->m_currBucket = v6;
    result->m_currHashTable = this;
  }
  return v5;
}

//----- (00428490) --------------------------------------------------------  // acclient.c:100629
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this, unsigned int _numBuckets)
{
  unsigned int *v2; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // edi@1
  unsigned int *v4; // eax@1

  v2 = g_bucketSizesEnd;
  v3 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)this;
  v4 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v2 )
    --v4;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(v3, *v4);
}

//----- (0042A8C0) --------------------------------------------------------  // acclient.c:103480
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // esi@1
  char result; // al@2
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // ebx@3
  int v5; // ecx@4
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // eax@5
  int v7; // eax@6
  HashTableData<unsigned long,HeritageGroup_CG> **v8; // edi@7
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // ecx@7
  HashTableData<unsigned long,HeritageGroup_CG> *v10; // eax@9
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edx@10
  HashTableData<unsigned long,HeritageGroup_CG> *v12; // ecx@17
  HashTableData<unsigned long,HeritageGroup_CG> *v13; // edi@18
  int v14; // eax@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<unsigned long,HeritageGroup_CG> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<unsigned long,HeritageGroup_CG> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_24;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_24:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<unsigned long,HeritageGroup_CG> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      v2,
      _numBuckets);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        v14 = (int)&v2->m_buckets[v12->m_hashKey % v2->m_numBuckets];
        v12->m_hashNext = *(HashTableData<unsigned long,HeritageGroup_CG> **)v14;
        *(_DWORD *)v14 = v12;
        if ( (HashTableData<unsigned long,HeritageGroup_CG> **)v14 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<unsigned long,HeritageGroup_CG> **)v14;
        ++v2->m_numElements;
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0044E200) --------------------------------------------------------  // acclient.c:139356
SmartArray<QuickButton *,1> *__thiscall SmartArray<int,1>::operator=(SmartArray<QuickButton *,1> *this, int a2)
{
  SmartArray<QuickButton *,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  QuickButton **v5; // ecx@3
  unsigned int i; // eax@5

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<int,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 4 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        *v5 = *(QuickButton **)v3;
        v3 += 4;
        ++v5;
      }
      while ( v3 < v4 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
      v2->m_data[i] = 0;
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (004E6920) --------------------------------------------------------  // acclient.c:276486
signed int gmUIElement_EffectsIndicator::GetUIElementType()
{
  return 268435458;
}

//----- (00585EE0) --------------------------------------------------------  // acclient.c:430871
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // esi@1
  char *v3; // eax@2
  unsigned int v4; // ecx@4

  v2 = this;
  this->m_numBuckets = _numBuckets;
  if ( _numBuckets > 0x17 )
    v3 = (char *)operator new[](4 * _numBuckets);
  else
    v3 = (char *)this->m_aInplaceBuckets;
  v4 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,HeritageGroup_CG> **)&v3[v4];
  v2->m_buckets = (HashTableData<unsigned long,HeritageGroup_CG> **)v3;
  memset(v3, 0, v4);
}

//----- (005BD3F0) --------------------------------------------------------  // acclient.c:488507
CharGenData *__thiscall CharGenData::vector_deleting_destructor(CharGenData *this, unsigned int a2)
{
  CharGenData *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CharGenData::vftable;
  DBObj::~DBObj((DBObj *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E7648: using guessed type __int32 (__stdcall *CharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005BD420) --------------------------------------------------------  // acclient.c:488521
void __thiscall Skill_CG::Skill_CG(Skill_CG *this)
{
  this->vfptr = (Skill_CGVtbl *)&Skill_CG::vftable;
  this->skillNum = 0;
  this->normalCost = 0;
  this->primaryCost = 0;
}
// 79FA7C: using guessed type void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *);

//----- (005BD440) --------------------------------------------------------  // acclient.c:488531
void __cdecl SB_AsPackObj<1>::Serialize(FaceStrip_CG *const *__formal, ObjDesc *i_obj, Archive *io_archive)
{
  void *v3; // ecx@0
  Archive *v4; // esi@1
  PackObjVtbl *v5; // edx@2
  unsigned int v6; // ebx@2
  unsigned int v7; // edi@4
  unsigned int v8; // eax@4
  unsigned int v9; // eax@4
  PackObjVtbl *v10; // edx@4
  unsigned int v11; // ebx@4
  void *pCurrent; // [sp+8h] [bp-4h]@1

  pCurrent = v3;
  v4 = io_archive;
  LOBYTE(io_archive) = Archive::IsWordAligned(io_archive);
  Archive::SetWordAligned(v4, 1);
  Archive::CheckAlignment(v4, 4u);
  Archive::SetWordAligned(v4, (bool)io_archive);
  if ( v4->m_flags & 1 )
  {
    v5 = i_obj->vfptr;
    io_archive = 0;
    v6 = ((int (__thiscall *)(ObjDesc *, Archive **, _DWORD))v5->Pack)(i_obj, &io_archive, 0);
    pCurrent = (void *)Archive::GetBytes(v4, v6);
    if ( pCurrent )
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))i_obj->vfptr->Pack)(i_obj, &pCurrent, v6);
  }
  else
  {
    v7 = Archive::GetSizeLeft(v4);
    v8 = Archive::GetSizeUsed(v4);
    v9 = Archive::PeekBytes(v4, v8, v7);
    v10 = i_obj->vfptr;
    v11 = v9;
    io_archive = (Archive *)v9;
    if ( ((int (__stdcall *)(Archive **, unsigned int))v10->UnPack)(&io_archive, v7) )
      Archive::GetBytes(v4, (unsigned int)((char *)io_archive - v11));
    else
      Archive::RaiseError(v4);
  }
}

//----- (005BD510) --------------------------------------------------------  // acclient.c:488575
int __thiscall EyesStrip_CG::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  ObjDesc::operator=((ObjDesc *)(this + 12), (ObjDesc *)(a2 + 12));
  ObjDesc::operator=((ObjDesc *)(v2 + 56), (ObjDesc *)(a2 + 56));
  return v2;
}

//----- (005BD550) --------------------------------------------------------  // acclient.c:488588
void __thiscall SmartArray<Skill_CG,1>::Reset(SmartArray<Skill_CG,1> *this)
{
  SmartArray<Skill_CG,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  Skill_CG *v4; // edx@2
  int v5; // ecx@3
  int v6; // eax@3
  int v7; // ecx@3
  int v8; // ecx@4
  int v9; // eax@9
  int v10; // ecx@10
  int v11; // edx@10
  int v12; // eax@11

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = v4[-1].primaryCost;
      v6 = (int)&v4[v5];
      v7 = v5 - 1;
      if ( v7 >= 0 )
      {
        v8 = v7 + 1;
        do
        {
          v6 -= 16;
          --v8;
          *(_DWORD *)v6 = &Skill_CG::vftable;
        }
        while ( v8 );
      }
      operator delete[](&v4[-1].primaryCost);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v9 = (v2 & 0x7FFFFFFF) - 1;
    if ( v9 >= 0 )
    {
      v10 = v9;
      v11 = v9 + 1;
      do
      {
        v12 = (int)&v1->m_data[v10];
        --v10;
        --v11;
        *(_DWORD *)(v12 + 4) = 0;
        *(_DWORD *)(v12 + 8) = 0;
        *(_DWORD *)(v12 + 12) = 0;
      }
      while ( v11 );
    }
  }
}
// 79FA7C: using guessed type void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *);

//----- (005BD5D0) --------------------------------------------------------  // acclient.c:488654
void __cdecl ACCharGenData::FormatName(char *_name)
{
  signed int v1; // ebp@1
  unsigned int i; // eax@1
  unsigned int v3; // eax@4
  bool v4; // cf@4
  bool v5; // zf@4
  int *v6; // eax@4
  char v7; // cl@6
  int v8; // ebx@6
  char v9; // al@7
  char v10; // dl@8
  signed int v11; // edi@10
  int v12; // ebx@61
  char v13; // al@63
  const char *v14; // esi@68
  signed int v15; // edx@89
  signed int v16; // ecx@89
  int v17; // esi@89
  signed int j; // edi@89
  char v19; // al@90
  int k; // ecx@108
  CharCase v21; // edx@109
  char v22; // al@110
  char v23; // al@114
  const char *v24; // [sp-8h] [bp-A8h]@71
  int cur; // [sp+10h] [bp-90h]@1
  int length; // [sp+14h] [bp-8Ch]@4
  unsigned int v27; // [sp+18h] [bp-88h]@4
  CharCase cases[33]; // [sp+1Ch] [bp-84h]@59

  v1 = 0;
  cur = 0;
  for ( i = strlen(_name) - 1; (i & 0x80000000) == 0; _name[i + 1] = 0 )
  {
    if ( _name[i] != 32 )
      break;
    --i;
  }
  length = 32;
  v3 = strlen(_name);
  v27 = v3;
  v4 = v3 < 0x20;
  v5 = v3 == 32;
  v6 = &length;
  if ( v4 || v5 )
    v6 = (int *)&v27;
  v7 = 0;
  v8 = 0;
  length = *v6;
  if ( length > 0 )
  {
    while ( 1 )
    {
      v9 = v7;
      v7 = _name[v8];
      if ( v8 >= length - 1 )
        v10 = 0;
      else
        v10 = _name[v8 + 1];
      v11 = 1;
      if ( v7 >= 97 && v7 <= 122 || v7 >= 65 && v7 <= 90 || v7 == 39 )
        goto LABEL_18;
      if ( v7 != 32 )
        break;
LABEL_19:
      if ( v9 == 32 || !v9 )
        v11 = 0;
      if ( !v10 )
        v11 = 0;
LABEL_24:
      if ( v7 == 39 )
      {
        if ( v9 == 39 )
        {
          v11 = 0;
        }
        else if ( v9 )
        {
          if ( v9 >= 97 && v9 <= 122 || v9 >= 65 && v9 <= 90 || (unsigned __int8)v9 >= 0x80u )
            goto LABEL_55;
        }
        else
        {
          v11 = 0;
        }
        if ( v10 >= 97 && v10 <= 122 || v10 >= 65 && v10 <= 90 || (unsigned __int8)v10 >= 0x80u )
          goto LABEL_55;
      }
      else
      {
        if ( v7 != 45 )
          goto LABEL_55;
        if ( v9 == 45 )
        {
          v11 = 0;
        }
        else if ( !v9 || (v9 < 97 || v9 > 122) && (v9 < 65 || v9 > 90) && (unsigned __int8)v9 < 0x80u )
        {
          goto LABEL_57;
        }
        if ( v10 >= 97 && v10 <= 122 || v10 >= 65 && v10 <= 90 || (unsigned __int8)v10 >= 0x80u || v10 == 45 )
        {
LABEL_55:
          if ( v11 )
            _name[v1++] = v7;
          goto LABEL_57;
        }
      }
LABEL_57:
      ++v8;
      if ( v8 >= length )
      {
        cur = v1;
        goto LABEL_59;
      }
    }
    if ( v7 != 45 )
      v11 = 0;
LABEL_18:
    if ( v7 != 32 )
      goto LABEL_24;
    goto LABEL_19;
  }
LABEL_59:
  _name[v1] = 0;
  cases[0] = 0;
  if ( v1 > 1 )
    memset32(&cases[1], 1, v1 - 1);
  v12 = -1;
  if ( v1 - 1 > -1 )
  {
    while ( 1 )
    {
      if ( v12 == -1 )
        goto LABEL_68;
      v13 = _name[v12];
      if ( v13 == 45 || v13 == 39 || v13 == 32 )
        break;
LABEL_88:
      ++v12;
      if ( v12 >= cur - 1 )
        goto LABEL_89;
    }
    if ( v12 > -1 )
      cases[v12 + 1] = 2;
LABEL_68:
    v14 = &_name[v12 + 1];
    switch ( *v14 )
    {
      case 77:
      case 109:
        if ( !__strnicmp(&_name[v12 + 1], "Mac", 3u) )
          cases[v12 + 4] = 2;
        v24 = "Mc";
        goto LABEL_86;
      case 70:
      case 102:
        if ( !__strnicmp(&_name[v12 + 1], "Fitz", 4u) )
          cases[v12 + 5] = 2;
        goto LABEL_88;
      case 86:
      case 118:
        if ( !__strnicmp(&_name[v12 + 1], "Von", 3u) )
          cases[v12 + 4] = 2;
        if ( !__strnicmp(v14, "Van", 3u) )
          cases[v12 + 4] = 2;
        goto LABEL_88;
      case 68:
      case 100:
        if ( !__strnicmp(&_name[v12 + 1], "De", 2u) )
          cases[v12 + 3] = 2;
        if ( !__strnicmp(v14, "Di", 2u) )
          cases[v12 + 3] = 2;
        v24 = "Du";
        goto LABEL_86;
      case 76:
      case 108:
        if ( !__strnicmp(&_name[v12 + 1], "Le", 2u) )
          cases[v12 + 3] = 2;
        v24 = "La";
LABEL_86:
        if ( !__strnicmp(v14, v24, 2u) )
          cases[v12 + 3] = 2;
        break;
      default:
        goto LABEL_88;
    }
    goto LABEL_88;
  }
LABEL_89:
  v15 = -1;
  v16 = -1;
  v17 = 0;
  for ( j = 1; v17 < cur; ++v17 )
  {
    v19 = _name[v17];
    if ( v19 >= 97 && v19 <= 122 || v19 >= 65 && v19 <= 90 || (unsigned __int8)v19 >= 0x80u )
    {
      if ( v15 == -1 )
        v15 = v17;
      v16 = v17;
      if ( v19 != 73 && v19 != 86 && v19 != 88 )
        j = 0;
      if ( v17 != cur - 1 )
        continue;
    }
    if ( v15 != -1 && j && v15 <= v16 )
      memset(&cases[v15], 0, 4 * (v16 - v15 + 1));
    v16 = -1;
    j = 1;
    v15 = -1;
  }
  for ( k = 0; k < cur; ++k )
  {
    v21 = cases[k];
    if ( v21 == 1 )
    {
      v22 = _name[k];
      if ( v22 >= 65 && v22 <= 90 )
        _name[k] = v22 + 32;
    }
    if ( v21 == CASE_UPPER )
    {
      v23 = _name[k];
      if ( v23 >= 97 && v23 <= 122 )
        _name[k] = v23 - 32;
    }
  }
}

//----- (005BD9C0) --------------------------------------------------------  // acclient.c:488886
void __thiscall Skill_CG::Serialize(Skill_CG *this, Archive *io_archive)
{
  Skill_CG *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->skillNum;
    else
      v2->skillNum = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->normalCost;
    else
      v2->normalCost = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->primaryCost;
    else
      v2->primaryCost = *(_DWORD *)v5;
  }
}

//----- (005BDA50) --------------------------------------------------------  // acclient.c:488924
void __thiscall HairStyle_CG::HairStyle_CG(HairStyle_CG *this)
{
  this->vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
  this->iconImage.id = stru_8EF864.id;
  this->bald = 0;
  this->alternateSetup.id = stru_8EF864.id;
  ObjDesc::ObjDesc(&this->objDesc);
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005BDA80) --------------------------------------------------------  // acclient.c:488935
void __thiscall HairStyle_CG::Serialize(HairStyle_CG *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  HairStyle_CG *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v4;
  }
  Serializer::SerializeObject(&v3->bald, v2);
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->alternateSetup.id;
    else
      v3->alternateSetup.id = *(_DWORD *)v5;
  }
  SB_AsPackObj<1>::Serialize((FaceStrip_CG *const *)&io_archive, &v3->objDesc, v2);
}

//----- (005BDB00) --------------------------------------------------------  // acclient.c:488967
void __thiscall EyesStrip_CG::EyesStrip_CG(EyesStrip_CG *this)
{
  EyesStrip_CG *v1; // esi@1

  v1 = this;
  this->vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
  this->iconImage.id = stru_8EF864.id;
  this->iconImage_Bald.id = stru_8EF864.id;
  ObjDesc::ObjDesc(&this->objDesc);
  ObjDesc::ObjDesc(&v1->objDesc_Bald);
}
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);

//----- (005BDB30) --------------------------------------------------------  // acclient.c:488981
void __thiscall EyesStrip_CG::Serialize(EyesStrip_CG *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  EyesStrip_CG *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->iconImage_Bald.id;
    else
      v3->iconImage_Bald.id = *(_DWORD *)v5;
  }
  SB_AsPackObj<1>::Serialize((FaceStrip_CG *const *)&io_archive, &v3->objDesc, v2);
  SB_AsPackObj<1>::Serialize((FaceStrip_CG *const *)&io_archive, &v3->objDesc_Bald, v2);
}

//----- (005BDBB0) --------------------------------------------------------  // acclient.c:489013
void __thiscall FaceStrip_CG::FaceStrip_CG(FaceStrip_CG *this)
{
  this->vfptr = (FaceStrip_CGVtbl *)&FaceStrip_CG::vftable;
  this->iconImage.id = stru_8EF864.id;
  ObjDesc::ObjDesc(&this->objDesc);
}
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);

//----- (005BDBD0) --------------------------------------------------------  // acclient.c:489022
void __thiscall FaceStrip_CG::Serialize(FaceStrip_CG *this, Archive *io_archive)
{
  Archive *v2; // edi@1
  FaceStrip_CG *v3; // esi@1
  unsigned int v4; // eax@1

  v2 = io_archive;
  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v4;
  }
  SB_AsPackObj<1>::Serialize((FaceStrip_CG *const *)&io_archive, &v3->objDesc, v2);
}

//----- (005BDC20) --------------------------------------------------------  // acclient.c:489043
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E76D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable)(void *, char);

//----- (005BDC60) --------------------------------------------------------  // acclient.c:489064
int __thiscall Style_CG::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  return v2;
}

//----- (005BDCC0) --------------------------------------------------------  // acclient.c:489088
char __thiscall SmartArray<Position,1>::shrink(SmartArray<Position,1> *this)
{
  SmartArray<Position,1> *v1; // edi@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // ebx@5
  int v6; // eax@6
  int v7; // esi@7
  int v8; // ebx@7
  unsigned int v9; // ebp@7
  int v10; // eax@8
  Position *v11; // ecx@13
  unsigned int v12; // edx@17
  Position *new_data; // [sp+0h] [bp-4h]@5

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](72 * v2 + 4);
    if ( !v4 )
      return 0;
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = v2;
    vector_constructor_iterator((char *)v4 + 4, 0x48u, v2, (void *(__thiscall *)(void *))Position::Position);
    new_data = (Position *)v5;
    if ( !v5 )
      return 0;
    v6 = v1->m_num - 1;
    if ( v6 >= 0 )
    {
      v7 = v5 + 72 * v6 + 8;
      v8 = -8 - v5;
      v9 = v1->m_num;
      do
      {
        v10 = (int)((char *)v1->m_data + v8 + v7);
        *(_DWORD *)(v7 - 4) = *(_DWORD *)(v10 + 4);
        Frame::operator=(v7, v10 + 8);
        v7 -= 72;
        --v9;
      }
      while ( v9 );
    }
  }
  else
  {
    new_data = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v11 = v1->m_data;
    if ( v1->m_data )
    {
      if ( LODWORD(v11[-1].frame.m_fOrigin.z) )
        ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(3);
      else
        operator delete[](&v11[-1].frame.m_fOrigin.z);
    }
  }
  v12 = v1->m_num | 0x80000000;
  v1->m_data = new_data;
  v1->m_sizeAndDeallocate = v12;
  return 1;
}

//----- (005BDDB0) --------------------------------------------------------  // acclient.c:489157
char __thiscall SmartArray<Skill_CG,1>::grow(SmartArray<Skill_CG,1> *this, unsigned int i_nSize)
{
  SmartArray<Skill_CG,1> *v2; // esi@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // ecx@9
  unsigned int v9; // edi@9
  int v10; // eax@10
  Skill_CG *v11; // edx@13
  int v12; // eax@14
  int v13; // ecx@14
  int v14; // ecx@15

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Skill_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator((char *)v5 + 4, 0x10u, i_nSize, (void *(__thiscall *)(void *))Skill_CG::Skill_CG);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = 16 * v7 + v6 + 8;
            v9 = v2->m_num;
            do
            {
              v10 = (int)((char *)v2->m_data + -8 - v6 + v8);
              *(_DWORD *)(v8 - 4) = *(_DWORD *)(v10 + 4);
              *(_DWORD *)v8 = *(_DWORD *)(v10 + 8);
              *(_DWORD *)(v8 + 4) = *(_DWORD *)(v10 + 12);
              v8 -= 16;
              --v9;
            }
            while ( v9 );
            v3 = i_nSize;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v11 = v2->m_data;
            if ( v2->m_data )
            {
              v12 = (int)&v11[v11[-1].primaryCost];
              v13 = v11[-1].primaryCost - 1;
              if ( v13 >= 0 )
              {
                v14 = v11[-1].primaryCost;
                do
                {
                  v12 -= 16;
                  --v14;
                  *(_DWORD *)v12 = &Skill_CG::vftable;
                }
                while ( v14 );
              }
              operator delete[](&v11[-1].primaryCost);
            }
          }
        }
        v2->m_data = (Skill_CG *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}
// 79FA7C: using guessed type void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *);

//----- (005BDEC0) --------------------------------------------------------  // acclient.c:489243
char __thiscall SmartArray<Skill_CG,1>::shrink(SmartArray<Skill_CG,1> *this)
{
  SmartArray<Skill_CG,1> *v1; // ebx@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // edi@5
  int v6; // eax@6
  int v7; // ecx@7
  unsigned int v8; // esi@7
  int v9; // eax@8
  Skill_CG *v10; // edx@13
  int v11; // eax@14
  int v12; // ecx@15
  unsigned int v13; // edx@18

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](16 * v2 + 4);
    if ( !v4 )
      return 0;
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = v2;
    vector_constructor_iterator((char *)v4 + 4, 0x10u, v2, (void *(__thiscall *)(void *))Skill_CG::Skill_CG);
    if ( !v5 )
      return 0;
    v6 = v1->m_num - 1;
    if ( v6 >= 0 )
    {
      v7 = 16 * v6 + v5 + 8;
      v8 = v1->m_num;
      do
      {
        v9 = (int)((char *)v1->m_data + -8 - v5 + v7);
        *(_DWORD *)(v7 - 4) = *(_DWORD *)(v9 + 4);
        *(_DWORD *)v7 = *(_DWORD *)(v9 + 8);
        *(_DWORD *)(v7 + 4) = *(_DWORD *)(v9 + 12);
        v7 -= 16;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v10 = v1->m_data;
    if ( v1->m_data )
    {
      v11 = (int)&v10[v10[-1].primaryCost];
      if ( v10[-1].primaryCost - 1 >= 0 )
      {
        v12 = v10[-1].primaryCost;
        do
        {
          v11 -= 16;
          --v12;
          *(_DWORD *)v11 = &Skill_CG::vftable;
        }
        while ( v12 );
      }
      operator delete[](&v10[-1].primaryCost);
    }
  }
  v13 = v1->m_num;
  v1->m_data = (Skill_CG *)v5;
  v1->m_sizeAndDeallocate = v13 | 0x80000000;
  return 1;
}
// 79FA7C: using guessed type void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *);

//----- (005BDFA0) --------------------------------------------------------  // acclient.c:489321
char __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::shrink(SmartArray<IDClass<_tagDataID,32,0>,1> *this)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v1; // esi@1
  int v2; // edi@1
  void *v3; // eax@3
  int v4; // ebx@4
  int v5; // edi@4
  int i; // eax@5
  unsigned int v8; // eax@13

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v3 = operator new[](4 * v2 + 4);
    if ( v3 )
    {
      v4 = (int)((char *)v3 + 4);
      *(_DWORD *)v3 = v2;
      vector_constructor_iterator(
        (char *)v3 + 4,
        4u,
        v2,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      v5 = v4;
      if ( v4 )
      {
        for ( i = v1->m_num - 1; i >= 0; *(_DWORD *)(v4 + 4 * i + 4) = v1->m_data[i + 1].id )
          --i;
        goto LABEL_10;
      }
    }
    return 0;
  }
  v5 = 0;
LABEL_10:
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v1->m_data )
      operator delete[](&v1->m_data[-1]);
  }
  v8 = v1->m_num;
  v1->m_data = (IDClass<_tagDataID,32,0> *)v5;
  v1->m_sizeAndDeallocate = v8 | 0x80000000;
  return 1;
}

//----- (005BE040) --------------------------------------------------------  // acclient.c:489371
char __thiscall SmartArray<HairStyle_CG,1>::shrink(SmartArray<HairStyle_CG,1> *this)
{
  SmartArray<HairStyle_CG,1> *v1; // ebp@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // edi@5
  HairStyle_CG *v6; // eax@5
  int v7; // ebx@6
  int v8; // edi@7
  int v9; // esi@7
  unsigned int v10; // ebx@7
  int v11; // eax@8
  HairStyle_CG *v12; // ecx@14
  void *v13; // ebx@15
  int v14; // esi@15
  int v15; // edi@16
  HairStyle_CG *new_data; // [sp+8h] [bp-4h]@5

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( !v2 )
  {
    new_data = 0;
LABEL_12:
    v6 = new_data;
    goto LABEL_13;
  }
  v4 = operator new[](60 * v2 + 4);
  if ( !v4 )
    return 0;
  v5 = (int)((char *)v4 + 4);
  *(_DWORD *)v4 = v2;
  vector_constructor_iterator((char *)v4 + 4, 0x3Cu, v2, (void *(__thiscall *)(void *))HairStyle_CG::HairStyle_CG);
  v6 = (HairStyle_CG *)v5;
  new_data = (HairStyle_CG *)v5;
  if ( !v5 )
    return 0;
  v7 = v1->m_num - 1;
  if ( v7 >= 0 )
  {
    v8 = -8 - v5;
    v9 = (int)&v6[v7].bald;
    v10 = v1->m_num;
    do
    {
      v11 = (int)((char *)v1->m_data + v8 + v9);
      *(_DWORD *)(v9 - 4) = *(_DWORD *)(v11 + 4);
      *(_BYTE *)v9 = *(_BYTE *)(v11 + 8);
      *(_DWORD *)(v9 + 4) = *(_DWORD *)(v11 + 12);
      ObjDesc::operator=((ObjDesc *)(v9 + 8), (ObjDesc *)(v11 + 16));
      v9 -= 60;
      --v10;
    }
    while ( v10 );
    goto LABEL_12;
  }
LABEL_13:
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v12 = v1->m_data;
    if ( v1->m_data )
    {
      v13 = &v12[-1].objDesc.num_anim_part_changes;
      v14 = (int)&v12[v12[-1].objDesc.num_anim_part_changes];
      if ( v12[-1].objDesc.num_anim_part_changes - 1 >= 0 )
      {
        v15 = v12[-1].objDesc.num_anim_part_changes;
        do
        {
          v14 -= 60;
          *(_DWORD *)v14 = &HairStyle_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v14 + 16));
          --v15;
        }
        while ( v15 );
      }
      operator delete[](v13);
      v6 = new_data;
    }
  }
  v1->m_data = v6;
  v1->m_sizeAndDeallocate = v1->m_num | 0x80000000;
  return 1;
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005BE160) --------------------------------------------------------  // acclient.c:489460
char __thiscall SmartArray<EyesStrip_CG,1>::shrink(SmartArray<EyesStrip_CG,1> *this)
{
  SmartArray<EyesStrip_CG,1> *v1; // ebx@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // edi@5
  EyesStrip_CG *v6; // eax@5
  int v7; // ebp@6
  int v8; // ebx@7
  int v9; // edi@7
  int v10; // ebp@7
  int v11; // esi@8
  EyesStrip_CG *v12; // ecx@14
  void *v13; // ebp@15
  int v14; // esi@15
  int v15; // edi@16
  unsigned int v16; // edx@19
  EyesStrip_CG *new_data; // [sp+8h] [bp-8h]@5
  SmartArray<EyesStrip_CG,1> *v18; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->m_num;
  v18 = this;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( !v2 )
  {
    new_data = 0;
LABEL_12:
    v6 = new_data;
    goto LABEL_13;
  }
  v4 = operator new[](100 * v2 + 4);
  if ( !v4 )
    return 0;
  v5 = (int)((char *)v4 + 4);
  *(_DWORD *)v4 = v2;
  vector_constructor_iterator((char *)v4 + 4, 0x64u, v2, (void *(__thiscall *)(void *))EyesStrip_CG::EyesStrip_CG);
  v6 = (EyesStrip_CG *)v5;
  new_data = (EyesStrip_CG *)v5;
  if ( !v5 )
    return 0;
  v7 = v1->m_num - 1;
  if ( v7 >= 0 )
  {
    v8 = -8 - v5;
    v9 = 100 * v7 + v5 + 8;
    v10 = v7 + 1;
    do
    {
      v11 = (int)((char *)v18->m_data + v8 + v9);
      *(_DWORD *)(v9 - 4) = *(_DWORD *)(v11 + 4);
      *(_DWORD *)v9 = *(_DWORD *)(v11 + 8);
      ObjDesc::operator=((ObjDesc *)(v9 + 4), (ObjDesc *)(v11 + 12));
      ObjDesc::operator=((ObjDesc *)(v9 + 48), (ObjDesc *)(v11 + 56));
      v9 -= 100;
      --v10;
    }
    while ( v10 );
    v1 = v18;
    goto LABEL_12;
  }
LABEL_13:
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v12 = v1->m_data;
    if ( v1->m_data )
    {
      v13 = &v12[-1].objDesc_Bald.num_anim_part_changes;
      v14 = (int)&v12[v12[-1].objDesc_Bald.num_anim_part_changes];
      if ( v12[-1].objDesc_Bald.num_anim_part_changes - 1 >= 0 )
      {
        v15 = v12[-1].objDesc_Bald.num_anim_part_changes;
        do
        {
          v14 -= 100;
          *(_DWORD *)v14 = &EyesStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v14 + 56));
          ObjDesc::~ObjDesc((ObjDesc *)(v14 + 12));
          --v15;
        }
        while ( v15 );
      }
      operator delete[](v13);
      v6 = new_data;
    }
  }
  v16 = v1->m_num | 0x80000000;
  v1->m_data = v6;
  v1->m_sizeAndDeallocate = v16;
  return 1;
}
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);

//----- (005BE2A0) --------------------------------------------------------  // acclient.c:489555
char __thiscall SmartArray<FaceStrip_CG,1>::shrink(SmartArray<FaceStrip_CG,1> *this)
{
  SmartArray<FaceStrip_CG,1> *v1; // ebp@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // edi@5
  FaceStrip_CG *v6; // eax@5
  int v7; // ebx@6
  int v8; // edi@7
  ObjDesc *v9; // esi@7
  unsigned int v10; // ebx@7
  int v11; // eax@8
  FaceStrip_CG *v12; // ecx@14
  void *v13; // ebx@15
  int v14; // esi@15
  int v15; // edi@16
  FaceStrip_CG *new_data; // [sp+8h] [bp-4h]@5

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( !v2 )
  {
    new_data = 0;
LABEL_12:
    v6 = new_data;
    goto LABEL_13;
  }
  v4 = operator new[](52 * v2 + 4);
  if ( !v4 )
    return 0;
  v5 = (int)((char *)v4 + 4);
  *(_DWORD *)v4 = v2;
  vector_constructor_iterator((char *)v4 + 4, 0x34u, v2, (void *(__thiscall *)(void *))FaceStrip_CG::FaceStrip_CG);
  v6 = (FaceStrip_CG *)v5;
  new_data = (FaceStrip_CG *)v5;
  if ( !v5 )
    return 0;
  v7 = v1->m_num - 1;
  if ( v7 >= 0 )
  {
    v8 = -8 - v5;
    v9 = &v6[v7].objDesc;
    v10 = v1->m_num;
    do
    {
      v11 = (int)((char *)v1->m_data + (unsigned int)((char *)v9 + v8));
      v9[-1].num_anim_part_changes = *(_DWORD *)(v11 + 4);
      ObjDesc::operator=(v9, (ObjDesc *)(v11 + 8));
      v9 = (ObjDesc *)((char *)v9 - 52);
      --v10;
    }
    while ( v10 );
    goto LABEL_12;
  }
LABEL_13:
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v12 = v1->m_data;
    if ( v1->m_data )
    {
      v13 = &v12[-1].objDesc.num_anim_part_changes;
      v14 = (int)&v12[v12[-1].objDesc.num_anim_part_changes];
      if ( v12[-1].objDesc.num_anim_part_changes - 1 >= 0 )
      {
        v15 = v12[-1].objDesc.num_anim_part_changes;
        do
        {
          v14 -= 52;
          *(_DWORD *)v14 = &FaceStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v14 + 8));
          --v15;
        }
        while ( v15 );
      }
      operator delete[](v13);
      v6 = new_data;
    }
  }
  v1->m_data = v6;
  v1->m_sizeAndDeallocate = v1->m_num | 0x80000000;
  return 1;
}
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);

//----- (005BE3B0) --------------------------------------------------------  // acclient.c:489642
char __thiscall SmartArray<MediaDesc *,1>::shrink(SmartArray<int,1> *this)
{
  SmartArray<int,1> *v1; // esi@1
  unsigned int v2; // eax@1
  void *v4; // edi@4
  int i; // eax@5
  unsigned int v6; // edx@12

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](4 * v2);
    if ( !v4 )
      return 0;
    for ( i = v1->m_num - 1; i >= 0; *((_DWORD *)v4 + i + 1) = v1->m_data[i + 1] )
      --i;
  }
  else
  {
    v4 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_data);
  v6 = v1->m_num;
  v1->m_data = (int *)v4;
  v1->m_sizeAndDeallocate = v6 | 0x80000000;
  return 1;
}

//----- (005BE430) --------------------------------------------------------  // acclient.c:489675
void __cdecl SB_As32Bit_Compressed::Serialize(const int *_class, unsigned int *_obj, Archive *_arc)
{
  Archive *v3; // esi@1
  char v4; // al@1
  unsigned int v5; // eax@2
  char v6; // bl@3
  unsigned int v7; // eax@3
  char v8; // cl@7
  unsigned int v9; // eax@10
  unsigned __int8 v10; // bl@12
  Archive *v11; // [sp-4h] [bp-14h]@6
  unsigned __int16 mediumBits; // [sp+8h] [bp-8h]@7
  unsigned int lowBits; // [sp+Ch] [bp-4h]@8

  v3 = _arc;
  v4 = LOBYTE(_arc->m_flags);
  if ( v4 & 1 )
  {
    v5 = *_obj;
    if ( *_obj > 0x7F )
    {
      v11 = _arc;
      if ( v5 > 0x3FFF )
      {
        lowBits = *_obj;
        LOBYTE(_arc) = BYTE3(v5) | 0xC0;
        LOBYTE(mediumBits) = v5 >> 16;
        Serializer::SerializeObject((char *)&_arc, v11);
        Serializer::SerializeObject((char *)&mediumBits, v3);
        Serializer::SerializeObject((unsigned __int16 *)&lowBits, v3);
      }
      else
      {
        v8 = *(_BYTE *)_obj;
        LOBYTE(_arc) = *((_BYTE *)_obj + 1) | 0x80;
        LOBYTE(mediumBits) = v8;
        Serializer::SerializeObject((char *)&_arc, v11);
        Serializer::SerializeObject((char *)&mediumBits, v3);
      }
    }
    else
    {
      v6 = *_obj;
      Archive::CheckAlignment(_arc, 1u);
      v7 = Archive::GetBytes(v3, 1u);
      if ( v7 )
      {
        if ( v3->m_flags & 1 )
          *(_BYTE *)v7 = v6;
      }
    }
  }
  else if ( ~v4 & 1 )
  {
    Archive::CheckAlignment(_arc, 1u);
    v9 = Archive::GetBytes(v3, 1u);
    if ( v9 )
    {
      if ( v3->m_flags & 1 )
      {
        v10 = (unsigned __int8)_arc;
        *(_BYTE *)v9 = (_BYTE)_arc;
      }
      else
      {
        v10 = *(_BYTE *)v9;
      }
    }
    else
    {
      v10 = (unsigned __int8)_arc;
    }
    if ( (v10 & 0x80u) == 0 )
    {
      *_obj = v10;
    }
    else
    {
      Serializer::SerializeObject((char *)&_arc, v3);
      if ( v10 & 0x40 )
      {
        Serializer::SerializeObject(&mediumBits, v3);
        *_obj = mediumBits | (((unsigned __int8)_arc | ((v10 & 0x3F) << 8)) << 16);
      }
      else
      {
        *_obj = (unsigned __int8)_arc | ((v10 & 0x7F) << 8);
      }
    }
  }
}

//----- (005BE5A0) --------------------------------------------------------  // acclient.c:489768
int __thiscall Position::vector_deleting_destructor(Position *this, unsigned int a2)
{
  Position *v2; // esi@1
  float v3; // ecx@2
  int v4; // eax@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@3
  int result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].frame.m_fOrigin.z;
    v4 = 9 * LODWORD(v3);
    v5 = LODWORD(v3) - 1;
    v6 = (int)&v2[8 * v4 / 0x48u];
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 72;
        --v7;
        *(_DWORD *)v6 = &PackObj::vftable;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](&v2[-1].frame.m_fOrigin.z);
    result = (int)&v2[-1].frame.m_fOrigin.z;
  }
  else
  {
    this->vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( a2 & 1 )
      operator delete(this);
    result = (int)v2;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005BE600) --------------------------------------------------------  // acclient.c:489812
void __thiscall SmartArray<Position,1>::Reset(SmartArray<Position,1> *this)
{
  SmartArray<Position,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  Position *v4; // ecx@2
  int v5; // eax@8
  int v6; // esi@9
  int v7; // ebx@9
  int v8; // eax@10
  Frame v9; // [sp+10h] [bp-40h]@10

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      if ( LODWORD(v4[-1].frame.m_fOrigin.z) )
      {
        ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(3);
        v1->m_data = 0;
        v1->m_sizeAndDeallocate = 0;
        return;
      }
      operator delete[](&v4[-1].frame.m_fOrigin.z);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v5 = (v2 & 0x7FFFFFFF) - 1;
    if ( v5 >= 0 )
    {
      v6 = v5;
      v7 = v5 + 1;
      do
      {
        LODWORD(v9.qw) = 1065353216;
        LODWORD(v9.qx) = 0;
        LODWORD(v9.qy) = 0;
        LODWORD(v9.qz) = 0;
        LODWORD(v9.m_fOrigin.x) = 0;
        LODWORD(v9.m_fOrigin.y) = 0;
        LODWORD(v9.m_fOrigin.z) = 0;
        Frame::cache(&v9);
        v8 = (int)&v1->m_data[v6];
        *(_DWORD *)(v8 + 4) = 0;
        Frame::operator=(v8 + 8, (int)&v9);
        --v6;
        --v7;
      }
      while ( v7 );
    }
  }
}

//----- (005BE6F0) --------------------------------------------------------  // acclient.c:489874
void __thiscall SmartArray<HairStyle_CG,1>::Reset(SmartArray<HairStyle_CG,1> *this)
{
  SmartArray<HairStyle_CG,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  HairStyle_CG *v4; // ecx@2
  void *v5; // edx@3
  int v6; // esi@3
  int v7; // ebp@4
  int v8; // eax@10
  int v9; // esi@11
  int v10; // ebp@11
  unsigned int v11; // ST18_4@12
  unsigned int v12; // ST20_4@12
  int v13; // eax@12
  int v14; // [sp+Ch] [bp-40h]@3
  ObjDesc rhs; // [sp+20h] [bp-2Ch]@12

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = &v4[-1].objDesc.num_anim_part_changes;
      v6 = (int)&v4[v4[-1].objDesc.num_anim_part_changes];
      v14 = (int)&v4[-1].objDesc.num_anim_part_changes;
      if ( v4[-1].objDesc.num_anim_part_changes - 1 >= 0 )
      {
        v7 = v4[-1].objDesc.num_anim_part_changes;
        do
        {
          v6 -= 60;
          *(_DWORD *)v6 = &HairStyle_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v6 + 16));
          --v7;
        }
        while ( v7 );
        v5 = (void *)v14;
      }
      operator delete[](v5);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v8 = (v2 & 0x7FFFFFFF) - 1;
    if ( v8 >= 0 )
    {
      v9 = v8;
      v10 = v8 + 1;
      do
      {
        v11 = stru_8EF864.id;
        v12 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        v13 = (int)&v1->m_data[v9];
        *(_DWORD *)(v13 + 4) = v11;
        *(_BYTE *)(v13 + 8) = 0;
        *(_DWORD *)(v13 + 12) = v12;
        ObjDesc::operator=((ObjDesc *)(v13 + 16), &rhs);
        ObjDesc::~ObjDesc(&rhs);
        --v9;
        --v10;
      }
      while ( v10 );
    }
  }
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005BE7F0) --------------------------------------------------------  // acclient.c:489950
void __thiscall SmartArray<EyesStrip_CG,1>::Reset(SmartArray<EyesStrip_CG,1> *this)
{
  SmartArray<EyesStrip_CG,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  EyesStrip_CG *v4; // ecx@2
  void *v5; // ebp@3
  int v6; // esi@3
  int v7; // edi@4
  int v8; // eax@9
  int v9; // edi@10
  int v10; // ebp@10
  unsigned int v11; // ST18_4@11
  unsigned int v12; // ST1C_4@11
  int v13; // esi@11
  ObjDesc rhs; // [sp+1Ch] [bp-58h]@11
  ObjDesc v15; // [sp+48h] [bp-2Ch]@11

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = &v4[-1].objDesc_Bald.num_anim_part_changes;
      v6 = (int)&v4[v4[-1].objDesc_Bald.num_anim_part_changes];
      if ( v4[-1].objDesc_Bald.num_anim_part_changes - 1 >= 0 )
      {
        v7 = v4[-1].objDesc_Bald.num_anim_part_changes;
        do
        {
          v6 -= 100;
          *(_DWORD *)v6 = &EyesStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v6 + 56));
          ObjDesc::~ObjDesc((ObjDesc *)(v6 + 12));
          --v7;
        }
        while ( v7 );
      }
      operator delete[](v5);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v8 = (v2 & 0x7FFFFFFF) - 1;
    if ( v8 >= 0 )
    {
      v9 = v8;
      v10 = v8 + 1;
      do
      {
        v11 = stru_8EF864.id;
        v12 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        ObjDesc::ObjDesc(&v15);
        v13 = (int)&v1->m_data[v9];
        *(_DWORD *)(v13 + 4) = v11;
        *(_DWORD *)(v13 + 8) = v12;
        ObjDesc::operator=((ObjDesc *)(v13 + 12), &rhs);
        ObjDesc::operator=((ObjDesc *)(v13 + 56), &v15);
        ObjDesc::~ObjDesc(&v15);
        ObjDesc::~ObjDesc(&rhs);
        --v9;
        --v10;
      }
      while ( v10 );
    }
  }
}
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);

//----- (005BE900) --------------------------------------------------------  // acclient.c:490027
void __thiscall SmartArray<FaceStrip_CG,1>::Reset(SmartArray<FaceStrip_CG,1> *this)
{
  SmartArray<FaceStrip_CG,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  FaceStrip_CG *v4; // ecx@2
  void *v5; // edx@3
  int v6; // esi@3
  int v7; // ebx@4
  int v8; // eax@10
  int v9; // esi@11
  int v10; // ebx@11
  unsigned int v11; // ST18_4@12
  int v12; // eax@12
  int v13; // [sp+Ch] [bp-38h]@3
  ObjDesc rhs; // [sp+18h] [bp-2Ch]@12

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = &v4[-1].objDesc.num_anim_part_changes;
      v6 = (int)&v4[v4[-1].objDesc.num_anim_part_changes];
      v13 = (int)&v4[-1].objDesc.num_anim_part_changes;
      if ( v4[-1].objDesc.num_anim_part_changes - 1 >= 0 )
      {
        v7 = v4[-1].objDesc.num_anim_part_changes;
        do
        {
          v6 -= 52;
          *(_DWORD *)v6 = &FaceStrip_CG::vftable;
          ObjDesc::~ObjDesc((ObjDesc *)(v6 + 8));
          --v7;
        }
        while ( v7 );
        v5 = (void *)v13;
      }
      operator delete[](v5);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v8 = (v2 & 0x7FFFFFFF) - 1;
    if ( v8 >= 0 )
    {
      v9 = v8;
      v10 = v8 + 1;
      do
      {
        v11 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        v12 = (int)&v1->m_data[v9];
        *(_DWORD *)(v12 + 4) = v11;
        ObjDesc::operator=((ObjDesc *)(v12 + 8), &rhs);
        ObjDesc::~ObjDesc(&rhs);
        --v9;
        --v10;
      }
      while ( v10 );
    }
  }
}
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);

//----- (005BE9F0) --------------------------------------------------------  // acclient.c:490099
void __thiscall ACCharGenStartArea::ACCharGenStartArea(ACCharGenStartArea *this)
{
  ACCharGenStartArea *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (ACCharGenStartAreaVtbl *)&ACCharGenStartArea::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->mPositionList.m_data = 0;
  v1->mPositionList.m_sizeAndDeallocate = 0;
  v1->mPositionList.m_num = 0;
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005BEA20) --------------------------------------------------------  // acclient.c:490116
void __thiscall ACCharGenStartArea::~ACCharGenStartArea(ACCharGenStartArea *this)
{
  ACCharGenStartArea *v1; // esi@1
  Position *v2; // ecx@2
  int v3; // esi@6

  v1 = this;
  this->vfptr = (ACCharGenStartAreaVtbl *)&ACCharGenStartArea::vftable;
  if ( (this->mPositionList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v2 = this->mPositionList.m_data;
    if ( v2 )
    {
      if ( LODWORD(v2[-1].frame.m_fOrigin.z) )
        ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      else
        operator delete[](&v2[-1].frame.m_fOrigin.z);
    }
  }
  v3 = (int)&v1->name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005BEA80) --------------------------------------------------------  // acclient.c:490145
void __thiscall Style_CG::Style_CG(Style_CG *this)
{
  Style_CG *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (Style_CGVtbl *)&Style_CG::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->clothingTable.id = stru_8EF864.id;
  v1->weenieDefault.id = stru_8EF864.id;
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005BEAC0) --------------------------------------------------------  // acclient.c:490161
void __thiscall Style_CG::Style_CG(Style_CG *this, Style_CG *_style)
{
  Style_CG *v2; // esi@1
  volatile LONG *v3; // ST04_4@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ebx@2
  PSRefBufferCharData<char> *v6; // edi@5

  v2 = this;
  this->vfptr = (Style_CGVtbl *)&Style_CG::vftable;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v2->clothingTable.id = _style->clothingTable.id;
  v2->weenieDefault.id = _style->weenieDefault.id;
  v4 = v2->name.m_charbuffer;
  if ( v4 != _style->name.m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    v6 = _style->name.m_charbuffer;
    v2->name.m_charbuffer = v6;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
  }
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005BEB30) --------------------------------------------------------  // acclient.c:490193
void __thiscall Template_CG::Template_CG(Template_CG *this)
{
  Template_CG *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  unsigned int v3; // edx@1

  v1 = this;
  this->vfptr = (Template_CGVtbl *)&Template_CG::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = stru_8EF864.id;
  v1->titleID = 0;
  v1->strength = 0;
  v1->endurance = 0;
  v1->coordination = 0;
  v1->quickness = 0;
  v1->focus = 0;
  v1->self = 0;
  v1->iconImage.id = v3;
  v1->mNormalSkillsList.m_data = 0;
  v1->mNormalSkillsList.m_sizeAndDeallocate = 0;
  v1->mNormalSkillsList.m_num = 0;
  v1->mPrimarySkillsList.m_data = 0;
  v1->mPrimarySkillsList.m_sizeAndDeallocate = 0;
  v1->mPrimarySkillsList.m_num = 0;
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (005BEB90) --------------------------------------------------------  // acclient.c:490223
SmartArray<Skill_CG,1> *__thiscall SmartArray<Skill_CG,1>::operator=(SmartArray<Skill_CG,1> *this, int a2)
{
  SmartArray<Skill_CG,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // ecx@3
  int v5; // edx@4
  int v6; // ecx@6
  int v7; // edx@7
  int v8; // eax@8

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<Skill_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 16 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      v5 = (int)&v2->m_data->normalCost;
      do
      {
        *(_DWORD *)(v5 - 4) = *(_DWORD *)(v3 + 4);
        *(_DWORD *)v5 = *(_DWORD *)(v3 + 8);
        *(_DWORD *)(v5 + 4) = *(_DWORD *)(v3 + 12);
        v3 += 16;
        v5 += 16;
      }
      while ( v3 < v4 );
    }
    v6 = *(_DWORD *)(a2 + 8);
    if ( v6 < v2->m_num )
    {
      v7 = v6;
      do
      {
        v8 = (int)&v2->m_data[v7];
        *(_DWORD *)(v8 + 4) = 0;
        *(_DWORD *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 12) = 0;
        ++v6;
        ++v7;
      }
      while ( v6 < v2->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (005BEC40) --------------------------------------------------------  // acclient.c:490273
SmartArray<IDClass<_tagDataID,32,0>,1> *__thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::operator=(SmartArray<IDClass<_tagDataID,32,0>,1> *this, int a2)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  IDClass<_tagDataID,32,0> *v5; // ecx@3
  unsigned int i; // eax@5

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<IDClass<_tagDataID,32,0>,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 4 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        v5->id = *(_DWORD *)v3;
        v3 += 4;
        ++v5;
      }
      while ( v3 < v4 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
      v2->m_data[i].id = a2;
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (005BECC0) --------------------------------------------------------  // acclient.c:490306
void *__thiscall ACCharGenStartArea::vector_deleting_destructor(ACCharGenStartArea *this, unsigned int a2)
{
  ACCharGenStartArea *v2; // esi@1
  unsigned int v3; // eax@2
  char *v4; // ebx@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // edi@2
  int v8; // ecx@5
  int v9; // esi@9
  void *result; // eax@15
  int v11; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].mPositionList.m_num;
    v4 = (char *)&this[-1].mPositionList.m_num;
    v5 = 5 * v3;
    v6 = v3 - 1;
    v7 = (int)&v2[4 * v5 / 0x14u];
    if ( v6 >= 0 )
    {
      v11 = v6 + 1;
      do
      {
        v7 -= 20;
        *(_DWORD *)v7 = &ACCharGenStartArea::vftable;
        if ( (*(_DWORD *)(v7 + 12) & 0x80000000) == 0x80000000 )
        {
          v8 = *(_DWORD *)(v7 + 8);
          if ( v8 )
          {
            if ( *(_DWORD *)(v8 - 4) )
              (**(void (__stdcall ***)(_DWORD))v8)(3);
            else
              operator delete[]((void *)(v8 - 4));
          }
        }
        v9 = *(_DWORD *)(v7 + 4) - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        --v11;
      }
      while ( v11 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    ACCharGenStartArea::~ACCharGenStartArea(this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005BED90) --------------------------------------------------------  // acclient.c:490368
char __thiscall SmartArray<Position,1>::grow(SmartArray<Position,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<Position,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // esi@6
  int v7; // eax@8
  int v8; // esi@9
  int v9; // ebx@9
  int v10; // ST08_4@10
  Position *v11; // ecx@13
  int v12; // [sp+Ch] [bp-4h]@6
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Position,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](72 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      v12 = (int)((char *)v5 + 4);
      vector_constructor_iterator((char *)v5 + 4, 0x48u, i_nSize, (void *(__thiscall *)(void *))Position::Position);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v6 + 72 * v7 + 8;
            v9 = -8 - v12;
            i_nSizea = v3->m_num;
            do
            {
              v10 = (int)((char *)&v3->m_data->frame + v9 + v8);
              *(_DWORD *)(v8 - 4) = *(unsigned int *)((char *)&v3->m_data->objcell_id + v9 + v8);
              Frame::operator=(v8, v10);
              v8 -= 72;
              --i_nSizea;
            }
            while ( i_nSizea );
            v6 = v12;
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v11 = v3->m_data;
            if ( v3->m_data )
            {
              if ( LODWORD(v11[-1].frame.m_fOrigin.z) )
              {
                ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(3);
                v3->m_data = (Position *)v6;
                v3->m_sizeAndDeallocate = v2 | 0x80000000;
                return 1;
              }
              operator delete[](&v11[-1].frame.m_fOrigin.z);
            }
          }
        }
        v3->m_data = (Position *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005BEEC0) --------------------------------------------------------  // acclient.c:490447
char __thiscall SmartArray<HairStyle_CG,1>::grow(SmartArray<HairStyle_CG,1> *this, unsigned int i_nSize)
{
  SmartArray<HairStyle_CG,1> *v2; // ebx@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // ebp@6
  int v7; // eax@8
  int v8; // esi@9
  int v9; // edi@9
  unsigned int v10; // ebp@9
  int v11; // eax@10
  HairStyle_CG *v12; // ecx@13
  void *v13; // edx@14
  int v14; // esi@14
  int v15; // [sp+Ch] [bp-4h]@6
  int v16; // [sp+Ch] [bp-4h]@14
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@15

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<HairStyle_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](60 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      v15 = (int)((char *)v5 + 4);
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x3Cu,
        i_nSize,
        (void *(__thiscall *)(void *))HairStyle_CG::HairStyle_CG);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = 60 * v7 + v6 + 8;
            v9 = -8 - v6;
            v10 = v2->m_num;
            do
            {
              v11 = (int)((char *)v2->m_data + v9 + v8);
              *(_DWORD *)(v8 - 4) = *(_DWORD *)(v11 + 4);
              *(_BYTE *)v8 = *(_BYTE *)(v11 + 8);
              *(_DWORD *)(v8 + 4) = *(_DWORD *)(v11 + 12);
              ObjDesc::operator=((ObjDesc *)(v8 + 8), (ObjDesc *)(v11 + 16));
              v8 -= 60;
              --v10;
            }
            while ( v10 );
            v3 = i_nSize;
            v6 = v15;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v12 = v2->m_data;
            if ( v2->m_data )
            {
              v13 = &v12[-1].objDesc.num_anim_part_changes;
              v14 = (int)&v12[v12[-1].objDesc.num_anim_part_changes];
              v16 = (int)&v12[-1].objDesc.num_anim_part_changes;
              if ( v12[-1].objDesc.num_anim_part_changes - 1 >= 0 )
              {
                i_nSizea = v12[-1].objDesc.num_anim_part_changes;
                do
                {
                  v14 -= 60;
                  *(_DWORD *)v14 = &HairStyle_CG::vftable;
                  ObjDesc::~ObjDesc((ObjDesc *)(v14 + 16));
                  --i_nSizea;
                }
                while ( i_nSizea );
                v13 = (void *)v16;
              }
              operator delete[](v13);
            }
          }
        }
        v2->m_data = (HairStyle_CG *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);

//----- (005BF000) --------------------------------------------------------  // acclient.c:490547
char __thiscall SmartArray<EyesStrip_CG,1>::grow(SmartArray<EyesStrip_CG,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<EyesStrip_CG,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<EyesStrip_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](100 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x64u,
        i_nSize,
        (void *(__thiscall *)(void *))EyesStrip_CG::EyesStrip_CG);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              EyesStrip_CG::operator=(v8 * 100 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              EyesStrip_CG::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (EyesStrip_CG *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005BF0D0) --------------------------------------------------------  // acclient.c:490611
char __thiscall SmartArray<FaceStrip_CG,1>::grow(SmartArray<FaceStrip_CG,1> *this, unsigned int i_nSize)
{
  SmartArray<FaceStrip_CG,1> *v2; // ebx@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // ebp@6
  int v7; // eax@8
  ObjDesc *v8; // esi@9
  int v9; // edi@9
  unsigned int v10; // ebp@9
  int v11; // eax@10
  FaceStrip_CG *v12; // ecx@13
  void *v13; // edx@14
  int v14; // esi@14
  int v15; // [sp+Ch] [bp-4h]@6
  int v16; // [sp+Ch] [bp-4h]@14
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@15

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<FaceStrip_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](52 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      v15 = (int)((char *)v5 + 4);
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x34u,
        i_nSize,
        (void *(__thiscall *)(void *))FaceStrip_CG::FaceStrip_CG);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = (ObjDesc *)(52 * v7 + v6 + 8);
            v9 = -8 - v6;
            v10 = v2->m_num;
            do
            {
              v11 = (int)((char *)v2->m_data + (unsigned int)((char *)v8 + v9));
              v8[-1].num_anim_part_changes = *(_DWORD *)(v11 + 4);
              ObjDesc::operator=(v8, (ObjDesc *)(v11 + 8));
              v8 = (ObjDesc *)((char *)v8 - 52);
              --v10;
            }
            while ( v10 );
            v3 = i_nSize;
            v6 = v15;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v12 = v2->m_data;
            if ( v2->m_data )
            {
              v13 = &v12[-1].objDesc.num_anim_part_changes;
              v14 = (int)&v12[v12[-1].objDesc.num_anim_part_changes];
              v16 = (int)&v12[-1].objDesc.num_anim_part_changes;
              if ( v12[-1].objDesc.num_anim_part_changes - 1 >= 0 )
              {
                i_nSizea = v12[-1].objDesc.num_anim_part_changes;
                do
                {
                  v14 -= 52;
                  *(_DWORD *)v14 = &FaceStrip_CG::vftable;
                  ObjDesc::~ObjDesc((ObjDesc *)(v14 + 8));
                  --i_nSizea;
                }
                while ( i_nSizea );
                v13 = (void *)v16;
              }
              operator delete[](v13);
            }
          }
        }
        v2->m_data = (FaceStrip_CG *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);

//----- (005BF210) --------------------------------------------------------  // acclient.c:490709
char __thiscall SmartArray<Style_CG,1>::shrink(SmartArray<Style_CG,1> *this)
{
  SmartArray<Style_CG,1> *v1; // edi@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // ebx@5
  int v6; // eax@6
  int v7; // esi@7
  unsigned int v8; // ebp@7
  unsigned int v9; // ecx@15

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](16 * v2 + 4);
    if ( !v4 )
      return 0;
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = v2;
    vector_constructor_iterator((char *)v4 + 4, 0x10u, v2, (void *(__thiscall *)(void *))Style_CG::Style_CG);
    if ( !v5 )
      return 0;
    v6 = v1->m_num - 1;
    if ( v6 >= 0 )
    {
      v7 = v6;
      v8 = v1->m_num;
      do
      {
        Style_CG::operator=(v7 * 16 + v5, (int)&v1->m_data[v7]);
        --v7;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v1->m_data )
      Style_CG::vector_deleting_destructor(v1->m_data, 3u);
  }
  v9 = v1->m_num;
  v1->m_data = (Style_CG *)v5;
  v1->m_sizeAndDeallocate = v9 | 0x80000000;
  return 1;
}

//----- (005BF2C0) --------------------------------------------------------  // acclient.c:490764
void __thiscall SmartArray<Style_CG,1>::Reset(SmartArray<Style_CG,1> *this)
{
  SmartArray<Style_CG,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // ecx@8
  int v7; // esi@8
  int v8; // [sp+8h] [bp-14h]@7
  void (__thiscall **v9)(Style_CG *, struct Archive *); // [sp+Ch] [bp-10h]@7
  PSRefBufferCharData<char> *v10; // [sp+10h] [bp-Ch]@8
  unsigned int v11; // [sp+14h] [bp-8h]@8
  unsigned int v12; // [sp+18h] [bp-4h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      Style_CG::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v9 = &Style_CG::vftable;
      v8 = v4 + 1;
      do
      {
        v10 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v6 = (int)&v1->m_data[v5];
        v11 = stru_8EF864.id;
        v12 = stru_8EF864.id;
        Style_CG::operator=(v6, (int)&v9);
        v7 = (int)&v10[-2].m_data[12];
        v9 = &Style_CG::vftable;
        if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        --v5;
        --v8;
      }
      while ( v8 );
    }
  }
}
// 79FE70: using guessed type void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *);

//----- (005BF3A0) --------------------------------------------------------  // acclient.c:490820
void __thiscall Sex_CG::GetSubDataIDs(Sex_CG *this, QualifiedDataIDArray *id_array)
{
  Sex_CG *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID *v5; // eax@1
  QualifiedDataID *v6; // eax@1
  QualifiedDataID *v7; // eax@1
  QualifiedDataID *v8; // eax@1
  QualifiedDataID *v9; // eax@1
  QualifiedDataID *v10; // eax@1
  unsigned int v11; // ebx@1
  QualifiedDataID *v12; // eax@2
  unsigned int j; // ebx@3
  QualifiedDataID *v14; // eax@4
  bool v15; // zf@5
  int v16; // ebx@7
  QualifiedDataID *v17; // eax@7
  bool v18; // cf@7
  EyesStrip_CG *v19; // ebx@10
  IDClass<_tagDataID,32,0> v20; // eax@10
  int v21; // ebx@10
  QualifiedDataID *v22; // eax@10
  QualifiedDataID *v23; // eax@10
  int v24; // ebx@13
  QualifiedDataID *v25; // eax@13
  int v26; // ebx@16
  QualifiedDataID *v27; // eax@16
  Style_CG *v28; // ebx@19
  QualifiedDataID *v29; // eax@19
  QualifiedDataID *v30; // eax@19
  Style_CG *v31; // ebx@22
  QualifiedDataID *v32; // eax@22
  QualifiedDataID *v33; // eax@22
  Style_CG *v34; // ebx@25
  QualifiedDataID *v35; // eax@25
  QualifiedDataID *v36; // eax@25
  Style_CG *v37; // ebx@28
  QualifiedDataID *v38; // eax@28
  QualifiedDataID *v39; // eax@28
  int v40; // [sp+Ch] [bp-1Ch]@6
  int v41; // [sp+Ch] [bp-1Ch]@9
  int v42; // [sp+Ch] [bp-1Ch]@12
  int v43; // [sp+Ch] [bp-1Ch]@15
  int v44; // [sp+Ch] [bp-1Ch]@18
  int v45; // [sp+Ch] [bp-1Ch]@21
  int v46; // [sp+Ch] [bp-1Ch]@24
  int v47; // [sp+Ch] [bp-1Ch]@27
  QualifiedDataID i; // [sp+10h] [bp-18h]@1
  QualifiedDataID v49; // [sp+18h] [bp-10h]@7
  QualifiedDataID v50; // [sp+20h] [bp-8h]@10

  v2 = this;
  QualifiedDataID::QualifiedDataID(&i, this->setup, 0);
  QualifiedDataIDArray::AddQDID(id_array, v3, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->soundTable, 0);
  QualifiedDataIDArray::AddQDID(id_array, v4, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->iconImage, 0);
  QualifiedDataIDArray::AddQDID(id_array, v5, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->basePalette, 0);
  QualifiedDataIDArray::AddQDID(id_array, v6, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->skinPalSet, 0);
  QualifiedDataIDArray::AddQDID(id_array, v7, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->physicsTable, 0);
  QualifiedDataIDArray::AddQDID(id_array, v8, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->motionTable, 0);
  QualifiedDataIDArray::AddQDID(id_array, v9, 8u);
  QualifiedDataID::QualifiedDataID(&i, v2->combatTable, 0);
  QualifiedDataIDArray::AddQDID(id_array, v10, 8u);
  ObjDesc::GetSubDataIDs(&v2->objDesc, id_array);
  v11 = 0;
  if ( v2->mHairColorList.m_num )
  {
    do
    {
      QualifiedDataID::QualifiedDataID(&i, v2->mHairColorList.m_data[v11], 0);
      QualifiedDataIDArray::AddQDID(id_array, v12, 0);
      ++v11;
    }
    while ( v11 < v2->mHairColorList.m_num );
  }
  for ( j = 0; j < v2->mEyeColorList.m_num; ++j )
  {
    QualifiedDataID::QualifiedDataID(&i, v2->mEyeColorList.m_data[j], 0);
    QualifiedDataIDArray::AddQDID(id_array, v14, 0);
  }
  v15 = v2->mHairStyleList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v40 = 0;
    do
    {
      v16 = (int)&v2->mHairStyleList.m_data[v40];
      QualifiedDataID::QualifiedDataID(&v49, *(IDClass<_tagDataID,32,0> *)(v16 + 4), 0);
      QualifiedDataIDArray::AddQDID(id_array, v17, 8u);
      ObjDesc::GetSubDataIDs((ObjDesc *)(v16 + 16), id_array);
      v18 = (signed int)i.Type + 1 < v2->mHairStyleList.m_num;
      ++i.Type;
      ++v40;
    }
    while ( v18 );
  }
  v15 = v2->mEyeStripList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v41 = 0;
    do
    {
      v19 = v2->mEyeStripList.m_data;
      v20.id = v19[v41].iconImage.id;
      v21 = (int)&v19[v41];
      QualifiedDataID::QualifiedDataID(&v49, v20, 0);
      QualifiedDataIDArray::AddQDID(id_array, v22, 8u);
      QualifiedDataID::QualifiedDataID(&v50, *(IDClass<_tagDataID,32,0> *)(v21 + 8), 0);
      QualifiedDataIDArray::AddQDID(id_array, v23, 8u);
      ObjDesc::GetSubDataIDs((ObjDesc *)(v21 + 12), id_array);
      ObjDesc::GetSubDataIDs((ObjDesc *)(v21 + 56), id_array);
      v18 = (signed int)i.Type + 1 < v2->mEyeStripList.m_num;
      ++i.Type;
      ++v41;
    }
    while ( v18 );
  }
  v15 = v2->mNoseStripList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v42 = 0;
    do
    {
      v24 = (int)&v2->mNoseStripList.m_data[v42];
      QualifiedDataID::QualifiedDataID(&v50, *(IDClass<_tagDataID,32,0> *)(v24 + 4), 0);
      QualifiedDataIDArray::AddQDID(id_array, v25, 8u);
      ObjDesc::GetSubDataIDs((ObjDesc *)(v24 + 8), id_array);
      v18 = (signed int)i.Type + 1 < v2->mNoseStripList.m_num;
      ++i.Type;
      ++v42;
    }
    while ( v18 );
  }
  v15 = v2->mMouthStripList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v43 = 0;
    do
    {
      v26 = (int)&v2->mMouthStripList.m_data[v43];
      QualifiedDataID::QualifiedDataID(&v50, *(IDClass<_tagDataID,32,0> *)(v26 + 4), 0);
      QualifiedDataIDArray::AddQDID(id_array, v27, 8u);
      ObjDesc::GetSubDataIDs((ObjDesc *)(v26 + 8), id_array);
      v18 = (signed int)i.Type + 1 < v2->mMouthStripList.m_num;
      ++i.Type;
      ++v43;
    }
    while ( v18 );
  }
  v15 = v2->mHeadgearList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v44 = 0;
    do
    {
      v28 = v2->mHeadgearList.m_data;
      QualifiedDataID::QualifiedDataID(&v50, v28[v44].clothingTable, 0);
      QualifiedDataIDArray::AddQDID(id_array, v29, 8u);
      QualifiedDataID::QualifiedDataID(&v49, v28[v44].weenieDefault, 0);
      QualifiedDataIDArray::AddQDID(id_array, v30, 8u);
      v18 = (signed int)i.Type + 1 < v2->mHeadgearList.m_num;
      ++i.Type;
      ++v44;
    }
    while ( v18 );
  }
  v15 = v2->mShirtList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v45 = 0;
    do
    {
      v31 = v2->mShirtList.m_data;
      QualifiedDataID::QualifiedDataID(&v50, v31[v45].clothingTable, 0);
      QualifiedDataIDArray::AddQDID(id_array, v32, 8u);
      QualifiedDataID::QualifiedDataID(&v49, v31[v45].weenieDefault, 0);
      QualifiedDataIDArray::AddQDID(id_array, v33, 8u);
      v18 = (signed int)i.Type + 1 < v2->mShirtList.m_num;
      ++i.Type;
      ++v45;
    }
    while ( v18 );
  }
  v15 = v2->mPantsList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v46 = 0;
    do
    {
      v34 = v2->mPantsList.m_data;
      QualifiedDataID::QualifiedDataID(&v50, v34[v46].clothingTable, 0);
      QualifiedDataIDArray::AddQDID(id_array, v35, 8u);
      QualifiedDataID::QualifiedDataID(&v49, v34[v46].weenieDefault, 0);
      QualifiedDataIDArray::AddQDID(id_array, v36, 8u);
      v18 = (signed int)i.Type + 1 < v2->mPantsList.m_num;
      ++i.Type;
      ++v46;
    }
    while ( v18 );
  }
  v15 = v2->mFootwearList.m_num == 0;
  i.Type = 0;
  if ( !v15 )
  {
    v47 = 0;
    do
    {
      v37 = v2->mFootwearList.m_data;
      QualifiedDataID::QualifiedDataID(&v50, v37[v47].clothingTable, 0);
      QualifiedDataIDArray::AddQDID(id_array, v38, 8u);
      QualifiedDataID::QualifiedDataID(&v49, v37[v47].weenieDefault, 0);
      QualifiedDataIDArray::AddQDID(id_array, v39, 8u);
      v18 = (signed int)i.Type + 1 < v2->mFootwearList.m_num;
      ++i.Type;
      ++v47;
    }
    while ( v18 );
  }
}

//----- (005BF850) --------------------------------------------------------  // acclient.c:491054
SmartArray<HairStyle_CG,1> *__thiscall SmartArray<HairStyle_CG,1>::operator=(SmartArray<HairStyle_CG,1> *this, int a2)
{
  int v2; // ebx@1
  SmartArray<HairStyle_CG,1> *v3; // edi@1
  unsigned int v4; // esi@3
  int v5; // ebp@3
  int v6; // ebx@4
  int v7; // esi@7
  int v8; // ebp@8
  unsigned int v9; // ST18_4@9
  unsigned int v10; // ST20_4@9
  int v11; // eax@9
  ObjDesc rhs; // [sp+18h] [bp-2Ch]@9

  v2 = a2;
  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<HairStyle_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v5 = *(_DWORD *)a2 + 60 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = (int)&v3->m_data->bald;
      do
      {
        *(_DWORD *)(v6 - 4) = *(_DWORD *)(v4 + 4);
        *(_BYTE *)v6 = *(_BYTE *)(v4 + 8);
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v4 + 12);
        ObjDesc::operator=((ObjDesc *)(v6 + 8), (ObjDesc *)(v4 + 16));
        v4 += 60;
        v6 += 60;
      }
      while ( v4 < v5 );
      v2 = a2;
    }
    v7 = *(_DWORD *)(v2 + 8);
    if ( v7 < v3->m_num )
    {
      v8 = v7;
      do
      {
        v9 = stru_8EF864.id;
        v10 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        v11 = (int)&v3->m_data[v8];
        *(_DWORD *)(v11 + 4) = v9;
        *(_BYTE *)(v11 + 8) = 0;
        *(_DWORD *)(v11 + 12) = v10;
        ObjDesc::operator=((ObjDesc *)(v11 + 16), &rhs);
        ObjDesc::~ObjDesc(&rhs);
        ++v7;
        ++v8;
      }
      while ( v7 < v3->m_num );
      v2 = a2;
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005BF960) --------------------------------------------------------  // acclient.c:491117
SmartArray<EyesStrip_CG,1> *__thiscall SmartArray<EyesStrip_CG,1>::operator=(SmartArray<EyesStrip_CG,1> *this, int a2)
{
  int v2; // ebp@1
  SmartArray<EyesStrip_CG,1> *v3; // edi@1
  unsigned int v4; // esi@3
  int v5; // ebx@3
  int v6; // ebp@4
  int v7; // ebx@7
  int v8; // ebp@8
  unsigned int v9; // ST18_4@9
  unsigned int v10; // ST1C_4@9
  int v11; // esi@9
  ObjDesc rhs; // [sp+14h] [bp-58h]@9
  ObjDesc v14; // [sp+40h] [bp-2Ch]@9

  v2 = a2;
  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<EyesStrip_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v5 = *(_DWORD *)a2 + 100 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = (int)&v3->m_data->iconImage_Bald;
      do
      {
        *(_DWORD *)(v6 - 4) = *(_DWORD *)(v4 + 4);
        *(_DWORD *)v6 = *(_DWORD *)(v4 + 8);
        ObjDesc::operator=((ObjDesc *)(v6 + 4), (ObjDesc *)(v4 + 12));
        ObjDesc::operator=((ObjDesc *)(v6 + 48), (ObjDesc *)(v4 + 56));
        v4 += 100;
        v6 += 100;
      }
      while ( v4 < v5 );
      v2 = a2;
    }
    v7 = *(_DWORD *)(v2 + 8);
    if ( v7 < v3->m_num )
    {
      v8 = v7;
      do
      {
        v9 = stru_8EF864.id;
        v10 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        ObjDesc::ObjDesc(&v14);
        v11 = (int)&v3->m_data[v8];
        *(_DWORD *)(v11 + 4) = v9;
        *(_DWORD *)(v11 + 8) = v10;
        ObjDesc::operator=((ObjDesc *)(v11 + 12), &rhs);
        ObjDesc::operator=((ObjDesc *)(v11 + 56), &v14);
        ObjDesc::~ObjDesc(&v14);
        ObjDesc::~ObjDesc(&rhs);
        ++v7;
        ++v8;
      }
      while ( v7 < v3->m_num );
      v2 = a2;
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005BFA90) --------------------------------------------------------  // acclient.c:491183
SmartArray<FaceStrip_CG,1> *__thiscall SmartArray<FaceStrip_CG,1>::operator=(SmartArray<FaceStrip_CG,1> *this, int a2)
{
  int v2; // ebp@1
  SmartArray<FaceStrip_CG,1> *v3; // edi@1
  unsigned int v4; // esi@3
  int v5; // ebx@3
  ObjDesc *v6; // ebp@4
  int v7; // esi@7
  int v8; // ebx@8
  unsigned int v9; // ST18_4@9
  int v10; // eax@9
  ObjDesc rhs; // [sp+10h] [bp-2Ch]@9

  v2 = a2;
  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<FaceStrip_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v5 = *(_DWORD *)a2 + 52 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = &v3->m_data->objDesc;
      do
      {
        v6[-1].num_anim_part_changes = *(_DWORD *)(v4 + 4);
        ObjDesc::operator=(v6, (ObjDesc *)(v4 + 8));
        v4 += 52;
        v6 = (ObjDesc *)((char *)v6 + 52);
      }
      while ( v4 < v5 );
      v2 = a2;
    }
    v7 = *(_DWORD *)(v2 + 8);
    if ( v7 < v3->m_num )
    {
      v8 = v7;
      do
      {
        v9 = stru_8EF864.id;
        ObjDesc::ObjDesc(&rhs);
        v10 = (int)&v3->m_data[v8];
        *(_DWORD *)(v10 + 4) = v9;
        ObjDesc::operator=((ObjDesc *)(v10 + 8), &rhs);
        ObjDesc::~ObjDesc(&rhs);
        ++v7;
        ++v8;
      }
      while ( v7 < v3->m_num );
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005BFB80) --------------------------------------------------------  // acclient.c:491239
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Template_CG *const *_class, SmartArray<int,1> *_obj, Archive *_arc)
{
  Archive *v3; // esi@1
  SmartArray<int,1> *v4; // edi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<int,1> *v7; // ebp@2
  unsigned int v8; // eax@4
  int *v9; // ebp@9
  unsigned int v10; // eax@10

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<int,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<MediaDesc *,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      Archive::CheckAlignment(v3, 4u);
      v10 = Archive::GetBytes(v3, 4u);
      if ( v10 )
      {
        if ( v3->m_flags & 1 )
          *(_DWORD *)v10 = *v9;
        else
          *v9 = *(_DWORD *)v10;
      }
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<MediaDesc *,1>::shrink(v4);
      }
    }
  }
}

//----- (005BFC70) --------------------------------------------------------  // acclient.c:491312
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(HeritageGroup_CG *const *_class, SmartArray<Skill_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<Skill_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<Skill_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  Skill_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<Skill_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<Skill_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<Skill_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<Skill_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005BFD40) --------------------------------------------------------  // acclient.c:491376
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Sex_CG *const *_class, SmartArray<IDClass<_tagDataID,32,0>,1> *_obj, Archive *_arc)
{
  Archive *v3; // esi@1
  SmartArray<IDClass<_tagDataID,32,0>,1> *v4; // edi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<IDClass<_tagDataID,32,0>,1> *v7; // ebp@2
  unsigned int v8; // eax@4
  IDClass<_tagDataID,32,0> *v9; // ebp@9
  unsigned int v10; // eax@10

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<IDClass<_tagDataID,32,0>,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<IDClass<_tagDataID,32,0>,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<IDClass<_tagDataID,32,0>,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      Archive::CheckAlignment(v3, 4u);
      v10 = Archive::GetBytes(v3, 4u);
      if ( v10 )
      {
        if ( v3->m_flags & 1 )
          *(_DWORD *)v10 = v9->id;
        else
          v9->id = *(_DWORD *)v10;
      }
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<IDClass<_tagDataID,32,0>,1>::shrink(v4);
      }
    }
  }
}

//----- (005BFE30) --------------------------------------------------------  // acclient.c:491449
int __thiscall Template_CG::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v2 + 40), a2 + 40);
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v2 + 52), a2 + 52);
  return v2;
}

//----- (005BFEC0) --------------------------------------------------------  // acclient.c:491481
SmartArray<Position,1> *__thiscall SmartArray<Position,1>::operator=(SmartArray<Position,1> *this, int a2)
{
  int v2; // ebp@1
  SmartArray<Position,1> *v3; // edi@1
  int v4; // eax@3
  int v5; // edx@3
  int v6; // esi@4
  int v7; // ecx@4
  unsigned int v8; // edx@4
  int v9; // ebx@5
  unsigned int v10; // esi@7
  int v11; // ebx@8
  Position *v12; // eax@9
  int v13; // eax@9
  int v14; // edx@9
  Frame v16; // [sp+10h] [bp-40h]@9

  v2 = a2;
  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<Position,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v5 = *(_DWORD *)a2 + 72 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = (int)&v3->m_data->frame.qx;
      v7 = v4 + 12;
      v8 = (v5 - v4 - 1) / 0x48u + 1;
      do
      {
        *(_DWORD *)(v6 - 8) = *(_DWORD *)(v7 - 8);
        v9 = v6 + 48;
        *(_DWORD *)v9 = *(_DWORD *)(v7 + 48);
        *(_DWORD *)(v9 + 4) = *(_DWORD *)(v7 + 52);
        *(_DWORD *)(v9 + 8) = *(_DWORD *)(v7 + 56);
        *(_DWORD *)(v6 - 4) = *(_DWORD *)(v7 - 4);
        *(_DWORD *)v6 = *(_DWORD *)v7;
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v7 + 4);
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v7 + 8);
        *(_DWORD *)(v6 + 12) = *(_DWORD *)(v7 + 12);
        *(_DWORD *)(v6 + 16) = *(_DWORD *)(v7 + 16);
        *(_DWORD *)(v6 + 20) = *(_DWORD *)(v7 + 20);
        *(_DWORD *)(v6 + 24) = *(_DWORD *)(v7 + 24);
        *(_DWORD *)(v6 + 28) = *(_DWORD *)(v7 + 28);
        *(_DWORD *)(v6 + 32) = *(_DWORD *)(v7 + 32);
        *(_DWORD *)(v6 + 36) = *(_DWORD *)(v7 + 36);
        *(_DWORD *)(v6 + 40) = *(_DWORD *)(v7 + 40);
        *(_DWORD *)(v6 + 44) = *(_DWORD *)(v7 + 44);
        v7 += 72;
        v6 += 72;
        --v8;
      }
      while ( v8 );
      v2 = a2;
    }
    v10 = *(_DWORD *)(v2 + 8);
    if ( v10 < v3->m_num )
    {
      v11 = v10;
      do
      {
        LODWORD(v16.qw) = 1065353216;
        LODWORD(v16.qx) = 0;
        LODWORD(v16.qy) = 0;
        LODWORD(v16.qz) = 0;
        LODWORD(v16.m_fOrigin.x) = 0;
        LODWORD(v16.m_fOrigin.y) = 0;
        LODWORD(v16.m_fOrigin.z) = 0;
        Frame::cache(&v16);
        v12 = v3->m_data;
        v12[v11].objcell_id = 0;
        v13 = (int)&v12[v11];
        v14 = v13 + 60;
        *(_DWORD *)v14 = LODWORD(v16.m_fOrigin.x);
        *(_DWORD *)(v14 + 4) = LODWORD(v16.m_fOrigin.y);
        *(_DWORD *)(v14 + 8) = LODWORD(v16.m_fOrigin.z);
        *(_DWORD *)(v13 + 8) = (_DWORD)v16.qw;
        *(_DWORD *)(v13 + 12) = LODWORD(v16.qx);
        *(_DWORD *)(v13 + 16) = LODWORD(v16.qy);
        *(_DWORD *)(v13 + 20) = LODWORD(v16.qz);
        *(_DWORD *)(v13 + 24) = LODWORD(v16.m_fl2gv[0]);
        *(_DWORD *)(v13 + 28) = LODWORD(v16.m_fl2gv[1]);
        *(_DWORD *)(v13 + 32) = LODWORD(v16.m_fl2gv[2]);
        *(_DWORD *)(v13 + 36) = LODWORD(v16.m_fl2gv[3]);
        *(_DWORD *)(v13 + 40) = LODWORD(v16.m_fl2gv[4]);
        *(_DWORD *)(v13 + 44) = LODWORD(v16.m_fl2gv[5]);
        *(_DWORD *)(v13 + 48) = LODWORD(v16.m_fl2gv[6]);
        *(_DWORD *)(v13 + 52) = LODWORD(v16.m_fl2gv[7]);
        *(_DWORD *)(v13 + 56) = LODWORD(v16.m_fl2gv[8]);
        ++v10;
        ++v11;
      }
      while ( v10 < v3->m_num );
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005C00C0) --------------------------------------------------------  // acclient.c:491582
char __thiscall SmartArray<Template_CG,1>::shrink(SmartArray<Template_CG,1> *this)
{
  SmartArray<Template_CG,1> *v1; // edi@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // ebx@5
  int v6; // eax@6
  int v7; // esi@7
  unsigned int v8; // ebp@7
  unsigned int v9; // ecx@15

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[]((v2 << 6) + 4);
    if ( !v4 )
      return 0;
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = v2;
    vector_constructor_iterator((char *)v4 + 4, 0x40u, v2, (void *(__thiscall *)(void *))Template_CG::Template_CG);
    if ( !v5 )
      return 0;
    v6 = v1->m_num - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 << 6;
      v8 = v1->m_num;
      do
      {
        Template_CG::operator=(v7 + v5, (int)((char *)v1->m_data + v7));
        v7 -= 64;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v1->m_data )
      Template_CG::vector_deleting_destructor(v1->m_data, 3u);
  }
  v9 = v1->m_num;
  v1->m_data = (Template_CG *)v5;
  v1->m_sizeAndDeallocate = v9 | 0x80000000;
  return 1;
}

//----- (005C0170) --------------------------------------------------------  // acclient.c:491637
char __thiscall SmartArray<Style_CG,1>::grow(SmartArray<Style_CG,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<Style_CG,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Style_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator((char *)v5 + 4, 0x10u, i_nSize, (void *(__thiscall *)(void *))Style_CG::Style_CG);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              Style_CG::operator=(v8 * 16 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              Style_CG::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (Style_CG *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005C0240) --------------------------------------------------------  // acclient.c:491697
void __thiscall SmartArray<Template_CG,1>::Reset(SmartArray<Template_CG,1> *this)
{
  SmartArray<Template_CG,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // ebx@7
  int v7; // eax@8
  Template_CG v8; // [sp+8h] [bp-40h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      Template_CG::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4 << 6;
      v6 = v4 + 1;
      do
      {
        Template_CG::Template_CG(&v8);
        Template_CG::operator=((int)((char *)v1->m_data + v5), v7);
        Template_CG::~Template_CG(&v8);
        v5 -= 64;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (005C02C0) --------------------------------------------------------  // acclient.c:491740
void __thiscall Sex_CG::Sex_CG(Sex_CG *this)
{
  Sex_CG *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (Sex_CGVtbl *)&Sex_CG::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->scaling = 0;
  v1->setup.id = stru_8EF864.id;
  v1->soundTable.id = stru_8EF864.id;
  v1->iconImage.id = stru_8EF864.id;
  ObjDesc::ObjDesc(&v1->objDesc);
  v1->physicsTable.id = stru_8EF864.id;
  v1->motionTable.id = stru_8EF864.id;
  v1->combatTable.id = stru_8EF864.id;
  v1->basePalette.id = stru_8EF864.id;
  v1->skinPalSet.id = stru_8EF864.id;
  v1->mHairColorList.m_data = 0;
  v1->mHairColorList.m_sizeAndDeallocate = 0;
  v1->mHairColorList.m_num = 0;
  v1->mHairStyleList.m_data = 0;
  v1->mHairStyleList.m_sizeAndDeallocate = 0;
  v1->mHairStyleList.m_num = 0;
  v1->mEyeColorList.m_data = 0;
  v1->mEyeColorList.m_sizeAndDeallocate = 0;
  v1->mEyeColorList.m_num = 0;
  v1->mEyeStripList.m_data = 0;
  v1->mEyeStripList.m_sizeAndDeallocate = 0;
  v1->mEyeStripList.m_num = 0;
  v1->mNoseStripList.m_data = 0;
  v1->mNoseStripList.m_sizeAndDeallocate = 0;
  v1->mNoseStripList.m_num = 0;
  v1->mMouthStripList.m_data = 0;
  v1->mMouthStripList.m_sizeAndDeallocate = 0;
  v1->mMouthStripList.m_num = 0;
  v1->mHeadgearList.m_data = 0;
  v1->mHeadgearList.m_sizeAndDeallocate = 0;
  v1->mHeadgearList.m_num = 0;
  v1->mShirtList.m_data = 0;
  v1->mShirtList.m_sizeAndDeallocate = 0;
  v1->mShirtList.m_num = 0;
  v1->mPantsList.m_data = 0;
  v1->mPantsList.m_sizeAndDeallocate = 0;
  v1->mPantsList.m_num = 0;
  v1->mFootwearList.m_data = 0;
  v1->mFootwearList.m_sizeAndDeallocate = 0;
  v1->mFootwearList.m_num = 0;
  v1->mClothingColorsList.m_data = 0;
  v1->mClothingColorsList.m_sizeAndDeallocate = 0;
  v1->mClothingColorsList.m_num = 0;
}
// 79FE7C: using guessed type void (__thiscall *Sex_CG::vftable)(Sex_CG *this, struct Archive *);

//----- (005C03E0) --------------------------------------------------------  // acclient.c:491797
void __thiscall Style_CG::Serialize(Style_CG *this, Archive *io_archive)
{
  Style_CG *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  PStringBase<char>::Serialize(&this->name, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->clothingTable.id;
    else
      v2->clothingTable.id = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->weenieDefault.id;
    else
      v2->weenieDefault.id = *(_DWORD *)v4;
  }
}

//----- (005C0450) --------------------------------------------------------  // acclient.c:491826
void __thiscall Template_CG::Serialize(Template_CG *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  Template_CG *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17
  unsigned int v9; // eax@21
  unsigned int v10; // eax@25
  unsigned int v11; // eax@29

  v2 = io_archive;
  v3 = this;
  PStringBase<char>::Serialize(&this->name, io_archive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->titleID;
    else
      v3->titleID = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v6 = v3->strength;
    else
      v3->strength = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(v2, 4u);
  v7 = Archive::GetBytes(v2, 4u);
  if ( v7 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v7 = v3->endurance;
    else
      v3->endurance = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v3->coordination;
    else
      v3->coordination = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(v2, 4u);
  v9 = Archive::GetBytes(v2, 4u);
  if ( v9 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v9 = v3->quickness;
    else
      v3->quickness = *(_DWORD *)v9;
  }
  Archive::CheckAlignment(v2, 4u);
  v10 = Archive::GetBytes(v2, 4u);
  if ( v10 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v10 = v3->focus;
    else
      v3->focus = *(_DWORD *)v10;
  }
  Archive::CheckAlignment(v2, 4u);
  v11 = Archive::GetBytes(v2, 4u);
  if ( v11 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v11 = v3->self;
    else
      v3->self = *(_DWORD *)v11;
  }
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Template_CG *const *)&io_archive,
    &v3->mNormalSkillsList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Template_CG *const *)&io_archive,
    &v3->mPrimarySkillsList,
    v2);
}

//----- (005C05D0) --------------------------------------------------------  // acclient.c:491925
void __thiscall HeritageGroup_CG::GetSubDataIDs(HeritageGroup_CG *this, QualifiedDataIDArray *id_array)
{
  HeritageGroup_CG *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID *v5; // eax@1
  unsigned int v6; // edi@1
  int v7; // ebx@2
  QualifiedDataID *v8; // eax@3
  int v9; // ecx@4
  HashTableData<unsigned long,Sex_CG> **v10; // eax@5
  int v11; // eax@6
  HashTableData<unsigned long,Sex_CG> **v12; // eax@7
  HashTableData<unsigned long,Sex_CG> *v13; // edi@7
  HashTableData<unsigned long,Sex_CG> **v14; // ebx@9
  QualifiedDataID v15; // [sp+10h] [bp-8h]@1

  v2 = this;
  QualifiedDataID::QualifiedDataID(&v15, this->iconImage, 0);
  QualifiedDataIDArray::AddQDID(id_array, v3, 8u);
  QualifiedDataID::QualifiedDataID(&v15, v2->setupID, 0);
  QualifiedDataIDArray::AddQDID(id_array, v4, 8u);
  QualifiedDataID::QualifiedDataID(&v15, v2->environmentSetupID, 0);
  QualifiedDataIDArray::AddQDID(id_array, v5, 8u);
  v6 = 0;
  if ( v2->mTemplateList.m_num )
  {
    v7 = 0;
    do
    {
      QualifiedDataID::QualifiedDataID(&v15, v2->mTemplateList.m_data[v7].iconImage, 0);
      QualifiedDataIDArray::AddQDID(id_array, v8, 8u);
      ++v6;
      ++v7;
    }
    while ( v6 < v2->mTemplateList.m_num );
  }
  v9 = (int)&v2->mGenderList.m_intrusiveTable.m_buckets[v2->mGenderList.m_intrusiveTable.m_numBuckets];
  if ( v2->mGenderList.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,Sex_CG> **)v9 )
  {
LABEL_7:
    v12 = 0;
    v13 = 0;
  }
  else
  {
    while ( 1 )
    {
      v10 = v2->mGenderList.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v10 )
        break;
      v11 = (int)(v10 + 1);
      v2->mGenderList.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,Sex_CG> **)v11;
      if ( v11 == v9 )
        goto LABEL_7;
    }
    v12 = v2->mGenderList.m_intrusiveTable.m_firstInterestingBucket;
    v13 = *v12;
  }
  v14 = v12;
  if ( v13 )
  {
    do
    {
LABEL_10:
      Sex_CG::GetSubDataIDs(&v13->m_data, id_array);
      v13 = v13->m_hashNext;
    }
    while ( v13 );
    while ( 1 )
    {
      ++v14;
      if ( v14 == &v2->mGenderList.m_intrusiveTable.m_buckets[v2->mGenderList.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v14 )
      {
        v13 = *v14;
        if ( *v14 )
          goto LABEL_10;
        return;
      }
    }
  }
}

//----- (005C06E0) --------------------------------------------------------  // acclient.c:492011
SmartArray<Style_CG,1> *__thiscall SmartArray<Style_CG,1>::operator=(SmartArray<Style_CG,1> *this, int a2)
{
  int v2; // ebx@1
  SmartArray<Style_CG,1> *v3; // ebp@1
  unsigned int v4; // esi@3
  int v5; // edi@3
  int v6; // ebx@4
  int v7; // eax@9
  int v8; // eax@12
  PSRefBufferCharData<char> *v9; // edi@14
  volatile LONG *v10; // ebx@14
  int v11; // esi@14
  PSRefBufferCharData<char> *v12; // eax@14
  int v13; // ebp@15
  bool v14; // cf@22
  int v16; // [sp+Ch] [bp-1Ch]@13
  int v17; // [sp+10h] [bp-18h]@6
  int v18; // [sp+10h] [bp-18h]@12
  SmartArray<Style_CG,1> *v19; // [sp+14h] [bp-14h]@1
  unsigned int v20; // [sp+20h] [bp-8h]@14
  unsigned int v21; // [sp+24h] [bp-4h]@14

  v2 = a2;
  v3 = this;
  v19 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<Style_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)a2;
    v5 = *(_DWORD *)a2 + 16 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      v6 = (int)&v3->m_data->name;
      do
      {
        if ( *(_DWORD *)v6 != *(_DWORD *)(v4 + 4) )
        {
          v17 = *(_DWORD *)v6 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
            (**(void (__stdcall ***)(_DWORD))v17)(1);
          v7 = *(_DWORD *)(v4 + 4);
          *(_DWORD *)v6 = v7;
          InterlockedIncrement((volatile LONG *)(v7 - 16));
        }
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v4 + 8);
        *(_DWORD *)(v6 + 8) = *(_DWORD *)(v4 + 12);
        v4 += 16;
        v6 += 16;
      }
      while ( v4 < v5 );
      v2 = a2;
    }
    v8 = *(_DWORD *)(v2 + 8);
    v18 = *(_DWORD *)(v2 + 8);
    if ( v8 < v3->m_num )
    {
      v16 = v8;
      do
      {
        v9 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v10 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v11 = (int)&v3->m_data[v16];
        v20 = stru_8EF864.id;
        v21 = stru_8EF864.id;
        v12 = *(PSRefBufferCharData<char> **)(v11 + 4);
        if ( v12 != v9 )
        {
          v13 = (int)&v12[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v12[-1]) && v13 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
          *(_DWORD *)(v11 + 4) = v9;
          InterlockedIncrement(v10);
          v3 = v19;
        }
        *(_DWORD *)(v11 + 8) = v20;
        *(_DWORD *)(v11 + 12) = v21;
        if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
          (**(void (__thiscall ***)(char *, signed int))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
        v14 = v18++ + 1 < v3->m_num;
        ++v16;
      }
      while ( v14 );
      v2 = a2;
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005C0870) --------------------------------------------------------  // acclient.c:492102
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(ACCharGenStartArea *const *_class, SmartArray<Position,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<Position,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<Position,1> *v7; // edi@2
  unsigned int v8; // eax@4
  Position *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<Position,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<Position,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<Position,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      Position::Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<Position,1>::shrink(v4);
      }
    }
  }
}

//----- (005C0940) --------------------------------------------------------  // acclient.c:492166
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Sex_CG *const *_class, SmartArray<HairStyle_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<HairStyle_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<HairStyle_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  HairStyle_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<HairStyle_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<HairStyle_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<HairStyle_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<HairStyle_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005C0A10) --------------------------------------------------------  // acclient.c:492230
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Sex_CG *const *_class, SmartArray<EyesStrip_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<EyesStrip_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<EyesStrip_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  EyesStrip_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<EyesStrip_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<EyesStrip_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<EyesStrip_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<EyesStrip_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005C0AE0) --------------------------------------------------------  // acclient.c:492294
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Sex_CG *const *_class, SmartArray<FaceStrip_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<FaceStrip_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<FaceStrip_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  FaceStrip_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<FaceStrip_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<FaceStrip_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<FaceStrip_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<FaceStrip_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005C0BB0) --------------------------------------------------------  // acclient.c:492358
int __thiscall ACCharGenStartArea::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  SmartArray<Position,1>::operator=((SmartArray<Position,1> *)(v2 + 8), a2 + 8);
  return v2;
}

//----- (005C0C10) --------------------------------------------------------  // acclient.c:492381
char __thiscall SmartArray<ACCharGenStartArea,1>::shrink(SmartArray<ACCharGenStartArea,1> *this)
{
  SmartArray<ACCharGenStartArea,1> *v1; // edi@1
  int v2; // esi@1
  void *v4; // eax@4
  int v5; // ebx@5
  int v6; // eax@6
  int v7; // esi@7
  unsigned int v8; // ebp@7
  unsigned int v9; // edx@15

  v1 = this;
  v2 = this->m_num;
  if ( v2 == (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
    return 0;
  if ( v2 )
  {
    v4 = operator new[](20 * v2 + 4);
    if ( !v4 )
      return 0;
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = v2;
    vector_constructor_iterator(
      (char *)v4 + 4,
      0x14u,
      v2,
      (void *(__thiscall *)(void *))ACCharGenStartArea::ACCharGenStartArea);
    if ( !v5 )
      return 0;
    v6 = v1->m_num - 1;
    if ( v6 >= 0 )
    {
      v7 = v6;
      v8 = v1->m_num;
      do
      {
        ACCharGenStartArea::operator=(v7 * 20 + v5, (int)&v1->m_data[v7]);
        --v7;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    v5 = 0;
  }
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v1->m_data )
      ACCharGenStartArea::vector_deleting_destructor(v1->m_data, 3u);
  }
  v9 = v1->m_num;
  v1->m_data = (ACCharGenStartArea *)v5;
  v1->m_sizeAndDeallocate = v9 | 0x80000000;
  return 1;
}

//----- (005C0CC0) --------------------------------------------------------  // acclient.c:492440
char __thiscall SmartArray<Template_CG,1>::grow(SmartArray<Template_CG,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<Template_CG,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Template_CG,1>::Reset(this);
      return 1;
    }
    v5 = operator new[]((i_nSize << 6) + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x40u,
        i_nSize,
        (void *(__thiscall *)(void *))Template_CG::Template_CG);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7 << 6;
            i_nSizea = v3->m_num;
            do
            {
              Template_CG::operator=(v8 + v6, (int)((char *)v3->m_data + v8));
              v8 -= 64;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              Template_CG::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (Template_CG *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005C0D90) --------------------------------------------------------  // acclient.c:492504
void __thiscall SmartArray<ACCharGenStartArea,1>::Reset(SmartArray<ACCharGenStartArea,1> *this)
{
  SmartArray<ACCharGenStartArea,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // esi@7
  int v6; // ebp@7
  int v7; // ecx@8
  ACCharGenStartArea v8; // [sp+8h] [bp-14h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      ACCharGenStartArea::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        v8.name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v8.vfptr = (ACCharGenStartAreaVtbl *)&ACCharGenStartArea::vftable;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v7 = (int)&v1->m_data[v5];
        v8.mPositionList.m_data = 0;
        v8.mPositionList.m_sizeAndDeallocate = 0;
        v8.mPositionList.m_num = 0;
        ACCharGenStartArea::operator=(v7, (int)&v8);
        ACCharGenStartArea::~ACCharGenStartArea(&v8);
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005C0E30) --------------------------------------------------------  // acclient.c:492554
void __thiscall ACCharGenStartArea::ACCharGenStartArea(ACCharGenStartArea *this, ACCharGenStartArea *__that)
{
  ACCharGenStartArea *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@1

  v2 = this;
  this->vfptr = (ACCharGenStartAreaVtbl *)&ACCharGenStartArea::vftable;
  v3 = __that->name.m_charbuffer;
  this->name.m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v4 = (int)&v2->mPositionList;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  SmartArray<Position,1>::operator=(&v2->mPositionList, (int)&__that->mPositionList);
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005C0E70) --------------------------------------------------------  // acclient.c:492574
void __thiscall ACCharGenStartArea::Serialize(ACCharGenStartArea *this, Archive *io_archive)
{
  Archive *v2; // edi@1
  ACCharGenStartArea *v3; // esi@1

  v2 = io_archive;
  v3 = this;
  PStringBase<char>::Serialize(&this->name, io_archive);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (ACCharGenStartArea *const *)&io_archive,
    &v3->mPositionList,
    v2);
}

//----- (005C0EA0) --------------------------------------------------------  // acclient.c:492589
void __thiscall ACCharGenData::GetSubDataIDs(ACCharGenData *this, QualifiedDataIDArray *id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         &this->mHeritageGroupList.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      HeritageGroup_CG::GetSubDataIDs(&v3->m_data, id_array);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v3 = *v5;
        if ( *v5 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (005C0F00) --------------------------------------------------------  // acclient.c:492629
int __thiscall Sex_CG::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  ObjDesc::operator=((ObjDesc *)(v2 + 24), (ObjDesc *)(a2 + 24));
  *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
  *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
  SmartArray<IDClass<_tagDataID,32,0>,1>::operator=((SmartArray<IDClass<_tagDataID,32,0>,1> *)(v2 + 88), a2 + 88);
  SmartArray<HairStyle_CG,1>::operator=((SmartArray<HairStyle_CG,1> *)(v2 + 100), a2 + 100);
  SmartArray<IDClass<_tagDataID,32,0>,1>::operator=((SmartArray<IDClass<_tagDataID,32,0>,1> *)(v2 + 112), a2 + 112);
  SmartArray<EyesStrip_CG,1>::operator=((SmartArray<EyesStrip_CG,1> *)(v2 + 124), a2 + 124);
  SmartArray<FaceStrip_CG,1>::operator=((SmartArray<FaceStrip_CG,1> *)(v2 + 136), a2 + 136);
  SmartArray<FaceStrip_CG,1>::operator=((SmartArray<FaceStrip_CG,1> *)(v2 + 148), a2 + 148);
  SmartArray<Style_CG,1>::operator=((SmartArray<Style_CG,1> *)(v2 + 160), a2 + 160);
  SmartArray<Style_CG,1>::operator=((SmartArray<Style_CG,1> *)(v2 + 172), a2 + 172);
  SmartArray<Style_CG,1>::operator=((SmartArray<Style_CG,1> *)(v2 + 184), a2 + 184);
  SmartArray<Style_CG,1>::operator=((SmartArray<Style_CG,1> *)(v2 + 196), a2 + 196);
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v2 + 208), a2 + 208);
  return v2;
}

//----- (005C1040) --------------------------------------------------------  // acclient.c:492672
SmartArray<Template_CG,1> *__thiscall SmartArray<Template_CG,1>::operator=(SmartArray<Template_CG,1> *this, int a2)
{
  SmartArray<Template_CG,1> *v2; // ebp@1
  int v3; // edi@3
  int v4; // ebx@3
  unsigned int v5; // ebx@5
  unsigned int v6; // ebx@6
  int v7; // ecx@7
  int v8; // edi@11
  int v10; // [sp+Ch] [bp-44h]@3
  unsigned int v11; // [sp+Ch] [bp-44h]@5
  void (__thiscall **v12)(Template_CG *, struct Archive *); // [sp+10h] [bp-40h]@6
  PSRefBufferCharData<char> *v13; // [sp+14h] [bp-3Ch]@7
  unsigned int v14; // [sp+18h] [bp-38h]@7
  int v15; // [sp+1Ch] [bp-34h]@7
  int v16; // [sp+20h] [bp-30h]@7
  int v17; // [sp+24h] [bp-2Ch]@7
  int v18; // [sp+28h] [bp-28h]@7
  int v19; // [sp+2Ch] [bp-24h]@7
  int v20; // [sp+30h] [bp-20h]@7
  int v21; // [sp+34h] [bp-1Ch]@7
  void *v22; // [sp+38h] [bp-18h]@7
  int v23; // [sp+3Ch] [bp-14h]@7
  int v24; // [sp+40h] [bp-10h]@7
  void *v25; // [sp+44h] [bp-Ch]@7
  int v26; // [sp+48h] [bp-8h]@7
  int v27; // [sp+4Ch] [bp-4h]@7

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<Template_CG,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + (*(_DWORD *)(a2 + 8) << 6);
    v10 = (int)v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        Template_CG::operator=(v10, v3);
        v3 += 64;
        v10 += 64;
      }
      while ( v3 < (unsigned int)v4 );
    }
    v5 = *(_DWORD *)(a2 + 8);
    v11 = *(_DWORD *)(a2 + 8);
    if ( v5 < v2->m_num )
    {
      v12 = &Template_CG::vftable;
      v6 = v5 << 6;
      do
      {
        v13 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v7 = (int)((char *)v2->m_data + v6);
        v14 = stru_8EF864.id;
        v15 = 0;
        v16 = 0;
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v20 = 0;
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v26 = 0;
        v27 = 0;
        Template_CG::operator=(v7, (int)&v12);
        v12 = &Template_CG::vftable;
        if ( (v26 & 0x80000000) == 0x80000000 )
          operator delete[](v25);
        if ( (v23 & 0x80000000) == 0x80000000 )
          operator delete[](v22);
        v8 = (int)&v13[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v13[-1]) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        v6 += 64;
        ++v11;
      }
      while ( v11 < v2->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}
// 79FE78: using guessed type void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *);

//----- (005C11D0) --------------------------------------------------------  // acclient.c:492763
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(Sex_CG *const *_class, SmartArray<Style_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<Style_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<Style_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  Style_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<Style_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<Style_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<Style_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<Style_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005C12A0) --------------------------------------------------------  // acclient.c:492827
char __thiscall SmartArray<ACCharGenStartArea,1>::grow(SmartArray<ACCharGenStartArea,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<ACCharGenStartArea,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ACCharGenStartArea,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](20 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x14u,
        i_nSize,
        (void *(__thiscall *)(void *))ACCharGenStartArea::ACCharGenStartArea);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              ACCharGenStartArea::operator=(v8 * 20 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              ACCharGenStartArea::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (ACCharGenStartArea *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005C1380) --------------------------------------------------------  // acclient.c:492891
int __thiscall ACCharGenData::GetStartingPosition(ACCharGenData *this, CharGenResult *cgr, Position *pos)
{
  ACCharGenData *v3; // edi@1
  unsigned int v5; // ebx@4
  int v6; // eax@5
  int v7; // eax@8
  Position *v8; // eax@8
  ACCharGenStartArea sa; // [sp+8h] [bp-14h]@5

  v3 = this;
  if ( ((int (__thiscall *)(CharGenResult *))cgr->vfptr[2].__vecDelDtor)(cgr)
    && (*(int (__thiscall **)(CharGenResult *))&cgr->vfptr[2].gap4[0])(cgr) )
  {
    pos->objcell_id = -186253286;
    pos->frame.m_fOrigin.x = pos->frame.m_fOrigin.x + 92.0;
    pos->frame.m_fOrigin.y = pos->frame.m_fOrigin.y + 35.0;
    pos->frame.m_fOrigin.z = pos->frame.m_fOrigin.z + 10.0;
    Frame::set_heading(&pos->frame, 90.0);
    return 1;
  }
  ((void (__thiscall *)(CharGenResult *))cgr->vfptr[1].UnPack)(cgr);
  v5 = v3->mStartAreaList.m_num;
  if ( ((int (__thiscall *)(CharGenResult *))cgr->vfptr[1].UnPack)(cgr) >= v5 )
    return 0;
  v6 = ((int (__thiscall *)(CharGenResult *))cgr->vfptr[1].UnPack)(cgr);
  ACCharGenStartArea::ACCharGenStartArea(&sa, &v3->mStartAreaList.m_data[v6]);
  if ( (signed int)sa.mPositionList.m_num <= 0 )
  {
    ACCharGenStartArea::~ACCharGenStartArea(&sa);
    return 0;
  }
  v7 = Random::RollDice(1, sa.mPositionList.m_num);
  v8 = &sa.mPositionList.m_data[v7 - 1];
  pos->objcell_id = v8->objcell_id;
  Frame::operator=((int)&pos->frame, (int)&v8->frame);
  ACCharGenStartArea::~ACCharGenStartArea(&sa);
  return 1;
}

//----- (005C1480) --------------------------------------------------------  // acclient.c:492931
void __thiscall Sex_CG::Sex_CG(Sex_CG *this, Sex_CG *__that)
{
  Sex_CG *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@1
  int v5; // ecx@1
  int v6; // ecx@1
  int v7; // ecx@1
  int v8; // ecx@1
  int v9; // ecx@1
  int v10; // ecx@1
  int v11; // ecx@1
  int v12; // ecx@1
  int v13; // ecx@1
  int v14; // ecx@1

  v2 = this;
  this->vfptr = (Sex_CGVtbl *)&Sex_CG::vftable;
  v3 = __that->name.m_charbuffer;
  this->name.m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v2->scaling = __that->scaling;
  v2->setup.id = __that->setup.id;
  v2->soundTable.id = __that->soundTable.id;
  v2->iconImage.id = __that->iconImage.id;
  ObjDesc::ObjDesc(&v2->objDesc, &__that->objDesc);
  v2->physicsTable.id = __that->physicsTable.id;
  v2->motionTable.id = __that->motionTable.id;
  v2->combatTable.id = __that->combatTable.id;
  v2->basePalette.id = __that->basePalette.id;
  v4 = (int)&v2->mHairColorList;
  v2->skinPalSet.id = __that->skinPalSet.id;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  SmartArray<IDClass<_tagDataID,32,0>,1>::operator=(&v2->mHairColorList, (int)&__that->mHairColorList);
  v5 = (int)&v2->mHairStyleList;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  SmartArray<HairStyle_CG,1>::operator=(&v2->mHairStyleList, (int)&__that->mHairStyleList);
  v6 = (int)&v2->mEyeColorList;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  SmartArray<IDClass<_tagDataID,32,0>,1>::operator=(&v2->mEyeColorList, (int)&__that->mEyeColorList);
  v7 = (int)&v2->mEyeStripList;
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  SmartArray<EyesStrip_CG,1>::operator=(&v2->mEyeStripList, (int)&__that->mEyeStripList);
  v8 = (int)&v2->mNoseStripList;
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = 0;
  *(_DWORD *)(v8 + 8) = 0;
  SmartArray<FaceStrip_CG,1>::operator=(&v2->mNoseStripList, (int)&__that->mNoseStripList);
  v9 = (int)&v2->mMouthStripList;
  *(_DWORD *)v9 = 0;
  *(_DWORD *)(v9 + 4) = 0;
  *(_DWORD *)(v9 + 8) = 0;
  SmartArray<FaceStrip_CG,1>::operator=(&v2->mMouthStripList, (int)&__that->mMouthStripList);
  v10 = (int)&v2->mHeadgearList;
  *(_DWORD *)v10 = 0;
  *(_DWORD *)(v10 + 4) = 0;
  *(_DWORD *)(v10 + 8) = 0;
  SmartArray<Style_CG,1>::operator=(&v2->mHeadgearList, (int)&__that->mHeadgearList);
  v11 = (int)&v2->mShirtList;
  *(_DWORD *)v11 = 0;
  *(_DWORD *)(v11 + 4) = 0;
  *(_DWORD *)(v11 + 8) = 0;
  SmartArray<Style_CG,1>::operator=(&v2->mShirtList, (int)&__that->mShirtList);
  v12 = (int)&v2->mPantsList;
  *(_DWORD *)v12 = 0;
  *(_DWORD *)(v12 + 4) = 0;
  *(_DWORD *)(v12 + 8) = 0;
  SmartArray<Style_CG,1>::operator=(&v2->mPantsList, (int)&__that->mPantsList);
  v13 = (int)&v2->mFootwearList;
  *(_DWORD *)v13 = 0;
  *(_DWORD *)(v13 + 4) = 0;
  *(_DWORD *)(v13 + 8) = 0;
  SmartArray<Style_CG,1>::operator=(&v2->mFootwearList, (int)&__that->mFootwearList);
  v14 = (int)&v2->mClothingColorsList;
  *(_DWORD *)v14 = 0;
  *(_DWORD *)(v14 + 4) = 0;
  *(_DWORD *)(v14 + 8) = 0;
  SmartArray<int,1>::operator=(
    (SmartArray<QuickButton *,1> *)&v2->mClothingColorsList,
    (int)&__that->mClothingColorsList);
}
// 79FE7C: using guessed type void (__thiscall *Sex_CG::vftable)(Sex_CG *this, struct Archive *);

//----- (005C1600) --------------------------------------------------------  // acclient.c:493023
void __thiscall Sex_CG::Serialize(Sex_CG *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  Sex_CG *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17
  unsigned int v9; // eax@21
  unsigned int v10; // eax@25
  unsigned int v11; // eax@29
  unsigned int v12; // eax@33

  v2 = io_archive;
  v3 = this;
  PStringBase<char>::Serialize(&this->name, io_archive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->scaling;
    else
      v3->scaling = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->setup.id;
    else
      v3->setup.id = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v6 = v3->soundTable.id;
    else
      v3->soundTable.id = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(v2, 4u);
  v7 = Archive::GetBytes(v2, 4u);
  if ( v7 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v7 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v3->basePalette.id;
    else
      v3->basePalette.id = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(v2, 4u);
  v9 = Archive::GetBytes(v2, 4u);
  if ( v9 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v9 = v3->skinPalSet.id;
    else
      v3->skinPalSet.id = *(_DWORD *)v9;
  }
  Archive::CheckAlignment(v2, 4u);
  v10 = Archive::GetBytes(v2, 4u);
  if ( v10 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v10 = v3->physicsTable.id;
    else
      v3->physicsTable.id = *(_DWORD *)v10;
  }
  Archive::CheckAlignment(v2, 4u);
  v11 = Archive::GetBytes(v2, 4u);
  if ( v11 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v11 = v3->motionTable.id;
    else
      v3->motionTable.id = *(_DWORD *)v11;
  }
  Archive::CheckAlignment(v2, 4u);
  v12 = Archive::GetBytes(v2, 4u);
  if ( v12 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v12 = v3->combatTable.id;
    else
      v3->combatTable.id = *(_DWORD *)v12;
  }
  SB_AsPackObj<1>::Serialize((FaceStrip_CG *const *)&io_archive, &v3->objDesc, v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mHairColorList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mHairStyleList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mEyeColorList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mEyeStripList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mNoseStripList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mMouthStripList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mHeadgearList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mShirtList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mPantsList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Sex_CG *const *)&io_archive,
    &v3->mFootwearList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Template_CG *const *)&io_archive,
    (SmartArray<int,1> *)&v3->mClothingColorsList,
    v2);
}

//----- (005C1850) --------------------------------------------------------  // acclient.c:493169
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,HeritageGroup_CG> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,HeritageGroup_CG> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7E76D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable)(void *, char);

//----- (005C18E0) --------------------------------------------------------  // acclient.c:493202
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,Sex_CG> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,Sex_CG> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79FE74: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable)(void *, char);

//----- (005C1970) --------------------------------------------------------  // acclient.c:493235
char __thiscall SmartArray<ACCharGenStartArea,1>::SetNElements(SmartArray<ACCharGenStartArea,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<ACCharGenStartArea,1> *v3; // ebp@1
  const unsigned int v4; // esi@1
  unsigned int v5; // eax@3
  char result; // al@5
  PSRefBufferCharData<char> *v7; // edi@9
  volatile LONG *v8; // ebx@9
  int v9; // esi@9
  PSRefBufferCharData<char> *v10; // eax@9
  bool v11; // cf@14
  unsigned int i; // [sp+8h] [bp-1Ch]@7
  int v13; // [sp+Ch] [bp-18h]@10
  ACCharGenStartArea v14; // [sp+10h] [bp-14h]@9
  const unsigned int i_bGrowExactlya; // [sp+2Ch] [bp+8h]@8

  v3 = this;
  v4 = i_nSize;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    i = i_nSize;
    if ( i_nSize < this->m_num )
    {
      i_bGrowExactlya = i_nSize;
      do
      {
        v7 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
        v14.vfptr = (ACCharGenStartAreaVtbl *)&ACCharGenStartArea::vftable;
        v14.name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v9 = (int)&v3->m_data[i_bGrowExactlya];
        v14.mPositionList.m_data = 0;
        v14.mPositionList.m_sizeAndDeallocate = 0;
        v14.mPositionList.m_num = 0;
        v10 = *(PSRefBufferCharData<char> **)(v9 + 4);
        if ( v10 != v7 )
        {
          v13 = (int)&v10[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v13 )
            (**(void (__stdcall ***)(_DWORD))v13)(1);
          *(_DWORD *)(v9 + 4) = v7;
          InterlockedIncrement(v8);
        }
        SmartArray<Position,1>::operator=((SmartArray<Position,1> *)(v9 + 8), (int)&v14.mPositionList);
        ACCharGenStartArea::~ACCharGenStartArea(&v14);
        v11 = i++ + 1 < v3->m_num;
        ++i_bGrowExactlya;
      }
      while ( v11 );
      v4 = i_nSize;
    }
    goto LABEL_16;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<ACCharGenStartArea,1>::grow(v3, v5);
  if ( result )
  {
LABEL_16:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}
// 7E76D4: using guessed type void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *);

//----- (005C1A80) --------------------------------------------------------  // acclient.c:493305
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(HeritageGroup_CG *const *_class, SmartArray<Template_CG,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<Template_CG,1> *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<Template_CG,1> *v7; // edi@2
  unsigned int v8; // eax@4
  Template_CG *v9; // edi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<Template_CG,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<Template_CG,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<Template_CG,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<Template_CG,1>::shrink(v4);
      }
    }
  }
}

//----- (005C1B50) --------------------------------------------------------  // acclient.c:493369
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this)
{
  HashTableData<unsigned long,Sex_CG> **v1; // edx@2
  HashTableData<unsigned long,Sex_CG> **v2; // eax@3
  HashTableData<unsigned long,Sex_CG> **v3; // eax@4
  HashTableData<unsigned long,Sex_CG> **v4; // edi@5
  HashTableData<unsigned long,Sex_CG> *v5; // edx@5
  HashTableData<unsigned long,Sex_CG> *v6; // eax@7
  HashTableData<unsigned long,Sex_CG> *v7; // esi@8

  if ( this->m_numElements )
  {
    do
    {
      v1 = &this->m_buckets[this->m_numBuckets];
      if ( this->m_firstInterestingBucket == v1 )
      {
LABEL_5:
        v4 = 0;
        v5 = 0;
      }
      else
      {
        while ( 1 )
        {
          v2 = this->m_firstInterestingBucket;
          if ( *v2 )
            break;
          v3 = v2 + 1;
          this->m_firstInterestingBucket = v3;
          if ( v3 == v1 )
            goto LABEL_5;
        }
        v5 = *this->m_firstInterestingBucket;
        v4 = this->m_firstInterestingBucket;
      }
      v6 = *v4;
      if ( *v4 == v5 )
        goto LABEL_15;
      do
      {
        v7 = v6;
        v6 = v6->m_hashNext;
      }
      while ( v6 != v5 );
      if ( v7 )
        v7->m_hashNext = v6->m_hashNext;
      else
LABEL_15:
        *v4 = v6->m_hashNext;
    }
    while ( this->m_numElements-- != 1 );
  }
}

//----- (005C1BC0) --------------------------------------------------------  // acclient.c:493425
Sex_CG *__thiscall HeritageGroup_CG::GetSX(HeritageGroup_CG *this, Sex_CG *result, unsigned int gender)
{
  HeritageGroup_CG *v3; // esi@1
  HashTableData<unsigned long,Sex_CG> *v4; // eax@1
  Sex_CG sex; // [sp+4h] [bp-DCh]@1

  v3 = this;
  Sex_CG::Sex_CG(&sex);
  v4 = v3->mGenderList.m_intrusiveTable.m_buckets[gender % v3->mGenderList.m_intrusiveTable.m_numBuckets];
  if ( v4 )
  {
    while ( v4->m_hashKey != gender )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        goto LABEL_7;
    }
    if ( v4 )
      Sex_CG::operator=((int)&sex, (int)&v4->m_data);
  }
LABEL_7:
  Sex_CG::Sex_CG(result, &sex);
  Sex_CG::~Sex_CG(&sex);
  return result;
}

//----- (005C1C40) --------------------------------------------------------  // acclient.c:493452
void __cdecl SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(ACCharGenData *const *_class, SmartArray<ACCharGenStartArea,1> *_obj, Archive *_arc)
{
  Archive *v3; // ebp@1
  SmartArray<ACCharGenStartArea,1> *v4; // edi@1
  char v5; // bl@1
  unsigned int v6; // eax@2
  SmartArray<ACCharGenStartArea,1> *v7; // esi@2
  unsigned int v8; // eax@4
  ACCharGenStartArea *v9; // esi@9

  v3 = _arc;
  v4 = _obj;
  _obj = (SmartArray<ACCharGenStartArea,1> *)_obj->m_num;
  SB_As32Bit_Compressed::Serialize((const int *)_class, (unsigned int *)&_obj, _arc);
  v5 = 0;
  if ( ~LOBYTE(v3->m_flags) & 1 )
  {
    v6 = Archive::GetSizeLeft(v3);
    v7 = _obj;
    if ( (unsigned int)_obj > v6 )
    {
      Archive::RaiseError(v3);
      return;
    }
    v8 = v4->m_num;
    if ( (unsigned int)_obj <= v8 )
    {
      if ( (unsigned int)_obj < v8 )
      {
        v4->m_num = (unsigned int)_obj;
        SmartArray<ACCharGenStartArea,1>::shrink(v4);
      }
    }
    else
    {
      SmartArray<ACCharGenStartArea,1>::grow(v4, (unsigned int)_obj);
      v4->m_num = (unsigned int)v7;
    }
    v5 = 1;
  }
  v9 = v4->m_data;
  if ( v4->m_data != &v4->m_data[v4->m_num] )
  {
    while ( 1 )
    {
      v9->vfptr->Serialize(v9, v3);
      if ( (v3->m_flags >> 2) & 1 )
        break;
      ++v9;
      if ( v9 == &v4->m_data[v4->m_num] )
        return;
    }
    if ( v5 )
    {
      if ( v4->m_num )
      {
        v4->m_num = 0;
        SmartArray<ACCharGenStartArea,1>::shrink(v4);
      }
    }
  }
}

//----- (005C1D10) --------------------------------------------------------  // acclient.c:493516
void __cdecl _SerializeIntrusiveHashTable____PAVHeritageGroup_CG__V__IntrusiveHashTable_KPAV__HashTableData_KVSex_CG_____0A___PAV__HashTableData_KVSex_CG____USB_HashData___SB_Hash_USB_Default__U1__1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVHeritageGroup_CG__AAV__IntrusiveHashTable_KPAV__HashTableData_KVSex_CG_____0A___AAVArchive___Z(HeritageGroup_CG *const *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // edi@32
  unsigned int v19; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear(io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        v11->m_data.vfptr->Serialize(&v11->m_data, v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_43:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0xE4u);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            Sex_CG::Sex_CG((Sex_CG *)((char *)v17 + 8));
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v19;
          }
          (**((void (__thiscall ***)(_DWORD, _DWORD))v18 + 2))((char *)v18 + 8, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_43;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (005C1F30) --------------------------------------------------------  // acclient.c:493669
int __thiscall HashTable<unsigned long,Sex_CG,0>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // ebx@1
  unsigned int *v4; // ebp@2
  unsigned int *v5; // eax@2
  void *v6; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@4
  void *v9; // esi@7
  unsigned int v10; // ebx@10
  int v11; // ecx@10
  int v12; // edx@11
  int v13; // eax@14
  HashTableData<unsigned long,HeritageGroup_CG> **v14; // ecx@18
  HashTableData<unsigned long,HeritageGroup_CG> **v15; // eax@19
  int v17; // [sp+8h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v19; // [sp+18h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v17 = this;
  if ( this == __val )
    return v3;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)(this + 4));
  v4 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v5 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v5 == v4 )
    --v5;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::resize_internal(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v3 + 4),
    *v5);
  v6 = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v8 = v7->m_currElement;
  v19 = v7->m_currHashTable;
  result.m_currBucket = v7->m_currBucket;
  if ( !v8 )
    return v3;
  while ( 1 )
  {
    v9 = operator new(0xE4u);
    if ( v9 )
    {
      *(_DWORD *)v9 = v8->m_hashKey;
      *((_DWORD *)v9 + 1) = 0;
      Sex_CG::Sex_CG((Sex_CG *)((char *)v9 + 8), (Sex_CG *)&v8->m_data);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)(v3 + 108);
    v11 = *(_DWORD *)v9 % v10;
    if ( !v6 )
      goto LABEL_14;
    v12 = *(_DWORD *)v6 % v10;
    if ( v11 != v12 )
    {
      if ( v11 <= (unsigned int)v12 )
        goto LABEL_17;
LABEL_14:
      v13 = *(_DWORD *)(v17 + 100) + 4 * v11;
      *(_DWORD *)v13 = v9;
      if ( !v6 )
        *(_DWORD *)(v17 + 104) = v13;
      goto LABEL_16;
    }
    *((_DWORD *)v6 + 1) = v9;
LABEL_16:
    ++*(_DWORD *)(v17 + 112);
LABEL_17:
    v8 = v8->m_hashNext;
    v6 = v9;
    if ( !v8 )
      break;
LABEL_6:
    v3 = v17;
  }
  v14 = &v19->m_buckets[v19->m_numBuckets];
  while ( 1 )
  {
    v15 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v14 )
      return v17;
    if ( *v15 )
    {
      v8 = *v15;
      if ( *v15 )
        goto LABEL_6;
      return v17;
    }
  }
}

//----- (005C2080) --------------------------------------------------------  // acclient.c:493770
void __thiscall HeritageGroup_CG::HeritageGroup_CG(HeritageGroup_CG *this)
{
  HeritageGroup_CG *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (HeritageGroup_CGVtbl *)&HeritageGroup_CG::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->iconImage.id = stru_8EF864.id;
  v1->setupID.id = stru_8EF864.id;
  v1->environmentSetupID.id = stru_8EF864.id;
  v1->numAttributeCredits = 0;
  v1->numSkillCredits = 0;
  v1->mPrimaryStartAreaList.m_data = 0;
  v1->mPrimaryStartAreaList.m_sizeAndDeallocate = 0;
  v1->mPrimaryStartAreaList.m_num = 0;
  v1->mSecondaryStartAreaList.m_data = 0;
  v1->mSecondaryStartAreaList.m_sizeAndDeallocate = 0;
  v1->mSecondaryStartAreaList.m_num = 0;
  v1->mSkillList.m_data = 0;
  v1->mSkillList.m_sizeAndDeallocate = 0;
  v1->mSkillList.m_num = 0;
  v1->mTemplateList.m_data = 0;
  v1->mTemplateList.m_sizeAndDeallocate = 0;
  v1->mTemplateList.m_num = 0;
  v1->mGenderList.vfptr = (HashTable<unsigned long,Sex_CG,0>Vtbl *)&HashTable<unsigned long,Sex_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>(
    &v1->mGenderList.m_intrusiveTable,
    0x17u);
}
// 79FE80: using guessed type int (__thiscall *HashTable<unsigned long,Sex_CG,0>::vftable)(void *, char);
// 79FE84: using guessed type void (__thiscall *HeritageGroup_CG::vftable)(HeritageGroup_CG *this, struct Archive *);

//----- (005C2100) --------------------------------------------------------  // acclient.c:493806
void __thiscall HeritageGroup_CG::Serialize(HeritageGroup_CG *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  HeritageGroup_CG *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17

  v2 = io_archive;
  v3 = this;
  PStringBase<char>::Serialize(&this->name, io_archive);
  Archive::CheckAlignment(v2, 4u);
  v4 = Archive::GetBytes(v2, 4u);
  if ( v4 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v4 = v3->iconImage.id;
    else
      v3->iconImage.id = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v3->setupID.id;
    else
      v3->setupID.id = *(_DWORD *)v5;
  }
  Archive::CheckAlignment(v2, 4u);
  v6 = Archive::GetBytes(v2, 4u);
  if ( v6 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v6 = v3->environmentSetupID.id;
    else
      v3->environmentSetupID.id = *(_DWORD *)v6;
  }
  Archive::CheckAlignment(v2, 4u);
  v7 = Archive::GetBytes(v2, 4u);
  if ( v7 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v7 = v3->numAttributeCredits;
    else
      v3->numAttributeCredits = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(v2, 4u);
  v8 = Archive::GetBytes(v2, 4u);
  if ( v8 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v8 = v3->numSkillCredits;
    else
      v3->numSkillCredits = *(_DWORD *)v8;
  }
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Template_CG *const *)&io_archive,
    (SmartArray<int,1> *)&v3->mPrimaryStartAreaList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (Template_CG *const *)&io_archive,
    (SmartArray<int,1> *)&v3->mSecondaryStartAreaList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (HeritageGroup_CG *const *)&io_archive,
    &v3->mSkillList,
    v2);
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (HeritageGroup_CG *const *)&io_archive,
    &v3->mTemplateList,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::delete_contents(&v3->mGenderList.m_intrusiveTable);
  _SerializeIntrusiveHashTable____PAVHeritageGroup_CG__V__IntrusiveHashTable_KPAV__HashTableData_KVSex_CG_____0A___PAV__HashTableData_KVSex_CG____USB_HashData___SB_Hash_USB_Default__U1__1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVHeritageGroup_CG__AAV__IntrusiveHashTable_KPAV__HashTableData_KVSex_CG_____0A___AAVArchive___Z(
    (HeritageGroup_CG *const *)&io_archive,
    &v3->mGenderList.m_intrusiveTable,
    v2);
}

//----- (005C2240) --------------------------------------------------------  // acclient.c:493889
int __thiscall HeritageGroup_CG::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v2 + 28), a2 + 28);
  SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v2 + 40), a2 + 40);
  SmartArray<Skill_CG,1>::operator=((SmartArray<Skill_CG,1> *)(v2 + 52), a2 + 52);
  SmartArray<Template_CG,1>::operator=((SmartArray<Template_CG,1> *)(v2 + 64), a2 + 64);
  HashTable<unsigned long,Sex_CG,0>::operator=(v2 + 76, a2 + 76);
  return v2;
}

//----- (005C22E0) --------------------------------------------------------  // acclient.c:493921
void __thiscall HeritageGroup_CG::HeritageGroup_CG(HeritageGroup_CG *this, HeritageGroup_CG *__that)
{
  HeritageGroup_CG *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@1
  int v5; // ecx@1
  int v6; // ecx@1
  int v7; // ecx@1

  v2 = this;
  this->vfptr = (HeritageGroup_CGVtbl *)&HeritageGroup_CG::vftable;
  v3 = __that->name.m_charbuffer;
  this->name.m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v2->iconImage.id = __that->iconImage.id;
  v2->setupID.id = __that->setupID.id;
  v2->environmentSetupID.id = __that->environmentSetupID.id;
  v2->numAttributeCredits = __that->numAttributeCredits;
  v2->numSkillCredits = __that->numSkillCredits;
  v4 = (int)&v2->mPrimaryStartAreaList;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  SmartArray<int,1>::operator=(
    (SmartArray<QuickButton *,1> *)&v2->mPrimaryStartAreaList,
    (int)&__that->mPrimaryStartAreaList);
  v5 = (int)&v2->mSecondaryStartAreaList;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  SmartArray<int,1>::operator=(
    (SmartArray<QuickButton *,1> *)&v2->mSecondaryStartAreaList,
    (int)&__that->mSecondaryStartAreaList);
  v6 = (int)&v2->mSkillList;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  SmartArray<Skill_CG,1>::operator=(&v2->mSkillList, (int)&__that->mSkillList);
  v7 = (int)&v2->mTemplateList;
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = 0;
  SmartArray<Template_CG,1>::operator=(&v2->mTemplateList, (int)&__that->mTemplateList);
  v2->mGenderList.vfptr = (HashTable<unsigned long,Sex_CG,0>Vtbl *)&HashTable<unsigned long,Sex_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>(
    &v2->mGenderList.m_intrusiveTable,
    __that->mGenderList.m_intrusiveTable.m_numBuckets);
  HashTable<unsigned long,Sex_CG,0>::operator=((int)&v2->mGenderList, (unsigned int)&__that->mGenderList);
}
// 79FE80: using guessed type int (__thiscall *HashTable<unsigned long,Sex_CG,0>::vftable)(void *, char);
// 79FE84: using guessed type void (__thiscall *HeritageGroup_CG::vftable)(HeritageGroup_CG *this, struct Archive *);

//----- (005C23A0) --------------------------------------------------------  // acclient.c:493974
HeritageGroup_CG *__thiscall ACCharGenData::GetHG(ACCharGenData *this, HeritageGroup_CG *result, unsigned int heritage)
{
  ACCharGenData *v3; // esi@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // eax@1
  HeritageGroup_CG hg; // [sp+4h] [bp-C0h]@1

  v3 = this;
  HeritageGroup_CG::HeritageGroup_CG(&hg);
  v4 = v3->mHeritageGroupList.m_intrusiveTable.m_buckets[heritage % v3->mHeritageGroupList.m_intrusiveTable.m_numBuckets];
  if ( v4 )
  {
    while ( v4->m_hashKey != heritage )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        goto LABEL_7;
    }
    if ( v4 )
      HeritageGroup_CG::operator=((int)&hg, (int)&v4->m_data);
  }
LABEL_7:
  HeritageGroup_CG::HeritageGroup_CG(result, &hg);
  HeritageGroup_CG::~HeritageGroup_CG(&hg);
  return result;
}

//----- (005C2420) --------------------------------------------------------  // acclient.c:494001
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edx@5
  HashTableData<unsigned long,HeritageGroup_CG> *v6; // edi@5
  HashTableData<unsigned long,HeritageGroup_CG> *v7; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,HeritageGroup_CG> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,HeritageGroup_CG> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      HeritageGroup_CG::~HeritageGroup_CG(&v6->m_data);
      operator delete(v6);
    }
  }
}

//----- (005C24B0) --------------------------------------------------------  // acclient.c:494061
void __cdecl _SerializeIntrusiveHashTable____PAVACCharGenData__V__IntrusiveHashTable_KPAV__HashTableData_KVHeritageGroup_CG_____0A___PAV__HashTableData_KVHeritageGroup_CG____USB_HashData___SB_Hash_USB_Default__U1__1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVACCharGenData__AAV__IntrusiveHashTable_KPAV__HashTableData_KVHeritageGroup_CG_____0A___AAVArchive___Z(ACCharGenData *const *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@30
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@31
  unsigned int v16; // ebp@31
  void *v17; // eax@32
  void *v18; // edi@32
  unsigned int v19; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(io_object, &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        v11->m_data.vfptr->Serialize(&v11->m_data, v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_43:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0xC8u);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            HeritageGroup_CG::HeritageGroup_CG((HeritageGroup_CG *)((char *)v17 + 8));
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v19;
          }
          (**((void (__thiscall ***)(_DWORD, _DWORD))v18 + 2))((char *)v18 + 8, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_43;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (005C26D0) --------------------------------------------------------  // acclient.c:494212
int __thiscall ACCharGenData::GetSkillTrainedCost(ACCharGenData *this, int _skillID, unsigned int heritage, unsigned int gender)
{
  unsigned int v4; // eax@1
  char *v5; // ecx@2
  int v6; // eax@5
  unsigned int v7; // edi@6
  int v8; // esi@7
  int v9; // edx@8
  int v10; // esi@12
  HeritageGroup_CG hg; // [sp+Ch] [bp-19Ch]@1
  Sex_CG sex; // [sp+CCh] [bp-DCh]@1

  ACCharGenData::GetHG(this, &hg, heritage);
  HeritageGroup_CG::GetSX(&hg, &sex, gender);
  v4 = 0;
  if ( hg.mSkillList.m_num )
  {
    v5 = (char *)&hg.mSkillList.m_data->skillNum;
    while ( *(_DWORD *)v5 != _skillID )
    {
      ++v4;
      v5 += 16;
      if ( v4 >= hg.mSkillList.m_num )
        goto LABEL_5;
    }
    v10 = hg.mSkillList.m_data[v4].normalCost;
    goto LABEL_17;
  }
LABEL_5:
  v6 = DBCache::GetFromEnumStatic(4, 2, 0x10000004u);
  if ( !v6 )
  {
LABEL_15:
    Sex_CG::~Sex_CG(&sex);
    HeritageGroup_CG::~HeritageGroup_CG(&hg);
    return -1;
  }
  v7 = *(_DWORD *)(v6 + 68);
  if ( !v7 )
    goto LABEL_14;
  v8 = *(_DWORD *)(v6 + 64);
  if ( !v8 )
    goto LABEL_14;
  v9 = *(_DWORD *)(v8 + 4 * (_skillID % v7));
  if ( !v9 )
    goto LABEL_14;
  while ( _skillID != *(_DWORD *)v9 )
  {
    v9 = *(_DWORD *)(v9 + 96);
    if ( !v9 )
      goto LABEL_14;
  }
  if ( v9 == -8 )
  {
LABEL_14:
    (*(void (**)(void))(*(_DWORD *)v6 + 20))();
    goto LABEL_15;
  }
  v10 = *(_DWORD *)(v9 + 24);
LABEL_17:
  Sex_CG::~Sex_CG(&sex);
  HeritageGroup_CG::~HeritageGroup_CG(&hg);
  return v10;
}

//----- (005C27D0) --------------------------------------------------------  // acclient.c:494278
int __thiscall ACCharGenData::GetSkillSpecializedCost(ACCharGenData *this, int _skillID, unsigned int heritage, unsigned int gender)
{
  unsigned int v4; // eax@1
  char *v5; // ecx@2
  int v6; // eax@5
  unsigned int v7; // edi@6
  int v8; // esi@7
  int v9; // edx@8
  int v10; // esi@12
  HeritageGroup_CG hg; // [sp+Ch] [bp-19Ch]@1
  Sex_CG sex; // [sp+CCh] [bp-DCh]@1

  ACCharGenData::GetHG(this, &hg, heritage);
  HeritageGroup_CG::GetSX(&hg, &sex, gender);
  v4 = 0;
  if ( hg.mSkillList.m_num )
  {
    v5 = (char *)&hg.mSkillList.m_data->skillNum;
    while ( *(_DWORD *)v5 != _skillID )
    {
      ++v4;
      v5 += 16;
      if ( v4 >= hg.mSkillList.m_num )
        goto LABEL_5;
    }
    v10 = hg.mSkillList.m_data[v4].primaryCost;
    goto LABEL_17;
  }
LABEL_5:
  v6 = DBCache::GetFromEnumStatic(4, 2, 0x10000004u);
  if ( !v6 )
  {
LABEL_15:
    Sex_CG::~Sex_CG(&sex);
    HeritageGroup_CG::~HeritageGroup_CG(&hg);
    return -1;
  }
  v7 = *(_DWORD *)(v6 + 68);
  if ( !v7 )
    goto LABEL_14;
  v8 = *(_DWORD *)(v6 + 64);
  if ( !v8 )
    goto LABEL_14;
  v9 = *(_DWORD *)(v8 + 4 * (_skillID % v7));
  if ( !v9 )
    goto LABEL_14;
  while ( _skillID != *(_DWORD *)v9 )
  {
    v9 = *(_DWORD *)(v9 + 96);
    if ( !v9 )
      goto LABEL_14;
  }
  if ( v9 == -8 )
  {
LABEL_14:
    (*(void (**)(void))(*(_DWORD *)v6 + 20))();
    goto LABEL_15;
  }
  v10 = *(_DWORD *)(v9 + 28);
LABEL_17:
  Sex_CG::~Sex_CG(&sex);
  HeritageGroup_CG::~HeritageGroup_CG(&hg);
  return v10;
}

//----- (005C28D0) --------------------------------------------------------  // acclient.c:494344
int __thiscall ACCharGenData::GenerateBaseAppearanceData(ACCharGenData *this, ACCharGenResult *_cgr, CharAppearanceData *_cad, ObjDesc *_objDesc)
{
  unsigned int v4; // eax@1
  unsigned int v5; // eax@1
  HairStyle_CG *v6; // eax@1
  AnimPartChange *v7; // eax@1
  EyesStrip_CG *v8; // edi@8
  char *v9; // ecx@9
  TextureMapChange *v10; // eax@10
  CharAppearanceData *v11; // edi@16
  FaceStrip_CG *v12; // eax@18
  ObjDesc *v13; // ecx@18
  TextureMapChange *v14; // eax@19
  FaceStrip_CG *v15; // eax@23
  ObjDesc *v16; // ecx@23
  TextureMapChange *v17; // eax@24
  QualifiedDataID *v18; // eax@28
  int v19; // edi@28
  QualifiedDataID *v20; // eax@29
  int v21; // edi@29
  int result; // eax@30
  int use_second_texture; // [sp+10h] [bp-2C4h]@5
  Subpalette eyeSubPal; // [sp+14h] [bp-2C0h]@1
  Subpalette skinSubPal; // [sp+2Ch] [bp-2A8h]@1
  Subpalette hairSubPal; // [sp+44h] [bp-290h]@1
  FaceStrip_CG curFS; // [sp+5Ch] [bp-278h]@18
  QualifiedDataID v28; // [sp+90h] [bp-244h]@28
  HairStyle_CG curHS; // [sp+98h] [bp-23Ch]@1
  EyesStrip_CG curES; // [sp+D4h] [bp-200h]@8
  Sex_CG curSX; // [sp+138h] [bp-19Ch]@1
  HeritageGroup_CG curHG; // [sp+214h] [bp-C0h]@1

  skinSubPal.subID.id = stru_8EF864.id;
  hairSubPal.subID.id = stru_8EF864.id;
  eyeSubPal.subID.id = stru_8EF864.id;
  v4 = _cgr->heritageGroup;
  skinSubPal.vfptr = (PackObjVtbl *)&Subpalette::vftable;
  hairSubPal.vfptr = (PackObjVtbl *)&Subpalette::vftable;
  eyeSubPal.vfptr = (PackObjVtbl *)&Subpalette::vftable;
  skinSubPal.offset = 0;
  skinSubPal.numcolors = 0;
  skinSubPal.prev = 0;
  skinSubPal.next = 0;
  hairSubPal.offset = 0;
  hairSubPal.numcolors = 0;
  hairSubPal.prev = 0;
  hairSubPal.next = 0;
  eyeSubPal.offset = 0;
  eyeSubPal.numcolors = 0;
  eyeSubPal.prev = 0;
  eyeSubPal.next = 0;
  ACCharGenData::GetHG(this, &curHG, v4);
  HeritageGroup_CG::GetSX(&curHG, &curSX, _cgr->gender);
  v5 = curSX.basePalette.id;
  _objDesc->paletteID.id = curSX.basePalette.id;
  _cad->base_palette.id = v5;
  ObjDesc::operator+=(_objDesc, &curSX.objDesc);
  v6 = &curSX.mHairStyleList.m_data[_cgr->hairStyle];
  curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
  curHS.iconImage.id = v6->iconImage.id;
  curHS.bald = v6->bald;
  curHS.alternateSetup.id = v6->alternateSetup.id;
  ObjDesc::ObjDesc(&curHS.objDesc, &v6->objDesc);
  ObjDesc::operator+=(_objDesc, &curHS.objDesc);
  v7 = ObjDesc::GetAnimPartChange(&curHS.objDesc, 0);
  if ( v7 )
  {
    if ( _cgr->heritageGroup == 6 )
      _cad->head_object.id = stru_8EF864.id;
    else
      _cad->head_object.id = v7->part_id.id;
  }
  use_second_texture = 0;
  if ( curHS.alternateSetup.id == UNDEAD_MALE_SKELETON_SETUP_1.id
    || curHS.alternateSetup.id == UNDEAD_FEMALE_SKELETON_SETUP_1.id )
    use_second_texture = 1;
  v8 = &curSX.mEyeStripList.m_data[_cgr->eyesStrip];
  curES.vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
  curES.iconImage.id = v8->iconImage.id;
  curES.iconImage_Bald.id = v8->iconImage_Bald.id;
  ObjDesc::ObjDesc(&curES.objDesc, &v8->objDesc);
  ObjDesc::ObjDesc(&curES.objDesc_Bald, &v8->objDesc_Bald);
  if ( curHS.bald )
  {
    ObjDesc::operator+=(_objDesc, &curES.objDesc_Bald);
    v9 = (char *)&curES.objDesc_Bald;
    if ( !use_second_texture )
      goto LABEL_15;
    v10 = ObjDesc::GetTextureMapChange(&curES.objDesc_Bald, 1);
    if ( !v10 )
    {
      v9 = (char *)&curES.objDesc_Bald;
      goto LABEL_15;
    }
LABEL_16:
    v11 = _cad;
    _cad->eyes_texture.id = v10->new_tex_id.id;
    _cad->default_eyes_texture.id = v10->old_tex_id.id;
    goto LABEL_18;
  }
  ObjDesc::operator+=(_objDesc, &curES.objDesc);
  v9 = (char *)&curES.objDesc;
  if ( use_second_texture )
  {
    v10 = ObjDesc::GetTextureMapChange(&curES.objDesc, 1);
    if ( v10 )
      goto LABEL_16;
    v9 = (char *)&curES.objDesc;
  }
LABEL_15:
  v10 = ObjDesc::GetTextureMapChange((ObjDesc *)v9, 0);
  if ( v10 )
    goto LABEL_16;
  v11 = _cad;
LABEL_18:
  v12 = &curSX.mNoseStripList.m_data[_cgr->noseStrip];
  curFS.vfptr = (FaceStrip_CGVtbl *)&FaceStrip_CG::vftable;
  curFS.iconImage.id = v12->iconImage.id;
  ObjDesc::ObjDesc(&curFS.objDesc, &v12->objDesc);
  ObjDesc::operator+=(_objDesc, &curFS.objDesc);
  v13 = &curFS.objDesc;
  if ( !use_second_texture )
    goto LABEL_21;
  v14 = ObjDesc::GetTextureMapChange(&curFS.objDesc, 1);
  if ( !v14 )
  {
    v13 = &curFS.objDesc;
LABEL_21:
    v14 = ObjDesc::GetTextureMapChange(v13, 0);
    if ( !v14 )
      goto LABEL_23;
  }
  v11->nose_texture.id = v14->new_tex_id.id;
  v11->default_nose_texture.id = v14->old_tex_id.id;
LABEL_23:
  v15 = &curSX.mMouthStripList.m_data[_cgr->mouthStrip];
  curFS.iconImage.id = v15->iconImage.id;
  ObjDesc::operator=(&curFS.objDesc, &v15->objDesc);
  ObjDesc::operator+=(_objDesc, &curFS.objDesc);
  v16 = &curFS.objDesc;
  if ( use_second_texture )
  {
    v17 = ObjDesc::GetTextureMapChange(&curFS.objDesc, 1);
    if ( v17 )
    {
LABEL_27:
      v11->mouth_texture.id = v17->new_tex_id.id;
      v11->default_mouth_texture.id = v17->old_tex_id.id;
      goto LABEL_28;
    }
    v16 = &curFS.objDesc;
  }
  v17 = ObjDesc::GetTextureMapChange(v16, 0);
  if ( v17 )
    goto LABEL_27;
LABEL_28:
  QualifiedDataID::QualifiedDataID(&v28, curSX.skinPalSet, 0x18u);
  v19 = DBObj::Get(v18);
  if ( v19
    && (skinSubPal.subID.id = PalSet::GetPaletteID(
                                (PalSet *)v19,
                                (IDClass<_tagDataID,32,0> *)&use_second_texture,
                                _cgr->skinShade)->id,
        skinSubPal.offset = 0,
        skinSubPal.numcolors = 192,
        ObjDesc::AddSubpalette(_objDesc, &skinSubPal),
        _cad->skin_palette.id = skinSubPal.subID.id,
        (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 20))(v19),
        QualifiedDataID::QualifiedDataID(&v28, curSX.mHairColorList.m_data[_cgr->hairColor], 0x18u),
        (v21 = DBObj::Get(v20)) != 0) )
  {
    hairSubPal.subID.id = PalSet::GetPaletteID(
                            (PalSet *)v21,
                            (IDClass<_tagDataID,32,0> *)&use_second_texture,
                            _cgr->hairShade)->id;
    hairSubPal.offset = 192;
    hairSubPal.numcolors = 64;
    ObjDesc::AddSubpalette(_objDesc, &hairSubPal);
    _cad->hair_palette.id = hairSubPal.subID.id;
    (*(void (__thiscall **)(int))(*(_DWORD *)v21 + 20))(v21);
    eyeSubPal.subID.id = curSX.mEyeColorList.m_data[_cgr->eyeColor].id;
    eyeSubPal.offset = 256;
    eyeSubPal.numcolors = 64;
    ObjDesc::AddSubpalette(_objDesc, &eyeSubPal);
    _cad->eyes_palette.id = eyeSubPal.subID.id;
    curFS.vfptr = (FaceStrip_CGVtbl *)&FaceStrip_CG::vftable;
    ObjDesc::~ObjDesc(&curFS.objDesc);
    curES.vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
    ObjDesc::~ObjDesc(&curES.objDesc_Bald);
    ObjDesc::~ObjDesc(&curES.objDesc);
    curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
    ObjDesc::~ObjDesc(&curHS.objDesc);
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
    result = 1;
  }
  else
  {
    curFS.vfptr = (FaceStrip_CGVtbl *)&FaceStrip_CG::vftable;
    ObjDesc::~ObjDesc(&curFS.objDesc);
    curES.vfptr = (EyesStrip_CGVtbl *)&EyesStrip_CG::vftable;
    ObjDesc::~ObjDesc(&curES.objDesc_Bald);
    ObjDesc::~ObjDesc(&curES.objDesc);
    curHS.vfptr = (HairStyle_CGVtbl *)&HairStyle_CG::vftable;
    ObjDesc::~ObjDesc(&curHS.objDesc);
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
    result = 0;
  }
  return result;
}
// 79FA80: using guessed type void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *);
// 79FA84: using guessed type void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *);
// 79FA88: using guessed type void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *);
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);

//----- (005C2DD0) --------------------------------------------------------  // acclient.c:494561
unsigned int __thiscall ACCharGenData::GetHairIndexFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, const bool bald)
{
  unsigned int result; // eax@2
  unsigned int v6; // ebp@3
  int v7; // esi@4
  HairStyle_CG curHS; // [sp+4h] [bp-1D8h]@5
  Sex_CG curSX; // [sp+40h] [bp-19Ch]@3
  HeritageGroup_CG curHG; // [sp+11Ch] [bp-C0h]@3

  if ( id.id == stru_8EF864.id )
  {
    result = 0;
  }
  else
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v6 = 0;
    if ( curSX.mHairStyleList.m_num )
    {
      v7 = 0;
      while ( 1 )
      {
        curHS.iconImage.id = curSX.mHairStyleList.m_data[v7].iconImage.id;
        curHS.bald = curSX.mHairStyleList.m_data[v7].bald;
        curHS.alternateSetup.id = curSX.mHairStyleList.m_data[v7].alternateSetup.id;
        ObjDesc::ObjDesc(&curHS.objDesc, &curSX.mHairStyleList.m_data[v7].objDesc);
        if ( id.id == ObjDesc::GetAnimPartChange(&curHS.objDesc, 0)->part_id.id && curHS.bald == bald )
          break;
        ObjDesc::~ObjDesc(&curHS.objDesc);
        ++v6;
        ++v7;
        if ( v6 >= curSX.mHairStyleList.m_num )
          goto LABEL_8;
      }
      ObjDesc::~ObjDesc(&curHS.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = v6;
    }
    else
    {
LABEL_8:
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = 0;
    }
  }
  return result;
}

//----- (005C2F00) --------------------------------------------------------  // acclient.c:494613
unsigned int __thiscall ACCharGenData::GetEyeStripIndexFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, const bool use_alternate_texture, const bool bald)
{
  unsigned int result; // eax@2
  unsigned int v7; // ebp@3
  int v8; // edi@4
  EyesStrip_CG *v9; // esi@5
  TextureMapChange *v10; // eax@6
  int texture_change_index; // [sp+0h] [bp-204h]@3
  EyesStrip_CG curES; // [sp+4h] [bp-200h]@5
  Sex_CG curSX; // [sp+68h] [bp-19Ch]@3
  HeritageGroup_CG curHG; // [sp+144h] [bp-C0h]@3

  if ( id.id == stru_8EF864.id )
  {
    result = 0;
  }
  else
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v7 = 0;
    texture_change_index = use_alternate_texture != 0;
    if ( curSX.mEyeStripList.m_num )
    {
      v8 = 0;
      while ( 1 )
      {
        v9 = &curSX.mEyeStripList.m_data[v8];
        curES.iconImage.id = curSX.mEyeStripList.m_data[v8].iconImage.id;
        curES.iconImage_Bald.id = curSX.mEyeStripList.m_data[v8].iconImage_Bald.id;
        ObjDesc::ObjDesc(&curES.objDesc, &curSX.mEyeStripList.m_data[v8].objDesc);
        ObjDesc::ObjDesc(&curES.objDesc_Bald, &v9->objDesc_Bald);
        v10 = bald ? ObjDesc::GetTextureMapChange(&curES.objDesc_Bald, texture_change_index) : ObjDesc::GetTextureMapChange(
                                                                                                 &curES.objDesc,
                                                                                                 texture_change_index);
        if ( id.id == v10->new_tex_id.id )
          break;
        ObjDesc::~ObjDesc(&curES.objDesc_Bald);
        ObjDesc::~ObjDesc(&curES.objDesc);
        ++v7;
        ++v8;
        if ( v7 >= curSX.mEyeStripList.m_num )
          goto LABEL_10;
      }
      ObjDesc::~ObjDesc(&curES.objDesc_Bald);
      ObjDesc::~ObjDesc(&curES.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = v7;
    }
    else
    {
LABEL_10:
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = 0;
    }
  }
  return result;
}

//----- (005C3070) --------------------------------------------------------  // acclient.c:494675
unsigned int __thiscall ACCharGenData::GetNoseStripIndexFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, const bool use_alternate_texture)
{
  unsigned int result; // eax@2
  unsigned int v6; // edi@3
  int v7; // esi@4
  FaceStrip_CG curFS; // [sp+0h] [bp-1D0h]@5
  Sex_CG curSX; // [sp+34h] [bp-19Ch]@3
  HeritageGroup_CG curHG; // [sp+110h] [bp-C0h]@3

  if ( id.id == stru_8EF864.id )
  {
    result = 0;
  }
  else
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v6 = 0;
    if ( curSX.mNoseStripList.m_num )
    {
      v7 = 0;
      while ( 1 )
      {
        curFS.iconImage.id = curSX.mNoseStripList.m_data[v7].iconImage.id;
        ObjDesc::ObjDesc(&curFS.objDesc, &curSX.mNoseStripList.m_data[v7].objDesc);
        if ( id.id == ObjDesc::GetTextureMapChange(&curFS.objDesc, use_alternate_texture != 0)->new_tex_id.id )
          break;
        ObjDesc::~ObjDesc(&curFS.objDesc);
        ++v6;
        ++v7;
        if ( v6 >= curSX.mNoseStripList.m_num )
          goto LABEL_7;
      }
      ObjDesc::~ObjDesc(&curFS.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = v6;
    }
    else
    {
LABEL_7:
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = 0;
    }
  }
  return result;
}

//----- (005C3190) --------------------------------------------------------  // acclient.c:494725
unsigned int __thiscall ACCharGenData::GetMouthStripIndexFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, const bool use_alternate_texture)
{
  unsigned int result; // eax@2
  unsigned int v6; // edi@3
  int v7; // esi@4
  FaceStrip_CG curFS; // [sp+0h] [bp-1D0h]@5
  Sex_CG curSX; // [sp+34h] [bp-19Ch]@3
  HeritageGroup_CG curHG; // [sp+110h] [bp-C0h]@3

  if ( id.id == stru_8EF864.id )
  {
    result = 0;
  }
  else
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v6 = 0;
    if ( curSX.mMouthStripList.m_num )
    {
      v7 = 0;
      while ( 1 )
      {
        curFS.iconImage.id = curSX.mMouthStripList.m_data[v7].iconImage.id;
        ObjDesc::ObjDesc(&curFS.objDesc, &curSX.mMouthStripList.m_data[v7].objDesc);
        if ( id.id == ObjDesc::GetTextureMapChange(&curFS.objDesc, use_alternate_texture != 0)->new_tex_id.id )
          break;
        ObjDesc::~ObjDesc(&curFS.objDesc);
        ++v6;
        ++v7;
        if ( v6 >= curSX.mMouthStripList.m_num )
          goto LABEL_7;
      }
      ObjDesc::~ObjDesc(&curFS.objDesc);
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = v6;
    }
    else
    {
LABEL_7:
      Sex_CG::~Sex_CG(&curSX);
      HeritageGroup_CG::~HeritageGroup_CG(&curHG);
      result = 0;
    }
  }
  return result;
}

//----- (005C32B0) --------------------------------------------------------  // acclient.c:494775
void __thiscall ACCharGenData::GetSkinShadeFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, long double *shade)
{
  int v5; // edi@1
  QualifiedDataID *v6; // eax@2
  int v7; // esi@2
  IDClass<_tagDataID,32,0> temp; // [sp+Ch] [bp-1A8h]@3
  QualifiedDataID v9; // [sp+10h] [bp-1A4h]@2
  HeritageGroup_CG curHG; // [sp+18h] [bp-19Ch]@2
  Sex_CG curSX; // [sp+D8h] [bp-DCh]@2

  v5 = 0;
  *(_QWORD *)shade = 0i64;
  if ( id.id != stru_8EF864.id )
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    QualifiedDataID::QualifiedDataID(&v9, curSX.skinPalSet, 0x18u);
    v7 = DBObj::Get(v6);
    if ( *(_DWORD *)(v7 + 56) > 0u )
    {
      do
      {
        PalSet::GetPaletteID_Integral((PalSet *)v7, &temp, v5);
        if ( id.id == temp.id )
          break;
        ++v5;
      }
      while ( (unsigned int)v5 < *(_DWORD *)(v7 + 56) );
    }
    temp.id = v5 + 1;
    *shade = (double)(unsigned int)(v5 + 1) / (double)*(unsigned int *)(v7 + 56);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}

//----- (005C33A0) --------------------------------------------------------  // acclient.c:494813
void __thiscall ACCharGenData::GetHairColorFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, unsigned int *color, long double *shade)
{
  long double *v6; // esi@1
  bool v7; // zf@2
  QualifiedDataID *v8; // eax@3
  int v9; // esi@3
  unsigned int v10; // edi@3
  unsigned int v11; // eax@6
  bool v12; // cf@6
  IDClass<_tagDataID,32,0> temp; // [sp+Ch] [bp-1ACh]@4
  unsigned int v14; // [sp+10h] [bp-1A8h]@11
  QualifiedDataID v15; // [sp+14h] [bp-1A4h]@3
  Sex_CG curSX; // [sp+1Ch] [bp-19Ch]@2
  HeritageGroup_CG curHG; // [sp+F8h] [bp-C0h]@2

  v6 = shade;
  *color = 0;
  *(_QWORD *)shade = 0i64;
  if ( id.id != stru_8EF864.id )
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v7 = curSX.mHairColorList.m_num == 0;
    *color = 0;
    if ( v7 )
    {
LABEL_8:
      *color = 0;
      *(_DWORD *)v6 = 0;
      *((_DWORD *)v6 + 1) = 0;
    }
    else
    {
      while ( 1 )
      {
        QualifiedDataID::QualifiedDataID(&v15, curSX.mHairColorList.m_data[*color], 0x18u);
        v9 = DBObj::Get(v8);
        v10 = 0;
        if ( *(_DWORD *)(v9 + 56) )
          break;
LABEL_6:
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
        v11 = *color + 1;
        v12 = v11 < curSX.mHairColorList.m_num;
        *color = v11;
        if ( !v12 )
        {
          v6 = shade;
          goto LABEL_8;
        }
      }
      while ( 1 )
      {
        PalSet::GetPaletteID_Integral((PalSet *)v9, &temp, v10++);
        if ( id.id == temp.id )
          break;
        if ( v10 >= *(_DWORD *)(v9 + 56) )
          goto LABEL_6;
      }
      v14 = v10;
      *shade = (double)v10 / (double)*(unsigned int *)(v9 + 56);
      (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 20))(v9);
    }
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}

//----- (005C3500) --------------------------------------------------------  // acclient.c:494882
void __thiscall ACCharGenData::GetEyeColorFromID(ACCharGenData *this, const unsigned int heritage, const unsigned int gender, IDClass<_tagDataID,32,0> id, unsigned int *color)
{
  unsigned int v5; // edx@2
  bool v6; // zf@2
  IDClass<_tagDataID,32,0> *v7; // ecx@3
  unsigned int v8; // eax@5
  Sex_CG curSX; // [sp+8h] [bp-19Ch]@2
  HeritageGroup_CG curHG; // [sp+E4h] [bp-C0h]@2

  *color = 0;
  if ( id.id != stru_8EF864.id )
  {
    ACCharGenData::GetHG(this, &curHG, heritage);
    HeritageGroup_CG::GetSX(&curHG, &curSX, gender);
    v5 = curSX.mEyeColorList.m_num;
    v6 = curSX.mEyeColorList.m_num == 0;
    *color = 0;
    if ( v6 )
    {
LABEL_6:
      *color = 0;
    }
    else
    {
      v7 = curSX.mEyeColorList.m_data;
      while ( id.id != v7[*color].id )
      {
        v8 = *color + 1;
        *color = v8;
        if ( v8 >= v5 )
          goto LABEL_6;
      }
    }
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}

//----- (005C35A0) --------------------------------------------------------  // acclient.c:494921
HashTable<unsigned long,HeritageGroup_CG,0> *__thiscall HashTable<unsigned long,HeritageGroup_CG,0>::scalar_deleting_destructor(HashTable<unsigned long,HeritageGroup_CG,0> *this, unsigned int a2)
{
  HashTable<unsigned long,HeritageGroup_CG,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,HeritageGroup_CG,0>Vtbl *)&HashTable<unsigned long,HeritageGroup_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E76D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable)(void *, char);
// 7E76E0: using guessed type int (__thiscall *HashTable<unsigned long,HeritageGroup_CG,0>::vftable)(void *, char);

//----- (005C3600) --------------------------------------------------------  // acclient.c:494947
void __thiscall ACCharGenData::ACCharGenData(ACCharGenData *this)
{
  ACCharGenData *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8EF864);
  v1->vfptr = (InterfaceVtbl *)&ACCharGenData::vftable;
  v1->mStartAreaList.m_data = 0;
  v1->mStartAreaList.m_sizeAndDeallocate = 0;
  v1->mStartAreaList.m_num = 0;
  v1->mHeritageGroupList.vfptr = (HashTable<unsigned long,HeritageGroup_CG,0>Vtbl *)&HashTable<unsigned long,HeritageGroup_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>(
    &v1->mHeritageGroupList.m_intrusiveTable,
    0x17u);
}
// 7E76E0: using guessed type int (__thiscall *HashTable<unsigned long,HeritageGroup_CG,0>::vftable)(void *, char);
// 7E76E8: using guessed type __int32 (__stdcall *ACCharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005C3640) --------------------------------------------------------  // acclient.c:494966
void __thiscall ACCharGenData::~ACCharGenData(ACCharGenData *this)
{
  ACCharGenData *v1; // edi@1
  char *v2; // ebx@1
  void *v3; // eax@1

  v1 = this;
  v2 = (char *)&this->mStartAreaList;
  this->vfptr = (InterfaceVtbl *)&ACCharGenData::vftable;
  SmartArray<ACCharGenStartArea,1>::SetNElements(&this->mStartAreaList, 0, 1);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::delete_contents(&v1->mHeritageGroupList.m_intrusiveTable);
  v1->mHeritageGroupList.vfptr = (HashTable<unsigned long,HeritageGroup_CG,0>Vtbl *)&HashTable<unsigned long,HeritageGroup_CG,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::delete_contents(&v1->mHeritageGroupList.m_intrusiveTable);
  v3 = v1->mHeritageGroupList.m_intrusiveTable.m_buckets;
  v1->mHeritageGroupList.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable;
  if ( v3 != v1->mHeritageGroupList.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->mHeritageGroupList.m_intrusiveTable.m_buckets = 0;
  v1->mHeritageGroupList.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->mHeritageGroupList.m_intrusiveTable.m_numBuckets = 0;
  v1->mHeritageGroupList.m_intrusiveTable.m_numElements = 0;
  if ( (*((_DWORD *)v2 + 1) & 0x80000000) == 0x80000000 && *(_DWORD *)v2 )
    ACCharGenStartArea::vector_deleting_destructor(*(ACCharGenStartArea **)v2, 3u);
  v1->vfptr = (InterfaceVtbl *)&CharGenData::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 7E7648: using guessed type __int32 (__stdcall *CharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7E76D0: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable)(void *, char);
// 7E76E0: using guessed type int (__thiscall *HashTable<unsigned long,HeritageGroup_CG,0>::vftable)(void *, char);
// 7E76E8: using guessed type __int32 (__stdcall *ACCharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005C36D0) --------------------------------------------------------  // acclient.c:494998
void __thiscall ACCharGenData::Serialize(ACCharGenData *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  ACCharGenData *v3; // edi@1
  unsigned int v4; // ebp@2
  unsigned int v5; // eax@2
  unsigned int v6; // ebp@5
  unsigned int v7; // eax@5

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  if ( v2->m_flags & 1 )
  {
    v4 = v3->m_DID.id;
    Archive::CheckAlignment(v2, 4u);
    v5 = Archive::GetBytes(v2, 4u);
    if ( v5 && v2->m_flags & 1 )
      *(_DWORD *)v5 = v4;
  }
  else
  {
    v6 = stru_8EF864.id;
    Archive::CheckAlignment(v2, 4u);
    v7 = Archive::GetBytes(v2, 4u);
    if ( v7 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v7 = v6;
      else
        v6 = *(_DWORD *)v7;
    }
    ((void (__thiscall *)(ACCharGenData *, unsigned int))v3->vfptr[2].Release)(v3, v6);
  }
  SB_Container<SB_Default,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
    (ACCharGenData *const *)&io_archive,
    &v3->mStartAreaList,
    v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::delete_contents(&v3->mHeritageGroupList.m_intrusiveTable);
  _SerializeIntrusiveHashTable____PAVACCharGenData__V__IntrusiveHashTable_KPAV__HashTableData_KVHeritageGroup_CG_____0A___PAV__HashTableData_KVHeritageGroup_CG____USB_HashData___SB_Hash_USB_Default__U1__1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVACCharGenData__AAV__IntrusiveHashTable_KPAV__HashTableData_KVHeritageGroup_CG_____0A___AAVArchive___Z(
    (ACCharGenData *const *)&io_archive,
    &v3->mHeritageGroupList.m_intrusiveTable,
    v2);
}

//----- (005C3780) --------------------------------------------------------  // acclient.c:495045
ACCharGenData *__thiscall ACCharGenData::scalar_deleting_destructor(ACCharGenData *this, unsigned int a2)
{
  ACCharGenData *v2; // esi@1

  v2 = this;
  ACCharGenData::~ACCharGenData(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0069A7C0) --------------------------------------------------------  // acclient.c:690548
bool __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *this, HashTableData<unsigned long,Sex_CG> *_data, HashTableData<unsigned long,Sex_CG> *_prev)
{
  unsigned int v3; // ebx@1
  unsigned int v4; // esi@1
  unsigned int v5; // edx@2
  bool result; // al@3
  HashTableData<unsigned long,Sex_CG> **v7; // eax@6

  v3 = this->m_numBuckets;
  v4 = _data->m_hashKey % v3;
  if ( !_prev )
    goto LABEL_11;
  v5 = _prev->m_hashKey % v3;
  if ( v4 == v5 )
  {
    _prev->m_hashNext = _data;
    ++this->m_numElements;
    return 1;
  }
  if ( v4 <= v5 )
  {
    result = 0;
  }
  else
  {
LABEL_11:
    v7 = &this->m_buckets[v4];
    *v7 = _data;
    if ( !_prev )
      this->m_firstInterestingBucket = v7;
    ++this->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0070EF60) --------------------------------------------------------  // acclient.c:802003
void sub_70EF60()
{
  flt_8EF868 = 1000.0 + 1.0;
}

//----- (0070EF80) --------------------------------------------------------  // acclient.c:802009
void sub_70EF80()
{
  flt_8EF86C = 24.0 * 8.0;
}

//----- (0070EFA0) --------------------------------------------------------  // acclient.c:802015
void sub_70EFA0()
{
  flt_8EF870 = 24.0 * 0.5;
}

//----- (0070EFC0) --------------------------------------------------------  // acclient.c:802021
int sub_70EFC0()
{
  return atexit(nullsub_1625);
}

//----- (0070EFD0) --------------------------------------------------------  // acclient.c:802027
int sub_70EFD0()
{
  return atexit(nullsub_1626);
}

//----- (0070EFE0) --------------------------------------------------------  // acclient.c:802033
int sub_70EFE0()
{
  return atexit(nullsub_1627);
}

//----- (0070EFF0) --------------------------------------------------------  // acclient.c:802039
int sub_70EFF0()
{
  return atexit(nullsub_1628);
}

//----- (0070F000) --------------------------------------------------------  // acclient.c:802045
int _E109_85()
{
  return atexit(nullsub_1629);
}

//----- (0070F010) --------------------------------------------------------  // acclient.c:802051
int sub_70F010()
{
  return atexit(_E113_72);
}

//----- (0070F020) --------------------------------------------------------  // acclient.c:802057
int _E115_91()
{
  return atexit(_E116_64);
}

//----- (0070F030) --------------------------------------------------------  // acclient.c:802063
int _E118_82()
{
  return atexit(_E119_90);
}

//----- (0070F040) --------------------------------------------------------  // acclient.c:802069
int _E121_75()
{
  return atexit(nullsub_1633);
}

//----- (0070F050) --------------------------------------------------------  // acclient.c:802075
int _E124_73()
{
  return atexit(_E125_70);
}

//----- (0070F060) --------------------------------------------------------  // acclient.c:802081
int _E127_62()
{
  return atexit(_E128_68);
}

//----- (0070F070) --------------------------------------------------------  // acclient.c:802087
int _E130_56()
{
  return atexit(_E131_57);
}

//----- (0070F080) --------------------------------------------------------  // acclient.c:802093
int _E133_48()
{
  return atexit(_E134_41);
}

//----- (0070F090) --------------------------------------------------------  // acclient.c:802099
int _E136_33()
{
  return atexit(_E137_40);
}

//----- (0070F0A0) --------------------------------------------------------  // acclient.c:802105
int _E139_33()
{
  return atexit(_E140_34);
}

//----- (0070F0B0) --------------------------------------------------------  // acclient.c:802111
int _E142_30()
{
  return atexit(_E143_34);
}

//----- (0070F0C0) --------------------------------------------------------  // acclient.c:802117
int _E145_32()
{
  return atexit(_E146_34);
}

//----- (0070F0D0) --------------------------------------------------------  // acclient.c:802123
int _E148_31()
{
  return atexit(_E149_33);
}

//----- (0070F0E0) --------------------------------------------------------  // acclient.c:802129
int _E151_29()
{
  return atexit(_E152_34);
}

//----- (0070F0F0) --------------------------------------------------------  // acclient.c:802135
int _E154_30()
{
  return atexit(_E155_30);
}

//----- (0070F100) --------------------------------------------------------  // acclient.c:802141
int _E157_27()
{
  return atexit(_E158_31);
}

//----- (0070F110) --------------------------------------------------------  // acclient.c:802147
int _E160_30()
{
  return atexit(_E161_28);
}

//----- (0070F120) --------------------------------------------------------  // acclient.c:802153
int _E163_23()
{
  return atexit(_E164_30);
}

//----- (0070F130) --------------------------------------------------------  // acclient.c:802159
int _E166_25()
{
  return atexit(_E167_26);
}

//----- (0070F140) --------------------------------------------------------  // acclient.c:802165
int _E169_23()
{
  return atexit(_E170_26);
}

//----- (0070F150) --------------------------------------------------------  // acclient.c:802171
int _E172_21()
{
  return atexit(_E173_21);
}

//----- (0070F160) --------------------------------------------------------  // acclient.c:802177
int _E175_18()
{
  return atexit(_E176_23);
}

//----- (0070F170) --------------------------------------------------------  // acclient.c:802183
int _E178_18()
{
  return atexit(_E179_22);
}

//----- (0070F180) --------------------------------------------------------  // acclient.c:802189
int _E181_18()
{
  return atexit(_E182_22);
}

//----- (0070F190) --------------------------------------------------------  // acclient.c:802195
int _E184_16()
{
  return atexit(_E185_19);
}

//----- (0070F1A0) --------------------------------------------------------  // acclient.c:802201
int _E187_15()
{
  return atexit(_E188_20);
}

//----- (0070F1B0) --------------------------------------------------------  // acclient.c:802207
int _E190_16()
{
  return atexit(_E191_19);
}

//----- (0070F1C0) --------------------------------------------------------  // acclient.c:802213
int _E193_15()
{
  return atexit(_E194_26);
}

//----- (0070F1D0) --------------------------------------------------------  // acclient.c:802219
int _E196_22()
{
  return atexit(_E197_16);
}

//----- (0070F1E0) --------------------------------------------------------  // acclient.c:802225
int _E199_14()
{
  return atexit(_E200_20);
}

//----- (0070F1F0) --------------------------------------------------------  // acclient.c:802231
int _E202_18()
{
  return atexit(_E203_19);
}

//----- (0070F200) --------------------------------------------------------  // acclient.c:802237
int _E205_15()
{
  return atexit(_E206_22);
}

//----- (0070F210) --------------------------------------------------------  // acclient.c:802243
int _E208_20()
{
  return atexit(_E209_17);
}

//----- (0070F220) --------------------------------------------------------  // acclient.c:802249
int _E211_15()
{
  UNDEAD_MALE_CLOTHING_DEFAULT_1.id = UNDEAD_MALE_UNDEAD_SETUP_1.id;
  return atexit(_E212_20);
}

//----- (0070F240) --------------------------------------------------------  // acclient.c:802256
int _E214_17()
{
  UNDEAD_FEMALE_CLOTHING_DEFAULT_1.id = UNDEAD_FEMALE_UNDEAD_SETUP_1.id;
  return atexit(_E215_17);
}

//----- (0070F260) --------------------------------------------------------  // acclient.c:802263
int _E217_14()
{
  UMBRAEN_MALE_CLOTHING_DEFAULT_1.id = UMBRAEN_MALE_CROWN_SETUP_1.id;
  return atexit(_E218_17);
}

//----- (0070F280) --------------------------------------------------------  // acclient.c:802270
int _E220_14()
{
  UMBRAEN_FEMALE_CLOTHING_DEFAULT_1.id = UMBRAEN_FEMALE_CROWN_SETUP_1.id;
  return atexit(_E221_17);
}

//----- (0070F2A0) --------------------------------------------------------  // acclient.c:802277
int _E223_15()
{
  PENUMBRAEN_MALE_CLOTHING_DEFAULT_1.id = PENUMBRAEN_MALE_CROWN_SETUP_1.id;
  return atexit(_E224_17);
}

//----- (0070F2C0) --------------------------------------------------------  // acclient.c:802284
int _E226_14()
{
  PENUMBRAEN_FEMALE_CLOTHING_DEFAULT_1.id = PENUMBRAEN_FEMALE_CROWN_SETUP_1.id;
  return atexit(_E227_17);
}

//----- (0070F2E0) --------------------------------------------------------  // acclient.c:802291
int _E229_15()
{
  return atexit(_E230_18);
}

//----- (0070F2F0) --------------------------------------------------------  // acclient.c:802297
int _E232_15()
{
  return atexit(_E233_17);
}

//----- (0070F300) --------------------------------------------------------  // acclient.c:802303
int _E235_15()
{
  return atexit(_E236_16);
}

//----- (0070F310) --------------------------------------------------------  // acclient.c:802309
int _E238_13()
{
  return atexit(_E239_16);
}

//----- (0070F320) --------------------------------------------------------  // acclient.c:802315
int _E241_13()
{
  return atexit(_E242_16);
}

//----- (0070F330) --------------------------------------------------------  // acclient.c:802321
int _E244_13()
{
  return atexit(_E245_15);
}

//----- (0070F340) --------------------------------------------------------  // acclient.c:802327
int _E247_12()
{
  return atexit(_E248_15);
}

//----- (0070F350) --------------------------------------------------------  // acclient.c:802333
int _E250_12()
{
  return atexit(_E251_14);
}

//----- (0070F360) --------------------------------------------------------  // acclient.c:802339
int _E253_12()
{
  return atexit(_E254_15);
}

//----- (0070F370) --------------------------------------------------------  // acclient.c:802345
int _E256_12()
{
  return atexit(_E257_13);
}

//----- (0070F380) --------------------------------------------------------  // acclient.c:802351
int _E259_13()
{
  return atexit(_E260_14);
}

//----- (0070F390) --------------------------------------------------------  // acclient.c:802357
int _E262_13()
{
  return atexit(_E263_13);
}

//----- (0070F3A0) --------------------------------------------------------  // acclient.c:802363
int _E265_13()
{
  return atexit(_E266_13);
}

//----- (0070F3B0) --------------------------------------------------------  // acclient.c:802369
int _E268_12()
{
  return atexit(_E269_12);
}

//----- (0070F3C0) --------------------------------------------------------  // acclient.c:802375
int _E271_11()
{
  return atexit(_E272_11);
}

//----- (0070F3D0) --------------------------------------------------------  // acclient.c:802381
int _E274_11()
{
  return atexit(_E275_11);
}

//----- (0070F3E0) --------------------------------------------------------  // acclient.c:802387
int _E277_11()
{
  return atexit(_E278_11);
}

//----- (0070F3F0) --------------------------------------------------------  // acclient.c:802393
int _E280_10()
{
  return atexit(_E281_11);
}

//----- (0070F400) --------------------------------------------------------  // acclient.c:802399
int _E283_10()
{
  return atexit(_E284_9);
}

//----- (0070F410) --------------------------------------------------------  // acclient.c:802405
int _E286_9()
{
  return atexit(_E287_10);
}

//----- (0070F420) --------------------------------------------------------  // acclient.c:802411
int _E289_8()
{
  return atexit(_E290_9);
}

//----- (0070F430) --------------------------------------------------------  // acclient.c:802417
int _E292_9()
{
  return atexit(_E293_8);
}

//----- (0070F440) --------------------------------------------------------  // acclient.c:802423
int _E295_8()
{
  return atexit(_E296_9);
}

//----- (0070F450) --------------------------------------------------------  // acclient.c:802429
int _E298_9()
{
  return atexit(_E299_7);
}

//----- (0070F460) --------------------------------------------------------  // acclient.c:802435
int _E301_7()
{
  return atexit(_E302_8);
}

//----- (0070F470) --------------------------------------------------------  // acclient.c:802441
int _E304_8()
{
  return atexit(_E305_7);
}

//----- (0070F480) --------------------------------------------------------  // acclient.c:802447
int _E307_7()
{
  return atexit(_E308_8);
}

//----- (0070F490) --------------------------------------------------------  // acclient.c:802453
int _E310_8()
{
  return atexit(_E311_7);
}

//----- (0070F4A0) --------------------------------------------------------  // acclient.c:802459
int _E313_7()
{
  return atexit(_E314_8);
}

//----- (0070F4B0) --------------------------------------------------------  // acclient.c:802465
int _E316_8()
{
  return atexit(_E317_7);
}

//----- (0070F4C0) --------------------------------------------------------  // acclient.c:802471
int _E319_7()
{
  return atexit(_E320_8);
}

//----- (0070F4D0) --------------------------------------------------------  // acclient.c:802477
int sub_70F4D0()
{
  return atexit(nullsub_1624);
}

