/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPhysicsObjHooks
   Object     : PORTAL\cphysobj\CPhysicsObjHooks.obj
   Functions  : 10
   Addresses  : 0051BA50 - 006FC9D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051BA50) --------------------------------------------------------  // acclient.c:329679
void __thiscall FPHook::FPHook(FPHook *this, PhysicsObjHook::HookType _hook_type, long double _time_created, long double _delta, float _start_value, float _end_value, void *user_data)
{
  this->hook_type = _hook_type;
  this->time_created = _time_created;
  this->interpolation_time = _delta;
  this->prev = 0;
  this->next = 0;
  this->user_data = user_data;
  this->vfptr = (PhysicsObjHookVtbl *)&FPHook::vftable;
  this->start_value = _start_value;
  this->end_value = _end_value;
}
// 7C7028: using guessed type int (__thiscall *FPHook::vftable)(FPHook *this, struct CPhysicsObj *);

//----- (0051BAA0) --------------------------------------------------------  // acclient.c:329694
BOOL __thiscall FPHook::Execute(FPHook *this, CPhysicsObj *object)
{
  long double v2; // st7@1
  float curr_value; // ST04_4@6
  float v5; // [sp+8h] [bp-4h]@2

  v2 = PhysicsTimer::curr_time - this->time_created;
  if ( v2 > 0.0 )
  {
    if ( v2 < this->interpolation_time )
      v5 = v2 / this->interpolation_time;
    else
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  curr_value = (this->end_value - this->start_value) * v5 + this->start_value;
  CPhysicsObj::process_fp_hook(object, this->hook_type, curr_value, this->user_data);
  return v5 == 1.0;
}

//----- (006FC900) --------------------------------------------------------  // acclient.c:784907
int sub_6FC900()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_8;
  INITIAL_MAX_DATA_RATE_75 = LOWEST_DATA_RATE_8;
  return result;
}

//----- (006FC910) --------------------------------------------------------  // acclient.c:784917
void sub_6FC910()
{
  flt_844138 = 1000.0 + 1.0;
}

//----- (006FC930) --------------------------------------------------------  // acclient.c:784923
void _E99_17()
{
  flt_84413C = 24.0 * 8.0;
}

//----- (006FC950) --------------------------------------------------------  // acclient.c:784929
void _E101_14()
{
  flt_844140 = 24.0 * 0.5;
}

//----- (006FC970) --------------------------------------------------------  // acclient.c:784935
void sub_6FC970()
{
  flt_844148 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FC990) --------------------------------------------------------  // acclient.c:784941
void _E105_21()
{
  dbl_844150 = 1.0 / 30.0;
}

//----- (006FC9B0) --------------------------------------------------------  // acclient.c:784947
void _E107_16()
{
  dbl_844158 = 1.0 / 5.0;
}

//----- (006FC9D0) --------------------------------------------------------  // acclient.c:784953
int sub_6FC9D0()
{
  return atexit(nullsub_1100);
}

