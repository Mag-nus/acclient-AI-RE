/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CharacterIdentity
   Object     : PORTAL\character\CharacterIdentity.obj
   Functions  : 5
   Addresses  : 004FE700 - 004FE880 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FE700) --------------------------------------------------------  // acclient.c:298748
void __thiscall CharacterIdentity::CharacterIdentity(CharacterIdentity *this)
{
  CharacterIdentity *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&CharacterIdentity::vftable;
  this->gid_ = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->name_.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->secondsGreyedOut_ = 0;
}
// 7C5F50: using guessed type int (__thiscall *CharacterIdentity::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FE730) --------------------------------------------------------  // acclient.c:298765
int __thiscall CharacterIdentity::pack_size(CharacterIdentity *this)
{
  unsigned int v1; // eax@1
  signed int v2; // ecx@1
  int v3; // edx@3
  int v4; // eax@3
  int v5; // ecx@4
  int v6; // ecx@6
  int result; // eax@7

  v1 = this->name_.m_buffer->m_len - 1;
  v2 = 0;
  if ( v1 >= 0xFFFF )
    v2 = 4;
  v3 = v2 + v1 + 2;
  v4 = ((_BYTE)v2 + (_BYTE)v1 + 2) & 3;
  if ( v4 )
    v5 = 4 - v4;
  else
    v5 = 0;
  v6 = v5 + v3 + 8;
  if ( v6 & 3 )
    result = 4 - (v6 & 3) + v6;
  else
    result = v6;
  return result;
}

//----- (004FE780) --------------------------------------------------------  // acclient.c:298794
int __thiscall CharacterIdentity::Pack(CharacterIdentity *this, void **addr, unsigned int size)
{
  void *v3; // ebp@1
  CharacterIdentity *v4; // edi@1
  unsigned int v5; // eax@1
  AC1Legacy::PStringBase<char> *v6; // ecx@1
  int v7; // eax@1
  signed int v8; // edx@1
  int v9; // ebx@3
  int v10; // eax@3
  int v11; // edx@4
  int v12; // ebx@6
  int v13; // edx@7
  int result; // eax@9

  v3 = *addr;
  v4 = this;
  v5 = this->name_.m_buffer->m_len;
  v6 = &this->name_;
  v7 = v5 - 1;
  v8 = 0;
  if ( (unsigned int)v7 >= 0xFFFF )
    v8 = 4;
  v9 = v8 + v7 + 2;
  v10 = ((_BYTE)v8 + (_BYTE)v7 + 2) & 3;
  if ( v10 )
    v11 = 4 - v10;
  else
    v11 = 0;
  v12 = v11 + v9 + 8;
  if ( v12 & 3 )
    v13 = 4 - (v12 & 3);
  else
    v13 = 0;
  result = v13 + v12;
  if ( size >= v13 + v12 )
  {
    *(_DWORD *)v3 = v4->gid_;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(v6, addr, size - 4);
    *(_DWORD *)*addr = v4->secondsGreyedOut_;
    *addr = (char *)*addr + 4;
    PackObj::ALIGN_PTR(addr);
    result = (_BYTE *)*addr - (_BYTE *)v3;
  }
  return result;
}

//----- (004FE820) --------------------------------------------------------  // acclient.c:298843
int __thiscall CharacterIdentity::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // eax@5

  v2 = this;
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
  return v2;
}

//----- (004FE880) --------------------------------------------------------  // acclient.c:298865
int __thiscall CharacterIdentity::UnPack(CharacterIdentity *this, void **addr, unsigned int size)
{
  void *v3; // ebx@1
  CharacterIdentity *v4; // edi@1
  int result; // eax@2

  v3 = *addr;
  v4 = this;
  this->gid_ = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( AC1Legacy::PStringBase<char>::UnPack(&this->name_, addr, size - 4) )
  {
    v4->secondsGreyedOut_ = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    PackObj::ALIGN_PTR(addr);
    result = 1;
  }
  else
  {
    _printf("CharacterIdentity: Unpack failed for name_");
    *addr = v3;
    result = 0;
  }
  return result;
}

