/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MasterDBMap
   Object     : ENGINE\filedb_core\MasterDBMap.obj
   Functions  : 10
   Addresses  : 0041C460 - 006C4AC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0041C460) --------------------------------------------------------  // acclient.c:89734
signed int __stdcall MasterDBMap::DivineType_Internal(IDClass<_tagDataID,32,0> did)
{
  if ( did.id > 0x1400FFFF )
  {
    if ( did.id > 0x2600FFFF )
    {
      if ( did.id > 0x39FFFFFF )
      {
        if ( did.id > 0x41FFFFFF )
        {
          if ( did.id <= 0x7FFFFFFF )
            return did.id < 0x78000000 ? 0 : 49;
        }
        else
        {
          if ( did.id >= 0x41000000 )
            return 48;
          if ( did.id <= 0x40FFFFFF )
          {
            if ( did.id >= 0x40001000 )
              return 47;
            if ( did.id <= 0x40000FFF )
              return did.id < 0x40000000 ? 0 : 46;
          }
        }
      }
      else
      {
        if ( did.id >= 0x39000000 )
          return 45;
        if ( did.id > 0x3200FFFF )
        {
          if ( did.id <= 0x3400FFFF )
          {
            if ( did.id >= 0x34000000 )
              return 44;
            if ( did.id <= 0x3300FFFF )
              return did.id < 0x33000000 ? 0 : 43;
          }
        }
        else
        {
          if ( did.id >= 0x32000000 )
            return 42;
          if ( did.id <= 0x3100FFFF )
          {
            if ( did.id >= 0x31000000 )
              return 41;
            if ( did.id <= 0x27FFFFFF )
              return did.id < 0x27000000 ? 0 : 40;
          }
        }
      }
    }
    else
    {
      if ( did.id >= 0x26000000 )
        return 39;
      if ( did.id > 0x2000FFFF )
      {
        if ( did.id > 0x24FFFFFF )
        {
          if ( did.id <= 0x25FFFFFF )
            return did.id < 0x25000000 ? 0 : 38;
        }
        else
        {
          if ( did.id >= 0x23000000 )
            return 37;
          if ( did.id <= 0x22FFFFFF )
          {
            if ( did.id >= 0x22000000 )
              return 36;
            if ( did.id <= 0x21FFFFFF )
              return did.id < 0x21000000 ? 0 : 35;
          }
        }
      }
      else
      {
        if ( did.id >= 0x20000000 )
          return 34;
        if ( did.id > 0x17FFFFFF )
        {
          if ( did.id <= 0x19FFFFFF )
          {
            if ( did.id >= 0x19000000 )
              return 67;
            if ( did.id <= 0x18FFFFFF )
              return did.id < 0x18000000 ? 0 : 33;
          }
        }
        else
        {
          if ( did.id >= 0x17000000 )
            return 32;
          if ( did.id <= 0x16FFFFFF )
          {
            if ( did.id >= 0x16000000 )
              return 31;
            if ( did.id <= 0x15FFFFFF )
              return did.id < 0x15000000 ? 0 : 30;
          }
        }
      }
    }
  }
  else
  {
    if ( did.id >= 0x14000000 )
      return 29;
    if ( did.id > 0xE00000D )
    {
      if ( did.id > 0xF00FFFF )
      {
        if ( did.id > 0x1200FFFF )
        {
          if ( did.id <= 0x1300FFFF )
            return did.id < 0x13000000 ? 0 : 28;
        }
        else
        {
          if ( did.id >= 0x12000000 )
            return 27;
          if ( did.id <= 0x1100FFFF )
          {
            if ( did.id >= 0x11000000 )
              return 26;
            if ( did.id <= 0x1000FFFF )
              return did.id < 0x10000000 ? 0 : 25;
          }
        }
      }
      else
      {
        if ( did.id >= 0xF000000 )
          return 24;
        if ( did.id > 0xE00001F )
        {
          if ( did.id <= 0xE02FFFF )
          {
            if ( did.id >= 0xE020000 )
              return 23;
            if ( did.id <= 0xE000020 )
              return did.id < 0xE000020 ? 0 : 22;
          }
        }
        else
        {
          if ( did.id >= 0xE00001F )
            return 21;
          if ( did.id <= 0xE00001E )
          {
            if ( did.id >= 0xE00001E )
              return 20;
            if ( did.id <= 0xE00001A )
              return did.id < 0xE00001A ? 0 : 19;
          }
        }
      }
    }
    else
    {
      if ( did.id >= 0xE00000D )
        return 18;
      if ( did.id > 0x7FFFFFF )
      {
        if ( did.id > 0xA00FFFF )
        {
          if ( did.id <= 0xE000007 )
          {
            if ( did.id >= 0xE000007 )
              return 17;
            if ( did.id <= 0xD00FFFF )
              return did.id < 0xD000000 ? 0 : 16;
          }
        }
        else
        {
          if ( did.id >= 0xA000000 )
            return 15;
          if ( did.id <= 0x900FFFF )
          {
            if ( did.id >= 0x9000000 )
              return 14;
            if ( did.id <= 0x800FFFF )
              return did.id < 0x8000000 ? 0 : 13;
          }
        }
      }
      else
      {
        if ( did.id >= 0x6000000 )
          return 12;
        if ( did.id > 0x300FFFF )
        {
          if ( did.id <= 0x5FFFFFF )
          {
            if ( did.id >= 0x5000000 )
              return 11;
            if ( did.id <= 0x400FFFF )
              return did.id < 0x4000000 ? 0 : 10;
          }
        }
        else
        {
          if ( did.id >= 0x3000000 )
            return 8;
          if ( did.id <= 0x200FFFF )
          {
            if ( did.id >= 0x2000000 )
              return 7;
            if ( did.id <= 0x100FFFF )
              return did.id < 0x1000000 ? 0 : 6;
          }
        }
      }
    }
  }
  return 0;
}

//----- (0041C8A0) --------------------------------------------------------  // acclient.c:89957
void __thiscall PStringBase<char>::tolower(PStringBase<char> *this)
{
  char **v1; // esi@1

  v1 = (char **)this;
  PStringBase<char>::break_reference(this);
  __strlwr(*v1);
}

//----- (0041C8C0) --------------------------------------------------------  // acclient.c:89967
signed int __stdcall MasterDBMap::DivineType_Internal(PStringBase<char> *filename)
{
  PSRefBufferCharData<char> *v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // eax@11
  int v5; // eax@12
  int v6; // eax@14
  PStringBase<char> *v7; // ecx@14
  int v8; // esi@15
  int v10; // esi@17
  int v11; // esi@19
  int v12; // eax@21
  int v13; // eax@22
  int v14; // esi@24
  int v15; // esi@26
  int v16; // esi@29
  int v17; // eax@33
  int v18; // eax@34
  int v19; // esi@38
  int v20; // esi@40
  int v21; // esi@44
  int v22; // esi@46
  int v23; // esi@48
  int v24; // eax@54
  int v25; // eax@55
  int v26; // esi@58
  int v27; // esi@60
  int v28; // esi@62
  int v29; // esi@67
  int v30; // esi@69
  int v31; // esi@76
  int v32; // esi@78
  int v33; // esi@80
  int v34; // esi@82
  int v35; // esi@86
  int v36; // esi@88
  int v37; // eax@90
  char *v38; // esi@90
  bool v39; // bl@90
  char *v40; // esi@94
  int v41; // esi@107
  int v42; // esi@109
  int v43; // esi@111
  int v44; // esi@113
  int v45; // esi@117
  int v46; // esi@119
  int v47; // esi@121
  int v48; // eax@125
  int v49; // eax@126
  int v50; // esi@129
  int v51; // eax@131
  PStringBase<char> *v52; // ecx@131
  int v53; // esi@132
  int v54; // esi@134
  int v55; // eax@138
  PStringBase<char> *v56; // ecx@138
  int v57; // esi@139
  int v58; // eax@141
  char *v59; // esi@141
  bool v60; // bl@141
  int v61; // esi@153
  int v62; // esi@156
  int v63; // esi@158
  int v64; // esi@160
  int v65; // esi@164
  int v66; // esi@166
  int v67; // esi@174
  int v68; // esi@176
  int v69; // esi@178
  int v70; // esi@180
  int v71; // esi@185
  int v72; // esi@187
  int v73; // esi@190
  PStringBase<char> ext; // [sp+Ch] [bp-E4h]@1
  PStringBase<char> v75; // [sp+10h] [bp-E0h]@88
  PStringBase<char> v76; // [sp+14h] [bp-DCh]@90
  PStringBase<char> v77; // [sp+18h] [bp-D8h]@15
  PStringBase<char> v78; // [sp+1Ch] [bp-D4h]@107
  PStringBase<char> v79; // [sp+20h] [bp-D0h]@19
  PStringBase<char> v80; // [sp+24h] [bp-CCh]@109
  PStringBase<char> v81; // [sp+28h] [bp-C8h]@26
  PStringBase<char> v82; // [sp+2Ch] [bp-C4h]@111
  PStringBase<char> v83; // [sp+30h] [bp-C0h]@29
  PStringBase<char> v84; // [sp+34h] [bp-BCh]@113
  PStringBase<char> v85; // [sp+38h] [bp-B8h]@37
  PStringBase<char> v86; // [sp+3Ch] [bp-B4h]@117
  PStringBase<char> v87; // [sp+40h] [bp-B0h]@40
  PStringBase<char> v88; // [sp+44h] [bp-ACh]@119
  PStringBase<char> v89; // [sp+48h] [bp-A8h]@46
  PStringBase<char> v90; // [sp+4Ch] [bp-A4h]@121
  PStringBase<char> v91; // [sp+50h] [bp-A0h]@57
  PStringBase<char> v92; // [sp+54h] [bp-9Ch]@128
  PStringBase<char> v93; // [sp+58h] [bp-98h]@60
  PStringBase<char> v94; // [sp+5Ch] [bp-94h]@131
  PStringBase<char> v95; // [sp+60h] [bp-90h]@66
  PStringBase<char> v96; // [sp+64h] [bp-8Ch]@132
  PStringBase<char> v97; // [sp+68h] [bp-88h]@69
  PStringBase<char> v98; // [sp+6Ch] [bp-84h]@134
  PStringBase<char> v99; // [sp+70h] [bp-80h]@78
  PStringBase<char> v100; // [sp+74h] [bp-7Ch]@138
  PStringBase<char> v101; // [sp+78h] [bp-78h]@82
  PStringBase<char> v102; // [sp+7Ch] [bp-74h]@139
  PStringBase<char> v103; // [sp+80h] [bp-70h]@14
  PStringBase<char> v104; // [sp+84h] [bp-6Ch]@141
  PStringBase<char> v105; // [sp+88h] [bp-68h]@24
  PStringBase<char> v106; // [sp+8Ch] [bp-64h]@153
  PStringBase<char> v107; // [sp+90h] [bp-60h]@36
  PStringBase<char> v108; // [sp+94h] [bp-5Ch]@155
  PStringBase<char> v109; // [sp+98h] [bp-58h]@44
  PStringBase<char> v110; // [sp+9Ch] [bp-54h]@158
  PStringBase<char> v111; // [sp+A0h] [bp-50h]@58
  PStringBase<char> v112; // [sp+A4h] [bp-4Ch]@160
  PStringBase<char> v113; // [sp+A8h] [bp-48h]@67
  PStringBase<char> v114; // [sp+ACh] [bp-44h]@164
  PStringBase<char> v115; // [sp+B0h] [bp-40h]@80
  PStringBase<char> v116; // [sp+B4h] [bp-3Ch]@166
  PStringBase<char> v117; // [sp+B8h] [bp-38h]@17
  PStringBase<char> v118; // [sp+BCh] [bp-34h]@168
  PStringBase<char> v119; // [sp+C0h] [bp-30h]@38
  PStringBase<char> v120; // [sp+C4h] [bp-2Ch]@174
  PStringBase<char> v121; // [sp+C8h] [bp-28h]@62
  PStringBase<char> v122; // [sp+CCh] [bp-24h]@176
  PStringBase<char> v123; // [sp+D0h] [bp-20h]@86
  PStringBase<char> v124; // [sp+D4h] [bp-1Ch]@178
  PStringBase<char> v125; // [sp+D8h] [bp-18h]@48
  PStringBase<char> v126; // [sp+DCh] [bp-14h]@180
  PStringBase<char> v127; // [sp+E0h] [bp-10h]@28
  PStringBase<char> v128; // [sp+E4h] [bp-Ch]@184
  PStringBase<char> v129; // [sp+E8h] [bp-8h]@76
  PStringBase<char> v130; // [sp+ECh] [bp-4h]@187

  PSUtils::get_extension(&ext, filename);
  PStringBase<char>::break_reference(&ext);
  __strlwr(ext.m_charbuffer->m_data);
  v2 = ext.m_charbuffer;
  v3 = *(_DWORD *)&ext.m_charbuffer[-1].m_data[8];
  if ( v3 == -1 )
  {
    v3 = compute_str_hash(ext.m_charbuffer->m_data);
    *(_DWORD *)&v2[-1].m_data[8] = v3;
    v2 = ext.m_charbuffer;
  }
  if ( v3 > 0x356C3 )
  {
    if ( v3 > 0x34B040 )
    {
      if ( v3 > 0xABA5BAE )
      {
        if ( v3 <= 0xAFEB0D8 )
        {
          if ( v3 == 184463576 )
          {
            PStringBase<char>::PStringBase<char>(&v126, ".rendermesh");
            v70 = __stricmp(ext.m_charbuffer->m_data, v126.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v126);
            if ( !v70 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 67;
            }
            goto LABEL_189;
          }
          if ( v3 == 180929733 )
          {
            PStringBase<char>::PStringBase<char>(&v124, ".surface");
            v69 = __stricmp(ext.m_charbuffer->m_data, v124.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v124);
            if ( !v69 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 13;
            }
            goto LABEL_189;
          }
          if ( v3 == 181373205 )
          {
            PStringBase<char>::PStringBase<char>(&v122, ".rtexture");
            v68 = __stricmp(ext.m_charbuffer->m_data, v122.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v122);
            if ( !v68 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 30;
            }
            goto LABEL_189;
          }
          if ( v3 == 181387221 )
          {
            PStringBase<char>::PStringBase<char>(&v120, ".texture");
            v67 = __stricmp(ext.m_charbuffer->m_data, v120.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v120);
            if ( !v67 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 11;
            }
            goto LABEL_189;
          }
          goto LABEL_190;
        }
        if ( v3 == 185013280 )
        {
          PStringBase<char>::PStringBase<char>(&v130, ".actionmap");
          v72 = __stricmp(ext.m_charbuffer->m_data, v130.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v130);
          if ( !v72 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 39;
          }
          goto LABEL_189;
        }
        if ( v3 != 195383353 )
          goto LABEL_190;
        PStringBase<char>::PStringBase<char>(&v128, ".stt_ansi");
        v51 = __stricmp(ext.m_charbuffer->m_data, v128.m_charbuffer->m_data);
        v52 = &v128;
        goto LABEL_185;
      }
      if ( v3 == 179985326 )
      {
        PStringBase<char>::PStringBase<char>(&v118, ".stt_bin");
        v51 = __stricmp(ext.m_charbuffer->m_data, v118.m_charbuffer->m_data);
        v52 = &v118;
        goto LABEL_185;
      }
      if ( v3 > 0x4657C30 )
      {
        if ( v3 == 85787568 )
        {
          PStringBase<char>::PStringBase<char>(&v116, ".keymap");
          v66 = __stricmp(ext.m_charbuffer->m_data, v116.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v116);
          if ( !v66 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 29;
          }
          goto LABEL_189;
        }
        if ( v3 == 175607596 )
        {
          PStringBase<char>::PStringBase<char>(&v114, ".font_local");
          v65 = __stricmp(ext.m_charbuffer->m_data, v114.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v114);
          if ( !v65 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 47;
          }
          goto LABEL_189;
        }
        goto LABEL_190;
      }
      if ( v3 == 73759792 )
      {
        PStringBase<char>::PStringBase<char>(&v112, ".monprop");
        v64 = __stricmp(ext.m_charbuffer->m_data, v112.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v112);
        if ( !v64 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 23;
        }
        goto LABEL_189;
      }
      if ( v3 == 3462740 )
      {
        PStringBase<char>::PStringBase<char>(&v110, ".font");
        v63 = __stricmp(ext.m_charbuffer->m_data, v110.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v110);
        if ( !v63 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 46;
        }
        goto LABEL_189;
      }
      if ( v3 != 3502980 )
      {
        if ( v3 == 56260959 )
        {
          PStringBase<char>::PStringBase<char>(&v106, ".taboo");
          v61 = __stricmp(ext.m_charbuffer->m_data, v106.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v106);
          if ( !v61 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 20;
          }
          goto LABEL_189;
        }
        goto LABEL_190;
      }
      PStringBase<char>::PStringBase<char>(&v108, ".pmat");
      v55 = __stricmp(ext.m_charbuffer->m_data, v108.m_charbuffer->m_data);
      v56 = &v108;
    }
    else
    {
      if ( v3 == 3452992 )
      {
        PStringBase<char>::PStringBase<char>(&v104, ".dimp");
        v58 = __stricmp(ext.m_charbuffer->m_data, v104.m_charbuffer->m_data);
        v59 = &v104.m_charbuffer[-2].m_data[12];
        v60 = v58 == 0;
        if ( !InterlockedDecrement((volatile LONG *)&v104.m_charbuffer[-1]) && v59 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v59)(v59, 1);
        if ( v60 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 40;
        }
        goto LABEL_189;
      }
      if ( v3 <= 0x35AA9 )
      {
        if ( v3 == 219817 )
        {
          PStringBase<char>::PStringBase<char>(&v90, ".sti");
          v47 = __stricmp(ext.m_charbuffer->m_data, v90.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v90);
          if ( !v47 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 48;
          }
        }
        else if ( v3 > 0x3599E )
        {
          if ( v3 == 219588 )
          {
            PStringBase<char>::PStringBase<char>(&v88, ".set");
            v46 = __stricmp(ext.m_charbuffer->m_data, v88.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v88);
            if ( !v46 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 7;
            }
          }
          else
          {
            if ( v3 != 219810 )
              goto LABEL_190;
            PStringBase<char>::PStringBase<char>(&v86, ".stb");
            v45 = __stricmp(ext.m_charbuffer->m_data, v86.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v86);
            if ( !v45 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 34;
            }
          }
        }
        else
        {
          switch ( v3 )
          {
            case 0x3599Eu:
              PStringBase<char>::PStringBase<char>(&v84, ".scn");
              v44 = __stricmp(ext.m_charbuffer->m_data, v84.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v84);
              if ( !v44 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 27;
              }
              break;
            case 0x356C4u:
              PStringBase<char>::PStringBase<char>(&v82, ".pet");
              v43 = __stricmp(ext.m_charbuffer->m_data, v82.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v82);
              if ( !v43 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 44;
              }
              break;
            case 0x357A4u:
              PStringBase<char>::PStringBase<char>(&v80, ".pst");
              v42 = __stricmp(ext.m_charbuffer->m_data, v80.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v80);
              if ( !v42 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 24;
              }
              break;
            default:
              if ( v3 != 219358 )
                goto LABEL_190;
              PStringBase<char>::PStringBase<char>(&v78, ".rgn");
              v41 = __stricmp(ext.m_charbuffer->m_data, v78.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v78);
              if ( !v41 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 28;
              }
              break;
          }
        }
        goto LABEL_189;
      }
      if ( v3 <= 0x35BFC )
      {
        if ( v3 == 220156 )
        {
          PStringBase<char>::PStringBase<char>(&v98, ".uil");
          v54 = __stricmp(ext.m_charbuffer->m_data, v98.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v98);
          if ( !v54 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 35;
          }
          goto LABEL_189;
        }
        v48 = v3 - 219826;
        if ( !v48 )
        {
          PStringBase<char>::PStringBase<char>(&v96, ".str");
          v53 = __stricmp(ext.m_charbuffer->m_data, v96.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v96);
          if ( !v53 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 41;
          }
          goto LABEL_189;
        }
        v49 = v48 - 2;
        if ( v49 )
        {
          if ( v49 != 29 )
            goto LABEL_190;
          PStringBase<char>::PStringBase<char>(&v92, ".tga");
          v6 = __stricmp(ext.m_charbuffer->m_data, v92.m_charbuffer->m_data);
          v7 = &v92;
          goto LABEL_129;
        }
        PStringBase<char>::PStringBase<char>(&v94, ".stt");
        v51 = __stricmp(ext.m_charbuffer->m_data, v94.m_charbuffer->m_data);
        v52 = &v94;
LABEL_185:
        v71 = v51;
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v52);
        if ( !v71 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 37;
        }
        goto LABEL_189;
      }
      if ( v3 == 220550 )
      {
        PStringBase<char>::PStringBase<char>(&v102, ".wav");
        v57 = __stricmp(ext.m_charbuffer->m_data, v102.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v102);
        if ( !v57 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 15;
        }
        goto LABEL_189;
      }
      if ( v3 != 3451235 )
        goto LABEL_190;
      PStringBase<char>::PStringBase<char>(&v100, ".dbpc");
      v55 = __stricmp(ext.m_charbuffer->m_data, v100.m_charbuffer->m_data);
      v56 = &v100;
    }
    v62 = v55;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v56);
    if ( !v62 )
    {
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
      return 49;
    }
    goto LABEL_189;
  }
  if ( v3 != 218819 )
  {
    if ( v3 > 0x34C44 )
    {
      if ( v3 > 0x35289 )
      {
        if ( v3 > 0x354D4 )
        {
          if ( v3 == 218506 )
          {
            PStringBase<char>::PStringBase<char>(&v75, ".obj");
            v36 = __stricmp(ext.m_charbuffer->m_data, v75.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v75);
            if ( !v36 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 6;
            }
          }
          else
          {
            if ( v3 != 218748 )
              goto LABEL_190;
            PStringBase<char>::PStringBase<char>(&v123, ".pal");
            v35 = __stricmp(ext.m_charbuffer->m_data, v123.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v123);
            if ( !v35 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 10;
            }
          }
        }
        else
        {
          switch ( v3 )
          {
            case 0x354D4u:
              PStringBase<char>::PStringBase<char>(&v101, ".nft");
              v34 = __stricmp(ext.m_charbuffer->m_data, v101.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v101);
              if ( !v34 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 22;
              }
              break;
            case 0x3528Fu:
              PStringBase<char>::PStringBase<char>(&v115, ".lbo");
              v33 = __stricmp(ext.m_charbuffer->m_data, v115.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v115);
              if ( !v33 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 4;
              }
              break;
            case 0x35384u:
              PStringBase<char>::PStringBase<char>(&v99, ".mat");
              v32 = __stricmp(ext.m_charbuffer->m_data, v99.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v99);
              if ( !v32 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 31;
              }
              break;
            default:
              if ( v3 != 218226 )
                goto LABEL_190;
              PStringBase<char>::PStringBase<char>(&v129, ".mpr");
              v31 = __stricmp(ext.m_charbuffer->m_data, v129.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v129);
              if ( !v31 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 45;
              }
              break;
          }
        }
        goto LABEL_189;
      }
      if ( v3 == 217737 )
      {
        PStringBase<char>::PStringBase<char>(&v97, ".lbi");
        v30 = __stricmp(ext.m_charbuffer->m_data, v97.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v97);
        if ( !v30 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 2;
        }
        goto LABEL_189;
      }
      if ( v3 > 0x35040 )
      {
        if ( v3 == 217171 )
        {
          PStringBase<char>::PStringBase<char>(&v113, ".ins");
          v29 = __stricmp(ext.m_charbuffer->m_data, v113.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v113);
          if ( !v29 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 5;
          }
          goto LABEL_189;
        }
        if ( v3 != 217447 )
          goto LABEL_190;
        PStringBase<char>::PStringBase<char>(&v95, ".jpg");
        v6 = __stricmp(ext.m_charbuffer->m_data, v95.m_charbuffer->m_data);
        v7 = &v95;
      }
      else
      {
        if ( v3 == 217152 )
        {
          PStringBase<char>::PStringBase<char>(&v121, ".imp");
          v28 = __stricmp(ext.m_charbuffer->m_data, v121.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v121);
          if ( !v28 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 38;
          }
          goto LABEL_189;
        }
        v24 = v3 - 216150;
        if ( !v24 )
        {
          PStringBase<char>::PStringBase<char>(&v93, ".env");
          v27 = __stricmp(ext.m_charbuffer->m_data, v93.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v93);
          if ( !v27 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 16;
          }
          goto LABEL_189;
        }
        v25 = v24 - 813;
        if ( !v25 )
        {
          PStringBase<char>::PStringBase<char>(&v111, ".hrc");
          v26 = __stricmp(ext.m_charbuffer->m_data, v111.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v111);
          if ( !v26 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 18;
          }
          goto LABEL_189;
        }
        if ( v25 != 67 )
          goto LABEL_190;
        PStringBase<char>::PStringBase<char>(&v91, ".iff");
        v6 = __stricmp(ext.m_charbuffer->m_data, v91.m_charbuffer->m_data);
        v7 = &v91;
      }
    }
    else
    {
      if ( v3 == 216132 )
      {
        PStringBase<char>::PStringBase<char>(&v125, ".emt");
        v23 = __stricmp(ext.m_charbuffer->m_data, v125.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v125);
        if ( !v23 )
        {
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
          return 42;
        }
        goto LABEL_189;
      }
      if ( v3 > 0x34A2F )
      {
        if ( v3 > 0x34AB7 )
        {
          if ( v3 == 215955 )
          {
            PStringBase<char>::PStringBase<char>(&v89, ".dsc");
            v22 = __stricmp(ext.m_charbuffer->m_data, v89.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v89);
            if ( !v22 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 14;
            }
          }
          else
          {
            if ( v3 != 216128 )
              goto LABEL_190;
            PStringBase<char>::PStringBase<char>(&v109, ".emp");
            v21 = __stricmp(ext.m_charbuffer->m_data, v109.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v109);
            if ( !v21 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 36;
            }
          }
          goto LABEL_189;
        }
        if ( v3 == 215735 )
        {
          PStringBase<char>::PStringBase<char>(&v87, ".deg");
          v20 = __stricmp(ext.m_charbuffer->m_data, v87.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v87);
          if ( !v20 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 26;
          }
          goto LABEL_189;
        }
        v17 = v3 - 215667;
        if ( !v17 )
        {
          PStringBase<char>::PStringBase<char>(&v119, ".cps");
          v19 = __stricmp(ext.m_charbuffer->m_data, v119.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v119);
          if ( !v19 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 17;
          }
          goto LABEL_189;
        }
        v18 = v17 - 38;
        if ( v18 )
        {
          if ( v18 != 26 )
            goto LABEL_190;
          PStringBase<char>::PStringBase<char>(&v107, ".dds");
          v6 = __stricmp(ext.m_charbuffer->m_data, v107.m_charbuffer->m_data);
          v7 = &v107;
        }
        else
        {
          PStringBase<char>::PStringBase<char>(&v85, ".csi");
          v6 = __stricmp(ext.m_charbuffer->m_data, v85.m_charbuffer->m_data);
          v7 = &v85;
        }
      }
      else
      {
        if ( v3 == 215599 )
        {
          PStringBase<char>::PStringBase<char>(&v83, ".clo");
          v16 = __stricmp(ext.m_charbuffer->m_data, v83.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v83);
          if ( !v16 )
          {
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
            return 25;
          }
          goto LABEL_189;
        }
        if ( v3 <= 0x347EB )
        {
          if ( v3 == 215019 )
          {
            PStringBase<char>::PStringBase<char>(&v79, ".ahk");
            v11 = __stricmp(ext.m_charbuffer->m_data, v79.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v79);
            if ( !v11 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 9;
            }
          }
          else
          {
            v4 = v3 - 13625;
            if ( v4 )
            {
              v5 = v4 - 4;
              if ( v5 )
              {
                if ( v5 == 188489 )
                {
                  PStringBase<char>::PStringBase<char>(&v103, ".256");
                  v6 = __stricmp(ext.m_charbuffer->m_data, v103.m_charbuffer->m_data);
                  v7 = &v103;
                  goto LABEL_129;
                }
LABEL_190:
                v73 = (int)&v2[-2].m_data[12];
                if ( !InterlockedDecrement((volatile LONG *)(v73 + 4)) )
                {
                  if ( v73 )
                    (**(void (__thiscall ***)(_DWORD, _DWORD))v73)(v73, 1);
                }
                return 0;
              }
              PStringBase<char>::PStringBase<char>(&v77, ".mm");
              v8 = __stricmp(ext.m_charbuffer->m_data, v77.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v77);
              if ( !v8 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 32;
              }
            }
            else
            {
              PStringBase<char>::PStringBase<char>(&v117, ".mi");
              v10 = __stricmp(ext.m_charbuffer->m_data, v117.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v117);
              if ( !v10 )
              {
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
                return 33;
              }
            }
          }
LABEL_189:
          v2 = ext.m_charbuffer;
          goto LABEL_190;
        }
        v12 = v3 - 215088;
        if ( v12 )
        {
          v13 = v12 - 29;
          if ( v13 )
          {
            if ( v13 != 39 )
              goto LABEL_190;
            PStringBase<char>::PStringBase<char>(&v105, ".bad");
            v14 = __stricmp(ext.m_charbuffer->m_data, v105.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v105);
            if ( !v14 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 19;
            }
          }
          else
          {
            PStringBase<char>::PStringBase<char>(&v81, ".anm");
            v15 = __stricmp(ext.m_charbuffer->m_data, v81.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v81);
            if ( !v15 )
            {
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
              return 8;
            }
          }
          goto LABEL_189;
        }
        PStringBase<char>::PStringBase<char>(&v127, ".alp");
        v6 = __stricmp(ext.m_charbuffer->m_data, v127.m_charbuffer->m_data);
        v7 = &v127;
      }
    }
LABEL_129:
    v50 = v6;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v7);
    if ( !v50 )
    {
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&ext);
      return 12;
    }
    goto LABEL_189;
  }
  PStringBase<char>::PStringBase<char>(&v76, ".pes");
  v37 = __stricmp(ext.m_charbuffer->m_data, v76.m_charbuffer->m_data);
  v38 = &v76.m_charbuffer[-2].m_data[12];
  v39 = v37 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v76.m_charbuffer[-1]) && v38 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v38)(v38, 1);
  if ( !v39 )
    goto LABEL_189;
  v40 = &ext.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ext.m_charbuffer[-1]) && v40 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v40)(v40, 1);
  return 43;
}

//----- (0041DCA0) --------------------------------------------------------  // acclient.c:90832
char __stdcall MasterDBMap::InqTypeByString_Internal(PStringBase<char> *i_sType, unsigned int *o_eType)
{
  char v3; // bl@1
  PSRefBufferCharData<char> *v4; // esi@1
  unsigned int v5; // eax@1
  int v6; // eax@11
  int v7; // eax@12
  int v8; // esi@14
  int v9; // esi@16
  int v10; // esi@18
  int v11; // esi@20
  int v12; // esi@24
  int v13; // esi@26
  int v14; // esi@28
  int v15; // esi@34
  int v16; // esi@36
  int v17; // esi@38
  int v18; // esi@42
  int v19; // esi@44
  int v20; // esi@46
  int v21; // esi@55
  int v22; // esi@57
  int v23; // esi@59
  int v24; // esi@61
  int v25; // esi@65
  int v26; // esi@67
  int v27; // esi@69
  int v28; // esi@75
  int v29; // esi@77
  int v30; // esi@79
  int v31; // esi@83
  int v32; // esi@85
  int v33; // eax@87
  char *v34; // esi@87
  int v35; // esi@101
  int v36; // esi@103
  int v37; // esi@105
  int v38; // esi@107
  int v39; // esi@111
  int v40; // esi@113
  int v41; // esi@115
  int v42; // esi@121
  int v43; // esi@123
  int v44; // esi@125
  int v45; // esi@129
  int v46; // esi@131
  char *v47; // esi@133
  int v48; // esi@144
  int v49; // esi@146
  int v50; // esi@148
  int v51; // esi@152
  int v52; // esi@154
  int v53; // esi@156
  int v54; // esi@162
  int v55; // esi@164
  int v56; // esi@166
  int v57; // esi@170
  int v58; // esi@172
  char *v59; // esi@175
  PStringBase<char> sType; // [sp+8h] [bp-D0h]@1
  bool v62; // [sp+Fh] [bp-C9h]@87
  PStringBase<char> v63; // [sp+10h] [bp-C8h]@83
  PStringBase<char> v64; // [sp+14h] [bp-C4h]@87
  PStringBase<char> v65; // [sp+18h] [bp-C0h]@16
  PStringBase<char> v66; // [sp+1Ch] [bp-BCh]@101
  PStringBase<char> v67; // [sp+20h] [bp-B8h]@20
  PStringBase<char> v68; // [sp+24h] [bp-B4h]@103
  PStringBase<char> v69; // [sp+28h] [bp-B0h]@26
  PStringBase<char> v70; // [sp+2Ch] [bp-ACh]@105
  PStringBase<char> v71; // [sp+30h] [bp-A8h]@34
  PStringBase<char> v72; // [sp+34h] [bp-A4h]@107
  PStringBase<char> v73; // [sp+38h] [bp-A0h]@38
  PStringBase<char> v74; // [sp+3Ch] [bp-9Ch]@111
  PStringBase<char> v75; // [sp+40h] [bp-98h]@44
  PStringBase<char> v76; // [sp+44h] [bp-94h]@113
  PStringBase<char> v77; // [sp+48h] [bp-90h]@55
  PStringBase<char> v78; // [sp+4Ch] [bp-8Ch]@115
  PStringBase<char> v79; // [sp+50h] [bp-88h]@59
  PStringBase<char> v80; // [sp+54h] [bp-84h]@121
  PStringBase<char> v81; // [sp+58h] [bp-80h]@65
  PStringBase<char> v82; // [sp+5Ch] [bp-7Ch]@123
  PStringBase<char> v83; // [sp+60h] [bp-78h]@69
  PStringBase<char> v84; // [sp+64h] [bp-74h]@125
  PStringBase<char> v85; // [sp+68h] [bp-70h]@77
  PStringBase<char> v86; // [sp+6Ch] [bp-6Ch]@129
  PStringBase<char> v87; // [sp+70h] [bp-68h]@14
  PStringBase<char> v88; // [sp+74h] [bp-64h]@131
  PStringBase<char> v89; // [sp+78h] [bp-60h]@18
  PStringBase<char> v90; // [sp+7Ch] [bp-5Ch]@133
  PStringBase<char> v91; // [sp+80h] [bp-58h]@28
  PStringBase<char> v92; // [sp+84h] [bp-54h]@144
  PStringBase<char> v93; // [sp+88h] [bp-50h]@42
  PStringBase<char> v94; // [sp+8Ch] [bp-4Ch]@146
  PStringBase<char> v95; // [sp+90h] [bp-48h]@57
  PStringBase<char> v96; // [sp+94h] [bp-44h]@148
  PStringBase<char> v97; // [sp+98h] [bp-40h]@67
  PStringBase<char> v98; // [sp+9Ch] [bp-3Ch]@152
  PStringBase<char> v99; // [sp+A0h] [bp-38h]@79
  PStringBase<char> v100; // [sp+A4h] [bp-34h]@154
  PStringBase<char> v101; // [sp+A8h] [bp-30h]@24
  PStringBase<char> v102; // [sp+ACh] [bp-2Ch]@156
  PStringBase<char> v103; // [sp+B0h] [bp-28h]@46
  PStringBase<char> v104; // [sp+B4h] [bp-24h]@162
  PStringBase<char> v105; // [sp+B8h] [bp-20h]@75
  PStringBase<char> v106; // [sp+BCh] [bp-1Ch]@164
  PStringBase<char> v107; // [sp+C0h] [bp-18h]@36
  PStringBase<char> v108; // [sp+C4h] [bp-14h]@166
  PStringBase<char> v109; // [sp+C8h] [bp-10h]@85
  PStringBase<char> v110; // [sp+CCh] [bp-Ch]@170
  PStringBase<char> v111; // [sp+D0h] [bp-8h]@61
  PStringBase<char> v112; // [sp+D4h] [bp-4h]@172

  sType.m_charbuffer = i_sType->m_charbuffer;
  v3 = 0;
  InterlockedIncrement((volatile LONG *)&sType.m_charbuffer[-1]);
  PStringBase<char>::break_reference(&sType);
  __strlwr(sType.m_charbuffer->m_data);
  v4 = sType.m_charbuffer;
  v5 = *(_DWORD *)&sType.m_charbuffer[-1].m_data[8];
  if ( v5 == -1 )
  {
    v5 = compute_str_hash(sType.m_charbuffer->m_data);
    *(_DWORD *)&v4[-1].m_data[8] = v5;
  }
  if ( v5 > 0x6779A4F )
  {
    if ( v5 > 0xCF90DC5 )
    {
      if ( v5 > 0xE710390 )
      {
        if ( v5 > 0xEC79057 )
        {
          if ( v5 == 250077262 )
          {
            PStringBase<char>::PStringBase<char>(&v112, "REGION");
            v58 = __stricmp(sType.m_charbuffer->m_data, v112.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v112);
            if ( !v58 )
            {
              *o_eType = 28;
              goto LABEL_174;
            }
          }
          else if ( v5 == 258667079 )
          {
            PStringBase<char>::PStringBase<char>(&v110, "CLOTHING");
            v57 = __stricmp(sType.m_charbuffer->m_data, v110.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v110);
            if ( !v57 )
            {
              *o_eType = 25;
              goto LABEL_174;
            }
          }
        }
        else
        {
          switch ( v5 )
          {
            case 0xEC79057u:
              PStringBase<char>::PStringBase<char>(&v108, "STRING");
              v56 = __stricmp(sType.m_charbuffer->m_data, v108.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v108);
              if ( !v56 )
              {
                *o_eType = 41;
                goto LABEL_174;
              }
              break;
            case 0xEBAA971u:
              PStringBase<char>::PStringBase<char>(&v106, "BADDATA");
              v55 = __stricmp(sType.m_charbuffer->m_data, v106.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v106);
              if ( !v55 )
              {
                *o_eType = 19;
                goto LABEL_174;
              }
              break;
            case 0xEC67935u:
              PStringBase<char>::PStringBase<char>(&v104, "STABLE");
              v54 = __stricmp(sType.m_charbuffer->m_data, v104.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v104);
              if ( !v54 )
              {
                *o_eType = 34;
                goto LABEL_174;
              }
              break;
          }
        }
      }
      else if ( v5 == 242287504 )
      {
        PStringBase<char>::PStringBase<char>(&v102, "KEYMAP");
        v53 = __stricmp(sType.m_charbuffer->m_data, v102.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v102);
        if ( !v53 )
        {
          *o_eType = 29;
          goto LABEL_174;
        }
      }
      else if ( v5 > 0xDB1F59A )
      {
        if ( v5 == 236717106 )
        {
          PStringBase<char>::PStringBase<char>(&v100, "DUAL_DID_MAPPER");
          v52 = __stricmp(sType.m_charbuffer->m_data, v100.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v100);
          if ( !v52 )
          {
            *o_eType = 40;
            goto LABEL_174;
          }
        }
        else if ( v5 == 237402421 )
        {
          PStringBase<char>::PStringBase<char>(&v98, "MTABLE");
          v51 = __stricmp(sType.m_charbuffer->m_data, v98.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v98);
          if ( !v51 )
          {
            *o_eType = 14;
            goto LABEL_174;
          }
        }
      }
      else
      {
        switch ( v5 )
        {
          case 0xDB1F59Au:
            PStringBase<char>::PStringBase<char>(&v96, "GFXOBJ");
            v50 = __stricmp(sType.m_charbuffer->m_data, v96.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v96);
            if ( !v50 )
            {
              *o_eType = 6;
              goto LABEL_174;
            }
            break;
          case 0xD4683BBu:
            PStringBase<char>::PStringBase<char>(&v94, "ANIMATION_HOOK");
            v49 = __stricmp(sType.m_charbuffer->m_data, v94.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v94);
            if ( !v49 )
            {
              *o_eType = 9;
              goto LABEL_174;
            }
            break;
          case 0xDACB838u:
            PStringBase<char>::PStringBase<char>(&v92, "RENDER_MESH");
            v48 = __stricmp(sType.m_charbuffer->m_data, v92.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v92);
            if ( !v48 )
            {
              *o_eType = 67;
              goto LABEL_174;
            }
            break;
        }
      }
    }
    else if ( v5 == 217648581 )
    {
      PStringBase<char>::PStringBase<char>(&v90, "PHYSICS_SCRIPT_TABLE");
      v62 = __stricmp(sType.m_charbuffer->m_data, v90.m_charbuffer->m_data) == 0;
      v47 = &v90.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v90.m_charbuffer[-1]) && v47 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v47)(v47, 1);
      if ( v62 )
      {
        *o_eType = 44;
        goto LABEL_174;
      }
    }
    else if ( v5 > 0xA4779DB )
    {
      if ( v5 > 0xB05A2E0 )
      {
        if ( v5 == 185390771 )
        {
          PStringBase<char>::PStringBase<char>(&v88, "DBPROPERTIES");
          v46 = __stricmp(sType.m_charbuffer->m_data, v88.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v88);
          if ( !v46 )
          {
            *o_eType = 49;
            goto LABEL_174;
          }
        }
        else if ( v5 == 201901685 )
        {
          PStringBase<char>::PStringBase<char>(&v86, "SURFACE");
          v45 = __stricmp(sType.m_charbuffer->m_data, v86.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v86);
          if ( !v45 )
          {
            *o_eType = 13;
            goto LABEL_174;
          }
        }
      }
      else
      {
        switch ( v5 )
        {
          case 0xB05A2E0u:
            PStringBase<char>::PStringBase<char>(&v84, "ACTIONMAP");
            v44 = __stricmp(sType.m_charbuffer->m_data, v84.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v84);
            if ( !v44 )
            {
              *o_eType = 39;
              goto LABEL_174;
            }
            break;
          case 0xA60E32Cu:
            PStringBase<char>::PStringBase<char>(&v82, "FONT_LOCAL");
            v43 = __stricmp(sType.m_charbuffer->m_data, v82.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v82);
            if ( !v43 )
            {
              *o_eType = 47;
              goto LABEL_174;
            }
            break;
          case 0xA9BA754u:
            PStringBase<char>::PStringBase<char>(&v80, "ENVIRONMENT");
            v42 = __stricmp(sType.m_charbuffer->m_data, v80.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v80);
            if ( !v42 )
            {
              *o_eType = 16;
              goto LABEL_174;
            }
            break;
        }
      }
    }
    else if ( v5 == 172456411 )
    {
      PStringBase<char>::PStringBase<char>(&v78, "LAND_BLOCK");
      v41 = __stricmp(sType.m_charbuffer->m_data, v78.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v78);
      if ( !v41 )
      {
        *o_eType = 1;
        goto LABEL_174;
      }
    }
    else if ( v5 > 0x93B52F5 )
    {
      if ( v5 == 155121762 )
      {
        PStringBase<char>::PStringBase<char>(&v76, "MATERIALMODIFIER");
        v40 = __stricmp(sType.m_charbuffer->m_data, v76.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v76);
        if ( !v40 )
        {
          *o_eType = 32;
          goto LABEL_174;
        }
      }
      else if ( v5 == 172219269 )
      {
        PStringBase<char>::PStringBase<char>(&v74, "SURFACETEXTURE");
        v39 = __stricmp(sType.m_charbuffer->m_data, v74.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v74);
        if ( !v39 )
        {
          *o_eType = 11;
          goto LABEL_174;
        }
      }
    }
    else
    {
      switch ( v5 )
      {
        case 0x93B52F5u:
          PStringBase<char>::PStringBase<char>(&v72, "MATERIALINSTANCE");
          v38 = __stricmp(sType.m_charbuffer->m_data, v72.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v72);
          if ( !v38 )
          {
            *o_eType = 33;
            goto LABEL_174;
          }
          break;
        case 0x686C245u:
          PStringBase<char>::PStringBase<char>(&v70, "TABOO_TABLE");
          v37 = __stricmp(sType.m_charbuffer->m_data, v70.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v70);
          if ( !v37 )
          {
            *o_eType = 20;
            goto LABEL_174;
          }
          break;
        case 0x730E209u:
          PStringBase<char>::PStringBase<char>(&v68, "OBJECT_HIERARCHY");
          v36 = __stricmp(sType.m_charbuffer->m_data, v68.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v68);
          if ( !v36 )
          {
            *o_eType = 18;
            goto LABEL_174;
          }
          break;
        case 0x8D7DA23u:
          PStringBase<char>::PStringBase<char>(&v66, "MONITOREDPROPERTIES");
          v35 = __stricmp(sType.m_charbuffer->m_data, v66.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v66);
          if ( !v35 )
          {
            *o_eType = 23;
            goto LABEL_174;
          }
          break;
      }
    }
  }
  else if ( v5 == 108501583 )
  {
    PStringBase<char>::PStringBase<char>(&v64, "DEGRADEINFO");
    v33 = __stricmp(sType.m_charbuffer->m_data, v64.m_charbuffer->m_data);
    v34 = &v64.m_charbuffer[-2].m_data[12];
    v62 = v33 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v64.m_charbuffer[-1]) && v34 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
    if ( v62 )
    {
      *o_eType = 26;
      goto LABEL_174;
    }
  }
  else if ( v5 > 0x29374E4 )
  {
    if ( v5 > 0x4448255 )
    {
      if ( v5 > 0x5E6EAF2 )
      {
        if ( v5 == 103134562 )
        {
          PStringBase<char>::PStringBase<char>(&v109, "DID_MAPPER");
          v32 = __stricmp(sType.m_charbuffer->m_data, v109.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v109);
          if ( !v32 )
          {
            *o_eType = 38;
            goto LABEL_174;
          }
        }
        else if ( v5 == 103361524 )
        {
          PStringBase<char>::PStringBase<char>(&v63, "UI_LAYOUT");
          v31 = __stricmp(sType.m_charbuffer->m_data, v63.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v63);
          if ( !v31 )
          {
            *o_eType = 35;
            goto LABEL_174;
          }
        }
      }
      else
      {
        switch ( v5 )
        {
          case 0x5E6EAF2u:
            PStringBase<char>::PStringBase<char>(&v99, "ENUM_MAPPER");
            v30 = __stricmp(sType.m_charbuffer->m_data, v99.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v99);
            if ( !v30 )
            {
              *o_eType = 36;
              goto LABEL_174;
            }
            break;
          case 0x44B11F5u:
            PStringBase<char>::PStringBase<char>(&v85, "RENDERTEXTURE");
            v29 = __stricmp(sType.m_charbuffer->m_data, v85.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v85);
            if ( !v29 )
            {
              *o_eType = 30;
              goto LABEL_174;
            }
            break;
          case 0x44C6AE5u:
            PStringBase<char>::PStringBase<char>(&v105, "RENDERSURFACE");
            v28 = __stricmp(sType.m_charbuffer->m_data, v105.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v105);
            if ( !v28 )
            {
              *o_eType = 12;
              goto LABEL_174;
            }
            break;
        }
      }
    }
    else if ( v5 == 71598677 )
    {
      PStringBase<char>::PStringBase<char>(&v83, "NAME_FILTER_TABLE");
      v27 = __stricmp(sType.m_charbuffer->m_data, v83.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v83);
      if ( !v27 )
      {
        *o_eType = 22;
        goto LABEL_174;
      }
    }
    else if ( v5 > 0x3CB6A89 )
    {
      if ( v5 == 63812245 )
      {
        PStringBase<char>::PStringBase<char>(&v97, "CHAT_POSE_TABLE");
        v26 = __stricmp(sType.m_charbuffer->m_data, v97.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v97);
        if ( !v26 )
        {
          *o_eType = 17;
          goto LABEL_174;
        }
      }
      else if ( v5 == 69792261 )
      {
        PStringBase<char>::PStringBase<char>(&v81, "FILE2ID_TABLE");
        v25 = __stricmp(sType.m_charbuffer->m_data, v81.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v81);
        if ( !v25 )
        {
          *o_eType = 21;
          goto LABEL_174;
        }
      }
    }
    else
    {
      switch ( v5 )
      {
        case 0x3CB6A89u:
          PStringBase<char>::PStringBase<char>(&v111, "MASTER_PROPERTY");
          v24 = __stricmp(sType.m_charbuffer->m_data, v111.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v111);
          if ( !v24 )
          {
            *o_eType = 45;
            goto LABEL_174;
          }
          break;
        case 0x2E89502u:
          PStringBase<char>::PStringBase<char>(&v79, "PARTICLE_EMITTER");
          v23 = __stricmp(sType.m_charbuffer->m_data, v79.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v79);
          if ( !v23 )
          {
            *o_eType = 42;
            goto LABEL_174;
          }
          break;
        case 0x3AD38F5u:
          PStringBase<char>::PStringBase<char>(&v95, "STRING_STATE");
          v22 = __stricmp(sType.m_charbuffer->m_data, v95.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v95);
          if ( !v22 )
          {
            *o_eType = 48;
            goto LABEL_174;
          }
          break;
        case 0x3ADE975u:
          PStringBase<char>::PStringBase<char>(&v77, "STRING_TABLE");
          v21 = __stricmp(sType.m_charbuffer->m_data, v77.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v77);
          if ( !v21 )
          {
            *o_eType = 37;
            goto LABEL_174;
          }
          break;
      }
    }
  }
  else if ( v5 == 43218148 )
  {
    PStringBase<char>::PStringBase<char>(&v103, "PHYSICS_SCRIPT");
    v20 = __stricmp(sType.m_charbuffer->m_data, v103.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v103);
    if ( !v20 )
    {
      *o_eType = 43;
      goto LABEL_174;
    }
  }
  else if ( v5 > (unsigned int)((char *)&loc_6209DA + 4) )
  {
    if ( v5 > 0xE658AC )
    {
      if ( v5 == 32443328 )
      {
        PStringBase<char>::PStringBase<char>(&v75, "SETUP");
        v19 = __stricmp(sType.m_charbuffer->m_data, v75.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v75);
        if ( !v19 )
        {
          *o_eType = 7;
          goto LABEL_174;
        }
      }
      else if ( v5 == 32463941 )
      {
        PStringBase<char>::PStringBase<char>(&v93, "SCENE");
        v18 = __stricmp(sType.m_charbuffer->m_data, v93.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v93);
        if ( !v18 )
        {
          *o_eType = 27;
          goto LABEL_174;
        }
      }
    }
    else
    {
      switch ( v5 )
      {
        case 0xE658ACu:
          PStringBase<char>::PStringBase<char>(&v73, "RENDERMATERIAL");
          v17 = __stricmp(sType.m_charbuffer->m_data, v73.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v73);
          if ( !v17 )
          {
            *o_eType = 31;
            goto LABEL_174;
          }
          break;
        case 0xC26824u:
          PStringBase<char>::PStringBase<char>(&v107, "PAL_SET");
          v16 = __stricmp(sType.m_charbuffer->m_data, v107.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v107);
          if ( !v16 )
          {
            *o_eType = 24;
            goto LABEL_174;
          }
          break;
        case 0xC2CA45u:
          PStringBase<char>::PStringBase<char>(&v71, "PALETTE");
          v15 = __stricmp(sType.m_charbuffer->m_data, v71.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v71);
          if ( !v15 )
          {
            *o_eType = 10;
            goto LABEL_174;
          }
          break;
      }
    }
  }
  else if ( (_UNKNOWN *)v5 == (_UNKNOWN *)((char *)&loc_6209DA + 4) )
  {
    PStringBase<char>::PStringBase<char>(&v91, "INSTANTIATION");
    v14 = __stricmp(sType.m_charbuffer->m_data, v91.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v91);
    if ( !v14 )
    {
      *o_eType = 5;
      goto LABEL_174;
    }
  }
  else if ( v5 > 0x1DBA54 )
  {
    if ( v5 == 1964076 )
    {
      PStringBase<char>::PStringBase<char>(&v69, "CELL");
      v13 = __stricmp(sType.m_charbuffer->m_data, v69.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v69);
      if ( !v13 )
      {
        *o_eType = 3;
        goto LABEL_174;
      }
    }
    else if ( v5 == 2012357 )
    {
      PStringBase<char>::PStringBase<char>(&v101, "WAVE");
      v12 = __stricmp(sType.m_charbuffer->m_data, v101.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v101);
      if ( !v12 )
      {
        *o_eType = 15;
        goto LABEL_174;
      }
    }
  }
  else if ( v5 == 1948244 )
  {
    PStringBase<char>::PStringBase<char>(&v67, "FONT");
    v11 = __stricmp(sType.m_charbuffer->m_data, v67.m_charbuffer->m_data);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v67);
    if ( !v11 )
    {
      *o_eType = 46;
      goto LABEL_174;
    }
  }
  else
  {
    v6 = v5 - 123977;
    if ( v6 )
    {
      v7 = v6 - 6;
      if ( v7 )
      {
        if ( v7 == 1787054 )
        {
          PStringBase<char>::PStringBase<char>(&v87, "ANIM");
          v8 = __stricmp(sType.m_charbuffer->m_data, v87.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v87);
          if ( !v8 )
          {
            *o_eType = 8;
LABEL_174:
            v3 = 1;
            goto LABEL_175;
          }
        }
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&v65, "LBO");
        v9 = __stricmp(sType.m_charbuffer->m_data, v65.m_charbuffer->m_data);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v65);
        if ( !v9 )
        {
          *o_eType = 4;
          goto LABEL_174;
        }
      }
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&v89, "LBI");
      v10 = __stricmp(sType.m_charbuffer->m_data, v89.m_charbuffer->m_data);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v89);
      if ( !v10 )
      {
        *o_eType = 2;
        goto LABEL_174;
      }
    }
  }
LABEL_175:
  v59 = &sType.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&sType.m_charbuffer[-1]) && v59 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v59)(v59, 1);
  return v3;
}

//----- (0041EE10) --------------------------------------------------------  // acclient.c:91596
SmartArray<PStringBase<char>,1> *__thiscall SmartArray<PStringBase<char>,1>::operator=(SmartArray<PStringBase<char>,1> *this, int a2)
{
  SmartArray<PStringBase<char>,1> *v2; // ebp@1
  int v3; // edi@1
  int v4; // eax@3
  PStringBase<char> *v5; // ebx@3
  unsigned int v6; // esi@3
  int v7; // ecx@3
  PSRefBufferCharData<char> *v8; // eax@4
  int v9; // edi@5
  PSRefBufferCharData<char> *v10; // eax@8
  unsigned int v11; // ebx@10
  PSRefBufferCharData<char> *v12; // esi@13
  volatile LONG *v13; // edi@13
  int v14; // ebx@13
  int v15; // eax@13
  int v16; // ebp@14
  int v17; // esi@18
  int v19; // [sp+Ch] [bp-8h]@3
  unsigned int v20; // [sp+Ch] [bp-8h]@10
  SmartArray<PStringBase<char>,1> *v21; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = a2;
  v21 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<PStringBase<char>,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v4 = *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    v6 = *(_DWORD *)a2;
    v7 = *(_DWORD *)a2 + 4 * v4;
    v19 = *(_DWORD *)a2 + 4 * v4;
    if ( *(_DWORD *)a2 < (unsigned int)v7 )
    {
      do
      {
        v8 = v5->m_charbuffer;
        if ( v5->m_charbuffer != *(PSRefBufferCharData<char> **)v6 )
        {
          v9 = (int)&v8[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
          v10 = *(PSRefBufferCharData<char> **)v6;
          v5->m_charbuffer = *(PSRefBufferCharData<char> **)v6;
          InterlockedIncrement((volatile LONG *)&v10[-1]);
          v3 = a2;
          v7 = v19;
        }
        v6 += 4;
        ++v5;
      }
      while ( v6 < v7 );
    }
    v11 = *(_DWORD *)(v3 + 8);
    v20 = *(_DWORD *)(v3 + 8);
    if ( v11 < v2->m_num )
    {
      while ( 1 )
      {
        v12 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v13 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v14 = (int)&v2->m_data[v11];
        v15 = *(_DWORD *)v14;
        if ( *(PSRefBufferCharData<char> **)v14 != v12 )
        {
          v16 = v15 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v15 - 20 + 4)) && v16 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
          *(_DWORD *)v14 = v12;
          InterlockedIncrement(v13);
          v2 = v21;
        }
        v17 = (int)&v12[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        ++v20;
        if ( v20 >= v2->m_num )
          break;
        v11 = v20;
      }
      v3 = a2;
    }
    v2->m_num = *(_DWORD *)(v3 + 8);
  }
  return v2;
}

//----- (0041EF50) --------------------------------------------------------  // acclient.c:91686
char __stdcall MasterDBMap::InqStringByType_Internal(unsigned int i_eType, PStringBase<char> *o_sType)
{
  char result; // al@1

  result = 0;
  switch ( i_eType )
  {
    case 1u:
      PStringBase<char>::set(o_sType, "LAND_BLOCK");
      result = 1;
      break;
    case 2u:
      PStringBase<char>::set(o_sType, "LBI");
      result = 1;
      break;
    case 3u:
      PStringBase<char>::set(o_sType, "CELL");
      result = 1;
      break;
    case 4u:
      PStringBase<char>::set(o_sType, "LBO");
      result = 1;
      break;
    case 5u:
      PStringBase<char>::set(o_sType, "INSTANTIATION");
      result = 1;
      break;
    case 6u:
      PStringBase<char>::set(o_sType, "GFXOBJ");
      result = 1;
      break;
    case 7u:
      PStringBase<char>::set(o_sType, "SETUP");
      result = 1;
      break;
    case 8u:
      PStringBase<char>::set(o_sType, "ANIM");
      result = 1;
      break;
    case 9u:
      PStringBase<char>::set(o_sType, "ANIMATION_HOOK");
      result = 1;
      break;
    case 0xAu:
      PStringBase<char>::set(o_sType, "PALETTE");
      result = 1;
      break;
    case 0xBu:
      PStringBase<char>::set(o_sType, "SURFACETEXTURE");
      result = 1;
      break;
    case 0xCu:
      PStringBase<char>::set(o_sType, "RENDERSURFACE");
      result = 1;
      break;
    case 0xDu:
      PStringBase<char>::set(o_sType, "SURFACE");
      result = 1;
      break;
    case 0xEu:
      PStringBase<char>::set(o_sType, "MTABLE");
      result = 1;
      break;
    case 0xFu:
      PStringBase<char>::set(o_sType, "WAVE");
      result = 1;
      break;
    case 0x10u:
      PStringBase<char>::set(o_sType, "ENVIRONMENT");
      result = 1;
      break;
    case 0x11u:
      PStringBase<char>::set(o_sType, "CHAT_POSE_TABLE");
      result = 1;
      break;
    case 0x12u:
      PStringBase<char>::set(o_sType, "OBJECT_HIERARCHY");
      result = 1;
      break;
    case 0x13u:
      PStringBase<char>::set(o_sType, "BADDATA");
      result = 1;
      break;
    case 0x14u:
      PStringBase<char>::set(o_sType, "TABOO_TABLE");
      result = 1;
      break;
    case 0x15u:
      PStringBase<char>::set(o_sType, "FILE2ID_TABLE");
      result = 1;
      break;
    case 0x16u:
      PStringBase<char>::set(o_sType, "NAME_FILTER_TABLE");
      result = 1;
      break;
    case 0x17u:
      PStringBase<char>::set(o_sType, "MONITOREDPROPERTIES");
      result = 1;
      break;
    case 0x18u:
      PStringBase<char>::set(o_sType, "PAL_SET");
      result = 1;
      break;
    case 0x19u:
      PStringBase<char>::set(o_sType, "CLOTHING");
      result = 1;
      break;
    case 0x1Au:
      PStringBase<char>::set(o_sType, "DEGRADEINFO");
      result = 1;
      break;
    case 0x1Bu:
      PStringBase<char>::set(o_sType, "SCENE");
      result = 1;
      break;
    case 0x1Cu:
      PStringBase<char>::set(o_sType, "REGION");
      result = 1;
      break;
    case 0x1Du:
      PStringBase<char>::set(o_sType, "KEYMAP");
      result = 1;
      break;
    case 0x1Eu:
      PStringBase<char>::set(o_sType, "RENDERTEXTURE");
      result = 1;
      break;
    case 0x1Fu:
      PStringBase<char>::set(o_sType, "RENDERMATERIAL");
      result = 1;
      break;
    case 0x20u:
      PStringBase<char>::set(o_sType, "MATERIALMODIFIER");
      result = 1;
      break;
    case 0x21u:
      PStringBase<char>::set(o_sType, "MATERIALINSTANCE");
      result = 1;
      break;
    case 0x43u:
      PStringBase<char>::set(o_sType, "RENDER_MESH");
      result = 1;
      break;
    case 0x22u:
      PStringBase<char>::set(o_sType, "STABLE");
      result = 1;
      break;
    case 0x23u:
      PStringBase<char>::set(o_sType, "UI_LAYOUT");
      result = 1;
      break;
    case 0x24u:
      PStringBase<char>::set(o_sType, "ENUM_MAPPER");
      result = 1;
      break;
    case 0x25u:
      PStringBase<char>::set(o_sType, "STRING_TABLE");
      result = 1;
      break;
    case 0x26u:
      PStringBase<char>::set(o_sType, "DID_MAPPER");
      result = 1;
      break;
    case 0x27u:
      PStringBase<char>::set(o_sType, "ACTIONMAP");
      result = 1;
      break;
    case 0x28u:
      PStringBase<char>::set(o_sType, "DUAL_DID_MAPPER");
      result = 1;
      break;
    case 0x29u:
      PStringBase<char>::set(o_sType, "STRING");
      result = 1;
      break;
    case 0x2Au:
      PStringBase<char>::set(o_sType, "PARTICLE_EMITTER");
      result = 1;
      break;
    case 0x2Bu:
      PStringBase<char>::set(o_sType, "PHYSICS_SCRIPT");
      result = 1;
      break;
    case 0x2Cu:
      PStringBase<char>::set(o_sType, "PHYSICS_SCRIPT_TABLE");
      result = 1;
      break;
    case 0x2Du:
      PStringBase<char>::set(o_sType, "MASTER_PROPERTY");
      result = 1;
      break;
    case 0x2Eu:
      PStringBase<char>::set(o_sType, "FONT");
      result = 1;
      break;
    case 0x2Fu:
      PStringBase<char>::set(o_sType, "FONT_LOCAL");
      result = 1;
      break;
    case 0x30u:
      PStringBase<char>::set(o_sType, "STRING_STATE");
      result = 1;
      break;
    case 0x31u:
      PStringBase<char>::set(o_sType, "DBPROPERTIES");
      result = 1;
      break;
    default:
      return result;
  }
  return result;
}

//----- (0041F430) --------------------------------------------------------  // acclient.c:91900
void __thiscall DBTypeDef::DBTypeDef(DBTypeDef *this, DBTypeDef *__that)
{
  DBTypeDef *v2; // esi@1
  char *v3; // ecx@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ecx@1

  v2 = this;
  this->m_base_did.id = __that->m_base_did.id;
  this->m_top_did.id = __that->m_top_did.id;
  v3 = (char *)&this->m_extensions;
  *(_DWORD *)v3 = 0;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  SmartArray<PStringBase<char>,1>::operator=((SmartArray<PStringBase<char>,1> *)v3, (int)&__that->m_extensions);
  v2->m_packVersion = __that->m_packVersion;
  v2->m_updateType = __that->m_updateType;
  v2->m_bHasFile = __that->m_bHasFile;
  v2->m_bIsPortalType = __that->m_bIsPortalType;
  v2->m_bIsCellType = __that->m_bIsCellType;
  v2->m_bIsLocalType = __that->m_bIsLocalType;
  v4 = __that->m_strDataDir.m_charbuffer;
  v2->m_strDataDir.m_charbuffer = v4;
  InterlockedIncrement((volatile LONG *)&v4[-1]);
  v2->m_bIsClientType = __that->m_bIsClientType;
  v2->m_bIsServerType = __that->m_bIsServerType;
  v2->m_bIsEngineType = __that->m_bIsEngineType;
  v2->m_bIsDIDPackedToDats = __that->m_bIsDIDPackedToDats;
  v2->m_bIsWBEditable = __that->m_bIsWBEditable;
  v2->m_bIsCategorized = __that->m_bIsCategorized;
  v2->m_bForceExpire = __that->m_bForceExpire;
  v5 = (int)&v2->m_freelistDef.m_bRecycle;
  *(_DWORD *)v5 = *(_DWORD *)&__that->m_freelistDef.m_bRecycle;
  *(_DWORD *)(v5 + 4) = __that->m_freelistDef.m_nIdealSize;
  *(_DWORD *)(v5 + 8) = __that->m_freelistDef.m_nMaxSize;
}

//----- (0041F4E0) --------------------------------------------------------  // acclient.c:91938
char __thiscall HashTable<unsigned long,DBTypeDef,0>::add(HashTable<unsigned long,DBTypeDef,0> *this, const unsigned int *_key, DBTypeDef *_data)
{
  HashTable<unsigned long,DBTypeDef,0> *v3; // edi@1
  void *v4; // esi@1
  int v5; // edi@6
  PStringBase<char> *v6; // ecx@10
  char result; // al@13

  v3 = this;
  v4 = operator new(0x40u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    DBTypeDef::DBTypeDef((DBTypeDef *)((char *)v4 + 8), _data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      v5 = *((_DWORD *)v4 + 10) - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      if ( (*((_DWORD *)v4 + 5) & 0x80000000) == 0x80000000 )
      {
        v6 = (PStringBase<char> *)*((_DWORD *)v4 + 4);
        if ( v6 )
          PStringBase<unsigned short>::vector_deleting_destructor(v6, 3u);
      }
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (0041F580) --------------------------------------------------------  // acclient.c:91985
char MasterDBMap::InitDBTypeDef_Internal()
{
  char *v1; // ebp@1
  char *v2; // ebp@4
  char *v3; // ebp@7
  char *v4; // ebp@10
  char *v5; // ebp@13
  char *v6; // ebp@16
  char *v7; // ebp@19
  char *v8; // ebp@22
  char *v9; // ebp@25
  char *v10; // ebp@28
  char *v11; // ebp@31
  char *v12; // ebp@34
  char *v13; // ebp@37
  char *v14; // ebp@40
  char *v15; // ebp@43
  char *v16; // ebp@46
  char *v17; // ebp@49
  char *v18; // ebp@52
  char *v19; // ebp@55
  char *v20; // ebp@58
  char *v21; // ebp@61
  char *v22; // ebp@64
  char *v23; // ebp@67
  char *v24; // ebp@70
  char *v25; // ebp@73
  char *v26; // ebp@76
  char *v27; // ebp@79
  char *v28; // ebp@82
  char *v29; // ebp@85
  char *v30; // ebp@88
  char *v31; // ebp@91
  char *v32; // ebp@94
  char *v33; // ebp@97
  char *v34; // ebp@100
  char *v35; // ebp@103
  char *v36; // ebp@106
  char *v37; // ebp@109
  char *v38; // ebp@112
  char *v39; // ebp@115
  char *v40; // ebp@118
  char *v41; // ebp@121
  char *v42; // ebp@124
  char *v43; // ebp@127
  char *v44; // ebp@130
  char *v45; // ebp@133
  char *v46; // ebp@136
  char *v47; // ebp@139
  char *v48; // ebp@142
  char *v49; // ebp@145
  char *v50; // ebp@148
  char *v51; // ebp@151
  char *v52; // ebp@154
  char *v53; // ebp@157
  char *v54; // ebp@160
  char *v55; // ebp@163
  char *v56; // ebp@166
  char *v57; // ebp@169
  PStringBase<char> i_rData; // [sp+DCh] [bp-3Ch]@1
  DBTypeDef def; // [sp+E0h] [bp-38h]@1

  DBTypeDef::DBTypeDef(&def);
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  def.m_packVersion = 1;
  def.m_updateType = 2;
  def.m_bHasFile = 0;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 1;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, &name);
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 21;
  def.m_freelistDef.m_nMaxSize = 144;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_LAND_BLOCK, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  PStringBase<char>::PStringBase<char>(&i_rData, ".lbi");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v1 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  def.m_packVersion = 1;
  def.m_updateType = 2;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 1;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "lbi");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 21;
  def.m_freelistDef.m_nMaxSize = 144;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_LBI, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  def.m_packVersion = 1;
  def.m_updateType = 2;
  def.m_bHasFile = 0;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 1;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, &name);
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 20;
  def.m_freelistDef.m_nMaxSize = 144;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_CELL, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  PStringBase<char>::PStringBase<char>(&i_rData, ".lbo");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v2 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  def.m_packVersion = 1;
  def.m_updateType = 2;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "lbo");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_LBO, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  PStringBase<char>::PStringBase<char>(&i_rData, ".ins");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v3 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  def.m_packVersion = 1;
  def.m_updateType = 2;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "ins");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_INSTANTIATION, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x1000000;
  def.m_top_did.id = 16842751;
  PStringBase<char>::PStringBase<char>(&i_rData, ".obj");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v4 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "gfxobj");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 100;
  def.m_freelistDef.m_nMaxSize = 200;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_GFXOBJ, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x2000000;
  def.m_top_did.id = 33619967;
  PStringBase<char>::PStringBase<char>(&i_rData, ".set");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v5 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "setup");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 25;
  def.m_freelistDef.m_nMaxSize = 100;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SETUP, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 50331648;
  def.m_top_did.id = 50397183;
  PStringBase<char>::PStringBase<char>(&i_rData, ".anm");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v6 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "anim");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 20;
  def.m_freelistDef.m_nMaxSize = 80;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ANIM, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0;
  def.m_top_did.id = 0;
  PStringBase<char>::PStringBase<char>(&i_rData, ".ahk");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v7 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "hk");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ANIMATION_HOOK, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x4000000;
  def.m_top_did.id = 67174399;
  PStringBase<char>::PStringBase<char>(&i_rData, ".pal");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v8 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "palette");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 60;
  def.m_freelistDef.m_nMaxSize = 100;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_PALETTE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 83886080;
  def.m_top_did.id = 100663295;
  PStringBase<char>::PStringBase<char>(&i_rData, ".texture");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v9 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "textures");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 1;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 100;
  def.m_freelistDef.m_nMaxSize = 400;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SURFACETEXTURE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 100663296;
  def.m_top_did.id = 0x7FFFFFF;
  PStringBase<char>::PStringBase<char>(&i_rData, ".jpg");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v10 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".dds");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v11 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".tga");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v12 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".iff");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v13 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".256");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v14 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".csi");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v15 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".alp");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v16 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "surfaces");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 1;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 100;
  def.m_freelistDef.m_nMaxSize = 400;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_RENDERSURFACE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x8000000;
  def.m_top_did.id = 134283263;
  PStringBase<char>::PStringBase<char>(&i_rData, ".surface");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v17 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "materials");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 50;
  def.m_freelistDef.m_nMaxSize = 200;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SURFACE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 150994944;
  def.m_top_did.id = 151060479;
  PStringBase<char>::PStringBase<char>(&i_rData, ".dsc");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v18 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "dsc");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MTABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 167772160;
  def.m_top_did.id = 167837695;
  PStringBase<char>::PStringBase<char>(&i_rData, ".wav");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v19 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "sound");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_WAVE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 218103808;
  def.m_top_did.id = 218169343;
  PStringBase<char>::PStringBase<char>(&i_rData, ".env");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v20 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "env");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ENVIRONMENT, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881031;
  def.m_top_did.id = 234881031;
  PStringBase<char>::PStringBase<char>(&i_rData, ".cps");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v21 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "ui");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 0;
  def.m_freelistDef.m_nIdealSize = 1;
  def.m_freelistDef.m_nMaxSize = 1;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_CHAT_POSE_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881037;
  def.m_top_did.id = 234881037;
  PStringBase<char>::PStringBase<char>(&i_rData, ".hrc");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v22 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "DungeonCfgs");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_OBJECT_HIERARCHY, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881050;
  def.m_top_did.id = 234881050;
  PStringBase<char>::PStringBase<char>(&i_rData, ".bad");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v23 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 0;
  def.m_freelistDef.m_nIdealSize = 1;
  def.m_freelistDef.m_nMaxSize = 1;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_BADDATA, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881054;
  def.m_top_did.id = 234881054;
  PStringBase<char>::PStringBase<char>(&i_rData, ".taboo");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v24 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "weenie");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_TABOO_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881055;
  def.m_top_did.id = 234881055;
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 0;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, &name);
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_FILE2ID_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 234881056;
  def.m_top_did.id = 234881056;
  PStringBase<char>::PStringBase<char>(&i_rData, ".nft");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v25 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v25 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "namefilter");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_NAME_FILTER_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 235012096;
  def.m_top_did.id = 235077631;
  PStringBase<char>::PStringBase<char>(&i_rData, ".monprop");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v26 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v26 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "properties");
  def.m_bIsClientType = 0;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MONITOREDPROPERTIES, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 251658240;
  def.m_top_did.id = 251723775;
  PStringBase<char>::PStringBase<char>(&i_rData, ".pst");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v27 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v27 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "palset");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 10;
  def.m_freelistDef.m_nMaxSize = 40;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_PAL_SET, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x10000000;
  def.m_top_did.id = 268500991;
  PStringBase<char>::PStringBase<char>(&i_rData, ".clo");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v28 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v28 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "clothing");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 20;
  def.m_freelistDef.m_nMaxSize = 40;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_CLOTHING, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 285212672;
  def.m_top_did.id = 285278207;
  PStringBase<char>::PStringBase<char>(&i_rData, ".deg");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v29 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v29 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "deg");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 80;
  def.m_freelistDef.m_nMaxSize = 200;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_DEGRADEINFO, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 301989888;
  def.m_top_did.id = 302055423;
  PStringBase<char>::PStringBase<char>(&i_rData, ".scn");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v30 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v30 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "scn");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 25;
  def.m_freelistDef.m_nMaxSize = 100;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_SCENE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 318767104;
  def.m_top_did.id = 318832639;
  PStringBase<char>::PStringBase<char>(&i_rData, ".rgn");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v31 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v31 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "landscape");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_REGION, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 335544320;
  def.m_top_did.id = 335609855;
  PStringBase<char>::PStringBase<char>(&i_rData, ".keymap");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v32 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v32 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "keymap");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_KEYMAP, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 352321536;
  def.m_top_did.id = 369098751;
  PStringBase<char>::PStringBase<char>(&i_rData, ".rtexture");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v33 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v33 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "textures");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 1;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 128;
  def.m_freelistDef.m_nMaxSize = 256;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_RENDERTEXTURE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 369098752;
  def.m_top_did.id = 385875967;
  PStringBase<char>::PStringBase<char>(&i_rData, ".mat");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v34 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v34 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "materials");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_RENDERMATERIAL, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 385875968;
  def.m_top_did.id = 402653183;
  PStringBase<char>::PStringBase<char>(&i_rData, ".mm");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v35 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v35 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v35)(v35, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "materials");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MATERIALMODIFIER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 402653184;
  def.m_top_did.id = 419430399;
  PStringBase<char>::PStringBase<char>(&i_rData, ".mi");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v36 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v36 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "materials");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MATERIALINSTANCE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 419430400;
  def.m_top_did.id = 436207615;
  PStringBase<char>::PStringBase<char>(&i_rData, ".rendermesh");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v37 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v37 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v37)(v37, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "mesh");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 16;
  def.m_freelistDef.m_nMaxSize = 32;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_RENDER_MESH, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x20000000;
  def.m_top_did.id = 536936447;
  PStringBase<char>::PStringBase<char>(&i_rData, ".stb");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v38 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v38 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v38)(v38, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "stb");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 2;
  def.m_freelistDef.m_nMaxSize = 6;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_STABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 553648128;
  def.m_top_did.id = 570425343;
  PStringBase<char>::PStringBase<char>(&i_rData, ".uil");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v39 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v39 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v39)(v39, 1);
  def.m_packVersion = 3;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 1;
  PStringBase<char>::set(&def.m_strDataDir, "ui/layout");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_UI_LAYOUT, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 570425344;
  def.m_top_did.id = 587202559;
  PStringBase<char>::PStringBase<char>(&i_rData, ".emp");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v40 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v40 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v40)(v40, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "emp");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ENUM_MAPPER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 587202560;
  def.m_top_did.id = 620756991;
  PStringBase<char>::PStringBase<char>(&i_rData, ".stt");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v41 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v41 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v41)(v41, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".stt_ansi");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v42 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v42 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v42)(v42, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".stt_bin");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v43 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v43 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v43)(v43, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 1;
  PStringBase<char>::set(&def.m_strDataDir, "stringtable");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_STRING_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 620756992;
  def.m_top_did.id = 637534207;
  PStringBase<char>::PStringBase<char>(&i_rData, ".imp");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v44 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v44 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v44)(v44, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "emp/idmap");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_DID_MAPPER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 637534208;
  def.m_top_did.id = 637599743;
  PStringBase<char>::PStringBase<char>(&i_rData, ".actionmap");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v45 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v45 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v45)(v45, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "actionmap");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_ACTIONMAP, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 654311424;
  def.m_top_did.id = 671088639;
  PStringBase<char>::PStringBase<char>(&i_rData, ".dimp");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v46 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v46 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v46)(v46, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "emp/idmap");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 64;
  def.m_freelistDef.m_nMaxSize = 128;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_DUAL_DID_MAPPER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 822083584;
  def.m_top_did.id = 822149119;
  PStringBase<char>::PStringBase<char>(&i_rData, ".str");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v47 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v47 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v47)(v47, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "string");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_STRING, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 838860800;
  def.m_top_did.id = 838926335;
  PStringBase<char>::PStringBase<char>(&i_rData, ".emt");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v48 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v48 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v48)(v48, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "emt");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_PARTICLE_EMITTER, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 855638016;
  def.m_top_did.id = 855703551;
  PStringBase<char>::PStringBase<char>(&i_rData, ".pes");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v49 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v49 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v49)(v49, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "pes");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_PHYSICS_SCRIPT, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 872415232;
  def.m_top_did.id = 872480767;
  PStringBase<char>::PStringBase<char>(&i_rData, ".pet");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v50 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v50 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v50)(v50, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "pet");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_PHYSICS_SCRIPT_TABLE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 956301312;
  def.m_top_did.id = 973078527;
  PStringBase<char>::PStringBase<char>(&i_rData, ".mpr");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v51 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v51 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v51)(v51, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "emp/property");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_MASTER_PROPERTY, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 0x40000000;
  def.m_top_did.id = 1073745919;
  PStringBase<char>::PStringBase<char>(&i_rData, ".font");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v52 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v52 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v52)(v52, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "fonts");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_FONT, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 1073745920;
  def.m_top_did.id = 1090519039;
  PStringBase<char>::PStringBase<char>(&i_rData, ".font_local");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v53 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v53 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v53)(v53, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 1;
  PStringBase<char>::set(&def.m_strDataDir, "fonts");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_FONT_LOCAL, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 1090519040;
  def.m_top_did.id = 1107296255;
  PStringBase<char>::PStringBase<char>(&i_rData, ".sti");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v54 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v54 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v54)(v54, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 0;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 1;
  PStringBase<char>::set(&def.m_strDataDir, "stringtable");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 0;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 1;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_STRING_STATE, &def);
  def.m_extensions.m_num = 0;
  def.m_base_did.id = 2013265920;
  def.m_top_did.id = 0x7FFFFFFF;
  PStringBase<char>::PStringBase<char>(&i_rData, ".dbpc");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v55 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v55 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v55)(v55, 1);
  PStringBase<char>::PStringBase<char>(&i_rData, ".pmat");
  SmartArray<PStringBase<char>,1>::AddToEnd(&def.m_extensions, &i_rData);
  v56 = &i_rData.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_rData.m_charbuffer[-1]) && v56 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v56)(v56, 1);
  def.m_packVersion = 1;
  def.m_updateType = 1;
  def.m_bHasFile = 1;
  def.m_bIsPortalType = 1;
  def.m_bIsCellType = 0;
  def.m_bIsLocalType = 0;
  PStringBase<char>::set(&def.m_strDataDir, "properties");
  def.m_bIsClientType = 1;
  def.m_bIsServerType = 1;
  def.m_bIsEngineType = 1;
  def.m_bIsDIDPackedToDats = 0;
  def.m_bIsWBEditable = 0;
  def.m_bIsCategorized = 0;
  def.m_freelistDef.m_bRecycle = 0;
  def.m_freelistDef.m_bShrink = 1;
  def.m_freelistDef.m_nIdealSize = 3;
  def.m_freelistDef.m_nMaxSize = 15;
  def.m_bForceExpire = 0;
  HashTable<unsigned long,DBTypeDef,0>::add(&MasterDBMap::sm_DBTypeDefHash, &DB_TYPE_DBPROPERTIES, &def);
  v57 = &def.m_strDataDir.m_charbuffer[-2].m_data[12];
  def.m_extensions.m_num = 0;
  if ( !InterlockedDecrement((volatile LONG *)&def.m_strDataDir.m_charbuffer[-1]) && v57 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v57)(v57, 1);
  if ( (def.m_extensions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && def.m_extensions.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor(def.m_extensions.m_data, 3u);
  return 1;
}

//----- (006C4AC0) --------------------------------------------------------  // acclient.c:733025
int _E1_13()
{
  return atexit(_E2_13);
}

