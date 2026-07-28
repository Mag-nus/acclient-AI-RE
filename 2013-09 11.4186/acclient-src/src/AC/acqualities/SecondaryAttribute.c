/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SecondaryAttribute
   Object     : AC\acqualities\SecondaryAttribute.obj
   Functions  : 4
   Addresses  : 005CAC40 - 005CAC90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CAC40) --------------------------------------------------------  // acclient.c:502324
int __stdcall SecondaryAttribute::LevelFromExperience(unsigned int xp)
{
  return ExperienceSystem::Attribute2ndLevelFromExperience(xp);
}

//----- (005CAC50) --------------------------------------------------------  // acclient.c:502330
int __stdcall SecondaryAttribute::ExperienceToLevel(unsigned int level)
{
  return ExperienceSystem::ExperienceToAttribute2ndLevel(level);
}

//----- (005CAC60) --------------------------------------------------------  // acclient.c:502336
signed int __thiscall SecondaryAttribute::Pack(SecondaryAttribute *this, void **addr, unsigned int size)
{
  SecondaryAttribute *v3; // edi@1

  v3 = this;
  if ( size >= 0x10 )
  {
    InventoryPlacement::Pack((ShortCutData *)this, addr, size);
    *(_DWORD *)*addr = v3->_current_level;
    *addr = (char *)*addr + 4;
  }
  return 16;
}

//----- (005CAC90) --------------------------------------------------------  // acclient.c:502351
int __thiscall SecondaryAttribute::UnPack(SecondaryAttribute *this, void **addr, unsigned int size)
{
  void *v3; // ebp@1
  SecondaryAttribute *v4; // edi@1
  unsigned int v5; // eax@2

  v3 = *addr;
  v4 = this;
  if ( size < 0x10 )
    return 0;
  Attribute::UnPack((Attribute *)&this->vfptr, addr, size);
  v4->_current_level = *(_DWORD *)*addr;
  v5 = (_BYTE *)*addr + 4 - (_BYTE *)v3;
  *addr = (char *)*addr + 4;
  if ( size < v5 )
  {
    *addr = v3;
    return 0;
  }
  return 1;
}

