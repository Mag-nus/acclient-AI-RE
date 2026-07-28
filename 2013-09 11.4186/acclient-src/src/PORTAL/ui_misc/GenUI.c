/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GenUI
   Object     : PORTAL\ui_misc\GenUI.obj
   Functions  : 4
   Addresses  : 004FC5B0 - 006F9450 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FC5B0) --------------------------------------------------------  // acclient.c:296245
void __thiscall IQueuedUIEventDeliverer::~IQueuedUIEventDeliverer(IQueuedUIEventDeliverer *this)
{
  this->vfptr = (InterfaceVtbl *)&IQueuedUIEventDeliverer::vftable;
}
// 7C5D84: using guessed type __int32 (__stdcall *IQueuedUIEventDeliverer::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004FC5C0) --------------------------------------------------------  // acclient.c:296252
void IQueuedUIEventDeliverer::OnShutdown()
{
  IQueuedUIEventDeliverer::s_pInstance = 0;
}

//----- (004FC5D0) --------------------------------------------------------  // acclient.c:296258
void __thiscall IQueuedUIEventDeliverer::IQueuedUIEventDeliverer(IQueuedUIEventDeliverer *this)
{
  this->vfptr = (InterfaceVtbl *)&IQueuedUIEventDeliverer::vftable;
  IQueuedUIEventDeliverer::s_pInstance = (UIQueueManager *)this;
}
// 7C5D84: using guessed type __int32 (__stdcall *IQueuedUIEventDeliverer::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006F9450) --------------------------------------------------------  // acclient.c:781993
int _E77_0()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE;
  INITIAL_MAX_DATA_RATE_61 = LOWEST_DATA_RATE;
  return result;
}

