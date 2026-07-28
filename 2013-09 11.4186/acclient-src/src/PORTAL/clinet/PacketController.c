/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PacketController
   Object     : PORTAL\clinet\PacketController.obj
   Functions  : 34
   Addresses  : 00540AC0 - 007055A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00540AC0) --------------------------------------------------------  // acclient.c:368116
PacketController *__cdecl PacketController::Instance()
{
  return PacketController::pcontrol_;
}
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00540AD0) --------------------------------------------------------  // acclient.c:368123
int __thiscall PacketController::AddReceiveQueue(PacketController *this, unsigned __int16 queueID, NIList<NetBlob *> *pqueue)
{
  this->netQueues_[queueID] = pqueue;
  return 1;
}

//----- (00540AF0) --------------------------------------------------------  // acclient.c:368130
void __thiscall PacketController::EnqueueRecip(PacketController *this, RecipientData *recip)
{
  if ( !recip->onQueue_ )
  {
    recip->onQueue_ = 1;
    recip->next_ = this->haveNaks_;
    this->haveNaks_ = recip;
  }
}

//----- (00540B20) --------------------------------------------------------  // acclient.c:368141
char __thiscall PacketController::SendBlob(PacketController *this, NetBlob *blob, unsigned __int16 recip)
{
  PacketController *v3; // esi@1
  char v4; // bl@1
  RecipientData *v5; // ecx@1

  v3 = this;
  v4 = 0;
  ((void (*)(void))this->m_pSendBlobCallsCounter->vfptr[3].__vecDelDtor)();
  v5 = v3->recipients_[recip];
  if ( v5 )
  {
    v4 = 1;
    RecipientData::EnqueueBlob(v5, blob);
  }
  return v4;
}

//----- (00540B50) --------------------------------------------------------  // acclient.c:368160
RecipientData *__thiscall PacketController::GetRecipient(PacketController *this, unsigned __int16 recID)
{
  return this->recipients_[recID];
}

//----- (00540B60) --------------------------------------------------------  // acclient.c:368166
PQueueArray<double,void *> *__thiscall PQueueArray<double,void *>::scalar_deleting_destructor(PQueueArray<double,void *> *this, unsigned int a2)
{
  PQueueArray<double,void *> *v2; // esi@1
  PQueueArray<double,void *>::PQueueNode *v3; // ST00_4@1

  v2 = this;
  v3 = this->A;
  this->vfptr = (PQueueArray<double,void *>Vtbl *)&PQueueArray<double,void *>::vftable;
  operator delete[](v3);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9E18: using guessed type int (__thiscall *PQueueArray<double,void *>::vftable)(void *, char);

//----- (00540B90) --------------------------------------------------------  // acclient.c:368182
void __thiscall PQueueArray<double,void *>::_ExpandNodes(PQueueArray<double,void *> *this)
{
  PQueueArray<double,void *> *v1; // ebx@1
  void *v2; // ebp@1
  void *v3; // ST00_4@1

  v1 = this;
  v2 = operator new[](32 * this->allocatedNodes);
  qmemcpy(v2, v1->A, 16 * v1->allocatedNodes);
  v3 = v1->A;
  v1->allocatedNodes *= 2;
  operator delete[](v3);
  v1->A = (PQueueArray<double,void *>::PQueueNode *)v2;
}

//----- (00540BE0) --------------------------------------------------------  // acclient.c:368198
void __thiscall PQueueArray<double,void *>::_Heapify(PQueueArray<double,void *> *this, int root)
{
  int v2; // edx@1
  PQueueArray<double,void *>::PQueueNode *v3; // edi@1
  int v4; // esi@2
  int v5; // ebx@2
  int v6; // eax@9
  int v7; // edx@9
  __int64 temp; // ST18_8@9
  int temp_8; // ST20_4@9
  int temp_12; // ST24_4@9
  int v11; // edx@9
  int v12; // ecx@9
  int v13; // [sp+10h] [bp-18h]@2
  PQueueArray<double,void *> *v14; // [sp+14h] [bp-14h]@1

  v2 = root;
  v14 = this;
  v3 = this->A - 1;
  while ( 1 )
  {
    v4 = 2 * v2;
    v5 = 2 * v2 + 1;
    v13 = this->curNumNodes;
    if ( 2 * v2 > v13 || v3[2 * v2].key >= v3[v2].key )
      v4 = v2;
    if ( v5 <= v13 && v3[v5].key < v3[v4].key )
      v4 = 2 * v2 + 1;
    if ( v4 == v2 )
      break;
    v7 = (int)&v3[v2];
    v6 = v7;
    temp = *(_QWORD *)v7;
    temp_8 = *(_DWORD *)(v7 + 8);
    temp_12 = *(_DWORD *)(v7 + 12);
    v11 = (int)&v3[v4];
    v12 = (int)&v3[v4];
    *(_DWORD *)v6 = *(_DWORD *)v12;
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(v12 + 4);
    *(_DWORD *)(v6 + 8) = *(_DWORD *)(v12 + 8);
    *(_DWORD *)(v6 + 12) = *(_DWORD *)(v12 + 12);
    *(_QWORD *)v11 = temp;
    *(_DWORD *)(v11 + 8) = temp_8;
    *(_DWORD *)(v11 + 12) = temp_12;
    this = v14;
    v2 = v4;
  }
}

//----- (00540CC0) --------------------------------------------------------  // acclient.c:368248
void __thiscall PacketController::~PacketController(PacketController *this)
{
  PacketController *v1; // ebx@1
  signed int v2; // esi@1
  RecipientData **v3; // eax@2
  void *v4; // edi@2
  PerfMonCounter<unsigned __int64> *v5; // esi@5
  void *v6; // ST00_4@8

  v1 = this;
  this->vfptr = (PacketControllerVtbl *)&PacketController::vftable;
  v2 = 0;
  do
  {
    v3 = v1->recipients_;
    v4 = v3[v2];
    if ( v4 )
    {
      RecipientData::~RecipientData(v3[v2]);
      operator delete(v4);
    }
    ++v2;
  }
  while ( v2 < 256 );
  operator delete[](v1->recipients_);
  PacketController::pcontrol_ = 0;
  v5 = v1->m_pSendBlobCallsCounter;
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    ((void (__thiscall *)(_DWORD))v5->vfptr->__vecDelDtor)(v5);
  v1->m_pSendBlobCallsCounter = 0;
  v6 = v1->FlowControlTimers.A;
  v1->FlowControlTimers.vfptr = (PQueueArray<double,void *>Vtbl *)&PQueueArray<double,void *>::vftable;
  operator delete[](v6);
}
// 7C9E18: using guessed type int (__thiscall *PQueueArray<double,void *>::vftable)(void *, char);
// 7C9E1C: using guessed type unsigned __int64 (__thiscall *PacketController::vftable)(PacketController *__hidden this);
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00540D50) --------------------------------------------------------  // acclient.c:368287
int __thiscall PacketController::GetNonEphemeralID(PacketController *this)
{
  PacketController *v1; // esi@1
  int result; // eax@2
  int v3; // edi@3
  int v4; // edx@3

  v1 = this;
  if ( PacketController::pcontrol_ )
  {
    v3 = LODWORD(this->m_curNonEphemeralID);
    LODWORD(this->m_curNonEphemeralID) = NetBlobIDUtils::NextNonEphemeralSequenceID(this->m_curNonEphemeralID);
    HIDWORD(v1->m_curNonEphemeralID) = v4;
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00540D90) --------------------------------------------------------  // acclient.c:368311
char __thiscall PacketController::EnqueueOptionalHeader(PacketController *this, unsigned __int16 recID, COptionalHeader *pHdr)
{
  int v3; // edx@1
  char result; // al@1

  v3 = recID;
  result = 0;
  if ( PacketController::pcontrol_->recipients_[v3] )
  {
    FlowQueue::EnqueueOptionalHeader((FlowQueue *)&this->recipients_[v3]->flowQueue_.vfptr, pHdr);
    result = 1;
  }
  return result;
}
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00540DD0) --------------------------------------------------------  // acclient.c:368328
void __thiscall AC1Legacy::PQueueArray<double>::Insert(PQueueArray<double,void *> *this, long double key, void *data)
{
  PQueueArray<double,void *> *v3; // esi@1
  int v4; // edi@3
  signed int v5; // edx@3
  bool v6; // sf@3
  signed int v7; // esi@4
  int v8; // ecx@4
  bool v9; // c0@4
  int v10; // ecx@4
  int v11; // edx@5
  int v12; // eax@6

  v3 = this;
  if ( this->curNumNodes == this->allocatedNodes )
    PQueueArray<double,void *>::_ExpandNodes(this);
  v4 = (int)&v3->A[-1];
  v5 = v3->curNumNodes + 1;
  v6 = v3->curNumNodes < 0;
  v3->curNumNodes = v5;
  if ( !((unsigned __int8)(v6 ^ __OFSUB__(v5, 1)) | (v5 == 1)) )
  {
    do
    {
      v7 = v5 >> 1;
      v8 = 16 * (v5 >> 1);
      v9 = key < *(double *)(v8 + v4);
      v10 = v4 + v8;
      if ( !v9 )
        break;
      v11 = v4 + 16 * v5;
      *(_DWORD *)v11 = *(_DWORD *)v10;
      *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
      *(_DWORD *)(v11 + 8) = *(_DWORD *)(v10 + 8);
      *(_DWORD *)(v11 + 12) = *(_DWORD *)(v10 + 12);
      v5 = v7;
    }
    while ( v7 > 1 );
  }
  v12 = 16 * v5 + v4;
  *(long double *)v12 = key;
  *(_DWORD *)(v12 + 8) = data;
}

//----- (00540E50) --------------------------------------------------------  // acclient.c:368373
char __thiscall PQueueArray<double,void *>::RemoveMin(PQueueArray<double,void *> *this, long double *key, void **data)
{
  PQueueArray<double,void *>::PQueueNode *v3; // eax@2
  int v4; // eax@3
  PQueueArray<double,void *>::PQueueNode *v5; // edx@4
  int v6; // eax@4
  int v7; // eax@4
  char result; // al@4

  if ( this->curNumNodes > 0 && (v3 = this->A) != 0 )
  {
    *(_QWORD *)key = *(_QWORD *)&v3->key;
    *data = this->A->data;
    v4 = this->curNumNodes;
    if ( v4 <= 1 )
    {
      this->curNumNodes = 0;
      PQueueArray<double,void *>::_Heapify(this, 1);
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
      PQueueArray<double,void *>::_Heapify(this, 1);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00540ED0) --------------------------------------------------------  // acclient.c:368415
char __thiscall PQueueArray<double,void *>::RemoveByData(PQueueArray<double,void *> *this, void *const data)
{
  int v2; // ebp@1
  int v3; // eax@1
  PQueueArray<double,void *>::PQueueNode *v4; // edi@2
  int v5; // edx@2
  char result; // al@5
  int v7; // ebx@6
  int v8; // edx@6
  int v9; // edi@6
  int v10; // esi@7
  int v11; // ebx@8
  int v12; // edx@10
  int v13; // ebx@10
  int v14; // ebp@11
  int v15; // eax@11
  int v16; // eax@11

  v2 = this->curNumNodes;
  v3 = v2 - 1;
  if ( v2 - 1 < 0 )
  {
LABEL_5:
    result = 0;
  }
  else
  {
    v4 = this->A;
    v5 = (int)&v4[v3].data;
    while ( *(void *const *)v5 != data )
    {
      --v3;
      v5 -= 16;
      if ( v3 < 0 )
        goto LABEL_5;
    }
    v7 = v3 + 1;
    v8 = (v3 + 1) >> 1;
    v9 = (int)&v4[-1];
    if ( v8 <= 0 || (v10 = 16 * v8 + v9, *(double *)v10 <= *(double *)(16 * v2 + v9)) )
    {
      v14 = v9 + 16 * v2;
      v15 = v9 + 16 * v7;
      *(_DWORD *)v15 = *(_DWORD *)v14;
      *(_DWORD *)(v15 + 4) = *(_DWORD *)(v14 + 4);
      *(_DWORD *)(v15 + 8) = *(_DWORD *)(v14 + 8);
      *(_DWORD *)(v15 + 12) = *(_DWORD *)(v14 + 12);
      v16 = this->curNumNodes - 1;
      this->curNumNodes = v16;
      if ( v7 < v16 )
        PQueueArray<double,void *>::_Heapify(this, v7);
      result = 1;
    }
    else
    {
      do
      {
        v11 = v9 + 16 * v7;
        *(_DWORD *)v11 = *(_DWORD *)v10;
        *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(v10 + 8);
        *(_DWORD *)(v11 + 12) = *(_DWORD *)(v10 + 12);
        v7 = v8;
        v8 >>= 1;
        if ( v8 <= 0 )
          break;
        v10 = 16 * v8 + v9;
      }
      while ( *(double *)v10 > *(double *)(16 * this->curNumNodes + v9) );
      v12 = v9 + 16 * this->curNumNodes;
      v13 = v9 + 16 * v7;
      *(_DWORD *)v13 = *(_DWORD *)v12;
      *(_DWORD *)(v13 + 4) = *(_DWORD *)(v12 + 4);
      *(_DWORD *)(v13 + 8) = *(_DWORD *)(v12 + 8);
      *(_DWORD *)(v13 + 12) = *(_DWORD *)(v12 + 12);
      --this->curNumNodes;
      result = 1;
    }
  }
  return result;
}

//----- (00540FF0) --------------------------------------------------------  // acclient.c:368498
void __thiscall PacketController::CheckFlowControlTimers(PacketController *this)
{
  PacketController *v1; // ebx@1
  long double *v2; // eax@3
  RecipientData *v3; // esi@5
  RecipientData *recip; // [sp+10h] [bp-18h]@5
  int v5; // [sp+14h] [bp-14h]@7
  long double TriggerTime; // [sp+18h] [bp-10h]@4
  long double now; // [sp+20h] [bp-8h]@1

  v1 = this;
  now = *(double *)&Timer::cur_time;
  while ( v1->FlowControlTimers.curNumNodes > 0 )
  {
    v2 = &v1->FlowControlTimers.A->key;
    if ( !v2 )
      break;
    TriggerTime = *v2;
    if ( now < TriggerTime )
      break;
    PQueueArray<double,void *>::RemoveMin(&v1->FlowControlTimers, &TriggerTime, (void **)&recip);
    v3 = recip;
    if ( !recip->onQueue_ )
    {
      recip->onQueue_ = 1;
      v3->next_ = v1->haveNaks_;
      v1->haveNaks_ = v3;
    }
    v5 = 1 - (unsigned __int64)((now - TriggerTime) * -2.0);
    TriggerTime = (double)v5 * 0.5 + TriggerTime;
    AC1Legacy::PQueueArray<double>::Insert(&v1->FlowControlTimers, TriggerTime, v3);
  }
}

//----- (005410D0) --------------------------------------------------------  // acclient.c:368533
void __thiscall PacketController::UseTime(PacketController *this)
{
  PacketController *v1; // esi@1
  RecipientData *v2; // eax@2
  unsigned __int16 v3; // cx@3
  int v4; // eax@4

  v1 = this;
  PacketController::CheckFlowControlTimers(this);
  while ( 1 )
  {
    v2 = v1->haveNaks_;
    if ( !v2 )
      break;
    v3 = v2->recID_;
    v2->onQueue_ = 0;
    v1->haveNaks_ = v1->haveNaks_->next_;
    if ( !v3 )
      break;
    v4 = v3;
    if ( PacketController::pcontrol_->recipients_[v4] )
      RecipientData::UseTime(v1->recipients_[v4]);
  }
}
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00541130) --------------------------------------------------------  // acclient.c:368560
int __thiscall PacketController::AddRecipient(PacketController *this, unsigned __int16 id, sockaddr_in addr, int noflow, float lineNoise, unsigned int gid, int fIsAdminConnection)
{
  PacketController *v7; // edi@1
  int v8; // ecx@1
  int v9; // ebp@3
  int v10; // eax@3
  RecipientData *v11; // eax@6
  sockaddr_in v12; // ST0C_16@7
  RecipientData *v13; // eax@7
  AC1Legacy::PSRefBuffer<char> *v14; // esi@9
  int v15; // eax@12
  AC1Legacy::PSRefBuffer<char> *v16; // esi@13
  AC1Legacy::PStringBase<char> result; // [sp+24h] [bp-Ch]@1
  Logger::LogMacro v18; // [sp+28h] [bp-8h]@5

  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v7 = this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  NetUtils::GetIPString(&addr, &result, 0);
  v8 = (int)"TRUE";
  if ( !fIsAdminConnection )
    v8 = (int)"FALSE";
  v9 = noflow;
  v10 = (int)"TRUE";
  if ( !noflow )
    v10 = (int)"FALSE";
  v18.m_ls = 5;
  v18.m_lc = 0;
  Logger::LogMacro::operator()(
    &v18,
    "PacketController::AddRecipient(%ld %s %f 0x%08X admin=%s) %s\n",
    id,
    v10,
    lineNoise,
    gid,
    v8,
    result.m_buffer->m_data);
  if ( v7->recipients_[id] )
  {
    v16 = result.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) && v16 )
      v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
    v15 = 0;
  }
  else
  {
    v11 = (RecipientData *)operator new(0x390u);
    if ( v11 )
    {
      *(_DWORD *)&v12.sin_family = *(_DWORD *)&addr;
      *(_QWORD *)&v12.sin_addr.S_un.S_un_b.s_b1 = *(_QWORD *)&addr.sin_addr.S_un.S_un_b.s_b1;
      *(_DWORD *)&v12.sin_zero[4] = *(_DWORD *)&addr.sin_zero[4];
      RecipientData::RecipientData(v11, id, v12, v9, lineNoise);
    }
    else
    {
      v13 = 0;
    }
    v7->recipients_[id] = v13;
    AC1Legacy::PQueueArray<double>::Insert(
      &v7->FlowControlTimers,
      *(long double *)&Timer::cur_time,
      v7->recipients_[id]);
    v14 = result.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) )
    {
      if ( v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
    }
    v15 = 1;
  }
  return v15;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005412A0) --------------------------------------------------------  // acclient.c:368636
int __thiscall PacketController::DeleteRecipient(PacketController *this, unsigned __int16 id)
{
  PacketController *v2; // esi@1
  int result; // eax@2
  unsigned int v4; // edi@3
  RecipientData *v5; // ebx@4
  RecipientData *v6; // eax@5
  RecipientData *v7; // ecx@5
  RecipientData **v8; // ecx@13
  void *v9; // ebx@13

  v2 = this;
  if ( PacketController::pcontrol_->net_ )
  {
    v4 = id;
    if ( PacketController::pcontrol_->recipients_[v4] )
    {
      v5 = this->recipients_[v4];
      PQueueArray<double,void *>::RemoveByData(&this->FlowControlTimers, v5);
      if ( v5->onQueue_ )
      {
        v6 = v2->haveNaks_;
        v7 = 0;
        if ( v6 )
        {
          while ( v6 != v5 )
          {
            v7 = v6;
            v6 = v6->next_;
            if ( !v6 )
              goto LABEL_12;
          }
          if ( v7 )
            v7->next_ = v6->next_;
          else
            v2->haveNaks_ = v6->next_;
        }
LABEL_12:
        v5->onQueue_ = 0;
      }
      v8 = v2->recipients_;
      v9 = v8[v4];
      if ( v9 )
      {
        RecipientData::~RecipientData(v8[v4]);
        operator delete(v9);
      }
      v2->recipients_[v4] = 0;
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00541360) --------------------------------------------------------  // acclient.c:368696
void __thiscall PerfMonCounterInfo::PerfMonCounterNameHelp::~PerfMonCounterNameHelp(PerfMonCounterInfo::PerfMonCounterNameHelp *this)
{
  PerfMonCounterInfo::PerfMonCounterNameHelp *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4

  v1 = this;
  v2 = (char *)&this->m_help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (005413B0) --------------------------------------------------------  // acclient.c:368715
int __thiscall PerfMonCounterInfo::PerfMonCounterNameHelp::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // ebx@7
  int v8; // edi@10

  v2 = this;
  *(_WORD *)this = *(_WORD *)a2;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *(_DWORD *)(v2 + 8);
  if ( v6 != *(_DWORD *)(a2 + 8) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  return v2;
}

//----- (00541440) --------------------------------------------------------  // acclient.c:368751
void __cdecl GetIPFromRecipientID(unsigned __int16 idRecip, AC1Legacy::PStringBase<char> *ip, bool bShortFormat)
{
  if ( idRecip < 0x100u
    && (SharedNet *)((char *)SharedNet::s_pNet + 136 * idRecip) != (SharedNet *)-32
    && *(_WORD *)&SharedNet::s_pNet->receivers_[136 * idRecip] )
    NetUtils::GetIPString((sockaddr_in *)&SharedNet::s_pNet->receivers_[136 * idRecip + 48], ip, bShortFormat);
  else
    AC1Legacy::PStringBase<char>::set(ip, "(No ReceiverData for that RecipientID)");
}

//----- (00541490) --------------------------------------------------------  // acclient.c:368762
int __thiscall PacketController::AddReceivedBlobToQueue(PacketController *this, NetBlob *blob)
{
  unsigned int v2; // esi@1
  unsigned __int16 v3; // ax@2
  NIList<unsigned long> *v4; // edi@4
  int result; // eax@5
  unsigned __int16 v6; // si@7
  int v7; // ecx@8
  NetBlob *v8; // esi@12

  v2 = (unsigned int)blob;
  if ( !blob )
    return 0;
  v3 = blob->queueID_;
  if ( v3 >= 0xCu || !v3 )
  {
    blob = (NetBlob *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v6 = *(_WORD *)(v2 + 60);
    if ( v6 < 0x100u
      && (v7 = 136 * v6, (SharedNet *)((char *)SharedNet::s_pNet + v7) != (SharedNet *)-32)
      && *(_WORD *)&SharedNet::s_pNet->receivers_[v7] )
      NetUtils::GetIPString(
        (sockaddr_in *)&SharedNet::s_pNet->receivers_[v7 + 48],
        (AC1Legacy::PStringBase<char> *)&blob,
        0);
    else
      AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&blob, "(No ReceiverData for that RecipientID)");
    v8 = blob;
    if ( !InterlockedDecrement((volatile LONG *)&blob->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
    return 0;
  }
  v4 = (NIList<unsigned long> *)this->netQueues_[v3];
  if ( v4 )
  {
    InterlockedIncrement((volatile LONG *)&blob->m_cRef);
    NIList<NetBlob *>::AddToTail(v4, v2);
    result = 1;
  }
  else
  {
    blob = (NetBlob *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    GetIPFromRecipientID(*(_WORD *)(v2 + 60), (AC1Legacy::PStringBase<char> *)&blob, 0);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&blob);
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00541590) --------------------------------------------------------  // acclient.c:368815
char __thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_front(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this, PerfMonCounterInfo::PerfMonCounterNameHelp *retval)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v2; // ebp@1
  int v3; // edi@1
  char result; // al@2
  int v5; // eax@3
  int v6; // esi@7
  int v7; // esi@10

  v2 = this;
  v3 = (int)this->_head;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 12);
    this->_head = (ListNode<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 16) = 0;
    else
      this->_tail = 0;
    PerfMonCounterInfo::PerfMonCounterNameHelp::operator=((int)retval, v3);
    if ( v3 )
    {
      v6 = *(_DWORD *)(v3 + 8) - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = *(_DWORD *)(v3 + 4) - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      }
      operator delete((void *)v3);
    }
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00541620) --------------------------------------------------------  // acclient.c:368859
char __thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_head(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v1; // esi@1
  char v2; // al@1
  char *v3; // esi@1
  char v4; // bl@1
  char *v5; // esi@4
  PerfMonCounterInfo::PerfMonCounterNameHelp dummy; // [sp+Ch] [bp-Ch]@1

  dummy.m_name.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  dummy.m_languageID = 0;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  dummy.m_help.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v2 = List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_front(v1, &dummy);
  v3 = (char *)&dummy.m_help.m_charbuffer[-1].m_data[6];
  v4 = v2;
  if ( !InterlockedDecrement((volatile LONG *)&dummy.m_help.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v5 = (char *)&dummy.m_name.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&dummy.m_name.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return v4;
}

//----- (005416B0) --------------------------------------------------------  // acclient.c:368886
void __thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::~List<PerfMonCounterInfo::PerfMonCounterNameHelp>(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v1; // esi@1

  v1 = this;
  this->vfptr = (List<PerfMonCounterInfo::PerfMonCounterNameHelp>Vtbl *)List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable;
  while ( v1->_head )
    List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_head(v1);
}
// 7C9E90: using guessed type int (__thiscall *List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable[2])(void *, char);

//----- (005416E0) --------------------------------------------------------  // acclient.c:368898
List<PerfMonCounterInfo::PerfMonCounterNameHelp> *__thiscall List<PerfMonCounterInfo::PerfMonCounterNameHelp>::scalar_deleting_destructor(List<PerfMonCounterInfo::PerfMonCounterNameHelp> *this, unsigned int a2)
{
  List<PerfMonCounterInfo::PerfMonCounterNameHelp> *v2; // esi@1

  v2 = this;
  this->vfptr = (List<PerfMonCounterInfo::PerfMonCounterNameHelp>Vtbl *)List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable;
  while ( v2->_head )
    List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_head(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C9E90: using guessed type int (__thiscall *List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable[2])(void *, char);

//----- (00541720) --------------------------------------------------------  // acclient.c:368913
void __thiscall PerfMonCounterInfo::~PerfMonCounterInfo(PerfMonCounterInfo *this)
{
  PerfMonCounterInfo *v1; // edi@1
  char *v2; // esi@1

  v1 = this;
  v2 = (char *)&this->m_CounterNamesList;
  this->m_CounterNamesList.vfptr = (List<PerfMonCounterInfo::PerfMonCounterNameHelp>Vtbl *)List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable;
  while ( *((_DWORD *)v2 + 1) )
    List<PerfMonCounterInfo::PerfMonCounterNameHelp>::pop_head((List<PerfMonCounterInfo::PerfMonCounterNameHelp> *)v2);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7C9E90: using guessed type int (__thiscall *List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable[2])(void *, char);

//----- (00541750) --------------------------------------------------------  // acclient.c:368929
void __thiscall PerfMonCounter<unsigned __int64>::IncCounter(PerfMonCounter<unsigned __int64> *this)
{
  ++this->m_counter;
}

//----- (00541760) --------------------------------------------------------  // acclient.c:368935
void __thiscall PerfMonCounter<unsigned __int64>::DecCounter(PerfMonCounter<unsigned __int64> *this)
{
  int v1; // edx@1

  v1 = LODWORD(this->m_counter);
  LODWORD(this->m_counter) = v1 - 1;
  HIDWORD(this->m_counter) = __CFADD__(v1, -1) + HIDWORD(this->m_counter) - 1;
}

//----- (00541770) --------------------------------------------------------  // acclient.c:368945
unsigned __int64 __thiscall PerfMonCounter<unsigned __int64>::GetValueAsInt64(PerfMonCounter<unsigned __int64> *this)
{
  return this->m_counter;
}

//----- (00541780) --------------------------------------------------------  // acclient.c:368951
PerfMonCounter<unsigned __int64> *__thiscall PerfMonCounter<unsigned __int64>::scalar_deleting_destructor(PerfMonCounter<unsigned __int64> *this, unsigned int a2)
{
  PerfMonCounter<unsigned __int64> *v2; // esi@1

  v2 = this;
  PerfMonCounterInfo::~PerfMonCounterInfo((PerfMonCounterInfo *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005417A0) --------------------------------------------------------  // acclient.c:368963
void __thiscall PacketController::PacketController(PacketController *this, ClientNet *net)
{
  char v2; // bl@1
  ClientNet *v3; // eax@1
  PacketController *v4; // esi@1
  int v5; // edx@1
  unsigned int v6; // eax@1
  void *v7; // edi@3
  unsigned int v8; // eax@4
  unsigned int v9; // eax@4
  char *v10; // edi@7
  char *v11; // ebx@11
  PStringBase<unsigned short> help; // [sp+Ch] [bp-4h]@1

  v2 = 0;
  help.m_charbuffer = 0;
  v3 = net;
  v4 = this;
  this->vfptr = (PacketControllerVtbl *)&PacketController::vftable;
  this->net_ = v3;
  this->haveNaks_ = 0;
  this->FlowControlTimers.vfptr = (PQueueArray<double,void *>Vtbl *)&PQueueArray<double,void *>::vftable;
  this->FlowControlTimers.curNumNodes = 0;
  this->FlowControlTimers.A = (PQueueArray<double,void *>::PQueueNode *)operator new[](0x400u);
  v4->FlowControlTimers.minAllocatedNodes = 64;
  v4->FlowControlTimers.allocatedNodes = 64;
  LODWORD(v4->lastEmpty_) = 0;
  HIDWORD(v4->lastEmpty_) = 0;
  LODWORD(v4->m_curNonEphemeralID) = 0;
  HIDWORD(v4->m_curNonEphemeralID) = 0;
  NetInterface::NetInterface(&v4->netInterface_);
  v4->m_pSendBlobCallsCounter = 0;
  LODWORD(v4->m_curNonEphemeralID) = NetBlobIDUtils::MakeInitialSequenceID(0);
  HIDWORD(v4->m_curNonEphemeralID) = v5;
  v4->recipients_ = (RecipientData **)operator new[](0x400u);
  PacketController::pcontrol_ = v4;
  v6 = 0;
  do
  {
    v4->recipients_[v6] = 0;
    ++v6;
  }
  while ( v6 < 256 );
  memset(v4->netQueues_, 0, sizeof(v4->netQueues_));
  v7 = operator new(0x28u);
  if ( v7 )
  {
    v8 = _wcslen(L"Number of NetBlobs that have passed through PacketController::SendBlob.");
    PStringBase<unsigned short>::allocate_ref_buffer(&help, v8);
    _wcscpy(help.m_charbuffer->m_data, L"Number of NetBlobs that have passed through PacketController::SendBlob.");
    v9 = _wcslen(L"Net - PacketController::SendBlob calls");
    PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&net, v9);
    _wcscpy((wchar_t *)net, L"Net - PacketController::SendBlob calls");
    v2 = 3;
    PerfMonCounterInfo::PerfMonCounterInfo((PerfMonCounterInfo *)v7, 0, (PStringBase<unsigned short> *)&net, &help, 9u);
    *(_DWORD *)v7 = &PerfMonCounter<unsigned __int64>::vftable;
    *((_DWORD *)v7 + 8) = 0;
    *((_DWORD *)v7 + 9) = 0;
  }
  else
  {
    v7 = 0;
  }
  v4->m_pSendBlobCallsCounter = (PerfMonCounter<unsigned __int64> *)v7;
  if ( v2 & 2 )
  {
    v10 = (char *)&net[-1].m_LinkStatusAverages.m_TimeDiffs.m_Samples[1] + 4;
    v2 &= 0xFDu;
    if ( !InterlockedDecrement((volatile LONG *)&net[-1].m_LinkStatusAverages.m_TimeDiffs.m_CurTotal) )
    {
      if ( v10 )
        (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    }
  }
  if ( v2 & 1 )
  {
    v11 = (char *)&help.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    }
  }
}
// 7C9E18: using guessed type int (__thiscall *PQueueArray<double,void *>::vftable)(void *, char);
// 7C9E1C: using guessed type unsigned __int64 (__thiscall *PacketController::vftable)(PacketController *__hidden this);
// 7C9E94: using guessed type int (__thiscall *PerfMonCounter<unsigned __int64>::vftable)(void *, char);
// 845EF8: using guessed type struct PacketController *PacketController::pcontrol_;

//----- (00705590) --------------------------------------------------------  // acclient.c:792576
int _E77_6()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_23;
  INITIAL_MAX_DATA_RATE_97 = LOWEST_DATA_RATE_23;
  return result;
}

//----- (007055A0) --------------------------------------------------------  // acclient.c:792586
int sub_7055A0()
{
  return atexit(nullsub_1204);
}

