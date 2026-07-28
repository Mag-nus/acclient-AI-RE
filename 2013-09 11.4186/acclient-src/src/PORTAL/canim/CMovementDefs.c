/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CMovementDefs
   Object     : PORTAL\canim\CMovementDefs.obj
   Functions  : 10
   Addresses  : 0052A9A0 - 006FDD10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0052A9A0) --------------------------------------------------------  // acclient.c:346152
void __thiscall MovementParameters::towards_and_away(MovementParameters *this, float curr_distance, float curr_heading, unsigned int *command, int *moving_away)
{
  if ( curr_distance <= (double)this->distance_to_object )
  {
    if ( curr_distance - this->min_distance >= 0.00019999999 )
    {
      *command = 0;
    }
    else
    {
      *command = 1157627910;
      *moving_away = 1;
    }
  }
  else
  {
    *command = 1157627909;
    *moving_away = 0;
  }
}

//----- (0052AA00) --------------------------------------------------------  // acclient.c:346174
void __thiscall MovementParameters::get_command(MovementParameters *this, float curr_distance, float curr_heading, unsigned int *command, HoldKey *key, int *moving_away)
{
  MovementParameters *v6; // esi@1
  unsigned int v7; // eax@1
  unsigned int v8; // eax@11

  v6 = this;
  v7 = this->bitfield;
  if ( BYTE1(v7) & 2 )
  {
    if ( BYTE1(v7) & 1 )
    {
      MovementParameters::towards_and_away(this, curr_distance, curr_heading, command, moving_away);
      goto LABEL_11;
    }
    goto LABEL_8;
  }
  if ( !(BYTE1(v7) & 1) )
  {
LABEL_8:
    if ( curr_distance > (double)this->distance_to_object )
    {
      *command = 1157627909;
      *moving_away = 0;
    }
    else
    {
      *command = 0;
    }
    goto LABEL_11;
  }
  if ( curr_distance < (double)this->min_distance )
  {
    *command = 1157627909;
    *moving_away = 1;
  }
  else
  {
    *command = 0;
  }
LABEL_11:
  v8 = v6->bitfield;
  if ( v8 & 0x10 || v8 & 2 && (!(v8 & 1) || curr_distance - v6->distance_to_object > v6->walk_run_threshhold) )
    *key = 2;
  else
    *key = 1;
}

//----- (0052AAD0) --------------------------------------------------------  // acclient.c:346223
double __stdcall MovementParameters::get_desired_heading(unsigned int command, int moving_away)
{
  if ( command == 1140850695 || command == 1157627909 )
  {
    if ( moving_away )
      return 180.0;
    return 0.0;
  }
  if ( command == 1157627910 )
  {
    if ( !moving_away )
      return 180.0;
    return 0.0;
  }
  return 0.0;
}

//----- (0052AB20) --------------------------------------------------------  // acclient.c:346241
signed int __thiscall MovementParameters::Pack(MovementParameters *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2
  char *v6; // esi@2
  char *v7; // edx@2
  char *v8; // esi@2
  char *v9; // edx@2
  char *v10; // esi@2
  char *v11; // edx@2

  if ( size >= 0x28 )
  {
    *(_DWORD *)*addr = this->bitfield;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(float *)v3 = this->distance_to_object;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(float *)v4 = this->min_distance;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = this->fail_distance;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = this->desired_heading;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = this->speed;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(float *)v8 = this->walk_run_threshhold;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = this->context_id;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = this->hold_key_to_apply;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = this->action_stamp;
    *addr = (char *)*addr + 4;
  }
  return 40;
}

//----- (0052ABC0) --------------------------------------------------------  // acclient.c:346289
int __thiscall MovementParameters::UnPack(MovementParameters *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3
  char *v5; // edx@3
  char *v6; // edx@3
  char *v7; // edx@3
  char *v8; // edx@3
  char *v9; // edx@3
  char *v10; // edx@3
  char *v11; // edx@3
  char *v12; // edx@3

  if ( size >= 0x28 )
  {
    this->bitfield = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->distance_to_object) = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(this->min_distance) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(this->fail_distance) = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    LODWORD(this->desired_heading) = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(this->speed) = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LODWORD(this->walk_run_threshhold) = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    this->context_id = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    this->hold_key_to_apply = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    this->action_stamp = *(_DWORD *)v12;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0052AC50) --------------------------------------------------------  // acclient.c:346343
int __thiscall MovementParameters::UnPackNet(MovementParameters *this, MovementTypes::Type type, void **addr, unsigned int size)
{
  unsigned int v4; // edx@2
  void **v5; // eax@6
  char *v6; // esi@6
  char *v7; // edx@6
  char *v8; // esi@6
  char *v9; // edx@6
  char *v10; // esi@6
  char *v11; // esi@7
  float *v12; // edx@8
  int result; // eax@8

  switch ( type )
  {
    case 6:
    case 7:
      v4 = 28;
      goto LABEL_4;
    case 8:
    case 9:
      v4 = 12;
LABEL_4:
      if ( size < v4 )
        goto LABEL_9;
      switch ( type )
      {
        case 6:
        case 7:
          v5 = addr;
          this->bitfield = *(_DWORD *)*addr;
          v6 = (char *)*addr + 4;
          *addr = v6;
          LODWORD(this->distance_to_object) = *(_DWORD *)v6;
          v7 = (char *)*addr + 4;
          *addr = v7;
          LODWORD(this->min_distance) = *(_DWORD *)v7;
          v8 = (char *)*addr + 4;
          *addr = v8;
          LODWORD(this->fail_distance) = *(_DWORD *)v8;
          v9 = (char *)*addr + 4;
          *addr = v9;
          LODWORD(this->speed) = *(_DWORD *)v9;
          v10 = (char *)*addr + 4;
          *addr = v10;
          LODWORD(this->walk_run_threshhold) = *(_DWORD *)v10;
          break;
        case 8:
        case 9:
          v5 = addr;
          this->bitfield = *(_DWORD *)*addr;
          v11 = (char *)*addr + 4;
          *addr = v11;
          LODWORD(this->speed) = *(_DWORD *)v11;
          break;
        default:
          goto LABEL_9;
      }
      v12 = (float *)((char *)*v5 + 4);
      *v5 = v12;
      LODWORD(this->desired_heading) = *(_DWORD *)v12;
      *v5 = (char *)*v5 + 4;
      result = 1;
      break;
    default:
LABEL_9:
      result = 0;
      break;
  }
  return result;
}

//----- (006FDCB0) --------------------------------------------------------  // acclient.c:786052
void sub_6FDCB0()
{
  flt_8446C8 = 1000.0 + 1.0;
}

//----- (006FDCD0) --------------------------------------------------------  // acclient.c:786058
void sub_6FDCD0()
{
  flt_8446CC = 24.0 * 8.0;
}

//----- (006FDCF0) --------------------------------------------------------  // acclient.c:786064
void sub_6FDCF0()
{
  flt_8446D0 = 24.0 * 0.5;
}

//----- (006FDD10) --------------------------------------------------------  // acclient.c:786070
int sub_6FDD10()
{
  return atexit(nullsub_1139);
}

