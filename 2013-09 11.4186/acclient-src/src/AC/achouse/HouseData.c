/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HouseData
   Object     : AC\achouse\HouseData.obj
   Functions  : 11
   Addresses  : 005BB460 - 0070E930 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BB460) --------------------------------------------------------  // acclient.c:486269
int __thiscall HouseData::GetPackSize(HouseData *this)
{
  char *v1; // esi@1
  char *v2; // edi@1
  PackObjVtbl *v3; // eax@1
  int v4; // ebx@1
  int v5; // ebx@1
  void *addr; // [sp+10h] [bp-4h]@1

  addr = this;
  v1 = (char *)&this->m_pos;
  v2 = (char *)&this->m_buy;
  v3 = this->m_rent.vfptr;
  addr = 0;
  v4 = ((int (__stdcall *)(void **, _DWORD))v3->Pack)(&addr, 0);
  v5 = (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v2 + 12))(v2, &addr, 0) + v4;
  return v5 + (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v1 + 12))(v1, &addr, 0) + 16;
}

//----- (005BB4B0) --------------------------------------------------------  // acclient.c:486289
unsigned int __thiscall HouseData::Pack(HouseData *this, void **addr, unsigned int size)
{
  HouseData *v3; // edi@1
  unsigned int v4; // ebp@1
  char *v5; // ecx@2
  char *v6; // eax@2
  char *v7; // edx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->m_buy_time;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->m_rent_time;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->m_type;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->m_maintenance_free;
    *addr = (char *)*addr + 4;
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_buy.vfptr->Pack)(&v3->m_buy, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_rent.vfptr->Pack)(&v3->m_rent, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_pos.vfptr->Pack)(&v3->m_pos, addr, size);
  }
  return v4;
}

//----- (005BB530) --------------------------------------------------------  // acclient.c:486320
int __thiscall HouseData::UnPack(HouseData *this, void **addr, unsigned int size)
{
  HouseData *v3; // edi@1
  int result; // eax@2
  void *v5; // ebx@3
  char *v6; // eax@3
  char *v7; // edx@3
  char *v8; // ecx@3
  char *v9; // eax@3
  int v10; // eax@3
  unsigned int v11; // edx@4
  unsigned int v12; // eax@8
  unsigned int v13; // edx@9
  char *v14; // eax@12
  unsigned int v15; // ebp@13

  v3 = this;
  if ( size >= 0x10 )
  {
    v5 = *addr;
    this->m_buy_time = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->m_rent_time = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->m_type = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    v3->m_maintenance_free = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v10 = v9 - (_BYTE *)v5;
    if ( size <= v10 )
      v11 = 0;
    else
      v11 = size - v10;
    if ( ((int (__thiscall *)(int, void **, unsigned int))v3->m_buy.vfptr->UnPack)(&v3->m_buy, addr, v11)
      && ((v12 = (_BYTE *)*addr - (_BYTE *)v5, size <= v12) ? (v13 = 0) : (v13 = size - v12),
          ((int (__thiscall *)(int, void **, unsigned int))v3->m_rent.vfptr->UnPack)(&v3->m_rent, addr, v13)) )
    {
      v14 = (char *)((_BYTE *)*addr - (_BYTE *)v5);
      if ( size <= (unsigned int)v14 )
        v15 = 0;
      else
        v15 = size - (_DWORD)v14;
      result = ((int (__thiscall *)(int, void **, unsigned int))v3->m_pos.vfptr->UnPack)(&v3->m_pos, addr, v15) != 0;
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

//----- (005BB5F0) --------------------------------------------------------  // acclient.c:486381
void __thiscall HouseData::HouseData(HouseData *this)
{
  HouseData *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&HouseData::vftable;
  v2 = (char *)&this->m_pos.frame;
  v1->m_buy_time = 0;
  v1->m_rent_time = 0;
  v1->m_buy.head = 0;
  v1->m_buy.tail = 0;
  v1->m_buy.curNum = 0;
  v1->m_buy.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  v1->m_rent.head = 0;
  v1->m_rent.tail = 0;
  v1->m_rent.curNum = 0;
  v1->m_rent.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  v1->m_pos.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->m_pos.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->m_type = 0;
  v1->m_maintenance_free = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);
// 7E741C: using guessed type int (__thiscall *HouseData::vftable)(void *, char);

//----- (005BB660) --------------------------------------------------------  // acclient.c:486417
HouseData *__thiscall HouseData::vector_deleting_destructor(HouseData *this, unsigned int a2)
{
  HouseData *v2; // esi@1

  v2 = this;
  this->m_pos.vfptr = (PackObjVtbl *)&PackObj::vftable;
  HousePaymentList::~HousePaymentList(&this->m_rent);
  HousePaymentList::~HousePaymentList(&v2->m_buy);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005BB6A0) --------------------------------------------------------  // acclient.c:486433
int __thiscall HouseData::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    PackableList<HousePayment>::operator=((PackableList<HousePayment> *)(this + 12), a2 + 12);
    PackableList<HousePayment>::operator=((PackableList<HousePayment> *)(v2 + 28), a2 + 28);
    *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 48);
    Frame::operator=(v2 + 52, a2 + 52);
    *(_DWORD *)(v2 + 116) = *(_DWORD *)(a2 + 116);
    *(_DWORD *)(v2 + 120) = *(_DWORD *)(a2 + 120);
  }
  return v2;
}

//----- (005BB700) --------------------------------------------------------  // acclient.c:486453
void __thiscall HouseData::HouseData(HouseData *this, HouseData *rhs)
{
  int v2; // esi@1
  char *v3; // ecx@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&HouseData::vftable;
  this->m_buy.head = 0;
  this->m_buy.tail = 0;
  this->m_buy.curNum = 0;
  this->m_buy.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  this->m_rent.vfptr = (PackObjVtbl *)&HousePaymentList::vftable;
  this->m_rent.head = 0;
  this->m_rent.tail = 0;
  this->m_rent.curNum = 0;
  v3 = (char *)&this->m_pos.frame;
  *(_DWORD *)(v2 + 44) = &Position::vftable;
  *(_DWORD *)(v2 + 48) = 0;
  *(_DWORD *)v3 = 1065353216;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 13) = 0;
  *((_DWORD *)v3 + 14) = 0;
  *((_DWORD *)v3 + 15) = 0;
  Frame::cache((Frame *)v3);
  HouseData::operator=(v2, (int)rhs);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E72E4: using guessed type int (__thiscall *HousePaymentList::vftable)(void *, char);
// 7E741C: using guessed type int (__thiscall *HouseData::vftable)(void *, char);

//----- (0070E8D0) --------------------------------------------------------  // acclient.c:801549
void sub_70E8D0()
{
  flt_8EF4A8 = 1000.0 + 1.0;
}

//----- (0070E8F0) --------------------------------------------------------  // acclient.c:801555
void sub_70E8F0()
{
  flt_8EF4AC = 24.0 * 8.0;
}

//----- (0070E910) --------------------------------------------------------  // acclient.c:801561
void sub_70E910()
{
  flt_8EF4B0 = 24.0 * 0.5;
}

//----- (0070E930) --------------------------------------------------------  // acclient.c:801567
int sub_70E930()
{
  return atexit(nullsub_1560);
}

