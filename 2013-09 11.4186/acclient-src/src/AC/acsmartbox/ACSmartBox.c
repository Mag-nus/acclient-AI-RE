/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACSmartBox
   Object     : AC\acsmartbox\ACSmartBox.obj
   Functions  : 15
   Addresses  : 00559570 - 00707E60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00559570) --------------------------------------------------------  // acclient.c:392660
void __thiscall ACSmartBox::ACSmartBox(ACSmartBox *this, NIList<NetBlob *> *_in_queue)
{
  ACSmartBox *v2; // esi@1

  v2 = this;
  SmartBox::SmartBox((SmartBox *)&this->vfptr, _in_queue);
  v2->vfptr = (SmartBoxVtbl *)&ACSmartBox::vftable;
}
// 7CBEB8: using guessed type int (__thiscall *ACSmartBox::vftable)(void *, char);

//----- (00559590) --------------------------------------------------------  // acclient.c:392671
int __thiscall ACSmartBox::IsReadyToDispatchEvent(ACSmartBox *this, NetBlob *blob)
{
  int result; // eax@2

  if ( this->player_id )
  {
    result = 1;
  }
  else if ( blob->bufSize_ < 4 )
  {
    result = 0;
  }
  else
  {
    result = *(_DWORD *)blob->buf_ == 63302;
  }
  return result;
}

//----- (005595D0) --------------------------------------------------------  // acclient.c:392691
signed int __userpurge ACSmartBox::DispatchSmartBoxEvent@<eax>(ACSmartBox *this@<ecx>, double a2@<st0>, NetBlob *blob)
{
  NetBlob *v3; // ebx@1
  unsigned int v4; // edx@1
  char *v5; // eax@1
  ACSmartBox *v6; // esi@1
  unsigned int v7; // ecx@2
  int v8; // eax@2
  int v9; // ecx@8
  signed int result; // eax@10
  unsigned int v11; // ebp@12
  signed int v12; // eax@12
  signed int v13; // edi@12
  HashBaseData<unsigned long> *v14; // eax@14
  CPhysics *v15; // ecx@14
  int v16; // ecx@20
  int v17; // ecx@21
  unsigned int v18; // ebp@35
  CObjectMaint *v19; // ecx@35
  HashBaseData<unsigned long> *v20; // edi@35
  unsigned __int16 v21; // cx@35
  CPhysics *v22; // ecx@38
  unsigned int size; // [sp+8h] [bp-8h]@1
  unsigned __int16 instance_timestamp; // [sp+Ch] [bp-4h]@35

  v3 = blob;
  v4 = blob->bufSize_;
  v5 = blob->buf_;
  v6 = this;
  blob = (NetBlob *)blob->buf_;
  size = v4;
  if ( v4 < 4 )
    return 3;
  v7 = *(_DWORD *)v5;
  v8 = (int)(v5 + 4);
  blob = (NetBlob *)v8;
  if ( v7 <= 0xF74B )
  {
    if ( v7 == 63307 )
      return CM_Physics::DispatchSB_SetState((SmartBox *)&v6->vfptr, v3);
    if ( v7 > 0xF747 )
    {
      v16 = v7 - 63304;
      if ( v16 )
      {
        v17 = v16 - 1;
        if ( !v17 )
          return CM_Physics::DispatchSB_ParentEvent((SmartBox *)&v6->vfptr, v3);
        if ( v17 == 1 )
          return CM_Physics::DispatchSB_PickupEvent((SmartBox *)&v6->vfptr, v3);
        return 3;
      }
      v11 = *(_DWORD *)v8;
      blob = (NetBlob *)(v8 + 4);
      v13 = SmartBox::UnpackPositionEvent((SmartBox *)&v6->vfptr, a2, v11, (void **)&blob, v4);
      if ( v13 != 4 )
        return v13;
    }
    else
    {
      if ( v7 == 63303 )
        return CM_Physics::DispatchSB_DeleteObject((SmartBox *)&v6->vfptr, v3);
      if ( v7 > 0xF745 )
      {
        if ( v7 == 63302 )
          return CM_Physics::DispatchSB_CreatePlayer((SmartBox *)&v6->vfptr, v3);
        return 3;
      }
      if ( v7 == 63301 )
        return CM_Physics::DispatchSB_CreateObject(a2, (SmartBox *)&v6->vfptr, v3);
      v9 = v7 - 63001;
      if ( v9 )
      {
        if ( v9 == 12 )
          return CM_Physics::DispatchSB_ObjDescEvent((SmartBox *)&v6->vfptr, v3);
        return 3;
      }
      v11 = *(_DWORD *)v8;
      blob = (NetBlob *)(v8 + 4);
      v12 = SmartBox::UnpackPositionEvent((SmartBox *)&v6->vfptr, a2, v11, (void **)&blob, v4);
      v13 = v12;
      if ( v12 != 4 )
      {
        if ( v12 == 1 )
        {
          v14 = CObjectMaint::GetObjectA(v6->m_pObjMaint, v11);
          v15 = v6->physics;
          if ( CPhysics::SetObjectMovement((CPhysicsObj *)v14, blob, size) )
          {
            ((void (*)(void))v6->cmdinterp->vfptr[8].OnAction)();
            return 1;
          }
        }
        return v13;
      }
    }
    SmartBox::QueueBlobForObject((SmartBox *)&v6->vfptr, v11, v3);
    return v13;
  }
  switch ( v7 )
  {
    case 0xF754u:
      result = CM_Physics::DispatchSB_PlayScriptID((SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF755u:
      result = CM_Physics::DispatchSB_PlayScriptType((SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF751u:
      result = CM_Physics::DispatchSB_PlayerTeleport((SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF750u:
      result = CM_Physics::DispatchSB_SoundEvent((SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF7DBu:
      result = CM_Physics::DispatchSB_UpdateObject(a2, (SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF74Eu:
      result = CM_Physics::DispatchSB_VectorUpdate((SmartBox *)&v6->vfptr, v3);
      break;
    case 0xF74Cu:
      v18 = *(_DWORD *)v8;
      v19 = v6->m_pObjMaint;
      blob = (NetBlob *)(v8 + 4);
      v20 = CObjectMaint::GetObjectA(v19, v18);
      v21 = LOWORD(blob->vfptr);
      blob = (NetBlob *)((char *)blob + 2);
      instance_timestamp = v21;
      if ( !v20 || CPhysicsObj::is_newer(LOWORD(v20[31].vfptr), v21) )
      {
        SmartBox::QueueBlobForObject((SmartBox *)&v6->vfptr, v18, v3);
        result = 4;
      }
      else if ( LOWORD(v20[31].vfptr) == instance_timestamp )
      {
        v22 = v6->physics;
        if ( CPhysics::SetObjectMovement((CPhysicsObj *)v20, blob, size) )
          ((void (*)(void))v6->cmdinterp->vfptr[8].OnAction)();
        result = 1;
      }
      else
      {
        result = 2;
      }
      break;
    default:
      return 3;
  }
  return result;
}

//----- (005599D0) --------------------------------------------------------  // acclient.c:392842
ACSmartBox *__thiscall SmartBox::scalar_deleting_destructor(ACSmartBox *this, unsigned int a2)
{
  ACSmartBox *v2; // esi@1

  v2 = this;
  SmartBox::~SmartBox((SmartBox *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00707D60) --------------------------------------------------------  // acclient.c:795066
void sub_707D60()
{
  flt_86FFD4 = 1000.0 + 1.0;
}

//----- (00707D80) --------------------------------------------------------  // acclient.c:795072
void sub_707D80()
{
  flt_86FFD8 = 24.0 * 8.0;
}

//----- (00707DA0) --------------------------------------------------------  // acclient.c:795078
void sub_707DA0()
{
  flt_86FFDC = 24.0 * 0.5;
}

//----- (00707DC0) --------------------------------------------------------  // acclient.c:795084
void sub_707DC0()
{
  flt_86FFE4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00707DE0) --------------------------------------------------------  // acclient.c:795090
void _E99_38()
{
  dbl_86FFE8 = 1.0 / 30.0;
}

//----- (00707E00) --------------------------------------------------------  // acclient.c:795096
void _E101_37()
{
  dbl_86FFF0 = 1.0 / 5.0;
}

//----- (00707E20) --------------------------------------------------------  // acclient.c:795102
void sub_707E20()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86FFF8, PFID_A8R8G8B8);
}

//----- (00707E30) --------------------------------------------------------  // acclient.c:795108
void _E105_48()
{
  dword_870030 = 1024;
}

//----- (00707E40) --------------------------------------------------------  // acclient.c:795114
void _E107_37()
{
  dword_870034 = 0x7FFF;
}

//----- (00707E50) --------------------------------------------------------  // acclient.c:795120
int _E109_72()
{
  const int result; // eax@1

  result = dword_870030;
  dword_870038 = dword_870030;
  return result;
}

//----- (00707E60) --------------------------------------------------------  // acclient.c:795130
int sub_707E60()
{
  return atexit(nullsub_1299);
}

