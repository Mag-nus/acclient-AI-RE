/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CContract
   Object     : AC\accquest\CContract.obj
   Functions  : 10
   Addresses  : 00599FE0 - 0070B070 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00599FE0) --------------------------------------------------------  // acclient.c:452397
void __thiscall CContract::CContract(CContract *this)
{
  CContract *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  volatile LONG *v6; // ST00_4@1
  volatile LONG *v7; // ST00_4@1
  volatile LONG *v8; // ST00_4@1
  volatile LONG *v9; // ST00_4@1
  volatile LONG *v10; // ST00_4@1
  volatile LONG *v11; // ST00_4@1
  volatile LONG *v12; // ST00_4@1
  int v13; // ecx@1
  int v14; // ecx@1
  int v15; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&CContract::vftable;
  this->_version = 0;
  this->_contract_id = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_contract_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_description.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_description_progress.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name_npc_start.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  v6 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_name_npc_end.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v6);
  v7 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_stamped.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v7);
  v8 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_started.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v8);
  v9 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_finished.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v9);
  v10 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_progress.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v10);
  v11 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_timer.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v11);
  v12 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->_questflag_repeat_time.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v12);
  v13 = (int)&v1->_location_npc_start.frame;
  v1->_location_npc_start.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->_location_npc_start.objcell_id = 0;
  *(_DWORD *)v13 = 1065353216;
  *(_DWORD *)(v13 + 4) = 0;
  *(_DWORD *)(v13 + 8) = 0;
  *(_DWORD *)(v13 + 12) = 0;
  *(_DWORD *)(v13 + 52) = 0;
  *(_DWORD *)(v13 + 56) = 0;
  *(_DWORD *)(v13 + 60) = 0;
  Frame::cache(&v1->_location_npc_start.frame);
  v14 = (int)&v1->_location_npc_end.frame;
  v1->_location_npc_end.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->_location_npc_end.objcell_id = 0;
  *(_DWORD *)v14 = 1065353216;
  *(_DWORD *)(v14 + 4) = 0;
  *(_DWORD *)(v14 + 8) = 0;
  *(_DWORD *)(v14 + 12) = 0;
  *(_DWORD *)(v14 + 52) = 0;
  *(_DWORD *)(v14 + 56) = 0;
  *(_DWORD *)(v14 + 60) = 0;
  Frame::cache(&v1->_location_npc_end.frame);
  v15 = (int)&v1->_location_quest_area.frame;
  v1->_location_quest_area.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->_location_quest_area.objcell_id = 0;
  *(_DWORD *)v15 = 1065353216;
  *(_DWORD *)(v15 + 4) = 0;
  *(_DWORD *)(v15 + 8) = 0;
  *(_DWORD *)(v15 + 12) = 0;
  *(_DWORD *)(v15 + 52) = 0;
  *(_DWORD *)(v15 + 56) = 0;
  *(_DWORD *)(v15 + 60) = 0;
  Frame::cache(&v1->_location_quest_area.frame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E5128: using guessed type int (__thiscall *CContract::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0059A140) --------------------------------------------------------  // acclient.c:452491
void __thiscall CContract::CContract(CContract *this, CContract *_contract)
{
  CContract *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // eax@1
  AC1Legacy::PSRefBuffer<char> *v6; // eax@1
  AC1Legacy::PSRefBuffer<char> *v7; // eax@1
  AC1Legacy::PSRefBuffer<char> *v8; // eax@1
  AC1Legacy::PSRefBuffer<char> *v9; // eax@1
  AC1Legacy::PSRefBuffer<char> *v10; // eax@1
  AC1Legacy::PSRefBuffer<char> *v11; // eax@1
  AC1Legacy::PSRefBuffer<char> *v12; // eax@1
  AC1Legacy::PSRefBuffer<char> *v13; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&CContract::vftable;
  this->_version = _contract->_version;
  this->_contract_id = _contract->_contract_id;
  v3 = _contract->_contract_name.m_buffer;
  this->_contract_name.m_buffer = v3;
  InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  v4 = _contract->_description.m_buffer;
  v2->_description.m_buffer = v4;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v5 = _contract->_description_progress.m_buffer;
  v2->_description_progress.m_buffer = v5;
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  v6 = _contract->_name_npc_start.m_buffer;
  v2->_name_npc_start.m_buffer = v6;
  InterlockedIncrement((volatile LONG *)&v6->m_cRef);
  v7 = _contract->_name_npc_end.m_buffer;
  v2->_name_npc_end.m_buffer = v7;
  InterlockedIncrement((volatile LONG *)&v7->m_cRef);
  v8 = _contract->_questflag_stamped.m_buffer;
  v2->_questflag_stamped.m_buffer = v8;
  InterlockedIncrement((volatile LONG *)&v8->m_cRef);
  v9 = _contract->_questflag_started.m_buffer;
  v2->_questflag_started.m_buffer = v9;
  InterlockedIncrement((volatile LONG *)&v9->m_cRef);
  v10 = _contract->_questflag_finished.m_buffer;
  v2->_questflag_finished.m_buffer = v10;
  InterlockedIncrement((volatile LONG *)&v10->m_cRef);
  v11 = _contract->_questflag_progress.m_buffer;
  v2->_questflag_progress.m_buffer = v11;
  InterlockedIncrement((volatile LONG *)&v11->m_cRef);
  v12 = _contract->_questflag_timer.m_buffer;
  v2->_questflag_timer.m_buffer = v12;
  InterlockedIncrement((volatile LONG *)&v12->m_cRef);
  v13 = _contract->_questflag_repeat_time.m_buffer;
  v2->_questflag_repeat_time.m_buffer = v13;
  InterlockedIncrement((volatile LONG *)&v13->m_cRef);
  v2->_location_npc_start.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->_location_npc_start.objcell_id = _contract->_location_npc_start.objcell_id;
  Frame::operator=((int)&v2->_location_npc_start.frame, (int)&_contract->_location_npc_start.frame);
  v2->_location_npc_end.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->_location_npc_end.objcell_id = _contract->_location_npc_end.objcell_id;
  Frame::operator=((int)&v2->_location_npc_end.frame, (int)&_contract->_location_npc_end.frame);
  v2->_location_quest_area.vfptr = (PackObjVtbl *)&Position::vftable;
  v2->_location_quest_area.objcell_id = _contract->_location_quest_area.objcell_id;
  Frame::operator=((int)&v2->_location_quest_area.frame, (int)&_contract->_location_quest_area.frame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E5128: using guessed type int (__thiscall *CContract::vftable)(void *, char);

//----- (0059A250) --------------------------------------------------------  // acclient.c:452557
CContract *__thiscall CContract::scalar_deleting_destructor(CContract *this, unsigned int a2)
{
  CContract *v2; // esi@1

  v2 = this;
  CContract::~CContract(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0059A270) --------------------------------------------------------  // acclient.c:452569
int __thiscall CContract::GetPackSize(CContract *this, const unsigned int version)
{
  CContract *v2; // esi@1
  char *v3; // edi@1
  char *v4; // ebx@1
  int v5; // ebp@1
  int v6; // ebp@1
  int v7; // ebp@1
  int v8; // ebp@1
  int v9; // ebp@1
  int v10; // ebp@1
  int v11; // ebp@1
  int v12; // ebp@1
  int v13; // ebp@1
  int v14; // ebp@1
  int v15; // ebp@1
  int v16; // ebp@1
  int v17; // ebp@1
  void *addr; // [sp+10h] [bp-8h]@1
  Position *v20; // [sp+14h] [bp-4h]@1

  v2 = this;
  addr = 0;
  v3 = (char *)&this->_location_quest_area;
  v4 = (char *)&this->_location_npc_end;
  v20 = &this->_location_npc_start;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->_questflag_repeat_time, &addr, 0);
  v6 = AC1Legacy::PStringBase<char>::Pack(&v2->_questflag_timer, &addr, 0) + v5;
  v7 = AC1Legacy::PStringBase<char>::Pack(&v2->_questflag_progress, &addr, 0) + v6;
  v8 = AC1Legacy::PStringBase<char>::Pack(&v2->_questflag_finished, &addr, 0) + v7;
  v9 = AC1Legacy::PStringBase<char>::Pack(&v2->_questflag_started, &addr, 0) + v8;
  v10 = AC1Legacy::PStringBase<char>::Pack(&v2->_questflag_stamped, &addr, 0) + v9;
  v11 = AC1Legacy::PStringBase<char>::Pack(&v2->_name_npc_end, &addr, 0) + v10;
  v12 = AC1Legacy::PStringBase<char>::Pack(&v2->_name_npc_start, &addr, 0) + v11;
  v13 = AC1Legacy::PStringBase<char>::Pack(&v2->_description_progress, &addr, 0) + v12;
  v14 = AC1Legacy::PStringBase<char>::Pack(&v2->_description, &addr, 0) + v13;
  v15 = AC1Legacy::PStringBase<char>::Pack(&v2->_contract_name, &addr, 0) + v14;
  v16 = (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v4 + 12))(&v2->_location_npc_end, &addr, 0) + v15;
  v17 = ((int (__stdcall *)(void **, _DWORD))v20->vfptr->Pack)(&addr, 0) + v16;
  return (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v3 + 12))(&v2->_location_quest_area, &addr, 0)
       + v17
       + 8;
}

//----- (0059A390) --------------------------------------------------------  // acclient.c:452614
int __thiscall CContract::Pack(CContract *this, void **addr, unsigned int size)
{
  CContract *v3; // edi@1
  int v4; // ebp@1
  char *v5; // eax@2

  v3 = this;
  v4 = CContract::GetPackSize(this, 0);
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = 0;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->_contract_id;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_contract_name, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_description, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_description_progress, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_name_npc_start, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_name_npc_end, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_stamped, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_started, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_finished, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_progress, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_timer, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->_questflag_repeat_time, addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->_location_npc_start.vfptr->Pack)(
      &v3->_location_npc_start,
      addr,
      size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->_location_npc_end.vfptr->Pack)(
      &v3->_location_npc_end,
      addr,
      size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->_location_quest_area.vfptr->Pack)(
      &v3->_location_quest_area,
      addr,
      size);
  }
  return v4;
}

//----- (0059A470) --------------------------------------------------------  // acclient.c:452657
int __thiscall CContract::UnPack(CContract *this, void **addr, unsigned int size)
{
  CContract *v3; // edi@1
  int result; // eax@2
  char *v5; // ecx@3
  int v6; // ebx@3
  int v7; // ebx@3
  int v8; // ebx@3
  int v9; // ebx@3
  int v10; // ebx@3
  int v11; // ebx@3
  int v12; // ebx@3
  int v13; // ebx@3
  int v14; // ebx@3
  int v15; // ebx@3
  int v16; // ebx@3
  int v17; // ebx@3
  int v18; // ebx@3

  v3 = this;
  if ( size >= CContract::GetPackSize(this, 0) )
  {
    v3->_version = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v3->_contract_id = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    v6 = AC1Legacy::PStringBase<char>::UnPack(&v3->_contract_name, addr, size) & 1;
    v7 = AC1Legacy::PStringBase<char>::UnPack(&v3->_description, addr, size) & v6;
    v8 = AC1Legacy::PStringBase<char>::UnPack(&v3->_description_progress, addr, size) & v7;
    v9 = AC1Legacy::PStringBase<char>::UnPack(&v3->_name_npc_start, addr, size) & v8;
    v10 = AC1Legacy::PStringBase<char>::UnPack(&v3->_name_npc_end, addr, size) & v9;
    v11 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_stamped, addr, size) & v10;
    v12 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_started, addr, size) & v11;
    v13 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_finished, addr, size) & v12;
    v14 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_progress, addr, size) & v13;
    v15 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_timer, addr, size) & v14;
    v16 = AC1Legacy::PStringBase<char>::UnPack(&v3->_questflag_repeat_time, addr, size) & v15;
    v17 = ((int (__stdcall *)(void **, unsigned int))v3->_location_npc_start.vfptr->UnPack)(addr, size) & v16;
    v18 = ((int (__thiscall *)(int, void **, unsigned int))v3->_location_npc_end.vfptr->UnPack)(
            &v3->_location_npc_end,
            addr,
            size) & v17;
    result = v18 & ((int (__stdcall *)(void **, unsigned int))v3->_location_quest_area.vfptr->UnPack)(addr, size);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0070B010) --------------------------------------------------------  // acclient.c:798194
void sub_70B010()
{
  flt_871164 = 1000.0 + 1.0;
}

//----- (0070B030) --------------------------------------------------------  // acclient.c:798200
void sub_70B030()
{
  flt_871168 = 24.0 * 8.0;
}

//----- (0070B050) --------------------------------------------------------  // acclient.c:798206
void sub_70B050()
{
  flt_87116C = 24.0 * 0.5;
}

//----- (0070B070) --------------------------------------------------------  // acclient.c:798212
int sub_70B070()
{
  return atexit(nullsub_1431);
}

