/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSeqPrim
   Object     : PORTAL\canim\CSeqPrim.obj
   Functions  : 19
   Addresses  : 00525BE0 - 006FD860 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00525BE0) --------------------------------------------------------  // acclient.c:340967
void __thiscall AnimSequenceNode::multiply_framerate(AnimSequenceNode *this, float multiplier)
{
  int v2; // eax@2

  if ( multiplier < 0.0 )
  {
    v2 = this->low_frame;
    this->low_frame = this->high_frame;
    this->high_frame = v2;
  }
  this->framerate = multiplier * this->framerate;
}

//----- (00525C10) --------------------------------------------------------  // acclient.c:340981
int __thiscall AnimSequenceNode::get_pos_frame(AnimSequenceNode *this, int fn)
{
  CAnimation *v2; // ecx@1
  int result; // eax@4

  v2 = this->anim;
  if ( v2 && fn >= 0 && fn < (signed int)v2->num_frames )
    result = (int)&v2->pos_frames[fn];
  else
    result = 0;
  return result;
}

//----- (00525C40) --------------------------------------------------------  // acclient.c:340995
int __thiscall AnimSequenceNode::get_part_frame(AnimSequenceNode *this, int fn)
{
  CAnimation *v2; // ecx@1
  int result; // eax@4

  v2 = this->anim;
  if ( v2 && fn >= 0 && fn < (signed int)v2->num_frames )
    result = (int)&v2->part_frames[fn];
  else
    result = 0;
  return result;
}

//----- (00525C80) --------------------------------------------------------  // acclient.c:341015
double __thiscall AnimSequenceNode::get_starting_frame(AnimSequenceNode *this)
{
  double result; // st7@2

  if ( this->framerate < 0.0 )
    result = (double)(this->high_frame + 1) - 0.00019999999;
  else
    result = (double)this->low_frame;
  return result;
}

//----- (00525CB0) --------------------------------------------------------  // acclient.c:341027
double __thiscall AnimSequenceNode::get_ending_frame(AnimSequenceNode *this)
{
  double result; // st7@2

  if ( this->framerate < 0.0 )
    result = (double)this->low_frame;
  else
    result = (double)(this->high_frame + 1) - 0.00019999999;
  return result;
}

//----- (00525CE0) --------------------------------------------------------  // acclient.c:341039
void __thiscall AnimData::AnimData(AnimData *this)
{
  this->vfptr = (PackObjVtbl *)&AnimData::vftable;
  this->anim_id.id = 0;
  this->low_frame = 0;
  this->high_frame = -1;
  LODWORD(this->framerate) = 1106247680;
}
// 7C84F0: using guessed type int (__thiscall *AnimData::vftable)(void *, char);

//----- (00525D00) --------------------------------------------------------  // acclient.c:341050
AnimData *__cdecl operator*(AnimData *result, float lhs, AnimData *rhs)
{
  unsigned int v3; // ecx@1
  int v4; // edx@1
  AnimData *v5; // eax@1
  double v6; // st7@1

  v3 = rhs->anim_id.id;
  v4 = rhs->low_frame;
  v5 = result;
  v6 = rhs->framerate * lhs;
  result->high_frame = rhs->high_frame;
  result->vfptr = (PackObjVtbl *)&AnimData::vftable;
  result->framerate = v6;
  result->anim_id.id = v3;
  result->low_frame = v4;
  return v5;
}
// 7C84F0: using guessed type int (__thiscall *AnimData::vftable)(void *, char);

//----- (00525D30) --------------------------------------------------------  // acclient.c:341071
void __thiscall AnimSequenceNode::AnimSequenceNode(AnimSequenceNode *this)
{
  this->dllist_next = 0;
  this->dllist_prev = 0;
  this->anim = 0;
  this->vfptr = (PackObjVtbl *)&AnimSequenceNode::vftable;
  LODWORD(this->framerate) = 1106247680;
  this->low_frame = -1;
  this->high_frame = -1;
}
// 7C8504: using guessed type int (__thiscall *AnimSequenceNode::vftable)(void *, char);

//----- (00525D60) --------------------------------------------------------  // acclient.c:341084
void __thiscall AnimSequenceNode::set_animation_id(AnimSequenceNode *this, IDClass<_tagDataID,32,0> id)
{
  AnimSequenceNode *v2; // esi@1
  CAnimation *v3; // ecx@1
  QualifiedDataID *v4; // eax@4
  CAnimation *v5; // eax@6
  unsigned int v6; // ecx@9
  unsigned int v7; // eax@11
  int v8; // eax@13
  QualifiedDataID v9; // [sp+4h] [bp-8h]@4

  v2 = this;
  v3 = this->anim;
  if ( v3 )
    ((void (*)(void))v3->vfptr->Release)();
  if ( id.id )
  {
    QualifiedDataID::QualifiedDataID(&v9, id, 8u);
    v2->anim = (CAnimation *)DBObj::Get(v4);
  }
  else
  {
    v2->anim = 0;
  }
  v5 = v2->anim;
  if ( v5 )
  {
    if ( v2->high_frame < 0 )
      v2->high_frame = v5->num_frames - 1;
    v6 = v5->num_frames;
    if ( v2->low_frame >= v6 )
      v2->low_frame = v6 - 1;
    v7 = v5->num_frames;
    if ( v2->high_frame >= v7 )
      v2->high_frame = v7 - 1;
    v8 = v2->low_frame;
    if ( v8 > v2->high_frame )
      v2->high_frame = v8;
  }
}

//----- (00525DE0) --------------------------------------------------------  // acclient.c:341126
int __thiscall AnimSequenceNode::GetNext(AnimSequenceNode *this)
{
  DLListData *v1; // eax@1
  int result; // eax@2

  v1 = this->dllist_next;
  if ( v1 )
    result = (int)&v1[-1].dllist_prev;
  else
    result = 0;
  return result;
}

//----- (00525DF0) --------------------------------------------------------  // acclient.c:341140
int __thiscall AnimSequenceNode::GetPrev(AnimSequenceNode *this)
{
  DLListData *v1; // eax@1
  int result; // eax@2

  v1 = this->dllist_prev;
  if ( v1 )
    result = (int)&v1[-1].dllist_prev;
  else
    result = 0;
  return result;
}

//----- (00525E00) --------------------------------------------------------  // acclient.c:341154
signed int __thiscall AnimData::Pack(AnimData *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2

  if ( size >= 0x10 )
  {
    *(_DWORD *)*addr = this->anim_id.id;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->low_frame;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->high_frame;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->framerate;
    *addr = (char *)*addr + 4;
  }
  return 16;
}

//----- (00525E50) --------------------------------------------------------  // acclient.c:341178
int __thiscall AnimData::UnPack(AnimData *this, void **addr, unsigned int size)
{
  int result; // eax@2
  unsigned int v4; // esi@3
  char *v5; // esi@3
  char *v6; // edx@3

  if ( size >= 0x10 )
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->anim_id.id = v4;
    this->low_frame = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->high_frame = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(this->framerate) = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00525EA0) --------------------------------------------------------  // acclient.c:341208
AnimSequenceNode *__thiscall AnimSequenceNode::vector_deleting_destructor(AnimSequenceNode *this, unsigned int a2)
{
  AnimSequenceNode *v2; // esi@1
  CAnimation *v3; // ecx@1

  v2 = this;
  v3 = this->anim;
  v2->vfptr = (PackObjVtbl *)&AnimSequenceNode::vftable;
  if ( v3 )
    ((void (*)(void))v3->vfptr->Release)();
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8504: using guessed type int (__thiscall *AnimSequenceNode::vftable)(void *, char);

//----- (00525EE0) --------------------------------------------------------  // acclient.c:341227
signed int __thiscall AnimSequenceNode::Pack(AnimSequenceNode *this, void **addr, unsigned int size)
{
  CAnimation *v3; // edx@2
  char *v4; // edx@5
  char *v5; // esi@5
  char *v6; // edx@5

  if ( size >= 0x10 )
  {
    v3 = this->anim;
    if ( v3 )
      *(_DWORD *)*addr = v3->m_DID.id;
    else
      *(_DWORD *)*addr = stru_844590.id;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->low_frame;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->high_frame;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = this->framerate;
    *addr = (char *)*addr + 4;
  }
  return 16;
}

//----- (00525F40) --------------------------------------------------------  // acclient.c:341256
int __thiscall AnimSequenceNode::UnPack(AnimSequenceNode *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  IDClass<_tagDataID,32,0> v5; // esi@3
  char *v6; // edx@3
  char *v7; // edx@3

  if ( size >= 0x10 )
  {
    v4 = (char *)*addr + 4;
    v5.id = *(_DWORD *)*addr;
    *addr = v4;
    this->low_frame = *(_DWORD *)v4;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->high_frame = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    LODWORD(this->framerate) = *(_DWORD *)v7;
    *addr = (char *)*addr + 4;
    AnimSequenceNode::set_animation_id(this, v5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00525F90) --------------------------------------------------------  // acclient.c:341288
void __thiscall AnimSequenceNode::AnimSequenceNode(AnimSequenceNode *this, AnimData *data)
{
  this->dllist_next = 0;
  this->dllist_prev = 0;
  this->anim = 0;
  this->vfptr = (PackObjVtbl *)&AnimSequenceNode::vftable;
  this->framerate = data->framerate;
  this->low_frame = data->low_frame;
  this->high_frame = data->high_frame;
  AnimSequenceNode::set_animation_id(this, data->anim_id);
}
// 7C8504: using guessed type int (__thiscall *AnimSequenceNode::vftable)(void *, char);

//----- (0069E000) --------------------------------------------------------  // acclient.c:694301
double __thiscall MD_Data_Fade::GetDuration(AnimSequenceNode *this)
{
  return this->framerate;
}

//----- (006FD860) --------------------------------------------------------  // acclient.c:785796
int sub_6FD860()
{
  return atexit(nullsub_1124);
}

