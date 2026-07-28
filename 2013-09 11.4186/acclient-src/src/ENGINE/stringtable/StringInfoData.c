/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StringInfoData
   Object     : ENGINE\stringtable\StringInfoData.obj
   Functions  : 46
   Addresses  : 0042E820 - 006C5820 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042E820) --------------------------------------------------------  // acclient.c:107761
void __thiscall StringInfo_StringInfoData::StringInfo_StringInfoData(StringInfo_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eType = 1;
  this->m_eVarID = i_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&StringInfo_StringInfoData::vftable;
  StringInfo::StringInfo(&this->m_cVal);
}
// 797FC0: using guessed type int (__thiscall *StringInfo_StringInfoData::vftable)(void *, char);

//----- (0042E850) --------------------------------------------------------  // acclient.c:107771
StringInfo_StringInfoData *__thiscall StringInfo_StringInfoData::vector_deleting_destructor(StringInfo_StringInfoData *this, unsigned int a2)
{
  StringInfo_StringInfoData *v2; // esi@1

  v2 = this;
  this->vfptr = (StringInfoDataVtbl *)&StringInfo_StringInfoData::vftable;
  StringInfo::~StringInfo(&this->m_cVal);
  v2->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FC0: using guessed type int (__thiscall *StringInfo_StringInfoData::vftable)(void *, char);

//----- (0042E880) --------------------------------------------------------  // acclient.c:107787
BOOL __thiscall StringInfo_StringInfoData::operator==(StringInfo_StringInfoData *this, StringInfo_StringInfoData *i_rcRhs)
{
  return this->m_eType == i_rcRhs->m_eType
      && this->m_eVarID == i_rcRhs->m_eVarID
      && StringInfo::operator==(&this->m_cVal, &i_rcRhs->m_cVal);
}

//----- (0042E8C0) --------------------------------------------------------  // acclient.c:107795
void __thiscall StringInfo_StringInfoData::GetSubDataIDs(StringInfo_StringInfoData *this, QualifiedDataIDArray *id_array)
{
  StringInfo::GetSubDataIDs(&this->m_cVal, id_array);
}

//----- (0042E8D0) --------------------------------------------------------  // acclient.c:107801
char __thiscall StringInfo_StringInfoData::IsValid(StringInfo_StringInfoData *this, int i_bValidateChildren)
{
  return StringInfo::IsValid(&this->m_cVal, i_bValidateChildren);
}

//----- (0042E8E0) --------------------------------------------------------  // acclient.c:107807
void __thiscall Double_StringInfoData::Double_StringInfoData(Double_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eVarID = i_eVarID;
  this->m_eType = 2;
  this->vfptr = (StringInfoDataVtbl *)&Double_StringInfoData::vftable;
  *(_QWORD *)&this->m_fVal = 0i64;
  this->m_iPrecision = 0;
}
// 797FD8: using guessed type int (__thiscall *Double_StringInfoData::vftable)(void *, char);

//----- (0042E910) --------------------------------------------------------  // acclient.c:107818
BOOL __thiscall Double_StringInfoData::operator==(Double_StringInfoData *this, Double_StringInfoData *i_rcRhs)
{
  return this->m_eType == i_rcRhs->m_eType
      && this->m_eVarID == i_rcRhs->m_eVarID
      && this->m_fVal == i_rcRhs->m_fVal
      && this->m_iPrecision == i_rcRhs->m_iPrecision;
}

//----- (0042E950) --------------------------------------------------------  // acclient.c:107827
void __thiscall LInt_StringInfoData::LInt_StringInfoData(LInt_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eVarID = i_eVarID;
  this->m_eType = 4;
  this->vfptr = (StringInfoDataVtbl *)&LInt_StringInfoData::vftable;
  this->m_iVal = 0i64;
}
// 797FF0: using guessed type int (__thiscall *LInt_StringInfoData::vftable)(void *, char);

//----- (0042E970) --------------------------------------------------------  // acclient.c:107837
BOOL __thiscall LInt_StringInfoData::operator==(ULInt_StringInfoData *this, ULInt_StringInfoData *i_rcRhs)
{
  return this->m_eType == i_rcRhs->m_eType
      && this->m_eVarID == i_rcRhs->m_eVarID
      && LODWORD(this->m_iVal) == LODWORD(i_rcRhs->m_iVal)
      && HIDWORD(this->m_iVal) == HIDWORD(i_rcRhs->m_iVal);
}

//----- (0042E9B0) --------------------------------------------------------  // acclient.c:107846
void __thiscall ULInt_StringInfoData::ULInt_StringInfoData(ULInt_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eVarID = i_eVarID;
  this->m_eType = 6;
  this->vfptr = (StringInfoDataVtbl *)&ULInt_StringInfoData::vftable;
  this->m_iVal = 0i64;
}
// 798008: using guessed type int (__thiscall *ULInt_StringInfoData::vftable)(void *, char);

//----- (0042E9D0) --------------------------------------------------------  // acclient.c:107856
ULInt_StringInfoData *__thiscall Double_StringInfoData::scalar_deleting_destructor(ULInt_StringInfoData *this, unsigned int a2)
{
  ULInt_StringInfoData *v2; // esi@1

  v2 = this;
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);

//----- (0042E9F0) --------------------------------------------------------  // acclient.c:107869
void __thiscall Formatted_Double_StringInfoData::Formatted_Double_StringInfoData(Formatted_Double_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eVarID = i_eVarID;
  *(_QWORD *)&this->m_fVal = 0i64;
  this->m_iPrecision = 0;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->m_bGrouping = 1;
  this->m_iBase = -1;
  this->vfptr = (StringInfoDataVtbl *)&Formatted_Double_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_Double_StringInfoData::vftable;
  this->m_eType = 3;
}
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 798020: using guessed type int (__stdcall *Formatted_Double_StringInfoData::vftable)(int);
// 798024: using guessed type int (__thiscall *Formatted_Double_StringInfoData::vftable)(void *, char);

//----- (0042EA30) --------------------------------------------------------  // acclient.c:107886
Formatted_Double_StringInfoData *__thiscall Formatted_Double_StringInfoData::vector_deleting_destructor(Formatted_Double_StringInfoData *this, unsigned int a2)
{
  Formatted_Double_StringInfoData *v2; // esi@1

  v2 = this;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_Double_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 798020: using guessed type int (__stdcall *Formatted_Double_StringInfoData::vftable)(int);

//----- (0042EA60) --------------------------------------------------------  // acclient.c:107903
BOOL __thiscall Formatted_Double_StringInfoData::operator==(Formatted_Double_StringInfoData *this, Formatted_Double_StringInfoData *i_rcRhs)
{
  return this->m_eType == i_rcRhs->m_eType
      && this->m_eVarID == i_rcRhs->m_eVarID
      && this->m_fVal == i_rcRhs->m_fVal
      && this->m_iPrecision == i_rcRhs->m_iPrecision
      && this->m_bGrouping == i_rcRhs->m_bGrouping
      && this->m_iBase == i_rcRhs->m_iBase;
}

//----- (0042EAB0) --------------------------------------------------------  // acclient.c:107914
void __thiscall Formatted_LInt_StringInfoData::Formatted_LInt_StringInfoData(Formatted_LInt_StringInfoData *this, unsigned int i_eVarID)
{
  this->m_eVarID = i_eVarID;
  this->m_iVal = 0i64;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->m_bGrouping = 1;
  this->m_iBase = -1;
  this->vfptr = (StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
  this->m_eType = 5;
}
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 79803C: using guessed type int (__thiscall *Formatted_LInt_StringInfoData::vftable)(void *, char);
// 798054: using guessed type int (__stdcall *Formatted_LInt_StringInfoData::vftable)(int);

//----- (0042EAF0) --------------------------------------------------------  // acclient.c:107930
Formatted_ULInt_StringInfoData *__thiscall Formatted_LInt_StringInfoData::vector_deleting_destructor(Formatted_ULInt_StringInfoData *this, unsigned int a2)
{
  Formatted_ULInt_StringInfoData *v2; // esi@1

  v2 = this;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 798054: using guessed type int (__stdcall *Formatted_LInt_StringInfoData::vftable)(int);

//----- (0042EB20) --------------------------------------------------------  // acclient.c:107947
BOOL __thiscall Formatted_ULInt_StringInfoData::operator==(Formatted_ULInt_StringInfoData *this, Formatted_ULInt_StringInfoData *i_rcRhs)
{
  return this->m_eType == i_rcRhs->m_eType
      && this->m_eVarID == i_rcRhs->m_eVarID
      && LODWORD(this->m_iVal) == LODWORD(i_rcRhs->m_iVal)
      && HIDWORD(this->m_iVal) == HIDWORD(i_rcRhs->m_iVal)
      && this->m_bGrouping == i_rcRhs->m_bGrouping
      && this->m_iBase == i_rcRhs->m_iBase;
}

//----- (0042EB70) --------------------------------------------------------  // acclient.c:107958
void __cdecl StringInfoData::Create(unsigned __int16 i_eType)
{
  StringInfo_StringInfoData *v1; // eax@2
  Double_StringInfoData *v2; // eax@4
  Formatted_Double_StringInfoData *v3; // eax@6
  LInt_StringInfoData *v4; // eax@8
  Formatted_LInt_StringInfoData *v5; // eax@10

  switch ( i_eType )
  {
    case 1u:
      v1 = (StringInfo_StringInfoData *)operator new(0x9Cu);
      if ( v1 )
        StringInfo_StringInfoData::StringInfo_StringInfoData(v1, 0);
      break;
    case 2u:
      v2 = (Double_StringInfoData *)operator new(0x20u);
      if ( v2 )
        Double_StringInfoData::Double_StringInfoData(v2, 0);
      break;
    case 3u:
      v3 = (Formatted_Double_StringInfoData *)operator new(0x28u);
      if ( v3 )
        Formatted_Double_StringInfoData::Formatted_Double_StringInfoData(v3, 0);
      break;
    case 4u:
    case 6u:
      v4 = (LInt_StringInfoData *)operator new(0x18u);
      if ( v4 )
        LInt_StringInfoData::LInt_StringInfoData(v4, 0);
      break;
    case 5u:
    case 7u:
      v5 = (Formatted_LInt_StringInfoData *)operator new(0x20u);
      if ( v5 )
        Formatted_LInt_StringInfoData::Formatted_LInt_StringInfoData(v5, 0);
      break;
    default:
      return;
  }
}

//----- (0042EC30) --------------------------------------------------------  // acclient.c:108001
void __thiscall StringInfo_StringInfoData::StringInfo_StringInfoData(StringInfo_StringInfoData *this, StringInfo_StringInfoData *__that)
{
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  this->m_eVarID = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&StringInfo_StringInfoData::vftable;
  StringInfo::StringInfo(&this->m_cVal, &__that->m_cVal);
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FC0: using guessed type int (__thiscall *StringInfo_StringInfoData::vftable)(void *, char);

//----- (0042EC70) --------------------------------------------------------  // acclient.c:108013
void __thiscall Double_StringInfoData::Double_StringInfoData(Double_StringInfoData *this, Double_StringInfoData *__that)
{
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  this->m_eVarID = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&Double_StringInfoData::vftable;
  this->m_fVal = __that->m_fVal;
  this->m_iPrecision = __that->m_iPrecision;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FD8: using guessed type int (__thiscall *Double_StringInfoData::vftable)(void *, char);

//----- (0042ECB0) --------------------------------------------------------  // acclient.c:108026
void __thiscall Formatted_Double_StringInfoData::Formatted_Double_StringInfoData(Formatted_Double_StringInfoData *this, Formatted_Double_StringInfoData *__that)
{
  unsigned int v2; // edx@1

  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  v2 = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&Double_StringInfoData::vftable;
  this->m_eVarID = v2;
  this->m_fVal = __that->m_fVal;
  this->m_iPrecision = __that->m_iPrecision;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->m_bGrouping = __that->m_bGrouping;
  this->m_iBase = __that->m_iBase;
  this->vfptr = (StringInfoDataVtbl *)&Formatted_Double_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_Double_StringInfoData::vftable;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 797FD8: using guessed type int (__thiscall *Double_StringInfoData::vftable)(void *, char);
// 798020: using guessed type int (__stdcall *Formatted_Double_StringInfoData::vftable)(int);
// 798024: using guessed type int (__thiscall *Formatted_Double_StringInfoData::vftable)(void *, char);

//----- (0042ED10) --------------------------------------------------------  // acclient.c:108050
void __thiscall LInt_StringInfoData::LInt_StringInfoData(LInt_StringInfoData *this, LInt_StringInfoData *__that)
{
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  this->m_eVarID = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&LInt_StringInfoData::vftable;
  this->m_iVal = __that->m_iVal;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FF0: using guessed type int (__thiscall *LInt_StringInfoData::vftable)(void *, char);

//----- (0042ED40) --------------------------------------------------------  // acclient.c:108062
void __thiscall Formatted_LInt_StringInfoData::Formatted_LInt_StringInfoData(Formatted_LInt_StringInfoData *this, Formatted_LInt_StringInfoData *__that)
{
  unsigned int v2; // edx@1

  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  v2 = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&LInt_StringInfoData::vftable;
  this->m_eVarID = v2;
  this->m_iVal = __that->m_iVal;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->m_bGrouping = __that->m_bGrouping;
  this->m_iBase = __that->m_iBase;
  this->vfptr = (StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 797FF0: using guessed type int (__thiscall *LInt_StringInfoData::vftable)(void *, char);
// 79803C: using guessed type int (__thiscall *Formatted_LInt_StringInfoData::vftable)(void *, char);
// 798054: using guessed type int (__stdcall *Formatted_LInt_StringInfoData::vftable)(int);

//----- (0042EDA0) --------------------------------------------------------  // acclient.c:108085
void __thiscall ULInt_StringInfoData::ULInt_StringInfoData(ULInt_StringInfoData *this, ULInt_StringInfoData *__that)
{
  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  this->m_eVarID = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&ULInt_StringInfoData::vftable;
  this->m_iVal = __that->m_iVal;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 798008: using guessed type int (__thiscall *ULInt_StringInfoData::vftable)(void *, char);

//----- (0042EDD0) --------------------------------------------------------  // acclient.c:108097
void __thiscall Formatted_ULInt_StringInfoData::Formatted_ULInt_StringInfoData(Formatted_ULInt_StringInfoData *this, Formatted_ULInt_StringInfoData *__that)
{
  unsigned int v2; // edx@1

  this->vfptr = (StringInfoDataVtbl *)&StringInfoData::vftable;
  this->m_eType = __that->m_eType;
  v2 = __that->m_eVarID;
  this->vfptr = (StringInfoDataVtbl *)&ULInt_StringInfoData::vftable;
  this->m_eVarID = v2;
  this->m_iVal = __that->m_iVal;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_StringInfoData::vftable;
  this->m_bGrouping = __that->m_bGrouping;
  this->m_iBase = __that->m_iBase;
  this->vfptr = (StringInfoDataVtbl *)&Formatted_ULInt_StringInfoData::vftable;
  this->vfptr = (Formatted_StringInfoDataVtbl *)&Formatted_LInt_StringInfoData::vftable;
}
// 797FA4: using guessed type int (__thiscall *StringInfoData::vftable)(void *, char);
// 797FBC: using guessed type void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *);
// 798008: using guessed type int (__thiscall *ULInt_StringInfoData::vftable)(void *, char);
// 798054: using guessed type int (__stdcall *Formatted_LInt_StringInfoData::vftable)(int);
// 798058: using guessed type int (__thiscall *Formatted_ULInt_StringInfoData::vftable)(void *, char);

//----- (0042EE30) --------------------------------------------------------  // acclient.c:108120
bool __cdecl StringInfoData::Compare(StringInfoData *i_pcLhs, StringInfoData *i_pcRhs)
{
  bool result; // al@1
  unsigned __int16 v3; // si@3

  result = 0;
  if ( i_pcLhs )
  {
    if ( i_pcRhs )
    {
      v3 = i_pcLhs->m_eType;
      if ( v3 == i_pcRhs->m_eType )
      {
        switch ( v3 )
        {
          case 1u:
            result = StringInfo_StringInfoData::operator==(
                       (StringInfo_StringInfoData *)i_pcRhs,
                       (StringInfo_StringInfoData *)i_pcLhs);
            break;
          case 2u:
            result = Double_StringInfoData::operator==(
                       (Double_StringInfoData *)i_pcRhs,
                       (Double_StringInfoData *)i_pcLhs);
            break;
          case 3u:
            result = Formatted_Double_StringInfoData::operator==(
                       (Formatted_Double_StringInfoData *)i_pcRhs,
                       (Formatted_Double_StringInfoData *)i_pcLhs);
            break;
          case 4u:
            result = LInt_StringInfoData::operator==((ULInt_StringInfoData *)i_pcRhs, (ULInt_StringInfoData *)i_pcLhs);
            break;
          case 5u:
            result = Formatted_ULInt_StringInfoData::operator==(
                       (Formatted_ULInt_StringInfoData *)i_pcRhs,
                       (Formatted_ULInt_StringInfoData *)i_pcLhs);
            break;
          case 6u:
            result = LInt_StringInfoData::operator==((ULInt_StringInfoData *)i_pcRhs, (ULInt_StringInfoData *)i_pcLhs);
            break;
          case 7u:
            result = Formatted_ULInt_StringInfoData::operator==(
                       (Formatted_ULInt_StringInfoData *)i_pcRhs,
                       (Formatted_ULInt_StringInfoData *)i_pcLhs);
            break;
          default:
            return result;
        }
      }
    }
  }
  return result;
}

//----- (0042EEC0) --------------------------------------------------------  // acclient.c:108176
void __thiscall StringInfoData::Serialize(StringInfoData *this, Archive *_rArchive)
{
  StringInfoData *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  Archive::CheckAlignment(_rArchive, 2u);
  v3 = Archive::GetBytes(_rArchive, 2u);
  if ( v3 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_WORD *)v3 = v2->m_eType;
    else
      v2->m_eType = *(_WORD *)v3;
  }
  Archive::CheckAlignment(_rArchive, 4u);
  v4 = Archive::GetBytes(_rArchive, 4u);
  if ( v4 )
  {
    if ( _rArchive->m_flags & 1 )
      *(_DWORD *)v4 = v2->m_eVarID;
    else
      v2->m_eVarID = *(_DWORD *)v4;
  }
}

//----- (0042EF30) --------------------------------------------------------  // acclient.c:108204
void __thiscall StringInfo_StringInfoData::Serialize(StringInfo_StringInfoData *this, Archive *io_rcArchive)
{
  StringInfo_StringInfoData *v2; // esi@1

  v2 = this;
  StringInfoData::Serialize((StringInfoData *)&this->vfptr, io_rcArchive);
  StringInfo::Serialize(&v2->m_cVal, io_rcArchive);
}

//----- (0042EF50) --------------------------------------------------------  // acclient.c:108214
void __thiscall StringInfo_StringInfoData::GetSubPrivateIDs(StringInfo_StringInfoData *this, QualifiedDataIDArray *id_array, IDClass<_tagDataID,32,0> fromTable)
{
  StringInfo::GetSubPrivateIDs(&this->m_cVal, id_array, fromTable);
}

//----- (0042EF60) --------------------------------------------------------  // acclient.c:108220
void __thiscall Double_StringInfoData::Serialize(Double_StringInfoData *this, Archive *io_rcArchive)
{
  Double_StringInfoData *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  StringInfoData::Serialize((StringInfoData *)&this->vfptr, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 8u);
  v3 = Archive::GetBytes(io_rcArchive, 8u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
    {
      *(_DWORD *)v3 = LODWORD(v2->m_fVal);
      *(_DWORD *)(v3 + 4) = HIDWORD(v2->m_fVal);
    }
    else
    {
      LODWORD(v2->m_fVal) = *(_DWORD *)v3;
      HIDWORD(v2->m_fVal) = *(_DWORD *)(v3 + 4);
    }
  }
  Archive::CheckAlignment(io_rcArchive, 2u);
  v4 = Archive::GetBytes(io_rcArchive, 2u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_WORD *)v4 = v2->m_iPrecision;
    else
      v2->m_iPrecision = *(_WORD *)v4;
  }
}

//----- (0042EFE0) --------------------------------------------------------  // acclient.c:108255
void __thiscall ULInt_StringInfoData::Serialize(ULInt_StringInfoData *this, Archive *io_rcArchive)
{
  ULInt_StringInfoData *v2; // esi@1
  unsigned int v3; // eax@1

  v2 = this;
  StringInfoData::Serialize((StringInfoData *)&this->vfptr, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 8u);
  v3 = Archive::GetBytes(io_rcArchive, 8u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
    {
      *(_DWORD *)v3 = LODWORD(v2->m_iVal);
      *(_DWORD *)(v3 + 4) = HIDWORD(v2->m_iVal);
    }
    else
    {
      LODWORD(v2->m_iVal) = *(_DWORD *)v3;
      HIDWORD(v2->m_iVal) = *(_DWORD *)(v3 + 4);
    }
  }
}

//----- (0042F030) --------------------------------------------------------  // acclient.c:108280
void __thiscall Formatted_StringInfoData::Serialize(Formatted_StringInfoData *this, Archive *io_rcArchive)
{
  Formatted_StringInfoData *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Serializer::SerializeObject(&this->m_bGrouping, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 2u);
  v3 = Archive::GetBytes(io_rcArchive, 2u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_WORD *)v3 = v2->m_iBase;
    else
      v2->m_iBase = *(_WORD *)v3;
  }
}

//----- (0042F080) --------------------------------------------------------  // acclient.c:108299
void __thiscall Formatted_Double_StringInfoData::Serialize(Formatted_Double_StringInfoData *this, Archive *io_rcArchive)
{
  Formatted_Double_StringInfoData *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Double_StringInfoData::Serialize((Double_StringInfoData *)&this->vfptr, io_rcArchive);
  Serializer::SerializeObject(&v2->m_bGrouping, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 2u);
  v3 = Archive::GetBytes(io_rcArchive, 2u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_WORD *)v3 = v2->m_iBase;
    else
      v2->m_iBase = *(_WORD *)v3;
  }
}

//----- (0042F0D0) --------------------------------------------------------  // acclient.c:108319
void __thiscall Formatted_LInt_StringInfoData::Serialize(Formatted_ULInt_StringInfoData *this, Archive *io_rcArchive)
{
  Formatted_ULInt_StringInfoData *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  StringInfoData::Serialize((StringInfoData *)&this->vfptr, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 8u);
  v3 = Archive::GetBytes(io_rcArchive, 8u);
  if ( v3 )
  {
    if ( io_rcArchive->m_flags & 1 )
    {
      *(_DWORD *)v3 = LODWORD(v2->m_iVal);
      *(_DWORD *)(v3 + 4) = HIDWORD(v2->m_iVal);
    }
    else
    {
      LODWORD(v2->m_iVal) = *(_DWORD *)v3;
      HIDWORD(v2->m_iVal) = *(_DWORD *)(v3 + 4);
    }
  }
  Serializer::SerializeObject(&v2->m_bGrouping, io_rcArchive);
  Archive::CheckAlignment(io_rcArchive, 2u);
  v4 = Archive::GetBytes(io_rcArchive, 2u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_WORD *)v4 = v2->m_iBase;
    else
      v2->m_iBase = *(_WORD *)v4;
  }
}

//----- (0042F160) --------------------------------------------------------  // acclient.c:108355
void __thiscall Formatted_Double_StringInfoData::Serialize(Formatted_Double_StringInfoData *this, Archive *a2)
{
  Formatted_Double_StringInfoData::Serialize((Formatted_Double_StringInfoData *)((char *)this - 32), a2);
}

//----- (0042F170) --------------------------------------------------------  // acclient.c:108361
void __thiscall Formatted_LInt_StringInfoData::Serialize(Formatted_ULInt_StringInfoData *this, Archive *a2)
{
  Formatted_LInt_StringInfoData::Serialize((Formatted_ULInt_StringInfoData *)((char *)this - 24), a2);
}

//----- (0042F180) --------------------------------------------------------  // acclient.c:108367
void __cdecl StringInfoData::Copy(StringInfoData *i_pcRhs)
{
  StringInfo_StringInfoData *v1; // eax@3
  Double_StringInfoData *v2; // eax@5
  Formatted_Double_StringInfoData *v3; // eax@7
  LInt_StringInfoData *v4; // eax@9
  Formatted_LInt_StringInfoData *v5; // eax@11
  ULInt_StringInfoData *v6; // eax@13
  Formatted_ULInt_StringInfoData *v7; // eax@15

  if ( i_pcRhs )
  {
    switch ( i_pcRhs->m_eType )
    {
      case 1u:
        v1 = (StringInfo_StringInfoData *)operator new(0x9Cu);
        if ( v1 )
          StringInfo_StringInfoData::StringInfo_StringInfoData(v1, (StringInfo_StringInfoData *)i_pcRhs);
        break;
      case 2u:
        v2 = (Double_StringInfoData *)operator new(0x20u);
        if ( v2 )
          Double_StringInfoData::Double_StringInfoData(v2, (Double_StringInfoData *)i_pcRhs);
        break;
      case 3u:
        v3 = (Formatted_Double_StringInfoData *)operator new(0x28u);
        if ( v3 )
          Formatted_Double_StringInfoData::Formatted_Double_StringInfoData(
            v3,
            (Formatted_Double_StringInfoData *)i_pcRhs);
        break;
      case 4u:
        v4 = (LInt_StringInfoData *)operator new(0x18u);
        if ( v4 )
          LInt_StringInfoData::LInt_StringInfoData(v4, (LInt_StringInfoData *)i_pcRhs);
        break;
      case 5u:
        v5 = (Formatted_LInt_StringInfoData *)operator new(0x20u);
        if ( v5 )
          Formatted_LInt_StringInfoData::Formatted_LInt_StringInfoData(v5, (Formatted_LInt_StringInfoData *)i_pcRhs);
        break;
      case 6u:
        v6 = (ULInt_StringInfoData *)operator new(0x18u);
        if ( v6 )
          ULInt_StringInfoData::ULInt_StringInfoData(v6, (ULInt_StringInfoData *)i_pcRhs);
        break;
      case 7u:
        v7 = (Formatted_ULInt_StringInfoData *)operator new(0x20u);
        if ( v7 )
          Formatted_ULInt_StringInfoData::Formatted_ULInt_StringInfoData(v7, (Formatted_ULInt_StringInfoData *)i_pcRhs);
        break;
      default:
        return;
    }
  }
}

//----- (0042F280) --------------------------------------------------------  // acclient.c:108425
PStringBase<unsigned short> *__cdecl StringInfoDataHelper::NumToString(PStringBase<unsigned short> *result, long double i_fVal, int i_iPrecision, bool i_bGrouping, int i_iBase)
{
  int v5; // edi@1
  signed int v6; // esi@1
  CLanguageInfoInterface *v7; // ecx@3
  int v8; // ecx@8
  long double v9; // st7@9
  unsigned __int64 v10; // rax@10
  unsigned __int16 v11; // bp@10
  __int16 v12; // cx@10
  bool v13; // zf@15
  PSRefBufferCharData<unsigned short> *v14; // ecx@17
  int i; // eax@17
  unsigned __int16 v16; // bp@18
  int v17; // edx@18
  PSRefBufferCharData<unsigned short> *v18; // ecx@21
  int j; // eax@21
  unsigned __int16 v20; // bp@22
  int v21; // edx@22
  PSRefBufferCharData<unsigned short> *v22; // eax@24
  PStringBase<unsigned short> *v23; // ebp@24
  LONG (__stdcall *v24)(volatile LONG *); // edi@24
  char *v25; // esi@24
  PSRefBufferCharData<unsigned short> *v26; // eax@30
  char *v27; // esi@30
  LONG v28; // eax@24
  char *v29; // esi@37
  char *v30; // esi@40
  char *v31; // esi@43
  PSRefBufferCharData<unsigned short> *v33; // eax@47
  PSRefBufferCharData<unsigned short> *v34; // eax@48
  unsigned __int16 *v35; // [sp-4h] [bp-F8h]@27
  PStringBase<unsigned short> retval; // [sp+10h] [bp-E4h]@1
  bool bLeadingZero; // [sp+17h] [bp-DDh]@8
  int v38; // [sp+18h] [bp-DCh]@8
  PStringBase<unsigned short> numerals; // [sp+1Ch] [bp-D8h]@8
  int base; // [sp+20h] [bp-D4h]@4
  PStringBase<unsigned short> groupingSeperator; // [sp+24h] [bp-D0h]@9
  PStringBase<unsigned short> decimalSeperator; // [sp+28h] [bp-CCh]@9
  int digitIndex; // [sp+2Ch] [bp-C8h]@1
  unsigned __int16 numDecimalDigits; // [sp+30h] [bp-C4h]@8
  PStringBase<unsigned short> negativeNumberFormat; // [sp+34h] [bp-C0h]@25
  unsigned __int16 groupingSize; // [sp+38h] [bp-BCh]@9
  long double curPlaceVal; // [sp+3Ch] [bp-B8h]@9
  long double remainingVal; // [sp+44h] [bp-B0h]@1
  unsigned __int64 v49; // [sp+4Ch] [bp-A8h]@9
  long double absVal; // [sp+54h] [bp-A0h]@1
  __int64 v51; // [sp+5Ch] [bp-98h]@10
  long double v52; // [sp+64h] [bp-90h]@9
  unsigned __int64 v53; // [sp+6Ch] [bp-88h]@10
  unsigned __int16 buffer[64]; // [sp+74h] [bp-80h]@1

  retval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  absVal = fabs(i_fVal);
  remainingVal = absVal;
  v5 = -i_iPrecision;
  buffer[63] = 0;
  v6 = 62;
  digitIndex = 0;
  if ( absVal < 1.0 )
    absVal = 1.0;
  v7 = CLanguageInfoInterface::m_instance;
  if ( !CLanguageInfoInterface::m_instance )
    goto LABEL_54;
  base = i_iBase;
  if ( (_WORD)i_iBase == -1 )
  {
    CLanguageInfoInterface::GetBase(CLanguageInfoInterface::m_instance, (unsigned __int16 *)&base);
    v7 = CLanguageInfoInterface::m_instance;
  }
  if ( (unsigned __int16)base <= 1u || (unsigned __int16)i_iPrecision > 0x14u )
  {
LABEL_54:
    v34 = retval.m_charbuffer;
    result->m_charbuffer = retval.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v34[-1].m_data[8]);
    if ( !InterlockedDecrement((volatile LONG *)&retval.m_charbuffer[-1].m_data[8])
      && retval.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(unsigned __int16 *, signed int))&retval.m_charbuffer[-1].m_data[6])(
        &retval.m_charbuffer[-1].m_data[6],
        1);
    return result;
  }
  CLanguageInfoInterface::GetLeadingZero(v7, &bLeadingZero);
  CLanguageInfoInterface::GetNumDecDigits(CLanguageInfoInterface::m_instance, &numDecimalDigits);
  numerals.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  CLanguageInfoInterface::GetNumerals(CLanguageInfoInterface::m_instance, &numerals);
  v8 = *(_DWORD *)&numerals.m_charbuffer[-1].m_data[14] - 1;
  v38 = (unsigned __int16)base;
  if ( v8 < (unsigned int)(unsigned __int16)base )
  {
    v33 = retval.m_charbuffer;
    result->m_charbuffer = retval.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v33[-1].m_data[8]);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&numerals);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&retval);
    return result;
  }
  v9 = (double)v38;
  v38 = (signed __int16)v5;
  curPlaceVal = pow(v9, (double)(signed __int16)v5);
  CLanguageInfoInterface::GetGroupingSize(CLanguageInfoInterface::m_instance, &groupingSize);
  groupingSeperator.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  CLanguageInfoInterface::GetGroupingSeperator(CLanguageInfoInterface::m_instance, &groupingSeperator);
  decimalSeperator.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  CLanguageInfoInterface::GetDecimalSeperator(CLanguageInfoInterface::m_instance, &decimalSeperator);
  v38 = (unsigned __int16)base;
  v49 = (unsigned __int16)base;
  v52 = (double)(unsigned __int16)base;
  while ( 1 )
  {
    v38 = -(signed __int16)v5;
    v10 = (unsigned __int64)(pow(v52, (double)v38) * remainingVal + 0.5) % v49;
    v11 = numerals.m_charbuffer->m_data[v10];
    LODWORD(v51) = v10;
    buffer[(signed __int16)v6] = v11;
    HIDWORD(v51) = HIDWORD(v10) & 0x7FFFFFFF;
    v53 = v10 & 0x8000000000000000ui64;
    --v6;
    v12 = digitIndex + 1;
    LOWORD(v5) = v5 + 1;
    ++digitIndex;
    remainingVal = remainingVal - (double)v10 * curPlaceVal;
    curPlaceVal = v52 * curPlaceVal;
    if ( curPlaceVal > absVal && (!bLeadingZero || v12 >= (signed int)numDecimalDigits) )
      break;
    if ( !(_WORD)v6 )
    {
      v22 = retval.m_charbuffer;
      v23 = result;
      result->m_charbuffer = retval.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v22[-1].m_data[8]);
      v24 = InterlockedDecrement;
      v25 = (char *)&decimalSeperator.m_charbuffer[-1].m_data[6];
      v28 = InterlockedDecrement((volatile LONG *)&decimalSeperator.m_charbuffer[-1].m_data[8]);
      goto LABEL_34;
    }
    if ( i_bGrouping )
    {
      v13 = (_WORD)v5 == 0;
      if ( (signed __int16)v5 <= 0 )
        goto LABEL_20;
      if ( !((signed __int16)v5 % (signed int)groupingSize) )
      {
        v14 = groupingSeperator.m_charbuffer;
        for ( i = *(_DWORD *)&groupingSeperator.m_charbuffer[-1].m_data[14] - 2; i >= 0; buffer[v17] = v16 )
        {
          v16 = v14->m_data[i];
          v17 = (signed __int16)v6--;
          --i;
        }
      }
    }
    v13 = (_WORD)v5 == 0;
LABEL_20:
    if ( v13 )
    {
      v18 = decimalSeperator.m_charbuffer;
      for ( j = *(_DWORD *)&decimalSeperator.m_charbuffer[-1].m_data[14] - 2; j >= 0; buffer[v21] = v20 )
      {
        v20 = v18->m_data[j];
        v21 = (signed __int16)v6--;
        --j;
      }
    }
  }
  negativeNumberFormat.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  CLanguageInfoInterface::GetNegNumFormat(CLanguageInfoInterface::m_instance, &negativeNumberFormat);
  if ( i_fVal >= 0.0 )
  {
    v35 = &buffer[(signed __int16)v6 + 1];
    if ( (_WORD)base == 16 )
      PStringBase<unsigned short>::sprintf(&retval, L"0x%s", v35);
    else
      PStringBase<unsigned short>::sprintf(&retval, L"%s", v35);
  }
  else
  {
    PStringBase<unsigned short>::sprintf(
      &retval,
      negativeNumberFormat.m_charbuffer->m_data,
      &buffer[(signed __int16)v6 + 1]);
  }
  v26 = retval.m_charbuffer;
  v23 = result;
  result->m_charbuffer = retval.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v26[-1].m_data[8]);
  v24 = InterlockedDecrement;
  v27 = (char *)&negativeNumberFormat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&negativeNumberFormat.m_charbuffer[-1].m_data[8]) && v27 )
    (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
  v25 = (char *)&decimalSeperator.m_charbuffer[-1].m_data[6];
  v28 = InterlockedDecrement((volatile LONG *)&decimalSeperator.m_charbuffer[-1].m_data[8]);
LABEL_34:
  if ( !v28 && v25 )
    (**(void (__thiscall ***)(char *, signed int))v25)(v25, 1);
  v29 = (char *)&groupingSeperator.m_charbuffer[-1].m_data[6];
  if ( !v24((volatile LONG *)&groupingSeperator.m_charbuffer[-1].m_data[8]) && v29 )
    (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
  v30 = (char *)&numerals.m_charbuffer[-1].m_data[6];
  if ( !v24((volatile LONG *)&numerals.m_charbuffer[-1].m_data[8]) && v30 )
    (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
  v31 = (char *)&retval.m_charbuffer[-1].m_data[6];
  if ( !v24((volatile LONG *)&retval.m_charbuffer[-1].m_data[8]) && v31 )
    (**(void (__thiscall ***)(char *, signed int))v31)(v31, 1);
  return v23;
}
// 798078: using guessed type wchar_t a0xS[5];

//----- (0042F700) --------------------------------------------------------  // acclient.c:108640
PStringBase<unsigned short> *__thiscall StringInfo_StringInfoData::ToString(StringInfo_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfo_StringInfoData *v2; // esi@1
  char *v3; // esi@2
  PSRefBufferCharData<unsigned short> *v4; // eax@5
  char *v5; // esi@5
  PStringBase<unsigned short> sRetval; // [sp+10h] [bp-8h]@1
  PStringBase<char> sError; // [sp+14h] [bp-4h]@2

  sRetval.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( StringInfo::InqStringInternal(&v2->m_cVal, &sRetval, 1) )
  {
    PStringBase<char>::PStringBase<char>(
      &sError,
      0,
      "Error: While rendering a StringInfo, could not render one of the inner variables: a StringInfo with table ID 0x%08X and token 0x%08x\n",
      v2->m_cVal.m_tableID.id,
      v2->m_cVal.m_stringID);
    v3 = &sError.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&sError.m_charbuffer[-1]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
    }
  }
  v4 = sRetval.m_charbuffer;
  result->m_charbuffer = sRetval.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v4[-1].m_data[8]);
  v5 = (char *)&sRetval.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&sRetval.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return result;
}

//----- (0042F7B0) --------------------------------------------------------  // acclient.c:108677
PStringBase<unsigned short> *__thiscall Double_StringInfoData::ToString(Double_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, this->m_fVal, this->m_iPrecision, 1, 0xFFFF);
  return result;
}

//----- (0042F7E0) --------------------------------------------------------  // acclient.c:108684
PStringBase<unsigned short> *__thiscall LInt_StringInfoData::ToString(LInt_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, (double)this->m_iVal, 0, 1, 0xFFFF);
  return result;
}

//----- (0042F810) --------------------------------------------------------  // acclient.c:108691
PStringBase<unsigned short> *__thiscall ULInt_StringInfoData::ToString(ULInt_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, (double)this->m_iVal, 0, 1, 0xFFFF);
  return result;
}

//----- (0042F870) --------------------------------------------------------  // acclient.c:108698
PStringBase<unsigned short> *__thiscall Formatted_Double_StringInfoData::ToString(Formatted_Double_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, this->m_fVal, this->m_iPrecision, this->m_bGrouping, this->m_iBase);
  return result;
}

//----- (0042F8A0) --------------------------------------------------------  // acclient.c:108705
PStringBase<unsigned short> *__thiscall Formatted_LInt_StringInfoData::ToString(Formatted_LInt_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, (double)this->m_iVal, 0, this->m_bGrouping, this->m_iBase);
  return result;
}

//----- (0042F8D0) --------------------------------------------------------  // acclient.c:108712
PStringBase<unsigned short> *__thiscall Formatted_ULInt_StringInfoData::ToString(Formatted_ULInt_StringInfoData *this, PStringBase<unsigned short> *result)
{
  StringInfoDataHelper::NumToString(result, (double)this->m_iVal, 0, this->m_bGrouping, this->m_iBase);
  return result;
}

//----- (006C5820) --------------------------------------------------------  // acclient.c:733827
int _E1_24()
{
  return atexit(_E2_24);
}

