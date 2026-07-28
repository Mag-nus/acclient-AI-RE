/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClipPlaneList
   Object     : PORTAL\cgeometry\ClipPlaneList.obj
   Functions  : 3
   Addresses  : 0053B990 - 0053BA00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053B990) --------------------------------------------------------  // acclient.c:362277
void __thiscall DArray<ClipPlane>::~DArray<ClipPlane>(DArray<ClipPlane> *this)
{
  DArray<ClipPlane> *v1; // ebp@1
  ClipPlane *v2; // ecx@1
  Sidedness v3; // eax@2
  void *v4; // ebx@2
  DiskSpace *v5; // esi@2
  int v6; // eax@2
  int v7; // edi@3

  v1 = this;
  v2 = this->data;
  if ( v2 )
  {
    v3 = v2[-1].side;
    v4 = &v2[-1].side;
    v5 = (DiskSpace *)&v2[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        v5 -= 8;
        gmNoticeHandler::RecvNotice_PrevSpellSelection(v5);
        --v7;
      }
      while ( v7 );
    }
    operator delete[](v4);
  }
  v1->data = 0;
}

//----- (0053B9E0) --------------------------------------------------------  // acclient.c:362312
void __thiscall ClipPlaneList::ClipPlaneList(ClipPlaneList *this)
{
  this->cplane_num = 0;
  this->cplane_list.data = 0;
  this->cplane_list.sizeOf = 0;
  this->cplane_list.next_available = 0;
  this->cplane_list.blocksize = 128;
  this->leaf_contains_obj = 0;
}

//----- (0053BA00) --------------------------------------------------------  // acclient.c:362323
void __thiscall ClipPlaneList::~ClipPlaneList(ClipPlaneList *this)
{
  DArray<ClipPlane>::~DArray<ClipPlane>(&this->cplane_list);
}

