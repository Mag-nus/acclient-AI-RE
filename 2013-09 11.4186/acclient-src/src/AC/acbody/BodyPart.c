/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BodyPart
   Object     : AC\acbody\BodyPart.obj
   Functions  : 14
   Addresses  : 00421F50 - 00710480 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00421F50) --------------------------------------------------------  // acclient.c:93677
signed int BodyPartSelectionData::GetPackSize()
{
  return 48;
}

//----- (005D10A0) --------------------------------------------------------  // acclient.c:509066
int __thiscall BodyPart::GetPackSize(BodyPart *this)
{
  BodyPart *v1; // edi@1
  PackObjVtbl *v2; // eax@1
  int v3; // eax@1
  BodyPartSelectionData *v4; // ecx@1
  int v5; // esi@1
  void *mem; // [sp+8h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = this->_acache.vfptr;
  mem = 0;
  v3 = ((int (__thiscall *)(ArmorCache *, void **, _DWORD))v2->Pack)(&this->_acache, &mem, 0);
  v4 = v1->_bpsd;
  v5 = v3 + 20;
  if ( v4 )
  {
    mem = 0;
    v5 += ((int (__stdcall *)(void **, _DWORD))v4->vfptr->Pack)(&mem, 0);
  }
  return v5;
}

//----- (005D10F0) --------------------------------------------------------  // acclient.c:509091
void __thiscall BodyPartSelectionData::BodyPartSelectionData(BodyPartSelectionData *this)
{
  this->vfptr = (PackObjVtbl *)&BodyPartSelectionData::vftable;
  LODWORD(this->HLF) = 0;
  LODWORD(this->MLF) = 0;
  LODWORD(this->LLF) = 0;
  LODWORD(this->HRF) = 0;
  LODWORD(this->MRF) = 0;
  LODWORD(this->LRF) = 0;
  LODWORD(this->HLB) = 0;
  LODWORD(this->MLB) = 0;
  LODWORD(this->LLB) = 0;
  LODWORD(this->HRB) = 0;
  LODWORD(this->MRB) = 0;
  LODWORD(this->LRB) = 0;
}
// 7E8948: using guessed type int (__thiscall *BodyPartSelectionData::vftable)(void *, char);

//----- (005D1120) --------------------------------------------------------  // acclient.c:509110
void __thiscall BodyPartSelectionData::BodyPartSelectionData(BodyPartSelectionData *this, BodyPartSelectionData *__that)
{
  this->vfptr = (PackObjVtbl *)&BodyPartSelectionData::vftable;
  this->HLF = __that->HLF;
  this->MLF = __that->MLF;
  this->LLF = __that->LLF;
  this->HRF = __that->HRF;
  this->MRF = __that->MRF;
  this->LRF = __that->LRF;
  this->HLB = __that->HLB;
  this->MLB = __that->MLB;
  this->LLB = __that->LLB;
  this->HRB = __that->HRB;
  this->MRB = __that->MRB;
  this->LRB = __that->LRB;
}
// 7E8948: using guessed type int (__thiscall *BodyPartSelectionData::vftable)(void *, char);

//----- (005D1180) --------------------------------------------------------  // acclient.c:509129
void __thiscall BodyPart::~BodyPart(BodyPart *this)
{
  BodyPart *v1; // esi@1
  BodyPartSelectionData *v2; // ecx@1

  v1 = this;
  v2 = this->_bpsd;
  v1->vfptr = (PackObjVtbl *)&BodyPart::vftable;
  if ( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->_bpsd = 0;
  }
  v1->_acache.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4380: using guessed type int (__thiscall *BodyPart::vftable)(void *, char);

//----- (005D11B0) --------------------------------------------------------  // acclient.c:509149
int __thiscall LM_UVRotate::operator=(int this, int a2)
{
  int result; // eax@1

  result = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  return result;
}

//----- (005D1210) --------------------------------------------------------  // acclient.c:509170
unsigned int __thiscall BodyPart::Pack(BodyPart *this, void **addr, unsigned int size)
{
  BodyPart *v3; // edi@1
  unsigned int v4; // ebp@1
  void **v5; // esi@2
  char *v6; // eax@2
  char *v7; // edx@2
  char *v8; // ecx@2
  BodyPartSelectionData *v9; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    v5 = addr;
    *(_DWORD *)*addr = v3->_bpsd != 0;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->_dtype;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->_dval;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(float *)v8 = v3->_dvar;
    *v5 = (char *)*v5 + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->_acache.vfptr->Pack)(addr, size);
    *(_DWORD *)*addr = v3->_bh;
    *v5 = (char *)*v5 + 4;
    v9 = v3->_bpsd;
    if ( v9 )
      ((void (__stdcall *)(void **, unsigned int))v9->vfptr->Pack)(addr, size);
  }
  return v4;
}

//----- (005D12A0) --------------------------------------------------------  // acclient.c:509207
int __thiscall BodyPart::UnPack(BodyPart *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  BodyPart *v4; // edi@1
  PackObjVtbl *v5; // edx@1
  char *v6; // ebx@1
  int v7; // eax@1
  unsigned int v8; // ecx@1
  int v9; // eax@2
  int v10; // ebp@2
  int v11; // eax@2
  int v12; // edx@2
  BodyPartSelectionData *v13; // eax@4
  BodyPartSelectionData *v14; // eax@5
  BodyPartSelectionData *v15; // ecx@9
  void *start; // [sp+14h] [bp-4h]@1

  v3 = addr;
  v4 = this;
  v5 = this->_acache.vfptr;
  start = *addr;
  v6 = (char *)&this->_acache;
  addr = 0;
  v7 = ((int (__thiscall *)(ArmorCache *, void ***, _DWORD))v5->Pack)(&this->_acache, &addr, 0);
  v8 = size;
  if ( size < v7 + 20 )
    return 0;
  v9 = (int)((char *)*v3 + 4);
  v10 = *(_DWORD *)*v3;
  *v3 = (void *)v9;
  v4->_dtype = *(_DWORD *)v9;
  v11 = (int)((char *)*v3 + 4);
  *v3 = (void *)v11;
  v4->_dval = *(_DWORD *)v11;
  v12 = (int)((char *)*v3 + 4);
  *v3 = (void *)v12;
  LODWORD(v4->_dvar) = *(_DWORD *)v12;
  *v3 = (char *)*v3 + 4;
  (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v6 + 16))(v6, v3, v8);
  v4->_bh = *(_DWORD *)*v3;
  *v3 = (char *)*v3 + 4;
  if ( v10 )
  {
    if ( !v4->_bpsd )
    {
      v13 = (BodyPartSelectionData *)operator new(0x34u);
      if ( v13 )
        BodyPartSelectionData::BodyPartSelectionData(v13);
      else
        v14 = 0;
      v4->_bpsd = v14;
    }
    ((void (__thiscall *)(BodyPartSelectionData *, void **, unsigned int))v4->_bpsd->vfptr->UnPack)(v4->_bpsd, v3, size);
  }
  else
  {
    v15 = v4->_bpsd;
    if ( v15 )
    {
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
      v4->_bpsd = 0;
    }
  }
  if ( size < (_BYTE *)*v3 - (_BYTE *)start )
  {
    *v3 = start;
    return 0;
  }
  return 1;
}

//----- (005D13A0) --------------------------------------------------------  // acclient.c:509279
int __thiscall BodyPart::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@2
  BodyPartSelectionData *v4; // eax@4
  int v5; // eax@5
  int result; // eax@5

  v2 = this;
  if ( a2 == this )
    return v2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
  v3 = *(_DWORD *)(this + 60);
  *(_DWORD *)(v2 + 56) = *(_DWORD *)(a2 + 56);
  if ( !*(_DWORD *)(a2 + 60) )
  {
    if ( v3 )
    {
      (**(void (__stdcall ***)(_DWORD))v3)(1);
      *(_DWORD *)(v2 + 60) = 0;
    }
    return v2;
  }
  if ( v3 )
  {
    LM_UVRotate::operator=(v3, *(_DWORD *)(a2 + 60));
    result = v2;
  }
  else
  {
    v4 = (BodyPartSelectionData *)operator new(0x34u);
    if ( v4 )
    {
      BodyPartSelectionData::BodyPartSelectionData(v4, *(BodyPartSelectionData **)(a2 + 60));
      *(_DWORD *)(v2 + 60) = v5;
      result = v2;
    }
    else
    {
      *(_DWORD *)(v2 + 60) = 0;
      result = v2;
    }
  }
  return result;
}

//----- (005D1460) --------------------------------------------------------  // acclient.c:509337
void __thiscall BodyPart::BodyPart(BodyPart *this, BodyPart *rhs)
{
  this->_dtype = 0;
  this->_dval = 0;
  LODWORD(this->_dvar) = 0;
  this->vfptr = (PackObjVtbl *)&BodyPart::vftable;
  this->_acache._base_armor = 0;
  this->_acache._armor_vs_slash = 0;
  this->_acache._armor_vs_pierce = 0;
  this->_acache._armor_vs_bludgeon = 0;
  this->_acache._armor_vs_cold = 0;
  this->_acache._armor_vs_fire = 0;
  this->_acache._armor_vs_acid = 0;
  this->_acache._armor_vs_electric = 0;
  this->_acache._armor_vs_nether = 0;
  this->_acache.vfptr = (PackObjVtbl *)&ArmorCache::vftable;
  this->_bh = 0;
  this->_bpsd = 0;
  BodyPart::operator=((int)this, (int)rhs);
}
// 7E436C: using guessed type int (__thiscall *ArmorCache::vftable)(void *, char);
// 7E4380: using guessed type int (__thiscall *BodyPart::vftable)(void *, char);

//----- (00710420) --------------------------------------------------------  // acclient.c:803531
void sub_710420()
{
  flt_8EFFB8 = 1000.0 + 1.0;
}

//----- (00710440) --------------------------------------------------------  // acclient.c:803537
void sub_710440()
{
  flt_8EFFBC = 24.0 * 8.0;
}

//----- (00710460) --------------------------------------------------------  // acclient.c:803543
void sub_710460()
{
  flt_8EFFC0 = 24.0 * 0.5;
}

//----- (00710480) --------------------------------------------------------  // acclient.c:803549
int sub_710480()
{
  return atexit(nullsub_1843);
}

