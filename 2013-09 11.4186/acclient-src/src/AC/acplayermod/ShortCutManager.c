/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ShortCutManager
   Object     : AC\acplayermod\ShortCutManager.obj
   Functions  : 8
   Addresses  : 005D5660 - 005D5880 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D5660) --------------------------------------------------------  // acclient.c:514029
void __thiscall ShortCutManager::Destroy(ShortCutManager *this)
{
  char *v1; // esi@1
  signed int v2; // edi@1

  v1 = (char *)this->shortCuts_;
  v2 = 18;
  do
  {
    if ( *(_DWORD *)v1 )
    {
      (***(void (__stdcall ****)(_DWORD))v1)(1);
      *(_DWORD *)v1 = 0;
    }
    v1 += 4;
    --v2;
  }
  while ( v2 );
}

//----- (005D5690) --------------------------------------------------------  // acclient.c:514050
void __thiscall ShortCutManager::RemoveShortCut(ShortCutManager *this, const int index)
{
  ShortCutManager *v2; // edi@1
  ShortCutData *v3; // ecx@3

  v2 = this;
  if ( index >= 0 && index < 18 )
  {
    v3 = this->shortCuts_[index];
    if ( v3 )
    {
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      v2->shortCuts_[index] = 0;
    }
  }
}

//----- (005D56C0) --------------------------------------------------------  // acclient.c:514068
signed int __thiscall ShortCutManager::pack_size(ShortCutManager *this)
{
  signed int v1; // edi@1
  char *v2; // esi@1
  signed int v3; // ebx@1
  void *dummy; // [sp+0h] [bp-4h]@1

  v1 = 4;
  dummy = 0;
  v2 = (char *)this->shortCuts_;
  v3 = 18;
  do
  {
    if ( *(_DWORD *)v2 )
      v1 += (*(int (__stdcall **)(void **, _DWORD))(**(_DWORD **)v2 + 12))(&dummy, 0);
    v2 += 4;
    --v3;
  }
  while ( v3 );
  return v1;
}

//----- (005D5710) --------------------------------------------------------  // acclient.c:514091
signed int __thiscall ShortCutManager::Pack(ShortCutManager *this, void **addr, unsigned int size)
{
  ShortCutManager *v3; // edi@1
  signed int result; // eax@1
  void **v5; // esi@2
  void *v6; // ebp@2
  int v7; // ebx@2
  int v8; // edi@2
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  void **addra; // [sp+10h] [bp+4h]@2

  v3 = this;
  result = ShortCutManager::pack_size(this);
  retVal = result;
  if ( size >= result )
  {
    v5 = addr;
    v6 = *addr;
    v7 = 0;
    *addr = (char *)*addr + 4;
    v8 = (int)v3->shortCuts_;
    addra = (void **)18;
    do
    {
      if ( *(_DWORD *)v8 )
      {
        (*(void (__stdcall **)(void **, unsigned int))(**(_DWORD **)v8 + 12))(v5, size);
        result = retVal;
        ++v7;
      }
      v8 += 4;
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
    *(_DWORD *)v6 = v7;
  }
  return result;
}

//----- (005D5770) --------------------------------------------------------  // acclient.c:514131
void __thiscall ShortCutManager::ShortCutManager(ShortCutManager *this)
{
  this->vfptr = (PackObjVtbl *)&ShortCutManager::vftable;
  memset(this->shortCuts_, 0, sizeof(this->shortCuts_));
}
// 7E8A90: using guessed type int (__thiscall *ShortCutManager::vftable)(void *, char);

//----- (005D5790) --------------------------------------------------------  // acclient.c:514139
int __thiscall ShortCutManager::AddShortCut(ShortCutManager *this, ShortCutData *scData)
{
  int v2; // edi@1
  ShortCutManager *v3; // ebx@1
  ShortCutData *v4; // eax@3
  void *v5; // eax@4
  int result; // eax@5

  v2 = scData->index_;
  v3 = this;
  if ( v2 < 0 || v2 >= 18 )
  {
    result = 0;
  }
  else
  {
    v4 = this->shortCuts_[v2];
    if ( v4 )
    {
      v4->index_ = v2;
      v4->objectID_ = scData->objectID_;
      v4->spellID_ = scData->spellID_;
      result = 1;
    }
    else
    {
      v5 = operator new(0x10u);
      if ( v5 )
      {
        *(_DWORD *)v5 = &CShortCutData::vftable;
        *((_DWORD *)v5 + 1) = scData->index_;
        *((_DWORD *)v5 + 2) = scData->objectID_;
        *((_DWORD *)v5 + 3) = scData->spellID_;
        v3->shortCuts_[v2] = (ShortCutData *)v5;
        result = 1;
      }
      else
      {
        v3->shortCuts_[v2] = 0;
        result = 1;
      }
    }
  }
  return result;
}
// 7E8A7C: using guessed type int (__thiscall *CShortCutData::vftable)(void *, char);

//----- (005D5820) --------------------------------------------------------  // acclient.c:514187
int __thiscall ShortCutManager::UnPack(ShortCutManager *this, void **addr, unsigned int size)
{
  ShortCutManager *v3; // esi@1
  int v4; // ebx@1
  ShortCutData scData; // [sp+Ch] [bp-10h]@1

  v3 = this;
  ShortCutManager::Destroy(this);
  v4 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  ShortCutData::ShortCutData(&scData);
  if ( v4 > 0 )
  {
    do
    {
      StatMod::UnPack(&scData, addr, size);
      ShortCutManager::AddShortCut(v3, &scData);
      --v4;
    }
    while ( v4 );
  }
  return 1;
}

//----- (005D5880) --------------------------------------------------------  // acclient.c:514212
ShortCutManager *__thiscall ShortCutManager::scalar_deleting_destructor(ShortCutManager *this, unsigned int a2)
{
  ShortCutManager *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&ShortCutManager::vftable;
  ShortCutManager::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8A90: using guessed type int (__thiscall *ShortCutManager::vftable)(void *, char);

