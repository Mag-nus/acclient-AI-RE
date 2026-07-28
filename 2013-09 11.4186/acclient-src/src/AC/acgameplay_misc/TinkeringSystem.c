/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TinkeringSystem
   Object     : AC\acgameplay_misc\TinkeringSystem.obj
   Functions  : 26
   Addresses  : 00598C30 - 0070FB10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598C30) --------------------------------------------------------  // acclient.c:450959
long double __thiscall PortalSummonSpell::InqDuration(SalvageResult *this)
{
  return this->m_workmanship;
}

//----- (005C9670) --------------------------------------------------------  // acclient.c:500470
int __cdecl TinkeringSystem::IsValidMaterialType(unsigned int material)
{
  int result; // eax@2

  switch ( material )
  {
    case 1u:
    case 2u:
    case 4u:
    case 5u:
    case 6u:
    case 7u:
    case 8u:
    case 0xAu:
    case 0xBu:
    case 0xCu:
    case 0xDu:
    case 0xEu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
    case 0x19u:
    case 0x1Au:
    case 0x1Bu:
    case 0x1Cu:
    case 0x1Du:
    case 0x1Eu:
    case 0x1Fu:
    case 0x20u:
    case 0x21u:
    case 0x22u:
    case 0x23u:
    case 0x24u:
    case 0x25u:
    case 0x26u:
    case 0x27u:
    case 0x28u:
    case 0x29u:
    case 0x2Au:
    case 0x2Bu:
    case 0x2Cu:
    case 0x2Du:
    case 0x2Eu:
    case 0x2Fu:
    case 0x30u:
    case 0x31u:
    case 0x32u:
    case 0x33u:
    case 0x34u:
    case 0x35u:
    case 0x36u:
    case 0x37u:
    case 0x39u:
    case 0x3Au:
    case 0x3Bu:
    case 0x3Cu:
    case 0x3Du:
    case 0x3Eu:
    case 0x3Fu:
    case 0x40u:
    case 0x42u:
    case 0x43u:
    case 0x44u:
    case 0x45u:
    case 0x46u:
    case 0x47u:
    case 0x49u:
    case 0x4Au:
    case 0x4Bu:
    case 0x4Cu:
    case 0x4Du:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005C96F0) --------------------------------------------------------  // acclient.c:500558
PackableList<SalvageResult> *__thiscall SalvageOperationsResultData::GetSalvageResults(SalvageOperationsResultData *this)
{
  return &this->m_salvageResults;
}

//----- (005C9700) --------------------------------------------------------  // acclient.c:500564
int __thiscall SalvageOperationsResultData::Pack(SalvageOperationsResultData *this, void **addr, unsigned int size)
{
  SalvageOperationsResultData *v3; // edi@1
  PackObjVtbl *v4; // eax@1
  char *v5; // ebp@1
  char *v6; // ebx@1
  int v7; // esi@1
  int result; // eax@1
  unsigned int retval; // [sp+20h] [bp-4h]@1

  v3 = this;
  v4 = this->m_notSalvagable.vfptr;
  v5 = (char *)&this->m_notSalvagable;
  retval = 0;
  v6 = (char *)&this->m_salvageResults;
  v7 = ((int (__thiscall *)(PackableList<unsigned long> *, unsigned int *, _DWORD))v4->Pack)(
         &this->m_notSalvagable,
         &retval,
         0);
  result = v7
         + (*(int (__thiscall **)(int, unsigned int *, _DWORD))(*(_DWORD *)v6 + 12))(&v3->m_salvageResults, &retval, 0)
         + 8;
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->m_skillUsed;
    *addr = (char *)*addr + 4;
    (*(void (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 12))(v5, addr, size);
    (*(void (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v6 + 12))(&v3->m_salvageResults, addr, size);
    *(_DWORD *)*addr = v3->m_augBonus;
    *addr = (char *)*addr + 4;
    result = retval;
  }
  return result;
}

//----- (005C9790) --------------------------------------------------------  // acclient.c:500601
int __thiscall SalvageOperationsResultData::UnPack(SalvageOperationsResultData *this, void **addr, unsigned int size)
{
  SalvageOperationsResultData *v3; // ebx@1
  PackObjVtbl *v4; // eax@1
  char *v5; // edi@1
  char *v6; // ebp@1
  int v7; // esi@1
  int result; // eax@4
  int v9; // [sp+10h] [bp-4h]@1

  v3 = this;
  v4 = this->m_notSalvagable.vfptr;
  v5 = (char *)&this->m_notSalvagable;
  v9 = 0;
  v6 = (char *)&this->m_salvageResults;
  v7 = ((int (__thiscall *)(PackableList<unsigned long> *, int *, _DWORD))v4->Pack)(&this->m_notSalvagable, &v9, 0);
  if ( size >= v7 + (*(int (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v6 + 12))(&v3->m_salvageResults, &v9, 0) + 8
    && (v3->m_skillUsed = *(_DWORD *)*addr,
        *addr = (char *)*addr + 4,
        (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v5 + 16))(v5, addr, size))
    && (*(int (__thiscall **)(int, void **, unsigned int))(*(_DWORD *)v6 + 16))(&v3->m_salvageResults, addr, size) )
  {
    v3->m_augBonus = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005C9850) --------------------------------------------------------  // acclient.c:500648
signed int __thiscall SalvageResult::Pack(SalvageResult *this, void **addr, unsigned int size)
{
  char *v3; // esi@2
  char *v4; // edx@2

  if ( size >= 0x10 )
  {
    *(_DWORD *)*addr = this->m_material;
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(double *)v3 = this->m_workmanship;
    v4 = (char *)*addr + 8;
    *addr = v4;
    *(_DWORD *)v4 = this->m_units;
    *addr = (char *)*addr + 4;
  }
  return 16;
}

//----- (005C9890) --------------------------------------------------------  // acclient.c:500668
int __thiscall SalvageResult::UnPack(SalvageResult *this, void **addr, unsigned int size)
{
  int result; // eax@2
  char *v4; // esi@3
  char *v5; // edx@3

  if ( size >= 0x10 )
  {
    this->m_material = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_QWORD *)&this->m_workmanship = *(_QWORD *)v4;
    v5 = (char *)*addr + 8;
    *addr = v5;
    this->m_units = *(_DWORD *)v5;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005C98E0) --------------------------------------------------------  // acclient.c:500694
signed int __thiscall PackableList<SalvageResult>::Pack(PackableList<SalvageResult> *this, void **addr, unsigned int size)
{
  PackableList<SalvageResult> *v3; // esi@1
  signed int v4; // ebp@1
  PackableLLNode<SalvageResult> *i; // esi@4

  v3 = this;
  v4 = PackableList<HousePayment>::pack_size(this);
  if ( size >= v4 )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->curNum;
      *addr = (char *)*addr + 4;
    }
    for ( i = v3->head; i; i = i->next )
      ((void (__thiscall *)(PackableLLNode<SalvageResult> *, void **, unsigned int))i->data.vfptr->Pack)(i, addr, size);
  }
  return v4;
}

//----- (005C9930) --------------------------------------------------------  // acclient.c:500716
signed int __thiscall PackableList<HousePayment>::pack_size(PackableList<SalvageResult> *this)
{
  PackableLLNode<SalvageResult> *v1; // esi@1
  signed int v2; // edi@1
  int v3; // eax@2
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->head;
  v2 = 4;
  for ( addr = 0; v1; v2 += v3 )
  {
    v3 = ((int (__thiscall *)(PackableLLNode<SalvageResult> *, void **, _DWORD))v1->data.vfptr->Pack)(v1, &addr, 0);
    v1 = v1->next;
  }
  return v2;
}

//----- (005C9970) --------------------------------------------------------  // acclient.c:500735
void __thiscall PackableList<SalvageResult>::Flush(PackableList<SalvageResult> *this)
{
  PackableList<SalvageResult> *v1; // esi@1
  PackableLLNode<SalvageResult> *v2; // ecx@2
  PackableLLNode<SalvageResult> *v3; // eax@3

  v1 = this;
  while ( v1->head )
  {
    v2 = v1->head;
    if ( v2 )
    {
      v3 = v2->next;
      v1->head = v3;
      if ( v3 )
        v3->prev = 0;
      else
        v1->tail = 0;
      if ( v2 )
      {
        v2->data.vfptr = (PackObjVtbl *)&PackObj::vftable;
        operator delete(v2);
      }
      --v1->curNum;
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005C99C0) --------------------------------------------------------  // acclient.c:500765
void __thiscall PackableList<SalvageResult>::~PackableList<SalvageResult>(PackableList<SalvageResult> *this)
{
  PackableList<SalvageResult> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<SalvageResult>::vftable;
  PackableList<SalvageResult>::Flush(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7F1C: using guessed type int (__thiscall *PackableList<SalvageResult>::vftable)(void *, char);

//----- (005C99E0) --------------------------------------------------------  // acclient.c:500778
int __thiscall PackableList<SalvageResult>::UnPack(PackableList<SalvageResult> *this, void **addr, unsigned int size)
{
  PackableList<SalvageResult> *v3; // ebp@1
  int v4; // esi@2
  int v5; // edi@2
  int result; // eax@5
  SalvageResult temp; // [sp+8h] [bp-18h]@2

  v3 = this;
  PackableList<SalvageResult>::Flush(this);
  if ( size < 4 )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    temp.vfptr = (PackObjVtbl *)&SalvageResult::vftable;
    temp.m_material = 0;
    *(_QWORD *)&temp.m_workmanship = 0i64;
    temp.m_units = 0;
    if ( v5 <= 0 )
    {
LABEL_5:
      result = 1;
    }
    else
    {
      while ( ((int (__thiscall *)(SalvageResult *, void **, unsigned int))temp.vfptr->UnPack)(&temp, addr, size) )
      {
        PackableList<SalvageResult>::InsertTail(v3, &temp);
        ++v4;
        if ( v4 >= v5 )
          goto LABEL_5;
      }
      result = 0;
    }
  }
  return result;
}
// 7E7F08: using guessed type int (__thiscall *SalvageResult::vftable)(void *, char);

//----- (005C9A70) --------------------------------------------------------  // acclient.c:500823
int __thiscall PackableList<SalvageResult>::InsertTail(PackableList<SalvageResult> *this, SalvageResult *val)
{
  PackableList<SalvageResult> *v2; // esi@1
  void *v3; // eax@1
  int result; // eax@5
  PackableLLNode<SalvageResult> *v5; // ecx@6

  v2 = this;
  v3 = operator new(0x20u);
  if ( v3 )
  {
    *(_DWORD *)v3 = &SalvageResult::vftable;
    *((_DWORD *)v3 + 1) = val->m_material;
    *((_QWORD *)v3 + 1) = *(_QWORD *)&val->m_workmanship;
    *((_DWORD *)v3 + 4) = val->m_units;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
  }
  else
  {
    v3 = 0;
  }
  if ( v2->head )
  {
    v5 = v2->tail;
    v5->next = (PackableLLNode<SalvageResult> *)v3;
    *((_DWORD *)v3 + 7) = v5;
    v2->tail = (PackableLLNode<SalvageResult> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  else
  {
    v2->head = (PackableLLNode<SalvageResult> *)v3;
    v2->tail = (PackableLLNode<SalvageResult> *)v3;
    result = v2->curNum + 1;
    v2->curNum = result;
  }
  return result;
}
// 7E7F08: using guessed type int (__thiscall *SalvageResult::vftable)(void *, char);

//----- (005C9AE0) --------------------------------------------------------  // acclient.c:500866
PackableList<SalvageResult> *__thiscall PackableList<SalvageResult>::vector_deleting_destructor(PackableList<SalvageResult> *this, unsigned int a2)
{
  PackableList<SalvageResult> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableList<SalvageResult>::vftable;
  PackableList<SalvageResult>::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7F1C: using guessed type int (__thiscall *PackableList<SalvageResult>::vftable)(void *, char);

//----- (005C9B10) --------------------------------------------------------  // acclient.c:500882
void __thiscall SalvageOperationsResultData::SalvageOperationsResultData(SalvageOperationsResultData *this)
{
  this->vfptr = (PackObjVtbl *)&SalvageOperationsResultData::vftable;
  this->m_skillUsed = 0;
  this->m_notSalvagable.vfptr = (PackObjVtbl *)&PackableList<unsigned long>::vftable;
  this->m_notSalvagable.head = 0;
  this->m_notSalvagable.tail = 0;
  this->m_notSalvagable.curNum = 0;
  this->m_salvageResults.vfptr = (PackObjVtbl *)&PackableList<SalvageResult>::vftable;
  this->m_salvageResults.head = 0;
  this->m_salvageResults.tail = 0;
  this->m_salvageResults.curNum = 0;
  *(_QWORD *)&this->m_percentReturn = 0i64;
  this->m_augBonus = 0;
}
// 7A3E80: using guessed type int (__thiscall *PackableList<unsigned long>::vftable)(void *, char);
// 7E7F1C: using guessed type int (__thiscall *PackableList<SalvageResult>::vftable)(void *, char);
// 7E7F30: using guessed type int (__thiscall *SalvageOperationsResultData::vftable)(void *, char);

//----- (005C9B50) --------------------------------------------------------  // acclient.c:500902
SalvageOperationsResultData *__thiscall SalvageOperationsResultData::scalar_deleting_destructor(SalvageOperationsResultData *this, unsigned int a2)
{
  SalvageOperationsResultData *v2; // esi@1

  v2 = this;
  PackableList<SalvageResult>::~PackableList<SalvageResult>(&this->m_salvageResults);
  PackableList<unsigned long>::~PackableList<unsigned long>(&v2->m_notSalvagable);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (006B3BE0) --------------------------------------------------------  // acclient.c:717588
int __thiscall SalvageOperationsResultData::GetAugBonus(SalvageOperationsResultData *this)
{
  return this->m_augBonus;
}

//----- (0070FA50) --------------------------------------------------------  // acclient.c:802869
int sub_70FA50()
{
  return atexit(nullsub_1793);
}

//----- (0070FA60) --------------------------------------------------------  // acclient.c:802875
int _E4_18()
{
  return atexit(_E5_18);
}

//----- (0070FA70) --------------------------------------------------------  // acclient.c:802881
int _E7_18()
{
  Outside_CellID_18.id = Invalid_CellID_18.id + 1;
  return atexit(_E8_18);
}

//----- (0070FA90) --------------------------------------------------------  // acclient.c:802888
int _E10_17()
{
  In_Limbo_CellID_17.id = Outside_CellID_18.id + 1;
  return atexit(_E11_17);
}

//----- (0070FAB0) --------------------------------------------------------  // acclient.c:802895
int _E13_17()
{
  First_Interior_CellID_17.id = In_Limbo_CellID_17.id + 1;
  return atexit(_E14_17);
}

//----- (0070FAD0) --------------------------------------------------------  // acclient.c:802902
int _E16_17()
{
  Last_Interior_CellID_17.id = Invalid_CellID_18.id - 1;
  return atexit(_E17_17);
}

//----- (0070FAF0) --------------------------------------------------------  // acclient.c:802909
int _E21_19()
{
  return atexit(_E22_19);
}

//----- (0070FB00) --------------------------------------------------------  // acclient.c:802915
int _E40_19()
{
  return atexit(_E41_19);
}

//----- (0070FB10) --------------------------------------------------------  // acclient.c:802921
int _E43_22()
{
  return atexit(_E44_22);
}

