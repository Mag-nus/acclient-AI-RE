/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceSystem
   Object     : AC\accui_misc\AllegianceSystem.obj
   Functions  : 26
   Addresses  : 00569F90 - 00708DB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00569F90) --------------------------------------------------------  // acclient.c:406988
ClientAllegianceSystem *__cdecl ClientAllegianceSystem::GetAllegianceSystem()
{
  return ClientAllegianceSystem::s_pAllegianceSystem;
}
// 8705AC: using guessed type struct ClientAllegianceSystem *ClientAllegianceSystem::s_pAllegianceSystem;

//----- (00569FA0) --------------------------------------------------------  // acclient.c:406995
void __thiscall ClientAllegianceSystem::OnEndCharacterSession(ClientAllegianceSystem *this)
{
  AllegianceProfile::Clear((AllegianceProfile *)&this->m_allegianceProfile.vfptr);
}

//----- (00569FB0) --------------------------------------------------------  // acclient.c:407001
void ClientAllegianceSystem::OnShutdown()
{
  if ( ClientAllegianceSystem::s_pAllegianceSystem )
  {
    ((void (*)(void))ClientAllegianceSystem::s_pAllegianceSystem->vfptr->Release)();
    ClientAllegianceSystem::s_pAllegianceSystem = 0;
  }
}
// 8705AC: using guessed type struct ClientAllegianceSystem *ClientAllegianceSystem::s_pAllegianceSystem;

//----- (00569FD0) --------------------------------------------------------  // acclient.c:407012
unsigned int __stdcall ClientAllegianceSystem::Handle_Allegiance__AllegianceUpdateAborted(const unsigned int etype)
{
  CM_Allegiance::SendNotice_AllegianceUpdateAborted(etype);
  return 0;
}

//----- (00569FF0) --------------------------------------------------------  // acclient.c:407019
unsigned int __stdcall ClientAllegianceSystem::Handle_Allegiance__AllegianceLoginNotificationEvent(unsigned int member, int bNowLoggedIn)
{
  CM_Allegiance::SendNotice_AllegianceLogin(member, bNowLoggedIn != 0);
  return 0;
}

//----- (0056A010) --------------------------------------------------------  // acclient.c:407026
void __thiscall ClientAllegianceSystem::~ClientAllegianceSystem(ClientAllegianceSystem *this)
{
  ClientAllegianceSystem *v1; // esi@1
  NoticeHandler *v2; // edi@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&ClientAllegianceSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  AllegianceHierarchy::~AllegianceHierarchy(&this->m_allegianceProfile._allegiance);
  v1->m_allegianceProfile.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CEE5C: using guessed type __int32 (__stdcall *ClientAllegianceSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0056A050) --------------------------------------------------------  // acclient.c:407047
TResult *__thiscall ClientAllegianceSystem::QueryInterface(ClientAllegianceSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S124_11 & 1 )
  {
    v4 = Offsets_7[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientAllegianceSystem_InterfaceType_58;
    _S124_11 |= 1u;
    Offsets_7[0].key = (_GUID *)&ClientAllegianceSystem_InterfaceType_58;
    dword_870638 = 0;
    dword_87063C = (int)&ClientSystem_InterfaceType_86;
    dword_870640 = 0;
    dword_870644 = (int)&stru_7CEE48;
    dword_870648 = 0;
    dword_87064C = 0;
    dword_870650 = 0;
  }
  v5 = (int)Offsets_7;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 870638: using guessed type int dword_870638;
// 87063C: using guessed type int dword_87063C;
// 870640: using guessed type int dword_870640;
// 870644: using guessed type int dword_870644;
// 870648: using guessed type int dword_870648;
// 87064C: using guessed type int dword_87064C;
// 870650: using guessed type int dword_870650;

//----- (0056A120) --------------------------------------------------------  // acclient.c:407114
unsigned int __thiscall ClientAllegianceSystem::Handle_Allegiance__AllegianceUpdate(ClientAllegianceSystem *this, CAllegianceProfile *prof, unsigned int rank)
{
  AllegianceProfile::operator=((int)&this->m_allegianceProfile, (int)prof);
  CM_Allegiance::SendNotice_AllegianceUpdate(prof, rank);
  return 0;
}

//----- (0056A150) --------------------------------------------------------  // acclient.c:407122
void __thiscall ClientAllegianceSystem::ClientAllegianceSystem(ClientAllegianceSystem *this)
{
  ClientAllegianceSystem *v1; // esi@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientAllegianceSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  CAllegianceProfile::CAllegianceProfile(&this->m_allegianceProfile);
  ClientAllegianceSystem::s_pAllegianceSystem = v1;
  InterlockedIncrement((volatile LONG *)&v1->m_cTurbineRefCount.m_cRef);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7CEE5C: using guessed type __int32 (__stdcall *ClientAllegianceSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8705AC: using guessed type struct ClientAllegianceSystem *ClientAllegianceSystem::s_pAllegianceSystem;

//----- (0056A1A0) --------------------------------------------------------  // acclient.c:407142
unsigned int __thiscall ClientAllegianceSystem::Release(ClientAllegianceSystem *this)
{
  ClientAllegianceSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientAllegianceSystem::~ClientAllegianceSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (0056A1D0) --------------------------------------------------------  // acclient.c:407158
unsigned int __thiscall ClientAllegianceSystem::Handle_Allegiance__AllegianceInfoResponseEvent(ClientAllegianceSystem *this, unsigned int target, CAllegianceProfile *prof)
{
  ClientSystem *v3; // edi@1
  unsigned int v4; // ebp@1
  AllegianceProfile *v5; // ebx@1
  unsigned int result; // eax@2
  unsigned int v7; // esi@3
  bool v8; // zf@6
  unsigned __int16 *v9; // eax@6
  unsigned __int16 *v10; // eax@9
  unsigned int v11; // esi@12
  unsigned __int16 *v12; // eax@14
  char *v13; // esi@17
  AC1Legacy::PSRefBuffer<char> *v14; // esi@20
  AC1Legacy::PStringBase<char> name; // [sp+Ch] [bp-40h]@6
  PStringBase<unsigned short> msg; // [sp+10h] [bp-3Ch]@8
  CAllegianceData data; // [sp+14h] [bp-38h]@1

  v3 = (ClientSystem *)this;
  CAllegianceData::CAllegianceData(&data);
  v4 = target;
  v5 = (AllegianceProfile *)prof;
  if ( AllegianceProfile::GetData((AllegianceProfile *)&prof->vfptr, target, (AllegianceData *)&data.vfptr) )
  {
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (PStringBase<unsigned short> *)&target,
      L"Note: An asterisk (*) indicates that the character is currently online.\n");
    ClientSystem::AddTextToScroll(v3, (PStringBase<unsigned short> *)&target, 0, 1, 0);
    v7 = target - 20;
    if ( !InterlockedDecrement((volatile LONG *)(target - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    AllegianceData::GetFullName((AllegianceData *)&data.vfptr, &name);
    v8 = AllegianceData::IsLoggedIn((AllegianceData *)&data.vfptr) == 0;
    v9 = L" *";
    if ( v8 )
      v9 = &word_794320;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &msg,
      0,
      L"Allegiance information for %hs%s:\n",
      name.m_buffer->m_data,
      v9);
    ClientSystem::AddTextToScroll(v3, &msg, 0, 1, 0);
    if ( AllegianceProfile::GetPatron(v5, v4, (AllegianceData *)&data.vfptr) )
    {
      AllegianceData::GetFullName((AllegianceData *)&data.vfptr, &name);
      v8 = AllegianceData::IsLoggedIn((AllegianceData *)&data.vfptr) == 0;
      v10 = L" *";
      if ( v8 )
        v10 = &word_794320;
      PStringBase<unsigned short>::sprintf(&msg, L"   Patron: %hs%s\n", name.m_buffer->m_data, v10);
      ClientSystem::AddTextToScroll(v3, &msg, 0, 1, 0);
    }
    v11 = AllegianceProfile::GetFirstVassal(v5, v4, (AllegianceData *)&data.vfptr);
    if ( v11 )
    {
      ClientSystem::AddTextToScroll(v3, "   Vassals: \n", 0, 1, 0);
      do
      {
        AllegianceData::GetFullName((AllegianceData *)&data.vfptr, &name);
        v8 = AllegianceData::IsLoggedIn((AllegianceData *)&data.vfptr) == 0;
        v12 = L" *";
        if ( v8 )
          v12 = &word_794320;
        PStringBase<unsigned short>::sprintf(&msg, L"      %hs%s\n", name.m_buffer->m_data, v12);
        ClientSystem::AddTextToScroll(v3, &msg, 0, 1, 0);
        v11 = AllegianceProfile::GetNextVassal(v5, v11, (AllegianceData *)&data.vfptr);
      }
      while ( v11 );
    }
    v13 = (char *)&msg.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&msg.m_charbuffer[-1].m_data[8]) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    v14 = name.m_buffer;
    if ( !InterlockedDecrement((volatile LONG *)&name.m_buffer->m_cRef) )
    {
      if ( v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
    }
    AllegianceData::~AllegianceData((AllegianceData *)&data.vfptr);
    result = 0;
  }
  else
  {
    AllegianceData::~AllegianceData((AllegianceData *)&data.vfptr);
    result = 0;
  }
  return result;
}
// 7CEF28: using guessed type wchar_t asc_7CEF28[3];
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00708C70) --------------------------------------------------------  // acclient.c:796054
void sub_708C70()
{
  flt_8705C8 = 1000.0 + 1.0;
}

//----- (00708C90) --------------------------------------------------------  // acclient.c:796060
void sub_708C90()
{
  flt_8705CC = 24.0 * 8.0;
}

//----- (00708CB0) --------------------------------------------------------  // acclient.c:796066
void sub_708CB0()
{
  flt_8705D0 = 24.0 * 0.5;
}

//----- (00708CD0) --------------------------------------------------------  // acclient.c:796072
int sub_708CD0()
{
  return atexit(nullsub_1335);
}

//----- (00708CE0) --------------------------------------------------------  // acclient.c:796078
int sub_708CE0()
{
  return atexit(nullsub_1336);
}

//----- (00708CF0) --------------------------------------------------------  // acclient.c:796084
int sub_708CF0()
{
  return atexit(nullsub_1337);
}

//----- (00708D00) --------------------------------------------------------  // acclient.c:796090
void sub_708D00()
{
  flt_8705D8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00708D20) --------------------------------------------------------  // acclient.c:796096
void _E108_90()
{
  dbl_8705E0 = 1.0 / 30.0;
}

//----- (00708D40) --------------------------------------------------------  // acclient.c:796102
void _E110_74()
{
  dbl_8705E8 = 1.0 / 5.0;
}

//----- (00708D60) --------------------------------------------------------  // acclient.c:796108
void sub_708D60()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8705F0, PFID_A8R8G8B8);
}

//----- (00708D70) --------------------------------------------------------  // acclient.c:796114
void _E115_74()
{
  dword_870628 = 1024;
}

//----- (00708D80) --------------------------------------------------------  // acclient.c:796120
void _E117_70()
{
  dword_87062C = 0x7FFF;
}

//----- (00708D90) --------------------------------------------------------  // acclient.c:796126
int _E119_24()
{
  const int result; // eax@1

  result = dword_870628;
  dword_870630 = dword_870628;
  return result;
}

//----- (00708DA0) --------------------------------------------------------  // acclient.c:796136
int _E121_65()
{
  return atexit(_E122_92);
}

//----- (00708DB0) --------------------------------------------------------  // acclient.c:796142
int sub_708DB0()
{
  return atexit(nullsub_1334);
}

