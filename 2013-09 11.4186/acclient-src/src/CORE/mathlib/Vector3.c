/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Vector3
   Object     : CORE\mathlib\Vector3.obj
   Functions  : 2
   Addresses  : 0065B6E0 - 0065B750 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065B6E0) --------------------------------------------------------  // acclient.c:625269
bool __thiscall Vector3::ToFileNode(Vector3 *this, PFileNode *_pNode)
{
  Vector3 *v2; // esi@1
  bool result; // al@5

  v2 = this;
  if ( _pNode
    && (unsigned __int8)Vector3Math::IsValid(this)
    && PFileNode::MakeSubNodeAsFloat(_pNode, v2->x)
    && PFileNode::MakeSubNodeAsFloat(_pNode, v2->y) )
    result = PFileNode::MakeSubNodeAsFloat(_pNode, v2->z) != 0;
  else
    result = 0;
  return result;
}

//----- (0065B750) --------------------------------------------------------  // acclient.c:625286
bool __thiscall Vector3::FromFileNode(Vector3 *this, PFileNode *_pNode)
{
  int v2; // edi@1
  PSRefBufferCharData<char> *v3; // ecx@2
  PFileNode *v4; // eax@4
  PSRefBufferCharData<char> *v5; // ecx@4
  PFileNode *v6; // eax@5
  PFileNode *v7; // eax@6
  PStringBase<char> v9; // [sp-4h] [bp-Ch]@3

  v2 = (int)this;
  if ( _pNode )
  {
    if ( PFileNode::GetNumSubNodes(_pNode) == 3 )
    {
      v4 = (PFileNode *)_pNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_pNode, 0);
      if ( PFileNode::GetNameAsFloat(v4, v2, (float *)v2) )
      {
        v6 = (PFileNode *)_pNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_pNode, 1u);
        if ( PFileNode::GetNameAsFloat(v6, v2, (float *)(v2 + 4)) )
        {
          v7 = (PFileNode *)_pNode->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_pNode, 2u);
          if ( PFileNode::GetNameAsFloat(v7, v2, (float *)(v2 + 8)) )
            return (unsigned __int8)Vector3Math::IsValid((Vector3 *)v2) != 0;
        }
      }
      v9.m_charbuffer = v5;
      PStringBase<char>::PStringBase<char>(&v9, "Invalid vector");
    }
    else
    {
      v9.m_charbuffer = v3;
      PStringBase<char>::PStringBase<char>(&v9, "Invalid number of components in vector");
    }
    PFileNode::ReportError(v2, _pNode, v9);
  }
  return 0;
}

