/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UILocationData
   Object     : ENGINE\engine_shared_gameplay\UILocationData.obj
   Functions  : 2
   Addresses  : 00678110 - 00678170 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00678110) --------------------------------------------------------  // acclient.c:654752
int __thiscall PFileNode::MakeSubNodeAsBool(PFileNode *this, bool i_name)
{
  int result; // eax@1
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@2
  void *v5; // eax@4

  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = (PFileNode *)result;
  if ( result )
  {
    v4 = *(IFileNodeName **)(result + 8);
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_pcName = 0;
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = &FileNodeName_Bool::vftable;
      *((_BYTE *)v5 + 4) = i_name;
      v3->m_pcName = (IFileNodeName *)v5;
      result = (int)v3;
    }
    else
    {
      v3->m_pcName = 0;
      result = (int)v3;
    }
  }
  return result;
}
// 796010: using guessed type int (__thiscall *FileNodeName_Bool::vftable)(void *, char);

//----- (00678170) --------------------------------------------------------  // acclient.c:654786
void __thiscall UILocationData::UILocationData(UILocationData *this)
{
  LODWORD(this->m_x0) = -1069547520;
  LODWORD(this->m_y0) = -1069547520;
  LODWORD(this->m_x1) = -1069547520;
  LODWORD(this->m_y1) = -1069547520;
  this->m_shown = 1;
}

