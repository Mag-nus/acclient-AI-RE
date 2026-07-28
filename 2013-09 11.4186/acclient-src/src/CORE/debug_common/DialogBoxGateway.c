/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DialogBoxGateway
   Object     : CORE\debug_common\DialogBoxGateway.obj
   Functions  : 12
   Addresses  : 0040E200 - 00725DA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040E200) --------------------------------------------------------  // acclient.c:73816
int __cdecl DialogBoxGateways::ReportThread_PrepareForDialogBox()
{
  int v0; // ebx@1
  int v1; // edi@1
  unsigned int v2; // esi@2
  unsigned __int64 v3; // rax@3

  v0 = dword_836814;
  v1 = DialogBoxGateways::s_qwReportContext;
  if ( !InterlockedIncrement(&DialogBoxGateways::s_nReportThreadPrepares) )
  {
    v2 = 0;
    if ( G_dialogBoxGateways.m_Plugins.m_num )
    {
      do
      {
        v3 = (unsigned __int64)(unsigned __int8)((int (*)(void))G_dialogBoxGateways.m_Plugins.m_data[v2]->vfptr[2].__vecDelDtor)() << v2;
        ++v2;
        v1 |= v3;
        v0 |= HIDWORD(v3);
      }
      while ( v2 < G_dialogBoxGateways.m_Plugins.m_num );
    }
    LODWORD(DialogBoxGateways::s_qwReportContext) = v1;
    dword_836814 = v0;
  }
  return v1;
}
// 836810: using guessed type unsigned __int64 DialogBoxGateways::s_qwReportContext;
// 836814: using guessed type int dword_836814;

//----- (0040E270) --------------------------------------------------------  // acclient.c:73848
void __cdecl DialogBoxGateways::ReportThread_DoneWithDialogBox(unsigned __int64 context)
{
  unsigned int v1; // esi@2
  unsigned __int64 v2; // rax@3

  if ( InterlockedDecrement(&DialogBoxGateways::s_nReportThreadPrepares) < 0 )
  {
    v1 = 0;
    if ( G_dialogBoxGateways.m_Plugins.m_num )
    {
      do
      {
        v2 = context >> v1;
        LOBYTE(v2) = (context >> v1) & 1;
        ((void (__fastcall *)(_DWORD, _DWORD, _DWORD))G_dialogBoxGateways.m_Plugins.m_data[v1]->vfptr[2].OnPluggedIn)(
          G_dialogBoxGateways.m_Plugins.m_data[v1],
          HIDWORD(v2),
          v2);
        ++v1;
      }
      while ( v1 < G_dialogBoxGateways.m_Plugins.m_num );
    }
  }
}

//----- (0040E2C0) --------------------------------------------------------  // acclient.c:73874
int __cdecl DialogBoxGateways::DialogThread_PrepareForDialogBox()
{
  int v0; // ebx@1
  int v1; // edi@1
  unsigned int v2; // esi@2
  unsigned __int64 v3; // rax@3

  v0 = dword_83680C;
  v1 = DialogBoxGateways::s_qwDialogContext;
  if ( !InterlockedIncrement(&DialogBoxGateways::s_nDialogThreadPrepares) )
  {
    v2 = 0;
    if ( G_dialogBoxGateways.m_Plugins.m_num )
    {
      do
      {
        v3 = (unsigned __int64)(unsigned __int8)((int (*)(void))G_dialogBoxGateways.m_Plugins.m_data[v2]->vfptr[3].__vecDelDtor)() << v2;
        ++v2;
        v1 |= v3;
        v0 |= HIDWORD(v3);
      }
      while ( v2 < G_dialogBoxGateways.m_Plugins.m_num );
    }
    LODWORD(DialogBoxGateways::s_qwDialogContext) = v1;
    dword_83680C = v0;
  }
  return v1;
}
// 836808: using guessed type unsigned __int64 DialogBoxGateways::s_qwDialogContext;
// 83680C: using guessed type int dword_83680C;

//----- (0040E330) --------------------------------------------------------  // acclient.c:73906
void __cdecl DialogBoxGateways::DialogThread_DoneWithDialogBox(unsigned __int64 context)
{
  unsigned int v1; // esi@2
  unsigned __int64 v2; // rax@3

  if ( InterlockedDecrement(&DialogBoxGateways::s_nDialogThreadPrepares) < 0 )
  {
    v1 = 0;
    if ( G_dialogBoxGateways.m_Plugins.m_num )
    {
      do
      {
        v2 = context >> v1;
        LOBYTE(v2) = (context >> v1) & 1;
        ((void (__fastcall *)(_DWORD, _DWORD, _DWORD))G_dialogBoxGateways.m_Plugins.m_data[v1]->vfptr[3].OnPluggedIn)(
          G_dialogBoxGateways.m_Plugins.m_data[v1],
          HIDWORD(v2),
          v2);
        ++v1;
      }
      while ( v1 < G_dialogBoxGateways.m_Plugins.m_num );
    }
  }
}

//----- (0040E380) --------------------------------------------------------  // acclient.c:73932
void __thiscall DialogBoxGateway::~DialogBoxGateway(DialogBoxGateway *this)
{
  DialogBoxGateway *v1; // esi@1
  CPluginManager *v2; // ecx@1

  v1 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&DialogBoxGateway::vftable;
  CPluginManager::RemovePluginPrototype(&G_dialogBoxGateways, (CPluginPrototype *)&this->vfptr);
  v2 = v1->m_pManager;
  v1->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v2 )
  {
    CPluginManager::RemovePluginPrototype(v2, (CPluginPrototype *)&v1->vfptr);
    v1->m_pManager = 0;
  }
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 79454C: using guessed type int (__thiscall *DialogBoxGateway::vftable)(void *, char);

//----- (0040E3B0) --------------------------------------------------------  // acclient.c:73952
DialogBoxGateway::ThisFunctionHasBeenRenamed InArchiveVersionStack::You_Must_Not_Have_Multiple_Implementations_Of_AddRef_In_A_Hierarchy()
{
  return 0;
}

//----- (0040E3C0) --------------------------------------------------------  // acclient.c:73958
DialogBoxGateway::ThisFunctionHasBeenRenamed __stdcall DialogBoxGateway::OnDialogBoxEnd(bool __formal)
{
  return 0;
}

//----- (0040E3D0) --------------------------------------------------------  // acclient.c:73964
bool DialogBoxGateway::DialogThread_OnDialogBoxBegin()
{
  return 0;
}

//----- (0040E3E0) --------------------------------------------------------  // acclient.c:73970
DialogBoxGateway *__thiscall DialogBoxGateway::vector_deleting_destructor(DialogBoxGateway *this, unsigned int a2)
{
  DialogBoxGateway *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&DialogBoxGateway::vftable;
  CPluginManager::RemovePluginPrototype(&G_dialogBoxGateways, (CPluginPrototype *)&this->vfptr);
  v3 = v2->m_pManager;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, (CPluginPrototype *)&v2->vfptr);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 79454C: using guessed type int (__thiscall *DialogBoxGateway::vftable)(void *, char);

//----- (0040E430) --------------------------------------------------------  // acclient.c:73993
void __thiscall DialogBoxGateway::DialogBoxGateway(DialogBoxGateway *this)
{
  this->m_pManager = 0;
  this->vfptr = (CPluginPrototypeVtbl *)&DialogBoxGateway::vftable;
  CPluginManager::AddPluginPrototype(&G_dialogBoxGateways, (CPluginPrototype *)&this->vfptr);
}
// 79454C: using guessed type int (__thiscall *DialogBoxGateway::vftable)(void *, char);

//----- (006C3A40) --------------------------------------------------------  // acclient.c:732055
int _E73_5()
{
  return atexit(_E74_8);
}

//----- (00725DA0) --------------------------------------------------------  // acclient.c:823675
void __cdecl _E74_8()
{
  CPluginManager::~CPluginManager(&G_dialogBoxGateways);
}

