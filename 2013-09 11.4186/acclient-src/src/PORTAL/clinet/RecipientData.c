/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RecipientData
   Object     : PORTAL\clinet\RecipientData.obj
   Functions  : 10
   Addresses  : 00546DD0 - 00705650 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00546DD0) --------------------------------------------------------  // acclient.c:374249
void __thiscall RecipientData::TouchConnection(RecipientData *this)
{
  this->lastTouched_ = (double)Timer::get_real_time();
}

//----- (00546DF0) --------------------------------------------------------  // acclient.c:374255
int __thiscall RecipientData::IndicateReceivedPacket(RecipientData *this, NetPacket *pPacket, unsigned int priority)
{
  Indicator::CheckInPacket(this->dependencies_, pPacket, pPacket->recipient_);
  return 1;
}

//----- (00546E20) --------------------------------------------------------  // acclient.c:374262
void __thiscall RecipientData::EnqueueBlob(RecipientData *this, NetBlob *newGuy)
{
  RecipientData *v2; // esi@1
  RecipientData *v3; // ST00_4@1
  PacketController *v4; // eax@1

  v2 = this;
  v3 = this;
  v4 = PacketController::Instance();
  PacketController::EnqueueRecip(v4, v3);
  (*(void (__thiscall **)(int, NetBlob *))&v2->flowQueue_.vfptr->gap4[0])(&v2->flowQueue_, newGuy);
}

//----- (00546E40) --------------------------------------------------------  // acclient.c:374276
void __thiscall RecipientData::UseTime(RecipientData *this)
{
  RecipientData *v1; // esi@1
  FlowQueue *v2; // edi@1
  unsigned int v3; // eax@1

  v1 = this;
  v2 = (FlowQueue *)&this->flowQueue_.vfptr;
  FlowQueue::Empty((FlowQueue *)&this->flowQueue_.vfptr);
  v3 = v1->flushNum_;
  if ( v3 )
  {
    FlowQueue::FlushSentPackets(v2, v3, 0);
    v1->flushNum_ = 0;
  }
  Indicator::FlushTimedOutEphInfo(v1->dependencies_);
}

//----- (00546E80) --------------------------------------------------------  // acclient.c:374295
void __thiscall RecipientData::RecipientData(RecipientData *this, unsigned __int16 recID, sockaddr_in addr, int noflow, float lineNoise)
{
  RecipientData *v5; // esi@1
  sockaddr_in v6; // ST00_16@1
  unsigned int v7; // edx@1
  Indicator *v8; // eax@1
  Indicator *v9; // eax@2

  v5 = this;
  *(_QWORD *)&v6.sin_family = *(_QWORD *)&addr;
  *(_QWORD *)&v6.sin_zero[0] = *(_QWORD *)&addr.sin_zero[0];
  *(_QWORD *)&this->lastTouched_ = 0i64;
  this->waitingBlobs_.head_ = 0;
  this->waitingBlobs_.tail_ = 0;
  ClientFlowQueue::ClientFlowQueue(&this->flowQueue_, v6, recID, lineNoise);
  v5->next_ = 0;
  v5->recID_ = recID;
  v5->onQueue_ = 0;
  v5->dependencies_ = 0;
  v5->gidPlayer_ = 0;
  v5->flushNum_ = 0;
  v7 = Timer::cur_time.Param;
  LODWORD(v5->timeAllocated_) = Timer::cur_time.Cmd;
  HIDWORD(v5->timeAllocated_) = v7;
  v8 = (Indicator *)operator new(0x58u);
  if ( v8 )
    Indicator::Indicator(v8);
  else
    v9 = 0;
  v5->dependencies_ = v9;
  v5->flowQueue_.myRecip_ = v5;
  v5->lastTouched_ = (double)Timer::get_real_time();
}

//----- (00546F40) --------------------------------------------------------  // acclient.c:374330
void __thiscall RecipientData::~RecipientData(RecipientData *this)
{
  RecipientData *v1; // ebx@1
  char *v2; // edi@1
  int v3; // eax@2
  int v4; // esi@3
  int v5; // ecx@4
  Indicator *v6; // ecx@10

  v1 = this;
  v2 = (char *)&this->waitingBlobs_;
  while ( 1 )
  {
    v3 = *(_DWORD *)v2;
    if ( *(_DWORD *)v2 )
    {
      v5 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)v2 = v5;
      if ( !v5 )
        *((_DWORD *)v2 + 1) = 0;
      v4 = *(_DWORD *)v3;
      operator delete((void *)v3);
    }
    else
    {
      v4 = 0;
    }
    if ( !v4 )
      break;
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
  FlowQueue::Destroy((FlowQueue *)&v1->flowQueue_.vfptr);
  v1->flushNum_ = 0;
  FlowQueue::FlushSentPackets((FlowQueue *)&v1->flowQueue_.vfptr, 0, 1);
  v6 = v1->dependencies_;
  v1->flushNum_ = 0;
  if ( v6 )
    ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
  ClientFlowQueue::~ClientFlowQueue(&v1->flowQueue_);
  NIList<unsigned long>::DeleteContents((NIList<NetPacket *> *)v2);
}

//----- (00546FD0) --------------------------------------------------------  // acclient.c:374374
void __thiscall RecipientData::QueueFlush(RecipientData *this, unsigned int num)
{
  unsigned int v2; // eax@1
  unsigned int v3; // edx@2
  int v4; // edi@2

  v2 = this->flushNum_;
  if ( num != v2 )
  {
    v3 = num - v2;
    v4 = 1;
    if ( num < v2 )
    {
      v3 = v2 - num;
      v4 = -1;
    }
    if ( v3 > 0x7FFFFFFF )
      v4 = -v4;
    if ( v4 > 0 )
      this->flushNum_ = num;
  }
}

//----- (00547010) --------------------------------------------------------  // acclient.c:374398
void __thiscall RecipientData::ProcessNaks(RecipientData *this, int numNaks, const unsigned int *seqIDs)
{
  RecipientData *v3; // esi@1
  PacketController *v4; // eax@1
  const unsigned int v5; // ecx@1
  unsigned int v6; // eax@1
  int v7; // edx@2
  int v8; // edi@2

  v3 = this;
  FlowQueue::EnqueueAcks((FlowQueue *)&this->flowQueue_.vfptr, seqIDs, numNaks);
  v4 = PacketController::Instance();
  PacketController::EnqueueRecip(v4, v3);
  v5 = *seqIDs;
  v6 = v3->flushNum_;
  if ( *seqIDs != v6 )
  {
    v7 = v5 - v6;
    v8 = 1;
    if ( v5 < v6 )
    {
      v7 = v6 - v5;
      v8 = -1;
    }
    if ( (unsigned int)v7 > 0x7FFFFFFF )
      v8 = -v8;
    if ( v8 > 0 )
      v3->flushNum_ = v5;
  }
}

//----- (00705640) --------------------------------------------------------  // acclient.c:792658
int _E77_10()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_27;
  dword_845F48 = LOWEST_DATA_RATE_27;
  return result;
}

//----- (00705650) --------------------------------------------------------  // acclient.c:792668
int sub_705650()
{
  return atexit(nullsub_1214);
}

