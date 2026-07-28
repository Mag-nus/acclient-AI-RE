/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Plane
   Object     : ENGINE\engine_shared_geometry\Plane.obj
   Functions  : 6
   Addresses  : 005B2AA0 - 0070E630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B2AA0) --------------------------------------------------------  // acclient.c:477314
int __thiscall PFileNode::MakeSubNodeAsFloat(PFileNode *this, float i_name)
{
  int result; // eax@1
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@2
  void *v5; // eax@4

  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = (PFileNode *)result;
  if ( result )
  {
    v4 = *(IFileNodeName **)(result + 8);
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_pcName = 0;
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = &FileNodeName_Float::vftable;
      *((float *)v5 + 1) = i_name;
      v3->m_pcName = (IFileNodeName *)v5;
      result = (int)v3;
    }
    else
    {
      v3->m_pcName = 0;
      result = (int)v3;
    }
  }
  return result;
}
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);

//----- (0070E5C0) --------------------------------------------------------  // acclient.c:801363
void sub_70E5C0()
{
  flt_8EF3A4 = 1000.0 + 1.0;
}

//----- (0070E5E0) --------------------------------------------------------  // acclient.c:801369
void sub_70E5E0()
{
  flt_8EF3A8 = 24.0 * 8.0;
}

//----- (0070E600) --------------------------------------------------------  // acclient.c:801375
void sub_70E600()
{
  flt_8EF3AC = 24.0 * 0.5;
}

//----- (0070E620) --------------------------------------------------------  // acclient.c:801381
int _E43_7()
{
  return atexit(_E44_7);
}

//----- (0070E630) --------------------------------------------------------  // acclient.c:801387
int sub_70E630()
{
  return atexit(nullsub_1551);
}

