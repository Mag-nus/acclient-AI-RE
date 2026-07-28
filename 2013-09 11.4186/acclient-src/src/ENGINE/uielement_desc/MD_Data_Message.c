/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Message
   Object     : ENGINE\uielement_desc\MD_Data_Message.obj
   Functions  : 106
   Addresses  : 0069DCC0 - 0078C330 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069DCC0) --------------------------------------------------------  // acclient.c:694093
void __thiscall MD_Data_Message::MD_Data_Message(MD_Data_Message *this)
{
  MD_Data_Message *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 7u);
  v1->m_messageID = 0;
  LODWORD(v1->m_probability) = 0;
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Message::vftable;
}
// 8012D8: using guessed type int (__thiscall *MD_Data_Message::vftable)(void *, char);

//----- (0069DCE0) --------------------------------------------------------  // acclient.c:694106
void __thiscall MD_Data_Message::MD_Data_Message(MD_Data_Message *this, MD_Data_Message *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Message::vftable;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  if ( (MD_Data_Message *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_messageID;
    *(_DWORD *)(v2 + 12) = LODWORD(_rhs->m_probability);
  }
}
// 8012D8: using guessed type int (__thiscall *MD_Data_Message::vftable)(void *, char);

//----- (0069DD20) --------------------------------------------------------  // acclient.c:694125
bool __thiscall MD_Data_Message::ToFileNode(MD_Data_Message *this, PFileNode *_file_node)
{
  MD_Data_Message *v2; // ebx@1
  PStringBase<char> v3; // ST08_4@3
  PFileNode *v4; // eax@3
  PStringBase<char> v5; // ST08_4@5
  PFileNode *v6; // eax@5
  bool result; // al@6

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v3.m_charbuffer = KW_EVENTID_7.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_EVENTID_7.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v3)) != 0)
    && FileNodeUtils::MakeSubNodeAsEnum(v4, 0x12u, v2->m_messageID)
    && (v5.m_charbuffer = KW_PROBABILITY_7.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_PROBABILITY_7.m_charbuffer[-1]),
        (v6 = PFileNode::MakeSubNode(_file_node, v5)) != 0) )
    result = PFileNode::MakeSubNodeAsFloat(v6, v2->m_probability) != 0;
  else
    result = 0;
  return result;
}

//----- (0069DDC0) --------------------------------------------------------  // acclient.c:694151
char __thiscall MD_Data_Message::FromFileNode(MD_Data_Message *this, PFileNode *_file_node)
{
  PFileNode *v2; // esi@1
  char v3; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // eax@5
  PFileNode *v5; // eax@5
  PFileNode *v6; // esi@5
  int v7; // eax@9
  PSRefBufferCharData<char> *v8; // ecx@9
  int v9; // eax@14
  PStringBase<char> *v10; // ecx@14
  PSRefBufferCharData<char> *v11; // ecx@17
  PStringBase<char> *v12; // eax@17
  char *v13; // esi@17
  int v14; // eax@19
  char *v15; // esi@20
  int v16; // edx@22
  char *v17; // esi@23
  int v18; // edx@25
  char v19; // al@27
  PStringBase<char> *v20; // [sp-8h] [bp-30h]@16
  PStringBase<char> v21; // [sp-4h] [bp-2Ch]@5
  PStringBase<char> strName; // [sp+10h] [bp-18h]@17
  unsigned int index; // [sp+14h] [bp-14h]@2
  MD_Data_Message *v24; // [sp+18h] [bp-10h]@1
  PStringBase<char> rhs; // [sp+1Ch] [bp-Ch]@17
  PStringBase<char> result; // [sp+20h] [bp-8h]@17
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
        if ( v5 )
        {
          if ( !PFileNode::IsKeyword(v5, (int)InterlockedDecrement, &KW_MEDIATYPE_7) )
          {
            if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_EVENTID_7) )
            {
              v7 = PFileNode::GetLeaf(v6);
              if ( v7 )
              {
                if ( !FileNodeUtils::GetNameAsEnum((PFileNode *)v7, 0x12u, &v24->m_messageID) )
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
            else if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_PROBABILITY_7) )
            {
              v9 = PFileNode::GetLeaf(v6);
              if ( !v9 || !PFileNode::GetNameAsFloat((PFileNode *)v9, (int)InterlockedDecrement, &v24->m_probability) )
              {
                v21.m_charbuffer = KW_PROBABILITY_7.m_charbuffer;
                v20 = v10;
                PStringBase<char>::PStringBase<char>(
                  (PStringBase<char> *)&v20,
                  "MD_Data_Message::FromFileNode, %s expects one float");
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
        }
        else
        {
          v3 = 0;
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

//----- (0071E7C0) --------------------------------------------------------  // acclient.c:816491
int sub_71E7C0()
{
  KW_NULL_11.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78B9D0);
}

//----- (0071E7E0) --------------------------------------------------------  // acclient.c:816499
int sub_71E7E0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_7, "Base");
  return atexit(sub_78BA00);
}

//----- (0071E800) --------------------------------------------------------  // acclient.c:816506
int sub_71E800()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_7, "BottomEdge");
  return atexit(sub_78BA30);
}

//----- (0071E820) --------------------------------------------------------  // acclient.c:816513
int _E82_67()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_7, "Child");
  return atexit(_E83_63);
}

//----- (0071E840) --------------------------------------------------------  // acclient.c:816520
int _E85_50()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_7, "Code");
  return atexit(_E86_42);
}

//----- (0071E860) --------------------------------------------------------  // acclient.c:816527
int _E88_39()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_7, "DefaultState");
  return atexit(_E89_52);
}

//----- (0071E880) --------------------------------------------------------  // acclient.c:816534
int sub_71E880()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_7, "DisplayHeight");
  return atexit(_E92_61);
}

//----- (0071E8A0) --------------------------------------------------------  // acclient.c:816541
int _E94_52()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_7, "DisplayWidth");
  return atexit(sub_78BB20);
}

//----- (0071E8C0) --------------------------------------------------------  // acclient.c:816548
int sub_71E8C0()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_7, "DrawMode");
  return atexit(sub_78BB50);
}

//----- (0071E8E0) --------------------------------------------------------  // acclient.c:816555
int sub_71E8E0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_7, "Duration");
  return atexit(sub_78BB80);
}

//----- (0071E900) --------------------------------------------------------  // acclient.c:816562
int sub_71E900()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_7, "Element");
  return atexit(sub_78BBB0);
}

//----- (0071E920) --------------------------------------------------------  // acclient.c:816569
int sub_71E920()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_7, "ElementHeader");
  return atexit(sub_78BBE0);
}

//----- (0071E940) --------------------------------------------------------  // acclient.c:816576
int sub_71E940()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_7, "ElementWHeader");
  return atexit(sub_78BC10);
}

//----- (0071E960) --------------------------------------------------------  // acclient.c:816583
int sub_71E960()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_7, "ElementID");
  return atexit(_E113_85);
}

//----- (0071E980) --------------------------------------------------------  // acclient.c:816590
int sub_71E980()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_7, "EndAlpha");
  return atexit(_E116_77);
}

//----- (0071E9A0) --------------------------------------------------------  // acclient.c:816597
int _E118_95()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_7, "EngineType");
  return atexit(sub_78BCA0);
}

//----- (0071E9C0) --------------------------------------------------------  // acclient.c:816604
int _E121_86()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_7, "EventID");
  return atexit(sub_78BCD0);
}

//----- (0071E9E0) --------------------------------------------------------  // acclient.c:816611
int _E124_86()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_7, "File");
  return atexit(_E125_80);
}

//----- (0071EA00) --------------------------------------------------------  // acclient.c:816618
int _E127_73()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_7, "Frames");
  return atexit(_E128_78);
}

//----- (0071EA20) --------------------------------------------------------  // acclient.c:816625
int _E130_66()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_7, "PREPROC_HEADER");
  return atexit(_E131_67);
}

//----- (0071EA40) --------------------------------------------------------  // acclient.c:816632
int _E133_59()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_7, "Height");
  return atexit(_E134_51);
}

//----- (0071EA60) --------------------------------------------------------  // acclient.c:816639
int _E136_43()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_7, "JumpItemIndex");
  return atexit(_E137_50);
}

//----- (0071EA80) --------------------------------------------------------  // acclient.c:816646
int _E139_43()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_7, "LeftEdge");
  return atexit(_E140_44);
}

//----- (0071EAA0) --------------------------------------------------------  // acclient.c:816653
int _E142_40()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_7, "MaxDuration");
  return atexit(_E143_44);
}

//----- (0071EAC0) --------------------------------------------------------  // acclient.c:816660
int _E145_42()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_7, "Media");
  return atexit(_E146_44);
}

//----- (0071EAE0) --------------------------------------------------------  // acclient.c:816667
int _E148_41()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_7, "MediaType");
  return atexit(_E149_43);
}

//----- (0071EB00) --------------------------------------------------------  // acclient.c:816674
int _E151_39()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_7, "MinDuration");
  return atexit(_E152_44);
}

//----- (0071EB20) --------------------------------------------------------  // acclient.c:816681
int _E154_40()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_7, "NoDBFile");
  return atexit(_E155_40);
}

//----- (0071EB40) --------------------------------------------------------  // acclient.c:816688
int _E157_37()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_7, "StretchToFullScreen");
  return atexit(_E158_41);
}

//----- (0071EB60) --------------------------------------------------------  // acclient.c:816695
int _E160_40()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_7, "PassToChildren");
  return atexit(_E161_38);
}

//----- (0071EB80) --------------------------------------------------------  // acclient.c:816702
int _E163_33()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_7, "Probability");
  return atexit(_E164_40);
}

//----- (0071EBA0) --------------------------------------------------------  // acclient.c:816709
int _E166_35()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_8, "Properties");
  return atexit(_E167_36);
}

//----- (0071EBC0) --------------------------------------------------------  // acclient.c:816716
int _E169_33()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_7, "Remove");
  return atexit(_E170_36);
}

//----- (0071EBE0) --------------------------------------------------------  // acclient.c:816723
int _E172_31()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_7, "RightEdge");
  return atexit(_E173_31);
}

//----- (0071EC00) --------------------------------------------------------  // acclient.c:816730
int _E175_28()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_7, "SoundName");
  return atexit(_E176_33);
}

//----- (0071EC20) --------------------------------------------------------  // acclient.c:816737
int _E178_28()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_7, "SoundTable");
  return atexit(_E179_32);
}

//----- (0071EC40) --------------------------------------------------------  // acclient.c:816744
int _E181_28()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_7, "StartAlpha");
  return atexit(_E182_32);
}

//----- (0071EC60) --------------------------------------------------------  // acclient.c:816751
int _E184_26()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_7, "State");
  return atexit(_E185_29);
}

//----- (0071EC80) --------------------------------------------------------  // acclient.c:816758
int _E187_25()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_7, "StateHeader");
  return atexit(_E188_30);
}

//----- (0071ECA0) --------------------------------------------------------  // acclient.c:816765
int _E190_26()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_7, "StateWHeader");
  return atexit(_E191_29);
}

//----- (0071ECC0) --------------------------------------------------------  // acclient.c:816772
int _E193_25()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_7, "StateID");
  return atexit(_E194_36);
}

//----- (0071ECE0) --------------------------------------------------------  // acclient.c:816779
int _E196_32()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_7, "TopEdge");
  return atexit(_E197_26);
}

//----- (0071ED00) --------------------------------------------------------  // acclient.c:816786
int _E199_24()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_7, "Type");
  return atexit(_E200_30);
}

//----- (0071ED20) --------------------------------------------------------  // acclient.c:816793
int _E202_28()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_7, "Width");
  return atexit(_E203_29);
}

//----- (0071ED40) --------------------------------------------------------  // acclient.c:816800
int _E205_26()
{
  PStringBase<char>::PStringBase<char>(&KW_X_7, "X");
  return atexit(_E206_33);
}

//----- (0071ED60) --------------------------------------------------------  // acclient.c:816807
int _E208_30()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_7, "XHotspot");
  return atexit(_E209_27);
}

//----- (0071ED80) --------------------------------------------------------  // acclient.c:816814
int _E211_25()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_7, "Y");
  return atexit(_E212_30);
}

//----- (0071EDA0) --------------------------------------------------------  // acclient.c:816821
int _E214_27()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_7, "YHotspot");
  return atexit(_E215_27);
}

//----- (0071EDC0) --------------------------------------------------------  // acclient.c:816828
int _E217_24()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_7, "ZLevel");
  return atexit(_E218_27);
}

//----- (0071EDE0) --------------------------------------------------------  // acclient.c:816835
int _E220_24()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_7, "Comments");
  return atexit(_E221_27);
}

//----- (0071EE00) --------------------------------------------------------  // acclient.c:816842
int _E223_25()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_7, "HasAlpha");
  return atexit(_E224_27);
}

//----- (0078B9D0) --------------------------------------------------------  // acclient.c:931667
void __cdecl sub_78B9D0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BA00) --------------------------------------------------------  // acclient.c:931680
void __cdecl sub_78BA00()
{
  char *v0; // esi@1

  v0 = &KW_BASE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BA30) --------------------------------------------------------  // acclient.c:931693
void __cdecl sub_78BA30()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BA60) --------------------------------------------------------  // acclient.c:931706
void __cdecl _E83_63()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BA90) --------------------------------------------------------  // acclient.c:931719
void __cdecl _E86_42()
{
  char *v0; // esi@1

  v0 = &KW_CODE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BAC0) --------------------------------------------------------  // acclient.c:931732
void __cdecl _E89_52()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BAF0) --------------------------------------------------------  // acclient.c:931745
void __cdecl _E92_61()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BB20) --------------------------------------------------------  // acclient.c:931758
void __cdecl sub_78BB20()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BB50) --------------------------------------------------------  // acclient.c:931771
void __cdecl sub_78BB50()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BB80) --------------------------------------------------------  // acclient.c:931784
void __cdecl sub_78BB80()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BBB0) --------------------------------------------------------  // acclient.c:931797
void __cdecl sub_78BBB0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BBE0) --------------------------------------------------------  // acclient.c:931810
void __cdecl sub_78BBE0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BC10) --------------------------------------------------------  // acclient.c:931823
void __cdecl sub_78BC10()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BC40) --------------------------------------------------------  // acclient.c:931836
void __cdecl _E113_85()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BC70) --------------------------------------------------------  // acclient.c:931849
void __cdecl _E116_77()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BCA0) --------------------------------------------------------  // acclient.c:931862
void __cdecl sub_78BCA0()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BCD0) --------------------------------------------------------  // acclient.c:931875
void __cdecl sub_78BCD0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BD00) --------------------------------------------------------  // acclient.c:931888
void __cdecl _E125_80()
{
  char *v0; // esi@1

  v0 = &KW_FILE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BD30) --------------------------------------------------------  // acclient.c:931901
void __cdecl _E128_78()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BD60) --------------------------------------------------------  // acclient.c:931914
void __cdecl _E131_67()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BD90) --------------------------------------------------------  // acclient.c:931927
void __cdecl _E134_51()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BDC0) --------------------------------------------------------  // acclient.c:931940
void __cdecl _E137_50()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BDF0) --------------------------------------------------------  // acclient.c:931953
void __cdecl _E140_44()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BE20) --------------------------------------------------------  // acclient.c:931966
void __cdecl _E143_44()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BE50) --------------------------------------------------------  // acclient.c:931979
void __cdecl _E146_44()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BE80) --------------------------------------------------------  // acclient.c:931992
void __cdecl _E149_43()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BEB0) --------------------------------------------------------  // acclient.c:932005
void __cdecl _E152_44()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BEE0) --------------------------------------------------------  // acclient.c:932018
void __cdecl _E155_40()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BF10) --------------------------------------------------------  // acclient.c:932031
void __cdecl _E158_41()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BF40) --------------------------------------------------------  // acclient.c:932044
void __cdecl _E161_38()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BF70) --------------------------------------------------------  // acclient.c:932057
void __cdecl _E164_40()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BFA0) --------------------------------------------------------  // acclient.c:932070
void __cdecl _E167_36()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078BFD0) --------------------------------------------------------  // acclient.c:932083
void __cdecl _E170_36()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C000) --------------------------------------------------------  // acclient.c:932096
void __cdecl _E173_31()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C030) --------------------------------------------------------  // acclient.c:932109
void __cdecl _E176_33()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C060) --------------------------------------------------------  // acclient.c:932122
void __cdecl _E179_32()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C090) --------------------------------------------------------  // acclient.c:932135
void __cdecl _E182_32()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C0C0) --------------------------------------------------------  // acclient.c:932148
void __cdecl _E185_29()
{
  char *v0; // esi@1

  v0 = &KW_STATE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C0F0) --------------------------------------------------------  // acclient.c:932161
void __cdecl _E188_30()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C120) --------------------------------------------------------  // acclient.c:932174
void __cdecl _E191_29()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C150) --------------------------------------------------------  // acclient.c:932187
void __cdecl _E194_36()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C180) --------------------------------------------------------  // acclient.c:932200
void __cdecl _E197_26()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C1B0) --------------------------------------------------------  // acclient.c:932213
void __cdecl _E200_30()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C1E0) --------------------------------------------------------  // acclient.c:932226
void __cdecl _E203_29()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C210) --------------------------------------------------------  // acclient.c:932239
void __cdecl _E206_33()
{
  char *v0; // esi@1

  v0 = &KW_X_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C240) --------------------------------------------------------  // acclient.c:932252
void __cdecl _E209_27()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C270) --------------------------------------------------------  // acclient.c:932265
void __cdecl _E212_30()
{
  char *v0; // esi@1

  v0 = &KW_Y_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C2A0) --------------------------------------------------------  // acclient.c:932278
void __cdecl _E215_27()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C2D0) --------------------------------------------------------  // acclient.c:932291
void __cdecl _E218_27()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C300) --------------------------------------------------------  // acclient.c:932304
void __cdecl _E221_27()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078C330) --------------------------------------------------------  // acclient.c:932317
void __cdecl _E224_27()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

