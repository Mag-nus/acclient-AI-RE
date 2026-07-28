/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AdminAccountData
   Object     : PORTAL\player\AdminAccountData.obj
   Functions  : 4
   Addresses  : 006B0B30 - 006B0BF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B0B30) --------------------------------------------------------  // acclient.c:713898
void __thiscall AdminAccountData::AdminAccountData(AdminAccountData *this)
{
  AdminAccountData *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AdminAccountData::vftable;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&this->accountName, &name);
  v1->bookieID = 0;
}
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006B0B60) --------------------------------------------------------  // acclient.c:713910
int __thiscall AdminPlayerData::GetPackSize(AdminAccountData *this)
{
  void *pvNull; // [sp+0h] [bp-4h]@1

  pvNull = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->accountName, &pvNull, 0) + 4;
}

//----- (006B0BB0) --------------------------------------------------------  // acclient.c:713931
unsigned int __thiscall AdminAccountData::Pack(AdminAccountData *this, void **addr, unsigned int size)
{
  AdminAccountData *v3; // ebx@1
  char *v4; // esi@1
  unsigned int v5; // ebp@1

  v3 = this;
  v4 = (char *)*addr + size;
  v5 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v5 )
  {
    AC1Legacy::PStringBase<char>::Pack(&v3->accountName, addr, v4 - (_BYTE *)*addr);
    *(_DWORD *)*addr = v3->bookieID;
    *addr = (char *)*addr + 4;
  }
  return v5;
}

//----- (006B0BF0) --------------------------------------------------------  // acclient.c:713950
int __thiscall AdminAccountData::UnPack(AdminAccountData *this, void **addr, unsigned int size)
{
  AdminAccountData *v3; // edi@1

  v3 = this;
  AC1Legacy::PStringBase<char>::UnPack(&this->accountName, addr, size);
  v3->bookieID = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  return 1;
}

