/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PublicWeenieDesc
   Object     : PORTAL\objdesc\PublicWeenieDesc.obj
   Functions  : 12
   Addresses  : 005AC7B0 - 0070E1E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AC7B0) --------------------------------------------------------  // acclient.c:470678
BOOL __cdecl PublicWeenieDesc::IsTalkable(ITEM_TYPE _itemType)
{
  return _itemType == 16;
}

//----- (005AC7C0) --------------------------------------------------------  // acclient.c:470684
void __thiscall PublicWeenieDesc::SetPlayerKillerStatus(PublicWeenieDesc *this, unsigned int pk)
{
  switch ( pk )
  {
    case 4u:
      this->_bitfield = this->_bitfield & 0xFDDFFFFF | 0x20;
      break;
    case 0x40u:
      this->_bitfield = this->_bitfield & 0xFFDFFFDF | 0x2000000;
      break;
    case 0x20u:
      this->_bitfield = this->_bitfield & 0xFDFFFFDF | 0x200000;
      break;
    default:
      this->_bitfield &= 0xFDDFFFDF;
      break;
  }
}

//----- (005AC820) --------------------------------------------------------  // acclient.c:470704
void __thiscall PublicWeenieDesc::set_pack_header(PublicWeenieDesc *this, unsigned int *header)
{
  if ( this->_plural_name.m_buffer->m_len != 1 )
    *header |= 1u;
  if ( this->_valid_locations )
    *header |= 0x10000u;
  if ( this->_location )
    *header |= 0x20000u;
  if ( this->_containerID )
    *header |= 0x4000u;
  if ( this->_wielderID )
    *header |= 0x8000u;
  if ( this->_itemsCapacity )
    *header |= 2u;
  if ( this->_containersCapacity )
    *header |= 4u;
  if ( this->_value )
    *header |= 8u;
  if ( this->_useability )
    *header |= 0x10u;
  if ( this->_useRadius != 0.0 )
    *header |= 0x20u;
  if ( this->_targetType )
    *header |= 0x80000u;
  if ( this->_effects )
    *header |= 0x80u;
  if ( this->_ammoType )
    *header |= 0x100u;
  if ( this->_combatUse )
    *header |= 0x200u;
  if ( this->_structure )
    *header |= 0x400u;
  if ( this->_maxStructure )
    *header |= 0x800u;
  if ( this->_stackSize )
    *header |= 0x1000u;
  if ( this->_maxStackSize )
    *header |= 0x2000u;
  if ( this->_priority )
    *header |= 0x40000u;
  if ( this->_blipColor )
    *header |= 0x100000u;
  if ( this->_radar_enum )
    *header |= (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)";
  if ( this->_workmanship > 0.0 )
    *header |= 0x1000000u;
  if ( this->_burden > 0 )
    *header |= 0x200000u;
  if ( this->_spellID )
    *header |= 0x400000u;
  if ( this->_house_owner_iid )
    *header |= 0x2000000u;
  if ( this->_pscript )
    *header |= 0x8000000u;
  if ( this->_db )
    *header |= 0x4000000u;
  if ( this->_hook_type )
    *header |= 0x10000000u;
  if ( this->_hook_item_types )
    *header |= 0x20000000u;
  if ( this->_monarch )
    *header |= 0x40u;
  if ( this->_iconOverlayID.id != stru_8EE100.id )
    *header |= 0x40000000u;
  if ( this->_material_type )
    *header |= 0x80000000;
}

//----- (005AC9E0) --------------------------------------------------------  // acclient.c:470773
void __thiscall PublicWeenieDesc::~PublicWeenieDesc(PublicWeenieDesc *this)
{
  PublicWeenieDesc *v1; // esi@1
  RestrictionDB *v2; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@6

  v1 = this;
  v2 = this->_db;
  v1->vfptr = (PackObjVtbl *)&PublicWeenieDesc::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_db = 0;
  }
  v3 = v1->_plural_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v1->_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  WeenieDesc::~WeenieDesc((WeenieDesc *)&v1->vfptr);
}
// 7E60B8: using guessed type int (__thiscall *PublicWeenieDesc::vftable)(void *, char);

//----- (005ACA50) --------------------------------------------------------  // acclient.c:470799
PublicWeenieDesc *__thiscall PublicWeenieDesc::scalar_deleting_destructor(PublicWeenieDesc *this, unsigned int a2)
{
  PublicWeenieDesc *v2; // esi@1

  v2 = this;
  PublicWeenieDesc::~PublicWeenieDesc(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005ACA70) --------------------------------------------------------  // acclient.c:470811
int __thiscall PublicWeenieDesc::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@5
  int v5; // ebx@6
  int v6; // eax@10
  int v7; // ecx@11
  RestrictionDB *v8; // eax@16
  int v9; // eax@17

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  v5 = *(_DWORD *)(v2 + 8);
  if ( v5 != *(_DWORD *)(a2 + 8) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v6;
    InterlockedIncrement((volatile LONG *)(v6 + 4));
  }
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(v2 + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(v2 + 60) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)(v2 + 64) = *(_DWORD *)(a2 + 64);
  *(float *)(v2 + 68) = *(float *)(a2 + 68);
  *(_DWORD *)(v2 + 72) = *(_DWORD *)(a2 + 72);
  *(_DWORD *)(v2 + 76) = *(_DWORD *)(a2 + 76);
  *(_DWORD *)(v2 + 80) = *(_DWORD *)(a2 + 80);
  *(_DWORD *)(v2 + 84) = *(_DWORD *)(a2 + 84);
  *(_DWORD *)(v2 + 88) = *(_DWORD *)(a2 + 88);
  *(_DWORD *)(v2 + 92) = *(_DWORD *)(a2 + 92);
  *(_DWORD *)(v2 + 96) = *(_DWORD *)(a2 + 96);
  *(_DWORD *)(v2 + 100) = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(v2 + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(v2 + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(v2 + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(v2 + 104) = *(_DWORD *)(a2 + 104);
  *(_DWORD *)(v2 + 108) = *(_DWORD *)(a2 + 108);
  *(_DWORD *)(v2 + 112) = *(_DWORD *)(a2 + 112);
  *(float *)(v2 + 152) = *(float *)(a2 + 152);
  *(_DWORD *)(v2 + 116) = *(_DWORD *)(a2 + 116);
  *(_DWORD *)(v2 + 120) = *(_DWORD *)(a2 + 120);
  v7 = *(_DWORD *)(v2 + 128);
  *(_DWORD *)(v2 + 124) = *(_DWORD *)(a2 + 124);
  *(_DWORD *)(v2 + 132) = *(_DWORD *)(a2 + 132);
  if ( v7 )
  {
    if ( *(_DWORD *)(a2 + 128) )
    {
      RestrictionDB::operator=(v7, *(_DWORD *)(a2 + 128));
    }
    else
    {
      (**(void (__stdcall ***)(_DWORD))v7)(1);
      *(_DWORD *)(v2 + 128) = 0;
    }
  }
  else if ( *(_DWORD *)(a2 + 128) )
  {
    v8 = (RestrictionDB *)operator new(0x84u);
    if ( v8 )
      RestrictionDB::RestrictionDB(v8, *(RestrictionDB **)(a2 + 128));
    else
      v9 = 0;
    *(_DWORD *)(v2 + 128) = v9;
  }
  *(_DWORD *)(v2 + 136) = *(_DWORD *)(a2 + 136);
  *(_DWORD *)(v2 + 140) = *(_DWORD *)(a2 + 140);
  *(_DWORD *)(v2 + 144) = *(_DWORD *)(a2 + 144);
  *(_DWORD *)(v2 + 148) = *(_DWORD *)(a2 + 148);
  *(_DWORD *)(v2 + 156) = *(_DWORD *)(a2 + 156);
  *(double *)(v2 + 160) = *(double *)(a2 + 160);
  *(_DWORD *)(v2 + 168) = *(_DWORD *)(a2 + 168);
  return v2;
}

//----- (005ACC70) --------------------------------------------------------  // acclient.c:470905
void __thiscall PublicWeenieDesc::Reset(PublicWeenieDesc *this)
{
  PublicWeenieDesc *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v3; // ebp@1
  AC1Legacy::PSRefBuffer<char> *v4; // ebp@9
  AC1Legacy::PSRefBuffer<char> *v5; // ebx@9
  RestrictionDB *v6; // ecx@17
  AC1Legacy::PStringBase<char> v7; // [sp+10h] [bp-4h]@1

  v1 = this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v7, &name);
  v2 = v1->_name.m_buffer;
  v3 = v7.m_buffer;
  if ( v2 != v7.m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    v1->_name.m_buffer = v3;
    InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  AC1Legacy::PStringBase<char>::PStringBase<char>(&v7, &name);
  v4 = v1->_plural_name.m_buffer;
  v5 = v7.m_buffer;
  if ( v4 != v7.m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    v1->_plural_name.m_buffer = v5;
    InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  v1->_wcid.id = stru_8EE100.id;
  v1->_iconID.id = stru_8EE100.id;
  v6 = v1->_db;
  v1->_iconOverlayID.id = stru_8EE100.id;
  v1->_iconUnderlayID.id = stru_8EE100.id;
  v1->_itemsCapacity = 0;
  v1->_containersCapacity = 0;
  v1->_type = 0;
  v1->_value = 0;
  v1->_useability = 0;
  LODWORD(v1->_useRadius) = 0;
  v1->_targetType = 0;
  v1->_effects = 0;
  v1->_ammoType = 0;
  v1->_combatUse = 0;
  v1->_structure = 0;
  v1->_maxStructure = 0;
  v1->_stackSize = 0;
  v1->_maxStackSize = 0;
  v1->_containerID = 0;
  v1->_wielderID = 0;
  v1->_location = 0;
  v1->_valid_locations = 0;
  v1->_priority = 0;
  v1->_bitfield = 0;
  v1->_blipColor = 0;
  v1->_radar_enum = 0;
  LODWORD(v1->_workmanship) = 0;
  v1->_burden = 0;
  v1->_spellID = 0;
  v1->_house_owner_iid = 0;
  v1->_pscript = 0;
  if ( v6 )
  {
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v1->_db = 0;
  }
  v1->_hook_type = 0;
  v1->_hook_item_types = 0;
  v1->_monarch = 0;
  v1->_material_type = 0;
  v1->_cooldown_id = 0;
  LODWORD(v1->_cooldown_duration) = 0;
  HIDWORD(v1->_cooldown_duration) = 0;
  v1->_pet_owner = 0;
}

//----- (005ACE00) --------------------------------------------------------  // acclient.c:470988
int __thiscall PublicWeenieDesc::pack_size(PublicWeenieDesc *this)
{
  PublicWeenieDesc *v1; // esi@1
  int v2; // edi@1
  int v3; // edi@1
  int v4; // edi@1
  int v5; // ecx@2
  int v6; // edi@4
  RestrictionDB *v7; // ecx@58
  IDClass<_tagDataID,32,0> v8; // ecx@66
  IDClass<_tagDataID,32,0> v9; // eax@68
  int result; // eax@79
  void *tmp; // [sp+8h] [bp-4h]@1

  v1 = this;
  tmp = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(&this->_name, &tmp, 0);
  v3 = Pack_AsDataIDOfKnownType(0x6000000u, v1->_iconID, &tmp, 0) + v2;
  v4 = v3 + Pack_AsWClassIDCompressed(v1->_wcid, &tmp, 0) + 12;
  if ( v4 & 3 )
    v5 = 4 - (v4 & 3);
  else
    v5 = 0;
  v6 = v5 + v4;
  if ( v1->_bitfield & 0x4000000 )
    v6 += 4;
  if ( v1->_plural_name.m_buffer->m_len != 1 )
    v6 += AC1Legacy::PStringBase<char>::Pack(&v1->_plural_name, &tmp, 0);
  if ( v1->_itemsCapacity )
    ++v6;
  if ( v1->_containersCapacity )
    ++v6;
  if ( v1->_ammoType )
    v6 += 2;
  if ( v1->_value )
    v6 += 4;
  if ( v1->_useability )
    v6 += 4;
  if ( v1->_useRadius != 0.0 )
    v6 += 4;
  if ( v1->_targetType )
    v6 += 4;
  if ( v1->_effects )
    v6 += 4;
  if ( v1->_combatUse )
    ++v6;
  if ( v1->_structure )
    v6 += 2;
  if ( v1->_maxStructure )
    v6 += 2;
  if ( v1->_stackSize )
    v6 += 2;
  if ( v1->_maxStackSize )
    v6 += 2;
  if ( v1->_containerID )
    v6 += 4;
  if ( v1->_wielderID )
    v6 += 4;
  if ( v1->_valid_locations )
    v6 += 4;
  if ( v1->_location )
    v6 += 4;
  if ( v1->_priority )
    v6 += 4;
  if ( v1->_blipColor )
    ++v6;
  if ( v1->_radar_enum )
    ++v6;
  if ( v1->_pscript )
    v6 += 2;
  if ( v1->_workmanship > 0.0 )
    v6 += 4;
  if ( v1->_burden > 0 )
    v6 += 2;
  if ( v1->_spellID )
    v6 += 2;
  if ( v1->_house_owner_iid )
    v6 += 4;
  v7 = v1->_db;
  if ( v7 )
    v6 += ((int (__stdcall *)(void **, _DWORD))v7->vfptr->Pack)(&tmp, 0);
  if ( v1->_hook_item_types )
    v6 += 4;
  if ( v1->_monarch )
    v6 += 4;
  if ( v1->_hook_type )
    v6 += 2;
  v8.id = v1->_iconOverlayID.id;
  if ( v8.id != stru_8EE100.id )
    v6 += Pack_AsDataIDOfKnownType(0x6000000u, v8, &tmp, 0);
  v9.id = v1->_iconUnderlayID.id;
  if ( v9.id != stru_8EE100.id )
    v6 += Pack_AsDataIDOfKnownType(0x6000000u, v9, &tmp, 0);
  if ( v1->_material_type )
    v6 += 4;
  if ( v1->_cooldown_id )
    v6 += 4;
  if ( v1->_cooldown_duration != 0.0 )
    v6 += 8;
  if ( v1->_pet_owner )
    v6 += 4;
  if ( v6 & 3 )
    result = v6 + 4 - (v6 & 3);
  else
    result = v6;
  return result;
}

//----- (005AD070) --------------------------------------------------------  // acclient.c:471097
int __thiscall PublicWeenieDesc::Pack(PublicWeenieDesc *this, void **addr, unsigned int size)
{
  PublicWeenieDesc *v3; // edi@1
  unsigned int v4; // eax@9
  unsigned int v5; // eax@10
  PackObjVtbl *v6; // edx@12
  int result; // eax@12
  unsigned int v8; // ebp@12
  unsigned int v9; // ebx@13
  char *v10; // ecx@13
  void *v11; // ecx@84
  unsigned int header2; // [sp+Ch] [bp-8h]@1
  unsigned int psize; // [sp+10h] [bp-4h]@12

  v3 = this;
  header2 = 0;
  if ( this->_iconUnderlayID.id != stru_8EE100.id )
    header2 = 1;
  if ( this->_cooldown_id )
    header2 |= 2u;
  if ( this->_cooldown_duration != 0.0 )
    header2 |= 4u;
  if ( this->_pet_owner )
    header2 |= 8u;
  v4 = this->_bitfield;
  if ( header2 )
    v5 = v4 | 0x4000000;
  else
    v5 = v4 & 0xFBFFFFFF;
  v6 = this->vfptr;
  this->_bitfield = v5;
  result = ((int (__thiscall *)(PublicWeenieDesc *))v6[1].__vecDelDtor)(this);
  v8 = size;
  psize = result;
  if ( size >= result )
  {
    size = 0;
    PublicWeenieDesc::set_pack_header(v3, &size);
    v9 = size;
    *(_DWORD *)*addr = size;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, v8);
    Pack_AsWClassIDCompressed(v3->_wcid, addr, v8);
    Pack_AsDataIDOfKnownType(0x6000000u, v3->_iconID, addr, v8);
    *(_DWORD *)*addr = v3->_type;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->_bitfield;
    *addr = (char *)*addr + 4;
    PackObj::ALIGN_PTR(addr);
    if ( v3->_bitfield & 0x4000000 )
    {
      *(_DWORD *)*addr = header2;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 1 )
      AC1Legacy::PStringBase<char>::Pack(&v3->_plural_name, addr, v8);
    if ( v9 & 2 )
    {
      *(_BYTE *)*addr = LOBYTE(v3->_itemsCapacity);
      *addr = (char *)*addr + 1;
    }
    if ( v9 & 4 )
    {
      *(_BYTE *)*addr = LOBYTE(v3->_containersCapacity);
      *addr = (char *)*addr + 1;
    }
    if ( BYTE1(v9) & 1 )
    {
      *(_WORD *)*addr = LOWORD(v3->_ammoType);
      *addr = (char *)*addr + 2;
    }
    if ( v9 & 8 )
    {
      *(_DWORD *)*addr = v3->_value;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x10 )
    {
      *(_DWORD *)*addr = v3->_useability;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x20 )
    {
      *(float *)*addr = v3->_useRadius;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x80000 )
    {
      *(_DWORD *)*addr = v3->_targetType;
      *addr = (char *)*addr + 4;
    }
    if ( (v9 & 0x80u) != 0 )
    {
      *(_DWORD *)*addr = v3->_effects;
      *addr = (char *)*addr + 4;
    }
    if ( BYTE1(v9) & 2 )
    {
      *(_BYTE *)*addr = LOBYTE(v3->_combatUse);
      *addr = (char *)*addr + 1;
    }
    if ( BYTE1(v9) & 4 )
    {
      *(_WORD *)*addr = LOWORD(v3->_structure);
      *addr = (char *)*addr + 2;
    }
    if ( BYTE1(v9) & 8 )
    {
      *(_WORD *)*addr = LOWORD(v3->_maxStructure);
      *addr = (char *)*addr + 2;
    }
    if ( BYTE1(v9) & 0x10 )
    {
      *(_WORD *)*addr = LOWORD(v3->_stackSize);
      *addr = (char *)*addr + 2;
    }
    if ( BYTE1(v9) & 0x20 )
    {
      *(_WORD *)*addr = LOWORD(v3->_maxStackSize);
      *addr = (char *)*addr + 2;
    }
    if ( BYTE1(v9) & 0x40 )
    {
      *(_DWORD *)*addr = v3->_containerID;
      *addr = (char *)*addr + 4;
    }
    if ( SBYTE1(v9) < 0 )
    {
      *(_DWORD *)*addr = v3->_wielderID;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x10000 )
    {
      *(_DWORD *)*addr = v3->_valid_locations;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x20000 )
    {
      *(_DWORD *)*addr = v3->_location;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x40000 )
    {
      *(_DWORD *)*addr = v3->_priority;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x100000 )
    {
      *(_BYTE *)*addr = LOBYTE(v3->_blipColor);
      *addr = (char *)*addr + 1;
    }
    if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v9 )
    {
      *(_BYTE *)*addr = LOBYTE(v3->_radar_enum);
      *addr = (char *)*addr + 1;
    }
    if ( v9 & 0x8000000 )
    {
      *(_WORD *)*addr = LOWORD(v3->_pscript);
      *addr = (char *)*addr + 2;
    }
    if ( v9 & 0x1000000 )
    {
      *(float *)*addr = v3->_workmanship;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x200000 )
    {
      *(_WORD *)*addr = LOWORD(v3->_burden);
      *addr = (char *)*addr + 2;
    }
    if ( v9 & 0x400000 )
    {
      *(_WORD *)*addr = LOWORD(v3->_spellID);
      *addr = (char *)*addr + 2;
    }
    if ( v9 & 0x2000000 )
    {
      *(_DWORD *)*addr = v3->_house_owner_iid;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x4000000 )
      ((void (__stdcall *)(void **, unsigned int))v3->_db->vfptr->Pack)(addr, v8);
    if ( v9 & 0x20000000 )
    {
      *(_DWORD *)*addr = v3->_hook_item_types;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x40 )
    {
      *(_DWORD *)*addr = v3->_monarch;
      *addr = (char *)*addr + 4;
    }
    if ( v9 & 0x10000000 )
    {
      *(_WORD *)*addr = LOWORD(v3->_hook_type);
      *addr = (char *)*addr + 2;
    }
    if ( v9 & 0x40000000 )
      Pack_AsDataIDOfKnownType(0x6000000u, v3->_iconOverlayID, addr, v8);
    if ( header2 & 1 )
      Pack_AsDataIDOfKnownType(0x6000000u, v3->_iconUnderlayID, addr, v8);
    if ( (v9 & 0x80000000) != 0 )
    {
      *(_DWORD *)*addr = v3->_material_type;
      *addr = (char *)*addr + 4;
    }
    if ( header2 & 2 )
    {
      *(_DWORD *)*addr = v3->_cooldown_id;
      *addr = (char *)*addr + 4;
    }
    if ( header2 & 4 )
    {
      v11 = *addr;
      *(_DWORD *)v11 = LODWORD(v3->_cooldown_duration);
      *((_DWORD *)v11 + 1) = HIDWORD(v3->_cooldown_duration);
      *addr = (char *)*addr + 8;
    }
    if ( header2 & 8 )
    {
      *(_DWORD *)*addr = v3->_pet_owner;
      *addr = (char *)*addr + 4;
    }
    PackObj::ALIGN_PTR(addr);
    result = psize;
  }
  return result;
}

//----- (005AD420) --------------------------------------------------------  // acclient.c:471329
void __thiscall PublicWeenieDesc::PublicWeenieDesc(PublicWeenieDesc *this)
{
  PublicWeenieDesc *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  WeenieDesc::WeenieDesc((WeenieDesc *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&PublicWeenieDesc::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_plural_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->_db = 0;
  PublicWeenieDesc::Reset(v1);
}
// 7E60B8: using guessed type int (__thiscall *PublicWeenieDesc::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005AD470) --------------------------------------------------------  // acclient.c:471351
int __thiscall PublicWeenieDesc::UnPack(PublicWeenieDesc *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  PublicWeenieDesc *v4; // edi@1
  int v5; // eax@1
  void *v6; // eax@2
  unsigned int v7; // ST14_4@2
  int v8; // ebx@2
  int v9; // eax@2
  int v10; // eax@3
  unsigned int v11; // ebp@4
  int v12; // edx@7
  char v13; // cl@9
  AMMO_TYPE v14; // ecx@11
  unsigned __int8 v15; // cl@23
  unsigned int v16; // ecx@25
  unsigned int v17; // edx@27
  unsigned __int16 v18; // cx@29
  unsigned int v19; // ecx@31
  unsigned __int8 v20; // cl@43
  RadarEnum v21; // ecx@45
  PScriptType v22; // edx@47
  int v23; // edx@51
  unsigned __int16 v24; // cx@53
  RestrictionDB *v25; // eax@57
  RestrictionDB *v26; // eax@58
  unsigned int v27; // ecx@66
  char v28; // al@73
  void *v29; // ecx@76
  void *start; // [sp+10h] [bp-4h]@1

  v3 = addr;
  v4 = this;
  start = *addr;
  PublicWeenieDesc::Reset(this);
  addr = 0;
  v5 = AC1Legacy::PStringBase<char>::Pack(&v4->_name, (void **)&addr, 0);
  if ( size < v5 + 16 )
    return 0;
  v6 = *v3;
  v7 = size;
  addr = 0;
  v8 = *(_DWORD *)v6;
  *v3 = (char *)v6 + 4;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_name, v3, v7);
  Unpack_AsWClassIDCompressed(&v4->_wcid, v3);
  Unpack_AsDataIDOfKnownType(0x6000000u, &v4->_iconID, v3);
  v4->_type = *(_DWORD *)*v3;
  v9 = (int)((char *)*v3 + 4);
  *v3 = (void *)v9;
  v4->_bitfield = *(_DWORD *)v9;
  *v3 = (char *)*v3 + 4;
  PackObj::ALIGN_PTR(v3);
  if ( v4->_bitfield & 0x4000000 )
  {
    v10 = (int)((char *)*v3 + 4);
    addr = *(void ***)*v3;
    *v3 = (void *)v10;
  }
  v11 = size;
  if ( v8 & 1 )
    AC1Legacy::PStringBase<char>::UnPack(&v4->_plural_name, v3, size);
  if ( v8 & 2 )
  {
    v12 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_itemsCapacity = v12;
  }
  if ( v8 & 4 )
  {
    v13 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_containersCapacity = v13;
  }
  if ( BYTE1(v8) & 1 )
  {
    v14 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_ammoType = v14;
  }
  if ( v8 & 8 )
  {
    v4->_value = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x10 )
  {
    v4->_useability = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x20 )
  {
    LODWORD(v4->_useRadius) = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x80000 )
  {
    v4->_targetType = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( (char)v8 < 0 )
  {
    v4->_effects = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( BYTE1(v8) & 2 )
  {
    v15 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_combatUse = v15;
  }
  if ( BYTE1(v8) & 4 )
  {
    v16 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_structure = v16;
  }
  if ( BYTE1(v8) & 8 )
  {
    v17 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_maxStructure = v17;
  }
  if ( BYTE1(v8) & 0x10 )
  {
    v18 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_stackSize = v18;
  }
  if ( BYTE1(v8) & 0x20 )
  {
    v19 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_maxStackSize = v19;
  }
  if ( BYTE1(v8) & 0x40 )
  {
    v4->_containerID = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( SBYTE1(v8) < 0 )
  {
    v4->_wielderID = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x10000 )
  {
    v4->_valid_locations = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x20000 )
  {
    v4->_location = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x40000 )
  {
    v4->_priority = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x100000 )
  {
    v20 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_blipColor = v20;
  }
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v8 )
  {
    v21 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_radar_enum = v21;
  }
  if ( v8 & 0x8000000 )
  {
    v22 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_pscript = v22;
  }
  if ( v8 & 0x1000000 )
  {
    LODWORD(v4->_workmanship) = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x200000 )
  {
    v23 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_burden = v23;
  }
  if ( v8 & 0x400000 )
  {
    v24 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_spellID = v24;
  }
  if ( v8 & 0x2000000 )
  {
    v4->_house_owner_iid = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x4000000 )
  {
    v25 = (RestrictionDB *)operator new(0x84u);
    if ( v25 )
      RestrictionDB::RestrictionDB(v25);
    else
      v26 = 0;
    v4->_db = v26;
    ((void (__thiscall *)(RestrictionDB *, void **, unsigned int))v26->vfptr->UnPack)(v26, v3, v11);
  }
  if ( v8 & 0x20000000 )
  {
    v4->_hook_item_types = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x40 )
  {
    v4->_monarch = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v8 & 0x10000000 )
  {
    v27 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_hook_type = v27;
  }
  if ( v8 & 0x40000000 )
    Unpack_AsDataIDOfKnownType(0x6000000u, &v4->_iconOverlayID, v3);
  if ( (unsigned __int8)addr & 1 )
    Unpack_AsDataIDOfKnownType(0x6000000u, &v4->_iconUnderlayID, v3);
  if ( v8 < 0 )
  {
    v4->_material_type = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  v28 = (char)addr;
  if ( (unsigned __int8)addr & 2 )
  {
    v4->_cooldown_id = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v28 & 4 )
  {
    v29 = *v3;
    LODWORD(v4->_cooldown_duration) = *(_DWORD *)*v3;
    HIDWORD(v4->_cooldown_duration) = *((_DWORD *)v29 + 1);
    *v3 = (char *)*v3 + 8;
  }
  if ( v28 & 8 )
  {
    v4->_pet_owner = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  PackObj::ALIGN_PTR(v3);
  if ( v11 < (_BYTE *)*v3 - (_BYTE *)start )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (0070E1E0) --------------------------------------------------------  // acclient.c:801099
int sub_70E1E0()
{
  return atexit(nullsub_1538);
}

