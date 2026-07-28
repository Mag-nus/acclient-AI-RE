/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ReceiverData
   Object     : PORTAL\clinet\ReceiverData.obj
   Functions  : 18
   Addresses  : 00548C60 - 007056B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00548C60) --------------------------------------------------------  // acclient.c:376160
void __thiscall ReceiverData::AddToQueue(ReceiverData *this, ReceiverData **head, ReceiverData **tail)
{
  if ( *head )
  {
    (*tail)->next_ = this;
    this->prev_ = *tail;
    *tail = this;
  }
  else
  {
    *head = this;
    *tail = this;
  }
}

//----- (00548C90) --------------------------------------------------------  // acclient.c:376176
void __thiscall ReceiverData::RemoveFromQueue(ReceiverData *this, ReceiverData **head, ReceiverData **tail)
{
  ReceiverData *v3; // edx@1
  ReceiverData *v4; // esi@2
  ReceiverData *v5; // edx@6

  v3 = this->prev_;
  if ( !v3 )
    goto LABEL_11;
  v4 = this->next_;
  if ( v4 )
  {
    v3->next_ = v4;
    this->next_->prev_ = this->prev_;
    this->prev_ = 0;
    this->next_ = 0;
    return;
  }
  if ( v3 )
  {
    v3->next_ = 0;
    *tail = this->prev_;
    this->prev_ = 0;
    this->next_ = 0;
  }
  else
  {
LABEL_11:
    v5 = this->next_;
    if ( v5 )
    {
      v5->prev_ = 0;
      *head = this->next_;
      this->prev_ = 0;
      this->next_ = 0;
    }
    else
    {
      *head = 0;
      *tail = 0;
      this->prev_ = 0;
      this->next_ = 0;
    }
  }
}

//----- (00548D10) --------------------------------------------------------  // acclient.c:376223
unsigned int __thiscall ReceiverData::Encrypt(ReceiverData *this, unsigned int seqnum, char *mem, unsigned int len, unsigned int *pEncryptKey)
{
  return CryptoSystem::EncryptData(this->cryptoOutgoing_, seqnum, mem, len, pEncryptKey);
}

//----- (00548D20) --------------------------------------------------------  // acclient.c:376229
unsigned int __thiscall ReceiverData::Decrypt(ReceiverData *this, unsigned int seqnum, char *mem, unsigned int len, unsigned int *pDecryptKey)
{
  return CryptoSystem::EncryptData(this->cryptoIncoming_, seqnum, mem, len, pDecryptKey);
}

//----- (00548D30) --------------------------------------------------------  // acclient.c:376235
void __thiscall AVLNode<unsigned long,unsigned long>::AVLNode<unsigned long,unsigned long>(AVLNode<unsigned long,unsigned long> *this, unsigned int key, unsigned int *data, AVLNode<unsigned long,unsigned long> *parent)
{
  this->_parent = parent;
  this->_key = key;
  this->_left = 0;
  this->_right = 0;
  this->_leftHeight = 1;
  this->_rightHeight = 1;
  this->_height = 1;
  this->_data = data;
  this->_parentsize = 1;
}

//----- (00548D70) --------------------------------------------------------  // acclient.c:376249
void __thiscall ReceiverData::SetConnectionState(ReceiverData *this, ConnectionState NewState)
{
  int v2; // edx@1

  v2 = HIDWORD(Timer::local_time);
  LODWORD(this->m_TimeLastConnectionStateChanged) = LODWORD(Timer::local_time);
  HIDWORD(this->m_TimeLastConnectionStateChanged) = v2;
  this->m_ConnectionState = NewState;
}

//----- (00548D90) --------------------------------------------------------  // acclient.c:376260
long double __thiscall ReceiverData::GetConnectionStateDuration(ReceiverData *this)
{
  return Timer::local_time - this->m_TimeLastConnectionStateChanged;
}

//----- (00548DA0) --------------------------------------------------------  // acclient.c:376266
void __thiscall ReceiverData::InitCrypto(ReceiverData *this, unsigned int seedIncoming, unsigned int seedOutgoing)
{
  ReceiverData *v3; // esi@1
  CryptoSystem *v4; // edi@1
  CryptoSystem *v5; // edi@3
  CryptoSystem *v6; // eax@5
  CryptoSystem *v7; // eax@6
  CryptoSystem *v8; // eax@8
  CryptoSystem *v9; // eax@9

  v3 = this;
  v4 = this->cryptoIncoming_;
  if ( v4 )
  {
    CryptoSystem::~CryptoSystem(this->cryptoIncoming_);
    operator delete(v4);
  }
  v5 = v3->cryptoOutgoing_;
  v3->cryptoIncoming_ = 0;
  if ( v5 )
  {
    CryptoSystem::~CryptoSystem(v5);
    operator delete(v5);
  }
  v3->cryptoOutgoing_ = 0;
  v6 = (CryptoSystem *)operator new(0xCu);
  if ( v6 )
    CryptoSystem::CryptoSystem(v6, seedIncoming);
  else
    v7 = 0;
  v3->cryptoIncoming_ = v7;
  v8 = (CryptoSystem *)operator new(0xCu);
  if ( v8 )
  {
    CryptoSystem::CryptoSystem(v8, seedOutgoing);
    v3->cryptoOutgoing_ = v9;
  }
  else
  {
    v3->cryptoOutgoing_ = 0;
  }
}

//----- (00548E30) --------------------------------------------------------  // acclient.c:376310
void __thiscall ReceiverData::ReceiverData(ReceiverData *this)
{
  this->m_RecID = 0;
  this->highestIDReceived_ = 0;
  this->next_ = 0;
  this->prev_ = 0;
  *(_QWORD *)&this->timeStamp_ = 0i64;
  this->cryptoOutgoing_ = 0;
  this->cryptoIncoming_ = 0;
  this->keyExch_ = 0;
  this->m_NetID = 0;
  this->m_NakState = 0;
  this->m_ConnectionState = 0;
  this->m_SeqIDsWeNAKed._root = 0;
  this->m_SeqIDsWeNAKed._currNum = 0;
  *(_QWORD *)&this->m_TimeLastConnectionStateChanged = 0i64;
  this->m_BytesReceived = 0;
}

//----- (00548E70) --------------------------------------------------------  // acclient.c:376330
void __thiscall ReceiverData::~ReceiverData(ReceiverData *this)
{
  ReceiverData *v1; // esi@1
  CryptoSystem *v2; // edi@1
  CryptoSystem *v3; // edi@3
  AVLNode<unsigned long,unsigned long> *v4; // esi@5
  AVLNode<unsigned long,unsigned long> *v5; // ecx@8

  v1 = this;
  v2 = this->cryptoIncoming_;
  if ( v2 )
  {
    CryptoSystem::~CryptoSystem(this->cryptoIncoming_);
    operator delete(v2);
  }
  v3 = v1->cryptoOutgoing_;
  v1->cryptoIncoming_ = 0;
  if ( v3 )
  {
    CryptoSystem::~CryptoSystem(v3);
    operator delete(v3);
  }
  v1->cryptoOutgoing_ = 0;
  v4 = v1->m_SeqIDsWeNAKed._root;
  if ( v4 )
  {
    if ( v4->_left )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v4->_left, 1u);
    v5 = v4->_right;
    if ( v5 )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v5, 1u);
    v4->_left = 0;
    v4->_right = 0;
    operator delete(v4);
  }
}

//----- (00548EF0) --------------------------------------------------------  // acclient.c:376368
void __thiscall ReceiverData::SharedInit(ReceiverData *this, sockaddr_in *addr, unsigned int highest, unsigned __int16 recID, unsigned __int16 netID, unsigned __int16 iteration, unsigned __int16 remoteInterval, NetKeyExch *keyExch, unsigned int seedIncoming, unsigned int seedOutgoing)
{
  ReceiverData *v10; // esi@1
  NetKeyExch *v11; // ecx@1
  ICMDCommandEnum v12; // eax@3
  int v13; // eax@3

  v10 = this;
  v11 = this->keyExch_;
  if ( v11 )
    ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
  v10->keyExch_ = keyExch;
  v10->m_Addr = *addr;
  v10->highestIDReceived_ = highest;
  v10->m_RecID = recID;
  v12 = (signed int)Timer::cur_time.Cmd;
  HIDWORD(v10->timeStamp_) = Timer::cur_time.Param;
  LODWORD(v10->timeStamp_) = v12;
  v13 = HIDWORD(Timer::local_time);
  LODWORD(v10->m_TimeLastConnectionStateChanged) = LODWORD(Timer::local_time);
  v10->m_NetID = netID;
  v10->m_CurrentRemoteInterval = remoteInterval;
  HIDWORD(v10->m_TimeLastConnectionStateChanged) = v13;
  LODWORD(v10->m_qwReferralCookie) = 0;
  HIDWORD(v10->m_qwReferralCookie) = 0;
  v10->iteration_ = iteration;
  ReceiverData::InitCrypto(v10, seedIncoming, seedOutgoing);
}

//----- (00548FA0) --------------------------------------------------------  // acclient.c:376398
void __thiscall ReceiverData::Init(ReceiverData *this, sockaddr_in addr, unsigned int highest, unsigned __int16 recID, unsigned __int16 netID, unsigned __int16 iteration, unsigned __int16 remoteInterval, NetKeyExch *keyExch, unsigned int seedIncoming, unsigned int seedOutgoing)
{
  unsigned int v10; // ST20_4@1
  ReceiverData *v11; // esi@1
  unsigned int v12; // ST1C_4@1
  NetKeyExch *v13; // ST18_4@1
  unsigned __int16 v14; // ST14_2@1
  unsigned __int16 v15; // ST10_2@1
  unsigned __int16 v16; // ST0C_2@1
  unsigned __int16 v17; // ST08_2@1
  unsigned int v18; // ST04_4@1
  ReceiverData *v19; // ecx@1

  v10 = seedOutgoing;
  v11 = this;
  v12 = seedIncoming;
  v13 = keyExch;
  v14 = remoteInterval;
  v15 = iteration;
  v16 = netID;
  v17 = recID;
  v18 = highest;
  *(_DWORD *)&this[1].m_RecID = 0;
  ReceiverData::SharedInit(this, &addr, v18, v17, v16, v15, v14, v13, v12, v10);
  v19 = (ReceiverData *)HIDWORD(Timer::local_time);
  v11[1].next_ = (ReceiverData *)LODWORD(Timer::local_time);
  v11[1].prev_ = v19;
}

//----- (00549000) --------------------------------------------------------  // acclient.c:376428
void __thiscall ReceiverData::Clear(ReceiverData *this)
{
  ReceiverData *v1; // esi@1
  int v2; // ecx@1
  AVLNode<unsigned long,unsigned long> *v3; // ebx@1
  AVLNode<unsigned long,unsigned long> *v4; // ecx@4
  CryptoSystem *v5; // ebx@7
  CryptoSystem *v6; // ebx@9
  NetKeyExch *v7; // ecx@11

  v1 = this;
  this->next_ = 0;
  this->prev_ = 0;
  this->highestIDReceived_ = 0;
  this->m_RecID = 0;
  this->m_NetID = 0;
  v2 = HIDWORD(Timer::local_time);
  LODWORD(v1->m_TimeLastConnectionStateChanged) = LODWORD(Timer::local_time);
  HIDWORD(v1->m_TimeLastConnectionStateChanged) = v2;
  v3 = v1->m_SeqIDsWeNAKed._root;
  if ( v3 )
  {
    if ( v3->_left )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v3->_left, 1u);
    v4 = v3->_right;
    if ( v4 )
      AVLNode<unsigned long,unsigned long>::scalar_deleting_destructor(v4, 1u);
    v3->_left = 0;
    v3->_right = 0;
    operator delete(v3);
  }
  v1->m_SeqIDsWeNAKed._root = 0;
  v1->m_SeqIDsWeNAKed._currNum = 0;
  v5 = v1->cryptoIncoming_;
  v1->m_NakState = 0;
  v1->m_ConnectionState = 0;
  LODWORD(v1->timeStamp_) = 0;
  HIDWORD(v1->timeStamp_) = 0;
  if ( v5 )
  {
    CryptoSystem::~CryptoSystem(v5);
    operator delete(v5);
  }
  v6 = v1->cryptoOutgoing_;
  v1->cryptoIncoming_ = 0;
  if ( v6 )
  {
    CryptoSystem::~CryptoSystem(v6);
    operator delete(v6);
  }
  v7 = v1->keyExch_;
  v1->cryptoOutgoing_ = 0;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
  v1->keyExch_ = 0;
}

//----- (005490C0) --------------------------------------------------------  // acclient.c:376486
unsigned int __thiscall ReceiverData::GetNaks(ReceiverData *this, unsigned int *naks)
{
  unsigned int result; // eax@1
  AVLNode<unsigned long,unsigned long> *v3; // ecx@3
  unsigned int v4; // esi@3
  AVLNode<unsigned long,unsigned long> *v5; // edx@4
  AVLNode<unsigned long,unsigned long> *v6; // edx@8
  AVLNode<unsigned long,unsigned long> *v7; // edx@10
  bool v8; // dl@13

  result = this->m_SeqIDsWeNAKed._currNum;
  if ( result > 0x72 )
    result = 114;
  v3 = this->m_SeqIDsWeNAKed._root;
  v4 = 0;
  if ( v3 )
  {
    v5 = v3->_left;
    if ( v3->_left )
    {
      do
      {
        v3 = v5;
        v5 = v5->_left;
      }
      while ( v5 );
    }
    while ( v3 )
    {
      if ( v4 >= 0x73 )
        break;
      naks[v4] = v3->_key;
      v6 = v3->_right;
      ++v4;
      if ( v6 )
      {
        v3 = v3->_right;
        if ( !v6 )
          return result;
        while ( 1 )
        {
          v7 = v3->_left;
          if ( !v3->_left )
            break;
          v3 = v3->_left;
          if ( !v7 )
            return result;
        }
      }
      else
      {
        while ( 1 )
        {
          v8 = v3->_parentsize;
          v3 = v3->_parent;
          if ( v8 )
            break;
          if ( !v3 )
            return result;
        }
      }
    }
  }
  return result;
}

//----- (00549140) --------------------------------------------------------  // acclient.c:376553
unsigned int *__thiscall AVL<unsigned long,unsigned long>::Add(AVL<unsigned long,unsigned long> *this, unsigned int key, unsigned int *data)
{
  AVL<unsigned long,unsigned long> *v3; // ebx@1
  AVLNode<unsigned long,unsigned long> *v4; // eax@1
  void *v5; // eax@2
  unsigned int *result; // eax@3
  bool v7; // cl@5
  AVLNode<unsigned long,unsigned long> *v8; // esi@5
  AVLNode<unsigned long,unsigned long> *v9; // eax@10
  unsigned int *v10; // ebp@10
  int v11; // eax@11
  AVLNode<unsigned long,unsigned long> *v12; // eax@13
  int v13; // eax@14

  v3 = this;
  v4 = this->_root;
  if ( this->_root )
  {
    do
    {
      v7 = key < v4->_key;
      v8 = v4;
      if ( key >= v4->_key )
        v4 = v4->_right;
      else
        v4 = v4->_left;
    }
    while ( v4 );
    if ( v7 )
    {
      v9 = (AVLNode<unsigned long,unsigned long> *)operator new(0x24u);
      v10 = data;
      if ( v9 )
      {
        AVLNode<unsigned long,unsigned long>::AVLNode<unsigned long,unsigned long>(v9, key, data, v8);
        v8->_left = (AVLNode<unsigned long,unsigned long> *)v11;
        *(_BYTE *)(v11 + 32) = 1;
      }
      else
      {
        v8->_left = 0;
        v20 = 1;
      }
    }
    else
    {
      v12 = (AVLNode<unsigned long,unsigned long> *)operator new(0x24u);
      v10 = data;
      if ( v12 )
        AVLNode<unsigned long,unsigned long>::AVLNode<unsigned long,unsigned long>(v12, key, data, v8);
      else
        v13 = 0;
      v8->_right = (AVLNode<unsigned long,unsigned long> *)v13;
      *(_BYTE *)(v13 + 32) = 0;
    }
    AVL<unsigned long,unsigned long>::ReBalanceTree(v3, v8, 0);
    ++v3->_currNum;
    result = v10;
  }
  else
  {
    v5 = operator new(0x24u);
    if ( v5 )
    {
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 1) = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 6) = key;
      *((_DWORD *)v5 + 3) = 1;
      *((_DWORD *)v5 + 4) = 1;
      *((_DWORD *)v5 + 5) = 1;
      *((_DWORD *)v5 + 7) = data;
      *((_BYTE *)v5 + 32) = 1;
      v3->_root = (AVLNode<unsigned long,unsigned long> *)v5;
      ++v3->_currNum;
      result = data;
    }
    else
    {
      v3->_root = 0;
      ++v3->_currNum;
      result = data;
    }
  }
  return result;
}

//----- (00549240) --------------------------------------------------------  // acclient.c:376641
void __thiscall ReceiverData::AddNakked(ReceiverData *this, unsigned int seqNum, unsigned int *pKeyPassed)
{
  AVLNode<unsigned long,unsigned long> *v3; // eax@3
  unsigned int v4; // esi@3
  AVL<unsigned long,unsigned long> *v5; // edi@3
  unsigned int v6; // edx@4
  unsigned int *v7; // eax@11

  if ( this->m_NakState == 2 )
    this->m_NakState = 1;
  v3 = this->m_SeqIDsWeNAKed._root;
  v4 = seqNum;
  v5 = &this->m_SeqIDsWeNAKed;
  if ( !v3 )
    goto LABEL_11;
  while ( 1 )
  {
    v6 = v3->_key;
    if ( seqNum == v6 )
      break;
    if ( seqNum >= v6 )
      v3 = v3->_right;
    else
      v3 = v3->_left;
    if ( !v3 )
      goto LABEL_11;
  }
  if ( !v3->_data )
  {
LABEL_11:
    v7 = pKeyPassed;
    seqNum = 0;
    if ( !pKeyPassed )
    {
      seqNum = CryptoSystem::GetNextCryptoSeed(this->cryptoIncoming_, v4);
      v7 = &seqNum;
    }
    AVL<unsigned long,unsigned long>::Add(v5, v4, (unsigned int *)*v7);
  }
}

//----- (007056A0) --------------------------------------------------------  // acclient.c:792706
int _E77_13()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_30;
  dword_845F74 = LOWEST_DATA_RATE_30;
  return result;
}

//----- (007056B0) --------------------------------------------------------  // acclient.c:792716
int sub_7056B0()
{
  return atexit(nullsub_1215);
}

