/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIOption
   Object     : GAME\game_ui_misc\UIOption.obj
   Functions  : 30
   Addresses  : 004EF1E0 - 006F7B20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EF1E0) --------------------------------------------------------  // acclient.c:283431
void __thiscall UIOption::UIOption(UIOption *this)
{
  UIOption *v1; // esi@1
  GlobalEventHandler *v2; // eax@1
  GlobalEventHandler *v3; // edi@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption::vftable;
  this->m_confirmChange = 0;
  this->m_bDelayConfirmation = 0;
  this->m_dialogContext = 0;
  this->m_shouldReloadOptions = 0;
  this->m_shouldRefreshOptionsPanel = 0;
  this->m_noticeFuncPtr = 0;
  this->m_pOCH = 0;
  this->m_nUserData = 0;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  v3 = v2;
  if ( v2 )
  {
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100004u, (NoticeHandler *)v1);
    v3->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v3,
      (unsigned int)((char *)&loc_4DD216 + 1),
      (NoticeHandler *)v1);
    v3->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v3, (unsigned int)&loc_4DD216, (NoticeHandler *)v1);
  }
}
// 7C3870: using guessed type bool (__thiscall *UIOption::vftable)(DBCache *this);

//----- (004EF240) --------------------------------------------------------  // acclient.c:283462
void __thiscall UIOption::~UIOption(UIOption *this)
{
  NoticeHandler *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = (NoticeHandler *)this;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption::vftable;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v2, v1);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v1);
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3870: using guessed type bool (__thiscall *UIOption::vftable)(DBCache *this);

//----- (004EF270) --------------------------------------------------------  // acclient.c:283479
void __thiscall UIOption::SetLabel(UIOption *this, unsigned int _stringID, unsigned int _tableID)
{
  UIOption *v3; // esi@1
  StringInfo v4; // [sp+4h] [bp-90h]@1

  v3 = this;
  StringInfo::StringInfo(&v4);
  StringInfo::SetStringIDandTableEnum(&v4, _stringID, _tableID);
  ((void (__thiscall *)(UIOption *, StringInfo *))v3->vfptr[7].RecvNotice_ItemAttributesChanged)(v3, &v4);
  StringInfo::~StringInfo(&v4);
}

//----- (004EF2C0) --------------------------------------------------------  // acclient.c:283492
void __thiscall UIOption::SetTooltip(UIOption *this, unsigned int _stringID, unsigned int _tableID)
{
  UIOption *v3; // esi@1
  StringInfo v4; // [sp+4h] [bp-90h]@1

  v3 = this;
  StringInfo::StringInfo(&v4);
  StringInfo::SetStringIDandTableEnum(&v4, _stringID, _tableID);
  v3->vfptr[7].RecvNotice_ServerSaysAttemptFailed((NoticeHandler *)v3, (unsigned int)&v4);
  StringInfo::~StringInfo(&v4);
}

//----- (004EF310) --------------------------------------------------------  // acclient.c:283505
void __thiscall UIOption::SetConfirmChange(UIOption *this, bool bDelayConfirmation)
{
  this->m_confirmChange = 1;
  this->m_bDelayConfirmation = bDelayConfirmation;
}

//----- (004EF320) --------------------------------------------------------  // acclient.c:283512
void __thiscall UIOption::SetChangeNotification(UIOption *this, IOptionChangeHandler *i_pOCH)
{
  this->m_pOCH = i_pOCH;
}

//----- (004EF330) --------------------------------------------------------  // acclient.c:283518
void __thiscall UIOption::SetUserData(UIOption *this, unsigned int i_nUserData)
{
  this->m_nUserData = i_nUserData;
}

//----- (004EF340) --------------------------------------------------------  // acclient.c:283524
NoticeHandler *__thiscall UIOption::scalar_deleting_destructor(UIOption *this, unsigned int a2)
{
  NoticeHandler *v2; // esi@1
  GlobalEventHandler *v3; // eax@1

  v2 = (NoticeHandler *)this;
  this->vfptr = (NoticeHandlerVtbl *)&UIOption::vftable;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, v2);
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7C3870: using guessed type bool (__thiscall *UIOption::vftable)(DBCache *this);

//----- (004EF380) --------------------------------------------------------  // acclient.c:283544
bool __thiscall DBObjGrabber<DBPropertyCollection>::set(DBObjGrabber<DBPropertyCollection> *this, IDClass<_tagDataID,32,0> _did)
{
  DBObjGrabber<DBPropertyCollection> *v2; // edi@1
  char *v3; // esi@2
  QualifiedDataID *v4; // eax@4
  int v5; // eax@4
  int v6; // eax@5
  QualifiedDataID v8; // [sp+8h] [bp-8h]@4

  v2 = this;
  if ( this->m_object )
    v3 = (char *)&this->m_object->vfptr;
  else
    v3 = 0;
  QualifiedDataID::QualifiedDataID(&v8, _did, 0x31u);
  v5 = DBObj::Get(v4);
  if ( v5 )
    v6 = v5 - 120;
  else
    v6 = 0;
  v2->m_object = (DBPropertyCollection *)v6;
  if ( v3 )
    (*(void (__thiscall **)(char *))(*(_DWORD *)v3 + 20))(v3);
  return v2->m_object != 0;
}

//----- (004EF3E0) --------------------------------------------------------  // acclient.c:283571
void __thiscall UIOption::RecvNotice_CloseDialog(UIOption *this, unsigned int _context, PropertyCollection *_data)
{
  UIOption *v3; // edi@1
  unsigned int v4; // edx@2
  HashTableData<unsigned long,BaseProperty> **v5; // eax@2
  BasePropertyValue *v6; // ecx@2
  HashTableData<unsigned long,BaseProperty> *v7; // eax@2
  bool v8; // zf@9
  IOptionChangeHandler *v9; // eax@11
  BasePropertyDesc *v10; // ecx@14
  unsigned int v11; // edx@14
  int v12; // edx@18
  BaseProperty p; // [sp+10h] [bp-8h]@2

  v3 = this;
  if ( this->m_dialogContext == _context )
  {
    v4 = 0x92 % _data->m_hashProperties.m_intrusiveTable.m_numBuckets;
    v5 = _data->m_hashProperties.m_intrusiveTable.m_buckets;
    v6 = 0;
    LOBYTE(_context) = 0;
    p.m_pcPropertyDesc = 0;
    p.m_pcPropertyValue = 0;
    v7 = v5[v4];
    if ( v7 )
    {
      while ( v7->m_hashKey != 146 )
      {
        v7 = v7->m_hashNext;
        if ( !v7 )
          goto LABEL_9;
      }
      if ( v7 )
      {
        BaseProperty::operator=(&p, (int)&v7->m_data);
        v6 = p.m_pcPropertyValue;
        if ( p.m_pcPropertyValue )
        {
          ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&_context);
          v6 = p.m_pcPropertyValue;
        }
      }
    }
LABEL_9:
    v8 = (_BYTE)_context == 0;
    v3->m_dialogContext = 0;
    if ( v8 )
    {
      ((void (__thiscall *)(UIOption *))v3->vfptr[7].RecvNotice_CharacterError)(v3);
      v6 = p.m_pcPropertyValue;
    }
    v9 = v3->m_pOCH;
    if ( v9 )
    {
      v9->vfptr->OnOptionChangeConfirmed(v9, v3, _context);
      v6 = p.m_pcPropertyValue;
    }
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v10 = p.m_pcPropertyDesc;
      v11 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v11;
      if ( !v11 )
        ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
      v6 = p.m_pcPropertyValue;
      p.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v12 = v6->m_cRef - 1;
      v6->m_cRef = v12;
      if ( !v12 )
        ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
    }
  }
}

//----- (004EF4D0) --------------------------------------------------------  // acclient.c:283649
char __stdcall UIOption::InqGameplayOptionProperty(unsigned int _propName, BaseProperty *_baseProp)
{
  DBPropertyCollection *v3; // edi@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@2
  BasePropertyValue *v6; // ecx@7
  BasePropertyValue *v7; // eax@9
  unsigned int v8; // esi@9
  char v9; // al@13
  BasePropertyValue *v10; // ecx@13
  BasePropertyDesc *v11; // ecx@18
  unsigned int v12; // edx@18
  int v13; // edx@22
  BasePropertyDesc *v14; // ecx@29
  unsigned int v15; // edx@29
  unsigned int v16; // esi@33
  BasePropertyDesc *v17; // ecx@38
  unsigned int v18; // edx@38
  int v19; // edx@42
  DBObjGrabber<DBPropertyCollection> optionListCollection; // [sp+28h] [bp-28h]@1
  unsigned int numOptionProperties; // [sp+2Ch] [bp-24h]@7
  IDClass<_tagDataID,32,0> optionInfoDID; // [sp+30h] [bp-20h]@1
  unsigned int optionPropEnum; // [sp+34h] [bp-1Ch]@15
  BaseProperty optionListProp; // [sp+38h] [bp-18h]@2
  BaseProperty optionStructProp; // [sp+40h] [bp-10h]@9
  BaseProperty enumProp; // [sp+48h] [bp-8h]@12

  DBCache::GetDIDFromEnumStatic(&optionInfoDID, 21, 2);
  optionListCollection.m_object = 0;
  DBObjGrabber<DBPropertyCollection>::set(&optionListCollection, optionInfoDID);
  v3 = optionListCollection.m_object;
  if ( optionListCollection.m_object )
  {
    optionListProp.m_pcPropertyDesc = 0;
    optionListProp.m_pcPropertyValue = 0;
    v4 = optionListCollection.m_object->m_hashProperties.m_intrusiveTable.m_buckets[0xD2
                                                                                  % optionListCollection.m_object->m_hashProperties.m_intrusiveTable.m_numBuckets];
    if ( !v4 )
      goto LABEL_5;
    while ( v4->m_hashKey != 210 )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
        goto LABEL_5;
    }
    if ( !v4 )
    {
LABEL_5:
      optionListCollection.m_object->vfptr->Release((Interface *)&optionListCollection.m_object->vfptr);
      return 0;
    }
    BaseProperty::operator=(&optionListProp, (int)&v4->m_data);
    v6 = optionListProp.m_pcPropertyValue;
    numOptionProperties = 0;
    if ( optionListProp.m_pcPropertyValue )
    {
      ((void (__stdcall *)(unsigned int *))optionListProp.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&numOptionProperties);
      v6 = optionListProp.m_pcPropertyValue;
    }
    v7 = 0;
    v8 = 0;
    optionStructProp.m_pcPropertyDesc = 0;
    optionStructProp.m_pcPropertyValue = 0;
    if ( numOptionProperties > 0 )
    {
      while ( !v6 )
      {
LABEL_27:
        ++v8;
        if ( v8 >= numOptionProperties )
        {
          if ( (_DWORD)optionStructProp.m_pcPropertyDesc )
          {
            v14 = optionStructProp.m_pcPropertyDesc;
            v15 = optionStructProp.m_pcPropertyDesc->m_cRef - 1;
            optionStructProp.m_pcPropertyDesc->m_cRef = v15;
            if ( !v15 )
              ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
            v6 = optionListProp.m_pcPropertyValue;
            v7 = optionStructProp.m_pcPropertyValue;
            optionStructProp.m_pcPropertyDesc = 0;
          }
          if ( v7 )
          {
            v16 = v7->m_cRef;
            v7->m_cRef = v16 - 1;
            if ( v16 == 1 )
              ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
            v6 = optionListProp.m_pcPropertyValue;
            optionStructProp.m_pcPropertyValue = 0;
          }
          v3 = optionListCollection.m_object;
          goto LABEL_37;
        }
      }
      if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v6->vfptr[61].__vecDelDtor)(
                              v8,
                              &optionStructProp) )
      {
        v7 = optionStructProp.m_pcPropertyValue;
        enumProp.m_pcPropertyDesc = 0;
        enumProp.m_pcPropertyValue = 0;
        if ( !optionStructProp.m_pcPropertyValue )
        {
LABEL_26:
          v6 = optionListProp.m_pcPropertyValue;
          goto LABEL_27;
        }
        v9 = ((int (__thiscall *)(BasePropertyValue *, signed int, BaseProperty *))optionStructProp.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
               optionStructProp.m_pcPropertyValue,
               214,
               &enumProp);
        v10 = enumProp.m_pcPropertyValue;
        if ( v9 )
        {
          if ( enumProp.m_pcPropertyValue )
          {
            ((void (__stdcall *)(unsigned int *))enumProp.m_pcPropertyValue->vfptr[42].__vecDelDtor)(&optionPropEnum);
            v10 = enumProp.m_pcPropertyValue;
          }
          if ( optionPropEnum == _propName )
          {
            BaseProperty::operator=(_baseProp, (int)&optionStructProp);
            BaseProperty::~BaseProperty(&enumProp);
            BaseProperty::~BaseProperty(&optionStructProp);
            BaseProperty::~BaseProperty(&optionListProp);
            optionListCollection.m_object->vfptr->Release((Interface *)&optionListCollection.m_object->vfptr);
            return 1;
          }
        }
        if ( (_DWORD)enumProp.m_pcPropertyDesc )
        {
          v11 = enumProp.m_pcPropertyDesc;
          v12 = enumProp.m_pcPropertyDesc->m_cRef - 1;
          enumProp.m_pcPropertyDesc->m_cRef = v12;
          if ( !v12 )
            ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
          v10 = enumProp.m_pcPropertyValue;
          enumProp.m_pcPropertyDesc = 0;
        }
        if ( v10 )
        {
          v13 = v10->m_cRef - 1;
          v10->m_cRef = v13;
          if ( !v13 )
            ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
          enumProp.m_pcPropertyValue = 0;
        }
      }
      v7 = optionStructProp.m_pcPropertyValue;
      goto LABEL_26;
    }
LABEL_37:
    if ( (_DWORD)optionListProp.m_pcPropertyDesc )
    {
      v17 = optionListProp.m_pcPropertyDesc;
      v18 = optionListProp.m_pcPropertyDesc->m_cRef - 1;
      optionListProp.m_pcPropertyDesc->m_cRef = v18;
      if ( !v18 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
      v6 = optionListProp.m_pcPropertyValue;
      optionListProp.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v19 = v6->m_cRef - 1;
      v6->m_cRef = v19;
      if ( !v19 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
      optionListProp.m_pcPropertyValue = 0;
    }
    v3->vfptr->Release((Interface *)&v3->vfptr);
  }
  return 0;
}

//----- (004EF750) --------------------------------------------------------  // acclient.c:283825
bool __stdcall UIOption::InqGameplayOptionNameAndTooltip(unsigned int _propName, StringInfo *_siName, StringInfo *_siTooltip)
{
  BasePropertyDesc *v4; // ecx@3
  unsigned int v5; // edx@3
  BasePropertyValue *v6; // ecx@7
  unsigned int v7; // edx@7
  bool result; // al@9
  BasePropertyValue *v9; // ecx@10
  char v10; // al@11
  char v11; // al@16
  BasePropertyDesc *v12; // ecx@21
  unsigned int v13; // edx@21
  int v14; // edx@25
  BasePropertyDesc *v15; // ecx@29
  unsigned int v16; // edx@29
  BasePropertyValue *v17; // ecx@33
  unsigned int v18; // edx@33
  bool retval; // [sp+11h] [bp-11h]@1
  BaseProperty prop; // [sp+12h] [bp-10h]@10
  BaseProperty baseProp; // [sp+1Ah] [bp-8h]@1

  retval = 1;
  baseProp.m_pcPropertyDesc = 0;
  baseProp.m_pcPropertyValue = 0;
  if ( UIOption::InqGameplayOptionProperty(_propName, &baseProp) )
  {
    v9 = 0;
    prop.m_pcPropertyDesc = 0;
    prop.m_pcPropertyValue = 0;
    if ( baseProp.m_pcPropertyValue
      && (v10 = ((int (__thiscall *)(BasePropertyValue *, signed int, BaseProperty *))baseProp.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                  baseProp.m_pcPropertyValue,
                  212,
                  &prop),
          v9 = prop.m_pcPropertyValue,
          v10) )
    {
      if ( prop.m_pcPropertyValue )
      {
        ((void (__stdcall *)(StringInfo *))prop.m_pcPropertyValue->vfptr[48].__vecDelDtor)(_siName);
        v9 = prop.m_pcPropertyValue;
      }
    }
    else
    {
      retval = 0;
    }
    if ( baseProp.m_pcPropertyValue
      && (v11 = ((int (__thiscall *)(BasePropertyValue *, signed int, BaseProperty *))baseProp.m_pcPropertyValue->vfptr[70].__vecDelDtor)(
                  baseProp.m_pcPropertyValue,
                  213,
                  &prop),
          v9 = prop.m_pcPropertyValue,
          v11) )
    {
      if ( prop.m_pcPropertyValue )
      {
        ((void (__stdcall *)(StringInfo *))prop.m_pcPropertyValue->vfptr[48].__vecDelDtor)(_siTooltip);
        v9 = prop.m_pcPropertyValue;
      }
    }
    else
    {
      retval = 0;
    }
    if ( (_DWORD)prop.m_pcPropertyDesc )
    {
      v12 = prop.m_pcPropertyDesc;
      v13 = prop.m_pcPropertyDesc->m_cRef - 1;
      prop.m_pcPropertyDesc->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      v9 = prop.m_pcPropertyValue;
      prop.m_pcPropertyDesc = 0;
    }
    if ( v9 )
    {
      v14 = v9->m_cRef - 1;
      v9->m_cRef = v14;
      if ( !v14 )
        ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      prop.m_pcPropertyValue = 0;
    }
    if ( (_DWORD)baseProp.m_pcPropertyDesc )
    {
      v15 = baseProp.m_pcPropertyDesc;
      v16 = baseProp.m_pcPropertyDesc->m_cRef - 1;
      baseProp.m_pcPropertyDesc->m_cRef = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      baseProp.m_pcPropertyDesc = 0;
    }
    if ( baseProp.m_pcPropertyValue )
    {
      v17 = baseProp.m_pcPropertyValue;
      v18 = baseProp.m_pcPropertyValue->m_cRef - 1;
      baseProp.m_pcPropertyValue->m_cRef = v18;
      if ( !v18 )
        ((void (__stdcall *)(signed int))v17->vfptr->__vecDelDtor)(1);
    }
    result = retval;
  }
  else
  {
    if ( (_DWORD)baseProp.m_pcPropertyDesc )
    {
      v4 = baseProp.m_pcPropertyDesc;
      v5 = baseProp.m_pcPropertyDesc->m_cRef - 1;
      baseProp.m_pcPropertyDesc->m_cRef = v5;
      if ( !v5 )
        ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
      baseProp.m_pcPropertyDesc = 0;
    }
    if ( baseProp.m_pcPropertyValue )
    {
      v6 = baseProp.m_pcPropertyValue;
      v7 = baseProp.m_pcPropertyValue->m_cRef - 1;
      baseProp.m_pcPropertyValue->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
    }
    result = 0;
  }
  return result;
}

//----- (004EF8D0) --------------------------------------------------------  // acclient.c:283952
char __stdcall UIOption::InqDefaultGameplayOptionProperty(unsigned int _propName, BaseProperty *_baseProp)
{
  DBPropertyCollection *v3; // esi@1
  char result; // al@2
  char v5; // bl@3
  DBObjGrabber<DBPropertyCollection> optionListCollection; // [sp+4h] [bp-8h]@1
  IDClass<_tagDataID,32,0> optionInfoDID; // [sp+8h] [bp-4h]@1

  DBCache::GetDIDFromEnumStatic(&optionInfoDID, 22, 2);
  optionListCollection.m_object = 0;
  DBObjGrabber<DBPropertyCollection>::set(&optionListCollection, optionInfoDID);
  v3 = optionListCollection.m_object;
  if ( optionListCollection.m_object )
  {
    v5 = HashTable<unsigned long,BaseProperty,1>::find(
           (HashTable<unsigned long,BaseProperty,1> *)&optionListCollection.m_object->m_hashProperties.vfptr,
           &_propName,
           _baseProp);
    v3->vfptr->Release((Interface *)&v3->vfptr);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004EF940) --------------------------------------------------------  // acclient.c:283981
void __thiscall UIOption::HandleDialog(UIOption *this)
{
  UIOption *v1; // esi@1
  unsigned int v2; // eax@5
  BasePropertyDesc *v3; // ecx@12
  unsigned int v4; // edx@12
  BasePropertyValue *v5; // ecx@16
  unsigned int v6; // esi@16
  BaseProperty p; // [sp+18h] [bp-114h]@1
  unsigned int _key; // [sp+20h] [bp-10Ch]@3
  PropertyCollection pc; // [sp+24h] [bp-108h]@1
  StringInfo info; // [sp+9Ch] [bp-90h]@5

  v1 = this;
  PropertyCollection::PropertyCollection(&pc);
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  BaseProperty::SetPropertyName(&p, 0x8Eu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC3u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  StringInfo::StringInfo(&info);
  v2 = compute_str_hash("ID_Option_ConfirmChange");
  StringInfo::SetStringIDandTableEnum(&info, v2, 268435460);
  BaseProperty::SetPropertyName(&p, 0xC5u);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&info);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xC6u);
  _key = LODWORD(DIALOG_CONFIRM_TIME);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[35].__vecDelDtor)(_key);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  BaseProperty::SetPropertyName(&p, 0xACu);
  if ( p.m_pcPropertyValue )
  {
    BaseProperty::CheckCopyOnWrite(&p);
    ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[29].__vecDelDtor)(1);
  }
  _key = (unsigned int)BaseProperty::GetPropertyName(&p);
  HashTable<unsigned long,BaseProperty,1>::add(
    (HashTable<unsigned long,BaseProperty,1> *)&pc.m_hashProperties.vfptr,
    &_key,
    &p);
  v1->m_dialogContext = DialogFactory::MakeDialogInCurrentUI(&pc);
  StringInfo::~StringInfo(&info);
  if ( (_DWORD)p.m_pcPropertyDesc )
  {
    v3 = p.m_pcPropertyDesc;
    v4 = p.m_pcPropertyDesc->m_cRef - 1;
    p.m_pcPropertyDesc->m_cRef = v4;
    if ( !v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyDesc = 0;
  }
  if ( p.m_pcPropertyValue )
  {
    v5 = p.m_pcPropertyValue;
    v6 = p.m_pcPropertyValue->m_cRef - 1;
    p.m_pcPropertyValue->m_cRef = v6;
    if ( !v6 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    p.m_pcPropertyValue = 0;
  }
  PropertyCollection::~PropertyCollection(&pc);
}

//----- (004EFB90) --------------------------------------------------------  // acclient.c:284081
void __thiscall UIOption::HandleDialogAndNotices(UIOption *this, bool _userRequested)
{
  UIOption *v2; // esi@1
  void (*v3)(void); // eax@8
  IOptionChangeHandler *v4; // ecx@10

  v2 = this;
  if ( this->m_confirmChange && _userRequested )
    UIOption::HandleDialog(this);
  if ( v2->m_shouldReloadOptions )
    CM_Character::SendNotice_ReloadOptions();
  if ( v2->m_shouldRefreshOptionsPanel )
    CM_UI::SendNotice_RefreshOptionsPanel();
  v3 = (void (*)(void))v2->m_noticeFuncPtr;
  if ( v3 )
    v3();
  v4 = v2->m_pOCH;
  if ( v4 )
  {
    if ( _userRequested )
      ((void (__stdcall *)(_DWORD))v4->vfptr->OnOptionChanged)(v2);
  }
}

//----- (006F79E0) --------------------------------------------------------  // acclient.c:780441
void sub_6F79E0()
{
  flt_840D48 = 1000.0 + 1.0;
}

//----- (006F7A00) --------------------------------------------------------  // acclient.c:780447
void sub_6F7A00()
{
  flt_840D4C = 24.0 * 8.0;
}

//----- (006F7A20) --------------------------------------------------------  // acclient.c:780453
void sub_6F7A20()
{
  flt_840D50 = 24.0 * 0.5;
}

//----- (006F7A40) --------------------------------------------------------  // acclient.c:780459
int sub_6F7A40()
{
  return atexit(nullsub_993);
}

//----- (006F7A50) --------------------------------------------------------  // acclient.c:780465
int sub_6F7A50()
{
  return atexit(nullsub_994);
}

//----- (006F7A60) --------------------------------------------------------  // acclient.c:780471
int sub_6F7A60()
{
  return atexit(nullsub_995);
}

//----- (006F7A70) --------------------------------------------------------  // acclient.c:780477
void _E106_80()
{
  DEFAULT_VIEW_RADIUS_82 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F7A90) --------------------------------------------------------  // acclient.c:780483
void _E108_62()
{
  MIN_QUANTUM_82 = 1.0 / 30.0;
}

//----- (006F7AB0) --------------------------------------------------------  // acclient.c:780489
void _E110_52()
{
  MAX_QUANTUM_82 = 1.0 / 5.0;
}

//----- (006F7AD0) --------------------------------------------------------  // acclient.c:780495
void _E112_72()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840D68, PFID_A8R8G8B8);
}

//----- (006F7AE0) --------------------------------------------------------  // acclient.c:780501
void _E115_52()
{
  dword_840DA0 = 1024;
}

//----- (006F7AF0) --------------------------------------------------------  // acclient.c:780507
void _E117_49()
{
  dword_840DA4 = 0x7FFF;
}

//----- (006F7B00) --------------------------------------------------------  // acclient.c:780513
int _E119_18()
{
  const int result; // eax@1

  result = dword_840DA0;
  INITIAL_MAX_DATA_RATE_55 = dword_840DA0;
  return result;
}

//----- (006F7B10) --------------------------------------------------------  // acclient.c:780523
int _E121_48()
{
  return atexit(_E122_78);
}

//----- (006F7B20) --------------------------------------------------------  // acclient.c:780529
int sub_6F7B20()
{
  return atexit(nullsub_992);
}

