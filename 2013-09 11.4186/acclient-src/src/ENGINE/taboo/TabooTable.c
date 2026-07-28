/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TabooTable
   Object     : ENGINE\taboo\TabooTable.obj
   Functions  : 25
   Addresses  : 00681570 - 007154E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00681570) --------------------------------------------------------  // acclient.c:664625
char __stdcall TabooTable::CreateCheckString(unsigned int chkType, const char *baseStr, unsigned int baseStrLength, char *strOut)
{
  int v5; // ebx@4
  unsigned int v6; // esi@4
  bool v7; // al@6
  char result; // al@12

  if ( strOut && baseStr && baseStrLength )
  {
    v5 = 0;
    v6 = 0;
    if ( baseStrLength != 1 )
    {
      do
      {
        if ( chkType == 2 )
        {
          v7 = _iswalpha(baseStr[v6]) != 0;
        }
        else
        {
          if ( chkType != 3 )
            goto LABEL_10;
          v7 = _iswspace(baseStr[v6]) == 0;
        }
        if ( v7 )
LABEL_10:
          strOut[v5++] = baseStr[v6];
        ++v6;
      }
      while ( v6 < baseStrLength - 1 );
    }
    strOut[v5] = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00681600) --------------------------------------------------------  // acclient.c:664668
bool __stdcall TabooTable::StringMatchesFilter(const char *_string, const char *_filter)
{
  const char v3; // al@3
  const char v4; // cl@3
  int v5; // esi@3
  signed int v6; // edx@3
  signed int i; // ebp@3
  const char v8; // al@11
  bool result; // al@15

  if ( _string && _filter )
  {
    v3 = *_filter;
    v4 = *_string;
    v5 = 0;
    v6 = 0;
    for ( i = -1; ; v6 = i )
    {
LABEL_4:
      if ( v3 == 42 )
      {
LABEL_5:
        v3 = _filter[v6 + 1];
        i = v6++;
        while ( v4 )
        {
          if ( v4 == v3 )
            goto LABEL_4;
          v4 = _string[v5++ + 1];
        }
        return v3 == 0;
      }
      if ( v3 == v4 )
        break;
LABEL_13:
      if ( i == -1 )
        goto LABEL_17;
      v3 = _filter[i];
    }
    while ( v4 )
    {
      v8 = _filter[v6 + 1];
      v4 = _string[v5 + 1];
      ++v6;
      ++v5;
      if ( v8 == 42 )
        goto LABEL_5;
      if ( v8 != v4 )
        goto LABEL_13;
    }
    result = 1;
  }
  else
  {
LABEL_17:
    result = 0;
  }
  return result;
}

//----- (00681690) --------------------------------------------------------  // acclient.c:664729
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *v2; // esi@1
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable;
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
// 7FE84C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable[2])(void *, char);

//----- (006816D0) --------------------------------------------------------  // acclient.c:664750
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *v2; // esi@1
  HashTableData<unsigned long,List<PStringBase<char> > > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable;
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
// 7FE850: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char);

//----- (00681710) --------------------------------------------------------  // acclient.c:664771
AC1Legacy::PStringBase<char> *__cdecl GetRandomOlthoiText(AC1Legacy::PStringBase<char> *result)
{
  AC1Legacy::PSRefBuffer<char> *v1; // ebp@14
  volatile LONG *v2; // esi@14
  volatile LONG *v3; // ST04_4@14
  AC1Legacy::PStringBase<char> random_text; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-4h]@2

  random_text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  switch ( Random::RollDice(1, 10) )
  {
    case 1:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "glares menacingly.");
      goto LABEL_12;
    case 2:
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        &rhs,
        "clicks its pincers together in anticipation of destruction.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 3:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "screeches in a horrible fashion.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 4:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "lets out a maddening series of clicks and hisses.");
      goto LABEL_12;
    case 5:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "surveys the area as acid drips from its mandibles.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 6:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "hisses some kind of threat.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 7:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "calls out searching for other Olthoi.");
      goto LABEL_12;
    case 8:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "cries out to indicate to its kin that prey is near.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 9:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "casts about looking for victims.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 10:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "prepares to hunt enemies of the queen.");
LABEL_12:
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
LABEL_13:
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&rhs);
      break;
    default:
      break;
  }
  v1 = random_text.m_buffer;
  v2 = (volatile LONG *)&random_text.m_buffer->m_cRef;
  v3 = (volatile LONG *)&random_text.m_buffer->m_cRef;
  result->m_buffer = random_text.m_buffer;
  InterlockedIncrement(v3);
  if ( !InterlockedDecrement(v2) && v1 )
    v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00681870) --------------------------------------------------------  // acclient.c:664840
AC1Legacy::PStringBase<char> *__cdecl GetRandomHumanText(AC1Legacy::PStringBase<char> *result)
{
  AC1Legacy::PSRefBuffer<char> *v1; // ebp@14
  volatile LONG *v2; // esi@14
  volatile LONG *v3; // ST04_4@14
  AC1Legacy::PStringBase<char> random_text; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> rhs; // [sp+14h] [bp-4h]@2

  random_text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  switch ( Random::RollDice(1, 10) )
  {
    case 1:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "cowers in fear.");
      goto LABEL_12;
    case 2:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "calls out for help and prepares to fight you.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 3:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "seems startled to see Olthoi.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 4:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "cries out to warn others that Olthoi are present.");
      goto LABEL_12;
    case 5:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "surveys the area with weapons at the ready.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 6:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "regards you warily.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 7:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "lets out a battle cry as a challenge.");
      goto LABEL_12;
    case 8:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "goes into a defensive posture at the sight of you.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 9:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "seems to be looking for an escape route.");
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
      goto LABEL_13;
    case 10:
      AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, "gestures a challenge to you.");
LABEL_12:
      AC1Legacy::PStringBase<char>::operator+=(&random_text, &rhs);
LABEL_13:
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&rhs);
      break;
    default:
      break;
  }
  v1 = random_text.m_buffer;
  v2 = (volatile LONG *)&random_text.m_buffer->m_cRef;
  v3 = (volatile LONG *)&random_text.m_buffer->m_cRef;
  result->m_buffer = random_text.m_buffer;
  InterlockedIncrement(v3);
  if ( !InterlockedDecrement(v2) && v1 )
    v1->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v1, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006819D0) --------------------------------------------------------  // acclient.c:664907
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE84C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable[2])(void *, char);

//----- (00681A60) --------------------------------------------------------  // acclient.c:664940
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,List<PStringBase<char> > > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,List<PStringBase<char> > > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE850: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char);

//----- (00681BD0) --------------------------------------------------------  // acclient.c:665063
void __thiscall List<PStringBase<char>>::Serialize(List<PStringBase<char> > *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  unsigned int v3; // eax@1
  List<PStringBase<char> > *v4; // ebx@1
  unsigned int v5; // eax@2
  ListNode<PStringBase<char> > *i; // edi@6
  unsigned int v7; // eax@11
  Archive *v8; // ebp@13
  unsigned int v9; // edi@19
  char *v10; // esi@22

  v2 = io_archive;
  v3 = io_archive->m_flags & 5;
  v4 = this;
  if ( v3 == 1 )
  {
    Archive::CheckAlignment(io_archive, 4u);
    v5 = Archive::GetBytes(v2, 4u);
    if ( v5 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v5 = v4->_num_elements;
      else
        v4->_num_elements = *(_DWORD *)v5;
    }
    for ( i = v4->_head; i; i = i->next )
    {
      PStringBase<char>::Serialize(&i->data, v2);
      if ( !i )
        break;
    }
  }
  else if ( !v3 )
  {
    List<PStringBase<char>>::flush(this);
    Archive::CheckAlignment(v2, 4u);
    v7 = Archive::GetBytes(v2, 4u);
    if ( v7 )
    {
      if ( v2->m_flags & 1 )
      {
        v8 = io_archive;
        *(_DWORD *)v7 = io_archive;
      }
      else
      {
        v8 = *(Archive **)v7;
      }
    }
    else
    {
      v8 = io_archive;
    }
    if ( ~(unsigned __int8)(v2->m_flags >> 2) & 1 )
    {
      if ( (unsigned int)v8 <= Archive::GetSizeLeft(v2) )
      {
        io_archive = (Archive *)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v9 = 0;
        if ( v8 )
        {
          do
          {
            PStringBase<char>::Serialize((PStringBase<char> *)&io_archive, v2);
            if ( (v2->m_flags >> 2) & 1 )
              break;
            List<PStringBase<char>>::push_back(v4, (PStringBase<char> *)&io_archive);
            ++v9;
          }
          while ( v9 < (unsigned int)v8 );
        }
        v10 = (char *)&io_archive[-1].m_buffer.m_size;
        if ( !InterlockedDecrement((volatile LONG *)&io_archive[-1].m_buffer.m_masterBuffer) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      else
      {
        Archive::RaiseError(v2);
      }
    }
  }
}

//----- (00681D00) --------------------------------------------------------  // acclient.c:665149
void __thiscall List<PStringBase<char>>::List<PStringBase<char>>(List<PStringBase<char> > *this, List<PStringBase<char> > *from)
{
  List<PStringBase<char> > *v2; // edi@1
  ListNode<PStringBase<char> > *i; // esi@2

  v2 = this;
  this->vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  this->_head = 0;
  this->_tail = 0;
  this->_num_elements = 0;
  if ( this != from )
  {
    List<PStringBase<char>>::flush(this);
    for ( i = from->_head; i; i = i->next )
    {
      List<PStringBase<char>>::push_back(v2, &i->data);
      if ( !i )
        break;
    }
  }
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (00681D50) --------------------------------------------------------  // acclient.c:665173
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,List<PStringBase<char> > > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,List<PStringBase<char> > > **v5; // edx@5
  HashTableData<unsigned long,List<PStringBase<char> > > *v6; // edi@5
  HashTableData<unsigned long,List<PStringBase<char> > > *v7; // eax@7
  HashTableData<unsigned long,List<PStringBase<char> > > *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,List<PStringBase<char> > > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,List<PStringBase<char> > > **)v4;
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
      v6->m_data.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
      List<PStringBase<char>>::flush(&v6->m_data);
      operator delete(v6);
    }
  }
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (00681DE0) --------------------------------------------------------  // acclient.c:665235
HashTable<unsigned long,List<PStringBase<char> >,0> *__thiscall HashTable<unsigned long,List<PStringBase<char>>,0>::vector_deleting_destructor(HashTable<unsigned long,List<PStringBase<char> >,0> *this, unsigned int a2)
{
  HashTable<unsigned long,List<PStringBase<char> >,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,List<PStringBase<char> >,0>Vtbl *)&HashTable<unsigned long,List<PStringBase<char>>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable;
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
// 7FE850: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char);
// 7FEB74: using guessed type int (__thiscall *HashTable<unsigned long,List<PStringBase<char>>,0>::vftable)(void *, char);

//----- (00681E40) --------------------------------------------------------  // acclient.c:665261
int __thiscall HashTable<unsigned long,List<PStringBase<char>>,0>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // ebx@1
  unsigned int *v4; // ebp@2
  unsigned int *v5; // eax@2
  void *v6; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@4
  void *v9; // esi@7
  unsigned int v10; // ebx@10
  int v11; // ecx@10
  int v12; // edx@11
  int v13; // eax@14
  HashTableData<unsigned long,HeritageGroup_CG> **v14; // ecx@18
  HashTableData<unsigned long,HeritageGroup_CG> **v15; // eax@19
  int v17; // [sp+8h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v19; // [sp+18h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v17 = this;
  if ( this == __val )
    return v3;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)(this + 4));
  v4 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v5 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v5 == v4 )
    --v5;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::resize_internal(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)(v3 + 4),
    *v5);
  v6 = 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v8 = v7->m_currElement;
  v19 = v7->m_currHashTable;
  result.m_currBucket = v7->m_currBucket;
  if ( !v8 )
    return v3;
  while ( 1 )
  {
    v9 = operator new(0x18u);
    if ( v9 )
    {
      *(_DWORD *)v9 = v8->m_hashKey;
      *((_DWORD *)v9 + 1) = 0;
      List<PStringBase<char>>::List<PStringBase<char>>(
        (List<PStringBase<char> > *)((char *)v9 + 8),
        (List<PStringBase<char> > *)&v8->m_data);
    }
    else
    {
      v9 = 0;
    }
    v10 = *(_DWORD *)(v3 + 108);
    v11 = *(_DWORD *)v9 % v10;
    if ( !v6 )
      goto LABEL_14;
    v12 = *(_DWORD *)v6 % v10;
    if ( v11 != v12 )
    {
      if ( v11 <= (unsigned int)v12 )
        goto LABEL_17;
LABEL_14:
      v13 = *(_DWORD *)(v17 + 100) + 4 * v11;
      *(_DWORD *)v13 = v9;
      if ( !v6 )
        *(_DWORD *)(v17 + 104) = v13;
      goto LABEL_16;
    }
    *((_DWORD *)v6 + 1) = v9;
LABEL_16:
    ++*(_DWORD *)(v17 + 112);
LABEL_17:
    v8 = v8->m_hashNext;
    v6 = v9;
    if ( !v8 )
      break;
LABEL_6:
    v3 = v17;
  }
  v14 = &v19->m_buckets[v19->m_numBuckets];
  while ( 1 )
  {
    v15 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v14 )
      return v17;
    if ( *v15 )
    {
      v8 = *v15;
      if ( *v15 )
        goto LABEL_6;
      return v17;
    }
  }
}

//----- (00681F90) --------------------------------------------------------  // acclient.c:665364
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *v1; // ebx@1
  int v2; // ecx@2
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **v5; // edx@5
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *v6; // edi@5
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *v7; // eax@7
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *v8; // ecx@8
  void *v9; // eax@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v6->m_data.vfptr = (HashTable<unsigned long,List<PStringBase<char> >,0>Vtbl *)&HashTable<unsigned long,List<PStringBase<char>>,0>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents(&v6->m_data.m_intrusiveTable);
      v9 = v6->m_data.m_intrusiveTable.m_buckets;
      v6->m_data.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable;
      if ( v9 != v6->m_data.m_intrusiveTable.m_aInplaceBuckets )
        operator delete[](v9);
      v6->m_data.m_intrusiveTable.m_buckets = 0;
      v6->m_data.m_intrusiveTable.m_firstInterestingBucket = 0;
      v6->m_data.m_intrusiveTable.m_numBuckets = 0;
      v6->m_data.m_intrusiveTable.m_numElements = 0;
      operator delete(v6);
    }
  }
}
// 7FE850: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char);
// 7FEB74: using guessed type int (__thiscall *HashTable<unsigned long,List<PStringBase<char>>,0>::vftable)(void *, char);

//----- (00682050) --------------------------------------------------------  // acclient.c:665436
unsigned int __thiscall TabooTable::CheckCensors(TabooTable *this, PStringBase<char> *strToCheck, unsigned int audience, unsigned int chkType, PStringBase<char> *tabooPatternMatchOut)
{
  TabooTable *v5; // esi@1
  unsigned int v6; // edx@1
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > **v7; // eax@1
  HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *v8; // eax@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@6
  void *v10; // ebp@6
  HashTableData<unsigned long,List<PStringBase<char> > > **v11; // ecx@6
  char *v12; // ebx@9
  unsigned int v13; // esi@12
  PSRefBufferCharData<char> *v14; // edi@12
  const char *v15; // ebx@12
  ListNode<PStringBase<char> > *v16; // esi@13
  PSRefBufferCharData<char> *v17; // eax@17
  int v18; // edi@18
  const char *v19; // esi@21
  char *v20; // esi@24
  HashTableData<unsigned long,List<PStringBase<char> > > **v21; // eax@29
  HashTableData<unsigned long,List<PStringBase<char> > > **v22; // ecx@30
  unsigned int err; // [sp+8h] [bp-A4h]@1
  PStringBase<char> strCheckInternal; // [sp+Ch] [bp-A0h]@7
  unsigned int reason; // [sp+10h] [bp-9Ch]@1
  TabooTable *v27; // [sp+14h] [bp-98h]@1
  unsigned int rejection_type; // [sp+18h] [bp-94h]@7
  List<PStringBase<char> > pattern_list; // [sp+1Ch] [bp-90h]@6
  HashIterator<unsigned long,List<PStringBase<char> >,0> rh_iter; // [sp+2Ch] [bp-80h]@6
  HashTable<unsigned long,List<PStringBase<char> >,0> rejection_hash; // [sp+38h] [bp-74h]@1

  v5 = this;
  v27 = this;
  err = 0;
  rejection_hash.vfptr = (HashTable<unsigned long,List<PStringBase<char> >,0>Vtbl *)&HashTable<unsigned long,List<PStringBase<char>>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>(
    &rejection_hash.m_intrusiveTable,
    0x17u);
  v6 = audience % v5->m_audienceToBannedPatterns.m_intrusiveTable.m_numBuckets;
  v7 = v5->m_audienceToBannedPatterns.m_intrusiveTable.m_buckets;
  reason = 0;
  v8 = v7[v6];
  if ( v8 )
  {
    while ( v8->m_hashKey != audience )
    {
      v8 = v8->m_hashNext;
      if ( !v8 )
        goto LABEL_38;
    }
    if ( v8 )
    {
      HashTable<unsigned long,List<PStringBase<char>>,0>::operator=((int)&rejection_hash, (unsigned int)&v8->m_data);
      v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
             (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&rejection_hash.m_intrusiveTable,
             (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&pattern_list);
      v10 = v9->m_currElement;
      v11 = (HashTableData<unsigned long,List<PStringBase<char> > > **)v9->m_currBucket;
      rh_iter.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)v9->m_currHashTable;
      rh_iter.m_iter.m_currBucket = v11;
      if ( v10 )
      {
        do
        {
LABEL_7:
          rejection_type = *(_DWORD *)v10;
          List<PStringBase<char>>::List<PStringBase<char>>(&pattern_list, (List<PStringBase<char> > *)((char *)v10 + 8));
          strCheckInternal.m_charbuffer = strToCheck->m_charbuffer;
          InterlockedIncrement((volatile LONG *)&strCheckInternal.m_charbuffer[-1]);
          if ( *(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[0] == 1 )
          {
            *(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[8] = -1;
          }
          else
          {
            v12 = &strCheckInternal.m_charbuffer[-2].m_data[12];
            PStringBase<char>::allocate_ref_buffer(
              &strCheckInternal,
              *(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[12] - 1);
            qmemcpy(strCheckInternal.m_charbuffer, v12 + 20, *(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[12]);
            if ( !InterlockedDecrement((volatile LONG *)v12 + 1) && v12 )
              (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
          }
          __strlwr(strCheckInternal.m_charbuffer->m_data);
          v13 = *(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[12];
          v14 = strCheckInternal.m_charbuffer;
          v15 = (const char *)operator new[](*(_DWORD *)&strCheckInternal.m_charbuffer[-1].m_data[12]);
          if ( TabooTable::CreateCheckString(chkType, v14->m_data, v13, (char *)v15) )
          {
            v16 = pattern_list._head;
            if ( pattern_list._head )
            {
              while ( !TabooTable::StringMatchesFilter(v15, v16->data.m_charbuffer->m_data) )
              {
                v16 = v16->next;
                if ( !v16 )
                  goto LABEL_24;
              }
              v17 = tabooPatternMatchOut->m_charbuffer;
              if ( tabooPatternMatchOut->m_charbuffer != v16->data.m_charbuffer )
              {
                v18 = (int)&v17[-2].m_data[12];
                if ( !InterlockedDecrement((volatile LONG *)&v17[-1]) && v18 )
                  (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
                v19 = v16->data.m_charbuffer->m_data;
                tabooPatternMatchOut->m_charbuffer = (PSRefBufferCharData<char> *)v19;
                InterlockedIncrement((volatile LONG *)v19 - 4);
              }
              reason = rejection_type;
            }
          }
          else
          {
            err = 2;
          }
LABEL_24:
          operator delete[]((void *)v15);
          v20 = &strCheckInternal.m_charbuffer[-2].m_data[12];
          if ( reason )
          {
            if ( !InterlockedDecrement((volatile LONG *)v20 + 1) && v20 )
              (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
            pattern_list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
            List<PStringBase<char>>::flush(&pattern_list);
            goto LABEL_38;
          }
          if ( !InterlockedDecrement((volatile LONG *)v20 + 1) && v20 )
            (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
          pattern_list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
          List<PStringBase<char>>::flush(&pattern_list);
          v10 = (void *)*((_DWORD *)v10 + 1);
        }
        while ( v10 );
        v21 = &rh_iter.m_iter.m_currHashTable->m_buckets[rh_iter.m_iter.m_currHashTable->m_numBuckets];
        while ( 1 )
        {
          v22 = rh_iter.m_iter.m_currBucket + 1;
          ++rh_iter.m_iter.m_currBucket;
          if ( rh_iter.m_iter.m_currBucket == v21 )
            break;
          if ( *v22 )
          {
            v10 = *v22;
            if ( *v22 )
              goto LABEL_7;
            break;
          }
        }
      }
    }
  }
LABEL_38:
  switch ( reason )
  {
    case 1u:
      err = 3;
      break;
    case 2u:
      err = 4;
      break;
    case 4u:
      err = 5;
      break;
    case 3u:
      err = 6;
      break;
    default:
      break;
  }
  rejection_hash.vfptr = (HashTable<unsigned long,List<PStringBase<char> >,0>Vtbl *)&HashTable<unsigned long,List<PStringBase<char>>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents(&rejection_hash.m_intrusiveTable);
  rejection_hash.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable;
  if ( (HashTableData<unsigned long,List<PStringBase<char> > > **)rejection_hash.m_intrusiveTable.m_buckets != rejection_hash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](rejection_hash.m_intrusiveTable.m_buckets);
  return err;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);
// 7FE850: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char);
// 7FEB74: using guessed type int (__thiscall *HashTable<unsigned long,List<PStringBase<char>>,0>::vftable)(void *, char);

//----- (00682350) --------------------------------------------------------  // acclient.c:665615
unsigned int __thiscall TabooTable::CheckCensorsW(TabooTable *this, PStringBase<unsigned short> *strToCheck, unsigned int audience, unsigned int chkType, PStringBase<unsigned short> *tabooPatternMatchOut)
{
  TabooTable *v5; // esi@1
  unsigned int v6; // ST0C_4@1
  unsigned int v7; // ST08_4@1
  PStringBase<char> *v8; // eax@1
  unsigned int v9; // eax@1
  unsigned int v10; // esi@1
  PSRefBufferCharData<unsigned short> **v11; // ebx@4
  PSRefBufferCharData<unsigned short> *v12; // eax@4
  int v13; // esi@5
  PSRefBufferCharData<unsigned short> *v14; // eax@8
  unsigned int v15; // esi@9
  char *v16; // esi@12
  PStringBase<char> temp; // [sp+10h] [bp-4h]@1

  temp.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v5 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v6 = chkType;
  v7 = audience;
  v8 = PSUtils::narrowify((PStringBase<char> *)&audience, strToCheck);
  v9 = TabooTable::CheckCensors(v5, v8, v7, v6, &temp);
  v10 = audience - 20;
  chkType = v9;
  if ( !InterlockedDecrement((volatile LONG *)(audience - 20 + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = (PSRefBufferCharData<unsigned short> **)PSUtils::widify((PStringBase<unsigned short> *)&audience, &temp);
  v12 = tabooPatternMatchOut->m_charbuffer;
  if ( tabooPatternMatchOut->m_charbuffer != *v11 )
  {
    v13 = (int)&v12[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v12[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v14 = *v11;
    tabooPatternMatchOut->m_charbuffer = *v11;
    InterlockedIncrement((volatile LONG *)&v14[-1].m_data[8]);
  }
  v15 = audience - 20;
  if ( !InterlockedDecrement((volatile LONG *)(audience - 20 + 4)) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  v16 = &temp.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&temp.m_charbuffer[-1]) && v16 )
    (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
  return chkType;
}

//----- (00682450) --------------------------------------------------------  // acclient.c:665663
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>,HashTableData<unsigned long,List<PStringBase<char>>> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  void *v9; // edi@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v11; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v12; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v13; // ebp@19
  unsigned int v14; // eax@21
  unsigned int v15; // eax@31
  HashTableData<unsigned long,Sex_CG> *v16; // ebx@32
  unsigned int v17; // ebp@32
  void *v18; // eax@35
  unsigned int v19; // eax@37
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  v9 = 0;
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v10 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
            &result);
    v11 = v10->m_currHashTable;
    v12 = v10->m_currElement;
    v13 = v10->m_currBucket;
LABEL_20:
    while ( v12 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v14 = Archive::GetBytes(v3, 4u);
        if ( v14 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v14 = v12->m_hashKey;
          else
            v12->m_hashKey = *(_DWORD *)v14;
        }
        List<PStringBase<char>>::Serialize((List<PStringBase<char> > *)&v12->m_data, v3);
        v12 = v12->m_hashNext;
      }
      while ( v12 );
      while ( 1 )
      {
        ++v13;
        if ( v13 == &v11->m_buckets[v11->m_numBuckets] )
          break;
        if ( *v13 )
        {
          v12 = *v13;
          goto LABEL_20;
        }
      }
    }
    v9 = 0;
  }
  if ( !(v3->m_flags & 5) )
  {
    v15 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v15 )
    {
LABEL_45:
      Archive::RaiseError(v3);
    }
    else
    {
      v16 = 0;
      v17 = 0;
      if ( (unsigned int)io_archive > 0 )
      {
        while ( 1 )
        {
          v18 = operator new(0x18u);
          if ( v18 )
          {
            *((_DWORD *)v18 + 1) = 0;
            *((_DWORD *)v18 + 3) = 0;
            *((_DWORD *)v18 + 4) = 0;
            *((_DWORD *)v18 + 5) = 0;
            *((_DWORD *)v18 + 2) = &List<PStringBase<char>>::vftable;
            v9 = v18;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v9;
            else
              *(_DWORD *)v9 = *(_DWORD *)v19;
          }
          List<PStringBase<char>>::Serialize((List<PStringBase<char> > *)((char *)v9 + 8), v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v9,
                  v16) )
            goto LABEL_45;
          ++v17;
          v16 = (HashTableData<unsigned long,Sex_CG> *)v9;
          if ( v17 >= (unsigned int)io_archive )
            break;
          v9 = 0;
        }
      }
    }
  }
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (00682670) --------------------------------------------------------  // acclient.c:665820
void __thiscall HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::~HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>(HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0>Vtbl *)HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7FE84C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable[2])(void *, char);
// 7FEB70: using guessed type int (__thiscall *HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable[2])(void *, char);

//----- (006826B0) --------------------------------------------------------  // acclient.c:665841
HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0> *__thiscall HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vector_deleting_destructor(HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0> *this, unsigned int a2)
{
  HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0>Vtbl *)HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable;
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
// 7FE84C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable[2])(void *, char);
// 7FEB70: using guessed type int (__thiscall *HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable[2])(void *, char);

//----- (00682710) --------------------------------------------------------  // acclient.c:665867
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::Serialize(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *this, Archive *io_archive)
{
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>,HashTableData<unsigned long,List<PStringBase<char>>> *,SB_Default>(
    (const int *)&io_archive,
    this,
    io_archive);
}

//----- (00682730) --------------------------------------------------------  // acclient.c:665876
void __thiscall TabooTable::TabooTable(TabooTable *this)
{
  TabooTable *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_8F79CC);
  v1->vfptr = (InterfaceVtbl *)&TabooTable::vftable;
  v1->m_audienceToBannedPatterns.vfptr = (HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0>,0>Vtbl *)HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>(
    &v1->m_audienceToBannedPatterns.m_intrusiveTable,
    0x17u);
}
// 7FEB70: using guessed type int (__thiscall *HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable[2])(void *, char);
// 7FEB78: using guessed type __int32 (__stdcall *TabooTable::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00682780) --------------------------------------------------------  // acclient.c:665898
DBObj *__thiscall TabooTable::scalar_deleting_destructor(TabooTable *this, unsigned int a2)
{
  DBObj *v2; // esi@1

  v2 = (DBObj *)this;
  HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::~HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>(&this->m_audienceToBannedPatterns);
  DBObj::~DBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006827B0) --------------------------------------------------------  // acclient.c:665911
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char> >,0> > *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // edi@1
  unsigned int *v4; // esi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebx@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // esi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebp@19
  unsigned int v13; // eax@21
  unsigned int v14; // eax@32
  HashTableData<unsigned long,Sex_CG> *v15; // ebx@33
  unsigned int v16; // ebp@33
  void *v17; // eax@34
  void *v18; // esi@34
  unsigned int v19; // eax@37
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        if ( ~LOBYTE(v3->m_flags) & 1 )
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)&v11->m_data.name);
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::Serialize(
          (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)&v11->m_data.name,
          v3);
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v14 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v14 )
    {
LABEL_47:
      Archive::RaiseError(v3);
    }
    else
    {
      v15 = 0;
      v16 = 0;
      if ( io_archive )
      {
        do
        {
          v17 = operator new(0x7Cu);
          v18 = v17;
          if ( v17 )
          {
            *((_DWORD *)v17 + 1) = 0;
            *((_DWORD *)v17 + 2) = &HashTable<unsigned long,List<PStringBase<char>>,0>::vftable;
            IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>(
              (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)((char *)v17 + 12),
              0x17u);
          }
          else
          {
            v18 = 0;
          }
          Archive::CheckAlignment(v3, 4u);
          v19 = Archive::GetBytes(v3, 4u);
          if ( v19 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v19 = *(_DWORD *)v18;
            else
              *(_DWORD *)v18 = *(_DWORD *)v19;
          }
          if ( ~LOBYTE(v3->m_flags) & 1 )
            IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)((char *)v18 + 12));
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::Serialize(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char> > > *,0> *)((char *)v18 + 12),
            v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v18,
                  v15) )
            goto LABEL_47;
          ++v16;
          v15 = (HashTableData<unsigned long,Sex_CG> *)v18;
        }
        while ( v16 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;
// 7FEB74: using guessed type int (__thiscall *HashTable<unsigned long,List<PStringBase<char>>,0>::vftable)(void *, char);

//----- (006829F0) --------------------------------------------------------  // acclient.c:666076
void __thiscall TabooTable::Serialize(TabooTable *this, Archive *_rArchive)
{
  Archive *v2; // edi@1
  TabooTable *v3; // esi@1

  v2 = _rArchive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, _rArchive);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::delete_contents(&v3->m_audienceToBannedPatterns.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,SB_Default>(
    (const int *)&_rArchive,
    &v3->m_audienceToBannedPatterns.m_intrusiveTable,
    v2);
}

//----- (007154E0) --------------------------------------------------------  // acclient.c:808283
int sub_7154E0()
{
  return atexit(nullsub_201);
}

