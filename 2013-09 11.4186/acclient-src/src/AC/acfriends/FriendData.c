/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FriendData
   Object     : AC\acfriends\FriendData.obj
   Functions  : 7
   Addresses  : 005B9C30 - 005B9E80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B9C30) --------------------------------------------------------  // acclient.c:484639
BOOL __thiscall FriendData::operator==(FriendData *this, FriendData *rhs)
{
  return this->m_id == rhs->m_id && AC1Legacy::PStringBase<char>::operator==(&this->m_name, &rhs->m_name);
}

//----- (005B9C60) --------------------------------------------------------  // acclient.c:484645
int __thiscall FriendData::GetPackSize(FriendData *this)
{
  char *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1
  int v4; // ebx@1
  void *dummy; // [sp+8h] [bp-4h]@1

  v1 = (char *)&this->m_friendOfList.vfptr;
  v2 = (char *)&this->m_friendsList.vfptr;
  dummy = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(&this->m_name, &dummy, 0);
  v4 = (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v1 + 12))(v1, &dummy, 0) + v3;
  return v4 + (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v2 + 12))(v2, &dummy, 0) + 12;
}

//----- (005B9CB0) --------------------------------------------------------  // acclient.c:484662
unsigned int __thiscall FriendData::Pack(FriendData *this, void **addr, unsigned int size)
{
  FriendData *v3; // edi@1
  unsigned int v4; // ebp@1
  char *v5; // ecx@2
  char *v6; // eax@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->m_id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->m_online;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->m_appearOffline;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->m_name, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_friendsList.vfptr->Pack)(
      &v3->m_friendsList.vfptr,
      addr,
      size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_friendOfList.vfptr->Pack)(
      &v3->m_friendOfList.vfptr,
      addr,
      size);
  }
  return v4;
}

//----- (005B9D20) --------------------------------------------------------  // acclient.c:484695
int __thiscall FriendData::UnPack(FriendData *this, void **addr, unsigned int size)
{
  FriendData *v3; // edi@1
  int result; // eax@2
  char *v5; // edx@3
  char *v6; // ecx@3

  v3 = this;
  if ( size >= 0xC )
  {
    this->m_id = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->m_online = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->m_appearOffline = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::UnPack(&v3->m_name, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_friendsList.vfptr->UnPack)(
      &v3->m_friendsList.vfptr,
      addr,
      size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_friendOfList.vfptr->UnPack)(
      &v3->m_friendOfList.vfptr,
      addr,
      size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B9D90) --------------------------------------------------------  // acclient.c:484732
void __thiscall FriendData::FriendData(FriendData *this)
{
  FriendData *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&FriendData::vftable;
  this->m_id = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->m_online = 0;
  v1->m_appearOffline = 0;
  v1->m_friendsList._head = 0;
  v1->m_friendsList._tail = 0;
  v1->m_friendsList._num_elements = 0;
  v1->m_friendsList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_friendsList.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
  v1->m_friendsList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
  v1->m_friendOfList._head = 0;
  v1->m_friendOfList._tail = 0;
  v1->m_friendOfList._num_elements = 0;
  v1->m_friendOfList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_friendOfList.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
  v1->m_friendOfList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A4128: using guessed type int (__thiscall *FriendData::vftable)(void *, char);
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B9E00) --------------------------------------------------------  // acclient.c:484765
int __thiscall FriendData::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    v3 = *(_DWORD *)(this + 8);
    if ( v3 != *(_DWORD *)(a2 + 8) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v2 + 8) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
    AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)(v2 + 20), a2 + 20);
    AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)(v2 + 40), a2 + 40);
  }
  return v2;
}

//----- (005B9E80) --------------------------------------------------------  // acclient.c:484793
void __thiscall FriendData::FriendData(FriendData *this, FriendData *rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&FriendData::vftable;
  this->m_id = 0;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  *(_DWORD *)(v2 + 36) = &PackObj::vftable;
  *(_DWORD *)(v2 + 20) = &PList<unsigned long>::vftable;
  *(_DWORD *)(v2 + 36) = &PList<unsigned long>::vftable;
  *(_DWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  *(_DWORD *)(v2 + 56) = &PackObj::vftable;
  *(_DWORD *)(v2 + 40) = &PList<unsigned long>::vftable;
  *(_DWORD *)(v2 + 56) = &PList<unsigned long>::vftable;
  FriendData::operator=(v2, (int)rhs);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A4128: using guessed type int (__thiscall *FriendData::vftable)(void *, char);
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

