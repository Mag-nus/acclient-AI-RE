/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorQueue
   Object     : AC\acgenerator\GeneratorQueue.obj
   Functions  : 13
   Addresses  : 004C0910 - 00710380 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004C0910) --------------------------------------------------------  // acclient.c:242996
signed int __thiscall PackableList<InventoryPlacement>::Pack(PackableList<GeneratorQueueNode> *this, void **addr, unsigned int size)
{
  PackableList<GeneratorQueueNode> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<GeneratorQueueNode> *i; // esi@4

  v3 = this;
  v4 = PackableList<InventoryPlacement>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<GeneratorQueueNode> *, void **, unsigned int))i->data.vfptr->Pack)(
        i,
        addr,
        size);
  }
  return v4;
}

//----- (004C0960) --------------------------------------------------------  // acclient.c:243021
signed int __thiscall PackableList<InventoryPlacement>::pack_size(PackableList<GeneratorQueueNode> *this)
{
  PackableLLNode<GeneratorQueueNode> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<GeneratorQueueNode> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (005D06C0) --------------------------------------------------------  // acclient.c:508307
int __thiscall GeneratorQueue::UnPack(GeneratorQueue *this, void **addr, unsigned int size)
{
  PackObjVtbl *v3; // eax@1
  char *v4; // esi@1
  int result; // eax@2
  GeneratorQueue *v6; // [sp+0h] [bp-4h]@1

  v6 = this;
  v3 = this->_queue.vfptr;
  v4 = (char *)&this->_queue;
  v6 = 0;
  if ( size >= ((int (__thiscall *)(PackableList<GeneratorQueueNode> *, int *, _DWORD))v3->Pack)(&this->_queue, &v6, 0) )
    result = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 16))(v4, addr, size);
  else
    result = 0;
  return result;
}

//----- (005D0700) --------------------------------------------------------  // acclient.c:508326
int __thiscall PackableList<GeneratorQueueNode>::InsertTail(PackableList<GeneratorQueueNode> *this, GeneratorQueueNode *val)
{
  PackableList<GeneratorQueueNode> *v2; // esi@1
  void *v3; // edi@1
  unsigned int v4; // eax@5
  int result; // eax@5
  PackableLLNode<GeneratorQueueNode> *v6; // eax@6
  unsigned int v7; // eax@6

  v2 = this;
  v3 = operator new(0x18u);
  if ( v3 )
  {
    GeneratorQueueNode::GeneratorQueueNode((GeneratorQueueNode *)v3, val);
    *((_DWORD *)v3 + 4) = 0;
    *((_DWORD *)v3 + 5) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<GeneratorQueueNode> *)v3;
    *((_DWORD *)v3 + 5) = v6;
    v7 = v2->curNum;
    v2->tail = (PackableLLNode<GeneratorQueueNode> *)v3;
    result = v7 + 1;
    v2->curNum = result;
  }
  else
  {
    v4 = v2->curNum;
    v2->head = (PackableLLNode<GeneratorQueueNode> *)v3;
    v2->tail = (PackableLLNode<GeneratorQueueNode> *)v3;
    result = v4 + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (005D0770) --------------------------------------------------------  // acclient.c:508369
void __thiscall PackableList<GeneratorQueueNode>::Flush(PackableList<GeneratorQueueNode> *this)
{
  PackableList<GeneratorQueueNode> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  GeneratorQueueNode dummyData; // [sp+8h] [bp-10h]@1

  v1 = this;
  GeneratorQueueNode::GeneratorQueueNode(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 16);
      v1->head = (PackableLLNode<GeneratorQueueNode> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 20) = 0;
      else
        v1->tail = 0;
      GeneratorQueueNode::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        *(_DWORD *)v2 = &PackObj::vftable;
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005D07E0) --------------------------------------------------------  // acclient.c:508402
int __thiscall PackableList<GeneratorQueueNode>::UnPack(PackableList<GeneratorQueueNode> *this, void **addr, unsigned int size)
{
  PackableList<GeneratorQueueNode> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  GeneratorQueueNode temp; // [sp+8h] [bp-10h]@2

  v3 = this;
  PackableList<GeneratorQueueNode>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    GeneratorQueueNode::GeneratorQueueNode(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(GeneratorQueueNode *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<GeneratorQueueNode>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}

//----- (005D0860) --------------------------------------------------------  // acclient.c:508443
PackableList<GeneratorQueueNode> *__thiscall PackableList<GeneratorQueueNode>::vector_deleting_destructor(PackableList<GeneratorQueueNode> *this, unsigned int a2)
{
  PackableList<GeneratorQueueNode> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<GeneratorQueueNode>::vftable;
  PackableList<GeneratorQueueNode>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8780: using guessed type int (__thiscall *PackableList<GeneratorQueueNode>::vftable)(void *, char);

//----- (005D0890) --------------------------------------------------------  // acclient.c:508459
void __thiscall GeneratorQueue::GeneratorQueue(GeneratorQueue *this)
{
  this->vfptr = (PackObjVtbl *)&GeneratorQueue::vftable;
  this->_queue.vfptr = (PackObjVtbl *)&PackableList<GeneratorQueueNode>::vftable;
  this->_queue.head = 0;
  this->_queue.tail = 0;
  this->_queue.curNum = 0;
}
// 7E8780: using guessed type int (__thiscall *PackableList<GeneratorQueueNode>::vftable)(void *, char);
// 7E8794: using guessed type int (__thiscall *GeneratorQueue::vftable)(void *, char);

//----- (005D08B0) --------------------------------------------------------  // acclient.c:508471
GeneratorQueue *__thiscall GeneratorQueue::vector_deleting_destructor(GeneratorQueue *this, unsigned int a2)
{
  GeneratorQueue *v2; // esi@1
  char *v3; // edi@1

  v2 = this;
  v3 = (char *)&this->_queue;
  this->vfptr = (PackObjVtbl *)&GeneratorQueue::vftable;
  this->_queue.vfptr = (PackObjVtbl *)&PackableList<GeneratorQueueNode>::vftable;
  PackableList<GeneratorQueueNode>::Flush(&this->_queue);
  *(_DWORD *)v3 = &PackObj::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8780: using guessed type int (__thiscall *PackableList<GeneratorQueueNode>::vftable)(void *, char);
// 7E8794: using guessed type int (__thiscall *GeneratorQueue::vftable)(void *, char);

//----- (00710320) --------------------------------------------------------  // acclient.c:803471
void sub_710320()
{
  flt_8EFF6C = 1000.0 + 1.0;
}

//----- (00710340) --------------------------------------------------------  // acclient.c:803477
void sub_710340()
{
  flt_8EFF70 = 24.0 * 8.0;
}

//----- (00710360) --------------------------------------------------------  // acclient.c:803483
void sub_710360()
{
  flt_8EFF74 = 24.0 * 0.5;
}

//----- (00710380) --------------------------------------------------------  // acclient.c:803489
int sub_710380()
{
  return atexit(nullsub_1842);
}

