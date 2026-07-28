/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLOCache
   Object     : ENGINE\engine_cdatabase\CLOCache.obj
   Functions  : 3
   Addresses  : 00417320 - 006F9440 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00417320) --------------------------------------------------------  // acclient.c:83983
CLOCache *__thiscall DBOCache::scalar_deleting_destructor(CLOCache *this, unsigned int a2)
{
  CLOCache *v2; // esi@1

  v2 = this;
  DBOCache::~DBOCache((DBOCache *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004FC500) --------------------------------------------------------  // acclient.c:296216
void __thiscall CLOCache::CLOCache(CLOCache *this, DBObj *(__cdecl *_allocator)(), unsigned int _dbtype)
{
  CLOCache *v3; // esi@1

  v3 = this;
  DBOCache::DBOCache((DBOCache *)&this->vfptr, _allocator, _dbtype);
  v3->vfptr = (DBOCacheVtbl *)&CLOCache::vftable;
}
// 7C5CF8: using guessed type int (__thiscall *CLOCache::vftable)(void *, char);

//----- (006F9440) --------------------------------------------------------  // acclient.c:781987
int sub_6F9440()
{
  return atexit(nullsub_1030);
}

