/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellComponentBase
   Object     : AC\acmagic\SpellComponentBase.obj
   Functions  : 13
   Addresses  : 005BBD20 - 0070EA70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BBD20) --------------------------------------------------------  // acclient.c:486919
unsigned int __thiscall SpellComponentBase::Pack(SpellComponentBase *this, void **addr, unsigned int size)
{
  SpellComponentBase *v3; // edi@1
  int v4; // ebx@1
  unsigned int v5; // ebp@1
  void **v6; // esi@2
  char *v7; // ecx@2
  char *v8; // eax@2
  char *v9; // edx@2
  char *v10; // ecx@2
  void *v12; // [sp+10h] [bp-4h]@1

  v3 = this;
  v12 = 0;
  v4 = AC1Legacy::PStringBase<char>::Pack(&this->_name, &v12, 0);
  v5 = v4 + AC1Legacy::PStringBase<char>::Pack(&v3->_text, &v12, 0) + 24;
  if ( size >= v5 )
  {
    v6 = addr;
    AC1Legacy::PStringBase<char>::Pack(&v3->_name, addr, size);
    *(_DWORD *)*addr = v3->_category;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_iconID.id;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->_type;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->_gesture;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(float *)v10 = v3->_time;
    *v6 = (char *)*v6 + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->_text, addr, size);
    *(float *)*addr = v3->_CDM;
    *v6 = (char *)*v6 + 4;
  }
  return v5;
}

//----- (005BBDD0) --------------------------------------------------------  // acclient.c:486961
void __thiscall SpellComponentBase::Init(SpellComponentBase *this)
{
  SpellComponentBase *v1; // esi@1

  v1 = this;
  AC1Legacy::PStringBase<char>::set(&this->_name, &name);
  v1->_category = 8;
  v1->_iconID.id = stru_8EF540.id;
  v1->_type = 0;
  v1->_gesture = 0;
  LODWORD(v1->_time) = 0;
  AC1Legacy::PStringBase<char>::set(&v1->_text, &name);
  LODWORD(v1->_CDM) = 0;
}

//----- (005BBE10) --------------------------------------------------------  // acclient.c:486977
int __thiscall SpellComponentBase::UnPack(SpellComponentBase *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  SpellComponentBase *v4; // edi@1
  int v5; // ebx@1
  unsigned int v6; // ecx@1
  unsigned int v7; // ebx@1
  int v8; // edx@2
  unsigned int v9; // ecx@2
  int v10; // ecx@2
  int v11; // eax@2
  int v12; // eax@2
  void *start; // [sp+10h] [bp-4h]@1

  v3 = addr;
  v4 = this;
  start = *addr;
  addr = 0;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->_name, (void **)&addr, 0);
  v6 = v5 + AC1Legacy::PStringBase<char>::Pack(&v4->_text, (void **)&addr, 0) + 24;
  v7 = size;
  if ( size < v6 )
    return 0;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_name, v3, size);
  v4->_category = *(_DWORD *)*v3;
  v8 = (int)((char *)*v3 + 4);
  *v3 = (void *)v8;
  v9 = *(_DWORD *)v8;
  *v3 = (void *)(v8 + 4);
  v4->_iconID.id = v9;
  v4->_type = *(_DWORD *)*v3;
  v10 = (int)((char *)*v3 + 4);
  *v3 = (void *)v10;
  v4->_gesture = *(_DWORD *)v10;
  v11 = (int)((char *)*v3 + 4);
  *v3 = (void *)v11;
  LODWORD(v4->_time) = *(_DWORD *)v11;
  *v3 = (char *)*v3 + 4;
  AC1Legacy::PStringBase<char>::UnPack(&v4->_text, v3, v7);
  LODWORD(v4->_CDM) = *(_DWORD *)*v3;
  v12 = (_BYTE *)*v3 + 4 - (_BYTE *)start;
  *v3 = (char *)*v3 + 4;
  if ( v7 < v12 )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (005BBEE0) --------------------------------------------------------  // acclient.c:487028
AC1Legacy::PStringBase<char> *__thiscall SpellComponentBase::InqName(SpellComponentBase *this, AC1Legacy::PStringBase<char> *result)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  char *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  AC1Legacy::PStringBase<char> n; // [sp+10h] [bp-4h]@1

  n.m_buffer = this->_name.m_buffer;
  InterlockedIncrement((volatile LONG *)&n.m_buffer->m_cRef);
  AC1Legacy::PStringBase<char>::break_reference(&n);
  v2 = n.m_buffer;
  v3 = n.m_buffer->m_data;
  v4 = (AC1Legacy::PSRefBuffer<char> *)((char *)n.m_buffer + n.m_buffer->m_len + 19);
  if ( (AC1Legacy::PSRefBuffer<char> *)((char *)n.m_buffer + 20) != v4 )
  {
    do
    {
      *v3 = 16 * *v3 | ((unsigned __int8)*v3 >> 4);
      ++v3;
    }
    while ( (AC1Legacy::PSRefBuffer<char> *)v3 != v4 );
  }
  result->m_buffer = v2;
  InterlockedIncrement((volatile LONG *)&v2->m_cRef);
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  return result;
}

//----- (0070E9B0) --------------------------------------------------------  // acclient.c:801597
int sub_70E9B0()
{
  return atexit(nullsub_1572);
}

//----- (0070E9C0) --------------------------------------------------------  // acclient.c:801603
int _E4_6()
{
  return atexit(_E5_6);
}

//----- (0070E9D0) --------------------------------------------------------  // acclient.c:801609
int _E7_6()
{
  Outside_CellID_6.id = Invalid_CellID_6.id + 1;
  return atexit(_E8_6);
}

//----- (0070E9F0) --------------------------------------------------------  // acclient.c:801616
int _E10_5()
{
  In_Limbo_CellID_5.id = Outside_CellID_6.id + 1;
  return atexit(_E11_5);
}

//----- (0070EA10) --------------------------------------------------------  // acclient.c:801623
int _E13_5()
{
  First_Interior_CellID_5.id = In_Limbo_CellID_5.id + 1;
  return atexit(_E14_5);
}

//----- (0070EA30) --------------------------------------------------------  // acclient.c:801630
int _E16_5()
{
  Last_Interior_CellID_5.id = Invalid_CellID_6.id - 1;
  return atexit(_E17_5);
}

//----- (0070EA50) --------------------------------------------------------  // acclient.c:801637
int _E21_7()
{
  return atexit(_E22_7);
}

//----- (0070EA60) --------------------------------------------------------  // acclient.c:801643
int _E40_7()
{
  return atexit(_E41_7);
}

//----- (0070EA70) --------------------------------------------------------  // acclient.c:801649
int _E43_10()
{
  return atexit(_E44_10);
}

