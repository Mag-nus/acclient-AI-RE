/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Fellowship
   Object     : AC\acfellowship\Fellowship.obj
   Functions  : 21
   Addresses  : 005B9070 - 0070E7C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B9070) --------------------------------------------------------  // acclient.c:483774
BOOL __thiscall Fellowship::IsFull(Fellowship *this)
{
  return this->_fellowship_table._currNum >= 9;
}

//----- (005B9080) --------------------------------------------------------  // acclient.c:483780
int __thiscall Fellowship::IsFellow(Fellowship *this, unsigned int fellow)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,Fellow> **v3; // ecx@2
  PackableHashData<unsigned long,Fellow> *v4; // edx@3
  int result; // eax@6

  v2 = this->_fellowship_table._table_size;
  if ( v2 && (v3 = this->_fellowship_table._buckets) != 0 && (v4 = v3[fellow % v2]) != 0 )
  {
    while ( fellow != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data != 0;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (005B90D0) --------------------------------------------------------  // acclient.c:483807
int __thiscall Fellowship::InqFellow(Fellowship *this, unsigned int fellow, Fellow *retval)
{
  unsigned int v3; // esi@1
  PackableHashData<unsigned long,Fellow> **v4; // ecx@2
  PackableHashData<unsigned long,Fellow> *v5; // edx@3
  int result; // eax@6

  v3 = this->_fellowship_table._table_size;
  if ( !v3 )
    goto LABEL_12;
  v4 = this->_fellowship_table._buckets;
  if ( !v4 )
    goto LABEL_12;
  v5 = v4[fellow % v3];
  if ( !v5 )
    goto LABEL_12;
  while ( fellow != v5->_key )
  {
    v5 = v5->_next;
    if ( !v5 )
      return 0;
  }
  if ( v5 != (PackableHashData<unsigned long,Fellow> *)-4 )
  {
    Fellow::operator=((int)retval, (int)&v5->_data);
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (005B9130) --------------------------------------------------------  // acclient.c:483843
unsigned int __thiscall Fellowship::CalculateExperienceProportionSum(Fellowship *this)
{
  unsigned int result; // eax@2
  unsigned int v2; // ebp@3
  PackableHashData<unsigned long,Fellow> **v3; // edi@3
  unsigned int v4; // ebx@3
  PackableHashData<unsigned long,Fellow> *v5; // esi@3
  int v6; // eax@7
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+0h] [bp-10h]@3

  if ( this->_share_xp )
  {
    v2 = 0;
    PackableHashTable<unsigned long,Fellow>::begin(&this->_fellowship_table, &iter);
    v3 = iter._buckets;
    v4 = iter._table_size;
    v5 = iter._current;
    while ( v5 )
    {
      v2 += FellowshipSystem::GetExperienceProportion(v5->_data._level);
      if ( v5->_next )
      {
        v5 = v5->_next;
      }
      else
      {
        v6 = v5->_hashVal + 1;
        if ( v6 >= v4 )
        {
LABEL_10:
          v5 = 0;
        }
        else
        {
          while ( !v3[v6] )
          {
            ++v6;
            if ( v6 >= v4 )
              goto LABEL_10;
          }
          v5 = v3[v6];
        }
      }
    }
    result = v2;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B91B0) --------------------------------------------------------  // acclient.c:483897
unsigned int __thiscall Fellowship::GetLeadersLevel(Fellowship *this)
{
  unsigned int v1; // esi@1
  unsigned int v2; // edi@1
  PackableHashData<unsigned long,Fellow> **v3; // ecx@2
  PackableHashData<unsigned long,Fellow> *v4; // edx@3
  unsigned int result; // eax@6

  v1 = this->_fellowship_table._table_size;
  v2 = this->_leader;
  if ( !v1 )
    goto LABEL_12;
  v3 = this->_fellowship_table._buckets;
  if ( !v3 )
    goto LABEL_12;
  v4 = v3[v2 % v1];
  if ( !v4 )
    goto LABEL_12;
  while ( v2 != v4->_key )
  {
    v4 = v4->_next;
    if ( !v4 )
      return -1;
  }
  if ( v4 != (PackableHashData<unsigned long,Fellow> *)-4 )
    result = v4->_data._level;
  else
LABEL_12:
    result = -1;
  return result;
}

//----- (005B9200) --------------------------------------------------------  // acclient.c:483930
unsigned int __thiscall Fellowship::GetNonLeaderFellowID(Fellowship *this)
{
  Fellowship *v1; // edi@1
  PackableHashData<unsigned long,Fellow> *v2; // eax@1
  unsigned int v3; // eax@6
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+8h] [bp-10h]@1

  v1 = this;
  PackableHashTable<unsigned long,Fellow>::begin(&this->_fellowship_table, &iter);
  v2 = iter._current;
  while ( v2 )
  {
    if ( v1->_leader != v2->_key )
      return v2->_key;
    if ( v2->_next )
    {
      v2 = v2->_next;
    }
    else
    {
      v3 = v2->_hashVal + 1;
      if ( v3 >= iter._table_size )
      {
LABEL_9:
        v2 = 0;
      }
      else
      {
        while ( !iter._buckets[v3] )
        {
          ++v3;
          if ( v3 >= iter._table_size )
            goto LABEL_9;
        }
        v2 = iter._buckets[v3];
      }
    }
  }
  return 0;
}

//----- (005B9270) --------------------------------------------------------  // acclient.c:483972
void __thiscall Fellowship::HandleLockedRemoveFellow(Fellowship *this, unsigned int fellow_id)
{
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v2; // esi@2
  int return_time; // [sp+0h] [bp-4h]@1

  return_time = (int)this;
  if ( this->_locked )
  {
    v2 = (PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *)&this->_fellows_departed;
    if ( PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
           (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&this->_fellows_departed,
           (IDClass<_tagDataID,32,0> *)&fellow_id) )
    {
      PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::remove(
        v2,
        &fellow_id,
        (IDClass<_tagDataID,32,0> *)&return_time);
      return_time = Timer::get_real_time();
      PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
        (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2,
        (IDClass<_tagDataID,32,0> *)&fellow_id,
        &return_time);
    }
    else
    {
      return_time = Timer::get_real_time();
      PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(
        (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2,
        (IDClass<_tagDataID,32,0> *)&fellow_id,
        &return_time);
    }
  }
}

//----- (005B92E0) --------------------------------------------------------  // acclient.c:484007
void __thiscall Fellowship::RecalculateEvenXPSplitting(Fellowship *this)
{
  Fellowship *v1; // ebx@1
  unsigned int v2; // ebp@2
  signed int v3; // edi@2
  PackableHashData<unsigned long,Fellow> *v4; // eax@2
  unsigned int v5; // ecx@4
  unsigned int v6; // eax@10
  unsigned int max; // [sp+4h] [bp-14h]@2
  PackableHashIterator<unsigned long,Fellow> iter; // [sp+8h] [bp-10h]@2

  v1 = this;
  if ( this->_share_xp )
  {
    v2 = Fellowship::GetLeadersLevel(this);
    v3 = 100000;
    max = 0;
    PackableHashTable<unsigned long,Fellow>::begin(&v1->_fellowship_table, &iter);
    v4 = iter._current;
    while ( v4 )
    {
      v5 = v4->_data._level;
      if ( v5 < v3 )
        v3 = v4->_data._level;
      if ( v5 > max )
        max = v4->_data._level;
      if ( v4->_next )
      {
        v4 = v4->_next;
      }
      else
      {
        v6 = v4->_hashVal + 1;
        if ( v6 >= iter._table_size )
        {
LABEL_13:
          v4 = 0;
        }
        else
        {
          while ( !iter._buckets[v6] )
          {
            ++v6;
            if ( v6 >= iter._table_size )
              goto LABEL_13;
          }
          v4 = iter._buckets[v6];
        }
      }
    }
    v1->_even_xp_split = 1;
    if ( (unsigned int)v3 < 0x32 )
    {
      if ( max > v2 + 5 )
        v1->_even_xp_split = 0;
      if ( v3 + 5 < v2 )
        v1->_even_xp_split = 0;
    }
  }
}

//----- (005B93A0) --------------------------------------------------------  // acclient.c:484069
int __thiscall Fellowship::GetPackSize(Fellowship *this)
{
  char *v1; // esi@1
  char *v2; // edi@1
  int v3; // ebx@1
  int v4; // ebx@1
  void *addr; // [sp+8h] [bp-4h]@1

  v1 = (char *)&this->_fellows_departed;
  v2 = (char *)&this->_fellowship_table;
  addr = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(&this->_name, &addr, 0);
  v4 = (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v1 + 12))(v1, &addr, 0) + v3;
  return v4 + (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v2 + 12))(v2, &addr, 0) + 20;
}

//----- (005B93F0) --------------------------------------------------------  // acclient.c:484086
unsigned int __thiscall Fellowship::Pack(Fellowship *this, void **addr, unsigned int size)
{
  Fellowship *v3; // edi@1
  unsigned int v4; // ebp@1
  char *v5; // ecx@2
  char *v6; // eax@2
  char *v7; // edx@2
  char *v8; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    ((void (__thiscall *)(int, void **, unsigned int))v3->_fellowship_table.vfptr->Pack)(
      &v3->_fellowship_table,
      addr,
      size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
    *(_DWORD *)*addr = v3->_leader;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_share_xp;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_even_xp_split;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_open_fellow;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_locked;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->_fellows_departed.vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (005B9480) --------------------------------------------------------  // acclient.c:484124
int __thiscall Fellowship::AddFellow(Fellowship *this, unsigned int fellow_id, Fellow *fellow)
{
  Fellowship *v3; // esi@1
  int *v4; // edi@2
  int result; // eax@5
  IDClass<_tagDataID,32,0> key; // [sp+0h] [bp-4h]@1

  v3 = this;
  key.id = fellow_id;
  if ( (!this->_locked
     || (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
                (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&this->_fellows_departed,
                &key)) != 0
     && Timer::get_real_time() - *v4 <= 900)
    && PackableHashTable<unsigned long,Fellow>::add(&v3->_fellowship_table, &fellow_id, fellow) )
  {
    Fellowship::RecalculateEvenXPSplitting(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B94F0) --------------------------------------------------------  // acclient.c:484151
int __thiscall Fellowship::UnPack(Fellowship *this, void **addr, unsigned int size)
{
  Fellowship *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@1
  int result; // eax@2
  void *v7; // ebp@3
  char *v8; // eax@5
  unsigned int v9; // ecx@6
  char *v10; // eax@9
  int v11; // edi@10

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  v5 = size;
  if ( size >= v4 )
  {
    v7 = *addr;
    if ( ((int (__thiscall *)(int, void **, unsigned int))v3->_fellowship_table.vfptr->UnPack)(
           &v3->_fellowship_table,
           addr,
           size)
      && ((v8 = (char *)((_BYTE *)*addr - (_BYTE *)v7), v5 <= (unsigned int)v8) ? (v9 = 0) : (v9 = v5 - (_DWORD)v8),
          AC1Legacy::PStringBase<char>::UnPack(&v3->_name, addr, v9)
       && (v10 = (char *)((_BYTE *)*addr - (_BYTE *)v7), v5 > (unsigned int)v10)
       && (v11 = v5 - (_DWORD)v10, (unsigned int)v11 >= 4)
       && (v3->_leader = *(_DWORD *)*addr,
           *addr = (char *)*addr + 4,
           size = v11 - 4,
           PackObj::UNPACK_TYPE(&v3->_share_xp, addr, &size))
       && PackObj::UNPACK_TYPE(&v3->_even_xp_split, addr, &size)
       && PackObj::UNPACK_TYPE(&v3->_open_fellow, addr, &size)
       && PackObj::UNPACK_TYPE(&v3->_locked, addr, &size)) )
      result = ((int (__thiscall *)(int, void **, unsigned int))v3->_fellows_departed.vfptr->UnPack)(
                 &v3->_fellows_departed,
                 addr,
                 size) != 0;
    else
      result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B95F0) --------------------------------------------------------  // acclient.c:484199
int __thiscall PackableHashTable<unsigned long,Fellow>::remove(PackableHashTable<unsigned long,Fellow> *this, const unsigned int *key, Fellow *retval)
{
  PackableHashTable<unsigned long,Fellow> *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,Fellow> **v5; // esi@2
  const unsigned int v6; // edx@3
  PackableHashData<unsigned long,Fellow> *v7; // edi@3
  PackableHashData<unsigned long,Fellow> *v8; // esi@3
  int result; // eax@6
  PackableHashData<unsigned long,Fellow> *v10; // ecx@7

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = *key % v4, v7 = 0, (v8 = v5[v6]) != 0) )
  {
    while ( v8->_key != *key )
    {
      v7 = v8;
      v8 = v8->_next;
      if ( !v8 )
        goto LABEL_6;
    }
    Fellow::operator=((int)retval, (int)&v8->_data);
    v10 = v8->_next;
    if ( v7 )
      v7->_next = v10;
    else
      v3->_buckets[*key % v3->_table_size] = v10;
    PackableHashData<unsigned long,Fellow>::scalar_deleting_destructor(v8, 1u);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (005B9680) --------------------------------------------------------  // acclient.c:484240
int __thiscall Fellowship::RemoveFellow(Fellowship *this, unsigned int fellow)
{
  unsigned int v2; // edi@1
  Fellowship *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@2
  int result; // eax@5
  AC1Legacy::PSRefBuffer<char> *v6; // esi@6
  Fellow dummy; // [sp+8h] [bp-30h]@1

  v2 = fellow;
  v3 = this;
  Fellowship::HandleLockedRemoveFellow(this, fellow);
  Fellow::Fellow(&dummy);
  fellow = v2;
  Fellowship::HandleLockedRemoveFellow(v3, v2);
  if ( PackableHashTable<unsigned long,Fellow>::remove(&v3->_fellowship_table, &fellow, &dummy) )
  {
    Fellowship::RecalculateEvenXPSplitting(v3);
    v6 = dummy._name.m_buffer;
    dummy.vfptr = (PackObjVtbl *)&Fellow::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&dummy._name.m_buffer->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    result = 1;
  }
  else
  {
    v4 = dummy._name.m_buffer;
    dummy.vfptr = (PackObjVtbl *)&Fellow::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&dummy._name.m_buffer->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
    result = 0;
  }
  return result;
}
// 7A515C: using guessed type int (__thiscall *Fellow::vftable)(void *, char);

//----- (005B9730) --------------------------------------------------------  // acclient.c:484280
int __thiscall Fellowship::UpdateFellow(Fellowship *this, unsigned int fellow_id, Fellow *fellow)
{
  Fellowship *v3; // edi@1
  unsigned int v4; // ecx@1
  PackableHashData<unsigned long,Fellow> **v5; // esi@2
  PackableHashData<unsigned long,Fellow> *v6; // edx@3
  int result; // eax@6

  v3 = this;
  v4 = this->_fellowship_table._table_size;
  if ( !v4 )
    goto LABEL_6;
  v5 = v3->_fellowship_table._buckets;
  if ( !v5 )
    goto LABEL_6;
  v6 = v5[fellow_id % v4];
  if ( !v6 )
    goto LABEL_6;
  while ( fellow_id != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_6;
  }
  if ( v6 != (PackableHashData<unsigned long,Fellow> *)-4 )
  {
    Fellow::operator=((int)&v6->_data, (int)fellow);
    Fellowship::RecalculateEvenXPSplitting(v3);
    result = 1;
  }
  else
  {
LABEL_6:
    result = Fellowship::AddFellow(v3, fellow_id, fellow);
  }
  return result;
}

//----- (005B97A0) --------------------------------------------------------  // acclient.c:484319
void __thiscall Fellowship::Fellowship(Fellowship *this)
{
  Fellowship *v1; // esi@1
  char *v2; // ecx@1
  volatile LONG *v3; // ST00_4@1
  int v4; // ecx@1

  v1 = this;
  v2 = (char *)&this->_fellowship_table;
  v1->vfptr = (PackObjVtbl *)&CFellowship::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,Fellow>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 16;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (int)&v1->_fellows_departed;
  v1->_leader = 0;
  v1->_share_xp = 1;
  v1->_even_xp_split = 0;
  v1->_open_fellow = 0;
  v1->_locked = 0;
  *(_DWORD *)v4 = &PackableHashTable<unsigned long,long>::vftable;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 32;
  *(_DWORD *)(v4 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v1->_fellows_departed);
}
// 7CEC44: using guessed type int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char);
// 7CEC58: using guessed type int (__thiscall *PackableHashTable<unsigned long,Fellow>::vftable)(void *, char);
// 7CEC6C: using guessed type int (__thiscall *CFellowship::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B9820) --------------------------------------------------------  // acclient.c:484357
int __thiscall Fellowship::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    PackableHashTable<unsigned long,Fellow>::operator=((PackableHashTable<unsigned long,Fellow> *)(this + 4), a2 + 4);
    v3 = *(_DWORD *)(v2 + 24);
    if ( v3 != *(_DWORD *)(a2 + 24) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 24);
      *(_DWORD *)(v2 + 24) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
    PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::operator=(
      (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)(v2 + 48),
      a2 + 48);
  }
  return v2;
}

//----- (0070E760) --------------------------------------------------------  // acclient.c:801465
void sub_70E760()
{
  flt_8EF434 = 1000.0 + 1.0;
}

//----- (0070E780) --------------------------------------------------------  // acclient.c:801471
void sub_70E780()
{
  flt_8EF438 = 24.0 * 8.0;
}

//----- (0070E7A0) --------------------------------------------------------  // acclient.c:801477
void sub_70E7A0()
{
  flt_8EF43C = 24.0 * 0.5;
}

//----- (0070E7C0) --------------------------------------------------------  // acclient.c:801483
int sub_70E7C0()
{
  return atexit(nullsub_1554);
}

