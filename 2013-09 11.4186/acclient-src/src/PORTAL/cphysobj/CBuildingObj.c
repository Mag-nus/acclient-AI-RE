/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CBuildingObj
   Object     : PORTAL\cphysobj\CBuildingObj.obj
   Functions  : 22
   Addresses  : 006B51B0 - 00723EE0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B51B0) --------------------------------------------------------  // acclient.c:719040
void __thiscall CBuildingObj::add_to_stablist(CBuildingObj *this, unsigned int **block_stab_list, unsigned int *max_size, unsigned int *stab_num)
{
  CBuildingObj *v4; // edi@1
  unsigned int v5; // esi@1

  v4 = this;
  v5 = 0;
  if ( this->num_portals )
  {
    do
      CBldPortal::add_to_stablist(v4->portals[v5++], block_stab_list, max_size, stab_num);
    while ( v5 < v4->num_portals );
  }
}

//----- (006B5200) --------------------------------------------------------  // acclient.c:719056
void __thiscall CBuildingObj::remove(CBuildingObj *this)
{
  CBuildingObj *v1; // esi@1

  v1 = this;
  CSortCell::remove_building((CSortCell *)this->cell, this);
  CPhysicsObj::set_cell_id((CPhysicsObj *)&v1->vfptr, 0);
  v1->cell = 0;
}

//----- (006B5230) --------------------------------------------------------  // acclient.c:719067
void __thiscall CBuildingObj::find_building_transit_cells(CBuildingObj *this, Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  CBuildingObj *v6; // ebx@1
  unsigned int v7; // edi@1
  CBldPortal *v8; // esi@2
  CEnvCell *v9; // eax@2

  v6 = this;
  v7 = 0;
  if ( this->num_portals )
  {
    do
    {
      v8 = v6->portals[v7];
      v9 = (CEnvCell *)CBldPortal::GetOtherCell(v8);
      if ( v9 )
        CEnvCell::check_building_transit(v9, v8->other_portal_id, p, num_sphere, sphere, cell_array, path);
      ++v7;
    }
    while ( v7 < v6->num_portals );
  }
}

//----- (006B52A0) --------------------------------------------------------  // acclient.c:719091
void __thiscall CBuildingObj::find_building_transit_cells(CBuildingObj *this, const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  CBuildingObj *v4; // ebx@1
  unsigned int v5; // edi@1
  CBldPortal *v6; // esi@2
  CEnvCell *v7; // eax@2

  v4 = this;
  v5 = 0;
  if ( this->num_portals )
  {
    do
    {
      v6 = v4->portals[v5];
      v7 = (CEnvCell *)CBldPortal::GetOtherCell(v6);
      if ( v7 )
        CEnvCell::check_building_transit(v7, v6->other_portal_id, num_parts, parts, cell_array);
      ++v5;
    }
    while ( v5 < v4->num_portals );
  }
}

//----- (006B5300) --------------------------------------------------------  // acclient.c:719115
signed int __thiscall CBuildingObj::find_building_collisions(CBuildingObj *this, CTransition *transition)
{
  signed int result; // eax@1

  result = 1;
  if ( this->part_array )
  {
    transition->sphere_path.bldg_check = 1;
    result = CPhysicsPart::find_obj_collisions(*this->part_array->parts, transition);
    transition->sphere_path.bldg_check = 0;
    if ( result != 1 && !(transition->object_info.state & 1) )
      transition->collision_info.collided_with_environment = 1;
  }
  return result;
}

//----- (006B5350) --------------------------------------------------------  // acclient.c:719132
void __thiscall CBuildingObj::CBuildingObj(CBuildingObj *this)
{
  CBuildingObj *v1; // esi@1

  v1 = this;
  CPhysicsObj::CPhysicsObj((CPhysicsObj *)&this->vfptr);
  v1->num_portals = 0;
  v1->portals = 0;
  v1->num_leaves = 0;
  v1->leaf_cells = 0;
  v1->num_shadow = 0;
  v1->vfptr = (HashBaseData<unsigned long>Vtbl *)&CBuildingObj::vftable;
  v1->shadow_list.data = 0;
  v1->shadow_list.sizeOf = 0;
  v1->shadow_list.next_available = 0;
  v1->shadow_list.blocksize = 128;
}
// 8063A0: using guessed type int (__thiscall *CBuildingObj::vftable)(void *, char);

//----- (006B53A0) --------------------------------------------------------  // acclient.c:719152
CBuildingObj *__cdecl CBuildingObj::makeBuilding(IDClass<_tagDataID,32,0> data_id, unsigned int _num_portals, CBldPortal **_portals, unsigned int _num_leaves)
{
  CBuildingObj *v4; // eax@1
  int v5; // eax@2
  int v6; // esi@2
  void *v7; // eax@6
  int v8; // ecx@6
  unsigned int v9; // eax@6
  void *v10; // eax@8
  int v11; // ecx@8
  unsigned int v12; // eax@8
  CBuildingObj *result; // eax@11

  v4 = (CBuildingObj *)operator new(0x1A0u);
  if ( v4 )
  {
    CBuildingObj::CBuildingObj(v4);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  if ( !CPhysicsObj::InitObjectBegin((CPhysicsObj *)v6, 0, 0)
    || !CPhysicsObj::InitPartArrayObject((CPhysicsObj *)v6, data_id, 1) )
    goto LABEL_17;
  *(_DWORD *)(v6 + 384) = _num_leaves;
  v7 = operator new[](4 * _num_leaves);
  v8 = *(_DWORD *)(v6 + 384);
  *(_DWORD *)(v6 + 388) = v7;
  v9 = 0;
  if ( v8 )
  {
    do
      *(_DWORD *)(*(_DWORD *)(v6 + 388) + 4 * v9++) = 0;
    while ( v9 < *(_DWORD *)(v6 + 384) );
  }
  *(_DWORD *)(v6 + 376) = _num_portals;
  v10 = operator new[](4 * _num_portals);
  v11 = *(_DWORD *)(v6 + 376);
  *(_DWORD *)(v6 + 380) = v10;
  v12 = 0;
  if ( v11 )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(v6 + 380) + 4 * v12) = _portals[v12];
      ++v12;
    }
    while ( v12 < *(_DWORD *)(v6 + 376) );
  }
  if ( CPhysicsObj::InitObjectEnd((CPhysicsObj *)v6) )
  {
    result = (CBuildingObj *)v6;
  }
  else
  {
LABEL_17:
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    result = 0;
  }
  return result;
}

//----- (006B54B0) --------------------------------------------------------  // acclient.c:719218
void __thiscall CBuildingObj::~CBuildingObj(CBuildingObj *this)
{
  CBuildingObj *v1; // esi@1
  CBldPortal **v2; // eax@1
  bool v3; // zf@3
  unsigned int i; // edi@4
  CPartCell *v5; // ecx@5

  v1 = this;
  v2 = this->portals;
  this->vfptr = (HashBaseData<unsigned long>Vtbl *)&CBuildingObj::vftable;
  if ( v2 )
  {
    operator delete[](v2);
    v1->portals = 0;
  }
  v3 = v1->leaf_cells == 0;
  v1->num_portals = 0;
  if ( !v3 )
  {
    for ( i = 0; i < v1->num_leaves; ++i )
    {
      v5 = v1->leaf_cells[i];
      if ( v5 )
        ((void (__stdcall *)(signed int))v5->vfptr->~CPartCell)(1);
    }
    operator delete[](v1->leaf_cells);
    v1->leaf_cells = 0;
  }
  v1->num_leaves = 0;
  v1->num_shadow = 0;
  operator delete[](v1->shadow_list.data);
  v1->shadow_list.data = 0;
  CPhysicsObj::~CPhysicsObj((CPhysicsObj *)&v1->vfptr);
}
// 8063A0: using guessed type int (__thiscall *CBuildingObj::vftable)(void *, char);

//----- (006B5550) --------------------------------------------------------  // acclient.c:719256
void __thiscall CBuildingObj::add_to_cell(CBuildingObj *this, CSortCell *new_cell)
{
  CBuildingObj *v2; // esi@1

  v2 = this;
  CSortCell::add_building(new_cell, this);
  CPhysicsObj::set_cell_id((CPhysicsObj *)&v2->vfptr, new_cell->m_DID.id);
  v2->cell = (CObjCell *)new_cell;
}

//----- (006B5580) --------------------------------------------------------  // acclient.c:719267
CBuildingObj *__thiscall CBuildingObj::scalar_deleting_destructor(CBuildingObj *this, unsigned int a2)
{
  CBuildingObj *v2; // esi@1

  v2 = this;
  CBuildingObj::~CBuildingObj(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006B55A0) --------------------------------------------------------  // acclient.c:719279
CPhysicsObj *__thiscall CBuildingObj::get_object(CBuildingObj *this, const unsigned int obj_iid)
{
  CBuildingObj *v2; // ebx@1
  unsigned int v3; // edi@1
  CBldPortal *v4; // ecx@2
  CEnvCell *v5; // eax@3
  CPhysicsObj *v6; // esi@4
  CPhysicsObj *result; // eax@8
  PackableHashTable<unsigned long,int> visited_cells; // [sp+Ch] [bp-14h]@1

  v2 = this;
  visited_cells.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,int>::vftable;
  visited_cells.m_fThrowawayDuplicateKeysOnUnPack = 0;
  visited_cells._buckets = 0;
  visited_cells._table_size = 32;
  visited_cells._currNum = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&visited_cells);
  v3 = 0;
  if ( v2->num_portals )
  {
    while ( 1 )
    {
      v4 = v2->portals[v3];
      if ( v4 )
      {
        v5 = (CEnvCell *)CBldPortal::GetOtherCell(v4);
        if ( v5 )
        {
          v6 = CEnvCell::recursively_get_object(v5, obj_iid, &visited_cells);
          if ( v6 )
            break;
        }
      }
      ++v3;
      if ( v3 >= v2->num_portals )
        goto LABEL_6;
    }
    visited_cells.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,int>::vftable;
    PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&visited_cells);
    if ( visited_cells._buckets )
      operator delete[](visited_cells._buckets);
    result = v6;
  }
  else
  {
LABEL_6:
    visited_cells.vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,int>::vftable;
    PackableHashTable<unsigned long,unsigned long>::EmptyContents((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)&visited_cells);
    if ( visited_cells._buckets )
      operator delete[](visited_cells._buckets);
    result = 0;
  }
  return result;
}
// 7E4430: using guessed type int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char);

//----- (00723DE0) --------------------------------------------------------  // acclient.c:821636
void sub_723DE0()
{
  flt_8FA9DC = 1000.0 + 1.0;
}

//----- (00723E00) --------------------------------------------------------  // acclient.c:821642
void sub_723E00()
{
  flt_8FA9E0 = 24.0 * 8.0;
}

//----- (00723E20) --------------------------------------------------------  // acclient.c:821648
void sub_723E20()
{
  flt_8FA9E4 = 24.0 * 0.5;
}

//----- (00723E40) --------------------------------------------------------  // acclient.c:821654
void sub_723E40()
{
  flt_8FA9EC = 0.00019999999 * 3.0 + 0.1;
}

//----- (00723E60) --------------------------------------------------------  // acclient.c:821660
void _E99_52()
{
  dbl_8FA9F0 = 1.0 / 30.0;
}

//----- (00723E80) --------------------------------------------------------  // acclient.c:821666
void _E101_50()
{
  dbl_8FA9F8 = 1.0 / 5.0;
}

//----- (00723EA0) --------------------------------------------------------  // acclient.c:821672
int _E107_52()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_50;
  dword_8FAA00 = LOWEST_DATA_RATE_50;
  return result;
}

//----- (00723EB0) --------------------------------------------------------  // acclient.c:821682
int sub_723EB0()
{
  return atexit(nullsub_1083);
}

//----- (00723EC0) --------------------------------------------------------  // acclient.c:821688
int sub_723EC0()
{
  return atexit(_E113_94);
}

//----- (00723ED0) --------------------------------------------------------  // acclient.c:821694
int sub_723ED0()
{
  return atexit(_E116_86);
}

//----- (00723EE0) --------------------------------------------------------  // acclient.c:821700
int sub_723EE0()
{
  return atexit(nullsub_1082);
}

