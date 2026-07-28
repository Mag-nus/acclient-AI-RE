/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPackClasses
   Object     : PORTAL\cphysobj\CPackClasses.obj
   Functions  : 27
   Addresses  : 004F1030 - 006FC430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F1030) --------------------------------------------------------  // acclient.c:285219
AutonomousPositionPack *__thiscall Attribute2ndBase::vector_deleting_destructor(AutonomousPositionPack *this, unsigned int a2)
{
  AutonomousPositionPack *v2; // esi@1

  v2 = this;
  this->position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00516440) --------------------------------------------------------  // acclient.c:323501
int __cdecl PositionPack::GetPackSize(unsigned int *bitfield, Position *p, AC1Legacy::Vector3 *velocity, unsigned int placement_id, int has_contact)
{
  int v5; // ecx@9
  unsigned int v6; // eax@21

  *bitfield = 0;
  if ( fabs(velocity->x) >= 0.00019999999 || fabs(velocity->y) >= 0.00019999999 || fabs(velocity->z) >= 0.00019999999 )
    *bitfield = 1;
  if ( placement_id )
    *bitfield |= 2u;
  if ( has_contact )
    *bitfield |= 4u;
  v5 = NoDrawHook::GetType() + 4;
  if ( fabs(p->frame.qw) >= 0.00019999999 )
    v5 += 4;
  else
    *bitfield |= 8u;
  if ( fabs(p->frame.qx) >= 0.00019999999 )
    v5 += 4;
  else
    *bitfield |= 0x10u;
  if ( fabs(p->frame.qy) >= 0.00019999999 )
    v5 += 4;
  else
    *bitfield |= 0x20u;
  if ( fabs(p->frame.qz) >= 0.00019999999 )
    v5 += 4;
  else
    *bitfield |= 0x40u;
  v6 = *bitfield;
  if ( *bitfield & 1 )
    v5 += 12;
  if ( v6 & 2 )
    v5 += 4;
  return v5 + 8;
}

//----- (00516540) --------------------------------------------------------  // acclient.c:323539
int __thiscall AC1Legacy::Vector3::UnPack(AC1Legacy::Vector3 *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // edx@3

  if ( size >= 0xC )
  {
    LODWORD(this->x) = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->y) = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->z) = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00516580) --------------------------------------------------------  // acclient.c:323565
void __thiscall PositionPack::PositionPack(PositionPack *this)
{
  PositionPack *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PositionPack::vftable;
  v2 = (char *)&this->position.frame;
  v1->position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->position.objcell_id = 0;
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
// 7C6BA4: using guessed type int (__thiscall *PositionPack::vftable)(void *, char);

//----- (005165C0) --------------------------------------------------------  // acclient.c:323588
void __cdecl PositionPack::PackPosition(void **addr, unsigned int size, unsigned int bitfield, Position *p, AC1Legacy::Vector3 *velocity, unsigned int placement_id, int has_contact, unsigned __int16 instance_timestamp, unsigned __int16 position_timestamp, unsigned __int16 teleport_timestamp, unsigned __int16 force_position_timestamp)
{
  char *v11; // edx@11
  char *v12; // ecx@11
  char *v13; // edi@14
  char *v14; // edx@14
  char *v15; // ecx@14

  *(_DWORD *)*addr = bitfield;
  *addr = (char *)*addr + 4;
  Position::PackOrigin(p, addr, size);
  if ( !(bitfield & 8) )
  {
    *(float *)*addr = p->frame.qw;
    *addr = (char *)*addr + 4;
  }
  if ( !(bitfield & 0x10) )
  {
    *(float *)*addr = p->frame.qx;
    *addr = (char *)*addr + 4;
  }
  if ( !(bitfield & 0x20) )
  {
    *(float *)*addr = p->frame.qy;
    *addr = (char *)*addr + 4;
  }
  if ( !(bitfield & 0x40) )
  {
    *(float *)*addr = p->frame.qz;
    *addr = (char *)*addr + 4;
  }
  if ( bitfield & 1 && size >= 0xC )
  {
    *(_DWORD *)*addr = LODWORD(velocity->x);
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(float *)v11 = velocity->y;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(float *)v12 = velocity->z;
    *addr = (char *)*addr + 4;
  }
  if ( bitfield & 2 )
  {
    *(_DWORD *)*addr = placement_id;
    *addr = (char *)*addr + 4;
  }
  *(_WORD *)*addr = instance_timestamp;
  v13 = (char *)*addr + 2;
  *addr = v13;
  *(_WORD *)v13 = position_timestamp;
  v14 = (char *)*addr + 2;
  *addr = v14;
  *(_WORD *)v14 = teleport_timestamp;
  v15 = (char *)*addr + 2;
  *addr = v15;
  *(_WORD *)v15 = force_position_timestamp;
  *addr = (char *)*addr + 2;
}

//----- (005166B0) --------------------------------------------------------  // acclient.c:323649
int __thiscall PositionPack::Pack(PositionPack *this, void **addr, unsigned int size)
{
  PositionPack *v3; // esi@1
  int v4; // ST4C_4@1
  int v5; // eax@1
  int v6; // ST48_4@1
  int v7; // ecx@1
  int v8; // ST44_4@1
  unsigned int v9; // edx@1
  int v10; // ebp@1
  unsigned int bitfield; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = this->force_position_timestamp;
  v5 = this->instance_timestamp;
  v6 = this->teleport_timestamp;
  v7 = this->has_contact;
  v8 = v3->position_timestamp;
  v9 = v3->placement_id;
  bitfield = 0;
  v10 = PositionPack::GetPackSize(&bitfield, &v3->position, &v3->velocity, v9, v7);
  PositionPack::PackPosition(
    addr,
    size,
    bitfield,
    &v3->position,
    &v3->velocity,
    v3->placement_id,
    v3->has_contact,
    v3->instance_timestamp,
    v3->position_timestamp,
    v3->teleport_timestamp,
    v3->force_position_timestamp);
  return v10;
}

//----- (00516740) --------------------------------------------------------  // acclient.c:323686
int __thiscall PositionPack::UnPack(PositionPack *this, void **addr, unsigned int size)
{
  int v3; // ebx@1
  PositionPack *v4; // edi@1
  Frame *v5; // ecx@1
  char *v6; // edx@15
  char *v7; // ecx@15
  int v8; // edx@16
  char *v9; // ebx@20
  char *v10; // edx@20
  char *v11; // ecx@20

  v3 = *(_DWORD *)*addr;
  v4 = this;
  *addr = (char *)*addr + 4;
  Position::UnPackOrigin(&this->position, addr, size);
  v5 = &v4->position.frame;
  if ( v3 & 8 )
  {
    LODWORD(v5->qw) = 0;
  }
  else
  {
    LODWORD(v5->qw) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v3 & 0x10 )
  {
    LODWORD(v4->position.frame.qx) = 0;
  }
  else
  {
    LODWORD(v4->position.frame.qx) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v3 & 0x20 )
  {
    LODWORD(v4->position.frame.qy) = 0;
  }
  else
  {
    LODWORD(v4->position.frame.qy) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v3 & 0x40 )
  {
    LODWORD(v4->position.frame.qz) = 0;
  }
  else
  {
    LODWORD(v4->position.frame.qz) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  Frame::cache(v5);
  if ( v3 & 1 )
  {
    if ( size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(v4->velocity.x);
      v6 = (char *)*addr + 4;
      *addr = v6;
      *(float *)v6 = v4->velocity.y;
      v7 = (char *)*addr + 4;
      *addr = v7;
      *(float *)v7 = v4->velocity.z;
      *addr = (char *)*addr + 4;
    }
  }
  else
  {
    v8 = (int)&v4->velocity;
    *(_DWORD *)v8 = 0;
    *(_DWORD *)(v8 + 4) = 0;
    *(_DWORD *)(v8 + 8) = 0;
  }
  if ( v3 & 2 )
  {
    v4->placement_id = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v4->placement_id = 0;
  }
  v4->has_contact = ((unsigned int)(unsigned __int8)v3 >> 2) & 1;
  v4->instance_timestamp = *(_WORD *)*addr;
  v9 = (char *)*addr + 2;
  *addr = v9;
  v4->position_timestamp = *(_WORD *)v9;
  v10 = (char *)*addr + 2;
  *addr = v10;
  v4->teleport_timestamp = *(_WORD *)v10;
  v11 = (char *)*addr + 2;
  *addr = v11;
  v4->force_position_timestamp = *(_WORD *)v11;
  *addr = (char *)*addr + 2;
  return 1;
}

//----- (005168A0) --------------------------------------------------------  // acclient.c:323786
int __thiscall MoveToStatePack::pack_size(MoveToStatePack *this)
{
  MoveToStatePack *v1; // esi@1
  PackObjVtbl *v2; // eax@1
  int v3; // edi@1
  int v4; // eax@1
  int v5; // ecx@1
  int v6; // eax@1
  int result; // eax@2
  void *foo; // [sp+8h] [bp-4h]@1

  foo = this;
  v1 = this;
  v2 = this->raw_motion_state.vfptr;
  foo = 0;
  v3 = ((int (__thiscall *)(RawMotionState *, void **, _DWORD))v2->Pack)(&this->raw_motion_state, &foo, 0);
  v4 = ((int (__stdcall *)(void **, _DWORD))v1->position.vfptr->Pack)(&foo, 0);
  v5 = v3 + v4 + 9;
  v6 = ((_BYTE)v3 + (_BYTE)v4 + 9) & 3;
  if ( v6 )
    result = 4 - v6 + v5;
  else
    result = v5;
  return result;
}

//----- (005168F0) --------------------------------------------------------  // acclient.c:323813
int __userpurge MoveToStatePack::Pack@<eax>(MoveToStatePack *this@<ecx>, int a2@<esi>, void **addr, unsigned int size)
{
  MoveToStatePack *v4; // edi@1
  int v5; // ebp@1
  char *v6; // ecx@2
  char *v7; // eax@2
  char *v8; // ebx@2
  char *v9; // edx@2

  v4 = this;
  v5 = MoveToStatePack::pack_size(this);
  if ( size >= v5 )
  {
    ((void (__thiscall *)(int, void **, unsigned int, int))v4->raw_motion_state.vfptr->Pack)(
      &v4->raw_motion_state,
      addr,
      size,
      a2);
    ((void (__thiscall *)(int))v4->position.vfptr->Pack)(&v4->position);
    *(_WORD *)*addr = v4->instance_timestamp;
    v6 = (char *)*addr + 2;
    *addr = v6;
    *(_WORD *)v6 = v4->server_control_timestamp;
    v7 = (char *)*addr + 2;
    *addr = v7;
    *(_WORD *)v7 = v4->teleport_timestamp;
    v8 = (char *)*addr + 2;
    *addr = v8;
    *(_WORD *)v8 = v4->force_position_ts;
    v9 = (char *)*addr + 2;
    *addr = v9;
    *v9 = (v4->contact != 0) | (v4->longjump_mode == 0 ? 0 : 2);
    *addr = (char *)*addr + 1;
    PackObj::ALIGN_PTR(addr);
  }
  return v5;
}
// 5168F0: could not find valid save-restore pair for esi

//----- (005169B0) --------------------------------------------------------  // acclient.c:323853
int __thiscall MoveToStatePack::UnPack(MoveToStatePack *this, void **addr, unsigned int size)
{
  MoveToStatePack *v3; // edi@1
  int result; // eax@2
  char *v5; // ebx@6
  char *v6; // edx@6
  char *v7; // ecx@6
  char *v8; // eax@6

  v3 = this;
  if ( size >= MoveToStatePack::pack_size(this) )
  {
    if ( ((int (__thiscall *)(int, void **, unsigned int))v3->raw_motion_state.vfptr->UnPack)(
           &v3->raw_motion_state,
           addr,
           size)
      && ((int (__thiscall *)(int, void **, unsigned int))v3->position.vfptr->UnPack)(&v3->position, addr, size) )
    {
      v3->instance_timestamp = *(_WORD *)*addr;
      v5 = (char *)*addr + 2;
      *addr = v5;
      v3->server_control_timestamp = *(_WORD *)v5;
      v6 = (char *)*addr + 2;
      *addr = v6;
      v3->teleport_timestamp = *(_WORD *)v6;
      v7 = (char *)*addr + 2;
      *addr = v7;
      v3->force_position_ts = *(_WORD *)v7;
      v8 = (char *)*addr + 2;
      *addr = v8;
      LOBYTE(v7) = *v8;
      *addr = v8 + 1;
      v3->contact = (unsigned __int8)v7 & 1;
      v3->longjump_mode = (unsigned __int8)v7 & 2;
      PackObj::ALIGN_PTR(addr);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00516A70) --------------------------------------------------------  // acclient.c:323903
void __thiscall AutonomousPositionPack::AutonomousPositionPack(AutonomousPositionPack *this, Position *_position, int _contact, unsigned __int16 _instance_timestamp, unsigned __int16 _server_control_timestamp, unsigned __int16 _teleport_timestamp, unsigned __int16 _force_position_ts)
{
  AutonomousPositionPack *v7; // esi@1
  char *v8; // ecx@1

  v7 = this;
  this->vfptr = (PackObjVtbl *)&AutonomousPositionPack::vftable;
  v8 = (char *)&this->position.frame;
  v7->position.vfptr = (PackObjVtbl *)&Position::vftable;
  v7->position.objcell_id = 0;
  *(_DWORD *)v8 = 1065353216;
  *((_DWORD *)v8 + 1) = 0;
  *((_DWORD *)v8 + 2) = 0;
  *((_DWORD *)v8 + 3) = 0;
  *((_DWORD *)v8 + 13) = 0;
  *((_DWORD *)v8 + 14) = 0;
  *((_DWORD *)v8 + 15) = 0;
  Frame::cache((Frame *)v8);
  v7->position.objcell_id = _position->objcell_id;
  Frame::operator=((int)&v7->position.frame, (int)&_position->frame);
  v7->instance_timestamp = _instance_timestamp;
  v7->contact = _contact;
  v7->force_position_ts = _force_position_ts;
  v7->server_control_timestamp = _server_control_timestamp;
  v7->teleport_timestamp = _teleport_timestamp;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C6BCC: using guessed type int (__thiscall *AutonomousPositionPack::vftable)(void *, char);

//----- (00516AF0) --------------------------------------------------------  // acclient.c:323933
int __thiscall AutonomousPositionPack::Pack(AutonomousPositionPack *this, void **addr, unsigned int size)
{
  AutonomousPositionPack *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebx@1
  int v6; // eax@1
  int v7; // edx@2
  int v8; // ebp@4
  char *v9; // ebx@5
  char *v10; // edx@5
  char *v11; // ecx@5
  char *v12; // eax@5
  int v14; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = this->position.vfptr;
  v5 = (char *)&this->position;
  v14 = 0;
  v6 = ((int (__thiscall *)(Position *, int *, _DWORD))v4->Pack)(&this->position, &v14, 0) + 9;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  v8 = v7 + v6;
  if ( size >= v7 + v6 )
  {
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
    *(_WORD *)*addr = v3->instance_timestamp;
    v9 = (char *)*addr + 2;
    *addr = v9;
    *(_WORD *)v9 = v3->server_control_timestamp;
    v10 = (char *)*addr + 2;
    *addr = v10;
    *(_WORD *)v10 = v3->teleport_timestamp;
    v11 = (char *)*addr + 2;
    *addr = v11;
    *(_WORD *)v11 = v3->force_position_ts;
    v12 = (char *)*addr + 2;
    *addr = v12;
    *v12 = v3->contact != 0;
    *addr = (char *)*addr + 1;
    PackObj::ALIGN_PTR(addr);
  }
  return v8;
}

//----- (00516BA0) --------------------------------------------------------  // acclient.c:323980
int __thiscall AutonomousPositionPack::UnPack(AutonomousPositionPack *this, void **addr, unsigned int size)
{
  AutonomousPositionPack *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebx@1
  int v6; // eax@1
  int v7; // edx@2
  int result; // eax@5
  char *v9; // ebx@7
  char *v10; // edx@7
  char *v11; // ecx@7
  char *v12; // eax@7
  AutonomousPositionPack *v13; // [sp+0h] [bp-4h]@1

  v13 = this;
  v3 = this;
  v4 = this->position.vfptr;
  v5 = (char *)&this->position;
  v13 = 0;
  v6 = ((int (__thiscall *)(Position *, int *, _DWORD))v4->Pack)(&this->position, &v13, 0) + 9;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  if ( size >= v6 + v7 )
  {
    result = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 16))(v5, addr, size);
    if ( result )
    {
      v3->instance_timestamp = *(_WORD *)*addr;
      v9 = (char *)*addr + 2;
      *addr = v9;
      v3->server_control_timestamp = *(_WORD *)v9;
      v10 = (char *)*addr + 2;
      *addr = v10;
      v3->teleport_timestamp = *(_WORD *)v10;
      v11 = (char *)*addr + 2;
      *addr = v11;
      v3->force_position_ts = *(_WORD *)v11;
      v12 = (char *)*addr + 2;
      *addr = v12;
      LOBYTE(v11) = *v12;
      *addr = v12 + 1;
      v3->contact = (_BYTE)v11 != 0;
      PackObj::ALIGN_PTR(addr);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00516C70) --------------------------------------------------------  // acclient.c:324036
void __thiscall JumpPack::JumpPack(JumpPack *this, float _extent, AC1Legacy::Vector3 *_velocity, Position *_position, unsigned __int16 _instance_timestamp, unsigned __int16 _server_control_timestamp, unsigned __int16 _teleport_timestamp, unsigned __int16 _force_position_ts)
{
  JumpPack *v8; // esi@1
  char *v9; // ecx@1

  v8 = this;
  this->vfptr = (PackObjVtbl *)&JumpPack::vftable;
  v9 = (char *)&this->position.frame;
  v8->position.vfptr = (PackObjVtbl *)&Position::vftable;
  v8->position.objcell_id = 0;
  *(_DWORD *)v9 = 1065353216;
  *((_DWORD *)v9 + 1) = 0;
  *((_DWORD *)v9 + 2) = 0;
  *((_DWORD *)v9 + 3) = 0;
  *((_DWORD *)v9 + 13) = 0;
  *((_DWORD *)v9 + 14) = 0;
  *((_DWORD *)v9 + 15) = 0;
  Frame::cache((Frame *)v9);
  v8->extent = _extent;
  v8->velocity = *_velocity;
  v8->position.objcell_id = _position->objcell_id;
  Frame::operator=((int)&v8->position.frame, (int)&_position->frame);
  v8->instance_timestamp = _instance_timestamp;
  v8->server_control_timestamp = _server_control_timestamp;
  v8->teleport_timestamp = _teleport_timestamp;
  v8->force_position_ts = _force_position_ts;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C6BE0: using guessed type int (__thiscall *JumpPack::vftable)(void *, char);

//----- (00516D10) --------------------------------------------------------  // acclient.c:324067
int __thiscall JumpPack::Pack(JumpPack *this, void **addr, unsigned int size)
{
  JumpPack *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebx@1
  int v6; // eax@1
  int v7; // edx@2
  int v8; // ebp@4
  char *v9; // ecx@5
  char *v10; // ecx@6
  char *v11; // edx@6
  char *v12; // ecx@7
  char *v13; // eax@7
  char *v14; // ebx@7
  int v16; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = this->position.vfptr;
  v5 = (char *)&this->position;
  v16 = 0;
  v6 = ((int (__thiscall *)(Position *, int *, _DWORD))v4->Pack)(&this->position, &v16, 0) + 24;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  v8 = v7 + v6;
  if ( size >= v7 + v6 )
  {
    *(float *)*addr = v3->extent;
    v9 = (char *)*addr + 4;
    *addr = v9;
    if ( size >= 0xC )
    {
      *(_DWORD *)v9 = LODWORD(v3->velocity.x);
      v10 = (char *)*addr + 4;
      *addr = v10;
      *(float *)v10 = v3->velocity.y;
      v11 = (char *)*addr + 4;
      *addr = v11;
      *(float *)v11 = v3->velocity.z;
      *addr = (char *)*addr + 4;
    }
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
    *(_WORD *)*addr = v3->instance_timestamp;
    v12 = (char *)*addr + 2;
    *addr = v12;
    *(_WORD *)v12 = v3->server_control_timestamp;
    v13 = (char *)*addr + 2;
    *addr = v13;
    *(_WORD *)v13 = v3->teleport_timestamp;
    v14 = (char *)*addr + 2;
    *addr = v14;
    *(_WORD *)v14 = v3->force_position_ts;
    *addr = (char *)*addr + 2;
    PackObj::ALIGN_PTR(addr);
  }
  return v8;
}

//----- (00516DF0) --------------------------------------------------------  // acclient.c:324127
int __thiscall JumpPack::UnPack(JumpPack *this, void **addr, unsigned int size)
{
  JumpPack *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebx@1
  int v6; // eax@1
  int v7; // edx@2
  int result; // eax@5
  char *v9; // eax@6
  char *v10; // eax@7
  char *v11; // edx@7
  char *v12; // ecx@8
  char *v13; // eax@8
  char *v14; // ebx@8
  JumpPack *v15; // [sp+0h] [bp-4h]@1

  v15 = this;
  v3 = this;
  v4 = this->position.vfptr;
  v5 = (char *)&this->position;
  v15 = 0;
  v6 = ((int (__thiscall *)(Position *, int *, _DWORD))v4->Pack)(&this->position, &v15, 0) + 24;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  if ( size >= v6 + v7 )
  {
    LODWORD(v3->extent) = *(_DWORD *)*addr;
    v9 = (char *)*addr + 4;
    *addr = v9;
    if ( size >= 0xC
      && (LODWORD(v3->velocity.x) = *(_DWORD *)v9,
          v10 = (char *)*addr + 4,
          *addr = v10,
          LODWORD(v3->velocity.y) = *(_DWORD *)v10,
          v11 = (char *)*addr + 4,
          *addr = v11,
          LODWORD(v3->velocity.z) = *(_DWORD *)v11,
          *addr = (char *)*addr + 4,
          (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 16))(v5, addr, size)) )
    {
      v3->instance_timestamp = *(_WORD *)*addr;
      v12 = (char *)*addr + 2;
      *addr = v12;
      v3->server_control_timestamp = *(_WORD *)v12;
      v13 = (char *)*addr + 2;
      *addr = v13;
      v3->teleport_timestamp = *(_WORD *)v13;
      v14 = (char *)*addr + 2;
      *addr = v14;
      v3->force_position_ts = *(_WORD *)v14;
      *addr = (char *)*addr + 2;
      PackObj::ALIGN_PTR(addr);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00516EF0) --------------------------------------------------------  // acclient.c:324196
void __thiscall PhysicsTimestampPack::PhysicsTimestampPack(PhysicsTimestampPack *this)
{
  this->vfptr = (PackObjVtbl *)&PhysicsTimestampPack::vftable;
  this->ts1 = 0;
  this->ts2 = 0;
}
// 7C6BF4: using guessed type int (__thiscall *PhysicsTimestampPack::vftable)(void *, char);

//----- (00516F10) --------------------------------------------------------  // acclient.c:324205
signed int __thiscall PhysicsTimestampPack::Pack(PhysicsTimestampPack *this, void **addr, unsigned int size)
{
  char *v3; // esi@2

  if ( size >= 4 )
  {
    *(_WORD *)*addr = this->ts1;
    v3 = (char *)*addr + 2;
    *addr = v3;
    *(_WORD *)v3 = this->ts2;
    *addr = (char *)*addr + 2;
    PackObj::ALIGN_PTR(addr);
  }
  return 4;
}

//----- (00516F50) --------------------------------------------------------  // acclient.c:324222
int __thiscall PhysicsTimestampPack::UnPack(PhysicsTimestampPack *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3

  if ( size >= 4 )
  {
    this->ts1 = *(_WORD *)*addr;
    v4 = (char *)*addr + 2;
    *addr = v4;
    this->ts2 = *(_WORD *)v4;
    *addr = (char *)*addr + 2;
    PackObj::ALIGN_PTR(addr);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00516F90) --------------------------------------------------------  // acclient.c:324245
PositionPack *__thiscall PositionPack::vector_deleting_destructor(PositionPack *this, unsigned int a2)
{
  PositionPack *v2; // esi@1

  v2 = this;
  this->position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00516FC0) --------------------------------------------------------  // acclient.c:324259
MoveToStatePack *__thiscall MoveToStatePack::vector_deleting_destructor(MoveToStatePack *this, unsigned int a2)
{
  MoveToStatePack *v2; // esi@1

  v2 = this;
  this->position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  RawMotionState::~RawMotionState(&this->raw_motion_state);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00516FF0) --------------------------------------------------------  // acclient.c:324274
void __thiscall MoveToStatePack::MoveToStatePack(MoveToStatePack *this, RawMotionState *_raw_motion_state, Position *_position, int _contact, int _longjump_mode, unsigned __int16 _instance_timestamp, unsigned __int16 _server_control_timestamp, unsigned __int16 _teleport_timestamp, unsigned __int16 _force_position_ts)
{
  MoveToStatePack *v9; // esi@1
  RawMotionState *v10; // edi@1
  int v11; // ecx@1

  v9 = this;
  v10 = &this->raw_motion_state;
  this->vfptr = (PackObjVtbl *)&MoveToStatePack::vftable;
  RawMotionState::RawMotionState(&this->raw_motion_state);
  v11 = (int)&v9->position.frame;
  v9->position.vfptr = (PackObjVtbl *)&Position::vftable;
  v9->position.objcell_id = 0;
  *(_DWORD *)v11 = 1065353216;
  *(_DWORD *)(v11 + 4) = 0;
  *(_DWORD *)(v11 + 8) = 0;
  *(_DWORD *)(v11 + 12) = 0;
  *(_DWORD *)(v11 + 52) = 0;
  *(_DWORD *)(v11 + 56) = 0;
  *(_DWORD *)(v11 + 60) = 0;
  Frame::cache(&v9->position.frame);
  RawMotionState::operator=(v10, (int)_raw_motion_state);
  v9->position.objcell_id = _position->objcell_id;
  Frame::operator=((int)&v9->position.frame, (int)&_position->frame);
  v9->longjump_mode = _longjump_mode;
  v9->contact = _contact;
  v9->instance_timestamp = _instance_timestamp;
  v9->teleport_timestamp = _teleport_timestamp;
  v9->server_control_timestamp = _server_control_timestamp;
  v9->force_position_ts = _force_position_ts;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C6BB8: using guessed type int (__thiscall *MoveToStatePack::vftable)(void *, char);

//----- (005170A0) --------------------------------------------------------  // acclient.c:324309
JumpPack *__thiscall JumpPack::scalar_deleting_destructor(JumpPack *this, unsigned int a2)
{
  JumpPack *v2; // esi@1

  v2 = this;
  this->position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (006FC3D0) --------------------------------------------------------  // acclient.c:784591
void sub_6FC3D0()
{
  flt_843F3C = 1000.0 + 1.0;
}

//----- (006FC3F0) --------------------------------------------------------  // acclient.c:784597
void sub_6FC3F0()
{
  flt_843F40 = 24.0 * 8.0;
}

//----- (006FC410) --------------------------------------------------------  // acclient.c:784603
void sub_6FC410()
{
  flt_843F44 = 24.0 * 0.5;
}

//----- (006FC430) --------------------------------------------------------  // acclient.c:784609
int sub_6FC430()
{
  return atexit(nullsub_1111);
}

