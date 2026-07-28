/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MovementSystem
   Object     : PORTAL\gameplay_misc\MovementSystem.obj
   Functions  : 7
   Addresses  : 006B0950 - 00723330 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B0950) --------------------------------------------------------  // acclient.c:713789
double __cdecl MovementSystem::GetRunRate(const float load, const int runskill, const float scaling)
{
  double v3; // st7@1
  double v4; // st6@1
  double result; // st7@2

  v3 = EncumbranceSystem::LoadMod(load);
  v4 = (double)runskill;
  if ( v4 == 800.0 )
    result = 18.0 / 4.0;
  else
    result = (v3 * (v4 / (v4 + 200.0) * 11.0) + 4.0) / scaling / 4.0;
  return result;
}

//----- (006B09B0) --------------------------------------------------------  // acclient.c:713805
double __cdecl MovementSystem::GetJumpHeight(const float load, const int jumpskill, const float _power, const float scaling)
{
  double result; // st7@5
  const float power; // [sp+0h] [bp-4h]@1
  const float _powera; // [sp+10h] [bp+Ch]@5

  power = _power;
  if ( _power <= 1.0 )
  {
    if ( _power < 0.0 )
      power = 0.0;
  }
  else
  {
    power = 1.0;
  }
  _powera = (double)jumpskill;
  result = EncumbranceSystem::LoadMod(load) * (_powera / (_powera + 1300.0) * 22.200001 + 0.050000001) * power / scaling;
  if ( result < 0.34999999 )
    result = 0.34999999;
  return result;
}

//----- (006B0A40) --------------------------------------------------------  // acclient.c:713829
unsigned __int64 __cdecl MovementSystem::JumpStaminaCost(float power, float load, int bPK)
{
  unsigned __int64 result; // rax@2

  if ( bPK )
    result = (unsigned __int64)((power + 1.0) * 100.0);
  else
    result = (unsigned __int64)_ceil((load + 0.5) * power * 8.0 + 2.0);
  return result;
}

//----- (007232D0) --------------------------------------------------------  // acclient.c:821090
void sub_7232D0()
{
  flt_8FA75C = 1000.0 + 1.0;
}

//----- (007232F0) --------------------------------------------------------  // acclient.c:821096
void sub_7232F0()
{
  flt_8FA760 = 24.0 * 8.0;
}

//----- (00723310) --------------------------------------------------------  // acclient.c:821102
void sub_723310()
{
  flt_8FA764 = 24.0 * 0.5;
}

//----- (00723330) --------------------------------------------------------  // acclient.c:821108
int sub_723330()
{
  return atexit(nullsub_1036);
}

