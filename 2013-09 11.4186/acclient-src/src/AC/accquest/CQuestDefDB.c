/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CQuestDefDB
   Object     : AC\accquest\CQuestDefDB.obj
   Functions  : 17
   Addresses  : 005992E0 - 0070AF90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005992E0) --------------------------------------------------------  // acclient.c:451467
void __thiscall QuestDef::~QuestDef(QuestDef *this)
{
  QuestDef *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1

  v1 = this;
  v2 = this->_fullname.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00599310) --------------------------------------------------------  // acclient.c:451481
void __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::EmptyContents(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this)
{
  unsigned int v1; // eax@2
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v4; // ebx@4
  AC1Legacy::PSRefBuffer<char> *v5; // edi@7
  unsigned int i; // [sp+8h] [bp-8h]@2
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v7; // [sp+Ch] [bp-4h]@1

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
            v3 = v2->_data._fullname.m_buffer;
            v4 = v2->_next;
            if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
              v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
            v2->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
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
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005993D0) --------------------------------------------------------  // acclient.c:451531
void __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::~PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4F98: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable)(void *, char);

//----- (00599410) --------------------------------------------------------  // acclient.c:451550
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::Pack(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, void **addr, unsigned int size)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v3; // ebp@1
  int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::pack_size(this);
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

//----- (005994A0) --------------------------------------------------------  // acclient.c:451597
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::pack_size(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  int v4; // edi@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *i; // esi@2
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
        v7 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (00599510) --------------------------------------------------------  // acclient.c:451631
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::UnPack(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  unsigned int v10; // ebx@5
  unsigned int v11; // ebp@5
  QuestDef *v12; // ecx@16
  void *start_addr; // [sp+8h] [bp-18h]@3
  unsigned int blob_size; // [sp+Ch] [bp-14h]@3
  QuestDef tempData; // [sp+10h] [bp-10h]@10
  void **addra; // [sp+24h] [bp+4h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::EmptyContents(this);
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
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&size);
    QuestDef::QuestDef(&tempData);
    addra = 0;
    if ( v11 )
    {
      while ( AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&size, v6, v10)
           && ((int (__thiscall *)(QuestDef *, void **, unsigned int))tempData.vfptr->UnPack)(&tempData, v6, v10)
           && (PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::add(
                 v4,
                 (AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *)&size,
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
        QuestDef::~QuestDef(&tempData);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
        return 1;
      }
    }
    QuestDef::~QuestDef(v12);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&size);
  }
  return 0;
}

//----- (00599670) --------------------------------------------------------  // acclient.c:451711
int __thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::add(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *key, QuestDef *data)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v3; // esi@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v4; // eax@2
  int v5; // eax@3
  int result; // eax@4
  int v7; // ecx@5

  v3 = this;
  if ( !PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::lookup(
          this,
          key)
    && (v4 = (PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *)operator new(0x1Cu)) != 0
    && (PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>(
          v4,
          key,
          data,
          v3->_table_size),
        v5) )
  {
    v7 = *(_DWORD *)(v5 + 24);
    *(_DWORD *)(v5 + 20) = v3->_buckets[v7];
    v3->_buckets[v7] = (PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *)v5;
    ++v3->_currNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005996D0) --------------------------------------------------------  // acclient.c:451745
void __thiscall PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>(PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *key, QuestDef *data, int highbound)
{
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v5; // esi@1

  v4 = key->m_buffer;
  v5 = this;
  this->_key.m_buffer = key->m_buffer;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  QuestDef::QuestDef(&v5->_data, data);
  v5->_next = 0;
  v5->_hashVal = AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>::case_insensitive_hash(key)
               % highbound;
}

//----- (00599720) --------------------------------------------------------  // acclient.c:451761
void __thiscall QuestDef::QuestDef(QuestDef *this, QuestDef *__that)
{
  QuestDef *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&QuestDef::vftable;
  v3 = __that->_fullname.m_buffer;
  this->_fullname.m_buffer = v3;
  InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  v2->_mindelta = __that->_mindelta;
  v2->_maxsolves = __that->_maxsolves;
}
// 7E4FAC: using guessed type int (__thiscall *QuestDef::vftable)(void *, char);

//----- (00599760) --------------------------------------------------------  // acclient.c:451777
QuestDef *__thiscall QuestDef::vector_deleting_destructor(QuestDef *this, unsigned int a2)
{
  QuestDef *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1

  v2 = this;
  v3 = this->_fullname.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005997A0) --------------------------------------------------------  // acclient.c:451794
QuestDef *__thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::lookup(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> > *key)
{
  unsigned int v2; // edi@1
  PackableHashData<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v3; // esi@3
  QuestDef *result; // eax@6

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

//----- (00599800) --------------------------------------------------------  // acclient.c:451826
PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *__thiscall PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vector_deleting_destructor(PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *this, unsigned int a2)
{
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char> >,QuestDef> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::EmptyContents(this);
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
// 7E4F98: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable)(void *, char);

//----- (00599850) --------------------------------------------------------  // acclient.c:451848
void __thiscall QuestDefDB::~QuestDefDB(QuestDefDB *this)
{
  QuestDefDB *v1; // edi@1
  char *v2; // esi@1

  v1 = this;
  v2 = (char *)&this->_defs;
  this->_defs.vfptr = (PackObjVtbl *)&PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::EmptyContents(&this->_defs);
  if ( *((_DWORD *)v2 + 2) )
  {
    operator delete[](*((void **)v2 + 2));
    *((_DWORD *)v2 + 2) = 0;
  }
  *((_DWORD *)v2 + 3) = 0;
  *(_DWORD *)v2 = &PackObj::vftable;
  if ( v1 )
  {
    v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
    DBObj::~DBObj((DBObj *)&v1->vfptr);
  }
  else
  {
    v0 = (size_t)&PackObj::vftable;
    DBObj::~DBObj(0);
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4F98: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable)(void *, char);

//----- (005998B0) --------------------------------------------------------  // acclient.c:451879
CQuestDefDB *__thiscall CQuestDefDB::vector_deleting_destructor(CQuestDefDB *this, unsigned int a2)
{
  return CQuestDefDB::vector_deleting_destructor((CQuestDefDB *)((char *)this - 48), a2);
}

//----- (005998C0) --------------------------------------------------------  // acclient.c:451885
void __thiscall CQuestDefDB::CQuestDefDB(CQuestDefDB *this)
{
  CQuestDefDB *v1; // esi@1

  v1 = this;
  QuestDefDB::QuestDefDB((QuestDefDB *)&this->vfptr, stru_871130);
  v1->vfptr = (InterfaceVtbl *)&CQuestDefDB::vftable;
  v1->vfptr = (PackObjVtbl *)&CQuestDefDB::vftable;
}
// 7E4FC0: using guessed type void *CQuestDefDB::vftable;
// 7E4FD8: using guessed type __int32 (__stdcall *CQuestDefDB::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005998E0) --------------------------------------------------------  // acclient.c:451898
CQuestDefDB *__thiscall CQuestDefDB::vector_deleting_destructor(CQuestDefDB *this, unsigned int a2)
{
  CQuestDefDB *v2; // esi@1

  v2 = this;
  QuestDefDB::~QuestDefDB((QuestDefDB *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0070AF90) --------------------------------------------------------  // acclient.c:798164
int sub_70AF90()
{
  return atexit(nullsub_1430);
}

