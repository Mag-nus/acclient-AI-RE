/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmPanelUI
   Object     : GAME\game_ui_misc\gmPanelUI.obj
   Functions  : 26
   Addresses  : 004BC670 - 006F2430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BC670) --------------------------------------------------------  // acclient.c:239247
int __thiscall gmPanelUI::ListenToElementMessage(gmPanelUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElement *v2; // edi@1
  unsigned int v3; // esi@2
  unsigned int v4; // edx@2
  gmPanelUI::PanelChildInfo *v5; // ecx@3

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

//----- (004BC6F0) --------------------------------------------------------  // acclient.c:239276
void __thiscall gmPanelUI::RecvNotice_SetPanelVisibility(gmPanelUI *this, unsigned int i_ePanelID, bool i_bVisible)
{
  gmPanelUI *v3; // esi@1
  HashSetData<UIElement *> *v4; // eax@2
  HashSetData<UIElement *> *v5; // ecx@2
  HashSet<UIElement *>Vtbl *v6; // eax@3
  UIElement *v7; // edi@8
  HashSetData<UIElement *> *v8; // ebp@10
  UIElement *v9; // ecx@20
  UIElement *v10; // ecx@21
  HashSetData<UIElement *> *v11; // edx@23
  unsigned int oldPanelID; // [sp+Ch] [bp-4h]@17

  v3 = this;
  if ( i_ePanelID )
  {
    v4 = this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0];
    v5 = 0;
    if ( (unsigned int)v4 > 0 )
    {
      v6 = v3->m_hashElementsRegisteredWith.vfptr;
      while ( !v6->__vecDelDtor
           || v6[1].__vecDelDtor != (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))i_ePanelID )
      {
        v5 = (HashSetData<UIElement *> *)((char *)v5 + 1);
        v6 += 2;
        if ( v5 >= v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[0] )
          return;
      }
      v7 = (UIElement *)v6->__vecDelDtor;
      if ( v6->__vecDelDtor )
      {
        if ( i_bVisible )
        {
          v8 = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1];
          if ( (UIElement *)v8 == v7 )
          {
            ((void (__thiscall *)(HashSetData<UIElement *> *, signed int))v8->m_hashKey->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3])(
              v8,
              1);
            ((void (__thiscall *)(int, signed int))v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5][3].m_hashKey)(
              &v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5],
              1);
          }
          else
          {
            v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = (HashSetData<UIElement *> *)v7;
            if ( v8 && ((unsigned int)v8[20].m_hashNext >> 1) & 1 )
            {
              i_bVisible = 0;
              UIElement::GetAttribute_Bool(v7, 0x10000049u, &i_bVisible);
              LOBYTE(i_ePanelID) = 0;
              UIElement::GetAttribute_Bool((UIElement *)&v8->m_hashKey, 0x10000049u, (bool *)&i_ePanelID);
              if ( !i_bVisible || (_BYTE)i_ePanelID )
                v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
              else
                v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = v8;
              oldPanelID = 0;
              UIElement::GetAttribute_Enum((UIElement *)&v8->m_hashKey, 0x10000029u, &oldPanelID);
              CM_UI::SendNotice_SetPanelVisibility(oldPanelID, 0);
            }
            v7->vfptr[2].__vecDelDtor((IInputActionCallback *)v7, 1u);
            ((void (__thiscall *)(_DWORD, _DWORD))v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5][3].m_hashKey)(
              &v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5],
              1);
          }
        }
        else
        {
          v9 = (UIElement *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1]->m_hashKey;
          if ( v9 == v7 )
          {
            ((void (__stdcall *)(_DWORD))v9->vfptr[2].__vecDelDtor)(0);
            v10 = (UIElement *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]->m_hashKey;
            if ( v10 )
            {
              *(_DWORD *)&i_bVisible = 0;
              UIElement::GetAttribute_Enum(v10, 0x10000029u, (unsigned int *)&i_bVisible);
              CM_UI::SendNotice_SetPanelVisibility(i_bVisible, 1);
              v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
            }
            else
            {
              v11 = v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5];
              v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = 0;
              ((void (__thiscall *)(int, _DWORD))v11[3].m_hashKey)(
                &v3[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5],
                0);
            }
          }
          else
          {
            v7->vfptr[2].__vecDelDtor((IInputActionCallback *)v7, 0);
          }
        }
      }
    }
  }
}

//----- (004BC880) --------------------------------------------------------  // acclient.c:239377
void __userpurge gmPanelUI::gmPanelUI(gmPanelUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPanelUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmPanelUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmPanelUI::vftable;
  v4->m_childrenInfoArray.m_data = 0;
  v4->m_childrenInfoArray.m_sizeAndDeallocate = 0;
  v4->m_childrenInfoArray.m_num = 0;
  v4->m_currentlyShownPanel = 0;
  v4->m_previouslyShownPanel = 0;
  v4->m_pPanelPagesFrame = 0;
  v4->m_bStretchMode = 0;
}
// 7B3C58: using guessed type bool (__thiscall *gmPanelUI::vftable)(DBCache *this);
// 7B3F00: using guessed type int (__thiscall *gmPanelUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BC8E0) --------------------------------------------------------  // acclient.c:239399
gmPanelUI *__thiscall gmPanelUI::DynamicCast(gmPanelUI *this, unsigned int i_eType)
{
  gmPanelUI *result; // eax@1

  result = this;
  if ( i_eType != 268435464 )
    result = (gmPanelUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004BC900) --------------------------------------------------------  // acclient.c:239410
signed int gmPanelUI::GetUIElementType()
{
  return 268435464;
}

//----- (004BC910) --------------------------------------------------------  // acclient.c:239416
void __usercall gmPanelUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmPanelUI *v3; // eax@1

  v3 = (gmPanelUI *)operator new(0x618u);
  if ( v3 )
    gmPanelUI::gmPanelUI(v3, a1, _layout, _full_desc);
}

//----- (004BC940) --------------------------------------------------------  // acclient.c:239426
void __thiscall gmPanelUI::~gmPanelUI(gmPanelUI *this)
{
  UIListener *v1; // esi@1
  char *v2; // edi@1
  NoticeHandler *v3; // ebx@1

  v1 = (UIListener *)this;
  v2 = (char *)&this->m_childrenInfoArray;
  v3 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmPanelUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmPanelUI::vftable;
  SmartArray<MaterialShaderConstant,1>::Reset((SmartArray<LOAD_WEIGHTS,1> *)&this->m_childrenInfoArray);
  UIListener::UnRegisterForGlobalMessage(v1, 1u);
  if ( (*((_DWORD *)v2 + 1) & 0x80000000) == 0x80000000 )
    operator delete[](*(void **)v2);
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field((UIElement_Field *)v1);
}
// 7B3C58: using guessed type bool (__thiscall *gmPanelUI::vftable)(DBCache *this);
// 7B3F00: using guessed type int (__thiscall *gmPanelUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004BC9A0) --------------------------------------------------------  // acclient.c:239450
void __cdecl gmPanelUI::Register()
{
  UIElement::RegisterElementClass(0x10000008u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmPanelUI::Create);
}

//----- (004BC9C0) --------------------------------------------------------  // acclient.c:239456
gmPanelUI *__thiscall gmPanelUI::vector_deleting_destructor(gmPanelUI *this, unsigned int a2)
{
  gmPanelUI *v2; // esi@1

  v2 = this;
  gmPanelUI::~gmPanelUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004BC9E0) --------------------------------------------------------  // acclient.c:239468
void __thiscall gmPanelUI::SetupChildren(gmPanelUI *this)
{
  gmPanelUI *v1; // edi@1
  int v2; // esi@1
  int v3; // eax@1
  unsigned int v4; // eax@2
  unsigned int v5; // edx@3
  int v6; // eax@3
  int v7; // eax@4
  unsigned int v8; // eax@5
  unsigned int v9; // eax@6
  int v10; // ecx@6
  int v11; // eax@7
  unsigned int v12; // eax@8
  unsigned int v13; // edx@9
  int v14; // eax@9
  int v15; // eax@10
  unsigned int v16; // eax@11
  unsigned int v17; // eax@12
  int v18; // ecx@12
  int v19; // eax@13
  unsigned int v20; // eax@14
  unsigned int v21; // edx@15
  int v22; // eax@15
  int v23; // eax@16
  unsigned int v24; // eax@17
  unsigned int v25; // eax@18
  int v26; // ecx@18
  int v27; // eax@19
  unsigned int v28; // eax@20
  unsigned int v29; // edx@21
  int v30; // eax@21
  int v31; // eax@22
  unsigned int v32; // eax@23
  unsigned int v33; // eax@24
  int v34; // ecx@24
  int v35; // eax@25
  unsigned int v36; // eax@26
  unsigned int v37; // edx@27
  int v38; // eax@27
  int v39; // eax@28
  unsigned int v40; // eax@29
  unsigned int v41; // eax@30
  int v42; // ecx@30
  int v43; // eax@31
  unsigned int v44; // eax@32
  unsigned int v45; // edx@33
  int v46; // eax@33
  int v47; // eax@34
  unsigned int v48; // eax@35
  unsigned int v49; // eax@36
  int v50; // ecx@36
  int v51; // eax@37
  unsigned int v52; // eax@38
  unsigned int v53; // edx@39
  int v54; // eax@39
  int v55; // eax@40
  unsigned int v56; // eax@41
  unsigned int v57; // eax@42
  int v58; // ecx@42
  int v59; // eax@43
  unsigned int v60; // eax@44
  unsigned int v61; // edx@45
  int v62; // eax@45
  int v63; // eax@46
  unsigned int v64; // eax@47
  unsigned int v65; // eax@48
  int v66; // ecx@48
  unsigned int v67; // ebx@49
  gmPanelUI::PanelChildInfo inventory; // [sp+10h] [bp-80h]@1
  gmPanelUI::PanelChildInfo social; // [sp+18h] [bp-78h]@4
  gmPanelUI::PanelChildInfo skill; // [sp+20h] [bp-70h]@7
  gmPanelUI::PanelChildInfo quest; // [sp+28h] [bp-68h]@10
  gmPanelUI::PanelChildInfo map; // [sp+30h] [bp-60h]@13
  gmPanelUI::PanelChildInfo book; // [sp+38h] [bp-58h]@16
  gmPanelUI::PanelChildInfo options; // [sp+40h] [bp-50h]@19
  gmPanelUI::PanelChildInfo spell; // [sp+48h] [bp-48h]@22
  gmPanelUI::PanelChildInfo positive_effects; // [sp+50h] [bp-40h]@25
  gmPanelUI::PanelChildInfo negative_effects; // [sp+58h] [bp-38h]@28
  gmPanelUI::PanelChildInfo abuse; // [sp+60h] [bp-30h]@31
  gmPanelUI::PanelChildInfo assistance; // [sp+68h] [bp-28h]@34
  gmPanelUI::PanelChildInfo character; // [sp+70h] [bp-20h]@37
  gmPanelUI::PanelChildInfo vitae; // [sp+78h] [bp-18h]@40
  gmPanelUI::PanelChildInfo net; // [sp+80h] [bp-10h]@43
  gmPanelUI::PanelChildInfo game; // [sp+88h] [bp-8h]@46

  v1 = this;
  inventory.child = UIElement::GetChildRecursive((UIElement *)&this->vfptr, 0x1000018Bu);
  UIElement::GetAttribute_Enum(inventory.child, 0x10000029u, &inventory.panelID);
  v2 = (int)&v1->m_childrenInfoArray;
  v3 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v4)) )
  {
    v5 = v1->m_childrenInfoArray.m_num;
    v6 = *(_DWORD *)v2;
    *(_DWORD *)(v6 + 8 * v5) = inventory.child;
    *(_DWORD *)(v6 + 8 * v5 + 4) = inventory.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  social.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000018Fu);
  UIElement::GetAttribute_Enum(social.child, 0x10000029u, &social.panelID);
  v7 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v7
    || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v8)) )
  {
    v9 = v1->m_childrenInfoArray.m_num;
    v10 = *(_DWORD *)v2;
    *(_DWORD *)(v10 + 8 * v9) = social.child;
    *(_DWORD *)(v10 + 8 * v9 + 4) = social.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  skill.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000018Eu);
  UIElement::GetAttribute_Enum(skill.child, 0x10000029u, &skill.panelID);
  v11 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v11
    || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v12)) )
  {
    v13 = v1->m_childrenInfoArray.m_num;
    v14 = *(_DWORD *)v2;
    *(_DWORD *)(v14 + 8 * v13) = skill.child;
    *(_DWORD *)(v14 + 8 * v13 + 4) = skill.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  quest.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000559u);
  UIElement::GetAttribute_Enum(quest.child, 0x10000029u, &quest.panelID);
  v15 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v15
    || (v16 = SmartArray<UIChildFramework *,1>::get_new_size(v15 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v16)) )
  {
    v17 = v1->m_childrenInfoArray.m_num;
    v18 = *(_DWORD *)v2;
    *(_DWORD *)(v18 + 8 * v17) = quest.child;
    *(_DWORD *)(v18 + 8 * v17 + 4) = quest.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  map.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000018Cu);
  UIElement::GetAttribute_Enum(map.child, 0x10000029u, &map.panelID);
  v19 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v19
    || (v20 = SmartArray<UIChildFramework *,1>::get_new_size(v19 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v20)) )
  {
    v21 = v1->m_childrenInfoArray.m_num;
    v22 = *(_DWORD *)v2;
    *(_DWORD *)(v22 + 8 * v21) = map.child;
    *(_DWORD *)(v22 + 8 * v21 + 4) = map.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  book.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000182u);
  UIElement::GetAttribute_Enum(book.child, 0x10000029u, &book.panelID);
  v23 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v23
    || (v24 = SmartArray<UIChildFramework *,1>::get_new_size(v23 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v24)) )
  {
    v25 = v1->m_childrenInfoArray.m_num;
    v26 = *(_DWORD *)v2;
    *(_DWORD *)(v26 + 8 * v25) = book.child;
    *(_DWORD *)(v26 + 8 * v25 + 4) = book.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  options.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000018Du);
  UIElement::GetAttribute_Enum(options.child, 0x10000029u, &options.panelID);
  v27 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v27
    || (v28 = SmartArray<UIChildFramework *,1>::get_new_size(v27 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v28)) )
  {
    v29 = v1->m_childrenInfoArray.m_num;
    v30 = *(_DWORD *)v2;
    *(_DWORD *)(v30 + 8 * v29) = options.child;
    *(_DWORD *)(v30 + 8 * v29 + 4) = options.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  spell.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000190u);
  UIElement::GetAttribute_Enum(spell.child, 0x10000029u, &spell.panelID);
  v31 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v31
    || (v32 = SmartArray<UIChildFramework *,1>::get_new_size(v31 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v32)) )
  {
    v33 = v1->m_childrenInfoArray.m_num;
    v34 = *(_DWORD *)v2;
    *(_DWORD *)(v34 + 8 * v33) = spell.child;
    *(_DWORD *)(v34 + 8 * v33 + 4) = spell.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  positive_effects.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000184u);
  UIElement::GetAttribute_Enum(positive_effects.child, 0x10000029u, &positive_effects.panelID);
  v35 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v35
    || (v36 = SmartArray<UIChildFramework *,1>::get_new_size(v35 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v36)) )
  {
    v37 = v1->m_childrenInfoArray.m_num;
    v38 = *(_DWORD *)v2;
    *(_DWORD *)(v38 + 8 * v37) = positive_effects.child;
    *(_DWORD *)(v38 + 8 * v37 + 4) = positive_effects.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  negative_effects.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000185u);
  UIElement::GetAttribute_Enum(negative_effects.child, 0x10000029u, &negative_effects.panelID);
  v39 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v39
    || (v40 = SmartArray<UIChildFramework *,1>::get_new_size(v39 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v40)) )
  {
    v41 = v1->m_childrenInfoArray.m_num;
    v42 = *(_DWORD *)v2;
    *(_DWORD *)(v42 + 8 * v41) = negative_effects.child;
    *(_DWORD *)(v42 + 8 * v41 + 4) = negative_effects.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  abuse.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000181u);
  UIElement::GetAttribute_Enum(abuse.child, 0x10000029u, &abuse.panelID);
  v43 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v43
    || (v44 = SmartArray<UIChildFramework *,1>::get_new_size(v43 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v44)) )
  {
    v45 = v1->m_childrenInfoArray.m_num;
    v46 = *(_DWORD *)v2;
    *(_DWORD *)(v46 + 8 * v45) = abuse.child;
    *(_DWORD *)(v46 + 8 * v45 + 4) = abuse.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  assistance.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000189u);
  UIElement::GetAttribute_Enum(assistance.child, 0x10000029u, &assistance.panelID);
  v47 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v47
    || (v48 = SmartArray<UIChildFramework *,1>::get_new_size(v47 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v48)) )
  {
    v49 = v1->m_childrenInfoArray.m_num;
    v50 = *(_DWORD *)v2;
    *(_DWORD *)(v50 + 8 * v49) = assistance.child;
    *(_DWORD *)(v50 + 8 * v49 + 4) = assistance.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  character.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000183u);
  UIElement::GetAttribute_Enum(character.child, 0x10000029u, &character.panelID);
  v51 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v51
    || (v52 = SmartArray<UIChildFramework *,1>::get_new_size(v51 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v52)) )
  {
    v53 = v1->m_childrenInfoArray.m_num;
    v54 = *(_DWORD *)v2;
    *(_DWORD *)(v54 + 8 * v53) = character.child;
    *(_DWORD *)(v54 + 8 * v53 + 4) = character.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  vitae.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000018Au);
  UIElement::GetAttribute_Enum(vitae.child, 0x10000029u, &vitae.panelID);
  v55 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v55
    || (v56 = SmartArray<UIChildFramework *,1>::get_new_size(v55 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v56)) )
  {
    v57 = v1->m_childrenInfoArray.m_num;
    v58 = *(_DWORD *)v2;
    *(_DWORD *)(v58 + 8 * v57) = vitae.child;
    *(_DWORD *)(v58 + 8 * v57 + 4) = vitae.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  net.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000187u);
  UIElement::GetAttribute_Enum(net.child, 0x10000029u, &net.panelID);
  v59 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v59
    || (v60 = SmartArray<UIChildFramework *,1>::get_new_size(v59 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v60)) )
  {
    v61 = v1->m_childrenInfoArray.m_num;
    v62 = *(_DWORD *)v2;
    *(_DWORD *)(v62 + 8 * v61) = net.child;
    *(_DWORD *)(v62 + 8 * v61 + 4) = net.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  game.child = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000188u);
  UIElement::GetAttribute_Enum(game.child, 0x10000029u, &game.panelID);
  v63 = v1->m_childrenInfoArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v1->m_childrenInfoArray.m_num < v63
    || (v64 = SmartArray<UIChildFramework *,1>::get_new_size(v63 + 1),
        SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)&v1->m_childrenInfoArray, v64)) )
  {
    v65 = v1->m_childrenInfoArray.m_num;
    v66 = *(_DWORD *)v2;
    *(_DWORD *)(v66 + 8 * v65) = game.child;
    *(_DWORD *)(v66 + 8 * v65 + 4) = game.panelID;
    ++v1->m_childrenInfoArray.m_num;
  }
  v67 = 0;
  if ( v1->m_childrenInfoArray.m_num )
  {
    do
      (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*(_DWORD *)v2 + 8 * v67++) + 24))(0);
    while ( v67 < v1->m_childrenInfoArray.m_num );
  }
}

//----- (004BD010) --------------------------------------------------------  // acclient.c:239774
void __thiscall gmPanelUI::PostInit(gmPanelUI *this)
{
  gmPanelUI *v1; // esi@1
  GlobalEventHandler *v2; // edi@1
  int v3; // eax@2
  int v4; // eax@5
  int v5; // eax@8
  int v6; // eax@11

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v1 )
    v3 = (int)&v1->vfptr;
  else
    v3 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD1F7 + 1), (NoticeHandler *)v3);
  if ( v1 )
    v4 = (int)&v1->vfptr;
  else
    v4 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)&loc_4DD1F0, (NoticeHandler *)v4);
  if ( v1 )
    v5 = (int)&v1->vfptr;
  else
    v5 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, (unsigned int)((char *)&loc_4DD21E + 1), (NoticeHandler *)v5);
  if ( v1 )
    v6 = (int)&v1->vfptr;
  else
    v6 = 0;
  v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 5100124u, (NoticeHandler *)v6);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 1u);
  gmPanelUI::SetupChildren(v1);
  if ( v1->m_currentlyShownPanel )
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 1u);
  else
    v1->vfptr[2].__vecDelDtor((IInputActionCallback *)v1, 0);
}

//----- (006F22F0) --------------------------------------------------------  // acclient.c:774589
void _E91_82()
{
  outside_val_74 = 1000.0 + 1.0;
}

//----- (006F2310) --------------------------------------------------------  // acclient.c:774595
void _E93_58()
{
  block_length_74 = 24.0 * 8.0;
}

//----- (006F2330) --------------------------------------------------------  // acclient.c:774601
void _E95_58()
{
  half_square_length_74 = 24.0 * 0.5;
}

//----- (006F2350) --------------------------------------------------------  // acclient.c:774607
int _E97_83()
{
  return atexit(_E98_95);
}

//----- (006F2360) --------------------------------------------------------  // acclient.c:774613
int _E100_76()
{
  return atexit(nullsub_781);
}

//----- (006F2370) --------------------------------------------------------  // acclient.c:774619
int _E103_68()
{
  return atexit(_E104_83);
}

//----- (006F2380) --------------------------------------------------------  // acclient.c:774625
void _E107_6()
{
  LOWEST_DATA_RATE_82 = 1024;
}

//----- (006F2390) --------------------------------------------------------  // acclient.c:774631
void _E109_32()
{
  HIGHEST_DATA_RATE_82 = 0x7FFF;
}

//----- (006F23A0) --------------------------------------------------------  // acclient.c:774637
int _E111_21()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_82;
  INITIAL_MAX_DATA_RATE_30 = LOWEST_DATA_RATE_82;
  return result;
}

//----- (006F23B0) --------------------------------------------------------  // acclient.c:774647
int _E113_9()
{
  return atexit(_E114_76);
}

//----- (006F23C0) --------------------------------------------------------  // acclient.c:774653
void _E116_10()
{
  DEFAULT_VIEW_RADIUS_45 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F23E0) --------------------------------------------------------  // acclient.c:774659
void _E118_40()
{
  MIN_QUANTUM_45 = 1.0 / 30.0;
}

//----- (006F2400) --------------------------------------------------------  // acclient.c:774665
void _E120_28()
{
  MAX_QUANTUM_45 = 1.0 / 5.0;
}

//----- (006F2420) --------------------------------------------------------  // acclient.c:774671
void _E122_14()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_80, PFID_A8R8G8B8);
}

//----- (006F2430) --------------------------------------------------------  // acclient.c:774677
int sub_6F2430()
{
  return atexit(nullsub_779);
}

