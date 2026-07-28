/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QuestDefDB
   Object     : AC\acquest\QuestDefDB.obj
   Functions  : 8
   Addresses  : 004BF9F0 - 007104B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004BF9F0) --------------------------------------------------------  // acclient.c:242086
signed int QuestDefDB::GetDBOType()
{
  return 268435466;
}

//----- (004FDAD0) --------------------------------------------------------  // acclient.c:297823
unsigned int __thiscall BadData::Pack(QuestDefDB *this, void **addr, unsigned int size)
{
  QuestDefDB *v3; // edi@1
  int v4; // eax@1
  unsigned int v5; // esi@1
  QuestDefDB *v7; // [sp+0h] [bp-4h]@1

  v7 = this;
  v3 = this;
  v4 = *(_DWORD *)&this->m_bLoaded;
  v7 = 0;
  v5 = (*(int (__thiscall **)(bool *, int *, _DWORD))(v4 + 12))(&this->m_bLoaded, &v7, 0);
  if ( size >= v5 )
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v3->m_bLoaded + 12))(&v3->m_bLoaded, addr, size);
  return v5;
}

//----- (005D2880) --------------------------------------------------------  // acclient.c:510861
int __thiscall QuestDefDB::UnPack(QuestDefDB *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  void *v4; // ebp@1
  QuestDefDB *v5; // esi@1
  int v6; // eax@1
  unsigned int v7; // eax@1
  unsigned int v8; // ebx@1

  v3 = addr;
  v4 = *addr;
  v5 = this;
  v6 = *(_DWORD *)&this->m_bLoaded;
  addr = 0;
  v7 = (*(int (__thiscall **)(bool *, void ***, _DWORD))(v6 + 12))(&this->m_bLoaded, &addr, 0);
  v8 = size;
  if ( size < v7
    || !(*(int (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)&v5->m_bLoaded + 16))(&v5->m_bLoaded, v3, size) )
    return 0;
  if ( v8 < (_BYTE *)*v3 - (_BYTE *)v4 )
  {
    *v3 = v4;
    return 0;
  }
  return 1;
}

//----- (005D28E0) --------------------------------------------------------  // acclient.c:510889
void __thiscall QuestDefDB::QuestDefDB(QuestDefDB *this, IDClass<_tagDataID,32,0> did)
{
  QuestDefDB *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, did);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = (int)&v2->_defs;
  v2->vfptr = (InterfaceVtbl *)&QuestDefDB::vftable;
  v2->vfptr = (PackObjVtbl *)&QuestDefDB::vftable;
  *(_DWORD *)v3 = &PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 32;
  *(_DWORD *)(v3 + 16) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&v2->_defs);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4F98: using guessed type int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable)(void *, char);
// 7E8998: using guessed type void *QuestDefDB::vftable;
// 7E89B0: using guessed type __int32 (__stdcall *QuestDefDB::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005D2930) --------------------------------------------------------  // acclient.c:510913
SerializeUsingPackDBObj *__thiscall QuestDefDB::vector_deleting_destructor(QuestDefDB *this, unsigned int a2)
{
  return QuestDefDB::vector_deleting_destructor((QuestDefDB *)((char *)this - 48), a2);
}

//----- (005D2950) --------------------------------------------------------  // acclient.c:510919
void __cdecl QuestDefDB::Allocator()
{
  QuestDefDB *v0; // eax@1

  v0 = (QuestDefDB *)operator new(0x50u);
  if ( v0 )
    QuestDefDB::QuestDefDB(v0, stru_8EFFDC);
}

//----- (005D2970) --------------------------------------------------------  // acclient.c:510929
SerializeUsingPackDBObj *__thiscall QuestDefDB::vector_deleting_destructor(QuestDefDB *this, unsigned int a2)
{
  SerializeUsingPackDBObj *v2; // esi@1

  v2 = (SerializeUsingPackDBObj *)this;
  PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::~PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>(&this->_defs);
  SerializeUsingPackDBObj::~SerializeUsingPackDBObj(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (007104B0) --------------------------------------------------------  // acclient.c:803567
int sub_7104B0()
{
  return atexit(nullsub_1847);
}

