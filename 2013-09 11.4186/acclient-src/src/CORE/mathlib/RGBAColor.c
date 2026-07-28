/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RGBAColor
   Object     : CORE\mathlib\RGBAColor.obj
   Functions  : 4
   Addresses  : 0065B360 - 0065B4E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065B360) --------------------------------------------------------  // acclient.c:625087
bool __thiscall RGBAColor::IsValid(RGBAColor *this)
{
  return this->a >= -0.00019999999
      && this->r >= -0.00019999999
      && this->g >= -0.00019999999
      && this->b >= -0.00019999999
      && this->a <= 1.0002
      && this->r <= 1.0002
      && this->g <= 1.0002
      && this->b <= 1.0002;
}

//----- (0065B3F0) --------------------------------------------------------  // acclient.c:625100
void __thiscall RGBAColor::Serialize(RGBAColor *this, Archive *io_archive)
{
  RGBAColor *v2; // edi@1
  const unsigned int v3; // ebp@2
  unsigned int v4; // eax@4

  v2 = this;
  if ( io_archive->m_flags & 1 )
    v3 = RGBAColor::MakeRGBA(this->r, this->g, this->b, this->a);
  else
    v3 = (const unsigned int)io_archive;
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    if ( !((io_archive->m_flags >> 2) & 1) )
      RGBAColor::SetColor32(v2, v3);
  }
}

//----- (0065B470) --------------------------------------------------------  // acclient.c:625128
bool __thiscall RGBAColor::ToFileNode(RGBAColor *this, PFileNode *node)
{
  RGBAColor *v2; // esi@1
  bool result; // al@5

  v2 = this;
  if ( node
    && PFileNode::MakeSubNodeAsFloat(node, this->r)
    && PFileNode::MakeSubNodeAsFloat(node, v2->g)
    && PFileNode::MakeSubNodeAsFloat(node, v2->b) )
    result = PFileNode::MakeSubNodeAsFloat(node, v2->a) != 0;
  else
    result = 0;
  return result;
}

//----- (0065B4E0) --------------------------------------------------------  // acclient.c:625145
char __thiscall RGBAColor::FromFileNode(RGBAColor *this, PFileNode *node, bool read_as_float, bool read_alpha)
{
  int v4; // edi@1
  bool v5; // bl@2
  unsigned int v6; // eax@2
  unsigned int v7; // ecx@2
  PFileNode *v9; // eax@10
  unsigned int v10; // ecx@10
  char v11; // al@14
  PFileNode *v12; // eax@22
  unsigned int v13; // ecx@22
  char v14; // al@23
  PFileNode *v15; // eax@26
  bool v16; // al@28
  PFileNode *v17; // eax@31
  bool v18; // al@33
  unsigned int v19; // ecx@44
  unsigned int v20; // [sp-4h] [bp-10h]@4

  v4 = (int)this;
  if ( !node )
    return 0;
  v5 = read_alpha;
  v6 = PFileNode::GetNumSubNodes(node);
  if ( v5 )
  {
    if ( v6 != 4 )
    {
      v20 = v7;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "alpha color needs 4 arguments");
LABEL_5:
      PFileNode::ReportError(v4, node, (PStringBase<char>)v20);
      return 0;
    }
  }
  else if ( v6 != 3 )
  {
    v20 = v7;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "non-alpha color needs 3 arguments");
    goto LABEL_5;
  }
  v20 = 0;
  if ( read_as_float )
  {
    v9 = (PFileNode *)node->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)node, v20);
    v11 = v9
       && PFileNode::GetNameAsFloat(v9, v4, (float *)v4)
       && PFileNode::GetSubName(node, v4, 1u, (float *)(v4 + 4))
       && PFileNode::GetSubName(node, v4, 2u, (float *)(v4 + 8));
    if ( v5 )
    {
      if ( !v11 )
      {
LABEL_21:
        v20 = v10;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "read failed for color");
        goto LABEL_5;
      }
      v11 = PFileNode::GetSubName(node, v4, 3u, (float *)(v4 + 12));
    }
    else
    {
      *(_DWORD *)(v4 + 12) = 1065353216;
    }
    if ( !v11 )
      goto LABEL_21;
  }
  else
  {
    v12 = (PFileNode *)node->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)node, v20);
    if ( v12 )
      v14 = PFileNode::GetNameAsUInt32(v12, v4, (unsigned int *)&read_alpha);
    else
      v14 = 0;
    *(float *)v4 = (double)read_alpha * 0.0039215689;
    v16 = 0;
    if ( v14 )
    {
      v15 = (PFileNode *)node->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)node, 1u);
      if ( v15 )
      {
        if ( PFileNode::GetNameAsUInt32(v15, v4, (unsigned int *)&read_alpha) )
          v16 = 1;
      }
    }
    *(float *)(v4 + 4) = (double)read_alpha * 0.0039215689;
    v18 = 0;
    if ( v16 )
    {
      v17 = (PFileNode *)node->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)node, 2u);
      if ( v17 )
      {
        if ( PFileNode::GetNameAsUInt32(v17, v4, (unsigned int *)&read_alpha) )
          v18 = 1;
      }
    }
    *(float *)(v4 + 8) = (double)read_alpha * 0.0039215689;
    if ( v5 )
    {
      v18 = v18 && PFileNode::GetSubName(node, v4, 3u, (unsigned int *)&read_alpha);
      v13 = read_alpha;
      *(float *)(v4 + 12) = (double)read_alpha * 0.0039215689;
    }
    else
    {
      *(_DWORD *)(v4 + 12) = 1065353216;
    }
    if ( !v18 )
    {
      v20 = v13;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "reading as integers failed for color");
      goto LABEL_5;
    }
  }
  if ( !RGBAColor::IsValid((RGBAColor *)v4) )
  {
    v20 = v19;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, "Not a valid color");
    goto LABEL_5;
  }
  return 1;
}

