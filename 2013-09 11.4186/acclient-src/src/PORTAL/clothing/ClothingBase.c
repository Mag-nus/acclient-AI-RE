/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClothingBase
   Object     : PORTAL\clothing\ClothingBase.obj
   Functions  : 11
   Addresses  : 005A8CD0 - 0070D840 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A8CD0) --------------------------------------------------------  // acclient.c:466424
signed int __thiscall ClothingBase::pack_size(ClothingBase *this)
{
  ClothingBase *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ebx@1
  unsigned int v4; // edi@1
  signed int v5; // ebp@1
  void *mem; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->numObjectEffects;
  v3 = 0;
  v4 = 0;
  mem = 0;
  v5 = 4;
  if ( v2 )
  {
    do
    {
      v5 += ((int (__thiscall *)(int, void **, _DWORD))v1->objectEffects[v3].vfptr->Pack)(
              &v1->objectEffects[v3],
              &mem,
              0);
      ++v4;
      ++v3;
    }
    while ( v4 < v1->numObjectEffects );
  }
  return v5;
}

//----- (005A8D20) --------------------------------------------------------  // acclient.c:466456
void __thiscall ClothingBase::ClothingBase(ClothingBase *this)
{
  this->vfptr = (PackObjVtbl *)&ClothingBase::vftable;
  this->numObjectEffects = 0;
  this->objectEffects = 0;
}
// 7E5B2C: using guessed type int (__thiscall *ClothingBase::vftable)(void *, char);

//----- (005A8D40) --------------------------------------------------------  // acclient.c:466465
void __thiscall ClothingBase::~ClothingBase(ClothingBase *this)
{
  ClothingBase *v1; // esi@1
  CloObjectEffect *v2; // ecx@1

  v1 = this;
  v2 = this->objectEffects;
  v1->vfptr = (PackObjVtbl *)&ClothingBase::vftable;
  if ( v2 )
  {
    if ( v2[-1].textureEffects )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      v1->objectEffects = 0;
      v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
      return;
    }
    operator delete[](&v2[-1].textureEffects);
    v1->objectEffects = 0;
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5B2C: using guessed type int (__thiscall *ClothingBase::vftable)(void *, char);

//----- (005A8D90) --------------------------------------------------------  // acclient.c:466491
int __thiscall ClothingBase::operator=(int this, int a2)
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
    v3 = *(_DWORD *)(this + 8);
    v4 = 0;
    if ( v3 )
    {
      if ( *(_DWORD *)(v3 - 4) )
        (**(void (__stdcall ***)(_DWORD))v3)(3);
      else
        operator delete[]((void *)(v3 - 4));
      *(_DWORD *)(v2 + 8) = 0;
    }
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
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
          (void *(__thiscall *)(void *))CloObjectEffect::CloObjectEffect);
      }
      v7 = *(_DWORD *)(v2 + 4);
      *(_DWORD *)(v2 + 8) = v4;
      v8 = 0;
      if ( v7 )
      {
        v9 = 0;
        do
        {
          CloObjectEffect::operator=(v9 + *(_DWORD *)(v2 + 8), v9 + *(_DWORD *)(a2 + 8));
          ++v8;
          v9 += 20;
        }
        while ( v8 < *(_DWORD *)(v2 + 4) );
      }
    }
  }
  return v2;
}

//----- (005A8E40) --------------------------------------------------------  // acclient.c:466550
void *__thiscall CloObjectEffect::vector_deleting_destructor(CloObjectEffect *this, unsigned int a2)
{
  CloObjectEffect *v2; // esi@1
  CloTextureEffect *v3; // eax@2
  char *v4; // ebp@2
  int v5; // ecx@2
  int v6; // eax@2
  CloObjectEffect *v7; // esi@2
  int v8; // edi@3
  void *result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].textureEffects;
    v4 = (char *)&this[-1].textureEffects;
    v5 = 5 * (_DWORD)v3;
    v6 = (int)((char *)&v3[-1].newTexID.id + 3);
    v7 = &v2[4 * v5 / 0x14u];
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        --v7;
        CloObjectEffect::~CloObjectEffect(v7);
        --v8;
      }
      while ( v8 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    CloObjectEffect::~CloObjectEffect(this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (005A8EB0) --------------------------------------------------------  // acclient.c:466595
int __thiscall ClothingBase::ApplyPartAndTextureChanges(ClothingBase *this, ObjDesc *od)
{
  ClothingBase *v2; // ebp@1
  unsigned int v3; // ecx@1
  int v4; // edi@1
  int result; // eax@1
  CloObjectEffect *v6; // ecx@2
  int v7; // esi@2
  int v8; // eax@3
  unsigned int v9; // ebx@3
  int v10; // ecx@4
  unsigned int v11; // edx@4
  unsigned int v12; // ecx@4
  unsigned int i; // [sp+8h] [bp-34h]@1
  int success; // [sp+Ch] [bp-30h]@1
  AnimPartChange apc; // [sp+10h] [bp-2Ch]@1
  TextureMapChange tmc; // [sp+24h] [bp-18h]@1

  v2 = this;
  v3 = this->numObjectEffects;
  v4 = 0;
  apc.part_id.id = stru_8EDA00.id;
  tmc.old_tex_id.id = stru_8EDA00.id;
  tmc.new_tex_id.id = stru_8EDA00.id;
  result = 1;
  apc.vfptr = (PackObjVtbl *)&AnimPartChange::vftable;
  apc.part_index = 0;
  apc.prev = 0;
  apc.next = 0;
  tmc.vfptr = (PackObjVtbl *)&TextureMapChange::vftable;
  tmc.part_index = 0;
  tmc.prev = 0;
  tmc.next = 0;
  success = 1;
  i = 0;
  if ( v3 )
  {
    v6 = v2->objectEffects;
    v7 = 0;
    do
    {
      apc.part_index = v6[v7].partNum;
      apc.part_id.id = v6[v7].objectID.id;
      ObjDesc::AddAnimPartChange(od, &apc);
      v6 = v2->objectEffects;
      v8 = (int)&v6[v7];
      v9 = 0;
      if ( v6[v7].numTextureEffects > 0 )
      {
        do
        {
          v10 = *(_DWORD *)(v8 + 16);
          v11 = *(_DWORD *)(v10 + v4 + 8);
          v12 = *(_DWORD *)(v4 + v10 + 4);
          tmc.part_index = *(_DWORD *)(v8 + 4);
          tmc.old_tex_id.id = v12;
          tmc.new_tex_id.id = v11;
          if ( v12 == stru_8EDA00.id || v11 == stru_8EDA00.id )
            success = 0;
          ObjDesc::AddTextureMapChange(od, &tmc);
          v6 = v2->objectEffects;
          v8 = (int)&v6[v7];
          ++v9;
          v4 += 12;
        }
        while ( v9 < v6[v7].numTextureEffects );
        v4 = 0;
      }
      ++v7;
      ++i;
    }
    while ( i < v2->numObjectEffects );
    result = success;
  }
  return result;
}
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);
// 7E5B18: using guessed type int (__thiscall *TextureMapChange::vftable)(void *, char);

//----- (005A8FC0) --------------------------------------------------------  // acclient.c:466675
signed int __thiscall ClothingBase::Pack(ClothingBase *this, void **addr, unsigned int size)
{
  ClothingBase *v3; // esi@1
  signed int result; // eax@1
  void **v5; // edi@1
  void *v6; // ecx@1
  unsigned int v7; // ebx@2
  int v8; // ebp@3
  unsigned int packed_size; // [sp+8h] [bp-4h]@1
  void **addra; // [sp+10h] [bp+4h]@1

  v3 = this;
  result = ClothingBase::pack_size(this);
  v5 = addr;
  v6 = *addr;
  packed_size = result;
  addra = (void **)((char *)*addr + size);
  if ( size >= result )
  {
    *(_DWORD *)v6 = v3->numObjectEffects;
    *v5 = (char *)*v5 + 4;
    v7 = 0;
    if ( v3->numObjectEffects )
    {
      v8 = 0;
      do
      {
        ((void (__thiscall *)(int, void **, int))v3->objectEffects[v8].vfptr->Pack)(
          &v3->objectEffects[v8],
          v5,
          (char *)addra - (_BYTE *)*v5);
        ++v7;
        ++v8;
      }
      while ( v7 < v3->numObjectEffects );
      result = packed_size;
    }
  }
  return result;
}

//----- (005A9030) --------------------------------------------------------  // acclient.c:466717
int __thiscall ClothingBase::UnPack(ClothingBase *this, void **addr, unsigned int size)
{
  ClothingBase *v3; // esi@1
  int result; // eax@2
  void **v5; // edi@3
  void *v6; // ebp@3
  char *v7; // eax@3
  CloObjectEffect *v8; // ecx@3
  int v9; // ebx@8
  void *v10; // eax@9
  int v11; // ebp@10
  int v12; // eax@10
  unsigned int v13; // ebx@12
  int v14; // ebp@13
  char *end; // [sp+0h] [bp-4h]@3
  void **addra; // [sp+8h] [bp+4h]@3

  v3 = this;
  if ( size >= ClothingBase::pack_size(this) )
  {
    v5 = addr;
    v6 = *addr;
    v7 = (char *)*addr + size;
    v8 = v3->objectEffects;
    addra = (void **)*addr;
    end = v7;
    if ( v8 )
    {
      if ( v8[-1].textureEffects )
        ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(3);
      else
        operator delete[](&v8[-1].textureEffects);
      v3->objectEffects = 0;
    }
    v3->numObjectEffects = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
    v9 = v3->numObjectEffects;
    if ( v9 )
    {
      v10 = operator new[](20 * v9 + 4);
      if ( v10 )
      {
        v11 = (int)((char *)v10 + 4);
        *(_DWORD *)v10 = v9;
        vector_constructor_iterator(
          (char *)v10 + 4,
          0x14u,
          v9,
          (void *(__thiscall *)(void *))CloObjectEffect::CloObjectEffect);
        v12 = v11;
        v6 = addra;
      }
      else
      {
        v12 = 0;
      }
      v3->objectEffects = (CloObjectEffect *)v12;
      v13 = 0;
      if ( v3->numObjectEffects )
      {
        v14 = 0;
        do
        {
          ((void (__thiscall *)(int, void **, int))v3->objectEffects[v14].vfptr->UnPack)(
            &v3->objectEffects[v14],
            v5,
            end - (_BYTE *)*v5);
          ++v13;
          ++v14;
        }
        while ( v13 < v3->numObjectEffects );
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

//----- (005A9130) --------------------------------------------------------  // acclient.c:466809
ClothingBase *__thiscall ClothingBase::vector_deleting_destructor(ClothingBase *this, unsigned int a2)
{
  ClothingBase *v2; // esi@1
  CloObjectEffect *v3; // ecx@1

  v2 = this;
  v3 = this->objectEffects;
  v2->vfptr = (PackObjVtbl *)&ClothingBase::vftable;
  if ( v3 )
  {
    if ( v3[-1].textureEffects )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v3[-1].textureEffects);
    v2->objectEffects = 0;
  }
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5B2C: using guessed type int (__thiscall *ClothingBase::vftable)(void *, char);

//----- (005A9180) --------------------------------------------------------  // acclient.c:466834
void __thiscall ClothingBase::ClothingBase(ClothingBase *this, ClothingBase *rhs)
{
  this->numObjectEffects = 0;
  this->objectEffects = 0;
  this->vfptr = (PackObjVtbl *)&ClothingBase::vftable;
  ClothingBase::operator=((int)this, (int)rhs);
}
// 7E5B2C: using guessed type int (__thiscall *ClothingBase::vftable)(void *, char);

//----- (0070D840) --------------------------------------------------------  // acclient.c:800479
int sub_70D840()
{
  return atexit(nullsub_1457);
}

