/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DebugConsole
   Object     : ENGINE\debugconsole\DebugConsole.obj
   Functions  : 63
   Addresses  : 00690090 - 00784770 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00690090) --------------------------------------------------------  // acclient.c:679608
char __cdecl DebugConsole::ConsoleCommand_Clear()
{
  char result; // al@2

  if ( DebugConsole::sm_pCurrentDebugConsole )
  {
    GlyphList::Flush(DebugConsole::sm_pCurrentDebugConsole->m_pOutputBuffer);
    result = 1;
    DebugConsole::sm_pCurrentDebugConsole->m_OutputBufferIsDirty = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}
// 8F84A0: using guessed type struct DebugConsole *DebugConsole::sm_pCurrentDebugConsole;

//----- (006900B0) --------------------------------------------------------  // acclient.c:679627
void __thiscall DebugConsole::InputMoveCursorToPreviousWord(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  unsigned int nPos; // [sp+0h] [bp-4h]@1

  nPos = (unsigned int)this;
  v1 = this;
  if ( GlyphList::FindPrevWord(this->m_pInputBuffer, this->m_InputCursorPos, &nPos) )
    v1->m_InputCursorPos = nPos;
}

//----- (006900E0) --------------------------------------------------------  // acclient.c:679639
void __thiscall DebugConsole::InputMoveCursorToNextWord(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  unsigned int nPos; // [sp+0h] [bp-4h]@1

  nPos = (unsigned int)this;
  v1 = this;
  if ( GlyphList::FindNextWord(this->m_pInputBuffer, this->m_InputCursorPos, &nPos) )
    v1->m_InputCursorPos = nPos;
}

//----- (00690110) --------------------------------------------------------  // acclient.c:679651
void __thiscall DebugConsole::Think(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  bool v2; // al@1
  int v3; // esi@5
  int v4; // esi@6

  v1 = this;
  v2 = this->m_WantActivateInput;
  if ( v2 || this->m_WantDeactivateInput )
  {
    this->m_IsInputActive = v2;
    this->m_WantActivateInput = 0;
    this->m_WantDeactivateInput = 0;
    if ( ICIDM::s_cidm )
    {
      if ( v2 )
      {
        ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputHandler)(&this->vfptr, 2);
        v3 = (int)&v1->vfptr;
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(7, v3, 4000);
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(1, v3, 3999);
        ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->SetTextMode)(1);
      }
      else
      {
        ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputHandler)(&this->vfptr, 2);
        v4 = (int)&v1->vfptr;
        ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(7, v4);
        ((void (__stdcall *)(_DWORD, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(1, v4);
        ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->SetTextMode)(0);
      }
    }
  }
}

//----- (006901D0) --------------------------------------------------------  // acclient.c:679688
void __thiscall DebugConsole::InvalidateTabCompletion(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // edi@2
  volatile LONG *v4; // ST00_4@5
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // edi@7
  volatile LONG *v7; // ST00_4@10

  v1 = this;
  v2 = this->m_LastTabCompletionWord.m_charbuffer;
  if ( v2 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_LastTabCompletionWord.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v5 = v1->m_LastTabCompletionString.m_charbuffer;
  if ( v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_LastTabCompletionString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
}

//----- (00690250) --------------------------------------------------------  // acclient.c:679725
void __thiscall DebugConsole::InputBackspaceCharacter(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // eax@2
  GlyphList *v4; // ecx@2

  v1 = this;
  v2 = this->m_InputCursorPos;
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = this->m_pInputBuffer;
    v1->m_InputCursorPos = v3;
    GlyphList::Delete(v4, v3, v3 + 1);
    v1->m_LastInputHistoryPos = -1;
    DebugConsole::InvalidateTabCompletion(v1);
  }
}

//----- (00690280) --------------------------------------------------------  // acclient.c:679746
void __thiscall DebugConsole::InputScrollOutputBufferUp(DebugConsole *this, const unsigned int _NumLinesToScrollUp)
{
  unsigned int v2; // eax@4
  unsigned int v3; // eax@5

  if ( this->m_OutputScrollPos == -1
    && (signed int)(this->m_pOutputBuffer->m_glyphLines.m_num - this->m_NumOutputLines) > 0 )
    this->m_OutputScrollPos = this->m_pOutputBuffer->m_glyphLines.m_num - this->m_NumOutputLines;
  v2 = this->m_OutputScrollPos;
  if ( v2 != -1 )
  {
    v3 = v2 - _NumLinesToScrollUp;
    if ( (v3 & 0x80000000) != 0 )
      v3 = 0;
    this->m_OutputScrollPos = v3;
  }
  this->m_OutputBufferIsDirty = 1;
}

//----- (006902B0) --------------------------------------------------------  // acclient.c:679766
void __thiscall DebugConsole::InputScrollOutputBufferDown(DebugConsole *this, const unsigned int _NumLinesToScrollDown)
{
  unsigned int v2; // eax@1
  GlyphList *v3; // edx@2
  unsigned int v4; // esi@2
  unsigned int v5; // eax@3
  int v6; // edx@3

  v2 = this->m_OutputScrollPos;
  if ( v2 == -1 || (v3 = this->m_pOutputBuffer, v4 = this->m_NumOutputLines, v2 >= v3->m_glyphLines.m_num - v4) )
  {
    this->m_OutputBufferIsDirty = 1;
    this->m_OutputScrollPos = -1;
  }
  else
  {
    v5 = _NumLinesToScrollDown + v2;
    this->m_OutputScrollPos = v5;
    v6 = v3->m_glyphLines.m_num - v4;
    this->m_OutputBufferIsDirty = 1;
    if ( v5 >= v6 )
      this->m_OutputScrollPos = -1;
  }
}

//----- (00690300) --------------------------------------------------------  // acclient.c:679792
void __thiscall DebugConsole::InputScrollOutputBufferToTop(DebugConsole *this)
{
  unsigned int v1; // edx@1
  bool v2; // cf@1
  bool v3; // zf@1

  v1 = this->m_pOutputBuffer->m_glyphLines.m_num;
  v2 = v1 < this->m_NumOutputLines;
  v3 = v1 == this->m_NumOutputLines;
  this->m_OutputBufferIsDirty = 1;
  if ( !v2 && !v3 )
    this->m_OutputScrollPos = 0;
}

//----- (00690320) --------------------------------------------------------  // acclient.c:679807
void __thiscall DebugConsole::InputDeleteCharacter(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  GlyphList *v2; // ecx@1
  unsigned int v3; // eax@1

  v1 = this;
  v2 = this->m_pInputBuffer;
  v3 = v1->m_InputCursorPos;
  if ( v3 < v2->m_glyphList._num_elements )
  {
    GlyphList::Delete(v2, v3, v3 + 1);
    v1->m_LastInputHistoryPos = -1;
    DebugConsole::InvalidateTabCompletion(v1);
  }
}

//----- (00690350) --------------------------------------------------------  // acclient.c:679825
void __thiscall DebugConsole::SetInputBufferContents(DebugConsole *this, PStringBase<char> *_Text)
{
  DebugConsole *v2; // esi@1
  GlyphList *v3; // ecx@1
  PSRefBufferCharData<char> *v4; // eax@3
  unsigned int v5; // ecx@3
  unsigned int v6; // edi@3
  bool v7; // cf@4
  int v8; // ecx@4
  unsigned int v9; // ecx@7
  int v10; // eax@8
  Glyph MyGlyph; // [sp+Ch] [bp-24h]@10

  v2 = this;
  v3 = this->m_pInputBuffer;
  v2->m_InputCursorPos = 0;
  if ( v3->m_glyphList._num_elements )
    GlyphList::Flush(v3);
  v4 = _Text->m_charbuffer;
  v5 = *(_DWORD *)&_Text->m_charbuffer[-1].m_data[12];
  v6 = 0;
  if ( v5 != 1 )
  {
    do
    {
      v7 = v6 < v5;
      v8 = (int)((char *)v4 + v5 - 1);
      if ( v7 )
        v8 = (int)((char *)v4 + v6);
      if ( *(_BYTE *)v8 != 10 )
      {
        v9 = *(_DWORD *)&v4[-1].m_data[12];
        if ( v6 < v9 )
          v10 = (int)((char *)v4 + v6);
        else
          v10 = (int)((char *)v4 + v9 - 1);
        Glyph::Glyph(&MyGlyph, *(_BYTE *)v10, &color, 0, 0, 8u, 0xCu);
        GlyphList::Insert(v2->m_pInputBuffer, v2->m_InputCursorPos++, &MyGlyph);
        Glyph::~Glyph(&MyGlyph);
      }
      v4 = _Text->m_charbuffer;
      v5 = *(_DWORD *)&_Text->m_charbuffer[-1].m_data[12];
      ++v6;
    }
    while ( v6 < v5 - 1 );
  }
}

//----- (00690400) --------------------------------------------------------  // acclient.c:679874
void __thiscall DebugConsole::SelectPreviousCommandInInputHistory(DebugConsole *this)
{
  unsigned int v1; // edx@1
  int v2; // eax@2
  PStringBase<char> *v3; // edx@4
  int v4; // eax@4
  int v5; // edx@5

  v1 = this->m_InputHistory.m_num;
  if ( v1 )
  {
    v2 = this->m_LastInputHistoryPos;
    if ( v2 != -1 && v2 )
    {
      v3 = this->m_InputHistory.m_data;
      v4 = v2 - 1;
      this->m_LastInputHistoryPos = v4;
      DebugConsole::SetInputBufferContents(this, &v3[v4]);
    }
    else
    {
      v5 = v1 - 1;
      this->m_LastInputHistoryPos = v5;
      DebugConsole::SetInputBufferContents(this, &this->m_InputHistory.m_data[v5]);
    }
  }
}

//----- (00690440) --------------------------------------------------------  // acclient.c:679903
void __thiscall DebugConsole::SelectNextCommandInInputHistory(DebugConsole *this)
{
  unsigned int v1; // edx@1
  int v2; // eax@2
  PStringBase<char> *v3; // edx@4
  int v4; // eax@4
  PStringBase<char> *v5; // edx@5

  v1 = this->m_InputHistory.m_num;
  if ( v1 )
  {
    v2 = this->m_LastInputHistoryPos;
    if ( v2 == -1 || v2 == v1 - 1 )
    {
      v5 = this->m_InputHistory.m_data;
      this->m_LastInputHistoryPos = 0;
      DebugConsole::SetInputBufferContents(this, &v5[this->m_LastInputHistoryPos]);
    }
    else
    {
      v3 = this->m_InputHistory.m_data;
      v4 = v2 + 1;
      this->m_LastInputHistoryPos = v4;
      DebugConsole::SetInputBufferContents(this, &v3[v4]);
    }
  }
}

//----- (00690480) --------------------------------------------------------  // acclient.c:679932
char __thiscall DebugConsole::Startup(DebugConsole *this)
{
  DebugConsole *v1; // ebx@1
  IConsoleCallbackObject *v2; // eax@2
  char *v3; // esi@6
  char *v4; // esi@9
  char *v5; // esi@14
  char *v6; // esi@17
  char *v7; // esi@22
  char *v8; // esi@25
  char *v9; // esi@28
  char *v10; // esi@31
  PStringBase<char> _Name; // [sp+1Ch] [bp-8h]@4
  PStringBase<char> _Description; // [sp+20h] [bp-4h]@4

  v1 = this;
  if ( this )
    v2 = (IConsoleCallbackObject *)&this->vfptr;
  else
    v2 = 0;
  GlobalRegistry::RegisterConsoleCallbackObject(v2);
  PStringBase<char>::PStringBase<char>(&_Description, "Force console output to always be visible, even when inactive");
  PStringBase<char>::PStringBase<char>(&_Name, "Console.AlwaysDrawOutput");
  if ( v1 != (DebugConsole *)-27 )
    GlobalRegistry::RegisterVariableInternal(
      &v1->m_AlwaysDrawOutput,
      GRVDataType_Bool,
      &_Name,
      &_Description,
      0,
      0,
      0,
      0);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Print all typed console commands to the output buffer");
  PStringBase<char>::PStringBase<char>(&_Description, "Console.EchoInput");
  if ( v1 != (DebugConsole *)-128 )
    GlobalRegistry::RegisterVariableInternal(&v1->m_EchoInput, GRVDataType_Bool, &_Description, &_Name, 0, 0, 0, 0);
  v5 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Console background window opacity (between 0.0 and 1.0 inclusive)");
  PStringBase<char>::PStringBase<char>(&_Description, "Console.BackgroundOpacity");
  if ( v1 != (DebugConsole *)-28 )
    GlobalRegistry::RegisterVariableInternal(
      &v1->m_BackgroundOpacity,
      GRVDataType_Float32,
      &_Description,
      &_Name,
      0,
      0,
      0,
      0);
  v7 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Clears the console output buffer");
  PStringBase<char>::PStringBase<char>(&_Description, "Clear");
  GlobalRegistry::RegisterCommand((bool (__cdecl *)())DebugConsole::ConsoleCommand_Clear, &_Description, &_Name);
  v9 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
  GlobalEventHandler::GetGlobalEventHandler();
  if ( ICIDM::s_cidm )
  {
    if ( v1 )
    {
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(11, &v1->vfptr, 4000);
      return 1;
    }
    ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))ICIDM::s_cidm->vfptr->RegisterInputMap)(11, 0, 4000);
  }
  return 1;
}

//----- (006906D0) --------------------------------------------------------  // acclient.c:680025
void __thiscall DebugConsole::Shutdown(DebugConsole *this)
{
  DebugConsole *v1; // ebx@1
  IConsoleCallbackObject *v2; // eax@2
  char *v3; // esi@4
  char *v4; // esi@7
  char *v5; // esi@10
  char *v6; // esi@13
  GlobalEventHandler *v7; // eax@16
  int v8; // edx@18
  PStringBase<char> _Name; // [sp+Ch] [bp-4h]@1

  _Name.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v1 = this;
  if ( this )
    v2 = (IConsoleCallbackObject *)&this->vfptr;
  else
    v2 = 0;
  GlobalRegistry::UnregisterConsoleCallbackObject(v2);
  PStringBase<char>::PStringBase<char>(&_Name, "Clear");
  GlobalRegistry::UnregisterCommand(&_Name);
  v3 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Console.EchoInput");
  GlobalRegistry::UnregisterVariable(&_Name);
  v4 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Console.AlwaysDrawOutput");
  GlobalRegistry::UnregisterVariable(&_Name);
  v5 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Console.BackgroundOpacity");
  GlobalRegistry::UnregisterVariable(&_Name);
  v6 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v7 )
  {
    if ( v1 )
      v8 = (int)&v1->vfptr;
    else
      v8 = 0;
    v7->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v7, (NoticeHandler *)v8);
  }
  if ( ICIDM::s_cidm )
  {
    if ( v1 )
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(&v1->vfptr);
    else
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(0);
  }
}

//----- (00690820) --------------------------------------------------------  // acclient.c:680083
void __thiscall DebugConsole::UpdateCoordinates(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  QuickWindow *v2; // ecx@1

  v1 = this;
  v2 = this->m_pOutputWindow;
  v1->m_NumOutputLines = v2->m_ClientAreaHeight / 0xC;
  v1->m_NumOutputCharactersPerLine = v2->m_ClientAreaWidth >> 3;
  SmartArray<PStringBase<char>,1>::Reset((SmartArray<PStringBase<char>,1> *)&v1->m_OutputLines.m_data);
  SmartArray<PStringBase<char>,1>::SetNElements(
    (SmartArray<PStringBase<char>,1> *)&v1->m_OutputLines.m_data,
    v1->m_NumOutputLines,
    1);
  v1->m_NumInputCharactersPerLine = v1->m_pInputWindow->m_ClientAreaWidth >> 3;
  v1->m_OutputBufferIsDirty = 1;
}

//----- (00690870) --------------------------------------------------------  // acclient.c:680102
void __thiscall DebugConsole::AppendTextToOutputBuffer(DebugConsole *this, PStringBase<char> *_Text)
{
  int v2; // esi@1
  unsigned int v3; // edi@4
  PSRefBufferCharData<char> *v4; // eax@5
  unsigned int v5; // ecx@5
  int v6; // eax@6
  unsigned int v7; // ecx@8
  unsigned int v8; // eax@8
  unsigned int v9; // edx@9
  int v10; // ST2C_4@14
  DebugConsole *v16; // [sp+8h] [bp-2Ch]@1
  Glyph MyGlyph; // [sp+10h] [bp-24h]@8

  v16 = this;
  v2 = *(_DWORD *)&_Text->m_charbuffer[-1].m_data[12];
  if ( v2 )
  {
    if ( !(_S138_54 & 1) )
    {
      _S138_54 |= 1u;
      GlyphText.m_data = 0;
      GlyphText.m_sizeAndDeallocate = 0;
      GlyphText.m_num = 0;
      atexit(_E139_92);
    }
    v3 = 0;
    for ( GlyphText.m_num = 0; v3 < v2 - 1; ++v3 )
    {
      v4 = _Text->m_charbuffer;
      v5 = *(_DWORD *)&_Text->m_charbuffer[-1].m_data[12];
      if ( v3 < v5 )
        v6 = (int)((char *)v4 + v3);
      else
        v6 = (int)((char *)v4 + v5 - 1);
      Glyph::Glyph(&MyGlyph, *(_BYTE *)v6, &color, 0, 0, 8u, 0xCu);
      v7 = GlyphText.m_num;
      v8 = GlyphText.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( GlyphText.m_num >= (GlyphText.m_sizeAndDeallocate & 0x7FFFFFFF) )
      {
        v9 = v8 + 1;
        if ( v8 + 1 > 8 )
        {
          if ( v9 <= 0x4000 )
          {
            v10 = v8 + 1;
            __asm { bsr     this, [esp+3Ch+var_28] }
            if ( v9 > 1 << _EAX )
              v9 = 2 * (1 << _EAX);
          }
          else if ( v9 & 0x3FFF )
          {
            v9 += 0x4000 - (v9 & 0x3FFF);
          }
        }
        else
        {
          v9 = 8;
        }
        if ( !SmartArray<Glyph,1>::grow(&GlyphText, v9) )
          goto LABEL_19;
        v7 = GlyphText.m_num;
      }
      Glyph::operator=((int)&GlyphText.m_data[v7], (int)&MyGlyph);
      ++GlyphText.m_num;
LABEL_19:
      Glyph::~Glyph(&MyGlyph);
    }
    GlyphList::AddText(v16->m_pOutputBuffer, v16->m_pOutputBuffer->m_glyphList._num_elements, &GlyphText);
    v16->m_OutputBufferIsDirty = 1;
  }
}

//----- (006909E0) --------------------------------------------------------  // acclient.c:680176
void __thiscall DebugConsole::InitOutputBuffer(DebugConsole *this)
{
  int v1; // edi@1
  GlyphList *v2; // ecx@1
  GlobalRegistryInstance *v3; // eax@1
  GlobalRegistryInstance *v4; // eax@2
  unsigned int v5; // esi@6
  int v6; // esi@7
  unsigned int v7; // ebp@7
  GlobalRegistryInstance *v8; // eax@8
  GlobalRegistryInstance *v9; // eax@10
  int v10; // ecx@14
  unsigned int v11; // edi@17
  int v12; // ecx@17
  char *v13; // esi@20
  char *v14; // esi@25
  char Source[4]; // [sp+8h] [bp-10h]@16
  PStringBase<char> TextToAdd; // [sp+Ch] [bp-Ch]@7
  int v17; // [sp+10h] [bp-8h]@1
  unsigned int NumChars; // [sp+14h] [bp-4h]@7

  v1 = (int)this;
  v2 = this->m_pOutputBuffer;
  v17 = v1;
  GlyphList::Flush(v2);
  v3 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v4 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v4 )
      GlobalRegistryInstance::GlobalRegistryInstance(v4);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  v5 = v3->m_Characters.m_nNumElements;
  if ( v5 )
  {
    TextToAdd.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v6 = v5 - 1;
    v7 = 0;
    NumChars = v6;
    if ( v6 )
    {
      v8 = GlobalRegistry::s_pcGlobalRegistry;
      do
      {
        if ( !v8 )
        {
          v9 = (GlobalRegistryInstance *)operator new(0x8100u);
          if ( v9 )
            GlobalRegistryInstance::GlobalRegistryInstance(v9);
          else
            v8 = 0;
          GlobalRegistry::s_pcGlobalRegistry = v8;
        }
        v10 = v7 + v8->m_Characters.m_nStartIndex;
        if ( (unsigned int)v10 >= 0x8000 )
          v10 -= 0x8000;
        Source[0] = v8->m_Characters.m_aMemory[v10];
        if ( Source[0] )
        {
          v11 = *(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[12];
          v12 = v11 + 1;
          if ( *(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[0] != 1
            || (unsigned int)v12 > *(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[4] )
          {
            v13 = &TextToAdd.m_charbuffer[-2].m_data[12];
            PStringBase<char>::allocate_ref_buffer(&TextToAdd, v11);
            strcpy(TextToAdd.m_charbuffer->m_data, v13 + 20);
            if ( !InterlockedDecrement((volatile LONG *)v13 + 1) && v13 )
              (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
          }
          else
          {
            *(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[12] = v12;
            *(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[8] = -1;
          }
          _strncpy((char *)TextToAdd.m_charbuffer + v11 - 1, Source, 1u);
          v1 = v17;
          v6 = NumChars;
          TextToAdd.m_charbuffer->m_data[*(_DWORD *)&TextToAdd.m_charbuffer[-1].m_data[12] - 1] = 0;
          v8 = GlobalRegistry::s_pcGlobalRegistry;
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
    DebugConsole::AppendTextToOutputBuffer((DebugConsole *)v1, &TextToAdd);
    v14 = &TextToAdd.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&TextToAdd.m_charbuffer[-1]) && v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  *(_BYTE *)(v1 + 40) = 1;
}

//----- (00690B70) --------------------------------------------------------  // acclient.c:680274
void __thiscall DebugConsole::DebugConsole(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  QuickWindow **v2; // edi@1
  volatile LONG *v3; // ST1C_4@1
  volatile LONG *v4; // ST1C_4@1
  GlyphList *v5; // eax@1
  GlyphList *v6; // eax@2
  GlyphList *v7; // eax@4
  GlyphList *v8; // eax@5
  GlyphList *v9; // ecx@7
  TResult result; // [sp+Ch] [bp-4h]@7

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (CInputHandlerVtbl *)&CInputHandler::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->vfptr = (IConsoleCallbackObjectVtbl *)&IConsoleCallbackObject::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&DebugConsole::vftable;
  this->vfptr = (CInputHandlerVtbl *)&DebugConsole::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->vfptr = (IConsoleCallbackObjectVtbl *)&DebugConsole::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&DebugConsole::vftable;
  this->m_WantActivateInput = 0;
  this->m_WantDeactivateInput = 0;
  this->m_IsInputActive = 0;
  this->m_AlwaysDrawOutput = 0;
  LODWORD(this->m_BackgroundOpacity) = 1065353216;
  this->m_pInputBuffer = 0;
  this->m_pOutputBuffer = 0;
  this->m_OutputBufferIsDirty = 1;
  this->m_pOutputWindow = 0;
  this->m_pInputWindow = 0;
  this->m_NumOutputLines = 0;
  this->m_NumOutputCharactersPerLine = 0;
  this->m_OutputScrollPos = -1;
  this->m_OutputLines.m_data = 0;
  this->m_OutputLines.m_sizeAndDeallocate = 0;
  this->m_OutputLines.m_num = 0;
  this->m_NumInputCharactersPerLine = 0;
  this->m_InputCursorPos = 0;
  this->m_IsInputCursorVisible = 0;
  *(_QWORD *)&this->m_LastInputCursorStateTime = 0i64;
  v2 = &this->m_pOutputWindow;
  this->m_InputHistory.m_data = 0;
  this->m_InputHistory.m_sizeAndDeallocate = 0;
  this->m_InputHistory.m_num = 0;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_LastTabCompletionWord.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_LastTabCompletionString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->m_LastInputHistoryPos = -1;
  v1->m_pOutputBackgroundTexture = 0;
  v1->m_pInputBackgroundTexture = 0;
  v1->m_EchoInput = 0;
  v5 = (GlyphList *)operator new(0x34u);
  if ( v5 )
    GlyphList::GlyphList(v5);
  else
    v6 = 0;
  v1->m_pInputBuffer = v6;
  v7 = (GlyphList *)operator new(0x34u);
  if ( v7 )
    GlyphList::GlyphList(v7);
  else
    v8 = 0;
  v9 = v1->m_pInputBuffer;
  v1->m_pOutputBuffer = v8;
  v9->m_nMaxCharacters = 1024;
  v1->m_pInputBuffer->m_bTrimFromTop = 0;
  v1->m_pOutputBuffer->m_nMaxCharacters = 0xFFFF;
  v1->m_pOutputBuffer->m_bTrimFromTop = 1;
  if ( (QuickWindow::Create(&result, v2, 20, 20, 0x320u, 0x12Cu, 8u, 6u)->m_val & 0x80000000) == 0
    && (QuickWindow::Create(&result, &v1->m_pInputWindow, 20, 330, 0x320u, 0x19u, 8u, 6u)->m_val & 0x80000000) == 0 )
  {
    DebugConsole::UpdateCoordinates(v1);
    DebugConsole::InitOutputBuffer(v1);
  }
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 79BA88: using guessed type void (__thiscall *CInputHandler::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 8003F8: using guessed type void (__thiscall *IConsoleCallbackObject::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 800534: using guessed type void *DebugConsole::vftable;
// 800540: using guessed type int (__stdcall *DebugConsole::vftable)(PStringBase<char> *_Text);
// 800544: using guessed type void (__thiscall *DebugConsole::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 80055C: using guessed type int (__thiscall *DebugConsole::vftable)(void *, char);

//----- (00690D10) --------------------------------------------------------  // acclient.c:680366
DebugConsole *__thiscall DebugConsole::vector_deleting_destructor(DebugConsole *this, unsigned int a2)
{
  return DebugConsole::vector_deleting_destructor((DebugConsole *)((char *)this - 20), a2);
}

//----- (00690D20) --------------------------------------------------------  // acclient.c:680372
void __thiscall DebugConsole::~DebugConsole(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  GlyphList *v2; // ecx@1
  GlyphList *v3; // ecx@3
  QuickWindow *v4; // ecx@5
  bool v5; // zf@6
  QuickWindow *v6; // ecx@9
  RenderTexture *v7; // ecx@13
  RenderTexture *v8; // ecx@15
  int v9; // edi@17
  int v10; // edi@20
  PStringBase<char> *v11; // ecx@24
  PStringBase<char> *v12; // ecx@27

  v1 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&DebugConsole::vftable;
  this->vfptr = (CInputHandlerVtbl *)&DebugConsole::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  this->vfptr = (IConsoleCallbackObjectVtbl *)&DebugConsole::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&DebugConsole::vftable;
  DebugConsole::sm_pCurrentDebugConsole = 0;
  DebugConsole::Shutdown(this);
  v2 = v1->m_pInputBuffer;
  v1->m_AlwaysDrawOutput = 0;
  LODWORD(v1->m_BackgroundOpacity) = 1065353216;
  v1->m_IsInputActive = 0;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->m_pOutputBuffer;
  v1->m_pInputBuffer = 0;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->m_pOutputWindow;
  v1->m_pOutputBuffer = 0;
  if ( v4 )
  {
    v5 = v4->m_cRef-- == 1;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_pOutputWindow = 0;
  }
  v6 = v1->m_pInputWindow;
  if ( v6 )
  {
    v5 = v6->m_cRef-- == 1;
    if ( v5 )
      ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    v1->m_pInputWindow = 0;
  }
  v7 = v1->m_pOutputBackgroundTexture;
  if ( v7 )
  {
    ((void (*)(void))v7->vfptr->Release)();
    v1->m_pOutputBackgroundTexture = 0;
  }
  v8 = v1->m_pInputBackgroundTexture;
  if ( v8 )
  {
    ((void (*)(void))v8->vfptr->Release)();
    v1->m_pInputBackgroundTexture = 0;
  }
  v9 = (int)&v1->m_LastTabCompletionString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = (int)&v1->m_LastTabCompletionWord.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  if ( (v1->m_InputHistory.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v11 = v1->m_InputHistory.m_data;
    if ( v11 )
      PStringBase<unsigned short>::vector_deleting_destructor(v11, 3u);
  }
  if ( (v1->m_OutputLines.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v12 = v1->m_OutputLines.m_data;
    if ( v12 )
      PStringBase<unsigned short>::vector_deleting_destructor(v12, 3u);
  }
  v1->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->UnregisterCallback)(&v1->vfptr);
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 800534: using guessed type void *DebugConsole::vftable;
// 800540: using guessed type int (__stdcall *DebugConsole::vftable)(PStringBase<char> *_Text);
// 800544: using guessed type void (__thiscall *DebugConsole::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 80055C: using guessed type int (__thiscall *DebugConsole::vftable)(void *, char);
// 8F84A0: using guessed type struct DebugConsole *DebugConsole::sm_pCurrentDebugConsole;

//----- (00690E70) --------------------------------------------------------  // acclient.c:680468
TResult *__cdecl DebugConsole::Create(TResult *result, DebugConsole **_pOutDebugConsole)
{
  DebugConsole *v2; // eax@1
  DebugConsole *v3; // eax@2
  char v4; // al@5
  DebugConsole *v5; // ecx@5
  TResult *v6; // eax@9

  v2 = (DebugConsole *)operator new(0x88u);
  if ( v2 )
    DebugConsole::DebugConsole(v2);
  else
    v3 = 0;
  *_pOutDebugConsole = v3;
  if ( !v3 )
  {
LABEL_9:
    v6 = result;
    result->m_val = -2147467259;
    return v6;
  }
  v4 = DebugConsole::Startup(v3);
  v5 = *_pOutDebugConsole;
  if ( !v4 )
  {
    if ( v5 )
      ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
    *_pOutDebugConsole = 0;
    goto LABEL_9;
  }
  v6 = result;
  DebugConsole::sm_pCurrentDebugConsole = *_pOutDebugConsole;
  result->m_val = 0;
  return v6;
}
// 8F84A0: using guessed type struct DebugConsole *DebugConsole::sm_pCurrentDebugConsole;

//----- (00690EE0) --------------------------------------------------------  // acclient.c:680506
void __thiscall DebugConsole::ConsoleCallback_OnTextAdded(DebugConsole *this, PStringBase<char> *_Text)
{
  DebugConsole::AppendTextToOutputBuffer((DebugConsole *)((char *)this - 16), _Text);
}

//----- (00690EF0) --------------------------------------------------------  // acclient.c:680512
DebugConsole *__thiscall DebugConsole::vector_deleting_destructor(DebugConsole *this, unsigned int a2)
{
  DebugConsole *v2; // esi@1

  v2 = this;
  DebugConsole::~DebugConsole(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00690F10) --------------------------------------------------------  // acclient.c:680524
bool __thiscall DebugConsole::OnAction(DebugConsole *this, InputEvent *i_evt)
{
  DebugConsole *v2; // esi@1
  bool v3; // al@5
  unsigned int v4; // eax@9
  unsigned int v5; // eax@13
  PStringBase<char> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v2 = this;
  if ( i_evt->m_InputAction == 86 )
  {
$L113234:
    v3 = 1;
  }
  else
  {
    if ( BYTE2(this->m_cRef) && i_evt->m_fStart )
    {
      switch ( i_evt->m_InputAction )
      {
        case 0x1Eu:
          DebugConsole::SelectPreviousCommandInInputHistory((DebugConsole *)((char *)this - 20));
          return 1;
        case 0x1Fu:
          DebugConsole::SelectNextCommandInInputHistory((DebugConsole *)((char *)this - 20));
          return 1;
        case 5u:
          DebugConsole::InputScrollOutputBufferUp((DebugConsole *)((char *)this - 20), 1u);
          return 1;
        case 6u:
          DebugConsole::InputScrollOutputBufferDown((DebugConsole *)((char *)this - 20), 1u);
          return 1;
        case 0x16u:
          v4 = this->m_OutputScrollPos;
          if ( v4 )
            this->m_OutputScrollPos = v4 - 1;
          return 1;
        case 0x18u:
          DebugConsole::InputMoveCursorToPreviousWord((DebugConsole *)((char *)this - 20));
          return 1;
        case 0x17u:
          v5 = this->m_OutputScrollPos;
          if ( (char *)(void (__thiscall *)(NoticeHandler *, unsigned int, unsigned int))v5 < (char *)this->vfptr->RecvNotice_ItemAttributesChanged )
            this->m_OutputScrollPos = v5 + 1;
          return 1;
        case 0x19u:
          DebugConsole::InputMoveCursorToNextWord((DebugConsole *)((char *)this - 20));
          return 1;
        case 0x1Au:
          this->m_OutputScrollPos = 0;
          return 1;
        case 0x1Cu:
          DebugConsole::InputScrollOutputBufferToTop((DebugConsole *)((char *)this - 20));
          return 1;
        case 0x1Bu:
          this->m_OutputScrollPos = (unsigned int)this->vfptr->RecvNotice_ItemAttributesChanged;
          return 1;
        case 0x1Du:
          *(_DWORD *)&this->m_OutputBufferIsDirty = -1;
          LOBYTE(this->vfptr) = 1;
          return 1;
        case 0x26u:
          DebugConsole::InputDeleteCharacter((DebugConsole *)((char *)this - 20));
          return 1;
        case 0x20u:
          DebugConsole::InputScrollOutputBufferUp(
            (DebugConsole *)((char *)this - 20),
            (const unsigned int)(&this->m_pInputBuffer[-1].m_bOneLine + 3));
          return 1;
        case 0x21u:
          DebugConsole::InputScrollOutputBufferDown(
            (DebugConsole *)((char *)this - 20),
            (const unsigned int)(&this->m_pInputBuffer[-1].m_bOneLine + 3));
          return 1;
        case 0x23u:
          this->m_InputHistory.m_data = (PStringBase<char> *)-1;
          return 1;
        case 0x24u:
          PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&i_evt);
          if ( Device::GetStringFromClipboard() )
          {
            PStringBase<unsigned short>::to_spstring((PStringBase<unsigned short> *)&i_evt, &result, 0);
            DebugConsole::SetInputBufferContents((DebugConsole *)((char *)v2 - 20), &result);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          }
          v2->m_InputHistory.m_data = (PStringBase<char> *)-1;
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_evt);
          goto $L113234;
        case 0x22u:
        case 0x28u:
          goto $L113234;
        default:
          break;
      }
    }
    v3 = 0;
  }
  return v3;
}

//----- (00691130) --------------------------------------------------------  // acclient.c:680626
void __thiscall DebugConsole::InputEnter(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  int v2; // eax@6
  PSRefBufferCharData<char> *v3; // eax@8
  int v4; // ecx@8
  int v5; // edi@10
  char *v6; // edi@13
  char *v7; // edi@18
  char *v8; // edi@21
  char *v9; // esi@26
  PStringBase<char> Text; // [sp+8h] [bp-10h]@6
  PStringBase<char> InputText; // [sp+Ch] [bp-Ch]@5
  PStringBase<unsigned short> InputTextW; // [sp+10h] [bp-8h]@4
  PStringBase<char> v13; // [sp+14h] [bp-4h]@8

  v1 = this;
  if ( this->m_OutputScrollPos != -1 )
  {
    this->m_OutputScrollPos = -1;
    this->m_OutputBufferIsDirty = 1;
  }
  if ( !this->m_pInputBuffer->m_glyphList._num_elements )
    goto LABEL_24;
  InputTextW.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( GlyphList::InqText(v1->m_pInputBuffer, 0, &InputTextW) )
  {
    PStringBase<unsigned short>::to_spstring(&InputTextW, &InputText, 0);
    if ( v1->m_EchoInput )
    {
      PStringBase<char>::PStringBase<char>(&Text, "Console: \"");
      v2 = *(_DWORD *)&InputText.m_charbuffer[-1].m_data[12];
      if ( v2 != 1 )
        PStringBase<char>::append_n_chars(&Text, InputText.m_charbuffer->m_data, v2 - 1);
      PStringBase<char>::PStringBase<char>(&v13, "\"\n\n");
      v3 = v13.m_charbuffer;
      v4 = *(_DWORD *)&v13.m_charbuffer[-1].m_data[12];
      if ( v4 != 1 )
      {
        PStringBase<char>::append_n_chars(&Text, v13.m_charbuffer->m_data, v4 - 1);
        v3 = v13.m_charbuffer;
      }
      v5 = (int)&v3[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      GlobalRegistry::OutputText(&Text);
      v6 = &Text.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&Text.m_charbuffer[-1]) && v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    }
    GlobalRegistry::ProcessCommand(&InputText);
    if ( v1->m_LastInputHistoryPos == -1 )
      SmartArray<PStringBase<char>,1>::AddToEnd(
        (SmartArray<PStringBase<char>,1> *)&v1->m_InputHistory.m_data,
        &InputText);
    v1->m_LastInputHistoryPos = -1;
    DebugConsole::InvalidateTabCompletion(v1);
    v7 = &InputText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&InputText.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    v8 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]) )
    {
      if ( v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
    }
LABEL_24:
    GlyphList::Flush(v1->m_pInputBuffer);
    v1->m_InputCursorPos = 0;
    return;
  }
  v9 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
}

//----- (006912E0) --------------------------------------------------------  // acclient.c:680704
void __thiscall DebugConsole::RefreshOutputBuffer(DebugConsole *this)
{
  DebugConsole *v1; // ebx@1
  QuickWindow *v2; // eax@2
  GlyphList *v3; // ecx@2
  GlyphList *v4; // eax@3
  ListNode<Glyph> *v5; // ecx@3
  unsigned int v6; // esi@3
  unsigned int v7; // eax@3
  int v8; // esi@3
  bool v9; // zf@7
  int v10; // ebp@8
  char *v11; // edi@11
  GlyphList *v12; // eax@15
  unsigned int v13; // ecx@15
  GlyphLine *v14; // edx@16
  unsigned int v15; // edi@16
  signed int v16; // esi@16
  int v17; // eax@18
  unsigned int v18; // eax@24
  Glyph *v19; // ebp@25
  PSRefBufferCharData<char> *v20; // esi@32
  unsigned int v21; // ebp@32
  PSRefBufferCharData<char> *v22; // eax@32
  int v23; // edi@33
  bool v24; // cf@40
  char *v25; // esi@41
  volatile LONG *v26; // ST0C_4@41
  PStringBase<unsigned short> LineString; // [sp+Ch] [bp-30h]@7
  unsigned int l; // [sp+10h] [bp-2Ch]@7
  unsigned int v29; // [sp+14h] [bp-28h]@8
  int v30; // [sp+18h] [bp-24h]@8
  unsigned int CurrentGlyphIndex; // [sp+1Ch] [bp-20h]@3
  int GLHeight; // [sp+20h] [bp-1Ch]@2
  int GLWidth; // [sp+24h] [bp-18h]@2
  unsigned __int16 str[2]; // [sp+28h] [bp-14h]@31
  PStringBase<char> result; // [sp+2Ch] [bp-10h]@32
  ListIterator<Glyph> GlyphIter; // [sp+30h] [bp-Ch]@3

  v1 = this;
  if ( this->m_OutputBufferIsDirty )
  {
    v2 = this->m_pOutputWindow;
    v3 = this->m_pOutputBuffer;
    GLWidth = 0;
    GLHeight = 0;
    if ( GlyphList::Recalculate(v3, v2->m_ClientAreaWidth, 0, &GLWidth, &GLHeight) )
    {
      v4 = v1->m_pOutputBuffer;
      v5 = v4->m_glyphList._head;
      v6 = v4->m_glyphLines.m_num;
      v7 = v1->m_OutputScrollPos;
      v8 = v6 - v1->m_NumOutputLines;
      GlyphIter._current = v5;
      CurrentGlyphIndex = 0;
      if ( v7 != -1 )
      {
        if ( (signed int)v7 < v8 )
          v8 = v7;
        else
          v1->m_OutputScrollPos = -1;
      }
      LineString.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v9 = v1->m_NumOutputLines == 0;
      l = 0;
      if ( !v9 )
      {
        v10 = v8;
        v30 = v8;
        v29 = 16 * v8;
        while ( 1 )
        {
          if ( (wchar_t *)LineString.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
          {
            v11 = (char *)&LineString.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&LineString.m_charbuffer[-1].m_data[8]) && v11 )
              (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
            LineString.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
            InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
          }
          v12 = v1->m_pOutputBuffer;
          v13 = v12->m_glyphLines.m_num;
          if ( v10 < v13 )
          {
            v14 = v12->m_glyphLines.m_data;
            v15 = v14[v29 / 0x10].m_nIndex;
            v16 = -1;
            if ( v10 + 1 < v13 )
              v16 = v14[v29 / 0x10 + 1].m_nIndex;
            while ( 1 )
            {
              v17 = *(_DWORD *)&LineString.m_charbuffer[-1].m_data[14];
              if ( v17 )
              {
                if ( v17 - 1 >= v1->m_NumOutputCharactersPerLine )
                  break;
              }
              if ( v15 >= v1->m_pOutputBuffer->m_glyphList._num_elements || v16 != -1 && v15 >= v16 )
                break;
              if ( CurrentGlyphIndex >= v15 )
              {
                v19 = &GlyphIter._current->data;
              }
              else
              {
                v18 = v15 - CurrentGlyphIndex;
                CurrentGlyphIndex = v15;
                do
                {
                  v19 = &GlyphIter._current->data;
                  if ( GlyphIter._current )
                  {
                    GlyphIter._current = GlyphIter._current->next;
                    v19 = &GlyphIter._current->data;
                  }
                  --v18;
                }
                while ( v18 );
              }
              if ( (unsigned __int8)Glyph::IsNewLine(v19) )
                break;
              *(_DWORD *)str = v19->m_data;
              PStringBase<unsigned short>::append_n_chars(&LineString, str, 1u);
              ++v15;
            }
          }
          PStringBase<unsigned short>::to_spstring(&LineString, &result, 0);
          v20 = result.m_charbuffer;
          v21 = (unsigned int)&v1->m_OutputLines.m_data[l];
          v22 = *(PSRefBufferCharData<char> **)v21;
          if ( *(PSRefBufferCharData<char> **)v21 != result.m_charbuffer )
          {
            v23 = (int)&v22[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&v22[-1]) && v23 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
            *(_DWORD *)v21 = v20;
            InterlockedIncrement((volatile LONG *)&v20[-1]);
          }
          if ( !InterlockedDecrement((volatile LONG *)&v20[-1]) && v20 != (PSRefBufferCharData<char> *)20 )
            (**(void (__thiscall ***)(char *, signed int))&v20[-2].m_data[12])(&v20[-2].m_data[12], 1);
          v24 = l++ + 1 < v1->m_NumOutputLines;
          v29 += 16;
          ++v30;
          if ( !v24 )
            break;
          v10 = v30;
        }
      }
      v25 = (char *)&LineString.m_charbuffer[-1].m_data[6];
      v26 = (volatile LONG *)&LineString.m_charbuffer[-1].m_data[8];
      v1->m_OutputBufferIsDirty = 0;
      if ( !InterlockedDecrement(v26) )
      {
        if ( v25 )
          (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
      }
    }
  }
}

//----- (00691520) --------------------------------------------------------  // acclient.c:680866
void __thiscall DebugConsole::Render(DebugConsole *this)
{
  DebugConsole *v1; // esi@1
  bool v2; // al@3
  int v3; // eax@6
  QuickWindow *v4; // ecx@6
  QuickWindow *v5; // eax@7
  int v6; // edx@7
  unsigned int v7; // ecx@7
  int v8; // edi@7
  unsigned int v9; // ebp@7
  unsigned int v10; // eax@7
  int v11; // ecx@7
  const int v12; // ebx@7
  unsigned int v13; // eax@9
  int v14; // eax@16
  QuickWindow *v15; // ecx@16
  unsigned int v16; // edi@20
  const int v17; // ebp@21
  bool v18; // al@23
  unsigned int v19; // ebp@25
  int v20; // ebp@25
  PSRefBufferCharData<char> *v21; // ecx@25
  unsigned int v22; // eax@25
  unsigned int v23; // ebx@25
  bool v24; // cf@27
  int v25; // eax@27
  unsigned int v26; // ebp@30
  int v27; // ecx@30
  int v28; // edi@33
  int v29; // edi@40
  char *v30; // edi@43
  int v31; // edi@46
  bool v32; // al@52
  int v33; // esi@53
  float ClipTop; // [sp+10h] [bp-94h]@8
  float ClipRight; // [sp+14h] [bp-90h]@8
  PStringBase<char> TempInputText; // [sp+18h] [bp-8Ch]@8
  bool WantDrawCursor; // [sp+1Fh] [bp-85h]@23
  char Source[4]; // [sp+20h] [bp-84h]@29
  float ClipLeft; // [sp+24h] [bp-80h]@7
  float ClipBottom; // [sp+28h] [bp-7Ch]@8
  const unsigned int LastCharacterOnLine; // [sp+2Ch] [bp-78h]@7
  Vector3 ClipPoints[4]; // [sp+30h] [bp-74h]@8
  unsigned int TopSITop; // [sp+60h] [bp-44h]@7
  RGBAColor ConsoleOutputScrollColor; // [sp+64h] [bp-40h]@3
  RGBAColor ConsoleOutputBGColor; // [sp+74h] [bp-30h]@3
  RGBAColor ConsoleInputCursorColor; // [sp+84h] [bp-20h]@3
  RGBAColor ConsoleInputBGColor; // [sp+94h] [bp-10h]@3

  v1 = this;
  if ( !this->m_IsInputActive && !this->m_AlwaysDrawOutput )
    return;
  RenderDeviceD3D::SetFillMode((RenderDeviceD3D *)RenderDevice::render_device, FILLMODE_SOLID);
  ConsoleOutputBGColor.a = v1->m_BackgroundOpacity;
  v2 = v1->m_IsInputActive;
  LODWORD(ConsoleOutputBGColor.r) = 1065353216;
  LODWORD(ConsoleOutputBGColor.g) = 1065353216;
  LODWORD(ConsoleOutputBGColor.b) = 1065353216;
  LODWORD(ConsoleOutputScrollColor.r) = 1053609165;
  LODWORD(ConsoleOutputScrollColor.g) = 1053609165;
  LODWORD(ConsoleOutputScrollColor.b) = 1053609165;
  LODWORD(ConsoleOutputScrollColor.a) = 1065353216;
  LODWORD(ConsoleInputBGColor.r) = 1065353216;
  LODWORD(ConsoleInputBGColor.g) = 1065353216;
  LODWORD(ConsoleInputBGColor.b) = 1065353216;
  ConsoleInputBGColor.a = ConsoleOutputBGColor.a;
  LODWORD(ConsoleInputCursorColor.r) = 1065353216;
  LODWORD(ConsoleInputCursorColor.g) = 1065353216;
  LODWORD(ConsoleInputCursorColor.b) = 1065353216;
  LODWORD(ConsoleInputCursorColor.a) = 1065353216;
  if ( v2 || v1->m_AlwaysDrawOutput )
  {
    DebugConsole::RefreshOutputBuffer(v1);
    if ( !v1->m_pOutputBackgroundTexture )
    {
      v3 = DBObj::GetByEnum(18, 2, 0x1Eu);
      v4 = v1->m_pOutputWindow;
      v1->m_pOutputBackgroundTexture = (RenderTexture *)v3;
      QuickWindow::SetBackgroundTexture(v4, (RenderTexture *)v3);
    }
    QuickWindow::SetColorAndOpacity(v1->m_pOutputWindow, &ConsoleOutputBGColor);
    ((void (*)(void))v1->m_pOutputWindow->vfptr[1].__vecDelDtor)();
    v5 = v1->m_pOutputWindow;
    v6 = v5->m_ClientAreaX;
    v7 = v5->m_ClientAreaWidth;
    v8 = v5->m_ClientAreaY;
    v9 = v5->m_ClientAreaHeight;
    v10 = v1->m_OutputScrollPos;
    v11 = v6 + v7;
    v12 = v11 - 15;
    LODWORD(ClipLeft) = v11 - 5;
    TopSITop = v8 + 4;
    LastCharacterOnLine = v8 + 14;
    if ( v10 != -1 )
    {
      SceneTool::IdentityMatrices();
      SceneTool::ViewportToClip(v12, v8 + v9 - 15, &ClipRight, &ClipTop);
      SceneTool::ViewportToClip(SLODWORD(ClipLeft), v8 + v9 - 5, (float *)&TempInputText, &ClipBottom);
      ClipPoints[0].x = ClipRight;
      ClipPoints[1].z = ClipBottom;
      LODWORD(ClipPoints[2].x) = TempInputText.m_charbuffer;
      ClipPoints[0].z = ClipTop;
      ClipPoints[2].z = ClipTop;
      ClipPoints[1].x = (*(float *)&TempInputText.m_charbuffer - ClipRight) * 0.5 + ClipRight;
      LODWORD(ClipPoints[0].y) = 0;
      LODWORD(ClipPoints[1].y) = 0;
      LODWORD(ClipPoints[2].y) = 0;
      SceneTool::DrawTriangle(
        ClipPoints,
        &ClipPoints[1],
        &ClipPoints[2],
        &ConsoleOutputScrollColor,
        0,
        0,
        CULLMODE_CW,
        BLEND_SRCALPHA,
        BLEND_INVSRCALPHA);
    }
    v13 = v1->m_OutputScrollPos;
    if ( v13 == -1 )
    {
      if ( (signed int)(v1->m_pOutputBuffer->m_glyphLines.m_num - v1->m_NumOutputLines) <= 0 )
        goto LABEL_14;
    }
    else if ( !v13 )
    {
      goto LABEL_14;
    }
    SceneTool::IdentityMatrices();
    SceneTool::ViewportToClip(v12, TopSITop, &ClipRight, &ClipBottom);
    SceneTool::ViewportToClip(SLODWORD(ClipLeft), LastCharacterOnLine, (float *)&TempInputText, &ClipTop);
    vector_constructor_iterator(
      ClipPoints,
      0xCu,
      3,
      (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
    LODWORD(ClipPoints[0].x) = TempInputText.m_charbuffer;
    ClipPoints[1].z = ClipBottom;
    ClipPoints[2].x = ClipRight;
    ClipPoints[0].z = ClipTop;
    ClipPoints[2].z = ClipTop;
    ClipPoints[1].x = (*(float *)&TempInputText.m_charbuffer - ClipRight) * 0.5 + ClipRight;
    LODWORD(ClipPoints[0].y) = 0;
    LODWORD(ClipPoints[1].y) = 0;
    LODWORD(ClipPoints[2].y) = 0;
    SceneTool::DrawTriangle(
      ClipPoints,
      &ClipPoints[1],
      &ClipPoints[2],
      &ConsoleOutputScrollColor,
      0,
      0,
      CULLMODE_CW,
      BLEND_SRCALPHA,
      BLEND_INVSRCALPHA);
  }
LABEL_14:
  if ( v1->m_IsInputActive )
  {
    if ( !v1->m_pInputBackgroundTexture )
    {
      v14 = DBObj::GetByEnum(19, 2, 0x1Eu);
      v15 = v1->m_pInputWindow;
      v1->m_pInputBackgroundTexture = (RenderTexture *)v14;
      QuickWindow::SetBackgroundTexture(v15, (RenderTexture *)v14);
    }
    QuickWindow::SetColorAndOpacity(v1->m_pInputWindow, &ConsoleInputBGColor);
    ((void (*)(void))v1->m_pInputWindow->vfptr[1].__vecDelDtor)();
  }
  RenderDeviceD3D::BeginRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
  if ( v1->m_IsInputActive || v1->m_AlwaysDrawOutput )
  {
    DebugConsole::RefreshOutputBuffer(v1);
    v16 = 0;
    if ( v1->m_NumOutputLines )
    {
      v17 = 0;
      do
      {
        QuickWindow::RenderText(
          v1->m_pOutputWindow,
          0,
          v17,
          v1->m_OutputLines.m_data[v16++].m_charbuffer->m_data,
          0xFFEAEAEA);
        v17 += 12;
      }
      while ( v16 < v1->m_NumOutputLines );
    }
  }
  v18 = v1->m_IsInputActive;
  WantDrawCursor = 0;
  if ( !v18 )
    goto LABEL_49;
  QuickWindow::RenderText(v1->m_pInputWindow, 0, 0, ">", 0xFF999999);
  ClipRight = *(float *)&PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( GlyphList::InqText(v1->m_pInputBuffer, 0, (PStringBase<unsigned short> *)&ClipRight) )
  {
    PStringBase<unsigned short>::to_spstring((PStringBase<unsigned short> *)&ClipRight, &TempInputText, 0);
    v19 = v1->m_NumInputCharactersPerLine;
    ClipTop = *(float *)&PStringBase<char>::s_NullBuffer.m_charbuffer;
    v20 = v19 - 1;
    LastCharacterOnLine = v20;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v21 = TempInputText.m_charbuffer;
    v22 = *(_DWORD *)&TempInputText.m_charbuffer[-1].m_data[12];
    v23 = 0;
    if ( v22 != 1 )
    {
      do
      {
        if ( v23 >= v20 )
          break;
        v24 = v23 < v22;
        v25 = (int)((char *)v21 + v22 - 1);
        if ( v24 )
          v25 = (int)((char *)v21 + v23);
        Source[0] = *(_BYTE *)v25;
        if ( Source[0] )
        {
          v26 = *(_DWORD *)(LODWORD(ClipTop) - 4);
          v27 = v26 + 1;
          if ( *(_DWORD *)(LODWORD(ClipTop) - 16) != 1 || (unsigned int)v27 > *(_DWORD *)(LODWORD(ClipTop) - 12) )
          {
            v28 = LODWORD(ClipTop) - 20;
            PStringBase<char>::allocate_ref_buffer((PStringBase<char> *)&ClipTop, v26);
            strcpy(LODWORD(ClipTop), (const char *)(v28 + 20));
            if ( !InterlockedDecrement((volatile LONG *)(v28 + 4)) && v28 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
          }
          else
          {
            *(_DWORD *)(LODWORD(ClipTop) - 4) = v27;
            *(_DWORD *)(LODWORD(ClipTop) - 8) = -1;
          }
          _strncpy((char *)(LODWORD(ClipTop) + v26 - 1), Source, 1u);
          v20 = LastCharacterOnLine;
          *(_BYTE *)(*(_DWORD *)(LODWORD(ClipTop) - 4) + LODWORD(ClipTop) - 1) = 0;
          v21 = TempInputText.m_charbuffer;
        }
        v22 = *(_DWORD *)&v21[-1].m_data[12];
        ++v23;
      }
      while ( v23 < v22 - 1 );
    }
    if ( *(_DWORD *)(LODWORD(ClipTop) - 4) - 1 < (unsigned int)v20 )
      WantDrawCursor = 1;
    QuickWindow::RenderText(v1->m_pInputWindow, 8, 0, LODWORD(ClipTop), 0xFFFFFFFF);
    v29 = LODWORD(ClipTop) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(LODWORD(ClipTop) - 20 + 4)) && v29 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
    v30 = &TempInputText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&TempInputText.m_charbuffer[-1]) && v30 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    v31 = LODWORD(ClipRight) - 20;
    if ( !InterlockedDecrement((volatile LONG *)(LODWORD(ClipRight) - 20 + 4)) && v31 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
LABEL_49:
    RenderDeviceD3D::EndRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
    if ( v1->m_IsInputActive && WantDrawCursor )
    {
      if ( Timer::local_time - v1->m_LastInputCursorStateTime > 0.2000000029802322 )
      {
        v32 = v1->m_IsInputCursorVisible;
        v1->m_LastInputCursorStateTime = Timer::local_time;
        v1->m_IsInputCursorVisible = v32 == 0;
      }
      if ( v1->m_IsInputCursorVisible )
      {
        SceneTool::IdentityMatrices();
        SceneTool::ViewportToClip(
          v1->m_pInputWindow->m_ClientAreaX + 8 * v1->m_InputCursorPos + 8,
          v1->m_pInputWindow->m_ClientAreaY,
          &ClipLeft,
          &ClipTop);
        SceneTool::ViewportToClip(
          v1->m_pInputWindow->m_ClientAreaX + 8 * v1->m_InputCursorPos + 15,
          v1->m_pInputWindow->m_ClientAreaY + 11,
          &ClipRight,
          (float *)&TempInputText);
        ClipPoints[0].x = ClipLeft;
        ClipPoints[1].x = ClipLeft;
        ClipPoints[0].z = ClipTop;
        LODWORD(ClipPoints[1].z) = TempInputText.m_charbuffer;
        LODWORD(ClipPoints[2].z) = TempInputText.m_charbuffer;
        ClipPoints[3].x = ClipRight;
        ClipPoints[2].x = ClipRight;
        LODWORD(ClipPoints[0].y) = 0;
        LODWORD(ClipPoints[1].y) = 0;
        LODWORD(ClipPoints[2].y) = 0;
        LODWORD(ClipPoints[3].y) = 0;
        ClipPoints[3].z = ClipTop;
        SceneTool::DrawPolygon(
          ClipPoints,
          4u,
          &ConsoleInputCursorColor,
          0,
          0,
          CULLMODE_CW,
          BLEND_SRCALPHA,
          BLEND_INVSRCALPHA);
      }
    }
    RenderDeviceD3D::SetFillMode(
      (RenderDeviceD3D *)RenderDevice::render_device,
      (FillModeType)(3 - (RenderDevice::render_device->m_WireframeMode != 0)));
    return;
  }
  v33 = LODWORD(ClipRight) - 20;
  if ( !InterlockedDecrement((volatile LONG *)(LODWORD(ClipRight) - 20 + 4)) && v33 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v33)(v33, 1);
}

//----- (00691BF0) --------------------------------------------------------  // acclient.c:681182
void __thiscall DebugConsole::InputTabCompletion(DebugConsole *this, const bool _SearchForward)
{
  DebugConsole *v2; // esi@1
  int v3; // ecx@2
  int v4; // edi@2
  char *v5; // esi@3
  int v6; // eax@5
  char *v7; // esi@6
  LONG v8; // eax@6
  char *v9; // esi@8
  int v10; // edx@10
  int v11; // ebx@12
  unsigned int v12; // esi@12
  PSRefBufferCharData<char> *v13; // eax@13
  unsigned int v14; // ecx@13
  char *v15; // edx@13
  char *v16; // edx@18
  bool v17; // cf@21
  char *v18; // ecx@21
  int v19; // eax@24
  unsigned int v20; // ecx@27
  int v21; // eax@28
  GlobalRegistryInstance *v22; // eax@33
  GlobalRegistryInstance *v23; // eax@35
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v24; // eax@39
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v25; // ebp@39
  HashTableData<unsigned long,HeritageGroup_CG> **v26; // edi@39
  HashTableData<unsigned long,HeritageGroup_CG> *v27; // esi@39
  GlobalRegistryInstance *v28; // eax@40
  GlobalRegistryInstance *v29; // eax@41
  GlobalRegistryInstance *v30; // eax@50
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v31; // eax@54
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v32; // ebx@54
  HashTableData<unsigned long,HeritageGroup_CG> **v33; // esi@54
  HashTableData<unsigned long,HeritageGroup_CG> *v34; // edi@54
  GlobalRegistryInstance *v35; // eax@55
  GlobalRegistryInstance *v36; // eax@56
  HeritageGroup_CGVtbl *v37; // ebp@59
  PStringBase<char> *v38; // ecx@65
  PStringBase<char> *v39; // edi@65
  PStringBase<char> *v40; // ebx@65
  unsigned int v41; // esi@66
  signed int v42; // eax@66
  int i; // edx@66
  int v44; // ebx@72
  unsigned int v45; // esi@73
  DebugConsole *v46; // ebp@74
  unsigned int v47; // eax@86
  int v48; // edx@87
  int v49; // ecx@89
  char *v50; // ebp@97
  int v51; // edx@99
  unsigned int v52; // edi@100
  PSRefBufferCharData<char> *v53; // ebp@100
  unsigned int v54; // eax@100
  unsigned int v55; // ecx@101
  char *v56; // ecx@102
  char *v57; // esi@104
  PSRefBufferCharData<char> *v58; // eax@108
  PSRefBufferCharData<char> **v59; // esi@108
  char *v60; // edi@109
  int v61; // edx@111
  int v62; // edx@115
  DebugConsole *v63; // ebp@116
  PSRefBufferCharData<char> *v64; // eax@116
  int v65; // esi@117
  int v66; // edx@119
  PSRefBufferCharData<char> *v67; // eax@120
  void (__stdcall *v68)(volatile LONG *); // ebx@120
  char *v69; // esi@121
  int v70; // eax@123
  PSRefBufferCharData<char> *v71; // eax@128
  PSRefBufferCharData<char> *v72; // edi@128
  int v73; // esi@129
  int v74; // edx@131
  int v75; // eax@134
  int v76; // esi@136
  int v77; // edx@138
  int v78; // edx@141
  PSRefBufferCharData<char> *v79; // eax@144
  PStringBase<char> *v80; // ebx@144
  PStringBase<char> *v81; // edi@144
  int v82; // eax@144
  PSRefBufferCharData<char> *v83; // esi@146
  int v84; // esi@146
  int v85; // edx@148
  char *v86; // esi@151
  int v87; // edx@153
  char *v88; // esi@154
  int v89; // edx@156
  char *v90; // esi@157
  int v91; // edx@159
  char *v92; // esi@160
  int v93; // edx@162
  int v94; // edx@167
  int v95; // [sp+Ch] [bp-60h]@2
  int FoundCompleteString; // [sp+20h] [bp-4Ch]@30
  PStringBase<char> WordToComplete; // [sp+24h] [bp-48h]@12
  PStringBase<char> StringLwr; // [sp+28h] [bp-44h]@95
  PStringBase<unsigned short> InputTextW; // [sp+2Ch] [bp-40h]@1
  PStringBase<char> InputText; // [sp+30h] [bp-3Ch]@2
  int s; // [sp+34h] [bp-38h]@89
  DebugConsole *v102; // [sp+38h] [bp-34h]@1
  PStringBase<char> WordToCompleteLwr; // [sp+3Ch] [bp-30h]@33
  int v104; // [sp+40h] [bp-2Ch]@87
  int v105; // [sp+44h] [bp-28h]@87
  PStringBase<char> CompleteString; // [sp+48h] [bp-24h]@86
  PStringBase<char> OtherWords; // [sp+4Ch] [bp-20h]@12
  int v108; // [sp+50h] [bp-1Ch]@86
  PStringBaseArray<char> StringList; // [sp+54h] [bp-18h]@33
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+60h] [bp-Ch]@39

  InputTextW.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  v102 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !GlyphList::InqText(v2->m_pInputBuffer, 0, &InputTextW) )
  {
    v7 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
    v8 = InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]);
    goto LABEL_165;
  }
  PStringBase<unsigned short>::to_spstring(&InputTextW, &InputText, 0);
  v95 = v3;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v95, " ");
  PStringBase<char>::trim(&InputText, 1, 1, (PStringBase<char>)v95);
  v4 = *(_DWORD *)&InputText.m_charbuffer[-1].m_data[12] - 1;
  if ( v4 < 1 )
  {
    v5 = &InputText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&InputText.m_charbuffer[-1]) && v5 )
    {
      v6 = *(_DWORD *)v5;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v6)(v5, 1);
    }
    v7 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
    v8 = InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]);
    goto LABEL_165;
  }
  if ( v2->m_InputCursorPos != v4 )
  {
    v9 = &InputText.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&InputText.m_charbuffer[-1]) && v9 )
    {
      v10 = *(_DWORD *)v9;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v10)(v9, 1);
    }
    v7 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
    v8 = InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]);
    goto LABEL_165;
  }
  WordToComplete.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v11 = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  OtherWords.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v12 = 0;
  if ( v4 )
  {
    do
    {
      v13 = InputText.m_charbuffer;
      v14 = *(_DWORD *)&InputText.m_charbuffer[-1].m_data[12];
      v15 = &InputText.m_charbuffer->m_data[v14 - 1];
      if ( v12 < v14 )
        v15 = &InputText.m_charbuffer->m_data[v12];
      if ( *v15 == 32 )
        ++v11;
      if ( v12 )
      {
        v16 = &InputText.m_charbuffer->m_data[v14 - 1];
        if ( v12 < v14 )
          v16 = &InputText.m_charbuffer->m_data[v12];
        if ( *v16 != 32 )
        {
          v17 = v12 - 1 < v14;
          v18 = &InputText.m_charbuffer->m_data[v14 - 1];
          if ( v17 )
            v18 = &InputText.m_charbuffer->m_data[v12 - 1];
          if ( *v18 == 32 )
          {
            v19 = *(_DWORD *)&WordToComplete.m_charbuffer[-1].m_data[12];
            if ( v19 != 1 )
              PStringBase<char>::append_n_chars(&OtherWords, WordToComplete.m_charbuffer->m_data, v19 - 1);
            PStringBase<char>::clear(&WordToComplete);
            v13 = InputText.m_charbuffer;
          }
        }
      }
      v20 = *(_DWORD *)&v13[-1].m_data[12];
      if ( v12 < v20 )
        v21 = (int)((char *)v13 + v12);
      else
        v21 = (int)((char *)v13 + v20 - 1);
      LOBYTE(FoundCompleteString) = *(_BYTE *)v21;
      PStringBase<char>::append_n_chars(&WordToComplete, (const char *)&FoundCompleteString, 1u);
      ++v12;
    }
    while ( v12 < v4 );
  }
  if ( *(_DWORD *)&v102->m_LastTabCompletionWord.m_charbuffer[-1].m_data[12] != 1 )
    PStringBase<unsigned short>::operator=(
      (PStringBase<unsigned short> *)&WordToComplete,
      (const unsigned __int16 *)&v102->m_LastTabCompletionWord);
  WordToCompleteLwr.m_charbuffer = WordToComplete.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&WordToComplete.m_charbuffer[-1]);
  PStringBase<char>::break_reference(&WordToCompleteLwr);
  __strlwr(WordToCompleteLwr.m_charbuffer->m_data);
  v22 = GlobalRegistry::s_pcGlobalRegistry;
  StringList.m_data = 0;
  StringList.m_sizeAndDeallocate = 0;
  StringList.m_num = 0;
  if ( v11 )
  {
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v30 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v30 )
        GlobalRegistryInstance::GlobalRegistryInstance(v30);
      else
        v22 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v22;
    }
    v31 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v22->m_ObjectHash.m_intrusiveTable,
            &result);
    v32 = v31->m_currHashTable;
    v33 = v31->m_currBucket;
    v34 = v31->m_currElement;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v35 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v35 )
      {
        GlobalRegistryInstance::GlobalRegistryInstance(v35);
        GlobalRegistry::s_pcGlobalRegistry = v36;
      }
      else
      {
        GlobalRegistry::s_pcGlobalRegistry = 0;
      }
    }
    if ( v34 )
    {
      do
      {
LABEL_59:
        v37 = v34->m_data.vfptr;
        if ( !(*((int (__thiscall **)(HeritageGroup_CGVtbl *))v37->Serialize + 15))(v34->m_data.vfptr) )
          SmartArray<PStringBase<char>,1>::AddToEnd(
            (SmartArray<PStringBase<char>,1> *)&StringList.m_data,
            (PStringBase<char> *)&v37[1]);
        v34 = v34->m_hashNext;
      }
      while ( v34 );
      while ( 1 )
      {
        ++v33;
        if ( v33 == &v32->m_buckets[v32->m_numBuckets] )
          break;
        if ( *v33 )
        {
          v34 = *v33;
          if ( *v33 )
            goto LABEL_59;
          break;
        }
      }
    }
  }
  else
  {
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v23 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v23 )
        GlobalRegistryInstance::GlobalRegistryInstance(v23);
      else
        v22 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v22;
    }
    v24 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v22->m_CommandHash.m_intrusiveTable,
            &result);
    v25 = v24->m_currHashTable;
    v26 = v24->m_currBucket;
    v27 = v24->m_currElement;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v28 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v28 )
      {
        GlobalRegistryInstance::GlobalRegistryInstance(v28);
        GlobalRegistry::s_pcGlobalRegistry = v29;
      }
      else
      {
        GlobalRegistry::s_pcGlobalRegistry = 0;
      }
    }
    if ( v27 )
    {
      do
      {
LABEL_44:
        SmartArray<PStringBase<char>,1>::AddToEnd(
          (SmartArray<PStringBase<char>,1> *)&StringList.m_data,
          (PStringBase<char> *)&v27->m_data.vfptr[1]);
        v27 = v27->m_hashNext;
      }
      while ( v27 );
      while ( 1 )
      {
        ++v26;
        if ( v26 == &v25->m_buckets[v25->m_numBuckets] )
          break;
        if ( *v26 )
        {
          v27 = *v26;
          if ( *v26 )
            goto LABEL_44;
          break;
        }
      }
    }
  }
  v38 = StringList.m_data;
  v39 = &StringList.m_data[StringList.m_num];
  v40 = StringList.m_data;
  if ( StringList.m_data != v39 )
  {
    v41 = 4 * StringList.m_num;
    v42 = (signed int)(4 * StringList.m_num) >> 2;
    for ( i = 0; v42 != 1; ++i )
      v42 >>= 1;
    _STL::__introsort_loop(
      StringList.m_data,
      &StringList.m_data[StringList.m_num],
      0,
      2 * i,
      (_STL::less<PStringBase<char> >)_SearchForward);
    if ( (signed int)(v41 & 0xFFFFFFFC) <= 64 )
    {
      v95 = _SearchForward;
      _STL::__insertion_sort(v40, v39);
    }
    else
    {
      v95 = _SearchForward;
      _STL::__insertion_sort(v40, v40 + 16);
      _STL::__unguarded_insertion_sort_aux(v40 + 16, v39);
    }
    v38 = StringList.m_data;
  }
  v44 = 0;
  if ( *(_DWORD *)&v102->m_LastTabCompletionString.m_charbuffer[-1].m_data[12] != 1 )
  {
    v45 = 0;
    if ( StringList.m_num )
    {
      v46 = v102;
      while ( __stricmp(v38[v45].m_charbuffer->m_data, v46->m_LastTabCompletionString.m_charbuffer->m_data) )
      {
        ++v45;
        if ( v45 >= StringList.m_num )
          goto LABEL_86;
        v38 = StringList.m_data;
      }
      if ( _SearchForward )
      {
        if ( v45 == StringList.m_num - 1 )
          v44 = 0;
        else
          v44 = v45 + 1;
      }
      else if ( v45 )
      {
        v44 = v45 - 1;
      }
      else
      {
        v44 = StringList.m_num - 1;
      }
    }
  }
LABEL_86:
  CompleteString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  LOBYTE(FoundCompleteString) = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v47 = StringList.m_num;
  v108 = 0;
  if ( !StringList.m_num )
    goto LABEL_116;
  v48 = v44;
  v104 = v44;
  v105 = v44;
  while ( 1 )
  {
    if ( _SearchForward )
    {
      v49 = v48;
      s = v48;
      if ( v48 < (signed int)v47 )
        goto LABEL_94;
      v49 = v48 - v47;
    }
    else
    {
      v49 = v44;
      s = v44;
      if ( v44 >= 0 )
        goto LABEL_94;
      v49 = v47 + v44;
    }
    s = v49;
LABEL_94:
    if ( *(_DWORD *)&StringList.m_data[v49].m_charbuffer[-1].m_data[12] >= *(_DWORD *)&WordToComplete.m_charbuffer[-1].m_data[12] )
      break;
LABEL_125:
    ++v48;
    --v44;
    v17 = v108++ + 1 < v47;
    v104 = v48;
    v105 = v44;
    if ( !v17 )
      goto LABEL_116;
  }
  StringLwr.m_charbuffer = StringList.m_data[v49].m_charbuffer;
  InterlockedIncrement((volatile LONG *)&StringLwr.m_charbuffer[-1]);
  if ( *(_DWORD *)&StringLwr.m_charbuffer[-1].m_data[0] == 1 )
  {
    *(_DWORD *)&StringLwr.m_charbuffer[-1].m_data[8] = -1;
  }
  else
  {
    v50 = &StringLwr.m_charbuffer[-2].m_data[12];
    PStringBase<char>::allocate_ref_buffer(&StringLwr, *(_DWORD *)&StringLwr.m_charbuffer[-1].m_data[12] - 1);
    qmemcpy(StringLwr.m_charbuffer, v50 + 20, *(_DWORD *)&StringLwr.m_charbuffer[-1].m_data[12]);
    if ( !InterlockedDecrement((volatile LONG *)v50 + 1) && v50 )
    {
      v51 = *(_DWORD *)v50;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v51)(v50, 1);
    }
  }
  __strlwr(StringLwr.m_charbuffer->m_data);
  v52 = *(_DWORD *)&WordToCompleteLwr.m_charbuffer[-1].m_data[12];
  v53 = StringLwr.m_charbuffer;
  v54 = 0;
  if ( v52 != 1 )
  {
    while ( 1 )
    {
      v55 = *(_DWORD *)&StringLwr.m_charbuffer[-1].m_data[12];
      if ( v54 < v55 )
        v56 = &WordToCompleteLwr.m_charbuffer->m_data[(char *)StringLwr.m_charbuffer
                                                    - (char *)WordToCompleteLwr.m_charbuffer
                                                    + v54];
      else
        v56 = &StringLwr.m_charbuffer->m_data[v55 - 1];
      v57 = &WordToCompleteLwr.m_charbuffer->m_data[v52 - 1];
      if ( v54 < v52 )
        v57 = &WordToCompleteLwr.m_charbuffer->m_data[v54];
      if ( *v56 != *v57 )
        break;
      ++v54;
      if ( v54 >= v52 - 1 )
        goto LABEL_108;
    }
    v69 = &StringLwr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&StringLwr.m_charbuffer[-1]) && v53 != (PSRefBufferCharData<char> *)20 )
    {
      v70 = *(_DWORD *)v69;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v70)(&v53[-2].m_data[12], 1);
    }
    v47 = StringList.m_num;
    v44 = v105;
    v48 = v104;
    goto LABEL_125;
  }
LABEL_108:
  v58 = StringList.m_data[s].m_charbuffer;
  v59 = &StringList.m_data[s].m_charbuffer;
  LOBYTE(FoundCompleteString) = 1;
  if ( CompleteString.m_charbuffer != v58 )
  {
    v60 = &CompleteString.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&CompleteString.m_charbuffer[-1]) && v60 )
    {
      v61 = *(_DWORD *)v60;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v61)(v60, 1);
    }
    CompleteString.m_charbuffer = *v59;
    InterlockedIncrement((volatile LONG *)&CompleteString.m_charbuffer[-1]);
    v53 = StringLwr.m_charbuffer;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v53[-1]) && v53 != (PSRefBufferCharData<char> *)20 )
  {
    v62 = *(_DWORD *)&v53[-2].m_data[12];
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v62)(&v53[-2].m_data[12], 1);
  }
LABEL_116:
  v63 = v102;
  v64 = v102->m_LastTabCompletionWord.m_charbuffer;
  if ( v64 == WordToComplete.m_charbuffer )
  {
    v68 = (void (__stdcall *)(volatile LONG *))InterlockedIncrement;
  }
  else
  {
    v65 = (int)&v64[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v64[-1]) && v65 )
    {
      v66 = *(_DWORD *)v65;
      v95 = 1;
      (*(void (__thiscall **)(int, signed int))v66)(v65, 1);
    }
    v67 = WordToComplete.m_charbuffer;
    v68 = (void (__stdcall *)(volatile LONG *))InterlockedIncrement;
    v63->m_LastTabCompletionWord.m_charbuffer = WordToComplete.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v67[-1]);
  }
  v71 = v63->m_LastTabCompletionString.m_charbuffer;
  v72 = CompleteString.m_charbuffer;
  if ( v71 != CompleteString.m_charbuffer )
  {
    v73 = (int)&v71[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v71[-1]) && v73 )
    {
      v74 = *(_DWORD *)v73;
      v95 = 1;
      (*(void (__thiscall **)(int, signed int))v74)(v73, 1);
    }
    v95 = (int)&v72[-1];
    v63->m_LastTabCompletionString.m_charbuffer = v72;
    v68((volatile LONG *)v95);
  }
  if ( (_BYTE)FoundCompleteString )
  {
    *(_DWORD *)&_SearchForward = OtherWords.m_charbuffer;
    v68((volatile LONG *)&OtherWords.m_charbuffer[-1]);
    v75 = *(_DWORD *)&v72[-1].m_data[12];
    if ( v75 != 1 )
      PStringBase<char>::append_n_chars((PStringBase<char> *)&_SearchForward, v72->m_data, v75 - 1);
    DebugConsole::SetInputBufferContents(v63, (PStringBase<char> *)&_SearchForward);
    v76 = _SearchForward - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_SearchForward - 20 + 4)) && v76 )
    {
      v77 = *(_DWORD *)v76;
      v95 = 1;
      (*(void (__thiscall **)(int, signed int))v77)(v76, 1);
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)&v72[-1]) && v72 != (PSRefBufferCharData<char> *)20 )
  {
    v78 = *(_DWORD *)&v72[-2].m_data[12];
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v78)(&v72[-2].m_data[12], 1);
  }
  if ( (StringList.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)StringList.m_data )
  {
    v79 = StringList.m_data[-1].m_charbuffer;
    v80 = StringList.m_data - 1;
    v81 = &StringList.m_data[(_DWORD)v79];
    v82 = (int)&v79[-1].m_data[15];
    if ( v82 >= 0 )
    {
      *(_DWORD *)&_SearchForward = v82 + 1;
      do
      {
        v83 = v81[-1].m_charbuffer;
        --v81;
        v84 = (int)&v83[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v84 + 4)) && v84 )
        {
          v85 = *(_DWORD *)v84;
          v95 = 1;
          (*(void (__thiscall **)(int, signed int))v85)(v84, 1);
        }
        *(_DWORD *)&_SearchForward = _SearchForward - 1;
      }
      while ( _SearchForward );
    }
    operator delete[](v80);
  }
  v86 = &WordToCompleteLwr.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WordToCompleteLwr.m_charbuffer[-1]) && v86 )
  {
    v87 = *(_DWORD *)v86;
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v87)(v86, 1);
  }
  v88 = &OtherWords.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherWords.m_charbuffer[-1]) && v88 )
  {
    v89 = *(_DWORD *)v88;
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v89)(v88, 1);
  }
  v90 = &WordToComplete.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WordToComplete.m_charbuffer[-1]) && v90 )
  {
    v91 = *(_DWORD *)v90;
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v91)(v90, 1);
  }
  v92 = &InputText.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InputText.m_charbuffer[-1]) && v92 )
  {
    v93 = *(_DWORD *)v92;
    v95 = 1;
    (*(void (__thiscall **)(char *, signed int))v93)(v92, 1);
  }
  v7 = (char *)&InputTextW.m_charbuffer[-1].m_data[6];
  v8 = InterlockedDecrement((volatile LONG *)&InputTextW.m_charbuffer[-1].m_data[8]);
LABEL_165:
  if ( !v8 )
  {
    if ( v7 )
    {
      v94 = *(_DWORD *)v7;
      v95 = 1;
      (*(void (__thiscall **)(char *, signed int))v94)(v7, 1);
    }
  }
}

//----- (00692420) --------------------------------------------------------  // acclient.c:681815
void __thiscall DebugConsole::CharacterHandler(DebugConsole *this, wchar_t _Char)
{
  DebugConsole *v2; // esi@1
  Glyph MyGlyph; // [sp+4h] [bp-24h]@8
  bool _Chara; // [sp+2Ch] [bp+4h]@5

  v2 = this;
  if ( _Char )
  {
    switch ( _Char )
    {
      case 0xAu:
      case 0xDu:
        DebugConsole::InputEnter((DebugConsole *)((char *)this - 8));
        break;
      case 8u:
        DebugConsole::InputBackspaceCharacter((DebugConsole *)((char *)this - 8));
        break;
      case 9u:
        _Chara = GetAsyncKeyState(16) == 0;
        DebugConsole::InputTabCompletion((DebugConsole *)((char *)v2 - 8), _Chara);
        break;
      default:
        if ( _Char >= 0x20u && _Char <= 0x7Fu )
        {
          Glyph::Glyph(&MyGlyph, _Char, &color, 0, 0, 8u, 0xCu);
          GlyphList::Insert(*(GlyphList **)&v2->m_WantActivateInput, v2->m_OutputLines.m_num++, &MyGlyph);
          v2->m_LastTabCompletionWord.m_charbuffer = (PSRefBufferCharData<char> *)-1;
          DebugConsole::InvalidateTabCompletion((DebugConsole *)((char *)v2 - 8));
          Glyph::~Glyph(&MyGlyph);
        }
        break;
    }
  }
}

//----- (00718E40) --------------------------------------------------------  // acclient.c:811621
int sub_718E40()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_39, "Display.Resolution");
  return atexit(sub_784500);
}

//----- (00718E60) --------------------------------------------------------  // acclient.c:811628
int sub_718E60()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_39, "Display.FullScreen");
  return atexit(sub_784530);
}

//----- (00718E80) --------------------------------------------------------  // acclient.c:811635
int _E79_92()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_39, "Display.RefreshRate");
  return atexit(_E80_89);
}

//----- (00718EA0) --------------------------------------------------------  // acclient.c:811642
int _E82_57()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_39, "Display.SyncToRefresh");
  return atexit(_E83_54);
}

//----- (00718EC0) --------------------------------------------------------  // acclient.c:811649
void _E85_41()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F84C0, PFID_A8R8G8B8);
}

//----- (00718ED0) --------------------------------------------------------  // acclient.c:811655
void sub_718ED0()
{
  LODWORD(dword_8F84FC) = 1053364187;
}

//----- (00718EE0) --------------------------------------------------------  // acclient.c:811661
void _E105_58()
{
  flt_8F8500 = 1000.0 + 1.0;
}

//----- (00718F00) --------------------------------------------------------  // acclient.c:811667
void _E107_46()
{
  flt_8F8504 = 24.0 * 8.0;
}

//----- (00718F20) --------------------------------------------------------  // acclient.c:811673
void _E109_88()
{
  flt_8F8508 = 24.0 * 0.5;
}

//----- (00718F40) --------------------------------------------------------  // acclient.c:811679
int _E111_61()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_75, "None");
  return atexit(sub_7845C0);
}

//----- (00718F60) --------------------------------------------------------  // acclient.c:811686
int _E114_67()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_75, "Speed");
  return atexit(sub_7845F0);
}

//----- (00718F80) --------------------------------------------------------  // acclient.c:811693
int _E117_85()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_75, "Noise");
  return atexit(sub_784620);
}

//----- (00718FA0) --------------------------------------------------------  // acclient.c:811700
int _E120_76()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_75, "Sine");
  return atexit(sub_784650);
}

//----- (00718FC0) --------------------------------------------------------  // acclient.c:811707
int _E123_49()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_75, "Square");
  return atexit(sub_784680);
}

//----- (00718FE0) --------------------------------------------------------  // acclient.c:811714
int _E126_55()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_75, "Bounce");
  return atexit(sub_7846B0);
}

//----- (00719000) --------------------------------------------------------  // acclient.c:811721
int _E129_50()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_75, "Perlin");
  return atexit(sub_7846E0);
}

//----- (00719020) --------------------------------------------------------  // acclient.c:811728
int _E132_50()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_75, "Fractal");
  return atexit(sub_784710);
}

//----- (00719040) --------------------------------------------------------  // acclient.c:811735
int _E135_58()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_75, "FrameLoop");
  return atexit(_E136_92);
}

//----- (00719060) --------------------------------------------------------  // acclient.c:811742
int sub_719060()
{
  return atexit(nullsub_239);
}

//----- (00784500) --------------------------------------------------------  // acclient.c:923439
void __cdecl sub_784500()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784530) --------------------------------------------------------  // acclient.c:923452
void __cdecl sub_784530()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784560) --------------------------------------------------------  // acclient.c:923465
void __cdecl _E80_89()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784590) --------------------------------------------------------  // acclient.c:923478
void __cdecl _E83_54()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007845C0) --------------------------------------------------------  // acclient.c:923491
void __cdecl sub_7845C0()
{
  char *v0; // esi@1

  v0 = &waveform_None_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007845F0) --------------------------------------------------------  // acclient.c:923504
void __cdecl sub_7845F0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784620) --------------------------------------------------------  // acclient.c:923517
void __cdecl sub_784620()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784650) --------------------------------------------------------  // acclient.c:923530
void __cdecl sub_784650()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784680) --------------------------------------------------------  // acclient.c:923543
void __cdecl sub_784680()
{
  char *v0; // esi@1

  v0 = &waveform_Square_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007846B0) --------------------------------------------------------  // acclient.c:923556
void __cdecl sub_7846B0()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007846E0) --------------------------------------------------------  // acclient.c:923569
void __cdecl sub_7846E0()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784710) --------------------------------------------------------  // acclient.c:923582
void __cdecl sub_784710()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784740) --------------------------------------------------------  // acclient.c:923595
void __cdecl _E136_92()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00784770) --------------------------------------------------------  // acclient.c:923608
void __cdecl _E139_92()
{
  SmartArray<Glyph,1>::~SmartArray<Glyph,1>(&GlyphText);
}

