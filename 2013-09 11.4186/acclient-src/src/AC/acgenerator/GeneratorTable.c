/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorTable
   Object     : AC\acgenerator\GeneratorTable.obj
   Functions  : 14
   Addresses  : 005D0090 - 007102A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D0090) --------------------------------------------------------  // acclient.c:507850
void __thiscall PackableLLNode<GeneratorProfile>::PackableLLNode<GeneratorProfile>(PackableLLNode<GeneratorProfile> *this, GeneratorProfile *_data)
{
  int v2; // esi@1
  char *v3; // ecx@1

  v2 = (int)this;
  this->data.vfptr = (PackObjVtbl *)&GeneratorProfile::vftable;
  v3 = (char *)&this->data.pos_val.frame;
  *(_DWORD *)(v2 + 52) = &Position::vftable;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)v3 = 1065353216;
  *((_DWORD *)v3 + 1) = 0;
  *((_DWORD *)v3 + 2) = 0;
  *((_DWORD *)v3 + 3) = 0;
  *((_DWORD *)v3 + 13) = 0;
  *((_DWORD *)v3 + 14) = 0;
  *((_DWORD *)v3 + 15) = 0;
  Frame::cache((Frame *)v3);
  GeneratorProfile::operator=(v2, (int)_data);
  *(_DWORD *)(v2 + 128) = 0;
  *(_DWORD *)(v2 + 132) = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E86AC: using guessed type int (__thiscall *GeneratorProfile::vftable)(void *, char);

//----- (005D00F0) --------------------------------------------------------  // acclient.c:507876
GeneratorProfile *__thiscall GeneratorProfile::vector_deleting_destructor(GeneratorProfile *this, unsigned int a2)
{
  GeneratorProfile *v2; // esi@1

  v2 = this;
  this->pos_val.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005D0120) --------------------------------------------------------  // acclient.c:507890
int __thiscall PackableList<GeneratorProfile>::InsertTail(PackableList<GeneratorProfile> *this, GeneratorProfile *val)
{
  PackableList<GeneratorProfile> *v2; // esi@1
  PackableLLNode<GeneratorProfile> *v3; // eax@1
  int v4; // eax@2
  int result; // eax@5
  PackableLLNode<GeneratorProfile> *v6; // ecx@6

  v2 = this;
  v3 = (PackableLLNode<GeneratorProfile> *)operator new(0x88u);
  if ( v3 )
    PackableLLNode<GeneratorProfile>::PackableLLNode<GeneratorProfile>(v3, val);
  else
    v4 = 0;
  if ( v2->head )
  {
    v6 = v2->tail;
    v6->next = (PackableLLNode<GeneratorProfile> *)v4;
    *(_DWORD *)(v4 + 132) = v6;
    v2->tail = (PackableLLNode<GeneratorProfile> *)v4;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  else
  {
    v2->head = (PackableLLNode<GeneratorProfile> *)v4;
    v2->tail = (PackableLLNode<GeneratorProfile> *)v4;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  return result;
}

//----- (005D0180) --------------------------------------------------------  // acclient.c:507924
signed int __thiscall PackableList<GeneratorProfile>::Pack(PackableList<GeneratorProfile> *this, void **addr, unsigned int size)
{
  PackableList<GeneratorProfile> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<GeneratorProfile> *i; // esi@4

  v3 = this;
  v4 = PackableList<GeneratorProfile>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<GeneratorProfile> *, void **, unsigned int))i->data.vfptr->Pack)(
        i,
        addr,
        size);
  }
  return v4;
}

//----- (005D01D0) --------------------------------------------------------  // acclient.c:507949
signed int __thiscall PackableList<GeneratorProfile>::pack_size(PackableList<GeneratorProfile> *this)
{
  PackableLLNode<GeneratorProfile> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<GeneratorProfile> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (005D0210) --------------------------------------------------------  // acclient.c:507968
void __thiscall PackableList<GeneratorProfile>::Flush(PackableList<GeneratorProfile> *this)
{
  PackableList<GeneratorProfile> *v1; // edi@1
  int v2; // esi@2
  int v3; // eax@3
  GeneratorProfile dummyData; // [sp+8h] [bp-80h]@1

  v1 = this;
  GeneratorProfile::GeneratorProfile(&dummyData);
  while ( v1->head )
  {
    v2 = (int)v1->head;
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 128);
      v1->head = (PackableLLNode<GeneratorProfile> *)v3;
      if ( v3 )
        *(_DWORD *)(v3 + 132) = 0;
      else
        v1->tail = 0;
      GeneratorProfile::operator=((int)&dummyData, v2);
      if ( v2 )
      {
        *(_DWORD *)(v2 + 52) = &PackObj::vftable;
        *(_DWORD *)v2 = &PackObj::vftable;
        operator delete((void *)v2);
      }
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005D0290) --------------------------------------------------------  // acclient.c:508002
int __thiscall PackableList<GeneratorProfile>::UnPack(PackableList<GeneratorProfile> *this, void **addr, unsigned int size)
{
  PackableList<GeneratorProfile> *v3; // ebp@1
  int v4; // edi@2
  int v5; // esi@2
  int result; // eax@5
  GeneratorProfile temp; // [sp+8h] [bp-80h]@2

  v3 = this;
  PackableList<GeneratorProfile>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    GeneratorProfile::GeneratorProfile(&temp);
    v5 = 0;
    if ( v4 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(GeneratorProfile *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<GeneratorProfile>::InsertTail(v3, &temp);
        ++v5;
        if ( v5 >= v4 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}

//----- (005D0330) --------------------------------------------------------  // acclient.c:508043
PackableList<GeneratorProfile> *__thiscall PackableList<GeneratorProfile>::scalar_deleting_destructor(PackableList<GeneratorProfile> *this, unsigned int a2)
{
  PackableList<GeneratorProfile> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<GeneratorProfile>::vftable;
  PackableList<GeneratorProfile>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E86C0: using guessed type int (__thiscall *PackableList<GeneratorProfile>::vftable)(void *, char);

//----- (005D0360) --------------------------------------------------------  // acclient.c:508059
void __thiscall GeneratorTable::GeneratorTable(GeneratorTable *this)
{
  this->vfptr = (PackObjVtbl *)&GeneratorTable::vftable;
  this->_profile_list.vfptr = (PackObjVtbl *)&PackableList<GeneratorProfile>::vftable;
  this->_profile_list.head = 0;
  this->_profile_list.tail = 0;
  this->_profile_list.curNum = 0;
}
// 7E86C0: using guessed type int (__thiscall *PackableList<GeneratorProfile>::vftable)(void *, char);
// 7E86D4: using guessed type int (__thiscall *GeneratorTable::vftable)(void *, char);

//----- (005D0380) --------------------------------------------------------  // acclient.c:508071
GeneratorTable *__thiscall GeneratorTable::vector_deleting_destructor(GeneratorTable *this, unsigned int a2)
{
  GeneratorTable *v2; // esi@1
  char *v3; // edi@1

  v2 = this;
  v3 = (char *)&this->_profile_list;
  this->vfptr = (PackObjVtbl *)&GeneratorTable::vftable;
  this->_profile_list.vfptr = (PackObjVtbl *)&PackableList<GeneratorProfile>::vftable;
  PackableList<GeneratorProfile>::Flush(&this->_profile_list);
  *(_DWORD *)v3 = &PackObj::vftable;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E86C0: using guessed type int (__thiscall *PackableList<GeneratorProfile>::vftable)(void *, char);
// 7E86D4: using guessed type int (__thiscall *GeneratorTable::vftable)(void *, char);

//----- (00710240) --------------------------------------------------------  // acclient.c:803423
void sub_710240()
{
  flt_8EFF2C = 1000.0 + 1.0;
}

//----- (00710260) --------------------------------------------------------  // acclient.c:803429
void sub_710260()
{
  flt_8EFF30 = 24.0 * 8.0;
}

//----- (00710280) --------------------------------------------------------  // acclient.c:803435
void sub_710280()
{
  flt_8EFF34 = 24.0 * 0.5;
}

//----- (007102A0) --------------------------------------------------------  // acclient.c:803441
int sub_7102A0()
{
  return atexit(nullsub_1838);
}

