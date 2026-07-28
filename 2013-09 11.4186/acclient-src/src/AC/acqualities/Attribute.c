/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Attribute
   Object     : AC\acqualities\Attribute.obj
   Functions  : 3
   Addresses  : 005CAB90 - 005CABF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CAB90) --------------------------------------------------------  // acclient.c:502264
int __stdcall Attribute::LevelFromExperience(unsigned int xp)
{
  return ExperienceSystem::AttributeLevelFromExperience(xp);
}

//----- (005CABA0) --------------------------------------------------------  // acclient.c:502270
int __stdcall Attribute::ExperienceToLevel(unsigned int level)
{
  return ExperienceSystem::ExperienceToAttributeLevel(level);
}

//----- (005CABF0) --------------------------------------------------------  // acclient.c:502296
int __thiscall Attribute::UnPack(Attribute *this, void **addr, unsigned int size)
{
  unsigned int *v3; // edx@1
  char *v4; // esi@2
  char *v5; // esi@2
  char *v6; // ecx@2

  v3 = (unsigned int *)*addr;
  if ( size < 0xC )
    return 0;
  this->_level_from_cp = *v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  this->_init_level = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  this->_cp_spent = *(_DWORD *)v5;
  v6 = (char *)*addr + 4;
  *addr = v6;
  if ( size < v6 - (char *)v3 )
  {
    *addr = v3;
    return 0;
  }
  return 1;
}

