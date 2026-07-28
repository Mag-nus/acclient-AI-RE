/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EnumPropertyValue
   Object     : ENGINE\property\EnumPropertyValue.obj
   Functions  : 11
   Addresses  : 0042B250 - 006C56D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042B250) --------------------------------------------------------  // acclient.c:104140
char __cdecl FileNodeUtils::GetNameAsEnumByDID(PFileNode *_node, IDClass<_tagDataID,32,0> _mapDID, unsigned int *_retvalue)
{
  PSRefBufferCharData<char> *v3; // esi@1
  char v4; // bl@1
  PSRefBufferCharData<char> *v5; // ecx@1
  int v6; // esi@3
  int v7; // edx@5
  PStringBase<char> v9; // [sp-8h] [bp-1Ch]@1
  signed int v10; // [sp-4h] [bp-18h]@2
  PStringBase<char> strName; // [sp+10h] [bp-4h]@1

  strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PFileNode::GetNameAsPString(_node, (int)InterlockedIncrement, &strName);
  v3 = strName.m_charbuffer;
  v4 = 1;
  v9.m_charbuffer = strName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&strName.m_charbuffer[-1]);
  if ( !EnumMapper::GetEnumByDID(_mapDID, v9, _retvalue) )
  {
    v10 = (signed int)v3;
    v9.m_charbuffer = v5;
    PStringBase<char>::PStringBase<char>(&v9, "invalid emp value '%s'");
    PFileNode::ReportError((int)InterlockedIncrement, _node, v9);
    v4 = 0;
  }
  v6 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
  {
    v7 = *(_DWORD *)v6;
    v10 = 1;
    (*(void (__thiscall **)(int, signed int))v7)(v6, 1);
  }
  return v4;
}

//----- (0042B2E0) --------------------------------------------------------  // acclient.c:104177
char __usercall FileNodeUtils::GetLeafAsEnumByDID@<al>(int a1@<edi>, PFileNode *_node, IDClass<_tagDataID,32,0> _mapDID, unsigned int *_retvalue)
{
  int v4; // eax@1
  PSRefBufferCharData<char> *v5; // ecx@1
  char result; // al@2
  PStringBase<char> v7; // [sp-4h] [bp-8h]@3

  v4 = PFileNode::GetLeaf(_node);
  if ( v4 )
  {
    result = FileNodeUtils::GetNameAsEnumByDID((PFileNode *)v4, _mapDID, _retvalue);
  }
  else
  {
    v7.m_charbuffer = v5;
    PStringBase<char>::PStringBase<char>(&v7, "Expecting a leaf node");
    PFileNode::ReportError(a1, _node, v7);
    result = 0;
  }
  return result;
}

//----- (0042B320) --------------------------------------------------------  // acclient.c:104200
char __cdecl FileNodeUtils::SetNameAsEnumByDID(PFileNode *_node, IDClass<_tagDataID,32,0> _mapDID, unsigned int _value)
{
  char v3; // bl@1
  PStringBase<char> v4; // esi@2
  volatile LONG *v5; // edi@2
  int v6; // esi@2
  char *v7; // esi@6
  PStringBase<char> name; // [sp+10h] [bp-4h]@1

  name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( EnumMapper::GetStringByDID(_mapDID, _value, &name) )
  {
    v4.m_charbuffer = name.m_charbuffer;
    v5 = (volatile LONG *)&name.m_charbuffer[-1];
    InterlockedIncrement((volatile LONG *)&name.m_charbuffer[-1]);
    InterlockedIncrement(v5);
    PFileNode::SetNameAsPString(_node, v4);
    v6 = (int)&v4.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v3 = 1;
  }
  v7 = &name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return v3;
}

//----- (0042B3C0) --------------------------------------------------------  // acclient.c:104231
PFileNode *__cdecl FileNodeUtils::MakeSubNodeAsEnumByDID(PFileNode *_node, IDClass<_tagDataID,32,0> _mapDID, unsigned int _value)
{
  PFileNode *v3; // eax@1
  PFileNode *v4; // esi@1
  PFileNode *result; // eax@3

  v3 = (PFileNode *)((int (__thiscall *)(PFileNode *))_node->vfptr[1].__vecDelDtor)(_node);
  v4 = v3;
  if ( !v3 || FileNodeUtils::SetNameAsEnumByDID(v3, _mapDID, _value) )
  {
    result = v4;
  }
  else
  {
    PFileNode::RemoveSubNodePtr(_node, v4);
    result = 0;
  }
  return result;
}

//----- (0042B400) --------------------------------------------------------  // acclient.c:104252
char __thiscall EnumPropertyValue::FromFileNode(EnumPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // edi@1
  EnumPropertyValue *v4; // ebp@1
  void *v5; // esi@3
  unsigned int v6; // ebx@3
  int v7; // eax@3
  PSRefBufferCharData<char> *v8; // ecx@3
  int v9; // esi@6
  int v10; // eax@8
  char result; // al@9
  char v12; // bl@12
  int v13; // eax@13
  char v14; // bl@15
  PStringBase<char> v15; // [sp-4h] [bp-18h]@6
  IDClass<_tagDataID,32,0> didMPR; // [sp+10h] [bp-4h]@11

  v3 = _node;
  v4 = this;
  if ( _node )
  {
    switch ( _desc->m_propertyType )
    {
      case 9u:
      case 0xFu:
      case 0x10u:
      case 0x14u:
        v5 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v6 = _desc->m_data;
        _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v7 = PFileNode::GetLeaf(v3);
        if ( !v7 )
          goto LABEL_6;
        if ( PFileNode::GetNameAsPString((PFileNode *)v7, (int)v3, (PStringBase<char> *)&_node) )
        {
          if ( _node[-1].user_data == 1 )
          {
            v4->m_value = 0;
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
            result = 1;
          }
          else
          {
            DBCache::GetDIDFromEnumStatic(&didMPR, 15, 2);
            if ( v6 == didMPR.id )
            {
              PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_desc);
              v13 = PFileNode::GetLeaf(v3);
              if ( v13 )
                PFileNode::GetNameAsPString((PFileNode *)v13, (int)v3, (PStringBase<char> *)&_desc);
              v14 = MasterProperty::InqPropertyNameEnumStatic((PStringBase<char> *)&_desc, &v4->m_value);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_desc);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
              result = v14;
            }
            else
            {
              v12 = FileNodeUtils::GetLeafAsEnumByDID((int)v3, v3, (IDClass<_tagDataID,32,0>)v6, &v4->m_value);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
              result = v12;
            }
          }
          return result;
        }
        v5 = _node;
LABEL_6:
        v15.m_charbuffer = v8;
        PStringBase<char>::PStringBase<char>(&v15, "Expected string.");
        PFileNode::ReportError((int)v3, v3, v15);
        v9 = (int)((char *)v5 - 20);
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
        {
          if ( v9 )
          {
            v10 = *(_DWORD *)v9;
            v15.m_charbuffer = (PSRefBufferCharData<char> *)1;
            (*(void (__thiscall **)(int, signed int))v10)(v9, 1);
          }
        }
        break;
      default:
        return 0;
    }
  }
  return 0;
}

//----- (0042B570) --------------------------------------------------------  // acclient.c:104341
char __thiscall EnumPropertyValue::ToFileNode(EnumPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // edi@1
  EnumPropertyValue *v4; // esi@1
  PSRefBufferCharData<char> *v6; // ecx@7
  PFileNode *v7; // eax@8
  PFileNode **v8; // ecx@8
  PStringBase<char> v9; // [sp-4h] [bp-Ch]@8

  v3 = _node;
  v4 = this;
  if ( !_node )
    return 0;
  if ( !this->m_value )
  {
    v9.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
    PFileNode::MakeSubNode(v3, v9);
    return 1;
  }
  if ( !BasePropertyDesc::InqDataID(_desc, (IDClass<_tagDataID,32,0> *)&_node) )
    return 0;
  DBCache::GetDIDFromEnumStatic((IDClass<_tagDataID,32,0> *)&_desc, 15, 2);
  if ( (BasePropertyDesc *)_node != _desc )
  {
    if ( !FileNodeUtils::MakeSubNodeAsEnumByDID(v3, (IDClass<_tagDataID,32,0>)_node, v4->m_value) )
      return 0;
    return 1;
  }
  _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( MasterProperty::InqPropertyNameStringStatic(v4->m_value, (PStringBase<char> *)&_node) )
  {
    v9.m_charbuffer = v6;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)&v9,
      (PStringBase<char> *)&_node);
    v7 = PFileNode::MakeSubNode(v3, v9);
    v8 = &_node;
    if ( v7 )
    {
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_node);
      return 1;
    }
  }
  else
  {
    v8 = &_node;
  }
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)v8);
  return 0;
}

//----- (0042B660) --------------------------------------------------------  // acclient.c:104395
char __thiscall EnumPropertyValue::GetValueAsString(EnumPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  EnumPropertyValue *v4; // esi@1
  char v5; // bl@1
  char *v6; // esi@6
  PStringBase<char> strValue; // [sp+0h] [bp-4h]@1

  strValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = BasePropertyDesc::InqPropertyEnum(_desc, v4->m_value, &strValue);
  if ( v5 )
  {
    if ( rawValue )
      PStringBase<char>::sprintf(_value, "%s", strValue.m_charbuffer);
    else
      PStringBase<char>::sprintf(_value, "%s [0x%08X]", strValue.m_charbuffer, v4->m_value);
  }
  else
  {
    PStringBase<char>::sprintf(_value, "Unable to map Enum [0x%08X] to a valid string.", v4->m_value);
  }
  v6 = &strValue.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return v5;
}

//----- (006C56A0) --------------------------------------------------------  // acclient.c:733720
int _E73_20()
{
  return atexit(_E74_23);
}

//----- (006C56B0) --------------------------------------------------------  // acclient.c:733726
int _E76_13()
{
  return atexit(_E77_41);
}

//----- (006C56C0) --------------------------------------------------------  // acclient.c:733732
int _E79_13()
{
  return atexit(_E80_15);
}

//----- (006C56D0) --------------------------------------------------------  // acclient.c:733738
int _E1_22()
{
  return atexit(_E2_22);
}

