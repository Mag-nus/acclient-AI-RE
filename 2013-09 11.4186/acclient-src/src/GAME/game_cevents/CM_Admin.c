/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Admin
   Object     : GAME\game_cevents\CM_Admin.obj
   Functions  : 36
   Addresses  : 006AD910 - 00722E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AD910) --------------------------------------------------------  // acclient.c:710794
unsigned int __cdecl CM_Admin::DispatchUI_Environs(UIQueueManager *ui, void *buf)
{
  CPlayerSystem *v2; // ecx@2
  unsigned int result; // eax@4

  if ( ui && (v2 = ui->m_pPlayerSystem) != 0 && *(_DWORD *)buf == 60000 )
    result = CPlayerSystem::Handle_Admin__Environs(v2, *((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AD940) --------------------------------------------------------  // acclient.c:710807
unsigned int __cdecl CM_Admin::DispatchUI_Recv_QueryPluginList(UIQueueManager *ui, void *buf)
{
  unsigned int result; // eax@4

  if ( ui && ui->m_pAdminSystem && *(_DWORD *)buf == 686 )
    result = ClientAdminSystem::Handle_Admin__Recv_QueryPluginList(*((_DWORD *)buf + 1));
  else
    result = 0;
  return result;
}

//----- (006AD970) --------------------------------------------------------  // acclient.c:710819
AdminAccountData *__thiscall AdminAccountData::vector_deleting_destructor(AdminAccountData *this, unsigned int a2)
{
  AdminAccountData *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  v3 = this->accountName.m_buffer;
  this->vfptr = (PackObjVtbl *)&AdminAccountData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006AD9C0) --------------------------------------------------------  // acclient.c:710838
AdminPlayerData *__thiscall AdminPlayerData::vector_deleting_destructor(AdminPlayerData *this, unsigned int a2)
{
  AdminPlayerData *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1

  v2 = this;
  v3 = this->name.m_buffer;
  this->vfptr = (PackObjVtbl *)&AdminPlayerData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

//----- (006ADAA0) --------------------------------------------------------  // acclient.c:710898
bool __cdecl CM_Admin::Event_QueryPluginListResponse(unsigned int i_context, AC1Legacy::PStringBase<char> *i_pluginList)
{
  int v2; // esi@1
  int v3; // esi@1
  void *v4; // eax@1
  char *v5; // edi@1
  char *v6; // eax@1
  char *v7; // eax@1
  bool v8; // zf@1
  unsigned int v9; // ecx@1
  int v10; // edx@4
  bool v11; // bl@6
  void *buf; // [sp+Ch] [bp-Ch]@1
  OrderHdr hdr; // [sp+10h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v2 = AC1Legacy::PStringBase<char>::Pack(i_pluginList, &buf, 0);
  v3 = v2 + OrderHdr::Pack(&hdr, &buf, 0) + 8;
  v4 = operator new[](v3);
  buf = v4;
  v5 = (char *)v4;
  OrderHdr::Pack(&hdr, &buf, v3);
  *(_DWORD *)buf = 687;
  v6 = (char *)buf + 4;
  buf = v6;
  *(_DWORD *)v6 = i_context;
  v7 = (char *)buf + 4;
  v9 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v8 = v9 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v9 = (((_BYTE)v9 - 1) | 0xFFFFFFFC) + 1;
    v8 = v9 == 0;
  }
  if ( !v8 )
  {
    v10 = 4 - v9;
    if ( 4 != v9 )
    {
      do
      {
        *v7 = 0;
        v7 = (char *)buf + 1;
        --v10;
        buf = (char *)buf + 1;
      }
      while ( v10 );
    }
  }
  AC1Legacy::PStringBase<char>::Pack(i_pluginList, &buf, v3 + v5 - v7);
  v11 = Proto_UI::SendToWeenie(v5, v3);
  if ( !v11 )
    Proto_UI::UICounterFailedSend();
  return v11;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006ADB90) --------------------------------------------------------  // acclient.c:710959
bool __cdecl CM_Admin::Event_QueryPluginResponse(unsigned int i_context, int i_success, AC1Legacy::PStringBase<char> *i_pluginName, AC1Legacy::PStringBase<char> *i_pluginAuthor, AC1Legacy::PStringBase<char> *i_pluginEMail, AC1Legacy::PStringBase<char> *i_pluginWebpage)
{
  int v6; // esi@1
  int v7; // esi@1
  int v8; // esi@1
  int v9; // esi@1
  int v10; // esi@1
  void *v11; // eax@1
  char *v12; // edi@1
  char *v13; // eax@1
  char *v14; // ecx@1
  bool v15; // zf@1
  unsigned int v16; // eax@1
  int v17; // edx@4
  char *v18; // eax@6
  bool v19; // zf@6
  unsigned int v20; // ecx@6
  int v21; // edx@9
  bool v22; // bl@11
  void *buf; // [sp+10h] [bp-Ch]@1
  OrderHdr hdr; // [sp+14h] [bp-8h]@1

  hdr.stamp_ = Proto_UI::GetNextUICounter();
  hdr.vfptr = (PackObjVtbl *)&OrderHdr::vftable;
  buf = 0;
  v6 = AC1Legacy::PStringBase<char>::Pack(i_pluginName, &buf, 0);
  v7 = AC1Legacy::PStringBase<char>::Pack(i_pluginAuthor, &buf, 0) + v6;
  v8 = AC1Legacy::PStringBase<char>::Pack(i_pluginEMail, &buf, 0) + v7;
  v9 = AC1Legacy::PStringBase<char>::Pack(i_pluginWebpage, &buf, 0) + v8;
  v10 = v9 + OrderHdr::Pack(&hdr, &buf, 0) + 12;
  v11 = operator new[](v10);
  buf = v11;
  v12 = (char *)v11;
  OrderHdr::Pack(&hdr, &buf, v10);
  *(_DWORD *)buf = 690;
  v13 = (char *)buf + 4;
  buf = v13;
  *(_DWORD *)v13 = i_context;
  v14 = (char *)buf + 4;
  v16 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v15 = v16 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v16 = (((_BYTE)v16 - 1) | 0xFFFFFFFC) + 1;
    v15 = v16 == 0;
  }
  if ( !v15 )
  {
    v17 = 4 - v16;
    if ( 4 != v16 )
    {
      do
      {
        *v14 = 0;
        v14 = (char *)buf + 1;
        --v17;
        buf = (char *)buf + 1;
      }
      while ( v17 );
    }
  }
  *(_DWORD *)v14 = i_success;
  v18 = (char *)buf + 4;
  v20 = (unsigned int)((char *)buf + 4) & 0x80000003;
  v19 = v20 == 0;
  buf = (char *)buf + 4;
  if ( ((unsigned int)buf & 0x80000003 & 0x80000000) != 0 )
  {
    v20 = (((_BYTE)v20 - 1) | 0xFFFFFFFC) + 1;
    v19 = v20 == 0;
  }
  if ( !v19 )
  {
    v21 = 4 - v20;
    if ( 4 != v20 )
    {
      do
      {
        *v18 = 0;
        v18 = (char *)buf + 1;
        --v21;
        buf = (char *)buf + 1;
      }
      while ( v21 );
    }
  }
  AC1Legacy::PStringBase<char>::Pack(i_pluginName, &buf, v10 + v12 - v18);
  AC1Legacy::PStringBase<char>::Pack(i_pluginAuthor, &buf, v10 + v12 - (_BYTE *)buf);
  AC1Legacy::PStringBase<char>::Pack(i_pluginEMail, &buf, v10 + v12 - (_BYTE *)buf);
  AC1Legacy::PStringBase<char>::Pack(i_pluginWebpage, &buf, v10 + v12 - (_BYTE *)buf);
  v22 = Proto_UI::SendToWeenie(v12, v10);
  if ( !v22 )
    Proto_UI::UICounterFailedSend();
  return v22;
}
// 801AD4: using guessed type int (__thiscall *OrderHdr::vftable)(void *, char);

//----- (006ADD50) --------------------------------------------------------  // acclient.c:711058
int __thiscall AdminPlayerData::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // edi@1
  int v4; // eax@5

  v2 = this;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  return v2;
}

//----- (006ADDA0) --------------------------------------------------------  // acclient.c:711079
unsigned int __cdecl CM_Admin::DispatchUI_Recv_QueryPlugin(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  void *v5; // esi@4
  unsigned int v6; // ebx@6
  void *v7; // edi@6
  ClientAdminSystem *v8; // ecx@6
  unsigned int v9; // edi@6
  UIQueueManager *v10; // esi@6

  v3 = ui;
  if ( ui && ui->m_pAdminSystem )
  {
    v5 = buf;
    if ( *(_DWORD *)buf == 689 )
    {
      v6 = *((_DWORD *)buf + 1);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      buf = (char *)buf + 8;
      v7 = buf;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, size + (_BYTE *)v5 - (_BYTE *)v7);
      v8 = v3->m_pAdminSystem;
      v9 = ClientAdminSystem::Handle_Admin__Recv_QueryPlugin(v6, (AC1Legacy::PStringBase<char> *)&ui);
      v10 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) )
      {
        if ( v10 )
          ((void (__thiscall *)(UIQueueManager *, signed int))v10->vfptr->IUnknown_QueryInterface)(v10, 1);
      }
      result = v9;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006ADE40) --------------------------------------------------------  // acclient.c:711126
unsigned int __cdecl CM_Admin::DispatchUI_Recv_QueryPluginResponse(UIQueueManager *ui, void *buf, unsigned int size)
{
  UIQueueManager *v3; // ebp@1
  unsigned int result; // eax@3
  int v5; // eax@4
  void *v6; // esi@4
  char *v7; // ebx@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  ClientAdminSystem *v10; // ecx@6
  unsigned int v11; // ebx@6
  UIQueueManager *v12; // esi@6
  AC1Legacy::PSRefBuffer<char> *v13; // esi@9
  AC1Legacy::PSRefBuffer<char> *v14; // esi@12
  AC1Legacy::PSRefBuffer<char> *v15; // esi@15
  AC1Legacy::PSRefBuffer<char> *v16; // esi@18
  AC1Legacy::PStringBase<char> pluginEMail; // [sp+4h] [bp-10h]@6
  AC1Legacy::PStringBase<char> pluginAuthor; // [sp+8h] [bp-Ch]@6
  AC1Legacy::PStringBase<char> pluginName; // [sp+Ch] [bp-8h]@6
  AC1Legacy::PStringBase<char> playerName; // [sp+10h] [bp-4h]@6

  v3 = ui;
  if ( ui && ui->m_pAdminSystem )
  {
    v5 = *(_DWORD *)buf;
    v6 = buf;
    v7 = (char *)buf + 4;
    buf = (char *)buf + 4;
    if ( v5 == 691 )
    {
      playerName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      v8 = (_BYTE *)v6 - v7;
      v9 = size;
      AC1Legacy::PStringBase<char>::UnPack(&playerName, &buf, size + v8);
      pluginName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&pluginName, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      pluginAuthor.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&pluginAuthor, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      pluginEMail.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack(&pluginEMail, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      ui = (UIQueueManager *)AC1Legacy::PStringBase<char>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
      AC1Legacy::PStringBase<char>::UnPack((AC1Legacy::PStringBase<char> *)&ui, &buf, v9 + (_BYTE *)v6 - (_BYTE *)buf);
      v10 = v3->m_pAdminSystem;
      v11 = ClientAdminSystem::Handle_Admin__Recv_QueryPluginResponse(
              &playerName,
              &pluginName,
              &pluginAuthor,
              &pluginEMail,
              (AC1Legacy::PStringBase<char> *)&ui);
      v12 = ui;
      if ( !InterlockedDecrement((volatile LONG *)&ui->m_cTurbineRefCount) && v12 )
        ((void (__thiscall *)(UIQueueManager *, signed int))v12->vfptr->IUnknown_QueryInterface)(v12, 1);
      v13 = pluginEMail.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&pluginEMail.m_buffer->m_cRef) && v13 )
        v13->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v13, 1u);
      v14 = pluginAuthor.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&pluginAuthor.m_buffer->m_cRef) && v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
      v15 = pluginName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&pluginName.m_buffer->m_cRef) && v15 )
        v15->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v15, 1u);
      v16 = playerName.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&playerName.m_buffer->m_cRef) )
      {
        if ( v16 )
          v16->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v16, 1u);
      }
      result = v11;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (006AE000) --------------------------------------------------------  // acclient.c:711214
int __thiscall PackableList<AdminAccountData>::InsertTail(PackableList<AdminAccountData> *this, AdminAccountData *val)
{
  PackableList<AdminAccountData> *v2; // edi@1
  void *v3; // eax@1
  void *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // eax@2
  int result; // eax@5
  PackableLLNode<AdminAccountData> *v7; // eax@6

  v2 = this;
  v3 = operator new(0x14u);
  v4 = v3;
  if ( v3 )
  {
    *(_DWORD *)v3 = &AdminAccountData::vftable;
    v5 = val->accountName.m_buffer;
    *((_DWORD *)v4 + 1) = v5;
    InterlockedIncrement((volatile LONG *)&v5->m_cRef);
    *((_DWORD *)v4 + 2) = val->bookieID;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
  }
  else
  {
    v4 = 0;
  }
  if ( v2->head )
  {
    v7 = v2->tail;
    v7->next = (PackableLLNode<AdminAccountData> *)v4;
    *((_DWORD *)v4 + 4) = v7;
    result = v2->curNum + 1;
    v2->tail = (PackableLLNode<AdminAccountData> *)v4;
    v2->curNum = result;
  }
  else
  {
    result = v2->curNum + 1;
    v2->head = (PackableLLNode<AdminAccountData> *)v4;
    v2->tail = (PackableLLNode<AdminAccountData> *)v4;
    v2->curNum = result;
  }
  return result;
}
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006AE080) --------------------------------------------------------  // acclient.c:711261
int __thiscall PackableList<AdminPlayerData>::InsertTail(PackableList<AdminPlayerData> *this, AdminPlayerData *val)
{
  PackableList<AdminPlayerData> *v2; // edi@1
  void *v3; // eax@1
  void *v4; // esi@1
  AC1Legacy::PSRefBuffer<char> *v5; // eax@2
  int result; // eax@5
  PackableLLNode<AdminPlayerData> *v7; // eax@6

  v2 = this;
  v3 = operator new(0x14u);
  v4 = v3;
  if ( v3 )
  {
    *(_DWORD *)v3 = &AdminPlayerData::vftable;
    v5 = val->name.m_buffer;
    *((_DWORD *)v4 + 1) = v5;
    InterlockedIncrement((volatile LONG *)&v5->m_cRef);
    *((_DWORD *)v4 + 2) = val->bookieID;
    *((_DWORD *)v4 + 3) = 0;
    *((_DWORD *)v4 + 4) = 0;
  }
  else
  {
    v4 = 0;
  }
  if ( v2->head )
  {
    v7 = v2->tail;
    v7->next = (PackableLLNode<AdminPlayerData> *)v4;
    *((_DWORD *)v4 + 4) = v7;
    result = v2->curNum + 1;
    v2->tail = (PackableLLNode<AdminPlayerData> *)v4;
    v2->curNum = result;
  }
  else
  {
    result = v2->curNum + 1;
    v2->head = (PackableLLNode<AdminPlayerData> *)v4;
    v2->tail = (PackableLLNode<AdminPlayerData> *)v4;
    v2->curNum = result;
  }
  return result;
}
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

//----- (006AE100) --------------------------------------------------------  // acclient.c:711308
int __thiscall PackableList<AdminAccountData>::RemoveHead(PackableList<AdminAccountData> *this, AdminAccountData *retVal)
{
  PackableList<AdminAccountData> *v2; // ebx@1
  int v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // edi@7

  v2 = this;
  v3 = (int)this->head;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 12);
    this->head = (PackableLLNode<AdminAccountData> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 16) = 0;
    else
      this->tail = 0;
    AdminPlayerData::operator=((int)retVal, v3);
    if ( v3 )
    {
      v6 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)v3 = &AdminAccountData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      *(_DWORD *)v3 = &PackObj::vftable;
      operator delete((void *)v3);
    }
    --v2->curNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006AE180) --------------------------------------------------------  // acclient.c:711352
int __thiscall PackableList<AdminPlayerData>::RemoveHead(PackableList<AdminPlayerData> *this, AdminPlayerData *retVal)
{
  PackableList<AdminPlayerData> *v2; // ebx@1
  int v3; // esi@1
  int result; // eax@2
  int v5; // eax@3
  int v6; // edi@7

  v2 = this;
  v3 = (int)this->head;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 12);
    this->head = (PackableLLNode<AdminPlayerData> *)v5;
    if ( v5 )
      *(_DWORD *)(v5 + 16) = 0;
    else
      this->tail = 0;
    AdminPlayerData::operator=((int)retVal, v3);
    if ( v3 )
    {
      v6 = *(_DWORD *)(v3 + 4);
      *(_DWORD *)v3 = &AdminPlayerData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      }
      *(_DWORD *)v3 = &PackObj::vftable;
      operator delete((void *)v3);
    }
    --v2->curNum;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

//----- (006AE200) --------------------------------------------------------  // acclient.c:711396
void __thiscall PackableList<AdminAccountData>::Flush(PackableList<AdminAccountData> *this)
{
  PackableList<AdminAccountData> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@3
  AdminAccountData dummyData; // [sp+4h] [bp-Ch]@1

  v1 = this;
  AdminAccountData::AdminAccountData(&dummyData);
  while ( v1->head )
    PackableList<AdminAccountData>::RemoveHead(v1, &dummyData);
  v2 = dummyData.accountName.m_buffer;
  dummyData.vfptr = (PackObjVtbl *)&AdminAccountData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&dummyData.accountName.m_buffer->m_cRef) )
  {
    if ( v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  }
}
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006AE260) --------------------------------------------------------  // acclient.c:711417
void __thiscall PackableList<AdminPlayerData>::Flush(PackableList<AdminPlayerData> *this)
{
  PackableList<AdminPlayerData> *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // esi@3
  AdminPlayerData dummyData; // [sp+4h] [bp-Ch]@1

  v1 = this;
  AdminPlayerData::AdminPlayerData(&dummyData);
  while ( v1->head )
    PackableList<AdminPlayerData>::RemoveHead(v1, &dummyData);
  v2 = dummyData.name.m_buffer;
  dummyData.vfptr = (PackObjVtbl *)&AdminPlayerData::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&dummyData.name.m_buffer->m_cRef) )
  {
    if ( v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  }
}
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

//----- (006AE2C0) --------------------------------------------------------  // acclient.c:711438
int __thiscall PackableList<AdminAccountData>::UnPack(PackableList<AdminAccountData> *this, void **addr, unsigned int size)
{
  PackableList<AdminAccountData> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  AC1Legacy::PSRefBuffer<char> *v6; // esi@5
  int result; // eax@8
  AC1Legacy::PSRefBuffer<char> *v8; // esi@10
  AdminAccountData temp; // [sp+8h] [bp-Ch]@2

  v3 = this;
  PackableList<AdminAccountData>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    AdminAccountData::AdminAccountData(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      v6 = temp.accountName.m_buffer;
      temp.vfptr = (PackObjVtbl *)&AdminAccountData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&temp.accountName.m_buffer->m_cRef) )
      {
        if ( v6 )
          v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      }
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(AdminAccountData *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<AdminAccountData>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      v8 = temp.accountName.m_buffer;
      temp.vfptr = (PackObjVtbl *)&AdminAccountData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&temp.accountName.m_buffer->m_cRef) && v8 )
        v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      result = 0;
    }
  }
  return result;
}
// 803534: using guessed type int (__thiscall *AdminAccountData::vftable)(void *, char);

//----- (006AE390) --------------------------------------------------------  // acclient.c:711493
int __thiscall PackableList<AdminPlayerData>::UnPack(PackableList<AdminPlayerData> *this, void **addr, unsigned int size)
{
  PackableList<AdminPlayerData> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  AC1Legacy::PSRefBuffer<char> *v6; // esi@5
  int result; // eax@8
  AC1Legacy::PSRefBuffer<char> *v8; // esi@10
  AdminPlayerData temp; // [sp+8h] [bp-Ch]@2

  v3 = this;
  PackableList<AdminPlayerData>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    AdminPlayerData::AdminPlayerData(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      v6 = temp.name.m_buffer;
      temp.vfptr = (PackObjVtbl *)&AdminPlayerData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&temp.name.m_buffer->m_cRef) )
      {
        if ( v6 )
          v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
      }
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(AdminPlayerData *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<AdminPlayerData>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      v8 = temp.name.m_buffer;
      temp.vfptr = (PackObjVtbl *)&AdminPlayerData::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&temp.name.m_buffer->m_cRef) && v8 )
        v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      result = 0;
    }
  }
  return result;
}
// 803548: using guessed type int (__thiscall *AdminPlayerData::vftable)(void *, char);

//----- (006AE460) --------------------------------------------------------  // acclient.c:711548
PackableList<AdminAccountData> *__thiscall PackableList<AdminAccountData>::scalar_deleting_destructor(PackableList<AdminAccountData> *this, unsigned int a2)
{
  PackableList<AdminAccountData> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<AdminAccountData>::vftable;
  PackableList<AdminAccountData>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 80350C: using guessed type int (__thiscall *PackableList<AdminAccountData>::vftable)(void *, char);

//----- (006AE490) --------------------------------------------------------  // acclient.c:711564
PackableList<AdminPlayerData> *__thiscall PackableList<AdminPlayerData>::vector_deleting_destructor(PackableList<AdminPlayerData> *this, unsigned int a2)
{
  PackableList<AdminPlayerData> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<AdminPlayerData>::vftable;
  PackableList<AdminPlayerData>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803520: using guessed type int (__thiscall *PackableList<AdminPlayerData>::vftable)(void *, char);

//----- (006AE4C0) --------------------------------------------------------  // acclient.c:711580
unsigned int __cdecl CM_Admin::DispatchUI_ReceiveAccountData(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  void **v7; // esi@6
  ClientAdminSystem *v8; // ecx@6
  unsigned int v9; // esi@6
  PackableList<AdminAccountData> accountDataList; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pAdminSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 63434;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      v7 = *(void ***)v5;
      buf = v5 + 4;
      accountDataList.vfptr = (PackObjVtbl *)&PackableList<AdminAccountData>::vftable;
      accountDataList.head = 0;
      accountDataList.tail = 0;
      accountDataList.curNum = 0;
      PackableList<AdminAccountData>::UnPack(&accountDataList, &buf, size + (_BYTE *)v4 - (v5 + 4));
      v8 = ui->m_pAdminSystem;
      v9 = CEnvCell::walkable_surface_type(v7, (unsigned int)&accountDataList);
      accountDataList.vfptr = (PackObjVtbl *)&PackableList<AdminAccountData>::vftable;
      PackableList<AdminAccountData>::Flush(&accountDataList);
      result = v9;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 80350C: using guessed type int (__thiscall *PackableList<AdminAccountData>::vftable)(void *, char);

//----- (006AE560) --------------------------------------------------------  // acclient.c:711626
unsigned int __cdecl CM_Admin::DispatchUI_ReceivePlayerData(UIQueueManager *ui, void *buf, unsigned int size)
{
  unsigned int result; // eax@3
  void *v4; // eax@4
  char *v5; // ecx@4
  bool v6; // zf@4
  void **v7; // esi@6
  ClientAdminSystem *v8; // ecx@6
  unsigned int v9; // esi@6
  PackableList<AdminPlayerData> playerDataList; // [sp+4h] [bp-10h]@6

  if ( ui && ui->m_pAdminSystem )
  {
    v4 = buf;
    v5 = (char *)buf + 4;
    v6 = *(_DWORD *)buf == 63435;
    buf = (char *)buf + 4;
    if ( v6 )
    {
      v7 = *(void ***)v5;
      buf = v5 + 4;
      playerDataList.vfptr = (PackObjVtbl *)&PackableList<AdminPlayerData>::vftable;
      playerDataList.head = 0;
      playerDataList.tail = 0;
      playerDataList.curNum = 0;
      PackableList<AdminPlayerData>::UnPack(&playerDataList, &buf, size + (_BYTE *)v4 - (v5 + 4));
      v8 = ui->m_pAdminSystem;
      v9 = CEnvCell::walkable_surface_type(v7, (unsigned int)&playerDataList);
      playerDataList.vfptr = (PackObjVtbl *)&PackableList<AdminPlayerData>::vftable;
      PackableList<AdminPlayerData>::Flush(&playerDataList);
      result = v9;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 803520: using guessed type int (__thiscall *PackableList<AdminPlayerData>::vftable)(void *, char);

//----- (00722D00) --------------------------------------------------------  // acclient.c:820685
void sub_722D00()
{
  flt_8FA558 = 1000.0 + 1.0;
}

//----- (00722D20) --------------------------------------------------------  // acclient.c:820691
void sub_722D20()
{
  flt_8FA55C = 24.0 * 8.0;
}

//----- (00722D40) --------------------------------------------------------  // acclient.c:820697
void sub_722D40()
{
  flt_8FA560 = 24.0 * 0.5;
}

//----- (00722D60) --------------------------------------------------------  // acclient.c:820703
int sub_722D60()
{
  return atexit(nullsub_368);
}

//----- (00722D70) --------------------------------------------------------  // acclient.c:820709
int sub_722D70()
{
  return atexit(nullsub_369);
}

//----- (00722D80) --------------------------------------------------------  // acclient.c:820715
int sub_722D80()
{
  return atexit(nullsub_370);
}

//----- (00722D90) --------------------------------------------------------  // acclient.c:820721
void sub_722D90()
{
  flt_8FA564 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00722DB0) --------------------------------------------------------  // acclient.c:820727
void sub_722DB0()
{
  dbl_8FA568 = 1.0 / 30.0;
}

//----- (00722DD0) --------------------------------------------------------  // acclient.c:820733
void _E110_96()
{
  dbl_8FA570 = 1.0 / 5.0;
}

//----- (00722DF0) --------------------------------------------------------  // acclient.c:820739
void sub_722DF0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA578, PFID_A8R8G8B8);
}

//----- (00722E00) --------------------------------------------------------  // acclient.c:820745
void sub_722E00()
{
  dword_8FA5B0 = 1024;
}

//----- (00722E10) --------------------------------------------------------  // acclient.c:820751
void sub_722E10()
{
  dword_8FA5B4 = 0x7FFF;
}

//----- (00722E20) --------------------------------------------------------  // acclient.c:820757
int _E119_48()
{
  const int result; // eax@1

  result = dword_8FA5B0;
  dword_8FA5B8 = dword_8FA5B0;
  return result;
}

//----- (00722E30) --------------------------------------------------------  // acclient.c:820767
int sub_722E30()
{
  return atexit(nullsub_366);
}

//----- (00722E40) --------------------------------------------------------  // acclient.c:820773
int sub_722E40()
{
  return atexit(nullsub_367);
}

