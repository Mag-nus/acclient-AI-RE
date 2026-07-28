/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CharacterTitleTable
   Object     : AC\accharacter\CharacterTitleTable.obj
   Functions  : 7
   Addresses  : 005C6E20 - 0070F590 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005C6E20) --------------------------------------------------------  // acclient.c:498046
int __thiscall CharacterTitleTable::GetPackSize(CharacterTitleTable *this)
{
  PackObjVtbl *v1; // eax@1
  void *dummy; // [sp+0h] [bp-4h]@1

  dummy = this;
  v1 = this->mTitleList.vfptr;
  dummy = 0;
  return ((int (__thiscall *)(PackObjVtbl **, void **, _DWORD))v1->Pack)(&this->mTitleList.vfptr, &dummy, 0) + 8;
}

//----- (005C6E40) --------------------------------------------------------  // acclient.c:498058
unsigned int __thiscall CharacterTitleTable::Pack(CharacterTitleTable *this, void **addr, unsigned int size)
{
  CharacterTitleTable *v3; // esi@1
  unsigned int v4; // edi@1
  char *v5; // ebx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = 1;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->mDisplayTitle;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->mTitleList.vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (005C6E90) --------------------------------------------------------  // acclient.c:498079
int __thiscall CharacterTitleTable::UnPack(CharacterTitleTable *this, void **addr, unsigned int size)
{
  CharacterTitleTable *v3; // esi@1
  int result; // eax@2
  char *v5; // ecx@3

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    v5 = (char *)*addr + 4;
    *addr = v5;
    v3->mDisplayTitle = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->mTitleList.vfptr->UnPack)(addr, size);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005C6ED0) --------------------------------------------------------  // acclient.c:498103
int __cdecl CharacterTitleTable::GetCharacterTitleFromID(unsigned int i_titleID, PStringBase<unsigned short> *i_strTitle)
{
  char *v2; // esi@3
  PSRefBufferCharData<char> *v4; // esi@7
  unsigned int v5; // eax@7
  const unsigned __int16 *v6; // eax@9
  char *v7; // esi@9
  char *v8; // esi@12
  PStringBase<char> titleIDStr; // [sp+4h] [bp-98h]@2
  PStringBase<unsigned short> result; // [sp+8h] [bp-94h]@9
  StringInfo siTitleText; // [sp+Ch] [bp-90h]@7

  if ( !i_titleID )
    return 0;
  titleIDStr.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !EnumMapper::GetString(0x10000006u, i_titleID, &titleIDStr) )
  {
    v2 = &titleIDStr.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&titleIDStr.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(char *, signed int))v2)(v2, 1);
    }
    return 0;
  }
  StringInfo::StringInfo(&siTitleText);
  v4 = titleIDStr.m_charbuffer;
  v5 = *(_DWORD *)&titleIDStr.m_charbuffer[-1].m_data[8];
  if ( v5 == -1 )
  {
    v5 = compute_str_hash(titleIDStr.m_charbuffer->m_data);
    *(_DWORD *)&v4[-1].m_data[8] = v5;
  }
  StringInfo::SetStringIDandTableEnum(&siTitleText, v5, 268435463);
  v6 = (const unsigned __int16 *)StringInfo::GetString(&siTitleText, &result, 0);
  PStringBase<unsigned short>::operator=(i_strTitle, v6);
  v7 = (char *)&result.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  StringInfo::~StringInfo(&siTitleText);
  v8 = &titleIDStr.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&titleIDStr.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  return 1;
}

//----- (005C6FE0) --------------------------------------------------------  // acclient.c:498151
void __thiscall CharacterTitleTable::CharacterTitleTable(CharacterTitleTable *this)
{
  this->vfptr = (PackObjVtbl *)&CharacterTitleTable::vftable;
  this->mDisplayTitle = 0;
  this->mTitleList._head = 0;
  this->mTitleList._tail = 0;
  this->mTitleList._num_elements = 0;
  this->mTitleList.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->mTitleList.vfptr = (AC1Legacy::List<unsigned long>Vtbl *)&PList<unsigned long>::vftable;
  this->mTitleList.vfptr = (PackObjVtbl *)&PList<unsigned long>::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7A4114: using guessed type void *PList<unsigned long>::vftable;
// 7A6F94: using guessed type int (__thiscall *CharacterTitleTable::vftable)(void *, char);
// 7A7388: using guessed type int (__thiscall *PList<unsigned long>::vftable)(void *, char);

//----- (005C7010) --------------------------------------------------------  // acclient.c:498168
int __thiscall CharacterTitleTable::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  AC1Legacy::List<unsigned long>::operator=((List<SkillRecord *> *)(this + 8), a2 + 8);
  return v2;
}

//----- (0070F590) --------------------------------------------------------  // acclient.c:802531
int sub_70F590()
{
  return atexit(nullsub_1709);
}

