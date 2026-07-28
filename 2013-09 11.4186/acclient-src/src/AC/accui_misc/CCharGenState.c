/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCharGenState
   Object     : AC\accui_misc\CCharGenState.obj
   Functions  : 15
   Addresses  : 005638C0 - 00708510 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005638C0) --------------------------------------------------------  // acclient.c:400911
void __thiscall ClientCharGenState::ClientCharGenState(ClientCharGenState *this)
{
  ClientCharGenState *v1; // esi@1
  Palette *v2; // eax@1

  v1 = this;
  CharGenState::CharGenState((CharGenState *)&this->vfptr);
  v1->vfptr = (CharGenStateVtbl *)&ClientCharGenState::vftable;
  v1->grayFacePal = 0;
  v1->trueFacePal = 0;
  v1->trueFacePalChangeNum = 0;
  v1->grayFacePal = (Palette *)DBObj::GetByEnum(1, 268435464, 0xAu);
  Palette::makeModifiedPalette();
  v1->trueFacePal = v2;
}
// 7CD640: using guessed type void (__thiscall *ClientCharGenState::vftable)(ClientCharGenState *__hidden this);

//----- (00563910) --------------------------------------------------------  // acclient.c:400929
int __stdcall CharGenState::GetRandomInt(int range)
{
  return RandInt(range);
}

//----- (00563920) --------------------------------------------------------  // acclient.c:400935
int __stdcall CharGenState::GetRandomInt(int range, int exclude)
{
  return RandInt(range, exclude);
}

//----- (00563940) --------------------------------------------------------  // acclient.c:400941
double CharGenState::GetRandomReal()
{
  return (double)_rand() * 0.00003051850947599719;
}

//----- (00563960) --------------------------------------------------------  // acclient.c:400947
void __thiscall ClientCharGenState::~ClientCharGenState(ClientCharGenState *this)
{
  ClientCharGenState *v1; // esi@1
  Palette *v2; // ecx@1

  v1 = this;
  v2 = this->grayFacePal;
  v1->vfptr = (CharGenStateVtbl *)&ClientCharGenState::vftable;
  ((void (*)(void))v2->vfptr->Release)();
  Palette::releasePalette(v1->trueFacePal);
  CharGenState::~CharGenState((CharGenState *)&v1->vfptr);
}
// 7CD640: using guessed type void (__thiscall *ClientCharGenState::vftable)(ClientCharGenState *__hidden this);

//----- (00563990) --------------------------------------------------------  // acclient.c:400962
unsigned int __stdcall ClientCharGenState::GetColorFromPal(IDClass<_tagDataID,32,0> _palID, int _colorNum)
{
  QualifiedDataID *v3; // eax@1
  int v4; // esi@1
  unsigned int v5; // edi@2
  unsigned int result; // eax@2
  ErrorStream *v7; // eax@3
  ErrorStream *v8; // eax@3
  ErrorStream *v9; // eax@3
  QualifiedDataID v10; // [sp+Ch] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v10, _palID, 0xAu);
  v4 = DBObj::Get(v3);
  if ( v4 )
  {
    v5 = Palette::get_color32((Palette *)v4, _colorNum);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 20))(v4);
    result = v5;
  }
  else
  {
    v7 = ErrorStream::operator<<(&perr, "palette ");
    v8 = ErrorStream::operator<<(v7, _palID);
    v9 = ErrorStream::operator<<(v8, " not loaded correctly from database.");
    ErrorStream::operator<<(v9, endp);
    result = 0;
  }
  return result;
}

//----- (00563A20) --------------------------------------------------------  // acclient.c:400993
void __thiscall ClientCharGenState::UpdateTrueFacePal(ClientCharGenState *this)
{
  ClientCharGenState *v1; // esi@1
  unsigned int v2; // eax@7
  signed int v3; // ebx@7
  unsigned int v4; // ST0C_4@9
  HeritageGroup_CG *v5; // eax@9
  QualifiedDataID *v6; // eax@9
  int v7; // edi@9
  unsigned int v8; // edx@10
  IDClass<_tagDataID,32,0> v9; // eax@10
  signed int v10; // eax@13
  int v11; // edi@15
  unsigned int v12; // edx@16
  IDClass<_tagDataID,32,0> v13; // eax@16
  signed int v14; // eax@19
  IDClass<_tagDataID,32,0> v15; // eax@21
  IDClass<_tagDataID,32,0> v16; // [sp+8h] [bp-1ACh]@10
  unsigned int v17; // [sp+Ch] [bp-1A8h]@10
  QualifiedDataID v18; // [sp+10h] [bp-1A4h]@9
  Sex_CG curSX; // [sp+18h] [bp-19Ch]@9
  HeritageGroup_CG result; // [sp+F4h] [bp-C0h]@9

  v1 = this;
  if ( !(dword_87028C & 1) )
  {
    dword_87028C |= 1u;
    skinPalID.id = stru_8702A0.id;
    atexit(nullsub_1322);
  }
  if ( !(dword_87028C & 2) )
  {
    dword_87028C |= 2u;
    eyesPalID.id = stru_8702A0.id;
    atexit(_E111_71);
  }
  if ( !(dword_87028C & 4) )
  {
    dword_87028C |= 4u;
    hairPalID.id = stru_8702A0.id;
    atexit(nullsub_1320);
  }
  v2 = v1->mHeritageGroup;
  v3 = 0;
  if ( v2 && v1->mGender )
  {
    v4 = v1->mGender;
    v5 = ACCharGenData::GetHG(v1->charGenData, &result, v2);
    HeritageGroup_CG::GetSX(v5, &curSX, v4);
    HeritageGroup_CG::~HeritageGroup_CG(&result);
    QualifiedDataID::QualifiedDataID(&v18, curSX.skinPalSet, 0x18u);
    v7 = DBObj::Get(v6);
    if ( v7 )
    {
      v8 = LODWORD(v1->skinShade);
      v17 = HIDWORD(v1->skinShade);
      v16.id = v8;
      v9.id = PalSet::GetPaletteID((PalSet *)v7, &v16, COERCE_LONG_DOUBLE(__PAIR__(v17, v8)))->id;
      if ( v9.id != skinPalID.id )
      {
        skinPalID.id = v9.id;
        Palette::Modify(v1->trueFacePal, v9, 0, 0xC0u);
        v3 = 1;
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    }
    v10 = v1->hairColor;
    if ( v10 > -1 && v10 < (signed int)curSX.mHairColorList.m_num )
    {
      v11 = PalSet::Get(curSX.mHairColorList.m_data[v10]);
      if ( v11 )
      {
        v12 = LODWORD(v1->hairShade);
        v17 = HIDWORD(v1->hairShade);
        v16.id = v12;
        v13.id = PalSet::GetPaletteID((PalSet *)v11, &v16, COERCE_LONG_DOUBLE(__PAIR__(v17, v12)))->id;
        if ( v13.id != hairPalID.id )
        {
          hairPalID.id = v13.id;
          Palette::Modify(v1->trueFacePal, v13, 0xC0u, 0x40u);
          v3 = 1;
        }
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
      }
    }
    v14 = v1->eyeColor;
    if ( v14 == -1
      || v14 >= (signed int)curSX.mEyeColorList.m_num
      || (v15.id = curSX.mEyeColorList.m_data[v14].id, v15.id == eyesPalID.id) )
    {
      if ( !v3 )
      {
LABEL_25:
        Sex_CG::~Sex_CG(&curSX);
        return;
      }
    }
    else
    {
      eyesPalID.id = v15.id;
      Palette::Modify(v1->trueFacePal, v15, 0x100u, 0x40u);
    }
    ++v1->trueFacePalChangeNum;
    goto LABEL_25;
  }
}

//----- (00708470) --------------------------------------------------------  // acclient.c:795524
void sub_708470()
{
  flt_8702A4 = 1000.0 + 1.0;
}

//----- (00708490) --------------------------------------------------------  // acclient.c:795530
void sub_708490()
{
  flt_8702A8 = 24.0 * 8.0;
}

//----- (007084B0) --------------------------------------------------------  // acclient.c:795536
void sub_7084B0()
{
  flt_8702AC = 24.0 * 0.5;
}

//----- (007084D0) --------------------------------------------------------  // acclient.c:795542
int sub_7084D0()
{
  return atexit(nullsub_1316);
}

//----- (007084E0) --------------------------------------------------------  // acclient.c:795548
int sub_7084E0()
{
  return atexit(nullsub_1317);
}

//----- (007084F0) --------------------------------------------------------  // acclient.c:795554
int sub_7084F0()
{
  return atexit(nullsub_1318);
}

//----- (00708500) --------------------------------------------------------  // acclient.c:795560
int sub_708500()
{
  return atexit(_E107_93);
}

//----- (00708510) --------------------------------------------------------  // acclient.c:795566
int sub_708510()
{
  return atexit(nullsub_1315);
}

