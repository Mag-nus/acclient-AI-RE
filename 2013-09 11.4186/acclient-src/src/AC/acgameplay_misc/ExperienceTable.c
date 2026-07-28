/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ExperienceTable
   Object     : AC\acgameplay_misc\ExperienceTable.obj
   Functions  : 27
   Addresses  : 004BFBF0 - 0070FCB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BFBF0) --------------------------------------------------------  // acclient.c:242233
signed int ExperienceTable::GetDBOType()
{
  return 268435465;
}

//----- (005C9C20) --------------------------------------------------------  // acclient.c:500948
signed int __thiscall ExperienceTable::GetExperienceForTrainedSkillLevel(ExperienceTable *this, unsigned int level)
{
  unsigned int *v2; // eax@2
  signed int result; // eax@3

  if ( level <= this->_max_trained_skill_level && (v2 = this->_trained_skill_table) != 0 )
    result = v2[level];
  else
    result = -1;
  return result;
}

//----- (005C9C40) --------------------------------------------------------  // acclient.c:500961
signed int __thiscall ExperienceTable::GetExperienceForSpecializedSkillLevel(ExperienceTable *this, unsigned int level)
{
  unsigned int *v2; // eax@2
  signed int result; // eax@3

  if ( level <= this->_max_specialized_skill_level && (v2 = this->_specialized_skill_table) != 0 )
    result = v2[level];
  else
    result = -1;
  return result;
}

//----- (005C9C60) --------------------------------------------------------  // acclient.c:500974
signed int __thiscall ExperienceTable::GetExperienceForAttributeLevel(ExperienceTable *this, unsigned int level)
{
  unsigned int *v2; // eax@2
  signed int result; // eax@3

  if ( level <= this->_max_attribute_level && (v2 = this->_attribute_table) != 0 )
    result = v2[level];
  else
    result = -1;
  return result;
}

//----- (005C9C80) --------------------------------------------------------  // acclient.c:500987
signed int __thiscall ExperienceTable::GetExperienceForAttribute2ndLevel(ExperienceTable *this, unsigned int level)
{
  unsigned int *v2; // eax@2
  signed int result; // eax@3

  if ( level <= this->_max_attribute2nd_level && (v2 = this->_attribute2nd_table) != 0 )
    result = v2[level];
  else
    result = -1;
  return result;
}

//----- (005C9CA0) --------------------------------------------------------  // acclient.c:501000
unsigned __int64 __thiscall ExperienceTable::GetExperienceForLevel(ExperienceTable *this, unsigned int level)
{
  unsigned int v2; // edx@1
  unsigned __int64 *v3; // ecx@3
  unsigned __int64 result; // rax@4

  v2 = level;
  if ( level > this->_max_level )
    v2 = this->_max_level;
  v3 = this->_level_table;
  if ( v3 )
    result = v3[v2];
  else
    result = 0i64;
  return result;
}

//----- (005C9CD0) --------------------------------------------------------  // acclient.c:501018
signed int __thiscall ExperienceTable::GetExperienceForLevel(ExperienceTable *this, ExperienceType type, unsigned int lvl)
{
  unsigned int v3; // eax@2
  unsigned int *v4; // ecx@3
  signed int result; // eax@5

  switch ( type )
  {
    case 1:
      v3 = lvl;
      if ( lvl > this->_max_attribute_level )
        goto LABEL_5;
      v4 = this->_attribute_table;
      goto LABEL_4;
    case 2:
      v3 = lvl;
      if ( lvl > this->_max_attribute2nd_level )
        goto LABEL_5;
      v4 = this->_attribute2nd_table;
      goto LABEL_4;
    case 3:
      v3 = lvl;
      if ( lvl > this->_max_trained_skill_level )
        goto LABEL_5;
      v4 = this->_trained_skill_table;
LABEL_4:
      if ( !v4 )
        goto LABEL_5;
      goto LABEL_12;
    case 4:
      v3 = lvl;
      if ( lvl > this->_max_specialized_skill_level )
        goto LABEL_5;
      v4 = this->_specialized_skill_table;
      if ( !v4 )
        goto LABEL_5;
LABEL_12:
      result = v4[v3];
      break;
    default:
LABEL_5:
      result = -1;
      break;
  }
  return result;
}

//----- (005C9D40) --------------------------------------------------------  // acclient.c:501066
unsigned int __thiscall ExperienceTable::GetLevelForExperience(ExperienceTable *this, ExperienceType type, unsigned int pp)
{
  unsigned int v3; // ebp@1
  ExperienceTable *v4; // ebx@1
  unsigned int v5; // edi@2
  unsigned int v6; // esi@8
  unsigned int v7; // edx@9
  unsigned __int64 v8; // rax@10
  unsigned int result; // eax@12
  unsigned __int64 v10; // rax@13
  bool v11; // zf@15
  bool v12; // sf@15
  unsigned __int8 v13; // of@15
  int i; // [sp+10h] [bp-8h]@8

  v3 = 0;
  v4 = this;
  switch ( type )
  {
    case 1:
      v5 = this->_max_attribute_level;
      break;
    case 2:
      v5 = this->_max_attribute2nd_level;
      break;
    case 3:
      v5 = this->_max_trained_skill_level;
      break;
    case 4:
      v5 = this->_max_specialized_skill_level;
      break;
    case 5:
      v5 = this->_max_level;
      break;
    default:
      v5 = 0;
      break;
  }
  v6 = (unsigned __int64)(((double)v5 + 1.0) * 0.5);
  i = 1;
  do
  {
    ExperienceTable::GetExperienceForLevel(v4, type, v6);
    if ( pp > ExperienceTable::GetExperienceForLevel(v4, type, v6 + 1) - 1 )
    {
      v3 = v6;
      v8 = (unsigned __int64)(((double)(v5 - v6) + 1.0) * 0.5);
      if ( !(_DWORD)v8 )
        return v6;
      v6 += v8;
      goto LABEL_15;
    }
    result = v6;
    if ( pp >= v7 )
      return result;
    v5 = v6;
    v10 = (unsigned __int64)(((double)(v6 - v3) + 1.0) * 0.5);
    if ( !(_DWORD)v10 )
      break;
    v6 -= v10;
LABEL_15:
    v13 = __OFSUB__(i + 1, 16);
    v11 = i == 15;
    v12 = i++ - 15 < 0;
  }
  while ( (unsigned __int8)(v12 ^ v13) | v11 );
  return v6;
}

//----- (005C9E70) --------------------------------------------------------  // acclient.c:501136
unsigned int __thiscall ExperienceTable::GetTrainedSkillLevelForExperience(ExperienceTable *this, unsigned int pp)
{
  return ExperienceTable::GetLevelForExperience(this, TrainedSkill_ExperienceType, pp);
}

//----- (005C9E80) --------------------------------------------------------  // acclient.c:501142
unsigned int __thiscall ExperienceTable::GetSpecializedSkillLevelForExperience(ExperienceTable *this, unsigned int pp)
{
  return ExperienceTable::GetLevelForExperience(this, SpecializedSkill_ExperienceType, pp);
}

//----- (005C9E90) --------------------------------------------------------  // acclient.c:501148
unsigned int __thiscall ExperienceTable::GetAttributeLevelForExperience(ExperienceTable *this, unsigned int xp)
{
  return ExperienceTable::GetLevelForExperience(this, Attribute_ExperienceType, xp);
}

//----- (005C9EA0) --------------------------------------------------------  // acclient.c:501154
unsigned int __thiscall ExperienceTable::GetAttribute2ndLevelForExperience(ExperienceTable *this, unsigned int xp)
{
  return ExperienceTable::GetLevelForExperience(this, Attribute2nd_ExperienceType, xp);
}

//----- (005C9EB0) --------------------------------------------------------  // acclient.c:501160
unsigned int __thiscall ExperienceTable::Pack(ExperienceTable *this, void **addr, unsigned int size)
{
  int v3; // ebx@1
  unsigned int result; // eax@1
  char *v5; // esi@2
  char *v6; // ebp@2
  char *v7; // ebx@2
  char *v8; // edi@2
  char *v9; // esi@2
  unsigned int v10; // edi@2
  signed int v11; // ebx@4
  int v12; // ebx@5
  char *v13; // ebp@8
  unsigned int v14; // edi@9
  signed int v15; // ebx@11
  int v16; // ebx@12
  char *v17; // ebp@15
  DBObj *v18; // edi@16
  signed int v19; // ebx@18
  DBObj *v20; // ebx@19
  char *v21; // ebp@22
  DBOCache *v22; // edi@23
  signed int v23; // ebx@25
  int v24; // ebx@26
  char *v25; // ebp@29
  unsigned int v26; // esi@30
  unsigned int v27; // ebp@31
  int v28; // edi@33
  int v29; // ebx@34
  void *v30; // ebp@36
  unsigned int v31; // esi@37
  unsigned int v32; // ebx@38
  PackObjVtbl *v33; // edi@40

  v3 = *(_DWORD *)&this->m_bLoaded;
  result = 4
         * (unsigned int)((char *)this->m_pNext
                        + (unsigned int)((char *)this->m_pMaintainer->m_ObjTable.m_intrusiveTable.m_aInplaceBuckets
                                       + 2 * this->m_DID.id)
                        + LODWORD(this->m_timeStamp)
                        + v3
                        + this->m_DID.id);
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = LODWORD(this->m_timeStamp);
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->m_pNext;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->m_pMaintainer;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = this->m_DID.id;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v10 = 0;
    if ( *(_DWORD *)&this->m_bLoaded != -1 )
    {
      do
      {
        if ( v10 <= *(_DWORD *)&this->m_bLoaded )
        {
          v12 = *((_DWORD *)&this->m_bLoaded + 1);
          if ( v12 )
            v11 = *(_DWORD *)(v12 + 4 * v10);
          else
            v11 = -1;
        }
        else
        {
          v11 = -1;
        }
        *(_DWORD *)v9 = v11;
        v13 = (char *)*addr + 4;
        *addr = v13;
        ++v10;
        v9 = v13;
      }
      while ( v10 < *(_DWORD *)&this->m_bLoaded + 1 );
    }
    v14 = 0;
    if ( LODWORD(this->m_timeStamp) != -1 )
    {
      do
      {
        if ( v14 <= LODWORD(this->m_timeStamp) )
        {
          v16 = HIDWORD(this->m_timeStamp);
          if ( v16 )
            v15 = *(_DWORD *)(v16 + 4 * v14);
          else
            v15 = -1;
        }
        else
        {
          v15 = -1;
        }
        *(_DWORD *)v9 = v15;
        v17 = (char *)*addr + 4;
        *addr = v17;
        ++v14;
        v9 = v17;
      }
      while ( v14 < LODWORD(this->m_timeStamp) + 1 );
    }
    v18 = 0;
    if ( this->m_pNext != (DBObj *)-1 )
    {
      do
      {
        if ( v18 <= this->m_pNext )
        {
          v20 = this->m_pLast;
          if ( v20 )
            v19 = *((_DWORD *)&v20->vfptr + (_DWORD)v18);
          else
            v19 = -1;
        }
        else
        {
          v19 = -1;
        }
        *(_DWORD *)v9 = v19;
        v21 = (char *)*addr + 4;
        *addr = v21;
        v18 = (DBObj *)((char *)v18 + 1);
        v9 = v21;
      }
      while ( (InterfaceVtbl **)v18 < (InterfaceVtbl **)((char *)&this->m_pNext->vfptr + 1) );
    }
    v22 = 0;
    if ( this->m_pMaintainer != (DBOCache *)-1 )
    {
      do
      {
        if ( v22 <= this->m_pMaintainer )
        {
          v24 = this->m_numLinks;
          if ( v24 )
            v23 = *(_DWORD *)(v24 + 4 * (_DWORD)v22);
          else
            v23 = -1;
        }
        else
        {
          v23 = -1;
        }
        *(_DWORD *)v9 = v23;
        v25 = (char *)*addr + 4;
        *addr = v25;
        v22 = (DBOCache *)((char *)v22 + 1);
        v9 = v25;
      }
      while ( (DBOCacheVtbl **)v22 < (DBOCacheVtbl **)((char *)&this->m_pMaintainer->vfptr + 1) );
    }
    v26 = 0;
    if ( this->m_DID.id != -1 )
    {
      do
      {
        v27 = v26;
        if ( v26 > this->m_DID.id )
          v27 = this->m_DID.id;
        v28 = *(_DWORD *)&this->m_AllowedInFreeList;
        if ( v28 )
        {
          v29 = *(_DWORD *)(v28 + 8 * v27);
          v28 = *(_DWORD *)(v28 + 8 * v27 + 4);
        }
        else
        {
          v29 = 0;
        }
        v30 = *addr;
        *(_DWORD *)v30 = v29;
        *((_DWORD *)v30 + 1) = v28;
        *addr = (char *)*addr + 8;
        ++v26;
      }
      while ( v26 < this->m_DID.id + 1 );
    }
    v31 = 0;
    if ( this->m_DID.id != -1 )
    {
      do
      {
        v32 = v31;
        if ( v31 > this->m_DID.id )
          v32 = this->m_DID.id;
        v33 = this->vfptr;
        if ( v33 )
          v33 = (PackObjVtbl *)*((_DWORD *)&v33->__vecDelDtor + v32);
        *(_DWORD *)*addr = v33;
        *addr = (char *)*addr + 4;
        ++v31;
      }
      while ( v31 < this->m_DID.id + 1 );
    }
  }
  return result;
}

//----- (005CA080) --------------------------------------------------------  // acclient.c:501367
void __thiscall ExperienceTable::ExperienceTable(ExperienceTable *this, IDClass<_tagDataID,32,0> did)
{
  ExperienceTable *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->_max_attribute_level = 0;
  v2->_attribute_table = 0;
  v2->_max_attribute2nd_level = 0;
  v2->_attribute2nd_table = 0;
  v2->_max_trained_skill_level = 0;
  v2->_trained_skill_table = 0;
  v2->_max_specialized_skill_level = 0;
  v2->_specialized_skill_table = 0;
  v2->_max_level = 0;
  v2->_level_table = 0;
  v2->_credit_table = 0;
  v2->vfptr = (InterfaceVtbl *)&ExperienceTable::vftable;
  v2->vfptr = (PackObjVtbl *)&ExperienceTable::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7FA8: using guessed type void *ExperienceTable::vftable;
// 7E7FC0: using guessed type __int32 (__stdcall *ExperienceTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005CA0D0) --------------------------------------------------------  // acclient.c:501393
ExperienceTable *__thiscall ExperienceTable::vector_deleting_destructor(ExperienceTable *this, unsigned int a2)
{
  return ExperienceTable::vector_deleting_destructor((ExperienceTable *)((char *)this - 48), a2);
}

//----- (005CA0E0) --------------------------------------------------------  // acclient.c:501399
void __thiscall ExperienceTable::Clear(ExperienceTable *this)
{
  ExperienceTable *v1; // esi@1

  v1 = this;
  if ( this->_attribute_table )
  {
    operator delete[](this->_attribute_table);
    v1->_attribute_table = 0;
  }
  if ( v1->_attribute2nd_table )
  {
    operator delete[](v1->_attribute2nd_table);
    v1->_attribute2nd_table = 0;
  }
  if ( v1->_trained_skill_table )
  {
    operator delete[](v1->_trained_skill_table);
    v1->_trained_skill_table = 0;
  }
  if ( v1->_specialized_skill_table )
  {
    operator delete[](v1->_specialized_skill_table);
    v1->_specialized_skill_table = 0;
  }
  if ( v1->_level_table )
  {
    operator delete[](v1->_level_table);
    v1->_level_table = 0;
  }
  if ( v1->_credit_table )
  {
    operator delete[](v1->_credit_table);
    v1->_credit_table = 0;
  }
}

//----- (005CA160) --------------------------------------------------------  // acclient.c:501437
int __thiscall ExperienceTable::UnPack(ExperienceTable *this, void **addr, unsigned int size)
{
  ExperienceTable *v3; // edi@1
  char *v5; // esi@3
  char *v6; // edx@3
  char *v7; // ecx@3
  char *v8; // eax@3
  char *v9; // ebp@3
  unsigned int v10; // ebp@3
  unsigned int v11; // ecx@4
  unsigned int v12; // eax@4
  void *v13; // edi@7
  int v14; // eax@9
  int v15; // ecx@9
  int v16; // eax@9
  unsigned int v17; // ebp@12
  unsigned int v18; // ecx@13
  unsigned int v19; // eax@13
  void *v20; // edi@16
  int v21; // eax@18
  int v22; // ecx@18
  int v23; // eax@18
  unsigned int v24; // ebp@21
  unsigned int v25; // ecx@22
  unsigned int v26; // eax@22
  void *v27; // edi@25
  int v28; // eax@27
  int v29; // ecx@27
  int v30; // eax@27
  unsigned int v31; // ebp@30
  unsigned int v32; // ecx@31
  unsigned int v33; // eax@31
  void *v34; // edi@34
  int v35; // eax@36
  int v36; // ecx@36
  int v37; // eax@36
  unsigned int v38; // ebp@39
  unsigned int v39; // ecx@40
  unsigned int v40; // edx@40
  unsigned int v41; // eax@40
  void *v42; // edi@43
  int v43; // eax@45
  bool v44; // zf@45
  int v45; // eax@45
  unsigned int v46; // ebp@48
  unsigned int v47; // ecx@49
  unsigned int v48; // eax@49
  void *v49; // edi@52
  int v50; // eax@54
  int v51; // ecx@54
  int v52; // eax@54
  ExperienceTable *v53; // [sp+4h] [bp-Ch]@1
  unsigned __int64 xp64; // [sp+8h] [bp-8h]@40
  unsigned int sizea; // [sp+18h] [bp+8h]@4
  unsigned int sizeb; // [sp+18h] [bp+8h]@13
  unsigned int sizec; // [sp+18h] [bp+8h]@22
  unsigned int sized; // [sp+18h] [bp+8h]@31
  unsigned int sizee; // [sp+18h] [bp+8h]@49

  v3 = this;
  v53 = this;
  if ( size < 0x14 )
    return 0;
  v5 = (char *)&this[-1]._max_attribute_level;
  ExperienceTable::Clear((ExperienceTable *)((char *)this - 48));
  *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)*addr;
  v6 = (char *)*addr + 4;
  *addr = v6;
  LODWORD(v3->m_timeStamp) = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v3->m_pNext = *(DBObj **)v7;
  v8 = (char *)*addr + 4;
  *addr = v8;
  v3->m_pMaintainer = *(DBOCache **)v8;
  v9 = (char *)*addr + 4;
  *addr = v9;
  v3->m_DID.id = *(_DWORD *)v9;
  *addr = (char *)*addr + 4;
  v10 = 0;
  if ( *(_DWORD *)&v3->m_bLoaded != -1 )
  {
    while ( 1 )
    {
      v11 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v12 = *((_DWORD *)v5 + 14);
      sizea = v11;
      if ( v10 <= v12 )
      {
        if ( *((_DWORD *)v5 + 15) )
          goto LABEL_9;
        if ( v12 )
        {
          v13 = operator new[](4 * v12 + 4);
          *((_DWORD *)v5 + 15) = v13;
          if ( v13 )
            break;
        }
      }
LABEL_11:
      v3 = v53;
      ++v10;
      if ( v10 >= *(_DWORD *)&v53->m_bLoaded + 1 )
        goto LABEL_12;
    }
    memset(v13, 0, 4 * *((_DWORD *)v5 + 14) + 4);
LABEL_9:
    v14 = *((_DWORD *)v5 + 15);
    v15 = *(_DWORD *)(v14 + 4 * v10);
    v16 = v14 + 4 * v10;
    if ( !v15 )
      *(_DWORD *)v16 = sizea;
    goto LABEL_11;
  }
LABEL_12:
  v17 = 0;
  if ( LODWORD(v3->m_timeStamp) != -1 )
  {
    while ( 1 )
    {
      v18 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v19 = *((_DWORD *)v5 + 16);
      sizeb = v18;
      if ( v17 <= v19 )
      {
        if ( *((_DWORD *)v5 + 17) )
          goto LABEL_18;
        if ( v19 )
        {
          v20 = operator new[](4 * v19 + 4);
          *((_DWORD *)v5 + 17) = v20;
          if ( v20 )
            break;
        }
      }
LABEL_20:
      v3 = v53;
      ++v17;
      if ( v17 >= LODWORD(v53->m_timeStamp) + 1 )
        goto LABEL_21;
    }
    memset(v20, 0, 4 * *((_DWORD *)v5 + 16) + 4);
LABEL_18:
    v21 = *((_DWORD *)v5 + 17);
    v22 = *(_DWORD *)(v21 + 4 * v17);
    v23 = v21 + 4 * v17;
    if ( !v22 )
      *(_DWORD *)v23 = sizeb;
    goto LABEL_20;
  }
LABEL_21:
  v24 = 0;
  if ( v3->m_pNext != (DBObj *)-1 )
  {
    while ( 1 )
    {
      v25 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v26 = *((_DWORD *)v5 + 18);
      sizec = v25;
      if ( v24 <= v26 )
      {
        if ( *((_DWORD *)v5 + 19) )
          goto LABEL_27;
        if ( v26 )
        {
          v27 = operator new[](4 * v26 + 4);
          *((_DWORD *)v5 + 19) = v27;
          if ( v27 )
            break;
        }
      }
LABEL_29:
      v3 = v53;
      ++v24;
      if ( (InterfaceVtbl **)v24 >= (InterfaceVtbl **)((char *)&v53->m_pNext->vfptr + 1) )
        goto LABEL_30;
    }
    memset(v27, 0, 4 * *((_DWORD *)v5 + 18) + 4);
LABEL_27:
    v28 = *((_DWORD *)v5 + 19);
    v29 = *(_DWORD *)(v28 + 4 * v24);
    v30 = v28 + 4 * v24;
    if ( !v29 )
      *(_DWORD *)v30 = sizec;
    goto LABEL_29;
  }
LABEL_30:
  v31 = 0;
  if ( v3->m_pMaintainer != (DBOCache *)-1 )
  {
    while ( 1 )
    {
      v32 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v33 = *((_DWORD *)v5 + 20);
      sized = v32;
      if ( v31 <= v33 )
      {
        if ( *((_DWORD *)v5 + 21) )
          goto LABEL_36;
        if ( v33 )
        {
          v34 = operator new[](4 * v33 + 4);
          *((_DWORD *)v5 + 21) = v34;
          if ( v34 )
            break;
        }
      }
LABEL_38:
      v3 = v53;
      ++v31;
      if ( (DBOCacheVtbl **)v31 >= (DBOCacheVtbl **)((char *)&v53->m_pMaintainer->vfptr + 1) )
        goto LABEL_39;
    }
    memset(v34, 0, 4 * *((_DWORD *)v5 + 20) + 4);
LABEL_36:
    v35 = *((_DWORD *)v5 + 21);
    v36 = *(_DWORD *)(v35 + 4 * v31);
    v37 = v35 + 4 * v31;
    if ( !v36 )
      *(_DWORD *)v37 = sized;
    goto LABEL_38;
  }
LABEL_39:
  v38 = 0;
  if ( v3->m_DID.id != -1 )
  {
    while ( 1 )
    {
      v39 = *(_DWORD *)*addr;
      v40 = *((_DWORD *)*addr + 1);
      *addr = (char *)*addr + 8;
      v41 = *((_DWORD *)v5 + 22);
      xp64 = __PAIR__(v40, v39);
      if ( v38 <= v41 )
      {
        if ( *((_DWORD *)v5 + 23) )
          goto LABEL_45;
        if ( v41 )
        {
          v42 = operator new[](8 * v41 + 8);
          *((_DWORD *)v5 + 23) = v42;
          if ( v42 )
            break;
        }
      }
LABEL_47:
      v3 = v53;
      ++v38;
      if ( v38 >= v53->m_DID.id + 1 )
        goto LABEL_48;
    }
    memset(v42, 0, 8 * *((_DWORD *)v5 + 22) + 8);
LABEL_45:
    v43 = *((_DWORD *)v5 + 23);
    v44 = *(_QWORD *)(v43 + 8 * v38) == 0i64;
    v45 = v43 + 8 * v38;
    if ( v44 )
      *(_QWORD *)v45 = xp64;
    goto LABEL_47;
  }
LABEL_48:
  v46 = 0;
  if ( v3->m_DID.id != -1 )
  {
    do
    {
      v47 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v48 = *((_DWORD *)v5 + 22);
      sizee = v47;
      if ( v46 <= v48 )
      {
        if ( !*((_DWORD *)v5 + 24) )
        {
          if ( !v48 )
            goto LABEL_56;
          v49 = operator new[](4 * v48 + 4);
          *((_DWORD *)v5 + 24) = v49;
          if ( !v49 )
            goto LABEL_56;
          memset(v49, 0, 4 * *((_DWORD *)v5 + 22) + 4);
        }
        v50 = *((_DWORD *)v5 + 24);
        v51 = *(_DWORD *)(v50 + 4 * v46);
        v52 = v50 + 4 * v46;
        if ( !v51 )
          *(_DWORD *)v52 = sizee;
      }
LABEL_56:
      ++v46;
    }
    while ( v46 < v53->m_DID.id + 1 );
  }
  return 1;
}

//----- (005CA500) --------------------------------------------------------  // acclient.c:501738
ExperienceTable *__thiscall ExperienceTable::vector_deleting_destructor(ExperienceTable *this, unsigned int a2)
{
  ExperienceTable *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&ExperienceTable::vftable;
  this->vfptr = (PackObjVtbl *)&ExperienceTable::vftable;
  ExperienceTable::Clear(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7FA8: using guessed type void *ExperienceTable::vftable;
// 7E7FC0: using guessed type __int32 (__stdcall *ExperienceTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070FBF0) --------------------------------------------------------  // acclient.c:802985
int sub_70FBF0()
{
  return atexit(nullsub_1766);
}

//----- (0070FC00) --------------------------------------------------------  // acclient.c:802991
int _E4_20()
{
  return atexit(_E5_20);
}

//----- (0070FC10) --------------------------------------------------------  // acclient.c:802997
int _E7_20()
{
  Outside_CellID_20.id = Invalid_CellID_20.id + 1;
  return atexit(_E8_20);
}

//----- (0070FC30) --------------------------------------------------------  // acclient.c:803004
int _E10_19()
{
  In_Limbo_CellID_19.id = Outside_CellID_20.id + 1;
  return atexit(_E11_19);
}

//----- (0070FC50) --------------------------------------------------------  // acclient.c:803011
int _E13_19()
{
  First_Interior_CellID_19.id = In_Limbo_CellID_19.id + 1;
  return atexit(_E14_19);
}

//----- (0070FC70) --------------------------------------------------------  // acclient.c:803018
int _E16_19()
{
  Last_Interior_CellID_19.id = Invalid_CellID_20.id - 1;
  return atexit(_E17_19);
}

//----- (0070FC90) --------------------------------------------------------  // acclient.c:803025
int _E21_21()
{
  return atexit(_E22_21);
}

//----- (0070FCA0) --------------------------------------------------------  // acclient.c:803031
int _E40_21()
{
  return atexit(_E41_21);
}

//----- (0070FCB0) --------------------------------------------------------  // acclient.c:803037
int _E43_24()
{
  return atexit(_E44_24);
}

