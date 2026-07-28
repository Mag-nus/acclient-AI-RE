/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Palette
   Object     : PORTAL\image\Palette.obj
   Functions  : 28
   Addresses  : 00526890 - 0076BDF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00526890) --------------------------------------------------------  // acclient.c:342065
signed int Palette::GetDBOType()
{
  return 10;
}

//----- (0053DF90) --------------------------------------------------------  // acclient.c:364968
void __thiscall Palette::Destroy(Palette *this)
{
  Palette *v1; // esi@1

  v1 = this;
  if ( this->ARGB )
  {
    operator delete[](this->ARGB);
    v1->ARGB = 0;
  }
}

//----- (0053DFB0) --------------------------------------------------------  // acclient.c:364981
void __cdecl Palette::releasePalette(Palette *pal)
{
  struct Palette *v1; // ecx@2
  bool v2; // zf@3

  if ( pal )
  {
    v1 = Palette::solid_color_palette;
    if ( pal == Palette::solid_color_palette )
    {
      v2 = Palette::solid_color_palette->m_numLinks-- == 1;
      if ( v2 )
      {
        ((void (__stdcall *)(signed int))v1->vfptr[1].IUnknown_QueryInterface)(1);
        if ( Palette::solid_color_palette )
          ((void (__stdcall *)(_DWORD))Palette::solid_color_palette->vfptr[1].IUnknown_QueryInterface)(1);
        Palette::solid_color_palette = 0;
        Palette::curr_solid_index = -1;
      }
    }
    else if ( pal->m_pMaintainer )
    {
      pal->vfptr->Release((Interface *)pal);
    }
    else
    {
      v2 = pal->m_numLinks-- == 1;
      if ( v2 )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))pal->vfptr[1].IUnknown_QueryInterface)(pal, 1);
        ((void (__thiscall *)(_DWORD, _DWORD))pal->vfptr[1].IUnknown_QueryInterface)(pal, 1);
      }
    }
  }
}
// 81E908: using guessed type int Palette::curr_solid_index;
// 845748: using guessed type struct Palette *Palette::solid_color_palette;

//----- (0053E030) --------------------------------------------------------  // acclient.c:365020
Palette *__cdecl Palette::copyRef(Palette *palette)
{
  if ( palette )
    palette->vfptr->AddRef((Interface *)palette);
  return palette;
}

//----- (0053E050) --------------------------------------------------------  // acclient.c:365028
unsigned int __thiscall Palette::get_color32(Palette *this, unsigned int color_index)
{
  return this->ARGB[color_index];
}

//----- (0053E060) --------------------------------------------------------  // acclient.c:365034
char __thiscall Palette::InitLoad(Palette *this)
{
  Palette *v1; // esi@1
  void *v2; // edi@3
  void *v3; // edx@3
  signed int v4; // eax@3
  unsigned int v5; // ecx@4

  v1 = this;
  if ( DBCache::IsRunTime() && v1->num_colors == 256 )
  {
    v2 = v1->ARGB;
    v1->num_colors = 2048;
    v1->ARGB = (unsigned int *)operator new[](0x2000u);
    v3 = v2;
    v4 = 3;
    do
    {
      v5 = *(_DWORD *)v3;
      v1->ARGB[v4 - 3] = *(_DWORD *)v3;
      v1->ARGB[v4 - 2] = v5;
      v1->ARGB[v4 - 1] = v5;
      v1->ARGB[v4] = v5;
      v1->ARGB[v4 + 1] = v5;
      v1->ARGB[v4 + 2] = v5;
      v1->ARGB[v4 + 3] = v5;
      v1->ARGB[v4 + 4] = v5;
      v4 += 8;
      v3 = (char *)v3 + 4;
    }
    while ( (unsigned int)(v4 * 4) < 0x200C );
    operator delete[](v2);
  }
  return 1;
}

//----- (0053E100) --------------------------------------------------------  // acclient.c:365071
void __thiscall Palette::Palette(Palette *this, int total_num_colors)
{
  Palette *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, stru_84575C);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&Palette::vftable;
  v2->vfptr = (PackObjVtbl *)&Palette::vftable;
  v2->ARGB = 0;
  LODWORD(v2->min_lighting) = 1036831949;
  v2->num_colors = total_num_colors;
  v2->ARGB = (unsigned int *)operator new[](4 * total_num_colors);
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C9C34: using guessed type void *Palette::vftable;
// 7C9C48: using guessed type __int32 (__stdcall *Palette::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0053E150) --------------------------------------------------------  // acclient.c:365090
Palette *__thiscall Palette::vector_deleting_destructor(Palette *this, unsigned int a2)
{
  return Palette::scalar_deleting_destructor((Palette *)((char *)this - 48), a2);
}

//----- (0053E160) --------------------------------------------------------  // acclient.c:365096
int __thiscall Palette::Modify(Palette *this, IDClass<_tagDataID,32,0> subID, unsigned int offset, unsigned int numcolors)
{
  Palette *v4; // edi@1
  int result; // eax@2
  unsigned int v6; // esi@4
  QualifiedDataID *v7; // eax@5
  int v8; // eax@5
  unsigned int i; // edx@6
  QualifiedDataID v10; // [sp+4h] [bp-8h]@5

  v4 = this;
  if ( this->m_pMaintainer || subID.id == stru_84575C.id )
  {
    result = 0;
  }
  else
  {
    v6 = offset + numcolors;
    if ( offset + numcolors <= this->num_colors
      && (QualifiedDataID::QualifiedDataID(&v10, subID, 0xAu), (v8 = DBObj::Get(v7)) != 0) )
    {
      for ( i = offset; i < v6; ++i )
        v4->ARGB[i] = *(_DWORD *)(*(_DWORD *)(v8 + 64) + 4 * i);
      (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0053E1F0) --------------------------------------------------------  // acclient.c:365131
int __thiscall Palette::Modify(Palette *this, Subpalette *_subs)
{
  Subpalette *v2; // esi@1
  Palette *v3; // edi@1
  int result; // eax@4

  v2 = _subs;
  v3 = this;
  if ( _subs )
  {
    while ( Palette::Modify(v3, v2->subID, v2->offset, v2->numcolors) )
    {
      v2 = v2->next;
      if ( !v2 )
        goto LABEL_4;
    }
    result = 0;
  }
  else
  {
LABEL_4:
    result = 1;
  }
  return result;
}

//----- (0053E230) --------------------------------------------------------  // acclient.c:365158
int __thiscall Palette::Modify(Palette *this, int _numSubs, Subpalette *_subs)
{
  int v3; // edi@1
  Palette *v4; // ebp@1
  char *v5; // esi@2
  int result; // eax@5

  v3 = 0;
  v4 = this;
  if ( _numSubs <= 0 )
  {
LABEL_5:
    result = 1;
  }
  else
  {
    v5 = (char *)&_subs->offset;
    while ( Palette::Modify(v4, *((IDClass<_tagDataID,32,0> *)v5 - 1), *(_DWORD *)v5, *((_DWORD *)v5 + 1)) )
    {
      ++v3;
      v5 += 24;
      if ( v3 >= _numSubs )
        goto LABEL_5;
    }
    result = 0;
  }
  return result;
}

//----- (0053E280) --------------------------------------------------------  // acclient.c:365188
void __cdecl Palette::makeModifiedPalette()
{
  Palette *v0; // eax@1
  int v1; // eax@2

  v0 = (Palette *)operator new(0x48u);
  if ( v0 )
  {
    Palette::Palette(v0, 2048);
    if ( v1 )
      ++*(_DWORD *)(v1 + 36);
  }
}

//----- (0053E2B0) --------------------------------------------------------  // acclient.c:365203
unsigned int __thiscall Palette::Pack(Palette *this, void **addr, unsigned int size)
{
  Palette *v3; // ebx@1
  int v4; // ecx@1
  unsigned int result; // eax@1
  char *v6; // edi@2

  v3 = this;
  v4 = *(_DWORD *)&this->m_bLoaded;
  result = 4 * v4 + 4;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v4;
    v6 = (char *)*addr + 4;
    *addr = v6;
    qmemcpy(v6, LODWORD(v3->m_timeStamp), 4 * *(_DWORD *)&v3->m_bLoaded);
    *addr = (char *)*addr + 4 * *(_DWORD *)&v3->m_bLoaded;
  }
  return result;
}

//----- (0053E310) --------------------------------------------------------  // acclient.c:365225
int __thiscall Palette::UnPack(Palette *this, void **addr, unsigned int size)
{
  unsigned int v3; // eax@1
  int v4; // edi@2

  *(_DWORD *)&this->m_bLoaded = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v3 = 0;
  if ( *(_DWORD *)&this->m_bLoaded )
  {
    do
    {
      v4 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      *(_DWORD *)(LODWORD(this->m_timeStamp) + 4 * v3++) = v4;
    }
    while ( v3 < *(_DWORD *)&this->m_bLoaded );
  }
  return 1;
}

//----- (0053E370) --------------------------------------------------------  // acclient.c:365247
Palette *__thiscall Palette::scalar_deleting_destructor(Palette *this, unsigned int a2)
{
  Palette *v2; // esi@1
  unsigned int *v3; // eax@1

  v2 = this;
  v3 = this->ARGB;
  this->vfptr = (InterfaceVtbl *)&Palette::vftable;
  this->vfptr = (PackObjVtbl *)&Palette::vftable;
  if ( v3 )
  {
    operator delete[](v3);
    v2->ARGB = 0;
  }
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C9C34: using guessed type void *Palette::vftable;
// 7C9C48: using guessed type __int32 (__stdcall *Palette::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0053E3C0) --------------------------------------------------------  // acclient.c:365272
int __cdecl Palette::makeModifiedPalette(IDClass<_tagDataID,32,0> palID, Subpalette *subs)
{
  unsigned int v2; // eax@1
  QualifiedDataID *v4; // eax@9
  Palette *v5; // eax@10
  int v6; // eax@11
  Palette *v7; // esi@11
  QualifiedDataID v8; // [sp+4h] [bp-8h]@9

  v2 = stru_84575C.id;
  if ( palID.id == stru_84575C.id )
    return 0;
  if ( subs && !subs->next && !subs->offset && subs->numcolors == 2048 )
    v2 = subs->subID.id;
  if ( v2 )
  {
    QualifiedDataID::QualifiedDataID(&v8, (IDClass<_tagDataID,32,0>)v2, 0xAu);
    return DBObj::Get(v4);
  }
  v5 = (Palette *)operator new(0x48u);
  if ( v5 )
  {
    Palette::Palette(v5, 2048);
    v7 = (Palette *)v6;
    if ( v6 )
    {
      ++*(_DWORD *)(v6 + 36);
      (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v6 + 68))(v6, palID.id);
      if ( Palette::Modify(v7, palID, 0, 0x800u) && Palette::Modify(v7, subs) )
        return (int)v7;
      ((void (__thiscall *)(Palette *, signed int))v7->vfptr[1].IUnknown_QueryInterface)(v7, 1);
    }
  }
  return 0;
}

//----- (00701C50) --------------------------------------------------------  // acclient.c:789393
int _E73_96()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_25, "Display.Resolution");
  return atexit(_E74_72);
}

//----- (00701C70) --------------------------------------------------------  // acclient.c:789400
int _E76_58()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_25, "Display.FullScreen");
  return atexit(_E77_86);
}

//----- (00701C90) --------------------------------------------------------  // acclient.c:789407
int _E79_51()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_25, "Display.RefreshRate");
  return atexit(_E80_50);
}

//----- (00701CB0) --------------------------------------------------------  // acclient.c:789414
int _E82_32()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_25, "Display.SyncToRefresh");
  return atexit(_E83_30);
}

//----- (00701CD0) --------------------------------------------------------  // acclient.c:789421
int _E85_22()
{
  return atexit(_E86_19);
}

//----- (00701CE0) --------------------------------------------------------  // acclient.c:789427
int _E88_17()
{
  return atexit(_E89_30);
}

//----- (00701CF0) --------------------------------------------------------  // acclient.c:789433
int sub_701CF0()
{
  return atexit(_E92_34);
}

//----- (00701D00) --------------------------------------------------------  // acclient.c:789439
int sub_701D00()
{
  return atexit(nullsub_1199);
}

//----- (0076BD60) --------------------------------------------------------  // acclient.c:899174
void __cdecl _E74_72()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BD90) --------------------------------------------------------  // acclient.c:899187
void __cdecl _E77_86()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BDC0) --------------------------------------------------------  // acclient.c:899200
void __cdecl _E80_50()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0076BDF0) --------------------------------------------------------  // acclient.c:899213
void __cdecl _E83_30()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_25.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_25.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

