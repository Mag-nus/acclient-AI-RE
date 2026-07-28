/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EncumbranceSystem
   Object     : PORTAL\gameplay_misc\EncumbranceSystem.obj
   Functions  : 3
   Addresses  : 004FCC00 - 004FCC70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FCC00) --------------------------------------------------------  // acclient.c:296730
int __cdecl EncumbranceSystem::EncumbranceCapacity(const int strength, const int encumb_augmentations)
{
  int result; // eax@2
  int v3; // eax@3

  if ( strength > 0 )
  {
    v3 = 30 * encumb_augmentations;
    if ( 30 * encumb_augmentations >= 0 )
    {
      if ( v3 > 150 )
        v3 = 150;
      result = 150 * strength + strength * v3;
    }
    else
    {
      result = 150 * strength;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FCC40) --------------------------------------------------------  // acclient.c:296757
double __cdecl EncumbranceSystem::Load(const int encumb_capacity, const int encumb_val)
{
  double result; // st7@2

  if ( encumb_capacity > 0 )
  {
    if ( encumb_val >= 0 )
      result = (double)encumb_val / (double)encumb_capacity;
    else
      result = 0.0;
  }
  else
  {
    result = 3.0;
  }
  return result;
}

//----- (004FCC70) --------------------------------------------------------  // acclient.c:296776
double __cdecl EncumbranceSystem::LoadMod(const float load)
{
  double result; // st7@2

  if ( load >= 1.0 )
  {
    if ( load >= 2.0 )
      result = 0.0;
    else
      result = 2.0 - load;
  }
  else
  {
    result = 1.0;
  }
  return result;
}

