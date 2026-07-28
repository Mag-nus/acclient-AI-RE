/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Viewport
   Object     : ENGINE\uielement_types\UIElement_Viewport.obj
   Functions  : 21
   Addresses  : 0046BA70 - 006EBD60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0046BA70) --------------------------------------------------------  // acclient.c:168241
signed int __thiscall UIElement_Viewport::DynamicCast(UIElement_Viewport *this, unsigned int i_eType)
{
  return i_eType != 13 ? 0 : (unsigned int)this;
}

//----- (0046BA90) --------------------------------------------------------  // acclient.c:168247
UIElement *__usercall UIElement_Viewport::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x660u);
  if ( v3 )
  {
    UIElement::UIElement((UIElement *)v3, a1, _layout, _full_desc);
    CreatureMode::CreatureMode((CreatureMode *)((char *)v3 + 1520));
    *(_DWORD *)v3 = &UIElement_Viewport::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 79C870: using guessed type int (__thiscall *UIElement_Viewport::vftable)(void *, char);

//----- (0046BAD0) --------------------------------------------------------  // acclient.c:168269
void __userpurge UIElement_Viewport::OnSetAttribute(UIElement_Viewport *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  UIElement::OnSetAttribute((UIElement *)&this->vfptr, a2, _attribute);
  BaseProperty::GetPropertyName(_attribute);
}

//----- (0046BAF0) --------------------------------------------------------  // acclient.c:168276
bool __stdcall UIElement_Viewport::MakeUIObject(UIObject **o_pcUIObject)
{
  UIViewportObject *v2; // eax@2
  UIObject *v3; // eax@3
  bool result; // al@3

  if ( *o_pcUIObject )
  {
    result = 0;
  }
  else
  {
    v2 = (UIViewportObject *)operator new(0x58u);
    if ( v2 )
    {
      UIViewportObject::UIViewportObject(v2);
      *o_pcUIObject = v3;
      result = v3 != 0;
    }
    else
    {
      result = 0;
      *o_pcUIObject = 0;
    }
  }
  return result;
}

//----- (0046BB40) --------------------------------------------------------  // acclient.c:168305
void __thiscall UIElement_Viewport::PostInit(UIElement_Viewport *this)
{
  UIElement_Viewport *v1; // esi@1

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  CreatureMode::InitializeScene((CreatureMode *)&v1->creature_mode_objects);
}

//----- (0046BB60) --------------------------------------------------------  // acclient.c:168315
void __thiscall UIElement_Viewport::SetCamera(UIElement_Viewport *this, Vector3 *position, Vector3 *direction)
{
  CreatureMode *v3; // esi@1

  v3 = (CreatureMode *)&this->creature_mode_objects;
  CreatureMode::SetCameraPosition((CreatureMode *)&this->creature_mode_objects, (AC1Legacy::Vector3 *)position);
  CreatureMode::SetCameraDirection(v3, (AC1Legacy::Vector3 *)direction);
}

//----- (0046BB90) --------------------------------------------------------  // acclient.c:168325
void __thiscall UIElement_Viewport::SetLight(UIElement_Viewport *this, LIGHTINFO::LightType lightType, float intensity, Vector3 *direction)
{
  CreatureMode *v4; // esi@1

  v4 = (CreatureMode *)&this->creature_mode_objects;
  CreatureMode::RemoveAllLights((CreatureMode *)&this->creature_mode_objects);
  CreatureMode::AddLight(v4, lightType, intensity);
  CreatureMode::SetLightDirection(v4, 0, (AC1Legacy::Vector3 *)direction);
}

//----- (0046BBD0) --------------------------------------------------------  // acclient.c:168336
UIElement *__thiscall UIElement_Viewport::scalar_deleting_destructor(UIElement_Viewport *this, unsigned int a2)
{
  UIElement *v2; // esi@1

  v2 = (UIElement *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Viewport::vftable;
  CreatureMode::~CreatureMode((CreatureMode *)&this->creature_mode_objects);
  UIElement::~UIElement(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79C870: using guessed type int (__thiscall *UIElement_Viewport::vftable)(void *, char);

//----- (0046BC10) --------------------------------------------------------  // acclient.c:168351
void __cdecl UIElement_Viewport::Register()
{
  UIElement::RegisterElementClass(0xDu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Viewport::Create);
}

//----- (0046BC20) --------------------------------------------------------  // acclient.c:168357
char __thiscall UIElement_Viewport::InqAvailableProperties(UIElement_Viewport *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement::InqAvailableProperties((UIElement *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0x14u, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006EBC60) --------------------------------------------------------  // acclient.c:767586
void _E91_34()
{
  outside_val_26 = 1000.0 + 1.0;
}

//----- (006EBC80) --------------------------------------------------------  // acclient.c:767592
void _E93_11()
{
  block_length_26 = 24.0 * 8.0;
}

//----- (006EBCA0) --------------------------------------------------------  // acclient.c:767598
void _E95_11()
{
  half_square_length_26 = 24.0 * 0.5;
}

//----- (006EBCC0) --------------------------------------------------------  // acclient.c:767604
void _E97_34()
{
  DEFAULT_VIEW_RADIUS_11 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EBCE0) --------------------------------------------------------  // acclient.c:767610
void _E99_8()
{
  MIN_QUANTUM_11 = 1.0 / 30.0;
}

//----- (006EBD00) --------------------------------------------------------  // acclient.c:767616
void _E101_4()
{
  MAX_QUANTUM_11 = 1.0 / 5.0;
}

//----- (006EBD20) --------------------------------------------------------  // acclient.c:767622
void _E103_20()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_43, PFID_A8R8G8B8);
}

//----- (006EBD30) --------------------------------------------------------  // acclient.c:767628
void _E105_11()
{
  LOWEST_DATA_RATE_57 = 1024;
}

//----- (006EBD40) --------------------------------------------------------  // acclient.c:767634
void _E107_4()
{
  HIGHEST_DATA_RATE_57 = 0x7FFF;
}

//----- (006EBD50) --------------------------------------------------------  // acclient.c:767640
int _E109_16()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_57;
  INITIAL_MAX_DATA_RATE_5 = LOWEST_DATA_RATE_57;
  return result;
}

//----- (006EBD60) --------------------------------------------------------  // acclient.c:767650
int _E1_61()
{
  return atexit(_E2_61);
}

