/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmJournalUI
   Object     : GAME\game_ui_misc\gmJournalUI.obj
   Functions  : 85
   Addresses  : 004949C0 - 0075FC20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004949C0) --------------------------------------------------------  // acclient.c:207276
long double __cdecl abs(long double _n)
{
  long double result; // st7@1

  result = _n;
  if ( _n < 0.0 )
    result = -_n;
  return result;
}

//----- (004949E0) --------------------------------------------------------  // acclient.c:207287
BOOL __cdecl PageInfoSortPageNumber(PageInfo *p1, PageInfo *p2)
{
  return p1->m_PageNumber < p2->m_PageNumber;
}

//----- (00494A00) --------------------------------------------------------  // acclient.c:207293
bool __cdecl PageInfoSortTimer(PageInfo *p1, PageInfo *p2)
{
  bool v2; // al@1
  bool result; // al@3

  v2 = p1->m_TimerRunning;
  if ( v2 )
  {
    if ( !p2->m_TimerRunning )
      return 1;
    if ( v2 )
      goto LABEL_13;
  }
  if ( p2->m_TimerRunning )
    return 0;
  if ( v2 || p2->m_TimerRunning )
LABEL_13:
    result = p1->m_TimerStamp < p2->m_TimerStamp;
  else
    result = p1->m_PageNumber < p2->m_PageNumber;
  return result;
}

//----- (00494A60) --------------------------------------------------------  // acclient.c:207317
bool __cdecl PageInfoReverseSortPageNumber(PageInfo *p1, PageInfo *p2)
{
  return p1->m_PageNumber > p2->m_PageNumber;
}

//----- (00494A80) --------------------------------------------------------  // acclient.c:207323
bool __cdecl PageInfoReverseSortTimer(PageInfo *p1, PageInfo *p2)
{
  bool v2; // al@1
  bool result; // al@3

  v2 = p1->m_TimerRunning;
  if ( v2 )
  {
    if ( !p2->m_TimerRunning )
      return 0;
    if ( v2 )
      goto LABEL_13;
  }
  if ( p2->m_TimerRunning )
    return 1;
  if ( v2 || p2->m_TimerRunning )
LABEL_13:
    result = p1->m_TimerStamp > p2->m_TimerStamp;
  else
    result = p1->m_PageNumber > p2->m_PageNumber;
  return result;
}

//----- (00494AE0) --------------------------------------------------------  // acclient.c:207347
void __thiscall gmJournalUI::ClearTimerText(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  UIElement_Text *v2; // ecx@1

  v1 = this;
  v2 = this->m_pDaysEditBox;
  LODWORD(v1->m_Info.m_TimerStamp) = 0;
  HIDWORD(v1->m_Info.m_TimerStamp) = 0;
  v1->m_Info.m_TimerRunning = 0;
  v1->m_Info.m_Minutes = 0;
  v1->m_Info.m_Hours = 0;
  v1->m_Info.m_Days = 0;
  UIElement_Text::ClearAllText(v2);
  UIElement_Text::ClearAllText(v1->m_pHoursEditBox);
  UIElement_Text::ClearAllText(v1->m_pMinutesEditBox);
}

//----- (00494B30) --------------------------------------------------------  // acclient.c:207366
bool __thiscall PStringBase<unsigned short>::operator!=(PStringBase<unsigned short> *this, PStringBase<unsigned short> *rhs)
{
  PSRefBufferCharData<unsigned short> *v2; // ecx@1
  int v3; // eax@2
  int v4; // esi@2
  int v5; // eax@5

  v2 = this->m_charbuffer;
  if ( *(_DWORD *)&v2[-1].m_data[14] == *(_DWORD *)&rhs->m_charbuffer[-1].m_data[14]
    && ((v3 = *(_DWORD *)&v2[-1].m_data[12], v4 = *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12], v3 == v4)
     || v3 == -1
     || v4 == -1) )
    v5 = _wcscmp(v2->m_data, rhs->m_charbuffer->m_data) != 0;
  else
    LOBYTE(v5) = 1;
  return v5;
}

//----- (00494B70) --------------------------------------------------------  // acclient.c:207385
void __thiscall PageInfo::PageInfo(PageInfo *this)
{
  PageInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  wchar_t *v5; // eax@1
  int v6; // ebp@2
  volatile LONG *v7; // ST00_4@5
  wchar_t *v8; // eax@6
  int v9; // ebp@7
  volatile LONG *v10; // ST00_4@10
  wchar_t *v11; // eax@11
  int v12; // ebp@12
  volatile LONG *v13; // ST00_4@15

  v1 = this;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_Label.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_Title.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_Notes.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = v1->m_Label.m_charbuffer->m_data;
  if ( (wchar_t *)v1->m_Label.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v6 = (int)(v5 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v5 - 4) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Label.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v7);
  }
  v8 = v1->m_Title.m_charbuffer->m_data;
  if ( v8 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v9 = (int)(v8 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v8 - 4) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Title.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v10);
  }
  v11 = v1->m_Notes.m_charbuffer->m_data;
  if ( v11 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v12 = (int)(v11 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v11 - 4) && v12 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    v13 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Notes.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v13);
  }
  v1->m_PageNumber = 0;
  LODWORD(v1->m_TimerStamp) = 0;
  HIDWORD(v1->m_TimerStamp) = 0;
  v1->m_Days = 0;
  v1->m_Hours = 0;
  v1->m_Minutes = 0;
  LODWORD(v1->m_xCoord) = 0;
  HIDWORD(v1->m_xCoord) = 0;
  LODWORD(v1->m_yCoord) = 0;
  HIDWORD(v1->m_yCoord) = 0;
  v1->m_TimerRunning = 0;
  v1->m_LocationSet = 0;
}

//----- (00494C90) --------------------------------------------------------  // acclient.c:207456
void __thiscall PageInfo::Clear(PageInfo *this)
{
  PageInfo *v1; // esi@1
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  wchar_t *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10
  wchar_t *v8; // eax@11
  int v9; // edi@12
  volatile LONG *v10; // ST00_4@15

  v1 = this;
  v2 = this->m_Label.m_charbuffer;
  if ( (wchar_t *)this->m_Label.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    v3 = (int)&v2[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1].m_data[8]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Label.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v4);
  }
  v5 = v1->m_Title.m_charbuffer->m_data;
  if ( v5 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v6 = (int)(v5 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v5 - 4) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Title.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v7);
  }
  v8 = v1->m_Notes.m_charbuffer->m_data;
  if ( v8 != PStringBase<unsigned short>::s_NullBuffer )
  {
    v9 = (int)(v8 - 10);
    if ( !InterlockedDecrement((volatile LONG *)v8 - 4) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
    v1->m_Notes.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement(v10);
  }
  v1->m_PageNumber = 0;
  LODWORD(v1->m_TimerStamp) = 0;
  HIDWORD(v1->m_TimerStamp) = 0;
  v1->m_Days = 0;
  v1->m_Hours = 0;
  v1->m_Minutes = 0;
  LODWORD(v1->m_xCoord) = 0;
  HIDWORD(v1->m_xCoord) = 0;
  LODWORD(v1->m_yCoord) = 0;
  HIDWORD(v1->m_yCoord) = 0;
  v1->m_TimerRunning = 0;
  v1->m_LocationSet = 0;
}

//----- (00494D70) --------------------------------------------------------  // acclient.c:207515
void __userpurge gmJournalUI::gmJournalUI(gmJournalUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmJournalUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmJournalUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pStartTimerButton = 0;
  v4->m_pLabelEditBox = 0;
  v4->m_pTitleEditBox = 0;
  v4->m_pNotesEditBox = 0;
  v4->m_pDaysEditBox = 0;
  v4->m_pHoursEditBox = 0;
  v4->m_pMinutesEditBox = 0;
  v4->m_pLocationStaticText = 0;
  v4->m_pTimerStaticText = 0;
  v4->m_pDaysStaticText = 0;
  v4->m_pHoursStaticText = 0;
  v4->m_pMinutesStaticText = 0;
  v4->m_pPageNumberStaticText = 0;
  v4->m_Loaded = 0;
  v4->m_CurrentPage = 0;
  PageInfo::PageInfo(&v4->m_Info);
  LODWORD(v4->m_timeNextUpdate) = 0;
  HIDWORD(v4->m_timeNextUpdate) = 0;
}
// 7A6420: using guessed type int (__thiscall *gmJournalUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00494E20) --------------------------------------------------------  // acclient.c:207547
gmJournalUI *__thiscall gmJournalUI::DynamicCast(gmJournalUI *this, unsigned int i_eType)
{
  gmJournalUI *result; // eax@1

  result = this;
  if ( i_eType != 268435528 )
    result = (gmJournalUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (00494E40) --------------------------------------------------------  // acclient.c:207558
signed int gmJournalUI::GetUIElementType()
{
  return 268435528;
}

//----- (00494E50) --------------------------------------------------------  // acclient.c:207564
void __thiscall gmJournalUI::~gmJournalUI(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  NoticeHandler *v2; // edi@1
  GlobalEventHandler *v3; // eax@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmJournalUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  UIListener::UnRegisterForGlobalMessage((UIListener *)&this->vfptr, 3u);
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  LookFile::~LookFile((LookFile *)&v1->m_Info);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7A6420: using guessed type int (__thiscall *gmJournalUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (00494EA0) --------------------------------------------------------  // acclient.c:207587
void __usercall gmJournalUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmJournalUI *v3; // eax@1

  v3 = (gmJournalUI *)operator new(0x680u);
  if ( v3 )
    gmJournalUI::gmJournalUI(v3, a1, _layout, _full_desc);
}

//----- (00494ED0) --------------------------------------------------------  // acclient.c:207597
bool __thiscall gmJournalUI::IsLastPage(gmJournalUI *this)
{
  return this->m_CurrentPage == g_JournalPages._M_finish - g_JournalPages._M_start;
}

//----- (00494EF0) --------------------------------------------------------  // acclient.c:207603
void __thiscall PageInfo::PageInfo(PageInfo *this, PageInfo *rhs)
{
  PageInfo *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  PSRefBufferCharData<unsigned short> *v6; // eax@1
  int v7; // ebp@2
  PSRefBufferCharData<unsigned short> *v8; // eax@5
  PSRefBufferCharData<unsigned short> *v9; // eax@6
  int v10; // ebp@7
  PSRefBufferCharData<unsigned short> *v11; // eax@10
  PSRefBufferCharData<unsigned short> *v12; // eax@11
  int v13; // ebp@12
  PSRefBufferCharData<unsigned short> *v14; // eax@15

  v2 = this;
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  this->m_Label.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v2->m_Title.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v2->m_Notes.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v5);
  v6 = v2->m_Label.m_charbuffer;
  if ( v2->m_Label.m_charbuffer != rhs->m_Label.m_charbuffer )
  {
    v7 = (int)&v6[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = rhs->m_Label.m_charbuffer;
    v2->m_Label.m_charbuffer = rhs->m_Label.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
  }
  v9 = v2->m_Title.m_charbuffer;
  if ( v9 != rhs->m_Title.m_charbuffer )
  {
    v10 = (int)&v9[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v9[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    v11 = rhs->m_Title.m_charbuffer;
    v2->m_Title.m_charbuffer = v11;
    InterlockedIncrement((volatile LONG *)&v11[-1].m_data[8]);
  }
  v12 = v2->m_Notes.m_charbuffer;
  if ( v12 != rhs->m_Notes.m_charbuffer )
  {
    v13 = (int)&v12[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v12[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v14 = rhs->m_Notes.m_charbuffer;
    v2->m_Notes.m_charbuffer = v14;
    InterlockedIncrement((volatile LONG *)&v14[-1].m_data[8]);
  }
  v2->m_PageNumber = rhs->m_PageNumber;
  v2->m_TimerRunning = rhs->m_TimerRunning;
  v2->m_TimerStamp = rhs->m_TimerStamp;
  v2->m_Days = rhs->m_Days;
  v2->m_Hours = rhs->m_Hours;
  v2->m_Minutes = rhs->m_Minutes;
  v2->m_LocationSet = rhs->m_LocationSet;
  v2->m_xCoord = rhs->m_xCoord;
  v2->m_yCoord = rhs->m_yCoord;
}

//----- (00495020) --------------------------------------------------------  // acclient.c:207671
void *__thiscall PageInfo::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // ebx@7
  int v8; // eax@10
  int v9; // eax@11
  int v10; // ebx@12
  int v11; // eax@15

  v2 = this;
  v3 = *(_DWORD *)this;
  if ( *(_DWORD *)this != *(_DWORD *)a2 )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)a2;
    *(_DWORD *)v2 = *(_DWORD *)a2;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *((_DWORD *)v2 + 1);
  if ( v6 != *(_DWORD *)(a2 + 4) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 4);
    *((_DWORD *)v2 + 1) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  v9 = *((_DWORD *)v2 + 2);
  if ( v9 != *(_DWORD *)(a2 + 8) )
  {
    v10 = v9 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v9 - 20 + 4)) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    v11 = *(_DWORD *)(a2 + 8);
    *((_DWORD *)v2 + 2) = v11;
    InterlockedIncrement((volatile LONG *)(v11 - 16));
  }
  *((_DWORD *)v2 + 3) = *(_DWORD *)(a2 + 12);
  *((_BYTE *)v2 + 16) = *(_BYTE *)(a2 + 16);
  *((_DWORD *)v2 + 6) = *(_DWORD *)(a2 + 24);
  *((_DWORD *)v2 + 7) = *(_DWORD *)(a2 + 28);
  *((_DWORD *)v2 + 8) = *(_DWORD *)(a2 + 32);
  *((_DWORD *)v2 + 9) = *(_DWORD *)(a2 + 36);
  *((_DWORD *)v2 + 10) = *(_DWORD *)(a2 + 40);
  *((_BYTE *)v2 + 44) = *(_BYTE *)(a2 + 44);
  *((_DWORD *)v2 + 12) = *(_DWORD *)(a2 + 48);
  *((_DWORD *)v2 + 13) = *(_DWORD *)(a2 + 52);
  *((_DWORD *)v2 + 14) = *(_DWORD *)(a2 + 56);
  *((_DWORD *)v2 + 15) = *(_DWORD *)(a2 + 60);
  return v2;
}

//----- (00495110) --------------------------------------------------------  // acclient.c:207731
gmJournalUI *__thiscall gmJournalUI::scalar_deleting_destructor(gmJournalUI *this, unsigned int a2)
{
  gmJournalUI *v2; // esi@1

  v2 = this;
  gmJournalUI::~gmJournalUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00495130) --------------------------------------------------------  // acclient.c:207743
void __cdecl gmJournalUI::Register()
{
  UIElement::RegisterElementClass(0x10000048u, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmJournalUI::Create);
}

//----- (00495150) --------------------------------------------------------  // acclient.c:207749
int __thiscall gmJournalUI::ResetTimer(gmJournalUI *this)
{
  const wchar_t *v1; // esi@1
  gmJournalUI *v2; // edi@1
  PStringBase<unsigned short> *v3; // ebx@1
  int v4; // esi@2
  char *v5; // ebx@6
  unsigned __int32 v6; // eax@9
  UIElement_Text *v7; // ecx@9
  PStringBase<unsigned short> *v8; // ebx@9
  int v9; // esi@10
  char *v10; // ebx@14
  unsigned __int32 v11; // eax@17
  UIElement_Text *v12; // ecx@17
  PStringBase<unsigned short> *v13; // ebx@17
  int v14; // esi@18
  char *v15; // ebx@22
  unsigned __int32 v16; // eax@25
  int v17; // edx@25
  int v18; // ecx@25
  int v19; // esi@25
  long double v20; // st7@25
  PStringBase<unsigned short> result; // [sp+10h] [bp-10h]@1
  PStringBase<unsigned short> v23; // [sp+14h] [bp-Ch]@9
  PStringBase<unsigned short> v24; // [sp+18h] [bp-8h]@17
  int v25; // [sp+1Ch] [bp-4h]@25

  v1 = PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v3 = UIElement_Text::GetText(v2->m_pDaysEditBox, &result);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v3->m_charbuffer )
  {
    v4 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v1 = v3->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v3->m_charbuffer[-1].m_data[8]);
  }
  v5 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  *__errno() = 0;
  v6 = _wcstoul(v1, 0, 0);
  v7 = v2->m_pHoursEditBox;
  v2->m_Info.m_Days = v6;
  v8 = UIElement_Text::GetText(v7, &v23);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v8->m_charbuffer )
  {
    v9 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v1 = v8->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v8->m_charbuffer[-1].m_data[8]);
  }
  v10 = (char *)&v23.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v23.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  *__errno() = 0;
  v11 = _wcstoul(v1, 0, 0);
  v12 = v2->m_pMinutesEditBox;
  v2->m_Info.m_Hours = v11;
  v13 = UIElement_Text::GetText(v12, &v24);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v13->m_charbuffer )
  {
    v14 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
    v1 = v13->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v13->m_charbuffer[-1].m_data[8]);
  }
  v15 = (char *)&v24.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v24.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  *__errno() = 0;
  v16 = _wcstoul(v1, 0, 0);
  v17 = v2->m_Info.m_Hours;
  v18 = 86400 * v2->m_Info.m_Days;
  v2->m_Info.m_Minutes = v16;
  v19 = (int)(v1 - 10);
  v25 = 3600 * v17;
  v20 = (double)v18 + (double)(signed int)(60 * v16) + (double)(3600 * v17) + COERCE_DOUBLE(Timer::cur_time.Cmd);
  v2->m_Info.m_TimerRunning = 1;
  v2->m_Info.m_TimerStamp = v20;
  if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  return 0;
}

//----- (00495360) --------------------------------------------------------  // acclient.c:207839
void __thiscall gmJournalUI::SaveThisPage(gmJournalUI *this)
{
  const wchar_t *v1; // esi@1
  gmJournalUI *v2; // edi@1
  PStringBase<unsigned short> *v3; // eax@1
  PStringBase<unsigned short> *v4; // ebx@1
  PSRefBufferCharData<unsigned short> *v5; // ecx@1
  PSRefBufferCharData<unsigned short> *v6; // eax@1
  int v7; // ebp@2
  PSRefBufferCharData<unsigned short> *v8; // ebx@5
  char *v9; // ebx@6
  PStringBase<unsigned short> *v10; // eax@9
  PSRefBufferCharData<unsigned short> *v11; // ebx@9
  PSRefBufferCharData<unsigned short> **v12; // ebp@9
  int v13; // ebx@10
  PSRefBufferCharData<unsigned short> *v14; // eax@13
  char *v15; // ebx@14
  PStringBase<unsigned short> *v16; // eax@17
  PSRefBufferCharData<unsigned short> *v17; // ebx@17
  PSRefBufferCharData<unsigned short> **v18; // ebp@17
  int v19; // ebx@18
  PSRefBufferCharData<unsigned short> *v20; // eax@21
  char *v21; // ebx@22
  UIElement_Text *v22; // ecx@25
  PStringBase<unsigned short> *v23; // ebx@25
  int v24; // esi@26
  char *v25; // ebx@30
  unsigned __int32 v26; // eax@33
  UIElement_Text *v27; // ecx@33
  PStringBase<unsigned short> *v28; // ebx@33
  int v29; // esi@34
  char *v30; // ebx@38
  unsigned __int32 v31; // eax@41
  UIElement_Text *v32; // ecx@41
  PStringBase<unsigned short> *v33; // ebx@41
  int v34; // esi@42
  char *v35; // ebx@46
  unsigned int v36; // edi@49
  int v37; // esi@51
  int v38; // [sp+30h] [bp-10h]@1
  PStringBase<unsigned short> result; // [sp+34h] [bp-Ch]@1
  PStringBase<unsigned short> v40; // [sp+38h] [bp-8h]@33
  PStringBase<unsigned short> v41; // [sp+3Ch] [bp-4h]@41

  v1 = PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v3 = UIElement_Text::GetText(v2->m_pLabelEditBox, &result);
  v4 = v3;
  v5 = v3->m_charbuffer;
  v38 = (int)&v2->m_Info;
  v6 = v2->m_Info.m_Label.m_charbuffer;
  if ( v6 != v5 )
  {
    v7 = (int)&v6[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = v4->m_charbuffer;
    *(_DWORD *)v38 = v8;
    InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
  }
  v9 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = UIElement_Text::GetText(v2->m_pTitleEditBox, &result);
  v11 = v2->m_Info.m_Title.m_charbuffer;
  v12 = (PSRefBufferCharData<unsigned short> **)v10;
  if ( v11 != v10->m_charbuffer )
  {
    v13 = (int)&v11[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
    v14 = *v12;
    v2->m_Info.m_Title.m_charbuffer = *v12;
    InterlockedIncrement((volatile LONG *)&v14[-1].m_data[8]);
  }
  v15 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  v16 = UIElement_Text::GetText(v2->m_pNotesEditBox, &result);
  v17 = v2->m_Info.m_Notes.m_charbuffer;
  v18 = (PSRefBufferCharData<unsigned short> **)v16;
  if ( v17 != v16->m_charbuffer )
  {
    v19 = (int)&v17[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
    v20 = *v18;
    v2->m_Info.m_Notes.m_charbuffer = *v18;
    InterlockedIncrement((volatile LONG *)&v20[-1].m_data[8]);
  }
  v21 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  v22 = v2->m_pDaysEditBox;
  v2->m_Info.m_PageNumber = v2->m_CurrentPage;
  v23 = UIElement_Text::GetText(v22, &result);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v23->m_charbuffer )
  {
    v24 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v24 + 4)) && v24 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
    v1 = v23->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v23->m_charbuffer[-1].m_data[8]);
  }
  v25 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v25 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
  *__errno() = 0;
  v26 = _wcstoul(v1, 0, 0);
  v27 = v2->m_pHoursEditBox;
  v2->m_Info.m_Days = v26;
  v28 = UIElement_Text::GetText(v27, &v40);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v28->m_charbuffer )
  {
    v29 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v29 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
    v1 = v28->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v28->m_charbuffer[-1].m_data[8]);
  }
  v30 = (char *)&v40.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1].m_data[8]) && v30 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
  *__errno() = 0;
  v31 = _wcstoul(v1, 0, 0);
  v32 = v2->m_pMinutesEditBox;
  v2->m_Info.m_Hours = v31;
  v33 = UIElement_Text::GetText(v32, &v41);
  if ( (PSRefBufferCharData<unsigned short> *)v1 != v33->m_charbuffer )
  {
    v34 = (int)(v1 - 10);
    if ( !InterlockedDecrement((volatile LONG *)(v34 + 4)) && v34 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v34)(v34, 1);
    v1 = v33->m_charbuffer->m_data;
    InterlockedIncrement((volatile LONG *)&v33->m_charbuffer[-1].m_data[8]);
  }
  v35 = (char *)&v41.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1].m_data[8]) && v35 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v35)(v35, 1);
  *__errno() = 0;
  v2->m_Info.m_Minutes = _wcstoul(v1, 0, 0);
  v36 = v2->m_CurrentPage;
  if ( v36 <= g_JournalPages._M_finish - g_JournalPages._M_start )
    PageInfo::operator=(&g_JournalPages._M_start[v36 - 1], v38);
  v37 = (int)(v1 - 10);
  if ( !InterlockedDecrement((volatile LONG *)(v37 + 4)) )
  {
    if ( v37 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v37)(v37, 1);
  }
}

//----- (004956A0) --------------------------------------------------------  // acclient.c:207993
PStringBase<unsigned short> *__cdecl GetTimerText(PStringBase<unsigned short> *result, const bool i_running, const long double timer_stamp)
{
  PSRefBufferCharData<unsigned short> *v3; // eax@8
  char *v4; // esi@8
  PStringBase<unsigned short> return_text; // [sp+14h] [bp-4h]@1
  signed int i_runninga; // [sp+20h] [bp+8h]@3

  return_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( i_running )
  {
    if ( timer_stamp <= 0.0 )
    {
      PStringBase<unsigned short>::sprintf(&return_text, L"None");
    }
    else
    {
      i_runninga = (unsigned __int64)(timer_stamp - COERCE_DOUBLE(Timer::cur_time.Cmd));
      if ( i_runninga <= 0 )
        PStringBase<unsigned short>::sprintf(&return_text, L"Ready");
      else
        ClientUISystem::DeltaTimeToString((double)i_runninga, &return_text);
    }
  }
  else
  {
    PStringBase<unsigned short>::sprintf(&return_text, L"None");
  }
  v3 = return_text.m_charbuffer;
  result->m_charbuffer = return_text.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1].m_data[8]);
  v4 = (char *)&return_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&return_text.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}
// 7A6564: using guessed type wchar_t aReady[6];

//----- (00495770) --------------------------------------------------------  // acclient.c:208032
void __thiscall gmJournalUI::ShowEditableTimer(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  UIElement_Text *v2; // ecx@1
  char *v3; // esi@1
  char *v4; // esi@4
  PStringBase<unsigned short> timer_text; // [sp+1Ch] [bp-8h]@1
  PStringBase<unsigned short> button_text; // [sp+20h] [bp-4h]@1

  button_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  timer_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&button_text, L"Start");
  PStringBase<unsigned short>::sprintf(&timer_text, &word_794320);
  v2 = v1->m_pDaysEditBox;
  v1->m_Info.m_TimerRunning = 0;
  ((void (__stdcall *)(signed int))v2->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v1->m_pDaysStaticText->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v1->m_pHoursEditBox->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v1->m_pHoursStaticText->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v1->m_pMinutesEditBox->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(signed int))v1->m_pMinutesStaticText->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(_DWORD))v1->m_pTimerStaticText->vfptr[2].__vecDelDtor)(0);
  UIElement_Text::SetText(v1->m_pTimerStaticText, &timer_text);
  UIElement_Text::SetText((UIElement_Text *)&v1->m_pStartTimerButton->vfptr, &button_text);
  v3 = (char *)&timer_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&timer_text.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (char *)&button_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&button_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00495890) --------------------------------------------------------  // acclient.c:208071
void __thiscall gmJournalUI::UpdateRunningTimer(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  char *v2; // esi@1
  PStringBase<unsigned short> timer_text; // [sp+0h] [bp-4h]@1

  timer_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  GetTimerText(&timer_text, this->m_Info.m_TimerRunning, this->m_Info.m_TimerStamp);
  UIElement_Text::SetText(v1->m_pTimerStaticText, &timer_text);
  v2 = (char *)&timer_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&timer_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}

//----- (004958F0) --------------------------------------------------------  // acclient.c:208090
void __thiscall gmJournalUI::UpdateLocation(gmJournalUI *this)
{
  gmJournalUI *v1; // edi@1
  unsigned __int16 *v2; // edx@8
  unsigned __int16 *v3; // ecx@12
  long double v4; // st7@15
  long double v5; // st7@17
  char *v6; // esi@21
  PStringBase<unsigned short> location_string; // [sp+14h] [bp-14h]@1
  long double v8; // [sp+18h] [bp-10h]@17
  long double v9; // [sp+20h] [bp-8h]@19

  location_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( (wchar_t *)location_string.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&location_string.m_charbuffer[-1].m_data[8])
      && location_string.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&location_string.m_charbuffer[-1].m_data[6])(
        &location_string.m_charbuffer[-1].m_data[6],
        1);
    location_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  }
  if ( v1->m_Info.m_LocationSet )
  {
    if ( v1->m_Info.m_xCoord >= 0.0 )
    {
      v2 = L"E";
      if ( v1->m_Info.m_xCoord <= 0.0 )
        v2 = &word_794320;
    }
    else
    {
      v2 = L"W";
    }
    if ( v1->m_Info.m_yCoord >= 0.0 )
    {
      v3 = L"N";
      if ( v1->m_Info.m_yCoord <= 0.0 )
        v3 = &word_794320;
    }
    else
    {
      v3 = L"S";
    }
    v4 = v1->m_Info.m_xCoord;
    if ( v4 < 0.0 )
      v4 = -v4;
    v8 = v4;
    v5 = v1->m_Info.m_yCoord;
    if ( v5 < 0.0 )
      v5 = -v5;
    v9 = v5;
    PStringBase<unsigned short>::sprintf(
      &location_string,
      L"%.1f%s, %.1f%s",
      LODWORD(v5),
      *(unsigned __int64 *)&v5 >> 32,
      v3,
      v8,
      v2);
  }
  else
  {
    PStringBase<unsigned short>::sprintf(&location_string, L"None");
  }
  UIElement_Text::SetText(v1->m_pLocationStaticText, &location_string);
  v6 = (char *)&location_string.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&location_string.m_charbuffer[-1].m_data[8]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}
// 7A659C: using guessed type wchar_t aN_1[2];
// 7A65A0: using guessed type wchar_t aS_9[2];
// 7A65A4: using guessed type wchar_t aE[2];
// 7A65A8: using guessed type wchar_t aW_0[2];

//----- (00495A70) --------------------------------------------------------  // acclient.c:208172
void __thiscall gmJournalUI::UpdatePageNumber(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  signed int v2; // edi@1
  char *v3; // esi@3
  PStringBase<unsigned short> page_number_string; // [sp+0h] [bp-4h]@1

  page_number_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  v2 = 1;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( v1->m_Info.m_PageNumber > 0 )
    v2 = v1->m_Info.m_PageNumber;
  PStringBase<unsigned short>::sprintf(&page_number_string, L"~ %d ~", v2);
  UIElement_Text::SetText(v1->m_pPageNumberStaticText, &page_number_string);
  v3 = (char *)&page_number_string.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&page_number_string.m_charbuffer[-1].m_data[8]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (00495AF0) --------------------------------------------------------  // acclient.c:208196
bool __cdecl PageInfoSortTitle(PageInfo *p1, PageInfo *p2)
{
  bool v2; // bl@11
  char *v3; // esi@11
  char *v4; // esi@14
  PStringBase<unsigned short> buffer_string2; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> buffer_string1; // [sp+14h] [bp-4h]@1

  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Title.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Title.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
  }
  if ( buffer_string2.m_charbuffer != p2->m_Title.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Title.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v2 = _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) < 0;
  v3 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return v2;
}

//----- (00495C10) --------------------------------------------------------  // acclient.c:208243
bool __cdecl PageInfoSortLabel(PageInfo *p1, PageInfo *p2)
{
  bool v2; // bl@11
  char *v3; // esi@11
  char *v4; // esi@14
  PStringBase<unsigned short> buffer_string2; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> buffer_string1; // [sp+14h] [bp-4h]@1

  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Label.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Label.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
  }
  if ( buffer_string2.m_charbuffer != p2->m_Label.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Label.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v2 = _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) < 0;
  v3 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return v2;
}

//----- (00495D30) --------------------------------------------------------  // acclient.c:208290
bool __cdecl PageInfoReverseSortTitle(PageInfo *p1, PageInfo *p2)
{
  bool v2; // bl@11
  char *v3; // esi@11
  char *v4; // esi@14
  PStringBase<unsigned short> buffer_string2; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> buffer_string1; // [sp+14h] [bp-4h]@1

  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Title.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Title.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
  }
  if ( buffer_string2.m_charbuffer != p2->m_Title.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Title.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v2 = _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) > 0;
  v3 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return v2;
}

//----- (00495E50) --------------------------------------------------------  // acclient.c:208337
bool __cdecl PageInfoReverseSortLabel(PageInfo *p1, PageInfo *p2)
{
  bool v2; // bl@11
  char *v3; // esi@11
  char *v4; // esi@14
  PStringBase<unsigned short> buffer_string2; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> buffer_string1; // [sp+14h] [bp-4h]@1

  buffer_string1.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  buffer_string2.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( buffer_string1.m_charbuffer != p1->m_Label.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8])
      && buffer_string1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string1.m_charbuffer[-1].m_data[6])(
        &buffer_string1.m_charbuffer[-1].m_data[6],
        1);
    buffer_string1.m_charbuffer = p1->m_Label.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]);
  }
  if ( buffer_string2.m_charbuffer != p2->m_Label.m_charbuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8])
      && buffer_string2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&buffer_string2.m_charbuffer[-1].m_data[6])(
        &buffer_string2.m_charbuffer[-1].m_data[6],
        1);
    buffer_string2.m_charbuffer = p2->m_Label.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]);
  }
  PStringBase<unsigned short>::break_reference(&buffer_string1);
  __wcslwr(buffer_string1.m_charbuffer->m_data);
  PStringBase<unsigned short>::break_reference(&buffer_string2);
  __wcslwr(buffer_string2.m_charbuffer->m_data);
  v2 = _wcscmp(buffer_string1.m_charbuffer->m_data, buffer_string2.m_charbuffer->m_data) > 0;
  v3 = (char *)&buffer_string2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string2.m_charbuffer[-1].m_data[8]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = (char *)&buffer_string1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&buffer_string1.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return v2;
}

//----- (00495F70) --------------------------------------------------------  // acclient.c:208384
void __thiscall gmJournalUI::PostInit(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement *v8; // eax@10
  int v9; // eax@11
  UIElement *v10; // eax@13
  int v11; // eax@14
  UIElement *v12; // eax@16
  int v13; // eax@17
  UIElement *v14; // eax@19
  int v15; // eax@20
  UIElement *v16; // eax@22
  int v17; // eax@23
  UIElement *v18; // eax@25
  int v19; // eax@26
  UIElement *v20; // eax@28
  int v21; // eax@29
  UIElement *v22; // eax@31
  int v23; // eax@32
  UIElement *v24; // eax@34
  int v25; // eax@35
  UIElement *v26; // eax@37
  int v27; // eax@38

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000057Du);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1);
  else
    v3 = 0;
  v1->m_pStartTimerButton = (UIElement_Button *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000569u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)12);
  else
    v5 = 0;
  v1->m_pLabelEditBox = (UIElement_Text *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000056Bu);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
  else
    v7 = 0;
  v1->m_pTitleEditBox = (UIElement_Text *)v7;
  v8 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000056Du);
  if ( v8 )
    v9 = v8->vfptr[12].OnAction((IInputActionCallback *)v8, (InputEvent *)12);
  else
    v9 = 0;
  v1->m_pNotesEditBox = (UIElement_Text *)v9;
  v10 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000576u);
  if ( v10 )
    v11 = v10->vfptr[12].OnAction((IInputActionCallback *)v10, (InputEvent *)12);
  else
    v11 = 0;
  v1->m_pDaysEditBox = (UIElement_Text *)v11;
  v12 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000578u);
  if ( v12 )
    v13 = v12->vfptr[12].OnAction((IInputActionCallback *)v12, (InputEvent *)12);
  else
    v13 = 0;
  v1->m_pHoursEditBox = (UIElement_Text *)v13;
  v14 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000057Au);
  if ( v14 )
    v15 = v14->vfptr[12].OnAction((IInputActionCallback *)v14, (InputEvent *)12);
  else
    v15 = 0;
  v1->m_pMinutesEditBox = (UIElement_Text *)v15;
  v16 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000573u);
  if ( v16 )
    v17 = v16->vfptr[12].OnAction((IInputActionCallback *)v16, (InputEvent *)12);
  else
    v17 = 0;
  v1->m_pLocationStaticText = (UIElement_Text *)v17;
  v18 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000057Cu);
  if ( v18 )
    v19 = v18->vfptr[12].OnAction((IInputActionCallback *)v18, (InputEvent *)12);
  else
    v19 = 0;
  v1->m_pTimerStaticText = (UIElement_Text *)v19;
  v20 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000577u);
  if ( v20 )
    v21 = v20->vfptr[12].OnAction((IInputActionCallback *)v20, (InputEvent *)12);
  else
    v21 = 0;
  v1->m_pDaysStaticText = (UIElement_Text *)v21;
  v22 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000579u);
  if ( v22 )
    v23 = v22->vfptr[12].OnAction((IInputActionCallback *)v22, (InputEvent *)12);
  else
    v23 = 0;
  v1->m_pHoursStaticText = (UIElement_Text *)v23;
  v24 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x1000057Bu);
  if ( v24 )
    v25 = v24->vfptr[12].OnAction((IInputActionCallback *)v24, (InputEvent *)12);
  else
    v25 = 0;
  v1->m_pMinutesStaticText = (UIElement_Text *)v25;
  v26 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000570u);
  if ( v26 )
    v27 = v26->vfptr[12].OnAction((IInputActionCallback *)v26, (InputEvent *)12);
  else
    v27 = 0;
  v1->m_pPageNumberStaticText = (UIElement_Text *)v27;
  gmJournalUI::ShowEditableTimer(v1);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 0xBu);
  g_JournalPanel = v1;
}

//----- (00496190) --------------------------------------------------------  // acclient.c:208501
void __thiscall gmJournalUI::ShowRunningTimer(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  UIElement_Text *v2; // ecx@1
  char *v3; // esi@1
  PStringBase<unsigned short> button_text; // [sp+1Ch] [bp-4h]@1

  button_text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v1 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  PStringBase<unsigned short>::sprintf(&button_text, L"Reset");
  v2 = v1->m_pDaysEditBox;
  v1->m_Info.m_TimerRunning = 1;
  ((void (__stdcall *)(_DWORD))v2->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pDaysStaticText->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pHoursEditBox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pHoursStaticText->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pMinutesEditBox->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(_DWORD))v1->m_pMinutesStaticText->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(signed int))v1->m_pTimerStaticText->vfptr[2].__vecDelDtor)(1);
  UIElement_Text::SetText((UIElement_Text *)&v1->m_pStartTimerButton->vfptr, &button_text);
  gmJournalUI::UpdateRunningTimer(v1);
  v3 = (char *)&button_text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&button_text.m_charbuffer[-1].m_data[8]) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (00496260) --------------------------------------------------------  // acclient.c:208532
void __thiscall gmJournalUI::ResetLocation(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  CPlayerSystem *v2; // eax@1
  int v3; // edi@2
  int v4; // ST04_4@2

  v1 = this;
  v2 = CPlayerSystem::GetPlayerSystem();
  if ( v2 )
  {
    v3 = (int)&v1->m_Info.m_xCoord;
    v4 = (int)&v1->m_Info.m_yCoord;
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    v1->m_Info.m_LocationSet = CPlayerSystem::InqPlayerCoords(v2, &v1->m_Info.m_xCoord, &v1->m_Info.m_yCoord);
    gmJournalUI::UpdateLocation(v1);
  }
}

//----- (004962A0) --------------------------------------------------------  // acclient.c:208555
PageInfo *__thiscall _STL::vector<PageInfo,_STL::allocator<PageInfo>>::erase(_STL::vector<PageInfo,_STL::allocator<PageInfo> > *this, PageInfo *__position)
{
  PageInfo *v2; // edi@1
  _STL::vector<PageInfo,_STL::allocator<PageInfo> > *v3; // esi@1
  PageInfo *v4; // eax@1
  LookFile *v5; // ecx@3

  v2 = __position;
  v3 = this;
  v4 = this->_M_finish;
  if ( &__position[1] != v4 )
    _STL::__copy(__position + 1, v4, __position);
  v5 = (LookFile *)&v3->_M_finish[-1];
  v3->_M_finish = (PageInfo *)v5;
  LookFile::~LookFile(v5);
  return v2;
}

//----- (004962E0) --------------------------------------------------------  // acclient.c:208574
void __thiscall gmJournalUI::ClearCurrentPage(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1
  char *v2; // esi@5
  PStringBase<unsigned short> num_string; // [sp+0h] [bp-4h]@1

  num_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  if ( this->m_Loaded )
  {
    num_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PageInfo::Clear(&g_JournalPages._M_start[v1->m_CurrentPage - 1]);
    PageInfo::Clear(&v1->m_Info);
    UIElement_Text::SetText(v1->m_pLabelEditBox, &v1->m_Info.m_Label);
    UIElement_Text::SetText(v1->m_pTitleEditBox, &v1->m_Info.m_Title);
    UIElement_Text::SetText(v1->m_pNotesEditBox, &v1->m_Info.m_Notes);
    PStringBase<unsigned short>::sprintf(&num_string, L"%d", v1->m_Info.m_Days);
    UIElement_Text::SetText(v1->m_pDaysEditBox, &num_string);
    PStringBase<unsigned short>::sprintf(&num_string, L"%d", v1->m_Info.m_Hours);
    UIElement_Text::SetText(v1->m_pHoursEditBox, &num_string);
    PStringBase<unsigned short>::sprintf(&num_string, L"%d", v1->m_Info.m_Minutes);
    UIElement_Text::SetText(v1->m_pMinutesEditBox, &num_string);
    gmJournalUI::UpdateRunningTimer(v1);
    gmJournalUI::UpdateLocation(v1);
    gmJournalUI::UpdatePageNumber(v1);
    if ( v1->m_Info.m_TimerRunning )
      gmJournalUI::ShowRunningTimer(v1);
    else
      gmJournalUI::ShowEditableTimer(v1);
    v2 = (char *)&num_string.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&num_string.m_charbuffer[-1].m_data[8]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
  }
}

//----- (00496430) --------------------------------------------------------  // acclient.c:208614
void __thiscall gmJournalUI::GotoPage(gmJournalUI *this, const unsigned int page_index)
{
  gmJournalUI *v2; // esi@1
  UIElement_Text *v3; // ecx@3
  char *v4; // esi@6
  PStringBase<unsigned short> num_string; // [sp+0h] [bp-4h]@1

  num_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  if ( this->m_Loaded )
  {
    num_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( page_index <= g_JournalPages._M_finish - g_JournalPages._M_start )
    {
      PageInfo::operator=(&v2->m_Info, (int)&g_JournalPages._M_start[page_index - 1]);
      v3 = v2->m_pLabelEditBox;
      v2->m_CurrentPage = page_index;
      UIElement_Text::SetText(v3, &v2->m_Info.m_Label);
      UIElement_Text::SetText(v2->m_pTitleEditBox, &v2->m_Info.m_Title);
      UIElement_Text::SetText(v2->m_pNotesEditBox, &v2->m_Info.m_Notes);
      PStringBase<unsigned short>::sprintf(&num_string, L"%d", v2->m_Info.m_Days);
      UIElement_Text::SetText(v2->m_pDaysEditBox, &num_string);
      PStringBase<unsigned short>::sprintf(&num_string, L"%d", v2->m_Info.m_Hours);
      UIElement_Text::SetText(v2->m_pHoursEditBox, &num_string);
      PStringBase<unsigned short>::sprintf(&num_string, L"%d", v2->m_Info.m_Minutes);
      UIElement_Text::SetText(v2->m_pMinutesEditBox, &num_string);
      gmJournalUI::UpdateRunningTimer(v2);
      gmJournalUI::UpdateLocation(v2);
      gmJournalUI::UpdatePageNumber(v2);
      if ( v2->m_Info.m_TimerRunning )
        gmJournalUI::ShowRunningTimer(v2);
      else
        gmJournalUI::ShowEditableTimer(v2);
    }
    v4 = (char *)&num_string.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&num_string.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
  }
}

//----- (00496590) --------------------------------------------------------  // acclient.c:208659
void __thiscall gmJournalUI::Update(gmJournalUI *this)
{
  gmJournalUI *v1; // esi@1

  v1 = this;
  if ( this->m_Loaded )
  {
    gmJournalUI::UpdateRunningTimer(this);
    gmJournalUI::UpdateLocation(v1);
    gmJournalUI::UpdatePageNumber(v1);
    if ( v1->m_Info.m_TimerRunning )
      gmJournalUI::ShowRunningTimer(v1);
    else
      gmJournalUI::ShowEditableTimer(v1);
  }
}

//----- (004965D0) --------------------------------------------------------  // acclient.c:208677
void __thiscall gmJournalUI::DeletePage(gmJournalUI *this, const unsigned int page_index)
{
  gmJournalUI *v2; // esi@1
  const unsigned int v3; // eax@2
  PageInfo *v4; // ecx@5
  unsigned int v5; // eax@5
  int v6; // edx@6

  v2 = this;
  if ( this->m_Loaded )
  {
    v3 = g_JournalPages._M_finish - g_JournalPages._M_start;
    if ( page_index <= v3 )
    {
      if ( v3 > 1 )
      {
        _STL::vector<PageInfo,_STL::allocator<PageInfo>>::erase(
          &g_JournalPages,
          &g_JournalPages._M_start[page_index - 1]);
        v4 = g_JournalPages._M_start;
        v5 = 0;
        if ( g_JournalPages._M_finish - g_JournalPages._M_start )
        {
          v6 = 0;
          do
          {
            ++v5;
            v4[v6].m_PageNumber = v5;
            v4 = g_JournalPages._M_start;
            ++v6;
          }
          while ( v5 < g_JournalPages._M_finish - g_JournalPages._M_start );
        }
        gmJournalUI::GotoPage(v2, 1u);
      }
      else
      {
        gmJournalUI::ClearCurrentPage(this);
      }
    }
  }
}

//----- (00496660) --------------------------------------------------------  // acclient.c:208721
void __stdcall gmJournalUI::CreateJournalPath(PStringBase<char> i_file_name, PStringBase<char> *o_file_path)
{
  PStringBase<char> *v3; // ebx@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // edi@2
  volatile LONG *v6; // ST1C_4@5
  unsigned int v7; // eax@7
  char *v8; // eax@9
  gmClient *v9; // eax@9
  PSRefBufferCharData<unsigned short> **v10; // eax@9
  PSRefBufferCharData<unsigned short> *v11; // edi@9
  volatile LONG *v12; // ST1C_4@9
  PStringBase<char> *v13; // esi@9
  char *v14; // esi@12
  char *v15; // esi@15
  int v16; // edi@18
  char *v17; // esi@21
  PStringBase<char> strPreferenceFile; // [sp+10h] [bp-10h]@9
  PStringBase<char> world_name; // [sp+14h] [bp-Ch]@9
  PStringBase<char> character_name; // [sp+18h] [bp-8h]@9
  PStringBase<unsigned short> wp_world_name; // [sp+1Ch] [bp-4h]@9

  v3 = o_file_path;
  v4 = o_file_path->m_charbuffer;
  if ( o_file_path->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v3->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v6);
  }
  if ( SmartBox::smartbox )
    v7 = SmartBox::smartbox->player_id;
  else
    v7 = 0;
  v8 = ACCWeenieObject::GetObjectName((ACCWeenieObject *)v7, 0, 0);
  PStringBase<char>::PStringBase<char>(&character_name, v8);
  v9 = Client::GetInstance();
  v10 = (PSRefBufferCharData<unsigned short> **)((int (__thiscall *)(gmClient *))v9->vfptr[3].QueryInterface)(v9);
  v11 = *v10;
  v12 = (volatile LONG *)&(*v10)[-1].m_data[8];
  wp_world_name.m_charbuffer = *v10;
  InterlockedIncrement(v12);
  PStringBase<unsigned short>::to_spstring(&wp_world_name, &world_name, 0);
  strPreferenceFile.m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]);
  o_file_path = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::get_directory((PStringBase<char> *)&o_file_path, &strPreferenceFile);
  PStringBase<char>::sprintf(
    v3,
    "%s%s-%s-%s.txt",
    o_file_path,
    i_file_name.m_charbuffer,
    world_name.m_charbuffer,
    character_name.m_charbuffer);
  v13 = o_file_path - 5;
  if ( !InterlockedDecrement((volatile LONG *)&o_file_path[-4]) && v13 )
    (*(void (__thiscall **)(_DWORD, _DWORD))&v13->m_charbuffer->m_data[0])(v13, 1);
  v14 = &strPreferenceFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strPreferenceFile.m_charbuffer[-1]) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = &world_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&world_name.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  v16 = (int)&v11[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  v17 = &character_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&character_name.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  if ( !InterlockedDecrement((volatile LONG *)&i_file_name.m_charbuffer[-1])
    && i_file_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&i_file_name.m_charbuffer[-2].m_data[12])(
      &i_file_name.m_charbuffer[-2].m_data[12],
      1);
}

//----- (00496800) --------------------------------------------------------  // acclient.c:208802
void __stdcall gmJournalUI::ReportInScroll(PStringBase<char> msg, const unsigned int ltt)
{
  ClientUISystem *v3; // eax@1
  PSRefBufferCharData<char> *v4; // edi@1
  ClientSystem *v5; // esi@1
  char *v6; // esi@1

  v3 = ClientUISystem::GetUISystem();
  v4 = msg.m_charbuffer;
  v5 = (ClientSystem *)v3;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&msg,
    0,
    msg.m_charbuffer->m_data);
  ClientSystem::AddTextToScroll(v5, (PStringBase<unsigned short> *)&msg, ltt, 1, 0);
  v6 = &msg.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
}

//----- (00496880) --------------------------------------------------------  // acclient.c:208825
void __thiscall gmJournalUI::NewPage(gmJournalUI *this)
{
  PageInfo page_info; // [sp+0h] [bp-40h]@2

  if ( this->m_Loaded )
  {
    PageInfo::PageInfo(&page_info);
    page_info.m_PageNumber = g_JournalPages._M_finish - g_JournalPages._M_start + 1;
    _STL::vector<PageInfo,_STL::allocator<PageInfo>>::insert(&g_JournalPages, g_JournalPages._M_finish, &page_info);
    LookFile::~LookFile((LookFile *)&page_info);
  }
}

//----- (004968D0) --------------------------------------------------------  // acclient.c:208839
UIElementMessageListenResult __thiscall gmJournalUI::ListenToElementMessage(gmJournalUI *this, UIElementMessageInfo *i_rMsg)
{
  gmJournalUI *v2; // esi@1
  UIElementMessageListenResult result; // eax@2
  unsigned int v4; // eax@9
  gmJournalUI *v5; // ecx@11

  v2 = this;
  if ( this->m_Loaded )
  {
    if ( i_rMsg->idMessage == 24 && (gmJournalUI *)i_rMsg->pElement == this && i_rMsg->dwParam1 )
      gmJournalUI::Update(this);
    if ( i_rMsg->idMessage == 1 )
    {
      switch ( i_rMsg->idElement )
      {
        case 0x10000565u:
          gmJournalUI::SaveThisPage(v2);
          v4 = v2->m_CurrentPage;
          if ( v4 == 1 )
            break;
          gmJournalUI::GotoPage(v2, v4 - 1);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x10000566u:
          gmJournalUI::SaveThisPage(v2);
          if ( gmJournalUI::IsLastPage(v2) )
            break;
          gmJournalUI::GotoPage(v5, v2->m_CurrentPage + 1);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x1000056Fu:
          gmJournalUI::SaveThisPage(v2);
          gmJournalUI::GotoPage(v2, 1u);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x10000571u:
          gmJournalUI::SaveThisPage(v2);
          gmJournalUI::GotoPage(v2, g_JournalPages._M_finish - g_JournalPages._M_start);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x10000567u:
          gmJournalUI::SaveThisPage(v2);
          gmJournalUI::NewPage(v2);
          gmJournalUI::GotoPage(v2, g_JournalPages._M_finish - g_JournalPages._M_start);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x10000574u:
          gmJournalUI::ResetLocation(v2);
          return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
        case 0x1000057Du:
          if ( v2->m_Info.m_TimerRunning )
          {
            LODWORD(v2->m_Info.m_TimerStamp) = 0;
            HIDWORD(v2->m_Info.m_TimerStamp) = 0;
            v2->m_Info.m_TimerRunning = 0;
            gmJournalUI::ShowEditableTimer(v2);
            return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
          }
          if ( !gmJournalUI::ResetTimer(v2) )
          {
            gmJournalUI::ShowRunningTimer(v2);
            return UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
          }
          gmJournalUI::ClearTimerText(v2);
          break;
        default:
          break;
      }
    }
    result = UIElement::ListenToElementMessage((UIElement *)&v2->vfptr, i_rMsg);
  }
  else
  {
    result = UIElement::ListenToElementMessage((UIElement *)&this->vfptr, i_rMsg);
  }
  return result;
}

//----- (00496AC0) --------------------------------------------------------  // acclient.c:208914
void __thiscall gmJournalUI::LoadPages(gmJournalUI *this, PStringBase<char> file_name)
{
  gmJournalUI *v2; // edi@1
  int v3; // ebx@1
  LONG (__stdcall *v4)(volatile LONG *); // edi@2
  int v5; // esi@5
  PSRefBufferCharData<char> *v6; // ebp@6
  _iobuf *v7; // edi@6
  char *v8; // esi@10
  bool v9; // zf@15
  PageInfo *v10; // esi@16
  char *v11; // eax@17
  int v12; // edi@19
  char *v13; // esi@19
  signed int v14; // ecx@19
  bool v15; // cf@19
  bool v16; // zf@19
  int v17; // edx@19
  char *v18; // eax@28
  char *v19; // eax@30
  PStringBase<unsigned short> *v20; // esi@30
  const unsigned __int16 *v21; // eax@30
  char *v22; // esi@30
  char *v23; // eax@34
  PageInfo *v24; // esi@34
  const unsigned __int16 *v25; // eax@34
  char *v26; // eax@36
  PageInfo *v27; // esi@36
  const unsigned __int16 *v28; // eax@36
  char *v29; // eax@38
  char *v30; // eax@41
  char *v31; // eax@44
  char *v32; // eax@51
  char *v33; // eax@54
  char *v34; // eax@61
  LONG (__stdcall *v35)(volatile LONG *); // edi@65
  char *v36; // esi@65
  char *v37; // esi@68
  int v38; // edx@75
  char *v39; // esi@77
  int v40; // eax@79
  char *v41; // esi@80
  int v42; // edx@82
  PStringBase<char> v43; // [sp-8h] [bp-880h]@16
  const unsigned int v44; // [sp-4h] [bp-87Ch]@16
  bool first_page_created; // [sp+13h] [bp-865h]@6
  PStringBase<char> token_string; // [sp+14h] [bp-864h]@6
  unsigned int scan_int; // [sp+18h] [bp-860h]@6
  PStringBase<char> file_path; // [sp+1Ch] [bp-85Ch]@1
  _iobuf *f; // [sp+20h] [bp-858h]@6
  long double scan_float; // [sp+24h] [bp-854h]@6
  PStringBase<char> str; // [sp+2Ch] [bp-84Ch]@36
  PStringBase<char> search; // [sp+30h] [bp-848h]@36
  gmJournalUI *v53; // [sp+34h] [bp-844h]@1
  PStringBase<unsigned short> v54; // [sp+38h] [bp-840h]@34
  PStringBase<unsigned short> result; // [sp+3Ch] [bp-83Ch]@30
  PStringBase<unsigned short> v56; // [sp+40h] [bp-838h]@36
  char line_buffer[2100]; // [sp+44h] [bp-834h]@16

  file_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  v53 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = 0;
  if ( !v2->m_Loaded )
  {
    v4 = InterlockedDecrement;
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1])
      && file_path.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&file_path.m_charbuffer[-2].m_data[12])(
        &file_path.m_charbuffer[-2].m_data[12],
        1);
    v5 = (int)&file_name.m_charbuffer[-2].m_data[12];
    goto LABEL_14;
  }
  v6 = file_name.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&file_name.m_charbuffer[-1]);
  gmJournalUI::CreateJournalPath(file_name, &file_path);
  token_string.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  scan_int = 0;
  scan_float = 0.0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  first_page_created = 0;
  v7 = _fopen(file_path.m_charbuffer->m_data, "r");
  f = v7;
  if ( !v7 )
  {
    v4 = InterlockedDecrement;
    if ( !InterlockedDecrement((volatile LONG *)&token_string.m_charbuffer[-1])
      && token_string.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&token_string.m_charbuffer[-2].m_data[12])(
        &token_string.m_charbuffer[-2].m_data[12],
        1);
    v8 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    v5 = (int)&file_name.m_charbuffer[-2].m_data[12];
LABEL_14:
    if ( !v4((volatile LONG *)(v5 + 4)) )
    {
      v9 = v5 == 0;
LABEL_74:
      if ( !v9 )
      {
        v38 = *(_DWORD *)v5;
        v44 = 1;
        (*(void (__thiscall **)(int, signed int))v38)(v5, 1);
      }
    }
    return;
  }
  v44 = 0;
  v43.m_charbuffer = (PSRefBufferCharData<char> *)&first_page_created;
  v10 = _STL::__copy(g_JournalPages._M_finish, g_JournalPages._M_finish, g_JournalPages._M_start);
  _STL::__destroy_aux(v10, g_JournalPages._M_finish);
  g_JournalPages._M_finish = v10;
  if ( !_fgets(line_buffer, 2100, v7) )
  {
LABEL_65:
    _fclose(v7);
    v35 = InterlockedDecrement;
    v36 = &token_string.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&token_string.m_charbuffer[-1]) && v36 )
      (**(void (__thiscall ***)(char *, signed int))v36)(v36, 1);
    v37 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v37 )
      (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
    v5 = (int)&v6[-2].m_data[12];
    goto LABEL_72;
  }
  while ( 1 )
  {
    v11 = _strtok(line_buffer, " \t\n\r");
    if ( v11 )
      break;
LABEL_63:
    if ( !_fgets(line_buffer, 2100, f) )
    {
      v7 = f;
      v6 = file_name.m_charbuffer;
      goto LABEL_65;
    }
  }
  if ( first_page_created )
    goto LABEL_86;
  v12 = (int)"<NEWP>";
  v13 = v11;
  v14 = 7;
  v17 = 0;
  v15 = 0;
  v16 = 1;
  do
  {
    if ( !v14 )
      break;
    v15 = (unsigned __int8)*v13 < *(_BYTE *)v12;
    v16 = *v13++ == *(_BYTE *)v12++;
    --v14;
  }
  while ( v16 );
  if ( !v16 )
    v17 = -v15 - (v15 - 1);
  if ( !v17 )
  {
LABEL_86:
    if ( !memcmp(v11, "<NEWP>", 7) )
    {
      gmJournalUI::NewPage(v53);
      v3 = g_JournalPages._M_finish - g_JournalPages._M_start - 1;
      g_JournalPages._M_start[v3].m_PageNumber = g_JournalPages._M_finish - g_JournalPages._M_start;
      first_page_created = 1;
    }
    else if ( !memcmp(v11, "<PNUM>", 7) )
    {
      v18 = _strtok(0, " \t\n\r");
      _sscanf(v18, "%d", &scan_int);
    }
    else if ( !memcmp(v11, "<LABE>", 7) )
    {
      v19 = _strtok(0, "\n\r");
      PStringBase<char>::set(&token_string, v19);
      v20 = &g_JournalPages._M_start[v3].m_Label;
      v21 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(&token_string, &result, 0);
      PStringBase<unsigned short>::operator=(v20, v21);
      v22 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v22 )
        (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
    }
    else if ( !memcmp(v11, "<TITL>", 7) )
    {
      v23 = _strtok(0, "\n\r");
      PStringBase<char>::set(&token_string, v23);
      v24 = &g_JournalPages._M_start[v3];
      v25 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(&token_string, &v54, 0);
      PStringBase<unsigned short>::operator=(&v24->m_Title, v25);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v54);
    }
    else if ( !memcmp(v11, "<NOTE>", 7) )
    {
      v26 = _strtok(0, "\n\r");
      PStringBase<char>::set(&token_string, v26);
      PStringBase<char>::PStringBase<char>(&str, "\n");
      PStringBase<char>::PStringBase<char>(&search, "\t");
      PStringBase<char>::replace(&token_string, &search, &str);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&search);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&str);
      v27 = &g_JournalPages._M_start[v3];
      v28 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(&token_string, &v56, 0);
      PStringBase<unsigned short>::operator=(&v27->m_Notes, v28);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v56);
    }
    else if ( !memcmp(v11, "<DAYS>", 7) )
    {
      v29 = _strtok(0, " \t\n\r");
      if ( _sscanf(v29, "%d", &scan_int) == 1 )
        g_JournalPages._M_start[v3].m_Days = scan_int;
    }
    else if ( !memcmp(v11, "<HOUR>", 7) )
    {
      v30 = _strtok(0, " \t\n\r");
      if ( _sscanf(v30, "%d", &scan_int) == 1 )
        g_JournalPages._M_start[v3].m_Hours = scan_int;
    }
    else if ( !memcmp(v11, "<MINU>", 7) )
    {
      v31 = _strtok(0, " \t\n\r");
      if ( _sscanf(v31, "%d", &scan_int) == 1 )
        g_JournalPages._M_start[v3].m_Minutes = scan_int;
    }
    else if ( !memcmp(v11, "<LOC?>", 7) )
    {
      g_JournalPages._M_start[v3].m_LocationSet = !memcmp(_strtok(0, " \t\n\r"), "TRUE", 5);
    }
    else if ( !memcmp(v11, "<LOCX>", 7) )
    {
      v32 = _strtok(0, " \t\n\r");
      if ( _sscanf(v32, "%lf", &scan_float) == 1 )
        g_JournalPages._M_start[v3].m_xCoord = scan_float;
    }
    else if ( !memcmp(v11, "<LOCY>", 7) )
    {
      v33 = _strtok(0, " \t\n\r");
      if ( _sscanf(v33, "%lf", &scan_float) == 1 )
        g_JournalPages._M_start[v3].m_yCoord = scan_float;
    }
    else if ( !memcmp(v11, "<TIM?>", 7) )
    {
      g_JournalPages._M_start[v3].m_TimerRunning = !memcmp(_strtok(0, " \t\n\r"), "TRUE", 5);
    }
    else if ( !memcmp(v11, "<TIME>", 7) )
    {
      v34 = _strtok(0, " \t\n\r");
      if ( _sscanf(v34, "%lf", &scan_float) == 1 )
        g_JournalPages._M_start[v3].m_TimerStamp = scan_float;
    }
    goto LABEL_63;
  }
  v44 = 26;
  v43.m_charbuffer = (PSRefBufferCharData<char> *)v14;
  PStringBase<char>::PStringBase<char>(&v43, "Problem loading journal: Your journal file does not create a new page!");
  gmJournalUI::ReportInScroll(v43, v44);
  _fclose(f);
  v35 = InterlockedDecrement;
  v39 = &token_string.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&token_string.m_charbuffer[-1]) && v39 )
  {
    v40 = *(_DWORD *)v39;
    v44 = 1;
    (*(void (__thiscall **)(char *, signed int))v40)(v39, 1);
  }
  v41 = &file_path.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1]) && v41 )
  {
    v42 = *(_DWORD *)v41;
    v44 = 1;
    (*(void (__thiscall **)(char *, signed int))v42)(v41, 1);
  }
  v5 = (int)&file_name.m_charbuffer[-2].m_data[12];
LABEL_72:
  if ( !v35((volatile LONG *)(v5 + 4)) )
  {
    v9 = v5 == 0;
    goto LABEL_74;
  }
}

//----- (00497270) --------------------------------------------------------  // acclient.c:209201
void __thiscall gmJournalUI::SavePages(gmJournalUI *this, PStringBase<char> file_name)
{
  gmJournalUI *v2; // edi@1
  LONG (__stdcall *v3)(volatile LONG *); // edi@2
  int v4; // esi@11
  PSRefBufferCharData<char> *v5; // ebx@12
  FILE *v6; // edi@12
  char *v7; // esi@17
  int v8; // esi@19
  PSRefBufferCharData<char> *v9; // ebp@20
  int v10; // ebp@20
  PSRefBufferCharData<char> *v11; // ebp@23
  int v12; // ebp@23
  PSRefBufferCharData<char> *v13; // ebp@26
  int v14; // ebp@31
  char *v15; // ebp@34
  char *v16; // ebp@37
  int v17; // eax@40
  int v18; // eax@42
  char *v19; // esi@46
  LONG v20; // eax@17
  char *v21; // esi@53
  PStringBase<char> line_to_write; // [sp+1Ch] [bp-28h]@1
  PStringBase<char> notes_buffer; // [sp+20h] [bp-24h]@1
  PStringBase<char> file_path; // [sp+24h] [bp-20h]@1
  PStringBase<char> search; // [sp+28h] [bp-1Ch]@34
  PStringBase<char> str; // [sp+2Ch] [bp-18h]@34
  unsigned int i; // [sp+30h] [bp-14h]@18
  PStringBase<char> result; // [sp+34h] [bp-10h]@20
  PStringBase<char> v29; // [sp+38h] [bp-Ch]@23
  PStringBase<char> v30; // [sp+3Ch] [bp-8h]@26
  char *v31; // [sp+40h] [bp-4h]@27

  file_path.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  line_to_write.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  notes_buffer.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( v2->m_Loaded )
  {
    v5 = file_name.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&file_name.m_charbuffer[-1]);
    gmJournalUI::CreateJournalPath(file_name, &file_path);
    v6 = _fopen(file_path.m_charbuffer->m_data, "w");
    if ( v6 || (v6 = _fopen(file_path.m_charbuffer->m_data, "w+")) != 0 )
    {
      i = 0;
      if ( g_JournalPages._M_finish - g_JournalPages._M_start )
      {
        v8 = 0;
        do
        {
          PStringBase<char>::sprintf(&line_to_write, "<NEWP>\n");
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<unsigned short>::to_spstring(&g_JournalPages._M_start[v8].m_Label, &result, 0);
          v9 = result.m_charbuffer;
          PStringBase<char>::sprintf(&line_to_write, "<LABE> %s\n", result.m_charbuffer);
          v10 = (int)&v9[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<unsigned short>::to_spstring(&g_JournalPages._M_start[v8].m_Title, &v29, 0);
          v11 = v29.m_charbuffer;
          PStringBase<char>::sprintf(&line_to_write, "<TITL> %s\n", v29.m_charbuffer);
          v12 = (int)&v11[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<unsigned short>::to_spstring(&g_JournalPages._M_start[v8].m_Notes, &v30, 0);
          v13 = v30.m_charbuffer;
          if ( notes_buffer.m_charbuffer != v30.m_charbuffer )
          {
            v31 = &notes_buffer.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&notes_buffer.m_charbuffer[-1]) && v31 )
              (**(void (__stdcall ***)(_DWORD))v31)(1);
            notes_buffer.m_charbuffer = v13;
            InterlockedIncrement((volatile LONG *)&v13[-1]);
          }
          v14 = (int)&v13[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
          PStringBase<char>::PStringBase<char>(&str, "\t");
          PStringBase<char>::PStringBase<char>(&search, "\n");
          PStringBase<char>::replace(&notes_buffer, &search, &str);
          v15 = &search.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1]) && v15 )
            (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
          v16 = &str.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
          PStringBase<char>::sprintf(&line_to_write, "<NOTE> %s\n", notes_buffer.m_charbuffer);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(&line_to_write, "<DAYS> %d\n", g_JournalPages._M_start[v8].m_Days);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(&line_to_write, "<HOUR> %d\n", g_JournalPages._M_start[v8].m_Hours);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(&line_to_write, "<MINU> %d\n", g_JournalPages._M_start[v8].m_Minutes);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          v17 = (int)"TRUE";
          if ( !g_JournalPages._M_start[v8].m_LocationSet )
            v17 = (int)"FALSE";
          PStringBase<char>::sprintf(&line_to_write, "<LOC?> %s\n", v17);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(
            &line_to_write,
            "<LOCX> %f\n",
            LODWORD(g_JournalPages._M_start[v8].m_xCoord),
            HIDWORD(g_JournalPages._M_start[v8].m_xCoord));
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(
            &line_to_write,
            "<LOCY> %f\n",
            LODWORD(g_JournalPages._M_start[v8].m_yCoord),
            HIDWORD(g_JournalPages._M_start[v8].m_yCoord));
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          v18 = (int)"TRUE";
          if ( !g_JournalPages._M_start[v8].m_TimerRunning )
            v18 = (int)"FALSE";
          PStringBase<char>::sprintf(&line_to_write, "<TIM?> %s\n", v18);
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          PStringBase<char>::sprintf(
            &line_to_write,
            "<TIME> %f\n\n",
            LODWORD(g_JournalPages._M_start[v8].m_TimerStamp),
            HIDWORD(g_JournalPages._M_start[v8].m_TimerStamp));
          _fwrite(line_to_write.m_charbuffer, 1u, *(_DWORD *)&line_to_write.m_charbuffer[-1].m_data[12] - 1, v6);
          ++v8;
          ++i;
        }
        while ( i < g_JournalPages._M_finish - g_JournalPages._M_start );
        v5 = file_name.m_charbuffer;
      }
      _fclose(v6);
      v3 = InterlockedDecrement;
      v19 = &notes_buffer.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&notes_buffer.m_charbuffer[-1]) && v19 )
        (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
      v7 = &line_to_write.m_charbuffer[-2].m_data[12];
      v20 = InterlockedDecrement((volatile LONG *)&line_to_write.m_charbuffer[-1]);
    }
    else
    {
      v3 = InterlockedDecrement;
      if ( !InterlockedDecrement((volatile LONG *)&notes_buffer.m_charbuffer[-1])
        && notes_buffer.m_charbuffer != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(char *, signed int))&notes_buffer.m_charbuffer[-2].m_data[12])(
          &notes_buffer.m_charbuffer[-2].m_data[12],
          1);
      v7 = &line_to_write.m_charbuffer[-2].m_data[12];
      v20 = InterlockedDecrement((volatile LONG *)&line_to_write.m_charbuffer[-1]);
    }
    if ( !v20 && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v21 = &file_path.m_charbuffer[-2].m_data[12];
    if ( !v3((volatile LONG *)&file_path.m_charbuffer[-1]) && v21 )
      (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
    v4 = (int)&v5[-2].m_data[12];
  }
  else
  {
    v3 = InterlockedDecrement;
    if ( !InterlockedDecrement((volatile LONG *)&notes_buffer.m_charbuffer[-1])
      && notes_buffer.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&notes_buffer.m_charbuffer[-2].m_data[12])(
        &notes_buffer.m_charbuffer[-2].m_data[12],
        1);
    if ( !InterlockedDecrement((volatile LONG *)&line_to_write.m_charbuffer[-1])
      && line_to_write.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&line_to_write.m_charbuffer[-2].m_data[12])(
        &line_to_write.m_charbuffer[-2].m_data[12],
        1);
    if ( !InterlockedDecrement((volatile LONG *)&file_path.m_charbuffer[-1])
      && file_path.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&file_path.m_charbuffer[-2].m_data[12])(
        &file_path.m_charbuffer[-2].m_data[12],
        1);
    v4 = (int)&file_name.m_charbuffer[-2].m_data[12];
  }
  if ( !v3((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (004977E0) --------------------------------------------------------  // acclient.c:209389
void __thiscall gmJournalUI::ListenToGlobalMessage(gmJournalUI *this, unsigned int i_messageID, int i_data_int)
{
  gmJournalUI *v3; // esi@1
  unsigned int v4; // ST04_4@4
  unsigned int v5; // esi@7

  v3 = this;
  if ( i_messageID == 3 )
  {
    if ( (*((_DWORD *)&this->0 + 41) >> 1) & 1 && COERCE_DOUBLE(Timer::cur_time.Cmd) >= this->m_timeNextUpdate )
    {
      gmJournalUI::UpdateRunningTimer(this);
      v3->m_timeNextUpdate = COERCE_DOUBLE(Timer::cur_time.Cmd) + 0.5;
    }
  }
  else if ( i_messageID == 11 && !this->m_Loaded )
  {
    this->m_Loaded = 1;
    i_messageID = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&i_messageID, "Journal");
    v4 = i_messageID;
    InterlockedIncrement((volatile LONG *)(i_messageID - 16));
    gmJournalUI::LoadPages(v3, (PStringBase<char>)v4);
    if ( g_JournalPages._M_finish - g_JournalPages._M_start )
    {
      PageInfo::operator=(&v3->m_Info, (int)g_JournalPages._M_start);
      gmJournalUI::GotoPage(v3, 1u);
    }
    else
    {
      gmJournalUI::NewPage(v3);
    }
    v3->m_CurrentPage = 1;
    v5 = i_messageID - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_messageID - 20 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
  }
}

//----- (004978F0) --------------------------------------------------------  // acclient.c:209433
void __thiscall gmJournalUI::OnVisibilityChanged(gmJournalUI *this, bool i_bVisible)
{
  bool v2; // bl@1
  gmJournalUI *v3; // esi@1
  PStringBase<char> v4; // ST08_4@4
  int v5; // esi@4

  v2 = i_bVisible;
  v3 = this;
  UIElement::OnVisibilityChanged((UIElement *)&this->vfptr, i_bVisible);
  if ( v3->m_Loaded )
  {
    *(_DWORD *)&i_bVisible = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PStringBase<char>::sprintf((PStringBase<char> *)&i_bVisible, "Journal");
    if ( v2 )
      _STL::sort(
        g_JournalPages._M_start,
        g_JournalPages._M_finish,
        (bool (__cdecl *)(PageInfo *, PageInfo *))PageInfoSortPageNumber);
    gmJournalUI::SaveThisPage(v3);
    v4.m_charbuffer = (PSRefBufferCharData<char> *)i_bVisible;
    InterlockedIncrement((volatile LONG *)(i_bVisible - 16));
    gmJournalUI::SavePages(v3, v4);
    v5 = i_bVisible - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_bVisible - 20 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
  }
}

//----- (006EE9D0) --------------------------------------------------------  // acclient.c:770693
void _E91_58()
{
  outside_val_50 = 1000.0 + 1.0;
}

//----- (006EE9F0) --------------------------------------------------------  // acclient.c:770699
void _E93_34()
{
  block_length_50 = 24.0 * 8.0;
}

//----- (006EEA10) --------------------------------------------------------  // acclient.c:770705
void _E95_34()
{
  half_square_length_50 = 24.0 * 0.5;
}

//----- (006EEA30) --------------------------------------------------------  // acclient.c:770711
int _E97_59()
{
  return atexit(_E98_71);
}

//----- (006EEA40) --------------------------------------------------------  // acclient.c:770717
int _E100_52()
{
  return atexit(_E101_89);
}

//----- (006EEA50) --------------------------------------------------------  // acclient.c:770723
int _E103_44()
{
  return atexit(_E104_59);
}

//----- (006EEA60) --------------------------------------------------------  // acclient.c:770729
void _E106_34()
{
  DEFAULT_VIEW_RADIUS_27 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EEA80) --------------------------------------------------------  // acclient.c:770735
void _E108_24()
{
  MIN_QUANTUM_27 = 1.0 / 30.0;
}

//----- (006EEAA0) --------------------------------------------------------  // acclient.c:770741
void _E110_15()
{
  MAX_QUANTUM_27 = 1.0 / 5.0;
}

//----- (006EEAC0) --------------------------------------------------------  // acclient.c:770747
void _E112_29()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_62, PFID_A8R8G8B8);
}

//----- (006EEAD0) --------------------------------------------------------  // acclient.c:770753
void _E115_22()
{
  LOWEST_DATA_RATE_70 = 1024;
}

//----- (006EEAE0) --------------------------------------------------------  // acclient.c:770759
void _E117_19()
{
  HIGHEST_DATA_RATE_70 = 0x7FFF;
}

//----- (006EEAF0) --------------------------------------------------------  // acclient.c:770765
int _E119_8()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_70;
  INITIAL_MAX_DATA_RATE_18 = LOWEST_DATA_RATE_70;
  return result;
}

//----- (006EEB00) --------------------------------------------------------  // acclient.c:770775
int _E121_29()
{
  return atexit(_E122_66);
}

//----- (006EEB10) --------------------------------------------------------  // acclient.c:770781
int _E124_27()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_22, "Misc.TooltipEnable");
  return atexit(_E125_37);
}

//----- (006EEB30) --------------------------------------------------------  // acclient.c:770788
int _E127_23()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_22, "Misc.TooltipDelay");
  return atexit(_E128_38);
}

//----- (006EEB50) --------------------------------------------------------  // acclient.c:770795
int _E130_20()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_35, "None");
  return atexit(_E131_30);
}

//----- (006EEB70) --------------------------------------------------------  // acclient.c:770802
int _E133_19()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_35, "Speed");
  return atexit(_E134_27);
}

//----- (006EEB90) --------------------------------------------------------  // acclient.c:770809
int _E136_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_35, "Noise");
  return atexit(_E137_26);
}

//----- (006EEBB0) --------------------------------------------------------  // acclient.c:770816
int _E139_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_35, "Sine");
  return atexit(_E140_21);
}

//----- (006EEBD0) --------------------------------------------------------  // acclient.c:770823
int _E142_14()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_35, "Square");
  return atexit(_E143_22);
}

//----- (006EEBF0) --------------------------------------------------------  // acclient.c:770830
int _E145_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_35, "Bounce");
  return atexit(_E146_22);
}

//----- (006EEC10) --------------------------------------------------------  // acclient.c:770837
int _E148_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_35, "Perlin");
  return atexit(_E149_22);
}

//----- (006EEC30) --------------------------------------------------------  // acclient.c:770844
int _E151_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_35, "Fractal");
  return atexit(_E152_21);
}

//----- (006EEC50) --------------------------------------------------------  // acclient.c:770851
int _E154_15()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_35, "FrameLoop");
  return atexit(_E155_18);
}

//----- (006EEC70) --------------------------------------------------------  // acclient.c:770858
int _E160_15()
{
  return atexit((void (__cdecl *)())_E161_18);
}

//----- (006EEC80) --------------------------------------------------------  // acclient.c:770864
int sub_6EEC80()
{
  return atexit(nullsub_876);
}

//----- (0075FA10) --------------------------------------------------------  // acclient.c:887419
void __cdecl _E125_37()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FA40) --------------------------------------------------------  // acclient.c:887432
void __cdecl _E128_38()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FA70) --------------------------------------------------------  // acclient.c:887445
void __cdecl _E131_30()
{
  char *v0; // esi@1

  v0 = &waveform_None_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FAA0) --------------------------------------------------------  // acclient.c:887458
void __cdecl _E134_27()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FAD0) --------------------------------------------------------  // acclient.c:887471
void __cdecl _E137_26()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FB00) --------------------------------------------------------  // acclient.c:887484
void __cdecl _E140_21()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FB30) --------------------------------------------------------  // acclient.c:887497
void __cdecl _E143_22()
{
  char *v0; // esi@1

  v0 = &waveform_Square_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FB60) --------------------------------------------------------  // acclient.c:887510
void __cdecl _E146_22()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FB90) --------------------------------------------------------  // acclient.c:887523
void __cdecl _E149_22()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FBC0) --------------------------------------------------------  // acclient.c:887536
void __cdecl _E152_21()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FBF0) --------------------------------------------------------  // acclient.c:887549
void __cdecl _E155_18()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_35.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_35.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075FC20) --------------------------------------------------------  // acclient.c:887562
void __thiscall _E161_18(void *this)
{
  void *v1; // [sp-2h] [bp-4h]@1

  v1 = this;
  _STL::__destroy_aux(g_JournalPages._M_start, g_JournalPages._M_finish);
  if ( (_DWORD)g_JournalPages._M_start )
    _STL::__node_alloc<1,0>::deallocate(
      g_JournalPages._M_start,
      (g_JournalPages._M_end_of_storage._M_data - g_JournalPages._M_start) << 6);
}

