/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GenItems
   Object     : PORTAL\ui_misc\GenItems.obj
   Functions  : 1
   Addresses  : 004FC550 - 004FC550 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004FC550) --------------------------------------------------------  // acclient.c:296227
void __cdecl GenItemHolder::ServerSaysMoveItem_s(unsigned int _itemID, unsigned int _oldContainer, unsigned int _oldWielder, unsigned int _oldLocation, unsigned int _newContainer, int _place, unsigned int _newWielder, unsigned int _newLocation)
{
  ECM_Item::SendNotice_ServerSaysMoveItem(
    _itemID,
    _oldContainer,
    _oldWielder,
    _oldLocation,
    _newContainer,
    _place,
    _newWielder,
    _newLocation);
  if ( _oldContainer )
    ECM_Item::SendNotice_ItemAttributesChanged(_oldContainer, 0);
  if ( _newContainer )
    ECM_Item::SendNotice_ItemAttributesChanged(_newContainer, 0);
}

