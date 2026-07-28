/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CWeenieObj
   Object     : PORTAL\cobject\CWeenieObj.obj
   Functions  : 6
   Addresses  : 00509430 - 006FB160 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00509430) --------------------------------------------------------  // acclient.c:310947
void __thiscall CWeenieObject::queue_netblob(CWeenieObject *this, unsigned int inStamp, NetBlob *blob)
{
  int fBlobWasRejected; // [sp+0h] [bp-4h]@1

  fBlobWasRejected = 0;
  TSRecv::AddEntry(&this->blobOrdering, inStamp, (ReferenceCountTemplate<1048576,0> *)&blob->vfptr, &fBlobWasRejected);
}

//----- (00509460) --------------------------------------------------------  // acclient.c:310956
int __thiscall CWeenieObject::fIsNextBlob(CWeenieObject *this, unsigned int inStamp, NetBlob *pBlob, NetBlob **ppBlobIndicated)
{
  return TSRecv::AddAndCheck(
           &this->blobOrdering,
           inStamp,
           (ReferenceCountTemplate<1048576,0> *)&pBlob->vfptr,
           (unsigned int *)&ppBlobIndicated,
           (ReferenceCountTemplate<1048576,0> **)ppBlobIndicated);
}

//----- (00509480) --------------------------------------------------------  // acclient.c:310967
void __thiscall CWeenieObject::queue_netblob(CWeenieObject *this, NetBlob *blob)
{
  CWeenieObject *v2; // esi@1
  void *v3; // eax@2
  NIList<NetBlob *> *v4; // esi@6
  void *v5; // eax@6
  NIListElement<NetBlob *> *v6; // ecx@9

  v2 = this;
  if ( !this->netblob_list )
  {
    v3 = operator new(8u);
    if ( v3 )
    {
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
    }
    else
    {
      v3 = 0;
    }
    v2->netblob_list = (NIList<NetBlob *> *)v3;
  }
  InterlockedIncrement((volatile LONG *)&blob->m_cRef);
  v4 = v2->netblob_list;
  v5 = operator new(8u);
  if ( v5 )
  {
    *(_DWORD *)v5 = blob;
    *((_DWORD *)v5 + 1) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = v4->tail_;
  if ( v6 )
  {
    v6->next_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = v4->tail_->next_;
  }
  else
  {
    v4->head_ = (NIListElement<NetBlob *> *)v5;
    v4->tail_ = (NIListElement<NetBlob *> *)v5;
  }
}

//----- (00509500) --------------------------------------------------------  // acclient.c:311016
void __thiscall CWeenieObject::process_netblobs(CWeenieObject *this)
{
  UIQueueManager *v1; // ebx@1
  CWeenieObject *v2; // ebp@1
  ReferenceCountTemplate<1048576,0> *v3; // esi@2
  NIList<NetBlob *> *v4; // eax@5
  NIList<NetBlob *> *v5; // ecx@7
  NIListElement<NetBlob *> *v6; // eax@7
  NetBlob *v7; // esi@8
  NIListElement<NetBlob *> *v8; // edx@9
  void *v9; // esi@16
  ReferenceCountTemplate<1048576,0> *ppObjOut; // [sp+8h] [bp-8h]@2
  unsigned int pstampOut; // [sp+Ch] [bp-4h]@2

  v1 = IQueuedUIEventDeliverer::s_pInstance;
  v2 = this;
  if ( IQueuedUIEventDeliverer::s_pInstance )
  {
    while ( 1 )
    {
      TSRecv::GetNextReadyEntry(&v2->blobOrdering, &pstampOut, &ppObjOut);
      v3 = ppObjOut;
      if ( !ppObjOut )
        break;
      ((void (__thiscall *)(UIQueueManager *, ReferenceCountTemplate<1048576,0> *))v1->vfptr[1].QueryInterface)(
        v1,
        ppObjOut);
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
    v4 = v2->netblob_list;
    if ( v4 )
    {
      if ( v4->head_ )
      {
        do
        {
          v5 = v2->netblob_list;
          v6 = v5->head_;
          if ( v5->head_ )
          {
            v8 = v6->next_;
            v5->head_ = v8;
            if ( !v8 )
              v5->tail_ = 0;
            v7 = v6->data_;
            operator delete(v6);
          }
          else
          {
            v7 = 0;
          }
          ((void (__thiscall *)(UIQueueManager *, _DWORD))v1->vfptr[1].AddRef)(v1, v7);
          if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
            v7->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, 1u);
        }
        while ( v2->netblob_list->head_ );
      }
      v9 = v2->netblob_list;
      if ( v9 )
      {
        NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v2->netblob_list);
        operator delete(v9);
      }
      v2->netblob_list = 0;
    }
  }
}

//----- (005095E0) --------------------------------------------------------  // acclient.c:311086
void __thiscall CWeenieObject::ObjectBeingDeleted(CWeenieObject *this)
{
  CWeenieObject *v1; // edi@1
  NIList<NetBlob *> *v2; // eax@1
  NIList<NetBlob *> *v3; // ecx@3
  NIListElement<NetBlob *> *v4; // eax@3
  NetBlob *v5; // esi@4
  NIListElement<NetBlob *> *v6; // edx@5
  void *v7; // esi@12

  v1 = this;
  v2 = this->netblob_list;
  if ( v2 )
  {
    if ( v2->head_ )
    {
      do
      {
        v3 = v1->netblob_list;
        v4 = v3->head_;
        if ( v3->head_ )
        {
          v6 = v4->next_;
          v3->head_ = v6;
          if ( !v6 )
            v3->tail_ = 0;
          v5 = v4->data_;
          operator delete(v4);
        }
        else
        {
          v5 = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
          v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
      }
      while ( v1->netblob_list->head_ );
    }
    v7 = v1->netblob_list;
    if ( v7 )
    {
      NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v1->netblob_list);
      operator delete(v7);
    }
    v1->netblob_list = 0;
  }
  ECM_Physics::SendNotice_BeingDeleted(v1);
}

//----- (006FB160) --------------------------------------------------------  // acclient.c:783612
int sub_6FB160()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_1;
  INITIAL_MAX_DATA_RATE_65 = LOWEST_DATA_RATE_1;
  return result;
}

