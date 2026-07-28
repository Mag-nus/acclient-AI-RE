/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Vector
   Object     : PORTAL\geometry\Vector.obj
   Functions  : 1
   Addresses  : 0068A3A0 - 0068A3A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0068A3A0) --------------------------------------------------------  // acclient.c:673820
void __thiscall QualifiedControl::Serialize(AC1Legacy::Vector3 *this, Archive *io_archive)
{
  AC1Legacy::Vector3 *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = LODWORD(v2->x);
    else
      LODWORD(v2->x) = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = LODWORD(v2->y);
    else
      LODWORD(v2->y) = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = LODWORD(v2->z);
    else
      LODWORD(v2->z) = *(_DWORD *)v5;
  }
}

