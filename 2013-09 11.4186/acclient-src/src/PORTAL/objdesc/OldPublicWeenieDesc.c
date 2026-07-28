/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : OldPublicWeenieDesc
   Object     : PORTAL\objdesc\OldPublicWeenieDesc.obj
   Functions  : 7
   Addresses  : 006B3DC0 - 00724860 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B3DC0) --------------------------------------------------------  // acclient.c:717716
unsigned int __stdcall CEnvCell::walkable_surface_type(void **addr, unsigned int size)
{
  return 0;
}

//----- (006B70C0) --------------------------------------------------------  // acclient.c:720673
void __thiscall OldPublicWeenieDesc::~OldPublicWeenieDesc(OldPublicWeenieDesc *this)
{
  OldPublicWeenieDesc *v1; // esi@1
  RestrictionDB *v2; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@6

  v1 = this;
  v2 = this->_db;
  v1->vfptr = (PackObjVtbl *)&OldPublicWeenieDesc::vftable;
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
// 8067CC: using guessed type int (__thiscall *OldPublicWeenieDesc::vftable)(void *, char);

//----- (006B7130) --------------------------------------------------------  // acclient.c:720699
OldPublicWeenieDesc *__thiscall OldPublicWeenieDesc::vector_deleting_destructor(OldPublicWeenieDesc *this, unsigned int a2)
{
  OldPublicWeenieDesc *v2; // esi@1

  v2 = this;
  OldPublicWeenieDesc::~OldPublicWeenieDesc(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006B7150) --------------------------------------------------------  // acclient.c:720711
void __thiscall OldPublicWeenieDesc::Reset(OldPublicWeenieDesc *this)
{
  OldPublicWeenieDesc *v1; // esi@1
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
  v1->_wcid.id = stru_9054BC.id;
  v1->_iconID.id = stru_9054BC.id;
  v1->_iconOverlayID.id = stru_9054BC.id;
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
  v1->_obvious_distance = RADAR_DEFAULT_OBVIOUS_DISTANCE;
  v1->_vndwcid.id = stru_9054BC.id;
  v6 = v1->_db;
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
}

//----- (006B72C0) --------------------------------------------------------  // acclient.c:720789
void __thiscall OldPublicWeenieDesc::OldPublicWeenieDesc(OldPublicWeenieDesc *this)
{
  OldPublicWeenieDesc *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  WeenieDesc::WeenieDesc((WeenieDesc *)&this->vfptr);
  v1->vfptr = (PackObjVtbl *)&OldPublicWeenieDesc::vftable;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_plural_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->_db = 0;
  OldPublicWeenieDesc::Reset(v1);
}
// 8067CC: using guessed type int (__thiscall *OldPublicWeenieDesc::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006B7310) --------------------------------------------------------  // acclient.c:720811
int __thiscall OldPublicWeenieDesc::UnPack(OldPublicWeenieDesc *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  OldPublicWeenieDesc *v4; // edi@1
  int v5; // eax@1
  int v6; // ebx@2
  unsigned int v7; // ST04_4@2
  unsigned __int16 v8; // cx@2
  unsigned __int16 v9; // cx@2
  unsigned int v10; // ebp@2
  int v11; // edx@2
  int v12; // ecx@5
  int v13; // edx@7
  AMMO_TYPE v14; // ecx@19
  COMBAT_USE v15; // edx@21
  unsigned __int16 v16; // cx@23
  unsigned int v17; // ecx@25
  unsigned int v18; // edx@27
  unsigned __int16 v19; // cx@29
  int v20; // edx@41
  unsigned __int8 v21; // cl@43
  unsigned __int16 v22; // cx@47
  unsigned int v23; // ecx@49
  PScriptType v24; // ecx@53
  RestrictionDB *v25; // eax@55
  RestrictionDB *v26; // eax@56
  unsigned __int16 v27; // cx@60
  int v28; // edx@66
  void *start; // [sp+Ch] [bp-4h]@1

  v3 = addr;
  v4 = this;
  start = *addr;
  OldPublicWeenieDesc::Reset(this);
  addr = 0;
  v5 = AC1Legacy::PStringBase<char>::Pack(&v4->_name, (void **)&addr, 0);
  if ( size < v5 + 16 )
    return 0;
  v6 = *(_DWORD *)*v3;
  v7 = size;
  *v3 = (char *)*v3 + 4;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_name, v3, v7);
  v8 = *(_WORD *)*v3;
  *v3 = (char *)*v3 + 2;
  v4->_wcid.id = v8;
  v9 = *(_WORD *)*v3;
  *v3 = (char *)*v3 + 2;
  v10 = size;
  v4->_iconID.id = v9 | 0x6000000;
  v4->_type = *(_DWORD *)*v3;
  v11 = (int)((char *)*v3 + 4);
  *v3 = (void *)v11;
  v4->_bitfield = *(_DWORD *)v11;
  *v3 = (char *)*v3 + 4;
  if ( v6 & 1 )
    AC1Legacy::PStringBase<char>::UnPack(&v4->_plural_name, v3, v10);
  if ( v6 & 2 )
  {
    v12 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_itemsCapacity = v12;
  }
  if ( v6 & 4 )
  {
    v13 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_containersCapacity = v13;
  }
  if ( v6 & 8 )
  {
    v4->_value = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x10 )
  {
    v4->_useability = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x20 )
  {
    LODWORD(v4->_useRadius) = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x80000 )
  {
    v4->_targetType = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( (char)v6 < 0 )
  {
    v4->_effects = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( BYTE1(v6) & 1 )
  {
    v14 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_ammoType = v14;
  }
  if ( BYTE1(v6) & 2 )
  {
    v15 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_combatUse = v15;
  }
  if ( BYTE1(v6) & 4 )
  {
    v16 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_structure = v16;
  }
  if ( BYTE1(v6) & 8 )
  {
    v17 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_maxStructure = v17;
  }
  if ( BYTE1(v6) & 0x10 )
  {
    v18 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_stackSize = v18;
  }
  if ( BYTE1(v6) & 0x20 )
  {
    v19 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_maxStackSize = v19;
  }
  if ( BYTE1(v6) & 0x40 )
  {
    v4->_containerID = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( SBYTE1(v6) < 0 )
  {
    v4->_wielderID = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x10000 )
  {
    v4->_valid_locations = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x20000 )
  {
    v4->_location = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x40000 )
  {
    v4->_priority = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x100000 )
  {
    v20 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_blipColor = v20;
  }
  if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v6 )
  {
    v21 = *(_BYTE *)*v3;
    *v3 = (char *)*v3 + 1;
    v4->_radar_enum = v21;
  }
  if ( v6 & 0x1000000 )
  {
    LODWORD(v4->_obvious_distance) = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x200000 )
  {
    v22 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_vndwcid.id = v22;
  }
  if ( v6 & 0x400000 )
  {
    v23 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_spellID = v23;
  }
  if ( v6 & 0x2000000 )
  {
    v4->_house_owner_iid = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x8000000 )
  {
    v24 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_pscript = v24;
  }
  if ( v6 & 0x4000000 )
  {
    v25 = (RestrictionDB *)operator new(0x84u);
    if ( v25 )
      RestrictionDB::RestrictionDB(v25);
    else
      v26 = 0;
    v4->_db = v26;
    ((void (__thiscall *)(RestrictionDB *, void **, unsigned int))v26->vfptr->UnPack)(v26, v3, v10);
  }
  if ( v6 & 0x10000000 )
  {
    v27 = *(_WORD *)*v3;
    *v3 = (char *)*v3 + 2;
    v4->_hook_type = v27;
  }
  if ( v6 & 0x20000000 )
  {
    v4->_hook_item_types = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x40 )
  {
    v4->_monarch = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  if ( v6 & 0x40000000 )
  {
    v28 = *(_WORD *)*v3 | 0x6000000;
    *v3 = (char *)*v3 + 2;
    v4->_iconOverlayID.id = v28;
  }
  if ( v6 < 0 )
  {
    v4->_material_type = *(_DWORD *)*v3;
    *v3 = (char *)*v3 + 4;
  }
  PackObj::ALIGN_PTR(v3);
  if ( v10 < (_BYTE *)*v3 - (_BYTE *)start )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (00724860) --------------------------------------------------------  // acclient.c:822231
int sub_724860()
{
  return atexit(nullsub_1539);
}

