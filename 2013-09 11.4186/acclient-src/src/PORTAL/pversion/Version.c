/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Version
   Object     : PORTAL\pversion\Version.obj
   Functions  : 4
   Addresses  : 00554CD0 - 00554E00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00554CD0) --------------------------------------------------------  // acclient.c:388007
char *__cdecl AC1Legacy::Version::StringFromVersion(AC1Legacy::VERSION_NO_t *version)
{
  void *v1; // eax@1
  void *v2; // esi@1

  v1 = operator new[](0x10u);
  v2 = v1;
  *((_BYTE *)v1 + 15) = 0;
  __snprintf(
    (char *)v1,
    0xFu,
    "%2.2d.%2.2d.%2.2d.%c%c%c%c.%c",
    version->rr,
    version->sc,
    version->bb,
    version->mm[0],
    version->mm[1],
    version->dd[0],
    version->dd[1],
    version->debug);
  return (char *)v2;
}

//----- (00554D20) --------------------------------------------------------  // acclient.c:388031
char *__cdecl AC1Legacy::Version::FileVersionStringFromVersion(AC1Legacy::VERSION_NO_t *version)
{
  void *v1; // eax@1
  void *v2; // esi@1

  v1 = operator new[](0xEu);
  v2 = v1;
  *((_BYTE *)v1 + 13) = 0;
  __snprintf(
    (char *)v1,
    0xDu,
    "%2.2d.%2.2d.%2.2d.%c%c%c%c",
    version->rr,
    version->sc,
    version->bb,
    version->mm[0],
    version->mm[1],
    version->dd[0],
    version->dd[1]);
  return (char *)v2;
}

//----- (00554D70) --------------------------------------------------------  // acclient.c:388054
DWORD __cdecl AC1Legacy::Version::Init(const char *fname)
{
  DWORD result; // eax@2
  char *v2; // esi@3
  AC1Legacy::VERSION_NO_t version; // [sp+0h] [bp-8h]@3

  if ( !AC1Legacy::Version::VerboseVersionString_ )
  {
    result = AC1Legacy::Resource::Init(fname);
    if ( !result )
      return result;
    AC1Legacy::Resource::GetVersion(&version);
    v2 = AC1Legacy::Resource::GetComments();
    AC1Legacy::Version::BuildVersion_ = AC1Legacy::Version::StringFromVersion(&version);
    AC1Legacy::Version::FileVersion_ = AC1Legacy::Version::FileVersionStringFromVersion(&version);
    AC1Legacy::Version::VerboseVersionString_ = operator new[](0x44u);
    _sprintf((char *)AC1Legacy::Version::VerboseVersionString_, "%s Portal:%s", AC1Legacy::Version::BuildVersion_, v2);
    operator delete(v2);
  }
  return 1;
}

//----- (00554E00) --------------------------------------------------------  // acclient.c:388077
void __cdecl AC1Legacy::Version::Cleanup()
{
  AC1Legacy::Resource::Cleanup();
  operator delete(AC1Legacy::Version::VerboseVersionString_);
  AC1Legacy::Version::VerboseVersionString_ = 0;
  operator delete(AC1Legacy::Version::BuildVersion_);
  operator delete(AC1Legacy::Version::FileVersion_);
}

