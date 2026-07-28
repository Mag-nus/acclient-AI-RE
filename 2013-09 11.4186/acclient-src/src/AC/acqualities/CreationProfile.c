/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CreationProfile
   Object     : AC\acqualities\CreationProfile.obj
   Functions  : 9
   Addresses  : 005CC2C0 - 00710080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CC2C0) --------------------------------------------------------  // acclient.c:503968
int __thiscall CreationProfile::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  }
  return result;
}

//----- (005CC300) --------------------------------------------------------  // acclient.c:503986
void __thiscall CreationProfile::CreationProfile(CreationProfile *this)
{
  this->vfptr = (PackObjVtbl *)&CreationProfile::vftable;
  this->wcid.id = stru_8EFEC0.id;
  this->try_to_bond = 0;
  this->palette = 0;
  LODWORD(this->shade) = 0;
  this->destination = 0;
  this->stack_size = 0;
}
// 7E83AC: using guessed type int (__thiscall *CreationProfile::vftable)(void *, char);

//----- (005CC330) --------------------------------------------------------  // acclient.c:503999
void __thiscall CreationProfile::CreationProfile(CreationProfile *this, CreationProfile *rhs)
{
  this->vfptr = (PackObjVtbl *)&CreationProfile::vftable;
  if ( this != rhs )
  {
    this->wcid.id = rhs->wcid.id;
    this->palette = rhs->palette;
    this->shade = rhs->shade;
    this->destination = rhs->destination;
    this->stack_size = rhs->stack_size;
    this->try_to_bond = rhs->try_to_bond;
  }
}
// 7E83AC: using guessed type int (__thiscall *CreationProfile::vftable)(void *, char);

//----- (005CC370) --------------------------------------------------------  // acclient.c:504015
signed int __thiscall CreationProfile::Pack(CreationProfile *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2
  char *v6; // esi@2
  char *v7; // edx@2

  if ( size >= 0x18 )
  {
    *(_DWORD *)*addr = this->wcid.id;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->palette;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(float *)v4 = this->shade;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->destination;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->stack_size;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->try_to_bond;
    *addr = (char *)*addr + 4;
  }
  return 24;
}

//----- (005CC3D0) --------------------------------------------------------  // acclient.c:504047
int __thiscall CreationProfile::UnPack(CreationProfile *this, void **addr, unsigned int size)
{
  int result; // eax@2
  unsigned int v4; // esi@3
  char *v5; // esi@3
  char *v6; // edx@3
  char *v7; // esi@3
  char *v8; // edx@3

  if ( size >= 0x18 )
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->wcid.id = v4;
    this->palette = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->shade) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->destination = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->stack_size = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->try_to_bond = *(_DWORD *)v8;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00710020) --------------------------------------------------------  // acclient.c:803289
void sub_710020()
{
  flt_8EFEC4 = 1000.0 + 1.0;
}

//----- (00710040) --------------------------------------------------------  // acclient.c:803295
void sub_710040()
{
  flt_8EFEC8 = 24.0 * 8.0;
}

//----- (00710060) --------------------------------------------------------  // acclient.c:803301
void sub_710060()
{
  flt_8EFECC = 24.0 * 0.5;
}

//----- (00710080) --------------------------------------------------------  // acclient.c:803307
int sub_710080()
{
  return atexit(nullsub_1835);
}

