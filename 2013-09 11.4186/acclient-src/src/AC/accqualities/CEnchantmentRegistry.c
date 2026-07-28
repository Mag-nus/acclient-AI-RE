/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEnchantmentRegistry
   Object     : AC\accqualities\CEnchantmentRegistry.obj
   Functions  : 41
   Addresses  : 00593970 - 0070ABE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00593970) --------------------------------------------------------  // acclient.c:444938
int __thiscall CEnchantmentRegistry::InqVitae(CEnchantmentRegistry *this, Enchantment *vitae)
{
  int result; // eax@1

  result = (int)this->_vitae;
  if ( result )
  {
    Enchantment::operator=((int)vitae, result);
    result = 1;
  }
  return result;
}

//----- (00593990) --------------------------------------------------------  // acclient.c:444952
double __thiscall CEnchantmentRegistry::GetVitaeValue(CEnchantmentRegistry *this)
{
  Enchantment *v1; // eax@1
  double result; // st7@2

  v1 = this->_vitae;
  if ( v1 )
    result = v1->_smod.val;
  else
    result = 1.0;
  return result;
}

//----- (005939B0) --------------------------------------------------------  // acclient.c:444966
void __thiscall CEnchantmentRegistry::CEnchantmentRegistry(CEnchantmentRegistry *this)
{
  this->vfptr = (PackObjVtbl *)&CEnchantmentRegistry::vftable;
  this->_mult_list = 0;
  this->_add_list = 0;
  this->_cooldown_list = 0;
  this->_vitae = 0;
  this->m_cHelpfulEnchantments = 0;
  this->m_cHarmfulEnchantments = 0;
}
// 7E4668: using guessed type int (__thiscall *CEnchantmentRegistry::vftable)(void *, char);

//----- (005939D0) --------------------------------------------------------  // acclient.c:444979
void __thiscall CEnchantmentRegistry::Clear(CEnchantmentRegistry *this)
{
  CEnchantmentRegistry *v1; // esi@1
  Enchantment *v2; // ecx@1
  PackableList<Enchantment> *v3; // ecx@3
  PackableList<Enchantment> *v4; // ecx@5
  PackableList<Enchantment> *v5; // ecx@7

  v1 = this;
  v2 = this->_vitae;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_vitae = 0;
  }
  v3 = v1->_mult_list;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->_mult_list = 0;
  }
  v4 = v1->_add_list;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->_add_list = 0;
  }
  v5 = v1->_cooldown_list;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->_cooldown_list = 0;
  }
  v1->m_cHelpfulEnchantments = 0;
  v1->m_cHarmfulEnchantments = 0;
}

//----- (00593A20) --------------------------------------------------------  // acclient.c:445017
int __thiscall CEnchantmentRegistry::UpdateVitae(CEnchantmentRegistry *this, Enchantment *vitae)
{
  CEnchantmentRegistry *v2; // esi@1
  Enchantment *v3; // eax@3
  Enchantment *v4; // eax@4
  int result; // eax@7

  v2 = this;
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & vitae->_smod.type
    && (this->_vitae
     || ((v3 = (Enchantment *)operator new(0x50u)) == 0 ? (v4 = 0) : Enchantment::Enchantment(v3, vitae),
         (v2->_vitae = v4) != 0)) )
  {
    Enchantment::operator=((int)v2->_vitae, (int)vitae);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00593A80) --------------------------------------------------------  // acclient.c:445041
int __thiscall CEnchantmentRegistry::Pack(CEnchantmentRegistry *this, void **addr, unsigned int size)
{
  CEnchantmentRegistry *v3; // edi@1
  int v4; // ebp@1
  signed int v5; // eax@2
  PackableList<Enchantment> *v6; // ecx@10
  PackableList<Enchantment> *v7; // ecx@12
  PackableList<Enchantment> *v8; // ecx@14
  Enchantment *v9; // ecx@16

  v3 = this;
  v4 = CEnchantmentRegistry::pack_size((GenericQualitiesData *)this);
  if ( size >= v4 )
  {
    v5 = 0;
    if ( v3->_mult_list )
      v5 = 1;
    if ( v3->_add_list )
      v5 |= 2u;
    if ( v3->_cooldown_list )
      v5 |= 8u;
    if ( v3->_vitae )
      v5 |= 4u;
    *(_DWORD *)*addr = v5;
    *addr = (char *)*addr + 4;
    v6 = v3->_mult_list;
    if ( v6 )
      ((void (__stdcall *)(void **, unsigned int))v6->vfptr->Pack)(addr, size);
    v7 = v3->_add_list;
    if ( v7 )
      ((void (__stdcall *)(void **, unsigned int))v7->vfptr->Pack)(addr, size);
    v8 = v3->_cooldown_list;
    if ( v8 )
      ((void (__stdcall *)(void **, unsigned int))v8->vfptr->Pack)(addr, size);
    v9 = v3->_vitae;
    if ( v9 )
      ((void (__stdcall *)(void **, unsigned int))v9->vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (00593B10) --------------------------------------------------------  // acclient.c:445083
CSpellBase *__thiscall CSpellTable::GetSpellBase(CSpellTable *this, const unsigned int key)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,CSpellBase> **v3; // ecx@2
  PackableHashData<unsigned long,CSpellBase> *v4; // edx@3
  CSpellBase *result; // eax@6

  v2 = this->_spellBaseHash._table_size;
  if ( v2 && (v3 = this->_spellBaseHash._buckets) != 0 && (v4 = v3[key % v2]) != 0 )
  {
    while ( key != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00593B50) --------------------------------------------------------  // acclient.c:445110
int __stdcall CEnchantmentRegistry::Enchant(PackableList<Enchantment> *affecting, float *val)
{
  PackableLLNode<Enchantment> *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@3

  v3 = affecting->head;
  v4 = 0;
  while ( v3 )
  {
    v5 = Enchantment::Enchant(&v3->data, val);
    v3 = v3->next;
    v4 |= v5;
  }
  return v4;
}

//----- (00593B80) --------------------------------------------------------  // acclient.c:445128
int __stdcall CEnchantmentRegistry::Enchant(PackableList<Enchantment> *affecting, EnchantedQualityDetails *val)
{
  PackableLLNode<Enchantment> *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@3

  v3 = affecting->head;
  v4 = 0;
  while ( v3 )
  {
    v5 = Enchantment::Enchant(&v3->data, val);
    v3 = v3->next;
    v4 |= v5;
  }
  return v4;
}

//----- (00593BB0) --------------------------------------------------------  // acclient.c:445146
PackableList<Enchantment> *__stdcall CEnchantmentRegistry::ReplaceEnchantmentInList(Enchantment *new_guy, PackableList<Enchantment> *list)
{
  PackableList<Enchantment> *result; // eax@1
  PackableList<Enchantment> *v4; // ebx@1
  int v5; // esi@2

  result = list;
  v4 = 0;
  if ( list )
  {
    v5 = (int)list->head;
    while ( v5 )
    {
      if ( ContentProfile::operator==((Enchantment *)v5, new_guy) )
      {
        Enchantment::operator=(v5, (int)new_guy);
        v5 = *(_DWORD *)(v5 + 80);
        v4 = (PackableList<Enchantment> *)((unsigned int)v4 | 1);
      }
      else
      {
        v5 = *(_DWORD *)(v5 + 80);
      }
    }
    result = v4;
  }
  return result;
}

//----- (00593C00) --------------------------------------------------------  // acclient.c:445176
int __stdcall CEnchantmentRegistry::IsEnchantmentInList(const unsigned int spell, PackableList<Enchantment> *list)
{
  PackableLLNode<Enchantment> *i; // eax@2

  if ( list )
  {
    for ( i = list->head; i; i = i->next )
    {
      if ( (i->data._id & 0xFFFF) == spell )
        return 1;
    }
  }
  return 0;
}

//----- (00593C40) --------------------------------------------------------  // acclient.c:445192
int __thiscall CEnchantmentRegistry::UpdateSpellTotals(CEnchantmentRegistry *this, unsigned int spell, int iDelta)
{
  CEnchantmentRegistry *v3; // ebx@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // esi@3
  CSpellBase *v7; // eax@4

  v3 = this;
  if ( spell >= 0x8000 )
    return 1;
  v5 = DBObj::GetByEnum(6, 2, 0x10000005u);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = CSpellTable::GetSpellBase((CSpellTable *)v5, spell);
  if ( !v7 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    return 0;
  }
  if ( v7->_bitfield & 4 )
  {
    v3->m_cHelpfulEnchantments += iDelta;
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    result = 1;
  }
  else
  {
    v3->m_cHarmfulEnchantments += iDelta;
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    result = 1;
  }
  return result;
}

//----- (00593CD0) --------------------------------------------------------  // acclient.c:445229
void __thiscall CEnchantmentRegistry::CountSpellsInList(CEnchantmentRegistry *this, PackableList<Enchantment> *list)
{
  CEnchantmentRegistry *v2; // edi@1
  PackableLLNode<Enchantment> *i; // esi@2

  v2 = this;
  if ( list )
  {
    for ( i = list->head; i; i = i->next )
      CEnchantmentRegistry::UpdateSpellTotals(v2, i->data._id & 0xFFFF, 1);
  }
}

//----- (00593D00) --------------------------------------------------------  // acclient.c:445243
int __stdcall CEnchantmentRegistry::AttemptToReplaceSpellInList(Enchantment *spell, PackableList<Enchantment> **list)
{
  int result; // eax@3
  int i; // ecx@4

  if ( *list && spell->_duration > 0.0 )
  {
    for ( i = (int)(*list)->head; i; i = *(_DWORD *)(i + 80) )
    {
      if ( !((spell->_id ^ *(_DWORD *)(i + 4)) & 0xFFFF) && *(double *)(i + 32) > 0.0 )
      {
        Enchantment::operator=(i, (int)spell);
        return 1;
      }
    }
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00593D60) --------------------------------------------------------  // acclient.c:445268
void __thiscall PackableList<Enchantment>::InsertHead(PackableList<Enchantment> *this, Enchantment *val)
{
  PackableList<Enchantment> *v2; // esi@1
  void *v3; // edi@1
  PackableLLNode<Enchantment> *v4; // eax@4
  unsigned int v5; // eax@5
  unsigned int v6; // eax@6

  v2 = this;
  v3 = operator new(0x58u);
  if ( v3 )
  {
    Enchantment::Enchantment((Enchantment *)v3, val);
    *((_DWORD *)v3 + 20) = 0;
    *((_DWORD *)v3 + 21) = 0;
  }
  else
  {
    v3 = 0;
  }
  v4 = v2->head;
  if ( v4 )
  {
    v4->prev = (PackableLLNode<Enchantment> *)v3;
    *((_DWORD *)v3 + 20) = v4;
    v6 = v2->curNum;
    v2->head = (PackableLLNode<Enchantment> *)v3;
    v2->curNum = v6 + 1;
  }
  else
  {
    v5 = v2->curNum;
    v2->tail = (PackableLLNode<Enchantment> *)v3;
    v2->head = (PackableLLNode<Enchantment> *)v3;
    v2->curNum = v5 + 1;
  }
}

//----- (00593DC0) --------------------------------------------------------  // acclient.c:445307
CEnchantmentRegistry *__thiscall CEnchantmentRegistry::vector_deleting_destructor(CEnchantmentRegistry *this, unsigned int a2)
{
  CEnchantmentRegistry *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&CEnchantmentRegistry::vftable;
  CEnchantmentRegistry::Clear(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4668: using guessed type int (__thiscall *CEnchantmentRegistry::vftable)(void *, char);

//----- (00593DF0) --------------------------------------------------------  // acclient.c:445323
int __thiscall CEnchantmentRegistry::AddEnchantmentToList(CEnchantmentRegistry *this, Enchantment *to_update, PackableList<Enchantment> **list)
{
  CEnchantmentRegistry *v3; // ebx@1
  void *v4; // eax@2
  int result; // eax@6

  v3 = this;
  if ( *list
    || ((v4 = operator new(0x10u)) == 0 ? (v4 = 0) : (*(_DWORD *)v4 = &PackableList<Enchantment>::vftable,
                                                      *((_DWORD *)v4 + 1) = 0,
                                                      *((_DWORD *)v4 + 2) = 0,
                                                      *((_DWORD *)v4 + 3) = 0),
        (*list = (PackableList<Enchantment> *)v4) != 0) )
  {
    if ( !CEnchantmentRegistry::AttemptToReplaceSpellInList(to_update, list) )
    {
      PackableList<Enchantment>::InsertHead(*list, to_update);
      CEnchantmentRegistry::UpdateSpellTotals(v3, to_update->_id & 0xFFFF, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (00593E70) --------------------------------------------------------  // acclient.c:445353
int __thiscall CEnchantmentRegistry::UpdateEnchantment(CEnchantmentRegistry *this, Enchantment *to_update)
{
  CEnchantmentRegistry *v2; // edi@1
  unsigned int v3; // ecx@1
  unsigned int v5; // eax@3
  unsigned int v6; // eax@7
  unsigned int v7; // eax@12

  v2 = this;
  v3 = to_update->_smod.type ^ ((to_update->_smod.type ^ (to_update->_smod.type >> 9)) >> 1);
  if ( !(BYTE1(v3) & 0x40) )
    return 0;
  v5 = to_update->_smod.type;
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v5 )
    return CEnchantmentRegistry::UpdateVitae(v2, to_update);
  if ( v5 & 0x1000000 && CEnchantmentRegistry::ReplaceEnchantmentInList(to_update, v2->_cooldown_list) )
    return 1;
  v6 = to_update->_smod.type;
  if ( BYTE1(v6) & 0x40 )
  {
    if ( CEnchantmentRegistry::ReplaceEnchantmentInList(to_update, v2->_mult_list) )
      return 1;
  }
  else if ( SBYTE1(v6) < 0 && CEnchantmentRegistry::ReplaceEnchantmentInList(to_update, v2->_add_list) )
  {
    return 1;
  }
  v7 = to_update->_smod.type;
  if ( v7 & 0x1000000 )
  {
    CEnchantmentRegistry::AddEnchantmentToList(v2, to_update, &v2->_cooldown_list);
    return 1;
  }
  if ( BYTE1(v7) & 0x40 )
  {
    CEnchantmentRegistry::AddEnchantmentToList(v2, to_update, &v2->_mult_list);
    return 1;
  }
  if ( SBYTE1(v7) < 0 )
    CEnchantmentRegistry::AddEnchantmentToList(v2, to_update, &v2->_add_list);
  return 1;
}

//----- (00593F50) --------------------------------------------------------  // acclient.c:445397
int __thiscall CEnchantmentRegistry::UpdateEnchantmentList(CEnchantmentRegistry *this, PackableList<Enchantment> *to_update_list)
{
  PackableLLNode<Enchantment> *v2; // esi@1
  CEnchantmentRegistry *v3; // ebx@1
  int v4; // edi@1
  int v5; // eax@3

  v2 = to_update_list->head;
  v3 = this;
  v4 = 0;
  while ( v2 )
  {
    v5 = CEnchantmentRegistry::UpdateEnchantment(v3, &v2->data);
    v2 = v2->next;
    v4 |= v5;
  }
  return v4;
}

//----- (00593F80) --------------------------------------------------------  // acclient.c:445417
int __thiscall CEnchantmentRegistry::IsEnchanted(CEnchantmentRegistry *this, const unsigned int spell)
{
  CEnchantmentRegistry *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( spell )
  {
    if ( spell == 666 )
    {
      result = this->_vitae != 0;
    }
    else if ( CEnchantmentRegistry::IsEnchantmentInList(spell, this->_cooldown_list)
           || CEnchantmentRegistry::IsEnchantmentInList(spell, v2->_mult_list) )
    {
      result = 1;
    }
    else
    {
      result = CEnchantmentRegistry::IsEnchantmentInList(spell, v2->_add_list) != 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00593FF0) --------------------------------------------------------  // acclient.c:445447
int __thiscall CEnchantmentRegistry::UnPack(CEnchantmentRegistry *this, void **addr, unsigned int size)
{
  CEnchantmentRegistry *v3; // esi@1
  int result; // eax@2
  void **v5; // ebp@3
  char *v6; // eax@3
  unsigned int v7; // ebx@3
  void *v8; // eax@5
  PackableList<Enchantment> *v9; // ecx@11
  void *v10; // eax@15
  PackableList<Enchantment> *v11; // ecx@21
  void *v12; // eax@25
  PackableList<Enchantment> *v13; // ecx@31
  Enchantment *v14; // eax@35
  Enchantment *v15; // eax@36
  Enchantment *v16; // ecx@41
  PackableList<Enchantment> *v17; // ST04_4@43
  void *v18; // [sp+10h] [bp-4h]@3
  void **addra; // [sp+18h] [bp+4h]@3

  v3 = this;
  if ( size < 4 )
    return 0;
  v5 = addr;
  v18 = *addr;
  v6 = (char *)*addr + 4;
  v7 = size - 4;
  addra = *(void ***)*addr;
  *v5 = v6;
  if ( (unsigned __int8)addra & 1 )
  {
    if ( !this->_mult_list )
    {
      v8 = operator new(0x10u);
      if ( v8 )
      {
        *(_DWORD *)v8 = &PackableList<Enchantment>::vftable;
        *((_DWORD *)v8 + 1) = 0;
        *((_DWORD *)v8 + 2) = 0;
        *((_DWORD *)v8 + 3) = 0;
      }
      else
      {
        v8 = 0;
      }
      v3->_mult_list = (PackableList<Enchantment> *)v8;
    }
    if ( !((int (__stdcall *)(void **, unsigned int))v3->_mult_list->vfptr->UnPack)(v5, v7) )
      return 0;
  }
  else
  {
    v9 = this->_mult_list;
    if ( v9 )
    {
      ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      v3->_mult_list = 0;
    }
  }
  if ( (unsigned __int8)addra & 2 )
  {
    if ( !v3->_add_list )
    {
      v10 = operator new(0x10u);
      if ( v10 )
      {
        *(_DWORD *)v10 = &PackableList<Enchantment>::vftable;
        *((_DWORD *)v10 + 1) = 0;
        *((_DWORD *)v10 + 2) = 0;
        *((_DWORD *)v10 + 3) = 0;
      }
      else
      {
        v10 = 0;
      }
      v3->_add_list = (PackableList<Enchantment> *)v10;
    }
    result = ((int (__stdcall *)(void **, unsigned int))v3->_add_list->vfptr->UnPack)(v5, v7);
    if ( !result )
      return result;
  }
  else
  {
    v11 = v3->_add_list;
    if ( v11 )
    {
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->_add_list = 0;
    }
  }
  if ( (unsigned __int8)addra & 8 )
  {
    if ( !v3->_cooldown_list )
    {
      v12 = operator new(0x10u);
      if ( v12 )
      {
        *(_DWORD *)v12 = &PackableList<Enchantment>::vftable;
        *((_DWORD *)v12 + 1) = 0;
        *((_DWORD *)v12 + 2) = 0;
        *((_DWORD *)v12 + 3) = 0;
      }
      else
      {
        v12 = 0;
      }
      v3->_cooldown_list = (PackableList<Enchantment> *)v12;
    }
    result = ((int (__stdcall *)(void **, unsigned int))v3->_cooldown_list->vfptr->UnPack)(v5, v7);
    if ( !result )
      return result;
  }
  else
  {
    v13 = v3->_cooldown_list;
    if ( v13 )
    {
      ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      v3->_cooldown_list = 0;
    }
  }
  if ( (unsigned __int8)addra & 4 )
  {
    if ( !v3->_vitae )
    {
      v14 = (Enchantment *)operator new(0x50u);
      if ( v14 )
        Enchantment::Enchantment(v14);
      else
        v15 = 0;
      v3->_vitae = v15;
    }
    result = ((int (__stdcall *)(void **, unsigned int))v3->_vitae->vfptr->UnPack)(v5, v7);
    if ( !result )
      return result;
  }
  else
  {
    v16 = v3->_vitae;
    if ( v16 )
    {
      ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
      v3->_vitae = 0;
    }
  }
  v17 = v3->_mult_list;
  v3->m_cHelpfulEnchantments = 0;
  v3->m_cHarmfulEnchantments = 0;
  CEnchantmentRegistry::CountSpellsInList(v3, v17);
  CEnchantmentRegistry::CountSpellsInList(v3, v3->_add_list);
  if ( v18 > *v5 )
    return 0;
  return size >= (_BYTE *)*v5 - (_BYTE *)v18;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (005941C0) --------------------------------------------------------  // acclient.c:445604
int __thiscall PackableList<Enchantment>::Remove(PackableList<Enchantment> *this, Enchantment *val)
{
  PackableList<Enchantment> *v2; // edi@1
  Enchantment *v3; // ecx@1
  int result; // eax@2
  Enchantment *v5; // esi@3
  PackableLLNode<Enchantment> *v6; // eax@4
  PackObjVtbl *v7; // eax@14
  void *(__thiscall *v8)(PackObj *, unsigned int); // ecx@14

  v2 = this;
  v3 = &this->head->data;
  if ( v3 )
  {
    v5 = v3;
    if ( ContentProfile::operator==(v3, val) )
    {
      Enchantment::operator=((int)val, (int)v2->head);
      v6 = v2->head->next;
      v2->head = v6;
      if ( v6 )
        v6->prev = 0;
      else
        v2->tail = 0;
      if ( v5 )
      {
        v5->_smod.vfptr = (PackObjVtbl *)&PackObj::vftable;
        v5->vfptr = (PackObjVtbl *)&PackObj::vftable;
        operator delete(v5);
      }
      --v2->curNum;
      result = 1;
    }
    else if ( v5[1].vfptr )
    {
      while ( !ContentProfile::operator==((Enchantment *)v5[1].vfptr, val) )
      {
        v5 = (Enchantment *)v5[1].vfptr;
        if ( !v5[1].vfptr )
          goto LABEL_13;
      }
      Enchantment::operator=((int)val, (int)v5[1].vfptr);
      v7 = v5[1].vfptr;
      v8 = v7[4].__vecDelDtor;
      v5[1].vfptr = (PackObjVtbl *)v8;
      if ( v8 )
        *((_DWORD *)v8 + 21) = v5;
      else
        v2->tail = (PackableLLNode<Enchantment> *)v5;
      *(_DWORD *)&v7[3].gap4[0] = &PackObj::vftable;
      v7->__vecDelDtor = (void *(__thiscall *)(PackObj *, unsigned int))&PackObj::vftable;
      operator delete(v7);
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

//----- (005942B0) --------------------------------------------------------  // acclient.c:445674
int __stdcall CEnchantmentRegistry::Duel(Enchantment *challenger, PackableList<Enchantment> *list)
{
  PackableLLNode<Enchantment> *i; // esi@1
  const unsigned int v5; // esi@7
  Enchantment *v6; // eax@8
  Enchantment *v7; // eax@9
  Enchantment *v8; // esi@9
  PackableLLNode<Enchantment> *v9; // eax@14
  unsigned int v10; // eax@15
  Enchantment v11; // [sp+Ch] [bp-50h]@8

  for ( i = list->head; i; i = i->next )
  {
    if ( i->data._spell_category == challenger->_spell_category )
    {
      if ( Enchantment::Duel(&i->data, challenger) )
        return 0;
      v5 = i->data._id;
      if ( v5 )
      {
        Enchantment::Enchantment(&v11, v5);
        PackableList<Enchantment>::Remove(list, v6);
      }
      break;
    }
  }
  v7 = (Enchantment *)operator new(0x58u);
  v8 = v7;
  if ( v7 )
  {
    Enchantment::Enchantment(v7, challenger);
    v8[1].vfptr = 0;
    v8[1]._id = 0;
  }
  else
  {
    v8 = 0;
  }
  if ( list->head )
  {
    v9 = list->tail;
    v9->next = (PackableLLNode<Enchantment> *)v8;
    v8[1]._id = (unsigned int)v9;
  }
  else
  {
    list->head = (PackableLLNode<Enchantment> *)v8;
  }
  v10 = list->curNum + 1;
  list->tail = (PackableLLNode<Enchantment> *)v8;
  list->curNum = v10;
  return 1;
}

//----- (00594360) --------------------------------------------------------  // acclient.c:445729
int __thiscall CEnchantmentRegistry::RemoveEnchantmentFromList(CEnchantmentRegistry *this, const unsigned int eid, PackableList<Enchantment> *list)
{
  CEnchantmentRegistry *v3; // ebx@1
  int result; // eax@2
  Enchantment *v5; // eax@3
  int v6; // edi@3
  Enchantment v7; // [sp+8h] [bp-50h]@3

  v3 = this;
  if ( list )
  {
    Enchantment::Enchantment(&v7, eid);
    v6 = PackableList<Enchantment>::Remove(list, v5);
    if ( v6 )
      CEnchantmentRegistry::UpdateSpellTotals(v3, (unsigned __int16)eid, -1);
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005943C0) --------------------------------------------------------  // acclient.c:445754
int __thiscall CEnchantmentRegistry::OnCooldown(CEnchantmentRegistry *this, const unsigned int cooldown_id, long double *time_left)
{
  PackableList<Enchantment> *v3; // eax@2
  PackableLLNode<Enchantment> *i; // edx@3
  long double v5; // st7@7

  if ( cooldown_id )
  {
    v3 = this->_cooldown_list;
    if ( v3 )
    {
      for ( i = v3->head; i; i = i->next )
      {
        if ( (i->data._id & 0xFFFF) == cooldown_id )
        {
          v5 = i->data._duration + i->data._start_time - COERCE_DOUBLE(Timer::cur_time.Cmd);
          *time_left = v5;
          if ( v5 <= 0.0 )
          {
            PackableList<Enchantment>::Remove(this->_cooldown_list, &i->data);
            return 0;
          }
          return 1;
        }
      }
    }
  }
  return 0;
}

//----- (00594430) --------------------------------------------------------  // acclient.c:445785
PackableList<Enchantment> *__stdcall CEnchantmentRegistry::GetEnchantmentsInEffectFromList(PackableList<Enchantment> *list, PackableList<Enchantment> *retval)
{
  PackableList<Enchantment> *result; // eax@1
  PackableList<Enchantment> *v4; // edi@1
  PackableLLNode<Enchantment> *v5; // esi@2
  int v6; // eax@4

  result = list;
  v4 = 0;
  if ( list )
  {
    v5 = list->head;
    while ( v5 )
    {
      v6 = CEnchantmentRegistry::Duel(&v5->data, retval);
      v5 = v5->next;
      v4 = (PackableList<Enchantment> *)(v6 | (unsigned int)v4);
    }
    result = v4;
  }
  return result;
}

//----- (00594470) --------------------------------------------------------  // acclient.c:445809
PackableList<Enchantment> *__stdcall CEnchantmentRegistry::CullEnchantmentsFromList(PackableList<Enchantment> *list, const unsigned int type, const unsigned int key, PackableList<Enchantment> *affecting)
{
  PackableList<Enchantment> *result; // eax@1
  PackableLLNode<Enchantment> *v6; // esi@2
  PackableList<Enchantment> *v7; // ebx@2
  unsigned int v8; // eax@4

  result = list;
  if ( list )
  {
    v6 = list->head;
    v7 = 0;
    while ( v6 )
    {
      v8 = v6->data._smod.type;
      if ( v8 & type
        && (BYTE1(v8) & 0x20
         || v6->data._smod.key == key
         || Enchantment::AffectsAttackSkills(&v6->data, key)
         || Enchantment::AffectsDefenseSkills(&v6->data, key)) )
        v7 = (PackableList<Enchantment> *)(CEnchantmentRegistry::Duel(&v6->data, affecting) | (unsigned int)v7);
      v6 = v6->next;
    }
    result = v7;
  }
  return result;
}

//----- (005944E0) --------------------------------------------------------  // acclient.c:445838
int __thiscall CEnchantmentRegistry::RemoveEnchantment(CEnchantmentRegistry *this, const unsigned int eid)
{
  CEnchantmentRegistry *v2; // esi@1
  Enchantment *v3; // ecx@1

  v2 = this;
  v3 = this->_vitae;
  if ( v3 && v3->_id == eid )
  {
    ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
    v2->_vitae = 0;
    return 1;
  }
  if ( CEnchantmentRegistry::RemoveEnchantmentFromList(v2, eid, v2->_cooldown_list)
    || CEnchantmentRegistry::RemoveEnchantmentFromList(v2, eid, v2->_mult_list) )
    return 1;
  return CEnchantmentRegistry::RemoveEnchantmentFromList(v2, eid, v2->_add_list);
}

//----- (00594540) --------------------------------------------------------  // acclient.c:445858
unsigned int __thiscall CEnchantmentRegistry::GetEnchantmentsInEffect(CEnchantmentRegistry *this, PackableList<Enchantment> *retval)
{
  CEnchantmentRegistry *v2; // esi@1
  PackableList<Enchantment> *v3; // ebx@1

  v2 = this;
  v3 = CEnchantmentRegistry::GetEnchantmentsInEffectFromList(this->_mult_list, retval);
  return (unsigned int)v3 | (unsigned int)CEnchantmentRegistry::GetEnchantmentsInEffectFromList(v2->_add_list, retval);
}

//----- (00594570) --------------------------------------------------------  // acclient.c:445869
int __thiscall CEnchantmentRegistry::EnchantAttribute(CEnchantmentRegistry *this, unsigned int stype, unsigned int *val)
{
  unsigned int *v3; // ebp@1
  CEnchantmentRegistry *v4; // esi@1
  PackableList<Enchantment> *v5; // ST00_4@1
  PackableLLNode<Enchantment> *v6; // esi@1
  int v7; // edi@1
  double v8; // st7@4
  PackableList<Enchantment> affecting; // [sp+4h] [bp-10h]@1

  v3 = val;
  v4 = this;
  *(float *)&val = (double)*val;
  v5 = this->_mult_list;
  affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  affecting.head = 0;
  affecting.tail = 0;
  affecting.curNum = 0;
  CEnchantmentRegistry::CullEnchantmentsFromList(v5, 1u, stype, &affecting);
  CEnchantmentRegistry::CullEnchantmentsFromList(v4->_add_list, 1u, stype, &affecting);
  v6 = affecting.head;
  v7 = 0;
  if ( affecting.head )
  {
    do
    {
      v7 |= Enchantment::Enchant(&v6->data, (float *)&val);
      if ( !v6 )
        break;
      v6 = v6->next;
    }
    while ( v6 );
  }
  v8 = *(float *)&val;
  if ( *v3 < 0xA )
  {
    if ( v8 < 1.0 )
      *(float *)&val = 1.0;
  }
  else if ( v8 < 10.0 )
  {
    *(float *)&val = 10.0;
  }
  *v3 = (unsigned __int64)(*(float *)&val + 0.5);
  affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  PackableList<Enchantment>::Flush(&affecting);
  return v7;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (00594670) --------------------------------------------------------  // acclient.c:445920
int __thiscall CEnchantmentRegistry::EnchantAttribute2nd(CEnchantmentRegistry *this, unsigned int stype, unsigned int *val)
{
  CEnchantmentRegistry *v3; // esi@1
  int result; // eax@1
  int v5; // edi@1
  int v6; // ebp@2
  int v7; // edi@4
  Enchantment *v8; // ecx@4
  PackableList<Enchantment> *v9; // ecx@6
  int v10; // eax@6
  double v11; // st7@6
  int v12; // edi@6
  float tmp; // [sp+8h] [bp-14h]@4
  PackableList<Enchantment> affecting; // [sp+Ch] [bp-10h]@6

  v3 = this;
  result = DBObj::GetByEnum(268435458, 3, 0x1000000Cu);
  v5 = result;
  if ( result )
  {
    v6 = ACQualityFilter::QueryAttribute2nd((ACQualityFilter *)result, stype);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    if ( v6 )
    {
      v7 = 0;
      v8 = v3->_vitae;
      tmp = (double)*val;
      if ( v8 )
        v7 = Enchantment::Enchant(v8, &tmp);
      v9 = v3->_mult_list;
      affecting.head = 0;
      affecting.tail = 0;
      affecting.curNum = 0;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      CEnchantmentRegistry::CullEnchantmentsFromList(v9, 2u, stype, &affecting);
      CEnchantmentRegistry::CullEnchantmentsFromList(v3->_add_list, 2u, stype, &affecting);
      v10 = CEnchantmentRegistry::Enchant(&affecting, &tmp);
      v11 = tmp;
      v12 = v10 | v7;
      if ( *val < 5 )
      {
        if ( v11 < 1.0 )
          tmp = 1.0;
      }
      else if ( v11 < 5.0 )
      {
        tmp = 5.0;
      }
      *val = (unsigned __int64)(tmp + 0.5);
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      PackableList<Enchantment>::Flush(&affecting);
      result = v12;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (005947B0) --------------------------------------------------------  // acclient.c:445983
int __thiscall CEnchantmentRegistry::EnchantSkill(CEnchantmentRegistry *this, unsigned int stype, int *val)
{
  CEnchantmentRegistry *v3; // esi@1
  Enchantment *v4; // ecx@1
  int v5; // ebp@1
  PackableList<Enchantment> *v6; // ST00_4@3
  PackableLLNode<Enchantment> *v7; // esi@3
  int v8; // edi@3
  int v9; // ebp@6
  float tmp; // [sp+8h] [bp-14h]@1
  PackableList<Enchantment> affecting; // [sp+Ch] [bp-10h]@3

  v3 = this;
  v4 = this->_vitae;
  tmp = (double)*val;
  v5 = 0;
  if ( v4 )
    v5 = Enchantment::Enchant(v4, &tmp);
  v6 = v3->_mult_list;
  affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  affecting.head = 0;
  affecting.tail = 0;
  affecting.curNum = 0;
  CEnchantmentRegistry::CullEnchantmentsFromList(v6, 0x10u, stype, &affecting);
  CEnchantmentRegistry::CullEnchantmentsFromList(v3->_add_list, 0x10u, stype, &affecting);
  v7 = affecting.head;
  v8 = 0;
  if ( affecting.head )
  {
    do
    {
      v8 |= Enchantment::Enchant(&v7->data, &tmp);
      if ( !v7 )
        break;
      v7 = v7->next;
    }
    while ( v7 );
  }
  v9 = v8 | v5;
  if ( tmp <= 0.5 )
    tmp = 0.0;
  *val = (unsigned __int64)(tmp + 0.5);
  affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
  PackableList<Enchantment>::Flush(&affecting);
  return v9;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (005948A0) --------------------------------------------------------  // acclient.c:446032
int __thiscall CEnchantmentRegistry::EnchantInt(CEnchantmentRegistry *this, unsigned int stype, int *val, int allow_negative)
{
  CEnchantmentRegistry *v4; // esi@1
  int result; // eax@1
  int v6; // ebx@1
  unsigned int v7; // edi@2
  PackableList<Enchantment> *v8; // edx@4
  int v9; // eax@4
  double v10; // st7@4
  int v11; // esi@4
  float tmp; // [sp+8h] [bp-14h]@4
  PackableList<Enchantment> affecting; // [sp+Ch] [bp-10h]@4
  unsigned int stypea; // [sp+20h] [bp+4h]@2

  v4 = this;
  result = DBObj::GetByEnum(268435458, 3, 0x1000000Cu);
  v6 = result;
  if ( result )
  {
    v7 = stype;
    stypea = QualityFilter::QueryInt((QualityFilter *)result, stype);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    if ( stypea )
    {
      v8 = v4->_mult_list;
      tmp = (double)*val;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      affecting.head = 0;
      affecting.tail = 0;
      affecting.curNum = 0;
      CEnchantmentRegistry::CullEnchantmentsFromList(v8, 4u, v7, &affecting);
      CEnchantmentRegistry::CullEnchantmentsFromList(v4->_add_list, 4u, v7, &affecting);
      v9 = CEnchantmentRegistry::Enchant(&affecting, &tmp);
      v10 = tmp;
      v11 = v9;
      if ( !allow_negative )
      {
        if ( v10 <= 0.5 )
          tmp = 0.0;
        v10 = tmp + 0.5;
      }
      *val = (unsigned __int64)v10;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      PackableList<Enchantment>::Flush(&affecting);
      result = v11;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (005949B0) --------------------------------------------------------  // acclient.c:446088
int __thiscall CEnchantmentRegistry::EnchantFloat(CEnchantmentRegistry *this, unsigned int stype, long double *val)
{
  CEnchantmentRegistry *v3; // esi@1
  int result; // eax@1
  int v5; // ebx@1
  unsigned int v6; // edi@2
  PackableList<Enchantment> *v7; // edx@4
  int v8; // eax@4
  int v9; // esi@4
  float tmp; // [sp+8h] [bp-14h]@4
  PackableList<Enchantment> affecting; // [sp+Ch] [bp-10h]@4
  unsigned int stypea; // [sp+20h] [bp+4h]@2

  v3 = this;
  result = DBObj::GetByEnum(268435458, 3, 0x1000000Cu);
  v5 = result;
  if ( result )
  {
    v6 = stype;
    stypea = QualityFilter::QueryFloat((QualityFilter *)result, stype);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    if ( stypea )
    {
      v7 = v3->_mult_list;
      tmp = *val;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      affecting.head = 0;
      affecting.tail = 0;
      affecting.curNum = 0;
      CEnchantmentRegistry::CullEnchantmentsFromList(v7, 8u, v6, &affecting);
      CEnchantmentRegistry::CullEnchantmentsFromList(v3->_add_list, 8u, v6, &affecting);
      v8 = CEnchantmentRegistry::Enchant(&affecting, &tmp);
      *val = tmp;
      v9 = v8;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      PackableList<Enchantment>::Flush(&affecting);
      result = v9;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (00594A90) --------------------------------------------------------  // acclient.c:446136
int __thiscall CEnchantmentRegistry::GetFloatEnchantmentDetails(CEnchantmentRegistry *this, unsigned int stype, EnchantedQualityDetails *val)
{
  CEnchantmentRegistry *v3; // esi@1
  int result; // eax@1
  int v5; // edi@1
  int v6; // ebp@2
  PackableList<Enchantment> *v7; // ST00_4@3
  PackableList<Enchantment> affecting; // [sp+8h] [bp-10h]@3

  v3 = this;
  result = DBObj::GetByEnum(268435458, 3, 0x1000000Cu);
  v5 = result;
  if ( result )
  {
    v6 = QualityFilter::QueryFloat((QualityFilter *)result, stype);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
    if ( v6 )
    {
      v7 = v3->_mult_list;
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      affecting.head = 0;
      affecting.tail = 0;
      affecting.curNum = 0;
      CEnchantmentRegistry::CullEnchantmentsFromList(v7, 8u, stype, &affecting);
      CEnchantmentRegistry::CullEnchantmentsFromList(v3->_add_list, 8u, stype, &affecting);
      CEnchantmentRegistry::Enchant(&affecting, val);
      affecting.vfptr = (PackObjVtbl *)&PackableList<Enchantment>::vftable;
      PackableList<Enchantment>::Flush(&affecting);
    }
    result = 1;
  }
  return result;
}
// 7B15C4: using guessed type int (__thiscall *PackableList<Enchantment>::vftable)(void *, char);

//----- (00594B40) --------------------------------------------------------  // acclient.c:446172
PackableLLNode<unsigned long> *__thiscall CEnchantmentRegistry::RemoveEnchantments(CEnchantmentRegistry *this, PackableList<unsigned long> *to_remove)
{
  PackableLLNode<unsigned long> *result; // eax@1
  CEnchantmentRegistry *v3; // edi@1
  PackableLLNode<unsigned long> *v4; // ebp@2
  Enchantment *v5; // ecx@4
  const unsigned int v6; // esi@4
  PackableList<Enchantment> *v7; // ebx@7
  Enchantment *v8; // eax@8
  int v9; // eax@8
  int v10; // eax@12
  int retval; // [sp+4h] [bp-54h]@1
  Enchantment v12; // [sp+8h] [bp-50h]@8

  result = to_remove->head;
  v3 = this;
  retval = 0;
  if ( result )
  {
    v4 = to_remove->head;
    while ( v4 )
    {
      v5 = v3->_vitae;
      v6 = v4->data;
      if ( v5 && v5->_id == v6 )
      {
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
        v3->_vitae = 0;
        v4 = v4->next;
        retval |= 1u;
      }
      else
      {
        v7 = v3->_cooldown_list;
        if ( v7
          && (Enchantment::Enchantment(&v12, v4->data),
              v9 = PackableList<Enchantment>::Remove(v7, v8),
              v12._smod.vfptr = (PackObjVtbl *)&PackObj::vftable,
              v12.vfptr = (PackObjVtbl *)&PackObj::vftable,
              v9) )
        {
          CEnchantmentRegistry::UpdateSpellTotals(v3, (unsigned __int16)v6, -1);
          v4 = v4->next;
          retval |= 1u;
        }
        else if ( CEnchantmentRegistry::RemoveEnchantmentFromList(v3, v6, v3->_mult_list) )
        {
          v4 = v4->next;
          retval |= 1u;
        }
        else
        {
          v10 = CEnchantmentRegistry::RemoveEnchantmentFromList(v3, v6, v3->_add_list);
          v4 = v4->next;
          retval |= v10;
        }
      }
    }
    result = (PackableLLNode<unsigned long> *)retval;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00594C50) --------------------------------------------------------  // acclient.c:446237
PackableLLNode<unsigned long> *__thiscall CEnchantmentRegistry::PurgeEnchantmentList(CEnchantmentRegistry *this, PackableList<Enchantment> *list)
{
  void *v3; // ebx@3
  PackableLLNode<Enchantment> *v4; // edi@3
  unsigned int v5; // esi@6
  void *v6; // eax@6
  PackableLLNode<unsigned long> *v7; // esi@13
  CEnchantmentRegistry *v8; // [sp+4h] [bp-14h]@1
  PackableList<unsigned long> to_remove; // [sp+8h] [bp-10h]@3

  v8 = this;
  if ( !list )
    return 0;
  v3 = 0;
  v4 = list->head;
  to_remove.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  to_remove.head = 0;
  to_remove.tail = 0;
  to_remove.curNum = 0;
  while ( v4 )
  {
    if ( v4->data._duration == -1.0 )
      goto LABEL_12;
    v5 = v4->data._id;
    v6 = operator new(0xCu);
    if ( v6 )
    {
      *(_DWORD *)v6 = v5;
      *((_DWORD *)v6 + 1) = 0;
      *((_DWORD *)v6 + 2) = 0;
    }
    else
    {
      v6 = 0;
    }
    if ( v3 )
    {
      *((_DWORD *)v3 + 2) = v6;
      *((_DWORD *)v6 + 1) = v3;
      v3 = v6;
      ++to_remove.curNum;
LABEL_12:
      v4 = v4->next;
    }
    else
    {
      v4 = v4->next;
      to_remove.tail = (PackableLLNode<unsigned long> *)v6;
      v3 = v6;
      ++to_remove.curNum;
    }
  }
  to_remove.head = (PackableLLNode<unsigned long> *)v3;
  v7 = CEnchantmentRegistry::RemoveEnchantments(v8, &to_remove);
  to_remove.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(&to_remove);
  return v7;
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (00594D10) --------------------------------------------------------  // acclient.c:446298
PackableLLNode<unsigned long> *__thiscall CEnchantmentRegistry::PurgeBadEnchantmentList(CEnchantmentRegistry *this, PackableList<Enchantment> *list)
{
  void *v3; // ebx@3
  PackableLLNode<Enchantment> *v4; // edi@3
  unsigned int v5; // esi@7
  void *v6; // eax@7
  PackableLLNode<unsigned long> *v7; // esi@14
  CEnchantmentRegistry *v8; // [sp+4h] [bp-14h]@1
  PackableList<unsigned long> to_remove; // [sp+8h] [bp-10h]@3

  v8 = this;
  if ( !list )
    return 0;
  v3 = 0;
  v4 = list->head;
  to_remove.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  to_remove.head = 0;
  to_remove.tail = 0;
  to_remove.curNum = 0;
  while ( v4 )
  {
    if ( v4->data._smod.type & 0x2000000 || v4->data._duration == -1.0 )
    {
LABEL_13:
      v4 = v4->next;
    }
    else
    {
      v5 = v4->data._id;
      v6 = operator new(0xCu);
      if ( v6 )
      {
        *(_DWORD *)v6 = v5;
        *((_DWORD *)v6 + 1) = 0;
        *((_DWORD *)v6 + 2) = 0;
      }
      else
      {
        v6 = 0;
      }
      if ( v3 )
      {
        *((_DWORD *)v3 + 2) = v6;
        *((_DWORD *)v6 + 1) = v3;
        v3 = v6;
        ++to_remove.curNum;
        goto LABEL_13;
      }
      v4 = v4->next;
      to_remove.tail = (PackableLLNode<unsigned long> *)v6;
      v3 = v6;
      ++to_remove.curNum;
    }
  }
  to_remove.head = (PackableLLNode<unsigned long> *)v3;
  v7 = CEnchantmentRegistry::RemoveEnchantments(v8, &to_remove);
  to_remove.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  PackableList<unsigned long>::Flush(&to_remove);
  return v7;
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);

//----- (00594DE0) --------------------------------------------------------  // acclient.c:446361
unsigned int __thiscall CEnchantmentRegistry::PurgeEnchantments(CEnchantmentRegistry *this)
{
  CEnchantmentRegistry *v1; // esi@1
  PackableLLNode<unsigned long> *v2; // edi@1

  v1 = this;
  v2 = CEnchantmentRegistry::PurgeEnchantmentList(this, this->_mult_list);
  return (unsigned int)v2 | (unsigned int)CEnchantmentRegistry::PurgeEnchantmentList(v1, v1->_add_list);
}

//----- (00594E00) --------------------------------------------------------  // acclient.c:446372
unsigned int __thiscall CEnchantmentRegistry::PurgeBadEnchantments(CEnchantmentRegistry *this)
{
  CEnchantmentRegistry *v1; // esi@1
  PackableLLNode<unsigned long> *v2; // edi@1

  v1 = this;
  v2 = CEnchantmentRegistry::PurgeBadEnchantmentList(this, this->_mult_list);
  return (unsigned int)v2 | (unsigned int)CEnchantmentRegistry::PurgeBadEnchantmentList(v1, v1->_add_list);
}

//----- (0070ABE0) --------------------------------------------------------  // acclient.c:797954
int sub_70ABE0()
{
  return atexit(nullsub_1421);
}

