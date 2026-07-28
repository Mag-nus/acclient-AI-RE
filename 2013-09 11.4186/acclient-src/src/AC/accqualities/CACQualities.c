/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CACQualities
   Object     : AC\accqualities\CACQualities.obj
   Functions  : 24
   Addresses  : 00592D10 - 0070ABD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00592D10) --------------------------------------------------------  // acclient.c:443988
void __thiscall CACQualities::Clear(CACQualities *this)
{
  CACQualities *v1; // esi@1
  AttributeCache *v2; // ecx@1
  PackableHashTable<unsigned long,Skill> *v3; // ecx@3
  Body *v4; // ecx@5
  CSpellBook *v5; // ecx@7
  CEnchantmentRegistry *v6; // ecx@9
  EventFilter *v7; // ecx@11
  CEmoteTable *v8; // ecx@13
  PackableList<CreationProfile> *v9; // ecx@15
  PageDataList *v10; // ecx@17
  GeneratorTable *v11; // ecx@19
  GeneratorRegistry *v12; // ecx@21
  GeneratorQueue *v13; // ecx@23

  v1 = this;
  v2 = this->_attribCache;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_attribCache = 0;
  }
  v3 = v1->_skillStatsTable;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v1->_skillStatsTable = 0;
  }
  v4 = v1->_body;
  if ( v4 )
  {
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->_body = 0;
  }
  v5 = v1->_spell_book;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->_spell_book = 0;
  }
  v6 = v1->_enchantment_reg;
  if ( v6 )
  {
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v1->_enchantment_reg = 0;
  }
  v7 = v1->_event_filter;
  if ( v7 )
  {
    ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    v1->_event_filter = 0;
  }
  v8 = v1->_emote_table;
  if ( v8 )
  {
    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    v1->_emote_table = 0;
  }
  v9 = v1->_create_list;
  if ( v9 )
  {
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v1->_create_list = 0;
  }
  v10 = v1->_pageDataList;
  if ( v10 )
  {
    ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    v1->_pageDataList = 0;
  }
  v11 = v1->_generator_table;
  if ( v11 )
  {
    ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
    v1->_generator_table = 0;
  }
  v12 = v1->_generator_registry;
  if ( v12 )
  {
    ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
    v1->_generator_registry = 0;
  }
  v13 = v1->_generator_queue;
  if ( v13 )
  {
    ((void (__stdcall *)(_DWORD))v13->vfptr->__vecDelDtor)(1);
    v1->_generator_queue = 0;
  }
}

//----- (00592E00) --------------------------------------------------------  // acclient.c:444080
unsigned int __thiscall CACQualities::InqWeenieTypeString(CACQualities *this, char *buff, const unsigned int size)
{
  unsigned int v3; // ST00_4@1

  v3 = this->m_dataCategory;
  return UIObject::DynamicCast_UIViewportObject();
}

//----- (00592E20) --------------------------------------------------------  // acclient.c:444089
void __thiscall CACQualities::SetPackHeader(CACQualities *this, unsigned int *bitfield)
{
  if ( this->_attribCache )
    *bitfield |= 1u;
  if ( this->_skillStatsTable )
    *bitfield |= 2u;
  if ( this->_body )
    *bitfield |= 4u;
  if ( this->_spell_book )
    *bitfield |= 0x100u;
  if ( this->_enchantment_reg )
    *bitfield |= 0x200u;
  if ( this->_event_filter )
    *bitfield |= 8u;
  if ( this->_emote_table )
    *bitfield |= 0x10u;
  if ( this->_create_list )
    *bitfield |= 0x20u;
  if ( this->_pageDataList )
    *bitfield |= 0x40u;
  if ( this->_generator_table )
    *bitfield |= 0x80u;
  if ( this->_generator_registry )
    *bitfield |= 0x400u;
  if ( this->_generator_queue )
    *bitfield |= 0x800u;
}

//----- (00592EC0) --------------------------------------------------------  // acclient.c:444118
int __thiscall CACQualities::GetPackSize(CACQualities *this)
{
  CACQualities *v1; // edi@1
  int v2; // eax@1
  PackObjVtbl *v3; // ecx@1
  int v4; // esi@1
  int v5; // ecx@3
  CBaseQualitiesVtbl *v6; // ecx@5
  unsigned int v7; // ecx@7
  PackableHashTable<unsigned long,long> *v8; // ecx@9
  PackableHashTable<unsigned long,__int64> *v9; // ecx@11
  PackableHashTable<unsigned long,int> *v10; // ecx@13
  PackableHashTable<unsigned long,double> *v11; // ecx@15
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v12; // ecx@17
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v13; // ecx@19
  PackableHashTable<unsigned long,unsigned long> *v14; // ecx@21
  PackableHashTable<unsigned long,Position> *v15; // ecx@23
  void *mem; // [sp+58h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = CBaseQualities::GetPackSize((CBaseQualities *)&this->m_bLoaded);
  v3 = v1->vfptr;
  v4 = v2 + 8;
  mem = 0;
  if ( v3 )
    v4 += (*((int (__stdcall **)(void **, _DWORD))v3->__vecDelDtor + 3))(&mem, 0);
  v5 = *((_DWORD *)&v1->48 + 1);
  if ( v5 )
    v4 += (*(int (__stdcall **)(void **, _DWORD))(*(_DWORD *)v5 + 12))(&mem, 0);
  v6 = v1->vfptr;
  if ( v6 )
    v4 += (*((int (__stdcall **)(void **, _DWORD))v6->__vecDelDtor + 3))(&mem, 0);
  v7 = v1->_weenie_type;
  if ( v7 )
    v4 += (*(int (__stdcall **)(void **, _DWORD))(*(_DWORD *)v7 + 12))(&mem, 0);
  v8 = v1->_intStatsTable;
  if ( v8 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v8->vfptr->Pack)(&mem, 0);
  v9 = v1->_int64StatsTable;
  if ( v9 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v9->vfptr->Pack)(&mem, 0);
  v10 = v1->_boolStatsTable;
  if ( v10 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v10->vfptr->Pack)(&mem, 0);
  v11 = v1->_floatStatsTable;
  if ( v11 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v11->vfptr->Pack)(&mem, 0);
  v12 = v1->_strStatsTable;
  if ( v12 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v12->vfptr->Pack)(&mem, 0);
  v13 = v1->_didStatsTable;
  if ( v13 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v13->vfptr->Pack)(&mem, 0);
  v14 = v1->_iidStatsTable;
  if ( v14 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v14->vfptr->Pack)(&mem, 0);
  v15 = v1->_posStatsTable;
  if ( v15 )
    v4 += ((int (__stdcall *)(void **, _DWORD))v15->vfptr->Pack)(&mem, 0);
  return v4;
}

//----- (00592FE0) --------------------------------------------------------  // acclient.c:444182
bool __thiscall PlayerDesc::PlayerIsPSRLead(PlayerDesc *this)
{
  CBaseQualities *v1; // esi@1
  bool result; // al@2
  int retval; // [sp+4h] [bp-8h]@1
  int isPSRLead; // [sp+8h] [bp-4h]@3

  v1 = (CBaseQualities *)&this->vfptr;
  retval = 0;
  CBaseQualities::InqBool((CBaseQualities *)&this->vfptr, 0x2Cu, &retval);
  if ( retval )
  {
    result = 1;
  }
  else
  {
    isPSRLead = 0;
    CBaseQualities::InqBool(v1, 0x2Du, &isPSRLead);
    result = isPSRLead != 0;
  }
  return result;
}

//----- (00593030) --------------------------------------------------------  // acclient.c:444206
bool __thiscall PlayerDesc::PlayerIsPSR(PlayerDesc *this)
{
  PlayerDesc *v1; // esi@1
  bool result; // al@2
  int isPSR; // [sp+0h] [bp-4h]@1

  isPSR = (int)this;
  v1 = this;
  if ( PlayerDesc::PlayerIsPSRLead(this) )
  {
    result = 1;
  }
  else
  {
    isPSR = 0;
    CBaseQualities::InqBool((CBaseQualities *)&v1->vfptr, 0x61u, &isPSR);
    result = isPSR != 0;
  }
  return result;
}

//----- (00593070) --------------------------------------------------------  // acclient.c:444228
void __thiscall CACQualities::CACQualities(CACQualities *this, IDClass<_tagDataID,32,0> wcid)
{
  CACQualities *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, wcid);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&SerializeUsingPackDBObj::vftable;
  v2->vfptr = (PackObjVtbl *)&SerializeUsingPackDBObj::vftable;
  CBaseQualities::CBaseQualities((CBaseQualities *)&v2->vfptr, wcid);
  v2->vfptr = (CBaseQualitiesVtbl *)&PlayerDesc::vftable;
  v2->_attribCache = 0;
  v2->_skillStatsTable = 0;
  v2->_body = 0;
  v2->_spell_book = 0;
  v2->_enchantment_reg = 0;
  v2->_event_filter = 0;
  v2->_emote_table = 0;
  v2->_create_list = 0;
  v2->_pageDataList = 0;
  v2->_generator_table = 0;
  v2->_generator_registry = 0;
  v2->_generator_queue = 0;
  v2->vfptr = (InterfaceVtbl *)&CACQualities::vftable;
  v2->vfptr = (PackObjVtbl *)&PlayerDesc::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C58CC: using guessed type void *SerializeUsingPackDBObj::vftable;
// 7C58E0: using guessed type __int32 (__stdcall *SerializeUsingPackDBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7E4560: using guessed type __int32 (__stdcall *CACQualities::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7E45BC: using guessed type void *PlayerDesc::vftable;
// 7E45EC: using guessed type void *PlayerDesc::vftable;

//----- (005930F0) --------------------------------------------------------  // acclient.c:444262
signed int CACQualities::GetDBOType()
{
  return 268435457;
}

//----- (00593100) --------------------------------------------------------  // acclient.c:444268
PlayerDesc *__thiscall PlayerDesc::vector_deleting_destructor(PlayerDesc *this, unsigned int a2)
{
  return CACQualities::scalar_deleting_destructor((PlayerDesc *)((char *)this - 48), a2);
}

//----- (00593110) --------------------------------------------------------  // acclient.c:444274
PlayerDesc *__thiscall CACQualities::vector_deleting_destructor(PlayerDesc *this, unsigned int a2)
{
  return CACQualities::scalar_deleting_destructor((PlayerDesc *)((char *)this - 56), a2);
}

//----- (00593120) --------------------------------------------------------  // acclient.c:444280
TResult *__thiscall PlayerDesc::QueryInterface(PlayerDesc *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S97_10 & 1 )
  {
    v4 = Offsets_13[0].key;
  }
  else
  {
    v4 = (_GUID *)&stru_7E451C;
    _S97_10 |= 1u;
    Offsets_13[0].key = (_GUID *)&stru_7E451C;
    dword_870FE0 = 0;
    dword_870FE4 = (int)&stru_7E453C;
    dword_870FE8 = 0;
    dword_870FEC = 0;
    dword_870FF0 = 0;
  }
  v5 = (int)Offsets_13;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 870FE0: using guessed type int dword_870FE0;
// 870FE4: using guessed type int dword_870FE4;
// 870FE8: using guessed type int dword_870FE8;
// 870FEC: using guessed type int dword_870FEC;
// 870FF0: using guessed type int dword_870FF0;

//----- (005931F0) --------------------------------------------------------  // acclient.c:444343
void __cdecl CACQualities::Allocator()
{
  CACQualities *v0; // eax@1

  v0 = (CACQualities *)operator new(0x90u);
  if ( v0 )
    CACQualities::CACQualities(v0, wcid);
}

//----- (00593220) --------------------------------------------------------  // acclient.c:444353
PlayerDesc *__thiscall CACQualities::scalar_deleting_destructor(PlayerDesc *this, unsigned int a2)
{
  PlayerDesc *v2; // esi@1
  CBaseQualities *v3; // edi@1

  v2 = this;
  v3 = (CBaseQualities *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&CACQualities::vftable;
  this->vfptr = (PackObjVtbl *)&PlayerDesc::vftable;
  this->vfptr = (CBaseQualitiesVtbl *)&PlayerDesc::vftable;
  CACQualities::Clear((CACQualities *)&this->vfptr);
  CBaseQualities::~CBaseQualities(v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4560: using guessed type __int32 (__stdcall *CACQualities::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7E45BC: using guessed type void *PlayerDesc::vftable;
// 7E45EC: using guessed type void *PlayerDesc::vftable;

//----- (00593270) --------------------------------------------------------  // acclient.c:444377
unsigned int __thiscall CACQualities::Pack(CACQualities *this, void **addr, unsigned int size)
{
  CACQualities *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ebp@1
  char *v7; // edx@2
  PackObjVtbl *v8; // ecx@2
  int v9; // ecx@4
  CBaseQualitiesVtbl *v10; // ecx@6
  unsigned int v11; // ecx@8
  PackableHashTable<unsigned long,long> *v12; // ecx@10
  PackableHashTable<unsigned long,__int64> *v13; // ecx@12
  PackableHashTable<unsigned long,int> *v14; // ecx@14
  PackableHashTable<unsigned long,double> *v15; // ecx@16
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v16; // ecx@18
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v17; // ecx@20
  PackableHashTable<unsigned long,unsigned long> *v18; // ecx@22
  PackableHashTable<unsigned long,Position> *v19; // ecx@24

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->IUnknown_Release)();
  v5 = size;
  v6 = v4;
  if ( size >= v4 )
  {
    CBaseQualities::Pack((CBaseQualities *)&v3->m_bLoaded, addr, size);
    size = 0;
    CACQualities::SetPackHeader((CACQualities *)((char *)v3 - 48), &size);
    *(_DWORD *)*addr = size;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3[-1]._generator_registry;
    *addr = (char *)*addr + 4;
    v8 = v3->vfptr;
    if ( v8 )
      (*((void (__stdcall **)(void **, unsigned int))v8->__vecDelDtor + 3))(addr, v5);
    v9 = *((_DWORD *)&v3->48 + 1);
    if ( v9 )
      (*(void (__stdcall **)(void **, unsigned int))(*(_DWORD *)v9 + 12))(addr, v5);
    v10 = v3->vfptr;
    if ( v10 )
      (*((void (__stdcall **)(void **, unsigned int))v10->__vecDelDtor + 3))(addr, v5);
    v11 = v3->_weenie_type;
    if ( v11 )
      (*(void (__stdcall **)(void **, unsigned int))(*(_DWORD *)v11 + 12))(addr, v5);
    v12 = v3->_intStatsTable;
    if ( v12 )
      ((void (__stdcall *)(void **, unsigned int))v12->vfptr->Pack)(addr, v5);
    v13 = v3->_int64StatsTable;
    if ( v13 )
      ((void (__stdcall *)(void **, unsigned int))v13->vfptr->Pack)(addr, v5);
    v14 = v3->_boolStatsTable;
    if ( v14 )
      ((void (__stdcall *)(void **, unsigned int))v14->vfptr->Pack)(addr, v5);
    v15 = v3->_floatStatsTable;
    if ( v15 )
      ((void (__stdcall *)(void **, unsigned int))v15->vfptr->Pack)(addr, v5);
    v16 = v3->_strStatsTable;
    if ( v16 )
      ((void (__stdcall *)(void **, unsigned int))v16->vfptr->Pack)(addr, v5);
    v17 = v3->_didStatsTable;
    if ( v17 )
      ((void (__stdcall *)(void **, unsigned int))v17->vfptr->Pack)(addr, v5);
    v18 = v3->_iidStatsTable;
    if ( v18 )
      ((void (__stdcall *)(void **, unsigned int))v18->vfptr->Pack)(addr, v5);
    v19 = v3->_posStatsTable;
    if ( v19 )
      ((void (__stdcall *)(void **, unsigned int))v19->vfptr->Pack)(addr, v5);
  }
  return v6;
}

//----- (00593380) --------------------------------------------------------  // acclient.c:444452
int __thiscall InterfacePtr<Interface>::_QueryInterface(void *this, int a2, int a3)
{
  void *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  int v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  int v9; // ecx@9
  char v10; // [sp+Ch] [bp-4h]@2

  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(char *, Turbine_GUID *, int *))(v4 + 12))(&v10, &stru_7E453C, &a3);
    v6 = *(_DWORD *)v3;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = v8;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        (*(void (**)(void))(*(_DWORD *)v6 + 20))();
      result = a2;
      *(_DWORD *)v3 = 0;
      *((_DWORD *)v3 + 1) = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    v9 = *(_DWORD *)this;
    if ( *(_DWORD *)v3 )
    {
      *(_DWORD *)v3 = 0;
      (*(void (**)(void))(*(_DWORD *)v9 + 20))();
      *((_DWORD *)v3 + 1) = 0;
    }
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (00593410) --------------------------------------------------------  // acclient.c:444506
unsigned int __thiscall CACQualities::Pack(void *this, void **a2, unsigned int a3)
{
  return CACQualities::Pack((CACQualities *)((char *)this - 8), a2, a3);
}

//----- (00593420) --------------------------------------------------------  // acclient.c:444512
int __thiscall CACQualities::UnPack(CACQualities *this, void **addr, unsigned int size)
{
  void **v3; // ebp@1
  void *v4; // ebx@1
  CACQualities *v5; // esi@1
  void *v6; // edx@2
  unsigned int v7; // eax@2
  unsigned int v8; // ecx@3
  int v9; // eax@4
  int v10; // edx@5
  int v11; // ebx@5
  AttributeCache *v12; // eax@7
  PackObjVtbl *v13; // eax@8
  int result; // eax@11
  PackObjVtbl *v15; // ecx@13
  PackableHashTable<unsigned long,Skill> *v16; // eax@17
  int v17; // eax@18
  int v18; // ecx@23
  Body *v19; // eax@27
  CBaseQualitiesVtbl *v20; // eax@28
  CBaseQualitiesVtbl *v21; // ecx@33
  CSpellBook *v22; // eax@37
  unsigned int v23; // eax@38
  unsigned int v24; // ecx@43
  CEnchantmentRegistry *v25; // eax@47
  PackableHashTable<unsigned long,long> *v26; // eax@48
  PackableHashTable<unsigned long,long> *v27; // ecx@53
  EventFilter *v28; // eax@57
  PackableHashTable<unsigned long,__int64> *v29; // eax@58
  PackableHashTable<unsigned long,__int64> *v30; // ecx@63
  CEmoteTable *v31; // eax@67
  PackableHashTable<unsigned long,int> *v32; // eax@68
  PackableHashTable<unsigned long,int> *v33; // ecx@73
  void *v34; // eax@77
  PackableHashTable<unsigned long,double> *v35; // ecx@83
  PageDataList *v36; // eax@87
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v37; // eax@88
  PackableHashTable<unsigned long,AC1Legacy::PStringBase<char> > *v38; // ecx@93
  GeneratorTable *v39; // eax@97
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v40; // eax@98
  PackableHashTable<unsigned long,IDClass<_tagDataID,32,0> > *v41; // ecx@103
  GeneratorRegistry *v42; // eax@107
  PackableHashTable<unsigned long,unsigned long> *v43; // eax@108
  PackableHashTable<unsigned long,unsigned long> *v44; // ecx@113
  GeneratorQueue *v45; // eax@117
  PackableHashTable<unsigned long,Position> *v46; // eax@118
  PackableHashTable<unsigned long,Position> *v47; // ecx@123
  void *start; // [sp+34h] [bp-4h]@1
  void **addra; // [sp+3Ch] [bp+4h]@4

  v3 = addr;
  v4 = *addr;
  v5 = this;
  start = *addr;
  if ( !CBaseQualities::UnPack((CBaseQualities *)&this->m_bLoaded, addr, size) )
    return 0;
  v6 = *addr;
  v7 = (_BYTE *)*addr - (_BYTE *)v4;
  if ( size <= v7 )
    return 0;
  v8 = size - v7;
  if ( size - v7 < 4 )
    return 0;
  addra = *(void ***)v6;
  v9 = (int)((char *)v6 + 4);
  *v3 = (char *)v6 + 4;
  if ( v8 - 4 < 4 )
    return 0;
  v10 = *(_DWORD *)v9;
  *v3 = (void *)(v9 + 4);
  v11 = v8 - 8;
  ((void (__stdcall *)(int))v5[-1]._attribCache[1]._health)(v10);
  if ( !((unsigned __int8)addra & 1) )
  {
    v15 = v5->vfptr;
    if ( v15 )
    {
      (*(void (__stdcall **)(signed int))v15->__vecDelDtor)(1);
      v5->vfptr = 0;
    }
LABEL_15:
    if ( (unsigned __int8)addra & 2 )
    {
      if ( !*((_DWORD *)&v5->48 + 1) )
      {
        v16 = (PackableHashTable<unsigned long,Skill> *)operator new(0x14u);
        if ( v16 )
          PackableHashTable<unsigned long,Skill>::PackableHashTable<unsigned long,Skill>(v16, 0);
        else
          v17 = 0;
        *((_DWORD *)&v5->48 + 1) = v17;
      }
      result = (*(int (__stdcall **)(void **, int))(**((_DWORD **)&v5->48 + 1) + 16))(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v18 = *((_DWORD *)&v5->48 + 1);
      if ( v18 )
      {
        (**(void (__stdcall ***)(_DWORD))v18)(1);
        *((_DWORD *)&v5->48 + 1) = 0;
      }
    }
    if ( (unsigned __int8)addra & 4 )
    {
      if ( !v5->vfptr )
      {
        v19 = (Body *)operator new(0x18u);
        if ( v19 )
          Body::Body(v19);
        else
          v20 = 0;
        v5->vfptr = v20;
      }
      result = (*((int (__stdcall **)(void **, int))v5->vfptr->__vecDelDtor + 4))(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v21 = v5->vfptr;
      if ( v21 )
      {
        (*(void (__stdcall **)(signed int))v21->__vecDelDtor)(1);
        v5->vfptr = 0;
      }
    }
    if ( BYTE1(addra) & 1 )
    {
      if ( !v5->_weenie_type )
      {
        v22 = (CSpellBook *)operator new(0x18u);
        if ( v22 )
          CSpellBook::CSpellBook(v22);
        else
          v23 = 0;
        v5->_weenie_type = v23;
      }
      result = (*(int (__stdcall **)(void **, int))(*(_DWORD *)v5->_weenie_type + 16))(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v24 = v5->_weenie_type;
      if ( v24 )
      {
        (**(void (__stdcall ***)(_DWORD))v24)(1);
        v5->_weenie_type = 0;
      }
    }
    if ( BYTE1(addra) & 2 )
    {
      if ( !v5->_intStatsTable )
      {
        v25 = (CEnchantmentRegistry *)operator new(0x1Cu);
        if ( v25 )
          CEnchantmentRegistry::CEnchantmentRegistry(v25);
        else
          v26 = 0;
        v5->_intStatsTable = v26;
      }
      result = ((int (__stdcall *)(void **, int))v5->_intStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v27 = v5->_intStatsTable;
      if ( v27 )
      {
        ((void (__stdcall *)(signed int))v27->vfptr->__vecDelDtor)(1);
        v5->_intStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 8 )
    {
      if ( !v5->_int64StatsTable )
      {
        v28 = (EventFilter *)operator new(0xCu);
        if ( v28 )
          EventFilter::EventFilter(v28);
        else
          v29 = 0;
        v5->_int64StatsTable = v29;
      }
      result = ((int (__stdcall *)(void **, int))v5->_int64StatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v30 = v5->_int64StatsTable;
      if ( v30 )
      {
        ((void (__stdcall *)(signed int))v30->vfptr->__vecDelDtor)(1);
        v5->_int64StatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x10 )
    {
      if ( !v5->_boolStatsTable )
      {
        v31 = (CEmoteTable *)operator new(0x18u);
        if ( v31 )
          CEmoteTable::CEmoteTable(v31);
        else
          v32 = 0;
        v5->_boolStatsTable = v32;
      }
      result = ((int (__stdcall *)(void **, int))v5->_boolStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v33 = v5->_boolStatsTable;
      if ( v33 )
      {
        ((void (__stdcall *)(signed int))v33->vfptr->__vecDelDtor)(1);
        v5->_boolStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x20 )
    {
      if ( !v5->_floatStatsTable )
      {
        v34 = operator new(0x10u);
        if ( v34 )
        {
          *(_DWORD *)v34 = &PackableList<CreationProfile>::vftable;
          *((_DWORD *)v34 + 1) = 0;
          *((_DWORD *)v34 + 2) = 0;
          *((_DWORD *)v34 + 3) = 0;
        }
        else
        {
          v34 = 0;
        }
        v5->_floatStatsTable = (PackableHashTable<unsigned long,double> *)v34;
      }
      result = ((int (__stdcall *)(void **, int))v5->_floatStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v35 = v5->_floatStatsTable;
      if ( v35 )
      {
        ((void (__stdcall *)(signed int))v35->vfptr->__vecDelDtor)(1);
        v5->_floatStatsTable = 0;
      }
    }
    if ( (unsigned __int8)addra & 0x40 )
    {
      if ( !v5->_strStatsTable )
      {
        v36 = (PageDataList *)operator new(0x1Cu);
        if ( v36 )
          PageDataList::PageDataList(v36);
        else
          v37 = 0;
        v5->_strStatsTable = v37;
      }
      result = ((int (__stdcall *)(void **, int))v5->_strStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v38 = v5->_strStatsTable;
      if ( v38 )
      {
        ((void (__stdcall *)(signed int))v38->vfptr->__vecDelDtor)(1);
        v5->_strStatsTable = 0;
      }
    }
    if ( (char)addra >= 0 )
    {
      v41 = v5->_didStatsTable;
      if ( v41 )
      {
        ((void (__stdcall *)(signed int))v41->vfptr->__vecDelDtor)(1);
        v5->_didStatsTable = 0;
      }
    }
    else
    {
      if ( !v5->_didStatsTable )
      {
        v39 = (GeneratorTable *)operator new(0x14u);
        if ( v39 )
          GeneratorTable::GeneratorTable(v39);
        else
          v40 = 0;
        v5->_didStatsTable = v40;
      }
      result = ((int (__stdcall *)(void **, int))v5->_didStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    if ( BYTE1(addra) & 4 )
    {
      if ( !v5->_iidStatsTable )
      {
        v42 = (GeneratorRegistry *)operator new(0x18u);
        if ( v42 )
          GeneratorRegistry::GeneratorRegistry(v42);
        else
          v43 = 0;
        v5->_iidStatsTable = v43;
      }
      result = ((int (__stdcall *)(void **, int))v5->_iidStatsTable->vfptr->UnPack)(v3, v11);
      if ( !result )
        return result;
    }
    else
    {
      v44 = v5->_iidStatsTable;
      if ( v44 )
      {
        ((void (__stdcall *)(signed int))v44->vfptr->__vecDelDtor)(1);
        v5->_iidStatsTable = 0;
      }
    }
    if ( BYTE1(addra) & 8 )
    {
      if ( !v5->_posStatsTable )
      {
        v45 = (GeneratorQueue *)operator new(0x14u);
        if ( v45 )
          GeneratorQueue::GeneratorQueue(v45);
        else
          v46 = 0;
        v5->_posStatsTable = v46;
      }
      if ( !((int (__stdcall *)(void **, int))v5->_posStatsTable->vfptr->UnPack)(v3, v11) )
        return 0;
    }
    else
    {
      v47 = v5->_posStatsTable;
      if ( v47 )
      {
        ((void (__stdcall *)(signed int))v47->vfptr->__vecDelDtor)(1);
        v5->_posStatsTable = 0;
      }
    }
    return PackObj::VERIFY_ADDR(*v3, start, size);
  }
  if ( !v5->vfptr )
  {
    v12 = (AttributeCache *)operator new(0x28u);
    if ( v12 )
      AttributeCache::AttributeCache(v12);
    else
      v13 = 0;
    v5->vfptr = v13;
  }
  result = (*((int (__stdcall **)(void **, int))v5->vfptr->__vecDelDtor + 4))(v3, v11);
  if ( result )
    goto LABEL_15;
  return result;
}
// 7E43BC: using guessed type int (__thiscall *PackableList<CreationProfile>::vftable)(void *, char);

//----- (00593870) --------------------------------------------------------  // acclient.c:444882
void __thiscall PlayerDesc::PlayerDesc(PlayerDesc *this)
{
  int v1; // esi@1
  Interface *v2; // edi@1
  Interface *v3; // ST08_4@1
  InterfaceSystem *v4; // eax@1
  char v5; // [sp+8h] [bp-10h]@1
  TResult tr; // [sp+Ch] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+10h] [bp-8h]@1

  v1 = (int)this;
  CACQualities::CACQualities((CACQualities *)&this->vfptr, wcid);
  *(_DWORD *)v1 = &PlayerDesc::vftable;
  *(_DWORD *)(v1 + 48) = &PlayerDesc::vftable;
  *(_DWORD *)(v1 + 56) = &PlayerDesc::vftable;
  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&v5, v1);
  v2 = spcIFace.m_pInterface;
  v3 = spcIFace.m_pInterface;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::RegisterClassA(v4, &tr, &PlayerDesc_ClassType_31, v3, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
}
// 7E45BC: using guessed type void *PlayerDesc::vftable;
// 7E45EC: using guessed type void *PlayerDesc::vftable;
// 7E4600: using guessed type __int32 (__stdcall *PlayerDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00593910) --------------------------------------------------------  // acclient.c:444912
void __thiscall PlayerDesc::Cleanup(PlayerDesc *this)
{
  Interface *v1; // esi@1
  Interface *v2; // ST08_4@1
  InterfaceSystem *v3; // eax@1
  TResult result; // [sp+4h] [bp-Ch]@1
  InterfacePtr<Interface> spcIFace; // [sp+8h] [bp-8h]@1

  spcIFace.m_pInterface = 0;
  spcIFace.m_trStatus.m_val = 0;
  InterfacePtr<Interface>::_QueryInterface(&spcIFace, (int)&result, (int)this);
  v1 = spcIFace.m_pInterface;
  v2 = spcIFace.m_pInterface;
  v3 = InterfaceSystem::GetInstance();
  InterfaceSystem::UnregisterClassA(v3, &result, &PlayerDesc_ClassType_31, v2, 0);
  if ( v1 )
    v1->vfptr->Release(v1);
}

//----- (00593960) --------------------------------------------------------  // acclient.c:444932
int __thiscall CACQualities::UnPack(void *this, void **a2, unsigned int a3)
{
  return CACQualities::UnPack((CACQualities *)((char *)this - 8), a2, a3);
}

//----- (0070AB70) --------------------------------------------------------  // acclient.c:797930
void sub_70AB70()
{
  flt_87100C = 1000.0 + 1.0;
}

//----- (0070AB90) --------------------------------------------------------  // acclient.c:797936
void sub_70AB90()
{
  flt_871010 = 24.0 * 8.0;
}

//----- (0070ABB0) --------------------------------------------------------  // acclient.c:797942
void sub_70ABB0()
{
  flt_871014 = 24.0 * 0.5;
}

//----- (0070ABD0) --------------------------------------------------------  // acclient.c:797948
int sub_70ABD0()
{
  return atexit(nullsub_1418);
}

