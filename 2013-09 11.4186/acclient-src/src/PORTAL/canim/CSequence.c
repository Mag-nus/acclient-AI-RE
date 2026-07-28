/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSequence
   Object     : PORTAL\canim\CSequence.obj
   Functions  : 41
   Addresses  : 005247B0 - 007681F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005247B0) --------------------------------------------------------  // acclient.c:339640
int __thiscall AnimSequenceNode::get_pos_frame(AnimSequenceNode *this, long double frame_number)
{
  AnimSequenceNode *v2; // esi@1
  double v3; // st7@1

  v2 = this;
  v3 = _floor(frame_number);
  return AnimSequenceNode::get_pos_frame(v2, (unsigned __int64)v3);
}

//----- (00524820) --------------------------------------------------------  // acclient.c:339676
void __thiscall CSequence::set_object(CSequence *this, CPhysicsObj *_phys_obj)
{
  this->hook_obj = _phys_obj;
}

//----- (00524830) --------------------------------------------------------  // acclient.c:339682
void __thiscall CSequence::execute_hooks(CSequence *this, AnimFrame *animframe, int dir)
{
  CSequence *v3; // edi@1
  CAnimHook *i; // esi@2
  int v5; // eax@3

  v3 = this;
  if ( this->hook_obj )
  {
    for ( i = animframe->hooks; i; i = i->next_hook )
    {
      v5 = i->direction_;
      if ( !v5 || dir == v5 )
        CPhysicsObj::add_anim_hook(v3->hook_obj, i);
    }
  }
}

//----- (00524880) --------------------------------------------------------  // acclient.c:339701
void __thiscall CSequence::set_velocity(CSequence *this, AC1Legacy::Vector3 *v)
{
  this->velocity = *v;
}

//----- (005248A0) --------------------------------------------------------  // acclient.c:339707
void __thiscall CSequence::set_omega(CSequence *this, AC1Legacy::Vector3 *o)
{
  this->omega = *o;
}

//----- (005248C0) --------------------------------------------------------  // acclient.c:339713
void __thiscall CSequence::combine_physics(CSequence *this, AC1Legacy::Vector3 *v, AC1Legacy::Vector3 *o)
{
  this->velocity.x = this->velocity.x + v->x;
  this->velocity.y = v->y + this->velocity.y;
  this->velocity.z = v->z + this->velocity.z;
  this->omega.x = this->omega.x + o->x;
  this->omega.y = o->y + this->omega.y;
  this->omega.z = o->z + this->omega.z;
}

//----- (00524900) --------------------------------------------------------  // acclient.c:339724
void __thiscall CSequence::subtract_physics(CSequence *this, AC1Legacy::Vector3 *v, AC1Legacy::Vector3 *o)
{
  this->velocity.x = this->velocity.x - v->x;
  this->velocity.y = this->velocity.y - v->y;
  this->velocity.z = this->velocity.z - v->z;
  this->omega.x = this->omega.x - o->x;
  this->omega.y = this->omega.y - o->y;
  this->omega.z = this->omega.z - o->z;
}

//----- (00524940) --------------------------------------------------------  // acclient.c:339735
void __thiscall CSequence::multiply_cyclic_animation_fr(CSequence *this, float multiplier)
{
  AnimSequenceNode *i; // esi@1

  for ( i = this->first_cyclic; i; i = (AnimSequenceNode *)AnimSequenceNode::GetNext(i) )
    AnimSequenceNode::multiply_framerate(i, multiplier);
}

//----- (00524970) --------------------------------------------------------  // acclient.c:339744
AnimFrame *__thiscall CSequence::get_curr_animframe(CSequence *this)
{
  AnimSequenceNode *v1; // esi@1
  int v2; // ST10_4@2
  double v3; // st7@2
  AnimFrame *result; // eax@2

  v1 = this->curr_anim;
  if ( v1 )
  {
    v2 = HIDWORD(this->frame_number);
    v3 = _floor(this->frame_number);
    result = (AnimFrame *)AnimSequenceNode::get_part_frame(v1, (unsigned __int64)v3);
  }
  else
  {
    result = this->placement_frame;
  }
  return result;
}

//----- (005249B0) --------------------------------------------------------  // acclient.c:339766
void __thiscall CSequence::set_placement_frame(CSequence *this, AnimFrame *_placement_frame, unsigned int _id)
{
  this->placement_frame = _placement_frame;
  this->placement_frame_id = _id;
}

//----- (005249D0) --------------------------------------------------------  // acclient.c:339773
unsigned __int64 __thiscall CSequence::get_curr_frame_number(CSequence *this)
{
  return (unsigned __int64)_floor(this->frame_number);
}

//----- (005249F0) --------------------------------------------------------  // acclient.c:339779
void __thiscall CSequence::CSequence(CSequence *this)
{
  this->vfptr = (PackObjVtbl *)&CSequence::vftable;
  this->anim_list.head_ = 0;
  this->anim_list.tail_ = 0;
  this->first_cyclic = 0;
  LODWORD(this->velocity.x) = 0;
  LODWORD(this->velocity.y) = 0;
  LODWORD(this->velocity.z) = 0;
  LODWORD(this->omega.x) = 0;
  LODWORD(this->omega.y) = 0;
  LODWORD(this->omega.z) = 0;
  this->hook_obj = 0;
  *(_QWORD *)&this->frame_number = 0i64;
  this->curr_anim = 0;
  this->placement_frame = 0;
  this->placement_frame_id = 0;
  this->bIsTrivial = 0;
}
// 7C84D8: using guessed type int (__thiscall *CSequence::vftable)(void *, char);

//----- (00524A30) --------------------------------------------------------  // acclient.c:339801
void __thiscall CSequence::~CSequence(CSequence *this)
{
  CSequence *v1; // esi@1
  DLListData *v2; // eax@1
  DLListData *v3; // eax@2
  DLListData *v4; // ecx@3
  DLListData *v5; // ecx@5
  bool v6; // zf@5
  DLListData *v7; // ecx@9

  v1 = this;
  v2 = this->anim_list.head_;
  this->vfptr = (PackObjVtbl *)&CSequence::vftable;
  if ( v2 )
  {
    do
    {
      v3 = v1->anim_list.head_;
      if ( v3 )
      {
        v4 = v3->dllist_prev;
        if ( v4 )
        {
          v4->dllist_next = v3->dllist_next;
        }
        else
        {
          v5 = v3->dllist_next;
          v6 = v3->dllist_next == 0;
          v1->anim_list.head_ = v3->dllist_next;
          if ( !v6 )
            v5->dllist_prev = 0;
        }
        if ( v3->dllist_next )
        {
          v3->dllist_next->dllist_prev = v3->dllist_prev;
        }
        else
        {
          v7 = v1->anim_list.tail_->dllist_prev;
          v1->anim_list.tail_ = v7;
          if ( v7 )
            v7->dllist_next = 0;
        }
        v3->dllist_next = 0;
        v3->dllist_prev = 0;
        if ( v3 && v3 != (DLListData *)4 )
          ((void (__stdcall *)(_DWORD))v3[-1].dllist_prev->dllist_next)(1);
      }
    }
    while ( v1->anim_list.head_ );
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C84D8: using guessed type int (__thiscall *CSequence::vftable)(void *, char);

//----- (00524AB0) --------------------------------------------------------  // acclient.c:339859
void __thiscall CSequence::apply_physics(CSequence *this, Frame *frame, long double quantum, long double sign)
{
  double v5; // st7@1
  char v6; // c0@1
  Frame *v7; // eax@3
  double v8; // st5@3
  double v9; // st6@3
  double v10; // st5@3
  double v11; // st7@3
  AC1Legacy::Vector3 w; // [sp+0h] [bp-18h]@3
  float v13; // [sp+14h] [bp-4h]@3

  v5 = fabs(quantum);
  if ( v6 )
    v5 = -v5;
  v7 = frame;
  v8 = v5 * this->velocity.x;
  w.y = v5 * this->velocity.y;
  w.z = v5 * this->velocity.z;
  frame->m_fOrigin.x = v8 + frame->m_fOrigin.x;
  v7->m_fOrigin.y = w.y + v7->m_fOrigin.y;
  v7->m_fOrigin.z = w.z + v7->m_fOrigin.z;
  v9 = v5 * this->omega.x;
  v10 = v5;
  v11 = v5 * this->omega.y;
  v13 = v10 * this->omega.z;
  w.z = v13;
  w.x = v9;
  w.y = v11;
  Frame::rotate(frame, &w);
}

//----- (00524B40) --------------------------------------------------------  // acclient.c:339892
void __thiscall CSequence::apricot(CSequence *this)
{
  CSequence *v1; // esi@1
  DLListData *v2; // eax@1
  int v3; // ecx@2
  int v4; // eax@7
  int v5; // edx@9
  DLListData *v6; // edx@11
  DLListData *v7; // edx@15
  DLListData *v8; // eax@19

  v1 = this;
  v2 = this->anim_list.head_;
  if ( v2 )
    v3 = (int)&v2[-1].dllist_prev;
  else
    v3 = 0;
  while ( (AnimSequenceNode *)v3 != v1->curr_anim )
  {
    if ( (AnimSequenceNode *)v3 == v1->first_cyclic )
      break;
    v4 = v3 ? v3 + 4 : 0;
    v5 = *(_DWORD *)(v4 + 4);
    if ( v5 )
    {
      *(_DWORD *)v5 = *(_DWORD *)v4;
    }
    else
    {
      v6 = v1->anim_list.head_->dllist_next;
      v1->anim_list.head_ = v6;
      if ( v6 )
        v6->dllist_prev = 0;
    }
    if ( *(_DWORD *)v4 )
    {
      *(_DWORD *)(*(_DWORD *)v4 + 4) = *(_DWORD *)(v4 + 4);
    }
    else
    {
      v7 = v1->anim_list.tail_->dllist_prev;
      v1->anim_list.tail_ = v7;
      if ( v7 )
        v7->dllist_next = 0;
    }
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    if ( v3 )
      (**(void (__stdcall ***)(_DWORD))v3)(1);
    v8 = v1->anim_list.head_;
    v3 = (int)(v8 ? &v8[-1].dllist_prev : 0);
  }
}

//----- (00524BD0) --------------------------------------------------------  // acclient.c:339947
BOOL __thiscall CSequence::has_anims(CSequence *this)
{
  return this->anim_list.head_ != 0;
}

//----- (00524BE0) --------------------------------------------------------  // acclient.c:339953
void __thiscall CSequence::remove_link_animations(CSequence *this, unsigned int n)
{
  unsigned int v2; // ebp@1
  CSequence *v3; // esi@1
  AnimSequenceNode *v4; // ecx@4
  int v5; // eax@6
  int v6; // edx@7
  int v7; // edi@9
  DLListData **v8; // ecx@11
  DLListData *v9; // edi@11
  bool v10; // zf@11
  DLListData *v11; // edi@15

  v2 = 0;
  v3 = this;
  if ( n )
  {
    do
    {
      if ( !AnimSequenceNode::GetPrev(v3->first_cyclic) )
        break;
      if ( (AnimSequenceNode *)AnimSequenceNode::GetPrev(v3->first_cyclic) == v3->curr_anim )
      {
        v4 = v3->first_cyclic;
        v3->curr_anim = v4;
        if ( v4 )
          v3->frame_number = AnimSequenceNode::get_starting_frame(v4);
      }
      v5 = AnimSequenceNode::GetPrev(v3->first_cyclic);
      v6 = v5 ? v5 + 4 : 0;
      v7 = *(_DWORD *)(v6 + 4);
      if ( v7 )
      {
        *(_DWORD *)v7 = *(_DWORD *)v6;
      }
      else
      {
        v8 = &v3->anim_list.head_->dllist_next;
        v9 = *v8;
        v10 = *v8 == 0;
        v3->anim_list.head_ = *v8;
        if ( !v10 )
          v9->dllist_prev = 0;
      }
      if ( *(_DWORD *)v6 )
      {
        *(_DWORD *)(*(_DWORD *)v6 + 4) = *(_DWORD *)(v6 + 4);
      }
      else
      {
        v11 = v3->anim_list.tail_->dllist_prev;
        v3->anim_list.tail_ = v11;
        if ( v11 )
          v11->dllist_next = 0;
      }
      *(_DWORD *)v6 = 0;
      *(_DWORD *)(v6 + 4) = 0;
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      ++v2;
    }
    while ( v2 < n );
  }
}

//----- (00524CA0) --------------------------------------------------------  // acclient.c:340019
void __thiscall CSequence::remove_all_link_animations(CSequence *this)
{
  CSequence *v1; // esi@1
  AnimSequenceNode *v2; // ecx@1
  AnimSequenceNode *v3; // ecx@4
  int v4; // eax@6
  int v5; // edx@7
  int v6; // edi@9
  DLListData **v7; // ecx@11
  DLListData *v8; // edi@11
  bool v9; // zf@11
  DLListData *v10; // edi@15

  v1 = this;
  v2 = this->first_cyclic;
  if ( v2 && AnimSequenceNode::GetPrev(v2) )
  {
    do
    {
      if ( (AnimSequenceNode *)AnimSequenceNode::GetPrev(v1->first_cyclic) == v1->curr_anim )
      {
        v3 = v1->first_cyclic;
        v1->curr_anim = v3;
        if ( v3 )
          v1->frame_number = AnimSequenceNode::get_starting_frame(v3);
      }
      v4 = AnimSequenceNode::GetPrev(v1->first_cyclic);
      if ( v4 )
        v5 = v4 + 4;
      else
        v5 = 0;
      v6 = *(_DWORD *)(v5 + 4);
      if ( v6 )
      {
        *(_DWORD *)v6 = *(_DWORD *)v5;
      }
      else
      {
        v7 = &v1->anim_list.head_->dllist_next;
        v8 = *v7;
        v9 = *v7 == 0;
        v1->anim_list.head_ = *v7;
        if ( !v9 )
          v8->dllist_prev = 0;
      }
      if ( *(_DWORD *)v5 )
      {
        *(_DWORD *)(*(_DWORD *)v5 + 4) = *(_DWORD *)(v5 + 4);
      }
      else
      {
        v10 = v1->anim_list.tail_->dllist_prev;
        v1->anim_list.tail_ = v10;
        if ( v10 )
          v10->dllist_next = 0;
      }
      *(_DWORD *)v5 = 0;
      *(_DWORD *)(v5 + 4) = 0;
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    while ( AnimSequenceNode::GetPrev(v1->first_cyclic) );
  }
}

//----- (00524D50) --------------------------------------------------------  // acclient.c:340085
void __thiscall CSequence::clear_physics(CSequence *this)
{
  char *v1; // eax@1
  char *v2; // ecx@1

  v1 = (char *)&this->velocity;
  *(_DWORD *)v1 = 0;
  *((_DWORD *)v1 + 1) = 0;
  *((_DWORD *)v1 + 2) = 0;
  v2 = (char *)&this->omega;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
}

//----- (00524DC0) --------------------------------------------------------  // acclient.c:340101
void __thiscall CSequence::clear_animations(CSequence *this)
{
  CSequence *v1; // esi@1
  DLListData *v2; // eax@2
  DLListData *v3; // ecx@3
  DLListData *v4; // ecx@5
  bool v5; // zf@5
  DLListData *v6; // ecx@9

  v1 = this;
  while ( v1->anim_list.head_ )
  {
    v2 = v1->anim_list.head_;
    if ( v2 )
    {
      v3 = v2->dllist_prev;
      if ( v3 )
      {
        v3->dllist_next = v2->dllist_next;
      }
      else
      {
        v4 = v2->dllist_next;
        v5 = v2->dllist_next == 0;
        v1->anim_list.head_ = v2->dllist_next;
        if ( !v5 )
          v4->dllist_prev = 0;
      }
      if ( v2->dllist_next )
      {
        v2->dllist_next->dllist_prev = v2->dllist_prev;
      }
      else
      {
        v6 = v1->anim_list.tail_->dllist_prev;
        v1->anim_list.tail_ = v6;
        if ( v6 )
          v6->dllist_next = 0;
      }
      v2->dllist_next = 0;
      v2->dllist_prev = 0;
      if ( v2 && v2 != (DLListData *)4 )
        ((void (__stdcall *)(_DWORD))v2[-1].dllist_prev->dllist_next)(1);
    }
  }
  v1->first_cyclic = 0;
  LODWORD(v1->frame_number) = 0;
  HIDWORD(v1->frame_number) = 0;
  v1->curr_anim = 0;
}

//----- (00524E40) --------------------------------------------------------  // acclient.c:340153
void __thiscall CSequence::remove_cyclic_anims(CSequence *this)
{
  CSequence *v1; // esi@1
  AnimSequenceNode *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@7
  int v5; // ecx@9
  DLListData *v6; // ecx@11
  DLListData *v7; // ecx@15
  DLListData *v8; // eax@20
  int temp; // [sp+Ch] [bp-4h]@6

  v1 = this;
  v2 = this->first_cyclic;
  if ( v2 )
  {
    do
    {
      if ( v1->curr_anim == v2 )
      {
        v3 = AnimSequenceNode::GetPrev(v2);
        v1->curr_anim = (AnimSequenceNode *)v3;
        if ( v3 )
        {
          v1->frame_number = AnimSequenceNode::get_ending_frame((AnimSequenceNode *)v3);
        }
        else
        {
          LODWORD(v1->frame_number) = 0;
          HIDWORD(v1->frame_number) = 0;
        }
      }
      temp = AnimSequenceNode::GetNext(v2);
      if ( v2 )
        v4 = (int)&v2->dllist_next;
      else
        v4 = 0;
      v5 = *(_DWORD *)(v4 + 4);
      if ( v5 )
      {
        *(_DWORD *)v5 = *(_DWORD *)v4;
      }
      else
      {
        v6 = v1->anim_list.head_->dllist_next;
        v1->anim_list.head_ = v6;
        if ( v6 )
          v6->dllist_prev = 0;
      }
      if ( *(_DWORD *)v4 )
      {
        *(_DWORD *)(*(_DWORD *)v4 + 4) = *(_DWORD *)(v4 + 4);
      }
      else
      {
        v7 = v1->anim_list.tail_->dllist_prev;
        v1->anim_list.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      *(_DWORD *)v4 = 0;
      *(_DWORD *)(v4 + 4) = 0;
      if ( v2 )
        v2->vfptr->__vecDelDtor((PackObj *)v2, 1u);
      v2 = (AnimSequenceNode *)temp;
    }
    while ( temp );
  }
  v8 = v1->anim_list.tail_;
  if ( v8 )
    v1->first_cyclic = (AnimSequenceNode *)&v8[-1].dllist_prev;
  else
    v1->first_cyclic = 0;
}

//----- (00524F20) --------------------------------------------------------  // acclient.c:340229
int __thiscall CSequence::pack_size(CSequence *this, unsigned int *bitfield, unsigned int *num_anims)
{
  unsigned int *v3; // ebx@1
  CSequence *v4; // ebp@1
  unsigned int *v5; // ecx@1
  DLListData *v6; // eax@1
  signed int v7; // edi@1
  int v8; // esi@2
  int v9; // edi@5
  int v10; // edi@7

  v3 = num_anims;
  v4 = this;
  v5 = bitfield;
  *bitfield = 0;
  *v3 = 0;
  v6 = v4->anim_list.head_;
  num_anims = 0;
  v7 = 4;
  if ( !v6 )
    goto LABEL_18;
  v8 = (int)&v6[-1].dllist_prev;
  if ( v6 == (DLListData *)4 )
    goto LABEL_18;
  do
  {
    v7 += (*(int (__thiscall **)(int, unsigned int **, _DWORD))(*(_DWORD *)v8 + 12))(v8, &num_anims, 0);
    ++*v3;
    v8 = AnimSequenceNode::GetNext((AnimSequenceNode *)v8);
  }
  while ( v8 );
  v5 = bitfield;
  if ( *v3 )
    v9 = v7 + 16;
  else
LABEL_18:
    v9 = v7 + 4;
  v10 = v9 + 4;
  if ( fabs(v4->velocity.x) > 0.00019999999
    || fabs(v4->velocity.y) > 0.00019999999
    || fabs(v4->velocity.z) > 0.00019999999 )
  {
    v10 += 12;
    *v5 |= 1u;
  }
  if ( fabs(v4->omega.x) > 0.00019999999 || fabs(v4->omega.y) > 0.00019999999 || fabs(v4->omega.z) > 0.00019999999 )
  {
    v10 += 12;
    *v5 |= 2u;
  }
  return v10;
}

//----- (00525020) --------------------------------------------------------  // acclient.c:340283
int __thiscall CSequence::Pack(CSequence *this, void **addr, unsigned int size)
{
  CSequence *v3; // edi@1
  int v4; // edx@1
  unsigned int v5; // ebp@2
  DLListData *v6; // eax@2
  int v7; // ebx@3
  void *v8; // ecx@6
  int v9; // ebx@7
  DLListData *v10; // eax@7
  AnimSequenceNode *v11; // ebp@7
  int v12; // eax@8
  int v13; // eax@11
  DLListData *v14; // eax@12
  AnimSequenceNode *v15; // ebp@12
  int v16; // ebx@12
  int v17; // eax@13
  unsigned int v18; // ecx@20
  char *v19; // eax@20
  char *v20; // eax@20
  char *v21; // eax@22
  char *v22; // ebp@22
  char *v23; // ebx@25
  char *v24; // ecx@25
  unsigned int retval; // [sp+8h] [bp-Ch]@1
  unsigned int num_anims; // [sp+Ch] [bp-8h]@1
  unsigned int bitfield; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = CSequence::pack_size(this, &bitfield, &num_anims);
  retval = v4;
  if ( size >= v4 )
  {
    v5 = num_anims;
    *(_DWORD *)*addr = num_anims;
    *addr = (char *)*addr + 4;
    v6 = v3->anim_list.head_;
    if ( v6 )
    {
      v7 = (int)&v6[-1].dllist_prev;
      if ( v6 != (DLListData *)4 )
      {
        do
        {
          (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v7 + 12))(v7, addr, size);
          v7 = AnimSequenceNode::GetNext((AnimSequenceNode *)v7);
        }
        while ( v7 );
        v4 = retval;
      }
    }
    v8 = *addr;
    if ( v5 )
    {
      v9 = 0;
      *(double *)v8 = v3->frame_number;
      *addr = (char *)*addr + 8;
      v10 = v3->anim_list.head_;
      v11 = v3->first_cyclic;
      if ( v10 && (v12 = (int)&v10[-1].dllist_prev) != 0 )
      {
        while ( (AnimSequenceNode *)v12 != v11 )
        {
          ++v9;
          v12 = AnimSequenceNode::GetNext((AnimSequenceNode *)v12);
          if ( !v12 )
            goto LABEL_11;
        }
        v13 = v9;
      }
      else
      {
LABEL_11:
        v13 = 0;
      }
      *(_DWORD *)*addr = v13;
      *addr = (char *)*addr + 4;
      v14 = v3->anim_list.head_;
      v15 = v3->curr_anim;
      v16 = 0;
      if ( v14 && (v17 = (int)&v14[-1].dllist_prev) != 0 )
      {
        while ( (AnimSequenceNode *)v17 != v15 )
        {
          ++v16;
          v17 = AnimSequenceNode::GetNext((AnimSequenceNode *)v17);
          if ( !v17 )
            goto LABEL_16;
        }
      }
      else
      {
LABEL_16:
        v16 = 0;
      }
      v4 = retval;
      *(_DWORD *)*addr = v16;
    }
    else
    {
      *(_DWORD *)v8 = v3->placement_frame_id;
    }
    v18 = bitfield;
    v19 = (char *)*addr + 4;
    *addr = v19;
    *(_DWORD *)v19 = v18;
    v20 = (char *)*addr + 4;
    *addr = v20;
    if ( v18 & 1 && size >= 0xC )
    {
      *(_DWORD *)v20 = LODWORD(v3->velocity.x);
      v21 = (char *)*addr + 4;
      *addr = v21;
      *(float *)v21 = v3->velocity.y;
      v22 = (char *)*addr + 4;
      *addr = v22;
      *(float *)v22 = v3->velocity.z;
      v20 = (char *)*addr + 4;
      *addr = v20;
    }
    if ( v18 & 2 && size >= 0xC )
    {
      *(_DWORD *)v20 = LODWORD(v3->omega.x);
      v23 = (char *)*addr + 4;
      *addr = v23;
      *(float *)v23 = v3->omega.y;
      v24 = (char *)*addr + 4;
      *addr = v24;
      *(float *)v24 = v3->omega.z;
      *addr = (char *)*addr + 4;
    }
  }
  return v4;
}

//----- (00525180) --------------------------------------------------------  // acclient.c:340419
void __thiscall Frame::combine(Frame *this, Frame *_f1, AFrame *_f2)
{
  Frame *v3; // eax@1
  AFrame *v4; // edx@1
  char *v5; // esi@1
  float v6; // ST18_4@1
  float v7; // ST1C_4@1
  double v8; // st7@1
  float v9; // ST20_4@1
  float new_qz; // ST0C_4@1
  float new_qy; // ST08_4@1
  float new_qx; // ST04_4@1
  float new_qw; // ST00_4@1

  v3 = _f1;
  v4 = _f2;
  v5 = (char *)&this->m_fOrigin;
  v6 = _f1->m_fl2gv[6] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[0] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[3] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.x;
  v7 = _f1->m_fl2gv[7] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[1] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[4] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.y;
  v8 = _f1->m_fl2gv[8] * _f2->m_fOrigin.z
     + _f1->m_fl2gv[2] * _f2->m_fOrigin.x
     + _f1->m_fl2gv[5] * _f2->m_fOrigin.y
     + _f1->m_fOrigin.z;
  *(float *)v5 = v6;
  *((float *)v5 + 1) = v7;
  v9 = v8;
  *((float *)v5 + 2) = v9;
  new_qz = v3->qx * v4->qy + v4->qz * v3->qw - v3->qy * v4->qx + v3->qz * v4->qw;
  new_qy = v4->qy * v3->qw - v3->qx * v4->qz + v3->qz * v4->qx + v3->qy * v4->qw;
  new_qx = v3->qx * v4->qw + v3->qw * v4->qx + v4->qz * v3->qy - v4->qy * v3->qz;
  new_qw = v3->qw * v4->qw - v3->qx * v4->qx - v4->qy * v3->qy - _f2->qz * _f1->qz;
  Frame::set_rotate(this, new_qw, new_qx, new_qy, new_qz);
}

//----- (00525290) --------------------------------------------------------  // acclient.c:340460
CSequence *__thiscall CSequence::scalar_deleting_destructor(CSequence *this, unsigned int a2)
{
  CSequence *v2; // esi@1

  v2 = this;
  CSequence::~CSequence(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005252B0) --------------------------------------------------------  // acclient.c:340472
void __thiscall CSequence::advance_to_next_animation(CSequence *this, long double quantum, AnimSequenceNode **_curr_anim, long double *_frame_number, Frame *retval)
{
  AnimSequenceNode *v5; // ecx@1
  Frame *v6; // edi@2
  __int64 v7; // kr00_8@5
  int v8; // eax@5
  double v9; // st7@7
  int v10; // eax@14
  __int64 v11; // kr08_8@14
  int v12; // eax@14
  int v13; // eax@20
  __int64 v14; // kr10_8@20
  int v15; // eax@20
  double v16; // st7@22
  int v17; // eax@24
  DLListData *v18; // eax@25
  int v19; // edx@31
  __int64 v20; // kr18_8@31
  int v21; // eax@31
  double v22; // st7@34
  long double v23; // [sp+8h] [bp-18h]@16
  CSequence *v24; // [sp+1Ch] [bp-4h]@1

  v24 = this;
  v5 = *_curr_anim;
  if ( quantum < 0.0 )
  {
    v6 = retval;
    if ( MD_Data_Fade::GetDuration(v5) >= 0.0 && retval )
    {
      if ( (*_curr_anim)->anim->pos_frames )
      {
        v13 = *((_DWORD *)_frame_number + 1);
        v14 = *(_QWORD *)_frame_number;
        v15 = AnimSequenceNode::get_pos_frame(*_curr_anim, *_frame_number);
        Frame::subtract1(retval, retval, (AFrame *)v15);
      }
      if ( fabs(MD_Data_Fade::GetDuration(*_curr_anim)) > 0.00019999999 )
      {
        v16 = MD_Data_Fade::GetDuration(*_curr_anim);
        CSequence::apply_physics(v24, retval, 1.0 / v16, quantum);
      }
    }
    if ( AnimSequenceNode::GetPrev(*_curr_anim) )
    {
      v17 = AnimSequenceNode::GetPrev(*_curr_anim);
    }
    else
    {
      v18 = v24->anim_list.tail_;
      if ( v18 )
        v17 = (int)&v18[-1].dllist_prev;
      else
        v17 = 0;
    }
    *_curr_anim = (AnimSequenceNode *)v17;
    *_frame_number = AnimSequenceNode::get_ending_frame((AnimSequenceNode *)v17);
    if ( MD_Data_Fade::GetDuration(*_curr_anim) < 0.0 && retval )
    {
      if ( (*_curr_anim)->anim->pos_frames )
      {
        v19 = *((_DWORD *)_frame_number + 1);
        v20 = *(_QWORD *)_frame_number;
        v21 = AnimSequenceNode::get_pos_frame(*_curr_anim, *_frame_number);
        Frame::combine(retval, retval, (AFrame *)v21);
      }
      if ( fabs(MD_Data_Fade::GetDuration(*_curr_anim)) > 0.00019999999 )
      {
        v23 = quantum;
        goto LABEL_34;
      }
    }
  }
  else
  {
    v6 = retval;
    if ( MD_Data_Fade::GetDuration(v5) < 0.0 && retval )
    {
      if ( (*_curr_anim)->anim->pos_frames )
      {
        v7 = *(_QWORD *)_frame_number;
        v8 = AnimSequenceNode::get_pos_frame(*_curr_anim, *_frame_number);
        Frame::subtract1(retval, retval, (AFrame *)v8);
      }
      if ( fabs(MD_Data_Fade::GetDuration(*_curr_anim)) > 0.00019999999 )
      {
        v9 = MD_Data_Fade::GetDuration(*_curr_anim);
        CSequence::apply_physics(v24, retval, 1.0 / v9, quantum);
      }
    }
    if ( AnimSequenceNode::GetNext(*_curr_anim) )
      *_curr_anim = (AnimSequenceNode *)AnimSequenceNode::GetNext(*_curr_anim);
    else
      *_curr_anim = v24->first_cyclic;
    *_frame_number = AnimSequenceNode::get_starting_frame(*_curr_anim);
    if ( MD_Data_Fade::GetDuration(*_curr_anim) > 0.0 && retval )
    {
      if ( (*_curr_anim)->anim->pos_frames )
      {
        v10 = *((_DWORD *)_frame_number + 1);
        v11 = *(_QWORD *)_frame_number;
        v12 = AnimSequenceNode::get_pos_frame(*_curr_anim, *_frame_number);
        Frame::combine(retval, retval, (AFrame *)v12);
      }
      if ( fabs(MD_Data_Fade::GetDuration(*_curr_anim)) > 0.00019999999 )
      {
        v23 = quantum;
LABEL_34:
        v22 = MD_Data_Fade::GetDuration(*_curr_anim);
        CSequence::apply_physics(v24, v6, 1.0 / v22, v23);
        return;
      }
    }
  }
}

//----- (00525510) --------------------------------------------------------  // acclient.c:340589
void __thiscall CSequence::append_animation(CSequence *this, AnimData *new_data)
{
  CSequence *v2; // edi@1
  AnimSequenceNode *v3; // eax@1
  AppraisalProfile *v4; // eax@2
  AppraisalProfile *v5; // esi@2
  DLListData *v6; // eax@8
  DLListData *v7; // eax@10
  int v8; // eax@11
  DLListData *v9; // ebx@14

  v2 = this;
  v3 = (AnimSequenceNode *)operator new(0x1Cu);
  if ( v3 )
  {
    AnimSequenceNode::AnimSequenceNode(v3, new_data);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( AnimSequenceNode::has_anim(v5) )
  {
    if ( v5 )
      v6 = (DLListData *)&v5->success_flag;
    else
      v6 = 0;
    DLListBase::InsertAfter((DLListBase *)&v2->anim_list.head_, v6, v2->anim_list.tail_);
    v7 = v2->anim_list.tail_;
    if ( v7 )
      v8 = (int)&v7[-1].dllist_prev;
    else
      v8 = 0;
    v2->first_cyclic = (AnimSequenceNode *)v8;
    if ( !v2->curr_anim )
    {
      v9 = v2->anim_list.head_;
      if ( v9 )
      {
        v2->curr_anim = (AnimSequenceNode *)&v9[-1].dllist_prev;
        v2->frame_number = AnimSequenceNode::get_starting_frame((AnimSequenceNode *)&v9[-1].dllist_prev);
      }
      else
      {
        v2->curr_anim = 0;
        v2->frame_number = AnimSequenceNode::get_starting_frame(0);
      }
    }
  }
  else if ( v5 )
  {
    v5->vfptr->__vecDelDtor((PackObj *)v5, 1u);
  }
}

//----- (005255B0) --------------------------------------------------------  // acclient.c:340646
void __thiscall CSequence::clear(CSequence *this)
{
  CSequence *v1; // esi@1

  v1 = this;
  CSequence::clear_animations(this);
  CSequence::clear_physics(v1);
  v1->placement_frame = 0;
  v1->placement_frame_id = 0;
}

//----- (005255D0) --------------------------------------------------------  // acclient.c:340658
void __thiscall CSequence::update_internal(CSequence *this, long double quantum, AnimSequenceNode **_curr_anim, long double *_frame_number, Frame *retval)
{
  double v5; // ST0C_8@2
  int v6; // ebx@2
  double v7; // ST44_8@3
  long double v8; // st7@4
  int v9; // ecx@10
  __int64 j; // kr00_8@10
  int v11; // eax@13
  int v12; // eax@16
  double v13; // ST44_8@19
  long double v14; // st7@20
  int v15; // edx@26
  __int64 k; // kr08_8@26
  int v17; // eax@29
  int v18; // eax@32
  CPhysicsObj *v19; // ecx@34
  DLListData *v20; // eax@35
  int v21; // eax@36
  CSequence *v22; // [sp+1Ch] [bp-2Ch]@1
  int advance_anim; // [sp+20h] [bp-28h]@2
  double i; // [sp+28h] [bp-20h]@2
  long double framerate; // [sp+30h] [bp-18h]@2
  double time_left; // [sp+38h] [bp-10h]@2
  double frame_quantum; // [sp+40h] [bp-8h]@2

  v22 = this;
  while ( 1 )
  {
    framerate = MD_Data_Fade::GetDuration(*_curr_anim);
    HIDWORD(v5) = *((_DWORD *)_frame_number + 1);
    frame_quantum = framerate * quantum;
    LODWORD(v5) = *(_DWORD *)_frame_number;
    advance_anim = 0;
    v6 = (unsigned __int64)_floor(v5);
    time_left = 0.0;
    i = frame_quantum + *_frame_number;
    *_frame_number = i;
    if ( frame_quantum > 0.0 )
    {
      v7 = _floor(i);
      if ( (double)(signed int)AnimSequenceNode::get_high_frame((ChatRoomTracker *)*_curr_anim) < v7 )
      {
        v8 = *_frame_number - (double)(signed int)AnimSequenceNode::get_high_frame((ChatRoomTracker *)*_curr_anim) - 1.0;
        if ( v8 < 0.0 )
          v8 = 0.0;
        if ( fabs(framerate) <= 0.00019999999 )
          time_left = 0.0;
        else
          time_left = v8 / framerate;
        advance_anim = 1;
        *_frame_number = (double)(signed int)AnimSequenceNode::get_high_frame((ChatRoomTracker *)*_curr_anim);
      }
      v9 = *((_DWORD *)_frame_number + 1);
      for ( j = *(_QWORD *)_frame_number; _floor(*_frame_number) > (double)v6; ++v6 )
      {
        if ( retval )
        {
          if ( (*_curr_anim)->anim->pos_frames )
          {
            v11 = AnimSequenceNode::get_pos_frame(*_curr_anim, v6);
            Frame::combine(retval, retval, (AFrame *)v11);
          }
          if ( fabs(framerate) > 0.00019999999 )
            CSequence::apply_physics(v22, retval, 1.0 / framerate, quantum);
        }
        v12 = AnimSequenceNode::get_part_frame(*_curr_anim, v6);
        CSequence::execute_hooks(v22, (AnimFrame *)v12, 1);
      }
      goto LABEL_33;
    }
    if ( frame_quantum >= 0.0 )
      break;
    v13 = _floor(i);
    if ( (double)(signed int)PhysicsDesc::get_animframe_id((ChatRoomTracker *)*_curr_anim) > v13 )
    {
      v14 = *_frame_number - (double)(signed int)PhysicsDesc::get_animframe_id((ChatRoomTracker *)*_curr_anim);
      if ( v14 > 0.0 )
        v14 = 0.0;
      if ( fabs(framerate) <= 0.00019999999 )
        time_left = 0.0;
      else
        time_left = v14 / framerate;
      advance_anim = 1;
      *_frame_number = (double)(signed int)PhysicsDesc::get_animframe_id((ChatRoomTracker *)*_curr_anim);
    }
    v15 = *((_DWORD *)_frame_number + 1);
    for ( k = *(_QWORD *)_frame_number; _floor(*_frame_number) < (double)v6; --v6 )
    {
      if ( retval )
      {
        if ( (*_curr_anim)->anim->pos_frames )
        {
          v17 = AnimSequenceNode::get_pos_frame(*_curr_anim, v6);
          Frame::subtract1(retval, retval, (AFrame *)v17);
        }
        if ( fabs(framerate) > 0.00019999999 )
          CSequence::apply_physics(v22, retval, 1.0 / framerate, quantum);
      }
      v18 = AnimSequenceNode::get_part_frame(*_curr_anim, v6);
      CSequence::execute_hooks(v22, (AnimFrame *)v18, -1);
    }
LABEL_33:
    if ( !advance_anim )
      return;
    v19 = v22->hook_obj;
    if ( v19 )
    {
      v20 = v22->anim_list.head_;
      if ( v20 )
        v21 = (int)&v20[-1].dllist_prev;
      else
        v21 = 0;
      if ( (AnimSequenceNode *)v21 != v22->first_cyclic )
        CPhysicsObj::add_anim_hook(v19, &anim_done_hook);
    }
    CSequence::advance_to_next_animation(v22, quantum, _curr_anim, _frame_number, retval);
    quantum = time_left;
  }
  if ( retval && fabs(quantum) > 0.00019999999 )
    CSequence::apply_physics(v22, retval, quantum, quantum);
}

//----- (005259D0) --------------------------------------------------------  // acclient.c:340782
int __thiscall CSequence::UnPack(CSequence *this, void **addr, unsigned int size)
{
  CSequence *v3; // edi@1
  void **v4; // esi@1
  void **v5; // ecx@1
  bool v6; // zf@1
  AnimSequenceNode *v7; // eax@3
  int v8; // eax@4
  int v9; // ebx@4
  DLListData *v10; // ecx@6
  int v11; // eax@6
  DLListData *v12; // edx@10
  void *v13; // eax@16
  int v14; // ebx@17
  int v15; // ecx@17
  DLListData *v16; // eax@17
  int v17; // eax@18
  int v18; // ebx@21
  int v19; // ecx@23
  DLListData *v20; // eax@23
  int v21; // eax@24
  int v22; // ebx@27
  int v23; // ecx@31
  int v24; // eax@31
  int v25; // eax@33
  int v26; // ebx@33
  int v27; // edx@36
  int v28; // ecx@36
  unsigned int num_anims; // [sp+8h] [bp-4h]@1
  void **addra; // [sp+10h] [bp+4h]@2

  v3 = this;
  CSequence::clear_animations(this);
  CSequence::clear_physics(v3);
  v4 = addr;
  v3->placement_frame = 0;
  v3->placement_frame_id = 0;
  v5 = *(void ***)*addr;
  v6 = v5 == 0;
  num_anims = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  if ( v5 )
  {
    addra = v5;
    do
    {
      v7 = (AnimSequenceNode *)operator new(0x1Cu);
      if ( v7 )
      {
        AnimSequenceNode::AnimSequenceNode(v7);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v9 + 16))(v9, v4, size);
      v10 = v3->anim_list.tail_;
      v11 = v9 + 4;
      if ( v10 )
      {
        *(_DWORD *)v11 = v10->dllist_next;
        if ( v10->dllist_next )
        {
          v10->dllist_next->dllist_prev = (DLListData *)v11;
          v10->dllist_next = (DLListData *)v11;
        }
        else
        {
          v3->anim_list.tail_ = (DLListData *)v11;
          v10->dllist_next = (DLListData *)v11;
        }
      }
      else
      {
        *(_DWORD *)v11 = v3->anim_list.head_;
        v12 = v3->anim_list.head_;
        if ( v12 )
          v12->dllist_prev = (DLListData *)v11;
        else
          v3->anim_list.tail_ = (DLListData *)v11;
        v3->anim_list.head_ = (DLListData *)v11;
      }
      *(_DWORD *)(v9 + 8) = v10;
      addra = (void **)((char *)addra - 1);
    }
    while ( addra );
    v6 = num_anims == 0;
  }
  v13 = *v4;
  if ( v6 )
  {
    v3->placement_frame_id = *(_DWORD *)v13;
    *v4 = (char *)*v4 + 4;
  }
  else
  {
    LODWORD(v3->frame_number) = *(_DWORD *)v13;
    HIDWORD(v3->frame_number) = *((_DWORD *)v13 + 1);
    v14 = (int)((char *)*v4 + 8);
    *v4 = (void *)v14;
    v15 = *(_DWORD *)v14;
    *v4 = (void *)(v14 + 4);
    v16 = v3->anim_list.head_;
    if ( v16 )
      v17 = (int)&v16[-1].dllist_prev;
    else
      v17 = 0;
    if ( v15 )
    {
      v18 = v15;
      do
      {
        v17 = AnimSequenceNode::GetNext((AnimSequenceNode *)v17);
        --v18;
      }
      while ( v18 );
    }
    v3->first_cyclic = (AnimSequenceNode *)v17;
    v19 = *(_DWORD *)*v4;
    *v4 = (char *)*v4 + 4;
    v20 = v3->anim_list.head_;
    if ( v20 )
      v21 = (int)&v20[-1].dllist_prev;
    else
      v21 = 0;
    if ( v19 )
    {
      v22 = v19;
      do
      {
        v21 = AnimSequenceNode::GetNext((AnimSequenceNode *)v21);
        --v22;
      }
      while ( v22 );
    }
    v3->curr_anim = (AnimSequenceNode *)v21;
  }
  v23 = *(_DWORD *)*v4;
  v24 = (int)((char *)*v4 + 4);
  *v4 = (void *)v24;
  if ( v23 & 1 && size >= 0xC )
  {
    LODWORD(v3->velocity.x) = *(_DWORD *)v24;
    v25 = (int)((char *)*v4 + 4);
    *v4 = (void *)v25;
    LODWORD(v3->velocity.y) = *(_DWORD *)v25;
    v26 = (int)((char *)*v4 + 4);
    *v4 = (void *)v26;
    LODWORD(v3->velocity.z) = *(_DWORD *)v26;
    v24 = (int)((char *)*v4 + 4);
    *v4 = (void *)v24;
  }
  if ( v23 & 2 && size >= 0xC )
  {
    LODWORD(v3->omega.x) = *(_DWORD *)v24;
    v27 = (int)((char *)*v4 + 4);
    *v4 = (void *)v27;
    LODWORD(v3->omega.y) = *(_DWORD *)v27;
    v28 = (int)((char *)*v4 + 4);
    *v4 = (void *)v28;
    LODWORD(v3->omega.z) = *(_DWORD *)v28;
    *v4 = (char *)*v4 + 4;
  }
  return 1;
}

//----- (00525B80) --------------------------------------------------------  // acclient.c:340950
void __thiscall CSequence::update(CSequence *this, long double quantum, Frame *retval)
{
  CSequence *v3; // esi@1

  v3 = this;
  if ( this->anim_list.head_ )
  {
    CSequence::update_internal(this, quantum, &this->curr_anim, &this->frame_number, retval);
    CSequence::apricot(v3);
  }
  else if ( retval )
  {
    CSequence::apply_physics(this, retval, quantum, quantum);
  }
}

//----- (006FD770) --------------------------------------------------------  // acclient.c:785738
int sub_6FD770()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_12;
  INITIAL_MAX_DATA_RATE_81 = LOWEST_DATA_RATE_12;
  return result;
}

//----- (006FD780) --------------------------------------------------------  // acclient.c:785748
void sub_6FD780()
{
  flt_84455C = 1000.0 + 1.0;
}

//----- (006FD7A0) --------------------------------------------------------  // acclient.c:785754
void _E99_23()
{
  flt_844560 = 24.0 * 8.0;
}

//----- (006FD7C0) --------------------------------------------------------  // acclient.c:785760
void _E101_21()
{
  flt_844564 = 24.0 * 0.5;
}

//----- (006FD7E0) --------------------------------------------------------  // acclient.c:785766
void sub_6FD7E0()
{
  flt_844568 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FD800) --------------------------------------------------------  // acclient.c:785772
void _E105_27()
{
  dbl_844570 = 1.0 / 30.0;
}

//----- (006FD820) --------------------------------------------------------  // acclient.c:785778
void _E107_21()
{
  dbl_844578 = 1.0 / 5.0;
}

//----- (006FD840) --------------------------------------------------------  // acclient.c:785784
int _E109_63()
{
  return atexit(sub_7681F0);
}

//----- (006FD850) --------------------------------------------------------  // acclient.c:785790
int sub_6FD850()
{
  return atexit(nullsub_1123);
}

//----- (007681F0) --------------------------------------------------------  // acclient.c:894965
void __cdecl sub_7681F0()
{
  anim_done_hook.vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
}
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);

