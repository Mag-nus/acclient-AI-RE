/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEmoteSet
   Object     : AC\accqualities\CEmoteSet.obj
   Functions  : 19
   Addresses  : 005962F0 - 0070AD30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005962F0) --------------------------------------------------------  // acclient.c:448069
int __thiscall PackableList<Emote>::InsertTail(PackableList<Emote> *this, Emote *val)
{
  PackableList<Emote> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<Emote> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x130u);
  if ( v3 )
  {
    Emote::Emote((Emote *)v3, val);
    *((_DWORD *)v3 + 74) = 0;
    *((_DWORD *)v3 + 75) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<Emote> *)v3;
    *((_DWORD *)v3 + 75) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<Emote> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<Emote> *)v3;
    v2->tail = (PackableLLNode<Emote> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (00596370) --------------------------------------------------------  // acclient.c:448112
signed int __thiscall PackableList<Emote>::Pack(PackableList<Emote> *this, void **addr, unsigned int size)
{
  PackableList<Emote> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<Emote> *i; // esi@4

  v3 = this;
  v4 = PackableList<Emote>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<Emote> *, void **, unsigned int))i->data.vfptr->Pack)(i, addr, size);
  }
  return v4;
}

//----- (005963C0) --------------------------------------------------------  // acclient.c:448134
signed int __thiscall PackableList<Emote>::pack_size(PackableList<Emote> *this)
{
  PackableLLNode<Emote> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<Emote> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (00596400) --------------------------------------------------------  // acclient.c:448153
int __thiscall EmoteSet::pack_size(EmoteSet *this)
{
  EmoteSet *v1; // edi@1
  unsigned int v2; // eax@1
  int v3; // esi@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this;
  v2 = this->category - 1;
  dummy = 0;
  v3 = 8;
  switch ( v2 )
  {
    case 0xBu:
    case 0xCu:
    case 0x15u:
    case 0x16u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Du:
    case 0x1Eu:
    case 0x1Fu:
    case 0x20u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
    case 0x24u:
    case 0x25u:
      v3 = AC1Legacy::PStringBase<char>::Pack(&this->quest, &dummy, 0) + 8;
      break;
    case 0u:
    case 1u:
    case 5u:
      v3 = 12;
      break;
    case 4u:
    case 0xEu:
      v3 = 16;
      break;
    default:
      return v3 + ((int (__thiscall *)(int, void **, _DWORD))v1->emotes.vfptr->Pack)(&v1->emotes, &dummy, 0);
  }
  return v3 + ((int (__thiscall *)(int, void **, _DWORD))v1->emotes.vfptr->Pack)(&v1->emotes, &dummy, 0);
}

//----- (005964A0) --------------------------------------------------------  // acclient.c:448201
int __thiscall EmoteSet::Pack(EmoteSet *this, void **addr, unsigned int size)
{
  EmoteSet *v3; // edi@1
  int v4; // ebp@1
  char *v5; // ecx@2
  char *v6; // eax@2
  char *v7; // ecx@4
  char *v9; // ecx@7

  v3 = this;
  v4 = EmoteSet::pack_size(this);
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->category;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->probability;
    v6 = (char *)*addr + 4;
    *addr = v6;
    switch ( v3->category )
    {
      case 1u:
      case 6u:
        *(_DWORD *)v6 = v3->classID.id;
        goto LABEL_8;
      case 5u:
        *(_DWORD *)v6 = v3->style;
        v7 = (char *)*addr + 4;
        *addr = v7;
        *(_DWORD *)v7 = v3->substyle;
        goto LABEL_8;
      case 0xCu:
      case 0xDu:
      case 0x16u:
      case 0x17u:
      case 0x1Bu:
      case 0x1Cu:
      case 0x1Du:
      case 0x1Eu:
      case 0x1Fu:
      case 0x20u:
      case 0x21u:
      case 0x22u:
      case 0x23u:
      case 0x24u:
      case 0x25u:
      case 0x26u:
        AC1Legacy::PStringBase<char>::Pack(&v3->quest, addr, size);
        ((void (__thiscall *)(int, void **, unsigned int))v3->emotes.vfptr->Pack)(&v3->emotes, addr, size);
        return v4;
      case 2u:
        *(_DWORD *)v6 = v3->vendorType;
        goto LABEL_8;
      case 0xFu:
        *(float *)v6 = v3->minhealth;
        v9 = (char *)*addr + 4;
        *addr = v9;
        *(float *)v9 = v3->maxhealth;
LABEL_8:
        *addr = (char *)*addr + 4;
        break;
      default:
        break;
    }
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->emotes.vfptr->Pack)(&v3->emotes, addr, size);
  }
  return v4;
}

//----- (005965A0) --------------------------------------------------------  // acclient.c:448271
void __thiscall PackableList<Emote>::Flush(PackableList<Emote> *this)
{
  PackableList<Emote> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  Emote dummyData; // [sp+8h] [bp-128h]@1

  v1 = this;
  Emote::Emote(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 296);
      v1->head = (PackableLLNode<Emote> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 300) = 0;
      else
        v1->tail = 0;
      Emote::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        Emote::~Emote((Emote *)v2);
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
  Emote::~Emote(&dummyData);
}

//----- (00596620) --------------------------------------------------------  // acclient.c:448304
int __thiscall EmoteSet::UnPack(EmoteSet *this, void **addr, unsigned int size)
{
  EmoteSet *v3; // edi@1
  int result; // eax@2
  char *v5; // ecx@3
  char *v6; // eax@3
  unsigned int v7; // ecx@6
  char *v8; // ecx@8
  char *v9; // ecx@13

  v3 = this;
  if ( size >= 8 )
  {
    this->category = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(v3->probability) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    switch ( v3->category )
    {
      case 1u:
      case 6u:
        if ( size < 0xC )
          goto LABEL_5;
        v7 = *(_DWORD *)v6;
        *addr = v6 + 4;
        v3->classID.id = v7;
        goto LABEL_15;
      case 5u:
        if ( size < 0x10 )
          goto LABEL_5;
        v3->style = *(_DWORD *)v6;
        v8 = (char *)*addr + 4;
        *addr = v8;
        v3->substyle = *(_DWORD *)v8;
        goto LABEL_14;
      case 0xCu:
      case 0xDu:
      case 0x16u:
      case 0x17u:
      case 0x1Bu:
      case 0x1Cu:
      case 0x1Du:
      case 0x1Eu:
      case 0x1Fu:
      case 0x20u:
      case 0x21u:
      case 0x22u:
      case 0x23u:
      case 0x24u:
      case 0x25u:
      case 0x26u:
        AC1Legacy::PStringBase<char>::UnPack(&v3->quest, addr, size);
        goto LABEL_15;
      case 2u:
        if ( size < 0xC )
          goto LABEL_5;
        v3->vendorType = *(_DWORD *)v6;
        goto LABEL_14;
      case 0xFu:
        if ( size < 0x10 )
        {
LABEL_5:
          result = 0;
        }
        else
        {
          LODWORD(v3->minhealth) = *(_DWORD *)v6;
          v9 = (char *)*addr + 4;
          *addr = v9;
          LODWORD(v3->maxhealth) = *(_DWORD *)v9;
LABEL_14:
          *addr = (char *)*addr + 4;
LABEL_15:
          result = ((int (__thiscall *)(int, void **, unsigned int))v3->emotes.vfptr->UnPack)(&v3->emotes, addr, size) != 0;
        }
        break;
      default:
        goto LABEL_15;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00596730) --------------------------------------------------------  // acclient.c:448394
PackableList<Emote> *__thiscall PackableList<Emote>::operator=(PackableList<Emote> *this, int a2)
{
  PackableList<Emote> *v2; // edi@1
  int i; // esi@1

  v2 = this;
  PackableList<Emote>::Flush(this);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 296) )
  {
    PackableList<Emote>::InsertTail(v2, (Emote *)i);
    if ( !i )
      break;
  }
  return v2;
}

//----- (00596770) --------------------------------------------------------  // acclient.c:448411
int __thiscall PackableList<Emote>::UnPack(PackableList<Emote> *this, void **addr, unsigned int size)
{
  PackableList<Emote> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  Emote temp; // [sp+8h] [bp-128h]@2

  v3 = this;
  PackableList<Emote>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    Emote::Emote(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      Emote::~Emote(&temp);
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(Emote *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<Emote>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      Emote::~Emote(&temp);
      result = 0;
    }
  }
  return result;
}

//----- (00596820) --------------------------------------------------------  // acclient.c:448454
PackableList<Emote> *__thiscall PackableList<Emote>::scalar_deleting_destructor(PackableList<Emote> *this, unsigned int a2)
{
  PackableList<Emote> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<Emote>::vftable;
  PackableList<Emote>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E47D0: using guessed type int (__thiscall *PackableList<Emote>::vftable)(void *, char);

//----- (00596850) --------------------------------------------------------  // acclient.c:448470
void __thiscall EmoteSet::EmoteSet(EmoteSet *this)
{
  EmoteSet *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&EmoteSet::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->quest.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->emotes.vfptr = (PackObjVtbl *)&PackableList<Emote>::vftable;
  v1->emotes.head = 0;
  v1->emotes.tail = 0;
  v1->emotes.curNum = 0;
  v1->category = 0;
  LODWORD(v1->probability) = 0;
  v1->classID.id = stru_871070.id;
  v1->style = 0;
  v1->substyle = 0;
  v1->vendorType = 0;
  AC1Legacy::PStringBase<char>::set(&v1->quest, &name);
  LODWORD(v1->minhealth) = 0;
  LODWORD(v1->maxhealth) = 0;
}
// 7E47D0: using guessed type int (__thiscall *PackableList<Emote>::vftable)(void *, char);
// 7E47E4: using guessed type int (__thiscall *EmoteSet::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005968C0) --------------------------------------------------------  // acclient.c:448499
void __thiscall EmoteSet::~EmoteSet(EmoteSet *this)
{
  EmoteSet *v1; // esi@1
  char *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v1 = this;
  v2 = (char *)&this->emotes;
  this->vfptr = (PackObjVtbl *)&EmoteSet::vftable;
  this->emotes.vfptr = (PackObjVtbl *)&PackableList<Emote>::vftable;
  PackableList<Emote>::Flush(&this->emotes);
  *(_DWORD *)v2 = &PackObj::vftable;
  v3 = v1->quest.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E47D0: using guessed type int (__thiscall *PackableList<Emote>::vftable)(void *, char);
// 7E47E4: using guessed type int (__thiscall *EmoteSet::vftable)(void *, char);

//----- (00596910) --------------------------------------------------------  // acclient.c:448521
int __thiscall EmoteSet::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
    PackableList<Emote>::operator=((PackableList<Emote> *)(this + 40), a2 + 40);
    v3 = *(_DWORD *)(v2 + 16);
    if ( v3 != *(_DWORD *)(a2 + 16) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 16);
      *(_DWORD *)(v2 + 16) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
  }
  return v2;
}

//----- (005969A0) --------------------------------------------------------  // acclient.c:448553
EmoteSet *__thiscall EmoteSet::scalar_deleting_destructor(EmoteSet *this, unsigned int a2)
{
  EmoteSet *v2; // esi@1
  char *v3; // edi@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1

  v2 = this;
  v3 = (char *)&this->emotes;
  this->vfptr = (PackObjVtbl *)&EmoteSet::vftable;
  this->emotes.vfptr = (PackObjVtbl *)&PackableList<Emote>::vftable;
  PackableList<Emote>::Flush(&this->emotes);
  *(_DWORD *)v3 = &PackObj::vftable;
  v4 = v2->quest.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E47D0: using guessed type int (__thiscall *PackableList<Emote>::vftable)(void *, char);
// 7E47E4: using guessed type int (__thiscall *EmoteSet::vftable)(void *, char);

//----- (00596A00) --------------------------------------------------------  // acclient.c:448578
void __thiscall EmoteSet::EmoteSet(EmoteSet *this, EmoteSet *rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&EmoteSet::vftable;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->quest.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  *(_DWORD *)(v2 + 40) = &PackableList<Emote>::vftable;
  *(_DWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  EmoteSet::operator=(v2, (int)rhs);
}
// 7E47D0: using guessed type int (__thiscall *PackableList<Emote>::vftable)(void *, char);
// 7E47E4: using guessed type int (__thiscall *EmoteSet::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070ACD0) --------------------------------------------------------  // acclient.c:798008
void sub_70ACD0()
{
  flt_871074 = 1000.0 + 1.0;
}

//----- (0070ACF0) --------------------------------------------------------  // acclient.c:798014
void sub_70ACF0()
{
  flt_871078 = 24.0 * 8.0;
}

//----- (0070AD10) --------------------------------------------------------  // acclient.c:798020
void sub_70AD10()
{
  flt_87107C = 24.0 * 0.5;
}

//----- (0070AD30) --------------------------------------------------------  // acclient.c:798026
int sub_70AD30()
{
  return atexit(nullsub_1423);
}

