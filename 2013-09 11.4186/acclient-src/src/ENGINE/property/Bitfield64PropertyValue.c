/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Bitfield64PropertyValue
   Object     : ENGINE\property\Bitfield64PropertyValue.obj
   Functions  : 4
   Addresses  : 0042AF00 - 006C5680 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042AF00) --------------------------------------------------------  // acclient.c:103934
char __thiscall Bitfield64PropertyValue::FromFileNode(Bitfield64PropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
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
        v7 = EnumeratedBitfield<unsigned __int64>::FromFileNode(
               (EnumeratedBitfield<unsigned __int64> *)&_node,
               v4 + 8,
               v3,
               (unsigned __int64 *)(v4 + 8));
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

//----- (0042AFB0) --------------------------------------------------------  // acclient.c:103989
char __thiscall Bitfield64PropertyValue::ToFileNode(Bitfield64PropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // edi@1
  Bitfield64PropertyValue *v4; // esi@1
  BasePropertyDesc *v5; // ecx@2
  unsigned int v6; // eax@2
  char v7; // bl@4
  char result; // al@6
  PStringBase<char> v9; // [sp-4h] [bp-10h]@7

  v3 = _node;
  v4 = this;
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
        v7 = EnumeratedBitfield<unsigned __int64>::ToFileNode(
               (EnumeratedBitfield<unsigned __int64> *)&_node,
               v4->m_value,
               v3);
        if ( _node )
          ((void (*)(void))_node->vfptr[5].__vecDelDtor)();
        result = v7;
        break;
      default:
LABEL_7:
        v9.m_charbuffer = (PSRefBufferCharData<char> *)v5;
        PStringBase<char>::PStringBase<char>(&v9, "There was a problem with the emp");
        PFileNode::ReportError((int)v3, v3, v9);
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

//----- (0042B060) --------------------------------------------------------  // acclient.c:104043
char __thiscall Bitfield64PropertyValue::GetValueAsString(Bitfield64PropertyValue *this, BasePropertyDesc *i_desc, PStringBase<char> *o_value, bool rawValue)
{
  Bitfield64PropertyValue *v4; // esi@1
  unsigned int v5; // eax@1
  unsigned __int64 v6; // ST00_8@3
  const unsigned __int16 *v7; // eax@3
  char *v8; // esi@3
  char *v9; // esi@6
  char v10; // al@14
  EnumeratedBitfield<unsigned __int64> empBitfield; // [sp+8h] [bp-14h]@1
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
      if ( !EnumeratedBitfield<unsigned __int64>::InitByDataID(&empBitfield, (IDClass<_tagDataID,32,0>)i_desc->m_data) )
      {
        if ( empBitfield.m_enumMapper.m_object )
          ((void (*)(void))empBitfield.m_enumMapper.m_object->vfptr->Release)();
        goto LABEL_17;
      }
      v6 = v4->m_value;
      strArray.m_data = 0;
      strArray.m_sizeAndDeallocate = 0;
      strArray.m_num = 0;
      EnumeratedBitfield<unsigned __int64>::InqStrings(&empBitfield, v6, &strArray);
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

//----- (006C5680) --------------------------------------------------------  // acclient.c:733708
int _E1_20()
{
  return atexit(_E2_20);
}

