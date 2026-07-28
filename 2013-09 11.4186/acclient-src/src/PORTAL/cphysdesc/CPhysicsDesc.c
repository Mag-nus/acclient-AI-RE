/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsDesc
   Object     : PORTAL\cphysdesc\CPhysicsDesc.obj
   Functions  : 20
   Addresses  : 0051D450 - 006FCE50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051D450) --------------------------------------------------------  // acclient.c:331296
unsigned __int16 __thiscall PhysicsDesc::get_timestamp(PhysicsDesc *this, PhysicsTimeStamp stamp)
{
  return this->timestamps[stamp];
}

//----- (0051D460) --------------------------------------------------------  // acclient.c:331302
unsigned int __thiscall PhysicsDesc::get_parent_id(PhysicsDesc *this)
{
  return this->parent_id;
}

//----- (0051D480) --------------------------------------------------------  // acclient.c:331314
unsigned int __thiscall UIFlow::GetPersistantData(PhysicsDesc *this)
{
  return this->num_children;
}

//----- (0051D490) --------------------------------------------------------  // acclient.c:331320
unsigned int __thiscall PhysicsDesc::get_child_id(PhysicsDesc *this, unsigned int index)
{
  return this->child_ids[index];
}

//----- (0051D4A0) --------------------------------------------------------  // acclient.c:331326
unsigned int __thiscall PhysicsDesc::get_child_location_id(PhysicsDesc *this, unsigned int index)
{
  return this->child_location_ids[index];
}

//----- (0051D4D0) --------------------------------------------------------  // acclient.c:331344
void __thiscall PhysicsDesc::PhysicsDesc(PhysicsDesc *this)
{
  PhysicsDesc *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PhysicsDesc::vftable;
  v2 = (char *)&this->pos.frame;
  v1->bitfield = 0;
  v1->movement_buffer = 0;
  v1->buff_length = 0;
  v1->autonomous_movement = 0;
  v1->animframe_id = 0;
  v1->pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->friction = DEFAULT_FRICTION_0;
  v1->state = 4197384;
  LODWORD(v1->object_scale) = 1065353216;
  v1->elasticity = DEFAULT_ELASTICITY_0;
  v1->translucency = DEFAULT_TRANSLUCENCY_0;
  LODWORD(v1->velocity.x) = 0;
  LODWORD(v1->velocity.y) = 0;
  LODWORD(v1->velocity.z) = 0;
  LODWORD(v1->acceleration.x) = 0;
  LODWORD(v1->acceleration.y) = 0;
  LODWORD(v1->acceleration.z) = 0;
  LODWORD(v1->omega.x) = 0;
  LODWORD(v1->omega.y) = 0;
  LODWORD(v1->omega.z) = 0;
  v1->num_children = 0;
  v1->child_ids = 0;
  v1->child_location_ids = 0;
  v1->parent_id = 0;
  v1->mtable_id.id = 0;
  v1->stable_id.id = 0;
  v1->phstable_id.id = 0;
  v1->default_script = 0;
  LODWORD(v1->default_script_intensity) = 0;
  v1->setup_id.id = 0;
  *(_DWORD *)&v1->timestamps[0] = 0;
  *(_DWORD *)&v1->timestamps[2] = 0;
  *(_DWORD *)&v1->timestamps[4] = 0;
  *(_DWORD *)&v1->timestamps[6] = 0;
  v1->timestamps[8] = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7C729C: using guessed type int (__thiscall *PhysicsDesc::vftable)(void *, char);

//----- (0051D5D0) --------------------------------------------------------  // acclient.c:331401
void __thiscall PhysicsDesc::Destroy(PhysicsDesc *this)
{
  PhysicsDesc *v1; // esi@1
  void *v2; // ST00_4@5
  int v3; // edx@5
  int v4; // ecx@5
  int v5; // eax@5
  int v6; // eax@5

  v1 = this;
  if ( this->child_ids )
  {
    operator delete[](this->child_ids);
    v1->child_ids = 0;
  }
  if ( v1->child_location_ids )
  {
    operator delete[](v1->child_location_ids);
    v1->child_location_ids = 0;
  }
  v2 = v1->movement_buffer;
  v1->num_children = 0;
  operator delete[](v2);
  v1->movement_buffer = 0;
  v1->buff_length = 0;
  v1->animframe_id = 0;
  v1->pos.objcell_id = 0;
  v1->num_children = 0;
  v1->child_ids = 0;
  v1->child_location_ids = 0;
  v1->parent_id = 0;
  v1->state = 4197384;
  v1->mtable_id.id = stru_8442C4.id;
  v1->stable_id.id = stru_8442C4.id;
  v1->phstable_id.id = stru_8442C4.id;
  v1->setup_id.id = stru_8442C4.id;
  v3 = (int)&v1->velocity;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  v4 = (int)&v1->acceleration;
  *(_DWORD *)v4 = 0;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  v5 = (int)&v1->omega;
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 0;
  v1->default_script = 0;
  LODWORD(v1->default_script_intensity) = 0;
  LODWORD(v1->object_scale) = 1065353216;
  *(_DWORD *)(v5 + 8) = 0;
  v6 = (int)v1->timestamps;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 0;
  *(_WORD *)(v6 + 16) = 0;
}

//----- (0051D740) --------------------------------------------------------  // acclient.c:331461
void __thiscall PhysicsDesc::~PhysicsDesc(PhysicsDesc *this)
{
  PhysicsDesc *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PhysicsDesc::vftable;
  PhysicsDesc::Destroy(this);
  v1->pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C729C: using guessed type int (__thiscall *PhysicsDesc::vftable)(void *, char);

//----- (0051D760) --------------------------------------------------------  // acclient.c:331475
IDClass<_tagDataID,32,0> *__thiscall PhysicsDesc::get_mtable_id(PhysicsDesc *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->mtable_id.id;
  return v2;
}

//----- (0051D770) --------------------------------------------------------  // acclient.c:331485
IDClass<_tagDataID,32,0> *__thiscall PhysicsDesc::get_setup_id(PhysicsDesc *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->setup_id.id;
  return v2;
}

//----- (0051D780) --------------------------------------------------------  // acclient.c:331495
PhysicsDesc *__thiscall PhysicsDesc::vector_deleting_destructor(PhysicsDesc *this, unsigned int a2)
{
  PhysicsDesc *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PhysicsDesc::vftable;
  PhysicsDesc::Destroy(this);
  v2->pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C729C: using guessed type int (__thiscall *PhysicsDesc::vftable)(void *, char);

//----- (0051D7C0) --------------------------------------------------------  // acclient.c:331512
int __thiscall PhysicsDesc::Pack(PhysicsDesc *this, void **addr, unsigned int size)
{
  PhysicsDesc *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@3
  unsigned int v6; // eax@37
  int v7; // esi@37
  unsigned int v8; // eax@44
  int v9; // esi@74
  int v10; // ecx@75
  int v11; // esi@77
  char *v12; // eax@78
  char *v13; // edi@78
  unsigned int v14; // ecx@78
  char *v15; // ecx@79
  char *v16; // edx@80
  unsigned int v17; // eax@84
  unsigned int v18; // eax@88
  unsigned int v19; // eax@90
  char *v20; // ecx@95
  char *v21; // eax@97
  char *v22; // ecx@97
  unsigned int v23; // eax@97
  char *v24; // edx@98
  unsigned int v25; // eax@101
  unsigned int v26; // eax@103
  char *v27; // edx@109
  char *v28; // ecx@109
  char *v29; // edx@112
  char *v30; // ecx@112
  char *v31; // edx@115
  char *v32; // ecx@115
  unsigned int v33; // eax@116
  unsigned int v34; // eax@118
  char *v35; // eax@120
  char *v36; // edi@120
  char *v37; // edx@120
  char *v38; // ecx@120
  char *v39; // eax@120
  char *v40; // edi@120
  char *v41; // edx@120
  char *v42; // ecx@120
  char *v43; // eax@120
  int v44; // eax@120
  int v45; // ecx@121
  void *mem; // [sp+10h] [bp-14h]@37
  unsigned int size_needed; // [sp+14h] [bp-10h]@77
  Vector3 _rhs; // [sp+18h] [bp-Ch]@27

  v3 = this;
  v4 = this->pos.objcell_id;
  this->bitfield = 0;
  if ( v4 )
    this->bitfield = 0x8000;
  v5 = this->buff_length;
  if ( v5 > 0 )
    this->bitfield |= 0x10000u;
  if ( this->animframe_id )
    this->bitfield |= 0x20000u;
  if ( this->mtable_id.id )
    this->bitfield |= 2u;
  if ( this->stable_id.id )
    this->bitfield |= 0x800u;
  if ( this->phstable_id.id )
    this->bitfield |= 0x1000u;
  if ( this->setup_id.id )
    this->bitfield |= 1u;
  if ( this->parent_id )
    this->bitfield |= 0x20u;
  if ( this->num_children )
    this->bitfield |= 0x40u;
  if ( LODWORD(this->object_scale) != 1065353216 )
    this->bitfield |= 0x80u;
  if ( this->friction != 0.94999999 )
    this->bitfield |= 0x100u;
  if ( this->elasticity != 0.050000001 )
    this->bitfield |= 0x200u;
  if ( this->translucency != 0.0 )
    this->bitfield |= 0x40000u;
  LODWORD(_rhs.x) = 0;
  LODWORD(_rhs.y) = 0;
  LODWORD(_rhs.z) = 0;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&this->velocity.x, &_rhs) )
    v3->bitfield |= 4u;
  LODWORD(_rhs.x) = 0;
  LODWORD(_rhs.y) = 0;
  LODWORD(_rhs.z) = 0;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&v3->acceleration.x, &_rhs) )
    v3->bitfield |= 8u;
  LODWORD(_rhs.x) = 0;
  LODWORD(_rhs.y) = 0;
  LODWORD(_rhs.z) = 0;
  if ( (unsigned __int8)Vector3::operator!=((Vector3 *)&v3->omega.x, &_rhs) )
    v3->bitfield |= 0x10u;
  if ( v3->default_script )
    v3->bitfield |= 0x2000u;
  if ( v3->default_script_intensity != 0.0 )
    v3->bitfield |= 0x4000u;
  v6 = v3->bitfield;
  mem = 0;
  v7 = 8;
  if ( v6 & 0x10000 )
  {
    v7 = 12;
    if ( v5 )
      v7 = v5 + 16;
  }
  else if ( v6 & 0x20000 )
  {
    v7 = 12;
  }
  if ( SBYTE1(v6) < 0 )
    v7 += ((int (__thiscall *)(int, void **, _DWORD))v3->pos.vfptr->Pack)(&v3->pos, &mem, 0);
  v8 = v3->bitfield;
  if ( v8 & 2 )
    v7 += 4;
  if ( BYTE1(v8) & 8 )
    v7 += 4;
  if ( BYTE1(v8) & 0x10 )
    v7 += 4;
  if ( v8 & 1 )
    v7 += 4;
  if ( v8 & 0x20 )
    v7 += 8;
  if ( v8 & 0x40 )
    v7 += 8 * v3->num_children + 4;
  if ( (v8 & 0x80u) != 0 )
    v7 += 4;
  if ( BYTE1(v8) & 1 )
    v7 += 4;
  if ( BYTE1(v8) & 2 )
    v7 += 4;
  if ( v8 & 0x40000 )
    v7 += 4;
  if ( v8 & 4 )
    v7 += 12;
  if ( v8 & 8 )
    v7 += 12;
  if ( v8 & 0x10 )
    v7 += 12;
  if ( BYTE1(v8) & 0x20 )
    v7 += 4;
  if ( BYTE1(v8) & 0x40 )
    v7 += 4;
  v9 = v7 + 18;
  if ( v9 & 3 )
    v10 = 4 - (v9 & 3);
  else
    v10 = 0;
  v11 = v10 + v9;
  size_needed = v11;
  if ( size >= v11 )
  {
    *(_DWORD *)*addr = v8;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->state;
    v13 = (char *)*addr + 4;
    *addr = v13;
    v14 = v3->bitfield;
    if ( v14 & 0x10000 )
    {
      *(_DWORD *)v13 = v3->buff_length;
      v15 = (char *)*addr + 4;
      *addr = v15;
      if ( v3->buff_length )
      {
        qmemcpy(v15, v3->movement_buffer, v3->buff_length);
        v11 = size_needed;
        v16 = (char *)*addr + v3->buff_length;
        *addr = v16;
        *(_DWORD *)v16 = v3->autonomous_movement;
LABEL_83:
        *addr = (char *)*addr + 4;
        goto LABEL_84;
      }
    }
    else if ( v14 & 0x20000 )
    {
      *(_DWORD *)v13 = v3->animframe_id;
      goto LABEL_83;
    }
LABEL_84:
    v17 = v3->bitfield;
    if ( SBYTE1(v17) < 0 )
      ((void (__thiscall *)(int, void **, unsigned int))v3->pos.vfptr->Pack)(&v3->pos, addr, size);
    if ( v3->bitfield & 2 )
    {
      *(_DWORD *)*addr = v3->mtable_id.id;
      *addr = (char *)*addr + 4;
    }
    v18 = v3->bitfield;
    if ( BYTE1(v18) & 8 )
    {
      *(_DWORD *)*addr = v3->stable_id.id;
      *addr = (char *)*addr + 4;
    }
    v19 = v3->bitfield;
    if ( BYTE1(v19) & 0x10 )
    {
      *(_DWORD *)*addr = v3->phstable_id.id;
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 1 )
    {
      *(_DWORD *)*addr = v3->setup_id.id;
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 0x20 )
    {
      *(_DWORD *)*addr = v3->parent_id;
      v20 = (char *)*addr + 4;
      *addr = v20;
      *(_DWORD *)v20 = v3->location_id;
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 0x40 )
    {
      *(_DWORD *)*addr = v3->num_children;
      v21 = (char *)*addr + 4;
      *addr = v21;
      v22 = v21;
      v23 = 0;
      if ( v3->num_children )
      {
        do
        {
          *(_DWORD *)v22 = v3->child_ids[v23];
          v24 = (char *)*addr + 4;
          *addr = v24;
          *(_DWORD *)v24 = v3->child_location_ids[v23];
          v22 = (char *)*addr + 4;
          *addr = v22;
          ++v23;
        }
        while ( v23 < v3->num_children );
      }
    }
    if ( SLOBYTE(v3->bitfield) < 0 )
    {
      *(_DWORD *)*addr = LODWORD(v3->object_scale);
      *addr = (char *)*addr + 4;
    }
    v25 = v3->bitfield;
    if ( BYTE1(v25) & 1 )
    {
      *(_DWORD *)*addr = LODWORD(v3->friction);
      *addr = (char *)*addr + 4;
    }
    v26 = v3->bitfield;
    if ( BYTE1(v26) & 2 )
    {
      *(_DWORD *)*addr = LODWORD(v3->elasticity);
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 0x40000 )
    {
      *(_DWORD *)*addr = LODWORD(v3->translucency);
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 4 && size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(v3->velocity.x);
      v27 = (char *)*addr + 4;
      *addr = v27;
      *(float *)v27 = v3->velocity.y;
      v28 = (char *)*addr + 4;
      *addr = v28;
      *(float *)v28 = v3->velocity.z;
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 8 && size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(v3->acceleration.x);
      v29 = (char *)*addr + 4;
      *addr = v29;
      *(float *)v29 = v3->acceleration.y;
      v30 = (char *)*addr + 4;
      *addr = v30;
      *(float *)v30 = v3->acceleration.z;
      *addr = (char *)*addr + 4;
    }
    if ( v3->bitfield & 0x10 && size >= 0xC )
    {
      *(_DWORD *)*addr = LODWORD(v3->omega.x);
      v31 = (char *)*addr + 4;
      *addr = v31;
      *(float *)v31 = v3->omega.y;
      v32 = (char *)*addr + 4;
      *addr = v32;
      *(float *)v32 = v3->omega.z;
      *addr = (char *)*addr + 4;
    }
    v33 = v3->bitfield;
    if ( BYTE1(v33) & 0x20 )
    {
      *(_DWORD *)*addr = v3->default_script;
      *addr = (char *)*addr + 4;
    }
    v34 = v3->bitfield;
    if ( BYTE1(v34) & 0x40 )
    {
      *(_DWORD *)*addr = LODWORD(v3->default_script_intensity);
      *addr = (char *)*addr + 4;
    }
    *(_WORD *)*addr = v3->timestamps[0];
    v35 = (char *)*addr + 2;
    *addr = v35;
    *(_WORD *)v35 = v3->timestamps[1];
    v36 = (char *)*addr + 2;
    *addr = v36;
    *(_WORD *)v36 = v3->timestamps[2];
    v37 = (char *)*addr + 2;
    *addr = v37;
    *(_WORD *)v37 = v3->timestamps[3];
    v38 = (char *)*addr + 2;
    *addr = v38;
    *(_WORD *)v38 = v3->timestamps[4];
    v39 = (char *)*addr + 2;
    *addr = v39;
    *(_WORD *)v39 = v3->timestamps[5];
    v40 = (char *)*addr + 2;
    *addr = v40;
    *(_WORD *)v40 = v3->timestamps[6];
    v41 = (char *)*addr + 2;
    *addr = v41;
    *(_WORD *)v41 = v3->timestamps[7];
    v42 = (char *)*addr + 2;
    *addr = v42;
    *(_WORD *)v42 = v3->timestamps[8];
    v43 = (char *)*addr + 2;
    *addr = v43;
    v44 = (signed int)v43 % 4;
    if ( v44 )
    {
      v45 = 4 - v44;
      if ( 4 != v44 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v45;
          *addr = (char *)*addr + 1;
        }
        while ( v45 );
      }
    }
  }
  return v11;
}

//----- (0051DDD0) --------------------------------------------------------  // acclient.c:331864
int __thiscall PhysicsDesc::UnPack(PhysicsDesc *this, void **addr, unsigned int size)
{
  PhysicsDesc *v3; // ebx@1
  char *v4; // edi@1
  char *v5; // esi@1
  unsigned int v6; // eax@1
  void *v7; // eax@3
  unsigned int v8; // ecx@3
  char *v9; // ecx@3
  unsigned int v10; // eax@7
  unsigned int v11; // ecx@11
  unsigned int v12; // eax@13
  unsigned int v13; // ecx@14
  unsigned int v14; // eax@16
  unsigned int v15; // ecx@17
  bool v16; // zf@19
  unsigned int v17; // ecx@20
  char *v18; // ecx@23
  void *v19; // eax@26
  unsigned int v20; // ecx@26
  unsigned int v21; // eax@26
  char *v22; // edx@27
  unsigned int v23; // eax@32
  unsigned int v24; // eax@34
  char *v25; // edx@40
  char *v26; // ecx@40
  char *v27; // edx@43
  char *v28; // ecx@43
  char *v29; // edx@46
  char *v30; // ecx@46
  unsigned int v31; // eax@47
  unsigned int v32; // eax@50
  char *v33; // esi@53
  char *v34; // edx@53
  char *v35; // ecx@53
  char *v36; // eax@53
  char *v37; // edi@53
  char *v38; // esi@53
  char *v39; // edx@53
  char *v40; // ecx@53
  char *v41; // eax@53
  int v42; // eax@53
  int v43; // ecx@54
  Frame v45; // [sp+18h] [bp-40h]@9

  v3 = this;
  PhysicsDesc::Destroy(this);
  v3->bitfield = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  v3->state = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  v6 = v3->bitfield;
  if ( v6 & 0x10000 )
  {
    v3->buff_length = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    if ( v3->buff_length )
    {
      v7 = operator new[](v3->buff_length);
      v8 = v3->buff_length;
      v3->movement_buffer = v7;
      qmemcpy(v7, *addr, v8);
      v9 = (char *)*addr + v3->buff_length;
      *addr = v9;
      v3->autonomous_movement = *(_DWORD *)v9;
      *addr = (char *)*addr + 4;
    }
  }
  else
  {
    v3->movement_buffer = 0;
    if ( v6 & 0x20000 )
    {
      v3->animframe_id = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
    }
    else
    {
      v3->animframe_id = 0;
    }
  }
  v10 = v3->bitfield;
  if ( SBYTE1(v10) >= 0 )
  {
    LODWORD(v45.qw) = 1065353216;
    LODWORD(v45.qx) = 0;
    LODWORD(v45.qy) = 0;
    LODWORD(v45.qz) = 0;
    LODWORD(v45.m_fOrigin.x) = 0;
    LODWORD(v45.m_fOrigin.y) = 0;
    LODWORD(v45.m_fOrigin.z) = 0;
    Frame::cache(&v45);
    v3->pos.objcell_id = 0;
    Frame::operator=((int)&v3->pos.frame, (int)&v45);
  }
  else
  {
    ((void (__thiscall *)(int, void **, unsigned int))v3->pos.vfptr->UnPack)(&v3->pos, addr, size);
  }
  if ( v3->bitfield & 2 )
  {
    v11 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3->mtable_id.id = v11;
  }
  else
  {
    v3->mtable_id.id = stru_8442C4.id;
  }
  v12 = v3->bitfield;
  if ( BYTE1(v12) & 8 )
  {
    v13 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3->stable_id.id = v13;
  }
  else
  {
    v3->stable_id.id = stru_8442C4.id;
  }
  v14 = v3->bitfield;
  if ( BYTE1(v14) & 0x10 )
  {
    v15 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v15 = stru_8442C4.id;
  }
  v16 = (v3->bitfield & 1) == 0;
  v3->phstable_id.id = v15;
  if ( v16 )
  {
    v3->setup_id.id = stru_8442C4.id;
  }
  else
  {
    v17 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3->setup_id.id = v17;
  }
  if ( v3->bitfield & 0x20 )
  {
    v3->parent_id = *(_DWORD *)*addr;
    v18 = (char *)*addr + 4;
    *addr = v18;
    v3->location_id = *(_DWORD *)v18;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->parent_id = 0;
  }
  if ( v3->bitfield & 0x40 )
  {
    v3->num_children = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3->child_ids = (unsigned int *)operator new[](4 * v3->num_children);
    v19 = operator new[](4 * v3->num_children);
    v20 = v3->num_children;
    v3->child_location_ids = (unsigned int *)v19;
    v21 = 0;
    if ( v20 > 0 )
    {
      do
      {
        v3->child_ids[v21] = *(_DWORD *)*addr;
        v22 = (char *)*addr + 4;
        *addr = v22;
        v3->child_location_ids[v21] = *(_DWORD *)v22;
        *addr = (char *)*addr + 4;
        ++v21;
      }
      while ( v21 < v3->num_children );
    }
  }
  else
  {
    v3->child_ids = 0;
    v3->child_location_ids = 0;
  }
  if ( SLOBYTE(v3->bitfield) < 0 )
  {
    LODWORD(v3->object_scale) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  v23 = v3->bitfield;
  if ( BYTE1(v23) & 1 )
  {
    LODWORD(v3->friction) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  v24 = v3->bitfield;
  if ( BYTE1(v24) & 2 )
  {
    LODWORD(v3->elasticity) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v3->bitfield & 0x40000 )
  {
    LODWORD(v3->translucency) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  if ( v3->bitfield & 4 && size >= 0xC )
  {
    LODWORD(v3->velocity.x) = *(_DWORD *)*addr;
    v25 = (char *)*addr + 4;
    *addr = v25;
    LODWORD(v3->velocity.y) = *(_DWORD *)v25;
    v26 = (char *)*addr + 4;
    *addr = v26;
    LODWORD(v3->velocity.z) = *(_DWORD *)v26;
    *addr = (char *)*addr + 4;
  }
  if ( v3->bitfield & 8 && size >= 0xC )
  {
    LODWORD(v3->acceleration.x) = *(_DWORD *)*addr;
    v27 = (char *)*addr + 4;
    *addr = v27;
    LODWORD(v3->acceleration.y) = *(_DWORD *)v27;
    v28 = (char *)*addr + 4;
    *addr = v28;
    LODWORD(v3->acceleration.z) = *(_DWORD *)v28;
    *addr = (char *)*addr + 4;
  }
  if ( v3->bitfield & 0x10 && size >= 0xC )
  {
    LODWORD(v3->omega.x) = *(_DWORD *)*addr;
    v29 = (char *)*addr + 4;
    *addr = v29;
    LODWORD(v3->omega.y) = *(_DWORD *)v29;
    v30 = (char *)*addr + 4;
    *addr = v30;
    LODWORD(v3->omega.z) = *(_DWORD *)v30;
    *addr = (char *)*addr + 4;
  }
  v31 = v3->bitfield;
  if ( BYTE1(v31) & 0x20 )
  {
    v3->default_script = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    v3->default_script = 0;
  }
  v32 = v3->bitfield;
  if ( BYTE1(v32) & 0x40 )
  {
    LODWORD(v3->default_script_intensity) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
  }
  else
  {
    LODWORD(v3->default_script_intensity) = 0;
  }
  v3->timestamps[0] = *(_WORD *)*addr;
  v33 = (char *)*addr + 2;
  *addr = v33;
  v3->timestamps[1] = *(_WORD *)v33;
  v34 = (char *)*addr + 2;
  *addr = v34;
  v3->timestamps[2] = *(_WORD *)v34;
  v35 = (char *)*addr + 2;
  *addr = v35;
  v3->timestamps[3] = *(_WORD *)v35;
  v36 = (char *)*addr + 2;
  *addr = v36;
  v3->timestamps[4] = *(_WORD *)v36;
  v37 = (char *)*addr + 2;
  *addr = v37;
  v3->timestamps[5] = *(_WORD *)v37;
  v38 = (char *)*addr + 2;
  *addr = v38;
  v3->timestamps[6] = *(_WORD *)v38;
  v39 = (char *)*addr + 2;
  *addr = v39;
  v3->timestamps[7] = *(_WORD *)v39;
  v40 = (char *)*addr + 2;
  *addr = v40;
  v3->timestamps[8] = *(_WORD *)v40;
  v41 = (char *)*addr + 2;
  *addr = v41;
  v42 = (signed int)v41 % 4;
  if ( v42 )
  {
    v43 = 4 - v42;
    if ( 4 != v42 )
    {
      do
      {
        *(_BYTE *)*addr = 0;
        --v43;
        *addr = (char *)*addr + 1;
      }
      while ( v43 );
    }
  }
  return 1;
}

//----- (006FCD90) --------------------------------------------------------  // acclient.c:785199
void sub_6FCD90()
{
  flt_8442B8 = 1000.0 + 1.0;
}

//----- (006FCDB0) --------------------------------------------------------  // acclient.c:785205
void sub_6FCDB0()
{
  flt_8442BC = 24.0 * 8.0;
}

//----- (006FCDD0) --------------------------------------------------------  // acclient.c:785211
void sub_6FCDD0()
{
  flt_8442C0 = 24.0 * 0.5;
}

//----- (006FCDF0) --------------------------------------------------------  // acclient.c:785217
void sub_6FCDF0()
{
  flt_8442C8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FCE10) --------------------------------------------------------  // acclient.c:785223
void _E99_20()
{
  dbl_8442D0 = 1.0 / 30.0;
}

//----- (006FCE30) --------------------------------------------------------  // acclient.c:785229
void _E101_17()
{
  dbl_8442D8 = 1.0 / 5.0;
}

//----- (006FCE50) --------------------------------------------------------  // acclient.c:785235
int sub_6FCE50()
{
  return atexit(nullsub_1114);
}

