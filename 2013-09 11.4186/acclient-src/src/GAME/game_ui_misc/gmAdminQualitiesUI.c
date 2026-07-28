/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmAdminQualitiesUI
   Object     : GAME\game_ui_misc\gmAdminQualitiesUI.obj
   Functions  : 20
   Addresses  : 004CCBE0 - 006F3450 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004CCBE0) --------------------------------------------------------  // acclient.c:254087
gmAdminQualitiesUI *__thiscall gmAdminQualitiesUI::DynamicCast(gmAdminQualitiesUI *this, unsigned int i_eType)
{
  gmAdminQualitiesUI *result; // eax@1

  result = this;
  if ( i_eType != 268435519 )
    result = (gmAdminQualitiesUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004CCC00) --------------------------------------------------------  // acclient.c:254098
signed int gmAdminQualitiesUI::GetUIElementType()
{
  return 268435519;
}

//----- (004CCC10) --------------------------------------------------------  // acclient.c:254104
UIElement *__usercall gmAdminQualitiesUI::Create@<eax>(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  void *v3; // esi@1
  UIElement *result; // eax@2

  v3 = operator new(0x5FCu);
  if ( v3 )
  {
    UIElement_Field::UIElement_Field((UIElement_Field *)v3, a1, _layout, _full_desc);
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    *(_DWORD *)v3 = &gmAdminQualitiesUI::vftable;
    *((_DWORD *)v3 + 382) = &ClientHousingSystem::vftable;
    result = (UIElement *)v3;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 7B8F50: using guessed type int (__thiscall *gmAdminQualitiesUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CCC60) --------------------------------------------------------  // acclient.c:254128
UIElement_Field *__thiscall gmAdminQualitiesUI::vector_deleting_destructor(gmAdminQualitiesUI *this, unsigned int a2)
{
  UIElement_Field *v2; // esi@1
  NoticeHandler *v3; // ecx@1

  v2 = (UIElement_Field *)this;
  v3 = (NoticeHandler *)&this->vfptr;
  v2->vfptr = (IInputActionCallbackVtbl *)&gmAdminQualitiesUI::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v3->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v3);
  UIElement_Field::~UIElement_Field(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7B8F50: using guessed type int (__thiscall *gmAdminQualitiesUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004CCCA0) --------------------------------------------------------  // acclient.c:254148
void __cdecl gmAdminQualitiesUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000003Fu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmAdminQualitiesUI::Create);
}

//----- (006F3310) --------------------------------------------------------  // acclient.c:775735
void _E91_94()
{
  outside_val_86 = 1000.0 + 1.0;
}

//----- (006F3330) --------------------------------------------------------  // acclient.c:775741
void _E93_70()
{
  block_length_86 = 24.0 * 8.0;
}

//----- (006F3350) --------------------------------------------------------  // acclient.c:775747
void _E95_70()
{
  half_square_length_86 = 24.0 * 0.5;
}

//----- (006F3370) --------------------------------------------------------  // acclient.c:775753
int _E97_95()
{
  return atexit(nullsub_790);
}

//----- (006F3380) --------------------------------------------------------  // acclient.c:775759
int _E100_88()
{
  return atexit(nullsub_791);
}

//----- (006F3390) --------------------------------------------------------  // acclient.c:775765
int _E103_80()
{
  return atexit(_E104_95);
}

//----- (006F33A0) --------------------------------------------------------  // acclient.c:775771
void _E106_53()
{
  DEFAULT_VIEW_RADIUS_55 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F33C0) --------------------------------------------------------  // acclient.c:775777
void _E108_40()
{
  MIN_QUANTUM_55 = 1.0 / 30.0;
}

//----- (006F33E0) --------------------------------------------------------  // acclient.c:775783
void _E110_31()
{
  MAX_QUANTUM_55 = 1.0 / 5.0;
}

//----- (006F3400) --------------------------------------------------------  // acclient.c:775789
void _E112_47()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_90, PFID_A8R8G8B8);
}

//----- (006F3410) --------------------------------------------------------  // acclient.c:775795
void _E115_45()
{
  LOWEST_DATA_RATE_92 = 1024;
}

//----- (006F3420) --------------------------------------------------------  // acclient.c:775801
void _E117_33()
{
  HIGHEST_DATA_RATE_92 = 0x7FFF;
}

//----- (006F3430) --------------------------------------------------------  // acclient.c:775807
int _E119_16()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_92;
  INITIAL_MAX_DATA_RATE_40 = LOWEST_DATA_RATE_92;
  return result;
}

//----- (006F3440) --------------------------------------------------------  // acclient.c:775817
int _E121_44()
{
  return atexit(_E122_76);
}

//----- (006F3450) --------------------------------------------------------  // acclient.c:775823
int sub_6F3450()
{
  return atexit(nullsub_789);
}

