/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorRegistryNode
   Object     : AC\acgenerator\GeneratorRegistryNode.obj
   Functions  : 5
   Addresses  : 005D0B90 - 00710400 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D0B90) --------------------------------------------------------  // acclient.c:508675
void __thiscall GeneratorRegistryNode::GeneratorRegistryNode(GeneratorRegistryNode *this)
{
  this->vfptr = (PackObjVtbl *)&GeneratorRegistryNode::vftable;
  this->m_wcidOrTtype.id = stru_8EFF9C.id;
  *(_QWORD *)&this->ts = 0i64;
  this->m_bTreasureType = 0;
  this->slot = 0;
  this->checkpointed = 0;
  this->shop = 0;
  this->amount = 0;
}
// 7E87E0: using guessed type int (__thiscall *GeneratorRegistryNode::vftable)(void *, char);

//----- (005D0BC0) --------------------------------------------------------  // acclient.c:508689
void __thiscall GeneratorRegistryNode::GeneratorRegistryNode(GeneratorRegistryNode *this, GeneratorRegistryNode *rhs)
{
  this->vfptr = (PackObjVtbl *)&GeneratorRegistryNode::vftable;
  if ( this != rhs )
  {
    this->m_wcidOrTtype.id = rhs->m_wcidOrTtype.id;
    this->ts = rhs->ts;
    this->m_bTreasureType = rhs->m_bTreasureType;
    this->slot = rhs->slot;
    this->checkpointed = rhs->checkpointed;
    this->shop = rhs->shop;
    this->amount = rhs->amount;
  }
}
// 7E87E0: using guessed type int (__thiscall *GeneratorRegistryNode::vftable)(void *, char);

//----- (005D0C10) --------------------------------------------------------  // acclient.c:508706
signed int __thiscall GeneratorRegistryNode::Pack(GeneratorRegistryNode *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2
  char *v5; // esi@2
  char *v6; // edx@2
  char *v7; // esi@2
  char *v8; // edx@2

  if ( size >= 0x20 )
  {
    *(_DWORD *)*addr = this->m_wcidOrTtype.id;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(double *)v3 = this->ts;
    v4 = (char *)*addr + 8;
    *addr = v4;
    *(_DWORD *)v4 = this->m_bTreasureType;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->slot;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->checkpointed;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->shop;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = this->amount;
    *addr = (char *)*addr + 4;
  }
  return 32;
}

//----- (005D0C80) --------------------------------------------------------  // acclient.c:508742
int __thiscall GeneratorRegistryNode::UnPack(GeneratorRegistryNode *this, void **addr, unsigned int size)
{
  int result; // eax@2
  unsigned int v4; // esi@3
  void *v5; // edx@3
  char *v6; // edx@3
  char *v7; // esi@3
  char *v8; // edx@3
  char *v9; // esi@3
  char *v10; // edx@3

  if ( size >= 0x20 )
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    this->m_wcidOrTtype.id = v4;
    v5 = *addr;
    LODWORD(this->ts) = *(_DWORD *)*addr;
    HIDWORD(this->ts) = *((_DWORD *)v5 + 1);
    v6 = (char *)*addr + 8;
    *addr = v6;
    this->m_bTreasureType = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->slot = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->checkpointed = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    this->shop = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    this->amount = *(_DWORD *)v10;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00710400) --------------------------------------------------------  // acclient.c:803519
int sub_710400()
{
  return atexit(nullsub_1841);
}

