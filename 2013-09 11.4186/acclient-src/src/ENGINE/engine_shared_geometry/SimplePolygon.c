/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SimplePolygon
   Object     : ENGINE\engine_shared_geometry\SimplePolygon.obj
   Functions  : 1
   Addresses  : 005B27D0 - 005B27D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B27D0) --------------------------------------------------------  // acclient.c:477193
void __cdecl Serializer::SerializeObject(Vector3 *io_object, Archive *io_archive)
{
  unsigned int v2; // eax@1

  Archive::CheckAlignment(io_archive, 0xCu);
  v2 = Archive::GetBytes(io_archive, 0xCu);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(Vector3 *)v2 = *io_object;
    }
    else
    {
      LODWORD(io_object->x) = *(_DWORD *)v2;
      LODWORD(io_object->y) = *(_DWORD *)(v2 + 4);
      LODWORD(io_object->z) = *(_DWORD *)(v2 + 8);
    }
  }
}

