/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Fade
   Object     : ENGINE\uielement_desc\MD_Data_Fade.obj
   Functions  : 107
   Addresses  : 0069D920 - 0078CCC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069D920) --------------------------------------------------------  // acclient.c:693869
void __thiscall MD_Data_Cursor::Serialize(MD_Data_Fade *this, Archive *_io_archive)
{
  MD_Data_Fade *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, _io_archive);
  Archive::CheckAlignment(_io_archive, 4u);
  v3 = Archive::GetBytes(_io_archive, 4u);
  if ( v3 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v3 = LODWORD(v2->m_startAlpha);
    else
      LODWORD(v2->m_startAlpha) = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(_io_archive, 4u);
  v4 = Archive::GetBytes(_io_archive, 4u);
  if ( v4 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v4 = LODWORD(v2->m_endAlpha);
    else
      LODWORD(v2->m_endAlpha) = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(_io_archive, 4u);
  v5 = Archive::GetBytes(_io_archive, 4u);
  if ( v5 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v5 = LODWORD(v2->m_duration);
    else
      LODWORD(v2->m_duration) = *(_DWORD *)v5;
  }
}

//----- (0069DFC0) --------------------------------------------------------  // acclient.c:694285
void __thiscall MD_Data_Fade::MD_Data_Fade(MD_Data_Fade *this)
{
  MD_Data_Fade *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 0xBu);
  LODWORD(v1->m_endAlpha) = 0;
  LODWORD(v1->m_duration) = 0;
  LODWORD(v1->m_startTime) = LODWORD(dbl_801380);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Fade::vftable;
  LODWORD(v1->m_startAlpha) = 1065353216;
  HIDWORD(v1->m_startTime) = HIDWORD(dbl_801380);
}
// 801388: using guessed type int (__thiscall *MD_Data_Fade::vftable)(void *, char);

//----- (0069E010) --------------------------------------------------------  // acclient.c:694307
void __thiscall MD_Data_Fade::MD_Data_Fade(MD_Data_Fade *this, MD_Data_Fade *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)v2 = &MD_Data_Fade::vftable;
  *(_DWORD *)(v2 + 8) = 1065353216;
  *(_QWORD *)(v2 + 24) = *(_QWORD *)&dbl_801380;
  if ( (MD_Data_Fade *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = LODWORD(_rhs->m_startAlpha);
    *(_DWORD *)(v2 + 12) = LODWORD(_rhs->m_endAlpha);
    *(_DWORD *)(v2 + 16) = LODWORD(_rhs->m_duration);
  }
}
// 801388: using guessed type int (__thiscall *MD_Data_Fade::vftable)(void *, char);

//----- (0069E070) --------------------------------------------------------  // acclient.c:694329
bool __thiscall MD_Data_Fade::ToFileNode(MD_Data_Fade *this, PFileNode *_file_node)
{
  MD_Data_Fade *v2; // ebx@1
  PFileNode *v3; // eax@3
  PFileNode *v4; // eax@5
  PSRefBufferCharData<char> *v5; // ecx@6
  PFileNode *v6; // eax@7
  bool result; // al@8
  PStringBase<char> v8; // [sp-4h] [bp-10h]@3

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v8.m_charbuffer = KW_STARTALPHA_8.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_STARTALPHA_8.m_charbuffer[-1]),
        (v3 = PFileNode::MakeSubNode(_file_node, v8)) != 0)
    && PFileNode::MakeSubNodeAsFloat(v3, v2->m_startAlpha)
    && (v8.m_charbuffer = KW_ENDALPHA_8.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_ENDALPHA_8.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v8)) != 0)
    && PFileNode::MakeSubNodeAsFloat(v4, v2->m_endAlpha)
    && (v8.m_charbuffer = v5,
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (CaseInsensitiveStringBase<PStringBase<char> > *)&v8,
          &KW_DURATION_8),
        (v6 = PFileNode::MakeSubNode(_file_node, v8)) != 0) )
    result = PFileNode::MakeSubNodeAsFloat(v6, v2->m_duration) != 0;
  else
    result = 0;
  return result;
}

//----- (0069E150) --------------------------------------------------------  // acclient.c:694362
char __thiscall MD_Data_Fade::FromFileNode(MD_Data_Fade *this, PFileNode *_file_node)
{
  PFileNode *v2; // ebp@1
  int v3; // edi@1
  char v4; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // eax@3
  PFileNode *v6; // eax@3
  PFileNode *v7; // esi@3
  int v8; // eax@6
  PStringBase<char> *v9; // ecx@6
  int v10; // eax@12
  int v11; // eax@16
  PSRefBufferCharData<char> *v12; // ecx@19
  PStringBase<char> *v13; // eax@19
  char v14; // al@21
  PStringBase<char> *v15; // [sp-8h] [bp-28h]@9
  PStringBase<char> v16; // [sp-4h] [bp-24h]@3
  unsigned int index; // [sp+10h] [bp-10h]@2
  PStringBase<char> rhs; // [sp+14h] [bp-Ch]@19
  PStringBase<char> result; // [sp+18h] [bp-8h]@19
  unsigned int num; // [sp+1Ch] [bp-4h]@2

  v2 = _file_node;
  v3 = (int)this;
  if ( _file_node )
  {
    v4 = 1;
    num = PFileNode::GetNumSubNodes(_file_node);
    index = 0;
    if ( num )
    {
      while ( 1 )
      {
        v5 = v2->vfptr;
        v16.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v6 = (PFileNode *)v5[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, index);
        v7 = v6;
        if ( !v6 )
          goto LABEL_10;
        if ( !PFileNode::IsKeyword(v6, v3, &KW_MEDIATYPE_8) )
          break;
LABEL_20:
        ++index;
        if ( index >= num )
          goto LABEL_21;
      }
      if ( PFileNode::IsKeyword(v7, v3, &KW_STARTALPHA_8) )
      {
        v8 = PFileNode::GetLeaf(v7);
        if ( v8 && PFileNode::GetNameAsFloat((PFileNode *)v8, v3, (float *)(v3 + 8)) )
          goto LABEL_20;
        v16.m_charbuffer = KW_STARTALPHA_8.m_charbuffer;
      }
      else if ( PFileNode::IsKeyword(v7, v3, &KW_ENDALPHA_8) )
      {
        v10 = PFileNode::GetLeaf(v7);
        if ( v10 && PFileNode::GetNameAsFloat((PFileNode *)v10, v3, (float *)(v3 + 12)) )
          goto LABEL_20;
        v16.m_charbuffer = KW_ENDALPHA_8.m_charbuffer;
      }
      else
      {
        if ( !PFileNode::IsKeyword(v7, v3, &KW_DURATION_8) )
        {
          _file_node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          PFileNode::GetNameAsPString(v7, v3, (PStringBase<char> *)&_file_node);
          PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
          v16.m_charbuffer = v12;
          v15 = &rhs;
          v13 = operator+(&result, "Unknown Keyword: [", (PStringBase<char> *)&_file_node);
          PStringBase<char>::operator+(v13, &v16, v15);
          PFileNode::ReportError(v3, v7, v16);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
          v4 = 0;
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_file_node);
          goto LABEL_20;
        }
        v11 = PFileNode::GetLeaf(v7);
        if ( v11 && PFileNode::GetNameAsFloat((PFileNode *)v11, v3, (float *)(v3 + 16)) )
          goto LABEL_20;
        v16.m_charbuffer = KW_DURATION_8.m_charbuffer;
      }
      v15 = v9;
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&v15,
        "MD_Data_Fade::FromFileNode, %s expects one float");
      PFileNode::ReportError(v3, v7, (PStringBase<char>)v15);
LABEL_10:
      v4 = 0;
      goto LABEL_20;
    }
LABEL_21:
    v14 = v4;
  }
  else
  {
    v14 = 0;
  }
  return v14;
}

//----- (0071EE20) --------------------------------------------------------  // acclient.c:816849
int sub_71EE20()
{
  KW_NULL_12.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78C360);
}

//----- (0071EE40) --------------------------------------------------------  // acclient.c:816857
int sub_71EE40()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_8, "Base");
  return atexit(sub_78C390);
}

//----- (0071EE60) --------------------------------------------------------  // acclient.c:816864
int sub_71EE60()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_8, "BottomEdge");
  return atexit(sub_78C3C0);
}

//----- (0071EE80) --------------------------------------------------------  // acclient.c:816871
int _E82_68()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_8, "Child");
  return atexit(_E83_64);
}

//----- (0071EEA0) --------------------------------------------------------  // acclient.c:816878
int _E85_51()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_8, "Code");
  return atexit(_E86_43);
}

//----- (0071EEC0) --------------------------------------------------------  // acclient.c:816885
int _E88_40()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_8, "DefaultState");
  return atexit(_E89_53);
}

//----- (0071EEE0) --------------------------------------------------------  // acclient.c:816892
int sub_71EEE0()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_8, "DisplayHeight");
  return atexit(_E92_62);
}

//----- (0071EF00) --------------------------------------------------------  // acclient.c:816899
int _E94_53()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_8, "DisplayWidth");
  return atexit(sub_78C4B0);
}

//----- (0071EF20) --------------------------------------------------------  // acclient.c:816906
int sub_71EF20()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_8, "DrawMode");
  return atexit(sub_78C4E0);
}

//----- (0071EF40) --------------------------------------------------------  // acclient.c:816913
int sub_71EF40()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_8, "Duration");
  return atexit(sub_78C510);
}

//----- (0071EF60) --------------------------------------------------------  // acclient.c:816920
int sub_71EF60()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_8, "Element");
  return atexit(sub_78C540);
}

//----- (0071EF80) --------------------------------------------------------  // acclient.c:816927
int sub_71EF80()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_8, "ElementHeader");
  return atexit(sub_78C570);
}

//----- (0071EFA0) --------------------------------------------------------  // acclient.c:816934
int sub_71EFA0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_8, "ElementWHeader");
  return atexit(sub_78C5A0);
}

//----- (0071EFC0) --------------------------------------------------------  // acclient.c:816941
int sub_71EFC0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_8, "ElementID");
  return atexit(_E113_86);
}

//----- (0071EFE0) --------------------------------------------------------  // acclient.c:816948
int sub_71EFE0()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_8, "EndAlpha");
  return atexit(_E116_78);
}

//----- (0071F000) --------------------------------------------------------  // acclient.c:816955
int _E118_96()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_8, "EngineType");
  return atexit(sub_78C630);
}

//----- (0071F020) --------------------------------------------------------  // acclient.c:816962
int _E121_87()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_8, "EventID");
  return atexit(sub_78C660);
}

//----- (0071F040) --------------------------------------------------------  // acclient.c:816969
int _E124_87()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_8, "File");
  return atexit(_E125_81);
}

//----- (0071F060) --------------------------------------------------------  // acclient.c:816976
int _E127_74()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_8, "Frames");
  return atexit(_E128_79);
}

//----- (0071F080) --------------------------------------------------------  // acclient.c:816983
int _E130_67()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_8, "PREPROC_HEADER");
  return atexit(_E131_68);
}

//----- (0071F0A0) --------------------------------------------------------  // acclient.c:816990
int _E133_60()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_8, "Height");
  return atexit(_E134_52);
}

//----- (0071F0C0) --------------------------------------------------------  // acclient.c:816997
int _E136_44()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_8, "JumpItemIndex");
  return atexit(_E137_51);
}

//----- (0071F0E0) --------------------------------------------------------  // acclient.c:817004
int _E139_44()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_8, "LeftEdge");
  return atexit(_E140_45);
}

//----- (0071F100) --------------------------------------------------------  // acclient.c:817011
int _E142_41()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_8, "MaxDuration");
  return atexit(_E143_45);
}

//----- (0071F120) --------------------------------------------------------  // acclient.c:817018
int _E145_43()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_8, "Media");
  return atexit(_E146_45);
}

//----- (0071F140) --------------------------------------------------------  // acclient.c:817025
int _E148_42()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_8, "MediaType");
  return atexit(_E149_44);
}

//----- (0071F160) --------------------------------------------------------  // acclient.c:817032
int _E151_40()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_8, "MinDuration");
  return atexit(_E152_45);
}

//----- (0071F180) --------------------------------------------------------  // acclient.c:817039
int _E154_41()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_8, "NoDBFile");
  return atexit(_E155_41);
}

//----- (0071F1A0) --------------------------------------------------------  // acclient.c:817046
int _E157_38()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_8, "StretchToFullScreen");
  return atexit(_E158_42);
}

//----- (0071F1C0) --------------------------------------------------------  // acclient.c:817053
int _E160_41()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_8, "PassToChildren");
  return atexit(_E161_39);
}

//----- (0071F1E0) --------------------------------------------------------  // acclient.c:817060
int _E163_34()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_8, "Probability");
  return atexit(_E164_41);
}

//----- (0071F200) --------------------------------------------------------  // acclient.c:817067
int _E166_36()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_9, "Properties");
  return atexit(_E167_37);
}

//----- (0071F220) --------------------------------------------------------  // acclient.c:817074
int _E169_34()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_8, "Remove");
  return atexit(_E170_37);
}

//----- (0071F240) --------------------------------------------------------  // acclient.c:817081
int _E172_32()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_8, "RightEdge");
  return atexit(_E173_32);
}

//----- (0071F260) --------------------------------------------------------  // acclient.c:817088
int _E175_29()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_8, "SoundName");
  return atexit(_E176_34);
}

//----- (0071F280) --------------------------------------------------------  // acclient.c:817095
int _E178_29()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_8, "SoundTable");
  return atexit(_E179_33);
}

//----- (0071F2A0) --------------------------------------------------------  // acclient.c:817102
int _E181_29()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_8, "StartAlpha");
  return atexit(_E182_33);
}

//----- (0071F2C0) --------------------------------------------------------  // acclient.c:817109
int _E184_27()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_8, "State");
  return atexit(_E185_30);
}

//----- (0071F2E0) --------------------------------------------------------  // acclient.c:817116
int _E187_26()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_8, "StateHeader");
  return atexit(_E188_31);
}

//----- (0071F300) --------------------------------------------------------  // acclient.c:817123
int _E190_27()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_8, "StateWHeader");
  return atexit(_E191_30);
}

//----- (0071F320) --------------------------------------------------------  // acclient.c:817130
int _E193_26()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_8, "StateID");
  return atexit(_E194_37);
}

//----- (0071F340) --------------------------------------------------------  // acclient.c:817137
int _E196_33()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_8, "TopEdge");
  return atexit(_E197_27);
}

//----- (0071F360) --------------------------------------------------------  // acclient.c:817144
int _E199_25()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_8, "Type");
  return atexit(_E200_31);
}

//----- (0071F380) --------------------------------------------------------  // acclient.c:817151
int _E202_29()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_8, "Width");
  return atexit(_E203_30);
}

//----- (0071F3A0) --------------------------------------------------------  // acclient.c:817158
int _E205_27()
{
  PStringBase<char>::PStringBase<char>(&KW_X_8, "X");
  return atexit(_E206_34);
}

//----- (0071F3C0) --------------------------------------------------------  // acclient.c:817165
int _E208_31()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_8, "XHotspot");
  return atexit(_E209_28);
}

//----- (0071F3E0) --------------------------------------------------------  // acclient.c:817172
int _E211_26()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_8, "Y");
  return atexit(_E212_31);
}

//----- (0071F400) --------------------------------------------------------  // acclient.c:817179
int _E214_28()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_8, "YHotspot");
  return atexit(_E215_28);
}

//----- (0071F420) --------------------------------------------------------  // acclient.c:817186
int _E217_25()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_8, "ZLevel");
  return atexit(_E218_28);
}

//----- (0071F440) --------------------------------------------------------  // acclient.c:817193
int _E220_25()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_8, "Comments");
  return atexit(_E221_28);
}

//----- (0071F460) --------------------------------------------------------  // acclient.c:817200
int _E223_26()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_8, "HasAlpha");
  return atexit(_E224_28);
}

//----- (0078C360) --------------------------------------------------------  // acclient.c:932330
void __cdecl sub_78C360()
{
  char *v0; // esi@1

  v0 = &KW_NULL_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C390) --------------------------------------------------------  // acclient.c:932343
void __cdecl sub_78C390()
{
  char *v0; // esi@1

  v0 = &KW_BASE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C3C0) --------------------------------------------------------  // acclient.c:932356
void __cdecl sub_78C3C0()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C3F0) --------------------------------------------------------  // acclient.c:932369
void __cdecl _E83_64()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C420) --------------------------------------------------------  // acclient.c:932382
void __cdecl _E86_43()
{
  char *v0; // esi@1

  v0 = &KW_CODE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C450) --------------------------------------------------------  // acclient.c:932395
void __cdecl _E89_53()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C480) --------------------------------------------------------  // acclient.c:932408
void __cdecl _E92_62()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C4B0) --------------------------------------------------------  // acclient.c:932421
void __cdecl sub_78C4B0()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C4E0) --------------------------------------------------------  // acclient.c:932434
void __cdecl sub_78C4E0()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C510) --------------------------------------------------------  // acclient.c:932447
void __cdecl sub_78C510()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C540) --------------------------------------------------------  // acclient.c:932460
void __cdecl sub_78C540()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C570) --------------------------------------------------------  // acclient.c:932473
void __cdecl sub_78C570()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C5A0) --------------------------------------------------------  // acclient.c:932486
void __cdecl sub_78C5A0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C5D0) --------------------------------------------------------  // acclient.c:932499
void __cdecl _E113_86()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C600) --------------------------------------------------------  // acclient.c:932512
void __cdecl _E116_78()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C630) --------------------------------------------------------  // acclient.c:932525
void __cdecl sub_78C630()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C660) --------------------------------------------------------  // acclient.c:932538
void __cdecl sub_78C660()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C690) --------------------------------------------------------  // acclient.c:932551
void __cdecl _E125_81()
{
  char *v0; // esi@1

  v0 = &KW_FILE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C6C0) --------------------------------------------------------  // acclient.c:932564
void __cdecl _E128_79()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C6F0) --------------------------------------------------------  // acclient.c:932577
void __cdecl _E131_68()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C720) --------------------------------------------------------  // acclient.c:932590
void __cdecl _E134_52()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C750) --------------------------------------------------------  // acclient.c:932603
void __cdecl _E137_51()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C780) --------------------------------------------------------  // acclient.c:932616
void __cdecl _E140_45()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C7B0) --------------------------------------------------------  // acclient.c:932629
void __cdecl _E143_45()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C7E0) --------------------------------------------------------  // acclient.c:932642
void __cdecl _E146_45()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C810) --------------------------------------------------------  // acclient.c:932655
void __cdecl _E149_44()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C840) --------------------------------------------------------  // acclient.c:932668
void __cdecl _E152_45()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C870) --------------------------------------------------------  // acclient.c:932681
void __cdecl _E155_41()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C8A0) --------------------------------------------------------  // acclient.c:932694
void __cdecl _E158_42()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C8D0) --------------------------------------------------------  // acclient.c:932707
void __cdecl _E161_39()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C900) --------------------------------------------------------  // acclient.c:932720
void __cdecl _E164_41()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C930) --------------------------------------------------------  // acclient.c:932733
void __cdecl _E167_37()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C960) --------------------------------------------------------  // acclient.c:932746
void __cdecl _E170_37()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C990) --------------------------------------------------------  // acclient.c:932759
void __cdecl _E173_32()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C9C0) --------------------------------------------------------  // acclient.c:932772
void __cdecl _E176_34()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C9F0) --------------------------------------------------------  // acclient.c:932785
void __cdecl _E179_33()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CA20) --------------------------------------------------------  // acclient.c:932798
void __cdecl _E182_33()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CA50) --------------------------------------------------------  // acclient.c:932811
void __cdecl _E185_30()
{
  char *v0; // esi@1

  v0 = &KW_STATE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CA80) --------------------------------------------------------  // acclient.c:932824
void __cdecl _E188_31()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CAB0) --------------------------------------------------------  // acclient.c:932837
void __cdecl _E191_30()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CAE0) --------------------------------------------------------  // acclient.c:932850
void __cdecl _E194_37()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CB10) --------------------------------------------------------  // acclient.c:932863
void __cdecl _E197_27()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CB40) --------------------------------------------------------  // acclient.c:932876
void __cdecl _E200_31()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CB70) --------------------------------------------------------  // acclient.c:932889
void __cdecl _E203_30()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CBA0) --------------------------------------------------------  // acclient.c:932902
void __cdecl _E206_34()
{
  char *v0; // esi@1

  v0 = &KW_X_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CBD0) --------------------------------------------------------  // acclient.c:932915
void __cdecl _E209_28()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CC00) --------------------------------------------------------  // acclient.c:932928
void __cdecl _E212_31()
{
  char *v0; // esi@1

  v0 = &KW_Y_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CC30) --------------------------------------------------------  // acclient.c:932941
void __cdecl _E215_28()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CC60) --------------------------------------------------------  // acclient.c:932954
void __cdecl _E218_28()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CC90) --------------------------------------------------------  // acclient.c:932967
void __cdecl _E221_28()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CCC0) --------------------------------------------------------  // acclient.c:932980
void __cdecl _E224_28()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

