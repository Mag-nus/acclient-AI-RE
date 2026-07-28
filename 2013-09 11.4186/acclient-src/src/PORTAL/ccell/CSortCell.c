/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSortCell
   Object     : PORTAL\ccell\CSortCell.obj
   Functions  : 20
   Addresses  : 00533FB0 - 006FF890 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00533FB0) --------------------------------------------------------  // acclient.c:356039
void __thiscall CSortCell::CSortCell(CSortCell *this)
{
  CSortCell *v1; // esi@1

  v1 = this;
  CObjCell::CObjCell((CObjCell *)&this->vfptr);
  v1->vfptr = (InterfaceVtbl *)&CSortCell::vftable;
  v1->vfptr = (PackObjVtbl *)&CSortCell::vftable;
  v1->vfptr = (CPartCellVtbl *)&CSortCell::vftable;
  v1->building = 0;
}
// 7C94E8: using guessed type void (__thiscall *CSortCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts);
// 7C94F4: using guessed type void *CSortCell::vftable;
// 7C9508: using guessed type __int32 (__stdcall *CSortCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00533FE0) --------------------------------------------------------  // acclient.c:356055
void __thiscall CSortCell::~CSortCell(CSortCell *this)
{
  this->vfptr = (InterfaceVtbl *)&CSortCell::vftable;
  this->vfptr = (PackObjVtbl *)&CSortCell::vftable;
  this->vfptr = (CPartCellVtbl *)&CSortCell::vftable;
  CObjCell::~CObjCell((CObjCell *)&this->vfptr);
}
// 7C94E8: using guessed type void (__thiscall *CSortCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts);
// 7C94F4: using guessed type void *CSortCell::vftable;
// 7C9508: using guessed type __int32 (__stdcall *CSortCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00534000) --------------------------------------------------------  // acclient.c:356067
BOOL __thiscall CSortCell::has_building(CSortCell *this)
{
  return this->building != 0;
}

//----- (00534030) --------------------------------------------------------  // acclient.c:356073
void __thiscall CSortCell::add_building(CSortCell *this, CBuildingObj *_object)
{
  if ( !this->building )
    this->building = _object;
}

//----- (00534050) --------------------------------------------------------  // acclient.c:356080
void __thiscall CSortCell::remove_building(CSortCell *this, CBuildingObj *_object)
{
  this->building = 0;
}

//----- (00534060) --------------------------------------------------------  // acclient.c:356086
void __thiscall CSortCell::find_transit_cells(CSortCell *this, Position *p, const unsigned int num_sphere, CSphere *sphere, CELLARRAY *cell_array, SPHEREPATH *path)
{
  CBuildingObj *v6; // ecx@1

  v6 = this->building;
  if ( v6 )
    CBuildingObj::find_building_transit_cells(v6, p, num_sphere, sphere, cell_array, path);
}

//----- (00534080) --------------------------------------------------------  // acclient.c:356096
void __thiscall CSortCell::find_transit_cells(CSortCell *this, const unsigned int num_parts, CPhysicsPart **parts, CELLARRAY *cell_array)
{
  CBuildingObj *v4; // ecx@1

  v4 = this->building;
  if ( v4 )
    CBuildingObj::find_building_transit_cells(v4, num_parts, parts, cell_array);
}

//----- (005340A0) --------------------------------------------------------  // acclient.c:356106
signed int __thiscall CSortCell::find_collisions(CSortCell *this, CTransition *transition)
{
  CBuildingObj *v2; // ecx@1
  signed int result; // eax@2

  v2 = this->building;
  if ( v2 )
    result = CBuildingObj::find_building_collisions(v2, transition);
  else
    result = 1;
  return result;
}

//----- (005340C0) --------------------------------------------------------  // acclient.c:356120
CPhysicsObj *__thiscall CSortCell::get_object(CSortCell *this, const unsigned int obj_iid)
{
  CSortCell *v2; // esi@1
  CPhysicsObj *result; // eax@1
  CBuildingObj *v4; // ecx@2

  v2 = this;
  result = CObjCell::get_object((CObjCell *)&this->vfptr, obj_iid);
  if ( !result )
  {
    v4 = v2->building;
    if ( v4 )
      result = CBuildingObj::get_object(v4, obj_iid);
  }
  return result;
}

//----- (005340F0) --------------------------------------------------------  // acclient.c:356138
CSortCell *__thiscall CSortCell::vector_deleting_destructor(CSortCell *this, unsigned int a2)
{
  return CSortCell::vector_deleting_destructor((CSortCell *)((char *)this - 48), a2);
}

//----- (00534100) --------------------------------------------------------  // acclient.c:356144
CSortCell *__thiscall CSortCell::vector_deleting_destructor(CSortCell *this, unsigned int a2)
{
  return CSortCell::vector_deleting_destructor((CSortCell *)((char *)this - 56), a2);
}

//----- (00534110) --------------------------------------------------------  // acclient.c:356150
CSortCell *__thiscall CSortCell::vector_deleting_destructor(CSortCell *this, unsigned int a2)
{
  CSortCell *v2; // esi@1

  v2 = this;
  this->vfptr = (InterfaceVtbl *)&CSortCell::vftable;
  this->vfptr = (PackObjVtbl *)&CSortCell::vftable;
  this->vfptr = (CPartCellVtbl *)&CSortCell::vftable;
  CObjCell::~CObjCell((CObjCell *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C94E8: using guessed type void (__thiscall *CSortCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts);
// 7C94F4: using guessed type void *CSortCell::vftable;
// 7C9508: using guessed type __int32 (__stdcall *CSortCell::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (006FF7C0) --------------------------------------------------------  // acclient.c:787514
int _E77_5()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_19;
  INITIAL_MAX_DATA_RATE_91 = LOWEST_DATA_RATE_19;
  return result;
}

//----- (006FF7D0) --------------------------------------------------------  // acclient.c:787524
void sub_6FF7D0()
{
  flt_844E88 = 1000.0 + 1.0;
}

//----- (006FF7F0) --------------------------------------------------------  // acclient.c:787530
void _E99_32()
{
  flt_844E8C = 24.0 * 8.0;
}

//----- (006FF810) --------------------------------------------------------  // acclient.c:787536
void _E101_29()
{
  flt_844E90 = 24.0 * 0.5;
}

//----- (006FF830) --------------------------------------------------------  // acclient.c:787542
void sub_6FF830()
{
  flt_844E98 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FF850) --------------------------------------------------------  // acclient.c:787548
void _E105_35()
{
  dbl_844EA0 = 1.0 / 30.0;
}

//----- (006FF870) --------------------------------------------------------  // acclient.c:787554
void _E107_28()
{
  dbl_844EA8 = 1.0 / 5.0;
}

//----- (006FF890) --------------------------------------------------------  // acclient.c:787560
int sub_6FF890()
{
  return atexit(nullsub_1161);
}

