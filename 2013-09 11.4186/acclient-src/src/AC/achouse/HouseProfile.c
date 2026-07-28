/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HouseProfile
   Object     : AC\achouse\HouseProfile.obj
   Functions  : 18
   Addresses  : 005BB770 - 0070E9A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BB770) --------------------------------------------------------  // acclient.c:486486
int __thiscall HouseProfile::IsPaidInFull(HouseProfile *this, HouseOp op)
{
  char *v2; // ecx@3

  if ( op == 1 )
  {
    v2 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v2 = (char *)&this->_rent;
  }
  if ( v2 )
    return HousePaymentList::IsPaidInFull((HousePaymentList *)v2);
  return 0;
}

//----- (005BB7A0) --------------------------------------------------------  // acclient.c:486506
int __thiscall HouseProfile::Pay(HouseProfile *this, HouseOp op, HousePayment *pay)
{
  char *v3; // ecx@3

  if ( op == 1 )
  {
    v3 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v3 = (char *)&this->_rent;
  }
  if ( v3 )
    return HousePaymentList::Pay((HousePaymentList *)v3, pay);
  return 0;
}

//----- (005BB7D0) --------------------------------------------------------  // acclient.c:486526
int __thiscall HouseProfile::RemovePayment(HouseProfile *this, HouseOp op, HousePayment *pay)
{
  char *v3; // ecx@3

  if ( op == 1 )
  {
    v3 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v3 = (char *)&this->_rent;
  }
  if ( v3 )
    return HousePaymentList::RemovePayment((HousePaymentList *)v3, pay);
  return 0;
}

//----- (005BB800) --------------------------------------------------------  // acclient.c:486546
int __thiscall HouseProfile::ComposeText(HouseProfile *this, HouseOp op, AC1Legacy::PStringBase<char> *text)
{
  char *v3; // ecx@3

  if ( op == 1 )
  {
    v3 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v3 = (char *)&this->_rent;
  }
  if ( v3 )
    return HousePaymentList::ComposeText((HousePaymentList *)v3, text);
  return 0;
}

//----- (005BB830) --------------------------------------------------------  // acclient.c:486566
int __thiscall HouseProfile::ComposeText2(HouseProfile *this, HouseOp op, AC1Legacy::PStringBase<char> *text)
{
  char *v3; // ecx@3

  if ( op == 1 )
  {
    v3 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v3 = (char *)&this->_rent;
  }
  if ( v3 )
    return HousePaymentList::ComposeText2((HousePaymentList *)v3, text);
  return 0;
}

//----- (005BB860) --------------------------------------------------------  // acclient.c:486586
int __thiscall HouseProfile::NeedsMore(HouseProfile *this, HouseOp op, IDClass<_tagDataID,32,0> wcid)
{
  char *v3; // ecx@3

  if ( op == 1 )
  {
    v3 = (char *)&this->_buy;
  }
  else
  {
    if ( op != 2 )
      return 0;
    v3 = (char *)&this->_rent;
  }
  if ( v3 )
    return HousePaymentList::NeedsMore((HousePaymentList *)v3, wcid);
  return 0;
}

//----- (005BB890) --------------------------------------------------------  // acclient.c:486606
int __thiscall HouseProfile::Pack(HouseProfile *this, void **addr, unsigned int size)
{
  HouseProfile *v3; // edi@1
  char *v4; // esi@1
  char *v5; // ebp@1
  int v6; // ebx@1
  int v7; // ebx@1
  int result; // eax@1
  char *v9; // ecx@2
  char *v10; // eax@2
  char *v11; // edx@2
  char *v12; // ecx@2
  char *v13; // eax@2
  char *v14; // edx@2
  char *v15; // ecx@2
  AC1Legacy::PStringBase<char> *v16; // ecx@2
  char *v17; // eax@2
  unsigned int retval; // [sp+20h] [bp-Ch]@1
  AC1Legacy::PStringBase<char> *v19; // [sp+24h] [bp-8h]@1
  HousePaymentList *v20; // [sp+28h] [bp-4h]@1

  v3 = this;
  v4 = (char *)&this->_buy;
  retval = 0;
  v5 = (char *)&this->_rent;
  v20 = &this->_buy;
  v19 = &this->_name;
  v6 = AC1Legacy::PStringBase<char>::Pack(&this->_name, (void **)&retval, 0);
  v7 = (*(int (__thiscall **)(int, unsigned int *, _DWORD))(*(_DWORD *)v4 + 12))(&v3->_buy, &retval, 0) + v6;
  result = v7 + (*(int (__thiscall **)(int, unsigned int *, _DWORD))(*(_DWORD *)v5 + 12))(&v3->_rent, &retval, 0) + 36;
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_id;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_owner;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->_bitmask;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->_min_level;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->_max_level;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->_min_alleg_rank;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(_DWORD *)v14 = v3->_max_alleg_rank;
    v15 = (char *)*addr + 4;
    *addr = v15;
    *(_DWORD *)v15 = v3->_maintenance_free;
    v16 = v19;
    v17 = (char *)*addr + 4;
    *addr = v17;
    *(_DWORD *)v17 = v3->_type;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(v16, addr, size);
    ((void (__stdcall *)(void **, unsigned int))v20->vfptr->Pack)(addr, size);
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v5 + 12))(&v3->_rent, addr, size);
    result = retval;
  }
  return result;
}

//----- (005BB9A0) --------------------------------------------------------  // acclient.c:486675
int __thiscall HouseProfile::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    v3 = *(_DWORD *)(this + 12);
    if ( v3 != *(_DWORD *)(a2 + 12) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v2 + 12) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    PackableList<HousePayment>::operator=((PackableList<HousePayment> *)(v2 + 20), a2 + 20);
    PackableList<HousePayment>::operator=((PackableList<HousePayment> *)(v2 + 36), a2 + 36);
    *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(v2 + 60) = *(_DWORD *)(a2 + 60);
    *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(v2 + 68) = *(_DWORD *)(a2 + 68);
    *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  }
  return v2;
}

//----- (005BBA40) --------------------------------------------------------  // acclient.c:486709
int __thiscall HouseProfile::UnPack(HouseProfile *this, unsigned int version, void **addr, unsigned int size)
{
  HouseProfile *v4; // edi@1
  unsigned int v5; // eax@1
  int result; // eax@8
  AC1Legacy::PStringBase<char> *v7; // ebp@9
  void *v8; // ebx@9
  char *v9; // ecx@9
  char *v10; // eax@9
  char *v11; // edx@9
  char *v12; // ecx@9
  char *v13; // eax@9
  char *v14; // edx@10
  int v15; // eax@15
  unsigned int v16; // ecx@16
  unsigned int v17; // eax@20
  unsigned int v18; // edx@21
  char *v19; // eax@24
  unsigned int v20; // edi@25
  int v21; // [sp+8h] [bp-4h]@9

  v4 = this;
  v5 = 20;
  if ( version >= 1 )
    v5 = 28;
  if ( version >= 2 )
    v5 += 4;
  if ( version >= 3 )
    v5 += 4;
  if ( size >= v5 )
  {
    v7 = &this->_name;
    this->_id = 0;
    this->_owner = 0;
    this->_bitmask = 0;
    this->_min_level = -1;
    this->_max_level = -1;
    this->_min_alleg_rank = -1;
    this->_max_alleg_rank = -1;
    AC1Legacy::PStringBase<char>::set(&this->_name, &name);
    v4->_maintenance_free = 0;
    v4->_type = 0;
    PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&v4->_buy.vfptr);
    v21 = (int)&v4->_rent;
    PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&v4->_rent.vfptr);
    v8 = *addr;
    v4->_id = *(_DWORD *)*addr;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v4->_owner = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    v4->_bitmask = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    v4->_min_level = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    v4->_max_level = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    if ( version >= 1 )
    {
      v4->_min_alleg_rank = *(_DWORD *)v13;
      v14 = (char *)*addr + 4;
      *addr = v14;
      v4->_max_alleg_rank = *(_DWORD *)v14;
      v13 = (char *)*addr + 4;
      *addr = v13;
    }
    if ( version >= 2 )
    {
      v4->_maintenance_free = *(_DWORD *)v13;
      v13 = (char *)*addr + 4;
      *addr = v13;
    }
    if ( version >= 3 )
    {
      v4->_type = *(_DWORD *)v13;
      v13 = (char *)*addr + 4;
      *addr = v13;
    }
    v15 = v13 - (_BYTE *)v8;
    if ( size <= v15 )
      v16 = 0;
    else
      v16 = size - v15;
    if ( AC1Legacy::PStringBase<char>::UnPack(v7, addr, v16)
      && ((v17 = (_BYTE *)*addr - (_BYTE *)v8, size <= v17) ? (v18 = 0) : (v18 = size - v17),
          ((int (__stdcall *)(void **, unsigned int))v4->_buy.vfptr->UnPack)(addr, v18)) )
    {
      v19 = (char *)((_BYTE *)*addr - (_BYTE *)v8);
      if ( size <= (unsigned int)v19 )
        v20 = 0;
      else
        v20 = size - (_DWORD)v19;
      result = (*(int (__stdcall **)(void **, unsigned int))(*(_DWORD *)v21 + 16))(addr, v20) != 0;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BBBD0) --------------------------------------------------------  // acclient.c:486820
void __thiscall HouseProfile::HouseProfile(HouseProfile *this)
{
  HouseProfile *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&HouseProfile::vftable;
  this->_id = 0;
  this->_owner = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->_bitmask = 0;
  v1->_buy.head = 0;
  v1->_buy.tail = 0;
  v1->_buy.curNum = 0;
  v1->_buy.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  v1->_rent.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  v1->_rent.head = 0;
  v1->_rent.tail = 0;
  v1->_rent.curNum = 0;
  v1->_maintenance_free = 0;
  v1->_type = 0;
  v1->_min_level = -1;
  v1->_max_level = -1;
  v1->_min_alleg_rank = -1;
  v1->_max_alleg_rank = -1;
}
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);
// 7E7468: using guessed type int (__thiscall *HouseProfile::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BBC30) --------------------------------------------------------  // acclient.c:486853
HouseProfile *__thiscall HouseProfile::scalar_deleting_destructor(HouseProfile *this, unsigned int a2)
{
  HouseProfile *v2; // esi@1

  v2 = this;
  HouseProfile::~HouseProfile(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005BBC50) --------------------------------------------------------  // acclient.c:486865
void __thiscall HouseProfile::~HouseProfile(HouseProfile *this)
{
  HouseProfile *v1; // esi@1
  char *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v1 = this;
  v2 = (char *)&this->_rent;
  this->_rent.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&this->_rent.vfptr);
  *(_DWORD *)v2 = &PackObj::vftable;
  v1->_buy.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  PackableList<HousePayment>::Flush((PackableList<HousePayment> *)&v1->_buy.vfptr);
  v1->_buy.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);

//----- (005BBCB0) --------------------------------------------------------  // acclient.c:486888
void __thiscall HouseProfile::HouseProfile(HouseProfile *this, HouseProfile *rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&HouseProfile::vftable;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  *(_DWORD *)(v2 + 20) = &HousePaymentList::vftable;
  *(_DWORD *)(v2 + 36) = &HousePaymentList::vftable;
  *(_DWORD *)(v2 + 40) = 0;
  *(_DWORD *)(v2 + 44) = 0;
  *(_DWORD *)(v2 + 48) = 0;
  HouseProfile::operator=(v2, (int)rhs);
}
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);
// 7E7468: using guessed type int (__thiscall *HouseProfile::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BBD00) --------------------------------------------------------  // acclient.c:486913
int __thiscall HouseProfile::UnPack(HouseProfile *this, void **addr, unsigned int size)
{
  return HouseProfile::UnPack(this, 3u, addr, size);
}

//----- (0070E940) --------------------------------------------------------  // acclient.c:801573
void sub_70E940()
{
  flt_8EF4C8 = 1000.0 + 1.0;
}

//----- (0070E960) --------------------------------------------------------  // acclient.c:801579
void sub_70E960()
{
  flt_8EF4CC = 24.0 * 8.0;
}

//----- (0070E980) --------------------------------------------------------  // acclient.c:801585
void sub_70E980()
{
  flt_8EF4D0 = 24.0 * 0.5;
}

//----- (0070E9A0) --------------------------------------------------------  // acclient.c:801591
int sub_70E9A0()
{
  return atexit(nullsub_1557);
}

