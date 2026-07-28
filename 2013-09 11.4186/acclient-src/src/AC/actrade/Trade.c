/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Trade
   Object     : AC\actrade\Trade.obj
   Functions  : 18
   Addresses  : 005B9EF0 - 005BA5B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B9EF0) --------------------------------------------------------  // acclient.c:484827
int __thiscall Trade::Register(Trade *this, unsigned int partner, long double stamp)
{
  int result; // eax@2

  if ( partner )
  {
    this->_partner = partner;
    this->_stamp = stamp;
    this->_status = 2;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B9F20) --------------------------------------------------------  // acclient.c:484846
int __thiscall Trade::GetPackSize(Trade *this)
{
  PackObjVtbl *v1; // eax@1
  char *v2; // esi@1
  int v3; // edi@1
  void *addr; // [sp+8h] [bp-4h]@1

  addr = this;
  v1 = this->_self_list.vfptr;
  v2 = (char *)&this->_partner_list;
  addr = 0;
  v3 = ((int (__thiscall *)(PackableList<ContentProfile> *, void **, _DWORD))v1->Pack)(&this->_self_list, &addr, 0);
  return v3 + (*(int (__thiscall **)(char *, void **, _DWORD))(*(_DWORD *)v2 + 12))(v2, &addr, 0) + 28;
}

//----- (005B9F60) --------------------------------------------------------  // acclient.c:484862
int __thiscall PackableList<ContentProfile>::Search(PackableList<ContentProfile> *this, ContentProfile *val)
{
  PackableLLNode<ContentProfile> *v2; // esi@1
  int result; // eax@4

  v2 = this->head;
  if ( v2 )
  {
    while ( !ContentProfile::operator==((Enchantment *)v2, (Enchantment *)val) )
    {
      v2 = v2->next;
      if ( !v2 )
        goto LABEL_4;
    }
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (005B9FA0) --------------------------------------------------------  // acclient.c:484887
int __thiscall Trade::IsPartnerTradingItem(Trade *this, unsigned int item)
{
  Trade *v2; // esi@1
  PackableLLNode<ContentProfile> *v3; // esi@1
  int result; // eax@4
  ContentProfile v5; // [sp+4h] [bp-Ch]@1

  v2 = this;
  ContentProfile::ContentProfile(&v5, item);
  v3 = v2->_partner_list.head;
  if ( v3 )
  {
    while ( !ContentProfile::operator==((Enchantment *)v3, (Enchantment *)&v5) )
    {
      v3 = v3->next;
      if ( !v3 )
        goto LABEL_4;
    }
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (005B9FF0) --------------------------------------------------------  // acclient.c:484916
unsigned int __thiscall Trade::Pack(Trade *this, void **addr, unsigned int size)
{
  Trade *v3; // edi@1
  unsigned int v4; // ebp@1
  char *v5; // edx@2
  char *v6; // ecx@2
  char *v7; // eax@2
  char *v8; // edx@2
  char *v9; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->_partner;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(double *)v5 = v3->_stamp;
    v6 = (char *)*addr + 8;
    *addr = v6;
    *(_DWORD *)v6 = v3->_status;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_initiator;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_accepted;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_p_accepted;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->_self_list.vfptr->Pack)(addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->_partner_list.vfptr->Pack)(&v3->_partner_list, addr, size);
  }
  return v4;
}

//----- (005BA080) --------------------------------------------------------  // acclient.c:484954
unsigned int __thiscall Trade::GetNumItems(Trade *this)
{
  PackableLLNode<ContentProfile> *v1; // ecx@1
  unsigned int result; // eax@1

  v1 = this->_self_list.head;
  for ( result = 0; v1; v1 = v1->next )
  {
    if ( !v1->data.m_uContainerProperties )
      ++result;
  }
  return result;
}

//----- (005BA0A0) --------------------------------------------------------  // acclient.c:484969
unsigned int __thiscall Trade::GetNumContainers(Trade *this)
{
  PackableLLNode<ContentProfile> *v1; // ecx@1
  unsigned int result; // eax@1

  v1 = this->_self_list.head;
  for ( result = 0; v1; v1 = v1->next )
  {
    if ( v1->data.m_uContainerProperties )
      ++result;
  }
  return result;
}

//----- (005BA0C0) --------------------------------------------------------  // acclient.c:484984
unsigned int __thiscall Trade::GetNumPartnerItems(Trade *this)
{
  PackableLLNode<ContentProfile> *v1; // ecx@1
  unsigned int result; // eax@1

  v1 = this->_partner_list.head;
  for ( result = 0; v1; v1 = v1->next )
  {
    if ( !v1->data.m_uContainerProperties )
      ++result;
  }
  return result;
}

//----- (005BA0E0) --------------------------------------------------------  // acclient.c:484999
unsigned int __thiscall Trade::GetNumPartnerContainers(Trade *this)
{
  PackableLLNode<ContentProfile> *v1; // ecx@1
  unsigned int result; // eax@1

  v1 = this->_partner_list.head;
  for ( result = 0; v1; v1 = v1->next )
  {
    if ( v1->data.m_uContainerProperties )
      ++result;
  }
  return result;
}

//----- (005BA100) --------------------------------------------------------  // acclient.c:485014
unsigned int __thiscall PackableList<ContentProfile>::InsertPos(PackableList<ContentProfile> *this, const unsigned int pos, ContentProfile *val)
{
  PackableList<ContentProfile> *v3; // esi@1
  const unsigned int v4; // ebx@1
  void *v5; // eax@1
  PackableLLNode<ContentProfile> *v6; // ecx@4
  const unsigned int result; // eax@5
  PackableLLNode<ContentProfile> *v8; // ecx@10
  PackableLLNode<ContentProfile> *v9; // edx@11

  v3 = this;
  v4 = pos;
  v5 = operator new(0x14u);
  if ( v5 )
  {
    *(_DWORD *)v5 = &ContentProfile::vftable;
    *((_DWORD *)v5 + 1) = val->m_iid;
    *((_DWORD *)v5 + 2) = val->m_uContainerProperties;
    *((_DWORD *)v5 + 3) = 0;
    *((_DWORD *)v5 + 4) = 0;
  }
  else
  {
    v5 = 0;
  }
  v6 = v3->head;
  if ( !v6 )
  {
    v3->head = (PackableLLNode<ContentProfile> *)v5;
    v3->tail = (PackableLLNode<ContentProfile> *)v5;
    ++v3->curNum;
    return 0;
  }
  if ( pos )
  {
    while ( v6 )
    {
      --v4;
      v6 = v6->next;
      if ( !v4 )
        goto LABEL_9;
    }
    goto LABEL_10;
  }
LABEL_9:
  if ( !v6 )
  {
LABEL_10:
    v8 = v3->tail;
    v8->next = (PackableLLNode<ContentProfile> *)v5;
    *((_DWORD *)v5 + 4) = v8;
    v3->tail = (PackableLLNode<ContentProfile> *)v5;
    result = v3->curNum;
    v3->curNum = result + 1;
    return result;
  }
  v9 = v6->prev;
  if ( v9 )
    v9->next = (PackableLLNode<ContentProfile> *)v5;
  else
    v3->head = (PackableLLNode<ContentProfile> *)v5;
  *((_DWORD *)v5 + 4) = v6->prev;
  *((_DWORD *)v5 + 3) = v6;
  v6->prev = (PackableLLNode<ContentProfile> *)v5;
  ++v3->curNum;
  return pos;
}
// 7CC40C: using guessed type int (__thiscall *ContentProfile::vftable)(void *, char);

//----- (005BA1B0) --------------------------------------------------------  // acclient.c:485084
int __stdcall Trade::AddItem(unsigned int item, PackableList<ContentProfile> *list, unsigned int loc)
{
  int result; // eax@4
  ContentProfile val; // [sp+8h] [bp-Ch]@2

  if ( !item
    || (ContentProfile::ContentProfile(&val, item), PackableList<ContentProfile>::Search(list, &val))
    || list->curNum >= 0x1A0A )
  {
    result = 0;
  }
  else
  {
    ContentProfile::ContentProfile(&val, item);
    PackableList<ContentProfile>::InsertPos(list, loc, &val);
    result = 1;
  }
  return result;
}

//----- (005BA220) --------------------------------------------------------  // acclient.c:485105
int __thiscall PackableList<ContentProfile>::Remove(PackableList<ContentProfile> *this, ContentProfile *val)
{
  PackableList<ContentProfile> *v2; // ebx@1
  PackableLLNode<ContentProfile> *v3; // ecx@1
  int result; // eax@2
  PackableLLNode<ContentProfile> *v5; // esi@3
  PackableLLNode<ContentProfile> *v6; // eax@4
  PackableLLNode<ContentProfile> *v7; // eax@4
  PackableLLNode<ContentProfile> *v8; // eax@14
  PackableLLNode<ContentProfile> *v9; // ecx@14
  PackableLLNode<ContentProfile> *v10; // eax@14

  v2 = this;
  v3 = this->head;
  if ( v3 )
  {
    v5 = v3;
    if ( ContentProfile::operator==((Enchantment *)v3, (Enchantment *)val) )
    {
      v6 = v2->head;
      val->m_iid = v6->data.m_iid;
      val->m_uContainerProperties = v6->data.m_uContainerProperties;
      v7 = v2->head->next;
      v2->head = v7;
      if ( v7 )
        v7->prev = 0;
      else
        v2->tail = 0;
      if ( v5 )
      {
        v5->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
        operator delete(v5);
      }
      --v2->curNum;
      result = 1;
    }
    else if ( v5->next )
    {
      while ( !ContentProfile::operator==((Enchantment *)v5->next, (Enchantment *)val) )
      {
        v5 = v5->next;
        if ( !v5->next )
          goto LABEL_13;
      }
      v8 = v5->next;
      val->m_iid = v8->data.m_iid;
      val->m_uContainerProperties = v8->data.m_uContainerProperties;
      v9 = v5->next;
      v10 = v9->next;
      v5->next = v10;
      if ( v10 )
        v10->prev = v5;
      else
        v2->tail = v5;
      v9->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
      operator delete(v9);
      --v2->curNum;
      result = 1;
    }
    else
    {
LABEL_13:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005BA310) --------------------------------------------------------  // acclient.c:485179
int __thiscall Trade::AddItem(Trade *this, unsigned int item, unsigned int id, unsigned int loc)
{
  Trade *v4; // esi@1
  unsigned int v6; // edi@4
  int v7; // eax@4
  int v8; // edx@5
  int v9; // eax@6
  ContentProfile val; // [sp+8h] [bp-18h]@4
  ContentProfile v11; // [sp+14h] [bp-Ch]@6

  v4 = this;
  if ( id == 1 )
  {
    v6 = item;
    ContentProfile::ContentProfile(&v11, item);
    v9 = PackableList<ContentProfile>::Search(&v4->_partner_list, &v11);
    v11.vfptr = (PackObjVtbl *)&PackObj::vftable;
    if ( !v9 )
    {
      v8 = (int)&v4->_self_list;
      return Trade::AddItem(v6, (PackableList<ContentProfile> *)v8, loc);
    }
    return 0;
  }
  if ( id != 2 )
    return 0;
  v6 = item;
  ContentProfile::ContentProfile(&val, item);
  v7 = PackableList<ContentProfile>::Search(&v4->_self_list, &val);
  val.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( v7 )
    return 0;
  v8 = (int)&v4->_partner_list;
  return Trade::AddItem(v6, (PackableList<ContentProfile> *)v8, loc);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005BA3A0) --------------------------------------------------------  // acclient.c:485217
int __thiscall Trade::RemoveItem(Trade *this, unsigned int item, unsigned int id)
{
  Trade *v3; // esi@1
  ContentProfile val; // [sp+4h] [bp-24h]@4
  ContentProfile v6; // [sp+10h] [bp-18h]@4
  ContentProfile v7; // [sp+1Ch] [bp-Ch]@5

  v3 = this;
  if ( item )
  {
    if ( id == 1 )
    {
      ContentProfile::ContentProfile(&v7, item);
      val.m_uContainerProperties = v7.m_uContainerProperties;
      val.vfptr = (PackObjVtbl *)&ContentProfile::vftable;
      val.m_iid = v7.m_iid;
      return PackableList<ContentProfile>::Remove(&v3->_self_list, &val);
    }
    if ( id == 2 )
    {
      ContentProfile::ContentProfile(&v6, item);
      val.m_uContainerProperties = v6.m_uContainerProperties;
      val.vfptr = (PackObjVtbl *)&ContentProfile::vftable;
      val.m_iid = v6.m_iid;
      return PackableList<ContentProfile>::Remove(&v3->_partner_list, &val);
    }
  }
  return 0;
}
// 7CC40C: using guessed type int (__thiscall *ContentProfile::vftable)(void *, char);

//----- (005BA430) --------------------------------------------------------  // acclient.c:485249
int __thiscall Trade::Reset(Trade *this)
{
  Trade *v1; // esi@1

  v1 = this;
  PackableList<ContentProfile>::Flush(&this->_self_list);
  PackableList<ContentProfile>::Flush(&v1->_partner_list);
  v1->_accepted = 0;
  v1->_p_accepted = 0;
  return 1;
}

//----- (005BA460) --------------------------------------------------------  // acclient.c:485262
int __thiscall Trade::UnPack(Trade *this, void **addr, unsigned int size)
{
  Trade *v3; // edi@1
  int result; // eax@2
  char *v5; // ebp@3
  unsigned int v6; // ecx@3
  void *v7; // ebx@3
  char *v8; // edx@3
  char *v9; // eax@3
  char *v10; // edx@3
  char *v11; // eax@3
  char *v12; // edx@3
  char *v13; // eax@3
  int v14; // eax@3
  char *v15; // eax@6
  unsigned int v16; // edi@7
  int v17; // [sp+8h] [bp-4h]@3

  v3 = this;
  if ( size >= 0x1C )
  {
    v5 = (char *)&this->_self_list;
    PackableList<ContentProfile>::Flush(&this->_self_list);
    v17 = (int)&v3->_partner_list;
    PackableList<ContentProfile>::Flush(&v3->_partner_list);
    v3->_stamp = dbl_7E72C8;
    v6 = 0;
    v3->_partner = 0;
    v3->_status = 0;
    v3->_initiator = 0;
    v3->_accepted = 0;
    v3->_p_accepted = 0;
    v7 = *addr;
    v3->_partner = *(_DWORD *)*addr;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(v3->_stamp) = *(_DWORD *)v8;
    HIDWORD(v3->_stamp) = *((_DWORD *)v8 + 1);
    v9 = (char *)*addr + 8;
    *addr = v9;
    v3->_status = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    v3->_initiator = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    v3->_accepted = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    v3->_p_accepted = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    v14 = v13 - (_BYTE *)v7;
    if ( size > v14 )
      v6 = size - v14;
    result = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 16))(v5, addr, v6);
    if ( result )
    {
      v15 = (char *)((_BYTE *)*addr - (_BYTE *)v7);
      if ( size <= (unsigned int)v15 )
        v16 = 0;
      else
        v16 = size - (_DWORD)v15;
      result = (*(int (__stdcall **)(void **, unsigned int))(*(_DWORD *)v17 + 16))(addr, v16) != 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BA560) --------------------------------------------------------  // acclient.c:485336
void __thiscall Trade::Trade(Trade *this)
{
  this->vfptr = (PackObjVtbl *)&Trade::vftable;
  this->_self_list.head = 0;
  this->_self_list.tail = 0;
  this->_self_list.curNum = 0;
  this->_self_list.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  this->_partner_list.vfptr = (PackObjVtbl *)&PackableList<ContentProfile>::vftable;
  this->_partner_list.head = 0;
  this->_partner_list.tail = 0;
  this->_partner_list.curNum = 0;
  HIDWORD(this->_stamp) = HIDWORD(dbl_7E72C8);
  this->_partner = 0;
  LODWORD(this->_stamp) = LODWORD(dbl_7E72C8);
  this->_status = 0;
  this->_initiator = 0;
  this->_accepted = 0;
  this->_p_accepted = 0;
}
// 7CC3F8: using guessed type int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char);
// 7E72D0: using guessed type int (__thiscall *Trade::vftable)(void *, char);

//----- (005BA5B0) --------------------------------------------------------  // acclient.c:485359
Trade *__thiscall Trade::vector_deleting_destructor(Trade *this, unsigned int a2)
{
  Trade *v2; // esi@1

  v2 = this;
  PackableList<ContentProfile>::~PackableList<ContentProfile>(&this->_partner_list);
  PackableList<ContentProfile>::~PackableList<ContentProfile>(&v2->_self_list);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

