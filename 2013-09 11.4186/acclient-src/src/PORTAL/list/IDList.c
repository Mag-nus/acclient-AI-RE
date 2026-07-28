/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : IDList
   Object     : PORTAL\list\IDList.obj
   Functions  : 19
   Addresses  : 005ADB50 - 005AE160 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005ADB50) --------------------------------------------------------  // acclient.c:471791
void __thiscall IDList::Add(IDList *this, unsigned int _id)
{
  IDList *v2; // esi@1
  void *v3; // eax@1
  IDListNode *v4; // ecx@4

  v2 = this;
  v3 = operator new(0xCu);
  if ( v3 )
  {
    *(_DWORD *)v3 = _id;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
  }
  else
  {
    v3 = 0;
  }
  *((_DWORD *)v3 + 1) = v2->last;
  *((_DWORD *)v3 + 2) = 0;
  v4 = v2->last;
  if ( v4 )
  {
    v4->next = (IDListNode *)v3;
    v2->last = (IDListNode *)v3;
    ++v2->numIDs;
  }
  else
  {
    v2->first = (IDListNode *)v3;
    v2->last = (IDListNode *)v3;
    ++v2->numIDs;
  }
}

//----- (005ADBA0) --------------------------------------------------------  // acclient.c:471827
int __thiscall IDList::GetPlaceInList(IDList *this, unsigned int _id)
{
  IDListNode *v2; // edx@1
  int v3; // ecx@1
  int result; // eax@1

  v2 = this->first;
  v3 = this->numIDs;
  for ( result = 0; result < v3; ++result )
  {
    if ( !v2 )
      break;
    if ( v2->id == _id )
      return result;
    v2 = v2->next;
  }
  return -1;
}

//----- (005ADBD0) --------------------------------------------------------  // acclient.c:471847
int __thiscall IDList::IsInList(IDList *this, unsigned int _id)
{
  IDListNode *v2; // eax@1
  int v3; // ecx@1
  int v4; // edx@1

  v2 = this->first;
  v3 = this->numIDs;
  v4 = 0;
  if ( v3 > 0 )
  {
    while ( v2 )
    {
      if ( v2->id == _id )
        return 1;
      v2 = v2->next;
      ++v4;
      if ( v4 >= v3 )
        return 0;
    }
  }
  return 0;
}

//----- (005ADC00) --------------------------------------------------------  // acclient.c:471872
int __thiscall IDList::SetCurToNext(IDList *this)
{
  IDListNode *v1; // eax@1
  IDListNode *v2; // eax@2

  v1 = this->curNode;
  if ( v1 )
  {
    v2 = v1->next;
    this->curNode = v2;
    if ( v2 )
    {
      ++this->curNum;
      return 1;
    }
    this->curNum = -1;
  }
  return 0;
}

//----- (005ADC30) --------------------------------------------------------  // acclient.c:471893
unsigned int __thiscall IDList::GetCurID(IDList *this)
{
  IDListNode *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->curNode;
  if ( v1 )
    result = v1->id;
  else
    result = 0;
  return result;
}

//----- (005ADC40) --------------------------------------------------------  // acclient.c:471907
IDListNode *__thiscall IDList::GetNodeByNum(IDList *this, int _num)
{
  signed int v2; // esi@2
  IDListNode *result; // eax@4
  int j; // ecx@4
  int i; // ecx@8

  if ( _num < 0 || (v2 = this->numIDs, _num >= v2) )
  {
    result = 0;
  }
  else if ( _num > v2 >> 1 )
  {
    result = this->last;
    for ( i = v2 - 1; i > _num; --i )
    {
      if ( !result )
        break;
      result = result->prev;
    }
  }
  else
  {
    result = this->first;
    for ( j = 0; j < _num; ++j )
    {
      if ( !result )
        break;
      result = result->next;
    }
  }
  return result;
}

//----- (005ADCA0) --------------------------------------------------------  // acclient.c:471942
int __thiscall IDList::RemoveNode(IDList *this, IDListNode *_node)
{
  int result; // eax@1
  IDList *v3; // esi@1
  IDListNode *v4; // ecx@2
  IDListNode *v5; // ecx@5

  result = (int)_node;
  v3 = this;
  if ( _node )
  {
    v4 = _node->prev;
    if ( v4 )
      v4->next = _node->next;
    else
      v3->first = _node->next;
    v5 = _node->next;
    if ( v5 )
      v5->prev = _node->prev;
    else
      v3->last = _node->prev;
    operator delete(_node);
    --v3->numIDs;
    result = 1;
  }
  return result;
}

//----- (005ADD00) --------------------------------------------------------  // acclient.c:471971
void __thiscall IDList::IDList(IDList *this)
{
  this->vfptr = (PackObjVtbl *)&IDList::vftable;
  this->first = 0;
  this->last = 0;
  this->curNode = 0;
  this->numIDs = 0;
  this->curNum = -1;
}
// 7E60E8: using guessed type int (__thiscall *IDList::vftable)(void *, char);

//----- (005ADD20) --------------------------------------------------------  // acclient.c:471983
int __thiscall IDList::AddAtNum(IDList *this, unsigned int _id, int _num, int _addAtEndOnFail)
{
  IDList *v4; // esi@1
  IDListNode *v5; // edi@1
  int result; // eax@4
  void *v7; // eax@6
  IDListNode *v8; // ecx@10
  int v9; // ecx@13
  int v10; // eax@17

  v4 = this;
  v5 = IDList::GetNodeByNum(this, _num);
  if ( v5 || _num == v4->numIDs )
  {
    v7 = operator new(0xCu);
    if ( v7 )
    {
      *(_DWORD *)v7 = _id;
      *((_DWORD *)v7 + 1) = 0;
      *((_DWORD *)v7 + 2) = 0;
    }
    else
    {
      v7 = 0;
    }
    if ( _num == v4->numIDs )
    {
      *((_DWORD *)v7 + 1) = v4->last;
      *((_DWORD *)v7 + 2) = 0;
      v8 = v4->last;
      if ( v8 )
      {
        v8->next = (IDListNode *)v7;
        v4->last = (IDListNode *)v7;
      }
      else
      {
        v4->first = (IDListNode *)v7;
        v4->last = (IDListNode *)v7;
      }
    }
    else
    {
      *((_DWORD *)v7 + 1) = v5->prev;
      *((_DWORD *)v7 + 2) = v5;
      v5->prev = (IDListNode *)v7;
      v9 = *((_DWORD *)v7 + 1);
      if ( v9 )
        *(_DWORD *)(v9 + 8) = v7;
      else
        v4->first = (IDListNode *)v7;
    }
    if ( v4->curNode )
    {
      v10 = v4->curNum;
      if ( _num <= v10 )
        v4->curNum = v10 + 1;
    }
    ++v4->numIDs;
    result = 1;
  }
  else if ( _addAtEndOnFail )
  {
    IDList::Add(v4, _id);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005ADDF0) --------------------------------------------------------  // acclient.c:472057
int __thiscall IDList::RemoveByID(IDList *this, unsigned int _id)
{
  IDListNode *v2; // eax@1
  int i; // edx@1
  int v4; // esi@7

  v2 = this->first;
  for ( i = 0; i < this->numIDs; ++i )
  {
    if ( !v2 )
      break;
    if ( v2->id == _id )
      break;
    v2 = v2->next;
  }
  if ( i == this->curNum )
  {
    this->curNum = -1;
    this->curNode = 0;
  }
  v4 = this->curNum;
  if ( i < v4 )
    this->curNum = v4 - 1;
  return IDList::RemoveNode(this, v2);
}

//----- (005ADE40) --------------------------------------------------------  // acclient.c:472084
unsigned int __thiscall IDList::GetByNum(IDList *this, int _num)
{
  IDListNode *v2; // eax@1
  unsigned int result; // eax@2

  v2 = IDList::GetNodeByNum(this, _num);
  if ( v2 )
    result = v2->id;
  else
    result = 0;
  return result;
}

//----- (005ADE60) --------------------------------------------------------  // acclient.c:472098
void __thiscall IDList::Clear(IDList *this)
{
  IDList *v1; // esi@1
  int v2; // ecx@2
  IDListNode *v3; // eax@3
  int i; // ecx@6
  int v5; // ecx@11
  IDListNode *v6; // ecx@14
  IDListNode *v7; // ecx@17

  v1 = this;
  while ( v1->numIDs > 0 )
  {
    v2 = v1->numIDs;
    if ( v2 > 0 )
    {
      if ( (v2 & 0xFFFFFFFE & 0x80000000) != 0 )
      {
        v3 = v1->last;
        for ( i = v2 - 1; i > 0; --i )
        {
          if ( !v3 )
            break;
          v3 = v3->prev;
        }
      }
      else
      {
        v3 = v1->first;
      }
    }
    else
    {
      v3 = 0;
    }
    if ( !v1->curNum )
    {
      v1->curNum = -1;
      v1->curNode = 0;
    }
    v5 = v1->curNum;
    if ( v5 > 0 )
      v1->curNum = v5 - 1;
    if ( v3 )
    {
      v6 = v3->prev;
      if ( v6 )
        v6->next = v3->next;
      else
        v1->first = v3->next;
      v7 = v3->next;
      if ( v7 )
        v7->prev = v3->prev;
      else
        v1->last = v3->prev;
      operator delete(v3);
      --v1->numIDs;
    }
  }
}

//----- (005ADF10) --------------------------------------------------------  // acclient.c:472160
int __thiscall IDList::SetCurToNum(IDList *this, int _num)
{
  IDList *v2; // esi@1
  IDListNode *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = IDList::GetNodeByNum(this, _num);
  v2->curNode = v3;
  if ( v3 )
  {
    v2->curNum = _num;
    result = 1;
  }
  else
  {
    v2->curNum = -1;
    result = 0;
  }
  return result;
}

//----- (005ADF40) --------------------------------------------------------  // acclient.c:472183
unsigned int __thiscall IDList::Pack(IDList *this, void **addr, unsigned int size)
{
  int v3; // edx@1
  unsigned int result; // eax@1
  int v5; // ebx@2
  IDListNode *v6; // edx@3
  int i; // edi@6
  int v8; // edi@9
  IDListNode *v9; // edx@13
  unsigned int v10; // edx@14
  IDListNode *v11; // edx@16
  IDListNode *v12; // edx@17

  v3 = this->numIDs;
  result = 4 * v3 + 4;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    *addr = (char *)*addr + 4;
    v5 = this->numIDs;
    if ( v5 > 0 )
    {
      if ( (v5 & 0xFFFFFFFE & 0x80000000) != 0 )
      {
        v6 = this->last;
        for ( i = v5 - 1; i > 0; --i )
        {
          if ( !v6 )
            break;
          v6 = v6->prev;
        }
      }
      else
      {
        v6 = this->first;
      }
    }
    else
    {
      v6 = 0;
    }
    v8 = 0;
    this->curNode = v6;
    if ( v6 )
      this->curNum = 0;
    else
      this->curNum = -1;
    if ( v5 > 0 )
    {
      do
      {
        v9 = this->curNode;
        if ( v9 )
          v10 = v9->id;
        else
          v10 = 0;
        *(_DWORD *)*addr = v10;
        *addr = (char *)*addr + 4;
        v11 = this->curNode;
        if ( v11 )
        {
          v12 = v11->next;
          this->curNode = v12;
          if ( v12 )
            ++this->curNum;
          else
            this->curNum = -1;
        }
        ++v8;
      }
      while ( v8 < this->numIDs );
    }
  }
  return result;
}

//----- (005ADFF0) --------------------------------------------------------  // acclient.c:472260
int __thiscall IDList::UnPack(IDList *this, void **addr, unsigned int size)
{
  IDList *v3; // esi@1
  void **v4; // ebx@1
  void **v5; // ecx@1
  int v6; // edi@3
  void *v7; // eax@3
  IDListNode *v8; // ecx@6
  int v9; // ecx@9
  bool v10; // zf@9
  void **addra; // [sp+10h] [bp+4h]@2

  v3 = this;
  IDList::Clear(this);
  v4 = addr;
  v5 = *(void ***)*addr;
  *addr = (char *)*addr + 4;
  if ( (signed int)v5 > 0 )
  {
    addra = v5;
    do
    {
      v6 = *(_DWORD *)*v4;
      *v4 = (char *)*v4 + 4;
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *(_DWORD *)v7 = v6;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 0;
      }
      else
      {
        v7 = 0;
      }
      *((_DWORD *)v7 + 1) = v3->last;
      *((_DWORD *)v7 + 2) = 0;
      v8 = v3->last;
      if ( v8 )
        v8->next = (IDListNode *)v7;
      else
        v3->first = (IDListNode *)v7;
      v9 = v3->numIDs;
      v3->last = (IDListNode *)v7;
      v10 = addra == (void **)1;
      v3->numIDs = v9 + 1;
      addra = (void **)((char *)addra - 1);
    }
    while ( !v10 );
  }
  return 1;
}

//----- (005AE070) --------------------------------------------------------  // acclient.c:472314
void __thiscall IDList::~IDList(IDList *this)
{
  IDList *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&IDList::vftable;
  IDList::Clear(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E60E8: using guessed type int (__thiscall *IDList::vftable)(void *, char);

//----- (005AE090) --------------------------------------------------------  // acclient.c:472327
void __thiscall IDList::AddList(IDList *this, IDList *_list)
{
  int v2; // edx@1
  int v3; // ebx@1
  IDList *v4; // edi@1
  IDListNode *v5; // eax@2
  int i; // ecx@5
  IDListNode *v7; // eax@12
  unsigned int v8; // eax@13
  IDListNode *v9; // eax@15
  IDListNode *v10; // eax@16

  v2 = _list->numIDs;
  v3 = 0;
  v4 = this;
  if ( v2 > 0 )
  {
    if ( (v2 & 0xFFFFFFFE & 0x80000000) != 0 )
    {
      v5 = _list->last;
      for ( i = v2 - 1; i > 0; --i )
      {
        if ( !v5 )
          break;
        v5 = v5->prev;
      }
    }
    else
    {
      v5 = _list->first;
    }
  }
  else
  {
    v5 = 0;
  }
  _list->curNode = v5;
  if ( v5 )
    _list->curNum = 0;
  else
    _list->curNum = -1;
  if ( v2 > 0 )
  {
    do
    {
      v7 = _list->curNode;
      if ( v7 )
        v8 = v7->id;
      else
        v8 = 0;
      IDList::AddAtNum(v4, v8, v4->numIDs, 1);
      v9 = _list->curNode;
      if ( v9 )
      {
        v10 = v9->next;
        _list->curNode = v10;
        if ( v10 )
          ++_list->curNum;
        else
          _list->curNum = -1;
      }
      ++v3;
    }
    while ( v3 < _list->numIDs );
  }
}

//----- (005AE130) --------------------------------------------------------  // acclient.c:472395
IDList *__thiscall IDList::scalar_deleting_destructor(IDList *this, unsigned int a2)
{
  IDList *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&IDList::vftable;
  IDList::Clear(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E60E8: using guessed type int (__thiscall *IDList::vftable)(void *, char);

//----- (005AE160) --------------------------------------------------------  // acclient.c:472411
void __thiscall IDList::IDList(IDList *this, IDList *_list)
{
  this->first = 0;
  this->last = 0;
  this->curNode = 0;
  this->numIDs = 0;
  this->vfptr = (PackObjVtbl *)&IDList::vftable;
  this->curNum = -1;
  IDList::AddList(this, _list);
}
// 7E60E8: using guessed type int (__thiscall *IDList::vftable)(void *, char);

