/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Scene
   Object     : PORTAL\region\Scene.obj
   Functions  : 22
   Addresses  : 005A5BB0 - 0070D320 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005A5BB0) --------------------------------------------------------  // acclient.c:462604
void __thiscall ObjectDesc::Place(ObjectDesc *this, unsigned int ix, unsigned int iy, unsigned int iq, AC1Legacy::Vector3 *obj_loc)
{
  AC1Legacy::Vector3 *v5; // esi@1
  double v6; // st7@5
  double v7; // st6@7
  float obj_loca; // [sp+1Ch] [bp+10h]@2

  v5 = obj_loc;
  obj_loc->x = this->base_loc.m_fOrigin.x;
  obj_loc->y = this->base_loc.m_fOrigin.y;
  obj_loc->z = this->base_loc.m_fOrigin.z;
  if ( this->displace_x <= 0.0 )
    obj_loca = obj_loc->x;
  else
    obj_loca = (double)(1813693831 * iy - (iq + 45773) * (1360117743 * iy * ix + 1888038839) - 1109124029 * ix)
             * 2.3283064e-10
             * this->displace_x
             + obj_loc->x;
  if ( this->displace_y <= 0.0 )
    v6 = v5->y;
  else
    v6 = (double)(1813693831 * iy - (iq + 72719) * (1360117743 * iy * ix + 1888038839) - 1109124029 * ix)
       * 2.3283064e-10
       * this->displace_y
       + v5->y;
  v7 = (double)(1813693831 * iy - ix * (1870387557 * iy + 1109124029) - 402451965) * 2.3283064e-10;
  if ( v7 >= 0.25 )
  {
    if ( v7 >= 0.5 )
    {
      if ( v7 >= 0.75 )
      {
        v5->x = v6;
        v5->y = -obj_loca;
      }
      else
      {
        v5->x = -obj_loca;
        v5->y = -v6;
      }
    }
    else
    {
      v5->x = -v6;
      v5->y = obj_loca;
    }
  }
  else
  {
    v5->y = v6;
    v5->x = obj_loca;
  }
}

//----- (005A5D50) --------------------------------------------------------  // acclient.c:462659
void __thiscall ObjectDesc::GetObjFrame(ObjectDesc *this, unsigned int x, unsigned int y, unsigned int k, AC1Legacy::Vector3 *loc, Frame *obj_frame)
{
  ObjectDesc *v6; // esi@1
  float degrees; // ST00_4@2

  v6 = this;
  Frame::operator=((int)obj_frame, (int)&this->base_loc);
  obj_frame->m_fOrigin = *loc;
  if ( v6->max_rot > 0.0 )
  {
    degrees = (double)(1813693831 * y - (k + 63127) * (1360117743 * y * x + 1888038839) - 1109124029 * x)
            * 2.3283064e-10
            * v6->max_rot;
    Frame::set_heading(obj_frame, degrees);
  }
}

//----- (005A5DF0) --------------------------------------------------------  // acclient.c:462677
void __thiscall ObjectDesc::ObjectDesc(ObjectDesc *this)
{
  ObjectDesc *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->base_loc;
  v1->obj_id.id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  LODWORD(v1->displace_x) = 0;
  LODWORD(v1->displace_y) = 0;
  LODWORD(v1->max_rot) = 0;
  LODWORD(v1->min_slope) = 0;
  v1->align = 0;
  v1->orient = 0;
  v1->weenie_obj = 0;
  LODWORD(v1->freq) = 1065353216;
  LODWORD(v1->min_scale) = 1065353216;
  LODWORD(v1->max_scale) = 1065353216;
  LODWORD(v1->max_slope) = 1119092736;
}

//----- (005A5E50) --------------------------------------------------------  // acclient.c:462707
void __thiscall ObjectDesc::ObjAlign(ObjectDesc *this, Plane *plane, AC1Legacy::Vector3 *loc, Frame *obj_frame)
{
  float degrees; // ST00_4@1
  AC1Legacy::Vector3 v5; // [sp+8h] [bp-Ch]@1

  Frame::operator=((int)obj_frame, (int)&this->base_loc);
  obj_frame->m_fOrigin = *loc;
  v5.x = -plane->N.x;
  v5.y = -plane->N.y;
  v5.z = -plane->N.z;
  degrees = AC1Legacy::Vector3::get_heading(&v5);
  Frame::set_heading(obj_frame, degrees);
}

//----- (005A5EC0) --------------------------------------------------------  // acclient.c:462722
void __thiscall Scene::Scene(Scene *this, IDClass<_tagDataID,32,0> id)
{
  Scene *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, id);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->num_objects = 0;
  v2->objects = 0;
  v2->vfptr = (InterfaceVtbl *)&Scene::vftable;
  v2->vfptr = (PackObjVtbl *)&Scene::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5968: using guessed type void *Scene::vftable;
// 7E5980: using guessed type __int32 (__stdcall *Scene::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (005A5EF0) --------------------------------------------------------  // acclient.c:462739
signed int Scene::GetDBOType()
{
  return 27;
}

//----- (005A5F00) --------------------------------------------------------  // acclient.c:462745
Scene *__thiscall Scene::vector_deleting_destructor(Scene *this, unsigned int a2)
{
  return Scene::scalar_deleting_destructor((Scene *)((char *)this - 48), a2);
}

//----- (005A5F10) --------------------------------------------------------  // acclient.c:462751
void *__thiscall ObjectDesc::vector_deleting_destructor(ObjectDesc *this, unsigned int a2)
{
  char v2; // bl@1
  ObjectDesc *v3; // esi@1
  int v4; // ecx@2
  void *v5; // ebp@2
  int v6; // eax@2
  int v7; // ecx@2
  int v8; // esi@3
  void *result; // eax@8

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1].weenie_obj;
    v5 = &v3[-1].weenie_obj;
    v6 = (int)&v3[v4];
    v7 = v4 - 1;
    if ( v7 >= 0 )
    {
      v8 = v7 + 1;
      do
      {
        v6 -= 112;
        --v8;
        *(_DWORD *)v6 = stru_8ED994.id;
        *(_DWORD *)(v6 + 68) = 1065353216;
        *(_DWORD *)(v6 + 72) = 0;
        *(_DWORD *)(v6 + 76) = 0;
        *(_DWORD *)(v6 + 80) = 1065353216;
        *(_DWORD *)(v6 + 84) = 1065353216;
        *(_DWORD *)(v6 + 100) = 0;
        *(_DWORD *)(v6 + 88) = 0;
        *(_DWORD *)(v6 + 104) = 0;
        *(_DWORD *)(v6 + 92) = 0;
        *(_DWORD *)(v6 + 96) = 1119092736;
        *(_DWORD *)(v6 + 108) = 0;
      }
      while ( v8 );
      v2 = a2;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    this->obj_id.id = stru_8ED994.id;
    LODWORD(this->freq) = 1065353216;
    LODWORD(this->displace_x) = 0;
    LODWORD(this->displace_y) = 0;
    LODWORD(this->min_scale) = 1065353216;
    LODWORD(this->max_scale) = 1065353216;
    this->align = 0;
    LODWORD(this->max_rot) = 0;
    this->orient = 0;
    LODWORD(this->min_slope) = 0;
    LODWORD(this->max_slope) = 1119092736;
    this->weenie_obj = 0;
    if ( a2 & 1 )
      operator delete(this);
    result = v3;
  }
  return result;
}

//----- (005A5FF0) --------------------------------------------------------  // acclient.c:462819
void __thiscall ObjectDesc::Pack(ObjectDesc *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  ObjectDesc *v4; // ebx@1
  char *v5; // eax@4
  int v6; // edi@4
  int v7; // edi@5
  char *v8; // eax@5
  int v9; // edi@6
  char *v10; // eax@6
  int v11; // edi@7
  char *v12; // eax@7
  int v13; // edi@8
  char *v14; // eax@8
  int v15; // edi@9
  char *v16; // eax@9
  int v17; // edi@10
  char *v18; // eax@10
  int v19; // edi@11
  char *v20; // eax@11
  char *v21; // eax@12
  int v22; // edi@12
  char *v23; // eax@13

  v3 = size;
  v4 = this;
  if ( size >= 4 )
  {
    *(_DWORD *)*addr = this->obj_id.id;
    *addr = (char *)*addr + 4;
    v3 = size - 4;
  }
  Frame::Pack(&this->base_loc, addr, v3);
  if ( v3 >= 4 )
  {
    *(float *)*addr = v4->freq;
    v5 = (char *)*addr + 4;
    v6 = v3 - 4;
    *addr = v5;
    if ( (unsigned int)v6 >= 4 )
    {
      v7 = v6 - 4;
      *(float *)v5 = v4->displace_x;
      v8 = (char *)*addr + 4;
      *addr = v8;
      if ( (unsigned int)v7 >= 4 )
      {
        v9 = v7 - 4;
        *(float *)v8 = v4->displace_y;
        v10 = (char *)*addr + 4;
        *addr = v10;
        if ( (unsigned int)v9 >= 4 )
        {
          v11 = v9 - 4;
          *(float *)v10 = v4->min_scale;
          v12 = (char *)*addr + 4;
          *addr = v12;
          if ( (unsigned int)v11 >= 4 )
          {
            v13 = v11 - 4;
            *(float *)v12 = v4->max_scale;
            v14 = (char *)*addr + 4;
            *addr = v14;
            if ( (unsigned int)v13 >= 4 )
            {
              v15 = v13 - 4;
              *(float *)v14 = v4->max_rot;
              v16 = (char *)*addr + 4;
              *addr = v16;
              if ( (unsigned int)v15 >= 4 )
              {
                v17 = v15 - 4;
                *(float *)v16 = v4->min_slope;
                v18 = (char *)*addr + 4;
                *addr = v18;
                if ( (unsigned int)v17 >= 4 )
                {
                  v19 = v17 - 4;
                  *(float *)v18 = v4->max_slope;
                  v20 = (char *)*addr + 4;
                  *addr = v20;
                  if ( (unsigned int)v19 >= 4 )
                  {
                    *(_DWORD *)v20 = v4->align;
                    v21 = (char *)*addr + 4;
                    v22 = v19 - 4;
                    *addr = v21;
                    if ( (unsigned int)v22 >= 4 )
                    {
                      *(_DWORD *)v21 = v4->orient;
                      v23 = (char *)*addr + 4;
                      *addr = v23;
                      if ( (unsigned int)(v22 - 4) >= 4 )
                      {
                        *(_DWORD *)v23 = v4->weenie_obj;
                        *addr = (char *)*addr + 4;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//----- (005A6110) --------------------------------------------------------  // acclient.c:462929
int __thiscall ObjectDesc::UnPack(ObjectDesc *this, void **addr, unsigned int size)
{
  unsigned int v3; // edi@1
  ObjectDesc *v4; // ebx@1
  unsigned int v5; // ecx@2
  int result; // eax@3
  char *v7; // eax@5
  int v8; // edi@5
  char *v9; // eax@6
  int v10; // edi@6
  char *v11; // eax@7
  int v12; // edi@7
  char *v13; // eax@8
  int v14; // edi@8
  char *v15; // eax@9
  int v16; // edi@9
  char *v17; // eax@10
  int v18; // edi@10
  char *v19; // eax@11
  int v20; // edi@11
  char *v21; // eax@12
  int v22; // edi@12
  char *v23; // eax@13
  int v24; // edi@13
  char *v25; // eax@14

  v3 = size;
  v4 = this;
  if ( size >= 4 )
  {
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v3 = size - 4;
    v4->obj_id.id = v5;
  }
  result = Frame::UnPack(&v4->base_loc, addr, v3);
  if ( result )
  {
    if ( v3 >= 4 )
    {
      LODWORD(v4->freq) = *(_DWORD *)*addr;
      v7 = (char *)*addr + 4;
      v8 = v3 - 4;
      *addr = v7;
      if ( (unsigned int)v8 >= 4 )
      {
        LODWORD(v4->displace_x) = *(_DWORD *)v7;
        v9 = (char *)*addr + 4;
        v10 = v8 - 4;
        *addr = v9;
        if ( (unsigned int)v10 >= 4 )
        {
          LODWORD(v4->displace_y) = *(_DWORD *)v9;
          v11 = (char *)*addr + 4;
          v12 = v10 - 4;
          *addr = v11;
          if ( (unsigned int)v12 >= 4 )
          {
            LODWORD(v4->min_scale) = *(_DWORD *)v11;
            v13 = (char *)*addr + 4;
            v14 = v12 - 4;
            *addr = v13;
            if ( (unsigned int)v14 >= 4 )
            {
              LODWORD(v4->max_scale) = *(_DWORD *)v13;
              v15 = (char *)*addr + 4;
              v16 = v14 - 4;
              *addr = v15;
              if ( (unsigned int)v16 >= 4 )
              {
                LODWORD(v4->max_rot) = *(_DWORD *)v15;
                v17 = (char *)*addr + 4;
                v18 = v16 - 4;
                *addr = v17;
                if ( (unsigned int)v18 >= 4 )
                {
                  LODWORD(v4->min_slope) = *(_DWORD *)v17;
                  v19 = (char *)*addr + 4;
                  v20 = v18 - 4;
                  *addr = v19;
                  if ( (unsigned int)v20 >= 4 )
                  {
                    LODWORD(v4->max_slope) = *(_DWORD *)v19;
                    v21 = (char *)*addr + 4;
                    v22 = v20 - 4;
                    *addr = v21;
                    if ( (unsigned int)v22 >= 4 )
                    {
                      v4->align = *(_DWORD *)v21;
                      v23 = (char *)*addr + 4;
                      v24 = v22 - 4;
                      *addr = v23;
                      if ( (unsigned int)v24 >= 4 )
                      {
                        v4->orient = *(_DWORD *)v23;
                        v25 = (char *)*addr + 4;
                        *addr = v25;
                        if ( (unsigned int)(v24 - 4) >= 4 )
                        {
                          v4->weenie_obj = *(_DWORD *)v25;
                          *addr = (char *)*addr + 4;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    result = 1;
  }
  return result;
}

//----- (005A6240) --------------------------------------------------------  // acclient.c:463047
void __thiscall Scene::Destroy(Scene *this)
{
  Scene *v1; // esi@1
  ObjectDesc *v2; // ecx@1

  v1 = this;
  v2 = this->objects;
  if ( v2 )
  {
    ObjectDesc::vector_deleting_destructor(v2, 3u);
    v1->objects = 0;
  }
  v1->num_objects = 0;
}

//----- (005A6270) --------------------------------------------------------  // acclient.c:463063
unsigned int __thiscall Scene::Pack(Scene *this, void **addr, unsigned int size)
{
  Scene *v3; // esi@1
  int v4; // eax@1
  unsigned int v5; // ecx@1
  int v6; // eax@2
  unsigned int v7; // eax@3
  unsigned int v8; // edi@6
  int v9; // ebx@7
  unsigned int result; // eax@10
  int v11; // [sp+Ch] [bp-4h]@1

  v3 = this;
  v4 = *((_DWORD *)&this->m_bLoaded + 1);
  v5 = 4;
  v11 = 4;
  if ( v4 )
  {
    v6 = 76 * v4;
    v11 = v6 + 4;
    v5 = v6 + 4;
  }
  v7 = size;
  if ( size < v5 )
    goto LABEL_14;
  if ( size >= 4 )
  {
    *(_DWORD *)*addr = *((_DWORD *)&v3->m_bLoaded + 1);
    v7 = size - 4;
    *addr = (char *)*addr + 4;
    size -= 4;
  }
  v8 = 0;
  if ( *((_DWORD *)&v3->m_bLoaded + 1) )
  {
    v9 = 0;
    while ( 1 )
    {
      ObjectDesc::Pack((ObjectDesc *)(v9 + LODWORD(v3->m_timeStamp)), addr, v7);
      ++v8;
      v9 += 112;
      if ( v8 >= *((_DWORD *)&v3->m_bLoaded + 1) )
        break;
      v7 = size;
    }
    result = v11;
  }
  else
  {
LABEL_14:
    result = v5;
  }
  return result;
}

//----- (005A6300) --------------------------------------------------------  // acclient.c:463119
int __thiscall Scene::UnPack(Scene *this, void **addr, unsigned int size)
{
  Scene *v3; // esi@1
  int result; // eax@2
  int v5; // edi@5
  void *v6; // eax@5
  int v7; // ebx@6
  int v8; // eax@8
  unsigned int v9; // edi@8
  int v10; // ebx@9

  v3 = this;
  if ( (char *)*addr + size > (char *)*addr + 4 )
  {
    (*(void (__thiscall **)(DBObj **))((void (__thiscall **)(_DWORD))&this[-1].m_pNext[1].m_bLoaded + 1))(&this[-1].m_pNext);
    if ( size >= 4 )
    {
      *((_DWORD *)&v3->m_bLoaded + 1) = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      size -= 4;
    }
    v5 = *((_DWORD *)&v3->m_bLoaded + 1);
    v6 = operator new[](112 * *((_DWORD *)&v3->m_bLoaded + 1) + 4);
    if ( v6 )
    {
      v7 = (int)((char *)v6 + 4);
      *(_DWORD *)v6 = v5;
      vector_constructor_iterator((char *)v6 + 4, 0x70u, v5, (void *(__thiscall *)(void *))ObjectDesc::ObjectDesc);
    }
    else
    {
      v7 = 0;
    }
    v8 = *((_DWORD *)&v3->m_bLoaded + 1);
    v9 = 0;
    LODWORD(v3->m_timeStamp) = v7;
    if ( v8 )
    {
      v10 = 0;
      do
      {
        ObjectDesc::UnPack((ObjectDesc *)(v10 + LODWORD(v3->m_timeStamp)), addr, size);
        ++v9;
        v10 += 112;
      }
      while ( v9 < *((_DWORD *)&v3->m_bLoaded + 1) );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005A63B0) --------------------------------------------------------  // acclient.c:463176
Scene *__thiscall Scene::scalar_deleting_destructor(Scene *this, unsigned int a2)
{
  Scene *v2; // esi@1
  ObjectDesc *v3; // ecx@1

  v2 = this;
  v3 = this->objects;
  v2->vfptr = (InterfaceVtbl *)&Scene::vftable;
  v2->vfptr = (PackObjVtbl *)&Scene::vftable;
  if ( v3 )
  {
    ObjectDesc::vector_deleting_destructor(v3, 3u);
    v2->objects = 0;
  }
  v2->num_objects = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E5968: using guessed type void *Scene::vftable;
// 7E5980: using guessed type __int32 (__stdcall *Scene::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0070D280) --------------------------------------------------------  // acclient.c:799971
int sub_70D280()
{
  return atexit(_E74_89);
}

//----- (0070D290) --------------------------------------------------------  // acclient.c:799977
int _E76_73()
{
  return atexit(nullsub_1455);
}

//----- (0070D2A0) --------------------------------------------------------  // acclient.c:799983
int _E79_67()
{
  return atexit(_E80_66);
}

//----- (0070D2B0) --------------------------------------------------------  // acclient.c:799989
void _E98_18()
{
  LODWORD(dword_8ED998) = 1053364187;
}

//----- (0070D2C0) --------------------------------------------------------  // acclient.c:799995
void sub_70D2C0()
{
  flt_8ED99C = 1000.0 + 1.0;
}

//----- (0070D2E0) --------------------------------------------------------  // acclient.c:800001
void _E102_36()
{
  flt_8ED9A0 = 24.0 * 8.0;
}

//----- (0070D300) --------------------------------------------------------  // acclient.c:800007
void _E104_18()
{
  flt_8ED9A4 = 24.0 * 0.5;
}

//----- (0070D320) --------------------------------------------------------  // acclient.c:800013
int sub_70D320()
{
  return atexit(nullsub_1453);
}

