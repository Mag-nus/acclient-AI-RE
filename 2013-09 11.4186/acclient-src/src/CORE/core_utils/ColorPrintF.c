/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ColorPrintF
   Object     : CORE\core_utils\ColorPrintF.obj
   Functions  : 7
   Addresses  : 0040FBC0 - 0040FFE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040FBC0) --------------------------------------------------------  // acclient.c:75604
void __thiscall ANSIColorStatus::Init(ANSIColorStatus *this)
{
  ANSIColorStatus *v1; // esi@1
  HANDLE v2; // edi@1
  DWORD v3; // eax@2
  unsigned __int16 v4; // ax@3
  _CONSOLE_SCREEN_BUFFER_INFO csbiInfo; // [sp+8h] [bp-18h]@1

  v1 = this;
  this->m_hConsole = 0;
  this->m_wDefaultAttr = 8;
  this->m_bInitialized = 1;
  v2 = GetStdHandle(0xFFFFFFF5);
  if ( GetConsoleScreenBufferInfo(v2, &csbiInfo) )
  {
    v4 = csbiInfo.wAttributes;
    v1->m_hConsole = v2;
    v1->m_wDefaultAttr = v4;
    v1->m_attr = v4;
  }
  else
  {
    v3 = GetLastError();
    _fprintf((FILE *)__iob[0]._ptr + 2, "GetConsoleScreenBufferInfo %d", v3);
  }
}

//----- (0040FC30) --------------------------------------------------------  // acclient.c:75632
void __thiscall ANSIColorStatus::SetForeColor(ANSIColorStatus *this, unsigned __int16 wAttr)
{
  ANSIColorStatus *v2; // esi@1
  void *v3; // ecx@3

  v2 = this;
  if ( !this->m_bInitialized )
    ANSIColorStatus::Init(this);
  v3 = v2->m_hConsole;
  v2->m_attr ^= ((unsigned __int8)wAttr ^ LOBYTE(v2->m_attr)) & 0xF;
  SetConsoleTextAttribute(v3, v2->m_attr);
}

//----- (0040FC60) --------------------------------------------------------  // acclient.c:75646
void __thiscall ANSIColorStatus::SetBackColor(ANSIColorStatus *this, unsigned __int16 wAttr)
{
  ANSIColorStatus *v2; // esi@1
  void *v3; // ecx@3

  v2 = this;
  if ( !this->m_bInitialized )
    ANSIColorStatus::Init(this);
  v3 = v2->m_hConsole;
  v2->m_attr ^= (unsigned __int8)((wAttr ^ LOBYTE(v2->m_attr)) & 0xF0);
  SetConsoleTextAttribute(v3, v2->m_attr);
}

//----- (0040FC90) --------------------------------------------------------  // acclient.c:75660
void __thiscall ANSIColorStatus::SetToDefaultColors(ANSIColorStatus *this)
{
  ANSIColorStatus *v1; // esi@1
  WORD v2; // ax@3

  v1 = this;
  if ( !this->m_bInitialized )
    ANSIColorStatus::Init(this);
  v2 = v1->m_wDefaultAttr;
  v1->m_attr = v2;
  SetConsoleTextAttribute(v1->m_hConsole, v2);
}

//----- (0040FCC0) --------------------------------------------------------  // acclient.c:75674
int __cdecl DoANSIEscape<char>(const char *pSeq)
{
  int result; // eax@2
  const char *v2; // ebp@4
  char v3; // bl@4
  int *v4; // esi@4
  const char v5; // al@10
  int v6; // ebp@10
  char v7; // cl@22
  char v8; // dl@22
  signed int v9; // edi@22
  unsigned __int16 v10; // si@23
  int v11; // eax@24
  char v12; // al@27
  char v13; // al@38
  int n; // [sp+4h] [bp-34h]@5
  int wAttr; // [sp+8h] [bp-30h]@22
  const char *pSeqStart; // [sp+Ch] [bp-2Ch]@3
  int args[10]; // [sp+10h] [bp-28h]@4
  const char *pSeqa; // [sp+3Ch] [bp+4h]@4

  if ( *pSeq != 27 || (pSeqStart = pSeq, pSeq[1] != 91) )
  {
    result = 0;
  }
  else
  {
    v2 = pSeq + 2;
    pSeqa = 0;
    v3 = 1;
    v4 = args;
    do
    {
      if ( !_sscanf(v2, "%d%n", v4, &n) )
        break;
      v2 += n;
      if ( *v2 == 59 )
        ++v2;
      else
        v3 = 0;
      ++pSeqa;
      ++v4;
    }
    while ( v3 );
    v5 = *v2;
    v6 = (int)(v2 + 1);
    if ( v5 == 109 )
    {
      if ( pSeqa == (const char *)1 )
      {
        switch ( args[0] )
        {
          case 0:
            ANSIColorStatus::SetToDefaultColors(&s_ConsoleColor);
            result = v6 - (_DWORD)pSeqStart;
            break;
          case 1:
          case 4:
            if ( !s_ConsoleColor.m_bInitialized )
              ANSIColorStatus::Init(&s_ConsoleColor);
            ANSIColorStatus::SetForeColor(&s_ConsoleColor, s_ConsoleColor.m_attr | 8);
            result = v6 - (_DWORD)pSeqStart;
            break;
          case 0x16:
          case 0x18:
            if ( !s_ConsoleColor.m_bInitialized )
              ANSIColorStatus::Init(&s_ConsoleColor);
            ANSIColorStatus::SetForeColor(&s_ConsoleColor, s_ConsoleColor.m_attr & 0xFFF7);
            result = v6 - (_DWORD)pSeqStart;
            break;
          default:
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        if ( !s_ConsoleColor.m_bInitialized )
          ANSIColorStatus::Init(&s_ConsoleColor);
        LOWORD(wAttr) = s_ConsoleColor.m_attr;
        v7 = 0;
        v8 = 0;
        v9 = 0;
        if ( (signed int)pSeqa > 0 )
        {
          v10 = wAttr;
          do
          {
            v11 = args[v9];
            switch ( v11 )
            {
              case 0:
                v7 = 1;
                break;
              case 1:
                v8 = 1;
                break;
              case 30:
              case 31:
              case 32:
              case 33:
              case 34:
              case 35:
              case 36:
              case 37:
                v12 = v11 - 30;
                v10 &= 0xFFF8u;
                if ( v12 & 1 )
                  v10 |= 4u;
                if ( v12 & 2 )
                  v10 |= 2u;
                if ( v12 & 4 )
                  v10 |= 1u;
                if ( v7 )
                  v10 &= 0xFFF7u;
                if ( v8 )
                  v10 |= 8u;
                ANSIColorStatus::SetForeColor(&s_ConsoleColor, v10);
                goto LABEL_49;
              case 40:
              case 41:
              case 42:
              case 43:
              case 44:
              case 45:
              case 46:
              case 47:
                v13 = v11 - 40;
                v10 &= 0xFF8Fu;
                if ( v13 & 1 )
                  v10 |= 0x40u;
                if ( v13 & 2 )
                  v10 |= 0x20u;
                if ( v13 & 4 )
                  v10 |= 0x10u;
                if ( v7 )
                  v10 &= 0xFF7Fu;
                if ( v8 )
                  v10 |= 0x80u;
                ANSIColorStatus::SetBackColor(&s_ConsoleColor, v10);
LABEL_49:
                v7 = 0;
                v8 = 0;
                break;
              default:
                break;
            }
            ++v9;
          }
          while ( v9 < (signed int)pSeqa );
        }
        result = v6 - (_DWORD)pSeqStart;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0040FF60) --------------------------------------------------------  // acclient.c:75837
int __cdecl DoANSIString<char>(const char *szString)
{
  const char *v1; // esi@1
  int v2; // ebp@1
  const char *v3; // ebx@1
  int v4; // eax@5
  int v5; // esi@10
  const char *v6; // eax@10

  v1 = szString;
  v2 = 0;
  v3 = szString;
  while ( *v1 )
  {
    if ( *v1 != 27 )
      goto LABEL_17;
    if ( v1 != v3 )
    {
      _printf("%0.*s", v1 - v3, v3);
      v2 += v1 - v3;
    }
    v4 = DoANSIEscape<char>(v1);
    if ( v4 )
    {
      v1 += v4;
      v3 = v1;
    }
    else
    {
LABEL_17:
      ++v1;
    }
  }
  if ( *v3 )
  {
    v5 = 0;
    v6 = v3;
    do
    {
      ++v6;
      ++v5;
    }
    while ( *v6 );
    if ( v5 )
    {
      _printf("%0.*s", v5, v3);
      v2 += v5;
    }
  }
  return v2;
}

//----- (0040FFE0) --------------------------------------------------------  // acclient.c:75890
int color_printf(const char *fmt, ...)
{
  int v1; // eax@1
  PSRefBufferCharData<char> *v2; // edi@1
  int v3; // esi@1
  int v4; // edi@3
  PStringBase<char> str; // [sp+0h] [bp-4h]@1
  va_list va; // [sp+Ch] [bp+8h]@1

  va_start(va, fmt);
  str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v1 = PStringBase<char>::vsprintf(&str, fmt, va);
  v2 = str.m_charbuffer;
  v3 = v1;
  if ( v1 >= 0 )
    v3 = DoANSIString<char>(str.m_charbuffer->m_data);
  v4 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  return v3;
}

