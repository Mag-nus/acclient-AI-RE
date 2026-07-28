/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GamePlayUI
   Object     : ENGINE\uiframework\GamePlayUI.obj
   Functions  : 11
   Addresses  : 006A0DA0 - 007218A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A0DA0) --------------------------------------------------------  // acclient.c:697445
void __thiscall GamePlayUI::GamePlayUI(GamePlayUI *this)
{
  GamePlayUI *v1; // esi@1

  v1 = this;
  UIMainFramework::UIMainFramework((UIMainFramework *)&this->vfptr);
  v1->vfptr = (IInputActionCallbackVtbl *)&GamePlayUI::vftable;
  SmartBox::Show(SmartBox::smartbox);
}
// 8018B0: using guessed type int (__thiscall *GamePlayUI::vftable)(void *, char);

//----- (006A0DC0) --------------------------------------------------------  // acclient.c:697457
void __thiscall GamePlayUI::~GamePlayUI(GamePlayUI *this)
{
  UIMainFramework *v1; // esi@1

  v1 = (UIMainFramework *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&GamePlayUI::vftable;
  SmartBox::Hide(SmartBox::smartbox);
  UIMainFramework::~UIMainFramework(v1);
}
// 8018B0: using guessed type int (__thiscall *GamePlayUI::vftable)(void *, char);

//----- (006A0DE0) --------------------------------------------------------  // acclient.c:697469
UIMainFramework *__thiscall GamePlayUI::scalar_deleting_destructor(GamePlayUI *this, unsigned int a2)
{
  UIMainFramework *v2; // esi@1

  v2 = (UIMainFramework *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&GamePlayUI::vftable;
  SmartBox::Hide(SmartBox::smartbox);
  UIMainFramework::~UIMainFramework(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 8018B0: using guessed type int (__thiscall *GamePlayUI::vftable)(void *, char);

//----- (007217D0) --------------------------------------------------------  // acclient.c:819207
void sub_7217D0()
{
  flt_8F9CE0 = 1000.0 + 1.0;
}

//----- (007217F0) --------------------------------------------------------  // acclient.c:819213
void sub_7217F0()
{
  flt_8F9CE4 = 24.0 * 8.0;
}

//----- (00721810) --------------------------------------------------------  // acclient.c:819219
void sub_721810()
{
  flt_8F9CE8 = 24.0 * 0.5;
}

//----- (00721830) --------------------------------------------------------  // acclient.c:819225
void sub_721830()
{
  flt_8F9CF0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00721850) --------------------------------------------------------  // acclient.c:819231
void _E99_48()
{
  dbl_8F9CF8 = 1.0 / 30.0;
}

//----- (00721870) --------------------------------------------------------  // acclient.c:819237
void _E101_46()
{
  dbl_8F9D00 = 1.0 / 5.0;
}

//----- (00721890) --------------------------------------------------------  // acclient.c:819243
void sub_721890()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F9D08, PFID_A8R8G8B8);
}

//----- (007218A0) --------------------------------------------------------  // acclient.c:819249
int sub_7218A0()
{
  return atexit(nullsub_365);
}

