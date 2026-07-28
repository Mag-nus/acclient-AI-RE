/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmHouseUI
   Object     : GAME\game_ui_misc\gmHouseUI.obj
   Functions  : 44
   Addresses  : 004A25A0 - 006F0C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A25A0) --------------------------------------------------------  // acclient.c:218753
gmHouseUI *__thiscall gmHouseUI::DynamicCast(gmHouseUI *this, unsigned int i_eType)
{
  gmHouseUI *result; // eax@1

  result = this;
  if ( i_eType != 268435493 )
    result = (gmHouseUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A25C0) --------------------------------------------------------  // acclient.c:218764
signed int gmHouseUI::GetUIElementType()
{
  return 268435493;
}

//----- (004A25D0) --------------------------------------------------------  // acclient.c:218770
UIElement *__usercall gmHouseUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x604u);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmHouseUI::vftable;
    *((_DWORD *)v3 + 382) = &gmHouseUI::vftable;
    *((_DWORD *)v3 + 383) = 0;
    *((_DWORD *)v3 + 384) = 0;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7AB268: using guessed type bool (__thiscall *gmHouseUI::vftable)(DBCache *this);
// 7AB510: using guessed type int (__thiscall *gmHouseUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A2630) --------------------------------------------------------  // acclient.c:218797
void __thiscall HousePayment::HousePayment(HousePayment *this)
{
  HousePayment *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&HousePayment::vftable;
  this->wcid.id = stru_83EB14.id;
  this->num = 0;
  this->paid = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->pname.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
}
// 7AB648: using guessed type int (__thiscall *HousePayment::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A2680) --------------------------------------------------------  // acclient.c:218819
void __thiscall HousePayment::~HousePayment(HousePayment *this)
{
  HousePayment *v1; // edi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@4

  v1 = this;
  v2 = this->pname.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004A26D0) --------------------------------------------------------  // acclient.c:218837
UIElement_Field *__thiscall gmHouseUI::scalar_deleting_destructor(gmHouseUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmHouseUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&gmHouseUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7AB268: using guessed type bool (__thiscall *gmHouseUI::vftable)(DBCache *this);
// 7AB510: using guessed type int (__thiscall *gmHouseUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A2710) --------------------------------------------------------  // acclient.c:218858
void __thiscall gmHouseUI::PostInit(gmHouseUI *this)
{
  gmHouseUI *v1; // edi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  GlobalEventHandler *v4; // esi@4
  int v5; // edi@4

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x100001E6u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)5);
  else
    v3 = 0;
  v1->m_pTextBox = (UIElement_ListBox *)v3;
  v4 = GlobalEventHandler::GetGlobalEventHandler();
  v5 = (int)&v1->vfptr;
  v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, (unsigned int)&byte_4DD225, (NoticeHandler *)v5);
  v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, (unsigned int)&byte_4DD226, (NoticeHandler *)v5);
  v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, (unsigned int)&byte_4DD227, (NoticeHandler *)v5);
  v4->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v4, (unsigned int)&byte_4DD228, (NoticeHandler *)v5);
}
// 4DD225: using guessed type char byte_4DD225;
// 4DD226: using guessed type char byte_4DD226;
// 4DD227: using guessed type char byte_4DD227;
// 4DD228: using guessed type char byte_4DD228;

//----- (004A2790) --------------------------------------------------------  // acclient.c:218887
void __cdecl gmHouseUI::Register()
{
  UIElement::RegisterElementClass(0x10000025u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmHouseUI::Create);
}

//----- (004A27B0) --------------------------------------------------------  // acclient.c:218893
char __thiscall gmHouseUI::GetHouseLocation(gmHouseUI *this, int *io_px, int *io_py)
{
  gmHouseUI *v3; // esi@1
  HouseData *v4; // eax@1
  unsigned int v6; // eax@5

  *io_px = -1;
  v3 = this;
  *io_py = -1;
  v4 = this->m_pHouseData;
  if ( !v4 )
    return 0;
  if ( v4->m_type != 4 )
  {
    if ( !Position::IsValid(&v4->m_pos) )
      return 0;
    v6 = Position::get_outside_cell_id(&v3->m_pHouseData->m_pos);
    LandDefs::gid_to_lcoord(v6, io_px, io_py);
  }
  return 1;
}

//----- (004A2810) --------------------------------------------------------  // acclient.c:218916
void __thiscall gmHouseUI::AddHousePanelText(gmHouseUI *this, PStringBase<unsigned short> *i_strText, HousePanelTextColor i_eColorType)
{
  UIElement_ListBox *v3; // ecx@1
  int v4; // eax@2
  UIElement *v5; // eax@3
  UIElement_Text *v6; // esi@3

  v3 = this->m_pTextBox;
  if ( v3 )
  {
    v4 = UIElement_ListBox::AddItemFromTemplateList(v3, 0, 0);
    if ( v4 )
    {
      v5 = (UIElement *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v4 + 148))(v4, 12);
      v6 = (UIElement_Text *)v5;
      if ( v5 )
      {
        UIElement::SetAttribute_Bool(v5, 0x29u, 1);
        UIElement_Text::SetTextWithFont(v6, i_strText, 0, i_eColorType);
      }
    }
  }
}

//----- (004A2860) --------------------------------------------------------  // acclient.c:218941
AC1Legacy::PStringBase<char> *__thiscall AC1Legacy::PStringBase<char>::operator+(AC1Legacy::PStringBase<char> *this, AC1Legacy::PStringBase<char> *result, AC1Legacy::PStringBase<char> *rhs)
{
  int v3; // edi@1
  volatile LONG *v4; // esi@1
  AC1Legacy::PStringBase<char> *v5; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v6; // esi@4
  AC1Legacy::PStringBase<char> retstr; // [sp+10h] [bp-4h]@1

  v3 = AC1Legacy::PStringBase<char>::s_NullBuffer;
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v5 = this;
  retstr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( !InterlockedDecrement(v4) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  AC1Legacy::PStringBase<char>::allocate_ref_buffer(&retstr, rhs->m_buffer->m_len + v5->m_buffer->m_len - 2);
  v6 = retstr.m_buffer;
  strcpy(retstr.m_buffer->m_data, v5->m_buffer->m_data);
  strcpy((char *)&v6->m_hash + v5->m_buffer->m_len + 3, rhs->m_buffer->m_data);
  result->m_buffer = v6;
  InterlockedIncrement((volatile LONG *)&v6->m_cRef);
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A2910) --------------------------------------------------------  // acclient.c:218969
HousePayment *__thiscall HousePayment::scalar_deleting_destructor(HousePayment *this, unsigned int a2)
{
  HousePayment *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@4

  v2 = this;
  v3 = this->pname.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = v2->name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004A2970) --------------------------------------------------------  // acclient.c:218990
int __thiscall PackableList<HousePayment>::RemoveHead(PackableList<HousePayment> *this, HousePayment *retVal)
{
  PackableList<HousePayment> *v2; // ebx@1
  int v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // edi@7
  int v7; // edi@10

  v2 = this;
  v3 = (int)this->head;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 24);
    this->head = (PackableLLNode<HousePayment> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 28) = 0;
    else
      this->tail = 0;
    HousePayment::operator=((int)retVal, v3);
    if ( v3 )
    {
      v6 = *(_DWORD *)(v3 + 20);
      if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = *(_DWORD *)(v3 + 16);
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
      {
        if ( v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      }
      *(_DWORD *)v3 = &PackObj::vftable;
      operator delete((void *)v3);
    }
    --v2->curNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (004A2A10) --------------------------------------------------------  // acclient.c:219036
void __thiscall PackableList<HousePayment>::Flush(PackableList<HousePayment> *this)
{
  PackableList<HousePayment> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@3
  AC1Legacy::PSRefBuffer<char> *v3; // esi@6
  HousePayment dummyData; // [sp+8h] [bp-18h]@1

  dummyData.wcid.id = stru_83EB14.id;
  dummyData.name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v1 = this;
  dummyData.vfptr = (PackObjVtbl *)&HousePayment::vftable;
  dummyData.num = 0;
  dummyData.paid = 0;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  dummyData.pname.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  while ( v1->head )
    PackableList<HousePayment>::RemoveHead(v1, &dummyData);
  v2 = dummyData.pname.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&dummyData.pname.m_buffer->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = dummyData.name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&dummyData.name.m_buffer->m_cRef) )
  {
    if ( v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  }
}
// 7AB648: using guessed type int (__thiscall *HousePayment::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A2AC0) --------------------------------------------------------  // acclient.c:219068
PackableList<HousePayment> *__thiscall PackableList<HousePayment>::operator=(PackableList<HousePayment> *this, int a2)
{
  PackableList<HousePayment> *v2; // edi@1
  int i; // ebx@1
  HousePayment *v4; // eax@2
  HousePayment *v5; // esi@2
  unsigned int v6; // eax@7
  int v7; // ecx@8

  v2 = this;
  PackableList<HousePayment>::Flush(this);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 24) )
  {
    v4 = (HousePayment *)operator new(0x20u);
    v5 = v4;
    if ( v4 )
    {
      HousePayment::HousePayment(v4, (HousePayment *)i);
      v5[1].vfptr = 0;
      v5[1].wcid.id = 0;
    }
    else
    {
      v5 = 0;
    }
    if ( v2->head )
    {
      v6 = (unsigned int)v2->tail;
      *(_DWORD *)(v6 + 24) = v5;
      v5[1].wcid.id = v6;
    }
    else
    {
      v2->head = (PackableLLNode<HousePayment> *)v5;
    }
    v7 = v2->curNum + 1;
    v2->tail = (PackableLLNode<HousePayment> *)v5;
    v2->curNum = v7;
    if ( !i )
      break;
  }
  return v2;
}

//----- (004A2B30) --------------------------------------------------------  // acclient.c:219113
void __thiscall gmHouseUI::DisplayBuyPayment(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  UIElement_ListBox *v2; // ecx@4
  PStringBase<unsigned short> *v3; // eax@4
  PStringBase<unsigned short> *v4; // edi@4
  int v5; // eax@5
  UIElement *v6; // eax@6
  UIElement_Text *v7; // esi@6
  char *v8; // esi@8
  AC1Legacy::PSRefBuffer<char> *v9; // esi@11
  AC1Legacy::PStringBase<char> strText; // [sp+8h] [bp-8h]@1
  PStringBase<unsigned short> v11; // [sp+Ch] [bp-4h]@4

  strText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v1 = this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  if ( v1->m_pHouseData )
  {
    AC1Legacy::PStringBase<char>::set(&strText, "The purchase price for this dwelling is:\n");
    HousePaymentList::ComposeText(&v1->m_pHouseData->m_buy, &strText);
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(&strText, "You do not currently own a house.");
  }
  PStringBase<unsigned short>::PStringBase<unsigned short>(&v11, 0, strText.m_buffer->m_data);
  v2 = v1->m_pTextBox;
  v4 = v3;
  if ( v2 )
  {
    v5 = UIElement_ListBox::AddItemFromTemplateList(v2, 0, 0);
    if ( v5 )
    {
      v6 = (UIElement *)(*(int (__thiscall **)(int, signed int))(*(_DWORD *)v5 + 148))(v5, 12);
      v7 = (UIElement_Text *)v6;
      if ( v6 )
      {
        UIElement::SetAttribute_Bool(v6, 0x29u, 1);
        UIElement_Text::SetTextWithFont(v7, v4, 0, 0);
      }
    }
  }
  v8 = (char *)&v11.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v11.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = strText.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&strText.m_buffer->m_cRef) )
  {
    if ( v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A2C20) --------------------------------------------------------  // acclient.c:219169
void __thiscall gmHouseUI::DisplayRentPayment(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  PStringBase<unsigned short> *v2; // eax@2
  char *v3; // esi@2
  AC1Legacy::PSRefBuffer<char> *v4; // esi@5
  AC1Legacy::PStringBase<char> strText; // [sp+4h] [bp-8h]@2
  PStringBase<unsigned short> v6; // [sp+8h] [bp-4h]@2

  v1 = this;
  if ( this->m_pHouseData )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&strText, "Rent:\n");
    HousePaymentList::ComposeText2(&v1->m_pHouseData->m_rent, &strText);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v6, 0, strText.m_buffer->m_data);
    gmHouseUI::AddHousePanelText(v1, v2, 0);
    v3 = (char *)&v6.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v6.m_charbuffer[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
    v4 = strText.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strText.m_buffer->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
  }
}

//----- (004A2CC0) --------------------------------------------------------  // acclient.c:219198
void __thiscall gmHouseUI::DisplayBuyTime(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  PStringBase<unsigned short> *v2; // eax@2
  char *v3; // esi@2
  AC1Legacy::PSRefBuffer<char> *v4; // esi@5
  AC1Legacy::PStringBase<char> strText; // [sp+4h] [bp-8h]@2
  PStringBase<unsigned short> v6; // [sp+8h] [bp-4h]@2

  v1 = this;
  if ( this->m_pHouseData )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&strText, "Bought: ");
    HouseSystem::ConvertTime(v1->m_pHouseData->m_buy_time, &strText);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v6, 0, strText.m_buffer->m_data);
    gmHouseUI::AddHousePanelText(v1, v2, 0);
    v3 = (char *)&v6.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v6.m_charbuffer[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
    v4 = strText.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strText.m_buffer->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    }
  }
}

//----- (004A2D60) --------------------------------------------------------  // acclient.c:219227
void __thiscall gmHouseUI::DisplayRentTimes(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  double v2; // st7@2
  PStringBase<unsigned short> *v3; // eax@2
  char *v4; // edi@2
  HouseData *v5; // eax@5
  double v6; // st7@7
  double v7; // st7@8
  PStringBase<unsigned short> *v8; // eax@9
  char *v9; // esi@9
  AC1Legacy::PSRefBuffer<char> *v10; // esi@12
  AC1Legacy::PSRefBuffer<char> *v11; // esi@15
  AC1Legacy::PStringBase<char> *v12; // [sp-8h] [bp-1Ch]@7
  AC1Legacy::PStringBase<char> strRentText; // [sp+8h] [bp-Ch]@5
  AC1Legacy::PStringBase<char> strMaintenanceText; // [sp+Ch] [bp-8h]@2
  PStringBase<unsigned short> v15; // [sp+10h] [bp-4h]@2

  v1 = this;
  if ( this->m_pHouseData )
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&strMaintenanceText, "This maintenance period ends: ");
    v2 = HouseSystem::GetRentPeriod(&v1->m_pHouseData->m_type) + (double)v1->m_pHouseData->m_rent_time;
    HouseSystem::ConvertTime((unsigned __int64)v2, &strMaintenanceText);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, 0, strMaintenanceText.m_buffer->m_data);
    gmHouseUI::AddHousePanelText(v1, v3, 0);
    v4 = (char *)&v15.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1].m_data[8]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&strRentText, "Maintenance is next due: ");
    v5 = v1->m_pHouseData;
    if ( v5->m_maintenance_free || HousePaymentList::IsPaidInFull(&v5->m_rent) )
    {
      v12 = &strRentText;
      v7 = HouseSystem::GetRentPeriod(&v1->m_pHouseData->m_type);
      v6 = v7 + v7;
    }
    else
    {
      v12 = &strRentText;
      v6 = HouseSystem::GetRentPeriod(&v1->m_pHouseData->m_type);
    }
    HouseSystem::ConvertTime((unsigned __int64)(v6 + (double)v1->m_pHouseData->m_rent_time), v12);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v15, 0, strRentText.m_buffer->m_data);
    gmHouseUI::AddHousePanelText(v1, v8, 0);
    v9 = (char *)&v15.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    v10 = strRentText.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strRentText.m_buffer->m_cRef) && v10 )
      v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    v11 = strMaintenanceText.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strMaintenanceText.m_buffer->m_cRef) )
    {
      if ( v11 )
        v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
    }
  }
}

//----- (004A2EE0) --------------------------------------------------------  // acclient.c:219288
void __thiscall gmHouseUI::DisplayLocation(gmHouseUI *this)
{
  gmHouseUI *v1; // ebx@1
  int v2; // esi@2
  AC1Legacy::PSRefBuffer<char> *v3; // edi@3
  int v4; // ecx@4
  int v5; // eax@6
  unsigned __int64 v6; // st7@8
  AC1Legacy::PSRefBuffer<char> *v7; // edi@8
  PStringBase<unsigned short> *v8; // eax@8
  char *v9; // esi@8
  int worldLocX; // [sp+24h] [bp-8h]@2
  AC1Legacy::PStringBase<char> strText; // [sp+28h] [bp-4h]@2

  v1 = this;
  if ( this->m_pHouseData )
  {
    worldLocX = -1;
    strText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)-1;
    gmHouseUI::GetHouseLocation(this, &worldLocX, (int *)&strText);
    v2 = worldLocX;
    if ( worldLocX != -1 )
    {
      v3 = strText.m_buffer;
      if ( strText.m_buffer != (AC1Legacy::PSRefBuffer<char> *)-1 )
      {
        strText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
        v4 = (int)"E";
        if ( v2 < 1024 )
          v4 = (int)"W";
        v5 = (int)"N";
        if ( (signed int)v3 < 1024 )
          v5 = (int)"S";
        worldLocX = (int)&v3[-43].m_len;
        *(double *)&v6 = fabs((double)(signed int)&v3[-43].m_len * 0.1 + 0.5);
        AC1Legacy::PStringBase<char>::sprintf(
          &strText,
          "Location: %.1f%s, %.1f%s",
          v6,
          v6 >> 32,
          v5,
          fabs((double)(v2 - 1024) * 0.1 + 0.5),
          v4);
        v7 = strText.m_buffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (PStringBase<unsigned short> *)&strText,
          0,
          strText.m_buffer->m_data);
        gmHouseUI::AddHousePanelText(v1, v8, 0);
        v9 = (char *)&strText.m_buffer[-1].m_cRef;
        if ( !InterlockedDecrement((volatile LONG *)&strText.m_buffer[-1].m_cRef + 1) && v9 )
          (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
        if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) )
        {
          if ( v7 )
            v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
        }
      }
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A3020) --------------------------------------------------------  // acclient.c:219353
void __thiscall gmHouseUI::DisplayWarningText(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  HouseData *v2; // eax@2
  PStringBase<unsigned short> *v3; // eax@4
  char *v4; // esi@4
  PStringBase<unsigned short> *v5; // eax@5
  AC1Legacy::PSRefBuffer<char> *v6; // esi@9
  volatile LONG *v7; // [sp-8h] [bp-14h]@4
  AC1Legacy::PStringBase<char> strText; // [sp+4h] [bp-8h]@2
  PStringBase<unsigned short> v9; // [sp+8h] [bp-4h]@4

  v1 = this;
  if ( this->m_pHouseData )
  {
    strText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    v2 = v1->m_pHouseData;
    if ( v2->m_maintenance_free || HousePaymentList::IsPaidInFull(&v2->m_rent) )
    {
      AC1Legacy::PStringBase<char>::set(
        &strText,
        "The maintenance has already been paid for this period. You may not prepay next period's maintenance.");
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v9, 0, strText.m_buffer->m_data);
      gmHouseUI::AddHousePanelText(v1, v5, RentPaid_HousePanelTextColor);
      v4 = (char *)&v9.m_charbuffer[-1].m_data[6];
      v7 = (volatile LONG *)&v9.m_charbuffer[-1].m_data[8];
    }
    else
    {
      HouseSystem::ConstructRentWarningMessage(&v1->m_pHouseData->m_type, &strText);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v9, 0, strText.m_buffer->m_data);
      gmHouseUI::AddHousePanelText(v1, v3, RentNotPaid_HousePanelTextColor);
      v4 = (char *)&v9.m_charbuffer[-1].m_data[6];
      v7 = (volatile LONG *)&v9.m_charbuffer[-1].m_data[8];
    }
    if ( !InterlockedDecrement(v7) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    v6 = strText.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&strText.m_buffer->m_cRef) )
    {
      if ( v6 )
        v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A3110) --------------------------------------------------------  // acclient.c:219402
void __thiscall gmHouseUI::DisplayPurchaseTimeText(gmHouseUI *this)
{
  InterfaceSystem *v1; // eax@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  int v3; // edi@3
  PlayerDesc *v4; // ecx@5
  struct tm *v5; // eax@11
  AC1Legacy::PStringBase<char> *v6; // eax@11
  AC1Legacy::PStringBase<char> *v7; // eax@11
  AC1Legacy::PStringBase<unsigned short> *v8; // eax@11
  AC1Legacy::PSRefBuffer<char> *v9; // esi@11
  AC1Legacy::PSRefBuffer<char> *v10; // esi@14
  unsigned int v11; // esi@17
  AC1Legacy::PSRefBuffer<char> *v12; // esi@20
  AC1Legacy::PSRefBuffer<char> *v13; // esi@23
  AC1Legacy::PSRefBuffer<char> *v14; // edi@26
  PStringBase<unsigned short> *v15; // eax@26
  unsigned int v16; // esi@26
  int v17; // [sp-4h] [bp-440h]@1
  AC1Legacy::PStringBase<char> strText; // [sp+14h] [bp-428h]@1
  int purchase_time; // [sp+18h] [bp-424h]@7
  TResult result; // [sp+1Ch] [bp-420h]@1
  gmHouseUI *v21; // [sp+20h] [bp-41Ch]@1
  AC1Legacy::PStringBase<char> v22; // [sp+24h] [bp-418h]@3
  AC1Legacy::PStringBase<char> v23; // [sp+28h] [bp-414h]@11
  AC1Legacy::PStringBase<char> rhs; // [sp+2Ch] [bp-410h]@11
  InterfacePtr<PlayerDesc> spPlayerDesc; // [sp+30h] [bp-40Ch]@1
  AC1Legacy::PStringBase<char> v26; // [sp+38h] [bp-404h]@11
  char time[1024]; // [sp+3Ch] [bp-400h]@11

  v21 = this;
  strText.m_buffer = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::GetClass(v1, &result, &PlayerDesc_ClassType_4, (Interface **)&strText);
  v17 = (int)strText.m_buffer;
  v2 = strText.m_buffer;
  spPlayerDesc.m_pInterface = 0;
  spPlayerDesc.m_trStatus.m_val = 0;
  if ( strText.m_buffer )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))strText.m_buffer->vfptr[4].__vecDelDtor)(strText.m_buffer);
  v3 = *(_DWORD *)InterfacePtr<PlayerDesc>::_QueryInterface(&spPlayerDesc, (int)&v22, v17, 0);
  if ( v2 )
    ((void (__thiscall *)(AC1Legacy::PSRefBuffer<char> *))v2->vfptr[5].__vecDelDtor)(v2);
  v4 = spPlayerDesc.m_pInterface;
  if ( (_DWORD)spPlayerDesc.m_pInterface )
  {
    if ( v3 >= 0 )
    {
      purchase_time = 0;
      CBaseQualities::InqInt((CBaseQualities *)&spPlayerDesc.m_pInterface->vfptr, 0xC7u, &purchase_time, 0, 0);
      strText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      if ( HouseSystem::HasPurchaseWaitPeriodExpired(purchase_time) )
      {
        if ( v21->m_pHouseData )
          AC1Legacy::PStringBase<char>::set(
            &strText,
            "You may buy another house immediately after you abandon this one.");
        else
          AC1Legacy::PStringBase<char>::set(&strText, "You may buy another house immediately.");
      }
      else
      {
        purchase_time += 2592000;
        v5 = _localtime(&purchase_time);
        _strftime(time, 0x400u, "%c", v5);
        AC1Legacy::PStringBase<char>::PStringBase<char>(&v23, ". This restriction does not apply to apartments.");
        AC1Legacy::PStringBase<char>::PStringBase<char>(&rhs, time);
        AC1Legacy::PStringBase<char>::PStringBase<char>(
          (AC1Legacy::PStringBase<char> *)&result,
          "You may buy another landscape house at ");
        v7 = AC1Legacy::PStringBase<char>::operator+(v6, &v22, &rhs);
        v8 = (AC1Legacy::PStringBase<unsigned short> *)AC1Legacy::PStringBase<char>::operator+(v7, &v26, &v23);
        AC1Legacy::PStringBase<unsigned short>::operator=((AC1Legacy::PStringBase<unsigned short> *)&strText, v8);
        v9 = v26.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v26.m_buffer->m_cRef) && v9 )
          v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
        v10 = v22.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v22.m_buffer->m_cRef) && v10 )
          v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
        v11 = result.m_val;
        if ( !InterlockedDecrement((volatile LONG *)(result.m_val + 4)) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
        v12 = rhs.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&rhs.m_buffer->m_cRef) && v12 )
          v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
        v13 = v23.m_buffer;
        if ( !InterlockedDecrement((volatile LONG *)&v23.m_buffer->m_cRef) && v13 )
          v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
      }
      v14 = strText.m_buffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        (PStringBase<unsigned short> *)&result,
        0,
        strText.m_buffer->m_data);
      gmHouseUI::AddHousePanelText(v21, v15, 0);
      v16 = result.m_val - 20;
      if ( !InterlockedDecrement((volatile LONG *)(result.m_val - 20 + 4)) && v16 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
      if ( !InterlockedDecrement((volatile LONG *)&v14->m_cRef) )
      {
        if ( v14 )
          v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
      }
      v4 = spPlayerDesc.m_pInterface;
    }
    ((void (*)(void))v4->vfptr->Release)();
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004A3380) --------------------------------------------------------  // acclient.c:219514
void __thiscall gmHouseUI::DisplayHouseData(gmHouseUI *this)
{
  gmHouseUI *v1; // esi@1
  UIElement_ListBox *v2; // ecx@1

  v1 = this;
  v2 = this->m_pTextBox;
  if ( v2 )
  {
    UIElement_ListBox::Flush(v2);
    gmHouseUI::DisplayBuyPayment(v1);
    gmHouseUI::DisplayRentPayment(v1);
    gmHouseUI::DisplayBuyTime(v1);
    gmHouseUI::DisplayRentTimes(v1);
    gmHouseUI::DisplayLocation(v1);
    gmHouseUI::DisplayWarningText(v1);
    gmHouseUI::DisplayPurchaseTimeText(v1);
  }
}

//----- (004A33D0) --------------------------------------------------------  // acclient.c:219535
char __thiscall gmHouseUI::Update(gmHouseUI *this, HouseData *i_houseData)
{
  gmHouseUI *v2; // esi@1
  int v3; // ecx@1
  HouseData *v4; // eax@2
  HouseData *v5; // eax@3
  UIElement_ListBox *v7; // ecx@8

  v2 = this;
  v3 = (int)this->m_pHouseData;
  if ( v3 )
  {
    HouseData::operator=(v3, (int)i_houseData);
  }
  else
  {
    v4 = (HouseData *)operator new(0x7Cu);
    if ( v4 )
      HouseData::HouseData(v4, i_houseData);
    else
      v5 = 0;
    v2->m_pHouseData = v5;
    if ( !v5 )
      return 0;
  }
  v7 = v2->m_pTextBox;
  if ( v7 )
  {
    UIElement_ListBox::Flush(v7);
    gmHouseUI::DisplayBuyPayment(v2);
    gmHouseUI::DisplayRentPayment(v2);
    gmHouseUI::DisplayBuyTime(v2);
    gmHouseUI::DisplayRentTimes(v2);
    gmHouseUI::DisplayLocation(v2);
    gmHouseUI::DisplayWarningText(v2);
    gmHouseUI::DisplayPurchaseTimeText(v2);
  }
  return 1;
}

//----- (004A3460) --------------------------------------------------------  // acclient.c:219576
char __thiscall gmHouseUI::Update(gmHouseUI *this, unsigned int i_eError)
{
  gmHouseUI *v2; // esi@1
  HouseData *v3; // ecx@1
  UIElement_ListBox *v4; // ecx@3

  v2 = this;
  v3 = this->m_pHouseData;
  if ( v3 )
  {
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->m_pHouseData = 0;
  }
  v4 = v2->m_pTextBox;
  if ( v4 )
  {
    UIElement_ListBox::Flush(v4);
    gmHouseUI::DisplayBuyPayment(v2);
    gmHouseUI::DisplayRentPayment(v2);
    gmHouseUI::DisplayBuyTime(v2);
    gmHouseUI::DisplayRentTimes(v2);
    gmHouseUI::DisplayLocation(v2);
    gmHouseUI::DisplayWarningText(v2);
    gmHouseUI::DisplayPurchaseTimeText(v2);
  }
  return 1;
}

//----- (004A34D0) --------------------------------------------------------  // acclient.c:219605
void __thiscall gmHouseUI::RecvNotice_UpdateHouseData(gmHouseUI *this, HouseData *i_houseData)
{
  gmHouseUI::Update((gmHouseUI *)((char *)this - 1528), i_houseData);
}

//----- (004A34E0) --------------------------------------------------------  // acclient.c:219611
void __thiscall gmHouseUI::RecvNotice_FailedHouseTransaction(gmHouseUI *this, unsigned int i_eType)
{
  gmHouseUI::Update((gmHouseUI *)((char *)this - 1528), i_eType);
}

//----- (004A34F0) --------------------------------------------------------  // acclient.c:219617
void __thiscall gmHouseUI::RecvNotice_UpdateRentTime(gmHouseUI *this, int i_rentTime)
{
  HashSet<UIElement *>Vtbl *v2; // eax@1
  char *v3; // esi@1

  v2 = this->m_hashElementsRegisteredWith.vfptr;
  v3 = (char *)this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets;
  if ( v2 )
  {
    v2[2].__vecDelDtor = (void *(__thiscall *)(HashSet<UIElement *> *, unsigned int))i_rentTime;
    HousePaymentList::ClearPayment((HousePaymentList *)(*((_DWORD *)v3 + 383) + 28));
    gmHouseUI::DisplayHouseData((gmHouseUI *)v3);
  }
}

//----- (004A3520) --------------------------------------------------------  // acclient.c:219633
void __thiscall gmHouseUI::RecvNotice_UpdateRentPayment(gmHouseUI *this, HousePaymentList *i_rent)
{
  HashSet<UIElement *>Vtbl *v2; // eax@1
  gmHouseUI *v3; // esi@1

  v2 = this->m_hashElementsRegisteredWith.vfptr;
  v3 = (gmHouseUI *)((char *)this - 1528);
  if ( v2 )
  {
    PackableList<HousePayment>::operator=((PackableList<HousePayment> *)&v2[7], (int)i_rent);
    gmHouseUI::DisplayHouseData(v3);
  }
}

//----- (006F0AD0) --------------------------------------------------------  // acclient.c:772853
void _E91_68()
{
  outside_val_60 = 1000.0 + 1.0;
}

//----- (006F0AF0) --------------------------------------------------------  // acclient.c:772859
void _E93_44()
{
  block_length_60 = 24.0 * 8.0;
}

//----- (006F0B10) --------------------------------------------------------  // acclient.c:772865
void _E95_44()
{
  half_square_length_60 = 24.0 * 0.5;
}

//----- (006F0B30) --------------------------------------------------------  // acclient.c:772871
int _E97_69()
{
  return atexit(_E98_81);
}

//----- (006F0B40) --------------------------------------------------------  // acclient.c:772877
int _E100_62()
{
  return atexit(nullsub_917);
}

//----- (006F0B50) --------------------------------------------------------  // acclient.c:772883
int _E103_54()
{
  return atexit(_E104_69);
}

//----- (006F0B60) --------------------------------------------------------  // acclient.c:772889
void _E106_44()
{
  DEFAULT_VIEW_RADIUS_33 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F0B80) --------------------------------------------------------  // acclient.c:772895
void _E108_31()
{
  MIN_QUANTUM_33 = 1.0 / 30.0;
}

//----- (006F0BA0) --------------------------------------------------------  // acclient.c:772901
void _E110_22()
{
  MAX_QUANTUM_33 = 1.0 / 5.0;
}

//----- (006F0BC0) --------------------------------------------------------  // acclient.c:772907
void _E112_39()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_68, PFID_A8R8G8B8);
}

//----- (006F0BD0) --------------------------------------------------------  // acclient.c:772913
void _E115_27()
{
  LOWEST_DATA_RATE_74 = 1024;
}

//----- (006F0BE0) --------------------------------------------------------  // acclient.c:772919
void _E117_23()
{
  HIGHEST_DATA_RATE_74 = 0x7FFF;
}

//----- (006F0BF0) --------------------------------------------------------  // acclient.c:772925
int _E119_12()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_74;
  INITIAL_MAX_DATA_RATE_22 = LOWEST_DATA_RATE_74;
  return result;
}

//----- (006F0C00) --------------------------------------------------------  // acclient.c:772935
int _E121_35()
{
  return atexit(_E122_71);
}

//----- (006F0C10) --------------------------------------------------------  // acclient.c:772941
int sub_6F0C10()
{
  return atexit(nullsub_915);
}

