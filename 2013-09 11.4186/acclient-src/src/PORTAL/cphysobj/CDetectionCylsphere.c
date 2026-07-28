/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CDetectionCylsphere
   Object     : PORTAL\cphysobj\CDetectionCylsphere.obj
   Functions  : 21
   Addresses  : 005196D0 - 006FC710 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005196D0) --------------------------------------------------------  // acclient.c:327020
signed int __thiscall DetectionManager::CheckDetection(DetectionManager *this, DetectionCylsphere *detcyl, CPhysicsObj *object)
{
  DetectionCylsphere *v3; // esi@1
  CPhysicsObj *v4; // edi@1
  double v5; // st7@1
  int v6; // eax@1
  signed int result; // eax@3
  float detcyla; // [sp+Ch] [bp+4h]@1
  CPhysicsObj *objecta; // [sp+10h] [bp+8h]@1

  v3 = detcyl;
  v4 = object;
  detcyla = detcyl->radius;
  *(float *)&objecta = Position::distance(&this->physobj->m_position, &object->m_position);
  v5 = CPhysicsObj::GetRadius(v4);
  v6 = v3->object_detected;
  if ( v5 + detcyla <= *(float *)&objecta )
  {
    if ( v6 )
    {
      v3->object_detected = 0;
      return 2;
    }
  }
  else if ( !v6 )
  {
    result = 1;
    v3->object_detected = 1;
    return result;
  }
  return 0;
}

//----- (005197A0) --------------------------------------------------------  // acclient.c:327087
void __thiscall LongNIHash<DetectionInfo>::destroy_contents(LongNIHash<DetectionInfo> *this)
{
  LongNIHash<DetectionInfo> *v1; // ebp@1
  LongNIHashData **v2; // ebx@1
  LongNIHashData *v3; // esi@2
  LongNIHashData *v4; // edi@3

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
          v4 = v3->next;
          if ( v3->data )
            operator delete(v3->data);
          operator delete(v3);
          v3 = v4;
        }
        while ( v4 );
      }
      *v2 = 0;
      ++v2;
    }
    while ( v2 < &v1->buckets[v1->table_size] );
  }
}

//----- (00519850) --------------------------------------------------------  // acclient.c:327153
void __thiscall DetectionManager::FindCellList(DetectionManager *this, DetectionCylsphere *detcyl, CELLARRAY *new_cell_array)
{
  CSphere sphere; // [sp+Ch] [bp-10h]@1

  LODWORD(sphere.center.x) = 0;
  LODWORD(sphere.center.y) = 0;
  LODWORD(sphere.center.z) = 0;
  sphere.radius = detcyl->radius;
  new_cell_array->do_not_load_cells = 1;
  CObjCell::find_cell_list(&this->physobj->m_position, &sphere, new_cell_array, 0);
}

//----- (00519910) --------------------------------------------------------  // acclient.c:327193
int __thiscall DetectionManager::InitializeGlobalDetection(DetectionManager *this, DetectionCylsphere *detcyl)
{
  DetectionManager *v2; // esi@1
  LongNIHash<TargettedVoyeurInfo> *v3; // eax@3
  LongNIHash<DetectionInfo> *v4; // eax@4
  CELLARRAY *v5; // eax@6
  CELLARRAY *v6; // eax@7
  unsigned int v7; // edi@9
  CObjCell *v8; // ecx@10
  int result; // eax@13

  v2 = this;
  if ( this->detection_objects || this->cell_array )
  {
    result = 0;
  }
  else
  {
    v3 = (LongNIHash<TargettedVoyeurInfo> *)operator new(8u);
    if ( v3 )
      LongNIHash<DetectionInfo>::LongNIHash<DetectionInfo>(v3, 32);
    else
      v4 = 0;
    v2->detection_objects = v4;
    v5 = (CELLARRAY *)operator new(0x1Cu);
    if ( v5 )
      CELLARRAY::CELLARRAY(v5);
    else
      v6 = 0;
    v2->cell_array = v6;
    DetectionManager::FindCellList(v2, detcyl, v6);
    v7 = 0;
    if ( v2->cell_array->num_cells )
    {
      do
      {
        v8 = v2->cell_array->cells.data[v7].cell;
        if ( v8 )
          CObjCell::add_voyeur(v8, v2->physobj->id, detcyl);
        ++v7;
      }
      while ( v7 < v2->cell_array->num_cells );
    }
    result = 1;
  }
  return result;
}

//----- (005199C0) --------------------------------------------------------  // acclient.c:327242
void __thiscall DetectionManager::ReceiveDetectionUpdate(DetectionManager *this, DetectionInfo *incoming_info)
{
  DetectionManager *v2; // esi@1
  LongNIHash<DetectionInfo> *v3; // ecx@1
  unsigned int v4; // edi@2
  LongNIHashData *v5; // edx@2
  void *v6; // edx@6
  unsigned int v7; // eax@9
  unsigned int v8; // eax@13
  void *v9; // eax@16
  unsigned int v10; // ecx@19

  v2 = this;
  v3 = this->detection_objects;
  if ( !v3 )
    return;
  v4 = incoming_info->object_id;
  v5 = v3->buckets[(incoming_info->object_id ^ (unsigned __int64)(incoming_info->object_id >> 16)) % v3->table_size];
  if ( v5 )
  {
    if ( v5->key == v4 )
    {
LABEL_6:
      v6 = v5->data;
      if ( v6 )
      {
        if ( incoming_info->object_status == 1 )
        {
          if ( *((_DWORD *)v6 + 1) == 2 )
          {
            *((_DWORD *)v6 + 1) = 0;
            v7 = v2->num_pending_global_detect_updates;
            if ( v7 )
              v2->num_pending_global_detect_updates = v7 - 1;
          }
          else
          {
            *((_DWORD *)v6 + 1) = 1;
            ++v2->num_pending_global_detect_updates;
          }
        }
        else if ( *((_DWORD *)v6 + 1) == 1 )
        {
          LongNIHash<TargettedVoyeurInfo>::remove((LongNIHash<ParticleEmitter> *)v3, incoming_info->object_id);
          v8 = v2->num_pending_global_detect_updates;
          if ( v8 )
            v2->num_pending_global_detect_updates = v8 - 1;
        }
        else
        {
          *((_DWORD *)v6 + 1) = 2;
          ++v2->num_pending_global_detect_updates;
        }
        return;
      }
    }
    else
    {
      while ( 1 )
      {
        v5 = v5->next;
        if ( !v5 )
          break;
        if ( v5->key == v4 )
          goto LABEL_6;
      }
    }
  }
  v9 = operator new(8u);
  if ( v9 )
  {
    *(_DWORD *)v9 = 0;
    *((_DWORD *)v9 + 1) = 0;
  }
  else
  {
    v9 = 0;
  }
  v10 = incoming_info->object_id;
  *(_QWORD *)v9 = *incoming_info;
  LongNIHash<ParticleEmitter>::add((LongNIHash<ParticleEmitter> *)v2->detection_objects, (ParticleEmitter *)v9, v10);
  ++v2->num_pending_global_detect_updates;
}

//----- (00519AB0) --------------------------------------------------------  // acclient.c:327327
void __thiscall DetectionManager::UpdateCellList(DetectionManager *this, DetectionCylsphere *detcyl)
{
  DetectionManager *v2; // esi@1
  int v3; // eax@4
  unsigned int v4; // edi@4
  CObjCell *v5; // ecx@5
  CELLARRAY *v6; // eax@8
  unsigned int v7; // edi@8
  unsigned int v8; // eax@9
  CELLARRAY *v9; // eax@12
  unsigned int v10; // edi@12
  CELLARRAY new_cell_array; // [sp+8h] [bp-1Ch]@4

  v2 = this;
  if ( this->cell_array || (DetectionManager::InitializeGlobalDetection(this, detcyl), v2->cell_array) )
  {
    if ( Position::distance(&v2->last_global_update, &v2->physobj->m_position) >= 5.0 )
    {
      v3 = (int)&v2->physobj->m_position.frame;
      v2->last_global_update.objcell_id = v2->physobj->m_position.objcell_id;
      Frame::operator=((int)&v2->last_global_update.frame, v3);
      CELLARRAY::CELLARRAY(&new_cell_array);
      DetectionManager::FindCellList(v2, detcyl, &new_cell_array);
      v4 = 0;
      if ( new_cell_array.num_cells )
      {
        do
        {
          v5 = new_cell_array.cells.data[v4].cell;
          if ( v5 )
            CObjCell::add_voyeur(v5, v2->physobj->id, detcyl);
          ++v4;
        }
        while ( v4 < new_cell_array.num_cells );
      }
      v6 = v2->cell_array;
      v7 = 0;
      if ( v6->num_cells )
      {
        do
        {
          v8 = CObjCell::GetVisible(v6->cells.data[v7].cell_id);
          if ( v8 )
            CObjCell::remove_voyeur((CObjCell *)v8, v2->physobj->id, detcyl);
          v6 = v2->cell_array;
          ++v7;
        }
        while ( v7 < v6->num_cells );
      }
      v9 = v2->cell_array;
      v9->num_cells = 0;
      v9->added_outside = 0;
      v9->do_not_load_cells = 0;
      v10 = 0;
      if ( new_cell_array.num_cells )
      {
        do
          CELLARRAY::add_cell(v2->cell_array, new_cell_array.cells.data[v10++].cell_id, 0);
        while ( v10 < new_cell_array.num_cells );
      }
      if ( new_cell_array.cells.data )
        operator delete[](&new_cell_array.cells.data[-1].cell);
    }
  }
}

//----- (00519BF0) --------------------------------------------------------  // acclient.c:327394
void __thiscall DetectionManager::ReportGlobalDetection(DetectionManager *this, unsigned int context_id)
{
  int v2; // eax@1
  int v3; // ebx@2
  LongNIHash<DetectionInfo> *v4; // ebp@2
  LongNIHashData *i; // edi@2
  unsigned int v6; // esi@4
  DetectionManager *v7; // [sp+0h] [bp-14h]@1
  LongNIHashIter<DetectionInfo> iter; // [sp+4h] [bp-10h]@1

  v7 = this;
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
    (LongNIHashIter<ParticleEmitter> *)&iter,
    (LongNIHash<ParticleEmitter> *)this->detection_objects);
  v2 = iter.fDone;
  if ( !iter.fDone )
  {
    v3 = iter.bucketNo;
    v4 = iter.hash;
    i = iter.curDat;
    do
    {
      if ( i )
        v6 = (unsigned int)i->data;
      else
        v6 = 0;
      if ( !v2 )
      {
        for ( i = i->next; !i; i = v4->buckets[v3] )
        {
          ++v3;
          if ( v3 >= v4->table_size )
          {
            iter.fDone = 1;
            break;
          }
        }
      }
      if ( *(_DWORD *)(v6 + 4) == 1 )
      {
        gmPanelUI::ListenToGlobalMessage((PlayerModule *)v7->physobj, (BaseProperty *)context_id, v6);
      }
      else if ( *(_DWORD *)(v6 + 4) == 2 )
      {
        gmPanelUI::ListenToGlobalMessage((PlayerModule *)v7->physobj, (BaseProperty *)context_id, v6);
      }
      if ( *(_DWORD *)(v6 + 4) == 2 )
      {
        LongNIHash<TargettedVoyeurInfo>::remove((LongNIHash<ParticleEmitter> *)v7->detection_objects, *(_DWORD *)v6);
        operator delete((void *)v6);
      }
      else
      {
        *(_DWORD *)(v6 + 4) = 0;
      }
      v2 = iter.fDone;
    }
    while ( !iter.fDone );
  }
}

//----- (00519CC0) --------------------------------------------------------  // acclient.c:327456
void __thiscall DetectionManager::CleanupGlobalDetection(DetectionManager *this, DetectionCylsphere *detcyl)
{
  DetectionManager *v2; // esi@1
  LongNIHash<DetectionInfo> *v3; // ecx@1
  void **v4; // edi@2
  CELLARRAY *v5; // eax@5
  unsigned int v6; // edi@6
  unsigned int v7; // eax@7
  CELLARRAY *v8; // edi@10
  CELLINFO *v9; // eax@11

  v2 = this;
  v3 = this->detection_objects;
  if ( v3 )
  {
    LongNIHash<DetectionInfo>::destroy_contents(v3);
    v4 = (void **)&v2->detection_objects->buckets;
    if ( v4 )
    {
      LongNIHash<DetectionCylsphere>::flush((LongNIHash<ParticleEmitter> *)v2->detection_objects);
      operator delete[](*v4);
      *v4 = 0;
      operator delete(v4);
    }
    v2->detection_objects = 0;
    v2->num_pending_global_detect_updates = 0;
  }
  v5 = v2->cell_array;
  if ( v5 )
  {
    v6 = 0;
    if ( v5->num_cells > 0 )
    {
      do
      {
        v7 = CObjCell::GetVisible(v2->cell_array->cells.data[v6].cell_id);
        if ( v7 )
          CObjCell::remove_voyeur((CObjCell *)v7, v2->physobj->id, detcyl);
        ++v6;
      }
      while ( v6 < v2->cell_array->num_cells );
    }
    v8 = v2->cell_array;
    if ( v8 )
    {
      v9 = v8->cells.data;
      if ( v9 )
        operator delete[](&v9[-1].cell);
      v8->cells.data = 0;
      operator delete(v8);
    }
    v2->cell_array = 0;
  }
}

//----- (00519D70) --------------------------------------------------------  // acclient.c:327512
void __thiscall DetectionManager::ClearPendingDeletions(DetectionManager *this)
{
  DetectionManager *v1; // esi@1
  unsigned int i; // edi@1
  ParticleEmitter *v3; // eax@2
  void *v4; // ebx@2
  unsigned int v5; // eax@6
  int v6; // eax@7

  v1 = this;
  for ( i = this->pending_deletions.m_num - 1; (i & 0x80000000) == 0; --i )
  {
    v3 = LongNIHash<TargettedVoyeurInfo>::remove(
           (LongNIHash<ParticleEmitter> *)&v1->detection_table,
           v1->pending_deletions.m_data[i]);
    v4 = v3;
    if ( v3 )
    {
      if ( !LODWORD(v3->parent_offset.qw) )
        DetectionManager::CleanupGlobalDetection(v1, (DetectionCylsphere *)v3);
      operator delete(v4);
    }
    v5 = v1->pending_deletions.m_num;
    if ( i < v5 )
    {
      v6 = v5 - 1;
      v1->pending_deletions.m_num = v6;
      if ( i != v6 )
        v1->pending_deletions.m_data[i] = v1->pending_deletions.m_data[v6];
    }
  }
}

//----- (00519DD0) --------------------------------------------------------  // acclient.c:327546
void __thiscall DetectionManager::CheckDetection(DetectionManager *this, DetectionCylsphere *detcyl)
{
  unsigned int v2; // edi@1
  DetectionManager *v3; // ebx@1
  HashBaseData<unsigned long> *v4; // eax@2
  __int32 v5; // eax@3
  unsigned int v6; // esi@3

  v2 = (unsigned int)&detcyl->info.object_id;
  v3 = this;
  if ( detcyl->info.object_id )
  {
    v4 = CPhysicsObj::GetObjectA(detcyl->info.object_id);
    if ( v4 )
    {
      detcyl->info.object_status = DetectionManager::CheckDetection(v3, detcyl, (CPhysicsObj *)v4);
      v5 = detcyl->info.object_status - 1;
      v6 = detcyl->context_id;
      if ( detcyl->info.object_status == 1 )
      {
LABEL_4:
        gmPanelUI::ListenToGlobalMessage((PlayerModule *)v3->physobj, (BaseProperty *)v6, v2);
        return;
      }
    }
    else
    {
      detcyl->info.object_status = 2;
      v5 = detcyl->info.object_status - 1;
      v6 = detcyl->context_id;
      if ( detcyl->info.object_status == 1 )
        goto LABEL_4;
    }
    if ( v5 == 1 )
      gmPanelUI::ListenToGlobalMessage((PlayerModule *)v3->physobj, (BaseProperty *)v6, v2);
  }
  else
  {
    DetectionManager::UpdateCellList(this, detcyl);
    DetectionManager::ReportGlobalDetection(v3, detcyl->context_id);
    v3->num_pending_global_detect_updates = 0;
  }
}

//----- (00519E60) --------------------------------------------------------  // acclient.c:327591
void __thiscall DetectionManager::~DetectionManager(DetectionManager *this)
{
  DetectionManager *v1; // edi@1
  LongNIHashData *i; // esi@2
  int v3; // ebx@2
  LongNIHash<DetectionCylsphere> *v4; // ebp@2
  void *v5; // edi@3
  DetectionManager *v6; // [sp+8h] [bp-14h]@1
  LongNIHashIter<DetectionCylsphere> iter; // [sp+Ch] [bp-10h]@1

  v1 = this;
  v6 = this;
  DetectionManager::ClearPendingDeletions(this);
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
    (LongNIHashIter<ParticleEmitter> *)&iter,
    (LongNIHash<ParticleEmitter> *)&v1->detection_table);
  if ( !iter.fDone )
  {
    i = iter.curDat;
    v3 = iter.bucketNo;
    v4 = iter.hash;
    if ( !iter.curDat )
      goto LABEL_8;
    while ( 1 )
    {
      v5 = i->data;
      if ( v5 )
      {
        if ( !*((_DWORD *)v5 + 3) )
          DetectionManager::CleanupGlobalDetection(v6, (DetectionCylsphere *)i->data);
        operator delete(v5);
      }
      v1 = v6;
LABEL_8:
      for ( i = i->next; !i; i = v4->buckets[v3] )
      {
        ++v3;
        if ( v3 >= v4->table_size )
          goto LABEL_12;
      }
    }
  }
LABEL_12:
  operator delete[](v1->pending_deletions.m_data);
  LongNIHash<DetectionCylsphere>::flush((LongNIHash<ParticleEmitter> *)&v1->detection_table);
  operator delete[](v1->detection_table.buckets);
  v1->detection_table.buckets = 0;
  v1->last_global_update.vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00519F10) --------------------------------------------------------  // acclient.c:327643
int __thiscall DetectionManager::DestroyDetectionCylsphere(DetectionManager *this, unsigned int context_id)
{
  LongNIHashData *v2; // edx@1
  unsigned int v3; // eax@6
  char *v4; // esi@6
  unsigned int v5; // eax@8

  v2 = this->detection_table.buckets[(context_id ^ (unsigned __int64)(context_id >> 16))
                                   % this->detection_table.table_size];
  if ( !v2 )
    return 0;
  while ( v2->key != context_id )
  {
    v2 = v2->next;
    if ( !v2 )
      return 0;
  }
  if ( !v2->data )
    return 0;
  v3 = this->pending_deletions.m_size;
  v4 = (char *)&this->pending_deletions;
  if ( this->pending_deletions.m_num < v3
    || (!v3 ? (v5 = 8) : (v5 = 2 * v3),
        AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&this->pending_deletions, v5)) )
    *(_DWORD *)(*(_DWORD *)v4 + 4 * (*((_DWORD *)v4 + 2))++) = context_id;
  return 1;
}

//----- (00519F90) --------------------------------------------------------  // acclient.c:327672
void __thiscall DetectionManager::CheckDetection(DetectionManager *this)
{
  DetectionManager *v1; // esi@1
  int v2; // ebp@2
  LongNIHashData *i; // esi@3
  LongNIHash<DetectionCylsphere> *v4; // ebx@3
  int v5; // edi@3
  DetectionCylsphere *v6; // eax@5
  int v7; // eax@15
  DetectionManager *v8; // [sp+4h] [bp-14h]@1
  LongNIHashIter<DetectionCylsphere> iter; // [sp+8h] [bp-10h]@2

  v1 = this;
  v8 = this;
  DetectionManager::ClearPendingDeletions(this);
  if ( PhysicsTimer::curr_time - v1->last_update_time >= 1.0 )
  {
    LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(
      (LongNIHashIter<ParticleEmitter> *)&iter,
      (LongNIHash<ParticleEmitter> *)&v1->detection_table);
    v2 = iter.fDone;
    if ( !iter.fDone )
    {
      i = iter.curDat;
      v4 = iter.hash;
      v5 = iter.bucketNo;
      do
      {
        if ( i )
          v6 = (DetectionCylsphere *)i->data;
        else
          v6 = 0;
        if ( !v2 )
        {
          for ( i = i->next; !i; i = v4->buckets[v5] )
          {
            ++v5;
            if ( v5 >= v4->table_size )
            {
              v2 = 1;
              break;
            }
          }
        }
        DetectionManager::CheckDetection(v8, v6);
      }
      while ( !v2 );
      v1 = v8;
    }
    v7 = HIDWORD(PhysicsTimer::curr_time);
    LODWORD(v1->last_update_time) = LODWORD(PhysicsTimer::curr_time);
    HIDWORD(v1->last_update_time) = v7;
  }
}

//----- (006FC640) --------------------------------------------------------  // acclient.c:784739
void sub_6FC640()
{
  flt_844014 = 1000.0 + 1.0;
}

//----- (006FC660) --------------------------------------------------------  // acclient.c:784745
void sub_6FC660()
{
  flt_844018 = 24.0 * 8.0;
}

//----- (006FC680) --------------------------------------------------------  // acclient.c:784751
void sub_6FC680()
{
  flt_84401C = 24.0 * 0.5;
}

//----- (006FC6A0) --------------------------------------------------------  // acclient.c:784757
int _E101_11()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_5;
  INITIAL_MAX_DATA_RATE_72 = LOWEST_DATA_RATE_5;
  return result;
}

//----- (006FC6B0) --------------------------------------------------------  // acclient.c:784767
void sub_6FC6B0()
{
  flt_844028 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC6D0) --------------------------------------------------------  // acclient.c:784773
void _E105_18()
{
  dbl_844030 = 1.0 / 30.0;
}

//----- (006FC6F0) --------------------------------------------------------  // acclient.c:784779
void _E107_13()
{
  dbl_844038 = 1.0 / 5.0;
}

//----- (006FC710) --------------------------------------------------------  // acclient.c:784785
int sub_6FC710()
{
  return atexit(nullsub_1101);
}

