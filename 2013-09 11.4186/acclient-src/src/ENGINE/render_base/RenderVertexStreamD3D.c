/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderVertexStreamD3D
   Object     : ENGINE\render_base\RenderVertexStreamD3D.obj
   Functions  : 28
   Addresses  : 006976C0 - 007859C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006976C0) --------------------------------------------------------  // acclient.c:687215
void __thiscall RenderVertexStreamD3D::Begin(RenderVertexStreamD3D *this)
{
  this->m_pD3DVertexBuffer = 0;
  this->m_nNumVertices = 0;
  memset(&this->m_VertexFormatInfo, 0, sizeof(this->m_VertexFormatInfo));
  this->m_Flags = 0;
  this->m_nNextVertexIndex = 0;
  this->m_nIdealVertexCount = 0;
  this->m_nStreamFrameID = 0;
  this->m_WriteLockCount = 0;
}

//----- (00697700) --------------------------------------------------------  // acclient.c:687228
char __thiscall RenderVertexStreamD3D::Create(RenderVertexStreamD3D *this, const unsigned int _nNumVertices, const unsigned int _VertexFormat, const unsigned int _Flags)
{
  RenderVertexStreamD3D *v4; // esi@1
  VertexFormatInfo *v5; // ecx@2
  unsigned int v6; // ecx@2
  char result; // al@3

  v4 = this;
  if ( !_nNumVertices
    || (this->m_nNumVertices = _nNumVertices,
        v5 = &this->m_VertexFormatInfo,
        v5->format = _VertexFormat,
        VertexFormatInfo::GenerateOffsets(v5),
        v6 = v4->m_VertexFormatInfo.numMatrices,
        v4->m_Flags = _Flags,
        v6) )
  {
    result = 0;
  }
  else
  {
    GraphicsResource::SetResourceIsThrashable((GraphicsResource *)&v4->vfptr, ~(unsigned __int8)(_Flags >> 2) & 1);
    v4->m_nStreamFrameID = 0;
    result = 1;
  }
  return result;
}

//----- (00697760) --------------------------------------------------------  // acclient.c:687257
char __thiscall RenderVertexStreamD3D::CreateD3DVertexBuffer(RenderVertexStreamD3D *this)
{
  RenderVertexStreamD3D *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // edx@4
  bool v4; // cl@7
  unsigned int v5; // eax@9
  signed int v6; // ebx@9
  const unsigned int v7; // edi@14
  int v8; // eax@15
  char bCanDiscardMoreMemory; // [sp+1Dh] [bp-9h]@14
  unsigned int iD3DUsage; // [sp+1Eh] [bp-8h]@1
  unsigned int nFVFFlags; // [sp+22h] [bp-4h]@12

  v1 = this;
  v2 = this->m_Flags;
  iD3DUsage = 8;
  if ( v2 & 1 || !(v2 & 0x10) )
    iD3DUsage = 520;
  v3 = this->m_VertexFormatInfo.format;
  if ( v3 & 0x20 || v2 & 2 )
  {
    iD3DUsage |= 0x40u;
    this->m_Flags = v2 | 2;
  }
  v4 = RenderDevice::render_device->m_caps.bHardwareVertexProcessing;
  if ( !v4 )
    iD3DUsage |= 0x10u;
  v5 = v1->m_Flags;
  v6 = 0;
  if ( v5 & 4 || !v4 )
  {
    v6 = 2;
    v1->m_Flags = v5 | 4;
  }
  nFVFFlags = 0;
  if ( v1->m_VertexFormatInfo.bFVFCompatible )
    nFVFFlags = v3;
  v7 = v1->m_nNumVertices * v1->m_VertexFormatInfo.size;
  for ( bCanDiscardMoreMemory = 1; ; bCanDiscardMoreMemory = GraphicsResource::DiscardResourceBytes(v7) )
  {
    v8 = (*(int (__stdcall **)(_DWORD, const unsigned int, unsigned int, unsigned int, signed int, int, _DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24) + 104))(
           LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24),
           v7,
           iD3DUsage,
           nFVFFlags,
           v6,
           &v1->m_pD3DVertexBuffer,
           0);
    if ( !v8 )
    {
      GraphicsResource::SetResourceSize((GraphicsResource *)&v1->vfptr, v7);
      GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
      ++v1->m_nStreamFrameID;
      v1->m_nNextVertexIndex = 0;
      return 1;
    }
    if ( v8 != -2005532292 || !bCanDiscardMoreMemory )
      break;
  }
  return 0;
}

//----- (00697880) --------------------------------------------------------  // acclient.c:687321
IDirect3DVertexBuffer9 *__thiscall RenderVertexStreamD3D::GetD3DVertexBuffer(RenderVertexStreamD3D *this)
{
  RenderVertexStreamD3D *v1; // esi@1
  IDirect3DVertexBuffer9 *result; // eax@3
  int v3; // edx@4

  v1 = this;
  if ( !this->m_bIsLost || (unsigned __int8)((int (*)(void))this->vfptr->RestoreResource)() )
  {
    v3 = HIDWORD(Timer::local_time);
    LODWORD(v1->m_TimeUsed) = LODWORD(Timer::local_time);
    HIDWORD(v1->m_TimeUsed) = v3;
    if ( RenderDevice::render_device )
      v1->m_FrameUsed = RenderDevice::render_device->m_nFrameStamp;
    if ( !v1->m_pD3DVertexBuffer )
      RenderVertexStreamD3D::CreateD3DVertexBuffer(v1);
    result = v1->m_pD3DVertexBuffer;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006978D0) --------------------------------------------------------  // acclient.c:687347
char __thiscall RenderVertexStreamD3D::FillData(RenderVertexStreamD3D *this, const unsigned int _FirstVertex, const unsigned int _NumVertices, const void *_pSourceData, VertexFormatInfo *_SourceVFI, const bool _SwapYAndZ, unsigned int *_nBaseVertexIndex)
{
  RenderVertexStreamD3D *v7; // esi@1
  const unsigned int v8; // edi@2
  bool v9; // zf@2
  signed int v10; // edx@2
  const unsigned int v11; // eax@3
  int v12; // eax@5
  unsigned int v13; // ebp@8
  const unsigned int v14; // ebx@8
  int v15; // ecx@9
  bool v16; // al@11
  IDirect3DVertexBuffer9 *v17; // ebp@18
  char *v18; // ST08_4@20
  char *pD3DVertices; // [sp+14h] [bp-Ch]@13
  unsigned int v21; // [sp+18h] [bp-8h]@2
  IDirect3DVertexBuffer9 *pD3DVertexBuffer; // [sp+1Ch] [bp-4h]@1
  const unsigned int _NumVerticesa; // [sp+28h] [bp+8h]@9

  v7 = this;
  pD3DVertexBuffer = RenderVertexStreamD3D::GetD3DVertexBuffer(this);
  if ( !pD3DVertexBuffer )
    return 0;
  v8 = _NumVertices;
  v9 = (v7->m_Flags & 1) == 0;
  v10 = 2048;
  v21 = v7->m_Flags & 1;
  if ( v9 )
  {
    v7->m_nNextVertexIndex = _FirstVertex;
    goto LABEL_8;
  }
  v11 = v7->m_nNumVertices;
  v7->m_nIdealVertexCount += _NumVertices;
  if ( _NumVertices > v11 )
    return 0;
  if ( _NumVertices + v7->m_nNextVertexIndex > v11 )
  {
    v12 = v7->m_nStreamFrameID + 1;
    v7->m_nNextVertexIndex = 0;
    v7->m_nStreamFrameID = v12;
  }
  v10 = v7->m_nNextVertexIndex != 0 ? 6144 : 10240;
LABEL_8:
  v13 = v7->m_nNextVertexIndex;
  v14 = v7->m_nNumVertices;
  if ( _NumVertices + v13 > v14 )
    return 0;
  v15 = v13 * v7->m_VertexFormatInfo.size;
  _NumVerticesa = _NumVertices * v7->m_VertexFormatInfo.size;
  v16 = !v15 && v8 == v14;
  pD3DVertices = 0;
  if ( !v21 && v7->m_WriteLockCount >= 1 )
  {
    if ( v16 )
      v10 |= 0x2000u;
    else
      v10 |= 0x1000u;
  }
  v17 = pD3DVertexBuffer;
  if ( ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pD3DVertexBuffer->vfptr[3].Release)(
         pD3DVertexBuffer,
         v15,
         v16 != 0 ? 0 : _NumVerticesa,
         &pD3DVertices,
         v10) < 0
    || !pD3DVertices )
    return 0;
  v18 = pD3DVertices;
  ++v7->m_WriteLockCount;
  RenderVertexBuffer::TransferVertices(_pSourceData, _SourceVFI, v18, &v7->m_VertexFormatInfo, v8, _SwapYAndZ);
  ((void (__stdcall *)(IDirect3DVertexBuffer9 *))v17->vfptr[4].QueryInterface)(v17);
  *_nBaseVertexIndex = v7->m_nNextVertexIndex;
  if ( v7->m_Flags & 1 )
    v7->m_nNextVertexIndex += v8;
  return 1;
}

//----- (00697A50) --------------------------------------------------------  // acclient.c:687426
void __thiscall RenderVertexStreamD3D::ResetVertexIndices(RenderVertexStreamD3D *this)
{
  this->m_nNextVertexIndex = 0;
  this->m_nIdealVertexCount = 0;
  ++this->m_nStreamFrameID;
}

//----- (00697A70) --------------------------------------------------------  // acclient.c:687434
char __thiscall RenderVertexStreamD3D::PurgeResource(RenderVertexStreamD3D *this)
{
  RenderVertexStreamD3D *v1; // esi@1
  char result; // al@1
  IDirect3DVertexBuffer9 *v3; // eax@5

  v1 = this;
  result = DBObj::InitLoad();
  if ( result )
  {
    if ( v1->m_pD3DVertexBuffer )
    {
      if ( RenderDevice::render_device )
        RenderDeviceD3D::InvalidateCachedVertexBufferPointer(
          (RenderDeviceD3D *)RenderDevice::render_device,
          v1->m_pD3DVertexBuffer);
      v3 = v1->m_pD3DVertexBuffer;
      if ( v3 )
      {
        v3->vfptr->Release((IUnknown *)v1->m_pD3DVertexBuffer);
        v1->m_pD3DVertexBuffer = 0;
      }
      v1->m_WriteLockCount = 0;
    }
    result = 1;
  }
  return result;
}

//----- (00697AC0) --------------------------------------------------------  // acclient.c:687464
void __thiscall RenderVertexStreamD3D::End(RenderVertexStreamD3D *this)
{
  RenderVertexStreamD3D *v1; // esi@1
  IDirect3DVertexBuffer9 *v2; // eax@1
  IDirect3DVertexBuffer9 *v3; // eax@4

  v1 = this;
  v2 = this->m_pD3DVertexBuffer;
  if ( v2 )
  {
    if ( RenderDevice::render_device )
      RenderDeviceD3D::InvalidateCachedVertexBufferPointer((RenderDeviceD3D *)RenderDevice::render_device, v2);
    v3 = v1->m_pD3DVertexBuffer;
    if ( v3 )
    {
      v3->vfptr->Release((IUnknown *)v1->m_pD3DVertexBuffer);
      v1->m_pD3DVertexBuffer = 0;
    }
    v1->m_WriteLockCount = 0;
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
}

//----- (00697B00) --------------------------------------------------------  // acclient.c:687488
void __thiscall RenderVertexStreamD3D::Destroy(RenderVertexStreamD3D *this)
{
  RenderVertexStreamD3D *v1; // esi@1
  IDirect3DVertexBuffer9 *v2; // eax@1
  IDirect3DVertexBuffer9 *v3; // eax@4

  v1 = this;
  v2 = this->m_pD3DVertexBuffer;
  if ( v2 )
  {
    if ( RenderDevice::render_device )
      RenderDeviceD3D::InvalidateCachedVertexBufferPointer((RenderDeviceD3D *)RenderDevice::render_device, v2);
    v3 = v1->m_pD3DVertexBuffer;
    if ( v3 )
    {
      v3->vfptr->Release((IUnknown *)v1->m_pD3DVertexBuffer);
      v1->m_pD3DVertexBuffer = 0;
    }
    v1->m_WriteLockCount = 0;
  }
  GraphicsResource::MarkResourceAsNotLost((GraphicsResource *)&v1->vfptr);
  v1->m_pD3DVertexBuffer = 0;
  v1->m_nNumVertices = 0;
  memset(&v1->m_VertexFormatInfo, 0, sizeof(v1->m_VertexFormatInfo));
  v1->m_Flags = 0;
  v1->m_nNextVertexIndex = 0;
  v1->m_nIdealVertexCount = 0;
  v1->m_nStreamFrameID = 0;
  v1->m_WriteLockCount = 0;
}

//----- (0071A1E0) --------------------------------------------------------  // acclient.c:812682
void sub_71A1E0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F8AB8, PFID_A8R8G8B8);
}

//----- (0071A1F0) --------------------------------------------------------  // acclient.c:812688
int sub_71A1F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_80, "None");
  return atexit(_E92_52);
}

//----- (0071A210) --------------------------------------------------------  // acclient.c:812695
int _E94_43()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_80, "Speed");
  return atexit(sub_785870);
}

//----- (0071A230) --------------------------------------------------------  // acclient.c:812702
int sub_71A230()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_80, "Noise");
  return atexit(sub_7858A0);
}

//----- (0071A250) --------------------------------------------------------  // acclient.c:812709
int sub_71A250()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_80, "Sine");
  return atexit(sub_7858D0);
}

//----- (0071A270) --------------------------------------------------------  // acclient.c:812716
int sub_71A270()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_80, "Square");
  return atexit(sub_785900);
}

//----- (0071A290) --------------------------------------------------------  // acclient.c:812723
int sub_71A290()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_80, "Bounce");
  return atexit(sub_785930);
}

//----- (0071A2B0) --------------------------------------------------------  // acclient.c:812730
int _E109_92()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_80, "Perlin");
  return atexit(sub_785960);
}

//----- (0071A2D0) --------------------------------------------------------  // acclient.c:812737
int sub_71A2D0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_80, "Fractal");
  return atexit(_E113_77);
}

//----- (0071A2F0) --------------------------------------------------------  // acclient.c:812744
int _E115_96()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_80, "FrameLoop");
  return atexit(_E116_69);
}

//----- (00785840) --------------------------------------------------------  // acclient.c:924805
void __cdecl _E92_52()
{
  char *v0; // esi@1

  v0 = &waveform_None_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785870) --------------------------------------------------------  // acclient.c:924818
void __cdecl sub_785870()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007858A0) --------------------------------------------------------  // acclient.c:924831
void __cdecl sub_7858A0()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007858D0) --------------------------------------------------------  // acclient.c:924844
void __cdecl sub_7858D0()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785900) --------------------------------------------------------  // acclient.c:924857
void __cdecl sub_785900()
{
  char *v0; // esi@1

  v0 = &waveform_Square_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785930) --------------------------------------------------------  // acclient.c:924870
void __cdecl sub_785930()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785960) --------------------------------------------------------  // acclient.c:924883
void __cdecl sub_785960()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00785990) --------------------------------------------------------  // acclient.c:924896
void __cdecl _E113_77()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007859C0) --------------------------------------------------------  // acclient.c:924909
void __cdecl _E116_69()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_80.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_80.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

