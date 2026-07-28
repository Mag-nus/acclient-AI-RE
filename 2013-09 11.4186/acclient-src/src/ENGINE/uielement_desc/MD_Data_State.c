/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_State
   Object     : ENGINE\uielement_desc\MD_Data_State.obj
   Functions  : 108
   Addresses  : 0069CE60 - 0078B9A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069CE60) --------------------------------------------------------  // acclient.c:693151
void __thiscall MD_Data_Pause::Serialize(MD_Data_State *this, Archive *_io_archive)
{
  MD_Data_State *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5

  v2 = this;
  MediaDesc::Serialize((MediaDesc *)&this->vfptr, _io_archive);
  Archive::CheckAlignment(_io_archive, 4u);
  v3 = Archive::GetBytes(_io_archive, 4u);
  if ( v3 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_stateID;
    else
      v2->m_stateID = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(_io_archive, 4u);
  v4 = Archive::GetBytes(_io_archive, 4u);
  if ( v4 )
  {
    if ( _io_archive->m_flags & 1 )
      *(_DWORD *)v4 = LODWORD(v2->m_probability);
    else
      LODWORD(v2->m_probability) = *(_DWORD *)v4;
  }
}

//----- (0069D9B0) --------------------------------------------------------  // acclient.c:693908
void __thiscall MD_Data_State::MD_Data_State(MD_Data_State *this)
{
  MD_Data_State *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 0xAu);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_State::vftable;
  v1->m_stateID = 0;
  LODWORD(v1->m_probability) = 1065353216;
}
// 801230: using guessed type int (__thiscall *MD_Data_State::vftable)(void *, char);

//----- (0069D9E0) --------------------------------------------------------  // acclient.c:693921
void __thiscall MD_Data_State::MD_Data_State(MD_Data_State *this, MD_Data_State *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_State::vftable;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 1065353216;
  if ( (MD_Data_State *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_stateID;
    *(_DWORD *)(v2 + 12) = LODWORD(_rhs->m_probability);
  }
}
// 801230: using guessed type int (__thiscall *MD_Data_State::vftable)(void *, char);

//----- (0069DA20) --------------------------------------------------------  // acclient.c:693940
bool __thiscall MD_Data_State::ToFileNode(MD_Data_State *this, PFileNode *_file_node)
{
  MD_Data_State *v2; // ebx@1
  PStringBase<char> v3; // ST08_4@3
  PFileNode *v4; // eax@3
  PStringBase<char> v5; // ST08_4@5
  PFileNode *v6; // eax@5
  bool result; // al@6

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v3.m_charbuffer = KW_STATE_6.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_STATE_6.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v3)) != 0)
    && FileNodeUtils::MakeSubNodeAsEnum(v4, 0x14u, v2->m_stateID)
    && (v5.m_charbuffer = KW_PROBABILITY_6.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_PROBABILITY_6.m_charbuffer[-1]),
        (v6 = PFileNode::MakeSubNode(_file_node, v5)) != 0) )
    result = PFileNode::MakeSubNodeAsFloat(v6, v2->m_probability) != 0;
  else
    result = 0;
  return result;
}

//----- (0069DAC0) --------------------------------------------------------  // acclient.c:693966
char __thiscall MD_Data_State::FromFileNode(MD_Data_State *this, PFileNode *_file_node)
{
  PFileNode *v2; // esi@1
  char v3; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // eax@5
  PFileNode *v5; // eax@5
  PFileNode *v6; // esi@5
  int v7; // eax@8
  PSRefBufferCharData<char> *v8; // ecx@8
  int v9; // eax@13
  PStringBase<char> *v10; // ecx@13
  PSRefBufferCharData<char> *v11; // ecx@16
  PStringBase<char> *v12; // eax@16
  char *v13; // esi@16
  int v14; // eax@18
  char *v15; // esi@19
  int v16; // edx@21
  char *v17; // esi@22
  int v18; // edx@24
  char v19; // al@26
  PStringBase<char> *v20; // [sp-8h] [bp-30h]@15
  PStringBase<char> v21; // [sp-4h] [bp-2Ch]@5
  PStringBase<char> strName; // [sp+10h] [bp-18h]@16
  unsigned int index; // [sp+14h] [bp-14h]@2
  MD_Data_State *v24; // [sp+18h] [bp-10h]@1
  PStringBase<char> rhs; // [sp+1Ch] [bp-Ch]@16
  PStringBase<char> result; // [sp+20h] [bp-8h]@16
  unsigned int num; // [sp+24h] [bp-4h]@2

  v2 = _file_node;
  v24 = this;
  if ( _file_node )
  {
    v3 = 1;
    num = PFileNode::GetNumSubNodes(_file_node);
    index = 0;
    if ( num )
    {
      while ( 1 )
      {
        v4 = v2->vfptr;
        v21.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v5 = (PFileNode *)v4[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, index);
        v6 = v5;
        if ( v5 && !PFileNode::IsKeyword(v5, (int)InterlockedDecrement, &KW_MEDIATYPE_6) )
        {
          if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_STATE_6) )
          {
            v7 = PFileNode::GetLeaf(v6);
            if ( v7 )
            {
              if ( !FileNodeUtils::GetNameAsEnum((PFileNode *)v7, 0x14u, &v24->m_stateID) )
                v3 = 0;
            }
            else
            {
              v21.m_charbuffer = v8;
              PStringBase<char>::PStringBase<char>(&v21, "Expecting a leaf node");
              PFileNode::ReportError((int)InterlockedDecrement, v6, v21);
              v3 = 0;
            }
          }
          else if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_PROBABILITY_6) )
          {
            v9 = PFileNode::GetLeaf(v6);
            if ( !v9 || !PFileNode::GetNameAsFloat((PFileNode *)v9, (int)InterlockedDecrement, &v24->m_probability) )
            {
              v21.m_charbuffer = KW_PROBABILITY_6.m_charbuffer;
              v20 = v10;
              PStringBase<char>::PStringBase<char>(
                (PStringBase<char> *)&v20,
                "MD_Data_State::FromFileNode, %s expects one float");
              PFileNode::ReportError((int)InterlockedDecrement, v6, (PStringBase<char>)v20);
              v3 = 0;
            }
          }
          else
          {
            strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PFileNode::GetNameAsPString(v6, (int)InterlockedDecrement, &strName);
            PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
            v21.m_charbuffer = v11;
            v20 = &rhs;
            v12 = operator+(&result, "Unknown Keyword: [", &strName);
            PStringBase<char>::operator+(v12, &v21, v20);
            PFileNode::ReportError((int)InterlockedDecrement, v6, v21);
            v13 = &result.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v13 )
            {
              v14 = *(_DWORD *)v13;
              v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v14)(v13, 1);
            }
            v15 = &rhs.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v15 )
            {
              v16 = *(_DWORD *)v15;
              v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v16)(v15, 1);
            }
            v17 = &strName.m_charbuffer[-2].m_data[12];
            v3 = 0;
            if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) && v17 )
            {
              v18 = *(_DWORD *)v17;
              v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v18)(v17, 1);
            }
          }
        }
        ++index;
        if ( index >= num )
          break;
        v2 = _file_node;
      }
    }
    v19 = v3;
  }
  else
  {
    v19 = 0;
  }
  return v19;
}

//----- (0069EA90) --------------------------------------------------------  // acclient.c:694947
MD_Data_State *__thiscall MD_Data_Pause::scalar_deleting_destructor(MD_Data_State *this, unsigned int a2)
{
  MD_Data_State *v2; // esi@1

  v2 = this;
  MediaDesc::~MediaDesc((MediaDesc *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0071E160) --------------------------------------------------------  // acclient.c:816133
int sub_71E160()
{
  KW_NULL_10.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78B040);
}

//----- (0071E180) --------------------------------------------------------  // acclient.c:816141
int sub_71E180()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_6, "Base");
  return atexit(sub_78B070);
}

//----- (0071E1A0) --------------------------------------------------------  // acclient.c:816148
int sub_71E1A0()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_6, "BottomEdge");
  return atexit(_E80_98);
}

//----- (0071E1C0) --------------------------------------------------------  // acclient.c:816155
int _E82_66()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_6, "Child");
  return atexit(_E83_62);
}

//----- (0071E1E0) --------------------------------------------------------  // acclient.c:816162
int _E85_49()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_6, "Code");
  return atexit(_E86_41);
}

//----- (0071E200) --------------------------------------------------------  // acclient.c:816169
int _E88_38()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_6, "DefaultState");
  return atexit(_E89_51);
}

//----- (0071E220) --------------------------------------------------------  // acclient.c:816176
int sub_71E220()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_6, "DisplayHeight");
  return atexit(_E92_60);
}

//----- (0071E240) --------------------------------------------------------  // acclient.c:816183
int _E94_51()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_6, "DisplayWidth");
  return atexit(sub_78B190);
}

//----- (0071E260) --------------------------------------------------------  // acclient.c:816190
int sub_71E260()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_6, "DrawMode");
  return atexit(sub_78B1C0);
}

//----- (0071E280) --------------------------------------------------------  // acclient.c:816197
int sub_71E280()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_6, "Duration");
  return atexit(sub_78B1F0);
}

//----- (0071E2A0) --------------------------------------------------------  // acclient.c:816204
int sub_71E2A0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_6, "Element");
  return atexit(sub_78B220);
}

//----- (0071E2C0) --------------------------------------------------------  // acclient.c:816211
int sub_71E2C0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_6, "ElementHeader");
  return atexit(sub_78B250);
}

//----- (0071E2E0) --------------------------------------------------------  // acclient.c:816218
int sub_71E2E0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_6, "ElementWHeader");
  return atexit(sub_78B280);
}

//----- (0071E300) --------------------------------------------------------  // acclient.c:816225
int sub_71E300()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_6, "ElementID");
  return atexit(_E113_84);
}

//----- (0071E320) --------------------------------------------------------  // acclient.c:816232
int sub_71E320()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_6, "EndAlpha");
  return atexit(_E116_76);
}

//----- (0071E340) --------------------------------------------------------  // acclient.c:816239
int _E118_94()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_6, "EngineType");
  return atexit(sub_78B310);
}

//----- (0071E360) --------------------------------------------------------  // acclient.c:816246
int _E121_85()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_6, "EventID");
  return atexit(sub_78B340);
}

//----- (0071E380) --------------------------------------------------------  // acclient.c:816253
int _E124_85()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_6, "File");
  return atexit(_E125_79);
}

//----- (0071E3A0) --------------------------------------------------------  // acclient.c:816260
int _E127_72()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_6, "Frames");
  return atexit(_E128_77);
}

//----- (0071E3C0) --------------------------------------------------------  // acclient.c:816267
int _E130_65()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_6, "PREPROC_HEADER");
  return atexit(_E131_66);
}

//----- (0071E3E0) --------------------------------------------------------  // acclient.c:816274
int _E133_58()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_6, "Height");
  return atexit(_E134_50);
}

//----- (0071E400) --------------------------------------------------------  // acclient.c:816281
int _E136_42()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_6, "JumpItemIndex");
  return atexit(_E137_49);
}

//----- (0071E420) --------------------------------------------------------  // acclient.c:816288
int _E139_42()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_6, "LeftEdge");
  return atexit(_E140_43);
}

//----- (0071E440) --------------------------------------------------------  // acclient.c:816295
int _E142_39()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_6, "MaxDuration");
  return atexit(_E143_43);
}

//----- (0071E460) --------------------------------------------------------  // acclient.c:816302
int _E145_41()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_6, "Media");
  return atexit(_E146_43);
}

//----- (0071E480) --------------------------------------------------------  // acclient.c:816309
int _E148_40()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_6, "MediaType");
  return atexit(_E149_42);
}

//----- (0071E4A0) --------------------------------------------------------  // acclient.c:816316
int _E151_38()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_6, "MinDuration");
  return atexit(_E152_43);
}

//----- (0071E4C0) --------------------------------------------------------  // acclient.c:816323
int _E154_39()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_6, "NoDBFile");
  return atexit(_E155_39);
}

//----- (0071E4E0) --------------------------------------------------------  // acclient.c:816330
int _E157_36()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_6, "StretchToFullScreen");
  return atexit(_E158_40);
}

//----- (0071E500) --------------------------------------------------------  // acclient.c:816337
int _E160_39()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_6, "PassToChildren");
  return atexit(_E161_37);
}

//----- (0071E520) --------------------------------------------------------  // acclient.c:816344
int _E163_32()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_6, "Probability");
  return atexit(_E164_39);
}

//----- (0071E540) --------------------------------------------------------  // acclient.c:816351
int _E166_34()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_7, "Properties");
  return atexit(_E167_35);
}

//----- (0071E560) --------------------------------------------------------  // acclient.c:816358
int _E169_32()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_6, "Remove");
  return atexit(_E170_35);
}

//----- (0071E580) --------------------------------------------------------  // acclient.c:816365
int _E172_30()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_6, "RightEdge");
  return atexit(_E173_30);
}

//----- (0071E5A0) --------------------------------------------------------  // acclient.c:816372
int _E175_27()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_6, "SoundName");
  return atexit(_E176_32);
}

//----- (0071E5C0) --------------------------------------------------------  // acclient.c:816379
int _E178_27()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_6, "SoundTable");
  return atexit(_E179_31);
}

//----- (0071E5E0) --------------------------------------------------------  // acclient.c:816386
int _E181_27()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_6, "StartAlpha");
  return atexit(_E182_31);
}

//----- (0071E600) --------------------------------------------------------  // acclient.c:816393
int _E184_25()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_6, "State");
  return atexit(_E185_28);
}

//----- (0071E620) --------------------------------------------------------  // acclient.c:816400
int _E187_24()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_6, "StateHeader");
  return atexit(_E188_29);
}

//----- (0071E640) --------------------------------------------------------  // acclient.c:816407
int _E190_25()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_6, "StateWHeader");
  return atexit(_E191_28);
}

//----- (0071E660) --------------------------------------------------------  // acclient.c:816414
int _E193_24()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_6, "StateID");
  return atexit(_E194_35);
}

//----- (0071E680) --------------------------------------------------------  // acclient.c:816421
int _E196_31()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_6, "TopEdge");
  return atexit(_E197_25);
}

//----- (0071E6A0) --------------------------------------------------------  // acclient.c:816428
int _E199_23()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_6, "Type");
  return atexit(_E200_29);
}

//----- (0071E6C0) --------------------------------------------------------  // acclient.c:816435
int _E202_27()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_6, "Width");
  return atexit(_E203_28);
}

//----- (0071E6E0) --------------------------------------------------------  // acclient.c:816442
int _E205_25()
{
  PStringBase<char>::PStringBase<char>(&KW_X_6, "X");
  return atexit(_E206_32);
}

//----- (0071E700) --------------------------------------------------------  // acclient.c:816449
int _E208_29()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_6, "XHotspot");
  return atexit(_E209_26);
}

//----- (0071E720) --------------------------------------------------------  // acclient.c:816456
int _E211_24()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_6, "Y");
  return atexit(_E212_29);
}

//----- (0071E740) --------------------------------------------------------  // acclient.c:816463
int _E214_26()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_6, "YHotspot");
  return atexit(_E215_26);
}

//----- (0071E760) --------------------------------------------------------  // acclient.c:816470
int _E217_23()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_6, "ZLevel");
  return atexit(_E218_26);
}

//----- (0071E780) --------------------------------------------------------  // acclient.c:816477
int _E220_23()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_6, "Comments");
  return atexit(_E221_26);
}

//----- (0071E7A0) --------------------------------------------------------  // acclient.c:816484
int _E223_24()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_6, "HasAlpha");
  return atexit(_E224_26);
}

//----- (0078B040) --------------------------------------------------------  // acclient.c:931004
void __cdecl sub_78B040()
{
  char *v0; // esi@1

  v0 = &KW_NULL_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B070) --------------------------------------------------------  // acclient.c:931017
void __cdecl sub_78B070()
{
  char *v0; // esi@1

  v0 = &KW_BASE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B0A0) --------------------------------------------------------  // acclient.c:931030
void __cdecl _E80_98()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B0D0) --------------------------------------------------------  // acclient.c:931043
void __cdecl _E83_62()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B100) --------------------------------------------------------  // acclient.c:931056
void __cdecl _E86_41()
{
  char *v0; // esi@1

  v0 = &KW_CODE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B130) --------------------------------------------------------  // acclient.c:931069
void __cdecl _E89_51()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B160) --------------------------------------------------------  // acclient.c:931082
void __cdecl _E92_60()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B190) --------------------------------------------------------  // acclient.c:931095
void __cdecl sub_78B190()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B1C0) --------------------------------------------------------  // acclient.c:931108
void __cdecl sub_78B1C0()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B1F0) --------------------------------------------------------  // acclient.c:931121
void __cdecl sub_78B1F0()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B220) --------------------------------------------------------  // acclient.c:931134
void __cdecl sub_78B220()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B250) --------------------------------------------------------  // acclient.c:931147
void __cdecl sub_78B250()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B280) --------------------------------------------------------  // acclient.c:931160
void __cdecl sub_78B280()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B2B0) --------------------------------------------------------  // acclient.c:931173
void __cdecl _E113_84()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B2E0) --------------------------------------------------------  // acclient.c:931186
void __cdecl _E116_76()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B310) --------------------------------------------------------  // acclient.c:931199
void __cdecl sub_78B310()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B340) --------------------------------------------------------  // acclient.c:931212
void __cdecl sub_78B340()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B370) --------------------------------------------------------  // acclient.c:931225
void __cdecl _E125_79()
{
  char *v0; // esi@1

  v0 = &KW_FILE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B3A0) --------------------------------------------------------  // acclient.c:931238
void __cdecl _E128_77()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B3D0) --------------------------------------------------------  // acclient.c:931251
void __cdecl _E131_66()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B400) --------------------------------------------------------  // acclient.c:931264
void __cdecl _E134_50()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B430) --------------------------------------------------------  // acclient.c:931277
void __cdecl _E137_49()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B460) --------------------------------------------------------  // acclient.c:931290
void __cdecl _E140_43()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B490) --------------------------------------------------------  // acclient.c:931303
void __cdecl _E143_43()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B4C0) --------------------------------------------------------  // acclient.c:931316
void __cdecl _E146_43()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B4F0) --------------------------------------------------------  // acclient.c:931329
void __cdecl _E149_42()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B520) --------------------------------------------------------  // acclient.c:931342
void __cdecl _E152_43()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B550) --------------------------------------------------------  // acclient.c:931355
void __cdecl _E155_39()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B580) --------------------------------------------------------  // acclient.c:931368
void __cdecl _E158_40()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B5B0) --------------------------------------------------------  // acclient.c:931381
void __cdecl _E161_37()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B5E0) --------------------------------------------------------  // acclient.c:931394
void __cdecl _E164_39()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B610) --------------------------------------------------------  // acclient.c:931407
void __cdecl _E167_35()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B640) --------------------------------------------------------  // acclient.c:931420
void __cdecl _E170_35()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B670) --------------------------------------------------------  // acclient.c:931433
void __cdecl _E173_30()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B6A0) --------------------------------------------------------  // acclient.c:931446
void __cdecl _E176_32()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B6D0) --------------------------------------------------------  // acclient.c:931459
void __cdecl _E179_31()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B700) --------------------------------------------------------  // acclient.c:931472
void __cdecl _E182_31()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B730) --------------------------------------------------------  // acclient.c:931485
void __cdecl _E185_28()
{
  char *v0; // esi@1

  v0 = &KW_STATE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B760) --------------------------------------------------------  // acclient.c:931498
void __cdecl _E188_29()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B790) --------------------------------------------------------  // acclient.c:931511
void __cdecl _E191_28()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B7C0) --------------------------------------------------------  // acclient.c:931524
void __cdecl _E194_35()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B7F0) --------------------------------------------------------  // acclient.c:931537
void __cdecl _E197_25()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B820) --------------------------------------------------------  // acclient.c:931550
void __cdecl _E200_29()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B850) --------------------------------------------------------  // acclient.c:931563
void __cdecl _E203_28()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B880) --------------------------------------------------------  // acclient.c:931576
void __cdecl _E206_32()
{
  char *v0; // esi@1

  v0 = &KW_X_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B8B0) --------------------------------------------------------  // acclient.c:931589
void __cdecl _E209_26()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B8E0) --------------------------------------------------------  // acclient.c:931602
void __cdecl _E212_29()
{
  char *v0; // esi@1

  v0 = &KW_Y_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B910) --------------------------------------------------------  // acclient.c:931615
void __cdecl _E215_26()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B940) --------------------------------------------------------  // acclient.c:931628
void __cdecl _E218_26()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B970) --------------------------------------------------------  // acclient.c:931641
void __cdecl _E221_26()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078B9A0) --------------------------------------------------------  // acclient.c:931654
void __cdecl _E224_26()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

