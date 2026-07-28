/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HookAppraisalProfile
   Object     : AC\acappraisal\HookAppraisalProfile.obj
   Functions  : 5
   Addresses  : 005B64B0 - 005B64F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B64B0) --------------------------------------------------------  // acclient.c:481107
void __thiscall HookAppraisalProfile::Clear(HookAppraisalProfile *this)
{
  this->mBitfield = 0;
  this->mValidLocations = 0;
  this->mAmmoType = 0;
}

//----- (005B64C0) --------------------------------------------------------  // acclient.c:481115
unsigned int __thiscall HookAppraisalProfile::IsInscribable(HookAppraisalProfile *this)
{
  return this->mBitfield & 1;
}

//----- (005B64D0) --------------------------------------------------------  // acclient.c:481121
unsigned int __thiscall HookAppraisalProfile::IsHealer(HookAppraisalProfile *this)
{
  return this->mBitfield & 2;
}

//----- (005B64E0) --------------------------------------------------------  // acclient.c:481127
unsigned int __thiscall HookAppraisalProfile::IsLockpick(HookAppraisalProfile *this)
{
  return this->mBitfield & 8;
}

//----- (005B64F0) --------------------------------------------------------  // acclient.c:481133
signed int __thiscall HookAppraisalProfile::Pack(HookAppraisalProfile *this, void **addr, unsigned int size)
{
  char *v3; // esi@3
  char *v4; // edx@3

  if ( *addr && size >= 0xC )
  {
    *(_DWORD *)*addr = this->mBitfield;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->mValidLocations;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->mAmmoType;
    *addr = (char *)*addr + 4;
  }
  return 12;
}

