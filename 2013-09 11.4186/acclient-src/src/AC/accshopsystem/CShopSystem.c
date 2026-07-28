/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CShopSystem
   Object     : AC\accshopsystem\CShopSystem.obj
   Functions  : 3
   Addresses  : 006B6120 - 00724110 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B6120) --------------------------------------------------------  // acclient.c:719869
int __cdecl ShopSystem::BuyPrice(int unit_value, ITEM_TYPE itype, float buy_price, int num_item)
{
  double v4; // st7@2
  unsigned __int64 v5; // rax@4

  if ( itype == 0x40000 )
    v4 = 1.0;
  else
    v4 = buy_price;
  v5 = (unsigned __int64)_floor(v4 * (double)unit_value * (double)num_item + 0.1);
  if ( (_DWORD)v5 )
  {
    if ( (v5 & 0x80000000) != 0i64 )
      LODWORD(v5) = -1;
  }
  else
  {
    LODWORD(v5) = 1;
  }
  return v5;
}

//----- (006B6180) --------------------------------------------------------  // acclient.c:719892
int __cdecl ShopSystem::SellPrice(int unit_value, ITEM_TYPE itype, float sell_price, int num_item)
{
  double v4; // st7@2
  unsigned __int64 v5; // rax@4

  if ( itype == 0x40000 )
    v4 = 1.15;
  else
    v4 = sell_price;
  v5 = (unsigned __int64)_ceil(v4 * (double)unit_value * (double)num_item - 0.1);
  if ( (_DWORD)v5 )
  {
    if ( (signed int)v5 <= 0 )
      LODWORD(v5) = -1;
  }
  else
  {
    LODWORD(v5) = 1;
  }
  return v5;
}

//----- (00724110) --------------------------------------------------------  // acclient.c:821848
int sub_724110()
{
  return atexit(nullsub_1428);
}

