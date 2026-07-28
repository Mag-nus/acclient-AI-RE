/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AdminSystem
   Object     : AC\accui_misc\AdminSystem.obj
   Functions  : 23
   Addresses  : 006B5E60 - 007911D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B5E60) --------------------------------------------------------  // acclient.c:719725
void __thiscall ATL::CComBSTR::CComBSTR(ATL::CComBSTR *this, const char *pSrc)
{
  UINT v2; // eax@2
  UINT v3; // edi@2
  int v4; // eax@2
  int v5; // ebx@2
  unsigned __int16 *v6; // eax@2
  unsigned __int16 *v7; // esi@2
  int v8; // [sp+0h] [bp-34h]@2

  if ( pSrc )
  {
    v2 = ((unsigned int (__stdcall *)())ATL::g_pfnGetThreadACP)();
    v3 = v2;
    v4 = MultiByteToWideChar(v2, 0, pSrc, -1, 0, 0);
    v5 = v4;
    v6 = SysAllocStringLen(0, v4 - 1);
    v7 = v6;
    if ( v6 )
      MultiByteToWideChar(v3, 0, pSrc, -1, v6, v5);
    *(_DWORD *)v8 = v7;
  }
  else
  {
    this->m_str = 0;
  }
}
// 81FA8C: invalid function type has been ignored
// 6B5E60: could not find valid save-restore pair for ebx
// 6B5E60: could not find valid save-restore pair for edi
// 6B5E60: could not find valid save-restore pair for esi

//----- (006B5ED0) --------------------------------------------------------  // acclient.c:719758
unsigned int __stdcall ClientAdminSystem::Handle_Admin__Recv_QueryPluginResponse(AC1Legacy::PStringBase<char> *playerName, AC1Legacy::PStringBase<char> *pluginName, AC1Legacy::PStringBase<char> *pluginAuthor, AC1Legacy::PStringBase<char> *pluginEMail, AC1Legacy::PStringBase<char> *pluginWebpage)
{
  return 0;
}

//----- (006B5EE0) --------------------------------------------------------  // acclient.c:719764
unsigned int __stdcall ClientAdminSystem::Handle_Admin__Recv_QueryPluginList(unsigned int context)
{
  IACPlugin *v2; // eax@2
  unsigned __int16 *v3; // esi@3
  AC1Legacy::PSRefBuffer<unsigned short> *v4; // esi@6
  AC1Legacy::PStringBase<unsigned short> pluginList; // [sp+Ch] [bp-8h]@1
  unsigned __int16 *bstrPluginList; // [sp+10h] [bp-4h]@2

  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&pluginList, L"3rd party API not in use.");
  if ( APIManager::APIIsReady() )
  {
    v2 = APIManager::GetACPlugin();
    ((void (__stdcall *)(IACPlugin *, unsigned __int16 **))v2->vfptr[1].QueryInterface)(v2, &bstrPluginList);
    AC1Legacy::PStringBase<unsigned short>::set(&pluginList, bstrPluginList);
  }
  AC1Legacy::PStringBase<unsigned short>::to_spstring(&pluginList, (AC1Legacy::PStringBase<char> *)&bstrPluginList, 0);
  CM_Admin::Event_QueryPluginListResponse(context, (AC1Legacy::PStringBase<char> *)&bstrPluginList);
  v3 = bstrPluginList;
  if ( !InterlockedDecrement((volatile LONG *)bstrPluginList + 1) && v3 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))v3)(v3, 1);
  v4 = pluginList.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&pluginList.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  return 0;
}

//----- (006B5F80) --------------------------------------------------------  // acclient.c:719791
unsigned int __stdcall ClientAdminSystem::Handle_Admin__Recv_QueryPlugin(unsigned int context, AC1Legacy::PStringBase<char> *pluginName)
{
  int v3; // esi@1
  int v4; // eax@1
  AC1Legacy::PStringBase<char> *v5; // edi@1
  IACPlugin *v6; // eax@2
  unsigned __int16 *v7; // ebx@2
  AC1Legacy::PStringBase<char> *v8; // esi@3
  unsigned __int16 *v9; // esi@6
  unsigned __int16 *v10; // esi@9
  AC1Legacy::PSRefBuffer<unsigned short> *v11; // esi@12
  AC1Legacy::PSRefBuffer<unsigned short> *v12; // esi@15
  AC1Legacy::PSRefBuffer<unsigned short> *v13; // esi@18
  AC1Legacy::PStringBase<unsigned short> pluginWebpage; // [sp+20h] [bp-18h]@1
  AC1Legacy::PStringBase<unsigned short> pluginEmail; // [sp+24h] [bp-14h]@1
  AC1Legacy::PStringBase<unsigned short> pluginAuthor; // [sp+28h] [bp-10h]@1
  unsigned __int16 *bstrPluginEmail; // [sp+2Ch] [bp-Ch]@2
  unsigned __int16 *bstrPluginAuthor; // [sp+30h] [bp-8h]@2
  unsigned __int16 *bstrPluginWebpage; // [sp+34h] [bp-4h]@2

  v3 = 0;
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&pluginAuthor, L"Unknown");
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&pluginEmail, L"Unknown");
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&pluginWebpage, L"Unknown");
  v4 = APIManager::APIIsReady();
  v5 = pluginName;
  if ( v4 )
  {
    ATL::CComBSTR::CComBSTR((ATL::CComBSTR *)&pluginName, pluginName->m_buffer->m_data);
    v6 = APIManager::GetACPlugin();
    v7 = (unsigned __int16 *)pluginName;
    ((void (__stdcall *)(IACPlugin *, AC1Legacy::PStringBase<char> *, unsigned __int16 **, unsigned __int16 **, unsigned __int16 **))v6->vfptr[1].AddRef)(
      v6,
      pluginName,
      &bstrPluginAuthor,
      &bstrPluginEmail,
      &bstrPluginWebpage);
    AC1Legacy::PStringBase<unsigned short>::set(&pluginAuthor, bstrPluginAuthor);
    AC1Legacy::PStringBase<unsigned short>::set(&pluginEmail, bstrPluginEmail);
    AC1Legacy::PStringBase<unsigned short>::set(&pluginWebpage, bstrPluginWebpage);
    v3 = 1;
    SysFreeString(v7);
  }
  AC1Legacy::PStringBase<unsigned short>::to_spstring(
    &pluginWebpage,
    (AC1Legacy::PStringBase<char> *)&bstrPluginAuthor,
    0);
  AC1Legacy::PStringBase<unsigned short>::to_spstring(&pluginEmail, (AC1Legacy::PStringBase<char> *)&bstrPluginEmail, 0);
  AC1Legacy::PStringBase<unsigned short>::to_spstring(&pluginAuthor, (AC1Legacy::PStringBase<char> *)&pluginName, 0);
  CM_Admin::Event_QueryPluginResponse(
    context,
    v3,
    v5,
    (AC1Legacy::PStringBase<char> *)&pluginName,
    (AC1Legacy::PStringBase<char> *)&bstrPluginEmail,
    (AC1Legacy::PStringBase<char> *)&bstrPluginAuthor);
  v8 = pluginName;
  if ( !InterlockedDecrement((volatile LONG *)&pluginName[1]) && v8 )
    ((void (__thiscall *)(AC1Legacy::PStringBase<char> *, signed int))v8->m_buffer->vfptr)(v8, 1);
  v9 = bstrPluginEmail;
  if ( !InterlockedDecrement((volatile LONG *)bstrPluginEmail + 1) && v9 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))v9)(v9, 1);
  v10 = bstrPluginAuthor;
  if ( !InterlockedDecrement((volatile LONG *)bstrPluginAuthor + 1) && v10 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))v10)(v10, 1);
  v11 = pluginWebpage.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&pluginWebpage.m_buffer->m_cRef) && v11 )
    v11->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v11, 1u);
  v12 = pluginEmail.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&pluginEmail.m_buffer->m_cRef) && v12 )
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  v13 = pluginAuthor.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&pluginAuthor.m_buffer->m_cRef) && v13 )
    v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
  return 0;
}

//----- (00723F80) --------------------------------------------------------  // acclient.c:821740
void sub_723F80()
{
  flt_8FB584 = 1000.0 + 1.0;
}

//----- (00723FA0) --------------------------------------------------------  // acclient.c:821746
void sub_723FA0()
{
  flt_8FB588 = 24.0 * 8.0;
}

//----- (00723FC0) --------------------------------------------------------  // acclient.c:821752
void sub_723FC0()
{
  flt_8FB58C = 24.0 * 0.5;
}

//----- (00723FE0) --------------------------------------------------------  // acclient.c:821758
int sub_723FE0()
{
  return atexit(nullsub_1330);
}

//----- (00723FF0) --------------------------------------------------------  // acclient.c:821764
int sub_723FF0()
{
  return atexit(nullsub_1331);
}

//----- (00724000) --------------------------------------------------------  // acclient.c:821770
int sub_724000()
{
  return atexit(nullsub_1332);
}

//----- (00724010) --------------------------------------------------------  // acclient.c:821776
void sub_724010()
{
  flt_8FB590 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00724030) --------------------------------------------------------  // acclient.c:821782
void sub_724030()
{
  dbl_8FB598 = 1.0 / 30.0;
}

//----- (00724050) --------------------------------------------------------  // acclient.c:821788
void sub_724050()
{
  dbl_8FB5A0 = 1.0 / 5.0;
}

//----- (00724070) --------------------------------------------------------  // acclient.c:821794
void sub_724070()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FB5A8, PFID_A8R8G8B8);
}

//----- (00724080) --------------------------------------------------------  // acclient.c:821800
void sub_724080()
{
  dword_8FB5E0 = 1024;
}

//----- (00724090) --------------------------------------------------------  // acclient.c:821806
void sub_724090()
{
  dword_8FB5E4 = 0x7FFF;
}

//----- (007240A0) --------------------------------------------------------  // acclient.c:821812
int _E119_51()
{
  const int result; // eax@1

  result = dword_8FB5E0;
  dword_8FB5E8 = dword_8FB5E0;
  return result;
}

//----- (007240B0) --------------------------------------------------------  // acclient.c:821822
int sub_7240B0()
{
  return atexit(nullsub_1328);
}

//----- (007240C0) --------------------------------------------------------  // acclient.c:821828
int _E125_13()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_52, "Misc.TooltipEnable");
  return atexit(_E126_67);
}

//----- (007240E0) --------------------------------------------------------  // acclient.c:821835
int _E128_14()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_52, "Misc.TooltipDelay");
  return atexit(_E129_62);
}

//----- (00724100) --------------------------------------------------------  // acclient.c:821842
int sub_724100()
{
  return atexit(nullsub_1329);
}

//----- (007911A0) --------------------------------------------------------  // acclient.c:937263
void __cdecl _E126_67()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007911D0) --------------------------------------------------------  // acclient.c:937276
void __cdecl _E129_62()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

