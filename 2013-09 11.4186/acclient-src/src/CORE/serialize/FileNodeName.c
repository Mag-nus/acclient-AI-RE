/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FileNodeName
   Object     : CORE\serialize\FileNodeName.obj
   Functions  : 65
   Addresses  : 00659F90 - 0077EDB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00659F90) --------------------------------------------------------  // acclient.c:623869
int __cdecl IFileNodeName::GetNameType(IFileNodeName *i_pcName)
{
  int result; // eax@2

  if ( i_pcName )
    result = ((int (*)(void))i_pcName->vfptr->GetType)();
  else
    result = 255;
  return result;
}

//----- (00659FB0) --------------------------------------------------------  // acclient.c:623881
bool __thiscall FileNodeName_Int32::operator==(FileNodeName_Int32 *this, IFileNodeName *i_rhs)
{
  FileNodeName_Int32 *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = (IFileNodeNameVtbl *)v2->m_name == i_rhs[1].vfptr;
  else
    result = 0;
  return result;
}

//----- (00659FF0) --------------------------------------------------------  // acclient.c:623897
bool __thiscall FileNodeName_UInt64::operator==(FileNodeName_Int64 *this, IFileNodeName *i_rhs)
{
  FileNodeName_Int64 *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = LODWORD(v2->m_name) == i_rhs[2].vfptr && (IFileNodeNameVtbl *)HIDWORD(v2->m_name) == i_rhs[3].vfptr;
  else
    result = 0;
  return result;
}

//----- (0065A040) --------------------------------------------------------  // acclient.c:623913
bool __thiscall FileNodeName_Double::operator==(FileNodeName_Double *this, IFileNodeName *i_rhs)
{
  FileNodeName_Double *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = fabs(v2->m_name - *(double *)&i_rhs[2].vfptr) <= 0.00000003999999797903004;
  else
    result = 0;
  return result;
}

//----- (0065A090) --------------------------------------------------------  // acclient.c:623929
bool __thiscall FileNodeName_InstanceID::operator==(FileNodeName_InstanceID *this, IFileNodeName *i_rhs)
{
  FileNodeName_InstanceID *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = LODWORD(v2->m_name.id) == i_rhs[2].vfptr && (IFileNodeNameVtbl *)HIDWORD(v2->m_name.id) == i_rhs[3].vfptr;
  else
    result = 0;
  return result;
}

//----- (0065A0E0) --------------------------------------------------------  // acclient.c:623945
bool __thiscall FileNodeName_Bool::operator==(FileNodeName_Bool *this, IFileNodeName *i_rhs)
{
  FileNodeName_Bool *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = v2->m_name == LOBYTE(i_rhs[1].vfptr);
  else
    result = 0;
  return result;
}

//----- (0065A120) --------------------------------------------------------  // acclient.c:623961
bool __thiscall FileNodeName_Binary::operator==(FileNodeName_Binary *this, IFileNodeName *i_rhs)
{
  FileNodeName_Binary *v2; // edi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2
  unsigned int v5; // ebp@3
  unsigned int v6; // eax@5

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
  {
    v5 = SmartBuffer::GetSize(&v2->m_name);
    if ( v5 == SmartBuffer::GetSize((SmartBuffer *)&i_rhs[1]) )
    {
      v6 = SmartBuffer::GetBuffer((SmartBuffer *)&i_rhs[1]);
      result = memcmp((const void *)SmartBuffer::GetBuffer(&v2->m_name), (const void *)v6, v5) == 0;
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

//----- (0065A190) --------------------------------------------------------  // acclient.c:623992
signed int FileNodeName_UInt64::GetType()
{
  return 11;
}

//----- (0065A1A0) --------------------------------------------------------  // acclient.c:623998
IFileNodeName *__thiscall FileNodeName_UInt64::Clone(FileNodeName_UInt64 *this)
{
  FileNodeName_UInt64 *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(0x10u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_UInt64::vftable;
    result[2].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name);
    result[3].vfptr = (IFileNodeNameVtbl *)HIDWORD(v1->m_name);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD868: using guessed type int (__thiscall *FileNodeName_UInt64::vftable)(void *, char);

//----- (0065A1D0) --------------------------------------------------------  // acclient.c:624020
FileNodeName_LongHex *__thiscall FileNodeName_Int64::vector_deleting_destructor(FileNodeName_LongHex *this, unsigned int a2)
{
  FileNodeName_LongHex *v2; // esi@1

  v2 = this;
  this->vfptr = (IFileNodeNameVtbl *)&IFileNodeName::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79602C: using guessed type int (__thiscall *IFileNodeName::vftable)(void *, char);

//----- (0065A1F0) --------------------------------------------------------  // acclient.c:624033
signed int FileNodeName_Int64::GetType()
{
  return 12;
}

//----- (0065A200) --------------------------------------------------------  // acclient.c:624039
IFileNodeName *__thiscall FileNodeName_Int64::Clone(FileNodeName_Int64 *this)
{
  FileNodeName_Int64 *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(0x10u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Int64::vftable;
    result[2].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name);
    result[3].vfptr = (IFileNodeNameVtbl *)HIDWORD(v1->m_name);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD884: using guessed type int (__thiscall *FileNodeName_Int64::vftable)(void *, char);

//----- (0065A230) --------------------------------------------------------  // acclient.c:624061
signed int FileNodeName_CellID::GetType()
{
  return 5;
}

//----- (0065A240) --------------------------------------------------------  // acclient.c:624067
IFileNodeName *__thiscall FileNodeName_CellID::Clone(FileNodeName_CellID *this)
{
  FileNodeName_CellID *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(8u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_CellID::vftable;
    LOWORD(result[1].vfptr) = v1->m_name.id;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD8A0: using guessed type int (__thiscall *FileNodeName_CellID::vftable)(void *, char);

//----- (0065A270) --------------------------------------------------------  // acclient.c:624088
signed int FileNodeName_InstanceID::GetType()
{
  return 6;
}

//----- (0065A280) --------------------------------------------------------  // acclient.c:624094
IFileNodeName *__thiscall FileNodeName_InstanceID::Clone(FileNodeName_InstanceID *this)
{
  FileNodeName_InstanceID *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(0x10u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_InstanceID::vftable;
    result[2].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name.id);
    result[3].vfptr = (IFileNodeNameVtbl *)HIDWORD(v1->m_name.id);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD8BC: using guessed type int (__thiscall *FileNodeName_InstanceID::vftable)(void *, char);

//----- (0065A2B0) --------------------------------------------------------  // acclient.c:624116
signed int FileNodeName_Guid::GetType()
{
  return 14;
}

//----- (0065A2C0) --------------------------------------------------------  // acclient.c:624122
IFileNodeName *__thiscall FileNodeName_Guid::Clone(FileNodeName_Guid *this)
{
  FileNodeName_Guid *v1; // esi@1
  IFileNodeName *result; // eax@1
  int v3; // esi@2
  IFileNodeName *v4; // ecx@2

  v1 = this;
  result = (IFileNodeName *)operator new(0x14u);
  if ( result )
  {
    v3 = (int)&v1->m_name;
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_Guid::vftable;
    v4 = result + 1;
    v4->vfptr = *(IFileNodeNameVtbl **)v3;
    v4[1].vfptr = *(IFileNodeNameVtbl **)(v3 + 4);
    v4[2].vfptr = *(IFileNodeNameVtbl **)(v3 + 8);
    v4[3].vfptr = *(IFileNodeNameVtbl **)(v3 + 12);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD8D8: using guessed type int (__thiscall *FileNodeName_Guid::vftable)(void *, char);

//----- (0065A300) --------------------------------------------------------  // acclient.c:624150
signed int FileNodeName_LongHex::GetType()
{
  return 13;
}

//----- (0065A310) --------------------------------------------------------  // acclient.c:624156
IFileNodeName *__thiscall FileNodeName_LongHex::Clone(FileNodeName_LongHex *this)
{
  FileNodeName_LongHex *v1; // esi@1
  IFileNodeName *result; // eax@1

  v1 = this;
  result = (IFileNodeName *)operator new(0x10u);
  if ( result )
  {
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_UInt64::vftable;
    result[2].vfptr = (IFileNodeNameVtbl *)LODWORD(v1->m_name);
    result[3].vfptr = (IFileNodeNameVtbl *)HIDWORD(v1->m_name);
    result->vfptr = (IFileNodeNameVtbl *)&FileNodeName_LongHex::vftable;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7FD868: using guessed type int (__thiscall *FileNodeName_UInt64::vftable)(void *, char);
// 7FD8F4: using guessed type int (__thiscall *FileNodeName_LongHex::vftable)(void *, char);

//----- (0065A340) --------------------------------------------------------  // acclient.c:624180
bool __thiscall FileNodeName_Float::operator==(FileNodeName_Float *this, IFileNodeName *i_rhs)
{
  FileNodeName_Float *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = fabs(v2->m_name - *(float *)&i_rhs[1].vfptr) <= 0.00019999999;
  else
    result = 0;
  return result;
}

//----- (0065A390) --------------------------------------------------------  // acclient.c:624196
bool __thiscall FileNodeName_CellID::operator==(FileNodeName_CellID *this, IFileNodeName *i_rhs)
{
  FileNodeName_CellID *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = v2->m_name.id == LOWORD(i_rhs[1].vfptr);
  else
    result = 0;
  return result;
}

//----- (0065A3D0) --------------------------------------------------------  // acclient.c:624212
bool __thiscall FileNodeName_PString::operator==(FileNodeName_PString *this, IFileNodeName *i_rhs)
{
  FileNodeName_PString *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = PStringBase<char>::operator==(&v2->m_name, (PStringBase<char> *)&i_rhs[1]);
  else
    result = 0;
  return result;
}

//----- (0065A410) --------------------------------------------------------  // acclient.c:624228
bool __thiscall FileNodeName_Guid::operator==(FileNodeName_Guid *this, IFileNodeName *i_rhs)
{
  FileNodeName_Guid *v2; // esi@1
  NodeNameType v3; // ebx@1
  bool result; // al@2

  v2 = this;
  v3 = (int)i_rhs->vfptr->GetType(i_rhs);
  if ( v3 == v2->vfptr->GetType((IFileNodeName *)v2) )
    result = (IFileNodeNameVtbl *)v2->m_name.m_data1 == i_rhs[1].vfptr
          && *(IFileNodeNameVtbl **)&v2->m_name.m_data2 == i_rhs[2].vfptr
          && *(IFileNodeNameVtbl **)&v2->m_name.m_data4[0] == i_rhs[3].vfptr
          && *(IFileNodeNameVtbl **)&v2->m_name.m_data4[4] == i_rhs[4].vfptr;
  else
    result = 0;
  return result;
}

//----- (0065A470) --------------------------------------------------------  // acclient.c:624247
char __thiscall FileNodeName_Guid::FromPString(FileNodeName_Guid *this, PStringBase<char> *i_rcString)
{
  return Turbine_GUID::Convert(&this->m_name, i_rcString->m_charbuffer->m_data);
}

//----- (0065A490) --------------------------------------------------------  // acclient.c:624253
void __thiscall FileNodeName_Int64::Serialize(FileNodeName_InstanceID *this, Archive *io_archive)
{
  Serializer::SerializePrimitive<InstanceID>(&this->m_name, io_archive);
}

//----- (0065A4B0) --------------------------------------------------------  // acclient.c:624259
bool __cdecl PSUtils::is_uint32<char>(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _strtoul(str.m_charbuffer->m_data, (char **)&end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (0065A520) --------------------------------------------------------  // acclient.c:624275
bool __cdecl PSUtils::is_int32<char>(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _strtol(str.m_charbuffer->m_data, (char **)&end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (0065A590) --------------------------------------------------------  // acclient.c:624291
bool __cdecl PSUtils::is_uint64<char>(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  strtouint64(str.m_charbuffer->m_data, &end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (0065A600) --------------------------------------------------------  // acclient.c:624307
bool __cdecl PSUtils::is_int64<char>(PStringBase<char> str)
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

//----- (0065A670) --------------------------------------------------------  // acclient.c:624323
bool __cdecl PSUtils::is_double<char>(PStringBase<char> str)
{
  bool v1; // bl@3
  const char *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _strtod(str.m_charbuffer->m_data, (char **)&end);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1])
    && str.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&str.m_charbuffer[-2].m_data[12])(&str.m_charbuffer[-2].m_data[12], 1);
  return v1;
}

//----- (0065A6E0) --------------------------------------------------------  // acclient.c:624339
void __thiscall FileNodeName_CellID::Serialize(FileNodeName_CellID *this, Archive *io_archive)
{
  FileNodeName_CellID *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_archive, 2u);
  v3 = Archive::GetBytes(io_archive, 2u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_WORD *)v3 = v2->m_name.id;
    else
      v2->m_name.id = *(_WORD *)v3;
  }
}

//----- (0065A720) --------------------------------------------------------  // acclient.c:624357
void __cdecl Serializer::SerializePrimitive<InstanceID>(InstanceID *io_object, Archive *io_archive)
{
  unsigned __int64 *v2; // eax@1

  Archive::CheckAlignment(io_archive, 8u);
  v2 = (unsigned __int64 *)Archive::GetBytes(io_archive, 8u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = io_object->id;
    else
      io_object->id = *v2;
  }
}

//----- (0065A760) --------------------------------------------------------  // acclient.c:624373
void __thiscall FileNodeName_Guid::Serialize(FileNodeName_Guid *this, Archive *io_archive)
{
  char *v2; // esi@1
  unsigned int v3; // eax@1

  v2 = (char *)&this->m_name;
  Archive::CheckAlignment(io_archive, 0x10u);
  v3 = Archive::GetBytes(io_archive, 0x10u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v3 = *(_DWORD *)v2;
      *(_DWORD *)(v3 + 4) = *((_DWORD *)v2 + 1);
      *(_DWORD *)(v3 + 8) = *((_DWORD *)v2 + 2);
      *(_DWORD *)(v3 + 12) = *((_DWORD *)v2 + 3);
    }
    else
    {
      *(_DWORD *)v2 = *(_DWORD *)v3;
      *((_DWORD *)v2 + 1) = *(_DWORD *)(v3 + 4);
      *((_DWORD *)v2 + 2) = *(_DWORD *)(v3 + 8);
      *((_DWORD *)v2 + 3) = *(_DWORD *)(v3 + 12);
    }
  }
}

//----- (0065A7C0) --------------------------------------------------------  // acclient.c:624401
void __cdecl IFileNodeName::CreateFromEnum(NodeNameType i_enumType)
{
  void *v1; // eax@4
  void *v2; // eax@6
  void *v3; // eax@8
  void *v4; // eax@10
  void *v5; // eax@12
  void *v6; // eax@14
  void *v7; // eax@16
  void *v8; // eax@18
  void *v9; // eax@20
  void *v10; // eax@22
  void *v11; // eax@24
  FileNodeName_Binary *v12; // eax@26
  FileNodeName_PString *v13; // eax@28
  void *v14; // eax@30

  if ( (signed int)i_enumType <= 255 && i_enumType != 255 )
  {
    switch ( i_enumType )
    {
      case 1:
        v1 = operator new(8u);
        if ( v1 )
          *(_DWORD *)v1 = &FileNodeName_UInt32::vftable;
        break;
      case 2:
        v2 = operator new(8u);
        if ( v2 )
          *(_DWORD *)v2 = &FileNodeName_Int32::vftable;
        break;
      case 11:
        v3 = operator new(0x10u);
        if ( v3 )
          *(_DWORD *)v3 = &FileNodeName_UInt64::vftable;
        break;
      case 12:
        v4 = operator new(0x10u);
        if ( v4 )
          *(_DWORD *)v4 = &FileNodeName_Int64::vftable;
        break;
      case 3:
        v5 = operator new(0x10u);
        if ( v5 )
          *(_DWORD *)v5 = &FileNodeName_Double::vftable;
        break;
      case 4:
        v6 = operator new(8u);
        if ( v6 )
          *(_DWORD *)v6 = &FileNodeName_Float::vftable;
        break;
      case 5:
        v7 = operator new(8u);
        if ( v7 )
          *(_DWORD *)v7 = &FileNodeName_CellID::vftable;
        break;
      case 6:
        v8 = operator new(0x10u);
        if ( v8 )
          *(_DWORD *)v8 = &FileNodeName_InstanceID::vftable;
        break;
      case 8:
        v9 = operator new(8u);
        if ( v9 )
          *(_DWORD *)v9 = &FileNodeName_Hex::vftable;
        break;
      case 13:
        v10 = operator new(0x10u);
        if ( v10 )
          *(_DWORD *)v10 = &FileNodeName_LongHex::vftable;
        break;
      case 7:
        v11 = operator new(8u);
        if ( v11 )
          *(_DWORD *)v11 = &FileNodeName_Bool::vftable;
        break;
      case 9:
        v12 = (FileNodeName_Binary *)operator new(0x10u);
        if ( v12 )
          FileNodeName_Binary::FileNodeName_Binary(v12);
        break;
      case 0:
        v13 = (FileNodeName_PString *)operator new(8u);
        if ( v13 )
          FileNodeName_PString::FileNodeName_PString(v13);
        break;
      case 14:
        v14 = operator new(0x14u);
        if ( v14 )
          *(_DWORD *)v14 = &FileNodeName_Guid::vftable;
        break;
      default:
        return;
    }
  }
}
// 796010: using guessed type int (__thiscall *FileNodeName_Bool::vftable)(void *, char);
// 796E28: using guessed type int (__thiscall *FileNodeName_Double::vftable)(void *, char);
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);
// 7970EC: using guessed type int (__thiscall *FileNodeName_Hex::vftable)(void *, char);
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);
// 797124: using guessed type int (__thiscall *FileNodeName_Int32::vftable)(void *, char);
// 7FD868: using guessed type int (__thiscall *FileNodeName_UInt64::vftable)(void *, char);
// 7FD884: using guessed type int (__thiscall *FileNodeName_Int64::vftable)(void *, char);
// 7FD8A0: using guessed type int (__thiscall *FileNodeName_CellID::vftable)(void *, char);
// 7FD8BC: using guessed type int (__thiscall *FileNodeName_InstanceID::vftable)(void *, char);
// 7FD8D8: using guessed type int (__thiscall *FileNodeName_Guid::vftable)(void *, char);
// 7FD8F4: using guessed type int (__thiscall *FileNodeName_LongHex::vftable)(void *, char);

//----- (0065A970) --------------------------------------------------------  // acclient.c:624511
char __thiscall FileNodeName_UInt32::FromPString(FileNodeName_UInt32 *this, PStringBase<char> *i_rcString)
{
  FileNodeName_UInt32 *v2; // esi@1
  PStringBase<char> v3; // ST08_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_uint32<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    v2->m_name = _strtoul(v4->m_data, 0, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065A9D0) --------------------------------------------------------  // acclient.c:624536
char __thiscall FileNodeName_Int32::FromPString(FileNodeName_Int32 *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Int32 *v2; // esi@1
  PStringBase<char> v3; // ST08_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_int32<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    v2->m_name = _strtol(v4->m_data, 0, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065AA30) --------------------------------------------------------  // acclient.c:624561
char __thiscall FileNodeName_UInt64::FromPString(FileNodeName_InstanceID *this, PStringBase<char> *i_rcString)
{
  FileNodeName_InstanceID *v2; // esi@1
  PStringBase<char> v3; // ST08_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  int v5; // edx@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_uint64<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    LODWORD(v2->m_name.id) = strtouint64(v4->m_data, 0, 0);
    HIDWORD(v2->m_name.id) = v5;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065AA90) --------------------------------------------------------  // acclient.c:624588
char __thiscall FileNodeName_Int64::FromPString(FileNodeName_Int64 *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Int64 *v2; // esi@1
  PStringBase<char> v3; // ST08_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  int v5; // edx@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_int64<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    LODWORD(v2->m_name) = strtoint64(v4->m_data, 0, 0);
    HIDWORD(v2->m_name) = v5;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065AAF0) --------------------------------------------------------  // acclient.c:624615
char __thiscall FileNodeName_Double::FromPString(FileNodeName_Double *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Double *v2; // esi@1
  PStringBase<char> v3; // ST04_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_double<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    v2->m_name = _strtod(v4->m_data, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065AB50) --------------------------------------------------------  // acclient.c:624640
char __thiscall FileNodeName_Float::FromPString(FileNodeName_Float *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Float *v2; // esi@1
  PStringBase<char> v3; // ST04_4@1
  PSRefBufferCharData<char> *v4; // edi@2
  char result; // al@2

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_double<char>(v3) )
  {
    v4 = i_rcString->m_charbuffer;
    *__errno() = 0;
    v2->m_name = _strtod(v4->m_data, 0);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065ABB0) --------------------------------------------------------  // acclient.c:624665
char __thiscall FileNodeName_CellID::FromPString(FileNodeName_CellID *this, PStringBase<char> *i_rcString)
{
  FileNodeName_CellID *v2; // edi@1
  PStringBase<char> v3; // ST08_4@1
  PSRefBufferCharData<char> *v4; // esi@2
  unsigned __int32 v5; // eax@2
  char result; // al@3

  v2 = this;
  v3.m_charbuffer = i_rcString->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&i_rcString->m_charbuffer[-1]);
  if ( PSUtils::is_uint32<char>(v3)
    && (v4 = i_rcString->m_charbuffer, *__errno() = 0, v5 = _strtoul(v4->m_data, 0, 0), v5 <= 0xFFFF) )
  {
    v2->m_name.id = v5;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0065AC10) --------------------------------------------------------  // acclient.c:624690
signed int __thiscall FileNodeName_Bool::FromPString(FileNodeName_Bool *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Bool *v2; // esi@1
  signed int result; // eax@3

  v2 = this;
  if ( !__stricmp(i_rcString->m_charbuffer->m_data, TRUE_PSTRING.m_charbuffer->m_data)
    || !__stricmp(i_rcString->m_charbuffer->m_data, ONE_PSTRING.m_charbuffer->m_data) )
  {
    result = 1;
    v2->m_name = 1;
  }
  else
  {
    result = 1;
    v2->m_name = 0;
  }
  return result;
}

//----- (0065AC60) --------------------------------------------------------  // acclient.c:624711
PStringBase<char> *__thiscall FileNodeName_Bool::ToPString(FileNodeName_Bool *this, PStringBase<char> *result)
{
  PStringBase<char> *v2; // eax@1
  PSRefBufferCharData<char> *v3; // eax@3

  v2 = &TRUE_PSTRING;
  if ( !this->m_name )
    v2 = &FALSE_PSTRING;
  v3 = v2->m_charbuffer;
  result->m_charbuffer = v3;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  return result;
}

//----- (0065AC90) --------------------------------------------------------  // acclient.c:624726
char __thiscall FileNodeName_Binary::FromPString(FileNodeName_Binary *this, PStringBase<char> *i_rcString)
{
  FileNodeName_Binary *v2; // esi@1
  int v3; // eax@1
  PStringBase<char> *v4; // esi@1
  SmartBuffer result; // [sp+4h] [bp-Ch]@1

  i_rcString = (PStringBase<char> *)i_rcString->m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&i_rcString[-4]);
  PSUtils::unwrap_string((PStringBase<char> *)&i_rcString);
  v3 = (int)PSUtils::get_binary_buffer_from_string(&result, (PStringBase<char> *)&i_rcString);
  SmartBuffer::operator=((int)&v2->m_name, v3);
  SmartBuffer::ReleaseMasterBuffer(&result);
  v4 = i_rcString - 5;
  if ( !InterlockedDecrement((volatile LONG *)&i_rcString[-4]) && v4 )
    (*(void (__thiscall **)(_DWORD, _DWORD))&v4->m_charbuffer->m_data[0])(v4, 1);
  return 1;
}

//----- (0065AD10) --------------------------------------------------------  // acclient.c:624747
PStringBase<char> *__thiscall FileNodeName_Binary::ToPString(FileNodeName_Binary *this, PStringBase<char> *result)
{
  PSRefBufferCharData<char> *v2; // eax@1
  char *v3; // esi@1
  PStringBase<char> ret; // [sp+0h] [bp-4h]@1

  ret.m_charbuffer = (PSRefBufferCharData<char> *)this;
  PSUtils::stringify_buffer(&ret, &this->m_name);
  PSUtils::linewrap_string(&ret, 0x64u);
  v2 = ret.m_charbuffer;
  result->m_charbuffer = ret.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  v3 = &ret.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ret.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  return result;
}

//----- (0065AD70) --------------------------------------------------------  // acclient.c:624766
PStringBase<char> *__thiscall FileNodeName_Guid::ToPString(FileNodeName_Guid *this, PStringBase<char> *result)
{
  Turbine_GUID::ToString(&this->m_name, result);
  return result;
}

//----- (0065AD90) --------------------------------------------------------  // acclient.c:624773
void __cdecl SB_As32Bit_Compressed::Serialize<int,unsigned long>(int a1, int a2, char io_object)
{
  Archive *v3; // esi@1
  char v4; // al@1
  unsigned int v5; // eax@2
  char v6; // al@5
  char v7; // bl@8
  Archive *v8; // [sp-4h] [bp-10h]@2
  unsigned __int16 v9[2]; // [sp+4h] [bp-8h]@5
  unsigned __int16 v10[2]; // [sp+8h] [bp-4h]@6

  v3 = (Archive *)io_object;
  v4 = *(_BYTE *)(io_object + 4);
  if ( v4 & 1 )
  {
    v5 = *(_DWORD *)a2;
    v8 = (Archive *)io_object;
    if ( *(_DWORD *)a2 > 0x7Fu )
    {
      if ( v5 > 0x3FFF )
      {
        *(_DWORD *)v10 = *(_DWORD *)a2;
        io_object = BYTE3(v5) | 0xC0;
        LOBYTE(v9[0]) = v5 >> 16;
        Serializer::SerializePrimitive<unsigned char>(&io_object, v8);
        Serializer::SerializePrimitive<unsigned char>((char *)v9, v3);
        Serializer::SerializePrimitive<unsigned short>(v10, v3);
      }
      else
      {
        v6 = *(_BYTE *)a2;
        io_object = *(_BYTE *)(a2 + 1) | 0x80;
        LOBYTE(v9[0]) = v6;
        Serializer::SerializePrimitive<unsigned char>(&io_object, v8);
        Serializer::SerializePrimitive<unsigned char>((char *)v9, v3);
      }
    }
    else
    {
      io_object = v5;
      Serializer::SerializePrimitive<unsigned char>(&io_object, v8);
    }
  }
  else if ( ~v4 & 1 )
  {
    Serializer::SerializePrimitive<unsigned char>(&io_object, (Archive *)io_object);
    v7 = io_object;
    if ( io_object >= 0 )
    {
      *(_DWORD *)a2 = (unsigned __int8)io_object;
    }
    else
    {
      Serializer::SerializePrimitive<unsigned char>(&io_object, v3);
      if ( v7 & 0x40 )
      {
        Serializer::SerializePrimitive<unsigned short>(v9, v3);
        *(_DWORD *)a2 = v9[0] | ((__PAIR__((unsigned __int8)v7, io_object) & 0x3FFF) << 16);
      }
      else
      {
        *(_DWORD *)a2 = __PAIR__((unsigned __int8)v7, io_object) & 0x7FFF;
      }
    }
  }
}

//----- (0065AEC0) --------------------------------------------------------  // acclient.c:624841
void __cdecl Serializer::SerializePrimitive<unsigned short>(unsigned __int16 *io_object, Archive *io_archive)
{
  unsigned __int16 *v2; // eax@1

  Archive::CheckAlignment(io_archive, 2u);
  v2 = (unsigned __int16 *)Archive::GetBytes(io_archive, 2u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (0065AF00) --------------------------------------------------------  // acclient.c:624857
PStringBase<char> *__thiscall FileNodeName_UInt32::ToPString(FileNodeName_UInt32 *this, PStringBase<char> *result)
{
  FileNodeName_UInt32 *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST08_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%lu", v2->m_name);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065AF70) --------------------------------------------------------  // acclient.c:624880
PStringBase<char> *__thiscall FileNodeName_Int32::ToPString(FileNodeName_Int32 *this, PStringBase<char> *result)
{
  FileNodeName_Int32 *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST08_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%ld", v2->m_name);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065AFE0) --------------------------------------------------------  // acclient.c:624903
PStringBase<char> *__thiscall FileNodeName_UInt64::ToPString(FileNodeName_UInt64 *this, PStringBase<char> *result)
{
  FileNodeName_UInt64 *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%I64u", LODWORD(v2->m_name), HIDWORD(v2->m_name));
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B050) --------------------------------------------------------  // acclient.c:624926
PStringBase<char> *__thiscall FileNodeName_Int64::ToPString(FileNodeName_Int64 *this, PStringBase<char> *result)
{
  FileNodeName_Int64 *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%I64d", LODWORD(v2->m_name), HIDWORD(v2->m_name));
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B0C0) --------------------------------------------------------  // acclient.c:624949
PStringBase<char> *__thiscall FileNodeName_Double::ToPString(FileNodeName_Double *this, PStringBase<char> *result)
{
  FileNodeName_Double *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+14h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%.16g", v2->m_name);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B130) --------------------------------------------------------  // acclient.c:624972
PStringBase<char> *__thiscall FileNodeName_Float::ToPString(FileNodeName_Float *this, PStringBase<char> *result)
{
  FileNodeName_Float *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+14h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "%.8g", v2->m_name);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B1A0) --------------------------------------------------------  // acclient.c:624995
PStringBase<char> *__thiscall FileNodeName_CellID::ToPString(FileNodeName_CellID *this, PStringBase<char> *result)
{
  FileNodeName_CellID *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST08_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "0x%04X", v2->m_name.id);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B210) --------------------------------------------------------  // acclient.c:625018
PStringBase<char> *__thiscall FileNodeName_InstanceID::ToPString(FileNodeName_InstanceID *this, PStringBase<char> *result)
{
  FileNodeName_InstanceID *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "0x%016I64X", LODWORD(v2->m_name.id), HIDWORD(v2->m_name.id));
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B280) --------------------------------------------------------  // acclient.c:625041
PStringBase<char> *__thiscall FileNodeName_Hex::ToPString(FileNodeName_Hex *this, PStringBase<char> *result)
{
  FileNodeName_Hex *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST08_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "0x%08x", v2->m_name);
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (0065B2F0) --------------------------------------------------------  // acclient.c:625064
PStringBase<char> *__thiscall FileNodeName_LongHex::ToPString(FileNodeName_LongHex *this, PStringBase<char> *result)
{
  FileNodeName_LongHex *v2; // esi@1
  PSRefBufferCharData<char> *v3; // esi@1
  volatile LONG *v4; // ST0C_4@1
  int v5; // esi@1
  PStringBase<char> retval; // [sp+0h] [bp-4h]@1

  retval.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&retval, "0x%16x", LODWORD(v2->m_name), HIDWORD(v2->m_name));
  v3 = retval.m_charbuffer;
  v4 = (volatile LONG *)&retval.m_charbuffer[-1];
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return result;
}

//----- (00714BB0) --------------------------------------------------------  // acclient.c:807580
int sub_714BB0()
{
  PStringBase<char>::PStringBase<char>(&TRUE_PSTRING, "true");
  return atexit(sub_77ED50);
}

//----- (00714BD0) --------------------------------------------------------  // acclient.c:807587
int _E76_82()
{
  PStringBase<char>::PStringBase<char>(&FALSE_PSTRING, "false");
  return atexit(sub_77ED80);
}

//----- (00714BF0) --------------------------------------------------------  // acclient.c:807594
int _E79_78()
{
  PStringBase<char>::PStringBase<char>(&ONE_PSTRING, "1");
  return atexit(_E80_75);
}

//----- (0077ED50) --------------------------------------------------------  // acclient.c:917947
void __cdecl sub_77ED50()
{
  char *v0; // esi@1

  v0 = &TRUE_PSTRING.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TRUE_PSTRING.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077ED80) --------------------------------------------------------  // acclient.c:917960
void __cdecl sub_77ED80()
{
  char *v0; // esi@1

  v0 = &FALSE_PSTRING.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FALSE_PSTRING.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077EDB0) --------------------------------------------------------  // acclient.c:917973
void __cdecl _E80_75()
{
  char *v0; // esi@1

  v0 = &ONE_PSTRING.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ONE_PSTRING.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

