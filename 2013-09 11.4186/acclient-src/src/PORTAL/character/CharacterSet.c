/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CharacterSet
   Object     : PORTAL\character\CharacterSet.obj
   Functions  : 15
   Addresses  : 004FDE50 - 004FE570 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FDE50) --------------------------------------------------------  // acclient.c:298073
void __thiscall AC1Legacy::SmartArray<CharacterIdentity>::Reset(AC1Legacy::SmartArray<CharacterIdentity> *this)
{
  AC1Legacy::SmartArray<CharacterIdentity> *v1; // esi@1
  CharacterIdentity *v2; // ecx@1

  v1 = this;
  v2 = this->m_data;
  v1->m_num = 0;
  v1->m_size = 0;
  if ( v2 )
  {
    if ( v2[-1].secondsGreyedOut_ )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      v1->m_data = 0;
      return;
    }
    operator delete[](&v2[-1].secondsGreyedOut_);
  }
  v1->m_data = 0;
}

//----- (004FDE90) --------------------------------------------------------  // acclient.c:298096
int __thiscall AC1Legacy::SmartArray<CharacterIdentity>::RemoveOrderedByIndex(AC1Legacy::SmartArray<CharacterIdentity> *this, unsigned int index)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  CharacterIdentity *v4; // edx@2
  int v5; // ecx@2
  int v6; // esi@2
  int v7; // edi@3
  int result; // eax@4

  v2 = this->m_num;
  if ( index >= v2 )
  {
    result = 0;
  }
  else
  {
    v3 = v2 - 1;
    this->m_num = v3;
    v4 = this->m_data;
    v5 = (int)&this->m_data[index];
    v6 = (int)&v4[v3];
    if ( v5 < (unsigned int)v6 )
    {
      do
      {
        v7 = v5 + 16;
        CharacterIdentity::operator=(v5, v5 + 16);
        v5 = v7;
      }
      while ( v7 < (unsigned int)v6 );
    }
    result = 1;
  }
  return result;
}

//----- (004FDEE0) --------------------------------------------------------  // acclient.c:298134
void __thiscall CharacterSet::ClearIdentity(CharacterSet *this, int slot)
{
  if ( slot >= 0 && slot < this->set_.m_num )
    AC1Legacy::SmartArray<CharacterIdentity>::RemoveOrderedByIndex(&this->set_, slot);
}

//----- (004FDF00) --------------------------------------------------------  // acclient.c:298141
char *__thiscall CharacterSet::GetName(CharacterSet *this, int index)
{
  CharacterIdentity *v2; // eax@2
  char *result; // eax@4

  if ( index < this->set_.m_num && (v2 = &this->set_.m_data[index], v2->gid_) && v2 )
    result = v2->name_.m_buffer->m_data;
  else
    result = 0;
  return result;
}

//----- (004FDF30) --------------------------------------------------------  // acclient.c:298154
unsigned int __thiscall CharacterSet::GetGID(CharacterSet *this, int slot)
{
  CharacterIdentity *v2; // eax@2
  unsigned int result; // eax@4

  if ( slot < this->set_.m_num && (v2 = &this->set_.m_data[slot], v2->gid_) && v2 )
    result = v2->gid_;
  else
    result = 0;
  return result;
}

//----- (004FDF60) --------------------------------------------------------  // acclient.c:298167
unsigned int __thiscall CharacterSet::GetSlot(CharacterSet *this, unsigned int i_iidAvatar)
{
  unsigned int v2; // edx@1
  unsigned int result; // eax@1
  CharacterIdentity *v4; // esi@2
  int v5; // ecx@2

  v2 = this->set_.m_num;
  result = 0;
  if ( !v2 )
    goto LABEL_10;
  v4 = this->set_.m_data;
  v5 = (int)&v4->gid_;
  while ( *(_DWORD *)v5 != i_iidAvatar )
  {
    ++result;
    v5 += 16;
    if ( result >= v2 )
      return -1;
  }
  if ( !v4[result].gid_ )
LABEL_10:
    result = -1;
  return result;
}

//----- (004FDFA0) --------------------------------------------------------  // acclient.c:298194
unsigned int __thiscall CharacterSet::GetGreyedOutFor(CharacterSet *this, int slot)
{
  int v2; // edx@2
  CharacterIdentity *v3; // eax@5
  unsigned int result; // eax@6

  if ( slot >= 0
    && ((v2 = this->numAllowedCharacters_, slot < v2) || v2 <= 0)
    && slot < this->set_.m_num
    && (v3 = &this->set_.m_data[slot], v3->gid_) )
    result = v3->secondsGreyedOut_;
  else
    result = 0;
  return result;
}

//----- (004FDFE0) --------------------------------------------------------  // acclient.c:298211
int __thiscall AC1Legacy::SmartArray<CharacterIdentity>::grow(AC1Legacy::SmartArray<CharacterIdentity> *this, unsigned int _size)
{
  AC1Legacy::SmartArray<CharacterIdentity> *v2; // esi@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // ebp@6
  unsigned int v7; // ebx@8
  int v8; // edi@9
  CharacterIdentity *v9; // ecx@12

  v2 = this;
  v3 = _size;
  if ( _size >= this->m_num )
  {
    if ( _size <= this->m_size )
      return 1;
    if ( !_size )
    {
      AC1Legacy::SmartArray<CharacterIdentity>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * _size + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = _size;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x10u,
        _size,
        (void *(__thiscall *)(void *))CharacterIdentity::CharacterIdentity);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = 0;
          if ( v2->m_num )
          {
            v8 = 0;
            do
            {
              CharacterIdentity::operator=(v8 * 16 + v6, (int)&v2->m_data[v8]);
              ++v7;
              ++v8;
            }
            while ( v7 < v2->m_num );
            v3 = _size;
          }
          v9 = v2->m_data;
          if ( v2->m_data )
          {
            if ( v9[-1].secondsGreyedOut_ )
            {
              ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(3);
              v2->m_size = v3;
              v2->m_data = (CharacterIdentity *)v6;
              return 1;
            }
            operator delete[](&v9[-1].secondsGreyedOut_);
          }
        }
        v2->m_data = (CharacterIdentity *)v6;
        v2->m_size = v3;
        return 1;
      }
    }
  }
  return 0;
}

//----- (004FE0C0) --------------------------------------------------------  // acclient.c:298282
void __thiscall CharacterIdentity::~CharacterIdentity(CharacterIdentity *this)
{
  CharacterIdentity *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1

  v1 = this;
  v2 = this->name_.m_buffer;
  this->vfptr = (PackObjVtbl *)&CharacterIdentity::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5F50: using guessed type int (__thiscall *CharacterIdentity::vftable)(void *, char);

//----- (004FE0F0) --------------------------------------------------------  // acclient.c:298298
void *__thiscall CharacterIdentity::vector_deleting_destructor(CharacterIdentity *this, unsigned int a2)
{
  char v2; // bl@1
  CharacterIdentity *v3; // edi@1
  unsigned int v4; // eax@2
  char *v5; // ebp@2
  CharacterIdentity *v6; // esi@2
  int v7; // eax@2
  int v8; // ebx@3
  AC1Legacy::PSRefBuffer<char> *v9; // edi@4
  void *result; // eax@11
  AC1Legacy::PSRefBuffer<char> *v11; // esi@12
  char *v12; // [sp+4h] [bp-4h]@2

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1].secondsGreyedOut_;
    v5 = (char *)&this[-1].secondsGreyedOut_;
    v6 = &this[v4];
    v7 = v4 - 1;
    v12 = (char *)&this[-1].secondsGreyedOut_;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        v9 = v6[-1].name_.m_buffer;
        --v6;
        v6->vfptr = (PackObjVtbl *)&CharacterIdentity::vftable;
        if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) && v9 )
          v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
        --v8;
        v6->vfptr = (PackObjVtbl *)&PackObj::vftable;
      }
      while ( v8 );
      v5 = v12;
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    v11 = this->name_.m_buffer;
    this->vfptr = (PackObjVtbl *)&CharacterIdentity::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&v11->m_cRef) && v11 )
      v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
    v3->vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5F50: using guessed type int (__thiscall *CharacterIdentity::vftable)(void *, char);

//----- (004FE1B0) --------------------------------------------------------  // acclient.c:298359
int __thiscall CharacterSet::pack_size(CharacterSet *this)
{
  CharacterSet *v1; // esi@1
  signed int v2; // ebx@1
  signed int v3; // ebp@1
  int v4; // edi@2
  int v5; // ecx@3
  int v6; // ebp@6
  signed int v7; // ebx@6
  int v8; // edi@7
  CharacterIdentity *v9; // ecx@8
  unsigned int v10; // eax@8
  CharacterIdentity *v11; // ecx@8
  int v12; // ebp@11
  int v13; // eax@11
  signed int v14; // ecx@11
  int v15; // edx@13
  int v16; // eax@13
  int result; // eax@14

  v1 = this;
  v2 = 0;
  v3 = 8;
  if ( (signed int)this->set_.m_num > 0 )
  {
    v4 = 0;
    do
    {
      v5 = (int)&v1->set_.m_data[v4];
      if ( *(_DWORD *)(v5 + 4) )
        v3 += CharacterIdentity::pack_size((CharacterIdentity *)v5);
      ++v2;
      ++v4;
    }
    while ( v2 < (signed int)v1->set_.m_num );
  }
  v6 = v3 + 4;
  v7 = 0;
  if ( (signed int)v1->delSet_.m_num > 0 )
  {
    v8 = 0;
    do
    {
      v9 = v1->delSet_.m_data;
      v10 = v9[v8].gid_;
      v11 = &v9[v8];
      if ( v10 )
        v6 += CharacterIdentity::pack_size(v11);
      ++v7;
      ++v8;
    }
    while ( v7 < (signed int)v1->delSet_.m_num );
  }
  v12 = v6 + 4;
  v13 = v1->account_.m_buffer->m_len - 1;
  v14 = 0;
  if ( (unsigned int)v13 >= 0xFFFF )
    v14 = 4;
  v15 = v14 + v13 + 2;
  v16 = ((_BYTE)v14 + (_BYTE)v13 + 2) & 3;
  if ( v16 )
    result = v15 + 4 - v16 + v12 + 8;
  else
    result = v15 + v12 + 8;
  return result;
}

//----- (004FE260) --------------------------------------------------------  // acclient.c:298427
int __thiscall CharacterSet::Pack(CharacterSet *this, void **addr, unsigned int size)
{
  CharacterSet *v3; // edi@1
  int result; // eax@1
  unsigned int v5; // edx@1
  unsigned int v6; // eax@2
  char *v7; // ebx@2
  signed int v8; // ebx@2
  int v9; // ebp@3
  int v10; // ecx@4
  signed int v11; // ebp@7
  int v12; // ebx@8
  CharacterIdentity *v13; // ecx@9
  unsigned int v14; // eax@9
  int v15; // ecx@9
  char *v16; // ecx@12
  unsigned int retVal; // [sp+10h] [bp-4h]@1

  v3 = this;
  result = CharacterSet::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    v6 = v3->set_.m_num;
    *(_DWORD *)*addr = v3->status_;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v6;
    *addr = (char *)*addr + 4;
    v8 = 0;
    if ( (signed int)v3->set_.m_num > 0 )
    {
      v9 = 0;
      do
      {
        v10 = (int)&v3->set_.m_data[v9];
        if ( *(_DWORD *)(v10 + 4) )
        {
          (*(void (__stdcall **)(void **, unsigned int))(*(_DWORD *)v10 + 12))(addr, v5);
          v5 = size;
        }
        ++v8;
        ++v9;
      }
      while ( v8 < (signed int)v3->set_.m_num );
    }
    *(_DWORD *)*addr = v3->delSet_.m_num;
    *addr = (char *)*addr + 4;
    v11 = 0;
    if ( (signed int)v3->delSet_.m_num > 0 )
    {
      v12 = 0;
      do
      {
        v13 = v3->delSet_.m_data;
        v14 = v13[v12].gid_;
        v15 = (int)&v13[v12];
        if ( v14 )
        {
          (*(void (__stdcall **)(void **, unsigned int))(*(_DWORD *)v15 + 12))(addr, v5);
          v5 = size;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < (signed int)v3->delSet_.m_num );
    }
    *(_DWORD *)*addr = v3->numAllowedCharacters_;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&v3->account_.m_buffer, addr, v5);
    *(_DWORD *)*addr = v3->m_fUseTurbineChat;
    v16 = (char *)*addr + 4;
    *addr = v16;
    *(_DWORD *)v16 = v3->m_fHasThroneofDestiny;
    *addr = (char *)*addr + 4;
    result = retVal;
  }
  return result;
}

//----- (004FE340) --------------------------------------------------------  // acclient.c:298509
int __thiscall CharacterSet::UnPack(CharacterSet *this, void **addr, unsigned int size)
{
  CharacterSet *v3; // ebx@1
  char *v4; // ecx@1
  int v5; // ebp@1
  CharacterIdentity *v6; // ecx@1
  int v7; // edi@1
  unsigned int v8; // eax@6
  unsigned int v9; // eax@8
  int v10; // ebp@13
  int v11; // edi@13
  CharacterIdentity *v12; // ecx@13
  unsigned int v13; // eax@18
  unsigned int v14; // eax@20
  char *v15; // ebp@25
  AC1Legacy::PSRefBuffer<char> *v16; // eax@25
  AC1Legacy::PSRefBuffer<char> *v17; // esi@25
  CharacterIdentity id; // [sp+10h] [bp-10h]@1

  v3 = this;
  this->status_ = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  v5 = *(_DWORD *)v4;
  *addr = v4 + 4;
  CharacterIdentity::CharacterIdentity(&id);
  v6 = v3->set_.m_data;
  v7 = (int)&v3->set_;
  *(_DWORD *)(v7 + 8) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  if ( v6 )
  {
    if ( v6[-1].secondsGreyedOut_ )
      ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v6[-1].secondsGreyedOut_);
  }
  *(_DWORD *)v7 = 0;
  if ( v5 > 0 )
  {
    do
    {
      CharacterIdentity::UnPack(&id, addr, size);
      v8 = v3->set_.m_size;
      if ( v3->set_.m_num < v8
        || (!v8 ? (v9 = 8) : (v9 = 2 * v8), AC1Legacy::SmartArray<CharacterIdentity>::grow(&v3->set_, v9)) )
        CharacterIdentity::operator=(*(_DWORD *)v7 + 16 * v3->set_.m_num++, (int)&id);
      --v5;
    }
    while ( v5 );
  }
  v10 = *(_DWORD *)*addr;
  v11 = (int)&v3->delSet_;
  *addr = (char *)*addr + 4;
  v12 = v3->delSet_.m_data;
  *(_DWORD *)(v11 + 8) = 0;
  *(_DWORD *)(v11 + 4) = 0;
  if ( v12 )
  {
    if ( v12[-1].secondsGreyedOut_ )
      ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v12[-1].secondsGreyedOut_);
  }
  *(_DWORD *)v11 = 0;
  if ( v10 > 0 )
  {
    do
    {
      CharacterIdentity::UnPack(&id, addr, size);
      v13 = v3->delSet_.m_size;
      if ( v3->delSet_.m_num < v13
        || (!v13 ? (v14 = 8) : (v14 = 2 * v13), AC1Legacy::SmartArray<CharacterIdentity>::grow(&v3->delSet_, v14)) )
        CharacterIdentity::operator=(*(_DWORD *)v11 + 16 * v3->delSet_.m_num++, (int)&id);
      --v10;
    }
    while ( v10 );
  }
  v3->numAllowedCharacters_ = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&v3->account_.m_buffer, addr, size);
  v3->m_fUseTurbineChat = *(_DWORD *)*addr;
  v15 = (char *)*addr + 4;
  *addr = v15;
  v16 = id.name_.m_buffer;
  v3->m_fHasThroneofDestiny = *(_DWORD *)v15;
  *addr = (char *)*addr + 4;
  v17 = v16;
  id.vfptr = (PackObjVtbl *)&CharacterIdentity::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v16->m_cRef) && v17 )
    v17->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v17, 1u);
  return 1;
}
// 7C5F50: using guessed type int (__thiscall *CharacterIdentity::vftable)(void *, char);

//----- (004FE4F0) --------------------------------------------------------  // acclient.c:298605
int __thiscall CharacterSet::AddIdentity(CharacterSet *this, CharacterIdentity *toAdd)
{
  unsigned int v2; // esi@1
  signed int v3; // edx@1
  char *v4; // eax@2
  unsigned int v5; // eax@5
  char *v6; // esi@5
  unsigned int v7; // eax@7
  int result; // eax@8

  v2 = this->set_.m_num;
  v3 = 0;
  if ( (signed int)v2 <= 0 )
  {
LABEL_5:
    v5 = this->set_.m_size;
    v6 = (char *)&this->set_;
    if ( this->set_.m_num < v5
      || (!v5 ? (v7 = 8) : (v7 = 2 * v5), AC1Legacy::SmartArray<CharacterIdentity>::grow(&this->set_, v7)) )
      CharacterIdentity::operator=(*(_DWORD *)v6 + 16 * (*((_DWORD *)v6 + 2))++, (int)toAdd);
    result = 1;
  }
  else
  {
    v4 = (char *)&this->set_.m_data->gid_;
    while ( *(_DWORD *)v4 != toAdd->gid_ )
    {
      ++v3;
      v4 += 16;
      if ( v3 >= (signed int)v2 )
        goto LABEL_5;
    }
    result = 0;
  }
  return result;
}

//----- (004FE570) --------------------------------------------------------  // acclient.c:298643
int __thiscall CharacterSet::operator=(int this, int a2)
{
  int v2; // edi@1
  int v3; // ebp@1
  int v4; // ecx@2
  int v5; // esi@2
  int v6; // ebx@6
  int v7; // ecx@6
  unsigned int v8; // eax@12
  int v9; // ebp@12
  unsigned int v10; // eax@14
  int v11; // ecx@18
  bool v12; // sf@18
  unsigned __int8 v13; // of@18
  int v14; // ebp@21
  unsigned int v15; // eax@22
  int v16; // esi@22
  unsigned int v17; // eax@24
  int v19; // [sp+8h] [bp-8h]@11
  int v20; // [sp+Ch] [bp-4h]@1
  int v21; // [sp+14h] [bp+4h]@10
  int v22; // [sp+14h] [bp+4h]@20

  v2 = a2;
  v3 = this;
  v20 = this;
  if ( this != a2 )
  {
    v4 = *(_DWORD *)(this + 12);
    v5 = v3 + 12;
    *(_DWORD *)(v5 + 8) = 0;
    *(_DWORD *)(v5 + 4) = 0;
    if ( v4 )
    {
      if ( *(_DWORD *)(v4 - 4) )
        (**(void (__stdcall ***)(_DWORD))v4)(3);
      else
        operator delete[]((void *)(v4 - 4));
    }
    v6 = v3 + 24;
    *(_DWORD *)v5 = 0;
    v7 = *(_DWORD *)(v3 + 24);
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 4) = 0;
    if ( v7 )
    {
      if ( *(_DWORD *)(v7 - 4) )
        (**(void (__stdcall ***)(_DWORD))v7)(3);
      else
        operator delete[]((void *)(v7 - 4));
    }
    *(_DWORD *)v6 = 0;
    v21 = 0;
    if ( *(_DWORD *)(v2 + 20) > 0 )
    {
      v19 = 0;
      do
      {
        v8 = *(_DWORD *)(v5 + 4);
        v9 = v19 + *(_DWORD *)(v2 + 12);
        if ( *(_DWORD *)(v5 + 8) < v8
          || (!v8 ? (v10 = 8) : (v10 = 2 * v8),
              AC1Legacy::SmartArray<CharacterIdentity>::grow((AC1Legacy::SmartArray<CharacterIdentity> *)v5, v10)) )
          CharacterIdentity::operator=(*(_DWORD *)v5 + 16 * (*(_DWORD *)(v5 + 8))++, v9);
        v11 = *(_DWORD *)(v2 + 20);
        v13 = __OFSUB__(v21 + 1, v11);
        v12 = v21++ + 1 - v11 < 0;
        v19 += 16;
      }
      while ( v12 ^ v13 );
      v3 = v20;
    }
    v22 = 0;
    if ( *(_DWORD *)(v2 + 32) > 0 )
    {
      v14 = 0;
      do
      {
        v15 = *(_DWORD *)(v6 + 4);
        v16 = v14 + *(_DWORD *)(v2 + 24);
        if ( *(_DWORD *)(v6 + 8) < v15
          || (!v15 ? (v17 = 8) : (v17 = 2 * v15),
              AC1Legacy::SmartArray<CharacterIdentity>::grow((AC1Legacy::SmartArray<CharacterIdentity> *)v6, v17)) )
          CharacterIdentity::operator=(*(_DWORD *)v6 + 16 * (*(_DWORD *)(v6 + 8))++, v16);
        v14 += 16;
        ++v22;
      }
      while ( v22 < *(_DWORD *)(v2 + 32) );
      v3 = v20;
    }
    *(_DWORD *)(v3 + 36) = *(_DWORD *)(v2 + 36);
    *(_DWORD *)(v3 + 40) = *(_DWORD *)(v2 + 40);
    AC1Legacy::PStringBase<char>::set(
      (AC1Legacy::PStringBase<char> *)(v3 + 44),
      (const char *)(*(_DWORD *)(v2 + 44) + 20));
    *(_DWORD *)(v3 + 48) = *(_DWORD *)(v2 + 48);
    *(_DWORD *)(v3 + 52) = *(_DWORD *)(v2 + 52);
    *(_DWORD *)(v3 + 56) = *(_DWORD *)(v2 + 56);
    *(_DWORD *)(v3 + 60) = *(_DWORD *)(v2 + 60);
    *(_DWORD *)(v3 + 64) = *(_DWORD *)(v2 + 64);
  }
  return v3;
}

