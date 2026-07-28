/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HousePayment
   Object     : AC\achouse\HousePayment.obj
   Functions  : 21
   Addresses  : 005BA5E0 - 0070E8B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BA5E0) --------------------------------------------------------  // acclient.c:485374
int __thiscall HousePayment::PayWithTradeNote(HousePayment *this, const int amount, const int value)
{
  HousePayment *v3; // esi@1
  unsigned int v4; // edi@1
  int v5; // ecx@6
  int v6; // eax@6
  int v7; // eax@7
  int result; // eax@9

  v3 = this;
  v4 = this->wcid.id;
  if ( !(WClassIDHelper::IsCoinstack::_2::local_static_guard & 1) )
  {
    WClassIDHelper::IsCoinstack::_2::local_static_guard |= 1u;
    DBObj::GetDIDByEnum(&WClassIDHelper::IsCoinstack::_2::didCoinstack, 268435458, 12);
    atexit(WClassIDHelper::IsCoinstack::_2::didCoinstack);
  }
  if ( v4 != WClassIDHelper::IsCoinstack::_2::didCoinstack.id
    || amount <= 0
    || value <= 0
    || (v5 = v3->paid, v6 = v3->num, v5 >= v6)
    || (v7 = v6 - v5, v7 <= 0)
    || v7 < value
    || (result = v7 / value, result <= 0) )
  {
    result = 0;
  }
  else
  {
    if ( result > amount )
      result = amount;
    v3->paid = v5 + value * result;
  }
  return result;
}
// 83F41C: using guessed type int WClassIDHelper::IsCoinstack::_2::local_static_guard;

//----- (005BA680) --------------------------------------------------------  // acclient.c:485412
int __thiscall HousePaymentList::ClearPayment(HousePaymentList *this)
{
  PackableLLNode<HousePayment> *i; // eax@1

  for ( i = this->head; i; i = i->next )
    i->data.paid = 0;
  return 1;
}

//----- (005BA6A0) --------------------------------------------------------  // acclient.c:485422
int __thiscall HousePaymentList::IsPaidInFull(HousePaymentList *this)
{
  PackableLLNode<HousePayment> *v1; // eax@1
  int result; // eax@4

  v1 = this->head;
  if ( v1 )
  {
    while ( v1->data.paid >= v1->data.num )
    {
      v1 = v1->next;
      if ( !v1 )
        goto LABEL_4;
    }
    result = 0;
  }
  else
  {
LABEL_4:
    result = 1;
  }
  return result;
}

//----- (005BA6C0) --------------------------------------------------------  // acclient.c:485447
int __thiscall HousePaymentList::RemovePayment(HousePaymentList *this, HousePayment *remove)
{
  PackableLLNode<HousePayment> *v2; // esi@1
  HousePayment *v3; // ebx@2
  unsigned int v4; // edi@3
  int result; // eax@9
  int v6; // eax@10
  int v7; // ecx@12
  int v8; // eax@15

  v2 = this->head;
  if ( v2 )
  {
    v3 = remove;
    while ( 1 )
    {
      v4 = v2->data.wcid.id;
      if ( !(WClassIDHelper::IsCoinstack::_2::local_static_guard & 1) )
      {
        WClassIDHelper::IsCoinstack::_2::local_static_guard |= 1u;
        DBObj::GetDIDByEnum(&WClassIDHelper::IsCoinstack::_2::didCoinstack, 268435458, 12);
        atexit(WClassIDHelper::IsCoinstack::_2::didCoinstack);
      }
      if ( v4 == WClassIDHelper::IsCoinstack::_2::didCoinstack.id
        && HouseSystem::IsTradeNote(&v3->wcid, (unsigned int *)&remove) )
        break;
      if ( v3->wcid.id == v2->data.wcid.id )
      {
        v7 = v3->num;
        goto LABEL_14;
      }
      v2 = v2->next;
      if ( !v2 )
        goto LABEL_9;
    }
    v6 = v3->num;
    if ( v6 <= 0 || (signed int)remove <= 0 )
      goto LABEL_9;
    v7 = (_DWORD)remove * v6;
LABEL_14:
    if ( v7 <= 0 )
      goto LABEL_9;
    v8 = v2->data.paid;
    if ( v7 <= v8 )
    {
      v2->data.paid = v8 - v7;
      result = 1;
    }
    else
    {
      v2->data.paid = 0;
      result = 1;
    }
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}
// 83F41C: using guessed type int WClassIDHelper::IsCoinstack::_2::local_static_guard;

//----- (005BA790) --------------------------------------------------------  // acclient.c:485511
int __thiscall HousePaymentList::NeedsMore(HousePaymentList *this, IDClass<_tagDataID,32,0> wcid)
{
  PackableLLNode<HousePayment> *v2; // esi@1
  unsigned int v3; // edi@2
  int result; // eax@8
  int v5; // eax@9
  int v6; // esi@9
  unsigned int amount; // [sp+0h] [bp-4h]@1

  amount = (unsigned int)this;
  v2 = this->head;
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = v2->data.wcid.id;
      if ( !(WClassIDHelper::IsCoinstack::_2::local_static_guard & 1) )
      {
        WClassIDHelper::IsCoinstack::_2::local_static_guard |= 1u;
        DBObj::GetDIDByEnum(&WClassIDHelper::IsCoinstack::_2::didCoinstack, 268435458, 12);
        atexit(WClassIDHelper::IsCoinstack::_2::didCoinstack);
      }
      if ( v3 == WClassIDHelper::IsCoinstack::_2::didCoinstack.id )
      {
        amount = 0;
        if ( HouseSystem::IsTradeNote(&wcid, &amount) )
          break;
      }
      if ( v2->data.wcid.id == wcid.id )
        return v2->data.paid < v2->data.num;
      v2 = v2->next;
      if ( !v2 )
        goto LABEL_8;
    }
    v5 = v2->data.paid;
    v6 = v2->data.num;
    if ( v5 >= v6 )
      goto LABEL_8;
    result = v6 - v5 >= amount;
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}
// 83F41C: using guessed type int WClassIDHelper::IsCoinstack::_2::local_static_guard;

//----- (005BA850) --------------------------------------------------------  // acclient.c:485561
int __thiscall HousePaymentList::AttemptToPay(HousePaymentList *this, IDClass<_tagDataID,32,0> wcid, const int amount)
{
  PackableLLNode<HousePayment> *v3; // esi@1
  unsigned int v4; // edi@2
  const int result; // eax@8
  const int v6; // edx@10
  int v7; // ecx@11
  int v8; // eax@11
  unsigned int value; // [sp+0h] [bp-4h]@1

  value = (unsigned int)this;
  v3 = this->head;
  if ( !v3 )
    goto LABEL_8;
  while ( 1 )
  {
    v4 = v3->data.wcid.id;
    if ( !(WClassIDHelper::IsCoinstack::_2::local_static_guard & 1) )
    {
      WClassIDHelper::IsCoinstack::_2::local_static_guard |= 1u;
      DBObj::GetDIDByEnum(&WClassIDHelper::IsCoinstack::_2::didCoinstack, 268435458, 12);
      atexit(WClassIDHelper::IsCoinstack::_2::didCoinstack);
    }
    if ( v4 == WClassIDHelper::IsCoinstack::_2::didCoinstack.id && HouseSystem::IsTradeNote(&wcid, &value) )
      return HousePayment::PayWithTradeNote(&v3->data, amount, value);
    if ( wcid.id == v3->data.wcid.id )
      break;
    v3 = v3->next;
    if ( !v3 )
      goto LABEL_8;
  }
  v6 = amount;
  if ( amount > 0 && (v7 = v3->data.paid, v8 = v3->data.num, v7 < v8) )
  {
    if ( v7 + amount <= v8 )
    {
      v3->data.paid = v7 + amount;
      result = v6;
    }
    else
    {
      v3->data.paid = v8;
      result = v8 - v7;
    }
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}
// 83F41C: using guessed type int WClassIDHelper::IsCoinstack::_2::local_static_guard;

//----- (005BA920) --------------------------------------------------------  // acclient.c:485616
int __thiscall HousePayment::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6
  int v5; // ebx@7
  int v6; // edi@11

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    v3 = *(_DWORD *)(this + 16);
    if ( v3 != *(_DWORD *)(a2 + 16) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 16);
      *(_DWORD *)(v2 + 16) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    v5 = *(_DWORD *)(v2 + 20);
    if ( v5 != *(_DWORD *)(a2 + 20) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(v2 + 20) = v6;
      InterlockedIncrement((volatile LONG *)(v6 + 4));
    }
  }
  return v2;
}

//----- (005BA9B0) --------------------------------------------------------  // acclient.c:485653
int __thiscall HousePayment::GetPackSize(HousePayment *this)
{
  HousePayment *v1; // esi@1
  int v2; // edi@1
  void *mem; // [sp+0h] [bp-4h]@1

  v1 = this;
  mem = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(&this->pname, &mem, 0);
  return v2 + AC1Legacy::PStringBase<char>::Pack(&v1->name, &mem, 0) + 12;
}

//----- (005BA9F0) --------------------------------------------------------  // acclient.c:485666
unsigned int __thiscall HousePayment::Pack(HousePayment *this, void **addr, unsigned int size)
{
  HousePayment *v3; // edi@1
  unsigned int v4; // ebp@1
  char *v5; // eax@2
  char *v6; // edx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->num;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->paid;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->wcid.id;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->name, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->pname, addr, size);
  }
  return v4;
}

//----- (005BAA50) --------------------------------------------------------  // acclient.c:485692
BOOL __thiscall HousePaymentList::Pay(HousePaymentList *this, HousePayment *pay)
{
  return HousePaymentList::AttemptToPay(this, pay->wcid, pay->num) != 0;
}

//----- (005BAA70) --------------------------------------------------------  // acclient.c:485698
void __thiscall HousePayment::HousePayment(HousePayment *this, HousePayment *rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&HousePayment::vftable;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  *(_DWORD *)(v2 + 20) = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  HousePayment::operator=(v2, (int)rhs);
}
// 7AB648: using guessed type int (__thiscall *HousePayment::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BAAC0) --------------------------------------------------------  // acclient.c:485718
int __thiscall HousePayment::UnPack(HousePayment *this, void **addr, unsigned int size)
{
  HousePayment *v3; // edi@1
  int result; // eax@2
  void *v5; // ebx@3
  char *v6; // ecx@3
  char *v7; // eax@3
  unsigned int v8; // ecx@3
  char *v9; // eax@3
  unsigned int v10; // ecx@4
  char *v11; // eax@7
  unsigned int v12; // ebp@8

  v3 = this;
  if ( size >= 0xC )
  {
    v5 = *addr;
    this->num = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->paid = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    v8 = *(_DWORD *)v7;
    *addr = v7 + 4;
    v3->wcid.id = v8;
    v9 = (char *)((_BYTE *)*addr - (_BYTE *)v5);
    if ( size <= (unsigned int)v9 )
      v10 = 0;
    else
      v10 = size - (_DWORD)v9;
    result = AC1Legacy::PStringBase<char>::UnPack(&v3->name, addr, v10);
    if ( result )
    {
      v11 = (char *)((_BYTE *)*addr - (_BYTE *)v5);
      if ( size <= (unsigned int)v11 )
        v12 = 0;
      else
        v12 = size - (_DWORD)v11;
      result = AC1Legacy::PStringBase<char>::UnPack(&v3->pname, addr, v12) != 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BAB50) --------------------------------------------------------  // acclient.c:485768
int __thiscall HousePayment::GetName(HousePayment *this, AC1Legacy::PStringBase<char> *n)
{
  HousePayment *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@2
  unsigned int v4; // eax@2
  AC1Legacy::PSRefBuffer<char> *v6; // eax@5
  AC1Legacy::PSRefBuffer<char> *v7; // esi@6
  unsigned int v8; // eax@6
  AC1Legacy::PSRefBuffer<char> *v9; // eax@9
  unsigned int v10; // ecx@9
  AC1Legacy::PStringBase<char> *v11; // edi@9
  AC1Legacy::PSRefBuffer<char> *v12; // esi@12
  unsigned int v13; // eax@12
  int v14; // ecx@12
  bool v15; // cf@12
  int v16; // eax@12
  char v17; // al@14
  AC1Legacy::PStringBase<char> *v18; // esi@17
  AC1Legacy::PSRefBuffer<char> *v19; // eax@17

  v2 = this;
  if ( this->num == 1 )
  {
    v3 = this->name.m_buffer;
    v4 = v3->m_len;
    if ( v4 != 1 && v3 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      AC1Legacy::PStringBase<char>::append_n_chars(n, v3->m_data, v4 - 1);
      return 1;
    }
  }
  else
  {
    v6 = this->pname.m_buffer;
    if ( v6->m_len == 1 )
    {
      v9 = this->name.m_buffer;
      v10 = v9->m_len;
      v11 = n;
      if ( v10 != 1 && v9 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(n, v9->m_data, v10 - 1);
      v12 = v2->name.m_buffer;
      v13 = v12->m_len;
      v14 = v13 - 1;
      v15 = v13 - 1 < v13;
      v16 = (int)((char *)&v12->m_hash + v13 + 3);
      if ( v15 )
        v16 = (int)&v12->m_data[v14];
      v17 = *(_BYTE *)v16;
      if ( v17 != 115 && v17 != 120 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&n, "s");
        AC1Legacy::PStringBase<char>::operator+=(v11, (AC1Legacy::PStringBase<char> *)&n);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&n);
        return 1;
      }
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&n, "es");
      v18 = n;
      v19 = n[2].m_buffer;
      if ( v19 != (AC1Legacy::PSRefBuffer<char> *)1
        && n != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
        AC1Legacy::PStringBase<char>::append_n_chars(v11, (const char *)&n[5], (unsigned int)&v19[-1].m_data[3]);
      if ( !InterlockedDecrement((volatile LONG *)&v18[1]) )
        ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v18->m_buffer->vfptr)(v18, 1);
    }
    else
    {
      v7 = this->pname.m_buffer;
      v8 = v6->m_len;
      if ( v8 != 1 && v7 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      {
        AC1Legacy::PStringBase<char>::append_n_chars(n, v7->m_data, v8 - 1);
        return 1;
      }
    }
  }
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BAC90) --------------------------------------------------------  // acclient.c:485849
int __thiscall PackableList<HousePayment>::UnPack(PackableList<HousePayment> *this, void **addr, unsigned int size)
{
  PackableList<HousePayment> *v3; // edi@1
  int v4; // esi@2
  void *v5; // eax@4
  int v6; // esi@4
  volatile LONG *v7; // ST04_4@5
  volatile LONG *v8; // ST04_4@5
  int result; // eax@6
  PackableLLNode<HousePayment> *v10; // eax@10
  AC1Legacy::PSRefBuffer<char> *v11; // esi@12
  AC1Legacy::PSRefBuffer<char> *v12; // esi@15
  AC1Legacy::PSRefBuffer<char> *v13; // esi@19
  AC1Legacy::PSRefBuffer<char> *v14; // esi@22
  int ii; // [sp+8h] [bp-20h]@2
  int maxNum; // [sp+Ch] [bp-1Ch]@2
  HousePayment temp; // [sp+10h] [bp-18h]@2

  v3 = this;
  PackableList<HousePayment>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    temp.wcid.id = stru_8EF488.id;
    temp.name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    maxNum = v4;
    temp.vfptr = (PackObjVtbl *)&HousePayment::vftable;
    temp.num = 0;
    temp.paid = 0;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    temp.pname.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    ii = 0;
    if ( v4 <= 0 )
    {
LABEL_12:
      v11 = temp.pname.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&temp.pname.m_buffer->m_cRef) && v11 )
        v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
      v12 = temp.name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&temp.name.m_buffer->m_cRef) )
      {
        if ( v12 )
          v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
      }
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(HousePayment *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        v5 = operator new(0x20u);
        v6 = (int)v5;
        if ( v5 )
        {
          *(_DWORD *)v5 = &HousePayment::vftable;
          v7 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
          *((_DWORD *)v5 + 4) = AC1Legacy::PStringBase<char>::s_NullBuffer;
          InterlockedIncrement(v7);
          v8 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
          *(_DWORD *)(v6 + 20) = AC1Legacy::PStringBase<char>::s_NullBuffer;
          InterlockedIncrement(v8);
          HousePayment::operator=(v6, (int)&temp);
          *(_DWORD *)(v6 + 24) = 0;
          *(_DWORD *)(v6 + 28) = 0;
        }
        else
        {
          v6 = 0;
        }
        if ( v3->head )
        {
          v10 = v3->tail;
          v10->next = (PackableLLNode<HousePayment> *)v6;
          *(_DWORD *)(v6 + 28) = v10;
        }
        else
        {
          v3->head = (PackableLLNode<HousePayment> *)v6;
        }
        v3->tail = (PackableLLNode<HousePayment> *)v6;
        ++v3->curNum;
        ++ii;
        if ( ii >= maxNum )
          goto LABEL_12;
      }
      v13 = temp.pname.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&temp.pname.m_buffer->m_cRef) && v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
      v14 = temp.name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&temp.name.m_buffer->m_cRef) && v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
      result = 0;
    }
  }
  return result;
}
// 7AB648: using guessed type int (__thiscall *HousePayment::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BAE50) --------------------------------------------------------  // acclient.c:485955
HousePaymentList *__thiscall PackableList<HousePayment>::vector_deleting_destructor(HousePaymentList *this, unsigned int a2)
{
  HousePaymentList *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&this->vfptr);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);

//----- (005BAE80) --------------------------------------------------------  // acclient.c:485971
void __thiscall HousePaymentList::~HousePaymentList(HousePaymentList *this)
{
  HousePaymentList *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);

//----- (005BAEA0) --------------------------------------------------------  // acclient.c:485984
int __thiscall HousePayment::ComposeText(HousePayment *this, AC1Legacy::PStringBase<char> *text)
{
  HousePayment *v2; // edi@1
  int v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  unsigned int v5; // eax@1
  AC1Legacy::PStringBase<char> *v6; // ebx@1
  AC1Legacy::PStringBase<char> *v7; // esi@6
  AC1Legacy::PSRefBuffer<char> *v8; // eax@6
  AC1Legacy::PStringBase<char> v10; // [sp+0h] [bp-4h]@1

  v10.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = this;
  v3 = this->num;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::operator=(&v10, v3);
  v4 = v10.m_buffer;
  v5 = v10.m_buffer->m_len;
  v6 = text;
  if ( v5 != 1 && v10.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(text, v10.m_buffer->m_data, v5 - 1);
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&text, " ");
  v7 = text;
  v8 = text[2].m_buffer;
  if ( v8 != (AC1Legacy::PSRefBuffer<char> *)1
    && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)&text[5], (unsigned int)&v8[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v7[1]) )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v7->m_buffer->vfptr)(v7, 1);
  return HousePayment::GetName(v2, v6);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BAF60) --------------------------------------------------------  // acclient.c:486020
int __thiscall HousePayment::ComposeText2(HousePayment *this, AC1Legacy::PStringBase<char> *text)
{
  HousePayment *v2; // edi@1
  int v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  unsigned int v5; // eax@1
  AC1Legacy::PStringBase<char> *v6; // ebp@1
  AC1Legacy::PStringBase<char> *v7; // esi@6
  AC1Legacy::PSRefBuffer<char> *v8; // eax@6
  int v9; // esi@11
  AC1Legacy::PStringBase<char> *v10; // esi@11
  AC1Legacy::PSRefBuffer<char> *v11; // eax@11
  AC1Legacy::PStringBase<char> *v12; // esi@16
  AC1Legacy::PSRefBuffer<char> *v13; // eax@16
  AC1Legacy::PStringBase<char> v15; // [sp+10h] [bp-4h]@1

  v15.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = this;
  v3 = this->paid;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::operator=(&v15, v3);
  v4 = v15.m_buffer;
  v5 = v15.m_buffer->m_len;
  v6 = text;
  if ( v5 != 1 && v15.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(text, v15.m_buffer->m_data, v5 - 1);
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&text, "/");
  v7 = text;
  v8 = text[2].m_buffer;
  if ( v8 != (AC1Legacy::PSRefBuffer<char> *)1
    && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)&text[5], (unsigned int)&v8[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v7[1]) )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v7->m_buffer->vfptr)(v7, 1);
  v9 = v2->num;
  text = (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::operator=((AC1Legacy::PStringBase<char> *)&text, v9);
  v10 = text;
  v11 = text[2].m_buffer;
  if ( v11 != (AC1Legacy::PSRefBuffer<char> *)1
    && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)&text[5], (unsigned int)&v11[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v10[1]) )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v10->m_buffer->vfptr)(v10, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&text, " ");
  v12 = text;
  v13 = text[2].m_buffer;
  if ( v13 != (AC1Legacy::PSRefBuffer<char> *)1
    && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v6, (const char *)&text[5], (unsigned int)&v13[-1].m_data[3]);
  if ( !InterlockedDecrement((volatile LONG *)&v12[1]) )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v12->m_buffer->vfptr)(v12, 1);
  return HousePayment::GetName(v2, v6);
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BB0B0) --------------------------------------------------------  // acclient.c:486080
int __thiscall HousePaymentList::ComposeText(HousePaymentList *this, AC1Legacy::PStringBase<char> *text)
{
  AC1Legacy::PStringBase<char> *v2; // ebx@1
  PackableLLNode<HousePayment> *i; // edi@1
  AC1Legacy::PStringBase<char> *v4; // esi@2
  AC1Legacy::PSRefBuffer<char> *v5; // eax@2
  AC1Legacy::PStringBase<char> v7; // [sp-4h] [bp-14h]@9

  v2 = text;
  for ( i = this->head; i; i = i->next )
  {
    HousePayment::ComposeText(&i->data, v2);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&text, ", ");
    v4 = text;
    v5 = text[2].m_buffer;
    if ( v5 != (AC1Legacy::PSRefBuffer<char> *)1
      && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)&text[5], (unsigned int)&v5[-1].m_data[3]);
    if ( !InterlockedDecrement((volatile LONG *)&v4[1]) )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v4->m_buffer->vfptr)(v4, 1);
    if ( !i )
      break;
  }
  v7.m_buffer = (AC1Legacy::PSRefBuffer<char> *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v7, ", ");
  AC1Legacy::PStringBase<char>::trim(v2, 0, 1, v7);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BB140) --------------------------------------------------------  // acclient.c:486111
int __thiscall HousePaymentList::ComposeText2(HousePaymentList *this, AC1Legacy::PStringBase<char> *text)
{
  AC1Legacy::PStringBase<char> *v2; // ebx@1
  PackableLLNode<HousePayment> *i; // edi@1
  AC1Legacy::PStringBase<char> *v4; // esi@2
  AC1Legacy::PSRefBuffer<char> *v5; // eax@2
  AC1Legacy::PStringBase<char> v7; // [sp-4h] [bp-14h]@9

  v2 = text;
  for ( i = this->head; i; i = i->next )
  {
    HousePayment::ComposeText2(&i->data, v2);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&text, ", ");
    v4 = text;
    v5 = text[2].m_buffer;
    if ( v5 != (AC1Legacy::PSRefBuffer<char> *)1
      && text != (AC1Legacy::PStringBase<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(v2, (const char *)&text[5], (unsigned int)&v5[-1].m_data[3]);
    if ( !InterlockedDecrement((volatile LONG *)&v4[1]) )
      ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v4->m_buffer->vfptr)(v4, 1);
    if ( !i )
      break;
  }
  v7.m_buffer = (AC1Legacy::PSRefBuffer<char> *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v7, ", ");
  AC1Legacy::PStringBase<char>::trim(v2, 0, 1, v7);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070E8B0) --------------------------------------------------------  // acclient.c:801537
int sub_70E8B0()
{
  return atexit(nullsub_1558);
}

