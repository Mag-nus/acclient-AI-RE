/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Bitfield32PropertyValue
   Object     : ENGINE\property\Bitfield32PropertyValue.obj
   Functions  : 5
   Addresses  : 0042ABB0 - 006C5670 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042ABB0) --------------------------------------------------------  // acclient.c:103721
char __thiscall Bitfield32PropertyValue::FromFileNode(Bitfield32PropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // esi@1
  int v4; // edi@1
  BasePropertyDesc *v5; // ecx@2
  unsigned int v6; // eax@2
  char v7; // bl@4
  char result; // al@6
  PStringBase<char> v9; // [sp-4h] [bp-10h]@7

  v3 = _node;
  v4 = (int)this;
  if ( _node )
  {
    v5 = _desc;
    v6 = _desc->m_propertyType;
    _node = 0;
    switch ( v6 )
    {
      case 9u:
      case 0xFu:
      case 0x10u:
      case 0x14u:
        if ( !EnumeratedBitfield<unsigned __int64>::InitByDataID(
                (EnumeratedBitfield<unsigned __int64> *)&_node,
                (IDClass<_tagDataID,32,0>)_desc->m_data) )
          goto LABEL_7;
        v7 = EnumeratedBitfield<unsigned long>::FromFileNode(
               (EnumeratedBitfield<unsigned long> *)&_node,
               v4 + 8,
               v3,
               (unsigned int *)(v4 + 8));
        if ( _node )
          ((void (*)(void))_node->vfptr[5].__vecDelDtor)();
        result = v7;
        break;
      default:
LABEL_7:
        v9.m_charbuffer = (PSRefBufferCharData<char> *)v5;
        PStringBase<char>::PStringBase<char>(&v9, "There was a problem with the emp");
        PFileNode::ReportError(v4, v3, v9);
        if ( _node )
          ((void (*)(void))_node->vfptr[5].__vecDelDtor)();
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}

//----- (0042AC60) --------------------------------------------------------  // acclient.c:103776
char __thiscall Bitfield32PropertyValue::ToFileNode(Bitfield32PropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // esi@1
  int v4; // edi@1
  BasePropertyDesc *v5; // ecx@2
  unsigned int v6; // eax@2
  char v7; // bl@4
  char result; // al@6
  PStringBase<char> v9; // [sp-4h] [bp-10h]@7

  v3 = _node;
  v4 = (int)this;
  if ( _node )
  {
    v5 = _desc;
    v6 = _desc->m_propertyType;
    _node = 0;
    switch ( v6 )
    {
      case 9u:
      case 0xFu:
      case 0x10u:
      case 0x14u:
        if ( !EnumeratedBitfield<unsigned __int64>::InitByDataID(
                (EnumeratedBitfield<unsigned __int64> *)&_node,
                (IDClass<_tagDataID,32,0>)_desc->m_data) )
          goto LABEL_7;
        v7 = EnumeratedBitfield<unsigned long>::ToFileNode(
               (EnumeratedBitfield<unsigned long> *)&_node,
               *(_DWORD *)(v4 + 8),
               v3);
        if ( _node )
          ((void (*)(void))_node->vfptr[5].__vecDelDtor)();
        result = v7;
        break;
      default:
LABEL_7:
        v9.m_charbuffer = (PSRefBufferCharData<char> *)v5;
        PStringBase<char>::PStringBase<char>(&v9, "There was a problem with the emp");
        PFileNode::ReportError(v4, v3, v9);
        if ( _node )
          ((void (*)(void))_node->vfptr[5].__vecDelDtor)();
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    result = 0;
  }
  return result;
}

//----- (0042AD10) --------------------------------------------------------  // acclient.c:103830
PStringBase<char> *__thiscall PStringBaseArray<char>::join(PStringBaseArray<char> *this, PStringBase<char> *result, PStringBase<char> *i_separator)
{
  PStringBaseArray<char> *v3; // esi@1
  unsigned int v4; // eax@1
  const char **v5; // esi@2
  int i; // edi@2
  int v7; // ecx@3
  int v8; // ecx@5
  const char *v9; // esi@8
  int v10; // eax@8
  PSRefBufferCharData<char> *v11; // eax@10
  char *v12; // esi@10
  PStringBase<char> retval; // [sp+Ch] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v4 = v3->m_num;
  if ( v4 )
  {
    v5 = (const char **)v3->m_data;
    for ( i = (int)&v5[v4 - 1]; v5 != (const char **)i; ++v5 )
    {
      v7 = *((_DWORD *)*v5 - 1);
      if ( v7 != 1 )
        PStringBase<char>::append_n_chars(&retval, *v5, v7 - 1);
      v8 = *(_DWORD *)&i_separator->m_charbuffer[-1].m_data[12];
      if ( v8 != 1 )
        PStringBase<char>::append_n_chars(&retval, i_separator->m_charbuffer->m_data, v8 - 1);
    }
    v9 = *v5;
    v10 = *((_DWORD *)v9 - 1);
    if ( v10 != 1 )
      PStringBase<char>::append_n_chars(&retval, v9, v10 - 1);
  }
  v11 = retval.m_charbuffer;
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1]);
  v12 = &retval.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
  return result;
}

//----- (0042ADD0) --------------------------------------------------------  // acclient.c:103875
char __thiscall Bitfield32PropertyValue::GetValueAsString(Bitfield32PropertyValue *this, BasePropertyDesc *i_desc, PStringBase<char> *o_value, bool rawValue)
{
  Bitfield32PropertyValue *v4; // esi@1
  unsigned int v5; // eax@1
  unsigned int v6; // ST00_4@3
  const unsigned __int16 *v7; // eax@3
  char *v8; // esi@3
  char *v9; // esi@6
  char v10; // al@14
  EnumeratedBitfield<unsigned long> empBitfield; // [sp+8h] [bp-14h]@1
  PStringBase<char> result; // [sp+Ch] [bp-10h]@3
  PStringBaseArray<char> strArray; // [sp+10h] [bp-Ch]@3

  v4 = this;
  v5 = i_desc->m_propertyType;
  empBitfield.m_enumMapper.m_object = 0;
  switch ( v5 )
  {
    case 9u:
    case 0xFu:
    case 0x10u:
    case 0x14u:
      if ( !EnumeratedBitfield<unsigned __int64>::InitByDataID(
              (EnumeratedBitfield<unsigned __int64> *)&empBitfield,
              (IDClass<_tagDataID,32,0>)i_desc->m_data) )
      {
        if ( empBitfield.m_enumMapper.m_object )
          ((void (*)(void))empBitfield.m_enumMapper.m_object->vfptr->Release)();
        goto LABEL_17;
      }
      v6 = v4->m_value;
      strArray.m_data = 0;
      strArray.m_sizeAndDeallocate = 0;
      strArray.m_num = 0;
      EnumeratedBitfield<unsigned long>::InqStrings(&empBitfield, v6, &strArray);
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_desc, " ");
      v7 = (const unsigned __int16 *)PStringBaseArray<char>::join(&strArray, &result, (PStringBase<char> *)&i_desc);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)o_value, v7);
      v8 = &result.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      v9 = (char *)&i_desc[-1].m_bRecorded;
      if ( !InterlockedDecrement((volatile LONG *)&i_desc[-1].m_nMinElements) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)strArray.m_data )
        PStringBase<unsigned short>::vector_deleting_destructor(strArray.m_data, 3u);
      if ( empBitfield.m_enumMapper.m_object )
        ((void (*)(void))empBitfield.m_enumMapper.m_object->vfptr->Release)();
      v10 = 1;
      break;
    default:
LABEL_17:
      v10 = 0;
      break;
  }
  return v10;
}

//----- (006C5670) --------------------------------------------------------  // acclient.c:733702
int _E1_19()
{
  return atexit(_E2_19);
}

