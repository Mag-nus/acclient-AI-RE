/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CombatManeuver
   Object     : AC\acgameplay_misc\CombatManeuver.obj
   Functions  : 11
   Addresses  : 005CA7B0 - 0070FF20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CA7B0) --------------------------------------------------------  // acclient.c:501959
signed int __thiscall CombatManeuver::Pack(CombatManeuver *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2
  char *v5; // esi@2
  char *v6; // edx@2

  if ( size >= 0x14 )
  {
    *(_DWORD *)*addr = this->style;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->attack_height;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->attack_type;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->min_skill_level;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->motion;
    *addr = (char *)*addr + 4;
  }
  return 20;
}

//----- (005CA810) --------------------------------------------------------  // acclient.c:501987
int __thiscall CombatManeuver::UnPack(CombatManeuver *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // edx@3
  char *v6; // edx@3
  char *v7; // edx@3

  if ( size >= 0x14 )
  {
    this->style = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    this->attack_height = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->attack_type = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->min_skill_level = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->motion = *(_DWORD *)v7;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070FE60) --------------------------------------------------------  // acclient.c:803159
int sub_70FE60()
{
  return atexit(nullsub_1739);
}

//----- (0070FE70) --------------------------------------------------------  // acclient.c:803165
int _E4_23()
{
  return atexit(_E5_23);
}

//----- (0070FE80) --------------------------------------------------------  // acclient.c:803171
int _E7_23()
{
  Outside_CellID_23.id = Invalid_CellID_23.id + 1;
  return atexit(_E8_23);
}

//----- (0070FEA0) --------------------------------------------------------  // acclient.c:803178
int _E10_22()
{
  In_Limbo_CellID_22.id = Outside_CellID_23.id + 1;
  return atexit(_E11_22);
}

//----- (0070FEC0) --------------------------------------------------------  // acclient.c:803185
int _E13_22()
{
  First_Interior_CellID_22.id = In_Limbo_CellID_22.id + 1;
  return atexit(_E14_22);
}

//----- (0070FEE0) --------------------------------------------------------  // acclient.c:803192
int _E16_22()
{
  Last_Interior_CellID_22.id = Invalid_CellID_23.id - 1;
  return atexit(_E17_22);
}

//----- (0070FF00) --------------------------------------------------------  // acclient.c:803199
int _E21_24()
{
  return atexit(_E22_24);
}

//----- (0070FF10) --------------------------------------------------------  // acclient.c:803205
int _E40_24()
{
  return atexit(_E41_24);
}

//----- (0070FF20) --------------------------------------------------------  // acclient.c:803211
int _E43_27()
{
  return atexit(_E44_27);
}

