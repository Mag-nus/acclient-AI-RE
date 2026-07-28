/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ItemProfile
   Object     : AC\acshop\ItemProfile.obj
   Functions  : 10
   Addresses  : 005D1750 - 00710490 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D1750) --------------------------------------------------------  // acclient.c:509581
void __thiscall ItemProfile::Clear(ItemProfile *this)
{
  ItemProfile *v1; // esi@1
  PublicWeenieDesc *v2; // ecx@1

  v1 = this;
  v2 = this->pwd;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->pwd = 0;
  }
}

//----- (005D1770) --------------------------------------------------------  // acclient.c:509596
int __thiscall ItemProfile::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@2
  int v4; // edi@3
  int result; // eax@4
  PublicWeenieDesc *v6; // eax@7
  int v7; // eax@8

  v2 = this;
  if ( this == a2 )
    return v2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  v3 = *(_DWORD *)(this + 12);
  if ( !v3 )
  {
    if ( *(_DWORD *)(a2 + 12) )
    {
      v6 = (PublicWeenieDesc *)operator new(0xB0u);
      if ( v6 )
        PublicWeenieDesc::PublicWeenieDesc(v6);
      else
        v7 = 0;
      *(_DWORD *)(v2 + 12) = v7;
      PublicWeenieDesc::operator=(v7, *(_DWORD *)(a2 + 12));
    }
    return v2;
  }
  v4 = *(_DWORD *)(a2 + 12);
  if ( v4 )
  {
    PublicWeenieDesc::operator=(v3, v4);
    result = v2;
  }
  else
  {
    (**(void (__stdcall ***)(_DWORD))v3)(1);
    *(_DWORD *)(v2 + 12) = 0;
    result = v2;
  }
  return result;
}

//----- (005D17F0) --------------------------------------------------------  // acclient.c:509641
BOOL __thiscall ItemProfile::operator==(ItemProfile *this, ItemProfile *rhs)
{
  return this->iid == rhs->iid;
}

//----- (005D1810) --------------------------------------------------------  // acclient.c:509647
void __thiscall ItemProfile::ItemProfile(ItemProfile *this)
{
  this->vfptr = (PackObjVtbl *)&ItemProfile::vftable;
  this->amount = 0;
  this->iid = 0;
  this->pwd = 0;
}
// 7E895C: using guessed type int (__thiscall *ItemProfile::vftable)(void *, char);

//----- (005D1830) --------------------------------------------------------  // acclient.c:509657
void __thiscall ItemProfile::~ItemProfile(ItemProfile *this)
{
  ItemProfile *v1; // esi@1
  PublicWeenieDesc *v2; // ecx@1

  v1 = this;
  v2 = this->pwd;
  v1->vfptr = (PackObjVtbl *)&ItemProfile::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->pwd = 0;
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E895C: using guessed type int (__thiscall *ItemProfile::vftable)(void *, char);

//----- (005D1860) --------------------------------------------------------  // acclient.c:509676
void __thiscall ItemProfile::ItemProfile(ItemProfile *this, ItemProfile *rhs)
{
  this->amount = 0;
  this->iid = 0;
  this->pwd = 0;
  this->vfptr = (PackObjVtbl *)&ItemProfile::vftable;
  ItemProfile::operator=((int)this, (int)rhs);
}
// 7E895C: using guessed type int (__thiscall *ItemProfile::vftable)(void *, char);

//----- (005D1890) --------------------------------------------------------  // acclient.c:509687
unsigned int __thiscall ItemProfile::Pack(ItemProfile *this, void **addr, unsigned int size)
{
  ItemProfile *v3; // esi@1
  PublicWeenieDesc *v4; // ecx@1
  unsigned int v5; // edi@1
  signed int v6; // eax@4
  char *v7; // ecx@6
  PublicWeenieDesc *v8; // ecx@6
  ItemProfile *v10; // [sp+0h] [bp-4h]@1

  v10 = this;
  v3 = this;
  v4 = this->pwd;
  v5 = 8;
  if ( v4 )
  {
    v10 = 0;
    v5 = ((int (__stdcall *)(int *, _DWORD))v4->vfptr->Pack)(&v10, 0) + 8;
  }
  if ( size >= v5 )
  {
    v6 = 0;
    if ( v3->pwd )
      v6 = -1;
    *(_DWORD *)*addr = (v6 << 24) | v3->amount & 0xFFFFFF;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->iid;
    *addr = (char *)*addr + 4;
    v8 = v3->pwd;
    if ( v8 )
      ((void (__stdcall *)(void **, unsigned int))v8->vfptr->Pack)(addr, size);
  }
  return v5;
}

//----- (005D1910) --------------------------------------------------------  // acclient.c:509724
int __thiscall ItemProfile::UnPack(ItemProfile *this, void **addr, unsigned int size)
{
  ItemProfile *v3; // esi@1
  PublicWeenieDesc *v4; // ecx@1
  unsigned int v5; // eax@1
  signed int v7; // ecx@5
  signed int v8; // ecx@7
  PublicWeenieDesc *v9; // ecx@9
  PublicWeenieDesc *v10; // ecx@11
  PublicWeenieDesc *v11; // eax@15
  PublicWeenieDesc *v12; // eax@16
  int v13; // [sp+8h] [bp-9Ch]@2
  OldPublicWeenieDesc junk; // [sp+Ch] [bp-98h]@11

  v3 = this;
  v4 = this->pwd;
  v5 = 8;
  if ( v4 )
  {
    v13 = 0;
    v5 = ((int (__stdcall *)(int *, _DWORD))v4->vfptr->Pack)(&v13, 0) + 8;
  }
  if ( size < v5 )
    return 0;
  v7 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v3->amount = v7 & 0xFFFFFF;
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v7 & 0xFFFFFF )
    v3->amount = v7 & 0xFFFFFF | 0xFF000000;
  v3->iid = *(_DWORD *)*addr;
  v8 = v7 >> 24;
  *addr = (char *)*addr + 4;
  if ( v8 == -1 )
  {
    if ( !v3->pwd )
    {
      v11 = (PublicWeenieDesc *)operator new(0xB0u);
      if ( v11 )
        PublicWeenieDesc::PublicWeenieDesc(v11);
      else
        v12 = 0;
      v3->pwd = v12;
    }
    ((void (__stdcall *)(void **, unsigned int))v3->pwd->vfptr->UnPack)(addr, size);
    return 1;
  }
  if ( v8 != 1 )
  {
    v9 = v3->pwd;
    if ( v9 )
    {
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      v3->pwd = 0;
      return 1;
    }
    return 1;
  }
  OldPublicWeenieDesc::OldPublicWeenieDesc(&junk);
  OldPublicWeenieDesc::UnPack(&junk, addr, size);
  v10 = v3->pwd;
  if ( v10 )
  {
    ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
    v3->pwd = 0;
  }
  OldPublicWeenieDesc::~OldPublicWeenieDesc(&junk);
  return 1;
}

//----- (005D1A50) --------------------------------------------------------  // acclient.c:509794
ItemProfile *__thiscall ItemProfile::scalar_deleting_destructor(ItemProfile *this, unsigned int a2)
{
  ItemProfile *v2; // esi@1
  PublicWeenieDesc *v3; // ecx@1

  v2 = this;
  v3 = this->pwd;
  v2->vfptr = (PackObjVtbl *)&ItemProfile::vftable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->pwd = 0;
  }
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E895C: using guessed type int (__thiscall *ItemProfile::vftable)(void *, char);

//----- (00710490) --------------------------------------------------------  // acclient.c:803555
int sub_710490()
{
  return atexit(nullsub_1845);
}

