/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MagicSystem
   Object     : AC\accui_misc\MagicSystem.obj
   Functions  : 62
   Addresses  : 00566E60 - 00708B10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00566E60) --------------------------------------------------------  // acclient.c:403730
ClientMagicSystem *__cdecl ClientMagicSystem::GetMagicSystem()
{
  return ClientMagicSystem::s_pMagicSystem;
}

//----- (00566E70) --------------------------------------------------------  // acclient.c:403736
SpellComponentTable *__thiscall ClientMagicSystem::GetSpellComponentTable(ClientMagicSystem *this)
{
  ClientMagicSystem *v1; // esi@1

  v1 = this;
  if ( !this->spellComponentTable )
    this->spellComponentTable = (SpellComponentTable *)DBObj::GetByEnum(5, 2, 0x10000006u);
  return v1->spellComponentTable;
}

//----- (00566EA0) --------------------------------------------------------  // acclient.c:403747
void __thiscall ClientMagicSystem::OnShutdown(ClientMagicSystem *this)
{
  ClientMagicSystem *v1; // esi@1
  SpellComponentTable *v2; // ecx@1
  CSpellTable *v3; // ecx@3

  v1 = this;
  v2 = this->spellComponentTable;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->spellComponentTable = 0;
  }
  v3 = v1->spellTable;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->spellTable = 0;
  }
  if ( ClientMagicSystem::s_pMagicSystem )
  {
    ((void (*)(void))ClientMagicSystem::s_pMagicSystem->vfptr->Release)();
    ClientMagicSystem::s_pMagicSystem = 0;
  }
}

//----- (00566EF0) --------------------------------------------------------  // acclient.c:403774
void __stdcall ClientMagicSystem::FreeHandsAndCastSpell(unsigned int _spellID, unsigned int _targetID)
{
  ClientUISystem *v3; // eax@2
  ClientUISystem *v4; // eax@3

  ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[16].__vecDelDtor)();
  if ( _targetID )
  {
    CM_Magic::Event_CastTargetedSpell(_targetID, _spellID);
    v4 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v4);
  }
  else
  {
    CM_Magic::Event_CastUntargetedSpell(_spellID);
    v3 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v3);
  }
}

//----- (00566F50) --------------------------------------------------------  // acclient.c:403795
void __thiscall ClientMagicSystem::OnEndCharacterSession(ClientMagicSystem *this)
{
  this->selectedSpell = 0;
  ClientMagicSystem::targetingSpell = 0;
}
// 870440: using guessed type unsigned __int32 ClientMagicSystem::targetingSpell;

//----- (00566F60) --------------------------------------------------------  // acclient.c:403803
TResult *__thiscall ClientMagicSystem::QueryInterface(ClientMagicSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S129_81 & 1 )
  {
    v4 = Offsets_5[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientMagicSystem_InterfaceType_58;
    _S129_81 |= 1u;
    Offsets_5[0].key = (_GUID *)&ClientMagicSystem_InterfaceType_58;
    dword_8704D8 = 0;
    dword_8704DC = (int)&ClientSystem_InterfaceType_84;
    dword_8704E0 = 0;
    dword_8704E4 = (int)&stru_7CE758;
    dword_8704E8 = 0;
    dword_8704EC = 0;
    dword_8704F0 = 0;
  }
  v5 = (int)Offsets_5;
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
// 8704D8: using guessed type int dword_8704D8;
// 8704DC: using guessed type int dword_8704DC;
// 8704E0: using guessed type int dword_8704E0;
// 8704E4: using guessed type int dword_8704E4;
// 8704E8: using guessed type int dword_8704E8;
// 8704EC: using guessed type int dword_8704EC;
// 8704F0: using guessed type int dword_8704F0;

//----- (00567030) --------------------------------------------------------  // acclient.c:403870
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *v2; // esi@1
  HashTableData<unsigned long,Graphic *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CE76C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable[2])(void *, char);

//----- (00567070) --------------------------------------------------------  // acclient.c:403891
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vector_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CE770: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable)(void *, char);

//----- (005670B0) --------------------------------------------------------  // acclient.c:403912
int __thiscall CSpellTable::InqSpellBase(CSpellTable *this, const unsigned int key, CSpellBase *sbase)
{
  unsigned int v3; // esi@1
  PackableHashData<unsigned long,CSpellBase> **v4; // ecx@2
  PackableHashData<unsigned long,CSpellBase> *v5; // edx@3
  int result; // eax@6

  v3 = this->_spellBaseHash._table_size;
  if ( !v3 )
    goto LABEL_12;
  v4 = this->_spellBaseHash._buckets;
  if ( !v4 )
    goto LABEL_12;
  v5 = v4[key % v3];
  if ( !v5 )
    goto LABEL_12;
  while ( key != v5->_key )
  {
    v5 = v5->_next;
    if ( !v5 )
      return 0;
  }
  if ( v5 != (PackableHashData<unsigned long,CSpellBase> *)-8 )
  {
    CSpellBase::operator=((int)sbase, (int)&v5->_data);
    result = 1;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  return result;
}

//----- (00567110) --------------------------------------------------------  // acclient.c:403948
bool __thiscall ClientMagicSystem::InqSpellBase(ClientMagicSystem *this, unsigned int _spellID, CSpellBase *_spellBase)
{
  ClientMagicSystem *v3; // esi@1

  v3 = this;
  if ( !this->spellTable )
    this->spellTable = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  return CSpellTable::InqSpellBase(v3->spellTable, _spellID, _spellBase) != 0;
}

//----- (00567150) --------------------------------------------------------  // acclient.c:403959
AC1Legacy::PStringBase<char> *__thiscall ClientMagicSystem::GetSpellName(ClientMagicSystem *this, AC1Legacy::PStringBase<char> *result, unsigned int _spellID)
{
  ClientMagicSystem *v3; // esi@1
  CSpellBase sBase; // [sp+4h] [bp-90h]@1

  v3 = this;
  CSpellBase::CSpellBase(&sBase);
  if ( !v3->spellTable )
    v3->spellTable = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  CSpellTable::InqSpellBase(v3->spellTable, _spellID, &sBase);
  SpellComponentBase::InqName((SpellComponentBase *)&sBase, result);
  CSpellBase::~CSpellBase(&sBase);
  return result;
}

//----- (005671C0) --------------------------------------------------------  // acclient.c:403975
AC1Legacy::PStringBase<char> *__thiscall ClientMagicSystem::GetSpellDescription(ClientMagicSystem *this, AC1Legacy::PStringBase<char> *result, unsigned int _spellID)
{
  ClientMagicSystem *v3; // esi@1
  CSpellBase sBase; // [sp+4h] [bp-90h]@1

  v3 = this;
  CSpellBase::CSpellBase(&sBase);
  if ( !v3->spellTable )
    v3->spellTable = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  CSpellTable::InqSpellBase(v3->spellTable, _spellID, &sBase);
  CSpellBase::InqDescription(&sBase, result);
  CSpellBase::~CSpellBase(&sBase);
  return result;
}

//----- (00567230) --------------------------------------------------------  // acclient.c:403991
bool __cdecl ClientMagicSystem::ObjectCompatibleWithSpellTargetType(unsigned int _targetID, unsigned int _targetType, bool _quiet)
{
  char *v4; // esi@5
  char *v5; // esi@13
  CPlayerSystem *v6; // eax@17
  CPlayerSystem *v7; // ebp@17
  HashBaseData<unsigned long> *v8; // eax@23
  HashBaseData<unsigned long> *v9; // esi@23
  unsigned int v10; // eax@24
  PStringBase<unsigned short> *v11; // eax@31
  PStringBase<unsigned short> *v12; // eax@36
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@5
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@31
  StringInfo siError; // [sp+10h] [bp-90h]@5

  if ( !_targetType )
  {
    if ( !_targetID )
      return 1;
    if ( _quiet )
      return 0;
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"This spell would require no target");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    v4 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_9;
  }
  if ( !_targetID )
  {
    if ( _quiet )
      return 0;
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"This spell would require a target");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    v5 = (char *)&errorText.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_9:
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  v6 = CPlayerSystem::GetPlayerSystem();
  v7 = v6;
  if ( !(_targetType & 0x8107) && _targetID == v6->playerID )
  {
    if ( _quiet )
      return 0;
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"You cannot cast this spell upon yourself");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_21:
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  v8 = ClientObjMaintSystem::GetWeenieObject(_targetID);
  v9 = v8;
  if ( !v8 )
    return 0;
  v10 = v8[20].id;
  if ( v10 && v10 > 1 )
  {
    if ( _quiet )
      return 0;
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Cannot cast spell on a stack of items.");
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_21;
  }
  if ( !(((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[6].__vecDelDtor)(v9) & _targetType)
    && !(_targetType & 0x8107)
    || !((int (__thiscall *)(HashBaseData<unsigned long> *))v9->vfptr[4].__vecDelDtor)(v9)
    && !((unsigned int)v9[21].hash_next & 0x10) )
  {
    if ( _quiet )
      return 0;
    v11 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v9, &result, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"This spell cannot be cast on %s",
      v11->m_charbuffer);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_37;
  }
  if ( v9[26].id )
  {
    if ( _quiet )
      return 0;
    v12 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v9, &result, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"This spell cannot be cast on %s",
      v12->m_charbuffer);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_37:
    StringInfo::~StringInfo(&siError);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    return 0;
  }
  return ClientObjMaintSystem::GetWeenieObject(v7->playerID) != 0;
}

//----- (00567550) --------------------------------------------------------  // acclient.c:404112
void __stdcall ClientMagicSystem::CompositeSpellIcon(unsigned int _spellID, Graphic *icon)
{
  CSpellTable **v3; // esi@1
  RenderSurface *v4; // esi@5
  SpellFormula *v5; // eax@6
  int v6; // eax@6
  int v7; // edi@6
  SurfaceWindow *v8; // esi@6
  QualifiedDataID *v9; // eax@6
  int v10; // ebx@6
  int v11; // ebp@8
  int v12; // edi@12
  int v13; // [sp-18h] [bp-ECh]@9
  DBObjGrabber<RenderSurface> powerIcon; // [sp+4h] [bp-D0h]@6
  RGBAColor white; // [sp+8h] [bp-CCh]@8
  QualifiedDataID v16; // [sp+18h] [bp-BCh]@6
  CSpellBase spellBase; // [sp+20h] [bp-B4h]@1
  SpellFormula result; // [sp+B0h] [bp-24h]@6

  CSpellBase::CSpellBase(&spellBase);
  v3 = &ClientMagicSystem::s_pMagicSystem->spellTable;
  if ( !ClientMagicSystem::s_pMagicSystem->spellTable )
    *v3 = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  if ( !CSpellTable::InqSpellBase(*v3, _spellID, &spellBase) || (v4 = icon->m_image) == 0 )
  {
    CSpellBase::~CSpellBase(&spellBase);
    return;
  }
  v5 = CSpellBase::InqSpellFormula(&spellBase, &result);
  v6 = SpellFormula::GetPowerLevelOfPowerComponent(v5);
  v7 = DBObj::GetByEnum(v6, 268435462, 0xCu);
  v8 = &v4->window;
  powerIcon.m_object = (RenderSurface *)v7;
  result.vfptr = (PackObjVtbl *)&PackObj::vftable;
  SurfaceWindow::Blit(v8, (SurfaceWindow *)(v7 + 172), 0, 1.0);
  QualifiedDataID::QualifiedDataID(&v16, spellBase._iconID, 0xCu);
  v10 = DBObj::Get(v9);
  if ( v10 )
    SurfaceWindow::Blit(v8, (SurfaceWindow *)(v10 + 172), Blit_4Alpha, 1.0);
  v11 = DBObj::GetByEnum(2 - ((spellBase._bitfield & 0x10) != 0), 268435463, 0xCu);
  LODWORD(white.r) = 1065353216;
  LODWORD(white.g) = 1065353216;
  LODWORD(white.b) = 1065353216;
  LODWORD(white.a) = 1065353216;
  SurfaceWindow::ReplaceColor(v8, &white, (SurfaceWindow *)(v11 + 172));
  if ( BYTE1(spellBase._bitfield) & 0x20 )
  {
    v13 = 4;
LABEL_12:
    v12 = DBObj::GetByEnum(v13, 268435463, 0xCu);
    SurfaceWindow::Blit(v8, (SurfaceWindow *)(v12 + 172), Blit_4Alpha, 1.0);
    if ( v12 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 20))(v12);
    v7 = (int)powerIcon.m_object;
    goto LABEL_15;
  }
  if ( spellBase._bitfield & 8 )
  {
    v13 = 3;
    goto LABEL_12;
  }
LABEL_15:
  if ( v11 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
  if ( v10 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 20))(v10);
  if ( v7 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
  CSpellBase::~CSpellBase(&spellBase);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00567720) --------------------------------------------------------  // acclient.c:404185
void __stdcall ClientMagicSystem::CompositeSpellComponentIcon(IDClass<_tagDataID,32,0> _componentID, Graphic *icon)
{
  RenderSurface *v3; // esi@1
  QualifiedDataID *v4; // eax@2
  int v5; // eax@2
  int v6; // edi@2
  SurfaceWindow *v7; // esi@3
  QualifiedDataID v8; // [sp+4h] [bp-28h]@2
  RGBAColor black; // [sp+Ch] [bp-20h]@3
  RGBAColor white; // [sp+1Ch] [bp-10h]@3

  v3 = icon->m_image;
  if ( v3 )
  {
    QualifiedDataID::QualifiedDataID(&v8, _componentID, 0xCu);
    v5 = DBObj::Get(v4);
    v6 = v5;
    if ( v5 )
    {
      v7 = &v3->window;
      SurfaceWindow::Blit(v7, (SurfaceWindow *)(v5 + 172), 0, 1.0);
      LODWORD(white.r) = 1065353216;
      LODWORD(white.g) = 1065353216;
      LODWORD(white.b) = 1065353216;
      LODWORD(white.a) = 1065353216;
      LODWORD(black.r) = 0;
      LODWORD(black.g) = 0;
      LODWORD(black.b) = 0;
      LODWORD(black.a) = 1065353216;
      SurfaceWindow::ReplaceColor(v7, &white, &black);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
    }
    else
    {
      SurfaceWindow::Fill(&v3->window, &ClientMagicSystem::s_NullColor);
    }
  }
}

//----- (005677F0) --------------------------------------------------------  // acclient.c:404225
unsigned int __stdcall ClientMagicSystem::Handle_Magic__UpdateSpell(unsigned int spell_id)
{
  InterfaceSystem *v2; // eax@1
  Interface *v3; // edi@1
  PlayerDesc *v4; // edi@5
  int v6; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v9; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v9, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::AddSpell((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, spell_id);
    CM_Magic::SendNotice_SpellAdded(spell_id);
    v4->vfptr->Release((Interface *)v4);
  }
  return 0;
}

//----- (00567890) --------------------------------------------------------  // acclient.c:404259
unsigned int __stdcall ClientMagicSystem::Handle_Magic__RemoveSpell(unsigned int spell_id)
{
  InterfaceSystem *v2; // eax@1
  Interface *v3; // edi@1
  PlayerDesc *v4; // edi@5
  int v6; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v9; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v9, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::RemoveSpell((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, spell_id);
    CM_Magic::SendNotice_SpellRemoved(spell_id);
    v4->vfptr->Release((Interface *)v4);
  }
  return 0;
}

//----- (00567930) --------------------------------------------------------  // acclient.c:404293
unsigned int __stdcall ClientMagicSystem::Handle_Magic__UpdateEnchantment(Enchantment *enchant)
{
  InterfaceSystem *v2; // eax@1
  Interface *v3; // edi@1
  PlayerDesc *v4; // edi@5
  int v6; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v9; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v9, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::UpdateEnchantment((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, enchant);
    if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & enchant->_smod.type )
    {
      CM_Magic::SendNotice_VitaeChanged();
      v4->vfptr->Release((Interface *)v4);
      return 0;
    }
    CM_Magic::SendNotice_EnchantmentsChanged();
    v4->vfptr->Release((Interface *)v4);
  }
  return 0;
}

//----- (005679E0) --------------------------------------------------------  // acclient.c:404333
unsigned int __stdcall ClientMagicSystem::Handle_Magic__UpdateMultipleEnchantments(PackableList<Enchantment> *list)
{
  InterfaceSystem *v2; // eax@1
  Interface *v3; // edi@1
  PlayerDesc *v4; // edi@5
  int v6; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v9; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v2 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v2, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v6 = (int)_rpInterface;
  v3 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v9, v6, 0);
  if ( v3 )
    v3->vfptr->Release(v3);
  v4 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::UpdateEnchantments((CACQualities *)&spPlayerDesc.m_pInterface->vfptr, list);
    CM_Magic::SendNotice_EnchantmentsChanged();
    v4->vfptr->Release((Interface *)v4);
  }
  return 0;
}

//----- (00567A70) --------------------------------------------------------  // acclient.c:404367
unsigned int ClientMagicSystem::Handle_Magic__PurgeEnchantments()
{
  InterfaceSystem *v1; // eax@1
  Interface *v2; // edi@1
  PlayerDesc *v3; // edi@5
  int v5; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v8; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v1, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v5 = (int)_rpInterface;
  v2 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v8, v5, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
  v3 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::PurgeEnchantments((CACQualities *)&spPlayerDesc.m_pInterface->vfptr);
    CM_Magic::SendNotice_EnchantmentsChanged();
    CM_Magic::SendNotice_VitaeChanged();
    v3->vfptr->Release((Interface *)v3);
  }
  return 0;
}

//----- (00567B00) --------------------------------------------------------  // acclient.c:404402
unsigned int ClientMagicSystem::Handle_Magic__PurgeBadEnchantments()
{
  InterfaceSystem *v1; // eax@1
  Interface *v2; // edi@1
  PlayerDesc *v3; // edi@5
  int v5; // [sp-8h] [bp-24h]@1
  Interface *_rpInterface; // [sp+8h] [bp-14h]@1
  TResult result; // [sp+Ch] [bp-10h]@1
  char v8; // [sp+10h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+14h] [bp-8h]@1

  _rpInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v1, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v5 = (int)_rpInterface;
  v2 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v8, v5, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
  v3 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    CACQualities::PurgeBadEnchantments((CACQualities *)&spPlayerDesc.m_pInterface->vfptr);
    CM_Magic::SendNotice_EnchantmentsChanged();
    CM_Magic::SendNotice_VitaeChanged();
    v3->vfptr->Release((Interface *)v3);
  }
  return 0;
}

//----- (00567B90) --------------------------------------------------------  // acclient.c:404437
bool ClientMagicSystem::AreSpellComponentsRequired()
{
  InterfaceSystem *v1; // eax@1
  Interface *v2; // esi@1
  PlayerDesc *v3; // esi@5
  bool v4; // bl@5
  int v6; // [sp-8h] [bp-2Ch]@1
  Interface *_rpInterface; // [sp+Ch] [bp-18h]@1
  int required; // [sp+10h] [bp-14h]@1
  TResult result; // [sp+14h] [bp-10h]@1
  char v10; // [sp+18h] [bp-Ch]@3
  InterfacePtr<PlayerDesc> pPlayerDesc; // [sp+1Ch] [bp-8h]@1

  required = 1;
  _rpInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v1, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v6 = (int)_rpInterface;
  v2 = _rpInterface;
  pPlayerDesc.m_pInterface = 0;
  pPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&pPlayerDesc, (int)&v10, v6, 0);
  if ( v2 )
    v2->vfptr->Release(v2);
  v3 = pPlayerDesc.m_pInterface;
  CBaseQualities::InqBool((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, 0x44u, &required);
  v4 = required != 0;
  if ( v3 )
    v3->vfptr->Release((Interface *)v3);
  return v4;
}

//----- (00567C30) --------------------------------------------------------  // acclient.c:404472
char __cdecl ClientMagicSystem::ObjectCompatibleWithSpell(unsigned int _targetID, unsigned int _spellID, bool _quiet, bool _displayCastMessage)
{
  CSpellTable **v4; // esi@2
  signed int v5; // eax@5
  AC1Legacy::PStringBase<char> *v7; // eax@9
  PStringBase<unsigned short> *v8; // eax@9
  AC1Legacy::PStringBase<char> result; // [sp+4h] [bp-128h]@9
  PStringBase<unsigned short> v10; // [sp+8h] [bp-124h]@9
  CSpellBase spellBase; // [sp+Ch] [bp-120h]@2
  StringInfo siError; // [sp+9Ch] [bp-90h]@9

  if ( !_spellID )
    return 0;
  CSpellBase::CSpellBase(&spellBase);
  v4 = &ClientMagicSystem::s_pMagicSystem->spellTable;
  if ( !ClientMagicSystem::s_pMagicSystem->spellTable )
    *v4 = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  if ( !CSpellTable::InqSpellBase(*v4, _spellID, &spellBase)
    || (v5 = CSpellBase::InqTargetType(&spellBase),
        !ClientMagicSystem::ObjectCompatibleWithSpellTargetType(_targetID, v5, _quiet)) )
  {
    CSpellBase::~CSpellBase(&spellBase);
    return 0;
  }
  if ( _displayCastMessage )
  {
    StringInfo::StringInfo(&siError);
    v7 = SpellComponentBase::InqName((SpellComponentBase *)&spellBase, &result);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, 0, L"Casting %hs", v7->m_buffer->m_data);
    StringInfo::SetLiteralValue(&siError, v8, 1);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v10);
    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&result);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
  }
  CSpellBase::~CSpellBase(&spellBase);
  return 1;
}

//----- (00567D50) --------------------------------------------------------  // acclient.c:404512
SpellFormula *__cdecl ClientMagicSystem::GetAppropriateSpellFormula(SpellFormula *result, CSpellBase *sBase)
{
  CSpellBase *v2; // esi@1
  CPlayerSystem *v3; // edi@1
  PlayerDesc *v4; // edi@2
  AC1Legacy::PSRefBuffer<char> *v5; // esi@2
  SpellFormula *v6; // eax@8
  InterfaceSystem *v7; // eax@9
  AC1Legacy::PSRefBuffer<char> *v8; // ebp@9
  PlayerDesc *v9; // ebp@13
  PlayerDesc *v10; // edi@21
  AC1Legacy::PSRefBuffer<char> *v11; // esi@21
  unsigned int v12; // [sp-10h] [bp-44h]@14
  int *v13; // [sp-Ch] [bp-40h]@14
  int v14; // [sp-8h] [bp-3Ch]@9
  AC1Legacy::PStringBase<char> account_name; // [sp+10h] [bp-24h]@2
  IDClass<_tagDataID,32,0> wcidEssence; // [sp+14h] [bp-20h]@1
  ACCWeenieObject *myObj; // [sp+18h] [bp-1Ch]@1
  TResult v18; // [sp+1Ch] [bp-18h]@9
  char v19; // [sp+20h] [bp-14h]@11
  InterfacePtr<PlayerDesc> pPlayerDesc; // [sp+24h] [bp-10h]@2

  v2 = sBase;
  SpellComponentTable::SchoolOfMagic2WCID(&wcidEssence, sBase->_school);
  v3 = CPlayerSystem::GetPlayerSystem();
  myObj = (ACCWeenieObject *)ClientObjMaintSystem::GetWeenieObject(v3->playerID);
  if ( myObj )
  {
    sBase = 0;
    account_name.m_buffer = 0;
    v7 = InterfaceSystem::GetInstance();
    InterfaceSystem::GetClass(v7, &v18, &PlayerDesc_ClassType_28, (Interface **)&account_name);
    v14 = (int)account_name.m_buffer;
    v8 = account_name.m_buffer;
    pPlayerDesc.m_pInterface = 0;
    pPlayerDesc.m_trStatus.m_val = 0;
    if ( account_name.m_buffer )
      ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))account_name.m_buffer->vfptr[4].__vecDelDtor)(account_name.m_buffer);
    InterfacePtr<PlayerDesc>::_QueryInterface(&pPlayerDesc, (int)&v19, v14, 0);
    if ( v8 )
      ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))v8->vfptr[5].__vecDelDtor)(v8);
    v9 = pPlayerDesc.m_pInterface;
    switch ( v2->_school )
    {
      case 1u:
        v13 = (int *)&sBase;
        v12 = 297;
        goto LABEL_19;
      case 2u:
        v13 = (int *)&sBase;
        v12 = 296;
        goto LABEL_19;
      case 3u:
        v13 = (int *)&sBase;
        v12 = 295;
        goto LABEL_19;
      case 4u:
        v13 = (int *)&sBase;
        v12 = 294;
        goto LABEL_19;
      case 5u:
        v13 = (int *)&sBase;
        v12 = 328;
LABEL_19:
        CBaseQualities::InqInt((CBaseQualities *)&pPlayerDesc.m_pInterface->vfptr, v12, v13, 0, 0);
        if ( (signed int)sBase <= 0 )
          goto LABEL_20;
        goto LABEL_30;
      default:
LABEL_20:
        if ( ACCWeenieObject::MagicPackIsOwned(myObj, wcidEssence) )
        {
LABEL_30:
          CSpellBase::InqScarabOnlyFormula(v2, result);
          if ( v9 )
            v9->vfptr->Release((Interface *)v9);
          v6 = result;
        }
        else
        {
          accountID::accountID((accountID *)&pPlayerDesc, &v3->account_);
          v10 = pPlayerDesc.m_pInterface;
          AC1Legacy::PStringBase<char>::PStringBase<char>(
            &account_name,
            (const char *)&pPlayerDesc.m_pInterface->m_timeStamp + 4);
          CSpellBase::InqCustomizedSpellFormula(v2, result, &account_name);
          v11 = account_name.m_buffer;
          if ( !InterlockedDecrement((volatile LONG *)&account_name.m_buffer->m_cRef) && v11 )
            v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
          if ( !InterlockedDecrement((volatile LONG *)&v10->m_dataCategory) && v10 )
            ((void (__thiscall *)(PlayerDesc *, signed int))v10->vfptr->IUnknown_QueryInterface)(v10, 1);
          if ( v9 )
            v9->vfptr->Release((Interface *)v9);
          v6 = result;
        }
        break;
    }
  }
  else
  {
    accountID::accountID((accountID *)&pPlayerDesc, &v3->account_);
    v4 = pPlayerDesc.m_pInterface;
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      &account_name,
      (const char *)&pPlayerDesc.m_pInterface->m_timeStamp + 4);
    CSpellBase::InqCustomizedSpellFormula(v2, result, &account_name);
    v5 = account_name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&account_name.m_buffer->m_cRef) && v5 )
      v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_dataCategory) )
    {
      if ( v4 )
        ((void (__thiscall *)(PlayerDesc *, signed int))v4->vfptr->IUnknown_QueryInterface)(v4, 1);
    }
    v6 = result;
  }
  return v6;
}

//----- (00567FA0) --------------------------------------------------------  // acclient.c:404632
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::resize_internal(v2, *v3);
}

//----- (00567FF0) --------------------------------------------------------  // acclient.c:404650
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::grow(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00568040) --------------------------------------------------------  // acclient.c:404670
void __cdecl ClientMagicSystem::CastSpell(unsigned int _spellID)
{
  CSpellTable **v1; // esi@1
  CPlayerSystem *v2; // eax@6
  ComponentTracker *v3; // eax@6
  ComponentTracker *v4; // edi@6
  int v5; // esi@6
  const unsigned int v6; // eax@9
  IDClass<_tagDataID,32,0> *v7; // eax@11
  unsigned int v8; // esi@16
  ClientUISystem *v9; // eax@22
  unsigned int v10; // esi@23
  unsigned int v11; // esi@26
  IDClass<_tagDataID,32,0> result; // [sp+8h] [bp-148h]@11
  SpellFormula formula; // [sp+Ch] [bp-144h]@6
  CSpellBase spellBase; // [sp+30h] [bp-120h]@1
  StringInfo siError; // [sp+C0h] [bp-90h]@16

  CSpellBase::CSpellBase(&spellBase);
  v1 = &ClientMagicSystem::s_pMagicSystem->spellTable;
  if ( !ClientMagicSystem::s_pMagicSystem->spellTable )
    *v1 = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
  if ( !CSpellTable::InqSpellBase(*v1, _spellID, &spellBase) )
  {
    CSpellBase::~CSpellBase(&spellBase);
    return;
  }
  if ( ClientMagicSystem::AreSpellComponentsRequired()
    && (ClientMagicSystem::GetAppropriateSpellFormula(&formula, &spellBase),
        v2 = CPlayerSystem::GetPlayerSystem(),
        CPlayerSystem::GetComponentTracker(v2),
        v4 = v3,
        v5 = 0,
        SpellFormula::GetNumSpellComponents(&formula) > 0) )
  {
    while ( 1 )
    {
      v6 = v5 < 0 || v5 >= 8 ? 0 : formula._comps[v5];
      v7 = SpellComponentTable::SCIDtoWCID(&result, v6);
      if ( !ComponentTracker::ComponentIsOwned(v4, (IDClass<_tagDataID,32,0>)v7->id) )
        break;
      ++v5;
      if ( v5 >= SpellFormula::GetNumSpellComponents(&formula) )
        goto LABEL_13;
    }
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&result,
      L"You do not have all of this spell's components");
    StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&result, 1);
    v8 = result.id - 20;
    if ( !InterlockedDecrement((volatile LONG *)(result.id - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    formula.vfptr = (PackObjVtbl *)&PackObj::vftable;
    CSpellBase::~CSpellBase(&spellBase);
  }
  else
  {
LABEL_13:
    if ( spellBase._bitfield & 8 )
    {
      if ( SmartBox::smartbox )
      {
        ClientMagicSystem::FreeHandsAndCastSpell(_spellID, SmartBox::smartbox->player_id);
        CSpellBase::~CSpellBase(&spellBase);
      }
      else
      {
        ClientMagicSystem::FreeHandsAndCastSpell(_spellID, 0);
        CSpellBase::~CSpellBase(&spellBase);
      }
    }
    else
    {
      if ( !CSpellBase::InqTargetType(&spellBase) )
      {
        ((void (*)(void))SmartBox::smartbox->cmdinterp->vfptr[16].__vecDelDtor)();
        CM_Magic::Event_CastUntargetedSpell(_spellID);
        v9 = ClientUISystem::GetUISystem();
        ClientUISystem::IncrementBusyCount(v9);
        CSpellBase::~CSpellBase(&spellBase);
        return;
      }
      v10 = ACCWeenieObject::selectedID;
      if ( ACCWeenieObject::selectedID )
      {
        if ( ClientMagicSystem::ObjectCompatibleWithSpell(ACCWeenieObject::selectedID, _spellID, 0, 1) )
        {
          ClientMagicSystem::FreeHandsAndCastSpell(_spellID, v10);
          ACCWeenieObject::SetSelectedObject(v10, 0);
          CSpellBase::~CSpellBase(&spellBase);
          return;
        }
      }
      else
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&result,
          L"You must select a suitable target before casting this spell");
        StringInfo::SetLiteralValue(&siError, (PStringBase<unsigned short> *)&result, 1);
        v11 = result.id - 20;
        if ( !InterlockedDecrement((volatile LONG *)(result.id - 20 + 4)) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
      }
      CSpellBase::~CSpellBase(&spellBase);
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00568320) --------------------------------------------------------  // acclient.c:404786
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,Graphic *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,Graphic *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CE76C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable[2])(void *, char);

//----- (005683B0) --------------------------------------------------------  // acclient.c:404819
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7CE770: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable)(void *, char);

//----- (00568440) --------------------------------------------------------  // acclient.c:404852
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned long,Graphic *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned long,Graphic *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned long,Graphic *> **v9; // ebx@7
  HashTableData<unsigned long,Graphic *> *v10; // ecx@7
  HashTableData<unsigned long,Graphic *> *v11; // eax@9
  HashTableData<unsigned long,Graphic *> *v12; // edx@10
  HashTableData<unsigned long,Graphic *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<unsigned long,Graphic *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned long,Graphic *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<unsigned long,Graphic *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<unsigned long,Graphic *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<unsigned long,Graphic *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<unsigned long,Graphic *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00568580) --------------------------------------------------------  // acclient.c:404968
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v9; // ebx@7
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v10; // ecx@7
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v11; // eax@9
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v12; // edx@10
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey.id % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (005686C0) --------------------------------------------------------  // acclient.c:405086
char __thiscall ClientMagicSystem::NotifyOfEnchantmentRemoval(ClientMagicSystem *this, unsigned int eid)
{
  ClientSystem *v2; // ebp@1
  int v3; // edi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@1
  CSpellTable **v5; // esi@6
  AC1Legacy::PSRefBuffer<char> *v7; // esi@12
  unsigned int v8; // eax@12
  AC1Legacy::PSRefBuffer<char> *v9; // esi@17
  AC1Legacy::PStringBase<char> account_name; // [sp+10h] [bp-98h]@1
  AC1Legacy::PStringBase<char> msg; // [sp+14h] [bp-94h]@10
  CSpellBase spellBase; // [sp+18h] [bp-90h]@6

  v2 = (ClientSystem *)this;
  AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, &name);
  v3 = gmCCommunicationSystem::IsSquelched(0, &account_name, 7u);
  v4 = account_name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&account_name.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  if ( !v3 && (unsigned __int16)eid < 0x8000u )
  {
    CSpellBase::CSpellBase(&spellBase);
    v5 = &ClientMagicSystem::s_pMagicSystem->spellTable;
    if ( !ClientMagicSystem::s_pMagicSystem->spellTable )
      *v5 = (CSpellTable *)DBObj::GetByEnum(6, 2, 0x10000005u);
    if ( !CSpellTable::InqSpellBase(*v5, (unsigned __int16)eid, &spellBase) )
    {
      CSpellBase::~CSpellBase(&spellBase);
      return 0;
    }
    SpellComponentBase::InqName((SpellComponentBase *)&spellBase, &msg);
    if ( (unsigned __int16)eid == 666 )
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, " penalty");
      AC1Legacy::PStringBase<char>::operator+=(&msg, &account_name);
      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&account_name);
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&account_name, " has expired.\n");
    v7 = account_name.m_buffer;
    v8 = account_name.m_buffer->m_len;
    if ( v8 != 1 && account_name.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&msg, account_name.m_buffer->m_data, v8 - 1);
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    ClientSystem::AddTextToScroll(v2, msg.m_buffer->m_data, 7u, 1, 0);
    v9 = msg.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_buffer->m_cRef) )
    {
      if ( v9 )
        v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    }
    CSpellBase::~CSpellBase(&spellBase);
  }
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00568850) --------------------------------------------------------  // acclient.c:405144
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *this, HashTableData<unsigned long,Graphic *> *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,Graphic *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,Graphic *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,Graphic *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,Graphic *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (005688D0) --------------------------------------------------------  // acclient.c:405188
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::add(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *this, HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != data->m_hashKey.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00568950) --------------------------------------------------------  // acclient.c:405232
unsigned int __thiscall ClientMagicSystem::Handle_Magic__RemoveEnchantment(ClientMagicSystem *this, unsigned int eid, bool fNotify)
{
  ClientMagicSystem *v3; // ebp@1
  InterfaceSystem *v4; // eax@1
  Interface *v5; // esi@1
  CACQualities *v6; // esi@5
  unsigned int v7; // edi@5
  int v9; // [sp-8h] [bp-7Ch]@1
  Interface *_rpInterface; // [sp+10h] [bp-64h]@1
  TResult result; // [sp+14h] [bp-60h]@1
  char v12; // [sp+18h] [bp-5Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+1Ch] [bp-58h]@1
  Enchantment enchant; // [sp+24h] [bp-50h]@6
  char eida; // [sp+78h] [bp+4h]@6

  v3 = this;
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v9 = (int)_rpInterface;
  v5 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v12, v9, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v6 = (CACQualities *)spPlayerDesc.m_pInterface;
  v7 = eid;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    eida = 0;
    Enchantment::Enchantment(&enchant);
    if ( CACQualities::InqVitae(v6, &enchant) && enchant._id == v7 )
      eida = 1;
    CACQualities::RemoveEnchantment(v6, v7);
    if ( eida )
      CM_Magic::SendNotice_VitaeChanged();
    else
      CM_Magic::SendNotice_EnchantmentsChanged();
  }
  if ( fNotify )
    ClientMagicSystem::NotifyOfEnchantmentRemoval(v3, v7);
  if ( v6 )
    v6->vfptr->Release((Interface *)v6);
  return 0;
}

//----- (00568A30) --------------------------------------------------------  // acclient.c:405282
unsigned int __thiscall ClientMagicSystem::Handle_Magic__RemoveMultipleEnchantments(ClientMagicSystem *this, PackableList<unsigned long> *eidList, bool fNotify)
{
  unsigned int v3; // ebp@1
  InterfaceSystem *v4; // eax@1
  Interface *v5; // esi@1
  CACQualities *v6; // edi@5
  PackableList<unsigned long> *v7; // esi@5
  int v9; // [sp-8h] [bp-80h]@1
  Interface *_rpInterface; // [sp+10h] [bp-68h]@1
  ClientMagicSystem *v11; // [sp+14h] [bp-64h]@1
  TResult result; // [sp+18h] [bp-60h]@1
  char v13; // [sp+1Ch] [bp-5Ch]@3
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+20h] [bp-58h]@1
  Enchantment enchant; // [sp+28h] [bp-50h]@6

  v11 = this;
  v3 = 0;
  _rpInterface = 0;
  v4 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v4, &result, &PlayerDesc_ClassType_28, &_rpInterface);
  v9 = (int)_rpInterface;
  v5 = _rpInterface;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( _rpInterface )
    _rpInterface->vfptr->AddRef(_rpInterface);
  InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v13, v9, 0);
  if ( v5 )
    v5->vfptr->Release(v5);
  v6 = (CACQualities *)spPlayerDesc.m_pInterface;
  v7 = eidList;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    Enchantment::Enchantment(&enchant);
    if ( CACQualities::InqVitae(v6, &enchant) )
      v3 = enchant._id;
    CACQualities::RemoveEnchantments(v6, eidList);
    CM_Magic::SendNotice_EnchantmentsChanged();
  }
  while ( 1 )
  {
    v7 = (PackableList<unsigned long> *)v7->head;
    if ( !v7 )
      break;
    if ( fNotify )
      ClientMagicSystem::NotifyOfEnchantmentRemoval(v11, (unsigned int)v7->vfptr);
    if ( v7->vfptr == (PackObjVtbl *)v3 )
      CM_Magic::SendNotice_VitaeChanged();
  }
  if ( v6 )
    v6->vfptr->Release((Interface *)v6);
  return 0;
}

//----- (00568B10) --------------------------------------------------------  // acclient.c:405337
unsigned int __thiscall ClientMagicSystem::Handle_Magic__DispelEnchantment(ClientMagicSystem *this, unsigned int eid)
{
  return ClientMagicSystem::Handle_Magic__RemoveEnchantment(this, eid, 0);
}

//----- (00568B20) --------------------------------------------------------  // acclient.c:405343
unsigned int __thiscall ClientMagicSystem::Handle_Magic__DispelMultipleEnchantments(ClientMagicSystem *this, PackableList<unsigned long> *eidList)
{
  return ClientMagicSystem::Handle_Magic__RemoveMultipleEnchantments(this, eidList, 0);
}

//----- (00568B30) --------------------------------------------------------  // acclient.c:405349
char __thiscall HashTable<unsigned long,Graphic *,1>::add(HashTable<unsigned long,Graphic *,1> *this, const unsigned int *_key, Graphic *const *_data)
{
  HashTable<unsigned long,Graphic *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,Graphic *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00568B90) --------------------------------------------------------  // acclient.c:405385
char __thiscall HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::add(HashTable<IDClass<_tagDataID,32,0>,Graphic *,1> *this, IDClass<_tagDataID,32,0> *_key, Graphic *const *_data)
{
  HashTable<IDClass<_tagDataID,32,0>,Graphic *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = _key->id;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (00568BF0) --------------------------------------------------------  // acclient.c:405421
Graphic *__thiscall ClientMagicSystem::GetSpellIcon(ClientMagicSystem *this, unsigned int _spellID)
{
  ClientMagicSystem *v2; // ebx@1
  Graphic *v3; // esi@1
  HashTableData<unsigned long,Graphic *> *v4; // eax@1
  int v5; // eax@7
  RenderSurface *v6; // edi@7
  int v7; // ebp@8
  PixelFormatID v8; // eax@8
  Graphic *v9; // eax@9
  Graphic *v10; // eax@10
  Graphic *icon; // [sp+10h] [bp-4h]@1

  icon = (Graphic *)this;
  v2 = this;
  v3 = 0;
  v4 = this->m_hashSpellIconTable.m_intrusiveTable.m_buckets[_spellID
                                                           % this->m_hashSpellIconTable.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_7;
  while ( v4->m_hashKey != _spellID )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_7;
  }
  if ( !v4 || (v3 = v4->m_data) == 0 )
  {
LABEL_7:
    v5 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
    v6 = (RenderSurface *)v5;
    if ( v5 )
    {
      v7 = *(_DWORD *)v5;
      v8 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
      if ( (unsigned __int8)(*(int (__thiscall **)(RenderSurface *, signed int, signed int, PixelFormatID, signed int))(v7 + 88))(
                              v6,
                              32,
                              32,
                              v8,
                              1) )
      {
        v9 = (Graphic *)operator new(0xCu);
        if ( v9 )
        {
          Graphic::Graphic(v9, v6);
          v3 = v10;
        }
        else
        {
          v3 = 0;
        }
        icon = v3;
        HashTable<unsigned long,Graphic *,1>::add(&v2->m_hashSpellIconTable, &_spellID, &icon);
        ClientMagicSystem::CompositeSpellIcon(_spellID, v3);
      }
      v6->vfptr->Release((Interface *)v6);
    }
  }
  return v3;
}

//----- (00568CB0) --------------------------------------------------------  // acclient.c:405484
Graphic *__thiscall ClientMagicSystem::GetSpellComponentIcon(ClientMagicSystem *this, IDClass<_tagDataID,32,0> _componentID)
{
  ClientMagicSystem *v2; // ebx@1
  Graphic *v3; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v4; // eax@1
  int v5; // eax@7
  RenderSurface *v6; // edi@7
  int v7; // ebp@8
  PixelFormatID v8; // eax@8
  Graphic *v9; // eax@9
  Graphic *v10; // eax@10
  Graphic *icon; // [sp+10h] [bp-4h]@1

  icon = (Graphic *)this;
  v2 = this;
  v3 = 0;
  v4 = this->m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets[_componentID.id
                                                                    % this->m_hashSpellComponentIconTable.m_intrusiveTable.m_numBuckets];
  if ( !v4 )
    goto LABEL_7;
  while ( v4->m_hashKey.id != _componentID.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_7;
  }
  if ( !v4 || (v3 = v4->m_data) == 0 )
  {
LABEL_7:
    v5 = (*(int (**)(void))&RenderDevice::render_device->vfptr->gap4[8])();
    v6 = (RenderSurface *)v5;
    if ( v5 )
    {
      v7 = *(_DWORD *)v5;
      v8 = RenderDevice::GetUISurfaceFormat(RenderDevice::render_device);
      if ( (unsigned __int8)(*(int (__thiscall **)(RenderSurface *, signed int, signed int, PixelFormatID, signed int))(v7 + 88))(
                              v6,
                              32,
                              32,
                              v8,
                              1) )
      {
        v9 = (Graphic *)operator new(0xCu);
        if ( v9 )
        {
          Graphic::Graphic(v9, v6);
          v3 = v10;
        }
        else
        {
          v3 = 0;
        }
        icon = v3;
        HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::add(&v2->m_hashSpellComponentIconTable, &_componentID, &icon);
        ClientMagicSystem::CompositeSpellComponentIcon(_componentID, v3);
      }
      v6->vfptr->Release((Interface *)v6);
    }
  }
  return v3;
}

//----- (00568D70) --------------------------------------------------------  // acclient.c:405547
HashTable<unsigned long,Graphic *,1> *__thiscall HashTable<unsigned long,Graphic *,1>::vector_deleting_destructor(HashTable<unsigned long,Graphic *,1> *this, unsigned int a2)
{
  HashTable<unsigned long,Graphic *,1> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,Graphic *,1>Vtbl *)HashTable<unsigned long,Graphic *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CE76C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable[2])(void *, char);
// 7CE9FC: using guessed type int (__thiscall *HashTable<unsigned long,Graphic *,1>::vftable[2])(void *, char);

//----- (00568DD0) --------------------------------------------------------  // acclient.c:405573
HashTable<IDClass<_tagDataID,32,0>,Graphic *,1> *__thiscall HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vector_deleting_destructor(HashTable<IDClass<_tagDataID,32,0>,Graphic *,1> *this, unsigned int a2)
{
  HashTable<IDClass<_tagDataID,32,0>,Graphic *,1> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7CE770: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable)(void *, char);
// 7CEA00: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable)(void *, char);

//----- (00568E30) --------------------------------------------------------  // acclient.c:405599
void __thiscall ClientMagicSystem::ClientMagicSystem(ClientMagicSystem *this)
{
  ClientMagicSystem *v1; // esi@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientMagicSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  this->spellTable = 0;
  this->spellComponentTable = 0;
  this->selectedSpell = 0;
  this->m_hashSpellIconTable.vfptr = (HashTable<unsigned long,Graphic *,1>Vtbl *)HashTable<unsigned long,Graphic *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>(
    &this->m_hashSpellIconTable.m_intrusiveTable,
    0x17u);
  v1->m_hashSpellComponentIconTable.vfptr = (HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>(
    &v1->m_hashSpellComponentIconTable.m_intrusiveTable,
    0x17u);
  ClientMagicSystem::s_pMagicSystem = v1;
  InterlockedIncrement((volatile LONG *)&v1->m_cTurbineRefCount.m_cRef);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CE9FC: using guessed type int (__thiscall *HashTable<unsigned long,Graphic *,1>::vftable[2])(void *, char);
// 7CEA00: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable)(void *, char);
// 7CEA04: using guessed type __int32 (__stdcall *ClientMagicSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00568EA0) --------------------------------------------------------  // acclient.c:405630
void __thiscall ClientMagicSystem::~ClientMagicSystem(ClientMagicSystem *this)
{
  ClientMagicSystem *v1; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v2; // ebx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  HeritageGroup_CGVtbl *v7; // ecx@2
  int v8; // ecx@8
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v9; // eax@9
  int v10; // eax@10
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v11; // eax@11
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *v12; // edi@11
  HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **v13; // esi@13
  Graphic *v14; // ecx@14
  void *v15; // eax@20
  void *v16; // eax@22
  NoticeHandler *v17; // [sp+10h] [bp-1Ch]@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v18; // [sp+14h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+20h] [bp-Ch]@1

  v1 = this;
  v17 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v2 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_hashSpellIconTable.m_intrusiveTable;
  this->vfptr = (InterfaceVtbl *)&ClientMagicSystem::vftable;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashSpellIconTable.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currHashTable;
  v6 = v3->m_currBucket;
  v18 = v3->m_currHashTable;
  if ( v4 )
  {
    do
    {
LABEL_2:
      v7 = v4->m_data.vfptr;
      if ( v7 )
      {
        (*(void (__stdcall **)(_DWORD))v7->Serialize)(1);
        v5 = v18;
      }
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v4 = *v6;
        if ( *v6 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(v2);
  v8 = (int)&v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets[v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_numBuckets];
  if ( v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v8 )
  {
LABEL_11:
    v11 = 0;
    v12 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_firstInterestingBucket;
      if ( *v9 )
        break;
      v10 = (int)(v9 + 1);
      v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,Graphic *> **)v10;
      if ( v10 == v8 )
        goto LABEL_11;
    }
    v11 = v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_firstInterestingBucket;
    v12 = *v11;
  }
  v13 = v11;
  if ( v12 )
  {
    do
    {
LABEL_14:
      v14 = v12->m_data;
      if ( v14 )
        ((void (__stdcall *)(_DWORD))v14->vfptr->__vecDelDtor)(1);
      v12 = v12->m_hashNext;
    }
    while ( v12 );
    while ( 1 )
    {
      ++v13;
      if ( v13 == &v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets[v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_numBuckets] )
        break;
      if ( *v13 )
      {
        v12 = *v13;
        if ( *v13 )
          goto LABEL_14;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashSpellComponentIconTable.m_intrusiveTable);
  v1->m_hashSpellComponentIconTable.vfptr = (HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>Vtbl *)&HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashSpellComponentIconTable.m_intrusiveTable);
  v15 = v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets;
  v1->m_hashSpellComponentIconTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>Vtbl *)&IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable;
  if ( v15 != v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v15);
  v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_buckets = 0;
  v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashSpellComponentIconTable.m_intrusiveTable.m_numElements = 0;
  v1->m_hashSpellIconTable.vfptr = (HashTable<unsigned long,Graphic *,1>Vtbl *)HashTable<unsigned long,Graphic *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_hashSpellIconTable.m_intrusiveTable);
  v16 = v1->m_hashSpellIconTable.m_intrusiveTable.m_buckets;
  v1->m_hashSpellIconTable.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable;
  if ( v16 != v1->m_hashSpellIconTable.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v16);
  v1->m_hashSpellIconTable.m_intrusiveTable.m_buckets = 0;
  v1->m_hashSpellIconTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashSpellIconTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashSpellIconTable.m_intrusiveTable.m_numElements = 0;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v17->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v17);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CE76C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable[2])(void *, char);
// 7CE770: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable)(void *, char);
// 7CE9FC: using guessed type int (__thiscall *HashTable<unsigned long,Graphic *,1>::vftable[2])(void *, char);
// 7CEA00: using guessed type int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable)(void *, char);
// 7CEA04: using guessed type __int32 (__stdcall *ClientMagicSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00569030) --------------------------------------------------------  // acclient.c:405775
unsigned int __thiscall ClientMagicSystem::Release(ClientMagicSystem *this)
{
  ClientMagicSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientMagicSystem::~ClientMagicSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (007089D0) --------------------------------------------------------  // acclient.c:795866
void sub_7089D0()
{
  flt_870470 = 1000.0 + 1.0;
}

//----- (007089F0) --------------------------------------------------------  // acclient.c:795872
void sub_7089F0()
{
  flt_870474 = 24.0 * 8.0;
}

//----- (00708A10) --------------------------------------------------------  // acclient.c:795878
void sub_708A10()
{
  flt_870478 = 24.0 * 0.5;
}

//----- (00708A30) --------------------------------------------------------  // acclient.c:795884
int sub_708A30()
{
  return atexit(nullsub_1360);
}

//----- (00708A40) --------------------------------------------------------  // acclient.c:795890
int sub_708A40()
{
  return atexit(nullsub_1361);
}

//----- (00708A50) --------------------------------------------------------  // acclient.c:795896
int sub_708A50()
{
  return atexit(nullsub_1362);
}

//----- (00708A60) --------------------------------------------------------  // acclient.c:795902
void sub_708A60()
{
  flt_87047C = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708A80) --------------------------------------------------------  // acclient.c:795908
void _E108_88()
{
  dbl_870480 = 1.0 / 30.0;
}

//----- (00708AA0) --------------------------------------------------------  // acclient.c:795914
void _E110_72()
{
  dbl_870488 = 1.0 / 5.0;
}

//----- (00708AC0) --------------------------------------------------------  // acclient.c:795920
void sub_708AC0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870490, PFID_A8R8G8B8);
}

//----- (00708AD0) --------------------------------------------------------  // acclient.c:795926
void _E115_72()
{
  dword_8704C8 = 1024;
}

//----- (00708AE0) --------------------------------------------------------  // acclient.c:795932
void _E117_68()
{
  dword_8704CC = 0x7FFF;
}

//----- (00708AF0) --------------------------------------------------------  // acclient.c:795938
int _E119_22()
{
  const int result; // eax@1

  result = dword_8704C8;
  dword_8704D0 = dword_8704C8;
  return result;
}

//----- (00708B00) --------------------------------------------------------  // acclient.c:795948
int _E121_63()
{
  return atexit(_E122_90);
}

//----- (00708B10) --------------------------------------------------------  // acclient.c:795954
int sub_708B10()
{
  return atexit(nullsub_1359);
}

