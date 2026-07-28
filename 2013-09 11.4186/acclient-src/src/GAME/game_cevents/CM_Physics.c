/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CM_Physics
   Object     : GAME\game_cevents\CM_Physics.obj
   Functions  : 22
   Addresses  : 006AC6A0 - 00722A50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AC6A0) --------------------------------------------------------  // acclient.c:709598
signed int __cdecl CM_Physics::DispatchSB_DeleteObject(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  int v3; // edx@3
  int v4; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, v3 = *(_DWORD *)v2, v4 = (int)(v2 + 4), v3 == 63303) )
    result = SmartBox::HandleDeleteObject(smartbox, blob, *(_DWORD *)v4, *(_WORD *)(v4 + 4));
  else
    result = 3;
  return result;
}

//----- (006AC6E0) --------------------------------------------------------  // acclient.c:709613
signed int __cdecl CM_Physics::DispatchSB_PlayScriptType(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  int v3; // edx@3
  int v4; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, v3 = *(_DWORD *)v2, v4 = (int)(v2 + 4), v3 == 63317) )
    result = SmartBox::HandlePlayScriptType(smartbox, blob, *(_DWORD *)v4, *(_DWORD *)(v4 + 4), *(float *)(v4 + 8));
  else
    result = 3;
  return result;
}

//----- (006AC730) --------------------------------------------------------  // acclient.c:709628
signed int __cdecl CM_Physics::DispatchSB_PlayerTeleport(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, *(_DWORD *)v2 == 63313) )
    result = SmartBox::HandlePlayerTeleport(smartbox, blob, *((_WORD *)v2 + 2));
  else
    result = 3;
  return result;
}

//----- (006AC760) --------------------------------------------------------  // acclient.c:709641
signed int __cdecl CM_Physics::DispatchSB_SoundEvent(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  int v3; // edx@3
  int v4; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, v3 = *(_DWORD *)v2, v4 = (int)(v2 + 4), v3 == 63312) )
    result = SmartBox::HandleSoundEvent(smartbox, blob, *(_DWORD *)v4, *(_DWORD *)(v4 + 4), *(float *)(v4 + 8));
  else
    result = 3;
  return result;
}

//----- (006AC7B0) --------------------------------------------------------  // acclient.c:709656
signed int __usercall CM_Physics::DispatchSB_UpdateObject@<eax>(double a1@<st0>, SmartBox *smartbox, NetBlob *blob)
{
  signed int result; // eax@3
  char *v4; // eax@4
  unsigned int v5; // esi@4
  int v6; // ecx@4
  char *v7; // edi@4
  int v8; // eax@4
  unsigned int v9; // ebp@6
  signed int v10; // esi@6
  void *buf; // [sp+4h] [bp-1B8h]@4
  ObjDesc objdesc; // [sp+8h] [bp-1B4h]@6
  PublicWeenieDesc wdesc; // [sp+34h] [bp-188h]@6
  PhysicsDesc physicsdesc; // [sp+E4h] [bp-D8h]@6

  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    v5 = blob->bufSize_;
    buf = v4;
    v6 = *(_DWORD *)v4;
    v7 = v4;
    v8 = (int)(v4 + 4);
    buf = (void *)v8;
    if ( v6 == 63451 )
    {
      v9 = *(_DWORD *)v8;
      buf = (void *)(v8 + 4);
      ObjDesc::ObjDesc(&objdesc);
      ObjDesc::UnPack(&objdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      PhysicsDesc::PhysicsDesc(&physicsdesc);
      PhysicsDesc::UnPack(&physicsdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      PublicWeenieDesc::PublicWeenieDesc(&wdesc);
      PublicWeenieDesc::UnPack(&wdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      v10 = SmartBox::HandleUpdateObject(
              smartbox,
              a1,
              blob,
              v9,
              (VisualDesc *)&objdesc.vfptr,
              &physicsdesc,
              (WeenieDesc *)&wdesc.vfptr);
      PublicWeenieDesc::~PublicWeenieDesc(&wdesc);
      PhysicsDesc::~PhysicsDesc(&physicsdesc);
      ObjDesc::~ObjDesc(&objdesc);
      result = v10;
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (006AC8D0) --------------------------------------------------------  // acclient.c:709716
signed int __usercall CM_Physics::DispatchSB_CreateObject@<eax>(double a1@<st0>, SmartBox *smartbox, NetBlob *blob)
{
  signed int result; // eax@3
  char *v4; // eax@4
  unsigned int v5; // esi@4
  int v6; // ecx@4
  char *v7; // edi@4
  int v8; // eax@4
  unsigned int v9; // ebp@6
  signed int v10; // esi@6
  void *buf; // [sp+4h] [bp-1B8h]@4
  ObjDesc objdesc; // [sp+8h] [bp-1B4h]@6
  PublicWeenieDesc wdesc; // [sp+34h] [bp-188h]@6
  PhysicsDesc physicsdesc; // [sp+E4h] [bp-D8h]@6

  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    v5 = blob->bufSize_;
    buf = v4;
    v6 = *(_DWORD *)v4;
    v7 = v4;
    v8 = (int)(v4 + 4);
    buf = (void *)v8;
    if ( v6 == 63301 )
    {
      v9 = *(_DWORD *)v8;
      buf = (void *)(v8 + 4);
      ObjDesc::ObjDesc(&objdesc);
      ObjDesc::UnPack(&objdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      PhysicsDesc::PhysicsDesc(&physicsdesc);
      PhysicsDesc::UnPack(&physicsdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      PublicWeenieDesc::PublicWeenieDesc(&wdesc);
      PublicWeenieDesc::UnPack(&wdesc, &buf, (unsigned int)&v7[v5 - (_DWORD)buf]);
      v10 = SmartBox::HandleCreateObject(
              smartbox,
              a1,
              blob,
              v9,
              (VisualDesc *)&objdesc.vfptr,
              &physicsdesc,
              (WeenieDesc *)&wdesc.vfptr,
              0);
      PublicWeenieDesc::~PublicWeenieDesc(&wdesc);
      PhysicsDesc::~PhysicsDesc(&physicsdesc);
      ObjDesc::~ObjDesc(&objdesc);
      result = v10;
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (006AC9F0) --------------------------------------------------------  // acclient.c:709777
signed int __cdecl CM_Physics::DispatchSB_CreatePlayer(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, *(_DWORD *)v2 == 63302) )
    result = SmartBox::HandleCreatePlayer(smartbox, blob, *((_DWORD *)v2 + 1));
  else
    result = 3;
  return result;
}

//----- (006ACA20) --------------------------------------------------------  // acclient.c:709790
signed int __cdecl CM_Physics::DispatchSB_ObjDescEvent(SmartBox *smartbox, NetBlob *blob)
{
  NetBlob *v2; // ebx@1
  signed int result; // eax@3
  char *v4; // eax@4
  unsigned int v5; // esi@4
  int v6; // ecx@4
  char *v7; // edi@4
  int v8; // eax@4
  unsigned int v9; // ebp@6
  signed int v10; // esi@6
  PhysicsTimestampPack timestamps; // [sp+4h] [bp-34h]@6
  ObjDesc desc; // [sp+Ch] [bp-2Ch]@6

  v2 = blob;
  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    v5 = blob->bufSize_;
    blob = (NetBlob *)v4;
    v6 = *(_DWORD *)v4;
    v7 = v4;
    v8 = (int)(v4 + 4);
    blob = (NetBlob *)v8;
    if ( v6 == 63013 )
    {
      v9 = *(_DWORD *)v8;
      blob = (NetBlob *)(v8 + 4);
      ObjDesc::ObjDesc(&desc);
      ObjDesc::UnPack(&desc, (void **)&blob, (unsigned int)&v7[v5 - (_DWORD)blob]);
      PhysicsTimestampPack::PhysicsTimestampPack(&timestamps);
      PhysicsTimestampPack::UnPack(&timestamps, (void **)&blob, (unsigned int)&v7[v5 - (_DWORD)blob]);
      v10 = SmartBox::HandleObjDescEvent(smartbox, v2, v9, (VisualDesc *)&desc.vfptr, &timestamps);
      timestamps.vfptr = (PackObjVtbl *)&PackObj::vftable;
      ObjDesc::~ObjDesc(&desc);
      result = v10;
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (006ACAF0) --------------------------------------------------------  // acclient.c:709841
signed int __cdecl CM_Physics::DispatchSB_ParentEvent(SmartBox *smartbox, NetBlob *blob)
{
  NetBlob *v2; // edi@1
  signed int result; // eax@3
  char *v4; // eax@4
  int v5; // ecx@4
  NetBlob *v6; // eax@4
  unsigned int v7; // esi@4
  int v8; // eax@6
  unsigned int v9; // ebx@6
  unsigned int v10; // ebp@6
  unsigned int v11; // ecx@6
  unsigned int child_location; // ST30_4@6
  unsigned int placement_id; // ST2C_4@6
  char *bufStart; // [sp+4h] [bp-14h]@4
  PhysicsTimestampPack timestamps; // [sp+10h] [bp-8h]@6

  v2 = blob;
  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    blob = (NetBlob *)v4;
    v5 = *(_DWORD *)v4;
    bufStart = v4;
    v6 = (NetBlob *)(v4 + 4);
    v7 = v2->bufSize_;
    blob = v6;
    if ( v5 == 63305 )
    {
      v8 = (int)&v6->m_cRef;
      v9 = *(_DWORD *)(v8 - 4);
      blob = (NetBlob *)v8;
      v8 += 4;
      v10 = *(_DWORD *)(v8 - 4);
      blob = (NetBlob *)v8;
      v11 = *(_DWORD *)v8;
      blob = (NetBlob *)(v8 + 4);
      child_location = v11;
      placement_id = *(_DWORD *)(v8 + 4);
      blob = (NetBlob *)(v8 + 8);
      PhysicsTimestampPack::PhysicsTimestampPack(&timestamps);
      PhysicsTimestampPack::UnPack(&timestamps, (void **)&blob, (unsigned int)&bufStart[v7 - (_DWORD)blob]);
      result = SmartBox::HandleParentEvent(smartbox, v2, v9, v10, child_location, placement_id, &timestamps);
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (006ACBB0) --------------------------------------------------------  // acclient.c:709898
signed int __cdecl CM_Physics::DispatchSB_PickupEvent(SmartBox *smartbox, NetBlob *blob)
{
  NetBlob *v2; // edi@1
  signed int result; // eax@3
  char *v4; // eax@4
  int v5; // ecx@4
  char *v6; // ebp@4
  int v7; // eax@4
  unsigned int v8; // esi@4
  unsigned int v9; // ebx@6
  PhysicsTimestampPack timestamps; // [sp+4h] [bp-8h]@6

  v2 = blob;
  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    blob = (NetBlob *)v4;
    v5 = *(_DWORD *)v4;
    v6 = v4;
    v7 = (int)(v4 + 4);
    v8 = v2->bufSize_;
    blob = (NetBlob *)v7;
    if ( v5 == 63306 )
    {
      v9 = *(_DWORD *)v7;
      blob = (NetBlob *)(v7 + 4);
      PhysicsTimestampPack::PhysicsTimestampPack(&timestamps);
      PhysicsTimestampPack::UnPack(&timestamps, (void **)&blob, (unsigned int)&v6[v8 - (_DWORD)blob]);
      result = SmartBox::HandlePickupEvent(smartbox, v2, v9, &timestamps);
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (006ACC40) --------------------------------------------------------  // acclient.c:709941
signed int __cdecl CM_Physics::DispatchSB_PlayScriptID(SmartBox *smartbox, NetBlob *blob)
{
  char *v2; // eax@3
  int v3; // edx@3
  int v4; // eax@3
  signed int result; // eax@4

  if ( blob && smartbox && (v2 = blob->buf_, v3 = *(_DWORD *)v2, v4 = (int)(v2 + 4), v3 == 63316) )
    result = SmartBox::HandlePlayScriptID(smartbox, blob, *(_DWORD *)v4, *(IDClass<_tagDataID,32,0> *)(v4 + 4));
  else
    result = 3;
  return result;
}

//----- (006ACC80) --------------------------------------------------------  // acclient.c:709956
signed int __cdecl CM_Physics::DispatchSB_SetState(SmartBox *smartbox, NetBlob *blob)
{
  NetBlob *v2; // edi@1
  signed int result; // eax@3
  char *v4; // eax@4
  int v5; // ecx@4
  int v6; // eax@4
  unsigned int v7; // esi@4
  unsigned int v8; // ebx@6
  unsigned int v9; // ebp@6
  char *bufStart; // [sp+4h] [bp-Ch]@4
  PhysicsTimestampPack timestamps; // [sp+8h] [bp-8h]@6

  v2 = blob;
  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    blob = (NetBlob *)v4;
    v5 = *(_DWORD *)v4;
    bufStart = v4;
    v6 = (int)(v4 + 4);
    v7 = v2->bufSize_;
    blob = (NetBlob *)v6;
    if ( v5 == 63307 )
    {
      v8 = *(_DWORD *)v6;
      blob = (NetBlob *)(v6 + 4);
      v9 = *(_DWORD *)(v6 + 4);
      blob = (NetBlob *)(v6 + 8);
      PhysicsTimestampPack::PhysicsTimestampPack(&timestamps);
      PhysicsTimestampPack::UnPack(&timestamps, (void **)&blob, (unsigned int)&bufStart[v7 - (_DWORD)blob]);
      result = SmartBox::HandleSetState(smartbox, v2, v8, v9, &timestamps);
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (006ACD20) --------------------------------------------------------  // acclient.c:710002
signed int __cdecl CM_Physics::DispatchSB_VectorUpdate(SmartBox *smartbox, NetBlob *blob)
{
  NetBlob *v2; // ebx@1
  signed int result; // eax@3
  char *v4; // eax@4
  unsigned int v5; // esi@4
  int v6; // ecx@4
  char *v7; // edi@4
  int v8; // eax@4
  unsigned int v9; // ebp@6
  PhysicsTimestampPack timestamps; // [sp+4h] [bp-20h]@6
  AC1Legacy::Vector3 omega; // [sp+Ch] [bp-18h]@6
  AC1Legacy::Vector3 velocity; // [sp+18h] [bp-Ch]@6

  v2 = blob;
  if ( blob && smartbox )
  {
    v4 = blob->buf_;
    v5 = blob->bufSize_;
    blob = (NetBlob *)v4;
    v6 = *(_DWORD *)v4;
    v7 = v4;
    v8 = (int)(v4 + 4);
    blob = (NetBlob *)v8;
    if ( v6 == 63310 )
    {
      v9 = *(_DWORD *)v8;
      blob = (NetBlob *)(v8 + 4);
      AC1Legacy::Vector3::UnPack(&velocity, (void **)&blob, (unsigned int)&v7[v5 - (v8 + 4)]);
      AC1Legacy::Vector3::UnPack(&omega, (void **)&blob, (unsigned int)&v7[v5 - (_DWORD)blob]);
      PhysicsTimestampPack::PhysicsTimestampPack(&timestamps);
      PhysicsTimestampPack::UnPack(&timestamps, (void **)&blob, (unsigned int)&v7[v5 - (_DWORD)blob]);
      result = SmartBox::HandleVectorUpdate(smartbox, v2, v9, &velocity, &omega, &timestamps);
    }
    else
    {
      result = 3;
    }
  }
  else
  {
    result = 3;
  }
  return result;
}

//----- (00722970) --------------------------------------------------------  // acclient.c:820439
void sub_722970()
{
  flt_8FA3C0 = 1000.0 + 1.0;
}

//----- (00722990) --------------------------------------------------------  // acclient.c:820445
void sub_722990()
{
  flt_8FA3C4 = 24.0 * 8.0;
}

//----- (007229B0) --------------------------------------------------------  // acclient.c:820451
void sub_7229B0()
{
  flt_8FA3C8 = 24.0 * 0.5;
}

//----- (007229D0) --------------------------------------------------------  // acclient.c:820457
void sub_7229D0()
{
  flt_8FA3D0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007229F0) --------------------------------------------------------  // acclient.c:820463
void _E99_49()
{
  dbl_8FA3D8 = 1.0 / 30.0;
}

//----- (00722A10) --------------------------------------------------------  // acclient.c:820469
void _E101_47()
{
  dbl_8FA3E0 = 1.0 / 5.0;
}

//----- (00722A30) --------------------------------------------------------  // acclient.c:820475
int _E107_49()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_47;
  dword_8FA3E8 = LOWEST_DATA_RATE_47;
  return result;
}

//----- (00722A40) --------------------------------------------------------  // acclient.c:820485
void sub_722A40()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA3EC, PFID_A8R8G8B8);
}

//----- (00722A50) --------------------------------------------------------  // acclient.c:820491
int sub_722A50()
{
  return atexit(nullsub_441);
}

