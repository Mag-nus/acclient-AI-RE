/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmMasterDBMap
   Object     : GAME\game_database\gmMasterDBMap.obj
   Functions  : 6
   Addresses  : 005D5980 - 007104D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D5980) --------------------------------------------------------  // acclient.c:514290
signed int __stdcall gmMasterDBMap::DivineType_Internal(IDClass<_tagDataID,32,0> did)
{
  if ( did.id > 0xE000018 )
  {
    if ( did.id > 0xE00001D )
    {
      if ( did.id > 0x3000FFFF )
      {
        if ( did.id <= 0x3800FFFF && did.id >= 0x38000000 )
          return 268435470;
      }
      else
      {
        if ( did.id >= 0x30000000 )
          return 268435469;
        if ( did.id <= 0xE01FFFF && did.id >= 0xE010000 )
          return 268435468;
      }
    }
    else
    {
      if ( did.id >= 0xE00001D )
        return 268435472;
      if ( did.id > 0xE00001B )
      {
        if ( did.id <= 0xE00001C && did.id >= 0xE00001C )
          return 268435467;
      }
      else
      {
        if ( did.id >= 0xE00001B )
          return 268435466;
        if ( did.id <= 0xE000019 && did.id >= 0xE000019 )
          return 268435464;
      }
    }
  }
  else
  {
    if ( did.id >= 0xE000018 )
      return 268435465;
    if ( did.id > 0xE000004 )
    {
      if ( did.id > 0xE00000F )
      {
        if ( did.id <= 0xE000011 && did.id >= 0xE000011 )
          return 268435463;
      }
      else
      {
        if ( did.id >= 0xE00000F )
          return 268435462;
        if ( did.id <= 0xE00000E && did.id >= 0xE00000E )
          return 268435461;
      }
    }
    else
    {
      if ( did.id >= 0xE000004 )
        return 268435460;
      if ( did.id > 0xE000002 )
      {
        if ( did.id <= 0xE000003 && did.id >= 0xE000003 )
          return 268435459;
      }
      else
      {
        if ( did.id >= 0xE000002 )
          return 268435458;
        if ( did.id <= 0xFFFF && did.id >= 1 )
          return 268435457;
      }
    }
  }
  return MasterDBMap::DivineType_Internal(did);
}

//----- (005D5AD0) --------------------------------------------------------  // acclient.c:514368
signed int __thiscall gmMasterDBMap::DivineType_Internal(gmMasterDBMap *this, PStringBase<char> *filename)
{
  PSRefBufferCharData<char> *v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // esi@10
  int v6; // edi@12
  int v7; // esi@14
  int v8; // esi@16
  int v9; // esi@18
  int v10; // esi@23
  int v11; // esi@25
  int v12; // esi@27
  int v13; // eax@29
  char *v14; // esi@29
  bool v15; // bl@29
  char *v16; // esi@33
  int v17; // eax@39
  int v18; // eax@40
  int v19; // esi@42
  int v20; // esi@44
  int v21; // esi@46
  int v22; // eax@48
  char *v23; // esi@48
  bool v24; // bl@48
  int v25; // esi@55
  int v26; // eax@57
  char *v27; // esi@57
  bool v28; // bl@57
  signed int v29; // eax@62
  char *v30; // esi@62
  signed int v31; // edi@62
  PStringBase<char> ext; // [sp+10h] [bp-44h]@1
  PStringBase<char> v33; // [sp+14h] [bp-40h]@10
  PStringBase<char> v34; // [sp+18h] [bp-3Ch]@12
  PStringBase<char> v35; // [sp+1Ch] [bp-38h]@14
  PStringBase<char> v36; // [sp+20h] [bp-34h]@16
  PStringBase<char> v37; // [sp+24h] [bp-30h]@18
  PStringBase<char> v38; // [sp+28h] [bp-2Ch]@23
  PStringBase<char> v39; // [sp+2Ch] [bp-28h]@25
  PStringBase<char> v40; // [sp+30h] [bp-24h]@27
  PStringBase<char> v41; // [sp+34h] [bp-20h]@29
  PStringBase<char> v42; // [sp+38h] [bp-1Ch]@42
  PStringBase<char> v43; // [sp+3Ch] [bp-18h]@44
  PStringBase<char> v44; // [sp+40h] [bp-14h]@46
  PStringBase<char> v45; // [sp+44h] [bp-10h]@48
  PStringBase<char> v46; // [sp+48h] [bp-Ch]@55
  PStringBase<char> v47; // [sp+4Ch] [bp-8h]@57
  MasterDBMap *v48; // [sp+50h] [bp-4h]@1

  v48 = (MasterDBMap *)this;
  PSUtils::get_extension(&ext, filename);
  PStringBase<char>::break_reference(&ext);
  __strlwr(ext.m_charbuffer->m_data);
  v2 = ext.m_charbuffer;
  v3 = *(_DWORD *)&ext.m_charbuffer[-1].m_data[8];
  if ( v3 == -1 )
  {
    v3 = compute_str_hash(ext.m_charbuffer->m_data);
    *(_DWORD *)&v2[-1].m_data[8] = v3;
  }
  if ( v3 > 0x35D42 )
  {
    if ( v3 > 0x35E9B )
    {
      if ( v3 == 220851 )
      {
        PStringBase<char>::PStringBase<char>(&v47, ".wts");
        v26 = __stricmp(ext.m_charbuffer->m_data, v47.m_charbuffer->m_data);
        v27 = &v47.m_charbuffer[-2].m_data[12];
        v28 = v26 == 0;
        if ( !InterlockedDecrement((volatile LONG *)&v47.m_charbuffer[-1]) && v27 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
        if ( v28 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 268435463;
        }
      }
      else if ( v3 == 221044 )
      {
        PStringBase<char>::PStringBase<char>(&v46, ".xpt");
        v25 = __stricmp(ext.m_charbuffer->m_data, v46.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v46);
        if ( !v25 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 268435465;
        }
      }
    }
    else if ( v3 == 220827 )
    {
      PStringBase<char>::PStringBase<char>(&v45, ".wsk");
      v22 = __stricmp(ext.m_charbuffer->m_data, v45.m_charbuffer->m_data);
      v23 = &v45.m_charbuffer[-2].m_data[12];
      v24 = v22 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v45.m_charbuffer[-1]) && v23 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
      if ( v24 )
      {
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
        return 268435460;
      }
    }
    else
    {
      v17 = v3 - 220580;
      if ( v17 )
      {
        v18 = v17 - 2;
        if ( v18 )
        {
          if ( v18 == 208 )
          {
            PStringBase<char>::PStringBase<char>(&v42, ".wqf");
            v19 = __stricmp(ext.m_charbuffer->m_data, v42.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v42);
            if ( !v19 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 268435468;
            }
          }
        }
        else
        {
          PStringBase<char>::PStringBase<char>(&v43, ".wdf");
          v20 = __stricmp(ext.m_charbuffer->m_data, v43.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v43);
          if ( !v20 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435457;
          }
        }
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&v44, ".wct");
        v21 = __stricmp(ext.m_charbuffer->m_data, v44.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v44);
        if ( !v21 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 268435469;
        }
      }
    }
    goto LABEL_62;
  }
  if ( v3 != 220482 )
  {
    if ( v3 > 0x35036 )
    {
      switch ( v3 )
      {
        case 0x357A4u:
          PStringBase<char>::PStringBase<char>(&v40, ".qdd");
          v12 = __stricmp(ext.m_charbuffer->m_data, v40.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v40);
          if ( !v12 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435466;
          }
          break;
        case 0x359A4u:
          PStringBase<char>::PStringBase<char>(&v39, ".sct");
          v11 = __stricmp(ext.m_charbuffer->m_data, v39.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v39);
          if ( !v11 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435462;
          }
          break;
        case 0x35A74u:
          PStringBase<char>::PStringBase<char>(&v38, ".spt");
          v10 = __stricmp(ext.m_charbuffer->m_data, v38.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v38);
          if ( !v10 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435461;
          }
          break;
      }
    }
    else
    {
      switch ( v3 )
      {
        case 0x35036u:
          PStringBase<char>::PStringBase<char>(&v37, ".imf");
          v9 = __stricmp(ext.m_charbuffer->m_data, v37.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v37);
          if ( !v9 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435470;
          }
          break;
        case 0x34793u:
          PStringBase<char>::PStringBase<char>(&v36, ".acc");
          v8 = __stricmp(ext.m_charbuffer->m_data, v36.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v36);
          if ( !v8 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435472;
          }
          break;
        case 0x349D4u:
          PStringBase<char>::PStringBase<char>(&v34, ".cgd");
          v6 = __stricmp(ext.m_charbuffer->m_data, v34.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v34);
          if ( !v6 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435458;
          }
          PStringBase<char>::PStringBase<char>(&v35, ".cft");
          v7 = __stricmp(ext.m_charbuffer->m_data, v35.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v35);
          if ( !v7 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435464;
          }
          break;
        case 0x34DB4u:
          PStringBase<char>::PStringBase<char>(&v33, ".ged");
          v4 = __stricmp(ext.m_charbuffer->m_data, v33.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v33);
          if ( !v4 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 268435467;
          }
          break;
      }
    }
    goto LABEL_62;
  }
  PStringBase<char>::PStringBase<char>(&v41, ".wa2");
  v13 = __stricmp(ext.m_charbuffer->m_data, v41.m_charbuffer->m_data);
  v14 = &v41.m_charbuffer[-2].m_data[12];
  v15 = v13 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  if ( !v15 )
  {
LABEL_62:
    v29 = MasterDBMap::DivineType_Internal(filename);
    v30 = &ext.m_charbuffer[-2].m_data[12];
    v31 = v29;
    if ( !InterlockedDecrement((volatile LONG *)&ext.m_charbuffer[-1]) )
    {
      if ( v30 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    }
    return v31;
  }
  v16 = &ext.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ext.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  return 268435459;
}

//----- (005D60C0) --------------------------------------------------------  // acclient.c:514638
char __thiscall gmMasterDBMap::InqTypeByString_Internal(gmMasterDBMap *this, PStringBase<char> *i_sType, unsigned int *o_eType)
{
  PSRefBufferCharData<char> *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int *v5; // edi@3
  int v6; // esi@10
  int v7; // esi@12
  int v8; // esi@14
  int v9; // esi@16
  int v10; // esi@21
  int v11; // esi@23
  int v12; // esi@25
  int v13; // eax@27
  char *v14; // esi@27
  bool v15; // bl@27
  int v16; // esi@37
  int v17; // esi@39
  int v18; // esi@41
  int v19; // eax@43
  char *v20; // esi@43
  bool v21; // bl@43
  int v22; // esi@51
  int v23; // esi@53
  int v24; // eax@55
  char *v25; // esi@55
  bool v26; // bl@55
  char v27; // al@60
  char *v28; // esi@60
  char v29; // bl@60
  PStringBase<char> sType; // [sp+10h] [bp-40h]@1
  PStringBase<char> v32; // [sp+14h] [bp-3Ch]@12
  PStringBase<char> v33; // [sp+18h] [bp-38h]@14
  PStringBase<char> v34; // [sp+1Ch] [bp-34h]@16
  PStringBase<char> v35; // [sp+20h] [bp-30h]@21
  PStringBase<char> v36; // [sp+24h] [bp-2Ch]@23
  PStringBase<char> v37; // [sp+28h] [bp-28h]@25
  PStringBase<char> v38; // [sp+2Ch] [bp-24h]@27
  PStringBase<char> v39; // [sp+30h] [bp-20h]@37
  PStringBase<char> v40; // [sp+34h] [bp-1Ch]@39
  PStringBase<char> v41; // [sp+38h] [bp-18h]@41
  PStringBase<char> v42; // [sp+3Ch] [bp-14h]@43
  PStringBase<char> v43; // [sp+40h] [bp-10h]@51
  PStringBase<char> v44; // [sp+44h] [bp-Ch]@53
  PStringBase<char> v45; // [sp+48h] [bp-8h]@55
  MasterDBMap *v46; // [sp+4Ch] [bp-4h]@1

  sType.m_charbuffer = i_sType->m_charbuffer;
  v46 = (MasterDBMap *)this;
  InterlockedIncrement((volatile LONG *)&sType.m_charbuffer[-1]);
  PStringBase<char>::break_reference(&sType);
  __strlwr(sType.m_charbuffer->m_data);
  v3 = sType.m_charbuffer;
  v4 = *(_DWORD *)&sType.m_charbuffer[-1].m_data[8];
  if ( v4 == -1 )
  {
    v4 = compute_str_hash(sType.m_charbuffer->m_data);
    *(_DWORD *)&v3[-1].m_data[8] = v4;
  }
  v5 = o_eType;
  if ( v4 > 0x78631B2 )
  {
    if ( v4 > 0xA6A67B5 )
    {
      switch ( v4 )
      {
        case 0xB4C8F32u:
          PStringBase<char>::PStringBase<char>(&v45, "QUEST_DEF_DB");
          v24 = __stricmp(sType.m_charbuffer->m_data, v45.m_charbuffer->m_data);
          v25 = &v45.m_charbuffer[-2].m_data[12];
          v26 = v24 == 0;
          if ( !InterlockedDecrement((volatile LONG *)&v45.m_charbuffer[-1]) && v25 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
          if ( v26 )
            *v5 = 268435466;
          break;
        case 0xCB8E025u:
          PStringBase<char>::PStringBase<char>(&v44, "ATTRIBUTE_2ND_TABLE");
          v23 = __stricmp(sType.m_charbuffer->m_data, v44.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v44);
          if ( !v23 )
            *v5 = 268435459;
          break;
        case 0xCD1C98Du:
          PStringBase<char>::PStringBase<char>(&v43, "W_TREASURE_SYSTEM");
          v22 = __stricmp(sType.m_charbuffer->m_data, v43.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v43);
          if ( !v22 )
            *v5 = 268435463;
          break;
      }
    }
    else
    {
      switch ( v4 )
      {
        case 0xA6A67B5u:
          PStringBase<char>::PStringBase<char>(&v42, "XP_TABLE");
          v19 = __stricmp(sType.m_charbuffer->m_data, v42.m_charbuffer->m_data);
          v20 = &v42.m_charbuffer[-2].m_data[12];
          v21 = v19 == 0;
          if ( !InterlockedDecrement((volatile LONG *)&v42.m_charbuffer[-1]) && v20 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
          if ( v21 )
            *v5 = 268435465;
          break;
        case 0x7C6B192u:
          PStringBase<char>::PStringBase<char>(&v41, "MUTATE_FILTER");
          v18 = __stricmp(sType.m_charbuffer->m_data, v41.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v41);
          if ( !v18 )
            *v5 = 268435470;
          break;
        case 0x86041B5u:
          PStringBase<char>::PStringBase<char>(&v40, "COMBAT_TABLE");
          v17 = __stricmp(sType.m_charbuffer->m_data, v40.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v40);
          if ( !v17 )
            *v5 = 268435469;
          break;
        case 0x8DD0DD5u:
          PStringBase<char>::PStringBase<char>(&v39, "SPELLCOMPONENT_TABLE");
          v16 = __stricmp(sType.m_charbuffer->m_data, v39.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v39);
          if ( !v16 )
            *v5 = 268435462;
          break;
      }
    }
  }
  else if ( v4 == 126235058 )
  {
    PStringBase<char>::PStringBase<char>(&v38, "GAME_EVENT_DB");
    v13 = __stricmp(sType.m_charbuffer->m_data, v38.m_charbuffer->m_data);
    v14 = &v38.m_charbuffer[-2].m_data[12];
    v15 = v13 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v38.m_charbuffer[-1]) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    if ( v15 )
      *v5 = 268435467;
  }
  else if ( v4 > 0x288404E )
  {
    switch ( v4 )
    {
      case 0x3F0FF15u:
        PStringBase<char>::PStringBase<char>(&v37, "W_CRAFT_TABLE");
        v12 = __stricmp(sType.m_charbuffer->m_data, v37.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v37);
        if ( !v12 )
          *v5 = 268435464;
        break;
      case 0x431E285u:
        PStringBase<char>::PStringBase<char>(&v36, "CONTRACT_TABLE");
        v11 = __stricmp(sType.m_charbuffer->m_data, v36.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v36);
        if ( !v11 )
          *v5 = 268435472;
        break;
      case 0x4E5ED76u:
        PStringBase<char>::PStringBase<char>(&v35, "WEENIE_DEF");
        v10 = __stricmp(sType.m_charbuffer->m_data, v35.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v35);
        if ( !v10 )
          *v5 = 268435457;
        break;
    }
  }
  else
  {
    switch ( v4 )
    {
      case 0x288404Eu:
        PStringBase<char>::PStringBase<char>(&v34, "CHAR_GEN");
        v9 = __stricmp(sType.m_charbuffer->m_data, v34.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v34);
        if ( !v9 )
          *v5 = 268435458;
        break;
      case 0x186D515u:
        PStringBase<char>::PStringBase<char>(&v33, "SPELL_TABLE");
        v8 = __stricmp(sType.m_charbuffer->m_data, v33.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v33);
        if ( !v8 )
          *v5 = 268435461;
        break;
      case 0x19A9915u:
        PStringBase<char>::PStringBase<char>(&v32, "SKILL_TABLE");
        v7 = __stricmp(sType.m_charbuffer->m_data, v32.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v32);
        if ( !v7 )
          *v5 = 268435460;
        break;
      case 0x24D2FD2u:
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&o_eType, "QUALITY_FILTER");
        v6 = __stricmp(sType.m_charbuffer->m_data, (const char *)o_eType);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&o_eType);
        if ( !v6 )
          *v5 = 268435468;
        break;
    }
  }
  v27 = MasterDBMap::InqTypeByString_Internal(i_sType, v5);
  v28 = &sType.m_charbuffer[-2].m_data[12];
  v29 = v27;
  if ( !InterlockedDecrement((volatile LONG *)&sType.m_charbuffer[-1]) && v28 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
  return v29;
}

//----- (005D65F0) --------------------------------------------------------  // acclient.c:514848
char __stdcall gmMasterDBMap::InqStringByType_Internal(unsigned int i_eType, PStringBase<char> *o_sType)
{
  switch ( i_eType )
  {
    case 0x10000001u:
      PStringBase<char>::set(o_sType, "WEENIE_DEF");
      break;
    case 0x10000002u:
      PStringBase<char>::set(o_sType, "CHAR_GEN");
      break;
    case 0x10000003u:
      PStringBase<char>::set(o_sType, "ATTRIBUTE_2ND_TABLE");
      break;
    case 0x10000004u:
      PStringBase<char>::set(o_sType, "SKILL_TABLE");
      break;
    case 0x10000005u:
      PStringBase<char>::set(o_sType, "SPELL_TABLE");
      break;
    case 0x10000006u:
      PStringBase<char>::set(o_sType, "SPELLCOMPONENT_TABLE");
      break;
    case 0x10000007u:
      PStringBase<char>::set(o_sType, "W_TREASURE_SYSTEM");
      break;
    case 0x10000008u:
      PStringBase<char>::set(o_sType, "W_CRAFT_TABLE");
      break;
    case 0x10000009u:
      PStringBase<char>::set(o_sType, "XP_TABLE");
      break;
    case 0x1000000Au:
      PStringBase<char>::set(o_sType, "QUEST_DEF_DB");
      break;
    case 0x1000000Bu:
      PStringBase<char>::set(o_sType, "GAME_EVENT_DB");
      break;
    case 0x1000000Cu:
      PStringBase<char>::set(o_sType, "QUALITY_FILTER");
      break;
    case 0x1000000Du:
      PStringBase<char>::set(o_sType, "COMBAT_TABLE");
      break;
    case 0x1000000Eu:
      PStringBase<char>::set(o_sType, "MUTATE_FILTER");
      break;
    case 0x10000010u:
      PStringBase<char>::set(o_sType, "CONTRACT_TABLE");
      break;
    default:
      return MasterDBMap::InqStringByType_Internal(i_eType, o_sType);
  }
  return MasterDBMap::InqStringByType_Internal(i_eType, o_sType);
}

//----- (005D66D0) --------------------------------------------------------  // acclient.c:514904
char __thiscall gmMasterDBMap::InitDBTypeDef_Internal(gmMasterDBMap *this)
{
  char *v1; // ebp@1
  char v2; // al@46
  char *v3; // ebp@46
  char v5; // [sp+41h] [bp-45h]@46
  PStringBase<char> i_rData; // [sp+42h] [bp-44h]@1
  char *v7; // [sp+46h] [bp-40h]@4
  MasterDBMap *v8; // [sp+4Ah] [bp-3Ch]@1
  DBTypeDef def; // [sp+4Eh] [bp-38h]@1

  v8 = (MasterDBMap *)this;
  DBTypeDef::DBTypeDef(&def);
  def.m_base_did.id = 1;
  def.m_top_did.id = 0xFFFF;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wdf");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v1 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/defaults");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_WEENIE_DEF, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881026;
  def.m_top_did.id = 234881026;
  PStringBase<char>::PStringBase<char>(&i_rData, ".cgd");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_CHAR_GEN_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881027;
  def.m_top_did.id = 234881027;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wa2");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/skills");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ATTRIBUTE_2ND_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881028;
  def.m_top_did.id = 234881028;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wsk");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/skills");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SKILL_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881038;
  def.m_top_did.id = 234881038;
  PStringBase<char>::PStringBase<char>(&i_rData, ".spt");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/magic");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SPELL_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881039;
  def.m_top_did.id = 234881039;
  PStringBase<char>::PStringBase<char>(&i_rData, ".sct");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/magic");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SPELLCOMPONENT_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881041;
  def.m_top_did.id = 234881041;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wts");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/treasure");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_W_TREASURE_SYSTEM, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881049;
  def.m_top_did.id = 234881049;
  PStringBase<char>::PStringBase<char>(&i_rData, ".cft");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/craft");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_W_CRAFT_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881048;
  def.m_top_did.id = 234881048;
  PStringBase<char>::PStringBase<char>(&i_rData, ".xpt");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/experience");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_XP_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881051;
  def.m_top_did.id = 234881051;
  PStringBase<char>::PStringBase<char>(&i_rData, ".qdd");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_QUEST_DEF_DB_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881052;
  def.m_top_did.id = 234881052;
  PStringBase<char>::PStringBase<char>(&i_rData, ".ged");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_GAME_EVENT_DB, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234946560;
  def.m_top_did.id = 235012095;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wqf");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/filters");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_QUALITY_FILTER_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 805306368;
  def.m_top_did.id = 805371903;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wct");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/combat_tables");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_COMBAT_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 939524096;
  def.m_top_did.id = 939589631;
  PStringBase<char>::PStringBase<char>(&i_rData, ".imf");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie/ItemMutationFiles");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MUTATE_FILTER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881053;
  def.m_top_did.id = 234881053;
  PStringBase<char>::PStringBase<char>(&i_rData, ".acc");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__stdcall ***)(_DWORD))v7)(1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 0;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_CONTRACT_TABLE_0, &def);
  def.m_extensions.m_num = 0;
  v2 = MasterDBMap::InitDBTypeDef_Internal();
  v3 = &def.m_strDataDir.m_charbuffer[-2].m_data[12];
  v5 = v2;
  if ( !InterlockedDecrement((volatile LONG *)&def.m_strDataDir.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( (def.m_extensions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && def.m_extensions.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor(def.m_extensions.m_data, 3u);
  return v5;
}

//----- (007104D0) --------------------------------------------------------  // acclient.c:803579
int sub_7104D0()
{
  return atexit(nullsub_1849);
}

