/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmDataPatchUI
   Object     : GAME\game_ui_misc\gmDataPatchUI.obj
   Functions  : 44
   Addresses  : 004EDE30 - 00763B90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EDE30) --------------------------------------------------------  // acclient.c:282601
signed int __thiscall gmDataPatchUI::ListenToElementMessage(gmDataPatchUI *this, UIElementMessageInfo *i_rMsg)
{
  UIFramework *v2; // esi@1

  v2 = (UIFramework *)this;
  if ( i_rMsg->idMessage == 1 && i_rMsg->idElement == 268436508 )
    UIFramework::QueueUIMode(0x10000009u);
  return UIFramework::ListenToElementMessage(v2, i_rMsg);
}

//----- (004EDE60) --------------------------------------------------------  // acclient.c:282612
void __thiscall gmDataPatchUI::SetConnectLevel(gmDataPatchUI *this, float i_fConnectLevel)
{
  gmDataPatchUI *v2; // esi@1
  UIElement *v3; // ecx@2
  signed int v4; // edx@2

  v2 = this;
  if ( i_fConnectLevel != this->m_fConnectLevel )
  {
    v3 = this->m_connectMeter;
    v2->m_fConnectLevel = i_fConnectLevel;
    UIElement::SetAttribute_Float(v3, 0x66u, i_fConnectLevel);
    v4 = 1;
    if ( v2->m_fConnectLevel > 0.0 )
    {
      v4 = 268435515;
      if ( v2->m_fConnectLevel >= 1.0 )
        v4 = 268435516;
    }
    ((void (__stdcall *)(signed int))v2->m_connectText->vfptr[13].__vecDelDtor)(v4);
  }
}

//----- (004EDEE0) --------------------------------------------------------  // acclient.c:282636
void __thiscall gmDataPatchUI::SetPatchLevel(gmDataPatchUI *this, float i_fPatchLevel)
{
  if ( i_fPatchLevel != this->m_fPatchLevel )
  {
    this->m_fPatchLevel = i_fPatchLevel;
    UIElement::SetAttribute_Float(this->m_patchMeter, 0x66u, i_fPatchLevel);
  }
}

//----- (004EDF10) --------------------------------------------------------  // acclient.c:282646
void __thiscall gmDataPatchUI::UseTime(gmDataPatchUI *this)
{
  gmDataPatchUI *v1; // esi@1
  char v2; // [sp+4h] [bp-Ch]@6
  unsigned __int64 freeBytes; // [sp+8h] [bp-8h]@6

  v1 = this;
  if ( this->m_fConnectLevel < 1.0 && *(_WORD *)&SharedNet::s_pNet[1].receivers_[454] )
    gmDataPatchUI::SetConnectLevel(this, 1.0);
  if ( v1->m_expected && COERCE_DOUBLE(Timer::cur_time.Cmd) >= v1->m_timeNextDiskspaceCheck )
  {
    DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
    DiskSpace::GetDriveFreeBytes(0, &freeBytes);
    v1->m_timeNextDiskspaceCheck = COERCE_DOUBLE(Timer::cur_time.Cmd) + 60.0;
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v2);
  }
  if ( v1->m_fConnectLevel >= 1.0
    && v1->m_fPatchLevel >= 1.0
    && (!PacketController::Instance() || *(_BYTE *)(UIFramework::GetPersistantData() + 72)) )
    UIFramework::QueueUIMode(0x10000001u);
}

//----- (004EDFF0) --------------------------------------------------------  // acclient.c:282669
void __thiscall gmDataPatchUI::OnDDDEvent(gmDataPatchUI *this, DDDEvent _eventNum, unsigned int _nBytes)
{
  gmDataPatchUI *v3; // esi@1
  unsigned int v4; // ST04_4@6
  unsigned int v5; // edi@7
  unsigned int v6; // eax@7
  float progress; // ST14_4@10
  double v8; // st7@9
  float i_fPatchLevel; // ST08_4@11
  gmClient *v10; // eax@12
  StringInfo siStatus; // [sp+10h] [bp-90h]@1

  v3 = this;
  StringInfo::StringInfo(&siStatus);
  switch ( _eventNum )
  {
    case 0:
      StringInfo::SetStringIDandTableEnum(&siStatus, ID_DataPatch_Interrogation, 268435458);
      if ( v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] == (HashSetData<UIElement *> *)-1 )
        UIElement_Text::SetStringInfo(
          (UIElement_Text *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
          &siStatus);
      break;
    case 2:
      StringInfo::SetStringIDandTableEnum(&siStatus, ID_DataPatch_Waiting, 268435458);
      StringInfo::AddVariable_Int(&siStatus, token_total, _nBytes);
      if ( v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] == (HashSetData<UIElement *> *)-1 )
        UIElement_Text::SetStringInfo(
          (UIElement_Text *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
          &siStatus);
      break;
    case 3:
      v4 = ID_DataPatch_Patching;
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = (HashSetData<UIElement *> *)_nBytes;
      StringInfo::SetStringIDandTableEnum(&siStatus, v4, 268435458);
      UIElement_Text::SetStringInfo(
        (UIElement_Text *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
        &siStatus);
      break;
    case 5:
      v5 = (unsigned int)((char *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] + _nBytes);
      v6 = (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6];
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = (HashSetData<UIElement *> *)v5;
      if ( v6 != -1 )
      {
        if ( v6 )
        {
          progress = (double)v5 / (double)v6;
          v8 = MathLib::Clamp(progress, 0.0, 1.0);
        }
        else
        {
          v8 = MathLib::Clamp(1.0, 0.0, 1.0);
        }
        i_fPatchLevel = v8;
        gmDataPatchUI::SetPatchLevel((gmDataPatchUI *)((char *)v3 - 156), i_fPatchLevel);
        StringInfo::SetStringIDandTableEnum(&siStatus, ID_DataPatch_PatchProgress, 268435458);
        StringInfo::AddVariable_UInt(
          &siStatus,
          token_percent,
          (unsigned int)(unsigned __int64)(*(float *)&v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5]
                                         * 100.0));
        StringInfo::AddVariable_UInt(
          &siStatus,
          token_total,
          (unsigned int)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] >> 10);
        goto LABEL_17;
      }
      break;
    case 4:
      v10 = Client::GetInstance();
      if ( v10 )
        ((void (__thiscall *)(gmClient *, unsigned int))v10->vfptr[4].IUnknown_QueryInterface)(
          v10,
          v3 != (gmDataPatchUI *)156 ? (unsigned int)v3 : 0);
      if ( v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] == (HashSetData<UIElement *> *)-1 )
        v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = 0;
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7] = v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6];
      gmDataPatchUI::SetPatchLevel((gmDataPatchUI *)((char *)v3 - 156), 1.0);
      StringInfo::SetStringIDandTableEnum(&siStatus, ID_DataPatch_PatchingDone, 268435458);
LABEL_17:
      UIElement_Text::SetStringInfo(
        (UIElement_Text *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2],
        &siStatus);
      break;
    default:
      break;
  }
  StringInfo::~StringInfo(&siStatus);
}

//----- (004EE210) --------------------------------------------------------  // acclient.c:282761
void __thiscall gmDataPatchUI::ListenToGlobalMessage(gmDataPatchUI *this, unsigned int i_messageID, int i_data_int)
{
  if ( i_messageID == 3 )
    gmDataPatchUI::UseTime(this);
}

//----- (004EE220) --------------------------------------------------------  // acclient.c:282768
void __thiscall gmDataPatchUI::~gmDataPatchUI(gmDataPatchUI *this)
{
  gmDataPatchUI *v1; // esi@1
  NoticeHandler *v2; // ebx@1
  char *v3; // edi@1
  gmClient *v4; // eax@1
  CPluginManager *v5; // ecx@3

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v3 = (char *)&this->vfptr;
  this->vfptr = (IInputActionCallbackVtbl *)&gmDataPatchUI::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (CPluginPrototypeVtbl *)&gmDataPatchUI::vftable;
  v4 = Client::GetInstance();
  if ( v4 )
    ((void (__thiscall *)(gmClient *, char *))v4->vfptr[4].IUnknown_QueryInterface)(v4, v3);
  UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  UIMainFramework::RemoveRootElement((UIMainFramework *)&v1->vfptr, &v1->m_datapatchField);
  v5 = (CPluginManager *)*((_DWORD *)v3 + 1);
  *(_DWORD *)v3 = &CPluginPrototype::vftable;
  if ( v5 )
  {
    CPluginManager::RemovePluginPrototype(v5, (CPluginPrototype *)v3);
    *((_DWORD *)v3 + 1) = 0;
  }
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  UIMainFramework::~UIMainFramework((UIMainFramework *)&v1->vfptr);
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3420: using guessed type void *gmDataPatchUI::vftable;
// 7C3430: using guessed type int (__thiscall *gmDataPatchUI::vftable)(void *, char);

//----- (004EE2A0) --------------------------------------------------------  // acclient.c:282804
gmDataPatchUI *__thiscall gmDataPatchUI::vector_deleting_destructor(gmDataPatchUI *this, unsigned int a2)
{
  return gmDataPatchUI::scalar_deleting_destructor((gmDataPatchUI *)((char *)this - 156), a2);
}

//----- (004EE2B0) --------------------------------------------------------  // acclient.c:282810
void __thiscall gmDataPatchUI::gmDataPatchUI(gmDataPatchUI *this)
{
  gmDataPatchUI *v1; // esi@1
  int v2; // eax@1
  UIElement *v3; // eax@2
  int v4; // eax@2
  UIElement *v5; // ecx@2
  UIElement *v6; // eax@2
  int v7; // eax@2
  UIElement *v8; // ecx@2
  UIElement *v9; // eax@2
  UIElement *v10; // ecx@2
  gmClient *v11; // eax@3
  UIElement *v12; // ecx@6

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&CDDDStatusPlugin::vftable;
  v1->m_pManager = 0;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmDataPatchUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->vfptr = (CPluginPrototypeVtbl *)&gmDataPatchUI::vftable;
  v1->m_datapatchField = 0;
  v1->m_connectText = 0;
  v1->m_connectMeter = 0;
  v1->m_patchText = 0;
  v1->m_patchMeter = 0;
  LODWORD(v1->m_fConnectLevel) = -1082130432;
  LODWORD(v1->m_fPatchLevel) = -1082130432;
  v1->m_expected = -1;
  v1->m_recieved = 0;
  v2 = UIMainFramework::CreateAndAddRootElement((UIMainFramework *)&v1->vfptr, 0x10000001u, 0x1000041Au);
  v1->m_datapatchField = (UIElement *)v2;
  if ( v2 )
  {
    v3 = UIElement::GetChildRecursive((UIElement *)v2, 0x10000420u);
    v4 = v3->vfptr[12].OnAction((IInputActionCallback *)v3, (InputEvent *)12);
    v5 = v1->m_datapatchField;
    v1->m_connectText = (UIElement_Text *)v4;
    v6 = UIElement::GetChildRecursive(v5, 0x10000421u);
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)12);
    v8 = v1->m_datapatchField;
    v1->m_patchText = (UIElement_Text *)v7;
    v9 = UIElement::GetChildRecursive(v8, 0x1000041Eu);
    v10 = v1->m_datapatchField;
    v1->m_connectMeter = v9;
    v1->m_patchMeter = UIElement::GetChildRecursive(v10, 0x1000041Fu);
  }
  v11 = Client::GetInstance();
  if ( v11 )
    ((void (__thiscall *)(gmClient *, int))v11->vfptr[3].Release)(v11, &v1->vfptr);
  UIListener::RegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  gmDataPatchUI::SetConnectLevel(v1, 0.0);
  if ( 0.0 != v1->m_fPatchLevel )
  {
    v12 = v1->m_patchMeter;
    LODWORD(v1->m_fPatchLevel) = 0;
    UIElement::SetAttribute_Float(v12, 0x66u, 0.0);
  }
}
// 7949A8: using guessed type int (__thiscall *CDDDStatusPlugin::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3420: using guessed type void *gmDataPatchUI::vftable;
// 7C3430: using guessed type int (__thiscall *gmDataPatchUI::vftable)(void *, char);

//----- (004EE410) --------------------------------------------------------  // acclient.c:282877
gmDataPatchUI *__thiscall gmDataPatchUI::scalar_deleting_destructor(gmDataPatchUI *this, unsigned int a2)
{
  gmDataPatchUI *v2; // esi@1

  v2 = this;
  gmDataPatchUI::~gmDataPatchUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004EE430) --------------------------------------------------------  // acclient.c:282889
void __cdecl gmDataPatchUI::Create()
{
  gmDataPatchUI *v0; // eax@1

  v0 = (gmDataPatchUI *)operator new(0xD0u);
  if ( v0 )
    gmDataPatchUI::gmDataPatchUI(v0);
}

//----- (004EE450) --------------------------------------------------------  // acclient.c:282899
void __cdecl gmDataPatchUI::Register(unsigned int mode)
{
  UIFlow::RegisterFrameworkClass(mode, (UIMainFramework *(__cdecl *)())gmDataPatchUI::Create);
}

//----- (006F7570) --------------------------------------------------------  // acclient.c:780109
void sub_6F7570()
{
  flt_840C3C = 1000.0 + 1.0;
}

//----- (006F7590) --------------------------------------------------------  // acclient.c:780115
void sub_6F7590()
{
  flt_840C40 = 24.0 * 8.0;
}

//----- (006F75B0) --------------------------------------------------------  // acclient.c:780121
void sub_6F75B0()
{
  flt_840C44 = 24.0 * 0.5;
}

//----- (006F75D0) --------------------------------------------------------  // acclient.c:780127
int sub_6F75D0()
{
  return atexit(nullsub_481);
}

//----- (006F75E0) --------------------------------------------------------  // acclient.c:780133
int sub_6F75E0()
{
  return atexit(nullsub_482);
}

//----- (006F75F0) --------------------------------------------------------  // acclient.c:780139
int sub_6F75F0()
{
  return atexit(nullsub_483);
}

//----- (006F7600) --------------------------------------------------------  // acclient.c:780145
int _E106_78()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_18, "Display.Resolution");
  return atexit(_E107_79);
}

//----- (006F7620) --------------------------------------------------------  // acclient.c:780152
int _E109_47()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_18, "Display.FullScreen");
  return atexit(sub_763B30);
}

//----- (006F7640) --------------------------------------------------------  // acclient.c:780159
int _E112_70()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_18, "Display.RefreshRate");
  return atexit(_E113_54);
}

//----- (006F7660) --------------------------------------------------------  // acclient.c:780166
int _E115_51()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_18, "Display.SyncToRefresh");
  return atexit(_E116_46);
}

//----- (006F7680) --------------------------------------------------------  // acclient.c:780173
void _E118_54()
{
  dword_840C58 = 1024;
}

//----- (006F7690) --------------------------------------------------------  // acclient.c:780179
void _E120_44()
{
  dword_840C5C = 0x7FFF;
}

//----- (006F76A0) --------------------------------------------------------  // acclient.c:780185
int _E122_23()
{
  const int result; // eax@1

  result = dword_840C58;
  INITIAL_MAX_DATA_RATE_53 = dword_840C58;
  return result;
}

//----- (006F76B0) --------------------------------------------------------  // acclient.c:780195
unsigned int _E124_49()
{
  unsigned int result; // eax@1

  result = compute_str_hash("PROGRESS");
  ID_Progress = result;
  return result;
}

//----- (006F76D0) --------------------------------------------------------  // acclient.c:780205
unsigned int _E126_26()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_PatchProgress");
  ID_DataPatch_PatchProgress = result;
  return result;
}

//----- (006F76F0) --------------------------------------------------------  // acclient.c:780215
unsigned int _E128_9()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_PatchRate");
  ID_DataPatch_PatchRate = result;
  return result;
}

//----- (006F7710) --------------------------------------------------------  // acclient.c:780225
unsigned int _E130_37()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_Interrogation");
  ID_DataPatch_Interrogation = result;
  return result;
}

//----- (006F7730) --------------------------------------------------------  // acclient.c:780235
unsigned int _E132_22()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_Patching");
  ID_DataPatch_Patching = result;
  return result;
}

//----- (006F7750) --------------------------------------------------------  // acclient.c:780245
unsigned int _E134_6()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_PatchingDone");
  ID_DataPatch_PatchingDone = result;
  return result;
}

//----- (006F7770) --------------------------------------------------------  // acclient.c:780255
unsigned int _E136_23()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_DataPatch_Waiting");
  ID_DataPatch_Waiting = result;
  return result;
}

//----- (006F7790) --------------------------------------------------------  // acclient.c:780265
unsigned int _E138_19()
{
  unsigned int result; // eax@1

  result = compute_str_hash("error");
  token_error = result;
  return result;
}

//----- (006F77B0) --------------------------------------------------------  // acclient.c:780275
unsigned int _E140_3()
{
  unsigned int result; // eax@1

  result = compute_str_hash("host");
  token_host = result;
  return result;
}

//----- (006F77D0) --------------------------------------------------------  // acclient.c:780285
unsigned int _E142_20()
{
  unsigned int result; // eax@1

  result = compute_str_hash("port");
  token_port = result;
  return result;
}

//----- (006F77F0) --------------------------------------------------------  // acclient.c:780295
unsigned int _E144_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("percent");
  token_percent = result;
  return result;
}

//----- (006F7810) --------------------------------------------------------  // acclient.c:780305
unsigned int _E146_4()
{
  unsigned int result; // eax@1

  result = compute_str_hash("rate");
  token_rate = result;
  return result;
}

//----- (006F7830) --------------------------------------------------------  // acclient.c:780315
unsigned int _E148_23()
{
  unsigned int result; // eax@1

  result = compute_str_hash("total");
  token_total = result;
  return result;
}

//----- (006F7850) --------------------------------------------------------  // acclient.c:780325
unsigned int _E150_18()
{
  unsigned int result; // eax@1

  result = compute_str_hash("so_far");
  token_so_far = result;
  return result;
}

//----- (006F7870) --------------------------------------------------------  // acclient.c:780335
int sub_6F7870()
{
  return atexit(nullsub_480);
}

//----- (00763B00) --------------------------------------------------------  // acclient.c:890289
void __cdecl _E107_79()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763B30) --------------------------------------------------------  // acclient.c:890302
void __cdecl sub_763B30()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763B60) --------------------------------------------------------  // acclient.c:890315
void __cdecl _E113_54()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00763B90) --------------------------------------------------------  // acclient.c:890328
void __cdecl _E116_46()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

