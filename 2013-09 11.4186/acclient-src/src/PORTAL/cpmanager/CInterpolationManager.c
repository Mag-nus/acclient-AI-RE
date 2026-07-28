/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CInterpolationManager
   Object     : PORTAL\cpmanager\CInterpolationManager.obj
   Functions  : 21
   Addresses  : 00509680 - 00707110 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00509680) --------------------------------------------------------  // acclient.c:311142
void __thiscall QuickWindow::SetWindowID(InterpolationManager *this, CPhysicsObj *new_physobj)
{
  this->physics_obj = new_physobj;
}

//----- (00555870) --------------------------------------------------------  // acclient.c:388765
LListData *__thiscall LListBase::RemoveTail(LListBase *this)
{
  LListData *result; // eax@1
  LListData v2; // edx@2
  LListData *v3; // esi@2
  LListData **v4; // edx@8

  result = this->head_;
  if ( this->head_ )
  {
    v2.llist_next = result->llist_next;
    v3 = this->tail_;
    if ( result == v3 )
    {
      this->head_ = v2.llist_next;
      if ( !v2.llist_next )
        this->tail_ = 0;
      result->llist_next = 0;
    }
    else
    {
      if ( v2.llist_next != v3 )
      {
        do
        {
          result = v2.llist_next;
          v2.llist_next = v2.llist_next->llist_next;
        }
        while ( v2.llist_next != this->tail_ );
      }
      v4 = &result->llist_next->llist_next;
      if ( result->llist_next )
      {
        result->llist_next = *v4;
        *v4 = 0;
        if ( (LListData **)this->tail_ == v4 )
          this->tail_ = result;
        result = (LListData *)v4;
      }
      else
      {
        result = 0;
      }
    }
  }
  return result;
}

//----- (005558D0) --------------------------------------------------------  // acclient.c:388814
void __thiscall InterpolationManager::InterpolationManager(InterpolationManager *this, CPhysicsObj *_physics_obj)
{
  InterpolationManager *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  this->original_distance = BIG_DISTANCE;
  this->position_queue.head_ = 0;
  this->position_queue.tail_ = 0;
  this->frame_counter = 0;
  LODWORD(this->progress_quantum) = 0;
  this->node_fail_counter = 0;
  v3 = (char *)&this->blipto_position.frame;
  v2->blipto_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->blipto_position.objcell_id = 0;
  *(_DWORD *)v3 = 1065353216;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 13) = 0;
  *((_DWORD *)v3 + 14) = 0;
  *((_DWORD *)v3 + 15) = 0;
  Frame::cache((Frame *)v3);
  v2->physics_obj = _physics_obj;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00555930) --------------------------------------------------------  // acclient.c:388842
void __cdecl InterpolationManager::Create(CPhysicsObj *obj)
{
  InterpolationManager *v1; // eax@1

  v1 = (InterpolationManager *)operator new(0x68u);
  if ( v1 )
    InterpolationManager::InterpolationManager(v1, obj);
}

//----- (00555950) --------------------------------------------------------  // acclient.c:388852
void __thiscall InterpolationManager::StopInterpolating(InterpolationManager *this)
{
  InterpolationManager *v1; // esi@1
  LListData *v2; // eax@2
  bool v3; // zf@3

  v1 = this;
  while ( v1->position_queue.head_ )
  {
    v2 = v1->position_queue.head_;
    if ( v1->position_queue.head_ )
    {
      v3 = v2->llist_next == 0;
      v1->position_queue.head_ = v2->llist_next;
      if ( v3 )
        v1->position_queue.tail_ = 0;
      v2->llist_next = 0;
      v2[2].llist_next = (LListData *)&PackObj::vftable;
      operator delete(v2);
    }
  }
  v1->frame_counter = 0;
  LODWORD(v1->progress_quantum) = 0;
  v1->node_fail_counter = 0;
  v1->original_distance = BIG_DISTANCE;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005559A0) --------------------------------------------------------  // acclient.c:388881
void __thiscall InterpolationManager::NodeCompleted(InterpolationManager *this, int success)
{
  InterpolationManager *v2; // esi@1
  LListData *v3; // eax@2
  bool v4; // zf@2
  LListData *v5; // ecx@3
  LListData *v6; // edi@5
  LListData *v7; // eax@7

  v2 = this;
  if ( this->physics_obj )
  {
    v3 = this->position_queue.head_;
    v4 = this->position_queue.head_ == 0;
    this->frame_counter = 0;
    LODWORD(this->progress_quantum) = 0;
    if ( v4 )
    {
      v6 = 0;
    }
    else
    {
      v5 = v3->llist_next;
      v4 = v3->llist_next == 0;
      v2->position_queue.head_ = v3->llist_next;
      if ( v4 )
        v2->position_queue.tail_ = v5;
      v3->llist_next = 0;
      v6 = v3;
    }
    v7 = v2->position_queue.head_;
    if ( v2->position_queue.head_ )
    {
      if ( v7[1].llist_next == (LListData *)1 )
      {
        v2->original_distance = Position::distance(&v2->physics_obj->m_position, (Position *)&v7[2]);
      }
      else if ( !success )
      {
        if ( !v6 )
          return;
        Position::operator=((int)&v2->blipto_position, (int)&v6[2]);
      }
    }
    else
    {
      v2->original_distance = BIG_DISTANCE;
      if ( success )
      {
        InterpolationManager::StopInterpolating(v2);
      }
      else
      {
        if ( !v6 )
          return;
        Position::operator=((int)&v2->blipto_position, (int)&v6[2]);
      }
    }
    if ( v6 )
    {
      v6[2].llist_next = (LListData *)&PackObj::vftable;
      operator delete(v6);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00555A50) --------------------------------------------------------  // acclient.c:388949
void __thiscall InterpolationNode::InterpolationNode(InterpolationNode *this)
{
  InterpolationNode *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->llist_next = 0;
  this->type = 0;
  v2 = (char *)&this->p.frame;
  v1->p.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->p.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00555A90) --------------------------------------------------------  // acclient.c:388972
Frame *__thiscall Position::subtract2(Position *this, Frame *result, Position *p2)
{
  Position *v3; // esi@1
  AC1Legacy::Vector3 *v4; // eax@1
  AC1Legacy::Vector3 v6; // [sp+8h] [bp-4Ch]@1
  Frame retval; // [sp+14h] [bp-40h]@1

  v3 = this;
  Frame::subtract2(&retval, &this->frame, &p2->frame);
  v4 = Position::localtolocal(p2, &v6, v3, &stru_86FB44);
  retval.m_fOrigin.x = v4->x;
  retval.m_fOrigin.y = v4->y;
  retval.m_fOrigin.z = v4->z;
  Frame::operator=((int)result, (int)&retval);
  return result;
}

//----- (00555AF0) --------------------------------------------------------  // acclient.c:388990
void __thiscall InterpolationManager::Destroy(InterpolationManager *this)
{
  InterpolationManager *v1; // esi@1
  LListData *v2; // eax@2
  LListData *v3; // ecx@3
  bool v4; // zf@3

  v1 = this;
  while ( 1 )
  {
    v2 = v1->position_queue.head_;
    if ( !v1->position_queue.head_ )
      break;
    v3 = v2->llist_next;
    v4 = v2->llist_next == 0;
    v1->position_queue.head_ = v2->llist_next;
    if ( v4 )
      v1->position_queue.tail_ = v3;
    v2->llist_next = 0;
    v2[2].llist_next = (LListData *)&PackObj::vftable;
    operator delete(v2);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00555B20) --------------------------------------------------------  // acclient.c:389016
void __thiscall InterpolationManager::InterpolateTo(InterpolationManager *this, Position *p, int _keep_heading)
{
  InterpolationManager *v3; // esi@1
  CPhysicsObj *v4; // ecx@1
  LListData *v5; // eax@2
  int v6; // ecx@4
  Position *v7; // ebx@6
  InterpolationNode *v8; // eax@7
  int v9; // eax@8
  int v10; // edi@8
  LListData *v11; // eax@12
  float degrees; // ST00_4@17
  LListData *v13; // eax@20
  LListData *v14; // eax@22
  LListData *v15; // ecx@25
  LListData *v16; // eax@25
  unsigned int v17; // edx@25
  LListData *v18; // eax@29
  bool v19; // zf@29
  InterpolationNode *v20; // eax@32
  int v21; // eax@33
  int v22; // edi@33
  LListData *v23; // eax@37
  Position *pa; // [sp+18h] [bp+4h]@6
  float pb; // [sp+18h] [bp+4h]@11
  float pc; // [sp+18h] [bp+4h]@36

  v3 = this;
  v4 = this->physics_obj;
  if ( v4 )
  {
    v5 = v3->position_queue.tail_;
    if ( v5 && v5[1].llist_next == (LListData *)1 )
      v6 = (int)&v5[2];
    else
      v6 = (int)&v4->m_position;
    v7 = p;
    *(float *)&pa = Position::distance((Position *)v6, p);
    if ( CPhysicsObj::GetAutonomyBlipDistance(v3->physics_obj) >= *(float *)&pa )
    {
      if ( Position::distance(&v3->physics_obj->m_position, v7) > 0.050000001 )
      {
        while ( v3->position_queue.tail_ )
        {
          v13 = v3->position_queue.tail_;
          if ( v13[1].llist_next != (LListData *)1 || Position::distance((Position *)&v13[2], v7) >= 0.050000001 )
            break;
          v14 = LListBase::RemoveTail((LListBase *)&v3->position_queue.head_);
          if ( v14 )
          {
            v14[2].llist_next = (LListData *)&PackObj::vftable;
            operator delete(v14);
          }
        }
        while ( 1 )
        {
          v15 = v3->position_queue.head_;
          v16 = v3->position_queue.head_;
          v17 = 0;
          if ( !v3->position_queue.head_ )
            break;
          do
          {
            v16 = v16->llist_next;
            ++v17;
          }
          while ( v16 );
          if ( v17 < 0x14 )
            break;
          if ( v15 )
          {
            v18 = v15->llist_next;
            v19 = v15->llist_next == 0;
            v3->position_queue.head_ = v15->llist_next;
            if ( v19 )
              v3->position_queue.tail_ = v18;
            v15->llist_next = 0;
            v15[2].llist_next = (LListData *)&PackObj::vftable;
            operator delete(v15);
          }
        }
        v3->keep_heading = _keep_heading;
        v20 = (InterpolationNode *)operator new(0x60u);
        if ( v20 )
        {
          InterpolationNode::InterpolationNode(v20);
          v22 = v21;
        }
        else
        {
          v22 = 0;
        }
        *(_DWORD *)(v22 + 4) = 1;
        *(_DWORD *)(v22 + 12) = v7->objcell_id;
        Frame::operator=(v22 + 16, (int)&v7->frame);
        if ( v3->keep_heading )
        {
          pc = CPhysicsObj::get_heading(v3->physics_obj);
          Frame::set_heading((Frame *)(v22 + 16), pc);
        }
        v23 = v3->position_queue.tail_;
        if ( v23 )
        {
          v23->llist_next = (LListData *)v22;
          v3->position_queue.tail_ = (LListData *)v22;
        }
        else
        {
          v3->position_queue.head_ = (LListData *)v22;
          v3->position_queue.tail_ = (LListData *)v22;
        }
      }
      else
      {
        if ( !_keep_heading )
        {
          degrees = Frame::get_heading(&v7->frame);
          CPhysicsObj::set_heading(v3->physics_obj, degrees, 1);
        }
        InterpolationManager::StopInterpolating(v3);
      }
    }
    else
    {
      v8 = (InterpolationNode *)operator new(0x60u);
      if ( v8 )
      {
        InterpolationNode::InterpolationNode(v8);
        v10 = v9;
      }
      else
      {
        v10 = 0;
      }
      *(_DWORD *)(v10 + 4) = 1;
      *(_DWORD *)(v10 + 12) = v7->objcell_id;
      Frame::operator=(v10 + 16, (int)&v7->frame);
      if ( v3->keep_heading )
      {
        pb = CPhysicsObj::get_heading(v3->physics_obj);
        Frame::set_heading((Frame *)(v10 + 16), pb);
      }
      v11 = v3->position_queue.tail_;
      if ( v11 )
      {
        v11->llist_next = (LListData *)v10;
        v3->position_queue.tail_ = (LListData *)v10;
        v3->node_fail_counter = 4;
      }
      else
      {
        v3->position_queue.head_ = (LListData *)v10;
        v3->position_queue.tail_ = (LListData *)v10;
        v3->node_fail_counter = 4;
      }
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00555D30) --------------------------------------------------------  // acclient.c:389177
void __thiscall InterpolationManager::adjust_offset(InterpolationManager *this, Frame *offset, long double quantum)
{
  InterpolationManager *v3; // esi@1
  LListData *v4; // ecx@1
  CPhysicsObj *v5; // eax@2
  LListData *v6; // edx@4
  Position *v7; // ebx@6
  Position *v8; // edi@6
  double v9; // st7@6
  CPhysicsObj *v10; // ecx@9
  CMotionInterp *v11; // eax@10
  double v12; // st7@10
  CMotionInterp *v13; // eax@11
  int v14; // eax@15
  double v15; // st7@22
  float _rhs; // ST04_4@25
  float my_max_speed; // [sp+10h] [bp-4Ch]@8
  float curr_distance; // [sp+14h] [bp-48h]@6
  float progress_made; // [sp+18h] [bp-44h]@16
  float progress_madea; // [sp+18h] [bp-44h]@22
  Frame adjustment; // [sp+1Ch] [bp-40h]@22
  float adjustment_distance; // [sp+64h] [bp+8h]@22

  v3 = this;
  v4 = this->position_queue.head_;
  if ( !v4 )
    return;
  v5 = v3->physics_obj;
  if ( !v5 )
    return;
  if ( !(v5->transient_state & 1) )
    return;
  v6 = v4[1].llist_next;
  if ( v6 == (LListData *)2 || v6 == (LListData *)3 )
    return;
  v7 = (Position *)&v4[2];
  v8 = &v5->m_position;
  v9 = Position::distance(&v5->m_position, (Position *)&v4[2]);
  curr_distance = v9;
  if ( v9 < 0.050000001 )
  {
LABEL_7:
    InterpolationManager::NodeCompleted(v3, 1);
    return;
  }
  my_max_speed = 0.0;
  if ( CPhysicsObj::get_minterp(v3->physics_obj) )
  {
    v10 = v3->physics_obj;
    if ( InterpolationManager::fUseAdjustedSpeed_ )
    {
      v11 = CPhysicsObj::get_minterp(v10);
      v12 = CMotionInterp::get_adjusted_max_speed(v11);
    }
    else
    {
      v13 = CPhysicsObj::get_minterp(v10);
      v12 = CMotionInterp::get_max_speed(v13);
    }
    my_max_speed = v12 * 2.0;
  }
  if ( my_max_speed < 0.00019999999 )
    my_max_speed = MAX_INTERPOLATED_VELOCITY;
  v14 = v3->frame_counter + 1;
  v3->progress_quantum = quantum + v3->progress_quantum;
  v3->frame_counter = v14;
  if ( (unsigned int)v14 < 5 )
    goto LABEL_22;
  progress_made = v3->original_distance - curr_distance;
  if ( CPhysicsObj::get_sticky_object_id(v3->physics_obj)
    || progress_made >= 0.00019999999 && progress_made / v3->progress_quantum / my_max_speed >= 0.30000001 )
  {
    v3->frame_counter = 0;
    LODWORD(v3->progress_quantum) = 0;
    v3->original_distance = curr_distance;
LABEL_22:
    Position::subtract2(v7, &adjustment, v8);
    progress_madea = my_max_speed * quantum;
    v15 = AC1Legacy::Vector3::magnitude(&adjustment.m_fOrigin);
    adjustment_distance = v15;
    if ( v15 <= 0.050000001 )
      InterpolationManager::NodeCompleted(v3, 1);
    if ( adjustment_distance > (double)progress_madea )
    {
      _rhs = progress_madea / adjustment_distance;
      Vector3::operator*=((Vector3 *)&adjustment.m_fOrigin.x, _rhs);
    }
    if ( v3->keep_heading )
      Frame::set_heading(&adjustment, 0.0);
    Frame::operator=((int)offset, (int)&adjustment);
    return;
  }
  if ( curr_distance < 0.2 )
    goto LABEL_7;
  ++v3->node_fail_counter;
  InterpolationManager::NodeCompleted(v3, 0);
}
// 81F418: using guessed type int InterpolationManager::fUseAdjustedSpeed_;

//----- (00555F20) --------------------------------------------------------  // acclient.c:389277
void __thiscall InterpolationManager::UseTime(InterpolationManager *this)
{
  InterpolationManager *v1; // ebx@1
  CPhysicsObj *v2; // ecx@1
  unsigned int v3; // edx@2
  LListData *v4; // eax@3
  LListData *v5; // edx@6
  LListData *v6; // edi@10
  signed int v7; // ebp@11
  signed int v8; // esi@11
  LListData *v9; // eax@11
  LListData *v10; // esi@14
  bool v11; // zf@14
  float v12; // edx@14
  float v13; // eax@14
  Position *v14; // [sp-Ch] [bp-70h]@23
  AC1Legacy::Vector3 v; // [sp+10h] [bp-54h]@14
  Position pos; // [sp+1Ch] [bp-48h]@11

  v1 = this;
  v2 = this->physics_obj;
  if ( v2 )
  {
    v3 = v1->node_fail_counter;
    if ( v3 > 3 )
      goto LABEL_10;
    v4 = v1->position_queue.head_;
    if ( !v1->position_queue.head_ )
    {
      if ( (signed int)v3 <= 0 )
        return;
LABEL_10:
      v6 = v1->position_queue.tail_;
      if ( v6 )
      {
        v7 = 0;
        v8 = 0;
        Position::Position(&pos);
        v9 = v6[1].llist_next;
        if ( v9 != (LListData *)2 && v9 != (LListData *)3 )
        {
          Position::operator=((int)&pos, (int)&v6[2]);
          goto LABEL_20;
        }
        v10 = v1->position_queue.head_;
        v11 = v1->position_queue.head_ == v6;
        v12 = *(float *)&v6[21].llist_next;
        v13 = *(float *)&v6[22].llist_next;
        LODWORD(v.x) = v6[20].llist_next;
        v.y = v12;
        v.z = v13;
        if ( !v11 )
        {
          do
          {
            if ( v10[1].llist_next == (LListData *)1 )
            {
              pos.objcell_id = (unsigned int)v10[3].llist_next;
              Frame::operator=((int)&pos.frame, (int)&v10[4]);
              v7 = 1;
            }
            v10 = v10->llist_next;
          }
          while ( v10 != v6 );
          if ( v7 )
          {
            v8 = 1;
LABEL_20:
            if ( CPhysicsObj::SetPositionSimple(v1->physics_obj, &pos, 1) )
              return;
            if ( v8 )
            {
              CPhysicsObj::set_velocity(v1->physics_obj, &v, 1);
              InterpolationManager::StopInterpolating(v1);
              return;
            }
LABEL_26:
            InterpolationManager::StopInterpolating(v1);
            return;
          }
        }
        v2 = v1->physics_obj;
        v14 = &v1->blipto_position;
      }
      else
      {
        v14 = &v1->blipto_position;
      }
      if ( CPhysicsObj::SetPositionSimple(v2, v14, 1) )
        return;
      goto LABEL_26;
    }
    v5 = v4[1].llist_next;
    if ( v5 == (LListData *)3 )
    {
      CPhysicsObj::set_velocity(v2, (AC1Legacy::Vector3 *)&v4[20], 1);
      InterpolationManager::NodeCompleted(v1, 1);
    }
    else if ( v5 == (LListData *)2 )
    {
      InterpolationManager::NodeCompleted(v1, 1);
    }
  }
}

//----- (00556070) --------------------------------------------------------  // acclient.c:389383
void __thiscall InterpolationManager::~InterpolationManager(InterpolationManager *this)
{
  InterpolationManager *v1; // esi@1

  v1 = this;
  InterpolationManager::Destroy(this);
  v1->blipto_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00707040) --------------------------------------------------------  // acclient.c:794259
void sub_707040()
{
  flt_86FB5C = 1000.0 + 1.0;
}

//----- (00707060) --------------------------------------------------------  // acclient.c:794265
void sub_707060()
{
  flt_86FB60 = 24.0 * 8.0;
}

//----- (00707080) --------------------------------------------------------  // acclient.c:794271
void sub_707080()
{
  flt_86FB64 = 24.0 * 0.5;
}

//----- (007070A0) --------------------------------------------------------  // acclient.c:794277
int _E101_35()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_38;
  dword_86FB6C = LOWEST_DATA_RATE_38;
  return result;
}

//----- (007070B0) --------------------------------------------------------  // acclient.c:794287
void sub_7070B0()
{
  flt_86FB70 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007070D0) --------------------------------------------------------  // acclient.c:794293
void _E105_45()
{
  dbl_86FB78 = 1.0 / 30.0;
}

//----- (007070F0) --------------------------------------------------------  // acclient.c:794299
void _E107_34()
{
  dbl_86FB80 = 1.0 / 5.0;
}

//----- (00707110) --------------------------------------------------------  // acclient.c:794305
int sub_707110()
{
  return atexit(nullsub_1260);
}

