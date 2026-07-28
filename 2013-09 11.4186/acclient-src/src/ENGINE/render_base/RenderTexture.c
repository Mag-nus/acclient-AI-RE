/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderTexture
   Object     : ENGINE\render_base\RenderTexture.obj
   Functions  : 894
   Addresses  : 0044B790 - 00745CD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044B790) --------------------------------------------------------  // acclient.c:136286
char __thiscall RenderTexture::Create2D(RenderTexture *this, const unsigned int _nWidth, const unsigned int _nHeight, const unsigned int _nNumLevels, PixelFormatID _PixelFormat, const unsigned int _Flags)
{
  char result; // al@3

  if ( _Flags & 2 && _Flags & 1 )
  {
    result = 0;
  }
  else
  {
    this->m_nNumLevels = _nNumLevels;
    this->m_PixelFormat = _PixelFormat;
    this->m_Flags = _Flags;
    this->m_TextureType = 2;
    this->m_nWidth = _nWidth;
    this->m_nHeight = _nHeight;
    GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&this->vfptr);
    result = 1;
  }
  return result;
}

//----- (0044B7E0) --------------------------------------------------------  // acclient.c:136309
char __thiscall RenderTexture::CreateCube(RenderTexture *this, const unsigned int _nEdgeLength, const unsigned int _nNumLevels, PixelFormatID _PixelFormat, const unsigned int _Flags)
{
  char result; // al@4

  if ( !RenderDevice::render_device->m_caps.bCubeTextures || _Flags & 2 && _Flags & 1 )
  {
    result = 0;
  }
  else
  {
    this->m_nNumLevels = _nNumLevels;
    this->m_Flags = _Flags;
    this->m_TextureType = 4;
    this->m_PixelFormat = _PixelFormat;
    this->m_nEdgeLength = _nEdgeLength;
    GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&this->vfptr);
    result = 1;
  }
  return result;
}

//----- (0044B830) --------------------------------------------------------  // acclient.c:136331
BOOL __cdecl RenderTexture::ShouldDropHighDetail()
{
  return (unsigned __int8)(*(int (__thiscall **)(AsyncCacheVtbl **, signed int, signed int))((int (__thiscall **)(_DWORD, _DWORD, _DWORD))&DBCache::s_pCache->vfptr->AreOnDisk
                                                                                           + 1))(
                            &DBCache::s_pCache->vfptr,
                            1766222152,
                            1) == 0;
}

//----- (0044B850) --------------------------------------------------------  // acclient.c:136341
bool __thiscall RenderTexture::Refresh(RenderTexture *this, IDClass<_tagDataID,32,0> _DataID)
{
  RenderTexture *v2; // esi@1
  bool result; // al@2

  v2 = this;
  if ( (unsigned __int8)((int (*)(void))this->vfptr[1].Release)() )
    result = (unsigned __int8)v2->vfptr[1].AddRef((Interface *)v2) != 0;
  else
    result = 0;
  return result;
}

//----- (0044B880) --------------------------------------------------------  // acclient.c:136355
PixelFormatID __cdecl RenderTexture::SelectTextureFormat(PixelFormatID format)
{
  PixelFormatID v1; // esi@1
  PixelFormatDesc pfDesc; // [sp+4h] [bp-38h]@1

  v1 = format;
  PixelFormatDesc::PixelFormatDesc(&pfDesc, format);
  if ( DBCache::IsRunTime() && Render::m_pRenderer && HACK_formatConversion && !(pfDesc.flags & 4) )
  {
    if ( pfDesc.flags & 2 && pfDesc.flags & 1 )
      return RenderDevice::render_device->m_displayInfo.pfARGBTextures;
    if ( pfDesc.flags & 2 )
      return RenderDevice::render_device->m_displayInfo.pfAlphaTextures;
    if ( pfDesc.flags & 1 )
      v1 = RenderDevice::render_device->m_displayInfo.pfRGBTextures;
  }
  return v1;
}
// 818248: using guessed type bool HACK_formatConversion;

//----- (0044B900) --------------------------------------------------------  // acclient.c:136376
void __thiscall RenderTexture::ReleaseSourceLevelReferences(RenderTexture *this)
{
  RenderTexture *v1; // edi@1
  int v2; // esi@2
  signed int v3; // ebx@3
  RenderSurface *v4; // ecx@4
  unsigned int il; // [sp+8h] [bp-4h]@1

  v1 = this;
  il = 0;
  if ( this->m_SourceLevels.m_num )
  {
    v2 = 0;
    do
    {
      v3 = 6;
      do
      {
        v4 = v1->m_SourceLevels.m_data->m_Resources[v2].m_pResource;
        if ( v4 )
        {
          ((void (*)(void))v4->vfptr->Release)();
          v1->m_SourceLevels.m_data->m_Resources[v2].m_pResource = 0;
        }
        ++v2;
        --v3;
      }
      while ( v3 );
      ++il;
    }
    while ( il < v1->m_SourceLevels.m_num );
  }
}

//----- (0044B960) --------------------------------------------------------  // acclient.c:136411
char __thiscall RenderTexture::ReleaseSubObjects(RenderTexture *this)
{
  RenderTexture *v1; // esi@1

  v1 = this;
  if ( DBCache::IsRunTime() )
    RenderTexture::ReleaseSourceLevelReferences(v1);
  return 1;
}

//----- (0044B980) --------------------------------------------------------  // acclient.c:136422
bool __thiscall RenderTexture::LoadLevelResources(RenderTexture *this)
{
  RenderTexture *v1; // ebp@1
  int v2; // eax@3
  int v3; // edi@4
  DBLevelInfo *v4; // esi@5
  int v5; // eax@5
  int v6; // esi@5
  TextureType v7; // eax@6
  bool v8; // zf@8
  int v9; // ecx@9
  QualifiedDataID *v10; // eax@11
  int v11; // eax@11
  bool v12; // cf@15
  bool retval; // [sp+17h] [bp-11h]@1
  signed int v15; // [sp+18h] [bp-10h]@4
  unsigned int il; // [sp+1Ch] [bp-Ch]@3
  QualifiedDataID v17; // [sp+20h] [bp-8h]@11

  v1 = this;
  retval = 1;
  if ( this->m_TextureType == 5 )
    return retval;
  if ( this->m_SourceLevels.m_num )
  {
    il = 0;
    v2 = 0;
    do
    {
      v3 = v2;
      v15 = 6;
      do
      {
        v4 = v1->m_SourceLevels.m_data;
        v5 = *(unsigned int *)((char *)&v4->m_Resources[0].m_LevelID.id + v3);
        v6 = (int)((char *)v4 + v3);
        if ( v5 != INVALID_DID_41.id )
        {
          v7 = v1->m_TextureType;
          if ( v7 == 2 || v7 == 4 )
          {
            v9 = *(_DWORD *)(v6 + 8);
            if ( v9 )
            {
              (*(void (**)(void))(*(_DWORD *)v9 + 20))();
              *(_DWORD *)(v6 + 8) = 0;
            }
            QualifiedDataID::QualifiedDataID(&v17, *(IDClass<_tagDataID,32,0> *)(v6 + 4), 0xCu);
            v11 = DBObj::Get(v10);
            *(_DWORD *)(v6 + 8) = v11;
            v8 = v11 == 0;
          }
          else
          {
            v8 = v7 == 3;
          }
          if ( v8 )
            retval = 0;
        }
        v3 += 12;
        --v15;
      }
      while ( v15 );
      v12 = il++ + 1 < v1->m_SourceLevels.m_num;
      v2 = v3;
    }
    while ( v12 );
    return retval;
  }
  return 0;
}

//----- (0044BA70) --------------------------------------------------------  // acclient.c:136495
bool __thiscall RenderTexture::ConstructTexture(RenderTexture *this)
{
  RenderTexture *v1; // edi@1
  TextureType v2; // eax@1
  unsigned int v3; // ecx@2
  bool result; // al@4
  RenderSurface *v5; // eax@6
  unsigned int v6; // esi@7
  unsigned int v7; // ebp@7
  int v8; // ebx@7
  unsigned int v9; // ebp@9
  int v10; // eax@12
  int v11; // esi@13
  RenderSurface *v12; // eax@26
  unsigned int v13; // ebx@27
  PixelFormatID v14; // esi@28
  int v15; // ebp@28
  unsigned int v16; // ebx@32
  int v17; // ecx@33
  int v18; // eax@34
  int v19; // esi@35
  bool v20; // cf@38
  char v21; // al@44
  int v22; // [sp+20h] [bp-18h]@10
  PixelFormatID v23; // [sp+20h] [bp-18h]@32
  unsigned int il; // [sp+24h] [bp-14h]@11
  unsigned int ila; // [sp+24h] [bp-14h]@30
  PixelFormatID NewFormat; // [sp+28h] [bp-10h]@7
  PixelFormatID NewFormata; // [sp+28h] [bp-10h]@31
  unsigned int nTextureWidth; // [sp+2Ch] [bp-Ch]@7
  unsigned int nTextureWidtha; // [sp+2Ch] [bp-Ch]@28
  RenderSurface *pSourceSurface; // [sp+30h] [bp-8h]@7
  RenderSurface *pSourceSurfacea; // [sp+30h] [bp-8h]@33
  unsigned int v32; // [sp+34h] [bp-4h]@27

  v1 = this;
  GraphicsResource::SetResourceIsThrashable(
    (GraphicsResource *)&this->vfptr,
    ~(unsigned __int8)(this->m_Flags >> 1) & 1);
  v2 = v1->m_TextureType;
  if ( v2 != 5 )
  {
    v3 = v1->m_SourceLevels.m_num;
    if ( !v3 || v3 < 1 )
      return 0;
  }
  if ( v2 != 2 )
  {
    if ( v2 != 4 )
    {
      if ( v2 == 5 )
      {
        RenderTexture::ReleaseSourceLevelReferences(v1);
        return 1;
      }
      return 0;
    }
    v12 = v1->m_SourceLevels.m_data->m_Resources[0].m_pResource;
    if ( !v12 )
      return 0;
    v13 = v12->width;
    v32 = v12->width;
    if ( v13 != v12->height )
      return 0;
    v14 = RenderTexture::SelectTextureFormat(v12->pfDesc.format);
    nTextureWidtha = v14;
    v15 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
    if ( !v15 )
      return 0;
    if ( (unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, PixelFormatID, signed int))(*(_DWORD *)v15 + 92))(
                            v15,
                            v13,
                            v1->m_SourceLevels.m_num,
                            v14,
                            2) )
    {
      ila = 0;
      if ( v1->m_SourceLevels.m_num )
      {
        NewFormata = 0;
LABEL_32:
        v16 = 0;
        v23 = NewFormata;
        while ( 1 )
        {
          pSourceSurfacea = *(RenderSurface **)((char *)&v1->m_SourceLevels.m_data->m_Resources[0].m_pResource + v23);
          v17 = v15;
          if ( !pSourceSurfacea )
            goto LABEL_45;
          v18 = (*(int (__thiscall **)(int, unsigned int, unsigned int))(*(_DWORD *)v15 + 100))(v15, ila, v16);
          if ( !v18 )
            goto LABEL_43;
          v19 = v18 - 48;
          if ( v18 == 48 )
            goto LABEL_43;
          if ( !(unsigned __int8)(*(int (__thiscall **)(int, RenderSurface *))(*(_DWORD *)v19 + 104))(
                                   v19,
                                   pSourceSurfacea) )
          {
            (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 20))(v19);
LABEL_43:
            (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 20))(v15);
            return 0;
          }
          (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 20))(v19);
          ++v16;
          v23 += 12;
          if ( v16 >= 6 )
          {
            v20 = ila++ + 1 < v1->m_SourceLevels.m_num;
            NewFormata += 72;
            if ( v20 )
              goto LABEL_32;
            v14 = nTextureWidtha;
            v13 = v32;
            break;
          }
        }
      }
      if ( (unsigned __int8)((int (__thiscall *)(RenderTexture *, unsigned int, unsigned int, PixelFormatID, _DWORD))v1->vfptr[3].Release)(
                              v1,
                              v13,
                              v1->m_SourceLevels.m_num,
                              v14,
                              0) )
      {
        v21 = ((int (__thiscall *)(RenderTexture *, int))v1->vfptr[4].IUnknown_QueryInterface)(v1, v15);
        v17 = v15;
        if ( v21 )
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 20))(v15);
          RenderTexture::ReleaseSourceLevelReferences(v1);
          return 1;
        }
LABEL_45:
        (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 20))(v17);
        return 0;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v15 + 20))(v15);
    return 0;
  }
  v5 = v1->m_SourceLevels.m_data->m_Resources[0].m_pResource;
  if ( !v5 )
    return 0;
  v6 = v5->width;
  v7 = v5->height;
  nTextureWidth = v5->width;
  pSourceSurface = (RenderSurface *)v5->height;
  NewFormat = RenderTexture::SelectTextureFormat(v5->pfDesc.format);
  v8 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
  if ( !v8 )
    return 0;
  if ( !(unsigned __int8)(*(int (__thiscall **)(int, unsigned int, unsigned int, unsigned int, PixelFormatID, signed int))(*(_DWORD *)v8 + 88))(
                           v8,
                           v6,
                           v7,
                           v1->m_SourceLevels.m_num,
                           NewFormat,
                           2) )
    goto LABEL_23;
  v9 = 0;
  if ( v1->m_SourceLevels.m_num )
  {
    v22 = 0;
    while ( 1 )
    {
      il = (unsigned int)v1->m_SourceLevels.m_data[v22].m_Resources[0].m_pResource;
      if ( !v1->m_SourceLevels.m_data[v22].m_Resources[0].m_pResource )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
        return 0;
      }
      v10 = (*(int (__thiscall **)(int, unsigned int, _DWORD))(*(_DWORD *)v8 + 100))(v8, v9, 0);
      if ( !v10 )
        goto LABEL_23;
      v11 = v10 - 48;
      if ( v10 == 48 )
        goto LABEL_23;
      if ( !(unsigned __int8)(*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v11 + 104))(v11, il) )
        break;
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
      ++v9;
      ++v22;
      if ( v9 >= v1->m_SourceLevels.m_num )
      {
        v6 = nTextureWidth;
        goto LABEL_17;
      }
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    goto LABEL_23;
  }
LABEL_17:
  if ( !(unsigned __int8)((int (__thiscall *)(RenderTexture *, unsigned int, RenderSurface *, unsigned int, PixelFormatID, _DWORD))v1->vfptr[3].AddRef)(
                           v1,
                           v6,
                           pSourceSurface,
                           v1->m_SourceLevels.m_num,
                           NewFormat,
                           0) )
  {
LABEL_23:
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
    return 0;
  }
  if ( (unsigned __int8)((int (__thiscall *)(RenderTexture *, int))v1->vfptr[4].IUnknown_QueryInterface)(v1, v8) )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
    RenderTexture::ReleaseSourceLevelReferences(v1);
    result = 1;
  }
  else
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
    result = 0;
  }
  return result;
}

//----- (0044BDC0) --------------------------------------------------------  // acclient.c:136716
bool __thiscall RenderTexture::GetSubObjects(RenderTexture *this)
{
  RenderTexture *v1; // esi@1
  bool result; // al@2

  v1 = this;
  if ( DBCache::IsRunTime() )
  {
    if ( Render::m_pRenderer && RenderTexture::LoadLevelResources(v1) )
      result = RenderTexture::ConstructTexture(v1) != 0;
    else
      result = 0;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0044BE00) --------------------------------------------------------  // acclient.c:136737
void *__thiscall DBLevelInfo::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // edi@1
  signed int v4; // ebp@1
  int v5; // eax@2
  int v6; // ebx@3
  int v7; // eax@6
  void *v9; // [sp+10h] [bp-4h]@1

  v9 = this;
  v2 = this;
  v3 = a2 - (_DWORD)this;
  v4 = 6;
  do
  {
    v5 = *(_DWORD *)v2;
    if ( *(_DWORD *)v2 != *(_DWORD *)((char *)v2 + v3) )
    {
      v6 = v5 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = *(_DWORD *)((char *)v2 + v3);
      *(_DWORD *)v2 = v7;
      InterlockedIncrement((volatile LONG *)(v7 - 16));
      this = v9;
    }
    *((_DWORD *)v2 + 1) = *(_DWORD *)((char *)v2 + v3 + 4);
    *((_DWORD *)v2 + 2) = *(_DWORD *)((char *)v2 + v3 + 8);
    v2 = (char *)v2 + 12;
    --v4;
  }
  while ( v4 );
  return this;
}

//----- (0044BE70) --------------------------------------------------------  // acclient.c:136774
void __thiscall DBLevelInfo::DBLevelInfo(DBLevelInfo *this)
{
  DBLevelInfo *v1; // esi@1
  signed int v2; // edi@1
  volatile LONG *v3; // ST00_4@2

  v1 = this;
  v2 = 6;
  do
  {
    v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_Resources[0].m_Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v3);
    v1->m_Resources[0].m_LevelID.id = INVALID_DID_41.id;
    v1->m_Resources[0].m_pResource = 0;
    v1 = (DBLevelInfo *)((char *)v1 + 12);
    --v2;
  }
  while ( v2 );
}

//----- (0044BEC0) --------------------------------------------------------  // acclient.c:136796
void __thiscall DBLevelInfo::~DBLevelInfo(DBLevelInfo *this)
{
  DBLevelInfo *v1; // edi@1
  RenderSurface *v2; // ecx@2
  int v3; // esi@4
  signed int v4; // [sp+4h] [bp-4h]@1

  v1 = this + 1;
  v4 = 6;
  do
  {
    v2 = v1[-1].m_Resources[5].m_pResource;
    v1 = (DBLevelInfo *)((char *)v1 - 12);
    if ( v2 )
    {
      ((void (*)(void))v2->vfptr->Release)();
      v1->m_Resources[0].m_pResource = 0;
    }
    v3 = (int)&v1->m_Resources[0].m_Name.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v4;
  }
  while ( v4 );
}

//----- (0044BF20) --------------------------------------------------------  // acclient.c:136826
void __thiscall SmartArray<DBLevelInfo,1>::~SmartArray<DBLevelInfo,1>(SmartArray<DBLevelInfo,1> *this)
{
  DBLevelInfo *v1; // ecx@2
  RenderSurface *v2; // eax@3
  void *v3; // ebx@3
  int v4; // edx@3
  int v5; // eax@3
  DBLevelInfo *v6; // esi@3
  int v7; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].m_Resources[5].m_pResource;
      v3 = &v1[-1].m_Resources[5].m_pResource;
      v4 = 9 * (_DWORD)v2;
      v5 = (int)(&v2[-1].m_ReadOnlyLock + 2);
      v6 = &v1[8 * v4 / 0x48u];
      if ( v5 >= 0 )
      {
        v7 = v5 + 1;
        do
        {
          --v6;
          DBLevelInfo::~DBLevelInfo(v6);
          --v7;
        }
        while ( v7 );
      }
      operator delete[](v3);
    }
  }
}

//----- (0044BF70) --------------------------------------------------------  // acclient.c:136863
void __thiscall SmartArray<DBLevelInfo,1>::Reset(SmartArray<DBLevelInfo,1> *this)
{
  SmartArray<DBLevelInfo,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  DBLevelInfo *v4; // ecx@2
  RenderSurface *v5; // eax@3
  void *v6; // ebp@3
  int v7; // edx@3
  int v8; // eax@3
  DBLevelInfo *v9; // esi@3
  int v10; // ebx@4
  int v11; // eax@9
  int v12; // esi@10
  int v13; // ebx@10
  int v14; // eax@11
  DBLevelInfo v15; // [sp+Ch] [bp-48h]@11

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = v4[-1].m_Resources[5].m_pResource;
      v6 = &v4[-1].m_Resources[5].m_pResource;
      v7 = 9 * (_DWORD)v5;
      v8 = (int)(&v5[-1].m_ReadOnlyLock + 2);
      v9 = &v4[8 * v7 / 0x48u];
      if ( v8 >= 0 )
      {
        v10 = v8 + 1;
        do
        {
          --v9;
          DBLevelInfo::~DBLevelInfo(v9);
          --v10;
        }
        while ( v10 );
      }
      operator delete[](v6);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v11 = (v2 & 0x7FFFFFFF) - 1;
    if ( v11 >= 0 )
    {
      v12 = v11;
      v13 = v11 + 1;
      do
      {
        DBLevelInfo::DBLevelInfo(&v15);
        DBLevelInfo::operator=(&v1->m_data[v12], v14);
        DBLevelInfo::~DBLevelInfo(&v15);
        --v12;
        --v13;
      }
      while ( v13 );
    }
  }
}

//----- (0044C020) --------------------------------------------------------  // acclient.c:136932
char __thiscall SmartArray<DBLevelInfo,1>::grow(SmartArray<DBLevelInfo,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<DBLevelInfo,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  DBLevelInfo *v9; // esi@12
  RenderSurface *v10; // eax@13
  void *v11; // ecx@13
  int v12; // edx@13
  int v13; // eax@13
  DBLevelInfo *v14; // esi@13
  int v15; // [sp+Ch] [bp-4h]@13
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@9
  unsigned int i_nSizeb; // [sp+14h] [bp+4h]@14

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<DBLevelInfo,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](72 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x48u,
        i_nSize,
        (void *(__thiscall *)(void *))DBLevelInfo::DBLevelInfo);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              DBLevelInfo::operator=((void *)(v8 * 72 + v6), (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v9 = v3->m_data;
            if ( v3->m_data )
            {
              v10 = v9[-1].m_Resources[5].m_pResource;
              v11 = &v9[-1].m_Resources[5].m_pResource;
              v12 = 9 * (_DWORD)v10;
              v13 = (int)(&v10[-1].m_ReadOnlyLock + 2);
              v15 = (int)&v9[-1].m_Resources[5].m_pResource;
              v14 = &v9[8 * v12 / 0x48u];
              if ( v13 >= 0 )
              {
                i_nSizeb = v13 + 1;
                do
                {
                  --v14;
                  DBLevelInfo::~DBLevelInfo(v14);
                  --i_nSizeb;
                }
                while ( i_nSizeb );
                v11 = (void *)v15;
              }
              operator delete[](v11);
            }
          }
        }
        v3->m_data = (DBLevelInfo *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (0044C130) --------------------------------------------------------  // acclient.c:137025
SmartArray<DBLevelInfo,1> *__thiscall SmartArray<DBLevelInfo,1>::operator=(SmartArray<DBLevelInfo,1> *this, int a2)
{
  SmartArray<DBLevelInfo,1> *v2; // edi@1
  int v3; // esi@3
  void *v4; // ebx@3
  int v5; // ebp@3
  int v6; // esi@5
  int v7; // ebx@6
  int v8; // eax@7
  DBLevelInfo v10; // [sp+8h] [bp-48h]@7

  v2 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= (*(_DWORD *)(a2 + 4) & 0x7FFFFFFFu)
    || (this->m_num = 0, SmartArray<DBLevelInfo,1>::grow(this, *(_DWORD *)(a2 + 4) & 0x7FFFFFFF)) )
  {
    v3 = *(_DWORD *)a2;
    v4 = v2->m_data;
    v5 = *(_DWORD *)a2 + 72 * *(_DWORD *)(a2 + 8);
    if ( *(_DWORD *)a2 < (unsigned int)v5 )
    {
      do
      {
        DBLevelInfo::operator=(v4, v3);
        v3 += 72;
        v4 = (char *)v4 + 72;
      }
      while ( v3 < (unsigned int)v5 );
    }
    v6 = *(_DWORD *)(a2 + 8);
    if ( v6 < v2->m_num )
    {
      v7 = v6;
      do
      {
        DBLevelInfo::DBLevelInfo(&v10);
        DBLevelInfo::operator=(&v2->m_data[v7], v8);
        DBLevelInfo::~DBLevelInfo(&v10);
        ++v6;
        ++v7;
      }
      while ( v6 < v2->m_num );
    }
    v2->m_num = *(_DWORD *)(a2 + 8);
  }
  return v2;
}

//----- (0044C1E0) --------------------------------------------------------  // acclient.c:137073
char __thiscall SmartArray<DBLevelInfo,1>::SetNElements(SmartArray<DBLevelInfo,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<DBLevelInfo,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  const unsigned int v6; // ebx@7
  const unsigned int v7; // edi@8
  int v8; // eax@9
  DBLevelInfo v9; // [sp+8h] [bp-48h]@9

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v6 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      v7 = i_nSize;
      do
      {
        DBLevelInfo::DBLevelInfo(&v9);
        DBLevelInfo::operator=(&v3->m_data[v7], v8);
        DBLevelInfo::~DBLevelInfo(&v9);
        ++v6;
        ++v7;
      }
      while ( v6 < v3->m_num );
    }
    goto LABEL_10;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<DBLevelInfo,1>::grow(v3, v4);
  if ( result )
  {
LABEL_10:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (0044C270) --------------------------------------------------------  // acclient.c:137117
void __thiscall RenderTexture::RenderTexture(RenderTexture *this)
{
  RenderTexture *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_41);
  GraphicsResource::GraphicsResource((GraphicsResource *)&v1->vfptr);
  v2 = (int)&v1->m_SourceLevels;
  v1->vfptr = (InterfaceVtbl *)&RenderTexture::vftable;
  v1->vfptr = (GraphicsResourceVtbl *)&RenderTexture::vftable;
  v1->m_ManagedRefCount = 0;
  LODWORD(v1->m_LastManagedReleaseTime) = 0;
  HIDWORD(v1->m_LastManagedReleaseTime) = 0;
  v1->m_AllowManagement = 1;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  v1->m_TextureType = 1;
  v1->m_nNumLevels = 0;
  v1->m_PixelFormat = 0;
  v1->m_Flags = 0;
  v1->m_bDropLevelsCalled = 0;
  SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
  v1->m_nWidth = 0;
  v1->m_nHeight = 0;
  v1->m_nEdgeLength = 0;
}
// 79B198: using guessed type void *RenderTexture::vftable;
// 79B1A8: using guessed type __int32 (__stdcall *RenderTexture::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0044C2E0) --------------------------------------------------------  // acclient.c:137149
signed int RenderTexture::GetDBOType()
{
  return 30;
}

//----- (0044C2F0) --------------------------------------------------------  // acclient.c:137155
RenderTexture *__thiscall RenderTexture::vector_deleting_destructor(RenderTexture *this, unsigned int a2)
{
  return RenderTexture::scalar_deleting_destructor((RenderTexture *)((char *)this - 48), a2);
}

//----- (0044C300) --------------------------------------------------------  // acclient.c:137161
void __thiscall RenderTexture::End(RenderTexture *this)
{
  RenderTexture *v1; // esi@1

  v1 = this;
  if ( DBCache::IsRunTime() )
    RenderTexture::ReleaseSourceLevelReferences(v1);
  RenderTexture::ReleaseSourceLevelReferences(v1);
  SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
}

//----- (0044C330) --------------------------------------------------------  // acclient.c:137173
void __thiscall RenderTexture::Destroy(RenderTexture *this)
{
  RenderTexture *v1; // esi@1

  v1 = this;
  if ( DBCache::IsRunTime() )
    RenderTexture::ReleaseSourceLevelReferences(v1);
  RenderTexture::ReleaseSourceLevelReferences(v1);
  SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
  v1->m_TextureType = 1;
  v1->m_nNumLevels = 0;
  v1->m_PixelFormat = 0;
  v1->m_Flags = 0;
  v1->m_bDropLevelsCalled = 0;
  SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
  v1->m_nWidth = 0;
  v1->m_nHeight = 0;
  v1->m_nEdgeLength = 0;
}

//----- (0044C390) --------------------------------------------------------  // acclient.c:137194
char __thiscall RenderTexture::DropUnwantedLevels(RenderTexture *this)
{
  RenderTexture *v1; // ebx@1
  char result; // al@2
  int v3; // edi@3
  int v4; // esi@5
  unsigned int v5; // eax@10
  int v6; // ebp@13
  int v7; // esi@14
  SmartArray<DBLevelInfo,1> NewLevels; // [sp+8h] [bp-Ch]@13

  v1 = this;
  if ( this->m_bDropLevelsCalled )
  {
    result = 1;
  }
  else
  {
    this->m_bDropLevelsCalled = 1;
    v3 = 0;
    if ( Render::m_pRenderer )
    {
      switch ( dword_81EF9C )
      {
        case 4:
          v4 = 4;
          goto LABEL_10;
        case 3:
          v4 = 3;
          goto LABEL_10;
        case 2:
          v4 = 2;
          goto LABEL_10;
        case 0:
          if ( (unsigned __int8)RenderTexture::ShouldDropHighDetail() )
            goto $L118229;
          goto LABEL_17;
        case 1:
$L118229:
          v4 = 1;
LABEL_10:
          v5 = v1->m_SourceLevels.m_num;
          if ( v5 <= 1 )
            goto LABEL_17;
          if ( v4 >= v5 )
            v4 = v5 - 1;
          v6 = v5 - v4;
          NewLevels.m_data = 0;
          NewLevels.m_sizeAndDeallocate = 0;
          NewLevels.m_num = 0;
          SmartArray<DBLevelInfo,1>::SetNElements(&NewLevels, v5 - v4, 1);
          if ( (unsigned int)v6 > 0 )
          {
            v7 = v4;
            do
            {
              DBLevelInfo::operator=(&NewLevels.m_data[v3], (int)&v1->m_SourceLevels.m_data[v7]);
              ++v3;
              ++v7;
              --v6;
            }
            while ( v6 );
          }
          RenderTexture::ReleaseSourceLevelReferences(v1);
          SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
          SmartArray<DBLevelInfo,1>::operator=(&v1->m_SourceLevels, (int)&NewLevels);
          SmartArray<DBLevelInfo,1>::~SmartArray<DBLevelInfo,1>(&NewLevels);
          result = 1;
          break;
        default:
LABEL_17:
          result = 1;
          break;
      }
    }
    else
    {
      result = 0;
    }
  }
  return result;
}
// 81EF9C: using guessed type int dword_81EF9C;

//----- (0044C4A0) --------------------------------------------------------  // acclient.c:137279
void RenderTexture::Allocate()
{
  RenderTexture *v1; // eax@4

  if ( DBCache::IsRunTime() )
  {
    if ( Render::m_pRenderer )
      ((void (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
  }
  else
  {
    v1 = (RenderTexture *)operator new(0x98u);
    if ( v1 )
      RenderTexture::RenderTexture(v1);
  }
}

//----- (0044C4E0) --------------------------------------------------------  // acclient.c:137297
RenderTexture *__thiscall RenderTexture::scalar_deleting_destructor(RenderTexture *this, unsigned int a2)
{
  RenderTexture *v2; // esi@1

  v2 = this;
  RenderTexture::~RenderTexture(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044C500) --------------------------------------------------------  // acclient.c:137309
void __thiscall RenderTexture::~RenderTexture(RenderTexture *this)
{
  RenderTexture *v1; // esi@1
  GraphicsResource *v2; // ebx@1

  v1 = this;
  v2 = (GraphicsResource *)&this->vfptr;
  this->vfptr = (InterfaceVtbl *)&RenderTexture::vftable;
  this->vfptr = (GraphicsResourceVtbl *)&RenderTexture::vftable;
  if ( DBCache::IsRunTime() )
    RenderTexture::ReleaseSourceLevelReferences(v1);
  RenderTexture::ReleaseSourceLevelReferences(v1);
  SmartArray<DBLevelInfo,1>::Reset(&v1->m_SourceLevels);
  SmartArray<DBLevelInfo,1>::~SmartArray<DBLevelInfo,1>(&v1->m_SourceLevels);
  GraphicsResource::~GraphicsResource(v2);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79B198: using guessed type void *RenderTexture::vftable;
// 79B1A8: using guessed type __int32 (__stdcall *RenderTexture::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0044C550) --------------------------------------------------------  // acclient.c:137330
char __thiscall RenderTexture::CopyInto(RenderTexture *this, DBObj *_Retval)
{
  DBObj *v2; // ebp@1
  RenderTexture *v3; // edi@1
  GraphicsResource *v4; // eax@2
  char result; // al@4
  const unsigned int v6; // ebx@5
  unsigned int v7; // esi@5
  DBLevelInfo *v8; // ebx@7
  PSRefBufferCharData<char> *v9; // ecx@7
  DBObj *v10; // ebp@7
  PSRefBufferCharData<char> *v11; // eax@7
  int v12; // ebx@7
  int v13; // ebp@7
  int v14; // ebx@11
  RenderSurface *v15; // ecx@12
  signed int v16; // [sp+8h] [bp-Ch]@6
  unsigned int il; // [sp+Ch] [bp-8h]@5
  int v18; // [sp+10h] [bp-4h]@8

  v2 = _Retval;
  v3 = this;
  if ( _Retval )
    v4 = (GraphicsResource *)&_Retval[1];
  else
    v4 = 0;
  result = GraphicsResource::CopyInto((GraphicsResource *)&this->vfptr, v4);
  if ( result )
  {
    _Retval[1].m_DID.id = v3->m_TextureType;
    *(_DWORD *)&_Retval[1].m_AllowedInFreeList = v3->m_nNumLevels;
    _Retval[2].vfptr = (InterfaceVtbl *)v3->m_PixelFormat;
    _Retval[2].m_dataCategory = v3->m_Flags;
    _Retval[2].m_bLoaded = v3->m_bDropLevelsCalled;
    v6 = v3->m_SourceLevels.m_num;
    RenderTexture::ReleaseSourceLevelReferences((RenderTexture *)_Retval);
    SmartArray<DBLevelInfo,1>::Reset((SmartArray<DBLevelInfo,1> *)&_Retval[2].m_pLast);
    SmartArray<DBLevelInfo,1>::SetNElements((SmartArray<DBLevelInfo,1> *)&_Retval[2].m_pLast, v6, 1);
    v7 = 0;
    il = 0;
    if ( v3->m_SourceLevels.m_num )
    {
      do
      {
        v16 = 6;
        do
        {
          v8 = v3->m_SourceLevels.m_data;
          v9 = v8->m_Resources[v7].m_Name.m_charbuffer;
          v10 = v2[2].m_pLast;
          v11 = *(PSRefBufferCharData<char> **)((char *)&v10->vfptr + v7 * 12);
          v12 = (int)((char *)v8 + v7 * 12);
          v13 = (int)((char *)v10 + v7 * 12);
          if ( v11 != v9 )
          {
            v18 = (int)&v11[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) && v18 )
              (**(void (__stdcall ***)(_DWORD))v18)(1);
            v14 = *(_DWORD *)v12;
            *(_DWORD *)v13 = v14;
            InterlockedIncrement((volatile LONG *)(v14 - 16));
          }
          *(unsigned int *)((char *)&_Retval[2].m_pLast->m_dataCategory + v7 * 12) = v3->m_SourceLevels.m_data->m_Resources[v7].m_LevelID.id;
          *(_DWORD *)(&_Retval[2].m_pLast->m_bLoaded + v7 * 12) = v3->m_SourceLevels.m_data->m_Resources[v7].m_pResource;
          v15 = v3->m_SourceLevels.m_data->m_Resources[v7].m_pResource;
          if ( v15 )
            ((void (*)(void))v15->vfptr->AddRef)();
          v2 = _Retval;
          ++v7;
          --v16;
        }
        while ( v16 );
        ++il;
      }
      while ( il < v3->m_SourceLevels.m_num );
    }
    v2[2].m_DID.id = v3->m_nWidth;
    *(_DWORD *)&v2[2].m_AllowedInFreeList = v3->m_nHeight;
    v2[3].vfptr = (InterfaceVtbl *)v3->m_nEdgeLength;
    result = 1;
  }
  return result;
}

//----- (0044C6C0) --------------------------------------------------------  // acclient.c:137415
void __thiscall RenderTexture::GetSubDataIDs(RenderTexture *this, QualifiedDataIDArray *_aQDID)
{
  RenderTexture *v2; // ebx@1
  unsigned int v3; // edi@3
  int v4; // esi@4
  IDClass<_tagDataID,32,0> v5; // eax@5
  signed int v6; // ecx@6
  unsigned int v7; // ST08_4@9
  QualifiedDataID *v8; // eax@9
  signed int v9; // [sp+Ch] [bp-Ch]@4
  QualifiedDataID v10; // [sp+10h] [bp-8h]@9

  v2 = this;
  if ( DBCache::IsRunTime() )
    RenderTexture::DropUnwantedLevels(v2);
  v3 = 0;
  if ( v2->m_SourceLevels.m_num )
  {
    do
    {
      v4 = 6 * v3;
      v9 = 6;
      do
      {
        v5.id = v2->m_SourceLevels.m_data->m_Resources[v4].m_LevelID.id;
        if ( v5.id != INVALID_DID_41.id )
        {
          v6 = 0;
          if ( !v3 && v2->m_SourceLevels.m_num > 1 )
            v6 = 4;
          v7 = v6;
          QualifiedDataID::QualifiedDataID(&v10, v5, 0);
          QualifiedDataIDArray::AddQDID(_aQDID, v8, v7);
        }
        ++v4;
        --v9;
      }
      while ( v9 );
      ++v3;
    }
    while ( v3 < v2->m_SourceLevels.m_num );
  }
}

//----- (0044C760) --------------------------------------------------------  // acclient.c:137460
bool __thiscall RenderTexture::InitLoad(RenderTexture *this)
{
  RenderTexture *v1; // esi@1
  bool result; // al@2

  v1 = this;
  if ( DBCache::IsRunTime() )
    result = RenderTexture::DropUnwantedLevels(v1) != 0;
  else
    result = 1;
  return result;
}

//----- (0044C780) --------------------------------------------------------  // acclient.c:137474
void __thiscall RenderTexture::Serialize(RenderTexture *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  RenderTexture *v3; // ebp@1
  unsigned __int8 v4; // bl@1
  unsigned int v5; // eax@1
  const unsigned int v6; // edi@7
  unsigned int v7; // eax@7
  int v8; // ebx@14
  int v9; // edi@17
  unsigned int v10; // eax@17
  bool v11; // zf@22
  int v12; // [sp+10h] [bp-8h]@14
  const unsigned int v13; // [sp+14h] [bp-4h]@14
  Archive *io_archivea; // [sp+1Ch] [bp+4h]@16

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  v4 = LOBYTE(v3->m_TextureType);
  Archive::CheckAlignment(io_archive, 1u);
  v5 = Archive::GetBytes(io_archive, 1u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v5 = v4;
    else
      v4 = *(_BYTE *)v5;
  }
  if ( !(io_archive->m_flags & 5) )
    v3->m_TextureType = v4;
  v6 = v3->m_SourceLevels.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v7 = v6;
    else
      v6 = *(_DWORD *)v7;
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
  {
    RenderTexture::ReleaseSourceLevelReferences(v3);
    SmartArray<DBLevelInfo,1>::Reset(&v3->m_SourceLevels);
    SmartArray<DBLevelInfo,1>::SetNElements(&v3->m_SourceLevels, v6, 1);
    v3->m_bDropLevelsCalled = 0;
  }
  if ( v6 )
  {
    v8 = 0;
    v12 = 0;
    v13 = v6;
    do
    {
      if ( (v3->m_TextureType != 4 ? 0 : 5) != -1 )
      {
        io_archivea = (Archive *)(v3->m_TextureType != 4 ? 1 : 6);
        do
        {
          v9 = (int)((char *)&v3->m_SourceLevels.m_data->m_Resources[0].m_LevelID + v8);
          Archive::CheckAlignment(v2, 4u);
          v10 = Archive::GetBytes(v2, 4u);
          if ( v10 )
          {
            if ( v2->m_flags & 1 )
              *(_DWORD *)v10 = *(_DWORD *)v9;
            else
              *(_DWORD *)v9 = *(_DWORD *)v10;
          }
          v8 += 12;
          io_archivea = (Archive *)((char *)io_archivea - 1);
        }
        while ( io_archivea );
      }
      v8 = v12 + 72;
      v11 = v13 == 1;
      v12 += 72;
      --v13;
    }
    while ( !v11 );
  }
}

//----- (006D6F80) --------------------------------------------------------  // acclient.c:749131
void _E73_45()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_19, PFID_A8R8G8B8);
}

//----- (006D6F90) --------------------------------------------------------  // acclient.c:749137
int _E91_21()
{
  return atexit(_E92_23);
}

//----- (006D6FA0) --------------------------------------------------------  // acclient.c:749143
int _E94_12()
{
  return atexit(nullsub_260);
}

//----- (006D6FB0) --------------------------------------------------------  // acclient.c:749149
int _E97_20()
{
  return atexit(_E98_38);
}

//----- (006D6FC0) --------------------------------------------------------  // acclient.c:749155
int _E100_17()
{
  PStringBase<char>::PStringBase<char>(&PHeader_3, "PREPROC_HEADER");
  return atexit(_E101_63);
}

//----- (006D6FE0) --------------------------------------------------------  // acclient.c:749162
int _E103_10()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_3, "VertexArray");
  return atexit(_E104_33);
}

//----- (006D7000) --------------------------------------------------------  // acclient.c:749169
int _E106_13()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_3, "BinaryVertexArray");
  return atexit(_E107_65);
}

//----- (006D7020) --------------------------------------------------------  // acclient.c:749176
int _E109_9()
{
  PStringBase<char>::PStringBase<char>(&VertexType_4, "VertexType");
  return atexit(sub_741350);
}

//----- (006D7040) --------------------------------------------------------  // acclient.c:749183
int _E112_11()
{
  PStringBase<char>::PStringBase<char>(&VertexData_3, "VertexData");
  return atexit(_E113_44);
}

//----- (006D7060) --------------------------------------------------------  // acclient.c:749190
int _E115_8()
{
  PStringBase<char>::PStringBase<char>(&Vertex_3, "Vertex");
  return atexit(_E116_36);
}

//----- (006D7080) --------------------------------------------------------  // acclient.c:749197
int _E118_12()
{
  PStringBase<char>::PStringBase<char>(&Index_7, "Index");
  return atexit(_E119_61);
}

//----- (006D70A0) --------------------------------------------------------  // acclient.c:749204
int _E121_9()
{
  PStringBase<char>::PStringBase<char>(&Origin_7, "P");
  return atexit(_E122_48);
}

//----- (006D70C0) --------------------------------------------------------  // acclient.c:749211
int _E124_12()
{
  PStringBase<char>::PStringBase<char>(&Normal_3, "N");
  return atexit(_E125_23);
}

//----- (006D70E0) --------------------------------------------------------  // acclient.c:749218
int _E127_8()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_7, "Diffuse");
  return atexit(_E128_24);
}

//----- (006D7100) --------------------------------------------------------  // acclient.c:749225
int _E130_9()
{
  PStringBase<char>::PStringBase<char>(&Specular_7, "Specular");
  return atexit(_E131_20);
}

//----- (006D7120) --------------------------------------------------------  // acclient.c:749232
int _E133_8()
{
  PStringBase<char>::PStringBase<char>(&UVS_3, "UVS");
  return atexit(_E134_19);
}

//----- (006D7140) --------------------------------------------------------  // acclient.c:749239
int _E136_7()
{
  PStringBase<char>::PStringBase<char>(&VectorS_3, "VectorS");
  return atexit(_E137_19);
}

//----- (006D7160) --------------------------------------------------------  // acclient.c:749246
int _E139_6()
{
  PStringBase<char>::PStringBase<char>(&VectorT_3, "VectorT");
  return atexit(_E140_14);
}

//----- (006D7180) --------------------------------------------------------  // acclient.c:749253
int _E142_6()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_3, "VectorSxT");
  return atexit(_E143_15);
}

//----- (006D71A0) --------------------------------------------------------  // acclient.c:749260
int _E145_5()
{
  PStringBase<char>::PStringBase<char>(&Weights_3, "Weights");
  return atexit(_E146_14);
}

//----- (006D71C0) --------------------------------------------------------  // acclient.c:749267
int _E148_5()
{
  PStringBase<char>::PStringBase<char>(&Importance_3, "Importance");
  return atexit(_E149_14);
}

//----- (006D71E0) --------------------------------------------------------  // acclient.c:749274
int _E151_5()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_3, "PhysMtl");
  return atexit(_E152_13);
}

//----- (006D7200) --------------------------------------------------------  // acclient.c:749281
int _E154_6()
{
  PStringBase<char>::PStringBase<char>(&Material_16, "Material");
  return atexit(_E155_11);
}

//----- (006D7220) --------------------------------------------------------  // acclient.c:749288
int _E157_5()
{
  PStringBase<char>::PStringBase<char>(&ID_8, "ID");
  return atexit(_E158_14);
}

//----- (006D7240) --------------------------------------------------------  // acclient.c:749295
int _E160_6()
{
  PStringBase<char>::PStringBase<char>(&FileName_3, "FileName");
  return atexit(_E161_11);
}

//----- (006D7260) --------------------------------------------------------  // acclient.c:749302
int _E163_4()
{
  PStringBase<char>::PStringBase<char>(&Polygon_7, "Polygon");
  return atexit(_E164_14);
}

//----- (006D7280) --------------------------------------------------------  // acclient.c:749309
int _E166_5()
{
  PStringBase<char>::PStringBase<char>(&ID_9, "ID");
  return atexit(_E167_10);
}

//----- (006D72A0) --------------------------------------------------------  // acclient.c:749316
int _E169_3()
{
  PStringBase<char>::PStringBase<char>(&Indices_5, "INDICES");
  return atexit(_E170_9);
}

//----- (006D72C0) --------------------------------------------------------  // acclient.c:749323
int _E172_3()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_3, "MaterialID");
  return atexit(_E173_8);
}

//----- (006D72E0) --------------------------------------------------------  // acclient.c:749330
int _E175_3()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_3, "PhysMaterialID");
  return atexit(_E176_9);
}

//----- (006D7300) --------------------------------------------------------  // acclient.c:749337
int _E178_3()
{
  PStringBase<char>::PStringBase<char>(&Markings_3, "Markings");
  return atexit(_E179_8);
}

//----- (006D7320) --------------------------------------------------------  // acclient.c:749344
int _E181_3()
{
  PStringBase<char>::PStringBase<char>(&Material_17, "Material");
  return atexit(_E182_8);
}

//----- (006D7340) --------------------------------------------------------  // acclient.c:749351
int _E184_1()
{
  PStringBase<char>::PStringBase<char>(&Index_8, "Index");
  return atexit(_E185_5);
}

//----- (006D7360) --------------------------------------------------------  // acclient.c:749358
int _E187_1()
{
  PStringBase<char>::PStringBase<char>(&Filename_3, "Filename");
  return atexit(_E188_6);
}

//----- (006D7380) --------------------------------------------------------  // acclient.c:749365
int _E190_1()
{
  PStringBase<char>::PStringBase<char>(&Surface_3, "Surface");
  return atexit(_E191_5);
}

//----- (006D73A0) --------------------------------------------------------  // acclient.c:749372
int _E193_1()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_3, "CellPoly");
  return atexit(_E194_12);
}

//----- (006D73C0) --------------------------------------------------------  // acclient.c:749379
int _E196_3()
{
  PStringBase<char>::PStringBase<char>(&Sphere_4, "Sphere");
  return atexit(_E197_3);
}

//----- (006D73E0) --------------------------------------------------------  // acclient.c:749386
int _E199_1()
{
  PStringBase<char>::PStringBase<char>(&Side_3, "Side");
  return atexit(_E200_8);
}

//----- (006D7400) --------------------------------------------------------  // acclient.c:749393
int _E202_1()
{
  PStringBase<char>::PStringBase<char>(&Positive_3, "Positive");
  return atexit(_E203_7);
}

//----- (006D7420) --------------------------------------------------------  // acclient.c:749400
int _E205_2()
{
  PStringBase<char>::PStringBase<char>(&Negative_3, "Negative");
  return atexit(_E206_10);
}

//----- (006D7440) --------------------------------------------------------  // acclient.c:749407
int _E208_3()
{
  PStringBase<char>::PStringBase<char>(&Polygon_8, "PolygonIndex");
  return atexit(_E209_5);
}

//----- (006D7460) --------------------------------------------------------  // acclient.c:749414
int _E211_2()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_7, "OtherCellMeshIndex");
  return atexit(_E212_8);
}

//----- (006D7480) --------------------------------------------------------  // acclient.c:749421
int _E214_2()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_3, "CellPortal");
  return atexit(_E215_4);
}

//----- (006D74A0) --------------------------------------------------------  // acclient.c:749428
int _E217_2()
{
  PStringBase<char>::PStringBase<char>(&Portal_4, "PortalIndex");
  return atexit(_E218_5);
}

//----- (006D74C0) --------------------------------------------------------  // acclient.c:749435
int _E220_2()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_8, "OtherCellID");
  return atexit(_E221_5);
}

//----- (006D74E0) --------------------------------------------------------  // acclient.c:749442
int _E223_2()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_3, "OtherPortalIndex");
  return atexit(_E224_5);
}

//----- (006D7500) --------------------------------------------------------  // acclient.c:749449
int _E226_2()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_3, "ExactMatch");
  return atexit(_E227_5);
}

//----- (006D7520) --------------------------------------------------------  // acclient.c:749456
int _E229_2()
{
  PStringBase<char>::PStringBase<char>(&StabList_3, "StabList");
  return atexit(_E230_5);
}

//----- (006D7540) --------------------------------------------------------  // acclient.c:749463
int _E232_2()
{
  PStringBase<char>::PStringBase<char>(&Period_3, "Period");
  return atexit(_E233_4);
}

//----- (006D7560) --------------------------------------------------------  // acclient.c:749470
int _E235_2()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_3, "GrannyAnimation");
  return atexit(_E236_4);
}

//----- (006D7580) --------------------------------------------------------  // acclient.c:749477
int _E238_2()
{
  PStringBase<char>::PStringBase<char>(&Transform_3, "Transform");
  return atexit(_E239_5);
}

//----- (006D75A0) --------------------------------------------------------  // acclient.c:749484
int _E241_2()
{
  PStringBase<char>::PStringBase<char>(&Scale_11, "Scale");
  return atexit(_E242_5);
}

//----- (006D75C0) --------------------------------------------------------  // acclient.c:749491
int _E244_2()
{
  PStringBase<char>::PStringBase<char>(&Weight_3, "Weight");
  return atexit(_E245_4);
}

//----- (006D75E0) --------------------------------------------------------  // acclient.c:749498
int _E247_2()
{
  PStringBase<char>::PStringBase<char>(&Offset_3, "Offset");
  return atexit(_E248_4);
}

//----- (006D7600) --------------------------------------------------------  // acclient.c:749505
int _E250_2()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_4, "Quaternion");
  return atexit(_E251_4);
}

//----- (006D7620) --------------------------------------------------------  // acclient.c:749512
int _E253_2()
{
  PStringBase<char>::PStringBase<char>(&Rotation_7, "Rotation");
  return atexit(_E254_5);
}

//----- (006D7640) --------------------------------------------------------  // acclient.c:749519
int _E256_2()
{
  PStringBase<char>::PStringBase<char>(&STime_3, "STime");
  return atexit(_E257_3);
}

//----- (006D7660) --------------------------------------------------------  // acclient.c:749526
int _E259_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_3, "PhysicsSplines");
  return atexit(_E260_4);
}

//----- (006D7680) --------------------------------------------------------  // acclient.c:749533
int _E262_2()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_3, "BoneOpacities");
  return atexit(_E263_2);
}

//----- (006D76A0) --------------------------------------------------------  // acclient.c:749540
int _E265_2()
{
  PStringBase<char>::PStringBase<char>(&LowPt_3, "LowPoint");
  return atexit(_E266_2);
}

//----- (006D76C0) --------------------------------------------------------  // acclient.c:749547
int _E268_2()
{
  PStringBase<char>::PStringBase<char>(&Radius_3, "Radius");
  return atexit(_E269_2);
}

//----- (006D76E0) --------------------------------------------------------  // acclient.c:749554
int _E271_1()
{
  PStringBase<char>::PStringBase<char>(&Height_3, "Height");
  return atexit(_E272_1);
}

//----- (006D7700) --------------------------------------------------------  // acclient.c:749561
int _E274_1()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_3, "Texture2D");
  return atexit(_E275_1);
}

//----- (006D7720) --------------------------------------------------------  // acclient.c:749568
int _E277_1()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_3, "Texture3D");
  return atexit(_E278_1);
}

//----- (006D7740) --------------------------------------------------------  // acclient.c:749575
int _E280_1()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_3, "TextureCube");
  return atexit(_E281_2);
}

//----- (006D7760) --------------------------------------------------------  // acclient.c:749582
int _E283_1()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_3, "TextureMovie2D");
  return atexit(_E284_1);
}

//----- (006D7780) --------------------------------------------------------  // acclient.c:749589
int _E286_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_3, "MovieFile");
  return atexit(_E287_2);
}

//----- (006D77A0) --------------------------------------------------------  // acclient.c:749596
int _E289_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_3, "MovieFPS");
  return atexit(_E290_2);
}

//----- (006D77C0) --------------------------------------------------------  // acclient.c:749603
int _E292_1()
{
  PStringBase<char>::PStringBase<char>(&Levels_3, "Levels");
  return atexit(_E293_1);
}

//----- (006D77E0) --------------------------------------------------------  // acclient.c:749610
int _E295_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_39, "Instance");
  return atexit(_E296_2);
}

//----- (006D7800) --------------------------------------------------------  // acclient.c:749617
int _E298_1()
{
  PStringBase<char>::PStringBase<char>(&Material_18, "Material");
  return atexit(_E299_0);
}

//----- (006D7820) --------------------------------------------------------  // acclient.c:749624
int _E301_0()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_3, "MaterialType");
  return atexit(_E302_1);
}

//----- (006D7840) --------------------------------------------------------  // acclient.c:749631
int _E304_0()
{
  PStringBase<char>::PStringBase<char>(&Modifier_3, "Modifier");
  return atexit(_E305_0);
}

//----- (006D7860) --------------------------------------------------------  // acclient.c:749638
int _E307_0()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_3, "AllowStencilShadows");
  return atexit(_E308_1);
}

//----- (006D7880) --------------------------------------------------------  // acclient.c:749645
int _E310_0()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_3, "DiscardGeometry");
  return atexit(_E311_0);
}

//----- (006D78A0) --------------------------------------------------------  // acclient.c:749652
int _E313_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_40, "Material");
  return atexit(_E314_1);
}

//----- (006D78C0) --------------------------------------------------------  // acclient.c:749659
int _E316_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_3, "SortMode");
  return atexit(_E317_0);
}

//----- (006D78E0) --------------------------------------------------------  // acclient.c:749666
int _E319_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_3, "None");
  return atexit(_E320_1);
}

//----- (006D7900) --------------------------------------------------------  // acclient.c:749673
int _E322_0()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_3, "Triangle");
  return atexit(_E323_0);
}

//----- (006D7920) --------------------------------------------------------  // acclient.c:749680
int _E325_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_41, "Modifier");
  return atexit(_E326_1);
}

//----- (006D7940) --------------------------------------------------------  // acclient.c:749687
int _E328_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_42, "Property");
  return atexit(_E329_0);
}

//----- (006D7960) --------------------------------------------------------  // acclient.c:749694
int _E331_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_3, "Data");
  return atexit(_E332_1);
}

//----- (006D7980) --------------------------------------------------------  // acclient.c:749701
int _E334_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_3, "Waveform");
  return atexit(_E335_0);
}

//----- (006D79A0) --------------------------------------------------------  // acclient.c:749708
int _E337_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_3, "Color");
  return atexit(_E338_0);
}

//----- (006D79C0) --------------------------------------------------------  // acclient.c:749715
int _E340_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_3, "Texture");
  return atexit(_E341_0);
}

//----- (006D79E0) --------------------------------------------------------  // acclient.c:749722
int _E343_0()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_3, "Bool");
  return atexit(_E344_0);
}

//----- (006D7A00) --------------------------------------------------------  // acclient.c:749729
int _E346_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_43, "Layer");
  return atexit(_E347_0);
}

//----- (006D7A20) --------------------------------------------------------  // acclient.c:749736
int _E349_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_3, "UVTranslate");
  return atexit(_E350_0);
}

//----- (006D7A40) --------------------------------------------------------  // acclient.c:749743
int _E352_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_3, "UVRotate");
  return atexit(_E353_0);
}

//----- (006D7A60) --------------------------------------------------------  // acclient.c:749750
int _E355_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_3, "UVScale");
  return atexit(_E356_0);
}

//----- (006D7A80) --------------------------------------------------------  // acclient.c:749757
int _E358_0()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_3, "UVTransform");
  return atexit(_E359_0);
}

//----- (006D7AA0) --------------------------------------------------------  // acclient.c:749764
int _E361_0()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_3, "TrueFlags");
  return atexit(_E362_0);
}

//----- (006D7AC0) --------------------------------------------------------  // acclient.c:749771
int _E364_0()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_3, "FalseFlags");
  return atexit(_E365_0);
}

//----- (006D7AE0) --------------------------------------------------------  // acclient.c:749778
int _E367_0()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_3, "RenderPass");
  return atexit(_E368_0);
}

//----- (006D7B00) --------------------------------------------------------  // acclient.c:749785
int _E370_0()
{
  PStringBase<char>::PStringBase<char>(&Blend_3, "Blend");
  return atexit(_E371_0);
}

//----- (006D7B20) --------------------------------------------------------  // acclient.c:749792
int _E373_0()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_3, "DepthTest");
  return atexit(_E374_0);
}

//----- (006D7B40) --------------------------------------------------------  // acclient.c:749799
int _E376_0()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_3, "DepthWrite");
  return atexit(_E377_0);
}

//----- (006D7B60) --------------------------------------------------------  // acclient.c:749806
int _E379_0()
{
  PStringBase<char>::PStringBase<char>(&CullMode_3, "CullMode");
  return atexit(_E380_0);
}

//----- (006D7B80) --------------------------------------------------------  // acclient.c:749813
int _E382_0()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_3, "DepthFog");
  return atexit(_E383_0);
}

//----- (006D7BA0) --------------------------------------------------------  // acclient.c:749820
int _E385_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_3, "AlphaTestMode");
  return atexit(_E386_0);
}

//----- (006D7BC0) --------------------------------------------------------  // acclient.c:749827
int _E388_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_3, "AlphaTestRef");
  return atexit(_E389_0);
}

//----- (006D7BE0) --------------------------------------------------------  // acclient.c:749834
int _E391_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_3, "FFUseLighting");
  return atexit(_E392_0);
}

//----- (006D7C00) --------------------------------------------------------  // acclient.c:749841
int _E394_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_3, "FFUseDyeColorInTFactor");
  return atexit(_E395_0);
}

//----- (006D7C20) --------------------------------------------------------  // acclient.c:749848
int _E397_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_3, "FFUseSpecularLighting");
  return atexit(_E398_0);
}

//----- (006D7C40) --------------------------------------------------------  // acclient.c:749855
int _E400_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_3, "FFUseDistanceFog");
  return atexit(_E401_0);
}

//----- (006D7C60) --------------------------------------------------------  // acclient.c:749862
int _E403_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_3, "FFUseVertexDiffuse");
  return atexit(_E404_0);
}

//----- (006D7C80) --------------------------------------------------------  // acclient.c:749869
int _E406_0()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_3, "FFUseVertexSpecular");
  return atexit(_E407_0);
}

//----- (006D7CA0) --------------------------------------------------------  // acclient.c:749876
int _E409_0()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_3, "ShaderSupportsDynamicLights");
  return atexit(_E410_0);
}

//----- (006D7CC0) --------------------------------------------------------  // acclient.c:749883
int _E412_0()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_3, "UsesTransparency");
  return atexit(_E413_0);
}

//----- (006D7CE0) --------------------------------------------------------  // acclient.c:749890
int _E415_0()
{
  PStringBase<char>::PStringBase<char>(&Ambient_3, "Ambient");
  return atexit(_E416_0);
}

//----- (006D7D00) --------------------------------------------------------  // acclient.c:749897
int _E418_0()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_8, "Diffuse");
  return atexit(_E419_0);
}

//----- (006D7D20) --------------------------------------------------------  // acclient.c:749904
int _E421_0()
{
  PStringBase<char>::PStringBase<char>(&Specular_8, "Specular");
  return atexit(_E422_0);
}

//----- (006D7D40) --------------------------------------------------------  // acclient.c:749911
int _E424_0()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_3, "SpecularPower");
  return atexit(_E425_0);
}

//----- (006D7D60) --------------------------------------------------------  // acclient.c:749918
int _E427_0()
{
  PStringBase<char>::PStringBase<char>(&Dye_3, "Dye");
  return atexit(_E428_0);
}

//----- (006D7D80) --------------------------------------------------------  // acclient.c:749925
int _E430_0()
{
  PStringBase<char>::PStringBase<char>(&Emissive_3, "Emissive");
  return atexit(_E431_0);
}

//----- (006D7DA0) --------------------------------------------------------  // acclient.c:749932
int _E433_0()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_3, "VertexFormat");
  return atexit(_E434_0);
}

//----- (006D7DC0) --------------------------------------------------------  // acclient.c:749939
int _E436_0()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_3, "VertexShader");
  return atexit(_E437_0);
}

//----- (006D7DE0) --------------------------------------------------------  // acclient.c:749946
int _E439_0()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_3, "PixelShader");
  return atexit(_E440_0);
}

//----- (006D7E00) --------------------------------------------------------  // acclient.c:749953
int _E442_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_3, "None");
  return atexit(_E443_0);
}

//----- (006D7E20) --------------------------------------------------------  // acclient.c:749960
int _E445_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_3, "Reflections");
  return atexit(_E446_0);
}

//----- (006D7E40) --------------------------------------------------------  // acclient.c:749967
int _E448_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_3, "VideoPost");
  return atexit(_E449_0);
}

//----- (006D7E60) --------------------------------------------------------  // acclient.c:749974
int _E451_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_3, "HighDetail");
  return atexit(_E452_0);
}

//----- (006D7E80) --------------------------------------------------------  // acclient.c:749981
int _E454_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_3, "Specular");
  return atexit(_E455_0);
}

//----- (006D7EA0) --------------------------------------------------------  // acclient.c:749988
int _E457_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_3, "Class1");
  return atexit(_E458_0);
}

//----- (006D7EC0) --------------------------------------------------------  // acclient.c:749995
int _E460_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_3, "Class2");
  return atexit(_E461_0);
}

//----- (006D7EE0) --------------------------------------------------------  // acclient.c:750002
int _E463_0()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_3, "Class3");
  return atexit(_E464_0);
}

//----- (006D7F00) --------------------------------------------------------  // acclient.c:750009
int _E466_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_3, "Default");
  return atexit(_E467_0);
}

//----- (006D7F20) --------------------------------------------------------  // acclient.c:750016
int _E469_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_3,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E470_0);
}

//----- (006D7F40) --------------------------------------------------------  // acclient.c:750025
int _E472_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_3, "PointLightDiffuseAndSpecular");
  return atexit(_E473_0);
}

//----- (006D7F60) --------------------------------------------------------  // acclient.c:750032
int _E475_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_3,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E476_0);
}

//----- (006D7F80) --------------------------------------------------------  // acclient.c:750041
int _E478_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_3,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E479_0);
}

//----- (006D7FA0) --------------------------------------------------------  // acclient.c:750050
int _E481_0()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_3,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E482_0);
}

//----- (006D7FC0) --------------------------------------------------------  // acclient.c:750059
int _E484_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_3, "DistanceFog");
  return atexit(_E485_0);
}

//----- (006D7FE0) --------------------------------------------------------  // acclient.c:750066
int _E487_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_3, "FFGlow");
  return atexit(_E488_0);
}

//----- (006D8000) --------------------------------------------------------  // acclient.c:750073
int _E490_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_3, "ShaderGlow");
  return atexit(_E491_0);
}

//----- (006D8020) --------------------------------------------------------  // acclient.c:750080
int _E493_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_3, "LandscapeShadowMap");
  return atexit(_E494_0);
}

//----- (006D8040) --------------------------------------------------------  // acclient.c:750087
int _E496_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_3, "AlphaBlend");
  return atexit(_E497_0);
}

//----- (006D8060) --------------------------------------------------------  // acclient.c:750094
int _E499_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_3, "AL_0DL_0PL");
  return atexit(_E500_0);
}

//----- (006D8080) --------------------------------------------------------  // acclient.c:750101
int _E502_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_3, "AL_0DL_1PL");
  return atexit(_E503_0);
}

//----- (006D80A0) --------------------------------------------------------  // acclient.c:750108
int _E505_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_3, "AL_0DL_2PL");
  return atexit(_E506_0);
}

//----- (006D80C0) --------------------------------------------------------  // acclient.c:750115
int _E508_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_3, "AL_0DL_3PL");
  return atexit(_E509_0);
}

//----- (006D80E0) --------------------------------------------------------  // acclient.c:750122
int _E511_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_3, "AL_0DL_4PL");
  return atexit(_E512_0);
}

//----- (006D8100) --------------------------------------------------------  // acclient.c:750129
int _E514_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_3, "AL_0DL_5PL");
  return atexit(_E515_0);
}

//----- (006D8120) --------------------------------------------------------  // acclient.c:750136
int _E517_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_3, "AL_0DL_6PL");
  return atexit(_E518_0);
}

//----- (006D8140) --------------------------------------------------------  // acclient.c:750143
int _E520_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_3, "AL_0DL_7PL");
  return atexit(_E521_0);
}

//----- (006D8160) --------------------------------------------------------  // acclient.c:750150
int _E523_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_3, "AL_0DL_8PL");
  return atexit(_E524_0);
}

//----- (006D8180) --------------------------------------------------------  // acclient.c:750157
int _E526_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_3, "AL_1DL_0PL");
  return atexit(_E527_0);
}

//----- (006D81A0) --------------------------------------------------------  // acclient.c:750164
int _E529_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_3, "AL_1DL_1PL");
  return atexit(_E530_0);
}

//----- (006D81C0) --------------------------------------------------------  // acclient.c:750171
int _E532_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_3, "AL_1DL_2PL");
  return atexit(_E533_0);
}

//----- (006D81E0) --------------------------------------------------------  // acclient.c:750178
int _E535_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_3, "AL_1DL_3PL");
  return atexit(_E536_0);
}

//----- (006D8200) --------------------------------------------------------  // acclient.c:750185
int _E538_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_3, "AL_1DL_4PL");
  return atexit(_E539_0);
}

//----- (006D8220) --------------------------------------------------------  // acclient.c:750192
int _E541_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_3, "AL_1DL_5PL");
  return atexit(_E542_0);
}

//----- (006D8240) --------------------------------------------------------  // acclient.c:750199
int _E544_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_3, "AL_1DL_6PL");
  return atexit(_E545_0);
}

//----- (006D8260) --------------------------------------------------------  // acclient.c:750206
int _E547_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_3, "AL_1DL_7PL");
  return atexit(_E548_0);
}

//----- (006D8280) --------------------------------------------------------  // acclient.c:750213
int _E550_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_3, "AL_0DL_0PL_Fog");
  return atexit(_E551_0);
}

//----- (006D82A0) --------------------------------------------------------  // acclient.c:750220
int _E553_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_3, "AL_0DL_1PL_Fog");
  return atexit(_E554_0);
}

//----- (006D82C0) --------------------------------------------------------  // acclient.c:750227
int _E556_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_3, "AL_0DL_2PL_Fog");
  return atexit(_E557_0);
}

//----- (006D82E0) --------------------------------------------------------  // acclient.c:750234
int _E559_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_3, "AL_0DL_3PL_Fog");
  return atexit(_E560_0);
}

//----- (006D8300) --------------------------------------------------------  // acclient.c:750241
int _E562_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_3, "AL_0DL_4PL_Fog");
  return atexit(_E563_0);
}

//----- (006D8320) --------------------------------------------------------  // acclient.c:750248
int _E565_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_3, "AL_0DL_5PL_Fog");
  return atexit(_E566_0);
}

//----- (006D8340) --------------------------------------------------------  // acclient.c:750255
int _E568_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_3, "AL_0DL_6PL_Fog");
  return atexit(_E569_0);
}

//----- (006D8360) --------------------------------------------------------  // acclient.c:750262
int _E571_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_3, "AL_0DL_7PL_Fog");
  return atexit(_E572_0);
}

//----- (006D8380) --------------------------------------------------------  // acclient.c:750269
int _E574_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_3, "AL_0DL_8PL_Fog");
  return atexit(_E575_0);
}

//----- (006D83A0) --------------------------------------------------------  // acclient.c:750276
int _E577_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_3, "AL_1DL_0PL_Fog");
  return atexit(_E578_0);
}

//----- (006D83C0) --------------------------------------------------------  // acclient.c:750283
int _E580_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_3, "AL_1DL_1PL_Fog");
  return atexit(_E581_0);
}

//----- (006D83E0) --------------------------------------------------------  // acclient.c:750290
int _E583_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_3, "AL_1DL_2PL_Fog");
  return atexit(_E584_0);
}

//----- (006D8400) --------------------------------------------------------  // acclient.c:750297
int _E586_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_3, "AL_1DL_3PL_Fog");
  return atexit(_E587_0);
}

//----- (006D8420) --------------------------------------------------------  // acclient.c:750304
int _E589_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_3, "AL_1DL_4PL_Fog");
  return atexit(_E590_0);
}

//----- (006D8440) --------------------------------------------------------  // acclient.c:750311
int _E592_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_3, "AL_1DL_5PL_Fog");
  return atexit(_E593_0);
}

//----- (006D8460) --------------------------------------------------------  // acclient.c:750318
int _E595_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_3, "AL_1DL_6PL_Fog");
  return atexit(_E596_0);
}

//----- (006D8480) --------------------------------------------------------  // acclient.c:750325
int _E598_0()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_3, "AL_1DL_7PL_Fog");
  return atexit(_E599_0);
}

//----- (006D84A0) --------------------------------------------------------  // acclient.c:750332
int _E601_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_3, "Zero");
  return atexit(_E602_0);
}

//----- (006D84C0) --------------------------------------------------------  // acclient.c:750339
int _E604_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_3, "One");
  return atexit(_E605_0);
}

//----- (006D84E0) --------------------------------------------------------  // acclient.c:750346
int _E607_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_3, "SrcColor");
  return atexit(_E608_0);
}

//----- (006D8500) --------------------------------------------------------  // acclient.c:750353
int _E610_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_3, "InvSrcColor");
  return atexit(_E611_0);
}

//----- (006D8520) --------------------------------------------------------  // acclient.c:750360
int _E613_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_3, "SrcAlpha");
  return atexit(_E614_0);
}

//----- (006D8540) --------------------------------------------------------  // acclient.c:750367
int _E616_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_3, "InvSrcAlpha");
  return atexit(_E617_0);
}

//----- (006D8560) --------------------------------------------------------  // acclient.c:750374
int _E619_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_3, "DstAlpha");
  return atexit(_E620_0);
}

//----- (006D8580) --------------------------------------------------------  // acclient.c:750381
int _E622_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_3, "InvDstAlpha");
  return atexit(_E623_0);
}

//----- (006D85A0) --------------------------------------------------------  // acclient.c:750388
int _E625_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_3, "DstColor");
  return atexit(_E626_0);
}

//----- (006D85C0) --------------------------------------------------------  // acclient.c:750395
int _E628_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_3, "InvDstColor");
  return atexit(_E629_0);
}

//----- (006D85E0) --------------------------------------------------------  // acclient.c:750402
int _E631_0()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_3, "SrcAlphaSat");
  return atexit(_E632_0);
}

//----- (006D8600) --------------------------------------------------------  // acclient.c:750409
int _E634_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_3, "Less");
  return atexit(_E635_0);
}

//----- (006D8620) --------------------------------------------------------  // acclient.c:750416
int _E637_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_3, "Equal");
  return atexit(_E638_0);
}

//----- (006D8640) --------------------------------------------------------  // acclient.c:750423
int _E640_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_3, "LessEqual");
  return atexit(_E641_0);
}

//----- (006D8660) --------------------------------------------------------  // acclient.c:750430
int _E643_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_3, "Greater");
  return atexit(_E644_0);
}

//----- (006D8680) --------------------------------------------------------  // acclient.c:750437
int _E646_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_3, "NotEqual");
  return atexit(_E647_0);
}

//----- (006D86A0) --------------------------------------------------------  // acclient.c:750444
int _E649_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_3, "GreaterEqual");
  return atexit(_E650_0);
}

//----- (006D86C0) --------------------------------------------------------  // acclient.c:750451
int _E652_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_3, "Always");
  return atexit(_E653_0);
}

//----- (006D86E0) --------------------------------------------------------  // acclient.c:750458
int _E655_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_3, "On");
  return atexit(_E656_0);
}

//----- (006D8700) --------------------------------------------------------  // acclient.c:750465
int _E658_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_3, "Off");
  return atexit(_E659_0);
}

//----- (006D8720) --------------------------------------------------------  // acclient.c:750472
int _E661_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_3, "LayerDiffuse");
  return atexit(_E662_0);
}

//----- (006D8740) --------------------------------------------------------  // acclient.c:750479
int _E664_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_3, "LayerSpecular");
  return atexit(_E665_0);
}

//----- (006D8760) --------------------------------------------------------  // acclient.c:750486
int _E667_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_3, "VertexDiffuse");
  return atexit(_E668_0);
}

//----- (006D8780) --------------------------------------------------------  // acclient.c:750493
int _E670_0()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_3, "VertexSpecular");
  return atexit(_E671_0);
}

//----- (006D87A0) --------------------------------------------------------  // acclient.c:750500
int _E673_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_3, "None");
  return atexit(_E674_0);
}

//----- (006D87C0) --------------------------------------------------------  // acclient.c:750507
int _E676_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_3, "CW");
  return atexit(_E677_0);
}

//----- (006D87E0) --------------------------------------------------------  // acclient.c:750514
int _E679_0()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_3, "CCW");
  return atexit(_E680_0);
}

//----- (006D8800) --------------------------------------------------------  // acclient.c:750521
int _E682_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_3, "None");
  return atexit(_E683_0);
}

//----- (006D8820) --------------------------------------------------------  // acclient.c:750528
int _E685_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_3, "Simple");
  return atexit(_E686_0);
}

//----- (006D8840) --------------------------------------------------------  // acclient.c:750535
int _E688_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_3, "Diffuse");
  return atexit(_E689_0);
}

//----- (006D8860) --------------------------------------------------------  // acclient.c:750542
int _E691_0()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_3, "Specular");
  return atexit(_E692_0);
}

//----- (006D8880) --------------------------------------------------------  // acclient.c:750549
int _E694_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_3, "Off");
  return atexit(_E695_0);
}

//----- (006D88A0) --------------------------------------------------------  // acclient.c:750556
int _E697_0()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_3, "On");
  return atexit(_E698_0);
}

//----- (006D88C0) --------------------------------------------------------  // acclient.c:750563
int _E700_0()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_3, "Off");
  return atexit(_E701_0);
}

//----- (006D88E0) --------------------------------------------------------  // acclient.c:750570
int _E703_0()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_3, "On");
  return atexit(_E704_0);
}

//----- (006D8900) --------------------------------------------------------  // acclient.c:750577
int _E706_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_3, "Origin");
  return atexit(_E707_0);
}

//----- (006D8920) --------------------------------------------------------  // acclient.c:750584
int _E709_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_3, "Normal");
  return atexit(_E710_0);
}

//----- (006D8940) --------------------------------------------------------  // acclient.c:750591
int _E712_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_3, "PointSize");
  return atexit(_E713_0);
}

//----- (006D8960) --------------------------------------------------------  // acclient.c:750598
int _E715_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_3, "Diffuse");
  return atexit(_E716_0);
}

//----- (006D8980) --------------------------------------------------------  // acclient.c:750605
int _E718_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_3, "Specular");
  return atexit(_E719_0);
}

//----- (006D89A0) --------------------------------------------------------  // acclient.c:750612
int _E721_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_3, "TCPairX1");
  return atexit(_E722_0);
}

//----- (006D89C0) --------------------------------------------------------  // acclient.c:750619
int _E724_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_3, "TCPairX2");
  return atexit(_E725_0);
}

//----- (006D89E0) --------------------------------------------------------  // acclient.c:750626
int _E727_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_3, "TCPairX3");
  return atexit(_E728_0);
}

//----- (006D8A00) --------------------------------------------------------  // acclient.c:750633
int _E730_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_3, "TCPairX4");
  return atexit(_E731_0);
}

//----- (006D8A20) --------------------------------------------------------  // acclient.c:750640
int _E733_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_3, "TCPairX5");
  return atexit(_E734_0);
}

//----- (006D8A40) --------------------------------------------------------  // acclient.c:750647
int _E736_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_3, "TCPairX6");
  return atexit(_E737_0);
}

//----- (006D8A60) --------------------------------------------------------  // acclient.c:750654
int _E739_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_3, "TCPairX7");
  return atexit(_E740_0);
}

//----- (006D8A80) --------------------------------------------------------  // acclient.c:750661
int _E742_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_3, "TCPairX8");
  return atexit(_E743_0);
}

//----- (006D8AA0) --------------------------------------------------------  // acclient.c:750668
int _E745_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_3, "VectorS");
  return atexit(_E746_0);
}

//----- (006D8AC0) --------------------------------------------------------  // acclient.c:750675
int _E748_0()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_3, "VectorT");
  return atexit(_E749_0);
}

//----- (006D8AE0) --------------------------------------------------------  // acclient.c:750682
int _E751_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_44, "Stage");
  return atexit(_E752_0);
}

//----- (006D8B00) --------------------------------------------------------  // acclient.c:750689
int _E754_0()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_3, "Sampler");
  return atexit(_E755_0);
}

//----- (006D8B20) --------------------------------------------------------  // acclient.c:750696
int _E757_0()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_3, "SamplerName");
  return atexit(_E758_0);
}

//----- (006D8B40) --------------------------------------------------------  // acclient.c:750703
int _E760_0()
{
  PStringBase<char>::PStringBase<char>(&Texture_3, "Texture");
  return atexit(_E761_0);
}

//----- (006D8B60) --------------------------------------------------------  // acclient.c:750710
int _E763_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_3, "!FrameBuffer");
  return atexit(_E764_0);
}

//----- (006D8B80) --------------------------------------------------------  // acclient.c:750717
int _E766_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_3, "!Distortion");
  return atexit(_E767_0);
}

//----- (006D8BA0) --------------------------------------------------------  // acclient.c:750724
int _E769_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_3, "!Reflection");
  return atexit(_E770_0);
}

//----- (006D8BC0) --------------------------------------------------------  // acclient.c:750731
int _E772_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_3, "!NormalizeCube");
  return atexit(_E773_0);
}

//----- (006D8BE0) --------------------------------------------------------  // acclient.c:750738
int _E775_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_3, "!LightProjectorCube");
  return atexit(_E776_0);
}

//----- (006D8C00) --------------------------------------------------------  // acclient.c:750745
int _E778_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_3, "!EnvironmentCube");
  return atexit(_E779_0);
}

//----- (006D8C20) --------------------------------------------------------  // acclient.c:750752
int _E781_0()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_3, "!LandscapeShadows");
  return atexit(_E782_0);
}

//----- (006D8C40) --------------------------------------------------------  // acclient.c:750759
int _E784_0()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_3, "AddressMode");
  return atexit(_E785_0);
}

//----- (006D8C60) --------------------------------------------------------  // acclient.c:750766
int _E787_0()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_3, "FilterMode");
  return atexit(_E788_0);
}

//----- (006D8C80) --------------------------------------------------------  // acclient.c:750773
int _E790_0()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_3, "FFColorOp");
  return atexit(_E791_0);
}

//----- (006D8CA0) --------------------------------------------------------  // acclient.c:750780
int _E793_0()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_3, "FFColorArg1");
  return atexit(_E794_0);
}

//----- (006D8CC0) --------------------------------------------------------  // acclient.c:750787
int _E796_0()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_3, "FFColorArg2");
  return atexit(_E797_0);
}

//----- (006D8CE0) --------------------------------------------------------  // acclient.c:750794
int _E799_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_3, "FFAlphaOp");
  return atexit(_E800_0);
}

//----- (006D8D00) --------------------------------------------------------  // acclient.c:750801
int _E802_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_3, "FFAlphaArg1");
  return atexit(_E803_0);
}

//----- (006D8D20) --------------------------------------------------------  // acclient.c:750808
int _E805_0()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_3, "FFAlphaArg2");
  return atexit(_E806_0);
}

//----- (006D8D40) --------------------------------------------------------  // acclient.c:750815
int _E808_0()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_3, "FFTexCoordIndex");
  return atexit(_E809_0);
}

//----- (006D8D60) --------------------------------------------------------  // acclient.c:750822
int _E811_0()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_3, "FFUseProjection");
  return atexit(_E812_0);
}

//----- (006D8D80) --------------------------------------------------------  // acclient.c:750829
int _E814_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_3, "SelectArg1");
  return atexit(_E815_0);
}

//----- (006D8DA0) --------------------------------------------------------  // acclient.c:750836
int _E817_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_3, "SelectArg2");
  return atexit(_E818_0);
}

//----- (006D8DC0) --------------------------------------------------------  // acclient.c:750843
int _E820_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_3, "Modulate");
  return atexit(_E821_0);
}

//----- (006D8DE0) --------------------------------------------------------  // acclient.c:750850
int _E823_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_3, "Modulate2X");
  return atexit(_E824_0);
}

//----- (006D8E00) --------------------------------------------------------  // acclient.c:750857
int _E826_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_3, "Modulate4X");
  return atexit(_E827_0);
}

//----- (006D8E20) --------------------------------------------------------  // acclient.c:750864
int _E829_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_3, "Add");
  return atexit(_E830_0);
}

//----- (006D8E40) --------------------------------------------------------  // acclient.c:750871
int _E832_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_3, "AddSigned");
  return atexit(_E833_0);
}

//----- (006D8E60) --------------------------------------------------------  // acclient.c:750878
int _E835_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_3, "AddSigned2X");
  return atexit(_E836_0);
}

//----- (006D8E80) --------------------------------------------------------  // acclient.c:750885
int _E838_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_3, "Subtract");
  return atexit(_E839_0);
}

//----- (006D8EA0) --------------------------------------------------------  // acclient.c:750892
int _E841_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_3, "AddSmooth");
  return atexit(_E842_0);
}

//----- (006D8EC0) --------------------------------------------------------  // acclient.c:750899
int _E844_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_3, "BlendDiffuseAlpha");
  return atexit(_E845_0);
}

//----- (006D8EE0) --------------------------------------------------------  // acclient.c:750906
int _E847_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_3, "BlendTextureAlpha");
  return atexit(_E848_0);
}

//----- (006D8F00) --------------------------------------------------------  // acclient.c:750913
int _E850_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_3, "BlendFactorAlpha");
  return atexit(_E851_0);
}

//----- (006D8F20) --------------------------------------------------------  // acclient.c:750920
int _E853_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_3, "BlendTextureAlphaPM");
  return atexit(_E854_0);
}

//----- (006D8F40) --------------------------------------------------------  // acclient.c:750927
int _E856_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_3, "BlendCurrentAlpha");
  return atexit(_E857_0);
}

//----- (006D8F60) --------------------------------------------------------  // acclient.c:750934
int _E859_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_3, "Premodulate");
  return atexit(_E860_0);
}

//----- (006D8F80) --------------------------------------------------------  // acclient.c:750941
int _E862_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_3, "ModulateAlphaAddColor");
  return atexit(_E863_0);
}

//----- (006D8FA0) --------------------------------------------------------  // acclient.c:750948
int _E865_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_3, "ModulateColorAddAlpha");
  return atexit(_E866_0);
}

//----- (006D8FC0) --------------------------------------------------------  // acclient.c:750955
int _E868_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_3, "ModulateInvAlphaAddColor");
  return atexit(_E869_0);
}

//----- (006D8FE0) --------------------------------------------------------  // acclient.c:750962
int _E871_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_3, "ModulateInvColorAddAlpha");
  return atexit(_E872_0);
}

//----- (006D9000) --------------------------------------------------------  // acclient.c:750969
int _E874_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_3, "BumpEnvMap");
  return atexit(_E875_0);
}

//----- (006D9020) --------------------------------------------------------  // acclient.c:750976
int _E877_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_3, "BumpEnvMapLuminance");
  return atexit(_E878_0);
}

//----- (006D9040) --------------------------------------------------------  // acclient.c:750983
int _E880_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_3, "DotProduct3");
  return atexit(_E881_0);
}

//----- (006D9060) --------------------------------------------------------  // acclient.c:750990
int _E883_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_3, "MultiplyAdd");
  return atexit(_E884_0);
}

//----- (006D9080) --------------------------------------------------------  // acclient.c:750997
int _E886_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_3, "Lerp");
  return atexit(_E887_0);
}

//----- (006D90A0) --------------------------------------------------------  // acclient.c:751004
int _E889_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_3, "Diffuse");
  return atexit(_E890_0);
}

//----- (006D90C0) --------------------------------------------------------  // acclient.c:751011
int _E892_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_3, "Specular");
  return atexit(_E893_0);
}

//----- (006D90E0) --------------------------------------------------------  // acclient.c:751018
int _E895_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_3, "Current");
  return atexit(_E896_0);
}

//----- (006D9100) --------------------------------------------------------  // acclient.c:751025
int _E898_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_3, "Texture");
  return atexit(_E899_0);
}

//----- (006D9120) --------------------------------------------------------  // acclient.c:751032
int _E901_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_3, "TFactor");
  return atexit(_E902_0);
}

//----- (006D9140) --------------------------------------------------------  // acclient.c:751039
int _E904_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_3, "Wrap");
  return atexit(_E905_0);
}

//----- (006D9160) --------------------------------------------------------  // acclient.c:751046
int _E907_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_3, "Mirror");
  return atexit(_E908_0);
}

//----- (006D9180) --------------------------------------------------------  // acclient.c:751053
int _E910_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_3, "Clamp");
  return atexit(_E911_0);
}

//----- (006D91A0) --------------------------------------------------------  // acclient.c:751060
int _E913_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_3, "Border");
  return atexit(_E914_0);
}

//----- (006D91C0) --------------------------------------------------------  // acclient.c:751067
int _E916_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_3, "None");
  return atexit(_E917_0);
}

//----- (006D91E0) --------------------------------------------------------  // acclient.c:751074
int _E919_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_3, "Point");
  return atexit(_E920_0);
}

//----- (006D9200) --------------------------------------------------------  // acclient.c:751081
int _E922_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_3, "Linear");
  return atexit(_E923_0);
}

//----- (006D9220) --------------------------------------------------------  // acclient.c:751088
int _E925_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_3, "Anisotropic");
  return atexit(_E926_0);
}

//----- (006D9240) --------------------------------------------------------  // acclient.c:751095
int _E928_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_3, "ReflectionVector");
  return atexit(_E929_0);
}

//----- (006D9260) --------------------------------------------------------  // acclient.c:751102
int _E931_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_3, "ViewNormal");
  return atexit(_E932_0);
}

//----- (006D9280) --------------------------------------------------------  // acclient.c:751109
int _E934_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_3, "ViewOrigin");
  return atexit(_E935_0);
}

//----- (006D92A0) --------------------------------------------------------  // acclient.c:751116
int _E937_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_3, "SphereMap");
  return atexit(_E938_0);
}

//----- (006D92C0) --------------------------------------------------------  // acclient.c:751123
int _E940_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_3, "CubeMapReflection");
  return atexit(_E941_0);
}

//----- (006D92E0) --------------------------------------------------------  // acclient.c:751130
int _E943_0()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_3, "CubeMapFakeLight");
  return atexit(_E944_0);
}

//----- (006D9300) --------------------------------------------------------  // acclient.c:751137
int _E946_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_45, "FFModifier");
  return atexit(_E947_0);
}

//----- (006D9320) --------------------------------------------------------  // acclient.c:751144
int _E949_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_3, "Origin");
  return atexit(_E950_0);
}

//----- (006D9340) --------------------------------------------------------  // acclient.c:751151
int _E952_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_3, "Normal");
  return atexit(_E953_0);
}

//----- (006D9360) --------------------------------------------------------  // acclient.c:751158
int _E955_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_3, "Diffuse");
  return atexit(_E956_0);
}

//----- (006D9380) --------------------------------------------------------  // acclient.c:751165
int _E958_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_3, "UVTranslate");
  return atexit(_E959_0);
}

//----- (006D93A0) --------------------------------------------------------  // acclient.c:751172
int _E961_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_3, "UVRotate");
  return atexit(_E962_0);
}

//----- (006D93C0) --------------------------------------------------------  // acclient.c:751179
int _E964_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_3, "UVScale");
  return atexit(_E965_0);
}

//----- (006D93E0) --------------------------------------------------------  // acclient.c:751186
int _E967_0()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_3, "UVTransform");
  return atexit(_E968_0);
}

//----- (006D9400) --------------------------------------------------------  // acclient.c:751193
int _E970_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_3, "TexCoordIndex");
  return atexit(_E971_0);
}

//----- (006D9420) --------------------------------------------------------  // acclient.c:751200
int _E973_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_3, "Translate");
  return atexit(_E974_0);
}

//----- (006D9440) --------------------------------------------------------  // acclient.c:751207
int _E976_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_3, "TexCoordIndex");
  return atexit(_E977_0);
}

//----- (006D9460) --------------------------------------------------------  // acclient.c:751214
int _E979_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_3, "Rotate");
  return atexit(_E980_0);
}

//----- (006D9480) --------------------------------------------------------  // acclient.c:751221
int _E982_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_3, "TexCoordIndex");
  return atexit(_E983_0);
}

//----- (006D94A0) --------------------------------------------------------  // acclient.c:751228
int _E985_0()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_3, "Scale");
  return atexit(_E986_0);
}

//----- (006D94C0) --------------------------------------------------------  // acclient.c:751235
int _E988_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_46, "PSDesc");
  return atexit(_E989_0);
}

//----- (006D94E0) --------------------------------------------------------  // acclient.c:751242
int _E991_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_3, "PhysicsTimeStep");
  return atexit(_E992_0);
}

//----- (006D9500) --------------------------------------------------------  // acclient.c:751249
int _E994_0()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_3, "FastForwardTime");
  return atexit(_E995_0);
}

//----- (006D9520) --------------------------------------------------------  // acclient.c:751256
int _E997_0()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_3, "StartFadeDistance");
  return atexit(_E998_0);
}

//----- (006D9540) --------------------------------------------------------  // acclient.c:751263
int _E1000_0()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_3, "StopFadeDistance");
  return atexit(_E1001_0);
}

//----- (006D9560) --------------------------------------------------------  // acclient.c:751270
int _E1003_0()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_3, "PhysicsDuration");
  return atexit(_E1004_0);
}

//----- (006D9580) --------------------------------------------------------  // acclient.c:751277
int _E1006_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_3, "ScaleType");
  return atexit(_E1007_0);
}

//----- (006D95A0) --------------------------------------------------------  // acclient.c:751284
int _E1009_0()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_3, "WorldSpace");
  return atexit(_E1010_0);
}

//----- (006D95C0) --------------------------------------------------------  // acclient.c:751291
int _E1012_0()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_3, "ForceDraw");
  return atexit(_E1013_0);
}

//----- (006D95E0) --------------------------------------------------------  // acclient.c:751298
int _E1015_0()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_3, "NumEmitters");
  return atexit(_E1016_0);
}

//----- (006D9600) --------------------------------------------------------  // acclient.c:751305
int _E1018_0()
{
  PStringBase<char>::PStringBase<char>(&Material_19, "Material");
  return atexit(_E1019_0);
}

//----- (006D9620) --------------------------------------------------------  // acclient.c:751312
int _E1021_0()
{
  PStringBase<char>::PStringBase<char>(&Version_3, "Version");
  return atexit(_E1022_0);
}

//----- (006D9640) --------------------------------------------------------  // acclient.c:751319
int _E1024_0()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_3, "MaxParticles");
  return atexit(_E1025_0);
}

//----- (006D9660) --------------------------------------------------------  // acclient.c:751326
int _E1027_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_47, "Emitter");
  return atexit(_E1028_0);
}

//----- (006D9680) --------------------------------------------------------  // acclient.c:751333
int _E1030_0()
{
  PStringBase<char>::PStringBase<char>(&Origin_8, "Origin");
  return atexit(_E1031_0);
}

//----- (006D96A0) --------------------------------------------------------  // acclient.c:751340
int _E1033_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_3, "Shape");
  return atexit(_E1034_0);
}

//----- (006D96C0) --------------------------------------------------------  // acclient.c:751347
int _E1036_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_3, "Point");
  return atexit(_E1037_0);
}

//----- (006D96E0) --------------------------------------------------------  // acclient.c:751354
int _E1039_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_3, "Line");
  return atexit(_E1040_0);
}

//----- (006D9700) --------------------------------------------------------  // acclient.c:751361
int _E1042_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_3, "Quad");
  return atexit(_E1043_0);
}

//----- (006D9720) --------------------------------------------------------  // acclient.c:751368
int _E1045_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_3, "Disc");
  return atexit(_E1046_0);
}

//----- (006D9740) --------------------------------------------------------  // acclient.c:751375
int _E1048_0()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_3, "Sphere");
  return atexit(_E1049_0);
}

//----- (006D9760) --------------------------------------------------------  // acclient.c:751382
int _E1051_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_3, "ParticleShape");
  return atexit(_E1052_0);
}

//----- (006D9780) --------------------------------------------------------  // acclient.c:751389
int _E1054_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_3, "Triangle");
  return atexit(_E1055_0);
}

//----- (006D97A0) --------------------------------------------------------  // acclient.c:751396
int _E1057_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_3, "Quad");
  return atexit(_E1058_0);
}

//----- (006D97C0) --------------------------------------------------------  // acclient.c:751403
int _E1060_0()
{
  PStringBase<char>::PStringBase<char>(&Streak_3, "Streak");
  return atexit(_E1061_0);
}

//----- (006D97E0) --------------------------------------------------------  // acclient.c:751410
int _E1063_0()
{
  PStringBase<char>::PStringBase<char>(&Rotation_8, "Rotation");
  return atexit(_E1064_0);
}

//----- (006D9800) --------------------------------------------------------  // acclient.c:751417
int _E1066_0()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_3, "WorldRotation");
  return atexit(_E1067_0);
}

//----- (006D9820) --------------------------------------------------------  // acclient.c:751424
int _E1069_0()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_3, "RotateVelocity");
  return atexit(_E1070_0);
}

//----- (006D9840) --------------------------------------------------------  // acclient.c:751431
int _E1072_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_3, "ParticleScale");
  return atexit(_E1073_0);
}

//----- (006D9860) --------------------------------------------------------  // acclient.c:751438
int _E1075_0()
{
  PStringBase<char>::PStringBase<char>(&Scale_12, "Scale");
  return atexit(_E1076_0);
}

//----- (006D9880) --------------------------------------------------------  // acclient.c:751445
int _E1078_0()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_3, "ExplodingDir");
  return atexit(_E1079_0);
}

//----- (006D98A0) --------------------------------------------------------  // acclient.c:751452
int _E1081_0()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_3, "BirthRate");
  return atexit(_E1082_0);
}

//----- (006D98C0) --------------------------------------------------------  // acclient.c:751459
int _E1084_0()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_3, "Lifespan");
  return atexit(_E1085_0);
}

//----- (006D98E0) --------------------------------------------------------  // acclient.c:751466
int _E1087_0()
{
  PStringBase<char>::PStringBase<char>(&Velocity_3, "Velocity");
  return atexit(_E1088_0);
}

//----- (006D9900) --------------------------------------------------------  // acclient.c:751473
int _E1090_0()
{
  PStringBase<char>::PStringBase<char>(&Direction_3, "Direction");
  return atexit(_E1091_0);
}

//----- (006D9920) --------------------------------------------------------  // acclient.c:751480
int _E1093_0()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_3, "MinSpread");
  return atexit(_E1094_0);
}

//----- (006D9940) --------------------------------------------------------  // acclient.c:751487
int _E1096_0()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_3, "MaxSpread");
  return atexit(_E1097_0);
}

//----- (006D9960) --------------------------------------------------------  // acclient.c:751494
int _E1099_0()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_3, "EmissionLimit");
  return atexit(_E1100_0);
}

//----- (006D9980) --------------------------------------------------------  // acclient.c:751501
int _E1102_0()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_3, "BlastCount");
  return atexit(_E1103_0);
}

//----- (006D99A0) --------------------------------------------------------  // acclient.c:751508
int _E1105_0()
{
  PStringBase<char>::PStringBase<char>(&StartTime_3, "StartTime");
  return atexit(_E1106_0);
}

//----- (006D99C0) --------------------------------------------------------  // acclient.c:751515
int _E1108_0()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_3, "TimeLimit");
  return atexit(_E1109_0);
}

//----- (006D99E0) --------------------------------------------------------  // acclient.c:751522
int _E1111_0()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_3, "EmissionDistance");
  return atexit(_E1112_0);
}

//----- (006D9A00) --------------------------------------------------------  // acclient.c:751529
int _E1114_0()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_3, "ParticleSnap");
  return atexit(_E1115_0);
}

//----- (006D9A20) --------------------------------------------------------  // acclient.c:751536
int _E1117_0()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_3, "InclusiveShape");
  return atexit(_E1118_0);
}

//----- (006D9A40) --------------------------------------------------------  // acclient.c:751543
int _E1120_0()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_3, "NumKeyframes");
  return atexit(_E1121_0);
}

//----- (006D9A60) --------------------------------------------------------  // acclient.c:751550
int _E1123_0()
{
  PStringBase<char>::PStringBase<char>(&IsActive_3, "IsActive");
  return atexit(_E1124_0);
}

//----- (006D9A80) --------------------------------------------------------  // acclient.c:751557
int _E1126_0()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_3, "FadeIn");
  return atexit(_E1127_0);
}

//----- (006D9AA0) --------------------------------------------------------  // acclient.c:751564
int _E1129_0()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_3, "FadeOut");
  return atexit(_E1130_0);
}

//----- (006D9AC0) --------------------------------------------------------  // acclient.c:751571
int _E1132_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_3, "ConstrainX");
  return atexit(_E1133_0);
}

//----- (006D9AE0) --------------------------------------------------------  // acclient.c:751578
int _E1135_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_3, "ConstrainY");
  return atexit(_E1136_0);
}

//----- (006D9B00) --------------------------------------------------------  // acclient.c:751585
int _E1138_0()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_3, "ConstrainZ");
  return atexit(_E1139_0);
}

//----- (006D9B20) --------------------------------------------------------  // acclient.c:751592
int _E1141_0()
{
  PStringBase<char>::PStringBase<char>(&NodeName_48, "Keyframe");
  return atexit(_E1142_0);
}

//----- (006D9B40) --------------------------------------------------------  // acclient.c:751599
int _E1144_0()
{
  PStringBase<char>::PStringBase<char>(&Time_3, "Time");
  return atexit(_E1145_0);
}

//----- (006D9B60) --------------------------------------------------------  // acclient.c:751606
int _E1147_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_3, "Flags");
  return atexit(_E1148_0);
}

//----- (006D9B80) --------------------------------------------------------  // acclient.c:751613
int _E1150_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_3, "None");
  return atexit(_E1151_0);
}

//----- (006D9BA0) --------------------------------------------------------  // acclient.c:751620
int _E1153_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_3, "BlendScale");
  return atexit(_E1154_0);
}

//----- (006D9BC0) --------------------------------------------------------  // acclient.c:751627
int _E1156_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_3, "BlendColor");
  return atexit(_E1157_0);
}

//----- (006D9BE0) --------------------------------------------------------  // acclient.c:751634
int _E1159_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_3, "BlendMass");
  return atexit(_E1160_0);
}

//----- (006D9C00) --------------------------------------------------------  // acclient.c:751641
int _E1162_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_3, "SetScale");
  return atexit(_E1163_0);
}

//----- (006D9C20) --------------------------------------------------------  // acclient.c:751648
int _E1165_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_3, "SetColor");
  return atexit(_E1166_0);
}

//----- (006D9C40) --------------------------------------------------------  // acclient.c:751655
int _E1168_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_3, "SetMass");
  return atexit(_E1169_0);
}

//----- (006D9C60) --------------------------------------------------------  // acclient.c:751662
int _E1171_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_3, "SetParticleFlags");
  return atexit(_E1172_0);
}

//----- (006D9C80) --------------------------------------------------------  // acclient.c:751669
int _E1174_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_3, "SetControllerType");
  return atexit(_E1175_0);
}

//----- (006D9CA0) --------------------------------------------------------  // acclient.c:751676
int _E1177_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_3, "SetPhysicsFlags");
  return atexit(_E1178_0);
}

//----- (006D9CC0) --------------------------------------------------------  // acclient.c:751683
int _E1180_0()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_3, "SetParams");
  return atexit(_E1181_0);
}

//----- (006D9CE0) --------------------------------------------------------  // acclient.c:751690
int _E1183_0()
{
  PStringBase<char>::PStringBase<char>(&Scale_13, "Scale");
  return atexit(_E1184_0);
}

//----- (006D9D00) --------------------------------------------------------  // acclient.c:751697
int _E1186_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_3, "ScaleX");
  return atexit(_E1187_0);
}

//----- (006D9D20) --------------------------------------------------------  // acclient.c:751704
int _E1189_0()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_3, "ScaleY");
  return atexit(_E1190_0);
}

//----- (006D9D40) --------------------------------------------------------  // acclient.c:751711
int _E1192_0()
{
  PStringBase<char>::PStringBase<char>(&Color_3, "Color");
  return atexit(_E1193_0);
}

//----- (006D9D60) --------------------------------------------------------  // acclient.c:751718
int _E1195_0()
{
  PStringBase<char>::PStringBase<char>(&Mass_3, "Mass");
  return atexit(_E1196_0);
}

//----- (006D9D80) --------------------------------------------------------  // acclient.c:751725
int _E1198_0()
{
  PStringBase<char>::PStringBase<char>(&PFlags_3, "ParticleFlags");
  return atexit(_E1199_0);
}

//----- (006D9DA0) --------------------------------------------------------  // acclient.c:751732
int _E1201_0()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_3, "None");
  return atexit(_E1202_0);
}

//----- (006D9DC0) --------------------------------------------------------  // acclient.c:751739
int _E1204_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_3, "ControllerType");
  return atexit(_E1205_0);
}

//----- (006D9DE0) --------------------------------------------------------  // acclient.c:751746
int _E1207_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_3, "None");
  return atexit(_E1208_0);
}

//----- (006D9E00) --------------------------------------------------------  // acclient.c:751753
int _E1210_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_3, "Physics");
  return atexit(_E1211_0);
}

//----- (006D9E20) --------------------------------------------------------  // acclient.c:751760
int _E1213_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_3, "Parametric");
  return atexit(_E1214_0);
}

//----- (006D9E40) --------------------------------------------------------  // acclient.c:751767
int _E1216_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_3, "AttractRepulse");
  return atexit(_E1217_0);
}

//----- (006D9E60) --------------------------------------------------------  // acclient.c:751774
int _E1219_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_3, "PointFile");
  return atexit(_E1220_0);
}

//----- (006D9E80) --------------------------------------------------------  // acclient.c:751781
int _E1222_0()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_3, "PointFileLerp");
  return atexit(_E1223_0);
}

//----- (006D9EA0) --------------------------------------------------------  // acclient.c:751788
int _E1225_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_3, "PhysicsFlags");
  return atexit(_E1226_0);
}

//----- (006D9EC0) --------------------------------------------------------  // acclient.c:751795
int _E1228_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_3, "None");
  return atexit(_E1229_0);
}

//----- (006D9EE0) --------------------------------------------------------  // acclient.c:751802
int _E1231_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_3, "Gravity");
  return atexit(_E1232_0);
}

//----- (006D9F00) --------------------------------------------------------  // acclient.c:751809
int _E1234_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_3, "Wind");
  return atexit(_E1235_0);
}

//----- (006D9F20) --------------------------------------------------------  // acclient.c:751816
int _E1237_0()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_3, "Momentum");
  return atexit(_E1238_0);
}

//----- (006D9F40) --------------------------------------------------------  // acclient.c:751823
int _E1240_0()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_3, "RandomPoint");
  return atexit(_E1241_0);
}

//----- (006D9F60) --------------------------------------------------------  // acclient.c:751830
int _E1243_0()
{
  PStringBase<char>::PStringBase<char>(&Position_4, "Position");
  return atexit(_E1244_0);
}

//----- (006D9F80) --------------------------------------------------------  // acclient.c:751837
int _E1246_0()
{
  PStringBase<char>::PStringBase<char>(&PointList_3, "PointList");
  return atexit(_E1247_0);
}

//----- (006D9FA0) --------------------------------------------------------  // acclient.c:751844
int _E1249_0()
{
  PStringBase<char>::PStringBase<char>(&Point_8, "pt");
  return atexit(_E1250_0);
}

//----- (006D9FC0) --------------------------------------------------------  // acclient.c:751851
int _E1252_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_3, "DetailLevels");
  return atexit(_E1253_0);
}

//----- (006D9FE0) --------------------------------------------------------  // acclient.c:751858
int _E1255_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_3, "Low");
  return atexit(_E1256_0);
}

//----- (006DA000) --------------------------------------------------------  // acclient.c:751865
int _E1258_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_3, "Medium");
  return atexit(_E1259_0);
}

//----- (006DA020) --------------------------------------------------------  // acclient.c:751872
int _E1261_0()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_3, "High");
  return atexit(_E1262_0);
}

//----- (006DA040) --------------------------------------------------------  // acclient.c:751879
int _E1264_0()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_3, "FadeSpeed");
  return atexit(_E1265_0);
}

//----- (006DA060) --------------------------------------------------------  // acclient.c:751886
int _E1267_0()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_3, "MaxOpacity");
  return atexit(_E1268_0);
}

//----- (006DA080) --------------------------------------------------------  // acclient.c:751893
int _E1270_0()
{
  PStringBase<char>::PStringBase<char>(&Point_9, "Point");
  return atexit(_E1271_0);
}

//----- (006DA0A0) --------------------------------------------------------  // acclient.c:751900
int _E1273_0()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_3, "AxisPos");
  return atexit(_E1274_0);
}

//----- (006DA0C0) --------------------------------------------------------  // acclient.c:751907
int _E1276_0()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_3, "Texture");
  return atexit(_E1277_0);
}

//----- (006DA0E0) --------------------------------------------------------  // acclient.c:751914
int _E1279_0()
{
  PStringBase<char>::PStringBase<char>(&PointSize_3, "Size");
  return atexit(_E1280_1);
}

//----- (006DA100) --------------------------------------------------------  // acclient.c:751921
int _E1282_0()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_3, "UseOcclusion");
  return atexit(_E1283_0);
}

//----- (006DA120) --------------------------------------------------------  // acclient.c:751928
int _E1285_0()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_3, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83A864, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83A868, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_83A86C, "PREPROC_OPTIONS");
  return atexit(_E1286_0);
}

//----- (006DA170) --------------------------------------------------------  // acclient.c:751938
void _E1288_0()
{
  LODWORD(dword_83A870) = 1053364187;
}

//----- (006DA180) --------------------------------------------------------  // acclient.c:751944
void _E1290_2()
{
  outside_val_15 = 1000.0 + 1.0;
}

//----- (006DA1A0) --------------------------------------------------------  // acclient.c:751950
void _E1292()
{
  block_length_15 = 24.0 * 8.0;
}

//----- (006DA1C0) --------------------------------------------------------  // acclient.c:751956
void _E1294_0()
{
  half_square_length_15 = 24.0 * 0.5;
}

//----- (006DA1E0) --------------------------------------------------------  // acclient.c:751962
int _E1296_2()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_10, "Render.TextureFiltering");
  return atexit(_E1297_6);
}

//----- (006DA200) --------------------------------------------------------  // acclient.c:751969
int _E1299_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_10, "Render.LandscapeDetailTextures");
  return atexit(_E1300_6);
}

//----- (006DA220) --------------------------------------------------------  // acclient.c:751976
int _E1302_2()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_10, "Render.BuildingDetailTextures");
  return atexit(_E1303_5);
}

//----- (006DA240) --------------------------------------------------------  // acclient.c:751983
int _E1305_2()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_10, "Render.FieldOfView");
  return atexit(_E1306_4);
}

//----- (006DA260) --------------------------------------------------------  // acclient.c:751990
int _E1308_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_10, "Render.LandscapeTextureDetail");
  return atexit(_E1309_4);
}

//----- (006DA280) --------------------------------------------------------  // acclient.c:751997
int _E1311_2()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_10, "Render.EnvironmentTextureDetail");
  return atexit(_E1312_4);
}

//----- (006DA2A0) --------------------------------------------------------  // acclient.c:752004
int _E1314_2()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_10, "Render.SceneryDrawDistance");
  return atexit(_E1315_2);
}

//----- (006DA2C0) --------------------------------------------------------  // acclient.c:752011
int _E1317_2()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_10, "Render.LandscapeDrawDistance");
  return atexit(_E1318_2);
}

//----- (006DA2E0) --------------------------------------------------------  // acclient.c:752018
int _E1320_2()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_10, "Render.ScreenBrightness");
  return atexit(_E1321_2);
}

//----- (006DA300) --------------------------------------------------------  // acclient.c:752025
int _E1323_2()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_10, "Render.AspectRatio");
  return atexit(_E1324_2);
}

//----- (006DA320) --------------------------------------------------------  // acclient.c:752032
int _E1326_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_10, "Render.DisplayAdapter");
  return atexit(_E1327_2);
}

//----- (006DA340) --------------------------------------------------------  // acclient.c:752039
int _E1329_2()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_10, "Render.MaxHardwareClass");
  return atexit(_E1330_2);
}

//----- (006DA360) --------------------------------------------------------  // acclient.c:752046
int _E1332_2()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_10, "Render.AutomaticDegrades");
  return atexit(_E1333_2);
}

//----- (006DA380) --------------------------------------------------------  // acclient.c:752053
int _E1335_2()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_10, "Render.GraphicsPerformance");
  return atexit(_E1336_2);
}

//----- (006DA3A0) --------------------------------------------------------  // acclient.c:752060
int _E1338_2()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_10, "Render.DegradeDistance");
  return atexit(_E1339_2);
}

//----- (006DA3C0) --------------------------------------------------------  // acclient.c:752067
int _E1341_2()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_10, "Render.MultiPassAlpha");
  return atexit(_E1342_2);
}

//----- (006DA3E0) --------------------------------------------------------  // acclient.c:752074
int _E1344_2()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_10, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_83A8C4, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_83A8C8, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_83A8CC, "Anisotropic");
  return atexit(_E1345_2);
}

//----- (006DA430) --------------------------------------------------------  // acclient.c:752084
int _E1347_2()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_10, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83A8D4, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83A8D8, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83A8DC, "High");
  PStringBase<char>::PStringBase<char>(&stru_83A8E0, "VeryHigh");
  return atexit(_E1348_2);
}

//----- (006DA490) --------------------------------------------------------  // acclient.c:752095
int _E1350_2()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_10, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83A8E8, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83A8EC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83A8F0, "High");
  PStringBase<char>::PStringBase<char>(&stru_83A8F4, "VeryHigh");
  return atexit(_E1351_2);
}

//----- (006DA4F0) --------------------------------------------------------  // acclient.c:752106
int _E1353_2()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_10, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83A8FC, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83A900, "High");
  return atexit(_E1354_2);
}

//----- (006DA530) --------------------------------------------------------  // acclient.c:752115
int _E1356_2()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_10, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_83A908, "Low");
  PStringBase<char>::PStringBase<char>(&stru_83A90C, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_83A910, "High");
  PStringBase<char>::PStringBase<char>(&stru_83A914, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_83A918, "Extreme");
  return atexit(_E1357_2);
}

//----- (006DA5A0) --------------------------------------------------------  // acclient.c:752127
int _E1359_2()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_10, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_83A920, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_83A924, "Wide");
  return atexit(_E1360_2);
}

//----- (006DA5E0) --------------------------------------------------------  // acclient.c:752136
int _E1362_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_17, "None");
  return atexit(_E1363_2);
}

//----- (006DA600) --------------------------------------------------------  // acclient.c:752143
int _E1365_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_17, "Speed");
  return atexit(_E1366_2);
}

//----- (006DA620) --------------------------------------------------------  // acclient.c:752150
int _E1368_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_17, "Noise");
  return atexit(_E1369_2);
}

//----- (006DA640) --------------------------------------------------------  // acclient.c:752157
int _E1371_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_17, "Sine");
  return atexit(_E1372_2);
}

//----- (006DA660) --------------------------------------------------------  // acclient.c:752164
int _E1374_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_17, "Square");
  return atexit(_E1375_2);
}

//----- (006DA680) --------------------------------------------------------  // acclient.c:752171
int _E1377_2()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_17, "Bounce");
  return atexit(_E1378_2);
}

//----- (006DA6A0) --------------------------------------------------------  // acclient.c:752178
int _E1380_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_17, "Perlin");
  return atexit(_E1381_1);
}

//----- (006DA6C0) --------------------------------------------------------  // acclient.c:752185
int _E1383_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_17, "Fractal");
  return atexit(_E1384_1);
}

//----- (006DA6E0) --------------------------------------------------------  // acclient.c:752192
int _E1386_1()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_17, "FrameLoop");
  return atexit(_E1387_1);
}

//----- (006DA700) --------------------------------------------------------  // acclient.c:752199
int _E1_41()
{
  return atexit(_E2_41);
}

//----- (00740C90) --------------------------------------------------------  // acclient.c:853620
void __cdecl _E1297_6()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740CC0) --------------------------------------------------------  // acclient.c:853633
void __cdecl _E1300_6()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740CF0) --------------------------------------------------------  // acclient.c:853646
void __cdecl _E1303_5()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740D20) --------------------------------------------------------  // acclient.c:853659
void __cdecl _E1306_4()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740D50) --------------------------------------------------------  // acclient.c:853672
void __cdecl _E1309_4()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740D80) --------------------------------------------------------  // acclient.c:853685
void __cdecl _E1312_4()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740DB0) --------------------------------------------------------  // acclient.c:853698
void __cdecl _E1315_2()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740DE0) --------------------------------------------------------  // acclient.c:853711
void __cdecl _E1318_2()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740E10) --------------------------------------------------------  // acclient.c:853724
void __cdecl _E1321_2()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740E40) --------------------------------------------------------  // acclient.c:853737
void __cdecl _E1324_2()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740E70) --------------------------------------------------------  // acclient.c:853750
void __cdecl _E1327_2()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740EA0) --------------------------------------------------------  // acclient.c:853763
void __cdecl _E1330_2()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740ED0) --------------------------------------------------------  // acclient.c:853776
void __cdecl _E1333_2()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740F00) --------------------------------------------------------  // acclient.c:853789
void __cdecl _E1336_2()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740F30) --------------------------------------------------------  // acclient.c:853802
void __cdecl _E1339_2()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740F60) --------------------------------------------------------  // acclient.c:853815
void __cdecl _E1342_2()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00740F90) --------------------------------------------------------  // acclient.c:853828
void __cdecl _E1345_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_10;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00740FD0) --------------------------------------------------------  // acclient.c:853853
void __cdecl _E1348_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_10;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00741010) --------------------------------------------------------  // acclient.c:853878
void __cdecl _E1351_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_10;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00741050) --------------------------------------------------------  // acclient.c:853903
void __cdecl _E1354_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_10;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00741090) --------------------------------------------------------  // acclient.c:853928
void __cdecl _E1357_2()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_10;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (007410D0) --------------------------------------------------------  // acclient.c:853953
void __cdecl _E1360_2()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_17;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (00741110) --------------------------------------------------------  // acclient.c:853978
void __cdecl _E1363_2()
{
  char *v0; // esi@1

  v0 = &waveform_None_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741140) --------------------------------------------------------  // acclient.c:853991
void __cdecl _E1366_2()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741170) --------------------------------------------------------  // acclient.c:854004
void __cdecl _E1369_2()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007411A0) --------------------------------------------------------  // acclient.c:854017
void __cdecl _E1372_2()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007411D0) --------------------------------------------------------  // acclient.c:854030
void __cdecl _E1375_2()
{
  char *v0; // esi@1

  v0 = &waveform_Square_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741200) --------------------------------------------------------  // acclient.c:854043
void __cdecl _E1378_2()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741230) --------------------------------------------------------  // acclient.c:854056
void __cdecl _E1381_1()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741260) --------------------------------------------------------  // acclient.c:854069
void __cdecl _E1384_1()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741290) --------------------------------------------------------  // acclient.c:854082
void __cdecl _E1387_1()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007412C0) --------------------------------------------------------  // acclient.c:854095
void __cdecl _E101_63()
{
  char *v0; // esi@1

  v0 = &PHeader_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007412F0) --------------------------------------------------------  // acclient.c:854108
void __cdecl _E104_33()
{
  char *v0; // esi@1

  v0 = &VertexArray_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741320) --------------------------------------------------------  // acclient.c:854121
void __cdecl _E107_65()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741350) --------------------------------------------------------  // acclient.c:854134
void __cdecl sub_741350()
{
  char *v0; // esi@1

  v0 = &VertexType_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741380) --------------------------------------------------------  // acclient.c:854147
void __cdecl _E113_44()
{
  char *v0; // esi@1

  v0 = &VertexData_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007413B0) --------------------------------------------------------  // acclient.c:854160
void __cdecl _E116_36()
{
  char *v0; // esi@1

  v0 = &Vertex_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007413E0) --------------------------------------------------------  // acclient.c:854173
void __cdecl _E119_61()
{
  char *v0; // esi@1

  v0 = &Index_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741410) --------------------------------------------------------  // acclient.c:854186
void __cdecl _E122_48()
{
  char *v0; // esi@1

  v0 = &Origin_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741440) --------------------------------------------------------  // acclient.c:854199
void __cdecl _E125_23()
{
  char *v0; // esi@1

  v0 = &Normal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741470) --------------------------------------------------------  // acclient.c:854212
void __cdecl _E128_24()
{
  char *v0; // esi@1

  v0 = &Diffuse_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007414A0) --------------------------------------------------------  // acclient.c:854225
void __cdecl _E131_20()
{
  char *v0; // esi@1

  v0 = &Specular_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007414D0) --------------------------------------------------------  // acclient.c:854238
void __cdecl _E134_19()
{
  char *v0; // esi@1

  v0 = &UVS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741500) --------------------------------------------------------  // acclient.c:854251
void __cdecl _E137_19()
{
  char *v0; // esi@1

  v0 = &VectorS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741530) --------------------------------------------------------  // acclient.c:854264
void __cdecl _E140_14()
{
  char *v0; // esi@1

  v0 = &VectorT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741560) --------------------------------------------------------  // acclient.c:854277
void __cdecl _E143_15()
{
  char *v0; // esi@1

  v0 = &VectorSxT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741590) --------------------------------------------------------  // acclient.c:854290
void __cdecl _E146_14()
{
  char *v0; // esi@1

  v0 = &Weights_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007415C0) --------------------------------------------------------  // acclient.c:854303
void __cdecl _E149_14()
{
  char *v0; // esi@1

  v0 = &Importance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007415F0) --------------------------------------------------------  // acclient.c:854316
void __cdecl _E152_13()
{
  char *v0; // esi@1

  v0 = &PhysMtl_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741620) --------------------------------------------------------  // acclient.c:854329
void __cdecl _E155_11()
{
  char *v0; // esi@1

  v0 = &Material_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741650) --------------------------------------------------------  // acclient.c:854342
void __cdecl _E158_14()
{
  char *v0; // esi@1

  v0 = &ID_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741680) --------------------------------------------------------  // acclient.c:854355
void __cdecl _E161_11()
{
  char *v0; // esi@1

  v0 = &FileName_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007416B0) --------------------------------------------------------  // acclient.c:854368
void __cdecl _E164_14()
{
  char *v0; // esi@1

  v0 = &Polygon_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007416E0) --------------------------------------------------------  // acclient.c:854381
void __cdecl _E167_10()
{
  char *v0; // esi@1

  v0 = &ID_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741710) --------------------------------------------------------  // acclient.c:854394
void __cdecl _E170_9()
{
  char *v0; // esi@1

  v0 = &Indices_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741740) --------------------------------------------------------  // acclient.c:854407
void __cdecl _E173_8()
{
  char *v0; // esi@1

  v0 = &MaterialID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741770) --------------------------------------------------------  // acclient.c:854420
void __cdecl _E176_9()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007417A0) --------------------------------------------------------  // acclient.c:854433
void __cdecl _E179_8()
{
  char *v0; // esi@1

  v0 = &Markings_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007417D0) --------------------------------------------------------  // acclient.c:854446
void __cdecl _E182_8()
{
  char *v0; // esi@1

  v0 = &Material_17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_17.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741800) --------------------------------------------------------  // acclient.c:854459
void __cdecl _E185_5()
{
  char *v0; // esi@1

  v0 = &Index_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741830) --------------------------------------------------------  // acclient.c:854472
void __cdecl _E188_6()
{
  char *v0; // esi@1

  v0 = &Filename_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741860) --------------------------------------------------------  // acclient.c:854485
void __cdecl _E191_5()
{
  char *v0; // esi@1

  v0 = &Surface_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741890) --------------------------------------------------------  // acclient.c:854498
void __cdecl _E194_12()
{
  char *v0; // esi@1

  v0 = &CellPoly_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007418C0) --------------------------------------------------------  // acclient.c:854511
void __cdecl _E197_3()
{
  char *v0; // esi@1

  v0 = &Sphere_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007418F0) --------------------------------------------------------  // acclient.c:854524
void __cdecl _E200_8()
{
  char *v0; // esi@1

  v0 = &Side_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741920) --------------------------------------------------------  // acclient.c:854537
void __cdecl _E203_7()
{
  char *v0; // esi@1

  v0 = &Positive_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741950) --------------------------------------------------------  // acclient.c:854550
void __cdecl _E206_10()
{
  char *v0; // esi@1

  v0 = &Negative_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741980) --------------------------------------------------------  // acclient.c:854563
void __cdecl _E209_5()
{
  char *v0; // esi@1

  v0 = &Polygon_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007419B0) --------------------------------------------------------  // acclient.c:854576
void __cdecl _E212_8()
{
  char *v0; // esi@1

  v0 = &OtherCell_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007419E0) --------------------------------------------------------  // acclient.c:854589
void __cdecl _E215_4()
{
  char *v0; // esi@1

  v0 = &CellPortal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741A10) --------------------------------------------------------  // acclient.c:854602
void __cdecl _E218_5()
{
  char *v0; // esi@1

  v0 = &Portal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741A40) --------------------------------------------------------  // acclient.c:854615
void __cdecl _E221_5()
{
  char *v0; // esi@1

  v0 = &OtherCell_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741A70) --------------------------------------------------------  // acclient.c:854628
void __cdecl _E224_5()
{
  char *v0; // esi@1

  v0 = &OtherPortal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741AA0) --------------------------------------------------------  // acclient.c:854641
void __cdecl _E227_5()
{
  char *v0; // esi@1

  v0 = &ExactMatch_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741AD0) --------------------------------------------------------  // acclient.c:854654
void __cdecl _E230_5()
{
  char *v0; // esi@1

  v0 = &StabList_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741B00) --------------------------------------------------------  // acclient.c:854667
void __cdecl _E233_4()
{
  char *v0; // esi@1

  v0 = &Period_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741B30) --------------------------------------------------------  // acclient.c:854680
void __cdecl _E236_4()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741B60) --------------------------------------------------------  // acclient.c:854693
void __cdecl _E239_5()
{
  char *v0; // esi@1

  v0 = &Transform_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741B90) --------------------------------------------------------  // acclient.c:854706
void __cdecl _E242_5()
{
  char *v0; // esi@1

  v0 = &Scale_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741BC0) --------------------------------------------------------  // acclient.c:854719
void __cdecl _E245_4()
{
  char *v0; // esi@1

  v0 = &Weight_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741BF0) --------------------------------------------------------  // acclient.c:854732
void __cdecl _E248_4()
{
  char *v0; // esi@1

  v0 = &Offset_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741C20) --------------------------------------------------------  // acclient.c:854745
void __cdecl _E251_4()
{
  char *v0; // esi@1

  v0 = &Quaternion_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741C50) --------------------------------------------------------  // acclient.c:854758
void __cdecl _E254_5()
{
  char *v0; // esi@1

  v0 = &Rotation_7.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_7.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741C80) --------------------------------------------------------  // acclient.c:854771
void __cdecl _E257_3()
{
  char *v0; // esi@1

  v0 = &STime_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741CB0) --------------------------------------------------------  // acclient.c:854784
void __cdecl _E260_4()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741CE0) --------------------------------------------------------  // acclient.c:854797
void __cdecl _E263_2()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741D10) --------------------------------------------------------  // acclient.c:854810
void __cdecl _E266_2()
{
  char *v0; // esi@1

  v0 = &LowPt_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741D40) --------------------------------------------------------  // acclient.c:854823
void __cdecl _E269_2()
{
  char *v0; // esi@1

  v0 = &Radius_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741D70) --------------------------------------------------------  // acclient.c:854836
void __cdecl _E272_1()
{
  char *v0; // esi@1

  v0 = &Height_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741DA0) --------------------------------------------------------  // acclient.c:854849
void __cdecl _E275_1()
{
  char *v0; // esi@1

  v0 = &Texture2D_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741DD0) --------------------------------------------------------  // acclient.c:854862
void __cdecl _E278_1()
{
  char *v0; // esi@1

  v0 = &Texture3D_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741E00) --------------------------------------------------------  // acclient.c:854875
void __cdecl _E281_2()
{
  char *v0; // esi@1

  v0 = &TextureCube_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741E30) --------------------------------------------------------  // acclient.c:854888
void __cdecl _E284_1()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741E60) --------------------------------------------------------  // acclient.c:854901
void __cdecl _E287_2()
{
  char *v0; // esi@1

  v0 = &MovieFileName_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741E90) --------------------------------------------------------  // acclient.c:854914
void __cdecl _E290_2()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741EC0) --------------------------------------------------------  // acclient.c:854927
void __cdecl _E293_1()
{
  char *v0; // esi@1

  v0 = &Levels_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741EF0) --------------------------------------------------------  // acclient.c:854940
void __cdecl _E296_2()
{
  char *v0; // esi@1

  v0 = &NodeName_39.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_39.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741F20) --------------------------------------------------------  // acclient.c:854953
void __cdecl _E299_0()
{
  char *v0; // esi@1

  v0 = &Material_18.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_18.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741F50) --------------------------------------------------------  // acclient.c:854966
void __cdecl _E302_1()
{
  char *v0; // esi@1

  v0 = &MaterialType_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741F80) --------------------------------------------------------  // acclient.c:854979
void __cdecl _E305_0()
{
  char *v0; // esi@1

  v0 = &Modifier_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741FB0) --------------------------------------------------------  // acclient.c:854992
void __cdecl _E308_1()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00741FE0) --------------------------------------------------------  // acclient.c:855005
void __cdecl _E311_0()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742010) --------------------------------------------------------  // acclient.c:855018
void __cdecl _E314_1()
{
  char *v0; // esi@1

  v0 = &NodeName_40.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_40.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742040) --------------------------------------------------------  // acclient.c:855031
void __cdecl _E317_0()
{
  char *v0; // esi@1

  v0 = &SortMode_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742070) --------------------------------------------------------  // acclient.c:855044
void __cdecl _E320_1()
{
  char *v0; // esi@1

  v0 = &SortMode_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007420A0) --------------------------------------------------------  // acclient.c:855057
void __cdecl _E323_0()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007420D0) --------------------------------------------------------  // acclient.c:855070
void __cdecl _E326_1()
{
  char *v0; // esi@1

  v0 = &NodeName_41.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_41.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742100) --------------------------------------------------------  // acclient.c:855083
void __cdecl _E329_0()
{
  char *v0; // esi@1

  v0 = &NodeName_42.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_42.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742130) --------------------------------------------------------  // acclient.c:855096
void __cdecl _E332_1()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742160) --------------------------------------------------------  // acclient.c:855109
void __cdecl _E335_0()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742190) --------------------------------------------------------  // acclient.c:855122
void __cdecl _E338_0()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007421C0) --------------------------------------------------------  // acclient.c:855135
void __cdecl _E341_0()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007421F0) --------------------------------------------------------  // acclient.c:855148
void __cdecl _E344_0()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742220) --------------------------------------------------------  // acclient.c:855161
void __cdecl _E347_0()
{
  char *v0; // esi@1

  v0 = &NodeName_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742250) --------------------------------------------------------  // acclient.c:855174
void __cdecl _E350_0()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742280) --------------------------------------------------------  // acclient.c:855187
void __cdecl _E353_0()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007422B0) --------------------------------------------------------  // acclient.c:855200
void __cdecl _E356_0()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007422E0) --------------------------------------------------------  // acclient.c:855213
void __cdecl _E359_0()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742310) --------------------------------------------------------  // acclient.c:855226
void __cdecl _E362_0()
{
  char *v0; // esi@1

  v0 = &TrueFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742340) --------------------------------------------------------  // acclient.c:855239
void __cdecl _E365_0()
{
  char *v0; // esi@1

  v0 = &FalseFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742370) --------------------------------------------------------  // acclient.c:855252
void __cdecl _E368_0()
{
  char *v0; // esi@1

  v0 = &RenderPass_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007423A0) --------------------------------------------------------  // acclient.c:855265
void __cdecl _E371_0()
{
  char *v0; // esi@1

  v0 = &Blend_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007423D0) --------------------------------------------------------  // acclient.c:855278
void __cdecl _E374_0()
{
  char *v0; // esi@1

  v0 = &DepthTest_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742400) --------------------------------------------------------  // acclient.c:855291
void __cdecl _E377_0()
{
  char *v0; // esi@1

  v0 = &DepthWrite_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742430) --------------------------------------------------------  // acclient.c:855304
void __cdecl _E380_0()
{
  char *v0; // esi@1

  v0 = &CullMode_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742460) --------------------------------------------------------  // acclient.c:855317
void __cdecl _E383_0()
{
  char *v0; // esi@1

  v0 = &DepthFog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742490) --------------------------------------------------------  // acclient.c:855330
void __cdecl _E386_0()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007424C0) --------------------------------------------------------  // acclient.c:855343
void __cdecl _E389_0()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007424F0) --------------------------------------------------------  // acclient.c:855356
void __cdecl _E392_0()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742520) --------------------------------------------------------  // acclient.c:855369
void __cdecl _E395_0()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742550) --------------------------------------------------------  // acclient.c:855382
void __cdecl _E398_0()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742580) --------------------------------------------------------  // acclient.c:855395
void __cdecl _E401_0()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007425B0) --------------------------------------------------------  // acclient.c:855408
void __cdecl _E404_0()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007425E0) --------------------------------------------------------  // acclient.c:855421
void __cdecl _E407_0()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742610) --------------------------------------------------------  // acclient.c:855434
void __cdecl _E410_0()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742640) --------------------------------------------------------  // acclient.c:855447
void __cdecl _E413_0()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742670) --------------------------------------------------------  // acclient.c:855460
void __cdecl _E416_0()
{
  char *v0; // esi@1

  v0 = &Ambient_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007426A0) --------------------------------------------------------  // acclient.c:855473
void __cdecl _E419_0()
{
  char *v0; // esi@1

  v0 = &Diffuse_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007426D0) --------------------------------------------------------  // acclient.c:855486
void __cdecl _E422_0()
{
  char *v0; // esi@1

  v0 = &Specular_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742700) --------------------------------------------------------  // acclient.c:855499
void __cdecl _E425_0()
{
  char *v0; // esi@1

  v0 = &SpecularPower_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742730) --------------------------------------------------------  // acclient.c:855512
void __cdecl _E428_0()
{
  char *v0; // esi@1

  v0 = &Dye_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742760) --------------------------------------------------------  // acclient.c:855525
void __cdecl _E431_0()
{
  char *v0; // esi@1

  v0 = &Emissive_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742790) --------------------------------------------------------  // acclient.c:855538
void __cdecl _E434_0()
{
  char *v0; // esi@1

  v0 = &VertexFormat_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007427C0) --------------------------------------------------------  // acclient.c:855551
void __cdecl _E437_0()
{
  char *v0; // esi@1

  v0 = &VertexShader_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007427F0) --------------------------------------------------------  // acclient.c:855564
void __cdecl _E440_0()
{
  char *v0; // esi@1

  v0 = &PixelShader_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742820) --------------------------------------------------------  // acclient.c:855577
void __cdecl _E443_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742850) --------------------------------------------------------  // acclient.c:855590
void __cdecl _E446_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742880) --------------------------------------------------------  // acclient.c:855603
void __cdecl _E449_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007428B0) --------------------------------------------------------  // acclient.c:855616
void __cdecl _E452_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007428E0) --------------------------------------------------------  // acclient.c:855629
void __cdecl _E455_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742910) --------------------------------------------------------  // acclient.c:855642
void __cdecl _E458_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742940) --------------------------------------------------------  // acclient.c:855655
void __cdecl _E461_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742970) --------------------------------------------------------  // acclient.c:855668
void __cdecl _E464_0()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007429A0) --------------------------------------------------------  // acclient.c:855681
void __cdecl _E467_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007429D0) --------------------------------------------------------  // acclient.c:855694
void __cdecl _E470_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742A00) --------------------------------------------------------  // acclient.c:855707
void __cdecl _E473_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742A30) --------------------------------------------------------  // acclient.c:855720
void __cdecl _E476_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742A60) --------------------------------------------------------  // acclient.c:855733
void __cdecl _E479_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742A90) --------------------------------------------------------  // acclient.c:855746
void __cdecl _E482_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742AC0) --------------------------------------------------------  // acclient.c:855759
void __cdecl _E485_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742AF0) --------------------------------------------------------  // acclient.c:855772
void __cdecl _E488_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742B20) --------------------------------------------------------  // acclient.c:855785
void __cdecl _E491_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742B50) --------------------------------------------------------  // acclient.c:855798
void __cdecl _E494_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742B80) --------------------------------------------------------  // acclient.c:855811
void __cdecl _E497_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742BB0) --------------------------------------------------------  // acclient.c:855824
void __cdecl _E500_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742BE0) --------------------------------------------------------  // acclient.c:855837
void __cdecl _E503_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742C10) --------------------------------------------------------  // acclient.c:855850
void __cdecl _E506_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742C40) --------------------------------------------------------  // acclient.c:855863
void __cdecl _E509_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742C70) --------------------------------------------------------  // acclient.c:855876
void __cdecl _E512_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742CA0) --------------------------------------------------------  // acclient.c:855889
void __cdecl _E515_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742CD0) --------------------------------------------------------  // acclient.c:855902
void __cdecl _E518_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742D00) --------------------------------------------------------  // acclient.c:855915
void __cdecl _E521_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742D30) --------------------------------------------------------  // acclient.c:855928
void __cdecl _E524_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742D60) --------------------------------------------------------  // acclient.c:855941
void __cdecl _E527_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742D90) --------------------------------------------------------  // acclient.c:855954
void __cdecl _E530_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742DC0) --------------------------------------------------------  // acclient.c:855967
void __cdecl _E533_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742DF0) --------------------------------------------------------  // acclient.c:855980
void __cdecl _E536_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742E20) --------------------------------------------------------  // acclient.c:855993
void __cdecl _E539_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742E50) --------------------------------------------------------  // acclient.c:856006
void __cdecl _E542_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742E80) --------------------------------------------------------  // acclient.c:856019
void __cdecl _E545_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742EB0) --------------------------------------------------------  // acclient.c:856032
void __cdecl _E548_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742EE0) --------------------------------------------------------  // acclient.c:856045
void __cdecl _E551_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742F10) --------------------------------------------------------  // acclient.c:856058
void __cdecl _E554_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742F40) --------------------------------------------------------  // acclient.c:856071
void __cdecl _E557_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742F70) --------------------------------------------------------  // acclient.c:856084
void __cdecl _E560_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742FA0) --------------------------------------------------------  // acclient.c:856097
void __cdecl _E563_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00742FD0) --------------------------------------------------------  // acclient.c:856110
void __cdecl _E566_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743000) --------------------------------------------------------  // acclient.c:856123
void __cdecl _E569_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743030) --------------------------------------------------------  // acclient.c:856136
void __cdecl _E572_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743060) --------------------------------------------------------  // acclient.c:856149
void __cdecl _E575_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743090) --------------------------------------------------------  // acclient.c:856162
void __cdecl _E578_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007430C0) --------------------------------------------------------  // acclient.c:856175
void __cdecl _E581_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007430F0) --------------------------------------------------------  // acclient.c:856188
void __cdecl _E584_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743120) --------------------------------------------------------  // acclient.c:856201
void __cdecl _E587_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743150) --------------------------------------------------------  // acclient.c:856214
void __cdecl _E590_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743180) --------------------------------------------------------  // acclient.c:856227
void __cdecl _E593_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007431B0) --------------------------------------------------------  // acclient.c:856240
void __cdecl _E596_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007431E0) --------------------------------------------------------  // acclient.c:856253
void __cdecl _E599_0()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743210) --------------------------------------------------------  // acclient.c:856266
void __cdecl _E602_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743240) --------------------------------------------------------  // acclient.c:856279
void __cdecl _E605_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743270) --------------------------------------------------------  // acclient.c:856292
void __cdecl _E608_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007432A0) --------------------------------------------------------  // acclient.c:856305
void __cdecl _E611_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007432D0) --------------------------------------------------------  // acclient.c:856318
void __cdecl _E614_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743300) --------------------------------------------------------  // acclient.c:856331
void __cdecl _E617_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743330) --------------------------------------------------------  // acclient.c:856344
void __cdecl _E620_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743360) --------------------------------------------------------  // acclient.c:856357
void __cdecl _E623_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743390) --------------------------------------------------------  // acclient.c:856370
void __cdecl _E626_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007433C0) --------------------------------------------------------  // acclient.c:856383
void __cdecl _E629_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007433F0) --------------------------------------------------------  // acclient.c:856396
void __cdecl _E632_0()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743420) --------------------------------------------------------  // acclient.c:856409
void __cdecl _E635_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743450) --------------------------------------------------------  // acclient.c:856422
void __cdecl _E638_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743480) --------------------------------------------------------  // acclient.c:856435
void __cdecl _E641_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007434B0) --------------------------------------------------------  // acclient.c:856448
void __cdecl _E644_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007434E0) --------------------------------------------------------  // acclient.c:856461
void __cdecl _E647_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743510) --------------------------------------------------------  // acclient.c:856474
void __cdecl _E650_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743540) --------------------------------------------------------  // acclient.c:856487
void __cdecl _E653_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743570) --------------------------------------------------------  // acclient.c:856500
void __cdecl _E656_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007435A0) --------------------------------------------------------  // acclient.c:856513
void __cdecl _E659_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007435D0) --------------------------------------------------------  // acclient.c:856526
void __cdecl _E662_0()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743600) --------------------------------------------------------  // acclient.c:856539
void __cdecl _E665_0()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743630) --------------------------------------------------------  // acclient.c:856552
void __cdecl _E668_0()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743660) --------------------------------------------------------  // acclient.c:856565
void __cdecl _E671_0()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743690) --------------------------------------------------------  // acclient.c:856578
void __cdecl _E674_0()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007436C0) --------------------------------------------------------  // acclient.c:856591
void __cdecl _E677_0()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007436F0) --------------------------------------------------------  // acclient.c:856604
void __cdecl _E680_0()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743720) --------------------------------------------------------  // acclient.c:856617
void __cdecl _E683_0()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743750) --------------------------------------------------------  // acclient.c:856630
void __cdecl _E686_0()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743780) --------------------------------------------------------  // acclient.c:856643
void __cdecl _E689_0()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007437B0) --------------------------------------------------------  // acclient.c:856656
void __cdecl _E692_0()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007437E0) --------------------------------------------------------  // acclient.c:856669
void __cdecl _E695_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743810) --------------------------------------------------------  // acclient.c:856682
void __cdecl _E698_0()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743840) --------------------------------------------------------  // acclient.c:856695
void __cdecl _E701_0()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743870) --------------------------------------------------------  // acclient.c:856708
void __cdecl _E704_0()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007438A0) --------------------------------------------------------  // acclient.c:856721
void __cdecl _E707_0()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007438D0) --------------------------------------------------------  // acclient.c:856734
void __cdecl _E710_0()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743900) --------------------------------------------------------  // acclient.c:856747
void __cdecl _E713_0()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743930) --------------------------------------------------------  // acclient.c:856760
void __cdecl _E716_0()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743960) --------------------------------------------------------  // acclient.c:856773
void __cdecl _E719_0()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743990) --------------------------------------------------------  // acclient.c:856786
void __cdecl _E722_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007439C0) --------------------------------------------------------  // acclient.c:856799
void __cdecl _E725_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007439F0) --------------------------------------------------------  // acclient.c:856812
void __cdecl _E728_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743A20) --------------------------------------------------------  // acclient.c:856825
void __cdecl _E731_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743A50) --------------------------------------------------------  // acclient.c:856838
void __cdecl _E734_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743A80) --------------------------------------------------------  // acclient.c:856851
void __cdecl _E737_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743AB0) --------------------------------------------------------  // acclient.c:856864
void __cdecl _E740_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743AE0) --------------------------------------------------------  // acclient.c:856877
void __cdecl _E743_0()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743B10) --------------------------------------------------------  // acclient.c:856890
void __cdecl _E746_0()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743B40) --------------------------------------------------------  // acclient.c:856903
void __cdecl _E749_0()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743B70) --------------------------------------------------------  // acclient.c:856916
void __cdecl _E752_0()
{
  char *v0; // esi@1

  v0 = &NodeName_44.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_44.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743BA0) --------------------------------------------------------  // acclient.c:856929
void __cdecl _E755_0()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743BD0) --------------------------------------------------------  // acclient.c:856942
void __cdecl _E758_0()
{
  char *v0; // esi@1

  v0 = &SamplerName_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743C00) --------------------------------------------------------  // acclient.c:856955
void __cdecl _E761_0()
{
  char *v0; // esi@1

  v0 = &Texture_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743C30) --------------------------------------------------------  // acclient.c:856968
void __cdecl _E764_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743C60) --------------------------------------------------------  // acclient.c:856981
void __cdecl _E767_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743C90) --------------------------------------------------------  // acclient.c:856994
void __cdecl _E770_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743CC0) --------------------------------------------------------  // acclient.c:857007
void __cdecl _E773_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743CF0) --------------------------------------------------------  // acclient.c:857020
void __cdecl _E776_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743D20) --------------------------------------------------------  // acclient.c:857033
void __cdecl _E779_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743D50) --------------------------------------------------------  // acclient.c:857046
void __cdecl _E782_0()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743D80) --------------------------------------------------------  // acclient.c:857059
void __cdecl _E785_0()
{
  char *v0; // esi@1

  v0 = &AddressMode_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743DB0) --------------------------------------------------------  // acclient.c:857072
void __cdecl _E788_0()
{
  char *v0; // esi@1

  v0 = &TexFilter_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743DE0) --------------------------------------------------------  // acclient.c:857085
void __cdecl _E791_0()
{
  char *v0; // esi@1

  v0 = &ColorOp_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743E10) --------------------------------------------------------  // acclient.c:857098
void __cdecl _E794_0()
{
  char *v0; // esi@1

  v0 = &ColorArg1_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743E40) --------------------------------------------------------  // acclient.c:857111
void __cdecl _E797_0()
{
  char *v0; // esi@1

  v0 = &ColorArg2_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743E70) --------------------------------------------------------  // acclient.c:857124
void __cdecl _E800_0()
{
  char *v0; // esi@1

  v0 = &AlphaOp_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743EA0) --------------------------------------------------------  // acclient.c:857137
void __cdecl _E803_0()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743ED0) --------------------------------------------------------  // acclient.c:857150
void __cdecl _E806_0()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743F00) --------------------------------------------------------  // acclient.c:857163
void __cdecl _E809_0()
{
  char *v0; // esi@1

  v0 = &TexCoord_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743F30) --------------------------------------------------------  // acclient.c:857176
void __cdecl _E812_0()
{
  char *v0; // esi@1

  v0 = &UseProjection_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743F60) --------------------------------------------------------  // acclient.c:857189
void __cdecl _E815_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743F90) --------------------------------------------------------  // acclient.c:857202
void __cdecl _E818_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743FC0) --------------------------------------------------------  // acclient.c:857215
void __cdecl _E821_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00743FF0) --------------------------------------------------------  // acclient.c:857228
void __cdecl _E824_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744020) --------------------------------------------------------  // acclient.c:857241
void __cdecl _E827_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744050) --------------------------------------------------------  // acclient.c:857254
void __cdecl _E830_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744080) --------------------------------------------------------  // acclient.c:857267
void __cdecl _E833_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007440B0) --------------------------------------------------------  // acclient.c:857280
void __cdecl _E836_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007440E0) --------------------------------------------------------  // acclient.c:857293
void __cdecl _E839_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744110) --------------------------------------------------------  // acclient.c:857306
void __cdecl _E842_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744140) --------------------------------------------------------  // acclient.c:857319
void __cdecl _E845_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744170) --------------------------------------------------------  // acclient.c:857332
void __cdecl _E848_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007441A0) --------------------------------------------------------  // acclient.c:857345
void __cdecl _E851_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007441D0) --------------------------------------------------------  // acclient.c:857358
void __cdecl _E854_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744200) --------------------------------------------------------  // acclient.c:857371
void __cdecl _E857_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744230) --------------------------------------------------------  // acclient.c:857384
void __cdecl _E860_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744260) --------------------------------------------------------  // acclient.c:857397
void __cdecl _E863_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744290) --------------------------------------------------------  // acclient.c:857410
void __cdecl _E866_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007442C0) --------------------------------------------------------  // acclient.c:857423
void __cdecl _E869_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007442F0) --------------------------------------------------------  // acclient.c:857436
void __cdecl _E872_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744320) --------------------------------------------------------  // acclient.c:857449
void __cdecl _E875_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744350) --------------------------------------------------------  // acclient.c:857462
void __cdecl _E878_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744380) --------------------------------------------------------  // acclient.c:857475
void __cdecl _E881_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007443B0) --------------------------------------------------------  // acclient.c:857488
void __cdecl _E884_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007443E0) --------------------------------------------------------  // acclient.c:857501
void __cdecl _E887_0()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744410) --------------------------------------------------------  // acclient.c:857514
void __cdecl _E890_0()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744440) --------------------------------------------------------  // acclient.c:857527
void __cdecl _E893_0()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744470) --------------------------------------------------------  // acclient.c:857540
void __cdecl _E896_0()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007444A0) --------------------------------------------------------  // acclient.c:857553
void __cdecl _E899_0()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007444D0) --------------------------------------------------------  // acclient.c:857566
void __cdecl _E902_0()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744500) --------------------------------------------------------  // acclient.c:857579
void __cdecl _E905_0()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744530) --------------------------------------------------------  // acclient.c:857592
void __cdecl _E908_0()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744560) --------------------------------------------------------  // acclient.c:857605
void __cdecl _E911_0()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744590) --------------------------------------------------------  // acclient.c:857618
void __cdecl _E914_0()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007445C0) --------------------------------------------------------  // acclient.c:857631
void __cdecl _E917_0()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007445F0) --------------------------------------------------------  // acclient.c:857644
void __cdecl _E920_0()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744620) --------------------------------------------------------  // acclient.c:857657
void __cdecl _E923_0()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744650) --------------------------------------------------------  // acclient.c:857670
void __cdecl _E926_0()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744680) --------------------------------------------------------  // acclient.c:857683
void __cdecl _E929_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007446B0) --------------------------------------------------------  // acclient.c:857696
void __cdecl _E932_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007446E0) --------------------------------------------------------  // acclient.c:857709
void __cdecl _E935_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744710) --------------------------------------------------------  // acclient.c:857722
void __cdecl _E938_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744740) --------------------------------------------------------  // acclient.c:857735
void __cdecl _E941_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744770) --------------------------------------------------------  // acclient.c:857748
void __cdecl _E944_0()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007447A0) --------------------------------------------------------  // acclient.c:857761
void __cdecl _E947_0()
{
  char *v0; // esi@1

  v0 = &NodeName_45.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_45.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007447D0) --------------------------------------------------------  // acclient.c:857774
void __cdecl _E950_0()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744800) --------------------------------------------------------  // acclient.c:857787
void __cdecl _E953_0()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744830) --------------------------------------------------------  // acclient.c:857800
void __cdecl _E956_0()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744860) --------------------------------------------------------  // acclient.c:857813
void __cdecl _E959_0()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744890) --------------------------------------------------------  // acclient.c:857826
void __cdecl _E962_0()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007448C0) --------------------------------------------------------  // acclient.c:857839
void __cdecl _E965_0()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007448F0) --------------------------------------------------------  // acclient.c:857852
void __cdecl _E968_0()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744920) --------------------------------------------------------  // acclient.c:857865
void __cdecl _E971_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744950) --------------------------------------------------------  // acclient.c:857878
void __cdecl _E974_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744980) --------------------------------------------------------  // acclient.c:857891
void __cdecl _E977_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007449B0) --------------------------------------------------------  // acclient.c:857904
void __cdecl _E980_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007449E0) --------------------------------------------------------  // acclient.c:857917
void __cdecl _E983_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744A10) --------------------------------------------------------  // acclient.c:857930
void __cdecl _E986_0()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744A40) --------------------------------------------------------  // acclient.c:857943
void __cdecl _E989_0()
{
  char *v0; // esi@1

  v0 = &NodeName_46.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_46.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744A70) --------------------------------------------------------  // acclient.c:857956
void __cdecl _E992_0()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744AA0) --------------------------------------------------------  // acclient.c:857969
void __cdecl _E995_0()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744AD0) --------------------------------------------------------  // acclient.c:857982
void __cdecl _E998_0()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744B00) --------------------------------------------------------  // acclient.c:857995
void __cdecl _E1001_0()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744B30) --------------------------------------------------------  // acclient.c:858008
void __cdecl _E1004_0()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744B60) --------------------------------------------------------  // acclient.c:858021
void __cdecl _E1007_0()
{
  char *v0; // esi@1

  v0 = &ScaleType_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744B90) --------------------------------------------------------  // acclient.c:858034
void __cdecl _E1010_0()
{
  char *v0; // esi@1

  v0 = &WorldSpace_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744BC0) --------------------------------------------------------  // acclient.c:858047
void __cdecl _E1013_0()
{
  char *v0; // esi@1

  v0 = &ForceDraw_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744BF0) --------------------------------------------------------  // acclient.c:858060
void __cdecl _E1016_0()
{
  char *v0; // esi@1

  v0 = &NumEmitters_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744C20) --------------------------------------------------------  // acclient.c:858073
void __cdecl _E1019_0()
{
  char *v0; // esi@1

  v0 = &Material_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744C50) --------------------------------------------------------  // acclient.c:858086
void __cdecl _E1022_0()
{
  char *v0; // esi@1

  v0 = &Version_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744C80) --------------------------------------------------------  // acclient.c:858099
void __cdecl _E1025_0()
{
  char *v0; // esi@1

  v0 = &MaxParticles_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744CB0) --------------------------------------------------------  // acclient.c:858112
void __cdecl _E1028_0()
{
  char *v0; // esi@1

  v0 = &NodeName_47.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_47.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744CE0) --------------------------------------------------------  // acclient.c:858125
void __cdecl _E1031_0()
{
  char *v0; // esi@1

  v0 = &Origin_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744D10) --------------------------------------------------------  // acclient.c:858138
void __cdecl _E1034_0()
{
  char *v0; // esi@1

  v0 = &Shape_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744D40) --------------------------------------------------------  // acclient.c:858151
void __cdecl _E1037_0()
{
  char *v0; // esi@1

  v0 = &Shape_Point_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744D70) --------------------------------------------------------  // acclient.c:858164
void __cdecl _E1040_0()
{
  char *v0; // esi@1

  v0 = &Shape_Line_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744DA0) --------------------------------------------------------  // acclient.c:858177
void __cdecl _E1043_0()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744DD0) --------------------------------------------------------  // acclient.c:858190
void __cdecl _E1046_0()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744E00) --------------------------------------------------------  // acclient.c:858203
void __cdecl _E1049_0()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744E30) --------------------------------------------------------  // acclient.c:858216
void __cdecl _E1052_0()
{
  char *v0; // esi@1

  v0 = &ParticleShape_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744E60) --------------------------------------------------------  // acclient.c:858229
void __cdecl _E1055_0()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744E90) --------------------------------------------------------  // acclient.c:858242
void __cdecl _E1058_0()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744EC0) --------------------------------------------------------  // acclient.c:858255
void __cdecl _E1061_0()
{
  char *v0; // esi@1

  v0 = &Streak_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744EF0) --------------------------------------------------------  // acclient.c:858268
void __cdecl _E1064_0()
{
  char *v0; // esi@1

  v0 = &Rotation_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744F20) --------------------------------------------------------  // acclient.c:858281
void __cdecl _E1067_0()
{
  char *v0; // esi@1

  v0 = &WorldRotation_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744F50) --------------------------------------------------------  // acclient.c:858294
void __cdecl _E1070_0()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744F80) --------------------------------------------------------  // acclient.c:858307
void __cdecl _E1073_0()
{
  char *v0; // esi@1

  v0 = &ParticleScale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744FB0) --------------------------------------------------------  // acclient.c:858320
void __cdecl _E1076_0()
{
  char *v0; // esi@1

  v0 = &Scale_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00744FE0) --------------------------------------------------------  // acclient.c:858333
void __cdecl _E1079_0()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745010) --------------------------------------------------------  // acclient.c:858346
void __cdecl _E1082_0()
{
  char *v0; // esi@1

  v0 = &BirthRate_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745040) --------------------------------------------------------  // acclient.c:858359
void __cdecl _E1085_0()
{
  char *v0; // esi@1

  v0 = &Lifespan_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745070) --------------------------------------------------------  // acclient.c:858372
void __cdecl _E1088_0()
{
  char *v0; // esi@1

  v0 = &Velocity_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007450A0) --------------------------------------------------------  // acclient.c:858385
void __cdecl _E1091_0()
{
  char *v0; // esi@1

  v0 = &Direction_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007450D0) --------------------------------------------------------  // acclient.c:858398
void __cdecl _E1094_0()
{
  char *v0; // esi@1

  v0 = &MinSpread_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745100) --------------------------------------------------------  // acclient.c:858411
void __cdecl _E1097_0()
{
  char *v0; // esi@1

  v0 = &MaxSpread_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745130) --------------------------------------------------------  // acclient.c:858424
void __cdecl _E1100_0()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745160) --------------------------------------------------------  // acclient.c:858437
void __cdecl _E1103_0()
{
  char *v0; // esi@1

  v0 = &BlastCount_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745190) --------------------------------------------------------  // acclient.c:858450
void __cdecl _E1106_0()
{
  char *v0; // esi@1

  v0 = &StartTime_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007451C0) --------------------------------------------------------  // acclient.c:858463
void __cdecl _E1109_0()
{
  char *v0; // esi@1

  v0 = &TimeLimit_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007451F0) --------------------------------------------------------  // acclient.c:858476
void __cdecl _E1112_0()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745220) --------------------------------------------------------  // acclient.c:858489
void __cdecl _E1115_0()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745250) --------------------------------------------------------  // acclient.c:858502
void __cdecl _E1118_0()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745280) --------------------------------------------------------  // acclient.c:858515
void __cdecl _E1121_0()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007452B0) --------------------------------------------------------  // acclient.c:858528
void __cdecl _E1124_0()
{
  char *v0; // esi@1

  v0 = &IsActive_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007452E0) --------------------------------------------------------  // acclient.c:858541
void __cdecl _E1127_0()
{
  char *v0; // esi@1

  v0 = &FadeIn_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745310) --------------------------------------------------------  // acclient.c:858554
void __cdecl _E1130_0()
{
  char *v0; // esi@1

  v0 = &FadeOut_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745340) --------------------------------------------------------  // acclient.c:858567
void __cdecl _E1133_0()
{
  char *v0; // esi@1

  v0 = &ConstrainX_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745370) --------------------------------------------------------  // acclient.c:858580
void __cdecl _E1136_0()
{
  char *v0; // esi@1

  v0 = &ConstrainY_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007453A0) --------------------------------------------------------  // acclient.c:858593
void __cdecl _E1139_0()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007453D0) --------------------------------------------------------  // acclient.c:858606
void __cdecl _E1142_0()
{
  char *v0; // esi@1

  v0 = &NodeName_48.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_48.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745400) --------------------------------------------------------  // acclient.c:858619
void __cdecl _E1145_0()
{
  char *v0; // esi@1

  v0 = &Time_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745430) --------------------------------------------------------  // acclient.c:858632
void __cdecl _E1148_0()
{
  char *v0; // esi@1

  v0 = &Flags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745460) --------------------------------------------------------  // acclient.c:858645
void __cdecl _E1151_0()
{
  char *v0; // esi@1

  v0 = &Flags_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745490) --------------------------------------------------------  // acclient.c:858658
void __cdecl _E1154_0()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007454C0) --------------------------------------------------------  // acclient.c:858671
void __cdecl _E1157_0()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007454F0) --------------------------------------------------------  // acclient.c:858684
void __cdecl _E1160_0()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745520) --------------------------------------------------------  // acclient.c:858697
void __cdecl _E1163_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745550) --------------------------------------------------------  // acclient.c:858710
void __cdecl _E1166_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745580) --------------------------------------------------------  // acclient.c:858723
void __cdecl _E1169_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007455B0) --------------------------------------------------------  // acclient.c:858736
void __cdecl _E1172_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007455E0) --------------------------------------------------------  // acclient.c:858749
void __cdecl _E1175_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745610) --------------------------------------------------------  // acclient.c:858762
void __cdecl _E1178_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745640) --------------------------------------------------------  // acclient.c:858775
void __cdecl _E1181_0()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745670) --------------------------------------------------------  // acclient.c:858788
void __cdecl _E1184_0()
{
  char *v0; // esi@1

  v0 = &Scale_13.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_13.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007456A0) --------------------------------------------------------  // acclient.c:858801
void __cdecl _E1187_0()
{
  char *v0; // esi@1

  v0 = &ScaleX_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007456D0) --------------------------------------------------------  // acclient.c:858814
void __cdecl _E1190_0()
{
  char *v0; // esi@1

  v0 = &ScaleY_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745700) --------------------------------------------------------  // acclient.c:858827
void __cdecl _E1193_0()
{
  char *v0; // esi@1

  v0 = &Color_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745730) --------------------------------------------------------  // acclient.c:858840
void __cdecl _E1196_0()
{
  char *v0; // esi@1

  v0 = &Mass_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745760) --------------------------------------------------------  // acclient.c:858853
void __cdecl _E1199_0()
{
  char *v0; // esi@1

  v0 = &PFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745790) --------------------------------------------------------  // acclient.c:858866
void __cdecl _E1202_0()
{
  char *v0; // esi@1

  v0 = &PFlags_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007457C0) --------------------------------------------------------  // acclient.c:858879
void __cdecl _E1205_0()
{
  char *v0; // esi@1

  v0 = &PCType_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007457F0) --------------------------------------------------------  // acclient.c:858892
void __cdecl _E1208_0()
{
  char *v0; // esi@1

  v0 = &PCType_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745820) --------------------------------------------------------  // acclient.c:858905
void __cdecl _E1211_0()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745850) --------------------------------------------------------  // acclient.c:858918
void __cdecl _E1214_0()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745880) --------------------------------------------------------  // acclient.c:858931
void __cdecl _E1217_0()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007458B0) --------------------------------------------------------  // acclient.c:858944
void __cdecl _E1220_0()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007458E0) --------------------------------------------------------  // acclient.c:858957
void __cdecl _E1223_0()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745910) --------------------------------------------------------  // acclient.c:858970
void __cdecl _E1226_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745940) --------------------------------------------------------  // acclient.c:858983
void __cdecl _E1229_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745970) --------------------------------------------------------  // acclient.c:858996
void __cdecl _E1232_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007459A0) --------------------------------------------------------  // acclient.c:859009
void __cdecl _E1235_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007459D0) --------------------------------------------------------  // acclient.c:859022
void __cdecl _E1238_0()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745A00) --------------------------------------------------------  // acclient.c:859035
void __cdecl _E1241_0()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745A30) --------------------------------------------------------  // acclient.c:859048
void __cdecl _E1244_0()
{
  char *v0; // esi@1

  v0 = &Position_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745A60) --------------------------------------------------------  // acclient.c:859061
void __cdecl _E1247_0()
{
  char *v0; // esi@1

  v0 = &PointList_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745A90) --------------------------------------------------------  // acclient.c:859074
void __cdecl _E1250_0()
{
  char *v0; // esi@1

  v0 = &Point_8.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_8.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745AC0) --------------------------------------------------------  // acclient.c:859087
void __cdecl _E1253_0()
{
  char *v0; // esi@1

  v0 = &DetailLevels_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745AF0) --------------------------------------------------------  // acclient.c:859100
void __cdecl _E1256_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745B20) --------------------------------------------------------  // acclient.c:859113
void __cdecl _E1259_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745B50) --------------------------------------------------------  // acclient.c:859126
void __cdecl _E1262_0()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745B80) --------------------------------------------------------  // acclient.c:859139
void __cdecl _E1265_0()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745BB0) --------------------------------------------------------  // acclient.c:859152
void __cdecl _E1268_0()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745BE0) --------------------------------------------------------  // acclient.c:859165
void __cdecl _E1271_0()
{
  char *v0; // esi@1

  v0 = &Point_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745C10) --------------------------------------------------------  // acclient.c:859178
void __cdecl _E1274_0()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745C40) --------------------------------------------------------  // acclient.c:859191
void __cdecl _E1277_0()
{
  char *v0; // esi@1

  v0 = &PointTexture_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745C70) --------------------------------------------------------  // acclient.c:859204
void __cdecl _E1280_1()
{
  char *v0; // esi@1

  v0 = &PointSize_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745CA0) --------------------------------------------------------  // acclient.c:859217
void __cdecl _E1283_0()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_3.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_3.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00745CD0) --------------------------------------------------------  // acclient.c:859230
void __cdecl _E1286_0()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &dword_83A870;
  v1 = 4;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

