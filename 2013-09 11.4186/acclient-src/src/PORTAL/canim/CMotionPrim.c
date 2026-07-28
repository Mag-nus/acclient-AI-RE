/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMotionPrim
   Object     : PORTAL\canim\CMotionPrim.obj
   Functions  : 17
   Addresses  : 00525FD0 - 00526790 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00525FD0) --------------------------------------------------------  // acclient.c:341302
void __thiscall MotionState::MotionState(MotionState *this)
{
  this->style = 0;
  this->substate = 0;
  LODWORD(this->substate_mod) = 1065353216;
  this->modifier_head = 0;
  this->action_head = 0;
  this->action_tail = 0;
}

//----- (00525FF0) --------------------------------------------------------  // acclient.c:341313
void __thiscall MotionState::add_modifier_no_check(MotionState *this, unsigned int modifier, float speed_mod)
{
  MotionState *v3; // esi@1
  void *v4; // eax@1

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 1065353216;
    *((_DWORD *)v4 + 2) = 0;
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)v4 = modifier;
  *((float *)v4 + 1) = speed_mod;
  *((_DWORD *)v4 + 2) = v3->modifier_head;
  v3->modifier_head = (MotionList *)v4;
}

//----- (00526040) --------------------------------------------------------  // acclient.c:341337
void __thiscall MotionState::remove_modifier(MotionState *this, MotionList *curr, MotionList *prev)
{
  if ( prev )
  {
    prev->next = curr->next;
    operator delete(curr);
  }
  else
  {
    this->modifier_head = curr->next;
    operator delete(curr);
  }
}

//----- (00526070) --------------------------------------------------------  // acclient.c:341352
void __thiscall MotionState::clear_modifiers(MotionState *this)
{
  MotionState *v1; // edi@1
  MotionList *v2; // esi@1
  void *v3; // eax@2

  v1 = this;
  v2 = this->modifier_head;
  while ( v2 )
  {
    v3 = v2;
    v2 = v2->next;
    operator delete(v3);
  }
  v1->modifier_head = 0;
}

//----- (005260A0) --------------------------------------------------------  // acclient.c:341370
void __thiscall MotionState::add_action(MotionState *this, unsigned int action, float speed_mod)
{
  MotionState *v3; // esi@1
  void *v4; // eax@1
  MotionList *v5; // ecx@6

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 1065353216;
    *((_DWORD *)v4 + 2) = 0;
  }
  else
  {
    v4 = 0;
  }
  *(_DWORD *)v4 = action;
  *((float *)v4 + 1) = speed_mod;
  *((_DWORD *)v4 + 2) = 0;
  if ( !v3->action_head )
    v3->action_head = (MotionList *)v4;
  v5 = v3->action_tail;
  if ( v5 )
    v5->next = (MotionList *)v4;
  v3->action_tail = (MotionList *)v4;
}

//----- (005260F0) --------------------------------------------------------  // acclient.c:341400
void __thiscall MotionState::clear_actions(MotionState *this)
{
  MotionState *v1; // edi@1
  MotionList *v2; // esi@1
  void *v3; // eax@2

  v1 = this;
  v2 = this->action_head;
  while ( v2 )
  {
    v3 = v2;
    v2 = v2->next;
    operator delete(v3);
  }
  v1->action_head = 0;
  v1->action_tail = 0;
}

//----- (00526120) --------------------------------------------------------  // acclient.c:341419
unsigned int __thiscall MotionState::remove_action_head(MotionState *this)
{
  MotionList *v1; // edx@1
  unsigned int result; // eax@1
  MotionList *v3; // eax@2
  unsigned int v4; // esi@2

  v1 = this->action_head;
  result = 0;
  if ( v1 )
  {
    v3 = v1->next;
    v4 = v1->motion;
    this->action_head = v3;
    if ( !v3 )
      this->action_tail = 0;
    operator delete(v1);
    result = v4;
  }
  return result;
}

//----- (00526150) --------------------------------------------------------  // acclient.c:341442
void __thiscall MotionData::Destroy(MotionData *this)
{
  MotionData *v1; // esi@1
  AnimData *v2; // ecx@1

  v1 = this;
  v2 = this->anims;
  if ( v2 )
  {
    if ( LODWORD(v2[-1].framerate) )
    {
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(3);
      v1->anims = 0;
      v1->num_anims = 0;
      return;
    }
    operator delete[](&v2[-1].framerate);
  }
  v1->anims = 0;
  v1->num_anims = 0;
}

//----- (00526190) --------------------------------------------------------  // acclient.c:341465
unsigned int __cdecl PackObj::GET_SIZE_LEFT(void *addr, void *start, unsigned int size)
{
  unsigned int result; // eax@2

  if ( size <= (_BYTE *)addr - (_BYTE *)start )
    result = 0;
  else
    result = size - ((_BYTE *)addr - (_BYTE *)start);
  return result;
}

//----- (005261B0) --------------------------------------------------------  // acclient.c:341477
int __cdecl PackObj::VERIFY_ADDR(void *addr, void *start, unsigned int size)
{
  int result; // eax@2

  if ( start > addr )
    result = 0;
  else
    result = size >= (_BYTE *)addr - (_BYTE *)start;
  return result;
}

//----- (005261D0) --------------------------------------------------------  // acclient.c:341489
void __thiscall MotionState::copy(MotionState *this, MotionState *s)
{
  MotionState *v2; // ebx@1
  MotionState *v3; // edi@1
  void *v4; // eax@2
  MotionList *v5; // ecx@3
  MotionList *v6; // esi@5
  void *v7; // eax@6
  void *v8; // eax@13
  MotionList *v9; // ecx@14
  MotionList *v10; // esi@16
  void *v11; // ebx@16
  void *v12; // eax@17
  MotionState *sa; // [sp+14h] [bp+4h]@5

  v2 = s;
  v3 = this;
  this->style = s->style;
  this->substate = s->substate;
  this->substate_mod = s->substate_mod;
  if ( s->modifier_head )
  {
    v4 = operator new(0xCu);
    if ( v4 )
    {
      v5 = s->modifier_head;
      *((_DWORD *)v4 + 2) = 0;
      *(_DWORD *)v4 = v5->motion;
      *((_DWORD *)v4 + 1) = LODWORD(v5->speed_mod);
    }
    else
    {
      v4 = 0;
    }
    v3->modifier_head = (MotionList *)v4;
    v6 = s->modifier_head->next;
    for ( sa = (MotionState *)v4; v6; sa = (MotionState *)v7 )
    {
      v7 = operator new(0xCu);
      if ( v7 )
      {
        *((_DWORD *)v7 + 2) = 0;
        *(_DWORD *)v7 = v6->motion;
        *((_DWORD *)v7 + 1) = LODWORD(v6->speed_mod);
      }
      else
      {
        v7 = 0;
      }
      LODWORD(sa->substate_mod) = v7;
      v6 = v6->next;
    }
  }
  else
  {
    this->modifier_head = 0;
  }
  if ( v2->action_head )
  {
    v8 = operator new(0xCu);
    if ( v8 )
    {
      v9 = v2->action_head;
      *((_DWORD *)v8 + 2) = 0;
      *(_DWORD *)v8 = v9->motion;
      *((_DWORD *)v8 + 1) = LODWORD(v9->speed_mod);
    }
    else
    {
      v8 = 0;
    }
    v3->action_head = (MotionList *)v8;
    v10 = v2->action_head->next;
    v11 = v8;
    for ( v3->action_tail = (MotionList *)v8; v10; v11 = v3->action_tail )
    {
      v12 = operator new(0xCu);
      if ( v12 )
      {
        *((_DWORD *)v12 + 2) = 0;
        *(_DWORD *)v12 = v10->motion;
        *((_DWORD *)v12 + 1) = LODWORD(v10->speed_mod);
      }
      else
      {
        v12 = 0;
      }
      v3->action_tail = (MotionList *)v12;
      *((_DWORD *)v11 + 2) = v12;
      v10 = v10->next;
    }
  }
  else
  {
    v3->action_head = 0;
    v3->action_tail = 0;
  }
}

//----- (005262E0) --------------------------------------------------------  // acclient.c:341589
void __thiscall MotionState::Destroy(MotionState *this)
{
  MotionState *v1; // edi@1
  MotionList *v2; // esi@1
  void *v3; // eax@2
  MotionList *v4; // esi@3
  void *v5; // eax@4

  v1 = this;
  v2 = this->modifier_head;
  while ( v2 )
  {
    v3 = v2;
    v2 = v2->next;
    operator delete(v3);
  }
  v4 = v1->action_head;
  v1->modifier_head = 0;
  while ( v4 )
  {
    v5 = v4;
    v4 = v4->next;
    operator delete(v5);
  }
  v1->action_head = 0;
  v1->action_tail = 0;
}

//----- (00526340) --------------------------------------------------------  // acclient.c:341618
int __thiscall MotionState::add_modifier(MotionState *this, unsigned int modifier, float speed_mod)
{
  MotionList *v3; // eax@1

  v3 = this->modifier_head;
  if ( v3 )
  {
    while ( v3->motion != modifier )
    {
      v3 = v3->next;
      if ( !v3 )
        goto LABEL_4;
    }
    return 0;
  }
LABEL_4:
  if ( this->substate == modifier )
    return 0;
  MotionState::add_modifier_no_check(this, modifier, speed_mod);
  return 1;
}

//----- (00526380) --------------------------------------------------------  // acclient.c:341641
unsigned int __thiscall MotionData::Pack(MotionData *this, void **addr, unsigned int size)
{
  MotionData *v3; // edi@1
  char v4; // bl@1
  void **v5; // esi@5
  unsigned int v6; // ecx@5
  unsigned int v7; // ebp@5
  int v8; // ebx@6
  int v9; // eax@7
  unsigned int v10; // eax@13
  unsigned int result; // eax@14
  int v12; // ecx@15
  int v13; // ebp@15
  int v14; // edx@15
  int v15; // ecx@15
  bool v16; // zf@15
  bool v17; // sf@15
  unsigned int v18; // edx@15
  int v19; // ebx@18
  int v20; // ebp@19
  unsigned int v21; // ebp@20
  int v22; // ebx@21
  int v23; // edi@25
  int v24; // edx@25
  int v25; // edi@28
  int v26; // edx@28
  char physics_bitfield; // [sp+13h] [bp-19h]@1
  char physics_bitfielda; // [sp+13h] [bp-19h]@11
  unsigned int retval; // [sp+14h] [bp-18h]@5
  char *v30; // [sp+18h] [bp-14h]@1
  int v31; // [sp+1Ch] [bp-10h]@3
  Vector3 _rhs; // [sp+20h] [bp-Ch]@1
  char addra; // [sp+30h] [bp+4h]@9

  v3 = this;
  v4 = 0;
  physics_bitfield = 0;
  LODWORD(_rhs.x) = 0;
  LODWORD(_rhs.y) = 0;
  LODWORD(_rhs.z) = 0;
  v30 = (char *)&this->velocity;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&this->velocity.x, &_rhs) )
  {
    physics_bitfield = 1;
    v4 = 1;
  }
  LODWORD(_rhs.x) = 0;
  LODWORD(_rhs.y) = 0;
  LODWORD(_rhs.z) = 0;
  v31 = (int)&v3->omega;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&v3->omega.x, &_rhs) )
  {
    v4 |= 2u;
    physics_bitfield = v4;
  }
  v5 = addr;
  v6 = 8;
  v7 = 0;
  retval = 8;
  if ( v3->num_anims )
  {
    v8 = 0;
    do
    {
      v9 = ((int (__thiscall *)(int, void **, _DWORD))v3->anims[v8].vfptr->Pack)(&v3->anims[v8], addr, 0);
      v6 = v9 + retval;
      ++v7;
      ++v8;
      retval += v9;
    }
    while ( v7 < v3->num_anims );
    v4 = physics_bitfield;
  }
  addra = v4 & 1;
  if ( v4 & 1 )
  {
    v6 += 12;
    retval = v6;
  }
  physics_bitfielda = v4 & 2;
  if ( v4 & 2 )
  {
    v6 += 12;
    retval = v6;
  }
  v10 = size;
  if ( size >= v6 )
  {
    *(_DWORD *)*v5 = v3->id;
    v12 = (int)((char *)*v5 + 4);
    *v5 = (void *)v12;
    *(_BYTE *)v12 = v3->num_anims;
    v13 = (int)((char *)*v5 + 1);
    *v5 = (void *)v13;
    *(_BYTE *)v13 = v3->bitfield;
    v14 = (int)((char *)*v5 + 1);
    *v5 = (void *)v14;
    *(_BYTE *)v14 = v4;
    v15 = (int)((char *)*v5 + 1);
    v18 = v15 & 0x80000003;
    v16 = (v15 & 0x80000003) == 0;
    v17 = (v15 & 0x80000003 & 0x80000000) != 0;
    *v5 = (void *)v15;
    if ( v17 )
    {
      v18 = (((_BYTE)v18 - 1) | 0xFFFFFFFC) + 1;
      v16 = v18 == 0;
    }
    if ( !v16 )
    {
      v19 = 4 - v18;
      if ( 4 != v18 )
      {
        do
        {
          *(_BYTE *)v15 = 0;
          v20 = (int)((char *)*v5 + 1);
          --v19;
          *v5 = (void *)v20;
          v15 = v20;
        }
        while ( v19 );
      }
    }
    v21 = 0;
    if ( v3->num_anims )
    {
      v22 = 0;
      do
      {
        ((void (__thiscall *)(int, void **, unsigned int))v3->anims[v22].vfptr->Pack)(&v3->anims[v22], v5, v10);
        ++v21;
        ++v22;
        v10 = size;
      }
      while ( v21 < v3->num_anims );
    }
    if ( addra && v10 >= 0xC )
    {
      *(_DWORD *)*v5 = *(_DWORD *)v30;
      v23 = (int)((char *)*v5 + 4);
      *v5 = (void *)v23;
      *(float *)v23 = *((float *)v30 + 1);
      v24 = (int)((char *)*v5 + 4);
      *v5 = (void *)v24;
      *(float *)v24 = *((float *)v30 + 2);
      *v5 = (char *)*v5 + 4;
    }
    if ( physics_bitfielda )
    {
      if ( v10 >= 0xC )
      {
        *(_DWORD *)*v5 = *(_DWORD *)v31;
        v25 = (int)((char *)*v5 + 4);
        *v5 = (void *)v25;
        *(float *)v25 = *(float *)(v31 + 4);
        v26 = (int)((char *)*v5 + 4);
        *v5 = (void *)v26;
        *(float *)v26 = *(float *)(v31 + 8);
        *v5 = (char *)*v5 + 4;
      }
    }
    result = retval;
  }
  else
  {
    result = v6;
  }
  return result;
}

//----- (00526570) --------------------------------------------------------  // acclient.c:341813
int __thiscall MotionData::UnPack(MotionData *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  MotionData *v4; // edi@1
  char *v5; // edx@1
  char *v6; // ecx@1
  char *v7; // eax@1
  int v8; // eax@1
  int v9; // ecx@2
  char v10; // al@4
  int v11; // ebp@5
  void *v12; // eax@5
  int v13; // ebx@6
  unsigned int v14; // ebp@9
  int v15; // ebx@10
  int v16; // ebp@14
  int v17; // ebx@14
  int v18; // eax@15
  int v19; // edx@18
  int v20; // ecx@18
  int v22; // edi@19
  char addra; // [sp+18h] [bp+4h]@1

  v3 = addr;
  v4 = this;
  this->id = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  this->num_anims = *v5;
  v6 = (char *)*addr + 1;
  *addr = v6;
  v4->bitfield = *v6;
  v7 = (char *)*addr + 1;
  *addr = v7;
  LOBYTE(v6) = *v7++;
  *addr = v7;
  addra = (char)v6;
  v8 = (signed int)v7 % 4;
  if ( v8 )
  {
    v9 = 4 - v8;
    if ( 4 != v8 )
    {
      do
      {
        *(_BYTE *)*v3 = 0;
        --v9;
        *v3 = (char *)*v3 + 1;
      }
      while ( v9 );
    }
  }
  v10 = v4->num_anims;
  if ( v10 )
  {
    v11 = (unsigned __int8)v10;
    v12 = operator new[](20 * (unsigned __int8)v10 + 4);
    if ( v12 )
    {
      v13 = (int)((char *)v12 + 4);
      *(_DWORD *)v12 = v11;
      vector_constructor_iterator((char *)v12 + 4, 0x14u, v11, (void *(__thiscall *)(void *))AnimData::AnimData);
    }
    else
    {
      v13 = 0;
    }
    v4->anims = (AnimData *)v13;
  }
  v14 = 0;
  if ( v4->num_anims )
  {
    v15 = 0;
    do
    {
      ((void (__thiscall *)(int, void **, unsigned int))v4->anims[v15].vfptr->UnPack)(&v4->anims[v15], v3, size);
      ++v14;
      ++v15;
    }
    while ( v14 < v4->num_anims );
  }
  if ( addra & 1 )
  {
    if ( size >= 0xC )
    {
      LODWORD(v4->velocity.x) = *(_DWORD *)*v3;
      v16 = (int)((char *)*v3 + 4);
      *v3 = (void *)v16;
      LODWORD(v4->velocity.y) = *(_DWORD *)v16;
      v17 = (int)((char *)*v3 + 4);
      *v3 = (void *)v17;
      LODWORD(v4->velocity.z) = *(_DWORD *)v17;
      *v3 = (char *)*v3 + 4;
    }
  }
  else
  {
    v18 = (int)&v4->velocity;
    *(_DWORD *)v18 = 0;
    *(_DWORD *)(v18 + 4) = 0;
    *(_DWORD *)(v18 + 8) = 0;
  }
  if ( addra & 2 )
  {
    if ( size >= 0xC )
    {
      LODWORD(v4->omega.x) = *(_DWORD *)*v3;
      v19 = (int)((char *)*v3 + 4);
      *v3 = (void *)v19;
      LODWORD(v4->omega.y) = *(_DWORD *)v19;
      v20 = (int)((char *)*v3 + 4);
      *v3 = (void *)v20;
      LODWORD(v4->omega.z) = *(_DWORD *)v20;
      *v3 = (char *)*v3 + 4;
      return 1;
    }
  }
  else
  {
    v22 = (int)&v4->omega;
    *(_DWORD *)v22 = 0;
    *(_DWORD *)(v22 + 4) = 0;
    *(_DWORD *)(v22 + 8) = 0;
  }
  return 1;
}

//----- (00526720) --------------------------------------------------------  // acclient.c:341941
void *__thiscall AnimData::vector_deleting_destructor(AnimData *this, unsigned int a2)
{
  AnimData *v2; // esi@1
  float v3; // eax@2
  char *v4; // ebp@2
  int v5; // ecx@2
  int v6; // eax@2
  WeenieDesc *v7; // esi@2
  int v8; // edi@3
  void *result; // eax@7

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].framerate;
    v4 = (char *)&this[-1].framerate;
    v5 = 5 * LODWORD(v3);
    v6 = LODWORD(v3) - 1;
    v7 = (WeenieDesc *)&v2[4 * v5 / 0x14u];
    if ( v6 >= 0 )
    {
      v8 = v6 + 1;
      do
      {
        v7 -= 5;
        WeenieDesc::~WeenieDesc(v7);
        --v8;
      }
      while ( v8 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    WeenieDesc::~WeenieDesc((WeenieDesc *)this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (00526790) --------------------------------------------------------  // acclient.c:341986
void __thiscall MotionState::MotionState(MotionState *this, MotionState *s)
{
  MotionState::copy(this, s);
}

