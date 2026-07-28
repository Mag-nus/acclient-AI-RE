/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMInterpPrim
   Object     : PORTAL\canim\CMInterpPrim.obj
   Functions  : 33
   Addresses  : 0051E6E0 - 006FD4E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051E6E0) --------------------------------------------------------  // acclient.c:332494
void __thiscall RawMotionState::RemoveMotion(RawMotionState *this, unsigned int motion)
{
  switch ( motion )
  {
    case 0x6500000Fu:
    case 0x65000010u:
      this->sidestep_command = 0;
      break;
    case 0x6500000Du:
    case 0x6500000Eu:
      this->turn_command = 0;
      break;
    default:
      if ( motion & 0x40000000 )
      {
        if ( motion == this->forward_command )
        {
          this->forward_command = 1090519043;
          LODWORD(this->forward_speed) = 1065353216;
        }
      }
      else if ( (motion & 0x80000000) != 0 && motion == this->current_style )
      {
        this->current_style = -2147483587;
      }
      break;
  }
}

//----- (0051E750) --------------------------------------------------------  // acclient.c:332524
void __thiscall InterpretedMotionState::copy_movement_from(InterpretedMotionState *this, InterpretedMotionState *rhs)
{
  this->current_style = rhs->current_style;
  this->forward_command = rhs->forward_command;
  this->forward_speed = rhs->forward_speed;
  this->sidestep_command = rhs->sidestep_command;
  this->sidestep_speed = rhs->sidestep_speed;
  this->turn_command = rhs->turn_command;
  this->turn_speed = rhs->turn_speed;
}

//----- (0051E790) --------------------------------------------------------  // acclient.c:332536
void __thiscall InterpretedMotionState::RemoveMotion(InterpretedMotionState *this, unsigned int motion)
{
  if ( motion == 1694498829 )
  {
    this->turn_command = 0;
  }
  else if ( motion == 1694498831 )
  {
    this->sidestep_command = 0;
  }
  else if ( motion & 0x40000000 )
  {
    if ( motion == this->forward_command )
    {
      this->forward_command = 1090519043;
      LODWORD(this->forward_speed) = 1065353216;
    }
  }
  else if ( (motion & 0x80000000) != 0 && motion == this->current_style )
  {
    this->current_style = -2147483587;
  }
}

//----- (0051E7F0) --------------------------------------------------------  // acclient.c:332561
void __thiscall RawMotionState::RawMotionState(RawMotionState *this)
{
  this->vfptr = (PackObjVtbl *)&RawMotionState::vftable;
  this->actions.head_ = 0;
  this->actions.tail_ = 0;
  this->current_holdkey = 1;
  this->current_style = -2147483587;
  this->forward_command = 1090519043;
  this->forward_holdkey = 0;
  LODWORD(this->forward_speed) = 1065353216;
  this->sidestep_command = 0;
  this->sidestep_holdkey = 0;
  LODWORD(this->sidestep_speed) = 1065353216;
  this->turn_command = 0;
  this->turn_holdkey = 0;
  LODWORD(this->turn_speed) = 1065353216;
}
// 7C7A4C: using guessed type int (__thiscall *RawMotionState::vftable)(void *, char);

//----- (0051E840) --------------------------------------------------------  // acclient.c:332581
void __thiscall RawMotionState::AddAction(RawMotionState *this, unsigned int action, float speed, unsigned int stamp, int autonomous)
{
  RawMotionState *v5; // esi@1
  void *v6; // eax@1
  LListData *v7; // ecx@4

  v5 = this;
  v6 = operator new(0x14u);
  if ( v6 )
  {
    *((_DWORD *)v6 + 1) = action;
    *((float *)v6 + 2) = speed;
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 3) = stamp;
    *((_DWORD *)v6 + 4) = autonomous;
  }
  else
  {
    v6 = 0;
  }
  v7 = v5->actions.tail_;
  if ( v7 )
  {
    v7->llist_next = (LListData *)v6;
    v5->actions.tail_ = (LListData *)v6;
  }
  else
  {
    v5->actions.head_ = (LListData *)v6;
    v5->actions.tail_ = (LListData *)v6;
  }
}

//----- (0051E8A0) --------------------------------------------------------  // acclient.c:332615
unsigned int __thiscall RawMotionState::RemoveAction(RawMotionState *this)
{
  LListData *v1; // edx@1
  unsigned int result; // eax@1
  LListData *v3; // eax@2
  bool v4; // zf@2
  unsigned int v5; // esi@4

  v1 = this->actions.head_;
  result = 0;
  if ( v1 )
  {
    v3 = v1->llist_next;
    v4 = v1->llist_next == 0;
    this->actions.head_ = v1->llist_next;
    if ( v4 )
      this->actions.tail_ = v3;
    v1->llist_next = 0;
    v5 = (unsigned int)v1[1].llist_next;
    operator delete(v1);
    result = v5;
  }
  return result;
}

//----- (0051E8D0) --------------------------------------------------------  // acclient.c:332641
void __thiscall InterpretedMotionState::InterpretedMotionState(InterpretedMotionState *this)
{
  this->vfptr = (PackObjVtbl *)&InterpretedMotionState::vftable;
  this->current_style = -2147483587;
  this->forward_command = 1090519043;
  LODWORD(this->forward_speed) = 1065353216;
  this->sidestep_command = 0;
  LODWORD(this->sidestep_speed) = 1065353216;
  this->turn_command = 0;
  LODWORD(this->turn_speed) = 1065353216;
  this->actions.head_ = 0;
  this->actions.tail_ = 0;
}
// 7C7A60: using guessed type int (__thiscall *InterpretedMotionState::vftable)(void *, char);

//----- (0051E910) --------------------------------------------------------  // acclient.c:332657
void __thiscall InterpretedMotionState::Destroy(InterpretedMotionState *this)
{
  InterpretedMotionState *v1; // esi@1
  void *v2; // eax@2
  LListData *v3; // ecx@3
  bool v4; // zf@3

  v1 = this;
  while ( v1->actions.head_ )
  {
    v2 = v1->actions.head_;
    if ( v2 )
    {
      v3 = *(LListData **)v2;
      v4 = *(_DWORD *)v2 == 0;
      v1->actions.head_ = *(LListData **)v2;
      if ( v4 )
        v1->actions.tail_ = v3;
      *(_DWORD *)v2 = 0;
      operator delete(v2);
    }
  }
}

//----- (0051E950) --------------------------------------------------------  // acclient.c:332682
InterpretedMotionState *__thiscall InterpretedMotionState::operator=(InterpretedMotionState *this, int a2)
{
  InterpretedMotionState *v2; // edi@1
  int i; // esi@1
  void *v4; // eax@2
  LListData *v5; // ecx@5

  v2 = this;
  InterpretedMotionState::Destroy(this);
  v2->current_style = *(_DWORD *)(a2 + 4);
  v2->forward_command = *(_DWORD *)(a2 + 8);
  LODWORD(v2->forward_speed) = *(_DWORD *)(a2 + 12);
  v2->sidestep_command = *(_DWORD *)(a2 + 16);
  LODWORD(v2->sidestep_speed) = *(_DWORD *)(a2 + 20);
  v2->turn_command = *(_DWORD *)(a2 + 24);
  LODWORD(v2->turn_speed) = *(_DWORD *)(a2 + 28);
  for ( i = *(_DWORD *)(a2 + 32); i; i = *(_DWORD *)i )
  {
    v4 = operator new(0x14u);
    if ( v4 )
    {
      *(_DWORD *)v4 = 0;
      *((_DWORD *)v4 + 1) = *(_DWORD *)(i + 4);
      *((_DWORD *)v4 + 2) = *(_DWORD *)(i + 8);
      *((_DWORD *)v4 + 3) = *(_DWORD *)(i + 12);
      *((_DWORD *)v4 + 4) = *(_DWORD *)(i + 16);
    }
    else
    {
      v4 = 0;
    }
    v5 = v2->actions.tail_;
    if ( v5 )
      v5->llist_next = (LListData *)v4;
    else
      v2->actions.head_ = (LListData *)v4;
    v2->actions.tail_ = (LListData *)v4;
  }
  return v2;
}

//----- (0051E9E0) --------------------------------------------------------  // acclient.c:332724
void __thiscall InterpretedMotionState::AddAction(InterpretedMotionState *this, unsigned int action, float speed, unsigned int stamp, int autonomous)
{
  InterpretedMotionState *v5; // esi@1
  void *v6; // eax@1
  LListData *v7; // ecx@4

  v5 = this;
  v6 = operator new(0x14u);
  if ( v6 )
  {
    *((_DWORD *)v6 + 1) = action;
    *((float *)v6 + 2) = speed;
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 3) = stamp;
    *((_DWORD *)v6 + 4) = autonomous;
  }
  else
  {
    v6 = 0;
  }
  v7 = v5->actions.tail_;
  if ( v7 )
  {
    v7->llist_next = (LListData *)v6;
    v5->actions.tail_ = (LListData *)v6;
  }
  else
  {
    v5->actions.head_ = (LListData *)v6;
    v5->actions.tail_ = (LListData *)v6;
  }
}

//----- (0051EA40) --------------------------------------------------------  // acclient.c:332758
void __thiscall InterpretedMotionState::ApplyMotion(InterpretedMotionState *this, unsigned int motion, MovementParameters *params)
{
  if ( motion == 1694498829 )
  {
    this->turn_command = 1694498829;
    this->turn_speed = params->speed;
  }
  else if ( motion == 1694498831 )
  {
    this->sidestep_command = 1694498831;
    this->sidestep_speed = params->speed;
  }
  else if ( motion & 0x40000000 )
  {
    this->forward_command = motion;
    this->forward_speed = params->speed;
  }
  else if ( (motion & 0x80000000) == 0 )
  {
    if ( motion & 0x10000000 )
      InterpretedMotionState::AddAction(this, motion, params->speed, params->action_stamp, (params->bitfield >> 12) & 1);
  }
  else
  {
    this->forward_command = 1090519043;
    this->current_style = motion;
  }
}

//----- (0051EAD0) --------------------------------------------------------  // acclient.c:332788
unsigned int __thiscall InterpretedMotionState::RemoveAction(InterpretedMotionState *this)
{
  LListData *v1; // edx@1
  unsigned int result; // eax@1
  LListData *v3; // eax@2
  bool v4; // zf@2
  unsigned int v5; // esi@4

  v1 = this->actions.head_;
  result = 0;
  if ( v1 )
  {
    v3 = v1->llist_next;
    v4 = v1->llist_next == 0;
    this->actions.head_ = v1->llist_next;
    if ( v4 )
      this->actions.tail_ = v3;
    v1->llist_next = 0;
    v5 = (unsigned int)v1[1].llist_next;
    operator delete(v1);
    result = v5;
  }
  return result;
}

//----- (0051EB00) --------------------------------------------------------  // acclient.c:332814
unsigned int __thiscall InterpretedMotionState::GetNumActions(InterpretedMotionState *this)
{
  LListData *v1; // ecx@1
  unsigned int result; // eax@1

  v1 = this->actions.head_;
  for ( result = 0; v1; ++result )
    v1 = v1->llist_next;
  return result;
}

//----- (0051EB20) --------------------------------------------------------  // acclient.c:332826
void __thiscall RawMotionState::Destroy(RawMotionState *this)
{
  RawMotionState *v1; // esi@1
  void *v2; // eax@2
  LListData *v3; // ecx@3
  bool v4; // zf@3

  v1 = this;
  while ( v1->actions.head_ )
  {
    v2 = v1->actions.head_;
    if ( v2 )
    {
      v3 = *(LListData **)v2;
      v4 = *(_DWORD *)v2 == 0;
      v1->actions.head_ = *(LListData **)v2;
      if ( v4 )
        v1->actions.tail_ = v3;
      *(_DWORD *)v2 = 0;
      operator delete(v2);
    }
  }
}

//----- (0051EB60) --------------------------------------------------------  // acclient.c:332851
void __thiscall RawMotionState::ApplyMotion(RawMotionState *this, unsigned int motion, MovementParameters *params)
{
  unsigned int v3; // edx@2
  unsigned int v4; // edx@5
  unsigned int v5; // edx@10

  switch ( motion )
  {
    case 0x6500000Fu:
    case 0x65000010u:
      this->sidestep_command = motion;
      v3 = params->bitfield;
      if ( BYTE1(v3) & 8 )
      {
        this->sidestep_holdkey = 0;
        this->sidestep_speed = params->speed;
      }
      else
      {
        this->sidestep_holdkey = params->hold_key_to_apply;
        this->sidestep_speed = params->speed;
      }
      break;
    case 0x6500000Du:
    case 0x6500000Eu:
      this->turn_command = motion;
      v4 = params->bitfield;
      if ( BYTE1(v4) & 8 )
      {
        this->turn_holdkey = 0;
        this->turn_speed = params->speed;
      }
      else
      {
        this->turn_holdkey = params->hold_key_to_apply;
        this->turn_speed = params->speed;
      }
      break;
    default:
      if ( motion & 0x40000000 )
      {
        if ( motion != 1140850695 )
        {
          this->forward_command = motion;
          v5 = params->bitfield;
          if ( BYTE1(v5) & 8 )
          {
            this->forward_holdkey = 0;
            this->forward_speed = params->speed;
          }
          else
          {
            this->forward_holdkey = params->hold_key_to_apply;
            this->forward_speed = params->speed;
          }
        }
      }
      else if ( (motion & 0x80000000) == 0 )
      {
        if ( motion & 0x10000000 )
          RawMotionState::AddAction(this, motion, params->speed, params->action_stamp, (params->bitfield >> 12) & 1);
      }
      else if ( this->current_style != motion )
      {
        this->forward_command = 1090519043;
        this->current_style = motion;
      }
      break;
  }
}

//----- (0051EC60) --------------------------------------------------------  // acclient.c:332923
RawMotionState *__thiscall RawMotionState::operator=(RawMotionState *this, int a2)
{
  RawMotionState *v2; // esi@1
  int i; // edi@1
  void *v4; // eax@2
  LListData *v5; // ecx@5

  v2 = this;
  RawMotionState::Destroy(this);
  v2->current_holdkey = *(_DWORD *)(a2 + 12);
  v2->current_style = *(_DWORD *)(a2 + 16);
  v2->forward_command = *(_DWORD *)(a2 + 20);
  v2->forward_holdkey = *(_DWORD *)(a2 + 24);
  LODWORD(v2->forward_speed) = *(_DWORD *)(a2 + 28);
  v2->sidestep_command = *(_DWORD *)(a2 + 32);
  v2->sidestep_holdkey = *(_DWORD *)(a2 + 36);
  LODWORD(v2->sidestep_speed) = *(_DWORD *)(a2 + 40);
  v2->turn_command = *(_DWORD *)(a2 + 44);
  v2->turn_holdkey = *(_DWORD *)(a2 + 48);
  LODWORD(v2->turn_speed) = *(_DWORD *)(a2 + 52);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)i )
  {
    v4 = operator new(0x14u);
    if ( v4 )
    {
      *(_DWORD *)v4 = 0;
      *((_DWORD *)v4 + 1) = *(_DWORD *)(i + 4);
      *((_DWORD *)v4 + 2) = *(_DWORD *)(i + 8);
      *((_DWORD *)v4 + 3) = *(_DWORD *)(i + 12);
      *((_DWORD *)v4 + 4) = *(_DWORD *)(i + 16);
    }
    else
    {
      v4 = 0;
    }
    v5 = v2->actions.tail_;
    if ( v5 )
      v5->llist_next = (LListData *)v4;
    else
      v2->actions.head_ = (LListData *)v4;
    v2->actions.tail_ = (LListData *)v4;
  }
  return v2;
}

//----- (0051ED10) --------------------------------------------------------  // acclient.c:332969
unsigned int __thiscall RawMotionState::Pack(RawMotionState *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  int v4; // eax@1
  unsigned int v5; // ebx@3
  int v6; // ebx@5
  int v7; // ebx@7
  int v8; // ebx@9
  int v9; // ebx@11
  int v10; // ebx@13
  int v11; // ebx@15
  int v12; // ebx@17
  int v13; // ebx@19
  int v14; // ebx@21
  LListData *v15; // edx@23
  __int16 i; // si@23
  int v17; // ebx@25
  LListData *j; // ecx@50
  __int16 v19; // si@52
  char *v20; // ebx@54
  char *v21; // edi@54

  v3 = 4;
  v4 = ((unsigned __int8)size ^ (this->current_holdkey != 1)) & 1;
  if ( ((unsigned __int8)v4 ^ (unsigned __int8)size) & 1 )
    v3 = 8;
  v5 = ((unsigned __int8)(v4 ^ size) ^ (unsigned __int8)(2 * (this->current_style != -2147483587))) & 2 ^ v4 ^ size;
  if ( v5 & 2 )
    v3 += 4;
  v6 = ((unsigned __int8)v5 ^ (unsigned __int8)(4 * (this->forward_command != 1090519043))) & 4 ^ v5;
  if ( v6 & 4 )
    v3 += 4;
  v7 = ((unsigned __int8)v6 ^ (unsigned __int8)(8 * (this->forward_holdkey != 0))) & 8 ^ v6;
  if ( v7 & 8 )
    v3 += 4;
  v8 = ((unsigned __int8)v7 ^ (unsigned __int8)(16 * (LODWORD(this->forward_speed) != 1065353216))) & 0x10 ^ v7;
  if ( v8 & 0x10 )
    v3 += 4;
  v9 = ((unsigned __int8)v8 ^ (unsigned __int8)(32 * (this->sidestep_command != 0))) & 0x20 ^ v8;
  if ( v9 & 0x20 )
    v3 += 4;
  v10 = ((unsigned __int8)v9 ^ (unsigned __int8)((this->sidestep_holdkey != 0) << 6)) & 0x40 ^ v9;
  if ( v10 & 0x40 )
    v3 += 4;
  v11 = (unsigned __int8)((v10 ^ ((LODWORD(this->sidestep_speed) != 1065353216) << 7)) & 0x80) ^ v10;
  if ( (char)v11 < 0 )
    v3 += 4;
  v12 = ((unsigned __int16)v11 ^ (unsigned __int16)((this->turn_command != 0) << 8)) & 0x100 ^ v11;
  if ( BYTE1(v12) & 1 )
    v3 += 4;
  v13 = ((unsigned __int16)v12 ^ (unsigned __int16)((this->turn_holdkey != 0) << 9)) & 0x200 ^ v12;
  if ( BYTE1(v13) & 2 )
    v3 += 4;
  v14 = ((unsigned __int16)v13 ^ (unsigned __int16)((LODWORD(this->turn_speed) != 1065353216) << 10)) & 0x400 ^ v13;
  if ( BYTE1(v14) & 4 )
    v3 += 4;
  v15 = this->actions.head_;
  for ( i = 0; v15; ++i )
  {
    v15 = v15->llist_next;
    v3 += 8;
  }
  v17 = (unsigned __int16)((v14 ^ (i << 11)) & 0xF800) ^ v14;
  if ( size >= v3 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v17;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 1 )
    {
      *(_DWORD *)*addr = this->current_holdkey;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 2 )
    {
      *(_DWORD *)*addr = this->current_style;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 4 )
    {
      *(_DWORD *)*addr = this->forward_command;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 8 )
    {
      *(_DWORD *)*addr = this->forward_holdkey;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 0x10 )
    {
      *(_DWORD *)*addr = LODWORD(this->forward_speed);
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 0x20 )
    {
      *(_DWORD *)*addr = this->sidestep_command;
      *addr = (char *)*addr + 4;
    }
    if ( v17 & 0x40 )
    {
      *(_DWORD *)*addr = this->sidestep_holdkey;
      *addr = (char *)*addr + 4;
    }
    if ( (char)v17 < 0 )
    {
      *(_DWORD *)*addr = LODWORD(this->sidestep_speed);
      *addr = (char *)*addr + 4;
    }
    if ( BYTE1(v17) & 1 )
    {
      *(_DWORD *)*addr = this->turn_command;
      *addr = (char *)*addr + 4;
    }
    if ( BYTE1(v17) & 2 )
    {
      *(_DWORD *)*addr = this->turn_holdkey;
      *addr = (char *)*addr + 4;
    }
    if ( BYTE1(v17) & 4 )
    {
      *(_DWORD *)*addr = LODWORD(this->turn_speed);
      *addr = (char *)*addr + 4;
    }
    for ( j = this->actions.head_; j; j = j->llist_next )
    {
      if ( size >= 8 )
      {
        v19 = (unsigned int)j[3].llist_next & 0x7FFF;
        if ( j[4].llist_next )
          v19 |= 0x8000u;
        *(_WORD *)*addr = LOWORD(j[1].llist_next);
        v20 = (char *)*addr + 2;
        *addr = v20;
        *(_WORD *)v20 = v19;
        v21 = (char *)*addr + 2;
        *addr = v21;
        *(float *)v21 = *(float *)&j[2].llist_next;
        *addr = (char *)*addr + 4;
      }
    }
  }
  return v3;
}

//----- (0051EFC0) --------------------------------------------------------  // acclient.c:333116
int __thiscall RawMotionState::UnPack(RawMotionState *this, void **addr, unsigned int size)
{
  RawMotionState *v3; // edi@1
  int v4; // ecx@2
  int v5; // ecx@37
  int v6; // ebx@38
  void *v7; // eax@39
  void *v8; // ecx@40
  unsigned __int16 v9; // dx@43
  char *v10; // edx@43
  unsigned __int16 v11; // ax@43
  LListData *v12; // eax@44

  v3 = this;
  RawMotionState::Destroy(this);
  if ( size < 4 )
  {
    LOWORD(v4) = size;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v4 & 1 )
  {
    v3->current_holdkey = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->current_holdkey = 1;
  }
  if ( v4 & 2 )
  {
    v3->current_style = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->current_style = -2147483587;
  }
  if ( v4 & 4 )
  {
    v3->forward_command = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->forward_command = 1090519043;
  }
  if ( v4 & 8 )
  {
    v3->forward_holdkey = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->forward_holdkey = 0;
  }
  if ( v4 & 0x10 )
  {
    LODWORD(v3->forward_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->forward_speed) = 1065353216;
  }
  if ( v4 & 0x20 )
  {
    v3->sidestep_command = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->sidestep_command = 0;
  }
  if ( v4 & 0x40 )
  {
    v3->sidestep_holdkey = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->sidestep_holdkey = 0;
  }
  if ( (char)v4 >= 0 )
  {
    LODWORD(v3->sidestep_speed) = 1065353216;
  }
  else
  {
    LODWORD(v3->sidestep_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( BYTE1(v4) & 1 )
  {
    v3->turn_command = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->turn_command = 0;
  }
  if ( BYTE1(v4) & 2 )
  {
    v3->turn_holdkey = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->turn_holdkey = 0;
  }
  if ( BYTE1(v4) & 4 )
  {
    LODWORD(v3->turn_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->turn_speed) = 1065353216;
  }
  v5 = (unsigned __int16)v4 >> 11;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      v7 = operator new(0x14u);
      if ( v7 )
      {
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 1) = 0;
        *((_DWORD *)v7 + 2) = 1065353216;
        *((_DWORD *)v7 + 3) = 0;
        *((_DWORD *)v7 + 4) = 0;
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      if ( size >= 8 )
      {
        v9 = *(_WORD *)*addr;
        *addr = (char *)*addr + 2;
        *((_DWORD *)v8 + 1) = command_ids[v9];
        v10 = (char *)*addr + 2;
        v11 = *(_WORD *)*addr;
        *addr = v10;
        *((_DWORD *)v8 + 2) = *(_DWORD *)v10;
        *addr = (char *)*addr + 4;
        *((_DWORD *)v8 + 3) = v11 & 0x7FFF;
        *((_DWORD *)v8 + 4) = ((unsigned int)v11 >> 15) & 1;
      }
      v12 = v3->actions.tail_;
      if ( v12 )
        v12->llist_next = (LListData *)v8;
      else
        v3->actions.head_ = (LListData *)v8;
      --v6;
      v3->actions.tail_ = (LListData *)v8;
    }
    while ( v6 );
  }
  return 1;
}

//----- (0051F180) --------------------------------------------------------  // acclient.c:333286
void __thiscall InterpretedMotionState::InterpretedMotionState(InterpretedMotionState *this, InterpretedMotionState *rhs)
{
  this->vfptr = (PackObjVtbl *)&InterpretedMotionState::vftable;
  this->actions.head_ = 0;
  this->actions.tail_ = 0;
  InterpretedMotionState::operator=(this, (int)rhs);
}
// 7C7A60: using guessed type int (__thiscall *InterpretedMotionState::vftable)(void *, char);

//----- (0051F1B0) --------------------------------------------------------  // acclient.c:333296
void __thiscall InterpretedMotionState::~InterpretedMotionState(InterpretedMotionState *this)
{
  InterpretedMotionState *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&InterpretedMotionState::vftable;
  InterpretedMotionState::Destroy(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A60: using guessed type int (__thiscall *InterpretedMotionState::vftable)(void *, char);

//----- (0051F1D0) --------------------------------------------------------  // acclient.c:333309
unsigned int __thiscall InterpretedMotionState::Pack(InterpretedMotionState *this, void **addr, unsigned int size)
{
  signed int v3; // eax@1
  int v4; // edx@1
  unsigned int v5; // ebx@3
  int v6; // ebx@5
  int v7; // ebx@7
  int v8; // ebx@9
  int v9; // ebx@11
  int v10; // ebx@13
  LListData *v11; // edx@15
  __int16 i; // si@15
  int v13; // ebx@17
  int v14; // esi@18
  unsigned int result; // eax@20
  LListData *j; // ecx@37
  __int16 v17; // si@39
  char *v18; // ebx@41
  char *v19; // edi@41
  int v20; // esi@43
  int v21; // ecx@44

  v3 = 4;
  v4 = ((unsigned __int8)size ^ (this->current_style != -2147483587)) & 1;
  if ( ((unsigned __int8)v4 ^ (unsigned __int8)size) & 1 )
    v3 = 6;
  v5 = ((unsigned __int8)(v4 ^ size) ^ (unsigned __int8)(2 * (this->forward_command != 1090519043))) & 2 ^ v4 ^ size;
  if ( v5 & 2 )
    v3 += 2;
  v6 = ((unsigned __int8)v5 ^ (unsigned __int8)(8 * (this->sidestep_command != 0))) & 8 ^ v5;
  if ( v6 & 8 )
    v3 += 2;
  v7 = ((unsigned __int8)v6 ^ (unsigned __int8)(32 * (this->turn_command != 0))) & 0x20 ^ v6;
  if ( v7 & 0x20 )
    v3 += 2;
  v8 = ((unsigned __int8)v7 ^ (unsigned __int8)(4 * (LODWORD(this->forward_speed) != 1065353216))) & 4 ^ v7;
  if ( v8 & 4 )
    v3 += 4;
  v9 = ((unsigned __int8)v8 ^ (unsigned __int8)(16 * (LODWORD(this->sidestep_speed) != 1065353216))) & 0x10 ^ v8;
  if ( v9 & 0x10 )
    v3 += 4;
  v10 = ((unsigned __int8)v9 ^ (unsigned __int8)((LODWORD(this->turn_speed) != 1065353216) << 6)) & 0x40 ^ v9;
  if ( v10 & 0x40 )
    v3 += 4;
  v11 = this->actions.head_;
  for ( i = 0; v11; ++i )
  {
    v11 = v11->llist_next;
    v3 += 8;
  }
  v13 = ((unsigned __int16)v10 ^ (unsigned __int16)(i << 7)) & 0xF80 ^ v10;
  if ( v3 & 3 )
    v14 = 4 - (v3 & 3);
  else
    v14 = 0;
  result = v14 + v3;
  if ( size >= result )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v13;
      *addr = (char *)*addr + 4;
    }
    if ( v13 & 1 )
    {
      *(_WORD *)*addr = LOWORD(this->current_style);
      *addr = (char *)*addr + 2;
    }
    if ( v13 & 2 )
    {
      *(_WORD *)*addr = LOWORD(this->forward_command);
      *addr = (char *)*addr + 2;
    }
    if ( v13 & 8 )
    {
      *(_WORD *)*addr = LOWORD(this->sidestep_command);
      *addr = (char *)*addr + 2;
    }
    if ( v13 & 0x20 )
    {
      *(_WORD *)*addr = LOWORD(this->turn_command);
      *addr = (char *)*addr + 2;
    }
    if ( v13 & 4 )
    {
      *(_DWORD *)*addr = LODWORD(this->forward_speed);
      *addr = (char *)*addr + 4;
    }
    if ( v13 & 0x10 )
    {
      *(_DWORD *)*addr = LODWORD(this->sidestep_speed);
      *addr = (char *)*addr + 4;
    }
    if ( v13 & 0x40 )
    {
      *(_DWORD *)*addr = LODWORD(this->turn_speed);
      *addr = (char *)*addr + 4;
    }
    for ( j = this->actions.head_; j; j = j->llist_next )
    {
      if ( size >= 8 )
      {
        v17 = (unsigned int)j[3].llist_next & 0x7FFF;
        if ( j[4].llist_next )
          v17 |= 0x8000u;
        *(_WORD *)*addr = LOWORD(j[1].llist_next);
        v18 = (char *)*addr + 2;
        *addr = v18;
        *(_WORD *)v18 = v17;
        v19 = (char *)*addr + 2;
        *addr = v19;
        *(float *)v19 = *(float *)&j[2].llist_next;
        *addr = (char *)*addr + 4;
      }
    }
    v20 = (signed int)*addr % 4;
    if ( v20 )
    {
      v21 = 4 - v20;
      if ( 4 != v20 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v21;
          *addr = (char *)*addr + 1;
        }
        while ( v21 );
      }
    }
  }
  return result;
}

//----- (0051F400) --------------------------------------------------------  // acclient.c:333444
int __thiscall InterpretedMotionState::UnPack(InterpretedMotionState *this, void **addr, unsigned int size)
{
  InterpretedMotionState *v3; // edi@1
  unsigned int v4; // edx@2
  unsigned __int16 v5; // cx@5
  unsigned __int16 v6; // cx@8
  unsigned __int16 v7; // cx@11
  unsigned __int16 v8; // cx@14
  int v9; // edx@25
  int v10; // ebp@26
  void *v11; // eax@27
  void *v12; // ecx@28
  int v13; // edx@31
  char *v14; // edx@31
  unsigned __int16 v15; // ax@31
  LListData *v16; // eax@32
  int v17; // ecx@36
  int v18; // eax@37

  v3 = this;
  InterpretedMotionState::Destroy(this);
  if ( size < 4 )
  {
    v4 = size;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v4 & 1 )
  {
    v5 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v3->current_style = command_ids[v5];
  }
  else
  {
    v3->current_style = -2147483587;
  }
  if ( v4 & 2 )
  {
    v6 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v3->forward_command = command_ids[v6];
  }
  else
  {
    v3->forward_command = 1090519043;
  }
  if ( v4 & 8 )
  {
    v7 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v3->sidestep_command = command_ids[v7];
  }
  else
  {
    v3->sidestep_command = 0;
  }
  if ( v4 & 0x20 )
  {
    v8 = *(_WORD *)*addr;
    *addr = (char *)*addr + 2;
    v3->turn_command = command_ids[v8];
  }
  else
  {
    v3->turn_command = 0;
  }
  if ( v4 & 4 )
  {
    LODWORD(v3->forward_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->forward_speed) = 1065353216;
  }
  if ( v4 & 0x10 )
  {
    LODWORD(v3->sidestep_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->sidestep_speed) = 1065353216;
  }
  if ( v4 & 0x40 )
  {
    LODWORD(v3->turn_speed) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->turn_speed) = 1065353216;
  }
  v9 = (v4 >> 7) & 0x1F;
  if ( v9 )
  {
    v10 = v9;
    do
    {
      v11 = operator new(0x14u);
      if ( v11 )
      {
        *(_DWORD *)v11 = 0;
        *((_DWORD *)v11 + 1) = 0;
        *((_DWORD *)v11 + 2) = 1065353216;
        *((_DWORD *)v11 + 3) = 0;
        *((_DWORD *)v11 + 4) = 0;
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      if ( size >= 8 )
      {
        v13 = *(_WORD *)*addr;
        *addr = (char *)*addr + 2;
        *((_DWORD *)v12 + 1) = command_ids[v13];
        v14 = (char *)*addr + 2;
        v15 = *(_WORD *)*addr;
        *addr = v14;
        *((_DWORD *)v12 + 2) = *(_DWORD *)v14;
        *addr = (char *)*addr + 4;
        *((_DWORD *)v12 + 3) = v15 & 0x7FFF;
        *((_DWORD *)v12 + 4) = ((unsigned int)v15 >> 15) & 1;
      }
      v16 = v3->actions.tail_;
      if ( v16 )
        v16->llist_next = (LListData *)v12;
      else
        v3->actions.head_ = (LListData *)v12;
      --v10;
      v3->actions.tail_ = (LListData *)v12;
    }
    while ( v10 );
  }
  v17 = (signed int)*addr % 4;
  if ( v17 )
  {
    v18 = 4 - v17;
    if ( 4 != v17 )
    {
      do
      {
        *(_BYTE *)*addr = 0;
        --v18;
        *addr = (char *)*addr + 1;
      }
      while ( v18 );
    }
  }
  return 1;
}

//----- (0051F5C0) --------------------------------------------------------  // acclient.c:333603
void __thiscall RawMotionState::~RawMotionState(RawMotionState *this)
{
  RawMotionState *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&RawMotionState::vftable;
  RawMotionState::Destroy(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A4C: using guessed type int (__thiscall *RawMotionState::vftable)(void *, char);

//----- (0051F5E0) --------------------------------------------------------  // acclient.c:333616
InterpretedMotionState *__thiscall InterpretedMotionState::scalar_deleting_destructor(InterpretedMotionState *this, unsigned int a2)
{
  InterpretedMotionState *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&InterpretedMotionState::vftable;
  InterpretedMotionState::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A60: using guessed type int (__thiscall *InterpretedMotionState::vftable)(void *, char);

//----- (0051F610) --------------------------------------------------------  // acclient.c:333632
RawMotionState *__thiscall RawMotionState::scalar_deleting_destructor(RawMotionState *this, unsigned int a2)
{
  RawMotionState *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&RawMotionState::vftable;
  RawMotionState::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C7A4C: using guessed type int (__thiscall *RawMotionState::vftable)(void *, char);

//----- (006FD410) --------------------------------------------------------  // acclient.c:785514
void sub_6FD410()
{
  flt_844434 = 1000.0 + 1.0;
}

//----- (006FD430) --------------------------------------------------------  // acclient.c:785520
void sub_6FD430()
{
  flt_844438 = 24.0 * 8.0;
}

//----- (006FD450) --------------------------------------------------------  // acclient.c:785526
void sub_6FD450()
{
  flt_84443C = 24.0 * 0.5;
}

//----- (006FD470) --------------------------------------------------------  // acclient.c:785532
int _E101_18()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_10;
  INITIAL_MAX_DATA_RATE_79 = LOWEST_DATA_RATE_10;
  return result;
}

//----- (006FD480) --------------------------------------------------------  // acclient.c:785542
void sub_6FD480()
{
  flt_844448 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FD4A0) --------------------------------------------------------  // acclient.c:785548
void _E105_25()
{
  dbl_844450 = 1.0 / 30.0;
}

//----- (006FD4C0) --------------------------------------------------------  // acclient.c:785554
void _E107_19()
{
  dbl_844458 = 1.0 / 5.0;
}

//----- (006FD4E0) --------------------------------------------------------  // acclient.c:785560
int sub_6FD4E0()
{
  return atexit(nullsub_1136);
}

