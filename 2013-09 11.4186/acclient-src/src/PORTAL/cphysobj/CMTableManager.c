/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMTableManager
   Object     : PORTAL\cphysobj\CMTableManager.obj
   Functions  : 28
   Addresses  : 0051BBD0 - 006FCC60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051BBD0) --------------------------------------------------------  // acclient.c:329772
BOOL __thiscall MotionTableManager::SetMotionTableID(MotionTableManager *this, IDClass<_tagDataID,32,0> mtable_id)
{
  MotionTableManager *v2; // esi@1
  CMotionTable *v3; // ecx@1
  QualifiedDataID *v4; // eax@3
  int v5; // eax@3
  QualifiedDataID v7; // [sp+4h] [bp-8h]@3

  v2 = this;
  v3 = this->table;
  if ( v3 )
    ((void (*)(void))v3->vfptr->Release)();
  QualifiedDataID::QualifiedDataID(&v7, mtable_id, 0xEu);
  v5 = DBObj::Get(v4);
  v2->table = (CMotionTable *)v5;
  return v5 != 0;
}

//----- (0051BC10) --------------------------------------------------------  // acclient.c:329791
IDClass<_tagDataID,32,0> *__thiscall MotionTableManager::GetMotionTableID(MotionTableManager *this, IDClass<_tagDataID,32,0> *result)
{
  CMotionTable *v2; // eax@1
  unsigned int v3; // ST00_4@2
  IDClass<_tagDataID,32,0> *v4; // eax@2

  v2 = this->table;
  if ( v2 )
  {
    v3 = v2->m_DID.id;
    v4 = result;
    result->id = v3;
  }
  else
  {
    v4 = result;
    result->id = stru_8441E4.id;
  }
  return v4;
}

//----- (0051BC50) --------------------------------------------------------  // acclient.c:329813
MotionTableManager *__cdecl MotionTableManager::Create(IDClass<_tagDataID,32,0> mtable_id)
{
  void *v1; // eax@1
  void *v2; // esi@1
  MotionTableManager *result; // eax@4

  v1 = operator new(0x2Cu);
  v2 = v1;
  if ( v1 )
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    MotionState::MotionState((MotionState *)((char *)v1 + 8));
    *((_DWORD *)v2 + 8) = 0;
    *((_DWORD *)v2 + 9) = 0;
    *((_DWORD *)v2 + 10) = 0;
    if ( mtable_id.id != stru_8441E4.id )
      MotionTableManager::SetMotionTableID((MotionTableManager *)v2, mtable_id);
    result = (MotionTableManager *)v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051BCA0) --------------------------------------------------------  // acclient.c:329841
void __thiscall MotionTableManager::truncate_animation_list(MotionTableManager *this, MotionTableManager::AnimNode *node, CSequence *seq)
{
  DLListData *v3; // eax@2
  unsigned int v4; // edx@2
  DLListData *v5; // ecx@4

  if ( node )
  {
    v3 = this->pending_animations.tail_;
    v4 = 0;
    if ( (MotionTableManager::AnimNode *)v3 == node )
    {
LABEL_5:
      CSequence::remove_link_animations(seq, v4);
    }
    else
    {
      while ( v3 )
      {
        v5 = v3[1].dllist_prev;
        v3[1].dllist_prev = 0;
        v3 = v3->dllist_prev;
        v4 += (unsigned int)v5;
        if ( (MotionTableManager::AnimNode *)v3 == node )
          goto LABEL_5;
      }
    }
  }
}

//----- (0051BCE0) --------------------------------------------------------  // acclient.c:329872
void __thiscall MotionTableManager::AnimationDone(MotionTableManager *this, int success)
{
  MotionTableManager *v2; // esi@1
  DLListData *v3; // edi@1
  void *v4; // eax@6
  int v5; // ecx@7
  int v6; // ecx@9
  bool v7; // zf@9
  DLListData *v8; // ecx@13

  v2 = this;
  v3 = this->pending_animations.head_;
  if ( v3 )
  {
    ++this->animation_counter;
    do
    {
      if ( v3[1].dllist_prev > (DLListData *)v2->animation_counter )
        break;
      if ( (unsigned int)v3[1].dllist_next & 0x10000000 )
        MotionState::remove_action_head(&v2->state);
      CPhysicsObj::MotionDone(v2->physics_obj, (unsigned int)v3[1].dllist_next, success);
      v2->animation_counter -= (int)v3[1].dllist_prev;
      v4 = v2->pending_animations.head_;
      if ( v4 )
      {
        v5 = *((_DWORD *)v4 + 1);
        if ( v5 )
        {
          *(_DWORD *)v5 = *(_DWORD *)v4;
        }
        else
        {
          v6 = *(_DWORD *)v4;
          v7 = *(_DWORD *)v4 == 0;
          v2->pending_animations.head_ = *(DLListData **)v4;
          if ( !v7 )
            *(_DWORD *)(v6 + 4) = 0;
        }
        if ( *(_DWORD *)v4 )
        {
          *(_DWORD *)(*(_DWORD *)v4 + 4) = *((_DWORD *)v4 + 1);
        }
        else
        {
          v8 = v2->pending_animations.tail_->dllist_prev;
          v2->pending_animations.tail_ = v8;
          if ( v8 )
            v8->dllist_next = 0;
        }
        *(_DWORD *)v4 = 0;
        *((_DWORD *)v4 + 1) = 0;
        if ( v4 )
          operator delete(v4);
      }
      v3 = v2->pending_animations.head_;
    }
    while ( v3 );
    if ( v2->animation_counter )
    {
      if ( !v3 )
        v2->animation_counter = 0;
    }
  }
}

//----- (0051BDA0) --------------------------------------------------------  // acclient.c:329939
void __thiscall MotionTableManager::HandleExitWorld(MotionTableManager *this, CSequence *seq)
{
  MotionTableManager *i; // esi@1

  for ( i = this; i->pending_animations.head_; MotionTableManager::AnimationDone(i, 0) )
    ;
}

//----- (0051BDD0) --------------------------------------------------------  // acclient.c:329948
void __thiscall MotionTableManager::HandleEnterWorld(MotionTableManager *this, CSequence *seq)
{
  MotionTableManager *v2; // esi@1

  v2 = this;
  CSequence::remove_all_link_animations(seq);
  while ( v2->pending_animations.head_ )
    MotionTableManager::AnimationDone(v2, 0);
}

//----- (0051BE00) --------------------------------------------------------  // acclient.c:329959
void __thiscall MotionTableManager::CheckForCompletedMotions(MotionTableManager *this)
{
  MotionTableManager *v1; // edi@1
  DLListData *i; // esi@1
  void *v3; // eax@5
  int v4; // ecx@6
  int v5; // ecx@8
  bool v6; // zf@8
  DLListData *v7; // ecx@12

  v1 = this;
  for ( i = this->pending_animations.head_; i; i = v1->pending_animations.head_ )
  {
    if ( i[1].dllist_prev )
      break;
    if ( (unsigned int)i[1].dllist_next & 0x10000000 )
      MotionState::remove_action_head(&v1->state);
    CPhysicsObj::MotionDone(v1->physics_obj, (unsigned int)i[1].dllist_next, 1);
    v3 = v1->pending_animations.head_;
    if ( v3 )
    {
      v4 = *((_DWORD *)v3 + 1);
      if ( v4 )
      {
        *(_DWORD *)v4 = *(_DWORD *)v3;
      }
      else
      {
        v5 = *(_DWORD *)v3;
        v6 = *(_DWORD *)v3 == 0;
        v1->pending_animations.head_ = *(DLListData **)v3;
        if ( !v6 )
          *(_DWORD *)(v5 + 4) = 0;
      }
      if ( *(_DWORD *)v3 )
      {
        *(_DWORD *)(*(_DWORD *)v3 + 4) = *((_DWORD *)v3 + 1);
      }
      else
      {
        v7 = v1->pending_animations.tail_->dllist_prev;
        v1->pending_animations.tail_ = v7;
        if ( v7 )
          v7->dllist_next = 0;
      }
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      if ( v3 )
        operator delete(v3);
    }
  }
}

//----- (0051BE90) --------------------------------------------------------  // acclient.c:330013
void __thiscall MotionTableManager::Destroy(MotionTableManager *this)
{
  MotionTableManager *v1; // esi@1
  void *v2; // eax@2
  int v3; // ecx@3
  int v4; // ecx@5
  bool v5; // zf@5
  DLListData *v6; // ecx@9
  CMotionTable *v7; // ecx@13

  v1 = this;
  while ( 1 )
  {
    v2 = v1->pending_animations.head_;
    if ( !v2 )
      break;
    v3 = *((_DWORD *)v2 + 1);
    if ( v3 )
    {
      *(_DWORD *)v3 = *(_DWORD *)v2;
    }
    else
    {
      v4 = *(_DWORD *)v2;
      v5 = *(_DWORD *)v2 == 0;
      v1->pending_animations.head_ = *(DLListData **)v2;
      if ( !v5 )
        *(_DWORD *)(v4 + 4) = 0;
    }
    if ( *(_DWORD *)v2 )
    {
      *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
    }
    else
    {
      v6 = v1->pending_animations.tail_->dllist_prev;
      v1->pending_animations.tail_ = v6;
      if ( v6 )
        v6->dllist_next = 0;
    }
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = 0;
    if ( !v2 )
      break;
    operator delete(v2);
  }
  v7 = v1->table;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v1->table = 0;
  }
}

//----- (0051BF00) --------------------------------------------------------  // acclient.c:330068
void __thiscall MotionTableManager::~MotionTableManager(MotionTableManager *this)
{
  MotionTableManager *v1; // esi@1

  v1 = this;
  MotionTableManager::Destroy(this);
  MotionState::~MotionState(&v1->state);
}

//----- (0051BF20) --------------------------------------------------------  // acclient.c:330078
void __thiscall MotionTableManager::remove_redundant_links(MotionTableManager *this, CSequence *seq)
{
  DLListData *v2; // eax@1
  DLListData *v3; // edx@5
  DLListData *v4; // esi@5
  DLListData *v5; // eax@7
  DLListData *v6; // edx@8
  DLListData *v7; // edx@16

  v2 = this->pending_animations.tail_;
  if ( v2 )
  {
    while ( !v2[1].dllist_prev )
    {
      v2 = v2->dllist_prev;
      if ( !v2 )
        return;
    }
    v3 = v2[1].dllist_next;
    v4 = v2[1].dllist_next;
    if ( (unsigned int)v3 & 0x40000000 && !((unsigned int)v3 & 0x20000000) )
    {
      v5 = v2->dllist_prev;
      if ( !v5 )
        return;
      while ( 1 )
      {
        v6 = v5[1].dllist_next;
        if ( v6 == v4 )
        {
          if ( v5[1].dllist_prev )
            break;
        }
        if ( !v5[1].dllist_prev || !((unsigned int)v6 & 0xB0000000) )
        {
          v5 = v5->dllist_prev;
          if ( v5 )
            continue;
        }
        return;
      }
      goto LABEL_21;
    }
    if ( (signed int)v3 < 0 )
    {
      v5 = v2->dllist_prev;
      if ( v5 )
      {
        while ( 1 )
        {
          v7 = v5[1].dllist_next;
          if ( v7 == v4 )
            break;
          if ( !v5[1].dllist_prev || !((unsigned int)v7 & 0x70000000) )
          {
            v5 = v5->dllist_prev;
            if ( v5 )
              continue;
          }
          return;
        }
LABEL_21:
        MotionTableManager::truncate_animation_list(this, (MotionTableManager::AnimNode *)v5, seq);
        return;
      }
    }
  }
}

//----- (0051BFE0) --------------------------------------------------------  // acclient.c:330148
void __thiscall MotionTableManager::add_to_queue(MotionTableManager *this, unsigned int motion, unsigned int num_anims, CSequence *seq)
{
  MotionTableManager *v4; // esi@1
  void *v5; // eax@1

  v4 = this;
  v5 = operator new(0x10u);
  if ( v5 )
  {
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 2) = motion;
    *((_DWORD *)v5 + 3) = num_anims;
  }
  else
  {
    v5 = 0;
  }
  DLListBase::InsertAfter((DLListBase *)&v4->pending_animations.head_, (DLListData *)v5, v4->pending_animations.tail_);
  MotionTableManager::remove_redundant_links(v4, seq);
}

//----- (0051C030) --------------------------------------------------------  // acclient.c:330171
void __thiscall MotionTableManager::initialize_state(MotionTableManager *this, CSequence *seq)
{
  MotionTableManager *v2; // esi@1
  CMotionTable *v3; // ecx@1
  unsigned int v4; // edi@4
  void *v5; // eax@4
  unsigned int num_anims; // [sp+0h] [bp-4h]@1

  num_anims = (unsigned int)this;
  v2 = this;
  v3 = this->table;
  num_anims = 0;
  if ( v3 )
    CMotionTable::SetDefaultState(v3, &v2->state, seq, &num_anims);
  else
    num_anims = 0;
  v4 = num_anims;
  v5 = operator new(0x10u);
  if ( v5 )
  {
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 2) = 1090519043;
    *((_DWORD *)v5 + 3) = v4;
  }
  else
  {
    v5 = 0;
  }
  DLListBase::InsertAfter((DLListBase *)&v2->pending_animations.head_, (DLListData *)v5, v2->pending_animations.tail_);
  MotionTableManager::remove_redundant_links(v2, seq);
}

//----- (0051C0B0) --------------------------------------------------------  // acclient.c:330205
signed int __thiscall MotionTableManager::PerformMovement(MotionTableManager *this, MovementStruct *ms, CSequence *seq)
{
  MotionTableManager *v3; // esi@1
  CMotionTable *v4; // ecx@1
  bool v6; // zf@3
  __int32 v7; // eax@3
  int v8; // eax@4
  unsigned int num_anims; // [sp+0h] [bp-4h]@1

  num_anims = (unsigned int)this;
  v3 = this;
  v4 = this->table;
  if ( !v4 )
    return 7;
  v7 = ms->type - 2;
  v6 = ms->type == 2;
  num_anims = 0;
  if ( v6 )
  {
    if ( CMotionTable::DoObjectMotion(v4, ms->motion, &v3->state, seq, ms->params->speed, &num_anims) )
    {
      MotionTableManager::add_to_queue(v3, ms->motion, num_anims, seq);
      return 0;
    }
    return 67;
  }
  v8 = v7 - 2;
  if ( !v8 )
  {
    if ( CMotionTable::StopObjectMotion(v4, ms->motion, ms->params->speed, &v3->state, seq, &num_anims) )
    {
      MotionTableManager::add_to_queue(v3, 0x41000003u, num_anims, seq);
      return 0;
    }
    return 67;
  }
  if ( v8 == 1 )
  {
    CMotionTable::StopObjectCompletely(v4, &v3->state, seq, &num_anims);
    MotionTableManager::add_to_queue(v3, 0x41000003u, num_anims, seq);
    return 0;
  }
  return (signed int)seq;
}

//----- (006FCB30) --------------------------------------------------------  // acclient.c:785035
int _E89()
{
  return atexit(_E90);
}

//----- (006FCB40) --------------------------------------------------------  // acclient.c:785041
int _E92()
{
  return atexit(nullsub_1109);
}

//----- (006FCB50) --------------------------------------------------------  // acclient.c:785047
int sub_6FCB50()
{
  return atexit(_E96_3);
}

//----- (006FCB60) --------------------------------------------------------  // acclient.c:785053
void _E98_6()
{
  LODWORD(dword_8441E8) = 1053364187;
}

//----- (006FCB70) --------------------------------------------------------  // acclient.c:785059
void sub_6FCB70()
{
  flt_8441EC = 1000.0 + 1.0;
}

//----- (006FCB90) --------------------------------------------------------  // acclient.c:785065
void _E102_15()
{
  flt_8441F0 = 24.0 * 8.0;
}

//----- (006FCBB0) --------------------------------------------------------  // acclient.c:785071
void _E104_8()
{
  flt_8441F4 = 24.0 * 0.5;
}

//----- (006FCBD0) --------------------------------------------------------  // acclient.c:785077
void _E106_93()
{
  dword_8441F8 = 1024;
}

//----- (006FCBE0) --------------------------------------------------------  // acclient.c:785083
void _E108_69()
{
  dword_8441FC = 0x7FFF;
}

//----- (006FCBF0) --------------------------------------------------------  // acclient.c:785089
int _E110_58()
{
  const int result; // eax@1

  result = dword_8441F8;
  INITIAL_MAX_DATA_RATE_77 = dword_8441F8;
  return result;
}

//----- (006FCC00) --------------------------------------------------------  // acclient.c:785099
void _E112_86()
{
  flt_844204 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FCC20) --------------------------------------------------------  // acclient.c:785105
void _E114_44()
{
  dbl_844208 = 1.0 / 30.0;
}

//----- (006FCC40) --------------------------------------------------------  // acclient.c:785111
void _E116_18()
{
  dbl_844210 = 1.0 / 5.0;
}

//----- (006FCC60) --------------------------------------------------------  // acclient.c:785117
int sub_6FCC60()
{
  return atexit(nullsub_1107);
}

