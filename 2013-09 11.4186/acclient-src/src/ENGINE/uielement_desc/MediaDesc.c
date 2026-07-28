/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MediaDesc
   Object     : ENGINE\uielement_desc\MediaDesc.obj
   Functions  : 112
   Addresses  : 0069D3C0 - 0078A670 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069D3C0) --------------------------------------------------------  // acclient.c:693513
void __thiscall MediaDesc::MediaDesc(MediaDesc *this)
{
  this->vfptr = (MediaDescVtbl *)&MediaDesc::vftable;
  this->m_type = 0;
}
// 801118: using guessed type int (__thiscall *MediaDesc::vftable)(void *, char);

//----- (0069D3D0) --------------------------------------------------------  // acclient.c:693521
void __thiscall MediaDesc::MediaDesc(MediaDesc *this, unsigned int _type)
{
  this->vfptr = (MediaDescVtbl *)&MediaDesc::vftable;
  this->m_type = _type;
}
// 801118: using guessed type int (__thiscall *MediaDesc::vftable)(void *, char);

//----- (0069D3F0) --------------------------------------------------------  // acclient.c:693529
void __thiscall MediaDesc::~MediaDesc(MediaDesc *this)
{
  this->vfptr = (MediaDescVtbl *)&MediaDesc::vftable;
}
// 801118: using guessed type int (__thiscall *MediaDesc::vftable)(void *, char);

//----- (0069D400) --------------------------------------------------------  // acclient.c:693536
int __thiscall MediaDesc::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  if ( this != a2 )
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  return result;
}

//----- (0069D420) --------------------------------------------------------  // acclient.c:693547
void __cdecl MediaDesc::CreateMediaType(unsigned int _type)
{
  MD_Data_Anim *v1; // eax@2
  MD_Data_Alpha *v2; // eax@4
  MD_Data_Pause *v3; // eax@6
  MD_Data_Image *v4; // eax@8
  MD_Data_Sound *v5; // eax@10
  MD_Data_Jump *v6; // eax@12
  MD_Data_Fade *v7; // eax@14
  MD_Data_Message *v8; // eax@16
  MD_Data_State *v9; // eax@18
  MD_Data_Movie *v10; // eax@20
  MD_Data_Cursor *v11; // eax@22

  switch ( _type )
  {
    case 3u:
      v1 = (MD_Data_Anim *)operator new(0x30u);
      if ( v1 )
        MD_Data_Anim::MD_Data_Anim(v1);
      break;
    case 2u:
      v2 = (MD_Data_Alpha *)operator new(0xCu);
      if ( v2 )
        MD_Data_Alpha::MD_Data_Alpha(v2);
      break;
    case 8u:
      v3 = (MD_Data_Pause *)operator new(0x18u);
      if ( v3 )
        MD_Data_Pause::MD_Data_Pause(v3);
      break;
    case 5u:
      v4 = (MD_Data_Image *)operator new(0x10u);
      if ( v4 )
        MD_Data_Image::MD_Data_Image(v4);
      break;
    case 9u:
      v5 = (MD_Data_Sound *)operator new(0x10u);
      if ( v5 )
        MD_Data_Sound::MD_Data_Sound(v5);
      break;
    case 6u:
      v6 = (MD_Data_Jump *)operator new(0x10u);
      if ( v6 )
        MD_Data_Jump::MD_Data_Jump(v6);
      break;
    case 0xBu:
      v7 = (MD_Data_Fade *)operator new(0x20u);
      if ( v7 )
        MD_Data_Fade::MD_Data_Fade(v7);
      break;
    case 7u:
      v8 = (MD_Data_Message *)operator new(0x10u);
      if ( v8 )
        MD_Data_Message::MD_Data_Message(v8);
      break;
    case 0xAu:
      v9 = (MD_Data_State *)operator new(0x10u);
      if ( v9 )
        MD_Data_State::MD_Data_State(v9);
      break;
    case 1u:
      v10 = (MD_Data_Movie *)operator new(0x14u);
      if ( v10 )
        MD_Data_Movie::MD_Data_Movie(v10);
      break;
    case 4u:
      v11 = (MD_Data_Cursor *)operator new(0x14u);
      if ( v11 )
        MD_Data_Cursor::MD_Data_Cursor(v11);
      break;
    default:
      return;
  }
}

//----- (0069D570) --------------------------------------------------------  // acclient.c:693624
void __cdecl MediaDesc::CreateMediaType(MediaDesc *_rhs)
{
  MD_Data_Anim *v1; // eax@2
  MD_Data_Alpha *v2; // eax@4
  MD_Data_Pause *v3; // eax@6
  MD_Data_Image *v4; // eax@8
  MD_Data_Sound *v5; // eax@10
  MD_Data_Jump *v6; // eax@12
  MD_Data_Fade *v7; // eax@14
  MD_Data_Message *v8; // eax@16
  MD_Data_State *v9; // eax@18
  MD_Data_Movie *v10; // eax@20
  MD_Data_Cursor *v11; // eax@22

  switch ( _rhs->m_type )
  {
    case 3u:
      v1 = (MD_Data_Anim *)operator new(0x30u);
      if ( v1 )
        MD_Data_Anim::MD_Data_Anim(v1, (MD_Data_Anim *)_rhs);
      break;
    case 2u:
      v2 = (MD_Data_Alpha *)operator new(0xCu);
      if ( v2 )
        MD_Data_Alpha::MD_Data_Alpha(v2, (MD_Data_Alpha *)_rhs);
      break;
    case 8u:
      v3 = (MD_Data_Pause *)operator new(0x18u);
      if ( v3 )
        MD_Data_Pause::MD_Data_Pause(v3, (MD_Data_Pause *)_rhs);
      break;
    case 5u:
      v4 = (MD_Data_Image *)operator new(0x10u);
      if ( v4 )
        MD_Data_Image::MD_Data_Image(v4, (MD_Data_Image *)_rhs);
      break;
    case 9u:
      v5 = (MD_Data_Sound *)operator new(0x10u);
      if ( v5 )
        MD_Data_Sound::MD_Data_Sound(v5, (MD_Data_Sound *)_rhs);
      break;
    case 6u:
      v6 = (MD_Data_Jump *)operator new(0x10u);
      if ( v6 )
        MD_Data_Jump::MD_Data_Jump(v6, (MD_Data_Jump *)_rhs);
      break;
    case 0xBu:
      v7 = (MD_Data_Fade *)operator new(0x20u);
      if ( v7 )
        MD_Data_Fade::MD_Data_Fade(v7, (MD_Data_Fade *)_rhs);
      break;
    case 7u:
      v8 = (MD_Data_Message *)operator new(0x10u);
      if ( v8 )
        MD_Data_Message::MD_Data_Message(v8, (MD_Data_Message *)_rhs);
      break;
    case 0xAu:
      v9 = (MD_Data_State *)operator new(0x10u);
      if ( v9 )
        MD_Data_State::MD_Data_State(v9, (MD_Data_State *)_rhs);
      break;
    case 1u:
      v10 = (MD_Data_Movie *)operator new(0x14u);
      if ( v10 )
        MD_Data_Movie::MD_Data_Movie(v10, (MD_Data_Movie *)_rhs);
      break;
    case 4u:
      v11 = (MD_Data_Cursor *)operator new(0x14u);
      if ( v11 )
        MD_Data_Cursor::MD_Data_Cursor(v11, (MD_Data_Cursor *)_rhs);
      break;
    default:
      return;
  }
}

//----- (0069D6E0) --------------------------------------------------------  // acclient.c:693701
MediaDesc *__thiscall MediaDesc::vector_deleting_destructor(MediaDesc *this, unsigned int a2)
{
  MediaDesc *v2; // esi@1

  v2 = this;
  this->vfptr = (MediaDescVtbl *)&MediaDesc::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 801118: using guessed type int (__thiscall *MediaDesc::vftable)(void *, char);

//----- (0069D700) --------------------------------------------------------  // acclient.c:693714
void __thiscall MediaDesc::Serialize(MediaDesc *this, Archive *io_archive)
{
  MediaDesc *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_type;
    else
      v2->m_type = *(_DWORD *)v3;
  }
}

//----- (0069D740) --------------------------------------------------------  // acclient.c:693732
char __thiscall MediaDesc::ToFileNode(MediaDesc *this, PFileNode *_file_node)
{
  PStringBase<char> v2; // esi@2
  volatile LONG *v3; // edi@2
  PFileNode *v4; // edi@2
  int v5; // esi@2
  unsigned int v6; // ebx@6
  PFileNode *v7; // eax@6
  PFileNode *v8; // esi@6
  MediaDesc *v10; // [sp+10h] [bp-4h]@1

  v10 = this;
  if ( !_file_node )
    return 0;
  v2.m_charbuffer = KW_MEDIATYPE_4.m_charbuffer;
  v3 = (volatile LONG *)&KW_MEDIATYPE_4.m_charbuffer[-1];
  InterlockedIncrement((volatile LONG *)&KW_MEDIATYPE_4.m_charbuffer[-1]);
  InterlockedIncrement(v3);
  v4 = PFileNode::MakeSubNodeAsPString(_file_node, v2);
  v5 = (int)&v2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  if ( !v4 )
    return 0;
  v6 = v10->m_type;
  v7 = (PFileNode *)((int (__thiscall *)(PFileNode *))v4->vfptr[1].__vecDelDtor)(v4);
  v8 = v7;
  if ( !v7 )
    return 0;
  if ( !FileNodeUtils::SetNameAsEnum(v7, 0xEu, v6) )
  {
    PFileNode::RemoveSubNodePtr(v4, v8);
    return 0;
  }
  return 1;
}

//----- (0069D7E0) --------------------------------------------------------  // acclient.c:693770
MediaDesc *__cdecl MediaDesc::CreateFromFileNode(PFileNode *_file_node)
{
  PFileNode *v1; // ebx@1
  MediaDesc *v2; // esi@2
  PFileNode *v3; // eax@2
  PSRefBufferCharData<char> *v4; // ecx@2
  int v5; // edi@2
  MediaDesc *result; // eax@3
  int v7; // eax@4
  PSRefBufferCharData<char> *v8; // ecx@4
  MediaDesc *v9; // eax@6
  PStringBase<char> v10; // [sp-4h] [bp-10h]@3

  v1 = _file_node;
  if ( _file_node )
  {
    v2 = 0;
    v3 = PFileNode::FindSubNode(_file_node, &KW_MEDIATYPE_4);
    v5 = (int)v3;
    if ( v3 )
    {
      _file_node = 0;
      v7 = PFileNode::GetLeaf(v3);
      if ( v7 )
      {
        if ( FileNodeUtils::GetNameAsEnum((PFileNode *)v7, 0xEu, (unsigned int *)&_file_node) )
        {
          MediaDesc::CreateMediaType((unsigned int)_file_node);
          v2 = v9;
          if ( v9 )
          {
            if ( !v9->vfptr->FromFileNode(v9, v1) )
            {
              v2->vfptr->__vecDelDtor(v2, 1u);
              v2 = 0;
            }
          }
        }
        result = v2;
      }
      else
      {
        v10.m_charbuffer = v8;
        PStringBase<char>::PStringBase<char>(&v10, "Expecting a leaf node");
        PFileNode::ReportError(v5, (PFileNode *)v5, v10);
        result = 0;
      }
    }
    else
    {
      v10.m_charbuffer = v4;
      PStringBase<char>::PStringBase<char>(&v10, "MediaDesc::CreateFromFileNode, missing type node");
      PFileNode::ReportError(v5, v1, v10);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0071D490) --------------------------------------------------------  // acclient.c:815411
int sub_71D490()
{
  KW_NULL_8.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_789D10);
}

//----- (0071D4B0) --------------------------------------------------------  // acclient.c:815419
int sub_71D4B0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_4, "Base");
  return atexit(sub_789D40);
}

//----- (0071D4D0) --------------------------------------------------------  // acclient.c:815426
int sub_71D4D0()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_4, "BottomEdge");
  return atexit(_E80_96);
}

//----- (0071D4F0) --------------------------------------------------------  // acclient.c:815433
int _E82_64()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_4, "Child");
  return atexit(_E83_60);
}

//----- (0071D510) --------------------------------------------------------  // acclient.c:815440
int _E85_47()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_4, "Code");
  return atexit(_E86_39);
}

//----- (0071D530) --------------------------------------------------------  // acclient.c:815447
int _E88_36()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_4, "DefaultState");
  return atexit(_E89_49);
}

//----- (0071D550) --------------------------------------------------------  // acclient.c:815454
int sub_71D550()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_4, "DisplayHeight");
  return atexit(_E92_58);
}

//----- (0071D570) --------------------------------------------------------  // acclient.c:815461
int _E94_49()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_4, "DisplayWidth");
  return atexit(sub_789E60);
}

//----- (0071D590) --------------------------------------------------------  // acclient.c:815468
int sub_71D590()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_4, "DrawMode");
  return atexit(sub_789E90);
}

//----- (0071D5B0) --------------------------------------------------------  // acclient.c:815475
int sub_71D5B0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_4, "Duration");
  return atexit(sub_789EC0);
}

//----- (0071D5D0) --------------------------------------------------------  // acclient.c:815482
int sub_71D5D0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_4, "Element");
  return atexit(sub_789EF0);
}

//----- (0071D5F0) --------------------------------------------------------  // acclient.c:815489
int sub_71D5F0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_4, "ElementHeader");
  return atexit(sub_789F20);
}

//----- (0071D610) --------------------------------------------------------  // acclient.c:815496
int _E109_97()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_4, "ElementWHeader");
  return atexit(sub_789F50);
}

//----- (0071D630) --------------------------------------------------------  // acclient.c:815503
int sub_71D630()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_4, "ElementID");
  return atexit(_E113_82);
}

//----- (0071D650) --------------------------------------------------------  // acclient.c:815510
int sub_71D650()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_4, "EndAlpha");
  return atexit(_E116_74);
}

//----- (0071D670) --------------------------------------------------------  // acclient.c:815517
int _E118_92()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_4, "EngineType");
  return atexit(_E119_97);
}

//----- (0071D690) --------------------------------------------------------  // acclient.c:815524
int _E121_83()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_4, "EventID");
  return atexit(sub_78A010);
}

//----- (0071D6B0) --------------------------------------------------------  // acclient.c:815531
int _E124_83()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_4, "File");
  return atexit(_E125_77);
}

//----- (0071D6D0) --------------------------------------------------------  // acclient.c:815538
int _E127_70()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_4, "Frames");
  return atexit(_E128_75);
}

//----- (0071D6F0) --------------------------------------------------------  // acclient.c:815545
int _E130_63()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_4, "PREPROC_HEADER");
  return atexit(_E131_64);
}

//----- (0071D710) --------------------------------------------------------  // acclient.c:815552
int _E133_56()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_4, "Height");
  return atexit(_E134_48);
}

//----- (0071D730) --------------------------------------------------------  // acclient.c:815559
int _E136_40()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_4, "JumpItemIndex");
  return atexit(_E137_47);
}

//----- (0071D750) --------------------------------------------------------  // acclient.c:815566
int _E139_40()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_4, "LeftEdge");
  return atexit(_E140_41);
}

//----- (0071D770) --------------------------------------------------------  // acclient.c:815573
int _E142_37()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_4, "MaxDuration");
  return atexit(_E143_41);
}

//----- (0071D790) --------------------------------------------------------  // acclient.c:815580
int _E145_39()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_4, "Media");
  return atexit(_E146_41);
}

//----- (0071D7B0) --------------------------------------------------------  // acclient.c:815587
int _E148_38()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_4, "MediaType");
  return atexit(_E149_40);
}

//----- (0071D7D0) --------------------------------------------------------  // acclient.c:815594
int _E151_36()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_4, "MinDuration");
  return atexit(_E152_41);
}

//----- (0071D7F0) --------------------------------------------------------  // acclient.c:815601
int _E154_37()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_4, "NoDBFile");
  return atexit(_E155_37);
}

//----- (0071D810) --------------------------------------------------------  // acclient.c:815608
int _E157_34()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_4, "StretchToFullScreen");
  return atexit(_E158_38);
}

//----- (0071D830) --------------------------------------------------------  // acclient.c:815615
int _E160_37()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_4, "PassToChildren");
  return atexit(_E161_35);
}

//----- (0071D850) --------------------------------------------------------  // acclient.c:815622
int _E163_30()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_4, "Probability");
  return atexit(_E164_37);
}

//----- (0071D870) --------------------------------------------------------  // acclient.c:815629
int _E166_32()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_5, "Properties");
  return atexit(_E167_33);
}

//----- (0071D890) --------------------------------------------------------  // acclient.c:815636
int _E169_30()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_4, "Remove");
  return atexit(_E170_33);
}

//----- (0071D8B0) --------------------------------------------------------  // acclient.c:815643
int _E172_28()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_4, "RightEdge");
  return atexit(_E173_28);
}

//----- (0071D8D0) --------------------------------------------------------  // acclient.c:815650
int _E175_25()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_4, "SoundName");
  return atexit(_E176_30);
}

//----- (0071D8F0) --------------------------------------------------------  // acclient.c:815657
int _E178_25()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_4, "SoundTable");
  return atexit(_E179_29);
}

//----- (0071D910) --------------------------------------------------------  // acclient.c:815664
int _E181_25()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_4, "StartAlpha");
  return atexit(_E182_29);
}

//----- (0071D930) --------------------------------------------------------  // acclient.c:815671
int _E184_23()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_4, "State");
  return atexit(_E185_26);
}

//----- (0071D950) --------------------------------------------------------  // acclient.c:815678
int _E187_22()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_4, "StateHeader");
  return atexit(_E188_27);
}

//----- (0071D970) --------------------------------------------------------  // acclient.c:815685
int _E190_23()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_4, "StateWHeader");
  return atexit(_E191_26);
}

//----- (0071D990) --------------------------------------------------------  // acclient.c:815692
int _E193_22()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_4, "StateID");
  return atexit(_E194_33);
}

//----- (0071D9B0) --------------------------------------------------------  // acclient.c:815699
int _E196_29()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_4, "TopEdge");
  return atexit(_E197_23);
}

//----- (0071D9D0) --------------------------------------------------------  // acclient.c:815706
int _E199_21()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_4, "Type");
  return atexit(_E200_27);
}

//----- (0071D9F0) --------------------------------------------------------  // acclient.c:815713
int _E202_25()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_4, "Width");
  return atexit(_E203_26);
}

//----- (0071DA10) --------------------------------------------------------  // acclient.c:815720
int _E205_23()
{
  PStringBase<char>::PStringBase<char>(&KW_X_4, "X");
  return atexit(_E206_30);
}

//----- (0071DA30) --------------------------------------------------------  // acclient.c:815727
int _E208_27()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_4, "XHotspot");
  return atexit(_E209_24);
}

//----- (0071DA50) --------------------------------------------------------  // acclient.c:815734
int _E211_22()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_4, "Y");
  return atexit(_E212_27);
}

//----- (0071DA70) --------------------------------------------------------  // acclient.c:815741
int _E214_24()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_4, "YHotspot");
  return atexit(_E215_24);
}

//----- (0071DA90) --------------------------------------------------------  // acclient.c:815748
int _E217_21()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_4, "ZLevel");
  return atexit(_E218_24);
}

//----- (0071DAB0) --------------------------------------------------------  // acclient.c:815755
int _E220_21()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_4, "Comments");
  return atexit(_E221_24);
}

//----- (0071DAD0) --------------------------------------------------------  // acclient.c:815762
int _E223_22()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_4, "HasAlpha");
  return atexit(_E224_24);
}

//----- (00789D10) --------------------------------------------------------  // acclient.c:929678
void __cdecl sub_789D10()
{
  char *v0; // esi@1

  v0 = &KW_NULL_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789D40) --------------------------------------------------------  // acclient.c:929691
void __cdecl sub_789D40()
{
  char *v0; // esi@1

  v0 = &KW_BASE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789D70) --------------------------------------------------------  // acclient.c:929704
void __cdecl _E80_96()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789DA0) --------------------------------------------------------  // acclient.c:929717
void __cdecl _E83_60()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789DD0) --------------------------------------------------------  // acclient.c:929730
void __cdecl _E86_39()
{
  char *v0; // esi@1

  v0 = &KW_CODE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789E00) --------------------------------------------------------  // acclient.c:929743
void __cdecl _E89_49()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789E30) --------------------------------------------------------  // acclient.c:929756
void __cdecl _E92_58()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789E60) --------------------------------------------------------  // acclient.c:929769
void __cdecl sub_789E60()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789E90) --------------------------------------------------------  // acclient.c:929782
void __cdecl sub_789E90()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789EC0) --------------------------------------------------------  // acclient.c:929795
void __cdecl sub_789EC0()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789EF0) --------------------------------------------------------  // acclient.c:929808
void __cdecl sub_789EF0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789F20) --------------------------------------------------------  // acclient.c:929821
void __cdecl sub_789F20()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789F50) --------------------------------------------------------  // acclient.c:929834
void __cdecl sub_789F50()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789F80) --------------------------------------------------------  // acclient.c:929847
void __cdecl _E113_82()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789FB0) --------------------------------------------------------  // acclient.c:929860
void __cdecl _E116_74()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00789FE0) --------------------------------------------------------  // acclient.c:929873
void __cdecl _E119_97()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A010) --------------------------------------------------------  // acclient.c:929886
void __cdecl sub_78A010()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A040) --------------------------------------------------------  // acclient.c:929899
void __cdecl _E125_77()
{
  char *v0; // esi@1

  v0 = &KW_FILE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A070) --------------------------------------------------------  // acclient.c:929912
void __cdecl _E128_75()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A0A0) --------------------------------------------------------  // acclient.c:929925
void __cdecl _E131_64()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A0D0) --------------------------------------------------------  // acclient.c:929938
void __cdecl _E134_48()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A100) --------------------------------------------------------  // acclient.c:929951
void __cdecl _E137_47()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A130) --------------------------------------------------------  // acclient.c:929964
void __cdecl _E140_41()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A160) --------------------------------------------------------  // acclient.c:929977
void __cdecl _E143_41()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A190) --------------------------------------------------------  // acclient.c:929990
void __cdecl _E146_41()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A1C0) --------------------------------------------------------  // acclient.c:930003
void __cdecl _E149_40()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A1F0) --------------------------------------------------------  // acclient.c:930016
void __cdecl _E152_41()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A220) --------------------------------------------------------  // acclient.c:930029
void __cdecl _E155_37()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A250) --------------------------------------------------------  // acclient.c:930042
void __cdecl _E158_38()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A280) --------------------------------------------------------  // acclient.c:930055
void __cdecl _E161_35()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A2B0) --------------------------------------------------------  // acclient.c:930068
void __cdecl _E164_37()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A2E0) --------------------------------------------------------  // acclient.c:930081
void __cdecl _E167_33()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A310) --------------------------------------------------------  // acclient.c:930094
void __cdecl _E170_33()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A340) --------------------------------------------------------  // acclient.c:930107
void __cdecl _E173_28()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A370) --------------------------------------------------------  // acclient.c:930120
void __cdecl _E176_30()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A3A0) --------------------------------------------------------  // acclient.c:930133
void __cdecl _E179_29()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A3D0) --------------------------------------------------------  // acclient.c:930146
void __cdecl _E182_29()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A400) --------------------------------------------------------  // acclient.c:930159
void __cdecl _E185_26()
{
  char *v0; // esi@1

  v0 = &KW_STATE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A430) --------------------------------------------------------  // acclient.c:930172
void __cdecl _E188_27()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A460) --------------------------------------------------------  // acclient.c:930185
void __cdecl _E191_26()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A490) --------------------------------------------------------  // acclient.c:930198
void __cdecl _E194_33()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A4C0) --------------------------------------------------------  // acclient.c:930211
void __cdecl _E197_23()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A4F0) --------------------------------------------------------  // acclient.c:930224
void __cdecl _E200_27()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A520) --------------------------------------------------------  // acclient.c:930237
void __cdecl _E203_26()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A550) --------------------------------------------------------  // acclient.c:930250
void __cdecl _E206_30()
{
  char *v0; // esi@1

  v0 = &KW_X_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A580) --------------------------------------------------------  // acclient.c:930263
void __cdecl _E209_24()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A5B0) --------------------------------------------------------  // acclient.c:930276
void __cdecl _E212_27()
{
  char *v0; // esi@1

  v0 = &KW_Y_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A5E0) --------------------------------------------------------  // acclient.c:930289
void __cdecl _E215_24()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A610) --------------------------------------------------------  // acclient.c:930302
void __cdecl _E218_24()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A640) --------------------------------------------------------  // acclient.c:930315
void __cdecl _E221_24()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078A670) --------------------------------------------------------  // acclient.c:930328
void __cdecl _E224_24()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

