/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Items
   Object     : AC\accui_gameplay\Items.obj
   Functions  : 33
   Addresses  : 00586E90 - 00709DA0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00586E90) --------------------------------------------------------  // acclient.c:431989
int __cdecl ItemHolder::CheckHookStatus(ACCWeenieObject *ween_obj, ACCWeenieObject *container, int *not_owner)
{
  unsigned int v3; // edx@3
  ITEM_TYPE v4; // esi@3
  unsigned int v6; // eax@9

  *not_owner = 0;
  if ( !ween_obj || !container )
    return 0;
  v3 = container->pwd._hook_type;
  v4 = container->pwd._hook_item_types;
  if ( !v3 || v4 == TYPE_UNDEF )
    return 1;
  if ( !container->pwd._house_owner_iid )
  {
    *not_owner = 1;
    return 0;
  }
  v6 = ween_obj->pwd._hook_type;
  if ( !v6 || !(v6 & v3) )
    return 0;
  return (v4 & ((int (*)(void))ween_obj->vfptr[6].__vecDelDtor)()) != 0;
}

//----- (00586F00) --------------------------------------------------------  // acclient.c:432014
unsigned int __cdecl ItemHolder::GetObjectSplitSize(ACCWeenieObject *_weenObj)
{
  unsigned int result; // eax@2

  if ( _weenObj->id == ACCWeenieObject::selectedID )
  {
    result = GenItemHolder::splitSize;
  }
  else
  {
    result = _weenObj->pwd._stackSize;
    if ( !result )
      result = 1;
  }
  return result;
}

//----- (00586F30) --------------------------------------------------------  // acclient.c:432032
int __cdecl ItemHolder::IsMergeAttemptLegal(unsigned int _objectID, unsigned int _mergeToID, int _quiet)
{
  int result; // eax@1
  HashBaseData<unsigned long> *v4; // esi@3
  HashBaseData<unsigned long> *v5; // eax@3
  unsigned int v6; // edx@6
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@11
  StringInfo siError; // [sp+8h] [bp-90h]@11

  result = ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(_quiet);
  if ( result )
  {
    if ( _objectID == _mergeToID )
      goto LABEL_19;
    v4 = ClientObjMaintSystem::GetWeenieObject(_objectID);
    v5 = ClientObjMaintSystem::GetWeenieObject(_mergeToID);
    if ( !v4 )
      goto LABEL_19;
    if ( !v5 )
      goto LABEL_19;
    if ( v4[21].vfptr <= (HashBaseData<unsigned long>Vtbl *)1 )
      goto LABEL_19;
    v6 = (unsigned int)v5[21].vfptr;
    if ( v6 <= 1 )
      goto LABEL_19;
    if ( v4[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 || v5[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
    {
      if ( !_quiet )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &_value,
          L"You cannot merge items while they are being traded.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        goto LABEL_18;
      }
    }
    else
    {
      if ( v4[13].id == v5[13].id )
      {
        if ( v5[20].id < v6 )
          return 1;
        if ( _quiet )
          goto LABEL_19;
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"The destination stack is already full.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        goto LABEL_18;
      }
      if ( !_quiet )
      {
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You cannot merge different types of items.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_18:
        StringInfo::~StringInfo(&siError);
        goto LABEL_19;
      }
    }
LABEL_19:
    result = 0;
  }
  return result;
}

//----- (005870C0) --------------------------------------------------------  // acclient.c:432105
int __cdecl ItemHolder::AttemptToPlaceInContainer_IsItemLegal(unsigned int i_itemID, int i_bQuiet)
{
  HashBaseData<unsigned long> *v2; // esi@1
  char *v3; // esi@3
  unsigned int v5; // eax@9
  char *v6; // esi@13
  PStringBase<unsigned short> *v7; // eax@24
  PStringBase<unsigned short> *v8; // eax@28
  PStringBase<unsigned short> *v9; // eax@32
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@3
  PStringBase<unsigned short> result; // [sp+Ch] [bp-94h]@24
  StringInfo siError; // [sp+10h] [bp-90h]@3

  v2 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  if ( !v2 )
  {
    if ( !i_bQuiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"That item is not valid!");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v3 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_7;
    }
    return 0;
  }
  if ( SmartBox::smartbox )
    v5 = SmartBox::smartbox->player_id;
  else
    v5 = 0;
  if ( i_itemID == v5 )
  {
    if ( !i_bQuiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        L"You cannot place yourself within a container!");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v6 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_7;
    }
    return 0;
  }
  if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v2->vfptr[6].__vecDelDtor)(v2) == 16 )
  {
    if ( !i_bQuiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"You cannot pick up creatures!");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_7:
      StringInfo::~StringInfo(&siError);
      return 0;
    }
    return 0;
  }
  if ( (unsigned int)v2[21].hash_next & 4 && !v2[15].vfptr && !v2[15].hash_next )
  {
    if ( !i_bQuiet )
    {
      v7 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v2, &result, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"The %s cannot be picked up!",
        v7->m_charbuffer);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_33:
      StringInfo::~StringInfo(&siError);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      return 0;
    }
    return 0;
  }
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v2) && v2[16].hash_next )
  {
    if ( !i_bQuiet )
    {
      v8 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v2, &result, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"The %s is being wielded by someone else!",
        v8->m_charbuffer);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_33;
    }
    return 0;
  }
  if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v2) && v2[17].vfptr )
  {
    if ( !i_bQuiet )
    {
      v9 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v2, &result, NAME_APPROPRIATE, 0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"The %s can't be picked up!",
        v9->m_charbuffer);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_33;
    }
    return 0;
  }
  return 1;
}

//----- (005873D0) --------------------------------------------------------  // acclient.c:432234
int __cdecl ItemHolder::AttemptSetGroundObject(unsigned int _objectID)
{
  int v1; // eax@1
  HashBaseData<unsigned long> *v2; // esi@2
  char *v3; // esi@4
  PStringBase<unsigned short> *v4; // eax@11
  ClientUISystem *v5; // eax@13
  PStringBase<unsigned short> errorText; // [sp+0h] [bp-98h]@4
  PStringBase<unsigned short> result; // [sp+4h] [bp-94h]@11
  StringInfo siError; // [sp+8h] [bp-90h]@4

  v1 = (int)ClientUISystem::GetUISystem();
  if ( v1 )
  {
    v2 = ClientObjMaintSystem::GetWeenieObject(_objectID);
    if ( !ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
      return 0;
    if ( !v2 )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        L"The object has no representation on the client.");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v3 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      return 0;
    }
    if ( (unsigned int)v2[21].hash_next & 1 )
    {
      v5 = ClientUISystem::GetUISystem();
      ClientUISystem::SetGroundObject(v5, _objectID, 1);
      v1 = 1;
    }
    else
    {
      if ( !((int (__thiscall *)(HashBaseData<unsigned long> *))v2->vfptr[11].__vecDelDtor)(v2) )
      {
        v4 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v2, &result, NAME_APPROPRIATE, 0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"The %s is locked", v4->m_charbuffer);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      }
      v1 = 0;
    }
  }
  return v1;
}

//----- (00587520) --------------------------------------------------------  // acclient.c:432294
char __cdecl ItemHolder::TargetCompatibleWithObject(unsigned int _targetID, unsigned int _targetingObjectID, bool _quiet, bool _displayUseMessage)
{
  HashBaseData<unsigned long> *v4; // esi@3
  HashBaseData<unsigned long> *v5; // eax@3
  HashBaseData<unsigned long> *v6; // edi@3
  char v7; // al@6
  PSRefBufferCharData<unsigned short> *v8; // ST10_4@8
  PSRefBufferCharData<unsigned short> *v9; // ST10_4@12
  PSRefBufferCharData<unsigned short> *v10; // ST10_4@16
  char v11; // al@18
  PSRefBufferCharData<unsigned short> *v12; // ST10_4@22
  PSRefBufferCharData<unsigned short> *v13; // ST10_4@25
  PSRefBufferCharData<unsigned short> *v14; // ST10_4@29
  PStringBase<unsigned short> *v15; // ecx@30
  unsigned int v17; // ebx@34
  PStringBase<unsigned short> *v18; // edi@36
  PStringBase<unsigned short> *v19; // eax@36
  PStringBase<unsigned short> *v20; // eax@38
  PStringBase<unsigned short> *v21; // eax@41
  PStringBase<unsigned short> errorText; // [sp+Ch] [bp-A0h]@8
  PStringBase<unsigned short> result; // [sp+10h] [bp-9Ch]@8
  PStringBase<unsigned short> v24; // [sp+14h] [bp-98h]@36
  ItemUses uses; // [sp+18h] [bp-94h]@5
  StringInfo siError; // [sp+1Ch] [bp-90h]@9

  if ( !_targetID )
    return 0;
  if ( !_targetingObjectID )
    return 0;
  v4 = ClientObjMaintSystem::GetWeenieObject(_targetingObjectID);
  v5 = ClientObjMaintSystem::GetWeenieObject(_targetID);
  v6 = v5;
  if ( !v4 || !v5 )
    return 0;
  ItemUses::ItemUses(&uses, (const unsigned int)v4[18].vfptr);
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    v7 = ItemUses::GetLeastLimitedSourceUse(&uses);
    if ( v7 & 8 )
    {
      if ( !_quiet )
      {
        v8 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"You must own the %s to use it", v8);
LABEL_9:
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_32:
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        return 0;
      }
      return 0;
    }
    if ( v7 & 4 )
    {
      if ( _quiet )
        return 0;
      v9 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"You must wield the %s to use it", v9);
LABEL_13:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_32;
    }
  }
  if ( v6[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
  {
    if ( _quiet )
      return 0;
    v10 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"You can't use the %s on an item you are trading",
      v10);
    goto LABEL_30;
  }
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v6) )
  {
    v11 = ItemUses::GetLeastLimitedTargetUse(&uses);
    if ( v11 & 8 )
    {
      if ( _targetID != GetPlayerID() || !ItemUses::IsUseable_SelfTarget(&uses) )
      {
        if ( !_quiet )
        {
          v12 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &errorText,
            0,
            L"You can't use the %s on what you don't own",
            v12);
          goto LABEL_9;
        }
        return 0;
      }
    }
    else if ( v11 & 4 )
    {
      if ( _quiet )
        return 0;
      v13 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"You can't use the %s on what you aren't wielding",
        v13);
      goto LABEL_13;
    }
  }
  if ( _targetID == GetPlayerID() && !ItemUses::IsUseable_SelfTarget(&uses) )
  {
    if ( _quiet )
      return 0;
    v14 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Cannot use the %s on yourself", v14);
LABEL_30:
    v15 = &result;
LABEL_31:
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v15);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_32;
  }
  v17 = v4[18].id;
  if ( !(((int (__thiscall *)(HashBaseData<unsigned long> *))v6->vfptr[6].__vecDelDtor)(v6) & v17) )
  {
    if ( _quiet )
      return 0;
    v18 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v6, &v24, NAME_APPROPRIATE, 0);
    v19 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &result, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      &errorText,
      0,
      L"Cannot use the %s with the %s",
      v19->m_charbuffer,
      v18->m_charbuffer);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
    v15 = &v24;
    goto LABEL_31;
  }
  if ( _displayUseMessage )
  {
    v20 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v4, &v24, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Using the %s", v20->m_charbuffer);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v24);
    if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v6->vfptr[4].__vecDelDtor)(v6) )
      PStringBase<unsigned short>::append_string(&errorText, L" on ");
    else
      PStringBase<unsigned short>::append_string(&errorText, L" with the ");
    v21 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v6, &v24, NAME_APPROPRIATE, 0);
    PStringBase<unsigned short>::append_string(&errorText, v21);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v24);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
  }
  return 1;
}
// 7E2418: using guessed type wchar_t aOn_2[5];
// 7E24A0: using guessed type wchar_t aYouCanTUseTh_2[49];
// 7E2508: using guessed type wchar_t aYouCanTUseTh_1[43];
// 7E2560: using guessed type wchar_t aYouCanTUseTheS[48];

//----- (005878F0) --------------------------------------------------------  // acclient.c:432467
int __cdecl ItemHolder::AttemptMerge(unsigned int _objectID, unsigned int _mergeToID, int _quiet)
{
  HashBaseData<unsigned long> *v3; // ebx@1
  HashBaseData<unsigned long> *v4; // edi@1
  int result; // eax@1
  signed int v6; // edx@3
  signed int v7; // ecx@6
  HashBaseData<unsigned long>Vtbl *v8; // eax@6
  int v9; // eax@8
  bool v10; // cf@8
  int *v11; // eax@8
  int v12; // [sp+10h] [bp-8h]@6
  int v13; // [sp+14h] [bp-4h]@8

  v3 = ClientObjMaintSystem::GetWeenieObject(_objectID);
  v4 = ClientObjMaintSystem::GetWeenieObject(_mergeToID);
  result = ItemHolder::IsMergeAttemptLegal(_objectID, _mergeToID, _quiet);
  if ( result )
  {
    if ( v3->id == ACCWeenieObject::selectedID )
    {
      v6 = GenItemHolder::splitSize;
    }
    else
    {
      v6 = v3[20].id;
      if ( !v6 )
        v6 = 1;
    }
    v7 = v4[20].id;
    v8 = v4[21].vfptr;
    v12 = v6;
    if ( !v7 )
      v7 = 1;
    v9 = (int)((char *)v8 - v7);
    v13 = v9;
    v10 = v6 < (unsigned int)v9;
    v11 = &v12;
    if ( !v10 )
      v11 = &v13;
    ACCWeenieObject::UIAttemptMerge((ACCWeenieObject *)v3, _mergeToID, *v11);
    CM_UI::SendNotice_FullMergingItem(_objectID, _mergeToID);
    ACCWeenieObject::SetSelectedObject(_mergeToID, 0);
    result = 1;
  }
  return result;
}

//----- (005879B0) --------------------------------------------------------  // acclient.c:432516
int __cdecl ItemHolder::AttemptToPlaceInContainer_IsContainerLegal(unsigned int i_itemID, unsigned int i_containerID, int i_bQuiet)
{
  HashBaseData<unsigned long> *v3; // eax@1
  HashBaseData<unsigned long> *v4; // esi@1
  char *v5; // esi@3
  char *v7; // esi@10
  unsigned int v8; // eax@16
  PStringBase<unsigned short> *v9; // eax@20
  PStringBase<unsigned short> *v10; // eax@23
  HashBaseData<unsigned long> *v11; // eax@24
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-98h]@3
  int not_owner; // [sp+Ch] [bp-94h]@20
  StringInfo siError; // [sp+10h] [bp-90h]@3

  v3 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
  v4 = v3;
  if ( !v3 )
  {
    if ( !i_bQuiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"The destination container is not valid!");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v5 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) )
      {
        if ( v5 )
          (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
      }
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_7:
      StringInfo::~StringInfo(&siError);
      return 0;
    }
    return 0;
  }
  if ( i_itemID == i_containerID )
  {
    if ( !i_bQuiet )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"You cannot place an object within itself!");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      v7 = (char *)&errorText.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&errorText.m_charbuffer[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_7;
    }
    return 0;
  }
  if ( !((unsigned int)v3[21].hash_next & 1) )
  {
    v8 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
    if ( i_containerID != v8 )
    {
      if ( !i_bQuiet )
      {
        v9 = ACCWeenieObject::GetObjectNameWide(
               (ACCWeenieObject *)v4,
               (PStringBase<unsigned short> *)&not_owner,
               NAME_APPROPRIATE,
               0);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"The %s is locked", v9->m_charbuffer);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&not_owner);
        StringInfo::StringInfo(&siError);
        StringInfo::SetLiteralValue(&siError, &errorText, 1);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_29:
        StringInfo::~StringInfo(&siError);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
        return 0;
      }
      return 0;
    }
  }
  if ( v4[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
  {
    if ( !i_bQuiet )
    {
      v10 = ACCWeenieObject::GetObjectNameWide(
              (ACCWeenieObject *)v4,
              (PStringBase<unsigned short> *)&not_owner,
              NAME_APPROPRIATE,
              0);
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"The %s is being traded",
        v10->m_charbuffer);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&not_owner);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_29;
    }
    return 0;
  }
  v11 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  if ( !ItemHolder::CheckHookStatus((ACCWeenieObject *)v11, (ACCWeenieObject *)v4, &not_owner) )
  {
    if ( !i_bQuiet )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"That item cannot be placed on the hook.");
      if ( not_owner )
        PStringBase<unsigned short>::sprintf_append(&errorText, L" You must own the house to manipulate the hook.");
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_29;
    }
    return 0;
  }
  return 1;
}

//----- (00587C40) --------------------------------------------------------  // acclient.c:432633
int __cdecl ItemHolder::AttemptAutoMerge(unsigned int i_itemID, unsigned int i_topContainerID, unsigned int i_preferredContainerID)
{
  HashBaseData<unsigned long> *v3; // esi@1
  HashBaseData<unsigned long> *v4; // edi@1
  HashBaseData<unsigned long> *v5; // eax@1
  int v6; // ebx@6
  unsigned int v7; // edi@7
  HashBaseData<unsigned long> *v8; // esi@7
  HashBaseData<unsigned long>Vtbl *v9; // eax@10
  signed int v10; // esi@10
  IDList *v12; // eax@17
  int v13; // esi@18
  ACCWeenieObject *prefContainerObject; // [sp+10h] [bp-1Ch]@1
  IDList contentsList; // [sp+14h] [bp-18h]@6

  v3 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  v4 = ClientObjMaintSystem::GetWeenieObject(i_topContainerID);
  v5 = ClientObjMaintSystem::GetWeenieObject(i_preferredContainerID);
  prefContainerObject = (ACCWeenieObject *)v5;
  if ( !v3 || !v4 || i_preferredContainerID && !v5 || v3[21].vfptr <= (HashBaseData<unsigned long>Vtbl *)1 )
    return 0;
  ACCWeenieObject::GetExhaustiveContainedItemsList((ACCWeenieObject *)v4, &contentsList);
  v6 = 0;
  if ( contentsList.numIDs <= 0 )
  {
LABEL_14:
    IDList::~IDList(&contentsList);
    return 0;
  }
  while ( 1 )
  {
    v7 = IDList::GetByNum(&contentsList, v6);
    v8 = ClientObjMaintSystem::GetWeenieObject(v7);
    if ( v8 )
    {
      if ( i_itemID != v7 && ItemHolder::IsMergeAttemptLegal(i_itemID, v7, 1) )
      {
        v9 = v8[21].vfptr;
        v10 = v8[20].id;
        if ( !v10 )
          v10 = 1;
        if ( GenItemHolder::splitSize <= (unsigned int)((char *)v9 - v10) )
          break;
      }
    }
    ++v6;
    if ( v6 >= contentsList.numIDs )
      goto LABEL_14;
  }
  if ( prefContainerObject )
  {
    v12 = ACCWeenieObject::GetContainedItemsList(prefContainerObject);
    IDList::IsInList(v12, v7);
  }
  v13 = ItemHolder::AttemptMerge(i_itemID, v7, 0);
  IDList::~IDList(&contentsList);
  return v13;
}

//----- (00587D60) --------------------------------------------------------  // acclient.c:432693
int __cdecl ItemHolder::WillItemFitInContainer(unsigned int i_itemID, unsigned int i_containerID)
{
  HashBaseData<unsigned long> *v2; // eax@1
  HashBaseData<unsigned long> *v3; // esi@1
  unsigned int v4; // eax@5
  HashBaseData<unsigned long> *v5; // eax@9
  HashBaseData<unsigned long> *v7; // edi@11
  HashBaseData<unsigned long> *v8; // eax@11
  HashBaseData<unsigned long> *v9; // esi@11
  int v10; // edi@14
  IDList *v11; // eax@17
  int v12; // edi@19
  IDList *v13; // eax@23
  int not_owner; // [sp+Ch] [bp-4h]@9

  v2 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
  v3 = v2;
  if ( !v2 || i_itemID == i_containerID )
    return 0;
  if ( !((unsigned int)v2[21].hash_next & 1) )
  {
    v4 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
    if ( i_containerID != v4 )
      return 0;
  }
  if ( v3[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
    return 0;
  v5 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  if ( !ItemHolder::CheckHookStatus((ACCWeenieObject *)v5, (ACCWeenieObject *)v3, &not_owner) )
    return 0;
  v7 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
  v8 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
  v9 = v8;
  if ( v7 && v8 )
  {
    if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v7) )
    {
      v10 = (int)v9[17].vfptr;
      if ( v10 == -1 )
        return 1;
      if ( ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v9) < v10 )
        return 1;
      if ( ACCWeenieObject::GetContainedContainersList((ACCWeenieObject *)v9) )
      {
        v11 = ACCWeenieObject::GetContainedContainersList((ACCWeenieObject *)v9);
        if ( IDList::IsInList(v11, i_itemID) )
          return 1;
      }
    }
    else
    {
      v12 = v9[16].id;
      if ( v12 == -1 || ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v9) < v12 )
        return 1;
      if ( GenItemHolder::splitSize == GenItemHolder::maxSplitSize )
      {
        if ( ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v9) )
        {
          v13 = ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v9);
          if ( IDList::IsInList(v13, i_itemID) )
            return 1;
        }
      }
    }
  }
  return 0;
}

//----- (00587E90) --------------------------------------------------------  // acclient.c:432762
int __cdecl ItemHolder::IsDragIntoContainerAttemptLegal(unsigned int i_itemID, unsigned int i_containerID)
{
  int v2; // ecx@0
  int result; // eax@1
  HashBaseData<unsigned long> *v4; // esi@2
  unsigned int v5; // eax@4
  HashBaseData<unsigned long> *v6; // eax@15
  HashBaseData<unsigned long> *v7; // esi@15
  unsigned int v8; // eax@19
  HashBaseData<unsigned long> *v9; // eax@23
  HashBaseData<unsigned long> *v10; // ebp@24
  HashBaseData<unsigned long> *v11; // eax@24
  HashBaseData<unsigned long> *v12; // esi@24
  int v13; // edi@27
  IDList *v14; // eax@30
  int v15; // edi@32
  IDList *v16; // eax@36
  int not_owner; // [sp+0h] [bp-4h]@1

  not_owner = v2;
  result = ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(1);
  if ( result )
  {
    v4 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
    result = 0;
    if ( v4 )
    {
      v5 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
      if ( i_itemID != v5
        && ((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[6].__vecDelDtor)(v4) != 16
        && (!((unsigned int)v4[21].hash_next & 4) || v4[15].vfptr || v4[15].hash_next)
        && (ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) || !v4[16].hash_next)
        && (!ACCWeenieObject::IsContainer((ACCWeenieObject *)v4) || !v4[17].vfptr) )
      {
        v6 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
        v7 = v6;
        if ( v6 )
        {
          if ( i_itemID != i_containerID )
          {
            if ( (unsigned int)v6[21].hash_next & 1
              || (!SmartBox::smartbox ? (v8 = 0) : (v8 = SmartBox::smartbox->player_id), i_containerID == v8) )
            {
              if ( v7[10].vfptr != (HashBaseData<unsigned long>Vtbl *)1 )
              {
                v9 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
                if ( ItemHolder::CheckHookStatus((ACCWeenieObject *)v9, (ACCWeenieObject *)v7, &not_owner) )
                {
                  v10 = ClientObjMaintSystem::GetWeenieObject(i_itemID);
                  v11 = ClientObjMaintSystem::GetWeenieObject(i_containerID);
                  v12 = v11;
                  if ( v10 )
                  {
                    if ( v11 )
                    {
                      if ( !ACCWeenieObject::IsContainer((ACCWeenieObject *)v10)
                        || (v13 = (int)v12[17].vfptr, v13 == -1)
                        || ACCWeenieObject::GetNumContainedContainers((ACCWeenieObject *)v12) < v13
                        || ACCWeenieObject::GetContainedContainersList((ACCWeenieObject *)v12)
                        && (v14 = ACCWeenieObject::GetContainedContainersList((ACCWeenieObject *)v12),
                            IDList::IsInList(v14, i_itemID)) )
                      {
                        if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v10)
                          || (v15 = v12[16].id, v15 == -1)
                          || ACCWeenieObject::GetNumContainedItems((ACCWeenieObject *)v12) < v15
                          || GenItemHolder::splitSize == GenItemHolder::maxSplitSize
                          && ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v12)
                          && (v16 = ACCWeenieObject::GetContainedItemsList((ACCWeenieObject *)v12),
                              IDList::IsInList(v16, i_itemID)) )
                          result = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (00588070) --------------------------------------------------------  // acclient.c:432847
bool __cdecl ItemHolder::IsTargetCompatibleWithTargetingObject(unsigned int i_idTargetObject)
{
  unsigned int v1; // ebx@1
  HashBaseData<unsigned long> *v2; // esi@3
  HashBaseData<unsigned long> *v3; // eax@3
  HashBaseData<unsigned long> *v4; // edi@3
  char v5; // al@6
  char v6; // al@10
  unsigned int v8; // esi@17

  v1 = i_idTargetObject;
  if ( !i_idTargetObject )
    return 0;
  if ( !ItemHolder::targetingObject )
    return 0;
  v2 = ClientObjMaintSystem::GetWeenieObject(ItemHolder::targetingObject);
  v3 = ClientObjMaintSystem::GetWeenieObject(v1);
  v4 = v3;
  if ( !v2 )
    return 0;
  if ( !v3 )
    return 0;
  ItemUses::ItemUses((ItemUses *)&i_idTargetObject, (const unsigned int)v2[18].vfptr);
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v2) )
  {
    v5 = ItemUses::GetLeastLimitedSourceUse((ItemUses *)&i_idTargetObject);
    if ( v5 & 8 || v5 & 4 )
      return 0;
  }
  if ( v4[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
    return 0;
  if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v4) )
  {
    v6 = ItemUses::GetLeastLimitedTargetUse((ItemUses *)&i_idTargetObject);
    if ( v6 & 8 )
    {
      if ( v1 != GetPlayerID() || !ItemUses::IsUseable_SelfTarget((ItemUses *)&i_idTargetObject) )
        return 0;
    }
    else if ( v6 & 4 )
    {
      return 0;
    }
  }
  if ( v1 == GetPlayerID() && !ItemUses::IsUseable_SelfTarget((ItemUses *)&i_idTargetObject) )
    return 0;
  v8 = v2[18].id;
  return (((int (__thiscall *)(HashBaseData<unsigned long> *))v4->vfptr[6].__vecDelDtor)(v4) & v8) != 0;
}

//----- (00588140) --------------------------------------------------------  // acclient.c:432898
int __cdecl ItemHolder::AttemptToPlaceInContainer(unsigned int i_itemID, unsigned int i_topContainerID, unsigned int i_preferredContainerID, int i_bAttemptAutoMerge, int i_place)
{
  int result; // eax@1
  unsigned int v6; // esi@4
  HashBaseData<unsigned long> *v7; // eax@4
  HashBaseData<unsigned long> *v8; // edi@4
  unsigned int v9; // eax@8
  HashBaseData<unsigned long> *v10; // eax@12
  PSRefBufferCharData<unsigned short> *v11; // eax@16
  PSRefBufferCharData<unsigned short> *v12; // edi@16
  HashBaseData<unsigned long> *v13; // eax@16
  ACCWeenieObject *v14; // ebp@16
  IDList *v15; // eax@20
  IDList *v16; // edi@20
  int v17; // ebp@21
  unsigned int v18; // eax@22
  HashBaseData<unsigned long> *v19; // esi@22
  PSRefBufferCharData<unsigned short> *v20; // ST0C_4@29
  PSRefBufferCharData<unsigned short> *v21; // ST0C_4@34
  PSRefBufferCharData<unsigned short> *v22; // ST0C_4@36
  PSRefBufferCharData<unsigned short> *v23; // ST0C_4@37
  ACCWeenieObject *topContainerObject; // [sp+0h] [bp-98h]@12
  PStringBase<unsigned short> errorText; // [sp+4h] [bp-94h]@16
  StringInfo siError; // [sp+8h] [bp-90h]@38

  result = ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0);
  if ( result )
  {
    if ( !ItemHolder::AttemptToPlaceInContainer_IsItemLegal(i_itemID, 0)
      || !ItemHolder::AttemptToPlaceInContainer_IsContainerLegal(i_itemID, i_topContainerID, 0) )
      return 0;
    v6 = i_preferredContainerID;
    v7 = ClientObjMaintSystem::GetWeenieObject(i_preferredContainerID);
    v8 = v7;
    if ( !v7
      || i_itemID == i_preferredContainerID
      || !((unsigned int)v7[21].hash_next & 1)
      && (!SmartBox::smartbox ? (v9 = 0) : (v9 = SmartBox::smartbox->player_id), i_preferredContainerID != v9)
      || v8[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1
      || (v10 = ClientObjMaintSystem::GetWeenieObject(i_itemID),
          !ItemHolder::CheckHookStatus((ACCWeenieObject *)v10, (ACCWeenieObject *)v8, (int *)&topContainerObject)) )
      v6 = 0;
    if ( i_bAttemptAutoMerge && ItemHolder::AttemptAutoMerge(i_itemID, i_topContainerID, v6) )
      return 1;
    v11 = (PSRefBufferCharData<unsigned short> *)ClientObjMaintSystem::GetWeenieObject(i_itemID);
    v12 = v11;
    errorText.m_charbuffer = v11;
    v13 = ClientObjMaintSystem::GetWeenieObject(i_topContainerID);
    v14 = (ACCWeenieObject *)v13;
    topContainerObject = (ACCWeenieObject *)v13;
    if ( !v12 || !v13 )
      return 0;
    if ( ItemHolder::WillItemFitInContainer(i_itemID, v6) )
      goto LABEL_31;
    v6 = i_topContainerID;
    if ( ItemHolder::WillItemFitInContainer(i_itemID, i_topContainerID) )
      goto LABEL_31;
    v15 = ACCWeenieObject::GetContainedContainersList(v14);
    v16 = v15;
    if ( v15 )
    {
      v17 = 0;
      if ( v15->numIDs > 0 )
      {
        while ( 1 )
        {
          v18 = IDList::GetByNum(v16, v17);
          v19 = ClientObjMaintSystem::GetWeenieObject(v18);
          if ( v19 )
          {
            if ( ItemHolder::WillItemFitInContainer(i_itemID, v19->id) )
              break;
          }
          ++v17;
          if ( v17 >= v16->numIDs )
            goto LABEL_25;
        }
        v6 = v19->id;
        v14 = topContainerObject;
        v12 = errorText.m_charbuffer;
LABEL_31:
        if ( v6 )
        {
          if ( GenItemHolder::splitSize < GenItemHolder::maxSplitSize )
          {
            ACCWeenieObject::UIAttemptSplitToContainer((ACCWeenieObject *)v12, v6, i_place, GenItemHolder::splitSize);
            return 1;
          }
          ACCWeenieObject::UIAttemptPutInContainer((ACCWeenieObject *)v12, v6, i_place);
          return 1;
        }
        goto LABEL_27;
      }
LABEL_25:
      v14 = topContainerObject;
    }
    v12 = errorText.m_charbuffer;
LABEL_27:
    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText);
    if ( ((int (__thiscall *)(ACCWeenieObject *))v14->vfptr[4].__vecDelDtor)(v14) )
    {
      if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v12) )
      {
        v20 = ACCWeenieObject::GetObjectNameWide(
                v14,
                (PStringBase<unsigned short> *)&topContainerObject,
                NAME_APPROPRIATE,
                0)->m_charbuffer;
        PStringBase<unsigned short>::sprintf(&errorText, L"%s can carry no more containers!", v20);
      }
      else
      {
        v21 = ACCWeenieObject::GetObjectNameWide(
                v14,
                (PStringBase<unsigned short> *)&topContainerObject,
                NAME_APPROPRIATE,
                1)->m_charbuffer;
        PStringBase<unsigned short>::sprintf(&errorText, L"%s is completely full!", v21);
      }
    }
    else if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v12) )
    {
      v22 = ACCWeenieObject::GetObjectNameWide(
              v14,
              (PStringBase<unsigned short> *)&topContainerObject,
              NAME_APPROPRIATE,
              0)->m_charbuffer;
      PStringBase<unsigned short>::sprintf(&errorText, L"The %s can fit no more containers!", v22);
    }
    else
    {
      v23 = ACCWeenieObject::GetObjectNameWide(
              v14,
              (PStringBase<unsigned short> *)&topContainerObject,
              NAME_APPROPRIATE,
              0)->m_charbuffer;
      PStringBase<unsigned short>::sprintf(&errorText, L"The %s is completely full!", v23);
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&topContainerObject);
    StringInfo::StringInfo(&siError);
    StringInfo::SetLiteralValue(&siError, &errorText, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    StringInfo::~StringInfo(&siError);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
    return 0;
  }
  return result;
}
// 7E2800: using guessed type wchar_t aTheSCanFitNoMo[35];
// 7E2848: using guessed type wchar_t aSIsCompletelyF[23];
// 7E2878: using guessed type wchar_t aSCanCarryNoMor[33];

//----- (00588400) --------------------------------------------------------  // acclient.c:433051
int __thiscall ACCWeenieObject::IsComponentPack(ACCWeenieObject *this)
{
  ACCWeenieObject *v1; // esi@1
  int v2; // eax@1
  unsigned int v3; // esi@1
  int v4; // ecx@1
  int v5; // eax@1
  bool v6; // zf@1
  int v7; // esi@5

  v1 = this;
  v2 = DBObj::GetByEnum(5, 268435457, 0x28u);
  v3 = v1->pwd._wcid.id;
  v4 = v2;
  v5 = *(_DWORD *)(*(_DWORD *)(v2 + 612) + 4 * (v3 % *(_DWORD *)(v2 + 620)));
  v6 = v5 == 0;
  if ( v5 )
  {
    do
    {
      if ( *(_DWORD *)v5 == v3 )
        break;
      v5 = *(_DWORD *)(v5 + 4);
    }
    while ( v5 );
    v6 = v5 == 0;
  }
  v7 = !v6;
  if ( v4 )
    (*(void (**)(void))(*(_DWORD *)v4 + 20))();
  return v7;
}

//----- (00588460) --------------------------------------------------------  // acclient.c:433085
unsigned __int16 __cdecl ItemHolder::DetermineUseResult(ACCWeenieObject *_weenObj)
{
  ACCWeenieObject *v1; // esi@1
  unsigned int v2; // edi@4
  unsigned int v3; // ecx@5
  unsigned int v4; // eax@7
  int v5; // eax@14
  int v6; // edi@15
  unsigned int v7; // eax@20
  unsigned int v8; // eax@24
  unsigned int v9; // ecx@24
  unsigned int v10; // esi@38
  unsigned int v11; // eax@39

  v1 = _weenObj;
  if ( (_weenObj->pwd._containerID || _weenObj->pwd._bitfield & 4)
    && (!ClientUISystem::GetUISystem()->groundObject
     || (v2 = v1->pwd._containerID, v2 != ClientUISystem::GetUISystem()->groundObject))
    || (v3 = v1->pwd._wielderID) != 0
    && (!SmartBox::smartbox ? (v4 = 0) : (v4 = SmartBox::smartbox->player_id), v3 != v4)
    || ((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v1->pwd._bitfield
     || v1->pwd._itemsCapacity
     || v1->pwd._containersCapacity)
    && !ACCWeenieObject::IsComponentPack(v1) )
  {
    v6 = ((int (__thiscall *)(ACCWeenieObject *))v1->vfptr[6].__vecDelDtor)(v1);
    if ( ACCWeenieObject::IsOwnedByPlayer(v1) )
    {
      if ( v1->pwd._combatUse || v6 & 0x8000 || v1->pwd._bitfield & 0x20000000 )
      {
        v7 = SmartBox::smartbox ? SmartBox::smartbox->player_id : 0;
        if ( v1->pwd._wielderID != v7 )
          return (v1->pwd._bitfield & 0x40000000) != 0 ? 8 : 3;
      }
      v8 = v1->pwd._valid_locations;
      v9 = v1->pwd._location;
      if ( BYTE1(v8) & 0x7E && !(BYTE1(v9) & 0x7E)
        || v8 & 0x80001FF && !(v9 & 0x80001FF)
        || v8 & 0x7C0F8000 && !(v9 & 0x7C0F8000) )
      {
        LOWORD(v5) = 4;
        return v5;
      }
      if ( v6 & 0x20000000 )
      {
        LOWORD(v5) = 6;
        return v5;
      }
    }
    else if ( v6 < 0 )
    {
      LOWORD(v5) = 7;
      return v5;
    }
    ItemUses::ItemUses((ItemUses *)&_weenObj, v1->pwd._useability);
    if ( ItemUses::IsUseable((ItemUses *)&_weenObj) )
    {
      LOWORD(v5) = 1;
    }
    else if ( ((int (__thiscall *)(ACCWeenieObject *))v1->vfptr[4].__vecDelDtor)(v1)
           && ((v10 = v1->id, !SmartBox::smartbox) ? (v11 = 0) : (v11 = SmartBox::smartbox->player_id), v10 != v11) )
    {
      LOWORD(v5) = 5;
    }
    else
    {
      LOWORD(v5) = 0;
    }
  }
  else
  {
    LOWORD(v5) = 2;
  }
  return v5;
}

//----- (00588600) --------------------------------------------------------  // acclient.c:433162
int __cdecl ItemHolder::AttemptPlaceIn3D(unsigned int _objectID, unsigned int _draggedOnID, int _dropIfGiveFails)
{
  int v3; // eax@1
  int v4; // ebp@2
  HashBaseData<unsigned long> *v5; // ebx@2
  unsigned int v6; // eax@4
  CPlayerSystem *v7; // eax@7
  PSRefBufferCharData<unsigned short> *v8; // ST10_4@9
  PSRefBufferCharData<unsigned short> *v9; // ST10_4@14
  HashBaseData<unsigned long> *v10; // eax@17
  HashBaseData<unsigned long> *v11; // esi@17
  HashBaseData<unsigned long> *v12; // eax@18
  ClientUISystem *v13; // eax@20
  CPlayerSystem *v14; // eax@22
  ClientTradeSystem *v15; // eax@24
  unsigned int v16; // eax@26
  PSRefBufferCharData<unsigned short> *v17; // ST10_4@29
  PSRefBufferCharData<unsigned short> *v18; // ST10_4@31
  PStringBase<unsigned short> *v19; // esi@35
  PStringBase<unsigned short> *v20; // eax@35
  unsigned int v21; // eax@38
  HashBaseData<unsigned long> *v22; // eax@38
  PStringBase<unsigned short> errorText; // [sp+0h] [bp-9Ch]@9
  PStringBase<unsigned short> result; // [sp+4h] [bp-98h]@9
  PStringBase<unsigned short> v25; // [sp+8h] [bp-94h]@35
  StringInfo siError; // [sp+Ch] [bp-90h]@10

  v3 = ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0);
  if ( v3 )
  {
    v4 = 0;
    v5 = ClientObjMaintSystem::GetWeenieObject(_objectID);
    if ( !v5 )
      return 0;
    if ( SmartBox::smartbox )
      v6 = SmartBox::smartbox->player_id;
    else
      v6 = 0;
    if ( _draggedOnID == v6 )
    {
      v7 = CPlayerSystem::GetPlayerSystem();
      return (unsigned __int8)CPlayerSystem::PlaceInBackpack(v7, _objectID, 0);
    }
    if ( !ACCWeenieObject::IsOwnedByPlayer((ACCWeenieObject *)v5) )
    {
      v8 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v5, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"You must first pick up the %s", v8);
LABEL_10:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_11:
      StringInfo::~StringInfo(&siError);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      return 0;
    }
    if ( v5[10].vfptr )
    {
      v9 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v5, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &errorText,
        0,
        L"You are trading the %s, it cannot be dropped",
        v9);
LABEL_32:
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
      StringInfo::StringInfo(&siError);
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      goto LABEL_11;
    }
    if ( _draggedOnID )
    {
      v4 = ItemHolder::AttemptMerge(_objectID, _draggedOnID, 0);
      if ( v4 )
        return v4;
      v10 = ClientObjMaintSystem::GetWeenieObject(_draggedOnID);
      v11 = v10;
      if ( v10 )
      {
        v12 = v10[21].hash_next;
        if ( BYTE1(v12) & 2 )
        {
          if ( GenItemHolder::splitSize == GenItemHolder::maxSplitSize )
          {
            v13 = ClientUISystem::GetUISystem();
            ClientUISystem::AttemptSellToVendor(v13, _draggedOnID, _objectID);
            return 0;
          }
          StringInfo::StringInfo(&siError);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &errorText,
            L"You must split the stack before selling it.");
          StringInfo::SetLiteralValue(&siError, &errorText, 1);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          goto LABEL_47;
        }
        v14 = CPlayerSystem::GetPlayerSystem();
        if ( (unsigned __int8)PlayerModule::DragItemOnPlayerOpensSecureTrade((PlayerModule *)&v14->playerModule.vfptr)
          && ((int (__thiscall *)(HashBaseData<unsigned long> *))v11->vfptr[4].__vecDelDtor)(v11) )
        {
          v15 = ClientTradeSystem::GetTradeSystem();
          ClientTradeSystem::AttemptToTradeItem(v15, _draggedOnID, _objectID);
          return 0;
        }
        if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v11->vfptr[6].__vecDelDtor)(v11) == 16 )
        {
          v16 = ItemHolder::GetObjectSplitSize((ACCWeenieObject *)v5);
          ACCWeenieObject::UIAttemptGive((ACCWeenieObject *)v5, _draggedOnID, v16);
          return 1;
        }
        if ( ACCWeenieObject::IsContainer((ACCWeenieObject *)v11) )
        {
          if ( !((unsigned int)v11[21].hash_next & 1) )
          {
            v17 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
            PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"The %s is locked", v17);
            goto LABEL_10;
          }
          if ( ClientUISystem::GetUISystem()->groundObject != _draggedOnID )
          {
            v18 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
            PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"You must open the %s first", v18);
            goto LABEL_32;
          }
          v4 = ItemHolder::AttemptToPlaceInContainer(_objectID, _draggedOnID, 0, 1, 0);
        }
        if ( !_dropIfGiveFails )
        {
          v19 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v11, &v25, NAME_APPROPRIATE, 0);
          v20 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v5, &result, NAME_APPROPRIATE, 0);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            &errorText,
            0,
            L"Cannot give %s to %s",
            v20->m_charbuffer,
            v19->m_charbuffer);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v25);
          StringInfo::StringInfo(&siError);
          StringInfo::SetLiteralValue(&siError, &errorText, 1);
          ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
          goto LABEL_11;
        }
      }
      if ( v4 )
        return v4;
    }
    if ( !_dropIfGiveFails )
      return v4;
    v21 = GetPlayerID();
    v22 = ClientObjMaintSystem::GetPhysicsObject(v21);
    if ( !v22 || !CPhysicsObj::on_ground((CPhysicsObj *)v22) )
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"You cannot do that in mid air");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_47:
      StringInfo::~StringInfo(&siError);
      return 0;
    }
    if ( GenItemHolder::splitSize < GenItemHolder::maxSplitSize )
    {
      ACCWeenieObject::UIAttemptSplitTo3D((ACCWeenieObject *)v5, GenItemHolder::splitSize);
      return 1;
    }
    if ( v5[8].id )
    {
      ACCWeenieObject::UIAttemptPutIn3D((ACCWeenieObject *)v5);
      v3 = 1;
    }
    else
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, L"Move cancelled");
      StringInfo::SetLiteralValue(&siError, &errorText, 1);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
      StringInfo::~StringInfo(&siError);
      v3 = v4;
    }
  }
  return v3;
}
// 7E29D8: using guessed type wchar_t aYouAreTradingT[45];

//----- (00588A80) --------------------------------------------------------  // acclient.c:433353
void __cdecl ItemHolder::UseObject(unsigned int _itemID, int _targetIsSelected, int _forceUse)
{
  HashBaseData<unsigned long> *v3; // esi@2
  HashBaseData<unsigned long>Vtbl *v4; // ebx@6
  signed int v5; // ebx@7
  signed int v6; // eax@8
  PSRefBufferCharData<unsigned short> *v7; // ST0C_4@13
  PSRefBufferCharData<unsigned short> *v8; // ST0C_4@18
  unsigned int v9; // ebx@21
  PStringBase<unsigned short> *v10; // eax@22
  ClientUISystem *v11; // eax@24
  CPlayerSystem *v12; // eax@25
  ClientUISystem *v13; // eax@26
  PSRefBufferCharData<unsigned short> *v14; // ST0C_4@26
  HashBaseData<unsigned long> *v15; // eax@28
  CPlayerSystem *v16; // eax@33
  ClientUISystem *v17; // eax@35
  CPlayerSystem *v18; // eax@35
  PSRefBufferCharData<unsigned short> *v19; // ST0C_4@36
  PSRefBufferCharData<unsigned short> *v20; // ST0C_4@37
  CPlayerSystem *v21; // eax@38
  HashBaseData<unsigned long> *v22; // eax@39
  PStringBase<unsigned short> *v23; // eax@40
  PSRefBufferCharData<unsigned short> *v24; // ST0C_4@44
  PSRefBufferCharData<unsigned short> *v25; // ST0C_4@47
  PStringBase<unsigned short> errorText; // [sp+8h] [bp-9Ch]@13
  PStringBase<unsigned short> result; // [sp+Ch] [bp-98h]@13
  ItemUses uses; // [sp+10h] [bp-94h]@11
  StringInfo siError; // [sp+14h] [bp-90h]@14

  if ( ClientUISystem::GetUISystem() )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(_itemID);
    if ( v3 )
    {
      if ( COERCE_DOUBLE(Timer::cur_time.Cmd) >= ItemHolder::m_timeLastUsed + 0.2 )
      {
        ItemHolder::m_timeLastUsed = *(double *)&Timer::cur_time;
        if ( ACCWeenieObject::IsPlayerReadyToMakeInventoryRequest(0) )
        {
          if ( !ClientUISystem::GetUISystem()->vendorID
            || (v4 = v3[15].vfptr, v4 != (HashBaseData<unsigned long>Vtbl *)ClientUISystem::GetUISystem()->vendorID) )
          {
            v5 = 0;
            if ( !_forceUse )
            {
              v6 = ItemHolder::DetermineUseResult((ACCWeenieObject *)v3);
              if ( (signed int)(unsigned __int16)v6 >= 2 && v6 <= 7 )
                v5 = 1;
            }
            ItemUses::ItemUses(&uses, (const unsigned int)v3[18].vfptr);
            if ( v5 )
              goto LABEL_25;
            if ( v3[10].vfptr == (HashBaseData<unsigned long>Vtbl *)1 )
            {
              v7 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &errorText,
                0,
                L"You cannot use the %s because you are trading it",
                v7);
LABEL_14:
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
              StringInfo::StringInfo(&siError);
              StringInfo::SetLiteralValue(&siError, &errorText, 1);
              ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_15:
              StringInfo::~StringInfo(&siError);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&errorText);
              return;
            }
            if ( !v3[16].hash_next && ItemUses::GetLeastLimitedSourceUse(&uses) & 4 )
            {
              v8 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                &errorText,
                0,
                L"You must wield the %s to use it",
                v8);
              goto LABEL_48;
            }
            if ( ItemUses::IsUseable_Targeted(&uses) )
            {
              if ( !_targetIsSelected )
              {
                ItemHolder::targetingObject = _itemID;
                v13 = ClientUISystem::GetUISystem();
                ClientUISystem::SetTargetMode(v13, TARGET_MODE_USE_TARGET);
                v14 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  &errorText,
                  0,
                  L"Choose a target for the %s",
                  v14);
                goto LABEL_14;
              }
              v9 = ACCWeenieObject::selectedID;
              if ( ACCWeenieObject::selectedID == Formatted )
              {
                v10 = ACCWeenieObject::GetObjectNameWide(
                        (ACCWeenieObject *)v3,
                        &result,
                        NAME_APPROPRIATE,
                        ACCWeenieObject::selectedID);
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  &errorText,
                  (_Formatted)v9,
                  L"Select your target before using the %s",
                  v10->m_charbuffer);
                PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
                StringInfo::StringInfo(&siError);
                StringInfo::SetLiteralValue(&siError, &errorText, 1);
LABEL_41:
                ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
                goto LABEL_15;
              }
              if ( ItemHolder::TargetCompatibleWithObject(ACCWeenieObject::selectedID, _itemID, 0, 1) )
              {
                CM_Inventory::Event_UseWithTargetEvent(_itemID, v9);
                v11 = ClientUISystem::GetUISystem();
                ClientUISystem::IncrementBusyCount(v11);
LABEL_25:
                v12 = CPlayerSystem::GetPlayerSystem();
                CPlayerSystem::UsingItem(v12, _itemID, 1, _forceUse);
                return;
              }
            }
            else if ( ItemUses::IsUseable(&uses) )
            {
              v15 = v3[21].hash_next;
              if ( BYTE1(v15) & 4 )
              {
                ClientUISystem::GetUISystem();
                ClientUISystem::UsageConfirmation_PKAltar(_itemID);
              }
              else if ( BYTE1(v15) & 8 )
              {
                ClientUISystem::GetUISystem();
                ClientUISystem::UsageConfirmation_NPKAltar(_itemID);
              }
              else
              {
                if ( !((unsigned int)v15 & 0x10000000)
                  || (v16 = CPlayerSystem::GetPlayerSystem(),
                      !(unsigned __int8)PlayerModule::ConfirmVolatileRareUse((PlayerModule *)&v16->playerModule.vfptr)) )
                {
                  CM_Inventory::Event_UseEvent(_itemID);
                  v17 = ClientUISystem::GetUISystem();
                  ClientUISystem::IncrementBusyCount(v17);
                  v18 = CPlayerSystem::GetPlayerSystem();
                  CPlayerSystem::UsingItem(v18, _itemID, 1, _forceUse);
                  if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[6].__vecDelDtor)(v3) & 0x10 )
                  {
                    v19 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
                    PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Approaching %s", v19);
                    goto LABEL_14;
                  }
                  v20 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"Using the %s", v20);
LABEL_48:
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
                  StringInfo::StringInfo(&siError);
                  StringInfo::SetLiteralValue(&siError, &errorText, 1);
                  ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
                  goto LABEL_15;
                }
                ClientUISystem::GetUISystem();
                ClientUISystem::UsageConfirmation_VolatileRare(_itemID);
              }
            }
            else
            {
              v21 = CPlayerSystem::GetPlayerSystem();
              CPlayerSystem::UsingItem(v21, _itemID, 0, _forceUse);
              if ( _itemID != GetPlayerID() )
              {
                v22 = v3[21].hash_next;
                if ( BYTE1(v22) & 0x10 )
                {
                  v23 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0);
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &errorText,
                    0,
                    L"You can't open or close this %s that way",
                    v23->m_charbuffer);
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
                  StringInfo::StringInfo(&siError);
                  StringInfo::SetLiteralValue(&siError, &errorText, 1);
                  goto LABEL_41;
                }
                ClientCombatSystem::GetCombatSystem();
                if ( ClientCombatSystem::ObjectIsAttackable(_itemID)
                  && ClientCombatSystem::GetCombatSystem()->combatMode == 1 )
                {
                  v24 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
                  PStringBase<unsigned short>::PStringBase<unsigned short>(
                    &errorText,
                    0,
                    L"To attack %s, click on the dove icon first",
                    v24);
                  goto LABEL_14;
                }
                ClientCombatSystem::GetCombatSystem();
                if ( !ClientCombatSystem::ObjectIsAttackable(_itemID)
                  || ClientCombatSystem::GetCombatSystem()->combatMode == 1 )
                {
                  v25 = ACCWeenieObject::GetObjectNameWide((ACCWeenieObject *)v3, &result, NAME_APPROPRIATE, 0)->m_charbuffer;
                  PStringBase<unsigned short>::PStringBase<unsigned short>(&errorText, 0, L"The %s cannot be used", v25);
                  goto LABEL_48;
                }
              }
            }
          }
        }
      }
    }
  }
}
// 7E2AA0: using guessed type wchar_t aToAttackSClick[43];
// 7E2B4C: using guessed type wchar_t aApproachingS[15];
// 7E2B6C: using guessed type wchar_t aChooseATargetF[27];
// 870AD8: using guessed type double ItemHolder::m_timeLastUsed;

//----- (00588EF0) --------------------------------------------------------  // acclient.c:433577
void __cdecl ItemHolder::TargetAcquired(unsigned int _targetID)
{
  unsigned int v1; // esi@1
  unsigned int v2; // ST0C_4@1
  HashBaseData<unsigned long> *v3; // edi@2
  HashBaseData<unsigned long> *v4; // eax@2
  HashBaseData<unsigned long> *v5; // ebx@2
  ClientSystem *v6; // eax@7
  CPlayerSystem *v7; // eax@9
  ClientUISystem *v8; // eax@13
  CPlayerSystem *v9; // eax@13

  v1 = ItemHolder::targetingObject;
  v2 = ItemHolder::targetingObject;
  ItemHolder::targetingObject = 0;
  if ( ItemHolder::TargetCompatibleWithObject(_targetID, v2, 0, 1) )
  {
    v3 = ClientObjMaintSystem::GetWeenieObject(v1);
    v4 = ClientObjMaintSystem::GetWeenieObject(_targetID);
    v5 = v4;
    if ( v3 && v4 )
    {
      if ( ((int (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[6].__vecDelDtor)(v3) & 0x80000
        && !((unsigned int)v3[19].vfptr & 1) )
      {
        if ( BYTE3(v5[21].hash_next) & 1 )
        {
          v6 = (ClientSystem *)ClientUISystem::GetUISystem();
          ClientSystem::AddTextToScroll(
            v6,
            "You cannot drain the mana of this item because it is \"Retained\".\n",
            0,
            1,
            0);
        }
        else
        {
          ClientUISystem::GetUISystem();
          ClientUISystem::TargetedUsageConfirmation_ManaStone(v1, _targetID);
        }
        return;
      }
      v7 = CPlayerSystem::GetPlayerSystem();
      if ( !(unsigned __int8)PlayerModule::UseCraftSuccessDialog((PlayerModule *)&v7->playerModule.vfptr)
        && ((int (__thiscall *)(_DWORD))v3->vfptr[6].__vecDelDtor)(v3) & 0x40000000 )
      {
        ClientUISystem::GetUISystem();
        ClientUISystem::TargetedUsageConfirmation_Salvage(v1, _targetID);
        return;
      }
      ((void (__thiscall *)(HashBaseData<unsigned long> *))v3->vfptr[6].__vecDelDtor)(v3);
    }
    CM_Inventory::Event_UseWithTargetEvent(v1, _targetID);
    v8 = ClientUISystem::GetUISystem();
    ClientUISystem::IncrementBusyCount(v8);
    v9 = CPlayerSystem::GetPlayerSystem();
    CPlayerSystem::UsingItem(v9, v1, 1, 0);
  }
}

//----- (00709C60) --------------------------------------------------------  // acclient.c:797012
void _E94_28()
{
  flt_870AFC = 1000.0 + 1.0;
}

//----- (00709C80) --------------------------------------------------------  // acclient.c:797018
void _E96_0()
{
  flt_870B00 = 24.0 * 8.0;
}

//----- (00709CA0) --------------------------------------------------------  // acclient.c:797024
void _E98_15()
{
  flt_870B04 = 24.0 * 0.5;
}

//----- (00709CC0) --------------------------------------------------------  // acclient.c:797030
int sub_709CC0()
{
  return atexit(nullsub_1380);
}

//----- (00709CD0) --------------------------------------------------------  // acclient.c:797036
int sub_709CD0()
{
  return atexit(nullsub_1381);
}

//----- (00709CE0) --------------------------------------------------------  // acclient.c:797042
int sub_709CE0()
{
  return atexit(_E107_95);
}

//----- (00709CF0) --------------------------------------------------------  // acclient.c:797048
void _E109_74()
{
  flt_870B08 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709D10) --------------------------------------------------------  // acclient.c:797054
void _E111_49()
{
  dbl_870B10 = 1.0 / 30.0;
}

//----- (00709D30) --------------------------------------------------------  // acclient.c:797060
void _E113_26()
{
  dbl_870B18 = 1.0 / 5.0;
}

//----- (00709D50) --------------------------------------------------------  // acclient.c:797066
void _E115_80()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870B20, PFID_A8R8G8B8);
}

//----- (00709D60) --------------------------------------------------------  // acclient.c:797072
void _E118_76()
{
  dword_870B58 = 1024;
}

//----- (00709D70) --------------------------------------------------------  // acclient.c:797078
void _E120_68()
{
  dword_870B5C = 0x7FFF;
}

//----- (00709D80) --------------------------------------------------------  // acclient.c:797084
int _E122_32()
{
  const int result; // eax@1

  result = dword_870B58;
  dword_870B60 = dword_870B58;
  return result;
}

//----- (00709D90) --------------------------------------------------------  // acclient.c:797094
int _E124_67()
{
  return atexit(_E125_64);
}

//----- (00709DA0) --------------------------------------------------------  // acclient.c:797100
int sub_709DA0()
{
  return atexit(nullsub_1379);
}

