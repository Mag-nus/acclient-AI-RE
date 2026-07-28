/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextureBasedFont
   Object     : ENGINE\render_base\TextureBasedFont.obj
   Functions  : 37
   Addresses  : 00696190 - 00785820 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00696190) --------------------------------------------------------  // acclient.c:685992
void __thiscall TextureBasedFont::BeginRenderingText(TextureBasedFont *this)
{
  g_FontVertices.m_num = 0;
  this->m_IsReadyToRender = 1;
  this->m_QueuedTextUsesScaling = 0;
}

//----- (00696200) --------------------------------------------------------  // acclient.c:686031
void __thiscall SmartArray<TextureBasedFontVertexType,1>::Reset(SmartArray<TextureBasedFontVertexType,1> *this)
{
  SmartArray<TextureBasedFontVertexType,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // esi@4
  const void *v5; // eax@5
  int v6; // edx@5
  int v7; // ebp@5
  void *v8; // edi@6

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
      v6 = v4;
      v7 = v4 + 1;
      do
      {
        v8 = &v1->m_data[v6];
        --v6;
        --v7;
        qmemcpy(v8, v5, 0x18u);
      }
      while ( v7 );
    }
  }
}

//----- (00696280) --------------------------------------------------------  // acclient.c:686073
bool __thiscall TextureBasedFont::SetupFontTexture(TextureBasedFont *this)
{
  TextureBasedFont *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  unsigned __int16 v4; // cx@2
  unsigned __int16 v5; // ax@2
  int v6; // esi@8
  int v7; // eax@8
  RenderTexture *v8; // ebp@8
  bool result; // al@10
  int v10; // eax@11
  int v11; // esi@12
  unsigned int v12; // ecx@14
  unsigned int v13; // eax@14
  unsigned int v14; // ebp@17
  unsigned int v15; // ecx@17
  unsigned int v16; // eax@18
  unsigned int v17; // eax@24
  const int v18; // ebp@24
  int v19; // esi@27
  int v20; // ebx@27
  int v21; // eax@30
  unsigned int v22; // ecx@30
  bool v23; // cf@30
  bool v24; // zf@30
  bool IsCompleteFont; // [sp+20h] [bp-32h]@24
  char CharacterWidth; // [sp+21h] [bp-31h]@27
  unsigned int CurrentY; // [sp+22h] [bp-30h]@24
  unsigned int c; // [sp+26h] [bp-2Ch]@24
  Font *pFont; // [sp+2Ah] [bp-28h]@1
  int v30; // [sp+2Eh] [bp-24h]@25
  RenderSurface *pSystemMemorySurface; // [sp+32h] [bp-20h]@12
  RenderTexture *pSystemMemoryTexture; // [sp+36h] [bp-1Ch]@8
  RGBAColor color; // [sp+42h] [bp-10h]@14

  v1 = this;
  v2 = FontMapper::GetFontByDataID(this->m_SourceFontDID);
  v3 = v2;
  pFont = (Font *)v2;
  if ( !v2 )
    return 0;
  v4 = *(_WORD *)(v2 + 100);
  v1->m_FirstUnicodeCharacter = v4;
  v5 = *(_WORD *)(v2 + 102);
  v1->m_LastUnicodeCharacter = v5;
  if ( v4 > 0x20u || v5 < 0x7Fu )
    return 0;
  if ( v4 < 0x20u )
    v1->m_FirstUnicodeCharacter = 32;
  if ( v1->m_LastUnicodeCharacter > 0x7Fu )
    v1->m_LastUnicodeCharacter = 127;
  v6 = v1->m_LastUnicodeCharacter - v1->m_FirstUnicodeCharacter + 1;
  operator delete[](v1->m_Characters.m_data);
  v1->m_Characters.m_data = 0;
  v1->m_Characters.m_num = 0;
  v1->m_Characters.m_num = v6;
  v1->m_Characters.m_data = (TextureBasedFontCharacter *)operator new[](24 * v6);
  v7 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
  v8 = (RenderTexture *)v7;
  pSystemMemoryTexture = (RenderTexture *)v7;
  if ( !v7 )
    return 0;
  if ( !(unsigned __int8)(*(int (__thiscall **)(int, signed int, signed int, signed int, signed int, signed int))(*(_DWORD *)v7 + 88))(
                           v7,
                           256,
                           256,
                           1,
                           21,
                           2) )
  {
    v8->vfptr->Release((Interface *)v8);
    return 0;
  }
  v10 = ((int (__thiscall *)(RenderTexture *, _DWORD, _DWORD))v8->vfptr[4].IUnknown_AddRef)(v8, 0, 0);
  if ( !v10 || (v11 = v10 - 48, pSystemMemorySurface = (RenderSurface *)(v10 - 48), v10 == 48) )
  {
    v8->vfptr->Release((Interface *)v8);
    return 0;
  }
  LODWORD(color.r) = 1065353216;
  LODWORD(color.g) = 1065353216;
  LODWORD(color.b) = 1065353216;
  LODWORD(color.a) = 0;
  SurfaceWindow::Fill((SurfaceWindow *)(v11 + 172), &color);
  v12 = v1->m_VerticalSpacing;
  v13 = *(_DWORD *)(v3 + 48);
  v1->m_MaxCharacterHeight = v13;
  if ( !v12 )
    v1->m_VerticalSpacing = v13;
  if ( !v1->m_HorizontalSpacing )
  {
    v14 = v1->m_FirstUnicodeCharacter;
    v15 = v1->m_LastUnicodeCharacter;
    v1->m_HorizontalSpacing = 0;
    if ( v14 <= v15 )
    {
      do
      {
        v16 = (unsigned __int8)Font::GetCharWidthA((Font *)v3, v14);
        if ( (unsigned __int8)v16 > v1->m_HorizontalSpacing )
          v1->m_HorizontalSpacing = v16;
        ++v14;
      }
      while ( v14 <= v1->m_LastUnicodeCharacter );
    }
    v8 = pSystemMemoryTexture;
  }
  if ( !SurfaceWindow::Lock((SurfaceWindow *)(v11 + 172), 0) || !Font::LockSurfaces((Font *)v3) )
  {
    v8->vfptr->Release((Interface *)v8);
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
    return 0;
  }
  v17 = v1->m_FirstUnicodeCharacter;
  v18 = 0;
  CurrentY = 0;
  IsCompleteFont = 1;
  c = v17;
  if ( v17 > v1->m_LastUnicodeCharacter )
    goto LABEL_34;
  v30 = 0;
  while ( 1 )
  {
    v19 = (int)&v1->m_Characters.m_data[v30];
    v20 = Font::GetCharDesc((Font *)v3, v17);
    CharacterWidth = *(_BYTE *)(v20 + 6);
    if ( v18 + (unsigned int)(unsigned __int8)CharacterWidth < 0x100 )
      goto LABEL_30;
    if ( v1->m_MaxCharacterHeight + CurrentY + 1 >= 0x100 )
      break;
    v18 = 0;
    CurrentY += v1->m_MaxCharacterHeight + 1;
LABEL_30:
    SurfaceWindow::DrawCharacter(&pSystemMemorySurface->window, v18, CurrentY, pFont, c, 0xFFFFFFFF, 0x100u, 0xFF000000);
    v21 = v1->m_MaxCharacterHeight + CurrentY - 1;
    *(float *)v19 = (double)(unsigned int)v18 * 0.00390625;
    *(float *)(v19 + 4) = (double)CurrentY * 0.00390625;
    *(float *)(v19 + 8) = ((double)((unsigned int)(unsigned __int8)CharacterWidth + v18 - 1) + 1.0) * 0.00390625;
    *(_BYTE *)(v19 + 16) = CharacterWidth;
    v18 += (unsigned __int8)CharacterWidth + 1;
    *(float *)(v19 + 12) = ((double)(unsigned int)v21 + 1.0) * 0.00390625;
    *(_BYTE *)(v19 + 18) = *(_BYTE *)(v20 + 8);
    *(_BYTE *)(v19 + 19) = *(_BYTE *)(v20 + 9);
    *(_BYTE *)(v19 + 17) = LOBYTE(v1->m_MaxCharacterHeight);
    *(_BYTE *)(v19 + 20) = *(_BYTE *)(v20 + 10);
    v22 = v1->m_LastUnicodeCharacter;
    v23 = c + 1 < v22;
    v24 = c + 1 == v22;
    ++v30;
    v3 = (unsigned int)pFont;
    ++c;
    if ( !v23 && !v24 )
      goto LABEL_33;
    LOWORD(v17) = c;
  }
  v3 = (unsigned int)pFont;
  IsCompleteFont = 0;
LABEL_33:
  v11 = (int)pSystemMemorySurface;
LABEL_34:
  SurfaceWindow::Unlock((SurfaceWindow *)(v11 + 172));
  Font::UnlockSurfaces((Font *)v3);
  (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 20))(v11);
  if ( (unsigned __int8)((int (__thiscall *)(RenderTexture *, RenderTexture *))v1->m_pTexture->vfptr[4].IUnknown_QueryInterface)(
                          v1->m_pTexture,
                          pSystemMemoryTexture) )
  {
    pSystemMemoryTexture->vfptr->Release((Interface *)pSystemMemoryTexture);
    result = IsCompleteFont != 0;
  }
  else
  {
    pSystemMemoryTexture->vfptr->Release((Interface *)pSystemMemoryTexture);
    result = 0;
  }
  return result;
}

//----- (00696610) --------------------------------------------------------  // acclient.c:686253
void __thiscall TextureBasedFont::EndRenderingText(TextureBasedFont *this)
{
  TextureBasedFont *v1; // esi@1

  v1 = this;
  if ( !this->m_pTexture->m_bIsLost || TextureBasedFont::SetupFontTexture(this) )
  {
    if ( g_FontVertices.m_num )
    {
      if ( v1->m_QueuedTextUsesScaling )
      {
        (*(*v1->m_pMaterial->layers.m_data)->m_Stages.m_data)->m_MinFilterMode = 2;
        (*(*v1->m_pMaterial->layers.m_data)->m_Stages.m_data)->m_MagFilterMode = 2;
      }
      else
      {
        (*(*v1->m_pMaterial->layers.m_data)->m_Stages.m_data)->m_MinFilterMode = 1;
        (*(*v1->m_pMaterial->layers.m_data)->m_Stages.m_data)->m_MagFilterMode = 1;
      }
      SceneTool::StoreMatrices();
      SceneTool::IdentityMatrices();
      RenderDeviceD3D::RenderDynamicPrimitivesUsingMaterial(
        PRIMTYPE_TRIANGLELIST,
        g_FontVertices.m_num / 3,
        g_FontVertices.m_data,
        0x142u,
        v1->m_pMaterial,
        v1->m_pMaterial,
        &stru_834788);
      g_FontVertices.m_num = 0;
      SceneTool::RestoreMatrices();
    }
    v1->m_IsReadyToRender = 0;
  }
}

//----- (006966E0) --------------------------------------------------------  // acclient.c:686290
unsigned int __thiscall TextureBasedFont::ComputeTextWidth(TextureBasedFont *this, const char *_pText, const unsigned int _Flags)
{
  TextureBasedFont *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // ecx@1
  unsigned int result; // eax@2
  unsigned int v7; // esi@3
  TextureBasedFontCharacter *v8; // eax@4
  unsigned __int16 v9; // bp@4
  int v10; // edi@7
  int v11; // edx@6
  unsigned int TextWidth; // [sp+8h] [bp-Ch]@3
  TextureBasedFont *v13; // [sp+Ch] [bp-8h]@1
  unsigned int NumCharacters; // [sp+10h] [bp-4h]@1

  v3 = this;
  v13 = this;
  v4 = strlen(_pText);
  v5 = v4;
  NumCharacters = v4;
  if ( v4 )
  {
    v7 = 0;
    TextWidth = 0;
    if ( v4 )
    {
      v8 = v3->m_Characters.m_data;
      v9 = v3->m_FirstUnicodeCharacter;
      do
      {
        if ( _Flags & 1 )
        {
          v11 = v13->m_HorizontalSpacing;
        }
        else
        {
          v10 = (int)&v8[(unsigned __int16)(_pText[v7] - v9)];
          v11 = *(_BYTE *)(v10 + 16) + *(_BYTE *)(v10 + 18) + *(_BYTE *)(v10 + 19);
          v5 = NumCharacters;
        }
        ++v7;
        TextWidth += v11;
      }
      while ( v7 < v5 );
    }
    result = TextWidth;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00696790) --------------------------------------------------------  // acclient.c:686345
char __thiscall SmartArray<TextureBasedFontVertexType,1>::grow(SmartArray<TextureBasedFontVertexType,1> *this, unsigned int i_nSize)
{
  SmartArray<TextureBasedFontVertexType,1> *v2; // ebx@1
  unsigned int v3; // esi@1
  void *v5; // eax@5
  TextureBasedFontVertexType *v6; // ebp@5
  int v7; // ecx@7
  int v8; // eax@8
  unsigned int v9; // edx@8
  const void *v10; // esi@9
  void *v11; // edi@9

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<TextureBasedFontVertexType,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](24 * i_nSize);
    v6 = (TextureBasedFontVertexType *)v5;
    if ( v5 )
    {
      vector_constructor_iterator(
        v5,
        0x18u,
        i_nSize,
        (void *(__thiscall *)(void *))DeleteLeafTransactInfo::DynamicCast_DeleteLeaf);
      if ( v2->m_data )
      {
        v7 = v2->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          v9 = v2->m_num;
          do
          {
            v10 = &v2->m_data[v8];
            v11 = &v6[v8];
            --v8;
            --v9;
            qmemcpy(v11, v10, 0x18u);
          }
          while ( v9 );
          v3 = i_nSize;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = v6;
      v2->m_sizeAndDeallocate = v3 | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00696850) --------------------------------------------------------  // acclient.c:686407
TextureBasedFont *__thiscall TextureBasedFont::vector_deleting_destructor(TextureBasedFont *this, unsigned int a2)
{
  TextureBasedFont *v2; // esi@1
  RenderTexture *v3; // ecx@1
  RenderMaterial *v4; // ecx@3

  v2 = this;
  v3 = this->m_pTexture;
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&TextureBasedFont::vftable;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v2->m_pTexture = 0;
  }
  v4 = v2->m_pMaterial;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v2->m_pMaterial = 0;
  }
  operator delete[](v2->m_Characters.m_data);
  v2->m_Characters.m_data = 0;
  v2->m_Characters.m_num = 0;
  v2->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 8009C4: using guessed type int (__thiscall *TextureBasedFont::vftable)(void *, char);

//----- (006968B0) --------------------------------------------------------  // acclient.c:686439
void __thiscall TextureBasedFont::RenderText(TextureBasedFont *this, const float _X, const float _Y, const float _Scale, const char *_pText, const unsigned int _Color32, const unsigned int _Flags)
{
  TextureBasedFont *v7; // esi@1
  unsigned int v8; // edi@1
  char v9; // al@2
  double v10; // st7@3
  double v11; // st7@8
  unsigned int v12; // esi@12
  unsigned int v13; // edi@12
  unsigned int v14; // eax@13
  bool v15; // zf@13
  int v16; // edi@15
  int v17; // ebp@15
  const unsigned int v18; // ecx@15
  int v19; // eax@16
  int v20; // edx@17
  int v21; // ebp@18
  double v22; // st7@20
  double v23; // st7@20
  int v24; // ST3C_4@20
  char *v25; // edi@20
  double v26; // st6@20
  int v27; // eax@20
  double v28; // st6@20
  double v29; // st5@20
  double v30; // st5@20
  double v31; // st5@20
  ProfilerDBObjStat *v32; // edi@20
  int v33; // edi@20
  char *v34; // edi@20
  ProfilerDBObjStat *v35; // edi@20
  ProfilerDBObjStat *v36; // edi@20
  int v37; // edi@20
  char *v38; // edi@20
  int v39; // edx@20
  int v40; // esi@20
  int v41; // eax@20
  int v42; // edi@20
  double v43; // st7@23
  double v44; // st7@23
  int v45; // ST3C_4@23
  char *v46; // edi@23
  double v47; // st6@23
  int v48; // eax@23
  double v49; // st6@23
  double v50; // st5@23
  double v51; // st5@23
  double v52; // st5@23
  ProfilerDBObjStat *v53; // edi@23
  int v54; // edi@23
  char *v55; // edi@23
  ProfilerDBObjStat *v56; // edi@23
  ProfilerDBObjStat *v57; // edi@23
  int v58; // edi@23
  char *v59; // edi@23
  int v60; // edx@23
  int v61; // esi@23
  int v62; // eax@23
  int v63; // edi@23
  double v64; // st7@26
  double v65; // st7@26
  int v66; // ST3C_4@26
  char *v67; // edi@26
  double v68; // st6@26
  int v69; // eax@26
  double v70; // st6@26
  double v71; // st5@26
  double v72; // st5@26
  double v73; // st5@26
  ProfilerDBObjStat *v74; // edi@26
  int v75; // edi@26
  char *v76; // edi@26
  ProfilerDBObjStat *v77; // edi@26
  ProfilerDBObjStat *v78; // edi@26
  int v79; // edi@26
  char *v80; // edi@26
  int v81; // edx@26
  int v82; // esi@26
  int v83; // eax@26
  int v84; // edi@26
  double v85; // st7@29
  double v86; // st7@29
  int v87; // ST3C_4@29
  char *v88; // edi@29
  double v89; // st6@29
  int v90; // eax@29
  double v91; // st6@29
  double v92; // st5@29
  double v93; // st5@29
  double v94; // st5@29
  ProfilerDBObjStat *v95; // edi@29
  int v96; // edi@29
  char *v97; // edi@29
  ProfilerDBObjStat *v98; // edi@29
  int v99; // edi@29
  ProfilerDBObjStat *v100; // edi@29
  int v101; // edi@29
  char *v102; // edi@29
  int v103; // ebp@29
  int v104; // edx@32
  int v105; // esi@32
  int v106; // eax@34
  int v107; // ebp@34
  double v108; // st7@37
  double v109; // st7@37
  double v110; // st6@37
  ProfilerDBObjStat *v111; // edx@37
  int v112; // edx@37
  int v113; // esi@37
  double v114; // st6@37
  double v115; // st5@37
  double v116; // st5@37
  double v117; // st5@37
  ProfilerDBObjStat *v118; // edx@37
  int v119; // edx@37
  char *v120; // edx@37
  ProfilerDBObjStat *v121; // edx@37
  ProfilerDBObjStat *v122; // edx@37
  int v123; // edx@37
  char *v124; // edx@37
  int BeforeVOffset; // [sp+Ch] [bp-30h]@17
  int BeforeVOffseta; // [sp+Ch] [bp-30h]@20
  int BeforeVOffsetb; // [sp+Ch] [bp-30h]@23
  int BeforeVOffsetc; // [sp+Ch] [bp-30h]@26
  int BeforeVOffsetd; // [sp+Ch] [bp-30h]@34
  unsigned int OffsetDist; // [sp+10h] [bp-2Ch]@18
  unsigned int OffsetDista; // [sp+10h] [bp-2Ch]@21
  unsigned int OffsetDistb; // [sp+10h] [bp-2Ch]@24
  unsigned int OffsetDistc; // [sp+10h] [bp-2Ch]@27
  unsigned int OffsetDistd; // [sp+10h] [bp-2Ch]@35
  int CurrentX; // [sp+14h] [bp-28h]@15
  int CurrentXa; // [sp+14h] [bp-28h]@20
  int CurrentXb; // [sp+14h] [bp-28h]@23
  int CurrentXc; // [sp+14h] [bp-28h]@26
  TextureBasedFont *v139; // [sp+18h] [bp-24h]@1
  const float JustifiedX; // [sp+1Ch] [bp-20h]@2
  const float JustifiedY; // [sp+20h] [bp-1Ch]@2
  const char *v142; // [sp+24h] [bp-18h]@16
  int v143; // [sp+28h] [bp-14h]@16
  int v144; // [sp+28h] [bp-14h]@32
  unsigned int c; // [sp+2Ch] [bp-10h]@15
  unsigned int NumCharacters; // [sp+30h] [bp-Ch]@1
  float _Xa; // [sp+40h] [bp+4h]@12
  float OneOverViewportWidth; // [sp+44h] [bp+8h]@12
  const unsigned int _Color32a; // [sp+50h] [bp+14h]@20
  float _Color32b; // [sp+50h] [bp+14h]@20
  const unsigned int _Color32c; // [sp+50h] [bp+14h]@23
  float _Color32d; // [sp+50h] [bp+14h]@23
  const unsigned int _Color32e; // [sp+50h] [bp+14h]@26
  float _Color32f; // [sp+50h] [bp+14h]@26
  const unsigned int _Color32g; // [sp+50h] [bp+14h]@29
  float _Color32h; // [sp+50h] [bp+14h]@29
  const unsigned int _Color32i; // [sp+50h] [bp+14h]@37
  float _Color32j; // [sp+50h] [bp+14h]@37
  int ClipSpaceTopY; // [sp+54h] [bp+18h]@37

  v7 = this;
  v139 = this;
  v8 = strlen(_pText);
  NumCharacters = v8;
  if ( !v8 )
    return;
  JustifiedX = _X;
  v9 = _Flags;
  JustifiedY = _Y;
  if ( _Flags & 8 )
  {
    v10 = (double)TextureBasedFont::ComputeTextWidth(v7, _pText, _Flags) * _Scale;
  }
  else
  {
    if ( !(_Flags & 0x10) )
      goto LABEL_7;
    v10 = (double)TextureBasedFont::ComputeTextWidth(v7, _pText, _Flags) * _Scale * 0.5;
  }
  v9 = _Flags;
  JustifiedX = _X - v10;
LABEL_7:
  if ( v9 & 0x40 )
  {
    v11 = (double)v7->m_MaxCharacterHeight * _Scale;
  }
  else
  {
    if ( v9 >= 0 )
      goto LABEL_12;
    v11 = (double)v7->m_MaxCharacterHeight * _Scale * 0.5;
  }
  JustifiedY = _Y - v11;
LABEL_12:
  _Xa = 1.0 / (double)RenderDevice::render_device->m_viewportWidth;
  v12 = g_FontVertices.m_num;
  v13 = g_FontVertices.m_num + 6 * v8;
  OneOverViewportWidth = 1.0 / (double)RenderDevice::render_device->m_viewportHeight;
  if ( (g_FontVertices.m_sizeAndDeallocate & 0x7FFFFFFF) >= v13
    || (v14 = SmartArray<UIChildFramework *,1>::get_new_size(v13),
        v15 = SmartArray<TextureBasedFontVertexType,1>::grow(
                (SmartArray<TextureBasedFontVertexType,1> *)&g_FontVertices,
                v14) == 0,
        v9 = _Flags,
        !v15) )
    g_FontVertices.m_num = v13;
  v16 = 0;
  v17 = 0;
  v18 = _Color32;
  CurrentX = 0;
  c = 0;
  if ( (signed int)NumCharacters >= 4 )
  {
    v143 = v9 & 1;
    v142 = _pText + 1;
    v19 = 24 * v12;
    do
    {
      v20 = (int)&v139->m_Characters.m_data[(unsigned __int16)(*(v142 - 1) - v139->m_FirstUnicodeCharacter)];
      BeforeVOffset = 0;
      if ( v143 )
      {
        OffsetDist = v139->m_HorizontalSpacing;
        v21 = 0;
      }
      else
      {
        OffsetDist = *(_BYTE *)(v20 + 19) + *(_BYTE *)(v20 + 18) + *(_BYTE *)(v20 + 16);
        v21 = *(_BYTE *)(v20 + 18);
        BeforeVOffset = *(_BYTE *)(v20 + 20);
        v16 = CurrentX;
      }
      v22 = (double)(v16 + v21) * _Scale + JustifiedX;
      *(float *)&_Color32a = v22;
      v23 = v22 * _Xa + v22 * _Xa - 1.0 - _Xa;
      v24 = *(_BYTE *)(v20 + 17) - 1;
      v25 = (char *)g_FontVertices.m_data + v19;
      v26 = (double)(*(_BYTE *)(v20 + 16) - 1) * _Scale;
      *((_DWORD *)v25 + 2) = 0;
      *((_DWORD *)v25 + 3) = v18;
      v27 = v19 + 24;
      v28 = (v26 + *(float *)&_Color32a) * _Xa + (v26 + *(float *)&_Color32a) * _Xa - 1.0 + _Xa;
      v29 = (double)BeforeVOffset * _Scale + JustifiedY;
      _Color32b = -(OneOverViewportWidth * v29 + OneOverViewportWidth * v29 - 1.0 - OneOverViewportWidth);
      *((float *)v25 + 1) = _Color32b;
      v30 = (v29 + (double)v24 * _Scale) * OneOverViewportWidth;
      v31 = -(v30 + v30 - 1.0 + OneOverViewportWidth);
      *(float *)v25 = v23;
      *((_DWORD *)v25 + 4) = *(_DWORD *)v20;
      *((_DWORD *)v25 + 5) = *(_DWORD *)(v20 + 4);
      v32 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v27) = v23;
      v33 = (int)((char *)v32 + v27);
      *(float *)(v33 + 4) = v31;
      *(_DWORD *)(v33 + 8) = 0;
      *(_DWORD *)(v33 + 12) = v18;
      *(_DWORD *)(v33 + 16) = *(_DWORD *)v20;
      v27 += 24;
      *(_DWORD *)(v33 + 20) = *(_DWORD *)(v20 + 12);
      v34 = (char *)g_FontVertices.m_data + v27;
      v27 += 24;
      *((_DWORD *)v34 + 2) = 0;
      *(float *)v34 = v28;
      *((_DWORD *)v34 + 3) = v18;
      BeforeVOffseta = 0;
      *((float *)v34 + 1) = v31;
      *((_DWORD *)v34 + 4) = *(_DWORD *)(v20 + 8);
      *((_DWORD *)v34 + 5) = *(_DWORD *)(v20 + 12);
      v35 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v27) = v28;
      *(unsigned int *)((char *)&v35->NumActive + v27) = 0;
      *(float *)((char *)&v35->DBTypeName.m_charbuffer + v27) = v31;
      *(unsigned int *)((char *)&v35->NumFree + v27) = v18;
      *(_DWORD *)((char *)&v35->LastLocalTimeNotEmpty + v27) = *(_DWORD *)(v20 + 8);
      *(_DWORD *)((char *)&v35->LastLocalTimeNotEmpty + v27 + 4) = *(_DWORD *)(v20 + 12);
      v36 = g_FontVertices.m_data;
      v27 += 24;
      *(float *)((char *)&g_FontVertices.m_data->DBTypeName.m_charbuffer + v27) = _Color32b;
      *(float *)((char *)&v36->DBType + v27) = v28;
      v37 = (int)((char *)v36 + v27);
      *(_DWORD *)(v37 + 8) = 0;
      *(_DWORD *)(v37 + 12) = v18;
      *(_DWORD *)(v37 + 16) = *(_DWORD *)(v20 + 8);
      *(_DWORD *)(v37 + 20) = *(_DWORD *)(v20 + 4);
      v27 += 24;
      v38 = (char *)g_FontVertices.m_data + v27;
      *((float *)v38 + 1) = _Color32b;
      *(float *)v38 = v23;
      *((_DWORD *)v38 + 2) = 0;
      *((_DWORD *)v38 + 3) = v18;
      *((_DWORD *)v38 + 4) = *(_DWORD *)v20;
      *((_DWORD *)v38 + 5) = *(_DWORD *)(v20 + 4);
      CurrentXa = OffsetDist + CurrentX;
      v39 = (int)&v139->m_Characters.m_data[(unsigned __int16)(*v142 - v139->m_FirstUnicodeCharacter)];
      v40 = v12 + 6;
      v41 = v27 + 24;
      v42 = 0;
      if ( v143 )
      {
        OffsetDista = v139->m_HorizontalSpacing;
      }
      else
      {
        v42 = *(_BYTE *)(v39 + 18);
        OffsetDista = *(_BYTE *)(v39 + 19) + v42 + *(_BYTE *)(v39 + 16);
        BeforeVOffseta = *(_BYTE *)(v39 + 20);
      }
      v43 = (double)(CurrentXa + v42) * _Scale + JustifiedX;
      *(float *)&_Color32c = v43;
      v44 = v43 * _Xa + v43 * _Xa - 1.0 - _Xa;
      v45 = *(_BYTE *)(v39 + 17) - 1;
      v46 = (char *)g_FontVertices.m_data + v41;
      v47 = (double)(*(_BYTE *)(v39 + 16) - 1) * _Scale;
      *((_DWORD *)v46 + 2) = 0;
      *((_DWORD *)v46 + 3) = v18;
      v48 = v41 + 24;
      v49 = (v47 + *(float *)&_Color32c) * _Xa + (v47 + *(float *)&_Color32c) * _Xa - 1.0 + _Xa;
      v50 = (double)BeforeVOffseta * _Scale + JustifiedY;
      _Color32d = -(OneOverViewportWidth * v50 + OneOverViewportWidth * v50 - 1.0 - OneOverViewportWidth);
      *((float *)v46 + 1) = _Color32d;
      v51 = (v50 + (double)v45 * _Scale) * OneOverViewportWidth;
      v52 = -(v51 + v51 - 1.0 + OneOverViewportWidth);
      *(float *)v46 = v44;
      *((_DWORD *)v46 + 4) = *(_DWORD *)v39;
      *((_DWORD *)v46 + 5) = *(_DWORD *)(v39 + 4);
      v53 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v48) = v44;
      v54 = (int)((char *)v53 + v48);
      *(float *)(v54 + 4) = v52;
      *(_DWORD *)(v54 + 8) = 0;
      *(_DWORD *)(v54 + 12) = v18;
      *(_DWORD *)(v54 + 16) = *(_DWORD *)v39;
      *(_DWORD *)(v54 + 20) = *(_DWORD *)(v39 + 12);
      v48 += 24;
      v55 = (char *)g_FontVertices.m_data + v48;
      *((_DWORD *)v55 + 2) = 0;
      *(float *)v55 = v49;
      *((_DWORD *)v55 + 3) = v18;
      v48 += 24;
      *((float *)v55 + 1) = v52;
      *((_DWORD *)v55 + 4) = *(_DWORD *)(v39 + 8);
      *((_DWORD *)v55 + 5) = *(_DWORD *)(v39 + 12);
      v56 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v48) = v49;
      *(unsigned int *)((char *)&v56->NumActive + v48) = 0;
      *(float *)((char *)&v56->DBTypeName.m_charbuffer + v48) = v52;
      *(unsigned int *)((char *)&v56->NumFree + v48) = v18;
      *(_DWORD *)((char *)&v56->LastLocalTimeNotEmpty + v48) = *(_DWORD *)(v39 + 8);
      *(_DWORD *)((char *)&v56->LastLocalTimeNotEmpty + v48 + 4) = *(_DWORD *)(v39 + 12);
      v57 = g_FontVertices.m_data;
      v48 += 24;
      *(float *)((char *)&g_FontVertices.m_data->DBTypeName.m_charbuffer + v48) = _Color32d;
      *(float *)((char *)&v57->DBType + v48) = v49;
      v58 = (int)((char *)v57 + v48);
      *(_DWORD *)(v58 + 8) = 0;
      *(_DWORD *)(v58 + 12) = v18;
      *(_DWORD *)(v58 + 16) = *(_DWORD *)(v39 + 8);
      *(_DWORD *)(v58 + 20) = *(_DWORD *)(v39 + 4);
      v48 += 24;
      v59 = (char *)g_FontVertices.m_data + v48;
      *((float *)v59 + 1) = _Color32d;
      *(float *)v59 = v44;
      *((_DWORD *)v59 + 2) = 0;
      *((_DWORD *)v59 + 3) = v18;
      *((_DWORD *)v59 + 4) = *(_DWORD *)v39;
      *((_DWORD *)v59 + 5) = *(_DWORD *)(v39 + 4);
      CurrentXb = OffsetDista + CurrentXa;
      v60 = (int)&v139->m_Characters.m_data[(unsigned __int16)(v142[1] - v139->m_FirstUnicodeCharacter)];
      v61 = v40 + 6;
      v62 = v48 + 24;
      v63 = 0;
      BeforeVOffsetb = 0;
      if ( v143 )
      {
        OffsetDistb = v139->m_HorizontalSpacing;
      }
      else
      {
        v63 = *(_BYTE *)(v60 + 18);
        OffsetDistb = *(_BYTE *)(v60 + 19) + v63 + *(_BYTE *)(v60 + 16);
        BeforeVOffsetb = *(_BYTE *)(v60 + 20);
      }
      v64 = (double)(CurrentXb + v63) * _Scale + JustifiedX;
      *(float *)&_Color32e = v64;
      v65 = v64 * _Xa + v64 * _Xa - 1.0 - _Xa;
      v66 = *(_BYTE *)(v60 + 17) - 1;
      v67 = (char *)g_FontVertices.m_data + v62;
      v68 = (double)(*(_BYTE *)(v60 + 16) - 1) * _Scale;
      *((_DWORD *)v67 + 2) = 0;
      *((_DWORD *)v67 + 3) = v18;
      v69 = v62 + 24;
      v70 = (v68 + *(float *)&_Color32e) * _Xa + (v68 + *(float *)&_Color32e) * _Xa - 1.0 + _Xa;
      v71 = (double)BeforeVOffsetb * _Scale + JustifiedY;
      _Color32f = -(OneOverViewportWidth * v71 + OneOverViewportWidth * v71 - 1.0 - OneOverViewportWidth);
      *((float *)v67 + 1) = _Color32f;
      v72 = (v71 + (double)v66 * _Scale) * OneOverViewportWidth;
      v73 = -(v72 + v72 - 1.0 + OneOverViewportWidth);
      *(float *)v67 = v65;
      *((_DWORD *)v67 + 4) = *(_DWORD *)v60;
      *((_DWORD *)v67 + 5) = *(_DWORD *)(v60 + 4);
      v74 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v69) = v65;
      v75 = (int)((char *)v74 + v69);
      *(float *)(v75 + 4) = v73;
      *(_DWORD *)(v75 + 8) = 0;
      *(_DWORD *)(v75 + 12) = v18;
      *(_DWORD *)(v75 + 16) = *(_DWORD *)v60;
      *(_DWORD *)(v75 + 20) = *(_DWORD *)(v60 + 12);
      v69 += 24;
      v76 = (char *)g_FontVertices.m_data + v69;
      *((_DWORD *)v76 + 2) = 0;
      *(float *)v76 = v70;
      *((_DWORD *)v76 + 3) = v18;
      v69 += 24;
      *((float *)v76 + 1) = v73;
      *((_DWORD *)v76 + 4) = *(_DWORD *)(v60 + 8);
      *((_DWORD *)v76 + 5) = *(_DWORD *)(v60 + 12);
      v77 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v69) = v70;
      *(unsigned int *)((char *)&v77->NumActive + v69) = 0;
      *(float *)((char *)&v77->DBTypeName.m_charbuffer + v69) = v73;
      *(unsigned int *)((char *)&v77->NumFree + v69) = v18;
      *(_DWORD *)((char *)&v77->LastLocalTimeNotEmpty + v69) = *(_DWORD *)(v60 + 8);
      *(_DWORD *)((char *)&v77->LastLocalTimeNotEmpty + v69 + 4) = *(_DWORD *)(v60 + 12);
      v78 = g_FontVertices.m_data;
      v69 += 24;
      *(float *)((char *)&g_FontVertices.m_data->DBTypeName.m_charbuffer + v69) = _Color32f;
      *(float *)((char *)&v78->DBType + v69) = v70;
      v79 = (int)((char *)v78 + v69);
      *(_DWORD *)(v79 + 8) = 0;
      *(_DWORD *)(v79 + 12) = v18;
      *(_DWORD *)(v79 + 16) = *(_DWORD *)(v60 + 8);
      *(_DWORD *)(v79 + 20) = *(_DWORD *)(v60 + 4);
      v69 += 24;
      v80 = (char *)g_FontVertices.m_data + v69;
      *((float *)v80 + 1) = _Color32f;
      *(float *)v80 = v65;
      *((_DWORD *)v80 + 2) = 0;
      *((_DWORD *)v80 + 3) = v18;
      *((_DWORD *)v80 + 4) = *(_DWORD *)v60;
      *((_DWORD *)v80 + 5) = *(_DWORD *)(v60 + 4);
      CurrentXc = OffsetDistb + CurrentXb;
      v81 = (int)&v139->m_Characters.m_data[(unsigned __int16)(v142[2] - v139->m_FirstUnicodeCharacter)];
      v82 = v61 + 6;
      v83 = v69 + 24;
      v84 = 0;
      BeforeVOffsetc = 0;
      if ( v143 )
      {
        OffsetDistc = v139->m_HorizontalSpacing;
      }
      else
      {
        v84 = *(_BYTE *)(v81 + 18);
        OffsetDistc = *(_BYTE *)(v81 + 19) + v84 + *(_BYTE *)(v81 + 16);
        BeforeVOffsetc = *(_BYTE *)(v81 + 20);
      }
      v85 = (double)(CurrentXc + v84) * _Scale + JustifiedX;
      *(float *)&_Color32g = v85;
      v86 = v85 * _Xa + v85 * _Xa - 1.0 - _Xa;
      v87 = *(_BYTE *)(v81 + 17) - 1;
      v88 = (char *)g_FontVertices.m_data + v83;
      v89 = (double)(*(_BYTE *)(v81 + 16) - 1) * _Scale;
      *((_DWORD *)v88 + 2) = 0;
      *((_DWORD *)v88 + 3) = v18;
      v90 = v83 + 24;
      v91 = (v89 + *(float *)&_Color32g) * _Xa + (v89 + *(float *)&_Color32g) * _Xa - 1.0 + _Xa;
      v92 = (double)BeforeVOffsetc * _Scale + JustifiedY;
      _Color32h = -(OneOverViewportWidth * v92 + OneOverViewportWidth * v92 - 1.0 - OneOverViewportWidth);
      *((float *)v88 + 1) = _Color32h;
      v93 = (v92 + (double)v87 * _Scale) * OneOverViewportWidth;
      v94 = -(v93 + v93 - 1.0 + OneOverViewportWidth);
      *(float *)v88 = v86;
      *((_DWORD *)v88 + 4) = *(_DWORD *)v81;
      *((_DWORD *)v88 + 5) = *(_DWORD *)(v81 + 4);
      v95 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v90) = v86;
      v96 = (int)((char *)v95 + v90);
      *(float *)(v96 + 4) = v94;
      *(_DWORD *)(v96 + 8) = 0;
      *(_DWORD *)(v96 + 12) = v18;
      *(_DWORD *)(v96 + 16) = *(_DWORD *)v81;
      *(_DWORD *)(v96 + 20) = *(_DWORD *)(v81 + 12);
      v90 += 24;
      v97 = (char *)g_FontVertices.m_data + v90;
      *((_DWORD *)v97 + 2) = 0;
      *(float *)v97 = v91;
      *((_DWORD *)v97 + 3) = v18;
      v90 += 24;
      *((float *)v97 + 1) = v94;
      *((_DWORD *)v97 + 4) = *(_DWORD *)(v81 + 8);
      *((_DWORD *)v97 + 5) = *(_DWORD *)(v81 + 12);
      v98 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v90) = v91;
      v99 = (int)((char *)v98 + v90);
      *(float *)(v99 + 4) = v94;
      *(_DWORD *)(v99 + 8) = 0;
      *(_DWORD *)(v99 + 12) = v18;
      *(_DWORD *)(v99 + 16) = *(_DWORD *)(v81 + 8);
      *(_DWORD *)(v99 + 20) = *(_DWORD *)(v81 + 12);
      v100 = g_FontVertices.m_data;
      v90 += 24;
      *(float *)((char *)&g_FontVertices.m_data->DBTypeName.m_charbuffer + v90) = _Color32h;
      *(float *)((char *)&v100->DBType + v90) = v91;
      v101 = (int)((char *)v100 + v90);
      *(_DWORD *)(v101 + 8) = 0;
      *(_DWORD *)(v101 + 12) = v18;
      *(_DWORD *)(v101 + 16) = *(_DWORD *)(v81 + 8);
      *(_DWORD *)(v101 + 20) = *(_DWORD *)(v81 + 4);
      v90 += 24;
      v102 = (char *)g_FontVertices.m_data + v90;
      *((float *)v102 + 1) = _Color32h;
      *(float *)v102 = v86;
      *((_DWORD *)v102 + 2) = 0;
      *((_DWORD *)v102 + 3) = v18;
      *((_DWORD *)v102 + 4) = *(_DWORD *)v81;
      *((_DWORD *)v102 + 5) = *(_DWORD *)(v81 + 4);
      c += 4;
      v16 = OffsetDistc + CurrentXc;
      v103 = (int)&v142[2 - (_DWORD)_pText + 4];
      v142 += 4;
      v12 = v82 + 6;
      v19 = v90 + 24;
      CurrentX = OffsetDistc + CurrentXc;
    }
    while ( v103 < NumCharacters );
    v9 = _Flags;
    v17 = c;
  }
  if ( v17 < NumCharacters )
  {
    v104 = v9 & 1;
    v144 = v9 & 1;
    v105 = 24 * v12;
    while ( 1 )
    {
      v106 = (int)&v139->m_Characters.m_data[(unsigned __int16)(_pText[v17] - v139->m_FirstUnicodeCharacter)];
      v107 = 0;
      BeforeVOffsetd = 0;
      if ( v104 )
      {
        OffsetDistd = v139->m_HorizontalSpacing;
      }
      else
      {
        OffsetDistd = *(_BYTE *)(v106 + 19) + *(_BYTE *)(v106 + 18) + *(_BYTE *)(v106 + 16);
        v107 = *(_BYTE *)(v106 + 18);
        BeforeVOffsetd = *(_BYTE *)(v106 + 20);
      }
      v108 = (double)(v16 + v107) * _Scale + JustifiedX;
      *(float *)&_Color32i = v108;
      v109 = v108 * _Xa + v108 * _Xa - 1.0 - _Xa;
      v110 = (double)(*(_BYTE *)(v106 + 16) - 1);
      ClipSpaceTopY = *(_BYTE *)(v106 + 17) - 1;
      v111 = g_FontVertices.m_data;
      *(unsigned int *)((char *)&g_FontVertices.m_data->NumActive + v105) = 0;
      *(unsigned int *)((char *)&v111->NumFree + v105) = v18;
      v112 = (int)((char *)v111 + v105);
      v113 = v105 + 24;
      v114 = (v110 * _Scale + *(float *)&_Color32i) * _Xa + (v110 * _Scale + *(float *)&_Color32i) * _Xa - 1.0 + _Xa;
      v115 = (double)BeforeVOffsetd * _Scale + JustifiedY;
      _Color32j = -(OneOverViewportWidth * v115 + OneOverViewportWidth * v115 - 1.0 - OneOverViewportWidth);
      *(float *)(v112 + 4) = _Color32j;
      v116 = (v115 + (double)ClipSpaceTopY * _Scale) * OneOverViewportWidth;
      v117 = -(v116 + v116 - 1.0 + OneOverViewportWidth);
      *(float *)v112 = v109;
      *(_DWORD *)(v112 + 16) = *(_DWORD *)v106;
      *(_DWORD *)(v112 + 20) = *(_DWORD *)(v106 + 4);
      v118 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v113) = v109;
      v119 = (int)((char *)v118 + v113);
      *(float *)(v119 + 4) = v117;
      *(_DWORD *)(v119 + 8) = 0;
      *(_DWORD *)(v119 + 12) = v18;
      *(_DWORD *)(v119 + 16) = *(_DWORD *)v106;
      *(_DWORD *)(v119 + 20) = *(_DWORD *)(v106 + 12);
      v113 += 24;
      v120 = (char *)g_FontVertices.m_data + v113;
      *(float *)v120 = v114;
      v113 += 24;
      *((float *)v120 + 1) = v117;
      *((_DWORD *)v120 + 2) = 0;
      *((_DWORD *)v120 + 3) = v18;
      *((_DWORD *)v120 + 4) = *(_DWORD *)(v106 + 8);
      *((_DWORD *)v120 + 5) = *(_DWORD *)(v106 + 12);
      v121 = g_FontVertices.m_data;
      *(float *)((char *)&g_FontVertices.m_data->DBType + v113) = v114;
      *(unsigned int *)((char *)&v121->NumActive + v113) = 0;
      *(float *)((char *)&v121->DBTypeName.m_charbuffer + v113) = v117;
      *(unsigned int *)((char *)&v121->NumFree + v113) = v18;
      *(_DWORD *)((char *)&v121->LastLocalTimeNotEmpty + v113) = *(_DWORD *)(v106 + 8);
      *(_DWORD *)((char *)&v121->LastLocalTimeNotEmpty + v113 + 4) = *(_DWORD *)(v106 + 12);
      v122 = g_FontVertices.m_data;
      v113 += 24;
      *(float *)((char *)&g_FontVertices.m_data->DBTypeName.m_charbuffer + v113) = _Color32j;
      *(float *)((char *)&v122->DBType + v113) = v114;
      v123 = (int)((char *)v122 + v113);
      *(_DWORD *)(v123 + 8) = 0;
      *(_DWORD *)(v123 + 12) = v18;
      *(_DWORD *)(v123 + 16) = *(_DWORD *)(v106 + 8);
      *(_DWORD *)(v123 + 20) = *(_DWORD *)(v106 + 4);
      v113 += 24;
      v124 = (char *)g_FontVertices.m_data + v113;
      *((float *)v124 + 1) = _Color32j;
      *(float *)v124 = v109;
      *((_DWORD *)v124 + 2) = 0;
      *((_DWORD *)v124 + 3) = v18;
      *((_DWORD *)v124 + 4) = *(_DWORD *)v106;
      v16 += OffsetDistd;
      v105 = v113 + 24;
      *((_DWORD *)v124 + 5) = *(_DWORD *)(v106 + 4);
      v17 = c + 1;
      c = v17;
      if ( v17 >= NumCharacters )
        break;
      v104 = v144;
    }
  }
  if ( fabs(_Scale) > 0.00019999999 )
    v139->m_QueuedTextUsesScaling = 1;
}

//----- (00697470) --------------------------------------------------------  // acclient.c:687058
void __thiscall TextureBasedFont::RenderText(TextureBasedFont *this, const int _X, const int _Y, const char *_pText, const unsigned int _Color32, const unsigned int _Flags)
{
  float v6; // ST04_4@1
  float v7; // ST00_4@1

  v6 = (double)_Y;
  v7 = (double)_X;
  TextureBasedFont::RenderText(this, v7, v6, 1.0, _pText, _Color32, _Flags);
}

//----- (006974A0) --------------------------------------------------------  // acclient.c:687069
bool __thiscall TextureBasedFont::InitFromFont(TextureBasedFont *this, const unsigned int _FontID)
{
  TextureBasedFont *v2; // ebp@1
  int v3; // eax@1
  RenderMaterial *v4; // eax@3
  RenderMaterial *v5; // eax@4
  MaterialLayer *v6; // eax@7
  int v7; // eax@8
  int v8; // edi@8
  LayerStage *v9; // eax@9
  LayerStage *v10; // eax@10
  LayerStage *v11; // esi@10
  RenderTexture *v12; // ecx@13
  unsigned int v14; // eax@16

  v2 = this;
  this->m_IsReadyToRender = 0;
  v3 = ((int (*)(void))RenderDevice::render_device->vfptr->CreateTexture)();
  v2->m_pTexture = (RenderTexture *)v3;
  if ( !v3 )
    return 0;
  *(_BYTE *)(v3 + 120) = 0;
  if ( !v2->m_pMaterial )
  {
    v4 = (RenderMaterial *)operator new(0x4E0u);
    if ( v4 )
      RenderMaterial::RenderMaterial(v4);
    else
      v5 = 0;
    v2->m_pMaterial = v5;
    if ( !v5 )
      return 0;
    v6 = (MaterialLayer *)operator new(0xD8u);
    if ( !v6 )
      return 0;
    MaterialLayer::MaterialLayer(v6);
    v8 = v7;
    if ( !v7 )
      return 0;
    v9 = (LayerStage *)operator new(0x48u);
    if ( !v9 )
      return 0;
    LayerStage::LayerStage(v9);
    v11 = v10;
    if ( !v10 )
      return 0;
    MaterialLayer::InsertStage((MaterialLayer *)v8, *(_DWORD *)(v8 + 36), v10);
    RenderMaterial::InsertLayer(v2->m_pMaterial, v2->m_pMaterial->layers.m_num, (MaterialLayer *)v8);
    *(_DWORD *)v8 |= 0x20u;
    *(_DWORD *)(v8 + 52) = 5;
    *(_DWORD *)(v8 + 56) = 6;
    *(_BYTE *)(v8 + 68) = 0;
    *(_DWORD *)(v8 + 64) = 8;
    *(_DWORD *)(v8 + 72) = 1;
    LayerStage::SetTexture(v11, v2->m_pTexture);
    v11->m_MinFilterMode = 1;
    v11->m_MagFilterMode = 1;
    v11->m_AddressModeU = 3;
    v11->m_AddressModeV = 3;
    v11->m_FFColorOp = 3;
    v11->m_FFTexCoordIndex = 0;
    v11->m_FFColorArg1 = 2;
    v11->m_FFColorArg2 = 0;
    v11->m_FFAlphaOp = 4;
    v11->m_FFAlphaArg1 = 2;
    v11->m_FFAlphaArg2 = 0;
    RenderMaterial::Optimize(v2->m_pMaterial);
  }
  if ( !(unsigned __int8)((int (__stdcall *)(signed int, signed int, signed int, signed int, _DWORD))v2->m_pTexture->vfptr[3].AddRef)(
                           256,
                           256,
                           1,
                           21,
                           0) )
  {
    v12 = v2->m_pTexture;
    if ( v12 )
    {
      ((void (*)(void))v12->vfptr->Release)();
      v2->m_pTexture = 0;
    }
    return 0;
  }
  v14 = DBObj::GetDIDByEnum((IDClass<_tagDataID,32,0> *)&_FontID, _FontID, 9)->id;
  v2->m_SourceFontDID.id = v14;
  if ( v14 == stru_8F8A58.id )
    return 0;
  return TextureBasedFont::SetupFontTexture(v2) != 0;
}

//----- (00697630) --------------------------------------------------------  // acclient.c:687160
TResult *__cdecl TextureBasedFont::CreateFromFont(TResult *result, const unsigned int _FontID, TextureBasedFont **_pOutObject)
{
  void *v3; // eax@1
  TextureBasedFont *v4; // ecx@6
  bool v5; // zf@7
  TResult *v6; // eax@10

  v3 = operator new(0x30u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 1;
    *(_DWORD *)v3 = &TextureBasedFont::vftable;
    *((_DWORD *)v3 + 2) = stru_8F8A58.id;
    *((_DWORD *)v3 + 4) = 0;
    *((_WORD *)v3 + 10) = 0;
    *((_WORD *)v3 + 11) = 0;
    *((_DWORD *)v3 + 6) = 0;
    *((_DWORD *)v3 + 7) = 0;
    *((_DWORD *)v3 + 8) = 0;
    *((_DWORD *)v3 + 9) = 0;
    *((_DWORD *)v3 + 10) = 0;
    *((_BYTE *)v3 + 44) = 0;
    *((_BYTE *)v3 + 45) = 0;
  }
  else
  {
    v3 = 0;
  }
  *_pOutObject = (TextureBasedFont *)v3;
  if ( !v3 )
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467259;
    return v6;
  }
  if ( !TextureBasedFont::InitFromFont((TextureBasedFont *)v3, _FontID) )
  {
    v4 = *_pOutObject;
    if ( *_pOutObject )
    {
      v5 = v4->m_cRef-- == 1;
      if ( v5 )
        ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
      *_pOutObject = 0;
    }
    goto LABEL_10;
  }
  v6 = result;
  result->m_val = 0;
  return v6;
}
// 8009C4: using guessed type int (__thiscall *TextureBasedFont::vftable)(void *, char);

//----- (0071A020) --------------------------------------------------------  // acclient.c:812577
void sub_71A020()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8A20, PFID_A8R8G8B8);
}

//----- (0071A030) --------------------------------------------------------  // acclient.c:812583
int sub_71A030()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_79, "None");
  return atexit(_E92_51);
}

//----- (0071A050) --------------------------------------------------------  // acclient.c:812590
int _E94_42()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_79, "Speed");
  return atexit(sub_7856A0);
}

//----- (0071A070) --------------------------------------------------------  // acclient.c:812597
int sub_71A070()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_79, "Noise");
  return atexit(sub_7856D0);
}

//----- (0071A090) --------------------------------------------------------  // acclient.c:812604
int sub_71A090()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_79, "Sine");
  return atexit(sub_785700);
}

//----- (0071A0B0) --------------------------------------------------------  // acclient.c:812611
int sub_71A0B0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_79, "Square");
  return atexit(sub_785730);
}

//----- (0071A0D0) --------------------------------------------------------  // acclient.c:812618
int sub_71A0D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_79, "Bounce");
  return atexit(sub_785760);
}

//----- (0071A0F0) --------------------------------------------------------  // acclient.c:812625
int _E109_91()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_79, "Perlin");
  return atexit(sub_785790);
}

//----- (0071A110) --------------------------------------------------------  // acclient.c:812632
int sub_71A110()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_79, "Fractal");
  return atexit(_E113_76);
}

//----- (0071A130) --------------------------------------------------------  // acclient.c:812639
int _E115_95()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_79, "FrameLoop");
  return atexit(_E116_68);
}

//----- (0071A150) --------------------------------------------------------  // acclient.c:812646
void _E118_86()
{
  LODWORD(dword_8F8A80) = 1053364187;
}

//----- (0071A160) --------------------------------------------------------  // acclient.c:812652
void _E120_80()
{
  flt_8F8A84 = 1000.0 + 1.0;
}

//----- (0071A180) --------------------------------------------------------  // acclient.c:812658
void _E122_35()
{
  flt_8F8A88 = 24.0 * 8.0;
}

//----- (0071A1A0) --------------------------------------------------------  // acclient.c:812664
void _E124_77()
{
  flt_8F8A8C = 24.0 * 0.5;
}

//----- (0071A1C0) --------------------------------------------------------  // acclient.c:812670
int _E126_58()
{
  return atexit(sub_785820);
}

//----- (0071A1D0) --------------------------------------------------------  // acclient.c:812676
int sub_71A1D0()
{
  return atexit(nullsub_268);
}

//----- (00785670) --------------------------------------------------------  // acclient.c:924681
void __cdecl _E92_51()
{
  char *v0; // esi@1

  v0 = &waveform_None_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007856A0) --------------------------------------------------------  // acclient.c:924694
void __cdecl sub_7856A0()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007856D0) --------------------------------------------------------  // acclient.c:924707
void __cdecl sub_7856D0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785700) --------------------------------------------------------  // acclient.c:924720
void __cdecl sub_785700()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785730) --------------------------------------------------------  // acclient.c:924733
void __cdecl sub_785730()
{
  char *v0; // esi@1

  v0 = &waveform_Square_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785760) --------------------------------------------------------  // acclient.c:924746
void __cdecl sub_785760()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785790) --------------------------------------------------------  // acclient.c:924759
void __cdecl sub_785790()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007857C0) --------------------------------------------------------  // acclient.c:924772
void __cdecl _E113_76()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007857F0) --------------------------------------------------------  // acclient.c:924785
void __cdecl _E116_68()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_79.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_79.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785820) --------------------------------------------------------  // acclient.c:924798
void __cdecl sub_785820()
{
  if ( (g_FontVertices.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](g_FontVertices.m_data);
}

