/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PortalEvent
   Object     : CORE\newthread\PortalEvent.obj
   Functions  : 4
   Addresses  : 0065DAE0 - 0065DB30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065DAE0) --------------------------------------------------------  // acclient.c:627483
void __thiscall PortalEvent::PortalEvent(PortalEvent *this)
{
  this->eventHandle_ = 0;
  this->eventHandle_ = CreateEventA(0, 0, 0, 0);
}

//----- (0065DB00) --------------------------------------------------------  // acclient.c:627490
void __thiscall PortalEvent::~PortalEvent(PortalEvent *this)
{
  PortalEvent *v1; // esi@1

  v1 = this;
  if ( this->eventHandle_ )
  {
    CloseHandle(this->eventHandle_);
    v1->eventHandle_ = 0;
  }
}

//----- (0065DB20) --------------------------------------------------------  // acclient.c:627503
bool __thiscall PortalEvent::Signal(PortalEvent *this)
{
  return SetEvent(this->eventHandle_) != 0;
}

//----- (0065DB30) --------------------------------------------------------  // acclient.c:627509
bool __thiscall PortalEvent::WaitForSignal(PortalEvent *this, unsigned int milliseconds)
{
  return WaitForSingleObject(this->eventHandle_, milliseconds) == 0;
}

