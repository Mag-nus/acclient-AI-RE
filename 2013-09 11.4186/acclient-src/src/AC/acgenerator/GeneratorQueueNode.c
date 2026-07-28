/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorQueueNode
   Object     : AC\acgenerator\GeneratorQueueNode.obj
   Functions  : 5
   Addresses  : 005B6490 - 005D0D80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B6490) --------------------------------------------------------  // acclient.c:481092
int __thiscall GeneratorQueueNode::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  }
  return result;
}

//----- (005D0D00) --------------------------------------------------------  // acclient.c:508787
void __thiscall GeneratorQueueNode::GeneratorQueueNode(GeneratorQueueNode *this)
{
  this->vfptr = (PackObjVtbl *)&GeneratorQueueNode::vftable;
  this->slot = 0;
  *(_QWORD *)&this->when = 0i64;
}
// 7E87F4: using guessed type int (__thiscall *GeneratorQueueNode::vftable)(void *, char);

//----- (005D0D20) --------------------------------------------------------  // acclient.c:508796
void __thiscall GeneratorQueueNode::GeneratorQueueNode(GeneratorQueueNode *this, GeneratorQueueNode *rhs)
{
  this->vfptr = (PackObjVtbl *)&GeneratorQueueNode::vftable;
  if ( this != rhs )
  {
    this->slot = rhs->slot;
    this->when = rhs->when;
  }
}
// 7E87F4: using guessed type int (__thiscall *GeneratorQueueNode::vftable)(void *, char);

//----- (005D0D50) --------------------------------------------------------  // acclient.c:508808
signed int __thiscall GeneratorQueueNode::Pack(GeneratorQueueNode *this, void **addr, unsigned int size)
{
  char *v3; // edx@2

  if ( size >= 0xC )
  {
    *(_DWORD *)*addr = this->slot;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(double *)v3 = this->when;
    *addr = (char *)*addr + 8;
  }
  return 12;
}

//----- (005D0D80) --------------------------------------------------------  // acclient.c:508824
int __thiscall GeneratorQueueNode::UnPack(GeneratorQueueNode *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // edx@3

  if ( size >= 0xC )
  {
    this->slot = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_QWORD *)&this->when = *(_QWORD *)v4;
    *addr = (char *)*addr + 8;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

