/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClothingData
   Object     : PORTAL\clothing\ClothingData.obj
   Functions  : 24
   Addresses  : 005A82E0 - 0070D830 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A82E0) --------------------------------------------------------  // acclient.c:465529
signed int __thiscall CloObjectEffect::pack_size(CloObjectEffect *this)
{
  CloObjectEffect *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ebx@1
  unsigned int v4; // edi@1
  signed int v5; // ebp@1
  void *mem; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->numTextureEffects;
  v3 = 0;
  v4 = 0;
  mem = 0;
  v5 = 12;
  if ( v2 )
  {
    do
    {
      v5 += ((int (__thiscall *)(int, void **, _DWORD))v1->textureEffects[v3].vfptr->Pack)(
              &v1->textureEffects[v3],
              &mem,
              0);
      ++v4;
      ++v3;
    }
    while ( v4 < v1->numTextureEffects );
  }
  return v5;
}

//----- (005A8330) --------------------------------------------------------  // acclient.c:465561
signed int __thiscall CloPaletteTemplate::pack_size(CloPaletteTemplate *this)
{
  CloPaletteTemplate *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ebx@1
  unsigned int v4; // edi@1
  signed int v5; // ebp@1
  void *mem; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->numSubpalEffects;
  v3 = 0;
  v4 = 0;
  mem = 0;
  v5 = 8;
  if ( v2 )
  {
    do
    {
      v5 += ((int (__thiscall *)(int, void **, _DWORD))v1->subpalEffects[v3].vfptr->Pack)(
              &v1->subpalEffects[v3],
              &mem,
              0);
      ++v4;
      ++v3;
    }
    while ( v4 < v1->numSubpalEffects );
  }
  return v5;
}

//----- (005A8380) --------------------------------------------------------  // acclient.c:465593
void __thiscall CloObjectEffect::CloObjectEffect(CloObjectEffect *this)
{
  this->vfptr = (PackObjVtbl *)&CloObjectEffect::vftable;
  this->partNum = 0;
  this->objectID.id = stru_8ED9F8.id;
  this->numTextureEffects = 0;
  this->textureEffects = 0;
}
// 7E5AC8: using guessed type int (__thiscall *CloObjectEffect::vftable)(void *, char);

//----- (005A83A0) --------------------------------------------------------  // acclient.c:465604
int __thiscall CloTextureEffect::vector_deleting_destructor(CloTextureEffect *this, unsigned int a2)
{
  CloTextureEffect *v2; // esi@1
  unsigned int v3; // ecx@2
  int v4; // eax@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@3
  int result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].newTexID.id;
    v4 = 3 * v3;
    v5 = v3 - 1;
    v6 = (int)&v2[4 * v4 / 0xCu];
    if ( v5 >= 0 )
    {
      v7 = v5 + 1;
      do
      {
        v6 -= 12;
        --v7;
        *(_DWORD *)v6 = &PackObj::vftable;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](&v2[-1].newTexID);
    result = (int)&v2[-1].newTexID;
  }
  else
  {
    this->vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( a2 & 1 )
      operator delete(this);
    result = (int)v2;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005A8400) --------------------------------------------------------  // acclient.c:465648
void __thiscall CloObjectEffect::~CloObjectEffect(CloObjectEffect *this)
{
  CloObjectEffect *v1; // esi@1
  CloTextureEffect *v2; // ecx@1

  v1 = this;
  v2 = this->textureEffects;
  v1->vfptr = (PackObjVtbl *)&CloObjectEffect::vftable;
  if ( v2 )
  {
    if ( v2[-1].newTexID.id )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      v1->textureEffects = 0;
      v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
      return;
    }
    operator delete[](&v2[-1].newTexID);
    v1->textureEffects = 0;
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5AC8: using guessed type int (__thiscall *CloObjectEffect::vftable)(void *, char);

//----- (005A8450) --------------------------------------------------------  // acclient.c:465674
void __thiscall CloTextureEffect::CloTextureEffect(CloTextureEffect *this)
{
  this->vfptr = (PackObjVtbl *)&CloTextureEffect::vftable;
  this->oldTexID.id = stru_8ED9F8.id;
  this->newTexID.id = stru_8ED9F8.id;
}
// 7E5ADC: using guessed type int (__thiscall *CloTextureEffect::vftable)(void *, char);

//----- (005A8470) --------------------------------------------------------  // acclient.c:465683
void __thiscall CloPaletteTemplate::CloPaletteTemplate(CloPaletteTemplate *this)
{
  this->vfptr = (PackObjVtbl *)&CloPaletteTemplate::vftable;
  this->iconID.id = stru_8ED9F8.id;
  this->numSubpalEffects = 0;
  this->subpalEffects = 0;
}
// 7E5AF0: using guessed type int (__thiscall *CloPaletteTemplate::vftable)(void *, char);

//----- (005A8490) --------------------------------------------------------  // acclient.c:465693
void __thiscall CloPaletteTemplate::~CloPaletteTemplate(CloPaletteTemplate *this)
{
  CloPaletteTemplate *v1; // esi@1
  CloSubpalEffect *v2; // ecx@1

  v1 = this;
  v2 = this->subpalEffects;
  v1->vfptr = (PackObjVtbl *)&CloPaletteTemplate::vftable;
  v1->iconID.id = stru_8ED9F8.id;
  if ( v2 )
  {
    if ( v2[-1].palSet.id )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      v1->subpalEffects = 0;
      v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
      return;
    }
    operator delete[](&v2[-1].palSet);
    v1->subpalEffects = 0;
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5AF0: using guessed type int (__thiscall *CloPaletteTemplate::vftable)(void *, char);

//----- (005A84E0) --------------------------------------------------------  // acclient.c:465720
void __thiscall CloSubpalEffect::CloSubpalEffect(CloSubpalEffect *this)
{
  this->vfptr = (PackObjVtbl *)&CloSubpalEffect::vftable;
  this->numRanges = 0;
  this->rangeStart = 0;
  this->rangeLength = 0;
  this->palSet.id = stru_8ED9F8.id;
}
// 7E5B04: using guessed type int (__thiscall *CloSubpalEffect::vftable)(void *, char);

//----- (005A8500) --------------------------------------------------------  // acclient.c:465731
int __thiscall CloSubpalEffect::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@5
  void *v4; // eax@5
  unsigned int v5; // ST00_4@5
  void *v6; // eax@5
  int v7; // ecx@5
  unsigned int v8; // eax@5

  v2 = this;
  if ( *(_DWORD *)(this + 8) )
  {
    operator delete[](*(void **)(this + 8));
    *(_DWORD *)(v2 + 8) = 0;
  }
  if ( *(_DWORD *)(v2 + 12) )
  {
    operator delete[](*(void **)(v2 + 12));
    *(_DWORD *)(v2 + 12) = 0;
  }
  v3 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v2 + 4) = v3;
  v4 = operator new[](4 * v3);
  v5 = 4 * *(_DWORD *)(v2 + 4);
  *(_DWORD *)(v2 + 8) = v4;
  v6 = operator new[](v5);
  v7 = *(_DWORD *)(v2 + 4);
  *(_DWORD *)(v2 + 12) = v6;
  v8 = 0;
  if ( v7 )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4 * v8) = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 4 * v8);
      *(_DWORD *)(*(_DWORD *)(v2 + 12) + 4 * v8) = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 4 * v8);
      ++v8;
    }
    while ( v8 < *(_DWORD *)(v2 + 4) );
  }
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  return v2;
}

//----- (005A8590) --------------------------------------------------------  // acclient.c:465776
int __thiscall CloObjectEffect::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@2
  int v4; // ebx@2
  int v5; // edi@7
  void *v6; // eax@8
  int v7; // eax@10
  unsigned int v8; // edi@10
  int v9; // edx@11
  int v10; // eax@12
  int v11; // ecx@12

  v2 = this;
  if ( this != a2 )
  {
    v3 = *(_DWORD *)(this + 16);
    v4 = 0;
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 - 4) )
        (**(void (__stdcall ***)(_DWORD))v3)(3);
      else
        operator delete[]((void *)(v3 - 4));
      *(_DWORD *)(v2 + 16) = 0;
    }
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
    v5 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 12) = v5;
    if ( (unsigned int)v5 > 0 )
    {
      v6 = operator new[](12 * v5 + 4);
      if ( v6 )
      {
        v4 = (int)((char *)v6 + 4);
        *(_DWORD *)v6 = v5;
        vector_constructor_iterator(
          (char *)v6 + 4,
          0xCu,
          v5,
          (void *(__thiscall *)(void *))CloTextureEffect::CloTextureEffect);
      }
      v7 = *(_DWORD *)(v2 + 12);
      v8 = 0;
      *(_DWORD *)(v2 + 16) = v4;
      if ( v7 )
      {
        v9 = 0;
        do
        {
          v10 = *(_DWORD *)(a2 + 16);
          v11 = v9 + *(_DWORD *)(v2 + 16);
          *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + v9 + 4);
          *(_DWORD *)(v11 + 8) = *(_DWORD *)(v9 + v10 + 8);
          ++v8;
          v9 += 12;
        }
        while ( v8 < *(_DWORD *)(v2 + 12) );
      }
    }
  }
  return v2;
}

//----- (005A8650) --------------------------------------------------------  // acclient.c:465842
signed int __thiscall CloObjectEffect::Pack(CloObjectEffect *this, void **addr, unsigned int size)
{
  CloObjectEffect *v3; // edi@1
  signed int result; // eax@1
  void **v5; // esi@1
  void *v6; // ecx@1
  int v7; // ebp@2
  int v8; // ebx@2
  unsigned int v9; // ebx@2
  int v10; // ebp@3
  unsigned int packed_size; // [sp+10h] [bp-4h]@1
  void **addra; // [sp+18h] [bp+4h]@1

  v3 = this;
  result = CloObjectEffect::pack_size(this);
  v5 = addr;
  v6 = *addr;
  packed_size = result;
  addra = (void **)((char *)*addr + size);
  if ( size >= result )
  {
    *(_DWORD *)v6 = v3->partNum;
    v7 = (int)((char *)*v5 + 4);
    *v5 = (void *)v7;
    *(_DWORD *)v7 = v3->objectID.id;
    v8 = (int)((char *)*v5 + 4);
    *v5 = (void *)v8;
    *(_DWORD *)v8 = v3->numTextureEffects;
    *v5 = (char *)*v5 + 4;
    v9 = 0;
    if ( v3->numTextureEffects )
    {
      v10 = 0;
      do
      {
        ((void (__thiscall *)(int, void **, int))v3->textureEffects[v10].vfptr->Pack)(
          &v3->textureEffects[v10],
          v5,
          (char *)addra - (_BYTE *)*v5);
        ++v9;
        ++v10;
      }
      while ( v9 < v3->numTextureEffects );
      result = packed_size;
    }
  }
  return result;
}

//----- (005A86D0) --------------------------------------------------------  // acclient.c:465892
int __thiscall CloObjectEffect::UnPack(CloObjectEffect *this, void **addr, unsigned int size)
{
  CloObjectEffect *v3; // edi@1
  int result; // eax@2
  void **v5; // esi@3
  void *v6; // ebp@3
  char *v7; // eax@3
  CloTextureEffect *v8; // ecx@3
  int v9; // edx@8
  unsigned int v10; // ecx@8
  int v11; // ebx@8
  void *v12; // eax@9
  int v13; // ebp@10
  int v14; // eax@10
  unsigned int v15; // ebx@12
  int v16; // ebp@13
  char *end; // [sp+0h] [bp-4h]@3
  void **addra; // [sp+8h] [bp+4h]@3

  v3 = this;
  if ( size >= CloObjectEffect::pack_size(this) )
  {
    v5 = addr;
    v6 = *addr;
    v7 = (char *)*addr + size;
    v8 = v3->textureEffects;
    addra = (void **)*addr;
    end = v7;
    if ( v8 )
    {
      if ( v8[-1].newTexID.id )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(3);
      else
        operator delete[](&v8[-1].newTexID);
      v3->textureEffects = 0;
    }
    v3->partNum = *(_DWORD *)*v5;
    v9 = (int)((char *)*v5 + 4);
    *v5 = (void *)v9;
    v10 = *(_DWORD *)v9;
    *v5 = (void *)(v9 + 4);
    v3->objectID.id = v10;
    v3->numTextureEffects = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
    v11 = v3->numTextureEffects;
    if ( v11 )
    {
      v12 = operator new[](12 * v11 + 4);
      if ( v12 )
      {
        v13 = (int)((char *)v12 + 4);
        *(_DWORD *)v12 = v11;
        vector_constructor_iterator(
          (char *)v12 + 4,
          0xCu,
          v11,
          (void *(__thiscall *)(void *))CloTextureEffect::CloTextureEffect);
        v14 = v13;
        v6 = addra;
      }
      else
      {
        v14 = 0;
      }
      v3->textureEffects = (CloTextureEffect *)v14;
      v15 = 0;
      if ( v3->numTextureEffects )
      {
        v16 = 0;
        do
        {
          ((void (__thiscall *)(int, void **, int))v3->textureEffects[v16].vfptr->UnPack)(
            &v3->textureEffects[v16],
            v5,
            end - (_BYTE *)*v5);
          ++v15;
          ++v16;
        }
        while ( v15 < v3->numTextureEffects );
        v6 = addra;
      }
    }
    if ( size >= (_BYTE *)*v5 - (_BYTE *)v6 )
    {
      result = 1;
    }
    else
    {
      *v5 = v6;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A87E0) --------------------------------------------------------  // acclient.c:465992
signed int __thiscall ContentProfile::Pack(CloTextureEffect *this, void **addr, unsigned int size)
{
  char *v3; // edx@2

  if ( size >= 8 )
  {
    *(_DWORD *)*addr = this->oldTexID.id;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->newTexID.id;
    *addr = (char *)*addr + 4;
  }
  return 8;
}

//----- (005A8810) --------------------------------------------------------  // acclient.c:466008
int __thiscall CloTextureEffect::UnPack(CloTextureEffect *this, void **addr, unsigned int size)
{
  int result; // eax@2
  void *v4; // esi@3
  unsigned int v5; // edi@3
  unsigned int v6; // edi@3

  if ( size >= 8 )
  {
    v4 = *addr;
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->oldTexID.id = v5;
    v6 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->newTexID.id = v6;
    if ( size >= (_BYTE *)*addr - (_BYTE *)v4 )
    {
      result = 1;
    }
    else
    {
      *addr = v4;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A8860) --------------------------------------------------------  // acclient.c:466042
CloPaletteTemplate *__thiscall CloPaletteTemplate::vector_deleting_destructor(CloPaletteTemplate *this, unsigned int a2)
{
  CloPaletteTemplate *v2; // esi@1

  v2 = this;
  CloPaletteTemplate::~CloPaletteTemplate(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005A8880) --------------------------------------------------------  // acclient.c:466054
int __thiscall CloPaletteTemplate::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@2
  int v4; // ebx@2
  int v5; // edi@7
  void *v6; // eax@8
  int v7; // eax@10
  unsigned int v8; // ebx@10
  int v9; // edi@11

  v2 = this;
  if ( this != a2 )
  {
    v3 = *(_DWORD *)(this + 12);
    v4 = 0;
    *(_DWORD *)(v2 + 4) = stru_8ED9F8.id;
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 - 4) )
        (**(void (__stdcall ***)(_DWORD))v3)(3);
      else
        operator delete[]((void *)(v3 - 4));
      *(_DWORD *)(v2 + 12) = 0;
    }
    *(_DWORD *)(v2 + 4) = *(_DWORD *)(a2 + 4);
    v5 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v5;
    if ( (unsigned int)v5 > 0 )
    {
      v6 = operator new[](20 * v5 + 4);
      if ( v6 )
      {
        v4 = (int)((char *)v6 + 4);
        *(_DWORD *)v6 = v5;
        vector_constructor_iterator(
          (char *)v6 + 4,
          0x14u,
          v5,
          (void *(__thiscall *)(void *))CloSubpalEffect::CloSubpalEffect);
      }
      v7 = *(_DWORD *)(v2 + 8);
      *(_DWORD *)(v2 + 12) = v4;
      v8 = 0;
      if ( v7 )
      {
        v9 = 0;
        do
        {
          CloSubpalEffect::operator=(v9 + *(_DWORD *)(v2 + 12), v9 + *(_DWORD *)(a2 + 12));
          ++v8;
          v9 += 20;
        }
        while ( v8 < *(_DWORD *)(v2 + 8) );
      }
    }
  }
  return v2;
}

//----- (005A8940) --------------------------------------------------------  // acclient.c:466115
void *__thiscall CloSubpalEffect::vector_deleting_destructor(CloSubpalEffect *this, unsigned int a2)
{
  CloSubpalEffect *v2; // esi@1
  unsigned int v3; // eax@2
  char *v4; // ebx@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // esi@2
  int v8; // ebp@3
  void *v9; // eax@4
  void *result; // eax@11
  unsigned int *v11; // eax@12

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].palSet.id;
    v4 = (char *)&this[-1].palSet;
    v5 = 5 * v3;
    v6 = v3 - 1;
    v7 = (int)&v2[4 * v5 / 0x14u];
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v9 = *(void **)(v7 - 12);
        v7 -= 20;
        *(_DWORD *)v7 = &CloSubpalEffect::vftable;
        if ( v9 )
        {
          operator delete[](v9);
          *(_DWORD *)(v7 + 8) = 0;
        }
        if ( *(_DWORD *)(v7 + 12) )
        {
          operator delete[](*(void **)(v7 + 12));
          *(_DWORD *)(v7 + 12) = 0;
        }
        --v8;
        *(_DWORD *)v7 = &PackObj::vftable;
      }
      while ( v8 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v11 = this->rangeStart;
    this->vfptr = (PackObjVtbl *)&CloSubpalEffect::vftable;
    if ( v11 )
    {
      operator delete[](v11);
      v2->rangeStart = 0;
    }
    if ( v2->rangeLength )
    {
      operator delete[](v2->rangeLength);
      v2->rangeLength = 0;
    }
    v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5B04: using guessed type int (__thiscall *CloSubpalEffect::vftable)(void *, char);

//----- (005A8A00) --------------------------------------------------------  // acclient.c:466188
signed int __thiscall CloPaletteTemplate::Pack(CloPaletteTemplate *this, void **addr, unsigned int size)
{
  CloPaletteTemplate *v3; // edi@1
  signed int result; // eax@1
  char *v5; // ebx@2
  unsigned int v6; // ebx@2
  int v7; // ebp@3
  unsigned int psize; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = CloPaletteTemplate::pack_size(this);
  psize = result;
  if ( size >= result )
  {
    sizea = (unsigned int)((char *)*addr + size);
    *(_DWORD *)*addr = v3->iconID.id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->numSubpalEffects;
    *addr = (char *)*addr + 4;
    v6 = 0;
    if ( v3->numSubpalEffects )
    {
      v7 = 0;
      do
      {
        ((void (__thiscall *)(int, void **, int))v3->subpalEffects[v7].vfptr->Pack)(
          &v3->subpalEffects[v7],
          addr,
          sizea - (_DWORD)*addr);
        ++v6;
        ++v7;
      }
      while ( v6 < v3->numSubpalEffects );
      result = psize;
    }
  }
  return result;
}

//----- (005A8A70) --------------------------------------------------------  // acclient.c:466230
int __thiscall CloPaletteTemplate::UnPack(CloPaletteTemplate *this, void **addr, unsigned int size)
{
  CloPaletteTemplate *v3; // esi@1
  int result; // eax@2
  void **v5; // edi@3
  CloSubpalEffect *v6; // ecx@3
  int v7; // ebp@3
  unsigned int v8; // ecx@8
  int v9; // ebx@8
  void *v10; // eax@9
  unsigned int v11; // eax@11
  unsigned int v12; // ebx@11
  int v13; // ebp@12
  void *start; // [sp+8h] [bp-4h]@3
  void **addra; // [sp+10h] [bp+4h]@3

  v3 = this;
  if ( size >= CloPaletteTemplate::pack_size(this) )
  {
    v5 = addr;
    start = *addr;
    v6 = v3->subpalEffects;
    addra = (void **)((char *)*addr + size);
    v7 = 0;
    v3->iconID.id = stru_8ED9F8.id;
    if ( v6 )
    {
      if ( v6[-1].palSet.id )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(3);
      else
        operator delete[](&v6[-1].palSet);
      v3->subpalEffects = 0;
    }
    v8 = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
    v3->iconID.id = v8;
    v3->numSubpalEffects = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
    v9 = v3->numSubpalEffects;
    if ( (unsigned int)v9 > 0 )
    {
      v10 = operator new[](20 * v9 + 4);
      if ( v10 )
      {
        v7 = (int)((char *)v10 + 4);
        *(_DWORD *)v10 = v9;
        vector_constructor_iterator(
          (char *)v10 + 4,
          0x14u,
          v9,
          (void *(__thiscall *)(void *))CloSubpalEffect::CloSubpalEffect);
      }
      v11 = v3->numSubpalEffects;
      v12 = 0;
      v3->subpalEffects = (CloSubpalEffect *)v7;
      if ( v11 )
      {
        v13 = 0;
        do
        {
          ((void (__thiscall *)(int, void **, int))v3->subpalEffects[v13].vfptr->UnPack)(
            &v3->subpalEffects[v13],
            v5,
            (char *)addra - (_BYTE *)*v5);
          ++v12;
          ++v13;
        }
        while ( v12 < v3->numSubpalEffects );
      }
    }
    if ( size >= (_BYTE *)*v5 - (_BYTE *)start )
    {
      result = 1;
    }
    else
    {
      *v5 = start;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A8B70) --------------------------------------------------------  // acclient.c:466318
unsigned int __thiscall CloSubpalEffect::Pack(CloSubpalEffect *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // esi@2
  char *v6; // edi@2
  signed int i; // esi@2
  char *v8; // ebx@3

  v3 = this->numRanges;
  result = 8 * v3 + 8;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = v5;
    for ( i = 0; i < (signed int)this->numRanges; ++i )
    {
      *(_DWORD *)v6 = this->rangeStart[i];
      v8 = (char *)*addr + 4;
      *addr = v8;
      *(_DWORD *)v8 = this->rangeLength[i];
      v6 = (char *)*addr + 4;
      *addr = v6;
    }
    *(_DWORD *)v6 = this->palSet.id;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (005A8BE0) --------------------------------------------------------  // acclient.c:466351
int __thiscall CloSubpalEffect::UnPack(CloSubpalEffect *this, void **addr, unsigned int size)
{
  CloSubpalEffect *v3; // edi@1
  int result; // eax@2
  void *v5; // eax@3
  void *v6; // ebx@3
  void *v7; // eax@3
  unsigned int v8; // ST00_4@3
  void *v9; // eax@3
  unsigned int v10; // ecx@3
  signed int v11; // eax@3
  char *v12; // edx@4
  unsigned int v13; // ecx@5

  v3 = this;
  if ( size >= 8 * this->numRanges + 8 )
  {
    v5 = *addr;
    this->numRanges = *(_DWORD *)*addr;
    v6 = v5;
    *addr = (char *)*addr + 4;
    v7 = operator new[](4 * this->numRanges);
    v8 = 4 * v3->numRanges;
    v3->rangeStart = (unsigned int *)v7;
    v9 = operator new[](v8);
    v10 = v3->numRanges;
    v3->rangeLength = (unsigned int *)v9;
    v11 = 0;
    if ( (signed int)v10 > 0 )
    {
      do
      {
        v3->rangeStart[v11] = *(_DWORD *)*addr;
        v12 = (char *)*addr + 4;
        *addr = v12;
        v3->rangeLength[v11] = *(_DWORD *)v12;
        *addr = (char *)*addr + 4;
        ++v11;
      }
      while ( v11 < (signed int)v3->numRanges );
    }
    v13 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3->palSet.id = v13;
    if ( size >= (_BYTE *)*addr - (_BYTE *)v6 )
    {
      result = 1;
    }
    else
    {
      *addr = v6;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A8CA0) --------------------------------------------------------  // acclient.c:466413
void __thiscall CloPaletteTemplate::CloPaletteTemplate(CloPaletteTemplate *this, CloPaletteTemplate *rhs)
{
  this->vfptr = (PackObjVtbl *)&CloPaletteTemplate::vftable;
  this->iconID.id = stru_8ED9F8.id;
  this->numSubpalEffects = 0;
  this->subpalEffects = 0;
  CloPaletteTemplate::operator=((int)this, (int)rhs);
}
// 7E5AF0: using guessed type int (__thiscall *CloPaletteTemplate::vftable)(void *, char);

//----- (0070D830) --------------------------------------------------------  // acclient.c:800473
int sub_70D830()
{
  return atexit(nullsub_1531);
}

