/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CParticleManager
   Object     : PORTAL\cphysobj\CParticleManager.obj
   Functions  : 12
   Addresses  : 00519740 - 0051B8A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00519740) --------------------------------------------------------  // acclient.c:327054
void __thiscall LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(LongNIHashIter<ParticleEmitter> *this, LongNIHash<ParticleEmitter> *_hash)
{
  LongNIHashIter<ParticleEmitter> *v2; // eax@1
  int v3; // ecx@3
  LongNIHashData *v4; // ecx@4

  v2 = this;
  this->hash = _hash;
  this->bucketNo = -1;
  this->curDat = 0;
  this->fDone = 0;
  if ( _hash )
  {
    while ( 1 )
    {
      v3 = v2->bucketNo + 1;
      v2->bucketNo = v3;
      if ( v3 >= _hash->table_size )
        break;
      v4 = _hash->buckets[v3];
      v2->curDat = v4;
      if ( v4 )
        return;
    }
    v2->fDone = 1;
  }
  else
  {
    this->fDone = 1;
  }
}

//----- (00519800) --------------------------------------------------------  // acclient.c:327121
void __thiscall LongNIHash<DetectionCylsphere>::flush(LongNIHash<ParticleEmitter> *this)
{
  LongNIHash<ParticleEmitter> *v1; // ebx@1
  LongNIHashData **v2; // edi@1
  void *v3; // eax@2
  void *v4; // esi@3

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
          v4 = *(void **)v3;
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

//----- (005198C0) --------------------------------------------------------  // acclient.c:327166
int __thiscall LongNIHash<ParticleEmitter>::add(LongNIHash<ParticleEmitter> *this, ParticleEmitter *data, unsigned int key)
{
  LongNIHashData **v3; // edi@1
  void *v4; // eax@1
  int result; // eax@2

  v3 = &this->buckets[(key ^ (unsigned __int64)(key >> 16)) % this->table_size];
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 2) = key;
    *((_DWORD *)v4 + 1) = data;
    *(_DWORD *)v4 = *v3;
    *v3 = (LongNIHashData *)v4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051A770) --------------------------------------------------------  // acclient.c:328228
ParticleEmitter *__thiscall LongNIHash<TargettedVoyeurInfo>::remove(LongNIHash<ParticleEmitter> *this, unsigned int key)
{
  LongNIHashData **v2; // edx@1
  ParticleEmitter *result; // eax@1
  ParticleEmitter *v4; // ecx@3
  CPhysicsObj *v5; // esi@6
  CPhysicsObj *v6; // esi@8

  v2 = &this->buckets[(key ^ (unsigned __int64)(key >> 16)) % this->table_size];
  result = (ParticleEmitter *)*v2;
  if ( *v2 )
  {
    if ( result->part_index == key )
    {
LABEL_8:
      *v2 = (LongNIHashData *)result->id;
      v6 = result->parent;
      operator delete(result);
      result = (ParticleEmitter *)v6;
    }
    else
    {
      do
      {
        v4 = result;
        result = (ParticleEmitter *)result->id;
        if ( !result )
          return 0;
      }
      while ( result->part_index != key );
      if ( !v4 )
        goto LABEL_8;
      v4->id = result->id;
      v5 = result->parent;
      operator delete(result);
      result = (ParticleEmitter *)v5;
    }
  }
  return result;
}

//----- (0051B580) --------------------------------------------------------  // acclient.c:329273
int __thiscall ParticleManager::GetNumEmitters(ParticleManager *this)
{
  int v1; // esi@1
  int v2; // ecx@2
  LongNIHashData *v3; // eax@2
  LongNIHashIter<ParticleEmitter> iter; // [sp+4h] [bp-10h]@1

  v1 = 0;
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(&iter, &this->particle_table);
  if ( !iter.fDone )
  {
    v2 = iter.bucketNo;
    v3 = iter.curDat;
    while ( 1 )
    {
      v3 = v3->next;
      ++v1;
      while ( !v3 )
      {
        ++v2;
        if ( v2 >= iter.hash->table_size )
          return v1;
        v3 = iter.hash->buckets[v2];
      }
    }
  }
  return v1;
}

//----- (0051B5D0) --------------------------------------------------------  // acclient.c:329303
void __thiscall ParticleManager::ParticleManager(ParticleManager *this)
{
  ParticleManager *v1; // esi@1
  void *v2; // eax@1
  unsigned int v3; // edx@1

  v1 = this;
  this->next_emitter_id = -65536;
  this->particle_table.buckets = 0;
  this->particle_table.table_size = 2;
  v2 = operator new[](8u);
  v3 = 4 * v1->particle_table.table_size;
  v1->particle_table.buckets = (LongNIHashData **)v2;
  memset(v2, 0, v3);
}

//----- (0051B620) --------------------------------------------------------  // acclient.c:329320
void __thiscall ParticleManager::~ParticleManager(ParticleManager *this)
{
  LongNIHash<ParticleEmitter> *v1; // esi@1
  int v2; // eax@1
  LongNIHashData *i; // esi@2
  LongNIHash<ParticleEmitter> *v4; // ebx@2
  int v5; // edi@2
  ParticleEmitter *v6; // ebp@4
  char *v7; // [sp+4h] [bp-14h]@1
  LongNIHashIter<ParticleEmitter> iter; // [sp+8h] [bp-10h]@1

  v1 = &this->particle_table;
  v7 = (char *)&this->particle_table;
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(&iter, &this->particle_table);
  v2 = iter.fDone;
  if ( !iter.fDone )
  {
    i = iter.curDat;
    v4 = iter.hash;
    v5 = iter.bucketNo;
    do
    {
      if ( i )
        v6 = (ParticleEmitter *)i->data;
      else
        v6 = 0;
      if ( !v2 )
      {
        for ( i = i->next; !i; i = v4->buckets[v5] )
        {
          ++v5;
          if ( v5 >= v4->table_size )
          {
            iter.fDone = 1;
            break;
          }
        }
      }
      if ( v6 )
      {
        ParticleEmitter::~ParticleEmitter(v6);
        operator delete(v6);
      }
      v2 = iter.fDone;
    }
    while ( !iter.fDone );
    v1 = (LongNIHash<ParticleEmitter> *)v7;
  }
  LongNIHash<DetectionCylsphere>::flush(v1);
  operator delete[](v1->buckets);
  v1->buckets = 0;
}

//----- (0051B6C0) --------------------------------------------------------  // acclient.c:329374
unsigned int __thiscall ParticleManager::CreateParticleEmitter(ParticleManager *this, CPhysicsObj *physobj, IDClass<_tagDataID,32,0> emitter_info_id, unsigned int part_index, Frame *offset, unsigned int emitter_id)
{
  unsigned int v6; // esi@1
  ParticleManager *v7; // ebx@1
  ParticleEmitter *v8; // eax@2
  void *v9; // edi@2
  ParticleEmitter *v10; // eax@4
  ParticleEmitter *v11; // edi@4

  v6 = emitter_id;
  v7 = this;
  if ( emitter_id )
  {
    v8 = LongNIHash<TargettedVoyeurInfo>::remove(&this->particle_table, emitter_id);
    v9 = v8;
    if ( v8 )
    {
      ParticleEmitter::~ParticleEmitter(v8);
      operator delete(v9);
    }
  }
  ParticleEmitter::makeParticleEmitter(physobj);
  v11 = v10;
  if ( !v10 )
    return 0;
  if ( !ParticleEmitter::SetInfo(v10, emitter_info_id)
    || !ParticleEmitter::SetParenting(v11, part_index, offset)
    || !ParticleEmitter::InitEnd(v11) )
  {
    ParticleEmitter::~ParticleEmitter(v11);
    operator delete(v11);
    return 0;
  }
  if ( !emitter_id )
    v6 = v7->next_emitter_id++;
  v11->id = v6;
  LongNIHash<ParticleEmitter>::add(&v7->particle_table, v11, v6);
  return v6;
}

//----- (0051B770) --------------------------------------------------------  // acclient.c:329415
unsigned int __thiscall ParticleManager::DestroyParticleEmitter(ParticleManager *this, unsigned int emitter_id)
{
  unsigned int result; // eax@1
  ParticleEmitter *v3; // eax@2
  void *v4; // esi@2

  result = emitter_id;
  if ( emitter_id )
  {
    v3 = LongNIHash<TargettedVoyeurInfo>::remove(&this->particle_table, emitter_id);
    v4 = v3;
    if ( v3 )
    {
      ParticleEmitter::~ParticleEmitter(v3);
      operator delete(v4);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0051B7B0) --------------------------------------------------------  // acclient.c:329441
int __thiscall ParticleManager::StopParticleEmitter(ParticleManager *this, unsigned int emitter_id)
{
  LongNIHashData *v2; // edx@2
  void *v3; // edx@6
  int result; // eax@7

  if ( emitter_id )
  {
    v2 = this->particle_table.buckets[(emitter_id ^ (unsigned __int64)(emitter_id >> 16))
                                    % this->particle_table.table_size];
    if ( v2 )
    {
      if ( v2->key == emitter_id )
      {
LABEL_6:
        v3 = v2->data;
        if ( v3 )
        {
          result = 1;
          *((_DWORD *)v3 + 35) = 1;
          return result;
        }
      }
      else
      {
        while ( 1 )
        {
          v2 = v2->next;
          if ( !v2 )
            break;
          if ( v2->key == emitter_id )
            goto LABEL_6;
        }
      }
    }
  }
  return 0;
}

//----- (0051B800) --------------------------------------------------------  // acclient.c:329481
void __thiscall ParticleManager::UpdateParticles(ParticleManager *this)
{
  LongNIHash<ParticleEmitter> *v1; // ebp@2
  LongNIHashData *i; // esi@2
  int v3; // edi@2
  unsigned int *v4; // ebx@4
  LongNIHash<ParticleEmitter> *v5; // [sp+0h] [bp-14h]@1
  LongNIHashIter<ParticleEmitter> iter; // [sp+4h] [bp-10h]@1

  v5 = &this->particle_table;
  LongNIHashIter<DetectionCylsphere>::LongNIHashIter<DetectionCylsphere>(&iter, &this->particle_table);
  if ( !iter.fDone )
  {
    v1 = iter.hash;
    i = iter.curDat;
    v3 = iter.bucketNo;
    do
    {
      if ( i )
        v4 = (unsigned int *)i->data;
      else
        v4 = 0;
      if ( !iter.fDone )
      {
        for ( i = i->next; !i; i = v1->buckets[v3] )
        {
          ++v3;
          if ( v3 >= v1->table_size )
          {
            iter.fDone = 1;
            break;
          }
        }
      }
      if ( !ParticleEmitter::UpdateParticles((ParticleEmitter *)v4) )
      {
        LongNIHash<TargettedVoyeurInfo>::remove(v5, *v4);
        ParticleEmitter::~ParticleEmitter((ParticleEmitter *)v4);
        operator delete(v4);
      }
    }
    while ( !iter.fDone );
  }
}

//----- (0051B8A0) --------------------------------------------------------  // acclient.c:329527
unsigned int __thiscall ParticleManager::CreateBlockingParticleEmitter(ParticleManager *this, CPhysicsObj *physobj, IDClass<_tagDataID,32,0> emitter_info_id, unsigned int part_index, Frame *offset, unsigned int emitter_id)
{
  LongNIHashData *v6; // edx@2

  if ( emitter_id )
  {
    v6 = this->particle_table.buckets[(emitter_id ^ (unsigned __int64)(emitter_id >> 16))
                                    % this->particle_table.table_size];
    if ( v6 )
    {
      if ( v6->key == emitter_id )
      {
LABEL_6:
        if ( v6->data )
          return 0;
      }
      else
      {
        while ( 1 )
        {
          v6 = v6->next;
          if ( !v6 )
            break;
          if ( v6->key == emitter_id )
            goto LABEL_6;
        }
      }
    }
  }
  return ParticleManager::CreateParticleEmitter(this, physobj, emitter_info_id, part_index, offset, emitter_id);
}

