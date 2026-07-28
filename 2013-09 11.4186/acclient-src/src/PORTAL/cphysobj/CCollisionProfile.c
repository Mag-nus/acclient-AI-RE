/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCollisionProfile
   Object     : PORTAL\cphysobj\CCollisionProfile.obj
   Functions  : 12
   Addresses  : 0051B900 - 006FC8F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051B900) --------------------------------------------------------  // acclient.c:329560
void __thiscall AtkCollisionProfile::AtkCollisionProfile(AtkCollisionProfile *this)
{
  this->part = -1;
  this->id = 0;
  this->location = 0;
}

//----- (0051B920) --------------------------------------------------------  // acclient.c:329568
void __thiscall EnvCollisionProfile::SetMeInContact(EnvCollisionProfile *this, const int hasContact)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( hasContact )
    this->_bitfield = v2 | 1;
  else
    this->_bitfield = v2 & 0xFFFFFFFE;
}

//----- (0051B940) --------------------------------------------------------  // acclient.c:329580
void __thiscall ObjCollisionProfile::SetCreature(ObjCollisionProfile *this, const int isCreature)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( isCreature )
    this->_bitfield = v2 | 1;
  else
    this->_bitfield = v2 & 0xFFFFFFFE;
}

//----- (0051B960) --------------------------------------------------------  // acclient.c:329592
void __thiscall ObjCollisionProfile::SetPlayer(ObjCollisionProfile *this, const int isPlayer)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( isPlayer )
    this->_bitfield = v2 | 2;
  else
    this->_bitfield = v2 & 0xFFFFFFFD;
}

//----- (0051B980) --------------------------------------------------------  // acclient.c:329604
void __thiscall ObjCollisionProfile::SetDoor(ObjCollisionProfile *this, const int isDoor)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( isDoor )
    this->_bitfield = v2 | 0x40;
  else
    this->_bitfield = v2 & 0xFFFFFFBF;
}

//----- (0051B9A0) --------------------------------------------------------  // acclient.c:329616
void __thiscall ObjCollisionProfile::SetAttackable(ObjCollisionProfile *this, const int attackable)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( attackable )
    this->_bitfield = v2 | 4;
  else
    this->_bitfield = v2 & 0xFFFFFFFB;
}

//----- (0051B9C0) --------------------------------------------------------  // acclient.c:329628
void __thiscall ObjCollisionProfile::SetMissile(ObjCollisionProfile *this, const int isMissile)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( isMissile )
    this->_bitfield = v2 | 8;
  else
    this->_bitfield = v2 & 0xFFFFFFF7;
}

//----- (0051B9E0) --------------------------------------------------------  // acclient.c:329640
void __thiscall ObjCollisionProfile::SetInContact(ObjCollisionProfile *this, const int hasContact)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( hasContact )
    this->_bitfield = v2 | 0x10;
  else
    this->_bitfield = v2 & 0xFFFFFFEF;
}

//----- (0051BA00) --------------------------------------------------------  // acclient.c:329652
void __thiscall ObjCollisionProfile::SetMeInContact(ObjCollisionProfile *this, const int hasContact)
{
  unsigned int v2; // eax@1

  v2 = this->_bitfield;
  if ( hasContact )
    this->_bitfield = v2 | 0x20;
  else
    this->_bitfield = v2 & 0xFFFFFFDF;
}

//----- (0051BA20) --------------------------------------------------------  // acclient.c:329664
void __thiscall EnvCollisionProfile::EnvCollisionProfile(EnvCollisionProfile *this)
{
  this->_bitfield = 0;
}

//----- (0051BA30) --------------------------------------------------------  // acclient.c:329670
void __thiscall ObjCollisionProfile::ObjCollisionProfile(ObjCollisionProfile *this)
{
  this->id = 0;
  this->wcid.id = stru_844110.id;
  this->itemType = 0;
  this->_bitfield = 0;
}

//----- (006FC8F0) --------------------------------------------------------  // acclient.c:784901
int sub_6FC8F0()
{
  return atexit(nullsub_1112);
}

