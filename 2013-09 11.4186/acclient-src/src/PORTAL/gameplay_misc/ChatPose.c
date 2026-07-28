/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ChatPose
   Object     : PORTAL\gameplay_misc\ChatPose.obj
   Functions  : 30
   Addresses  : 004114F0 - 006F9470 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004114F0) --------------------------------------------------------  // acclient.c:77435
void __thiscall AC1Legacy::PStringBase<char>::PStringBase<char>(AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *this)
{
  volatile LONG *v1; // ST00_4@1

  v1 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v1);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FCDB0) --------------------------------------------------------  // acclient.c:296913
int __thiscall ChatPoseTable::UnPack(ChatPoseTable *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  void *v4; // ebp@1
  ChatPoseTable *v5; // esi@1
  int v6; // eax@1
  char *v7; // ebx@1
  int v8; // ST18_4@1
  int v9; // eax@1
  unsigned int v10; // ebx@1

  v3 = addr;
  v4 = *addr;
  v5 = this;
  v6 = *(_DWORD *)&this->m_bLoaded;
  addr = 0;
  v7 = (char *)&this->m_pLast;
  v8 = (*(int (__thiscall **)(bool *, void ***, _DWORD))(v6 + 12))(&this->m_bLoaded, &addr, 0);
  v9 = (*(int (__thiscall **)(int, void ***, _DWORD))(*(_DWORD *)v7 + 12))(&v5->m_pLast, &addr, 0);
  v10 = size;
  if ( size < v9 + v8 )
    return 0;
  (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v5->m_bLoaded + 16))(&v5->m_bLoaded, v3, size);
  LODWORD(v5->m_pLast->m_timeStamp)(&v5->m_pLast, v3, v10);
  if ( v10 < (_BYTE *)*v3 - (_BYTE *)v4 )
  {
    *v3 = v4;
    return 0;
  }
  return 1;
}

//----- (004FCE30) --------------------------------------------------------  // acclient.c:296946
void __thiscall ChatEmoteData::~ChatEmoteData(ChatEmoteData *this)
{
  ChatEmoteData *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@4

  v1 = this;
  v2 = this->otherEmote.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->myEmote.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004FCE80) --------------------------------------------------------  // acclient.c:296964
int __thiscall ChatEmoteData::Pack(ChatEmoteData *this, void **addr, unsigned int size)
{
  ChatEmoteData *v3; // esi@1
  int v4; // ebp@1

  v3 = this;
  v4 = AC1Legacy::PStringBase<char>::Pack(&this->myEmote, addr, size);
  return v4 + AC1Legacy::PStringBase<char>::Pack(&v3->otherEmote, addr, size);
}

//----- (004FCEB0) --------------------------------------------------------  // acclient.c:296975
void __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::EmptyContents(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this)
{
  unsigned int v1; // eax@2
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v4; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  unsigned int i; // [sp+8h] [bp-8h]@2
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v7; // [sp+Ch] [bp-4h]@1

  v7 = this;
  if ( this->_buckets )
  {
    v1 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v2 = this->_buckets[v1];
        if ( v2 )
        {
          do
          {
            v3 = v2->_data.m_buffer;
            v4 = v2->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
              v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
            v5 = v2->_key.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v2->_key.m_buffer->m_cRef) && v5 )
              v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
            operator delete(v2);
            v2 = v4;
          }
          while ( v4 );
          v1 = i;
          this = v7;
        }
        this->_buckets[v1++] = 0;
        i = v1;
      }
      while ( v1 < this->_table_size );
    }
  }
  this->_currNum = 0;
}

//----- (004FCF60) --------------------------------------------------------  // acclient.c:297023
void __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::EmptyContents(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v4; // ebp@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  AC1Legacy::PSRefBuffer<char> *v6; // edi@10
  unsigned int i; // [sp+18h] [bp-8h]@2
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v8; // [sp+1Ch] [bp-4h]@1

  v8 = this;
  if ( this->_buckets )
  {
    v1 = 0;
    i = 0;
    if ( this->_table_size )
    {
      do
      {
        v2 = this->_buckets[v1];
        if ( v2 )
        {
          do
          {
            v3 = v2->_data.otherEmote.m_buffer;
            v4 = v2->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
              v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
            v5 = v2->_data.myEmote.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
              v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
            v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            v6 = v2->_key.m_buffer;
            if ( !InterlockedDecrement((volatile LONG *)&v2->_key.m_buffer->m_cRef) && v6 )
              v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
            operator delete(v2);
            v2 = v4;
          }
          while ( v4 );
          v1 = i;
          this = v8;
        }
        this->_buckets[v1++] = 0;
        i = v1;
      }
      while ( v1 < this->_table_size );
    }
  }
  this->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004FD040) --------------------------------------------------------  // acclient.c:297077
BOOL __thiscall ChatEmoteData::UnPack(ChatEmoteData *this, void **addr, unsigned int size)
{
  ChatEmoteData *v3; // esi@1

  v3 = this;
  return AC1Legacy::PStringBase<char>::UnPack(&this->myEmote, addr, size)
      && AC1Legacy::PStringBase<char>::UnPack(&v3->otherEmote, addr, size);
}

//----- (004FD080) --------------------------------------------------------  // acclient.c:297087
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::Pack(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v3; // ebp@1
  int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&v7->_key.m_buffer, addr, v5);
            AC1Legacy::PStringBase<char>::Pack(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (004FD110) --------------------------------------------------------  // acclient.c:297134
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::pack_size(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  int v4; // edi@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *i; // esi@2
  int v6; // edi@3
  int v7; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 = v7 + v6 )
      {
        v6 = AC1Legacy::PStringBase<char>::Pack((AC1Legacy::PStringBase<char> *)&i->_key.m_buffer, &addr, 0) + v4;
        v7 = AC1Legacy::PStringBase<char>::Pack(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (004FD180) --------------------------------------------------------  // acclient.c:297168
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::Pack(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, void **addr, unsigned int size)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v3; // ebp@1
  int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            AC1Legacy::PStringBase<char>::Pack(&v7->_key, addr, v5);
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (004FD210) --------------------------------------------------------  // acclient.c:297215
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::pack_size(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  int v4; // edi@1
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *i; // esi@2
  int v6; // edi@3
  int v7; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 = v7 + v6 )
      {
        v6 = AC1Legacy::PStringBase<char>::Pack(&i->_key, &addr, 0) + v4;
        v7 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (004FD280) --------------------------------------------------------  // acclient.c:297249
void __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::~PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5E28: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (004FD2C0) --------------------------------------------------------  // acclient.c:297268
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::UnPack(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  unsigned int v10; // ebx@5
  unsigned int v11; // ebp@5
  int v12; // eax@11
  unsigned int *v13; // ecx@11
  int v14; // eax@12
  unsigned int i; // [sp+8h] [bp-Ch]@10
  void *start_addr; // [sp+Ch] [bp-8h]@3
  unsigned int blob_size; // [sp+10h] [bp-4h]@3

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*v6;
  *v6 = (char *)*v6 + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&addr);
    size = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    i = 0;
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&addr, v6, v10);
        v13 = &size;
        if ( !v12 )
          break;
        v14 = AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&size, v6, v10);
        v13 = &size;
        if ( !v14 )
          break;
        if ( !PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::add(
                v4,
                (AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&addr,
                (AC1Legacy::PStringBase<char> *)&size)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        {
          v13 = &size;
          break;
        }
        ++i;
        if ( i >= v11 )
          goto LABEL_16;
      }
    }
    else
    {
LABEL_16:
      v13 = &size;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&addr);
        return 1;
      }
    }
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)v13);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&addr);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FD420) --------------------------------------------------------  // acclient.c:297361
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::add(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this, AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *key, AC1Legacy::PStringBase<char> *data)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v3; // edi@1
  int result; // eax@2
  AC1Legacy::PStringBase<char> *v5; // eax@3
  AC1Legacy::PStringBase<char> *v6; // esi@3
  unsigned int v7; // ebp@4
  unsigned int v8; // eax@4

  v3 = this;
  if ( PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::lookup(
         this,
         key) )
  {
    result = 0;
  }
  else
  {
    v5 = (AC1Legacy::PStringBase<char> *)operator new(0x10u);
    v6 = v5;
    if ( v5 )
    {
      v7 = v3->_table_size;
      AC1Legacy::PStringBase<char>::PStringBase<char>(v5, (AC1Legacy::PStringBase<char> *)&key->m_buffer);
      AC1Legacy::PStringBase<char>::PStringBase<char>(v6 + 1, data);
      v6[2].m_buffer = 0;
      v8 = AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>::case_insensitive_hash(key);
      v6[3].m_buffer = (AC1Legacy::PSRefBuffer<char> *)(v8 % v7);
      v6[2].m_buffer = (AC1Legacy::PSRefBuffer<char> *)&v3->_buckets[v8 % v7]->_key.m_buffer;
      v3->_buckets[v8 % v7] = (PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *)v6;
      ++v3->_currNum;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (004FD4B0) --------------------------------------------------------  // acclient.c:297403
unsigned int __thiscall AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>::case_insensitive_hash(AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *this)
{
  char v1; // al@1
  char *v2; // edi@1
  unsigned int i; // esi@1

  v1 = this->m_buffer->m_data[0];
  v2 = this->m_buffer->m_data;
  for ( i = 0; v1; ++v2 )
  {
    i = (char)_tolower(v1) + 16 * i;
    if ( i & 0xF0000000 )
      i = (i ^ ((i & 0xF0000000) >> 24)) & 0xFFFFFFF;
    v1 = v2[1];
  }
  return i;
}

//----- (004FD500) --------------------------------------------------------  // acclient.c:297422
AC1Legacy::PStringBase<char> *__thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::lookup(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this, AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *key)
{
  unsigned int v2; // edi@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v3; // esi@3
  AC1Legacy::PStringBase<char> *result; // eax@6

  v2 = this->_table_size;
  if ( v2
    && this->_buckets
    && (v3 = this->_buckets[AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>::case_insensitive_hash(key)
                          % v2]) != 0 )
  {
    while ( !(unsigned __int8)AC1Legacy::PStringBase<char>::eq(
                                (AC1Legacy::PStringBase<char> *)&key->m_buffer,
                                (AC1Legacy::PStringBase<char> *)&v3->_key.m_buffer,
                                0) )
    {
      v3 = v3->_next;
      if ( !v3 )
        goto LABEL_6;
    }
    result = &v3->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (004FD560) --------------------------------------------------------  // acclient.c:297454
void __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::~PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable;
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5E3C: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable)(void *, char);

//----- (004FD5A0) --------------------------------------------------------  // acclient.c:297473
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::UnPack(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  unsigned int v10; // ebx@5
  unsigned int v11; // ebp@5
  ChatEmoteData *v12; // ecx@16
  void *start_addr; // [sp+8h] [bp-14h]@3
  unsigned int blob_size; // [sp+Ch] [bp-10h]@3
  ChatEmoteData tempData; // [sp+10h] [bp-Ch]@10
  void **addra; // [sp+20h] [bp+4h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::EmptyContents(this);
  if ( v4->_buckets )
  {
    operator delete[](v4->_buckets);
    v4->_buckets = 0;
  }
  v4->_table_size = 0;
  v7 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v8 = v7 >> 16;
  v9 = (unsigned __int16)v7;
  v10 = v3 - 4;
  v4->_table_size = v8;
  v11 = v9;
  if ( !v8 )
    return v9 == 0;
  if ( v8 <= 0x10000
    && v9 <= 0x10000
    && PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v4) )
  {
    size = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    ChatEmoteData::ChatEmoteData(&tempData);
    addra = 0;
    if ( v11 )
    {
      while ( AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&size, v6, v10)
           && ((int (__thiscall *)(ChatEmoteData *, void **, unsigned int))tempData.vfptr->UnPack)(&tempData, v6, v10)
           && (PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::add(
                 v4,
                 (AC1Legacy::PStringBase<char> *)&size,
                 &tempData)
            || v4->m_fThrowawayDuplicateKeysOnUnPack) )
      {
        addra = (void **)((char *)addra + 1);
        if ( (unsigned int)addra >= v11 )
          goto LABEL_16;
      }
      v12 = &tempData;
    }
    else
    {
LABEL_16:
      v12 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        ChatEmoteData::~ChatEmoteData(&tempData);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
        return 1;
      }
    }
    ChatEmoteData::~ChatEmoteData(v12);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FD700) --------------------------------------------------------  // acclient.c:297555
void __thiscall ChatEmoteData::ChatEmoteData(ChatEmoteData *this)
{
  ChatEmoteData *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&ChatEmoteData::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->myEmote.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->otherEmote.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
}
// 7C5E50: using guessed type int (__thiscall *ChatEmoteData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004FD740) --------------------------------------------------------  // acclient.c:297574
ChatEmoteData *__thiscall ChatEmoteData::scalar_deleting_destructor(ChatEmoteData *this, unsigned int a2)
{
  ChatEmoteData *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@4

  v2 = this;
  v3 = this->otherEmote.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v2->myEmote.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004FD7A0) --------------------------------------------------------  // acclient.c:297595
int __thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::add(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, AC1Legacy::PStringBase<char> *key, ChatEmoteData *data)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v3; // esi@1
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v4; // eax@2
  int v5; // eax@3
  int result; // eax@4
  int v7; // ecx@5

  v3 = this;
  if ( !PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::lookup(this, key)
    && (v4 = (PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *)operator new(0x18u)) != 0
    && (PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData>::PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData>(
          v4,
          key,
          data,
          v3->_table_size),
        v5) )
  {
    v7 = *(_DWORD *)(v5 + 20);
    *(_DWORD *)(v5 + 16) = v3->_buckets[v7];
    v3->_buckets[v7] = (PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *)v5;
    ++v3->_currNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004FD800) --------------------------------------------------------  // acclient.c:297627
ChatEmoteData *__thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::lookup(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, AC1Legacy::PStringBase<char> *key)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@3
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v5; // ebp@5
  ChatEmoteData *result; // eax@8

  v2 = this;
  v3 = this->_table_size;
  if ( !v3 || !this->_buckets )
    goto LABEL_8;
  v4 = key->m_buffer->m_hash;
  if ( v4 == -1 )
  {
    v4 = AC1Legacy::PStringBase<char>::compute_hash(key);
    key->m_buffer->m_hash = v4;
  }
  v5 = v2->_buckets[v4 % v3];
  if ( v5 )
  {
    while ( strcmp(key->m_buffer->m_data, v5->_key.m_buffer->m_data) )
    {
      v5 = v5->_next;
      if ( !v5 )
        goto LABEL_8;
    }
    result = &v5->_data;
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}

//----- (004FD8A0) --------------------------------------------------------  // acclient.c:297665
unsigned int __thiscall AC1Legacy::PStringBase<char>::compute_hash(AC1Legacy::PStringBase<char> *this)
{
  AC1Legacy::PSRefBuffer<char> *v1; // edx@1
  char v2; // cl@1
  int v3; // edx@1
  unsigned int result; // eax@1

  v1 = this->m_buffer;
  v2 = this->m_buffer->m_data[0];
  v3 = (int)v1->m_data;
  result = 0;
  if ( v2 )
  {
    do
    {
      result = v2 + 16 * result;
      if ( result & 0xF0000000 )
        result = (result ^ ((result & 0xF0000000) >> 24)) & 0xFFFFFFF;
      v2 = *(_BYTE *)(v3++ + 1);
    }
    while ( v2 );
    if ( result == -1 )
      result = -2;
  }
  return result;
}

//----- (004FD8F0) --------------------------------------------------------  // acclient.c:297693
void __thiscall PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData>::PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData>(PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, AC1Legacy::PStringBase<char> *key, ChatEmoteData *data, int highbound)
{
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  PackableHashData<AC1Legacy::PStringBase<char>,ChatEmoteData> *v5; // esi@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebx@1
  unsigned int v7; // eax@1

  v4 = key->m_buffer;
  v5 = this;
  this->_key.m_buffer = key->m_buffer;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v5->_data.vfptr = (PackObjVtbl *)&ChatEmoteData::vftable;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v5->_data.myEmote, &data->myEmote);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v5->_data.otherEmote, &data->otherEmote);
  v5->_next = 0;
  v6 = key->m_buffer;
  v7 = key->m_buffer->m_hash;
  if ( v7 == -1 )
  {
    v7 = AC1Legacy::PStringBase<char>::compute_hash(key);
    v6->m_hash = v7;
  }
  v5->_hashVal = v7 % highbound;
}
// 7C5E50: using guessed type int (__thiscall *ChatEmoteData::vftable)(void *, char);

//----- (004FD960) --------------------------------------------------------  // acclient.c:297720
PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *__thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vector_deleting_destructor(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *this, unsigned int a2)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,AC1Legacy::PStringBase<char> > *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5E28: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable)(void *, char);

//----- (004FD9B0) --------------------------------------------------------  // acclient.c:297742
PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *__thiscall PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::scalar_deleting_destructor(PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *this, unsigned int a2)
{
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable;
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5E3C: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable)(void *, char);

//----- (004FDA00) --------------------------------------------------------  // acclient.c:297764
void __thiscall ChatPoseTable::ChatPoseTable(ChatPoseTable *this, IDClass<_tagDataID,32,0> gid)
{
  ChatPoseTable *v2; // esi@1
  int v3; // ecx@1
  int v4; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, gid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_chatPoseHash;
  v2->vfptr = (InterfaceVtbl *)&ChatPoseTable::vftable;
  v2->vfptr = (PackObjVtbl *)&ChatPoseTable::vftable;
  *(_DWORD *)v3 = &PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 32;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_chatPoseHash);
  v4 = (int)&v2->_chatEmoteHash;
  *(_DWORD *)v4 = &PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 32;
  *(_DWORD *)(v4 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_chatEmoteHash);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C5E28: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable)(void *, char);
// 7C5E3C: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable)(void *, char);
// 7C5E64: using guessed type void *ChatPoseTable::vftable;
// 7C5E78: using guessed type __int32 (__stdcall *ChatPoseTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004FDA80) --------------------------------------------------------  // acclient.c:297803
ChatPoseTable *__thiscall ChatPoseTable::vector_deleting_destructor(ChatPoseTable *this, unsigned int a2)
{
  return ChatPoseTable::scalar_deleting_destructor((ChatPoseTable *)((char *)this - 48), a2);
}

//----- (004FDAA0) --------------------------------------------------------  // acclient.c:297809
ChatPoseTable *__thiscall ChatPoseTable::scalar_deleting_destructor(ChatPoseTable *this, unsigned int a2)
{
  ChatPoseTable *v2; // esi@1

  v2 = this;
  PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::~PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>(&this->_chatEmoteHash);
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::~PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>(&v2->_chatPoseHash);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj((SerializeUsingPackDBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006F9470) --------------------------------------------------------  // acclient.c:782009
int sub_6F9470()
{
  return atexit(nullsub_1037);
}

