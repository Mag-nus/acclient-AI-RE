/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EnginePackBehaviors
   Object     : ENGINE\engine_utils\EnginePackBehaviors.obj
   Functions  : 5
   Addresses  : 00684480 - 00715800 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00684480) --------------------------------------------------------  // acclient.c:667688
signed int __cdecl Pack_AsDataIDOfKnownType(unsigned int i_FirstID, IDClass<_tagDataID,32,0> i_toPack, void **io_pBuff, unsigned int i_size)
{
  unsigned int v4; // ecx@1
  unsigned int v5; // ecx@3
  signed int result; // eax@6
  char *v7; // edx@9

  v4 = i_toPack.id;
  if ( !i_toPack.id )
    v4 = i_FirstID;
  v5 = v4 - i_FirstID;
  if ( v5 > 0x3FFF )
  {
    if ( v5 > 0x3FFFFFFF )
    {
      result = 0;
    }
    else
    {
      if ( i_size >= 4 )
      {
        *(_WORD *)*io_pBuff = HIWORD(v5) | 0x8000;
        v7 = (char *)*io_pBuff + 2;
        *io_pBuff = v7;
        *(_WORD *)v7 = v5;
        *io_pBuff = (char *)*io_pBuff + 2;
      }
      result = 4;
    }
  }
  else
  {
    if ( i_size >= 2 )
    {
      *(_WORD *)*io_pBuff = v5;
      *io_pBuff = (char *)*io_pBuff + 2;
    }
    result = 2;
  }
  return result;
}

//----- (006844F0) --------------------------------------------------------  // acclient.c:667731
char __cdecl Unpack_AsDataIDOfKnownType(unsigned int i_didFirstID, IDClass<_tagDataID,32,0> *o_toPack, void **io_pBuff)
{
  unsigned __int16 v3; // ax@1
  char *v4; // ecx@1
  unsigned __int16 v5; // si@2
  char result; // al@2

  v3 = *(_WORD *)*io_pBuff;
  v4 = (char *)*io_pBuff + 2;
  *io_pBuff = v4;
  if ( SHIBYTE(v3) >= 0 )
  {
    o_toPack->id = i_didFirstID + v3;
    result = 1;
  }
  else
  {
    v5 = *(_WORD *)v4;
    *io_pBuff = v4 + 2;
    o_toPack->id = i_didFirstID + (v5 | ((v3 & 0x3FFF) << 16));
    result = 1;
  }
  return result;
}

//----- (00684540) --------------------------------------------------------  // acclient.c:667757
signed int __cdecl Pack_AsWClassIDCompressed(IDClass<_tagDataID,32,0> i_toPack, void **io_pBuff, unsigned int i_size)
{
  signed int result; // eax@4
  char *v4; // edx@6

  if ( i_toPack.id > 0x7FFF )
  {
    if ( i_size >= 4 )
    {
      *(_WORD *)*io_pBuff = HIWORD(i_toPack.id) | 0x8000;
      v4 = (char *)*io_pBuff + 2;
      *io_pBuff = v4;
      *(_WORD *)v4 = i_toPack.id;
      *io_pBuff = (char *)*io_pBuff + 2;
    }
    result = 4;
  }
  else
  {
    if ( i_size >= 2 )
    {
      *(_WORD *)*io_pBuff = i_toPack.id;
      *io_pBuff = (char *)*io_pBuff + 2;
    }
    result = 2;
  }
  return result;
}

//----- (006845A0) --------------------------------------------------------  // acclient.c:667787
char __cdecl Unpack_AsWClassIDCompressed(IDClass<_tagDataID,32,0> *o_toPack, void **io_pBuff)
{
  unsigned __int16 v2; // ax@1
  char *v3; // ecx@1
  unsigned __int16 v4; // si@2
  char result; // al@2

  v2 = *(_WORD *)*io_pBuff;
  v3 = (char *)*io_pBuff + 2;
  *io_pBuff = v3;
  if ( SHIBYTE(v2) >= 0 )
  {
    o_toPack->id = v2;
    result = 1;
  }
  else
  {
    v4 = *(_WORD *)v3;
    *io_pBuff = v3 + 2;
    o_toPack->id = v4 | ((v2 & 0x7FFF) << 16);
    result = 1;
  }
  return result;
}

//----- (00715800) --------------------------------------------------------  // acclient.c:808502
int sub_715800()
{
  return atexit(nullsub_230);
}

