/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CFileNameDesc
   Object     : PORTAL\cregion\CFileNameDesc.obj
   Functions  : 1
   Addresses  : 005008D0 - 005008D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005008D0) --------------------------------------------------------  // acclient.c:301374
void __thiscall FileNameDesc::~FileNameDesc(FileNameDesc *this)
{
  FileNameDesc *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@4
  AC1Legacy::PSRefBuffer<char> *v4; // esi@7
  AC1Legacy::PSRefBuffer<char> *v5; // edi@10

  v1 = this;
  v2 = this->encounter_type_map.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->scene_map.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v1->terrain_map.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v5 = v1->height_map.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
  {
    if ( v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  }
}

