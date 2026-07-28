/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CEnvironment
   Object     : PORTAL\ccell\CEnvironment.obj
   Functions  : 13
   Addresses  : 00530BF0 - 006FEF60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00530BF0) --------------------------------------------------------  // acclient.c:352896
CCellStruct *__thiscall CEnvironment::get_cellstruct(CEnvironment *this, unsigned int index)
{
  return &this->cells[index];
}

//----- (00530C00) --------------------------------------------------------  // acclient.c:352902
signed int __thiscall CEnvironment::pack_size(CEnvironment *this)
{
  CEnvironment *v1; // esi@1
  unsigned int v2; // eax@1
  int v3; // ebx@1
  unsigned int v4; // edi@1
  signed int v5; // ebp@1
  void *dummy; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = this->num_cells;
  v3 = 0;
  v4 = 0;
  dummy = 0;
  v5 = 4;
  if ( v2 )
  {
    do
    {
      v5 += CCellStruct::Pack(&v1->cells[v3], &dummy, 0);
      ++v4;
      ++v3;
    }
    while ( v4 < v1->num_cells );
  }
  return v5;
}

//----- (00530C50) --------------------------------------------------------  // acclient.c:352931
void __thiscall CEnvironment::CEnvironment(CEnvironment *this)
{
  CEnvironment *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844C28);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->num_cells = 0;
  v1->cells = 0;
  v1->vfptr = (InterfaceVtbl *)&CEnvironment::vftable;
  v1->vfptr = (PackObjVtbl *)&CEnvironment::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C9038: using guessed type void *CEnvironment::vftable;
// 7C9050: using guessed type __int32 (__stdcall *CEnvironment::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00530C80) --------------------------------------------------------  // acclient.c:352948
CEnvironment *__thiscall CEnvironment::vector_deleting_destructor(CEnvironment *this, unsigned int a2)
{
  return CEnvironment::scalar_deleting_destructor((CEnvironment *)((char *)this - 48), a2);
}

//----- (00530C90) --------------------------------------------------------  // acclient.c:352954
signed int __thiscall CEnvironment::Pack(CEnvironment *this, void **addr, unsigned int size)
{
  CEnvironment *v3; // esi@1
  signed int result; // eax@1
  unsigned int v5; // edi@2
  int v6; // ebx@3
  unsigned int retval; // [sp+0h] [bp-4h]@1

  v3 = this;
  result = CEnvironment::pack_size((CEnvironment *)((char *)this - 48));
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = *(_DWORD *)&v3->m_bLoaded;
    *addr = (char *)*addr + 4;
    v5 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      v6 = 0;
      do
      {
        CCellStruct::Pack((CCellStruct *)(v6 + *((_DWORD *)&v3->m_bLoaded + 1)), addr, size);
        ++v5;
        v6 += 88;
      }
      while ( v5 < *(_DWORD *)&v3->m_bLoaded );
      result = retval;
    }
  }
  return result;
}

//----- (00530CF0) --------------------------------------------------------  // acclient.c:352987
int __thiscall CEnvironment::UnPack(CEnvironment *this, void **addr, unsigned int size)
{
  CEnvironment *v3; // esi@1
  void **v4; // ebp@1
  int v5; // edi@1
  void *v6; // eax@1
  int v7; // eax@2
  int v8; // edi@2
  CCellStruct *v9; // ebx@2
  int v10; // edi@3
  unsigned int v11; // edi@7
  int v12; // ebx@8
  void **addra; // [sp+14h] [bp+4h]@2

  v3 = this;
  (*(void (__thiscall **)(long double *))(LODWORD(this[-1].m_timeStamp) + 60))(&this[-1].m_timeStamp);
  v4 = addr;
  *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)*addr;
  *v4 = (char *)*v4 + 4;
  v5 = *(_DWORD *)&v3->m_bLoaded;
  v6 = operator new[](88 * *(_DWORD *)&v3->m_bLoaded + 4);
  if ( v6 )
  {
    v7 = (int)((char *)v6 + 4);
    *(_DWORD *)(v7 - 4) = v5;
    v8 = v5 - 1;
    addra = (void **)v7;
    v9 = (CCellStruct *)v7;
    if ( v8 >= 0 )
    {
      v10 = v8 + 1;
      do
      {
        CCellStruct::CCellStruct(v9);
        ++v9;
        --v10;
      }
      while ( v10 );
      v7 = (int)addra;
    }
  }
  else
  {
    v7 = 0;
  }
  *((_DWORD *)&v3->m_bLoaded + 1) = v7;
  v11 = 0;
  if ( *(_DWORD *)&v3->m_bLoaded )
  {
    v12 = 0;
    do
    {
      CCellStruct::UnPack((CCellStruct *)(v12 + *((_DWORD *)&v3->m_bLoaded + 1)), v4, size);
      ++v11;
      v12 += 88;
    }
    while ( v11 < *(_DWORD *)&v3->m_bLoaded );
  }
  return 1;
}

//----- (00530DA0) --------------------------------------------------------  // acclient.c:353049
void __thiscall CEnvironment::Destroy(CEnvironment *this)
{
  CEnvironment *v1; // ebx@1
  CCellStruct *v2; // ecx@1
  BSPTREE *v3; // eax@2
  void *v4; // ebp@2
  CCellStruct *v5; // esi@2
  int v6; // eax@2
  int v7; // edi@3

  v1 = this;
  v2 = this->cells;
  if ( v2 )
  {
    v3 = v2[-1].cell_bsp;
    v4 = &v2[-1].cell_bsp;
    v5 = &v2[(_DWORD)v3];
    v6 = (int)((char *)&v3[-1].root_node + 3);
    if ( v6 >= 0 )
    {
      v7 = v6 + 1;
      do
      {
        --v5;
        CCellStruct::~CCellStruct(v5);
        --v7;
      }
      while ( v7 );
    }
    operator delete[](v4);
    v1->cells = 0;
    v1->num_cells = 0;
  }
  else
  {
    v1->num_cells = 0;
  }
}

//----- (00530DF0) --------------------------------------------------------  // acclient.c:353089
CEnvironment *__thiscall CEnvironment::scalar_deleting_destructor(CEnvironment *this, unsigned int a2)
{
  CEnvironment *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CEnvironment::vftable;
  this->vfptr = (PackObjVtbl *)&CEnvironment::vftable;
  CEnvironment::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C9038: using guessed type void *CEnvironment::vftable;
// 7C9050: using guessed type __int32 (__stdcall *CEnvironment::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006FEF20) --------------------------------------------------------  // acclient.c:787041
int _E73_92()
{
  return atexit(_E74_68);
}

//----- (006FEF30) --------------------------------------------------------  // acclient.c:787047
int _E76_54()
{
  return atexit(_E77_82);
}

//----- (006FEF40) --------------------------------------------------------  // acclient.c:787053
int _E79_47()
{
  return atexit(_E80_46);
}

//----- (006FEF50) --------------------------------------------------------  // acclient.c:787059
void _E82_29()
{
  PixelFormatDesc::PixelFormatDesc(&stru_844C2C, PFID_A8R8G8B8);
}

//----- (006FEF60) --------------------------------------------------------  // acclient.c:787065
int sub_6FEF60()
{
  return atexit(nullsub_1168);
}

