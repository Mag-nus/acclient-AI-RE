/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PlayerModule
   Object     : AC\acplayermod\PlayerModule.obj
   Functions  : 154
   Addresses  : 00401C80 - 007104C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00401C80) --------------------------------------------------------  // acclient.c:61516
unsigned int __thiscall PlayerModule::GetSpellbookFilters(PlayerModule *this)
{
  return this->spell_filters_;
}

//----- (00401C90) --------------------------------------------------------  // acclient.c:61522
void __thiscall Client::SetPortA(PlayerModule *this, unsigned int filters)
{
  this->spell_filters_ = filters;
}

//----- (004F0E90) --------------------------------------------------------  // acclient.c:285123
ShortCutManager *__thiscall CInputManager::GetMouseX(PlayerModule *this)
{
  return this->shortcuts_;
}

//----- (004FDB70) --------------------------------------------------------  // acclient.c:297869
signed int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::Pack(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, void **addr, unsigned int size)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v3; // ebx@1
  signed int result; // eax@1
  char *v5; // esi@2
  unsigned int v6; // ebp@2
  char *v7; // edi@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> *i; // edx@3
  char *v9; // edi@5
  char *v10; // esi@5

  v3 = this;
  result = PackableHashTable<unsigned long,int>::pack_size(this);
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = 0;
    v7 = v5;
    if ( v3->_table_size )
    {
      do
      {
        for ( i = v3->_buckets[v6]; i; i = i->_next )
        {
          if ( size >= 4 )
          {
            *(_DWORD *)v7 = i->_key.id;
            v9 = (char *)*addr + 4;
            *addr = v9;
            *(_DWORD *)v9 = i->_data;
            v10 = (char *)*addr + 4;
            *addr = v10;
            v7 = v10;
          }
        }
        ++v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (0052D370) --------------------------------------------------------  // acclient.c:349045
int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, IDClass<_tagDataID,32,0> *key, const int *data)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v5; // ebx@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v6; // edx@3
  void *v7; // eax@8
  unsigned int v8; // edi@9
  unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[key->id % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( key->id != v6->_key.id )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<IDClass<_tagDataID,32,0>,long> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x10u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = key->id;
      *((_DWORD *)v7 + 1) = *data;
      *((_DWORD *)v7 + 2) = 0;
      v9 = key->id % v8;
      *((_DWORD *)v7 + 3) = v9;
      *((_DWORD *)v7 + 2) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<IDClass<_tagDataID,32,0>,long> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}

//----- (0052EF90) --------------------------------------------------------  // acclient.c:351267
void __thiscall PackableHashTable<unsigned long,unsigned long>::EmptyContents(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v3; // eax@3
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v4; // esi@4

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

//----- (00569340) --------------------------------------------------------  // acclient.c:406032
signed int __thiscall PackableHashTable<unsigned long,int>::pack_size(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this)
{
  unsigned int v1; // edx@1
  signed int result; // eax@1
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v3; // esi@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> *i; // ecx@3

  v1 = this->_table_size;
  result = 4;
  if ( v1 )
  {
    v3 = this->_buckets;
    do
    {
      for ( i = *v3; i; result += 8 )
        i = i->_next;
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  return result;
}

//----- (00590250) --------------------------------------------------------  // acclient.c:441046
void __thiscall PackableHashTable<unsigned long,unsigned long>::Destroy(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v1; // esi@1

  v1 = this;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
}

//----- (005BC050) --------------------------------------------------------  // acclient.c:487105
int __thiscall PackableHashTable<unsigned long,CContractTracker>::Init(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v1; // esi@1
  unsigned int v2; // eax@2
  void *v3; // eax@3
  unsigned int v5; // eax@5

  v1 = this;
  if ( this->_buckets )
    return 0;
  v2 = this->_table_size;
  if ( v2 )
  {
    v3 = operator new[](4 * v2);
    v1->_buckets = (PackableHashData<IDClass<_tagDataID,32,0>,long> **)v3;
    if ( !v3 )
      return 0;
    v5 = 0;
    if ( v1->_table_size )
    {
      do
        v1->_buckets[v5++] = 0;
      while ( v5 < v1->_table_size );
    }
  }
  return 1;
}

//----- (005D29A0) --------------------------------------------------------  // acclient.c:510942
bool __thiscall PlayerModule::AddShortCut(PlayerModule *this, ShortCutData *scData)
{
  PlayerModule *v2; // esi@1
  ShortCutManager *v3; // eax@2
  ShortCutManager *v4; // eax@3

  v2 = this;
  if ( !this->shortcuts_ )
  {
    v3 = (ShortCutManager *)operator new(0x4Cu);
    if ( v3 )
      ShortCutManager::ShortCutManager(v3);
    else
      v4 = 0;
    v2->shortcuts_ = v4;
  }
  return ShortCutManager::AddShortCut(v2->shortcuts_, scData) != 0;
}

//----- (005D29E0) --------------------------------------------------------  // acclient.c:510962
void __thiscall PlayerModule::RemoveShortCut(PlayerModule *this, const int index)
{
  ShortCutManager *v2; // ecx@1

  v2 = this->shortcuts_;
  if ( v2 )
    ShortCutManager::RemoveShortCut(v2, index);
}

//----- (005D29F0) --------------------------------------------------------  // acclient.c:510972
PackableList<unsigned long> *__thiscall PlayerModule::GetFavoriteSpellsList(PlayerModule *this, const int list)
{
  return &this->favorite_spells_[list];
}

//----- (005D2A00) --------------------------------------------------------  // acclient.c:510978
void __thiscall PlayerModule::ClearDesiredCompList(PlayerModule *this)
{
  PlayerModule *v1; // esi@1
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // ecx@1

  v1 = this;
  v2 = this->desired_comps_;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->desired_comps_ = 0;
}

//----- (005D2A20) --------------------------------------------------------  // acclient.c:510991
unsigned int __thiscall PlayerModule::AllowGive(PlayerModule *this)
{
  return (this->options_ >> 6) & 1;
}

//----- (005D2A30) --------------------------------------------------------  // acclient.c:510997
char __stdcall PlayerModule::GetDefaultOptionValue(PlayerOption po)
{
  char result; // al@2

  switch ( po )
  {
    case 0u:
    case 2u:
    case 6u:
    case 8u:
    case 0xAu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x14u:
    case 0x15u:
    case 0x19u:
    case 0x1Bu:
    case 0x23u:
    case 0x24u:
    case 0x25u:
    case 0x2Au:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005D2A90) --------------------------------------------------------  // acclient.c:511029
unsigned int __thiscall PlayerModule::AutoRepeatAttack(PlayerModule *this)
{
  return (this->options_ >> 1) & 1;
}

//----- (005D2AA0) --------------------------------------------------------  // acclient.c:511035
void __thiscall PlayerModule::SetAutoRepeatAttack(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 1) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 2;
    else
      v3 = v2 & 0xFFFFFFFD;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(0);
  }
}

//----- (005D2AE0) --------------------------------------------------------  // acclient.c:511053
unsigned int __thiscall PlayerModule::IgnoreAllegianceRequests(PlayerModule *this)
{
  return (this->options_ >> 2) & 1;
}

//----- (005D2AF0) --------------------------------------------------------  // acclient.c:511059
void __thiscall PlayerModule::SetIgnoreAllegianceRequests(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 2) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 4;
    else
      v3 = v2 & 0xFFFFFFFB;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(1);
  }
}

//----- (005D2B30) --------------------------------------------------------  // acclient.c:511077
unsigned int __thiscall PlayerModule::IgnoreFellowshipRequests(PlayerModule *this)
{
  return (this->options_ >> 3) & 1;
}

//----- (005D2B40) --------------------------------------------------------  // acclient.c:511083
void __thiscall PlayerModule::SetIgnoreFellowshipRequests(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 3) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 8;
    else
      v3 = v2 & 0xFFFFFFF7;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(2);
  }
}

//----- (005D2B80) --------------------------------------------------------  // acclient.c:511101
unsigned int __thiscall PlayerModule::IgnoreTradeRequests(PlayerModule *this)
{
  return (this->options_ >> 17) & 1;
}

//----- (005D2B90) --------------------------------------------------------  // acclient.c:511107
void __thiscall PlayerModule::SetIgnoreTradeRequests(PlayerModule *this, bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 17) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x20000;
    else
      v3 = v2 & 0xFFFDFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(3);
  }
}

//----- (005D2BD0) --------------------------------------------------------  // acclient.c:511125
int __thiscall PlayerModule::DisableMostWeatherEffects(PlayerModule *this)
{
  return BYTE2(this->options_) & 1;
}

//----- (005D2BE0) --------------------------------------------------------  // acclient.c:511131
void __thiscall PlayerModule::SetDisableMostWeatherEffects(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( (BYTE2(this->options_) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x10000;
    else
      v3 = v2 & 0xFFFEFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(4);
  }
}

//----- (005D2C20) --------------------------------------------------------  // acclient.c:511149
unsigned int __thiscall PlayerModule::PersistentAtDay(PlayerModule *this)
{
  return this->options2_ & 1;
}

//----- (005D2C30) --------------------------------------------------------  // acclient.c:511155
void __thiscall PlayerModule::SetPersistentAtDay(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( (this->options2_ & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 1;
    else
      v3 = v2 & 0xFFFFFFFE;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(5);
  }
}

//----- (005D2C70) --------------------------------------------------------  // acclient.c:511173
void __thiscall PlayerModule::SetAllowGive(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 6) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x40;
    else
      v3 = v2 & 0xFFFFFFBF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(6);
  }
}

//----- (005D2CB0) --------------------------------------------------------  // acclient.c:511191
unsigned int __thiscall PlayerModule::ViewCombatTarget(PlayerModule *this)
{
  return (this->options_ >> 7) & 1;
}

//----- (005D2CC0) --------------------------------------------------------  // acclient.c:511197
void __thiscall PlayerModule::SetViewCombatTarget(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 7) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x80;
    else
      v3 = v2 & 0xFFFFFF7F;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(7);
  }
}

//----- (005D2D00) --------------------------------------------------------  // acclient.c:511215
unsigned int __thiscall PlayerModule::ShowTooltips(PlayerModule *this)
{
  return (this->options_ >> 8) & 1;
}

//----- (005D2D10) --------------------------------------------------------  // acclient.c:511221
void __thiscall PlayerModule::SetShowTooltips(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((LOWORD(this->options_) >> 8) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x100;
    else
      v3 = v2 & 0xFFFFFEFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(8);
  }
}

//----- (005D2D50) --------------------------------------------------------  // acclient.c:511239
unsigned int __thiscall PlayerModule::UseDeception(PlayerModule *this)
{
  return (this->options_ >> 9) & 1;
}

//----- (005D2D60) --------------------------------------------------------  // acclient.c:511245
void __thiscall PlayerModule::SetUseDeception(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 9) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x200;
    else
      v3 = v2 & 0xFFFFFDFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(9);
  }
}

//----- (005D2DA0) --------------------------------------------------------  // acclient.c:511263
unsigned int __thiscall PlayerModule::ToggleRun(PlayerModule *this)
{
  return (this->options_ >> 10) & 1;
}

//----- (005D2DB0) --------------------------------------------------------  // acclient.c:511269
void __thiscall PlayerModule::SetToggleRun(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 10) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x400;
    else
      v3 = v2 & 0xFFFFFBFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(10);
  }
}

//----- (005D2DF0) --------------------------------------------------------  // acclient.c:511287
unsigned int __thiscall PlayerModule::StayInChatMode(PlayerModule *this)
{
  return (this->options_ >> 11) & 1;
}

//----- (005D2E00) --------------------------------------------------------  // acclient.c:511293
void __thiscall PlayerModule::SetStayInChatMode(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 11) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x800;
    else
      v3 = v2 & 0xFFFFF7FF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(11);
  }
}

//----- (005D2E40) --------------------------------------------------------  // acclient.c:511311
unsigned int __thiscall PlayerModule::AdvancedCombatUI(PlayerModule *this)
{
  return (this->options_ >> 12) & 1;
}

//----- (005D2E50) --------------------------------------------------------  // acclient.c:511317
void __thiscall PlayerModule::SetAdvancedCombatUI(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 12) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x1000;
    else
      v3 = v2 & 0xFFFFEFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(12);
  }
}

//----- (005D2E90) --------------------------------------------------------  // acclient.c:511335
unsigned int __thiscall PlayerModule::AutoTarget(PlayerModule *this)
{
  return (this->options_ >> 13) & 1;
}

//----- (005D2EA0) --------------------------------------------------------  // acclient.c:511341
void __thiscall PlayerModule::SetAutoTarget(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 13) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x2000;
    else
      v3 = v2 & 0xFFFFDFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(13);
  }
}

//----- (005D2EE0) --------------------------------------------------------  // acclient.c:511359
unsigned int __thiscall PlayerModule::VividTargetingIndicator(PlayerModule *this)
{
  return (this->options_ >> 15) & 1;
}

//----- (005D2EF0) --------------------------------------------------------  // acclient.c:511365
void __thiscall PlayerModule::SetVividTargetingIndicator(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 15) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x8000;
    else
      v3 = v2 & 0xFFFF7FFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(14);
  }
}

//----- (005D2F30) --------------------------------------------------------  // acclient.c:511383
unsigned int __thiscall PlayerModule::FellowshipShareXP(PlayerModule *this)
{
  return (this->options_ >> 18) & 1;
}

//----- (005D2F40) --------------------------------------------------------  // acclient.c:511389
void __thiscall PlayerModule::SetFellowshipShareXP(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 18) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x40000;
    else
      v3 = v2 & 0xFFFBFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(15);
  }
}

//----- (005D2F80) --------------------------------------------------------  // acclient.c:511407
unsigned int __thiscall PlayerModule::AcceptLootPermits(PlayerModule *this)
{
  return (this->options_ >> 19) & 1;
}

//----- (005D2F90) --------------------------------------------------------  // acclient.c:511413
void __thiscall PlayerModule::SetAcceptLootPermits(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 19) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x80000;
    else
      v3 = v2 & 0xFFF7FFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(16);
  }
}

//----- (005D2FD0) --------------------------------------------------------  // acclient.c:511431
unsigned int __thiscall PlayerModule::FellowshipShareLoot(PlayerModule *this)
{
  return (this->options_ >> 20) & 1;
}

//----- (005D2FE0) --------------------------------------------------------  // acclient.c:511437
void __thiscall PlayerModule::SetFellowshipShareLoot(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 20) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x100000;
    else
      v3 = v2 & 0xFFEFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(17);
  }
}

//----- (005D3020) --------------------------------------------------------  // acclient.c:511455
unsigned int __thiscall PlayerModule::FellowshipAutoAcceptRequests(PlayerModule *this)
{
  return (this->options_ >> 29) & 1;
}

//----- (005D3030) --------------------------------------------------------  // acclient.c:511461
void __thiscall PlayerModule::SetFellowshipAutoAcceptRequests(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 29) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x20000000;
    else
      v3 = v2 & 0xDFFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(18);
  }
}

//----- (005D3070) --------------------------------------------------------  // acclient.c:511479
unsigned int __thiscall PlayerModule::SideBySideVitals(PlayerModule *this)
{
  return (this->options_ >> 21) & 1;
}

//----- (005D3080) --------------------------------------------------------  // acclient.c:511485
void __thiscall PlayerModule::SetSideBySideVitals(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 21) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x200000;
    else
      v3 = v2 & 0xFFDFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(19);
  }
}

//----- (005D30C0) --------------------------------------------------------  // acclient.c:511503
unsigned int __thiscall PlayerModule::CoordinatesOnRadar(PlayerModule *this)
{
  return (this->options_ >> 22) & 1;
}

//----- (005D30D0) --------------------------------------------------------  // acclient.c:511509
void __thiscall PlayerModule::SetCoordinatesOnRadar(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 22) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x400000;
    else
      v3 = v2 & 0xFFBFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(20);
  }
}

//----- (005D3110) --------------------------------------------------------  // acclient.c:511527
unsigned int __thiscall PlayerModule::SpellDuration(PlayerModule *this)
{
  return (this->options_ >> 23) & 1;
}

//----- (005D3120) --------------------------------------------------------  // acclient.c:511533
void __thiscall PlayerModule::SetSpellDuration(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 23) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | v2;
    else
      v3 = v2 & 0xFF7FFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(21);
  }
}

//----- (005D3160) --------------------------------------------------------  // acclient.c:511551
unsigned int __thiscall PlayerModule::DisableHouseRestrictionEffects(PlayerModule *this)
{
  return (this->options_ >> 25) & 1;
}

//----- (005D3170) --------------------------------------------------------  // acclient.c:511557
void __thiscall PlayerModule::SetDisableHouseRestrictionEffects(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 25) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x2000000;
    else
      v3 = v2 & 0xFDFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(22);
  }
}

//----- (005D31B0) --------------------------------------------------------  // acclient.c:511575
unsigned int __thiscall PlayerModule::DragItemOnPlayerOpensSecureTrade(PlayerModule *this)
{
  return (this->options_ >> 26) & 1;
}

//----- (005D31C0) --------------------------------------------------------  // acclient.c:511581
void __thiscall PlayerModule::SetDragItemOnPlayerOpensSecureTrade(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 26) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x4000000;
    else
      v3 = v2 & 0xFBFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(23);
  }
}

//----- (005D3200) --------------------------------------------------------  // acclient.c:511599
unsigned int __thiscall PlayerModule::DisplayAllegianceLogonNotifications(PlayerModule *this)
{
  return (this->options_ >> 27) & 1;
}

//----- (005D3210) --------------------------------------------------------  // acclient.c:511605
void __thiscall PlayerModule::SetDisplayAllegianceLogonNotifications(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 27) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x8000000;
    else
      v3 = v2 & 0xF7FFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(24);
  }
}

//----- (005D3250) --------------------------------------------------------  // acclient.c:511623
unsigned int __thiscall PlayerModule::UseChargeAttack(PlayerModule *this)
{
  return (this->options_ >> 28) & 1;
}

//----- (005D3260) --------------------------------------------------------  // acclient.c:511629
void __thiscall PlayerModule::SetUseChargeAttack(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 28) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x10000000;
    else
      v3 = v2 & 0xEFFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(25);
  }
}

//----- (005D32A0) --------------------------------------------------------  // acclient.c:511647
unsigned int __thiscall PlayerModule::ShowHelm(PlayerModule *this)
{
  return (this->options2_ >> 20) & 1;
}

//----- (005D32B0) --------------------------------------------------------  // acclient.c:511653
void __thiscall PlayerModule::SetShowHelm(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 20) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x100000;
    else
      v3 = v2 & 0xFFEFFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(47);
  }
}

//----- (005D32F0) --------------------------------------------------------  // acclient.c:511671
void __thiscall PlayerModule::SetShowCloak(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 23) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" | v2;
    else
      v3 = v2 & 0xFF7FFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(50);
  }
}

//----- (005D3330) --------------------------------------------------------  // acclient.c:511689
int __thiscall PlayerModule::LockUI(PlayerModule *this)
{
  return BYTE3(this->options2_) & 1;
}

//----- (005D3340) --------------------------------------------------------  // acclient.c:511695
void __thiscall PlayerModule::SetLockUI(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( (BYTE3(this->options2_) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x1000000;
    else
      v3 = v2 & 0xFEFFFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(51);
  }
}

//----- (005D3380) --------------------------------------------------------  // acclient.c:511713
unsigned int __thiscall PlayerModule::UseMouseTurning(PlayerModule *this)
{
  return (this->options2_ >> 22) & 1;
}

//----- (005D3390) --------------------------------------------------------  // acclient.c:511719
void __thiscall PlayerModule::SetUseMouseTurning(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 22) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x400000;
    else
      v3 = v2 & 0xFFBFFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(49);
  }
}

//----- (005D33D0) --------------------------------------------------------  // acclient.c:511737
unsigned int __thiscall PlayerModule::DisableDistanceFog(PlayerModule *this)
{
  return (this->options2_ >> 21) & 1;
}

//----- (005D33E0) --------------------------------------------------------  // acclient.c:511743
void __thiscall PlayerModule::SetDisableDistanceFog(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 21) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x200000;
    else
      v3 = v2 & 0xFFDFFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(48);
  }
}

//----- (005D3420) --------------------------------------------------------  // acclient.c:511761
unsigned int __thiscall PlayerModule::LeadMissileTargets(PlayerModule *this)
{
  return (this->options2_ >> 15) & 1;
}

//----- (005D3430) --------------------------------------------------------  // acclient.c:511767
void __thiscall PlayerModule::SetLeadMissileTargets(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 15) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x8000;
    else
      v3 = v2 & 0xFFFF7FFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(42);
  }
}

//----- (005D3470) --------------------------------------------------------  // acclient.c:511785
int __thiscall PlayerModule::UseFastMissiles(PlayerModule *this)
{
  return BYTE2(this->options2_) & 1;
}

//----- (005D3480) --------------------------------------------------------  // acclient.c:511791
void __thiscall PlayerModule::SetUseFastMissiles(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( (BYTE2(this->options2_) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x10000;
    else
      v3 = v2 & 0xFFFEFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(43);
  }
}

//----- (005D34C0) --------------------------------------------------------  // acclient.c:511809
unsigned int __thiscall PlayerModule::UseCraftSuccessDialog(PlayerModule *this)
{
  return this->options_ >> 31;
}

//----- (005D34D0) --------------------------------------------------------  // acclient.c:511815
void __thiscall PlayerModule::SetUseCraftSuccessDialog(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 31) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x80000000;
    else
      v3 = v2 & 0x7FFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(26);
  }
}

//----- (005D3510) --------------------------------------------------------  // acclient.c:511833
unsigned int __thiscall PlayerModule::ConfirmVolatileRareUse(PlayerModule *this)
{
  return (this->options2_ >> 18) & 1;
}

//----- (005D3520) --------------------------------------------------------  // acclient.c:511839
void __thiscall PlayerModule::SetConfirmVolatileRareUse(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 18) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x40000;
    else
      v3 = v2 & 0xFFFBFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(45);
  }
}

//----- (005D3560) --------------------------------------------------------  // acclient.c:511857
unsigned int __thiscall PlayerModule::HearAllegianceChat(PlayerModule *this)
{
  return (this->options_ >> 30) & 1;
}

//----- (005D3570) --------------------------------------------------------  // acclient.c:511863
void __thiscall PlayerModule::SetHearAllegianceChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options_ >> 30) & 1) != on )
  {
    v2 = this->options_;
    if ( on )
      v3 = v2 | 0x40000000;
    else
      v3 = v2 & 0xBFFFFFFF;
    this->options_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(27);
  }
}

//----- (005D35B0) --------------------------------------------------------  // acclient.c:511881
unsigned int __thiscall PlayerModule::HearGeneralChat(PlayerModule *this)
{
  return (this->options2_ >> 8) & 1;
}

//----- (005D35C0) --------------------------------------------------------  // acclient.c:511887
void __thiscall PlayerModule::SetHearGeneralChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((LOWORD(this->options2_) >> 8) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x100;
    else
      v3 = v2 & 0xFFFFFEFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(35);
  }
}

//----- (005D3600) --------------------------------------------------------  // acclient.c:511905
unsigned int __thiscall PlayerModule::HearTradeChat(PlayerModule *this)
{
  return (this->options2_ >> 9) & 1;
}

//----- (005D3610) --------------------------------------------------------  // acclient.c:511911
void __thiscall PlayerModule::SetHearTradeChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 9) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x200;
    else
      v3 = v2 & 0xFFFFFDFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(36);
  }
}

//----- (005D3650) --------------------------------------------------------  // acclient.c:511929
unsigned int __thiscall PlayerModule::HearLFGChat(PlayerModule *this)
{
  return (this->options2_ >> 10) & 1;
}

//----- (005D3660) --------------------------------------------------------  // acclient.c:511935
void __thiscall PlayerModule::SetHearLFGChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 10) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x400;
    else
      v3 = v2 & 0xFFFFFBFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(37);
  }
}

//----- (005D36A0) --------------------------------------------------------  // acclient.c:511953
unsigned int __thiscall PlayerModule::HearRoleplayChat(PlayerModule *this)
{
  return (this->options2_ >> 11) & 1;
}

//----- (005D36B0) --------------------------------------------------------  // acclient.c:511959
void __thiscall PlayerModule::SetHearRoleplayChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 11) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x800;
    else
      v3 = v2 & 0xFFFFF7FF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(38);
  }
}

//----- (005D36F0) --------------------------------------------------------  // acclient.c:511977
unsigned int __thiscall PlayerModule::HearSocietyChat(PlayerModule *this)
{
  return (this->options2_ >> 19) & 1;
}

//----- (005D3700) --------------------------------------------------------  // acclient.c:511983
void __thiscall PlayerModule::SetHearSocietyChat(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 19) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x80000;
    else
      v3 = v2 & 0xFFF7FFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(46);
  }
}

//----- (005D3740) --------------------------------------------------------  // acclient.c:512001
void __thiscall PlayerModule::SetAppearOffline(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 12) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x1000;
    else
      v3 = v2 & 0xFFFFEFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(39);
  }
}

//----- (005D3780) --------------------------------------------------------  // acclient.c:512019
unsigned int __thiscall PlayerModule::DisplayDateOfBirth(PlayerModule *this)
{
  return (this->options2_ >> 1) & 1;
}

//----- (005D3790) --------------------------------------------------------  // acclient.c:512025
void __thiscall PlayerModule::SetDisplayDateOfBirth(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 1) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 2;
    else
      v3 = v2 & 0xFFFFFFFD;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(28);
  }
}

//----- (005D37D0) --------------------------------------------------------  // acclient.c:512043
unsigned int __thiscall PlayerModule::DisplayAge(PlayerModule *this)
{
  return (this->options2_ >> 5) & 1;
}

//----- (005D37E0) --------------------------------------------------------  // acclient.c:512049
void __thiscall PlayerModule::SetDisplayAge(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 5) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x20;
    else
      v3 = v2 & 0xFFFFFFDF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(29);
  }
}

//----- (005D3820) --------------------------------------------------------  // acclient.c:512067
unsigned int __thiscall PlayerModule::DisplayChessRank(PlayerModule *this)
{
  return (this->options2_ >> 2) & 1;
}

//----- (005D3830) --------------------------------------------------------  // acclient.c:512073
void __thiscall PlayerModule::SetDisplayChessRank(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 2) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 4;
    else
      v3 = v2 & 0xFFFFFFFB;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(30);
  }
}

//----- (005D3870) --------------------------------------------------------  // acclient.c:512091
unsigned int __thiscall PlayerModule::DisplayFishingSkill(PlayerModule *this)
{
  return (this->options2_ >> 3) & 1;
}

//----- (005D3880) --------------------------------------------------------  // acclient.c:512097
void __thiscall PlayerModule::SetDisplayFishingSkill(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 3) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 8;
    else
      v3 = v2 & 0xFFFFFFF7;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(31);
  }
}

//----- (005D38C0) --------------------------------------------------------  // acclient.c:512115
unsigned int __thiscall PlayerModule::DisplayNumberDeaths(PlayerModule *this)
{
  return (this->options2_ >> 4) & 1;
}

//----- (005D38D0) --------------------------------------------------------  // acclient.c:512121
void __thiscall PlayerModule::SetDisplayNumberDeaths(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 4) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x10;
    else
      v3 = v2 & 0xFFFFFFEF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(32);
  }
}

//----- (005D3910) --------------------------------------------------------  // acclient.c:512139
unsigned int __thiscall PlayerModule::DisplayNumberCharacterTitles(PlayerModule *this)
{
  return (this->options2_ >> 13) & 1;
}

//----- (005D3920) --------------------------------------------------------  // acclient.c:512145
void __thiscall PlayerModule::SetDisplayNumberCharacterTitles(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 13) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x2000;
    else
      v3 = v2 & 0xFFFFDFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(40);
  }
}

//----- (005D3960) --------------------------------------------------------  // acclient.c:512163
unsigned int __thiscall PlayerModule::FilterLanguage(PlayerModule *this)
{
  return (this->options2_ >> 17) & 1;
}

//----- (005D3970) --------------------------------------------------------  // acclient.c:512169
void __thiscall PlayerModule::SetFilterLanguage(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 17) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x20000;
    else
      v3 = v2 & 0xFFFDFFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(44);
  }
}

//----- (005D39B0) --------------------------------------------------------  // acclient.c:512187
unsigned int __thiscall PlayerModule::DisplayTimeStamps(PlayerModule *this)
{
  return (this->options2_ >> 6) & 1;
}

//----- (005D39C0) --------------------------------------------------------  // acclient.c:512193
void __thiscall PlayerModule::SetDisplayTimeStamps(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 6) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x40;
    else
      v3 = v2 & 0xFFFFFFBF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(33);
  }
}

//----- (005D3A00) --------------------------------------------------------  // acclient.c:512211
unsigned int __thiscall PlayerModule::SalvageMultiple(PlayerModule *this)
{
  return (this->options2_ >> 7) & 1;
}

//----- (005D3A10) --------------------------------------------------------  // acclient.c:512217
void __thiscall PlayerModule::SetSalvageMultiple(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 7) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x80;
    else
      v3 = v2 & 0xFFFFFF7F;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(34);
  }
}

//----- (005D3A50) --------------------------------------------------------  // acclient.c:512235
unsigned int __thiscall PlayerModule::MainPackPreferred(PlayerModule *this)
{
  return (this->options2_ >> 14) & 1;
}

//----- (005D3A60) --------------------------------------------------------  // acclient.c:512241
void __thiscall PlayerModule::SetMainPackPreferred(PlayerModule *this, const bool on)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3

  if ( ((this->options2_ >> 14) & 1) != on )
  {
    v2 = this->options2_;
    if ( on )
      v3 = v2 | 0x4000;
    else
      v3 = v2 & 0xFFFFBFFF;
    this->options2_ = v3;
    ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(41);
  }
}

//----- (005D3AA0) --------------------------------------------------------  // acclient.c:512259
bool __thiscall PlayerModule::GetOption(PlayerModule *this, PlayerOption po)
{
  unsigned int v2; // eax@2

  if ( po )
  {
    switch ( po )
    {
      case 1u:
        v2 = (this->options_ >> 2) & 1;
        break;
      case 2u:
        v2 = (this->options_ >> 3) & 1;
        break;
      case 3u:
        v2 = (this->options_ >> 17) & 1;
        break;
      case 4u:
        LOBYTE(v2) = BYTE2(this->options_) & 1;
        break;
      case 5u:
        v2 = this->options2_ & 1;
        break;
      case 6u:
        v2 = (this->options_ >> 6) & 1;
        break;
      case 7u:
        v2 = (this->options_ >> 7) & 1;
        break;
      case 8u:
        v2 = (this->options_ >> 8) & 1;
        break;
      case 9u:
        v2 = (this->options_ >> 9) & 1;
        break;
      case 0xAu:
        v2 = (this->options_ >> 10) & 1;
        break;
      case 0xBu:
        v2 = (this->options_ >> 11) & 1;
        break;
      case 0xCu:
        v2 = (this->options_ >> 12) & 1;
        break;
      case 0xDu:
        v2 = (this->options_ >> 13) & 1;
        break;
      case 0xEu:
        v2 = (this->options_ >> 15) & 1;
        break;
      case 0xFu:
        v2 = (this->options_ >> 18) & 1;
        break;
      case 0x10u:
        v2 = (this->options_ >> 19) & 1;
        break;
      case 0x11u:
        v2 = (this->options_ >> 20) & 1;
        break;
      case 0x12u:
        v2 = (this->options_ >> 29) & 1;
        break;
      case 0x13u:
        v2 = (this->options_ >> 21) & 1;
        break;
      case 0x14u:
        v2 = (this->options_ >> 22) & 1;
        break;
      case 0x15u:
        v2 = (this->options_ >> 23) & 1;
        break;
      case 0x16u:
        v2 = (this->options_ >> 25) & 1;
        break;
      case 0x17u:
        v2 = (this->options_ >> 26) & 1;
        break;
      case 0x18u:
        v2 = (this->options_ >> 27) & 1;
        break;
      case 0x19u:
        v2 = (this->options_ >> 28) & 1;
        break;
      case 0x2Au:
        v2 = (this->options2_ >> 15) & 1;
        break;
      case 0x2Bu:
        LOBYTE(v2) = BYTE2(this->options2_) & 1;
        break;
      case 0x1Au:
        v2 = this->options_ >> 31;
        break;
      case 0x2Du:
        v2 = (this->options2_ >> 18) & 1;
        break;
      case 0x1Bu:
        v2 = (this->options_ >> 30) & 1;
        break;
      case 0x23u:
        v2 = (this->options2_ >> 8) & 1;
        break;
      case 0x24u:
        v2 = (this->options2_ >> 9) & 1;
        break;
      case 0x25u:
        v2 = (this->options2_ >> 10) & 1;
        break;
      case 0x26u:
        v2 = (this->options2_ >> 11) & 1;
        break;
      case 0x27u:
        v2 = (this->options2_ >> 12) & 1;
        break;
      case 0x1Cu:
        v2 = (this->options2_ >> 1) & 1;
        break;
      case 0x1Du:
        v2 = (this->options2_ >> 5) & 1;
        break;
      case 0x1Eu:
        v2 = (this->options2_ >> 2) & 1;
        break;
      case 0x1Fu:
        v2 = (this->options2_ >> 3) & 1;
        break;
      case 0x20u:
        v2 = (this->options2_ >> 4) & 1;
        break;
      case 0x28u:
        v2 = (this->options2_ >> 13) & 1;
        break;
      case 0x21u:
        v2 = (this->options2_ >> 6) & 1;
        break;
      case 0x2Cu:
        v2 = (this->options2_ >> 17) & 1;
        break;
      case 0x22u:
        v2 = (this->options2_ >> 7) & 1;
        break;
      case 0x29u:
        v2 = (this->options2_ >> 14) & 1;
        break;
      case 0x2Eu:
        v2 = (this->options2_ >> 19) & 1;
        break;
      case 0x2Fu:
        v2 = (this->options2_ >> 20) & 1;
        break;
      case 0x30u:
        v2 = (this->options2_ >> 21) & 1;
        break;
      case 0x31u:
        v2 = (this->options2_ >> 22) & 1;
        break;
      case 0x32u:
        v2 = (this->options2_ >> 23) & 1;
        break;
      case 0x33u:
        LOBYTE(v2) = BYTE3(this->options2_) & 1;
        break;
      default:
        LOBYTE(v2) = 0;
        break;
    }
  }
  else
  {
    v2 = (this->options_ >> 1) & 1;
  }
  return v2;
}

//----- (005D3EB0) --------------------------------------------------------  // acclient.c:512433
void __thiscall PlayerModule::SetOption(PlayerModule *this, PlayerOption po, bool on)
{
  unsigned int v3; // eax@3

  if ( po )
  {
    switch ( po )
    {
      case 1u:
        PlayerModule::SetIgnoreAllegianceRequests(this, on);
        break;
      case 2u:
        PlayerModule::SetIgnoreFellowshipRequests(this, on);
        break;
      case 3u:
        PlayerModule::SetIgnoreTradeRequests(this, on);
        break;
      case 4u:
        PlayerModule::SetDisableMostWeatherEffects(this, on);
        break;
      case 5u:
        PlayerModule::SetPersistentAtDay(this, on);
        break;
      case 6u:
        PlayerModule::SetAllowGive(this, on);
        break;
      case 7u:
        PlayerModule::SetViewCombatTarget(this, on);
        break;
      case 8u:
        PlayerModule::SetShowTooltips(this, on);
        break;
      case 9u:
        PlayerModule::SetUseDeception(this, on);
        break;
      case 0xAu:
        PlayerModule::SetToggleRun(this, on);
        break;
      case 0xBu:
        PlayerModule::SetStayInChatMode(this, on);
        break;
      case 0xCu:
        PlayerModule::SetAdvancedCombatUI(this, on);
        break;
      case 0xDu:
        PlayerModule::SetAutoTarget(this, on);
        break;
      case 0xEu:
        PlayerModule::SetVividTargetingIndicator(this, on);
        break;
      case 0xFu:
        PlayerModule::SetFellowshipShareXP(this, on);
        break;
      case 0x10u:
        PlayerModule::SetAcceptLootPermits(this, on);
        break;
      case 0x11u:
        PlayerModule::SetFellowshipShareLoot(this, on);
        break;
      case 0x12u:
        PlayerModule::SetFellowshipAutoAcceptRequests(this, on);
        break;
      case 0x13u:
        PlayerModule::SetSideBySideVitals(this, on);
        break;
      case 0x14u:
        PlayerModule::SetCoordinatesOnRadar(this, on);
        break;
      case 0x15u:
        PlayerModule::SetSpellDuration(this, on);
        break;
      case 0x16u:
        PlayerModule::SetDisableHouseRestrictionEffects(this, on);
        break;
      case 0x17u:
        PlayerModule::SetDragItemOnPlayerOpensSecureTrade(this, on);
        break;
      case 0x18u:
        PlayerModule::SetDisplayAllegianceLogonNotifications(this, on);
        break;
      case 0x19u:
        PlayerModule::SetUseChargeAttack(this, on);
        break;
      case 0x2Au:
        PlayerModule::SetLeadMissileTargets(this, on);
        break;
      case 0x2Bu:
        PlayerModule::SetUseFastMissiles(this, on);
        break;
      case 0x1Au:
        PlayerModule::SetUseCraftSuccessDialog(this, on);
        break;
      case 0x2Du:
        PlayerModule::SetConfirmVolatileRareUse(this, on);
        break;
      case 0x1Bu:
        PlayerModule::SetHearAllegianceChat(this, on);
        break;
      case 0x23u:
        PlayerModule::SetHearGeneralChat(this, on);
        break;
      case 0x24u:
        PlayerModule::SetHearTradeChat(this, on);
        break;
      case 0x25u:
        PlayerModule::SetHearLFGChat(this, on);
        break;
      case 0x26u:
        PlayerModule::SetHearRoleplayChat(this, on);
        break;
      case 0x27u:
        PlayerModule::SetAppearOffline(this, on);
        break;
      case 0x1Cu:
        PlayerModule::SetDisplayDateOfBirth(this, on);
        break;
      case 0x1Du:
        PlayerModule::SetDisplayAge(this, on);
        break;
      case 0x1Eu:
        PlayerModule::SetDisplayChessRank(this, on);
        break;
      case 0x1Fu:
        PlayerModule::SetDisplayFishingSkill(this, on);
        break;
      case 0x20u:
        PlayerModule::SetDisplayNumberDeaths(this, on);
        break;
      case 0x28u:
        PlayerModule::SetDisplayNumberCharacterTitles(this, on);
        break;
      case 0x21u:
        PlayerModule::SetDisplayTimeStamps(this, on);
        break;
      case 0x2Cu:
        PlayerModule::SetFilterLanguage(this, on);
        break;
      case 0x22u:
        PlayerModule::SetSalvageMultiple(this, on);
        break;
      case 0x29u:
        PlayerModule::SetMainPackPreferred(this, on);
        break;
      case 0x2Eu:
        PlayerModule::SetHearSocietyChat(this, on);
        break;
      case 0x2Fu:
        PlayerModule::SetShowHelm(this, on);
        break;
      case 0x30u:
        PlayerModule::SetDisableDistanceFog(this, on);
        break;
      case 0x31u:
        PlayerModule::SetUseMouseTurning(this, on);
        break;
      case 0x32u:
        PlayerModule::SetShowCloak(this, on);
        break;
      case 0x33u:
        PlayerModule::SetLockUI(this, on);
        break;
    }
  }
  else if ( ((this->options_ >> 1) & 1) != on )
  {
    v3 = this->options_;
    if ( on )
    {
      this->options_ = v3 | 2;
      ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(0);
    }
    else
    {
      this->options_ = v3 & 0xFFFFFFFD;
      ((void (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(0);
    }
  }
}

//----- (005D42A0) --------------------------------------------------------  // acclient.c:512613
unsigned int __thiscall PackableList<unsigned long>::InsertPos(PackableList<unsigned long> *this, const unsigned int pos, const unsigned int *val)
{
  PackableList<unsigned long> *v3; // esi@1
  const unsigned int v4; // edi@1
  void *v5; // eax@1
  void *v6; // ecx@2
  PackableLLNode<unsigned long> *v7; // eax@4
  const unsigned int result; // eax@5
  PackableLLNode<unsigned long> *v9; // eax@10
  PackableLLNode<unsigned long> *v10; // edx@11
  PackableLLNode<unsigned long> *v11; // edx@14

  v3 = this;
  v4 = pos;
  v5 = operator new(0xCu);
  if ( v5 )
  {
    *(_DWORD *)v5 = *val;
    *((_DWORD *)v5 + 1) = 0;
    *((_DWORD *)v5 + 2) = 0;
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = v3->head;
  if ( !v7 )
  {
    ++v3->curNum;
    v3->head = (PackableLLNode<unsigned long> *)v6;
    v3->tail = (PackableLLNode<unsigned long> *)v6;
    return 0;
  }
  if ( pos )
  {
    while ( v7 )
    {
      --v4;
      v7 = v7->next;
      if ( !v4 )
        goto LABEL_9;
    }
    goto LABEL_10;
  }
LABEL_9:
  if ( !v7 )
  {
LABEL_10:
    v9 = v3->tail;
    v9->next = (PackableLLNode<unsigned long> *)v6;
    *((_DWORD *)v6 + 2) = v9;
    result = v3->curNum;
    v3->tail = (PackableLLNode<unsigned long> *)v6;
    v3->curNum = result + 1;
    return result;
  }
  v10 = v7->prev;
  if ( v10 )
    v10->next = (PackableLLNode<unsigned long> *)v6;
  else
    v3->head = (PackableLLNode<unsigned long> *)v6;
  v11 = v7->prev;
  *((_DWORD *)v6 + 1) = v7;
  *((_DWORD *)v6 + 2) = v11;
  v7->prev = (PackableLLNode<unsigned long> *)v6;
  ++v3->curNum;
  return pos;
}

//----- (005D4350) --------------------------------------------------------  // acclient.c:512684
void __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::PackableHashTable<IDClass<_tagDataID,32,0>,long>(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init(this);
}
// 7E8A08: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (005D4380) --------------------------------------------------------  // acclient.c:512696
PackableHashIterator<IDClass<_tagDataID,32,0>,long> *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::begin(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, PackableHashIterator<IDClass<_tagDataID,32,0>,long> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v4; // edi@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v5; // esi@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v6; // ecx@5
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> *v7; // eax@5
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7B4FBC: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (005D43E0) --------------------------------------------------------  // acclient.c:512741
void __thiscall PlayerModule::AddSpellFavorite(PlayerModule *this, const unsigned int spid, const int index, const int list)
{
  if ( list >= 0 && list < 8 )
    PackableList<unsigned long>::InsertPos(&this->favorite_spells_[list], index, &spid);
}

//----- (005D4410) --------------------------------------------------------  // acclient.c:512748
PackableHashIterator<IDClass<_tagDataID,32,0>,long> *__thiscall PlayerModule::GetDesiredCompHashStart(PlayerModule *this, PackableHashIterator<IDClass<_tagDataID,32,0>,long> *result)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // ecx@1
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> *v3; // eax@2

  v2 = this->desired_comps_;
  if ( v2 )
  {
    PackableHashTable<IDClass<_tagDataID,32,0>,long>::begin(v2, result);
    v3 = result;
  }
  else
  {
    v3 = result;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
    result->_current = 0;
    result->_buckets = 0;
    result->_table_size = 0;
  }
  return v3;
}
// 7B4FBC: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (005D4450) --------------------------------------------------------  // acclient.c:512772
PackableHashIterator<IDClass<_tagDataID,32,0>,long> *__thiscall PlayerModule::GetDesiredCompHashEnd(PlayerModule *this, PackableHashIterator<IDClass<_tagDataID,32,0>,long> *result)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // eax@1
  PackableHashIterator<IDClass<_tagDataID,32,0>,long> *v3; // eax@2
  unsigned int v4; // ecx@3
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v5; // edx@3

  v2 = this->desired_comps_;
  if ( v2 )
  {
    v4 = v2->_table_size;
    v5 = v2->_buckets;
    v3 = result;
    result->_current = 0;
    result->_buckets = v5;
    result->_table_size = v4;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
  }
  else
  {
    v3 = result;
    result->_buckets = 0;
    result->_table_size = 0;
    result->_current = 0;
    result->vfptr = (PackableHashIterator<IDClass<_tagDataID,32,0>,long>Vtbl *)&PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable;
  }
  return v3;
}
// 7B4FBC: using guessed type int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (005D44A0) --------------------------------------------------------  // acclient.c:512803
void __thiscall PlayerModule::SetPackHeader(PlayerModule *this, unsigned int *bitfield)
{
  unsigned int v2; // edx@3
  unsigned int v3; // edx@5

  if ( this->shortcuts_ )
    *bitfield |= 1u;
  v2 = *bitfield | 0x400;
  *bitfield = v2;
  if ( this->desired_comps_ )
    *bitfield = v2 | 8;
  v3 = *bitfield | 0x60;
  *bitfield = v3;
  if ( this->m_pPlayerOptionsData )
    *bitfield = v3 | 0x100;
  if ( this->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_numElements )
    *bitfield |= 0x200u;
}

//----- (005D4500) --------------------------------------------------------  // acclient.c:512823
int __thiscall PlayerModule::GetPackSize(PlayerModule *this)
{
  PlayerModule *v1; // ebx@1
  ShortCutManager *v2; // ecx@1
  int v3; // esi@1
  int v4; // edi@3
  signed int v5; // ebp@3
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v6; // ecx@5
  GenericQualitiesData *v7; // ecx@7
  int result; // eax@12
  void *mem; // [sp+20h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = this->shortcuts_;
  v3 = 16;
  mem = 0;
  if ( v2 )
    v3 = ((int (__stdcall *)(void **, _DWORD))v2->vfptr->Pack)(&mem, 0) + 16;
  v4 = (int)v1->favorite_spells_;
  v5 = 8;
  do
  {
    v3 += (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v4 + 12))(v4, &mem, 0);
    v4 += 16;
    --v5;
  }
  while ( v5 );
  v6 = v1->desired_comps_;
  if ( v6 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v6->vfptr->Pack)(&mem, 0);
  v7 = v1->m_pPlayerOptionsData;
  if ( v7 )
    v3 += ((int (__stdcall *)(void **, _DWORD))v7->vfptr->Pack)(&mem, 0);
  if ( v1->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_numElements )
    v3 += ((int (__thiscall *)(int, void **, _DWORD))v1->m_colGameplayOptions.vfptr->Pack)(
            &v1->m_colGameplayOptions,
            &mem,
            0);
  if ( v3 & 3 )
    result = v3 + 4 - (v3 & 3);
  else
    result = v3;
  return result;
}

//----- (005D45C0) --------------------------------------------------------  // acclient.c:512870
int __thiscall PlayerModule::Pack(PlayerModule *this, void **addr, unsigned int size)
{
  PlayerModule *v3; // edi@1
  int result; // eax@1
  unsigned int v5; // ebp@1
  char *v6; // edx@2
  ShortCutManager *v7; // ecx@2
  int v8; // ebx@4
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v9; // ecx@6
  char *v10; // edx@8
  GenericQualitiesData *v11; // ecx@8
  int v12; // ecx@12
  int v13; // eax@13
  unsigned int retVal; // [sp+28h] [bp-4h]@1

  v3 = this;
  result = ((int (*)(void))this->vfptr->GetPackSize)();
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    size = 0;
    PlayerModule::SetPackHeader(v3, &size);
    *(_DWORD *)*addr = size;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->options_;
    *addr = (char *)*addr + 4;
    v7 = v3->shortcuts_;
    if ( v7 )
      ((void (__stdcall *)(void **, unsigned int))v7->vfptr->Pack)(addr, v5);
    v8 = (int)v3->favorite_spells_;
    size = 8;
    do
    {
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v8 + 12))(v8, addr, v5);
      v8 += 16;
      --size;
    }
    while ( size );
    v9 = v3->desired_comps_;
    if ( v9 )
      ((void (__stdcall *)(void **, unsigned int))v9->vfptr->Pack)(addr, v5);
    *(_DWORD *)*addr = v3->spell_filters_;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->options2_;
    *addr = (char *)*addr + 4;
    v11 = v3->m_pPlayerOptionsData;
    if ( v11 )
      ((void (__stdcall *)(void **, unsigned int))v11->vfptr->Pack)(addr, v5);
    if ( v3->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_numElements )
      ((void (__thiscall *)(int, void **, unsigned int))v3->m_colGameplayOptions.vfptr->Pack)(
        &v3->m_colGameplayOptions,
        addr,
        v5);
    v12 = (signed int)*addr % 4;
    if ( v12 )
    {
      v13 = 4 - v12;
      if ( 4 != v12 )
      {
        do
        {
          *(_BYTE *)*addr = 0;
          --v13;
          *addr = (char *)*addr + 1;
        }
        while ( v13 );
      }
    }
    result = retVal;
  }
  return result;
}

//----- (005D46E0) --------------------------------------------------------  // acclient.c:512947
int *__thiscall PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, IDClass<_tagDataID,32,0> *key)
{
  unsigned int v2; // edi@1
  PackableHashData<IDClass<_tagDataID,32,0>,long> **v3; // esi@2
  PackableHashData<IDClass<_tagDataID,32,0>,long> *v4; // edx@3
  int *result; // eax@6

  v2 = this->_table_size;
  if ( v2 && (v3 = this->_buckets) != 0 && (v4 = v3[key->id % v2]) != 0 )
  {
    while ( key->id != v4->_key.id )
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

//----- (005D4720) --------------------------------------------------------  // acclient.c:512974
int __thiscall PackableList<unsigned long>::Remove(PackableList<unsigned long> *this, unsigned int *val)
{
  PackableList<unsigned long> *v2; // esi@1
  int result; // eax@1
  PackableLLNode<unsigned long> *v4; // ecx@3
  int v5; // ecx@10
  int v6; // edx@13
  int v7; // ecx@13

  v2 = this;
  result = (int)this->head;
  if ( result )
  {
    if ( *(_DWORD *)result == *val )
    {
      *val = *(_DWORD *)result;
      v4 = this->head->next;
      v2->head = v4;
      if ( v4 )
        v4->prev = 0;
      else
        v2->tail = 0;
      if ( result )
        operator delete((void *)result);
      --v2->curNum;
      result = 1;
    }
    else if ( *(_DWORD *)(result + 4) )
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(result + 4);
        if ( *(_DWORD *)v5 == *val )
          break;
        result = *(_DWORD *)(result + 4);
        if ( !*(_DWORD *)(v5 + 4) )
          goto LABEL_12;
      }
      *val = **(_DWORD **)(result + 4);
      v6 = *(_DWORD *)(result + 4);
      v7 = *(_DWORD *)(v6 + 4);
      *(_DWORD *)(result + 4) = v7;
      if ( v7 )
        *(_DWORD *)(v7 + 8) = result;
      else
        v2->tail = (PackableLLNode<unsigned long> *)result;
      operator delete((void *)v6);
      --v2->curNum;
      result = 1;
    }
    else
    {
LABEL_12:
      result = 0;
    }
  }
  return result;
}

//----- (005D47D0) --------------------------------------------------------  // acclient.c:513034
int __thiscall PlayerModule::GetDesiredCompLevel(PlayerModule *this, IDClass<_tagDataID,32,0> wcid)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // ecx@1
  int result; // eax@2
  int *v4; // eax@3

  v2 = this->desired_comps_;
  if ( v2 && (v4 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(v2, &wcid)) != 0 )
    result = *v4;
  else
    result = 0;
  return result;
}

//----- (005D4800) --------------------------------------------------------  // acclient.c:513049
void __thiscall PlayerModule::SetTimeStampFormat(PlayerModule *this, AC1Legacy::PStringBase<char> format)
{
  PlayerModule *v2; // edi@1
  GenericQualitiesData *v3; // eax@1
  bool v4; // zf@1
  GenericQualitiesData *v5; // eax@2
  GenericQualitiesData *v6; // eax@3
  AC1Legacy::PSRefBuffer<char> *v7; // esi@7
  AC1Legacy::PSRefBuffer<char> *v8; // eax@11
  AC1Legacy::PSRefBuffer<char> *v9; // esi@13

  v2 = this;
  v3 = this->m_pPlayerOptionsData;
  v4 = v3 == 0;
  if ( !v3 )
  {
    v5 = (GenericQualitiesData *)operator new(0x14u);
    if ( v5 )
      GenericQualitiesData::GenericQualitiesData(v5);
    else
      v6 = 0;
    v2->m_pPlayerOptionsData = v6;
    v4 = v6 == 0;
  }
  if ( !v4 )
  {
    v7 = v2->m_TimeStampFormat.m_buffer;
    if ( v7 != format.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
        v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
      v8 = format.m_buffer;
      v2->m_TimeStampFormat.m_buffer = format.m_buffer;
      InterlockedIncrement((volatile LONG *)&v8->m_cRef);
    }
    GenericQualitiesData::SetString(v2->m_pPlayerOptionsData, 1u, &format);
  }
  v9 = format.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&format.m_buffer->m_cRef) )
  {
    if ( v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  }
}

//----- (005D48A0) --------------------------------------------------------  // acclient.c:513095
void __thiscall PlayerModule::Clear(PlayerModule *this)
{
  PlayerModule *v1; // esi@1
  ShortCutManager *v2; // ecx@1
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v3; // ecx@3
  GenericQualitiesData *v4; // ecx@5

  v1 = this;
  AC1Legacy::PStringBase<char>::set(&this->m_TimeStampFormat, "%#H:%M:%S ");
  v2 = v1->shortcuts_;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->shortcuts_ = 0;
  }
  v3 = v1->desired_comps_;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->desired_comps_ = 0;
  }
  v4 = v1->m_pPlayerOptionsData;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_pPlayerOptionsData = 0;
  }
  v1->m_colGameplayOptions.vfptr->Destroy((PropertyCollection *)&v1->m_colGameplayOptions.vfptr);
}

//----- (005D4910) --------------------------------------------------------  // acclient.c:513126
void __thiscall PlayerModule::RemoveSpellFavorite(PlayerModule *this, const unsigned int spid, const int list)
{
  const int v3; // eax@1

  v3 = list;
  if ( list >= 0 && list < 8 )
  {
    list = spid;
    PackableList<unsigned long>::Remove(&this->favorite_spells_[v3], (unsigned int *)&list);
  }
}

//----- (005D4940) --------------------------------------------------------  // acclient.c:513139
bool __thiscall PlayerModule::SetDesiredCompLevel(PlayerModule *this, IDClass<_tagDataID,32,0> wcid, const int amount)
{
  const int v3; // edi@1
  PlayerModule *v4; // esi@1
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v5; // eax@4
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v6; // eax@5
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v7; // esi@8
  int *v8; // eax@8
  bool result; // al@9

  v3 = amount;
  v4 = this;
  if ( amount >= 0
    && amount <= 5000
    && (this->desired_comps_
     || ((v5 = (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)operator new(0x14u)) == 0 ? (v6 = 0) : PackableHashTable<IDClass<_tagDataID,32,0>,long>::PackableHashTable<IDClass<_tagDataID,32,0>,long>(v5, 0x100u),
         (v4->desired_comps_ = v6) != 0)) )
  {
    v7 = v4->desired_comps_;
    v8 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(v7, &wcid);
    if ( v8 )
    {
      *v8 = v3;
      result = 1;
    }
    else
    {
      result = PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(v7, &wcid, &amount) != 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005D49D0) --------------------------------------------------------  // acclient.c:513177
int __thiscall PlayerModule::UnPack(PlayerModule *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PlayerModule *v4; // edi@1
  void **v5; // esi@2
  void *v6; // eax@2
  void **v7; // ecx@2
  char *v8; // edx@2
  ShortCutManager *v9; // eax@4
  ShortCutManager *v10; // eax@5
  ShortCutManager *v11; // ecx@8
  int v12; // ebp@11
  signed int v13; // ebx@11
  int v14; // ebp@15
  signed int v15; // ebx@15
  int v16; // ebp@19
  signed int v17; // ebx@19
  void *v18; // ebp@24
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v19; // ecx@29
  AC1Legacy::PSRefBuffer<char> *v20; // ebx@38
  volatile LONG *v21; // ebp@38
  AC1Legacy::PStringBase<char> v22; // ST10_4@38
  GenericQualitiesData *v23; // eax@44
  GenericQualitiesData *v24; // eax@45
  GenericQualitiesData *v25; // ecx@48
  GenericQualitiesData *v26; // ecx@51
  int v27; // ecx@55
  int v28; // eax@56
  AC1Legacy::PStringBase<char> timeStampFormat; // [sp+24h] [bp-8h]@38
  void *v31; // [sp+28h] [bp-4h]@2
  void **addra; // [sp+30h] [bp+4h]@2

  v3 = size;
  v4 = this;
  if ( size < 8 )
    return 0;
  v5 = addr;
  v6 = *addr;
  v7 = *(void ***)*addr;
  v31 = v6;
  v6 = (char *)v6 + 4;
  *addr = v6;
  v4->options_ = *(_DWORD *)v6;
  v8 = (char *)*addr + 4;
  addra = v7;
  *v5 = v8;
  if ( (unsigned __int8)v7 & 1 )
  {
    if ( !v4->shortcuts_ )
    {
      v9 = (ShortCutManager *)operator new(0x4Cu);
      if ( v9 )
      {
        ShortCutManager::ShortCutManager(v9);
        v4->shortcuts_ = v10;
        ((void (__stdcall *)(void **, unsigned int))v10->vfptr->UnPack)(v5, size);
        goto LABEL_10;
      }
      v4->shortcuts_ = 0;
    }
    ((void (__stdcall *)(void **, unsigned int))v4->shortcuts_->vfptr->UnPack)(v5, size);
  }
  else
  {
    v11 = v4->shortcuts_;
    if ( v11 )
    {
      ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v4->shortcuts_ = 0;
    }
  }
LABEL_10:
  ((void (__thiscall *)(int, void **, unsigned int))v4->favorite_spells_[0].vfptr->UnPack)(
    v4->favorite_spells_,
    v5,
    size);
  if ( (unsigned __int8)addra & 4 )
  {
    v12 = (int)&v4->favorite_spells_[1];
    v13 = 4;
    do
    {
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v12 + 16))(v12, v5, size);
      v12 += 16;
      --v13;
    }
    while ( v13 );
  }
  else if ( (unsigned __int8)addra & 0x10 )
  {
    v14 = (int)&v4->favorite_spells_[1];
    v15 = 6;
    do
    {
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v14 + 16))(v14, v5, size);
      v14 += 16;
      --v15;
    }
    while ( v15 );
  }
  else
  {
    if ( !(BYTE1(addra) & 4) )
      goto LABEL_22;
    v16 = (int)&v4->favorite_spells_[1];
    v17 = 7;
    do
    {
      (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v16 + 16))(v16, v5, size);
      v16 += 16;
      --v17;
    }
    while ( v17 );
  }
  v3 = size;
LABEL_22:
  if ( (unsigned __int8)addra & 8 )
  {
    if ( !v4->desired_comps_ )
    {
      v18 = operator new(0x14u);
      if ( v18 )
      {
        *(_DWORD *)v18 = &PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable;
        *((_DWORD *)v18 + 1) = 0;
        *((_DWORD *)v18 + 2) = 0;
        *((_DWORD *)v18 + 3) = 0;
        *((_DWORD *)v18 + 4) = 0;
        PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v18);
      }
      else
      {
        v18 = 0;
      }
      v4->desired_comps_ = (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v18;
    }
    ((void (__stdcall *)(void **, unsigned int))v4->desired_comps_->vfptr->UnPack)(v5, v3);
  }
  else
  {
    v19 = v4->desired_comps_;
    if ( v19 )
    {
      ((void (__stdcall *)(signed int))v19->vfptr->__vecDelDtor)(1);
      v4->desired_comps_ = 0;
    }
  }
  if ( (unsigned __int8)addra & 0x20 )
  {
    v4->spell_filters_ = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
  }
  else
  {
    v4->spell_filters_ = 0x3FFF;
  }
  if ( (unsigned __int8)addra & 0x40 )
  {
    v4->options2_ = *(_DWORD *)*v5;
    *v5 = (char *)*v5 + 4;
  }
  else
  {
    v4->options2_ = 9733888;
  }
  if ( (char)addra < 0 )
  {
    timeStampFormat.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AC1Legacy::PStringBase<char>::UnPack(&timeStampFormat, v5, v3);
    v20 = timeStampFormat.m_buffer;
    v21 = (volatile LONG *)&timeStampFormat.m_buffer->m_cRef;
    v22.m_buffer = timeStampFormat.m_buffer;
    InterlockedIncrement((volatile LONG *)&timeStampFormat.m_buffer->m_cRef);
    PlayerModule::SetTimeStampFormat(v4, v22);
    if ( !InterlockedDecrement(v21) && v20 )
      v20->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v20, 1u);
    v3 = size;
  }
  if ( BYTE1(addra) & 1 )
  {
    if ( !v4->m_pPlayerOptionsData )
    {
      v23 = (GenericQualitiesData *)operator new(0x14u);
      if ( v23 )
        GenericQualitiesData::GenericQualitiesData(v23);
      else
        v24 = 0;
      v4->m_pPlayerOptionsData = v24;
    }
    v25 = v4->m_pPlayerOptionsData;
    if ( v25 )
      ((void (__stdcall *)(void **, unsigned int))v25->vfptr->UnPack)(v5, v3);
    GenericQualitiesData::InqString(v4->m_pPlayerOptionsData, 1u, &v4->m_TimeStampFormat);
  }
  else
  {
    v26 = v4->m_pPlayerOptionsData;
    if ( v26 )
    {
      ((void (__stdcall *)(signed int))v26->vfptr->__vecDelDtor)(1);
      v4->m_pPlayerOptionsData = 0;
    }
  }
  if ( BYTE1(addra) & 2 )
    ((void (__thiscall *)(int, void **, unsigned int))v4->m_colGameplayOptions.vfptr->UnPack)(
      &v4->m_colGameplayOptions,
      v5,
      v3);
  v27 = (signed int)*v5 % 4;
  if ( v27 )
  {
    v28 = 4 - v27;
    if ( 4 != v27 )
    {
      do
      {
        *(_BYTE *)*v5 = 0;
        --v28;
        *v5 = (char *)*v5 + 1;
      }
      while ( v28 );
    }
  }
  if ( v3 < (_BYTE *)*v5 - (_BYTE *)v31 )
  {
    *v5 = v31;
    return 0;
  }
  return 1;
}
// 7E8A08: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D4CD0) --------------------------------------------------------  // acclient.c:513412
char __thiscall PlayerModule::InqOption(PlayerModule *this, unsigned int i_propName, BaseProperty *o_baseProp)
{
  return HashTable<unsigned long,BaseProperty,1>::find(
           (HashTable<unsigned long,BaseProperty,1> *)&this->m_colGameplayOptions.m_hashProperties.vfptr,
           &i_propName,
           o_baseProp);
}

//----- (005D4CF0) --------------------------------------------------------  // acclient.c:513421
int __thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::UnPack(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebx@1
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v4; // esi@1
  void **v6; // edi@3
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int v9; // eax@5
  int v10; // ebx@5
  unsigned int v11; // ebp@5
  void **v12; // ecx@14
  int data_r; // [sp+8h] [bp-10h]@12
  IDClass<_tagDataID,32,0> tempKey; // [sp+Ch] [bp-Ch]@13
  void *start_addr; // [sp+10h] [bp-8h]@3
  unsigned int blob_size; // [sp+14h] [bp-4h]@3

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  v6 = addr;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,unsigned long>::EmptyContents(this);
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
  if ( v8 > 0x10000 || v9 > 0x10000 || !PackableHashTable<unsigned long,CContractTracker>::Init(v4) )
    return 0;
  size = 0;
  if ( v11 )
  {
    while ( 1 )
    {
      addr = (void **)v10;
      if ( !PackObj::UNPACK_TYPE(&data_r, v6, (unsigned int *)&addr) )
        break;
      tempKey.id = data_r;
      if ( (unsigned int)v10 < 4 )
        break;
      v12 = *(void ***)*v6;
      *v6 = (char *)*v6 + 4;
      addr = v12;
      if ( !PackableHashTable<IDClass<_tagDataID,32,0>,long>::add(v4, &tempKey, (const int *)&addr)
        && !v4->m_fThrowawayDuplicateKeysOnUnPack )
        break;
      ++size;
      if ( size >= v11 )
        return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
    }
    return 0;
  }
  return blob_size >= (_BYTE *)*v6 - (_BYTE *)start_addr;
}

//----- (005D4E20) --------------------------------------------------------  // acclient.c:513489
PackableHashTable<IDClass<_tagDataID,32,0>,long> *__thiscall PackableHashTable<IDClass<_tagDataID,32,0>,long>::scalar_deleting_destructor(PackableHashTable<IDClass<_tagDataID,32,0>,long> *this, unsigned int a2)
{
  PackableHashTable<IDClass<_tagDataID,32,0>,long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable;
  PackableHashTable<unsigned long,unsigned long>::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8A08: using guessed type int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char);

//----- (005D4E50) --------------------------------------------------------  // acclient.c:513505
unsigned int __thiscall PackUsingSerialize<PackObj>::Pack(PackUsingSerialize<PackObj> *this, void **addr, unsigned int size)
{
  PackUsingSerialize<PackObj> *v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebp@1
  ArchiveVtbl *v6; // edi@4
  int v7; // eax@4
  SmartBuffer result; // [sp+Ch] [bp-Ch]@3

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  v5 = v4;
  if ( *addr )
  {
    if ( v4 <= size )
    {
      Archive::GetSerializedBuffer((Archive *)&v3->m_ar.vfptr, &result);
      qmemcpy(*addr, (const void *)SmartBuffer::GetBuffer(&result), v5);
      *addr = (char *)*addr + v5;
      SmartBuffer::ReleaseMasterBuffer(&result);
    }
    v6 = v3->m_ar.vfptr;
    SmartBuffer::SmartBuffer(&result);
    v6[1].SetCheckpointing((Archive *)&v3->m_ar, v7);
    SmartBuffer::ReleaseMasterBuffer(&result);
    v3->m_fArchiveValid = 0;
  }
  return v5;
}

//----- (005D4EE0) --------------------------------------------------------  // acclient.c:513536
unsigned int __thiscall PackUsingSerialize<PackObj>::GetPackSize(PackUsingSerialize<PackObj> *this)
{
  PackUsingSerialize<PackObj> *v1; // esi@1
  ArchiveVtbl *v2; // ebx@2
  int v3; // eax@2
  SmartBuffer v5; // [sp+4h] [bp-Ch]@2

  v1 = this;
  if ( !this->m_fArchiveValid )
  {
    v2 = this->m_ar.vfptr;
    SmartBuffer::SmartBuffer(&v5);
    v2[1].SetCheckpointing((Archive *)&v1->m_ar, v3);
    SmartBuffer::ReleaseMasterBuffer(&v5);
    v1->vfptr[1].__vecDelDtor((PackObj *)v1, (unsigned int)&v1->m_ar);
    AutoStoreVersionArchive::OnSerializingDone(&v1->m_ar);
    v1->m_fArchiveValid = 1;
  }
  return Archive::GetSizeUsed((Archive *)&v1->m_ar.vfptr);
}

//----- (005D4F30) --------------------------------------------------------  // acclient.c:513558
PackUsingSerialize<PackObj> *__thiscall PackUsingSerialize<PackObj>::scalar_deleting_destructor(PackUsingSerialize<PackObj> *this, unsigned int a2)
{
  PackUsingSerialize<PackObj> *v2; // edi@1
  Archive *v3; // esi@1

  v2 = this;
  v3 = (Archive *)&this->m_ar.vfptr;
  this->m_ar.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  if ( (this->m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive(v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (005D4F80) --------------------------------------------------------  // acclient.c:513578
void __thiscall PackObjPropertyCollection::Serialize(PackObjPropertyCollection *this, Archive *io_archive)
{
  PropertyCollection::Serialize((PropertyCollection *)&this->vfptr, io_archive);
}

//----- (005D4F90) --------------------------------------------------------  // acclient.c:513584
PackObjPropertyCollection *__thiscall PackObjPropertyCollection::vector_deleting_destructor(PackObjPropertyCollection *this, unsigned int a2)
{
  return PackObjPropertyCollection::vector_deleting_destructor((PackObjPropertyCollection *)((char *)this - 140), a2);
}

//----- (005D4FA0) --------------------------------------------------------  // acclient.c:513590
PackObjPropertyCollection *__thiscall PackObjPropertyCollection::vector_deleting_destructor(PackObjPropertyCollection *this, unsigned int a2)
{
  PackObjPropertyCollection *v2; // esi@1
  PropertyCollection *v3; // ecx@2

  v2 = this;
  if ( this )
    v3 = (PropertyCollection *)&this->vfptr;
  else
    v3 = 0;
  PropertyCollection::~PropertyCollection(v3);
  v2->m_ar.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  if ( (unsigned __int8)BitUtils::AllAreOn(
                          v2->m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate,
                          0x80000000) )
    operator delete[](v2->m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive((Archive *)&v2->m_ar.vfptr);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (005D5010) --------------------------------------------------------  // acclient.c:513616
void __thiscall PlayerModule::~PlayerModule(PlayerModule *this)
{
  PlayerModule *v1; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  PropertyCollection *v3; // ecx@5
  PackableList<unsigned long> *v4; // esi@9
  signed int v5; // edi@9

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PlayerModule::vftable;
  PlayerModule::Clear(this);
  v2 = v1->m_TimeStampFormat.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  if ( v1 == (PlayerModule *)-156 )
    v3 = 0;
  else
    v3 = (PropertyCollection *)&v1->m_colGameplayOptions.vfptr;
  PropertyCollection::~PropertyCollection(v3);
  v1->m_colGameplayOptions.m_ar.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  if ( (unsigned __int8)BitUtils::AllAreOn(
                          v1->m_colGameplayOptions.m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate,
                          0x80000000) )
    operator delete[](v1->m_colGameplayOptions.m_ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive((Archive *)&v1->m_colGameplayOptions.m_ar.vfptr);
  v1->m_colGameplayOptions.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v4 = (PackableList<unsigned long> *)&v1->desired_comps_;
  v5 = 8;
  do
  {
    --v4;
    v4->vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
    PackableList<unsigned long>::Flush(v4);
    --v5;
    v4->vfptr = (PackObjVtbl *)&PackObj::vftable;
  }
  while ( v5 );
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);
// 7E8A60: using guessed type int (__thiscall *PlayerModule::vftable)(void *, char);

//----- (005D50D0) --------------------------------------------------------  // acclient.c:513661
int __thiscall PackUsingSerialize<PackObj>::UnPack(PackUsingSerialize<PackObj> *this, void **addr, unsigned int size)
{
  PackUsingSerialize<PackObj> *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // edx@1
  int v6; // esi@1
  AutoStoreVersionArchive ar; // [sp+8h] [bp-84h]@1

  v3 = this;
  AutoStoreVersionArchive::AutoStoreVersionArchive(&ar, 0, *addr, size);
  v3->vfptr[1].__vecDelDtor((PackObj *)v3, (unsigned int)&ar);
  AutoStoreVersionArchive::OnSerializingDone(&ar);
  v4 = Archive::GetSizeUsed((Archive *)&ar.vfptr);
  v5 = ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate;
  *addr = (char *)*addr + v4;
  ar.vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  v6 = ~(unsigned __int8)(ar.m_flags >> 2) & 1;
  if ( (v5 & 0x80000000) == 0x80000000 )
    operator delete[](ar.m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data);
  Archive::~Archive((Archive *)&ar.vfptr);
  return v6;
}
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (005D5170) --------------------------------------------------------  // acclient.c:513686
void __thiscall AutoStoreVersionArchive::AutoStoreVersionArchive(AutoStoreVersionArchive *this, Archive::tagUnpacking __formal, void *addr, unsigned int size)
{
  AutoStoreVersionArchive *v4; // esi@1
  SmartBuffer *v5; // eax@1
  SmartBuffer v6; // [sp+8h] [bp-Ch]@1

  v4 = this;
  this->vfptr = (ArchiveVtbl *)&Archive::vftable;
  this->m_flags = 0;
  this->m_hrError.m_val = 0;
  SmartBuffer::SmartBuffer(&this->m_buffer);
  v4->m_currOffset = 0;
  v4->m_pcUserDataHash = 0;
  v4->m_pVersionStack = 0;
  v4->vfptr = (ArchiveVtbl *)AutoStoreVersionArchive::vftable;
  v4->m_SerializeVersionRow.vfptr = (ArchiveInitializerVtbl *)&AutoStoreVersionArchive::tagSerializeVersionRow::vftable;
  v4->m_SerializeVersionRow.m_rowInitialData.vfptr = (ArchiveVersionRowVtbl *)&ArchiveVersionRow::vftable;
  v4->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_data = (ArchiveVersionRow::VersionEntry *)v4->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_aPrimitiveInplaceMemory;
  v4->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_sizeAndDeallocate = 8;
  v4->m_SerializeVersionRow.m_rowInitialData.m_aVersions.m_num = 0;
  v4->m_bOnSerializingDoneCalled = 1;
  SmartBuffer::SmartBuffer(&v6, addr, size);
  AutoStoreVersionArchive::InitForUnpacking(v4, v5);
  SmartBuffer::ReleaseMasterBuffer(&v6);
}
// 792B3C: using guessed type void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer);
// 794430: using guessed type unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32);
// 799A90: using guessed type bool (__thiscall *AutoStoreVersionArchive::tagSerializeVersionRow::vftable)(AutoStoreVersionArchive::tagSerializeVersionRow *this, struct Archive *);
// 799A94: using guessed type void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *);

//----- (005D51F0) --------------------------------------------------------  // acclient.c:513717
void __thiscall PlayerModule::PlayerModule(PlayerModule *this)
{
  PlayerModule *v1; // esi@1
  char *v2; // eax@1
  signed int v3; // edx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PlayerModule::vftable;
  this->shortcuts_ = 0;
  v2 = (char *)this->favorite_spells_;
  v3 = 8;
  do
  {
    *(_DWORD *)v2 = &PackableList<unsigned long>::vftable;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = 0;
    *((_DWORD *)v2 + 3) = 0;
    v2 += 16;
    --v3;
  }
  while ( v3 );
  this->desired_comps_ = 0;
  this->m_pPlayerOptionsData = 0;
  this->options_ = 1355064650;
  this->options2_ = 9733888;
  this->spell_filters_ = 0x3FFF;
  this->m_colGameplayOptions.m_fArchiveValid = 0;
  this->m_colGameplayOptions.vfptr = (PackObjVtbl *)&PackUsingSerialize<PackObj>::vftable;
  AutoStoreVersionArchive::AutoStoreVersionArchive(&this->m_colGameplayOptions.m_ar);
  PropertyCollection::PropertyCollection((PropertyCollection *)&v1->m_colGameplayOptions.vfptr);
  v1->m_colGameplayOptions.vfptr = (PackObjVtbl *)&PackObjPropertyCollection::vftable;
  v1->m_colGameplayOptions.vfptr = (PropertyCollectionVtbl *)&PackObjPropertyCollection::vftable;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v1->m_TimeStampFormat, "%#H:%M:%S ");
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);
// 7E8A28: using guessed type int (__thiscall *PackUsingSerialize<PackObj>::vftable)(void *, char);
// 7E8A40: using guessed type int (__thiscall *PackObjPropertyCollection::vftable)(void *, char);
// 7E8A58: using guessed type void *PackObjPropertyCollection::vftable;
// 7E8A60: using guessed type int (__thiscall *PlayerModule::vftable)(void *, char);

//----- (005D52A0) --------------------------------------------------------  // acclient.c:513758
PlayerModule *__thiscall PlayerModule::vector_deleting_destructor(PlayerModule *this, unsigned int a2)
{
  PlayerModule *v2; // esi@1

  v2 = this;
  PlayerModule::~PlayerModule(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005D52C0) --------------------------------------------------------  // acclient.c:513770
void __thiscall PlayerModule::SetOption(PlayerModule *this, BaseProperty *i_prop)
{
  BaseProperty *v2; // edi@1
  PlayerModule *v3; // esi@1

  v2 = i_prop;
  v3 = this;
  i_prop = (BaseProperty *)BaseProperty::GetPropertyName(i_prop);
  HashTable<unsigned long,BaseProperty,1>::set(
    (HashTable<unsigned long,BaseProperty,1> *)&v3->m_colGameplayOptions.m_hashProperties.vfptr,
    (const unsigned int *)&i_prop,
    v2);
  (*(void (__thiscall **)(PlayerModule *, BaseProperty *, _DWORD))&v3->vfptr[1].gap4[0])(v3, v2, 0);
}

//----- (005D5300) --------------------------------------------------------  // acclient.c:513786
int __thiscall PlayerModule::GetChatOptionStructure(PlayerModule *this, unsigned int i_nWhichWindow)
{
  PlayerModule *v2; // esi@1
  unsigned int v3; // ebp@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  int v5; // eax@4
  int v6; // edi@5
  HashTableData<unsigned long,BaseProperty> *v7; // eax@6
  BasePropertyDesc *v8; // ecx@12
  unsigned int v9; // edx@12
  BasePropertyValue *v10; // ecx@16
  unsigned int v11; // edx@16
  BasePropertyDesc *v13; // ecx@24
  unsigned int v14; // edx@24
  BasePropertyValue *v15; // ecx@28
  unsigned int v16; // edx@28
  int v17; // eax@31
  int v18; // ecx@34
  unsigned int i; // esi@36
  BasePropertyDesc *v20; // ecx@41
  unsigned int v21; // esi@41
  BasePropertyValue *v22; // ecx@45
  unsigned int v23; // edx@45
  int v24; // ecx@47
  BaseProperty propArrayElement; // [sp+18h] [bp-10h]@6
  BaseProperty propArray; // [sp+20h] [bp-8h]@6

  v2 = this;
  v3 = i_nWhichWindow - 1;
  v4 = this->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_buckets[0x1000008C
                                                                            % this->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != 268435596 )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
    v5 = (int)&v4->m_data;
  else
LABEL_4:
    v5 = 0;
  v6 = v5;
  if ( !v5 )
  {
    propArray.m_pcPropertyDesc = 0;
    propArray.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propArray, 0x1000008Cu);
    propArrayElement.m_pcPropertyDesc = BaseProperty::GetPropertyName(&propArray);
    HashTable<unsigned long,BaseProperty,1>::add(
      (HashTable<unsigned long,BaseProperty,1> *)&v2->m_colGameplayOptions.m_hashProperties.vfptr,
      (const unsigned int *)&propArrayElement,
      &propArray);
    v7 = v2->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_buckets[0x1000008C
                                                                            % v2->m_colGameplayOptions.m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( !v7 )
      goto LABEL_9;
    while ( v7->m_hashKey != 268435596 )
    {
      v7 = v7->m_hashNext;
      if ( !v7 )
        goto LABEL_9;
    }
    if ( v7 )
      v6 = (int)&v7->m_data;
    else
LABEL_9:
      v6 = 0;
    if ( !v6 )
    {
      if ( (_DWORD)propArray.m_pcPropertyDesc )
      {
        v8 = propArray.m_pcPropertyDesc;
        v9 = propArray.m_pcPropertyDesc->m_cRef - 1;
        propArray.m_pcPropertyDesc->m_cRef = v9;
        if ( !v9 )
          ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
        propArray.m_pcPropertyDesc = 0;
      }
      if ( propArray.m_pcPropertyValue )
      {
        v10 = propArray.m_pcPropertyValue;
        v11 = propArray.m_pcPropertyValue->m_cRef - 1;
        propArray.m_pcPropertyValue->m_cRef = v11;
        if ( !v11 )
          ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
      }
      return 0;
    }
    if ( (_DWORD)propArray.m_pcPropertyDesc )
    {
      v13 = propArray.m_pcPropertyDesc;
      v14 = propArray.m_pcPropertyDesc->m_cRef - 1;
      propArray.m_pcPropertyDesc->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      propArray.m_pcPropertyDesc = 0;
    }
    if ( propArray.m_pcPropertyValue )
    {
      v15 = propArray.m_pcPropertyValue;
      v16 = propArray.m_pcPropertyValue->m_cRef - 1;
      propArray.m_pcPropertyValue->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      propArray.m_pcPropertyValue = 0;
    }
  }
  v17 = *(_DWORD *)v6;
  if ( !*(_DWORD *)v6 || *(_DWORD *)(v17 + 12) != 17 || v3 >= *(_DWORD *)(v17 + 192) )
    return 0;
  i_nWhichWindow = 0;
  v18 = *(_DWORD *)(v6 + 4);
  if ( !v18 || ((*(void (__stdcall **)(unsigned int *))(*(_DWORD *)v18 + 240))(&i_nWhichWindow), i_nWhichWindow <= v3) )
  {
    propArrayElement.m_pcPropertyDesc = 0;
    propArrayElement.m_pcPropertyValue = 0;
    BaseProperty::SetPropertyName(&propArrayElement, 0x1000008Bu);
    for ( i = i_nWhichWindow; i <= v3; ++i )
    {
      if ( *(_DWORD *)(v6 + 4) )
      {
        BaseProperty::CheckCopyOnWrite((BaseProperty *)v6);
        (*(void (__stdcall **)(unsigned int, BaseProperty *))(**(_DWORD **)(v6 + 4) + 248))(i, &propArrayElement);
      }
    }
    if ( (_DWORD)propArrayElement.m_pcPropertyDesc )
    {
      v20 = propArrayElement.m_pcPropertyDesc;
      v21 = propArrayElement.m_pcPropertyDesc->m_cRef - 1;
      propArrayElement.m_pcPropertyDesc->m_cRef = v21;
      if ( !v21 )
        ((void (__stdcall *)(signed int))v20->vfptr->__vecDelDtor)(1);
      propArrayElement.m_pcPropertyDesc = 0;
    }
    if ( propArrayElement.m_pcPropertyValue )
    {
      v22 = propArrayElement.m_pcPropertyValue;
      v23 = propArrayElement.m_pcPropertyValue->m_cRef - 1;
      propArrayElement.m_pcPropertyValue->m_cRef = v23;
      if ( !v23 )
        ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
    }
  }
  BaseProperty::CheckCopyOnWrite((BaseProperty *)v6);
  v24 = *(_DWORD *)(v6 + 4);
  if ( !v24 )
    return 0;
  return (*(int (__stdcall **)(unsigned int))(*(_DWORD *)v24 + 268))(v3);
}

//----- (005D5540) --------------------------------------------------------  // acclient.c:513940
bool __thiscall PlayerModule::InqChatWindowOption(PlayerModule *this, unsigned int i_nWhichWindow, unsigned int i_propName, BaseProperty *o_baseProp)
{
  int v4; // eax@1
  int v5; // ecx@2
  bool result; // al@3

  v4 = PlayerModule::GetChatOptionStructure(this, i_nWhichWindow);
  if ( v4 && (v5 = *(_DWORD *)(v4 + 4)) != 0 )
    result = (*(int (__stdcall **)(unsigned int, BaseProperty *))(*(_DWORD *)v5 + 280))(i_propName, o_baseProp);
  else
    result = 0;
  return result;
}

//----- (005D5570) --------------------------------------------------------  // acclient.c:513955
char __thiscall PlayerModule::SetChatWindowOption(PlayerModule *this, unsigned int i_nWhichWindow, BaseProperty *i_prop)
{
  PlayerModule *v3; // edi@1
  char v4; // bl@1
  int v5; // esi@1
  BasePropertyDesc *v6; // ebx@2

  v3 = this;
  v4 = 0;
  v5 = PlayerModule::GetChatOptionStructure(this, i_nWhichWindow);
  if ( !v5 )
    return v4;
  v6 = BaseProperty::GetPropertyName(i_prop);
  if ( *(_DWORD *)(v5 + 4) )
  {
    BaseProperty::CheckCopyOnWrite((BaseProperty *)v5);
    v4 = (*(int (__stdcall **)(BasePropertyDesc *, BaseProperty *))(**(_DWORD **)(v5 + 4) + 284))(v6, i_prop);
    if ( v4 )
      (*(void (__thiscall **)(PlayerModule *, BaseProperty *, unsigned int))&v3->vfptr[1].gap4[0])(
        v3,
        i_prop,
        i_nWhichWindow);
    return v4;
  }
  return 0;
}

//----- (007104C0) --------------------------------------------------------  // acclient.c:803573
int sub_7104C0()
{
  return atexit(nullsub_1848);
}

