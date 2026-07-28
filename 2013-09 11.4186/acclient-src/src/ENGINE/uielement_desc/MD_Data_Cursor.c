/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Cursor
   Object     : ENGINE\uielement_desc\MD_Data_Cursor.obj
   Functions  : 105
   Addresses  : 0069D8A0 - 0078B010 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069D8A0) --------------------------------------------------------  // acclient.c:693834
void __thiscall MD_Data_Cursor::MD_Data_Cursor(MD_Data_Cursor *this)
{
  MD_Data_Cursor *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 4u);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Cursor::vftable;
  v1->m_file.id = stru_8F9540.id;
  v1->m_xHotspot = 0;
  v1->m_yHotspot = 0;
}
// 8011C0: using guessed type int (__thiscall *MD_Data_Cursor::vftable)(void *, char);

//----- (0069D8D0) --------------------------------------------------------  // acclient.c:693848
void __thiscall MD_Data_Cursor::MD_Data_Cursor(MD_Data_Cursor *this, MD_Data_Cursor *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Cursor::vftable;
  *(_DWORD *)(v2 + 8) = stru_8F9540.id;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  if ( (MD_Data_Cursor *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_file.id;
    *(_DWORD *)(v2 + 12) = _rhs->m_xHotspot;
    *(_DWORD *)(v2 + 16) = _rhs->m_yHotspot;
  }
}
// 8011C0: using guessed type int (__thiscall *MD_Data_Cursor::vftable)(void *, char);

//----- (0071DAF0) --------------------------------------------------------  // acclient.c:815769
int sub_71DAF0()
{
  KW_NULL_9.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78A6B0);
}

//----- (0071DB10) --------------------------------------------------------  // acclient.c:815777
int sub_71DB10()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_5, "Base");
  return atexit(sub_78A6E0);
}

//----- (0071DB30) --------------------------------------------------------  // acclient.c:815784
int sub_71DB30()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_5, "BottomEdge");
  return atexit(_E80_97);
}

//----- (0071DB50) --------------------------------------------------------  // acclient.c:815791
int _E82_65()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_5, "Child");
  return atexit(_E83_61);
}

//----- (0071DB70) --------------------------------------------------------  // acclient.c:815798
int _E85_48()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_5, "Code");
  return atexit(_E86_40);
}

//----- (0071DB90) --------------------------------------------------------  // acclient.c:815805
int _E88_37()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_5, "DefaultState");
  return atexit(_E89_50);
}

//----- (0071DBB0) --------------------------------------------------------  // acclient.c:815812
int sub_71DBB0()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_5, "DisplayHeight");
  return atexit(_E92_59);
}

//----- (0071DBD0) --------------------------------------------------------  // acclient.c:815819
int _E94_50()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_5, "DisplayWidth");
  return atexit(sub_78A800);
}

//----- (0071DBF0) --------------------------------------------------------  // acclient.c:815826
int sub_71DBF0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_5, "DrawMode");
  return atexit(sub_78A830);
}

//----- (0071DC10) --------------------------------------------------------  // acclient.c:815833
int sub_71DC10()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_5, "Duration");
  return atexit(sub_78A860);
}

//----- (0071DC30) --------------------------------------------------------  // acclient.c:815840
int sub_71DC30()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_5, "Element");
  return atexit(sub_78A890);
}

//----- (0071DC50) --------------------------------------------------------  // acclient.c:815847
int sub_71DC50()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_5, "ElementHeader");
  return atexit(sub_78A8C0);
}

//----- (0071DC70) --------------------------------------------------------  // acclient.c:815854
int _E109_98()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_5, "ElementWHeader");
  return atexit(sub_78A8F0);
}

//----- (0071DC90) --------------------------------------------------------  // acclient.c:815861
int sub_71DC90()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_5, "ElementID");
  return atexit(_E113_83);
}

//----- (0071DCB0) --------------------------------------------------------  // acclient.c:815868
int sub_71DCB0()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_5, "EndAlpha");
  return atexit(_E116_75);
}

//----- (0071DCD0) --------------------------------------------------------  // acclient.c:815875
int _E118_93()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_5, "EngineType");
  return atexit(_E119_98);
}

//----- (0071DCF0) --------------------------------------------------------  // acclient.c:815882
int _E121_84()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_5, "EventID");
  return atexit(sub_78A9B0);
}

//----- (0071DD10) --------------------------------------------------------  // acclient.c:815889
int _E124_84()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_5, "File");
  return atexit(_E125_78);
}

//----- (0071DD30) --------------------------------------------------------  // acclient.c:815896
int _E127_71()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_5, "Frames");
  return atexit(_E128_76);
}

//----- (0071DD50) --------------------------------------------------------  // acclient.c:815903
int _E130_64()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_5, "PREPROC_HEADER");
  return atexit(_E131_65);
}

//----- (0071DD70) --------------------------------------------------------  // acclient.c:815910
int _E133_57()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_5, "Height");
  return atexit(_E134_49);
}

//----- (0071DD90) --------------------------------------------------------  // acclient.c:815917
int _E136_41()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_5, "JumpItemIndex");
  return atexit(_E137_48);
}

//----- (0071DDB0) --------------------------------------------------------  // acclient.c:815924
int _E139_41()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_5, "LeftEdge");
  return atexit(_E140_42);
}

//----- (0071DDD0) --------------------------------------------------------  // acclient.c:815931
int _E142_38()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_5, "MaxDuration");
  return atexit(_E143_42);
}

//----- (0071DDF0) --------------------------------------------------------  // acclient.c:815938
int _E145_40()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_5, "Media");
  return atexit(_E146_42);
}

//----- (0071DE10) --------------------------------------------------------  // acclient.c:815945
int _E148_39()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_5, "MediaType");
  return atexit(_E149_41);
}

//----- (0071DE30) --------------------------------------------------------  // acclient.c:815952
int _E151_37()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_5, "MinDuration");
  return atexit(_E152_42);
}

//----- (0071DE50) --------------------------------------------------------  // acclient.c:815959
int _E154_38()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_5, "NoDBFile");
  return atexit(_E155_38);
}

//----- (0071DE70) --------------------------------------------------------  // acclient.c:815966
int _E157_35()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_5, "StretchToFullScreen");
  return atexit(_E158_39);
}

//----- (0071DE90) --------------------------------------------------------  // acclient.c:815973
int _E160_38()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_5, "PassToChildren");
  return atexit(_E161_36);
}

//----- (0071DEB0) --------------------------------------------------------  // acclient.c:815980
int _E163_31()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_5, "Probability");
  return atexit(_E164_38);
}

//----- (0071DED0) --------------------------------------------------------  // acclient.c:815987
int _E166_33()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_6, "Properties");
  return atexit(_E167_34);
}

//----- (0071DEF0) --------------------------------------------------------  // acclient.c:815994
int _E169_31()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_5, "Remove");
  return atexit(_E170_34);
}

//----- (0071DF10) --------------------------------------------------------  // acclient.c:816001
int _E172_29()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_5, "RightEdge");
  return atexit(_E173_29);
}

//----- (0071DF30) --------------------------------------------------------  // acclient.c:816008
int _E175_26()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_5, "SoundName");
  return atexit(_E176_31);
}

//----- (0071DF50) --------------------------------------------------------  // acclient.c:816015
int _E178_26()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_5, "SoundTable");
  return atexit(_E179_30);
}

//----- (0071DF70) --------------------------------------------------------  // acclient.c:816022
int _E181_26()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_5, "StartAlpha");
  return atexit(_E182_30);
}

//----- (0071DF90) --------------------------------------------------------  // acclient.c:816029
int _E184_24()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_5, "State");
  return atexit(_E185_27);
}

//----- (0071DFB0) --------------------------------------------------------  // acclient.c:816036
int _E187_23()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_5, "StateHeader");
  return atexit(_E188_28);
}

//----- (0071DFD0) --------------------------------------------------------  // acclient.c:816043
int _E190_24()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_5, "StateWHeader");
  return atexit(_E191_27);
}

//----- (0071DFF0) --------------------------------------------------------  // acclient.c:816050
int _E193_23()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_5, "StateID");
  return atexit(_E194_34);
}

//----- (0071E010) --------------------------------------------------------  // acclient.c:816057
int _E196_30()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_5, "TopEdge");
  return atexit(_E197_24);
}

//----- (0071E030) --------------------------------------------------------  // acclient.c:816064
int _E199_22()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_5, "Type");
  return atexit(_E200_28);
}

//----- (0071E050) --------------------------------------------------------  // acclient.c:816071
int _E202_26()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_5, "Width");
  return atexit(_E203_27);
}

//----- (0071E070) --------------------------------------------------------  // acclient.c:816078
int _E205_24()
{
  PStringBase<char>::PStringBase<char>(&KW_X_5, "X");
  return atexit(_E206_31);
}

//----- (0071E090) --------------------------------------------------------  // acclient.c:816085
int _E208_28()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_5, "XHotspot");
  return atexit(_E209_25);
}

//----- (0071E0B0) --------------------------------------------------------  // acclient.c:816092
int _E211_23()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_5, "Y");
  return atexit(_E212_28);
}

//----- (0071E0D0) --------------------------------------------------------  // acclient.c:816099
int _E214_25()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_5, "YHotspot");
  return atexit(_E215_25);
}

//----- (0071E0F0) --------------------------------------------------------  // acclient.c:816106
int _E217_22()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_5, "ZLevel");
  return atexit(_E218_25);
}

//----- (0071E110) --------------------------------------------------------  // acclient.c:816113
int _E220_22()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_5, "Comments");
  return atexit(_E221_25);
}

//----- (0071E130) --------------------------------------------------------  // acclient.c:816120
int _E223_23()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_5, "HasAlpha");
  return atexit(_E224_25);
}

//----- (0071E150) --------------------------------------------------------  // acclient.c:816127
int sub_71E150()
{
  return atexit(nullsub_313);
}

//----- (0078A6B0) --------------------------------------------------------  // acclient.c:930341
void __cdecl sub_78A6B0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A6E0) --------------------------------------------------------  // acclient.c:930354
void __cdecl sub_78A6E0()
{
  char *v0; // esi@1

  v0 = &KW_BASE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A710) --------------------------------------------------------  // acclient.c:930367
void __cdecl _E80_97()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A740) --------------------------------------------------------  // acclient.c:930380
void __cdecl _E83_61()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A770) --------------------------------------------------------  // acclient.c:930393
void __cdecl _E86_40()
{
  char *v0; // esi@1

  v0 = &KW_CODE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A7A0) --------------------------------------------------------  // acclient.c:930406
void __cdecl _E89_50()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A7D0) --------------------------------------------------------  // acclient.c:930419
void __cdecl _E92_59()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A800) --------------------------------------------------------  // acclient.c:930432
void __cdecl sub_78A800()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A830) --------------------------------------------------------  // acclient.c:930445
void __cdecl sub_78A830()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A860) --------------------------------------------------------  // acclient.c:930458
void __cdecl sub_78A860()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A890) --------------------------------------------------------  // acclient.c:930471
void __cdecl sub_78A890()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A8C0) --------------------------------------------------------  // acclient.c:930484
void __cdecl sub_78A8C0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A8F0) --------------------------------------------------------  // acclient.c:930497
void __cdecl sub_78A8F0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A920) --------------------------------------------------------  // acclient.c:930510
void __cdecl _E113_83()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A950) --------------------------------------------------------  // acclient.c:930523
void __cdecl _E116_75()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A980) --------------------------------------------------------  // acclient.c:930536
void __cdecl _E119_98()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A9B0) --------------------------------------------------------  // acclient.c:930549
void __cdecl sub_78A9B0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A9E0) --------------------------------------------------------  // acclient.c:930562
void __cdecl _E125_78()
{
  char *v0; // esi@1

  v0 = &KW_FILE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AA10) --------------------------------------------------------  // acclient.c:930575
void __cdecl _E128_76()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AA40) --------------------------------------------------------  // acclient.c:930588
void __cdecl _E131_65()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AA70) --------------------------------------------------------  // acclient.c:930601
void __cdecl _E134_49()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AAA0) --------------------------------------------------------  // acclient.c:930614
void __cdecl _E137_48()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AAD0) --------------------------------------------------------  // acclient.c:930627
void __cdecl _E140_42()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AB00) --------------------------------------------------------  // acclient.c:930640
void __cdecl _E143_42()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AB30) --------------------------------------------------------  // acclient.c:930653
void __cdecl _E146_42()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AB60) --------------------------------------------------------  // acclient.c:930666
void __cdecl _E149_41()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AB90) --------------------------------------------------------  // acclient.c:930679
void __cdecl _E152_42()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ABC0) --------------------------------------------------------  // acclient.c:930692
void __cdecl _E155_38()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ABF0) --------------------------------------------------------  // acclient.c:930705
void __cdecl _E158_39()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AC20) --------------------------------------------------------  // acclient.c:930718
void __cdecl _E161_36()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AC50) --------------------------------------------------------  // acclient.c:930731
void __cdecl _E164_38()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AC80) --------------------------------------------------------  // acclient.c:930744
void __cdecl _E167_34()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ACB0) --------------------------------------------------------  // acclient.c:930757
void __cdecl _E170_34()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ACE0) --------------------------------------------------------  // acclient.c:930770
void __cdecl _E173_29()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AD10) --------------------------------------------------------  // acclient.c:930783
void __cdecl _E176_31()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AD40) --------------------------------------------------------  // acclient.c:930796
void __cdecl _E179_30()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AD70) --------------------------------------------------------  // acclient.c:930809
void __cdecl _E182_30()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ADA0) --------------------------------------------------------  // acclient.c:930822
void __cdecl _E185_27()
{
  char *v0; // esi@1

  v0 = &KW_STATE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ADD0) --------------------------------------------------------  // acclient.c:930835
void __cdecl _E188_28()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AE00) --------------------------------------------------------  // acclient.c:930848
void __cdecl _E191_27()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AE30) --------------------------------------------------------  // acclient.c:930861
void __cdecl _E194_34()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AE60) --------------------------------------------------------  // acclient.c:930874
void __cdecl _E197_24()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AE90) --------------------------------------------------------  // acclient.c:930887
void __cdecl _E200_28()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AEC0) --------------------------------------------------------  // acclient.c:930900
void __cdecl _E203_27()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AEF0) --------------------------------------------------------  // acclient.c:930913
void __cdecl _E206_31()
{
  char *v0; // esi@1

  v0 = &KW_X_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AF20) --------------------------------------------------------  // acclient.c:930926
void __cdecl _E209_25()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AF50) --------------------------------------------------------  // acclient.c:930939
void __cdecl _E212_28()
{
  char *v0; // esi@1

  v0 = &KW_Y_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AF80) --------------------------------------------------------  // acclient.c:930952
void __cdecl _E215_25()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AFB0) --------------------------------------------------------  // acclient.c:930965
void __cdecl _E218_25()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078AFE0) --------------------------------------------------------  // acclient.c:930978
void __cdecl _E221_25()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B010) --------------------------------------------------------  // acclient.c:930991
void __cdecl _E224_25()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

