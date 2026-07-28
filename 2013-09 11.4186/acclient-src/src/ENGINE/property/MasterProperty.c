/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MasterProperty
   Object     : ENGINE\property\MasterProperty.obj
   Functions  : 362
   Addresses  : 00417340 - 00727980 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00417340) --------------------------------------------------------  // acclient.c:83995
void __thiscall BaseProperty::BaseProperty(BaseProperty *this)
{
  this->m_pcPropertyDesc = 0;
  this->m_pcPropertyValue = 0;
}

//----- (00423180) --------------------------------------------------------  // acclient.c:94925
char __thiscall MasterProperty::InqPropertyNameString(MasterProperty *this, unsigned int _name_enum, PStringBase<char> *_name_str)
{
  return EnumMapper::GetString((unsigned int)&this->m_emapper, (PStringBase<char> *)_name_enum, _name_str);
}

//----- (00423190) --------------------------------------------------------  // acclient.c:94931
unsigned int __thiscall ReferenceCountTemplate<1048576,1>::Release(ReferenceCountTemplate<1048576,1> *this)
{
  unsigned int result; // eax@1

  result = this->m_cRef - 1;
  this->m_cRef = result;
  if ( !result )
  {
    ((void (__stdcall *)(signed int))this->vfptr->__vecDelDtor)(1);
    result = 0;
  }
  return result;
}

//----- (004231B0) --------------------------------------------------------  // acclient.c:94946
void __thiscall BaseProperty::~BaseProperty(BaseProperty *this)
{
  BaseProperty *v1; // esi@1
  BasePropertyDesc *v2; // ecx@1
  bool v3; // zf@2
  BasePropertyValue *v4; // ecx@5

  v1 = this;
  v2 = this->m_pcPropertyDesc;
  if ( v2 )
  {
    v3 = v2->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->m_pcPropertyDesc = 0;
  }
  v4 = v1->m_pcPropertyValue;
  if ( v4 )
  {
    v3 = v4->m_cRef-- == 1;
    if ( v3 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v1->m_pcPropertyValue = 0;
  }
}

//----- (004231F0) --------------------------------------------------------  // acclient.c:94973
char __thiscall DataFilePropertyValue::InqDataID(StringTokenPropertyValue *this, unsigned int *_value)
{
  *_value = this->m_value;
  return 1;
}

//----- (00423200) --------------------------------------------------------  // acclient.c:94980
char __thiscall TriStatePropertyValue::SetTriState(StringTokenPropertyValue *this, const unsigned int _value)
{
  this->m_value = _value;
  return 1;
}

//----- (00423210) --------------------------------------------------------  // acclient.c:94987
int __thiscall Bitfield32PropertyValue::SetValue(Bitfield32PropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[56].__vecDelDtor)(&this->m_value);
}

//----- (00423230) --------------------------------------------------------  // acclient.c:94993
bool __thiscall Bitfield32PropertyValue::Compare(Bitfield32PropertyValue *this, BasePropertyValue *_p)
{
  Bitfield32PropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[56].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00423270) --------------------------------------------------------  // acclient.c:95007
char __thiscall Bitfield32PropertyValue::InqLessThan(Bitfield32PropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  Bitfield32PropertyValue *v3; // esi@1
  char result; // al@2

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[56].__vecDelDtor)(&i_pcRHS) )
  {
    *o_rbLessThan = v3->m_value < (unsigned int)i_pcRHS;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004232B0) --------------------------------------------------------  // acclient.c:95026
void __thiscall Bitfield32PropertyValue::operator=&(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    v2->m_value &= (unsigned int)i_rcRhs;
}

//----- (004232E0) --------------------------------------------------------  // acclient.c:95036
void __thiscall Bitfield32PropertyValue::on(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    v2->m_value |= (unsigned int)i_rcRhs;
}

//----- (00423310) --------------------------------------------------------  // acclient.c:95046
void __thiscall Bitfield32PropertyValue::operator=^(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    v2->m_value ^= (unsigned int)i_rcRhs;
}

//----- (00423340) --------------------------------------------------------  // acclient.c:95056
bool __thiscall Bitfield32PropertyValue::operator!=(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value != (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00423370) --------------------------------------------------------  // acclient.c:95070
bool __thiscall Bitfield32PropertyValue::operator==(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value == (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004233A0) --------------------------------------------------------  // acclient.c:95084
bool __thiscall Bitfield32PropertyValue::contains(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    result = ((unsigned int)i_rcRhs & v2->m_value) == (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004233E0) --------------------------------------------------------  // acclient.c:95098
void __thiscall Bitfield32PropertyValue::off(Bitfield32PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield32PropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[56].__vecDelDtor)(&i_rcRhs) )
    v2->m_value &= ~(unsigned int)i_rcRhs;
}

//----- (00423410) --------------------------------------------------------  // acclient.c:95108
void __thiscall Bitfield32PropertyValue::toggle(Bitfield32PropertyValue *this)
{
  this->m_value = ~this->m_value;
}

//----- (00423420) --------------------------------------------------------  // acclient.c:95114
BasePropertyValue *__thiscall Bitfield32PropertyValue::Copy(Bitfield32PropertyValue *this)
{
  Bitfield32PropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&Bitfield32PropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 795C50: using guessed type int (__thiscall *Bitfield32PropertyValue::vftable)(void *, char);

//----- (00423450) --------------------------------------------------------  // acclient.c:95138
char __thiscall TimeStampPropertyValue::InqTimeStamp(TimeStampPropertyValue *this, long double *_value)
{
  *(_QWORD *)_value = *(_QWORD *)&this->m_value;
  return 1;
}

//----- (00423470) --------------------------------------------------------  // acclient.c:95145
char __thiscall Bitfield64PropertyValue::SetBitfield64(TimeStampPropertyValue *this, const long double _value)
{
  this->m_value = _value;
  return 1;
}

//----- (00423490) --------------------------------------------------------  // acclient.c:95152
int __thiscall Bitfield64PropertyValue::SetValue(Bitfield64PropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[58].__vecDelDtor)(&this->m_value);
}

//----- (004234B0) --------------------------------------------------------  // acclient.c:95158
bool __thiscall Bitfield64PropertyValue::Compare(Bitfield64PropertyValue *this, BasePropertyValue *_p)
{
  Bitfield64PropertyValue *v2; // esi@1
  bool result; // al@3
  unsigned __int64 nValue; // [sp+4h] [bp-8h]@2

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))_p->vfptr[58].__vecDelDtor)(&nValue) )
    result = v2->m_value == nValue;
  else
    result = 0;
  return result;
}

//----- (00423500) --------------------------------------------------------  // acclient.c:95173
char __thiscall Bitfield64PropertyValue::InqLessThan(Bitfield64PropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  Bitfield64PropertyValue *v3; // esi@1
  char result; // al@3
  unsigned __int64 nOtherValue; // [sp+4h] [bp-8h]@1

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[58].__vecDelDtor)(&nOtherValue) )
  {
    if ( v3->m_value >= nOtherValue )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00423560) --------------------------------------------------------  // acclient.c:95201
void __thiscall Bitfield64PropertyValue::operator=&(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  int v3; // eax@2
  unsigned __int64 fRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&fRhsValue) )
  {
    v3 = HIDWORD(v2->m_value);
    LODWORD(v2->m_value) &= fRhsValue;
    HIDWORD(v2->m_value) = HIDWORD(fRhsValue) & v3;
  }
}

//----- (004235A0) --------------------------------------------------------  // acclient.c:95217
void __thiscall Bitfield64PropertyValue::operator=^(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  int v3; // eax@2
  unsigned __int64 fRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&fRhsValue) )
  {
    v3 = HIDWORD(v2->m_value);
    LODWORD(v2->m_value) ^= fRhsValue;
    HIDWORD(v2->m_value) = HIDWORD(fRhsValue) ^ v3;
  }
}

//----- (004235E0) --------------------------------------------------------  // acclient.c:95233
bool __thiscall Bitfield64PropertyValue::operator!=(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  bool result; // al@2
  unsigned __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value != iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00423630) --------------------------------------------------------  // acclient.c:95248
bool __thiscall Bitfield64PropertyValue::operator==(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  bool result; // al@2
  unsigned __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value == iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00423680) --------------------------------------------------------  // acclient.c:95263
bool __thiscall Bitfield64PropertyValue::contains(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  bool result; // al@2
  unsigned __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&iRhsValue) )
    result = (iRhsValue & v2->m_value) == iRhsValue;
  else
    result = 0;
  return result;
}

//----- (004236E0) --------------------------------------------------------  // acclient.c:95278
void __thiscall Bitfield64PropertyValue::operator=|(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  int v3; // eax@2
  unsigned __int64 fRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned __int64 *))i_rcRhs->vfptr[58].__vecDelDtor)(&fRhsValue) )
  {
    v3 = HIDWORD(v2->m_value);
    LODWORD(v2->m_value) |= fRhsValue;
    HIDWORD(v2->m_value) = HIDWORD(fRhsValue) | v3;
  }
}

//----- (00423720) --------------------------------------------------------  // acclient.c:95294
void __thiscall Bitfield64PropertyValue::off(Bitfield64PropertyValue *this, BasePropertyValue *i_rcRhs)
{
  Bitfield64PropertyValue *v2; // esi@1
  int v3; // eax@2
  unsigned __int64 fRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[58].__vecDelDtor)(&fRhsValue) )
  {
    v3 = ~HIDWORD(fRhsValue) & HIDWORD(v2->m_value);
    LODWORD(v2->m_value) &= ~(_DWORD)fRhsValue;
    HIDWORD(v2->m_value) = v3;
  }
}

//----- (00423760) --------------------------------------------------------  // acclient.c:95310
void __thiscall Bitfield64PropertyValue::toggle(Bitfield64PropertyValue *this)
{
  int v1; // edx@1

  v1 = ~HIDWORD(this->m_value);
  LODWORD(this->m_value) = ~LODWORD(this->m_value);
  HIDWORD(this->m_value) = v1;
}

//----- (00423780) --------------------------------------------------------  // acclient.c:95320
BasePropertyValue *__thiscall Bitfield64PropertyValue::Copy(Bitfield64PropertyValue *this)
{
  Bitfield64PropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0x10u);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)LODWORD(v1->m_value);
    result[1].m_cRef = HIDWORD(v1->m_value);
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&Bitfield64PropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 795D90: using guessed type int (__thiscall *Bitfield64PropertyValue::vftable)(void *, char);

//----- (004237B0) --------------------------------------------------------  // acclient.c:95345
void __thiscall LongIntegerPropertyValue::Serialize(LongIntegerPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Serializer::SerializePrimitive((long double *)&this->m_value, io_archive);
}

//----- (004237D0) --------------------------------------------------------  // acclient.c:95351
char __thiscall BoolPropertyValue::InqBool(BoolPropertyValue *this, bool *_value)
{
  *_value = this->m_value;
  return 1;
}

//----- (004237E0) --------------------------------------------------------  // acclient.c:95358
char __thiscall BoolPropertyValue::SetBool(BoolPropertyValue *this, const bool _value)
{
  this->m_value = _value;
  return 1;
}

//----- (004237F0) --------------------------------------------------------  // acclient.c:95365
int __thiscall BoolPropertyValue::SetValue(BoolPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[28].__vecDelDtor)(&this->m_value);
}

//----- (00423810) --------------------------------------------------------  // acclient.c:95371
bool __thiscall BoolPropertyValue::Compare(BoolPropertyValue *this, BasePropertyValue *_p)
{
  BoolPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[28].__vecDelDtor)(&_p) )
    result = v2->m_value == (_BYTE)_p;
  else
    result = 0;
  return result;
}

//----- (00423850) --------------------------------------------------------  // acclient.c:95385
char __thiscall BoolPropertyValue::InqLessThan(BoolPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  BoolPropertyValue *v3; // esi@1
  char result; // al@2

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[28].__vecDelDtor)(&i_pcRHS) )
  {
    *o_rbLessThan = v3->m_value < (unsigned __int8)i_pcRHS;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00423890) --------------------------------------------------------  // acclient.c:95404
bool __thiscall BoolPropertyValue::operator!=(BoolPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  BoolPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[28].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value != (_BYTE)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004238C0) --------------------------------------------------------  // acclient.c:95418
bool __thiscall BoolPropertyValue::operator==(BoolPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  BoolPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[28].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value == (_BYTE)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004238F0) --------------------------------------------------------  // acclient.c:95432
void __thiscall BoolPropertyValue::operator=&(BoolPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  BoolPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[28].__vecDelDtor)(&i_rcRhs) )
    v2->m_value &= (unsigned __int8)i_rcRhs;
}

//----- (00423920) --------------------------------------------------------  // acclient.c:95442
void __thiscall BoolPropertyValue::operator=|(BoolPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  BoolPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[28].__vecDelDtor)(&i_rcRhs) )
    v2->m_value |= (unsigned __int8)i_rcRhs;
}

//----- (00423950) --------------------------------------------------------  // acclient.c:95452
void __thiscall BoolPropertyValue::operator=^(BoolPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  BoolPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[28].__vecDelDtor)(&i_rcRhs) )
    v2->m_value ^= (unsigned __int8)i_rcRhs;
}

//----- (00423980) --------------------------------------------------------  // acclient.c:95462
void __thiscall BoolPropertyValue::toggle(BoolPropertyValue *this)
{
  this->m_value = this->m_value == 0;
}

//----- (00423990) --------------------------------------------------------  // acclient.c:95468
BasePropertyValue *__thiscall BoolPropertyValue::Copy(BoolPropertyValue *this)
{
  BoolPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  bool v3; // cl@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&BoolPropertyValue::vftable;
    LOBYTE(result[1].vfptr) = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 795ED0: using guessed type int (__thiscall *BoolPropertyValue::vftable)(void *, char);

//----- (004239C0) --------------------------------------------------------  // acclient.c:95492
void __thiscall BoolPropertyValue::Serialize(BoolPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Serializer::SerializeObject(&this->m_value, io_archive);
}

//----- (004239E0) --------------------------------------------------------  // acclient.c:95498
char __thiscall BoolPropertyValue::ToFileNode(BoolPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // eax@1
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // edx@2
  PFileNode *v5; // eax@2
  char result; // al@3
  bool _nodea; // [sp+8h] [bp+8h]@2

  v3 = _node;
  if ( _node
    && (v4 = _node->vfptr,
        _nodea = this->m_value,
        (v5 = (PFileNode *)((int (__thiscall *)(PFileNode *))v4[1].__vecDelDtor)(v3)) != 0) )
  {
    PFileNode::SetNameAsBool(v5, _nodea);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00423A10) --------------------------------------------------------  // acclient.c:95523
void __thiscall PFileNode::SetNameAsBool(PFileNode *this, bool i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(8u);
  if ( v4 )
  {
    *(_DWORD *)v4 = &FileNodeName_Bool::vftable;
    *((_BYTE *)v4 + 4) = i_name;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 796010: using guessed type int (__thiscall *FileNodeName_Bool::vftable)(void *, char);

//----- (00423A60) --------------------------------------------------------  // acclient.c:95549
IFileNodeName *__thiscall FileNodeName_Bool::Clone(FileNodeName_Bool *this)
{
  FileNodeName_Bool *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Bool::vftable;
    LOBYTE(result[1].vfptr) = v1->m_name;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796010: using guessed type int (__thiscall *FileNodeName_Bool::vftable)(void *, char);

//----- (00423A90) --------------------------------------------------------  // acclient.c:95570
FileNodeName_Int32 *__thiscall FileNodeName_UInt32::scalar_deleting_destructor(FileNodeName_Int32 *this, unsigned int a2)
{
  FileNodeName_Int32 *v2; // esi@1

  v2 = this;
  this->vfptr = (IFileNodeNameVtbl *)&IFileNodeName::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79602C: using guessed type int (__thiscall *IFileNodeName::vftable)(void *, char);

//----- (00423AB0) --------------------------------------------------------  // acclient.c:95583
void __thiscall ColorPropertyValue::ColorPropertyValue(ColorPropertyValue *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ColorPropertyValue::vftable;
  this->m_value = RGBAColor_Black_4;
}
// 796048: using guessed type int (__thiscall *ColorPropertyValue::vftable)(void *, char);

//----- (00423AF0) --------------------------------------------------------  // acclient.c:95592
char __thiscall ColorPropertyValue::FromFileNode(ColorPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  char result; // al@2

  if ( _node )
    result = RGBAColor::FromFileNode(&this->m_value, _node, 1, 1);
  else
    result = 0;
  return result;
}

//----- (00423B10) --------------------------------------------------------  // acclient.c:95604
bool __thiscall ColorPropertyValue::ToFileNode(ColorPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  bool result; // al@2

  if ( _node )
    result = RGBAColor::ToFileNode(&this->m_value, _node) != 0;
  else
    result = 0;
  return result;
}

//----- (00423B30) --------------------------------------------------------  // acclient.c:95616
char __thiscall ColorPropertyValue::InqColor(ColorPropertyValue *this, RGBAColor *_value)
{
  char *v2; // ecx@1

  v2 = (char *)&this->m_value;
  LODWORD(_value->r) = *(_DWORD *)v2;
  LODWORD(_value->g) = *((_DWORD *)v2 + 1);
  LODWORD(_value->b) = *((_DWORD *)v2 + 2);
  LODWORD(_value->a) = *((_DWORD *)v2 + 3);
  return 1;
}

//----- (00423B60) --------------------------------------------------------  // acclient.c:95629
char __thiscall ColorPropertyValue::SetColor(ColorPropertyValue *this, RGBAColor *_value)
{
  this->m_value = *_value;
  return 1;
}

//----- (00423B90) --------------------------------------------------------  // acclient.c:95636
int __thiscall ColorPropertyValue::SetValue(ColorPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[38].__vecDelDtor)(&this->m_value);
}

//----- (00423BB0) --------------------------------------------------------  // acclient.c:95642
BasePropertyValue *__thiscall ColorPropertyValue::Copy(ColorPropertyValue *this)
{
  ColorPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  int v3; // esi@2
  BasePropertyValue *v4; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0x18u);
  if ( result )
  {
    v3 = (int)&v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ColorPropertyValue::vftable;
    v4 = result + 1;
    v4->vfptr = *(ReferenceCountTemplate<1048576,1>Vtbl **)v3;
    v4->m_cRef = *(_DWORD *)(v3 + 4);
    v4[1].vfptr = *(ReferenceCountTemplate<1048576,1>Vtbl **)(v3 + 8);
    v4[1].m_cRef = *(_DWORD *)(v3 + 12);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796048: using guessed type int (__thiscall *ColorPropertyValue::vftable)(void *, char);

//----- (00423BF0) --------------------------------------------------------  // acclient.c:95671
void __thiscall ColorPropertyValue::Serialize(ColorPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  RGBAColor::Serialize(&this->m_value, io_archive);
}

//----- (00423C00) --------------------------------------------------------  // acclient.c:95677
bool __thiscall ColorPropertyValue::Compare(ColorPropertyValue *this, BasePropertyValue *_p)
{
  ColorPropertyValue *v2; // esi@1
  bool result; // al@3
  RGBAColor nValue; // [sp+4h] [bp-10h]@2

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(RGBAColor *))_p->vfptr[38].__vecDelDtor)(&nValue) )
    result = RGBAColor::operator==(&v2->m_value, &nValue);
  else
    result = 0;
  return result;
}

//----- (00423C40) --------------------------------------------------------  // acclient.c:95692
BOOL __thiscall RGBAColor::operator==(RGBAColor *this, RGBAColor *c)
{
  return fabs(this->r - c->r) <= 0.00019999999
      && fabs(this->g - c->g) <= 0.00019999999
      && fabs(this->b - c->b) <= 0.00019999999
      && fabs(this->a - c->a) <= 0.00019999999;
}

//----- (00423CB0) --------------------------------------------------------  // acclient.c:95701
char __thiscall ColorPropertyValue::InqLessThan(ColorPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  ColorPropertyValue *v3; // esi@1
  unsigned int v4; // esi@2
  char result; // al@2
  RGBAColor cValue; // [sp+4h] [bp-10h]@1

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[38].__vecDelDtor)(&cValue) )
  {
    v4 = RGBAColor::GetColor32(&v3->m_value);
    *o_rbLessThan = v4 < RGBAColor::GetColor32(&cValue);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00423D00) --------------------------------------------------------  // acclient.c:95723
unsigned int __thiscall RGBAColor::GetColor32(RGBAColor *this)
{
  return (((unsigned int)(unsigned __int64)(this->g * 255.0) | (((unsigned int)(unsigned __int64)(this->r * 255.0) | ((unsigned int)(unsigned __int64)(this->a * 255.0) << 8)) << 8)) << 8) | (unsigned __int64)(this->b * 255.0);
}

//----- (00423D50) --------------------------------------------------------  // acclient.c:95729
int __thiscall DataFilePropertyValue::SetValue(DataFilePropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[44].__vecDelDtor)(&this->m_value);
}

//----- (00423D70) --------------------------------------------------------  // acclient.c:95735
BasePropertyValue *__thiscall DataFilePropertyValue::Copy(DataFilePropertyValue *this)
{
  DataFilePropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value.id;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&DataFilePropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796190: using guessed type int (__thiscall *DataFilePropertyValue::vftable)(void *, char);

//----- (00423DA0) --------------------------------------------------------  // acclient.c:95759
BOOL __thiscall DataFilePropertyValue::HasValidData(DataFilePropertyValue *this)
{
  return this->m_value.id != INVALID_DID_16.id;
}

//----- (00423DC0) --------------------------------------------------------  // acclient.c:95765
void __thiscall EnumPropertyValue::Serialize(StringTokenPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  StringTokenPropertyValue *v3; // edi@1
  unsigned int v4; // eax@1

  v3 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_value;
    else
      v3->m_value = *(_DWORD *)v4;
  }
}

//----- (00423E00) --------------------------------------------------------  // acclient.c:95783
bool __thiscall DataFilePropertyValue::Compare(DataFilePropertyValue *this, BasePropertyValue *_p)
{
  DataFilePropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[44].__vecDelDtor)(&_p) )
    result = v2->m_value.id == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00423E30) --------------------------------------------------------  // acclient.c:95797
bool __thiscall DataFilePropertyValue::operator!=(DataFilePropertyValue *this, BasePropertyValue *i_rcRhs)
{
  DataFilePropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[44].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value.id != (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00423E60) --------------------------------------------------------  // acclient.c:95811
bool __thiscall DataFilePropertyValue::operator==(DataFilePropertyValue *this, BasePropertyValue *i_rcRhs)
{
  DataFilePropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[44].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value.id == (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00423EA0) --------------------------------------------------------  // acclient.c:95831
int __thiscall EnumPropertyValue::SetValue(EnumPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[42].__vecDelDtor)(&this->m_value);
}

//----- (00423EC0) --------------------------------------------------------  // acclient.c:95837
bool __thiscall EnumPropertyValue::Compare(EnumPropertyValue *this, BasePropertyValue *_p)
{
  EnumPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[42].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00423F00) --------------------------------------------------------  // acclient.c:95851
bool __thiscall EnumPropertyValue::operator!=(EnumPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  EnumPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[42].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value != (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00423F30) --------------------------------------------------------  // acclient.c:95865
bool __thiscall EnumPropertyValue::operator==(EnumPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  EnumPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[42].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value == (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00423F60) --------------------------------------------------------  // acclient.c:95879
BasePropertyValue *__thiscall EnumPropertyValue::Copy(EnumPropertyValue *this)
{
  EnumPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&EnumPropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7962D0: using guessed type int (__thiscall *EnumPropertyValue::vftable)(void *, char);

//----- (00423F90) --------------------------------------------------------  // acclient.c:95903
int __thiscall FloatPropertyValue::SetValue(FloatPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[34].__vecDelDtor)(&this->m_value);
}

//----- (00423FB0) --------------------------------------------------------  // acclient.c:95909
char __thiscall FloatPropertyValue::InqLessThan(FloatPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  FloatPropertyValue *v3; // esi@1
  char result; // al@3

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[34].__vecDelDtor)(&i_pcRHS) )
  {
    if ( v3->m_value >= (double)*(float *)&i_pcRHS )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00424000) --------------------------------------------------------  // acclient.c:95936
void __thiscall FloatPropertyValue::operator+=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    v2->m_value = *(float *)&i_rcRhs + v2->m_value;
}

//----- (00424030) --------------------------------------------------------  // acclient.c:95946
void __thiscall FloatPropertyValue::operator-=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    v2->m_value = v2->m_value - *(float *)&i_rcRhs;
}

//----- (00424060) --------------------------------------------------------  // acclient.c:95956
void __thiscall FloatPropertyValue::operator*=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    v2->m_value = *(float *)&i_rcRhs * v2->m_value;
}

//----- (00424090) --------------------------------------------------------  // acclient.c:95966
void __thiscall FloatPropertyValue::operator=/(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    v2->m_value = v2->m_value / *(float *)&i_rcRhs;
}

//----- (004240C0) --------------------------------------------------------  // acclient.c:95976
bool __thiscall FloatPropertyValue::operator>(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value > (double)*(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424100) --------------------------------------------------------  // acclient.c:95990
bool __thiscall FloatPropertyValue::operator>=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value >= (double)*(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424140) --------------------------------------------------------  // acclient.c:96004
bool __thiscall FloatPropertyValue::operator<(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value < (double)*(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424180) --------------------------------------------------------  // acclient.c:96018
bool __thiscall FloatPropertyValue::operator<=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value <= (double)*(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004241C0) --------------------------------------------------------  // acclient.c:96032
bool __thiscall FloatPropertyValue::operator!=(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value != *(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424200) --------------------------------------------------------  // acclient.c:96046
bool __thiscall FloatPropertyValue::operator==(FloatPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[34].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value == *(float *)&i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424240) --------------------------------------------------------  // acclient.c:96060
BasePropertyValue *__thiscall FloatPropertyValue::Copy(FloatPropertyValue *this)
{
  FloatPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  double v3; // st7@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = v1->m_value;
    result->m_cRef = 1;
    *(float *)&result[1].vfptr = v3;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&FloatPropertyValue::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796410: using guessed type int (__thiscall *FloatPropertyValue::vftable)(void *, char);

//----- (00424270) --------------------------------------------------------  // acclient.c:96084
void __thiscall FileNodeName_Bool::Serialize(FileNodeName_Bool *this, Archive *io_archive)
{
  Serializer::SerializeObject(&this->m_name, io_archive);
}

//----- (00424290) --------------------------------------------------------  // acclient.c:96090
bool __thiscall FloatPropertyValue::Compare(FloatPropertyValue *this, BasePropertyValue *_p)
{
  FloatPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( *(float *)&_p != 0.0
    && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[34].__vecDelDtor)(&_p) )
    result = fabs(v2->m_value - *(float *)&_p) <= 0.00019999999;
  else
    result = 0;
  return result;
}

//----- (004242E0) --------------------------------------------------------  // acclient.c:96105
int __thiscall InstanceIDPropertyValue::SetValue(InstanceIDPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[50].__vecDelDtor)(&this->m_value);
}

//----- (00424300) --------------------------------------------------------  // acclient.c:96111
bool __thiscall InstanceIDPropertyValue::Compare(InstanceIDPropertyValue *this, BasePropertyValue *_p)
{
  InstanceIDPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[50].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00424340) --------------------------------------------------------  // acclient.c:96125
BasePropertyValue *__thiscall InstanceIDPropertyValue::Copy(InstanceIDPropertyValue *this)
{
  InstanceIDPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&InstanceIDPropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796550: using guessed type int (__thiscall *InstanceIDPropertyValue::vftable)(void *, char);

//----- (00424370) --------------------------------------------------------  // acclient.c:96149
WaveformPropertyValue *__thiscall TriStatePropertyValue::scalar_deleting_destructor(WaveformPropertyValue *this, unsigned int a2)
{
  WaveformPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);

//----- (00424390) --------------------------------------------------------  // acclient.c:96162
int __thiscall IntegerPropertyValue::SetValue(IntegerPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[30].__vecDelDtor)(&this->m_value);
}

//----- (004243B0) --------------------------------------------------------  // acclient.c:96168
bool __thiscall IntegerPropertyValue::Compare(IntegerPropertyValue *this, BasePropertyValue *_p)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[30].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (004243F0) --------------------------------------------------------  // acclient.c:96182
char __thiscall IntegerPropertyValue::InqLessThan(IntegerPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  IntegerPropertyValue *v3; // esi@1
  char result; // al@2

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[30].__vecDelDtor)(&i_pcRHS) )
  {
    *o_rbLessThan = v3->m_value < (signed int)i_pcRHS;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00424430) --------------------------------------------------------  // acclient.c:96201
void __thiscall IntegerPropertyValue::operator+=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    v2->m_value += (int)i_rcRhs;
}

//----- (00424460) --------------------------------------------------------  // acclient.c:96211
void __thiscall IntegerPropertyValue::operator-=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    v2->m_value -= (int)i_rcRhs;
}

//----- (00424490) --------------------------------------------------------  // acclient.c:96221
void __thiscall IntegerPropertyValue::operator*=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    v2->m_value *= (_DWORD)i_rcRhs;
}

//----- (004244C0) --------------------------------------------------------  // acclient.c:96231
void __thiscall IntegerPropertyValue::operator=/(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    v2->m_value /= (signed int)i_rcRhs;
}

//----- (004244F0) --------------------------------------------------------  // acclient.c:96241
bool __thiscall IntegerPropertyValue::operator>(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value > (signed int)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424520) --------------------------------------------------------  // acclient.c:96255
bool __thiscall IntegerPropertyValue::operator>=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value >= (signed int)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424550) --------------------------------------------------------  // acclient.c:96269
bool __thiscall IntegerPropertyValue::operator<(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value < (signed int)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424580) --------------------------------------------------------  // acclient.c:96283
bool __thiscall IntegerPropertyValue::operator<=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value <= (signed int)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004245B0) --------------------------------------------------------  // acclient.c:96297
bool __thiscall IntegerPropertyValue::operator!=(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value != (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (004245E0) --------------------------------------------------------  // acclient.c:96311
bool __thiscall IntegerPropertyValue::operator==(IntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  IntegerPropertyValue *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))i_rcRhs->vfptr[30].__vecDelDtor)(&i_rcRhs) )
    result = v2->m_value == (_DWORD)i_rcRhs;
  else
    result = 0;
  return result;
}

//----- (00424610) --------------------------------------------------------  // acclient.c:96325
BasePropertyValue *__thiscall IntegerPropertyValue::Copy(IntegerPropertyValue *this)
{
  IntegerPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&IntegerPropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796690: using guessed type int (__thiscall *IntegerPropertyValue::vftable)(void *, char);

//----- (00424640) --------------------------------------------------------  // acclient.c:96349
void __thiscall IntegerPropertyValue::Serialize(IntegerPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Serializer::SerializeObject((CliDatError *)&this->m_value, io_archive);
}

//----- (00424660) --------------------------------------------------------  // acclient.c:96355
int __thiscall LongIntegerPropertyValue::SetValue(LongIntegerPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[32].__vecDelDtor)(&this->m_value);
}

//----- (00424680) --------------------------------------------------------  // acclient.c:96361
bool __thiscall LongIntegerPropertyValue::Compare(LongIntegerPropertyValue *this, BasePropertyValue *_p)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@3
  __int64 nValue; // [sp+4h] [bp-8h]@2

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(__int64 *))_p->vfptr[32].__vecDelDtor)(&nValue) )
    result = v2->m_value == nValue;
  else
    result = 0;
  return result;
}

//----- (004246D0) --------------------------------------------------------  // acclient.c:96376
char __thiscall LongIntegerPropertyValue::InqLessThan(LongIntegerPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  LongIntegerPropertyValue *v3; // esi@1
  char result; // al@3
  __int64 nOtherValue; // [sp+4h] [bp-8h]@1

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[32].__vecDelDtor)(&nOtherValue) )
  {
    if ( v3->m_value >= nOtherValue )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00424730) --------------------------------------------------------  // acclient.c:96404
void __thiscall LongIntegerPropertyValue::operator+=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  int v3; // ecx@2
  unsigned __int8 v4; // cf@2
  int v5; // eax@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
  {
    v3 = LODWORD(v2->m_value);
    v4 = __CFADD__((_DWORD)iRhsValue, v3);
    v5 = HIDWORD(v2->m_value);
    LODWORD(v2->m_value) = iRhsValue + v3;
    HIDWORD(v2->m_value) = HIDWORD(iRhsValue) + v4 + v5;
  }
}

//----- (00424770) --------------------------------------------------------  // acclient.c:96424
void __thiscall LongIntegerPropertyValue::operator-=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  unsigned int v3; // ecx@2
  bool v4; // cf@2
  int v5; // eax@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
  {
    v3 = LODWORD(v2->m_value);
    v4 = v3 < (unsigned int)iRhsValue;
    v5 = HIDWORD(v2->m_value);
    LODWORD(v2->m_value) = v3 - iRhsValue;
    HIDWORD(v2->m_value) = v5 - (v4 + HIDWORD(iRhsValue));
  }
}

//----- (004247B0) --------------------------------------------------------  // acclient.c:96444
void __thiscall LongIntegerPropertyValue::operator*=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    v2->m_value *= iRhsValue;
}

//----- (004247F0) --------------------------------------------------------  // acclient.c:96455
void __thiscall LongIntegerPropertyValue::operator=/(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    v2->m_value /= iRhsValue;
}

//----- (00424830) --------------------------------------------------------  // acclient.c:96466
bool __thiscall LongIntegerPropertyValue::operator>(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value > iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00424880) --------------------------------------------------------  // acclient.c:96481
bool __thiscall LongIntegerPropertyValue::operator>=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value >= iRhsValue;
  else
    result = 0;
  return result;
}

//----- (004248D0) --------------------------------------------------------  // acclient.c:96496
bool __thiscall LongIntegerPropertyValue::operator<(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value < iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00424920) --------------------------------------------------------  // acclient.c:96511
bool __thiscall LongIntegerPropertyValue::operator<=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value <= iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00424970) --------------------------------------------------------  // acclient.c:96526
bool __thiscall LongIntegerPropertyValue::operator!=(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value != iRhsValue;
  else
    result = 0;
  return result;
}

//----- (004249C0) --------------------------------------------------------  // acclient.c:96541
bool __thiscall LongIntegerPropertyValue::operator==(LongIntegerPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  LongIntegerPropertyValue *v2; // esi@1
  bool result; // al@2
  __int64 iRhsValue; // [sp+4h] [bp-8h]@1

  v2 = this;
  if ( (unsigned __int8)((int (__stdcall *)(__int64 *))i_rcRhs->vfptr[32].__vecDelDtor)(&iRhsValue) )
    result = v2->m_value == iRhsValue;
  else
    result = 0;
  return result;
}

//----- (00424A10) --------------------------------------------------------  // acclient.c:96556
BasePropertyValue *__thiscall LongIntegerPropertyValue::Copy(LongIntegerPropertyValue *this)
{
  LongIntegerPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0x10u);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)LODWORD(v1->m_value);
    result[1].m_cRef = HIDWORD(v1->m_value);
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&LongIntegerPropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7967D0: using guessed type int (__thiscall *LongIntegerPropertyValue::vftable)(void *, char);

//----- (00424A40) --------------------------------------------------------  // acclient.c:96581
void __cdecl Serializer::SerializePrimitive(long double *io_object, Archive *io_archive)
{
  unsigned int v2; // eax@1

  Archive::CheckAlignment(io_archive, 8u);
  v2 = Archive::GetBytes(io_archive, 8u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *(_QWORD *)v2 = *(_QWORD *)io_object;
    else
      *(_QWORD *)io_object = *(_QWORD *)v2;
  }
}

//----- (00424A80) --------------------------------------------------------  // acclient.c:96597
void __thiscall Frame::Frame(Frame *this)
{
  LODWORD(this->qw) = 1065353216;
  LODWORD(this->qx) = 0;
  LODWORD(this->qy) = 0;
  LODWORD(this->qz) = 0;
  LODWORD(this->m_fOrigin.x) = 0;
  LODWORD(this->m_fOrigin.y) = 0;
  LODWORD(this->m_fOrigin.z) = 0;
  Frame::cache(this);
}

//----- (00424AB0) --------------------------------------------------------  // acclient.c:96610
void __thiscall Position::Position(Position *this)
{
  Position *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->frame;
  v1->vfptr = (PackObjVtbl *)&Position::vftable;
  v1->objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00424AF0) --------------------------------------------------------  // acclient.c:96631
void __thiscall PositionPropertyValue::PositionPropertyValue(PositionPropertyValue *this)
{
  PositionPropertyValue *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&PositionPropertyValue::vftable;
  v2 = (char *)&this->m_value.frame;
  v1->m_value.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->m_value.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 796928: using guessed type int (__thiscall *PositionPropertyValue::vftable)(void *, char);

//----- (00424B30) --------------------------------------------------------  // acclient.c:96655
bool __thiscall PositionPropertyValue::HasValidData(PositionPropertyValue *this)
{
  return Position::IsValid(&this->m_value) != 0;
}

//----- (00424B40) --------------------------------------------------------  // acclient.c:96661
int __thiscall PositionPropertyValue::SetValue(PositionPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[52].__vecDelDtor)(&this->m_value);
}

//----- (00424B60) --------------------------------------------------------  // acclient.c:96667
void __thiscall PositionPropertyValue::Serialize(PositionPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Position::Serialize(&this->m_value, io_archive);
}

//----- (00424B70) --------------------------------------------------------  // acclient.c:96673
bool __thiscall PositionPropertyValue::Compare(PositionPropertyValue *this, BasePropertyValue *_p)
{
  PositionPropertyValue *v2; // esi@1
  bool result; // al@5
  Position nValue; // [sp+4h] [bp-48h]@1

  v2 = this;
  nValue.vfptr = (PackObjVtbl *)&Position::vftable;
  nValue.objcell_id = 0;
  LODWORD(nValue.frame.qw) = 1065353216;
  LODWORD(nValue.frame.qx) = 0;
  LODWORD(nValue.frame.qy) = 0;
  LODWORD(nValue.frame.qz) = 0;
  LODWORD(nValue.frame.m_fOrigin.x) = 0;
  LODWORD(nValue.frame.m_fOrigin.y) = 0;
  LODWORD(nValue.frame.m_fOrigin.z) = 0;
  Frame::cache(&nValue.frame);
  if ( _p && (unsigned __int8)((int (__stdcall *)(Position *))_p->vfptr[52].__vecDelDtor)(&nValue) )
    result = v2->m_value.objcell_id == nValue.objcell_id && Frame::is_equal(&v2->m_value.frame, &nValue.frame);
  else
    result = 0;
  return result;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);

//----- (00424C30) --------------------------------------------------------  // acclient.c:96699
BOOL __thiscall Frame::is_equal(Frame *this, Frame *rhs)
{
  Frame *v2; // esi@1

  v2 = this;
  return (unsigned __int8)Vector3Math::AreEqual(
                            (Vector3 *)&this->m_fOrigin.x,
                            (Vector3 *)&rhs->m_fOrigin.x,
                            0.00019999999)
      && Frame::is_quaternion_equal(v2, rhs);
}

//----- (00424C70) --------------------------------------------------------  // acclient.c:96712
BOOL __thiscall Frame::is_quaternion_equal(Frame *this, Frame *rhs)
{
  return fabs(this->qw - rhs->qw) < 0.00019999999
      && fabs(this->qx - rhs->qx) < 0.00019999999
      && fabs(this->qy - rhs->qy) < 0.00019999999
      && fabs(this->qz - rhs->qz) < 0.00019999999;
}

//----- (00424CE0) --------------------------------------------------------  // acclient.c:96721
BOOL __cdecl Vector3Math::AreEqual(Vector3 *_A, Vector3 *_B, const float _Epsilon)
{
  return fabs(_A->x - _B->x) <= _Epsilon && fabs(_A->y - _B->y) <= _Epsilon && fabs(_A->z - _B->z) <= _Epsilon;
}

//----- (00424D30) --------------------------------------------------------  // acclient.c:96727
PositionPropertyValue *__thiscall PositionPropertyValue::scalar_deleting_destructor(PositionPropertyValue *this, unsigned int a2)
{
  PositionPropertyValue *v2; // esi@1

  v2 = this;
  this->m_value.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);

//----- (00424D60) --------------------------------------------------------  // acclient.c:96742
void __thiscall StringInfoPropertyValue::StringInfoPropertyValue(StringInfoPropertyValue *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringInfoPropertyValue::vftable;
  StringInfo::StringInfo(&this->m_value);
}
// 796A68: using guessed type int (__thiscall *StringInfoPropertyValue::vftable)(void *, char);

//----- (00424D80) --------------------------------------------------------  // acclient.c:96751
char __thiscall StringInfoPropertyValue::InqStringInfo(StringInfoPropertyValue *this, StringInfo *_value)
{
  StringInfo::operator=(_value, (int)&this->m_value);
  return 1;
}

//----- (00424DA0) --------------------------------------------------------  // acclient.c:96758
char __thiscall StringInfoPropertyValue::SetStringInfo(StringInfoPropertyValue *this, StringInfo *_value)
{
  StringInfo::operator=(&this->m_value, (int)_value);
  return 1;
}

//----- (00424DC0) --------------------------------------------------------  // acclient.c:96765
int __thiscall StringInfoPropertyValue::SetValue(StringInfoPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[48].__vecDelDtor)(&this->m_value);
}

//----- (00424DE0) --------------------------------------------------------  // acclient.c:96771
bool __thiscall StringInfoPropertyValue::operator!=(StringInfoPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  StringInfoPropertyValue *v2; // esi@1
  bool v3; // bl@2
  bool result; // al@2
  StringInfo siRhsValue; // [sp+4h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siRhsValue);
  if ( (unsigned __int8)((int (__stdcall *)(StringInfo *))i_rcRhs->vfptr[48].__vecDelDtor)(&siRhsValue) )
  {
    v3 = StringInfo::operator==(&v2->m_value, &siRhsValue) == 0;
    StringInfo::~StringInfo(&siRhsValue);
    result = v3;
  }
  else
  {
    StringInfo::~StringInfo(&siRhsValue);
    result = 0;
  }
  return result;
}

//----- (00424E50) --------------------------------------------------------  // acclient.c:96795
bool __thiscall StringInfoPropertyValue::operator==(StringInfoPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  StringInfoPropertyValue *v2; // esi@1
  bool v3; // bl@2
  bool result; // al@2
  StringInfo siRhsValue; // [sp+4h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&siRhsValue);
  if ( (unsigned __int8)((int (__stdcall *)(StringInfo *))i_rcRhs->vfptr[48].__vecDelDtor)(&siRhsValue) )
  {
    v3 = StringInfo::operator==(&v2->m_value, &siRhsValue);
    StringInfo::~StringInfo(&siRhsValue);
    result = v3;
  }
  else
  {
    StringInfo::~StringInfo(&siRhsValue);
    result = 0;
  }
  return result;
}

//----- (00424EC0) --------------------------------------------------------  // acclient.c:96819
BasePropertyValue *__thiscall StringInfoPropertyValue::Copy(StringInfoPropertyValue *this)
{
  StringInfoPropertyValue *v1; // edi@1
  void *v2; // eax@1
  BasePropertyValue *v3; // esi@1
  BasePropertyValue *result; // eax@2

  v1 = this;
  v2 = operator new(0x98u);
  v3 = (BasePropertyValue *)v2;
  if ( v2 )
  {
    *((_DWORD *)v2 + 1) = 1;
    *(_DWORD *)v2 = &StringInfoPropertyValue::vftable;
    StringInfo::StringInfo((StringInfo *)((char *)v2 + 8), &v1->m_value);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796A68: using guessed type int (__thiscall *StringInfoPropertyValue::vftable)(void *, char);

//----- (00424F00) --------------------------------------------------------  // acclient.c:96845
void __thiscall StringInfoPropertyValue::Serialize(StringInfoPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  StringInfo::Serialize(&this->m_value, io_archive);
}

//----- (00424F10) --------------------------------------------------------  // acclient.c:96851
StringInfoPropertyValue *__thiscall StringInfoPropertyValue::scalar_deleting_destructor(StringInfoPropertyValue *this, unsigned int a2)
{
  StringInfoPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringInfoPropertyValue::vftable;
  StringInfo::~StringInfo(&this->m_value);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 796A68: using guessed type int (__thiscall *StringInfoPropertyValue::vftable)(void *, char);

//----- (00424F40) --------------------------------------------------------  // acclient.c:96867
int __thiscall TriStatePropertyValue::SetValue(TriStatePropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[78].__vecDelDtor)(&this->m_value);
}

//----- (00424F60) --------------------------------------------------------  // acclient.c:96873
bool __thiscall TriStatePropertyValue::Compare(TriStatePropertyValue *this, BasePropertyValue *_p)
{
  TriStatePropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[78].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00424FA0) --------------------------------------------------------  // acclient.c:96887
char __thiscall TriStatePropertyValue::InqLessThan(TriStatePropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  TriStatePropertyValue *v3; // esi@1
  char result; // al@2

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[78].__vecDelDtor)(&i_pcRHS) )
  {
    *o_rbLessThan = v3->m_value < (signed int)i_pcRHS;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00424FE0) --------------------------------------------------------  // acclient.c:96906
BasePropertyValue *__thiscall TriStatePropertyValue::Copy(TriStatePropertyValue *this)
{
  TriStatePropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  ReferenceCountTemplate<1048576,1>Vtbl *v3; // ecx@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0xCu);
  if ( result )
  {
    v3 = (ReferenceCountTemplate<1048576,1>Vtbl *)v1->m_value;
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&TriStatePropertyValue::vftable;
    result[1].vfptr = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796BA8: using guessed type int (__thiscall *TriStatePropertyValue::vftable)(void *, char);

//----- (00425010) --------------------------------------------------------  // acclient.c:96930
void __thiscall TimeStampPropertyValue::TimeStampPropertyValue(TimeStampPropertyValue *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&TimeStampPropertyValue::vftable;
  this->m_value = INVALID_TIME_3;
}
// 796CE8: using guessed type int (__thiscall *TimeStampPropertyValue::vftable)(void *, char);

//----- (00425040) --------------------------------------------------------  // acclient.c:96939
BOOL __thiscall TimeStampPropertyValue::HasValidData(TimeStampPropertyValue *this)
{
  return this->m_value != -1.0;
}

//----- (00425060) --------------------------------------------------------  // acclient.c:96945
int __thiscall TimeStampPropertyValue::SetValue(TimeStampPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[54].__vecDelDtor)(&this->m_value);
}

//----- (00425080) --------------------------------------------------------  // acclient.c:96951
bool __thiscall TimeStampPropertyValue::Compare(TimeStampPropertyValue *this, BasePropertyValue *_p)
{
  TimeStampPropertyValue *v2; // esi@1
  bool result; // al@3
  long double nValue; // [sp+4h] [bp-8h]@2

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(long double *))_p->vfptr[54].__vecDelDtor)(&nValue) )
    result = v2->m_value == nValue;
  else
    result = 0;
  return result;
}

//----- (004250D0) --------------------------------------------------------  // acclient.c:96966
char __thiscall TimeStampPropertyValue::InqLessThan(TimeStampPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  TimeStampPropertyValue *v3; // esi@1
  char result; // al@3
  long double nOtherValue; // [sp+4h] [bp-8h]@1

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[54].__vecDelDtor)(&nOtherValue) )
  {
    if ( v3->m_value >= nOtherValue )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425130) --------------------------------------------------------  // acclient.c:96994
BasePropertyValue *__thiscall TimeStampPropertyValue::Copy(TimeStampPropertyValue *this)
{
  TimeStampPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1
  long double v3; // st7@2

  v1 = this;
  result = (BasePropertyValue *)operator new(0x10u);
  if ( result )
  {
    v3 = v1->m_value;
    result->m_cRef = 1;
    COERCE_LONG_DOUBLE(result[1].vfptr) = v3;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&TimeStampPropertyValue::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796CE8: using guessed type int (__thiscall *TimeStampPropertyValue::vftable)(void *, char);

//----- (00425160) --------------------------------------------------------  // acclient.c:97018
char __thiscall TimeStampPropertyValue::ToFileNode(TimeStampPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // eax@2
  char result; // al@3
  long double i_name; // [sp+0h] [bp-8h]@2

  if ( _node
    && (v3 = (PFileNode *)((int (__cdecl *)(_DWORD, _DWORD))_node->vfptr[1].__vecDelDtor)(
                            LODWORD(this->m_value),
                            HIDWORD(this->m_value))) != 0 )
  {
    PFileNode::SetNameAsDouble(v3, i_name);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004251B0) --------------------------------------------------------  // acclient.c:97040
void __thiscall PFileNode::SetNameAsDouble(PFileNode *this, long double i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = &FileNodeName_Double::vftable;
    *((long double *)v4 + 1) = i_name;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 796E28: using guessed type int (__thiscall *FileNodeName_Double::vftable)(void *, char);

//----- (00425200) --------------------------------------------------------  // acclient.c:97066
IFileNodeName *__thiscall FileNodeName_Double::Clone(FileNodeName_Double *this)
{
  FileNodeName_Double *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(0x10u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Double::vftable;
    result[2].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name);
    result[3].vfptr = (IFileNodeNameVtbl *)HIDWORD(v1->m_name);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796E28: using guessed type int (__thiscall *FileNodeName_Double::vftable)(void *, char);

//----- (00425230) --------------------------------------------------------  // acclient.c:97088
void __thiscall FileNodeName_Double::Serialize(FileNodeName_Double *this, Archive *io_archive)
{
  Serializer::SerializePrimitive(&this->m_name, io_archive);
}

//----- (00425250) --------------------------------------------------------  // acclient.c:97094
void __thiscall VectorPropertyValue::VectorPropertyValue(VectorPropertyValue *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VectorPropertyValue::vftable;
  this->m_value = Vector3_ZeroVector___4;
}
// 796E48: using guessed type int (__thiscall *VectorPropertyValue::vftable)(void *, char);

//----- (00425280) --------------------------------------------------------  // acclient.c:97103
bool __thiscall VectorPropertyValue::FromFileNode(VectorPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  bool result; // al@2

  if ( _node )
    result = Vector3::FromFileNode(&this->m_value, _node);
  else
    result = 0;
  return result;
}

//----- (004252A0) --------------------------------------------------------  // acclient.c:97115
bool __thiscall VectorPropertyValue::ToFileNode(VectorPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  bool result; // al@2

  if ( _node )
    result = Vector3::ToFileNode(&this->m_value, _node) != 0;
  else
    result = 0;
  return result;
}

//----- (004252C0) --------------------------------------------------------  // acclient.c:97127
char __thiscall VectorPropertyValue::InqVector(VectorPropertyValue *this, Vector3 *_value)
{
  char *v2; // ecx@1

  v2 = (char *)&this->m_value;
  LODWORD(_value->x) = *(_DWORD *)v2;
  LODWORD(_value->y) = *((_DWORD *)v2 + 1);
  LODWORD(_value->z) = *((_DWORD *)v2 + 2);
  return 1;
}

//----- (004252E0) --------------------------------------------------------  // acclient.c:97139
char __thiscall VectorPropertyValue::SetVector(VectorPropertyValue *this, Vector3 *_value)
{
  this->m_value = *_value;
  return 1;
}

//----- (00425300) --------------------------------------------------------  // acclient.c:97146
int __thiscall VectorPropertyValue::SetValue(VectorPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[36].__vecDelDtor)(&this->m_value);
}

//----- (00425320) --------------------------------------------------------  // acclient.c:97152
bool __thiscall VectorPropertyValue::Compare(VectorPropertyValue *this, BasePropertyValue *_p)
{
  VectorPropertyValue *v2; // esi@1
  bool result; // al@3
  Vector3 value; // [sp+4h] [bp-Ch]@2

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(Vector3 *))_p->vfptr[36].__vecDelDtor)(&value) )
    result = Vector3Math::AreEqual(&v2->m_value, &value, 0.00019999999);
  else
    result = 0;
  return result;
}

//----- (00425370) --------------------------------------------------------  // acclient.c:97167
char __thiscall VectorPropertyValue::InqLessThan(VectorPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  VectorPropertyValue *v3; // esi@1
  double v4; // st7@2
  unsigned __int8 v6; // c0@2
  unsigned __int8 v7; // c3@2
  char result; // al@3
  Vector3 vOtherValue; // [sp+4h] [bp-Ch]@1

  v3 = this;
  if ( (unsigned __int8)((int (__stdcall *)(Vector3 *))i_pcRHS->vfptr[36].__vecDelDtor)(&vOtherValue) )
  {
    v4 = v3->m_value.z;
    if ( v6 | v7 )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425400) --------------------------------------------------------  // acclient.c:97199
BasePropertyValue *__thiscall VectorPropertyValue::Copy(VectorPropertyValue *this)
{
  VectorPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1

  v1 = this;
  result = (BasePropertyValue *)operator new(0x14u);
  if ( result )
  {
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&VectorPropertyValue::vftable;
    result[1].vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)LODWORD(v1->m_value.x);
    result[1].m_cRef = LODWORD(v1->m_value.y);
    result[2].vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)LODWORD(v1->m_value.z);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796E48: using guessed type int (__thiscall *VectorPropertyValue::vftable)(void *, char);

//----- (00425440) --------------------------------------------------------  // acclient.c:97223
void __thiscall WaveformPropertyValue::WaveformPropertyValue(WaveformPropertyValue *this)
{
  Waveform *v1; // edi@1

  v1 = &this->m_value;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&WaveformPropertyValue::vftable;
  Waveform::Waveform(&this->m_value);
  Waveform::SetDefaults(v1);
}
// 796F88: using guessed type int (__thiscall *WaveformPropertyValue::vftable)(void *, char);

//----- (00425470) --------------------------------------------------------  // acclient.c:97236
bool __thiscall WaveformPropertyValue::FromFileNode(WaveformPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  WaveformPropertyValue *v3; // esi@1
  PFileNode *v4; // eax@2
  bool result; // al@2

  v3 = this;
  if ( _node )
  {
    v4 = (PFileNode *)((int (__stdcall *)(_DWORD))_node->vfptr[3].__vecDelDtor)(0);
    result = Waveform::Parse(&v3->m_value, v4) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004254A0) --------------------------------------------------------  // acclient.c:97256
char __thiscall WaveformPropertyValue::ToFileNode(WaveformPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  char result; // al@2

  if ( _node )
  {
    Waveform::Output(&this->m_value, _node);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004254C0) --------------------------------------------------------  // acclient.c:97273
char __thiscall WaveformPropertyValue::InqWaveform(WaveformPropertyValue *this, Waveform *_value)
{
  Waveform::operator=((int)_value, (int)&this->m_value);
  return 1;
}

//----- (004254E0) --------------------------------------------------------  // acclient.c:97280
int __thiscall Waveform::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  return result;
}

//----- (00425530) --------------------------------------------------------  // acclient.c:97300
char __thiscall WaveformPropertyValue::SetWaveform(WaveformPropertyValue *this, Waveform *_value)
{
  this->m_value = *_value;
  return 1;
}

//----- (00425580) --------------------------------------------------------  // acclient.c:97307
int __thiscall WaveformPropertyValue::SetValue(WaveformPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[46].__vecDelDtor)(&this->m_value);
}

//----- (004255A0) --------------------------------------------------------  // acclient.c:97313
bool __thiscall WaveformPropertyValue::Compare(WaveformPropertyValue *this, BasePropertyValue *_p)
{
  WaveformPropertyValue *v2; // esi@1
  bool result; // al@3
  Waveform value; // [sp+4h] [bp-2Ch]@1

  v2 = this;
  Waveform::Waveform(&value);
  if ( _p && (unsigned __int8)((int (__stdcall *)(Waveform *))_p->vfptr[46].__vecDelDtor)(&value) )
    result = Waveform::operator==(&v2->m_value, &value);
  else
    result = 0;
  return result;
}

//----- (004255F0) --------------------------------------------------------  // acclient.c:97329
BOOL __thiscall Waveform::operator==(Waveform *this, Waveform *_rhs)
{
  return this->type == _rhs->type
      && fabs(this->base - _rhs->base) <= 0.00019999999
      && fabs(this->base_vel - _rhs->base_vel) <= 0.00019999999
      && fabs(this->amplitude - _rhs->amplitude) <= 0.00019999999
      && fabs(this->amplitude_vel - _rhs->amplitude_vel) <= 0.00019999999
      && fabs(this->phase - _rhs->phase) <= 0.00019999999
      && fabs(this->phase_vel - _rhs->phase_vel) <= 0.00019999999
      && fabs(this->frequency - _rhs->frequency) <= 0.00019999999
      && fabs(this->frequency_vel - _rhs->frequency_vel) <= 0.00019999999
      && fabs(this->roughness - _rhs->roughness) <= 0.00019999999
      && fabs(this->roughness_vel - _rhs->roughness_vel) <= 0.00019999999;
}

//----- (004256F0) --------------------------------------------------------  // acclient.c:97345
char __thiscall WaveformPropertyValue::InqLessThan(WaveformPropertyValue *this, BasePropertyValue *i_pcRHS, bool *o_rbLessThan)
{
  WaveformPropertyValue *v3; // esi@1
  char result; // al@3
  Waveform cOtherValue; // [sp+4h] [bp-2Ch]@1

  v3 = this;
  Waveform::Waveform(&cOtherValue);
  if ( (unsigned __int8)((int (__stdcall *)(_DWORD))i_pcRHS->vfptr[46].__vecDelDtor)(&cOtherValue) )
  {
    if ( v3->m_value.base >= (double)cOtherValue.base )
    {
      result = 1;
      *o_rbLessThan = 0;
    }
    else
    {
      result = 1;
      *o_rbLessThan = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425750) --------------------------------------------------------  // acclient.c:97374
BasePropertyValue *__thiscall WaveformPropertyValue::Copy(WaveformPropertyValue *this)
{
  WaveformPropertyValue *v1; // esi@1
  BasePropertyValue *result; // eax@1

  v1 = this;
  result = (BasePropertyValue *)operator new(0x34u);
  if ( result )
  {
    result->m_cRef = 1;
    result->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&WaveformPropertyValue::vftable;
    qmemcpy(&result[1], &v1->m_value, 0x2Cu);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 796F88: using guessed type int (__thiscall *WaveformPropertyValue::vftable)(void *, char);

//----- (00425790) --------------------------------------------------------  // acclient.c:97396
void __thiscall WaveformPropertyValue::Serialize(WaveformPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Waveform::Serialize(&this->m_value, io_archive);
}

//----- (004257A0) --------------------------------------------------------  // acclient.c:97402
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *v2; // esi@1
  HashTableData<unsigned long,BasePropertyDesc *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7970C8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable[3])(void *, char);

//----- (004257E0) --------------------------------------------------------  // acclient.c:97423
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // esi@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7970CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char);

//----- (00425820) --------------------------------------------------------  // acclient.c:97444
void *__thiscall BaseProperty::vector_deleting_destructor(BaseProperty *this, unsigned int a2)
{
  BaseProperty *v2; // esi@1
  BasePropertyValue *v3; // eax@2
  char *v4; // ebp@2
  BaseProperty *v5; // esi@2
  int v6; // eax@2
  int v7; // ebx@3
  BasePropertyDesc *v8; // ecx@4
  bool v9; // zf@5
  BasePropertyValue *v10; // ecx@8
  void *result; // eax@15
  BasePropertyDesc *v12; // ecx@16
  BasePropertyValue *v13; // ecx@20

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].m_pcPropertyValue;
    v4 = (char *)&this[-1].m_pcPropertyValue;
    v5 = &this[(_DWORD)v3];
    v6 = (int)((char *)&v3[-1].m_cRef + 3);
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v8 = v5[-1].m_pcPropertyDesc;
        --v5;
        if ( v8 )
        {
          v9 = v8->m_cRef-- == 1;
          if ( v9 )
            ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
          v5->m_pcPropertyDesc = 0;
        }
        v10 = v5->m_pcPropertyValue;
        if ( v10 )
        {
          v9 = v10->m_cRef-- == 1;
          if ( v9 )
            ((void (__stdcall *)(signed int))v10->vfptr->__vecDelDtor)(1);
          v5->m_pcPropertyValue = 0;
        }
        --v7;
      }
      while ( v7 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v12 = this->m_pcPropertyDesc;
    if ( v2->m_pcPropertyDesc )
    {
      v9 = v12->m_cRef-- == 1;
      if ( v9 )
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
      v2->m_pcPropertyDesc = 0;
    }
    v13 = v2->m_pcPropertyValue;
    if ( v13 )
    {
      v9 = v13->m_cRef-- == 1;
      if ( v9 )
        ((void (__stdcall *)(signed int))v13->vfptr->__vecDelDtor)(1);
      v2->m_pcPropertyValue = 0;
    }
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004258E0) --------------------------------------------------------  // acclient.c:97522
void __thiscall MasterPropertyGrabber::MasterPropertyGrabber(MasterPropertyGrabber *this)
{
  MasterPropertyGrabber *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@2

  v1 = this;
  this->m_object = 0;
  v2 = MasterPropertyGrabber::s_spcMasterPropertyList;
  if ( MasterPropertyGrabber::s_spcMasterPropertyList )
    goto LABEL_12;
  v3 = DBObj::GetByEnum(15, 2, 0x2Du);
  v2 = MasterPropertyGrabber::s_spcMasterPropertyList;
  if ( MasterPropertyGrabber::s_spcMasterPropertyList )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)MasterPropertyGrabber::s_spcMasterPropertyList + 20))(MasterPropertyGrabber::s_spcMasterPropertyList);
    v2 = 0;
    MasterPropertyGrabber::s_spcMasterPropertyList = 0;
  }
  if ( v3 )
  {
    MasterPropertyGrabber::s_spcMasterPropertyList = v3;
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 16))(v3);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
    v2 = MasterPropertyGrabber::s_spcMasterPropertyList;
  }
  if ( v1->m_object )
  {
    ((void (*)(void))v1->m_object->vfptr->Release)();
    v1->m_object = 0;
    v2 = MasterPropertyGrabber::s_spcMasterPropertyList;
  }
  if ( v2 )
  {
LABEL_12:
    v1->m_object = (MasterProperty *)v2;
    (*(void (**)(void))(*(_DWORD *)v2 + 16))();
  }
}
// 836DB8: using guessed type int MasterPropertyGrabber::s_spcMasterPropertyList;

//----- (00425960) --------------------------------------------------------  // acclient.c:97564
char __thiscall FloatPropertyValue::ToFileNode(FloatPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // eax@1
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // edx@2
  PFileNode *v5; // eax@2
  char result; // al@3
  float _nodea; // [sp+8h] [bp+8h]@2

  v3 = _node;
  if ( _node
    && (v4 = _node->vfptr,
        _nodea = this->m_value,
        (v5 = (PFileNode *)((int (__thiscall *)(PFileNode *))v4[1].__vecDelDtor)(v3)) != 0) )
  {
    PFileNode::SetNameAsFloat(v5, _nodea);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425990) --------------------------------------------------------  // acclient.c:97589
void __thiscall PFileNode::SetNameAsFloat(PFileNode *this, float i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(8u);
  if ( v4 )
  {
    *(_DWORD *)v4 = &FileNodeName_Float::vftable;
    *((float *)v4 + 1) = i_name;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);

//----- (004259E0) --------------------------------------------------------  // acclient.c:97615
IFileNodeName *__thiscall FileNodeName_Float::Clone(FileNodeName_Float *this)
{
  FileNodeName_Float *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Float::vftable;
    result[1].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);

//----- (00425A10) --------------------------------------------------------  // acclient.c:97636
char __thiscall InstanceIDPropertyValue::ToFileNode(InstanceIDPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  unsigned int v3; // esi@2
  PFileNode *v4; // eax@2
  char result; // al@3

  if ( _node
    && (v3 = this->m_value, (v4 = (PFileNode *)((int (__thiscall *)(_DWORD))_node->vfptr[1].__vecDelDtor)(_node)) != 0) )
  {
    PFileNode::SetNameAsHex(v4, v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425A40) --------------------------------------------------------  // acclient.c:97656
void __thiscall PFileNode::SetNameAsHex(PFileNode *this, unsigned int i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(8u);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = i_name;
    *(_DWORD *)v4 = &FileNodeName_Hex::vftable;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 7970EC: using guessed type int (__thiscall *FileNodeName_Hex::vftable)(void *, char);

//----- (00425A90) --------------------------------------------------------  // acclient.c:97682
IFileNodeName *__thiscall FileNodeName_Hex::Clone(FileNodeName_Hex *this)
{
  FileNodeName_Hex *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_UInt32::vftable;
    result[1].vfptr = (IFileNodeNameVtbl *)v1->m_name;
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Hex::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7970EC: using guessed type int (__thiscall *FileNodeName_Hex::vftable)(void *, char);
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (00425AC0) --------------------------------------------------------  // acclient.c:97705
IFileNodeName *__thiscall FileNodeName_UInt32::Clone(FileNodeName_UInt32 *this)
{
  FileNodeName_UInt32 *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_UInt32::vftable;
    result[1].vfptr = (IFileNodeNameVtbl *)v1->m_name;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (00425AF0) --------------------------------------------------------  // acclient.c:97726
char __thiscall IntegerPropertyValue::ToFileNode(IntegerPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  int v3; // esi@2
  PFileNode *v4; // eax@2
  char result; // al@3

  if ( _node
    && (v3 = this->m_value, (v4 = (PFileNode *)((int (__thiscall *)(_DWORD))_node->vfptr[1].__vecDelDtor)(_node)) != 0) )
  {
    PFileNode::SetNameAsInt32(v4, v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00425B20) --------------------------------------------------------  // acclient.c:97746
void __thiscall PFileNode::SetNameAsInt32(PFileNode *this, int i_name)
{
  PFileNode *v2; // esi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(8u);
  if ( v4 )
  {
    *(_DWORD *)v4 = &FileNodeName_Int32::vftable;
    *((_DWORD *)v4 + 1) = i_name;
    v2->m_pcName = (IFileNodeName *)v4;
  }
  else
  {
    v2->m_pcName = 0;
  }
}
// 797124: using guessed type int (__thiscall *FileNodeName_Int32::vftable)(void *, char);

//----- (00425B70) --------------------------------------------------------  // acclient.c:97772
IFileNodeName *__thiscall FileNodeName_Int32::Clone(FileNodeName_Int32 *this)
{
  FileNodeName_Int32 *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Int32::vftable;
    result[1].vfptr = (IFileNodeNameVtbl *)v1->m_name;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 797124: using guessed type int (__thiscall *FileNodeName_Int32::vftable)(void *, char);

//----- (00425BA0) --------------------------------------------------------  // acclient.c:97793
void __thiscall FileNodeName_Int32::Serialize(FileNodeName_Int32 *this, Archive *io_archive)
{
  Serializer::SerializeObject((CliDatError *)&this->m_name, io_archive);
}

//----- (00425BC0) --------------------------------------------------------  // acclient.c:97799
void __thiscall PositionPropertyValue::Copy(PositionPropertyValue *this)
{
  PositionPropertyValue *v1; // esi@1
  PositionPropertyValue *v2; // eax@1

  v1 = this;
  v2 = (PositionPropertyValue *)operator new(0x50u);
  if ( v2 )
    PositionPropertyValue::PositionPropertyValue(v2, &v1->m_value);
}

//----- (00425BF0) --------------------------------------------------------  // acclient.c:97811
void __thiscall PositionPropertyValue::PositionPropertyValue(PositionPropertyValue *this, Position *i_rcValue)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&PositionPropertyValue::vftable;
  this->m_value.vfptr = (PackObjVtbl *)&Position::vftable;
  this->m_value.objcell_id = i_rcValue->objcell_id;
  Frame::operator=((int)&this->m_value.frame, (int)&i_rcValue->frame);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 796928: using guessed type int (__thiscall *PositionPropertyValue::vftable)(void *, char);

//----- (00425C30) --------------------------------------------------------  // acclient.c:97823
int __thiscall Frame::operator=(int this, int a2)
{
  int result; // eax@1
  int v3; // esi@1

  result = this;
  v3 = this + 52;
  *(_DWORD *)v3 = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(v3 + 4) = *(_DWORD *)(a2 + 56);
  *(_DWORD *)(v3 + 8) = *(_DWORD *)(a2 + 60);
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  return result;
}

//----- (00425CA0) --------------------------------------------------------  // acclient.c:97850
bool __userpurge PositionPropertyValue::FromFileNode@<al>(PositionPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  PositionPropertyValue *v4; // esi@1
  int v5; // eax@1
  bool v6; // bl@3
  char *v7; // esi@3
  bool result; // al@6
  char *v9; // esi@7
  PStringBase<char> strValue; // [sp+0h] [bp-4h]@1

  strValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = PFileNode::GetLeaf(_node);
  if ( v5 && PFileNode::GetNameAsPString((PFileNode *)v5, a2, &strValue) )
  {
    v6 = Position::FromString(&v4->m_value, strValue.m_charbuffer->m_data) != 0;
    v7 = &strValue.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) )
    {
      if ( v7 )
        (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    }
    result = v6;
  }
  else
  {
    v9 = &strValue.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    result = 0;
  }
  return result;
}

//----- (00425D40) --------------------------------------------------------  // acclient.c:97886
char __userpurge PFileNode::GetNameAsPString@<al>(PFileNode *this@<ecx>, int a2@<edi>, PStringBase<char> *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@4
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( !v6 )
    {
      PStringBase<char>::set(o_name, (PStringBase<char> *)&v7[1]);
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    v10 = v9;
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_PString::vftable;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)v9 + 1);
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      PStringBase<char>::set(o_name, (PStringBase<char> *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (00425E10) --------------------------------------------------------  // acclient.c:97949
IFileNodeName *__thiscall FileNodeName_PString::Clone(FileNodeName_PString *this)
{
  FileNodeName_PString *v1; // edi@1
  void *v2; // eax@1
  IFileNodeName *v3; // esi@1
  IFileNodeName *result; // eax@2

  v1 = this;
  v2 = operator new(8u);
  v3 = (IFileNodeName *)v2;
  if ( v2 )
  {
    *(_DWORD *)v2 = &FileNodeName_PString::vftable;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)v2 + 1,
      &v1->m_name);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (00425E40) --------------------------------------------------------  // acclient.c:97976
char __thiscall FileNodeName_PString::FromPString(FileNodeName_PString *this, PStringBase<char> *i_rcString)
{
  PStringBase<char>::set(&this->m_name, i_rcString);
  return 1;
}

//----- (00425E60) --------------------------------------------------------  // acclient.c:97983
PStringBase<char> *__thiscall FileNodeName_PString::ToPString(FileNodeName_PString *this, PStringBase<char> *result)
{
  PSRefBufferCharData<char> *v2; // eax@1

  v2 = this->m_name.m_charbuffer;
  result->m_charbuffer = v2;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  return result;
}

//----- (00425E80) --------------------------------------------------------  // acclient.c:97994
FileNodeName_PString *__thiscall FileNodeName_PString::scalar_deleting_destructor(FileNodeName_PString *this, unsigned int a2)
{
  FileNodeName_PString *v2; // esi@1

  v2 = this;
  this->vfptr = (IFileNodeNameVtbl *)&FileNodeName_PString::vftable;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&this->m_name);
  v2->vfptr = (IFileNodeNameVtbl *)&IFileNodeName::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79602C: using guessed type int (__thiscall *IFileNodeName::vftable)(void *, char);
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (00425EB0) --------------------------------------------------------  // acclient.c:98010
char __thiscall PositionPropertyValue::InqPosition(PositionPropertyValue *this, Position *_value)
{
  _value->objcell_id = this->m_value.objcell_id;
  Frame::operator=((int)&_value->frame, (int)&this->m_value.frame);
  return 1;
}

//----- (00425ED0) --------------------------------------------------------  // acclient.c:98018
char __thiscall PositionPropertyValue::SetPosition(PositionPropertyValue *this, Position *_value)
{
  this->m_value.objcell_id = _value->objcell_id;
  Frame::operator=((int)&this->m_value.frame, (int)&_value->frame);
  return 1;
}

//----- (00425EF0) --------------------------------------------------------  // acclient.c:98026
signed int __thiscall StringInfoPropertyValue::HasValidData(StringInfoPropertyValue *this)
{
  signed int result; // eax@2

  if ( this->m_value.m_tableID.id == INVALID_DID_16.id
    || (result = 1, *(_DWORD *)&this->m_value.m_strToken.m_charbuffer[-1].m_data[12] == 1) )
    result = 0;
  return result;
}

//----- (00425F10) --------------------------------------------------------  // acclient.c:98037
bool __thiscall StringInfoPropertyValue::Compare(StringInfoPropertyValue *this, BasePropertyValue *_p)
{
  StringInfoPropertyValue *v2; // ebx@1
  PSRefBufferCharData<char> *v3; // esi@2
  bool v4; // bl@3
  int v5; // esi@3
  int v7; // esi@7
  StringInfo value; // [sp+Ch] [bp-90h]@2

  v2 = this;
  if ( !_p )
    return 0;
  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  StringInfo::StringInfo(&value);
  if ( !(unsigned __int8)_p->vfptr[48].__vecDelDtor((ReferenceCountTemplate<1048576,1> *)_p, (unsigned int)&value) )
  {
    StringInfo::~StringInfo(&value);
    v7 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    return 0;
  }
  v4 = StringInfo::operator==(&v2->m_value, &value);
  StringInfo::~StringInfo(&value);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
  {
    if ( v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  }
  return v4;
}

//----- (00425FD0) --------------------------------------------------------  // acclient.c:98072
void __thiscall StringPropertyValue::StringPropertyValue(StringPropertyValue *this)
{
  volatile LONG *v1; // ST00_4@1

  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringPropertyValue::vftable;
  v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_value.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v1);
}
// 797160: using guessed type int (__thiscall *StringPropertyValue::vftable)(void *, char);

//----- (00426000) --------------------------------------------------------  // acclient.c:98085
int __thiscall StringPropertyValue::SetValue(StringPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[40].__vecDelDtor)(&this->m_value);
}

//----- (00426020) --------------------------------------------------------  // acclient.c:98091
bool __thiscall StringPropertyValue::HasValidData(StringPropertyValue *this)
{
  return *(_DWORD *)&this->m_value.m_charbuffer[-1].m_data[12] != 1;
}

//----- (00426040) --------------------------------------------------------  // acclient.c:98097
BasePropertyValue *__thiscall StringPropertyValue::Copy(StringPropertyValue *this)
{
  StringPropertyValue *v1; // edi@1
  void *v2; // eax@1
  BasePropertyValue *v3; // esi@1
  BasePropertyValue *result; // eax@2

  v1 = this;
  v2 = operator new(0xCu);
  v3 = (BasePropertyValue *)v2;
  if ( v2 )
  {
    *((_DWORD *)v2 + 1) = 1;
    *(_DWORD *)v2 = &StringPropertyValue::vftable;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)v2 + 2,
      &v1->m_value);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 797160: using guessed type int (__thiscall *StringPropertyValue::vftable)(void *, char);

//----- (00426080) --------------------------------------------------------  // acclient.c:98125
char __userpurge StringPropertyValue::FromFileNode@<al>(StringPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  StringPropertyValue *v4; // esi@1
  int v5; // eax@2
  char result; // al@3

  v4 = this;
  if ( _node && (v5 = PFileNode::GetLeaf(_node)) != 0 )
    result = PFileNode::GetNameAsPString((PFileNode *)v5, a2, &v4->m_value);
  else
    result = 0;
  return result;
}

//----- (004260B0) --------------------------------------------------------  // acclient.c:98140
char __thiscall StringPropertyValue::InqString(StringPropertyValue *this, PStringBase<char> *_value)
{
  PStringBase<char>::set(_value, &this->m_value);
  return 1;
}

//----- (004260D0) --------------------------------------------------------  // acclient.c:98147
char __thiscall StringPropertyValue::SetString(StringPropertyValue *this, PStringBase<char> *_value)
{
  PStringBase<char>::set(&this->m_value, _value);
  return 1;
}

//----- (004260F0) --------------------------------------------------------  // acclient.c:98154
char __thiscall StringPropertyValue::GetValueAsString(StringPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::set(_value, &this->m_value);
  return 1;
}

//----- (00426110) --------------------------------------------------------  // acclient.c:98161
bool __thiscall StringPropertyValue::Compare(StringPropertyValue *this, BasePropertyValue *_p)
{
  StringPropertyValue *v2; // esi@1
  int v3; // eax@3
  char *v4; // esi@3
  bool v5; // bl@3
  bool result; // al@6
  char *v7; // esi@7
  PStringBase<char> strValue; // [sp+4h] [bp-4h]@1

  strValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( _p && (unsigned __int8)((int (__stdcall *)(PStringBase<char> *))_p->vfptr[40].__vecDelDtor)(&strValue) )
  {
    v3 = PStringBase<char>::cmp(&v2->m_value, &strValue, 0);
    v4 = &strValue.m_charbuffer[-2].m_data[12];
    v5 = v3 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    result = v5;
  }
  else
  {
    v7 = &strValue.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    result = 0;
  }
  return result;
}

//----- (004261B0) --------------------------------------------------------  // acclient.c:98197
bool __thiscall StringPropertyValue::operator!=(StringPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  StringPropertyValue *v2; // esi@1
  bool v3; // al@2
  char *v4; // esi@2
  bool v5; // bl@2
  bool result; // al@5
  char *v7; // esi@6
  PStringBase<char> strRhsValue; // [sp+4h] [bp-4h]@1

  strRhsValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( (unsigned __int8)((int (__stdcall *)(PStringBase<char> *))i_rcRhs->vfptr[40].__vecDelDtor)(&strRhsValue) )
  {
    v3 = PStringBase<char>::operator!=(&v2->m_value, &strRhsValue);
    v4 = &strRhsValue.m_charbuffer[-2].m_data[12];
    v5 = v3;
    if ( !InterlockedDecrement((volatile LONG *)&strRhsValue.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    result = v5;
  }
  else
  {
    v7 = &strRhsValue.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRhsValue.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    result = 0;
  }
  return result;
}

//----- (00426240) --------------------------------------------------------  // acclient.c:98233
bool __thiscall PStringBase<char>::operator!=(PStringBase<char> *this, PStringBase<char> *rhs)
{
  PSRefBufferCharData<char> *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // ecx@2
  int v5; // edx@2
  bool result; // al@5

  v2 = rhs->m_charbuffer;
  v3 = this->m_charbuffer;
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[12] == *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12]
    && ((v4 = *(_DWORD *)&v3[-1].m_data[8], v5 = *(_DWORD *)&v2[-1].m_data[8], v4 == v5) || v4 == -1 || v5 == -1) )
    result = strcmp(v3->m_data, v2->m_data) != 0;
  else
    result = 1;
  return result;
}

//----- (004262C0) --------------------------------------------------------  // acclient.c:98252
bool __thiscall StringPropertyValue::operator==(StringPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  StringPropertyValue *v2; // esi@1
  bool v3; // al@2
  char *v4; // esi@2
  bool v5; // bl@2
  bool result; // al@5
  char *v7; // esi@6
  PStringBase<char> strRhsValue; // [sp+4h] [bp-4h]@1

  strRhsValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( (unsigned __int8)((int (__stdcall *)(PStringBase<char> *))i_rcRhs->vfptr[40].__vecDelDtor)(&strRhsValue) )
  {
    v3 = PStringBase<char>::operator==(&v2->m_value, &strRhsValue);
    v4 = &strRhsValue.m_charbuffer[-2].m_data[12];
    v5 = v3;
    if ( !InterlockedDecrement((volatile LONG *)&strRhsValue.m_charbuffer[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    result = v5;
  }
  else
  {
    v7 = &strRhsValue.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strRhsValue.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
    result = 0;
  }
  return result;
}

//----- (00426350) --------------------------------------------------------  // acclient.c:98288
StringPropertyValue *__thiscall StringPropertyValue::scalar_deleting_destructor(StringPropertyValue *this, unsigned int a2)
{
  StringPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringPropertyValue::vftable;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&this->m_value);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 797160: using guessed type int (__thiscall *StringPropertyValue::vftable)(void *, char);

//----- (00426380) --------------------------------------------------------  // acclient.c:98304
void __thiscall StringTokenPropertyValue::StringTokenPropertyValue(StringTokenPropertyValue *this)
{
  volatile LONG *v1; // ST00_4@1

  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringTokenPropertyValue::vftable;
  this->m_value = 0;
  v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_tokenName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v1);
}
// 7972A0: using guessed type int (__thiscall *StringTokenPropertyValue::vftable)(void *, char);

//----- (004263B0) --------------------------------------------------------  // acclient.c:98318
int __thiscall StringTokenPropertyValue::SetValue(StringTokenPropertyValue *this, BasePropertyValue *_value)
{
  return ((int (__stdcall *)(_DWORD))_value->vfptr[76].__vecDelDtor)(&this->m_value);
}

//----- (004263D0) --------------------------------------------------------  // acclient.c:98324
bool __thiscall StringTokenPropertyValue::Compare(StringTokenPropertyValue *this, BasePropertyValue *_p)
{
  StringTokenPropertyValue *v2; // esi@1
  bool result; // al@3

  v2 = this;
  if ( _p && (unsigned __int8)((int (__stdcall *)(BasePropertyValue **))_p->vfptr[76].__vecDelDtor)(&_p) )
    result = v2->m_value == (_DWORD)_p;
  else
    result = 0;
  return result;
}

//----- (00426410) --------------------------------------------------------  // acclient.c:98338
BasePropertyValue *__thiscall StringTokenPropertyValue::Copy(StringTokenPropertyValue *this)
{
  StringTokenPropertyValue *v1; // edi@1
  void *v2; // esi@1
  unsigned int v3; // eax@2
  BasePropertyValue *result; // eax@2

  v1 = this;
  v2 = operator new(0x10u);
  if ( v2 )
  {
    v3 = v1->m_value;
    *((_DWORD *)v2 + 1) = 1;
    *(_DWORD *)v2 = &StringTokenPropertyValue::vftable;
    *((_DWORD *)v2 + 2) = v3;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)v2 + 3,
      &v1->m_tokenName);
    result = (BasePropertyValue *)v2;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7972A0: using guessed type int (__thiscall *StringTokenPropertyValue::vftable)(void *, char);

//----- (00426450) --------------------------------------------------------  // acclient.c:98367
char __thiscall StringTokenPropertyValue::FromFileNode(StringTokenPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  int v3; // edi@1
  int v4; // eax@2
  char result; // al@4

  v3 = (int)this;
  if ( _node
    && (v4 = PFileNode::GetLeaf(_node)) != 0
    && PFileNode::GetNameAsPString((PFileNode *)v4, v3, (PStringBase<char> *)(v3 + 12)) )
  {
    *(_DWORD *)(v3 + 8) = PStringBase<char>::hash((PStringBase<char> *)(v3 + 12));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426490) --------------------------------------------------------  // acclient.c:98389
StringTokenPropertyValue *__thiscall StringTokenPropertyValue::scalar_deleting_destructor(StringTokenPropertyValue *this, unsigned int a2)
{
  StringTokenPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StringTokenPropertyValue::vftable;
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&this->m_tokenName);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7972A0: using guessed type int (__thiscall *StringTokenPropertyValue::vftable)(void *, char);

//----- (004264C0) --------------------------------------------------------  // acclient.c:98405
char __thiscall TriStatePropertyValue::GetValueAsString(TriStatePropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  TriState v4; // eax@1
  int v5; // eax@2
  char result; // al@4

  v4 = this->m_value;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 254 )
      {
        PStringBase<char>::set(_value, &KW_UNDEF);
        result = 1;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      PStringBase<char>::set(_value, &KW_TRUE);
      result = 1;
    }
  }
  else
  {
    PStringBase<char>::set(_value, &KW_FALSE);
    result = 1;
  }
  return result;
}

//----- (00426510) --------------------------------------------------------  // acclient.c:98442
void __thiscall VectorPropertyValue::Serialize(VectorPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  char *v3; // esi@1
  unsigned int v4; // eax@1

  v3 = (char *)&this->m_value;
  Archive::CheckAlignment(io_archive, 0xCu);
  v4 = Archive::GetBytes(io_archive, 0xCu);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v4 = *(_DWORD *)v3;
      *(_DWORD *)(v4 + 4) = *((_DWORD *)v3 + 1);
      *(_DWORD *)(v4 + 8) = *((_DWORD *)v3 + 2);
    }
    else
    {
      *(_DWORD *)v3 = *(_DWORD *)v4;
      *((_DWORD *)v3 + 1) = *(_DWORD *)(v4 + 4);
      *((_DWORD *)v3 + 2) = *(_DWORD *)(v4 + 8);
    }
  }
}

//----- (00426560) --------------------------------------------------------  // acclient.c:98468
char __thiscall WaveformPropertyValue::GetValueAsString(WaveformPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char> *v4; // eax@1
  char *v5; // esi@1
  PStringBase<char> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v4 = Waveform::ToString(&this->m_value, &result);
  PStringBase<char>::set(_value, v4);
  v5 = &result.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (004265B0) --------------------------------------------------------  // acclient.c:98484
char __cdecl MasterProperty::InqPropertyNameStringStatic(unsigned int _name_enum, PStringBase<char> *_name_str)
{
  MasterProperty *v2; // ecx@0
  MasterProperty *v3; // esi@1
  char result; // al@2
  char v5; // bl@3
  MasterPropertyGrabber mpr; // [sp+0h] [bp-4h]@1

  mpr.m_object = v2;
  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v3 = mpr.m_object;
  if ( mpr.m_object )
  {
    v5 = EnumMapper::GetString((unsigned int)&mpr.m_object->m_emapper, (PStringBase<char> *)_name_enum, _name_str);
    v3->vfptr->Release((Interface *)v3);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004265F0) --------------------------------------------------------  // acclient.c:98509
char __cdecl MasterProperty::InqPropertyGroupNameStringStatic(unsigned int _group_name_enum, PStringBase<char> *_name_str)
{
  MasterProperty *v2; // ecx@0
  MasterProperty *v3; // esi@1
  char result; // al@2
  char v5; // bl@3
  MasterPropertyGrabber mpr; // [sp+0h] [bp-4h]@1

  mpr.m_object = v2;
  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v3 = mpr.m_object;
  if ( mpr.m_object )
  {
    v5 = EnumMapper::GetString(0xAu, _group_name_enum, _name_str);
    v3->vfptr->Release((Interface *)v3);
    result = v5;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426630) --------------------------------------------------------  // acclient.c:98534
void __thiscall SmartArray<BaseProperty,1>::~SmartArray<BaseProperty,1>(SmartArray<BaseProperty,1> *this)
{
  BaseProperty *v1; // ecx@2

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
      BaseProperty::vector_deleting_destructor(v1, 3u);
  }
}

//----- (00426650) --------------------------------------------------------  // acclient.c:98547
void __thiscall ArrayPropertyValue::ArrayPropertyValue(ArrayPropertyValue *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ArrayPropertyValue::vftable;
  this->m_value.m_data = 0;
  this->m_value.m_sizeAndDeallocate = 0;
  this->m_value.m_num = 0;
}
// 7973E0: using guessed type int (__thiscall *ArrayPropertyValue::vftable)(void *, char);

//----- (00426680) --------------------------------------------------------  // acclient.c:98564
char __thiscall ArrayPropertyValue::InqArrayNumElements(ArrayPropertyValue *this, unsigned int *_num)
{
  *_num = this->m_value.m_num;
  return 1;
}

//----- (00426690) --------------------------------------------------------  // acclient.c:98571
char __thiscall ArrayPropertyValue::RemoveArrayElement(ArrayPropertyValue *this, const unsigned int _index)
{
  return SmartArray<BaseProperty,1>::RemoveOrderedByIndex(&this->m_value, _index);
}

//----- (004266A0) --------------------------------------------------------  // acclient.c:98577
char __thiscall SmartArray<BaseProperty,1>::RemoveOrderedByIndex(SmartArray<BaseProperty,1> *this, unsigned int index)
{
  SmartArray<BaseProperty,1> *v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // eax@2
  BaseProperty *v5; // ecx@2
  int v6; // edi@2
  int v7; // ebx@3
  void *v8; // ecx@4
  int v9; // ecx@5
  int v10; // edx@5
  int v11; // ecx@9
  int v12; // edx@9
  char result; // al@11
  int v14; // [sp+4h] [bp-8h]@4
  int v15; // [sp+8h] [bp-4h]@4

  v2 = this;
  v3 = this->m_num;
  if ( index >= v3 )
  {
    result = 0;
  }
  else
  {
    v4 = v3 - 1;
    v5 = &this->m_data[index];
    v6 = (int)&v2->m_data[v4];
    v2->m_num = v4;
    if ( (unsigned int)v5 < v6 )
    {
      do
      {
        v7 = (int)&v5[1];
        BaseProperty::operator=(v5, (int)&v5[1]);
        v5 = (BaseProperty *)v7;
      }
      while ( v7 < (unsigned int)v6 );
    }
    v8 = &v2->m_data[v2->m_num];
    v14 = 0;
    v15 = 0;
    BaseProperty::operator=(v8, (int)&v14);
    if ( v14 )
    {
      v9 = v14;
      v10 = *(_DWORD *)(v14 + 4) - 1;
      *(_DWORD *)(v14 + 4) = v10;
      if ( !v10 )
        (**(void (__stdcall ***)(_DWORD))v9)(1);
      v14 = 0;
    }
    if ( v15 )
    {
      v11 = v15;
      v12 = *(_DWORD *)(v15 + 4) - 1;
      *(_DWORD *)(v15 + 4) = v12;
      if ( !v12 )
        (**(void (__stdcall ***)(_DWORD))v11)(1);
    }
    result = 1;
  }
  return result;
}

//----- (00426750) --------------------------------------------------------  // acclient.c:98643
char __thiscall ArrayPropertyValue::PopArrayElement(ArrayPropertyValue *this, BaseProperty *_value)
{
  return SmartArray<BaseProperty,1>::pop(&this->m_value, _value);
}

//----- (00426760) --------------------------------------------------------  // acclient.c:98649
char __thiscall SmartArray<BaseProperty,1>::pop(SmartArray<BaseProperty,1> *this, BaseProperty *o_rData)
{
  SmartArray<BaseProperty,1> *v2; // esi@1
  unsigned int v3; // eax@1
  char result; // al@2
  unsigned int v5; // eax@3
  int v6; // ST00_4@3
  void *v7; // ecx@3
  int v8; // ecx@4
  int v9; // edx@4
  int v10; // ecx@8
  int v11; // edx@8
  int v12; // [sp+4h] [bp-8h]@3
  int v13; // [sp+8h] [bp-4h]@3

  v2 = this;
  v3 = this->m_num;
  if ( v3 )
  {
    v5 = v3 - 1;
    v6 = (int)&this->m_data[v5];
    this->m_num = v5;
    BaseProperty::operator=(o_rData, v6);
    v7 = &v2->m_data[v2->m_num];
    v12 = 0;
    v13 = 0;
    BaseProperty::operator=(v7, (int)&v12);
    if ( v12 )
    {
      v8 = v12;
      v9 = *(_DWORD *)(v12 + 4) - 1;
      *(_DWORD *)(v12 + 4) = v9;
      if ( !v9 )
        (**(void (__stdcall ***)(_DWORD))v8)(1);
      v12 = 0;
    }
    if ( v13 )
    {
      v10 = v13;
      v11 = *(_DWORD *)(v13 + 4) - 1;
      *(_DWORD *)(v13 + 4) = v11;
      if ( !v11 )
        (**(void (__stdcall ***)(_DWORD))v10)(1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426800) --------------------------------------------------------  // acclient.c:98703
char __thiscall ArrayPropertyValue::InqArrayElement(ArrayPropertyValue *this, const unsigned int _index, BaseProperty *_value)
{
  char result; // al@2

  if ( _index >= this->m_value.m_num )
  {
    result = 0;
  }
  else
  {
    BaseProperty::operator=(_value, (int)&this->m_value.m_data[_index]);
    result = 1;
  }
  return result;
}

//----- (00426830) --------------------------------------------------------  // acclient.c:98720
BaseProperty *__thiscall ArrayPropertyValue::GetArrayElement(ArrayPropertyValue *this, const unsigned int _index)
{
  return &this->m_value.m_data[_index];
}

//----- (00426840) --------------------------------------------------------  // acclient.c:98726
ArrayPropertyValue *__thiscall ArrayPropertyValue::scalar_deleting_destructor(ArrayPropertyValue *this, unsigned int a2)
{
  ArrayPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ArrayPropertyValue::vftable;
  SmartArray<BaseProperty,1>::~SmartArray<BaseProperty,1>(&this->m_value);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7973E0: using guessed type int (__thiscall *ArrayPropertyValue::vftable)(void *, char);

//----- (00426870) --------------------------------------------------------  // acclient.c:98742
char __userpurge BoolPropertyValue::FromFileNode@<al>(BoolPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  BoolPropertyValue *v4; // esi@1
  int v5; // eax@2
  char result; // al@3

  v4 = this;
  if ( _node && (v5 = PFileNode::GetLeaf(_node)) != 0 )
    result = PFileNode::GetNameAsBool((PFileNode *)v5, a2, &v4->m_value);
  else
    result = 0;
  return result;
}

//----- (004268A0) --------------------------------------------------------  // acclient.c:98757
char __userpurge PFileNode::GetNameAsBool@<al>(PFileNode *this@<ecx>, int a2@<edi>, bool *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 7 )
    {
      *o_name = LOBYTE(v7[1].vfptr);
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Bool::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *o_name = *((_BYTE *)v10 + 4);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 796010: using guessed type int (__thiscall *FileNodeName_Bool::vftable)(void *, char);

//----- (00426960) --------------------------------------------------------  // acclient.c:98819
char __userpurge FloatPropertyValue::FromFileNode@<al>(FloatPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  FloatPropertyValue *v4; // esi@1
  int v5; // eax@2
  char result; // al@3

  v4 = this;
  if ( _node && (v5 = PFileNode::GetLeaf(_node)) != 0 )
    result = PFileNode::GetNameAsFloat((PFileNode *)v5, a2, &v4->m_value);
  else
    result = 0;
  return result;
}

//----- (00426990) --------------------------------------------------------  // acclient.c:98834
char __userpurge PFileNode::GetNameAsFloat@<al>(PFileNode *this@<ecx>, int a2@<edi>, float *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 4 )
    {
      *(_DWORD *)o_name = v7[1].vfptr;
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Float::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *(_DWORD *)o_name = *((_DWORD *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);

//----- (00426A50) --------------------------------------------------------  // acclient.c:98896
char __userpurge InstanceIDPropertyValue::FromFileNode@<al>(InstanceIDPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  InstanceIDPropertyValue *v4; // esi@1
  int v5; // eax@2
  char result; // al@3

  v4 = this;
  if ( _node && (v5 = PFileNode::GetLeaf(_node)) != 0 )
    result = PFileNode::GetNameAsHex((PFileNode *)v5, a2, &v4->m_value);
  else
    result = 0;
  return result;
}

//----- (00426A80) --------------------------------------------------------  // acclient.c:98911
char __userpurge PFileNode::GetNameAsHex@<al>(PFileNode *this@<ecx>, int a2@<edi>, unsigned int *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 8 )
    {
      *o_name = (unsigned int)v7[1].vfptr;
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Hex::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *o_name = *((_DWORD *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 7970EC: using guessed type int (__thiscall *FileNodeName_Hex::vftable)(void *, char);

//----- (00426B40) --------------------------------------------------------  // acclient.c:98973
char __userpurge IntegerPropertyValue::FromFileNode@<al>(IntegerPropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  IntegerPropertyValue *v4; // esi@1
  int v5; // eax@2
  char result; // al@3

  v4 = this;
  if ( _node && (v5 = PFileNode::GetLeaf(_node)) != 0 )
    result = PFileNode::GetNameAsInt32((PFileNode *)v5, a2, &v4->m_value);
  else
    result = 0;
  return result;
}

//----- (00426B70) --------------------------------------------------------  // acclient.c:98988
char __userpurge PFileNode::GetNameAsInt32@<al>(PFileNode *this@<ecx>, int a2@<edi>, int *o_name)
{
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // edi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 2 )
    {
      *o_name = (int)v7[1].vfptr;
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(8u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Int32::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *o_name = *((_DWORD *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 797124: using guessed type int (__thiscall *FileNodeName_Int32::vftable)(void *, char);

//----- (00426C30) --------------------------------------------------------  // acclient.c:99050
bool __thiscall StringPropertyValue::ToFileNode(StringPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PStringBase<char> v3; // ST04_4@2
  bool result; // al@2

  if ( _node )
  {
    v3.m_charbuffer = this->m_value.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1]);
    result = PFileNode::MakeSubNode(_node, v3) != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426C70) --------------------------------------------------------  // acclient.c:99069
PFileNode *__thiscall PFileNode::MakeSubNode(PFileNode *this, PStringBase<char> i_name)
{
  PFileNode *v2; // edi@1
  PFileNode *v3; // edi@1

  v2 = this;
  InterlockedIncrement((volatile LONG *)&i_name.m_charbuffer[-1]);
  v3 = PFileNode::MakeSubNodeAsPString(v2, i_name);
  if ( !InterlockedDecrement((volatile LONG *)&i_name.m_charbuffer[-1])
    && i_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&i_name.m_charbuffer[-2].m_data[12])(
      &i_name.m_charbuffer[-2].m_data[12],
      1);
  return v3;
}

//----- (00426CC0) --------------------------------------------------------  // acclient.c:99086
PFileNode *__thiscall PFileNode::MakeSubNodeAsPString(PFileNode *this, PStringBase<char> i_name)
{
  PFileNode *v2; // edi@1
  PFileNode *result; // eax@5

  v2 = (PFileNode *)((int (*)(void))this->vfptr[1].__vecDelDtor)();
  if ( v2 )
  {
    InterlockedIncrement((volatile LONG *)&i_name.m_charbuffer[-1]);
    PFileNode::SetNameAsPString(v2, i_name);
    if ( !InterlockedDecrement((volatile LONG *)&i_name.m_charbuffer[-1])
      && i_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&i_name.m_charbuffer[-2].m_data[12])(
        &i_name.m_charbuffer[-2].m_data[12],
        1);
    result = v2;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)&i_name.m_charbuffer[-1])
      && i_name.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&i_name.m_charbuffer[-2].m_data[12])(
        &i_name.m_charbuffer[-2].m_data[12],
        1);
    result = 0;
  }
  return result;
}

//----- (00426D30) --------------------------------------------------------  // acclient.c:99116
void __thiscall PFileNode::SetNameAsPString(PFileNode *this, PStringBase<char> i_name)
{
  PFileNode *v2; // edi@1
  IFileNodeName *v3; // ecx@1
  void *v4; // eax@3
  IFileNodeName *v5; // esi@3
  char *v6; // esi@6

  v2 = this;
  v3 = this->m_pcName;
  if ( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v2->m_pcName = 0;
  v4 = operator new(8u);
  v5 = (IFileNodeName *)v4;
  if ( v4 )
  {
    *(_DWORD *)v4 = &FileNodeName_PString::vftable;
    PStringBase<unsigned short>::PStringBase<unsigned short>(
      (CaseInsensitiveStringBase<PStringBase<char> > *)v4 + 1,
      &i_name);
  }
  else
  {
    v5 = 0;
  }
  v2->m_pcName = v5;
  v6 = &i_name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&i_name.m_charbuffer[-1]) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}
// 797140: using guessed type int (__thiscall *FileNodeName_PString::vftable)(void *, char);

//----- (00426DA0) --------------------------------------------------------  // acclient.c:99153
bool __thiscall StringTokenPropertyValue::ToFileNode(StringTokenPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PStringBase<char> v3; // esi@2
  PFileNode *v4; // edi@2
  int v5; // esi@2
  bool result; // al@5

  if ( _node )
  {
    v3.m_charbuffer = this->m_tokenName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1]);
    InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1]);
    v4 = PFileNode::MakeSubNodeAsPString(_node, v3);
    v5 = (int)&v3.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = v4 != 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426E00) --------------------------------------------------------  // acclient.c:99182
void __thiscall TriStatePropertyValue::Serialize(TriStatePropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  TriStatePropertyValue *v3; // esi@1
  unsigned int v4; // [sp-2h] [bp-4h]@1

  v4 = (unsigned int)this;
  v3 = this;
  BYTE3(v4) = LOBYTE(this->m_value);
  Serializer::SerializeObject((char *)&v4 + 3, io_archive);
  if ( !(io_archive->m_flags & 5) )
    v3->m_value = BYTE3(v4);
}

//----- (00426E40) --------------------------------------------------------  // acclient.c:99196
char __thiscall TriStatePropertyValue::ToFileNode(TriStatePropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  TriState v3; // eax@2
  int v4; // eax@3
  PSRefBufferCharData<char> *v5; // edx@5
  PStringBase<char> v7; // ST04_4@9
  PStringBase<char> v8; // [sp-4h] [bp-8h]@5

  if ( !_node )
    return 0;
  v3 = this->m_value;
  if ( v3 )
  {
    v4 = v3 - 1;
    if ( v4 )
    {
      if ( v4 != 254 )
        return 0;
      v8.m_charbuffer = KW_UNDEF.m_charbuffer;
      v5 = KW_UNDEF.m_charbuffer;
    }
    else
    {
      v8.m_charbuffer = KW_TRUE.m_charbuffer;
      v5 = KW_TRUE.m_charbuffer;
    }
    InterlockedIncrement((volatile LONG *)&v5[-1]);
    if ( !PFileNode::MakeSubNode(_node, v8) )
      return 0;
  }
  else
  {
    v7.m_charbuffer = KW_FALSE.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&KW_FALSE.m_charbuffer[-1]);
    if ( !PFileNode::MakeSubNode(_node, v7) )
      return 0;
  }
  return 1;
}

//----- (00426ED0) --------------------------------------------------------  // acclient.c:99237
char __cdecl MasterProperty::InqPropertyNameEnumStatic(PStringBase<char> *_name_str, unsigned int *_name_enum)
{
  MasterProperty *v2; // ecx@0
  MasterProperty *v3; // esi@1
  char result; // al@2
  unsigned int *v5; // ST04_4@3
  char v6; // bl@3
  MasterPropertyGrabber mpr; // [sp+0h] [bp-4h]@1

  mpr.m_object = v2;
  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v3 = mpr.m_object;
  if ( mpr.m_object )
  {
    v5 = (unsigned int *)_name_str->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&_name_str->m_charbuffer[-1]);
    v6 = EnumMapper::GetEnum((PStringBase<char>)&v3->m_emapper, v5, _name_enum);
    v3->vfptr->Release((Interface *)v3);
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00426F20) --------------------------------------------------------  // acclient.c:99265
char __thiscall MasterProperty::InqAvailablePropertiesByPropertyGroup(MasterProperty *this, unsigned int _group_name, AvailablePropertySet *_set)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  HeritageGroup_CGVtbl *v7; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_properties.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currHashTable;
  v6 = v3->m_currBucket;
  if ( v4 )
  {
    do
    {
LABEL_2:
      v7 = v4->m_data.vfptr;
      if ( v7
        && v7[4].Serialize == (void (__thiscall *)(HeritageGroup_CG *, Archive *))_group_name
        && !AvailablePropertySet::AddProperty(_set, v4->m_hashKey) )
        return 0;
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v4 = *v6;
        if ( *v6 )
          goto LABEL_2;
        return 1;
      }
    }
  }
  return 1;
}

//----- (00426FA0) --------------------------------------------------------  // acclient.c:99311
void __thiscall MasterProperty::GetSubDataIDs(MasterProperty *this, QualifiedDataIDArray *id_array)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v5; // edi@1
  BasePropertyDesc *v6; // ecx@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_properties.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currHashTable;
  v5 = v2->m_currBucket;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v6 = (BasePropertyDesc *)v3->m_data.vfptr;
      if ( v6 )
        BasePropertyDesc::GetSubDataIDs(v6, id_array);
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v5;
      if ( v5 == &v4->m_buckets[v4->m_numBuckets] )
        break;
      if ( *v5 )
      {
        v3 = *v5;
        if ( *v5 )
          goto LABEL_2;
        return;
      }
    }
  }
}

//----- (00427040) --------------------------------------------------------  // acclient.c:99367
void __thiscall ArrayPropertyValue::operator+=(ArrayPropertyValue *this, BasePropertyValue *i_rcRhs)
{
  ArrayPropertyValue *v2; // esi@1
  SmartArray<BaseProperty,1> *v3; // eax@1

  v2 = this;
  v3 = (SmartArray<BaseProperty,1> *)((int (*)(void))i_rcRhs->vfptr[66].__vecDelDtor)();
  if ( v3 )
    SmartArray<BaseProperty,1>::AddToEnd(&v2->m_value, v3);
}

//----- (00427060) --------------------------------------------------------  // acclient.c:99379
char __thiscall SmartArray<BaseProperty,1>::AddToEnd(SmartArray<BaseProperty,1> *this, SmartArray<BaseProperty,1> *i_rRhs)
{
  SmartArray<BaseProperty,1> *v2; // edi@1
  unsigned int i; // esi@1

  v2 = this;
  SmartArray<BaseProperty,1>::grow(this, i_rRhs->m_num + this->m_num);
  for ( i = i_rRhs->m_num - 1; (i & 0x80000000) == 0; --i )
    BaseProperty::operator=(&v2->m_data[i] + v2->m_num, (int)&i_rRhs->m_data[i]);
  v2->m_num += i_rRhs->m_num;
  return 1;
}

//----- (004270B0) --------------------------------------------------------  // acclient.c:99393
char __thiscall SmartArray<BaseProperty,1>::grow(SmartArray<BaseProperty,1> *this, unsigned int i_nSize)
{
  SmartArray<BaseProperty,1> *v2; // esi@1
  void *v4; // eax@5
  int v5; // ebp@6
  int i; // edi@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<BaseProperty,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = i_nSize;
      vector_constructor_iterator(
        (char *)v4 + 4,
        8u,
        i_nSize,
        (void *(__thiscall *)(void *))BaseProperty::BaseProperty);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          for ( i = v2->m_num - 1; i >= 0; --i )
            BaseProperty::operator=((void *)(8 * i + v5), (int)&v2->m_data[i]);
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              BaseProperty::vector_deleting_destructor(v2->m_data, 3u);
          }
        }
        v2->m_data = (BaseProperty *)v5;
        v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00427170) --------------------------------------------------------  // acclient.c:99442
void __thiscall SmartArray<BaseProperty,1>::Reset(SmartArray<BaseProperty,1> *this)
{
  SmartArray<BaseProperty,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // ebx@6
  void *v5; // ecx@7
  int v6; // ecx@8
  int v7; // edx@8
  int v8; // ecx@12
  int v9; // edx@12
  int v10; // [sp+8h] [bp-8h]@7
  int v11; // [sp+Ch] [bp-4h]@7

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      BaseProperty::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; --i )
    {
      v5 = &v1->m_data[i];
      v10 = 0;
      v11 = 0;
      BaseProperty::operator=(v5, (int)&v10);
      if ( v10 )
      {
        v6 = v10;
        v7 = *(_DWORD *)(v10 + 4) - 1;
        *(_DWORD *)(v10 + 4) = v7;
        if ( !v7 )
          (**(void (__stdcall ***)(_DWORD))v6)(1);
        v10 = 0;
      }
      if ( v11 )
      {
        v8 = v11;
        v9 = *(_DWORD *)(v11 + 4) - 1;
        *(_DWORD *)(v11 + 4) = v9;
        if ( !v9 )
          (**(void (__stdcall ***)(_DWORD))v8)(1);
        v11 = 0;
      }
    }
  }
}

//----- (00427220) --------------------------------------------------------  // acclient.c:99498
char __thiscall ArrayPropertyValue::SetValue(ArrayPropertyValue *this, BasePropertyValue *_value)
{
  ArrayPropertyValue *v2; // esi@1
  int v3; // eax@1
  char result; // al@2

  v2 = this;
  v3 = ((int (*)(void))_value->vfptr[66].__vecDelDtor)();
  if ( v3 )
  {
    SmartArray<BaseProperty,1>::operator=(&v2->m_value, v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00427250) --------------------------------------------------------  // acclient.c:99519
SmartArray<BaseProperty,1> *__thiscall SmartArray<BaseProperty,1>::operator=(SmartArray<BaseProperty,1> *this, int a2)
{
  SmartArray<BaseProperty,1> *v2; // ebx@1
  int v3; // esi@3
  void *v4; // edi@3
  int v5; // ebp@3
  unsigned int i; // edi@5
  void *v7; // ecx@6
  int v8; // ecx@7
  int v9; // edx@7
  int v10; // ecx@11
  int v11; // edx@11
  int v13; // [sp+8h] [bp-8h]@6
  int v14; // [sp+Ch] [bp-4h]@6

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<BaseProperty,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = v2->m_data;
    v5 = *(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      do
      {
        BaseProperty::operator=(v4, v3);
        v3 += 8;
        v4 = (char *)v4 + 8;
      }
      while ( v3 < (unsigned int)v5 );
    }
    for ( i = *(_DWORD *)(a2 + 8); i < v2->m_num; ++i )
    {
      v7 = &v2->m_data[i];
      v13 = 0;
      v14 = 0;
      BaseProperty::operator=(v7, (int)&v13);
      if ( v13 )
      {
        v8 = v13;
        v9 = *(_DWORD *)(v13 + 4) - 1;
        *(_DWORD *)(v13 + 4) = v9;
        if ( !v9 )
          (**(void (__stdcall ***)(_DWORD))v8)(1);
        v13 = 0;
      }
      if ( v14 )
      {
        v10 = v14;
        v11 = *(_DWORD *)(v14 + 4) - 1;
        *(_DWORD *)(v14 + 4) = v11;
        if ( !v11 )
          (**(void (__stdcall ***)(_DWORD))v10)(1);
        v14 = 0;
      }
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (00427340) --------------------------------------------------------  // acclient.c:99582
char __thiscall BoolPropertyValue::GetValueAsString(BoolPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  char result; // al@2

  if ( this->m_value )
  {
    PStringBase<char>::set(_value, "True");
    result = 1;
  }
  else
  {
    PStringBase<char>::set(_value, "False");
    result = 1;
  }
  return result;
}

//----- (00427370) --------------------------------------------------------  // acclient.c:99600
char __thiscall ColorPropertyValue::GetValueAsString(ColorPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::sprintf(
    _value,
    "%.3f %.3f %.3f %.3f",
    this->m_value.r,
    this->m_value.g,
    this->m_value.b,
    this->m_value.a);
  return 1;
}

//----- (004273B0) --------------------------------------------------------  // acclient.c:99613
char __thiscall FloatPropertyValue::GetValueAsString(FloatPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  char result; // al@2
  double v5; // [sp+0h] [bp-8h]@1

  v5 = this->m_value;
  if ( rawValue )
  {
    PStringBase<char>::sprintf(_value, "%.3f", v5);
    result = 1;
  }
  else
  {
    PStringBase<char>::sprintf(_value, "%.3g", v5);
    result = 1;
  }
  return result;
}

//----- (004273F0) --------------------------------------------------------  // acclient.c:99633
void __thiscall FileNodeName_PString::Serialize(FileNodeName_PString *this, Archive *io_archive)
{
  PStringBase<char>::Serialize(&this->m_name, io_archive);
}

//----- (00427400) --------------------------------------------------------  // acclient.c:99639
char __thiscall InstanceIDPropertyValue::GetValueAsString(InstanceIDPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::sprintf(_value, "0x%08X", this->m_value);
  return 1;
}

//----- (00427420) --------------------------------------------------------  // acclient.c:99646
char __thiscall IntegerPropertyValue::GetValueAsString(IntegerPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::sprintf(_value, "%d", this->m_value);
  return 1;
}

//----- (00427440) --------------------------------------------------------  // acclient.c:99653
char __thiscall LongIntegerPropertyValue::FromFileNode(LongIntegerPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@2
  int v6; // ecx@2
  char *v7; // esi@4
  int v8; // eax@6
  int v10; // ecx@8
  char *v11; // esi@9
  int v12; // edx@11
  PFileNode *v13; // esi@12
  int v14; // eax@12
  PFileNode *v15; // esi@12
  int v16; // esi@12
  int v17; // edx@12
  int v18; // [sp-4h] [bp-10h]@4

  v3 = _node;
  v4 = (int)this;
  if ( !_node )
    return 0;
  _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = PFileNode::GetLeaf(v3);
  if ( !v5 || !PFileNode::GetNameAsPString((PFileNode *)v5, v4, (PStringBase<char> *)&_node) )
  {
    v18 = v6;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v18, "Couldn't read value.");
    PFileNode::ReportError(v4, v3, (PStringBase<char>)v18);
    v7 = (char *)&_node[-1].sub_nodes.m_num;
    if ( !InterlockedDecrement((volatile LONG *)&_node[-1].m_bProcessed) )
    {
      if ( v7 )
      {
        v8 = *(_DWORD *)v7;
        v18 = 1;
        (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
      }
    }
    return 0;
  }
  v18 = (int)_node;
  InterlockedIncrement((volatile LONG *)&_node[-1].m_bProcessed);
  if ( !PSUtils::is_int64((PStringBase<char>)v18) )
  {
    v18 = v10;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v18, "Not an int64.");
    PFileNode::ReportError(v4, v3, (PStringBase<char>)v18);
    v11 = (char *)&_node[-1].sub_nodes.m_num;
    if ( !InterlockedDecrement((volatile LONG *)&_node[-1].m_bProcessed) && v11 )
    {
      v12 = *(_DWORD *)v11;
      v18 = 1;
      (*(void (__thiscall **)(char *, signed int))v12)(v11, 1);
      return 0;
    }
    return 0;
  }
  v13 = _node;
  v18 = 0;
  *__errno() = 0;
  v14 = strtoint64((const char *)v13, 0, v18);
  v15 = _node;
  *(_DWORD *)(v4 + 8) = v14;
  v16 = (int)&v15[-1].sub_nodes.m_num;
  v18 = v16 + 4;
  *(_DWORD *)(v4 + 12) = v17;
  if ( !InterlockedDecrement((volatile LONG *)v18) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  return 1;
}

//----- (00427570) --------------------------------------------------------  // acclient.c:99727
bool __cdecl PSUtils::is_int64(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  strtoint64(str.m_charbuffer->m_data, &end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (004275E0) --------------------------------------------------------  // acclient.c:99743
char __thiscall LongIntegerPropertyValue::ToFileNode(LongIntegerPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // ebp@1
  LongIntegerPropertyValue *v4; // edi@1
  int v5; // ebx@2
  int v6; // edi@2
  PStringBase<char> v7; // edi@2
  volatile LONG *v8; // ebx@2
  PFileNode *v9; // ebx@2
  char *v10; // esi@5
  PStringBase<char> str; // [sp+10h] [bp-4h]@2

  v3 = _node;
  v4 = this;
  if ( !_node )
    return 0;
  _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v5 = LODWORD(v4->m_value);
  v6 = HIDWORD(v4->m_value);
  PStringBase<char>::PStringBase<char>(&str);
  PStringBase<char>::sprintf(&str, "%I64d", v5, v6);
  PStringBase<char>::append_string((PStringBase<char> *)&_node, &str);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&str);
  v7.m_charbuffer = (PSRefBufferCharData<char> *)_node;
  v8 = (volatile LONG *)&_node[-1].m_bProcessed;
  InterlockedIncrement((volatile LONG *)&_node[-1].m_bProcessed);
  InterlockedIncrement(v8);
  v9 = PFileNode::MakeSubNodeAsPString(v3, v7);
  if ( !InterlockedDecrement((volatile LONG *)&v7.m_charbuffer[-1])
    && v7.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v7.m_charbuffer[-2].m_data[12])(&v7.m_charbuffer[-2].m_data[12], 1);
  v10 = (char *)&_node[-1].sub_nodes.m_num;
  if ( !v9 )
  {
    if ( !InterlockedDecrement((volatile LONG *)v10 + 1) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
    return 0;
  }
  if ( !InterlockedDecrement((volatile LONG *)v10 + 1) )
  {
    if ( v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  }
  return 1;
}

//----- (004276D0) --------------------------------------------------------  // acclient.c:99791
char __thiscall LongIntegerPropertyValue::GetValueAsString(LongIntegerPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  LongIntegerPropertyValue *v4; // esi@1
  int v5; // ebx@1
  int v6; // esi@2
  char result; // al@2
  int v8; // ebp@3
  int v9; // ebp@5
  int v10; // ebp@8
  int v11; // esi@8
  int v12; // esi@10

  v4 = this;
  PStringBase<char>::clear(_value);
  v5 = LODWORD(v4->m_value);
  if ( rawValue )
  {
    v6 = HIDWORD(v4->m_value);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&rawValue);
    PStringBase<char>::sprintf((PStringBase<char> *)&rawValue, "%I64d", v5, v6);
    PStringBase<char>::append_string(_value, (PStringBase<char> *)&rawValue);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rawValue);
    result = 1;
  }
  else
  {
    v8 = HIDWORD(v4->m_value);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&rawValue);
    PStringBase<char>::sprintf((PStringBase<char> *)&rawValue, "0x%016I64X", v5, v8);
    PStringBase<char>::append_string(_value, (PStringBase<char> *)&rawValue);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rawValue);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&rawValue, " (");
    if ( *(_DWORD *)(rawValue - 4) != 1 )
      PStringBase<char>::append_string(_value, (PStringBase<char> *)&rawValue);
    v9 = rawValue - 20;
    if ( !InterlockedDecrement((volatile LONG *)(rawValue - 20 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = LODWORD(v4->m_value);
    v11 = HIDWORD(v4->m_value);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&rawValue);
    PStringBase<char>::sprintf((PStringBase<char> *)&rawValue, "%I64d", v10, v11);
    PStringBase<char>::append_string(_value, (PStringBase<char> *)&rawValue);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rawValue);
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&rawValue, ")");
    if ( *(_DWORD *)(rawValue - 4) != 1 )
      PStringBase<char>::append_string(_value, (PStringBase<char> *)&rawValue);
    v12 = rawValue - 20;
    if ( !InterlockedDecrement((volatile LONG *)(rawValue - 20 + 4)) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
    }
    result = 1;
  }
  return result;
}

//----- (00427830) --------------------------------------------------------  // acclient.c:99849
bool __thiscall PositionPropertyValue::ToFileNode(PositionPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PSRefBufferCharData<char> *v3; // ecx@1
  int v4; // eax@2
  PStringBase<char> v6; // [sp-4h] [bp-204h]@2
  char szBuffer[512]; // [sp+0h] [bp-200h]@1

  if ( Position::ToString(&this->m_value, szBuffer, 0x200u) )
  {
    v6.m_charbuffer = v3;
    PStringBase<char>::PStringBase<char>(&v6, szBuffer);
    v4 = PFileNode::MakeSubNodeAsPString(_node, v6) != 0;
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  return v4;
}

//----- (00427880) --------------------------------------------------------  // acclient.c:99870
char __thiscall PositionPropertyValue::GetValueAsString(PositionPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  char szBuffer[512]; // [sp+0h] [bp-200h]@1

  Position::ToString(&this->m_value, szBuffer, 0x200u);
  PStringBase<char>::set(_value, szBuffer);
  return 1;
}

//----- (004278C0) --------------------------------------------------------  // acclient.c:99880
char __thiscall StringInfoPropertyValue::FromFileNode(StringInfoPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  int v3; // eax@2
  char v4; // bl@4
  char *v5; // esi@4
  int v6; // eax@8
  char *v7; // esi@9
  PSRefBufferCharData<char> *v9; // ecx@13
  char *v10; // esi@14
  int v11; // edx@16
  PStringBase<char> v12; // [sp-4h] [bp-B0h]@14
  PStringBase<char> strNode; // [sp+10h] [bp-9Ch]@2
  PStringBase<char> rhs; // [sp+14h] [bp-98h]@4
  StringInfoPropertyValue *v15; // [sp+18h] [bp-94h]@1
  StringInfo v16; // [sp+1Ch] [bp-90h]@8

  v15 = this;
  if ( !_node )
    return 0;
  strNode.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = PFileNode::GetLeaf(_node);
  if ( !v3 || !PFileNode::GetNameAsPString((PFileNode *)v3, (int)_node, &strNode) )
    goto LABEL_20;
  PStringBase<char>::PStringBase<char>(&rhs, "INVALID");
  v4 = PStringBase<char>::eq(&strNode, &rhs, 0);
  v5 = &rhs.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  if ( !v4 )
  {
LABEL_20:
    if ( StringInfo::FromFileNode(&v15->m_value, _node) )
      goto LABEL_9;
    v12.m_charbuffer = v9;
    PStringBase<char>::PStringBase<char>(&v12, "Error loading stringinfo!");
    PFileNode::ReportError((int)_node, _node, v12);
    v10 = &strNode.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strNode.m_charbuffer[-1]) && v10 )
    {
      v11 = *(_DWORD *)v10;
      v12.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
    }
    return 0;
  }
  StringInfo::StringInfo(&v16);
  StringInfo::operator=(&v15->m_value, v6);
  StringInfo::~StringInfo(&v16);
LABEL_9:
  v7 = &strNode.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strNode.m_charbuffer[-1]) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  }
  return 1;
}

//----- (00427A00) --------------------------------------------------------  // acclient.c:99940
char __thiscall StringInfoPropertyValue::ToFileNode(StringInfoPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PSRefBufferCharData<char> *v3; // ecx@2
  char result; // al@3
  PStringBase<char> v5; // [sp-4h] [bp-Ch]@4

  if ( _node )
  {
    if ( StringInfo::IsValid(&this->m_value, 1) )
    {
      BasePropertyValue::InqTimeStamp((PStringBase<char> *)_node);
      result = 1;
    }
    else
    {
      v5.m_charbuffer = v3;
      PStringBase<char>::PStringBase<char>(&v5, "INVALID");
      PFileNode::MakeSubNodeAsPString(_node, v5);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00427A50) --------------------------------------------------------  // acclient.c:99969
char __thiscall StringInfoPropertyValue::GetValueAsString(StringInfoPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  StringInfoPropertyValue *v4; // esi@1
  PStringBase<unsigned short> *v5; // eax@2
  int v6; // esi@2
  char *v7; // esi@8
  PStringBase<unsigned short> *v9; // eax@12
  int v10; // esi@12
  int v11; // esi@20
  char *v12; // esi@23
  PStringBase<char> filename; // [sp+8h] [bp-8h]@2
  int oldState; // [sp+Ch] [bp-4h]@2

  v4 = this;
  if ( this->m_value.m_Override == 1 )
  {
    v5 = StringInfo::GetLiteralValue(&this->m_value, (PStringBase<unsigned short> *)&oldState, 0);
    PSUtils::narrowify(&filename, v5);
    v6 = oldState - 20;
    if ( !InterlockedDecrement((volatile LONG *)(oldState - 20 + 4)) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    if ( rawValue )
      PStringBase<char>::sprintf(_value, "%s", filename.m_charbuffer);
    else
      PStringBase<char>::sprintf(_value, "Literal: %s", filename.m_charbuffer);
    v7 = &filename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&filename.m_charbuffer[-1]) && v7 )
    {
      (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
      return 1;
    }
    return 1;
  }
  if ( !rawValue )
  {
    filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    if ( !StringInfo::InqStringTableFile(&v4->m_value, &filename) )
      PStringBase<char>::sprintf(&filename, "0x%08X", v4->m_value.m_tableID.id);
    *(_DWORD *)&rawValue = v4->m_value.m_strToken.m_charbuffer;
    InterlockedIncrement((volatile LONG *)(rawValue - 16));
    if ( *(_DWORD *)(rawValue - 4) == 1 )
      PStringBase<char>::sprintf((PStringBase<char> *)&rawValue, "0x%08x", v4->m_value.m_stringID);
    PStringBase<char>::sprintf(_value, "%s:%s", filename.m_charbuffer, rawValue);
    v11 = rawValue - 20;
    if ( !InterlockedDecrement((volatile LONG *)(rawValue - 20 + 4)) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v12 = &filename.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&filename.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    return 1;
  }
  LOBYTE(oldState) = DBObj::InitLoad();
  v9 = StringInfo::GetString(&v4->m_value, (PStringBase<unsigned short> *)&rawValue, 0);
  PStringBase<char>::sprintf(_value, "%ls", v9->m_charbuffer);
  v10 = rawValue - 20;
  if ( !InterlockedDecrement((volatile LONG *)(rawValue - 20 + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  DBObj::InitLoad();
  return 1;
}

//----- (00427C50) --------------------------------------------------------  // acclient.c:100032
void __thiscall StringPropertyValue::Serialize(StringPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  PStringBase<char>::Serialize(&this->m_value, io_archive);
}

//----- (00427C60) --------------------------------------------------------  // acclient.c:100038
char __thiscall StringTokenPropertyValue::GetValueAsString(StringTokenPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  StringTokenPropertyValue *v4; // esi@1
  PSRefBufferCharData<char> *v5; // esi@1

  v4 = this;
  PStringBase<char>::sprintf(_value, "0x%08x", this->m_value);
  v5 = v4->m_tokenName.m_charbuffer;
  if ( *(_DWORD *)&v5[-1].m_data[12] != 1 && !rawValue )
    PStringBase<char>::sprintf_append(_value, " <%s>", v5);
  return 1;
}

//----- (00427CB0) --------------------------------------------------------  // acclient.c:100052
char __userpurge TriStatePropertyValue::FromFileNode@<al>(TriStatePropertyValue *this@<ecx>, int a2@<edi>, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v4; // esi@1
  TriStatePropertyValue *v5; // ebp@1
  char v6; // bl@2
  int v7; // eax@2
  PSRefBufferCharData<char> *v8; // ecx@2
  PSRefBufferCharData<char> *v9; // ecx@9
  char *v10; // esi@13
  int v11; // eax@15
  PStringBase<char> v13; // [sp-4h] [bp-14h]@4

  v4 = _node;
  v5 = this;
  if ( !_node )
    return 0;
  _node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
  v6 = 1;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v7 = PFileNode::GetLeaf(v4);
  if ( !v7 || !PFileNode::GetNameAsPString((PFileNode *)v7, a2, (PStringBase<char> *)&_node) )
  {
    v13.m_charbuffer = v8;
    PStringBase<char>::PStringBase<char>(&v13, "Expecting a leaf string node");
LABEL_12:
    PFileNode::ReportError(a2, v4, v13);
    v6 = 0;
    goto LABEL_13;
  }
  a2 = (int)__stricmp;
  if ( !__stricmp((const char *)_node, KW_TRUE.m_charbuffer->m_data) )
  {
    v5->m_value = 1;
  }
  else if ( !__stricmp((const char *)_node, KW_FALSE.m_charbuffer->m_data) )
  {
    v5->m_value = 0;
  }
  else
  {
    if ( __stricmp((const char *)_node, KW_UNDEF.m_charbuffer->m_data) )
    {
      v13.m_charbuffer = v9;
      PStringBase<char>::PStringBase<char>(&v13, "Unknown Keyword");
      goto LABEL_12;
    }
    v5->m_value = 255;
  }
LABEL_13:
  v10 = (char *)&_node[-1].sub_nodes.m_num;
  if ( !InterlockedDecrement((volatile LONG *)&_node[-1].m_bProcessed) )
  {
    if ( v10 )
    {
      v11 = *(_DWORD *)v10;
      v13.m_charbuffer = (PSRefBufferCharData<char> *)1;
      (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
    }
  }
  return v6;
}

//----- (00427DB0) --------------------------------------------------------  // acclient.c:100115
char __thiscall TimeStampPropertyValue::FromFileNode(TimeStampPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  TimeStampPropertyValue *v3; // esi@1
  int v4; // eax@2
  int v5; // esi@3
  PSRefBufferCharData<char> *v6; // ecx@3
  char result; // al@6
  PStringBase<char> v8; // [sp-4h] [bp-Ch]@5

  v3 = this;
  if ( _node
    && (v4 = PFileNode::GetLeaf(_node)) != 0
    && (v5 = (int)&v3->m_value, PFileNode::GetNameAsDouble((PFileNode *)v4, v5, (long double *)v5)) )
  {
    if ( *(double *)v5 != -1.0 )
    {
      v8.m_charbuffer = v6;
      PStringBase<char>::PStringBase<char>(
        &v8,
        "TimeStamp Properties are a runtime only mechanism for tracking server time. Only INVALID_TIME can be packed!");
      PFileNode::ReportError((int)_node, _node, v8);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00427E10) --------------------------------------------------------  // acclient.c:100147
char __userpurge PFileNode::GetNameAsDouble@<al>(PFileNode *this@<ecx>, int a2@<esi>, long double *o_name)
{
  PFileNode *v3; // edi@1
  IFileNodeName *v4; // ecx@1
  char v5; // bl@1
  int v6; // eax@2
  IFileNodeName *v7; // ecx@2
  void *v9; // eax@4
  void *v10; // esi@5
  IFileNodeName *v11; // ecx@8
  char *v12; // esi@12
  PStringBase<char> oldName; // [sp+Ch] [bp-4h]@1

  oldName.m_charbuffer = (PSRefBufferCharData<char> *)this;
  v3 = this;
  v4 = this->m_pcName;
  v5 = 0;
  if ( v4 )
  {
    v6 = ((int (*)(void))v4->vfptr->GetType)();
    v7 = v3->m_pcName;
    if ( v6 == 3 )
    {
      *(_QWORD *)o_name = *(_QWORD *)&v7[2].vfptr;
      return 1;
    }
    ((void (__stdcall *)(PStringBase<char> *, int))v7->vfptr->ToPString)(&oldName, a2);
    v9 = operator new(0x10u);
    if ( v9 )
    {
      *(_DWORD *)v9 = &FileNodeName_Double::vftable;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    if ( (unsigned __int8)(*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 16))(v10) )
    {
      *(_QWORD *)o_name = *((_QWORD *)v10 + 1);
      v11 = v3->m_pcName;
      if ( v11 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v3->m_pcName = (IFileNodeName *)v10;
      v5 = 1;
    }
    else
    {
      (**(void (__thiscall ***)(void *, signed int))v10)(v10, 1);
    }
    v12 = &oldName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&oldName.m_charbuffer[-1]) )
    {
      if ( v12 )
        (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    }
  }
  return v5;
}
// 796E28: using guessed type int (__thiscall *FileNodeName_Double::vftable)(void *, char);

//----- (00427ED0) --------------------------------------------------------  // acclient.c:100209
char __thiscall TimeStampPropertyValue::GetValueAsString(TimeStampPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::sprintf(_value, "%.3g", LODWORD(this->m_value), HIDWORD(this->m_value));
  return 1;
}

//----- (00427EF0) --------------------------------------------------------  // acclient.c:100216
char __thiscall VectorPropertyValue::GetValueAsString(VectorPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  PStringBase<char>::sprintf(_value, "%.3f %.3f %.3f", this->m_value.x, this->m_value.y, this->m_value.z);
  return 1;
}

//----- (00427F20) --------------------------------------------------------  // acclient.c:100223
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::resize_internal(v2, *v3);
}

//----- (00427F70) --------------------------------------------------------  // acclient.c:100241
void __thiscall ArrayPropertyValue::Copy(ArrayPropertyValue *this)
{
  ArrayPropertyValue *v1; // esi@1
  ArrayPropertyValue *v2; // eax@1

  v1 = this;
  v2 = (ArrayPropertyValue *)operator new(0x14u);
  if ( v2 )
    ArrayPropertyValue::ArrayPropertyValue(v2, &v1->m_value);
}

//----- (00427FA0) --------------------------------------------------------  // acclient.c:100253
void __thiscall ArrayPropertyValue::ArrayPropertyValue(ArrayPropertyValue *this, SmartArray<BaseProperty,1> *i_rcValue)
{
  ArrayPropertyValue *v2; // esi@1
  char *v3; // ecx@1

  v2 = this;
  v3 = (char *)&this->m_value;
  v2->m_cRef = 1;
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ArrayPropertyValue::vftable;
  *(_DWORD *)v3 = 0;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  SmartArray<BaseProperty,1>::operator=((SmartArray<BaseProperty,1> *)v3, (int)i_rcValue);
}
// 7973E0: using guessed type int (__thiscall *ArrayPropertyValue::vftable)(void *, char);

//----- (00427FD0) --------------------------------------------------------  // acclient.c:100270
void __thiscall ArrayPropertyValue::Serialize(ArrayPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  SmartArray<BaseProperty,1>::Serialize(&this->m_value, io_archive);
}

//----- (00427FE0) --------------------------------------------------------  // acclient.c:100276
void __thiscall SmartArray<BaseProperty,1>::Serialize(SmartArray<BaseProperty,1> *this, Archive *io_rcArchive)
{
  SmartArray<BaseProperty,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<BaseProperty,1>::SetNElements(v2, v3, 1);
  }
  v5 = 0;
  if ( v2->m_num )
  {
    do
      BaseProperty::Serialize(&v2->m_data[v5++], io_rcArchive);
    while ( v5 < v2->m_num );
  }
}

//----- (00428070) --------------------------------------------------------  // acclient.c:100314
char __thiscall SmartArray<BaseProperty,1>::SetNElements(SmartArray<BaseProperty,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<BaseProperty,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  const unsigned int v6; // ebx@7
  void *v7; // ecx@8
  int v8; // ecx@9
  int v9; // edx@9
  int v10; // ecx@13
  int v11; // edx@13
  int v12; // [sp+8h] [bp-8h]@8
  int v13; // [sp+Ch] [bp-4h]@8

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v6 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      do
      {
        v7 = &v3->m_data[v6];
        v12 = 0;
        v13 = 0;
        BaseProperty::operator=(v7, (int)&v12);
        if ( v12 )
        {
          v8 = v12;
          v9 = *(_DWORD *)(v12 + 4) - 1;
          *(_DWORD *)(v12 + 4) = v9;
          if ( !v9 )
            (**(void (__stdcall ***)(_DWORD))v8)(1);
          v12 = 0;
        }
        if ( v13 )
        {
          v10 = v13;
          v11 = *(_DWORD *)(v13 + 4) - 1;
          *(_DWORD *)(v13 + 4) = v11;
          if ( !v11 )
            (**(void (__stdcall ***)(_DWORD))v10)(1);
          v13 = 0;
        }
        ++v6;
      }
      while ( v6 < v3->m_num );
    }
    goto LABEL_17;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<BaseProperty,1>::grow(v3, v4);
  if ( result )
  {
LABEL_17:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (00428130) --------------------------------------------------------  // acclient.c:100379
char __thiscall ArrayPropertyValue::SetArrayElement(ArrayPropertyValue *this, const unsigned int _index, BaseProperty *_value)
{
  char result; // al@2

  if ( _index == this->m_value.m_num )
  {
    result = SmartArray<BaseProperty,1>::AddToEnd(&this->m_value, _value);
  }
  else if ( _index >= this->m_value.m_num )
  {
    result = 0;
  }
  else
  {
    BaseProperty::operator=(&this->m_value.m_data[_index], (int)_value);
    result = 1;
  }
  return result;
}

//----- (00428170) --------------------------------------------------------  // acclient.c:100400
char __thiscall SmartArray<BaseProperty,1>::AddToEnd(SmartArray<BaseProperty,1> *this, BaseProperty *i_rData)
{
  SmartArray<BaseProperty,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<BaseProperty,1>::grow(v2, v4)) != 0) )
  {
    BaseProperty::operator=(&v2->m_data[v2->m_num++], (int)i_rData);
    result = 1;
  }
  return result;
}

//----- (004281C0) --------------------------------------------------------  // acclient.c:100420
BasePropertyDesc *__thiscall MasterProperty::AccessPropertyDesc(MasterProperty *this, unsigned int _name_enum)
{
  HashTableData<unsigned long,BasePropertyDesc *> *v2; // eax@1
  BasePropertyDesc *result; // eax@4

  v2 = this->m_properties.m_intrusiveTable.m_buckets[_name_enum % this->m_properties.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != _name_enum )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = v2->m_data;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (00428200) --------------------------------------------------------  // acclient.c:100443
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,BasePropertyDesc *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,BasePropertyDesc *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7970C8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable[3])(void *, char);

//----- (00428290) --------------------------------------------------------  // acclient.c:100476
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,BaseProperty> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,BaseProperty> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7970CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char);

//----- (00428320) --------------------------------------------------------  // acclient.c:100509
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::add_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, HashTableData<unsigned long,BaseProperty> *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // esi@1
  HashTableData<unsigned long,BaseProperty> **v3; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::grow(this);
  v3 = &v2->m_buckets[data->m_hashKey % v2->m_numBuckets];
  data->m_hashNext = *v3;
  *v3 = data;
  if ( v3 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = v3;
  ++v2->m_numElements;
}

//----- (00428360) --------------------------------------------------------  // acclient.c:100526
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<unsigned long,BaseProperty> *v4; // ebx@3
  int v5; // ecx@4
  HashTableData<unsigned long,BaseProperty> **v6; // eax@5
  int v7; // eax@6
  HashTableData<unsigned long,BaseProperty> **v8; // ecx@7
  HashTableData<unsigned long,BaseProperty> *v9; // edi@7
  _BYTE v10[12]; // ST08_12@9
  unsigned int v11; // ST10_4@12
  HashTableData<unsigned long,BaseProperty> *v12; // edi@12
  HashTableData<unsigned long,BaseProperty> *v13; // ebp@13
  unsigned int *v14; // ebx@14
  unsigned int *v15; // eax@14
  int v16; // eax@18

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<unsigned long,BaseProperty> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<unsigned long,BaseProperty> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        *(_QWORD *)&v10[4] = __PAIR__((unsigned int)v9, (unsigned int)v8);
        *(_DWORD *)v10 = v2;
        IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::remove(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v2,
          *(IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)v10);
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<unsigned long,BaseProperty> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v11 = _numBuckets;
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v2,
      v11);
    v12 = v4;
    if ( v4 )
    {
      do
      {
        v13 = v12->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v2->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::resize_internal(v2, *v15);
        }
        v16 = (int)&v2->m_buckets[v12->m_hashKey % v2->m_numBuckets];
        v12->m_hashNext = *(HashTableData<unsigned long,BaseProperty> **)v16;
        *(_DWORD *)v16 = v12;
        if ( (HashTableData<unsigned long,BaseProperty> **)v16 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<unsigned long,BaseProperty> **)v16;
        ++v2->m_numElements;
        v12 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (004284E0) --------------------------------------------------------  // acclient.c:100644
void __thiscall ArrayPropertyValue::PushArrayElement(ArrayPropertyValue *this, BaseProperty *i_rcElement)
{
  SmartArray<BaseProperty,1>::AddToEnd(&this->m_value, i_rcElement);
}

//----- (004284F0) --------------------------------------------------------  // acclient.c:100650
void __thiscall TimeStampPropertyValue::Serialize(TimeStampPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  TimeStampPropertyValue *v3; // edi@1
  MasterProperty *v4; // esi@1
  HashTableData<unsigned long,BasePropertyDesc *> *v5; // eax@1
  BasePropertyDesc *v6; // eax@6
  long double *v7; // edi@8
  MasterPropertyGrabber mpr; // [sp+0h] [bp-4h]@1

  mpr.m_object = (MasterProperty *)this;
  v3 = this;
  MasterPropertyGrabber::MasterPropertyGrabber(&mpr);
  v4 = mpr.m_object;
  v5 = mpr.m_object->m_properties.m_intrusiveTable.m_buckets[i_eName
                                                           % mpr.m_object->m_properties.m_intrusiveTable.m_numBuckets];
  if ( !v5 )
    goto LABEL_15;
  while ( v5->m_hashKey != i_eName )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
    {
      Archive::RaiseError(io_archive);
      goto LABEL_11;
    }
  }
  if ( v5 && (v6 = v5->m_data) != 0 )
  {
    v7 = &v3->m_value;
    if ( v6->m_bAbsoluteTimeStamp )
      Serializer::SerializePrimitive(v7, io_archive);
    else
      Serializer::SerializeRelativeTime(v7, io_archive, *(long double *)&Timer::cur_time);
  }
  else
  {
LABEL_15:
    Archive::RaiseError(io_archive);
  }
LABEL_11:
  if ( v4 )
    v4->vfptr->Release((Interface *)v4);
}

//----- (004285A0) --------------------------------------------------------  // acclient.c:100695
void __cdecl Serializer::SerializeRelativeTime(long double *io_rtTime, Archive *io_rcArchive, long double i_tCurrentTime)
{
  unsigned int v3; // eax@5
  double tRelativeTime; // [sp+8h] [bp-8h]@0

  if ( (io_rcArchive->m_flags & 5) == 1 )
  {
    if ( *io_rtTime == -1.0 )
      tRelativeTime = 3.402823466385289e38;
    else
      tRelativeTime = *io_rtTime - i_tCurrentTime;
  }
  Archive::CheckAlignment(io_rcArchive, 8u);
  v3 = Archive::GetBytes(io_rcArchive, 8u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(double *)v3 = tRelativeTime;
    else
      tRelativeTime = *(double *)v3;
  }
  if ( !(io_rcArchive->m_flags & 5) )
  {
    if ( tRelativeTime == 3.402823466385289e38 )
      *(_QWORD *)io_rtTime = *(_QWORD *)&INVALID_TIME_3;
    else
      *io_rtTime = tRelativeTime + i_tCurrentTime;
  }
}

//----- (00428660) --------------------------------------------------------  // acclient.c:100726
void __cdecl _SerializeIntrusiveHashTable____PAVMasterProperty__V__IntrusiveHashTable_KPAV__HashTableData_KPAVBasePropertyDesc_____0A___PAV__HashTableData_KPAVBasePropertyDesc____USB_HashData___SB_Hash_USB_Default__U__SB_Alloc_USB_DefaultAllocator___0A_USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVMasterProperty__AAV__IntrusiveHashTable_KPAV__HashTableData_KPAVBasePropertyDesc_____0A___AAVArchive___Z(MasterProperty *const *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *io_object, Archive *io_archive)
{
  Archive *v3; // esi@1
  unsigned int *v4; // edi@4
  unsigned int *v5; // ebp@4
  const unsigned int *v6; // eax@4
  int v7; // ebx@6
  unsigned int v8; // eax@8
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // eax@19
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // ebp@19
  HashTableData<unsigned long,HeritageGroup_CG> *v11; // edi@19
  HashTableData<unsigned long,HeritageGroup_CG> **v12; // ebx@19
  unsigned int v13; // eax@21
  BasePropertyDesc *v14; // eax@27
  HeritageGroup_CGVtbl *v15; // eax@28
  BasePropertyDesc *v16; // ecx@31
  unsigned int v17; // eax@39
  HashTableData<unsigned long,Sex_CG> *v18; // ebx@40
  unsigned int v19; // ebp@40
  void *v20; // eax@41
  void *v21; // edi@41
  unsigned int v22; // eax@43
  BasePropertyDesc *v23; // eax@49
  int v24; // eax@50
  BasePropertyDesc *v25; // ecx@53
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@19

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
  {
    v4 = g_bucketSizesEnd;
    v5 = g_bucketSizesBegin;
    io_archive = (Archive *)io_object->m_numBuckets;
    v6 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, (const unsigned int *)&io_archive);
    if ( v6 == v4 )
      --v6;
    v7 = v6 - v5;
  }
  else
  {
    LOBYTE(v7) = (_BYTE)io_archive;
  }
  Archive::CheckAlignment(v3, 1u);
  v8 = Archive::GetBytes(v3, 1u);
  if ( v8 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v8 = v7;
    else
      LOBYTE(v7) = *(_BYTE *)v8;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v7 < g_numBucketSizes )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::resize(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
        g_bucketSizesBegin[(unsigned __int8)v7]);
    else
      Archive::RaiseError(v3);
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v9 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v10 = v9->m_currHashTable;
    v11 = v9->m_currElement;
    v12 = v9->m_currBucket;
LABEL_20:
    while ( v11 )
    {
      do
      {
        Archive::CheckAlignment(v3, 4u);
        v13 = Archive::GetBytes(v3, 4u);
        if ( v13 )
        {
          if ( v3->m_flags & 1 )
            *(_DWORD *)v13 = v11->m_hashKey;
          else
            v11->m_hashKey = *(_DWORD *)v13;
        }
        if ( !((v3->m_flags >> 2) & 1) )
        {
          if ( ~LOBYTE(v3->m_flags) & 1 )
          {
            v14 = (BasePropertyDesc *)operator new(0xCCu);
            if ( v14 )
              BasePropertyDesc::BasePropertyDesc(v14);
            else
              v15 = 0;
            v11->m_data.vfptr = v15;
          }
          v16 = (BasePropertyDesc *)v11->m_data.vfptr;
          if ( v16 )
            BasePropertyDesc::Serialize(v16, v3);
          else
            Archive::RaiseError(v3);
        }
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      while ( 1 )
      {
        ++v12;
        if ( v12 == &v10->m_buckets[v10->m_numBuckets] )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          goto LABEL_20;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v17 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v17 )
    {
LABEL_60:
      Archive::RaiseError(v3);
    }
    else
    {
      v18 = 0;
      v19 = 0;
      if ( io_archive )
      {
        do
        {
          v20 = operator new(0xCu);
          v21 = 0;
          if ( v20 )
          {
            *((_DWORD *)v20 + 1) = 0;
            v21 = v20;
          }
          Archive::CheckAlignment(v3, 4u);
          v22 = Archive::GetBytes(v3, 4u);
          if ( v22 )
          {
            if ( v3->m_flags & 1 )
              *(_DWORD *)v22 = *(_DWORD *)v21;
            else
              *(_DWORD *)v21 = *(_DWORD *)v22;
          }
          if ( !((v3->m_flags >> 2) & 1) )
          {
            if ( ~LOBYTE(v3->m_flags) & 1 )
            {
              v23 = (BasePropertyDesc *)operator new(0xCCu);
              if ( v23 )
                BasePropertyDesc::BasePropertyDesc(v23);
              else
                v24 = 0;
              *((_DWORD *)v21 + 2) = v24;
            }
            v25 = (BasePropertyDesc *)*((_DWORD *)v21 + 2);
            if ( v25 )
              BasePropertyDesc::Serialize(v25, v3);
            else
              Archive::RaiseError(v3);
          }
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v21,
                  v18) )
            goto LABEL_60;
          ++v19;
          v18 = (HashTableData<unsigned long,Sex_CG> *)v21;
        }
        while ( v19 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (00428940) --------------------------------------------------------  // acclient.c:100941
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v1; // edi@1
  int v2; // ecx@2
  HashTableData<unsigned long,BaseProperty> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,BaseProperty> **v5; // edx@5
  HashTableData<unsigned long,BaseProperty> *v6; // esi@5
  HashTableData<unsigned long,BaseProperty> *v7; // eax@7
  HashTableData<unsigned long,BaseProperty> *v8; // ecx@8
  BasePropertyDesc *v9; // ecx@13
  bool v10; // zf@14
  BasePropertyValue *v11; // ecx@17

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,BaseProperty> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,BaseProperty> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_25;
    do
    {
      v8 = v7;
      v7 = v7->m_hashNext;
    }
    while ( v7 != v6 );
    if ( v8 )
      v8->m_hashNext = v7->m_hashNext;
    else
LABEL_25:
      *v5 = v7->m_hashNext;
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = v6->m_data.m_pcPropertyDesc;
      if ( v9 )
      {
        v10 = v9->m_cRef-- == 1;
        if ( v10 )
          ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
        v6->m_data.m_pcPropertyDesc = 0;
      }
      v11 = v6->m_data.m_pcPropertyValue;
      if ( v11 )
      {
        v10 = v11->m_cRef-- == 1;
        if ( v10 )
          ((void (__stdcall *)(_DWORD))v11->vfptr->__vecDelDtor)(1);
        v6->m_data.m_pcPropertyValue = 0;
      }
      operator delete(v6);
    }
  }
}

//----- (004289F0) --------------------------------------------------------  // acclient.c:101019
char __thiscall MasterProperty::CopyInto(MasterProperty *this, DBObj *retval)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v2; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v3; // edi@1
  HashTableData<unsigned long,HeritageGroup_CG> **v4; // ebx@1
  HeritageGroup_CGVtbl *v5; // esi@2
  unsigned int v6; // ebp@2
  void *v7; // eax@3
  void *v8; // esi@4
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *cur; // [sp+10h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+1Ch] [bp-Ch]@1

  v2 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_properties.m_intrusiveTable,
         &result);
  v3 = v2->m_currElement;
  v4 = v2->m_currBucket;
  cur = v2->m_currHashTable;
  if ( v3 )
  {
    do
    {
LABEL_2:
      v5 = v3->m_data.vfptr;
      v6 = v3->m_hashKey;
      if ( v5 )
      {
        ++v5[1].Serialize;
        v7 = operator new(0xCu);
        if ( v7 )
        {
          *((_DWORD *)v7 + 2) = v5;
          *(_DWORD *)v7 = v6;
          *((_DWORD *)v7 + 1) = 0;
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
                (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&retval[7].m_dataCategory,
                (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v8)
          && v8 )
          operator delete(v8);
      }
      v3 = v3->m_hashNext;
    }
    while ( v3 );
    while ( 1 )
    {
      ++v4;
      if ( v4 == &cur->m_buckets[cur->m_numBuckets] )
        break;
      if ( *v4 )
      {
        v3 = *v4;
        if ( *v4 )
          goto LABEL_2;
        return 1;
      }
    }
  }
  return 1;
}

//----- (00428AA0) --------------------------------------------------------  // acclient.c:101086
void __thiscall MasterProperty::Destroy(MasterProperty *this)
{
  MasterProperty *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v2; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  HeritageGroup_CGVtbl *v7; // ecx@2
  bool v8; // zf@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@1

  v1 = this;
  ((void (__thiscall *)(_DWORD))this->m_emapper.vfptr[2].QueryInterface)(&this->m_emapper);
  v2 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_properties.m_intrusiveTable;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v1->m_properties.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currHashTable;
  v6 = v3->m_currBucket;
  if ( v4 )
  {
    do
    {
LABEL_2:
      v7 = v4->m_data.vfptr;
      if ( v7 )
      {
        v8 = v7[1].Serialize-- == (void (__thiscall *)(HeritageGroup_CG *, Archive *))1;
        if ( v8 )
          (*(void (__stdcall **)(_DWORD))v7->Serialize)(1);
      }
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v4 = *v6;
        if ( *v6 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(v2);
}

//----- (00428B20) --------------------------------------------------------  // acclient.c:101140
HashTable<unsigned long,BasePropertyDesc *,0> *__thiscall HashTable<unsigned long,BasePropertyDesc *,0>::scalar_deleting_destructor(HashTable<unsigned long,BasePropertyDesc *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,BasePropertyDesc *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,BasePropertyDesc *,0>Vtbl *)&HashTable<unsigned long,BasePropertyDesc *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7970C8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable[3])(void *, char);
// 7976A0: using guessed type int (__thiscall *HashTable<unsigned long,BasePropertyDesc *,0>::vftable)(void *, char);

//----- (00428B80) --------------------------------------------------------  // acclient.c:101166
signed int MasterProperty::GetDBOType()
{
  return 45;
}

//----- (00428B90) --------------------------------------------------------  // acclient.c:101172
void __thiscall MasterProperty::~MasterProperty(MasterProperty *this)
{
  MasterProperty *v1; // edi@1
  void *v2; // eax@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&MasterProperty::vftable;
  MasterProperty::Destroy(this);
  v1->m_properties.vfptr = (HashTable<unsigned long,BasePropertyDesc *,0>Vtbl *)&HashTable<unsigned long,BasePropertyDesc *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_properties.m_intrusiveTable);
  v2 = v1->m_properties.m_intrusiveTable.m_buckets;
  v1->m_properties.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable;
  if ( v2 != v1->m_properties.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_properties.m_intrusiveTable.m_buckets = 0;
  v1->m_properties.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_properties.m_intrusiveTable.m_numBuckets = 0;
  v1->m_properties.m_intrusiveTable.m_numElements = 0;
  EnumMapper::~EnumMapper(&v1->m_emapper);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 7970C8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable[3])(void *, char);
// 7976A0: using guessed type int (__thiscall *HashTable<unsigned long,BasePropertyDesc *,0>::vftable)(void *, char);
// 7976A8: using guessed type __int32 (__stdcall *MasterProperty::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00428BF0) --------------------------------------------------------  // acclient.c:101198
void __thiscall MasterProperty::Serialize(MasterProperty *this, Archive *io_archive)
{
  Archive *v2; // edi@1
  MasterProperty *v3; // esi@1

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  ((void (__thiscall *)(int, Archive *))v3->m_emapper.vfptr[1].IUnknown_AddRef)(&v3->m_emapper, v2);
  if ( ~LOBYTE(v2->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v3->m_properties.m_intrusiveTable);
  _SerializeIntrusiveHashTable____PAVMasterProperty__V__IntrusiveHashTable_KPAV__HashTableData_KPAVBasePropertyDesc_____0A___PAV__HashTableData_KPAVBasePropertyDesc____USB_HashData___SB_Hash_USB_Default__U__SB_Alloc_USB_DefaultAllocator___0A_USB_Default_____1_SB_DEFAULT_ITEM_NAME__3QBDB_1_SB_DEFAULT_KEY_NAME__3QBDB_1_SB_DEFAULT_VALUE_NAME__3QBDB____YAXABQAVMasterProperty__AAV__IntrusiveHashTable_KPAV__HashTableData_KPAVBasePropertyDesc_____0A___AAVArchive___Z(
    (MasterProperty *const *)&io_archive,
    &v3->m_properties.m_intrusiveTable,
    v2);
}

//----- (00428C50) --------------------------------------------------------  // acclient.c:101216
DBObj *__cdecl MasterProperty::Allocator()
{
  void *v0; // esi@1
  DBObj *result; // eax@2

  v0 = operator new(0x1C8u);
  if ( v0 )
  {
    DBObj::DBObj((DBObj *)v0, INVALID_DID_16);
    *(_DWORD *)v0 = &MasterProperty::vftable;
    EnumMapper::EnumMapper((EnumMapper *)((char *)v0 + 48));
    *((_DWORD *)v0 + 84) = &HashTable<unsigned long,BasePropertyDesc *,0>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0> *)((char *)v0 + 340),
      0x17u);
    result = (DBObj *)v0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7976A0: using guessed type int (__thiscall *HashTable<unsigned long,BasePropertyDesc *,0>::vftable)(void *, char);
// 7976A8: using guessed type __int32 (__stdcall *MasterProperty::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00428CA0) --------------------------------------------------------  // acclient.c:101243
void __thiscall AutoGrowHashTable<unsigned long,BaseProperty>::~AutoGrowHashTable<unsigned long,BaseProperty>(AutoGrowHashTable<unsigned long,BaseProperty> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7970CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char);
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);

//----- (00428CE0) --------------------------------------------------------  // acclient.c:101264
MasterProperty *__thiscall MasterProperty::vector_deleting_destructor(MasterProperty *this, unsigned int a2)
{
  MasterProperty *v2; // esi@1

  v2 = this;
  MasterProperty::~MasterProperty(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00428D00) --------------------------------------------------------  // acclient.c:101276
AutoGrowHashTable<unsigned long,BaseProperty> *__thiscall HashTable<unsigned long,BaseProperty,1>::scalar_deleting_destructor(AutoGrowHashTable<unsigned long,BaseProperty> *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,BaseProperty> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7970CC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char);
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);

//----- (00428D60) --------------------------------------------------------  // acclient.c:101302
void __thiscall StructPropertyValue::StructPropertyValue(StructPropertyValue *this)
{
  StructPropertyValue *v1; // esi@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StructPropertyValue::vftable;
  this->m_value.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &this->m_value.m_intrusiveTable,
    0);
  v1->m_value.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 797708: using guessed type int (__thiscall *StructPropertyValue::vftable)(void *, char);

//----- (00428D90) --------------------------------------------------------  // acclient.c:101319
char __thiscall StructPropertyValue::InqStructElement(StructPropertyValue *this, unsigned int _name, BaseProperty *_value)
{
  return HashTable<unsigned long,BaseProperty,1>::lookup(
           (HashTable<unsigned long,BaseProperty,1> *)&this->m_value.vfptr,
           &_name,
           _value);
}

//----- (00428DB0) --------------------------------------------------------  // acclient.c:101328
char __thiscall HashTable<unsigned long,BaseProperty,1>::lookup(HashTable<unsigned long,BaseProperty,1> *this, const unsigned int *_key, BaseProperty *_retval)
{
  char v3; // al@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::find_internal(
    &this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    BaseProperty::operator=(_retval, (int)&result.m_currElement->m_data);
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (00428DF0) --------------------------------------------------------  // acclient.c:101350
IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::find_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *result, const unsigned int *_key)
{
  HashTableData<unsigned long,BaseProperty> **v3; // edi@1
  HashTableData<unsigned long,BaseProperty> *i; // edx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v5; // eax@4

  v3 = &this->m_buckets[*_key % this->m_numBuckets];
  for ( i = *v3; i; i = i->m_hashNext )
  {
    if ( i->m_hashKey == *_key )
      break;
  }
  v5 = result;
  result->m_currBucket = v3;
  result->m_currHashTable = this;
  result->m_currElement = i;
  return v5;
}

//----- (00428E30) --------------------------------------------------------  // acclient.c:101370
BaseProperty *__thiscall StructPropertyValue::GetStructElement(StructPropertyValue *this, const unsigned int _name)
{
  BaseProperty *v2; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::find_internal(
    &this->m_value.m_intrusiveTable,
    &result,
    &_name);
  if ( result.m_currElement )
    v2 = &result.m_currElement->m_data;
  else
    v2 = 0;
  return v2;
}

//----- (00428E60) --------------------------------------------------------  // acclient.c:101387
char __thiscall StructPropertyValue::SetStructElement(StructPropertyValue *this, unsigned int _name, BaseProperty *_value)
{
  return HashTable<unsigned long,BaseProperty,1>::set(
           (HashTable<unsigned long,BaseProperty,1> *)&this->m_value.vfptr,
           &_name,
           _value);
}

//----- (00428E80) --------------------------------------------------------  // acclient.c:101396
char __thiscall HashTable<unsigned long,BaseProperty,1>::set(HashTable<unsigned long,BaseProperty,1> *this, const unsigned int *_key, BaseProperty *_data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v3; // edi@1
  char v4; // al@2
  void *v5; // esi@3
  int v6; // ecx@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> result; // [sp+8h] [bp-Ch]@1

  v3 = &this->m_intrusiveTable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::find_internal(
    &this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    BaseProperty::operator=(&result.m_currElement->m_data, (int)_data);
    v4 = 1;
  }
  else
  {
    v5 = operator new(0x10u);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 8);
      *(_DWORD *)v5 = *_key;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)v6 = 0;
      *(_DWORD *)(v6 + 4) = 0;
      BaseProperty::operator=((char *)v5 + 8, (int)_data);
    }
    else
    {
      v5 = 0;
    }
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::find_internal(
      v3,
      &result,
      (const unsigned int *)v5);
    if ( !result.m_currElement )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::add_internal(
        v3,
        (HashTableData<unsigned long,BaseProperty> *)v5);
    v4 = 1;
  }
  return v4;
}

//----- (00428F20) --------------------------------------------------------  // acclient.c:101444
char __thiscall StructPropertyValue::RemoveStructElement(StructPropertyValue *this, unsigned int _name)
{
  return HashTable<unsigned long,BaseProperty,1>::erase(
           (HashTable<unsigned long,BaseProperty,1> *)&this->m_value.vfptr,
           &_name);
}

//----- (00428F30) --------------------------------------------------------  // acclient.c:101452
char __thiscall HashTable<unsigned long,BaseProperty,1>::erase(HashTable<unsigned long,BaseProperty,1> *this, const unsigned int *_key)
{
  HashSetData<IDClass<_tagDataID,32,0> > *v2; // eax@1
  HashSetData<IDClass<_tagDataID,32,0> > *v3; // esi@1
  unsigned int v4; // ecx@2
  bool v5; // zf@3
  HashSetData<IDClass<_tagDataID,32,0> > *v6; // ecx@6
  char result; // al@10

  v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::remove(
         (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> *)&this->m_intrusiveTable,
         (IDClass<_tagDataID,32,0> *)_key);
  v3 = v2;
  if ( v2 )
  {
    v4 = v2[1].m_hashKey.id;
    if ( v4 )
    {
      v5 = (*(_DWORD *)(v4 + 4))-- == 1;
      if ( v5 )
        (**(void (__stdcall ***)(_DWORD))v4)(1);
      v3[1].m_hashKey.id = 0;
    }
    v6 = v3[1].m_hashNext;
    if ( v6 )
    {
      v5 = v6->m_hashNext-- == (HashSetData<IDClass<_tagDataID,32,0> > *)1;
      if ( v5 )
        (*(void (__stdcall **)(_DWORD))v6->m_hashKey.id)(1);
      v3[1].m_hashNext = 0;
    }
    operator delete(v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00428F90) --------------------------------------------------------  // acclient.c:101494
StructPropertyValue *__thiscall StructPropertyValue::vector_deleting_destructor(StructPropertyValue *this, unsigned int a2)
{
  StructPropertyValue *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StructPropertyValue::vftable;
  AutoGrowHashTable<unsigned long,BaseProperty>::~AutoGrowHashTable<unsigned long,BaseProperty>(&this->m_value);
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 797708: using guessed type int (__thiscall *StructPropertyValue::vftable)(void *, char);

//----- (00428FC0) --------------------------------------------------------  // acclient.c:101510
char __thiscall StructPropertyValue::SetValue(StructPropertyValue *this, BasePropertyValue *_value)
{
  StructPropertyValue *v2; // esi@1
  int v3; // eax@1
  char result; // al@2

  v2 = this;
  v3 = ((int (*)(void))_value->vfptr[74].__vecDelDtor)();
  if ( v3 )
  {
    HashTable<unsigned long,BaseProperty,1>::operator=((int)&v2->m_value, v3);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00428FF0) --------------------------------------------------------  // acclient.c:101531
int __thiscall HashTable<unsigned long,BaseProperty,1>::operator=(int this, int a2)
{
  int v2; // eax@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v3; // edi@2
  unsigned int v4; // eax@2
  HashTableData<unsigned long,Sex_CG> *v5; // ebp@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v6; // eax@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *v8; // ecx@2
  HashTableData<unsigned long,SpellSet> **v9; // edx@2
  HashTableData<unsigned long,SpellSet> *v10; // eax@2
  void *v11; // esi@3
  HashTableData<unsigned long,SpellSet> *v12; // eax@4
  int v13; // ecx@4
  int v14; // [sp+4h] [bp-28h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> v15; // [sp+8h] [bp-24h]@2
  HashIterator<unsigned long,SpellSet,0> v16; // [sp+14h] [bp-18h]@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0> result; // [sp+20h] [bp-Ch]@2

  v2 = this;
  v14 = this;
  if ( this != a2 )
  {
    v3 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *)(this + 4);
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *)(this + 4));
    v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::nice_num_buckets(*(_DWORD *)(a2 + 108));
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::resize_internal(v3, v4);
    v5 = 0;
    v15.m_currHashTable = 0;
    v15.m_currBucket = 0;
    v15.m_currElement = 0;
    v6 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::end(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)(a2 + 4),
           &result);
    HashIterator<unsigned long,SpellSet,0>::HashIterator<unsigned long,SpellSet,0>(&v16, v6);
    v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)(a2 + 4),
           (IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&result);
    v8 = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0> *)v7->m_currHashTable;
    v9 = (HashTableData<unsigned long,SpellSet> **)v7->m_currBucket;
    v10 = (HashTableData<unsigned long,SpellSet> *)v7->m_currElement;
    v15.m_currHashTable = v8;
    v15.m_currElement = v10;
    v15.m_currBucket = v9;
    while ( v15.m_currElement != v16.m_iter.m_currElement )
    {
      v11 = operator new(0x10u);
      if ( v11 )
      {
        v12 = v15.m_currElement;
        *(_DWORD *)v11 = v15.m_currElement->m_hashKey;
        v13 = (int)((char *)v11 + 8);
        *((_DWORD *)v11 + 1) = 0;
        *(_DWORD *)v13 = 0;
        *(_DWORD *)(v13 + 4) = 0;
        BaseProperty::operator=((char *)v11 + 8, (int)&v12->m_data);
      }
      else
      {
        v11 = 0;
      }
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
        (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)v3,
        (HashTableData<unsigned long,Sex_CG> *)v11,
        v5);
      v5 = (HashTableData<unsigned long,Sex_CG> *)v11;
      IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::operator++(&v15);
    }
    v2 = v14;
  }
  return v2;
}

//----- (00429120) --------------------------------------------------------  // acclient.c:101635
void __cdecl MasterProperty::AllocatePropertyValue(unsigned int _type_enum)
{
  void *v1; // eax@2
  void *v2; // eax@4
  void *v3; // eax@6
  void *v4; // eax@8
  VectorPropertyValue *v5; // eax@10
  ColorPropertyValue *v6; // eax@12
  StringPropertyValue *v7; // eax@14
  StringInfoPropertyValue *v8; // eax@16
  void *v9; // eax@18
  void *v10; // eax@20
  WaveformPropertyValue *v11; // eax@22
  void *v12; // eax@24
  PositionPropertyValue *v13; // eax@26
  TimeStampPropertyValue *v14; // eax@28
  void *v15; // eax@30
  void *v16; // eax@32
  ArrayPropertyValue *v17; // eax@34
  StructPropertyValue *v18; // eax@36
  StringTokenPropertyValue *v19; // eax@38
  void *v20; // eax@40

  switch ( _type_enum )
  {
    case 1u:
      v1 = operator new(0xCu);
      if ( v1 )
      {
        *(_DWORD *)v1 = &BoolPropertyValue::vftable;
        *((_BYTE *)v1 + 8) = 0;
        *((_DWORD *)v1 + 1) = 1;
      }
      break;
    case 2u:
      v2 = operator new(0xCu);
      if ( v2 )
      {
        *(_DWORD *)v2 = &IntegerPropertyValue::vftable;
        *((_DWORD *)v2 + 2) = 0;
        *((_DWORD *)v2 + 1) = 1;
      }
      break;
    case 3u:
      v3 = operator new(0x10u);
      if ( v3 )
      {
        *(_DWORD *)v3 = &LongIntegerPropertyValue::vftable;
        *((_DWORD *)v3 + 2) = 0;
        *((_DWORD *)v3 + 3) = 0;
        *((_DWORD *)v3 + 1) = 1;
      }
      break;
    case 4u:
      v4 = operator new(0xCu);
      if ( v4 )
      {
        *(_DWORD *)v4 = &FloatPropertyValue::vftable;
        *((_DWORD *)v4 + 2) = 0;
        *((_DWORD *)v4 + 1) = 1;
      }
      break;
    case 5u:
      v5 = (VectorPropertyValue *)operator new(0x14u);
      if ( v5 )
        VectorPropertyValue::VectorPropertyValue(v5);
      break;
    case 6u:
      v6 = (ColorPropertyValue *)operator new(0x18u);
      if ( v6 )
        ColorPropertyValue::ColorPropertyValue(v6);
      break;
    case 7u:
      v7 = (StringPropertyValue *)operator new(0xCu);
      if ( v7 )
        StringPropertyValue::StringPropertyValue(v7);
      break;
    case 8u:
      v8 = (StringInfoPropertyValue *)operator new(0x98u);
      if ( v8 )
        StringInfoPropertyValue::StringInfoPropertyValue(v8);
      break;
    case 9u:
    case 0x14u:
      v9 = operator new(0xCu);
      if ( v9 )
      {
        *(_DWORD *)v9 = &EnumPropertyValue::vftable;
        *((_DWORD *)v9 + 2) = 0;
        *((_DWORD *)v9 + 1) = 1;
      }
      break;
    case 0xAu:
      v10 = operator new(0xCu);
      if ( v10 )
      {
        *((_DWORD *)v10 + 1) = 1;
        *(_DWORD *)v10 = &DataFilePropertyValue::vftable;
        *((_DWORD *)v10 + 2) = INVALID_DID_16.id;
      }
      break;
    case 0xBu:
      v11 = (WaveformPropertyValue *)operator new(0x34u);
      if ( v11 )
        WaveformPropertyValue::WaveformPropertyValue(v11);
      break;
    case 0xCu:
      v12 = operator new(0xCu);
      if ( v12 )
      {
        *(_DWORD *)v12 = &InstanceIDPropertyValue::vftable;
        *((_DWORD *)v12 + 2) = 0;
        *((_DWORD *)v12 + 1) = 1;
      }
      break;
    case 0xDu:
      v13 = (PositionPropertyValue *)operator new(0x50u);
      if ( v13 )
        PositionPropertyValue::PositionPropertyValue(v13);
      break;
    case 0xEu:
      v14 = (TimeStampPropertyValue *)operator new(0x10u);
      if ( v14 )
        TimeStampPropertyValue::TimeStampPropertyValue(v14);
      break;
    case 0xFu:
      v15 = operator new(0xCu);
      if ( v15 )
      {
        *(_DWORD *)v15 = &Bitfield32PropertyValue::vftable;
        *((_DWORD *)v15 + 2) = 0;
        *((_DWORD *)v15 + 1) = 1;
      }
      break;
    case 0x10u:
      v16 = operator new(0x10u);
      if ( v16 )
      {
        *(_DWORD *)v16 = &Bitfield64PropertyValue::vftable;
        *((_DWORD *)v16 + 2) = 0;
        *((_DWORD *)v16 + 3) = 0;
        *((_DWORD *)v16 + 1) = 1;
      }
      break;
    case 0x11u:
      v17 = (ArrayPropertyValue *)operator new(0x14u);
      if ( v17 )
        ArrayPropertyValue::ArrayPropertyValue(v17);
      break;
    case 0x12u:
      v18 = (StructPropertyValue *)operator new(0x7Cu);
      if ( v18 )
        StructPropertyValue::StructPropertyValue(v18);
      break;
    case 0x13u:
      v19 = (StringTokenPropertyValue *)operator new(0x10u);
      if ( v19 )
        StringTokenPropertyValue::StringTokenPropertyValue(v19);
      break;
    case 0x15u:
      v20 = operator new(0xCu);
      if ( v20 )
      {
        *(_DWORD *)v20 = &TriStatePropertyValue::vftable;
        *((_DWORD *)v20 + 2) = 255;
        *((_DWORD *)v20 + 1) = 1;
      }
      break;
    default:
      return;
  }
}
// 795C50: using guessed type int (__thiscall *Bitfield32PropertyValue::vftable)(void *, char);
// 795D90: using guessed type int (__thiscall *Bitfield64PropertyValue::vftable)(void *, char);
// 795ED0: using guessed type int (__thiscall *BoolPropertyValue::vftable)(void *, char);
// 796190: using guessed type int (__thiscall *DataFilePropertyValue::vftable)(void *, char);
// 7962D0: using guessed type int (__thiscall *EnumPropertyValue::vftable)(void *, char);
// 796410: using guessed type int (__thiscall *FloatPropertyValue::vftable)(void *, char);
// 796550: using guessed type int (__thiscall *InstanceIDPropertyValue::vftable)(void *, char);
// 796690: using guessed type int (__thiscall *IntegerPropertyValue::vftable)(void *, char);
// 7967D0: using guessed type int (__thiscall *LongIntegerPropertyValue::vftable)(void *, char);
// 796BA8: using guessed type int (__thiscall *TriStatePropertyValue::vftable)(void *, char);

//----- (00429410) --------------------------------------------------------  // acclient.c:101819
void __thiscall StructPropertyValue::Copy(StructPropertyValue *this)
{
  StructPropertyValue *v1; // esi@1
  StructPropertyValue *v2; // eax@1

  v1 = this;
  v2 = (StructPropertyValue *)operator new(0x7Cu);
  if ( v2 )
    StructPropertyValue::StructPropertyValue(v2, &v1->m_value);
}

//----- (00429440) --------------------------------------------------------  // acclient.c:101831
void __thiscall StructPropertyValue::StructPropertyValue(StructPropertyValue *this, AutoGrowHashTable<unsigned long,BaseProperty> *i_rcValue)
{
  int v2; // edi@1

  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&StructPropertyValue::vftable;
  v2 = (int)&this->m_value;
  this->m_value.vfptr = (HashTable<unsigned long,BaseProperty,1>Vtbl *)&AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>(
    &this->m_value.m_intrusiveTable,
    i_rcValue->m_intrusiveTable.m_numBuckets);
  HashTable<unsigned long,BaseProperty,1>::operator=(v2, (int)i_rcValue);
  *(_DWORD *)v2 = &AutoGrowHashTable<unsigned long,BaseProperty>::vftable;
}
// 797700: using guessed type int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char);
// 797708: using guessed type int (__thiscall *StructPropertyValue::vftable)(void *, char);

//----- (00429490) --------------------------------------------------------  // acclient.c:101849
void __thiscall StructPropertyValue::Serialize(StructPropertyValue *this, Archive *io_archive, const unsigned int i_eName)
{
  Archive *v3; // edi@1
  StructPropertyValue *v4; // esi@1

  v3 = io_archive;
  v4 = this;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::delete_contents(&this->m_value.m_intrusiveTable);
  SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>,HashTableData<unsigned long,BaseProperty> *,SB_Default>(
    (const int *)&io_archive,
    &v4->m_value.m_intrusiveTable,
    v3);
}

//----- (004294C0) --------------------------------------------------------  // acclient.c:101865
void __cdecl SerializeIntrusiveHashTable<int,IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>,HashTableData<unsigned long,BaseProperty> *,SB_Default>(const int *_class, IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *io_object, Archive *io_archive)
{
  Archive *v3; // ebp@1
  signed int v4; // ebx@4
  unsigned int v5; // eax@6
  unsigned int v6; // eax@13
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@17
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v8; // ebx@17
  HashTableData<unsigned long,HeritageGroup_CG> *v9; // edi@17
  HashTableData<unsigned long,HeritageGroup_CG> **v10; // esi@17
  unsigned int v11; // eax@24
  HashTableData<unsigned long,Sex_CG> *v12; // edi@25
  unsigned int v13; // ebx@25
  HashTableData<unsigned long,BaseProperty> *v14; // esi@26
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@17

  v3 = io_archive;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::clear((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object);
  if ( (v3->m_flags & 5) == 1 )
    v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::get_bucket_size_pointer(io_object->m_numBuckets)
       - g_bucketSizesBegin;
  else
    LOBYTE(v4) = (_BYTE)io_archive;
  Archive::CheckAlignment(v3, 1u);
  v5 = Archive::GetBytes(v3, 1u);
  if ( v5 )
  {
    if ( v3->m_flags & 1 )
      *(_BYTE *)v5 = v4;
    else
      LOBYTE(v4) = *(_BYTE *)v5;
  }
  if ( !(v3->m_flags & 5) )
  {
    if ( (unsigned __int8)v4 < g_numBucketSizes )
    {
      v6 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::nice_num_buckets(g_bucketSizesBegin[(unsigned __int8)v4]);
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::resize_internal(io_object, v6);
    }
    else
    {
      Archive::RaiseError(v3);
    }
  }
  if ( (v3->m_flags & 5) == 1 )
    io_archive = (Archive *)io_object->m_numElements;
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v3);
  if ( (v3->m_flags & 5) == 1 )
  {
    v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)io_object,
           &result);
    v8 = v7->m_currHashTable;
    v9 = v7->m_currElement;
    v10 = v7->m_currBucket;
LABEL_18:
    while ( v9 )
    {
      do
      {
        Serializer::SerializeObject((CliDatError *)v9, v3);
        BaseProperty::Serialize((BaseProperty *)&v9->m_data, v3);
        v9 = v9->m_hashNext;
      }
      while ( v9 );
      while ( 1 )
      {
        ++v10;
        if ( v10 == &v8->m_buckets[v8->m_numBuckets] )
          break;
        if ( *v10 )
        {
          v9 = *v10;
          goto LABEL_18;
        }
      }
    }
  }
  if ( !(v3->m_flags & 5) )
  {
    v11 = Archive::GetSizeLeft(v3);
    if ( (unsigned int)io_archive > v11 )
    {
LABEL_30:
      Archive::RaiseError(v3);
    }
    else
    {
      v12 = 0;
      v13 = 0;
      if ( io_archive )
      {
        do
        {
          v14 = AllocateHashData();
          Serializer::SerializeObject((CliDatError *)v14, v3);
          BaseProperty::Serialize(&v14->m_data, v3);
          if ( (v3->m_flags >> 2) & 1 )
            break;
          if ( !IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::add_for_unpacking(
                  (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0> *)io_object,
                  (HashTableData<unsigned long,Sex_CG> *)v14,
                  v12) )
            goto LABEL_30;
          ++v13;
          v12 = (HashTableData<unsigned long,Sex_CG> *)v14;
        }
        while ( v13 < (unsigned int)io_archive );
      }
    }
  }
}
// 7946CC: using guessed type const unsigned __int32 g_numBucketSizes;

//----- (00429660) --------------------------------------------------------  // acclient.c:101981
HashTableData<unsigned long,BaseProperty> *__cdecl AllocateHashData()
{
  HashTableData<unsigned long,BaseProperty> *result; // eax@1

  result = (HashTableData<unsigned long,BaseProperty> *)operator new(0x10u);
  if ( result )
  {
    result->m_hashNext = 0;
    result->m_data.m_pcPropertyDesc = 0;
    result->m_data.m_pcPropertyValue = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006C4F00) --------------------------------------------------------  // acclient.c:733270
void _E91_1()
{
  outside_val_2 = 1000.0 + 1.0;
}

//----- (006C4F20) --------------------------------------------------------  // acclient.c:733276
void _E93()
{
  block_length_2 = 24.0 * 8.0;
}

//----- (006C4F40) --------------------------------------------------------  // acclient.c:733282
void _E95()
{
  half_square_length_2 = 24.0 * 0.5;
}

//----- (006C4F60) --------------------------------------------------------  // acclient.c:733288
int _E97_1()
{
  PStringBase<char>::PStringBase<char>(&KW_TRUE, "True");
  return atexit(_E98_24);
}

//----- (006C4F80) --------------------------------------------------------  // acclient.c:733295
int _E100_4()
{
  PStringBase<char>::PStringBase<char>(&KW_FALSE, "False");
  return atexit(_E101_54);
}

//----- (006C4FA0) --------------------------------------------------------  // acclient.c:733302
int _E103_1()
{
  PStringBase<char>::PStringBase<char>(&KW_UNDEF, "Undef");
  return atexit(_E104_24);
}

//----- (006C4FC0) --------------------------------------------------------  // acclient.c:733309
int _E106_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_1, "None");
  return atexit(_E107_56);
}

//----- (006C4FE0) --------------------------------------------------------  // acclient.c:733316
int _E109_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_1, "Speed");
  return atexit(sub_727800);
}

//----- (006C5000) --------------------------------------------------------  // acclient.c:733323
int _E112_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_1, "Noise");
  return atexit(_E113_37);
}

//----- (006C5020) --------------------------------------------------------  // acclient.c:733330
int _E115_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_1, "Sine");
  return atexit(_E116_29);
}

//----- (006C5040) --------------------------------------------------------  // acclient.c:733337
int _E118_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_1, "Square");
  return atexit(_E119_55);
}

//----- (006C5060) --------------------------------------------------------  // acclient.c:733344
int _E121_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_1, "Bounce");
  return atexit(_E122_42);
}

//----- (006C5080) --------------------------------------------------------  // acclient.c:733351
int _E124_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_1, "Perlin");
  return atexit(_E125_18);
}

//----- (006C50A0) --------------------------------------------------------  // acclient.c:733358
int _E127_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_1, "Fractal");
  return atexit(_E128_19);
}

//----- (006C50C0) --------------------------------------------------------  // acclient.c:733365
int _E130_3()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_1, "FrameLoop");
  return atexit(_E131_15);
}

//----- (006C50E0) --------------------------------------------------------  // acclient.c:733372
int _E133_3()
{
  return atexit(_E134_14);
}

//----- (006C50F0) --------------------------------------------------------  // acclient.c:733378
int _E1_16()
{
  return atexit(_E2_16);
}

//----- (00727740) --------------------------------------------------------  // acclient.c:825289
void __cdecl _E98_24()
{
  char *v0; // esi@1

  v0 = &KW_TRUE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TRUE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727770) --------------------------------------------------------  // acclient.c:825302
void __cdecl _E101_54()
{
  char *v0; // esi@1

  v0 = &KW_FALSE.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FALSE.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007277A0) --------------------------------------------------------  // acclient.c:825315
void __cdecl _E104_24()
{
  char *v0; // esi@1

  v0 = &KW_UNDEF.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_UNDEF.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007277D0) --------------------------------------------------------  // acclient.c:825328
void __cdecl _E107_56()
{
  char *v0; // esi@1

  v0 = &waveform_None_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727800) --------------------------------------------------------  // acclient.c:825341
void __cdecl sub_727800()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727830) --------------------------------------------------------  // acclient.c:825354
void __cdecl _E113_37()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727860) --------------------------------------------------------  // acclient.c:825367
void __cdecl _E116_29()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727890) --------------------------------------------------------  // acclient.c:825380
void __cdecl _E119_55()
{
  char *v0; // esi@1

  v0 = &waveform_Square_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007278C0) --------------------------------------------------------  // acclient.c:825393
void __cdecl _E122_42()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007278F0) --------------------------------------------------------  // acclient.c:825406
void __cdecl _E125_18()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727920) --------------------------------------------------------  // acclient.c:825419
void __cdecl _E128_19()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727950) --------------------------------------------------------  // acclient.c:825432
void __cdecl _E131_15()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00727980) --------------------------------------------------------  // acclient.c:825445
void __cdecl _E134_14()
{
  if ( MasterPropertyGrabber::s_spcMasterPropertyList )
  {
    (*(void (**)(void))(*(_DWORD *)MasterPropertyGrabber::s_spcMasterPropertyList + 20))();
    MasterPropertyGrabber::s_spcMasterPropertyList = 0;
  }
}
// 836DB8: using guessed type int MasterPropertyGrabber::s_spcMasterPropertyList;

