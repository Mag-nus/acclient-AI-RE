/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TurbineChatBlob
   Object     : AC\turbinechat\TurbineChatBlob.obj
   Functions  : 3
   Addresses  : 00502730 - 005CD9E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502730) --------------------------------------------------------  // acclient.c:303548
void __thiscall CSceneDesc::CSceneDesc(TurbineChatBlob *this)
{
  this->m_targetID = 0;
  this->m_hResult = 0;
  this->m_ChatType = 0;
}

//----- (0051BBC0) --------------------------------------------------------  // acclient.c:329766
void __thiscall TurbineChatBlob::SetTargetID(TurbineChatBlob *this, unsigned int targetID)
{
  this->m_targetID = targetID;
}

//----- (005CD9E0) --------------------------------------------------------  // acclient.c:505761
int __thiscall TurbineChatBlob::GetBlob(TurbineChatBlob *this, int a2)
{
  int result; // eax@1

  result = a2;
  *(_DWORD *)a2 = 12;
  *(_DWORD *)(a2 + 4) = this;
  return result;
}

