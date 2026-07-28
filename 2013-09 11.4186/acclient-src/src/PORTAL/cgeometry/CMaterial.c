/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMaterial
   Object     : PORTAL\cgeometry\CMaterial.obj
   Functions  : 9
   Addresses  : 005396A0 - 0069E710 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005396A0) --------------------------------------------------------  // acclient.c:360584
void __thiscall CMaterial::CheckAlphaValues(CMaterial *this)
{
  this->has_alpha = this->d3d_material.Ambient.a < 1.0
                 || this->d3d_material.Diffuse.a < 1.0
                 || this->d3d_material.Specular.a < 1.0
                 || this->d3d_material.Emissive.a < 1.0;
}

//----- (005396F0) --------------------------------------------------------  // acclient.c:360593
void __thiscall CMaterial::SetTranslucencySimple(CMaterial *this, float trans)
{
  double v2; // st7@1

  v2 = 1.0 - trans;
  this->d3d_material.Ambient.a = v2;
  this->d3d_material.Diffuse.a = v2;
  this->d3d_material.Specular.a = v2;
  this->d3d_material.Emissive.a = v2;
  CMaterial::CheckAlphaValues(this);
}

//----- (00539710) --------------------------------------------------------  // acclient.c:360606
double __thiscall CMaterial::GetTranslucencySimple(CMaterial *this)
{
  return 1.0 - this->d3d_material.Diffuse.a;
}

//----- (00539720) --------------------------------------------------------  // acclient.c:360612
void __thiscall CMaterial::SetLuminositySimple(CMaterial *this, float lumi)
{
  this->d3d_material.Emissive.r = lumi;
  this->d3d_material.Emissive.g = lumi;
  this->d3d_material.Emissive.b = lumi;
}

//----- (00539740) --------------------------------------------------------  // acclient.c:360620
double __thiscall CMaterial::GetLuminositySimple(CMaterial *this)
{
  return this->d3d_material.Emissive.r;
}

//----- (00539750) --------------------------------------------------------  // acclient.c:360626
void __thiscall CMaterial::SetDiffuseSimple(CMaterial *this, float diffuse)
{
  this->d3d_material.Diffuse.r = diffuse;
  this->d3d_material.Diffuse.g = diffuse;
  this->d3d_material.Diffuse.b = diffuse;
}

//----- (00539770) --------------------------------------------------------  // acclient.c:360634
void __thiscall CMaterial::CMaterial(CMaterial *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&DragDropInfo::vftable;
  this->has_alpha = 0;
  memset(&this->d3d_material, 0, sizeof(this->d3d_material));
  LODWORD(this->d3d_material.Diffuse.r) = 1065353216;
  LODWORD(this->d3d_material.Diffuse.g) = 1065353216;
  LODWORD(this->d3d_material.Diffuse.b) = 1065353216;
  LODWORD(this->d3d_material.Diffuse.a) = 1065353216;
  LODWORD(this->d3d_material.Ambient.r) = 1065353216;
  LODWORD(this->d3d_material.Ambient.g) = 1065353216;
  LODWORD(this->d3d_material.Ambient.b) = 1065353216;
  LODWORD(this->d3d_material.Ambient.a) = 1065353216;
}
// 7C9870: using guessed type int (__thiscall *DragDropInfo::vftable)(void *, char);

//----- (005397C0) --------------------------------------------------------  // acclient.c:360652
void __thiscall CMaterial::CMaterial(CMaterial *this, CMaterial *material)
{
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&DragDropInfo::vftable;
  this->m_cRef = 1;
  this->vfptr = material->vfptr;
}
// 7C9870: using guessed type int (__thiscall *DragDropInfo::vftable)(void *, char);

//----- (0069E710) --------------------------------------------------------  // acclient.c:694728
double __thiscall CMaterial::GetColorDiffuseSimple(CMaterial *this)
{
  return this->d3d_material.Diffuse.r;
}

