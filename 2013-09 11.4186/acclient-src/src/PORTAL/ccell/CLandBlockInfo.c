/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLandBlockInfo
   Object     : PORTAL\ccell\CLandBlockInfo.obj
   Functions  : 24
   Addresses  : 00526AA0 - 006FEC80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526AA0) --------------------------------------------------------  // acclient.c:342212
signed int CLandBlockInfo::GetDBOType()
{
  return 2;
}

//----- (0052E7C0) --------------------------------------------------------  // acclient.c:350641
int __thiscall CLandBlockInfo::PreFetchCells(CLandBlockInfo *this)
{
  CLandBlockInfo *v1; // ebp@1
  int result; // eax@1
  unsigned int v3; // ebx@1
  BuildInfo *v4; // esi@2
  unsigned int v5; // edi@2
  int retval; // [sp+8h] [bp-4h]@1

  v1 = this;
  result = 1;
  v3 = 0;
  retval = 1;
  if ( this->num_buildings )
  {
    do
    {
      v4 = v1->buildings[v3];
      v5 = 0;
      if ( v4->num_portals )
      {
        do
        {
          if ( !CBldPortal::PreFetchCells(v4->portals[v5]) )
            retval = 0;
          ++v5;
        }
        while ( v5 < v4->num_portals );
      }
      ++v3;
    }
    while ( v3 < v1->num_buildings );
    result = retval;
  }
  return result;
}

//----- (0052E820) --------------------------------------------------------  // acclient.c:350679
void __thiscall BuildInfo::~BuildInfo(BuildInfo *this)
{
  BuildInfo *v1; // esi@1
  unsigned int v2; // ebx@1
  CBldPortal **v3; // eax@2
  void *v4; // edi@2

  v1 = this;
  v2 = 0;
  if ( this->num_portals )
  {
    do
    {
      v3 = v1->portals;
      v4 = v3[v2];
      if ( v4 )
      {
        CBldPortal::~CBldPortal(v3[v2]);
        operator delete(v4);
      }
      ++v2;
    }
    while ( v2 < v1->num_portals );
  }
  operator delete[](v1->portals);
  v1->portals = 0;
  v1->building_id.id = stru_844AB0.id;
  v1->num_portals = 0;
  v1->num_leaves = 0;
}

//----- (0052E880) --------------------------------------------------------  // acclient.c:350711
void __thiscall CLandBlockInfo::CLandBlockInfo(CLandBlockInfo *this)
{
  CLandBlockInfo *v1; // esi@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_844AB0);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->num_objects = 0;
  v1->object_ids = 0;
  v1->object_frames = 0;
  v1->num_buildings = 0;
  v1->buildings = 0;
  v1->restriction_table = 0;
  v1->cell_ownership = 0;
  v1->num_cells = 0;
  v1->cell_ids = 0;
  v1->cells = 0;
  v1->vfptr = (InterfaceVtbl *)&CLandBlockInfo::vftable;
  v1->vfptr = (PackObjVtbl *)&CLandBlockInfo::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8E74: using guessed type void *CLandBlockInfo::vftable;
// 7C8E88: using guessed type __int32 (__stdcall *CLandBlockInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0052E8D0) --------------------------------------------------------  // acclient.c:350736
CLandBlockInfo *__thiscall CLandBlockInfo::vector_deleting_destructor(CLandBlockInfo *this, unsigned int a2)
{
  return CLandBlockInfo::scalar_deleting_destructor((CLandBlockInfo *)((char *)this - 48), a2);
}

//----- (0052E8E0) --------------------------------------------------------  // acclient.c:350742
void __thiscall PackableHashTable<unsigned long,unsigned long>::PackableHashTable<unsigned long,unsigned long>(PackableHashTable<unsigned long,unsigned long> *this, const unsigned int table_size)
{
  this->_table_size = table_size;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,unsigned long>::vftable;
  this->m_fThrowawayDuplicateKeysOnUnPack = 0;
  this->_buckets = 0;
  this->_currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
}
// 7C8EE0: using guessed type int (__thiscall *PackableHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (0052E910) --------------------------------------------------------  // acclient.c:350754
unsigned int __thiscall PackableHashTable<unsigned long,unsigned long>::Pack(PackableHashTable<unsigned long,unsigned long> *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  unsigned int result; // eax@1
  PackableHashData<unsigned long,unsigned long> **v5; // edi@2
  unsigned int v6; // ebx@2
  PackableHashData<unsigned long,unsigned long> *i; // edx@3
  char *v8; // edi@7
  unsigned int v9; // ebx@7
  PackableHashData<unsigned long,unsigned long> *j; // esi@8
  char *v11; // ebp@10

  v3 = this->_table_size;
  result = 4;
  if ( v3 )
  {
    v5 = this->_buckets;
    v6 = this->_table_size;
    do
    {
      for ( i = *v5; i; result += 8 )
        i = i->_next;
      ++v5;
      --v6;
    }
    while ( v6 );
  }
  if ( size >= result )
  {
    *(_DWORD *)*addr = this->_currNum | (v3 << 16);
    v8 = (char *)*addr + 4;
    *addr = v8;
    v9 = 0;
    if ( this->_table_size )
    {
      do
      {
        for ( j = this->_buckets[v9]; j; j = j->_next )
        {
          if ( size >= 4 )
          {
            *(_DWORD *)v8 = j->_key;
            v11 = (char *)*addr + 4;
            *addr = v11;
            *(_DWORD *)v11 = j->_data;
            v8 = (char *)*addr + 4;
            *addr = v8;
          }
        }
        ++v9;
      }
      while ( v9 < this->_table_size );
    }
  }
  return result;
}

//----- (0052E9C0) --------------------------------------------------------  // acclient.c:350812
void __thiscall CLandBlockInfo::Destroy(CLandBlockInfo *this)
{
  CLandBlockInfo *v1; // esi@1
  IDClass<_tagDataID,32,0> *v2; // eax@1
  Frame *v3; // eax@3
  unsigned int i; // edi@6
  CEnvCell *v5; // ecx@7
  unsigned int j; // ebx@14
  BuildInfo **v7; // eax@15
  void *v8; // edi@15
  PackableHashTable<unsigned long,unsigned long> *v9; // ecx@19
  PackableHashTable<unsigned long,PackableList<unsigned long> > *v10; // ecx@21

  v1 = this;
  v2 = this->object_ids;
  if ( v2 )
  {
    operator delete[](&v2[-1]);
    v1->object_ids = 0;
  }
  v3 = v1->object_frames;
  if ( v3 )
  {
    operator delete[](&v3[-1].m_fOrigin.z);
    v1->object_frames = 0;
  }
  if ( v1->cells )
  {
    for ( i = 0; i < v1->num_cells; ++i )
    {
      DBObj::Remove((DBObj *)&v1->cells[i]->vfptr);
      v5 = v1->cells[i];
      if ( v5 )
      {
        ((void (*)(void))v5->vfptr->Release)();
        v1->cells[i] = 0;
      }
    }
    operator delete[](v1->cells);
    v1->cells = 0;
  }
  if ( v1->cell_ids )
  {
    operator delete[](v1->cell_ids);
    v1->cell_ids = 0;
  }
  if ( v1->buildings )
  {
    for ( j = 0; j < v1->num_buildings; ++j )
    {
      v7 = v1->buildings;
      v8 = v7[j];
      if ( v8 )
      {
        BuildInfo::~BuildInfo(v7[j]);
        operator delete(v8);
      }
    }
    operator delete[](v1->buildings);
    v1->buildings = 0;
  }
  v9 = v1->restriction_table;
  v1->num_objects = 0;
  if ( v9 )
  {
    ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
    v1->restriction_table = 0;
  }
  v10 = v1->cell_ownership;
  if ( v10 )
  {
    ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    v1->cell_ownership = 0;
  }
  v1->num_cells = 0;
  v1->num_buildings = 0;
}

//----- (0052EAC0) --------------------------------------------------------  // acclient.c:350891
unsigned int __thiscall CLandBlockInfo::pack_size(CLandBlockInfo *this)
{
  CLandBlockInfo *v1; // ebx@1
  unsigned int v2; // ebp@1
  unsigned int v3; // edi@1
  signed int v4; // eax@2
  BuildInfo **v5; // ecx@2
  BuildInfo *v6; // eax@3
  unsigned int v7; // esi@3
  int v8; // eax@4
  PackableHashTable<unsigned long,unsigned long> *v9; // ebx@6
  unsigned int v10; // eax@7
  signed int v11; // ecx@7
  PackableHashData<unsigned long,unsigned long> **v12; // ebx@8
  unsigned int v13; // edx@8
  PackableHashData<unsigned long,unsigned long> *i; // eax@9
  int v16; // [sp+Ch] [bp-4h]@2

  v1 = this;
  v2 = 32 * this->num_objects + 12;
  v3 = 0;
  if ( this->num_buildings )
  {
    v4 = TChessPiece<CBasePiece>::GetPackSize();
    v5 = v1->buildings;
    v16 = v4 + 12;
    do
    {
      v6 = v5[v3];
      v2 += v16;
      v7 = 0;
      if ( v6->num_portals )
      {
        do
        {
          v8 = CBldPortal::pack_size(v6->portals[v7]);
          v5 = v1->buildings;
          v2 += v8;
          v6 = v5[v3];
          ++v7;
        }
        while ( v7 < v6->num_portals );
      }
      ++v3;
    }
    while ( v3 < v1->num_buildings );
  }
  v9 = v1->restriction_table;
  if ( v9 )
  {
    v10 = v9->_table_size;
    v11 = 4;
    if ( v10 )
    {
      v12 = v9->_buckets;
      v13 = v10;
      do
      {
        for ( i = *v12; i; v11 += 8 )
          i = i->_next;
        ++v12;
        --v13;
      }
      while ( v13 );
    }
    v2 += v11;
  }
  return v2;
}

//----- (0052EB60) --------------------------------------------------------  // acclient.c:350962
unsigned int __thiscall CLandBlockInfo::Pack(CLandBlockInfo *this, void **addr, unsigned int size)
{
  CLandBlockInfo *v3; // edi@1
  unsigned int result; // eax@1
  char *v5; // edx@2
  unsigned int v6; // ebx@2
  int v7; // ebp@3
  signed __int16 v8; // ax@5
  unsigned int v9; // ebx@7
  DBObj *v10; // eax@8
  char *v11; // eax@9
  int v12; // ecx@9
  unsigned int v13; // ebp@9
  DBObj *v14; // edi@12
  unsigned int retval; // [sp+8h] [bp-4h]@1

  v3 = this;
  result = CLandBlockInfo::pack_size((CLandBlockInfo *)((char *)this - 48));
  retval = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->m_numLinks;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = *(_DWORD *)&v3->m_bLoaded;
    *addr = (char *)*addr + 4;
    v6 = 0;
    if ( *(_DWORD *)&v3->m_bLoaded )
    {
      v7 = 0;
      do
      {
        *(_DWORD *)*addr = *(_DWORD *)(*((_DWORD *)&v3->m_bLoaded + 1) + 4 * v6);
        *addr = (char *)*addr + 4;
        Frame::Pack((Frame *)(v7 + LODWORD(v3->m_timeStamp)), addr, size);
        ++v6;
        v7 += 64;
      }
      while ( v6 < *(_DWORD *)&v3->m_bLoaded );
    }
    v8 = 0;
    if ( v3->m_pLast )
      v8 = 1;
    *(_DWORD *)*addr = HIDWORD(v3->m_timeStamp) | ((unsigned __int16)v8 << 16);
    *addr = (char *)*addr + 4;
    v9 = 0;
    if ( HIDWORD(v3->m_timeStamp) )
    {
      v10 = v3->m_pNext;
      do
      {
        *(_DWORD *)*addr = **((_DWORD **)&v10->vfptr + v9);
        *addr = (char *)*addr + 4;
        Frame::Pack((Frame *)(*((_DWORD *)&v3->m_pNext->vfptr + v9) + 4), addr, size);
        *(_DWORD *)*addr = *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v9) + 68);
        v11 = (char *)*addr + 4;
        *addr = v11;
        *(_DWORD *)v11 = *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v9) + 72);
        *addr = (char *)*addr + 4;
        v10 = v3->m_pNext;
        v12 = *((_DWORD *)&v10->vfptr + v9);
        v13 = 0;
        if ( *(_DWORD *)(v12 + 72) )
        {
          do
          {
            CBldPortal::Pack(*(CBldPortal **)(*(_DWORD *)(v12 + 76) + 4 * v13), addr, size);
            v10 = v3->m_pNext;
            v12 = *((_DWORD *)&v10->vfptr + v9);
            ++v13;
          }
          while ( v13 < *(_DWORD *)(v12 + 72) );
        }
        ++v9;
      }
      while ( v9 < HIDWORD(v3->m_timeStamp) );
    }
    v14 = v3->m_pLast;
    if ( v14 )
      ((void (__thiscall *)(DBObj *, void **, unsigned int))v14->vfptr->QueryInterface)(v14, addr, size);
    result = retval;
  }
  return result;
}

//----- (0052ECA0) --------------------------------------------------------  // acclient.c:351048
int __thiscall CLandBlockInfo::UnPack(CLandBlockInfo *this, void **addr, unsigned int size)
{
  CLandBlockInfo *v3; // esi@1
  void **v4; // edi@1
  char *v5; // edx@1
  int v6; // ebx@1
  void *v7; // eax@2
  int v8; // ebp@3
  int v9; // ebx@5
  unsigned int v10; // ST0C_4@5
  void *v11; // eax@5
  int v12; // ebp@6
  int v13; // eax@8
  unsigned int v14; // ebx@8
  int v15; // ebp@9
  int v16; // ecx@10
  int v17; // edx@10
  unsigned int v18; // eax@11
  unsigned int v19; // ebp@12
  void *v20; // ebx@13
  int v21; // ecx@14
  int v22; // ecx@16
  int v23; // edx@16
  int v24; // ecx@16
  unsigned int v25; // ebx@16
  CBldPortal *v26; // eax@17
  int v27; // eax@18
  void *v28; // eax@23
  void *v29; // ebx@23
  void *v30; // eax@24
  unsigned int i; // eax@25
  DBObj *v32; // ecx@27
  int result; // eax@29
  unsigned int pack_mask; // [sp+10h] [bp-4h]@11
  unsigned int addra; // [sp+18h] [bp+4h]@11

  v3 = this;
  ((void (__thiscall *)(PackObjVtbl **))this[-1].vfptr[3].__vecDelDtor)(&this[-1].vfptr);
  v4 = addr;
  v3->m_numLinks = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  *(_DWORD *)&v3->m_bLoaded = *(_DWORD *)v5;
  *v4 = (char *)*v4 + 4;
  v6 = *(_DWORD *)&v3->m_bLoaded;
  if ( v6 )
  {
    v7 = operator new[](4 * v6 + 4);
    if ( v7 )
    {
      v8 = (int)((char *)v7 + 4);
      *(_DWORD *)v7 = v6;
      vector_constructor_iterator(
        (char *)v7 + 4,
        4u,
        v6,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
    }
    else
    {
      v8 = 0;
    }
    v9 = *(_DWORD *)&v3->m_bLoaded;
    v10 = (*(_DWORD *)&v3->m_bLoaded << 6) + 4;
    *((_DWORD *)&v3->m_bLoaded + 1) = v8;
    v11 = operator new[](v10);
    if ( v11 )
    {
      v12 = (int)((char *)v11 + 4);
      *(_DWORD *)v11 = v9;
      vector_constructor_iterator((char *)v11 + 4, 0x40u, v9, (void *(__thiscall *)(void *))Frame::Frame);
    }
    else
    {
      v12 = 0;
    }
    v13 = *(_DWORD *)&v3->m_bLoaded;
    v14 = 0;
    LODWORD(v3->m_timeStamp) = v12;
    if ( v13 )
    {
      v15 = 0;
      do
      {
        v16 = *((_DWORD *)&v3->m_bLoaded + 1) + 4 * v14;
        v17 = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        *(_DWORD *)v16 = v17;
        Frame::UnPack((Frame *)(v15 + LODWORD(v3->m_timeStamp)), addr, size);
        ++v14;
        v15 += 64;
      }
      while ( v14 < *(_DWORD *)&v3->m_bLoaded );
    }
  }
  addra = (unsigned int)v3[-1].cell_ids & 0xFFFF0000;
  v18 = *(_DWORD *)*v4;
  *v4 = (char *)*v4 + 4;
  HIDWORD(v3->m_timeStamp) = (unsigned __int16)v18;
  pack_mask = v18 >> 16;
  if ( (_WORD)v18 )
  {
    v3->m_pNext = (DBObj *)operator new[](4 * (unsigned __int16)v18);
    v19 = 0;
    if ( HIDWORD(v3->m_timeStamp) )
    {
      do
      {
        v20 = operator new(0x50u);
        if ( v20 )
        {
          *(_DWORD *)v20 = stru_844AB0.id;
          v21 = (int)((char *)v20 + 4);
          *(_DWORD *)v21 = 1065353216;
          *(_DWORD *)(v21 + 4) = 0;
          *(_DWORD *)(v21 + 8) = 0;
          *(_DWORD *)(v21 + 12) = 0;
          *(_DWORD *)(v21 + 52) = 0;
          *(_DWORD *)(v21 + 56) = 0;
          *(_DWORD *)(v21 + 60) = 0;
          Frame::cache((Frame *)((char *)v20 + 4));
          *((_DWORD *)v20 + 17) = 0;
          *((_DWORD *)v20 + 18) = 0;
          *((_DWORD *)v20 + 19) = 0;
        }
        else
        {
          v20 = 0;
        }
        *((_DWORD *)&v3->m_pNext->vfptr + v19) = v20;
        v22 = *((_DWORD *)&v3->m_pNext->vfptr + v19);
        v23 = *(_DWORD *)*v4;
        *v4 = (char *)*v4 + 4;
        *(_DWORD *)v22 = v23;
        Frame::UnPack((Frame *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 4), v4, size);
        *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 68) = *(_DWORD *)*v4;
        v24 = (int)((char *)*v4 + 4);
        *v4 = (void *)v24;
        *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 72) = *(_DWORD *)v24;
        *v4 = (char *)*v4 + 4;
        *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 76) = operator new[](4 * *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr
                                                                                                  + v19)
                                                                                                + 72));
        v25 = 0;
        if ( *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 72) )
        {
          do
          {
            v26 = (CBldPortal *)operator new(0x1Cu);
            if ( v26 )
              CBldPortal::CBldPortal(v26);
            else
              v27 = 0;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 76) + 4 * v25) = v27;
            CBldPortal::UnPack(
              *(CBldPortal **)(*(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 76) + 4 * v25++),
              addra,
              v4,
              size);
          }
          while ( v25 < *(_DWORD *)(*((_DWORD *)&v3->m_pNext->vfptr + v19) + 72) );
        }
        ++v19;
      }
      while ( v19 < HIDWORD(v3->m_timeStamp) );
    }
  }
  if ( !(pack_mask & 1) )
    goto LABEL_33;
  v28 = operator new(0x14u);
  v29 = v28;
  if ( v28 )
  {
    *(_DWORD *)v28 = &PackableHashTable<unsigned long,unsigned long>::vftable;
    *((_DWORD *)v28 + 1) = 0;
    *((_DWORD *)v28 + 2) = 0;
    *((_DWORD *)v28 + 3) = 8;
    *((_DWORD *)v28 + 4) = 0;
    v30 = operator new[](0x20u);
    *((_DWORD *)v29 + 2) = v30;
    if ( v30 )
    {
      for ( i = 0; i < *((_DWORD *)v29 + 3); ++i )
        *(_DWORD *)(*((_DWORD *)v29 + 2) + 4 * i) = 0;
    }
    v32 = (DBObj *)v29;
  }
  else
  {
    v32 = 0;
  }
  v3->m_pLast = v32;
  result = ((int (__stdcall *)(void **, unsigned int))v32->vfptr->AddRef)(v4, size);
  if ( result )
LABEL_33:
    result = 1;
  return result;
}
// 7C8EE0: using guessed type int (__thiscall *PackableHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (0052EF70) --------------------------------------------------------  // acclient.c:351249
int __thiscall CLandBlockInfo::GetRestrictionIID(CLandBlockInfo *this, const unsigned int landcellid)
{
  PackableHashTable<unsigned long,unsigned long> *v2; // ecx@1
  int *v3; // eax@2
  int result; // eax@3

  v2 = this->restriction_table;
  if ( v2
    && (v3 = PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::lookup(
               (PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2,
               (IDClass<_tagDataID,32,0> *)&landcellid)) != 0 )
    result = *v3;
  else
    result = 0;
  return result;
}

//----- (0052EFE0) --------------------------------------------------------  // acclient.c:351302
PackableHashTable<unsigned long,unsigned long> *__thiscall PackableHashTable<unsigned long,unsigned long>::vector_deleting_destructor(PackableHashTable<unsigned long,unsigned long> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,unsigned long>::vftable;
  PackableHashTable<unsigned long,unsigned long>::Destroy((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8EE0: using guessed type int (__thiscall *PackableHashTable<unsigned long,unsigned long>::vftable)(void *, char);

//----- (0052F010) --------------------------------------------------------  // acclient.c:351318
CLandBlockInfo *__thiscall CLandBlockInfo::scalar_deleting_destructor(CLandBlockInfo *this, unsigned int a2)
{
  CLandBlockInfo *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CLandBlockInfo::vftable;
  this->vfptr = (PackObjVtbl *)&CLandBlockInfo::vftable;
  CLandBlockInfo::Destroy(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C8E74: using guessed type void *CLandBlockInfo::vftable;
// 7C8E88: using guessed type __int32 (__stdcall *CLandBlockInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006FEB90) --------------------------------------------------------  // acclient.c:786829
void sub_6FEB90()
{
  flt_844AA4 = 1000.0 + 1.0;
}

//----- (006FEBB0) --------------------------------------------------------  // acclient.c:786835
void sub_6FEBB0()
{
  flt_844AA8 = 24.0 * 8.0;
}

//----- (006FEBD0) --------------------------------------------------------  // acclient.c:786841
void sub_6FEBD0()
{
  flt_844AAC = 24.0 * 0.5;
}

//----- (006FEBF0) --------------------------------------------------------  // acclient.c:786847
int sub_6FEBF0()
{
  return atexit(nullsub_1147);
}

//----- (006FEC00) --------------------------------------------------------  // acclient.c:786853
int sub_6FEC00()
{
  return atexit(nullsub_1148);
}

//----- (006FEC10) --------------------------------------------------------  // acclient.c:786859
int sub_6FEC10()
{
  return atexit(nullsub_1149);
}

//----- (006FEC20) --------------------------------------------------------  // acclient.c:786865
void _E106_95()
{
  flt_844AB4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FEC40) --------------------------------------------------------  // acclient.c:786871
void _E108_72()
{
  dbl_844AB8 = 1.0 / 30.0;
}

//----- (006FEC60) --------------------------------------------------------  // acclient.c:786877
void _E110_59()
{
  dbl_844AC0 = 1.0 / 5.0;
}

//----- (006FEC80) --------------------------------------------------------  // acclient.c:786883
int sub_6FEC80()
{
  return atexit(nullsub_1146);
}

