/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCombatPanelUI
   Object     : GAME\game_ui_misc\gmCombatPanelUI.obj
   Functions  : 23
   Addresses  : 004F5900 - 006F8E00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F5900) --------------------------------------------------------  // acclient.c:289111
void __userpurge gmCombatPanelUI::RecvNotice_SetPanelVisibility(gmCombatPanelUI *this@<ecx>, int a2@<edi>, unsigned int i_ePanelID, bool i_bVisible)
{
  gmCombatPanelUI *v4; // esi@1
  HashSetData<UIElement *> *v5; // eax@2
  HashSetData<UIElement *> *v6; // ecx@2
  HashSet<UIElement *>Vtbl *v7; // eax@3
  HashSetData<UIElement *> *v8; // edi@8
  char v9; // bl@8
  HashSetData<UIElement *> *v10; // ecx@9
  UIElement *v11; // edx@14
  HashSetData<UIElement *> *v12; // ecx@21
  HashSetData<UIElement *> *v13; // eax@23
  int v14; // [sp-8h] [bp-Ch]@3

  v4 = this;
  if ( i_ePanelID )
  {
    v5 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
    v6 = 0;
    if ( v5 )
    {
      v7 = v4->m_hashElementsRegisteredWith.vfptr;
      v14 = a2;
      while ( !v7->__vecDelDtor
           || v7[1].__vecDelDtor != (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))i_ePanelID )
      {
        v6 = (HashSetData<UIElement *> *)((char *)v6 + 1);
        v7 += 3;
        if ( v6 >= v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] )
          return;
      }
      v8 = (HashSetData<UIElement *> *)v7->__vecDelDtor;
      v9 = LOBYTE(v7[2].__vecDelDtor);
      if ( v7->__vecDelDtor )
      {
        v10 = v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
        if ( i_bVisible )
        {
          if ( v10 == v8 )
          {
            v11 = v10->m_hashKey;
          }
          else
          {
            v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = v8;
            if ( v10 && ((unsigned int)v10[20].m_hashNext >> 1) & 1 )
            {
              *(_DWORD *)&i_bVisible = 0;
              UIElement::GetAttribute_Enum((UIElement *)&v10->m_hashKey, 0x10000029u, (unsigned int *)&i_bVisible);
              CM_UI::SendNotice_SetPanelVisibility(i_bVisible, 0);
            }
            v11 = v8->m_hashKey;
            v10 = v8;
          }
          ((void (__thiscall *)(HashSetData<UIElement *> *, signed int))v11->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
            v10,
            1);
          ((void (__thiscall *)(int, signed int))v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3][3].m_hashKey)(
            &v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3],
            1);
          if ( v9 )
            v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
        }
        else if ( v10 == v8 )
        {
          ((void (__stdcall *)(_DWORD, int))v10->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
            0,
            v14);
          if ( v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] == v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
            v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
          v12 = v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2];
          if ( v12 )
          {
            v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = v12;
            ((void (__cdecl *)(signed int))v12->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
          }
          else
          {
            v13 = v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
            ((void (__thiscall *)(int))v13[3].m_hashKey)(&v4[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3]);
          }
        }
        else
        {
          ((void (__thiscall *)(HashSetData<UIElement *> *, _DWORD))v8->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
            v8,
            0);
        }
      }
    }
  }
}
// 4F5900: could not find valid save-restore pair for edi

//----- (004F5AA0) --------------------------------------------------------  // acclient.c:289254
void __userpurge gmCombatPanelUI::gmCombatPanelUI(gmCombatPanelUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmCombatPanelUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmCombatPanelUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmCombatPanelUI::vftable;
  v4->m_childrenInfoArray.m_data = 0;
  v4->m_childrenInfoArray.m_sizeAndDeallocate = 0;
  v4->m_childrenInfoArray.m_num = 0;
  v4->m_currentlyShownPanel = 0;
  v4->m_pDefaultPanel = 0;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4E68: using guessed type bool (__thiscall *gmCombatPanelUI::vftable)(DBCache *this);
// 7C5110: using guessed type int (__thiscall *gmCombatPanelUI::vftable)(void *, char);

//----- (004F5B00) --------------------------------------------------------  // acclient.c:289274
gmCombatPanelUI *__thiscall gmCombatPanelUI::DynamicCast(gmCombatPanelUI *this, unsigned int i_eType)
{
  gmCombatPanelUI *result; // eax@1

  result = this;
  if ( i_eType != 268435541 )
    result = (gmCombatPanelUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004F5B20) --------------------------------------------------------  // acclient.c:289285
signed int gmCombatPanelUI::GetUIElementType()
{
  return 268435541;
}

//----- (004F5B30) --------------------------------------------------------  // acclient.c:289291
void __thiscall gmCombatPanelUI::~gmCombatPanelUI(gmCombatPanelUI *this)
{
  UIElement_Field *v1; // esi@1
  char *v2; // ebx@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v1 = (UIElement_Field *)this;
  v2 = (char *)&this->m_childrenInfoArray;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmCombatPanelUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmCombatPanelUI::vftable;
  SmartArray<gmCombatPanelUI::PanelChildInfo,1>::Reset((SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)&this->m_childrenInfoArray);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  if ( (*((_DWORD *)v2 + 1) & 0x80000000) == 0x80000000 )
    operator delete[](*(void **)v2);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v1);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C4E68: using guessed type bool (__thiscall *gmCombatPanelUI::vftable)(DBCache *this);
// 7C5110: using guessed type int (__thiscall *gmCombatPanelUI::vftable)(void *, char);

//----- (004F5C00) --------------------------------------------------------  // acclient.c:289338
gmCombatPanelUI *__thiscall gmCombatPanelUI::scalar_deleting_destructor(gmCombatPanelUI *this, unsigned int a2)
{
  gmCombatPanelUI *v2; // esi@1

  v2 = this;
  gmCombatPanelUI::~gmCombatPanelUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004F5C20) --------------------------------------------------------  // acclient.c:289350
void __thiscall gmCombatPanelUI::SetupChildren(gmCombatPanelUI *this)
{
  gmCombatPanelUI *v1; // esi@1
  unsigned int v2; // edi@1
  int v3; // ebx@2
  gmCombatPanelUI::PanelChildInfo pci; // [sp+Ch] [bp-Ch]@1

  v1 = this;
  pci.child = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x1000005Cu);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(
    (SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)&v1->m_childrenInfoArray,
    (gmEnvPanelUI::PanelChildInfo *)&pci);
  pci.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000061u);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(
    (SmartArray<gmEnvPanelUI::PanelChildInfo,1> *)&v1->m_childrenInfoArray,
    (gmEnvPanelUI::PanelChildInfo *)&pci);
  v2 = 0;
  if ( v1->m_childrenInfoArray.m_num )
  {
    v3 = 0;
    do
    {
      v1->m_childrenInfoArray.m_data[v3].child->vfptr[2].__vecDelDtor(
        (IInputActionCallback *)v1->m_childrenInfoArray.m_data[v3].child,
        0);
      ++v2;
      ++v3;
    }
    while ( v2 < v1->m_childrenInfoArray.m_num );
  }
}

//----- (004F5CD0) --------------------------------------------------------  // acclient.c:289387
void __thiscall gmCombatPanelUI::PostInit(gmCombatPanelUI *this)
{
  gmCombatPanelUI *v1; // esi@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  gmCombatPanelUI::SetupChildren(v1);
}

//----- (006F8CC0) --------------------------------------------------------  // acclient.c:781551
void sub_6F8CC0()
{
  flt_8411B8 = 1000.0 + 1.0;
}

//----- (006F8CE0) --------------------------------------------------------  // acclient.c:781557
void sub_6F8CE0()
{
  flt_8411BC = 24.0 * 8.0;
}

//----- (006F8D00) --------------------------------------------------------  // acclient.c:781563
void sub_6F8D00()
{
  flt_8411C0 = 24.0 * 0.5;
}

//----- (006F8D20) --------------------------------------------------------  // acclient.c:781569
int sub_6F8D20()
{
  return atexit(nullsub_721);
}

//----- (006F8D30) --------------------------------------------------------  // acclient.c:781575
int sub_6F8D30()
{
  return atexit(nullsub_722);
}

//----- (006F8D40) --------------------------------------------------------  // acclient.c:781581
int sub_6F8D40()
{
  return atexit(nullsub_723);
}

//----- (006F8D50) --------------------------------------------------------  // acclient.c:781587
void _E109_50()
{
  DEFAULT_VIEW_RADIUS_87 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F8D70) --------------------------------------------------------  // acclient.c:781593
void _E111_34()
{
  MIN_QUANTUM_87 = 1.0 / 30.0;
}

//----- (006F8D90) --------------------------------------------------------  // acclient.c:781599
void _E113_21()
{
  MAX_QUANTUM_87 = 1.0 / 5.0;
}

//----- (006F8DB0) --------------------------------------------------------  // acclient.c:781605
void _E115_56()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8411D8, PFID_A8R8G8B8);
}

//----- (006F8DC0) --------------------------------------------------------  // acclient.c:781611
int _E117_51()
{
  return atexit(nullsub_719);
}

//----- (006F8DD0) --------------------------------------------------------  // acclient.c:781617
void _E121_51()
{
  dword_841210 = 1024;
}

//----- (006F8DE0) --------------------------------------------------------  // acclient.c:781623
void _E123_23()
{
  dword_841214 = 0x7FFF;
}

//----- (006F8DF0) --------------------------------------------------------  // acclient.c:781629
int _E125_7()
{
  const int result; // eax@1

  result = dword_841210;
  INITIAL_MAX_DATA_RATE_58 = dword_841210;
  return result;
}

//----- (006F8E00) --------------------------------------------------------  // acclient.c:781639
int sub_6F8E00()
{
  return atexit(nullsub_720);
}

