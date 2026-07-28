/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Pause
   Object     : ENGINE\uielement_desc\MD_Data_Pause.obj
   Functions  : 106
   Addresses  : 0069E6E0 - 0078E980 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069E6E0) --------------------------------------------------------  // acclient.c:694713
void __thiscall MD_Data_Pause::MD_Data_Pause(MD_Data_Pause *this)
{
  MD_Data_Pause *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 8u);
  LODWORD(v1->m_minDuration) = 0;
  LODWORD(v1->m_maxDuration) = 0;
  LODWORD(v1->m_endTime) = LODWORD(dbl_801578);
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Pause::vftable;
  HIDWORD(v1->m_endTime) = HIDWORD(dbl_801578);
}
// 801580: using guessed type int (__thiscall *MD_Data_Pause::vftable)(void *, char);

//----- (0069E720) --------------------------------------------------------  // acclient.c:694734
void __thiscall MD_Data_Pause::MD_Data_Pause(MD_Data_Pause *this, MD_Data_Pause *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)v2 = &MD_Data_Pause::vftable;
  *(_QWORD *)(v2 + 16) = *(_QWORD *)&dbl_801578;
  if ( (MD_Data_Pause *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = LODWORD(_rhs->m_minDuration);
    *(_DWORD *)(v2 + 12) = LODWORD(_rhs->m_maxDuration);
  }
}
// 801580: using guessed type int (__thiscall *MD_Data_Pause::vftable)(void *, char);

//----- (0069E770) --------------------------------------------------------  // acclient.c:694754
bool __thiscall MD_Data_Pause::ToFileNode(MD_Data_Pause *this, PFileNode *_file_node)
{
  MD_Data_Pause *v2; // ebx@1
  PStringBase<char> v3; // ST04_4@3
  PFileNode *v4; // eax@3
  PStringBase<char> v5; // ST04_4@5
  PFileNode *v6; // eax@5
  bool result; // al@6

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v3.m_charbuffer = KW_MINDURATION_11.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_MINDURATION_11.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v3)) != 0)
    && PFileNode::MakeSubNodeAsFloat(v4, v2->m_minDuration)
    && (v5.m_charbuffer = KW_MAXDURATION_11.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_MAXDURATION_11.m_charbuffer[-1]),
        (v6 = PFileNode::MakeSubNode(_file_node, v5)) != 0) )
    result = PFileNode::MakeSubNodeAsFloat(v6, v2->m_maxDuration) != 0;
  else
    result = 0;
  return result;
}

//----- (0069E810) --------------------------------------------------------  // acclient.c:694780
char __thiscall MD_Data_Pause::FromFileNode(MD_Data_Pause *this, PFileNode *_file_node)
{
  PFileNode *v2; // ebp@1
  char v3; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // eax@3
  PFileNode *v5; // eax@3
  PFileNode *v6; // esi@3
  int v7; // eax@6
  PStringBase<char> *v8; // ecx@6
  int v9; // eax@12
  PSRefBufferCharData<char> *v10; // ecx@15
  PStringBase<char> *v11; // eax@15
  char *v12; // esi@15
  int v13; // eax@17
  char *v14; // esi@18
  int v15; // edx@20
  char *v16; // esi@21
  int v17; // edx@23
  char v18; // al@25
  PStringBase<char> *v19; // [sp-8h] [bp-2Ch]@9
  PStringBase<char> v20; // [sp-4h] [bp-28h]@3
  unsigned int index; // [sp+10h] [bp-14h]@2
  MD_Data_Pause *v22; // [sp+14h] [bp-10h]@1
  PStringBase<char> rhs; // [sp+18h] [bp-Ch]@15
  PStringBase<char> result; // [sp+1Ch] [bp-8h]@15
  unsigned int num; // [sp+20h] [bp-4h]@2

  v2 = _file_node;
  v22 = this;
  if ( _file_node )
  {
    v3 = 1;
    num = PFileNode::GetNumSubNodes(_file_node);
    index = 0;
    if ( num )
    {
      do
      {
        v4 = v2->vfptr;
        v20.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v5 = (PFileNode *)v4[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, index);
        v6 = v5;
        if ( !v5 )
          goto LABEL_10;
        if ( !PFileNode::IsKeyword(v5, (int)InterlockedDecrement, &KW_MEDIATYPE_11) )
        {
          if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_MINDURATION_11) )
          {
            v7 = PFileNode::GetLeaf(v6);
            if ( v7 && PFileNode::GetNameAsFloat((PFileNode *)v7, (int)InterlockedDecrement, &v22->m_minDuration) )
              goto LABEL_24;
            v20.m_charbuffer = KW_MINDURATION_11.m_charbuffer;
            goto LABEL_9;
          }
          if ( !PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_MAXDURATION_11) )
          {
            _file_node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PFileNode::GetNameAsPString(v6, (int)InterlockedDecrement, (PStringBase<char> *)&_file_node);
            PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
            v20.m_charbuffer = v10;
            v19 = &rhs;
            v11 = operator+(&result, "Unknown Keyword: [", (PStringBase<char> *)&_file_node);
            PStringBase<char>::operator+(v11, &v20, v19);
            PFileNode::ReportError((int)InterlockedDecrement, v6, v20);
            v12 = &result.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v12 )
            {
              v13 = *(_DWORD *)v12;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v13)(v12, 1);
            }
            v14 = &rhs.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v14 )
            {
              v15 = *(_DWORD *)v14;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v15)(v14, 1);
            }
            v16 = (char *)&_file_node[-1].sub_nodes.m_num;
            v3 = 0;
            if ( !InterlockedDecrement((volatile LONG *)&_file_node[-1].m_bProcessed) && v16 )
            {
              v17 = *(_DWORD *)v16;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v17)(v16, 1);
            }
            goto LABEL_24;
          }
          v9 = PFileNode::GetLeaf(v6);
          if ( !v9 || !PFileNode::GetNameAsFloat((PFileNode *)v9, (int)InterlockedDecrement, &v22->m_maxDuration) )
          {
            v20.m_charbuffer = KW_MAXDURATION_11.m_charbuffer;
LABEL_9:
            v19 = v8;
            PStringBase<char>::PStringBase<char>(
              (PStringBase<char> *)&v19,
              "MD_Data_Pause::FromFileNode, %s expects one float");
            PFileNode::ReportError((int)InterlockedDecrement, v6, (PStringBase<char>)v19);
LABEL_10:
            v3 = 0;
            goto LABEL_24;
          }
        }
LABEL_24:
        ++index;
      }
      while ( index < num );
    }
    v18 = v3;
  }
  else
  {
    v18 = 0;
  }
  return v18;
}

//----- (00720150) --------------------------------------------------------  // acclient.c:817929
int sub_720150()
{
  KW_NULL_15.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78E020);
}

//----- (00720170) --------------------------------------------------------  // acclient.c:817937
int sub_720170()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_11, "Base");
  return atexit(sub_78E050);
}

//----- (00720190) --------------------------------------------------------  // acclient.c:817944
int sub_720190()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_11, "BottomEdge");
  return atexit(sub_78E080);
}

//----- (007201B0) --------------------------------------------------------  // acclient.c:817951
int _E82_71()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_11, "Child");
  return atexit(_E83_67);
}

//----- (007201D0) --------------------------------------------------------  // acclient.c:817958
int _E85_54()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_11, "Code");
  return atexit(_E86_46);
}

//----- (007201F0) --------------------------------------------------------  // acclient.c:817965
int _E88_43()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_11, "DefaultState");
  return atexit(_E89_56);
}

//----- (00720210) --------------------------------------------------------  // acclient.c:817972
int sub_720210()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_11, "DisplayHeight");
  return atexit(_E92_65);
}

//----- (00720230) --------------------------------------------------------  // acclient.c:817979
int _E94_56()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_11, "DisplayWidth");
  return atexit(sub_78E170);
}

//----- (00720250) --------------------------------------------------------  // acclient.c:817986
int sub_720250()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_11, "DrawMode");
  return atexit(sub_78E1A0);
}

//----- (00720270) --------------------------------------------------------  // acclient.c:817993
int sub_720270()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_11, "Duration");
  return atexit(sub_78E1D0);
}

//----- (00720290) --------------------------------------------------------  // acclient.c:818000
int sub_720290()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_11, "Element");
  return atexit(sub_78E200);
}

//----- (007202B0) --------------------------------------------------------  // acclient.c:818007
int sub_7202B0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_11, "ElementHeader");
  return atexit(sub_78E230);
}

//----- (007202D0) --------------------------------------------------------  // acclient.c:818014
int sub_7202D0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_11, "ElementWHeader");
  return atexit(sub_78E260);
}

//----- (007202F0) --------------------------------------------------------  // acclient.c:818021
int sub_7202F0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_11, "ElementID");
  return atexit(_E113_89);
}

//----- (00720310) --------------------------------------------------------  // acclient.c:818028
int sub_720310()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_11, "EndAlpha");
  return atexit(_E116_81);
}

//----- (00720330) --------------------------------------------------------  // acclient.c:818035
int sub_720330()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_11, "EngineType");
  return atexit(sub_78E2F0);
}

//----- (00720350) --------------------------------------------------------  // acclient.c:818042
int _E121_90()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_11, "EventID");
  return atexit(sub_78E320);
}

//----- (00720370) --------------------------------------------------------  // acclient.c:818049
int _E124_90()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_11, "File");
  return atexit(_E125_84);
}

//----- (00720390) --------------------------------------------------------  // acclient.c:818056
int _E127_77()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_11, "Frames");
  return atexit(_E128_82);
}

//----- (007203B0) --------------------------------------------------------  // acclient.c:818063
int _E130_70()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_11, "PREPROC_HEADER");
  return atexit(_E131_71);
}

//----- (007203D0) --------------------------------------------------------  // acclient.c:818070
int _E133_63()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_11, "Height");
  return atexit(_E134_55);
}

//----- (007203F0) --------------------------------------------------------  // acclient.c:818077
int _E136_47()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_11, "JumpItemIndex");
  return atexit(_E137_54);
}

//----- (00720410) --------------------------------------------------------  // acclient.c:818084
int _E139_47()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_11, "LeftEdge");
  return atexit(_E140_48);
}

//----- (00720430) --------------------------------------------------------  // acclient.c:818091
int _E142_44()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_11, "MaxDuration");
  return atexit(_E143_48);
}

//----- (00720450) --------------------------------------------------------  // acclient.c:818098
int _E145_46()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_11, "Media");
  return atexit(_E146_48);
}

//----- (00720470) --------------------------------------------------------  // acclient.c:818105
int _E148_45()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_11, "MediaType");
  return atexit(_E149_47);
}

//----- (00720490) --------------------------------------------------------  // acclient.c:818112
int _E151_43()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_11, "MinDuration");
  return atexit(_E152_48);
}

//----- (007204B0) --------------------------------------------------------  // acclient.c:818119
int _E154_44()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_11, "NoDBFile");
  return atexit(_E155_44);
}

//----- (007204D0) --------------------------------------------------------  // acclient.c:818126
int _E157_41()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_11, "StretchToFullScreen");
  return atexit(_E158_45);
}

//----- (007204F0) --------------------------------------------------------  // acclient.c:818133
int _E160_44()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_11, "PassToChildren");
  return atexit(_E161_42);
}

//----- (00720510) --------------------------------------------------------  // acclient.c:818140
int _E163_37()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_11, "Probability");
  return atexit(_E164_44);
}

//----- (00720530) --------------------------------------------------------  // acclient.c:818147
int _E166_39()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_12, "Properties");
  return atexit(_E167_40);
}

//----- (00720550) --------------------------------------------------------  // acclient.c:818154
int _E169_37()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_11, "Remove");
  return atexit(_E170_40);
}

//----- (00720570) --------------------------------------------------------  // acclient.c:818161
int _E172_35()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_11, "RightEdge");
  return atexit(_E173_35);
}

//----- (00720590) --------------------------------------------------------  // acclient.c:818168
int _E175_32()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_11, "SoundName");
  return atexit(_E176_37);
}

//----- (007205B0) --------------------------------------------------------  // acclient.c:818175
int _E178_32()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_11, "SoundTable");
  return atexit(_E179_36);
}

//----- (007205D0) --------------------------------------------------------  // acclient.c:818182
int _E181_32()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_11, "StartAlpha");
  return atexit(_E182_36);
}

//----- (007205F0) --------------------------------------------------------  // acclient.c:818189
int _E184_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_11, "State");
  return atexit(_E185_33);
}

//----- (00720610) --------------------------------------------------------  // acclient.c:818196
int _E187_29()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_11, "StateHeader");
  return atexit(_E188_34);
}

//----- (00720630) --------------------------------------------------------  // acclient.c:818203
int _E190_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_11, "StateWHeader");
  return atexit(_E191_33);
}

//----- (00720650) --------------------------------------------------------  // acclient.c:818210
int _E193_29()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_11, "StateID");
  return atexit(_E194_40);
}

//----- (00720670) --------------------------------------------------------  // acclient.c:818217
int _E196_36()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_11, "TopEdge");
  return atexit(_E197_30);
}

//----- (00720690) --------------------------------------------------------  // acclient.c:818224
int _E199_28()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_11, "Type");
  return atexit(_E200_34);
}

//----- (007206B0) --------------------------------------------------------  // acclient.c:818231
int _E202_32()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_11, "Width");
  return atexit(_E203_33);
}

//----- (007206D0) --------------------------------------------------------  // acclient.c:818238
int _E205_30()
{
  PStringBase<char>::PStringBase<char>(&KW_X_11, "X");
  return atexit(_E206_37);
}

//----- (007206F0) --------------------------------------------------------  // acclient.c:818245
int _E208_34()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_11, "XHotspot");
  return atexit(_E209_31);
}

//----- (00720710) --------------------------------------------------------  // acclient.c:818252
int _E211_29()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_11, "Y");
  return atexit(_E212_34);
}

//----- (00720730) --------------------------------------------------------  // acclient.c:818259
int _E214_31()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_11, "YHotspot");
  return atexit(_E215_31);
}

//----- (00720750) --------------------------------------------------------  // acclient.c:818266
int _E217_28()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_11, "ZLevel");
  return atexit(_E218_31);
}

//----- (00720770) --------------------------------------------------------  // acclient.c:818273
int _E220_28()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_11, "Comments");
  return atexit(_E221_31);
}

//----- (00720790) --------------------------------------------------------  // acclient.c:818280
int _E223_29()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_11, "HasAlpha");
  return atexit(_E224_31);
}

//----- (0078E020) --------------------------------------------------------  // acclient.c:934319
void __cdecl sub_78E020()
{
  char *v0; // esi@1

  v0 = &KW_NULL_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E050) --------------------------------------------------------  // acclient.c:934332
void __cdecl sub_78E050()
{
  char *v0; // esi@1

  v0 = &KW_BASE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E080) --------------------------------------------------------  // acclient.c:934345
void __cdecl sub_78E080()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E0B0) --------------------------------------------------------  // acclient.c:934358
void __cdecl _E83_67()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E0E0) --------------------------------------------------------  // acclient.c:934371
void __cdecl _E86_46()
{
  char *v0; // esi@1

  v0 = &KW_CODE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E110) --------------------------------------------------------  // acclient.c:934384
void __cdecl _E89_56()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E140) --------------------------------------------------------  // acclient.c:934397
void __cdecl _E92_65()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E170) --------------------------------------------------------  // acclient.c:934410
void __cdecl sub_78E170()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E1A0) --------------------------------------------------------  // acclient.c:934423
void __cdecl sub_78E1A0()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E1D0) --------------------------------------------------------  // acclient.c:934436
void __cdecl sub_78E1D0()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E200) --------------------------------------------------------  // acclient.c:934449
void __cdecl sub_78E200()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E230) --------------------------------------------------------  // acclient.c:934462
void __cdecl sub_78E230()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E260) --------------------------------------------------------  // acclient.c:934475
void __cdecl sub_78E260()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E290) --------------------------------------------------------  // acclient.c:934488
void __cdecl _E113_89()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E2C0) --------------------------------------------------------  // acclient.c:934501
void __cdecl _E116_81()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E2F0) --------------------------------------------------------  // acclient.c:934514
void __cdecl sub_78E2F0()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E320) --------------------------------------------------------  // acclient.c:934527
void __cdecl sub_78E320()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E350) --------------------------------------------------------  // acclient.c:934540
void __cdecl _E125_84()
{
  char *v0; // esi@1

  v0 = &KW_FILE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E380) --------------------------------------------------------  // acclient.c:934553
void __cdecl _E128_82()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E3B0) --------------------------------------------------------  // acclient.c:934566
void __cdecl _E131_71()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E3E0) --------------------------------------------------------  // acclient.c:934579
void __cdecl _E134_55()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E410) --------------------------------------------------------  // acclient.c:934592
void __cdecl _E137_54()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E440) --------------------------------------------------------  // acclient.c:934605
void __cdecl _E140_48()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E470) --------------------------------------------------------  // acclient.c:934618
void __cdecl _E143_48()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E4A0) --------------------------------------------------------  // acclient.c:934631
void __cdecl _E146_48()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E4D0) --------------------------------------------------------  // acclient.c:934644
void __cdecl _E149_47()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E500) --------------------------------------------------------  // acclient.c:934657
void __cdecl _E152_48()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E530) --------------------------------------------------------  // acclient.c:934670
void __cdecl _E155_44()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E560) --------------------------------------------------------  // acclient.c:934683
void __cdecl _E158_45()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E590) --------------------------------------------------------  // acclient.c:934696
void __cdecl _E161_42()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E5C0) --------------------------------------------------------  // acclient.c:934709
void __cdecl _E164_44()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E5F0) --------------------------------------------------------  // acclient.c:934722
void __cdecl _E167_40()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E620) --------------------------------------------------------  // acclient.c:934735
void __cdecl _E170_40()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E650) --------------------------------------------------------  // acclient.c:934748
void __cdecl _E173_35()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E680) --------------------------------------------------------  // acclient.c:934761
void __cdecl _E176_37()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E6B0) --------------------------------------------------------  // acclient.c:934774
void __cdecl _E179_36()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E6E0) --------------------------------------------------------  // acclient.c:934787
void __cdecl _E182_36()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E710) --------------------------------------------------------  // acclient.c:934800
void __cdecl _E185_33()
{
  char *v0; // esi@1

  v0 = &KW_STATE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E740) --------------------------------------------------------  // acclient.c:934813
void __cdecl _E188_34()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E770) --------------------------------------------------------  // acclient.c:934826
void __cdecl _E191_33()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E7A0) --------------------------------------------------------  // acclient.c:934839
void __cdecl _E194_40()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E7D0) --------------------------------------------------------  // acclient.c:934852
void __cdecl _E197_30()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E800) --------------------------------------------------------  // acclient.c:934865
void __cdecl _E200_34()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E830) --------------------------------------------------------  // acclient.c:934878
void __cdecl _E203_33()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E860) --------------------------------------------------------  // acclient.c:934891
void __cdecl _E206_37()
{
  char *v0; // esi@1

  v0 = &KW_X_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E890) --------------------------------------------------------  // acclient.c:934904
void __cdecl _E209_31()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E8C0) --------------------------------------------------------  // acclient.c:934917
void __cdecl _E212_34()
{
  char *v0; // esi@1

  v0 = &KW_Y_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E8F0) --------------------------------------------------------  // acclient.c:934930
void __cdecl _E215_31()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E920) --------------------------------------------------------  // acclient.c:934943
void __cdecl _E218_31()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E950) --------------------------------------------------------  // acclient.c:934956
void __cdecl _E221_31()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078E980) --------------------------------------------------------  // acclient.c:934969
void __cdecl _E224_31()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

