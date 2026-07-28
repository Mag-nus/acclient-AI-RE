/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmEnvPanelUI
   Object     : GAME\game_ui_misc\gmEnvPanelUI.obj
   Functions  : 30
   Addresses  : 0044DF70 - 006F3300 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044DF70) --------------------------------------------------------  // acclient.c:139175
char __thiscall SmartArray<gmCombatPanelUI::PanelChildInfo,1>::grow(SmartArray<gmEnvPanelUI::PanelChildInfo,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebx@1
  SmartArray<gmEnvPanelUI::PanelChildInfo,1> *v3; // esi@1
  void *v5; // edi@5
  int v6; // ecx@7
  int v7; // eax@8
  int v8; // edx@9
  int v9; // ecx@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@8

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<gmCombatPanelUI::PanelChildInfo,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](12 * i_nSize);
    if ( v5 )
    {
      if ( v3->m_data )
      {
        v6 = v3->m_num - 1;
        if ( v6 >= 0 )
        {
          v7 = v6;
          i_nSizea = v3->m_num;
          do
          {
            v8 = (int)&v3->m_data[v7];
            v9 = (int)((char *)v5 + v7 * 12);
            *(_DWORD *)v9 = *(_DWORD *)v8;
            *(_DWORD *)(v9 + 4) = *(_DWORD *)(v8 + 4);
            *(_DWORD *)(v9 + 8) = *(_DWORD *)(v8 + 8);
            --v7;
            --i_nSizea;
          }
          while ( i_nSizea );
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v3->m_data);
      }
      v3->m_data = (gmEnvPanelUI::PanelChildInfo *)v5;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (004CC760) --------------------------------------------------------  // acclient.c:253801
void __userpurge gmEnvPanelUI::RecvNotice_SetPanelVisibility(gmEnvPanelUI *this@<ecx>, int a2@<edi>, unsigned int i_ePanelID, bool i_bVisible, unsigned int oldPanelID)
{
  gmEnvPanelUI *v5; // esi@1
  HashSetData<UIElement *> *v6; // eax@2
  HashSetData<UIElement *> *v7; // ecx@2
  HashSet<UIElement *>Vtbl *v8; // eax@3
  UIRegion *v9; // edi@8
  char v10; // bl@8
  HashSetData<UIElement *> *v11; // ecx@9
  int v12; // ST08_4@14
  int v13; // eax@14
  HashSetData<UIElement *> *v14; // eax@14
  int v15; // ecx@14
  HashSetData<UIElement *> *v16; // ecx@21
  HashSetData<UIElement *> *v17; // ebx@22
  int v18; // ST04_4@22
  int v19; // eax@22
  HashSetData<UIElement *> *v20; // eax@23
  int v21; // [sp-8h] [bp-10h]@3

  v5 = this;
  if ( i_ePanelID )
  {
    v6 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
    v7 = 0;
    if ( (unsigned int)v6 > 0 )
    {
      v8 = v5->m_hashElementsRegisteredWith.vfptr;
      v21 = a2;
      while ( !v8->__vecDelDtor
           || v8[1].__vecDelDtor != (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))i_ePanelID )
      {
        v7 = (HashSetData<UIElement *> *)((char *)v7 + 1);
        v8 += 3;
        if ( v7 >= v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] )
          return;
      }
      v9 = (UIRegion *)v8->__vecDelDtor;
      v10 = LOBYTE(v8[2].__vecDelDtor);
      if ( v8->__vecDelDtor )
      {
        v11 = v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
        if ( i_bVisible )
        {
          if ( (UIRegion *)v11 == v9 )
          {
            ((void (__stdcall *)(signed int, int))v11->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
              1,
              v21);
            v14 = v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v15 = (int)&v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
          }
          else
          {
            v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = (HashSetData<UIElement *> *)v9;
            if ( v11 && ((unsigned int)v11[20].m_hashNext >> 1) & 1 )
            {
              *(_DWORD *)&i_bVisible = 0;
              UIElement::GetAttribute_Enum((UIElement *)&v11->m_hashKey, 0x10000029u, (unsigned int *)&i_bVisible);
              CM_UI::SendNotice_SetPanelVisibility(i_bVisible, 0);
            }
            ((void (__thiscall *)(UIRegion *, signed int, int))v9->vfptr[2].__vecDelDtor)(v9, 1, v21);
            oldPanelID = (unsigned int)v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v12 = UIRegion::GetHeight(v9);
            v13 = UIRegion::GetWidth((UIRegion *)&v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3]);
            (*(void (__thiscall **)(int, int, int))(oldPanelID + 48))(
              &v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3],
              v13,
              v12);
            v14 = v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v15 = (int)&v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
          }
          ((void (__thiscall *)(int))v14[3].m_hashKey)(v15);
          if ( v10 )
            v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
        }
        else if ( (UIRegion *)v11 == v9 )
        {
          ((void (__stdcall *)(_DWORD, int))v11->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
            0,
            v21);
          if ( v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] == v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
            v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
          v16 = v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2];
          if ( v16 )
          {
            v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = v16;
            ((void (__cdecl *)(signed int))v16->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(1);
            v17 = v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v18 = UIRegion::GetHeight((UIRegion *)v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]);
            v19 = UIRegion::GetWidth((UIRegion *)&v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3]);
            ((void (__thiscall *)(int, int, int))v17[6].m_hashKey)(
              &v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3],
              v19,
              v18);
          }
          else
          {
            v20 = v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3];
            v5->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
            ((void (__thiscall *)(int))v20[3].m_hashKey)(&v5[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3]);
          }
        }
        else
        {
          v9->vfptr[2].__vecDelDtor((IInputActionCallback *)v9, 0);
        }
      }
    }
  }
}
// 4CC760: could not find valid save-restore pair for edi

//----- (004CC8D0) --------------------------------------------------------  // acclient.c:253915
void __userpurge gmEnvPanelUI::gmEnvPanelUI(gmEnvPanelUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmEnvPanelUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmEnvPanelUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmEnvPanelUI::vftable;
  v4->m_childrenInfoArray.m_data = 0;
  v4->m_childrenInfoArray.m_sizeAndDeallocate = 0;
  v4->m_childrenInfoArray.m_num = 0;
  v4->m_currentlyShownPanel = 0;
  v4->m_pDefaultPanel = 0;
}
// 7B8990: using guessed type bool (__thiscall *gmEnvPanelUI::vftable)(DBCache *this);
// 7B8C38: using guessed type int (__thiscall *gmEnvPanelUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CC930) --------------------------------------------------------  // acclient.c:253935
gmEnvPanelUI *__thiscall gmEnvPanelUI::DynamicCast(gmEnvPanelUI *this, unsigned int i_eType)
{
  gmEnvPanelUI *result; // eax@1

  result = this;
  if ( i_eType != 268435507 )
    result = (gmEnvPanelUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CC950) --------------------------------------------------------  // acclient.c:253946
signed int gmEnvPanelUI::GetUIElementType()
{
  return 268435507;
}

//----- (004CC960) --------------------------------------------------------  // acclient.c:253952
void __usercall gmEnvPanelUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmEnvPanelUI *v3; // eax@1

  v3 = (gmEnvPanelUI *)operator new(0x610u);
  if ( v3 )
    gmEnvPanelUI::gmEnvPanelUI(v3, a1, _layout, _full_desc);
}

//----- (004CC990) --------------------------------------------------------  // acclient.c:253962
void __thiscall gmEnvPanelUI::~gmEnvPanelUI(gmEnvPanelUI *this)
{
  UIElement_Field *v1; // esi@1
  char *v2; // ebx@1
  NoticeHandler *v3; // edi@1
  GlobalEventHandler *v4; // eax@1

  v1 = (UIElement_Field *)this;
  v2 = (char *)&this->m_childrenInfoArray;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmEnvPanelUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmEnvPanelUI::vftable;
  SmartArray<gmCombatPanelUI::PanelChildInfo,1>::Reset(&this->m_childrenInfoArray);
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v4 )
    v4->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v4, v3);
  if ( (*((_DWORD *)v2 + 1) & 0x80000000) == 0x80000000 )
    operator delete[](*(void **)v2);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v1);
}
// 7B8990: using guessed type bool (__thiscall *gmEnvPanelUI::vftable)(DBCache *this);
// 7B8C38: using guessed type int (__thiscall *gmEnvPanelUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CCA00) --------------------------------------------------------  // acclient.c:253989
void __cdecl gmEnvPanelUI::Register()
{
  UIElement::RegisterElementClass(
    0x10000033u,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmEnvPanelUI::Create);
}

//----- (004CCA20) --------------------------------------------------------  // acclient.c:253997
gmEnvPanelUI *__thiscall gmEnvPanelUI::scalar_deleting_destructor(gmEnvPanelUI *this, unsigned int a2)
{
  gmEnvPanelUI *v2; // esi@1

  v2 = this;
  gmEnvPanelUI::~gmEnvPanelUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004CCA40) --------------------------------------------------------  // acclient.c:254009
void __thiscall gmEnvPanelUI::SetupChildren(gmEnvPanelUI *this)
{
  gmEnvPanelUI *v1; // esi@1
  unsigned int v2; // ebp@1
  int v3; // ebx@2
  gmEnvPanelUI::PanelChildInfo pci; // [sp+Ch] [bp-Ch]@1

  v1 = this;
  pci.child = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x1000005Du);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(&v1->m_childrenInfoArray, &pci);
  pci.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000005Eu);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(&v1->m_childrenInfoArray, &pci);
  pci.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000005Fu);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(&v1->m_childrenInfoArray, &pci);
  pci.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000060u);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(&v1->m_childrenInfoArray, &pci);
  pci.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000062u);
  UIElement::GetAttribute_Enum(pci.child, 0x10000029u, &pci.panelID);
  pci.bShouldBeDefault = 0;
  SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(&v1->m_childrenInfoArray, &pci);
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

//----- (004CCB80) --------------------------------------------------------  // acclient.c:254054
void __thiscall gmEnvPanelUI::PostInit(gmEnvPanelUI *this)
{
  gmEnvPanelUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@3
  int v4; // eax@6

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
  {
    if ( v1 )
      v3 = (int)&v1->vfptr;
    else
      v3 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1F7 + 1),
      (NoticeHandler *)v3);
    if ( v1 )
      v4 = (int)&v1->vfptr;
    else
      v4 = 0;
    v2->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v2,
      (unsigned int)((char *)&loc_4DD1F9 + 2),
      (NoticeHandler *)v4);
  }
  gmEnvPanelUI::SetupChildren(v1);
}

//----- (004F5870) --------------------------------------------------------  // acclient.c:289075
void __thiscall gmEnvPanelUI::RecvNotice_SetCombatMode(gmEnvPanelUI *this, COMBAT_MODE i_eCombatMode)
{
  if ( i_eCombatMode == 1 )
    this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
}

//----- (004F5890) --------------------------------------------------------  // acclient.c:289082
int __thiscall gmCombatPanelUI::ListenToElementMessage(gmEnvPanelUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // edi@1
  unsigned int v3; // esi@2
  unsigned int v4; // edx@2
  gmEnvPanelUI::PanelChildInfo *v5; // ecx@3

  v2 = (UIElement *)this;
  if ( i_rMsg->idMessage == 24 )
  {
    v3 = this->m_childrenInfoArray.m_num;
    v4 = 0;
    if ( v3 )
    {
      v5 = this->m_childrenInfoArray.m_data;
      while ( !v5->child || v5->child != i_rMsg->pElement )
      {
        ++v4;
        ++v5;
        if ( v4 >= v3 )
          return UIElement::ListenToElementMessage(v2, i_rMsg);
      }
      CM_UI::SendNotice_SetPanelVisibility(v5->panelID, (*((_DWORD *)&v5->child->0 + 41) >> 1) & 0xFFFFFF01);
    }
  }
  return UIElement::ListenToElementMessage(v2, i_rMsg);
}

//----- (004F5A20) --------------------------------------------------------  // acclient.c:289207
void __thiscall SmartArray<gmCombatPanelUI::PanelChildInfo,1>::Reset(SmartArray<gmEnvPanelUI::PanelChildInfo,1> *this)
{
  SmartArray<gmEnvPanelUI::PanelChildInfo,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@5
  int v7; // ecx@5
  int v8; // ebp@6
  int v9; // [sp+8h] [bp-Ch]@0
  int v10; // [sp+Ch] [bp-8h]@0
  int v11; // [sp+10h] [bp-4h]@0

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    v5 = v4;
    if ( v4 >= 0 )
    {
      v6 = v4;
      v7 = v5 + 1;
      do
      {
        v8 = (int)&v1->m_data[v6];
        *(_DWORD *)v8 = v9;
        *(_DWORD *)(v8 + 4) = v10;
        --v6;
        --v7;
        *(_DWORD *)(v8 + 8) = v11;
      }
      while ( v7 );
    }
  }
}

//----- (004F5BA0) --------------------------------------------------------  // acclient.c:289318
char __thiscall SmartArray<gmEnvPanelUI::PanelChildInfo,1>::AddToEnd(SmartArray<gmEnvPanelUI::PanelChildInfo,1> *this, gmEnvPanelUI::PanelChildInfo *i_rData)
{
  SmartArray<gmEnvPanelUI::PanelChildInfo,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<gmCombatPanelUI::PanelChildInfo,1>::grow(v2, v4)) != 0) )
  {
    v2->m_data[v2->m_num++] = *i_rData;
    result = 1;
  }
  return result;
}

//----- (006F31C0) --------------------------------------------------------  // acclient.c:775641
void _E91_93()
{
  outside_val_85 = 1000.0 + 1.0;
}

//----- (006F31E0) --------------------------------------------------------  // acclient.c:775647
void _E93_69()
{
  block_length_85 = 24.0 * 8.0;
}

//----- (006F3200) --------------------------------------------------------  // acclient.c:775653
void _E95_69()
{
  half_square_length_85 = 24.0 * 0.5;
}

//----- (006F3220) --------------------------------------------------------  // acclient.c:775659
int _E97_94()
{
  return atexit(nullsub_726);
}

//----- (006F3230) --------------------------------------------------------  // acclient.c:775665
int _E100_87()
{
  return atexit(nullsub_727);
}

//----- (006F3240) --------------------------------------------------------  // acclient.c:775671
int _E103_79()
{
  return atexit(_E104_94);
}

//----- (006F3250) --------------------------------------------------------  // acclient.c:775677
void _E109_40()
{
  DEFAULT_VIEW_RADIUS_54 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F3270) --------------------------------------------------------  // acclient.c:775683
void _E111_29()
{
  MIN_QUANTUM_54 = 1.0 / 30.0;
}

//----- (006F3290) --------------------------------------------------------  // acclient.c:775689
void _E113_17()
{
  MAX_QUANTUM_54 = 1.0 / 5.0;
}

//----- (006F32B0) --------------------------------------------------------  // acclient.c:775695
void _E115_44()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_89, PFID_A8R8G8B8);
}

//----- (006F32C0) --------------------------------------------------------  // acclient.c:775701
int _E117_32()
{
  return atexit(nullsub_724);
}

//----- (006F32D0) --------------------------------------------------------  // acclient.c:775707
void _E121_43()
{
  LOWEST_DATA_RATE_91 = 1024;
}

//----- (006F32E0) --------------------------------------------------------  // acclient.c:775713
void _E123_17()
{
  HIGHEST_DATA_RATE_91 = 0x7FFF;
}

//----- (006F32F0) --------------------------------------------------------  // acclient.c:775719
int _E125_4()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_91;
  INITIAL_MAX_DATA_RATE_39 = LOWEST_DATA_RATE_91;
  return result;
}

//----- (006F3300) --------------------------------------------------------  // acclient.c:775729
int sub_6F3300()
{
  return atexit(nullsub_725);
}

