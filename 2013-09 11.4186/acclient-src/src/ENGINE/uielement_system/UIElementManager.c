/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElementManager
   Object     : ENGINE\uielement_system\UIElementManager.obj
   Functions  : 244
   Addresses  : 00459190 - 0075D850 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00459190) --------------------------------------------------------  // acclient.c:149498
UIObject *__thiscall UIRegion::GetObjectA(UIRegion *this)
{
  UIObject *result; // eax@1

  while ( 1 )
  {
    result = this->m_object;
    if ( result )
      break;
    this = this->m_parent;
    if ( !this )
      return 0;
  }
  return result;
}

//----- (004591B0) --------------------------------------------------------  // acclient.c:149515
void __thiscall UIElement::SetActivatable(UIElement *this, bool _b)
{
  this->m_nFlags ^= ((unsigned __int8)this->m_nFlags ^ (unsigned __int8)(4 * _b)) & 4;
}

//----- (004591D0) --------------------------------------------------------  // acclient.c:149521
void __thiscall UIElement::SetObjectIsTemporary(UIElement *this, bool _b)
{
  this->m_nFlags ^= (unsigned __int16)((this->m_nFlags ^ (_b << 15)) & 0x8000);
}

//----- (004591F0) --------------------------------------------------------  // acclient.c:149527
void __cdecl UIElementManager::DestroyUIElementManager()
{
  if ( UIElementManager::s_pInstance )
    ((void (__stdcall *)(_DWORD))UIElementManager::s_pInstance->vfptr->__vecDelDtor)(1);
  UIElementManager::s_pInstance = 0;
}

//----- (00459220) --------------------------------------------------------  // acclient.c:149535
void __cdecl LayoutDesc::Allocator()
{
  LayoutDesc *v0; // eax@1

  v0 = (LayoutDesc *)operator new(0xC0u);
  if ( v0 )
    LayoutDesc::LayoutDesc(v0);
}

//----- (00459240) --------------------------------------------------------  // acclient.c:149545
signed int LayoutDesc::GetDBOType()
{
  return 35;
}

//----- (00459250) --------------------------------------------------------  // acclient.c:149551
void __thiscall UIElementManager::StartHover(UIElementManager *this, int i_xWindow, int i_yWindow)
{
  if ( !this->m_bHoverStarted )
    this->m_bHoverStarted = ((int (__stdcall *)(_DWORD, _DWORD))this->m_pElementLastEntered->vfptr[7].OnAction)(
                              i_xWindow,
                              i_yWindow);
}

//----- (00459280) --------------------------------------------------------  // acclient.c:149560
void __thiscall UIElementManager::StopHover(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  UIElement *v2; // ecx@2
  UIElement *v3; // ecx@4

  v1 = this;
  if ( this->m_bHoverStarted )
  {
    v2 = this->m_pElementLastEntered;
    v1->m_bHoverStarted = 0;
    if ( v2 )
      ((void (*)(void))v2->vfptr[7].OnLoseFocus)();
  }
  v3 = v1->m_pTooltipElement;
  if ( v3 )
  {
    UIElement::AddToDeleteQueue(v3);
    v1->m_pTooltipElement = 0;
  }
}

//----- (004592C0) --------------------------------------------------------  // acclient.c:149583
void __thiscall UIElementManager::SetDurationForCurrentTooltip(UIElementManager *this, float i_secCustomDuration)
{
  this->m_tooltipStart = Timer::local_time - this->m_tooltipDuration + i_secCustomDuration;
}

//----- (004592E0) --------------------------------------------------------  // acclient.c:149589
char __thiscall UIElementManager::ClearDragandDrop(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  UIElement *v2; // ecx@1

  v1 = this;
  v2 = this->m_dragElement;
  if ( v2 && (v2->m_nFlags >> 15) & 1 )
  {
    UIElement::AddToDeleteQueue(v2);
    v1->m_dragElement = 0;
  }
  v1->m_bDragStarted = 0;
  v1->m_dragOwner = 0;
  v1->m_pcPotentialDragElement = 0;
  return 1;
}

//----- (00459320) --------------------------------------------------------  // acclient.c:149608
void __thiscall UIElementManager::SetVisible(UIElementManager *this, int _visible)
{
  UIElementManager *v2; // esi@1
  ContextMenu *v3; // ecx@1
  UIElement *v4; // ecx@4

  v2 = this;
  v3 = this->m_pCSM;
  if ( v3 )
    ContextMenu::SetVisible(v3, _visible);
  if ( !(_BYTE)_visible )
  {
    v4 = v2->m_pTooltipElement;
    v2->m_pTooltipOwner = 0;
    if ( v4 )
    {
      UIElement::AddToDeleteQueue(v4);
      v2->m_pTooltipElement = 0;
    }
  }
}

//----- (00459370) --------------------------------------------------------  // acclient.c:149631
char __cdecl MouseHitTester<MouseOverCriteria>::Recurse(UIElement *i_pElement, int i_xParent, int i_yParent, UIElement **o_pRet)
{
  UIElement *v4; // esi@2

  if ( (*((_DWORD *)&i_pElement->0 + 41) >> 1) & 1 )
  {
    v4 = UIElement::GetLastChildElement(i_pElement);
    if ( v4 )
    {
      while ( !UIRegion::PointIsOverRegion((UIRegion *)&v4->vfptr, i_xParent, i_yParent)
           || !MouseHitTester<MouseOverCriteria>::Recurse(
                 v4,
                 i_xParent - v4->m_box.m_x0,
                 i_yParent - v4->m_box.m_y0,
                 o_pRet) )
      {
        v4 = UIElement::GetPrevChildElement(i_pElement, v4);
        if ( !v4 )
          goto LABEL_6;
      }
      return 1;
    }
LABEL_6:
    if ( i_pElement->m_bIsMouseVisible || (*((_DWORD *)&i_pElement->0 + 41) >> 6) & 1 )
    {
      *o_pRet = i_pElement;
      return 1;
    }
  }
  return 0;
}

//----- (00459410) --------------------------------------------------------  // acclient.c:149664
char __thiscall SmartArray<UIElement *,1>::RemoveOrdered(SmartArray<UIElement *,1> *this, UIElement *const *i_rData)
{
  SmartArray<UIElement *,1> *v2; // eax@1
  UIElement **v3; // edi@1
  UIElement **v4; // ecx@1
  char result; // al@4
  int v6; // ecx@5
  int v7; // ecx@7

  v2 = this;
  v3 = this->m_data;
  v4 = &this->m_data[this->m_num];
  if ( v3 >= v4 )
  {
LABEL_4:
    result = 0;
  }
  else
  {
    while ( *v3 != *i_rData )
    {
      ++v3;
      if ( v3 >= v4 )
        goto LABEL_4;
    }
    v6 = (int)(v4 - 1);
    if ( (unsigned int)v3 < v6 )
      qmemcpy(v3, v3 + 1, 4 * (((unsigned int)(v6 - (_DWORD)v3 - 1) >> 2) + 1));
    v7 = v2->m_num - 1;
    v2->m_num = v7;
    v2->m_data[v7] = 0;
    result = 1;
  }
  return result;
}

//----- (00459470) --------------------------------------------------------  // acclient.c:149701
char __thiscall SmartArray<UIElement *,1>::RemoveOrderedByIndex(SmartArray<UIElement *,1> *this, unsigned int index)
{
  SmartArray<UIElement *,1> *v2; // edx@1
  unsigned int v3; // eax@1
  UIElement **v4; // ecx@2
  int v5; // eax@2
  unsigned int v6; // edi@2
  int v7; // ecx@2
  char result; // al@4

  v2 = this;
  v3 = this->m_num;
  if ( index >= v3 )
  {
    result = 0;
  }
  else
  {
    v4 = this->m_data;
    v5 = v3 - 1;
    v6 = (unsigned int)&v4[index];
    v7 = (int)&v4[v5];
    v2->m_num = v5;
    if ( v6 < v7 )
      qmemcpy((void *)v6, (const void *)(v6 + 4), 4 * (((v7 - v6 - 1) >> 2) + 1));
    v2->m_data[v2->m_num] = 0;
    result = 1;
  }
  return result;
}

//----- (004594C0) --------------------------------------------------------  // acclient.c:149733
void __thiscall SmartArray<Box2D,1>::Reset(SmartArray<Box2D,1> *this)
{
  SmartArray<Box2D,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@4
  int v5; // ecx@5
  int v6; // edx@5
  int v7; // eax@6
  char v8; // [sp+8h] [bp-10h]@6

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
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        v7 = (int)&v1->m_data[v5].m_x0;
        if ( (char *)v7 != &v8 )
        {
          *(_DWORD *)v7 = 0;
          *(_DWORD *)(v7 + 8) = 0;
          *(_DWORD *)(v7 + 4) = 0;
          *(_DWORD *)(v7 + 12) = 0;
        }
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (004595B0) --------------------------------------------------------  // acclient.c:149812
void __thiscall UIElementMessageInfo::UIElementMessageInfo(UIElementMessageInfo *this, unsigned int i_idElement, UIElement *i_pElement, unsigned int i_idMessage, unsigned int i_dwParam1, unsigned int i_dwParam2, int i_xWindow, int i_yWindow, int i_xElement, int i_yElement)
{
  this->idElement = i_idElement;
  this->pElement = i_pElement;
  this->idMessage = i_idMessage;
  this->dwParam1 = i_dwParam1;
  this->dwParam2 = i_dwParam2;
  this->tsSerialNumber.m_timestamp = 0;
  this->ptWindow.x = i_xWindow;
  this->ptWindow.y = i_yWindow;
  this->ptElement.x = i_xElement;
  this->ptElement.y = i_yElement;
}

//----- (00459600) --------------------------------------------------------  // acclient.c:149827
NonDBObjLayoutDesc *__thiscall LayoutDesc::vector_deleting_destructor(NonDBObjLayoutDesc *this, unsigned int a2)
{
  NonDBObjLayoutDesc *v2; // esi@1

  v2 = this;
  LayoutDesc::~LayoutDesc((LayoutDesc *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00459620) --------------------------------------------------------  // acclient.c:149839
NonDBObjElementDesc *__thiscall NonDBObjElementDesc::scalar_deleting_destructor(NonDBObjElementDesc *this, unsigned int a2)
{
  NonDBObjElementDesc *v2; // esi@1

  v2 = this;
  ElementDesc::~ElementDesc((ElementDesc *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00459640) --------------------------------------------------------  // acclient.c:149851
void __thiscall UIElementManager::ProcessUIMessageRemovalData(UIElementManager *this)
{
  int v1; // eax@1
  UIMessageRemovalData *v2; // edx@2
  UIListener *v3; // ebp@2
  SmartArray<UIMessageData,1> *v4; // eax@2
  unsigned int v5; // ebx@2
  unsigned int v6; // edx@2
  UIMessageData *v7; // edi@3
  UIMessageData *v8; // esi@3
  int v9; // esi@9
  unsigned int v10; // edx@10
  UIMessageData *v11; // eax@10
  unsigned int aIndex; // [sp+0h] [bp-8h]@1
  int v13; // [sp+4h] [bp-4h]@0

  v1 = 0;
  aIndex = 0;
  if ( this->m_aUIMessageRemovalData.m_num )
  {
    do
    {
      v2 = this->m_aUIMessageRemovalData.m_data;
      v3 = v2[v1].pListener;
      v4 = v2[v1].pListenerArray;
      v5 = v4->m_num;
      v6 = 0;
      if ( v5 )
      {
        v7 = v4->m_data;
        v8 = v4->m_data;
        while ( v8->pListener != v3 )
        {
          ++v6;
          ++v8;
          if ( v6 >= v4->m_num )
            goto LABEL_11;
        }
        if ( !v8->nCount && v6 < v5 )
        {
          v9 = v5 - 1;
          v4->m_num = v5 - 1;
          if ( v6 != v5 - 1 )
          {
            v7[v6].pListener = v7[v9].pListener;
            v7[v6].nCount = v7[v9].nCount;
            v10 = v4->m_num;
            v11 = v4->m_data;
            v11[v10].pListener = (UIListener *)aIndex;
            v11[v10].nCount = v13;
          }
        }
      }
LABEL_11:
      v1 = aIndex++ + 1;
    }
    while ( aIndex < this->m_aUIMessageRemovalData.m_num );
    this->m_aUIMessageRemovalData.m_num = 0;
  }
  else
  {
    this->m_aUIMessageRemovalData.m_num = 0;
  }
}

//----- (00459700) --------------------------------------------------------  // acclient.c:149917
void __thiscall UIElementManager::StartTooltip(UIElementManager *this, UIElement *i_pElementOwner, UIElement *i_pElementTooltip)
{
  UIElement *v3; // esi@1
  UIElementManager *v4; // ebx@1
  int v5; // ebp@1
  int v6; // eax@1
  ICIDMVtbl *v7; // edx@1
  int v8; // edi@1
  int v9; // eax@1
  UIElement **v10; // ecx@1
  bool v11; // sf@3
  int *v12; // eax@3
  int v13; // edi@5
  unsigned int v14; // eax@5
  unsigned __int8 v15; // of@5
  UIElement **v16; // eax@5
  UIElement *v17; // ebp@7
  unsigned int v18; // eax@7
  UIElement *v19; // eax@7
  void *v20; // eax@7
  int v21; // edi@9
  int v22; // ecx@9
  int newY; // [sp+10h] [bp-Ch]@1
  unsigned int v24; // [sp+14h] [bp-8h]@1
  int height; // [sp+18h] [bp-4h]@1

  v3 = i_pElementTooltip;
  v4 = this;
  v5 = UIRegion::GetWidth((UIRegion *)&i_pElementTooltip->vfptr);
  height = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
  v6 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
  v7 = ICIDM::s_cidm->vfptr;
  v8 = v6 + 32;
  i_pElementTooltip = (UIElement *)(v6 + 32);
  v9 = ((int (*)(void))v7->GetMouseY)() + 32;
  newY = v9;
  v24 = 0;
  v10 = (UIElement **)&v24;
  if ( v8 >= 0 )
    v10 = &i_pElementTooltip;
  v11 = v9 < 0;
  i_pElementTooltip = *v10;
  v24 = 0;
  v12 = (int *)&v24;
  if ( !v11 )
    v12 = &newY;
  v13 = *v12;
  newY = *v12;
  v14 = RenderDevice::GetDisplayWidth(RenderDevice::render_device) - v5;
  v24 = v14;
  v15 = __OFSUB__(v14, i_pElementTooltip);
  v11 = ((v14 - (_DWORD)i_pElementTooltip) & 0x80000000) != 0;
  v16 = (UIElement **)&v24;
  if ( !(v11 ^ v15) )
    v16 = &i_pElementTooltip;
  v17 = *v16;
  v18 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
  v19 = (UIElement *)(v18 - height);
  i_pElementTooltip = v19;
  v15 = __OFSUB__(v19, v13);
  v11 = (signed int)((char *)v19 - v13) < 0;
  v20 = &i_pElementTooltip;
  if ( !(v11 ^ v15) )
    v20 = &newY;
  v21 = *(_DWORD *)v20;
  v3->m_nFlags |= 0x8000u;
  UIElement::SetShouldOwnObject(v3, 1);
  UIElement::SetIsRootElement(v3, 1);
  ((void (__thiscall *)(UIElement *, UIElement *, int))v3->vfptr[3].OnLoseFocus)(v3, v17, v21);
  v4->m_pTooltipElement = v3;
  v22 = HIDWORD(Timer::local_time);
  LODWORD(v4->m_tooltipStart) = LODWORD(Timer::local_time);
  HIDWORD(v4->m_tooltipStart) = v22;
}

//----- (00459810) --------------------------------------------------------  // acclient.c:149993
void __thiscall UIElementManager::StopDragandDrop(UIElementManager *this)
{
  UIElementManager *v1; // edi@1
  void *v2; // eax@2
  void *v3; // esi@3
  UIElement *v4; // ecx@5
  UIElement *v5; // ecx@8
  UIElement *v6; // ecx@12

  v1 = this;
  if ( this->m_dragElement )
  {
    v2 = operator new(0x18u);
    if ( v2 )
    {
      *((_DWORD *)v2 + 1) = 1;
      *(_DWORD *)v2 = &DragDropInfo::vftable;
      *((_DWORD *)v2 + 2) = 0;
      *((_DWORD *)v2 + 3) = 0;
      *((_DWORD *)v2 + 4) = 0;
      *((_BYTE *)v2 + 20) = 0;
      v3 = v2;
    }
    else
    {
      v3 = 0;
    }
    *((_DWORD *)v3 + 2) = v1->m_dragElement;
    *((_DWORD *)v3 + 4) = v1->m_pElementLastDragCursorOver;
    *((_DWORD *)v3 + 3) = v1->m_dragOwner;
    *((_BYTE *)v3 + 20) = 1;
    v4 = v1->m_pElementLastDragCursorOver;
    if ( v4 )
      *((_BYTE *)v3 + 20) = ((int (__stdcall *)(void *))v4->vfptr[18].__vecDelDtor)(v3);
    else
      *((_BYTE *)v3 + 20) = 0;
    v5 = v1->m_dragOwner;
    if ( v5 )
      ((void (__stdcall *)(void *))v5->vfptr[18].OnLoseFocus)(v3);
    if ( !InterlockedDecrement((volatile LONG *)v3 + 1) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
  v6 = v1->m_dragElement;
  if ( v6 && (v6->m_nFlags >> 15) & 1 )
  {
    UIElement::AddToDeleteQueue(v6);
    v1->m_dragElement = 0;
  }
  v1->m_bDragStarted = 0;
  v1->m_dragOwner = 0;
  v1->m_pcPotentialDragElement = 0;
}
// 7C9870: using guessed type int (__thiscall *DragDropInfo::vftable)(void *, char);

//----- (004598F0) --------------------------------------------------------  // acclient.c:150048
void __thiscall UIElementManager::UnregisterActivatable(UIElementManager *this, UIElement *_element)
{
  if ( _element )
    SmartArray<UIElement *,1>::RemoveOrdered(&this->m_activatableElements, &_element);
}

//----- (00459910) --------------------------------------------------------  // acclient.c:150055
void __thiscall UIElementManager::ActivateNext(UIElementManager *this, bool _backwards)
{
  UIElementManager *v2; // edi@1
  unsigned int v3; // eax@1
  UIElement *v4; // esi@1
  int v5; // eax@1
  int v6; // ebx@2

  v2 = this;
  v3 = this->m_activatableElements.m_num;
  v4 = this->m_activatableElements.m_data[v3 - 1];
  v5 = v3 - 1;
  if ( v4 )
  {
    v6 = v5;
    do
    {
      if ( UIElement::IsVisible(v4) )
        break;
      v4 = v2->m_activatableElements.m_data[v6 - 1];
      --v6;
      if ( v4 == v2->m_pRootElement )
        break;
    }
    while ( v4 );
    ((void (__thiscall *)(UIElement *))v4->vfptr[21].__vecDelDtor)(v4);
  }
}

//----- (00459990) --------------------------------------------------------  // acclient.c:150095
UIElement *__thiscall UIElementManager::GetElement(UIElementManager *this, unsigned int _ID)
{
  unsigned int v2; // edi@1
  UIElement *result; // eax@1
  unsigned int v4; // edx@1
  UIElement **v5; // esi@2

  v2 = this->m_elementList.m_num;
  result = 0;
  v4 = 0;
  if ( v2 )
  {
    v5 = this->m_elementList.m_data;
    while ( !*v5 || (*v5)->m_desc.m_elementID != _ID )
    {
      ++v4;
      ++v5;
      if ( v4 >= v2 )
        return result;
    }
    result = *v5;
  }
  return result;
}

//----- (004599D0) --------------------------------------------------------  // acclient.c:150121
bool __thiscall DBObjGrabber<LayoutDesc>::set(DBObjGrabber<LayoutDesc> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<LayoutDesc> *v2; // esi@1
  LayoutDesc *v3; // edi@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID v6; // [sp+8h] [bp-8h]@1

  v2 = this;
  v3 = this->m_object;
  QualifiedDataID::QualifiedDataID(&v6, _did, 0x23u);
  v2->m_object = (LayoutDesc *)DBObj::Get(v4);
  if ( v3 )
    v3->vfptr->Release((Interface *)v3);
  return v2->m_object != 0;
}

//----- (00459A10) --------------------------------------------------------  // acclient.c:150138
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v2; // esi@1
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable;
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
// 79BD5C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable[9])(void *, char);

//----- (00459A50) --------------------------------------------------------  // acclient.c:150159
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v2; // esi@1
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
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
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);

//----- (00459A90) --------------------------------------------------------  // acclient.c:150180
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *v2; // esi@1
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable;
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
// 79BD64: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable[7])(void *, char);

//----- (00459AD0) --------------------------------------------------------  // acclient.c:150201
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0> *v2; // esi@1
  HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable;
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
// 79BD68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable[6])(void *, char);

//----- (00459B10) --------------------------------------------------------  // acclient.c:150222
IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *__thiscall IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v2; // esi@1
  HashSetData<unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
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
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);

//----- (00459B50) --------------------------------------------------------  // acclient.c:150243
void *__thiscall SurfaceUsageSummary::vector_deleting_destructor(SurfaceUsageSummary *this, unsigned int a2)
{
  SurfaceUsageSummary *v2; // edi@1
  unsigned int v3; // eax@2
  char *v4; // ebx@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // ecx@2
  int v8; // edi@3
  int v9; // esi@4
  int v10; // esi@4
  void *result; // eax@10
  char *v12; // esi@11
  int v13; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].SurfaceHeight;
    v4 = (char *)&this[-1].SurfaceHeight;
    v5 = 3 * v3;
    v6 = v3 - 1;
    v7 = (int)&v2[8 * v5 / 0x18u];
    if ( v6 >= 0 )
    {
      v8 = v7 + 4;
      v13 = v6 + 1;
      do
      {
        v9 = *(_DWORD *)(v8 - 24);
        v8 -= 24;
        v10 = v9 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        --v13;
      }
      while ( v13 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v12 = &this->Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)v12 + 1) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (00459C00) --------------------------------------------------------  // acclient.c:150298
int __thiscall SurfaceUsageSummary::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  return v2;
}

//----- (00459C70) --------------------------------------------------------  // acclient.c:150325
void __thiscall UIElementMessageInfo::UIElementMessageInfo(UIElementMessageInfo *this, UIElementMessageInfo *__that)
{
  *this = *__that;
}

//----- (00459CC0) --------------------------------------------------------  // acclient.c:150331
char __thiscall SmartArray<Box2D,1>::grow(SmartArray<Box2D,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebx@1
  SmartArray<Box2D,1> *v3; // esi@1
  void *v5; // eax@5
  Box2D *v6; // edi@5
  int v7; // eax@7
  int v8; // ecx@8
  int v9; // eax@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@8

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Box2D,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](16 * i_nSize);
    v6 = (Box2D *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(v5, 0x10u, i_nSize, (void *(__thiscall *)(void *))Box2D::Box2D);
      if ( v3->m_data )
      {
        v7 = v3->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = (int)&v6[v7].m_y0;
          i_nSizea = v3->m_num;
          do
          {
            v9 = (int)((char *)&v3->m_data->m_x0 + -4 - (_DWORD)v6 + v8);
            if ( v8 - 4 != v9 )
            {
              *(_DWORD *)(v8 - 4) = *(_DWORD *)v9;
              *(_DWORD *)(v8 + 4) = *(_DWORD *)(v9 + 8);
              *(_DWORD *)v8 = *(_DWORD *)(v9 + 4);
              *(_DWORD *)(v8 + 8) = *(_DWORD *)(v9 + 12);
            }
            v8 -= 16;
            --i_nSizea;
          }
          while ( i_nSizea );
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v3->m_data);
      }
      v3->m_data = v6;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00459DB0) --------------------------------------------------------  // acclient.c:150392
char __thiscall List<UIElementMessageInfo>::pop_front(List<UIElementMessageInfo> *this, UIElementMessageInfo *retval)
{
  List<UIElementMessageInfo> *v2; // esi@1
  ListNode<UIElementMessageInfo> *v3; // eax@1
  char result; // al@2
  ListNode<UIElementMessageInfo> *v5; // ecx@3

  v2 = this;
  v3 = this->_head;
  if ( v3 )
  {
    v5 = v3->next;
    v2->_head = v5;
    if ( v5 )
      v5->prev = 0;
    else
      v2->_tail = 0;
    retval->idElement = v3->data.idElement;
    retval->pElement = v3->data.pElement;
    retval->idMessage = v3->data.idMessage;
    retval->dwParam1 = v3->data.dwParam1;
    retval->dwParam2 = v3->data.dwParam2;
    retval->ptWindow.x = v3->data.ptWindow.x;
    retval->ptWindow.y = v3->data.ptWindow.y;
    retval->ptElement.x = v3->data.ptElement.x;
    retval->ptElement.y = v3->data.ptElement.y;
    retval->tsSerialNumber.m_timestamp = v3->data.tsSerialNumber.m_timestamp;
    operator delete(v3);
    --v2->_num_elements;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00459E30) --------------------------------------------------------  // acclient.c:150431
void __thiscall SmartArray<SurfaceUsageSummary,1>::Reset(SmartArray<SurfaceUsageSummary,1> *this)
{
  SmartArray<SurfaceUsageSummary,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // esi@8
  int v7; // [sp+8h] [bp-1Ch]@7
  char v8; // [sp+Ch] [bp-18h]@8
  PSRefBufferCharData<char> *v9; // [sp+10h] [bp-14h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      SurfaceUsageSummary::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v7 = v4 + 1;
      do
      {
        v9 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        SurfaceUsageSummary::operator=((int)&v1->m_data[v5], (int)&v8);
        v6 = (int)&v9[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
        --v5;
        --v7;
      }
      while ( v7 );
    }
  }
}

//----- (00459EF0) --------------------------------------------------------  // acclient.c:150478
void __cdecl _STL::swap(SurfaceUsageSummary *__a, SurfaceUsageSummary *__b)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  char *v4; // esi@1
  SurfaceUsageSummary __tmp; // [sp+8h] [bp-18h]@1

  __tmp.Bytes = __a->Bytes;
  __tmp.Name.m_charbuffer = __a->Name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&__tmp.Name.m_charbuffer[-1]);
  v2 = __a->ElementHeight;
  v3 = __a->SurfaceWidth;
  __tmp.ElementWidth = __a->ElementWidth;
  __tmp.SurfaceHeight = __a->SurfaceHeight;
  __tmp.ElementHeight = v2;
  __tmp.SurfaceWidth = v3;
  SurfaceUsageSummary::operator=((int)__a, (int)__b);
  SurfaceUsageSummary::operator=((int)__b, (int)&__tmp);
  v4 = &__tmp.Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&__tmp.Name.m_charbuffer[-1]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00459F70) --------------------------------------------------------  // acclient.c:150505
void __cdecl _STL::__unguarded_linear_insert(SurfaceUsageSummary *__last, SurfaceUsageSummary __val)
{
  unsigned int v2; // ebx@1
  int v3; // ebp@1
  SurfaceUsageSummary *i; // edi@1
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // esi@7
  PSRefBufferCharData<char> *v7; // eax@10
  char *v8; // esi@12

  v2 = __val.Bytes;
  v3 = (int)__last;
  for ( i = __last - 1; ; --i )
  {
    if ( v2 < i->Bytes )
      goto LABEL_6;
    if ( v2 != i->Bytes || strcmp(__val.Name.m_charbuffer->m_data, i->Name.m_charbuffer->m_data) >= 0 )
      break;
    v2 = __val.Bytes;
LABEL_6:
    *(_DWORD *)v3 = i->Bytes;
    v5 = *(PSRefBufferCharData<char> **)(v3 + 4);
    if ( v5 != i->Name.m_charbuffer )
    {
      v6 = (int)&v5[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      v7 = i->Name.m_charbuffer;
      *(_DWORD *)(v3 + 4) = v7;
      InterlockedIncrement((volatile LONG *)&v7[-1]);
    }
    *(_DWORD *)(v3 + 8) = i->ElementWidth;
    *(_DWORD *)(v3 + 12) = i->ElementHeight;
    *(_DWORD *)(v3 + 16) = i->SurfaceWidth;
    *(_DWORD *)(v3 + 20) = i->SurfaceHeight;
    v3 = (int)i;
  }
  SurfaceUsageSummary::operator=(v3, (int)&__val);
  v8 = &__val.Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&__val.Name.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
}

//----- (0045A060) --------------------------------------------------------  // acclient.c:150552
void __cdecl _STL::__push_heap(SurfaceUsageSummary *__first, int __holeIndex, int __topIndex, SurfaceUsageSummary __val)
{
  int v4; // ebp@1
  int v5; // edx@1
  bool v6; // zf@1
  bool v7; // sf@1
  unsigned __int8 v8; // of@1
  SurfaceUsageSummary *v9; // edi@4
  SurfaceUsageSummary *v10; // esi@7
  PSRefBufferCharData<char> *v11; // eax@7
  int v12; // ebx@8
  PSRefBufferCharData<char> *v13; // eax@11
  char *v14; // esi@13
  int __holeIndexa; // [sp+10h] [bp+8h]@1

  v4 = __holeIndex;
  v5 = (__holeIndex - 1) / 2;
  v8 = __OFSUB__(__holeIndex, __topIndex);
  v6 = __holeIndex == __topIndex;
  v7 = __holeIndex - __topIndex < 0;
  __holeIndexa = (__holeIndex - 1) / 2;
  if ( !((unsigned __int8)(v7 ^ v8) | v6) )
  {
    while ( 1 )
    {
      v9 = &__first[v5];
      if ( v9->Bytes >= __val.Bytes
        && (v9->Bytes != __val.Bytes || strcmp(v9->Name.m_charbuffer->m_data, __val.Name.m_charbuffer->m_data) >= 0) )
        break;
      v10 = &__first[v4];
      v10->Bytes = v9->Bytes;
      v11 = v10->Name.m_charbuffer;
      if ( v11 != v9->Name.m_charbuffer )
      {
        v12 = (int)&v11[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        v13 = v9->Name.m_charbuffer;
        v10->Name.m_charbuffer = v13;
        InterlockedIncrement((volatile LONG *)&v13[-1]);
        v5 = __holeIndexa;
      }
      v10->ElementWidth = v9->ElementWidth;
      v10->ElementHeight = v9->ElementHeight;
      v10->SurfaceWidth = v9->SurfaceWidth;
      v4 = v5;
      __holeIndexa = (v5 - 1) / 2;
      v10->SurfaceHeight = v9->SurfaceHeight;
      if ( v5 <= __topIndex )
        break;
      v5 = (v5 - 1) / 2;
    }
  }
  SurfaceUsageSummary::operator=((int)&__first[v4], (int)&__val);
  v14 = &__val.Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&__val.Name.m_charbuffer[-1]) )
  {
    if ( v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  }
}

//----- (0045A1A0) --------------------------------------------------------  // acclient.c:150615
SurfaceUsageSummary *__cdecl _STL::__copy_backward(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, SurfaceUsageSummary *__result)
{
  SurfaceUsageSummary *v3; // esi@1
  SurfaceUsageSummary *v4; // edi@2
  unsigned int v5; // ecx@3
  PSRefBufferCharData<char> *v6; // eax@3
  int v7; // ebx@4
  PSRefBufferCharData<char> *v8; // eax@7
  bool v9; // zf@8
  SurfaceUsageSummary *result; // eax@9
  SurfaceUsageSummary *__lasta; // [sp+10h] [bp+8h]@2

  v3 = __last;
  if ( __last - __first <= 0 )
  {
    result = __result;
  }
  else
  {
    v4 = __result;
    __lasta = (SurfaceUsageSummary *)(__last - __first);
    do
    {
      v5 = v3[-1].Bytes;
      --v3;
      --v4;
      v4->Bytes = v5;
      v6 = v4->Name.m_charbuffer;
      if ( v6 != v3->Name.m_charbuffer )
      {
        v7 = (int)&v6[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) )
        {
          if ( v7 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        }
        v8 = v3->Name.m_charbuffer;
        v4->Name.m_charbuffer = v8;
        InterlockedIncrement((volatile LONG *)&v8[-1]);
      }
      v4->ElementWidth = v3->ElementWidth;
      v4->ElementHeight = v3->ElementHeight;
      v4->SurfaceWidth = v3->SurfaceWidth;
      v9 = __lasta == (SurfaceUsageSummary *)1;
      v4->SurfaceHeight = v3->SurfaceHeight;
      __lasta = (SurfaceUsageSummary *)((char *)__lasta - 1);
    }
    while ( !v9 );
    result = v4;
  }
  return result;
}

//----- (0045A240) --------------------------------------------------------  // acclient.c:150669
void __usercall UIElementManager::CleanDeleteQueue(UIElementManager *this@<ecx>, signed int a2@<edi>)
{
  UIElementManager *v2; // esi@1
  UIElement *v3; // edi@3
  unsigned int v4; // eax@4
  int v5; // eax@5
  signed int v6; // [sp-4h] [bp-8h]@2

  v2 = this;
  if ( this->m_deleteQueue.m_num )
  {
    v6 = a2;
    do
    {
      v3 = *v2->m_deleteQueue.m_data;
      if ( v3 )
      {
        ((void (__thiscall *)(UIElement *, _DWORD, signed int))v3->vfptr[5].OnLoseFocus)(v3, 0, v6);
        v4 = v2->m_deleteQueue.m_num;
        if ( v4 )
        {
          v5 = v4 - 1;
          v2->m_deleteQueue.m_num = v5;
          if ( v5 )
          {
            *v2->m_deleteQueue.m_data = v2->m_deleteQueue.m_data[v5];
            v2->m_deleteQueue.m_data[v2->m_deleteQueue.m_num] = 0;
          }
        }
        v6 = 1;
        ((void (__thiscall *)(_DWORD))v3->vfptr->__vecDelDtor)(v3);
      }
    }
    while ( v2->m_deleteQueue.m_num );
  }
}
// 45A240: could not find valid save-restore pair for edi

//----- (0045A2A0) --------------------------------------------------------  // acclient.c:150708
char __thiscall List<UIElementMessageInfo>::remove(List<UIElementMessageInfo> *this, ListNode<UIElementMessageInfo> *node)
{
  ListNode<UIElementMessageInfo> *v2; // edx@1
  List<UIElementMessageInfo> *v3; // esi@1
  ListNode<UIElementMessageInfo> *v4; // ecx@2
  ListNode<UIElementMessageInfo> *v6; // ecx@5

  v2 = 0;
  v3 = this;
  if ( !node )
    return 0;
  v4 = this->_head;
  if ( !v4 )
    return 0;
  if ( node != v4 )
  {
    node->prev->next = node->next;
    v6 = node->next;
    if ( !v6 )
    {
      v3->_tail = node->prev;
      goto LABEL_11;
    }
    v2 = node->prev;
    goto LABEL_9;
  }
  v6 = node->next;
  v3->_head = v6;
  if ( v6 )
  {
LABEL_9:
    v6->prev = v2;
    goto LABEL_11;
  }
  v3->_tail = 0;
LABEL_11:
  operator delete(node);
  --v3->_num_elements;
  return 1;
}

//----- (0045A310) --------------------------------------------------------  // acclient.c:150750
SmartArray<Box2D,1> *__thiscall SmartArray<Box2D,1>::operator=(SmartArray<Box2D,1> *this, int a2)
{
  SmartArray<Box2D,1> *v2; // esi@1
  unsigned int v3; // eax@3
  Box2D *v4; // ecx@3
  int v5; // edx@3
  int v6; // ecx@7
  int v7; // edx@8
  int v8; // eax@9
  char v10; // [sp+Ch] [bp-10h]@9

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<Box2D,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = v2->m_data;
    v5 = *(_DWORD *)a2 + 16 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      do
      {
        if ( v4 != (Box2D *)v3 )
        {
          v4->m_x0 = *(_DWORD *)v3;
          v4->m_x1 = *(_DWORD *)(v3 + 8);
          v4->m_y0 = *(_DWORD *)(v3 + 4);
          v4->m_y1 = *(_DWORD *)(v3 + 12);
        }
        v3 += 16;
        ++v4;
      }
      while ( v3 < v5 );
    }
    v6 = *(_DWORD *)(a2 + 8);
    if ( v6 < v2->m_num )
    {
      v7 = v6;
      do
      {
        v8 = (int)&v2->m_data[v7].m_x0;
        if ( (char *)v8 != &v10 )
        {
          *(_DWORD *)v8 = 0;
          *(_DWORD *)(v8 + 8) = 0;
          *(_DWORD *)(v8 + 4) = 0;
          *(_DWORD *)(v8 + 12) = 0;
        }
        ++v6;
        ++v7;
      }
      while ( v6 < v2->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (0045A3D0) --------------------------------------------------------  // acclient.c:150809
SmartArray<LOAD_WEIGHTS,1> *__thiscall SmartArray<UIMessageData,1>::operator=(SmartArray<LOAD_WEIGHTS,1> *this, int a2)
{
  SmartArray<LOAD_WEIGHTS,1> *v2; // esi@1
  unsigned int v3; // eax@3
  int v4; // edx@3
  LOAD_WEIGHTS *v5; // ecx@3
  unsigned int i; // eax@5
  LOAD_WEIGHTS *v7; // ebx@6
  unsigned int v9; // [sp+8h] [bp-8h]@0
  float v10; // [sp+Ch] [bp-4h]@0

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<LOAD_UVPAIR,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = *(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 8);
    v5 = v2->m_data;
    if ( *(_DWORD *)a2 < (unsigned int)v4 )
    {
      do
      {
        v5->matrix_index = *(_DWORD *)v3;
        LODWORD(v5->matrix_weight) = *(_DWORD *)(v3 + 4);
        v3 += 8;
        ++v5;
      }
      while ( v3 < v4 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
    {
      v7 = v2->m_data;
      v7[i].matrix_index = v9;
      v7[i].matrix_weight = v10;
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (0045A470) --------------------------------------------------------  // acclient.c:150850
char __thiscall SmartArray<SurfaceUsageSummary,1>::grow(SmartArray<SurfaceUsageSummary,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<SurfaceUsageSummary,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<SurfaceUsageSummary,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](24 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x18u,
        i_nSize,
        (void *(__thiscall *)(void *))SurfaceUsageSummary::SurfaceUsageSummary);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              SurfaceUsageSummary::operator=(v8 * 24 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              SurfaceUsageSummary::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (SurfaceUsageSummary *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (0045A550) --------------------------------------------------------  // acclient.c:150914
SurfaceUsageSummary *__cdecl _STL::__median(SurfaceUsageSummary *__a, SurfaceUsageSummary *__b, SurfaceUsageSummary *__c)
{
  SurfaceUsageSummary *result; // eax@1
  unsigned int v4; // esi@1
  unsigned int v5; // edi@1
  SurfaceUsageSummary *v6; // ebp@5
  unsigned int v7; // ebx@5
  unsigned int v8; // ebx@13

  result = __b;
  v4 = __a->Bytes;
  v5 = __b->Bytes;
  if ( __a->Bytes < __b->Bytes )
  {
LABEL_5:
    v6 = __c;
    v7 = __c->Bytes;
    if ( v5 < __c->Bytes )
      return result;
    if ( v5 != __c->Bytes || !PStringBase<char>::operator<(&result->Name, &__c->Name) )
    {
      if ( v4 < v7 || v4 == v7 && PStringBase<char>::operator<(&__a->Name, &__c->Name) )
        return v6;
      return __a;
    }
    return __b;
  }
  if ( __a->Bytes == __b->Bytes && PStringBase<char>::operator<(&__a->Name, &__b->Name) )
  {
    result = __b;
    goto LABEL_5;
  }
  v6 = __c;
  v8 = __c->Bytes;
  if ( v4 < __c->Bytes || v4 == __c->Bytes && PStringBase<char>::operator<(&__a->Name, &__c->Name) )
    return __a;
  if ( v5 < v8 || v5 == v8 && PStringBase<char>::operator<(&__b->Name, &__c->Name) )
    return v6;
  return __b;
}

//----- (0045A610) --------------------------------------------------------  // acclient.c:150956
void __cdecl _STL::__unguarded_insertion_sort_aux(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last)
{
  char *v2; // esi@2
  _BYTE v3[24]; // ST04_24@3

  if ( __first != __last )
  {
    v2 = (char *)&__first->ElementWidth;
    do
    {
      *(_DWORD *)v3 = *((_DWORD *)v2 - 2);
      *(_DWORD *)&v3[4] = *((_DWORD *)v2 - 1);
      InterlockedIncrement((volatile LONG *)(*(_DWORD *)&v3[4] - 16));
      *(_QWORD *)&v3[8] = *(_QWORD *)v2;
      *(_QWORD *)&v3[16] = *((_QWORD *)v2 + 1);
      _STL::__unguarded_linear_insert((SurfaceUsageSummary *)(v2 - 8), *(SurfaceUsageSummary *)v3);
      v2 += 24;
    }
    while ( (SurfaceUsageSummary *)(v2 - 8) != __last );
  }
}

//----- (0045A680) --------------------------------------------------------  // acclient.c:150979
void __cdecl _STL::__adjust_heap(SurfaceUsageSummary *__first, int __holeIndex, int __len, SurfaceUsageSummary __val, int __comp)
{
  int v5; // ebp@1
  int v6; // ebx@1
  bool v7; // zf@1
  unsigned int v8; // edx@2
  SurfaceUsageSummary *v9; // eax@2
  SurfaceUsageSummary *v10; // esi@6
  SurfaceUsageSummary *v11; // edi@6
  PSRefBufferCharData<char> *v12; // eax@6
  int v13; // ebp@7
  PSRefBufferCharData<char> *v14; // eax@10
  char *v15; // edi@15
  int v16; // edx@17
  _BYTE v17[24]; // [sp-1Ch] [bp-2Ch]@15
  signed int v18; // [sp-4h] [bp-14h]@15

  v5 = __holeIndex;
  v6 = 2 * __holeIndex + 2;
  v7 = v6 == __len;
  if ( v6 < __len )
  {
    do
    {
      v8 = __first[v6 - 1].Bytes;
      v9 = &__first[v6];
      if ( v9->Bytes < v8
        || v9->Bytes == v8 && strcmp(v9->Name.m_charbuffer->m_data, v9[-1].Name.m_charbuffer->m_data) < 0 )
        --v6;
      v10 = &__first[v6];
      v11 = &__first[v5];
      v11->Bytes = __first[v6].Bytes;
      v12 = v11->Name.m_charbuffer;
      if ( v12 != v10->Name.m_charbuffer )
      {
        v13 = (int)&v12[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v12[-1]) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        v14 = v10->Name.m_charbuffer;
        v11->Name.m_charbuffer = v14;
        InterlockedIncrement((volatile LONG *)&v14[-1]);
      }
      v11->ElementWidth = v10->ElementWidth;
      v11->ElementHeight = v10->ElementHeight;
      v11->SurfaceWidth = v10->SurfaceWidth;
      v5 = v6;
      v6 = 2 * v6 + 2;
      v11->SurfaceHeight = v10->SurfaceHeight;
    }
    while ( v6 < __len );
    v7 = v6 == __len;
  }
  if ( v7 )
  {
    SurfaceUsageSummary::operator=((int)&__first[v5], (int)&__first[v6 - 1]);
    v5 = v6 - 1;
  }
  v18 = __comp;
  *(SurfaceUsageSummary *)v17 = __val;
  InterlockedIncrement((volatile LONG *)&__val.Name.m_charbuffer[-1]);
  _STL::__push_heap(__first, v5, __holeIndex, *(SurfaceUsageSummary *)v17);
  v15 = &__val.Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&__val.Name.m_charbuffer[-1])
    && __val.Name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
  {
    v16 = *(_DWORD *)v15;
    v18 = 1;
    (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
  }
}

//----- (0045A800) --------------------------------------------------------  // acclient.c:151051
void __thiscall UIElementManager::SetCursor(UIElementManager *this, IDClass<_tagDataID,32,0> _cursorDID, int _xOffset, int _yOffset, bool _default)
{
  QualifiedDataID *v5; // eax@7
  int v6; // eax@7
  int v7; // esi@7
  QualifiedDataID v8; // [sp+8h] [bp-8h]@7

  if ( _default )
  {
    this->m_defaultCursorDID.id = _cursorDID.id;
    this->m_defaultCursorHotX = _xOffset;
    this->m_defaultCursorHotY = _yOffset;
  }
  if ( _cursorDID.id != INVALID_DID_52.id
    && (_cursorDID.id != this->m_lastCursorDID.id
     || _xOffset != this->m_lastCursorHotX
     || _yOffset != this->m_lastCursorHotY) )
  {
    this->m_lastCursorDID.id = _cursorDID.id;
    this->m_lastCursorHotX = _xOffset;
    this->m_lastCursorHotY = _yOffset;
    QualifiedDataID::QualifiedDataID(&v8, _cursorDID, 0xCu);
    v6 = DBObj::Get(v5);
    v7 = v6;
    if ( v6 )
    {
      Device::SetCursorFromImage(_xOffset, _yOffset, (RenderSurface *)v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    }
  }
}

//----- (0045A8A0) --------------------------------------------------------  // acclient.c:151084
char __thiscall List<UIElementMessageInfo>::push_back(List<UIElementMessageInfo> *this, UIElementMessageInfo *val)
{
  List<UIElementMessageInfo> *v2; // esi@1
  void *v3; // eax@1
  char result; // al@3
  ListNode<UIElementMessageInfo> *v5; // ecx@5

  v2 = this;
  v3 = operator new(0x30u);
  if ( v3 )
  {
    *(UIElementMessageInfo *)v3 = *val;
    *((_DWORD *)v3 + 10) = 0;
    *((_DWORD *)v3 + 11) = 0;
    if ( v2->_head )
    {
      v5 = v2->_tail;
      v5->next = (ListNode<UIElementMessageInfo> *)v3;
      *((_DWORD *)v3 + 11) = v5;
      v2->_tail = (ListNode<UIElementMessageInfo> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
    else
    {
      v2->_head = (ListNode<UIElementMessageInfo> *)v3;
      v2->_tail = (ListNode<UIElementMessageInfo> *)v3;
      ++v2->_num_elements;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045A930) --------------------------------------------------------  // acclient.c:151123
SurfaceUsageSummary *__cdecl _STL::__unguarded_partition(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, SurfaceUsageSummary __pivot)
{
  SurfaceUsageSummary *v3; // ebp@1
  SurfaceUsageSummary *i; // edi@1
  unsigned int v5; // eax@6

  v3 = __last;
  for ( i = __first; ; ++i )
  {
    while ( i->Bytes < __pivot.Bytes
         || i->Bytes == __pivot.Bytes && strcmp(i->Name.m_charbuffer->m_data, __pivot.Name.m_charbuffer->m_data) < 0 )
      ++i;
    do
    {
      do
      {
        v5 = v3[-1].Bytes;
        --v3;
      }
      while ( __pivot.Bytes < v5 );
    }
    while ( __pivot.Bytes == v5 && strcmp(__pivot.Name.m_charbuffer->m_data, v3->Name.m_charbuffer->m_data) < 0 );
    if ( i >= v3 )
      break;
    _STL::swap(i, v3);
  }
  if ( !InterlockedDecrement((volatile LONG *)&__pivot.Name.m_charbuffer[-1])
    && __pivot.Name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&__pivot.Name.m_charbuffer[-2].m_data[12])(
      &__pivot.Name.m_charbuffer[-2].m_data[12],
      1);
  return i;
}

//----- (0045AA10) --------------------------------------------------------  // acclient.c:151158
void __cdecl _STL::__pop_heap(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, SurfaceUsageSummary *__result, SurfaceUsageSummary __val, int __comp)
{
  _BYTE v5[24]; // ST0C_24@1
  signed int v6; // edx@1

  SurfaceUsageSummary::operator=((int)__result, (int)__first);
  *(_DWORD *)v5 = __val.Bytes;
  *(_QWORD *)&v5[4] = *(_QWORD *)&__val.Name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&__val.Name.m_charbuffer[-1]);
  *(_QWORD *)&v5[12] = *(_QWORD *)&__val.ElementHeight;
  *(_DWORD *)&v5[20] = __val.SurfaceHeight;
  v6 = (signed int)((unsigned __int64)(715827883i64 * ((char *)__last - (char *)__first)) >> 32) >> 2;
  _STL::__adjust_heap(__first, 0, ((unsigned int)v6 >> 31) + v6, *(SurfaceUsageSummary *)v5, __comp);
  if ( !InterlockedDecrement((volatile LONG *)&__val.Name.m_charbuffer[-1])
    && __val.Name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&__val.Name.m_charbuffer[-2].m_data[12])(
      &__val.Name.m_charbuffer[-2].m_data[12],
      1);
}

//----- (0045AAB0) --------------------------------------------------------  // acclient.c:151179
void __cdecl _STL::__make_heap(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, int __comp)
{
  int v3; // ebp@1
  int v4; // ebx@2
  char *i; // edi@2
  _BYTE v6[24]; // ST0C_24@3

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    v4 = (v3 - 2) / 2;
    for ( i = (char *)&__first[v4].ElementWidth; ; i -= 24 )
    {
      *(_DWORD *)v6 = *((_DWORD *)i - 2);
      *(_DWORD *)&v6[4] = *((_DWORD *)i - 1);
      InterlockedIncrement((volatile LONG *)(*(_DWORD *)&v6[4] - 16));
      *(_QWORD *)&v6[8] = *(_QWORD *)i;
      *(_QWORD *)&v6[16] = *((_QWORD *)i + 1);
      _STL::__adjust_heap(__first, v4, v3, *(SurfaceUsageSummary *)v6, __comp);
      if ( !v4 )
        break;
      --v4;
    }
  }
}

//----- (0045AB40) --------------------------------------------------------  // acclient.c:151206
char __thiscall UIElementManager::BroadcastElementMessage(UIElementManager *this, UIElementMessageInfo *i_rMsg)
{
  UIElementManager *v2; // ebp@1
  unsigned int v3; // ecx@2
  char v4; // bl@4
  char result; // al@5
  UIElement *v6; // ecx@6
  ListNode<UIElementMessageInfo> *v7; // esi@9
  UIElement *v8; // ecx@10
  ListNode<UIElementMessageInfo> *v9; // eax@12

  v2 = this;
  if ( _S216_31 & 1 )
  {
    v3 = s_tsMsgSerialNumber.m_timestamp;
  }
  else
  {
    _S216_31 |= 1u;
    v3 = 0;
  }
  s_tsMsgSerialNumber.m_timestamp = v3 + 1;
  i_rMsg->tsSerialNumber.m_timestamp = v3 + 1;
  v4 = 0;
  if ( v2->m_bBroadcastingMessage )
  {
    List<UIElementMessageInfo>::push_back(&v2->m_listQueuedElementMessages, i_rMsg);
    result = 0;
  }
  else
  {
    v2->m_bBroadcastingMessage = 1;
    v6 = i_rMsg->pElement;
    if ( v6 && ((int (__stdcall *)(UIElementMessageInfo *))v6->vfptr[1].__vecDelDtor)(i_rMsg) )
      v4 = 1;
    v7 = v2->m_listQueuedElementMessages._head;
    while ( v7 )
    {
      v8 = v7->data.pElement;
      if ( v8 )
        ((void (__stdcall *)(ListNode<UIElementMessageInfo> *))v8->vfptr[1].__vecDelDtor)(v7);
      v9 = v7;
      v7 = v7->next;
      List<UIElementMessageInfo>::remove(&v2->m_listQueuedElementMessages, v9);
    }
    v2->m_bBroadcastingMessage = 0;
    result = v4;
  }
  return result;
}

//----- (0045ABF0) --------------------------------------------------------  // acclient.c:151258
void __thiscall UIElementManager::CheckCursor(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  UIElement *v2; // ecx@1
  UIElement *v3; // eax@3
  UIElement *v4; // ecx@4

  v1 = this;
  v2 = this->m_pElementWithMouseCapture;
  if ( v2 && (unsigned __int8)((int (*)(void))v2->vfptr[8].OnLoseFocus)() )
  {
    v3 = v1->m_pElementWithMouseCapture;
  }
  else
  {
    v4 = v1->m_pElementLastEntered;
    if ( !v4 || !(unsigned __int8)((int (*)(void))v4->vfptr[8].OnLoseFocus)() )
      goto LABEL_9;
    v3 = v1->m_pElementLastEntered;
  }
  if ( v3 )
  {
    UIElementManager::SetCursor(v1, v3->m_cursorDID, v3->m_cursorHotX, v3->m_cursorHotY, 0);
    return;
  }
LABEL_9:
  UIElementManager::SetCursor(v1, v1->m_defaultCursorDID, v1->m_defaultCursorHotX, v1->m_defaultCursorHotY, 1);
}

//----- (0045AC70) --------------------------------------------------------  // acclient.c:151288
void __stdcall UIElementManager::DrawRegionWithObject(UIElement *i_pElementWithObject, UIObject **io_pPrevObject)
{
  UIObject *v3; // esi@1
  UIRegion *v4; // ecx@2
  ReferenceCountTemplate<1048576,1>Vtbl *v5; // eax@6
  int v6; // eax@6
  int v7; // esi@7
  SmartArray<Box2D,1> dirty; // [sp+14h] [bp-1Ch]@6
  Box2D surfaceBox; // [sp+20h] [bp-10h]@8

  v3 = i_pElementWithObject->m_object;
  if ( v3 || (v4 = i_pElementWithObject->m_parent) != 0 && (v3 = UIRegion::GetObjectA(v4)) != 0 )
  {
    if ( ((int (__thiscall *)(UIElement *))i_pElementWithObject->vfptr[13].OnAction)(i_pElementWithObject) )
    {
      RenderUI::UnlinkObject(v3);
      RenderUI::LinkObjectAfter(v3, *io_pPrevObject);
      *io_pPrevObject = v3;
      if ( v3->m_dirtyRects.m_num )
      {
        dirty.m_data = 0;
        dirty.m_sizeAndDeallocate = 0;
        dirty.m_num = 0;
        SmartArray<Box2D,1>::operator=(&dirty, (int)&v3->m_dirtyRects);
        v5 = v3->vfptr;
        v3->m_dirtyRects.m_num = 0;
        v6 = ((int (__thiscall *)(UIObject *))v5[7].__vecDelDtor)(v3);
        if ( v6 )
        {
          v7 = *(_DWORD *)(v6 + 272);
          if ( v7 )
          {
            i_pElementWithObject->vfptr[4].OnAction(
              (IInputActionCallback *)i_pElementWithObject,
              (InputEvent *)&surfaceBox);
            ((void (__thiscall *)(UIElement *, Box2D *, Box2D *, SmartArray<Box2D,1> *, int))i_pElementWithObject->vfptr[5].__vecDelDtor)(
              i_pElementWithObject,
              &surfaceBox,
              &surfaceBox,
              &dirty,
              v7);
          }
        }
        if ( (dirty.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](dirty.m_data);
      }
    }
  }
}

//----- (0045AD60) --------------------------------------------------------  // acclient.c:151339
char __thiscall SmartArray<QualityChangeHandler *,1>::add_unique(SmartArray<UIElement *,1> *this, UIElement *const *_data)
{
  SmartArray<UIElement *,1> *v2; // esi@1
  unsigned int v3; // edx@1
  unsigned int v4; // eax@1
  UIElement **v5; // ecx@2
  int v6; // eax@7
  unsigned int v7; // eax@8

  v2 = this;
  v3 = this->m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = this->m_data;
    while ( *v5 != *_data )
    {
      ++v4;
      ++v5;
      if ( v4 >= v2->m_num )
        goto LABEL_7;
    }
    if ( v4 != -1 )
      return 0;
  }
LABEL_7:
  v6 = v2->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v3 >= v6 )
  {
    v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1);
    if ( !SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v7) )
      return 0;
  }
  v2->m_data[v2->m_num++] = *_data;
  return 1;
}

//----- (0045ADE0) --------------------------------------------------------  // acclient.c:151377
void __cdecl HierarchyNotifier<MouseOverNotificationLogic>::CallFunctions(UIElement *i_pOldLeaf, UIElement *i_pNewLeaf)
{
  unsigned int v2; // ebx@1
  UIElement *v3; // edi@1
  unsigned int v4; // ebp@1
  unsigned int v5; // eax@2
  unsigned int v6; // edx@3
  int v7; // ST14_4@8
  char v13; // al@10
  UIElement *i; // edi@13
  unsigned int v15; // eax@14
  unsigned int v16; // edx@15
  int v17; // ST14_4@20
  char v19; // al@22
  int v20; // esi@25
  int j; // ebx@25
  int k; // edi@30
  int l; // esi@33
  SmartArray<UIElement *,1> aNewHierarchy; // [sp+14h] [bp-18h]@1
  SmartArray<UIElement *,1> aOldHierarchy; // [sp+20h] [bp-Ch]@1

  v2 = 0;
  v3 = i_pOldLeaf;
  v4 = 0;
  aOldHierarchy.m_data = 0;
  aOldHierarchy.m_sizeAndDeallocate = 0;
  aOldHierarchy.m_num = 0;
  aNewHierarchy.m_data = 0;
  aNewHierarchy.m_sizeAndDeallocate = 0;
  for ( aNewHierarchy.m_num = 0; v3; v3 = (UIElement *)((int (__thiscall *)(UIElement *))v3->vfptr[13].OnAction)(v3) )
  {
    v5 = aOldHierarchy.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v4 >= (aOldHierarchy.m_sizeAndDeallocate & 0x7FFFFFFF) )
    {
      v6 = v5 + 1;
      if ( v5 + 1 > 8 )
      {
        if ( v6 <= 0x4000 )
        {
          v7 = v5 + 1;
          __asm { bsr     eax, [esp+2Ch+var_1C] }
          if ( v6 > 1 << _EAX )
            v6 = 2 * (1 << _EAX);
        }
        else if ( v6 & 0x3FFF )
        {
          v6 += 0x4000 - (v6 & 0x3FFF);
        }
      }
      else
      {
        v6 = 8;
      }
      v13 = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&aOldHierarchy, v6);
      v4 = aOldHierarchy.m_num;
      if ( !v13 )
        continue;
    }
    aOldHierarchy.m_data[v4++] = v3;
    aOldHierarchy.m_num = v4;
  }
  for ( i = i_pNewLeaf; i; i = (UIElement *)((int (__thiscall *)(UIElement *))i->vfptr[13].OnAction)(i) )
  {
    v15 = aNewHierarchy.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v2 >= (aNewHierarchy.m_sizeAndDeallocate & 0x7FFFFFFF) )
    {
      v16 = v15 + 1;
      if ( v15 + 1 > 8 )
      {
        if ( v16 <= 0x4000 )
        {
          v17 = v15 + 1;
          __asm { bsr     eax, [esp+2Ch+var_1C] }
          if ( v16 > 1 << _EAX )
            v16 = 2 * (1 << _EAX);
        }
        else if ( v16 & 0x3FFF )
        {
          v16 += 0x4000 - (v16 & 0x3FFF);
        }
      }
      else
      {
        v16 = 8;
      }
      v19 = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&aNewHierarchy, v16);
      v2 = aNewHierarchy.m_num;
      if ( !v19 )
        continue;
    }
    aNewHierarchy.m_data[v2++] = i;
    aNewHierarchy.m_num = v2;
  }
  v20 = v4 - 1;
  for ( j = v2 - 1; v20 > 0; --j )
  {
    if ( j <= 0 )
      break;
    if ( aOldHierarchy.m_data[v20] != aNewHierarchy.m_data[j] )
      break;
    --v20;
  }
  if ( i_pOldLeaf )
  {
    for ( k = 0; k <= v20; ++k )
      ((void (__stdcall *)(_DWORD))aOldHierarchy.m_data[k]->vfptr[6].OnLoseFocus)(0);
  }
  if ( i_pNewLeaf )
  {
    for ( l = 0; l <= j; ++l )
      ((void (__stdcall *)(signed int))aNewHierarchy.m_data[l]->vfptr[6].OnLoseFocus)(1);
  }
  if ( (aNewHierarchy.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](aNewHierarchy.m_data);
  if ( (aOldHierarchy.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](aOldHierarchy.m_data);
}

//----- (0045AFE0) --------------------------------------------------------  // acclient.c:151496
char __thiscall IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::grow(IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::resize_internal(v2, *v3);
}

//----- (0045B030) --------------------------------------------------------  // acclient.c:151514
void __thiscall List<UIElementMessageInfo>::~List<UIElementMessageInfo>(List<UIElementMessageInfo> *this)
{
  List<UIElementMessageInfo> *v1; // esi@1
  UIElementMessageInfo retval; // [sp+4h] [bp-28h]@3

  v1 = this;
  this->vfptr = (List<UIElementMessageInfo>Vtbl *)List<UIElementMessageInfo>::vftable;
  while ( v1->_head )
  {
    retval.tsSerialNumber.m_timestamp = 0;
    List<UIElementMessageInfo>::pop_front(v1, &retval);
  }
}
// 79BD58: using guessed type int (__thiscall *List<UIElementMessageInfo>::vftable[10])(void *, char);

//----- (0045B070) --------------------------------------------------------  // acclient.c:151530
HashListIterator<HashList<UIRegion *,UIRegion *,1> > *__thiscall HashList<UIRegion *,UIRegion *,1>::begin(HashList<UIRegion *,UIRegion *,1> *this, HashListIterator<HashList<UIRegion *,UIRegion *,1> > *result)
{
  DLListData *v2; // eax@2
  HashList<UIRegion *,UIRegion *,1>::HashListData *v3; // edx@3
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > *v4; // eax@3

  if ( this->m_ihlIntrusive.m_hash.m_numElements && (v2 = this->m_ihlIntrusive.m_list.head_) != 0 )
  {
    v3 = (HashList<UIRegion *,UIRegion *,1>::HashListData *)&v2[-1];
    v4 = result;
    result->m_iter.m_pData = v3;
    result->m_iter.m_pHashList = (IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *)this;
  }
  else
  {
    v4 = result;
    result->m_iter.m_pData = 0;
    result->m_iter.m_pHashList = (IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *)this;
  }
  return v4;
}

//----- (0045B0A0) --------------------------------------------------------  // acclient.c:151553
List<UIElementMessageInfo> *__thiscall List<UIElementMessageInfo>::scalar_deleting_destructor(List<UIElementMessageInfo> *this, unsigned int a2)
{
  List<UIElementMessageInfo> *v2; // esi@1

  v2 = this;
  List<UIElementMessageInfo>::~List<UIElementMessageInfo>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0045B0C0) --------------------------------------------------------  // acclient.c:151565
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateElementRecursiveFromFullDesc(UIElementManager *this, LayoutDesc *_layout, ElementDesc *full_desc)
{
  ElementDesc *v3; // edi@1
  UIElementManager *v4; // ebx@1
  HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *v5; // eax@1
  void *(__thiscall *v6)(HashSet<UIElement *> *, unsigned int); // eax@6
  unsigned int v7; // ecx@7
  HashSet<UIElement *>Vtbl *v8; // eax@8
  int v9; // ebp@15
  HashTable<unsigned long,unsigned long,0> *v10; // eax@16
  HashTable<unsigned long,unsigned long,0> *v11; // esi@16
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v12; // eax@22
  HashTableData<unsigned long,HeritageGroup_CG> *v13; // esi@22
  HashTableData<unsigned long,HeritageGroup_CG> **v14; // edi@22
  HashSet<UIElement *>Vtbl *v15; // eax@23
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *c_iter; // [sp+8h] [bp-18h]@22
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@22

  v3 = full_desc;
  v4 = this;
  v5 = v4->m_classCreateMethodTable.m_intrusiveTable.m_buckets[full_desc->m_type
                                                             % v4->m_classCreateMethodTable.m_intrusiveTable.m_numBuckets];
  if ( !v5 )
    goto LABEL_7;
  while ( v5->m_hashKey != full_desc->m_type )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      goto LABEL_7;
  }
  if ( !v5 || (v6 = (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))v5->m_data) == 0 )
  {
LABEL_7:
    v7 = full_desc->m_engineType;
    if ( !v7 )
      return 0;
    v8 = (HashSet<UIElement *>Vtbl *)v4->m_classCreateMethodTable.m_intrusiveTable.m_buckets[v7
                                                                                           % v4->m_classCreateMethodTable.m_intrusiveTable.m_numBuckets];
    if ( !v8 )
      return 0;
    while ( v8->__vecDelDtor != (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))v7 )
    {
      v8 = (HashSet<UIElement *>Vtbl *)v8[1].__vecDelDtor;
      if ( !v8 )
        return v8;
    }
    if ( !v8 )
      return 0;
    v6 = v8[2].__vecDelDtor;
    if ( !v6 )
      return 0;
  }
  v9 = ((int (__cdecl *)(LayoutDesc *, ElementDesc *))v6)(_layout, full_desc);
  full_desc = (ElementDesc *)v9;
  if ( v9 )
  {
    SmartArray<UIElement_Button *,1>::AddToEnd(
      (SmartArray<BSPNODE *,1> *)&v4->m_elementList,
      (BSPNODE *const *)&full_desc);
    full_desc = *(ElementDesc **)(v9 + 740);
    v10 = (HashTable<unsigned long,unsigned long,0> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                                        (HashTable<unsigned long,unsigned long,0> *)&v4->m_elementListenerTable,
                                                        (const unsigned int *)&full_desc);
    v11 = v10;
    if ( v10
      && (HashSet<unsigned long>::contains(v10, &Element_mouse_press_UIElementMessage)
       || HashSet<unsigned long>::contains(v11, &Element_mouse_release_UIElementMessage)
       || HashSet<unsigned long>::contains(v11, &Element_mouse_click_UIElementMessage)
       || HashSet<unsigned long>::contains(v11, &Element_mouse_tap_UIElementMessage)) )
      (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v9 + 272))(v9, 1);
    v12 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_children.m_intrusiveTable,
            &result);
    v13 = v12->m_currElement;
    v14 = v12->m_currBucket;
    c_iter = v12->m_currHashTable;
    if ( v13 )
    {
      do
      {
LABEL_23:
        v15 = UIElementManager::CreateElement(v4, _layout, (ElementDesc *)&v13->m_data);
        if ( v15 )
          (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, int))v15->__vecDelDtor + 17))(v15, v9);
        v13 = v13->m_hashNext;
      }
      while ( v13 );
      while ( 1 )
      {
        ++v14;
        if ( v14 == &c_iter->m_buckets[c_iter->m_numBuckets] )
          break;
        if ( *v14 )
        {
          v13 = *v14;
          if ( *v14 )
            goto LABEL_23;
          break;
        }
      }
    }
    v8 = (HashSet<UIElement *>Vtbl *)v9;
  }
  else
  {
    v8 = 0;
  }
  return v8;
}

//----- (0045B270) --------------------------------------------------------  // acclient.c:151676
void __thiscall UIElementManager::AddElementToDeleteQueue(UIElementManager *this, UIElement *_element)
{
  UIElement *v2; // esi@1

  v2 = _element;
  if ( _element && SmartArray<QualityChangeHandler *,1>::add_unique(&this->m_deleteQueue, &_element) )
  {
    v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
    if ( (unsigned __int8)UIElement::GetShouldOwnObject(v2) )
      UIElement::SetShouldOwnObject(v2, 0);
    ((void (__thiscall *)(UIElement *, _DWORD))v2->vfptr[5].OnLoseFocus)(v2, 0);
  }
}

//----- (0045B2C0) --------------------------------------------------------  // acclient.c:151691
char __thiscall UIElementManager::BroadcastElementMessage(UIElementManager *this, unsigned int _elementID, UIElement *_element, unsigned int _messageID, int _data_int)
{
  char v5; // bl@1
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v6; // eax@1
  HashTable<unsigned long,unsigned long,0> *v8; // eax@6
  unsigned int *v9; // eax@7
  unsigned int *v10; // esi@7
  unsigned int v11; // edi@8
  int v12; // ebp@9
  int v13; // ecx@10
  int v14; // eax@12

  v5 = 0;
  v6 = this->m_elementListenerTable.m_intrusiveTable.m_buckets[_elementID
                                                             % this->m_elementListenerTable.m_intrusiveTable.m_numBuckets];
  if ( v6 )
  {
    while ( v6->m_hashKey != _elementID )
    {
      v6 = v6->m_hashNext;
      if ( !v6 )
        return 0;
    }
    if ( v6 )
    {
      v8 = (HashTable<unsigned long,unsigned long,0> *)&v6->m_data;
      if ( v8 )
      {
        v9 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(v8, &_messageID);
        v10 = v9;
        if ( v9 )
        {
          v11 = 0;
          if ( v9[2] )
          {
            v12 = _data_int;
            do
            {
              v13 = *(_DWORD *)(*v10 + 8 * v11);
              if ( v13 && *(_DWORD *)(*v10 + 8 * v11 + 4) > 0 )
              {
                v14 = (*(int (__stdcall **)(unsigned int, UIElement *, unsigned int, int))(*(_DWORD *)v13 + 16))(
                        _elementID,
                        _element,
                        _messageID,
                        v12);
                if ( !v5 )
                {
                  if ( v14 )
                    v5 = 1;
                }
                if ( v14 == 2 )
                  break;
              }
              ++v11;
            }
            while ( v11 < v10[2] );
          }
        }
      }
    }
  }
  return v5;
}

//----- (0045B370) --------------------------------------------------------  // acclient.c:151757
char __thiscall UIElementManager::BroadcastElementMessage(UIElementManager *this, UIElement *i_pElement, unsigned int i_idMessage, unsigned int i_dwParam1, unsigned int i_dwParam2)
{
  char result; // al@2
  unsigned int v6; // esi@3
  UIElementMessageInfo msg; // [sp+0h] [bp-28h]@3

  if ( i_pElement )
  {
    v6 = i_pElement->m_desc.m_elementID;
    msg.pElement = i_pElement;
    msg.idMessage = i_idMessage;
    msg.tsSerialNumber.m_timestamp = 0;
    msg.ptWindow.x = 0;
    msg.ptWindow.y = 0;
    msg.ptElement.x = 0;
    msg.ptElement.y = 0;
    msg.dwParam1 = i_dwParam1;
    msg.idElement = v6;
    msg.dwParam2 = i_dwParam2;
    result = UIElementManager::BroadcastElementMessage(this, &msg);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045B3E0) --------------------------------------------------------  // acclient.c:151786
void __thiscall UIElementManager::BroadcastGlobalMessage(UIElementManager *this, unsigned int _messageID, int _data_int)
{
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v3; // eax@1
  int v4; // esi@6
  unsigned int v5; // edi@7
  int v6; // eax@8

  v3 = this->m_globalMessageListenerTable.m_intrusiveTable.m_buckets[_messageID
                                                                   % this->m_globalMessageListenerTable.m_intrusiveTable.m_numBuckets];
  if ( v3 )
  {
    while ( v3->m_hashKey != _messageID )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      v4 = (int)&v3->m_data;
      if ( v3 != (HashTableData<unsigned long,SmartArray<UIMessageData,1> > *)-8 )
      {
        v5 = 0;
        if ( v3->m_data.m_num )
        {
          do
          {
            v6 = *(_DWORD *)v4 + 8 * v5;
            if ( *(_DWORD *)v6 )
            {
              if ( *(_DWORD *)(v6 + 4) > 0 )
                (*(void (__stdcall **)(unsigned int, int))(**(_DWORD **)v6 + 20))(_messageID, _data_int);
            }
            ++v5;
          }
          while ( v5 < *(_DWORD *)(v4 + 8) );
        }
      }
    }
  }
}

//----- (0045B460) --------------------------------------------------------  // acclient.c:151829
void __thiscall UIElementManager::UnRegisterForMessageInternal(UIElementManager *this, UIListener *_pListener, AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *_pTable, unsigned int _messageID)
{
  UIListener *v4; // edi@1
  UIElementManager *v5; // ebx@1
  unsigned int *v6; // eax@3
  unsigned int v7; // esi@4
  unsigned int v8; // edx@4
  unsigned int v9; // ecx@5
  UIListener *v10; // edx@9
  bool v11; // zf@9
  bool v12; // sf@9
  void *v13; // edx@9
  int v14; // edx@11
  UIMessageRemovalData remove; // [sp+8h] [bp-8h]@12

  v4 = _pListener;
  v5 = this;
  if ( _pListener )
  {
    if ( _pTable )
    {
      v6 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
             (HashTable<unsigned long,unsigned long,0> *)_pTable,
             &_messageID);
      if ( v6 )
      {
        v7 = v6[2];
        v8 = 0;
        if ( v7 )
        {
          v9 = *v6;
          while ( *(UIListener **)v9 != v4 )
          {
            ++v8;
            v9 += 8;
            if ( v8 >= v7 )
              return;
          }
          v10 = (UIListener *)(*(_DWORD *)(v9 + 4) - 1);
          _pListener = v10;
          v11 = v10 == 0;
          v12 = (signed int)v10 < 0;
          _pTable = 0;
          v13 = &_pListener;
          if ( v12 || v11 )
            v13 = &_pTable;
          v14 = *(_DWORD *)v13;
          *(_DWORD *)(v9 + 4) = v14;
          if ( !v14 )
          {
            remove.pListener = v4;
            remove.pListenerArray = (SmartArray<UIMessageData,1> *)v6;
            SmartArray<UIMessageRemovalData,1>::add(
              (SmartArray<UIMessageData,1> *)&v5->m_aUIMessageRemovalData,
              (UIMessageData *)&remove);
          }
        }
      }
    }
  }
}

//----- (0045B4F0) --------------------------------------------------------  // acclient.c:151892
void __thiscall UIElementManager::UnRegisterForAllMessagesInternal(UIElementManager *this, UIListener *_pListener, SmartArray<UIMessageData,1> *_uiListenerArray)
{
  unsigned int v3; // esi@1
  unsigned int v4; // edx@1
  UIMessageData *v5; // eax@2
  char *v6; // esi@6
  unsigned int v7; // eax@6
  unsigned int v8; // eax@7
  int v9; // eax@8
  int v10; // ecx@8

  v3 = _uiListenerArray->m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = _uiListenerArray->m_data;
    while ( v5->pListener != _pListener )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
        return;
    }
    v6 = (char *)&this->m_aUIMessageRemovalData;
    v5->nCount = 0;
    v7 = this->m_aUIMessageRemovalData.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( this->m_aUIMessageRemovalData.m_num < v7
      || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
          SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)v6, v8)) )
    {
      v9 = *((_DWORD *)v6 + 2);
      v10 = *(_DWORD *)v6;
      *(_DWORD *)(v10 + 8 * v9) = _pListener;
      *(_DWORD *)(v10 + 8 * v9 + 4) = _uiListenerArray;
      ++*((_DWORD *)v6 + 2);
    }
  }
}

//----- (0045B560) --------------------------------------------------------  // acclient.c:151932
void __thiscall UIElementManager::SwitchMouseOver(UIElementManager *this, UIElement *pCurMouseOver)
{
  UIElementManager *v2; // esi@1
  UIElement *v3; // edi@1
  UIElement *v4; // eax@4
  UIElement *v5; // eax@9
  UIElement *v6; // edi@17
  UIElement *v7; // eax@21

  v2 = this;
  v3 = 0;
  if ( pCurMouseOver != this->m_pElementLastOver )
    this->m_pElementLastOver = pCurMouseOver;
  if ( pCurMouseOver )
  {
    v4 = this->m_pElementWithMouseCapture;
    if ( v4 )
    {
      if ( v4 != pCurMouseOver )
        goto LABEL_9;
    }
    else if ( !pCurMouseOver->m_bIsMouseVisible )
    {
      goto LABEL_9;
    }
    v3 = pCurMouseOver;
  }
LABEL_9:
  v5 = this->m_pElementLastEntered;
  if ( v3 != v5 )
  {
    HierarchyNotifier<MouseOverNotificationLogic>::CallFunctions(v5, v3);
    if ( v2->m_pElementLastEntered )
    {
      UIElementManager::StopHover(v2);
      ((void (__stdcall *)(_DWORD))v2->m_pElementLastEntered->vfptr[7].__vecDelDtor)(0);
    }
    if ( v3 && v3->m_bIsMouseVisible )
    {
      v2->m_pElementLastEntered = v3;
      v3->vfptr[7].__vecDelDtor((IInputActionCallback *)v3, 1u);
    }
    else
    {
      v2->m_pElementLastEntered = 0;
    }
    UIElementManager::CheckCursor(v2);
  }
  v6 = 0;
  if ( pCurMouseOver && v2->m_bDragStarted && v2->m_dragElement )
    v6 = (UIElement *)((int (__thiscall *)(_DWORD, _DWORD))pCurMouseOver->vfptr[19].OnLoseFocus)(
                        pCurMouseOver,
                        v2->m_dragElement);
  v7 = v2->m_pElementLastDragCursorOver;
  if ( v6 != v7 )
  {
    if ( v7 )
      UIElementManager::BroadcastElementMessage(v2, v7, 0x3Eu, 0, 0);
    if ( v6 )
      UIElementManager::BroadcastElementMessage(v2, v6, 0x3Eu, 1u, 0);
    v2->m_pElementLastDragCursorOver = v6;
  }
}

//----- (0045B660) --------------------------------------------------------  // acclient.c:151997
char __thiscall UIElementManager::DoVisibilityToggleAction(UIElementManager *this, unsigned int _action)
{
  UIElementManager *v2; // ebx@1
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v3; // eax@1
  char result; // al@4
  int v5; // esi@6
  unsigned int v6; // edi@7
  UIElement *v7; // eax@8

  v2 = this;
  v3 = this->m_elementInputActionListenerTable.m_intrusiveTable.m_buckets[_action
                                                                        % this->m_elementInputActionListenerTable.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != _action )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 && (v5 = (int)&v3->m_data, v3 != (HashTableData<unsigned long,SmartArray<UIElement *,1> > *)-8) )
  {
    v6 = 0;
    if ( v3->m_data.m_num )
    {
      do
      {
        v7 = *(UIElement **)(*(_DWORD *)v5 + 4 * v6);
        if ( v7 )
          UIElementManager::BroadcastElementMessage(v2, v7, 0x31u, _action, 0);
        ++v6;
      }
      while ( v6 < *(_DWORD *)(v5 + 8) );
    }
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0045B6E0) --------------------------------------------------------  // acclient.c:152042
void __thiscall UIElementManager::CheckTooltip(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  UIElement *v2; // ecx@4
  CInputManager *v3; // edi@8
  int v4; // ST04_4@8
  int v5; // eax@8
  UIElement *v6; // ecx@9
  float tDelay; // [sp+4h] [bp-Ch]@5
  long double now; // [sp+8h] [bp-8h]@1

  v1 = this;
  now = Timer::local_time;
  if ( this->m_bHoverStarted || this->m_bMouseHasLeftTheWindow )
  {
    v6 = this->m_pTooltipElement;
    if ( v6 && v1->m_tooltipDuration <= now - v1->m_tooltipStart )
    {
      UIElement::AddToDeleteQueue(v6);
      v1->m_pTooltipElement = 0;
      UIElementManager::SwitchMouseOver(v1, 0);
    }
  }
  else if ( !this->m_pElementWithMouseCapture )
  {
    v2 = this->m_pElementLastEntered;
    if ( v2 )
    {
      if ( !UIElement::GetAttribute_Float(v2, 0x50u, &tDelay) )
        tDelay = v1->m_tooltipDelay;
      if ( tDelay + v1->m_lastMouseMoveTime < now )
      {
        v3 = ICIDM::s_cidm;
        v4 = ICIDM::s_cidm->vfptr->GetMouseY((ICIDM *)ICIDM::s_cidm);
        v5 = v3->vfptr->GetMouseX((ICIDM *)v3);
        UIElementManager::StartHover(v1, v5, v4);
      }
    }
  }
}

//----- (0045B7C0) --------------------------------------------------------  // acclient.c:152084
void __thiscall UIElementManager::DrawRegion(UIElementManager *this, UIElement *i_pElement, UIObject **io_pPrevObject)
{
  UIElementManager *v3; // ebx@1
  UIElement *i; // esi@4

  v3 = this;
  if ( (*((_DWORD *)&i_pElement->0 + 41) >> 1) & 1 )
  {
    if ( *((_BYTE *)&i_pElement->1 + 2) & 1 )
      UIElementManager::DrawRegionWithObject(i_pElement, io_pPrevObject);
    for ( i = UIElement::GetFirstChildElement(i_pElement); i; i = UIElement::GetNextChildElement(i_pElement, i) )
      UIElementManager::DrawRegion(v3, i, io_pPrevObject);
  }
}

//----- (0045B820) --------------------------------------------------------  // acclient.c:152100
void __thiscall UIElementManager::DrawDirtyRegions(UIElementManager *this)
{
  UIElementManager *v1; // edi@1
  char *v2; // eax@1
  int v3; // esi@1
  int v4; // ecx@2
  int v5; // esi@6
  UIObject *pPrev; // [sp+8h] [bp-Ch]@1
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+Ch] [bp-8h]@5

  v1 = this;
  v2 = (char *)&this->m_pRootElement->m_children;
  pPrev = 0;
  v3 = 0;
  if ( *((_DWORD *)v2 + 27) )
  {
    v4 = *((_DWORD *)v2 + 28);
    if ( v4 )
      v3 = v4 - 8;
    else
      v3 = 0;
  }
  for ( iter.m_iter.m_pHashList = (IntrusiveHashList<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1> *)v2;
        v3;
        v3 = v5 - 8 )
  {
    UIElementManager::DrawRegion(v1, *(UIElement **)(v3 + 16), &pPrev);
    v5 = *(_DWORD *)(v3 + 8);
    if ( !v5 )
      break;
  }
}

//----- (0045B890) --------------------------------------------------------  // acclient.c:152134
void __thiscall UIElementManager::SetFocusElement(UIElementManager *this, UIElement *_focusElement)
{
  UIElementManager *v2; // esi@1
  UIElement *v3; // eax@1

  v2 = this;
  v3 = this->m_focusElement;
  if ( v3 != _focusElement )
  {
    if ( v3 )
    {
      UIElementManager::BroadcastElementMessage(this, v3, 0x2Fu, 0, 0);
      ((void (*)(void))v2->m_focusElement->vfptr[15].__vecDelDtor)();
    }
    v2->m_focusElement = _focusElement;
    if ( _focusElement )
    {
      UIElementManager::BroadcastElementMessage(v2, _focusElement, 0x2Fu, 1u, 0);
      ((void (__stdcall *)(signed int))v2->m_focusElement->vfptr[14].OnLoseFocus)(3000);
    }
  }
}

//----- (0045B900) --------------------------------------------------------  // acclient.c:152158
char __thiscall SmartArray<SurfaceUsageSummary,1>::add(SmartArray<SurfaceUsageSummary,1> *this, SurfaceUsageSummary *_data)
{
  SmartArray<SurfaceUsageSummary,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<SurfaceUsageSummary,1>::grow(v2, v4)) != 0) )
  {
    SurfaceUsageSummary::operator=((int)&v2->m_data[v2->m_num++], (int)_data);
    result = 1;
  }
  return result;
}

//----- (0045B950) --------------------------------------------------------  // acclient.c:152178
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &)> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BD68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable[6])(void *, char);

//----- (0045B9E0) --------------------------------------------------------  // acclient.c:152211
void __thiscall IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);

//----- (0045BA70) --------------------------------------------------------  // acclient.c:152244
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BD5C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable[9])(void *, char);

//----- (0045BB00) --------------------------------------------------------  // acclient.c:152277
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);

//----- (0045BB90) --------------------------------------------------------  // acclient.c:152310
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79BD64: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable[7])(void *, char);

//----- (0045BC20) --------------------------------------------------------  // acclient.c:152343
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0045BC70) --------------------------------------------------------  // acclient.c:152363
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0045BCC0) --------------------------------------------------------  // acclient.c:152383
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (0045BD10) --------------------------------------------------------  // acclient.c:152403
char __thiscall IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v3; // esi@1
  char result; // al@2
  HashSetData<unsigned long> *v5; // edi@3
  int v6; // ecx@4
  HashSetData<unsigned long> **v7; // eax@5
  int v8; // eax@6
  HashSetData<unsigned long> **v9; // ebx@7
  HashSetData<unsigned long> *v10; // ecx@7
  HashSetData<unsigned long> *v11; // eax@9
  HashSetData<unsigned long> *v12; // edx@10
  HashSetData<unsigned long> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashSetData<unsigned long> **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (HashSetData<unsigned long> **)v6 )
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
            v3->m_firstInterestingBucket = (HashSetData<unsigned long> **)v8;
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
    if ( (HashSetData<unsigned long> **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashSetData<unsigned long> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashSetData<unsigned long> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0045BE50) --------------------------------------------------------  // acclient.c:152519
void __cdecl _STL::__linear_insert(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, SurfaceUsageSummary __val)
{
  SurfaceUsageSummary *v3; // esi@1
  unsigned int v4; // edi@1
  PSRefBufferCharData<char> *v5; // edi@4
  _BYTE v6[24]; // ST04_24@5

  v3 = __first;
  v4 = __val.Bytes;
  if ( __val.Bytes < __first->Bytes
    || __val.Bytes == __first->Bytes && PStringBase<char>::operator<(&__val.Name, &__first->Name) )
  {
    _STL::__copy_backward(v3, __last, __last + 1);
    SurfaceUsageSummary::operator=((int)v3, (int)&__val);
    v5 = __val.Name.m_charbuffer;
  }
  else
  {
    *(_QWORD *)v6 = __PAIR__((unsigned int)__val.Name.m_charbuffer, v4);
    v5 = __val.Name.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&__val.Name.m_charbuffer[-1]);
    *(_QWORD *)&v6[8] = *(_QWORD *)&__val.ElementWidth;
    *(_QWORD *)&v6[16] = *(_QWORD *)&__val.SurfaceWidth;
    _STL::__unguarded_linear_insert(__last, *(SurfaceUsageSummary *)v6);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v5 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v5[-2].m_data[12])(&v5[-2].m_data[12], 1);
}

//----- (0045BF10) --------------------------------------------------------  // acclient.c:152549
void __cdecl _STL::sort_heap(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, int __comp)
{
  char *v3; // esi@2
  _BYTE v4[24]; // ST0C_24@3

  if ( __last - __first > 1 )
  {
    v3 = (char *)&__last[-1].ElementWidth;
    do
    {
      *(_DWORD *)v4 = *((_DWORD *)v3 - 2);
      *(_DWORD *)&v4[4] = *((_DWORD *)v3 - 1);
      InterlockedIncrement((volatile LONG *)(*(_DWORD *)&v4[4] - 16));
      *(_QWORD *)&v4[8] = *(_QWORD *)v3;
      *(_QWORD *)&v4[16] = *((_QWORD *)v3 + 1);
      _STL::__pop_heap(
        __first,
        (SurfaceUsageSummary *)(v3 - 8),
        (SurfaceUsageSummary *)(v3 - 8),
        *(SurfaceUsageSummary *)v4,
        __comp);
      v3 -= 24;
    }
    while ( (signed int)&v3[16 - (_DWORD)__first] / 24 > 1 );
  }
}

//----- (0045BFB0) --------------------------------------------------------  // acclient.c:152577
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateElementRecursiveFromPartialDesc(UIElementManager *this, LayoutDesc *_layout, ElementDesc *_desc)
{
  UIElementManager *v3; // esi@1
  HashSet<UIElement *>Vtbl *result; // eax@5
  HashSet<UIElement *>Vtbl *v5; // esi@6
  SmartArray<BaseInfo,1> recurse; // [sp+4h] [bp-1D0h]@1
  ElementDesc full_desc; // [sp+10h] [bp-1C4h]@1

  v3 = this;
  ElementDesc::ElementDesc(&full_desc);
  recurse.m_data = 0;
  recurse.m_sizeAndDeallocate = 0;
  recurse.m_num = 0;
  if ( LayoutDesc::InqFullDesc(_desc, &full_desc, &recurse) )
  {
    v5 = UIElementManager::CreateElementRecursiveFromFullDesc(v3, _layout, &full_desc);
    if ( (recurse.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)recurse.m_data )
      operator delete[](&recurse.m_data[-1].layoutID);
    ElementDesc::~ElementDesc(&full_desc);
    result = v5;
  }
  else
  {
    if ( (recurse.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      if ( (_DWORD)recurse.m_data )
        operator delete[](&recurse.m_data[-1].layoutID);
    }
    ElementDesc::~ElementDesc(&full_desc);
    result = 0;
  }
  return result;
}

//----- (0045C080) --------------------------------------------------------  // acclient.c:152612
void __thiscall UIElementManager::RemoveAndDeleteRootElement(UIElementManager *this, UIElement *_element)
{
  UIElement *v2; // esi@1

  v2 = _element;
  if ( _element && SmartArray<QualityChangeHandler *,1>::add_unique(&this->m_deleteQueue, &_element) )
  {
    v2->vfptr[2].__vecDelDtor((IInputActionCallback *)v2, 0);
    if ( (unsigned __int8)UIElement::GetShouldOwnObject(v2) )
      UIElement::SetShouldOwnObject(v2, 0);
    ((void (__thiscall *)(UIElement *, _DWORD))v2->vfptr[5].OnLoseFocus)(v2, 0);
  }
}

//----- (0045C0D0) --------------------------------------------------------  // acclient.c:152627
void __thiscall UIElementManager::UnRegisterForElementMessage(UIElementManager *this, UIListener *_listener, unsigned int _elementID, unsigned int _messageID)
{
  UIElementManager *v4; // esi@1
  AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *v5; // eax@2

  v4 = this;
  if ( _listener )
  {
    v5 = (AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                                                            (HashTable<unsigned long,unsigned long,0> *)&this->m_elementListenerTable,
                                                                            &_elementID);
    if ( v5 )
      UIElementManager::UnRegisterForMessageInternal(v4, _listener, v5, _messageID);
  }
}

//----- (0045C110) --------------------------------------------------------  // acclient.c:152644
void __thiscall UIElementManager::UnRegisterForGlobalMessage(UIElementManager *this, UIListener *_listener, unsigned int _messageID)
{
  if ( _listener )
    UIElementManager::UnRegisterForMessageInternal(this, _listener, &this->m_globalMessageListenerTable, _messageID);
}

//----- (0045C130) --------------------------------------------------------  // acclient.c:152651
void __thiscall UIElementManager::UnRegisterForAllMessages(UIElementManager *this, UIListener *_listener)
{
  UIElementManager *v2; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edx@2
  int v6; // ecx@3
  HashTableData<unsigned long,Sex_CG> *v7; // eax@4
  int v8; // eax@5
  HashTableData<unsigned long,Sex_CG> *v9; // eax@6
  unsigned int v10; // esi@6
  HashTableData<unsigned long,Sex_CG> *v11; // edi@8
  int v12; // ecx@18
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v13; // eax@19
  int v14; // eax@20
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v15; // eax@21
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v16; // esi@21
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v17; // edi@23
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *elIter; // [sp+4h] [bp-18h]@2
  HashTableData<unsigned long,HeritageGroup_CG> **elIter_4; // [sp+8h] [bp-14h]@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@2

  v2 = this;
  if ( _listener )
  {
    v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_elementListenerTable.m_intrusiveTable,
           &result);
    v4 = v3->m_currElement;
    v5 = v3->m_currBucket;
    elIter = v3->m_currHashTable;
    elIter_4 = v3->m_currBucket;
    if ( v4 )
    {
      do
      {
LABEL_3:
        v6 = (int)((char *)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[4]
                 + 4 * (unsigned int)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[6]);
        if ( v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[5] == (HashTableData<unsigned long,Sex_CG> *)v6 )
        {
LABEL_6:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[5];
            if ( v7->m_hashKey )
              break;
            v8 = (int)&v7->m_hashNext;
            v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[5] = (HashTableData<unsigned long,Sex_CG> *)v8;
            if ( v8 == v6 )
              goto LABEL_6;
          }
          v9 = v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[5];
          v10 = v9->m_hashKey;
        }
        v11 = v9;
        if ( v10 )
        {
          do
          {
LABEL_9:
            UIElementManager::UnRegisterForAllMessagesInternal(v2, _listener, (SmartArray<UIMessageData,1> *)(v10 + 8));
            v10 = *(_DWORD *)(v10 + 4);
          }
          while ( v10 );
          while ( 1 )
          {
            v11 = (HashTableData<unsigned long,Sex_CG> *)((char *)v11 + 4);
            if ( v11 == (HashTableData<unsigned long,Sex_CG> *)((char *)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[4]
                                                              + 4
                                                              * (unsigned int)v4->m_data.mGenderList.m_intrusiveTable.m_aInplaceBuckets[6]) )
              break;
            if ( v11->m_hashKey )
            {
              v10 = v11->m_hashKey;
              if ( v11->m_hashKey )
                goto LABEL_9;
              break;
            }
          }
          v5 = elIter_4;
        }
        v4 = v4->m_hashNext;
      }
      while ( v4 );
      while ( 1 )
      {
        ++v5;
        elIter_4 = v5;
        if ( v5 == &elIter->m_buckets[elIter->m_numBuckets] )
          break;
        if ( *v5 )
        {
          v4 = *v5;
          if ( *v5 )
            goto LABEL_3;
          break;
        }
      }
    }
    v12 = (int)&v2->m_globalMessageListenerTable.m_intrusiveTable.m_buckets[v2->m_globalMessageListenerTable.m_intrusiveTable.m_numBuckets];
    if ( v2->m_globalMessageListenerTable.m_intrusiveTable.m_firstInterestingBucket == (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v12 )
    {
LABEL_21:
      v15 = 0;
      v16 = 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = v2->m_globalMessageListenerTable.m_intrusiveTable.m_firstInterestingBucket;
        if ( *v13 )
          break;
        v14 = (int)(v13 + 1);
        v2->m_globalMessageListenerTable.m_intrusiveTable.m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v14;
        if ( v14 == v12 )
          goto LABEL_21;
      }
      v15 = v2->m_globalMessageListenerTable.m_intrusiveTable.m_firstInterestingBucket;
      v16 = *v15;
    }
    v17 = v15;
    if ( v16 )
    {
      do
      {
LABEL_24:
        UIElementManager::UnRegisterForAllMessagesInternal(v2, _listener, &v16->m_data);
        v16 = v16->m_hashNext;
      }
      while ( v16 );
      while ( 1 )
      {
        ++v17;
        if ( v17 == &v2->m_globalMessageListenerTable.m_intrusiveTable.m_buckets[v2->m_globalMessageListenerTable.m_intrusiveTable.m_numBuckets] )
          break;
        if ( *v17 )
        {
          v16 = *v17;
          if ( *v17 )
            goto LABEL_24;
          return;
        }
      }
    }
  }
}

//----- (0045C2A0) --------------------------------------------------------  // acclient.c:152806
void __thiscall UIElementManager::MouseLeaveEvent(UIElementManager *this)
{
  this->m_bMouseHasLeftTheWindow = 1;
  UIElementManager::SwitchMouseOver(this, 0);
}

//----- (0045C2B0) --------------------------------------------------------  // acclient.c:152813
void __thiscall UIElementManager::UpdateMouseOver(UIElementManager *this, int i_xWindow, int i_yWindow)
{
  UIElementManager *v3; // esi@1
  UIElement *v4; // eax@1
  UIElement *o_pRet; // [sp+0h] [bp-4h]@1

  o_pRet = (UIElement *)this;
  v3 = this;
  v4 = 0;
  if ( !this->m_bMouseHasLeftTheWindow )
  {
    o_pRet = 0;
    MouseHitTester<MouseOverCriteria>::Recurse(this->m_pRootElement, i_xWindow, i_yWindow, &o_pRet);
    v4 = o_pRet;
  }
  UIElementManager::SwitchMouseOver(v3, v4);
}

//----- (0045C300) --------------------------------------------------------  // acclient.c:152832
void __thiscall UIElementManager::KeyPressEvent(UIElementManager *this, unsigned int _action, float _extent)
{
  UIElementManager *v3; // esi@1
  UIElement *v4; // ecx@2

  v3 = this;
  if ( !SceneTool::m_pDebugConsole->m_IsInputActive )
  {
    v4 = this->m_focusElement;
    if ( !v4 && (v4 = v3->m_activeElement) == 0
      || !(unsigned __int8)((int (__stdcall *)(unsigned int, _DWORD))v4->vfptr[14].OnAction)(_action, LODWORD(_extent)) )
      UIElementManager::BroadcastGlobalMessage(v3, 1u, _action);
    UIElementManager::DoVisibilityToggleAction(v3, _action);
  }
}

//----- (0045C360) --------------------------------------------------------  // acclient.c:152849
void __thiscall UIElementManager::ResetTooltip(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  UIElement *v2; // ecx@1
  UIElement *v3; // ecx@4
  UIElement *v4; // ecx@6

  v1 = this;
  v2 = this->m_pTooltipElement;
  if ( v2 )
  {
    UIElement::AddToDeleteQueue(v2);
    v1->m_pTooltipElement = 0;
  }
  if ( v1->m_bHoverStarted )
  {
    v3 = v1->m_pElementLastEntered;
    v1->m_bHoverStarted = 0;
    if ( v3 )
      ((void (*)(void))v3->vfptr[7].OnLoseFocus)();
  }
  v4 = v1->m_pTooltipElement;
  if ( v4 )
  {
    UIElement::AddToDeleteQueue(v4);
    v1->m_pTooltipElement = 0;
  }
  UIElementManager::CheckTooltip(v1);
}

//----- (0045C3C0) --------------------------------------------------------  // acclient.c:152880
void __thiscall UIElementManager::RegisterActivatable(UIElementManager *this, UIElement *_element)
{
  char *v2; // ebx@1
  unsigned int v3; // ecx@1
  unsigned int v4; // eax@1
  int v5; // edx@2
  unsigned int v6; // ecx@7
  int v7; // edx@8
  int v8; // ecx@8
  int v9; // edi@8
  int v10; // ecx@8
  int v11; // eax@11
  unsigned int v12; // eax@12

  v2 = (char *)&this->m_activatableElements;
  v3 = this->m_activatableElements.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = *(_DWORD *)v2;
    while ( *(UIElement **)v5 != _element )
    {
      ++v4;
      v5 += 4;
      if ( v4 >= v3 )
        goto LABEL_11;
    }
    if ( v4 != -1 )
    {
      v6 = *((_DWORD *)v2 + 2);
      if ( v4 < v6 )
      {
        v7 = *(_DWORD *)v2;
        v8 = v6 - 1;
        *((_DWORD *)v2 + 2) = v8;
        v9 = v7 + 4 * v4;
        v10 = v7 + 4 * v8;
        if ( v9 < (unsigned int)v10 )
          qmemcpy((void *)v9, (const void *)(v9 + 4), 4 * (((unsigned int)(v10 - v9 - 1) >> 2) + 1));
        *(_DWORD *)(*(_DWORD *)v2 + 4 * *((_DWORD *)v2 + 2)) = 0;
      }
    }
  }
LABEL_11:
  v11 = *((_DWORD *)v2 + 1) & 0x7FFFFFFF;
  if ( *((_DWORD *)v2 + 2) < (unsigned int)v11
    || (v12 = SmartArray<UIChildFramework *,1>::get_new_size(v11 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v12)) )
    *(_DWORD *)(*(_DWORD *)v2 + 4 * (*((_DWORD *)v2 + 2))++) = _element;
}

//----- (0045C460) --------------------------------------------------------  // acclient.c:152932
void __thiscall UIElementManager::ActivationAlert(UIElementManager *this, UIElement *_element, bool _active)
{
  UIElementManager *v3; // esi@1
  UIElement *v4; // eax@2
  UIElement *v5; // ecx@6
  UIElement *v6; // ecx@8
  UIElement *v7; // eax@12

  v3 = this;
  if ( _element )
  {
    v4 = this->m_activeElement;
    if ( _active )
    {
      if ( _element != v4 )
      {
        if ( ICIDM::s_cidm )
          ((void (*)(void))ICIDM::s_cidm->vfptr->OnUIElementActivationChanging)();
        v5 = v3->m_activeElement;
        v3->m_activeElement = _element;
        if ( v5 )
          ((void (*)(void))v5->vfptr[21].OnAction)();
        v6 = v3->m_activeElement;
        if ( v6 )
        {
          ((void (__stdcall *)(signed int))v6->vfptr[14].OnLoseFocus)(2000);
          if ( !(unsigned __int8)((int (*)(void))v3->m_activeElement->vfptr[22].OnAction)() )
            UIElement::SetAttribute_Bool(v3->m_activeElement, 0x33u, 1);
        }
      }
    }
    else if ( v4 == _element )
    {
      v7 = this->m_focusElement;
      this->m_activeElement = 0;
      if ( v7 )
      {
        UIElementManager::BroadcastElementMessage(this, v7, 0x2Fu, 0, 0);
        ((void (*)(void))v3->m_focusElement->vfptr[15].__vecDelDtor)();
        v3->m_focusElement = 0;
      }
    }
  }
}

//----- (0045C530) --------------------------------------------------------  // acclient.c:152978
char __thiscall UIElementManager::RefreshEvent(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  unsigned int v2; // edi@2
  unsigned int v3; // eax@2
  IDClass<_tagDataID,32,0> v4; // edi@4
  char result; // al@4

  v1 = this;
  UIElementManager::BroadcastGlobalMessage(this, 5u, 0);
  if ( v1->m_pRootElement )
  {
    v2 = 800;
    v3 = 600;
    if ( RenderDevice::render_device )
    {
      v2 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
      v3 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
    }
    ((void (__stdcall *)(unsigned int, unsigned int))v1->m_pRootElement->vfptr[4].__vecDelDtor)(v2, v3);
    UIRegion::ForceUpdate((UIRegion *)&v1->m_pRootElement->vfptr, 7u);
    v4.id = v1->m_lastCursorDID.id;
    v1->m_lastCursorDID.id = INVALID_DID_52.id;
    UIElementManager::DrawDirtyRegions(v1);
    UIElementManager::SetCursor(v1, v4, v1->m_lastCursorHotX, v1->m_lastCursorHotY, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045C5C0) --------------------------------------------------------  // acclient.c:153013
char __thiscall IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::add(IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *this, HashSetData<unsigned long> *data)
{
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashSetData<unsigned long> *v4; // eax@1
  unsigned int v5; // edx@6
  HashSetData<unsigned long> **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashSetData<unsigned long> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashSetData<unsigned long> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0045C640) --------------------------------------------------------  // acclient.c:153057
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v9; // ebx@7
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v10; // ecx@7
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v11; // eax@9
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v12; // edx@10
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v6 )
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
            v3->m_firstInterestingBucket = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v8;
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
    if ( (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0045C780) --------------------------------------------------------  // acclient.c:153175
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v9; // ebx@7
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v10; // ecx@7
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v11; // eax@9
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v12; // edx@10
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v6 )
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
            v3->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v8;
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
    if ( (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0045C8C0) --------------------------------------------------------  // acclient.c:153293
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v9; // ebx@7
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v10; // ecx@7
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v11; // eax@9
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v12; // edx@10
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v17; // eax@23
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
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v6 )
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
            v3->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v8;
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
    if ( (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v3->m_buckets != v3->m_aInplaceBuckets )
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
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0045CA00) --------------------------------------------------------  // acclient.c:153411
void __cdecl _STL::__insertion_sort(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last)
{
  SurfaceUsageSummary *i; // esi@2
  _BYTE v3[24]; // ST08_24@3

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      *(_QWORD *)v3 = *(_QWORD *)&i->Bytes;
      InterlockedIncrement((volatile LONG *)((*(_QWORD *)&i->Bytes >> 32) - 16));
      *(_QWORD *)&v3[8] = *(_QWORD *)&i->ElementWidth;
      *(_QWORD *)&v3[16] = *(_QWORD *)&i->SurfaceWidth;
      _STL::__linear_insert(__first, i, *(SurfaceUsageSummary *)v3);
    }
  }
}

//----- (0045CA70) --------------------------------------------------------  // acclient.c:153430
void __cdecl _STL::__partial_sort(SurfaceUsageSummary *__first, SurfaceUsageSummary *__middle, SurfaceUsageSummary *__last, SurfaceUsageSummary *__formal, int __comp)
{
  SurfaceUsageSummary *v5; // ebx@1
  char *v6; // edi@2
  unsigned int v7; // edx@3
  int v8; // eax@5
  _BYTE v9[24]; // ST0C_24@6
  SurfaceUsageSummary *__lasta; // [sp+1Ch] [bp+Ch]@2

  v5 = __middle;
  _STL::__make_heap(__first, __middle, __comp);
  if ( __middle < __last )
  {
    v6 = (char *)&__middle->Name;
    __lasta = (SurfaceUsageSummary *)(((char *)__last - (char *)__middle - 1) / 0x18u + 1);
    do
    {
      v7 = *((_DWORD *)v6 - 1);
      if ( v7 < __first->Bytes
        || v7 == __first->Bytes
        && (v8 = strcmp(*(const char **)v6, __first->Name.m_charbuffer->m_data), v5 = __middle, v8 < 0) )
      {
        *(_DWORD *)v9 = *((_DWORD *)v6 - 1);
        *(_DWORD *)&v9[4] = *(_DWORD *)v6;
        InterlockedIncrement((volatile LONG *)(*(_DWORD *)v6 - 16));
        *(_QWORD *)&v9[8] = *(_QWORD *)(v6 + 4);
        *(_QWORD *)&v9[16] = *(_QWORD *)(v6 + 12);
        _STL::__pop_heap(__first, v5, (SurfaceUsageSummary *)(v6 - 4), *(SurfaceUsageSummary *)v9, __comp);
      }
      v6 += 24;
      __lasta = (SurfaceUsageSummary *)((char *)__lasta - 1);
    }
    while ( __lasta );
  }
  _STL::sort_heap(__first, v5, __comp);
}

//----- (0045CB70) --------------------------------------------------------  // acclient.c:153468
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateElement(UIElementManager *this, LayoutDesc *_layout, ElementDesc *_desc)
{
  HashSet<UIElement *>Vtbl *v3; // esi@1

  v3 = UIElementManager::CreateElementRecursiveFromPartialDesc(this, _layout, _desc);
  if ( v3 )
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *))v3->__vecDelDtor + 47))(v3);
  return v3;
}

//----- (0045CBA0) --------------------------------------------------------  // acclient.c:153479
void __cdecl UIElementManager::HandlePreferenceCallback(PStringBase<char> *_Name)
{
  UIElementManager *v1; // ebx@1

  v1 = UIElementManager::s_pInstance;
  if ( UIElementManager::s_pInstance )
  {
    if ( !__stricmp(_Name->m_charbuffer->m_data, Misc_TooltipDelay_2.m_charbuffer->m_data) )
    {
      UIElementManager::CheckTooltip(v1);
    }
    else if ( !__stricmp(_Name->m_charbuffer->m_data, Misc_TooltipEnable_2.m_charbuffer->m_data) )
    {
      UIElementManager::ResetTooltip(v1);
    }
  }
}

//----- (0045CC00) --------------------------------------------------------  // acclient.c:153498
void __thiscall UIElementManager::ActionHandler(UIElementManager *this, InputEvent *i_evt)
{
  UIElementManager *v2; // esi@1
  int v3; // edi@3
  UIElement *v4; // ecx@4

  v2 = this;
  if ( i_evt->m_fStart )
  {
    UIElementManager::KeyPressEvent(this, i_evt->m_InputAction, i_evt->m_InputExtent);
  }
  else
  {
    v3 = i_evt->m_InputAction;
    if ( !SceneTool::m_pDebugConsole->m_IsInputActive )
    {
      if ( (v4 = this->m_focusElement) == 0 && (v4 = v2->m_activeElement) == 0
        || !(unsigned __int8)((int (__stdcall *)(int))v4->vfptr[14].__vecDelDtor)(v3) )
        UIElementManager::BroadcastGlobalMessage(v2, 2u, v3);
    }
  }
}

//----- (0045CC60) --------------------------------------------------------  // acclient.c:153522
void __thiscall UIElementManager::DoMouseUpdate(UIElementManager *this)
{
  UIElementManager *v1; // edi@1
  CInputManager *v2; // esi@1
  int v3; // ebp@2
  int v4; // eax@2
  UIElement *v5; // ecx@2
  UIElement *v6; // edx@3
  UIElement *o_pRet; // [sp+0h] [bp-4h]@1

  o_pRet = (UIElement *)this;
  v1 = this;
  this->m_bPerformMouseHitTest = 0;
  v2 = ICIDM::s_cidm;
  if ( ICIDM::s_cidm )
  {
    v3 = ICIDM::s_cidm->vfptr->GetMouseX((ICIDM *)ICIDM::s_cidm);
    v4 = v2->vfptr->GetMouseY((ICIDM *)v2);
    v5 = 0;
    if ( !v1->m_bMouseHasLeftTheWindow )
    {
      v6 = v1->m_pRootElement;
      o_pRet = 0;
      MouseHitTester<MouseOverCriteria>::Recurse(v6, v3, v4, &o_pRet);
      v5 = o_pRet;
    }
    UIElementManager::SwitchMouseOver(v1, v5);
  }
}

//----- (0045CCC0) --------------------------------------------------------  // acclient.c:153553
char __cdecl RefreshEvent_g()
{
  char result; // al@2

  if ( UIElementManager::s_pInstance )
    result = UIElementManager::RefreshEvent(UIElementManager::s_pInstance);
  else
    result = 0;
  return result;
}

//----- (0045CCE0) --------------------------------------------------------  // acclient.c:153565
char __thiscall HashSet<unsigned long>::add(HashSet<unsigned long> *this, const unsigned int *_key)
{
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1> *v2; // esi@1
  HashSetData<unsigned long> *v3; // eax@1
  void *v4; // eax@4
  char result; // al@5

  v2 = &this->m_intrusiveTable;
  v3 = this->m_intrusiveTable.m_buckets[*_key % this->m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != *_key )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    v4 = operator new(8u);
    if ( v4 )
    {
      *(_DWORD *)v4 = *_key;
      *((_DWORD *)v4 + 1) = 0;
      IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::add(v2, (HashSetData<unsigned long> *)v4);
      result = 1;
    }
    else
    {
      IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::add(v2, 0);
      result = 1;
    }
  }
  return result;
}

//----- (0045CD50) --------------------------------------------------------  // acclient.c:153607
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this, HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0045CDD0) --------------------------------------------------------  // acclient.c:153651
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this, HashTableData<unsigned long,SmartArray<UIMessageData,1> > *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0045CE50) --------------------------------------------------------  // acclient.c:153695
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > **v5; // edx@5
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v6; // edi@5
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v7; // eax@7
  HashTableData<unsigned long,SmartArray<UIMessageData,1> > *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIMessageData,1> > **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      if ( (v6->m_data.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v6->m_data.m_data);
      operator delete(v6);
    }
  }
}

//----- (0045CEF0) --------------------------------------------------------  // acclient.c:153756
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *this, HashTableData<unsigned long,SmartArray<UIElement *,1> > *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v6; // eax@6
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
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0045CF70) --------------------------------------------------------  // acclient.c:153800
void __cdecl _STL::__final_insertion_sort(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last)
{
  if ( __last - __first <= 16 )
  {
    _STL::__insertion_sort(__first, __last);
  }
  else
  {
    _STL::__insertion_sort(__first, __first + 16);
    _STL::__unguarded_insertion_sort_aux(__first + 16, __last);
  }
}

//----- (0045CFD0) --------------------------------------------------------  // acclient.c:153814
void __usercall UIElementManager::UseTime(UIElementManager *this@<ecx>, signed int a2@<edi>)
{
  UIElementManager *v2; // esi@1
  UIElementManager *v3; // ecx@1

  v2 = this;
  UIElementManager::CleanDeleteQueue(this, a2);
  UIElementManager::ProcessUIMessageRemovalData(v2);
  if ( v2->m_bPerformMouseHitTest )
    UIElementManager::DoMouseUpdate(v3);
  UIElementManager::CheckTooltip(v2);
  UIElementManager::BroadcastGlobalMessage(v2, 3u, 0);
  if ( ICIDM::s_cidm )
    (*(void (**)(void))&ICIDM::s_cidm->vfptr->gap4[12])();
  UIElementManager::DrawDirtyRegions(v2);
}

//----- (0045D020) --------------------------------------------------------  // acclient.c:153832
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateRootElement(UIElementManager *this, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  HashSet<UIElement *>Vtbl *v3; // esi@1

  v3 = UIElementManager::CreateElementRecursiveFromPartialDesc(this, _layout, _full_desc);
  if ( v3 )
  {
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *))v3->__vecDelDtor + 47))(v3);
    UIElement::SetShouldOwnObject((UIElement *)v3, 1);
    UIElement::SetIsRootElement((UIElement *)v3, 1);
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *))v3->__vecDelDtor + 48))(v3);
    if ( UIElement::IsVisible((UIElement *)v3) )
      (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, signed int))v3->__vecDelDtor + 62))(v3, 1);
  }
  return v3;
}

//----- (0045D080) --------------------------------------------------------  // acclient.c:153850
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateChildElement(UIElementManager *this, UIElement *i_pParent, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  HashSet<UIElement *>Vtbl *v4; // esi@1

  v4 = UIElementManager::CreateElementRecursiveFromPartialDesc(this, _layout, _full_desc);
  if ( v4 )
  {
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *))v4->__vecDelDtor + 47))(v4);
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, UIElement *))v4->__vecDelDtor + 17))(v4, i_pParent);
    (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *))v4->__vecDelDtor + 48))(v4);
    if ( i_pParent )
    {
      if ( UIElement::IsVisible(i_pParent) )
        (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, signed int))v4->__vecDelDtor + 62))(v4, 1);
    }
  }
  return v4;
}

//----- (0045D0E0) --------------------------------------------------------  // acclient.c:153870
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateHollowElement(UIElementManager *this, UIElement *i_pParent)
{
  UIElementManager *v2; // esi@1
  unsigned int v3; // edi@1
  unsigned int v4; // ebx@1
  LayoutDesc *v5; // eax@4
  LayoutDesc *v6; // ebp@4
  LayoutDesc *v7; // eax@5
  ElementDesc *v8; // eax@9
  ElementDesc *v9; // ebp@9
  ElementDesc *v10; // eax@10
  ElementDesc *v11; // eax@12
  ElementDesc *v12; // eax@12
  LayoutDesc *v13; // ecx@13
  HashSet<UIElement *>Vtbl *result; // eax@15

  v2 = this;
  v3 = 800;
  v4 = 600;
  if ( RenderDevice::render_device )
  {
    v3 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
    v4 = RenderDevice::GetDisplayHeight(RenderDevice::render_device);
  }
  if ( !v2->m_pHollowLayoutDesc )
  {
    v5 = (LayoutDesc *)operator new(0xC0u);
    v6 = v5;
    if ( v5 )
    {
      LayoutDesc::LayoutDesc(v5);
      v6->vfptr = (InterfaceVtbl *)&NonDBObjLayoutDesc::vftable;
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    v2->m_pHollowLayoutDesc = v7;
    v7->m_displayWidth = v3;
    v2->m_pHollowLayoutDesc->m_displayHeight = v4;
  }
  if ( !v2->m_pHollowElementDesc )
  {
    v8 = (ElementDesc *)operator new(0x1C4u);
    v9 = v8;
    if ( v8 )
    {
      ElementDesc::ElementDesc(v8);
      v9->vfptr = (StateDescVtbl *)&ElementDesc::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    v2->m_pHollowElementDesc = v10;
    v10->m_elementID = 8;
    v2->m_pHollowElementDesc->m_type = 3;
    v11 = v2->m_pHollowElementDesc;
    v11->m_width = v3;
    v11->m_uiIncorporationFlags |= 8u;
    v12 = v2->m_pHollowElementDesc;
    v12->m_height = v4;
    v12->m_uiIncorporationFlags |= 0x10u;
    v2->m_pHollowElementDesc->m_leftEdge = 1;
    v2->m_pHollowElementDesc->m_rightEdge = 1;
    v2->m_pHollowElementDesc->m_topEdge = 1;
    v2->m_pHollowElementDesc->m_bottomEdge = 1;
  }
  v13 = v2->m_pHollowLayoutDesc;
  if ( v13 && v2->m_pHollowElementDesc )
    result = UIElementManager::CreateChildElement(v2, i_pParent, v13, v2->m_pHollowElementDesc);
  else
    result = 0;
  return result;
}
// 79BD34: using guessed type int (__thiscall *ElementDesc::vftable)(void *, char);
// 800AD0: using guessed type __int32 (__stdcall *NonDBObjLayoutDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0045D230) --------------------------------------------------------  // acclient.c:153951
void __thiscall UIElementManager::RegisterElementClass(UIElementManager *this, unsigned int _type, UIElement *(__cdecl *_createMethod)(LayoutDesc *, ElementDesc *))
{
  HashTable<unsigned long,RenderVertexStreamD3D *,0> *v3; // esi@3
  UIElement *(__cdecl *fnExisting)(LayoutDesc *, ElementDesc *); // [sp+0h] [bp-4h]@1

  fnExisting = (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))this;
  if ( _type && _createMethod )
  {
    v3 = (HashTable<unsigned long,RenderVertexStreamD3D *,0> *)&this->m_classCreateMethodTable;
    if ( !HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::find(
            (HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0> *)&this->m_classCreateMethodTable,
            (IDClass<_tagDataID,32,0> *)&_type,
            (SpellComponentRegion **)&fnExisting) )
      HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::add(
        v3,
        &_type,
        (RenderVertexStreamD3D *const *)&_createMethod);
  }
}

//----- (0045D270) --------------------------------------------------------  // acclient.c:153972
void __thiscall UIElementManager::SetMouseCapture(UIElementManager *this, UIElement *i_pElementToGetAllMouseMessages)
{
  UIElementManager *v2; // esi@1

  v2 = this;
  if ( this->m_pElementWithMouseCapture != i_pElementToGetAllMouseMessages )
  {
    this->m_nMouseCapture = 0;
    this->m_pElementWithMouseCapture = i_pElementToGetAllMouseMessages;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_setActionsTriggeringCapture.m_intrusiveTable);
  }
  if ( v2->m_pElementWithMouseCapture )
    ++v2->m_nMouseCapture;
}

//----- (0045D2B0) --------------------------------------------------------  // acclient.c:153988
void __thiscall UIElementManager::ReleaseMouseCapture(UIElementManager *this, UIElement *i_pElement)
{
  UIElementManager *v2; // esi@1
  UIElement *v3; // eax@1
  bool v4; // zf@3

  v2 = this;
  v3 = this->m_pElementWithMouseCapture;
  if ( v3 && v3 == i_pElement )
  {
    this->m_lastMouseMoveTime = Timer::local_time;
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_setActionsTriggeringCapture.m_intrusiveTable);
    v4 = v2->m_nMouseCapture-- == 1;
    if ( v4 )
      v2->m_pElementWithMouseCapture = 0;
  }
}

//----- (0045D300) --------------------------------------------------------  // acclient.c:154007
char __thiscall HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::add(HashTable<unsigned long,SmartArray<UIMessageData,1>,1> *this, const unsigned int *_key, SmartArray<UIMessageData,1> *_data)
{
  HashTable<unsigned long,SmartArray<UIMessageData,1>,1> *v3; // ebx@1
  void *v4; // esi@1
  int v5; // ecx@2
  char result; // al@9

  v3 = this;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    v5 = (int)((char *)v4 + 8);
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    SmartArray<UIMessageData,1>::operator=((SmartArray<LOAD_WEIGHTS,1> *)((char *)v4 + 8), (int)_data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,SmartArray<UIMessageData,1> > *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      if ( (*((_DWORD *)v4 + 3) & 0x80000000) == 0x80000000 )
        operator delete[](*((void **)v4 + 2));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (0045D390) --------------------------------------------------------  // acclient.c:154050
char __thiscall HashTable<unsigned long,SmartArray<UIElement *,1>,1>::add(HashTable<unsigned long,SmartArray<UIElement *,1>,1> *this, const unsigned int *_key, SmartArray<UIElement *,1> *_data)
{
  HashTable<unsigned long,SmartArray<UIElement *,1>,1> *v3; // ebx@1
  void *v4; // esi@1
  int v5; // ecx@2
  char result; // al@9

  v3 = this;
  v4 = operator new(0x14u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    v5 = (int)((char *)v4 + 8);
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    *(_DWORD *)(v5 + 8) = 0;
    SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)((char *)v4 + 8), (int)_data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,SmartArray<UIElement *,1> > *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      if ( (*((_DWORD *)v4 + 3) & 0x80000000) == 0x80000000 )
        operator delete[](*((void **)v4 + 2));
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (0045D420) --------------------------------------------------------  // acclient.c:154093
AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1> > *__thiscall HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor(AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1> > *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1> > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,SmartArray<UIElement *,1>,1>Vtbl *)AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable;
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
// 79BD64: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable[7])(void *, char);
// 79BD78: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable[2])(void *, char);

//----- (0045D480) --------------------------------------------------------  // acclient.c:154119
HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0> *__thiscall HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor(HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0> *this, unsigned int a2)
{
  HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0>Vtbl *)HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable;
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
// 79BD68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable[6])(void *, char);
// 79BD70: using guessed type int (__thiscall *HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable[4])(void *, char);

//----- (0045D4E0) --------------------------------------------------------  // acclient.c:154145
HashSet<unsigned long> *__thiscall HashSet<unsigned long>::vector_deleting_destructor(HashSet<unsigned long> *this, unsigned int a2)
{
  HashSet<unsigned long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
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
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);

//----- (0045D540) --------------------------------------------------------  // acclient.c:154171
int __thiscall HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::operator=(int this, unsigned int __val)
{
  unsigned int v2; // edi@1
  int v3; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *v4; // esi@2
  unsigned int *v5; // ebp@2
  unsigned int *v6; // eax@2
  void *v7; // ebp@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v8; // eax@4
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edi@4
  void *v10; // eax@5
  void *v11; // esi@5
  int v12; // ecx@6
  unsigned int v13; // ebx@8
  int v14; // ecx@8
  int v15; // edx@9
  int v16; // eax@12
  HashTableData<unsigned long,HeritageGroup_CG> **v17; // ecx@16
  HashTableData<unsigned long,HeritageGroup_CG> **v18; // eax@17
  int v19; // [sp+4h] [bp-1Ch]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+8h] [bp-18h]@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v21; // [sp+14h] [bp-Ch]@4

  v2 = __val;
  v3 = this;
  v19 = this;
  if ( this == __val )
    return v3;
  v4 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)(this + 4);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)(this + 4));
  v5 = g_bucketSizesEnd;
  __val = *(_DWORD *)(v2 + 108);
  v6 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v6 == v5 )
    --v6;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::resize_internal(
    v4,
    *v6);
  v7 = 0;
  v8 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(v2 + 4),
         &result);
  v9 = v8->m_currElement;
  v21 = v8->m_currHashTable;
  result.m_currBucket = v8->m_currBucket;
  if ( !v9 )
    return v19;
  do
  {
LABEL_5:
    v10 = operator new(0x14u);
    v11 = v10;
    if ( v10 )
    {
      v12 = (int)((char *)v10 + 8);
      *(_DWORD *)v10 = v9->m_hashKey;
      *((_DWORD *)v10 + 1) = 0;
      *(_DWORD *)v12 = 0;
      *(_DWORD *)(v12 + 4) = 0;
      *(_DWORD *)(v12 + 8) = 0;
      SmartArray<UIMessageData,1>::operator=((SmartArray<LOAD_WEIGHTS,1> *)((char *)v10 + 8), (int)&v9->m_data);
    }
    else
    {
      v11 = 0;
    }
    v13 = *(_DWORD *)(v19 + 108);
    v14 = *(_DWORD *)v11 % v13;
    if ( !v7 )
      goto LABEL_12;
    v15 = *(_DWORD *)v7 % v13;
    if ( v14 != v15 )
    {
      if ( v14 <= (unsigned int)v15 )
        goto LABEL_15;
LABEL_12:
      v16 = *(_DWORD *)(v19 + 100) + 4 * v14;
      *(_DWORD *)v16 = v11;
      if ( !v7 )
        *(_DWORD *)(v19 + 104) = v16;
      goto LABEL_14;
    }
    *((_DWORD *)v7 + 1) = v11;
LABEL_14:
    ++*(_DWORD *)(v19 + 112);
LABEL_15:
    v9 = v9->m_hashNext;
    v7 = v11;
  }
  while ( v9 );
  v17 = &v21->m_buckets[v21->m_numBuckets];
  while ( 1 )
  {
    v18 = result.m_currBucket + 1;
    ++result.m_currBucket;
    if ( result.m_currBucket == v17 )
      return v19;
    if ( *v18 )
    {
      v9 = *v18;
      if ( *v18 )
        goto LABEL_5;
      return v19;
    }
  }
}

//----- (0045D690) --------------------------------------------------------  // acclient.c:154279
void __cdecl _STL::__introsort_loop(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last, SurfaceUsageSummary *__formal, int __depth_limit, int __comp)
{
  SurfaceUsageSummary *v5; // ebx@1
  SurfaceUsageSummary *v6; // esi@3
  _BYTE v7[24]; // ST1C_24@3
  SurfaceUsageSummary *v8; // esi@3

  v5 = __last;
  if ( __last - __first > 16 )
  {
    while ( __depth_limit )
    {
      --__depth_limit;
      v6 = _STL::__median(__first, &__first[(v5 - __first) / 2], v5 - 1);
      *(_QWORD *)v7 = *(_QWORD *)&v6->Bytes;
      InterlockedIncrement((volatile LONG *)((*(_QWORD *)&v6->Bytes >> 32) - 16));
      *(_QWORD *)&v7[8] = *(_QWORD *)&v6->ElementWidth;
      *(_QWORD *)&v7[16] = *(_QWORD *)&v6->SurfaceWidth;
      v8 = _STL::__unguarded_partition(__first, v5, *(SurfaceUsageSummary *)v7);
      _STL::__introsort_loop(v8, v5, 0, __depth_limit, (_STL::less<SurfaceUsageSummary>)__comp);
      v5 = v8;
      if ( v8 - __first <= 16 )
        return;
    }
    _STL::__partial_sort(__first, v5, v5, 0, __comp);
  }
}

//----- (0045D7A0) --------------------------------------------------------  // acclient.c:154308
ElementDesc *__thiscall UIElementManager::CreateRootElement(UIElementManager *this, LayoutDesc *_layout, unsigned int _elementID)
{
  UIElementManager *v3; // esi@1
  ElementDesc *result; // eax@1

  v3 = this;
  result = LayoutDesc::AccessElementDesc(_layout, _elementID);
  if ( result )
    result = (ElementDesc *)UIElementManager::CreateRootElement(v3, _layout, result);
  return result;
}

//----- (0045D7D0) --------------------------------------------------------  // acclient.c:154321
ElementDesc *__thiscall UIElementManager::CreateChildElement(UIElementManager *this, UIElement *i_pParent, LayoutDesc *i_layout, unsigned int i_elementID)
{
  UIElementManager *v4; // esi@1
  ElementDesc *result; // eax@1

  v4 = this;
  result = LayoutDesc::AccessElementDesc(i_layout, i_elementID);
  if ( result )
    result = (ElementDesc *)UIElementManager::CreateChildElement(v4, i_pParent, i_layout, result);
  return result;
}

//----- (0045D800) --------------------------------------------------------  // acclient.c:154334
void __thiscall UIElementManager::RegisterElementForInputAction(UIElementManager *this, unsigned int i_eInputAction, UIElement *i_pElement)
{
  HashTable<unsigned long,SmartArray<UIElement *,1>,1> *v3; // esi@3
  SmartArray<UIElement *,1> *v4; // eax@3
  SmartArray<UIElement *,1> elementArray; // [sp+0h] [bp-Ch]@4

  if ( i_eInputAction && i_pElement )
  {
    v3 = (HashTable<unsigned long,SmartArray<UIElement *,1>,1> *)&this->m_elementInputActionListenerTable.vfptr;
    v4 = (SmartArray<UIElement *,1> *)HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                                        (HashTable<unsigned long,unsigned long,0> *)&this->m_elementInputActionListenerTable,
                                        &i_eInputAction);
    if ( v4 )
    {
      SmartArray<QualityChangeHandler *,1>::add_unique(v4, &i_pElement);
    }
    else
    {
      elementArray.m_data = 0;
      elementArray.m_sizeAndDeallocate = 0;
      elementArray.m_num = 0;
      SmartArray<UIElement_Button *,1>::AddToEnd(
        (SmartArray<BSPNODE *,1> *)&elementArray,
        (BSPNODE *const *)&i_pElement);
      HashTable<unsigned long,SmartArray<UIElement *,1>,1>::add(v3, &i_eInputAction, &elementArray);
      if ( (elementArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](elementArray.m_data);
    }
  }
}

//----- (0045D890) --------------------------------------------------------  // acclient.c:154366
void __thiscall UIElementManager::UnRegisterElementForAllInputActions(UIElementManager *this, UIElement *i_pElement)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,SmartArray<UIElement *,1> > *v3; // edi@1
  HashTableData<unsigned long,SmartArray<UIElement *,1> > **v4; // ebp@1
  UIElement **v5; // ebx@2
  unsigned int v6; // edx@2
  unsigned int v7; // ecx@2
  UIElement **v8; // eax@2
  unsigned int v9; // eax@8
  unsigned int v10; // edx@9
  int v11; // ST18_4@14
  unsigned int v17; // eax@17
  unsigned int i; // ebp@24
  unsigned int v19; // ebx@25
  int v20; // eax@25
  int v21; // esi@25
  int v22; // edx@31
  UIElementManager *v23; // [sp+10h] [bp-2Ch]@1
  SmartArray<unsigned long,1> aEmptyHashesToRemove; // [sp+18h] [bp-24h]@1
  SmartArray<UIElement *,1> elementArray; // [sp+24h] [bp-18h]@1
  HashIterator<unsigned long,SmartArray<UIElement *,1>,1> actionIter; // [sp+30h] [bp-Ch]@1

  v23 = this;
  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_elementInputActionListenerTable.m_intrusiveTable,
         (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&elementArray);
  v3 = (HashTableData<unsigned long,SmartArray<UIElement *,1> > *)v2->m_currElement;
  v4 = (HashTableData<unsigned long,SmartArray<UIElement *,1> > **)v2->m_currBucket;
  actionIter.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1> > *,1> *)v2->m_currHashTable;
  aEmptyHashesToRemove.m_data = 0;
  aEmptyHashesToRemove.m_sizeAndDeallocate = 0;
  aEmptyHashesToRemove.m_num = 0;
  if ( v3 )
  {
    do
    {
LABEL_2:
      elementArray.m_data = 0;
      elementArray.m_sizeAndDeallocate = 0;
      elementArray.m_num = 0;
      SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)&elementArray, (int)&v3->m_data);
      v5 = elementArray.m_data;
      v6 = elementArray.m_num;
      v7 = (unsigned int)&elementArray.m_data[elementArray.m_num];
      v8 = elementArray.m_data;
      if ( (unsigned int)elementArray.m_data < v7 )
      {
        while ( *v8 != i_pElement )
        {
          ++v8;
          if ( (unsigned int)v8 >= v7 )
            goto LABEL_7;
        }
        v6 = elementArray.m_num - 1;
        *v8 = elementArray.m_data[elementArray.m_num - 1];
        v5[v6] = 0;
      }
LABEL_7:
      if ( !v6 )
      {
        v9 = aEmptyHashesToRemove.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( aEmptyHashesToRemove.m_num < (aEmptyHashesToRemove.m_sizeAndDeallocate & 0x7FFFFFFF) )
          goto LABEL_43;
        v10 = v9 + 1;
        if ( v9 + 1 > 8 )
        {
          if ( v10 <= 0x4000 )
          {
            v11 = v9 + 1;
            __asm { bsr     this, [esp+3Ch+var_28] }
            if ( v10 > 1 << _EAX )
              v10 = 2 * (1 << _EAX);
          }
          else if ( v10 & 0x3FFF )
          {
            v10 += 0x4000 - (v10 & 0x3FFF);
          }
        }
        else
        {
          v10 = 8;
        }
        if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&aEmptyHashesToRemove, v10) )
        {
LABEL_43:
          v17 = aEmptyHashesToRemove.m_num;
          aEmptyHashesToRemove.m_data[aEmptyHashesToRemove.m_num] = v3->m_hashKey;
          aEmptyHashesToRemove.m_num = v17 + 1;
        }
      }
      if ( (elementArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v5);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &actionIter.m_iter.m_currHashTable->m_buckets[actionIter.m_iter.m_currHashTable->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_2;
        break;
      }
    }
  }
  for ( i = 0; i < aEmptyHashesToRemove.m_num; ++i )
  {
    v19 = (unsigned int)&v23->m_elementInputActionListenerTable.m_intrusiveTable.m_buckets[aEmptyHashesToRemove.m_data[i]
                                                                                         % v23->m_elementInputActionListenerTable.m_intrusiveTable.m_numBuckets];
    v20 = *(_DWORD *)v19;
    v21 = *(_DWORD *)v19;
    if ( *(_DWORD *)v19 )
    {
      while ( *(_DWORD *)v21 != aEmptyHashesToRemove.m_data[i] )
      {
        v21 = *(_DWORD *)(v21 + 4);
        if ( !v21 )
          goto LABEL_38;
      }
      if ( v21 )
      {
        if ( v20 == v21 )
          goto LABEL_44;
        do
        {
          v22 = v20;
          v20 = *(_DWORD *)(v20 + 4);
        }
        while ( v20 != v21 );
        if ( v22 )
          *(_DWORD *)(v22 + 4) = *(_DWORD *)(v20 + 4);
        else
LABEL_44:
          *(_DWORD *)v19 = *(_DWORD *)(v20 + 4);
        --v23->m_elementInputActionListenerTable.m_intrusiveTable.m_numElements;
        if ( (*(_DWORD *)(v21 + 12) & 0x80000000) == 0x80000000 )
          operator delete[](*(void **)(v21 + 8));
        operator delete((void *)v21);
      }
    }
LABEL_38:
    ;
  }
  if ( (aEmptyHashesToRemove.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](aEmptyHashesToRemove.m_data);
}

//----- (0045DAC0) --------------------------------------------------------  // acclient.c:154519
void __stdcall UIElementManager::RegisterForMessageInternal(UIListener *_pListener, AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *_pTable, unsigned int _messageID)
{
  unsigned int *v4; // eax@3
  unsigned int v5; // ecx@5
  unsigned int v6; // edx@5
  unsigned int v7; // esi@6
  UIMessageData data; // [sp+4h] [bp-Ch]@4
  int v9; // [sp+Ch] [bp-4h]@4

  if ( _pListener )
  {
    if ( _pTable )
    {
      v4 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
             (HashTable<unsigned long,unsigned long,0> *)_pTable,
             &_messageID);
      if ( v4
        || (data.pListener = 0,
            data.nCount = 0,
            v9 = 0,
            HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::add(
              (HashTable<unsigned long,SmartArray<UIMessageData,1>,1> *)&_pTable->vfptr,
              &_messageID,
              (SmartArray<UIMessageData,1> *)&data),
            (v4 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
                    (HashTable<unsigned long,unsigned long,0> *)_pTable,
                    &_messageID)) != 0) )
      {
        v5 = v4[2];
        v6 = 0;
        if ( v5 )
        {
          v7 = *v4;
          while ( *(UIListener **)v7 != _pListener )
          {
            ++v6;
            v7 += 8;
            if ( v6 >= v5 )
              goto LABEL_9;
          }
          ++*(_DWORD *)(v7 + 4);
        }
        else
        {
LABEL_9:
          data.pListener = _pListener;
          data.nCount = 1;
          SmartArray<UIMessageRemovalData,1>::add((SmartArray<UIMessageData,1> *)v4, &data);
        }
      }
    }
  }
}

//----- (0045DB60) --------------------------------------------------------  // acclient.c:154574
void __thiscall UIElementManager::MouseDownEvent(UIElementManager *this, unsigned int _action, float _extent)
{
  UIElementManager *v3; // esi@1
  int v4; // ebp@2
  int v5; // ebx@2
  UIElement *v6; // eax@4
  UIElement *v7; // ecx@5
  unsigned int v8; // edi@6
  UIElement *v9; // eax@14
  UIElement *v10; // ecx@19
  UIElement *v11; // eax@20
  UIElement *v12; // edi@20
  UIRegion *v13; // ecx@26
  UIElement *v14; // ecx@29
  UIElement *v15; // ecx@31
  UIRegion *v16; // ecx@36
  UIElement *v17; // ecx@38
  bool bIsTapAction; // [sp+7h] [bp-5h]@8
  UIElement *o_pRet; // [sp+8h] [bp-4h]@5

  v3 = this;
  if ( ICIDM::s_cidm )
  {
    v4 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
    v5 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
    if ( UIRegion::PointIsOverRegion((UIRegion *)&v3->m_pRootElement->vfptr, v4, v5) )
      v3->m_bMouseHasLeftTheWindow = 0;
    v6 = 0;
    if ( !v3->m_bMouseHasLeftTheWindow )
    {
      v7 = v3->m_pRootElement;
      o_pRet = 0;
      MouseHitTester<MouseOverCriteria>::Recurse(v7, v4, v5, &o_pRet);
      v6 = o_pRet;
    }
    UIElementManager::SwitchMouseOver(v3, v6);
    v8 = _action;
    if ( _action == 13 || _action == 15 || (bIsTapAction = 0, _action == 14) )
      bIsTapAction = 1;
    if ( !v3->m_bDragStarted && _action == 7 )
    {
      UIElementManager::ClearDragandDrop(v3);
      v3->m_dragX = v4;
      v3->m_dragY = v5;
    }
    if ( v3->m_pElementWithMouseCapture )
    {
      if ( v3->m_setActionsTriggeringCapture.m_intrusiveTable.m_numElements )
      {
        if ( bIsTapAction )
          goto LABEL_26;
        HashSet<unsigned long>::add(&v3->m_setActionsTriggeringCapture, &_action);
        goto LABEL_36;
      }
    }
    else
    {
      v9 = v3->m_pElementLastEntered;
      if ( v9 )
      {
        if ( !bIsTapAction )
        {
          UIElementManager::SetMouseCapture(v3, v9);
          HashSet<unsigned long>::add(&v3->m_setActionsTriggeringCapture, &_action);
          if ( !v3->m_bDragStarted && v8 == 7 )
            v3->m_pcPotentialDragElement = v3->m_pElementLastEntered;
        }
      }
      v10 = v3->m_pElementLastOver;
      if ( v10 )
      {
        v11 = UIElement::GetRootElement(v10);
        v12 = v11;
        if ( v11 != v3->m_activeElement )
        {
          if ( v11 && (unsigned __int8)((int (__thiscall *)(UIElement *))v11->vfptr[22].OnAction)(v11) )
          {
            ((void (__thiscall *)(UIElement *))v12->vfptr[21].__vecDelDtor)(v12);
          }
          else
          {
            v14 = v3->m_activeElement;
            if ( v14 )
              ((void (*)(void))v14->vfptr[21].OnAction)();
          }
        }
        v8 = _action;
      }
      else
      {
        v15 = v3->m_activeElement;
        if ( v15 )
          ((void (*)(void))v15->vfptr[21].OnAction)();
      }
    }
    if ( bIsTapAction )
    {
LABEL_26:
      v13 = (UIRegion *)&v3->m_pElementWithMouseCapture->vfptr;
      if ( v13 || (v13 = (UIRegion *)&v3->m_pElementLastEntered->vfptr) != 0 )
      {
        UIRegion::NotifyMouseTap(v13, v4, v5, v8);
        return;
      }
LABEL_38:
      v17 = v3->m_focusElement;
      if ( v17 )
        ((void (*)(void))v17->vfptr[22].__vecDelDtor)();
      return;
    }
LABEL_36:
    v16 = (UIRegion *)&v3->m_pElementWithMouseCapture->vfptr;
    if ( v16 )
    {
      UIRegion::NotifyMouseDown(v16, v4, v5, v8);
      return;
    }
    goto LABEL_38;
  }
}

//----- (0045DD50) --------------------------------------------------------  // acclient.c:154696
void __thiscall UIElementManager::MouseUpEvent(UIElementManager *this, unsigned int _action, IInputActionCallback *i_pcCallback)
{
  UIElementManager *v3; // esi@1
  int v4; // edi@2
  int v5; // ebp@2
  UIRegion *v6; // ebx@4
  HashSetData<IDClass<_tagDataID,32,0> > *v7; // eax@6
  UIElement *v8; // eax@9
  UIRegion *v9; // ecx@16
  UIElement *o_pRet; // [sp+0h] [bp-4h]@1

  o_pRet = (UIElement *)this;
  v3 = this;
  if ( ICIDM::s_cidm )
  {
    v4 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseX)();
    v5 = ((int (*)(void))ICIDM::s_cidm->vfptr->GetMouseY)();
    if ( UIRegion::PointIsOverRegion((UIRegion *)&v3->m_pRootElement->vfptr, v4, v5) )
      v3->m_bMouseHasLeftTheWindow = 0;
    v6 = (UIRegion *)&v3->m_pElementLastEntered->vfptr;
    if ( v3->m_pElementWithMouseCapture )
    {
      v6 = (UIRegion *)&v3->m_pElementWithMouseCapture->vfptr;
      if ( v3->m_setActionsTriggeringCapture.m_intrusiveTable.m_numElements )
      {
        v7 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
               (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&v3->m_setActionsTriggeringCapture.m_intrusiveTable,
               (IDClass<_tagDataID,32,0> *)&_action);
        if ( v7 )
        {
          operator delete(v7);
          if ( !v3->m_setActionsTriggeringCapture.m_intrusiveTable.m_numElements )
            UIElementManager::ReleaseMouseCapture(v3, v3->m_pElementWithMouseCapture);
        }
      }
    }
    v8 = 0;
    if ( !v3->m_bMouseHasLeftTheWindow )
    {
      o_pRet = 0;
      MouseHitTester<MouseOverCriteria>::Recurse(v3->m_pRootElement, v4, v5, &o_pRet);
      v8 = o_pRet;
    }
    UIElementManager::SwitchMouseOver(v3, v8);
    if ( _action == 7 )
    {
      if ( v3->m_bDragStarted )
      {
        if ( v3->m_dragElement )
        {
          v6 = 0;
          if ( v3->m_pElementWithMouseCapture )
          {
            UIElementManager::ReleaseMouseCapture(v3, v3->m_pElementWithMouseCapture);
            UIElementManager::SwitchMouseOver(v3, v3->m_pElementLastOver);
          }
          v9 = (UIRegion *)&v3->m_dragOwner->vfptr;
          if ( v9 )
            UIRegion::NotifyMouseUp(v9, v4, v5, 7u);
        }
        UIElementManager::StopDragandDrop(v3);
      }
      v3->m_pcPotentialDragElement = 0;
    }
    if ( v6 )
      UIRegion::NotifyMouseUp(v6, v4, v5, _action);
  }
}

//----- (0045DE90) --------------------------------------------------------  // acclient.c:154766
void __userpurge UIElementManager::StartTooltip(UIElementManager *this@<ecx>, int a2@<ebx>, StringInfo *i_siToolTip, UIElement *i_pElementOwner, unsigned int i_idToolTip, IDClass<_tagDataID,32,0> i_idTooltipLayout, unsigned int i_idToolTipText)
{
  UIElementManager *v7; // esi@1
  UIElement *v8; // ecx@1
  UIElement *v9; // edi@3
  StringInfo *v10; // ebx@4
  unsigned int v11; // ST0C_4@5
  StringInfo *v12; // edi@5
  ElementDesc *v13; // eax@6
  HashSet<UIElement *>Vtbl *v14; // esi@7
  UIElement *v15; // eax@11
  UIElement_Text *v16; // eax@12
  UIElement_Text *v17; // edi@12
  int v18; // eax@13
  int v19; // ebp@13
  int v20; // ebx@13
  int v21; // eax@13
  int v22; // ebp@13
  int v23; // eax@13
  int v24; // ebx@13
  int v25; // ebx@14
  int v26; // ebx@14
  int v27; // ebp@14
  int v28; // [sp-4h] [bp-20h]@4
  unsigned int textID; // [sp+Ch] [bp-10h]@9
  int iRequiredTextWidth; // [sp+10h] [bp-Ch]@13
  int iRequiredTextHeight; // [sp+14h] [bp-8h]@13
  UIElementManager *v32; // [sp+18h] [bp-4h]@1

  v7 = this;
  v8 = this->m_pTooltipElement;
  v32 = v7;
  if ( v8 )
  {
    UIElement::AddToDeleteQueue(v8);
    v7->m_pTooltipElement = 0;
  }
  v9 = i_pElementOwner;
  if ( i_pElementOwner )
  {
    v28 = a2;
    v10 = i_siToolTip;
    if ( StringInfo::IsValid(i_siToolTip, 1) )
    {
      v11 = i_idTooltipLayout.id;
      v7->m_pTooltipOwner = v9;
      i_siToolTip = 0;
      DBObjGrabber<LayoutDesc>::set((DBObjGrabber<LayoutDesc> *)&i_siToolTip, (IDClass<_tagDataID,32,0>)v11);
      v12 = i_siToolTip;
      if ( i_siToolTip )
      {
        v13 = LayoutDesc::AccessElementDesc((LayoutDesc *)i_siToolTip, i_idToolTip);
        if ( v13 && (v14 = UIElementManager::CreateRootElement(v7, (LayoutDesc *)v12, v13)) != 0 )
        {
          textID = i_idToolTipText;
          if ( i_idToolTipText || UIElement::GetAttribute_Enum((UIElement *)v14, 0x4Au, &textID) )
          {
            v15 = UIElement::GetChildRecursive((UIElement *)v14, textID);
            if ( v15 )
            {
              v16 = (UIElement_Text *)v15->vfptr[12].OnAction((IInputActionCallback *)v15, (InputEvent *)12);
              v17 = v16;
              if ( v16 )
              {
                UIElement_Text::SetStringInfo(v16, v10);
                UIElement_Text::InqSizewMargins(v17, v10, &iRequiredTextWidth, &iRequiredTextHeight, 0);
                v18 = UIRegion::GetWidth((UIRegion *)&v17->vfptr);
                v19 = iRequiredTextWidth - v18;
                v20 = v19 + UIRegion::GetWidth((UIRegion *)v14);
                v21 = UIRegion::GetHeight((UIRegion *)&v17->vfptr);
                v22 = iRequiredTextHeight - v21;
                v23 = UIRegion::GetHeight((UIRegion *)v14);
                (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, int, int, _DWORD))v14->__vecDelDtor + 12))(
                  v14,
                  v20,
                  v22 + v23,
                  v28);
                UIElement_Text::RecalculateGlyphList(v17);
                i_idToolTipText = UIRegion::GetWidth((UIRegion *)v14);
                UIRegion::GetHeight((UIRegion *)v14);
                v24 = v17->m_iScrollableHeight;
                if ( v24 > UIRegion::GetHeight((UIRegion *)&v17->vfptr) )
                {
                  v25 = v17->m_iScrollableHeight;
                  v26 = v25 - UIRegion::GetHeight((UIRegion *)&v17->vfptr);
                  v27 = UIRegion::GetHeight((UIRegion *)v14) + v26;
                }
                (*((void (__thiscall **)(HashSet<UIElement *>Vtbl *, unsigned int))v14->__vecDelDtor + 12))(
                  v14,
                  i_idToolTipText);
                UIElementManager::StartTooltip(v32, i_pElementOwner, (UIElement *)v14);
              }
            }
          }
          DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>((DBObjGrabber<ACCharGenData> *)&i_siToolTip);
        }
        else
        {
          (*(void (__thiscall **)(StringInfo *))&v12->m_strToken.m_charbuffer[1].m_data[4])(v12);
        }
      }
    }
  }
}
// 45DE90: could not find valid save-restore pair for ebx

//----- (0045E040) --------------------------------------------------------  // acclient.c:154873
char __thiscall UIElementManager::StartDragandDrop(UIElementManager *this, UIElement *_elem, int i_iClickX, int i_iClickY)
{
  UIElement *v4; // edi@1
  UIElementManager *v5; // esi@1
  CInputManager *v6; // ebx@3
  int v7; // ebp@9
  int v8; // ebx@9
  int v9; // eax@9
  int v10; // ecx@9
  bool v11; // dl@9
  IInputActionCallbackVtbl *v12; // eax@11
  UIElement *v13; // eax@12
  UIElement *v15; // eax@16
  UIRegion *v16; // ebx@20
  UIObject *v17; // eax@21
  UIElement *v18; // ecx@21
  UIElement *v19; // eax@21
  UIElement *newElem; // [sp+10h] [bp-34h]@16
  int mouse_y; // [sp+14h] [bp-30h]@9
  UIElement *newOwner; // [sp+18h] [bp-2Ch]@16
  UIElementMessageInfo msg; // [sp+1Ch] [bp-28h]@14

  v4 = _elem;
  v5 = this;
  if ( !_elem )
    return 0;
  if ( !RenderDevice::render_device )
    return 0;
  v6 = ICIDM::s_cidm;
  if ( !ICIDM::s_cidm )
    return 0;
  if ( !CInputManager::IsActionInProgress(ICIDM::s_cidm, 7u) )
    return 0;
  if ( v5->m_dragX < 0 )
    return 0;
  if ( v5->m_dragY < 0 )
    return 0;
  if ( v5->m_dragX > (signed int)RenderDevice::GetDisplayWidth(RenderDevice::render_device) )
    return 0;
  if ( v5->m_dragY > (signed int)RenderDevice::GetDisplayHeight(RenderDevice::render_device) )
    return 0;
  v7 = v6->vfptr->GetMouseX((ICIDM *)v6);
  v8 = v6->vfptr->GetMouseY((ICIDM *)v6);
  v9 = v7 - v5->m_dragX;
  v10 = v8 - v5->m_dragY;
  v11 = v5->m_bDragStarted;
  mouse_y = v8;
  if ( !v11 && (unsigned int)(v9 * v9 + v10 * v10) < 0x10 )
    return 0;
  UIElementManager::ClearDragandDrop(v5);
  v5->m_bDragStarted = 1;
  LOBYTE(_elem) = 0;
  UIElement::GetAttribute_Bool(v4, 0x3Au, (bool *)&_elem);
  v12 = v4->vfptr;
  if ( (_BYTE)_elem )
  {
    newElem = v4;
    v15 = (UIElement *)((int (__thiscall *)(UIElement *))v12[13].OnAction)(v4);
    newOwner = v15;
    if ( v15 && !v15->vfptr[19].OnAction((IInputActionCallback *)v15, (InputEvent *)&newElem) )
      return 0;
    if ( !newElem )
      return 0;
    if ( v4 == newElem )
      return 0;
    UIElement::SetObjectIsTemporary(newElem, 1);
    UIElement::SetShouldOwnObject(newElem, 1);
    ((void (__stdcall *)(_DWORD))newElem->vfptr[22].OnLoseFocus)(0);
    UIElement::SetIsRootElement(newElem, 1);
    ((void (__stdcall *)(_DWORD, _DWORD))newElem->vfptr[3].OnLoseFocus)(v7 - i_iClickX, v8 - i_iClickY);
    UIElement::BringChildToTop(v5->m_pRootElement, newElem);
    v16 = (UIRegion *)newElem;
    if ( !UIRegion::GetObjectA((UIRegion *)&newElem->vfptr) )
      return 0;
    v5->m_dragY = mouse_y;
    v5->m_dragX = v7;
    v5->m_dragBaseX = UIRegion::GetObjectA(v16)->m_nVirtualX;
    v17 = UIRegion::GetObjectA(v16);
    v18 = newOwner;
    v5->m_dragBaseY = v17->m_nVirtualY;
    v19 = v5->m_pElementWithMouseCapture;
    v5->m_dragElement = (UIElement *)v16;
    v5->m_dragOwner = v18;
    if ( v19 == v4 )
    {
      UIElementManager::ReleaseMouseCapture(v5, v19);
      UIElementManager::SetMouseCapture(v5, v5->m_dragElement);
    }
    UIElementManager::UpdateMouseOver(v5, v7, mouse_y);
  }
  else
  {
    v13 = (UIElement *)((int (__thiscall *)(UIElement *))v12[13].OnAction)(v4);
    if ( !v13 || !UIElementManager::StartDragandDrop(v5, v13, i_iClickX + v4->m_box.m_x0, i_iClickY + v4->m_box.m_y0) )
    {
      UIElementMessageInfo::UIElementMessageInfo(
        &msg,
        v4->m_desc.m_elementID,
        v4,
        0x21u,
        0,
        0,
        v5->m_dragX,
        v5->m_dragY,
        0,
        0);
      UIElementManager::BroadcastElementMessage(v5, &msg);
      return 0;
    }
  }
  return 1;
}

//----- (0045E2D0) --------------------------------------------------------  // acclient.c:154987
AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *__thiscall AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor(AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
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
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);

//----- (0045E330) --------------------------------------------------------  // acclient.c:155013
void __cdecl _STL::sort(SurfaceUsageSummary *__first, SurfaceUsageSummary *__last)
{
  signed int v2; // edx@2
  int i; // eax@2

  if ( __first != __last )
  {
    v2 = __last - __first;
    for ( i = 0; v2 != 1; ++i )
      v2 >>= 1;
    _STL::__introsort_loop(__first, __last, 0, 2 * i, (int)__first);
    _STL::__final_insertion_sort(__first, __last);
  }
}

//----- (0045E390) --------------------------------------------------------  // acclient.c:155029
void __thiscall AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::~AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>(AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);

//----- (0045E3D0) --------------------------------------------------------  // acclient.c:155050
HashSet<UIElement *>Vtbl *__thiscall UIElementManager::CreateRootElementByDataID(UIElementManager *this, IDClass<_tagDataID,32,0> _layoutDID, unsigned int _elementID)
{
  UIElementManager *v3; // edi@1
  QualifiedDataID *v4; // eax@1
  int v5; // esi@1
  HashSet<UIElement *>Vtbl *result; // eax@1
  ElementDesc *v7; // eax@2
  HashSet<UIElement *>Vtbl *v8; // edi@4
  QualifiedDataID v9; // [sp+8h] [bp-8h]@1

  v3 = this;
  QualifiedDataID::QualifiedDataID(&v9, _layoutDID, 0x23u);
  v5 = DBObj::Get(v4);
  result = 0;
  if ( v5 )
  {
    v7 = LayoutDesc::AccessElementDesc((LayoutDesc *)v5, _elementID);
    if ( v7 )
    {
      v8 = UIElementManager::CreateRootElement(v3, (LayoutDesc *)v5, v7);
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
      result = v8;
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 20))(v5);
      result = 0;
    }
  }
  return result;
}

//----- (0045E440) --------------------------------------------------------  // acclient.c:155083
int __thiscall UIElementManager::CreateChildElementByEnum(UIElementManager *this, UIElement *i_pParent, const unsigned int _layoutEnum, unsigned int _elementID)
{
  UIElementManager *v4; // edi@1
  int result; // eax@1
  LayoutDesc *v6; // esi@1
  ElementDesc *v7; // eax@2
  HashSet<UIElement *>Vtbl *v8; // edi@4

  v4 = this;
  result = DBObj::GetByEnum(_layoutEnum, 5, 0x23u);
  v6 = (LayoutDesc *)result;
  if ( result )
  {
    v7 = LayoutDesc::AccessElementDesc((LayoutDesc *)result, _elementID);
    if ( v7 )
    {
      v8 = UIElementManager::CreateChildElement(v4, i_pParent, v6, v7);
      v6->vfptr->Release((Interface *)v6);
      result = (int)v8;
    }
    else
    {
      v6->vfptr->Release((Interface *)v6);
      result = 0;
    }
  }
  return result;
}

//----- (0045E4A0) --------------------------------------------------------  // acclient.c:155113
int __thiscall UIElementManager::CreateChildElementByDid(UIElementManager *this, UIElement *i_pParent, IDClass<_tagDataID,32,0> _layoutID, unsigned int _elementID)
{
  UIElementManager *v4; // edi@1
  QualifiedDataID *v5; // eax@1
  int result; // eax@1
  LayoutDesc *v7; // esi@1
  ElementDesc *v8; // eax@2
  HashSet<UIElement *>Vtbl *v9; // edi@4
  QualifiedDataID v10; // [sp+8h] [bp-8h]@1

  v4 = this;
  QualifiedDataID::QualifiedDataID(&v10, _layoutID, 0x23u);
  result = DBObj::Get(v5);
  v7 = (LayoutDesc *)result;
  if ( result )
  {
    v8 = LayoutDesc::AccessElementDesc((LayoutDesc *)result, _elementID);
    if ( v8 )
    {
      v9 = UIElementManager::CreateChildElement(v4, i_pParent, v7, v8);
      v7->vfptr->Release((Interface *)v7);
      result = (int)v9;
    }
    else
    {
      v7->vfptr->Release((Interface *)v7);
      result = 0;
    }
  }
  return result;
}

//----- (0045E520) --------------------------------------------------------  // acclient.c:155146
void __thiscall UIElementManager::DeletingElement(UIElementManager *this, UIElement *_element)
{
  UIElement *v2; // ebp@1
  UIElementManager *v3; // esi@1
  UIElement *v4; // ecx@2
  UIElement *v5; // eax@4
  UIElement *v6; // eax@6
  UIElement *v7; // ecx@17
  ContextMenu *v8; // ecx@19
  List<UIElementMessageInfo> *v9; // edi@22
  ListNode<UIElementMessageInfo> *v10; // esi@22
  ListNode<UIElementMessageInfo> *v11; // eax@24

  v2 = _element;
  v3 = this;
  if ( _element )
  {
    UIElementManager::UnRegisterElementForAllInputActions(this, _element);
    SmartArray<UIElement *,1>::RemoveUnOrdered(
      (SmartArray<bool (__cdecl*)(void),1> *)&v3->m_elementList,
      (bool (__cdecl *const *)())&_element);
    _element = v2;
    SmartArray<UIElement *,1>::RemoveOrdered(&v3->m_activatableElements, &_element);
    v4 = v3->m_focusElement;
    if ( v4 == v2 )
      ((void (*)(void))v4->vfptr[22].__vecDelDtor)();
    v5 = v3->m_activeElement;
    if ( v5 == v2 )
    {
      if ( v5 )
      {
        v6 = v3->m_focusElement;
        v3->m_activeElement = 0;
        if ( v6 )
        {
          UIElementManager::BroadcastElementMessage(v3, v6, 0x2Fu, 0, 0);
          ((void (*)(void))v3->m_focusElement->vfptr[15].__vecDelDtor)();
          v3->m_focusElement = 0;
        }
      }
    }
    if ( v3->m_pElementWithMouseCapture == v2 )
    {
      v3->m_pElementWithMouseCapture = 0;
      v3->m_bPerformMouseHitTest = 1;
    }
    if ( v3->m_pElementLastOver == v2 )
    {
      UIElementManager::SwitchMouseOver(v3, 0);
      v3->m_pElementLastEntered = 0;
      v3->m_pElementLastOver = 0;
      v3->m_pElementLastDragCursorOver = 0;
      v3->m_bPerformMouseHitTest = 1;
    }
    if ( v3->m_pcPotentialDragElement == v2 )
      v3->m_pcPotentialDragElement = 0;
    if ( v3->m_dragOwner == v2 )
      UIElementManager::ClearDragandDrop(v3);
    if ( v3->m_pTooltipOwner == v2 )
    {
      v7 = v3->m_pTooltipElement;
      v3->m_pTooltipOwner = 0;
      if ( v7 )
      {
        UIElement::AddToDeleteQueue(v7);
        v3->m_pTooltipElement = 0;
      }
    }
    v8 = v3->m_pCSM;
    if ( v8 && v8->m_pParentDisplay == v2 )
    {
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
      v3->m_pCSM = 0;
    }
    v9 = &v3->m_listQueuedElementMessages;
    v10 = v3->m_listQueuedElementMessages._head;
    while ( v10 )
    {
      if ( v10->data.pElement == v2 )
      {
        v11 = v10;
        v10 = v10->next;
        List<UIElementMessageInfo>::remove(v9, v11);
      }
      else
      {
        v10 = v10->next;
      }
    }
  }
}

//----- (0045E680) --------------------------------------------------------  // acclient.c:155239
void __thiscall UIElementManager::RegisterForGlobalMessage(UIElementManager *this, UIListener *_listener, unsigned int _messageID)
{
  if ( _listener )
    UIElementManager::RegisterForMessageInternal(_listener, &this->m_globalMessageListenerTable, _messageID);
}

//----- (0045E6A0) --------------------------------------------------------  // acclient.c:155246
char __thiscall UIElementManager::OnAction(UIElementManager *this, InputEvent *i_evt)
{
  unsigned int v2; // eax@1

  v2 = i_evt->m_InputAction;
  if ( i_evt->m_fStart )
  {
    if ( v2 == 4 )
      return 1;
    if ( v2 > 4 && v2 <= 0xF )
    {
      UIElementManager::MouseDownEvent((UIElementManager *)((char *)this - 4), v2, i_evt->m_InputExtent);
      return 1;
    }
  }
  else
  {
    switch ( v2 )
    {
      case 5u:
      case 6u:
      case 7u:
      case 8u:
      case 9u:
      case 0xAu:
      case 0xBu:
      case 0xCu:
        UIElementManager::MouseUpEvent((UIElementManager *)((char *)this - 4), v2, i_evt->m_pcCallback);
        return 1;
      case 4u:
      case 0xDu:
      case 0xEu:
      case 0xFu:
        return 1;
      default:
        return 0;
    }
  }
  return 0;
}

//----- (0045E710) --------------------------------------------------------  // acclient.c:155288
void __thiscall UIElementManager::MouseMoveHandler(UIElementManager *this, int i_xWindow, int i_yWindow)
{
  int v3; // eax@1
  int v4; // edi@1
  UIElementManager *v5; // esi@1
  int v6; // ST0C_4@1
  UIRegion *v7; // ecx@1
  int v8; // eax@3
  UIRegion *v9; // ecx@6
  int v10; // ST0C_4@7
  unsigned int v11; // eax@7
  UIElement *v12; // ecx@8
  UIObject *v13; // eax@9
  UIRegion *v14; // ecx@10
  UIRegion *v15; // ecx@13

  v3 = LODWORD(Timer::local_time);
  v4 = i_yWindow;
  v5 = this;
  v6 = i_yWindow;
  HIDWORD(this->m_lastMouseMoveTime) = HIDWORD(Timer::local_time);
  v7 = (UIRegion *)&this->m_pRootElement->vfptr;
  LODWORD(v5->m_lastMouseMoveTime) = v3;
  if ( UIRegion::PointIsOverRegion(v7, i_xWindow, v6) )
    v5->m_bMouseHasLeftTheWindow = 0;
  v8 = 0;
  if ( !v5->m_bMouseHasLeftTheWindow )
  {
    i_yWindow = 0;
    MouseHitTester<MouseOverCriteria>::Recurse(v5->m_pRootElement, i_xWindow, v4, (UIElement **)&i_yWindow);
    v8 = i_yWindow;
  }
  UIElementManager::SwitchMouseOver(v5, (UIElement *)v8);
  if ( v5->m_bDragStarted || (v9 = (UIRegion *)&v5->m_pcPotentialDragElement->vfptr) == 0 )
  {
    v12 = v5->m_dragElement;
    if ( v12 )
    {
      v13 = v12->m_object;
      if ( v13 || (v14 = v12->m_parent) != 0 && (v13 = UIRegion::GetObjectA(v14)) != 0 )
        ((void (__thiscall *)(UIObject *, int, int, unsigned int, unsigned int))v13->vfptr[3].__vecDelDtor)(
          v13,
          i_xWindow + v5->m_dragBaseX - v5->m_dragX,
          v4 + v5->m_dragBaseY - v5->m_dragY,
          v13->m_nVirtualWidth,
          v13->m_nVirtualHeight);
    }
  }
  else
  {
    v10 = v4 - UIRegion::GetScreenY0(v9);
    v11 = UIRegion::GetScreenX0((UIRegion *)&v5->m_pcPotentialDragElement->vfptr);
    UIElementManager::StartDragandDrop(v5, v5->m_pcPotentialDragElement, i_xWindow - v11, v10);
  }
  v15 = (UIRegion *)&v5->m_pElementWithMouseCapture->vfptr;
  if ( v15 || (!v5->m_bDragStarted || !v5->m_dragElement) && (v15 = (UIRegion *)&v5->m_pElementLastEntered->vfptr) != 0 )
    UIRegion::NotifyMouseMove(v15, i_xWindow, v4);
}

//----- (0045E850) --------------------------------------------------------  // acclient.c:155348
char __cdecl UIElementManager::ConsoleCommand_PrintUISurfaceUsage()
{
  unsigned int v0; // eax@2
  unsigned int v1; // esi@2
  int v2; // ebp@5
  char v3; // al@5
  UIObject *v4; // eax@6
  UIRegion *v5; // ecx@7
  int v6; // eax@9
  int v7; // edi@10
  int v8; // esi@11
  int v9; // edi@11
  PixelFormatID v10; // eax@11
  unsigned int v11; // edx@11
  int v12; // eax@11
  unsigned int v13; // esi@11
  unsigned int v14; // eax@11
  unsigned int v15; // ecx@11
  unsigned int v16; // edx@11
  PSRefBufferCharData<char> *v17; // eax@11
  bool v18; // cf@11
  PSRefBufferCharData<char> **v19; // eax@11
  unsigned int v20; // eax@13
  unsigned int *v21; // eax@13
  char *v22; // esi@15
  char *v23; // esi@18
  char *v24; // esi@21
  unsigned int v25; // esi@26
  char *v26; // esi@27
  bool v27; // zf@28
  int v28; // edi@29
  unsigned int v29; // ebp@29
  unsigned int v30; // edi@29
  char *v31; // esi@31
  int v32; // edx@31
  int v33; // ST2C_4@31
  int v34; // ST28_4@31
  int v35; // edx@31
  int v36; // ST24_4@31
  char *v37; // esi@31
  char *v38; // esi@36
  char *v39; // esi@39
  char *v40; // esi@42
  unsigned int v41; // eax@51
  char *v42; // ebp@51
  int v43; // edx@51
  int v44; // eax@51
  char *v45; // edi@52
  int v46; // ebx@52
  int v47; // esi@53
  int v48; // esi@53
  PStringBase<char> str; // [sp+38h] [bp-7Ch]@11
  unsigned int MaxByteLength; // [sp+3Ch] [bp-78h]@2
  PStringBase<char> strError; // [sp+40h] [bp-74h]@2
  PStringBase<char> sFormat; // [sp+44h] [bp-70h]@5
  PStringBase<char> sNum; // [sp+48h] [bp-6Ch]@11
  unsigned int Count; // [sp+4Ch] [bp-68h]@2
  unsigned int v56; // [sp+50h] [bp-64h]@11
  PStringBase<char> sSharedFormat; // [sp+54h] [bp-60h]@11
  SmartArray<SurfaceUsageSummary,1> aData; // [sp+58h] [bp-5Ch]@2
  SurfaceUsageSummary data; // [sp+64h] [bp-50h]@11
  PixelFormatDesc v60; // [sp+7Ch] [bp-38h]@11

  if ( !UIElementManager::s_pInstance )
    return 0;
  v0 = (unsigned int)&UIElementManager::s_pInstance->m_elementList;
  aData.m_data = 0;
  aData.m_sizeAndDeallocate = 0;
  aData.m_num = 0;
  v1 = UIElementManager::s_pInstance->m_elementList.m_num;
  strError.m_charbuffer = 0;
  MaxByteLength = 0;
  Count = (unsigned int)&UIElementManager::s_pInstance->m_elementList;
  if ( v1 > 0 )
  {
    while ( 1 )
    {
      v2 = *(_DWORD *)(*(_DWORD *)v0 + 4 * v1 - 4);
      v3 = *(_BYTE *)(v2 + 1366);
      --v1;
      sFormat.m_charbuffer = (PSRefBufferCharData<char> *)v1;
      if ( v3 & 1 )
      {
        v4 = *(UIObject **)(v2 + 176);
        if ( v4 || (v5 = *(UIRegion **)(v2 + 172)) != 0 && (v4 = UIRegion::GetObjectA(v5)) != 0 )
        {
          v6 = ((int (__thiscall *)(UIObject *))v4->vfptr[7].__vecDelDtor)(v4);
          if ( v6 )
          {
            v7 = *(_DWORD *)(v6 + 272);
            if ( v7 )
            {
              v8 = *(_DWORD *)(v2 + 740);
              str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
              InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
              PStringBase<char>::sprintf(&str, "0x%08X", v8);
              v9 = *(_DWORD *)(v7 + 8);
              v10 = *(_DWORD *)(v9 + 96);
              v11 = *(_DWORD *)(v9 + 140);
              sSharedFormat.m_charbuffer = *(PSRefBufferCharData<char> **)(v9 + 136);
              v56 = v11;
              PixelFormatDesc::PixelFormatDesc(&v60, v10);
              v13 = (unsigned int)sSharedFormat.m_charbuffer * v56 * *(_BYTE *)(v12 + 12);
              data.Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
              v13 >>= 3;
              InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
              data.Bytes = v13;
              PStringBase<unsigned short>::operator=(
                (PStringBase<unsigned short> *)&data.Name,
                (const unsigned __int16 *)&str);
              data.ElementHeight = UIRegion::GetHeight((UIRegion *)v2);
              v14 = UIRegion::GetWidth((UIRegion *)v2);
              v15 = *(_DWORD *)(v9 + 140);
              v16 = *(_DWORD *)(v9 + 136);
              data.ElementWidth = v14;
              data.SurfaceHeight = v15;
              data.SurfaceWidth = v16;
              SmartArray<SurfaceUsageSummary,1>::add(&aData, &data);
              sNum.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
              InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
              PStringBase<char>::sprintf(&sNum, "%d", v13);
              v17 = *(PSRefBufferCharData<char> **)&str.m_charbuffer[-1].m_data[12];
              sSharedFormat.m_charbuffer = v17;
              v18 = (unsigned int)strError.m_charbuffer < (unsigned int)v17;
              v19 = (PSRefBufferCharData<char> **)&sSharedFormat;
              if ( !v18 )
                v19 = (PSRefBufferCharData<char> **)&strError;
              strError.m_charbuffer = *v19;
              v20 = *(_DWORD *)&sNum.m_charbuffer[-1].m_data[12];
              sSharedFormat.m_charbuffer = (PSRefBufferCharData<char> *)v20;
              v18 = MaxByteLength < v20;
              v21 = (unsigned int *)&sSharedFormat;
              if ( !v18 )
                v21 = &MaxByteLength;
              v22 = &sNum.m_charbuffer[-2].m_data[12];
              MaxByteLength = *v21;
              if ( !InterlockedDecrement((volatile LONG *)&sNum.m_charbuffer[-1]) && v22 )
                (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
              v23 = &data.Name.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&data.Name.m_charbuffer[-1]) && v23 )
                (**(void (__thiscall ***)(char *, signed int))v23)(v23, 1);
              v24 = &str.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v24 )
                (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
              v1 = (unsigned int)sFormat.m_charbuffer;
            }
          }
        }
      }
      if ( !v1 )
        break;
      v0 = Count;
    }
    v25 = aData.m_num;
    if ( aData.m_num )
    {
      sNum.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      Count = aData.m_num;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(&sNum, "%d", v25);
      v28 = *(_DWORD *)&sNum.m_charbuffer[-1].m_data[12];
      sSharedFormat.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      sFormat.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PStringBase<char>::sprintf(
        &sFormat,
        "%s%d%s%d%s%d%s",
        "%",
        v28,
        "d.) %",
        strError.m_charbuffer,
        "s - %",
        MaxByteLength,
        "d bytes, %.02fMB e:(%4dx%4d) s:(%4dx%4d)\n");
      _STL::sort(aData.m_data, &aData.m_data[aData.m_num]);
      v29 = 0;
      v30 = 0;
      if ( v25 )
      {
        MaxByteLength = 0;
        do
        {
          v31 = (char *)aData.m_data + MaxByteLength;
          v32 = *(unsigned int *)((char *)&aData.m_data->Bytes + MaxByteLength);
          strError.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          v30 += v32;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          v33 = *((_DWORD *)v31 + 5);
          v34 = *((_DWORD *)v31 + 4);
          v35 = *((_DWORD *)v31 + 2);
          ++v29;
          v36 = *((_DWORD *)v31 + 3);
          v56 = *(_DWORD *)v31;
          PStringBase<char>::sprintf(
            &strError,
            sFormat.m_charbuffer->m_data,
            v29,
            *((_DWORD *)v31 + 1),
            v56,
            (double)v56 * 0.00000095367432,
            v35,
            v36,
            v34,
            v33);
          GlobalRegistry::OutputText(&strError);
          v37 = &strError.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&strError.m_charbuffer[-1]) && v37 )
            (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
          MaxByteLength += 24;
        }
        while ( v29 < Count );
        v25 = Count;
      }
      str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v56 = v30;
      PStringBase<char>::sprintf(
        &str,
        " %d elements, %d bytes tot, %.02f MB tot\n",
        v25,
        v30,
        (double)v30 * 0.00000095367432);
      GlobalRegistry::OutputText(&str);
      v38 = &str.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v38 )
        (**(void (__thiscall ***)(char *, signed int))v38)(v38, 1);
      v39 = &sFormat.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&sFormat.m_charbuffer[-1]) && v39 )
        (**(void (__thiscall ***)(char *, signed int))v39)(v39, 1);
      v40 = &sSharedFormat.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&sSharedFormat.m_charbuffer[-1]) && v40 )
        (**(void (__thiscall ***)(char *, signed int))v40)(v40, 1);
      v26 = &sNum.m_charbuffer[-2].m_data[12];
      if ( InterlockedDecrement((volatile LONG *)&sNum.m_charbuffer[-1]) )
        goto LABEL_49;
      v27 = v26 == 0;
      goto LABEL_47;
    }
  }
  PStringBase<char>::PStringBase<char>(&sNum, "No Root Elements w/ UISurfaces\n");
  GlobalRegistry::OutputText(&sNum);
  v26 = &sNum.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&sNum.m_charbuffer[-1]) )
  {
    v27 = v26 == 0;
LABEL_47:
    if ( !v27 )
      (**(void (__thiscall ***)(char *, signed int))v26)(v26, 1);
  }
LABEL_49:
  if ( (aData.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)aData.m_data )
  {
    v41 = aData.m_data[-1].SurfaceHeight;
    v42 = (char *)&aData.m_data[-1].SurfaceHeight;
    v43 = 3 * v41;
    v44 = v41 - 1;
    if ( v44 >= 0 )
    {
      v45 = (char *)&aData.m_data[8 * v43 / 0x18u].Name;
      v46 = v44 + 1;
      do
      {
        v47 = *((_DWORD *)v45 - 6);
        v45 -= 24;
        v48 = v47 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v48 + 4)) )
        {
          if ( v48 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v48)(v48, 1);
        }
        --v46;
      }
      while ( v46 );
    }
    operator delete[](v42);
  }
  return 1;
}

//----- (0045ED50) --------------------------------------------------------  // acclient.c:155629
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *v1; // ebx@1
  int v2; // ecx@2
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **v5; // edx@5
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v6; // edi@5
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v7; // eax@7
  HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v8; // ecx@8
  void *v9; // eax@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_19;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_19:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v6->m_data.vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents(&v6->m_data.m_intrusiveTable);
      v9 = v6->m_data.m_intrusiveTable.m_buckets;
      v6->m_data.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
      if ( v9 != v6->m_data.m_intrusiveTable.m_aInplaceBuckets )
        operator delete[](v9);
      v6->m_data.m_intrusiveTable.m_buckets = 0;
      v6->m_data.m_intrusiveTable.m_firstInterestingBucket = 0;
      v6->m_data.m_intrusiveTable.m_numBuckets = 0;
      v6->m_data.m_intrusiveTable.m_numElements = 0;
      operator delete(v6);
    }
  }
}
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);

//----- (0045EE10) --------------------------------------------------------  // acclient.c:155701
char __thiscall UIElementManager::Init(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  char *v2; // edi@1
  char *v3; // edi@4
  HashSet<UIElement *>Vtbl *v4; // eax@7
  char result; // al@8
  int v6; // eax@9
  unsigned int v7; // eax@10
  char *v8; // edi@14
  char *v9; // edi@17
  PStringBase<char> _Description; // [sp+2Ch] [bp-8h]@1
  PStringBase<char> v11; // [sp+30h] [bp-4h]@14

  v1 = this;
  PStringBase<char>::PStringBase<char>(&_Description, "Tooltip Delay");
  UserPreferences::RegisterPreference(
    (float *)&_Description,
    &v1->m_tooltipDelay,
    &Misc_TooltipDelay_2,
    &_Description,
    UIElementManager::HandlePreferenceCallback,
    0,
    0,
    0);
  v2 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  PStringBase<char>::PStringBase<char>(&_Description, "Tooltip Enable");
  UserPreferences::RegisterPreference(
    (bool *)&_Description,
    &v1->m_tooltipEnable,
    &Misc_TooltipEnable_2,
    &_Description,
    UIElementManager::HandlePreferenceCallback,
    0,
    0,
    0);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  Render::LinkRGRCallback((bool (__cdecl *)())RefreshEvent_g);
  Timer::Init();
  UIElement_Field::Register();
  UIElement_Button::Register();
  UIElement_Text::Register();
  UIElement_Scrollbar::Register();
  UIElement_Meter::Register();
  UIElement_ListBox::Register();
  UIElement_Menu::Register();
  UIElement_Dragbar::Register();
  UIElement_Panel::Register();
  UIElement_Viewport::Register();
  UIElement_Resizebar::Register();
  UIElement_Browser::Register();
  UIElement_ColorPicker::Register();
  UIElement_GroupBox::Register();
  ConfirmationDialog::Register();
  ConfirmationMenuDialog::Register();
  ConfirmationTextInputDialog::Register();
  MenuDialog::Register();
  MessageDialog::Register();
  TextInputDialog::Register();
  WaitDialog::Register();
  v4 = UIElementManager::CreateHollowElement(v1, 0);
  v1->m_pRootElement = (UIElement *)v4;
  if ( v4 )
  {
    v4[341].__vecDelDtor = (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))((unsigned int)v4[341].__vecDelDtor | 4);
    SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v1->m_activatableElements);
    v6 = v1->m_activatableElements.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v1->m_activatableElements.m_num < v6
      || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v1->m_activatableElements, v7)) )
      v1->m_activatableElements.m_data[v1->m_activatableElements.m_num++] = v1->m_pRootElement;
    if ( ICIDM::s_cidm )
    {
      ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputHandler)(v1, 17);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(3, &v1->vfptr, 0);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(13, &v1->vfptr, 4000);
    }
    PStringBase<char>::PStringBase<char>(
      &v11,
      "The UIElementManager will tell you which root UIElements are using what UISurface Memory");
    PStringBase<char>::PStringBase<char>(&_Description, "UIElementManager.PrintUISurfaceUsage");
    GlobalRegistry::RegisterCommand(
      (bool (__cdecl *)())UIElementManager::ConsoleCommand_PrintUISurfaceUsage,
      &_Description,
      &v11);
    v8 = &_Description.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = &v11.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v11.m_charbuffer[-1]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
    v1->m_debugFontDID.id = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&v11, 23, 9)->id;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0045F060) --------------------------------------------------------  // acclient.c:155810
char __thiscall HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::add(HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1> *this, const unsigned int *_key, AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *_data)
{
  void *v3; // esi@1
  void *v4; // eax@6
  char result; // al@9
  HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1> *v6; // [sp+Ch] [bp-4h]@1

  v6 = this;
  v3 = operator new(0x7Cu);
  if ( v3 )
  {
    *(_DWORD *)v3 = *_key;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = &HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)((char *)v3 + 12),
      _data->m_intrusiveTable.m_numBuckets);
    HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::operator=((int)((char *)v3 + 8), (unsigned int)_data);
    *((_DWORD *)v3 + 2) = &HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  }
  else
  {
    v3 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::add(
         &v6->m_intrusiveTable,
         (HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *)v3) )
  {
    result = 1;
  }
  else
  {
    if ( v3 )
    {
      *((_DWORD *)v3 + 2) = &HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)((char *)v3 + 12));
      v4 = (void *)*((_DWORD *)v3 + 27);
      *((_DWORD *)v3 + 3) = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
      if ( v4 != (char *)v3 + 16 )
        operator delete[](v4);
      *((_DWORD *)v3 + 27) = 0;
      *((_DWORD *)v3 + 28) = 0;
      *((_DWORD *)v3 + 29) = 0;
      *((_DWORD *)v3 + 30) = 0;
      operator delete(v3);
    }
    result = 0;
  }
  return result;
}
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);

//----- (0045F120) --------------------------------------------------------  // acclient.c:155864
void __usercall UIElementManager::Cleanup(UIElementManager *this@<ecx>, signed int a2@<edi>)
{
  UIElementManager *v2; // esi@1
  ContextMenu *v3; // ecx@1
  UIElement *v4; // ecx@3
  UIElement *v5; // ecx@6
  UIElement *v6; // ecx@8
  int v7; // esi@11
  char *v8; // esi@12
  char *v9; // esi@15
  PStringBase<char> _Name; // [sp+24h] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v2 = this;
  v3 = this->m_pCSM;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v2->m_dragElement;
  v2->m_pCSM = 0;
  if ( v4 && (v4->m_nFlags >> 15) & 1 )
  {
    UIElement::AddToDeleteQueue(v4);
    v2->m_dragElement = 0;
  }
  v5 = v2->m_pTooltipElement;
  v2->m_bDragStarted = 0;
  v2->m_dragOwner = 0;
  v2->m_pcPotentialDragElement = 0;
  if ( v5 )
  {
    UIElement::AddToDeleteQueue(v5);
    v2->m_pTooltipElement = 0;
  }
  UIElementManager::CleanDeleteQueue(v2, a2);
  UserPreferences::UnregisterPreference(&Misc_TooltipDelay_2);
  UserPreferences::UnregisterPreference(&Misc_TooltipEnable_2);
  v6 = v2->m_pRootElement;
  if ( v6 )
    ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
  v2->m_pRootElement = 0;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::delete_contents(&v2->m_elementListenerTable.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents(&v2->m_globalMessageListenerTable.m_intrusiveTable);
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v2->m_classCreateMethodTable.m_intrusiveTable);
  SmartArray<ProfilerUIWindow *,1>::Reset((SmartArray<QuickButton *,1> *)&v2->m_activatableElements);
  Render::UnlinkRGRCallback((bool (__cdecl *)())RefreshEvent_g);
  if ( ICIDM::s_cidm )
  {
    ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputHandler)(v2, 17);
    v7 = (int)&v2->vfptr;
    ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(3, v7);
    ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(13, v7);
  }
  PStringBase<char>::PStringBase<char>(&_Name, "UIElementManager.ShowDebggingWindow");
  GlobalRegistry::UnregisterCommand(&_Name);
  v8 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "UIElementManager.PrintUISurfaceUsage");
  GlobalRegistry::UnregisterCommand(&_Name);
  v9 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
}

//----- (0045F2A0) --------------------------------------------------------  // acclient.c:155932
void __thiscall UIElementManager::RegisterForElementMessage(UIElementManager *this, UIListener *_listener, unsigned int _elementID, unsigned int _messageID)
{
  UIElementManager *v4; // edi@1
  unsigned int *v5; // eax@2
  unsigned int v6; // esi@4
  unsigned int v7; // esi@8
  unsigned int v8; // ebx@9
  UIElement *v9; // ecx@10
  AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > _data; // [sp+8h] [bp-74h]@3

  v4 = this;
  if ( _listener )
  {
    v5 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
           (HashTable<unsigned long,unsigned long,0> *)&this->m_elementListenerTable,
           &_elementID);
    if ( !v5 )
    {
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>(
        &_data.m_intrusiveTable,
        0);
      _data.vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
      HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::add(
        (HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1> *)&v4->m_elementListenerTable.vfptr,
        &_elementID,
        &_data);
      AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::~AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>(&_data);
      v5 = HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::find(
             (HashTable<unsigned long,unsigned long,0> *)&v4->m_elementListenerTable,
             &_elementID);
    }
    v6 = _messageID;
    UIElementManager::RegisterForMessageInternal(
      _listener,
      (AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > *)v5,
      _messageID);
    if ( v6 == 28 || v6 == 29 || v6 == 25 || v6 == 64 )
    {
      v7 = v4->m_elementList.m_num;
      if ( v7 )
      {
        v8 = _elementID;
        do
        {
          v9 = v4->m_elementList.m_data[v7-- - 1];
          if ( v9->m_desc.m_elementID == v8 )
            ((void (__stdcall *)(signed int))v9->vfptr[22].OnLoseFocus)(1);
        }
        while ( v7 );
      }
    }
  }
}
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);

//----- (0045F380) --------------------------------------------------------  // acclient.c:155988
void __thiscall UIElementManager::~UIElementManager(UIElementManager *this)
{
  UIElementManager *v1; // esi@1
  void *v2; // eax@3
  void *v3; // eax@5
  void *v4; // eax@9
  void *v5; // eax@11
  void *v6; // eax@13

  v1 = this;
  this[-1].m_pCSM = (ContextMenu *)&UIElementManager::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIElementManager::vftable;
  if ( ((unsigned int)this->m_activatableElements.m_data & 0x80000000) == 0x80000000 )
    operator delete[](this->m_activeElement);
  v1->m_pElementLastDragCursorOver = (UIElement *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_setActionsTriggeringCapture);
  v2 = v1->m_setActionsTriggeringCapture.m_intrusiveTable.m_aInplaceBuckets[22];
  v1->m_setActionsTriggeringCapture.vfptr = (HashSet<unsigned long>Vtbl *)IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable;
  if ( v2 != &v1->m_setActionsTriggeringCapture.m_intrusiveTable )
    operator delete[](v2);
  v1->m_setActionsTriggeringCapture.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
  v1->m_setActionsTriggeringCapture.m_intrusiveTable.m_buckets = 0;
  v1->m_setActionsTriggeringCapture.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_setActionsTriggeringCapture.m_intrusiveTable.m_numBuckets = 0;
  List<UIElementMessageInfo>::~List<UIElementMessageInfo>((List<UIElementMessageInfo> *)&v1->m_elementInputActionListenerTable.m_intrusiveTable.m_numElements);
  v1->m_aUIMessageRemovalData.m_num = (unsigned int)AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)&v1->m_elementInputActionListenerTable);
  v3 = v1->m_elementInputActionListenerTable.m_intrusiveTable.m_aInplaceBuckets[22];
  v1->m_elementInputActionListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIElement *,1>,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable;
  if ( v3 != &v1->m_elementInputActionListenerTable.m_intrusiveTable )
    operator delete[](v3);
  v1->m_elementInputActionListenerTable.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
  v1->m_elementInputActionListenerTable.m_intrusiveTable.m_buckets = 0;
  v1->m_elementInputActionListenerTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_elementInputActionListenerTable.m_intrusiveTable.m_numBuckets = 0;
  if ( ((unsigned int)v1->m_aUIMessageRemovalData.m_data & 0x80000000) == 0x80000000 )
    operator delete[]((void *)v1->m_globalMessageListenerTable.m_intrusiveTable.m_numElements);
  v1->m_elementListenerTable.m_intrusiveTable.m_numElements = (unsigned int)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1> > *,1> *)&v1->m_globalMessageListenerTable);
  v4 = v1->m_globalMessageListenerTable.m_intrusiveTable.m_aInplaceBuckets[22];
  v1->m_globalMessageListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable;
  if ( v4 != &v1->m_globalMessageListenerTable.m_intrusiveTable )
    operator delete[](v4);
  v1->m_globalMessageListenerTable.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
  v1->m_globalMessageListenerTable.m_intrusiveTable.m_buckets = 0;
  v1->m_globalMessageListenerTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_globalMessageListenerTable.m_intrusiveTable.m_numBuckets = 0;
  LODWORD(v1->m_vGlobalScale.z) = &HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *,1> *)&v1->m_elementListenerTable);
  v5 = v1->m_elementListenerTable.m_intrusiveTable.m_aInplaceBuckets[22];
  v1->m_elementListenerTable.vfptr = (HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable;
  if ( v5 != &v1->m_elementListenerTable.m_intrusiveTable )
    operator delete[](v5);
  v1->m_elementListenerTable.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
  v1->m_elementListenerTable.m_intrusiveTable.m_buckets = 0;
  v1->m_elementListenerTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_elementListenerTable.m_intrusiveTable.m_numBuckets = 0;
  v1->m_elementList.m_num = (unsigned int)HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_classCreateMethodTable);
  v6 = v1->m_classCreateMethodTable.m_intrusiveTable.m_aInplaceBuckets[22];
  v1->m_classCreateMethodTable.vfptr = (HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable;
  if ( v6 != &v1->m_classCreateMethodTable.m_intrusiveTable )
    operator delete[](v6);
  v1->m_classCreateMethodTable.m_intrusiveTable.m_aInplaceBuckets[22] = 0;
  v1->m_classCreateMethodTable.m_intrusiveTable.m_buckets = 0;
  v1->m_classCreateMethodTable.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_classCreateMethodTable.m_intrusiveTable.m_numBuckets = 0;
  if ( ((unsigned int)v1->m_elementList.m_data & 0x80000000) == 0x80000000 )
    operator delete[]((void *)v1->m_deleteQueue.m_num);
  if ( ((unsigned int)v1->m_deleteQueue.m_data & 0x80000000) == 0x80000000 )
    operator delete[](v1->vfptr);
  *(_DWORD *)(v1 != (UIElementManager *)4 ? (unsigned int)v1 : 0) = &IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(v1 != (UIElementManager *)4 ? (unsigned int)v1 : 0);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79BD5C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable[9])(void *, char);
// 79BD60: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char);
// 79BD64: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable[7])(void *, char);
// 79BD68: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable[6])(void *, char);
// 79BD6C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char);
// 79BD70: using guessed type int (__thiscall *HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable[4])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 79BD78: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable[2])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);
// 79BEE8: using guessed type int (__stdcall *UIElementManager::vftable)(char);
// 79BEF4: using guessed type void (__thiscall *UIElementManager::vftable)(UIElementManager *this, InputEvent *i_evt);
// 79BF0C: using guessed type int (__thiscall *HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable)(void *, char);

//----- (0045F570) --------------------------------------------------------  // acclient.c:156078
AutoGrowHashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *__thiscall AutoGrowHashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>>::scalar_deleting_destructor(AutoGrowHashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> > > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1>Vtbl *)&HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable;
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
// 79BD5C: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable[9])(void *, char);
// 79BF0C: using guessed type int (__thiscall *HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable)(void *, char);

//----- (0045F5D0) --------------------------------------------------------  // acclient.c:156104
void __thiscall UIElementManager::UIElementManager(UIElementManager *this)
{
  UIElementManager *v1; // esi@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIElementManager::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElementManager::vftable;
  this->m_deleteQueue.m_data = 0;
  this->m_deleteQueue.m_sizeAndDeallocate = 0;
  this->m_deleteQueue.m_num = 0;
  this->m_elementList.m_data = 0;
  this->m_elementList.m_sizeAndDeallocate = 0;
  this->m_elementList.m_num = 0;
  this->m_classCreateMethodTable.vfptr = (HashTable<unsigned long,UIElement * (__cdecl*)(LayoutDesc const &,ElementDesc const &),0>Vtbl *)HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>(
    &this->m_classCreateMethodTable.m_intrusiveTable,
    0x17u);
  v1->m_pHollowLayoutDesc = 0;
  v1->m_pHollowElementDesc = 0;
  v1->m_elementListenerTable.vfptr = (HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1>Vtbl *)&HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>(
    &v1->m_elementListenerTable.m_intrusiveTable,
    0);
  v1->m_elementListenerTable.vfptr = (HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1> >,1>Vtbl *)&HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable;
  v1->m_globalMessageListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>(
    &v1->m_globalMessageListenerTable.m_intrusiveTable,
    0);
  v1->m_globalMessageListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIMessageData,1>,1>Vtbl *)&HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable;
  v1->m_aUIMessageRemovalData.m_data = 0;
  v1->m_aUIMessageRemovalData.m_sizeAndDeallocate = 0;
  v1->m_aUIMessageRemovalData.m_num = 0;
  v1->m_elementInputActionListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIElement *,1>,1>Vtbl *)AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>(
    &v1->m_elementInputActionListenerTable.m_intrusiveTable,
    0);
  v1->m_elementInputActionListenerTable.vfptr = (HashTable<unsigned long,SmartArray<UIElement *,1>,1>Vtbl *)AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable;
  v1->m_listQueuedElementMessages.vfptr = (List<UIElementMessageInfo>Vtbl *)List<UIElementMessageInfo>::vftable;
  v1->m_listQueuedElementMessages._head = 0;
  v1->m_listQueuedElementMessages._tail = 0;
  v1->m_listQueuedElementMessages._num_elements = 0;
  v1->m_bBroadcastingMessage = 0;
  v1->m_defaultCursorDID.id = INVALID_DID_52.id;
  v1->m_defaultCursorHotX = 0;
  v1->m_defaultCursorHotY = 0;
  v1->m_lastCursorDID.id = INVALID_DID_52.id;
  v1->m_lastCursorHotX = 0;
  v1->m_lastCursorHotY = 0;
  v1->m_bPerformMouseHitTest = 0;
  v1->m_pElementLastOver = 0;
  v1->m_pElementLastEntered = 0;
  v1->m_pElementWithMouseCapture = 0;
  v1->m_pElementLastDragCursorOver = 0;
  v1->m_setActionsTriggeringCapture.vfptr = (HashSet<unsigned long>Vtbl *)HashSet<unsigned long>::vftable;
  IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>(
    &v1->m_setActionsTriggeringCapture.m_intrusiveTable,
    0x17u);
  v1->m_nMouseCapture = 0;
  v1->m_bDoVisualMouseDebugging = 0;
  v1->m_debugFontDID.id = INVALID_DID_52.id;
  LODWORD(v1->m_lastMouseMoveTime) = LODWORD(INVALID_TIME_4);
  v1->m_bMouseHasLeftTheWindow = 0;
  HIDWORD(v1->m_lastMouseMoveTime) = HIDWORD(INVALID_TIME_4);
  v1->m_tooltipStart = INVALID_TIME_4;
  v1->m_tooltipEnable = 1;
  LODWORD(v1->m_tooltipDelay) = 1048576000;
  LODWORD(v1->m_tooltipDuration) = 1092616192;
  v1->m_pTooltipOwner = 0;
  v1->m_pTooltipElement = 0;
  v1->m_dragX = 0;
  v1->m_dragY = 0;
  v1->m_pcPotentialDragElement = 0;
  v1->m_dragElement = 0;
  v1->m_bDragStarted = 0;
  v1->m_bHoverStarted = 0;
  v1->m_focusElement = 0;
  v1->m_activeElement = 0;
  v1->m_activatableElements.m_data = 0;
  v1->m_activatableElements.m_sizeAndDeallocate = 0;
  v1->m_activatableElements.m_num = 0;
  v1->m_pCSM = 0;
  v1->m_vGlobalScale = Vector3_OneVector___1;
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79BD58: using guessed type int (__thiscall *List<UIElementMessageInfo>::vftable[10])(void *, char);
// 79BD70: using guessed type int (__thiscall *HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable[4])(void *, char);
// 79BD74: using guessed type int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char);
// 79BD78: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable[2])(void *, char);
// 79BD7C: using guessed type int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char);
// 79BEE8: using guessed type int (__stdcall *UIElementManager::vftable)(char);
// 79BEF4: using guessed type void (__thiscall *UIElementManager::vftable)(UIElementManager *this, InputEvent *i_evt);
// 79BF0C: using guessed type int (__thiscall *HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable)(void *, char);

//----- (0045F7F0) --------------------------------------------------------  // acclient.c:156199
int __thiscall UIElementManager::vector_deleting_destructor(UIElementManager *this, char a2)
{
  UIElementManager *v2; // esi@1
  int result; // eax@1

  v2 = this;
  UIElementManager::~UIElementManager(this);
  result = (int)&v2[-1].m_pCSM;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1].m_pCSM);
    result = (int)&v2[-1].m_pCSM;
  }
  return result;
}

//----- (0045F820) --------------------------------------------------------  // acclient.c:156216
void __cdecl UIElementManager::CreateUIElementManager()
{
  UIElementManager *v0; // eax@2
  UIElementManager *v1; // eax@3

  if ( !UIElementManager::s_pInstance )
  {
    v0 = (UIElementManager *)operator new(0x340u);
    if ( v0 )
    {
      UIElementManager::UIElementManager(v0);
      UIElementManager::s_pInstance = v1;
    }
    else
    {
      UIElementManager::s_pInstance = 0;
    }
  }
}

//----- (006983C0) --------------------------------------------------------  // acclient.c:688163
char __thiscall SmartArray<UIMessageRemovalData,1>::add(SmartArray<UIMessageData,1> *this, UIMessageData *_data)
{
  SmartArray<UIMessageData,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2
  unsigned int v6; // ecx@3
  UIMessageData *v7; // edx@3

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<LOAD_UVPAIR,1>::grow((SmartArray<LOAD_WEIGHTS,1> *)v2, v4)) != 0) )
  {
    v6 = v2->m_num;
    v7 = v2->m_data;
    v7[v6].pListener = _data->pListener;
    v7[v6].nCount = _data->nCount;
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (006EAC20) --------------------------------------------------------  // acclient.c:766690
int _E73_60()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_2, "Misc.TooltipEnable");
  return atexit(_E74_44);
}

//----- (006EAC40) --------------------------------------------------------  // acclient.c:766697
int _E76_30()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_2, "Misc.TooltipDelay");
  return atexit(_E77_58);
}

//----- (006EAC60) --------------------------------------------------------  // acclient.c:766704
void _E79_30()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_37, PFID_A8R8G8B8);
}

//----- (006EAC70) --------------------------------------------------------  // acclient.c:766710
void _E97_30()
{
  LODWORD(dword_83D098) = 1053364187;
}

//----- (006EAC80) --------------------------------------------------------  // acclient.c:766716
void _E99_7()
{
  outside_val_23 = 1000.0 + 1.0;
}

//----- (006EACA0) --------------------------------------------------------  // acclient.c:766722
void _E101_3()
{
  block_length_23 = 24.0 * 8.0;
}

//----- (006EACC0) --------------------------------------------------------  // acclient.c:766728
void _E103_16()
{
  half_square_length_23 = 24.0 * 0.5;
}

//----- (006EACE0) --------------------------------------------------------  // acclient.c:766734
int _E105_9()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_16, "Render.TextureFiltering");
  return atexit(sub_75D130);
}

//----- (006EAD00) --------------------------------------------------------  // acclient.c:766741
int _E108_10()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_16, "Render.LandscapeDetailTextures");
  return atexit(sub_75D160);
}

//----- (006EAD20) --------------------------------------------------------  // acclient.c:766748
int _E111_11()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_16, "Render.BuildingDetailTextures");
  return atexit(sub_75D190);
}

//----- (006EAD40) --------------------------------------------------------  // acclient.c:766755
int _E114_12()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_16, "Render.FieldOfView");
  return atexit(sub_75D1C0);
}

//----- (006EAD60) --------------------------------------------------------  // acclient.c:766762
int _E117_11()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_16, "Render.LandscapeTextureDetail");
  return atexit(sub_75D1F0);
}

//----- (006EAD80) --------------------------------------------------------  // acclient.c:766769
int _E120_13()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_16, "Render.EnvironmentTextureDetail");
  return atexit(sub_75D220);
}

//----- (006EADA0) --------------------------------------------------------  // acclient.c:766776
int _E123_11()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_16, "Render.SceneryDrawDistance");
  return atexit(sub_75D250);
}

//----- (006EADC0) --------------------------------------------------------  // acclient.c:766783
int _E126_14()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_16, "Render.LandscapeDrawDistance");
  return atexit(_E127_95);
}

//----- (006EADE0) --------------------------------------------------------  // acclient.c:766790
int _E129_13()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_16, "Render.ScreenBrightness");
  return atexit(_E130_87);
}

//----- (006EAE00) --------------------------------------------------------  // acclient.c:766797
int _E132_14()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_16, "Render.AspectRatio");
  return atexit(_E133_80);
}

//----- (006EAE20) --------------------------------------------------------  // acclient.c:766804
int _E135_13()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_16, "Render.DisplayAdapter");
  return atexit(_E136_64);
}

//----- (006EAE40) --------------------------------------------------------  // acclient.c:766811
int _E138_14()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_16, "Render.MaxHardwareClass");
  return atexit(_E139_65);
}

//----- (006EAE60) --------------------------------------------------------  // acclient.c:766818
int _E141_14()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_16, "Render.AutomaticDegrades");
  return atexit(_E142_61);
}

//----- (006EAE80) --------------------------------------------------------  // acclient.c:766825
int _E144_13()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_16, "Render.GraphicsPerformance");
  return atexit(_E145_63);
}

//----- (006EAEA0) --------------------------------------------------------  // acclient.c:766832
int _E147_12()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_16, "Render.DegradeDistance");
  return atexit(_E148_61);
}

//----- (006EAEC0) --------------------------------------------------------  // acclient.c:766839
int _E150_12()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_16, "Render.MultiPassAlpha");
  return atexit(_E151_59);
}

//----- (006EAEE0) --------------------------------------------------------  // acclient.c:766846
int _E153_12()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_16, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83D0F0, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83D0F4, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83D0F8, "Anisotropic");
  return atexit(_E154_60);
}

//----- (006EAF30) --------------------------------------------------------  // acclient.c:766856
int _E156_13()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_16, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83D100, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83D104, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83D108, "High");
  PStringBase<char>::PStringBase<char>(&stru_83D10C, "VeryHigh");
  return atexit(_E157_57);
}

//----- (006EAF90) --------------------------------------------------------  // acclient.c:766867
int _E159_12()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_16, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83D114, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83D118, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83D11C, "High");
  PStringBase<char>::PStringBase<char>(&stru_83D120, "VeryHigh");
  return atexit(_E160_60);
}

//----- (006EAFF0) --------------------------------------------------------  // acclient.c:766878
int _E162_13()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_16, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83D128, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83D12C, "High");
  return atexit(_E163_53);
}

//----- (006EB030) --------------------------------------------------------  // acclient.c:766887
int _E165_12()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_16, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83D134, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83D138, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83D13C, "High");
  PStringBase<char>::PStringBase<char>(&stru_83D140, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83D144, "Extreme");
  return atexit(_E166_55);
}

//----- (006EB0A0) --------------------------------------------------------  // acclient.c:766899
int _E168_13()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_16, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83D14C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83D150, "Wide");
  return atexit(_E169_54);
}

//----- (006EB0E0) --------------------------------------------------------  // acclient.c:766908
int _E171_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_28, "None");
  return atexit(_E172_52);
}

//----- (006EB100) --------------------------------------------------------  // acclient.c:766915
int _E174_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_28, "Speed");
  return atexit(_E175_49);
}

//----- (006EB120) --------------------------------------------------------  // acclient.c:766922
int _E177_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_28, "Noise");
  return atexit(_E178_49);
}

//----- (006EB140) --------------------------------------------------------  // acclient.c:766929
int _E180_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_28, "Sine");
  return atexit(_E181_49);
}

//----- (006EB160) --------------------------------------------------------  // acclient.c:766936
int _E183_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_28, "Square");
  return atexit(_E184_46);
}

//----- (006EB180) --------------------------------------------------------  // acclient.c:766943
int _E186_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_28, "Bounce");
  return atexit(_E187_45);
}

//----- (006EB1A0) --------------------------------------------------------  // acclient.c:766950
int _E189_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_28, "Perlin");
  return atexit(_E190_46);
}

//----- (006EB1C0) --------------------------------------------------------  // acclient.c:766957
int _E192_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_28, "Fractal");
  return atexit(_E193_41);
}

//----- (006EB1E0) --------------------------------------------------------  // acclient.c:766964
int _E195_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_28, "FrameLoop");
  return atexit(_E196_48);
}

//----- (006EB200) --------------------------------------------------------  // acclient.c:766971
int _E198_8()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_7, "Display.Resolution");
  return atexit(_E199_40);
}

//----- (006EB220) --------------------------------------------------------  // acclient.c:766978
int _E201_6()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_7, "Display.FullScreen");
  return atexit(_E202_41);
}

//----- (006EB240) --------------------------------------------------------  // acclient.c:766985
int _E204_5()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_7, "Display.RefreshRate");
  return atexit(_E205_37);
}

//----- (006EB260) --------------------------------------------------------  // acclient.c:766992
int _E207_3()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_7, "Display.SyncToRefresh");
  return atexit(_E208_41);
}

//----- (006EB280) --------------------------------------------------------  // acclient.c:766999
void _E210_5()
{
  DEFAULT_VIEW_RADIUS_10 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EB2A0) --------------------------------------------------------  // acclient.c:767005
void _E212_0()
{
  MIN_QUANTUM_10 = 1.0 / 30.0;
}

//----- (006EB2C0) --------------------------------------------------------  // acclient.c:767011
void _E214_10()
{
  MAX_QUANTUM_10 = 1.0 / 5.0;
}

//----- (006EB2E0) --------------------------------------------------------  // acclient.c:767017
int _E1_52()
{
  return atexit(_E2_52);
}

//----- (0075D130) --------------------------------------------------------  // acclient.c:885208
void __cdecl sub_75D130()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D160) --------------------------------------------------------  // acclient.c:885221
void __cdecl sub_75D160()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D190) --------------------------------------------------------  // acclient.c:885234
void __cdecl sub_75D190()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D1C0) --------------------------------------------------------  // acclient.c:885247
void __cdecl sub_75D1C0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D1F0) --------------------------------------------------------  // acclient.c:885260
void __cdecl sub_75D1F0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D220) --------------------------------------------------------  // acclient.c:885273
void __cdecl sub_75D220()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D250) --------------------------------------------------------  // acclient.c:885286
void __cdecl sub_75D250()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D280) --------------------------------------------------------  // acclient.c:885299
void __cdecl _E127_95()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D2B0) --------------------------------------------------------  // acclient.c:885312
void __cdecl _E130_87()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D2E0) --------------------------------------------------------  // acclient.c:885325
void __cdecl _E133_80()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D310) --------------------------------------------------------  // acclient.c:885338
void __cdecl _E136_64()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D340) --------------------------------------------------------  // acclient.c:885351
void __cdecl _E139_65()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D370) --------------------------------------------------------  // acclient.c:885364
void __cdecl _E142_61()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D3A0) --------------------------------------------------------  // acclient.c:885377
void __cdecl _E145_63()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D3D0) --------------------------------------------------------  // acclient.c:885390
void __cdecl _E148_61()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D400) --------------------------------------------------------  // acclient.c:885403
void __cdecl _E151_59()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D430) --------------------------------------------------------  // acclient.c:885416
void __cdecl _E154_60()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_16;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D470) --------------------------------------------------------  // acclient.c:885441
void __cdecl _E157_57()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_16;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D4B0) --------------------------------------------------------  // acclient.c:885466
void __cdecl _E160_60()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_16;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D4F0) --------------------------------------------------------  // acclient.c:885491
void __cdecl _E163_53()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_16;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D530) --------------------------------------------------------  // acclient.c:885516
void __cdecl _E166_55()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_16;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D570) --------------------------------------------------------  // acclient.c:885541
void __cdecl _E169_54()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_28;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0075D5B0) --------------------------------------------------------  // acclient.c:885566
void __cdecl _E172_52()
{
  char *v0; // esi@1

  v0 = &waveform_None_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D5E0) --------------------------------------------------------  // acclient.c:885579
void __cdecl _E175_49()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D610) --------------------------------------------------------  // acclient.c:885592
void __cdecl _E178_49()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D640) --------------------------------------------------------  // acclient.c:885605
void __cdecl _E181_49()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D670) --------------------------------------------------------  // acclient.c:885618
void __cdecl _E184_46()
{
  char *v0; // esi@1

  v0 = &waveform_Square_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D6A0) --------------------------------------------------------  // acclient.c:885631
void __cdecl _E187_45()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D6D0) --------------------------------------------------------  // acclient.c:885644
void __cdecl _E190_46()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D700) --------------------------------------------------------  // acclient.c:885657
void __cdecl _E193_41()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D730) --------------------------------------------------------  // acclient.c:885670
void __cdecl _E196_48()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_28.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_28.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D760) --------------------------------------------------------  // acclient.c:885683
void __cdecl _E199_40()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D790) --------------------------------------------------------  // acclient.c:885696
void __cdecl _E202_41()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D7C0) --------------------------------------------------------  // acclient.c:885709
void __cdecl _E205_37()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D7F0) --------------------------------------------------------  // acclient.c:885722
void __cdecl _E208_41()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D820) --------------------------------------------------------  // acclient.c:885735
void __cdecl _E74_44()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075D850) --------------------------------------------------------  // acclient.c:885748
void __cdecl _E77_58()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

