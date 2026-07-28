/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ItemUses
   Object     : PORTAL\gameplay_misc\ItemUses.obj
   Functions  : 6
   Addresses  : 004FCCB0 - 004FCD50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FCCB0) --------------------------------------------------------  // acclient.c:296795
void __thiscall ItemUses::ItemUses(ItemUses *this, const unsigned int useable_bitfield)
{
  this->_useable_bitfield = useable_bitfield;
}

//----- (004FCCC0) --------------------------------------------------------  // acclient.c:296801
int __thiscall ItemUses::IsUseable(ItemUses *this)
{
  return ~(unsigned __int8)this->_useable_bitfield & 1;
}

//----- (004FCCD0) --------------------------------------------------------  // acclient.c:296807
int __thiscall ItemUses::GetLeastLimitedSourceUse(ItemUses *this)
{
  int v1; // eax@1
  int result; // eax@2

  v1 = this->_useable_bitfield;
  if ( this->_useable_bitfield & 0x20 )
  {
    result = 32;
  }
  else if ( v1 & 0x10 )
  {
    result = 16;
  }
  else if ( v1 & 8 )
  {
    result = 8;
  }
  else if ( v1 & 4 )
  {
    result = 4;
  }
  else
  {
    result = v1 & 2;
  }
  return result;
}

//----- (004FCD10) --------------------------------------------------------  // acclient.c:296837
unsigned int __thiscall ItemUses::IsUseable_Targeted(ItemUses *this)
{
  unsigned int v1; // edx@1
  unsigned int result; // eax@1

  v1 = 0xFFFF;
  result = this->_useable_bitfield & 0xFFFF0000;
  do
  {
    v1 >>= 1;
    result >>= 1;
  }
  while ( v1 );
  return result;
}

//----- (004FCD30) --------------------------------------------------------  // acclient.c:296854
unsigned int __thiscall ItemUses::IsUseable_SelfTarget(ItemUses *this)
{
  unsigned int v1; // edx@1
  unsigned int v2; // eax@1

  v1 = 0xFFFF;
  v2 = this->_useable_bitfield & 0xFFFF0000;
  do
  {
    v1 >>= 1;
    v2 >>= 1;
  }
  while ( v1 );
  return v2 & 2;
}

//----- (004FCD50) --------------------------------------------------------  // acclient.c:296871
int __thiscall ItemUses::GetLeastLimitedTargetUse(ItemUses *this)
{
  unsigned int v1; // edx@1
  unsigned int v2; // eax@1
  int result; // eax@4

  v1 = 0xFFFF;
  v2 = this->_useable_bitfield & 0xFFFF0000;
  do
  {
    v1 >>= 1;
    v2 >>= 1;
  }
  while ( v1 );
  if ( v2 & 0x20 )
  {
    result = 32;
  }
  else if ( v2 & 0x10 )
  {
    result = 16;
  }
  else if ( v2 & 8 )
  {
    result = 8;
  }
  else if ( v2 & 4 )
  {
    result = 4;
  }
  else if ( v2 & 2 )
  {
    result = 2;
  }
  else
  {
    result = v2 & 0x80;
  }
  return result;
}

