/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PlatformString
   Object     : ENGINE\platformstring\PlatformString.obj
   Functions  : 6
   Addresses  : 0043C9C0 - 00729B00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043C9C0) --------------------------------------------------------  // acclient.c:121564
PStringBase<unsigned short> *__thiscall PlatformString::StringAccessor::GetString(PlatformString::StringAccessor *this, PStringBase<unsigned short> *result, unsigned __int16 stringID)
{
  PSRefBufferCharData<unsigned short> *v4; // eax@4
  PStringBase<unsigned short> *v5; // edi@4
  char *v6; // esi@4
  PSRefBufferCharData<unsigned short> *v7; // eax@7
  char *v8; // esi@7
  PStringBase<unsigned short> v9; // [sp+Ch] [bp-3004h]@4
  char Buffer; // [sp+10h] [bp-3000h]@2
  int v11; // [sp+FF8h] [bp-2018h]@3
  unsigned __int16 WideCharStr; // [sp+1010h] [bp-2000h]@3
  char v13; // [sp+1012h] [bp-1FFEh]@3
  __int16 v14; // [sp+300Eh] [bp-2h]@3

  if ( this->h )
  {
    if ( LoadStringA(this->h, stringID, &Buffer, 4096) )
    {
      WideCharStr = 0;
      memset(&v13, 0, 0x1FFCu);
      v14 = 0;
      MultiByteToWideChar(0, 1u, &Buffer, -1, &WideCharStr, 4096);
      PStringBase<unsigned short>::PStringBase<unsigned short>(result, (const unsigned __int16 *)&v11);
      return result;
    }
    v9.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&v9, L"<corestrings.dll is missing string ID %d>", stringID);
    v4 = v9.m_charbuffer;
    v5 = result;
    result->m_charbuffer = v9.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
    v6 = (char *)&v9.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v9.m_charbuffer[-1].m_data[8]) && v6 )
    {
      (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      return result;
    }
  }
  else
  {
    v9.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    PStringBase<unsigned short>::sprintf(&v9, L"<corestrings.dll not found. Tried to print stringID %d>", stringID);
    v7 = v9.m_charbuffer;
    v5 = result;
    result->m_charbuffer = v9.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v7[-1].m_data[8]);
    v8 = (char *)&v9.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v9.m_charbuffer[-1].m_data[8]) && v8 )
      (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  }
  return v5;
}

//----- (0043CB20) --------------------------------------------------------  // acclient.c:121620
PStringBase<unsigned short> *__cdecl PlatformString::GetString(PStringBase<unsigned short> *result, unsigned __int16 stringID, PStringBase<unsigned short> param1, PStringBase<unsigned short> param2, PStringBase<unsigned short> param3)
{
  unsigned int v5; // eax@1
  char *v6; // esi@1
  unsigned int v7; // eax@4
  char *v8; // esi@4
  unsigned int v9; // eax@7
  char *v10; // esi@7
  PSRefBufferCharData<unsigned short> *v11; // eax@10
  char *v12; // esi@10
  char *v13; // esi@13
  char *v14; // esi@16
  char *v15; // esi@19
  PStringBase<unsigned short> ws; // [sp+10h] [bp-8h]@1
  PStringBase<unsigned short> search; // [sp+14h] [bp-4h]@1

  PlatformString::StringAccessor::GetString(&g_StringAccessor, &ws, stringID);
  v5 = _wcslen(L"%1");
  PStringBase<unsigned short>::allocate_ref_buffer(&search, v5);
  _wcscpy(search.m_charbuffer->m_data, L"%1");
  PStringBase<unsigned short>::replace(&ws, &search, &param1);
  v6 = (char *)&search.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1].m_data[8]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  v7 = _wcslen(L"%2");
  PStringBase<unsigned short>::allocate_ref_buffer(&search, v7);
  _wcscpy(search.m_charbuffer->m_data, L"%2");
  PStringBase<unsigned short>::replace(&ws, &search, &param2);
  v8 = (char *)&search.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1].m_data[8]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  v9 = _wcslen(L"%3");
  PStringBase<unsigned short>::allocate_ref_buffer(&search, v9);
  _wcscpy(search.m_charbuffer->m_data, L"%3");
  PStringBase<unsigned short>::replace(&ws, &search, &param3);
  v10 = (char *)&search.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  v11 = ws.m_charbuffer;
  result->m_charbuffer = ws.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1].m_data[8]);
  v12 = (char *)&ws.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&ws.m_charbuffer[-1].m_data[8]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  v13 = (char *)&param1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&param1.m_charbuffer[-1].m_data[8]) && v13 )
    (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
  v14 = (char *)&param2.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&param2.m_charbuffer[-1].m_data[8]) && v14 )
    (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  v15 = (char *)&param3.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&param3.m_charbuffer[-1].m_data[8]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  return result;
}

//----- (0043CCE0) --------------------------------------------------------  // acclient.c:121677
void __cdecl PlatformString::DisplayFinalString(PStringBase<unsigned short> str, PlatformString::DisplayStringMode mode)
{
  int v2; // ebp@1
  int v3; // edx@1
  unsigned __int64 v4; // rax@1
  unsigned int v5; // eax@1
  signed int v6; // ecx@1
  PSRefBufferCharData<unsigned short> *v7; // ecx@4
  PSRefBufferCharData<unsigned short> *v8; // ecx@4
  const unsigned __int16 *v9; // eax@4
  __int32 v10; // esi@4
  int v11; // eax@6
  PSRefBufferCharData<unsigned short> *v12; // ecx@8
  PSRefBufferCharData<unsigned short> *v13; // ecx@8
  const unsigned __int16 *v14; // eax@8
  char *v15; // esi@8
  int v16; // eax@10
  PSRefBufferCharData<unsigned short> *v17; // ecx@12
  PSRefBufferCharData<unsigned short> *v18; // ecx@12
  const unsigned __int16 *v19; // eax@12
  char *v20; // esi@12
  int v21; // eax@14
  int v22; // esi@16
  PStringBase<unsigned short> v23; // [sp-8h] [bp-38h]@4
  PStringBase<unsigned short> v24; // [sp-4h] [bp-34h]@4
  PStringBase<unsigned short> v25; // [sp+0h] [bp-30h]@4
  int v26; // [sp+4h] [bp-2Ch]@16
  unsigned __int64 v27; // [sp+10h] [bp-20h]@1
  PStringBase<unsigned short> result; // [sp+18h] [bp-18h]@8
  PStringBase<unsigned short> v29; // [sp+1Ch] [bp-14h]@12
  unsigned __int64 reportContext; // [sp+20h] [bp-10h]@1
  unsigned __int64 dialogContext; // [sp+28h] [bp-8h]@1

  v2 = DialogBoxGateways::ReportThread_PrepareForDialogBox();
  HIDWORD(dialogContext) = v3;
  LODWORD(v4) = DialogBoxGateways::DialogThread_PrepareForDialogBox();
  reportContext = v4;
  v5 = _wcslen(L"ERROR");
  PStringBase<unsigned short>::allocate_ref_buffer((PStringBase<unsigned short> *)&v27 + 1, v5);
  _wcscpy(HIDWORD(v27), L"ERROR");
  v6 = 327680;
  if ( mode )
  {
    if ( mode == 1 )
    {
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)327680;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v25, &word_794320);
      v24.m_charbuffer = v12;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v24, &word_794320);
      v23.m_charbuffer = v13;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v23, &word_794320);
      v14 = (const unsigned __int16 *)PlatformString::GetString(&result, 0xCu, v23, v24, v25);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&v27 + 1, v14);
      v15 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v15 )
      {
        v16 = *(_DWORD *)v15;
        v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
      }
      v6 = 327728;
    }
    else if ( mode == 2 )
    {
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)327680;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v25, &word_794320);
      v24.m_charbuffer = v7;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v24, &word_794320);
      v23.m_charbuffer = v8;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&v23, &word_794320);
      v9 = (const unsigned __int16 *)PlatformString::GetString(
                                       (PStringBase<unsigned short> *)&mode,
                                       0xDu,
                                       v23,
                                       v24,
                                       v25);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&v27 + 1, v9);
      v10 = mode - 20;
      if ( !InterlockedDecrement((volatile LONG *)(mode - 20 + 4)) && v10 )
      {
        v11 = *(_DWORD *)v10;
        v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(__int32, signed int))v11)(v10, 1);
      }
      v6 = 327744;
    }
  }
  else
  {
    v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)327680;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v25, &word_794320);
    v24.m_charbuffer = v17;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v24, &word_794320);
    v23.m_charbuffer = v18;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v23, &word_794320);
    v19 = (const unsigned __int16 *)PlatformString::GetString(&v29, 0xBu, v23, v24, v25);
    PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)&v27 + 1, v19);
    v20 = (char *)&v29.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v29.m_charbuffer[-1].m_data[8]) && v20 )
    {
      v21 = *(_DWORD *)v20;
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
      (*(void (__thiscall **)(char *, signed int))v21)(v20, 1);
    }
    v6 = 327696;
  }
  v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v6;
  v24.m_charbuffer = (PSRefBufferCharData<unsigned short> *)HIDWORD(v27);
  v23.m_charbuffer = str.m_charbuffer;
  user32_MessageBoxW_Ptr();
  DialogBoxGateways::DialogThread_DoneWithDialogBox(__PAIR__((unsigned int)v29.m_charbuffer, v2));
  DialogBoxGateways::ReportThread_DoneWithDialogBox(v27);
  v22 = v26 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v26 - 20 + 4)) && v22 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v22)(v22, 1);
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1].m_data[8])
    && str.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))&str.m_charbuffer[-1].m_data[6])(
      &str.m_charbuffer[-1].m_data[6],
      1);
}

//----- (0043CEF0) --------------------------------------------------------  // acclient.c:121800
void __cdecl PlatformString::DisplayString(unsigned __int16 stringID, PStringBase<unsigned short> param1, PStringBase<unsigned short> param2, PStringBase<unsigned short> param3, PlatformString::DisplayStringMode mode)
{
  PSRefBufferCharData<unsigned short> *v5; // ecx@0
  char *v6; // ebp@1
  char *v7; // ebx@1
  char *v8; // esi@1
  int v9; // eax@3
  int v10; // edx@6
  int v11; // edx@9
  PStringBase<unsigned short> v12; // [sp-8h] [bp-18h]@1
  PlatformString::DisplayStringMode v13; // [sp-4h] [bp-14h]@1

  v13 = mode;
  v12.m_charbuffer = v5;
  v6 = (char *)&param3.m_charbuffer[-1].m_data[6];
  InterlockedIncrement((volatile LONG *)&param3.m_charbuffer[-1].m_data[8]);
  v7 = (char *)&param2.m_charbuffer[-1].m_data[6];
  InterlockedIncrement((volatile LONG *)&param2.m_charbuffer[-1].m_data[8]);
  InterlockedIncrement((volatile LONG *)&param1.m_charbuffer[-1].m_data[8]);
  PlatformString::GetString(&v12, stringID, param1, param2, param3);
  PlatformString::DisplayFinalString(v12, v13);
  v8 = (char *)&param1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&param1.m_charbuffer[-1].m_data[8])
    && param1.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
  {
    v9 = *(_DWORD *)v8;
    v13 = 1;
    (*(void (__thiscall **)(char *, signed int))v9)(v8, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)v7 + 1)
    && param2.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
  {
    v10 = *(_DWORD *)v7;
    v13 = 1;
    (*(void (__thiscall **)(char *, signed int))v10)(v7, 1);
  }
  if ( !InterlockedDecrement((volatile LONG *)v6 + 1)
    && param3.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
  {
    v11 = *(_DWORD *)v6;
    v13 = 1;
    (*(void (__thiscall **)(char *, signed int))v11)(v6, 1);
  }
}

//----- (006C6A90) --------------------------------------------------------  // acclient.c:734834
int _E73_31()
{
  g_StringAccessor.h = LoadLibraryA("corestrings.dll");
  return atexit(_E74_32);
}

//----- (00729B00) --------------------------------------------------------  // acclient.c:827716
void __cdecl _E74_32()
{
  FreeLibrary(g_StringAccessor.h);
}

