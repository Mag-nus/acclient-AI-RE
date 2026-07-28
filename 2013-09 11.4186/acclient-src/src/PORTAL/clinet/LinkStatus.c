/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LinkStatus
   Object     : PORTAL\clinet\LinkStatus.obj
   Functions  : 9
   Addresses  : 00546440 - 007055E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00546440) --------------------------------------------------------  // acclient.c:373700
void __thiscall CLinkStatusAverages::CAverager<float,4>::AddSample(CLinkStatusAverages::CAverager<float,4> *this, float Data)
{
  unsigned __int16 v2; // ax@1
  int v3; // eax@2

  v2 = this->m_nSamples;
  if ( v2 == 4 )
  {
    v3 = this->m_idxFirst;
    this->m_CurTotal = this->m_CurTotal - this->m_Samples[v3];
    this->m_Samples[v3] = Data;
    this->m_idxFirst = (unsigned __int16)(this->m_idxFirst + 1) % 4;
    this->m_CurTotal = Data + this->m_CurTotal;
  }
  else
  {
    this->m_Samples[v2] = Data;
    ++this->m_nSamples;
    this->m_CurTotal = Data + this->m_CurTotal;
  }
}

//----- (005464B0) --------------------------------------------------------  // acclient.c:373723
void __thiscall CLinkStatusAverages::CAverager<unsigned short,40>::AddSample(CLinkStatusAverages::CAverager<unsigned short,40> *this, unsigned __int16 Data)
{
  unsigned __int16 v2; // ax@1
  int v3; // eax@2

  v2 = this->m_nSamples;
  if ( v2 == 40 )
  {
    v3 = this->m_idxFirst;
    this->m_CurTotal = this->m_CurTotal - (double)this->m_Samples[v3];
    this->m_Samples[v3] = Data;
    this->m_idxFirst = (unsigned __int16)(this->m_idxFirst + 1) % 40;
  }
  else
  {
    this->m_Samples[v2] = Data;
    ++this->m_nSamples;
  }
  this->m_CurTotal = (double)Data + this->m_CurTotal;
}

//----- (00546520) --------------------------------------------------------  // acclient.c:373745
void __thiscall CLinkStatusAverages::CAverager<unsigned long,2>::AddSample(CLinkStatusAverages::CAverager<unsigned long,2> *this, unsigned int Data)
{
  unsigned __int16 v2; // ax@1
  int v3; // eax@2
  unsigned int v4; // edx@2

  v2 = this->m_nSamples;
  if ( v2 == 2 )
  {
    v3 = this->m_idxFirst;
    v4 = Data;
    this->m_CurTotal = this->m_CurTotal - (double)this->m_Samples[v3];
    this->m_Samples[v3] = Data;
    this->m_idxFirst = (unsigned __int16)(this->m_idxFirst + 1) % 2;
  }
  else
  {
    v4 = Data;
    this->m_Samples[v2] = Data;
    ++this->m_nSamples;
  }
  this->m_CurTotal = (double)v4 + this->m_CurTotal;
}

//----- (005465A0) --------------------------------------------------------  // acclient.c:373770
void __thiscall CLinkStatusAverages::CAverager<double,2>::AddSample(CLinkStatusAverages::CAverager<double,2> *this, long double Data)
{
  unsigned __int16 v2; // ax@1
  int v3; // eax@2

  v2 = this->m_nSamples;
  if ( v2 == 2 )
  {
    v3 = this->m_idxFirst;
    this->m_CurTotal = this->m_CurTotal - this->m_Samples[v3];
    this->m_Samples[v3] = Data;
    this->m_idxFirst = (unsigned __int16)(this->m_idxFirst + 1) % 2;
    this->m_CurTotal = Data + this->m_CurTotal;
  }
  else
  {
    this->m_Samples[v2] = Data;
    ++this->m_nSamples;
    this->m_CurTotal = Data + this->m_CurTotal;
  }
}

//----- (00546610) --------------------------------------------------------  // acclient.c:373793
double __thiscall CLinkStatusAverages::GetAveragePacketLoss(CLinkStatusAverages *this)
{
  long double v1; // st7@1
  double result; // st7@2
  long double v3; // st6@3

  v1 = this->m_nPktsReceived.m_CurTotal + this->m_nPktsSent.m_CurTotal;
  if ( v1 > 0.0 )
  {
    v3 = this->m_nPktsNAKed.m_CurTotal + this->m_nPktsRetransmitted.m_CurTotal;
    result = v3 / v1 + v3 / v1;
  }
  else
  {
    result = 0.0;
  }
  return result;
}

//----- (00546650) --------------------------------------------------------  // acclient.c:373813
void __thiscall CLinkStatusAverages::AddSnapshot(CLinkStatusAverages *this, CLinkStatusSnapshot *Snap)
{
  long double v2; // st7@1
  CLinkStatusAverages *v3; // ebx@1
  double SampleDuration; // [sp+8h] [bp-8h]@1

  v2 = Timer::local_time;
  v3 = this;
  SampleDuration = Snap->SnapshotDuration;
  if ( this->m_LocalTimeOfSnapshot == 0.0 || Snap->SnapshotDuration <= 0.0 )
    SampleDuration = 1.0;
  qmemcpy(this, Snap, 0x1Cu);
  this->m_LocalTimeOfSnapshot = v2;
  CLinkStatusAverages::CAverager<unsigned short,40>::AddSample(&this->m_nPktsSent, Snap->nPktsSent);
  CLinkStatusAverages::CAverager<unsigned short,40>::AddSample(&v3->m_nPktsRetransmitted, Snap->nPktsRetransmitted);
  CLinkStatusAverages::CAverager<unsigned short,40>::AddSample(&v3->m_nPktsReceived, Snap->nPktsReceived);
  CLinkStatusAverages::CAverager<unsigned short,40>::AddSample(&v3->m_nPktsNAKed, Snap->nPktsNAKed);
  CLinkStatusAverages::CAverager<unsigned long,2>::AddSample(&v3->m_nBytesSent, Snap->nBytesSent);
  CLinkStatusAverages::CAverager<unsigned long,2>::AddSample(&v3->m_nBytesReceived, Snap->nBytesReceived);
  CLinkStatusAverages::CAverager<double,2>::AddSample(&v3->m_TimeDiffs, SampleDuration);
}

//----- (00546730) --------------------------------------------------------  // acclient.c:373836
void __thiscall CLinkStatusAverages::OnPingResponse(CLinkStatusAverages *this, float RoundTripDelay)
{
  CLinkStatusAverages::CAverager<float,4>::AddSample(&this->m_RoundTripDelays, RoundTripDelay);
}

//----- (007055D0) --------------------------------------------------------  // acclient.c:792608
int _E77_8()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_25;
  dword_845F1C = LOWEST_DATA_RATE_25;
  return result;
}

//----- (007055E0) --------------------------------------------------------  // acclient.c:792618
int sub_7055E0()
{
  return atexit(nullsub_1218);
}

