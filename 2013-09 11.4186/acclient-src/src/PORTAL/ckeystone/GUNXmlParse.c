/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GUNXmlParse
   Object     : PORTAL\ckeystone\GUNXmlParse.obj
   Functions  : 14
   Addresses  : 00557200 - 00773010 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00557200) --------------------------------------------------------  // acclient.c:390560
void CParseXml::CParseXml()
{
  int v1; // eax@1

  v1 = pXMLDoc;
  if ( pXMLDoc )
  {
    pXMLDoc = 0;
    (*(void (__stdcall **)(int))(*(_DWORD *)v1 + 8))(v1);
  }
}
// 86FE60: using guessed type int pXMLDoc;

//----- (00557220) --------------------------------------------------------  // acclient.c:390574
void CParseXml::~CParseXml()
{
  if ( pXMLDoc )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)pXMLDoc + 8))(pXMLDoc);
    pXMLDoc = 0;
  }
}
// 86FE60: using guessed type int pXMLDoc;

//----- (00557240) --------------------------------------------------------  // acclient.c:390585
bool CParseXml::Init()
{
  HRESULT v1; // esi@3
  int v3; // [sp+0h] [bp-20h]@1
  HRESULT hr; // [sp+Ch] [bp-14h]@3
  int *v5; // [sp+10h] [bp-10h]@1
  int v6; // [sp+1Ch] [bp-4h]@1

  v5 = &v3;
  v6 = 0;
  if ( pXMLDoc )
    (*(void (__stdcall **)(int))(*(_DWORD *)pXMLDoc + 8))(pXMLDoc);
  v1 = CoCreateInstance(
         &_GUID_88d969c0_f192_11d4_a65f_0040963251e5,
         0,
         7u,
         &_GUID_00000000_0000_0000_c000_000000000046,
         (LPVOID *)&hr);
  if ( v1 < 0 )
    goto LABEL_11;
  v1 = OleRun((LPUNKNOWN)hr);
  if ( v1 >= 0 )
    v1 = (**(int (__stdcall ***)(HRESULT, GUID *, int *))hr)(hr, &_GUID_2933bf95_7b36_11d2_b20e_00c04f983e60, &pXMLDoc);
  (*(void (__stdcall **)(HRESULT))(*(_DWORD *)hr + 8))(hr);
  if ( v1 < 0 )
LABEL_11:
    pXMLDoc = 0;
  return v1 >= 0;
}
// 86FE60: using guessed type int pXMLDoc;

//----- (007079D0) --------------------------------------------------------  // acclient.c:794808
int sub_7079D0()
{
  return atexit(nullsub_1282);
}

//----- (007079E0) --------------------------------------------------------  // acclient.c:794814
int _E4_4()
{
  return atexit(_E5_4);
}

//----- (007079F0) --------------------------------------------------------  // acclient.c:794820
int _E7_4()
{
  Outside_CellID_4.id = Invalid_CellID_4.id + 1;
  return atexit(_E8_4);
}

//----- (00707A10) --------------------------------------------------------  // acclient.c:794827
int _E10_3()
{
  In_Limbo_CellID_3.id = Outside_CellID_4.id + 1;
  return atexit(_E11_3);
}

//----- (00707A30) --------------------------------------------------------  // acclient.c:794834
int _E13_3()
{
  First_Interior_CellID_3.id = In_Limbo_CellID_3.id + 1;
  return atexit(_E14_3);
}

//----- (00707A50) --------------------------------------------------------  // acclient.c:794841
int _E16_3()
{
  Last_Interior_CellID_3.id = Invalid_CellID_4.id - 1;
  return atexit(_E17_3);
}

//----- (00707A70) --------------------------------------------------------  // acclient.c:794848
int _E21_5()
{
  return atexit(_E22_5);
}

//----- (00707A80) --------------------------------------------------------  // acclient.c:794854
int _E40_3()
{
  return atexit(_E41_3);
}

//----- (00707A90) --------------------------------------------------------  // acclient.c:794860
int _E43_4()
{
  return atexit(_E44_4);
}

//----- (00707AA0) --------------------------------------------------------  // acclient.c:794866
int sub_707AA0()
{
  return atexit(_E74_82);
}

//----- (00773010) --------------------------------------------------------  // acclient.c:906869
void __cdecl _E74_82()
{
  if ( pXMLDoc )
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)pXMLDoc + 8))(pXMLDoc);
}
// 86FE60: using guessed type int pXMLDoc;

