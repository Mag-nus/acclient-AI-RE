/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : BodyPartSelectionData
   Object     : AC\acbody\BodyPartSelectionData.obj
   Functions  : 2
   Addresses  : 005D15E0 - 005D1690 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005D15E0) --------------------------------------------------------  // acclient.c:509457
unsigned int __thiscall BodyPartSelectionData::Pack(BodyPartSelectionData *this, void **addr, unsigned int size)
{
  BodyPartSelectionData *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edx@2
  char *v6; // edx@2
  char *v7; // edx@2
  char *v8; // edx@2
  char *v9; // edx@2
  char *v10; // edx@2
  char *v11; // edx@2
  char *v12; // edx@2
  char *v13; // edx@2
  char *v14; // edx@2
  char *v15; // edx@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= result )
  {
    *(float *)*addr = v3->HLF;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->MLF;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->LLF;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = v3->HRF;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(float *)v8 = v3->MRF;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(float *)v9 = v3->LRF;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(float *)v10 = v3->HLB;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(float *)v11 = v3->MLB;
    v12 = (char *)*addr + 4;
    *addr = v12;
    *(float *)v12 = v3->LLB;
    v13 = (char *)*addr + 4;
    *addr = v13;
    *(float *)v13 = v3->HRB;
    v14 = (char *)*addr + 4;
    *addr = v14;
    *(float *)v14 = v3->MRB;
    v15 = (char *)*addr + 4;
    *addr = v15;
    *(float *)v15 = v3->LRB;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (005D1690) --------------------------------------------------------  // acclient.c:509517
int __thiscall BodyPartSelectionData::UnPack(BodyPartSelectionData *this, void **addr, unsigned int size)
{
  BodyPartSelectionData *v3; // esi@1
  int result; // eax@2
  char *v5; // edx@3
  char *v6; // ecx@3
  char *v7; // edx@3
  char *v8; // ecx@3
  char *v9; // edx@3
  char *v10; // ecx@3
  char *v11; // edx@3
  char *v12; // ecx@3
  char *v13; // edx@3
  char *v14; // ecx@3
  char *v15; // edx@3

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr->GetPackSize)() )
  {
    LODWORD(v3->HLF) = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(v3->MLF) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    LODWORD(v3->LLF) = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    LODWORD(v3->HRF) = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    LODWORD(v3->MRF) = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    LODWORD(v3->LRF) = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    LODWORD(v3->HLB) = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    LODWORD(v3->MLB) = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    LODWORD(v3->LLB) = *(_DWORD *)v12;
    v13 = (char *)*addr + 4;
    *addr = v13;
    LODWORD(v3->HRB) = *(_DWORD *)v13;
    v14 = (char *)*addr + 4;
    *addr = v14;
    LODWORD(v3->MRB) = *(_DWORD *)v14;
    v15 = (char *)*addr + 4;
    *addr = v15;
    LODWORD(v3->LRB) = *(_DWORD *)v15;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

