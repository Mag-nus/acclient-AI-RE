/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Sound
   Object     : ENGINE\uielement_desc\MD_Data_Sound.obj
   Functions  : 107
   Addresses  : 0069E5F0 - 0078DFF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069E5F0) --------------------------------------------------------  // acclient.c:694648
void __thiscall MD_Data_Sound::MD_Data_Sound(MD_Data_Sound *this)
{
  MD_Data_Sound *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 9u);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Sound::vftable;
  v1->m_file.id = stru_8F994C.id;
  v1->m_stype = 0;
}
// 801508: using guessed type int (__thiscall *MD_Data_Sound::vftable)(void *, char);

//----- (0069E620) --------------------------------------------------------  // acclient.c:694661
void __thiscall MD_Data_Sound::MD_Data_Sound(MD_Data_Sound *this, MD_Data_Sound *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Sound::vftable;
  *(_DWORD *)(v2 + 8) = stru_8F994C.id;
  *(_DWORD *)(v2 + 12) = 0;
  if ( (MD_Data_Sound *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_file.id;
    *(_DWORD *)(v2 + 12) = _rhs->m_stype;
  }
}
// 801508: using guessed type int (__thiscall *MD_Data_Sound::vftable)(void *, char);

//----- (0069E670) --------------------------------------------------------  // acclient.c:694680
void __thiscall MD_Data_Sound::Serialize(MD_Data_Sound *this, Archive *_io_archive)
{
  MD_Data_Sound *v2; // edi@1
  unsigned int v3; // eax@1
  SoundType v4; // ebp@5
  unsigned int v5; // eax@5

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, _io_archive);
  Archive::CheckAlignment(_io_archive, 4u);
  v3 = Archive::GetBytes(_io_archive, 4u);
  if ( v3 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_file.id;
    else
      v2->m_file.id = *(_DWORD *)v3;
  }
  v4 = v2->m_stype;
  Archive::CheckAlignment(_io_archive, 4u);
  v5 = Archive::GetBytes(_io_archive, 4u);
  if ( v5 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      v4 = *(_DWORD *)v5;
  }
  if ( !(_io_archive->m_flags & 5) )
    v2->m_stype = v4;
}

//----- (0069EAB0) --------------------------------------------------------  // acclient.c:694959
void __thiscall MD_Data_Alpha::GetSubDataIDs(MD_Data_Sound *this, QualifiedDataIDArray *_id_array)
{
  MD_Data_Sound *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  QualifiedDataID v4; // [sp+8h] [bp-8h]@1

  v2 = this;
  gmNoticeHandler::RecvNotice_UpdateRentPayment((PlayerModule *)this, (PlayerOption)_id_array);
  QualifiedDataID::QualifiedDataID(&v4, v2->m_file, 0);
  QualifiedDataIDArray::AddQDID(_id_array, v3, 0);
}

//----- (0071FAE0) --------------------------------------------------------  // acclient.c:817565
int sub_71FAE0()
{
  KW_NULL_14.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78D690);
}

//----- (0071FB00) --------------------------------------------------------  // acclient.c:817573
int sub_71FB00()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_10, "Base");
  return atexit(sub_78D6C0);
}

//----- (0071FB20) --------------------------------------------------------  // acclient.c:817580
int sub_71FB20()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_10, "BottomEdge");
  return atexit(sub_78D6F0);
}

//----- (0071FB40) --------------------------------------------------------  // acclient.c:817587
int _E82_70()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_10, "Child");
  return atexit(_E83_66);
}

//----- (0071FB60) --------------------------------------------------------  // acclient.c:817594
int _E85_53()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_10, "Code");
  return atexit(_E86_45);
}

//----- (0071FB80) --------------------------------------------------------  // acclient.c:817601
int _E88_42()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_10, "DefaultState");
  return atexit(_E89_55);
}

//----- (0071FBA0) --------------------------------------------------------  // acclient.c:817608
int sub_71FBA0()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_10, "DisplayHeight");
  return atexit(_E92_64);
}

//----- (0071FBC0) --------------------------------------------------------  // acclient.c:817615
int _E94_55()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_10, "DisplayWidth");
  return atexit(sub_78D7E0);
}

//----- (0071FBE0) --------------------------------------------------------  // acclient.c:817622
int sub_71FBE0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_10, "DrawMode");
  return atexit(sub_78D810);
}

//----- (0071FC00) --------------------------------------------------------  // acclient.c:817629
int sub_71FC00()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_10, "Duration");
  return atexit(sub_78D840);
}

//----- (0071FC20) --------------------------------------------------------  // acclient.c:817636
int sub_71FC20()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_10, "Element");
  return atexit(sub_78D870);
}

//----- (0071FC40) --------------------------------------------------------  // acclient.c:817643
int sub_71FC40()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_10, "ElementHeader");
  return atexit(sub_78D8A0);
}

//----- (0071FC60) --------------------------------------------------------  // acclient.c:817650
int sub_71FC60()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_10, "ElementWHeader");
  return atexit(sub_78D8D0);
}

//----- (0071FC80) --------------------------------------------------------  // acclient.c:817657
int sub_71FC80()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_10, "ElementID");
  return atexit(_E113_88);
}

//----- (0071FCA0) --------------------------------------------------------  // acclient.c:817664
int sub_71FCA0()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_10, "EndAlpha");
  return atexit(_E116_80);
}

//----- (0071FCC0) --------------------------------------------------------  // acclient.c:817671
int _E118_98()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_10, "EngineType");
  return atexit(sub_78D960);
}

//----- (0071FCE0) --------------------------------------------------------  // acclient.c:817678
int _E121_89()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_10, "EventID");
  return atexit(sub_78D990);
}

//----- (0071FD00) --------------------------------------------------------  // acclient.c:817685
int _E124_89()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_10, "File");
  return atexit(_E125_83);
}

//----- (0071FD20) --------------------------------------------------------  // acclient.c:817692
int _E127_76()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_10, "Frames");
  return atexit(_E128_81);
}

//----- (0071FD40) --------------------------------------------------------  // acclient.c:817699
int _E130_69()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_10, "PREPROC_HEADER");
  return atexit(_E131_70);
}

//----- (0071FD60) --------------------------------------------------------  // acclient.c:817706
int _E133_62()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_10, "Height");
  return atexit(_E134_54);
}

//----- (0071FD80) --------------------------------------------------------  // acclient.c:817713
int _E136_46()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_10, "JumpItemIndex");
  return atexit(_E137_53);
}

//----- (0071FDA0) --------------------------------------------------------  // acclient.c:817720
int _E139_46()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_10, "LeftEdge");
  return atexit(_E140_47);
}

//----- (0071FDC0) --------------------------------------------------------  // acclient.c:817727
int _E142_43()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_10, "MaxDuration");
  return atexit(_E143_47);
}

//----- (0071FDE0) --------------------------------------------------------  // acclient.c:817734
int _E145_45()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_10, "Media");
  return atexit(_E146_47);
}

//----- (0071FE00) --------------------------------------------------------  // acclient.c:817741
int _E148_44()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_10, "MediaType");
  return atexit(_E149_46);
}

//----- (0071FE20) --------------------------------------------------------  // acclient.c:817748
int _E151_42()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_10, "MinDuration");
  return atexit(_E152_47);
}

//----- (0071FE40) --------------------------------------------------------  // acclient.c:817755
int _E154_43()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_10, "NoDBFile");
  return atexit(_E155_43);
}

//----- (0071FE60) --------------------------------------------------------  // acclient.c:817762
int _E157_40()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_10, "StretchToFullScreen");
  return atexit(_E158_44);
}

//----- (0071FE80) --------------------------------------------------------  // acclient.c:817769
int _E160_43()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_10, "PassToChildren");
  return atexit(_E161_41);
}

//----- (0071FEA0) --------------------------------------------------------  // acclient.c:817776
int _E163_36()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_10, "Probability");
  return atexit(_E164_43);
}

//----- (0071FEC0) --------------------------------------------------------  // acclient.c:817783
int _E166_38()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_11, "Properties");
  return atexit(_E167_39);
}

//----- (0071FEE0) --------------------------------------------------------  // acclient.c:817790
int _E169_36()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_10, "Remove");
  return atexit(_E170_39);
}

//----- (0071FF00) --------------------------------------------------------  // acclient.c:817797
int _E172_34()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_10, "RightEdge");
  return atexit(_E173_34);
}

//----- (0071FF20) --------------------------------------------------------  // acclient.c:817804
int _E175_31()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_10, "SoundName");
  return atexit(_E176_36);
}

//----- (0071FF40) --------------------------------------------------------  // acclient.c:817811
int _E178_31()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_10, "SoundTable");
  return atexit(_E179_35);
}

//----- (0071FF60) --------------------------------------------------------  // acclient.c:817818
int _E181_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_10, "StartAlpha");
  return atexit(_E182_35);
}

//----- (0071FF80) --------------------------------------------------------  // acclient.c:817825
int _E184_29()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_10, "State");
  return atexit(_E185_32);
}

//----- (0071FFA0) --------------------------------------------------------  // acclient.c:817832
int _E187_28()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_10, "StateHeader");
  return atexit(_E188_33);
}

//----- (0071FFC0) --------------------------------------------------------  // acclient.c:817839
int _E190_29()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_10, "StateWHeader");
  return atexit(_E191_32);
}

//----- (0071FFE0) --------------------------------------------------------  // acclient.c:817846
int _E193_28()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_10, "StateID");
  return atexit(_E194_39);
}

//----- (00720000) --------------------------------------------------------  // acclient.c:817853
int _E196_35()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_10, "TopEdge");
  return atexit(_E197_29);
}

//----- (00720020) --------------------------------------------------------  // acclient.c:817860
int _E199_27()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_10, "Type");
  return atexit(_E200_33);
}

//----- (00720040) --------------------------------------------------------  // acclient.c:817867
int _E202_31()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_10, "Width");
  return atexit(_E203_32);
}

//----- (00720060) --------------------------------------------------------  // acclient.c:817874
int _E205_29()
{
  PStringBase<char>::PStringBase<char>(&KW_X_10, "X");
  return atexit(_E206_36);
}

//----- (00720080) --------------------------------------------------------  // acclient.c:817881
int _E208_33()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_10, "XHotspot");
  return atexit(_E209_30);
}

//----- (007200A0) --------------------------------------------------------  // acclient.c:817888
int _E211_28()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_10, "Y");
  return atexit(_E212_33);
}

//----- (007200C0) --------------------------------------------------------  // acclient.c:817895
int _E214_30()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_10, "YHotspot");
  return atexit(_E215_30);
}

//----- (007200E0) --------------------------------------------------------  // acclient.c:817902
int _E217_27()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_10, "ZLevel");
  return atexit(_E218_30);
}

//----- (00720100) --------------------------------------------------------  // acclient.c:817909
int _E220_27()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_10, "Comments");
  return atexit(_E221_30);
}

//----- (00720120) --------------------------------------------------------  // acclient.c:817916
int _E223_28()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_10, "HasAlpha");
  return atexit(_E224_30);
}

//----- (00720140) --------------------------------------------------------  // acclient.c:817923
int sub_720140()
{
  return atexit(nullsub_316);
}

//----- (0078D690) --------------------------------------------------------  // acclient.c:933656
void __cdecl sub_78D690()
{
  char *v0; // esi@1

  v0 = &KW_NULL_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D6C0) --------------------------------------------------------  // acclient.c:933669
void __cdecl sub_78D6C0()
{
  char *v0; // esi@1

  v0 = &KW_BASE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D6F0) --------------------------------------------------------  // acclient.c:933682
void __cdecl sub_78D6F0()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D720) --------------------------------------------------------  // acclient.c:933695
void __cdecl _E83_66()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D750) --------------------------------------------------------  // acclient.c:933708
void __cdecl _E86_45()
{
  char *v0; // esi@1

  v0 = &KW_CODE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D780) --------------------------------------------------------  // acclient.c:933721
void __cdecl _E89_55()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D7B0) --------------------------------------------------------  // acclient.c:933734
void __cdecl _E92_64()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D7E0) --------------------------------------------------------  // acclient.c:933747
void __cdecl sub_78D7E0()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D810) --------------------------------------------------------  // acclient.c:933760
void __cdecl sub_78D810()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D840) --------------------------------------------------------  // acclient.c:933773
void __cdecl sub_78D840()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D870) --------------------------------------------------------  // acclient.c:933786
void __cdecl sub_78D870()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D8A0) --------------------------------------------------------  // acclient.c:933799
void __cdecl sub_78D8A0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D8D0) --------------------------------------------------------  // acclient.c:933812
void __cdecl sub_78D8D0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D900) --------------------------------------------------------  // acclient.c:933825
void __cdecl _E113_88()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D930) --------------------------------------------------------  // acclient.c:933838
void __cdecl _E116_80()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D960) --------------------------------------------------------  // acclient.c:933851
void __cdecl sub_78D960()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D990) --------------------------------------------------------  // acclient.c:933864
void __cdecl sub_78D990()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D9C0) --------------------------------------------------------  // acclient.c:933877
void __cdecl _E125_83()
{
  char *v0; // esi@1

  v0 = &KW_FILE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D9F0) --------------------------------------------------------  // acclient.c:933890
void __cdecl _E128_81()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DA20) --------------------------------------------------------  // acclient.c:933903
void __cdecl _E131_70()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DA50) --------------------------------------------------------  // acclient.c:933916
void __cdecl _E134_54()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DA80) --------------------------------------------------------  // acclient.c:933929
void __cdecl _E137_53()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DAB0) --------------------------------------------------------  // acclient.c:933942
void __cdecl _E140_47()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DAE0) --------------------------------------------------------  // acclient.c:933955
void __cdecl _E143_47()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DB10) --------------------------------------------------------  // acclient.c:933968
void __cdecl _E146_47()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DB40) --------------------------------------------------------  // acclient.c:933981
void __cdecl _E149_46()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DB70) --------------------------------------------------------  // acclient.c:933994
void __cdecl _E152_47()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DBA0) --------------------------------------------------------  // acclient.c:934007
void __cdecl _E155_43()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DBD0) --------------------------------------------------------  // acclient.c:934020
void __cdecl _E158_44()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DC00) --------------------------------------------------------  // acclient.c:934033
void __cdecl _E161_41()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DC30) --------------------------------------------------------  // acclient.c:934046
void __cdecl _E164_43()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DC60) --------------------------------------------------------  // acclient.c:934059
void __cdecl _E167_39()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DC90) --------------------------------------------------------  // acclient.c:934072
void __cdecl _E170_39()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DCC0) --------------------------------------------------------  // acclient.c:934085
void __cdecl _E173_34()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DCF0) --------------------------------------------------------  // acclient.c:934098
void __cdecl _E176_36()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DD20) --------------------------------------------------------  // acclient.c:934111
void __cdecl _E179_35()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DD50) --------------------------------------------------------  // acclient.c:934124
void __cdecl _E182_35()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DD80) --------------------------------------------------------  // acclient.c:934137
void __cdecl _E185_32()
{
  char *v0; // esi@1

  v0 = &KW_STATE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DDB0) --------------------------------------------------------  // acclient.c:934150
void __cdecl _E188_33()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DDE0) --------------------------------------------------------  // acclient.c:934163
void __cdecl _E191_32()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DE10) --------------------------------------------------------  // acclient.c:934176
void __cdecl _E194_39()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DE40) --------------------------------------------------------  // acclient.c:934189
void __cdecl _E197_29()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DE70) --------------------------------------------------------  // acclient.c:934202
void __cdecl _E200_33()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DEA0) --------------------------------------------------------  // acclient.c:934215
void __cdecl _E203_32()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DED0) --------------------------------------------------------  // acclient.c:934228
void __cdecl _E206_36()
{
  char *v0; // esi@1

  v0 = &KW_X_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DF00) --------------------------------------------------------  // acclient.c:934241
void __cdecl _E209_30()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DF30) --------------------------------------------------------  // acclient.c:934254
void __cdecl _E212_33()
{
  char *v0; // esi@1

  v0 = &KW_Y_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DF60) --------------------------------------------------------  // acclient.c:934267
void __cdecl _E215_30()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DF90) --------------------------------------------------------  // acclient.c:934280
void __cdecl _E218_30()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DFC0) --------------------------------------------------------  // acclient.c:934293
void __cdecl _E221_30()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078DFF0) --------------------------------------------------------  // acclient.c:934306
void __cdecl _E224_30()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

