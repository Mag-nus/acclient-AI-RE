/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ContentsList
   Object     : PORTAL\gameplay_misc\ContentsList.obj
   Functions  : 3
   Addresses  : 006AFED0 - 006AFF10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AFED0) --------------------------------------------------------  // acclient.c:713270
void __thiscall ContentProfile::ContentProfile(ContentProfile *this, unsigned int iid)
{
  this->vfptr = (PackObjVtbl *)&ContentProfile::vftable;
  this->m_iid = iid;
  this->m_uContainerProperties = 0;
}
// 7CC40C: using guessed type int (__thiscall *ContentProfile::vftable)(void *, char);

//----- (006AFEF0) --------------------------------------------------------  // acclient.c:713279
void __thiscall ContentProfile::ContentProfile(ContentProfile *this)
{
  this->vfptr = (PackObjVtbl *)&ContentProfile::vftable;
  this->m_iid = 0;
  this->m_uContainerProperties = 0;
}
// 7CC40C: using guessed type int (__thiscall *ContentProfile::vftable)(void *, char);

//----- (006AFF10) --------------------------------------------------------  // acclient.c:713288
int __thiscall ContentProfile::UnPack(ContentProfile *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3

  if ( size >= 8 )
  {
    this->m_iid = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    this->m_uContainerProperties = *(_DWORD *)v4;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

