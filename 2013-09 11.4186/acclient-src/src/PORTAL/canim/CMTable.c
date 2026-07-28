/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMTable
   Object     : PORTAL\canim\CMTable.obj
   Functions  : 29
   Addresses  : 00502D80 - 006FD680 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502D80) --------------------------------------------------------  // acclient.c:304098
int __thiscall LongNIValHash<SurfInfo *>::lookup(LongNIValHash<LongHash<MotionData> *> *this, unsigned int key, LongHash<MotionData> **retval)
{
  HashBaseData<unsigned long> *v3; // eax@1
  int result; // eax@4

  v3 = this->buckets[this->table_mask & (key ^ (key >> this->key_shift))];
  if ( v3 )
  {
    while ( key != v3->id )
    {
      v3 = v3->hash_next;
      if ( !v3 )
        goto LABEL_4;
    }
    *retval = (LongHash<MotionData> *)v3[1].vfptr;
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00507F10) --------------------------------------------------------  // acclient.c:309507
void __thiscall LongNIValHash<unsigned long>::destroy_contents(LongHash<MotionData> *this)
{
  HashBaseData<unsigned long> *v1; // eax@2
  LongHashIter<MotionData> iter; // [sp+0h] [bp-14h]@1

  iter.myHash_ = (HashBase<unsigned long> *)this;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( this )
  {
    v1 = *this->buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = v1;
    if ( v1 || (HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_), !iter.fEnd_) )
    {
      do
        HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&iter.myHash_);
      while ( !iter.fEnd_ );
    }
  }
}

//----- (00522260) --------------------------------------------------------  // acclient.c:337250
int __cdecl same_sign(float a, float b)
{
  unsigned __int8 v3; // c0@1
  unsigned __int8 v4; // c2@1

  if ( v3 | v4 )
  {
    if ( b >= 0.0 )
      return 0;
  }
  else if ( b < 0.0 )
  {
    return 0;
  }
  return 1;
}

//----- (00522290) --------------------------------------------------------  // acclient.c:337268
void __cdecl change_cycle_speed(CSequence *sequence, MotionData *data, float old_speed, float new_speed)
{
  float multiplier; // ST00_4@2

  if ( fabs(old_speed) <= 0.00019999999 )
  {
    if ( fabs(new_speed) < 0.00019999999 )
      CSequence::multiply_cyclic_animation_fr(sequence, 0.0);
  }
  else
  {
    multiplier = new_speed / old_speed;
    CSequence::multiply_cyclic_animation_fr(sequence, multiplier);
  }
}

//----- (005222E0) --------------------------------------------------------  // acclient.c:337285
void __thiscall CMotionTable::re_modify(CMotionTable *this, CSequence *sequence, MotionState *state)
{
  MotionState *v3; // esi@1
  CMotionTable *v4; // ebx@1
  CSequence *v5; // ebp@3
  MotionList *v6; // eax@4
  unsigned int v7; // edi@4
  MotionState dummy_state; // [sp+8h] [bp-18h]@2

  v3 = state;
  v4 = this;
  if ( state->modifier_head )
  {
    MotionState::MotionState(&dummy_state, state);
    if ( dummy_state.modifier_head )
    {
      v5 = sequence;
      do
      {
        v6 = v3->modifier_head;
        v7 = v6->motion;
        state = (MotionState *)LODWORD(v6->speed_mod);
        MotionState::remove_modifier(v3, v6, 0);
        MotionState::remove_modifier(&dummy_state, dummy_state.modifier_head, 0);
        CMotionTable::GetObjectSequence(v4, v7, v3, v5, *(float *)&state, (unsigned int *)&sequence, 0);
      }
      while ( dummy_state.modifier_head );
    }
    MotionState::~MotionState(&dummy_state);
  }
}

//----- (00522370) --------------------------------------------------------  // acclient.c:337318
void __thiscall DArray<unsigned long>::grow(DArray<unsigned long> *this, unsigned int size)
{
  DArray<unsigned long> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](4 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->data[v4];
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (unsigned int *)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<unsigned long>::shrink(this, size);
  }
}

//----- (005223D0) --------------------------------------------------------  // acclient.c:337349
void __thiscall DArray<unsigned long>::shrink(DArray<unsigned long> *this, unsigned int size)
{
  DArray<unsigned long> *v2; // esi@1
  unsigned int *v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](4 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          *((_DWORD *)v4 + v5) = v2->data[v5];
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (unsigned int *)v4;
    }
    else
    {
      v3 = this->data;
      this->sizeOf = 0;
      operator delete[](v3);
      v2->data = 0;
    }
    if ( v2->next_available > size )
      v2->next_available = size;
  }
  else
  {
    DArray<unsigned long>::grow(this, size);
  }
}

//----- (00522450) --------------------------------------------------------  // acclient.c:337393
MotionData *__thiscall MotionData::vector_deleting_destructor(MotionData *this, unsigned int a2)
{
  return MotionData::vector_deleting_destructor((MotionData *)((char *)this - 4), a2);
}

//----- (00522460) --------------------------------------------------------  // acclient.c:337399
MotionData *__thiscall MotionData::vector_deleting_destructor(MotionData *this, unsigned int a2)
{
  MotionData *v2; // esi@1

  v2 = this;
  MotionData::~MotionData(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00522480) --------------------------------------------------------  // acclient.c:337411
void __thiscall MotionData::~MotionData(MotionData *this)
{
  MotionData *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&MotionData::vftable;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&MotionData::vftable;
  MotionData::Destroy(this);
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)LongHashData::vftable;
  v1->hash_next = 0;
  v1->id = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7C7CE4: using guessed type void *MotionData::vftable;
// 7C7CE8: using guessed type int (__thiscall *MotionData::vftable)(void *, char);

//----- (005224B0) --------------------------------------------------------  // acclient.c:337430
void __cdecl add_motion(CSequence *sequence, MotionData *data, float speed_mod)
{
  double v3; // st7@2
  double v4; // st6@2
  double v5; // st7@2
  double v6; // st6@2
  unsigned int v7; // edi@2
  int v8; // ebx@3
  AnimData *v9; // eax@4
  AC1Legacy::Vector3 v; // [sp+4h] [bp-20h]@2
  AnimData result; // [sp+10h] [bp-14h]@2

  if ( data )
  {
    v3 = speed_mod * data->velocity.x;
    v4 = speed_mod * data->velocity.y;
    *(float *)&result.low_frame = speed_mod * data->velocity.z;
    LODWORD(v.z) = result.low_frame;
    v.x = v3;
    v.y = v4;
    CSequence::set_velocity(sequence, &v);
    v5 = speed_mod * data->omega.x;
    v6 = speed_mod * data->omega.y;
    *(float *)&result.low_frame = speed_mod * data->omega.z;
    LODWORD(v.z) = result.low_frame;
    v.x = v5;
    v.y = v6;
    CSequence::set_omega(sequence, &v);
    v7 = 0;
    if ( data->num_anims )
    {
      v8 = 0;
      do
      {
        v9 = operator*(&result, speed_mod, &data->anims[v8]);
        CSequence::append_animation(sequence, v9);
        WeenieDesc::~WeenieDesc((WeenieDesc *)&result);
        ++v7;
        ++v8;
      }
      while ( v7 < data->num_anims );
    }
  }
}

//----- (00522580) --------------------------------------------------------  // acclient.c:337476
void __cdecl combine_motion(CSequence *sequence, MotionData *data, float speed_mod)
{
  double v3; // st7@2
  double v4; // st6@2
  double v5; // st7@2
  double v6; // st6@2
  AC1Legacy::Vector3 o; // [sp+0h] [bp-24h]@2
  AC1Legacy::Vector3 v; // [sp+Ch] [bp-18h]@2
  float v9; // [sp+20h] [bp-4h]@2

  if ( data )
  {
    v3 = speed_mod * data->omega.x;
    v4 = speed_mod * data->omega.y;
    v.z = speed_mod * data->omega.z;
    o.z = v.z;
    o.x = v3;
    o.y = v4;
    v5 = speed_mod * data->velocity.x;
    v6 = speed_mod * data->velocity.y;
    v9 = speed_mod * data->velocity.z;
    v.x = v5;
    v.z = v9;
    v.y = v6;
    CSequence::combine_physics(sequence, &v, &o);
  }
}

//----- (00522600) --------------------------------------------------------  // acclient.c:337505
void __cdecl subtract_motion(CSequence *sequence, MotionData *data, float speed_mod)
{
  double v3; // st7@2
  double v4; // st6@2
  double v5; // st7@2
  double v6; // st6@2
  AC1Legacy::Vector3 o; // [sp+0h] [bp-24h]@2
  AC1Legacy::Vector3 v; // [sp+Ch] [bp-18h]@2
  float v9; // [sp+20h] [bp-4h]@2

  if ( data )
  {
    v3 = speed_mod * data->omega.x;
    v4 = speed_mod * data->omega.y;
    v.z = speed_mod * data->omega.z;
    o.z = v.z;
    o.x = v3;
    o.y = v4;
    v5 = speed_mod * data->velocity.x;
    v6 = speed_mod * data->velocity.y;
    v9 = speed_mod * data->velocity.z;
    v.x = v5;
    v.z = v9;
    v.y = v6;
    CSequence::subtract_physics(sequence, &v, &o);
  }
}

//----- (00522680) --------------------------------------------------------  // acclient.c:337534
int __thiscall LongHash<MotionData>::lookup(LongHash<MotionData> *this, unsigned int key)
{
  HashBaseData<unsigned long> *v2; // eax@1
  int result; // eax@4

  v2 = this->buckets[this->table_mask & (key ^ (key >> this->key_shift))];
  if ( v2 )
  {
    while ( key != v2->id )
    {
      v2 = v2->hash_next;
      if ( !v2 )
        goto LABEL_4;
    }
    result = (int)&v2[-1].id;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (005226C0) --------------------------------------------------------  // acclient.c:337559
MotionData *__thiscall CMotionTable::is_allowed(CMotionTable *this, unsigned int motion, MotionData *mdata, MotionState *state)
{
  MotionData *result; // eax@1
  unsigned int v5; // esi@3

  result = mdata;
  if ( mdata )
  {
    if ( mdata->bitfield & 2 && (v5 = state->substate, motion != v5) )
    {
      LongNIValHash<SurfInfo *>::lookup(
        (LongNIValHash<LongHash<MotionData> *> *)&this->style_defaults,
        state->style,
        (LongHash<MotionData> **)&mdata);
      result = (MotionData *)(mdata == (MotionData *)v5);
    }
    else
    {
      result = (MotionData *)1;
    }
  }
  return result;
}

//----- (00522710) --------------------------------------------------------  // acclient.c:337584
int __thiscall CMotionTable::get_link(CMotionTable *this, unsigned int style, unsigned int substate, float substate_speed, unsigned int motion, float speed)
{
  unsigned int v6; // ebx@1
  CMotionTable *v7; // ebp@1
  unsigned int v8; // esi@3
  LongNIValHash<LongHash<MotionData> *> *v9; // edi@3
  int result; // eax@4
  MotionData *retval; // [sp+0h] [bp-4h]@1

  v6 = substate;
  v7 = this;
  retval = 0;
  if ( speed < 0.0 || substate_speed < 0.0 )
  {
    v8 = style << 16;
    v9 = &this->links;
    if ( !LongNIValHash<SurfInfo *>::lookup(
            &this->links,
            (style << 16) | motion & 0xFFFFFF,
            (LongHash<MotionData> **)&substate) )
      goto LABEL_8;
    result = LongHash<MotionData>::lookup((LongHash<MotionData> *)substate, v6);
    retval = (MotionData *)result;
  }
  else
  {
    v8 = style << 16;
    v9 = &this->links;
    if ( !LongNIValHash<SurfInfo *>::lookup(
            &this->links,
            (style << 16) | substate & 0xFFFFFF,
            (LongHash<MotionData> **)&substate) )
      goto LABEL_8;
    result = LongHash<MotionData>::lookup((LongHash<MotionData> *)substate, motion);
    retval = (MotionData *)result;
  }
  if ( result )
    return result;
LABEL_8:
  if ( speed < 0.0 || substate_speed < 0.0 )
  {
    if ( LongNIValHash<SurfInfo *>::lookup(
           (LongNIValHash<LongHash<MotionData> *> *)&v7->style_defaults,
           style,
           (LongHash<MotionData> **)&motion)
      && LongNIValHash<SurfInfo *>::lookup(v9, v8 | v6 & 0xFFFFFF, (LongHash<MotionData> **)&substate) )
      return LongHash<MotionData>::lookup((LongHash<MotionData> *)substate, motion);
  }
  else if ( LongNIValHash<SurfInfo *>::lookup(v9, v8, (LongHash<MotionData> **)&substate) )
  {
    return LongHash<MotionData>::lookup((LongHash<MotionData> *)substate, motion);
  }
  return (int)retval;
}

//----- (00522860) --------------------------------------------------------  // acclient.c:337640
int __thiscall CMotionTable::GetObjectSequence(CMotionTable *this, unsigned int motion, MotionState *curr_state, CSequence *sequence, float speed_mod, unsigned int *num_anims, int stop_modifiers)
{
  MotionState *v7; // esi@1
  CMotionTable *v8; // edi@1
  unsigned int v9; // eax@1
  unsigned int v10; // ebp@2
  unsigned int v11; // ebx@3
  float v12; // ebp@6
  int v13; // eax@11
  int v14; // edx@18
  int v15; // ecx@21
  int v16; // eax@24
  int result; // eax@26
  int v18; // eax@28
  unsigned int v19; // ebp@47
  int v20; // ecx@52
  int v21; // eax@55
  unsigned int v22; // eax@65
  unsigned int *v23; // ecx@65
  int v24; // eax@69
  int link2; // [sp+10h] [bp-10h]@3
  int link2a; // [sp+10h] [bp-10h]@63
  unsigned int new_substate; // [sp+14h] [bp-Ch]@3
  unsigned int mtype2; // [sp+18h] [bp-8h]@2
  MotionData *pre_link; // [sp+1Ch] [bp-4h]@3
  int motiona; // [sp+24h] [bp+4h]@14
  int motionb; // [sp+24h] [bp+4h]@37
  int motionc; // [sp+24h] [bp+4h]@60
  int motiond; // [sp+24h] [bp+4h]@62
  MotionData *link; // [sp+28h] [bp+8h]@11
  MotionData *linka; // [sp+28h] [bp+8h]@28
  MotionData *linkb; // [sp+28h] [bp+8h]@59
  MotionData *linkc; // [sp+28h] [bp+8h]@64
  unsigned int speed_moda; // [sp+30h] [bp+10h]@59
  int speed_modb; // [sp+30h] [bp+10h]@65
  float speed_modc; // [sp+30h] [bp+10h]@69
  int speed_modd; // [sp+30h] [bp+10h]@71

  v7 = curr_state;
  v8 = this;
  *num_anims = 0;
  v9 = curr_state->style;
  if ( !curr_state->style )
    return 0;
  mtype2 = curr_state->substate;
  v10 = mtype2;
  if ( !mtype2 )
    return 0;
  link2 = 0;
  pre_link = 0;
  LongNIValHash<SurfInfo *>::lookup(
    (LongNIValHash<LongHash<MotionData> *> *)&this->style_defaults,
    v9,
    (LongHash<MotionData> **)&new_substate);
  v11 = motion;
  if ( motion == new_substate && *(float *)&stop_modifiers == 0.0 && v10 & 0x20000000 )
    return 1;
  v12 = speed_mod;
  if ( (motion & 0x80000000) != 0 )
  {
    if ( curr_state->style == motion )
      return 1;
    LongNIValHash<SurfInfo *>::lookup(
      (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
      curr_state->style,
      (LongHash<MotionData> **)&new_substate);
    if ( mtype2 != new_substate )
      pre_link = (MotionData *)CMotionTable::get_link(
                                 v8,
                                 curr_state->style,
                                 mtype2,
                                 curr_state->substate_mod,
                                 new_substate,
                                 speed_mod);
    if ( LongNIValHash<SurfInfo *>::lookup(
           (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
           motion,
           (LongHash<MotionData> **)&stop_modifiers) )
    {
      v13 = LongHash<MotionData>::lookup(&v8->cycles, (motion << 16) | stop_modifiers & 0xFFFFFF);
      link = (MotionData *)v13;
      if ( v13 )
      {
        if ( *(_BYTE *)(v13 + 48) & 1 )
          MotionState::clear_modifiers(v7);
        motiona = CMotionTable::get_link(v8, v7->style, new_substate, v7->substate_mod, motion, speed_mod);
        if ( !motiona && v11 != v7->style )
        {
          motiona = CMotionTable::get_link(v8, v7->style, new_substate, 1.0, v8->default_style, 1.0);
          LongNIValHash<SurfInfo *>::lookup(
            (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
            v8->default_style,
            (LongHash<MotionData> **)&mtype2);
          link2 = CMotionTable::get_link(v8, v8->default_style, mtype2, 1.0, v11, 1.0);
        }
        CSequence::clear_physics(sequence);
        CSequence::remove_cyclic_anims(sequence);
        add_motion(sequence, pre_link, speed_mod);
        add_motion(sequence, (MotionData *)motiona, speed_mod);
        add_motion(sequence, (MotionData *)link2, speed_mod);
        add_motion(sequence, link, speed_mod);
        v7->substate = stop_modifiers;
        v7->style = v11;
        v7->substate_mod = speed_mod;
        CMotionTable::re_modify(v8, sequence, v7);
        if ( pre_link )
          v14 = pre_link->num_anims;
        else
          v14 = 0;
        if ( motiona )
          v15 = *(_BYTE *)(motiona + 16);
        else
          v15 = 0;
        if ( link2 )
          v16 = *(_BYTE *)(link2 + 16);
        else
          v16 = 0;
        *num_anims = v15 + v16 + link->num_anims + v14 - 1;
        return 1;
      }
    }
  }
  if ( motion & 0x40000000 )
  {
    v18 = LongHash<MotionData>::lookup(&v8->cycles, motion & 0xFFFFFF | (v7->style << 16));
    linka = (MotionData *)v18;
    if ( v18
      || (v18 = LongHash<MotionData>::lookup(&v8->cycles, motion & 0xFFFFFF | (v8->default_style << 16)),
          (linka = (MotionData *)v18) != 0) )
    {
      if ( CMotionTable::is_allowed(v8, motion, (MotionData *)v18, v7) )
      {
        if ( motion == mtype2 && same_sign(speed_mod, v7->substate_mod) && CSequence::has_anims(sequence) )
        {
          change_cycle_speed(sequence, linka, v7->substate_mod, speed_mod);
          subtract_motion(sequence, linka, v7->substate_mod);
          combine_motion(sequence, linka, speed_mod);
          v7->substate_mod = speed_mod;
          result = 1;
        }
        else
        {
          if ( linka->bitfield & 1 )
            MotionState::clear_modifiers(v7);
          motionb = CMotionTable::get_link(v8, v7->style, v7->substate, v7->substate_mod, motion, speed_mod);
          if ( !motionb || !same_sign(speed_mod, v7->substate_mod) )
          {
            LongNIValHash<SurfInfo *>::lookup(
              (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
              v7->style,
              (LongHash<MotionData> **)&stop_modifiers);
            motionb = CMotionTable::get_link(v8, v7->style, v7->substate, v7->substate_mod, stop_modifiers, 1.0);
            link2 = CMotionTable::get_link(v8, v7->style, stop_modifiers, 1.0, v11, speed_mod);
          }
          CSequence::clear_physics(sequence);
          CSequence::remove_cyclic_anims(sequence);
          if ( link2 )
          {
            add_motion(sequence, (MotionData *)motionb, v7->substate_mod);
            add_motion(sequence, (MotionData *)link2, speed_mod);
          }
          else
          {
            if ( v7->substate_mod >= 0.0 || speed_mod <= 0.0 )
              *(float *)&stop_modifiers = speed_mod;
            else
              *(float *)&stop_modifiers = -speed_mod;
            add_motion(sequence, (MotionData *)motionb, *(float *)&stop_modifiers);
          }
          add_motion(sequence, linka, speed_mod);
          v19 = v7->substate;
          if ( v19 != v11 )
          {
            if ( v19 & 0x20000000 )
            {
              LongNIValHash<SurfInfo *>::lookup(
                (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
                v7->style,
                (LongHash<MotionData> **)&stop_modifiers);
              if ( stop_modifiers != v11 )
                MotionState::add_modifier_no_check(v7, v19, v7->substate_mod);
            }
          }
          v7->substate_mod = speed_mod;
          v7->substate = v11;
          CMotionTable::re_modify(v8, sequence, v7);
          if ( motionb )
            v20 = *(_BYTE *)(motionb + 16);
          else
            v20 = 0;
          if ( link2 )
            v21 = *(_BYTE *)(link2 + 16);
          else
            v21 = 0;
          *num_anims = v21 + linka->num_anims + v20 - 1;
          result = 1;
        }
        return result;
      }
    }
  }
  if ( !(motion & 0x10000000) )
    goto LABEL_80;
  speed_moda = mtype2 & 0xFFFFFF | (v7->style << 16);
  linkb = (MotionData *)LongHash<MotionData>::lookup(&v8->cycles, speed_moda);
  if ( !linkb )
    goto LABEL_80;
  motionc = CMotionTable::get_link(v8, v7->style, mtype2, v7->substate_mod, motion, v12);
  if ( motionc )
  {
    MotionState::add_action(v7, v11, v12);
    CSequence::clear_physics(sequence);
    CSequence::remove_cyclic_anims(sequence);
    add_motion(sequence, (MotionData *)motionc, v12);
    add_motion(sequence, linkb, v7->substate_mod);
    CMotionTable::re_modify(v8, sequence, v7);
    *num_anims = *(_BYTE *)(motionc + 16);
    return 1;
  }
  LongNIValHash<SurfInfo *>::lookup(
    (LongNIValHash<LongHash<MotionData> *> *)&v8->style_defaults,
    v7->style,
    (LongHash<MotionData> **)&new_substate);
  motiond = CMotionTable::get_link(v8, v7->style, mtype2, v7->substate_mod, new_substate, 1.0);
  if ( !motiond
    || (link2a = CMotionTable::get_link(v8, v7->style, new_substate, 1.0, v11, v12)) == 0
    || (linkc = (MotionData *)LongHash<MotionData>::lookup(&v8->cycles, speed_moda)) == 0 )
  {
LABEL_80:
    if ( v11 & 0x20000000 )
    {
      LODWORD(speed_modc) = v7->style << 16;
      v24 = LongHash<MotionData>::lookup(&v8->cycles, (v7->style << 16) | mtype2 & 0xFFFFFF);
      if ( v24 )
      {
        if ( !(*(_BYTE *)(v24 + 48) & 1) )
        {
          speed_modd = LongHash<MotionData>::lookup(&v8->modifiers, LODWORD(speed_modc) | v11 & 0xFFFFFF);
          if ( speed_modd || (speed_modd = LongHash<MotionData>::lookup(&v8->modifiers, v11 & 0xFFFFFF)) != 0 )
          {
            if ( MotionState::add_modifier(v7, v11, v12)
              || (CMotionTable::StopSequenceMotion(v8, v11, 1.0, v7, sequence, (unsigned int *)&num_anims),
                  MotionState::add_modifier(v7, v11, v12)) )
            {
              combine_motion(sequence, (MotionData *)speed_modd, v12);
              return 1;
            }
          }
        }
      }
    }
    return 0;
  }
  speed_modb = CMotionTable::get_link(v8, v7->style, new_substate, 1.0, mtype2, v7->substate_mod);
  MotionState::add_action(v7, v11, v12);
  CSequence::clear_physics(sequence);
  CSequence::remove_cyclic_anims(sequence);
  add_motion(sequence, (MotionData *)motiond, 1.0);
  add_motion(sequence, (MotionData *)link2a, v12);
  add_motion(sequence, (MotionData *)speed_modb, 1.0);
  add_motion(sequence, linkc, v7->substate_mod);
  CMotionTable::re_modify(v8, sequence, v7);
  v22 = *(_BYTE *)(motiond + 16) + *(_BYTE *)(link2a + 16);
  v23 = num_anims;
  *num_anims = v22;
  if ( speed_modb )
    *v23 = v22 + *(_BYTE *)(speed_modb + 16);
  return 1;
}

//----- (00522FC0) --------------------------------------------------------  // acclient.c:337911
int __thiscall CMotionTable::StopSequenceMotion(CMotionTable *this, unsigned int motion, float speed, MotionState *curr_state, CSequence *sequence, unsigned int *num_anims)
{
  unsigned int *v6; // esi@1
  unsigned int v7; // edi@1
  CMotionTable *v8; // ebx@1
  int result; // eax@3
  MotionList *v10; // esi@5
  int v11; // edi@9
  LongHash<MotionData> *v12; // ebx@9
  int v13; // eax@9

  v6 = num_anims;
  v7 = motion;
  v8 = this;
  *num_anims = 0;
  if ( motion & 0x40000000 && motion == curr_state->substate )
  {
    LongNIValHash<SurfInfo *>::lookup(
      (LongNIValHash<LongHash<MotionData> *> *)&this->style_defaults,
      curr_state->style,
      (LongHash<MotionData> **)&num_anims);
    CMotionTable::GetObjectSequence(v8, (unsigned int)num_anims, curr_state, sequence, 1.0, v6, 1);
    result = 1;
  }
  else
  {
    if ( !(motion & 0x20000000) )
      goto LABEL_8;
    v10 = curr_state->modifier_head;
    num_anims = 0;
    if ( !v10 )
      goto LABEL_8;
    while ( v10->motion != motion )
    {
      num_anims = (unsigned int *)v10;
      v10 = v10->next;
      if ( !v10 )
        goto LABEL_8;
    }
    v11 = v7 & 0xFFFFFF;
    v12 = &this->modifiers;
    v13 = LongHash<MotionData>::lookup(&this->modifiers, v11 | (curr_state->style << 16));
    if ( v13 || (v13 = LongHash<MotionData>::lookup(v12, v11)) != 0 )
    {
      subtract_motion(sequence, (MotionData *)v13, v10->speed_mod);
      MotionState::remove_modifier(curr_state, v10, (MotionList *)num_anims);
      result = 1;
    }
    else
    {
LABEL_8:
      result = 0;
    }
  }
  return result;
}

//----- (005230A0) --------------------------------------------------------  // acclient.c:337969
int __thiscall CMotionTable::SetDefaultState(CMotionTable *this, MotionState *state, CSequence *sequence, unsigned int *num_anims)
{
  CMotionTable *v4; // esi@1
  int result; // eax@1
  unsigned int v6; // edx@2
  unsigned int v7; // ebx@2
  unsigned int v8; // eax@2
  HashBaseData<unsigned long> *v9; // ecx@2
  int v10; // esi@6
  unsigned int default_substate; // [sp+0h] [bp-4h]@1

  default_substate = (unsigned int)this;
  v4 = this;
  result = LongNIValHash<SurfInfo *>::lookup(
             (LongNIValHash<LongHash<MotionData> *> *)&this->style_defaults,
             this->default_style,
             (LongHash<MotionData> **)&default_substate);
  if ( result )
  {
    MotionState::clear_modifiers(state);
    MotionState::clear_actions(state);
    v6 = v4->default_style;
    v7 = default_substate;
    v8 = (v4->default_style << 16) | default_substate & 0xFFFFFF;
    v9 = v4->cycles.buckets[v4->cycles.table_mask & (v8 ^ (v8 >> v4->cycles.key_shift))];
    if ( !v9 )
      goto LABEL_11;
    while ( v8 != v9->id )
    {
      v9 = v9->hash_next;
      if ( !v9 )
        return 0;
    }
    v10 = (int)&v9[-1].id;
    if ( v9 != (HashBaseData<unsigned long> *)4 )
    {
      state->style = v6;
      state->substate = v7;
      LODWORD(state->substate_mod) = 1065353216;
      *num_anims = *(_BYTE *)(v10 + 16) - 1;
      CSequence::clear_physics(sequence);
      CSequence::clear_animations(sequence);
      add_motion(sequence, (MotionData *)v10, state->substate_mod);
      result = 1;
    }
    else
    {
LABEL_11:
      result = 0;
    }
  }
  return result;
}

//----- (00523180) --------------------------------------------------------  // acclient.c:338024
int __thiscall CMotionTable::Pack(CMotionTable *this, void **addr, unsigned int size)
{
  CMotionTable *v3; // ebx@1
  HashBase<unsigned long> *v4; // edx@1
  unsigned int v5; // ecx@1
  signed int v6; // edi@1
  HashBaseData<unsigned long> *v7; // eax@2
  unsigned int v8; // esi@7
  int v9; // eax@14
  unsigned int v10; // ebx@14
  HashBaseData<unsigned long> *v11; // esi@15
  int v12; // eax@20
  unsigned int v13; // ecx@21
  unsigned int v14; // ebx@27
  HashBaseData<unsigned long> *v15; // esi@28
  int v16; // eax@33
  unsigned int v17; // ecx@34
  HashBaseData<unsigned long> *v18; // esi@41
  unsigned int v19; // eax@44
  HashBaseData<unsigned long>Vtbl *v20; // esi@46
  unsigned int v21; // ebx@48
  HashBaseData<unsigned long> *v22; // esi@49
  unsigned int v23; // ecx@56
  unsigned int v24; // esi@61
  unsigned int v25; // eax@61
  int result; // eax@69
  unsigned int v27; // ecx@70
  char *v28; // esi@70
  HashBase<unsigned long> *v29; // eax@70
  char *v30; // edx@70
  unsigned int v31; // ebx@70
  bool v32; // zf@70
  char *v33; // esi@70
  HashBaseData<unsigned long> *v34; // eax@71
  HashBaseData<unsigned long>Vtbl *v35; // ecx@75
  char *v36; // esi@75
  char *v37; // edx@75
  HashBase<unsigned long> *v38; // eax@79
  unsigned int v39; // ebx@79
  HashBaseData<unsigned long> *v40; // esi@80
  HashBase<unsigned long> *v41; // eax@89
  unsigned int v42; // ebx@89
  HashBaseData<unsigned long> *v43; // esi@90
  HashBase<unsigned long> *v44; // eax@99
  HashBaseData<unsigned long> *v45; // eax@100
  HashBaseData<unsigned long>Vtbl *v46; // eax@105
  unsigned int *v47; // edx@105
  char *v48; // esi@105
  unsigned int v49; // ebx@105
  HashBaseData<unsigned long> *v50; // esi@106
  unsigned int v51; // ecx@113
  unsigned int v52; // edx@118
  unsigned int v53; // eax@118
  unsigned int retval; // [sp+10h] [bp-8Ch]@14
  unsigned int retvala; // [sp+10h] [bp-8Ch]@27
  int retvalb; // [sp+10h] [bp-8Ch]@40
  unsigned int num_modifiers; // [sp+14h] [bp-88h]@1
  unsigned int num_modifiersa; // [sp+14h] [bp-88h]@103
  LongNIValHashIter<LongHash<MotionData> *> l_iter; // [sp+18h] [bp-84h]@40
  unsigned int num_link_tables; // [sp+2Ch] [bp-70h]@1
  LongHashIter<MotionData> iter; // [sp+30h] [bp-6Ch]@44
  LongNIValHashIter<unsigned long> sd_iter; // [sp+44h] [bp-58h]@1
  LongHashIter<MotionData> m_iter; // [sp+58h] [bp-44h]@27
  LongHashIter<MotionData> c_iter; // [sp+6Ch] [bp-30h]@14
  CMotionTable *v65; // [sp+80h] [bp-1Ch]@1
  unsigned int num_default_styles; // [sp+84h] [bp-18h]@1
  unsigned int num_cycles; // [sp+88h] [bp-14h]@1
  DArray<unsigned long> link_table_sizes; // [sp+8Ch] [bp-10h]@44

  v3 = this;
  v4 = (HashBase<unsigned long> *)&this->m_bLoaded;
  v5 = 0;
  v65 = v3;
  num_default_styles = 0;
  num_cycles = 0;
  num_modifiers = 0;
  num_link_tables = 0;
  v6 = 8;
  sd_iter.myHash_ = v4;
  sd_iter.lastThisChain_ = 0;
  sd_iter.curBucket_ = 0;
  if ( v4 )
  {
    v7 = *v4->buckets;
    sd_iter.fEnd_ = 0;
    sd_iter.curPtr_ = v7;
    if ( !v7 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&sd_iter.myHash_);
      if ( sd_iter.fEnd_ )
        goto LABEL_14;
      v7 = sd_iter.curPtr_;
      v5 = sd_iter.curBucket_;
      v4 = sd_iter.myHash_;
    }
    do
    {
      v6 += 8;
      if ( !v7 || (sd_iter.lastThisChain_ = v7, (v7 = v7->hash_next) == 0) )
      {
        v8 = v4->table_size;
        while ( 1 )
        {
          ++v5;
          sd_iter.lastThisChain_ = 0;
          if ( v5 >= v8 )
            break;
          v7 = v4->buckets[v5];
          if ( v7 )
            goto LABEL_13;
        }
        sd_iter.fEnd_ = 1;
      }
LABEL_13:
      ++num_default_styles;
    }
    while ( !sd_iter.fEnd_ );
  }
  else
  {
    sd_iter.fEnd_ = 1;
    sd_iter.curPtr_ = 0;
  }
LABEL_14:
  v9 = (int)&v3->m_pMaintainer;
  v10 = 0;
  retval = v6 + 4;
  c_iter.myHash_ = (HashBase<unsigned long> *)v9;
  c_iter.lastThisChain_ = 0;
  c_iter.curBucket_ = 0;
  if ( v9 )
  {
    v11 = (HashBaseData<unsigned long> *)**(_DWORD **)(v9 + 12);
    c_iter.fEnd_ = 0;
    c_iter.curPtr_ = v11;
    if ( !v11 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&c_iter.myHash_);
      v11 = c_iter.curPtr_;
      v10 = c_iter.curBucket_;
    }
  }
  else
  {
    c_iter.fEnd_ = 1;
    v11 = 0;
  }
LABEL_18:
  while ( v11 && v11 != (HashBaseData<unsigned long> *)4 )
  {
    v12 = (*(int (__stdcall **)(void **, _DWORD))(v11[-1].id + 12))(addr, 0);
    c_iter.lastThisChain_ = v11;
    v11 = v11->hash_next;
    retval += v12;
    if ( !v11 )
    {
      v13 = c_iter.myHash_->table_size;
      while ( 1 )
      {
        ++v10;
        c_iter.lastThisChain_ = 0;
        if ( v10 >= v13 )
          break;
        v11 = c_iter.myHash_->buckets[v10];
        if ( v11 )
        {
          ++num_cycles;
          goto LABEL_18;
        }
      }
      c_iter.fEnd_ = 1;
    }
    ++num_cycles;
  }
  v14 = 0;
  retvala = retval + 4;
  m_iter.myHash_ = (HashBase<unsigned long> *)&v65->style_defaults.vfptr;
  m_iter.lastThisChain_ = 0;
  m_iter.curBucket_ = 0;
  if ( v65 == (CMotionTable *)-56 )
  {
    m_iter.fEnd_ = 1;
    v15 = 0;
  }
  else
  {
    v15 = *v65->style_defaults.buckets;
    m_iter.fEnd_ = 0;
    m_iter.curPtr_ = v15;
    if ( v15 )
      goto LABEL_32;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&m_iter.myHash_);
    v15 = m_iter.curPtr_;
    v14 = m_iter.curBucket_;
  }
LABEL_31:
  while ( v15 )
  {
LABEL_32:
    if ( v15 == (HashBaseData<unsigned long> *)4 )
      break;
    v16 = (*(int (__stdcall **)(void **, _DWORD))(v15[-1].id + 12))(addr, 0);
    m_iter.lastThisChain_ = v15;
    v15 = v15->hash_next;
    retvala += v16;
    if ( !v15 )
    {
      v17 = m_iter.myHash_->table_size;
      while ( 1 )
      {
        ++v14;
        m_iter.lastThisChain_ = 0;
        if ( v14 >= v17 )
          break;
        v15 = m_iter.myHash_->buckets[v14];
        if ( v15 )
        {
          ++num_modifiers;
          goto LABEL_31;
        }
      }
      m_iter.fEnd_ = 1;
    }
    ++num_modifiers;
  }
  retvalb = retvala + 4;
  l_iter.myHash_ = (HashBase<unsigned long> *)&v65->cycles.vfptr;
  l_iter.lastThisChain_ = 0;
  l_iter.curBucket_ = 0;
  if ( v65 == (CMotionTable *)-80 )
  {
    v18 = 0;
    l_iter.fEnd_ = 1;
    l_iter.curPtr_ = 0;
  }
  else
  {
    v18 = *v65->cycles.buckets;
    l_iter.fEnd_ = 0;
    l_iter.curPtr_ = v18;
    if ( !v18 )
    {
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&l_iter.myHash_);
      v18 = l_iter.curPtr_;
    }
  }
  iter.myHash_ = 0;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  iter.fEnd_ = 1;
  iter.curPtr_ = 0;
  link_table_sizes.data = (unsigned int *)operator new[](0x40u);
  v19 = 16;
  link_table_sizes.sizeOf = 16;
  link_table_sizes.next_available = 0;
  link_table_sizes.blocksize = 16;
  while ( v18 )
  {
    v20 = v18[1].vfptr;
    if ( v19 <= num_link_tables )
      DArray<unsigned long>::grow(&link_table_sizes, v19 + 16);
    link_table_sizes.data[num_link_tables] = 0;
    v21 = 0;
    retvalb += 8;
    iter.myHash_ = (HashBase<unsigned long> *)v20;
    iter.lastThisChain_ = 0;
    iter.curBucket_ = 0;
    if ( v20 )
    {
      v22 = *(HashBaseData<unsigned long> **)v20[3].__vecDelDtor;
      iter.fEnd_ = 0;
      iter.curPtr_ = v22;
      if ( v22 )
        goto LABEL_54;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
      v22 = iter.curPtr_;
      v21 = iter.curBucket_;
    }
    else
    {
      v22 = 0;
LABEL_52:
      iter.fEnd_ = 1;
    }
LABEL_53:
    if ( v22 )
    {
LABEL_54:
      while ( v22 != (HashBaseData<unsigned long> *)4 )
      {
        retvalb += (*(int (__stdcall **)(void **, _DWORD))(v22[-1].id + 12))(addr, 0);
        ++link_table_sizes.data[num_link_tables];
        iter.lastThisChain_ = v22;
        v22 = v22->hash_next;
        if ( !v22 )
        {
          v23 = iter.myHash_->table_size;
          while ( 1 )
          {
            ++v21;
            iter.lastThisChain_ = 0;
            if ( v21 >= v23 )
              goto LABEL_52;
            v22 = iter.myHash_->buckets[v21];
            if ( v22 )
              goto LABEL_53;
          }
        }
      }
    }
    l_iter.lastThisChain_ = l_iter.curPtr_;
    l_iter.curPtr_ = l_iter.curPtr_->hash_next;
    if ( !l_iter.curPtr_ )
    {
      v24 = l_iter.myHash_->table_size;
      v25 = l_iter.curBucket_;
      while ( 1 )
      {
        ++v25;
        l_iter.lastThisChain_ = 0;
        if ( v25 >= v24 )
          break;
        l_iter.curPtr_ = l_iter.myHash_->buckets[v25];
        if ( l_iter.curPtr_ )
          goto LABEL_66;
      }
      l_iter.fEnd_ = 1;
LABEL_66:
      l_iter.curBucket_ = v25;
    }
    v18 = l_iter.curPtr_;
    ++num_link_tables;
    v19 = link_table_sizes.sizeOf;
  }
  if ( size >= retvalb )
  {
    v27 = num_default_styles;
    *(_DWORD *)*addr = v65->modifiers.vfptr;
    v28 = (char *)*addr + 4;
    *addr = v28;
    *(_DWORD *)v28 = v27;
    v29 = sd_iter.myHash_;
    v30 = (char *)*addr + 4;
    v31 = 0;
    v32 = (_DWORD)sd_iter.myHash_ == 0;
    *addr = v30;
    v33 = v30;
    sd_iter.lastThisChain_ = 0;
    sd_iter.curBucket_ = 0;
    if ( v32 )
    {
      v34 = 0;
    }
    else
    {
      v34 = *v29->buckets;
      sd_iter.fEnd_ = 0;
      sd_iter.curPtr_ = v34;
      if ( v34 )
        goto LABEL_75;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&sd_iter.myHash_);
      v34 = sd_iter.curPtr_;
      v31 = sd_iter.curBucket_;
    }
    while ( v34 )
    {
      do
      {
LABEL_75:
        v35 = v34[1].vfptr;
        *(_DWORD *)v33 = v34->id;
        v36 = (char *)*addr + 4;
        *addr = v36;
        *(_DWORD *)v36 = v35;
        v37 = (char *)*addr + 4;
        *addr = v37;
        v34 = v34->hash_next;
        v33 = v37;
      }
      while ( v34 );
      do
      {
        ++v31;
        if ( v31 >= sd_iter.myHash_->table_size )
          break;
        v34 = sd_iter.myHash_->buckets[v31];
      }
      while ( !v34 );
    }
    v38 = c_iter.myHash_;
    *(_DWORD *)v33 = num_cycles;
    v39 = 0;
    *addr = (char *)*addr + 4;
    c_iter.lastThisChain_ = 0;
    c_iter.curBucket_ = 0;
    if ( v38 )
    {
      v40 = *v38->buckets;
      c_iter.fEnd_ = 0;
      c_iter.curPtr_ = v40;
      if ( v40 )
        goto LABEL_84;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&c_iter.myHash_);
      v40 = c_iter.curPtr_;
      v39 = c_iter.curBucket_;
    }
    else
    {
      v40 = 0;
    }
LABEL_83:
    if ( v40 )
    {
LABEL_84:
      while ( v40 != (HashBaseData<unsigned long> *)4 )
      {
        (*(void (__stdcall **)(void **, unsigned int))(v40[-1].id + 12))(addr, size);
        v40 = v40->hash_next;
        if ( !v40 )
        {
          do
          {
            ++v39;
            if ( v39 >= c_iter.myHash_->table_size )
              break;
            v40 = c_iter.myHash_->buckets[v39];
          }
          while ( !v40 );
          goto LABEL_83;
        }
      }
    }
    *(_DWORD *)*addr = num_modifiers;
    v41 = m_iter.myHash_;
    v42 = 0;
    v32 = (_DWORD)m_iter.myHash_ == 0;
    *addr = (char *)*addr + 4;
    m_iter.lastThisChain_ = 0;
    m_iter.curBucket_ = 0;
    if ( v32 )
    {
      v43 = 0;
    }
    else
    {
      v43 = *v41->buckets;
      m_iter.fEnd_ = 0;
      m_iter.curPtr_ = v43;
      if ( v43 )
        goto LABEL_94;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&m_iter.myHash_);
      v43 = m_iter.curPtr_;
      v42 = m_iter.curBucket_;
    }
LABEL_93:
    if ( v43 )
    {
LABEL_94:
      while ( v43 != (HashBaseData<unsigned long> *)4 )
      {
        (*(void (__stdcall **)(void **, unsigned int))(v43[-1].id + 12))(addr, size);
        v43 = v43->hash_next;
        if ( !v43 )
        {
          do
          {
            ++v42;
            if ( v42 >= m_iter.myHash_->table_size )
              break;
            v43 = m_iter.myHash_->buckets[v42];
          }
          while ( !v43 );
          goto LABEL_93;
        }
      }
    }
    *(_DWORD *)*addr = num_link_tables;
    v44 = l_iter.myHash_;
    v32 = (_DWORD)l_iter.myHash_ == 0;
    *addr = (char *)*addr + 4;
    l_iter.lastThisChain_ = 0;
    l_iter.curBucket_ = 0;
    if ( v32 )
    {
      l_iter.curPtr_ = 0;
    }
    else
    {
      v45 = *v44->buckets;
      l_iter.fEnd_ = 0;
      l_iter.curPtr_ = v45;
      if ( !v45 )
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&l_iter.myHash_);
    }
    num_modifiersa = 0;
    while ( l_iter.curPtr_ )
    {
      v46 = l_iter.curPtr_[1].vfptr;
      *(_DWORD *)*addr = l_iter.curPtr_->id;
      v47 = link_table_sizes.data;
      v48 = (char *)*addr + 4;
      *addr = v48;
      *(_DWORD *)v48 = v47[num_modifiersa];
      v49 = 0;
      *addr = (char *)*addr + 4;
      iter.myHash_ = (HashBase<unsigned long> *)v46;
      iter.lastThisChain_ = 0;
      iter.curBucket_ = 0;
      if ( v46 )
      {
        v50 = *(HashBaseData<unsigned long> **)v46[3].__vecDelDtor;
        iter.fEnd_ = 0;
        iter.curPtr_ = v50;
        if ( v50 )
          goto LABEL_111;
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
        v50 = iter.curPtr_;
        v49 = iter.curBucket_;
      }
      else
      {
        v50 = 0;
LABEL_109:
        iter.fEnd_ = 1;
      }
LABEL_110:
      if ( v50 )
      {
LABEL_111:
        while ( v50 != (HashBaseData<unsigned long> *)4 )
        {
          (*(void (__stdcall **)(void **, unsigned int))(v50[-1].id + 12))(addr, size);
          iter.lastThisChain_ = v50;
          v50 = v50->hash_next;
          if ( !v50 )
          {
            v51 = iter.myHash_->table_size;
            while ( 1 )
            {
              ++v49;
              iter.lastThisChain_ = 0;
              if ( v49 >= v51 )
                goto LABEL_109;
              v50 = iter.myHash_->buckets[v49];
              if ( v50 )
                goto LABEL_110;
            }
          }
        }
      }
      ++num_modifiersa;
      l_iter.curPtr_ = l_iter.curPtr_->hash_next;
      if ( !l_iter.curPtr_ )
      {
        v52 = l_iter.myHash_->table_size;
        v53 = l_iter.curBucket_;
        do
        {
          l_iter.curBucket_ = v53 + 1;
          if ( v53 + 1 >= v52 )
            break;
          v53 = l_iter.curBucket_;
          l_iter.curPtr_ = l_iter.myHash_->buckets[l_iter.curBucket_];
        }
        while ( !l_iter.curPtr_ );
      }
    }
    operator delete[](link_table_sizes.data);
    result = retvalb;
  }
  else
  {
    operator delete[](link_table_sizes.data);
    result = retvalb;
  }
  return result;
}

//----- (005238C0) --------------------------------------------------------  // acclient.c:338603
int __thiscall CMotionTable::UnPack(CMotionTable *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  void *v4; // ebx@1
  CMotionTable *v5; // ebp@1
  int result; // eax@2
  char *v7; // eax@3
  unsigned int v8; // ecx@3
  unsigned int v9; // edi@3
  unsigned int v10; // ecx@5
  int v11; // eax@5
  void *v12; // eax@5
  int v13; // edx@8
  unsigned int v14; // ecx@10
  int v15; // edi@10
  void *v16; // eax@11
  int v17; // eax@15
  unsigned int v18; // ecx@17
  int v19; // edi@17
  void *v20; // eax@18
  int v21; // eax@22
  unsigned int v22; // ecx@24
  int v23; // edi@24
  unsigned int v24; // ecx@26
  int v25; // eax@26
  void *v26; // eax@26
  void *v27; // edi@26
  signed int v28; // eax@27
  int v29; // edx@28
  unsigned int v30; // eax@29
  void *v31; // eax@34
  void *v32; // ebp@37
  int v33; // eax@38
  void *v34; // eax@40
  void *v35; // edx@41
  int v36; // eax@43
  void *start; // [sp+18h] [bp-1Ch]@1
  unsigned int n; // [sp+1Ch] [bp-18h]@3
  unsigned int na; // [sp+1Ch] [bp-18h]@10
  unsigned int nb; // [sp+1Ch] [bp-18h]@17
  unsigned int nc; // [sp+1Ch] [bp-18h]@24
  unsigned int size_counter; // [sp+20h] [bp-14h]@14
  unsigned int size_countera; // [sp+20h] [bp-14h]@21
  unsigned int size_counterb; // [sp+20h] [bp-14h]@26
  unsigned int key; // [sp+24h] [bp-10h]@5
  unsigned int keya; // [sp+24h] [bp-10h]@26
  unsigned int j; // [sp+28h] [bp-Ch]@33
  unsigned int table_size; // [sp+2Ch] [bp-8h]@26
  CMotionTable *v49; // [sp+30h] [bp-4h]@1
  void **addra; // [sp+38h] [bp+4h]@5
  void **addrb; // [sp+38h] [bp+4h]@12
  void **addrc; // [sp+38h] [bp+4h]@19
  void **addrd; // [sp+38h] [bp+4h]@35
  MotionData *mdata; // [sp+3Ch] [bp+8h]@3
  MotionData *mdataa; // [sp+3Ch] [bp+8h]@10
  MotionData *mdatab; // [sp+3Ch] [bp+8h]@17
  MotionData *mdatac; // [sp+3Ch] [bp+8h]@24

  v3 = addr;
  v4 = *addr;
  v5 = this;
  v49 = this;
  start = *addr;
  (*(void (__thiscall **)(unsigned int *))(this[-1].modifiers.key_shift + 60))(&this[-1].modifiers.key_shift);
  if ( size < 0xC )
  {
    *addr = v4;
    return 0;
  }
  v5->modifiers.vfptr = *(HashBase<unsigned long>Vtbl **)*addr;
  v7 = (char *)*addr + 4;
  *addr = v7;
  v9 = size - 8;
  n = *(_DWORD *)v7;
  v8 = *(_DWORD *)v7;
  *addr = v7 + 4;
  mdata = 0;
  if ( v8 )
  {
    while ( v9 >= 8 )
    {
      v10 = *(_DWORD *)*v3;
      v11 = (int)((char *)*v3 + 4);
      *v3 = (void *)v11;
      key = v10;
      addra = *(void ***)v11;
      *v3 = (void *)(v11 + 4);
      v9 -= 8;
      v12 = operator new(0x10u);
      if ( v12 )
      {
        *((_DWORD *)v12 + 1) = 0;
        *((_DWORD *)v12 + 2) = key;
        *(_DWORD *)v12 = LongHashData::vftable;
        *((_DWORD *)v12 + 3) = addra;
      }
      else
      {
        v12 = 0;
      }
      v13 = *((_DWORD *)&v5->m_bLoaded + 1) & (*((_DWORD *)v12 + 2) ^ (*((_DWORD *)v12 + 2) >> LODWORD(v5->m_timeStamp)));
      *((_DWORD *)v12 + 1) = *(_DWORD *)(HIDWORD(v5->m_timeStamp) + 4 * v13);
      *(_DWORD *)(HIDWORD(v5->m_timeStamp) + 4 * v13) = v12;
      mdata = (MotionData *)((char *)mdata + 1);
      if ( (unsigned int)mdata >= n )
        goto LABEL_9;
    }
    goto LABEL_47;
  }
LABEL_9:
  if ( v9 < 4 )
    goto LABEL_48;
  v14 = *(_DWORD *)*v3;
  v15 = v9 - 4;
  na = *(_DWORD *)*v3;
  *v3 = (char *)*v3 + 4;
  mdataa = 0;
  if ( v14 > 0 )
  {
    do
    {
      v16 = operator new(0x34u);
      if ( v16 )
      {
        *((_DWORD *)v16 + 2) = 0;
        *((_DWORD *)v16 + 3) = 0;
        *((_DWORD *)v16 + 1) = LongHashData::vftable;
        *(_DWORD *)v16 = &MotionData::vftable;
        *((_DWORD *)v16 + 1) = &MotionData::vftable;
        *((_BYTE *)v16 + 16) = 0;
        *((_DWORD *)v16 + 5) = 0;
        *((_DWORD *)v16 + 6) = 0;
        *((_DWORD *)v16 + 7) = 0;
        *((_DWORD *)v16 + 8) = 0;
        *((_DWORD *)v16 + 9) = 0;
        *((_DWORD *)v16 + 10) = 0;
        *((_DWORD *)v16 + 11) = 0;
        *((_BYTE *)v16 + 48) = 0;
        addrb = (void **)v16;
      }
      else
      {
        addrb = 0;
        v16 = 0;
      }
      size_counter = (unsigned int)*v3;
      if ( !(*(int (__thiscall **)(void *, void **, int))(*(_DWORD *)v16 + 16))(v16, v3, v15) )
        goto LABEL_47;
      v15 += size_counter - (_DWORD)*v3;
      v17 = v5->m_numLinks & ((unsigned int)addrb[3] ^ ((unsigned int)addrb[3] >> v5->m_DID.id));
      addrb[2] = *(void **)(*(_DWORD *)&v5->m_AllowedInFreeList + 4 * v17);
      *(_DWORD *)(*(_DWORD *)&v5->m_AllowedInFreeList + 4 * v17) = addrb + 1;
      mdataa = (MotionData *)((char *)mdataa + 1);
    }
    while ( (unsigned int)mdataa < na );
  }
  if ( (unsigned int)v15 < 4 )
    goto LABEL_48;
  v18 = *(_DWORD *)*v3;
  v19 = v15 - 4;
  nb = *(_DWORD *)*v3;
  *v3 = (char *)*v3 + 4;
  mdatab = 0;
  if ( v18 > 0 )
  {
    do
    {
      v20 = operator new(0x34u);
      if ( v20 )
      {
        *((_DWORD *)v20 + 2) = 0;
        *((_DWORD *)v20 + 3) = 0;
        *((_DWORD *)v20 + 1) = LongHashData::vftable;
        *(_DWORD *)v20 = &MotionData::vftable;
        *((_DWORD *)v20 + 1) = &MotionData::vftable;
        *((_BYTE *)v20 + 16) = 0;
        *((_DWORD *)v20 + 5) = 0;
        *((_DWORD *)v20 + 6) = 0;
        *((_DWORD *)v20 + 7) = 0;
        *((_DWORD *)v20 + 8) = 0;
        *((_DWORD *)v20 + 9) = 0;
        *((_DWORD *)v20 + 10) = 0;
        *((_DWORD *)v20 + 11) = 0;
        *((_BYTE *)v20 + 48) = 0;
        addrc = (void **)v20;
      }
      else
      {
        addrc = 0;
        v20 = 0;
      }
      size_countera = (unsigned int)*v3;
      if ( !(*(int (__thiscall **)(void *, void **, int))(*(_DWORD *)v20 + 16))(v20, v3, v19) )
        goto LABEL_47;
      v19 += size_countera - (_DWORD)*v3;
      v21 = v5->style_defaults.table_mask & ((unsigned int)addrc[3] ^ ((unsigned int)addrc[3] >> v5->style_defaults.key_shift));
      addrc[2] = v5->style_defaults.buckets[v21];
      v5->style_defaults.buckets[v21] = (HashBaseData<unsigned long> *)(addrc + 1);
      mdatab = (MotionData *)((char *)mdatab + 1);
    }
    while ( (unsigned int)mdatab < nb );
  }
  if ( (unsigned int)v19 < 4 )
  {
LABEL_48:
    *v3 = start;
    result = 0;
  }
  else
  {
    v22 = *(_DWORD *)*v3;
    v23 = v19 - 4;
    nc = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
    mdatac = 0;
    if ( v22 > 0 )
    {
      while ( (unsigned int)v23 >= 8 )
      {
        v24 = *(_DWORD *)*v3;
        v25 = (int)((char *)*v3 + 4);
        *v3 = (void *)v25;
        keya = v24;
        table_size = *(_DWORD *)v25;
        *v3 = (void *)(v25 + 4);
        size_counterb = v23 - 8;
        v26 = operator new(0x18u);
        v27 = v26;
        if ( v26 )
        {
          *(_DWORD *)v26 = LongHash<CWeenieObject>::vftable;
          *((_DWORD *)v26 + 5) = 0;
          *((_DWORD *)v26 + 3) = operator new[](0x100u);
          *((_DWORD *)v27 + 4) = 64;
          *((_DWORD *)v27 + 2) = 8;
          *((_DWORD *)v27 + 1) = 0;
          v28 = 1;
          do
          {
            v29 = v28 | *((_DWORD *)v27 + 1);
            v28 *= 2;
            *((_DWORD *)v27 + 1) = v29;
          }
          while ( (v28 | (unsigned int)v29) < *((_DWORD *)v27 + 4) );
          v30 = 0;
          do
            *(_DWORD *)(*((_DWORD *)v27 + 3) + 4 * v30++) = 0;
          while ( v30 < *((_DWORD *)v27 + 4) );
          *(_DWORD *)v27 = LongHash<CWeenieObject>::vftable;
        }
        else
        {
          v27 = 0;
        }
        j = 0;
        if ( table_size > 0 )
        {
          while ( 1 )
          {
            v31 = operator new(0x34u);
            if ( v31 )
            {
              *((_DWORD *)v31 + 2) = 0;
              *((_DWORD *)v31 + 3) = 0;
              *((_DWORD *)v31 + 1) = LongHashData::vftable;
              *(_DWORD *)v31 = &MotionData::vftable;
              *((_DWORD *)v31 + 1) = &MotionData::vftable;
              *((_BYTE *)v31 + 16) = 0;
              *((_DWORD *)v31 + 5) = 0;
              *((_DWORD *)v31 + 6) = 0;
              *((_DWORD *)v31 + 7) = 0;
              *((_DWORD *)v31 + 8) = 0;
              *((_DWORD *)v31 + 9) = 0;
              *((_DWORD *)v31 + 10) = 0;
              *((_DWORD *)v31 + 11) = 0;
              *((_BYTE *)v31 + 48) = 0;
              addrd = (void **)v31;
            }
            else
            {
              addrd = 0;
              v31 = 0;
            }
            v32 = *v3;
            if ( !(*(int (__thiscall **)(void *, void **, unsigned int))(*(_DWORD *)v31 + 16))(v31, v3, size_counterb) )
              goto LABEL_48;
            size_counterb += (_BYTE *)v32 - (_BYTE *)*v3;
            v33 = *((_DWORD *)v27 + 1) & ((unsigned int)addrd[3] ^ ((unsigned int)addrd[3] >> *((_DWORD *)v27 + 2)));
            addrd[2] = *(void **)(*((_DWORD *)v27 + 3) + 4 * v33);
            *(_DWORD *)(*((_DWORD *)v27 + 3) + 4 * v33) = addrd + 1;
            ++j;
            if ( j >= table_size )
            {
              v5 = v49;
              break;
            }
          }
        }
        v34 = operator new(0x10u);
        if ( v34 )
        {
          *((_DWORD *)v34 + 2) = keya;
          *((_DWORD *)v34 + 1) = 0;
          *(_DWORD *)v34 = LongHashData::vftable;
          *((_DWORD *)v34 + 3) = v27;
          v35 = v34;
        }
        else
        {
          v35 = 0;
        }
        v36 = v5->cycles.table_mask & (*((_DWORD *)v35 + 2) ^ (*((_DWORD *)v35 + 2) >> v5->cycles.key_shift));
        v23 = size_counterb;
        *((_DWORD *)v35 + 1) = v5->cycles.buckets[v36];
        v5->cycles.buckets[v36] = (HashBaseData<unsigned long> *)v35;
        mdatac = (MotionData *)((char *)mdatac + 1);
        if ( (unsigned int)mdatac >= nc )
          goto LABEL_44;
      }
LABEL_47:
      *v3 = start;
      return 0;
    }
LABEL_44:
    if ( (unsigned int)*v3 & 3 && v23 < 4 - ((unsigned int)*v3 & 3) )
    {
      *v3 = start;
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}
// 7C62F8: using guessed type int (__thiscall *LongHashData::vftable[2])(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C7CE4: using guessed type void *MotionData::vftable;
// 7C7CE8: using guessed type int (__thiscall *MotionData::vftable)(void *, char);

//----- (00523D70) --------------------------------------------------------  // acclient.c:338945
void __thiscall CMotionTable::Destroy(CMotionTable *this)
{
  CMotionTable *v1; // ebx@1
  HashBaseData<unsigned long> *v2; // eax@2
  HashBase<unsigned long> *v3; // esi@6
  HashBaseData<unsigned long> *v4; // eax@7
  HashBaseData<unsigned long> *v5; // eax@14
  HashBaseIter<unsigned long> v6; // [sp+10h] [bp-28h]@6
  LongNIValHashIter<unsigned long> iter; // [sp+24h] [bp-14h]@1

  v1 = this;
  LongNIValHash<unsigned long>::destroy_contents(&this->cycles);
  LongNIValHash<unsigned long>::destroy_contents(&v1->modifiers);
  iter.myHash_ = (HashBase<unsigned long> *)&v1->links.vfptr;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( v1 == (CMotionTable *)-128 )
  {
    iter.fEnd_ = 1;
    iter.curPtr_ = 0;
  }
  else
  {
    v2 = *v1->links.buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = v2;
    if ( !v2 )
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
  }
  while ( iter.curPtr_ )
  {
    v6.myHash_ = (HashBase<unsigned long> *)iter.curPtr_[1].vfptr;
    v3 = v6.myHash_;
    v6.lastThisChain_ = 0;
    v6.curBucket_ = 0;
    if ( (_DWORD)v6.myHash_ )
    {
      v4 = *v6.myHash_->buckets;
      v6.fEnd_ = 0;
      v6.curPtr_ = v4;
      if ( v4 || (HashBaseIter<unsigned long>::Next(&v6), !v6.fEnd_) )
      {
        do
          HashBaseIter<unsigned long>::DeleteCurrent(&v6);
        while ( !v6.fEnd_ );
      }
    }
    else
    {
      v6.fEnd_ = 1;
      v6.curPtr_ = 0;
    }
    HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&iter.myHash_);
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  iter.myHash_ = (HashBase<unsigned long> *)&v1->style_defaults.vfptr;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( v1 == (CMotionTable *)-56 )
  {
    iter.fEnd_ = 1;
    iter.curPtr_ = 0;
  }
  else
  {
    v5 = *v1->style_defaults.buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = v5;
    if ( !v5 )
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
  }
  while ( iter.curPtr_ )
    HashBaseIter<unsigned long>::DeleteCurrent((HashBaseIter<unsigned long> *)&iter.myHash_);
}

//----- (00523E90) --------------------------------------------------------  // acclient.c:339022
int __thiscall CMotionTable::DoObjectMotion(CMotionTable *this, unsigned int motion, MotionState *curr_state, CSequence *sequence, float speed_mod, unsigned int *num_anims)
{
  return CMotionTable::GetObjectSequence(this, motion, curr_state, sequence, speed_mod, num_anims, 0);
}

//----- (00523ED0) --------------------------------------------------------  // acclient.c:339028
int __thiscall CMotionTable::StopObjectCompletely(CMotionTable *this, MotionState *curr_state, CSequence *sequence, unsigned int *num_anims)
{
  MotionList *v4; // eax@1
  CMotionTable *v5; // edi@1
  bool v6; // zf@5
  int result; // eax@5
  int retval; // [sp+10h] [bp-4h]@1

  v4 = curr_state->modifier_head;
  v5 = this;
  for ( retval = 0; v4; v4 = curr_state->modifier_head )
  {
    if ( CMotionTable::StopSequenceMotion(v5, v4->motion, v4->speed_mod, curr_state, sequence, num_anims) )
      retval = 1;
  }
  v6 = CMotionTable::StopSequenceMotion(
         v5,
         curr_state->substate,
         curr_state->substate_mod,
         curr_state,
         sequence,
         num_anims) == 0;
  result = 1;
  if ( v6 )
    result = retval;
  return result;
}

//----- (00523F50) --------------------------------------------------------  // acclient.c:339057
void __thiscall CMotionTable::~CMotionTable(CMotionTable *this)
{
  CMotionTable *v1; // esi@1
  int v2; // eax@1
  int v3; // eax@3
  int v4; // eax@5
  int v5; // eax@7

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&CMotionTable::vftable;
  this->vfptr = (PackObjVtbl *)&CMotionTable::vftable;
  CMotionTable::Destroy(this);
  v1->links.vfptr = (HashBase<unsigned long>Vtbl *)&LongNIValHash<LongHash<MotionData> *>::vftable;
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->links);
  v2 = v1->links.fPlacementNew_;
  v1->links.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v2 )
    operator delete[](v1->links.buckets);
  v3 = v1->modifiers.fPlacementNew_;
  v1->modifiers.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](v1->modifiers.buckets);
  v4 = v1->cycles.fPlacementNew_;
  v1->cycles.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v4 )
    operator delete[](v1->cycles.buckets);
  v1->style_defaults.vfptr = (HashBase<unsigned long>Vtbl *)LongNIValHash<unsigned long>::vftable;
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->style_defaults);
  v5 = v1->style_defaults.fPlacementNew_;
  v1->style_defaults.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v5 )
    operator delete[](v1->style_defaults.buckets);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5A14: using guessed type int (__thiscall *LongNIValHash<unsigned long>::vftable[2])(void *, char);
// 7C5A18: using guessed type int (__thiscall *LongNIValHash<LongHash<MotionData> *>::vftable)(void *, char);
// 7C5ADC: using guessed type int (__stdcall *CMotionTable::vftable)(int);
// 7C5AF0: using guessed type __int32 (__stdcall *CMotionTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);

//----- (006FD650) --------------------------------------------------------  // acclient.c:785662
int _E89_1()
{
  return atexit(_E90_0);
}

//----- (006FD660) --------------------------------------------------------  // acclient.c:785668
int _E92_0()
{
  return atexit(nullsub_1133);
}

//----- (006FD670) --------------------------------------------------------  // acclient.c:785674
int sub_6FD670()
{
  return atexit(_E96_4);
}

//----- (006FD680) --------------------------------------------------------  // acclient.c:785680
int sub_6FD680()
{
  return atexit(nullsub_1131);
}

