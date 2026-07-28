/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ObjDesc
   Object     : PORTAL\objdesc\ObjDesc.obj
   Functions  : 24
   Addresses  : 005AB600 - 0070E1C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AB600) --------------------------------------------------------  // acclient.c:469200
TextureMapChange *__thiscall ObjDesc::GetTextureMapChange(ObjDesc *this, int _num)
{
  int v2; // edx@1
  TextureMapChange *result; // eax@3

  v2 = _num;
  if ( _num >= this->num_texture_map_changes || _num < 0 )
  {
    result = 0;
  }
  else
  {
    result = this->firstTMChange;
    if ( _num )
    {
      do
      {
        --v2;
        result = result->next;
      }
      while ( v2 );
    }
  }
  return result;
}

//----- (005AB620) --------------------------------------------------------  // acclient.c:469227
AnimPartChange *__thiscall ObjDesc::GetAnimPartChange(ObjDesc *this, int _num)
{
  int v2; // edx@1
  AnimPartChange *result; // eax@3

  v2 = _num;
  if ( _num >= this->num_anim_part_changes || _num < 0 )
  {
    result = 0;
  }
  else
  {
    result = this->firstAPChange;
    if ( _num )
    {
      do
      {
        --v2;
        result = result->next;
      }
      while ( v2 );
    }
  }
  return result;
}

//----- (005AB640) --------------------------------------------------------  // acclient.c:469254
void __thiscall ObjDesc::RemoveDuplicateSubpalette(ObjDesc *this, Subpalette *newGuy)
{
  ObjDesc *v2; // edi@1
  Subpalette *v3; // esi@1
  Subpalette *v4; // ebx@2
  Subpalette *v5; // eax@3
  Subpalette *v6; // eax@6

  v2 = this;
  v3 = this->firstSubpal;
  if ( v3 )
  {
    do
    {
      v4 = v3->next;
      if ( Subpalette::replaces(newGuy, v3) )
      {
        v5 = v3->next;
        if ( v5 )
          v5->prev = v3->prev;
        else
          v2->lastSubpal = v3->prev;
        v6 = v3->prev;
        if ( v6 )
          v6->next = v3->next;
        else
          v2->firstSubpal = v3->next;
        v3->vfptr->__vecDelDtor((PackObj *)v3, 1u);
        --v2->num_subpalettes;
      }
      v3 = v4;
    }
    while ( v4 );
  }
}

//----- (005AB6B0) --------------------------------------------------------  // acclient.c:469291
void __thiscall ObjDesc::RemoveDuplicateTextureMapChange(ObjDesc *this, TextureMapChange *newGuy)
{
  ObjDesc *v2; // edi@1
  TextureMapChange *v3; // esi@1
  TextureMapChange *v4; // eax@6
  TextureMapChange *v5; // eax@9

  v2 = this;
  v3 = this->firstTMChange;
  if ( v3 )
  {
    while ( !TextureMapChange::replaces(newGuy, v3) )
    {
      v3 = v3->next;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      v4 = v3->next;
      if ( v4 )
        v4->prev = v3->prev;
      else
        v2->lastTMChange = v3->prev;
      v5 = v3->prev;
      if ( v5 )
        v5->next = v3->next;
      else
        v2->firstTMChange = v3->next;
      v3->vfptr->__vecDelDtor((PackObj *)v3, 1u);
      --v2->num_texture_map_changes;
    }
  }
}

//----- (005AB720) --------------------------------------------------------  // acclient.c:469327
void __thiscall ObjDesc::RemoveDuplicateAnimPartChange(ObjDesc *this, AnimPartChange *newGuy)
{
  ObjDesc *v2; // edi@1
  AnimPartChange *v3; // esi@1
  AnimPartChange *v4; // eax@6
  AnimPartChange *v5; // eax@9

  v2 = this;
  v3 = this->firstAPChange;
  if ( v3 )
  {
    while ( !ContentProfile::operator==((Enchantment *)newGuy, (Enchantment *)v3) )
    {
      v3 = v3->next;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      v4 = v3->next;
      if ( v4 )
        v4->prev = v3->prev;
      else
        v2->lastAPChange = v3->prev;
      v5 = v3->prev;
      if ( v5 )
        v5->next = v3->next;
      else
        v2->firstAPChange = v3->next;
      v3->vfptr->__vecDelDtor((PackObj *)v3, 1u);
      --v2->num_anim_part_changes;
    }
  }
}

//----- (005AB790) --------------------------------------------------------  // acclient.c:469363
void __thiscall ObjDesc::Clear(ObjDesc *this)
{
  ObjDesc *v1; // esi@1
  Subpalette *v2; // ecx@2
  TextureMapChange *v3; // ecx@6
  AnimPartChange *v4; // ecx@10

  v1 = this;
  while ( v1->firstSubpal )
  {
    v2 = v1->firstSubpal;
    v1->firstSubpal = v2->next;
    if ( v2 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  }
  while ( v1->firstTMChange )
  {
    v3 = v1->firstTMChange;
    v1->firstTMChange = v3->next;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  }
  while ( v1->firstAPChange )
  {
    v4 = v1->firstAPChange;
    v1->firstAPChange = v4->next;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  }
  v1->lastSubpal = 0;
  v1->firstSubpal = 0;
  v1->lastTMChange = 0;
  v1->firstTMChange = 0;
  v1->lastAPChange = 0;
  v1->firstAPChange = 0;
  v1->num_subpalettes = 0;
  v1->num_texture_map_changes = 0;
  v1->num_anim_part_changes = 0;
}

//----- (005AB820) --------------------------------------------------------  // acclient.c:469404
void __thiscall ObjDesc::Wipe(ObjDesc *this)
{
  ObjDesc *v1; // esi@1
  Subpalette *v2; // ecx@2
  Subpalette *v3; // eax@3
  Subpalette *v4; // eax@6
  TextureMapChange *v5; // ecx@12
  TextureMapChange *v6; // eax@13
  TextureMapChange *v7; // eax@16
  AnimPartChange *v8; // ecx@22
  AnimPartChange *v9; // eax@23
  AnimPartChange *v10; // eax@26

  v1 = this;
  while ( v1->firstSubpal )
  {
    v2 = v1->firstSubpal;
    if ( v2 )
    {
      v3 = v2->next;
      if ( v3 )
        v3->prev = v2->prev;
      else
        v1->lastSubpal = v2->prev;
      v4 = v2->prev;
      if ( v4 )
        v4->next = v2->next;
      else
        v1->firstSubpal = v2->next;
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      --v1->num_subpalettes;
    }
  }
  while ( v1->firstTMChange )
  {
    v5 = v1->firstTMChange;
    if ( v5 )
    {
      v6 = v5->next;
      if ( v6 )
        v6->prev = v5->prev;
      else
        v1->lastTMChange = v5->prev;
      v7 = v5->prev;
      if ( v7 )
        v7->next = v5->next;
      else
        v1->firstTMChange = v5->next;
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
      --v1->num_texture_map_changes;
    }
  }
  while ( v1->firstAPChange )
  {
    v8 = v1->firstAPChange;
    if ( v8 )
    {
      v9 = v8->next;
      if ( v9 )
        v9->prev = v8->prev;
      else
        v1->lastAPChange = v8->prev;
      v10 = v8->prev;
      if ( v10 )
        v10->next = v8->next;
      else
        v1->firstAPChange = v8->next;
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      --v1->num_anim_part_changes;
    }
  }
}

//----- (005AB910) --------------------------------------------------------  // acclient.c:469478
void __thiscall ObjDesc::ObjDesc(ObjDesc *this)
{
  ObjDesc *v1; // esi@1

  v1 = this;
  WeenieDesc::WeenieDesc((WeenieDesc *)this);
  v1->vfptr = (PackObjVtbl *)&ObjDesc::vftable;
  v1->paletteID.id = stru_8EE0F0.id;
  v1->firstSubpal = 0;
  v1->lastSubpal = 0;
  v1->num_subpalettes = 0;
  v1->firstTMChange = 0;
  v1->lastTMChange = 0;
  v1->num_texture_map_changes = 0;
  v1->firstAPChange = 0;
  v1->lastAPChange = 0;
  v1->num_anim_part_changes = 0;
}
// 7E6028: using guessed type int (__thiscall *ObjDesc::vftable)(void *, char);

//----- (005AB950) --------------------------------------------------------  // acclient.c:469499
void __thiscall ObjDesc::~ObjDesc(ObjDesc *this)
{
  WeenieDesc *v1; // esi@1

  v1 = (WeenieDesc *)this;
  this->vfptr = (PackObjVtbl *)&ObjDesc::vftable;
  ObjDesc::Clear(this);
  WeenieDesc::~WeenieDesc(v1);
}
// 7E6028: using guessed type int (__thiscall *ObjDesc::vftable)(void *, char);

//----- (005AB970) --------------------------------------------------------  // acclient.c:469511
int __thiscall ObjDesc::AddSubpalette(ObjDesc *this, Subpalette *_subpal)
{
  ObjDesc *v2; // edi@1
  int result; // eax@2
  Subpalette *v4; // ebx@3
  Subpalette *v5; // eax@9
  int v6; // eax@12

  v2 = this;
  if ( _subpal )
  {
    v4 = this->firstSubpal;
    if ( v4 )
    {
      while ( !Subpalette::supercedes(v4, _subpal) )
      {
        v4 = v4->next;
        if ( !v4 )
          goto LABEL_6;
      }
      _subpal->vfptr->__vecDelDtor((PackObj *)_subpal, 1u);
      result = 1;
    }
    else
    {
LABEL_6:
      ObjDesc::RemoveDuplicateSubpalette(v2, _subpal);
      if ( v2->num_subpalettes == 255 )
      {
        _subpal->vfptr->__vecDelDtor((PackObj *)_subpal, 1u);
        result = 0;
      }
      else
      {
        v5 = v2->lastSubpal;
        if ( v5 )
        {
          _subpal->prev = v5;
          v2->lastSubpal->next = _subpal;
        }
        else
        {
          _subpal->prev = 0;
          v2->firstSubpal = _subpal;
        }
        _subpal->next = 0;
        v6 = v2->num_subpalettes + 1;
        v2->lastSubpal = _subpal;
        v2->num_subpalettes = v6;
        result = 1;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005ABA10) --------------------------------------------------------  // acclient.c:469572
int __thiscall ObjDesc::AddTextureMapChange(ObjDesc *this, TextureMapChange *_texChange)
{
  ObjDesc *v2; // esi@1
  TextureMapChange *v4; // eax@5
  int v5; // eax@8

  v2 = this;
  if ( !_texChange )
    return 0;
  ObjDesc::RemoveDuplicateTextureMapChange(this, _texChange);
  if ( v2->num_texture_map_changes == 255 )
  {
    _texChange->vfptr->__vecDelDtor((PackObj *)_texChange, 1u);
    return 0;
  }
  v4 = v2->lastTMChange;
  if ( v4 )
  {
    _texChange->prev = v4;
    v2->lastTMChange->next = _texChange;
  }
  else
  {
    _texChange->prev = 0;
    v2->firstTMChange = _texChange;
  }
  _texChange->next = 0;
  v5 = v2->num_texture_map_changes;
  v2->lastTMChange = _texChange;
  v2->num_texture_map_changes = v5 + 1;
  return 1;
}

//----- (005ABA80) --------------------------------------------------------  // acclient.c:469606
int __thiscall ObjDesc::AddAnimPartChange(ObjDesc *this, AnimPartChange *_partChange)
{
  ObjDesc *v2; // esi@1
  AnimPartChange *v4; // eax@5
  int v5; // eax@8

  v2 = this;
  if ( !_partChange )
    return 0;
  ObjDesc::RemoveDuplicateAnimPartChange(this, _partChange);
  if ( v2->num_anim_part_changes == 255 )
  {
    _partChange->vfptr->__vecDelDtor((PackObj *)_partChange, 1u);
    return 0;
  }
  v4 = v2->lastAPChange;
  if ( v4 )
  {
    _partChange->prev = v4;
    v2->lastAPChange->next = _partChange;
  }
  else
  {
    _partChange->prev = 0;
    v2->firstAPChange = _partChange;
  }
  _partChange->next = 0;
  v5 = v2->num_anim_part_changes;
  v2->lastAPChange = _partChange;
  v2->num_anim_part_changes = v5 + 1;
  return 1;
}

//----- (005ABAF0) --------------------------------------------------------  // acclient.c:469640
int __thiscall ObjDesc::pack_size(ObjDesc *this)
{
  ObjDesc *v1; // esi@1
  int v2; // eax@1
  unsigned int v3; // ebp@1
  int v4; // edi@1
  signed int v5; // eax@2
  Subpalette *v6; // ebx@2
  int v7; // eax@3
  TextureMapChange *v8; // ebx@4
  unsigned int v9; // ebp@4
  int v10; // eax@5
  AnimPartChange *v11; // ebx@6
  unsigned int v12; // ebp@6
  int v13; // eax@7
  int result; // eax@9
  void *pDummy; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->num_subpalettes;
  v3 = 0;
  pDummy = 0;
  v4 = 4;
  if ( v2 > 0 )
  {
    v5 = Pack_AsDataIDOfKnownType(0x4000000u, this->paletteID, &pDummy, 0);
    v6 = v1->firstSubpal;
    v4 = v5 + 4;
    if ( v1->num_subpalettes )
    {
      do
      {
        v7 = ((int (__thiscall *)(Subpalette *, void **, _DWORD))v6->vfptr->Pack)(v6, &pDummy, 0);
        v6 = v6->next;
        v4 += v7;
        ++v3;
      }
      while ( v3 < v1->num_subpalettes );
    }
  }
  v8 = v1->firstTMChange;
  v9 = 0;
  if ( v1->num_texture_map_changes )
  {
    do
    {
      v10 = ((int (__thiscall *)(TextureMapChange *, void **, _DWORD))v8->vfptr->Pack)(v8, &pDummy, 0);
      v8 = v8->next;
      v4 += v10;
      ++v9;
    }
    while ( v9 < v1->num_texture_map_changes );
  }
  v11 = v1->firstAPChange;
  v12 = 0;
  if ( v1->num_anim_part_changes )
  {
    do
    {
      v13 = ((int (__thiscall *)(AnimPartChange *, void **, _DWORD))v11->vfptr->Pack)(v11, &pDummy, 0);
      v11 = v11->next;
      v4 += v13;
      ++v12;
    }
    while ( v12 < v1->num_anim_part_changes );
  }
  if ( v4 & 3 )
    result = v4 + 4 - (v4 & 3);
  else
    result = v4;
  return result;
}

//----- (005ABBC0) --------------------------------------------------------  // acclient.c:469714
int __thiscall ObjDesc::Pack(ObjDesc *this, void **addr, unsigned int size)
{
  ObjDesc *v3; // edi@1
  int result; // eax@1
  char *v5; // edx@2
  char *v6; // ecx@2
  char *v7; // ebx@2
  Subpalette *v8; // ebx@4
  unsigned int v9; // ebp@4
  int v10; // ecx@7
  TextureMapChange *v11; // ebx@8
  unsigned int v12; // ebp@9
  int v13; // ecx@12
  AnimPartChange *v14; // ebx@13
  unsigned int v15; // ebp@14
  int v16; // edx@17
  int v17; // ecx@18
  unsigned int packed_size; // [sp+18h] [bp-4h]@1

  v3 = this;
  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  packed_size = result;
  if ( size >= result )
  {
    *(_BYTE *)*addr = 17;
    v5 = (char *)*addr + 1;
    *addr = v5;
    *v5 = LOBYTE(v3->num_subpalettes);
    v6 = (char *)*addr + 1;
    *addr = v6;
    *v6 = LOBYTE(v3->num_texture_map_changes);
    v7 = (char *)*addr + 1;
    *addr = v7;
    *v7 = LOBYTE(v3->num_anim_part_changes);
    *addr = (char *)*addr + 1;
    if ( v3->num_subpalettes > 0 && v3->firstSubpal )
    {
      Pack_AsDataIDOfKnownType(0x4000000u, v3->paletteID, addr, size);
      v8 = v3->firstSubpal;
      v9 = 0;
      if ( v3->num_subpalettes )
      {
        do
        {
          ((void (__thiscall *)(Subpalette *, void **, unsigned int))v8->vfptr->Pack)(v8, addr, size);
          v8 = v8->next;
          ++v9;
        }
        while ( v9 < v3->num_subpalettes );
      }
      result = packed_size;
    }
    v10 = v3->num_texture_map_changes;
    if ( v10 > 0 )
    {
      v11 = v3->firstTMChange;
      if ( v11 )
      {
        v12 = 0;
        if ( v10 )
        {
          do
          {
            ((void (__thiscall *)(TextureMapChange *, void **, unsigned int))v11->vfptr->Pack)(v11, addr, size);
            v11 = v11->next;
            ++v12;
          }
          while ( v12 < v3->num_texture_map_changes );
          result = packed_size;
        }
      }
    }
    v13 = v3->num_anim_part_changes;
    if ( v13 > 0 )
    {
      v14 = v3->firstAPChange;
      if ( v14 )
      {
        v15 = 0;
        if ( v13 )
        {
          do
          {
            ((void (__thiscall *)(AnimPartChange *, void **, unsigned int))v14->vfptr->Pack)(v14, addr, size);
            v14 = v14->next;
            ++v15;
          }
          while ( v15 < v3->num_anim_part_changes );
          result = packed_size;
        }
      }
    }
    v16 = (signed int)*addr % 4;
    if ( v16 )
    {
      v17 = 4 - v16;
      if ( 4 != v16 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v17;
          *addr = (char *)*addr + 1;
        }
        while ( v17 );
      }
    }
  }
  return result;
}

//----- (005ABCF0) --------------------------------------------------------  // acclient.c:469826
int __thiscall ObjDesc::UnPack(ObjDesc *this, void **addr, unsigned int size)
{
  ObjDesc *v3; // edi@1
  void **v4; // ebp@1
  char v5; // cl@1
  char *v6; // eax@1
  char v8; // cl@3
  int v9; // eax@3
  unsigned int v10; // ebx@3
  unsigned __int8 v11; // cl@3
  unsigned __int8 v12; // cl@3
  void *v13; // esi@3
  void *v14; // eax@5
  unsigned int v15; // ecx@6
  unsigned int v16; // ebx@9
  void *v17; // eax@10
  unsigned int v18; // edx@11
  TextureMapChange *v19; // eax@16
  int v20; // eax@19
  unsigned int v21; // ebx@21
  void *v22; // eax@24
  unsigned int v23; // ecx@25
  AnimPartChange *v24; // eax@29
  int v25; // eax@32
  int v26; // ecx@34
  int v27; // eax@35
  int numTMCs; // [sp+14h] [bp-8h]@3
  int numAPCs; // [sp+18h] [bp-4h]@3
  void **addra; // [sp+20h] [bp+4h]@1
  char *end; // [sp+24h] [bp+8h]@4

  v3 = this;
  ObjDesc::Wipe(this);
  v4 = addr;
  v5 = *(_BYTE *)*addr;
  v6 = (char *)*addr + 1;
  addra = (void **)((char *)*addr + size);
  *v4 = v6;
  if ( v5 != 17 )
    return 0;
  v8 = *v6;
  v9 = (int)(v6 + 1);
  *v4 = (void *)v9;
  v10 = (unsigned __int8)v8;
  v11 = *(_BYTE *)v9++;
  *v4 = (void *)v9;
  numTMCs = v11;
  v12 = *(_BYTE *)v9;
  v13 = 0;
  *v4 = (void *)(v9 + 1);
  numAPCs = v12;
  if ( (signed int)v10 > 0 )
  {
    Unpack_AsDataIDOfKnownType(0x4000000u, &v3->paletteID, v4);
    for ( end = 0; (unsigned int)end < v10; ++end )
    {
      v14 = operator new(0x18u);
      if ( v14 )
      {
        *(_DWORD *)v14 = &Subpalette::vftable;
        v15 = stru_8EE0F0.id;
        *((_DWORD *)v14 + 2) = 0;
        *((_DWORD *)v14 + 3) = 0;
        *((_DWORD *)v14 + 4) = 0;
        *((_DWORD *)v14 + 5) = 0;
        *((_DWORD *)v14 + 1) = v15;
        v13 = v14;
      }
      if ( !(*(int (__thiscall **)(void *, void **, int))(*(_DWORD *)v13 + 16))(v13, v4, (char *)addra - (_BYTE *)*v4) )
        return 0;
      ObjDesc::AddSubpalette(v3, (Subpalette *)v13);
      v13 = 0;
    }
  }
  v16 = 0;
  if ( (unsigned int)numTMCs > 0 )
  {
    do
    {
      v17 = operator new(0x18u);
      if ( v17 )
      {
        *((_DWORD *)v17 + 1) = 0;
        *(_DWORD *)v17 = &TextureMapChange::vftable;
        *((_DWORD *)v17 + 2) = stru_8EE0F0.id;
        v18 = stru_8EE0F0.id;
        *((_DWORD *)v17 + 4) = 0;
        *((_DWORD *)v17 + 5) = 0;
        *((_DWORD *)v17 + 3) = v18;
        v13 = v17;
      }
      if ( !(*(int (__thiscall **)(void *, void **, signed int))(*(_DWORD *)v13 + 16))(
              v13,
              v4,
              (char *)addra - (_BYTE *)*v4) )
        return 0;
      ObjDesc::RemoveDuplicateTextureMapChange(v3, (TextureMapChange *)v13);
      if ( v3->num_texture_map_changes == 255 )
      {
        (**(void (__thiscall ***)(void *, signed int))v13)(v13, 1);
      }
      else
      {
        v19 = v3->lastTMChange;
        if ( v19 )
        {
          *((_DWORD *)v13 + 4) = v19;
          v3->lastTMChange->next = (TextureMapChange *)v13;
        }
        else
        {
          *((_DWORD *)v13 + 4) = 0;
          v3->firstTMChange = (TextureMapChange *)v13;
        }
        *((_DWORD *)v13 + 5) = 0;
        v20 = v3->num_texture_map_changes + 1;
        v3->lastTMChange = (TextureMapChange *)v13;
        v3->num_texture_map_changes = v20;
      }
      ++v16;
      v13 = 0;
    }
    while ( v16 < numTMCs );
  }
  v21 = 0;
  if ( (unsigned int)numAPCs > 0 )
  {
    while ( 1 )
    {
      v22 = operator new(0x14u);
      if ( v22 )
      {
        *((_DWORD *)v22 + 1) = 0;
        *(_DWORD *)v22 = &AnimPartChange::vftable;
        v23 = stru_8EE0F0.id;
        *((_DWORD *)v22 + 3) = 0;
        *((_DWORD *)v22 + 4) = 0;
        *((_DWORD *)v22 + 2) = v23;
        v13 = v22;
      }
      if ( !(*(int (__thiscall **)(void *, void **, signed int))(*(_DWORD *)v13 + 16))(
              v13,
              v4,
              (char *)addra - (_BYTE *)*v4) )
        return 0;
      ObjDesc::RemoveDuplicateAnimPartChange(v3, (AnimPartChange *)v13);
      if ( v3->num_anim_part_changes == 255 )
      {
        (**(void (__thiscall ***)(void *, signed int))v13)(v13, 1);
      }
      else
      {
        v24 = v3->lastAPChange;
        if ( v24 )
        {
          *((_DWORD *)v13 + 3) = v24;
          v3->lastAPChange->next = (AnimPartChange *)v13;
        }
        else
        {
          *((_DWORD *)v13 + 3) = 0;
          v3->firstAPChange = (AnimPartChange *)v13;
        }
        *((_DWORD *)v13 + 4) = 0;
        v25 = v3->num_anim_part_changes + 1;
        v3->lastAPChange = (AnimPartChange *)v13;
        v3->num_anim_part_changes = v25;
      }
      ++v21;
      if ( v21 >= numAPCs )
        break;
      v13 = 0;
    }
  }
  v26 = (signed int)*v4 % 4;
  if ( v26 )
  {
    v27 = 4 - v26;
    if ( 4 != v26 )
    {
      do
      {
        *(_BYTE *)*v4 = 0;
        --v27;
        *v4 = (char *)*v4 + 1;
      }
      while ( v27 );
    }
  }
  return 1;
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);
// 7E5B18: using guessed type int (__thiscall *TextureMapChange::vftable)(void *, char);

//----- (005ABF60) --------------------------------------------------------  // acclient.c:470022
WeenieDesc *__thiscall ObjDesc::scalar_deleting_destructor(ObjDesc *this, unsigned int a2)
{
  WeenieDesc *v2; // esi@1

  v2 = (WeenieDesc *)this;
  this->vfptr = (PackObjVtbl *)&ObjDesc::vftable;
  ObjDesc::Clear(this);
  WeenieDesc::~WeenieDesc(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E6028: using guessed type int (__thiscall *ObjDesc::vftable)(void *, char);

//----- (005ABF90) --------------------------------------------------------  // acclient.c:470037
int __thiscall ObjDesc::AddSubpalette(ObjDesc *this, Subpalette *_subpal)
{
  ObjDesc *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &Subpalette::vftable;
    *((_DWORD *)v3 + 1) = _subpal->subID.id;
    *((_DWORD *)v3 + 2) = _subpal->offset;
    *((_DWORD *)v3 + 3) = _subpal->numcolors;
    *((_DWORD *)v3 + 4) = _subpal->prev;
    *((_DWORD *)v3 + 5) = _subpal->next;
    result = ObjDesc::AddSubpalette(v2, (Subpalette *)v3);
  }
  else
  {
    result = ObjDesc::AddSubpalette(v2, 0);
  }
  return result;
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);

//----- (005ABFF0) --------------------------------------------------------  // acclient.c:470064
int __thiscall ObjDesc::AddTextureMapChange(ObjDesc *this, TextureMapChange *_texChange)
{
  ObjDesc *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &TextureMapChange::vftable;
    *((_DWORD *)v3 + 1) = _texChange->part_index;
    *((_DWORD *)v3 + 2) = _texChange->old_tex_id.id;
    *((_DWORD *)v3 + 3) = _texChange->new_tex_id.id;
    *((_DWORD *)v3 + 4) = _texChange->prev;
    *((_DWORD *)v3 + 5) = _texChange->next;
    result = ObjDesc::AddTextureMapChange(v2, (TextureMapChange *)v3);
  }
  else
  {
    result = ObjDesc::AddTextureMapChange(v2, 0);
  }
  return result;
}
// 7E5B18: using guessed type int (__thiscall *TextureMapChange::vftable)(void *, char);

//----- (005AC050) --------------------------------------------------------  // acclient.c:470091
int __thiscall ObjDesc::AddAnimPartChange(ObjDesc *this, AnimPartChange *_partChange)
{
  ObjDesc *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = operator new(0x14u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &AnimPartChange::vftable;
    *((_DWORD *)v3 + 1) = _partChange->part_index;
    *((_DWORD *)v3 + 2) = _partChange->part_id.id;
    *((_DWORD *)v3 + 3) = _partChange->prev;
    *((_DWORD *)v3 + 4) = _partChange->next;
    result = ObjDesc::AddAnimPartChange(v2, (AnimPartChange *)v3);
  }
  else
  {
    result = ObjDesc::AddAnimPartChange(v2, 0);
  }
  return result;
}
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);

//----- (005AC0A0) --------------------------------------------------------  // acclient.c:470117
ObjDesc *__thiscall ObjDesc::operator+=(ObjDesc *this, ObjDesc *rhs)
{
  ObjDesc *v2; // ebp@1
  Subpalette *v3; // esi@1
  unsigned int v4; // ebx@1
  ObjDesc *v5; // edi@1
  void *v6; // eax@2
  TextureMapChange *v7; // ebx@6
  void *v8; // eax@7
  void *v9; // esi@7
  TextureMapChange *v10; // eax@10
  int v11; // eax@13
  AnimPartChange *v12; // ebx@15
  void *v13; // eax@16
  void *v14; // esi@16
  AnimPartChange *v15; // eax@19
  int v16; // eax@22
  ObjDesc *rhsa; // [sp+14h] [bp+4h]@6
  ObjDesc *rhsb; // [sp+14h] [bp+4h]@15

  v2 = rhs;
  v3 = rhs->firstSubpal;
  v4 = 0;
  v5 = this;
  if ( rhs->num_subpalettes )
  {
    do
    {
      v6 = operator new(0x18u);
      if ( v6 )
      {
        *(_DWORD *)v6 = &Subpalette::vftable;
        *((_DWORD *)v6 + 1) = v3->subID.id;
        *((_DWORD *)v6 + 2) = v3->offset;
        *((_DWORD *)v6 + 3) = v3->numcolors;
        *((_DWORD *)v6 + 4) = v3->prev;
        *((_DWORD *)v6 + 5) = v3->next;
      }
      else
      {
        v6 = 0;
      }
      ObjDesc::AddSubpalette(v5, (Subpalette *)v6);
      v3 = v3->next;
      ++v4;
    }
    while ( v4 < rhs->num_subpalettes );
  }
  v7 = rhs->firstTMChange;
  rhsa = 0;
  if ( v2->num_texture_map_changes )
  {
    do
    {
      v8 = operator new(0x18u);
      v9 = v8;
      if ( v8 )
      {
        *(_DWORD *)v8 = &TextureMapChange::vftable;
        *((_DWORD *)v8 + 1) = v7->part_index;
        *((_DWORD *)v8 + 2) = v7->old_tex_id.id;
        *((_DWORD *)v8 + 3) = v7->new_tex_id.id;
        *((_DWORD *)v8 + 4) = v7->prev;
        *((_DWORD *)v8 + 5) = v7->next;
        ObjDesc::RemoveDuplicateTextureMapChange(v5, (TextureMapChange *)v8);
        if ( v5->num_texture_map_changes == 255 )
        {
          (**(void (__thiscall ***)(void *, signed int))v9)(v9, 1);
        }
        else
        {
          v10 = v5->lastTMChange;
          if ( v10 )
          {
            *((_DWORD *)v9 + 4) = v10;
            v5->lastTMChange->next = (TextureMapChange *)v9;
          }
          else
          {
            *((_DWORD *)v9 + 4) = 0;
            v5->firstTMChange = (TextureMapChange *)v9;
          }
          *((_DWORD *)v9 + 5) = 0;
          v11 = v5->num_texture_map_changes + 1;
          v5->lastTMChange = (TextureMapChange *)v9;
          v5->num_texture_map_changes = v11;
        }
      }
      v7 = v7->next;
      rhsa = (ObjDesc *)((char *)rhsa + 1);
    }
    while ( (unsigned int)rhsa < v2->num_texture_map_changes );
  }
  v12 = v2->firstAPChange;
  rhsb = 0;
  if ( v2->num_anim_part_changes )
  {
    do
    {
      v13 = operator new(0x14u);
      v14 = v13;
      if ( v13 )
      {
        *(_DWORD *)v13 = &AnimPartChange::vftable;
        *((_DWORD *)v13 + 1) = v12->part_index;
        *((_DWORD *)v13 + 2) = v12->part_id.id;
        *((_DWORD *)v13 + 3) = v12->prev;
        *((_DWORD *)v13 + 4) = v12->next;
        ObjDesc::RemoveDuplicateAnimPartChange(v5, (AnimPartChange *)v13);
        if ( v5->num_anim_part_changes == 255 )
        {
          (**(void (__thiscall ***)(void *, signed int))v14)(v14, 1);
        }
        else
        {
          v15 = v5->lastAPChange;
          if ( v15 )
          {
            *((_DWORD *)v14 + 3) = v15;
            v5->lastAPChange->next = (AnimPartChange *)v14;
          }
          else
          {
            *((_DWORD *)v14 + 3) = 0;
            v5->firstAPChange = (AnimPartChange *)v14;
          }
          *((_DWORD *)v14 + 4) = 0;
          v16 = v5->num_anim_part_changes + 1;
          v5->lastAPChange = (AnimPartChange *)v14;
          v5->num_anim_part_changes = v16;
        }
      }
      v12 = v12->next;
      rhsb = (ObjDesc *)((char *)rhsb + 1);
    }
    while ( (unsigned int)rhsb < v2->num_anim_part_changes );
  }
  return v5;
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);
// 7E5B18: using guessed type int (__thiscall *TextureMapChange::vftable)(void *, char);

//----- (005AC250) --------------------------------------------------------  // acclient.c:470261
ObjDesc *__thiscall ObjDesc::operator=(ObjDesc *this, ObjDesc *rhs)
{
  ObjDesc *v2; // edi@1
  ObjDesc *v3; // ebp@1
  Subpalette *v4; // esi@1
  int i; // ebx@1
  void *v6; // eax@2
  TextureMapChange *v7; // ebx@6
  void *v8; // eax@7
  void *v9; // esi@7
  TextureMapChange *v10; // eax@10
  int v11; // eax@13
  AnimPartChange *v12; // ebx@15
  void *v13; // eax@16
  void *v14; // esi@16
  AnimPartChange *v15; // eax@19
  int v16; // eax@22
  ObjDesc *rhsa; // [sp+14h] [bp+4h]@6
  ObjDesc *rhsb; // [sp+14h] [bp+4h]@15

  v2 = this;
  ObjDesc::Clear(this);
  v3 = rhs;
  v2->paletteID.id = rhs->paletteID.id;
  v4 = rhs->firstSubpal;
  for ( i = 0; i < rhs->num_subpalettes; ++i )
  {
    v6 = operator new(0x18u);
    if ( v6 )
    {
      *(_DWORD *)v6 = &Subpalette::vftable;
      *((_DWORD *)v6 + 1) = v4->subID.id;
      *((_DWORD *)v6 + 2) = v4->offset;
      *((_DWORD *)v6 + 3) = v4->numcolors;
      *((_DWORD *)v6 + 4) = v4->prev;
      *((_DWORD *)v6 + 5) = v4->next;
    }
    else
    {
      v6 = 0;
    }
    ObjDesc::AddSubpalette(v2, (Subpalette *)v6);
    v4 = v4->next;
  }
  v7 = rhs->firstTMChange;
  rhsa = 0;
  if ( v3->num_texture_map_changes > 0 )
  {
    do
    {
      v8 = operator new(0x18u);
      v9 = v8;
      if ( v8 )
      {
        *(_DWORD *)v8 = &TextureMapChange::vftable;
        *((_DWORD *)v8 + 1) = v7->part_index;
        *((_DWORD *)v8 + 2) = v7->old_tex_id.id;
        *((_DWORD *)v8 + 3) = v7->new_tex_id.id;
        *((_DWORD *)v8 + 4) = v7->prev;
        *((_DWORD *)v8 + 5) = v7->next;
        ObjDesc::RemoveDuplicateTextureMapChange(v2, (TextureMapChange *)v8);
        if ( v2->num_texture_map_changes == 255 )
        {
          (**(void (__thiscall ***)(void *, signed int))v9)(v9, 1);
        }
        else
        {
          v10 = v2->lastTMChange;
          if ( v10 )
          {
            *((_DWORD *)v9 + 4) = v10;
            v2->lastTMChange->next = (TextureMapChange *)v9;
          }
          else
          {
            *((_DWORD *)v9 + 4) = 0;
            v2->firstTMChange = (TextureMapChange *)v9;
          }
          *((_DWORD *)v9 + 5) = 0;
          v11 = v2->num_texture_map_changes + 1;
          v2->lastTMChange = (TextureMapChange *)v9;
          v2->num_texture_map_changes = v11;
        }
      }
      v7 = v7->next;
      rhsa = (ObjDesc *)((char *)rhsa + 1);
    }
    while ( (signed int)rhsa < v3->num_texture_map_changes );
  }
  v12 = v3->firstAPChange;
  rhsb = 0;
  if ( v3->num_anim_part_changes > 0 )
  {
    do
    {
      v13 = operator new(0x14u);
      v14 = v13;
      if ( v13 )
      {
        *(_DWORD *)v13 = &AnimPartChange::vftable;
        *((_DWORD *)v13 + 1) = v12->part_index;
        *((_DWORD *)v13 + 2) = v12->part_id.id;
        *((_DWORD *)v13 + 3) = v12->prev;
        *((_DWORD *)v13 + 4) = v12->next;
        ObjDesc::RemoveDuplicateAnimPartChange(v2, (AnimPartChange *)v13);
        if ( v2->num_anim_part_changes == 255 )
        {
          (**(void (__thiscall ***)(void *, signed int))v14)(v14, 1);
        }
        else
        {
          v15 = v2->lastAPChange;
          if ( v15 )
          {
            *((_DWORD *)v14 + 3) = v15;
            v2->lastAPChange->next = (AnimPartChange *)v14;
          }
          else
          {
            *((_DWORD *)v14 + 3) = 0;
            v2->firstAPChange = (AnimPartChange *)v14;
          }
          *((_DWORD *)v14 + 4) = 0;
          v16 = v2->num_anim_part_changes + 1;
          v2->lastAPChange = (AnimPartChange *)v14;
          v2->num_anim_part_changes = v16;
        }
      }
      v12 = v12->next;
      rhsb = (ObjDesc *)((char *)rhsb + 1);
    }
    while ( (signed int)rhsb < v3->num_anim_part_changes );
  }
  return v2;
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);
// 7E5B18: using guessed type int (__thiscall *TextureMapChange::vftable)(void *, char);

//----- (005AC410) --------------------------------------------------------  // acclient.c:470401
void __thiscall ObjDesc::GetSubDataIDs(ObjDesc *this, QualifiedDataIDArray *id_array)
{
  ObjDesc *v2; // ebx@1
  QualifiedDataID *v3; // eax@1
  Subpalette *i; // esi@1
  QualifiedDataID *v5; // eax@2
  TextureMapChange *j; // esi@3
  QualifiedDataID *v7; // eax@4
  QualifiedDataID *v8; // eax@4
  AnimPartChange *k; // esi@5
  QualifiedDataID *v10; // eax@6
  QualifiedDataID v11; // [sp+10h] [bp-10h]@1
  QualifiedDataID v12; // [sp+18h] [bp-8h]@4

  v2 = this;
  QualifiedDataID::QualifiedDataID(&v11, this->paletteID, 0);
  QualifiedDataIDArray::AddQDID(id_array, v3, 0);
  for ( i = v2->firstSubpal; i; i = i->next )
  {
    QualifiedDataID::QualifiedDataID(&v11, i->subID, 0);
    QualifiedDataIDArray::AddQDID(id_array, v5, 8u);
  }
  for ( j = v2->firstTMChange; j; j = j->next )
  {
    QualifiedDataID::QualifiedDataID(&v11, j->old_tex_id, 0);
    QualifiedDataIDArray::AddQDID(id_array, v7, 8u);
    QualifiedDataID::QualifiedDataID(&v12, j->new_tex_id, 0);
    QualifiedDataIDArray::AddQDID(id_array, v8, 8u);
  }
  for ( k = v2->firstAPChange; k; k = k->next )
  {
    QualifiedDataID::QualifiedDataID(&v12, k->part_id, 0);
    QualifiedDataIDArray::AddQDID(id_array, v10, 8u);
  }
}

//----- (005AC4E0) --------------------------------------------------------  // acclient.c:470438
void __thiscall ObjDesc::ObjDesc(ObjDesc *this, ObjDesc *_od)
{
  ObjDesc *v2; // esi@1

  v2 = this;
  WeenieDesc::WeenieDesc((WeenieDesc *)this);
  v2->vfptr = (PackObjVtbl *)&ObjDesc::vftable;
  v2->paletteID.id = _od->paletteID.id;
  v2->firstSubpal = 0;
  v2->lastSubpal = 0;
  v2->num_subpalettes = 0;
  v2->firstTMChange = 0;
  v2->lastTMChange = 0;
  v2->num_texture_map_changes = 0;
  v2->firstAPChange = 0;
  v2->lastAPChange = 0;
  v2->num_anim_part_changes = 0;
  ObjDesc::operator+=(v2, _od);
}
// 7E6028: using guessed type int (__thiscall *ObjDesc::vftable)(void *, char);

//----- (0070E1C0) --------------------------------------------------------  // acclient.c:801087
int sub_70E1C0()
{
  return atexit(nullsub_1537);
}

