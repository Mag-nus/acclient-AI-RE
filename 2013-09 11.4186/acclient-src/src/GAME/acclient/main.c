/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : main
   Object     : GAME\acclient\main.obj
   Functions  : 37
   Addresses  : 00401000 - 00724ED0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00401000) --------------------------------------------------------  // acclient.c:60792
void __stdcall vector_constructor_iterator(void *__t, unsigned int __s, int __n, void *(__thiscall *__f)(void *))
{
  void *v4; // esi@2
  int v5; // edi@2

  if ( __n - 1 >= 0 )
  {
    v4 = __t;
    v5 = __n;
    do
    {
      __f(v4);
      v4 = (char *)v4 + __s;
      --v5;
    }
    while ( v5 );
  }
}

//----- (00401030) --------------------------------------------------------  // acclient.c:60812
void __stdcall vector_destructor_iterator(void *__t, unsigned int __s, int __n, void (__thiscall *__f)(void *))
{
  char *v4; // esi@1
  int v5; // edi@2

  v4 = (char *)__t + __n * __s;
  if ( __n - 1 >= 0 )
  {
    v5 = __n;
    do
    {
      v4 -= __s;
      __f(v4);
      --v5;
    }
    while ( v5 );
  }
}

//----- (00401070) --------------------------------------------------------  // acclient.c:60832
char *__cdecl ps_strcpy(char *out, const char *in)
{
  return strcpy(out, in);
}

//----- (00401090) --------------------------------------------------------  // acclient.c:60838
int __thiscall PackObj::GetPackSize(PackObj *this)
{
  return ((int (*)(void))this->vfptr->GetPackSize)();
}

//----- (004010A0) --------------------------------------------------------  // acclient.c:60844
unsigned int __thiscall ReferenceCountTemplate<268435456,0>::Release(ReferenceCountTemplate<268435456,0> *this)
{
  ReferenceCountTemplate<268435456,0> *v1; // esi@1
  char *v2; // edi@1
  unsigned int result; // eax@2

  v1 = this;
  v2 = (char *)&this->m_cRef;
  if ( InterlockedDecrement((volatile LONG *)&this->m_cRef) )
  {
    result = *(_DWORD *)v2;
  }
  else
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor(v1, 1u);
    result = 0;
  }
  return result;
}

//----- (004010D0) --------------------------------------------------------  // acclient.c:60866
BOOL __cdecl BitUtils::AllAreOn(unsigned int x, unsigned int y)
{
  return (y & x) == y;
}

//----- (004010F0) --------------------------------------------------------  // acclient.c:60872
void __cdecl ClientMain::ClientCleanUp(Client *pClient)
{
  if ( pClient )
  {
    ((void (__thiscall *)(_DWORD))pClient->vfptr[1].IUnknown_Release)(pClient);
    pClient->vfptr->Release((Interface *)pClient);
  }
  CFactory::CleanUp();
  AC1Legacy::Version::Cleanup();
}

//----- (00401120) --------------------------------------------------------  // acclient.c:60884
void __cdecl ClientMain::ConfigureFPU()
{
  Turbine::Debug::SetFloatingPointException(0, 0x80017u);
  __control87(0x10000u, 0x30000u);
  __control87(0, 0x300u);
  __control87(0, 0x40000u);
}

//----- (00401160) --------------------------------------------------------  // acclient.c:60893
signed int __cdecl ConstructClassObjectEx<Client,Interface>(Turbine_GUID *i_rcClassType)
{
  InterfaceSystem *v1; // eax@1
  Interface *pcInterface; // [sp+0h] [bp-8h]@1
  TResult cTr; // [sp+4h] [bp-4h]@1

  pcInterface = 0;
  v1 = InterfaceSystem::GetInstance();
  InterfaceSystem::CreateInstance(v1, &cTr, i_rcClassType, &Interface_InterfaceType_0, 0, (void **)&pcInterface);
  return (cTr.m_val & 0x80000000) != 0 ? 0 : (unsigned int)pcInterface;
}

//----- (00401220) --------------------------------------------------------  // acclient.c:60939
AC1Legacy::PStringBase<char> *__thiscall AC1Legacy::PStringBase<char>::vector_deleting_destructor(AC1Legacy::PStringBase<char> *this, unsigned int a2)
{
  AC1Legacy::PStringBase<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@2
  AC1Legacy::PStringBase<char> *v4; // ebx@2
  AC1Legacy::PStringBase<char> *v5; // edi@2
  int v6; // eax@2
  AC1Legacy::PSRefBuffer<char> *v7; // esi@4
  AC1Legacy::PStringBase<char> *result; // eax@10
  AC1Legacy::PSRefBuffer<char> *v9; // edi@11
  int v10; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].m_buffer;
    v4 = this - 1;
    v5 = &this[(_DWORD)v3];
    v6 = (int)&v3[-1].m_data[3];
    if ( v6 >= 0 )
    {
      v10 = v6 + 1;
      do
      {
        v7 = v5[-1].m_buffer;
        --v5;
        if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
          v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
        --v10;
      }
      while ( v10 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v9 = this->m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&this->m_buffer->m_cRef) && v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004012C0) --------------------------------------------------------  // acclient.c:60988
char __thiscall PStringBase<char>::allocate_ref_buffer(PStringBase<char> *this, unsigned int len)
{
  int v2; // esi@2
  unsigned int v3; // ST0C_4@4
  signed int v9; // eax@4
  void *v10; // eax@2
  char result; // al@10
  PStringBase<char> *v12; // [sp+4h] [bp-8h]@1

  v12 = this;
  if ( len >= 0x10 )
  {
    if ( len > 0x10000 )
    {
      v9 = (len & 0xFFFF0000) + 0x10000;
    }
    else
    {
      v3 = 2 * len;
      __asm { bsr     this, [esp+0Ch+var_4] }
      v9 = 1 << (_EAX + 1);
    }
    v2 = v9 - 16;
    if ( v9 == 16 )
      v10 = operator new[](0x24u);
    else
      v10 = operator new[](v2 + 36);
  }
  else
  {
    v2 = 0;
    v10 = operator new[](0x24u);
  }
  if ( v10 )
  {
    *((_DWORD *)v10 + 1) = 1;
    *(_DWORD *)v10 = AC1Legacy::PSRefBuffer<char>::vftable;
    *((_DWORD *)v10 + 4) = 1;
    *((_DWORD *)v10 + 2) = 1;
    *((_DWORD *)v10 + 3) = -1;
    *((_BYTE *)v10 + 20) = 0;
    v12->m_charbuffer = (PSRefBufferCharData<char> *)((char *)v10 + 20);
    *(_DWORD *)&v12->m_charbuffer[-1].m_data[12] = len + 1;
    *(_DWORD *)&v12->m_charbuffer[-1].m_data[4] = v2 + 16;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7CA074: using guessed type int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char);

//----- (00401380) --------------------------------------------------------  // acclient.c:61043
void __thiscall PStringBase<char>::PStringBase<char>(PStringBase<char> *this, const char *str)
{
  char **v2; // edi@1
  volatile LONG *v3; // ST00_4@4

  v2 = (char **)this;
  if ( str && *str )
  {
    PStringBase<char>::allocate_ref_buffer(this, strlen(str));
    strcpy(*v2, str);
  }
  else
  {
    v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    this->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v3);
  }
}

//----- (004013E0) --------------------------------------------------------  // acclient.c:61063
int __stdcall WinMain(HINSTANCE__ *hCurrentInst, HINSTANCE__ *__formal, char *lpszCmdLine, int a4)
{
  ErrorStream *v4; // eax@2
  const char *v6; // eax@3
  unsigned int v7; // ebx@7
  char **v8; // edi@7
  unsigned int v9; // ecx@7
  signed int v10; // eax@7
  Client *v11; // esi@7
  PStringBase<char> strAppName; // [sp+18h] [bp-1Ch]@14
  SmartArray<char *,1> rgArgs; // [sp+1Ch] [bp-18h]@3
  SmartBuffer sbArgs; // [sp+28h] [bp-Ch]@3

  if ( !Turbine::Debug::Init("ac", &name, 0xE08u) )
  {
    v4 = ErrorStream::operator<<(&perr, "Could not initialize Debugging facilities.");
    ErrorStream::operator<<(v4, endp);
    return 1;
  }
  SmartBuffer::SmartBuffer(&sbArgs);
  rgArgs.m_data = 0;
  rgArgs.m_sizeAndDeallocate = 0;
  rgArgs.m_num = 0;
  v6 = GetCommandLineA();
  if ( ConvertCommandLineToArgList(v6, &sbArgs, &rgArgs) )
  {
    v7 = rgArgs.m_num;
    v8 = rgArgs.m_data;
    ClientMain::ConfigureFPU();
    ProgramTypeSystem::s_eProgramType = 1073741825;
    IError::AddDataErrorHandlers(0, &PStringBase<char>::null_string);
    APIManager::Init();
    AC1Legacy::Version::Init(*v8);
    ACCFactory::Init(v9);
    v10 = ConstructClassObjectEx<Client,Interface>(&Client_ClassType);
    v11 = (Client *)v10;
    if ( v10 )
    {
      if ( (unsigned __int8)(*(int (__thiscall **)(int, char **, unsigned int, signed int))(*(_DWORD *)(v10 + 4) + 16))(
                              v10 + 4,
                              v8,
                              v7,
                              1) )
      {
        PStringBase<char>::PStringBase<char>(&strAppName, "Asheron's Call");
        if ( (unsigned __int8)((int (__thiscall *)(Client *, PStringBase<char> *, signed int, signed int))v11->vfptr[1].IUnknown_AddRef)(
                                v11,
                                &strAppName,
                                1,
                                1) )
        {
          v11->vfptr[1].Release((Interface *)v11);
          ClientMain::ClientCleanUp(v11);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAppName);
          SmartArray<char *,1>::~SmartArray<char *,1>((SmartArray<long,1> *)&rgArgs);
          SmartBuffer::ReleaseMasterBuffer(&sbArgs);
          return 0;
        }
        ClientMain::ClientCleanUp(v11);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strAppName);
        SmartArray<char *,1>::~SmartArray<char *,1>((SmartArray<long,1> *)&rgArgs);
      }
      else
      {
        ClientMain::ClientCleanUp(v11);
        if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](rgArgs.m_data);
      }
    }
    else
    {
      CFactory::CleanUp();
      AC1Legacy::Version::Cleanup();
      if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        operator delete[](rgArgs.m_data);
    }
    SmartBuffer::ReleaseMasterBuffer(&sbArgs);
    return 1;
  }
  if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](rgArgs.m_data);
  SmartBuffer::ReleaseMasterBuffer(&sbArgs);
  return 1;
}
// 836720: using guessed type enum ProgramType ProgramTypeSystem::s_eProgramType;

//----- (006C2C40) --------------------------------------------------------  // acclient.c:731270
int _E73()
{
  return atexit(_E74_1);
}

//----- (006C2C50) --------------------------------------------------------  // acclient.c:731276
int _E76()
{
  return atexit(_E77_27);
}

//----- (006C2C60) --------------------------------------------------------  // acclient.c:731282
int _E79()
{
  return atexit(_E80_1);
}

//----- (006C2C70) --------------------------------------------------------  // acclient.c:731288
void _E98()
{
  LOWEST_DATA_RATE_51 = 1024;
}

//----- (006C2C80) --------------------------------------------------------  // acclient.c:731294
void _E100()
{
  HIGHEST_DATA_RATE_51 = 0x7FFF;
}

//----- (006C2C90) --------------------------------------------------------  // acclient.c:731300
int _E102()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_51;
  INITIAL_MAX_DATA_RATE = LOWEST_DATA_RATE_51;
  return result;
}

//----- (006C2CA0) --------------------------------------------------------  // acclient.c:731310
void _E104()
{
  LODWORD(dword_83646C) = 1053364187;
}

//----- (006C2CB0) --------------------------------------------------------  // acclient.c:731316
void _E106()
{
  outside_val = 1000.0 + 1.0;
}

//----- (006C2CD0) --------------------------------------------------------  // acclient.c:731322
void _E108()
{
  block_length = 24.0 * 8.0;
}

//----- (006C2CF0) --------------------------------------------------------  // acclient.c:731328
void _E110()
{
  half_square_length = 24.0 * 0.5;
}

//----- (006C2D10) --------------------------------------------------------  // acclient.c:731334
void _E112()
{
  DEFAULT_VIEW_RADIUS = 0.00019999999 * 3.0 + 0.1;
}

//----- (006C2D30) --------------------------------------------------------  // acclient.c:731340
void _E114()
{
  MIN_QUANTUM = 1.0 / 30.0;
}

//----- (006C2D50) --------------------------------------------------------  // acclient.c:731346
void _E116()
{
  MAX_QUANTUM = 1.0 / 5.0;
}

//----- (006C2D70) --------------------------------------------------------  // acclient.c:731352
void _E118()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8, PFID_A8R8G8B8);
}

//----- (006C2D80) --------------------------------------------------------  // acclient.c:731358
int _E121()
{
  return atexit(_E122_38);
}

//----- (006C2D90) --------------------------------------------------------  // acclient.c:731364
int _E124()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution, "Display.Resolution");
  return atexit(_E125_14);
}

//----- (006C2DB0) --------------------------------------------------------  // acclient.c:731371
int _E127()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen, "Display.FullScreen");
  return atexit(_E128_15);
}

//----- (006C2DD0) --------------------------------------------------------  // acclient.c:731378
int _E130()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate, "Display.RefreshRate");
  return atexit(_E131_11);
}

//----- (006C2DF0) --------------------------------------------------------  // acclient.c:731385
int _E133()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh, "Display.SyncToRefresh");
  return atexit(_E134_10);
}

//----- (006C2E10) --------------------------------------------------------  // acclient.c:731392
int _E1_0()
{
  return atexit(_E2_0);
}

//----- (00724E40) --------------------------------------------------------  // acclient.c:822563
void __cdecl _E125_14()
{
  char *v0; // esi@1

  v0 = &Display_Resolution.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724E70) --------------------------------------------------------  // acclient.c:822576
void __cdecl _E128_15()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724EA0) --------------------------------------------------------  // acclient.c:822589
void __cdecl _E131_11()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00724ED0) --------------------------------------------------------  // acclient.c:822602
void __cdecl _E134_10()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

