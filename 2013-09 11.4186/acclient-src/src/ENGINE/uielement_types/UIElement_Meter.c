/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Meter
   Object     : ENGINE\uielement_types\UIElement_Meter.obj
   Functions  : 20
   Addresses  : 0046F4C0 - 0075E7E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046F4C0) --------------------------------------------------------  // acclient.c:172298
void __userpurge UIElement_Meter::UIElement_Meter(UIElement_Meter *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Meter *v4; // esi@1

  v4 = this;
  UIElement::UIElement((UIElement *)&this->vfptr, a2, _layout, _full_desc);
  v4->m_framemeter = 0;
  v4->m_animating = 0;
  LODWORD(v4->m_anim_start_pos) = 0;
  LODWORD(v4->m_anim_end_pos) = 0;
  LODWORD(v4->m_fOldPosition) = 0;
  v4->m_pcChildImage = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Meter::vftable;
  v4->m_animStartTime = INVALID_TIME_7;
  v4->m_animEndTime = INVALID_TIME_7;
  v4->m_currentFrame = -1;
  v4->m_eDirection = 1;
}
// 79CFA0: using guessed type int (__thiscall *UIElement_Meter::vftable)(void *, char);

//----- (0046F540) --------------------------------------------------------  // acclient.c:172319
signed int __thiscall UIElement_Meter::DynamicCast(UIElement_Meter *this, unsigned int i_eType)
{
  return i_eType != 7 ? 0 : (unsigned int)this;
}

//----- (0046F560) --------------------------------------------------------  // acclient.c:172325
void __usercall UIElement_Meter::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Meter *v3; // eax@1

  v3 = (UIElement_Meter *)operator new(0x620u);
  if ( v3 )
    UIElement_Meter::UIElement_Meter(v3, a1, _layout, _full_desc);
}

//----- (0046F590) --------------------------------------------------------  // acclient.c:172335
void __thiscall UIElement_Meter::RemoveChild(UIElement_Meter *this, UIRegion *_child)
{
  UIElement_Meter *v2; // esi@1

  v2 = this;
  UIRegion::RemoveChild((UIRegion *)&this->vfptr, _child);
  if ( (UIRegion *)v2->m_pcChildImage == _child )
    v2->m_pcChildImage = 0;
}

//----- (0046F5C0) --------------------------------------------------------  // acclient.c:172346
void __thiscall UIElement_Meter::StartAnimation(UIElement_Meter *this)
{
  UIElement_Meter *v1; // esi@1
  double v2; // st7@3
  ICMDCommandEnum v3; // eax@3
  float v4; // edx@3
  float smooth_movement_duration; // [sp+4h] [bp-8h]@2
  float pos; // [sp+8h] [bp-4h]@3

  v1 = this;
  if ( !this->m_animating )
  {
    UIElement::GetAttribute_Float((UIElement *)&this->vfptr, 0x6Bu, &smooth_movement_duration);
    if ( smooth_movement_duration != 0.0 )
    {
      UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x69u, &pos);
      UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x66u, &v1->m_anim_end_pos);
      v2 = smooth_movement_duration;
      v3 = (signed int)Timer::cur_time.Cmd;
      v4 = pos;
      HIDWORD(v1->m_animStartTime) = Timer::cur_time.Param;
      LODWORD(v1->m_animStartTime) = v3;
      v1->m_animEndTime = v2 + v1->m_animStartTime;
      v1->m_anim_start_pos = v4;
      v1->m_animating = 1;
      UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    }
  }
}

//----- (0046F660) --------------------------------------------------------  // acclient.c:172377
void __thiscall UIElement_Meter::UpdateChild(UIElement_Meter *this)
{
  UIElement_Meter *v1; // esi@1
  Box2D *v2; // eax@3
  int v3; // edi@4
  double v4; // st7@5
  double v5; // st7@6
  bool move_fill; // [sp+Bh] [bp-19h]@1
  float position; // [sp+Ch] [bp-18h]@4
  int v8; // [sp+10h] [bp-14h]@5
  char v9; // [sp+14h] [bp-10h]@3

  v1 = this;
  move_fill = 0;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x68u, &move_fill);
  if ( v1->m_pcChildImage )
  {
    if ( move_fill )
    {
      UIElement::GetAttribute_Float((UIElement *)&v1->vfptr, 0x69u, &position);
      v3 = 0;
      switch ( v1->m_eDirection )
      {
        case 1u:
          v8 = -UIRegion::GetWidth((UIRegion *)&v1->vfptr);
          v4 = (double)v8;
          goto LABEL_8;
        case 2u:
          v8 = -UIRegion::GetHeight((UIRegion *)&v1->vfptr);
          v5 = (double)v8;
          goto LABEL_10;
        case 3u:
          v8 = UIRegion::GetWidth((UIRegion *)&v1->vfptr);
          v4 = (double)v8;
LABEL_8:
          ((void (__stdcall *)(_DWORD, _DWORD))v1->m_pcChildImage->vfptr[3].OnLoseFocus)(
            (unsigned __int64)(v4 * (1.0 - position)),
            0);
          return;
        case 4u:
          v8 = UIRegion::GetHeight((UIRegion *)&v1->vfptr);
          v5 = (double)v8;
LABEL_10:
          v3 = (unsigned __int64)(v5 * (1.0 - position));
          break;
        default:
          break;
      }
      ((void (__stdcall *)(_DWORD, int))v1->m_pcChildImage->vfptr[3].OnLoseFocus)(0, v3);
    }
    else
    {
      v2 = (Box2D *)v1->vfptr[4].OnAction((IInputActionCallback *)v1, (InputEvent *)&v9);
      UIRegion::AddDirtyRect((UIRegion *)&v1->vfptr, v2);
    }
  }
}

//----- (0046F770) --------------------------------------------------------  // acclient.c:172436
UIElement_Meter *__thiscall UIElement_Meter::vector_deleting_destructor(UIElement_Meter *this, unsigned int a2)
{
  UIElement_Meter *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Meter::vftable;
  UIElement::~UIElement((UIElement *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79CFA0: using guessed type int (__thiscall *UIElement_Meter::vftable)(void *, char);

//----- (0046F7A0) --------------------------------------------------------  // acclient.c:172450
void __cdecl UIElement_Meter::Register()
{
  UIElement::RegisterElementClass(7u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Meter::Create);
}

//----- (0046F7B0) --------------------------------------------------------  // acclient.c:172456
void __thiscall UIElement_Meter::Initialize(UIElement_Meter *this)
{
  UIElement_Meter *v1; // esi@1
  IInputActionCallbackVtbl *v2; // eax@2
  char v3; // al@2
  BasePropertyValue *v4; // ecx@2
  BasePropertyDesc *v5; // ecx@6
  unsigned int v6; // edx@6
  bool v7; // zf@10
  BaseProperty prop; // [sp+10h] [bp-8h]@2

  v1 = this;
  UIElement::Initialize((UIElement *)&this->vfptr);
  UIElement::GetAttribute_Bool((UIElement *)&v1->vfptr, 0x67u, &v1->m_framemeter);
  if ( !v1->m_framemeter )
  {
    v1->m_pcChildImage = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 2u);
    v2 = v1->vfptr;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    v3 = ((int (__thiscall *)(UIElement_Meter *, signed int, BaseProperty *))v2[17].OnAction)(v1, 111, &prop);
    v4 = prop.m_pcPropertyValue;
    if ( v3 && prop.m_pcPropertyValue )
    {
      ((void (__stdcall *)(unsigned int *))prop.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&v1->m_eDirection);
      v4 = prop.m_pcPropertyValue;
    }
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v5 = prop.m_pcPropertyDesc;
      v6 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v6;
      if ( !v6 )
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      v4 = prop.m_pcPropertyValue;
      prop.m_pcPropertyDesc = 0;
    }
    if ( v4 )
    {
      v7 = v4->m_cRef-- == 1;
      if ( v7 )
        ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (0046F870) --------------------------------------------------------  // acclient.c:172503
void __thiscall UIElement_Meter::ListenToGlobalMessage(UIElement_Meter *this, unsigned int _messageID, int _data_int)
{
  UIElement_Meter *v3; // esi@1
  long double v4; // st7@3
  float _val; // ST04_4@5
  float _messageIDa; // [sp+Ch] [bp+4h]@3

  v3 = this;
  if ( _messageID == 3 && this->m_animating )
  {
    v4 = (COERCE_DOUBLE(Timer::cur_time.Cmd) - this->m_animStartTime) / (this->m_animEndTime - this->m_animStartTime);
    _messageIDa = v4;
    if ( v4 >= 1.0 )
    {
      _messageIDa = 1.0;
      this->m_animating = 0;
      UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    }
    _val = (v3->m_anim_end_pos - v3->m_anim_start_pos) * _messageIDa + v3->m_anim_start_pos;
    UIElement::SetAttribute_Float((UIElement *)&v3->vfptr, 0x69u, _val);
  }
}

//----- (0046F8F0) --------------------------------------------------------  // acclient.c:172527
char __thiscall UIElement_Meter::InqAvailableProperties(UIElement_Meter *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0xEu, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046F940) --------------------------------------------------------  // acclient.c:172555
void __thiscall UIElement_Meter::UpdateFrame(UIElement_Meter *this)
{
  UIElement_Meter *v1; // esi@1
  IInputActionCallbackVtbl *v2; // edx@1
  IInputActionCallbackVtbl *v3; // edx@5
  char v4; // al@5
  BasePropertyValue *v5; // edi@5
  bool v6; // sf@8
  double v7; // st7@8
  unsigned __int64 v8; // rax@10
  BasePropertyValue *v9; // ecx@11
  bool v10; // zf@11
  BasePropertyDesc *v11; // ecx@21
  unsigned int v12; // edx@21
  int v13; // edx@25
  char *v14; // esi@29
  BasePropertyDesc *v15; // ecx@33
  unsigned int v16; // edx@33
  BasePropertyValue *v17; // ecx@37
  unsigned int v18; // edx@37
  unsigned int iNumFrames; // [sp+20h] [bp-28h]@3
  PStringBase<char> elementName; // [sp+24h] [bp-24h]@8
  unsigned int drawmode; // [sp+28h] [bp-20h]@5
  float position; // [sp+2Ch] [bp-1Ch]@1
  BaseProperty dm; // [sp+30h] [bp-18h]@5
  BaseProperty array; // [sp+38h] [bp-10h]@1
  BaseProperty file; // [sp+40h] [bp-8h]@11

  v1 = this;
  UIElement::GetAttribute_Float((UIElement *)&this->vfptr, 0x69u, &position);
  v2 = v1->vfptr;
  array.m_pcPropertyDesc = 0;
  array.m_pcPropertyValue = 0;
  if ( !(unsigned __int8)((int (__thiscall *)(UIElement_Meter *, signed int, BaseProperty *))v2[17].OnAction)(
                           v1,
                           109,
                           &array) )
    goto LABEL_41;
  if ( array.m_pcPropertyValue )
    ((void (__stdcall *)(unsigned int *))array.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&iNumFrames);
  if ( iNumFrames )
  {
    v3 = v1->vfptr;
    drawmode = 1;
    dm.m_pcPropertyDesc = 0;
    dm.m_pcPropertyValue = 0;
    v4 = ((int (__thiscall *)(UIElement_Meter *, signed int, BaseProperty *))v3[17].OnAction)(v1, 110, &dm);
    v5 = dm.m_pcPropertyValue;
    if ( v4 && dm.m_pcPropertyValue )
    {
      dm.m_pcPropertyValue->vfptr[42].__vecDelDtor(
        (ReferenceCountTemplate<1048576,1> *)dm.m_pcPropertyValue,
        (unsigned int)&drawmode);
      v5 = dm.m_pcPropertyValue;
    }
    v6 = ((iNumFrames - 1) & 0x80000000) != 0;
    elementName.m_charbuffer = (PSRefBufferCharData<char> *)(iNumFrames - 1);
    v7 = (double)(signed int)(iNumFrames-- - 1);
    if ( v6 )
      v7 = v7 + 4294967300.0;
    v8 = (unsigned __int64)(v7 * position + 0.5);
    if ( v1->m_currentFrame != (_DWORD)v8 )
    {
      v9 = array.m_pcPropertyValue;
      v10 = array.m_pcPropertyValue == 0;
      v1->m_currentFrame = v8;
      file.m_pcPropertyDesc = 0;
      file.m_pcPropertyValue = 0;
      if ( !v10
        && (unsigned __int8)((int (__stdcall *)(_DWORD, BaseProperty *))v9->vfptr[61].__vecDelDtor)(v8, &file)
        && (elementName.m_charbuffer = (PSRefBufferCharData<char> *)INVALID_DID_66.id, file.m_pcPropertyValue)
        && (((void (__stdcall *)(PStringBase<char> *))file.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&elementName),
            elementName.m_charbuffer != (PSRefBufferCharData<char> *)INVALID_DID_66.id) )
      {
        UIRegion::SetImageByDID((UIRegion *)&v1->vfptr, (IDClass<_tagDataID,32,0>)elementName.m_charbuffer, drawmode);
      }
      else
      {
        elementName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( !EnumMapper::GetString(0x13u, v1->m_desc.m_elementID, &elementName) )
          PStringBase<char>::sprintf(&elementName, "0x%08X", v1->m_desc.m_elementID);
        UIRegion::ClearImage((UIRegion *)&v1->vfptr);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&elementName);
      }
      BaseProperty::~BaseProperty(&file);
      v5 = dm.m_pcPropertyValue;
    }
    if ( (_DWORD)dm.m_pcPropertyDesc )
    {
      v11 = dm.m_pcPropertyDesc;
      v12 = dm.m_pcPropertyDesc->m_cRef - 1;
      dm.m_pcPropertyDesc->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v5 = dm.m_pcPropertyValue;
      dm.m_pcPropertyDesc = 0;
    }
    if ( v5 )
    {
      v13 = v5->m_cRef - 1;
      v5->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    }
  }
  else
  {
LABEL_41:
    elementName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( !EnumMapper::GetString(0x13u, v1->m_desc.m_elementID, &elementName) )
      PStringBase<char>::sprintf(&elementName, "0x%08X", v1->m_desc.m_elementID);
    UIRegion::ClearImage((UIRegion *)&v1->vfptr);
    v14 = &elementName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&elementName.m_charbuffer[-1]) && v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  if ( (_DWORD)array.m_pcPropertyDesc )
  {
    v15 = array.m_pcPropertyDesc;
    v16 = array.m_pcPropertyDesc->m_cRef - 1;
    array.m_pcPropertyDesc->m_cRef = v16;
    if ( !v16 )
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    array.m_pcPropertyDesc = 0;
  }
  if ( array.m_pcPropertyValue )
  {
    v17 = array.m_pcPropertyValue;
    v18 = array.m_pcPropertyValue->m_cRef - 1;
    array.m_pcPropertyValue->m_cRef = v18;
    if ( !v18 )
      ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
  }
}

//----- (0046FBD0) --------------------------------------------------------  // acclient.c:172693
void __thiscall UIElement_Meter::DrawChildren(UIElement_Meter *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *i_pSurface)
{
  UIElement_Meter *v5; // esi@1
  HashList<UIRegion *,UIRegion *,1>::HashListData *v6; // eax@3
  DLListData *v7; // eax@4
  UIRegion *v8; // ecx@8
  UIObject *v9; // eax@8
  int v10; // edi@9
  int v11; // esi@9
  int v12; // ebp@9
  int v13; // ebx@9
  UIRegion *v14; // ecx@10
  double v15; // st7@14
  double v16; // st7@15
  DLListData *v17; // eax@18
  bool _val[4]; // [sp+10h] [bp-5Ch]@1
  float position; // [sp+14h] [bp-58h]@11
  UIElement *v20; // [sp+18h] [bp-54h]@1
  UIRegion *child; // [sp+1Ch] [bp-50h]@8
  int v22; // [sp+20h] [bp-4Ch]@12
  HashListIterator<HashList<UIRegion *,UIRegion *,1> > iter; // [sp+24h] [bp-48h]@7
  Box2D childSurfaceBox; // [sp+2Ch] [bp-40h]@9
  Box2D meterFillBox; // [sp+3Ch] [bp-30h]@11
  Box2D childClipBox; // [sp+4Ch] [bp-20h]@9
  Box2D surfaceBox; // [sp+5Ch] [bp-10h]@9

  v5 = this;
  v20 = (UIElement *)this;
  _val[3] = 0;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0x68u, &_val[3]);
  if ( !v5->m_pcChildImage || _val[3] )
  {
    UIRegion::DrawChildren((UIRegion *)&v5->vfptr, i_rectObjectSelf, i_rectObjectClip, i_aObjectBoxes, i_pSurface);
  }
  else
  {
    v6 = 0;
    if ( v5->m_children.m_ihlIntrusive.m_hash.m_numElements )
    {
      v7 = v5->m_children.m_ihlIntrusive.m_list.head_;
      if ( v7 )
        v6 = (HashList<UIRegion *,UIRegion *,1>::HashListData *)&v7[-1];
      else
        v6 = 0;
    }
    iter.m_iter.m_pData = v6;
    iter.m_iter.m_pHashList = &v5->m_children.m_ihlIntrusive;
    if ( v6 )
    {
      do
      {
        v8 = iter.m_iter.m_pData->m_data;
        v9 = v8->m_object;
        child = iter.m_iter.m_pData->m_data;
        if ( !v9 )
        {
          ((void (__stdcall *)(Box2D *))v8->vfptr[4].OnAction)(&surfaceBox);
          v10 = surfaceBox.m_x0 + i_rectObjectSelf->m_x0;
          v11 = surfaceBox.m_y0 + i_rectObjectSelf->m_y0;
          v12 = v10 + surfaceBox.m_x1 - surfaceBox.m_x0;
          v13 = v11 + surfaceBox.m_y1 - surfaceBox.m_y0;
          childSurfaceBox.m_x0 = surfaceBox.m_x0 + i_rectObjectSelf->m_x0;
          childSurfaceBox.m_y0 = v11;
          childSurfaceBox.m_x1 = v10 + surfaceBox.m_x1 - surfaceBox.m_x0;
          childSurfaceBox.m_y1 = v11 + surfaceBox.m_y1 - surfaceBox.m_y0;
          childClipBox.m_x0 = 0;
          childClipBox.m_y0 = 0;
          childClipBox.m_x1 = 0;
          childClipBox.m_y1 = 0;
          if ( (unsigned __int8)Box2D::Intersection(i_rectObjectClip, &childSurfaceBox, &childClipBox) )
          {
            v14 = child;
            if ( (HashSetData<UIElement *> *)child == v20[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] )
            {
              meterFillBox.m_x0 = v10;
              meterFillBox.m_x1 = v12;
              meterFillBox.m_y0 = v11;
              meterFillBox.m_y1 = v13;
              UIElement::GetAttribute_Float(v20, 0x69u, &position);
              switch ( v20[1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[8] )
              {
                case 1u:
                  v22 = childSurfaceBox.m_x1 - childSurfaceBox.m_x0 + 1;
                  meterFillBox.m_x1 = (unsigned __int64)((double)v22 * position) + v10 - 1;
                  break;
                case 2u:
                  v22 = childSurfaceBox.m_y1 - childSurfaceBox.m_y0 + 1;
                  meterFillBox.m_y1 = (unsigned __int64)((double)v22 * position) + v11 - 1;
                  break;
                case 3u:
                  v22 = childSurfaceBox.m_x1 - childSurfaceBox.m_x0 + 1;
                  v15 = (double)v22;
                  meterFillBox.m_x0 = childSurfaceBox.m_x0 + (unsigned __int64)((1.0 - position) * v15);
                  meterFillBox.m_x1 = (unsigned __int64)(v15 * position) + meterFillBox.m_x0 - 1;
                  break;
                case 4u:
                  v22 = childSurfaceBox.m_y1 - childSurfaceBox.m_y0 + 1;
                  v16 = (double)v22;
                  meterFillBox.m_y0 = childSurfaceBox.m_y0 + (unsigned __int64)((1.0 - position) * v16);
                  meterFillBox.m_y1 = (unsigned __int64)(v16 * position) + meterFillBox.m_y0 - 1;
                  break;
                default:
                  break;
              }
              Box2D::Intersection(&meterFillBox, &childClipBox, &childClipBox);
              v14 = child;
            }
            ((void (__stdcall *)(Box2D *, Box2D *, SmartArray<Box2D,1> *, UISurface *))v14->vfptr[5].__vecDelDtor)(
              &childSurfaceBox,
              &childClipBox,
              i_aObjectBoxes,
              i_pSurface);
          }
        }
        v17 = iter.m_iter.m_pData->dllist_next;
        if ( !v17 )
          break;
        iter.m_iter.m_pData = (HashList<UIRegion *,UIRegion *,1>::HashListData *)&v17[-1];
      }
      while ( v17 != (DLListData *)8 );
    }
  }
}

//----- (0046FE70) --------------------------------------------------------  // acclient.c:172818
void __userpurge UIElement_Meter::OnSetAttribute(UIElement_Meter *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  BaseProperty *v3; // edi@1
  UIElement_Meter *v4; // esi@1
  BasePropertyDesc *v5; // eax@1
  BasePropertyValue *v6; // ecx@3
  BasePropertyValue *v7; // ecx@17
  float f; // [sp+4h] [bp-4h]@1

  f = *(float *)&this;
  v3 = _attribute;
  v4 = this;
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, _attribute);
  v5 = BaseProperty::GetPropertyName(v3);
  if ( v5 == (BasePropertyDesc *)102 )
  {
    UIElement::GetAttribute_Bool((UIElement *)&v4->vfptr, 0x6Au, (bool *)&_attribute);
    if ( (_BYTE)_attribute )
    {
      if ( v4->m_animating )
      {
        v4->m_animating = 0;
        UIListener::UnRegisterForGlobalMessage((UIListener *)&v4->vfptr, 3u);
      }
      UIElement_Meter::StartAnimation(v4);
    }
    else
    {
      v7 = v3->m_pcPropertyValue;
      if ( v7 )
        ((void (__stdcall *)(float *))v7->vfptr[34].__vecDelDtor)(&f);
      UIElement::SetAttribute_Float((UIElement *)&v4->vfptr, 0x69u, f);
    }
  }
  else if ( v5 == (BasePropertyDesc *)105 )
  {
    v6 = v3->m_pcPropertyValue;
    if ( v6 )
      ((void (__stdcall *)(BaseProperty **))v6->vfptr[34].__vecDelDtor)(&_attribute);
    if ( v4->m_framemeter )
    {
      UIElement_Meter::UpdateFrame(v4);
    }
    else if ( v4->m_pcChildImage )
    {
      UIElement_Meter::UpdateChild(v4);
    }
    if ( fabs(*(float *)&_attribute - v4->m_fOldPosition) > 0.00019999999 )
    {
      v4->m_fOldPosition = *(float *)&_attribute;
      UIElement::BroadcastElementMessage((UIElement *)&v4->vfptr, 0x2Du, 0, 0);
    }
    f = 0.0;
    UIElement::GetAttribute_Float((UIElement *)&v4->vfptr, 0x66u, &f);
    if ( fabs(*(float *)&_attribute - f) <= 0.00019999999 )
      UIElement::BroadcastElementMessage((UIElement *)&v4->vfptr, 0x2Eu, 0, 0);
  }
}

//----- (0046FFB0) --------------------------------------------------------  // acclient.c:172878
void __userpurge UIElement_Meter::ResizeTo(UIElement_Meter *this@<ecx>, int a2@<edi>, const int _width, const int _height)
{
  UIElement_Meter *v4; // esi@1

  v4 = this;
  UIElement::ResizeTo((UIElement *)&this->vfptr, a2, _width, _height);
  if ( v4->m_framemeter )
  {
    UIElement_Meter::UpdateFrame(v4);
  }
  else if ( v4->m_pcChildImage )
  {
    UIElement_Meter::UpdateChild(v4);
  }
}

//----- (006EBFE0) --------------------------------------------------------  // acclient.c:767805
int _E73_71()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_10, "Misc.TooltipEnable");
  return atexit(_E74_53);
}

//----- (006EC000) --------------------------------------------------------  // acclient.c:767812
int _E76_39()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_10, "Misc.TooltipDelay");
  return atexit(_E77_67);
}

//----- (006EC020) --------------------------------------------------------  // acclient.c:767819
int _E1_66()
{
  return atexit(_E2_66);
}

//----- (0075E7B0) --------------------------------------------------------  // acclient.c:886748
void __cdecl _E74_53()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E7E0) --------------------------------------------------------  // acclient.c:886761
void __cdecl _E77_67()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

