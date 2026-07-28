/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CTargetting
   Object     : PORTAL\cphysobj\CTargetting.obj
   Functions  : 25
   Addresses  : 0051A370 - 006FC7F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051A370) --------------------------------------------------------  // acclient.c:327973
void __thiscall TargetManager::TargetManager(TargetManager *this, CPhysicsObj *object)
{
  this->physobj = object;
  this->target_info = 0;
  this->voyeur_table = 0;
  *(_QWORD *)&this->last_update_time = 0i64;
}

//----- (0051A390) --------------------------------------------------------  // acclient.c:327982
void __thiscall LongNIHash<DetectionInfo>::LongNIHash<DetectionInfo>(LongNIHash<TargettedVoyeurInfo> *this, int _table_size)
{
  LongNIHash<TargettedVoyeurInfo> *v2; // esi@1
  void *v3; // eax@1
  unsigned int v4; // edx@1

  v2 = this;
  this->table_size = _table_size;
  this->buckets = 0;
  v3 = operator new[](4 * _table_size);
  v4 = 4 * v2->table_size;
  v2->buckets = (LongNIHashData **)v3;
  memset(v3, 0, v4);
}

//----- (0051A3D0) --------------------------------------------------------  // acclient.c:327998
LongNIHashIter<TargettedVoyeurInfo> *__thiscall LongNIHashIter<TargettedVoyeurInfo>::operator++(LongNIHashIter<TargettedVoyeurInfo> *this, int num)
{
  LongNIHashIter<TargettedVoyeurInfo> *result; // eax@1
  LongNIHash<TargettedVoyeurInfo> *v3; // edx@4
  int v4; // ecx@4

  result = this;
  if ( !this->fDone )
  {
    this->curDat = this->curDat->next;
    do
    {
      if ( result->curDat )
        break;
      v3 = result->hash;
      v4 = result->bucketNo + 1;
      result->bucketNo = v4;
      if ( v4 < v3->table_size )
        result->curDat = v3->buckets[v4];
      else
        result->fDone = 1;
    }
    while ( !result->fDone );
  }
  return result;
}

//----- (0051A420) --------------------------------------------------------  // acclient.c:328026
void __thiscall TargetInfo::TargetInfo(TargetInfo *this)
{
  TargetInfo *v1; // esi@1
  char *v2; // ecx@1
  int v3; // ecx@1

  v1 = this;
  v2 = (char *)&this->target_position.frame;
  v1->context_id = 0;
  v1->object_id = 0;
  LODWORD(v1->radius) = 0;
  LODWORD(v1->quantum) = 0;
  HIDWORD(v1->quantum) = 0;
  v1->target_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->target_position.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v3 = (int)&v1->interpolated_position.frame;
  v1->interpolated_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->interpolated_position.objcell_id = 0;
  *(_DWORD *)v3 = 1065353216;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  Frame::cache(&v1->interpolated_position.frame);
  v1->status = 0;
  LODWORD(v1->last_update_time) = 0;
  HIDWORD(v1->last_update_time) = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0051A4A0) --------------------------------------------------------  // acclient.c:328067
void __thiscall TargetManager::SetTargetQuantum(TargetManager *this, long double new_quantum)
{
  TargetManager *v2; // esi@1
  TargetInfo *v3; // eax@1
  HashBaseData<unsigned long> *v4; // eax@2
  TargetInfo *v5; // ecx@3
  float quantum; // ST08_4@3

  v2 = this;
  v3 = this->target_info;
  if ( v3 )
  {
    v3->quantum = new_quantum;
    v4 = CPhysicsObj::GetObjectA(this->target_info->object_id);
    if ( v4 )
    {
      v5 = v2->target_info;
      quantum = v5->quantum;
      CPhysicsObj::add_voyeur((CPhysicsObj *)v4, v2->physobj->id, v5->radius, quantum);
    }
  }
}

//----- (0051A4F0) --------------------------------------------------------  // acclient.c:328091
void __thiscall TargetManager::SendVoyeurUpdate(TargetManager *this, TargettedVoyeurInfo *voyeur, Position *p, TargetStatus status)
{
  TargetManager *v4; // edi@1
  CPhysicsObj *v5; // edi@1
  unsigned int v6; // eax@1
  float v7; // edx@1
  AC1Legacy::Vector3 *v8; // eax@1
  unsigned int v9; // esi@1
  HashBaseData<unsigned long> *v10; // eax@1
  AC1Legacy::Vector3 result; // [sp+10h] [bp-DCh]@1
  TargetInfo info; // [sp+1Ch] [bp-D0h]@1

  v4 = this;
  voyeur->last_sent_position.objcell_id = p->objcell_id;
  Frame::operator=((int)&voyeur->last_sent_position.frame, (int)&p->frame);
  TargetInfo::TargetInfo(&info);
  v5 = v4->physobj;
  v6 = LODWORD(voyeur->quantum);
  v7 = voyeur->radius;
  info.context_id = 0;
  info.object_id = v5->id;
  *(_QWORD *)&info.quantum = __PAIR__(HIDWORD(voyeur->quantum), v6);
  info.radius = v7;
  info.target_position.objcell_id = v5->m_position.objcell_id;
  Frame::operator=((int)&info.target_position.frame, (int)&v5->m_position.frame);
  info.interpolated_position.objcell_id = p->objcell_id;
  Frame::operator=((int)&info.interpolated_position.frame, (int)&p->frame);
  v8 = CPhysicsObj::get_velocity(v5, &result);
  v9 = voyeur->object_id;
  info.velocity.x = v8->x;
  info.velocity.y = v8->y;
  info.velocity.z = v8->z;
  info.status = status;
  v10 = CPhysicsObj::GetObjectA(v9);
  if ( v10 )
    CPhysicsObj::receive_target_update((CPhysicsObj *)v10, &info);
}

//----- (0051A5E0) --------------------------------------------------------  // acclient.c:328130
void __thiscall TargetManager::GetInterpolatedPosition(TargetManager *this, long double quantum, Position *p)
{
  Position *v3; // esi@1
  CPhysicsObj **v4; // edi@1
  int v5; // eax@1
  AC1Legacy::Vector3 *v6; // eax@1
  double v7; // st7@1
  double v8; // st6@1
  AC1Legacy::Vector3 result; // [sp+8h] [bp-Ch]@1
  Position *pa; // [sp+20h] [bp+Ch]@1

  v3 = p;
  v4 = (CPhysicsObj **)this;
  v5 = (int)&this->physobj->m_position.frame;
  p->objcell_id = this->physobj->m_position.objcell_id;
  Frame::operator=((int)&p->frame, v5);
  *(float *)&pa = quantum;
  v6 = CPhysicsObj::get_velocity(*v4, &result);
  v7 = *(float *)&pa * v6->x;
  v8 = *(float *)&pa * v6->y;
  result.z = *(float *)&pa * v6->z;
  v3->frame.m_fOrigin.x = v7 + v3->frame.m_fOrigin.x;
  v3->frame.m_fOrigin.y = v8 + v3->frame.m_fOrigin.y;
  v3->frame.m_fOrigin.z = result.z + v3->frame.m_fOrigin.z;
}

//----- (0051A650) --------------------------------------------------------  // acclient.c:328157
void __thiscall TargetManager::CheckAndUpdateVoyeur(TargetManager *this, TargettedVoyeurInfo *voyeur)
{
  TargetManager *v2; // edi@1
  Position p; // [sp+8h] [bp-48h]@1

  v2 = this;
  p.vfptr = (PackObjVtbl *)&Position::vftable;
  p.objcell_id = 0;
  LODWORD(p.frame.qw) = 1065353216;
  LODWORD(p.frame.qx) = 0;
  LODWORD(p.frame.qy) = 0;
  LODWORD(p.frame.qz) = 0;
  LODWORD(p.frame.m_fOrigin.x) = 0;
  LODWORD(p.frame.m_fOrigin.y) = 0;
  LODWORD(p.frame.m_fOrigin.z) = 0;
  Frame::cache(&p.frame);
  TargetManager::GetInterpolatedPosition(v2, voyeur->quantum, &p);
  if ( Position::distance(&p, &voyeur->last_sent_position) > voyeur->radius )
    TargetManager::SendVoyeurUpdate(v2, voyeur, &p, Ok_TargetStatus);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0051A6F0) --------------------------------------------------------  // acclient.c:328180
void __thiscall TargetManager::NotifyVoyeurOfEvent(TargetManager *this, TargetStatus event)
{
  TargetManager *v2; // ebx@1
  LongNIHash<TargettedVoyeurInfo> *v3; // eax@1
  int v4; // ebp@2
  LongNIHashData *i; // esi@3
  int v6; // edi@3
  TargettedVoyeurInfo *v7; // eax@5
  LongNIHashIter<TargettedVoyeurInfo> iter; // [sp+4h] [bp-10h]@2

  v2 = this;
  v3 = this->voyeur_table;
  if ( v3 )
  {
    LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
      (LongNIHashIter<ParticleEmitter> *)&iter,
      (LongNIHash<ParticleEmitter> *)v3);
    v4 = iter.fDone;
    if ( !iter.fDone )
    {
      i = iter.curDat;
      v6 = iter.bucketNo;
      do
      {
        if ( i )
          v7 = (TargettedVoyeurInfo *)i->data;
        else
          v7 = 0;
        if ( !v4 )
        {
          for ( i = i->next; !i; i = iter.hash->buckets[v6] )
          {
            ++v6;
            if ( v6 >= iter.hash->table_size )
            {
              v4 = 1;
              break;
            }
          }
        }
        TargetManager::SendVoyeurUpdate(v2, v7, &v2->physobj->m_position, event);
      }
      while ( !v4 );
    }
  }
}

//----- (0051A7E0) --------------------------------------------------------  // acclient.c:328270
void __thiscall TargetManager::ClearTarget(TargetManager *this)
{
  TargetManager *v1; // esi@1
  TargetInfo *v2; // eax@1
  HashBaseData<unsigned long> *v3; // eax@2
  TargetInfo *v4; // eax@4
  void *v5; // ST00_4@5

  v1 = this;
  v2 = this->target_info;
  if ( v2 )
  {
    v3 = CPhysicsObj::GetObjectA(v2->object_id);
    if ( v3 )
      CPhysicsObj::remove_voyeur((CPhysicsObj *)v3, v1->physobj->id);
    v4 = v1->target_info;
    if ( v4 )
    {
      v5 = v1->target_info;
      v4->interpolated_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
      v4->target_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
      operator delete(v5);
    }
    v1->target_info = 0;
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0051A830) --------------------------------------------------------  // acclient.c:328299
void __thiscall TargetManager::AddVoyeur(TargetManager *this, unsigned int object_id, float radius, long double quantum)
{
  TargetManager *v4; // ebp@1
  LongNIHash<TargettedVoyeurInfo> *v5; // ecx@1
  LongNIHashData *v6; // edx@2
  void *v7; // edx@6
  LongNIHash<TargettedVoyeurInfo> *v8; // eax@8
  LongNIHash<TargettedVoyeurInfo> *v9; // eax@9
  void *v10; // eax@12
  void *v11; // esi@12
  int v12; // ecx@13

  v4 = this;
  v5 = this->voyeur_table;
  if ( v5 )
  {
    v6 = v5->buckets[(object_id ^ (unsigned __int64)(object_id >> 16)) % v5->table_size];
    if ( v6 )
    {
      if ( v6->key == object_id )
      {
LABEL_6:
        v7 = v6->data;
        if ( v7 )
        {
          *((float *)v7 + 4) = radius;
          *((long double *)v7 + 1) = quantum;
          return;
        }
      }
      else
      {
        while ( 1 )
        {
          v6 = v6->next;
          if ( !v6 )
            break;
          if ( v6->key == object_id )
            goto LABEL_6;
        }
      }
    }
  }
  else
  {
    v8 = (LongNIHash<TargettedVoyeurInfo> *)operator new(8u);
    if ( v8 )
      LongNIHash<DetectionInfo>::LongNIHash<DetectionInfo>(v8, 4);
    else
      v9 = 0;
    v4->voyeur_table = v9;
  }
  v10 = operator new(0x60u);
  v11 = v10;
  if ( v10 )
  {
    *(_DWORD *)v10 = 0;
    *((_DWORD *)v10 + 2) = 0;
    *((_DWORD *)v10 + 3) = 0;
    *((_DWORD *)v10 + 4) = 0;
    v12 = (int)((char *)v10 + 28);
    *((_DWORD *)v10 + 5) = &Position::vftable;
    *((_DWORD *)v10 + 6) = 0;
    *(_DWORD *)v12 = 1065353216;
    *(_DWORD *)(v12 + 4) = 0;
    *(_DWORD *)(v12 + 8) = 0;
    *(_DWORD *)(v12 + 12) = 0;
    *(_DWORD *)(v12 + 52) = 0;
    *(_DWORD *)(v12 + 56) = 0;
    *(_DWORD *)(v12 + 60) = 0;
    Frame::cache((Frame *)((char *)v10 + 28));
  }
  else
  {
    v11 = 0;
  }
  *(_DWORD *)v11 = object_id;
  *((float *)v11 + 4) = radius;
  *((long double *)v11 + 1) = quantum;
  LongNIHash<ParticleEmitter>::add((LongNIHash<ParticleEmitter> *)v4->voyeur_table, (ParticleEmitter *)v11, object_id);
  TargetManager::SendVoyeurUpdate(v4, (TargettedVoyeurInfo *)v11, &v4->physobj->m_position, Ok_TargetStatus);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (0051A930) --------------------------------------------------------  // acclient.c:328384
void __thiscall TargetManager::ReceiveUpdate(TargetManager *this, TargetInfo *target_update)
{
  CPhysicsObj **v2; // esi@1
  TargetInfo *v3; // eax@1
  unsigned int v4; // ecx@2
  unsigned int v5; // edx@3
  int v6; // eax@3
  unsigned int v7; // edx@3
  int v8; // eax@3
  int v9; // eax@3
  CPhysicsObj *v10; // edx@3
  unsigned int v11; // ecx@3
  AC1Legacy::Vector3 *v12; // eax@3
  int v13; // ecx@3
  CPhysicsObj *v14; // ecx@4
  TargetInfo v15; // [sp-D0h] [bp-E4h]@5
  char *v16; // [sp-4h] [bp-18h]@3
  AC1Legacy::Vector3 result; // [sp+8h] [bp-Ch]@3

  v2 = (CPhysicsObj **)this;
  v3 = this->target_info;
  if ( v3 )
  {
    v4 = target_update->object_id;
    if ( v4 == v3->object_id )
    {
      v3->object_id = v4;
      v2[1]->id = LODWORD(target_update->radius);
      *(_QWORD *)&v2[1]->part_array = *(_QWORD *)&target_update->quantum;
      v5 = target_update->target_position.objcell_id;
      v6 = (int)&v2[1]->player_vector.y;
      v16 = (char *)&target_update->target_position.frame;
      *(_DWORD *)(v6 + 4) = v5;
      Frame::operator=(v6 + 8, (int)v16);
      v7 = target_update->interpolated_position.objcell_id;
      v8 = (int)v2[1]->m_position.frame.m_fl2gv;
      v16 = (char *)&target_update->interpolated_position.frame;
      *(_DWORD *)(v8 + 4) = v7;
      Frame::operator=(v8 + 8, (int)v16);
      v9 = (int)&v2[1]->translucency;
      *(_DWORD *)v9 = LODWORD(target_update->velocity.x);
      *(_DWORD *)(v9 + 4) = LODWORD(target_update->velocity.y);
      *(_DWORD *)(v9 + 8) = LODWORD(target_update->velocity.z);
      LODWORD(v2[1]->massinv) = target_update->status;
      v10 = v2[1];
      v11 = Timer::cur_time.Param;
      v10->position_manager = (PositionManager *)Timer::cur_time.Cmd;
      v10->last_move_was_autonomous = v11;
      v12 = Position::get_offset(&(*v2)->m_position, &result, (Position *)((char *)&v2[1]->m_position + 24));
      v13 = (int)&v2[1]->state;
      *(_DWORD *)v13 = LODWORD(v12->x);
      *(_DWORD *)(v13 + 4) = LODWORD(v12->y);
      *(_DWORD *)(v13 + 8) = LODWORD(v12->z);
      if ( AC1Legacy::Vector3::normalize_check_small((AC1Legacy::Vector3 *)&v2[1]->state) )
      {
        v14 = v2[1];
        LODWORD(result.x) = 0;
        v14 = (CPhysicsObj *)((char *)v14 + 168);
        v14->vfptr = 0;
        LODWORD(result.y) = 0;
        LODWORD(result.z) = 1065353216;
        v14->hash_next = 0;
        v14->id = 1065353216;
      }
      TargetInfo::TargetInfo(&v15, (TargetInfo *)v2[1]);
      CPhysicsObj::HandleUpdateTarget(*v2, v15);
      if ( target_update->status == 2 )
        TargetManager::ClearTarget((TargetManager *)v2);
    }
  }
}

//----- (0051AA90) --------------------------------------------------------  // acclient.c:328457
void __thiscall TargetManager::HandleTargetting(TargetManager *this)
{
  TargetManager *v1; // edi@1
  TargetInfo *v2; // ecx@2
  TargettedVoyeurInfo *v3; // esi@9
  int v4; // edx@12
  TargetInfo v5; // [sp-D0h] [bp-E8h]@5
  LongNIHashIter<TargettedVoyeurInfo> iter; // [sp+8h] [bp-10h]@7

  v1 = this;
  if ( PhysicsTimer::curr_time - this->last_update_time >= 0.5 )
  {
    v2 = this->target_info;
    if ( v2 && v2->status == Undef_TargetStatus && v2->last_update_time + 10.0 < COERCE_DOUBLE(Timer::cur_time.Cmd) )
    {
      v2->status = 6;
      TargetInfo::TargetInfo(&v5, v1->target_info);
      CPhysicsObj::HandleUpdateTarget(v1->physobj, v5);
    }
    if ( v1->voyeur_table )
    {
      LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
        (LongNIHashIter<ParticleEmitter> *)&iter,
        (LongNIHash<ParticleEmitter> *)v1->voyeur_table);
      while ( !iter.fDone )
      {
        if ( iter.curDat )
          v3 = (TargettedVoyeurInfo *)iter.curDat->data;
        else
          v3 = 0;
        LongNIHashIter<TargettedVoyeurInfo>::operator++(&iter, 0);
        TargetManager::CheckAndUpdateVoyeur(v1, v3);
      }
    }
    v4 = HIDWORD(PhysicsTimer::curr_time);
    LODWORD(v1->last_update_time) = LODWORD(PhysicsTimer::curr_time);
    HIDWORD(v1->last_update_time) = v4;
  }
}

//----- (0051AB60) --------------------------------------------------------  // acclient.c:328498
void __thiscall LongNIHash<TargettedVoyeurInfo>::destroy_contents(LongNIHash<TargettedVoyeurInfo> *this)
{
  LongNIHash<TargettedVoyeurInfo> *v1; // ebp@1
  LongNIHashData **v2; // ebx@1
  LongNIHashData *v3; // esi@2
  void *v4; // eax@3
  LongNIHashData *v5; // edi@3
  void *v6; // ST00_4@4

  v1 = this;
  v2 = this->buckets;
  if ( this->buckets < &this->buckets[this->table_size] )
  {
    do
    {
      v3 = *v2;
      if ( *v2 )
      {
        do
        {
          v4 = v3->data;
          v5 = v3->next;
          if ( v4 )
          {
            v6 = v3->data;
            *((_DWORD *)v4 + 5) = &PackObj::vftable;
            operator delete(v6);
          }
          operator delete(v3);
          v3 = v5;
        }
        while ( v5 );
      }
      *v2 = 0;
      ++v2;
    }
    while ( v2 < &v1->buckets[v1->table_size] );
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0051ABD0) --------------------------------------------------------  // acclient.c:328540
void __thiscall TargetManager::~TargetManager(TargetManager *this)
{
  TargetManager *v1; // esi@1
  TargetInfo *v2; // eax@1
  LongNIHash<TargettedVoyeurInfo> *v3; // ecx@3
  LongNIHash<ParticleEmitter> *v4; // esi@4

  v1 = this;
  v2 = this->target_info;
  if ( v2 )
  {
    v2->interpolated_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
    v2->target_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
    operator delete(v2);
    v1->target_info = 0;
  }
  v3 = v1->voyeur_table;
  if ( v3 )
  {
    LongNIHash<TargettedVoyeurInfo>::destroy_contents(v3);
    v4 = (LongNIHash<ParticleEmitter> *)v1->voyeur_table;
    if ( v4 )
    {
      LongNIHash<DetectionCylsphere>::flush(v4);
      operator delete[](v4->buckets);
      v4->buckets = 0;
      operator delete(v4);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0051AC30) --------------------------------------------------------  // acclient.c:328573
void __thiscall TargetManager::SetTarget(TargetManager *this, unsigned int context_id, unsigned int object_id, float radius, long double quantum)
{
  CPhysicsObj **v5; // esi@1
  TargetInfo *v6; // eax@1
  HashBaseData<unsigned long> *v7; // eax@2
  CPhysicsObj *v8; // eax@4
  TargetInfo *v9; // eax@8
  CPhysicsObj *v10; // eax@9
  CPhysicsObj *v11; // edx@11
  unsigned int v12; // ecx@11
  HashBaseData<unsigned long> *v13; // eax@11
  CPhysicsObj *v14; // ecx@12
  TargetInfo v15; // [sp-C8h] [bp-1A8h]@13
  float v16; // [sp+4h] [bp-DCh]@5
  TargetInfo failed_target_info; // [sp+10h] [bp-D0h]@13

  v5 = (CPhysicsObj **)this;
  v6 = this->target_info;
  if ( v6 )
  {
    v7 = CPhysicsObj::GetObjectA(v6->object_id);
    if ( v7 )
      CPhysicsObj::remove_voyeur((CPhysicsObj *)v7, (*v5)->id);
    v8 = v5[1];
    if ( v8 )
    {
      v16 = *((float *)v5 + 1);
      LODWORD(v8->m_position.frame.m_fl2gv[0]) = &PackObj::vftable;
      LODWORD(v8->player_vector.y) = &PackObj::vftable;
      operator delete(LODWORD(v16));
    }
    v5[1] = 0;
  }
  if ( object_id )
  {
    v9 = (TargetInfo *)operator new(0xD0u);
    if ( v9 )
      TargetInfo::TargetInfo(v9);
    else
      v10 = 0;
    v5[1] = v10;
    v10->vfptr = (HashBaseData<unsigned long>Vtbl *)context_id;
    v5[1]->hash_next = (HashBaseData<unsigned long> *)object_id;
    *(float *)&v5[1]->id = radius;
    *(long double *)&v5[1]->part_array = quantum;
    v11 = v5[1];
    v12 = Timer::cur_time.Param;
    v11->position_manager = (PositionManager *)Timer::cur_time.Cmd;
    v11->last_move_was_autonomous = v12;
    v13 = CPhysicsObj::GetObjectA((unsigned int)v5[1]->hash_next);
    if ( v13 )
    {
      v14 = v5[1];
      v16 = *(double *)&v14->part_array;
      CPhysicsObj::add_voyeur((CPhysicsObj *)v13, (*v5)->id, *(float *)&v14->id, v16);
    }
  }
  else
  {
    TargetInfo::TargetInfo(&failed_target_info);
    failed_target_info.context_id = context_id;
    failed_target_info.object_id = 0;
    failed_target_info.status = 6;
    TargetInfo::TargetInfo(&v15, &failed_target_info);
    CPhysicsObj::HandleUpdateTarget(*v5, v15);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0051AD90) --------------------------------------------------------  // acclient.c:328643
int __thiscall TargetManager::RemoveVoyeur(TargetManager *this, unsigned int object_id)
{
  LongNIHash<TargettedVoyeurInfo> *v2; // ecx@1
  ParticleEmitter *v3; // eax@2
  int result; // eax@3

  v2 = this->voyeur_table;
  if ( v2 && (v3 = LongNIHash<TargettedVoyeurInfo>::remove((LongNIHash<ParticleEmitter> *)v2, object_id)) != 0 )
  {
    LODWORD(v3->parent_offset.qy) = &PackObj::vftable;
    operator delete(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (006FC720) --------------------------------------------------------  // acclient.c:784791
void sub_6FC720()
{
  flt_84406C = 1000.0 + 1.0;
}

//----- (006FC740) --------------------------------------------------------  // acclient.c:784797
void sub_6FC740()
{
  flt_844070 = 24.0 * 8.0;
}

//----- (006FC760) --------------------------------------------------------  // acclient.c:784803
void sub_6FC760()
{
  flt_844074 = 24.0 * 0.5;
}

//----- (006FC780) --------------------------------------------------------  // acclient.c:784809
int _E101_12()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_6;
  INITIAL_MAX_DATA_RATE_73 = LOWEST_DATA_RATE_6;
  return result;
}

//----- (006FC790) --------------------------------------------------------  // acclient.c:784819
void sub_6FC790()
{
  flt_844080 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC7B0) --------------------------------------------------------  // acclient.c:784825
void _E105_19()
{
  dbl_844088 = 1.0 / 30.0;
}

//----- (006FC7D0) --------------------------------------------------------  // acclient.c:784831
void _E107_14()
{
  dbl_844090 = 1.0 / 5.0;
}

//----- (006FC7F0) --------------------------------------------------------  // acclient.c:784837
int sub_6FC7F0()
{
  return atexit(nullsub_1102);
}

