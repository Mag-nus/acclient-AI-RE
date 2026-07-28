/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Font
   Object     : ENGINE\render_base\Font.obj
   Functions  : 16
   Addresses  : 004432F0 - 006C7780 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004432F0) --------------------------------------------------------  // acclient.c:127298
void __thiscall Font::End(Font *this)
{
  Font *v1; // esi@1

  v1 = this;
  ((void (*)(void))this->vfptr[1].Release)();
  if ( v1->characterMap )
  {
    operator delete[](v1->characterMap);
    v1->characterMap = 0;
  }
  if ( v1->charDescs )
  {
    operator delete[](v1->charDescs);
    v1->charDescs = 0;
  }
}

//----- (00443330) --------------------------------------------------------  // acclient.c:127317
char __thiscall Font::ReleaseSubObjects(Font *this)
{
  Font *v1; // esi@1
  RenderSurface *v2; // ecx@1
  RenderSurface *v3; // ecx@3

  v1 = this;
  v2 = this->m_pForegroundSurface;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pForegroundSurface = 0;
  }
  v3 = v1->m_pBackgroundSurface;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pBackgroundSurface = 0;
  }
  return 1;
}

//----- (00443360) --------------------------------------------------------  // acclient.c:127340
int __thiscall Font::GetCharDesc(Font *this, const unsigned __int16 chr)
{
  FontCharDesc *v2; // ebp@1
  unsigned __int16 *v3; // ebx@2
  unsigned __int16 v4; // di@2
  unsigned __int16 v5; // ax@4
  unsigned __int16 v6; // dx@6
  unsigned int v7; // eax@8
  unsigned int v9; // esi@10
  FontCharDesc *v10; // edx@11

  v2 = this->charDescs;
  if ( !v2 )
    return 0;
  v3 = this->characterMap;
  v4 = chr;
  while ( v3 )
  {
    v5 = this->minUnicodeChar;
    if ( v4 >= v5 && v4 <= this->maxUnicodeChar )
    {
      v6 = v3[v4 - v5];
      if ( v6 >= this->numCharacters )
        return 0;
      if ( &v2[v6] )
      {
        v7 = v6;
        return (int)&v2[v7];
      }
    }
LABEL_14:
    if ( v4 == 63 )
      return 0;
    v4 = 63;
  }
  v9 = this->numCharacters;
  v7 = 0;
  if ( !v9 )
    goto LABEL_14;
  v10 = this->charDescs;
  while ( v10->m_Unicode != v4 )
  {
    ++v7;
    ++v10;
    if ( v7 >= v9 )
      goto LABEL_14;
  }
  return (int)&v2[v7];
}

//----- (004433F0) --------------------------------------------------------  // acclient.c:127391
char __thiscall Font::GetCharWidthA(Font *this, const unsigned __int16 chr)
{
  int v2; // eax@1
  int v3; // eax@2

  v2 = Font::GetCharDesc(this, chr);
  if ( v2 )
    v3 = *(_BYTE *)(v2 + 6) + *(_BYTE *)(v2 + 8) + *(_BYTE *)(v2 + 9);
  else
    LOBYTE(v3) = 0;
  return v3;
}

//----- (00443420) --------------------------------------------------------  // acclient.c:127405
char __thiscall Font::ContainsChar(Font *this, const unsigned __int16 ch)
{
  FontCharDesc *v2; // ebx@1
  unsigned __int16 *v3; // edi@2
  char result; // al@2
  unsigned __int16 v5; // dx@3
  unsigned int v6; // edx@5

  v2 = this->charDescs;
  if ( !v2
    || (v3 = this->characterMap, result = 1, v3)
    && ((v5 = this->minUnicodeChar, ch < v5)
     || ch > this->maxUnicodeChar
     || (v6 = v3[ch - v5], v6 >= this->numCharacters)
     || !&v2[v6]) )
    result = 0;
  return result;
}

//----- (00443470) --------------------------------------------------------  // acclient.c:127425
char __thiscall Font::GenerateCharacterMap(Font *this)
{
  Font *v1; // esi@1
  FontCharDesc *v2; // edx@1
  unsigned int v3; // eax@2
  int v4; // ecx@2
  int v5; // eax@3
  unsigned __int16 v6; // ax@4
  unsigned __int16 v7; // ax@9
  unsigned __int16 v8; // cx@9
  int v9; // eax@10
  void *v10; // eax@10
  unsigned int v11; // edx@10
  int v12; // eax@10
  int v13; // ecx@11
  char result; // al@13

  v1 = this;
  v2 = this->charDescs;
  if ( !v2 )
    goto LABEL_17;
  v3 = this->numCharacters;
  v4 = 0;
  v1->minUnicodeChar = -1;
  v1->maxUnicodeChar = 0;
  if ( v3 )
  {
    v5 = 0;
    do
    {
      v6 = v2[v5].m_Unicode;
      if ( v6 < v1->minUnicodeChar )
        v1->minUnicodeChar = v6;
      if ( v6 > v1->maxUnicodeChar )
        v1->maxUnicodeChar = v6;
      ++v4;
      v5 = (unsigned __int16)v4;
    }
    while ( (unsigned __int16)v4 < v1->numCharacters );
  }
  v7 = v1->maxUnicodeChar;
  v8 = v1->minUnicodeChar;
  if ( v7 >= v8 )
  {
    v9 = v7 - v8 + 1;
    v1->unicodeRangeLength = v9;
    v10 = operator new[](2 * v9);
    v11 = 2 * v1->unicodeRangeLength;
    v1->characterMap = (unsigned __int16 *)v10;
    memset(v10, 0, v11);
    v12 = 0;
    if ( v1->numCharacters )
    {
      v13 = 0;
      do
      {
        v1->characterMap[v1->charDescs[v13].m_Unicode - v1->minUnicodeChar] = v12++;
        v13 = (unsigned __int16)v12;
      }
      while ( (unsigned __int16)v12 < v1->numCharacters );
    }
    result = 1;
  }
  else
  {
LABEL_17:
    result = 0;
  }
  return result;
}

//----- (00443540) --------------------------------------------------------  // acclient.c:127497
bool __thiscall Font::LockSurfaces(Font *this)
{
  Font *v1; // esi@1
  RenderSurface *v2; // eax@1
  RenderSurface *v3; // esi@3
  bool result; // al@5

  v1 = this;
  v2 = this->m_pForegroundSurface;
  result = 0;
  if ( !v2 || SurfaceWindow::Lock(&v2->window, 1) )
  {
    v3 = v1->m_pBackgroundSurface;
    if ( !v3 || SurfaceWindow::Lock(&v3->window, 1) )
      result = 1;
  }
  return result;
}

//----- (00443580) --------------------------------------------------------  // acclient.c:127517
bool __thiscall Font::UnlockSurfaces(Font *this)
{
  Font *v1; // esi@1
  RenderSurface *v2; // eax@1
  RenderSurface *v3; // esi@3
  bool result; // al@5

  v1 = this;
  v2 = this->m_pForegroundSurface;
  result = 0;
  if ( !v2 || SurfaceWindow::Unlock(&v2->window) )
  {
    v3 = v1->m_pBackgroundSurface;
    if ( !v3 || SurfaceWindow::Unlock(&v3->window) )
      result = 1;
  }
  return result;
}

//----- (004435C0) --------------------------------------------------------  // acclient.c:127537
char __thiscall Font::InitLoad(Font *this)
{
  char result; // al@1

  result = Font::GenerateCharacterMap(this);
  if ( result )
    result = 1;
  return result;
}

//----- (004435E0) --------------------------------------------------------  // acclient.c:127548
char __thiscall Font::GetSubObjects(Font *this)
{
  Font *v1; // esi@1
  unsigned int v2; // eax@1
  char v3; // bl@1
  QualifiedDataID *v4; // eax@2
  int v5; // eax@2
  IDClass<_tagDataID,32,0> v6; // eax@4
  QualifiedDataID *v7; // eax@5
  int v8; // eax@5
  char result; // al@6
  QualifiedDataID v10; // [sp+8h] [bp-8h]@2

  v1 = this;
  v2 = this->m_ForegroundSurfaceDataID.id;
  v3 = 1;
  if ( v2 != INVALID_DID_32.id )
  {
    QualifiedDataID::QualifiedDataID(&v10, (IDClass<_tagDataID,32,0>)v2, 0xCu);
    v5 = DBObj::Get(v4);
    v1->m_pForegroundSurface = (RenderSurface *)v5;
    if ( !v5 )
      v3 = 0;
  }
  v6.id = v1->m_BackgroundSurfaceDataID.id;
  if ( v6.id == INVALID_DID_32.id
    || (QualifiedDataID::QualifiedDataID(&v10, v6, 0xCu),
        v8 = DBObj::Get(v7),
        (v1->m_pBackgroundSurface = (RenderSurface *)v8) != 0) )
    result = v3;
  else
    result = 0;
  return result;
}

//----- (00443650) --------------------------------------------------------  // acclient.c:127584
void __thiscall Font::Serialize(Font *this, Archive *io_archive)
{
  Font *v2; // ebx@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  int v6; // esi@13
  const void *v7; // edi@15
  unsigned int v8; // eax@15
  unsigned int v9; // ecx@16
  char v10; // dl@17
  unsigned int v11; // ecx@17
  int v12; // edi@17
  int v13; // esi@17
  char v14; // cl@17
  const void *v15; // esi@18
  char v16; // al@18
  unsigned int v17; // ecx@18
  unsigned int v18; // eax@20
  unsigned int v19; // eax@24
  unsigned int v20; // eax@28
  unsigned int v21; // eax@32
  unsigned int v22; // eax@36

  v2 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->maxCharHeight;
    else
      v2->maxCharHeight = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v2->maxCharWidth;
    else
      v2->maxCharWidth = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->numCharacters;
    else
      v2->numCharacters = *(_DWORD *)v5;
  }
  v6 = 11 * v2->numCharacters;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    v2->charDescs = (FontCharDesc *)operator new[](v6);
  v7 = v2->charDescs;
  v8 = Archive::GetBytes(io_archive, v6);
  if ( v8 )
  {
    v9 = v6;
    if ( io_archive->m_flags & 1 )
    {
      v10 = v6;
      v11 = (unsigned int)v6 >> 2;
      qmemcpy((void *)v8, v7, 4 * ((unsigned int)v6 >> 2));
      v13 = (int)((char *)v7 + 4 * ((unsigned int)v6 >> 2));
      v12 = v8 + 4 * v11;
      v14 = v10;
    }
    else
    {
      v15 = (const void *)v8;
      v16 = v9;
      v17 = v9 >> 2;
      qmemcpy((void *)v7, v15, 4 * v17);
      v13 = (int)((char *)v15 + 4 * v17);
      v12 = (int)((char *)v7 + 4 * v17);
      v14 = v16;
    }
    qmemcpy((void *)v12, (const void *)v13, v14 & 3);
  }
  Archive::CheckAlignment(io_archive, 4u);
  v18 = Archive::GetBytes(io_archive, 4u);
  if ( v18 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v18 = v2->m_NumHorizontalBorderPixels;
    else
      v2->m_NumHorizontalBorderPixels = *(_DWORD *)v18;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v19 = Archive::GetBytes(io_archive, 4u);
  if ( v19 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v19 = v2->m_NumVerticalBorderPixels;
    else
      v2->m_NumVerticalBorderPixels = *(_DWORD *)v19;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v20 = Archive::GetBytes(io_archive, 4u);
  if ( v20 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v20 = v2->m_BaselineOffset;
    else
      v2->m_BaselineOffset = *(_DWORD *)v20;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v21 = Archive::GetBytes(io_archive, 4u);
  if ( v21 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v21 = v2->m_ForegroundSurfaceDataID.id;
    else
      v2->m_ForegroundSurfaceDataID.id = *(_DWORD *)v21;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v22 = Archive::GetBytes(io_archive, 4u);
  if ( v22 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v22 = v2->m_BackgroundSurfaceDataID.id;
    else
      v2->m_BackgroundSurfaceDataID.id = *(_DWORD *)v22;
  }
}

//----- (00443800) --------------------------------------------------------  // acclient.c:127714
void __thiscall Font::Begin(Font *this)
{
  Font *v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // ebx@2
  volatile LONG *v4; // ST00_4@5
  PSRefBufferCharData<char> *v5; // eax@6
  int v6; // ebx@7
  volatile LONG *v7; // ST00_4@10
  unsigned int v8; // edx@11

  v1 = this;
  this->maxCharHeight = 0;
  this->maxCharWidth = 0;
  this->numCharacters = 0;
  this->charDescs = 0;
  this->m_NumHorizontalBorderPixels = 0;
  this->m_NumVerticalBorderPixels = 0;
  v2 = this->m_ForegroundSurfaceFileName.m_charbuffer;
  if ( v2 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_ForegroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
  v1->m_ForegroundSurfaceDataID.id = INVALID_DID_32.id;
  v1->m_pForegroundSurface = 0;
  v5 = v1->m_BackgroundSurfaceFileName.m_charbuffer;
  if ( v5 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_BackgroundSurfaceFileName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v7);
  }
  v8 = INVALID_DID_32.id;
  v1->m_pBackgroundSurface = 0;
  v1->minUnicodeChar = 0;
  v1->maxUnicodeChar = 0;
  v1->unicodeRangeLength = 0;
  v1->characterMap = 0;
  v1->m_BackgroundSurfaceDataID.id = v8;
}

//----- (004438C0) --------------------------------------------------------  // acclient.c:127764
void __thiscall Font::Destroy(Font *this)
{
  Font *v1; // esi@1

  v1 = this;
  ((void (*)(void))this->vfptr[1].Release)();
  if ( v1->characterMap )
  {
    operator delete[](v1->characterMap);
    v1->characterMap = 0;
  }
  if ( v1->charDescs )
  {
    operator delete[](v1->charDescs);
    v1->charDescs = 0;
  }
  Font::Begin(v1);
}

//----- (00443900) --------------------------------------------------------  // acclient.c:127784
void __thiscall Font::GetSubDataIDs(Font *this, QualifiedDataIDArray *_aQDID)
{
  Font *v2; // esi@1
  unsigned int v3; // eax@1
  QualifiedDataID *v4; // eax@2
  IDClass<_tagDataID,32,0> v5; // esi@3
  QualifiedDataID *v6; // eax@4
  QualifiedDataID v7; // [sp+8h] [bp-8h]@2

  v2 = this;
  v3 = this->m_ForegroundSurfaceDataID.id;
  if ( v3 != INVALID_DID_32.id )
  {
    QualifiedDataID::QualifiedDataID(&v7, (IDClass<_tagDataID,32,0>)v3, 0);
    QualifiedDataIDArray::AddQDID(_aQDID, v4, 0);
  }
  v5.id = v2->m_BackgroundSurfaceDataID.id;
  if ( v5.id != INVALID_DID_32.id )
  {
    QualifiedDataID::QualifiedDataID(&v7, v5, 0);
    QualifiedDataIDArray::AddQDID(_aQDID, v6, 0);
  }
}

//----- (006C7770) --------------------------------------------------------  // acclient.c:735466
void _E73_35()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_10, PFID_A8R8G8B8);
}

//----- (006C7780) --------------------------------------------------------  // acclient.c:735472
int _E1_32()
{
  return atexit(_E2_32);
}

