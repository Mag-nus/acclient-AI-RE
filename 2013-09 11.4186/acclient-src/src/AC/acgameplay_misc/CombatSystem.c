/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CombatSystem
   Object     : AC\acgameplay_misc\CombatSystem.obj
   Functions  : 11
   Addresses  : 005C9020 - 0070FA40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C9020) --------------------------------------------------------  // acclient.c:500131
long double __cdecl CombatSystem::GetElementalModPKModifier(const long double elementalModifier)
{
  return (elementalModifier - 1.0) * CombatSystem::ElementalModPKModifier + 1.0;
}
// 822C50: using guessed type double CombatSystem::ElementalModPKModifier;

//----- (005C9040) --------------------------------------------------------  // acclient.c:500138
int __cdecl CombatSystem::InqCombatHitAdjectives(DAMAGE_TYPE damage_type, const long double php, AC1Legacy::PStringBase<char> *single_adj, AC1Legacy::PStringBase<char> *plural_adj)
{
  int v4; // eax@2
  AC1Legacy::PStringBase<char> *v5; // esi@13
  AC1Legacy::PStringBase<unsigned short> *v6; // eax@13
  AC1Legacy::PStringBase<char> *v7; // ecx@13
  AC1Legacy::PStringBase<char> *v8; // esi@35
  AC1Legacy::PStringBase<unsigned short> *v9; // eax@35
  AC1Legacy::PStringBase<char> *v10; // esi@61
  AC1Legacy::PStringBase<unsigned short> *v11; // eax@61
  AC1Legacy::PStringBase<char> *v12; // esi@69
  AC1Legacy::PStringBase<unsigned short> *v13; // eax@69
  AC1Legacy::PStringBase<char> *v14; // esi@79
  AC1Legacy::PStringBase<unsigned short> *v15; // eax@79
  const char *v16; // [sp-8h] [bp-1Ch]@7
  const char *v17; // [sp-8h] [bp-1Ch]@29
  const char *v18; // [sp-8h] [bp-1Ch]@55
  const char *v19; // [sp-8h] [bp-1Ch]@63
  const char *v20; // [sp-8h] [bp-1Ch]@73
  AC1Legacy::PStringBase<char> result; // [sp+0h] [bp-14h]@13
  AC1Legacy::PStringBase<char> v22; // [sp+4h] [bp-10h]@35
  AC1Legacy::PStringBase<char> v23; // [sp+8h] [bp-Ch]@61
  AC1Legacy::PStringBase<char> v24; // [sp+Ch] [bp-8h]@69
  AC1Legacy::PStringBase<char> v25; // [sp+10h] [bp-4h]@79

  if ( php < 0.0 )
    return 0;
  if ( (signed int)damage_type > 16 )
  {
    if ( (signed int)damage_type > 128 )
    {
      if ( damage_type != 1024 )
        goto LABEL_71;
      if ( php > 0.1 )
      {
        if ( php > 0.25 )
        {
          if ( php > 0.5 )
            v20 = "eradicate";
          else
            v20 = "wither";
        }
        else
        {
          v20 = "twist";
        }
      }
      else
      {
        v20 = "scar";
      }
      v14 = single_adj;
      AC1Legacy::PStringBase<char>::set(single_adj, v20);
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&php, "s");
      v15 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(
                                                        v14,
                                                        &v25,
                                                        (AC1Legacy::PStringBase<char> *)&php);
      AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)plural_adj, v15);
      v7 = &v25;
    }
    else if ( damage_type == 128 )
    {
      if ( php > 0.1 )
      {
        if ( php > 0.25 )
        {
          if ( php > 0.5 )
            v19 = "deplete";
          else
            v19 = "siphon";
        }
        else
        {
          v19 = "exhaust";
        }
      }
      else
      {
        v19 = "drain";
      }
      v12 = single_adj;
      AC1Legacy::PStringBase<char>::set(single_adj, v19);
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&php, "s");
      v13 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(
                                                        v12,
                                                        &v24,
                                                        (AC1Legacy::PStringBase<char> *)&php);
      AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)plural_adj, v13);
      v7 = &v24;
    }
    else
    {
      if ( damage_type != 32 )
      {
        if ( damage_type == 64 )
        {
          if ( php > 0.1 )
          {
            if ( php > 0.25 )
            {
              if ( php > 0.5 )
              {
                AC1Legacy::PStringBase<char>::set(single_adj, "blast");
                AC1Legacy::PStringBase<char>::set(plural_adj, "blasts");
                v4 = 1;
              }
              else
              {
                AC1Legacy::PStringBase<char>::set(single_adj, "jolt");
                AC1Legacy::PStringBase<char>::set(plural_adj, "jolts");
                v4 = 1;
              }
            }
            else
            {
              AC1Legacy::PStringBase<char>::set(single_adj, "shock");
              AC1Legacy::PStringBase<char>::set(plural_adj, "shocks");
              v4 = 1;
            }
          }
          else
          {
            AC1Legacy::PStringBase<char>::set(single_adj, "spark");
            AC1Legacy::PStringBase<char>::set(plural_adj, "sparks");
            v4 = 1;
          }
          return v4;
        }
LABEL_71:
        AC1Legacy::PStringBase<char>::set(single_adj, "hit");
        AC1Legacy::PStringBase<char>::set(plural_adj, "hits");
        return 0;
      }
      if ( php > 0.1 )
      {
        if ( php > 0.25 )
        {
          if ( php > 0.5 )
            v18 = "dissolve";
          else
            v18 = "corrode";
        }
        else
        {
          v18 = "sear";
        }
      }
      else
      {
        v18 = "blister";
      }
      v10 = single_adj;
      AC1Legacy::PStringBase<char>::set(single_adj, v18);
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&php, "s");
      v11 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(
                                                        v10,
                                                        &v23,
                                                        (AC1Legacy::PStringBase<char> *)&php);
      AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)plural_adj, v11);
      v7 = &v23;
    }
LABEL_80:
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)v7);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&php);
    return 1;
  }
  if ( damage_type != 16 )
  {
    switch ( damage_type )
    {
      case 8:
        if ( php > 0.1 )
        {
          if ( php > 0.25 )
          {
            if ( php > 0.5 )
              v16 = "freeze";
            else
              v16 = "frost";
          }
          else
          {
            v16 = "chill";
          }
        }
        else
        {
          v16 = "numb";
        }
        v5 = single_adj;
        AC1Legacy::PStringBase<char>::set(single_adj, v16);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&php, "s");
        v6 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(
                                                         v5,
                                                         &result,
                                                         (AC1Legacy::PStringBase<char> *)&php);
        AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)plural_adj, v6);
        v7 = &result;
        goto LABEL_80;
      case 4:
        if ( php > 0.1 )
        {
          if ( php > 0.25 )
          {
            if ( php > 0.5 )
            {
              AC1Legacy::PStringBase<char>::set(single_adj, "crush");
              AC1Legacy::PStringBase<char>::set(plural_adj, "crushes");
              v4 = 1;
            }
            else
            {
              AC1Legacy::PStringBase<char>::set(single_adj, "smash");
              AC1Legacy::PStringBase<char>::set(plural_adj, "smashes");
              v4 = 1;
            }
          }
          else
          {
            AC1Legacy::PStringBase<char>::set(single_adj, "bash");
            AC1Legacy::PStringBase<char>::set(plural_adj, "bashes");
            v4 = 1;
          }
        }
        else
        {
          AC1Legacy::PStringBase<char>::set(single_adj, "graze");
          AC1Legacy::PStringBase<char>::set(plural_adj, "grazes");
          v4 = 1;
        }
        return v4;
      case 1:
        if ( php > 0.1 )
        {
          if ( php > 0.25 )
          {
            if ( php > 0.5 )
            {
              AC1Legacy::PStringBase<char>::set(single_adj, "mangle");
              AC1Legacy::PStringBase<char>::set(plural_adj, "mangles");
              v4 = 1;
            }
            else
            {
              AC1Legacy::PStringBase<char>::set(single_adj, "slash");
              AC1Legacy::PStringBase<char>::set(plural_adj, "slashes");
              v4 = 1;
            }
          }
          else
          {
            AC1Legacy::PStringBase<char>::set(single_adj, "cut");
            AC1Legacy::PStringBase<char>::set(plural_adj, "cuts");
            v4 = 1;
          }
        }
        else
        {
          AC1Legacy::PStringBase<char>::set(single_adj, "scratch");
          AC1Legacy::PStringBase<char>::set(plural_adj, "scratches");
          v4 = 1;
        }
        return v4;
      case 2:
        if ( php > 0.1 )
        {
          if ( php > 0.25 )
          {
            if ( php > 0.5 )
              v17 = "gore";
            else
              v17 = "impale";
          }
          else
          {
            v17 = "stab";
          }
        }
        else
        {
          v17 = "nick";
        }
        v8 = single_adj;
        AC1Legacy::PStringBase<char>::set(single_adj, v17);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&php, "s");
        v9 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(
                                                         v8,
                                                         &v22,
                                                         (AC1Legacy::PStringBase<char> *)&php);
        AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)plural_adj, v9);
        v7 = &v22;
        goto LABEL_80;
      default:
        goto LABEL_71;
    }
    goto LABEL_71;
  }
  if ( php > 0.1 )
  {
    if ( php > 0.25 )
    {
      if ( php > 0.5 )
      {
        AC1Legacy::PStringBase<char>::set(single_adj, "incinerate");
        AC1Legacy::PStringBase<char>::set(plural_adj, "incinerates");
        v4 = 1;
      }
      else
      {
        AC1Legacy::PStringBase<char>::set(single_adj, "burn");
        AC1Legacy::PStringBase<char>::set(plural_adj, "burns");
        v4 = 1;
      }
    }
    else
    {
      AC1Legacy::PStringBase<char>::set(single_adj, "scorch");
      AC1Legacy::PStringBase<char>::set(plural_adj, "scorches");
      v4 = 1;
    }
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(single_adj, "singe");
    AC1Legacy::PStringBase<char>::set(plural_adj, "singes");
    v4 = 1;
  }
  return v4;
}

//----- (0070F980) --------------------------------------------------------  // acclient.c:802811
int sub_70F980()
{
  return atexit(nullsub_1712);
}

//----- (0070F990) --------------------------------------------------------  // acclient.c:802817
int _E4_17()
{
  return atexit(_E5_17);
}

//----- (0070F9A0) --------------------------------------------------------  // acclient.c:802823
int _E7_17()
{
  Outside_CellID_17.id = Invalid_CellID_17.id + 1;
  return atexit(_E8_17);
}

//----- (0070F9C0) --------------------------------------------------------  // acclient.c:802830
int _E10_16()
{
  In_Limbo_CellID_16.id = Outside_CellID_17.id + 1;
  return atexit(_E11_16);
}

//----- (0070F9E0) --------------------------------------------------------  // acclient.c:802837
int _E13_16()
{
  First_Interior_CellID_16.id = In_Limbo_CellID_16.id + 1;
  return atexit(_E14_16);
}

//----- (0070FA00) --------------------------------------------------------  // acclient.c:802844
int _E16_16()
{
  Last_Interior_CellID_16.id = Invalid_CellID_17.id - 1;
  return atexit(_E17_16);
}

//----- (0070FA20) --------------------------------------------------------  // acclient.c:802851
int _E21_18()
{
  return atexit(_E22_18);
}

//----- (0070FA30) --------------------------------------------------------  // acclient.c:802857
int _E40_18()
{
  return atexit(_E41_18);
}

//----- (0070FA40) --------------------------------------------------------  // acclient.c:802863
int _E43_21()
{
  return atexit(_E44_21);
}

