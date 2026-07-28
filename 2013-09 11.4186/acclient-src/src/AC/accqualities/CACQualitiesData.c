/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CACQualitiesData
   Object     : AC\accqualities\CACQualitiesData.obj
   Functions  : 45
   Addresses  : 0058EEB0 - 0070AA80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0058EEB0) --------------------------------------------------------  // acclient.c:439497
BOOL __thiscall CACQualities::HasSpellBook(CACQualities *this)
{
  return this->_spell_book != 0;
}

//----- (0058EEC0) --------------------------------------------------------  // acclient.c:439503
int __thiscall CACQualities::IsSpellKnown(CACQualities *this, const unsigned int spell)
{
  CSpellBook *v2; // ecx@1
  int result; // eax@2

  v2 = this->_spell_book;
  if ( v2 )
    result = CSpellBook::Exists(v2, spell);
  else
    result = 0;
  return result;
}

//----- (0058EEE0) --------------------------------------------------------  // acclient.c:439517
int __thiscall CACQualities::TranscribeSpells(CACQualities *this, PackableList<unsigned long> *list)
{
  CSpellBook *v2; // ecx@1
  int result; // eax@2

  v2 = this->_spell_book;
  if ( v2 )
    result = CSpellBook::TranscribeSpells(v2, list);
  else
    result = 0;
  return result;
}

//----- (0058EF00) --------------------------------------------------------  // acclient.c:439531
BOOL __thiscall CACQualities::HasEnchantmentRegistry(CACQualities *this)
{
  return this->_enchantment_reg != 0;
}

//----- (0058EF10) --------------------------------------------------------  // acclient.c:439537
int __thiscall CACQualities::IsEnchanted(CACQualities *this, const unsigned int spell)
{
  CEnchantmentRegistry *v2; // ecx@1
  int result; // eax@2

  v2 = this->_enchantment_reg;
  if ( v2 )
    result = CEnchantmentRegistry::IsEnchanted(v2, spell);
  else
    result = 0;
  return result;
}

//----- (0058EF30) --------------------------------------------------------  // acclient.c:439551
unsigned int __thiscall CACQualities::PurgeEnchantments(CACQualities *this)
{
  CEnchantmentRegistry *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->_enchantment_reg;
  if ( v1 )
    result = CEnchantmentRegistry::PurgeEnchantments(v1);
  else
    result = 0;
  return result;
}

//----- (0058EF40) --------------------------------------------------------  // acclient.c:439565
unsigned int __thiscall CACQualities::PurgeBadEnchantments(CACQualities *this)
{
  CEnchantmentRegistry *v1; // ecx@1
  unsigned int result; // eax@2

  v1 = this->_enchantment_reg;
  if ( v1 )
    result = CEnchantmentRegistry::PurgeBadEnchantments(v1);
  else
    result = 0;
  return result;
}

//----- (0058EF50) --------------------------------------------------------  // acclient.c:439579
unsigned int __thiscall CACQualities::GetEnchantmentsInEffect(CACQualities *this, PackableList<Enchantment> *retval)
{
  CEnchantmentRegistry *v2; // ecx@1
  unsigned int result; // eax@2

  v2 = this->_enchantment_reg;
  if ( v2 )
    result = CEnchantmentRegistry::GetEnchantmentsInEffect(v2, retval);
  else
    result = 0;
  return result;
}

//----- (0058EF70) --------------------------------------------------------  // acclient.c:439593
int __thiscall CACQualities::RemoveEnchantment(CACQualities *this, const unsigned int eid)
{
  CEnchantmentRegistry *v2; // ecx@1
  int result; // eax@2

  v2 = this->_enchantment_reg;
  if ( v2 )
    result = CEnchantmentRegistry::RemoveEnchantment(v2, eid);
  else
    result = 0;
  return result;
}

//----- (0058EF90) --------------------------------------------------------  // acclient.c:439607
PackableLLNode<unsigned long> *__thiscall CACQualities::RemoveEnchantments(CACQualities *this, PackableList<unsigned long> *to_remove)
{
  CEnchantmentRegistry *v2; // ecx@1
  PackableLLNode<unsigned long> *result; // eax@2

  v2 = this->_enchantment_reg;
  if ( v2 )
    result = CEnchantmentRegistry::RemoveEnchantments(v2, to_remove);
  else
    result = 0;
  return result;
}

//----- (0058EFB0) --------------------------------------------------------  // acclient.c:439621
void __thiscall CACQualities::UpdateEnchantment(CACQualities *this, Enchantment *to_update)
{
  CACQualities *v2; // esi@1
  CEnchantmentRegistry *v3; // eax@2
  CEnchantmentRegistry *v4; // eax@3

  v2 = this;
  if ( this->_enchantment_reg
    || ((v3 = (CEnchantmentRegistry *)operator new(0x1Cu)) == 0 ? (v4 = 0) : CEnchantmentRegistry::CEnchantmentRegistry(v3),
        (v2->_enchantment_reg = v4) != 0) )
    CEnchantmentRegistry::UpdateEnchantment(v2->_enchantment_reg, to_update);
}

//----- (0058EFF0) --------------------------------------------------------  // acclient.c:439635
void __thiscall CACQualities::UpdateEnchantments(CACQualities *this, PackableList<Enchantment> *to_update_list)
{
  CACQualities *v2; // esi@1
  CEnchantmentRegistry *v3; // eax@2
  CEnchantmentRegistry *v4; // eax@3

  v2 = this;
  if ( this->_enchantment_reg
    || ((v3 = (CEnchantmentRegistry *)operator new(0x1Cu)) == 0 ? (v4 = 0) : CEnchantmentRegistry::CEnchantmentRegistry(v3),
        (v2->_enchantment_reg = v4) != 0) )
    CEnchantmentRegistry::UpdateEnchantmentList(v2->_enchantment_reg, to_update_list);
}

//----- (0058F030) --------------------------------------------------------  // acclient.c:439649
int __thiscall CACQualities::InqVitae(CACQualities *this, Enchantment *vitae)
{
  CEnchantmentRegistry *v2; // ecx@1
  int result; // eax@2

  v2 = this->_enchantment_reg;
  if ( v2 )
    result = CEnchantmentRegistry::InqVitae(v2, vitae);
  else
    result = 0;
  return result;
}

//----- (0058F050) --------------------------------------------------------  // acclient.c:439663
double __thiscall CACQualities::GetVitaeValue(CACQualities *this)
{
  CEnchantmentRegistry *v1; // ecx@1
  double result; // st7@2

  v1 = this->_enchantment_reg;
  if ( v1 )
    result = CEnchantmentRegistry::GetVitaeValue(v1);
  else
    result = 1.0;
  return result;
}

//----- (0058F070) --------------------------------------------------------  // acclient.c:439677
int __thiscall CACQualities::EnchantAttribute(CACQualities *this, unsigned int stype, unsigned int *val)
{
  CEnchantmentRegistry *v3; // ecx@1
  int result; // eax@2

  v3 = this->_enchantment_reg;
  if ( v3 )
    result = CEnchantmentRegistry::EnchantAttribute(v3, stype, val);
  else
    result = 0;
  return result;
}

//----- (0058F090) --------------------------------------------------------  // acclient.c:439691
int __thiscall CACQualities::EnchantAttribute2nd(CACQualities *this, unsigned int stype, unsigned int *val)
{
  CEnchantmentRegistry *v3; // ecx@1
  int result; // eax@2

  v3 = this->_enchantment_reg;
  if ( v3 )
    result = CEnchantmentRegistry::EnchantAttribute2nd(v3, stype, val);
  else
    result = 0;
  return result;
}

//----- (0058F0B0) --------------------------------------------------------  // acclient.c:439705
int __thiscall CACQualities::EnchantSkill(CACQualities *this, unsigned int stype, int *val)
{
  CEnchantmentRegistry *v3; // ecx@1
  int result; // eax@2

  v3 = this->_enchantment_reg;
  if ( v3 )
    result = CEnchantmentRegistry::EnchantSkill(v3, stype, val);
  else
    result = 0;
  return result;
}

//----- (0058F0D0) --------------------------------------------------------  // acclient.c:439719
int __thiscall CACQualities::EnchantInt(CACQualities *this, unsigned int stype, int *val, int allow_negative)
{
  CBaseQualitiesVtbl *v4; // ecx@1
  int result; // eax@2

  v4 = this->vfptr;
  if ( v4 )
    result = CEnchantmentRegistry::EnchantInt((CEnchantmentRegistry *)v4, stype, val, allow_negative);
  else
    result = 0;
  return result;
}

//----- (0058F0F0) --------------------------------------------------------  // acclient.c:439733
int __thiscall CACQualities::EnchantFloat(CACQualities *this, unsigned int stype, long double *val)
{
  CBaseQualitiesVtbl *v3; // ecx@1
  int result; // eax@2

  v3 = this->vfptr;
  if ( v3 )
    result = CEnchantmentRegistry::EnchantFloat((CEnchantmentRegistry *)v3, stype, val);
  else
    result = 0;
  return result;
}

//----- (0058F110) --------------------------------------------------------  // acclient.c:439747
int __thiscall CACQualities::GetFloatEnchantmentDetails(CACQualities *this, unsigned int stype, EnchantedQualityDetails *val)
{
  CBaseQualitiesVtbl *v3; // ecx@1
  int result; // eax@2

  v3 = this->vfptr;
  if ( v3 )
    result = CEnchantmentRegistry::GetFloatEnchantmentDetails((CEnchantmentRegistry *)v3, stype, val);
  else
    result = 0;
  return result;
}

//----- (0058F130) --------------------------------------------------------  // acclient.c:439761
int __thiscall CACQualities::InqLoad(CACQualities *this, float *load)
{
  CBaseQualities *v2; // edi@1
  int v3; // esi@1
  const int v4; // ebx@1
  int encumb_augmentations; // [sp+Ch] [bp-Ch]@1
  unsigned int strength; // [sp+10h] [bp-8h]@1
  int encumb_val; // [sp+14h] [bp-4h]@1

  strength = 10;
  encumb_val = 0;
  v2 = (CBaseQualities *)&this->vfptr;
  v3 = CACQualities::InqAttribute(this, 1u, &strength, 0) | 1;
  encumb_augmentations = 0;
  CBaseQualities::InqInt(v2, 0xE6u, &encumb_augmentations, 0, 0);
  v4 = EncumbranceSystem::EncumbranceCapacity(strength, encumb_augmentations);
  CBaseQualities::InqInt(v2, 5u, &encumb_val, 0, 0);
  *load = EncumbranceSystem::Load(v4, encumb_val);
  return v3;
}

//----- (0058F1C0) --------------------------------------------------------  // acclient.c:439783
void __thiscall BodyPart::BodyPart(BodyPart *this)
{
  this->vfptr = (PackObjVtbl *)&BodyPart::vftable;
  this->_dtype = 0;
  this->_dval = 0;
  LODWORD(this->_dvar) = 0;
  this->_acache.vfptr = (PackObjVtbl *)&ArmorCache::vftable;
  this->_acache._base_armor = 0;
  this->_acache._armor_vs_slash = 0;
  this->_acache._armor_vs_pierce = 0;
  this->_acache._armor_vs_bludgeon = 0;
  this->_acache._armor_vs_cold = 0;
  this->_acache._armor_vs_fire = 0;
  this->_acache._armor_vs_acid = 0;
  this->_acache._armor_vs_electric = 0;
  this->_acache._armor_vs_nether = 0;
  this->_bh = 0;
  this->_bpsd = 0;
}
// 7E436C: using guessed type int (__thiscall *ArmorCache::vftable)(void *, char);
// 7E4380: using guessed type int (__thiscall *BodyPart::vftable)(void *, char);

//----- (0058F200) --------------------------------------------------------  // acclient.c:439806
BodyPart *__thiscall BodyPart::vector_deleting_destructor(BodyPart *this, unsigned int a2)
{
  BodyPart *v2; // esi@1

  v2 = this;
  BodyPart::~BodyPart(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0058F220) --------------------------------------------------------  // acclient.c:439818
void __thiscall CACQualities::AddSpell(CACQualities *this, const unsigned int newSpell)
{
  CACQualities *v2; // esi@1
  CSpellBook *v3; // eax@1
  CSpellBook *v4; // eax@2
  CSpellBook *v5; // eax@3
  SpellBookPage page; // [sp+4h] [bp-8h]@1

  v2 = this;
  v3 = this->_spell_book;
  page.vfptr = (PackObjVtbl *)&SpellBookPage::vftable;
  LODWORD(page._casting_likelihood) = 0;
  if ( v3
    || ((v4 = (CSpellBook *)operator new(0x18u)) == 0 ? (v5 = 0) : CSpellBook::CSpellBook(v4),
        (v2->_spell_book = v5) != 0) )
    CSpellBook::AddSpell(v2->_spell_book, newSpell, &page);
}
// 7E4394: using guessed type int (__thiscall *SpellBookPage::vftable)(void *, char);

//----- (0058F280) --------------------------------------------------------  // acclient.c:439838
int __thiscall CACQualities::RemoveSpell(CACQualities *this, const unsigned int spell)
{
  CSpellBook *v2; // ecx@1
  int result; // eax@2
  SpellBookPage dummy; // [sp+0h] [bp-8h]@1

  v2 = this->_spell_book;
  dummy.vfptr = (PackObjVtbl *)&SpellBookPage::vftable;
  LODWORD(dummy._casting_likelihood) = 0;
  if ( v2 )
    result = CSpellBook::RemoveSpell(v2, spell, &dummy);
  else
    result = 0;
  return result;
}
// 7E4394: using guessed type int (__thiscall *SpellBookPage::vftable)(void *, char);

//----- (0058F2C0) --------------------------------------------------------  // acclient.c:439856
void __thiscall PackableHashTable<long,BodyPart>::EmptyContents(PackableHashTable<long,BodyPart> *this)
{
  PackableHashTable<long,BodyPart> *v1; // ebx@1
  unsigned int v2; // ebp@2
  PackableHashData<long,BodyPart> *v3; // esi@3
  PackableHashData<long,BodyPart> *v4; // edi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            BodyPart::~BodyPart(&v3->_data);
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}

//----- (0058F320) --------------------------------------------------------  // acclient.c:439892
int __thiscall PackableHashTable<long,BodyPart>::add(PackableHashTable<long,BodyPart> *this, const int *key, BodyPart *data)
{
  PackableHashTable<long,BodyPart> *v3; // edi@1
  unsigned int v4; // esi@1
  PackableHashData<long,BodyPart> **v5; // ebx@2
  PackableHashData<long,BodyPart> *v6; // edx@3
  void *v7; // esi@8
  unsigned int v8; // ebx@9
  const unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[*key % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( *key != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<long,BodyPart> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x4Cu);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      BodyPart::BodyPart((BodyPart *)((char *)v7 + 4), data);
      *((_DWORD *)v7 + 17) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 18) = v9;
      *((_DWORD *)v7 + 17) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<long,BodyPart> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (0058F3C0) --------------------------------------------------------  // acclient.c:439940
signed int __thiscall PackableHashTable<long,BodyPart>::Pack(PackableHashTable<long,BodyPart> *this, void **addr, unsigned int size)
{
  PackableHashTable<long,BodyPart> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<long,BodyPart> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<long,BodyPart>::pack_size(this);
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
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
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

//----- (0058F450) --------------------------------------------------------  // acclient.c:439991
signed int __thiscall PackableHashTable<long,BodyPart>::pack_size(PackableHashTable<long,BodyPart> *this)
{
  PackableHashTable<long,BodyPart> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<long,BodyPart> *i; // esi@2
  int v6; // eax@3
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
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (0058F4B0) --------------------------------------------------------  // acclient.c:440023
int __thiscall PackableList<CreationProfile>::InsertTail(PackableList<CreationProfile> *this, CreationProfile *val)
{
  PackableList<CreationProfile> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<CreationProfile> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x24u);
  if ( v3 )
  {
    CreationProfile::CreationProfile((CreationProfile *)v3, val);
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<CreationProfile> *)v3;
    *((_DWORD *)v3 + 8) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<CreationProfile> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<CreationProfile> *)v3;
    v2->tail = (PackableLLNode<CreationProfile> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (0058F520) --------------------------------------------------------  // acclient.c:440066
signed int __thiscall PackableList<CreationProfile>::Pack(PackableList<CreationProfile> *this, void **addr, unsigned int size)
{
  PackableList<CreationProfile> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<CreationProfile> *i; // esi@4

  v3 = this;
  v4 = PackableList<CreationProfile>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<CreationProfile> *, void **, unsigned int))i->data.vfptr->Pack)(
        i,
        addr,
        size);
  }
  return v4;
}

//----- (0058F570) --------------------------------------------------------  // acclient.c:440091
signed int __thiscall PackableList<CreationProfile>::pack_size(PackableList<CreationProfile> *this)
{
  PackableLLNode<CreationProfile> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<CreationProfile> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (0058F5B0) --------------------------------------------------------  // acclient.c:440110
void __thiscall PackableHashTable<long,BodyPart>::~PackableHashTable<long,BodyPart>(PackableHashTable<long,BodyPart> *this)
{
  PackableHashTable<long,BodyPart> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<long,BodyPart>::vftable;
  PackableHashTable<long,BodyPart>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E43A8: using guessed type int (__thiscall *PackableHashTable<long,BodyPart>::vftable)(void *, char);

//----- (0058F5F0) --------------------------------------------------------  // acclient.c:440129
int __thiscall PackableHashTable<long,BodyPart>::UnPack(PackableHashTable<long,BodyPart> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<long,BodyPart> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void *v12; // eax@12
  PackObjVtbl *v13; // edx@12
  BodyPart *v14; // ecx@16
  void *start_addr; // [sp+8h] [bp-48h]@3
  unsigned int blob_size; // [sp+Ch] [bp-44h]@3
  BodyPart tempData; // [sp+10h] [bp-40h]@10

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<long,BodyPart>::EmptyContents(this);
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
    BodyPart::BodyPart(&tempData);
    size = 0;
    if ( v11 )
    {
      while ( (unsigned int)v10 >= 4 )
      {
        v12 = *v6;
        v13 = tempData.vfptr;
        addr = *(void ***)*v6;
        *v6 = (char *)v12 + 4;
        if ( !((int (__thiscall *)(BodyPart *, void **, int))v13->UnPack)(&tempData, v6, v10)
          || !PackableHashTable<long,BodyPart>::add(v4, (const int *)&addr, &tempData)
          && !v4->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++size;
        if ( size >= v11 )
          goto LABEL_16;
      }
      v14 = &tempData;
    }
    else
    {
LABEL_16:
      v14 = &tempData;
      if ( blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr )
      {
        BodyPart::~BodyPart(&tempData);
        return 1;
      }
    }
    BodyPart::~BodyPart(v14);
  }
  return 0;
}

//----- (0058F730) --------------------------------------------------------  // acclient.c:440209
PackableHashTable<long,BodyPart> *__thiscall PackableHashTable<long,BodyPart>::scalar_deleting_destructor(PackableHashTable<long,BodyPart> *this, unsigned int a2)
{
  PackableHashTable<long,BodyPart> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<long,BodyPart>::vftable;
  PackableHashTable<long,BodyPart>::EmptyContents(this);
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
// 7E43A8: using guessed type int (__thiscall *PackableHashTable<long,BodyPart>::vftable)(void *, char);

//----- (0058F780) --------------------------------------------------------  // acclient.c:440231
void __thiscall Body::Body(Body *this)
{
  Body *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->_body_part_table;
  v1->vfptr = (PackObjVtbl *)&Body::vftable;
  *(_DWORD *)v2 = &PackableHashTable<long,BodyPart>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 32;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
}
// 7E43A8: using guessed type int (__thiscall *PackableHashTable<long,BodyPart>::vftable)(void *, char);
// 7E43D0: using guessed type int (__thiscall *Body::vftable)(void *, char);

//----- (0058F7B0) --------------------------------------------------------  // acclient.c:440250
void __thiscall PackableList<CreationProfile>::Flush(PackableList<CreationProfile> *this)
{
  PackableList<CreationProfile> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  CreationProfile dummyData; // [sp+8h] [bp-1Ch]@1

  v1 = this;
  CreationProfile::CreationProfile(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 28);
      v1->head = (PackableLLNode<CreationProfile> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 32) = 0;
      else
        v1->tail = 0;
      CreationProfile::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackObj::vftable;
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0058F820) --------------------------------------------------------  // acclient.c:440283
Body *__thiscall Body::scalar_deleting_destructor(Body *this, unsigned int a2)
{
  Body *v2; // esi@1

  v2 = this;
  PackableHashTable<long,BodyPart>::~PackableHashTable<long,BodyPart>(&this->_body_part_table);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (0058F850) --------------------------------------------------------  // acclient.c:440297
int __thiscall CACQualities::InqPluralNameString(CACQualities *this, AC1Legacy::PStringBase<char> *pluralName)
{
  int v2; // ebx@1
  volatile LONG *v3; // ebp@1
  CACQualities *v4; // esi@1
  CBaseQualities *v5; // esi@1
  AC1Legacy::PSRefBuffer<char> *v6; // esi@2
  AC1Legacy::PSRefBuffer<char> *v7; // eax@2
  AC1Legacy::PSRefBuffer<char> *v8; // eax@6
  AC1Legacy::PSRefBuffer<char> *v9; // esi@7
  unsigned int v11; // eax@14
  int v12; // edx@14
  bool v13; // cf@14
  char *v14; // eax@14
  AC1Legacy::PSRefBuffer<char> *v15; // esi@17
  char v16; // al@24
  AC1Legacy::PStringBase<char> *v17; // eax@26
  AC1Legacy::PStringBase<char> *v18; // eax@27
  AC1Legacy::PSRefBuffer<char> *v19; // esi@27
  AC1Legacy::PSRefBuffer<char> *v20; // esi@30
  AC1Legacy::PStringBase<char> item_name; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> msg; // [sp+14h] [bp-4h]@1

  v2 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v4 = this;
  msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  item_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v5 = (CBaseQualities *)&v4->vfptr;
  if ( CBaseQualities::InqString(v5, 0x14u, &item_name) )
  {
    v6 = pluralName->m_buffer;
    v7 = item_name.m_buffer;
    if ( pluralName->m_buffer != item_name.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      v8 = item_name.m_buffer;
      pluralName->m_buffer = item_name.m_buffer;
      InterlockedIncrement((volatile LONG *)&v8->m_cRef);
      v7 = item_name.m_buffer;
    }
    v9 = v7;
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && msg.m_buffer )
    {
      ((void (__stdcall *)(signed int))msg.m_buffer->vfptr->__vecDelDtor)(1);
      return 1;
    }
    return 1;
  }
  if ( CBaseQualities::InqString(v5, 1u, &item_name) )
  {
    v11 = item_name.m_buffer->m_len;
    v12 = v11 - 1;
    v13 = v11 - 1 < v11;
    v14 = (char *)&item_name.m_buffer->m_hash + v11 + 3;
    if ( v13 )
      v14 = &item_name.m_buffer->m_data[v12];
    if ( v14 )
    {
      v16 = *v14;
      if ( v16 == 115 || v16 == 120 )
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(&msg, "es");
        AC1Legacy::PStringBase<char>::operator+=(&item_name, v18);
        v19 = msg.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) && v19 )
          v19->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v19, 1u);
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>(&msg, "s");
        AC1Legacy::PStringBase<char>::operator+=(&item_name, v17);
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&msg);
      }
      AC1Legacy::PStringBase<unsigned short>::operator=(
        (AC1Legacy::PStringBase<unsigned short> *)pluralName,
        (AC1Legacy::PStringBase<unsigned short> *)&item_name);
      v20 = item_name.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&item_name.m_buffer->m_cRef) && v20 )
        v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
      if ( !InterlockedDecrement(v3) && v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
      return 1;
    }
  }
  AC1Legacy::PStringBase<char>::set(pluralName, "items");
  v15 = item_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&item_name.m_buffer->m_cRef) && v15 )
    v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
  if ( !InterlockedDecrement(v3) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0058FA50) --------------------------------------------------------  // acclient.c:440398
int __thiscall PackableList<CreationProfile>::UnPack(PackableList<CreationProfile> *this, void **addr, unsigned int size)
{
  PackableList<CreationProfile> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  CreationProfile temp; // [sp+8h] [bp-1Ch]@2

  v3 = this;
  PackableList<CreationProfile>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    CreationProfile::CreationProfile(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(CreationProfile *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<CreationProfile>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}

//----- (0058FAD0) --------------------------------------------------------  // acclient.c:440439
PackableList<CreationProfile> *__thiscall PackableList<CreationProfile>::scalar_deleting_destructor(PackableList<CreationProfile> *this, unsigned int a2)
{
  PackableList<CreationProfile> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<CreationProfile>::vftable;
  PackableList<CreationProfile>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E43BC: using guessed type int (__thiscall *PackableList<CreationProfile>::vftable)(void *, char);

//----- (0070AA20) --------------------------------------------------------  // acclient.c:797858
void sub_70AA20()
{
  flt_870F90 = 1000.0 + 1.0;
}

//----- (0070AA40) --------------------------------------------------------  // acclient.c:797864
void sub_70AA40()
{
  flt_870F94 = 24.0 * 8.0;
}

//----- (0070AA60) --------------------------------------------------------  // acclient.c:797870
void sub_70AA60()
{
  flt_870F98 = 24.0 * 0.5;
}

//----- (0070AA80) --------------------------------------------------------  // acclient.c:797876
int sub_70AA80()
{
  return atexit(nullsub_1420);
}

