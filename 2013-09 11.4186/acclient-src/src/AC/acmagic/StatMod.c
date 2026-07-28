/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StatMod
   Object     : AC\acmagic\StatMod.obj
   Functions  : 10
   Addresses  : 005BD090 - 0070ECE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BD090) --------------------------------------------------------  // acclient.c:488292
signed int __thiscall StatMod::Pack(StatMod *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2

  if ( size >= 0xC )
  {
    *(_DWORD *)*addr = this->type;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->key;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(float *)v4 = this->val;
    *addr = (char *)*addr + 4;
  }
  return 12;
}

//----- (0070EC20) --------------------------------------------------------  // acclient.c:801771
int sub_70EC20()
{
  return atexit(nullsub_1617);
}

//----- (0070EC30) --------------------------------------------------------  // acclient.c:801777
int _E4_9()
{
  return atexit(_E5_9);
}

//----- (0070EC40) --------------------------------------------------------  // acclient.c:801783
int _E7_9()
{
  Outside_CellID_9.id = Invalid_CellID_9.id + 1;
  return atexit(_E8_9);
}

//----- (0070EC60) --------------------------------------------------------  // acclient.c:801790
int _E10_8()
{
  In_Limbo_CellID_8.id = Outside_CellID_9.id + 1;
  return atexit(_E11_8);
}

//----- (0070EC80) --------------------------------------------------------  // acclient.c:801797
int _E13_8()
{
  First_Interior_CellID_8.id = In_Limbo_CellID_8.id + 1;
  return atexit(_E14_8);
}

//----- (0070ECA0) --------------------------------------------------------  // acclient.c:801804
int _E16_8()
{
  Last_Interior_CellID_8.id = Invalid_CellID_9.id - 1;
  return atexit(_E17_8);
}

//----- (0070ECC0) --------------------------------------------------------  // acclient.c:801811
int _E21_10()
{
  return atexit(_E22_10);
}

//----- (0070ECD0) --------------------------------------------------------  // acclient.c:801817
int _E40_10()
{
  return atexit(_E41_10);
}

//----- (0070ECE0) --------------------------------------------------------  // acclient.c:801823
int _E43_13()
{
  return atexit(_E44_13);
}

