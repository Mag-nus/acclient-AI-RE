/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : RenderAllocator
   Object     : PORTAL\renderalloc\RenderAllocator.obj
   Functions  : 79
   Addresses  : 005862C0 - 00774940 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005862C0) --------------------------------------------------------  // acclient.c:431105
void __thiscall IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *this)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v5; // edi@5
  void *v6; // ecx@5
  void *v7; // eax@7
  void *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned long,RenderVertexStreamD3D *> **)v2 )
    {
LABEL_5:
      v5 = 0;
      v6 = 0;
    }
    else
    {
      while ( 1 )
      {
        v3 = v1->m_firstInterestingBucket;
        if ( *v3 )
          break;
        v4 = (int)(v3 + 1);
        v1->m_firstInterestingBucket = (HashTableData<unsigned long,RenderVertexStreamD3D *> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_17;
    do
    {
      v8 = v7;
      v7 = (void *)*((_DWORD *)v7 + 1);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 1) = *((_DWORD *)v7 + 1);
    else
LABEL_17:
      *v5 = (HashTableData<unsigned long,RenderVertexStreamD3D *> *)*((_DWORD *)v7 + 1);
    --v1->m_numElements;
    if ( v6 )
      operator delete(v6);
  }
}

//----- (0058AEC0) --------------------------------------------------------  // acclient.c:435613
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v2; // esi@1
  HashTableData<unsigned long,RenderVertexStreamD3D *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E32FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable[2])(void *, char);

//----- (0058AF00) --------------------------------------------------------  // acclient.c:435634
double __stdcall Render::GetFogAdjustment(float fog_distance)
{
  return fog_distance;
}

//----- (0058AF10) --------------------------------------------------------  // acclient.c:435640
Render *__thiscall Render::vector_deleting_destructor(Render *this, unsigned int a2)
{
  Render *v2; // esi@1

  v2 = this;
  this->vfptr = (RenderVtbl *)&Render::vftable;
  Render::End(this);
  if ( (v2->m_DisplayModes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_DisplayModes.m_data);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E3300: using guessed type int (__thiscall *Render::vftable)(void *, char);

//----- (0058AF50) --------------------------------------------------------  // acclient.c:435656
RenderDevice::GraphicsStatesType *__thiscall PrimD3DRender::GetObjectMatrixInternal(PrimD3DRender *this)
{
  ((void (*)(void))this->vfptr->CalcObjectMatrixInternal)();
  return &RenderDevice::render_device->m_GState;
}

//----- (0058AF60) --------------------------------------------------------  // acclient.c:435663
void __thiscall PrimD3DRender::~PrimD3DRender(PrimD3DRender *this)
{
  PrimD3DRender *v1; // esi@1

  v1 = this;
  this->vfptr = (RenderVtbl *)&Render::vftable;
  Render::End((Render *)&this->vfptr);
  if ( (v1->m_DisplayModes.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_DisplayModes.m_data);
}
// 7E3300: using guessed type int (__thiscall *Render::vftable)(void *, char);

//----- (0058AF90) --------------------------------------------------------  // acclient.c:435676
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,RenderVertexStreamD3D *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,RenderVertexStreamD3D *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7E32FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable[2])(void *, char);

//----- (0058B020) --------------------------------------------------------  // acclient.c:435709
void __thiscall HashTable<unsigned long,RenderVertexStreamD3D *,0>::~HashTable<unsigned long,RenderVertexStreamD3D *,0>(HashTable<unsigned long,RenderVertexStreamD3D *,0> *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,RenderVertexStreamD3D *,0>Vtbl *)&HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 7E32FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable[2])(void *, char);
// 7E3348: using guessed type int (__thiscall *HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable)(void *, char);

//----- (0058B060) --------------------------------------------------------  // acclient.c:435730
HashTable<unsigned long,RenderVertexStreamD3D *,0> *__thiscall HashTable<unsigned long,RenderVertexStreamD3D *,0>::scalar_deleting_destructor(HashTable<unsigned long,RenderVertexStreamD3D *,0> *this, unsigned int a2)
{
  HashTable<unsigned long,RenderVertexStreamD3D *,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,RenderVertexStreamD3D *,0>Vtbl *)&HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E32FC: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable[2])(void *, char);
// 7E3348: using guessed type int (__thiscall *HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable)(void *, char);

//----- (0058B0C0) --------------------------------------------------------  // acclient.c:435756
D3DPolyRender *__thiscall D3DPolyRender::scalar_deleting_destructor(D3DPolyRender *this, unsigned int a2)
{
  D3DPolyRender *v2; // esi@1

  v2 = this;
  this->vfptr = (RenderVtbl *)&D3DPolyRender::vftable;
  D3DPolyRender::End(this);
  HashTable<unsigned long,RenderVertexStreamD3D *,0>::~HashTable<unsigned long,RenderVertexStreamD3D *,0>(&v2->m_DynamicVertexStreamHash);
  PrimD3DRender::~PrimD3DRender((PrimD3DRender *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7E3350: using guessed type int (__thiscall *D3DPolyRender::vftable)(void *, char);

//----- (0058B100) --------------------------------------------------------  // acclient.c:435772
Render *__cdecl RenderAllocator::AllocateRender()
{
  void *v0; // esi@1
  Render *result; // eax@1

  v0 = operator new(0x9Cu);
  result = 0;
  if ( v0 )
  {
    *(_DWORD *)v0 = &Render::vftable;
    *((_DWORD *)v0 + 1) = 1;
    *((_DWORD *)v0 + 3) = 0;
    *((_DWORD *)v0 + 4) = 0;
    *((_DWORD *)v0 + 5) = 0;
    Render::Begin((Render *)v0);
    *(_DWORD *)v0 = &D3DPolyRender::vftable;
    *((_DWORD *)v0 + 8) = &HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)((char *)v0 + 36),
      0x17u);
    D3DPolyRender::Begin((D3DPolyRender *)v0);
    result = (Render *)v0;
  }
  return result;
}
// 7E3300: using guessed type int (__thiscall *Render::vftable)(void *, char);
// 7E3348: using guessed type int (__thiscall *HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable)(void *, char);
// 7E3350: using guessed type int (__thiscall *D3DPolyRender::vftable)(void *, char);

//----- (0070A090) --------------------------------------------------------  // acclient.c:797312
void sub_70A090()
{
  PixelFormatDesc::PixelFormatDesc(&stru_870CA0, PFID_A8R8G8B8);
}

//----- (0070A0A0) --------------------------------------------------------  // acclient.c:797318
void sub_70A0A0()
{
  LODWORD(dword_870CD8) = 1053364187;
}

//----- (0070A0B0) --------------------------------------------------------  // acclient.c:797324
void sub_70A0B0()
{
  flt_870CDC = 1000.0 + 1.0;
}

//----- (0070A0D0) --------------------------------------------------------  // acclient.c:797330
void sub_70A0D0()
{
  flt_870CE0 = 24.0 * 8.0;
}

//----- (0070A0F0) --------------------------------------------------------  // acclient.c:797336
void sub_70A0F0()
{
  flt_870CE4 = 24.0 * 0.5;
}

//----- (0070A110) --------------------------------------------------------  // acclient.c:797342
int _E99_39()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_36, "Render.TextureFiltering");
  return atexit(sub_774340);
}

//----- (0070A130) --------------------------------------------------------  // acclient.c:797349
int _E102_34()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_36, "Render.LandscapeDetailTextures");
  return atexit(sub_774370);
}

//----- (0070A150) --------------------------------------------------------  // acclient.c:797356
int _E105_49()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_36, "Render.BuildingDetailTextures");
  return atexit(sub_7743A0);
}

//----- (0070A170) --------------------------------------------------------  // acclient.c:797363
int _E108_96()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_36, "Render.FieldOfView");
  return atexit(sub_7743D0);
}

//----- (0070A190) --------------------------------------------------------  // acclient.c:797370
int _E111_51()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_36, "Render.LandscapeTextureDetail");
  return atexit(sub_774400);
}

//----- (0070A1B0) --------------------------------------------------------  // acclient.c:797377
int _E114_61()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_36, "Render.EnvironmentTextureDetail");
  return atexit(sub_774430);
}

//----- (0070A1D0) --------------------------------------------------------  // acclient.c:797384
int _E117_75()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_36, "Render.SceneryDrawDistance");
  return atexit(sub_774460);
}

//----- (0070A1F0) --------------------------------------------------------  // acclient.c:797391
int _E120_70()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_36, "Render.LandscapeDrawDistance");
  return atexit(sub_774490);
}

//----- (0070A210) --------------------------------------------------------  // acclient.c:797398
int _E123_42()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_36, "Render.ScreenBrightness");
  return atexit(sub_7744C0);
}

//----- (0070A230) --------------------------------------------------------  // acclient.c:797405
int _E126_49()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_36, "Render.AspectRatio");
  return atexit(sub_7744F0);
}

//----- (0070A250) --------------------------------------------------------  // acclient.c:797412
int _E129_43()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_36, "Render.DisplayAdapter");
  return atexit(sub_774520);
}

//----- (0070A270) --------------------------------------------------------  // acclient.c:797419
int _E132_43()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_36, "Render.MaxHardwareClass");
  return atexit(sub_774550);
}

//----- (0070A290) --------------------------------------------------------  // acclient.c:797426
int _E135_50()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_36, "Render.AutomaticDegrades");
  return atexit(_E136_85);
}

//----- (0070A2B0) --------------------------------------------------------  // acclient.c:797433
int _E138_38()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_36, "Render.GraphicsPerformance");
  return atexit(_E139_85);
}

//----- (0070A2D0) --------------------------------------------------------  // acclient.c:797440
int _E141_40()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_36, "Render.DegradeDistance");
  return atexit(_E142_80);
}

//----- (0070A2F0) --------------------------------------------------------  // acclient.c:797447
int _E144_37()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_36, "Render.MultiPassAlpha");
  return atexit(_E145_82);
}

//----- (0070A310) --------------------------------------------------------  // acclient.c:797454
int _E147_36()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_36, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_870D30, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_870D34, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_870D38, "Anisotropic");
  return atexit(_E148_78);
}

//----- (0070A360) --------------------------------------------------------  // acclient.c:797464
int _E150_35()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_36, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_870D40, "Low");
  PStringBase<char>::PStringBase<char>(&stru_870D44, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_870D48, "High");
  PStringBase<char>::PStringBase<char>(&stru_870D4C, "VeryHigh");
  return atexit(_E151_76);
}

//----- (0070A3C0) --------------------------------------------------------  // acclient.c:797475
int _E153_33()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_36, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_870D54, "Low");
  PStringBase<char>::PStringBase<char>(&stru_870D58, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_870D5C, "High");
  PStringBase<char>::PStringBase<char>(&stru_870D60, "VeryHigh");
  return atexit(_E154_77);
}

//----- (0070A420) --------------------------------------------------------  // acclient.c:797486
int _E156_35()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_36, "Low");
  PStringBase<char>::PStringBase<char>(&stru_870D68, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_870D6C, "High");
  return atexit(_E157_73);
}

//----- (0070A460) --------------------------------------------------------  // acclient.c:797495
int _E159_33()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_36, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_870D74, "Low");
  PStringBase<char>::PStringBase<char>(&stru_870D78, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_870D7C, "High");
  PStringBase<char>::PStringBase<char>(&stru_870D80, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_870D84, "Extreme");
  return atexit(_E160_76);
}

//----- (0070A4D0) --------------------------------------------------------  // acclient.c:797507
int _E162_36()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_36, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_870D8C, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_870D90, "Wide");
  return atexit(_E163_69);
}

//----- (0070A510) --------------------------------------------------------  // acclient.c:797516
int _E165_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_63, "None");
  return atexit(_E166_71);
}

//----- (0070A530) --------------------------------------------------------  // acclient.c:797523
int _E168_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_63, "Speed");
  return atexit(_E169_70);
}

//----- (0070A550) --------------------------------------------------------  // acclient.c:797530
int _E171_31()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_63, "Noise");
  return atexit(_E172_68);
}

//----- (0070A570) --------------------------------------------------------  // acclient.c:797537
int _E174_33()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_63, "Sine");
  return atexit(_E175_65);
}

//----- (0070A590) --------------------------------------------------------  // acclient.c:797544
int _E177_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_63, "Square");
  return atexit(_E178_65);
}

//----- (0070A5B0) --------------------------------------------------------  // acclient.c:797551
int _E180_30()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_63, "Bounce");
  return atexit(_E181_65);
}

//----- (0070A5D0) --------------------------------------------------------  // acclient.c:797558
int _E183_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_63, "Perlin");
  return atexit(_E184_62);
}

//----- (0070A5F0) --------------------------------------------------------  // acclient.c:797565
int _E186_29()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_63, "Fractal");
  return atexit(_E187_61);
}

//----- (0070A610) --------------------------------------------------------  // acclient.c:797572
int _E189_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_63, "FrameLoop");
  return atexit(_E190_62);
}

//----- (0070A630) --------------------------------------------------------  // acclient.c:797579
int sub_70A630()
{
  return atexit(nullsub_1404);
}

//----- (00774340) --------------------------------------------------------  // acclient.c:907740
void __cdecl sub_774340()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774370) --------------------------------------------------------  // acclient.c:907753
void __cdecl sub_774370()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007743A0) --------------------------------------------------------  // acclient.c:907766
void __cdecl sub_7743A0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007743D0) --------------------------------------------------------  // acclient.c:907779
void __cdecl sub_7743D0()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774400) --------------------------------------------------------  // acclient.c:907792
void __cdecl sub_774400()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774430) --------------------------------------------------------  // acclient.c:907805
void __cdecl sub_774430()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774460) --------------------------------------------------------  // acclient.c:907818
void __cdecl sub_774460()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774490) --------------------------------------------------------  // acclient.c:907831
void __cdecl sub_774490()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007744C0) --------------------------------------------------------  // acclient.c:907844
void __cdecl sub_7744C0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007744F0) --------------------------------------------------------  // acclient.c:907857
void __cdecl sub_7744F0()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774520) --------------------------------------------------------  // acclient.c:907870
void __cdecl sub_774520()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774550) --------------------------------------------------------  // acclient.c:907883
void __cdecl sub_774550()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774580) --------------------------------------------------------  // acclient.c:907896
void __cdecl _E136_85()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007745B0) --------------------------------------------------------  // acclient.c:907909
void __cdecl _E139_85()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007745E0) --------------------------------------------------------  // acclient.c:907922
void __cdecl _E142_80()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774610) --------------------------------------------------------  // acclient.c:907935
void __cdecl _E145_82()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_36.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_36.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774640) --------------------------------------------------------  // acclient.c:907948
void __cdecl _E148_78()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_36;
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

//----- (00774680) --------------------------------------------------------  // acclient.c:907973
void __cdecl _E151_76()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_36;
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

//----- (007746C0) --------------------------------------------------------  // acclient.c:907998
void __cdecl _E154_77()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_36;
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

//----- (00774700) --------------------------------------------------------  // acclient.c:908023
void __cdecl _E157_73()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_36;
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

//----- (00774740) --------------------------------------------------------  // acclient.c:908048
void __cdecl _E160_76()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_36;
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

//----- (00774780) --------------------------------------------------------  // acclient.c:908073
void __cdecl _E163_69()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_63;
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

//----- (007747C0) --------------------------------------------------------  // acclient.c:908098
void __cdecl _E166_71()
{
  char *v0; // esi@1

  v0 = &waveform_None_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007747F0) --------------------------------------------------------  // acclient.c:908111
void __cdecl _E169_70()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774820) --------------------------------------------------------  // acclient.c:908124
void __cdecl _E172_68()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774850) --------------------------------------------------------  // acclient.c:908137
void __cdecl _E175_65()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774880) --------------------------------------------------------  // acclient.c:908150
void __cdecl _E178_65()
{
  char *v0; // esi@1

  v0 = &waveform_Square_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007748B0) --------------------------------------------------------  // acclient.c:908163
void __cdecl _E181_65()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007748E0) --------------------------------------------------------  // acclient.c:908176
void __cdecl _E184_62()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774910) --------------------------------------------------------  // acclient.c:908189
void __cdecl _E187_61()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00774940) --------------------------------------------------------  // acclient.c:908202
void __cdecl _E190_62()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_63.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_63.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

