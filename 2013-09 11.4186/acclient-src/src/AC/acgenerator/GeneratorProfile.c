/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GeneratorProfile
   Object     : AC\acgenerator\GeneratorProfile.obj
   Functions  : 8
   Addresses  : 005D08F0 - 007103F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D08F0) --------------------------------------------------------  // acclient.c:508492
void __thiscall GeneratorProfile::GeneratorProfile(GeneratorProfile *this)
{
  GeneratorProfile *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&GeneratorProfile::vftable;
  LODWORD(this->probability) = 0;
  this->type.id = stru_8EFF88.id;
  LODWORD(this->delay) = 0;
  HIDWORD(this->delay) = 1082310656;
  this->whereCreate = 2;
  this->ptid = 0;
  LODWORD(this->shade) = 0;
  this->initCreate = 1;
  this->whenCreate = 1;
  v2 = (char *)&this->pos_val.frame;
  v1->maxNum = -1;
  v1->stackSize = -1;
  v1->pos_val.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->pos_val.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->slot = 0;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E86AC: using guessed type int (__thiscall *GeneratorProfile::vftable)(void *, char);

//----- (005D0970) --------------------------------------------------------  // acclient.c:508527
int __thiscall GeneratorProfile::UnPack(GeneratorProfile *this, void **addr, unsigned int size)
{
  GeneratorProfile *v3; // edi@1
  char *v4; // ebx@1
  int result; // eax@2
  char *v6; // edx@3
  char *v7; // eax@3
  char *v8; // edx@3
  char *v9; // eax@3
  char *v10; // edx@3
  char *v11; // eax@3
  char *v12; // edx@3
  char *v13; // eax@3
  char *v14; // edx@3

  v3 = this;
  v4 = (char *)&this->pos_val;
  if ( size >= Position::pack_size(&this->pos_val) + 48 )
  {
    LODWORD(v3->probability) = *(_DWORD *)*addr;
    v6 = (char *)*addr + 4;
    *addr = v6;
    v3->type.id = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    LODWORD(v3->delay) = *(_DWORD *)v7;
    HIDWORD(v3->delay) = *((_DWORD *)v7 + 1);
    v8 = (char *)*addr + 8;
    *addr = v8;
    v3->initCreate = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    v3->maxNum = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    v3->whenCreate = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    v3->whereCreate = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    v3->stackSize = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    v3->ptid = *(_DWORD *)v13;
    v14 = (char *)*addr + 4;
    *addr = v14;
    LODWORD(v3->shade) = *(_DWORD *)v14;
    *addr = (char *)*addr + 4;
    result = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 16))(v4, addr, size);
    if ( result )
    {
      v3->slot = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005D0A50) --------------------------------------------------------  // acclient.c:508592
int __thiscall GeneratorProfile::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
    Frame::operator=(this + 60, a2 + 60);
    *(_DWORD *)(v2 + 124) = *(_DWORD *)(a2 + 124);
  }
  return v2;
}

//----- (005D0AC0) --------------------------------------------------------  // acclient.c:508618
unsigned int __thiscall GeneratorProfile::Pack(GeneratorProfile *this, void **addr, unsigned int size)
{
  GeneratorProfile *v3; // edi@1
  char *v4; // ebx@1
  unsigned int v5; // ebp@1
  char *v6; // edx@2
  char *v7; // eax@2
  char *v8; // edx@2
  char *v9; // eax@2
  char *v10; // edx@2
  char *v11; // eax@2
  char *v12; // edx@2
  char *v13; // eax@2
  char *v14; // edx@2

  v3 = this;
  v4 = (char *)&this->pos_val;
  v5 = Position::pack_size(&this->pos_val) + 48;
  if ( size >= v5 )
  {
    *(float *)*addr = v3->probability;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->type.id;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(double *)v7 = v3->delay;
    v8 = (char *)*addr + 8;
    *addr = v8;
    *(_DWORD *)v8 = v3->initCreate;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->maxNum;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->whenCreate;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->whereCreate;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(_DWORD *)v12 = v3->stackSize;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(_DWORD *)v13 = v3->ptid;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(float *)v14 = v3->shade;
    *addr = (char *)*addr + 4;
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 12))(v4, addr, size);
    *(_DWORD *)*addr = v3->slot;
    *addr = (char *)*addr + 4;
  }
  return v5;
}

//----- (00710390) --------------------------------------------------------  // acclient.c:803495
void sub_710390()
{
  flt_8EFF8C = 1000.0 + 1.0;
}

//----- (007103B0) --------------------------------------------------------  // acclient.c:803501
void sub_7103B0()
{
  flt_8EFF90 = 24.0 * 8.0;
}

//----- (007103D0) --------------------------------------------------------  // acclient.c:803507
void sub_7103D0()
{
  flt_8EFF94 = 24.0 * 0.5;
}

//----- (007103F0) --------------------------------------------------------  // acclient.c:803513
int sub_7103F0()
{
  return atexit(nullsub_1840);
}

