/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Movie
   Object     : ENGINE\uielement_desc\MD_Data_Movie.obj
   Functions  : 112
   Addresses  : 0069CEE0 - 00789CE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069CEE0) --------------------------------------------------------  // acclient.c:693180
void __thiscall MD_Data_Movie::MD_Data_Movie(MD_Data_Movie *this)
{
  MD_Data_Movie *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 1u);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Movie::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_strFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v1->m_StretchToFullScreen = 0;
  v1->m_pMovieTheatre = 0;
}
// 801028: using guessed type int (__thiscall *MD_Data_Movie::vftable)(void *, char);

//----- (0069CF10) --------------------------------------------------------  // acclient.c:693197
int __thiscall MD_Data_Movie::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@2
  int v4; // ebx@3
  int v5; // eax@6
  int v6; // ecx@7
  bool v7; // zf@8
  int v8; // edi@11

  v2 = this;
  if ( this != a2 )
  {
    MediaDesc::operator=(this, a2);
    v3 = *(_DWORD *)(v2 + 8);
    if ( v3 != *(_DWORD *)(a2 + 8) )
    {
      v4 = v3 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      v5 = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v2 + 8) = v5;
      InterlockedIncrement((volatile LONG *)(v5 - 16));
    }
    v6 = *(_DWORD *)(v2 + 16);
    *(_BYTE *)(v2 + 12) = *(_BYTE *)(a2 + 12);
    if ( v6 )
    {
      v7 = (*(_DWORD *)(v6 + 4))-- == 1;
      if ( v7 )
        (**(void (__stdcall ***)(_DWORD))v6)(1);
      *(_DWORD *)(v2 + 16) = 0;
    }
    v8 = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v2 + 16) = v8;
    if ( v8 )
      ++*(_DWORD *)(v8 + 4);
  }
  return v2;
}

//----- (0069CF90) --------------------------------------------------------  // acclient.c:693239
MD_Data_Movie *__thiscall MD_Data_Movie::scalar_deleting_destructor(MD_Data_Movie *this, unsigned int a2)
{
  MD_Data_Movie *v2; // esi@1
  MovieTheatre *v3; // ecx@1
  bool v4; // zf@2
  int v5; // edi@5

  v2 = this;
  v3 = this->m_pMovieTheatre;
  v2->vfptr = (MediaDescVtbl *)&MD_Data_Movie::vftable;
  if ( v3 )
  {
    v4 = v3->m_cRef-- == 1;
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
    v2->m_pMovieTheatre = 0;
  }
  v5 = (int)&v2->m_strFileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  MediaDesc::~MediaDesc((MediaDesc *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 801028: using guessed type int (__thiscall *MD_Data_Movie::vftable)(void *, char);

//----- (0069D000) --------------------------------------------------------  // acclient.c:693267
void __thiscall MD_Data_Movie::MD_Data_Movie(MD_Data_Movie *this, MD_Data_Movie *_rhs)
{
  int v2; // esi@1
  volatile LONG *v3; // ST00_4@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Movie::vftable;
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  *(_DWORD *)(v2 + 8) = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  *(_BYTE *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  MD_Data_Movie::operator=(v2, (int)_rhs);
}
// 801028: using guessed type int (__thiscall *MD_Data_Movie::vftable)(void *, char);

//----- (0069D040) --------------------------------------------------------  // acclient.c:693285
char __thiscall MD_Data_Movie::Update(MD_Data_Movie *this, UIElement *i_pOwner)
{
  MovieTheatre **v2; // esi@1
  char result; // al@3
  char v4; // bl@5
  MovieTheatre *v5; // ecx@6
  bool v6; // zf@7

  v2 = &this->m_pMovieTheatre;
  if ( this->m_pMovieTheatre
    || (MovieTheatre::CreateTheatreForMovie(
          (TResult *)&i_pOwner,
          &this->m_strFileName,
          0,
          i_pOwner,
          &this->m_pMovieTheatre)->m_val & 0x80000000) == 0 )
  {
    if ( *v2 )
    {
      v4 = MovieTheatre::HasFinishedPlaying(*v2);
      if ( v4 )
      {
        v5 = *v2;
        if ( *v2 )
        {
          v6 = v5->m_cRef-- == 1;
          if ( v6 )
            ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
          *v2 = 0;
        }
      }
      result = v4;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0069D0B0) --------------------------------------------------------  // acclient.c:693331
void __thiscall MD_Data_Movie::Serialize(MD_Data_Movie *this, Archive *_io_archive)
{
  MD_Data_Movie *v2; // esi@1

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, _io_archive);
  PStringBase<char>::Serialize(&v2->m_strFileName, _io_archive);
  Serializer::SerializeObject(&v2->m_StretchToFullScreen, _io_archive);
}

//----- (0069D0E0) --------------------------------------------------------  // acclient.c:693342
bool __thiscall MD_Data_Movie::ToFileNode(MD_Data_Movie *this, PFileNode *_file_node)
{
  MD_Data_Movie *v2; // ebp@1
  PStringBase<char> v3; // ST04_4@3
  PFileNode *v4; // edi@3
  PStringBase<char> v5; // ST04_4@4
  PStringBase<char> v6; // ST04_4@5
  PFileNode *v7; // eax@5
  bool result; // al@6

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v3.m_charbuffer = KW_NO_DB_FILE_3.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_NO_DB_FILE_3.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v3)) != 0)
    && (v5.m_charbuffer = v2->m_strFileName.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&v5.m_charbuffer[-1]),
        PFileNode::MakeSubNode(v4, v5))
    && (v6.m_charbuffer = KW_STRETCH_TO_FULL_SCREEN_3.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_3.m_charbuffer[-1]),
        (v7 = PFileNode::MakeSubNode(_file_node, v6)) != 0) )
    result = PFileNode::MakeSubNodeAsBool(v7, v2->m_StretchToFullScreen) != 0;
  else
    result = 0;
  return result;
}

//----- (0069D190) --------------------------------------------------------  // acclient.c:693371
char __thiscall MD_Data_Movie::FromFileNode(MD_Data_Movie *this, PFileNode *_file_node)
{
  int v2; // edi@1
  char v3; // bl@2
  int v4; // eax@3
  PFileNode *v5; // eax@3
  PFileNode *v6; // esi@3
  int v7; // eax@7
  int v8; // edi@9
  PStringBase<char> *v9; // ecx@9
  int v10; // edx@11
  char v11; // al@14
  int v12; // eax@16
  PSRefBufferCharData<char> *v13; // ecx@16
  PSRefBufferCharData<char> *v14; // ecx@19
  PStringBase<char> *v15; // eax@19
  char *v16; // esi@19
  int v17; // edx@21
  char *v18; // esi@22
  int v19; // edx@24
  char *v20; // esi@25
  int v21; // edx@27
  PStringBase<char> *v22; // [sp-8h] [bp-30h]@9
  PStringBase<char> v23; // [sp-4h] [bp-2Ch]@3
  PStringBase<char> strName; // [sp+10h] [bp-18h]@9
  unsigned int index; // [sp+14h] [bp-14h]@2
  MD_Data_Movie *v26; // [sp+18h] [bp-10h]@1
  PStringBase<char> rhs; // [sp+1Ch] [bp-Ch]@19
  PStringBase<char> result; // [sp+20h] [bp-8h]@19
  unsigned int num; // [sp+24h] [bp-4h]@2

  v2 = (int)_file_node;
  v26 = this;
  if ( _file_node )
  {
    v3 = 1;
    num = PFileNode::GetNumSubNodes(_file_node);
    index = 0;
    if ( num )
    {
      do
      {
        v4 = *(_DWORD *)v2;
        v23.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v5 = (PFileNode *)(*(int (__thiscall **)(int, unsigned int))(v4 + 12))(v2, index);
        v6 = v5;
        if ( v5 )
        {
          if ( !PFileNode::IsKeyword(v5, v2, &KW_MEDIATYPE_3) )
          {
            if ( PFileNode::IsKeyword(v6, v2, &KW_NO_DB_FILE_3) )
            {
              v7 = PFileNode::GetLeaf(v6);
              if ( !v7 || !PFileNode::GetNameAsPString((PFileNode *)v7, v2, &v26->m_strFileName) )
              {
                strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
                InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
                PFileNode::GetNameAsPString(v6, v2, &strName);
                v8 = (int)strName.m_charbuffer;
                v23.m_charbuffer = strName.m_charbuffer;
                v22 = v9;
                PStringBase<char>::PStringBase<char>(
                  (PStringBase<char> *)&v22,
                  "MD_Data_Movie::HandleNode, %s expects one string");
                PFileNode::ReportError(v8, v6, (PStringBase<char>)v22);
                v3 = 0;
                if ( !InterlockedDecrement((volatile LONG *)(v8 - 20 + 4)) && v8 != 20 )
                {
                  v10 = *(_DWORD *)(v8 - 20);
                  v23.m_charbuffer = (PSRefBufferCharData<char> *)1;
                  (*(void (__thiscall **)(int, signed int))v10)(v8 - 20, 1);
                }
                v2 = (int)_file_node;
              }
            }
            else if ( PFileNode::IsKeyword(v6, v2, &KW_STRETCH_TO_FULL_SCREEN_3) )
            {
              v12 = PFileNode::GetLeaf(v6);
              if ( !v12 || !PFileNode::GetNameAsBool((PFileNode *)v12, v2, &v26->m_StretchToFullScreen) )
              {
                v23.m_charbuffer = v13;
                PStringBase<char>::PStringBase<char>(
                  &v23,
                  "MD_Data_Movie::FromFileNode, could not parse 'StretchToFullScreen' node");
                PFileNode::ReportError(v2, v6, v23);
                v3 = 0;
              }
            }
            else
            {
              strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
              InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
              PFileNode::GetNameAsPString(v6, v2, &strName);
              PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
              v23.m_charbuffer = v14;
              v22 = &rhs;
              v15 = operator+(&result, "Unknown Keyword: [", &strName);
              PStringBase<char>::operator+(v15, &v23, v22);
              PFileNode::ReportError(v2, v6, v23);
              v16 = &result.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v16 )
              {
                v17 = *(_DWORD *)v16;
                v23.m_charbuffer = (PSRefBufferCharData<char> *)1;
                (*(void (__thiscall **)(char *, signed int))v17)(v16, 1);
              }
              v18 = &rhs.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v18 )
              {
                v19 = *(_DWORD *)v18;
                v23.m_charbuffer = (PSRefBufferCharData<char> *)1;
                (*(void (__thiscall **)(char *, signed int))v19)(v18, 1);
              }
              v20 = &strName.m_charbuffer[-2].m_data[12];
              v3 = 0;
              if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) && v20 )
              {
                v21 = *(_DWORD *)v20;
                v23.m_charbuffer = (PSRefBufferCharData<char> *)1;
                (*(void (__thiscall **)(char *, signed int))v21)(v20, 1);
              }
            }
          }
        }
        else
        {
          v3 = 0;
        }
        ++index;
      }
      while ( index < num );
    }
    v11 = v3;
  }
  else
  {
    v11 = 0;
  }
  return v11;
}

//----- (0071CE10) --------------------------------------------------------  // acclient.c:815041
void _E74()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9298, PFID_A8R8G8B8);
}

//----- (0071CE20) --------------------------------------------------------  // acclient.c:815047
int _E92_7()
{
  KW_NULL_7.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_789380);
}

//----- (0071CE40) --------------------------------------------------------  // acclient.c:815055
int sub_71CE40()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_3, "Base");
  return atexit(_E96_9);
}

//----- (0071CE60) --------------------------------------------------------  // acclient.c:815062
int _E98_19()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_3, "BottomEdge");
  return atexit(_E99_53);
}

//----- (0071CE80) --------------------------------------------------------  // acclient.c:815069
int _E101_45()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_3, "Child");
  return atexit(_E102_43);
}

//----- (0071CEA0) --------------------------------------------------------  // acclient.c:815076
int _E104_20()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_3, "Code");
  return atexit(_E105_69);
}

//----- (0071CEC0) --------------------------------------------------------  // acclient.c:815083
int _E107_48()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_3, "DefaultState");
  return atexit(sub_789470);
}

//----- (0071CEE0) --------------------------------------------------------  // acclient.c:815090
int _E110_82()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_3, "DisplayHeight");
  return atexit(_E111_73);
}

//----- (0071CF00) --------------------------------------------------------  // acclient.c:815097
int _E113_33()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_3, "DisplayWidth");
  return atexit(_E114_79);
}

//----- (0071CF20) --------------------------------------------------------  // acclient.c:815104
int _E116_26()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_3, "DrawMode");
  return atexit(sub_789500);
}

//----- (0071CF40) --------------------------------------------------------  // acclient.c:815111
int _E119_34()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_3, "Duration");
  return atexit(_E120_87);
}

//----- (0071CF60) --------------------------------------------------------  // acclient.c:815118
int _E122_37()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_3, "Element");
  return atexit(_E123_58);
}

//----- (0071CF80) --------------------------------------------------------  // acclient.c:815125
int _E125_12()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_3, "ElementHeader");
  return atexit(_E126_66);
}

//----- (0071CFA0) --------------------------------------------------------  // acclient.c:815132
int _E128_13()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_3, "ElementWHeader");
  return atexit(_E129_61);
}

//----- (0071CFC0) --------------------------------------------------------  // acclient.c:815139
int _E131_10()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_3, "ElementID");
  return atexit(_E132_62);
}

//----- (0071CFE0) --------------------------------------------------------  // acclient.c:815146
int _E134_9()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_3, "EndAlpha");
  return atexit(_E135_70);
}

//----- (0071D000) --------------------------------------------------------  // acclient.c:815153
int _E137_11()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_3, "EngineType");
  return atexit(_E138_55);
}

//----- (0071D020) --------------------------------------------------------  // acclient.c:815160
int _E140_6()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_3, "EventID");
  return atexit(_E141_57);
}

//----- (0071D040) --------------------------------------------------------  // acclient.c:815167
int _E143_8()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_3, "File");
  return atexit(_E144_53);
}

//----- (0071D060) --------------------------------------------------------  // acclient.c:815174
int _E146_7()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_3, "Frames");
  return atexit(_E147_52);
}

//----- (0071D080) --------------------------------------------------------  // acclient.c:815181
int _E149_7()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_3, "PREPROC_HEADER");
  return atexit(_E150_51);
}

//----- (0071D0A0) --------------------------------------------------------  // acclient.c:815188
int _E152_6()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_3, "Height");
  return atexit(_E153_49);
}

//----- (0071D0C0) --------------------------------------------------------  // acclient.c:815195
int _E155_4()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_3, "JumpItemIndex");
  return atexit(_E156_50);
}

//----- (0071D0E0) --------------------------------------------------------  // acclient.c:815202
int _E158_7()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_3, "LeftEdge");
  return atexit(_E159_48);
}

//----- (0071D100) --------------------------------------------------------  // acclient.c:815209
int _E161_4()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_3, "MaxDuration");
  return atexit(_E162_51);
}

//----- (0071D120) --------------------------------------------------------  // acclient.c:815216
int _E164_8()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_3, "Media");
  return atexit(_E165_47);
}

//----- (0071D140) --------------------------------------------------------  // acclient.c:815223
int _E167_4()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_3, "MediaType");
  return atexit(_E168_48);
}

//----- (0071D160) --------------------------------------------------------  // acclient.c:815230
int _E170_4()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_3, "MinDuration");
  return atexit(_E171_47);
}

//----- (0071D180) --------------------------------------------------------  // acclient.c:815237
int _E173_3()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_3, "NoDBFile");
  return atexit(_E174_49);
}

//----- (0071D1A0) --------------------------------------------------------  // acclient.c:815244
int _E176_4()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_3, "StretchToFullScreen");
  return atexit(_E177_46);
}

//----- (0071D1C0) --------------------------------------------------------  // acclient.c:815251
int _E179_3()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_3, "PassToChildren");
  return atexit(_E180_47);
}

//----- (0071D1E0) --------------------------------------------------------  // acclient.c:815258
int _E182_3()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_3, "Probability");
  return atexit(_E183_46);
}

//----- (0071D200) --------------------------------------------------------  // acclient.c:815265
int _E185_2()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_4, "Properties");
  return atexit(_E186_46);
}

//----- (0071D220) --------------------------------------------------------  // acclient.c:815272
int _E188_3()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_3, "Remove");
  return atexit(_E189_45);
}

//----- (0071D240) --------------------------------------------------------  // acclient.c:815279
int _E191_2()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_3, "RightEdge");
  return atexit(_E192_35);
}

//----- (0071D260) --------------------------------------------------------  // acclient.c:815286
int _E194_8()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_3, "SoundName");
  return atexit(_E195_26);
}

//----- (0071D280) --------------------------------------------------------  // acclient.c:815293
int _E197_0()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_3, "SoundTable");
  return atexit(_E198_31);
}

//----- (0071D2A0) --------------------------------------------------------  // acclient.c:815300
int _E200_5()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_3, "StartAlpha");
  return atexit(_E201_24);
}

//----- (0071D2C0) --------------------------------------------------------  // acclient.c:815307
int _E203_4()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_3, "State");
  return atexit(_E204_19);
}

//----- (0071D2E0) --------------------------------------------------------  // acclient.c:815314
int _E206_6()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_3, "StateHeader");
  return atexit(_E207_15);
}

//----- (0071D300) --------------------------------------------------------  // acclient.c:815321
int _E209_1()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_3, "StateWHeader");
  return atexit(_E210_19);
}

//----- (0071D320) --------------------------------------------------------  // acclient.c:815328
int _E212_4()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_3, "StateID");
  return atexit(_E213_14);
}

//----- (0071D340) --------------------------------------------------------  // acclient.c:815335
int _E215_0()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_3, "TopEdge");
  return atexit(_E216_16);
}

//----- (0071D360) --------------------------------------------------------  // acclient.c:815342
int _E218_0()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_3, "Type");
  return atexit(_E219_12);
}

//----- (0071D380) --------------------------------------------------------  // acclient.c:815349
int _E221_1()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_3, "Width");
  return atexit(_E222_11);
}

//----- (0071D3A0) --------------------------------------------------------  // acclient.c:815356
int _E224_0()
{
  PStringBase<char>::PStringBase<char>(&KW_X_3, "X");
  return atexit(_E225_8);
}

//----- (0071D3C0) --------------------------------------------------------  // acclient.c:815363
int _E227_0()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_3, "XHotspot");
  return atexit(_E228_8);
}

//----- (0071D3E0) --------------------------------------------------------  // acclient.c:815370
int _E230_0()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_3, "Y");
  return atexit(_E231_8);
}

//----- (0071D400) --------------------------------------------------------  // acclient.c:815377
int _E233_0()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_3, "YHotspot");
  return atexit(_E234_7);
}

//----- (0071D420) --------------------------------------------------------  // acclient.c:815384
int _E236_0()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_3, "ZLevel");
  return atexit(_E237_8);
}

//----- (0071D440) --------------------------------------------------------  // acclient.c:815391
int _E239_1()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_3, "Comments");
  return atexit(_E240_8);
}

//----- (0071D460) --------------------------------------------------------  // acclient.c:815398
int _E242_1()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_3, "HasAlpha");
  return atexit(_E243_8);
}

//----- (0071D480) --------------------------------------------------------  // acclient.c:815405
int sub_71D480()
{
  return atexit(nullsub_315);
}

//----- (00789380) --------------------------------------------------------  // acclient.c:929015
void __cdecl sub_789380()
{
  char *v0; // esi@1

  v0 = &KW_NULL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007893B0) --------------------------------------------------------  // acclient.c:929028
void __cdecl _E96_9()
{
  char *v0; // esi@1

  v0 = &KW_BASE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007893E0) --------------------------------------------------------  // acclient.c:929041
void __cdecl _E99_53()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789410) --------------------------------------------------------  // acclient.c:929054
void __cdecl _E102_43()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789440) --------------------------------------------------------  // acclient.c:929067
void __cdecl _E105_69()
{
  char *v0; // esi@1

  v0 = &KW_CODE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789470) --------------------------------------------------------  // acclient.c:929080
void __cdecl sub_789470()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007894A0) --------------------------------------------------------  // acclient.c:929093
void __cdecl _E111_73()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007894D0) --------------------------------------------------------  // acclient.c:929106
void __cdecl _E114_79()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789500) --------------------------------------------------------  // acclient.c:929119
void __cdecl sub_789500()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789530) --------------------------------------------------------  // acclient.c:929132
void __cdecl _E120_87()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789560) --------------------------------------------------------  // acclient.c:929145
void __cdecl _E123_58()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789590) --------------------------------------------------------  // acclient.c:929158
void __cdecl _E126_66()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007895C0) --------------------------------------------------------  // acclient.c:929171
void __cdecl _E129_61()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007895F0) --------------------------------------------------------  // acclient.c:929184
void __cdecl _E132_62()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789620) --------------------------------------------------------  // acclient.c:929197
void __cdecl _E135_70()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789650) --------------------------------------------------------  // acclient.c:929210
void __cdecl _E138_55()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789680) --------------------------------------------------------  // acclient.c:929223
void __cdecl _E141_57()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007896B0) --------------------------------------------------------  // acclient.c:929236
void __cdecl _E144_53()
{
  char *v0; // esi@1

  v0 = &KW_FILE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007896E0) --------------------------------------------------------  // acclient.c:929249
void __cdecl _E147_52()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789710) --------------------------------------------------------  // acclient.c:929262
void __cdecl _E150_51()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789740) --------------------------------------------------------  // acclient.c:929275
void __cdecl _E153_49()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789770) --------------------------------------------------------  // acclient.c:929288
void __cdecl _E156_50()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007897A0) --------------------------------------------------------  // acclient.c:929301
void __cdecl _E159_48()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007897D0) --------------------------------------------------------  // acclient.c:929314
void __cdecl _E162_51()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789800) --------------------------------------------------------  // acclient.c:929327
void __cdecl _E165_47()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789830) --------------------------------------------------------  // acclient.c:929340
void __cdecl _E168_48()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789860) --------------------------------------------------------  // acclient.c:929353
void __cdecl _E171_47()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789890) --------------------------------------------------------  // acclient.c:929366
void __cdecl _E174_49()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007898C0) --------------------------------------------------------  // acclient.c:929379
void __cdecl _E177_46()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007898F0) --------------------------------------------------------  // acclient.c:929392
void __cdecl _E180_47()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789920) --------------------------------------------------------  // acclient.c:929405
void __cdecl _E183_46()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789950) --------------------------------------------------------  // acclient.c:929418
void __cdecl _E186_46()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789980) --------------------------------------------------------  // acclient.c:929431
void __cdecl _E189_45()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007899B0) --------------------------------------------------------  // acclient.c:929444
void __cdecl _E192_35()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007899E0) --------------------------------------------------------  // acclient.c:929457
void __cdecl _E195_26()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789A10) --------------------------------------------------------  // acclient.c:929470
void __cdecl _E198_31()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789A40) --------------------------------------------------------  // acclient.c:929483
void __cdecl _E201_24()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789A70) --------------------------------------------------------  // acclient.c:929496
void __cdecl _E204_19()
{
  char *v0; // esi@1

  v0 = &KW_STATE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789AA0) --------------------------------------------------------  // acclient.c:929509
void __cdecl _E207_15()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789AD0) --------------------------------------------------------  // acclient.c:929522
void __cdecl _E210_19()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789B00) --------------------------------------------------------  // acclient.c:929535
void __cdecl _E213_14()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789B30) --------------------------------------------------------  // acclient.c:929548
void __cdecl _E216_16()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789B60) --------------------------------------------------------  // acclient.c:929561
void __cdecl _E219_12()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789B90) --------------------------------------------------------  // acclient.c:929574
void __cdecl _E222_11()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789BC0) --------------------------------------------------------  // acclient.c:929587
void __cdecl _E225_8()
{
  char *v0; // esi@1

  v0 = &KW_X_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789BF0) --------------------------------------------------------  // acclient.c:929600
void __cdecl _E228_8()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789C20) --------------------------------------------------------  // acclient.c:929613
void __cdecl _E231_8()
{
  char *v0; // esi@1

  v0 = &KW_Y_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789C50) --------------------------------------------------------  // acclient.c:929626
void __cdecl _E234_7()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789C80) --------------------------------------------------------  // acclient.c:929639
void __cdecl _E237_8()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789CB0) --------------------------------------------------------  // acclient.c:929652
void __cdecl _E240_8()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789CE0) --------------------------------------------------------  // acclient.c:929665
void __cdecl _E243_8()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

