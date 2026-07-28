/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Body
   Object     : AC\acbody\Body.obj
   Functions  : 3
   Addresses  : 005CB130 - 00710410 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CB130) --------------------------------------------------------  // acclient.c:502695
int __thiscall Body::UnPack(Body *this, void **addr, unsigned int size)
{
  PackObjVtbl *v3; // eax@1
  void **v4; // edi@1
  void *v5; // ebp@1
  char *v6; // esi@1
  unsigned int v7; // eax@1
  unsigned int v8; // ebx@1

  v3 = this->_body_part_table.vfptr;
  v4 = addr;
  v5 = *addr;
  v6 = (char *)&this->_body_part_table;
  addr = 0;
  v7 = ((int (__thiscall *)(PackableHashTable<long,BodyPart> *, void ***, _DWORD))v3->Pack)(
         &this->_body_part_table,
         &addr,
         0);
  v8 = size;
  if ( size < v7 )
    return 0;
  (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v6 + 16))(v6, v4, size);
  if ( v8 < (_BYTE *)*v4 - (_BYTE *)v5 )
  {
    *v4 = v5;
    return 0;
  }
  return 1;
}

//----- (005D1060) --------------------------------------------------------  // acclient.c:509045
unsigned int __thiscall GeneratorRegistry::Pack(Body *this, void **addr, unsigned int size)
{
  PackObjVtbl *v3; // eax@1
  char *v4; // esi@1
  unsigned int v5; // edi@1
  Body *v7; // [sp+0h] [bp-4h]@1

  v7 = this;
  v3 = this->_body_part_table.vfptr;
  v4 = (char *)&this->_body_part_table;
  v7 = 0;
  v5 = ((int (__thiscall *)(PackableHashTable<long,BodyPart> *, int *, _DWORD))v3->Pack)(
         &this->_body_part_table,
         &v7,
         0);
  if ( size >= v5 )
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 12))(v4, addr, size);
  return v5;
}

//----- (00710410) --------------------------------------------------------  // acclient.c:803525
int sub_710410()
{
  return atexit(nullsub_1844);
}

