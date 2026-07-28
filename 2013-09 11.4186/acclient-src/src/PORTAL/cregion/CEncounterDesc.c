/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEncounterDesc
   Object     : PORTAL\cregion\CEncounterDesc.obj
   Functions  : 5
   Addresses  : 00502990 - 006F9DE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502990) --------------------------------------------------------  // acclient.c:303758
void __thiscall CEncounterDesc::Destroy(CEncounterDesc *this)
{
  CEncounterDesc *v1; // edi@1
  unsigned int v2; // ebx@2
  void *v3; // esi@3

  v1 = this;
  if ( this->encounter_table )
  {
    v2 = 0;
    if ( this->num_encounter_type )
    {
      do
      {
        v3 = v1->encounter_table[v2];
        if ( v3 )
        {
          if ( *(_DWORD *)v3 )
            operator delete[]((void *)(*(_DWORD *)v3 - 4));
          *(_DWORD *)v3 = 0;
          operator delete(v3);
        }
        ++v2;
      }
      while ( v2 < v1->num_encounter_type );
    }
    operator delete[](v1->encounter_table);
    v1->encounter_table = 0;
  }
  if ( v1->encounter_map )
  {
    operator delete[](v1->encounter_map);
    v1->encounter_map = 0;
  }
  v1->num_encounter_type = 0;
}

//----- (006F9D80) --------------------------------------------------------  // acclient.c:782541
void sub_6F9D80()
{
  flt_84164C = 1000.0 + 1.0;
}

//----- (006F9DA0) --------------------------------------------------------  // acclient.c:782547
void sub_6F9DA0()
{
  flt_841650 = 24.0 * 8.0;
}

//----- (006F9DC0) --------------------------------------------------------  // acclient.c:782553
void sub_6F9DC0()
{
  flt_841654 = 24.0 * 0.5;
}

//----- (006F9DE0) --------------------------------------------------------  // acclient.c:782559
int sub_6F9DE0()
{
  return atexit(nullsub_1064);
}

