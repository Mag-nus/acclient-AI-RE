/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CObjMaint
   Object     : PORTAL\cobject\CObjMaint.obj
   Functions  : 56
   Addresses  : 005077A0 - 007668C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005077A0) --------------------------------------------------------  // acclient.c:308922
void __thiscall DArray<CPhysicsObj *>::grow(DArray<CPhysicsObj *> *this, unsigned int size)
{
  DArray<CPhysicsObj *> *v2; // esi@1
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
    v2->data = (CPhysicsObj **)v3;
    v2->sizeOf = size;
  }
  else
  {
    DArray<CPhysicsObj *>::shrink(this, size);
  }
}

//----- (00507800) --------------------------------------------------------  // acclient.c:308953
AC1Legacy::PQueueArray<double> *__thiscall AC1Legacy::PQueueArray<double>::scalar_deleting_destructor(AC1Legacy::PQueueArray<double> *this, unsigned int a2)
{
  AC1Legacy::PQueueArray<double> *v2; // esi@1
  AC1Legacy::PQueueArray<double>::PQueueNode *v3; // ST00_4@1

  v2 = this;
  v3 = this->A;
  this->vfptr = (AC1Legacy::PQueueArray<double>Vtbl *)AC1Legacy::PQueueArray<double>::vftable;
  operator delete[](v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C66A4: using guessed type int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char);

//----- (00507830) --------------------------------------------------------  // acclient.c:308969
void __thiscall DArray<CPhysicsObj *>::shrink(DArray<CPhysicsObj *> *this, unsigned int size)
{
  DArray<CPhysicsObj *> *v2; // esi@1
  CPhysicsObj **v3; // ST04_4@4
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
      v2->data = (CPhysicsObj **)v4;
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
    DArray<CPhysicsObj *>::grow(this, size);
  }
}

//----- (005078B0) --------------------------------------------------------  // acclient.c:309013
TResult *__thiscall CObjectMaint::QueryInterface(CObjectMaint *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( dword_841B64 & 1 )
  {
    v4 = Offsets_0[0].key;
  }
  else
  {
    v4 = (_GUID *)&CObjectMaint_InterfaceType_71;
    dword_841B64 |= 1u;
    Offsets_0[0].key = (_GUID *)&CObjectMaint_InterfaceType_71;
    dword_841B50 = 0;
    dword_841B54 = (int)&stru_7C6690;
    dword_841B58 = 0;
    dword_841B5C = 0;
    dword_841B60 = 0;
  }
  v5 = (int)Offsets_0;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 841B50: using guessed type int dword_841B50;
// 841B54: using guessed type int dword_841B54;
// 841B58: using guessed type int dword_841B58;
// 841B5C: using guessed type int dword_841B5C;
// 841B60: using guessed type int dword_841B60;

//----- (00507970) --------------------------------------------------------  // acclient.c:309076
CPhysicsObj *__thiscall CLostCell::remove_object(CLostCell *this, CPhysicsObj *object)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // edx@1
  CPhysicsObj **v4; // edi@2
  CPhysicsObj *result; // eax@2
  CPhysicsObj **v6; // esi@2

  v2 = this->num_objects;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->objects.data;
    result = object;
    v6 = this->objects.data;
    while ( *v6 != object )
    {
      ++v3;
      ++v6;
      if ( v3 >= this->num_objects )
        goto LABEL_5;
    }
    this->num_objects = v2 - 1;
    v4[v3] = v4[v2 - 1];
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (005079C0) --------------------------------------------------------  // acclient.c:309110
int __thiscall AC1Legacy::PQueueArray<double>::RemoveMin(AC1Legacy::PQueueArray<double> *this, long double *key, void **data)
{
  AC1Legacy::PQueueArray<double>::PQueueNode *v3; // eax@2
  int v4; // eax@3
  AC1Legacy::PQueueArray<double>::PQueueNode *v5; // edx@4
  int v6; // eax@4
  int v7; // eax@4
  int result; // eax@4

  if ( this->curNumNodes > 0 && (v3 = this->A) != 0 )
  {
    *(_QWORD *)key = *(_QWORD *)&v3->key;
    *data = this->A->data;
    v4 = this->curNumNodes;
    if ( v4 <= 1 )
    {
      this->curNumNodes = 0;
      PQueueArray<double,void *>::_Heapify((PQueueArray<double,void *> *)this, 1);
      result = 1;
    }
    else
    {
      v5 = this->A;
      v6 = v4 - 1;
      this->curNumNodes = v6;
      v7 = (int)&v5[v6];
      LODWORD(v5->key) = *(_DWORD *)v7;
      HIDWORD(v5->key) = *(_DWORD *)(v7 + 4);
      v5->data = *(void **)(v7 + 8);
      *((_DWORD *)&v5->data + 1) = *(_DWORD *)(v7 + 12);
      PQueueArray<double,void *>::_Heapify((PQueueArray<double,void *> *)this, 1);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00507A40) --------------------------------------------------------  // acclient.c:309152
IntrusiveHashTable<unsigned long,CLostCell *,0> *__thiscall IntrusiveHashTable<unsigned long,CLostCell *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,CLostCell *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,CLostCell *,0> *v2; // esi@1
  CLostCell **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,CLostCell *,0>Vtbl *)IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C66A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable[4])(void *, char);

//----- (00507A80) --------------------------------------------------------  // acclient.c:309173
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *v2; // esi@1
  HashTableData<unsigned long,double> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C66AC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable[3])(void *, char);

//----- (00507AC0) --------------------------------------------------------  // acclient.c:309194
HashBaseData<unsigned long> *__thiscall HashBase<unsigned long>::remove(HashBase<unsigned long> *this, unsigned int key)
{
  HashBaseData<unsigned long> **v2; // ecx@1
  HashBaseData<unsigned long> *result; // eax@1
  HashBaseData<unsigned long> *v4; // ecx@5
  HashBaseData<unsigned long> *v5; // ecx@8

  v2 = &this->buckets[this->table_mask & (key ^ (key >> this->key_shift))];
  result = *v2;
  if ( !*v2 )
    goto LABEL_7;
  if ( result->id == key )
  {
    *v2 = result->hash_next;
    return result;
  }
  if ( result->hash_next )
  {
    while ( 1 )
    {
      v4 = result->hash_next;
      if ( v4->id == key )
        break;
      result = result->hash_next;
      if ( !v4->hash_next )
        goto LABEL_7;
    }
    v5 = result->hash_next;
    result->hash_next = v5->hash_next;
    result = v5;
  }
  else
  {
LABEL_7:
    result = 0;
  }
  return result;
}

//----- (00507B20) --------------------------------------------------------  // acclient.c:309234
int __thiscall InterfacePtr<Interface>::_QueryInterface(void *this, int a2, int a3)
{
  void *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  int v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  int v9; // ecx@9
  char v10; // [sp+Ch] [bp-4h]@2

  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(char *, Turbine_GUID *, int *))(v4 + 12))(&v10, &stru_7C6690, &a3);
    v6 = *(_DWORD *)v3;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = v8;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    v9 = *(_DWORD *)this;
    if ( *(_DWORD *)v3 )
    {
      *(_DWORD *)v3 = 0;
      (*(void (**)(void))(*(_DWORD *)v9 + 20))();
      *((_DWORD *)v3 + 1) = 0;
    }
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (00507BB0) --------------------------------------------------------  // acclient.c:309288
void __stdcall CObjectMaint::ReleaseObjCell(CObjCell *cell)
{
  unsigned int v2; // esi@1
  unsigned int v3; // edi@1
  unsigned int v4; // ebp@3
  CPhysicsObj *v5; // esi@4

  v2 = 0;
  v3 = 0;
  if ( !(_S112_35 & 1) )
  {
    _S112_35 |= 1u;
    object_list.data = 0;
    object_list.sizeOf = 0;
    object_list.next_available = 0;
    object_list.blocksize = 128;
    atexit(_E113_61);
  }
  v4 = 0;
  if ( cell->num_objects > 0 )
  {
    do
    {
      v5 = cell->object_list.data[v4];
      if ( !(v5->state & 1) && !v5->parent )
      {
        if ( v3 >= object_list.sizeOf )
          DArray<CPhysicsObj *>::grow(&object_list, v3 + object_list.blocksize);
        object_list.data[v3] = v5;
        if ( v3 >= object_list.next_available )
          object_list.next_available = v3 + 1;
        ++v3;
      }
      ++v4;
    }
    while ( v4 < cell->num_objects );
    v2 = 0;
  }
  if ( v3 )
  {
    do
      CPhysicsObj::leave_visibility(object_list.data[v2++]);
    while ( v2 < v3 );
  }
}

//----- (00507C90) --------------------------------------------------------  // acclient.c:309335
void __thiscall CObjectMaint::OnShutdown(CObjectMaint *this)
{
  Interface *v1; // esi@1
  Interface *v2; // ST08_4@1
  InterfaceSystem *v3; // eax@1
  TResult result; // [sp+4h] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+8h] [bp-8h]@1

  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&result, (int)this);
  v1 = spcIFace.m_pInterface;
  v2 = spcIFace.m_pInterface;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::UnregisterClassA(v3, &result, &CObjectMaint_ClassType_0, v2, 0);
  if ( v1 )
    v1->vfptr->Release(v1);
}

//----- (00507CE0) --------------------------------------------------------  // acclient.c:309355
void __thiscall CObjectMaint::AddObject(CObjectMaint *this, CPhysicsObj *object)
{
  unsigned int v2; // eax@1

  v2 = this->object_table.table_mask & (object->id ^ (object->id >> this->object_table.key_shift));
  object->hash_next = this->object_table.buckets[v2];
  this->object_table.buckets[v2] = (HashBaseData<unsigned long> *)object;
}

//----- (00507D20) --------------------------------------------------------  // acclient.c:309365
void __thiscall CObjectMaint::AddWeenieObject(CObjectMaint *this, CWeenieObject *object)
{
  unsigned int v2; // eax@1

  v2 = this->weenie_object_table.table_mask & (object->id ^ (object->id >> this->weenie_object_table.key_shift));
  object->hash_next = this->weenie_object_table.buckets[v2];
  this->weenie_object_table.buckets[v2] = (HashBaseData<unsigned long> *)object;
}

//----- (00507D60) --------------------------------------------------------  // acclient.c:309375
HashBaseData<unsigned long> *__thiscall CObjectMaint::GetObjectA(CObjectMaint *this, unsigned int object_id)
{
  HashBaseData<unsigned long> *result; // eax@1

  result = this->object_table.buckets[this->object_table.table_mask & (object_id ^ (object_id >> this->object_table.key_shift))];
  if ( result )
  {
    while ( object_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00507DB0) --------------------------------------------------------  // acclient.c:309398
HashBaseData<unsigned long> *__thiscall CObjectMaint::GetWeenieObject(CObjectMaint *this, unsigned int object_id)
{
  HashBaseData<unsigned long> *result; // eax@1

  result = this->weenie_object_table.buckets[this->weenie_object_table.table_mask & (object_id ^ (object_id >> this->weenie_object_table.key_shift))];
  if ( result )
  {
    while ( object_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00507E00) --------------------------------------------------------  // acclient.c:309421
HashBaseData<unsigned long> *__thiscall CObjectMaint::GetObjectInventory(CObjectMaint *this, unsigned int object_id)
{
  HashBaseData<unsigned long> *result; // eax@1

  result = this->object_inventory_table.buckets[this->object_inventory_table.table_mask & (object_id ^ (object_id >> this->object_inventory_table.key_shift))];
  if ( result )
  {
    while ( object_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (00507E50) --------------------------------------------------------  // acclient.c:309444
void __thiscall CObjectMaint::UnRegisterAllNoticeHandlers(CObjectMaint *this, NoticeHandler *_handler)
{
  unsigned int v2; // edi@1
  HashBase<unsigned long> *v3; // ebx@1
  HashBaseData<unsigned long> *v4; // esi@2
  LongHashIter<CWeenieObject> ot_iter; // [sp+8h] [bp-14h]@1

  v2 = 0;
  v3 = (HashBase<unsigned long> *)&this->weenie_object_table.vfptr;
  ot_iter.myHash_ = (HashBase<unsigned long> *)&this->weenie_object_table.vfptr;
  ot_iter.lastThisChain_ = 0;
  ot_iter.curBucket_ = 0;
  if ( this != (CObjectMaint *)-180 )
  {
    v4 = *this->weenie_object_table.buckets;
    ot_iter.fEnd_ = 0;
    ot_iter.curPtr_ = v4;
    if ( v4 )
      goto LABEL_5;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&ot_iter.myHash_);
    if ( !ot_iter.fEnd_ )
    {
      v4 = ot_iter.curPtr_;
      v2 = ot_iter.curBucket_;
      v3 = ot_iter.myHash_;
LABEL_5:
      while ( 1 )
      {
        v4[1].vfptr[3].__vecDelDtor(&v4[1], (unsigned int)_handler);
        v4 = v4->hash_next;
        if ( !v4 )
          break;
LABEL_8:
        if ( ot_iter.fEnd_ )
          return;
      }
      while ( 1 )
      {
        ++v2;
        if ( v2 >= v3->table_size )
          break;
        v4 = v3->buckets[v2];
        if ( v4 )
          goto LABEL_8;
      }
    }
  }
}

//----- (00507F70) --------------------------------------------------------  // acclient.c:309530
int __thiscall CObjectMaint::GetObjectA(CObjectMaint *this, unsigned int object_id, CPhysicsObj **physobj, CWeenieObject **weenieobj)
{
  CObjectMaint *v4; // esi@1
  int result; // eax@1

  v4 = this;
  *physobj = (CPhysicsObj *)CObjectMaint::GetObjectA(this, object_id);
  result = (int)CObjectMaint::GetWeenieObject(v4, object_id);
  *weenieobj = (CWeenieObject *)result;
  if ( *physobj || result )
    result = 1;
  return result;
}

//----- (00507FB0) --------------------------------------------------------  // acclient.c:309545
void __thiscall CObjectMaint::RemoveFromLostCell(CObjectMaint *this, CPhysicsObj *object)
{
  CPhysicsObj *v2; // esi@1
  CLostCell *v3; // eax@3

  v2 = object;
  if ( !object->cell && !object->parent )
  {
    object = (CPhysicsObj *)object->m_position.objcell_id;
    v3 = (CLostCell *)IntrusiveHashTable<unsigned long,CLostCell *,0>::find(
                        (IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0> *)&this->lost_cell_table,
                        (IDClass<_tagDataID,32,0> *)&object);
    if ( v3 )
      CLostCell::remove_object(v3, v2);
  }
}

//----- (00507FF0) --------------------------------------------------------  // acclient.c:309563
void __thiscall IntrusiveHashTable<unsigned long,CLostCell *,0>::IntrusiveHashTable<unsigned long,CLostCell *,0>(IntrusiveHashTable<unsigned long,CLostCell *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,CLostCell *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,CLostCell *,0>Vtbl *)IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (CLostCell **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (CLostCell **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C66A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable[4])(void *, char);

//----- (00508080) --------------------------------------------------------  // acclient.c:309596
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,double> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,double> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7C66AC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable[3])(void *, char);

//----- (00508110) --------------------------------------------------------  // acclient.c:309629
void __thiscall IntrusiveHashTable<unsigned long,CLostCell *,0>::delete_contents(IntrusiveHashTable<unsigned long,CLostCell *,0> *this)
{
  IntrusiveHashTable<unsigned long,CLostCell *,0> *v1; // esi@1
  int v2; // ecx@2
  CLostCell **v3; // eax@3
  int v4; // eax@4
  CLostCell **v5; // edx@5
  CLostCell *v6; // edi@5
  CLostCell *v7; // eax@7
  CLostCell *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (CLostCell **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (CLostCell **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_17:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      operator delete[](v6->objects.data);
      v6->objects.data = 0;
      operator delete(v6);
    }
  }
}

//----- (005081A0) --------------------------------------------------------  // acclient.c:309690
CLostCell *__thiscall CObjectMaint::GetLostCell(CObjectMaint *this, unsigned int cell_id)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v2; // esi@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v3; // edi@1
  CLostCell *result; // eax@1
  void *v5; // eax@6

  v2 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->lost_cell_table;
  v3 = 0;
  result = this->lost_cell_table.m_buckets[cell_id % this->lost_cell_table.m_numBuckets];
  if ( !result )
    goto LABEL_6;
  while ( result->m_hashKey != cell_id )
  {
    result = result->m_hashNext;
    if ( !result )
      goto LABEL_6;
  }
  if ( !result )
  {
LABEL_6:
    v5 = operator new(0x1Cu);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *(_DWORD *)v5 = cell_id;
      *((_DWORD *)v5 + 3) = 0;
      *((_DWORD *)v5 + 6) = 0;
      *((_DWORD *)v5 + 5) = 0;
      *((_DWORD *)v5 + 4) = 128;
      v3 = (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5;
    }
    IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
      v2,
      v3);
    result = (CLostCell *)v3;
  }
  return result;
}

//----- (00508210) --------------------------------------------------------  // acclient.c:309732
void __thiscall CObjectMaint::GotoLostCell(CObjectMaint *this, CPhysicsObj *object, unsigned int new_cell_id)
{
  CObjectMaint *v3; // esi@1
  CLostCell *v4; // eax@2
  CLostCell *v5; // esi@2
  unsigned int v6; // eax@2
  unsigned int v7; // eax@4
  CPhysicsObj **v8; // edx@4

  v3 = this;
  if ( !object->parent )
  {
    CPhysicsObj::set_cell_id(object, new_cell_id);
    v4 = CObjectMaint::GetLostCell(v3, object->m_position.objcell_id);
    v5 = v4;
    v6 = v4->num_objects;
    if ( v6 >= v5->objects.sizeOf )
      DArray<CPhysicsObj *>::grow(&v5->objects, v6 + 5);
    v7 = v5->num_objects;
    v8 = v5->objects.data;
    v5->num_objects = v7 + 1;
    v8[v7] = object;
  }
}

//----- (00508260) --------------------------------------------------------  // acclient.c:309758
void __thiscall CObjectMaint::InitObjCell(CObjectMaint *this, CObjCell *cell)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // esi@1
  unsigned int v4; // edi@2

  cell = (CObjCell *)cell->m_DID.id;
  v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->lost_cell_table,
         (IDClass<_tagDataID,32,0> *)&cell);
  v3 = v2;
  if ( v2 )
  {
    v4 = 0;
    if ( v2[1].m_hashKey.id )
    {
      do
        CPhysicsObj::reenter_visibility(*((CPhysicsObj **)&v3[1].m_hashNext->m_hashKey.id + v4++));
      while ( v4 < v3[1].m_hashKey.id );
    }
    v3[1].m_hashKey.id = 0;
    operator delete[](v3[1].m_hashNext);
    v3[1].m_hashNext = 0;
    operator delete(v3);
  }
}

//----- (005082D0) --------------------------------------------------------  // acclient.c:309786
char __thiscall HashTable<unsigned long,double,0>::add(HashTable<unsigned long,double,0> *this, const unsigned int *_key, const long double *_data)
{
  HashTable<unsigned long,double,0> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_QWORD *)v4 + 1) = *(_QWORD *)_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_intrusiveTable,
         (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00508330) --------------------------------------------------------  // acclient.c:309822
HashTable<unsigned long,double,0> *__thiscall HashTable<unsigned long,double,0>::scalar_deleting_destructor(HashTable<unsigned long,double,0> *this, unsigned int a2)
{
  HashTable<unsigned long,double,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,double,0>Vtbl *)&HashTable<unsigned long,double,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C66AC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable[3])(void *, char);
// 7C66B4: using guessed type int (__thiscall *HashTable<unsigned long,double,0>::vftable)(void *, char);

//----- (00508390) --------------------------------------------------------  // acclient.c:309848
void __thiscall CObjectMaint::UpdateVisibleObjectList(CObjectMaint *this)
{
  CObjectMaint *v1; // ebx@1
  unsigned int v2; // edi@1
  HashBase<unsigned long> *v3; // ebp@1
  HashBaseData<unsigned long> *v4; // esi@2
  LongHashIter<CPhysicsObj> iter; // [sp+Ch] [bp-14h]@1

  v1 = this;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->visible_object_table.m_intrusiveTable);
  v2 = 0;
  v3 = (HashBase<unsigned long> *)&v1->object_table.vfptr;
  iter.myHash_ = (HashBase<unsigned long> *)&v1->object_table.vfptr;
  iter.lastThisChain_ = 0;
  iter.curBucket_ = 0;
  if ( v1 != (CObjectMaint *)-132 )
  {
    v4 = *v1->object_table.buckets;
    iter.fEnd_ = 0;
    iter.curPtr_ = v4;
    if ( v4 )
      goto LABEL_5;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&iter.myHash_);
    if ( !iter.fEnd_ )
    {
      v4 = iter.curPtr_;
      v2 = iter.curBucket_;
      v3 = iter.myHash_;
      while ( 1 )
      {
LABEL_5:
        if ( v4[12].vfptr )
        {
          if ( !((unsigned int)v4[14].vfptr & 1) )
            HashSet<unsigned long>::add(&v1->visible_object_table, &v4->id);
        }
        v4 = v4->hash_next;
        if ( !v4 )
          break;
LABEL_11:
        if ( iter.fEnd_ )
          return;
      }
      while ( 1 )
      {
        ++v2;
        if ( v2 >= v3->table_size )
          break;
        v4 = v3->buckets[v2];
        if ( v4 )
          goto LABEL_11;
      }
    }
  }
}

//----- (00508440) --------------------------------------------------------  // acclient.c:309905
void __thiscall CObjectMaint::RemoveObjectToBeDestroyed(CObjectMaint *this, unsigned int object_id)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1

  v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->destruction_object_table.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&object_id);
  if ( v2 )
    operator delete(v2);
}

//----- (00508460) --------------------------------------------------------  // acclient.c:309917
void __thiscall CObjectMaint::DeleteObject(CObjectMaint *this, CPhysicsObj *object)
{
  CObjectMaint *v2; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // eax@1

  v2 = this;
  CPhysicsObj::exit_world(object);
  CPhysicsObj::leave_world(object);
  HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v2->object_table.vfptr, object->id);
  HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v2->null_object_table.vfptr, object->id);
  v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v2->destruction_object_table.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&object->id);
  if ( v3 )
    operator delete(v3);
  CPhysicsObj::unset_parent(object);
  CPhysicsObj::unparent_children(object);
  object->vfptr->__vecDelDtor((HashBaseData<unsigned long> *)object, 1u);
}

//----- (005084D0) --------------------------------------------------------  // acclient.c:309938
int __thiscall CObjectMaint::DeleteObject(CObjectMaint *this, unsigned int object_id)
{
  CObjectMaint *v2; // edi@1
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // esi@13
  int result; // eax@16
  int retval; // [sp+10h] [bp-4h]@1

  v2 = this;
  retval = 1;
  v3 = this->object_table.buckets[this->object_table.table_mask & (object_id ^ (object_id >> this->object_table.key_shift))];
  if ( v3 )
  {
    while ( object_id != v3->id )
    {
      v3 = v3->hash_next;
      if ( !v3 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    v3 = 0;
  }
  if ( v3 )
    goto LABEL_21;
  v3 = this->null_object_table.buckets[this->null_object_table.table_mask & (object_id ^ (object_id >> this->null_object_table.key_shift))];
  if ( v3 )
  {
    while ( object_id != v3->id )
    {
      v3 = v3->hash_next;
      if ( !v3 )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v3 = 0;
  }
  if ( v3 )
LABEL_21:
    CObjectMaint::DeleteObject(this, (CPhysicsObj *)v3);
  else
    retval = 0;
  v4 = v2->weenie_object_table.buckets[v2->weenie_object_table.table_mask & (object_id ^ (object_id >> v2->weenie_object_table.key_shift))];
  if ( !v4 )
    goto LABEL_16;
  while ( object_id != v4->id )
  {
    v4 = v4->hash_next;
    if ( !v4 )
      goto LABEL_16;
  }
  if ( v4 )
  {
    ((void (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[1].__vecDelDtor)(v4);
    HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v2->weenie_object_table.vfptr, v4->id);
    HashBase<unsigned long>::remove((HashBase<unsigned long> *)&v2->null_weenie_object_table.vfptr, v4->id);
    v4->vfptr->__vecDelDtor(v4, 1u);
    result = retval;
  }
  else
  {
LABEL_16:
    result = 0;
  }
  return result;
}

//----- (005085D0) --------------------------------------------------------  // acclient.c:310011
void __thiscall CObjectMaint::CObjectMaint(CObjectMaint *this)
{
  int v1; // esi@1
  signed int v2; // eax@1
  int v3; // edx@2
  unsigned int v4; // eax@3
  signed int v5; // eax@5
  int v6; // edx@6
  unsigned int v7; // eax@7
  signed int v8; // eax@9
  int v9; // edx@10
  unsigned int v10; // eax@11
  signed int v11; // eax@13
  int v12; // edx@14
  unsigned int v13; // eax@15
  signed int v14; // eax@17
  int v15; // edx@18
  unsigned int v16; // eax@19
  Interface *v17; // ebx@21
  Interface *v18; // ST08_4@21
  InterfaceSystem *v19; // eax@21
  char v20; // [sp+10h] [bp-10h]@21
  TResult tr; // [sp+14h] [bp-Ch]@21
  InterfacePtr<Interface> spcIFace; // [sp+18h] [bp-8h]@21

  v1 = (int)this;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->vfptr = (InterfaceVtbl *)&CObjectMaint::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  this->is_active = 1;
  IntrusiveHashTable<unsigned long,CLostCell *,0>::IntrusiveHashTable<unsigned long,CLostCell *,0>(
    &this->lost_cell_table,
    0x80u);
  *(_DWORD *)(v1 + 132) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 152) = 0;
  *(_DWORD *)(v1 + 144) = operator new[](0x200u);
  *(_DWORD *)(v1 + 148) = 128;
  *(_DWORD *)(v1 + 140) = 8;
  *(_DWORD *)(v1 + 136) = 0;
  v2 = 1;
  do
  {
    v3 = v2 | *(_DWORD *)(v1 + 136);
    v2 *= 2;
    *(_DWORD *)(v1 + 136) = v3;
  }
  while ( (v2 | (unsigned int)v3) < *(_DWORD *)(v1 + 148) );
  v4 = 0;
  do
    *(_DWORD *)(*(_DWORD *)(v1 + 144) + 4 * v4++) = 0;
  while ( v4 < *(_DWORD *)(v1 + 148) );
  *(_DWORD *)(v1 + 132) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 156) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 176) = 0;
  *(_DWORD *)(v1 + 168) = operator new[](0x40u);
  *(_DWORD *)(v1 + 172) = 16;
  *(_DWORD *)(v1 + 164) = 8;
  *(_DWORD *)(v1 + 160) = 0;
  v5 = 1;
  do
  {
    v6 = v5 | *(_DWORD *)(v1 + 160);
    v5 *= 2;
    *(_DWORD *)(v1 + 160) = v6;
  }
  while ( (v5 | (unsigned int)v6) < *(_DWORD *)(v1 + 172) );
  v7 = 0;
  do
    *(_DWORD *)(*(_DWORD *)(v1 + 168) + 4 * v7++) = 0;
  while ( v7 < *(_DWORD *)(v1 + 172) );
  *(_DWORD *)(v1 + 156) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 180) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 200) = 0;
  *(_DWORD *)(v1 + 192) = operator new[](0x200u);
  *(_DWORD *)(v1 + 196) = 128;
  *(_DWORD *)(v1 + 188) = 8;
  *(_DWORD *)(v1 + 184) = 0;
  v8 = 1;
  do
  {
    v9 = v8 | *(_DWORD *)(v1 + 184);
    v8 *= 2;
    *(_DWORD *)(v1 + 184) = v9;
  }
  while ( (v8 | (unsigned int)v9) < *(_DWORD *)(v1 + 196) );
  v10 = 0;
  do
    *(_DWORD *)(*(_DWORD *)(v1 + 192) + 4 * v10++) = 0;
  while ( v10 < *(_DWORD *)(v1 + 196) );
  *(_DWORD *)(v1 + 180) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 204) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 224) = 0;
  *(_DWORD *)(v1 + 216) = operator new[](0x40u);
  *(_DWORD *)(v1 + 220) = 16;
  *(_DWORD *)(v1 + 212) = 8;
  *(_DWORD *)(v1 + 208) = 0;
  v11 = 1;
  do
  {
    v12 = v11 | *(_DWORD *)(v1 + 208);
    v11 *= 2;
    *(_DWORD *)(v1 + 208) = v12;
  }
  while ( (v11 | (unsigned int)v12) < *(_DWORD *)(v1 + 220) );
  v13 = 0;
  do
    *(_DWORD *)(*(_DWORD *)(v1 + 216) + 4 * v13++) = 0;
  while ( v13 < *(_DWORD *)(v1 + 220) );
  *(_DWORD *)(v1 + 204) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 228) = HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(
    (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *)(v1 + 232),
    0x80u);
  *(_DWORD *)(v1 + 344) = &HashTable<unsigned long,double,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0> *)(v1 + 348),
    0x40u);
  *(_DWORD *)(v1 + 460) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 480) = 0;
  *(_DWORD *)(v1 + 472) = operator new[](0x80u);
  *(_DWORD *)(v1 + 476) = 32;
  *(_DWORD *)(v1 + 468) = 8;
  *(_DWORD *)(v1 + 464) = 0;
  v14 = 1;
  do
  {
    v15 = v14 | *(_DWORD *)(v1 + 464);
    v14 *= 2;
    *(_DWORD *)(v1 + 464) = v15;
  }
  while ( (v14 | (unsigned int)v15) < *(_DWORD *)(v1 + 476) );
  v16 = 0;
  do
    *(_DWORD *)(*(_DWORD *)(v1 + 472) + 4 * v16++) = 0;
  while ( v16 < *(_DWORD *)(v1 + 476) );
  *(_DWORD *)(v1 + 460) = LongHash<CWeenieObject>::vftable;
  *(_DWORD *)(v1 + 484) = AC1Legacy::PQueueArray<double>::vftable;
  *(_DWORD *)(v1 + 492) = 0;
  *(_DWORD *)(v1 + 488) = operator new[](0x400u);
  *(_DWORD *)(v1 + 500) = 64;
  *(_DWORD *)(v1 + 496) = 64;
  CObjectMaint::s_pcInstance = (CObjectMaint *)v1;
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&v20, v1);
  v17 = spcIFace.m_pInterface;
  v18 = spcIFace.m_pInterface;
  v19 = InterfaceSystem::GetInstance();
  InterfaceSystem::RegisterClassA(v19, &tr, &CObjectMaint_ClassType_0, v18, 0);
  if ( v17 )
    v17->vfptr->Release(v17);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 7C66A4: using guessed type int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C66B4: using guessed type int (__thiscall *HashTable<unsigned long,double,0>::vftable)(void *, char);
// 7C66B8: using guessed type __int32 (__stdcall *CObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

//----- (00508940) --------------------------------------------------------  // acclient.c:310174
CPhysicsObj *__stdcall CObjectMaint::CreateObject(unsigned int objectID, VisualDesc *vdesc, PhysicsDesc *physicsdesc, WeenieDesc *wdesc)
{
  return 0;
}

//----- (00508980) --------------------------------------------------------  // acclient.c:310192
unsigned int __thiscall CObjectMaint::Release(CObjectMaint *this)
{
  CObjectMaint *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    ((void (__thiscall *)(CObjectMaint *, signed int))v1->vfptr[1].IUnknown_Release)(v1, 1);
  return v2;
}

//----- (005089B0) --------------------------------------------------------  // acclient.c:310205
void __thiscall CObjectMaint::UseTime(CObjectMaint *this)
{
  CObjectMaint *v1; // ebp@1
  int v2; // eax@1
  long double *v3; // eax@6
  void *v4; // esi@8
  unsigned int v5; // edx@8
  HashTableData<unsigned long,double> **v6; // eax@8
  HashTableData<unsigned long,double> *v7; // edx@8
  HashSetData<IDClass<_tagDataID,32,0> > *v8; // eax@14
  HashBase<unsigned long> *v9; // ebx@17
  unsigned int v10; // edi@17
  HashBaseData<unsigned long> *v11; // esi@18
  int v12; // ebp@18
  unsigned int v13; // eax@22
  unsigned int v14; // ST04_4@22
  HashBase<unsigned long> *v15; // ebx@28
  int v16; // ebp@28
  unsigned int v17; // edi@28
  HashBaseData<unsigned long> *v18; // esi@29
  unsigned int v19; // edx@33
  unsigned int v20; // ST04_4@33
  void *data; // [sp+14h] [bp-2Ch]@4
  CObjectMaint *v22; // [sp+18h] [bp-28h]@1
  unsigned int object_id; // [sp+1Ch] [bp-24h]@8
  long double key; // [sp+20h] [bp-20h]@7
  LongHashIter<CWeenieObject> weenie_iter; // [sp+2Ch] [bp-14h]@17

  v1 = this;
  v2 = this->is_active;
  v22 = this;
  if ( v2 )
  {
    if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - last_radar_update > 1.0 )
    {
      CObjectMaint::UpdateVisibleObjectList(this);
      *(_QWORD *)&last_radar_update = Timer::cur_time;
    }
    data = 0;
LABEL_5:
    while ( v1->object_destruction_queue.curNumNodes > 0 )
    {
      v3 = &v1->object_destruction_queue.A->key;
      if ( !v3 )
        break;
      key = *v3;
      if ( key >= COERCE_DOUBLE(Timer::cur_time.Cmd) )
        break;
      AC1Legacy::PQueueArray<double>::RemoveMin(&v1->object_destruction_queue, &key, &data);
      v4 = data;
      v5 = (unsigned int)data % v1->destruction_object_table.m_intrusiveTable.m_numBuckets;
      v6 = v1->destruction_object_table.m_intrusiveTable.m_buckets;
      object_id = (unsigned int)data;
      v7 = v6[v5];
      if ( v7 )
      {
        while ( (void *)v7->m_hashKey != data )
        {
          v7 = v7->m_hashNext;
          if ( !v7 )
            goto LABEL_5;
        }
        if ( v7 && fabs(v7->m_data - key) < 0.00019999999 )
        {
          v8 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
                 (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v1->destruction_object_table.m_intrusiveTable,
                 (IDClass<_tagDataID,32,0> *)&object_id);
          if ( v8 )
            operator delete(v8);
          ((void (__thiscall *)(CObjectMaint *, void *))v1->vfptr[1].IUnknown_AddRef)(v1, v4);
        }
      }
    }
    v9 = (HashBase<unsigned long> *)&v1->null_object_table.vfptr;
    v10 = 0;
    weenie_iter.myHash_ = (HashBase<unsigned long> *)&v1->null_object_table.vfptr;
    weenie_iter.lastThisChain_ = 0;
    weenie_iter.curBucket_ = 0;
    if ( v1 != (CObjectMaint *)-156 )
    {
      v11 = *v1->null_object_table.buckets;
      v12 = 0;
      weenie_iter.fEnd_ = 0;
      weenie_iter.curPtr_ = v11;
      if ( v11 )
        goto LABEL_21;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&weenie_iter.myHash_);
      v12 = weenie_iter.fEnd_;
      if ( !weenie_iter.fEnd_ )
      {
        v11 = weenie_iter.curPtr_;
        v10 = weenie_iter.curBucket_;
        v9 = weenie_iter.myHash_;
        while ( 1 )
        {
LABEL_21:
          if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - *(double *)&v11[18].vfptr > 20.0 )
          {
            v13 = Timer::cur_time.Param;
            v14 = v11->id;
            v11[18].vfptr = (HashBaseData<unsigned long>Vtbl *)Timer::cur_time.Cmd;
            v11[18].hash_next = (HashBaseData<unsigned long> *)v13;
            Proto_UI::SendForceObjdesc(v14);
          }
          v11 = v11->hash_next;
          if ( !v11 )
            break;
LABEL_26:
          if ( v12 )
            goto LABEL_27;
        }
        while ( 1 )
        {
          ++v10;
          if ( v10 >= v9->table_size )
            break;
          v11 = v9->buckets[v10];
          if ( v11 )
            goto LABEL_26;
        }
      }
LABEL_27:
      v1 = v22;
    }
    v15 = (HashBase<unsigned long> *)&v1->null_weenie_object_table.vfptr;
    v16 = 0;
    v17 = 0;
    weenie_iter.myHash_ = v15;
    weenie_iter.lastThisChain_ = 0;
    weenie_iter.curBucket_ = 0;
    if ( v15 )
    {
      v18 = *v15->buckets;
      weenie_iter.fEnd_ = 0;
      weenie_iter.curPtr_ = v18;
      if ( v18 )
        goto LABEL_32;
      HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&weenie_iter.myHash_);
      v16 = weenie_iter.fEnd_;
      if ( !weenie_iter.fEnd_ )
      {
        v18 = weenie_iter.curPtr_;
        v17 = weenie_iter.curBucket_;
        v15 = weenie_iter.myHash_;
        while ( 1 )
        {
LABEL_32:
          if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - *(double *)&v18[2].vfptr > 20.0 )
          {
            v19 = Timer::cur_time.Param;
            v20 = v18->id;
            v18[2].vfptr = (HashBaseData<unsigned long>Vtbl *)Timer::cur_time.Cmd;
            v18[2].hash_next = (HashBaseData<unsigned long> *)v19;
            Proto_UI::SendForceObjdesc(v20);
          }
          v18 = v18->hash_next;
          if ( !v18 )
            break;
LABEL_37:
          if ( v16 )
            return;
        }
        while ( 1 )
        {
          ++v17;
          if ( v17 >= v15->table_size )
            break;
          v18 = v15->buckets[v17];
          if ( v18 )
            goto LABEL_37;
        }
      }
    }
  }
}

//----- (00508C30) --------------------------------------------------------  // acclient.c:310382
void __thiscall CObjectMaint::DestroyObjects(CObjectMaint *this)
{
  CObjectMaint *v1; // ebp@1
  HashBase<unsigned long> *v2; // esi@1
  unsigned int v3; // edx@1
  HashBaseData<unsigned long> *v4; // edi@2
  unsigned int v5; // eax@6
  unsigned int v6; // edx@12
  int v7; // ecx@12
  int v8; // eax@12
  int v9; // ecx@16
  unsigned int v10; // edx@20
  int v11; // ecx@20
  int v12; // eax@20
  int v13; // ecx@24
  int v14; // edx@28
  HashTableData<unsigned long,double> **v15; // eax@28
  HashTableData<unsigned long,double> *v16; // ecx@28
  int v17; // ebx@28
  HashTableData<unsigned long,double> *v18; // eax@28
  HashTableData<unsigned long,double> *v19; // edx@34
  HashBaseData<unsigned long> *v20; // esi@41
  unsigned int v21; // edx@45
  int v22; // ecx@45
  int v23; // eax@45
  int v24; // ecx@49
  unsigned int v25; // edx@53
  int v26; // ecx@53
  int v27; // eax@53
  int v28; // ecx@57
  LongHashIter<CWeenieObject> weenIter; // [sp+10h] [bp-14h]@1

  v1 = this;
  v2 = (HashBase<unsigned long> *)&this->object_table.vfptr;
  v3 = 0;
  weenIter.myHash_ = (HashBase<unsigned long> *)&this->object_table.vfptr;
  weenIter.lastThisChain_ = 0;
  weenIter.curBucket_ = 0;
  if ( this != (CObjectMaint *)-132 )
  {
    v4 = *this->object_table.buckets;
    weenIter.fEnd_ = 0;
    weenIter.curPtr_ = v4;
    if ( v4 )
      goto LABEL_5;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&weenIter.myHash_);
    if ( !weenIter.fEnd_ )
    {
      while ( 1 )
      {
        v4 = weenIter.curPtr_;
        v3 = weenIter.curBucket_;
        v2 = weenIter.myHash_;
        if ( !weenIter.curPtr_ )
          break;
LABEL_5:
        weenIter.curPtr_ = v4->hash_next;
        if ( !weenIter.curPtr_ )
          break;
LABEL_12:
        CPhysicsObj::exit_world((CPhysicsObj *)v4);
        CPhysicsObj::leave_world((CPhysicsObj *)v4);
        v6 = v4->id;
        v7 = (int)&v1->object_table.buckets[v1->object_table.table_mask & (v6 ^ (v4->id >> v1->object_table.key_shift))];
        v8 = *(_DWORD *)v7;
        if ( *(_DWORD *)v7 )
        {
          if ( *(_DWORD *)(v8 + 8) == v6 )
          {
            *(_DWORD *)v7 = *(_DWORD *)(v8 + 4);
          }
          else if ( *(_DWORD *)(v8 + 4) )
          {
            while ( 1 )
            {
              v9 = *(_DWORD *)(v8 + 4);
              if ( *(_DWORD *)(v9 + 8) == v6 )
                break;
              v8 = *(_DWORD *)(v8 + 4);
              if ( !*(_DWORD *)(v9 + 4) )
                goto LABEL_20;
            }
            *(_DWORD *)(v8 + 4) = *(_DWORD *)(*(_DWORD *)(v8 + 4) + 4);
          }
        }
LABEL_20:
        v10 = v4->id;
        v11 = (int)&v1->null_object_table.buckets[v1->null_object_table.table_mask & (v10 ^ (v4->id >> v1->null_object_table.key_shift))];
        v12 = *(_DWORD *)v11;
        if ( *(_DWORD *)v11 )
        {
          if ( *(_DWORD *)(v12 + 8) == v10 )
          {
            *(_DWORD *)v11 = *(_DWORD *)(v12 + 4);
          }
          else if ( *(_DWORD *)(v12 + 4) )
          {
            while ( 1 )
            {
              v13 = *(_DWORD *)(v12 + 4);
              if ( *(_DWORD *)(v13 + 8) == v10 )
                break;
              v12 = *(_DWORD *)(v12 + 4);
              if ( !*(_DWORD *)(v13 + 4) )
                goto LABEL_28;
            }
            *(_DWORD *)(v12 + 4) = *(_DWORD *)(*(_DWORD *)(v12 + 4) + 4);
          }
        }
LABEL_28:
        v14 = v4->id % v1->destruction_object_table.m_intrusiveTable.m_numBuckets;
        v15 = v1->destruction_object_table.m_intrusiveTable.m_buckets;
        v16 = v15[v14];
        v17 = (int)&v15[v14];
        v18 = v15[v14];
        if ( v18 )
        {
          while ( v18->m_hashKey != v4->id )
          {
            v18 = v18->m_hashNext;
            if ( !v18 )
              goto LABEL_39;
          }
          if ( v18 )
          {
            if ( v16 == v18 )
              goto LABEL_69;
            do
            {
              v19 = v16;
              v16 = v16->m_hashNext;
            }
            while ( v16 != v18 );
            if ( v19 )
              v19->m_hashNext = v16->m_hashNext;
            else
LABEL_69:
              *(_DWORD *)v17 = v16->m_hashNext;
            --v1->destruction_object_table.m_intrusiveTable.m_numElements;
            operator delete(v18);
          }
        }
LABEL_39:
        CPhysicsObj::unset_parent((CPhysicsObj *)v4);
        CPhysicsObj::unparent_children((CPhysicsObj *)v4);
        v4->vfptr->__vecDelDtor(v4, 1u);
        if ( weenIter.fEnd_ )
          goto LABEL_40;
      }
      v5 = v2->table_size;
      while ( 1 )
      {
        ++v3;
        if ( v3 >= v5 )
          break;
        weenIter.curPtr_ = v2->buckets[v3];
        if ( weenIter.curPtr_ )
          goto LABEL_11;
      }
      weenIter.fEnd_ = 1;
LABEL_11:
      weenIter.curBucket_ = v3;
      goto LABEL_12;
    }
  }
LABEL_40:
  weenIter.myHash_ = (HashBase<unsigned long> *)&v1->weenie_object_table.vfptr;
  weenIter.lastThisChain_ = 0;
  weenIter.curBucket_ = 0;
  if ( v1 == (CObjectMaint *)-180 )
  {
    weenIter.fEnd_ = 1;
    v20 = 0;
  }
  else
  {
    v20 = *v1->weenie_object_table.buckets;
    weenIter.fEnd_ = 0;
    weenIter.curPtr_ = v20;
    if ( v20 )
      goto LABEL_45;
    HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&weenIter.myHash_);
    v20 = weenIter.curPtr_;
  }
  if ( v20 )
  {
    while ( 1 )
    {
LABEL_45:
      v21 = v20->id;
      v22 = (int)&v1->weenie_object_table.buckets[v1->weenie_object_table.table_mask & (v21 ^ (v20->id >> v1->weenie_object_table.key_shift))];
      v23 = *(_DWORD *)v22;
      if ( *(_DWORD *)v22 )
      {
        if ( *(_DWORD *)(v23 + 8) == v21 )
        {
          *(_DWORD *)v22 = *(_DWORD *)(v23 + 4);
        }
        else if ( *(_DWORD *)(v23 + 4) )
        {
          while ( 1 )
          {
            v24 = *(_DWORD *)(v23 + 4);
            if ( *(_DWORD *)(v24 + 8) == v21 )
              break;
            v23 = *(_DWORD *)(v23 + 4);
            if ( !*(_DWORD *)(v24 + 4) )
              goto LABEL_53;
          }
          *(_DWORD *)(v23 + 4) = *(_DWORD *)(*(_DWORD *)(v23 + 4) + 4);
        }
      }
LABEL_53:
      v25 = v20->id;
      v26 = (int)&v1->null_weenie_object_table.buckets[v1->null_weenie_object_table.table_mask & (v25 ^ (v20->id >> v1->null_weenie_object_table.key_shift))];
      v27 = *(_DWORD *)v26;
      if ( *(_DWORD *)v26 )
      {
        if ( *(_DWORD *)(v27 + 8) == v25 )
        {
          *(_DWORD *)v26 = *(_DWORD *)(v27 + 4);
        }
        else if ( *(_DWORD *)(v27 + 4) )
        {
          while ( 1 )
          {
            v28 = *(_DWORD *)(v27 + 4);
            if ( *(_DWORD *)(v28 + 8) == v25 )
              break;
            v27 = *(_DWORD *)(v27 + 4);
            if ( !*(_DWORD *)(v28 + 4) )
              goto LABEL_61;
          }
          *(_DWORD *)(v27 + 4) = *(_DWORD *)(*(_DWORD *)(v27 + 4) + 4);
        }
      }
LABEL_61:
      v20->vfptr->__vecDelDtor(v20, 1u);
      weenIter.lastThisChain_ = 0;
      weenIter.curBucket_ = 0;
      if ( !(_DWORD)weenIter.myHash_ )
        break;
      v20 = *weenIter.myHash_->buckets;
      weenIter.fEnd_ = 0;
      weenIter.curPtr_ = v20;
      if ( !v20 )
      {
        HashBaseIter<unsigned long>::Next((HashBaseIter<unsigned long> *)&weenIter.myHash_);
        v20 = weenIter.curPtr_;
LABEL_65:
        if ( !v20 )
          goto LABEL_66;
      }
    }
    weenIter.fEnd_ = 1;
    v20 = 0;
    goto LABEL_65;
  }
LABEL_66:
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->object_table);
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->null_object_table);
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->weenie_object_table);
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->null_weenie_object_table);
  IntrusiveHashTable<unsigned long,CLostCell *,0>::delete_contents(&v1->lost_cell_table);
  LongNIValHash<unsigned long>::destroy_contents((LongHash<MotionData> *)&v1->object_inventory_table);
}

//----- (00508F70) --------------------------------------------------------  // acclient.c:310650
void __thiscall CObjectMaint::AddObjectToBeDestroyed(CObjectMaint *this, unsigned int object_id)
{
  unsigned int v2; // edi@1
  CObjectMaint *v3; // esi@1
  HashSetData<IDClass<_tagDataID,32,0> > *v4; // eax@1
  long double destruction_time; // [sp+8h] [bp-8h]@1

  v2 = object_id;
  v3 = this;
  LODWORD(destruction_time) = object_id;
  v4 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->destruction_object_table.m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)&destruction_time);
  if ( v4 )
    operator delete(v4);
  destruction_time = COERCE_DOUBLE(Timer::cur_time.Cmd) + 25.0;
  HashTable<unsigned long,double,0>::add(&v3->destruction_object_table, &object_id, &destruction_time);
  AC1Legacy::PQueueArray<double>::Insert(
    (PQueueArray<double,void *> *)&v3->object_destruction_queue,
    destruction_time,
    (void *)v2);
}

//----- (00508FE0) --------------------------------------------------------  // acclient.c:310674
HashBaseData<unsigned long> *__thiscall CObjectMaint::GetNullObject(CObjectMaint *this, unsigned int object_id, int create_new_object)
{
  CObjectMaint *v3; // edi@1
  HashBaseData<unsigned long> *result; // eax@1
  int v5; // eax@7
  ICMDCommandEnum v6; // edx@7
  int v7; // esi@7
  int v8; // eax@7

  v3 = this;
  result = this->null_object_table.buckets[this->null_object_table.table_mask & (object_id ^ (object_id >> this->null_object_table.key_shift))];
  if ( result )
  {
    while ( object_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  if ( !result )
  {
    if ( create_new_object )
    {
      v5 = CPhysicsObj::makeNullObject(object_id, 1);
      v6 = (signed int)Timer::cur_time.Cmd;
      v7 = v5;
      *(_DWORD *)(v5 + 220) = Timer::cur_time.Param;
      *(_DWORD *)(v5 + 216) = v6;
      v8 = v3->null_object_table.table_mask & (*(_DWORD *)(v5 + 8) ^ (*(_DWORD *)(v5 + 8) >> v3->null_object_table.key_shift));
      *(_DWORD *)(v7 + 4) = v3->null_object_table.buckets[v8];
      v3->null_object_table.buckets[v8] = (HashBaseData<unsigned long> *)v7;
      CObjectMaint::AddObjectToBeDestroyed(v3, object_id);
      result = (HashBaseData<unsigned long> *)v7;
    }
  }
  return result;
}

//----- (00509090) --------------------------------------------------------  // acclient.c:310719
HashBaseData<unsigned long> *__thiscall CObjectMaint::GetNullWeenieObject(CObjectMaint *this, unsigned int object_id, int create_new_object)
{
  CObjectMaint *v3; // edi@1
  HashBaseData<unsigned long> *result; // eax@1
  int v5; // eax@7
  ICMDCommandEnum v6; // edx@7
  int v7; // esi@7
  int v8; // eax@7

  v3 = this;
  result = this->null_weenie_object_table.buckets[this->null_weenie_object_table.table_mask & (object_id ^ (object_id >> this->null_weenie_object_table.key_shift))];
  if ( result )
  {
    while ( object_id != result->id )
    {
      result = result->hash_next;
      if ( !result )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = 0;
  }
  if ( !result )
  {
    if ( create_new_object )
    {
      v5 = CFactory::MakeCWeenieObject(object_id);
      v6 = (signed int)Timer::cur_time.Cmd;
      v7 = v5;
      *(_DWORD *)(v5 + 28) = Timer::cur_time.Param;
      *(_DWORD *)(v5 + 24) = v6;
      v8 = v3->null_weenie_object_table.table_mask & (*(_DWORD *)(v5 + 8) ^ (*(_DWORD *)(v5 + 8) >> v3->null_weenie_object_table.key_shift));
      *(_DWORD *)(v7 + 4) = v3->null_weenie_object_table.buckets[v8];
      v3->null_weenie_object_table.buckets[v8] = (HashBaseData<unsigned long> *)v7;
      CObjectMaint::AddObjectToBeDestroyed(v3, object_id);
      result = (HashBaseData<unsigned long> *)v7;
    }
  }
  return result;
}

//----- (00509140) --------------------------------------------------------  // acclient.c:310764
void __thiscall CObjectMaint::~CObjectMaint(CObjectMaint *this)
{
  CObjectMaint *v1; // esi@1
  void *v2; // ST04_4@1
  int v3; // eax@1
  void *v4; // eax@3
  void *v5; // eax@5
  bool v6; // zf@7
  void *v7; // eax@15
  NoticeHandler *v8; // [sp+Ch] [bp-4h]@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&CObjectMaint::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  v8 = (NoticeHandler *)&this->vfptr;
  CObjectMaint::s_pcInstance = 0;
  CObjectMaint::DestroyObjects(this);
  v2 = v1->object_destruction_queue.A;
  v1->object_destruction_queue.vfptr = (AC1Legacy::PQueueArray<double>Vtbl *)AC1Legacy::PQueueArray<double>::vftable;
  operator delete[](v2);
  v3 = v1->object_inventory_table.fPlacementNew_;
  v1->object_inventory_table.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( !v3 )
    operator delete[](v1->object_inventory_table.buckets);
  v1->destruction_object_table.vfptr = (HashTable<unsigned long,double,0>Vtbl *)&HashTable<unsigned long,double,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->destruction_object_table.m_intrusiveTable);
  v4 = v1->destruction_object_table.m_intrusiveTable.m_buckets;
  v1->destruction_object_table.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable;
  if ( v4 != v1->destruction_object_table.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->destruction_object_table.m_intrusiveTable.m_buckets = 0;
  v1->destruction_object_table.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->destruction_object_table.m_intrusiveTable.m_numBuckets = 0;
  v1->destruction_object_table.m_intrusiveTable.m_numElements = 0;
  v1->visible_object_table.vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->visible_object_table.m_intrusiveTable);
  v5 = v1->visible_object_table.m_intrusiveTable.m_buckets;
  v1->visible_object_table.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
  if ( v5 != v1->visible_object_table.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v5);
  v1->visible_object_table.m_intrusiveTable.m_buckets = 0;
  v1->visible_object_table.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->visible_object_table.m_intrusiveTable.m_numBuckets = 0;
  v1->visible_object_table.m_intrusiveTable.m_numElements = 0;
  v6 = v1->null_weenie_object_table.fPlacementNew_ == 0;
  v1->null_weenie_object_table.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( v6 )
    operator delete[](v1->null_weenie_object_table.buckets);
  v6 = v1->weenie_object_table.fPlacementNew_ == 0;
  v1->weenie_object_table.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( v6 )
    operator delete[](v1->weenie_object_table.buckets);
  v6 = v1->null_object_table.fPlacementNew_ == 0;
  v1->null_object_table.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( v6 )
    operator delete[](v1->null_object_table.buckets);
  v6 = v1->object_table.fPlacementNew_ == 0;
  v1->object_table.vfptr = (HashBase<unsigned long>Vtbl *)LongHash<CWeenieObject>::vftable;
  if ( v6 )
    operator delete[](v1->object_table.buckets);
  v7 = v1->lost_cell_table.m_buckets;
  v1->lost_cell_table.vfptr = (IntrusiveHashTable<unsigned long,CLostCell *,0>Vtbl *)IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable;
  if ( v7 != v1->lost_cell_table.m_aInplaceBuckets )
    operator delete[](v7);
  v1->lost_cell_table.m_buckets = 0;
  v1->lost_cell_table.m_firstInterestingBucket = 0;
  v1->lost_cell_table.m_numBuckets = 0;
  v1->lost_cell_table.m_numElements = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  NoticeHandler::~NoticeHandler(v8);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 7C66A4: using guessed type int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char);
// 7C66A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable[4])(void *, char);
// 7C66AC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable[3])(void *, char);
// 7C66B0: using guessed type int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char);
// 7C66B4: using guessed type int (__thiscall *HashTable<unsigned long,double,0>::vftable)(void *, char);
// 7C66B8: using guessed type __int32 (__stdcall *CObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);

//----- (005092D0) --------------------------------------------------------  // acclient.c:310847
void __thiscall CObjectMaint::QueueBlobForObject(CObjectMaint *this, unsigned int object_id, NetBlob *blob)
{
  CObjectMaint *v3; // esi@1
  HashBaseData<unsigned long> *v4; // edi@1

  v3 = this;
  v4 = CObjectMaint::GetObjectA(this, object_id);
  if ( !v4 )
  {
    v4 = CObjectMaint::GetNullObject(v3, object_id, 1);
    CObjectMaint::AddObjectToBeDestroyed(v3, object_id);
  }
  CPhysicsObj::queue_netblob((CPhysicsObj *)v4, blob);
}

//----- (00509310) --------------------------------------------------------  // acclient.c:310863
void __thiscall CObjectMaint::QueueBlobForWeenieObject(CObjectMaint *this, unsigned int object_id, unsigned int stamp, NetBlob *blob)
{
  CObjectMaint *v4; // esi@1
  HashBaseData<unsigned long> *v5; // eax@1

  v4 = this;
  v5 = CObjectMaint::GetNullWeenieObject(this, object_id, 1);
  CWeenieObject::queue_netblob((CWeenieObject *)v5, stamp, blob);
  CObjectMaint::AddObjectToBeDestroyed(v4, object_id);
}

//----- (00509340) --------------------------------------------------------  // acclient.c:310875
void __thiscall CObjectMaint::QueueBlobForWeenieObject(CObjectMaint *this, unsigned int object_id, NetBlob *blob)
{
  CObjectMaint *v3; // esi@1
  HashBaseData<unsigned long> *v4; // eax@1

  v3 = this;
  v4 = CObjectMaint::GetNullWeenieObject(this, object_id, 1);
  CWeenieObject::queue_netblob((CWeenieObject *)v4, blob);
  CObjectMaint::AddObjectToBeDestroyed(v3, object_id);
}

//----- (00509370) --------------------------------------------------------  // acclient.c:310887
void __thiscall CObjectMaint::SetChildren(CObjectMaint *this, CPhysicsObj *obj, PhysicsDesc *desc)
{
  CObjectMaint *v3; // edi@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@2
  HashBaseData<unsigned long> *v6; // ecx@2
  HashBaseData<unsigned long> *v7; // ebp@6
  unsigned int v8; // eax@7
  unsigned int v9; // eax@8

  v3 = this;
  CPhysicsObj::unparent_children(obj);
  v4 = 0;
  if ( UIFlow::GetPersistantData(desc) )
  {
    do
    {
      v5 = PhysicsDesc::get_child_id(desc, v4);
      v6 = v3->object_table.buckets[v3->object_table.table_mask & (v5 ^ (v5 >> v3->object_table.key_shift))];
      if ( v6 )
      {
        while ( v5 != v6->id )
        {
          v6 = v6->hash_next;
          if ( !v6 )
            goto LABEL_5;
        }
      }
      else
      {
LABEL_5:
        v6 = 0;
      }
      v7 = v6;
      if ( !v6 )
      {
        v8 = PhysicsDesc::get_child_id(desc, v4);
        v7 = CObjectMaint::GetNullObject(v3, v8, 1);
      }
      v9 = PhysicsDesc::get_child_location_id(desc, v4);
      CPhysicsObj::set_parent((CPhysicsObj *)v7, obj, v9);
      ++v4;
    }
    while ( v4 < UIFlow::GetPersistantData(desc) );
  }
}

//----- (00509410) --------------------------------------------------------  // acclient.c:310935
CObjectMaint *__thiscall CObjectMaint::scalar_deleting_destructor(CObjectMaint *this, unsigned int a2)
{
  CObjectMaint *v2; // esi@1

  v2 = this;
  CObjectMaint::~CObjectMaint(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006FB070) --------------------------------------------------------  // acclient.c:783554
void sub_6FB070()
{
  flt_841AE8 = 1000.0 + 1.0;
}

//----- (006FB090) --------------------------------------------------------  // acclient.c:783560
void sub_6FB090()
{
  flt_841AEC = 24.0 * 8.0;
}

//----- (006FB0B0) --------------------------------------------------------  // acclient.c:783566
void sub_6FB0B0()
{
  flt_841AF0 = 24.0 * 0.5;
}

//----- (006FB0D0) --------------------------------------------------------  // acclient.c:783572
void sub_6FB0D0()
{
  DEFAULT_VIEW_RADIUS_92 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FB0F0) --------------------------------------------------------  // acclient.c:783578
void _E99_10()
{
  MIN_QUANTUM_92 = 1.0 / 30.0;
}

//----- (006FB110) --------------------------------------------------------  // acclient.c:783584
void _E101_6()
{
  MAX_QUANTUM_92 = 1.0 / 5.0;
}

//----- (006FB130) --------------------------------------------------------  // acclient.c:783590
int _E107_9()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_0;
  INITIAL_MAX_DATA_RATE_64 = LOWEST_DATA_RATE_0;
  return result;
}

//----- (006FB140) --------------------------------------------------------  // acclient.c:783600
void _E109_58()
{
  PixelFormatDesc::PixelFormatDesc(&stru_841B14, PFID_A8R8G8B8);
}

//----- (006FB150) --------------------------------------------------------  // acclient.c:783606
int sub_6FB150()
{
  return atexit(nullsub_1073);
}

//----- (007668C0) --------------------------------------------------------  // acclient.c:893291
void __cdecl _E113_61()
{
  operator delete[](object_list.data);
  object_list.data = 0;
}

