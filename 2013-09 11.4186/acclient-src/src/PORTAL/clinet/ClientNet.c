/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClientNet
   Object     : PORTAL\clinet\ClientNet.obj
   Functions  : 99
   Addresses  : 004011E0 - 007055C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004011E0) --------------------------------------------------------  // acclient.c:60919
AC1Legacy::PSRefBuffer<unsigned short> *__thiscall AC1Legacy::PSRefBuffer<unsigned short>::scalar_deleting_destructor(AC1Legacy::PSRefBuffer<unsigned short> *this, unsigned int a2)
{
  AC1Legacy::PSRefBuffer<unsigned short> *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<268435456,0>Vtbl *)AC1Legacy::PSRefBuffer<char>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (00541930) --------------------------------------------------------  // acclient.c:369053
void __stdcall SharedNet::ProcessNewestSeqNum(CNetLayerPacket *pkt)
{
  unsigned int v2; // ebx@1
  ReceiverData *v3; // ebp@1
  unsigned int v4; // esi@3

  v2 = pkt->m_Hdr.seqID_;
  v3 = pkt->m_pRecv;
  if ( !(pkt->m_Hdr.header_ & 2) )
    ++v2;
  v4 = v3->highestIDReceived_ + 1;
  if ( v4 == v2 )
  {
    v3->highestIDReceived_ = pkt->m_Hdr.seqID_;
  }
  else
  {
    do
    {
      if ( v4 )
        ReceiverData::AddNakked(pkt->m_pRecv, v4, 0);
      ++v4;
    }
    while ( v4 != v2 );
    v3->highestIDReceived_ = pkt->m_Hdr.seqID_;
  }
}

//----- (00541990) --------------------------------------------------------  // acclient.c:369082
int __stdcall SharedNet::ChecksumHeader(ProtoHeader *Hdr)
{
  unsigned int v2; // edx@1
  unsigned __int16 v3; // cx@1
  unsigned __int16 v4; // cx@1
  ProtoHeader mutableHeader; // [sp+0h] [bp-14h]@1

  v2 = Hdr->header_;
  mutableHeader.seqID_ = Hdr->seqID_;
  v3 = Hdr->recID_;
  mutableHeader.header_ = v2;
  LOWORD(v2) = Hdr->interval_;
  mutableHeader.recID_ = v3;
  v4 = Hdr->iteration_;
  mutableHeader.interval_ = v2;
  LOWORD(v2) = Hdr->datalen_;
  mutableHeader.iteration_ = v4;
  mutableHeader.datalen_ = v2;
  mutableHeader.checksum_ = -1159892771;
  return PortalChecksum::CalcChecksum32((const char *)&mutableHeader, 0x14u);
}

//----- (005419F0) --------------------------------------------------------  // acclient.c:369105
char __thiscall SharedNet::ProcessOptionalHeaders(SharedNet *this, CNetLayerPacket *pkt)
{
  SharedNet *v2; // ebx@1
  unsigned __int16 v3; // ST08_2@1
  PacketController *v4; // eax@1
  unsigned int v5; // edi@1
  char *v6; // ebp@2

  v2 = this;
  v3 = pkt->recipient_;
  v4 = PacketController::Instance();
  PacketController::GetRecipient(v4, v3);
  v5 = 0;
  if ( pkt->numSpecialFrags_ )
  {
    v6 = (char *)pkt->specialFragList_;
    do
    {
      v2->vfptr->ProcessOptionalHeader(v2, *(COptionalHeader **)v6, pkt);
      ++v5;
      v6 += 4;
    }
    while ( v5 < pkt->numSpecialFrags_ );
  }
  return 1;
}

//----- (00541A50) --------------------------------------------------------  // acclient.c:369133
BOOL __stdcall SharedNet::ProcessBlobFrags(CNetLayerPacket *pkt)
{
  return RecipientData::IndicateReceivedPacket(pkt->m_pRecip, (NetPacket *)&pkt->vfptr, pkt->realPriority_) != 0;
}

//----- (00541A70) --------------------------------------------------------  // acclient.c:369139
int __thiscall SharedNet::SendBuff(SharedNet *this, _WSABUF *vecs, int iovNum, sockaddr_in addr_to)
{
  SharedNet *v4; // edi@1
  int v5; // ecx@1
  int v6; // eax@1
  int v7; // eax@4
  char *v8; // ebx@4
  int v9; // eax@7
  int v10; // esi@7
  int result; // eax@8
  void (__cdecl *v12)(PacketInfo *, unsigned int); // eax@9
  unsigned int v13; // ecx@10
  int v14; // [sp+Ch] [bp-10014h]@1
  unsigned int s; // [sp+10h] [bp-10010h]@1
  int v16; // [sp+18h] [bp-10008h]@10
  sockaddr_in *v17; // [sp+1Ch] [bp-10004h]@10
  int v18; // [sp+20h] [bp-10000h]@10
  char *v19; // [sp+24h] [bp-FFFCh]@10
  char *v20; // [sp+28h] [bp-FFF8h]@10
  int v21; // [sp+2Ch] [bp-FFF4h]@10
  int v22; // [sp+30h] [bp-FFF0h]@10
  int v23; // [sp+34h] [bp-FFECh]@10
  char v24; // [sp+38h] [bp-FFE8h]@10
  char *v25; // [sp+3Ch] [bp-FFE4h]@10
  char buf; // [sp+40h] [bp-FFE0h]@4

  v4 = this;
  s = this->m_sockWrite;
  v5 = 0;
  v6 = 0;
  v14 = 0;
  if ( iovNum > 0 )
  {
    do
      v5 += vecs[v6++].len;
    while ( v6 < iovNum );
    v14 = v5;
  }
  v7 = 0;
  v8 = &buf;
  if ( iovNum > 0 )
  {
    do
    {
      qmemcpy(v8, vecs[v7].buf, vecs[v7].len);
      v8 += vecs[v7++].len;
    }
    while ( v7 < iovNum );
    v5 = v14;
  }
  v9 = sendto(s, &buf, v5, 0, (const struct sockaddr *)&addr_to, 16);
  v10 = v9;
  if ( v9 == -1 )
  {
    result = 0;
  }
  else
  {
    v4->vfptr->AddToPerfCounter(v4, 0, v9);
    v12 = v4->m_Loggers.pfnSendLogger;
    if ( v12 )
    {
      v17 = &addr_to;
      v19 = &buf;
      v20 = &v24;
      v13 = v4->m_Loggers.dwUserLoggingData;
      v25 = &buf;
      v16 = 40;
      v18 = v10;
      v21 = 1;
      v22 = 16;
      v23 = 2;
      *(_DWORD *)&v24 = v10;
      v12((PacketInfo *)&v16, v13);
    }
    result = v10;
  }
  return result;
}

//----- (00541BA0) --------------------------------------------------------  // acclient.c:369220
char __thiscall SharedNet::SendPacket(SharedNet *this, NetPacket *packet, ProtoHeader *pheader, sockaddr_in *addr)
{
  SharedNet *v4; // edi@1
  unsigned int v5; // ecx@1
  unsigned int v6; // edx@1
  signed int v7; // eax@1
  int v8; // esi@1
  char *v9; // edi@2
  int v10; // ecx@3
  char *v11; // esi@6
  int v12; // ecx@7
  int v13; // esi@8
  signed int i; // eax@8
  SharedNetVtbl *v15; // eax@10
  signed int v16; // ecx@10
  char result; // al@11
  SharedNetVtbl *v18; // eax@12
  int v19; // [sp-10h] [bp-2FCh]@10
  unsigned int v20; // [sp-Ch] [bp-2F8h]@10
  signed int v21; // [sp-8h] [bp-2F4h]@10
  signed int v22; // [sp-4h] [bp-2F0h]@10
  SharedNet *v23; // [sp+10h] [bp-2DCh]@1
  _WSABUF scatter[91]; // [sp+14h] [bp-2D8h]@1

  v4 = this;
  v23 = this;
  pheader->checksum_ += SharedNet::ChecksumHeader(pheader);
  v5 = packet->numSpecialFrags_;
  v6 = v5 + 2 * packet->numFrags_ + 1;
  scatter[0].buf = (char *)pheader;
  v7 = 1;
  v8 = v5 + 1;
  scatter[0].len = 20;
  if ( v5 < 0xFFFFFFFF && v5 != 0 )
  {
    v9 = (char *)packet->specialFragList_;
    do
    {
      v10 = *(_DWORD *)v9;
      scatter[v7].buf = *(char **)(*(_DWORD *)v9 + 16);
      scatter[v7++].len = *(_DWORD *)(v10 + 20);
      v9 += 4;
    }
    while ( v7 < (unsigned int)v8 );
    v4 = v23;
  }
  if ( v7 < (signed int)v6 )
  {
    v11 = (char *)packet->fragList_;
    do
    {
      v12 = *(_DWORD *)v11;
      scatter[v7].buf = *(char **)(*(_DWORD *)v11 + 16);
      scatter[v7].len = 16;
      scatter[v7 + 1].buf = *(char **)(v12 + 40);
      scatter[v7 + 1].len = *(_WORD *)(*(_DWORD *)(v12 + 16) + 10) - 16;
      v7 += 2;
      v11 += 4;
    }
    while ( v7 < (signed int)v6 );
  }
  v13 = 0;
  for ( i = 0; i < (signed int)v6; ++i )
    v13 += scatter[i].len;
  v15 = v4->vfptr;
  v19 = *(_DWORD *)&addr->sin_family;
  v20 = addr->sin_addr.S_un.S_addr;
  v16 = *(_DWORD *)&addr->sin_zero[4];
  v21 = *(_DWORD *)&addr->sin_zero[0];
  v22 = v16;
  if ( (*(int (__thiscall **)(SharedNet *, _WSABUF *, unsigned int, int, unsigned int, signed int, signed int))&v15->gap4[0])(
         v4,
         scatter,
         v6,
         v19,
         v20,
         v21,
         v16) >= v13 )
  {
    v18 = v4->vfptr;
    v22 = 1;
    v21 = 9;
    v18->AddToPerfCounter(v4, 9, 1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00541CC0) --------------------------------------------------------  // acclient.c:369313
void __thiscall SharedNet::SetConnectionState(SharedNet *this, unsigned __int16 idRecip, ConnectionState NewState)
{
  ReceiverData *v3; // ecx@2
  PacketController *v4; // eax@4
  RecipientData *v5; // eax@4

  if ( idRecip >= 0x100u )
    v3 = 0;
  else
    v3 = (ReceiverData *)&this->receivers_[136 * idRecip];
  ReceiverData::SetConnectionState(v3, NewState);
  v4 = PacketController::Instance();
  v5 = PacketController::GetRecipient(v4, idRecip);
  if ( v5 )
    v5->m_ConnectionState = NewState;
}

//----- (00541D10) --------------------------------------------------------  // acclient.c:369331
char __cdecl ParseInAddr(const char **p, in_addr *Addr)
{
  signed int v2; // ebx@1
  int v3; // edx@5
  const char *v4; // eax@5
  int v5; // ecx@9
  unsigned int v6; // ST0C_4@9
  int n; // [sp+10h] [bp-8h]@1
  int i; // [sp+14h] [bp-4h]@1

  v2 = 0;
  if ( _sscanf(*p, "%d%n", &i, &n) )
  {
    while ( i >= 0 && i <= 255 )
    {
      ++v2;
      if ( v2 <= 4 )
      {
        v3 = n;
        Addr->S_un.S_addr = i | (Addr->S_un.S_addr << 8);
        v4 = &(*p)[v3];
        *p = v4;
        if ( *v4 == 46 )
        {
          *p = v4 + 1;
          if ( _sscanf(*p, "%d%n", &i, &n) )
            continue;
        }
      }
      if ( v2 >= 1 && v2 <= 4 )
      {
        v5 = 8 * (4 - v2);
        v6 = Addr->S_un.S_addr << v5;
        Addr->S_un.S_addr = v6;
        Addr->S_un.S_addr = htonl(v6);
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

//----- (00541DD0) --------------------------------------------------------  // acclient.c:369375
void __thiscall ClientNet::OnStateBegun(ClientNet *this, AsyncContext hContext)
{
  int v2; // eax@1

  *(_DWORD *)&this->receivers_[48] = 0;
  *(_DWORD *)&this->receivers_[24] = 0;
  v2 = *(_DWORD *)&this[-1].receivers_[1064];
  this->receivers_[52] = 1;
  (*(void (__thiscall **)(_BYTE *))(v2 + 92))(&this[-1].receivers_[1064]);
}

//----- (00541DF0) --------------------------------------------------------  // acclient.c:369387
void __thiscall ClientNet::EnterWorld(ClientNet *this)
{
  this->fCurrentlyInGame_ = 1;
}

//----- (00541E00) --------------------------------------------------------  // acclient.c:369393
void __thiscall ClientNet::ExitWorldDisconnect(ClientNet *this)
{
  ClientNet *v1; // esi@1
  ReceiverData *v2; // eax@3
  ReceiverData *v3; // edi@4
  unsigned __int16 v4; // ax@4
  ReceiverData *v5; // eax@7

  v1 = this;
  if ( this->fCurrentlyInGame_ )
    this->fCurrentlyInGame_ = 0;
  this->currServerRecID_ = this->logonRecID_;
  v2 = this->connectionsHead_;
  if ( v2 )
  {
    do
    {
      v3 = v2->next_;
      v4 = v2->m_RecID;
      if ( v4 != v1->logonRecID_ )
        ClientNet::RemoveConnection(v1, v4);
      v2 = v3;
    }
    while ( v3 );
  }
  v5 = v1->connectionsHead_;
  if ( v5 )
  {
    v1->netID_ = v5->m_NetID;
    v5->m_NakState = 2;
    v1->m_WorldSwitchHistory.bBeenSwitchedBefore = 0;
    Proto_UI::SetEventCounter(0);
  }
  else
  {
    v1->logonRecID_ = 0;
  }
}

//----- (00541E90) --------------------------------------------------------  // acclient.c:369433
int __thiscall ClientNet::SendBuff(ClientNet *this, _WSABUF *vecs, int vecNum, sockaddr_in addr_to)
{
  int result; // eax@2
  sockaddr_in v5; // ST08_16@3
  int v6; // esi@3

  if ( this->logOffSent_ )
  {
    result = 0;
  }
  else
  {
    *(_QWORD *)&v5.sin_family = *(_QWORD *)&addr_to;
    *(_QWORD *)&v5.sin_zero[0] = *(_QWORD *)&addr_to.sin_zero[0];
    v6 = SharedNet::SendBuff((SharedNet *)&this->vfptr, vecs, vecNum, v5);
    if ( !v6 )
      WSAGetLastError();
    result = v6;
  }
  return result;
}

//----- (00541EF0) --------------------------------------------------------  // acclient.c:369456
void __thiscall COnePrimHeader<512,7,sockaddr_in>::InqData(COnePrimHeader<512,7,sockaddr_in> *this, sockaddr_in *o_Ret)
{
  char *v2; // ecx@1

  v2 = (char *)&this->m_Prim;
  *(_DWORD *)&o_Ret->sin_family = *(_DWORD *)v2;
  o_Ret->sin_addr.S_un.S_addr = *((_DWORD *)v2 + 1);
  *(_DWORD *)&o_Ret->sin_zero[0] = *((_DWORD *)v2 + 2);
  *(_DWORD *)&o_Ret->sin_zero[4] = *((_DWORD *)v2 + 3);
}

//----- (00541F10) --------------------------------------------------------  // acclient.c:369468
AVLNode<unsigned long,unsigned long> *__thiscall AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(AVLNode<unsigned long,unsigned long> *this, unsigned int a2)
{
  AVLNode<unsigned long,unsigned long> *v2; // esi@1

  v2 = this;
  AVLNode<unsigned long,unsigned long>::~AVLNode<unsigned long,unsigned long>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00541F30) --------------------------------------------------------  // acclient.c:369480
void __thiscall AVLNode<unsigned long,unsigned long>::~AVLNode<unsigned long,unsigned long>(AVLNode<unsigned long,unsigned long> *this)
{
  AVLNode<unsigned long,unsigned long> *v1; // esi@1
  AVLNode<unsigned long,unsigned long> *v2; // edi@1
  void *v3; // edi@3

  v1 = this;
  v2 = this->_left;
  if ( this->_left )
  {
    AVLNode<unsigned long,unsigned long>::~AVLNode<unsigned long,unsigned long>(this->_left);
    operator delete(v2);
  }
  v3 = v1->_right;
  if ( v3 )
  {
    AVLNode<unsigned long,unsigned long>::~AVLNode<unsigned long,unsigned long>(v1->_right);
    operator delete(v3);
  }
  v1->_left = 0;
  v1->_right = 0;
}

//----- (00541F80) --------------------------------------------------------  // acclient.c:369504
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::LeftRotate(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *aNode, AVLNode<unsigned long,unsigned long> *bNode, AVLNode<unsigned long,unsigned long> *cNode)
{
  AVLNode<unsigned long,unsigned long> *result; // eax@1
  AVLNode<unsigned long,unsigned long> *v5; // esi@1
  int v6; // edi@9
  AVLNode<unsigned long,unsigned long> *v7; // esi@11
  int v8; // esi@12
  int v9; // edx@17
  AVLNode<unsigned long,unsigned long> *v10; // esi@19
  int v11; // ecx@20

  result = bNode;
  v5 = aNode->_parent;
  aNode->_right = cNode;
  bNode->_left = aNode;
  bNode->_parent = v5;
  if ( v5 )
  {
    if ( aNode->_parentsize )
    {
      v5->_left = bNode;
      bNode->_parentsize = 1;
    }
    else
    {
      v5->_right = bNode;
      bNode->_parentsize = 0;
    }
  }
  else
  {
    this->_root = bNode;
  }
  aNode->_parent = bNode;
  aNode->_parentsize = 1;
  if ( cNode )
  {
    cNode->_parent = aNode;
    cNode->_parentsize = 0;
  }
  if ( aNode->_left )
    v6 = aNode->_left->_height + 1;
  else
    v6 = 1;
  v7 = aNode->_right;
  aNode->_leftHeight = v6;
  if ( v7 )
    v8 = v7->_height + 1;
  else
    v8 = 1;
  aNode->_rightHeight = v8;
  if ( v6 >= v8 )
    v8 = v6;
  aNode->_height = v8;
  if ( bNode->_left )
    v9 = bNode->_left->_height + 1;
  else
    v9 = 1;
  v10 = bNode->_right;
  bNode->_leftHeight = v9;
  if ( v10 )
    v11 = v10->_height + 1;
  else
    v11 = 1;
  bNode->_rightHeight = v11;
  if ( v9 < v11 )
    bNode->_height = v11;
  else
    bNode->_height = v9;
  return result;
}

//----- (00542040) --------------------------------------------------------  // acclient.c:369577
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::RightRotate(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *aNode, AVLNode<unsigned long,unsigned long> *bNode, AVLNode<unsigned long,unsigned long> *cNode)
{
  AVLNode<unsigned long,unsigned long> *result; // eax@1
  AVLNode<unsigned long,unsigned long> *v5; // esi@1
  int v6; // edi@9
  AVLNode<unsigned long,unsigned long> *v7; // esi@11
  int v8; // esi@12
  int v9; // edx@17
  AVLNode<unsigned long,unsigned long> *v10; // esi@19
  int v11; // ecx@20

  result = bNode;
  v5 = aNode->_parent;
  aNode->_left = cNode;
  bNode->_right = aNode;
  bNode->_parent = v5;
  if ( v5 )
  {
    if ( aNode->_parentsize )
    {
      v5->_left = bNode;
      bNode->_parentsize = 1;
    }
    else
    {
      v5->_right = bNode;
      bNode->_parentsize = 0;
    }
  }
  else
  {
    this->_root = bNode;
  }
  aNode->_parent = bNode;
  aNode->_parentsize = 0;
  if ( cNode )
  {
    cNode->_parent = aNode;
    cNode->_parentsize = 1;
  }
  if ( aNode->_left )
    v6 = aNode->_left->_height + 1;
  else
    v6 = 1;
  v7 = aNode->_right;
  aNode->_leftHeight = v6;
  if ( v7 )
    v8 = v7->_height + 1;
  else
    v8 = 1;
  aNode->_rightHeight = v8;
  if ( v6 >= v8 )
    v8 = v6;
  aNode->_height = v8;
  if ( bNode->_left )
    v9 = bNode->_left->_height + 1;
  else
    v9 = 1;
  v10 = bNode->_right;
  bNode->_leftHeight = v9;
  if ( v10 )
    v11 = v10->_height + 1;
  else
    v11 = 1;
  bNode->_rightHeight = v11;
  if ( v9 < v11 )
    bNode->_height = v11;
  else
    bNode->_height = v9;
  return result;
}

//----- (00542100) --------------------------------------------------------  // acclient.c:369650
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::LeftRightRotate(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *aNode, AVLNode<unsigned long,unsigned long> *bNode, AVLNode<unsigned long,unsigned long> *cNode)
{
  AVL<unsigned long,unsigned long> *v4; // ebx@1
  int v5; // ecx@2
  AVLNode<unsigned long,unsigned long> *v6; // eax@4
  int v7; // eax@5
  int v8; // ecx@10
  AVLNode<unsigned long,unsigned long> *v9; // eax@12
  int v10; // eax@13
  int v11; // ecx@18
  AVLNode<unsigned long,unsigned long> *v12; // eax@20
  int v13; // eax@21
  AVLNode<unsigned long,unsigned long> *result; // eax@24

  v4 = this;
  AVL<unsigned long,unsigned long>::LeftRotate(this, bNode, cNode, cNode->_left);
  AVL<unsigned long,unsigned long>::RightRotate(v4, aNode, cNode, cNode->_right);
  if ( aNode->_left )
    v5 = aNode->_left->_height + 1;
  else
    v5 = 1;
  v6 = aNode->_right;
  aNode->_leftHeight = v5;
  if ( v6 )
    v7 = v6->_height + 1;
  else
    v7 = 1;
  aNode->_rightHeight = v7;
  if ( v5 >= v7 )
    v7 = v5;
  aNode->_height = v7;
  if ( bNode->_left )
    v8 = bNode->_left->_height + 1;
  else
    v8 = 1;
  v9 = bNode->_right;
  bNode->_leftHeight = v8;
  if ( v9 )
    v10 = v9->_height + 1;
  else
    v10 = 1;
  bNode->_rightHeight = v10;
  if ( v8 >= v10 )
    v10 = v8;
  bNode->_height = v10;
  if ( cNode->_left )
    v11 = cNode->_left->_height + 1;
  else
    v11 = 1;
  v12 = cNode->_right;
  cNode->_leftHeight = v11;
  if ( v12 )
    v13 = v12->_height + 1;
  else
    v13 = 1;
  cNode->_rightHeight = v13;
  if ( v11 < v13 )
  {
    cNode->_height = v13;
    result = cNode;
  }
  else
  {
    cNode->_height = v11;
    result = cNode;
  }
  return result;
}

//----- (005421E0) --------------------------------------------------------  // acclient.c:369720
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::RightLeftRotate(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *aNode, AVLNode<unsigned long,unsigned long> *bNode, AVLNode<unsigned long,unsigned long> *cNode)
{
  AVL<unsigned long,unsigned long> *v4; // ebx@1
  int v5; // ecx@2
  AVLNode<unsigned long,unsigned long> *v6; // eax@4
  int v7; // eax@5
  int v8; // ecx@10
  AVLNode<unsigned long,unsigned long> *v9; // eax@12
  int v10; // eax@13
  int v11; // ecx@18
  AVLNode<unsigned long,unsigned long> *v12; // eax@20
  int v13; // eax@21
  AVLNode<unsigned long,unsigned long> *result; // eax@24

  v4 = this;
  AVL<unsigned long,unsigned long>::RightRotate(this, bNode, cNode, cNode->_right);
  AVL<unsigned long,unsigned long>::LeftRotate(v4, aNode, cNode, cNode->_left);
  if ( aNode->_left )
    v5 = aNode->_left->_height + 1;
  else
    v5 = 1;
  v6 = aNode->_right;
  aNode->_leftHeight = v5;
  if ( v6 )
    v7 = v6->_height + 1;
  else
    v7 = 1;
  aNode->_rightHeight = v7;
  if ( v5 >= v7 )
    v7 = v5;
  aNode->_height = v7;
  if ( bNode->_left )
    v8 = bNode->_left->_height + 1;
  else
    v8 = 1;
  v9 = bNode->_right;
  bNode->_leftHeight = v8;
  if ( v9 )
    v10 = v9->_height + 1;
  else
    v10 = 1;
  bNode->_rightHeight = v10;
  if ( v8 >= v10 )
    v10 = v8;
  bNode->_height = v10;
  if ( cNode->_left )
    v11 = cNode->_left->_height + 1;
  else
    v11 = 1;
  v12 = cNode->_right;
  cNode->_leftHeight = v11;
  if ( v12 )
    v13 = v12->_height + 1;
  else
    v13 = 1;
  cNode->_rightHeight = v13;
  if ( v11 < v13 )
  {
    cNode->_height = v13;
    result = cNode;
  }
  else
  {
    cNode->_height = v11;
    result = cNode;
  }
  return result;
}

//----- (005422C0) --------------------------------------------------------  // acclient.c:369790
int __thiscall AC1Legacy::PStringBase<char>::find_substring(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *str)
{
  AC1Legacy::PStringBase<char> *v2; // esi@1
  char *v3; // eax@1
  int result; // eax@2

  v2 = this;
  v3 = _strstr(this->m_buffer->m_data, str->m_buffer->m_data);
  if ( v3 )
    result = v3 - (char *)v2->m_buffer - 20;
  else
    result = -1;
  return result;
}

//----- (005422F0) --------------------------------------------------------  // acclient.c:369806
char __thiscall SmartArray<ClientNet::CReferralQueueEntry,1>::RemoveUnOrderedByIndex(SmartArray<ClientNet::CReferralQueueEntry,1> *this, unsigned int index)
{
  SmartArray<ClientNet::CReferralQueueEntry,1> *v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // ecx@2
  char result; // al@4
  char v6; // [sp+0h] [bp-28h]@3

  v2 = this;
  v3 = this->m_num;
  if ( index >= v3 )
  {
    result = 0;
  }
  else
  {
    v4 = v3 - 1;
    v2->m_num = v4;
    if ( index != v4 )
    {
      qmemcpy(&v2->m_data[index], &v2->m_data[v4], sizeof(v2->m_data[index]));
      qmemcpy(&v2->m_data[v2->m_num], &v6, sizeof(v2->m_data[v2->m_num]));
    }
    result = 1;
  }
  return result;
}

//----- (00542350) --------------------------------------------------------  // acclient.c:369835
void __thiscall CEchoResponseHeader::UpdateTimeSensitivePayload(CEchoResponseHeader *this)
{
  this->m_WireData.HoldingTime = Timer::local_time - this->m_LocalTimeConstructed;
}

//----- (00542360) --------------------------------------------------------  // acclient.c:369841
void __thiscall CLinkStatusAverages::CLinkStatusAverages(CLinkStatusAverages *this)
{
  *(_QWORD *)&this->m_LocalTimeOfSnapshot = 0i64;
  *(_QWORD *)&this->m_RoundTripDelays.m_CurTotal = 0i64;
  this->m_RoundTripDelays.m_nSamples = 0;
  this->m_RoundTripDelays.m_idxFirst = 0;
  *(_QWORD *)&this->m_nPktsSent.m_CurTotal = 0i64;
  this->m_nPktsSent.m_nSamples = 0;
  this->m_nPktsSent.m_idxFirst = 0;
  *(_QWORD *)&this->m_nPktsRetransmitted.m_CurTotal = 0i64;
  this->m_nPktsRetransmitted.m_nSamples = 0;
  this->m_nPktsRetransmitted.m_idxFirst = 0;
  *(_QWORD *)&this->m_nPktsReceived.m_CurTotal = 0i64;
  this->m_nPktsReceived.m_nSamples = 0;
  this->m_nPktsReceived.m_idxFirst = 0;
  *(_QWORD *)&this->m_nPktsNAKed.m_CurTotal = 0i64;
  this->m_nPktsNAKed.m_nSamples = 0;
  this->m_nPktsNAKed.m_idxFirst = 0;
  *(_QWORD *)&this->m_nBytesSent.m_CurTotal = 0i64;
  this->m_nBytesSent.m_nSamples = 0;
  this->m_nBytesSent.m_idxFirst = 0;
  *(_QWORD *)&this->m_nBytesReceived.m_CurTotal = 0i64;
  this->m_nBytesReceived.m_nSamples = 0;
  this->m_nBytesReceived.m_idxFirst = 0;
  *(_QWORD *)&this->m_TimeDiffs.m_CurTotal = 0i64;
  this->m_TimeDiffs.m_nSamples = 0;
  this->m_TimeDiffs.m_idxFirst = 0;
}

//----- (00542430) --------------------------------------------------------  // acclient.c:369871
CClientsideLoginStateHandler *__thiscall CClientsideLoginStateHandler::vector_deleting_destructor(CClientsideLoginStateHandler *this, unsigned int a2)
{
  CClientsideLoginStateHandler *v2; // esi@1

  v2 = this;
  CAsyncStateHandler::~CAsyncStateHandler((CAsyncStateHandler *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00542450) --------------------------------------------------------  // acclient.c:369883
bool __thiscall SharedNet::UseTime(SharedNet *this)
{
  SharedNet *v1; // esi@1
  DWORD v2; // eax@1
  SharedNetVtbl *v3; // edx@1
  bool v4; // bl@1
  long double now; // [sp+Ch] [bp-8h]@1

  v1 = this;
  memset(&this->m_packetStatsIncoming, 0, sizeof(this->m_packetStatsIncoming));
  now = *(double *)&Timer::cur_time;
  v2 = GetTickCount();
  v3 = v1->vfptr;
  v1->m_UseTime_TimeLimit.m_dwStart = v2;
  v3->BeforeCheckingSocket(v1);
  v4 = v1->vfptr->ReadAndProcessPackets(v1);
  (*(void (__thiscall **)(SharedNet *))&v1->vfptr->gap4[4])(v1);
  if ( GetTickCount() - v1->m_UseTime_TimeLimit.m_dwStart >= v1->m_UseTime_TimeLimit.m_dwInterval )
    v1->vfptr->OnUseTimeTimeout(v1);
  v1->lastDidUseTime_ = now;
  return v4;
}

//----- (005424E0) --------------------------------------------------------  // acclient.c:369907
char __thiscall SharedNet::ReadAndProcessPackets(SharedNet *this)
{
  SharedNet *v1; // esi@1
  CNetLayerPacket *v2; // edi@1
  int v3; // ebp@2
  bool v4; // sf@2
  char result; // al@8

  v1 = this;
  v2 = this->m_pIncomingPacket;
  if ( !v2 )
    goto LABEL_12;
  while ( 1 )
  {
    CNetLayerPacket::Clear(v2);
    v3 = v1->vfptr->ReadNextPacket(v1, v1->m_sockRead, v2);
    v4 = v3 < 0;
    if ( v3 <= 0 )
      break;
    if ( v2->m_bValid )
      v1->vfptr->ProcessPacket(v1, v2);
    if ( GetTickCount() - v1->m_UseTime_TimeLimit.m_dwStart >= v1->m_UseTime_TimeLimit.m_dwInterval )
    {
      v4 = v3 < 0;
      break;
    }
  }
  if ( !v4 )
    result = 1;
  else
LABEL_12:
    result = 0;
  return result;
}

//----- (00542560) --------------------------------------------------------  // acclient.c:369943
int __thiscall SharedNet::ReadNextPacket(SharedNet *this, unsigned int S, CNetLayerPacket *pkt)
{
  SharedNet *v3; // ebp@1
  int v4; // esi@1
  void (__cdecl *v5)(PacketInfo *, unsigned int); // eax@2
  unsigned int v6; // ecx@3
  int recvAddrSize; // [sp+10h] [bp-2Ch]@1
  int v9; // [sp+14h] [bp-28h]@3
  __int16 *v10; // [sp+18h] [bp-24h]@3
  int v11; // [sp+1Ch] [bp-20h]@3
  ProtoHeader *v12; // [sp+20h] [bp-1Ch]@3
  int *v13; // [sp+24h] [bp-18h]@3
  int v14; // [sp+28h] [bp-14h]@3
  int v15; // [sp+2Ch] [bp-10h]@3
  int v16; // [sp+30h] [bp-Ch]@3
  int v17; // [sp+34h] [bp-8h]@3
  ProtoHeader *v18; // [sp+38h] [bp-4h]@3

  v3 = this;
  recvAddrSize = 16;
  v4 = recvfrom(S, (char *)&pkt->m_Hdr, 65504, 0, (struct sockaddr *)&pkt->m_Addr, &recvAddrSize);
  if ( v4 > 0 )
  {
    v3->vfptr->AddToPerfCounter(v3, BytesReceivedCounter, v4);
    v5 = v3->m_Loggers.pfnRecvLogger;
    if ( v5 )
    {
      v10 = &pkt->m_Addr.sin_family;
      v13 = &v17;
      v6 = v3->m_Loggers.dwUserLoggingData;
      v15 = recvAddrSize;
      v9 = 40;
      v11 = v4;
      v12 = &pkt->m_Hdr;
      v14 = 1;
      v16 = 2;
      v18 = &pkt->m_Hdr;
      v17 = v4;
      v5((PacketInfo *)&v9, v6);
    }
  }
  if ( v4 >= 20 )
  {
    pkt->m_Hdr.checksum_ -= SharedNet::ChecksumHeader(&pkt->m_Hdr);
    pkt->m_Iter.m_dwCurOfs = 0;
    pkt->m_Iter.m_cbBufSize = v4 - 20;
    pkt->m_bValid = 1;
    return v4;
  }
  if ( WSAGetLastError() != 10035 )
    return v4;
  return 0;
}

//----- (00542660) --------------------------------------------------------  // acclient.c:369998
void __stdcall SharedNet::HandlePak(COnePrimHeader<16384,1,unsigned long> *pPakHdr, CNetLayerPacket *pkt)
{
  unsigned int v3; // esi@1
  RecipientData *v4; // edi@1
  unsigned __int16 v5; // ST00_2@3
  PacketController *v6; // eax@3

  v3 = pPakHdr->m_Prim;
  v4 = pkt->m_pRecip;
  if ( v3 && v4 )
  {
    v5 = pkt->m_Hdr.recID_;
    v6 = PacketController::Instance();
    if ( PacketController::GetRecipient(v6, v5) )
      RecipientData::QueueFlush(v4, v3);
  }
}

//----- (005426A0) --------------------------------------------------------  // acclient.c:370017
void __stdcall SharedNet::HandleNak(CSeqIDListHeader<4096,33> *pNakHdr, CNetLayerPacket *pkt)
{
  unsigned __int16 v3; // si@1
  unsigned __int16 v4; // ST00_2@1
  PacketController *v5; // eax@1
  PacketController *v6; // eax@2
  RecipientData *v7; // eax@2

  v3 = pkt->m_Hdr.recID_;
  v4 = pkt->m_Hdr.recID_;
  v5 = PacketController::Instance();
  if ( PacketController::GetRecipient(v5, v4) )
  {
    v6 = PacketController::Instance();
    v7 = PacketController::GetRecipient(v6, v3);
    RecipientData::ProcessNaks(v7, pNakHdr->m_IDs[0], &pNakHdr->m_IDs[1]);
  }
}

//----- (005426F0) --------------------------------------------------------  // acclient.c:370037
char __thiscall SharedNet::ProcessConnections(SharedNet *this)
{
  SharedNet *v1; // ebx@1
  ReceiverData *v2; // esi@1
  ReceiverData *v3; // edi@3

  v1 = this;
  v2 = this->connectionsHead_;
  if ( v2 )
  {
    do
    {
      if ( GetTickCount() - v1->m_UseTime_TimeLimit.m_dwStart >= v1->m_UseTime_TimeLimit.m_dwInterval )
        break;
      v3 = v2->next_;
      if ( v2->m_RecID )
        v1->vfptr->ProcessConnection(v1, v2);
      v2 = v3;
    }
    while ( v3 );
  }
  return 1;
}

//----- (00542740) --------------------------------------------------------  // acclient.c:370062
signed int __stdcall SharedNet::SetNakState(ReceiverData *recData)
{
  signed int result; // eax@2

  if ( recData->m_SeqIDsWeNAKed._currNum )
  {
    recData->m_NakState = 1;
    result = 1;
  }
  else
  {
    recData->m_NakState = 2;
    result = 2;
  }
  return result;
}

//----- (00542770) --------------------------------------------------------  // acclient.c:370080
void __thiscall SharedNet::AddToPerfCounter(SharedNet *this, NetPerfCounter WhichCounter, int n)
{
  SharedNet *v3; // esi@1
  PerfMonCounter<unsigned __int64> *v4; // ecx@2
  PerfMonCounter<unsigned __int64> *v5; // esi@4
  int v6; // ecx@14

  v3 = this;
  switch ( WhichCounter )
  {
    case 2:
      ++this->m_packetStatsIncoming.cBad;
      v4 = this->m_pBadPacketsReceivedCounter;
      if ( v4 )
      {
        ((void (*)(void))v4->vfptr[3].__vecDelDtor)();
        ((void (*)(void))v3->m_pBadPacketsReceivedRawCounter->vfptr[3].__vecDelDtor)();
      }
      return;
    case 0:
      v5 = this->m_pBytesSentCounter;
      goto LABEL_13;
    case 1:
      v5 = this->m_pBytesReceivedCounter;
      goto LABEL_13;
    case 3:
      ++this->m_packetStatsIncoming.cHeaderOnly;
      break;
    case 4:
      ++this->m_packetStatsIncoming.cHeaderAndData;
      break;
    case 5:
      ++this->m_packetStatsIncoming.cDataOnly;
      break;
    case 6:
      ++this->m_packetStatsIncoming.cAck;
      break;
    case 7:
      ++this->m_packetStatsIncoming.cNak;
      break;
    case 8:
      ++this->m_packetStatsIncoming.cPak;
      break;
    case 10:
      v5 = this->m_pPacketsRetransmittedCounter;
LABEL_13:
      if ( v5 )
      {
        v6 = LODWORD(v5->m_counter);
        LODWORD(v5->m_counter) = n + v6;
        HIDWORD(v5->m_counter) += ((unsigned __int64)n >> 32) + __CFADD__(n, v6);
      }
      break;
    case 11:
      ++this->m_packetStatsIncoming.cMisc;
      break;
    default:
      return;
  }
}

//----- (00542860) --------------------------------------------------------  // acclient.c:370142
bool __thiscall ClientNet::UseTime(ClientNet *this)
{
  SharedNet *v1; // esi@1

  v1 = (SharedNet *)this;
  if ( this->m_LogonData.bMyTurn )
    ((void (*)(void))this->vfptr[1].ProcessConnection)();
  return SharedNet::UseTime(v1);
}

//----- (00542880) --------------------------------------------------------  // acclient.c:370153
void __thiscall ClientNet::AddToPerfCounter(ClientNet *this, NetPerfCounter WhichCounter, int n)
{
  switch ( WhichCounter )
  {
    case 0:
      this->m_CurrentLinkStatus.nBytesSent += n;
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
    case 1:
      this->m_CurrentLinkStatus.nBytesReceived += n;
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
    case 6:
      this->m_CurrentLinkStatus.nPktsNAKed += n;
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
    case 10:
      this->m_CurrentLinkStatus.nPktsRetransmitted += n;
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
    case 3:
    case 4:
    case 5:
      this->m_CurrentLinkStatus.nPktsReceived += n;
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
    case 9:
      this->m_CurrentLinkStatus.nPktsSent += n;
      goto LABEL_8;
    default:
LABEL_8:
      SharedNet::AddToPerfCounter((SharedNet *)&this->vfptr, WhichCounter, n);
      break;
  }
}

//----- (00542940) --------------------------------------------------------  // acclient.c:370190
CPackObjHeader<NetError,1048576,7> *__thiscall CPackObjHeader<NetError,1048576,7>::vector_deleting_destructor(CPackObjHeader<NetError,1048576,7> *this, unsigned int a2)
{
  CPackObjHeader<NetError,1048576,7> *v2; // esi@1
  char *v3; // ST00_4@1

  v2 = this;
  v3 = this->m_pAdoptedData;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,1048576,7>::vftable;
  operator delete(v3);
  v2->m_pAdoptedData = 0;
  v2->m_Obj.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA084: using guessed type int (__thiscall *CPackObjHeader<NetError,1048576,7>::vftable)(void *, char);

//----- (00542980) --------------------------------------------------------  // acclient.c:370211
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::Rebalance(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *problemNode)
{
  AVLNode<unsigned long,unsigned long> *v2; // edx@2
  int v3; // esi@2
  AVLNode<unsigned long,unsigned long> *result; // eax@3
  AVLNode<unsigned long,unsigned long> *v5; // [sp-8h] [bp-14h]@2
  AVLNode<unsigned long,unsigned long> *v6; // [sp-8h] [bp-14h]@6
  AVLNode<unsigned long,unsigned long> *v7; // [sp-4h] [bp-10h]@2
  AVLNode<unsigned long,unsigned long> *v8; // [sp-4h] [bp-10h]@6

  if ( problemNode->_rightHeight - problemNode->_leftHeight == 2 )
  {
    v2 = problemNode->_right;
    v7 = v2->_left;
    v3 = v2->_rightHeight - v2->_leftHeight;
    v5 = problemNode->_right;
    if ( v3 == 1 || v3 != -1 )
      result = AVL<unsigned long,unsigned long>::LeftRotate(this, problemNode, v5, v7);
    else
      result = AVL<unsigned long,unsigned long>::RightLeftRotate(this, problemNode, v5, v7);
  }
  else
  {
    v8 = problemNode->_left->_right;
    v6 = problemNode->_left;
    if ( problemNode->_left->_rightHeight - problemNode->_left->_leftHeight == 1 )
      result = AVL<unsigned long,unsigned long>::LeftRightRotate(this, problemNode, v6, v8);
    else
      result = AVL<unsigned long,unsigned long>::RightRotate(this, problemNode, v6, v8);
  }
  return result;
}

//----- (005429F0) --------------------------------------------------------  // acclient.c:370245
int __cdecl TimeStampUtils::OverflowCompare(unsigned __int16 _a, unsigned __int16 _b)
{
  int result; // eax@2
  unsigned __int16 v3; // dx@3

  if ( _a == _b )
  {
    result = 0;
  }
  else
  {
    v3 = _a - _b;
    result = 1;
    if ( _a < _b )
    {
      v3 = _b - _a;
      result = -1;
    }
    if ( v3 > 0x7FFFu )
      result = -result;
  }
  return result;
}

//----- (00542A30) --------------------------------------------------------  // acclient.c:370270
void __thiscall SmartArray<ClientNet::CReferralQueueEntry,1>::Reset(SmartArray<ClientNet::CReferralQueueEntry,1> *this)
{
  SmartArray<ClientNet::CReferralQueueEntry,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  int v7; // edx@5
  void *v8; // edi@6
  char v9; // [sp+8h] [bp-28h]@6

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = v4;
      v7 = v5 + 1;
      do
      {
        v8 = &v1->m_data[v6];
        --v6;
        --v7;
        qmemcpy(v8, &v9, 0x28u);
      }
      while ( v7 );
    }
  }
}

//----- (00542AA0) --------------------------------------------------------  // acclient.c:370313
void __thiscall AC1Legacy::PStringBase<unsigned short>::allocate_ref_buffer(AC1Legacy::PStringBase<unsigned short> *this, unsigned int len)
{
  AC1Legacy::PStringBase<unsigned short> *v2; // edi@1
  unsigned int v3; // esi@1
  void *v4; // eax@3

  v2 = this;
  v3 = 1;
  do
    v3 *= 2;
  while ( len > v3 );
  v4 = operator new[](2 * v3 + 24);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 1;
    *(_DWORD *)v4 = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)v4 + 2) = 1;
    *((_DWORD *)v4 + 3) = 1;
    *((_DWORD *)v4 + 4) = -1;
    *((_WORD *)v4 + 10) = 0;
    v2->m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)v4;
    *((_DWORD *)v4 + 2) = len + 1;
    v2->m_buffer->m_size = v3 + 1;
  }
  else
  {
    v2->m_buffer = 0;
    v8 = len + 1;
    v2->m_buffer->m_size = v3 + 1;
  }
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (00542B20) --------------------------------------------------------  // acclient.c:370347
COptionalHeader *__cdecl CEchoResponseHeader::CreateFromData(float EchoRequestPayload)
{
  COptionalHeader *result; // eax@1
  unsigned int v2; // esi@2

  result = (COptionalHeader *)operator new(0x28u);
  if ( result )
  {
    result->m_cRef = 1;
    result->m_dwMask = 0x4000000;
    result->m_Flags = 24;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 8;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CEchoResponseHeader::vftable;
    v2 = HIDWORD(Timer::local_time);
    result[1].m_dwMask = LODWORD(Timer::local_time);
    result[1].m_Flags = v2;
    *(float *)&result[1].vfptr = EchoRequestPayload;
    result[1].m_cRef = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA078: using guessed type int (__thiscall *CEchoResponseHeader::vftable)(void *, char);

//----- (00542BA0) --------------------------------------------------------  // acclient.c:370389
NetPacket *__cdecl NetPacket::CreateForSend(unsigned __int16 recip)
{
  NetPacket *result; // eax@1

  result = (NetPacket *)operator new(0x124u);
  if ( result )
  {
    result->next_ = 0;
    result->numSpecialFrags_ = 0;
    result->numFrags_ = 0;
    result->recipient_ = 0;
    result->realPriority_ = 0;
    result->size_ = 0;
    result->seqNum_ = 0;
    result->cryptoKey_ = 0;
    result->checksum_ = 0;
    result->flags_ = 0;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)NetPacket::vftable;
    result->recipient_ = recip;
  }
  else
  {
    result = 0;
    v108 = recip;
  }
  return result;
}
// 7CA080: using guessed type int (__thiscall *NetPacket::vftable[2])(void *, char);

//----- (00542C40) --------------------------------------------------------  // acclient.c:370432
void __thiscall NetPacket::~NetPacket(NetPacket *this)
{
  NetPacket *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  char *v4; // ebp@2
  int v5; // edi@3
  unsigned int v6; // ebp@7
  int v7; // ebx@8
  int v8; // edi@9

  v1 = this;
  v2 = this->numSpecialFrags_;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)NetPacket::vftable;
  if ( v2 )
  {
    v4 = (char *)this->specialFragList_;
    do
    {
      v5 = *(_DWORD *)v4;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v4 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      ++v3;
      v4 += 4;
    }
    while ( v3 < v1->numSpecialFrags_ );
  }
  v6 = 0;
  if ( v1->numFrags_ )
  {
    v7 = (int)v1->fragList_;
    do
    {
      v8 = *(_DWORD *)v7;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v7 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      ++v6;
      v7 += 4;
    }
    while ( v6 < v1->numFrags_ );
  }
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7CA080: using guessed type int (__thiscall *NetPacket::vftable[2])(void *, char);

//----- (00542CE0) --------------------------------------------------------  // acclient.c:370480
void __thiscall SharedNet::~SharedNet(SharedNet *this)
{
  SharedNet *v1; // esi@1
  PortalDH *v2; // edi@1
  CNetLayerPacket *v3; // edi@3
  PerfMonCounter<unsigned __int64> *v4; // edi@8
  PerfMonCounter<unsigned __int64> *v5; // edi@13
  PerfMonCounter<unsigned __int64> *v6; // edi@18
  PerfMonCounter<unsigned __int64> *v7; // edi@23
  PerfMonCounter<unsigned __int64> *v8; // edi@28
  ReceiverData *v9; // edi@33
  signed int v10; // ebx@33

  v1 = this;
  v2 = this->dh_;
  this->vfptr = (SharedNetVtbl *)&SharedNet::vftable;
  if ( v2 )
  {
    AC1Legacy::vlong::~vlong(&v2->shared_prime_);
    AC1Legacy::vlong::~vlong(&v2->shared_base_);
    operator delete(v2);
  }
  v3 = v1->m_pIncomingPacket;
  v1->dh_ = 0;
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
    v1->m_pIncomingPacket = 0;
  }
  v4 = v1->m_pBytesSentCounter;
  if ( v4 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    v1->m_pBytesSentCounter = 0;
  }
  v5 = v1->m_pBytesReceivedCounter;
  if ( v5 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
    v1->m_pBytesReceivedCounter = 0;
  }
  v6 = v1->m_pBadPacketsReceivedCounter;
  if ( v6 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
    v1->m_pBadPacketsReceivedCounter = 0;
  }
  v7 = v1->m_pBadPacketsReceivedRawCounter;
  if ( v7 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v7, 1u);
    v1->m_pBadPacketsReceivedRawCounter = 0;
  }
  v8 = v1->m_pPacketsRetransmittedCounter;
  if ( v8 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
    v1->m_pPacketsRetransmittedCounter = 0;
  }
  v9 = (ReceiverData *)&v1->connectionsHead_;
  v10 = 256;
  do
  {
    v9 = (ReceiverData *)((char *)v9 - 136);
    ReceiverData::~ReceiverData(v9);
    --v10;
  }
  while ( v10 );
  NetInitializer::~NetInitializer();
}
// 7CA090: using guessed type void (__thiscall *SharedNet::vftable)(SharedNet *this, NetPerfCounter WhichCounter, int);

//----- (00542E30) --------------------------------------------------------  // acclient.c:370559
bool __thiscall SharedNet::SplitPacketData(SharedNet *this, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v2; // edi@1
  ReceiverData *v3; // eax@1
  SharedNet *v4; // ebp@1
  bool v5; // bl@1
  char v6; // dl@3
  unsigned int v7; // eax@5
  unsigned int v8; // esi@8
  int v9; // ecx@9
  unsigned int v10; // ebp@9
  int v11; // eax@10
  unsigned int v12; // ecx@22
  unsigned int v13; // eax@22
  BlobFrag *v14; // eax@24
  BlobFrag *v15; // esi@24
  unsigned int v16; // ecx@29
  unsigned int v17; // eax@29
  char v18; // al@32
  CNetLayerPacket *v19; // esi@36
  bool result; // al@39
  unsigned int v21; // eax@43
  SharedNet *v22; // [sp+10h] [bp-4h]@1

  v2 = pkt;
  v3 = pkt->m_pRecv;
  v4 = this;
  v22 = this;
  v5 = 1;
  if ( v3 && v3->m_RecID )
  {
    v6 = 1;
    LOBYTE(pkt) = 1;
  }
  else
  {
    LOBYTE(pkt) = 0;
    v6 = 0;
  }
  v7 = v2->m_Hdr.header_;
  if ( !(v7 & 0xFFFFFF00) )
  {
LABEL_8:
    v8 = v2->numSpecialFrags_;
    if ( v8 )
    {
      v9 = (int)v2->specialFragList_;
      v10 = v2->numSpecialFrags_;
      do
      {
        v11 = *(_DWORD *)(*(_DWORD *)v9 + 12);
        if ( v11 & 2 && (v8 > 1 || v2->numFrags_) )
          v5 = 0;
        if ( !v6 && !(v11 & 4) )
          v5 = 0;
        v9 += 4;
        --v10;
      }
      while ( v10 );
      v4 = v22;
    }
    if ( v5 && v2->m_Hdr.header_ & 4 )
    {
      if ( v6 )
      {
        while ( 1 )
        {
          v12 = v2->m_Iter.m_dwCurOfs;
          v13 = v2->m_Iter.m_cbBufSize;
          if ( v12 >= v13 || v13 - v12 <= 0x10 )
            break;
          v14 = BlobFrag::CreateForRecv(&v2->m_Iter);
          v15 = v14;
          if ( !v14 )
          {
            v5 = 0;
            break;
          }
          NetPacket::AddFrag((NetPacket *)&v2->vfptr, v14, 0, 0);
          if ( !InterlockedDecrement((volatile LONG *)&v15->m_cRef) )
            v15->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v15, 1u);
        }
        v4 = v22;
      }
      else
      {
        v5 = 0;
      }
    }
    goto LABEL_29;
  }
  v5 = COptionalHeaderFactory::AddOptionalHeadersToPacket(v7, (NetPacket *)&v2->vfptr, &v2->m_Iter);
  if ( v5 )
  {
    v6 = (char)pkt;
    goto LABEL_8;
  }
LABEL_29:
  v16 = v2->m_Iter.m_dwCurOfs;
  v17 = v2->m_Iter.m_cbBufSize;
  if ( v16 < v17 && v17 != v16 )
    v5 = 0;
  v18 = (v2->m_Hdr.header_ >> 1) & 1;
  if ( v18 != ((v2->flags_ >> 2) & 1) || v18 && !v2->m_Hdr.seqID_ )
  {
    v5 = 0;
LABEL_36:
    pkt = (CNetLayerPacket *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    NetUtils::GetIPString(&v2->m_Addr, (AC1Legacy::PStringBase<char> *)&pkt, 0);
    v19 = pkt;
    if ( !InterlockedDecrement((volatile LONG *)&pkt->m_cRef) && v19 )
      v19->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v19, 1u);
    goto LABEL_39;
  }
  if ( !v5 )
    goto LABEL_36;
  if ( v2->checksum_ != v2->m_Hdr.checksum_ )
  {
    v5 = 0;
LABEL_39:
    v4->vfptr->AddToPerfCounter(v4, BadPacketsReceivedCounter, 1);
    return v5;
  }
  v2->seqNum_ = v2->m_Hdr.seqID_;
  v21 = v2->numFrags_;
  v2->recipient_ = v2->m_Hdr.recID_;
  if ( !v21 )
    goto LABEL_54;
  if ( v2->numSpecialFrags_ )
  {
    v4->vfptr->AddToPerfCounter(v4, OptionalHeadersAndDataPacketsReceivedCounter, 1);
    return v5;
  }
  if ( v21 )
  {
    v4->vfptr->AddToPerfCounter(v4, DataOnlyPacketsReceivedCounter, 1);
    result = v5;
  }
  else
  {
LABEL_54:
    if ( v2->numSpecialFrags_ )
      v4->vfptr->AddToPerfCounter(v4, OptionalHeadersOnlyPacketsReceivedCounter, 1);
    result = v5;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00543070) --------------------------------------------------------  // acclient.c:370710
char __thiscall SharedNet::ProcessOptionalHeader(SharedNet *this, COptionalHeader *pHdr, CNetLayerPacket *pkt)
{
  unsigned int v3; // eax@1
  COptionalHeader *v5; // eax@14
  ReferenceCountTemplate<1048576,0> *v6; // esi@14
  COptionalHeader *v7; // ST04_4@14
  unsigned __int16 v8; // ST00_2@14
  PacketController *v9; // eax@14

  v3 = pHdr->m_dwMask;
  if ( v3 <= 0x200000 )
  {
    if ( v3 == 0x200000 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->SetConnectionState)(pkt->m_Hdr.recID_, 6);
      return 1;
    }
    if ( v3 == 4096 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->HandleNak)(pHdr, pkt);
      return 1;
    }
    if ( v3 == 0x2000 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->HandleEmptyAck)(pHdr, pkt);
      return 1;
    }
    if ( v3 == 0x4000 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->HandlePak)(pHdr, pkt);
      return 1;
    }
    return 0;
  }
  if ( v3 == 0x1000000 )
  {
    ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->HandleTimeSynch)(pHdr, pkt);
  }
  else
  {
    if ( v3 == 0x2000000 )
    {
      v5 = CEchoResponseHeader::CreateFromData(*(float *)&pHdr[1].vfptr);
      v6 = (ReferenceCountTemplate<1048576,0> *)v5;
      v7 = v5;
      v8 = pkt->recipient_;
      v9 = PacketController::Instance();
      PacketController::EnqueueOptionalHeader(v9, v8, v7);
      ReferenceCountTemplate<1048576,0>::Release(v6);
      return 1;
    }
    if ( v3 != 0x4000000 )
      return 0;
  }
  return 1;
}

//----- (00543160) --------------------------------------------------------  // acclient.c:370768
char __thiscall SharedNet::SendOptionalHeader(SharedNet *this, COptionalHeader *pHdr, sockaddr_in *addr, ReceiverData *pRecv)
{
  unsigned int v4; // ecx@1
  char result; // al@1
  NetPacket *v6; // esi@7
  unsigned int v7; // ecx@7
  unsigned __int16 v8; // cx@8
  char v9; // bl@10
  SharedNet *v10; // [sp+8h] [bp-18h]@1
  ProtoHeader Hdr; // [sp+Ch] [bp-14h]@7

  v10 = this;
  v4 = pHdr->m_Flags;
  result = 0;
  if ( !(v4 & 0x10) && v4 & 1 && v4 & 2 && !(v4 & 8) && (v4 & 4 || pRecv) )
  {
    v6 = NetPacket::CreateForSend(0);
    NetPacket::AddOptionalHeader(v6, pHdr);
    v7 = pHdr->m_dwMask;
    Hdr.seqID_ = 0;
    Hdr.header_ = 0;
    Hdr.checksum_ = 0;
    Hdr.datalen_ = 0;
    Hdr.recID_ = 0;
    Hdr.interval_ = 0;
    Hdr.iteration_ = 0;
    Hdr.datalen_ = LOWORD(v6->size_);
    Hdr.header_ = v7;
    Hdr.checksum_ = v6->checksum_;
    Hdr.seqID_ = 0;
    if ( pRecv )
    {
      v8 = pRecv->iteration_;
      Hdr.recID_ = pRecv->m_NetID;
      Hdr.iteration_ = v8;
    }
    else
    {
      Hdr.recID_ = 0;
      Hdr.iteration_ = 0;
    }
    v9 = SharedNet::SendPacket(v10, v6, &Hdr, addr);
    ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v6->vfptr);
    result = v9;
  }
  return result;
}

//----- (00543250) --------------------------------------------------------  // acclient.c:370817
char __cdecl ParseInterfaceString(AC1Legacy::PStringBase<char> st, in_addr *NetNumber, in_addr *NetMask)
{
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  in_addr *v4; // edi@1
  in_addr *v5; // eax@1
  in_addr *v6; // ST0C_4@1
  bool v7; // bl@3
  u_long v9; // eax@8
  unsigned int v10; // ecx@11
  const char *p; // [sp+0h] [bp-4h]@1

  v3 = st.m_buffer;
  v4 = NetMask;
  p = st.m_buffer->m_data;
  v5 = NetNumber;
  v6 = NetNumber;
  NetMask->S_un.S_addr = 0;
  v5->S_un.S_addr = 0;
  if ( !ParseInAddr(&p, v6) )
    goto LABEL_26;
  if ( *p != 47 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    return 0;
  }
  ++p;
  v7 = _strchr(p, 46) == 0;
  if ( !ParseInAddr(&p, v4) )
  {
LABEL_26:
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    {
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
      return 0;
    }
    return 0;
  }
  if ( v7 )
  {
    v9 = ntohl(v4->S_un.S_addr) >> 24;
    if ( (v9 & 0x80000000) != 0 || (signed int)v9 > 32 )
    {
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&st);
      return 0;
    }
    v4->S_un.S_addr = 0;
    if ( (signed int)v9 > 0 )
    {
      v10 = 0;
      do
      {
        v10 = (v10 >> 1) | 0x80000000;
        --v9;
      }
      while ( v9 );
      v4->S_un.S_addr = v10;
    }
    v4->S_un.S_addr = htonl(v4->S_un.S_addr);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return 1;
}

//----- (00543380) --------------------------------------------------------  // acclient.c:370883
void __thiscall ClientNet::EndState(ClientNet *this, NetError *FailureReason)
{
  ClientNet *v2; // esi@1
  CAsyncStateHandler *v3; // edi@1
  int v4; // eax@1

  v2 = this;
  v3 = (CAsyncStateHandler *)&this->vfptr;
  v4 = CAsyncStateHandler::GetContextData(
         (CAsyncStateHandler *)&this->vfptr,
         this->m_LogonData.hCurrentContext,
         this->m_idxFailureReason);
  *(_DWORD *)(v4 + 4) = FailureReason->m_stringID;
  *(_DWORD *)(v4 + 8) = FailureReason->m_tableID;
  v2->m_LogonData.bMyTurn = 0;
  if ( FailureReason->m_stringID != ID_NetError_None.m_stringID
    || FailureReason->m_tableID != ID_NetError_None.m_tableID )
    CAsyncStateHandler::EndStateFailed(v3, v2->m_LogonData.hCurrentContext);
  else
    CAsyncStateHandler::EndStateOK(v3, v2->m_LogonData.hCurrentContext, 2147483646);
}

//----- (00543400) --------------------------------------------------------  // acclient.c:370906
void __thiscall ClientNet::AbortConnection(ClientNet *this)
{
  if ( this->m_LogonData.hCurrentContext.m_id != INVALID_ASYNCCONTEXT_7.m_id )
    ClientNet::EndState(this, &ID_NetError_AbortedHandshake);
}

//----- (00543420) --------------------------------------------------------  // acclient.c:370913
char __thiscall ClientNet::VerifyHeader(ClientNet *this, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v2; // ebx@1
  unsigned __int16 v3; // ax@1
  sockaddr_in *v4; // esi@1
  char *v5; // edi@2
  char result; // al@7
  int v7; // eax@8
  CNetLayerPacket *v8; // esi@17
  AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > v9; // [sp+0h] [bp-4h]@1

  v9.m_buffer = (AC1Legacy::PSRefBuffer<char> *)this;
  v2 = pkt;
  v3 = pkt->m_Hdr.recID_;
  v4 = &pkt->m_Addr;
  if ( v3 >= 0x100u )
  {
    ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->AddToPerfCounter)(2, 1);
    pkt = (CNetLayerPacket *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&pkt, 0);
    v8 = pkt;
    if ( !InterlockedDecrement((volatile LONG *)&pkt->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v8, 1u);
    result = 0;
  }
  else
  {
    v5 = (char *)this + 136 * v3;
    if ( *((_WORD *)v5 + 16) != 0 )
    {
      if ( *((_DWORD *)v5 + 21) != pkt->m_Addr.sin_addr.S_un.S_addr )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(&v9);
        NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&v9.m_buffer, 0);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&pkt);
        NetUtils::GetIPString((sockaddr_in *)v5 + 5, (AC1Legacy::PStringBase<char> *)&pkt, 0);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pkt);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v9);
        return 0;
      }
      v7 = TimeStampUtils::OverflowCompare(pkt->m_Hdr.iteration_, *((_WORD *)v5 + 17));
      if ( v7 < 0 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&pkt);
        NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&pkt, 0);
        goto LABEL_15;
      }
      if ( v7 > 0 && !(v2->m_Hdr.header_ & 0x40000) )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&pkt);
        NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&pkt, 0);
        goto LABEL_15;
      }
      if ( v2->m_Hdr.datalen_ > 0xFFE0u )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&pkt);
        NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&pkt, 0);
        goto LABEL_15;
      }
    }
    else if ( pkt->m_Hdr.seqID_ )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->AddToPerfCounter)(2, 1);
      pkt = (CNetLayerPacket *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      NetUtils::GetIPString(v4, (AC1Legacy::PStringBase<char> *)&pkt, 0);
LABEL_15:
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pkt);
      return 0;
    }
    result = 1;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005435D0) --------------------------------------------------------  // acclient.c:370991
void __thiscall ClientNet::NotifyPluginsOfStatusChange(ClientNet *this, NetStatus Status, int Param1, int Param2)
{
  ClientNet *v4; // edi@1
  unsigned int v5; // esi@1
  CPluginPrototype *v6; // ecx@2

  v4 = this;
  v5 = this->m_Plugins.m_num;
  while ( v5 )
  {
    v6 = v4->m_Plugins.m_data[v5-- - 1];
    ((void (__stdcall *)(NetStatus, int, int))v6->vfptr[1].OnPluggedIn)(Status, Param1, Param2);
  }
}

//----- (00543620) --------------------------------------------------------  // acclient.c:371007
void __thiscall ClientNet::NotifyPluginsOfHeartbeat(ClientNet *this)
{
  ClientNet *v1; // edi@1
  unsigned int v2; // esi@1
  CPluginPrototype *v3; // ecx@2

  v1 = this;
  v2 = this->m_Plugins.m_num;
  while ( v2 )
  {
    v3 = v1->m_Plugins.m_data[v2-- - 1];
    ((void (__stdcall *)(int))v3->vfptr[1].__vecDelDtor)(&v1->m_LinkStatusAverages);
  }
}

//----- (00543660) --------------------------------------------------------  // acclient.c:371023
COptionalHeader *__cdecl COnePrimHeader<134217728,16,CFlowStruct>::CreateFromData(CFlowStruct Prim)
{
  COptionalHeader *result; // eax@1
  COptionalHeader *v2; // ecx@2

  result = (COptionalHeader *)operator new(0x20u);
  if ( result )
  {
    v2 = result + 1;
    v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)Prim.cbDataRecvd;
    result->m_cRef = 1;
    result->m_dwMask = 0x8000000;
    result->m_Flags = 16;
    result->m_pData = (char *)&result[1];
    result->m_cbData = 6;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    LOWORD(v2->m_cRef) = Prim.interval;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005436B0) --------------------------------------------------------  // acclient.c:371050
COptionalHeader *__cdecl CPackObjHeader<NetError,1048576,7>::CreateFromData(NetError *ConstObj)
{
  NetError *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // esi@1
  NetError *v4; // eax@1
  PackObjVtbl *v5; // edx@1
  void *v6; // edi@1
  COptionalHeader *result; // eax@3

  v1 = ConstObj;
  v2 = ((int (__thiscall *)(NetError *))ConstObj->vfptr->GetPackSize)(ConstObj);
  v3 = v2;
  v4 = (NetError *)operator new[](v2);
  v5 = v1->vfptr;
  v6 = v4;
  ConstObj = v4;
  if ( ((int (__thiscall *)(NetError *, NetError **, unsigned int))v5->Pack)(v1, &ConstObj, v3) != v3 )
  {
    operator delete(v6);
    return 0;
  }
  result = (COptionalHeader *)operator new(0x30u);
  if ( !result )
    return 0;
  result->m_pData = (char *)v6;
  result[1].vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)v6;
  result->m_cbData = v3;
  result[1].m_cRef = v3;
  result->m_cRef = 1;
  result->m_dwMask = 0x100000;
  result->m_Flags = 7;
  result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&CPackObjHeader<NetError,1048576,7>::vftable;
  result[1].m_dwMask = (unsigned int)&NetError::vftable;
  return result;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7CA084: using guessed type int (__thiscall *CPackObjHeader<NetError,1048576,7>::vftable)(void *, char);

//----- (00543730) --------------------------------------------------------  // acclient.c:371090
COptionalHeader *__cdecl COnePrimHeader<2048,1073741922,CReferralStruct>::CreateFromData(CReferralStruct Prim)
{
  COptionalHeader *result; // eax@1

  result = (COptionalHeader *)operator new(0x38u);
  if ( result )
  {
    result->m_pData = (char *)&result[1];
    qmemcpy(&result[1], &Prim, 0x20u);
    result->m_cRef = 1;
    result->m_dwMask = 2048;
    result->m_Flags = 1073741922;
    result->m_cbData = 32;
    result->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00543780) --------------------------------------------------------  // acclient.c:371114
void __thiscall AVL<unsigned long,unsigned long>::ReBalanceTree(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *curr, AVLNode<unsigned long,unsigned long> *limit)
{
  AVLNode<unsigned long,unsigned long> *v3; // esi@1
  AVL<unsigned long,unsigned long> *i; // edi@1
  int v5; // ecx@3
  AVLNode<unsigned long,unsigned long> *v6; // eax@5
  int v7; // eax@6
  int v8; // edx@8

  v3 = curr;
  for ( i = this; v3 != limit; v3 = v3->_parent )
  {
    if ( v3->_left )
      v5 = v3->_left->_height + 1;
    else
      v5 = 1;
    v6 = v3->_right;
    v3->_leftHeight = v5;
    if ( v6 )
      v7 = v6->_height + 1;
    else
      v7 = 1;
    v3->_rightHeight = v7;
    v8 = v5;
    if ( v5 < v7 )
      v8 = v7;
    v3->_height = v8;
    if ( abs(v7 - v5) == 2 )
      AVL<unsigned long,unsigned long>::Rebalance(i, v3);
  }
}

//----- (005437F0) --------------------------------------------------------  // acclient.c:371147
AVLNode<unsigned long,unsigned long> *__thiscall AVL<unsigned long,unsigned long>::FindSuccessor(AVL<unsigned long,unsigned long> *this, AVLNode<unsigned long,unsigned long> *parent, AVLNode<unsigned long,unsigned long> *curr)
{
  AVLNode<unsigned long,unsigned long> *v3; // esi@1
  AVLNode<unsigned long,unsigned long> *v4; // eax@1
  AVLNode<unsigned long,unsigned long> *v5; // edx@2
  AVLNode<unsigned long,unsigned long> *v6; // eax@5
  bool v7; // zf@6
  AVLNode<unsigned long,unsigned long> *v8; // eax@6
  AVLNode<unsigned long,unsigned long> *result; // eax@7

  v3 = curr;
  v4 = curr->_left;
  if ( curr->_left )
  {
    do
    {
      v5 = v3;
      v3 = v4;
      v4 = v4->_left;
    }
    while ( v4 );
  }
  else
  {
    v5 = parent;
  }
  v6 = v3->_right;
  if ( v6 )
  {
    v7 = v3->_parentsize == 0;
    v6->_parent = v5;
    v8 = v3->_right;
    if ( v7 )
    {
      v5->_right = v8;
      v3->_right->_parentsize = 0;
      AVL<unsigned long,unsigned long>::ReBalanceTree(this, v5, 0);
      result = v3;
    }
    else
    {
      v5->_left = v8;
      v3->_right->_parentsize = 1;
      AVL<unsigned long,unsigned long>::ReBalanceTree(this, v5, 0);
      result = v3;
    }
  }
  else if ( v3->_parentsize )
  {
    v5->_left = 0;
    AVL<unsigned long,unsigned long>::ReBalanceTree(this, v5, 0);
    result = v3;
  }
  else
  {
    v5->_right = 0;
    AVL<unsigned long,unsigned long>::ReBalanceTree(this, v5, 0);
    result = v3;
  }
  return result;
}

//----- (00543890) --------------------------------------------------------  // acclient.c:371210
bool __cdecl TimeStampUtils::lhs_newer(unsigned int _a, unsigned int _b)
{
  bool result; // al@2
  unsigned int v3; // ecx@3
  int v4; // esi@3

  if ( _a == _b )
  {
    result = 0;
  }
  else
  {
    v3 = _a - _b;
    v4 = 1;
    if ( _a < _b )
    {
      v3 = _b - _a;
      v4 = -1;
    }
    if ( v3 > 0x7FFFFFFF )
      v4 = -v4;
    result = v4 > 0;
  }
  return result;
}

//----- (005438D0) --------------------------------------------------------  // acclient.c:371237
bool __cdecl TimeStampUtils::lhs_newer(unsigned __int16 _a, unsigned __int16 _b)
{
  bool result; // al@2
  unsigned __int16 v3; // cx@3
  int v4; // esi@3

  if ( _a == _b )
  {
    result = 0;
  }
  else
  {
    v3 = _a - _b;
    v4 = 1;
    if ( _a < _b )
    {
      v3 = _b - _a;
      v4 = -1;
    }
    if ( v3 > 0x7FFFu )
      v4 = -v4;
    result = v4 > 0;
  }
  return result;
}

//----- (00543910) --------------------------------------------------------  // acclient.c:371264
void __thiscall AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(AC1Legacy::PStringBase<unsigned short> *this, const unsigned __int16 *str)
{
  AC1Legacy::PStringBase<unsigned short> *v2; // esi@1
  unsigned int v3; // eax@3
  volatile LONG *v4; // ST04_4@4

  v2 = this;
  if ( str && *str )
  {
    v3 = _wcslen(str);
    AC1Legacy::PStringBase<unsigned short>::allocate_ref_buffer(v2, v3);
    _wcscpy(v2->m_buffer->m_data, str);
  }
  else
  {
    v4 = (volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4);
    this->m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (00543970) --------------------------------------------------------  // acclient.c:371287
char __thiscall SmartArray<ClientNet::CReferralQueueEntry,1>::grow(SmartArray<ClientNet::CReferralQueueEntry,1> *this, unsigned int i_nSize)
{
  SmartArray<ClientNet::CReferralQueueEntry,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // ebp@5
  int v6; // ecx@7
  int v7; // eax@8
  unsigned int v8; // edx@8
  const void *v9; // esi@9
  void *v10; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ClientNet::CReferralQueueEntry,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](40 * i_nSize);
    if ( v5 )
    {
      if ( v2->m_data )
      {
        v6 = v2->m_num - 1;
        if ( v6 >= 0 )
        {
          v7 = v6;
          v8 = v2->m_num;
          do
          {
            v9 = &v2->m_data[v7];
            v10 = (char *)v5 + v7 * 40;
            --v7;
            --v8;
            qmemcpy(v10, v9, 0x28u);
          }
          while ( v8 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (ClientNet::CReferralQueueEntry *)v5;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00543A20) --------------------------------------------------------  // acclient.c:371342
bool __stdcall SharedNet::SeqIDSanityCheck(CNetLayerPacket *pkt)
{
  unsigned int v2; // ecx@1
  ReceiverData *v3; // edi@1
  int v4; // eax@1
  int v5; // edx@2
  int v6; // esi@2
  bool result; // al@7

  v2 = pkt->m_Hdr.seqID_;
  v3 = pkt->m_pRecv;
  v4 = v3->highestIDReceived_ + 0x7FFF;
  if ( v2 == v4 )
    goto LABEL_11;
  v5 = v2 - v4;
  v6 = 1;
  if ( v2 < v4 )
  {
    v5 = v4 - v2;
    v6 = -1;
  }
  if ( (unsigned int)v5 > 0x7FFFFFFF )
    v6 = -v6;
  if ( v6 <= 0 )
LABEL_11:
    result = v3->m_SeqIDsWeNAKed._currNum <= 0x9C40;
  else
    result = 0;
  return result;
}

//----- (00543A80) --------------------------------------------------------  // acclient.c:371374
char __stdcall SharedNet::ProcessNewRemoteInterval(CNetLayerPacket *pkt)
{
  ReceiverData *v2; // eax@1
  _BYTE v3[6]; // ST00_6@2
  COptionalHeader *v4; // esi@2
  unsigned __int16 v5; // ST00_2@2
  PacketController *v6; // eax@2

  v2 = pkt->m_pRecv;
  if ( v2->m_CurrentRemoteInterval )
  {
    *(_DWORD *)v3 = v2->m_BytesReceived;
    *(_WORD *)&v3[4] = v2->m_CurrentRemoteInterval;
    v4 = COnePrimHeader<134217728,16,CFlowStruct>::CreateFromData(*(CFlowStruct *)v3);
    v5 = pkt->m_Hdr.recID_;
    v6 = PacketController::Instance();
    PacketController::EnqueueOptionalHeader(v6, v5, v4);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    }
  }
  pkt->m_pRecv->m_CurrentRemoteInterval = pkt->m_Hdr.interval_;
  pkt->m_pRecv->m_BytesReceived = 0;
  return 1;
}

//----- (00543B10) --------------------------------------------------------  // acclient.c:371403
void __stdcall SharedNet::EnqueuePak(ReceiverData *recData)
{
  unsigned int v2; // esi@2
  void *v3; // eax@2
  void *v4; // esi@3
  unsigned __int16 v5; // ST00_2@5
  PacketController *v6; // eax@5
  long double now; // [sp+4h] [bp-8h]@1

  now = *(double *)&Timer::cur_time;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - recData->timeStamp_ >= 2.0 )
  {
    v2 = recData->highestIDReceived_;
    v3 = operator new(0x1Cu);
    if ( v3 )
    {
      *((_DWORD *)v3 + 6) = v2;
      *((_DWORD *)v3 + 1) = 1;
      *((_DWORD *)v3 + 2) = 0x4000;
      *((_DWORD *)v3 + 3) = 1;
      *((_DWORD *)v3 + 4) = (char *)v3 + 24;
      *((_DWORD *)v3 + 5) = 4;
      *(_DWORD *)v3 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
      v4 = v3;
    }
    else
    {
      v4 = 0;
    }
    v5 = recData->m_RecID;
    v6 = PacketController::Instance();
    PacketController::EnqueueOptionalHeader(v6, v5, (COptionalHeader *)v4);
    if ( v4 )
    {
      if ( !InterlockedDecrement((volatile LONG *)v4 + 1) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    recData->timeStamp_ = now;
  }
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00543BD0) --------------------------------------------------------  // acclient.c:371446
void __stdcall SharedNet::EnqueueNaks(ReceiverData *recData)
{
  unsigned int v2; // esi@2
  void *v3; // eax@2
  void *v4; // esi@3
  unsigned __int16 v5; // ST00_2@5
  PacketController *v6; // eax@5
  long double now; // [sp+4h] [bp-1D4h]@1
  unsigned int naks[115]; // [sp+Ch] [bp-1CCh]@2

  now = *(double *)&Timer::cur_time;
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - recData->timeStamp_ > 0.6 )
  {
    v2 = ReceiverData::GetNaks(recData, naks);
    v3 = operator new(0x1E4u);
    if ( v3 )
    {
      *((_DWORD *)v3 + 6) = v2;
      *((_DWORD *)v3 + 4) = (char *)v3 + 24;
      *((_DWORD *)v3 + 5) = 4 * v2 + 4;
      *((_DWORD *)v3 + 1) = 1;
      *((_DWORD *)v3 + 2) = 4096;
      *((_DWORD *)v3 + 3) = 33;
      *(_DWORD *)v3 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
      qmemcpy((char *)v3 + 28, naks, 4 * (4 * v2 >> 2));
      v4 = v3;
    }
    else
    {
      v4 = 0;
    }
    v5 = recData->m_RecID;
    v6 = PacketController::Instance();
    PacketController::EnqueueOptionalHeader(v6, v5, (COptionalHeader *)v4);
    if ( v4 )
    {
      if ( !InterlockedDecrement((volatile LONG *)v4 + 1) )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    recData->timeStamp_ = now;
  }
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00543CC0) --------------------------------------------------------  // acclient.c:371491
void __thiscall ClientNet::OnContextEnded(ClientNet *this, AsyncContext hContext, AsyncStateMachineStatus CompletionStatus)
{
  ClientNet *v3; // esi@1
  int v4; // eax@1
  int v5; // ecx@1

  v3 = this;
  v4 = CAsyncStateHandler::GetContextData((CAsyncStateHandler *)this, hContext, *(_DWORD *)&this->receivers_[4]);
  v5 = (int)&v3->receivers_[56];
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(v4 + 8);
  *(_DWORD *)&v3->receivers_[20] = INVALID_ASYNCCONTEXT_7.m_id;
  if ( *(_DWORD *)&v3->receivers_[60] != ID_NetError_None.m_stringID
    || *(_DWORD *)&v3->receivers_[64] != ID_NetError_None.m_tableID )
    ClientNet::NotifyPluginsOfStatusChange(
      (ClientNet *)((char *)v3 - 34952),
      Net_LoginConnectionError,
      (int)&v3->receivers_[56],
      0);
  else
    ClientNet::NotifyPluginsOfStatusChange((ClientNet *)((char *)v3 - 34952), Net_LoginConnected, 0, 0);
}

//----- (00543D30) --------------------------------------------------------  // acclient.c:371515
void __thiscall ClientNet::HandleTimeSynch(ClientNet *this, CTimeSyncHeader *pHdr, CNetLayerPacket *pkt)
{
  ClientNet *v3; // esi@1
  int v4; // edx@1
  RecipientData *v5; // edi@1
  COptionalHeader *v6; // esi@5
  unsigned __int16 v7; // ST00_2@5
  PacketController *v8; // eax@5
  long double srvtime; // [sp+8h] [bp-10h]@1
  long double now; // [sp+10h] [bp-8h]@1

  v3 = this;
  v4 = LODWORD(pHdr->m_time);
  v5 = pkt->m_pRecip;
  HIDWORD(srvtime) = HIDWORD(pHdr->m_time);
  LODWORD(srvtime) = v4;
  now = *(double *)&Timer::cur_time;
  Timer::set_time(&srvtime);
  if ( srvtime + 60.0 >= now )
  {
    LODWORD(v3->_timeClientSpeedHackDetection) = 0;
    HIDWORD(v3->_timeClientSpeedHackDetection) = 0;
  }
  else if ( v3->_timeClientSpeedHackDetection == 0.0 )
  {
    v3->_timeClientSpeedHackDetection = now;
  }
  else if ( now > v3->_timeClientSpeedHackDetection + 60.0 )
  {
    if ( v5 )
    {
      v6 = CPackObjHeader<NetError,1048576,7>::CreateFromData(&ID_ConnectionError_RunningSpeedhack);
      v7 = v5->recID_;
      v8 = PacketController::Instance();
      PacketController::EnqueueOptionalHeader(v8, v7, v6);
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v6->vfptr);
    }
  }
}

//----- (00543E20) --------------------------------------------------------  // acclient.c:371556
void __thiscall ClientNet::HandleServerSwitch(ClientNet *this, COnePrimHeader<256,96,CServerSwitchStruct> *pSwitchHdr, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v3; // edi@1
  ServerSwitchType v4; // ebx@1
  unsigned int v5; // edx@1
  char *v6; // esi@1
  int v7; // eax@7
  int v8; // edi@8
  int v9; // ebp@8
  ReceiverData *pRecv; // [sp+0h] [bp-4h]@1

  v3 = pkt;
  pRecv = pkt->m_pRecv;
  v4 = pSwitchHdr->m_Prim.Type;
  v5 = pSwitchHdr->m_Prim.dwSeqNo.m_timestamp;
  v6 = 0;
  if ( pSwitchHdr->m_Prim.Type )
  {
    if ( pSwitchHdr->m_Prim.Type != 1 )
      goto LABEL_7;
    v6 = (char *)&this->m_LogonSwitchHistory;
  }
  else
  {
    v6 = (char *)&this->m_WorldSwitchHistory;
  }
  if ( v6 && !v6[4] )
  {
LABEL_14:
    v6[4] = 1;
    *(_DWORD *)v6 = v5;
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        if ( !this->fCurrentlyInGame_ )
          this->currServerRecID_ = v3->recipient_;
        this->logonRecID_ = v3->recipient_;
      }
    }
    else
    {
      this->currServerRecID_ = v3->recipient_;
      this->netID_ = pRecv->m_NetID;
    }
    return;
  }
LABEL_7:
  v7 = *(_DWORD *)v6;
  if ( v5 != *(_DWORD *)v6 )
  {
    v8 = v5 - v7;
    v9 = 1;
    if ( v5 < v7 )
    {
      v8 = v7 - v5;
      v9 = -1;
    }
    if ( (unsigned int)v8 > 0x7FFFFFFF )
      v9 = -v9;
    if ( v9 > 0 )
    {
      v3 = pkt;
      goto LABEL_14;
    }
  }
}

//----- (00543EF0) --------------------------------------------------------  // acclient.c:371625
void __thiscall ClientNet::LogOffServer(ClientNet *this)
{
  ClientNet *v1; // ebp@1
  ReceiverData *v2; // esi@1
  void *v3; // eax@1
  void *v4; // edi@2

  v1 = this;
  v2 = this->connectionsHead_;
  v3 = operator new(0x1Cu);
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 1;
    *((_DWORD *)v3 + 2) = 0x8000;
    *((_DWORD *)v3 + 3) = 3;
    *((_DWORD *)v3 + 4) = (char *)v3 + 24;
    *((_DWORD *)v3 + 5) = 0;
    *(_DWORD *)v3 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    *((_DWORD *)v3 + 6) = 0;
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  for ( ; v2; v2 = v2->next_ )
    SharedNet::SendOptionalHeader((SharedNet *)&v1->vfptr, (COptionalHeader *)v4, &v2->m_Addr, v2);
  if ( v4 && !InterlockedDecrement((volatile LONG *)v4 + 1) )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v1->logOffSent_ = 1;
  v1->logonRecID_ = 0;
  ClientNet::ExitWorldDisconnect(v1);
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00543F90) --------------------------------------------------------  // acclient.c:371661
char __thiscall ClientNet::SendLoginRequest(ClientNet *this, sockaddr_in *ServerAddr, NetAuthenticator *pNetAuth)
{
  NetAuthenticator *v3; // esi@1
  char v4; // al@1
  sockaddr_in *v5; // ebp@2
  COptionalHeader *v6; // edi@2
  sockaddr_in *v7; // esi@2
  unsigned int v8; // eax@5
  NetPacket *v9; // esi@10
  unsigned int v10; // ecx@10
  AC1Legacy::PSRefBuffer<char> *v11; // esi@13
  AC1Legacy::PStringBase<char> result; // [sp+8h] [bp-1Ch]@2
  SharedNet *v13; // [sp+Ch] [bp-18h]@1
  ProtoHeader pheader; // [sp+10h] [bp-14h]@10

  v3 = pNetAuth;
  v4 = 0;
  v13 = (SharedNet *)this;
  if ( pNetAuth )
  {
    result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v5 = ServerAddr;
    NetUtils::GetIPString(ServerAddr, &result, 0);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&ServerAddr, "1802");
    v6 = CLogonHeader::CreateFromData((AC1Legacy::PStringBase<char> *)&ServerAddr, v3);
    v7 = ServerAddr;
    if ( !InterlockedDecrement((volatile LONG *)&ServerAddr->sin_addr.S_un.S_addr) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v7->sin_family)(v7, 1);
    v8 = v6->m_Flags;
    LOBYTE(pNetAuth) = 0;
    if ( !(v8 & 0x10) && v8 & 1 && v8 & 2 && !(v8 & 8) && v8 & 4 )
    {
      v9 = NetPacket::CreateForSend(0);
      NetPacket::AddOptionalHeader(v9, v6);
      v10 = v6->m_dwMask;
      pheader.seqID_ = 0;
      pheader.header_ = 0;
      pheader.checksum_ = 0;
      pheader.recID_ = 0;
      pheader.datalen_ = 0;
      pheader.iteration_ = 0;
      pheader.interval_ = 0;
      pheader.datalen_ = LOWORD(v9->size_);
      pheader.header_ = v10;
      pheader.checksum_ = v9->checksum_;
      pheader.seqID_ = 0;
      pheader.recID_ = 0;
      pheader.iteration_ = 0;
      LOBYTE(pNetAuth) = SharedNet::SendPacket(v13, v9, &pheader, v5);
      ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v9->vfptr);
    }
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
    v11 = result.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) )
    {
      if ( v11 )
        v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
    }
    v4 = (char)pNetAuth;
  }
  return v4;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005440F0) --------------------------------------------------------  // acclient.c:371728
bool __thiscall ClientNet::SendConnectAck(ClientNet *this, ReceiverData *pReceiver)
{
  ClientNet *v2; // ebx@1
  unsigned int v3; // edx@1
  int v4; // ecx@1
  int v5; // edx@1
  u_short v6; // ax@1
  unsigned __int16 v7; // ax@1
  int v8; // edi@1
  int v9; // ebp@1
  void *v10; // eax@1
  int v11; // ecx@2
  void *v12; // edi@2
  unsigned __int64 v13; // rax@5
  bool bOK; // [sp+13h] [bp-11h]@1
  sockaddr_in ServerOtherAddr; // [sp+14h] [bp-10h]@1

  v2 = this;
  pReceiver->lastSentHandshake_ = Timer::local_time;
  v3 = pReceiver->m_Addr.sin_addr.S_un.S_addr;
  *(_DWORD *)&ServerOtherAddr.sin_family = *(_DWORD *)&pReceiver->m_Addr.sin_family;
  v4 = *(_DWORD *)&pReceiver->m_Addr.sin_zero[0];
  ServerOtherAddr.sin_addr.S_un.S_addr = v3;
  v5 = *(_DWORD *)&pReceiver->m_Addr.sin_zero[4];
  bOK = 0;
  *(_DWORD *)&ServerOtherAddr.sin_zero[0] = v4;
  *(_DWORD *)&ServerOtherAddr.sin_zero[4] = v5;
  v6 = ntohs(ServerOtherAddr.sin_port);
  v7 = htons(v6 + 1);
  v8 = LODWORD(pReceiver->m_qwReferralCookie);
  v9 = HIDWORD(pReceiver->m_qwReferralCookie);
  ServerOtherAddr.sin_port = v7;
  v10 = operator new(0x20u);
  if ( v10 )
  {
    v11 = (int)((char *)v10 + 24);
    *(_DWORD *)v11 = v8;
    *((_DWORD *)v10 + 1) = 1;
    *((_DWORD *)v10 + 2) = 0x80000;
    *((_DWORD *)v10 + 3) = 536870919;
    *((_DWORD *)v10 + 4) = (char *)v10 + 24;
    *((_DWORD *)v10 + 5) = 8;
    *(_DWORD *)v10 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
    *(_DWORD *)(v11 + 4) = v9;
    v12 = v10;
  }
  else
  {
    v12 = 0;
  }
  if ( SharedNet::SendOptionalHeader((SharedNet *)&v2->vfptr, (COptionalHeader *)v12, &ServerOtherAddr, pReceiver) )
  {
    bOK = 1;
    v13 = (unsigned __int64)(ReceiverData::GetConnectionStateDuration(pReceiver) / 0.333333333);
    ClientNet::NotifyPluginsOfStatusChange(v2, Net_LoginConnecting, v13 + 1, 0);
  }
  if ( v12 && !InterlockedDecrement((volatile LONG *)v12 + 1) )
    (**(void (__thiscall ***)(void *, signed int))v12)(v12, 1);
  return bOK;
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (005441F0) --------------------------------------------------------  // acclient.c:371791
void __thiscall ClientNet::ProcessReferralQueue(ClientNet *this)
{
  ClientNet *v1; // ebp@1
  unsigned int v2; // esi@1
  int v3; // ebx@2
  int v4; // ecx@3
  ClientNet::CReferralQueueEntry *v5; // edx@5
  int v6; // edi@5
  int v7; // esi@5
  void *v8; // eax@5
  int v9; // ecx@6
  void *v10; // edi@6
  int v11; // eax@8
  NetPacket *v12; // esi@13
  unsigned int v13; // ecx@13
  unsigned __int16 v14; // dx@13
  unsigned int v15; // edx@13
  unsigned int v16; // eax@19
  int v17; // eax@20
  unsigned int i; // [sp+10h] [bp-38h]@3
  sockaddr_in *addr; // [sp+14h] [bp-34h]@8
  double LocalTimeNow; // [sp+18h] [bp-30h]@1
  ProtoHeader pheader; // [sp+20h] [bp-28h]@13

  v1 = this;
  v2 = this->m_ReferralQueue.m_num;
  LocalTimeNow = Timer::local_time;
  if ( v2 )
  {
    v3 = v2;
    do
    {
      --v3;
      v4 = (int)&v1->m_ReferralQueue.m_data[v3];
      --v2;
      i = v2;
      if ( *(double *)(v4 + 8) < LocalTimeNow )
      {
        if ( 280.0 / 0.333333333 <= (double)*(unsigned int *)v4 )
        {
          v16 = v1->m_ReferralQueue.m_num;
          if ( v2 < v16 )
          {
            v17 = v16 - 1;
            v1->m_ReferralQueue.m_num = v17;
            if ( v2 != v17 )
            {
              qmemcpy(
                &v1->m_ReferralQueue.m_data[v3],
                &v1->m_ReferralQueue.m_data[v17],
                sizeof(v1->m_ReferralQueue.m_data[v3]));
              qmemcpy(
                &v1->m_ReferralQueue.m_data[v1->m_ReferralQueue.m_num],
                &pheader,
                sizeof(v1->m_ReferralQueue.m_data[v1->m_ReferralQueue.m_num]));
            }
          }
          ClientNet::NotifyPluginsOfStatusChange(v1, Net_WorldConnectionError, 0, 0);
        }
        else
        {
          ++*(_DWORD *)v4;
          v1->m_ReferralQueue.m_data[v3].localtimeToSendNextWorldAuth = LocalTimeNow + 0.333333333;
          v5 = v1->m_ReferralQueue.m_data;
          v6 = LODWORD(v5[v3].qwCookie);
          v7 = HIDWORD(v5[v3].qwCookie);
          v8 = operator new(0x20u);
          if ( v8 )
          {
            v9 = (int)((char *)v8 + 24);
            *(_DWORD *)v9 = v6;
            *((_DWORD *)v8 + 1) = 1;
            *((_DWORD *)v8 + 2) = 0x20000;
            *((_DWORD *)v8 + 3) = 7;
            *((_DWORD *)v8 + 4) = (char *)v8 + 24;
            *((_DWORD *)v8 + 5) = 8;
            *(_DWORD *)v8 = &COnePrimHeader<256,96,CServerSwitchStruct>::vftable;
            *(_DWORD *)(v9 + 4) = v7;
            v10 = v8;
          }
          else
          {
            v10 = 0;
          }
          v11 = *((_DWORD *)v10 + 3);
          addr = &v1->m_ReferralQueue.m_data[v3].ServerAddr;
          if ( !(v11 & 0x10) && v11 & 1 && v11 & 2 && !(v11 & 8) && v11 & 4 )
          {
            v12 = NetPacket::CreateForSend(0);
            NetPacket::AddOptionalHeader(v12, (COptionalHeader *)v10);
            v13 = *((_DWORD *)v10 + 2);
            pheader.seqID_ = 0;
            pheader.header_ = 0;
            pheader.checksum_ = 0;
            pheader.recID_ = 0;
            pheader.datalen_ = 0;
            pheader.iteration_ = 0;
            pheader.interval_ = 0;
            v14 = LOWORD(v12->size_);
            pheader.header_ = v13;
            pheader.datalen_ = v14;
            v15 = v12->checksum_;
            pheader.recID_ = 0;
            pheader.iteration_ = 0;
            pheader.checksum_ = v15;
            SharedNet::SendPacket((SharedNet *)&v1->vfptr, v12, &pheader, addr);
            ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v12->vfptr);
          }
          if ( !InterlockedDecrement((volatile LONG *)v10 + 1) )
            (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
          v2 = i;
        }
      }
    }
    while ( v2 );
  }
}
// 7CA508: using guessed type int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char);

//----- (00544420) --------------------------------------------------------  // acclient.c:371911
unsigned int __thiscall AVL<unsigned long,unsigned long>::Remove(AVL<unsigned long,unsigned long> *this, unsigned int key)
{
  AVL<unsigned long,unsigned long> *v2; // ebp@1
  AVLNode<unsigned long,unsigned long> *v3; // esi@1
  AVLNode<unsigned long,unsigned long> *v4; // ebx@1
  unsigned int result; // eax@2
  AVLNode<unsigned long,unsigned long> *v6; // eax@9
  AVLNode<unsigned long,unsigned long> *v7; // ecx@16
  AVLNode<unsigned long,unsigned long> *v8; // edi@20
  AVLNode<unsigned long,unsigned long> *v9; // ecx@29
  unsigned int keya; // [sp+10h] [bp+4h]@9

  v2 = this;
  v3 = this->_root;
  v4 = 0;
  if ( !this->_root )
    return 0;
  while ( v3->_key != key )
  {
    v4 = v3;
    v3 = key >= v3->_key ? v3->_right : v3->_left;
    if ( !v3 )
      return 0;
  }
  keya = (unsigned int)v3->_data;
  v6 = v3->_right;
  if ( v6 || v3->_left )
  {
    if ( v6 )
    {
      v8 = AVL<unsigned long,unsigned long>::FindSuccessor(this, v3, v6);
    }
    else
    {
      if ( v4 )
      {
        if ( v3->_parentsize )
        {
          v4->_left = v3->_left;
          v3->_left->_parentsize = 1;
          v3->_left->_parent = v4;
        }
        else
        {
          v4->_right = v3->_left;
          v3->_left->_parentsize = 0;
          v3->_left->_parent = v4;
        }
      }
      else
      {
        this->_root = v3->_left;
      }
      v8 = v3;
      this->_root->_parent = 0;
    }
    v3->_data = v8->_data;
    v3->_key = v8->_key;
    v8->_left = 0;
    v8->_right = 0;
    if ( v8->_left )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v8->_left, 1u);
    v9 = v8->_right;
    if ( v9 )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v9, 1u);
    v8->_left = 0;
    v8->_right = 0;
    operator delete(v8);
    AVL<unsigned long,unsigned long>::ReBalanceTree(v2, v4, 0);
    --v2->_currNum;
    result = keya;
  }
  else
  {
    if ( v4 )
    {
      if ( v3->_parentsize )
        v4->_left = 0;
      else
        v4->_right = 0;
    }
    else
    {
      this->_root = 0;
    }
    v3->_left = 0;
    v3->_right = 0;
    v7 = v3->_right;
    if ( v7 )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v7, 1u);
    v3->_left = 0;
    v3->_right = 0;
    operator delete(v3);
    AVL<unsigned long,unsigned long>::ReBalanceTree(v2, v4, 0);
    --v2->_currNum;
    result = keya;
  }
  return result;
}

//----- (00544590) --------------------------------------------------------  // acclient.c:372012
void __thiscall CClientsideLoginStateHandler::OnStateHandlerInit(CClientsideLoginStateHandler *this)
{
  CClientsideLoginStateHandler *v1; // esi@1
  unsigned int v2; // eax@1
  char *v3; // edi@1
  volatile LONG *v4; // ST00_4@1
  unsigned int v5; // eax@4
  char *v6; // edi@4
  volatile LONG *v7; // ST00_4@4
  unsigned int v8; // eax@7
  char *v9; // edi@7
  volatile LONG *v10; // ST00_4@7
  char *v11; // esi@10
  PStringBase<char> DataName; // [sp+Ch] [bp-4h]@1

  DataName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  PStringBase<char>::PStringBase<char>(&DataName, "RecipientID");
  v2 = CAsyncStateHandler::RegisterContextDataName((CAsyncStateHandler *)&v1->vfptr, &DataName);
  v3 = &DataName.m_charbuffer[-2].m_data[12];
  v4 = (volatile LONG *)&DataName.m_charbuffer[-1];
  v1->m_idxRecipientID = v2;
  if ( !InterlockedDecrement(v4) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&DataName, "ServerAddr");
  v5 = CAsyncStateHandler::RegisterContextDataName((CAsyncStateHandler *)&v1->vfptr, &DataName);
  v6 = &DataName.m_charbuffer[-2].m_data[12];
  v7 = (volatile LONG *)&DataName.m_charbuffer[-1];
  v1->m_idxServerAddr = v5;
  if ( !InterlockedDecrement(v7) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>(&DataName, "NetAuthenticator");
  v8 = CAsyncStateHandler::RegisterContextDataName((CAsyncStateHandler *)&v1->vfptr, &DataName);
  v9 = &DataName.m_charbuffer[-2].m_data[12];
  v10 = (volatile LONG *)&DataName.m_charbuffer[-1];
  v1->m_idxNetAuth = v8;
  if ( !InterlockedDecrement(v10) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  PStringBase<char>::PStringBase<char>(&DataName, "FailureReason");
  v1->m_idxFailureReason = CAsyncStateHandler::RegisterContextDataName((CAsyncStateHandler *)&v1->vfptr, &DataName);
  v11 = &DataName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataName.m_charbuffer[-1]) )
  {
    if ( v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  }
}

//----- (00544690) --------------------------------------------------------  // acclient.c:372061
char __thiscall SharedNet::ProcessNewSeqNum(SharedNet *this, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v2; // esi@1
  ReceiverData *v3; // edi@1
  unsigned int v4; // ebx@1
  SharedNet *v5; // ebp@1
  unsigned int v7; // eax@8
  unsigned int *pDecryptionKey; // [sp+10h] [bp-4h]@6

  v2 = pkt;
  v3 = pkt->m_pRecv;
  pkt->cryptoKey_ = 0;
  v4 = v2->m_Hdr.seqID_;
  v5 = this;
  if ( !v3 || v4 && !v3->m_RecID )
  {
    ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->AddToPerfCounter)(2, 1);
    return 0;
  }
  if ( !SharedNet::SeqIDSanityCheck(v2) )
  {
    v5->vfptr->AddToPerfCounter(v5, BadPacketsReceivedCounter, 1);
    return 0;
  }
  pDecryptionKey = 0;
  pkt = 0;
  if ( !(v2->m_Hdr.header_ & 2) || TimeStampUtils::lhs_newer(v4, v3->highestIDReceived_) )
    goto LABEL_10;
  v7 = AVL<unsigned long,unsigned long>::Remove(&v3->m_SeqIDsWeNAKed, v4);
  if ( !v7 )
    return 0;
  pkt = (CNetLayerPacket *)v7;
  pDecryptionKey = (unsigned int *)&pkt;
  SharedNet::SetNakState(v3);
LABEL_10:
  if ( TimeStampUtils::lhs_newer(v4, v3->highestIDReceived_) )
    SharedNet::ProcessNewestSeqNum(v2);
  if ( v2->m_Hdr.header_ & 2 )
    v2->cryptoKey_ = ReceiverData::Decrypt(v3, v2->m_Hdr.seqID_, (char *)&v2->m_Hdr.checksum_, 4u, pDecryptionKey);
  return 1;
}

//----- (00544790) --------------------------------------------------------  // acclient.c:372104
char __thiscall SharedNet::ProcessPacket(SharedNet *this, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v2; // esi@1
  SharedNet *v3; // edi@1
  unsigned __int16 v4; // ST08_2@2
  PacketController *v5; // eax@2
  char v7; // bl@6
  ReceiverData *v8; // ecx@7
  unsigned int v9; // eax@8
  ReceiverData *v10; // eax@17
  int v11; // edx@18

  v2 = pkt;
  v3 = this;
  if ( !(unsigned __int8)((int (__stdcall *)(CNetLayerPacket *))this->vfptr->VerifyHeader)(pkt) )
    return 0;
  v2->m_pRecv = (ReceiverData *)&v3->receivers_[136 * v2->m_Hdr.recID_];
  v4 = v2->m_Hdr.recID_;
  v5 = PacketController::Instance();
  v2->m_pRecip = PacketController::GetRecipient(v5, v4);
  if ( v2->m_Hdr.seqID_ )
  {
    if ( !SharedNet::ProcessNewSeqNum(v3, v2) )
      return 0;
  }
  else if ( v2->m_Hdr.header_ & 2 )
  {
    return 0;
  }
  v7 = v3->vfptr->SplitPacketData(v3, v2);
  if ( v7 )
  {
    if ( !v2->m_pRecv->m_CurrentRemoteInterval
      || TimeStampUtils::lhs_newer(v2->m_Hdr.interval_, v2->m_pRecv->m_CurrentRemoteInterval) )
      v7 |= v3->vfptr->ProcessNewRemoteInterval(v3, v2);
    v2->m_pRecv->m_BytesReceived += v2->size_ + 20;
    if ( v2->numSpecialFrags_ && !v3->vfptr->ProcessOptionalHeaders(v3, v2) )
      v7 = 0;
    v10 = v2->m_pRecv;
    if ( v10 )
    {
      v11 = HIDWORD(Timer::local_time);
      LODWORD(v10->m_LocalTimeLastGotData) = LODWORD(Timer::local_time);
      HIDWORD(v10->m_LocalTimeLastGotData) = v11;
      if ( v2->numFrags_ )
      {
        if ( !v3->vfptr->ProcessBlobFrags(v3, v2) )
          v7 = 0;
      }
    }
  }
  else
  {
    v8 = v2->m_pRecv;
    if ( v8 )
    {
      v9 = v2->m_Hdr.seqID_;
      if ( v9 )
      {
        if ( v2->m_Hdr.header_ & 2 )
        {
          pkt = (CNetLayerPacket *)v2->cryptoKey_;
          ReceiverData::AddNakked(v8, v9, (unsigned int *)&pkt);
          return 0;
        }
      }
    }
  }
  return v7;
}

//----- (005448F0) --------------------------------------------------------  // acclient.c:372176
void __thiscall SharedNet::HandleEmptyAck(SharedNet *this, CSeqIDListHeader<8192,33> *pPakHdr, CNetLayerPacket *pkt)
{
  unsigned __int16 v3; // ax@1
  int v4; // edx@2
  unsigned int v5; // edi@3
  AVL<unsigned long,unsigned long> *v6; // ebp@4
  unsigned int *v7; // esi@4

  v3 = pkt->m_Hdr.recID_;
  if ( v3 < 0x100u )
  {
    v4 = 136 * v3;
    if ( (SharedNet *)((char *)this + v4) != (SharedNet *)-32 )
    {
      v5 = 0;
      if ( pPakHdr->m_IDs[0] )
      {
        v6 = (AVL<unsigned long,unsigned long> *)&this->receivers_[v4 + 76];
        v7 = &pPakHdr->m_IDs[1];
        do
        {
          AVL<unsigned long,unsigned long>::Remove(v6, *v7);
          ++v5;
          ++v7;
        }
        while ( v5 < pPakHdr->m_IDs[0] );
      }
    }
  }
}

//----- (00544950) --------------------------------------------------------  // acclient.c:372208
char __stdcall SharedNet::ProcessConnection(ReceiverData *recData)
{
  char result; // al@2

  if ( recData->m_SeqIDsWeNAKed._currNum )
  {
    recData->m_NakState = 1;
    SharedNet::EnqueueNaks(recData);
    result = 1;
  }
  else
  {
    recData->m_NakState = 2;
    SharedNet::EnqueuePak(recData);
    result = 1;
  }
  return result;
}

//----- (00544980) --------------------------------------------------------  // acclient.c:372228
void __thiscall ClientNet::OnContextBegun(ClientNet *this, AsyncContext hContext)
{
  unsigned int v2; // edi@1
  ClientNet *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // esi@1

  v2 = hContext.m_id;
  v3 = this;
  *(_DWORD *)&this->receivers_[20] = hContext.m_id;
  CAsyncStateHandler::SetContextData((CAsyncStateHandler *)this, (AsyncContext)v2, *(_DWORD *)&this->netID_, 0);
  CAsyncStateHandler::SetContextData(
    (CAsyncStateHandler *)v3,
    (AsyncContext)v2,
    *((_DWORD *)&v3->netID_ + 1),
    (int)&v3->receivers_[28]);
  CAsyncStateHandler::SetContextData(
    (CAsyncStateHandler *)v3,
    (AsyncContext)v2,
    *(_DWORD *)&v3->receivers_[0],
    *(_DWORD *)&v3->receivers_[44]);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&hContext, "FailureReason");
  v4 = CAsyncStateHandler::RegisterContextDataName((CAsyncStateHandler *)v3, (PStringBase<char> *)&hContext);
  CAsyncStateHandler::SetContextData((CAsyncStateHandler *)v3, (AsyncContext)v2, v4, (int)&v3->receivers_[56]);
  v5 = hContext.m_id - 20;
  if ( !InterlockedDecrement((volatile LONG *)(hContext.m_id - 20 + 4)) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (00544A10) --------------------------------------------------------  // acclient.c:372261
void __thiscall ClientNet::LogonUseTime(ClientNet *this)
{
  ClientNet *v1; // esi@1
  int v2; // eax@1
  unsigned __int16 v3; // cx@1
  signed int v4; // ecx@2

  v1 = this;
  v2 = Timer::get_real_time();
  v3 = v1->logonRecID_;
  if ( v3 )
  {
    if ( v3 >= 0x100u
      || (ClientNet *)((char *)v1 + 136 * v3) == (ClientNet *)-32
      || !*(_WORD *)&v1->receivers_[136 * v3]
      || *(_DWORD *)&v1->receivers_[136 * v3 + 72] > 5 )
      ClientNet::EndState(v1, &ID_ConnectionError_Generic);
  }
  else
  {
    v4 = v1->m_LogonData.nRequestsSent;
    if ( !v4 || (double)(v2 - v1->m_LogonData.timeLastLoginRequestSent) >= 2.0 )
    {
      if ( v4 < 20 )
      {
        v1->m_LogonData.nRequestsSent = v4 + 1;
        v1->m_LogonData.timeLastLoginRequestSent = Timer::get_real_time();
        CAsyncStateHandler::GetContextData(
          (CAsyncStateHandler *)&v1->vfptr,
          v1->m_LogonData.hCurrentContext,
          v1->m_idxNetAuth);
        if ( ClientNet::SendLoginRequest(v1, &v1->m_LogonData.ServerAddr, v1->m_LogonData.pNetAuth) )
          ClientNet::NotifyPluginsOfStatusChange(v1, Net_LoginAuthenticating, v1->m_LogonData.nRequestsSent, 20);
        else
          ClientNet::EndState(v1, &ID_ConnectionError_Generic);
      }
      else
      {
        ClientNet::EndState(v1, &ID_ConnectionError_ClientTimedOutServer);
      }
    }
  }
}

//----- (00544B00) --------------------------------------------------------  // acclient.c:372306
NetError *__thiscall ClientNet::InitAddresses(ClientNet *this, NetError *result, const char *host, int port, sockaddr_in *udp_srv_addr, ClientNetConfiguration *Config)
{
  const char *v6; // ebp@1
  const char *v7; // edi@1
  AC1Legacy::PSRefBuffer<char> *v8; // ebx@1
  const char *v9; // esi@1
  char *v10; // eax@1
  int v11; // ebx@2
  AC1Legacy::PSRefBuffer<char> *v12; // edi@7
  unsigned int v13; // eax@8
  AC1Legacy::PSRefBuffer<char> *v14; // edx@12
  int v15; // eax@13
  char v16; // cl@14
  const char *v17; // ebx@18
  char *v18; // eax@18
  int v19; // esi@19
  unsigned int v20; // eax@25
  AC1Legacy::PSRefBuffer<char> *v21; // edx@29
  int v22; // eax@30
  char v23; // cl@31
  const char *v24; // edi@34
  const char *v25; // esi@34
  unsigned __int32 v26; // ebx@34
  sockaddr_in *v27; // esi@40
  sockaddr_in *v28; // ecx@40
  NetError *v29; // esi@41
  int v30; // eax@41
  SOCKET v31; // eax@43
  ClientNet *v32; // ebp@43
  u_long v33; // esi@43
  int v34; // ebx@43
  AC1Legacy::PSRefBuffer<char> *v35; // eax@44
  AC1Legacy::PStringBase<char> v36; // ST08_4@45
  signed int v37; // eax@46
  bool v38; // bl@50
  u_long v39; // esi@51
  int v40; // edi@51
  SOCKET v41; // eax@56
  int v42; // esi@56
  int v43; // edi@56
  SOCKET v44; // ecx@57
  SOCKET v45; // edx@57
  unsigned __int16 v46; // ax@60
  SOCKET v47; // edx@60
  SOCKET v49; // ecx@69
  AC1Legacy::PStringBase<char> hostStr; // [sp+10h] [bp-30h]@1
  ClientNet *v51; // [sp+14h] [bp-2Ch]@1
  int optlen; // [sp+18h] [bp-28h]@56
  int MinRcv; // [sp+1Ch] [bp-24h]@56
  unsigned int one; // [sp+20h] [bp-20h]@69
  InterfaceEnumerator interfaceEnum; // [sp+24h] [bp-1Ch]@43
  sockaddr_in udp_cli_addr; // [sp+30h] [bp-10h]@43

  v6 = host;
  v51 = this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&hostStr, host);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&host, ",");
  v7 = host;
  v8 = hostStr.m_buffer;
  v9 = hostStr.m_buffer->m_data;
  v10 = _strstr(hostStr.m_buffer->m_data, host + 20);
  if ( v10 )
    v11 = v10 - (char *)v8 - 20;
  else
    v11 = -1;
  if ( !InterlockedDecrement((volatile LONG *)v7 + 1) && v7 )
    (**(void (__thiscall ***)(const char *, signed int))v7)(v7, 1);
  v12 = hostStr.m_buffer;
  if ( v11 != -1 )
  {
    LOBYTE(host) = 0;
    v13 = hostStr.m_buffer->m_len;
    if ( v11 < v13 && hostStr.m_buffer->m_data[v11] )
    {
      if ( v11 == v13 - 1 )
      {
        AC1Legacy::PStringBase<char>::append_n_chars(&hostStr, (const char *)&host, 1u);
      }
      else
      {
        AC1Legacy::PStringBase<char>::break_reference(&hostStr);
        v14 = hostStr.m_buffer;
        hostStr.m_buffer->m_data[v11] = (char)host;
        if ( !(_BYTE)host )
        {
          v15 = (int)v14->m_data;
          do
            v16 = *(_BYTE *)v15++;
          while ( v16 );
          v14->m_len = v15 - (_DWORD)((char *)v14 + 21) + 1;
        }
      }
      v12 = hostStr.m_buffer;
    }
    v9 = v12->m_data;
    v6 = v12->m_data;
  }
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&host, ":");
  v17 = host;
  v18 = _strstr(v9, host + 20);
  if ( v18 )
    v19 = v18 - (char *)v12 - 20;
  else
    v19 = -1;
  if ( !InterlockedDecrement((volatile LONG *)v17 + 1) && v17 )
    (**(void (__thiscall ***)(const char *, signed int))v17)(v17, 1);
  if ( v19 == -1 )
  {
    LOWORD(v26) = port;
  }
  else
  {
    LOBYTE(host) = 0;
    v20 = v12->m_len;
    if ( v19 < v20 && v12->m_data[v19] )
    {
      if ( v19 == v20 - 1 )
      {
        AC1Legacy::PStringBase<char>::append_n_chars(&hostStr, (const char *)&host, 1u);
      }
      else
      {
        AC1Legacy::PStringBase<char>::break_reference(&hostStr);
        v21 = hostStr.m_buffer;
        hostStr.m_buffer->m_data[v19] = (char)host;
        if ( !(_BYTE)host )
        {
          v22 = (int)v21->m_data;
          do
            v23 = *(_BYTE *)v22++;
          while ( v23 );
          v21->m_len = v22 - (_DWORD)((char *)v21 + 21) + 1;
        }
      }
      v12 = hostStr.m_buffer;
    }
    v6 = v12->m_data;
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&host, &v12->m_data[v19 + 1]);
    v24 = host;
    v25 = host + 20;
    *__errno() = 0;
    v26 = _strtoul(v25, 0, 0);
    if ( !v26 )
      LOWORD(v26) = 7304;
    if ( !InterlockedDecrement((volatile LONG *)v24 + 1) && v24 )
      (**(void (__thiscall ***)(const char *, signed int))v24)(v24, 1);
    v12 = hostStr.m_buffer;
  }
  v27 = udp_srv_addr;
  v28 = udp_srv_addr;
  *(_DWORD *)&udp_srv_addr->sin_family = 0;
  v28->sin_addr.S_un.S_addr = 0;
  *(_DWORD *)&v28->sin_zero[0] = 0;
  *(_DWORD *)&v28->sin_zero[4] = 0;
  v28->sin_family = 2;
  v27->sin_port = htons(v26);
  if ( !NetUtils::GetSinAddr(v6, &v27->sin_addr) )
  {
    v29 = result;
    result->vfptr = (PackObjVtbl *)&NetError::vftable;
    result->m_stringID = dword_8EDEB8;
    v30 = dword_8EDEBC;
LABEL_70:
    v29->m_tableID = v30;
    if ( !InterlockedDecrement((volatile LONG *)&v12->m_cRef) )
    {
      if ( v12 )
        v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
    }
    return v29;
  }
  v31 = socket(2, 2, 0);
  v32 = v51;
  v51->m_sockRead = v31;
  v32->m_sockWrite = v31;
  *(_DWORD *)&udp_cli_addr.sin_family = 0;
  udp_cli_addr.sin_addr.S_un.S_addr = 0;
  *(_DWORD *)&udp_cli_addr.sin_zero[0] = 0;
  *(_DWORD *)&udp_cli_addr.sin_zero[4] = 0;
  udp_cli_addr.sin_family = 2;
  udp_cli_addr.sin_addr.S_un.S_addr = htonl(0);
  InterfaceEnumerator::InterfaceEnumerator(&interfaceEnum);
  v33 = (u_long)CInputManager::GetMouseX((PlayerModule *)&interfaceEnum);
  v34 = HookAppraisalProfile::GetValidLocations((ChatDisplayInfo *)&interfaceEnum);
  if ( v33 )
  {
    v35 = Config->DesiredInterface.m_buffer;
    if ( v35->m_len != 1
      && (v36.m_buffer = Config->DesiredInterface.m_buffer,
          InterlockedIncrement((volatile LONG *)&v35->m_cRef),
          ParseInterfaceString(v36, (in_addr *)&port, (in_addr *)&host))
      && (v37 = 0, (signed int)v33 > 0) )
    {
      while ( ((unsigned int)host & *(_DWORD *)(v34 + 4 * v37)) != port )
      {
        ++v37;
        if ( v37 >= (signed int)v33 )
          goto LABEL_49;
      }
      v33 = *(_DWORD *)(v34 + 4 * v37);
      udp_cli_addr.sin_addr.S_un.S_addr = *(_DWORD *)(v34 + 4 * v37);
    }
    else
    {
LABEL_49:
      v33 = *(_DWORD *)v34;
    }
  }
  InterfaceEnumerator::~InterfaceEnumerator(&interfaceEnum);
  v38 = 0;
  if ( Config->bAutoGenerateUniquePort )
  {
    v39 = htonl(v33) % 0xFA07;
    v40 = (unsigned __int16)v39;
    while ( 1 )
    {
      v39 = (unsigned __int16)(v39 + 256);
      if ( v39 == v40 )
        break;
      if ( v39 >= 0x400 )
      {
        udp_cli_addr.sin_port = htons(v39);
        v38 = bind(v32->m_sockRead, (const struct sockaddr *)&udp_cli_addr, 16) == 0;
      }
      if ( v38 )
        goto LABEL_56;
    }
    v12 = hostStr.m_buffer;
  }
  else
  {
    v46 = htons(Config->dwPort);
    v47 = v32->m_sockRead;
    udp_cli_addr.sin_port = v46;
    v38 = bind(v47, (const struct sockaddr *)&udp_cli_addr, 16) == 0;
  }
  if ( v38 )
  {
LABEL_56:
    v41 = v32->m_sockRead;
    optlen = 4;
    getsockopt(v41, 0xFFFF, 4098, (char *)&MinRcv, &optlen);
    v42 = MinRcv;
    v43 = 0x20000;
    if ( MinRcv < 0x20000 )
    {
      do
      {
        v42 = (v43 + v42) / 2 + (v43 + v42) % 2;
        v44 = v51->m_sockRead;
        Config = (ClientNetConfiguration *)v42;
        setsockopt(v44, 0xFFFF, 4098, (const char *)&Config, 4);
        v45 = v51->m_sockRead;
        optlen = 4;
        getsockopt(v45, 0xFFFF, 4098, (char *)&Config, &optlen);
        if ( (signed int)Config >= v42 )
        {
          MinRcv = v42;
        }
        else
        {
          v43 = v42 - 1;
          v42 = MinRcv;
        }
      }
      while ( v42 < v43 );
      v32 = v51;
    }
    v49 = v32->m_sockRead;
    one = 1;
    ioctlsocket(v49, -2147195266, &one);
    v29 = result;
    v12 = hostStr.m_buffer;
    result->vfptr = (PackObjVtbl *)&NetError::vftable;
    result->m_stringID = ID_NetError_None.m_stringID;
    v30 = ID_NetError_None.m_tableID;
    goto LABEL_70;
  }
  v29 = result;
  result->vfptr = (PackObjVtbl *)&NetError::vftable;
  result->m_stringID = dword_8EDEC4;
  result->m_tableID = dword_8EDEC8;
  if ( !InterlockedDecrement((volatile LONG *)&v12->m_cRef) && v12 )
  {
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
    return result;
  }
  return v29;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 8EDEB8: using guessed type int dword_8EDEB8;
// 8EDEBC: using guessed type int dword_8EDEBC;
// 8EDEC4: using guessed type int dword_8EDEC4;
// 8EDEC8: using guessed type int dword_8EDEC8;

//----- (00545010) --------------------------------------------------------  // acclient.c:372602
NetError *__thiscall ClientNet::Init(ClientNet *this, NetError *result, int port, const char *host, DatIDStamp *dataVer, NetAuthenticator *pNetAuth, ClientNetConfiguration *Config)
{
  ClientNet *v7; // ebx@1
  ClientNetConfiguration *v8; // ebp@1
  unsigned int v9; // eax@1
  NetError *v10; // eax@2
  int v11; // ecx@2
  NetError *v12; // eax@3
  unsigned int v13; // esi@3
  int v14; // ebp@3
  NetError Ret; // [sp+10h] [bp-Ch]@1

  v7 = this;
  v8 = Config;
  Ret.m_tableID = ID_ConnectionError_Generic.m_tableID;
  Ret.m_stringID = ID_ConnectionError_Generic.m_stringID;
  memset(&this->m_CurrentLinkStatus, 0, sizeof(this->m_CurrentLinkStatus));
  qmemcpy(&this->m_Loggers, v8, sizeof(this->m_Loggers));
  v9 = Timer::get_real_time();
  v7->m_dwCurrentConnectionSequenceNumber = v9;
  v7->m_WorldSwitchHistory.bBeenSwitchedBefore = 0;
  v7->m_LogonSwitchHistory.bBeenSwitchedBefore = 0;
  if ( pNetAuth )
  {
    pNetAuth->m_dwConnectionSequenceNumber = v9;
    v12 = ClientNet::InitAddresses(v7, &Ret, host, port, &v7->m_LogonData.ServerAddr, v8);
    v13 = v12->m_stringID;
    v14 = v12->m_tableID;
    if ( ID_NetError_None.m_stringID == v13 && ID_NetError_None.m_tableID == v14 )
    {
      v7->m_LogonData.pNetAuth = pNetAuth;
      CAsyncStateMachine::AllocateAndBeginContext(&v7->m_ConnectionFSM, (AsyncContext *)&Config);
    }
    v10 = result;
    result->m_stringID = v13;
    result->m_tableID = v14;
    result->vfptr = (PackObjVtbl *)&NetError::vftable;
  }
  else
  {
    v10 = result;
    v11 = Ret.m_tableID;
    result->m_stringID = Ret.m_stringID;
    result->m_tableID = v11;
    result->vfptr = (PackObjVtbl *)&NetError::vftable;
  }
  return v10;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (00545100) --------------------------------------------------------  // acclient.c:372653
char __thiscall ClientNet::ProcessPacket(ClientNet *this, CNetLayerPacket *pkt)
{
  ClientNet *v2; // edi@1
  char result; // al@1
  char v4; // bl@1
  ReceiverData *v5; // esi@2

  v2 = this;
  result = SharedNet::ProcessPacket((SharedNet *)&this->vfptr, pkt);
  v4 = result;
  if ( result )
  {
    v5 = pkt->m_pRecv;
    if ( v5 )
    {
      if ( v5->m_ConnectionState == 4 )
      {
        if ( !(pkt->m_Hdr.header_ & 0x40000) )
        {
          v2->vfptr->SetConnectionState((SharedNet *)v2, pkt->m_Hdr.recID_, cs_Connected);
          LODWORD(v5->m_qwReferralCookie) = 0;
          HIDWORD(v5->m_qwReferralCookie) = 0;
          if ( v2->m_LogonData.bMyTurn )
            ClientNet::EndState(v2, &ID_NetError_None);
        }
      }
      else if ( v5->m_ConnectionState == 5 )
      {
        if ( v5->m_qwReferralCookie )
        {
          LODWORD(v5->m_qwReferralCookie) = 0;
          HIDWORD(v5->m_qwReferralCookie) = 0;
        }
        return result;
      }
    }
    result = v4;
  }
  return result;
}

//----- (005451A0) --------------------------------------------------------  // acclient.c:372695
bool __thiscall ClientNet::ProcessOptionalHeader(ClientNet *this, COptionalHeader *pHdr, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v3; // ebp@1
  ClientNet *v4; // esi@1
  char v5; // bl@1
  unsigned int v6; // eax@1
  sockaddr_in *v7; // esi@7
  bool result; // al@7
  int v9; // ecx@12
  unsigned int v10; // edx@12
  ReceiverData *v11; // ecx@19
  char *v12; // edi@21
  unsigned __int16 v13; // bp@23
  NetError Reason; // [sp+10h] [bp-Ch]@12

  v3 = pkt;
  v4 = this;
  v5 = SharedNet::ProcessOptionalHeader((SharedNet *)&this->vfptr, pHdr, pkt);
  v6 = pHdr->m_dwMask;
  if ( v6 > 0x100000 )
  {
    switch ( v6 )
    {
      case 0x200000u:
        Reason.vfptr = (PackObjVtbl *)&NetError::vftable;
        Reason.m_stringID = pHdr[1].m_Flags;
        v12 = pHdr[1].m_pData;
        Reason.m_tableID = (int)pHdr[1].m_pData;
        if ( ID_NetError_None.m_stringID != Reason.m_stringID || (char *)ID_NetError_None.m_tableID != v12 )
        {
          v13 = v3->m_Hdr.recID_;
          if ( v13 == v4->logonRecID_ )
          {
            ClientNet::NotifyPluginsOfStatusChange(v4, Net_LoginConnectionError, (int)&Reason, 0);
            return v5;
          }
          if ( v13 == v4->currServerRecID_ )
            ClientNet::NotifyPluginsOfStatusChange(v4, Net_WorldConnectionError, (int)&Reason, 0);
        }
        break;
      case 0x4000000u:
        v11 = v3->m_pRecv;
        v5 = 1;
        *(float *)&pkt = Timer::local_time - *(float *)&pHdr[1].vfptr - *(float *)&pHdr[1].m_cRef;
        *(float *)&v11[1].m_RecID = *(float *)&pkt;
        if ( v3->recipient_ == v4->currServerRecID_ )
        {
          CLinkStatusAverages::OnPingResponse(&v4->m_LinkStatusAverages, *(float *)&pkt);
          return 1;
        }
        break;
      case 0x8000000u:
        return 1;
    }
    return v5;
  }
  if ( v6 != 0x100000 )
  {
    if ( v6 > 0x800 )
    {
      if ( v6 == 0x40000 )
      {
        v4->vfptr[1].AddToPerfCounter((SharedNet *)v4, (NetPerfCounter)pHdr, (int)v3);
        return 1;
      }
    }
    else
    {
      if ( v6 == 2048 )
      {
        (*(void (__thiscall **)(ClientNet *, COptionalHeader *))&v4->vfptr[1].gap4[0])(v4, pHdr);
        return 1;
      }
      if ( v6 == 256 )
      {
        (*(void (__thiscall **)(ClientNet *, COptionalHeader *, CNetLayerPacket *))&v4->vfptr[1].gap4[4])(v4, pHdr, v3);
        return 1;
      }
      if ( v6 == 512 )
      {
        v7 = &v4->m_LogonData.ServerAddr;
        COnePrimHeader<512,7,sockaddr_in>::InqData((COnePrimHeader<512,7,sockaddr_in> *)pHdr, v7);
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&pkt);
        NetUtils::GetIPString(v7, (AC1Legacy::PStringBase<char> *)&pkt, 0);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&pkt);
        return 1;
      }
    }
    return v5;
  }
  v9 = (int)pHdr[1].m_pData;
  v10 = v4->m_LogonData.hCurrentContext.m_id;
  Reason.m_stringID = pHdr[1].m_Flags;
  Reason.m_tableID = v9;
  Reason.vfptr = (PackObjVtbl *)&NetError::vftable;
  if ( v10 == INVALID_ASYNCCONTEXT_7.m_id )
  {
    ClientNet::LogOffServer(v4);
    ECM_Login::SendNotice_ServerDied();
    result = 1;
  }
  else
  {
    ClientNet::EndState(v4, &Reason);
    result = 1;
  }
  return result;
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);

//----- (005453C0) --------------------------------------------------------  // acclient.c:372806
void __thiscall ClientNet::RemoveConnection(ClientNet *this, unsigned __int16 recID)
{
  ClientNet *v2; // esi@1
  PacketController *v3; // eax@2
  int v4; // eax@3
  ReceiverData *v5; // edi@3

  v2 = this;
  if ( PacketController::Instance() )
  {
    v3 = PacketController::Instance();
    PacketController::DeleteRecipient(v3, recID);
  }
  v4 = 136 * recID;
  v5 = (ReceiverData *)&v2->receivers_[v4];
  ReceiverData::RemoveFromQueue(v5, &v2->connectionsHead_, &v2->connectionsTail_);
  ReceiverData::Clear(v5);
  if ( (recID == v2->logonRecID_ || recID == v2->currServerRecID_) && !v2->logOffSent_ )
  {
    ClientNet::LogOffServer(v2);
    ECM_Login::SendNotice_ServerDied();
  }
}

//----- (00545440) --------------------------------------------------------  // acclient.c:372831
char __thiscall ClientNet::ProcessConnections(ClientNet *this)
{
  SharedNet *v1; // esi@1

  v1 = (SharedNet *)this;
  ClientNet::ProcessReferralQueue(this);
  return SharedNet::ProcessConnections(v1);
}

//----- (00545450) --------------------------------------------------------  // acclient.c:372841
char __thiscall ClientNet::ProcessConnection(ClientNet *this, ReceiverData *pReceiver)
{
  ClientNet *v2; // ebp@1
  char v3; // bl@1
  PacketController *v4; // eax@4
  RecipientData *v5; // eax@4
  ReceiverData *v6; // edx@9
  float v7; // eax@9
  long double v8; // st7@9
  ConnectionState v9; // edi@17
  unsigned int v10; // eax@19
  unsigned int v11; // ecx@19
  int v12; // edi@21
  unsigned __int16 v13; // dx@21
  ReferenceCountTemplate<1048576,0> *v14; // esi@21
  SharedNetVtbl *v15; // eax@21
  CReferralStruct v17; // [sp-20h] [bp-50h]@21
  ReceiverData *v18; // [sp-4h] [bp-34h]@4
  CReferralStruct data; // [sp+10h] [bp-20h]@21

  v2 = this;
  v3 = 1;
  switch ( pReceiver->m_ConnectionState )
  {
    case 4:
      if ( Timer::local_time - pReceiver->lastSentHandshake_ > 0.333333333 )
        ClientNet::SendConnectAck(this, pReceiver);
      break;
    case 6:
      v18 = (ReceiverData *)pReceiver->m_RecID;
      v4 = PacketController::Instance();
      v5 = PacketController::GetRecipient(v4, (unsigned __int16)v18);
      if ( !v5 || v5->m_ConnectionState == 7 )
        ReceiverData::SetConnectionState(pReceiver, cs_DisconnectSent);
      goto $L101044;
    case 5:
$L101044:
      if ( pReceiver->m_RecID == v2->currServerRecID_ && Timer::local_time - *(double *)&pReceiver[1].next_ >= 2.0 )
      {
        v6 = (ReceiverData *)HIDWORD(Timer::local_time);
        v7 = *(float *)&pReceiver[1].m_RecID;
        pReceiver[1].next_ = (ReceiverData *)LODWORD(Timer::local_time);
        pReceiver[1].prev_ = v6;
        v2->m_CurrentLinkStatus.RoundTripDelay = v7;
        v8 = Timer::local_time - pReceiver->m_LocalTimeLastGotData;
        v18 = (ReceiverData *)&v2->m_CurrentLinkStatus;
        v2->m_CurrentLinkStatus.TimeSinceLastGotData = v8;
        v2->m_CurrentLinkStatus.SnapshotDuration = Timer::local_time - v2->m_LinkStatusAverages.m_LocalTimeOfSnapshot;
        CLinkStatusAverages::AddSnapshot(&v2->m_LinkStatusAverages, (CLinkStatusSnapshot *)v18);
        ClientNet::NotifyPluginsOfHeartbeat(v2);
        memset(&v2->m_CurrentLinkStatus, 0, sizeof(v2->m_CurrentLinkStatus));
      }
      if ( pReceiver->m_SeqIDsWeNAKed._currNum )
      {
        v18 = pReceiver;
        pReceiver->m_NakState = 1;
        SharedNet::EnqueueNaks(v18);
      }
      else
      {
        v18 = pReceiver;
        pReceiver->m_NakState = 2;
        SharedNet::EnqueuePak(v18);
      }
      break;
    case 7:
      ClientNet::RemoveConnection(this, pReceiver->m_RecID);
      break;
    default:
      v3 = 0;
      break;
  }
  if ( COERCE_DOUBLE(Timer::cur_time.Cmd) - v2->lastDidUseTime_ < 140.0
    && Timer::local_time - pReceiver->m_LocalTimeLastGotData > 140.0 )
  {
    v9 = pReceiver->m_ConnectionState;
    if ( (signed int)v9 < 6 )
    {
      v2->vfptr->SetConnectionState((SharedNet *)v2, pReceiver->m_RecID, cs_DisconnectReceived);
      if ( v9 == 5 )
      {
        v10 = LODWORD(pReceiver->m_qwReferralCookie);
        v11 = HIDWORD(pReceiver->m_qwReferralCookie);
        if ( pReceiver->m_qwReferralCookie )
        {
          if ( !v2->logOffSent_ )
          {
            *(_DWORD *)&data.Addr.sin_family = *(_DWORD *)&pReceiver->m_Addr.sin_family;
            data.Addr.sin_addr.S_un.S_addr = pReceiver->m_Addr.sin_addr.S_un.S_addr;
            v12 = *(_DWORD *)&pReceiver->m_Addr.sin_zero[0];
            *(_DWORD *)&data.Addr.sin_zero[4] = *(_DWORD *)&pReceiver->m_Addr.sin_zero[4];
            v13 = pReceiver->m_RecID;
            *(_DWORD *)&data.Addr.sin_zero[0] = v12;
            data.idServer = v13;
            data.qwCookie = __PAIR__(v11, v10);
            qmemcpy(&v17, &data, sizeof(v17));
            v14 = (ReferenceCountTemplate<1048576,0> *)COnePrimHeader<2048,1073741922,CReferralStruct>::CreateFromData(v17);
            v15 = v2->vfptr;
            v18 = (ReceiverData *)v14;
            (*(void (__thiscall **)(ClientNet *, ReferenceCountTemplate<1048576,0> *))&v15[1].gap4[0])(v2, v14);
            ReferenceCountTemplate<1048576,0>::Release(v14);
          }
        }
      }
    }
  }
  return v3;
}

//----- (00545670) --------------------------------------------------------  // acclient.c:372951
char __thiscall SmartArray<ClientNet::CReferralQueueEntry,1>::AddToEnd(SmartArray<ClientNet::CReferralQueueEntry,1> *this, ClientNet::CReferralQueueEntry *i_rData)
{
  SmartArray<ClientNet::CReferralQueueEntry,1> *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<ClientNet::CReferralQueueEntry,1>::grow(v2, v4)) != 0) )
  {
    qmemcpy(&v2->m_data[v2->m_num++], i_rData, sizeof(v2->m_data[v2->m_num++]));
    result = 1;
  }
  return result;
}

//----- (005456D0) --------------------------------------------------------  // acclient.c:372971
AC1Legacy::PStringBase<char> *__thiscall AC1Legacy::PStringBase<unsigned short>::to_spstring(AC1Legacy::PStringBase<unsigned short> *this, AC1Legacy::PStringBase<char> *result, const unsigned __int16 i_targetCodePage)
{
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PStringBase<unsigned short> *v4; // ebx@1
  volatile LONG *v5; // edi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v6; // ecx@1
  AC1Legacy::PStringBase<char> *v7; // ebx@2
  const char *v9; // ebp@5
  int *v10; // ebx@5
  int v11; // esi@15
  unsigned int v12; // ebp@18
  int v13; // ebx@21
  signed int v14; // edi@21
  volatile LONG v15; // eax@23
  unsigned int v16; // ecx@23
  int v17; // eax@24
  unsigned __int16 v18; // bx@26
  int v19; // esi@27
  int v20; // edi@35
  volatile LONG v21; // eax@39
  int v22; // ecx@39
  int v23; // esi@39
  int v24; // eax@39
  DWORD v25; // ST10_4@40
  DWORD v26; // eax@40
  int v27; // esi@40
  volatile LONG *v28; // edi@40
  volatile LONG *v29; // ST10_4@40
  int v30; // [sp+0h] [bp-50h]@40
  int v31; // [sp+4h] [bp-4Ch]@39
  volatile LONG *v32; // [sp+Ch] [bp-44h]@27
  AC1Legacy::PStringBase<char> *v33; // [sp+14h] [bp-3Ch]@40
  int v34; // [sp+20h] [bp-30h]@18
  signed int v35; // [sp+24h] [bp-2Ch]@16
  signed int v36; // [sp+28h] [bp-28h]@22
  volatile LONG *v37; // [sp+2Ch] [bp-24h]@2
  int v38; // [sp+34h] [bp-1Ch]@35
  int v39; // [sp+38h] [bp-18h]@27
  AC1Legacy::PStringBase<char> ret_str; // [sp+40h] [bp-10h]@1
  int fCouldNotConvertACharacter; // [sp+44h] [bp-Ch]@5
  AC1Legacy::PStringBase<unsigned short> *v42; // [sp+4Ch] [bp-4h]@1

  v3 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v4 = this;
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v42 = this;
  ret_str.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v6 = v4->m_buffer;
  if ( v4->m_buffer->m_len == 1 )
  {
    v7 = result;
    v37 = v5;
    result->m_buffer = v3;
    InterlockedIncrement(v37);
    if ( !InterlockedDecrement(v5) && v3 )
    {
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
      return result;
    }
    return v7;
  }
  fCouldNotConvertACharacter = 0;
  v9 = "?";
  v10 = &fCouldNotConvertACharacter;
  if ( (signed int)i_targetCodePage > 52936 )
  {
    if ( (signed int)i_targetCodePage > 57011 )
    {
      if ( (signed int)i_targetCodePage < 65000 || (signed int)i_targetCodePage > 65001 )
        goto LABEL_15;
    }
    else if ( (signed int)i_targetCodePage < 57002 && i_targetCodePage != 54936 )
    {
      goto LABEL_15;
    }
$L77039:
    v10 = 0;
    v9 = 0;
    goto LABEL_15;
  }
  if ( i_targetCodePage == 52936 )
    goto $L77039;
  switch ( i_targetCodePage )
  {
    case 0xC42Cu:
    case 0xC42Du:
    case 0xC42Eu:
    case 0xC431u:
    case 0xC433u:
    case 0xC435u:
      goto $L77039;
    default:
      break;
  }
LABEL_15:
  v11 = WideCharToMultiByte(i_targetCodePage, 0, v6->m_data, v6->m_len, 0, 0, v9, v10);
  if ( v11 )
  {
    if ( !v35 )
    {
      AC1Legacy::PStringBase<char>::allocate_ref_buffer((AC1Legacy::PStringBase<char> *)&v34, v11);
      v21 = *v37;
      v22 = *(_DWORD *)(*v37 + 8);
      v31 = v11;
      v23 = v34;
      v24 = WideCharToMultiByte(i_targetCodePage, 0, (LPCWSTR)(v21 + 20), v22, (LPSTR)(v34 + 20), v31, v9, v10);
      if ( v24 )
      {
        v7 = v33;
        *(_DWORD *)(v23 + 8) = v24;
        v7->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v23;
        InterlockedIncrement((volatile LONG *)(v23 + 4));
        if ( !InterlockedDecrement((volatile LONG *)(v23 + 4)) )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
      }
      else
      {
        v25 = GetLastError();
        v26 = GetLastError();
        AC1Legacy::PStringBase<char>::sprintf(
          (AC1Legacy::PStringBase<char> *)&v30,
          "Failed conversion to codepage %hu! GetLastError %d (0x%08x)\n",
          i_targetCodePage,
          v26,
          v25);
        v27 = v30;
        v7 = v33;
        v28 = (volatile LONG *)(v30 + 4);
        v29 = (volatile LONG *)(v30 + 4);
        v33->m_buffer = (AC1Legacy::PSRefBuffer<char> *)v30;
        InterlockedIncrement(v29);
        if ( !InterlockedDecrement(v28) && v27 )
        {
          (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
          return v7;
        }
      }
      return v7;
    }
  }
  else
  {
    v35 = 1;
  }
  v12 = *(_DWORD *)(*v37 + 8) - 1;
  if ( !InterlockedDecrement((volatile LONG *)(v34 + 4)) && v34 )
    (**(void (__stdcall ***)(_DWORD))v34)(1);
  AC1Legacy::PStringBase<char>::allocate_ref_buffer((AC1Legacy::PStringBase<char> *)&v34, v12);
  v13 = v34;
  v14 = 0;
  *(_DWORD *)(v34 + 8) = 1;
  if ( (signed int)v12 > 0 )
  {
    v36 = 20;
    do
    {
      v15 = *v37;
      v16 = *(_DWORD *)(*v37 + 8);
      if ( v14 < v16 )
        v17 = v36 + v15;
      else
        v17 = v15 + 2 * v16 + 18;
      v18 = *(_WORD *)v17;
      if ( *(_WORD *)v17 <= 0x7Fu )
      {
        LOBYTE(v39) = *(_WORD *)v17;
        AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&v34, (const char *)&v39, 1u);
      }
      else
      {
        v39 = AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        v32 = (volatile LONG *)v18;
        AC1Legacy::PStringBase<char>::sprintf((AC1Legacy::PStringBase<char> *)&v39, "<%04x>", v18);
        v19 = v39;
        if ( v39 != AC1Legacy::PStringBase<char>::s_NullBuffer )
          AC1Legacy::PStringBase<char>::append_n_chars(
            (AC1Legacy::PStringBase<char> *)&v34,
            (const char *)(v39 + 20),
            *(_DWORD *)(v39 + 8) - 1);
        if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
      }
      ++v14;
      v36 += 2;
    }
    while ( v14 < (signed int)v12 );
    v13 = v34;
  }
  v20 = v38;
  v32 = (volatile LONG *)(v13 + 4);
  *(_DWORD *)v38 = v13;
  InterlockedIncrement(v32);
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  return (AC1Legacy::PStringBase<char> *)v20;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005459D0) --------------------------------------------------------  // acclient.c:373172
void __thiscall ClientNet::~ClientNet(ClientNet *this)
{
  ClientNet *v1; // esi@1
  ClientNet *v2; // ebp@1
  signed int v3; // edi@1
  char *v4; // ebx@1
  int v5; // eax@8
  unsigned int i; // ecx@10
  unsigned int v7; // ecx@12

  v1 = this;
  v2 = (ClientNet *)((char *)this - 34952);
  *(_DWORD *)&this[-1].receivers_[1064] = &ClientNet::vftable;
  this->vfptr = (SharedNetVtbl *)&ClientNet::vftable;
  v3 = 0;
  v4 = &this[-1].receivers_[1096];
  do
  {
    if ( *(_WORD *)v4 )
      ClientNet::RemoveConnection(v2, v3);
    ++v3;
    v4 += 136;
  }
  while ( v3 < 256 );
  closesocket(*(_DWORD *)&v1[-1].receivers_[1076]);
  FlowQueue::SharedStaticCleanup();
  if ( (*(_DWORD *)&v1->receivers_[444] & 0x80000000) == 0x80000000 )
    operator delete[](*(void **)&v1->receivers_[440]);
  CAsyncStateMachine::~CAsyncStateMachine((CAsyncStateMachine *)&v1->receivers_[68]);
  *(_DWORD *)&v1->receivers_[56] = &PackObj::vftable;
  if ( v1 == (ClientNet *)34952 )
    v5 = 0;
  else
    v5 = (int)&v1->receivers_[8];
  for ( i = 0; i < *(_DWORD *)(v5 + 8); ++i )
    *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v5 + 4 * i) + 4) = 0;
  v7 = *(_DWORD *)(v5 + 4) & 0x80000000;
  *(_DWORD *)(v5 + 8) = 0;
  if ( v7 == 0x80000000 )
    operator delete[](*(void **)v5);
  CAsyncStateHandler::~CAsyncStateHandler((CAsyncStateHandler *)(v1 != (ClientNet *)34952 ? (unsigned int)v1 : 0));
  SharedNet::~SharedNet((SharedNet *)&v2->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CA140: using guessed type int (__stdcall *ClientNet::vftable)(char);
// 7CA160: using guessed type void (__thiscall *ClientNet::vftable)(ClientNet *this, NetPerfCounter WhichCounter, int);

//----- (00545AC0) --------------------------------------------------------  // acclient.c:373220
void __thiscall ClientNet::HandleConnectionRequest(ClientNet *this, CConnectHeader *pConnectHeader, CNetLayerPacket *pkt)
{
  CNetLayerPacket *v3; // ebx@1
  ReceiverData *v4; // ebp@1
  ClientNet *v5; // esi@1
  unsigned __int16 v6; // ax@2
  unsigned __int16 v7; // cx@2
  unsigned __int16 v8; // dx@3
  int v9; // edi@3
  char *v10; // edi@9
  NetKeyExch *v11; // eax@9
  NetKeyExch *v12; // eax@10
  AC1Legacy::vlong *v13; // eax@12
  sockaddr_in v14; // ST00_16@12
  sockaddr_in v15; // ST10_16@12
  unsigned __int16 v16; // ST0C_2@12
  PacketController *v17; // eax@12
  unsigned int v18; // edx@14
  int v19; // eax@15
  AC1Legacy::PSRefBuffer<char> *v20; // esi@20
  AC1Legacy::PStringBase<char> result; // [sp+10h] [bp-10h]@9
  AC1Legacy::vlong v22; // [sp+14h] [bp-Ch]@12
  NetKeyExch *pkta; // [sp+28h] [bp+8h]@10

  v3 = pkt;
  v4 = pkt->m_pRecv;
  v5 = this;
  if ( v4->m_RecID )
  {
    v6 = v4->iteration_;
    v7 = pkt->m_Hdr.iteration_;
    if ( v7 == v6 )
      return;
    v8 = v7 - v6;
    v9 = 1;
    if ( v7 < v6 )
    {
      v8 = v6 - v7;
      v9 = -1;
    }
    if ( v8 > 0x7FFFu )
      v9 = -v9;
    if ( v9 <= 0 )
      return;
    ClientNet::RemoveConnection(v5, pkt->m_Hdr.recID_);
  }
  result.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v10 = (char *)&pkt->m_Addr;
  NetUtils::GetIPString(&pkt->m_Addr, &result, 0);
  v11 = (NetKeyExch *)operator new(0x18u);
  if ( v11 )
  {
    NetKeyExch::NetKeyExch(v11, v5->dh_);
    pkta = v12;
  }
  else
  {
    pkta = 0;
  }
  AC1Legacy::vlong::vlong(&v22, 0xAu);
  NetKeyExch::SetPrivateRandom(pkta, v13);
  AC1Legacy::vlong::~vlong(&v22);
  *(_DWORD *)&v14.sin_family = *(_DWORD *)v10;
  v14.sin_addr.S_un.S_addr = v3->m_Addr.sin_addr.S_un.S_addr;
  *(_QWORD *)&v14.sin_zero[0] = *(_QWORD *)&v3->m_Addr.sin_zero[0];
  ReceiverData::Init(
    v4,
    v14,
    1u,
    v3->m_Hdr.recID_,
    LOWORD(pConnectHeader->m_Data.NetID),
    v3->m_Hdr.iteration_,
    v3->m_Hdr.interval_,
    pkta,
    pConnectHeader->m_Data.OutgoingSeed,
    pConnectHeader->m_Data.IncomingSeed);
  *(_DWORD *)&v15.sin_family = *(_DWORD *)v10;
  *(_QWORD *)&v15.sin_addr.S_un.S_un_b.s_b1 = *(_QWORD *)&v3->m_Addr.sin_addr.S_un.S_un_b.s_b1;
  *(_DWORD *)&v15.sin_zero[4] = *(_DWORD *)&v3->m_Addr.sin_zero[4];
  v16 = v3->m_Hdr.recID_;
  v17 = PacketController::Instance();
  PacketController::AddRecipient(v17, v16, v15, 0, 0.0, 0, 0);
  ReceiverData::AddToQueue(v4, &v5->connectionsHead_, &v5->connectionsTail_);
  v4->m_NakState = 2;
  if ( !v5->logonRecID_ )
  {
    v5->logonRecID_ = v3->m_Hdr.recID_;
    v5->currServerRecID_ = v3->m_Hdr.recID_;
  }
  v18 = 0;
  if ( v5->m_ReferralQueue.m_num )
  {
    v19 = (int)&v5->m_ReferralQueue.m_data->idServer;
    while ( *(_WORD *)v19 != v3->m_Hdr.recID_ )
    {
      ++v18;
      v19 += 40;
      if ( v18 >= v5->m_ReferralQueue.m_num )
        goto LABEL_20;
    }
    SmartArray<ClientNet::CReferralQueueEntry,1>::RemoveUnOrderedByIndex(&v5->m_ReferralQueue, v18);
  }
LABEL_20:
  v4->m_qwReferralCookie = pConnectHeader->m_Data.qwCookie;
  v5->vfptr->SetConnectionState((SharedNet *)v5, v3->m_Hdr.recID_, cs_ConnectionRequestAcked);
  ClientNet::SendConnectAck(v5, v4);
  v20 = result.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&result.m_buffer->m_cRef) )
  {
    if ( v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00545D00) --------------------------------------------------------  // acclient.c:373337
int __thiscall ClientNet::scalar_deleting_destructor(ClientNet *this, char a2)
{
  ClientNet *v2; // esi@1
  int result; // eax@1

  v2 = this;
  ClientNet::~ClientNet(this);
  result = (int)&v2[-1].receivers_[1064];
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].receivers_[1064]);
    result = (int)&v2[-1].receivers_[1064];
  }
  return result;
}

//----- (00545D30) --------------------------------------------------------  // acclient.c:373354
void __thiscall ClientNet::HandleReferral(ClientNet *this, COnePrimHeader<2048,1073741922,CReferralStruct> *pRefHdr)
{
  unsigned __int16 v2; // bx@1
  ClientNet *v3; // edi@1
  int v4; // eax@2
  char *v5; // esi@2
  unsigned int v6; // edx@6
  unsigned int v7; // ecx@6
  int v8; // eax@7
  unsigned int v9; // ecx@10
  int v10; // eax@10
  unsigned int v11; // edx@10
  unsigned int v12; // eax@10
  ClientNet::CReferralQueueEntry Referral; // [sp+Ch] [bp-28h]@10

  v2 = pRefHdr->m_Prim.idServer;
  v3 = this;
  if ( v2 < 0x100u )
  {
    v4 = 136 * v2;
    v5 = &this->receivers_[v4];
    if ( (ClientNet *)((char *)this + v4) != (ClientNet *)-32 )
    {
      if ( *(_DWORD *)&this->receivers_[v4 + 72] > 5 )
        ClientNet::RemoveConnection(this, *(_WORD *)v5);
      if ( *(_WORD *)v5 )
      {
        *((_QWORD *)v5 + 14) = pRefHdr->m_Prim.qwCookie;
      }
      else
      {
        v6 = v3->m_ReferralQueue.m_num;
        v7 = 0;
        if ( v6 )
        {
          v8 = (int)&v3->m_ReferralQueue.m_data->idServer;
          while ( *(_WORD *)v8 != v2 )
          {
            ++v7;
            v8 += 40;
            if ( v7 >= v6 )
              goto LABEL_10;
          }
        }
        else
        {
LABEL_10:
          v9 = pRefHdr->m_Prim.Addr.sin_addr.S_un.S_addr;
          *(_DWORD *)&Referral.ServerAddr.sin_family = *(_DWORD *)&pRefHdr->m_Prim.Addr.sin_family;
          v10 = *(_DWORD *)&pRefHdr->m_Prim.Addr.sin_zero[0];
          Referral.ServerAddr.sin_addr.S_un.S_addr = v9;
          v11 = LODWORD(pRefHdr->m_Prim.qwCookie);
          *(_DWORD *)&Referral.ServerAddr.sin_zero[4] = *(_DWORD *)&pRefHdr->m_Prim.Addr.sin_zero[4];
          *(_DWORD *)&Referral.ServerAddr.sin_zero[0] = v10;
          v12 = HIDWORD(pRefHdr->m_Prim.qwCookie);
          *(_QWORD *)&Referral.localtimeToSendNextWorldAuth = 0i64;
          Referral.qwCookie = __PAIR__(v12, v11);
          Referral.nAuthsSent = 0;
          Referral.idServer = v2;
          SmartArray<ClientNet::CReferralQueueEntry,1>::AddToEnd(&v3->m_ReferralQueue, &Referral);
          ClientNet::ProcessReferralQueue(v3);
        }
      }
    }
  }
}

//----- (00545E20) --------------------------------------------------------  // acclient.c:373422
bool __cdecl PerfMonCounterFactory::CreateNewCounter(PerfMonCounter<unsigned __int64> **pOut, PerfMonCounterInfo::EPerfCounterType counterType, PStringBase<unsigned short> *name, PStringBase<unsigned short> *help, const unsigned __int16 language)
{
  void *v5; // esi@1
  bool result; // al@2

  v5 = operator new(0x28u);
  if ( v5 )
  {
    PerfMonCounterInfo::PerfMonCounterInfo((PerfMonCounterInfo *)v5, counterType, name, help, language);
    *(_DWORD *)v5 = &PerfMonCounter<unsigned __int64>::vftable;
    *((_DWORD *)v5 + 8) = 0;
    *((_DWORD *)v5 + 9) = 0;
    *pOut = (PerfMonCounter<unsigned __int64> *)v5;
    result = v5 != 0;
  }
  else
  {
    *pOut = 0;
    result = 0;
  }
  return result;
}
// 7C9E94: using guessed type int (__thiscall *PerfMonCounter<unsigned __int64>::vftable)(void *, char);

//----- (00545E80) --------------------------------------------------------  // acclient.c:373447
void __thiscall SharedNet::SharedNet(SharedNet *this, unsigned __int16 netID)
{
  SharedNet *v2; // esi@1
  ReceiverData *v3; // edi@1
  signed int v4; // ebx@1
  AC1Legacy::vlong *v5; // eax@3
  AC1Legacy::vlong *v6; // edi@3
  PortalDH *v7; // eax@4
  CNetLayerPacket *v8; // eax@6
  unsigned int v9; // eax@6
  unsigned int v10; // eax@6
  PerfMonCounterInfo *v11; // eax@6
  int v12; // ebp@9
  char *v13; // ebp@12
  unsigned int v14; // eax@15
  unsigned int v15; // eax@15
  PerfMonCounterInfo *v16; // eax@15
  int v17; // ebp@18
  char *v18; // ebp@21
  unsigned int v19; // eax@24
  unsigned int v20; // eax@24
  PerfMonCounterInfo *v21; // eax@24
  int v22; // ebp@27
  char *v23; // ebp@30
  unsigned int v24; // eax@33
  unsigned int v25; // eax@33
  PerfMonCounterInfo *v26; // eax@33
  int v27; // ebp@36
  char *v28; // ebp@39
  unsigned int v29; // eax@42
  unsigned int v30; // eax@42
  PerfMonCounterInfo *v31; // eax@42
  int v32; // edi@45
  char *v33; // edi@48
  PStringBase<unsigned short> help; // [sp+24h] [bp-1Ch]@6
  AC1Legacy::vlong shared_prime; // [sp+28h] [bp-18h]@3
  AC1Legacy::vlong shared_base; // [sp+34h] [bp-Ch]@3

  v2 = this;
  this->vfptr = (SharedNetVtbl *)&SharedNet::vftable;
  NetInitializer::NetInitializer();
  v2->m_sockRead = -1;
  v2->m_sockWrite = -1;
  v2->netID_ = netID;
  v3 = (ReceiverData *)v2->receivers_;
  v4 = 256;
  do
  {
    ReceiverData::ReceiverData(v3);
    v3 = (ReceiverData *)((char *)v3 + 136);
    --v4;
  }
  while ( v4 );
  v2->connectionsHead_ = 0;
  v2->connectionsTail_ = 0;
  LODWORD(v2->lastDidUseTime_) = 0;
  HIDWORD(v2->lastDidUseTime_) = 0;
  v2->m_UseTime_TimeLimit.m_dwInterval = 50;
  v2->m_UseTime_TimeLimit.m_dwStart = GetTickCount();
  v2->m_Loggers.pfnRecvLogger = 0;
  v2->m_Loggers.pfnSendLogger = 0;
  v2->m_Loggers.pfnUncompressedRecvLogger = 0;
  v2->m_Loggers.pfnUncompressedSendLogger = 0;
  v2->m_Loggers.dwUserLoggingData = 0;
  SharedNet::s_pNet = v2;
  AC1Legacy::vlong::vlong(&shared_base, 0);
  AC1Legacy::vlong::vlong(&shared_prime, 0);
  v5 = (AC1Legacy::vlong *)operator new(0x18u);
  v6 = v5;
  if ( v5 )
  {
    AC1Legacy::vlong::vlong(v5, 0);
    AC1Legacy::vlong::vlong(v6 + 1, 0);
    v7 = (PortalDH *)v6;
  }
  else
  {
    v7 = 0;
  }
  v2->dh_ = v7;
  AC1Legacy::vlong::read_from_hex_string(
    &shared_base,
    "dd80c2e508b630998076a9f7319c930d954f2866f53932baa2938467f25ed069");
  AC1Legacy::vlong::read_from_hex_string(
    &shared_prime,
    "dd80c2e508b630998076a9f7319c930d954f2866f53932baa2938467f2602bfb");
  PortalDH::Init(v2->dh_, &shared_base, &shared_prime);
  AC1Legacy::vlong::~vlong(&shared_prime);
  AC1Legacy::vlong::~vlong(&shared_base);
  memset(&v2->m_packetStatsIncoming, 0, sizeof(v2->m_packetStatsIncoming));
  CNetLayerPacket::Create();
  v2->m_pIncomingPacket = v8;
  v9 = _wcslen(L"Bytes sent via 'sendto' calls.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v9);
  _wcscpy(help.m_charbuffer->m_data, L"Bytes sent via 'sendto' calls.");
  v10 = _wcslen(L"Net - Bytes sent/sec");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&netID, v10);
  _wcscpy((wchar_t *)netID, L"Net - Bytes sent/sec");
  v11 = PerfMonCounterInfo::LookupExistingCounterByName((PStringBase<unsigned short> *)&netID, 9);
  if ( v11 )
    v2->m_pBytesSentCounter = (PerfMonCounter<unsigned __int64> *)v11;
  else
    PerfMonCounterFactory::CreateNewCounter(
      &v2->m_pBytesSentCounter,
      PER_SEC,
      (PStringBase<unsigned short> *)&netID,
      &help,
      9u);
  v12 = netID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(netID - 20 + 4)) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  v13 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  v14 = _wcslen(L"Bytes received.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v14);
  _wcscpy(help.m_charbuffer->m_data, L"Bytes received.");
  v15 = _wcslen(L"Net - Bytes received/sec");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&netID, v15);
  _wcscpy((wchar_t *)netID, L"Net - Bytes received/sec");
  v16 = PerfMonCounterInfo::LookupExistingCounterByName((PStringBase<unsigned short> *)&netID, 9);
  if ( v16 )
    v2->m_pBytesReceivedCounter = (PerfMonCounter<unsigned __int64> *)v16;
  else
    PerfMonCounterFactory::CreateNewCounter(
      &v2->m_pBytesReceivedCounter,
      PER_SEC,
      (PStringBase<unsigned short> *)&netID,
      &help,
      9u);
  v17 = netID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(netID - 20 + 4)) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  v18 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  v19 = _wcslen(L"Packet rejection rate.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v19);
  _wcscpy(help.m_charbuffer->m_data, L"Packet rejection rate.");
  v20 = _wcslen(L"Net - Bad packets received/sec");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&netID, v20);
  _wcscpy((wchar_t *)netID, L"Net - Bad packets received/sec");
  v21 = PerfMonCounterInfo::LookupExistingCounterByName((PStringBase<unsigned short> *)&netID, 9);
  if ( v21 )
    v2->m_pBadPacketsReceivedCounter = (PerfMonCounter<unsigned __int64> *)v21;
  else
    PerfMonCounterFactory::CreateNewCounter(
      &v2->m_pBadPacketsReceivedCounter,
      PER_SEC,
      (PStringBase<unsigned short> *)&netID,
      &help,
      9u);
  v22 = netID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(netID - 20 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  v23 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  v24 = _wcslen(L"Total rejected packets.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v24);
  _wcscpy(help.m_charbuffer->m_data, L"Total rejected packets.");
  v25 = _wcslen(L"Net - Total bad packets received");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&netID, v25);
  _wcscpy((wchar_t *)netID, L"Net - Total bad packets received");
  v26 = PerfMonCounterInfo::LookupExistingCounterByName((PStringBase<unsigned short> *)&netID, 9);
  if ( v26 )
    v2->m_pBadPacketsReceivedRawCounter = (PerfMonCounter<unsigned __int64> *)v26;
  else
    PerfMonCounterFactory::CreateNewCounter(
      &v2->m_pBadPacketsReceivedRawCounter,
      0,
      (PStringBase<unsigned short> *)&netID,
      &help,
      9u);
  v27 = netID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(netID - 20 + 4)) && v27 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
  v28 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) && v28 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
  v29 = _wcslen(L"Rate at which we have had to re-send a packet.");
  PStringBase<unsigned short>::allocate_ref_buffer(&help, v29);
  _wcscpy(help.m_charbuffer->m_data, L"Rate at which we have had to re-send a packet.");
  v30 = _wcslen(L"Net - Packets retransmitted/sec");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&netID, v30);
  _wcscpy((wchar_t *)netID, L"Net - Packets retransmitted/sec");
  v31 = PerfMonCounterInfo::LookupExistingCounterByName((PStringBase<unsigned short> *)&netID, 9);
  if ( v31 )
    v2->m_pPacketsRetransmittedCounter = (PerfMonCounter<unsigned __int64> *)v31;
  else
    PerfMonCounterFactory::CreateNewCounter(
      &v2->m_pPacketsRetransmittedCounter,
      PER_SEC,
      (PStringBase<unsigned short> *)&netID,
      &help,
      9u);
  v32 = netID - 20;
  if ( !InterlockedDecrement((volatile LONG *)(netID - 20 + 4)) && v32 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
  v33 = (char *)&help.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&help.m_charbuffer[-1].m_data[8]) )
  {
    if ( v33 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
  }
}
// 7CA090: using guessed type void (__thiscall *SharedNet::vftable)(SharedNet *this, NetPerfCounter WhichCounter, int);

//----- (00546360) --------------------------------------------------------  // acclient.c:373656
void __thiscall ClientNet::ClientNet(ClientNet *this)
{
  ClientNet *v1; // esi@1
  int v2; // ebp@1
  int v3; // edi@1
  unsigned int v4; // eax@1

  v1 = this;
  SharedNet::SharedNet((SharedNet *)&this->vfptr, 0);
  v2 = (int)&v1->vfptr;
  CAsyncStateHandler::CAsyncStateHandler((CAsyncStateHandler *)&v1->vfptr, 0);
  *(_DWORD *)v2 = &CClientsideLoginStateHandler::vftable;
  v1->m_Plugins.m_data = 0;
  v1->m_Plugins.m_sizeAndDeallocate = 0;
  v1->m_Plugins.m_num = 0;
  v1->vfptr = (SharedNetVtbl *)&ClientNet::vftable;
  *(_DWORD *)v2 = &ClientNet::vftable;
  v3 = (int)&v1->m_LogonData;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 36) = &NetError::vftable;
  CAsyncStateMachine::CAsyncStateMachine(&v1->m_ConnectionFSM);
  v1->m_ReferralQueue.m_data = 0;
  v1->m_ReferralQueue.m_sizeAndDeallocate = 0;
  v1->m_ReferralQueue.m_num = 0;
  v1->logonRecID_ = 0;
  v1->currServerRecID_ = 0;
  v1->m_dwCurrentConnectionSequenceNumber = 0;
  v1->m_WorldSwitchHistory.LastSwitchStamp.m_timestamp = 0;
  v1->m_LogonSwitchHistory.LastSwitchStamp.m_timestamp = 0;
  v1->logOffSent_ = 0;
  v1->fCurrentlyInGame_ = 0;
  CLinkStatusAverages::CLinkStatusAverages(&v1->m_LinkStatusAverages);
  memset(&v1->m_LogonData, 0, sizeof(v1->m_LogonData));
  v4 = Timer::get_real_time();
  _srand(v4);
  FlowQueue::SharedStaticInit();
  CAsyncStateMachine::AddStateHandler(&v1->m_ConnectionFSM, (CAsyncStateHandler *)&v1->vfptr);
}
// 794878: using guessed type int (__thiscall *NetError::vftable)(void *, char);
// 7CA054: using guessed type int (__thiscall *CClientsideLoginStateHandler::vftable)(void *, char);
// 7CA140: using guessed type int (__stdcall *ClientNet::vftable)(char);
// 7CA160: using guessed type void (__thiscall *ClientNet::vftable)(ClientNet *this, NetPerfCounter WhichCounter, int);

//----- (007055B0) --------------------------------------------------------  // acclient.c:792592
int _E77_7()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_24;
  INITIAL_MAX_DATA_RATE_98 = LOWEST_DATA_RATE_24;
  return result;
}

//----- (007055C0) --------------------------------------------------------  // acclient.c:792602
int sub_7055C0()
{
  return atexit(nullsub_1203);
}

