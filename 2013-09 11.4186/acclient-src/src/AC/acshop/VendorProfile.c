/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : VendorProfile
   Object     : AC\acshop\VendorProfile.obj
   Functions  : 11
   Addresses  : 005D1A90 - 007104A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D1A90) --------------------------------------------------------  // acclient.c:509816
int __thiscall VendorProfile::InqAcceptability(VendorProfile *this, PublicWeenieDesc *_item)
{
  unsigned int v2; // edi@1
  int result; // eax@1
  unsigned int v4; // eax@3
  unsigned int v5; // esi@3
  int v6; // edx@7
  int v7; // ecx@10

  v2 = _item->_type;
  result = 1;
  if ( this->item_types & v2 && !(BYTE3(_item->_bitfield) & 1) )
  {
    v4 = _item->_value;
    v5 = _item->_stackSize;
    if ( v5 )
      v4 /= v5;
    if ( v4 )
    {
      v6 = this->max_value;
      if ( v6 == -1 || (signed int)v4 <= v6 )
      {
        v7 = this->min_value;
        if ( v7 == -1 || (signed int)v4 >= v7 )
          result = 0;
        else
          result = 3;
      }
      else
      {
        result = ~(unsigned __int8)(v2 >> 16) & 4;
      }
    }
    else
    {
      result = 2;
    }
  }
  return result;
}

//----- (005D1B00) --------------------------------------------------------  // acclient.c:509858
int __thiscall VendorProfile::VendorSellPrice(VendorProfile *this, PublicWeenieDesc *_item, unsigned int _subAmount)
{
  ITEM_TYPE v3; // edx@1
  float v4; // ecx@1
  unsigned int v5; // esi@1
  int v6; // eax@1
  int result; // eax@2

  v3 = _item->_type;
  v4 = this->sell_price;
  v5 = _item->_stackSize;
  v6 = _item->_value;
  if ( v5 )
    result = ShopSystem::SellPrice(v6 / v5, v3, v4, _subAmount);
  else
    result = ShopSystem::SellPrice(v6, v3, v4, _subAmount);
  return result;
}

//----- (005D1B50) --------------------------------------------------------  // acclient.c:509878
BOOL __thiscall VendorProfile::IsAcceptable(VendorProfile *this, PublicWeenieDesc *_item)
{
  return VendorProfile::InqAcceptability(this, _item) == 0;
}

//----- (005D1B70) --------------------------------------------------------  // acclient.c:509884
int __thiscall VendorProfile::VendorBuyPrice(VendorProfile *this, PublicWeenieDesc *_vendor, PublicWeenieDesc *_item)
{
  VendorProfile *v3; // edi@1
  int result; // eax@2
  int v5; // ecx@3

  v3 = this;
  if ( VendorProfile::InqAcceptability(this, _item) )
  {
    result = 0;
  }
  else
  {
    v5 = _item->_stackSize;
    if ( v5 )
      result = ShopSystem::BuyPrice(_item->_value / v5, _item->_type, v3->buy_price, v5);
    else
      result = ShopSystem::BuyPrice(_item->_value, _item->_type, v3->buy_price, 1);
  }
  return result;
}

//----- (005D1BD0) --------------------------------------------------------  // acclient.c:509907
IDClass<_tagDataID,32,0> *__thiscall VendorProfile::VendorTradeCurrency(VendorProfile *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->trade_id.id;
  return v2;
}

//----- (005D1BE0) --------------------------------------------------------  // acclient.c:509917
void __thiscall VendorProfile::VendorProfile(VendorProfile *this)
{
  VendorProfile *v1; // esi@1
  unsigned int v2; // ecx@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->item_types = 0;
  this->magic = 0;
  this->vfptr = (PackObjVtbl *)&VendorProfile::vftable;
  this->min_value = -1;
  this->max_value = -1;
  LODWORD(this->buy_price) = 1063675494;
  LODWORD(this->sell_price) = 1066192077;
  v2 = stru_8EFFD4.id;
  v1->trade_num = 0;
  v1->trade_id.id = v2;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->trade_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
}
// 7E8970: using guessed type int (__thiscall *VendorProfile::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D1C30) --------------------------------------------------------  // acclient.c:509942
VendorProfile *__thiscall VendorProfile::scalar_deleting_destructor(VendorProfile *this, unsigned int a2)
{
  VendorProfile *v2; // esi@1

  v2 = this;
  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&this->trade_name);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005D1C60) --------------------------------------------------------  // acclient.c:509956
int __thiscall VendorProfile::GetPackSize(VendorProfile *this)
{
  void *mem; // [sp+0h] [bp-4h]@1

  mem = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->trade_name, &mem, 0) + 32;
}

//----- (005D1C80) --------------------------------------------------------  // acclient.c:509965
unsigned int __thiscall VendorProfile::Pack(VendorProfile *this, void **addr, unsigned int size)
{
  VendorProfile *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // ebx@2
  char *v6; // ecx@2
  char *v7; // ebx@2
  char *v8; // ecx@2
  char *v9; // ebx@2
  char *v10; // ecx@2
  char *v11; // ebx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->item_types;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->min_value;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->max_value;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->magic;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(float *)v8 = v3->buy_price;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(float *)v9 = v3->sell_price;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->trade_id.id;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->trade_num;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->trade_name, addr, size);
  }
  return v4;
}

//----- (005D1D20) --------------------------------------------------------  // acclient.c:510010
int __thiscall VendorProfile::UnPack(VendorProfile *this, void **addr, unsigned int size)
{
  VendorProfile *v3; // esi@1
  int result; // eax@2
  char *v5; // ecx@3
  char *v6; // edx@3
  char *v7; // ecx@3
  char *v8; // edx@3
  char *v9; // ecx@3
  char *v10; // edx@3
  char *v11; // ecx@3
  unsigned int v12; // edx@3

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    v3->item_types = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v3->min_value = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->max_value = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    v3->magic = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(v3->buy_price) = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LODWORD(v3->sell_price) = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    v11 = v10;
    v12 = *(_DWORD *)v10;
    *addr = v11 + 4;
    v3->trade_id.id = v12;
    v3->trade_num = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::UnPack(&v3->trade_name, addr, size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (007104A0) --------------------------------------------------------  // acclient.c:803561
int sub_7104A0()
{
  return atexit(nullsub_1846);
}

