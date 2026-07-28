/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmMapUI
   Object     : GAME\game_ui_misc\gmMapUI.obj
   Functions  : 33
   Addresses  : 004A1870 - 00760D30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A1870) --------------------------------------------------------  // acclient.c:218122
void __thiscall gmMapUI::RecvNotice_UpdateHouseData(gmMapUI *this, HouseData *i_houseData)
{
  if ( i_houseData->m_type == 4 )
  {
    this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10] = 0;
  }
  else
  {
    this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10] = (HashSetData<UIElement *> *)i_houseData->m_pos.objcell_id;
    Frame::operator=(
      (int)&this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11],
      (int)&i_houseData->m_pos.frame);
  }
}

//----- (004A18A0) --------------------------------------------------------  // acclient.c:218138
void __thiscall gmMapUI::RecvNotice_FailedHouseTransaction(gmMapUI *this, unsigned int i_eType)
{
  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[10] = 0;
}

//----- (004A18B0) --------------------------------------------------------  // acclient.c:218144
char __thiscall gmMapUI::PlaceMarkerOnMap(gmMapUI *this, UIElement *i_pMarker, long double i_x, long double i_y)
{
  char result; // al@2
  int v5; // ebx@3
  int v6; // edx@3
  int v7; // ebp@3
  int v8; // ST18_4@3
  int v9; // ST1C_4@3
  int v10; // edi@3
  int v11; // ebx@3

  if ( i_pMarker )
  {
    v5 = this->m_boxMapMarkerArea.m_x1;
    v6 = this->m_boxMapMarkerArea.m_x0;
    v7 = this->m_boxMapMarkerArea.m_y1;
    v8 = this->m_boxMapMarkerArea.m_x0;
    v9 = this->m_boxMapMarkerArea.m_y0;
    v10 = v8
        + UIRegion::GetWidth((UIRegion *)&i_pMarker->vfptr) / -2
        - (unsigned __int64)((double)(v5 - v6 + 1) * (i_x * 10.0 + 1024.0) * -0.00048828125);
    v11 = UIRegion::GetHeight((UIRegion *)&i_pMarker->vfptr) / -2;
    ((void (__thiscall *)(UIElement *, int, _DWORD))i_pMarker->vfptr[3].OnLoseFocus)(
      i_pMarker,
      v10,
      v9 + v11 - (unsigned __int64)((2047.0 - (i_y * 10.0 + 1024.0)) * (double)(v7 - v9 + 1) * -0.00048828125));
    i_pMarker->vfptr[2].__vecDelDtor((IInputActionCallback *)i_pMarker, 1u);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004A19A0) --------------------------------------------------------  // acclient.c:218181
unsigned int __cdecl LandDefs::lcoord_to_gid(int x, int y)
{
  unsigned int result; // eax@5

  if ( x < 0 || y < 0 || x >= 2040 || y >= 2040 )
    result = 0;
  else
    result = (((y >> 3) | 32 * (x & 0xFFFFFFF8)) << 16) | ((y & 7) + 8 * (x & 7) + 1);
  return result;
}

//----- (004A19F0) --------------------------------------------------------  // acclient.c:218193
void __userpurge gmMapUI::gmMapUI(gmMapUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMapUI *v4; // esi@1
  int v5; // ecx@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmMapUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmMapUI::vftable;
  v4->m_pDateTimeText = 0;
  v4->m_pCoordinateText = 0;
  v4->m_pPlayerLocationIcon = 0;
  v4->m_pHouseLocationIcon = 0;
  v4->m_pMap = 0;
  v4->m_boxMapMarkerArea.m_x0 = 0;
  v4->m_boxMapMarkerArea.m_y0 = 0;
  v4->m_boxMapMarkerArea.m_x1 = 0;
  v4->m_boxMapMarkerArea.m_y1 = 0;
  LODWORD(v4->m_nextUpdate) = 0;
  HIDWORD(v4->m_nextUpdate) = 0;
  v5 = (int)&v4->m_HousePosition.frame;
  v4->m_HousePosition.vfptr = (PackObjVtbl *)&Position::vftable;
  v4->m_HousePosition.objcell_id = 0;
  *(_DWORD *)v5 = 1065353216;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  *(_DWORD *)(v5 + 60) = 0;
  Frame::cache(&v4->m_HousePosition.frame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7AAC80: using guessed type bool (__thiscall *gmMapUI::vftable)(DBCache *this);
// 7AAF28: using guessed type int (__thiscall *gmMapUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A1AA0) --------------------------------------------------------  // acclient.c:218232
gmMapUI *__thiscall gmMapUI::DynamicCast(gmMapUI *this, unsigned int i_eType)
{
  gmMapUI *result; // eax@1

  result = this;
  if ( i_eType != 268435494 )
    result = (gmMapUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A1AC0) --------------------------------------------------------  // acclient.c:218243
signed int gmMapUI::GetUIElementType()
{
  return 268435494;
}

//----- (004A1AD0) --------------------------------------------------------  // acclient.c:218249
void __thiscall gmMapUI::~gmMapUI(gmMapUI *this)
{
  gmMapUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmMapUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&gmMapUI::vftable;
  this->m_pDateTimeText = 0;
  this->m_pCoordinateText = 0;
  this->m_pPlayerLocationIcon = 0;
  this->m_pHouseLocationIcon = 0;
  this->m_pMap = 0;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v1->m_HousePosition.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7AAC80: using guessed type bool (__thiscall *gmMapUI::vftable)(DBCache *this);
// 7AAF28: using guessed type int (__thiscall *gmMapUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A1B40) --------------------------------------------------------  // acclient.c:218278
void __usercall gmMapUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMapUI *v3; // eax@1

  v3 = (gmMapUI *)operator new(0x670u);
  if ( v3 )
    gmMapUI::gmMapUI(v3, a1, _layout, _full_desc);
}

//----- (004A1B70) --------------------------------------------------------  // acclient.c:218288
gmMapUI *__thiscall gmMapUI::scalar_deleting_destructor(gmMapUI *this, unsigned int a2)
{
  gmMapUI *v2; // esi@1

  v2 = this;
  gmMapUI::~gmMapUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A1B90) --------------------------------------------------------  // acclient.c:218300
void __cdecl gmMapUI::Register()
{
  UIElement::RegisterElementClass(0x10000026u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmMapUI::Create);
}

//----- (004A1BB0) --------------------------------------------------------  // acclient.c:218306
void __stdcall gmMapUI::AddMapNote(UIElement *pMap, unsigned int idNote, LayoutDesc *pLayout, gmMapUI::LocationRolloverInfo *lri)
{
  ElementDesc *v5; // eax@1
  UIElement *v6; // edi@1
  char *v7; // esi@2
  PStringBase<unsigned short> _value; // [sp+10h] [bp-94h]@2
  StringInfo _text; // [sp+14h] [bp-90h]@2

  v5 = UIElementManager::CreateChildElement(UIElementManager::s_pInstance, pMap, pLayout, idNote);
  v6 = (UIElement *)v5;
  if ( v5 )
  {
    ((void (__thiscall *)(ElementDesc *, unsigned int, unsigned int))v5->vfptr[1].GetSubDataIDs)(v5, lri->X, lri->Y);
    ((void (__thiscall *)(UIElement *, unsigned int, unsigned int))v6->vfptr[4].__vecDelDtor)(
      v6,
      lri->Width,
      lri->Height);
    StringInfo::StringInfo(&_text);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, lri->Name);
    StringInfo::SetLiteralValue(&_text, &_value, 1);
    v7 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    }
    UIElement::SetTooltip(v6, &_text);
    StringInfo::~StringInfo(&_text);
  }
}

//----- (004A1C70) --------------------------------------------------------  // acclient.c:218338
void __thiscall gmMapUI::PostInit(gmMapUI *this)
{
  gmMapUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  UIElement *v7; // ecx@8
  UIElement *v8; // ecx@8
  UIElement *v9; // ecx@8
  QualifiedDataID *v10; // eax@8
  int v11; // ebx@8
  gmMapUI::LocationRolloverInfo *v12; // edi@9
  signed int v13; // ebp@9
  GlobalEventHandler *v14; // edi@12
  int v15; // esi@12
  int point; // [sp+8h] [bp-14h]@8
  IDClass<_tagDataID,32,0> layoutID; // [sp+Ch] [bp-10h]@8
  unsigned int tooltipID; // [sp+10h] [bp-Ch]@8
  QualifiedDataID v19; // [sp+14h] [bp-8h]@8

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001EBu);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  else
    v3 = 0;
  v1->m_pDateTimeText = (UIElement_Text *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001EFu);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pCoordinateText = (UIElement_Text *)v5;
  v1->m_pPlayerLocationIcon = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001EDu);
  v1->m_pHouseLocationIcon = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001EEu);
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001ECu);
  v1->m_pMap = v6;
  if ( v6 )
  {
    UIElement::GetAttribute_Int(v6, 0x1000004Eu, &point);
    v7 = v1->m_pMap;
    v1->m_boxMapMarkerArea.m_x0 = point;
    UIElement::GetAttribute_Int(v7, 0x1000004Fu, &point);
    v1->m_boxMapMarkerArea.m_x1 = point;
    UIElement::GetAttribute_Int(v1->m_pMap, 0x10000050u, &point);
    v8 = v1->m_pMap;
    v1->m_boxMapMarkerArea.m_y0 = point;
    UIElement::GetAttribute_Int(v8, 0x10000051u, &point);
    v9 = v1->m_pMap;
    v1->m_boxMapMarkerArea.m_y1 = point;
    UIElement::GetAttribute_Enum(v9, 0x47u, &tooltipID);
    layoutID.id = stru_83EA94.id;
    UIElement::GetAttribute_DataID(v1->m_pMap, 0x48u, &layoutID);
    QualifiedDataID::QualifiedDataID(&v19, layoutID, 0x23u);
    v11 = DBObj::Get(v10);
    if ( v11 )
    {
      v12 = s_rgLocations;
      v13 = 53;
      do
      {
        gmMapUI::AddMapNote(v1->m_pMap, tooltipID, (LayoutDesc *)v11, v12);
        ++v12;
        --v13;
      }
      while ( v13 );
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    }
  }
  v14 = GlobalEventHandler::GetGlobalEventHandler();
  v15 = (int)&v1->vfptr;
  v14->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v14, (unsigned int)&byte_4DD225, (NoticeHandler *)v15);
  v14->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v14, (unsigned int)&byte_4DD226, (NoticeHandler *)v15);
}
// 4DD225: using guessed type char byte_4DD225;
// 4DD226: using guessed type char byte_4DD226;

//----- (004A1E40) --------------------------------------------------------  // acclient.c:218419
void __thiscall PStringBase<unsigned short>::PStringBase<unsigned short>(PStringBase<unsigned short> *this, _WidthConvert __formal, PStringBase<char> *str)
{
  PStringBase<unsigned short> *v3; // esi@1
  volatile LONG *v4; // ST04_4@1
  PSRefBufferCharData<unsigned short> *v5; // eax@1
  int v6; // ecx@1
  PStringBase<char> *v7; // edi@3

  v3 = this;
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = PStringBase<char>::to_wpstring(str, (PStringBase<unsigned short> *)&str, 0)->m_charbuffer;
  v6 = *(_DWORD *)&v5[-1].m_data[14];
  if ( v6 != 1 )
    PStringBase<unsigned short>::append_n_chars(v3, v5->m_data, v6 - 1);
  v7 = str - 5;
  if ( !InterlockedDecrement((volatile LONG *)&str[-4]) )
  {
    if ( v7 )
      (*(void (__thiscall **)(PStringBase<char> *, signed int))&v7->m_charbuffer->m_data[0])(v7, 1);
  }
}

//----- (004A1EB0) --------------------------------------------------------  // acclient.c:218444
char __thiscall gmMapUI::Update(gmMapUI *this)
{
  gmMapUI *v1; // esi@1
  UIElement_Text *v2; // eax@1
  PSRefBufferCharData<unsigned short> *v3; // eax@5
  bool v4; // bl@6
  int v5; // edx@7
  int v6; // edi@7
  int v7; // edi@12
  int v8; // edi@17
  int v9; // edi@20
  CPlayerSystem *v10; // edi@25
  unsigned __int16 *v12; // edx@30
  unsigned __int16 *v13; // ecx@34
  PStringBase<unsigned short> *v14; // eax@43
  bool v15; // bl@43
  unsigned int v16; // eax@48
  UIElement *v17; // edx@49
  __int64 worldX; // [sp+30h] [bp-94h]@5
  int v19; // [sp+38h] [bp-8Ch]@29
  double v20; // [sp+3Ch] [bp-88h]@5
  _DWORD x[3]; // [sp+40h] [bp-84h]@29
  int v22; // [sp+48h] [bp-7Ch]@29
  double v23; // [sp+4Ch] [bp-78h]@41
  char timeString[36]; // [sp+58h] [bp-6Ch]@2
  char dateString[66]; // [sp+7Ch] [bp-48h]@2

  v1 = this;
  v2 = this->m_pDateTimeText;
  this->m_nextUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + 5.0;
  if ( v2 )
  {
    *(_WORD *)&dateString[4] = 8250;
    *(_DWORD *)dateString = *(_DWORD *)"Date: ";
    dateString[6] = 0;
    memset(&dateString[7], 0, 0x38u);
    *(_WORD *)&dateString[63] = 0;
    dateString[65] = 0;
    *(_WORD *)&timeString[4] = 8250;
    *(_DWORD *)timeString = *(_DWORD *)"Time: ";
    timeString[6] = 0;
    memset(&timeString[7], 0, 0x1Cu);
    timeString[35] = 0;
    if ( GameTime::current_game_time )
    {
      GameTime::GetDateTimeString(GameTime::current_game_time, &dateString[6], &timeString[6]);
    }
    else
    {
      *(_WORD *)&dateString[6] = 32;
      *(_WORD *)&timeString[6] = 32;
    }
    LODWORD(worldX) = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&worldX, "%s\n%s", dateString, timeString);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&worldX + 1,
      0,
      (PStringBase<char> *)&worldX);
    v3 = UIElement_Text::GetText(v1->m_pDateTimeText, (PStringBase<unsigned short> *)&v20)->m_charbuffer;
    if ( *(_DWORD *)&v3[-1].m_data[14] == *(_DWORD *)(HIDWORD(worldX) - 4) )
    {
      v5 = *(_DWORD *)&v3[-1].m_data[12];
      v6 = *(_DWORD *)(HIDWORD(worldX) - 8);
      if ( v5 == v6 || v5 == -1 || v6 == -1 )
        v4 = _wcscmp(v3->m_data, HIDWORD(worldX)) != 0;
      else
        v4 = 1;
    }
    else
    {
      v4 = 1;
    }
    v7 = LODWORD(v20) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(LODWORD(v20) - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v4 )
      UIElement_Text::SetText(v1->m_pDateTimeText, (PStringBase<unsigned short> *)&worldX + 1);
    v8 = HIDWORD(worldX) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(HIDWORD(worldX) - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = worldX - 20;
    if ( !InterlockedDecrement((volatile LONG *)(worldX - 20 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
  if ( v1->m_pCoordinateText && v1->m_pPlayerLocationIcon )
  {
    v10 = CPlayerSystem::GetPlayerSystem();
    if ( !v10 )
      return 0;
    if ( CPlayerSystem::IsOutside() )
    {
      x[1] = 0;
      v22 = 0;
      HIDWORD(worldX) = 0;
      v19 = 0;
      CPlayerSystem::InqPlayerCoords(v10, (long double *)&x[1], (long double *)((char *)&worldX + 4));
      if ( *(double *)&x[1] >= 0.0 )
      {
        v12 = L"E";
        if ( *(double *)&x[1] <= 0.0 )
          v12 = &word_794320;
      }
      else
      {
        v12 = L"W";
      }
      if ( *(double *)((char *)&worldX + 4) >= 0.0 )
      {
        v13 = L"N";
        if ( *(double *)((char *)&worldX + 4) <= 0.0 )
          v13 = &word_794320;
      }
      else
      {
        v13 = L"S";
      }
      if ( *(double *)&x[1] < 0.0 )
      {
        v20 = -*(double *)&x[1];
      }
      else
      {
        LODWORD(v20) = x[1];
        x[0] = v22;
      }
      if ( *(double *)((char *)&worldX + 4) < 0.0 )
        v23 = -*(double *)((char *)&worldX + 4);
      else
        v23 = *(double *)((char *)&worldX + 4);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&worldX,
        0,
        L"%.1f%s, %.1f%s",
        v23,
        v13,
        LODWORD(v20),
        x[0],
        v12);
      v14 = UIElement_Text::GetText(v1->m_pCoordinateText, (PStringBase<unsigned short> *)&v20);
      v15 = PStringBase<unsigned short>::operator!=(v14, (PStringBase<unsigned short> *)&worldX);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v20);
      if ( v15 )
        UIElement_Text::SetText(v1->m_pCoordinateText, (PStringBase<unsigned short> *)&worldX);
      gmMapUI::PlaceMarkerOnMap(
        v1,
        v1->m_pPlayerLocationIcon,
        *(long double *)&x[1],
        *(long double *)((char *)&worldX + 4));
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&worldX);
    }
    else
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&worldX, &word_794320);
      UIElement_Text::SetText(v1->m_pCoordinateText, (PStringBase<unsigned short> *)&worldX);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&worldX);
      ((void (__stdcall *)(_DWORD))v1->m_pPlayerLocationIcon->vfptr[2].__vecDelDtor)(0);
    }
  }
  if ( v1->m_pHouseLocationIcon )
  {
    if ( Position::IsValid(&v1->m_HousePosition) )
    {
      worldX = -1i64;
      v16 = Position::get_outside_cell_id(&v1->m_HousePosition);
      LandDefs::gid_to_lcoord(v16, (int *)&worldX, (int *)&worldX + 1);
      if ( worldX != -1 )
      {
        v17 = v1->m_pHouseLocationIcon;
        LODWORD(v20) = worldX - 1024;
        gmMapUI::PlaceMarkerOnMap(
          v1,
          v17,
          (double)((signed int)worldX - 1024) * 0.1 + 0.5,
          (double)(HIDWORD(worldX) - 1024) * 0.1 + 0.5);
        return 1;
      }
    }
    else
    {
      v1->m_pHouseLocationIcon->vfptr[2].__vecDelDtor((IInputActionCallback *)v1->m_pHouseLocationIcon, 0);
    }
  }
  return 1;
}
// 7A659C: using guessed type wchar_t aN_1[2];
// 7A65A0: using guessed type wchar_t aS_9[2];
// 7A65A4: using guessed type wchar_t aE[2];
// 7A65A8: using guessed type wchar_t aW_0[2];

//----- (004A2320) --------------------------------------------------------  // acclient.c:218635
void __thiscall gmMapUI::ListenToGlobalMessage(gmMapUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_nextUpdate )
    gmMapUI::Update(this);
}

//----- (004A2350) --------------------------------------------------------  // acclient.c:218642
UIElementMessageListenResult __thiscall gmMapUI::ListenToElementMessage(gmMapUI *this, UIElementMessageInfo *i_rMsg)
{
  UIElementMessageInfo *v2; // ebx@1
  unsigned int v3; // eax@1
  gmMapUI *v4; // esi@1
  UIElementMessageListenResult v5; // eax@4
  InterfaceSystem *v6; // eax@7
  Interface *v7; // edi@7
  PlayerDesc *v8; // edi@11
  UIRegion *v9; // edi@14
  unsigned int v10; // ebp@14
  int v11; // ecx@14
  int v12; // eax@14
  unsigned int v13; // eax@18
  int v14; // edi@18
  int v15; // ebx@18
  unsigned int v16; // eax@18
  int v17; // [sp-8h] [bp-88h]@7
  Interface *_rpInterface; // [sp+10h] [bp-70h]@7
  int y; // [sp+14h] [bp-6Ch]@14
  int v20; // [sp+18h] [bp-68h]@18
  int v21; // [sp+1Ch] [bp-64h]@9
  TResult result; // [sp+20h] [bp-60h]@7
  InterfacePtr<PlayerDesc> spPD; // [sp+24h] [bp-5Ch]@7
  int v24; // [sp+2Ch] [bp-54h]@18
  int v25; // [sp+30h] [bp-50h]@18
  int v26; // [sp+34h] [bp-4Ch]@18
  Position dest; // [sp+38h] [bp-48h]@18

  v2 = i_rMsg;
  v3 = i_rMsg->idMessage;
  v4 = this;
  if ( v3 != 24 )
  {
    if ( v3 == 28 )
    {
      _rpInterface = 0;
      v6 = InterfaceSystem::GetInstance();
      InterfaceSystem::GetClass(v6, &result, &PlayerDesc_ClassType_3, &_rpInterface);
      v7 = _rpInterface;
      v17 = (int)_rpInterface;
      spPD.m_pInterface = 0;
      spPD.m_trStatus.m_val = 0;
      if ( _rpInterface )
        _rpInterface->vfptr->AddRef(_rpInterface);
      _rpInterface = *(Interface **)InterfacePtr<PlayerDesc>::_QueryInterface(&spPD, (int)&v21, v17, 0);
      if ( v7 )
        v7->vfptr->Release(v7);
      v8 = spPD.m_pInterface;
      if ( (_DWORD)spPD.m_pInterface )
      {
        if ( (signed int)_rpInterface >= 0 && PlayerDesc::PlayerIsPSR(spPD.m_pInterface) )
        {
          v9 = (UIRegion *)UIElement::GetChildRecursive((UIElement *)&v4->vfptr, 0x100001ECu);
          v10 = i_rMsg->ptWindow.x - UIRegion::GetScreenX0(v9);
          v11 = i_rMsg->ptWindow.y - UIRegion::GetScreenY0(v9);
          v12 = v4->m_boxMapMarkerArea.m_x0;
          y = v11;
          v21 = v12;
          if ( (signed int)v10 >= v12 && (signed int)v10 < v4->m_boxMapMarkerArea.m_x1 )
          {
            _rpInterface = (Interface *)v4->m_boxMapMarkerArea.m_y0;
            if ( v11 >= (signed int)_rpInterface && v11 < v4->m_boxMapMarkerArea.m_y1 )
            {
              v13 = v4->m_boxMapMarkerArea.m_x0;
              v14 = v4->m_boxMapMarkerArea.m_x1;
              v15 = v4->m_boxMapMarkerArea.m_y1;
              v20 = v4->m_boxMapMarkerArea.m_y0;
              result.m_val = v13;
              Position::Position(&dest);
              v16 = LandDefs::lcoord_to_gid(
                      (signed int)(2047 * (v10 - v21)) / (signed int)(v14 - result.m_val),
                      2047 * (signed int)((char *)_rpInterface - y) / (v15 - v20) + 2047);
              v26 = 0;
              dest.objcell_id = v16;
              v24 = 1092616192;
              v25 = 1092616192;
              LODWORD(dest.frame.m_fOrigin.z) = 0;
              LODWORD(dest.frame.m_fOrigin.x) = 1092616192;
              LODWORD(dest.frame.m_fOrigin.y) = 1092616192;
              Frame::set_heading(&dest.frame, 0.0);
              AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&_rpInterface, &name);
              CM_Advocate::Event_Teleport((AC1Legacy::PStringBase<char> *)&_rpInterface, &dest);
              CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&_rpInterface);
              v2 = i_rMsg;
            }
          }
          v8 = spPD.m_pInterface;
        }
        v8->vfptr->Release((Interface *)v8);
      }
    }
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  }
  if ( (gmMapUI *)i_rMsg->pElement != this )
    return UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, v2);
  if ( i_rMsg->dwParam1 )
  {
    UIListener::RegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    gmMapUI::Update(v4);
    v5 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
  }
  else
  {
    UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
    v5 = UIElement::ListenToElementMessage((UIElement *)&v4->vfptr, i_rMsg);
  }
  return v5;
}

//----- (006F0970) --------------------------------------------------------  // acclient.c:772767
void _E91_67()
{
  outside_val_59 = 1000.0 + 1.0;
}

//----- (006F0990) --------------------------------------------------------  // acclient.c:772773
void _E93_43()
{
  block_length_59 = 24.0 * 8.0;
}

//----- (006F09B0) --------------------------------------------------------  // acclient.c:772779
void _E95_43()
{
  half_square_length_59 = 24.0 * 0.5;
}

//----- (006F09D0) --------------------------------------------------------  // acclient.c:772785
int _E97_68()
{
  return atexit(_E98_80);
}

//----- (006F09E0) --------------------------------------------------------  // acclient.c:772791
int _E100_61()
{
  return atexit(_E101_98);
}

//----- (006F09F0) --------------------------------------------------------  // acclient.c:772797
int _E103_53()
{
  return atexit(_E104_68);
}

//----- (006F0A00) --------------------------------------------------------  // acclient.c:772803
int _E106_43()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_27, "Misc.TooltipEnable");
  return atexit(_E107_74);
}

//----- (006F0A20) --------------------------------------------------------  // acclient.c:772810
int _E109_24()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_27, "Misc.TooltipDelay");
  return atexit(sub_760D30);
}

//----- (006F0A40) --------------------------------------------------------  // acclient.c:772817
void _E112_38()
{
  DEFAULT_VIEW_RADIUS_32 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0A60) --------------------------------------------------------  // acclient.c:772823
void _E114_25()
{
  MIN_QUANTUM_32 = 1.0 / 30.0;
}

//----- (006F0A80) --------------------------------------------------------  // acclient.c:772829
void _E116_5()
{
  MAX_QUANTUM_32 = 1.0 / 5.0;
}

//----- (006F0AA0) --------------------------------------------------------  // acclient.c:772835
void _E118_33()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_67, PFID_A8R8G8B8);
}

//----- (006F0AB0) --------------------------------------------------------  // acclient.c:772841
int _E120_21()
{
  return atexit(nullsub_919);
}

//----- (006F0AC0) --------------------------------------------------------  // acclient.c:772847
int sub_6F0AC0()
{
  return atexit(nullsub_920);
}

//----- (00760D00) --------------------------------------------------------  // acclient.c:888606
void __cdecl _E107_74()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00760D30) --------------------------------------------------------  // acclient.c:888619
void __cdecl sub_760D30()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_27.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_27.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

