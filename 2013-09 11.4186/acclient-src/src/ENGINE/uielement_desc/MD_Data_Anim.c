/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Anim
   Object     : ENGINE\uielement_desc\MD_Data_Anim.obj
   Functions  : 109
   Addresses  : 0069EAF0 - 0078FCB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069EAF0) --------------------------------------------------------  // acclient.c:694972
void __thiscall MD_Data_Anim::GetSubDataIDs(MD_Data_Anim *this, QualifiedDataIDArray *_id_array)
{
  MD_Data_Anim *v2; // esi@1

  v2 = this;
  gmNoticeHandler::RecvNotice_UpdateRentPayment((PlayerModule *)this, (PlayerOption)_id_array);
  QualifiedDataIDArray::CopyDIDs(_id_array, &v2->m_frames, 0);
}

//----- (0069EB20) --------------------------------------------------------  // acclient.c:694988
void __thiscall MD_Data_Anim::MD_Data_Anim(MD_Data_Anim *this)
{
  MD_Data_Anim *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 3u);
  LODWORD(v1->m_duration) = 0;
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Anim::vftable;
  v1->m_drawMode = 1;
  v1->m_frames.m_data = 0;
  v1->m_frames.m_sizeAndDeallocate = 0;
  v1->m_frames.m_num = 0;
  v1->m_StartTime = dbl_801698;
  v1->m_displayedFrameNum = -1;
}
// 8016A0: using guessed type int (__thiscall *MD_Data_Anim::vftable)(void *, char);

//----- (0069EB70) --------------------------------------------------------  // acclient.c:695006
double __thiscall MD_Data_Anim::GetDuration(MD_Data_Anim *this)
{
  return this->m_duration;
}

//----- (0069EB80) --------------------------------------------------------  // acclient.c:695012
void __thiscall SmartArray<IDClass<_tagDataID,32,0>,1>::Serialize(SmartArray<IDClass<_tagDataID,32,0>,1> *this, Archive *io_rcArchive)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v2; // edi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@9
  int v6; // ebp@10
  unsigned int v7; // eax@10

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
    SmartArray<IDClass<_tagDataID,32,0>,1>::SetNElements(v2, v3, 1);
  }
  v5 = 0;
  if ( v2->m_num )
  {
    do
    {
      v6 = (int)&v2->m_data[v5];
      Archive::CheckAlignment(io_rcArchive, 4u);
      v7 = Archive::GetBytes(io_rcArchive, 4u);
      if ( v7 )
      {
        if ( io_rcArchive->m_flags & 1 )
          *(_DWORD *)v7 = *(_DWORD *)v6;
        else
          *(_DWORD *)v6 = *(_DWORD *)v7;
      }
      ++v5;
    }
    while ( v5 < v2->m_num );
  }
}

//----- (0069EC30) --------------------------------------------------------  // acclient.c:695064
MediaDesc *__thiscall MD_Data_Anim::scalar_deleting_destructor(MD_Data_Anim *this, unsigned int a2)
{
  MediaDesc *v2; // esi@1

  v2 = (MediaDesc *)this;
  SmartArray<IDClass<_tagDataID,32,0>,1>::~SmartArray<IDClass<_tagDataID,32,0>,1>(&this->m_frames);
  MediaDesc::~MediaDesc(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0069EC60) --------------------------------------------------------  // acclient.c:695077
void __thiscall MD_Data_Anim::MD_Data_Anim(MD_Data_Anim *this, MD_Data_Anim *_rhs)
{
  int v2; // esi@1
  int v3; // edi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)(v2 + 8) = 0;
  v3 = v2 + 16;
  *(_DWORD *)v2 = &MD_Data_Anim::vftable;
  *(_DWORD *)(v2 + 12) = 1;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_QWORD *)(v2 + 32) = *(_QWORD *)&dbl_801698;
  *(_DWORD *)(v2 + 40) = -1;
  if ( (MD_Data_Anim *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = LODWORD(_rhs->m_duration);
    *(_DWORD *)(v2 + 12) = _rhs->m_drawMode;
    SmartArray<IDClass<_tagDataID,32,0>,1>::operator=(
      (SmartArray<IDClass<_tagDataID,32,0>,1> *)(v2 + 16),
      (int)&_rhs->m_frames);
  }
}
// 8016A0: using guessed type int (__thiscall *MD_Data_Anim::vftable)(void *, char);

//----- (0069ECD0) --------------------------------------------------------  // acclient.c:695106
void __thiscall MD_Data_Anim::Serialize(MD_Data_Anim *this, Archive *_io_archive)
{
  MD_Data_Anim *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, _io_archive);
  Archive::CheckAlignment(_io_archive, 4u);
  v3 = Archive::GetBytes(_io_archive, 4u);
  if ( v3 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v3 = LODWORD(v2->m_duration);
    else
      LODWORD(v2->m_duration) = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(_io_archive, 4u);
  v4 = Archive::GetBytes(_io_archive, 4u);
  if ( v4 )
  {
    if ( _io_archive->m_flags & 1 )
    {
      *(_DWORD *)v4 = v2->m_drawMode;
      SmartArray<IDClass<_tagDataID,32,0>,1>::Serialize(&v2->m_frames, _io_archive);
      return;
    }
    v2->m_drawMode = *(_DWORD *)v4;
  }
  SmartArray<IDClass<_tagDataID,32,0>,1>::Serialize(&v2->m_frames, _io_archive);
}

//----- (00720E20) --------------------------------------------------------  // acclient.c:818651
int sub_720E20()
{
  KW_NULL_17.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78F350);
}

//----- (00720E40) --------------------------------------------------------  // acclient.c:818659
int sub_720E40()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_13, "Base");
  return atexit(sub_78F380);
}

//----- (00720E60) --------------------------------------------------------  // acclient.c:818666
int sub_720E60()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_13, "BottomEdge");
  return atexit(sub_78F3B0);
}

//----- (00720E80) --------------------------------------------------------  // acclient.c:818673
int _E82_73()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_13, "Child");
  return atexit(_E83_69);
}

//----- (00720EA0) --------------------------------------------------------  // acclient.c:818680
int _E85_56()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_13, "Code");
  return atexit(_E86_48);
}

//----- (00720EC0) --------------------------------------------------------  // acclient.c:818687
int _E88_45()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_13, "DefaultState");
  return atexit(_E89_58);
}

//----- (00720EE0) --------------------------------------------------------  // acclient.c:818694
int sub_720EE0()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_13, "DisplayHeight");
  return atexit(_E92_67);
}

//----- (00720F00) --------------------------------------------------------  // acclient.c:818701
int _E94_58()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_13, "DisplayWidth");
  return atexit(sub_78F4A0);
}

//----- (00720F20) --------------------------------------------------------  // acclient.c:818708
int sub_720F20()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_13, "DrawMode");
  return atexit(sub_78F4D0);
}

//----- (00720F40) --------------------------------------------------------  // acclient.c:818715
int sub_720F40()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_13, "Duration");
  return atexit(sub_78F500);
}

//----- (00720F60) --------------------------------------------------------  // acclient.c:818722
int sub_720F60()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_13, "Element");
  return atexit(sub_78F530);
}

//----- (00720F80) --------------------------------------------------------  // acclient.c:818729
int sub_720F80()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_13, "ElementHeader");
  return atexit(sub_78F560);
}

//----- (00720FA0) --------------------------------------------------------  // acclient.c:818736
int sub_720FA0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_13, "ElementWHeader");
  return atexit(sub_78F590);
}

//----- (00720FC0) --------------------------------------------------------  // acclient.c:818743
int sub_720FC0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_13, "ElementID");
  return atexit(_E113_91);
}

//----- (00720FE0) --------------------------------------------------------  // acclient.c:818750
int sub_720FE0()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_13, "EndAlpha");
  return atexit(_E116_83);
}

//----- (00721000) --------------------------------------------------------  // acclient.c:818757
int sub_721000()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_13, "EngineType");
  return atexit(sub_78F620);
}

//----- (00721020) --------------------------------------------------------  // acclient.c:818764
int _E121_92()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_13, "EventID");
  return atexit(sub_78F650);
}

//----- (00721040) --------------------------------------------------------  // acclient.c:818771
int _E124_92()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_13, "File");
  return atexit(_E125_86);
}

//----- (00721060) --------------------------------------------------------  // acclient.c:818778
int _E127_79()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_13, "Frames");
  return atexit(_E128_84);
}

//----- (00721080) --------------------------------------------------------  // acclient.c:818785
int _E130_72()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_13, "PREPROC_HEADER");
  return atexit(_E131_73);
}

//----- (007210A0) --------------------------------------------------------  // acclient.c:818792
int _E133_65()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_13, "Height");
  return atexit(_E134_57);
}

//----- (007210C0) --------------------------------------------------------  // acclient.c:818799
int _E136_49()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_13, "JumpItemIndex");
  return atexit(_E137_56);
}

//----- (007210E0) --------------------------------------------------------  // acclient.c:818806
int _E139_49()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_13, "LeftEdge");
  return atexit(_E140_50);
}

//----- (00721100) --------------------------------------------------------  // acclient.c:818813
int _E142_46()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_13, "MaxDuration");
  return atexit(_E143_50);
}

//----- (00721120) --------------------------------------------------------  // acclient.c:818820
int _E145_48()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_13, "Media");
  return atexit(_E146_50);
}

//----- (00721140) --------------------------------------------------------  // acclient.c:818827
int _E148_47()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_13, "MediaType");
  return atexit(_E149_49);
}

//----- (00721160) --------------------------------------------------------  // acclient.c:818834
int _E151_45()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_13, "MinDuration");
  return atexit(_E152_50);
}

//----- (00721180) --------------------------------------------------------  // acclient.c:818841
int _E154_46()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_13, "NoDBFile");
  return atexit(_E155_46);
}

//----- (007211A0) --------------------------------------------------------  // acclient.c:818848
int _E157_43()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_13, "StretchToFullScreen");
  return atexit(_E158_47);
}

//----- (007211C0) --------------------------------------------------------  // acclient.c:818855
int _E160_46()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_13, "PassToChildren");
  return atexit(_E161_44);
}

//----- (007211E0) --------------------------------------------------------  // acclient.c:818862
int _E163_39()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_13, "Probability");
  return atexit(_E164_46);
}

//----- (00721200) --------------------------------------------------------  // acclient.c:818869
int _E166_41()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_14, "Properties");
  return atexit(_E167_42);
}

//----- (00721220) --------------------------------------------------------  // acclient.c:818876
int _E169_39()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_13, "Remove");
  return atexit(_E170_42);
}

//----- (00721240) --------------------------------------------------------  // acclient.c:818883
int _E172_37()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_13, "RightEdge");
  return atexit(_E173_37);
}

//----- (00721260) --------------------------------------------------------  // acclient.c:818890
int _E175_34()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_13, "SoundName");
  return atexit(_E176_39);
}

//----- (00721280) --------------------------------------------------------  // acclient.c:818897
int _E178_34()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_13, "SoundTable");
  return atexit(_E179_38);
}

//----- (007212A0) --------------------------------------------------------  // acclient.c:818904
int _E181_34()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_13, "StartAlpha");
  return atexit(_E182_38);
}

//----- (007212C0) --------------------------------------------------------  // acclient.c:818911
int _E184_32()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_13, "State");
  return atexit(_E185_35);
}

//----- (007212E0) --------------------------------------------------------  // acclient.c:818918
int _E187_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_13, "StateHeader");
  return atexit(_E188_36);
}

//----- (00721300) --------------------------------------------------------  // acclient.c:818925
int _E190_32()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_13, "StateWHeader");
  return atexit(_E191_35);
}

//----- (00721320) --------------------------------------------------------  // acclient.c:818932
int _E193_31()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_13, "StateID");
  return atexit(_E194_42);
}

//----- (00721340) --------------------------------------------------------  // acclient.c:818939
int _E196_38()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_13, "TopEdge");
  return atexit(_E197_32);
}

//----- (00721360) --------------------------------------------------------  // acclient.c:818946
int _E199_30()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_13, "Type");
  return atexit(_E200_36);
}

//----- (00721380) --------------------------------------------------------  // acclient.c:818953
int _E202_34()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_13, "Width");
  return atexit(_E203_35);
}

//----- (007213A0) --------------------------------------------------------  // acclient.c:818960
int _E205_32()
{
  PStringBase<char>::PStringBase<char>(&KW_X_13, "X");
  return atexit(_E206_39);
}

//----- (007213C0) --------------------------------------------------------  // acclient.c:818967
int _E208_36()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_13, "XHotspot");
  return atexit(_E209_33);
}

//----- (007213E0) --------------------------------------------------------  // acclient.c:818974
int _E211_31()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_13, "Y");
  return atexit(_E212_36);
}

//----- (00721400) --------------------------------------------------------  // acclient.c:818981
int _E214_33()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_13, "YHotspot");
  return atexit(_E215_33);
}

//----- (00721420) --------------------------------------------------------  // acclient.c:818988
int _E217_30()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_13, "ZLevel");
  return atexit(_E218_33);
}

//----- (00721440) --------------------------------------------------------  // acclient.c:818995
int _E220_30()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_13, "Comments");
  return atexit(_E221_33);
}

//----- (00721460) --------------------------------------------------------  // acclient.c:819002
int _E223_31()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_13, "HasAlpha");
  return atexit(_E224_33);
}

//----- (0078F350) --------------------------------------------------------  // acclient.c:935645
void __cdecl sub_78F350()
{
  char *v0; // esi@1

  v0 = &KW_NULL_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F380) --------------------------------------------------------  // acclient.c:935658
void __cdecl sub_78F380()
{
  char *v0; // esi@1

  v0 = &KW_BASE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F3B0) --------------------------------------------------------  // acclient.c:935671
void __cdecl sub_78F3B0()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F3E0) --------------------------------------------------------  // acclient.c:935684
void __cdecl _E83_69()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F410) --------------------------------------------------------  // acclient.c:935697
void __cdecl _E86_48()
{
  char *v0; // esi@1

  v0 = &KW_CODE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F440) --------------------------------------------------------  // acclient.c:935710
void __cdecl _E89_58()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F470) --------------------------------------------------------  // acclient.c:935723
void __cdecl _E92_67()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F4A0) --------------------------------------------------------  // acclient.c:935736
void __cdecl sub_78F4A0()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F4D0) --------------------------------------------------------  // acclient.c:935749
void __cdecl sub_78F4D0()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F500) --------------------------------------------------------  // acclient.c:935762
void __cdecl sub_78F500()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F530) --------------------------------------------------------  // acclient.c:935775
void __cdecl sub_78F530()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F560) --------------------------------------------------------  // acclient.c:935788
void __cdecl sub_78F560()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F590) --------------------------------------------------------  // acclient.c:935801
void __cdecl sub_78F590()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F5C0) --------------------------------------------------------  // acclient.c:935814
void __cdecl _E113_91()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F5F0) --------------------------------------------------------  // acclient.c:935827
void __cdecl _E116_83()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F620) --------------------------------------------------------  // acclient.c:935840
void __cdecl sub_78F620()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F650) --------------------------------------------------------  // acclient.c:935853
void __cdecl sub_78F650()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F680) --------------------------------------------------------  // acclient.c:935866
void __cdecl _E125_86()
{
  char *v0; // esi@1

  v0 = &KW_FILE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F6B0) --------------------------------------------------------  // acclient.c:935879
void __cdecl _E128_84()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F6E0) --------------------------------------------------------  // acclient.c:935892
void __cdecl _E131_73()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F710) --------------------------------------------------------  // acclient.c:935905
void __cdecl _E134_57()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F740) --------------------------------------------------------  // acclient.c:935918
void __cdecl _E137_56()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F770) --------------------------------------------------------  // acclient.c:935931
void __cdecl _E140_50()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F7A0) --------------------------------------------------------  // acclient.c:935944
void __cdecl _E143_50()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F7D0) --------------------------------------------------------  // acclient.c:935957
void __cdecl _E146_50()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F800) --------------------------------------------------------  // acclient.c:935970
void __cdecl _E149_49()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F830) --------------------------------------------------------  // acclient.c:935983
void __cdecl _E152_50()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F860) --------------------------------------------------------  // acclient.c:935996
void __cdecl _E155_46()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F890) --------------------------------------------------------  // acclient.c:936009
void __cdecl _E158_47()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F8C0) --------------------------------------------------------  // acclient.c:936022
void __cdecl _E161_44()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F8F0) --------------------------------------------------------  // acclient.c:936035
void __cdecl _E164_46()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F920) --------------------------------------------------------  // acclient.c:936048
void __cdecl _E167_42()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F950) --------------------------------------------------------  // acclient.c:936061
void __cdecl _E170_42()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F980) --------------------------------------------------------  // acclient.c:936074
void __cdecl _E173_37()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F9B0) --------------------------------------------------------  // acclient.c:936087
void __cdecl _E176_39()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078F9E0) --------------------------------------------------------  // acclient.c:936100
void __cdecl _E179_38()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FA10) --------------------------------------------------------  // acclient.c:936113
void __cdecl _E182_38()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FA40) --------------------------------------------------------  // acclient.c:936126
void __cdecl _E185_35()
{
  char *v0; // esi@1

  v0 = &KW_STATE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FA70) --------------------------------------------------------  // acclient.c:936139
void __cdecl _E188_36()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FAA0) --------------------------------------------------------  // acclient.c:936152
void __cdecl _E191_35()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FAD0) --------------------------------------------------------  // acclient.c:936165
void __cdecl _E194_42()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FB00) --------------------------------------------------------  // acclient.c:936178
void __cdecl _E197_32()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FB30) --------------------------------------------------------  // acclient.c:936191
void __cdecl _E200_36()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FB60) --------------------------------------------------------  // acclient.c:936204
void __cdecl _E203_35()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FB90) --------------------------------------------------------  // acclient.c:936217
void __cdecl _E206_39()
{
  char *v0; // esi@1

  v0 = &KW_X_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FBC0) --------------------------------------------------------  // acclient.c:936230
void __cdecl _E209_33()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FBF0) --------------------------------------------------------  // acclient.c:936243
void __cdecl _E212_36()
{
  char *v0; // esi@1

  v0 = &KW_Y_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FC20) --------------------------------------------------------  // acclient.c:936256
void __cdecl _E215_33()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FC50) --------------------------------------------------------  // acclient.c:936269
void __cdecl _E218_33()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FC80) --------------------------------------------------------  // acclient.c:936282
void __cdecl _E221_33()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FCB0) --------------------------------------------------------  // acclient.c:936295
void __cdecl _E224_33()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

