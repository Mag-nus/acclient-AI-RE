/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Logger
   Object     : CORE\error\Logger.obj
   Functions  : 47
   Addresses  : 0040E580 - 00725E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040E580) --------------------------------------------------------  // acclient.c:74075
void __thiscall TextFileOutputHandler::Flush(TextFileOutputHandler *this)
{
  if ( this->m_fileLog )
    _fflush(this->m_fileLog);
}

//----- (0040E590) --------------------------------------------------------  // acclient.c:74082
PStringBase<char> *__thiscall TextFileOutputHandler::GetLogFileName(TextFileOutputHandler *this)
{
  return &this->m_strFilename;
}

//----- (0040E5B0) --------------------------------------------------------  // acclient.c:74088
signed int __thiscall LogController::CategoryHandler::SendToOutputHandlers(LogController::CategoryHandler *this, Logger::LoggingSeverity ls, unsigned int lc, const char *i_pszMsg)
{
  LogController::CategoryHandler *v4; // edi@1
  bool v5; // zf@1
  unsigned int v6; // kr00_4@2
  signed int v7; // eax@2
  unsigned int v8; // esi@6
  int v9; // eax@7
  signed int result; // eax@12
  int v11; // [sp+Ch] [bp-1004h]@1
  char Dest; // [sp+10h] [bp-1000h]@2
  char v13[4094]; // [sp+11h] [bp-FFFh]@5
  char v14; // [sp+100Fh] [bp-1h]@2

  v4 = this;
  v5 = this->m_rgOutputPlugins.m_num == 0;
  v11 = 2;
  if ( v5 )
  {
    result = 2;
  }
  else
  {
    _strncpy(&Dest, i_pszMsg, 0xFFFu);
    v14 = 0;
    v6 = strlen(&Dest);
    v7 = v6;
    if ( *((_BYTE *)&v11 + v6 + 3) != 10 )
    {
      if ( v6 == 4095 )
        v7 = 4094;
      *(&Dest + v7) = 10;
      v13[v7] = 0;
    }
    v8 = 0;
    if ( v4->m_rgOutputPlugins.m_num )
    {
      do
      {
        v9 = ((int (__stdcall *)(Logger::LoggingSeverity, unsigned int, char *))v4->m_rgOutputPlugins.m_data[v8]->vfptr[1].__vecDelDtor)(
               ls,
               lc,
               &Dest);
        if ( v9 >= 0 && v9 <= 1 )
        {
          if ( v11 )
            v11 = v9;
        }
        ++v8;
      }
      while ( v8 < v4->m_rgOutputPlugins.m_num );
      result = v11;
    }
    else
    {
      result = 2;
    }
  }
  return result;
}
// 40E5B0: using guessed type char var_FFF[4094];

//----- (0040E6A0) --------------------------------------------------------  // acclient.c:74151
signed int __stdcall ConsoleOutputHandler::Write(Logger::LoggingSeverity ls, unsigned int lc, const char *szMsg)
{
  _printf("%s", szMsg);
  return 1;
}

//----- (0040E6C0) --------------------------------------------------------  // acclient.c:74158
signed int __stdcall OutputDebugStringOutputHandler::Write(Logger::LoggingSeverity ls, unsigned int lc, const char *szMsg)
{
  if ( IsDebuggerPresent() )
    OutputDebugStringA(szMsg);
  return 1;
}

//----- (0040E6E0) --------------------------------------------------------  // acclient.c:74166
IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *__thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *v2; // esi@1
  LogController::CategoryHandler **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>Vtbl *)IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable;
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
// 7945BC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable[2])(void *, char);

//----- (0040E720) --------------------------------------------------------  // acclient.c:74187
Logger::ILoggingOutputHandler *__thiscall LogController::GetConsoleOutputHandler(LogController *this)
{
  LogController *v1; // esi@1
  void *v2; // eax@2

  v1 = this;
  if ( !this->m_plohConsole )
  {
    v2 = operator new(8u);
    if ( v2 )
    {
      *((_DWORD *)v2 + 1) = 1;
      *(_DWORD *)v2 = &ConsoleOutputHandler::vftable;
    }
    else
    {
      v2 = 0;
    }
    v1->m_plohConsole = (Logger::ILoggingOutputHandler *)v2;
  }
  InterlockedIncrement((volatile LONG *)&v1->m_plohConsole->m_cRef);
  return v1->m_plohConsole;
}
// 7945A0: using guessed type int (__thiscall *ConsoleOutputHandler::vftable)(void *, char);

//----- (0040E770) --------------------------------------------------------  // acclient.c:74213
Logger::ILoggingOutputHandler *__thiscall LogController::GetOutputDebugStringOutputHandler(LogController *this)
{
  LogController *v1; // esi@1
  void *v2; // eax@2

  v1 = this;
  if ( !this->m_plohODS )
  {
    v2 = operator new(8u);
    if ( v2 )
    {
      *((_DWORD *)v2 + 1) = 1;
      *(_DWORD *)v2 = &OutputDebugStringOutputHandler::vftable;
    }
    else
    {
      v2 = 0;
    }
    v1->m_plohODS = (Logger::ILoggingOutputHandler *)v2;
  }
  InterlockedIncrement((volatile LONG *)&v1->m_plohODS->m_cRef);
  return v1->m_plohODS;
}
// 7945B0: using guessed type int (__thiscall *OutputDebugStringOutputHandler::vftable)(void *, char);

//----- (0040E7C0) --------------------------------------------------------  // acclient.c:74239
unsigned int __cdecl Logger::CreateLoggingCategory(const char *i_psz)
{
  unsigned int result; // eax@2

  if ( i_psz )
    result = compute_str_hash<char>(i_psz);
  else
    result = 0;
  return result;
}

//----- (0040E7E0) --------------------------------------------------------  // acclient.c:74251
Logger::ILoggingOutputHandler *__cdecl Logger::GetConsoleOutputHandler()
{
  Logger::ILoggingOutputHandler *result; // eax@2

  if ( g_fInitialized )
    result = LogController::GetConsoleOutputHandler(&g_LogController);
  else
    result = 0;
  return result;
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040E800) --------------------------------------------------------  // acclient.c:74264
Logger::ILoggingOutputHandler *__cdecl Logger::GetOutputDebugStringOutputHandler()
{
  Logger::ILoggingOutputHandler *result; // eax@2

  if ( g_fInitialized )
    result = LogController::GetOutputDebugStringOutputHandler(&g_LogController);
  else
    result = 0;
  return result;
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040E820) --------------------------------------------------------  // acclient.c:74277
unsigned int __thiscall InstanceDiviner::AllocateIndex(InstanceDiviner *this, unsigned int i_RequiredIndex, PStringBase<char> i_NameStem)
{
  InstanceDiviner *v3; // esi@1
  const unsigned __int16 *v4; // eax@5
  char *v5; // edi@5
  unsigned int v6; // edi@9
  HANDLE v7; // eax@11
  unsigned int v8; // esi@16
  char *v9; // edi@16
  PStringBase<char> result; // [sp+8h] [bp-1004h]@5
  char Dest; // [sp+Ch] [bp-1000h]@11

  v3 = this;
  if ( !this->m_hMutex )
  {
    if ( *(_DWORD *)&i_NameStem.m_charbuffer[-1].m_data[12] != 1 )
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)this, (const unsigned __int16 *)&i_NameStem);
    if ( *(_DWORD *)&v3->m_NameStem.m_charbuffer[-1].m_data[12] == 1 )
    {
      v4 = (const unsigned __int16 *)PSUtils::get_process_name(&result);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)v3, v4);
      v5 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v5 )
        (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
      PSUtils::strip_directory(&v3->m_NameStem);
    }
    v6 = i_RequiredIndex;
    if ( !i_RequiredIndex )
      v6 = 1;
    while ( 1 )
    {
      _sprintf(&Dest, "%s_%d", v3->m_NameStem.m_charbuffer, v6);
      SetLastError(0);
      v7 = CreateMutexA(0, 0, &Dest);
      v3->m_hMutex = v7;
      if ( v7 )
      {
        if ( GetLastError() != 183 )
        {
          v3->m_Index = v6;
          break;
        }
        CloseHandle(v3->m_hMutex);
        if ( i_RequiredIndex )
          break;
      }
      ++v6;
    }
  }
  v8 = v3->m_Index;
  v9 = &i_NameStem.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_NameStem.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  return v8;
}

//----- (0040E950) --------------------------------------------------------  // acclient.c:74334
InstanceDiviner *__thiscall InstanceDiviner::scalar_deleting_destructor(InstanceDiviner *this, unsigned int a2)
{
  InstanceDiviner *v2; // edi@1
  int v3; // esi@3

  v2 = this;
  if ( this->m_hMutex )
  {
    CloseHandle(this->m_hMutex);
    v2->m_hMutex = 0;
    v2->m_Index = 0;
  }
  v3 = (int)&v2->m_NameStem.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040E9B0) --------------------------------------------------------  // acclient.c:74355
bool __thiscall TextFileOutputHandler::OpenLogFile(TextFileOutputHandler *this, PStringBase<char> *strFilename)
{
  TextFileOutputHandler *v2; // esi@1
  bool result; // al@2
  InstanceDiviner *v4; // ecx@6
  FILE *v5; // eax@9
  PStringBase<unsigned short> *v6; // ecx@9

  v2 = this;
  if ( *(_DWORD *)&strFilename->m_charbuffer[-1].m_data[12] == 1 )
    return 0;
  if ( this->m_fileLog )
  {
    if ( !__stricmp(this->m_strFilename.m_charbuffer->m_data, strFilename->m_charbuffer->m_data) )
      return 1;
    _fclose(v2->m_fileLog);
    v4 = v2->m_pidLogInstance;
    if ( v4 )
      InstanceDiviner::scalar_deleting_destructor(v4, 1u);
    v2->m_pidLogInstance = 0;
  }
  v5 = _fopen(v2->m_strFilename.m_charbuffer->m_data, "w");
  v2->m_fileLog = v5;
  v6 = (PStringBase<unsigned short> *)&v2->m_strFilename;
  if ( v5 )
  {
    PStringBase<unsigned short>::operator=(v6, (const unsigned __int16 *)strFilename);
    result = v2->m_fileLog != 0;
  }
  else
  {
    PStringBase<char>::clear((PStringBase<char> *)v6);
    result = v2->m_fileLog != 0;
  }
  return result;
}

//----- (0040EA50) --------------------------------------------------------  // acclient.c:74393
signed int __thiscall TimestamppedTextFileOutputHandler::Write(TimestamppedTextFileOutputHandler *this, Logger::LoggingSeverity ls, unsigned int lc, const char *szMsg)
{
  TimestamppedTextFileOutputHandler *v4; // esi@1
  FILE *v5; // eax@3
  signed int result; // eax@4

  v4 = this;
  if ( this->m_fFirstWrite )
  {
    TextFileOutputHandler::OpenLogFile((TextFileOutputHandler *)&this->vfptr, &this->m_strFilename);
    v4->m_fFirstWrite = 0;
  }
  v5 = v4->m_fileLog;
  if ( v5 )
  {
    _fprintf(v5, "%0.3lf: ", Timer::cur_time.Cmd, Timer::cur_time.Param);
    _fputs(szMsg, v4->m_fileLog);
    ((void (__thiscall *)(TimestamppedTextFileOutputHandler *))v4->vfptr[2].__vecDelDtor)(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040EAB0) --------------------------------------------------------  // acclient.c:74421
void __thiscall InstanceDiviner::InstanceDiviner(InstanceDiviner *this, PStringBase<char> i_NameStem, bool i_bAllocateImmediately, unsigned int i_RequiredIndex)
{
  InstanceDiviner *v4; // esi@1
  PStringBase<char> v5; // ST04_4@2

  v4 = this;
  this->m_NameStem.m_charbuffer = i_NameStem.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_NameStem.m_charbuffer[-1]);
  v4->m_hMutex = 0;
  v4->m_Index = 0;
  if ( i_bAllocateImmediately )
  {
    v5.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
    InstanceDiviner::AllocateIndex(v4, i_RequiredIndex, v5);
  }
  if ( !InterlockedDecrement((volatile LONG *)&i_NameStem.m_charbuffer[-1])
    && i_NameStem.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&i_NameStem.m_charbuffer[-2].m_data[12])(
      &i_NameStem.m_charbuffer[-2].m_data[12],
      1);
}

//----- (0040EB20) --------------------------------------------------------  // acclient.c:74445
char __thiscall SmartArray<unsigned long,1>::SetNElements(SmartArray<unsigned long,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<unsigned long,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int i; // eax@7

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
      this->m_data[i] = 0;
    goto LABEL_9;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (0040EB80) --------------------------------------------------------  // acclient.c:74474
void __thiscall TextFileOutputHandler::~TextFileOutputHandler(TextFileOutputHandler *this)
{
  TextFileOutputHandler *v1; // ebx@1
  _iobuf *v2; // eax@1
  InstanceDiviner *v3; // esi@3
  int v4; // edi@6
  int v5; // esi@10

  v1 = this;
  v2 = this->m_fileLog;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextFileOutputHandler::vftable;
  if ( v2 )
    _fclose(v2);
  v3 = v1->m_pidLogInstance;
  if ( v3 )
  {
    if ( v3->m_hMutex )
    {
      CloseHandle(v3->m_hMutex);
      v3->m_hMutex = 0;
      v3->m_Index = 0;
    }
    v4 = (int)&v3->m_NameStem.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    operator delete(v3);
  }
  v5 = (int)&v1->m_strFilename.m_charbuffer[-2].m_data[12];
  v1->m_pidLogInstance = 0;
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);
// 7945C0: using guessed type int (__thiscall *TextFileOutputHandler::vftable)(void *, char);

//----- (0040EC10) --------------------------------------------------------  // acclient.c:74511
signed int __thiscall TextFileOutputHandler::Write(TextFileOutputHandler *this, Logger::LoggingSeverity ls, unsigned int lc, const char *szMsg)
{
  TextFileOutputHandler *v4; // esi@1
  signed int result; // eax@4

  v4 = this;
  if ( this->m_fFirstWrite )
  {
    TextFileOutputHandler::OpenLogFile(this, &this->m_strFilename);
    v4->m_fFirstWrite = 0;
  }
  if ( v4->m_fileLog )
  {
    _fputs(szMsg, v4->m_fileLog);
    ((void (__thiscall *)(TextFileOutputHandler *))v4->vfptr[2].__vecDelDtor)(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040EC60) --------------------------------------------------------  // acclient.c:74536
bool __thiscall TextFileOutputHandler::ChangeLogFile(TextFileOutputHandler *this, PStringBase<char> *strFilename)
{
  TextFileOutputHandler *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<char> *v5; // eax@6
  bool result; // al@7

  v2 = this;
  if ( this->m_fFirstWrite )
  {
    v3 = this->m_strFilename.m_charbuffer;
    if ( v3 != strFilename->m_charbuffer )
    {
      v4 = (int)&v3[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = strFilename->m_charbuffer;
      v2->m_strFilename.m_charbuffer = strFilename->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v5[-1]);
    }
    result = 1;
  }
  else
  {
    result = TextFileOutputHandler::OpenLogFile(this, strFilename);
  }
  return result;
}

//----- (0040ECC0) --------------------------------------------------------  // acclient.c:74570
void __thiscall TimestamppedTextFileOutputHandler::TimestamppedTextFileOutputHandler(TimestamppedTextFileOutputHandler *this, const char *szFilename)
{
  TimestamppedTextFileOutputHandler *v2; // esi@1
  char *v3; // edi@1
  const char *v4; // ST00_4@1

  v2 = this;
  this->m_cRef = 1;
  this->m_fFirstWrite = 1;
  v3 = (char *)&this->m_strFilename;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextFileOutputHandler::vftable;
  this->m_fileLog = 0;
  PStringBase<char>::PStringBase<char>(&this->m_strFilename, szFilename);
  v4 = *(const char **)v3;
  v2->m_pidLogInstance = 0;
  DeleteFileA(v4);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TimestamppedTextFileOutputHandler::vftable;
}
// 7945C0: using guessed type int (__thiscall *TextFileOutputHandler::vftable)(void *, char);
// 7945EC: using guessed type int (__thiscall *TimestamppedTextFileOutputHandler::vftable)(void *, char);

//----- (0040ED10) --------------------------------------------------------  // acclient.c:74592
void __thiscall LogController::LogMessage(LogController *this, Logger::LoggingSeverity ls, unsigned int lc, const char *szMessage)
{
  LogController *v4; // edi@1
  unsigned int v5; // ecx@2
  LogController::CategoryHandler *v6; // ecx@3

  v4 = this;
  if ( !this->m_rgGloballyDisabledSeverities[ls] )
  {
    v5 = this->m_hashHandlers.m_numBuckets;
    if ( !v5 )
      goto LABEL_12;
    v6 = v4->m_hashHandlers.m_buckets[lc % v5];
    if ( !v6 )
      goto LABEL_12;
    do
    {
      if ( v6->m_hashKey == lc )
        break;
      v6 = v6->m_hashNext;
    }
    while ( v6 );
    if ( !v6 || v6->m_fEnabled && LogController::CategoryHandler::SendToOutputHandlers(v6, ls, lc, szMessage) == 2 )
LABEL_12:
      LogController::CategoryHandler::SendToOutputHandlers(&v4->m_DefaultHandler, ls, lc, szMessage);
  }
}

//----- (0040ED80) --------------------------------------------------------  // acclient.c:74621
void __cdecl Logger::Log(Logger::LoggingSeverity ls, unsigned int lc, const char *i_pszMsg)
{
  if ( g_fInitialized )
    LogController::LogMessage(&g_LogController, ls, lc, i_pszMsg);
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040EDB0) --------------------------------------------------------  // acclient.c:74629
void __thiscall PStringBase<char>::append_uint32(PStringBase<char> *this, unsigned int num)
{
  PStringBase<char> *v2; // edi@1
  PSRefBufferCharData<char> *v3; // esi@1
  int v4; // eax@1
  int v5; // esi@3
  PStringBase<char> buf; // [sp+0h] [bp-4h]@1

  buf.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&buf, "%lu", num);
  v3 = buf.m_charbuffer;
  v4 = *(_DWORD *)&buf.m_charbuffer[-1].m_data[12];
  if ( v4 != 1 )
    PStringBase<char>::append_n_chars(v2, buf.m_charbuffer->m_data, v4 - 1);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
}

//----- (0040EE20) --------------------------------------------------------  // acclient.c:74654
void __thiscall TextFileOutputHandler::TextFileOutputHandler(TextFileOutputHandler *this, bool fPlaceFileInCurrentDirectory)
{
  TextFileOutputHandler *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  InstanceDiviner *v4; // edi@3
  PStringBase<char> v5; // ST04_4@4
  InstanceDiviner *v6; // eax@4
  PStringBase<char> v7; // ST0C_4@6
  unsigned int v8; // edi@6
  int v9; // ebp@7
  int v10; // eax@7
  int v11; // ebp@9
  int v12; // edi@13
  int v13; // eax@13
  int v14; // edi@15
  PSRefBufferCharData<char> *v15; // eax@18
  int v16; // edi@19
  PSRefBufferCharData<char> *v17; // eax@22
  char *v18; // edi@23
  PStringBase<char> strModuleName; // [sp+10h] [bp-4h]@1

  v2 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextFileOutputHandler::vftable;
  this->m_fileLog = 0;
  this->m_fFirstWrite = 1;
  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  this->m_strFilename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  PSUtils::get_process_name(&strModuleName);
  if ( fPlaceFileInCurrentDirectory )
    PSUtils::strip_directory(&strModuleName);
  PSUtils::remove_extension(&strModuleName);
  v4 = (InstanceDiviner *)operator new(0xCu);
  if ( v4 )
  {
    v5.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
    InstanceDiviner::InstanceDiviner(v4, v5, 0, 0);
  }
  else
  {
    v6 = 0;
  }
  v2->m_pidLogInstance = v6;
  v7.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
  v8 = InstanceDiviner::AllocateIndex(v2->m_pidLogInstance, 0, v7);
  if ( v8 != 1 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&fPlaceFileInCurrentDirectory, "_");
    v9 = fPlaceFileInCurrentDirectory;
    v10 = *(_DWORD *)(fPlaceFileInCurrentDirectory - 4);
    if ( v10 != 1 )
      PStringBase<char>::append_n_chars(&strModuleName, (const char *)fPlaceFileInCurrentDirectory, v10 - 1);
    v11 = v9 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    PStringBase<char>::append_uint32(&strModuleName, v8);
  }
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&fPlaceFileInCurrentDirectory, ".log");
  v12 = fPlaceFileInCurrentDirectory;
  v13 = *(_DWORD *)(fPlaceFileInCurrentDirectory - 4);
  if ( v13 != 1 )
    PStringBase<char>::append_n_chars(&strModuleName, (const char *)fPlaceFileInCurrentDirectory, v13 - 1);
  v14 = v12 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
  v15 = v2->m_strFilename.m_charbuffer;
  if ( v15 != strModuleName.m_charbuffer )
  {
    v16 = (int)&v15[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v15[-1]) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    v17 = strModuleName.m_charbuffer;
    v2->m_strFilename.m_charbuffer = strModuleName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v17[-1]);
  }
  DeleteFileA(v2->m_strFilename.m_charbuffer->m_data);
  v18 = &strModuleName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strModuleName.m_charbuffer[-1]) )
  {
    if ( v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
  }
}
// 7945C0: using guessed type int (__thiscall *TextFileOutputHandler::vftable)(void *, char);

//----- (0040EFD0) --------------------------------------------------------  // acclient.c:74743
TimestamppedTextFileOutputHandler *__thiscall TextFileOutputHandler::scalar_deleting_destructor(TimestamppedTextFileOutputHandler *this, unsigned int a2)
{
  TimestamppedTextFileOutputHandler *v2; // esi@1

  v2 = this;
  TextFileOutputHandler::~TextFileOutputHandler((TextFileOutputHandler *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040EFF0) --------------------------------------------------------  // acclient.c:74755
Logger::ITextFileOutputHandler *__thiscall LogController::GetTextFileOutputHandler(LogController *this, bool fPlaceFileInCurrentDirectory)
{
  LogController *v2; // edi@1
  TextFileOutputHandler *v3; // esi@2

  v2 = this;
  if ( !this->m_plohTextFile )
  {
    v3 = (TextFileOutputHandler *)operator new(0x18u);
    if ( v3 )
    {
      TextFileOutputHandler::TextFileOutputHandler(v3, fPlaceFileInCurrentDirectory);
      v3->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TimestamppedTextFileOutputHandler::vftable;
    }
    else
    {
      v3 = 0;
    }
    v2->m_plohTextFile = (Logger::ITextFileOutputHandler *)v3;
  }
  InterlockedIncrement((volatile LONG *)&v2->m_plohTextFile->m_cRef);
  return v2->m_plohTextFile;
}
// 7945EC: using guessed type int (__thiscall *TimestamppedTextFileOutputHandler::vftable)(void *, char);

//----- (0040F050) --------------------------------------------------------  // acclient.c:74781
char __thiscall LogController::CategoryHandler::RemoveAllHandlers(LogController::CategoryHandler *this)
{
  LogController::CategoryHandler *v1; // esi@1
  unsigned int v2; // eax@2
  Logger::ILoggingOutputHandler **v3; // ecx@3
  int v4; // eax@3
  Logger::ILoggingOutputHandler *v5; // edi@3
  unsigned int v6; // eax@6

  v1 = this;
  while ( 1 )
  {
    v2 = v1->m_rgOutputPlugins.m_num;
    if ( !v2 )
      break;
    v3 = v1->m_rgOutputPlugins.m_data;
    v4 = v2 - 1;
    v1->m_rgOutputPlugins.m_num = v4;
    v5 = v3[v4];
    v3[v4] = 0;
    if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) )
    {
      if ( v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v5, 1u);
    }
  }
  v6 = 0;
  if ( v1->m_rgContextIDs.m_num )
  {
    do
      v1->m_rgContextIDs.m_data[v6++] = 0;
    while ( v6 < v1->m_rgContextIDs.m_num );
  }
  v1->m_rgContextIDs.m_num = 0;
  return 1;
}

//----- (0040F0C0) --------------------------------------------------------  // acclient.c:74819
void __cdecl Logger::LogVAList(Logger::LoggingSeverity ls, unsigned int lc, const char *szFormat, char *args)
{
  Turbine::InplaceString<4096,char> v4; // [sp+0h] [bp-1004h]@2

  if ( g_fInitialized )
  {
    v4.m_pBuffer = v4.m_buffer;
    Turbine::InplaceString<4096,char>::Init(&v4, szFormat, args);
    if ( g_fInitialized )
      LogController::LogMessage(&g_LogController, ls, lc, v4.m_pBuffer);
    if ( (char *)v4.m_pBuffer != v4.m_buffer )
      operator delete[](v4.m_pBuffer);
  }
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040F140) --------------------------------------------------------  // acclient.c:74836
void Logger::LogMacro::operator()(Logger::LogMacro *this, const char *i_szFmt, ...)
{
  va_list va; // [sp+Ch] [bp+Ch]@1

  va_start(va, i_szFmt);
  Logger::LogVAList(this->m_ls, this->m_lc, i_szFmt, va);
}

//----- (0040F160) --------------------------------------------------------  // acclient.c:74845
Logger::ITextFileOutputHandler *__cdecl Logger::GetTextFileOutputHandler()
{
  Logger::ITextFileOutputHandler *result; // eax@2

  if ( g_fInitialized )
    result = LogController::GetTextFileOutputHandler(&g_LogController, 0);
  else
    result = 0;
  return result;
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040F180) --------------------------------------------------------  // acclient.c:74858
char __thiscall SmartArray<Logger::ILoggingOutputHandler *,1>::add_unique(SmartArray<Logger::ILoggingOutputHandler *,1> *this, Logger::ILoggingOutputHandler *const *_data)
{
  SmartArray<Logger::ILoggingOutputHandler *,1> *v2; // esi@1
  unsigned int v3; // edx@1
  unsigned int v4; // eax@1
  Logger::ILoggingOutputHandler **v5; // ecx@2
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
    v7 = SmartArray<char *,1>::get_new_size(v6 + 1);
    if ( !SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)v2, v7) )
      return 0;
  }
  v2->m_data[v2->m_num++] = *_data;
  return 1;
}

//----- (0040F1F0) --------------------------------------------------------  // acclient.c:74896
void __thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>Vtbl *)IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (LogController::CategoryHandler **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (LogController::CategoryHandler **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7945BC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable[2])(void *, char);

//----- (0040F290) --------------------------------------------------------  // acclient.c:74934
void __thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this, IntrusiveHashIterator<unsigned long,LogController::CategoryHandler *,0> iter)
{
  LogController::CategoryHandler *v2; // eax@1
  LogController::CategoryHandler *v3; // edx@2

  v2 = *iter.m_currBucket;
  if ( *iter.m_currBucket == iter.m_currElement )
    goto LABEL_8;
  do
  {
    v3 = v2;
    v2 = v2->m_hashNext;
  }
  while ( v2 != iter.m_currElement );
  if ( v3 )
  {
    v3->m_hashNext = v2->m_hashNext;
    --this->m_numElements;
  }
  else
  {
LABEL_8:
    *iter.m_currBucket = v2->m_hashNext;
    --this->m_numElements;
  }
}

//----- (0040F2D0) --------------------------------------------------------  // acclient.c:74962
char __thiscall LogController::CategoryHandler::AddHandler(LogController::CategoryHandler *this, Logger::ILoggingOutputHandler *i_ploh, unsigned int i_ctx)
{
  LogController::CategoryHandler *v3; // esi@1
  unsigned int v4; // eax@2
  int v5; // esi@2
  int v6; // eax@2
  unsigned int v7; // eax@3
  char result; // al@5

  v3 = this;
  if ( SmartArray<Logger::ILoggingOutputHandler *,1>::add_unique(&this->m_rgOutputPlugins, &i_ploh) )
  {
    InterlockedIncrement((volatile LONG *)&i_ploh->m_cRef);
    v4 = v3->m_rgContextIDs.m_sizeAndDeallocate;
    v5 = (int)&v3->m_rgContextIDs;
    v6 = v4 & 0x7FFFFFFF;
    if ( *(_DWORD *)(v5 + 8) < (unsigned int)v6
      || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v5, v7)) )
      *(_DWORD *)(*(_DWORD *)v5 + 4 * (*(_DWORD *)(v5 + 8))++) = i_ctx;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0040F340) --------------------------------------------------------  // acclient.c:74992
char __thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::add(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this, LogController::CategoryHandler *data)
{
  LogController::CategoryHandler **v2; // edx@1
  LogController::CategoryHandler *v3; // eax@1
  char result; // al@6

  v2 = &this->m_buckets[data->m_hashKey % this->m_numBuckets];
  v3 = *v2;
  if ( !*v2 )
    goto LABEL_4;
  while ( v3->m_hashKey != data->m_hashKey )
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
    data->m_hashNext = *v2;
    *v2 = data;
    if ( v2 < this->m_firstInterestingBucket )
      this->m_firstInterestingBucket = v2;
    result = 1;
    ++this->m_numElements;
  }
  return result;
}

//----- (0040F3A0) --------------------------------------------------------  // acclient.c:75026
LogController::CategoryHandler *__thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this, const unsigned int *key)
{
  const unsigned int v2; // edx@1
  LogController::CategoryHandler **v3; // eax@1
  LogController::CategoryHandler *v4; // esi@1
  int v5; // edx@1
  LogController::CategoryHandler *result; // eax@4
  _BYTE v7[12]; // ST00_12@6

  v2 = *key % this->m_numBuckets;
  v3 = this->m_buckets;
  v4 = v3[v2];
  v5 = (int)&v3[v2];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != *key )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    *(_DWORD *)v7 = this;
    *(_QWORD *)&v7[4] = __PAIR__((unsigned int)v4, v5);
    IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(
      this,
      *(IntrusiveHashIterator<unsigned long,LogController::CategoryHandler *,0> *)v7);
    result = v4;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (0040F400) --------------------------------------------------------  // acclient.c:75065
void __thiscall IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::delete_contents(IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *this)
{
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0> *v1; // esi@1
  int v2; // ecx@2
  LogController::CategoryHandler **v3; // eax@3
  int v4; // eax@4
  LogController::CategoryHandler **v5; // edx@5
  LogController::CategoryHandler *v6; // edi@5
  LogController::CategoryHandler *v7; // eax@7
  LogController::CategoryHandler *v8; // ecx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (LogController::CategoryHandler **)v2 )
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
        v1->m_firstInterestingBucket = (LogController::CategoryHandler **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_21;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_21:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      LogController::CategoryHandler::RemoveAllHandlers(v6);
      if ( (v6->m_rgContextIDs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v6->m_rgContextIDs.m_data);
      if ( (v6->m_rgOutputPlugins.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](v6->m_rgOutputPlugins.m_data);
      operator delete(v6);
    }
  }
}

//----- (0040F4C0) --------------------------------------------------------  // acclient.c:75129
void __thiscall LogController::LogController(LogController *this)
{
  LogController *v1; // esi@1
  int v2; // eax@1
  int v3; // edx@1

  v1 = this;
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>(
    &this->m_hashHandlers,
    0xAu);
  v1->m_LastAssignedContext = 10;
  v2 = (int)&v1->m_DefaultHandler;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_BYTE *)(v2 + 8) = 1;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  v1->m_plohTextFile = 0;
  v1->m_plohConsole = 0;
  v1->m_plohODS = 0;
  v3 = (int)v1->m_rgGloballyDisabledSeverities;
  *(_DWORD *)v3 = 0;
  *(_WORD *)(v3 + 4) = 0;
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::add(&v1->m_hashHandlers, &v1->m_DefaultHandler);
  g_fSegmentInitialized = 1;
}
// 8368D8: using guessed type bool g_fSegmentInitialized;

//----- (0040F530) --------------------------------------------------------  // acclient.c:75162
void __thiscall LogController::~LogController(LogController *this)
{
  LogController *v1; // esi@1
  Logger::ITextFileOutputHandler *v2; // edi@1
  Logger::ILoggingOutputHandler *v3; // edi@6
  Logger::ILoggingOutputHandler *v4; // edi@11
  void *v5; // eax@20

  v1 = this;
  g_fSegmentInitialized = 0;
  g_fInitialized = 0;
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::remove(
    &this->m_hashHandlers,
    &cat_DefaultHandler);
  IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::delete_contents(&v1->m_hashHandlers);
  v2 = v1->m_plohTextFile;
  if ( v2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
    v1->m_plohTextFile = 0;
  }
  v3 = v1->m_plohConsole;
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
      v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
    v1->m_plohConsole = 0;
  }
  v4 = v1->m_plohODS;
  if ( v4 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    v1->m_plohODS = 0;
  }
  LogController::CategoryHandler::RemoveAllHandlers(&v1->m_DefaultHandler);
  if ( (v1->m_DefaultHandler.m_rgContextIDs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_DefaultHandler.m_rgContextIDs.m_data);
  if ( (v1->m_DefaultHandler.m_rgOutputPlugins.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_DefaultHandler.m_rgOutputPlugins.m_data);
  v5 = v1->m_hashHandlers.m_buckets;
  v1->m_hashHandlers.vfptr = (IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>Vtbl *)IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable;
  if ( v5 != v1->m_hashHandlers.m_aInplaceBuckets )
    operator delete[](v5);
  v1->m_hashHandlers.m_buckets = 0;
  v1->m_hashHandlers.m_firstInterestingBucket = 0;
  v1->m_hashHandlers.m_numBuckets = 0;
  v1->m_hashHandlers.m_numElements = 0;
}
// 7945BC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable[2])(void *, char);
// 8368D8: using guessed type bool g_fSegmentInitialized;
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040F640) --------------------------------------------------------  // acclient.c:75217
unsigned int __thiscall LogController::AddCategoryHandler(LogController *this, unsigned int i_lc, Logger::ILoggingOutputHandler *i_ploh)
{
  LogController *v3; // esi@1
  LogController::CategoryHandler *i; // edx@1
  LogController::CategoryHandler *v5; // edi@4
  void *v6; // eax@5

  v3 = this;
  for ( i = this->m_hashHandlers.m_buckets[i_lc % this->m_hashHandlers.m_numBuckets]; i; i = i->m_hashNext )
  {
    if ( i->m_hashKey == i_lc )
      break;
  }
  v5 = i;
  if ( !i )
  {
    v6 = operator new(0x24u);
    if ( v6 )
    {
      *(_DWORD *)v6 = i_lc;
      *((_DWORD *)v6 + 1) = 0;
      *((_BYTE *)v6 + 8) = 1;
      *((_DWORD *)v6 + 3) = 0;
      *((_DWORD *)v6 + 4) = 0;
      *((_DWORD *)v6 + 5) = 0;
      *((_DWORD *)v6 + 6) = 0;
      *((_DWORD *)v6 + 7) = 0;
      *((_DWORD *)v6 + 8) = 0;
      v5 = (LogController::CategoryHandler *)v6;
    }
    else
    {
      v5 = 0;
    }
    IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::add(&v3->m_hashHandlers, v5);
  }
  ++v3->m_LastAssignedContext;
  LogController::CategoryHandler::AddHandler(v5, i_ploh, v3->m_LastAssignedContext);
  return v3->m_LastAssignedContext;
}

//----- (0040F6D0) --------------------------------------------------------  // acclient.c:75259
void __thiscall LogController::Initialize(LogController *this, bool fDefaultLogsToCurrentDirectory)
{
  LogController *v2; // esi@1
  Logger::ITextFileOutputHandler *v3; // edi@1
  LogController::CategoryHandler *v4; // ebx@1
  void *v5; // eax@5
  Logger::ILoggingOutputHandler *v6; // esi@9

  v2 = this;
  v3 = LogController::GetTextFileOutputHandler(this, fDefaultLogsToCurrentDirectory);
  v4 = &v2->m_DefaultHandler;
  LogController::CategoryHandler::AddHandler(&v2->m_DefaultHandler, (Logger::ILoggingOutputHandler *)&v3->vfptr, 0);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
  if ( !v2->m_plohODS )
  {
    v5 = operator new(8u);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = 1;
      *(_DWORD *)v5 = &OutputDebugStringOutputHandler::vftable;
    }
    else
    {
      v5 = 0;
    }
    v2->m_plohODS = (Logger::ILoggingOutputHandler *)v5;
  }
  InterlockedIncrement((volatile LONG *)&v2->m_plohODS->m_cRef);
  v6 = v2->m_plohODS;
  LogController::CategoryHandler::AddHandler(v4, v6, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) )
  {
    if ( v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v6, 1u);
  }
}
// 7945B0: using guessed type int (__thiscall *OutputDebugStringOutputHandler::vftable)(void *, char);

//----- (0040F780) --------------------------------------------------------  // acclient.c:75299
void __cdecl Logger::Initialize(bool fDefaultLogsToCurrentDirectory)
{
  if ( !g_fInitialized )
  {
    LogController::Initialize(&g_LogController, fDefaultLogsToCurrentDirectory);
    g_fInitialized = 1;
  }
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040F7A0) --------------------------------------------------------  // acclient.c:75310
unsigned int __cdecl Logger::AddCategoryHandler(unsigned int i_lc, Logger::ILoggingOutputHandler *i_pHandler)
{
  unsigned int result; // eax@2

  if ( g_fInitialized )
    result = LogController::AddCategoryHandler(&g_LogController, i_lc, i_pHandler);
  else
    result = 0;
  return result;
}
// 8368D9: using guessed type bool g_fInitialized;

//----- (0040F980) --------------------------------------------------------  // acclient.c:75440
OutputDebugStringOutputHandler *__thiscall PreciseTimerInstance::vector_deleting_destructor(OutputDebugStringOutputHandler *this, unsigned int a2)
{
  OutputDebugStringOutputHandler *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (006C3B20) --------------------------------------------------------  // acclient.c:732119
int _E73_6()
{
  LogController::LogController(&g_LogController);
  return atexit(_E74_9);
}

//----- (00725E40) --------------------------------------------------------  // acclient.c:823681
void __cdecl _E74_9()
{
  LogController::~LogController(&g_LogController);
}

