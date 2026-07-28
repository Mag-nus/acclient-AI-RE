/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MaterialModifier
   Object     : ENGINE\render_base\MaterialModifier.obj
   Functions  : 822
   Addresses  : 004503B0 - 00756B70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004503B0) --------------------------------------------------------  // acclient.c:141559
void __thiscall MaterialModifier::GetSubDataIDs(MaterialModifier *this, QualifiedDataIDArray *id_array)
{
  MaterialModifier *v2; // edi@1
  unsigned int v3; // esi@1

  v2 = this;
  v3 = 0;
  if ( this->properties.m_num )
  {
    do
      MaterialProperty::GetSubDataIDs(v2->properties.m_data[v3++], id_array);
    while ( v3 < v2->properties.m_num );
  }
}

//----- (004503E0) --------------------------------------------------------  // acclient.c:141575
char __thiscall MaterialModifier::GetSubObjects(MaterialModifier *this)
{
  MaterialModifier *v1; // edi@1
  unsigned int v2; // esi@1
  char v3; // bl@1

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->properties.m_num )
  {
    do
    {
      if ( !MaterialProperty::GetSubObjects(v1->properties.m_data[v2]) )
        v3 = 0;
      ++v2;
    }
    while ( v2 < v1->properties.m_num );
  }
  return v3;
}

//----- (00450410) --------------------------------------------------------  // acclient.c:141598
char __thiscall MaterialModifier::ReleaseSubObjects(MaterialModifier *this)
{
  MaterialModifier *v1; // edi@1
  unsigned int v2; // esi@1
  char v3; // bl@1

  v1 = this;
  v2 = 0;
  v3 = 1;
  if ( this->properties.m_num )
  {
    do
    {
      if ( !MaterialProperty::ReleaseSubObjects(v1->properties.m_data[v2]) )
        v3 = 0;
      ++v2;
    }
    while ( v2 < v1->properties.m_num );
  }
  return v3;
}

//----- (00450440) --------------------------------------------------------  // acclient.c:141621
void __thiscall MaterialModifier::MaterialModifier(MaterialModifier *this)
{
  MaterialModifier *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_46);
  v1->vfptr = (InterfaceVtbl *)&MaterialModifier::vftable;
  v1->properties.m_data = 0;
  v1->properties.m_sizeAndDeallocate = 0;
  v1->properties.m_num = 0;
}
// 79B458: using guessed type __int32 (__stdcall *MaterialModifier::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00450480) --------------------------------------------------------  // acclient.c:141641
void __thiscall MaterialModifier::End(MaterialModifier *this)
{
  MaterialModifier *v1; // esi@1
  unsigned int v2; // edi@1
  unsigned int v3; // edi@3
  MaterialProperty **v4; // ecx@4
  void *v5; // ebx@4
  unsigned int v6; // eax@7
  unsigned int v7; // ecx@7
  int i; // eax@10

  v1 = this;
  v2 = 0;
  if ( this->properties.m_num )
  {
    do
      MaterialProperty::ReleaseSubObjects(v1->properties.m_data[v2++]);
    while ( v2 < v1->properties.m_num );
  }
  v3 = 0;
  if ( v1->properties.m_num )
  {
    do
    {
      v4 = v1->properties.m_data;
      v5 = v4[v3];
      if ( v5 )
      {
        MaterialProperty::~MaterialProperty(v4[v3]);
        operator delete(v5);
      }
      v1->properties.m_data[v3++] = 0;
    }
    while ( v3 < v1->properties.m_num );
  }
  v6 = v1->properties.m_sizeAndDeallocate;
  v7 = v1->properties.m_sizeAndDeallocate & 0x80000000;
  v1->properties.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->properties.m_data);
    v1->properties.m_data = 0;
    v1->properties.m_sizeAndDeallocate = 0;
  }
  else if ( v1->properties.m_data )
  {
    for ( i = (v6 & 0x7FFFFFFF) - 1; i >= 0; v1->properties.m_data[i + 1] = 0 )
      --i;
  }
}

//----- (00450560) --------------------------------------------------------  // acclient.c:141693
DBObj *__cdecl MaterialModifier::Allocator()
{
  void *v0; // esi@1
  DBObj *result; // eax@2

  v0 = operator new(0x40u);
  if ( v0 )
  {
    DBObj::DBObj((DBObj *)v0, INVALID_DID_46);
    *(_DWORD *)v0 = &MaterialModifier::vftable;
    *((_DWORD *)v0 + 12) = 0;
    *((_DWORD *)v0 + 13) = 0;
    *((_DWORD *)v0 + 14) = 0;
    result = (DBObj *)v0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79B458: using guessed type __int32 (__stdcall *MaterialModifier::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004505B0) --------------------------------------------------------  // acclient.c:141717
void __thiscall MaterialModifier::~MaterialModifier(MaterialModifier *this)
{
  MaterialModifier *v1; // esi@1

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&MaterialModifier::vftable;
  MaterialModifier::End(this);
  if ( (v1->properties.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->properties.m_data);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79B458: using guessed type __int32 (__stdcall *MaterialModifier::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004505F0) --------------------------------------------------------  // acclient.c:141731
MaterialModifier *__thiscall MaterialModifier::scalar_deleting_destructor(MaterialModifier *this, unsigned int a2)
{
  MaterialModifier *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&MaterialModifier::vftable;
  MaterialModifier::End(this);
  if ( (v2->properties.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->properties.m_data);
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79B458: using guessed type __int32 (__stdcall *MaterialModifier::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00450640) --------------------------------------------------------  // acclient.c:141748
char __thiscall MaterialModifier::CopyInto(MaterialModifier *this, DBObj *retval)
{
  MaterialModifier *v2; // ebp@1
  unsigned int v3; // ebx@1
  MaterialProperty *v4; // ecx@2
  unsigned int v5; // edi@3
  unsigned int v6; // eax@3
  unsigned int v7; // eax@4
  char result; // al@7

  v2 = this;
  v3 = 0;
  if ( this->properties.m_num )
  {
    while ( 1 )
    {
      v4 = v2->properties.m_data[v3];
      if ( !v4 )
        break;
      v5 = MaterialProperty::Copy(v4);
      v6 = retval[1].m_dataCategory & 0x7FFFFFFF;
      if ( *(_DWORD *)&retval[1].m_bLoaded < v6
        || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
            SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&retval[1], v7)) )
        *((_DWORD *)&retval[1].vfptr->IUnknown_QueryInterface + (*(_DWORD *)&retval[1].m_bLoaded)++) = v5;
      ++v3;
      if ( v3 >= v2->properties.m_num )
        goto LABEL_7;
    }
    result = 0;
  }
  else
  {
LABEL_7:
    result = 1;
  }
  return result;
}

//----- (004506C0) --------------------------------------------------------  // acclient.c:141788
void __thiscall MaterialModifier::Serialize(MaterialModifier *this, Archive *io_archive)
{
  Archive *v2; // ebx@1
  MaterialModifier *v3; // ebp@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@1
  int v6; // eax@5
  MaterialProperty *v7; // eax@7
  MaterialProperty *v8; // eax@8
  MaterialProperty *v9; // edi@8
  int v10; // eax@12
  unsigned int v11; // eax@13
  unsigned int v12; // [sp+Ch] [bp-4h]@5
  Archive *io_archivea; // [sp+14h] [bp+4h]@1

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  v4 = v3->properties.m_num;
  io_archivea = (Archive *)v3->properties.m_num;
  Archive::CheckAlignment(v2, 4u);
  v5 = Archive::GetBytes(v2, 4u);
  if ( v5 )
  {
    if ( v2->m_flags & 1 )
      *(_DWORD *)v5 = v4;
    else
      io_archivea = *(Archive **)v5;
  }
  v6 = 0;
  v12 = 0;
  if ( io_archivea )
  {
    do
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v7 = (MaterialProperty *)operator new(0x2Cu);
        if ( v7 )
        {
          MaterialProperty::MaterialProperty(v7);
          v9 = v8;
        }
        else
        {
          v9 = 0;
        }
      }
      else
      {
        v9 = v3->properties.m_data[v6];
      }
      MaterialProperty::Serialize(v9, v2);
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v10 = v3->properties.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v3->properties.m_num < v10
          || (v11 = SmartArray<UIChildFramework *,1>::get_new_size(v10 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3->properties, v11)) )
          v3->properties.m_data[v3->properties.m_num++] = v9;
      }
      v6 = v12++ + 1;
    }
    while ( v12 < (unsigned int)io_archivea );
  }
}

//----- (006E2C60) --------------------------------------------------------  // acclient.c:759618
int _E73_52()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_23, "None");
  return atexit(_E74_40);
}

//----- (006E2C80) --------------------------------------------------------  // acclient.c:759625
int _E76_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_23, "Speed");
  return atexit(_E77_54);
}

//----- (006E2CA0) --------------------------------------------------------  // acclient.c:759632
int _E79_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_23, "Noise");
  return atexit(_E80_28);
}

//----- (006E2CC0) --------------------------------------------------------  // acclient.c:759639
int _E82_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_23, "Sine");
  return atexit(_E83_17);
}

//----- (006E2CE0) --------------------------------------------------------  // acclient.c:759646
int _E85_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_23, "Square");
  return atexit(_E86_14);
}

//----- (006E2D00) --------------------------------------------------------  // acclient.c:759653
int _E88_12()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_23, "Bounce");
  return atexit(_E89_25);
}

//----- (006E2D20) --------------------------------------------------------  // acclient.c:759660
int _E91_26()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_23, "Perlin");
  return atexit(_E92_27);
}

//----- (006E2D40) --------------------------------------------------------  // acclient.c:759667
int _E94_16()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_23, "Fractal");
  return atexit(sub_752100);
}

//----- (006E2D60) --------------------------------------------------------  // acclient.c:759674
int _E97_25()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_23, "FrameLoop");
  return atexit(_E98_42);
}

//----- (006E2D80) --------------------------------------------------------  // acclient.c:759681
void _E100_22()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_26, PFID_A8R8G8B8);
}

//----- (006E2D90) --------------------------------------------------------  // acclient.c:759687
int _E118_16()
{
  PStringBase<char>::PStringBase<char>(&PHeader_8, "PREPROC_HEADER");
  return atexit(_E119_65);
}

//----- (006E2DB0) --------------------------------------------------------  // acclient.c:759694
int _E121_13()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_6, "VertexArray");
  return atexit(_E122_52);
}

//----- (006E2DD0) --------------------------------------------------------  // acclient.c:759701
int _E124_16()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_6, "BinaryVertexArray");
  return atexit(_E125_27);
}

//----- (006E2DF0) --------------------------------------------------------  // acclient.c:759708
int _E127_12()
{
  PStringBase<char>::PStringBase<char>(&VertexType_7, "VertexType");
  return atexit(_E128_28);
}

//----- (006E2E10) --------------------------------------------------------  // acclient.c:759715
int _E130_13()
{
  PStringBase<char>::PStringBase<char>(&VertexData_6, "VertexData");
  return atexit(_E131_24);
}

//----- (006E2E30) --------------------------------------------------------  // acclient.c:759722
int _E133_12()
{
  PStringBase<char>::PStringBase<char>(&Vertex_6, "Vertex");
  return atexit(_E134_23);
}

//----- (006E2E50) --------------------------------------------------------  // acclient.c:759729
int _E136_11()
{
  PStringBase<char>::PStringBase<char>(&Index_13, "Index");
  return atexit(_E137_23);
}

//----- (006E2E70) --------------------------------------------------------  // acclient.c:759736
int _E139_10()
{
  PStringBase<char>::PStringBase<char>(&Origin_13, "P");
  return atexit(_E140_18);
}

//----- (006E2E90) --------------------------------------------------------  // acclient.c:759743
int _E142_10()
{
  PStringBase<char>::PStringBase<char>(&Normal_6, "N");
  return atexit(_E143_19);
}

//----- (006E2EB0) --------------------------------------------------------  // acclient.c:759750
int _E145_9()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_13, "Diffuse");
  return atexit(_E146_18);
}

//----- (006E2ED0) --------------------------------------------------------  // acclient.c:759757
int _E148_9()
{
  PStringBase<char>::PStringBase<char>(&Specular_13, "Specular");
  return atexit(_E149_18);
}

//----- (006E2EF0) --------------------------------------------------------  // acclient.c:759764
int _E151_9()
{
  PStringBase<char>::PStringBase<char>(&UVS_6, "UVS");
  return atexit(_E152_17);
}

//----- (006E2F10) --------------------------------------------------------  // acclient.c:759771
int _E154_10()
{
  PStringBase<char>::PStringBase<char>(&VectorS_6, "VectorS");
  return atexit(_E155_15);
}

//----- (006E2F30) --------------------------------------------------------  // acclient.c:759778
int _E157_9()
{
  PStringBase<char>::PStringBase<char>(&VectorT_6, "VectorT");
  return atexit(_E158_18);
}

//----- (006E2F50) --------------------------------------------------------  // acclient.c:759785
int _E160_10()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_6, "VectorSxT");
  return atexit(_E161_15);
}

//----- (006E2F70) --------------------------------------------------------  // acclient.c:759792
int _E163_8()
{
  PStringBase<char>::PStringBase<char>(&Weights_6, "Weights");
  return atexit(_E164_18);
}

//----- (006E2F90) --------------------------------------------------------  // acclient.c:759799
int _E166_9()
{
  PStringBase<char>::PStringBase<char>(&Importance_6, "Importance");
  return atexit(_E167_14);
}

//----- (006E2FB0) --------------------------------------------------------  // acclient.c:759806
int _E169_7()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_6, "PhysMtl");
  return atexit(_E170_13);
}

//----- (006E2FD0) --------------------------------------------------------  // acclient.c:759813
int _E172_7()
{
  PStringBase<char>::PStringBase<char>(&Material_30, "Material");
  return atexit(_E173_12);
}

//----- (006E2FF0) --------------------------------------------------------  // acclient.c:759820
int _E175_7()
{
  PStringBase<char>::PStringBase<char>(&ID_16, "ID");
  return atexit(_E176_13);
}

//----- (006E3010) --------------------------------------------------------  // acclient.c:759827
int _E178_7()
{
  PStringBase<char>::PStringBase<char>(&FileName_6, "FileName");
  return atexit(_E179_12);
}

//----- (006E3030) --------------------------------------------------------  // acclient.c:759834
int _E181_7()
{
  PStringBase<char>::PStringBase<char>(&Polygon_13, "Polygon");
  return atexit(_E182_12);
}

//----- (006E3050) --------------------------------------------------------  // acclient.c:759841
int _E184_5()
{
  PStringBase<char>::PStringBase<char>(&ID_17, "ID");
  return atexit(_E185_9);
}

//----- (006E3070) --------------------------------------------------------  // acclient.c:759848
int _E187_5()
{
  PStringBase<char>::PStringBase<char>(&Indices_12, "INDICES");
  return atexit(_E188_10);
}

//----- (006E3090) --------------------------------------------------------  // acclient.c:759855
int _E190_5()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_6, "MaterialID");
  return atexit(_E191_9);
}

//----- (006E30B0) --------------------------------------------------------  // acclient.c:759862
int _E193_5()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_6, "PhysMaterialID");
  return atexit(_E194_16);
}

//----- (006E30D0) --------------------------------------------------------  // acclient.c:759869
int _E196_7()
{
  PStringBase<char>::PStringBase<char>(&Markings_6, "Markings");
  return atexit(_E197_7);
}

//----- (006E30F0) --------------------------------------------------------  // acclient.c:759876
int _E199_5()
{
  PStringBase<char>::PStringBase<char>(&Material_31, "Material");
  return atexit(_E200_12);
}

//----- (006E3110) --------------------------------------------------------  // acclient.c:759883
int _E202_5()
{
  PStringBase<char>::PStringBase<char>(&Index_14, "Index");
  return atexit(_E203_11);
}

//----- (006E3130) --------------------------------------------------------  // acclient.c:759890
int _E205_6()
{
  PStringBase<char>::PStringBase<char>(&Filename_6, "Filename");
  return atexit(_E206_14);
}

//----- (006E3150) --------------------------------------------------------  // acclient.c:759897
int _E208_7()
{
  PStringBase<char>::PStringBase<char>(&Surface_6, "Surface");
  return atexit(_E209_9);
}

//----- (006E3170) --------------------------------------------------------  // acclient.c:759904
int _E211_6()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_6, "CellPoly");
  return atexit(_E212_12);
}

//----- (006E3190) --------------------------------------------------------  // acclient.c:759911
int _E214_6()
{
  PStringBase<char>::PStringBase<char>(&Sphere_9, "Sphere");
  return atexit(_E215_8);
}

//----- (006E31B0) --------------------------------------------------------  // acclient.c:759918
int _E217_6()
{
  PStringBase<char>::PStringBase<char>(&Side_6, "Side");
  return atexit(_E218_9);
}

//----- (006E31D0) --------------------------------------------------------  // acclient.c:759925
int _E220_6()
{
  PStringBase<char>::PStringBase<char>(&Positive_6, "Positive");
  return atexit(_E221_9);
}

//----- (006E31F0) --------------------------------------------------------  // acclient.c:759932
int _E223_6()
{
  PStringBase<char>::PStringBase<char>(&Negative_6, "Negative");
  return atexit(_E224_9);
}

//----- (006E3210) --------------------------------------------------------  // acclient.c:759939
int _E226_6()
{
  PStringBase<char>::PStringBase<char>(&Polygon_14, "PolygonIndex");
  return atexit(_E227_9);
}

//----- (006E3230) --------------------------------------------------------  // acclient.c:759946
int _E229_6()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_13, "OtherCellMeshIndex");
  return atexit(_E230_9);
}

//----- (006E3250) --------------------------------------------------------  // acclient.c:759953
int _E232_6()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_6, "CellPortal");
  return atexit(_E233_8);
}

//----- (006E3270) --------------------------------------------------------  // acclient.c:759960
int _E235_6()
{
  PStringBase<char>::PStringBase<char>(&Portal_9, "PortalIndex");
  return atexit(_E236_8);
}

//----- (006E3290) --------------------------------------------------------  // acclient.c:759967
int _E238_6()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_14, "OtherCellID");
  return atexit(_E239_9);
}

//----- (006E32B0) --------------------------------------------------------  // acclient.c:759974
int _E241_6()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_6, "OtherPortalIndex");
  return atexit(_E242_9);
}

//----- (006E32D0) --------------------------------------------------------  // acclient.c:759981
int _E244_6()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_6, "ExactMatch");
  return atexit(_E245_8);
}

//----- (006E32F0) --------------------------------------------------------  // acclient.c:759988
int _E247_6()
{
  PStringBase<char>::PStringBase<char>(&StabList_6, "StabList");
  return atexit(_E248_8);
}

//----- (006E3310) --------------------------------------------------------  // acclient.c:759995
int _E250_6()
{
  PStringBase<char>::PStringBase<char>(&Period_6, "Period");
  return atexit(_E251_8);
}

//----- (006E3330) --------------------------------------------------------  // acclient.c:760002
int _E253_6()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_6, "GrannyAnimation");
  return atexit(_E254_9);
}

//----- (006E3350) --------------------------------------------------------  // acclient.c:760009
int _E256_6()
{
  PStringBase<char>::PStringBase<char>(&Transform_6, "Transform");
  return atexit(_E257_7);
}

//----- (006E3370) --------------------------------------------------------  // acclient.c:760016
int _E259_6()
{
  PStringBase<char>::PStringBase<char>(&Scale_20, "Scale");
  return atexit(_E260_8);
}

//----- (006E3390) --------------------------------------------------------  // acclient.c:760023
int _E262_6()
{
  PStringBase<char>::PStringBase<char>(&Weight_6, "Weight");
  return atexit(_E263_6);
}

//----- (006E33B0) --------------------------------------------------------  // acclient.c:760030
int _E265_6()
{
  PStringBase<char>::PStringBase<char>(&Offset_6, "Offset");
  return atexit(_E266_6);
}

//----- (006E33D0) --------------------------------------------------------  // acclient.c:760037
int _E268_6()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_7, "Quaternion");
  return atexit(_E269_6);
}

//----- (006E33F0) --------------------------------------------------------  // acclient.c:760044
int _E271_5()
{
  PStringBase<char>::PStringBase<char>(&Rotation_13, "Rotation");
  return atexit(_E272_5);
}

//----- (006E3410) --------------------------------------------------------  // acclient.c:760051
int _E274_5()
{
  PStringBase<char>::PStringBase<char>(&STime_6, "STime");
  return atexit(_E275_5);
}

//----- (006E3430) --------------------------------------------------------  // acclient.c:760058
int _E277_5()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_6, "PhysicsSplines");
  return atexit(_E278_5);
}

//----- (006E3450) --------------------------------------------------------  // acclient.c:760065
int _E280_5()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_6, "BoneOpacities");
  return atexit(_E281_6);
}

//----- (006E3470) --------------------------------------------------------  // acclient.c:760072
int _E283_5()
{
  PStringBase<char>::PStringBase<char>(&LowPt_6, "LowPoint");
  return atexit(_E284_5);
}

//----- (006E3490) --------------------------------------------------------  // acclient.c:760079
int _E286_5()
{
  PStringBase<char>::PStringBase<char>(&Radius_6, "Radius");
  return atexit(_E287_6);
}

//----- (006E34B0) --------------------------------------------------------  // acclient.c:760086
int _E289_5()
{
  PStringBase<char>::PStringBase<char>(&Height_6, "Height");
  return atexit(_E290_6);
}

//----- (006E34D0) --------------------------------------------------------  // acclient.c:760093
int _E292_5()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_6, "Texture2D");
  return atexit(_E293_5);
}

//----- (006E34F0) --------------------------------------------------------  // acclient.c:760100
int _E295_5()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_6, "Texture3D");
  return atexit(_E296_6);
}

//----- (006E3510) --------------------------------------------------------  // acclient.c:760107
int _E298_5()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_6, "TextureCube");
  return atexit(_E299_4);
}

//----- (006E3530) --------------------------------------------------------  // acclient.c:760114
int _E301_4()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_6, "TextureMovie2D");
  return atexit(_E302_5);
}

//----- (006E3550) --------------------------------------------------------  // acclient.c:760121
int _E304_4()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_6, "MovieFile");
  return atexit(_E305_4);
}

//----- (006E3570) --------------------------------------------------------  // acclient.c:760128
int _E307_4()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_6, "MovieFPS");
  return atexit(_E308_5);
}

//----- (006E3590) --------------------------------------------------------  // acclient.c:760135
int _E310_4()
{
  PStringBase<char>::PStringBase<char>(&Levels_6, "Levels");
  return atexit(_E311_4);
}

//----- (006E35B0) --------------------------------------------------------  // acclient.c:760142
int _E313_4()
{
  PStringBase<char>::PStringBase<char>(&NodeName_69, "Instance");
  return atexit(_E314_5);
}

//----- (006E35D0) --------------------------------------------------------  // acclient.c:760149
int _E316_4()
{
  PStringBase<char>::PStringBase<char>(&Material_32, "Material");
  return atexit(_E317_4);
}

//----- (006E35F0) --------------------------------------------------------  // acclient.c:760156
int _E319_4()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_6, "MaterialType");
  return atexit(_E320_5);
}

//----- (006E3610) --------------------------------------------------------  // acclient.c:760163
int _E322_4()
{
  PStringBase<char>::PStringBase<char>(&Modifier_6, "Modifier");
  return atexit(_E323_4);
}

//----- (006E3630) --------------------------------------------------------  // acclient.c:760170
int _E325_4()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_6, "AllowStencilShadows");
  return atexit(_E326_5);
}

//----- (006E3650) --------------------------------------------------------  // acclient.c:760177
int _E328_4()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_6, "DiscardGeometry");
  return atexit(_E329_4);
}

//----- (006E3670) --------------------------------------------------------  // acclient.c:760184
int _E331_4()
{
  PStringBase<char>::PStringBase<char>(&NodeName_70, "Material");
  return atexit(_E332_5);
}

//----- (006E3690) --------------------------------------------------------  // acclient.c:760191
int _E334_4()
{
  PStringBase<char>::PStringBase<char>(&SortMode_6, "SortMode");
  return atexit(_E335_4);
}

//----- (006E36B0) --------------------------------------------------------  // acclient.c:760198
int _E337_4()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_6, "None");
  return atexit(_E338_4);
}

//----- (006E36D0) --------------------------------------------------------  // acclient.c:760205
int _E340_4()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_6, "Triangle");
  return atexit(_E341_4);
}

//----- (006E36F0) --------------------------------------------------------  // acclient.c:760212
int _E343_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_71, "Modifier");
  return atexit(_E344_2);
}

//----- (006E3710) --------------------------------------------------------  // acclient.c:760219
int _E346_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_72, "Property");
  return atexit(_E347_2);
}

//----- (006E3730) --------------------------------------------------------  // acclient.c:760226
int _E349_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_6, "Data");
  return atexit(_E350_2);
}

//----- (006E3750) --------------------------------------------------------  // acclient.c:760233
int _E352_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_6, "Waveform");
  return atexit(_E353_2);
}

//----- (006E3770) --------------------------------------------------------  // acclient.c:760240
int _E355_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_6, "Color");
  return atexit(_E356_2);
}

//----- (006E3790) --------------------------------------------------------  // acclient.c:760247
int _E358_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_6, "Texture");
  return atexit(_E359_2);
}

//----- (006E37B0) --------------------------------------------------------  // acclient.c:760254
int _E361_2()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_6, "Bool");
  return atexit(_E362_2);
}

//----- (006E37D0) --------------------------------------------------------  // acclient.c:760261
int _E364_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_73, "Layer");
  return atexit(_E365_2);
}

//----- (006E37F0) --------------------------------------------------------  // acclient.c:760268
int _E367_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_6, "UVTranslate");
  return atexit(_E368_2);
}

//----- (006E3810) --------------------------------------------------------  // acclient.c:760275
int _E370_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_6, "UVRotate");
  return atexit(_E371_2);
}

//----- (006E3830) --------------------------------------------------------  // acclient.c:760282
int _E373_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_6, "UVScale");
  return atexit(_E374_2);
}

//----- (006E3850) --------------------------------------------------------  // acclient.c:760289
int _E376_2()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_6, "UVTransform");
  return atexit(_E377_2);
}

//----- (006E3870) --------------------------------------------------------  // acclient.c:760296
int _E379_2()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_6, "TrueFlags");
  return atexit(_E380_2);
}

//----- (006E3890) --------------------------------------------------------  // acclient.c:760303
int _E382_2()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_6, "FalseFlags");
  return atexit(_E383_2);
}

//----- (006E38B0) --------------------------------------------------------  // acclient.c:760310
int _E385_2()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_6, "RenderPass");
  return atexit(_E386_2);
}

//----- (006E38D0) --------------------------------------------------------  // acclient.c:760317
int _E388_2()
{
  PStringBase<char>::PStringBase<char>(&Blend_6, "Blend");
  return atexit(_E389_2);
}

//----- (006E38F0) --------------------------------------------------------  // acclient.c:760324
int _E391_2()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_6, "DepthTest");
  return atexit(_E392_2);
}

//----- (006E3910) --------------------------------------------------------  // acclient.c:760331
int _E394_2()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_6, "DepthWrite");
  return atexit(_E395_2);
}

//----- (006E3930) --------------------------------------------------------  // acclient.c:760338
int _E397_2()
{
  PStringBase<char>::PStringBase<char>(&CullMode_6, "CullMode");
  return atexit(_E398_2);
}

//----- (006E3950) --------------------------------------------------------  // acclient.c:760345
int _E400_2()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_6, "DepthFog");
  return atexit(_E401_2);
}

//----- (006E3970) --------------------------------------------------------  // acclient.c:760352
int _E403_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_6, "AlphaTestMode");
  return atexit(_E404_2);
}

//----- (006E3990) --------------------------------------------------------  // acclient.c:760359
int _E406_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_6, "AlphaTestRef");
  return atexit(_E407_2);
}

//----- (006E39B0) --------------------------------------------------------  // acclient.c:760366
int _E409_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_6, "FFUseLighting");
  return atexit(_E410_2);
}

//----- (006E39D0) --------------------------------------------------------  // acclient.c:760373
int _E412_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_6, "FFUseDyeColorInTFactor");
  return atexit(_E413_2);
}

//----- (006E39F0) --------------------------------------------------------  // acclient.c:760380
int _E415_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_6, "FFUseSpecularLighting");
  return atexit(_E416_2);
}

//----- (006E3A10) --------------------------------------------------------  // acclient.c:760387
int _E418_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_6, "FFUseDistanceFog");
  return atexit(_E419_2);
}

//----- (006E3A30) --------------------------------------------------------  // acclient.c:760394
int _E421_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_6, "FFUseVertexDiffuse");
  return atexit(_E422_2);
}

//----- (006E3A50) --------------------------------------------------------  // acclient.c:760401
int _E424_2()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_6, "FFUseVertexSpecular");
  return atexit(_E425_2);
}

//----- (006E3A70) --------------------------------------------------------  // acclient.c:760408
int _E427_2()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_6, "ShaderSupportsDynamicLights");
  return atexit(_E428_2);
}

//----- (006E3A90) --------------------------------------------------------  // acclient.c:760415
int _E430_2()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_6, "UsesTransparency");
  return atexit(_E431_2);
}

//----- (006E3AB0) --------------------------------------------------------  // acclient.c:760422
int _E433_2()
{
  PStringBase<char>::PStringBase<char>(&Ambient_6, "Ambient");
  return atexit(_E434_2);
}

//----- (006E3AD0) --------------------------------------------------------  // acclient.c:760429
int _E436_2()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_14, "Diffuse");
  return atexit(_E437_2);
}

//----- (006E3AF0) --------------------------------------------------------  // acclient.c:760436
int _E439_2()
{
  PStringBase<char>::PStringBase<char>(&Specular_14, "Specular");
  return atexit(_E440_2);
}

//----- (006E3B10) --------------------------------------------------------  // acclient.c:760443
int _E442_2()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_6, "SpecularPower");
  return atexit(_E443_2);
}

//----- (006E3B30) --------------------------------------------------------  // acclient.c:760450
int _E445_2()
{
  PStringBase<char>::PStringBase<char>(&Dye_6, "Dye");
  return atexit(_E446_2);
}

//----- (006E3B50) --------------------------------------------------------  // acclient.c:760457
int _E448_2()
{
  PStringBase<char>::PStringBase<char>(&Emissive_6, "Emissive");
  return atexit(_E449_2);
}

//----- (006E3B70) --------------------------------------------------------  // acclient.c:760464
int _E451_2()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_6, "VertexFormat");
  return atexit(_E452_2);
}

//----- (006E3B90) --------------------------------------------------------  // acclient.c:760471
int _E454_2()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_6, "VertexShader");
  return atexit(_E455_2);
}

//----- (006E3BB0) --------------------------------------------------------  // acclient.c:760478
int _E457_2()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_6, "PixelShader");
  return atexit(_E458_2);
}

//----- (006E3BD0) --------------------------------------------------------  // acclient.c:760485
int _E460_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_6, "None");
  return atexit(_E461_2);
}

//----- (006E3BF0) --------------------------------------------------------  // acclient.c:760492
int _E463_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_6, "Reflections");
  return atexit(_E464_2);
}

//----- (006E3C10) --------------------------------------------------------  // acclient.c:760499
int _E466_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_6, "VideoPost");
  return atexit(_E467_2);
}

//----- (006E3C30) --------------------------------------------------------  // acclient.c:760506
int _E469_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_6, "HighDetail");
  return atexit(_E470_2);
}

//----- (006E3C50) --------------------------------------------------------  // acclient.c:760513
int _E472_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_6, "Specular");
  return atexit(_E473_2);
}

//----- (006E3C70) --------------------------------------------------------  // acclient.c:760520
int _E475_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_6, "Class1");
  return atexit(_E476_2);
}

//----- (006E3C90) --------------------------------------------------------  // acclient.c:760527
int _E478_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_6, "Class2");
  return atexit(_E479_2);
}

//----- (006E3CB0) --------------------------------------------------------  // acclient.c:760534
int _E481_2()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_6, "Class3");
  return atexit(_E482_2);
}

//----- (006E3CD0) --------------------------------------------------------  // acclient.c:760541
int _E484_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_6, "Default");
  return atexit(_E485_2);
}

//----- (006E3CF0) --------------------------------------------------------  // acclient.c:760548
int _E487_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_6,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E488_2);
}

//----- (006E3D10) --------------------------------------------------------  // acclient.c:760557
int _E490_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_6, "PointLightDiffuseAndSpecular");
  return atexit(_E491_2);
}

//----- (006E3D30) --------------------------------------------------------  // acclient.c:760564
int _E493_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_6,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E494_2);
}

//----- (006E3D50) --------------------------------------------------------  // acclient.c:760573
int _E496_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_6,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E497_2);
}

//----- (006E3D70) --------------------------------------------------------  // acclient.c:760582
int _E499_2()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_6,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E500_2);
}

//----- (006E3D90) --------------------------------------------------------  // acclient.c:760591
int _E502_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_6, "DistanceFog");
  return atexit(_E503_2);
}

//----- (006E3DB0) --------------------------------------------------------  // acclient.c:760598
int _E505_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_6, "FFGlow");
  return atexit(_E506_2);
}

//----- (006E3DD0) --------------------------------------------------------  // acclient.c:760605
int _E508_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_6, "ShaderGlow");
  return atexit(_E509_2);
}

//----- (006E3DF0) --------------------------------------------------------  // acclient.c:760612
int _E511_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_6, "LandscapeShadowMap");
  return atexit(_E512_2);
}

//----- (006E3E10) --------------------------------------------------------  // acclient.c:760619
int _E514_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_6, "AlphaBlend");
  return atexit(_E515_2);
}

//----- (006E3E30) --------------------------------------------------------  // acclient.c:760626
int _E517_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_6, "AL_0DL_0PL");
  return atexit(_E518_2);
}

//----- (006E3E50) --------------------------------------------------------  // acclient.c:760633
int _E520_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_6, "AL_0DL_1PL");
  return atexit(_E521_2);
}

//----- (006E3E70) --------------------------------------------------------  // acclient.c:760640
int _E523_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_6, "AL_0DL_2PL");
  return atexit(_E524_2);
}

//----- (006E3E90) --------------------------------------------------------  // acclient.c:760647
int _E526_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_6, "AL_0DL_3PL");
  return atexit(_E527_2);
}

//----- (006E3EB0) --------------------------------------------------------  // acclient.c:760654
int _E529_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_6, "AL_0DL_4PL");
  return atexit(_E530_2);
}

//----- (006E3ED0) --------------------------------------------------------  // acclient.c:760661
int _E532_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_6, "AL_0DL_5PL");
  return atexit(_E533_2);
}

//----- (006E3EF0) --------------------------------------------------------  // acclient.c:760668
int _E535_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_6, "AL_0DL_6PL");
  return atexit(_E536_2);
}

//----- (006E3F10) --------------------------------------------------------  // acclient.c:760675
int _E538_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_6, "AL_0DL_7PL");
  return atexit(_E539_2);
}

//----- (006E3F30) --------------------------------------------------------  // acclient.c:760682
int _E541_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_6, "AL_0DL_8PL");
  return atexit(_E542_2);
}

//----- (006E3F50) --------------------------------------------------------  // acclient.c:760689
int _E544_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_6, "AL_1DL_0PL");
  return atexit(_E545_2);
}

//----- (006E3F70) --------------------------------------------------------  // acclient.c:760696
int _E547_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_6, "AL_1DL_1PL");
  return atexit(_E548_2);
}

//----- (006E3F90) --------------------------------------------------------  // acclient.c:760703
int _E550_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_6, "AL_1DL_2PL");
  return atexit(_E551_2);
}

//----- (006E3FB0) --------------------------------------------------------  // acclient.c:760710
int _E553_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_6, "AL_1DL_3PL");
  return atexit(_E554_2);
}

//----- (006E3FD0) --------------------------------------------------------  // acclient.c:760717
int _E556_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_6, "AL_1DL_4PL");
  return atexit(_E557_2);
}

//----- (006E3FF0) --------------------------------------------------------  // acclient.c:760724
int _E559_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_6, "AL_1DL_5PL");
  return atexit(_E560_2);
}

//----- (006E4010) --------------------------------------------------------  // acclient.c:760731
int _E562_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_6, "AL_1DL_6PL");
  return atexit(_E563_2);
}

//----- (006E4030) --------------------------------------------------------  // acclient.c:760738
int _E565_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_6, "AL_1DL_7PL");
  return atexit(_E566_2);
}

//----- (006E4050) --------------------------------------------------------  // acclient.c:760745
int _E568_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_6, "AL_0DL_0PL_Fog");
  return atexit(_E569_2);
}

//----- (006E4070) --------------------------------------------------------  // acclient.c:760752
int _E571_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_6, "AL_0DL_1PL_Fog");
  return atexit(_E572_2);
}

//----- (006E4090) --------------------------------------------------------  // acclient.c:760759
int _E574_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_6, "AL_0DL_2PL_Fog");
  return atexit(_E575_2);
}

//----- (006E40B0) --------------------------------------------------------  // acclient.c:760766
int _E577_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_6, "AL_0DL_3PL_Fog");
  return atexit(_E578_2);
}

//----- (006E40D0) --------------------------------------------------------  // acclient.c:760773
int _E580_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_6, "AL_0DL_4PL_Fog");
  return atexit(_E581_2);
}

//----- (006E40F0) --------------------------------------------------------  // acclient.c:760780
int _E583_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_6, "AL_0DL_5PL_Fog");
  return atexit(_E584_2);
}

//----- (006E4110) --------------------------------------------------------  // acclient.c:760787
int _E586_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_6, "AL_0DL_6PL_Fog");
  return atexit(_E587_2);
}

//----- (006E4130) --------------------------------------------------------  // acclient.c:760794
int _E589_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_6, "AL_0DL_7PL_Fog");
  return atexit(_E590_2);
}

//----- (006E4150) --------------------------------------------------------  // acclient.c:760801
int _E592_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_6, "AL_0DL_8PL_Fog");
  return atexit(_E593_2);
}

//----- (006E4170) --------------------------------------------------------  // acclient.c:760808
int _E595_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_6, "AL_1DL_0PL_Fog");
  return atexit(_E596_2);
}

//----- (006E4190) --------------------------------------------------------  // acclient.c:760815
int _E598_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_6, "AL_1DL_1PL_Fog");
  return atexit(_E599_2);
}

//----- (006E41B0) --------------------------------------------------------  // acclient.c:760822
int _E601_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_6, "AL_1DL_2PL_Fog");
  return atexit(_E602_2);
}

//----- (006E41D0) --------------------------------------------------------  // acclient.c:760829
int _E604_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_6, "AL_1DL_3PL_Fog");
  return atexit(_E605_2);
}

//----- (006E41F0) --------------------------------------------------------  // acclient.c:760836
int _E607_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_6, "AL_1DL_4PL_Fog");
  return atexit(_E608_2);
}

//----- (006E4210) --------------------------------------------------------  // acclient.c:760843
int _E610_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_6, "AL_1DL_5PL_Fog");
  return atexit(_E611_2);
}

//----- (006E4230) --------------------------------------------------------  // acclient.c:760850
int _E613_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_6, "AL_1DL_6PL_Fog");
  return atexit(_E614_2);
}

//----- (006E4250) --------------------------------------------------------  // acclient.c:760857
int _E616_2()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_6, "AL_1DL_7PL_Fog");
  return atexit(_E617_2);
}

//----- (006E4270) --------------------------------------------------------  // acclient.c:760864
int _E619_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_6, "Zero");
  return atexit(_E620_2);
}

//----- (006E4290) --------------------------------------------------------  // acclient.c:760871
int _E622_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_6, "One");
  return atexit(_E623_2);
}

//----- (006E42B0) --------------------------------------------------------  // acclient.c:760878
int _E625_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_6, "SrcColor");
  return atexit(_E626_2);
}

//----- (006E42D0) --------------------------------------------------------  // acclient.c:760885
int _E628_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_6, "InvSrcColor");
  return atexit(_E629_2);
}

//----- (006E42F0) --------------------------------------------------------  // acclient.c:760892
int _E631_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_6, "SrcAlpha");
  return atexit(_E632_2);
}

//----- (006E4310) --------------------------------------------------------  // acclient.c:760899
int _E634_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_6, "InvSrcAlpha");
  return atexit(_E635_2);
}

//----- (006E4330) --------------------------------------------------------  // acclient.c:760906
int _E637_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_6, "DstAlpha");
  return atexit(_E638_2);
}

//----- (006E4350) --------------------------------------------------------  // acclient.c:760913
int _E640_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_6, "InvDstAlpha");
  return atexit(_E641_2);
}

//----- (006E4370) --------------------------------------------------------  // acclient.c:760920
int _E643_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_6, "DstColor");
  return atexit(_E644_2);
}

//----- (006E4390) --------------------------------------------------------  // acclient.c:760927
int _E646_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_6, "InvDstColor");
  return atexit(_E647_2);
}

//----- (006E43B0) --------------------------------------------------------  // acclient.c:760934
int _E649_2()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_6, "SrcAlphaSat");
  return atexit(_E650_2);
}

//----- (006E43D0) --------------------------------------------------------  // acclient.c:760941
int _E652_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_6, "Less");
  return atexit(_E653_2);
}

//----- (006E43F0) --------------------------------------------------------  // acclient.c:760948
int _E655_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_6, "Equal");
  return atexit(_E656_2);
}

//----- (006E4410) --------------------------------------------------------  // acclient.c:760955
int _E658_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_6, "LessEqual");
  return atexit(_E659_2);
}

//----- (006E4430) --------------------------------------------------------  // acclient.c:760962
int _E661_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_6, "Greater");
  return atexit(_E662_2);
}

//----- (006E4450) --------------------------------------------------------  // acclient.c:760969
int _E664_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_6, "NotEqual");
  return atexit(_E665_2);
}

//----- (006E4470) --------------------------------------------------------  // acclient.c:760976
int _E667_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_6, "GreaterEqual");
  return atexit(_E668_2);
}

//----- (006E4490) --------------------------------------------------------  // acclient.c:760983
int _E670_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_6, "Always");
  return atexit(_E671_2);
}

//----- (006E44B0) --------------------------------------------------------  // acclient.c:760990
int _E673_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_6, "On");
  return atexit(_E674_2);
}

//----- (006E44D0) --------------------------------------------------------  // acclient.c:760997
int _E676_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_6, "Off");
  return atexit(_E677_2);
}

//----- (006E44F0) --------------------------------------------------------  // acclient.c:761004
int _E679_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_6, "LayerDiffuse");
  return atexit(_E680_2);
}

//----- (006E4510) --------------------------------------------------------  // acclient.c:761011
int _E682_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_6, "LayerSpecular");
  return atexit(_E683_2);
}

//----- (006E4530) --------------------------------------------------------  // acclient.c:761018
int _E685_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_6, "VertexDiffuse");
  return atexit(_E686_2);
}

//----- (006E4550) --------------------------------------------------------  // acclient.c:761025
int _E688_2()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_6, "VertexSpecular");
  return atexit(_E689_2);
}

//----- (006E4570) --------------------------------------------------------  // acclient.c:761032
int _E691_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_6, "None");
  return atexit(_E692_2);
}

//----- (006E4590) --------------------------------------------------------  // acclient.c:761039
int _E694_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_6, "CW");
  return atexit(_E695_2);
}

//----- (006E45B0) --------------------------------------------------------  // acclient.c:761046
int _E697_2()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_6, "CCW");
  return atexit(_E698_2);
}

//----- (006E45D0) --------------------------------------------------------  // acclient.c:761053
int _E700_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_6, "None");
  return atexit(_E701_2);
}

//----- (006E45F0) --------------------------------------------------------  // acclient.c:761060
int _E703_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_6, "Simple");
  return atexit(_E704_2);
}

//----- (006E4610) --------------------------------------------------------  // acclient.c:761067
int _E706_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_6, "Diffuse");
  return atexit(_E707_2);
}

//----- (006E4630) --------------------------------------------------------  // acclient.c:761074
int _E709_2()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_6, "Specular");
  return atexit(_E710_2);
}

//----- (006E4650) --------------------------------------------------------  // acclient.c:761081
int _E712_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_6, "Off");
  return atexit(_E713_2);
}

//----- (006E4670) --------------------------------------------------------  // acclient.c:761088
int _E715_2()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_6, "On");
  return atexit(_E716_2);
}

//----- (006E4690) --------------------------------------------------------  // acclient.c:761095
int _E718_2()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_6, "Off");
  return atexit(_E719_2);
}

//----- (006E46B0) --------------------------------------------------------  // acclient.c:761102
int _E721_2()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_6, "On");
  return atexit(_E722_2);
}

//----- (006E46D0) --------------------------------------------------------  // acclient.c:761109
int _E724_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_6, "Origin");
  return atexit(_E725_2);
}

//----- (006E46F0) --------------------------------------------------------  // acclient.c:761116
int _E727_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_6, "Normal");
  return atexit(_E728_2);
}

//----- (006E4710) --------------------------------------------------------  // acclient.c:761123
int _E730_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_6, "PointSize");
  return atexit(_E731_2);
}

//----- (006E4730) --------------------------------------------------------  // acclient.c:761130
int _E733_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_6, "Diffuse");
  return atexit(_E734_2);
}

//----- (006E4750) --------------------------------------------------------  // acclient.c:761137
int _E736_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_6, "Specular");
  return atexit(_E737_2);
}

//----- (006E4770) --------------------------------------------------------  // acclient.c:761144
int _E739_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_6, "TCPairX1");
  return atexit(_E740_2);
}

//----- (006E4790) --------------------------------------------------------  // acclient.c:761151
int _E742_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_6, "TCPairX2");
  return atexit(_E743_2);
}

//----- (006E47B0) --------------------------------------------------------  // acclient.c:761158
int _E745_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_6, "TCPairX3");
  return atexit(_E746_2);
}

//----- (006E47D0) --------------------------------------------------------  // acclient.c:761165
int _E748_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_6, "TCPairX4");
  return atexit(_E749_2);
}

//----- (006E47F0) --------------------------------------------------------  // acclient.c:761172
int _E751_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_6, "TCPairX5");
  return atexit(_E752_2);
}

//----- (006E4810) --------------------------------------------------------  // acclient.c:761179
int _E754_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_6, "TCPairX6");
  return atexit(_E755_2);
}

//----- (006E4830) --------------------------------------------------------  // acclient.c:761186
int _E757_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_6, "TCPairX7");
  return atexit(_E758_2);
}

//----- (006E4850) --------------------------------------------------------  // acclient.c:761193
int _E760_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_6, "TCPairX8");
  return atexit(_E761_2);
}

//----- (006E4870) --------------------------------------------------------  // acclient.c:761200
int _E763_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_6, "VectorS");
  return atexit(_E764_2);
}

//----- (006E4890) --------------------------------------------------------  // acclient.c:761207
int _E766_2()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_6, "VectorT");
  return atexit(_E767_2);
}

//----- (006E48B0) --------------------------------------------------------  // acclient.c:761214
int _E769_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_74, "Stage");
  return atexit(_E770_2);
}

//----- (006E48D0) --------------------------------------------------------  // acclient.c:761221
int _E772_2()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_6, "Sampler");
  return atexit(_E773_2);
}

//----- (006E48F0) --------------------------------------------------------  // acclient.c:761228
int _E775_2()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_6, "SamplerName");
  return atexit(_E776_2);
}

//----- (006E4910) --------------------------------------------------------  // acclient.c:761235
int _E778_2()
{
  PStringBase<char>::PStringBase<char>(&Texture_6, "Texture");
  return atexit(_E779_2);
}

//----- (006E4930) --------------------------------------------------------  // acclient.c:761242
int _E781_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_6, "!FrameBuffer");
  return atexit(_E782_2);
}

//----- (006E4950) --------------------------------------------------------  // acclient.c:761249
int _E784_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_6, "!Distortion");
  return atexit(_E785_2);
}

//----- (006E4970) --------------------------------------------------------  // acclient.c:761256
int _E787_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_6, "!Reflection");
  return atexit(_E788_2);
}

//----- (006E4990) --------------------------------------------------------  // acclient.c:761263
int _E790_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_6, "!NormalizeCube");
  return atexit(_E791_2);
}

//----- (006E49B0) --------------------------------------------------------  // acclient.c:761270
int _E793_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_6, "!LightProjectorCube");
  return atexit(_E794_2);
}

//----- (006E49D0) --------------------------------------------------------  // acclient.c:761277
int _E796_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_6, "!EnvironmentCube");
  return atexit(_E797_2);
}

//----- (006E49F0) --------------------------------------------------------  // acclient.c:761284
int _E799_2()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_6, "!LandscapeShadows");
  return atexit(_E800_2);
}

//----- (006E4A10) --------------------------------------------------------  // acclient.c:761291
int _E802_2()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_6, "AddressMode");
  return atexit(_E803_2);
}

//----- (006E4A30) --------------------------------------------------------  // acclient.c:761298
int _E805_2()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_6, "FilterMode");
  return atexit(_E806_2);
}

//----- (006E4A50) --------------------------------------------------------  // acclient.c:761305
int _E808_2()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_6, "FFColorOp");
  return atexit(_E809_2);
}

//----- (006E4A70) --------------------------------------------------------  // acclient.c:761312
int _E811_2()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_6, "FFColorArg1");
  return atexit(_E812_2);
}

//----- (006E4A90) --------------------------------------------------------  // acclient.c:761319
int _E814_2()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_6, "FFColorArg2");
  return atexit(_E815_2);
}

//----- (006E4AB0) --------------------------------------------------------  // acclient.c:761326
int _E817_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_6, "FFAlphaOp");
  return atexit(_E818_2);
}

//----- (006E4AD0) --------------------------------------------------------  // acclient.c:761333
int _E820_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_6, "FFAlphaArg1");
  return atexit(_E821_2);
}

//----- (006E4AF0) --------------------------------------------------------  // acclient.c:761340
int _E823_2()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_6, "FFAlphaArg2");
  return atexit(_E824_2);
}

//----- (006E4B10) --------------------------------------------------------  // acclient.c:761347
int _E826_2()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_6, "FFTexCoordIndex");
  return atexit(_E827_2);
}

//----- (006E4B30) --------------------------------------------------------  // acclient.c:761354
int _E829_2()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_6, "FFUseProjection");
  return atexit(_E830_2);
}

//----- (006E4B50) --------------------------------------------------------  // acclient.c:761361
int _E832_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_6, "SelectArg1");
  return atexit(_E833_2);
}

//----- (006E4B70) --------------------------------------------------------  // acclient.c:761368
int _E835_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_6, "SelectArg2");
  return atexit(_E836_2);
}

//----- (006E4B90) --------------------------------------------------------  // acclient.c:761375
int _E838_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_6, "Modulate");
  return atexit(_E839_2);
}

//----- (006E4BB0) --------------------------------------------------------  // acclient.c:761382
int _E841_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_6, "Modulate2X");
  return atexit(_E842_2);
}

//----- (006E4BD0) --------------------------------------------------------  // acclient.c:761389
int _E844_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_6, "Modulate4X");
  return atexit(_E845_2);
}

//----- (006E4BF0) --------------------------------------------------------  // acclient.c:761396
int _E847_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_6, "Add");
  return atexit(_E848_2);
}

//----- (006E4C10) --------------------------------------------------------  // acclient.c:761403
int _E850_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_6, "AddSigned");
  return atexit(_E851_2);
}

//----- (006E4C30) --------------------------------------------------------  // acclient.c:761410
int _E853_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_6, "AddSigned2X");
  return atexit(_E854_2);
}

//----- (006E4C50) --------------------------------------------------------  // acclient.c:761417
int _E856_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_6, "Subtract");
  return atexit(_E857_2);
}

//----- (006E4C70) --------------------------------------------------------  // acclient.c:761424
int _E859_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_6, "AddSmooth");
  return atexit(_E860_2);
}

//----- (006E4C90) --------------------------------------------------------  // acclient.c:761431
int _E862_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_6, "BlendDiffuseAlpha");
  return atexit(_E863_2);
}

//----- (006E4CB0) --------------------------------------------------------  // acclient.c:761438
int _E865_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_6, "BlendTextureAlpha");
  return atexit(_E866_2);
}

//----- (006E4CD0) --------------------------------------------------------  // acclient.c:761445
int _E868_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_6, "BlendFactorAlpha");
  return atexit(_E869_2);
}

//----- (006E4CF0) --------------------------------------------------------  // acclient.c:761452
int _E871_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_6, "BlendTextureAlphaPM");
  return atexit(_E872_2);
}

//----- (006E4D10) --------------------------------------------------------  // acclient.c:761459
int _E874_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_6, "BlendCurrentAlpha");
  return atexit(_E875_2);
}

//----- (006E4D30) --------------------------------------------------------  // acclient.c:761466
int _E877_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_6, "Premodulate");
  return atexit(_E878_2);
}

//----- (006E4D50) --------------------------------------------------------  // acclient.c:761473
int _E880_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_6, "ModulateAlphaAddColor");
  return atexit(_E881_2);
}

//----- (006E4D70) --------------------------------------------------------  // acclient.c:761480
int _E883_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_6, "ModulateColorAddAlpha");
  return atexit(_E884_2);
}

//----- (006E4D90) --------------------------------------------------------  // acclient.c:761487
int _E886_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_6, "ModulateInvAlphaAddColor");
  return atexit(_E887_2);
}

//----- (006E4DB0) --------------------------------------------------------  // acclient.c:761494
int _E889_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_6, "ModulateInvColorAddAlpha");
  return atexit(_E890_2);
}

//----- (006E4DD0) --------------------------------------------------------  // acclient.c:761501
int _E892_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_6, "BumpEnvMap");
  return atexit(_E893_2);
}

//----- (006E4DF0) --------------------------------------------------------  // acclient.c:761508
int _E895_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_6, "BumpEnvMapLuminance");
  return atexit(_E896_2);
}

//----- (006E4E10) --------------------------------------------------------  // acclient.c:761515
int _E898_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_6, "DotProduct3");
  return atexit(_E899_2);
}

//----- (006E4E30) --------------------------------------------------------  // acclient.c:761522
int _E901_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_6, "MultiplyAdd");
  return atexit(_E902_2);
}

//----- (006E4E50) --------------------------------------------------------  // acclient.c:761529
int _E904_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_6, "Lerp");
  return atexit(_E905_2);
}

//----- (006E4E70) --------------------------------------------------------  // acclient.c:761536
int _E907_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_6, "Diffuse");
  return atexit(_E908_2);
}

//----- (006E4E90) --------------------------------------------------------  // acclient.c:761543
int _E910_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_6, "Specular");
  return atexit(_E911_2);
}

//----- (006E4EB0) --------------------------------------------------------  // acclient.c:761550
int _E913_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_6, "Current");
  return atexit(_E914_2);
}

//----- (006E4ED0) --------------------------------------------------------  // acclient.c:761557
int _E916_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_6, "Texture");
  return atexit(_E917_2);
}

//----- (006E4EF0) --------------------------------------------------------  // acclient.c:761564
int _E919_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_6, "TFactor");
  return atexit(_E920_2);
}

//----- (006E4F10) --------------------------------------------------------  // acclient.c:761571
int _E922_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_6, "Wrap");
  return atexit(_E923_2);
}

//----- (006E4F30) --------------------------------------------------------  // acclient.c:761578
int _E925_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_6, "Mirror");
  return atexit(_E926_2);
}

//----- (006E4F50) --------------------------------------------------------  // acclient.c:761585
int _E928_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_6, "Clamp");
  return atexit(_E929_2);
}

//----- (006E4F70) --------------------------------------------------------  // acclient.c:761592
int _E931_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_6, "Border");
  return atexit(_E932_2);
}

//----- (006E4F90) --------------------------------------------------------  // acclient.c:761599
int _E934_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_6, "None");
  return atexit(_E935_2);
}

//----- (006E4FB0) --------------------------------------------------------  // acclient.c:761606
int _E937_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_6, "Point");
  return atexit(_E938_2);
}

//----- (006E4FD0) --------------------------------------------------------  // acclient.c:761613
int _E940_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_6, "Linear");
  return atexit(_E941_2);
}

//----- (006E4FF0) --------------------------------------------------------  // acclient.c:761620
int _E943_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_6, "Anisotropic");
  return atexit(_E944_2);
}

//----- (006E5010) --------------------------------------------------------  // acclient.c:761627
int _E946_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_6, "ReflectionVector");
  return atexit(_E947_2);
}

//----- (006E5030) --------------------------------------------------------  // acclient.c:761634
int _E949_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_6, "ViewNormal");
  return atexit(_E950_2);
}

//----- (006E5050) --------------------------------------------------------  // acclient.c:761641
int _E952_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_6, "ViewOrigin");
  return atexit(_E953_2);
}

//----- (006E5070) --------------------------------------------------------  // acclient.c:761648
int _E955_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_6, "SphereMap");
  return atexit(_E956_2);
}

//----- (006E5090) --------------------------------------------------------  // acclient.c:761655
int _E958_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_6, "CubeMapReflection");
  return atexit(_E959_2);
}

//----- (006E50B0) --------------------------------------------------------  // acclient.c:761662
int _E961_2()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_6, "CubeMapFakeLight");
  return atexit(_E962_2);
}

//----- (006E50D0) --------------------------------------------------------  // acclient.c:761669
int _E964_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_75, "FFModifier");
  return atexit(_E965_2);
}

//----- (006E50F0) --------------------------------------------------------  // acclient.c:761676
int _E967_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_6, "Origin");
  return atexit(_E968_2);
}

//----- (006E5110) --------------------------------------------------------  // acclient.c:761683
int _E970_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_6, "Normal");
  return atexit(_E971_2);
}

//----- (006E5130) --------------------------------------------------------  // acclient.c:761690
int _E973_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_6, "Diffuse");
  return atexit(_E974_2);
}

//----- (006E5150) --------------------------------------------------------  // acclient.c:761697
int _E976_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_6, "UVTranslate");
  return atexit(_E977_2);
}

//----- (006E5170) --------------------------------------------------------  // acclient.c:761704
int _E979_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_6, "UVRotate");
  return atexit(_E980_2);
}

//----- (006E5190) --------------------------------------------------------  // acclient.c:761711
int _E982_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_6, "UVScale");
  return atexit(_E983_2);
}

//----- (006E51B0) --------------------------------------------------------  // acclient.c:761718
int _E985_2()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_6, "UVTransform");
  return atexit(_E986_2);
}

//----- (006E51D0) --------------------------------------------------------  // acclient.c:761725
int _E988_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_6, "TexCoordIndex");
  return atexit(_E989_2);
}

//----- (006E51F0) --------------------------------------------------------  // acclient.c:761732
int _E991_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_6, "Translate");
  return atexit(_E992_2);
}

//----- (006E5210) --------------------------------------------------------  // acclient.c:761739
int _E994_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_6, "TexCoordIndex");
  return atexit(_E995_2);
}

//----- (006E5230) --------------------------------------------------------  // acclient.c:761746
int _E997_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_6, "Rotate");
  return atexit(_E998_2);
}

//----- (006E5250) --------------------------------------------------------  // acclient.c:761753
int _E1000_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_6, "TexCoordIndex");
  return atexit(_E1001_2);
}

//----- (006E5270) --------------------------------------------------------  // acclient.c:761760
int _E1003_2()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_6, "Scale");
  return atexit(_E1004_2);
}

//----- (006E5290) --------------------------------------------------------  // acclient.c:761767
int _E1006_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_76, "PSDesc");
  return atexit(_E1007_2);
}

//----- (006E52B0) --------------------------------------------------------  // acclient.c:761774
int _E1009_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_6, "PhysicsTimeStep");
  return atexit(_E1010_2);
}

//----- (006E52D0) --------------------------------------------------------  // acclient.c:761781
int _E1012_2()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_6, "FastForwardTime");
  return atexit(_E1013_2);
}

//----- (006E52F0) --------------------------------------------------------  // acclient.c:761788
int _E1015_2()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_6, "StartFadeDistance");
  return atexit(_E1016_2);
}

//----- (006E5310) --------------------------------------------------------  // acclient.c:761795
int _E1018_2()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_6, "StopFadeDistance");
  return atexit(_E1019_2);
}

//----- (006E5330) --------------------------------------------------------  // acclient.c:761802
int _E1021_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_6, "PhysicsDuration");
  return atexit(_E1022_2);
}

//----- (006E5350) --------------------------------------------------------  // acclient.c:761809
int _E1024_2()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_6, "ScaleType");
  return atexit(_E1025_2);
}

//----- (006E5370) --------------------------------------------------------  // acclient.c:761816
int _E1027_2()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_6, "WorldSpace");
  return atexit(_E1028_2);
}

//----- (006E5390) --------------------------------------------------------  // acclient.c:761823
int _E1030_2()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_6, "ForceDraw");
  return atexit(_E1031_2);
}

//----- (006E53B0) --------------------------------------------------------  // acclient.c:761830
int _E1033_2()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_6, "NumEmitters");
  return atexit(_E1034_2);
}

//----- (006E53D0) --------------------------------------------------------  // acclient.c:761837
int _E1036_2()
{
  PStringBase<char>::PStringBase<char>(&Material_33, "Material");
  return atexit(_E1037_2);
}

//----- (006E53F0) --------------------------------------------------------  // acclient.c:761844
int _E1039_2()
{
  PStringBase<char>::PStringBase<char>(&Version_6, "Version");
  return atexit(_E1040_2);
}

//----- (006E5410) --------------------------------------------------------  // acclient.c:761851
int _E1042_2()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_6, "MaxParticles");
  return atexit(_E1043_2);
}

//----- (006E5430) --------------------------------------------------------  // acclient.c:761858
int _E1045_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_77, "Emitter");
  return atexit(_E1046_2);
}

//----- (006E5450) --------------------------------------------------------  // acclient.c:761865
int _E1048_2()
{
  PStringBase<char>::PStringBase<char>(&Origin_14, "Origin");
  return atexit(_E1049_2);
}

//----- (006E5470) --------------------------------------------------------  // acclient.c:761872
int _E1051_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_6, "Shape");
  return atexit(_E1052_2);
}

//----- (006E5490) --------------------------------------------------------  // acclient.c:761879
int _E1054_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_6, "Point");
  return atexit(_E1055_2);
}

//----- (006E54B0) --------------------------------------------------------  // acclient.c:761886
int _E1057_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_6, "Line");
  return atexit(_E1058_2);
}

//----- (006E54D0) --------------------------------------------------------  // acclient.c:761893
int _E1060_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_6, "Quad");
  return atexit(_E1061_2);
}

//----- (006E54F0) --------------------------------------------------------  // acclient.c:761900
int _E1063_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_6, "Disc");
  return atexit(_E1064_2);
}

//----- (006E5510) --------------------------------------------------------  // acclient.c:761907
int _E1066_2()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_6, "Sphere");
  return atexit(_E1067_2);
}

//----- (006E5530) --------------------------------------------------------  // acclient.c:761914
int _E1069_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_6, "ParticleShape");
  return atexit(_E1070_2);
}

//----- (006E5550) --------------------------------------------------------  // acclient.c:761921
int _E1072_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_6, "Triangle");
  return atexit(_E1073_2);
}

//----- (006E5570) --------------------------------------------------------  // acclient.c:761928
int _E1075_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_6, "Quad");
  return atexit(_E1076_2);
}

//----- (006E5590) --------------------------------------------------------  // acclient.c:761935
int _E1078_2()
{
  PStringBase<char>::PStringBase<char>(&Streak_6, "Streak");
  return atexit(_E1079_2);
}

//----- (006E55B0) --------------------------------------------------------  // acclient.c:761942
int _E1081_2()
{
  PStringBase<char>::PStringBase<char>(&Rotation_14, "Rotation");
  return atexit(_E1082_2);
}

//----- (006E55D0) --------------------------------------------------------  // acclient.c:761949
int _E1084_2()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_6, "WorldRotation");
  return atexit(_E1085_2);
}

//----- (006E55F0) --------------------------------------------------------  // acclient.c:761956
int _E1087_2()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_6, "RotateVelocity");
  return atexit(_E1088_2);
}

//----- (006E5610) --------------------------------------------------------  // acclient.c:761963
int _E1090_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_6, "ParticleScale");
  return atexit(_E1091_2);
}

//----- (006E5630) --------------------------------------------------------  // acclient.c:761970
int _E1093_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_21, "Scale");
  return atexit(_E1094_2);
}

//----- (006E5650) --------------------------------------------------------  // acclient.c:761977
int _E1096_2()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_6, "ExplodingDir");
  return atexit(_E1097_2);
}

//----- (006E5670) --------------------------------------------------------  // acclient.c:761984
int _E1099_2()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_6, "BirthRate");
  return atexit(_E1100_2);
}

//----- (006E5690) --------------------------------------------------------  // acclient.c:761991
int _E1102_2()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_6, "Lifespan");
  return atexit(_E1103_2);
}

//----- (006E56B0) --------------------------------------------------------  // acclient.c:761998
int _E1105_2()
{
  PStringBase<char>::PStringBase<char>(&Velocity_6, "Velocity");
  return atexit(_E1106_2);
}

//----- (006E56D0) --------------------------------------------------------  // acclient.c:762005
int _E1108_2()
{
  PStringBase<char>::PStringBase<char>(&Direction_6, "Direction");
  return atexit(_E1109_2);
}

//----- (006E56F0) --------------------------------------------------------  // acclient.c:762012
int _E1111_2()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_6, "MinSpread");
  return atexit(_E1112_2);
}

//----- (006E5710) --------------------------------------------------------  // acclient.c:762019
int _E1114_2()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_6, "MaxSpread");
  return atexit(_E1115_2);
}

//----- (006E5730) --------------------------------------------------------  // acclient.c:762026
int _E1117_2()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_6, "EmissionLimit");
  return atexit(_E1118_2);
}

//----- (006E5750) --------------------------------------------------------  // acclient.c:762033
int _E1120_2()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_6, "BlastCount");
  return atexit(_E1121_2);
}

//----- (006E5770) --------------------------------------------------------  // acclient.c:762040
int _E1123_2()
{
  PStringBase<char>::PStringBase<char>(&StartTime_6, "StartTime");
  return atexit(_E1124_2);
}

//----- (006E5790) --------------------------------------------------------  // acclient.c:762047
int _E1126_2()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_6, "TimeLimit");
  return atexit(_E1127_2);
}

//----- (006E57B0) --------------------------------------------------------  // acclient.c:762054
int _E1129_2()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_6, "EmissionDistance");
  return atexit(_E1130_2);
}

//----- (006E57D0) --------------------------------------------------------  // acclient.c:762061
int _E1132_2()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_6, "ParticleSnap");
  return atexit(_E1133_2);
}

//----- (006E57F0) --------------------------------------------------------  // acclient.c:762068
int _E1135_2()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_6, "InclusiveShape");
  return atexit(_E1136_2);
}

//----- (006E5810) --------------------------------------------------------  // acclient.c:762075
int _E1138_2()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_6, "NumKeyframes");
  return atexit(_E1139_2);
}

//----- (006E5830) --------------------------------------------------------  // acclient.c:762082
int _E1141_2()
{
  PStringBase<char>::PStringBase<char>(&IsActive_6, "IsActive");
  return atexit(_E1142_2);
}

//----- (006E5850) --------------------------------------------------------  // acclient.c:762089
int _E1144_2()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_6, "FadeIn");
  return atexit(_E1145_2);
}

//----- (006E5870) --------------------------------------------------------  // acclient.c:762096
int _E1147_2()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_6, "FadeOut");
  return atexit(_E1148_2);
}

//----- (006E5890) --------------------------------------------------------  // acclient.c:762103
int _E1150_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_6, "ConstrainX");
  return atexit(_E1151_2);
}

//----- (006E58B0) --------------------------------------------------------  // acclient.c:762110
int _E1153_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_6, "ConstrainY");
  return atexit(_E1154_2);
}

//----- (006E58D0) --------------------------------------------------------  // acclient.c:762117
int _E1156_2()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_6, "ConstrainZ");
  return atexit(_E1157_2);
}

//----- (006E58F0) --------------------------------------------------------  // acclient.c:762124
int _E1159_2()
{
  PStringBase<char>::PStringBase<char>(&NodeName_78, "Keyframe");
  return atexit(_E1160_2);
}

//----- (006E5910) --------------------------------------------------------  // acclient.c:762131
int _E1162_2()
{
  PStringBase<char>::PStringBase<char>(&Time_6, "Time");
  return atexit(_E1163_2);
}

//----- (006E5930) --------------------------------------------------------  // acclient.c:762138
int _E1165_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_6, "Flags");
  return atexit(_E1166_2);
}

//----- (006E5950) --------------------------------------------------------  // acclient.c:762145
int _E1168_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_6, "None");
  return atexit(_E1169_2);
}

//----- (006E5970) --------------------------------------------------------  // acclient.c:762152
int _E1171_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_6, "BlendScale");
  return atexit(_E1172_2);
}

//----- (006E5990) --------------------------------------------------------  // acclient.c:762159
int _E1174_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_6, "BlendColor");
  return atexit(_E1175_2);
}

//----- (006E59B0) --------------------------------------------------------  // acclient.c:762166
int _E1177_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_6, "BlendMass");
  return atexit(_E1178_2);
}

//----- (006E59D0) --------------------------------------------------------  // acclient.c:762173
int _E1180_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_6, "SetScale");
  return atexit(_E1181_2);
}

//----- (006E59F0) --------------------------------------------------------  // acclient.c:762180
int _E1183_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_6, "SetColor");
  return atexit(_E1184_2);
}

//----- (006E5A10) --------------------------------------------------------  // acclient.c:762187
int _E1186_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_6, "SetMass");
  return atexit(_E1187_2);
}

//----- (006E5A30) --------------------------------------------------------  // acclient.c:762194
int _E1189_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_6, "SetParticleFlags");
  return atexit(_E1190_2);
}

//----- (006E5A50) --------------------------------------------------------  // acclient.c:762201
int _E1192_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_6, "SetControllerType");
  return atexit(_E1193_2);
}

//----- (006E5A70) --------------------------------------------------------  // acclient.c:762208
int _E1195_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_6, "SetPhysicsFlags");
  return atexit(_E1196_2);
}

//----- (006E5A90) --------------------------------------------------------  // acclient.c:762215
int _E1198_2()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_6, "SetParams");
  return atexit(_E1199_2);
}

//----- (006E5AB0) --------------------------------------------------------  // acclient.c:762222
int _E1201_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_22, "Scale");
  return atexit(_E1202_2);
}

//----- (006E5AD0) --------------------------------------------------------  // acclient.c:762229
int _E1204_2()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_6, "ScaleX");
  return atexit(_E1205_2);
}

//----- (006E5AF0) --------------------------------------------------------  // acclient.c:762236
int _E1207_2()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_6, "ScaleY");
  return atexit(_E1208_2);
}

//----- (006E5B10) --------------------------------------------------------  // acclient.c:762243
int _E1210_2()
{
  PStringBase<char>::PStringBase<char>(&Color_6, "Color");
  return atexit(_E1211_2);
}

//----- (006E5B30) --------------------------------------------------------  // acclient.c:762250
int _E1213_2()
{
  PStringBase<char>::PStringBase<char>(&Mass_6, "Mass");
  return atexit(_E1214_2);
}

//----- (006E5B50) --------------------------------------------------------  // acclient.c:762257
int _E1216_2()
{
  PStringBase<char>::PStringBase<char>(&PFlags_6, "ParticleFlags");
  return atexit(_E1217_2);
}

//----- (006E5B70) --------------------------------------------------------  // acclient.c:762264
int _E1219_2()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_6, "None");
  return atexit(_E1220_2);
}

//----- (006E5B90) --------------------------------------------------------  // acclient.c:762271
int _E1222_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_6, "ControllerType");
  return atexit(_E1223_2);
}

//----- (006E5BB0) --------------------------------------------------------  // acclient.c:762278
int _E1225_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_6, "None");
  return atexit(_E1226_2);
}

//----- (006E5BD0) --------------------------------------------------------  // acclient.c:762285
int _E1228_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_6, "Physics");
  return atexit(_E1229_2);
}

//----- (006E5BF0) --------------------------------------------------------  // acclient.c:762292
int _E1231_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_6, "Parametric");
  return atexit(_E1232_2);
}

//----- (006E5C10) --------------------------------------------------------  // acclient.c:762299
int _E1234_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_6, "AttractRepulse");
  return atexit(_E1235_2);
}

//----- (006E5C30) --------------------------------------------------------  // acclient.c:762306
int _E1237_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_6, "PointFile");
  return atexit(_E1238_2);
}

//----- (006E5C50) --------------------------------------------------------  // acclient.c:762313
int _E1240_2()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_6, "PointFileLerp");
  return atexit(_E1241_2);
}

//----- (006E5C70) --------------------------------------------------------  // acclient.c:762320
int _E1243_2()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_6, "PhysicsFlags");
  return atexit(_E1244_2);
}

//----- (006E5C90) --------------------------------------------------------  // acclient.c:762327
int _E1246_2()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_6, "None");
  return atexit(_E1247_2);
}

//----- (006E5CB0) --------------------------------------------------------  // acclient.c:762334
int _E1249_2()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_6, "Gravity");
  return atexit(_E1250_2);
}

//----- (006E5CD0) --------------------------------------------------------  // acclient.c:762341
int _E1252_2()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_6, "Wind");
  return atexit(_E1253_2);
}

//----- (006E5CF0) --------------------------------------------------------  // acclient.c:762348
int _E1255_2()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_6, "Momentum");
  return atexit(_E1256_2);
}

//----- (006E5D10) --------------------------------------------------------  // acclient.c:762355
int _E1258_2()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_6, "RandomPoint");
  return atexit(_E1259_2);
}

//----- (006E5D30) --------------------------------------------------------  // acclient.c:762362
int _E1261_2()
{
  PStringBase<char>::PStringBase<char>(&Position_7, "Position");
  return atexit(_E1262_2);
}

//----- (006E5D50) --------------------------------------------------------  // acclient.c:762369
int _E1264_2()
{
  PStringBase<char>::PStringBase<char>(&PointList_6, "PointList");
  return atexit(_E1265_2);
}

//----- (006E5D70) --------------------------------------------------------  // acclient.c:762376
int _E1267_2()
{
  PStringBase<char>::PStringBase<char>(&Point_14, "pt");
  return atexit(_E1268_2);
}

//----- (006E5D90) --------------------------------------------------------  // acclient.c:762383
int _E1270_2()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_6, "DetailLevels");
  return atexit(_E1271_2);
}

//----- (006E5DB0) --------------------------------------------------------  // acclient.c:762390
int _E1273_2()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_6, "Low");
  return atexit(_E1274_2);
}

//----- (006E5DD0) --------------------------------------------------------  // acclient.c:762397
int _E1276_2()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_6, "Medium");
  return atexit(_E1277_2);
}

//----- (006E5DF0) --------------------------------------------------------  // acclient.c:762404
int _E1279_2()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_6, "High");
  return atexit(_E1280_3);
}

//----- (006E5E10) --------------------------------------------------------  // acclient.c:762411
int _E1282_2()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_6, "FadeSpeed");
  return atexit(_E1283_2);
}

//----- (006E5E30) --------------------------------------------------------  // acclient.c:762418
int _E1285_2()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_6, "MaxOpacity");
  return atexit(_E1286_2);
}

//----- (006E5E50) --------------------------------------------------------  // acclient.c:762425
int _E1288_2()
{
  PStringBase<char>::PStringBase<char>(&Point_15, "Point");
  return atexit(_E1289_1);
}

//----- (006E5E70) --------------------------------------------------------  // acclient.c:762432
int _E1291_1()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_6, "AxisPos");
  return atexit(_E1292_2);
}

//----- (006E5E90) --------------------------------------------------------  // acclient.c:762439
int _E1294_2()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_6, "Texture");
  return atexit(_E1295_1);
}

//----- (006E5EB0) --------------------------------------------------------  // acclient.c:762446
int _E1297_1()
{
  PStringBase<char>::PStringBase<char>(&PointSize_6, "Size");
  return atexit(_E1298_1);
}

//----- (006E5ED0) --------------------------------------------------------  // acclient.c:762453
int _E1300_1()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_6, "UseOcclusion");
  return atexit(_E1301_1);
}

//----- (006E5EF0) --------------------------------------------------------  // acclient.c:762460
int _E1303_1()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_5, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83C2AC, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83C2B0, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_83C2B4, "PREPROC_OPTIONS");
  return atexit(_E1304_1);
}

//----- (006E5F40) --------------------------------------------------------  // acclient.c:762470
int _E1_46()
{
  return atexit(_E2_46);
}

//----- (00751FB0) --------------------------------------------------------  // acclient.c:872801
void __cdecl _E74_40()
{
  char *v0; // esi@1

  v0 = &waveform_None_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00751FE0) --------------------------------------------------------  // acclient.c:872814
void __cdecl _E77_54()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752010) --------------------------------------------------------  // acclient.c:872827
void __cdecl _E80_28()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752040) --------------------------------------------------------  // acclient.c:872840
void __cdecl _E83_17()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752070) --------------------------------------------------------  // acclient.c:872853
void __cdecl _E86_14()
{
  char *v0; // esi@1

  v0 = &waveform_Square_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007520A0) --------------------------------------------------------  // acclient.c:872866
void __cdecl _E89_25()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007520D0) --------------------------------------------------------  // acclient.c:872879
void __cdecl _E92_27()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752100) --------------------------------------------------------  // acclient.c:872892
void __cdecl sub_752100()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752130) --------------------------------------------------------  // acclient.c:872905
void __cdecl _E98_42()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752160) --------------------------------------------------------  // acclient.c:872918
void __cdecl _E119_65()
{
  char *v0; // esi@1

  v0 = &PHeader_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752190) --------------------------------------------------------  // acclient.c:872931
void __cdecl _E122_52()
{
  char *v0; // esi@1

  v0 = &VertexArray_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007521C0) --------------------------------------------------------  // acclient.c:872944
void __cdecl _E125_27()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007521F0) --------------------------------------------------------  // acclient.c:872957
void __cdecl _E128_28()
{
  char *v0; // esi@1

  v0 = &VertexType_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752220) --------------------------------------------------------  // acclient.c:872970
void __cdecl _E131_24()
{
  char *v0; // esi@1

  v0 = &VertexData_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752250) --------------------------------------------------------  // acclient.c:872983
void __cdecl _E134_23()
{
  char *v0; // esi@1

  v0 = &Vertex_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752280) --------------------------------------------------------  // acclient.c:872996
void __cdecl _E137_23()
{
  char *v0; // esi@1

  v0 = &Index_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007522B0) --------------------------------------------------------  // acclient.c:873009
void __cdecl _E140_18()
{
  char *v0; // esi@1

  v0 = &Origin_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007522E0) --------------------------------------------------------  // acclient.c:873022
void __cdecl _E143_19()
{
  char *v0; // esi@1

  v0 = &Normal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752310) --------------------------------------------------------  // acclient.c:873035
void __cdecl _E146_18()
{
  char *v0; // esi@1

  v0 = &Diffuse_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752340) --------------------------------------------------------  // acclient.c:873048
void __cdecl _E149_18()
{
  char *v0; // esi@1

  v0 = &Specular_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752370) --------------------------------------------------------  // acclient.c:873061
void __cdecl _E152_17()
{
  char *v0; // esi@1

  v0 = &UVS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007523A0) --------------------------------------------------------  // acclient.c:873074
void __cdecl _E155_15()
{
  char *v0; // esi@1

  v0 = &VectorS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007523D0) --------------------------------------------------------  // acclient.c:873087
void __cdecl _E158_18()
{
  char *v0; // esi@1

  v0 = &VectorT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752400) --------------------------------------------------------  // acclient.c:873100
void __cdecl _E161_15()
{
  char *v0; // esi@1

  v0 = &VectorSxT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752430) --------------------------------------------------------  // acclient.c:873113
void __cdecl _E164_18()
{
  char *v0; // esi@1

  v0 = &Weights_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752460) --------------------------------------------------------  // acclient.c:873126
void __cdecl _E167_14()
{
  char *v0; // esi@1

  v0 = &Importance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752490) --------------------------------------------------------  // acclient.c:873139
void __cdecl _E170_13()
{
  char *v0; // esi@1

  v0 = &PhysMtl_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007524C0) --------------------------------------------------------  // acclient.c:873152
void __cdecl _E173_12()
{
  char *v0; // esi@1

  v0 = &Material_30.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_30.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007524F0) --------------------------------------------------------  // acclient.c:873165
void __cdecl _E176_13()
{
  char *v0; // esi@1

  v0 = &ID_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752520) --------------------------------------------------------  // acclient.c:873178
void __cdecl _E179_12()
{
  char *v0; // esi@1

  v0 = &FileName_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752550) --------------------------------------------------------  // acclient.c:873191
void __cdecl _E182_12()
{
  char *v0; // esi@1

  v0 = &Polygon_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752580) --------------------------------------------------------  // acclient.c:873204
void __cdecl _E185_9()
{
  char *v0; // esi@1

  v0 = &ID_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007525B0) --------------------------------------------------------  // acclient.c:873217
void __cdecl _E188_10()
{
  char *v0; // esi@1

  v0 = &Indices_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007525E0) --------------------------------------------------------  // acclient.c:873230
void __cdecl _E191_9()
{
  char *v0; // esi@1

  v0 = &MaterialID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752610) --------------------------------------------------------  // acclient.c:873243
void __cdecl _E194_16()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752640) --------------------------------------------------------  // acclient.c:873256
void __cdecl _E197_7()
{
  char *v0; // esi@1

  v0 = &Markings_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752670) --------------------------------------------------------  // acclient.c:873269
void __cdecl _E200_12()
{
  char *v0; // esi@1

  v0 = &Material_31.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_31.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007526A0) --------------------------------------------------------  // acclient.c:873282
void __cdecl _E203_11()
{
  char *v0; // esi@1

  v0 = &Index_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007526D0) --------------------------------------------------------  // acclient.c:873295
void __cdecl _E206_14()
{
  char *v0; // esi@1

  v0 = &Filename_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752700) --------------------------------------------------------  // acclient.c:873308
void __cdecl _E209_9()
{
  char *v0; // esi@1

  v0 = &Surface_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752730) --------------------------------------------------------  // acclient.c:873321
void __cdecl _E212_12()
{
  char *v0; // esi@1

  v0 = &CellPoly_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752760) --------------------------------------------------------  // acclient.c:873334
void __cdecl _E215_8()
{
  char *v0; // esi@1

  v0 = &Sphere_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752790) --------------------------------------------------------  // acclient.c:873347
void __cdecl _E218_9()
{
  char *v0; // esi@1

  v0 = &Side_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007527C0) --------------------------------------------------------  // acclient.c:873360
void __cdecl _E221_9()
{
  char *v0; // esi@1

  v0 = &Positive_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007527F0) --------------------------------------------------------  // acclient.c:873373
void __cdecl _E224_9()
{
  char *v0; // esi@1

  v0 = &Negative_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752820) --------------------------------------------------------  // acclient.c:873386
void __cdecl _E227_9()
{
  char *v0; // esi@1

  v0 = &Polygon_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752850) --------------------------------------------------------  // acclient.c:873399
void __cdecl _E230_9()
{
  char *v0; // esi@1

  v0 = &OtherCell_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752880) --------------------------------------------------------  // acclient.c:873412
void __cdecl _E233_8()
{
  char *v0; // esi@1

  v0 = &CellPortal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007528B0) --------------------------------------------------------  // acclient.c:873425
void __cdecl _E236_8()
{
  char *v0; // esi@1

  v0 = &Portal_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007528E0) --------------------------------------------------------  // acclient.c:873438
void __cdecl _E239_9()
{
  char *v0; // esi@1

  v0 = &OtherCell_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752910) --------------------------------------------------------  // acclient.c:873451
void __cdecl _E242_9()
{
  char *v0; // esi@1

  v0 = &OtherPortal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752940) --------------------------------------------------------  // acclient.c:873464
void __cdecl _E245_8()
{
  char *v0; // esi@1

  v0 = &ExactMatch_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752970) --------------------------------------------------------  // acclient.c:873477
void __cdecl _E248_8()
{
  char *v0; // esi@1

  v0 = &StabList_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007529A0) --------------------------------------------------------  // acclient.c:873490
void __cdecl _E251_8()
{
  char *v0; // esi@1

  v0 = &Period_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007529D0) --------------------------------------------------------  // acclient.c:873503
void __cdecl _E254_9()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752A00) --------------------------------------------------------  // acclient.c:873516
void __cdecl _E257_7()
{
  char *v0; // esi@1

  v0 = &Transform_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752A30) --------------------------------------------------------  // acclient.c:873529
void __cdecl _E260_8()
{
  char *v0; // esi@1

  v0 = &Scale_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752A60) --------------------------------------------------------  // acclient.c:873542
void __cdecl _E263_6()
{
  char *v0; // esi@1

  v0 = &Weight_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752A90) --------------------------------------------------------  // acclient.c:873555
void __cdecl _E266_6()
{
  char *v0; // esi@1

  v0 = &Offset_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752AC0) --------------------------------------------------------  // acclient.c:873568
void __cdecl _E269_6()
{
  char *v0; // esi@1

  v0 = &Quaternion_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752AF0) --------------------------------------------------------  // acclient.c:873581
void __cdecl _E272_5()
{
  char *v0; // esi@1

  v0 = &Rotation_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752B20) --------------------------------------------------------  // acclient.c:873594
void __cdecl _E275_5()
{
  char *v0; // esi@1

  v0 = &STime_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752B50) --------------------------------------------------------  // acclient.c:873607
void __cdecl _E278_5()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752B80) --------------------------------------------------------  // acclient.c:873620
void __cdecl _E281_6()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752BB0) --------------------------------------------------------  // acclient.c:873633
void __cdecl _E284_5()
{
  char *v0; // esi@1

  v0 = &LowPt_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752BE0) --------------------------------------------------------  // acclient.c:873646
void __cdecl _E287_6()
{
  char *v0; // esi@1

  v0 = &Radius_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752C10) --------------------------------------------------------  // acclient.c:873659
void __cdecl _E290_6()
{
  char *v0; // esi@1

  v0 = &Height_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752C40) --------------------------------------------------------  // acclient.c:873672
void __cdecl _E293_5()
{
  char *v0; // esi@1

  v0 = &Texture2D_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752C70) --------------------------------------------------------  // acclient.c:873685
void __cdecl _E296_6()
{
  char *v0; // esi@1

  v0 = &Texture3D_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752CA0) --------------------------------------------------------  // acclient.c:873698
void __cdecl _E299_4()
{
  char *v0; // esi@1

  v0 = &TextureCube_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752CD0) --------------------------------------------------------  // acclient.c:873711
void __cdecl _E302_5()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752D00) --------------------------------------------------------  // acclient.c:873724
void __cdecl _E305_4()
{
  char *v0; // esi@1

  v0 = &MovieFileName_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752D30) --------------------------------------------------------  // acclient.c:873737
void __cdecl _E308_5()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752D60) --------------------------------------------------------  // acclient.c:873750
void __cdecl _E311_4()
{
  char *v0; // esi@1

  v0 = &Levels_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752D90) --------------------------------------------------------  // acclient.c:873763
void __cdecl _E314_5()
{
  char *v0; // esi@1

  v0 = &NodeName_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752DC0) --------------------------------------------------------  // acclient.c:873776
void __cdecl _E317_4()
{
  char *v0; // esi@1

  v0 = &Material_32.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_32.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752DF0) --------------------------------------------------------  // acclient.c:873789
void __cdecl _E320_5()
{
  char *v0; // esi@1

  v0 = &MaterialType_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752E20) --------------------------------------------------------  // acclient.c:873802
void __cdecl _E323_4()
{
  char *v0; // esi@1

  v0 = &Modifier_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752E50) --------------------------------------------------------  // acclient.c:873815
void __cdecl _E326_5()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752E80) --------------------------------------------------------  // acclient.c:873828
void __cdecl _E329_4()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752EB0) --------------------------------------------------------  // acclient.c:873841
void __cdecl _E332_5()
{
  char *v0; // esi@1

  v0 = &NodeName_70.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_70.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752EE0) --------------------------------------------------------  // acclient.c:873854
void __cdecl _E335_4()
{
  char *v0; // esi@1

  v0 = &SortMode_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752F10) --------------------------------------------------------  // acclient.c:873867
void __cdecl _E338_4()
{
  char *v0; // esi@1

  v0 = &SortMode_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752F40) --------------------------------------------------------  // acclient.c:873880
void __cdecl _E341_4()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752F70) --------------------------------------------------------  // acclient.c:873893
void __cdecl _E344_2()
{
  char *v0; // esi@1

  v0 = &NodeName_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752FA0) --------------------------------------------------------  // acclient.c:873906
void __cdecl _E347_2()
{
  char *v0; // esi@1

  v0 = &NodeName_72.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_72.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00752FD0) --------------------------------------------------------  // acclient.c:873919
void __cdecl _E350_2()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753000) --------------------------------------------------------  // acclient.c:873932
void __cdecl _E353_2()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753030) --------------------------------------------------------  // acclient.c:873945
void __cdecl _E356_2()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753060) --------------------------------------------------------  // acclient.c:873958
void __cdecl _E359_2()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753090) --------------------------------------------------------  // acclient.c:873971
void __cdecl _E362_2()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007530C0) --------------------------------------------------------  // acclient.c:873984
void __cdecl _E365_2()
{
  char *v0; // esi@1

  v0 = &NodeName_73.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_73.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007530F0) --------------------------------------------------------  // acclient.c:873997
void __cdecl _E368_2()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753120) --------------------------------------------------------  // acclient.c:874010
void __cdecl _E371_2()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753150) --------------------------------------------------------  // acclient.c:874023
void __cdecl _E374_2()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753180) --------------------------------------------------------  // acclient.c:874036
void __cdecl _E377_2()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007531B0) --------------------------------------------------------  // acclient.c:874049
void __cdecl _E380_2()
{
  char *v0; // esi@1

  v0 = &TrueFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007531E0) --------------------------------------------------------  // acclient.c:874062
void __cdecl _E383_2()
{
  char *v0; // esi@1

  v0 = &FalseFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753210) --------------------------------------------------------  // acclient.c:874075
void __cdecl _E386_2()
{
  char *v0; // esi@1

  v0 = &RenderPass_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753240) --------------------------------------------------------  // acclient.c:874088
void __cdecl _E389_2()
{
  char *v0; // esi@1

  v0 = &Blend_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753270) --------------------------------------------------------  // acclient.c:874101
void __cdecl _E392_2()
{
  char *v0; // esi@1

  v0 = &DepthTest_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007532A0) --------------------------------------------------------  // acclient.c:874114
void __cdecl _E395_2()
{
  char *v0; // esi@1

  v0 = &DepthWrite_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007532D0) --------------------------------------------------------  // acclient.c:874127
void __cdecl _E398_2()
{
  char *v0; // esi@1

  v0 = &CullMode_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753300) --------------------------------------------------------  // acclient.c:874140
void __cdecl _E401_2()
{
  char *v0; // esi@1

  v0 = &DepthFog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753330) --------------------------------------------------------  // acclient.c:874153
void __cdecl _E404_2()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753360) --------------------------------------------------------  // acclient.c:874166
void __cdecl _E407_2()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753390) --------------------------------------------------------  // acclient.c:874179
void __cdecl _E410_2()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007533C0) --------------------------------------------------------  // acclient.c:874192
void __cdecl _E413_2()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007533F0) --------------------------------------------------------  // acclient.c:874205
void __cdecl _E416_2()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753420) --------------------------------------------------------  // acclient.c:874218
void __cdecl _E419_2()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753450) --------------------------------------------------------  // acclient.c:874231
void __cdecl _E422_2()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753480) --------------------------------------------------------  // acclient.c:874244
void __cdecl _E425_2()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007534B0) --------------------------------------------------------  // acclient.c:874257
void __cdecl _E428_2()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007534E0) --------------------------------------------------------  // acclient.c:874270
void __cdecl _E431_2()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753510) --------------------------------------------------------  // acclient.c:874283
void __cdecl _E434_2()
{
  char *v0; // esi@1

  v0 = &Ambient_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753540) --------------------------------------------------------  // acclient.c:874296
void __cdecl _E437_2()
{
  char *v0; // esi@1

  v0 = &Diffuse_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753570) --------------------------------------------------------  // acclient.c:874309
void __cdecl _E440_2()
{
  char *v0; // esi@1

  v0 = &Specular_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007535A0) --------------------------------------------------------  // acclient.c:874322
void __cdecl _E443_2()
{
  char *v0; // esi@1

  v0 = &SpecularPower_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007535D0) --------------------------------------------------------  // acclient.c:874335
void __cdecl _E446_2()
{
  char *v0; // esi@1

  v0 = &Dye_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753600) --------------------------------------------------------  // acclient.c:874348
void __cdecl _E449_2()
{
  char *v0; // esi@1

  v0 = &Emissive_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753630) --------------------------------------------------------  // acclient.c:874361
void __cdecl _E452_2()
{
  char *v0; // esi@1

  v0 = &VertexFormat_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753660) --------------------------------------------------------  // acclient.c:874374
void __cdecl _E455_2()
{
  char *v0; // esi@1

  v0 = &VertexShader_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753690) --------------------------------------------------------  // acclient.c:874387
void __cdecl _E458_2()
{
  char *v0; // esi@1

  v0 = &PixelShader_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007536C0) --------------------------------------------------------  // acclient.c:874400
void __cdecl _E461_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007536F0) --------------------------------------------------------  // acclient.c:874413
void __cdecl _E464_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753720) --------------------------------------------------------  // acclient.c:874426
void __cdecl _E467_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753750) --------------------------------------------------------  // acclient.c:874439
void __cdecl _E470_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753780) --------------------------------------------------------  // acclient.c:874452
void __cdecl _E473_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007537B0) --------------------------------------------------------  // acclient.c:874465
void __cdecl _E476_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007537E0) --------------------------------------------------------  // acclient.c:874478
void __cdecl _E479_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753810) --------------------------------------------------------  // acclient.c:874491
void __cdecl _E482_2()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753840) --------------------------------------------------------  // acclient.c:874504
void __cdecl _E485_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753870) --------------------------------------------------------  // acclient.c:874517
void __cdecl _E488_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007538A0) --------------------------------------------------------  // acclient.c:874530
void __cdecl _E491_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007538D0) --------------------------------------------------------  // acclient.c:874543
void __cdecl _E494_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753900) --------------------------------------------------------  // acclient.c:874556
void __cdecl _E497_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753930) --------------------------------------------------------  // acclient.c:874569
void __cdecl _E500_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753960) --------------------------------------------------------  // acclient.c:874582
void __cdecl _E503_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753990) --------------------------------------------------------  // acclient.c:874595
void __cdecl _E506_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007539C0) --------------------------------------------------------  // acclient.c:874608
void __cdecl _E509_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007539F0) --------------------------------------------------------  // acclient.c:874621
void __cdecl _E512_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753A20) --------------------------------------------------------  // acclient.c:874634
void __cdecl _E515_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753A50) --------------------------------------------------------  // acclient.c:874647
void __cdecl _E518_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753A80) --------------------------------------------------------  // acclient.c:874660
void __cdecl _E521_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753AB0) --------------------------------------------------------  // acclient.c:874673
void __cdecl _E524_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753AE0) --------------------------------------------------------  // acclient.c:874686
void __cdecl _E527_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753B10) --------------------------------------------------------  // acclient.c:874699
void __cdecl _E530_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753B40) --------------------------------------------------------  // acclient.c:874712
void __cdecl _E533_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753B70) --------------------------------------------------------  // acclient.c:874725
void __cdecl _E536_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753BA0) --------------------------------------------------------  // acclient.c:874738
void __cdecl _E539_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753BD0) --------------------------------------------------------  // acclient.c:874751
void __cdecl _E542_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753C00) --------------------------------------------------------  // acclient.c:874764
void __cdecl _E545_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753C30) --------------------------------------------------------  // acclient.c:874777
void __cdecl _E548_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753C60) --------------------------------------------------------  // acclient.c:874790
void __cdecl _E551_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753C90) --------------------------------------------------------  // acclient.c:874803
void __cdecl _E554_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753CC0) --------------------------------------------------------  // acclient.c:874816
void __cdecl _E557_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753CF0) --------------------------------------------------------  // acclient.c:874829
void __cdecl _E560_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753D20) --------------------------------------------------------  // acclient.c:874842
void __cdecl _E563_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753D50) --------------------------------------------------------  // acclient.c:874855
void __cdecl _E566_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753D80) --------------------------------------------------------  // acclient.c:874868
void __cdecl _E569_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753DB0) --------------------------------------------------------  // acclient.c:874881
void __cdecl _E572_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753DE0) --------------------------------------------------------  // acclient.c:874894
void __cdecl _E575_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753E10) --------------------------------------------------------  // acclient.c:874907
void __cdecl _E578_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753E40) --------------------------------------------------------  // acclient.c:874920
void __cdecl _E581_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753E70) --------------------------------------------------------  // acclient.c:874933
void __cdecl _E584_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753EA0) --------------------------------------------------------  // acclient.c:874946
void __cdecl _E587_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753ED0) --------------------------------------------------------  // acclient.c:874959
void __cdecl _E590_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753F00) --------------------------------------------------------  // acclient.c:874972
void __cdecl _E593_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753F30) --------------------------------------------------------  // acclient.c:874985
void __cdecl _E596_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753F60) --------------------------------------------------------  // acclient.c:874998
void __cdecl _E599_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753F90) --------------------------------------------------------  // acclient.c:875011
void __cdecl _E602_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753FC0) --------------------------------------------------------  // acclient.c:875024
void __cdecl _E605_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00753FF0) --------------------------------------------------------  // acclient.c:875037
void __cdecl _E608_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754020) --------------------------------------------------------  // acclient.c:875050
void __cdecl _E611_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754050) --------------------------------------------------------  // acclient.c:875063
void __cdecl _E614_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754080) --------------------------------------------------------  // acclient.c:875076
void __cdecl _E617_2()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007540B0) --------------------------------------------------------  // acclient.c:875089
void __cdecl _E620_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007540E0) --------------------------------------------------------  // acclient.c:875102
void __cdecl _E623_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754110) --------------------------------------------------------  // acclient.c:875115
void __cdecl _E626_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754140) --------------------------------------------------------  // acclient.c:875128
void __cdecl _E629_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754170) --------------------------------------------------------  // acclient.c:875141
void __cdecl _E632_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007541A0) --------------------------------------------------------  // acclient.c:875154
void __cdecl _E635_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007541D0) --------------------------------------------------------  // acclient.c:875167
void __cdecl _E638_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754200) --------------------------------------------------------  // acclient.c:875180
void __cdecl _E641_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754230) --------------------------------------------------------  // acclient.c:875193
void __cdecl _E644_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754260) --------------------------------------------------------  // acclient.c:875206
void __cdecl _E647_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754290) --------------------------------------------------------  // acclient.c:875219
void __cdecl _E650_2()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007542C0) --------------------------------------------------------  // acclient.c:875232
void __cdecl _E653_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007542F0) --------------------------------------------------------  // acclient.c:875245
void __cdecl _E656_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754320) --------------------------------------------------------  // acclient.c:875258
void __cdecl _E659_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754350) --------------------------------------------------------  // acclient.c:875271
void __cdecl _E662_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754380) --------------------------------------------------------  // acclient.c:875284
void __cdecl _E665_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007543B0) --------------------------------------------------------  // acclient.c:875297
void __cdecl _E668_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007543E0) --------------------------------------------------------  // acclient.c:875310
void __cdecl _E671_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754410) --------------------------------------------------------  // acclient.c:875323
void __cdecl _E674_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754440) --------------------------------------------------------  // acclient.c:875336
void __cdecl _E677_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754470) --------------------------------------------------------  // acclient.c:875349
void __cdecl _E680_2()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007544A0) --------------------------------------------------------  // acclient.c:875362
void __cdecl _E683_2()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007544D0) --------------------------------------------------------  // acclient.c:875375
void __cdecl _E686_2()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754500) --------------------------------------------------------  // acclient.c:875388
void __cdecl _E689_2()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754530) --------------------------------------------------------  // acclient.c:875401
void __cdecl _E692_2()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754560) --------------------------------------------------------  // acclient.c:875414
void __cdecl _E695_2()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754590) --------------------------------------------------------  // acclient.c:875427
void __cdecl _E698_2()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007545C0) --------------------------------------------------------  // acclient.c:875440
void __cdecl _E701_2()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007545F0) --------------------------------------------------------  // acclient.c:875453
void __cdecl _E704_2()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754620) --------------------------------------------------------  // acclient.c:875466
void __cdecl _E707_2()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754650) --------------------------------------------------------  // acclient.c:875479
void __cdecl _E710_2()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754680) --------------------------------------------------------  // acclient.c:875492
void __cdecl _E713_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007546B0) --------------------------------------------------------  // acclient.c:875505
void __cdecl _E716_2()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007546E0) --------------------------------------------------------  // acclient.c:875518
void __cdecl _E719_2()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754710) --------------------------------------------------------  // acclient.c:875531
void __cdecl _E722_2()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754740) --------------------------------------------------------  // acclient.c:875544
void __cdecl _E725_2()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754770) --------------------------------------------------------  // acclient.c:875557
void __cdecl _E728_2()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007547A0) --------------------------------------------------------  // acclient.c:875570
void __cdecl _E731_2()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007547D0) --------------------------------------------------------  // acclient.c:875583
void __cdecl _E734_2()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754800) --------------------------------------------------------  // acclient.c:875596
void __cdecl _E737_2()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754830) --------------------------------------------------------  // acclient.c:875609
void __cdecl _E740_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754860) --------------------------------------------------------  // acclient.c:875622
void __cdecl _E743_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754890) --------------------------------------------------------  // acclient.c:875635
void __cdecl _E746_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007548C0) --------------------------------------------------------  // acclient.c:875648
void __cdecl _E749_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007548F0) --------------------------------------------------------  // acclient.c:875661
void __cdecl _E752_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754920) --------------------------------------------------------  // acclient.c:875674
void __cdecl _E755_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754950) --------------------------------------------------------  // acclient.c:875687
void __cdecl _E758_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754980) --------------------------------------------------------  // acclient.c:875700
void __cdecl _E761_2()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007549B0) --------------------------------------------------------  // acclient.c:875713
void __cdecl _E764_2()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007549E0) --------------------------------------------------------  // acclient.c:875726
void __cdecl _E767_2()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754A10) --------------------------------------------------------  // acclient.c:875739
void __cdecl _E770_2()
{
  char *v0; // esi@1

  v0 = &NodeName_74.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_74.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754A40) --------------------------------------------------------  // acclient.c:875752
void __cdecl _E773_2()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754A70) --------------------------------------------------------  // acclient.c:875765
void __cdecl _E776_2()
{
  char *v0; // esi@1

  v0 = &SamplerName_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754AA0) --------------------------------------------------------  // acclient.c:875778
void __cdecl _E779_2()
{
  char *v0; // esi@1

  v0 = &Texture_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754AD0) --------------------------------------------------------  // acclient.c:875791
void __cdecl _E782_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754B00) --------------------------------------------------------  // acclient.c:875804
void __cdecl _E785_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754B30) --------------------------------------------------------  // acclient.c:875817
void __cdecl _E788_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754B60) --------------------------------------------------------  // acclient.c:875830
void __cdecl _E791_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754B90) --------------------------------------------------------  // acclient.c:875843
void __cdecl _E794_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754BC0) --------------------------------------------------------  // acclient.c:875856
void __cdecl _E797_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754BF0) --------------------------------------------------------  // acclient.c:875869
void __cdecl _E800_2()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754C20) --------------------------------------------------------  // acclient.c:875882
void __cdecl _E803_2()
{
  char *v0; // esi@1

  v0 = &AddressMode_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754C50) --------------------------------------------------------  // acclient.c:875895
void __cdecl _E806_2()
{
  char *v0; // esi@1

  v0 = &TexFilter_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754C80) --------------------------------------------------------  // acclient.c:875908
void __cdecl _E809_2()
{
  char *v0; // esi@1

  v0 = &ColorOp_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754CB0) --------------------------------------------------------  // acclient.c:875921
void __cdecl _E812_2()
{
  char *v0; // esi@1

  v0 = &ColorArg1_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754CE0) --------------------------------------------------------  // acclient.c:875934
void __cdecl _E815_2()
{
  char *v0; // esi@1

  v0 = &ColorArg2_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754D10) --------------------------------------------------------  // acclient.c:875947
void __cdecl _E818_2()
{
  char *v0; // esi@1

  v0 = &AlphaOp_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754D40) --------------------------------------------------------  // acclient.c:875960
void __cdecl _E821_2()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754D70) --------------------------------------------------------  // acclient.c:875973
void __cdecl _E824_2()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754DA0) --------------------------------------------------------  // acclient.c:875986
void __cdecl _E827_2()
{
  char *v0; // esi@1

  v0 = &TexCoord_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754DD0) --------------------------------------------------------  // acclient.c:875999
void __cdecl _E830_2()
{
  char *v0; // esi@1

  v0 = &UseProjection_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754E00) --------------------------------------------------------  // acclient.c:876012
void __cdecl _E833_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754E30) --------------------------------------------------------  // acclient.c:876025
void __cdecl _E836_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754E60) --------------------------------------------------------  // acclient.c:876038
void __cdecl _E839_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754E90) --------------------------------------------------------  // acclient.c:876051
void __cdecl _E842_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754EC0) --------------------------------------------------------  // acclient.c:876064
void __cdecl _E845_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754EF0) --------------------------------------------------------  // acclient.c:876077
void __cdecl _E848_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754F20) --------------------------------------------------------  // acclient.c:876090
void __cdecl _E851_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754F50) --------------------------------------------------------  // acclient.c:876103
void __cdecl _E854_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754F80) --------------------------------------------------------  // acclient.c:876116
void __cdecl _E857_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754FB0) --------------------------------------------------------  // acclient.c:876129
void __cdecl _E860_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00754FE0) --------------------------------------------------------  // acclient.c:876142
void __cdecl _E863_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755010) --------------------------------------------------------  // acclient.c:876155
void __cdecl _E866_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755040) --------------------------------------------------------  // acclient.c:876168
void __cdecl _E869_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755070) --------------------------------------------------------  // acclient.c:876181
void __cdecl _E872_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007550A0) --------------------------------------------------------  // acclient.c:876194
void __cdecl _E875_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007550D0) --------------------------------------------------------  // acclient.c:876207
void __cdecl _E878_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755100) --------------------------------------------------------  // acclient.c:876220
void __cdecl _E881_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755130) --------------------------------------------------------  // acclient.c:876233
void __cdecl _E884_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755160) --------------------------------------------------------  // acclient.c:876246
void __cdecl _E887_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755190) --------------------------------------------------------  // acclient.c:876259
void __cdecl _E890_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007551C0) --------------------------------------------------------  // acclient.c:876272
void __cdecl _E893_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007551F0) --------------------------------------------------------  // acclient.c:876285
void __cdecl _E896_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755220) --------------------------------------------------------  // acclient.c:876298
void __cdecl _E899_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755250) --------------------------------------------------------  // acclient.c:876311
void __cdecl _E902_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755280) --------------------------------------------------------  // acclient.c:876324
void __cdecl _E905_2()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007552B0) --------------------------------------------------------  // acclient.c:876337
void __cdecl _E908_2()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007552E0) --------------------------------------------------------  // acclient.c:876350
void __cdecl _E911_2()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755310) --------------------------------------------------------  // acclient.c:876363
void __cdecl _E914_2()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755340) --------------------------------------------------------  // acclient.c:876376
void __cdecl _E917_2()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755370) --------------------------------------------------------  // acclient.c:876389
void __cdecl _E920_2()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007553A0) --------------------------------------------------------  // acclient.c:876402
void __cdecl _E923_2()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007553D0) --------------------------------------------------------  // acclient.c:876415
void __cdecl _E926_2()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755400) --------------------------------------------------------  // acclient.c:876428
void __cdecl _E929_2()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755430) --------------------------------------------------------  // acclient.c:876441
void __cdecl _E932_2()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755460) --------------------------------------------------------  // acclient.c:876454
void __cdecl _E935_2()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755490) --------------------------------------------------------  // acclient.c:876467
void __cdecl _E938_2()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007554C0) --------------------------------------------------------  // acclient.c:876480
void __cdecl _E941_2()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007554F0) --------------------------------------------------------  // acclient.c:876493
void __cdecl _E944_2()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755520) --------------------------------------------------------  // acclient.c:876506
void __cdecl _E947_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755550) --------------------------------------------------------  // acclient.c:876519
void __cdecl _E950_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755580) --------------------------------------------------------  // acclient.c:876532
void __cdecl _E953_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007555B0) --------------------------------------------------------  // acclient.c:876545
void __cdecl _E956_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007555E0) --------------------------------------------------------  // acclient.c:876558
void __cdecl _E959_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755610) --------------------------------------------------------  // acclient.c:876571
void __cdecl _E962_2()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755640) --------------------------------------------------------  // acclient.c:876584
void __cdecl _E965_2()
{
  char *v0; // esi@1

  v0 = &NodeName_75.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_75.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755670) --------------------------------------------------------  // acclient.c:876597
void __cdecl _E968_2()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007556A0) --------------------------------------------------------  // acclient.c:876610
void __cdecl _E971_2()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007556D0) --------------------------------------------------------  // acclient.c:876623
void __cdecl _E974_2()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755700) --------------------------------------------------------  // acclient.c:876636
void __cdecl _E977_2()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755730) --------------------------------------------------------  // acclient.c:876649
void __cdecl _E980_2()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755760) --------------------------------------------------------  // acclient.c:876662
void __cdecl _E983_2()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755790) --------------------------------------------------------  // acclient.c:876675
void __cdecl _E986_2()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007557C0) --------------------------------------------------------  // acclient.c:876688
void __cdecl _E989_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007557F0) --------------------------------------------------------  // acclient.c:876701
void __cdecl _E992_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755820) --------------------------------------------------------  // acclient.c:876714
void __cdecl _E995_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755850) --------------------------------------------------------  // acclient.c:876727
void __cdecl _E998_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755880) --------------------------------------------------------  // acclient.c:876740
void __cdecl _E1001_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007558B0) --------------------------------------------------------  // acclient.c:876753
void __cdecl _E1004_2()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007558E0) --------------------------------------------------------  // acclient.c:876766
void __cdecl _E1007_2()
{
  char *v0; // esi@1

  v0 = &NodeName_76.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_76.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755910) --------------------------------------------------------  // acclient.c:876779
void __cdecl _E1010_2()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755940) --------------------------------------------------------  // acclient.c:876792
void __cdecl _E1013_2()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755970) --------------------------------------------------------  // acclient.c:876805
void __cdecl _E1016_2()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007559A0) --------------------------------------------------------  // acclient.c:876818
void __cdecl _E1019_2()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007559D0) --------------------------------------------------------  // acclient.c:876831
void __cdecl _E1022_2()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755A00) --------------------------------------------------------  // acclient.c:876844
void __cdecl _E1025_2()
{
  char *v0; // esi@1

  v0 = &ScaleType_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755A30) --------------------------------------------------------  // acclient.c:876857
void __cdecl _E1028_2()
{
  char *v0; // esi@1

  v0 = &WorldSpace_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755A60) --------------------------------------------------------  // acclient.c:876870
void __cdecl _E1031_2()
{
  char *v0; // esi@1

  v0 = &ForceDraw_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755A90) --------------------------------------------------------  // acclient.c:876883
void __cdecl _E1034_2()
{
  char *v0; // esi@1

  v0 = &NumEmitters_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755AC0) --------------------------------------------------------  // acclient.c:876896
void __cdecl _E1037_2()
{
  char *v0; // esi@1

  v0 = &Material_33.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_33.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755AF0) --------------------------------------------------------  // acclient.c:876909
void __cdecl _E1040_2()
{
  char *v0; // esi@1

  v0 = &Version_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755B20) --------------------------------------------------------  // acclient.c:876922
void __cdecl _E1043_2()
{
  char *v0; // esi@1

  v0 = &MaxParticles_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755B50) --------------------------------------------------------  // acclient.c:876935
void __cdecl _E1046_2()
{
  char *v0; // esi@1

  v0 = &NodeName_77.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_77.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755B80) --------------------------------------------------------  // acclient.c:876948
void __cdecl _E1049_2()
{
  char *v0; // esi@1

  v0 = &Origin_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755BB0) --------------------------------------------------------  // acclient.c:876961
void __cdecl _E1052_2()
{
  char *v0; // esi@1

  v0 = &Shape_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755BE0) --------------------------------------------------------  // acclient.c:876974
void __cdecl _E1055_2()
{
  char *v0; // esi@1

  v0 = &Shape_Point_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755C10) --------------------------------------------------------  // acclient.c:876987
void __cdecl _E1058_2()
{
  char *v0; // esi@1

  v0 = &Shape_Line_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755C40) --------------------------------------------------------  // acclient.c:877000
void __cdecl _E1061_2()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755C70) --------------------------------------------------------  // acclient.c:877013
void __cdecl _E1064_2()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755CA0) --------------------------------------------------------  // acclient.c:877026
void __cdecl _E1067_2()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755CD0) --------------------------------------------------------  // acclient.c:877039
void __cdecl _E1070_2()
{
  char *v0; // esi@1

  v0 = &ParticleShape_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755D00) --------------------------------------------------------  // acclient.c:877052
void __cdecl _E1073_2()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755D30) --------------------------------------------------------  // acclient.c:877065
void __cdecl _E1076_2()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755D60) --------------------------------------------------------  // acclient.c:877078
void __cdecl _E1079_2()
{
  char *v0; // esi@1

  v0 = &Streak_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755D90) --------------------------------------------------------  // acclient.c:877091
void __cdecl _E1082_2()
{
  char *v0; // esi@1

  v0 = &Rotation_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755DC0) --------------------------------------------------------  // acclient.c:877104
void __cdecl _E1085_2()
{
  char *v0; // esi@1

  v0 = &WorldRotation_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755DF0) --------------------------------------------------------  // acclient.c:877117
void __cdecl _E1088_2()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755E20) --------------------------------------------------------  // acclient.c:877130
void __cdecl _E1091_2()
{
  char *v0; // esi@1

  v0 = &ParticleScale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755E50) --------------------------------------------------------  // acclient.c:877143
void __cdecl _E1094_2()
{
  char *v0; // esi@1

  v0 = &Scale_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755E80) --------------------------------------------------------  // acclient.c:877156
void __cdecl _E1097_2()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755EB0) --------------------------------------------------------  // acclient.c:877169
void __cdecl _E1100_2()
{
  char *v0; // esi@1

  v0 = &BirthRate_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755EE0) --------------------------------------------------------  // acclient.c:877182
void __cdecl _E1103_2()
{
  char *v0; // esi@1

  v0 = &Lifespan_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755F10) --------------------------------------------------------  // acclient.c:877195
void __cdecl _E1106_2()
{
  char *v0; // esi@1

  v0 = &Velocity_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755F40) --------------------------------------------------------  // acclient.c:877208
void __cdecl _E1109_2()
{
  char *v0; // esi@1

  v0 = &Direction_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755F70) --------------------------------------------------------  // acclient.c:877221
void __cdecl _E1112_2()
{
  char *v0; // esi@1

  v0 = &MinSpread_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755FA0) --------------------------------------------------------  // acclient.c:877234
void __cdecl _E1115_2()
{
  char *v0; // esi@1

  v0 = &MaxSpread_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00755FD0) --------------------------------------------------------  // acclient.c:877247
void __cdecl _E1118_2()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756000) --------------------------------------------------------  // acclient.c:877260
void __cdecl _E1121_2()
{
  char *v0; // esi@1

  v0 = &BlastCount_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756030) --------------------------------------------------------  // acclient.c:877273
void __cdecl _E1124_2()
{
  char *v0; // esi@1

  v0 = &StartTime_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756060) --------------------------------------------------------  // acclient.c:877286
void __cdecl _E1127_2()
{
  char *v0; // esi@1

  v0 = &TimeLimit_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756090) --------------------------------------------------------  // acclient.c:877299
void __cdecl _E1130_2()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007560C0) --------------------------------------------------------  // acclient.c:877312
void __cdecl _E1133_2()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007560F0) --------------------------------------------------------  // acclient.c:877325
void __cdecl _E1136_2()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756120) --------------------------------------------------------  // acclient.c:877338
void __cdecl _E1139_2()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756150) --------------------------------------------------------  // acclient.c:877351
void __cdecl _E1142_2()
{
  char *v0; // esi@1

  v0 = &IsActive_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756180) --------------------------------------------------------  // acclient.c:877364
void __cdecl _E1145_2()
{
  char *v0; // esi@1

  v0 = &FadeIn_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007561B0) --------------------------------------------------------  // acclient.c:877377
void __cdecl _E1148_2()
{
  char *v0; // esi@1

  v0 = &FadeOut_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007561E0) --------------------------------------------------------  // acclient.c:877390
void __cdecl _E1151_2()
{
  char *v0; // esi@1

  v0 = &ConstrainX_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756210) --------------------------------------------------------  // acclient.c:877403
void __cdecl _E1154_2()
{
  char *v0; // esi@1

  v0 = &ConstrainY_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756240) --------------------------------------------------------  // acclient.c:877416
void __cdecl _E1157_2()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756270) --------------------------------------------------------  // acclient.c:877429
void __cdecl _E1160_2()
{
  char *v0; // esi@1

  v0 = &NodeName_78.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_78.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007562A0) --------------------------------------------------------  // acclient.c:877442
void __cdecl _E1163_2()
{
  char *v0; // esi@1

  v0 = &Time_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007562D0) --------------------------------------------------------  // acclient.c:877455
void __cdecl _E1166_2()
{
  char *v0; // esi@1

  v0 = &Flags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756300) --------------------------------------------------------  // acclient.c:877468
void __cdecl _E1169_2()
{
  char *v0; // esi@1

  v0 = &Flags_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756330) --------------------------------------------------------  // acclient.c:877481
void __cdecl _E1172_2()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756360) --------------------------------------------------------  // acclient.c:877494
void __cdecl _E1175_2()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756390) --------------------------------------------------------  // acclient.c:877507
void __cdecl _E1178_2()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007563C0) --------------------------------------------------------  // acclient.c:877520
void __cdecl _E1181_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007563F0) --------------------------------------------------------  // acclient.c:877533
void __cdecl _E1184_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756420) --------------------------------------------------------  // acclient.c:877546
void __cdecl _E1187_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756450) --------------------------------------------------------  // acclient.c:877559
void __cdecl _E1190_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756480) --------------------------------------------------------  // acclient.c:877572
void __cdecl _E1193_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007564B0) --------------------------------------------------------  // acclient.c:877585
void __cdecl _E1196_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007564E0) --------------------------------------------------------  // acclient.c:877598
void __cdecl _E1199_2()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756510) --------------------------------------------------------  // acclient.c:877611
void __cdecl _E1202_2()
{
  char *v0; // esi@1

  v0 = &Scale_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756540) --------------------------------------------------------  // acclient.c:877624
void __cdecl _E1205_2()
{
  char *v0; // esi@1

  v0 = &ScaleX_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756570) --------------------------------------------------------  // acclient.c:877637
void __cdecl _E1208_2()
{
  char *v0; // esi@1

  v0 = &ScaleY_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007565A0) --------------------------------------------------------  // acclient.c:877650
void __cdecl _E1211_2()
{
  char *v0; // esi@1

  v0 = &Color_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007565D0) --------------------------------------------------------  // acclient.c:877663
void __cdecl _E1214_2()
{
  char *v0; // esi@1

  v0 = &Mass_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756600) --------------------------------------------------------  // acclient.c:877676
void __cdecl _E1217_2()
{
  char *v0; // esi@1

  v0 = &PFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756630) --------------------------------------------------------  // acclient.c:877689
void __cdecl _E1220_2()
{
  char *v0; // esi@1

  v0 = &PFlags_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756660) --------------------------------------------------------  // acclient.c:877702
void __cdecl _E1223_2()
{
  char *v0; // esi@1

  v0 = &PCType_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756690) --------------------------------------------------------  // acclient.c:877715
void __cdecl _E1226_2()
{
  char *v0; // esi@1

  v0 = &PCType_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007566C0) --------------------------------------------------------  // acclient.c:877728
void __cdecl _E1229_2()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007566F0) --------------------------------------------------------  // acclient.c:877741
void __cdecl _E1232_2()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756720) --------------------------------------------------------  // acclient.c:877754
void __cdecl _E1235_2()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756750) --------------------------------------------------------  // acclient.c:877767
void __cdecl _E1238_2()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756780) --------------------------------------------------------  // acclient.c:877780
void __cdecl _E1241_2()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007567B0) --------------------------------------------------------  // acclient.c:877793
void __cdecl _E1244_2()
{
  char *v0; // esi@1

  v0 = &PhysFlags_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007567E0) --------------------------------------------------------  // acclient.c:877806
void __cdecl _E1247_2()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756810) --------------------------------------------------------  // acclient.c:877819
void __cdecl _E1250_2()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756840) --------------------------------------------------------  // acclient.c:877832
void __cdecl _E1253_2()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756870) --------------------------------------------------------  // acclient.c:877845
void __cdecl _E1256_2()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007568A0) --------------------------------------------------------  // acclient.c:877858
void __cdecl _E1259_2()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007568D0) --------------------------------------------------------  // acclient.c:877871
void __cdecl _E1262_2()
{
  char *v0; // esi@1

  v0 = &Position_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756900) --------------------------------------------------------  // acclient.c:877884
void __cdecl _E1265_2()
{
  char *v0; // esi@1

  v0 = &PointList_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756930) --------------------------------------------------------  // acclient.c:877897
void __cdecl _E1268_2()
{
  char *v0; // esi@1

  v0 = &Point_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756960) --------------------------------------------------------  // acclient.c:877910
void __cdecl _E1271_2()
{
  char *v0; // esi@1

  v0 = &DetailLevels_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756990) --------------------------------------------------------  // acclient.c:877923
void __cdecl _E1274_2()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007569C0) --------------------------------------------------------  // acclient.c:877936
void __cdecl _E1277_2()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007569F0) --------------------------------------------------------  // acclient.c:877949
void __cdecl _E1280_3()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756A20) --------------------------------------------------------  // acclient.c:877962
void __cdecl _E1283_2()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756A50) --------------------------------------------------------  // acclient.c:877975
void __cdecl _E1286_2()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756A80) --------------------------------------------------------  // acclient.c:877988
void __cdecl _E1289_1()
{
  char *v0; // esi@1

  v0 = &Point_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756AB0) --------------------------------------------------------  // acclient.c:878001
void __cdecl _E1292_2()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756AE0) --------------------------------------------------------  // acclient.c:878014
void __cdecl _E1295_1()
{
  char *v0; // esi@1

  v0 = &PointTexture_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756B10) --------------------------------------------------------  // acclient.c:878027
void __cdecl _E1298_1()
{
  char *v0; // esi@1

  v0 = &PointSize_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756B40) --------------------------------------------------------  // acclient.c:878040
void __cdecl _E1301_1()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00756B70) --------------------------------------------------------  // acclient.c:878053
void __cdecl _E1304_1()
{
  IDClass<_tagDataID,32,0> *v0; // edi@1
  signed int v1; // ebp@1
  unsigned int v2; // esi@2
  int v3; // esi@2

  v0 = &INVALID_DID_46;
  v1 = 4;
  do
  {
    v2 = v0[-1].id;
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

