/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Alpha
   Object     : ENGINE\uielement_desc\MD_Data_Alpha.obj
   Functions  : 106
   Addresses  : 0069E9F0 - 0078F320 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069E9F0) --------------------------------------------------------  // acclient.c:694899
void __thiscall MD_Data_Alpha::MD_Data_Alpha(MD_Data_Alpha *this)
{
  MD_Data_Alpha *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 2u);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Alpha::vftable;
  v1->m_file.id = stru_8F9AEC.id;
}
// 801628: using guessed type int (__thiscall *MD_Data_Alpha::vftable)(void *, char);

//----- (0069EA10) --------------------------------------------------------  // acclient.c:694911
void __thiscall MD_Data_Alpha::MD_Data_Alpha(MD_Data_Alpha *this, MD_Data_Alpha *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Alpha::vftable;
  *(_DWORD *)(v2 + 8) = stru_8F9AEC.id;
  if ( (MD_Data_Alpha *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_file.id;
  }
}
// 801628: using guessed type int (__thiscall *MD_Data_Alpha::vftable)(void *, char);

//----- (0069EA50) --------------------------------------------------------  // acclient.c:694928
void __thiscall MD_Data_Alpha::Serialize(MD_Data_Alpha *this, Archive *io_archive)
{
  MD_Data_Alpha *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_file.id;
    else
      v2->m_file.id = *(_DWORD *)v3;
  }
}

//----- (007207B0) --------------------------------------------------------  // acclient.c:818287
int sub_7207B0()
{
  KW_NULL_16.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78E9C0);
}

//----- (007207D0) --------------------------------------------------------  // acclient.c:818295
int sub_7207D0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_12, "Base");
  return atexit(sub_78E9F0);
}

//----- (007207F0) --------------------------------------------------------  // acclient.c:818302
int sub_7207F0()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_12, "BottomEdge");
  return atexit(sub_78EA20);
}

//----- (00720810) --------------------------------------------------------  // acclient.c:818309
int _E82_72()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_12, "Child");
  return atexit(_E83_68);
}

//----- (00720830) --------------------------------------------------------  // acclient.c:818316
int _E85_55()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_12, "Code");
  return atexit(_E86_47);
}

//----- (00720850) --------------------------------------------------------  // acclient.c:818323
int _E88_44()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_12, "DefaultState");
  return atexit(_E89_57);
}

//----- (00720870) --------------------------------------------------------  // acclient.c:818330
int sub_720870()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_12, "DisplayHeight");
  return atexit(_E92_66);
}

//----- (00720890) --------------------------------------------------------  // acclient.c:818337
int _E94_57()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_12, "DisplayWidth");
  return atexit(sub_78EB10);
}

//----- (007208B0) --------------------------------------------------------  // acclient.c:818344
int sub_7208B0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_12, "DrawMode");
  return atexit(sub_78EB40);
}

//----- (007208D0) --------------------------------------------------------  // acclient.c:818351
int sub_7208D0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_12, "Duration");
  return atexit(sub_78EB70);
}

//----- (007208F0) --------------------------------------------------------  // acclient.c:818358
int sub_7208F0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_12, "Element");
  return atexit(sub_78EBA0);
}

//----- (00720910) --------------------------------------------------------  // acclient.c:818365
int sub_720910()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_12, "ElementHeader");
  return atexit(sub_78EBD0);
}

//----- (00720930) --------------------------------------------------------  // acclient.c:818372
int sub_720930()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_12, "ElementWHeader");
  return atexit(sub_78EC00);
}

//----- (00720950) --------------------------------------------------------  // acclient.c:818379
int sub_720950()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_12, "ElementID");
  return atexit(_E113_90);
}

//----- (00720970) --------------------------------------------------------  // acclient.c:818386
int sub_720970()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_12, "EndAlpha");
  return atexit(_E116_82);
}

//----- (00720990) --------------------------------------------------------  // acclient.c:818393
int sub_720990()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_12, "EngineType");
  return atexit(sub_78EC90);
}

//----- (007209B0) --------------------------------------------------------  // acclient.c:818400
int _E121_91()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_12, "EventID");
  return atexit(sub_78ECC0);
}

//----- (007209D0) --------------------------------------------------------  // acclient.c:818407
int _E124_91()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_12, "File");
  return atexit(_E125_85);
}

//----- (007209F0) --------------------------------------------------------  // acclient.c:818414
int _E127_78()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_12, "Frames");
  return atexit(_E128_83);
}

//----- (00720A10) --------------------------------------------------------  // acclient.c:818421
int _E130_71()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_12, "PREPROC_HEADER");
  return atexit(_E131_72);
}

//----- (00720A30) --------------------------------------------------------  // acclient.c:818428
int _E133_64()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_12, "Height");
  return atexit(_E134_56);
}

//----- (00720A50) --------------------------------------------------------  // acclient.c:818435
int _E136_48()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_12, "JumpItemIndex");
  return atexit(_E137_55);
}

//----- (00720A70) --------------------------------------------------------  // acclient.c:818442
int _E139_48()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_12, "LeftEdge");
  return atexit(_E140_49);
}

//----- (00720A90) --------------------------------------------------------  // acclient.c:818449
int _E142_45()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_12, "MaxDuration");
  return atexit(_E143_49);
}

//----- (00720AB0) --------------------------------------------------------  // acclient.c:818456
int _E145_47()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_12, "Media");
  return atexit(_E146_49);
}

//----- (00720AD0) --------------------------------------------------------  // acclient.c:818463
int _E148_46()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_12, "MediaType");
  return atexit(_E149_48);
}

//----- (00720AF0) --------------------------------------------------------  // acclient.c:818470
int _E151_44()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_12, "MinDuration");
  return atexit(_E152_49);
}

//----- (00720B10) --------------------------------------------------------  // acclient.c:818477
int _E154_45()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_12, "NoDBFile");
  return atexit(_E155_45);
}

//----- (00720B30) --------------------------------------------------------  // acclient.c:818484
int _E157_42()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_12, "StretchToFullScreen");
  return atexit(_E158_46);
}

//----- (00720B50) --------------------------------------------------------  // acclient.c:818491
int _E160_45()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_12, "PassToChildren");
  return atexit(_E161_43);
}

//----- (00720B70) --------------------------------------------------------  // acclient.c:818498
int _E163_38()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_12, "Probability");
  return atexit(_E164_45);
}

//----- (00720B90) --------------------------------------------------------  // acclient.c:818505
int _E166_40()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_13, "Properties");
  return atexit(_E167_41);
}

//----- (00720BB0) --------------------------------------------------------  // acclient.c:818512
int _E169_38()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_12, "Remove");
  return atexit(_E170_41);
}

//----- (00720BD0) --------------------------------------------------------  // acclient.c:818519
int _E172_36()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_12, "RightEdge");
  return atexit(_E173_36);
}

//----- (00720BF0) --------------------------------------------------------  // acclient.c:818526
int _E175_33()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_12, "SoundName");
  return atexit(_E176_38);
}

//----- (00720C10) --------------------------------------------------------  // acclient.c:818533
int _E178_33()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_12, "SoundTable");
  return atexit(_E179_37);
}

//----- (00720C30) --------------------------------------------------------  // acclient.c:818540
int _E181_33()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_12, "StartAlpha");
  return atexit(_E182_37);
}

//----- (00720C50) --------------------------------------------------------  // acclient.c:818547
int _E184_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_12, "State");
  return atexit(_E185_34);
}

//----- (00720C70) --------------------------------------------------------  // acclient.c:818554
int _E187_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_12, "StateHeader");
  return atexit(_E188_35);
}

//----- (00720C90) --------------------------------------------------------  // acclient.c:818561
int _E190_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_12, "StateWHeader");
  return atexit(_E191_34);
}

//----- (00720CB0) --------------------------------------------------------  // acclient.c:818568
int _E193_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_12, "StateID");
  return atexit(_E194_41);
}

//----- (00720CD0) --------------------------------------------------------  // acclient.c:818575
int _E196_37()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_12, "TopEdge");
  return atexit(_E197_31);
}

//----- (00720CF0) --------------------------------------------------------  // acclient.c:818582
int _E199_29()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_12, "Type");
  return atexit(_E200_35);
}

//----- (00720D10) --------------------------------------------------------  // acclient.c:818589
int _E202_33()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_12, "Width");
  return atexit(_E203_34);
}

//----- (00720D30) --------------------------------------------------------  // acclient.c:818596
int _E205_31()
{
  PStringBase<char>::PStringBase<char>(&KW_X_12, "X");
  return atexit(_E206_38);
}

//----- (00720D50) --------------------------------------------------------  // acclient.c:818603
int _E208_35()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_12, "XHotspot");
  return atexit(_E209_32);
}

//----- (00720D70) --------------------------------------------------------  // acclient.c:818610
int _E211_30()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_12, "Y");
  return atexit(_E212_35);
}

//----- (00720D90) --------------------------------------------------------  // acclient.c:818617
int _E214_32()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_12, "YHotspot");
  return atexit(_E215_32);
}

//----- (00720DB0) --------------------------------------------------------  // acclient.c:818624
int _E217_29()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_12, "ZLevel");
  return atexit(_E218_32);
}

//----- (00720DD0) --------------------------------------------------------  // acclient.c:818631
int _E220_29()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_12, "Comments");
  return atexit(_E221_32);
}

//----- (00720DF0) --------------------------------------------------------  // acclient.c:818638
int _E223_30()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_12, "HasAlpha");
  return atexit(_E224_32);
}

//----- (00720E10) --------------------------------------------------------  // acclient.c:818645
int sub_720E10()
{
  return atexit(nullsub_312);
}

//----- (0078E9C0) --------------------------------------------------------  // acclient.c:934982
void __cdecl sub_78E9C0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E9F0) --------------------------------------------------------  // acclient.c:934995
void __cdecl sub_78E9F0()
{
  char *v0; // esi@1

  v0 = &KW_BASE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EA20) --------------------------------------------------------  // acclient.c:935008
void __cdecl sub_78EA20()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EA50) --------------------------------------------------------  // acclient.c:935021
void __cdecl _E83_68()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EA80) --------------------------------------------------------  // acclient.c:935034
void __cdecl _E86_47()
{
  char *v0; // esi@1

  v0 = &KW_CODE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EAB0) --------------------------------------------------------  // acclient.c:935047
void __cdecl _E89_57()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EAE0) --------------------------------------------------------  // acclient.c:935060
void __cdecl _E92_66()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EB10) --------------------------------------------------------  // acclient.c:935073
void __cdecl sub_78EB10()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EB40) --------------------------------------------------------  // acclient.c:935086
void __cdecl sub_78EB40()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EB70) --------------------------------------------------------  // acclient.c:935099
void __cdecl sub_78EB70()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EBA0) --------------------------------------------------------  // acclient.c:935112
void __cdecl sub_78EBA0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EBD0) --------------------------------------------------------  // acclient.c:935125
void __cdecl sub_78EBD0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EC00) --------------------------------------------------------  // acclient.c:935138
void __cdecl sub_78EC00()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EC30) --------------------------------------------------------  // acclient.c:935151
void __cdecl _E113_90()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EC60) --------------------------------------------------------  // acclient.c:935164
void __cdecl _E116_82()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EC90) --------------------------------------------------------  // acclient.c:935177
void __cdecl sub_78EC90()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ECC0) --------------------------------------------------------  // acclient.c:935190
void __cdecl sub_78ECC0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ECF0) --------------------------------------------------------  // acclient.c:935203
void __cdecl _E125_85()
{
  char *v0; // esi@1

  v0 = &KW_FILE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ED20) --------------------------------------------------------  // acclient.c:935216
void __cdecl _E128_83()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ED50) --------------------------------------------------------  // acclient.c:935229
void __cdecl _E131_72()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078ED80) --------------------------------------------------------  // acclient.c:935242
void __cdecl _E134_56()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EDB0) --------------------------------------------------------  // acclient.c:935255
void __cdecl _E137_55()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EDE0) --------------------------------------------------------  // acclient.c:935268
void __cdecl _E140_49()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EE10) --------------------------------------------------------  // acclient.c:935281
void __cdecl _E143_49()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EE40) --------------------------------------------------------  // acclient.c:935294
void __cdecl _E146_49()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EE70) --------------------------------------------------------  // acclient.c:935307
void __cdecl _E149_48()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EEA0) --------------------------------------------------------  // acclient.c:935320
void __cdecl _E152_49()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EED0) --------------------------------------------------------  // acclient.c:935333
void __cdecl _E155_45()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EF00) --------------------------------------------------------  // acclient.c:935346
void __cdecl _E158_46()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EF30) --------------------------------------------------------  // acclient.c:935359
void __cdecl _E161_43()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EF60) --------------------------------------------------------  // acclient.c:935372
void __cdecl _E164_45()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EF90) --------------------------------------------------------  // acclient.c:935385
void __cdecl _E167_41()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EFC0) --------------------------------------------------------  // acclient.c:935398
void __cdecl _E170_41()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078EFF0) --------------------------------------------------------  // acclient.c:935411
void __cdecl _E173_36()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F020) --------------------------------------------------------  // acclient.c:935424
void __cdecl _E176_38()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F050) --------------------------------------------------------  // acclient.c:935437
void __cdecl _E179_37()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F080) --------------------------------------------------------  // acclient.c:935450
void __cdecl _E182_37()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F0B0) --------------------------------------------------------  // acclient.c:935463
void __cdecl _E185_34()
{
  char *v0; // esi@1

  v0 = &KW_STATE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F0E0) --------------------------------------------------------  // acclient.c:935476
void __cdecl _E188_35()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F110) --------------------------------------------------------  // acclient.c:935489
void __cdecl _E191_34()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F140) --------------------------------------------------------  // acclient.c:935502
void __cdecl _E194_41()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F170) --------------------------------------------------------  // acclient.c:935515
void __cdecl _E197_31()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F1A0) --------------------------------------------------------  // acclient.c:935528
void __cdecl _E200_35()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F1D0) --------------------------------------------------------  // acclient.c:935541
void __cdecl _E203_34()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F200) --------------------------------------------------------  // acclient.c:935554
void __cdecl _E206_38()
{
  char *v0; // esi@1

  v0 = &KW_X_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F230) --------------------------------------------------------  // acclient.c:935567
void __cdecl _E209_32()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F260) --------------------------------------------------------  // acclient.c:935580
void __cdecl _E212_35()
{
  char *v0; // esi@1

  v0 = &KW_Y_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F290) --------------------------------------------------------  // acclient.c:935593
void __cdecl _E215_32()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F2C0) --------------------------------------------------------  // acclient.c:935606
void __cdecl _E218_32()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F2F0) --------------------------------------------------------  // acclient.c:935619
void __cdecl _E221_32()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F320) --------------------------------------------------------  // acclient.c:935632
void __cdecl _E224_32()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

