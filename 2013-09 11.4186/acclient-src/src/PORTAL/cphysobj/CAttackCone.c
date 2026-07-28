/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CAttackCone
   Object     : PORTAL\cphysobj\CAttackCone.obj
   Functions  : 8
   Addresses  : 0051A040 - 0051A340 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051A040) --------------------------------------------------------  // acclient.c:327728
void __thiscall DArray<ObjectInfo>::grow(DArray<ObjectInfo> *this, unsigned int size)
{
  DArray<ObjectInfo> *v2; // esi@1
  void *v3; // edi@3
  unsigned int v4; // eax@3
  void *v5; // ecx@4

  v2 = this;
  if ( size > this->sizeOf )
  {
    v3 = operator new[](8 * size);
    v4 = 0;
    if ( v2->sizeOf )
    {
      do
      {
        v5 = v2->data;
        *((_DWORD *)v3 + 2 * v4) = v2->data[v4].object_id;
        *((_DWORD *)v3 + 2 * v4 + 1) = *((_DWORD *)v5 + 2 * v4 + 1);
        ++v4;
      }
      while ( v4 < v2->sizeOf );
    }
    operator delete[](v2->data);
    v2->data = (ObjectInfo *)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<ObjectInfo>::shrink(this, size);
  }
}

//----- (0051A0B0) --------------------------------------------------------  // acclient.c:327762
void __thiscall DArray<ObjectInfo>::shrink(DArray<ObjectInfo> *this, unsigned int size)
{
  DArray<ObjectInfo> *v2; // esi@1
  ObjectInfo *v3; // ST04_4@4
  void *v4; // ebx@5
  unsigned int v5; // eax@5
  void *v6; // edx@6

  v2 = this;
  if ( size <= this->sizeOf )
  {
    if ( size )
    {
      v4 = operator new[](8 * size);
      v5 = 0;
      v2->sizeOf = size;
      if ( size )
      {
        do
        {
          v6 = v2->data;
          *((_DWORD *)v4 + 2 * v5) = v2->data[v5].object_id;
          *((_DWORD *)v4 + 2 * v5 + 1) = *((_DWORD *)v6 + 2 * v5 + 1);
          ++v5;
        }
        while ( v5 < v2->sizeOf );
      }
      operator delete[](v2->data);
      v2->data = (ObjectInfo *)v4;
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
    DArray<ObjectInfo>::grow(this, size);
  }
}

//----- (0051A140) --------------------------------------------------------  // acclient.c:327809
void __thiscall AttackInfo::AttackInfo(AttackInfo *this, unsigned int _attack_id, int _part_index, float _attack_radius)
{
  AttackInfo *v4; // esi@1

  v4 = this;
  this->attack_id = _attack_id;
  this->part_index = _part_index;
  this->attack_radius = _attack_radius;
  this->waiting_for_cells = 0;
  this->num_objects = 0;
  this->object_list.data = (ObjectInfo *)operator new[](0x20u);
  v4->object_list.sizeOf = 4;
  v4->object_list.blocksize = 4;
  v4->object_list.next_available = 0;
}

//----- (0051A190) --------------------------------------------------------  // acclient.c:327826
void __thiscall AttackInfo::AddObject(AttackInfo *this, unsigned int object_id, unsigned int hit_location)
{
  AttackInfo *v3; // esi@1
  unsigned int v4; // edx@1
  unsigned int v5; // eax@1
  ObjectInfo *v6; // ecx@2
  unsigned int v7; // eax@5

  v3 = this;
  v4 = this->num_objects;
  v5 = 0;
  if ( v4 )
  {
    v6 = this->object_list.data;
    while ( object_id != v6->object_id )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3->num_objects )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v7 = v3->object_list.sizeOf;
    if ( v4 >= v7 )
      DArray<ObjectInfo>::grow(&v3->object_list, v7 + 4);
    v3->object_list.data[v3->num_objects].object_id = object_id;
    v3->object_list.data[v3->num_objects++].hit_location = hit_location;
  }
}

//----- (0051A1F0) --------------------------------------------------------  // acclient.c:327860
void __thiscall AttackManager::AttackManager(AttackManager *this)
{
  AttackManager *v1; // esi@1
  void *v2; // eax@1
  unsigned int v3; // edx@1

  v1 = this;
  LODWORD(this->attack_radius) = 0;
  this->current_attack = 0;
  this->pending_attacks.buckets = 0;
  this->pending_attacks.table_size = 2;
  v2 = operator new[](8u);
  v3 = 4 * v1->pending_attacks.table_size;
  v1->pending_attacks.buckets = (LongNIHashData **)v2;
  memset(v2, 0, v3);
}

//----- (0051A230) --------------------------------------------------------  // acclient.c:327878
void __thiscall AttackManager::~AttackManager(AttackManager *this)
{
  LongNIHash<ParticleEmitter> *v1; // esi@1
  LongNIHashData *i; // esi@2
  int v3; // ebx@2
  LongNIHash<AttackInfo> *v4; // ebp@2
  void *v5; // edi@3
  char *v6; // [sp+4h] [bp-14h]@1
  LongNIHashIter<AttackInfo> iter; // [sp+8h] [bp-10h]@1

  v1 = (LongNIHash<ParticleEmitter> *)&this->pending_attacks;
  v6 = (char *)&this->pending_attacks;
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
    (LongNIHashIter<ParticleEmitter> *)&iter,
    (LongNIHash<ParticleEmitter> *)&this->pending_attacks);
  if ( !iter.fDone )
  {
    i = iter.curDat;
    v3 = iter.bucketNo;
    v4 = iter.hash;
    if ( iter.curDat )
    {
LABEL_3:
      v5 = i->data;
      if ( v5 )
      {
        operator delete[](*((void **)v5 + 5));
        *((_DWORD *)v5 + 5) = 0;
        operator delete(v5);
      }
    }
    for ( i = i->next; ; i = v4->buckets[v3] )
    {
      if ( i )
        goto LABEL_3;
      ++v3;
      if ( v3 >= v4->table_size )
        break;
    }
    v1 = (LongNIHash<ParticleEmitter> *)v6;
  }
  LongNIHash<DetectionCylsphere>::flush(v1);
  operator delete[](v1->buckets);
  v1->buckets = 0;
}

//----- (0051A2C0) --------------------------------------------------------  // acclient.c:327925
int __thiscall AttackManager::NewAttack(AttackManager *this, int part_index)
{
  AttackManager *v2; // esi@1
  AttackInfo *v3; // eax@1
  int v4; // eax@2
  int v5; // ebp@2
  unsigned int v6; // edi@4
  LongNIHashData **v7; // ebx@4
  void *v8; // eax@4

  v2 = this;
  v3 = (AttackInfo *)operator new(0x24u);
  if ( v3 )
  {
    AttackInfo::AttackInfo(v3, v2->current_attack, part_index, v2->attack_radius);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = v2->current_attack;
  v7 = &v2->pending_attacks.buckets[(v6 ^ (unsigned __int64)(v2->current_attack >> 16)) % v2->pending_attacks.table_size];
  v8 = operator new(0xCu);
  if ( v8 )
  {
    *(_DWORD *)v8 = 0;
    *((_DWORD *)v8 + 1) = 0;
    *((_DWORD *)v8 + 2) = 0;
    *((_DWORD *)v8 + 1) = v5;
    *((_DWORD *)v8 + 2) = v6;
    *(_DWORD *)v8 = *v7;
    *v7 = (LongNIHashData *)v8;
  }
  ++v2->current_attack;
  return v5;
}

//----- (0051A340) --------------------------------------------------------  // acclient.c:327964
void __thiscall AttackManager::AttackDone(AttackManager *this, AttackInfo *attack_info)
{
  LongNIHash<TargettedVoyeurInfo>::remove((LongNIHash<ParticleEmitter> *)&this->pending_attacks, attack_info->attack_id);
  operator delete[](attack_info->object_list.data);
  attack_info->object_list.data = 0;
  operator delete(attack_info);
}

