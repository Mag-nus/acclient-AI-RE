/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MD_Data_Jump
   Object     : ENGINE\uielement_desc\MD_Data_Jump.obj
   Functions  : 106
   Addresses  : 0069E310 - 0078D650 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069E310) --------------------------------------------------------  // acclient.c:694466
void __thiscall MD_Data_Jump::MD_Data_Jump(MD_Data_Jump *this)
{
  MD_Data_Jump *v1; // esi@1

  v1 = this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr, 6u);
  v1->m_jumpItemIndex = 0;
  LODWORD(v1->m_probability) = 0;
  v1->vfptr = (MediaDescVtbl *)&MD_Data_Jump::vftable;
}
// 801430: using guessed type int (__thiscall *MD_Data_Jump::vftable)(void *, char);

//----- (0069E330) --------------------------------------------------------  // acclient.c:694479
void __thiscall MD_Data_Jump::MD_Data_Jump(MD_Data_Jump *this, MD_Data_Jump *_rhs)
{
  int v2; // esi@1

  v2 = (int)this;
  MediaDesc::MediaDesc((MediaDesc *)&this->vfptr);
  *(_DWORD *)v2 = &MD_Data_Jump::vftable;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  if ( (MD_Data_Jump *)v2 != _rhs )
  {
    MediaDesc::operator=(v2, (int)_rhs);
    *(_DWORD *)(v2 + 8) = _rhs->m_jumpItemIndex;
    *(_DWORD *)(v2 + 12) = LODWORD(_rhs->m_probability);
  }
}
// 801430: using guessed type int (__thiscall *MD_Data_Jump::vftable)(void *, char);

//----- (0069E370) --------------------------------------------------------  // acclient.c:694498
bool __thiscall MD_Data_Jump::ToFileNode(MD_Data_Jump *this, PFileNode *_file_node)
{
  MD_Data_Jump *v2; // ebx@1
  PStringBase<char> v3; // ST04_4@3
  PFileNode *v4; // eax@3
  PStringBase<char> v5; // ST04_4@5
  PFileNode *v6; // eax@5
  bool result; // al@6

  v2 = this;
  if ( _file_node
    && MediaDesc::ToFileNode((MediaDesc *)&this->vfptr, _file_node)
    && (v3.m_charbuffer = KW_JUMPITEMINDEX_9.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_JUMPITEMINDEX_9.m_charbuffer[-1]),
        (v4 = PFileNode::MakeSubNode(_file_node, v3)) != 0)
    && PFileNode::MakeSubNodeAsUInt32(v4, v2->m_jumpItemIndex)
    && (v5.m_charbuffer = KW_PROBABILITY_9.m_charbuffer,
        InterlockedIncrement((volatile LONG *)&KW_PROBABILITY_9.m_charbuffer[-1]),
        (v6 = PFileNode::MakeSubNode(_file_node, v5)) != 0) )
    result = PFileNode::MakeSubNodeAsFloat(v6, v2->m_probability) != 0;
  else
    result = 0;
  return result;
}

//----- (0069E410) --------------------------------------------------------  // acclient.c:694524
char __thiscall MD_Data_Jump::FromFileNode(MD_Data_Jump *this, PFileNode *_file_node)
{
  PFileNode *v2; // ebp@1
  char v3; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v4; // eax@3
  PFileNode *v5; // eax@3
  PFileNode *v6; // esi@3
  int v7; // eax@6
  PStringBase<char> *v8; // ecx@6
  int v9; // eax@12
  PStringBase<char> *v10; // ecx@12
  PSRefBufferCharData<char> *v11; // ecx@15
  PStringBase<char> *v12; // eax@15
  char *v13; // esi@15
  int v14; // eax@17
  char *v15; // esi@18
  int v16; // edx@20
  char *v17; // esi@21
  int v18; // edx@23
  char v19; // al@25
  PStringBase<char> *v20; // [sp-8h] [bp-2Ch]@8
  PStringBase<char> v21; // [sp-4h] [bp-28h]@3
  unsigned int index; // [sp+10h] [bp-14h]@2
  MD_Data_Jump *v23; // [sp+14h] [bp-10h]@1
  PStringBase<char> rhs; // [sp+18h] [bp-Ch]@15
  PStringBase<char> result; // [sp+1Ch] [bp-8h]@15
  unsigned int num; // [sp+20h] [bp-4h]@2

  v2 = _file_node;
  v23 = this;
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
        v21.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v5 = (PFileNode *)v4[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, index);
        v6 = v5;
        if ( !v5 )
          goto LABEL_10;
        if ( !PFileNode::IsKeyword(v5, (int)InterlockedDecrement, &KW_MEDIATYPE_9) )
        {
          if ( PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_JUMPITEMINDEX_9) )
          {
            v7 = PFileNode::GetLeaf(v6);
            if ( v7 && PFileNode::GetNameAsUInt32((PFileNode *)v7, (int)InterlockedDecrement, &v23->m_jumpItemIndex) )
              goto LABEL_24;
            v21.m_charbuffer = KW_JUMPITEMINDEX_9.m_charbuffer;
            v20 = v8;
            PStringBase<char>::PStringBase<char>(
              (PStringBase<char> *)&v20,
              "MD_Data_Jump::FromFileNode, %s expects one uint32");
            goto LABEL_9;
          }
          if ( !PFileNode::IsKeyword(v6, (int)InterlockedDecrement, &KW_PROBABILITY_9) )
          {
            _file_node = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PFileNode::GetNameAsPString(v6, (int)InterlockedDecrement, (PStringBase<char> *)&_file_node);
            PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
            v21.m_charbuffer = v11;
            v20 = &rhs;
            v12 = operator+(&result, "Unknown Keyword: [", (PStringBase<char> *)&_file_node);
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
            v17 = (char *)&_file_node[-1].sub_nodes.m_num;
            v3 = 0;
            if ( !InterlockedDecrement((volatile LONG *)&_file_node[-1].m_bProcessed) && v17 )
            {
              v18 = *(_DWORD *)v17;
              v21.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v18)(v17, 1);
            }
            goto LABEL_24;
          }
          v9 = PFileNode::GetLeaf(v6);
          if ( !v9 || !PFileNode::GetNameAsFloat((PFileNode *)v9, (int)InterlockedDecrement, &v23->m_probability) )
          {
            v21.m_charbuffer = KW_PROBABILITY_9.m_charbuffer;
            v20 = v10;
            PStringBase<char>::PStringBase<char>(
              (PStringBase<char> *)&v20,
              "MD_Data_Jump::FromFileNode, %s expects one float");
LABEL_9:
            PFileNode::ReportError((int)InterlockedDecrement, v6, (PStringBase<char>)v20);
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
    v19 = v3;
  }
  else
  {
    v19 = 0;
  }
  return v19;
}

//----- (0071F480) --------------------------------------------------------  // acclient.c:817207
int sub_71F480()
{
  KW_NULL_13.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_78CCF0);
}

//----- (0071F4A0) --------------------------------------------------------  // acclient.c:817215
int sub_71F4A0()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_9, "Base");
  return atexit(sub_78CD20);
}

//----- (0071F4C0) --------------------------------------------------------  // acclient.c:817222
int sub_71F4C0()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_9, "BottomEdge");
  return atexit(sub_78CD50);
}

//----- (0071F4E0) --------------------------------------------------------  // acclient.c:817229
int _E82_69()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_9, "Child");
  return atexit(_E83_65);
}

//----- (0071F500) --------------------------------------------------------  // acclient.c:817236
int _E85_52()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_9, "Code");
  return atexit(_E86_44);
}

//----- (0071F520) --------------------------------------------------------  // acclient.c:817243
int _E88_41()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_9, "DefaultState");
  return atexit(_E89_54);
}

//----- (0071F540) --------------------------------------------------------  // acclient.c:817250
int sub_71F540()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_9, "DisplayHeight");
  return atexit(_E92_63);
}

//----- (0071F560) --------------------------------------------------------  // acclient.c:817257
int _E94_54()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_9, "DisplayWidth");
  return atexit(sub_78CE40);
}

//----- (0071F580) --------------------------------------------------------  // acclient.c:817264
int sub_71F580()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_9, "DrawMode");
  return atexit(sub_78CE70);
}

//----- (0071F5A0) --------------------------------------------------------  // acclient.c:817271
int sub_71F5A0()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_9, "Duration");
  return atexit(sub_78CEA0);
}

//----- (0071F5C0) --------------------------------------------------------  // acclient.c:817278
int sub_71F5C0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_9, "Element");
  return atexit(sub_78CED0);
}

//----- (0071F5E0) --------------------------------------------------------  // acclient.c:817285
int sub_71F5E0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_9, "ElementHeader");
  return atexit(sub_78CF00);
}

//----- (0071F600) --------------------------------------------------------  // acclient.c:817292
int sub_71F600()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_9, "ElementWHeader");
  return atexit(sub_78CF30);
}

//----- (0071F620) --------------------------------------------------------  // acclient.c:817299
int sub_71F620()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_9, "ElementID");
  return atexit(_E113_87);
}

//----- (0071F640) --------------------------------------------------------  // acclient.c:817306
int sub_71F640()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_9, "EndAlpha");
  return atexit(_E116_79);
}

//----- (0071F660) --------------------------------------------------------  // acclient.c:817313
int _E118_97()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_9, "EngineType");
  return atexit(sub_78CFC0);
}

//----- (0071F680) --------------------------------------------------------  // acclient.c:817320
int _E121_88()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_9, "EventID");
  return atexit(sub_78CFF0);
}

//----- (0071F6A0) --------------------------------------------------------  // acclient.c:817327
int _E124_88()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_9, "File");
  return atexit(_E125_82);
}

//----- (0071F6C0) --------------------------------------------------------  // acclient.c:817334
int _E127_75()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_9, "Frames");
  return atexit(_E128_80);
}

//----- (0071F6E0) --------------------------------------------------------  // acclient.c:817341
int _E130_68()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_9, "PREPROC_HEADER");
  return atexit(_E131_69);
}

//----- (0071F700) --------------------------------------------------------  // acclient.c:817348
int _E133_61()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_9, "Height");
  return atexit(_E134_53);
}

//----- (0071F720) --------------------------------------------------------  // acclient.c:817355
int _E136_45()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_9, "JumpItemIndex");
  return atexit(_E137_52);
}

//----- (0071F740) --------------------------------------------------------  // acclient.c:817362
int _E139_45()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_9, "LeftEdge");
  return atexit(_E140_46);
}

//----- (0071F760) --------------------------------------------------------  // acclient.c:817369
int _E142_42()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_9, "MaxDuration");
  return atexit(_E143_46);
}

//----- (0071F780) --------------------------------------------------------  // acclient.c:817376
int _E145_44()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_9, "Media");
  return atexit(_E146_46);
}

//----- (0071F7A0) --------------------------------------------------------  // acclient.c:817383
int _E148_43()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_9, "MediaType");
  return atexit(_E149_45);
}

//----- (0071F7C0) --------------------------------------------------------  // acclient.c:817390
int _E151_41()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_9, "MinDuration");
  return atexit(_E152_46);
}

//----- (0071F7E0) --------------------------------------------------------  // acclient.c:817397
int _E154_42()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_9, "NoDBFile");
  return atexit(_E155_42);
}

//----- (0071F800) --------------------------------------------------------  // acclient.c:817404
int _E157_39()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_9, "StretchToFullScreen");
  return atexit(_E158_43);
}

//----- (0071F820) --------------------------------------------------------  // acclient.c:817411
int _E160_42()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_9, "PassToChildren");
  return atexit(_E161_40);
}

//----- (0071F840) --------------------------------------------------------  // acclient.c:817418
int _E163_35()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_9, "Probability");
  return atexit(_E164_42);
}

//----- (0071F860) --------------------------------------------------------  // acclient.c:817425
int _E166_37()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_10, "Properties");
  return atexit(_E167_38);
}

//----- (0071F880) --------------------------------------------------------  // acclient.c:817432
int _E169_35()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_9, "Remove");
  return atexit(_E170_38);
}

//----- (0071F8A0) --------------------------------------------------------  // acclient.c:817439
int _E172_33()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_9, "RightEdge");
  return atexit(_E173_33);
}

//----- (0071F8C0) --------------------------------------------------------  // acclient.c:817446
int _E175_30()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_9, "SoundName");
  return atexit(_E176_35);
}

//----- (0071F8E0) --------------------------------------------------------  // acclient.c:817453
int _E178_30()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_9, "SoundTable");
  return atexit(_E179_34);
}

//----- (0071F900) --------------------------------------------------------  // acclient.c:817460
int _E181_30()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_9, "StartAlpha");
  return atexit(_E182_34);
}

//----- (0071F920) --------------------------------------------------------  // acclient.c:817467
int _E184_28()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_9, "State");
  return atexit(_E185_31);
}

//----- (0071F940) --------------------------------------------------------  // acclient.c:817474
int _E187_27()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_9, "StateHeader");
  return atexit(_E188_32);
}

//----- (0071F960) --------------------------------------------------------  // acclient.c:817481
int _E190_28()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_9, "StateWHeader");
  return atexit(_E191_31);
}

//----- (0071F980) --------------------------------------------------------  // acclient.c:817488
int _E193_27()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_9, "StateID");
  return atexit(_E194_38);
}

//----- (0071F9A0) --------------------------------------------------------  // acclient.c:817495
int _E196_34()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_9, "TopEdge");
  return atexit(_E197_28);
}

//----- (0071F9C0) --------------------------------------------------------  // acclient.c:817502
int _E199_26()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_9, "Type");
  return atexit(_E200_32);
}

//----- (0071F9E0) --------------------------------------------------------  // acclient.c:817509
int _E202_30()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_9, "Width");
  return atexit(_E203_31);
}

//----- (0071FA00) --------------------------------------------------------  // acclient.c:817516
int _E205_28()
{
  PStringBase<char>::PStringBase<char>(&KW_X_9, "X");
  return atexit(_E206_35);
}

//----- (0071FA20) --------------------------------------------------------  // acclient.c:817523
int _E208_32()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_9, "XHotspot");
  return atexit(_E209_29);
}

//----- (0071FA40) --------------------------------------------------------  // acclient.c:817530
int _E211_27()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_9, "Y");
  return atexit(_E212_32);
}

//----- (0071FA60) --------------------------------------------------------  // acclient.c:817537
int _E214_29()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_9, "YHotspot");
  return atexit(_E215_29);
}

//----- (0071FA80) --------------------------------------------------------  // acclient.c:817544
int _E217_26()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_9, "ZLevel");
  return atexit(_E218_29);
}

//----- (0071FAA0) --------------------------------------------------------  // acclient.c:817551
int _E220_26()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_9, "Comments");
  return atexit(_E221_29);
}

//----- (0071FAC0) --------------------------------------------------------  // acclient.c:817558
int _E223_27()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_9, "HasAlpha");
  return atexit(_E224_29);
}

//----- (0078CCF0) --------------------------------------------------------  // acclient.c:932993
void __cdecl sub_78CCF0()
{
  char *v0; // esi@1

  v0 = &KW_NULL_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CD20) --------------------------------------------------------  // acclient.c:933006
void __cdecl sub_78CD20()
{
  char *v0; // esi@1

  v0 = &KW_BASE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CD50) --------------------------------------------------------  // acclient.c:933019
void __cdecl sub_78CD50()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CD80) --------------------------------------------------------  // acclient.c:933032
void __cdecl _E83_65()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CDB0) --------------------------------------------------------  // acclient.c:933045
void __cdecl _E86_44()
{
  char *v0; // esi@1

  v0 = &KW_CODE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CDE0) --------------------------------------------------------  // acclient.c:933058
void __cdecl _E89_54()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CE10) --------------------------------------------------------  // acclient.c:933071
void __cdecl _E92_63()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CE40) --------------------------------------------------------  // acclient.c:933084
void __cdecl sub_78CE40()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CE70) --------------------------------------------------------  // acclient.c:933097
void __cdecl sub_78CE70()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CEA0) --------------------------------------------------------  // acclient.c:933110
void __cdecl sub_78CEA0()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CED0) --------------------------------------------------------  // acclient.c:933123
void __cdecl sub_78CED0()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CF00) --------------------------------------------------------  // acclient.c:933136
void __cdecl sub_78CF00()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CF30) --------------------------------------------------------  // acclient.c:933149
void __cdecl sub_78CF30()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CF60) --------------------------------------------------------  // acclient.c:933162
void __cdecl _E113_87()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CF90) --------------------------------------------------------  // acclient.c:933175
void __cdecl _E116_79()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CFC0) --------------------------------------------------------  // acclient.c:933188
void __cdecl sub_78CFC0()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078CFF0) --------------------------------------------------------  // acclient.c:933201
void __cdecl sub_78CFF0()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D020) --------------------------------------------------------  // acclient.c:933214
void __cdecl _E125_82()
{
  char *v0; // esi@1

  v0 = &KW_FILE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D050) --------------------------------------------------------  // acclient.c:933227
void __cdecl _E128_80()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D080) --------------------------------------------------------  // acclient.c:933240
void __cdecl _E131_69()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D0B0) --------------------------------------------------------  // acclient.c:933253
void __cdecl _E134_53()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D0E0) --------------------------------------------------------  // acclient.c:933266
void __cdecl _E137_52()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D110) --------------------------------------------------------  // acclient.c:933279
void __cdecl _E140_46()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D140) --------------------------------------------------------  // acclient.c:933292
void __cdecl _E143_46()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D170) --------------------------------------------------------  // acclient.c:933305
void __cdecl _E146_46()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D1A0) --------------------------------------------------------  // acclient.c:933318
void __cdecl _E149_45()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D1D0) --------------------------------------------------------  // acclient.c:933331
void __cdecl _E152_46()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D200) --------------------------------------------------------  // acclient.c:933344
void __cdecl _E155_42()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D230) --------------------------------------------------------  // acclient.c:933357
void __cdecl _E158_43()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D260) --------------------------------------------------------  // acclient.c:933370
void __cdecl _E161_40()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D290) --------------------------------------------------------  // acclient.c:933383
void __cdecl _E164_42()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D2C0) --------------------------------------------------------  // acclient.c:933396
void __cdecl _E167_38()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D2F0) --------------------------------------------------------  // acclient.c:933409
void __cdecl _E170_38()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D320) --------------------------------------------------------  // acclient.c:933422
void __cdecl _E173_33()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D350) --------------------------------------------------------  // acclient.c:933435
void __cdecl _E176_35()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D380) --------------------------------------------------------  // acclient.c:933448
void __cdecl _E179_34()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D3B0) --------------------------------------------------------  // acclient.c:933461
void __cdecl _E182_34()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D3E0) --------------------------------------------------------  // acclient.c:933474
void __cdecl _E185_31()
{
  char *v0; // esi@1

  v0 = &KW_STATE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D410) --------------------------------------------------------  // acclient.c:933487
void __cdecl _E188_32()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D440) --------------------------------------------------------  // acclient.c:933500
void __cdecl _E191_31()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D470) --------------------------------------------------------  // acclient.c:933513
void __cdecl _E194_38()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D4A0) --------------------------------------------------------  // acclient.c:933526
void __cdecl _E197_28()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D4D0) --------------------------------------------------------  // acclient.c:933539
void __cdecl _E200_32()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D500) --------------------------------------------------------  // acclient.c:933552
void __cdecl _E203_31()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D530) --------------------------------------------------------  // acclient.c:933565
void __cdecl _E206_35()
{
  char *v0; // esi@1

  v0 = &KW_X_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D560) --------------------------------------------------------  // acclient.c:933578
void __cdecl _E209_29()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D590) --------------------------------------------------------  // acclient.c:933591
void __cdecl _E212_32()
{
  char *v0; // esi@1

  v0 = &KW_Y_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D5C0) --------------------------------------------------------  // acclient.c:933604
void __cdecl _E215_29()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D5F0) --------------------------------------------------------  // acclient.c:933617
void __cdecl _E218_29()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D620) --------------------------------------------------------  // acclient.c:933630
void __cdecl _E221_29()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078D650) --------------------------------------------------------  // acclient.c:933643
void __cdecl _E224_29()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

