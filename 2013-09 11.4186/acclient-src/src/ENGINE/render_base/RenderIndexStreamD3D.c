/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderIndexStreamD3D
   Object     : ENGINE\render_base\RenderIndexStreamD3D.obj
   Functions  : 10
   Addresses  : 00697B70 - 0071A310 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00697B70) --------------------------------------------------------  // acclient.c:687520
void __thiscall RenderIndexStreamD3D::RenderIndexStreamD3D(RenderIndexStreamD3D *this)
{
  RenderIndexStreamD3D *v1; // esi@1

  v1 = this;
  GraphicsResource::GraphicsResource((GraphicsResource *)&this->vfptr);
  v1->m_Flags = 0;
  v1->m_NumIndices = 0;
  v1->m_pDirect3DIndexBuffer = 0;
  v1->m_StreamFrameID = 0;
  v1->m_NextRemoteIndex = 0;
  v1->m_WriteLockCount = 0;
  v1->vfptr = (GraphicsResourceVtbl *)&RenderIndexStreamD3D::vftable;
  v1->m_IndexSizeInBytes = 2;
}
// 8009D4: using guessed type int (__thiscall *RenderIndexStreamD3D::vftable)(void *, char);

//----- (00697BA0) --------------------------------------------------------  // acclient.c:687538
char __thiscall RenderIndexStreamD3D::Init(RenderIndexStreamD3D *this, const unsigned int _NumIndices, const unsigned int _Flags)
{
  RenderIndexStreamD3D *v3; // esi@1
  char result; // al@2

  v3 = this;
  if ( _NumIndices )
  {
    this->m_NumIndices = _NumIndices;
    this->m_Flags = _Flags;
    GraphicsResource::SetResourceIsThrashable((GraphicsResource *)&this->vfptr, ~(unsigned __int8)(_Flags >> 1) & 1);
    v3->m_StreamFrameID = 0;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00697BE0) --------------------------------------------------------  // acclient.c:687560
char __thiscall RenderIndexStreamD3D::CreateDirect3DIndexBuffer(RenderIndexStreamD3D *this)
{
  RenderIndexStreamD3D *v1; // edi@1
  unsigned int v2; // eax@1
  bool v3; // cl@4
  unsigned int v4; // eax@9
  char result; // al@11
  signed int v6; // ebx@13
  const unsigned int v7; // esi@16
  int v8; // eax@17
  int v9; // ecx@21
  char CanDiscardMoreMemory; // [sp+1Dh] [bp-9h]@16
  unsigned int D3DUsage; // [sp+1Eh] [bp-8h]@1
  _D3DFORMAT D3DFormat; // [sp+22h] [bp-4h]@6

  v1 = this;
  v2 = this->m_Flags;
  D3DUsage = 8;
  if ( v2 & 1 || !(v2 & 4) )
    D3DUsage = 520;
  v3 = RenderDevice::render_device->m_caps.bHardwareVertexProcessing;
  if ( !v3 )
    D3DUsage |= 0x10u;
  D3DFormat = 0;
  if ( v2 & 2 || !v3 )
    D3DFormat = 2;
  v4 = v1->m_IndexSizeInBytes;
  if ( v4 == 2 || v4 == 4 )
  {
    if ( v4 == 2 )
    {
      v6 = 101;
    }
    else
    {
      v6 = 102;
      if ( v4 != 4 )
        v6 = D3DFormat;
    }
    v7 = v4 * v1->m_NumIndices;
    for ( CanDiscardMoreMemory = 1; ; CanDiscardMoreMemory = GraphicsResource::DiscardResourceBytes(v7) )
    {
      v8 = (*(int (__stdcall **)(_DWORD, const unsigned int, unsigned int, signed int, _D3DFORMAT, int, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 108))(
             LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
             v7,
             D3DUsage,
             v6,
             D3DFormat,
             &v1->m_pDirect3DIndexBuffer,
             0);
      if ( !v8 )
      {
        GraphicsResource::SetResourceSize((GraphicsResource *)&v1->vfptr, v7);
        GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
        v9 = v1->m_StreamFrameID + 1;
        v1->m_NextRemoteIndex = 0;
        v1->m_StreamFrameID = v9;
        g_TotalIndexBufferRemoteBytes += v7;
        return 1;
      }
      if ( v8 != -2005532292 || !CanDiscardMoreMemory )
        break;
    }
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8F8B14: using guessed type __int32 g_TotalIndexBufferRemoteBytes;

//----- (00697CF0) --------------------------------------------------------  // acclient.c:687634
char __thiscall RenderIndexStreamD3D::PurgeResource(RenderIndexStreamD3D *this)
{
  RenderIndexStreamD3D *v1; // esi@1
  char result; // al@1
  IDirect3DIndexBuffer9 *v3; // eax@2
  int v4; // edx@3

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    v3 = v1->m_pDirect3DIndexBuffer;
    if ( v3 )
    {
      v3->vfptr->Release((IUnknown *)v1->m_pDirect3DIndexBuffer);
      v4 = v1->m_IndexSizeInBytes * v1->m_NumIndices;
      v1->m_pDirect3DIndexBuffer = 0;
      v1->m_WriteLockCount = 0;
      g_TotalIndexBufferRemoteBytes -= v4;
    }
    result = 1;
  }
  return result;
}
// 8F8B14: using guessed type __int32 g_TotalIndexBufferRemoteBytes;

//----- (00697D30) --------------------------------------------------------  // acclient.c:687661
bool __thiscall RenderIndexStreamD3D::RestoreResource(RenderIndexStreamD3D *this)
{
  return GraphicsResource::RestoreResource((GraphicsResource *)&this->vfptr) != 0;
}

//----- (00697D40) --------------------------------------------------------  // acclient.c:687667
IDirect3DIndexBuffer9 *__thiscall RenderIndexStreamD3D::GetDirect3DIndexBuffer(RenderIndexStreamD3D *this)
{
  RenderIndexStreamD3D *v1; // esi@1
  IDirect3DIndexBuffer9 *result; // eax@3
  int v3; // edx@4

  v1 = this;
  if ( !this->m_bIsLost || (unsigned __int8)((int (*)(void))this->vfptr->RestoreResource)() )
  {
    v3 = HIDWORD(Timer::local_time);
    LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
    HIDWORD(v1->m_TimeUsed) = v3;
    if ( RenderDevice::render_device )
      v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
    if ( !v1->m_pDirect3DIndexBuffer )
      RenderIndexStreamD3D::CreateDirect3DIndexBuffer(v1);
    result = v1->m_pDirect3DIndexBuffer;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00697D90) --------------------------------------------------------  // acclient.c:687693
char __thiscall RenderIndexStreamD3D::FillData(RenderIndexStreamD3D *this, const unsigned int _NumIndices, const void *_pSourceData, unsigned int *_FirstRemoteIndex)
{
  RenderIndexStreamD3D *v4; // ebp@1
  const unsigned int v5; // ebx@2
  signed int v6; // esi@2
  int v7; // eax@5
  unsigned int v8; // edx@7
  int v9; // ecx@8
  unsigned int v10; // edi@8
  bool v11; // al@10
  IDirect3DIndexBuffer9 *v12; // ebx@17
  char *v13; // eax@18
  char result; // al@21
  char *pD3DIndices; // [sp+14h] [bp-Ch]@12
  unsigned int v16; // [sp+18h] [bp-8h]@3
  IDirect3DIndexBuffer9 *pDirect3DIndexBuffer; // [sp+1Ch] [bp-4h]@1

  v4 = this;
  pDirect3DIndexBuffer = RenderIndexStreamD3D::GetDirect3DIndexBuffer(this);
  if ( !pDirect3DIndexBuffer )
    goto LABEL_25;
  v5 = v4->m_NumIndices;
  v6 = 2048;
  if ( _NumIndices > v5 )
    goto LABEL_25;
  v16 = v4->m_Flags & 1;
  if ( v16 )
  {
    if ( _NumIndices + v4->m_NextRemoteIndex > v5 )
    {
      v7 = v4->m_StreamFrameID + 1;
      v4->m_NextRemoteIndex = 0;
      v4->m_StreamFrameID = v7;
    }
    v6 = v4->m_NextRemoteIndex != 0 ? 6144 : 10240;
  }
  v8 = v4->m_NextRemoteIndex;
  if ( v8 + _NumIndices > v5 )
    goto LABEL_25;
  v9 = v8 * v4->m_IndexSizeInBytes;
  v10 = _NumIndices * v4->m_IndexSizeInBytes;
  v11 = !v9 && _NumIndices == v5;
  pD3DIndices = 0;
  if ( !v16 && v4->m_WriteLockCount >= 1 )
  {
    if ( v11 )
      v6 |= 0x2000u;
    else
      v6 |= 0x1000u;
  }
  v12 = pDirect3DIndexBuffer;
  pDirect3DIndexBuffer = (IDirect3DIndexBuffer9 *)pDirect3DIndexBuffer->vfptr;
  if ( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pDirect3DIndexBuffer[11].vfptr)(
         v12,
         v9,
         v11 != 0 ? 0 : v10,
         &pD3DIndices,
         v6) >= 0
    && (v13 = pD3DIndices) != 0 )
  {
    ++v4->m_WriteLockCount;
    qmemcpy(v13, _pSourceData, v10);
    ((void (__stdcall *)(IDirect3DIndexBuffer9 *))v12->vfptr[4].QueryInterface)(v12);
    *_FirstRemoteIndex = v4->m_NextRemoteIndex;
    if ( v4->m_Flags & 1 )
      v4->m_NextRemoteIndex += _NumIndices;
    result = 1;
  }
  else
  {
LABEL_25:
    result = 0;
  }
  return result;
}

//----- (00697ED0) --------------------------------------------------------  // acclient.c:687770
void __thiscall RenderIndexStreamD3D::NotifyFrameChanged(RenderIndexStreamD3D *this)
{
  unsigned int v1; // eax@1

  v1 = this->m_StreamFrameID + 1;
  this->m_NextRemoteIndex = 0;
  this->m_StreamFrameID = v1;
}

//----- (00697EE0) --------------------------------------------------------  // acclient.c:687780
RenderIndexStreamD3D *__thiscall RenderIndexStreamD3D::vector_deleting_destructor(RenderIndexStreamD3D *this, unsigned int a2)
{
  RenderIndexStreamD3D *v2; // esi@1
  IDirect3DIndexBuffer9 *v3; // eax@1
  int v4; // edx@2

  v2 = this;
  v3 = this->m_pDirect3DIndexBuffer;
  this->vfptr = (GraphicsResourceVtbl *)&RenderIndexStreamD3D::vftable;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v3);
    v4 = v2->m_IndexSizeInBytes * v2->m_NumIndices;
    v2->m_pDirect3DIndexBuffer = 0;
    v2->m_WriteLockCount = 0;
    g_TotalIndexBufferRemoteBytes -= v4;
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v2->vfptr);
  GraphicsResource::~GraphicsResource((GraphicsResource *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 8009D4: using guessed type int (__thiscall *RenderIndexStreamD3D::vftable)(void *, char);
// 8F8B14: using guessed type __int32 g_TotalIndexBufferRemoteBytes;

//----- (0071A310) --------------------------------------------------------  // acclient.c:812751
void sub_71A310()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8B24, PFID_A8R8G8B8);
}

