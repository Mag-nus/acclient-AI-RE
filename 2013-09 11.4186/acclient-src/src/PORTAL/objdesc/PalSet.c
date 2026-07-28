/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PalSet
   Object     : PORTAL\objdesc\PalSet.obj
   Functions  : 9
   Addresses  : 005268F0 - 0070E1D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005268F0) --------------------------------------------------------  // acclient.c:342095
signed int TextInputDialog::GetUIElementType()
{
  return 24;
}

//----- (005AC530) --------------------------------------------------------  // acclient.c:470460
void __thiscall PalSet::PalSet(PalSet *this, IDClass<_tagDataID,32,0> global_id)
{
  PalSet *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, global_id);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->num_pals = 0;
  v2->palette_IDs = 0;
  v2->vfptr = (InterfaceVtbl *)&PalSet::vftable;
  v2->vfptr = (PackObjVtbl *)&PalSet::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6040: using guessed type void *PalSet::vftable;
// 7E6058: using guessed type __int32 (__stdcall *PalSet::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005AC560) --------------------------------------------------------  // acclient.c:470477
PalSet *__thiscall PalSet::vector_deleting_destructor(PalSet *this, unsigned int a2)
{
  return PalSet::vector_deleting_destructor((PalSet *)((char *)this - 48), a2);
}

//----- (005AC570) --------------------------------------------------------  // acclient.c:470483
IDClass<_tagDataID,32,0> *__thiscall PalSet::GetPaletteID(PalSet *this, IDClass<_tagDataID,32,0> *result, long double _shade)
{
  unsigned int v3; // edx@1
  IDClass<_tagDataID,32,0> *v4; // esi@2
  IDClass<_tagDataID,32,0> *v5; // eax@5

  v3 = this->num_pals;
  if ( v3 && (v4 = this->palette_IDs) != 0 && _shade <= 1.0 && _shade >= 0.0 )
  {
    v5 = result;
    result->id = v4[(unsigned __int64)(((double)v3 - 0.000001) * _shade)].id;
  }
  else
  {
    v5 = result;
    result->id = stru_8EE0F8.id;
  }
  return v5;
}

//----- (005AC5F0) --------------------------------------------------------  // acclient.c:470504
IDClass<_tagDataID,32,0> *__thiscall PalSet::GetPaletteID_Integral(PalSet *this, IDClass<_tagDataID,32,0> *result, int _num)
{
  IDClass<_tagDataID,32,0> *v3; // eax@3
  unsigned int v4; // ecx@4
  IDClass<_tagDataID,32,0> *v5; // eax@4

  if ( _num >= 0 && _num < (signed int)this->num_pals && (v3 = this->palette_IDs) != 0 )
  {
    v4 = v3[_num].id;
    v5 = result;
    result->id = v4;
  }
  else
  {
    v5 = result;
    result->id = stru_8EE0F8.id;
  }
  return v5;
}

//----- (005AC630) --------------------------------------------------------  // acclient.c:470525
unsigned int __thiscall PalSet::Pack(PalSet *this, void **addr, unsigned int size)
{
  int v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // esi@2
  char *v6; // edi@2
  unsigned int v7; // esi@2

  v3 = *(_DWORD *)&this->m_bLoaded;
  result = 4 * v3 + 4;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = v5;
    v7 = 0;
    if ( *(_DWORD *)&this->m_bLoaded )
    {
      do
      {
        *(_DWORD *)v6 = *(_DWORD *)(*((_DWORD *)&this->m_bLoaded + 1) + 4 * v7);
        v6 = (char *)*addr + 4;
        *addr = v6;
        ++v7;
      }
      while ( v7 < *(_DWORD *)&this->m_bLoaded );
    }
  }
  return result;
}

//----- (005AC680) --------------------------------------------------------  // acclient.c:470558
int __thiscall PalSet::UnPack(PalSet *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  void **v4; // edi@1
  void *v5; // eax@1
  PalSet *v6; // esi@1
  void *v7; // ecx@1
  int result; // eax@2
  int v9; // eax@5
  int v10; // ebx@7
  void *v11; // eax@8
  int v12; // ebp@9
  int v13; // eax@9
  int v14; // ecx@11
  unsigned int v15; // eax@11
  int v16; // ebx@12
  int v17; // edx@12
  void **addra; // [sp+10h] [bp+4h]@1

  v3 = size;
  v4 = addr;
  v5 = *addr;
  v6 = this;
  v7 = *addr;
  addra = (void **)*addr;
  if ( size >= 4 )
  {
    *(_DWORD *)&v6->m_bLoaded = *(_DWORD *)v5;
    *v4 = (char *)*v4 + 4;
    if ( size >= 4 * *(_DWORD *)&v6->m_bLoaded + 4 )
    {
      v9 = *((_DWORD *)&v6->m_bLoaded + 1);
      if ( v9 )
        operator delete[]((void *)(v9 - 4));
      v10 = *(_DWORD *)&v6->m_bLoaded;
      *((_DWORD *)&v6->m_bLoaded + 1) = 0;
      if ( v10 )
      {
        v11 = operator new[](4 * v10 + 4);
        if ( v11 )
        {
          v12 = (int)((char *)v11 + 4);
          *(_DWORD *)v11 = v10;
          vector_constructor_iterator(
            (char *)v11 + 4,
            4u,
            v10,
            (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
          v13 = v12;
          v3 = size;
        }
        else
        {
          v13 = 0;
        }
        v14 = *(_DWORD *)&v6->m_bLoaded;
        *((_DWORD *)&v6->m_bLoaded + 1) = v13;
        v15 = 0;
        if ( v14 )
        {
          do
          {
            v16 = *(_DWORD *)*v4;
            v17 = *((_DWORD *)&v6->m_bLoaded + 1) + 4 * v15;
            *v4 = (char *)*v4 + 4;
            *(_DWORD *)v17 = v16;
            ++v15;
          }
          while ( v15 < *(_DWORD *)&v6->m_bLoaded );
        }
      }
      if ( v3 >= (_BYTE *)*v4 - (_BYTE *)addra )
      {
        result = 1;
      }
      else
      {
        *v4 = addra;
        result = 0;
      }
    }
    else
    {
      *v4 = v7;
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005AC760) --------------------------------------------------------  // acclient.c:470653
PalSet *__thiscall PalSet::vector_deleting_destructor(PalSet *this, unsigned int a2)
{
  PalSet *v2; // esi@1
  IDClass<_tagDataID,32,0> *v3; // eax@1

  v2 = this;
  v3 = this->palette_IDs;
  this->vfptr = (InterfaceVtbl *)&PalSet::vftable;
  this->vfptr = (PackObjVtbl *)&PalSet::vftable;
  if ( v3 )
  {
    operator delete[](&v3[-1]);
    v2->palette_IDs = 0;
  }
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6040: using guessed type void *PalSet::vftable;
// 7E6058: using guessed type __int32 (__stdcall *PalSet::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070E1D0) --------------------------------------------------------  // acclient.c:801093
int sub_70E1D0()
{
  return atexit(nullsub_1541);
}

