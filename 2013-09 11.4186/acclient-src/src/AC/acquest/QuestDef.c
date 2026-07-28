/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : QuestDef
   Object     : AC\acquest\QuestDef.obj
   Functions  : 3
   Addresses  : 005D2740 - 005D2810 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D2740) --------------------------------------------------------  // acclient.c:510780
unsigned int __thiscall QuestDef::Pack(QuestDef *this, void **addr, unsigned int size)
{
  QuestDef *v3; // edi@1
  AC1Legacy::PStringBase<char> *v4; // ebx@1
  unsigned int v5; // esi@1
  char *v6; // ecx@2
  void *v8; // [sp+0h] [bp-4h]@1

  v3 = this;
  v4 = &this->_fullname;
  v8 = 0;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->_fullname, &v8, 0) + 8;
  if ( size >= v5 )
  {
    *(_DWORD *)*addr = v3->_mindelta;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_maxsolves;
    *addr = (char *)*addr + 4;
    AC1Legacy::PStringBase<char>::Pack(v4, addr, size);
  }
  return v5;
}

//----- (005D27A0) --------------------------------------------------------  // acclient.c:510805
void __thiscall QuestDef::QuestDef(QuestDef *this)
{
  QuestDef *v1; // edi@1
  char *v2; // esi@1
  volatile LONG *v3; // ST00_4@1
  int v4; // esi@1
  int v5; // eax@1
  int i; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&QuestDef::vftable;
  v2 = (char *)&this->_fullname;
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->_fullname.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->_mindelta = 0;
  v1->_maxsolves = -1;
  AC1Legacy::PStringBase<char>::set(&v1->_fullname, &name);
  AC1Legacy::PStringBase<char>::break_reference(&v1->_fullname);
  v4 = *(_DWORD *)v2;
  v5 = v4 + 20;
  for ( i = *(_DWORD *)(v4 + 8) + v4 + 19; v5 != i; ++v5 )
    *(_BYTE *)v5 = 16 * *(_BYTE *)v5 | ((unsigned __int16)*(_BYTE *)v5 >> 4);
}
// 7E4FAC: using guessed type int (__thiscall *QuestDef::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D2810) --------------------------------------------------------  // acclient.c:510833
int __thiscall QuestDef::UnPack(QuestDef *this, void **addr, unsigned int size)
{
  QuestDef *v3; // esi@1
  AC1Legacy::PStringBase<char> *v4; // edi@1
  int result; // eax@2
  char *v6; // ecx@3
  void *v7; // [sp+0h] [bp-4h]@1

  v3 = this;
  v4 = &this->_fullname;
  v7 = 0;
  if ( size >= AC1Legacy::PStringBase<char>::Pack(&this->_fullname, &v7, 0) + 8 )
  {
    v3->_mindelta = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->_maxsolves = *(_DWORD *)v6;
    *addr = (char *)*addr + 4;
    result = AC1Legacy::PStringBase<char>::UnPack(v4, addr, size) & 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

