/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ti_inst
   Object     : _runtime\intel_jpeg\ti_inst.obj
   Functions  : 1
   Addresses  : 006B7C70 - 006B7C70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B7C70) --------------------------------------------------------  // acclient.c:721557
int __thiscall type_info::vector_deleting_destructor(type_info *this, unsigned int a2)
{
  type_info *v2; // esi@1
  int result; // eax@4

  v2 = this;
  if ( a2 & 2 )
  {
    eh_vector_destructor_iterator(this, 0xCu, *(_DWORD *)&this[-1]._m_d_name[0], type_info::~type_info);
    if ( a2 & 1 )
      operator delete(v2[-1]._m_d_name);
    result = (int)v2[-1]._m_d_name;
  }
  else
  {
    type_info::~type_info(this);
    if ( a2 & 1 )
      operator delete(v2);
    result = (int)v2;
  }
  return result;
}

