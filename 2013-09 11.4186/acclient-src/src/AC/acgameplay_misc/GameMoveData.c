/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GameMoveData
   Object     : AC\acgameplay_misc\GameMoveData.obj
   Functions  : 12
   Addresses  : 006B7660 - 00724A00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7660) --------------------------------------------------------  // acclient.c:721052
signed int __thiscall GameMoveData::GetPackSize(GameMoveData *this)
{
  __int32 v1; // ecx@1
  signed int result; // eax@1
  int v3; // ecx@2

  v1 = this->m_type - 4;
  result = 8;
  if ( v1 )
  {
    v3 = v1 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        result = 12;
    }
    else
    {
      result = 24;
    }
  }
  else
  {
    result = 16;
  }
  return result;
}

//----- (006B7690) --------------------------------------------------------  // acclient.c:721081
unsigned int __thiscall GameMoveData::Pack(GameMoveData *this, void **addr, unsigned int size)
{
  GameMoveData *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edi@2
  char *v6; // edx@2
  char *v7; // edi@6
  char *v8; // edx@6
  char *v9; // edi@6
  char *v10; // edi@7

  v3 = this;
  result = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->m_type;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->m_idPlayer;
    v6 = (char *)*addr + 4;
    *addr = v6;
    switch ( v3->m_type )
    {
      case 4:
        *(_DWORD *)v6 = v3->m_idPieceToMove;
        v10 = (char *)*addr + 4;
        *addr = v10;
        *(_DWORD *)v10 = v3->m_yGrid;
        *addr = (char *)*addr + 4;
        break;
      case 5:
        *(_DWORD *)v6 = v3->m_idPieceToMove;
        v7 = (char *)*addr + 4;
        *addr = v7;
        *(_DWORD *)v7 = v3->m_yGrid;
        v8 = (char *)*addr + 4;
        *addr = v8;
        *(_DWORD *)v8 = v3->m_xTo;
        v9 = (char *)*addr + 4;
        *addr = v9;
        *(_DWORD *)v9 = v3->m_yTo;
        *addr = (char *)*addr + 4;
        break;
      case 6:
        *(_DWORD *)v6 = v3->m_idPieceToMove;
        *addr = (char *)*addr + 4;
        break;
    }
  }
  return result;
}

//----- (006B7740) --------------------------------------------------------  // acclient.c:721134
int __thiscall GameMoveData::UnPack(GameMoveData *this, void **addr, unsigned int size)
{
  GameMoveData *v3; // edi@1
  PackObjVtbl *v4; // edx@1
  char *v6; // ecx@3
  char *v7; // eax@3
  char *v8; // eax@7
  char *v9; // edx@7
  char *v10; // ecx@7
  char *v11; // ecx@8

  v3 = this;
  v4 = this->vfptr;
  this->m_type = *(_DWORD *)*addr;
  if ( size < ((int (*)(void))v4->GetPackSize)() )
    return 0;
  v6 = (char *)*addr + 4;
  *addr = v6;
  v3->m_idPlayer = *(_DWORD *)v6;
  v7 = (char *)*addr + 4;
  *addr = v7;
  if ( v3->m_type == 4 )
  {
    v3->m_idPieceToMove = *(_DWORD *)v7;
    v11 = (char *)*addr + 4;
    *addr = v11;
    v3->m_yGrid = *(_DWORD *)v11;
    *addr = (char *)*addr + 4;
  }
  else
  {
    if ( v3->m_type == 5 )
    {
      v3->m_idPieceToMove = *(_DWORD *)v7;
      v8 = (char *)*addr + 4;
      *addr = v8;
      v3->m_yGrid = *(_DWORD *)v8;
      v9 = (char *)*addr + 4;
      *addr = v9;
      v3->m_xTo = *(_DWORD *)v9;
      v10 = (char *)*addr + 4;
      *addr = v10;
      v3->m_yTo = *(_DWORD *)v10;
      *addr = (char *)*addr + 4;
      return 1;
    }
    if ( v3->m_type == 6 )
    {
      v3->m_idPieceToMove = *(_DWORD *)v7;
      *addr = (char *)*addr + 4;
      return 1;
    }
  }
  return 1;
}

//----- (00724940) --------------------------------------------------------  // acclient.c:822295
int sub_724940()
{
  return atexit(nullsub_1811);
}

//----- (00724950) --------------------------------------------------------  // acclient.c:822301
int _E4_37()
{
  return atexit(_E5_37);
}

//----- (00724960) --------------------------------------------------------  // acclient.c:822307
int _E7_37()
{
  Outside_CellID_37.id = Invalid_CellID_37.id + 1;
  return atexit(_E8_37);
}

//----- (00724980) --------------------------------------------------------  // acclient.c:822314
int _E10_36()
{
  In_Limbo_CellID_36.id = Outside_CellID_37.id + 1;
  return atexit(_E11_36);
}

//----- (007249A0) --------------------------------------------------------  // acclient.c:822321
int _E13_36()
{
  First_Interior_CellID_36.id = In_Limbo_CellID_36.id + 1;
  return atexit(_E14_36);
}

//----- (007249C0) --------------------------------------------------------  // acclient.c:822328
int _E16_36()
{
  Last_Interior_CellID_36.id = Invalid_CellID_37.id - 1;
  return atexit(_E17_36);
}

//----- (007249E0) --------------------------------------------------------  // acclient.c:822335
int _E21_39()
{
  return atexit(_E22_39);
}

//----- (007249F0) --------------------------------------------------------  // acclient.c:822341
int _E40_38()
{
  return atexit(_E41_38);
}

//----- (00724A00) --------------------------------------------------------  // acclient.c:822347
int _E43_41()
{
  return atexit(_E44_41);
}

