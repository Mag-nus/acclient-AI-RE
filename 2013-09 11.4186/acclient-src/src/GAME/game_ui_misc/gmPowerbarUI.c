/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmPowerbarUI
   Object     : GAME\game_ui_misc\gmPowerbarUI.obj
   Functions  : 23
   Addresses  : 004DA3A0 - 006F5770 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004DA3A0) --------------------------------------------------------  // acclient.c:264971
void __userpurge gmPowerbarUI::gmPowerbarUI(gmPowerbarUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPowerbarUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmPowerbarUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmPowerbarUI::vftable;
  v4->m_pbmCurrentMode = 0;
}
// 7BDE30: using guessed type bool (__thiscall *gmPowerbarUI::vftable)(DBCache *this);
// 7BE0D8: using guessed type int (__thiscall *gmPowerbarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DA3E0) --------------------------------------------------------  // acclient.c:264987
gmPowerbarUI *__thiscall gmPowerbarUI::DynamicCast(gmPowerbarUI *this, unsigned int i_eType)
{
  gmPowerbarUI *result; // eax@1

  result = this;
  if ( i_eType != 268435471 )
    result = (gmPowerbarUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004DA400) --------------------------------------------------------  // acclient.c:264998
signed int gmPowerbarUI::GetUIElementType()
{
  return 268435471;
}

//----- (004DA410) --------------------------------------------------------  // acclient.c:265004
void __thiscall gmPowerbarUI::~gmPowerbarUI(gmPowerbarUI *this)
{
  UIElement_Field *v1; // esi@1
  NoticeHandler *v2; // ecx@1

  v1 = (UIElement_Field *)this;
  v2 = (NoticeHandler *)&this->vfptr;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmPowerbarUI::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&gmPowerbarUI::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field(v1);
}
// 7BDE30: using guessed type bool (__thiscall *gmPowerbarUI::vftable)(DBCache *this);
// 7BE0D8: using guessed type int (__thiscall *gmPowerbarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DA440) --------------------------------------------------------  // acclient.c:265022
UIElement *__usercall gmPowerbarUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x604u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmPowerbarUI::vftable;
    *((_DWORD *)v3 + 382) = &gmPowerbarUI::vftable;
    *((_DWORD *)v3 + 383) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7BDE30: using guessed type bool (__thiscall *gmPowerbarUI::vftable)(DBCache *this);
// 7BE0D8: using guessed type int (__thiscall *gmPowerbarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DA4A0) --------------------------------------------------------  // acclient.c:265048
UIElement_Field *__thiscall gmPowerbarUI::vector_deleting_destructor(gmPowerbarUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmPowerbarUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&gmPowerbarUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BDE30: using guessed type bool (__thiscall *gmPowerbarUI::vftable)(DBCache *this);
// 7BE0D8: using guessed type int (__thiscall *gmPowerbarUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004DA4E0) --------------------------------------------------------  // acclient.c:265069
void __thiscall gmPowerbarUI::PostInit(gmPowerbarUI *this)
{
  gmPowerbarUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100005EEu);
  if ( v2 )
  {
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)3);
    v1->m_RecklessnessField = (UIElement_Field *)v3;
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 24))(v3, 0);
  }
  else
  {
    v1->m_RecklessnessField = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD))(v0 + 24))(0, 0);
  }
}

//----- (004DA530) --------------------------------------------------------  // acclient.c:265092
void __cdecl gmPowerbarUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000000Fu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmPowerbarUI::Create);
}

//----- (004DA550) --------------------------------------------------------  // acclient.c:265100
void __thiscall gmPowerbarUI::RecvNotice_SetPowerbarLevel(gmPowerbarUI *this, PowerBarMode i_pbm, float i_fLevel)
{
  UIElement *v3; // eax@2

  if ( (HashSet<UIElement *>Vtbl *)i_pbm == this->m_hashElementsRegisteredWith.vfptr )
  {
    v3 = UIElement::GetChildRecursive(
           (UIElement *)this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets,
           0x10000034u);
    if ( v3 )
      UIElement::SetAttribute_Float(v3, 0x69u, i_fLevel);
  }
}

//----- (004DA580) --------------------------------------------------------  // acclient.c:265115
void __thiscall gmPowerbarUI::RecvNotice_FinishPowerbar(gmPowerbarUI *this, PowerBarMode i_pbm)
{
  char *v2; // esi@2
  UIElement *v3; // eax@2

  if ( (HashSet<UIElement *>Vtbl *)i_pbm == this->m_hashElementsRegisteredWith.vfptr )
  {
    v2 = (char *)this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets;
    this->m_hashElementsRegisteredWith.vfptr = 0;
    v3 = UIElement::GetChildRecursive(
           (UIElement *)this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets,
           0x10000034u);
    if ( v3 )
      UIElement::SetAttribute_Float(v3, 0x69u, 0.0);
    (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v2 + 24))(v2, 0);
  }
}

//----- (004DA5C0) --------------------------------------------------------  // acclient.c:265134
void __thiscall gmPowerbarUI::RecvNotice_RuntimeDDDStatus(gmPowerbarUI *this, bool bStart, unsigned int current, unsigned int total)
{
  gmPowerbarUI *v4; // esi@1
  unsigned int v5; // eax@4
  unsigned int v6; // eax@4
  unsigned int v7; // eax@5
  unsigned int v8; // edi@6
  UIElement *v9; // esi@7
  UIElement *v10; // eax@7
  IInputActionCallbackVtbl *v11; // edx@8
  UIElement_Text *v12; // eax@8
  UIElement *v13; // eax@10
  unsigned int v14; // [sp-8h] [bp-A8h]@4
  unsigned int v15; // [sp-8h] [bp-A8h]@5
  PStringBase<unsigned short> v16; // [sp-4h] [bp-A4h]@6
  float fProgress; // [sp+Ch] [bp-94h]@4
  StringInfo _info; // [sp+10h] [bp-90h]@4

  v4 = this;
  if ( bStart )
  {
    if ( this->m_hashElementsRegisteredWith.vfptr != (HashSet<UIElement *>Vtbl *)4 )
      ((void (__stdcall *)(_DWORD))this->vfptr[12].__vecDelDtor)(4);
    fProgress = 0.0;
    StringInfo::StringInfo(&_info);
    v5 = compute_str_hash("ID_Powerbar_DDDModeText");
    StringInfo::SetStringIDandTableEnum(&_info, v5, 268435457);
    v6 = compute_str_hash("CURRENT");
    StringInfo::AddVariable_Int(&_info, v6, v14);
    if ( total )
    {
      v7 = compute_str_hash("TOTAL");
      StringInfo::AddVariable_Int(&_info, v7, v15);
      fProgress = (double)current / (double)total;
    }
    else
    {
      v8 = compute_str_hash("TOTAL");
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v16, L"???");
      StringInfo::AddVariable_String(&_info, v8, v16);
    }
    v9 = (UIElement *)v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets;
    v10 = UIElement::GetChildRecursive(v9, 0x10000035u);
    if ( v10 )
    {
      v11 = v10->vfptr;
      v16.m_charbuffer = (PSRefBufferCharData<unsigned short> *)12;
      v12 = (UIElement_Text *)v11[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
    }
    else
    {
      v12 = 0;
    }
    UIElement_Text::SetStringInfo(v12, &_info);
    v13 = UIElement::GetChildRecursive(v9, 0x10000034u);
    if ( v13 )
      UIElement::SetAttribute_Float(v13, 0x69u, fProgress);
    StringInfo::~StringInfo(&_info);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[13].__vecDelDtor)(4);
  }
}

//----- (004DA730) --------------------------------------------------------  // acclient.c:265200
void __thiscall gmPowerbarUI::RecvNotice_BeginPowerbar(gmPowerbarUI *this, PowerBarMode pbm)
{
  PowerBarMode v2; // ebp@1
  gmPowerbarUI *v3; // esi@1
  COMBAT_MODE v4; // ecx@2
  HashSetData<UIElement *> *v5; // eax@2
  bool v6; // zf@2
  int v7; // ecx@2
  InterfacePtr<Interface> *v8; // eax@3
  PlayerDesc *v9; // edi@5
  IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>Vtbl *v10; // ecx@5
  UIElement *v11; // esi@15
  UIElement *v12; // eax@15
  signed int v13; // [sp-4h] [bp-20h]@11
  InterfacePtr<Interface> result; // [sp+Ch] [bp-10h]@3
  InterfacePtr<PlayerDesc> playerDesc; // [sp+14h] [bp-8h]@3

  v2 = pbm;
  v3 = this;
  switch ( pbm )
  {
    case 2:
      v4 = ClientCombatSystem::GetCombatSystem()->combatMode;
      v5 = v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
      v6 = v4 == 2;
      v7 = (int)v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets;
      if ( !v6 )
      {
        ((void (__thiscall *)(int, signed int))v5[19].m_hashNext)(v7, 268435524);
        goto LABEL_14;
      }
      ((void (__thiscall *)(int, signed int))v5[19].m_hashNext)(v7, 268435523);
      v8 = GetClassObject(&result, &PlayerDesc_ClassType_18);
      InterfacePtr<PlayerDesc>::InterfacePtr<PlayerDesc>(&playerDesc, v8);
      if ( (_DWORD)result.m_pInterface )
        ((void (*)(void))result.m_pInterface->vfptr->Release)();
      v9 = playerDesc.m_pInterface;
      CACQualities::InqSkillAdvancementClass(
        (CACQualities *)&playerDesc.m_pInterface->vfptr,
        0x32u,
        (SKILL_ADVANCEMENT_CLASS *)&pbm);
      v10 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr;
      if ( (signed int)pbm < 2 )
        (*((void (__stdcall **)(_DWORD))v10->__vecDelDtor + 6))(0);
      else
        (*((void (__stdcall **)(signed int))v10->__vecDelDtor + 6))(1);
      if ( v9 )
        v9->vfptr->Release((Interface *)v9);
      goto LABEL_15;
    case 3:
      v13 = 268435522;
      goto LABEL_13;
    case 4:
      v13 = 268435525;
LABEL_13:
      ((void (__thiscall *)(int, signed int))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0][19].m_hashNext)(
        this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets,
        v13);
LABEL_14:
      (*((void (__stdcall **)(_DWORD))v3->m_hashElementsRegisteredWith.m_intrusiveTable.vfptr->__vecDelDtor + 6))(0);
      goto LABEL_15;
    case 1:
      return;
    default:
LABEL_15:
      v3->m_hashElementsRegisteredWith.vfptr = (HashSet<UIElement *>Vtbl *)v2;
      v11 = (UIElement *)v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets;
      v12 = UIElement::GetChildRecursive(v11, 0x10000034u);
      if ( v12 )
        UIElement::SetAttribute_Float(v12, 0x69u, 0.0);
      v11->vfptr[2].__vecDelDtor((IInputActionCallback *)v11, 1u);
      break;
  }
}

//----- (006F5670) --------------------------------------------------------  // acclient.c:777903
void sub_6F5670()
{
  flt_840418 = 1000.0 + 1.0;
}

//----- (006F5690) --------------------------------------------------------  // acclient.c:777909
void _E93_86()
{
  flt_84041C = 24.0 * 8.0;
}

//----- (006F56B0) --------------------------------------------------------  // acclient.c:777915
void _E95_86()
{
  flt_840420 = 24.0 * 0.5;
}

//----- (006F56D0) --------------------------------------------------------  // acclient.c:777921
int sub_6F56D0()
{
  return atexit(nullsub_632);
}

//----- (006F56E0) --------------------------------------------------------  // acclient.c:777927
int sub_6F56E0()
{
  return atexit(nullsub_633);
}

//----- (006F56F0) --------------------------------------------------------  // acclient.c:777933
int _E103_96()
{
  return atexit(nullsub_634);
}

//----- (006F5700) --------------------------------------------------------  // acclient.c:777939
void _E106_69()
{
  DEFAULT_VIEW_RADIUS_70 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F5720) --------------------------------------------------------  // acclient.c:777945
void _E108_54()
{
  MIN_QUANTUM_70 = 1.0 / 30.0;
}

//----- (006F5740) --------------------------------------------------------  // acclient.c:777951
void _E110_45()
{
  MAX_QUANTUM_70 = 1.0 / 5.0;
}

//----- (006F5760) --------------------------------------------------------  // acclient.c:777957
void _E112_61()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840438, PFID_A8R8G8B8);
}

//----- (006F5770) --------------------------------------------------------  // acclient.c:777963
int sub_6F5770()
{
  return atexit(nullsub_631);
}

