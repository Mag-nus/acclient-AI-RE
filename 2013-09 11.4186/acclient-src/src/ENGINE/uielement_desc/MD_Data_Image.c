/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Image
   Object     : ENGINE\uielement_desc\MD_Data_Image.obj
   Functions  : 105
   Addresses  : 0069CDD0 - 00789340 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069CDD0) --------------------------------------------------------  // acclient.c:693113
void __thiscall MD_Data_Image::MD_Data_Image(MD_Data_Image *this)
{
  MD_Data_Image *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 5u);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Image::vftable;
  v1->m_file.id = stru_8F9284.id;
  v1->m_drawMode = 1;
}
// 800F90: using guessed type int (__thiscall *MD_Data_Image::vftable)(void *, char);

//----- (0069CE10) --------------------------------------------------------  // acclient.c:693132
void __thiscall MD_Data_Image::MD_Data_Image(MD_Data_Image *this, MD_Data_Image *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Image::vftable;
  *(_DWORD *)(v2 + 8) = stru_8F9284.id;
  *(_DWORD *)(v2 + 12) = 1;
  if ( (MD_Data_Image *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_file.id;
    *(_DWORD *)(v2 + 12) = _rhs->m_drawMode;
  }
}
// 800F90: using guessed type int (__thiscall *MD_Data_Image::vftable)(void *, char);

//----- (0071C7A0) --------------------------------------------------------  // acclient.c:814677
int sub_71C7A0()
{
  KW_NULL_6.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_7889E0);
}

//----- (0071C7C0) --------------------------------------------------------  // acclient.c:814685
int sub_71C7C0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_2, "Base");
  return atexit(sub_788A10);
}

//----- (0071C7E0) --------------------------------------------------------  // acclient.c:814692
int _E79_98()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_2, "BottomEdge");
  return atexit(_E80_95);
}

//----- (0071C800) --------------------------------------------------------  // acclient.c:814699
int _E82_63()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_2, "Child");
  return atexit(_E83_59);
}

//----- (0071C820) --------------------------------------------------------  // acclient.c:814706
int _E85_46()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_2, "Code");
  return atexit(_E86_38);
}

//----- (0071C840) --------------------------------------------------------  // acclient.c:814713
int _E88_35()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_2, "DefaultState");
  return atexit(_E89_48);
}

//----- (0071C860) --------------------------------------------------------  // acclient.c:814720
int sub_71C860()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_2, "DisplayHeight");
  return atexit(_E92_57);
}

//----- (0071C880) --------------------------------------------------------  // acclient.c:814727
int _E94_48()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_2, "DisplayWidth");
  return atexit(sub_788B30);
}

//----- (0071C8A0) --------------------------------------------------------  // acclient.c:814734
int sub_71C8A0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_2, "DrawMode");
  return atexit(sub_788B60);
}

//----- (0071C8C0) --------------------------------------------------------  // acclient.c:814741
int sub_71C8C0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_2, "Duration");
  return atexit(sub_788B90);
}

//----- (0071C8E0) --------------------------------------------------------  // acclient.c:814748
int sub_71C8E0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_2, "Element");
  return atexit(sub_788BC0);
}

//----- (0071C900) --------------------------------------------------------  // acclient.c:814755
int sub_71C900()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_2, "ElementHeader");
  return atexit(sub_788BF0);
}

//----- (0071C920) --------------------------------------------------------  // acclient.c:814762
int _E109_96()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_2, "ElementWHeader");
  return atexit(sub_788C20);
}

//----- (0071C940) --------------------------------------------------------  // acclient.c:814769
int sub_71C940()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_2, "ElementID");
  return atexit(_E113_81);
}

//----- (0071C960) --------------------------------------------------------  // acclient.c:814776
int sub_71C960()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_2, "EndAlpha");
  return atexit(_E116_73);
}

//----- (0071C980) --------------------------------------------------------  // acclient.c:814783
int _E118_91()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_2, "EngineType");
  return atexit(_E119_96);
}

//----- (0071C9A0) --------------------------------------------------------  // acclient.c:814790
int _E121_82()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_2, "EventID");
  return atexit(sub_788CE0);
}

//----- (0071C9C0) --------------------------------------------------------  // acclient.c:814797
int _E124_82()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_2, "File");
  return atexit(_E125_76);
}

//----- (0071C9E0) --------------------------------------------------------  // acclient.c:814804
int _E127_69()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_2, "Frames");
  return atexit(_E128_74);
}

//----- (0071CA00) --------------------------------------------------------  // acclient.c:814811
int _E130_62()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_2, "PREPROC_HEADER");
  return atexit(_E131_63);
}

//----- (0071CA20) --------------------------------------------------------  // acclient.c:814818
int _E133_55()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_2, "Height");
  return atexit(_E134_47);
}

//----- (0071CA40) --------------------------------------------------------  // acclient.c:814825
int _E136_39()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_2, "JumpItemIndex");
  return atexit(_E137_46);
}

//----- (0071CA60) --------------------------------------------------------  // acclient.c:814832
int _E139_39()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_2, "LeftEdge");
  return atexit(_E140_40);
}

//----- (0071CA80) --------------------------------------------------------  // acclient.c:814839
int _E142_36()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_2, "MaxDuration");
  return atexit(_E143_40);
}

//----- (0071CAA0) --------------------------------------------------------  // acclient.c:814846
int _E145_38()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_2, "Media");
  return atexit(_E146_40);
}

//----- (0071CAC0) --------------------------------------------------------  // acclient.c:814853
int _E148_37()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_2, "MediaType");
  return atexit(_E149_39);
}

//----- (0071CAE0) --------------------------------------------------------  // acclient.c:814860
int _E151_35()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_2, "MinDuration");
  return atexit(_E152_40);
}

//----- (0071CB00) --------------------------------------------------------  // acclient.c:814867
int _E154_36()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_2, "NoDBFile");
  return atexit(_E155_36);
}

//----- (0071CB20) --------------------------------------------------------  // acclient.c:814874
int _E157_33()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_2, "StretchToFullScreen");
  return atexit(_E158_37);
}

//----- (0071CB40) --------------------------------------------------------  // acclient.c:814881
int _E160_36()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_2, "PassToChildren");
  return atexit(_E161_34);
}

//----- (0071CB60) --------------------------------------------------------  // acclient.c:814888
int _E163_29()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_2, "Probability");
  return atexit(_E164_36);
}

//----- (0071CB80) --------------------------------------------------------  // acclient.c:814895
int _E166_31()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_3, "Properties");
  return atexit(_E167_32);
}

//----- (0071CBA0) --------------------------------------------------------  // acclient.c:814902
int _E169_29()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_2, "Remove");
  return atexit(_E170_32);
}

//----- (0071CBC0) --------------------------------------------------------  // acclient.c:814909
int _E172_27()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_2, "RightEdge");
  return atexit(_E173_27);
}

//----- (0071CBE0) --------------------------------------------------------  // acclient.c:814916
int _E175_24()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_2, "SoundName");
  return atexit(_E176_29);
}

//----- (0071CC00) --------------------------------------------------------  // acclient.c:814923
int _E178_24()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_2, "SoundTable");
  return atexit(_E179_28);
}

//----- (0071CC20) --------------------------------------------------------  // acclient.c:814930
int _E181_24()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_2, "StartAlpha");
  return atexit(_E182_28);
}

//----- (0071CC40) --------------------------------------------------------  // acclient.c:814937
int _E184_22()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_2, "State");
  return atexit(_E185_25);
}

//----- (0071CC60) --------------------------------------------------------  // acclient.c:814944
int _E187_21()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_2, "StateHeader");
  return atexit(_E188_26);
}

//----- (0071CC80) --------------------------------------------------------  // acclient.c:814951
int _E190_22()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_2, "StateWHeader");
  return atexit(_E191_25);
}

//----- (0071CCA0) --------------------------------------------------------  // acclient.c:814958
int _E193_21()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_2, "StateID");
  return atexit(_E194_32);
}

//----- (0071CCC0) --------------------------------------------------------  // acclient.c:814965
int _E196_28()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_2, "TopEdge");
  return atexit(_E197_22);
}

//----- (0071CCE0) --------------------------------------------------------  // acclient.c:814972
int _E199_20()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_2, "Type");
  return atexit(_E200_26);
}

//----- (0071CD00) --------------------------------------------------------  // acclient.c:814979
int _E202_24()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_2, "Width");
  return atexit(_E203_25);
}

//----- (0071CD20) --------------------------------------------------------  // acclient.c:814986
int _E205_22()
{
  PStringBase<char>::PStringBase<char>(&KW_X_2, "X");
  return atexit(_E206_29);
}

//----- (0071CD40) --------------------------------------------------------  // acclient.c:814993
int _E208_26()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_2, "XHotspot");
  return atexit(_E209_23);
}

//----- (0071CD60) --------------------------------------------------------  // acclient.c:815000
int _E211_21()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_2, "Y");
  return atexit(_E212_26);
}

//----- (0071CD80) --------------------------------------------------------  // acclient.c:815007
int _E214_23()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_2, "YHotspot");
  return atexit(_E215_23);
}

//----- (0071CDA0) --------------------------------------------------------  // acclient.c:815014
int _E217_20()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_2, "ZLevel");
  return atexit(_E218_23);
}

//----- (0071CDC0) --------------------------------------------------------  // acclient.c:815021
int _E220_20()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_2, "Comments");
  return atexit(_E221_23);
}

//----- (0071CDE0) --------------------------------------------------------  // acclient.c:815028
int _E223_21()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_2, "HasAlpha");
  return atexit(_E224_23);
}

//----- (0071CE00) --------------------------------------------------------  // acclient.c:815035
int sub_71CE00()
{
  return atexit(nullsub_314);
}

//----- (007889E0) --------------------------------------------------------  // acclient.c:928352
void __cdecl sub_7889E0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788A10) --------------------------------------------------------  // acclient.c:928365
void __cdecl sub_788A10()
{
  char *v0; // esi@1

  v0 = &KW_BASE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788A40) --------------------------------------------------------  // acclient.c:928378
void __cdecl _E80_95()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788A70) --------------------------------------------------------  // acclient.c:928391
void __cdecl _E83_59()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788AA0) --------------------------------------------------------  // acclient.c:928404
void __cdecl _E86_38()
{
  char *v0; // esi@1

  v0 = &KW_CODE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788AD0) --------------------------------------------------------  // acclient.c:928417
void __cdecl _E89_48()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788B00) --------------------------------------------------------  // acclient.c:928430
void __cdecl _E92_57()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788B30) --------------------------------------------------------  // acclient.c:928443
void __cdecl sub_788B30()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788B60) --------------------------------------------------------  // acclient.c:928456
void __cdecl sub_788B60()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788B90) --------------------------------------------------------  // acclient.c:928469
void __cdecl sub_788B90()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788BC0) --------------------------------------------------------  // acclient.c:928482
void __cdecl sub_788BC0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788BF0) --------------------------------------------------------  // acclient.c:928495
void __cdecl sub_788BF0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788C20) --------------------------------------------------------  // acclient.c:928508
void __cdecl sub_788C20()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788C50) --------------------------------------------------------  // acclient.c:928521
void __cdecl _E113_81()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788C80) --------------------------------------------------------  // acclient.c:928534
void __cdecl _E116_73()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788CB0) --------------------------------------------------------  // acclient.c:928547
void __cdecl _E119_96()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788CE0) --------------------------------------------------------  // acclient.c:928560
void __cdecl sub_788CE0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788D10) --------------------------------------------------------  // acclient.c:928573
void __cdecl _E125_76()
{
  char *v0; // esi@1

  v0 = &KW_FILE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788D40) --------------------------------------------------------  // acclient.c:928586
void __cdecl _E128_74()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788D70) --------------------------------------------------------  // acclient.c:928599
void __cdecl _E131_63()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788DA0) --------------------------------------------------------  // acclient.c:928612
void __cdecl _E134_47()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788DD0) --------------------------------------------------------  // acclient.c:928625
void __cdecl _E137_46()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788E00) --------------------------------------------------------  // acclient.c:928638
void __cdecl _E140_40()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788E30) --------------------------------------------------------  // acclient.c:928651
void __cdecl _E143_40()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788E60) --------------------------------------------------------  // acclient.c:928664
void __cdecl _E146_40()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788E90) --------------------------------------------------------  // acclient.c:928677
void __cdecl _E149_39()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788EC0) --------------------------------------------------------  // acclient.c:928690
void __cdecl _E152_40()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788EF0) --------------------------------------------------------  // acclient.c:928703
void __cdecl _E155_36()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788F20) --------------------------------------------------------  // acclient.c:928716
void __cdecl _E158_37()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788F50) --------------------------------------------------------  // acclient.c:928729
void __cdecl _E161_34()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788F80) --------------------------------------------------------  // acclient.c:928742
void __cdecl _E164_36()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788FB0) --------------------------------------------------------  // acclient.c:928755
void __cdecl _E167_32()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788FE0) --------------------------------------------------------  // acclient.c:928768
void __cdecl _E170_32()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789010) --------------------------------------------------------  // acclient.c:928781
void __cdecl _E173_27()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789040) --------------------------------------------------------  // acclient.c:928794
void __cdecl _E176_29()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789070) --------------------------------------------------------  // acclient.c:928807
void __cdecl _E179_28()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007890A0) --------------------------------------------------------  // acclient.c:928820
void __cdecl _E182_28()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007890D0) --------------------------------------------------------  // acclient.c:928833
void __cdecl _E185_25()
{
  char *v0; // esi@1

  v0 = &KW_STATE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789100) --------------------------------------------------------  // acclient.c:928846
void __cdecl _E188_26()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789130) --------------------------------------------------------  // acclient.c:928859
void __cdecl _E191_25()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789160) --------------------------------------------------------  // acclient.c:928872
void __cdecl _E194_32()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789190) --------------------------------------------------------  // acclient.c:928885
void __cdecl _E197_22()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007891C0) --------------------------------------------------------  // acclient.c:928898
void __cdecl _E200_26()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007891F0) --------------------------------------------------------  // acclient.c:928911
void __cdecl _E203_25()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789220) --------------------------------------------------------  // acclient.c:928924
void __cdecl _E206_29()
{
  char *v0; // esi@1

  v0 = &KW_X_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789250) --------------------------------------------------------  // acclient.c:928937
void __cdecl _E209_23()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789280) --------------------------------------------------------  // acclient.c:928950
void __cdecl _E212_26()
{
  char *v0; // esi@1

  v0 = &KW_Y_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007892B0) --------------------------------------------------------  // acclient.c:928963
void __cdecl _E215_23()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007892E0) --------------------------------------------------------  // acclient.c:928976
void __cdecl _E218_23()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789310) --------------------------------------------------------  // acclient.c:928989
void __cdecl _E221_23()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789340) --------------------------------------------------------  // acclient.c:929002
void __cdecl _E224_23()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

