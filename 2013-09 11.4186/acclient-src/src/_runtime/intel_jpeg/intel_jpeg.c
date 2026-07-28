/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : intel_jpeg
   Object     : _runtime\intel_jpeg\intel_jpeg.obj
   Functions  : 64
   Addresses  : 00614C60 - 0064C230 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00614C60) --------------------------------------------------------  // acclient.c:569019
int __stdcall ijlInit(int a1)
{
  void *v1; // eax@1
  int v2; // eax@3
  int v3; // eax@3
  int v4; // edx@3
  void *v5; // eax@3
  int v6; // edx@3
  int v7; // esi@5
  signed int v8; // eax@5
  int v9; // esi@5
  int v11; // [sp+0h] [bp-40h]@1
  struct _IJL_CONTEXT *v12; // [sp+4h] [bp-3Ch]@1
  int v13; // [sp+8h] [bp-38h]@1
  int v14; // [sp+Ch] [bp-34h]@3
  int v15; // [sp+10h] [bp-30h]@3
  int v16; // [sp+14h] [bp-2Ch]@3
  int v17; // [sp+18h] [bp-28h]@3
  CPPEH_RECORD ms_exc; // [sp+28h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v11;
  v11 = 0;
  v12 = 0;
  ms_exc.registration.TryLevel = 0;
  v13 = a1 + 88;
  v1 = operator new(0x114u);
  v12 = (struct _IJL_CONTEXT *)v1;
  if ( v1 )
  {
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    *((_DWORD *)v1 + 5) = 0;
    *(_DWORD *)(v13 + 14320) = v1;
    ownInitializeLibrary((struct _IJL_CONTEXT *)v1);
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
    *(_DWORD *)(a1 + 16) = 0;
    *(_DWORD *)(a1 + 20) = 3;
    *(_DWORD *)(a1 + 24) = 2;
    *(_DWORD *)(a1 + 28) = 0;
    *(_DWORD *)(a1 + 36) = 0;
    *(_DWORD *)(a1 + 32) = 0;
    *(_DWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 44) = 0;
    *(_DWORD *)(a1 + 48) = 0;
    *(_DWORD *)(a1 + 52) = 3;
    *(_DWORD *)(a1 + 56) = 3;
    *(_DWORD *)(a1 + 60) = 1;
    *(_DWORD *)(a1 + 64) = 0;
    *(_DWORD *)(a1 + 68) = 0;
    *(_DWORD *)(a1 + 72) = 1;
    *(_DWORD *)(a1 + 76) = 1;
    *(_DWORD *)(a1 + 80) = 75;
    v2 = v13;
    *(_DWORD *)(v13 + 116) = 0;
    *(_DWORD *)(v2 + 24) = 0;
    *(_DWORD *)(v2 + 28) = 0;
    *(_DWORD *)v2 = -1;
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)(v2 + 8) = 0;
    *(_DWORD *)(v2 + 12) = 0;
    *(_DWORD *)(v2 + 16) = 0;
    *(_DWORD *)(v2 + 20) = 1;
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(v2 + 36) = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(v2 + 40) = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(v2 + 44) = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(v2 + 48) = *(_DWORD *)(a1 + 20);
    *(_DWORD *)(v2 + 52) = *(_DWORD *)(a1 + 24);
    *(_DWORD *)(v2 + 56) = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(v2 + 60) = 0;
    *(_DWORD *)(v2 + 68) = *(_DWORD *)(a1 + 36);
    *(_DWORD *)(v2 + 64) = *(_DWORD *)(a1 + 32);
    *(_DWORD *)(v2 + 72) = *(_DWORD *)(a1 + 40);
    *(_DWORD *)(v2 + 76) = *(_DWORD *)(a1 + 44);
    *(_DWORD *)(v2 + 80) = *(_DWORD *)(a1 + 48);
    *(_DWORD *)(v2 + 84) = *(_DWORD *)(a1 + 52);
    *(_DWORD *)(v2 + 88) = *(_DWORD *)(a1 + 56);
    *(_DWORD *)(v2 + 92) = *(_DWORD *)(a1 + 60);
    *(_DWORD *)(v2 + 96) = *(_DWORD *)(a1 + 64);
    *(_DWORD *)(v2 + 100) = *(_DWORD *)(a1 + 68);
    *(_DWORD *)(v2 + 104) = *(_DWORD *)(a1 + 72);
    *(_DWORD *)(v2 + 108) = *(_DWORD *)(a1 + 76);
    *(_DWORD *)(v2 + 112) = *(_DWORD *)(a1 + 80);
    *(_DWORD *)(v2 + 120) = 0;
    *(_DWORD *)(v2 + 124) = 0;
    *(_DWORD *)(v2 + 14100) = 0;
    *(_DWORD *)(v2 + 14104) = 0;
    *(_DWORD *)(v2 + 14052) = 0;
    *(_DWORD *)(v2 + 14056) = 0;
    *(_DWORD *)(v2 + 14060) = 0;
    *(_DWORD *)(v2 + 14064) = 0;
    *(_DWORD *)(v2 + 14068) = 0;
    *(_DWORD *)(v2 + 14072) = 0;
    *(_DWORD *)(v2 + 14076) = 0;
    *(_DWORD *)(v2 + 14080) = 0;
    *(_DWORD *)(v2 + 14084) = 0;
    *(_DWORD *)(v2 + 14088) = 0;
    *(_DWORD *)(v2 + 14092) = 0;
    *(_DWORD *)(v2 + 14096) = 0;
    __g_memzero((void *)(v2 + 148), 0xB4u);
    __g_memzero((void *)(v13 + 328), 0xB4u);
    __g_memzero((void *)(v13 + 508), 0xB4u);
    __g_memzero((void *)(v13 + 688), 0xB4u);
    v3 = v13;
    v14 = v13 + 160;
    v15 = v13 + 340;
    v16 = v13 + 520;
    v17 = v13 + 700;
    *(_DWORD *)(v13 + 156) = (v13 + 167) & 0xFFFFFFF8;
    *(_DWORD *)(v3 + 336) = (v3 + 347) & 0xFFFFFFF8;
    *(_DWORD *)(v3 + 516) = (v3 + 527) & 0xFFFFFFF8;
    *(_DWORD *)(v3 + 696) = (v3 + 707) & 0xFFFFFFF8;
    __g_memzero((void *)(v3 + 7460), 0x670u);
    __g_memzero((void *)(v13 + 9108), 0x670u);
    __g_memzero((void *)(v13 + 10756), 0x670u);
    __g_memzero((void *)(v13 + 12404), 0x670u);
    __g_memzero((void *)(v13 + 868), 0x670u);
    __g_memzero((void *)(v13 + 2516), 0x670u);
    __g_memzero((void *)(v13 + 4164), 0x670u);
    __g_memzero((void *)(v13 + 5812), 0x670u);
    v4 = v13;
    *(_DWORD *)(v13 + 14300) = 1;
    *(_DWORD *)(v4 + 14244) = 0;
    *(_DWORD *)(v4 + 14248) = 0;
    *(_DWORD *)(v4 + 14252) = 0;
    *(_DWORD *)(v4 + 14256) = 0;
    *(_DWORD *)(v4 + 14260) = 0;
    *(_DWORD *)(v4 + 14264) = 0;
    *(_DWORD *)(v4 + 14268) = 0;
    *(_DWORD *)(v4 + 14272) = 4;
    *(_DWORD *)(v4 + 14276) = 0;
    *(_DWORD *)(v4 + 14280) = 0;
    v5 = operator new(0x40u);
    v6 = v13;
    *(_DWORD *)(v13 + 14284) = v5;
    if ( v5 )
    {
      __g_memzero(v5, 16 * *(_DWORD *)(v6 + 14272));
      v7 = v13;
      *(_DWORD *)(v13 + 14288) = 0;
      *(_DWORD *)(v7 + 14292) = 0;
      *(_DWORD *)(v7 + 14296) = 0;
      *(_DWORD *)(v7 + 18472) = 0;
      *(_DWORD *)(v7 + 18476) = 0;
      *(_DWORD *)(v7 + 14304) = 0;
      *(_DWORD *)(v7 + 18480) = 0;
      *(_DWORD *)(v7 + 14108) = 0;
      *(_BYTE *)(v7 + 14112) = 0;
      *(_DWORD *)(v7 + 14116) = 0;
      *(_BYTE *)(v7 + 14120) = 0;
      *(_DWORD *)(v7 + 14124) = 0;
      *(_BYTE *)(v7 + 14128) = 0;
      *(_DWORD *)(v7 + 14132) = 0;
      *(_BYTE *)(v7 + 14136) = 0;
      *(_DWORD *)(v7 + 14140) = 0;
      *(_DWORD *)(v7 + 14144) = 0;
      *(_BYTE *)(v7 + 14148) = 0;
      *(_BYTE *)(v7 + 14149) = 0;
      *(_DWORD *)(v7 + 14152) = 0;
      *(_DWORD *)(v7 + 14156) = 0;
      *(_BYTE *)(v7 + 14160) = 0;
      *(_BYTE *)(v7 + 14161) = 0;
      *(_DWORD *)(v7 + 14164) = 0;
      *(_DWORD *)(v7 + 14168) = 0;
      *(_BYTE *)(v7 + 14172) = 0;
      *(_BYTE *)(v7 + 14173) = 0;
      *(_DWORD *)(v7 + 14176) = 0;
      *(_DWORD *)(v7 + 14180) = 0;
      *(_BYTE *)(v7 + 14184) = 0;
      *(_BYTE *)(v7 + 14185) = 0;
      *(_DWORD *)(v7 + 14188) = 0;
      *(_DWORD *)(v7 + 14192) = 0;
      *(_BYTE *)(v7 + 14196) = 0;
      *(_BYTE *)(v7 + 14197) = 0;
      *(_DWORD *)(v7 + 14200) = 0;
      *(_DWORD *)(v7 + 14204) = 0;
      *(_BYTE *)(v7 + 14208) = 0;
      *(_BYTE *)(v7 + 14209) = 0;
      *(_DWORD *)(v7 + 14212) = 0;
      *(_DWORD *)(v7 + 14216) = 0;
      *(_BYTE *)(v7 + 14220) = 0;
      *(_BYTE *)(v7 + 14221) = 0;
      *(_DWORD *)(v7 + 14224) = 0;
      *(_DWORD *)(v7 + 14228) = 0;
      *(_BYTE *)(v7 + 14232) = 0;
      *(_BYTE *)(v7 + 14233) = 0;
      *(_DWORD *)(v7 + 136) = 0;
      *(_DWORD *)(v7 + 140) = 0;
      *(_DWORD *)(v7 + 144) = 0;
      *(_DWORD *)(v7 + 132) = 0;
      *(_DWORD *)(v7 + 128) = 0;
      *(_BYTE *)(v7 + 14236) = 0;
      *(_BYTE *)(v7 + 14240) = 0;
      *(_BYTE *)(v7 + 14237) = 1;
      *(_BYTE *)(v7 + 14241) = 1;
      *(_BYTE *)(v7 + 14238) = 1;
      *(_BYTE *)(v7 + 14242) = 1;
      *(_BYTE *)(v7 + 14239) = 1;
      *(_BYTE *)(v7 + 14243) = 1;
      *(_DWORD *)(*(_DWORD *)(v7 + 14284) + 12) = 0;
      *(_DWORD *)(*(_DWORD *)(v7 + 14284) + 28) = 1;
      *(_DWORD *)(*(_DWORD *)(v7 + 14284) + 44) = 1;
      *(_DWORD *)(*(_DWORD *)(v7 + 14284) + 60) = 1;
      *(_DWORD *)(v7 + 14372) = 0;
      *(_DWORD *)(v7 + 14328) = 0;
      *(_DWORD *)(v7 + 14332) = 0;
      *(_DWORD *)(v7 + 14336) = 0;
      *(_DWORD *)(v7 + 14340) = 0;
      *(_DWORD *)(v7 + 14356) = 0;
      *(_DWORD *)(v7 + 14348) = 0;
      *(_DWORD *)(v7 + 14352) = 0;
      v8 = ownGetProcessorType(v12);
      v9 = v13;
      *(_DWORD *)(v13 + 14364) = v8;
      *(_DWORD *)(v9 + 14324) = 0;
      *(_DWORD *)(v9 + 14344) = 0;
      *(_DWORD *)(v9 + 14312) = 0;
      *(_DWORD *)(v9 + 14316) = 0;
      *(_BYTE *)(v9 + 14360) = 0;
      *(_DWORD *)(v9 + 14368) = 0;
      *(_DWORD *)(v9 + 18484) = 0;
      *(_DWORD *)(v9 + 19928) = v8;
      *(_DWORD *)(v9 + 19932) = 0;
      *(_DWORD *)(v9 + 19936) = 0;
      *(_DWORD *)(v9 + 19940) = 0;
      *(_DWORD *)(v9 + 19944) = 0;
      *(_DWORD *)(v9 + 19948) = 0;
      *(_WORD *)(v9 + 19952) = 100;
      *(_WORD *)(v9 + 19954) = 0;
      *(_WORD *)(v9 + 19956) = 0;
      *(_DWORD *)(v9 + 19960) = 0;
      *(_WORD *)(v9 + 19964) = 257;
      *(_BYTE *)(v9 + 19966) = 0;
      *(_WORD *)(v9 + 19968) = 1;
      *(_WORD *)(v9 + 19970) = 1;
      *(_DWORD *)(v9 + 19972) = 0;
      *(_WORD *)(v9 + 19976) = 0;
      ms_exc.registration.TryLevel = -1;
    }
    else
    {
      v11 = -5;
    }
  }
  else
  {
    v11 = -5;
  }
  if ( v11 < 0 )
  {
    if ( *(_DWORD *)(a1 + 14372) )
    {
      operator delete(*(void **)(a1 + 14372));
      *(_DWORD *)(a1 + 14372) = 0;
      *(_DWORD *)(a1 + 14360) = 0;
    }
    if ( *(_DWORD *)(a1 + 20028) )
    {
      operator delete(*(void **)(a1 + 20028));
      *(_DWORD *)(a1 + 20028) = 0;
    }
    if ( *(_DWORD *)(a1 + 18568) )
    {
      operator delete(*(void **)(a1 + 18568));
      *(_DWORD *)(a1 + 18568) = 0;
    }
    if ( *(_DWORD *)(a1 + 14392) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(a1 + 14392) + 52) )
      {
        operator delete(*(void **)(*(_DWORD *)(a1 + 14392) + 52));
        *(_DWORD *)(*(_DWORD *)(a1 + 14392) + 52) = 0;
      }
      operator delete(*(void **)(a1 + 14392));
      *(_DWORD *)(a1 + 14392) = 0;
    }
  }
  return v11;
}
// 8F75A4: using guessed type void (__cdecl *__g_memzero)(void *, unsigned int);

//----- (006153F0) --------------------------------------------------------  // acclient.c:569306
int __stdcall ijlFree(int a1)
{
  int v1; // eax@1
  void *v2; // edx@1
  void *v3; // edx@7
  void *v4; // edx@9
  void *v5; // edx@12
  int v6; // edx@14
  void *v7; // eax@15
  int v8; // edx@16
  int v9; // edx@18
  int v11; // ecx@22
  int v12; // edx@23
  void *v13; // ebx@23
  signed int v14; // edx@25
  signed int v15; // edx@27
  int v16; // [sp+0h] [bp-38h]@1
  int v17; // [sp+4h] [bp-34h]@1
  int v18; // [sp+8h] [bp-30h]@5
  void *v19; // [sp+Ch] [bp-2Ch]@19
  CPPEH_RECORD ms_exc; // [sp+20h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v16;
  v16 = 0;
  ms_exc.registration.TryLevel = 0;
  v1 = a1 + 88;
  v17 = a1 + 88;
  v2 = *(void **)(a1 + 14460);
  if ( v2 )
  {
    if ( !ownCloseFile(v2) )
    {
      v16 = -9;
      goto LABEL_19;
    }
    v1 = v17;
    *(_DWORD *)(v17 + 14372) = 0;
  }
  *(_DWORD *)(v1 + 14052) = 0;
  *(_DWORD *)(v1 + 14056) = 0;
  *(_DWORD *)(v1 + 14060) = 0;
  *(_DWORD *)(v1 + 14064) = 0;
  v18 = 4;
  if ( *(_DWORD *)(v1 + 14272) <= 255 )
  {
    v3 = *(void **)(v1 + 14284);
    if ( v3 )
    {
      operator delete(v3);
      v1 = v17;
      *(_DWORD *)(v17 + 14284) = 0;
      *(_DWORD *)(v1 + 14272) = 0;
    }
    v4 = *(void **)(v1 + 19940);
    if ( v4 )
    {
      operator delete(v4);
      v1 = v17;
      *(_DWORD *)(v17 + 19940) = 0;
    }
    if ( *(_DWORD *)(v1 + 19944) == 1 )
    {
      v11 = *(_DWORD *)(v1 + 19948);
      if ( v11 )
      {
        v12 = *(_DWORD *)(v11 + 4);
        v13 = *(void **)v11;
        if ( *(_DWORD *)v11 > v12 )
        {
          *(_DWORD *)v11 = v12;
          v11 = *(_DWORD *)(v1 + 19948);
          v13 = *(void **)v11;
        }
        v14 = *(_DWORD *)(v11 + 8);
        if ( (signed int)v13 > v14 )
        {
          *(_DWORD *)v11 = v14;
          v11 = *(_DWORD *)(v1 + 19948);
          v13 = *(void **)v11;
        }
        v15 = *(_DWORD *)(v11 + 12);
        if ( (signed int)v13 > v15 )
        {
          *(_DWORD *)v11 = v15;
          v13 = (void *)**(_DWORD **)(v1 + 19948);
        }
        operator delete(v13);
        operator delete(*(void **)(v17 + 19948));
        v1 = v17;
        *(_DWORD *)(v17 + 19948) = 0;
      }
    }
    v5 = *(void **)(v1 + 18480);
    if ( v5 )
    {
      operator delete(v5);
      v1 = v17;
      *(_DWORD *)(v17 + 18480) = 0;
    }
    v6 = *(_DWORD *)(v1 + 14304);
    if ( v6 )
    {
      v7 = *(void **)(v6 + 52);
      if ( v7 )
      {
        operator delete(v7);
        v8 = v17;
        *(_DWORD *)(*(_DWORD *)(v17 + 14304) + 52) = 0;
        v6 = *(_DWORD *)(v8 + 14304);
      }
      operator delete((void *)v6);
      v1 = v17;
      *(_DWORD *)(v17 + 14304) = 0;
    }
    __g_memzero((void *)(v1 + 14108), 0x20u);
    __g_memzero((void *)(v17 + 14140), 0x60u);
    v9 = v17;
    *(_DWORD *)(v17 + 128) = 0;
    *(_DWORD *)(v9 + 132) = 0;
    *(_DWORD *)(v9 + 144) = 0;
    *(_DWORD *)(v9 + 136) = 0;
    *(_DWORD *)(v9 + 140) = 0;
    *(_DWORD *)(v9 + 14100) = 0;
    *(_DWORD *)(v9 + 14104) = 0;
    ms_exc.registration.TryLevel = -1;
  }
  else
  {
    v16 = -8;
  }
LABEL_19:
  ownFreeLibrary(*(_DWORD *)(a1 + 14408));
  v19 = *(void **)(a1 + 14408);
  if ( v19 )
  {
    operator delete(v19);
    *(_DWORD *)(a1 + 14408) = 0;
  }
  return v16;
}
// 8F75A4: using guessed type void (__cdecl *__g_memzero)(void *, unsigned int);

//----- (006156A0) --------------------------------------------------------  // acclient.c:569449
signed int __cdecl CheckParameters(struct _JPEG_CORE_PROPERTIES *a1)
{
  char v1; // cl@1
  char v2; // dl@1
  char v3; // al@1
  _IJLIOTYPE v4; // esi@2
  int v5; // ebx@59
  int v6; // eax@63
  int v7; // eax@65
  _IJL_COLOR v9; // ecx@80
  _IJL_COLOR v10; // eax@87
  _DCTTYPE v11; // eax@95
  _IJL_JPGSUBSAMPLING v12; // eax@102
  _IJL_JPGSUBSAMPLING v13; // eax@106
  _IJL_COLOR v14; // edx@119
  _IJL_COLOR v15; // edx@138
  _IJL_COLOR v16; // edx@148
  _IJL_COLOR v17; // edx@168
  _IJL_COLOR v18; // edx@175
  _IJL_COLOR v19; // edx@189
  _IJL_COLOR v20; // edx@199
  int v21; // ebx@207
  int v22; // ebx@209
  int v23; // ebx@214
  _IJL_JPGSUBSAMPLING v24; // ebx@216
  _IJL_COLOR v25; // ebx@221
  char v26; // [sp+8h] [bp-1Ch]@1
  char v27; // [sp+Ch] [bp-18h]@1

  v1 = 0;
  v2 = 0;
  v27 = 0;
  v3 = 0;
  v26 = 0;
  if ( a1->UseJPEGPROPERTIES )
    return 0;
  v4 = a1->jprops.iotype;
  if ( v4 == -1 )
    return -8;
  if ( v4
    && v4 != 1
    && v4 != 2
    && v4 != 3
    && v4 != 4
    && v4 != 5
    && v4 != 6
    && v4 != 7
    && v4 != 14
    && v4 != 15
    && v4 != 16
    && v4 != 17
    && v4 != 18
    && v4 != 19
    && v4 != 20
    && v4 != 21 )
  {
    if ( v4 != 8 && v4 != 9 && v4 != 10 && v4 != 11 && v4 != 12 && v4 != 13 )
      return -8;
    v27 = 1;
  }
  else
  {
    v1 = 1;
  }
  if ( v4 == IJL_JFILE_READPARAMS
    || v4 == 2
    || v4 == 4
    || v4 == 6
    || v4 == 14
    || v4 == 16
    || v4 == 18
    || v4 == 20
    || v4 == 8
    || v4 == 10
    || v4 == 12 )
    v2 = 1;
  if ( v4 != 2
    && v4 != 3
    && v4 != 6
    && v4 != 7
    && v4 != 8
    && v4 != 9
    && v4 != 12
    && v4 != 13
    && v4 != 18
    && v4 != 19
    && v4 != 16
    && v4 != 17
    && v4 != 15
    && v4 != 20
    && v4 != 21
    || (v3 = 1, a1->jprops.raw_coefs) )
  {
LABEL_54:
    if ( v2 )
    {
      if ( !a1->JPGFile )
        return -8;
    }
    else if ( !a1->JPGBytes || !a1->JPGSizeBytes )
    {
      return -8;
    }
    v5 = a1->JPGChannels;
    if ( v5 <= 0 || v5 > 256 )
      return -8;
    if ( v27 )
    {
      if ( v3 )
      {
        v6 = a1->JPGWidth;
        if ( v6 <= 0 )
          return -8;
        if ( v6 > 0xFFFF )
          return -8;
        v7 = a1->JPGHeight;
        if ( v7 <= 0 || v7 > 0xFFFF )
          return -8;
        if ( a1->DIBColor != 4 && a1->JPGColor != 3 && v5 > a1->DIBChannels )
          return -8;
      }
      if ( v5 == 1 && a1->JPGSubsampling )
        return -3;
      if ( v5 == 3 )
      {
        v13 = a1->JPGSubsampling;
        if ( v13 != 1 && v13 != 2 && v13 )
          return -3;
      }
      if ( v5 == 4 )
      {
        v12 = a1->JPGSubsampling;
        if ( v12 != 3 && v12 != 4 && v12 )
          return -3;
      }
      if ( v5 != 1 && v5 != 3 && v5 != 4 && a1->JPGSubsampling )
        return -3;
    }
    if ( v1 )
    {
      v9 = a1->JPGColor;
      if ( v9 == 4 && v5 == 1 )
      {
        if ( (v16 = a1->DIBColor, v16 == 4) && a1->DIBChannels == 1
          || v16 == 1 && a1->DIBChannels == 3
          || v16 == 2 && a1->DIBChannels == 3
          || v16 == 5 && a1->DIBChannels == 4 )
          v26 = 1;
      }
      if ( v9 == 1 && v5 == 3 )
      {
        if ( (v15 = a1->DIBColor, v15 == 1) && a1->DIBChannels == 3
          || v15 == 2 && a1->DIBChannels == 3
          || v15 == 5 && a1->DIBChannels == 4 )
          v26 = 1;
      }
      if ( v9 == 5 && v5 == 4 && a1->DIBColor == 5 && a1->DIBChannels == 4 )
        v26 = 1;
      if ( v9 == 3 && v5 == 3 )
      {
        v14 = a1->DIBColor;
        if ( v14 == 4 && a1->DIBChannels == 1
          || v14 == 1 && a1->DIBChannels == 3
          || v14 == 2 && a1->DIBChannels == 3
          || v14 == 5 && a1->DIBChannels == 4 )
          v26 = 1;
        if ( v14 == 3 )
          v26 = 1;
      }
      if ( v9 == 6 && v5 == 4 && a1->DIBColor == 5 && a1->DIBChannels == 4 )
        v26 = 1;
      if ( v9 != 255 || a1->DIBColor != 255 )
        goto LABEL_94;
    }
    else
    {
      v10 = a1->DIBColor;
      if ( v10 == 4 && a1->DIBChannels == 1 )
      {
        if ( (v20 = a1->JPGColor, v20 == 4) && v5 == 1 || v20 == 3 && v5 == 3 )
          v26 = 1;
      }
      if ( v10 == 1 && a1->DIBChannels == 3 )
      {
        if ( (v19 = a1->JPGColor, v19 == 4) && v5 == 1 || v19 == 1 && v5 == 3 || v19 == 3 && v5 == 3 )
          v26 = 1;
      }
      if ( v10 == 1 && a1->DIBChannels == 4 && a1->JPGColor == 3 && v5 == 3 )
        v26 = 1;
      if ( v10 == 2 && a1->DIBChannels == 3 )
      {
        if ( (v18 = a1->JPGColor, v18 == 4) && v5 == 1 || v18 == 1 && v5 == 3 || v18 == 3 && v5 == 3 )
          v26 = 1;
      }
      if ( v10 == 5 && a1->DIBChannels == 4 )
      {
        if ( (v17 = a1->JPGColor, v17 == 5) && v5 == 4 || v17 == 6 && v5 == 4 )
          v26 = 1;
      }
      if ( v10 == 3 && a1->DIBChannels == 3 && a1->JPGColor == 3 && v5 == 3 )
        v26 = 1;
      if ( v10 != 255 || v5 > a1->DIBChannels || a1->JPGColor != 255 )
      {
LABEL_94:
        if ( v26 )
          goto LABEL_95;
        return -8;
      }
    }
LABEL_95:
    v11 = a1->jprops.dcttype;
    if ( v11 && v11 != 1 )
      return -8;
    if ( a1->jprops.upsampling_type == 1 && a1->jprops.raw_coefs )
      return -8;
    return 0;
  }
  if ( !a1->DIBBytes )
    return -8;
  v21 = a1->DIBWidth;
  if ( v21 > 0xFFFF )
    return -8;
  if ( v21 <= 0 )
    return -8;
  v22 = a1->DIBHeight;
  if ( v22 > 0xFFFF || v22 < -65535 )
    return -8;
  if ( v4 != 20 && v4 != 21 || (v25 = a1->DIBColor, v25 == 1) || v25 == 2 )
  {
    if ( a1->DIBPadBytes < 0 )
      return -8;
    v23 = a1->DIBChannels;
    if ( v23 <= 0 || v23 > 255 )
      return -8;
    v24 = a1->DIBSubsampling;
    if ( v24 && (v24 != 2 || a1->DIBColor != 3) )
      return -3;
    goto LABEL_54;
  }
  return -27;
}

//----- (00615DE0) --------------------------------------------------------  // acclient.c:569692
int __stdcall ijlRead(struct _JPEG_CORE_PROPERTIES *a1, int a2)
{
  _JPEG_PROPERTIES *v2; // eax@2
  _IJLIOTYPE v3; // edx@2
  struct _JPEG_CORE_PROPERTIES *v4; // edx@19
  _IJLIOTYPE v5; // eax@20
  char *v6; // eax@31
  struct _JPEG_PROPERTIES *v7; // ebx@31
  int v8; // ecx@31
  int v9; // esi@31
  char *v10; // esi@33
  struct _JPEG_PROPERTIES *v11; // ecx@33
  int v12; // ebx@33
  int v13; // edx@36
  struct _JPEG_PROPERTIES *v14; // edx@38
  signed int v15; // eax@38
  _JPEG_PROPERTIES *v16; // ecx@41
  _IJLIOTYPE v17; // eax@42
  int v18; // ebx@43
  signed int v19; // edx@47
  int v20; // edx@50
  signed int v21; // eax@70
  int v22; // ebx@70
  _IJLIOTYPE v23; // eax@74
  HANDLE v25; // eax@79
  struct _JPEG_PROPERTIES *v26; // edi@82
  int v27; // ecx@82
  _JPEG_PROPERTIES *v28; // eax@103
  int v29; // ecx@103
  int v30; // edx@103
  int v31; // ecx@105
  int v32; // edx@105
  signed int v33; // edx@108
  signed int v34; // edx@112
  void *v35; // eax@118
  _FRAME_COMPONENT *v36; // esi@122
  int v37; // ebx@122
  _FRAME_COMPONENT *v38; // esi@149
  int v39; // ebx@149
  _FRAME_COMPONENT *v40; // ebx@170
  int v41; // eax@181
  _JPEGQuantTable *v42; // ebx@182
  int v43; // ecx@182
  __int16 **v44; // edx@182
  int v45; // eax@182
  int v46; // eax@182
  int v47; // edx@182
  int v48; // ecx@185
  int v49; // eax@186
  int v50; // ecx@186
  int v51; // edx@186
  int v52; // ebx@186
  int v53; // eax@186
  int v54; // [sp+0h] [bp-78h]@1
  void *v55; // [sp+4h] [bp-74h]@1
  _JPEG_PROPERTIES *v56; // [sp+8h] [bp-70h]@1
  int v57; // [sp+Ch] [bp-6Ch]@179
  int v58; // [sp+10h] [bp-68h]@181
  int v59; // [sp+14h] [bp-64h]@186
  int v60; // [sp+18h] [bp-60h]@186
  char *v61; // [sp+1Ch] [bp-5Ch]@186
  int v62; // [sp+20h] [bp-58h]@186
  HANDLE v63; // [sp+24h] [bp-54h]@79
  int v64; // [sp+28h] [bp-50h]@60
  int *v65; // [sp+38h] [bp-40h]@180
  _QUANT_TABLE *v66; // [sp+3Ch] [bp-3Ch]@180
  char *v67; // [sp+40h] [bp-38h]@180
  struct _JPEG_PROPERTIES *v68; // [sp+44h] [bp-34h]@2
  int v69; // [sp+48h] [bp-30h]@82
  __int16 **v70; // [sp+4Ch] [bp-2Ch]@180
  _JPEGQuantTable *v71; // [sp+50h] [bp-28h]@180
  int v72; // [sp+54h] [bp-24h]@181
  int v73; // [sp+58h] [bp-20h]@179
  CPPEH_RECORD ms_exc; // [sp+60h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v54;
  v54 = 0;
  v55 = 0;
  ms_exc.registration.TryLevel = 0;
  v56 = &a1->jprops;
  v56->iotype = a2;
  v55 = a1->jprops.state.ctx;
  v54 = CheckParameters(a1);
  if ( !v54 )
  {
    v2 = v56;
    v68 = v56;
    v3 = v56->iotype;
    if ( v56->iotype == 4 || v3 == 5 || v3 == IJL_JFILE_READPARAMS || v3 == 1 || v3 == 20 || v3 == 21 )
      v56->needframe = 1;
    if ( v3 == 6
      || v3 == 7
      || v3 == 2
      || v3 == 3
      || v3 == 18
      || v3 == 19
      || v3 == 16
      || v3 == 17
      || v3 == 14
      || v3 == 15 )
    {
      if ( v2->use_external_qtables )
      {
        v73 = 0;
        v57 = 0;
        if ( v68->maxquantindex > 0 )
        {
          v65 = &v68->jFmtQuant[0].ident;
          v67 = &v68->rawquanttables[0].ident;
          v66 = v68->jFmtQuant;
          v70 = &v68->jFmtQuant[0].elements;
          v71 = v68->rawquanttables;
          do
          {
            v41 = 180 * v73;
            v72 = v41;
            v65[v41 / 4u] = (unsigned __int8)v67[8 * v73];
            v66[v41 / 0xB4u].precision = 0;
            v69 = 0;
            v58 = 0;
            do
            {
              v42 = v71;
              v43 = v69;
              v44 = v70;
              v45 = v72;
              (*(__int16 **)((char *)v70 + v72))[v69] = v71[v73].quantizer[v69];
              (*(__int16 **)((char *)v44 + v45))[v43 + 1] = v42[v73].quantizer[v43 + 1];
              (*(__int16 **)((char *)v44 + v45))[v43 + 2] = v42[v73].quantizer[v43 + 2];
              v46 = *(int *)((char *)v44 + v45);
              v47 = v69;
              *(_WORD *)(v46 + 2 * v69 + 6) = v42[v73].quantizer[v69 + 3];
              v69 = v47 + 4;
              v58 = v47 + 4;
            }
            while ( v47 + 4 < 64 );
            ++v73;
            v57 = v73;
          }
          while ( v73 < v68->maxquantindex );
        }
      }
      if ( v68->use_external_htables )
      {
        v48 = 0;
        v57 = 0;
        if ( v68->maxhuffindex > 0 )
        {
          while ( 1 )
          {
            v49 = v48;
            v50 = v68->rawhufftables[v48].hclass;
            v59 = v50;
            v51 = v68->rawhufftables[v49].ident;
            v60 = v68->rawhufftables[v49].ident;
            v52 = (int)v68->rawhufftables[v49].bits;
            v61 = v68->rawhufftables[v49].bits;
            v53 = (int)v68->rawhufftables[v49].vals;
            v62 = v53;
            if ( v50 )
            {
              v54 = BuildDecoderHuffmanTable(v52, v53, v50, v51, (int)&v68->jFmtAcHuffman[v51]);
              if ( v54 )
              {
                v54 = -6;
                goto LABEL_77;
              }
            }
            else
            {
              v54 = BuildDecoderHuffmanTable(v52, v53, 0, v51, (int)&v68->jFmtDcHuffman[v51]);
              if ( v54 )
              {
                v54 = -6;
                goto LABEL_77;
              }
            }
            v48 = v57 + 1;
            v57 = v48;
            v68 = v56;
            if ( v48 >= v56->maxhuffindex )
            {
              v4 = a1;
              goto LABEL_20;
            }
          }
        }
        v4 = a1;
      }
      else
      {
        v4 = a1;
      }
    }
    else
    {
      v4 = a1;
      a1->jprops.nqtables = 0;
      a1->jprops.maxquantindex = 0;
      a1->jprops.maxhuffindex = 0;
      a1->jprops.nhuffActables = 0;
      a1->jprops.nhuffDctables = 0;
    }
LABEL_20:
    v5 = v68->iotype;
    if ( (v68->iotype == 2
       || v5 == 4
       || v5 == 6
       || v5 == IJL_JFILE_READPARAMS
       || v5 == 18
       || v5 == 16
       || v5 == 14
       || v5 == 20)
      && !v68->state.file )
    {
      v25 = ownOpenFile(v4->JPGFile, 0x80000000);
      v63 = v25;
      if ( !v25 )
      {
        v54 = -10;
        goto LABEL_77;
      }
      v68 = v56;
      v56->state.file = v25;
      v4 = a1;
    }
    if ( v4->UseJPEGPROPERTIES )
    {
      v6 = v68->DIBBytes;
    }
    else
    {
      v6 = v4->DIBBytes;
      v7 = v68;
      v68->DIBBytes = v6;
      v7->DIBWidth = v4->DIBWidth;
      v8 = v4->DIBHeight;
      v7->DIBHeight = v8;
      v7->DIBPadBytes = v4->DIBPadBytes;
      v7->DIBChannels = v4->DIBChannels;
      v7->DIBColor = v4->DIBColor;
      v7->DIBSubsampling = v4->DIBSubsampling;
      v9 = v4->DIBPadBytes + v4->DIBChannels * v4->DIBWidth;
      v7->DIBLineBytes = v9;
      if ( v8 < 0 )
        v7->DIBLineBytes = -v9;
      v10 = v4->JPGBytes;
      v11 = v7;
      v7->JPGBytes = v10;
      v7->JPGFile = v4->JPGFile;
      v12 = v4->JPGSizeBytes;
      v11->JPGSizeBytes = v12;
      v11->JPGColor = v4->JPGColor;
      v11->cconversion_reqd = v4->cconversion_reqd;
      v11->upsampling_reqd = v4->upsampling_reqd;
      v11->jquality = v4->jquality;
      if ( !v11->jscan )
      {
        v26 = v68;
        LODWORD(v68->state.bit_buffer_64) = 0;
        HIDWORD(v26->state.bit_buffer_64) = 0;
        v26->state.bitbuf_bits_valid = 0;
        v26->state.unread_marker = 0;
        v27 = v26->iotype;
        v69 = v27;
        if ( v27 != 2 && v27 != 4 && v27 && v27 != 6 && v27 != 18 && v27 != 16 && v27 != 14 && v27 != 20 )
        {
          v26->state.start_entropy_ptr = v10;
          v26->state.end_entropy_ptr = &v10[v12];
          v26->state.cur_entropy_ptr = v10;
          v26->state.entropy_bytes_left = v12;
          v26->state.entropy_buf_maxsize = v12;
        }
        if ( v69 == 2 || v69 == 4 || !v69 || v69 == 6 || v69 == 18 || v69 == 16 || v69 == 14 || v69 == 20 )
        {
          v26->state.start_entropy_ptr = v26->state.JPGBuffer;
          v26->state.end_entropy_ptr = (char *)&v26->SawAdobeMarker;
          v26->state.cur_entropy_ptr = v26->state.JPGBuffer;
          v26->state.entropy_bytes_left = 4096;
          v26->state.entropy_buf_maxsize = 4096;
        }
        if ( v69 == 20 )
        {
          v64 = ownSeekFile(v26->state.file, 0, 0);
          if ( !v64 )
            goto LABEL_77;
          v4 = a1;
          v68 = v56;
          v6 = v56->DIBBytes;
        }
      }
    }
    v13 = v4->DIBHeight;
    if ( v13 < 0 )
    {
      v6 += v68->DIBLineBytes * (v13 + 1);
      v68->DIBBytes = v6;
    }
    v14 = v68;
    v68->state.DIB_ptr = v6;
    v14->MCUBuf = (char *)((unsigned int)&v14->tMCUBuf[31] & 0xFFFFFFE0);
    v15 = IJL_Decode(v14);
    v54 = v15;
    if ( v15 )
    {
      if ( v15 == 1 )
      {
        v28 = v56;
        v29 = v56->jframe.max_hsampling * (8 * v56->roi.right + 8);
        v56->roi.right = v29;
        v30 = v28->JPGWidth;
        if ( v29 > v30 )
          v28->roi.right = v30;
        v31 = v28->jframe.max_vsampling * (8 * v28->roi.bottom + 8);
        v28->roi.bottom = v31;
        v32 = v28->JPGHeight;
        if ( v31 > v32 )
          v28->roi.bottom = v32;
      }
    }
    else
    {
      v16 = v56;
      if ( v56->SawAdobeMarker )
      {
        v17 = v56->iotype;
        if ( v56->iotype && v17 != 1 )
        {
          v19 = v56->DIBColor;
        }
        else
        {
          v18 = v56->JPGChannels;
          v56->DIBChannels = v18;
          if ( v18 == 1 )
            v16->JPGColor = 4;
          if ( v18 == 3 )
          {
            if ( v16->AdobeXform )
              v34 = 3;
            else
              v34 = 1;
            v16->JPGColor = v34;
          }
          if ( v18 == 4 )
          {
            if ( v16->AdobeXform )
              v33 = 6;
            else
              v33 = 5;
            v16->JPGColor = v33;
            v19 = 5;
            v16->DIBColor = 5;
          }
          else
          {
            v19 = v16->DIBColor;
          }
        }
      }
      else
      {
        v20 = v56->JPGChannels;
        if ( v20 == 1 )
          v56->JPGColor = 4;
        if ( v16->jfif_app0_detected )
        {
          if ( v20 == 3 )
          {
            v16->JPGColor = 3;
            v19 = v16->DIBColor;
            v17 = v16->iotype;
          }
          else
          {
            v19 = v16->DIBColor;
            v17 = v16->iotype;
          }
        }
        else
        {
          v19 = v16->DIBColor;
          v17 = v16->iotype;
        }
      }
      if ( v19 == 3 && v16->JPGColor == 3 )
        v16->DIBSubsampling = 2;
      if ( v17 == 4 || v17 == 6 || v17 == IJL_JFILE_READPARAMS || v17 == 18 || v17 == 16 || v17 == 14 || v17 == 20 )
      {
        v64 = ownSeekFile(v16->state.file, -(*(_DWORD *)v55 + v16->state.entropy_bytes_left), 1u);
        if ( !v64 )
        {
          v54 = -23;
          goto LABEL_77;
        }
        v16 = v56;
        v17 = v56->iotype;
      }
      if ( v17 == 1 || v17 == 21 )
        v16->state.start_entropy_ptr = &v16->state.cur_entropy_ptr[-*(_DWORD *)v55];
      a1->JPGWidth = v16->JPGWidth;
      a1->JPGHeight = v16->JPGHeight;
      a1->JPGChannels = v16->JPGChannels;
      a1->JPGThumbWidth = v16->JPGThumbWidth;
      a1->JPGThumbHeight = v16->JPGThumbHeight;
      a1->cconversion_reqd = v16->cconversion_reqd;
      a1->upsampling_reqd = v16->upsampling_reqd;
      v21 = 255;
      a1->JPGSubsampling = 255;
      v22 = v16->jframe.ncomps;
      switch ( v22 )
      {
        case 1:
          v21 = 0;
          a1->JPGSubsampling = 0;
          break;
        case 2:
          v40 = v16->jframe.comps;
          if ( v40->hsampling == 1 && v40->vsampling == 1 && v40[1].hsampling == 1 && v40[1].vsampling == 1 )
          {
            v21 = 0;
            a1->JPGSubsampling = 0;
          }
          break;
        case 3:
          v38 = v16->jframe.comps;
          v39 = v38->hsampling;
          if ( v39 != 1
            || v38->vsampling != 1
            || v38[1].hsampling != 1
            || v38[1].vsampling != 1
            || v38[2].hsampling != 1
            || v38[2].vsampling != 1 )
          {
            if ( v39 != 2
              || v38->vsampling != 2
              || v38[1].hsampling != 1
              || v38[1].vsampling != 1
              || v38[2].hsampling != 1
              || v38[2].vsampling != 1 )
            {
              if ( v39 == 2
                && v38->vsampling == 1
                && v38[1].hsampling == 1
                && v38[1].vsampling == 1
                && v38[2].hsampling == 1
                && v38[2].vsampling == 1 )
              {
                v21 = 2;
                a1->JPGSubsampling = 2;
              }
            }
            else
            {
              v21 = 1;
              a1->JPGSubsampling = 1;
            }
          }
          else
          {
            v21 = 0;
            a1->JPGSubsampling = 0;
          }
          break;
        case 4:
          v36 = v16->jframe.comps;
          v37 = v36->hsampling;
          if ( v37 != 1
            || v36->vsampling != 1
            || v36[1].hsampling != 1
            || v36[1].vsampling != 1
            || v36[2].hsampling != 1
            || v36[2].vsampling != 1
            || v36[3].hsampling != 1
            || v36[3].vsampling != 1 )
          {
            if ( v37 != 2
              || v36->vsampling != 2
              || v36[1].hsampling != 1
              || v36[1].vsampling != 1
              || v36[2].hsampling != 1
              || v36[2].vsampling != 1
              || v36[3].hsampling != 2
              || v36[3].vsampling != 2 )
            {
              if ( v37 == 2
                && v36->vsampling == 1
                && v36[1].hsampling == 1
                && v36[1].vsampling == 1
                && v36[2].hsampling == 1
                && v36[2].vsampling == 1
                && v36[3].hsampling == 2
                && v36[3].vsampling == 1 )
              {
                v21 = 4;
                a1->JPGSubsampling = 4;
              }
            }
            else
            {
              v21 = 3;
              a1->JPGSubsampling = 3;
            }
          }
          else
          {
            v21 = 0;
            a1->JPGSubsampling = 0;
          }
          break;
      }
      v16->JPGSubsampling = v21;
      a1->JPGColor = v16->JPGColor;
      a1->DIBColor = v16->DIBColor;
      a1->DIBChannels = v16->DIBChannels;
      v23 = v16->iotype;
      if ( v16->iotype == 2 || v23 == 4 || v23 == 6 )
      {
        v35 = v16->state.file;
        if ( v35 )
        {
          v64 = ownCloseFile(v35);
          if ( v64 )
            v56->state.file = 0;
          else
            v54 = -9;
        }
      }
    }
  }
LABEL_77:
  (*((void (**)(void))v55 + 6))();
  ms_exc.registration.TryLevel = -1;
  if ( v54 < 0 && a1->jprops.state.file )
  {
    ownCloseFile(a1->jprops.state.file);
    a1->jprops.state.file = 0;
  }
  return v54;
}

//----- (00616900) --------------------------------------------------------  // acclient.c:570234
int __stdcall ijlWrite(struct _JPEG_CORE_PROPERTIES *a1, int a2)
{
  int v2; // esi@2
  _IJLIOTYPE v3; // eax@2
  struct _JPEG_PROPERTIES *v5; // ecx@10
  _IJL_COLOR v6; // eax@10
  _IJL_COLOR v7; // eax@12
  int v8; // eax@16
  _IJL_JPGSUBSAMPLING v9; // eax@16
  struct _JPEG_CORE_PROPERTIES *v10; // eax@36
  int v11; // ebx@36
  _FRAME_COMPONENT *v12; // edx@37
  int v13; // eax@38
  int v14; // edi@38
  int v15; // edi@40
  signed int v16; // eax@46
  int v17; // esi@47
  int v18; // eax@47
  _IJLIOTYPE v19; // eax@48
  signed int v20; // eax@53
  void *v21; // eax@56
  int v22; // edx@61
  int v23; // eax@61
  int v24; // edx@63
  int v25; // eax@63
  int v26; // edx@67
  int v27; // eax@69
  int v28; // eax@70
  int v29; // eax@74
  _IJL_COLOR v30; // edi@77
  int v31; // ecx@77
  _IJL_COLOR v32; // eax@77
  _IJL_JPGSUBSAMPLING v33; // edx@77
  int v34; // eax@77
  int v35; // edi@77
  int v36; // edi@78
  int v37; // edx@95
  int v38; // eax@96
  signed int v39; // ebx@100
  HANDLE v40; // eax@105
  int v41; // [sp+0h] [bp-50h]@1
  HANDLE v42; // [sp+4h] [bp-4Ch]@1
  struct _JPEG_PROPERTIES *v43; // [sp+8h] [bp-48h]@1
  int v44; // [sp+Ch] [bp-44h]@1
  int i; // [sp+10h] [bp-40h]@36
  int v46; // [sp+14h] [bp-3Ch]@57
  _IJL_COLOR v47; // [sp+28h] [bp-28h]@36
  int v48; // [sp+2Ch] [bp-24h]@36
  struct _JPEG_CORE_PROPERTIES *v49; // [sp+30h] [bp-20h]@16
  int v50; // [sp+34h] [bp-1Ch]@16
  CPPEH_RECORD ms_exc; // [sp+38h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v41;
  v41 = 0;
  v42 = 0;
  ms_exc.registration.TryLevel = 0;
  v43 = &a1->jprops;
  v44 = 0;
  v43->iotype = a2;
  v41 = CheckParameters(a1);
  if ( !v41 )
  {
    v2 = (int)v43;
    v3 = v43->iotype;
    if ( (v43->iotype == 8 || v3 == 10 || v3 == 12) && !v43->state.file )
    {
      v40 = ownOpenFile(a1->JPGFile, 0xC0000000);
      v42 = v40;
      if ( !v40 )
      {
        v41 = -10;
        goto LABEL_8;
      }
      v2 = (int)v43;
      v43->state.file = v40;
    }
    if ( !a1->UseJPEGPROPERTIES && !*(_DWORD *)(v2 + 14304) )
    {
      *(_DWORD *)(v2 + 76) = a1->JPGWidth;
      *(_DWORD *)(v2 + 80) = a1->JPGHeight;
      *(_DWORD *)(v2 + 84) = a1->JPGChannels;
      v30 = a1->JPGColor;
      v47 = v30;
      *(_DWORD *)(v2 + 88) = v30;
      *(_DWORD *)(v2 + 92) = a1->JPGSubsampling;
      *(_DWORD *)(v2 + 68) = a1->JPGBytes;
      *(_DWORD *)(v2 + 72) = a1->JPGSizeBytes;
      *(_DWORD *)(v2 + 64) = a1->JPGFile;
      *(_DWORD *)(v2 + 32) = a1->DIBBytes;
      *(_DWORD *)(v2 + 36) = a1->DIBWidth;
      v31 = a1->DIBHeight;
      *(_DWORD *)(v2 + 40) = v31;
      *(_DWORD *)(v2 + 44) = a1->DIBPadBytes;
      *(_DWORD *)(v2 + 48) = a1->DIBChannels;
      v32 = a1->DIBColor;
      v48 = v32;
      *(_DWORD *)(v2 + 52) = v32;
      v33 = a1->DIBSubsampling;
      *(_DWORD *)(v2 + 56) = v33;
      v34 = a1->DIBWidth;
      v35 = a1->DIBPadBytes;
      v49 = (struct _JPEG_CORE_PROPERTIES *)a1->DIBPadBytes;
      if ( v33 == 2 )
        v36 = v35 + 2 * v34;
      else
        v36 = (int)((char *)&v49->UseJPEGPROPERTIES + v34 * a1->DIBChannels);
      *(_DWORD *)(v2 + 60) = v36;
      if ( v31 < 0 )
        *(_DWORD *)(v2 + 60) = -v36;
      *(_DWORD *)(v2 + 104) = a1->cconversion_reqd;
      *(_DWORD *)(v2 + 108) = a1->upsampling_reqd;
      *(_DWORD *)(v2 + 112) = a1->jquality;
      if ( v33 == 2 && v48 == 3 && v47 == 3 )
        *(_DWORD *)(v2 + 92) = 2;
    }
    v41 = SetDefaultTables(v2);
    if ( !v41 )
    {
      v5 = v43;
      v43->cconversion_reqd = 1;
      v6 = v5->JPGColor;
      if ( v6 == 1 || v6 == 5 || (v7 = v5->DIBColor, v7 == 4) || v7 == 255 || v7 == 3 )
        v5->cconversion_reqd = 0;
      v49 = a1;
      v8 = a1->JPGChannels;
      v50 = v8;
      v5->jframe.ncomps = v8;
      v9 = a1->JPGSubsampling;
      if ( v9 )
      {
        switch ( v9 )
        {
          case 1:
            v5->jframe.comps->ident = 0;
            v5->jframe.comps->hsampling = 2;
            v5->jframe.comps->vsampling = 2;
            v5->jframe.comps[1].ident = 1;
            v5->jframe.comps[1].hsampling = 1;
            v5->jframe.comps[1].vsampling = 1;
            v5->jframe.comps[2].ident = 2;
            v5->jframe.comps[2].hsampling = 1;
            v5->jframe.comps[2].vsampling = 1;
            if ( v5->use_external_qtables )
            {
              v50 = v5->jframe.ncomps;
            }
            else if ( v49->cconversion_reqd )
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 1;
              v5->jframe.comps[2].quant_sel = 1;
              v50 = v5->jframe.ncomps;
            }
            else
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 0;
              v5->jframe.comps[2].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            break;
          case 2:
            v5->jframe.comps->ident = 0;
            v5->jframe.comps->hsampling = 2;
            v5->jframe.comps->vsampling = 1;
            v5->jframe.comps[1].ident = 1;
            v5->jframe.comps[1].hsampling = 1;
            v5->jframe.comps[1].vsampling = 1;
            v5->jframe.comps[2].ident = 2;
            v5->jframe.comps[2].hsampling = 1;
            v5->jframe.comps[2].vsampling = 1;
            if ( v5->use_external_qtables )
            {
              v50 = v5->jframe.ncomps;
            }
            else if ( v49->cconversion_reqd )
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 1;
              v5->jframe.comps[2].quant_sel = 1;
              v50 = v5->jframe.ncomps;
            }
            else
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 0;
              v5->jframe.comps[2].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            break;
          case 3:
            v5->jframe.comps->ident = 0;
            v5->jframe.comps->hsampling = 2;
            v5->jframe.comps->vsampling = 2;
            v5->jframe.comps[1].ident = 1;
            v5->jframe.comps[1].hsampling = 1;
            v5->jframe.comps[1].vsampling = 1;
            v5->jframe.comps[2].ident = 2;
            v5->jframe.comps[2].hsampling = 1;
            v5->jframe.comps[2].vsampling = 1;
            v5->jframe.comps[3].ident = 3;
            v5->jframe.comps[3].hsampling = 2;
            v5->jframe.comps[3].vsampling = 2;
            if ( v5->use_external_qtables )
            {
              v50 = v5->jframe.ncomps;
            }
            else if ( v49->cconversion_reqd )
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 1;
              v5->jframe.comps[2].quant_sel = 1;
              v5->jframe.comps[3].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            else
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 0;
              v5->jframe.comps[2].quant_sel = 0;
              v5->jframe.comps[3].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            break;
          case 4:
            v5->jframe.comps->ident = 0;
            v5->jframe.comps->hsampling = 2;
            v5->jframe.comps->vsampling = 1;
            v5->jframe.comps[1].ident = 1;
            v5->jframe.comps[1].hsampling = 1;
            v5->jframe.comps[1].vsampling = 1;
            v5->jframe.comps[2].ident = 2;
            v5->jframe.comps[2].hsampling = 1;
            v5->jframe.comps[2].vsampling = 1;
            v5->jframe.comps[3].ident = 3;
            v5->jframe.comps[3].hsampling = 2;
            v5->jframe.comps[3].vsampling = 1;
            if ( v5->use_external_qtables )
            {
              v50 = v5->jframe.ncomps;
            }
            else if ( v49->cconversion_reqd )
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 1;
              v5->jframe.comps[2].quant_sel = 1;
              v5->jframe.comps[3].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            else
            {
              v5->jframe.comps->quant_sel = 0;
              v5->jframe.comps[1].quant_sel = 0;
              v5->jframe.comps[2].quant_sel = 0;
              v5->jframe.comps[3].quant_sel = 0;
              v50 = v5->jframe.ncomps;
            }
            break;
        }
      }
      else
      {
        v37 = 0;
        for ( i = 0; v37 < v50; v50 = v5->jframe.ncomps )
        {
          v38 = v37;
          v5->jframe.comps[v38].ident = v37;
          v5->jframe.comps[v38].hsampling = 1;
          v5->jframe.comps[v38].vsampling = 1;
          ++v37;
          i = v37;
        }
        if ( !v5->use_external_qtables )
        {
          v5->jframe.comps->quant_sel = 0;
          if ( v5->cconversion_reqd )
          {
            v50 = v5->jframe.ncomps;
            if ( v50 >= 2 )
            {
              v39 = 1;
              for ( i = 1; v39 < v50; v50 = v5->jframe.ncomps )
              {
                v5->jframe.comps[v39++].quant_sel = 1;
                i = v39;
              }
            }
          }
          else
          {
            v50 = v5->jframe.ncomps;
          }
        }
      }
      v5->jframe.precision = 8;
      v10 = v49;
      v5->jframe.width = v49->JPGWidth;
      v5->jframe.height = v10->JPGHeight;
      v5->upsampling_reqd = 0;
      v48 = 0;
      v5->jframe.max_hsampling = 0;
      v47 = 0;
      v5->jframe.max_vsampling = 0;
      v11 = 0;
      i = 0;
      if ( v50 > 0 )
      {
        v12 = v5->jframe.comps;
        do
        {
          v13 = v11;
          v14 = v12[v11].hsampling;
          if ( v48 < v14 )
          {
            v48 = v12[v11].hsampling;
            v5->jframe.max_hsampling = v14;
          }
          v15 = v12[v13].vsampling;
          if ( v47 < v15 )
          {
            v47 = v12[v13].vsampling;
            v5->jframe.max_vsampling = v15;
          }
          if ( v12[v13].hsampling != 1 || v12[v13].vsampling != 1 )
            v5->upsampling_reqd = 1;
          ++v11;
          i = v11;
        }
        while ( v11 < v50 );
      }
      if ( v5->jinterleaveType == 1 )
      {
        v16 = 8;
        v48 = 8;
        v5->jframe.MCUwidth = 8;
        v47 = 8;
        v5->jframe.MCUheight = 8;
      }
      else
      {
        v16 = 8 * v48;
        v48 = v16;
        v5->jframe.MCUwidth = v16;
        v47 *= 8;
        v5->jframe.MCUheight = v47;
      }
      v17 = (v16 + v5->JPGWidth - 1) / v16;
      v5->numxMCUs = v17;
      v18 = (v47 + v5->JPGHeight - 1) / v47;
      v5->numyMCUs = v18;
      v5->jframe.horMCU = v17;
      v5->jframe.totalMCU = v17 * v18;
      if ( v5->jscan )
      {
        v19 = v5->iotype;
      }
      else
      {
        v5->state.entropy_bytes_processed = 0;
        v27 = v49->DIBHeight;
        if ( v27 < 0 )
        {
          v28 = (int)&v5->DIBBytes[v5->DIBLineBytes * (v27 + 1)];
          v5->DIBBytes = (char *)v28;
        }
        else
        {
          v28 = (int)v5->DIBBytes;
        }
        v5->state.DIB_ptr = (char *)v28;
        v41 = Encode_Frame_Init(v5);
        if ( v41 )
          goto LABEL_8;
        v5 = v43;
        v19 = v43->iotype;
        if ( v43->iotype == 10 || v19 == 11 )
        {
          v29 = v43->state.entropy_bytes_processed;
          v43->JPGSizeBytes = v29;
          a1->JPGSizeBytes = v29;
          v19 = v5->iotype;
        }
      }
      if ( v19 == 8 || v19 == 9 || v19 == 12 || v19 == 13 )
      {
        v5->MCUBuf = (char *)((unsigned int)&v5->tMCUBuf[31] & 0xFFFFFFE0);
        if ( v5->progressive_found )
        {
          v20 = Encode_Frame_P(v5);
          v41 = v20;
        }
        else
        {
          v20 = Encode_Frame(v5);
          v41 = v20;
        }
        v5 = v43;
        v43->needframe = 1;
        v26 = v5->state.entropy_bytes_processed + v44;
        v44 = v26;
        v5->JPGSizeBytes = v26;
        a1->JPGSizeBytes = v26;
      }
      else
      {
        v20 = v41;
      }
      if ( v20 != 1 && v20 != 2 )
      {
        v21 = v5->state.file;
        if ( v21 )
        {
          v46 = ownCloseFile(v21);
          if ( !v46 )
          {
            v41 = -9;
            goto LABEL_8;
          }
          v43->state.file = 0;
        }
        ms_exc.registration.TryLevel = -1;
        goto LABEL_8;
      }
      v22 = v5->jframe.max_hsampling * (8 * v5->roi.right + 8);
      v5->roi.right = v22;
      v23 = v5->JPGWidth;
      if ( v22 > v23 )
        v5->roi.right = v23;
      v24 = v5->jframe.max_vsampling * (8 * v5->roi.bottom + 8);
      v5->roi.bottom = v24;
      v25 = v5->JPGHeight;
      if ( v24 > v25 )
        v5->roi.bottom = v25;
    }
  }
LABEL_8:
  if ( v41 < 0 && a1->jprops.state.file )
  {
    ownCloseFile(a1->jprops.state.file);
    a1->jprops.state.file = 0;
  }
  (*((void (**)(void))a1->jprops.state.ctx + 6))();
  return v41;
}

//----- (00617310) --------------------------------------------------------  // acclient.c:570680
int __stdcall ijlErrorStr(int a1)
{
  int result; // eax@2

  switch ( a1 )
  {
    case 2:
      result = (int)aRoiSuccess;
      break;
    case 1:
      result = (int)aInterruptSucce;
      break;
    case 0:
      result = (int)aSuccess;
      break;
    default:
      result = (int)aUnknownErrorCo;
      break;
  }
  return result;
}

//----- (006183E0) --------------------------------------------------------  // acclient.c:571314
struct IJL_PROCESSOR_INFO *__cdecl ownGetProcessorInfo()
{
  return (struct IJL_PROCESSOR_INFO *)&dword_8F75C0;
}
// 8F75C0: using guessed type int dword_8F75C0;

//----- (006183F0) --------------------------------------------------------  // acclient.c:571321
signed int __cdecl ownGetProcessorType(struct _IJL_CONTEXT *a1)
{
  signed int result; // eax@1
  struct IJL_PROCESSOR_INFO *v2; // eax@8
  int v3; // edx@8
  int v4; // eax@10

  sub_618280();
  result = ownQueryProcessorType((int)a1);
  if ( result && result != 1 && result != 2 && result != 3 && result != 4 && result != 5 && result != 6 )
  {
    v2 = ownGetProcessorInfo();
    v3 = *((_DWORD *)v2 + 2);
    switch ( v3 )
    {
      case 5:
        if ( (unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & *((_DWORD *)v2 + 5) )
          result = 3;
        else
          result = 1;
        break;
      case 6:
        v4 = *((_DWORD *)v2 + 5);
        if ( !((unsigned int)"activation type (%s) with '%s' because of its toggle type (%s)" & v4) || v4 & 0x2000000 )
        {
          if ( (v4 & 0x2800000) == 41943040 )
            result = 5;
          else
            result = 2;
        }
        else
        {
          result = 4;
        }
        break;
      case 15:
        if ( *((_DWORD *)v2 + 5) & 0x4000000 )
          result = 6;
        else
          result = 0;
        break;
      default:
        result = 0;
        break;
    }
  }
  return result;
}

//----- (006184E0) --------------------------------------------------------  // acclient.c:571371
HANDLE __cdecl ownOpenFile(const char *lpFileName, DWORD dwDesiredAccess)
{
  DWORD v2; // eax@2
  HANDLE result; // eax@4

  if ( dwDesiredAccess & 0x40000000 )
    v2 = 2;
  else
    v2 = 3;
  result = CreateFileA(lpFileName, dwDesiredAccess, 1u, 0, v2, 0, 0);
  if ( result == (HANDLE)-1 )
    result = 0;
  return result;
}

//----- (006185A0) --------------------------------------------------------  // acclient.c:571416
int __cdecl Get_Scan(struct _STATE *a1, struct _SCAN *a2, struct _JPEG_PROPERTIES *a3)
{
  int result; // eax@2
  int v4; // edx@5
  _SCAN_COMPONENT *v5; // edi@6
  int v6; // ebx@6

  if ( a3->needframe )
  {
    result = -19;
  }
  else
  {
    result = DP_Parse_SOS(a3, a1, &a3->jframe, a2);
    if ( !result )
    {
      a1->Prog_EndOfBlock_Run = 0;
      v4 = 0;
      if ( a2->ncomps > 0 )
      {
        v5 = a2->comps;
        v6 = 0;
        while ( 1 )
        {
          if ( !v5[v6].dc_table || !v5[v6].ac_table )
            return -17;
          if ( !v5[v6].quant_table )
            break;
          ++v6;
          ++v4;
          if ( v4 >= a2->ncomps )
            return result;
        }
        result = -18;
      }
    }
  }
  return result;
}

//----- (00618650) --------------------------------------------------------  // acclient.c:571457
signed int __cdecl IJL_Decode(struct _JPEG_PROPERTIES *a1)
{
  struct _JPEG_PROPERTIES *v1; // esi@1
  char v2; // bl@1
  struct _STATE *v3; // ebp@1
  void *v4; // eax@1
  _SCAN *v5; // eax@1
  int v6; // edx@2
  _IJLIOTYPE v7; // eax@6
  _IJLIOTYPE v8; // eax@20
  signed int v9; // edi@22
  int v10; // eax@32
  struct _SCAN *v11; // ebp@33
  int v12; // edx@39
  int v13; // eax@39
  int v14; // edi@39
  _FRAME_COMPONENT *v15; // ecx@40
  int v16; // edi@43
  void *v17; // eax@44
  _SAMPLING_STATE *v18; // edx@45
  signed int v19; // eax@47
  _SCAN *v20; // edx@51
  int v21; // edx@56
  _IJLIOTYPE v22; // edx@73
  signed int v23; // eax@107
  int v24; // eax@110
  void *v26; // eax@135
  struct _STATE *v27; // ecx@136
  _IJLIOTYPE v28; // edx@137
  int v29; // ecx@143
  int v30; // edx@147
  int v31; // ecx@148
  int v32; // edi@148
  int v33; // ecx@158
  int v34; // edx@161
  int v35; // eax@161
  int v36; // edi@161
  _FRAME_COMPONENT *v37; // ecx@162
  void *v38; // eax@165
  _IJLIOTYPE v39; // eax@185
  int v40; // eax@190
  void *v41; // edx@191
  int v42; // [sp+10h] [bp-24h]@1
  int v43; // [sp+14h] [bp-20h]@68
  struct _STATE *v44; // [sp+18h] [bp-1Ch]@33
  void *v45; // [sp+1Ch] [bp-18h]@1
  struct _SCAN *v46; // [sp+20h] [bp-14h]@31

  v1 = a1;
  v2 = 0;
  v3 = &a1->state;
  v4 = a1->state.ctx;
  v42 = 0;
  v45 = v4;
  v5 = a1->jscan;
  if ( !v5 || (v6 = a1->jinterleaveType, v6 == 1) )
  {
    if ( v5 )
    {
      if ( v5->curxMCU )
      {
        v6 = a1->jinterleaveType;
      }
      else if ( v5->curyMCU )
      {
        v6 = a1->jinterleaveType;
      }
      else
      {
        DB_Begin(&a1->state);
        v5 = a1->jscan;
        v6 = a1->jinterleaveType;
      }
    }
    else
    {
      DB_Begin(&a1->state);
      v5 = a1->jscan;
      v6 = a1->jinterleaveType;
    }
  }
  if ( v6 == 1 && (!v5 || !v5->curxMCU && !v5->curyMCU) )
  {
    a1->state.bit_buffer_64 = 0i64;
    v39 = a1->iotype;
    if ( a1->iotype == 2 || v39 == 6 || v39 == 14 || v39 == 18 || v39 == 16 )
    {
      v41 = a1->state.file;
      a1->state.entropy_bytes_processed = 0;
      if ( !ownSeekFile(v41, 0, 0) )
        return -23;
      v9 = Buffer_Read_Bytes(v3);
      if ( v9 )
        return v9;
      v5 = a1->jscan;
    }
    else
    {
      v40 = a1->state.entropy_buf_maxsize;
      a1->state.cur_entropy_ptr = a1->JPGBytes;
      a1->state.entropy_bytes_processed = 0;
      a1->state.entropy_bytes_left = v40;
      v5 = a1->jscan;
    }
  }
  if ( v5 )
    v2 = 1;
  v7 = a1->iotype;
  if ( a1->iotype != 6
    && v7 != 7
    && v7 != 14
    && v7 != 15
    && v7 != 17
    && v7 != 16
    && v7 != 19
    && v7 != 18
    && !a1->roi.top
    && !a1->roi.bottom
    && !a1->roi.right
    && !a1->roi.left )
    a1->state.entropy_bytes_processed = 0;
  if ( a1->needframe || (v9 = Set_Decode_Fast_Path(a1)) == 0 )
  {
    v8 = a1->iotype;
    if ( a1->iotype == 1 || v8 == IJL_JFILE_READPARAMS || v8 == 5 || v8 == 4 || v8 == 21 || v8 == 20 )
    {
      v9 = DP_Get_Next_Marker(v3, (enum IJL_MARKER *)&v42);
      if ( v9 )
        return v9;
      if ( v42 != 216 )
        return -13;
    }
    if ( !a1->progressive_found )
    {
      a1->jframe.SeenAllACScans = 0;
      a1->jframe.SeenAllDCScans = 0;
    }
    v46 = a1->jscan;
    if ( !v46 || (v10 = a1->jinterleaveType, v10 == 1) && !v46->curxMCU && !v46->curyMCU )
    {
      while ( 1 )
      {
LABEL_114:
        v9 = DP_Get_Next_Marker(v3, (enum IJL_MARKER *)&v42);
        if ( v9 )
          return v9;
        v21 = v42;
        if ( v42 == 256 )
          return 0;
LABEL_59:
        switch ( v21 )
        {
          case 254:
            v9 = DP_Parse_COM(v1);
            if ( !v9 )
              continue;
            return v9;
          case 238:
            v9 = DP_Parse_APP14(v1);
            if ( !v9 )
            {
              if ( v1->needframe )
                continue;
              v9 = Set_Decode_Fast_Path(v1);
              if ( !v9 )
                continue;
            }
            return v9;
          case 224:
            if ( v1->iotype == 6 )
              continue;
            v9 = DP_Parse_APP0(v1);
            if ( !v9 )
              continue;
            return v9;
          case 221:
            v9 = DP_Parse_DRI(v3, &v43);
            if ( v9 )
              return v9;
            v1->jframe.restart_interv = v43;
            continue;
          case 219:
            v9 = DP_Parse_DQT(v1, v3, v1->dcttype);
            if ( !v9 )
              continue;
            return v9;
          case 218:
            v44 = v3;
            v11 = v1->jscan;
            goto LABEL_34;
          case 217:
            v22 = v1->iotype;
            if ( v1->iotype == 5 || v22 == 4 || v22 == 1 || v22 == IJL_JFILE_READPARAMS || v22 == 21 || v22 == 20 )
              return 0;
            if ( !v1->needframe )
            {
              if ( v1->jinterleaveType && v1->cconversion_reqd && !v1->progressive_found )
                CConvert_Image(v1);
              return v9;
            }
            v9 = DP_Get_Next_Marker(v3, (enum IJL_MARKER *)&v42);
            if ( v9 )
              return v9;
            v21 = v42;
            if ( v42 != 216 )
              return -22;
            goto LABEL_59;
          case 216:
            v1->jframe.restart_interv = 0;
            continue;
          case 207:
            return -29;
          case 206:
            return -29;
          case 205:
            return -29;
          case 203:
            return -29;
          case 202:
            return -29;
          case 201:
            return -29;
          case 200:
            return -29;
          case 199:
            return -29;
          case 198:
            return -29;
          case 197:
            return -29;
          case 196:
            v9 = DP_Parse_DHT(v1, v3);
            if ( !v9 )
              continue;
            return v9;
          case 195:
            return -29;
          case 194:
            if ( !v1->needframe )
              continue;
            goto LABEL_104;
          case 193:
            if ( v1->needframe )
              goto LABEL_104;
            continue;
          case 192:
LABEL_104:
            if ( v1->iotype == 5 || v1->iotype == 4 )
            {
              v1->state.entropy_bytes_processed -= 2;
              return 0;
            }
            v9 = DP_Parse_SOF(v3, v1);
            if ( v9 )
              return v9;
            v1->needframe = 0;
            v23 = v1->jframe.ncomps;
            if ( v23 <= 0 || v23 > 255 )
              return -14;
            v1->JPGChannels = v23;
            v24 = v1->jframe.height;
            v1->JPGWidth = v1->jframe.width;
            v1->JPGHeight = v24;
            v9 = Set_Decode_Fast_Path(v1);
            if ( v9 )
              return v9;
            break;
          default:
            v9 = DP_Skip(v3);
            if ( !v9 )
              continue;
            return v9;
          case 208:
          case 209:
          case 210:
          case 211:
          case 212:
          case 213:
          case 214:
          case 215:
            continue;
          case 256:
            return 0;
        }
      }
    }
    v44 = &a1->state;
    v11 = v46;
LABEL_34:
    if ( v11 && v2 )
    {
      v2 = 0;
      goto LABEL_37;
    }
    v26 = operator new(0x38u);
    v11 = (struct _SCAN *)v26;
    if ( !v26 )
      return -5;
    v27 = v44;
    *((_DWORD *)v26 + 7) = 0;
    *((_DWORD *)v26 + 8) = 0;
    *((_DWORD *)v26 + 9) = 0;
    *((_DWORD *)v26 + 10) = 0;
    *((_DWORD *)v26 + 11) = 0;
    *((_DWORD *)v26 + 12) = 0;
    v9 = Get_Scan(v27, (struct _SCAN *)v26, v1);
    if ( v9 )
    {
      v46 = v11;
      operator delete(v11);
      return v9;
    }
    v28 = v1->iotype;
    if ( v1->iotype == 1 )
    {
      v46 = v11;
    }
    else if ( v28 )
    {
      switch ( v28 )
      {
        case 5u:
          v46 = v11;
          break;
        case 4u:
          v46 = v11;
          break;
        case 0x15u:
          v46 = v11;
          break;
        default:
          if ( v28 != 20 )
          {
            v29 = v11->ncomps;
            v11->restart_interv = v1->jframe.restart_interv;
            v1->jinterleaveType = v29 < v1->jframe.ncomps && !v1->progressive_found;
            Set_Decode_Fast_Path(v1);
            v30 = v11->start_spec;
            if ( v30 )
            {
              v31 = v1->progressive_found;
              v32 = v11->approx_low;
            }
            else if ( v11->end_spec == 63 )
            {
              if ( v11->approx_high )
              {
                v31 = v1->progressive_found;
                v32 = v11->approx_low;
              }
              else
              {
                v32 = v11->approx_low;
                if ( v32 )
                {
                  v31 = v1->progressive_found;
                }
                else
                {
                  v31 = v1->progressive_found;
                  if ( !v31 )
                    goto LABEL_37;
                }
              }
            }
            else
            {
              v31 = v1->progressive_found;
              v32 = v11->approx_low;
            }
            if ( v30 || v11->end_spec )
            {
              if ( !v32 && v11->end_spec == 63 )
                ++v1->jframe.SeenAllACScans;
            }
            else if ( !v32 )
            {
              v1->jframe.SeenAllDCScans += v11->ncomps;
            }
            v33 = v31 + 1;
            v1->progressive_found = v33;
            if ( v33 == 1 )
            {
              v34 = 0;
              v35 = 0;
              v36 = v1->jframe.ncomps;
              if ( v36 > 0 )
              {
                v37 = v1->jframe.comps;
                do
                {
                  ++v35;
                  v34 += v37->vsampling * v37->hsampling;
                  ++v37;
                }
                while ( v35 < v36 );
                v1 = a1;
              }
              v38 = operator new(2 * v1->numyMCUs * v1->numxMCUs * (v34 << 6));
              v1->coef_buffer = (__int16 *)v38;
              if ( !v38 )
              {
                v46 = v11;
                operator delete(v11->comps);
                v11->comps = 0;
                operator delete(v11);
                v1->jscan = 0;
                return -5;
              }
            }
LABEL_37:
            if ( v1->jinterleaveType == 1 && !v1->progressive_found )
              v1->jframe.SeenAllACScans += v11->ncomps;
            v1->jscan = v11;
            if ( v1->upsampling_type == 1 )
            {
              v12 = 0;
              v13 = 0;
              v14 = v1->jframe.ncomps;
              if ( v14 > 0 )
              {
                v15 = v1->jframe.comps;
                do
                {
                  ++v13;
                  v12 += v15->vsampling * v15->hsampling;
                  ++v15;
                }
                while ( v13 < v14 );
                v1 = a1;
              }
              v16 = v1->numxMCUs * (v12 << 6) + (v12 << 7);
              if ( !v1->sampling_state_ptr )
              {
                v17 = operator new(0x14u);
                v1->sampling_state_ptr = (_SAMPLING_STATE *)v17;
                if ( !v17 )
                  return -5;
                v1->sampling_state_ptr->top_row = (__int16 *)operator new(8 * v16);
                v18 = v1->sampling_state_ptr;
                if ( !v18->top_row )
                {
                  operator delete(v1->sampling_state_ptr);
                  v1->sampling_state_ptr = 0;
                  return -5;
                }
                v18->cur_row = &v18->top_row[v16];
                v1->sampling_state_ptr->bottom_row = &v1->sampling_state_ptr->cur_row[v16];
                v1->sampling_state_ptr->last_row = &v1->sampling_state_ptr->bottom_row[v16];
                v1->sampling_state_ptr->cur_row_number = 0;
              }
            }
            v19 = Decode_Scan((enum IJL_MARKER *)&v42, v44, v11, v1);
            v9 = v19;
            if ( v19 == 1 )
            {
              v46 = v11;
            }
            else
            {
              if ( v19 != 2 )
              {
                if ( !v1->progressive_found )
                  v1->state.cur_scan_comp += v11->ncomps;
                v20 = v1->jscan;
                if ( v20 && !v19 )
                {
                  operator delete(v20->comps);
                  v1->jscan->comps = 0;
                  operator delete(v1->jscan);
                  v1->jscan = 0;
                }
                else if ( v19 < 0 )
                {
                  return v9;
                }
                v21 = v42;
                if ( v42 )
                {
                  v3 = v44;
                  goto LABEL_59;
                }
                v3 = v44;
                goto LABEL_114;
              }
              v46 = v11;
            }
            if ( !v1->progressive_found || v1->interrupt )
            {
              if ( v1->jinterleaveType != 1 || v19 != 2 )
              {
                v1->jscan = v11;
                v1->interrupt = 0;
              }
              else
              {
                if ( v1->cconversion_reqd )
                  CConvert_Image(v1);
                operator delete(v11->comps);
                v11->comps = 0;
                operator delete(v11);
                v1->jscan = 0;
              }
            }
            else
            {
              ++v1->jframe.SeenAllACScans;
              v1->jscan = v11;
              v1->interrupt = 0;
            }
            return v9;
          }
          v46 = v11;
          break;
      }
    }
    else
    {
      v46 = v11;
    }
    v1->state.entropy_bytes_processed -= *(_DWORD *)v45;
    operator delete(v11);
    return 0;
  }
  return v9;
}

//----- (00619F00) --------------------------------------------------------  // acclient.c:572698
int __cdecl Encode_Frame_Init(struct _JPEG_PROPERTIES *a1)
{
  int v1; // esi@1
  void *v2; // ebp@1
  int result; // eax@1
  _IJLIOTYPE v4; // edx@2
  _DCTTYPE v5; // edx@8
  int v6; // ecx@9
  int v7; // ecx@11
  int v8; // ecx@12
  int v9; // edi@20
  int v10; // eax@20
  int i; // esi@20
  __int16 *v12; // eax@25
  _DCTTYPE v13; // eax@25
  _HUFFMAN_TABLE *v14; // edi@31
  _HUFFMAN_TABLE *v15; // ebp@31
  int v16; // esi@31
  _IJL_COLOR v17; // eax@36
  enum _IJLERR v18; // [sp+14h] [bp-20h]@20
  void *v19; // [sp+18h] [bp-1Ch]@20
  int v20; // [sp+20h] [bp-14h]@31

  v1 = (int)&a1->state;
  v2 = a1->state.ctx;
  (*((void (__cdecl **)(_STATE *, char *, int))v2 + 22))(&a1->state, a1->JPGBytes, a1->JPGSizeBytes);
  result = EP_Write_SOI(&a1->state);
  if ( result )
    return result;
  v4 = a1->iotype;
  if ( a1->iotype != 8 && v4 != 9 && v4 != 10 && v4 != 11 )
    goto LABEL_6;
  v17 = a1->JPGColor;
  if ( v17 == 1 || v17 == 5 )
  {
    result = EP_Write_APP14(0, a1);
    if ( result )
      return result;
  }
  else if ( v17 == 6 )
  {
    result = EP_Write_APP14(2, a1);
    if ( result )
      return result;
  }
  else
  {
    result = EP_Write_APP0(a1);
    if ( result )
      return result;
  }
  result = EP_Write_COM(a1);
  if ( !result )
  {
    result = ownEncoderWriteJPEGTables(a1);
    if ( !result )
    {
      v4 = a1->iotype;
LABEL_6:
      if ( v4 != 12 && v4 != 13 )
        goto LABEL_8;
      v9 = 0;
      v18 = result;
      v10 = a1->maxquantindex;
      v19 = v2;
      for ( i = 0; i < v10; ++i )
      {
        if ( !a1->jEncFmtQuant[i] && a1->rawquanttables[i].quantizer )
        {
          v12 = a1->jFmtQuant[v9].elements;
          a1->jEncFmtQuant[i] = v12;
          Scale_Char_Matrix(a1->jquality, (int)a1->rawquanttables[i].quantizer, (int)v12);
          v13 = a1->dcttype;
          if ( v13 )
          {
            if ( v13 != 1 )
              return -8;
            FillEncoderQuantTable_IPP((int)a1->jEncFmtQuant[i]);
            v10 = a1->maxquantindex;
          }
          else
          {
            FillEncoderQuantTable_AAN((int)a1->jEncFmtQuant[i]);
            v10 = a1->maxquantindex;
          }
        }
        ++v9;
      }
      result = v18;
      v1 = (int)&a1->state;
      if ( 2 * a1->maxhuffindex <= 0 )
      {
LABEL_8:
        v5 = a1->dcttype;
        if ( v5 )
        {
          if ( v5 == 1 )
          {
            v7 = *((_DWORD *)v2 + 64);
            *((_DWORD *)v2 + 17) = *((_DWORD *)v2 + 8);
            *((_DWORD *)v2 + 65) = v7;
          }
          else
          {
            v8 = *((_DWORD *)v2 + 63);
            *((_DWORD *)v2 + 17) = *((_DWORD *)v2 + 7);
            *((_DWORD *)v2 + 65) = v8;
          }
        }
        else
        {
          v6 = *((_DWORD *)v2 + 63);
          *((_DWORD *)v2 + 17) = *((_DWORD *)v2 + 7);
          *((_DWORD *)v2 + 65) = v6;
        }
        if ( a1->iotype != 11 && a1->iotype != 10 || (result = EP_Write_EOI((struct _STATE *)v1)) == 0 )
        {
          if ( a1->state.file )
            result = Flush_Buffer_To_File(v1);
        }
      }
      else
      {
        v14 = a1->jFmtDcHuffman;
        v20 = 0;
        v15 = a1->jFmtAcHuffman;
        v16 = 0;
        while ( 1 )
        {
          a1->jEncFmtDcHuffman[a1->rawhufftables[v16].ident] = v14;
          a1->jEncFmtAcHuffman[a1->rawhufftables[v16 + 1].ident] = v15;
          result = BuildEncoderHuffmanTable(
                     (int)a1->rawhufftables[v16].bits,
                     (int)a1->rawhufftables[v16].vals,
                     (int)&a1->jEncFmtDcHuffman[a1->rawhufftables[v16].ident]->huff_class);
          if ( result )
            break;
          result = BuildEncoderHuffmanTable(
                     (int)a1->rawhufftables[v16 + 1].bits,
                     (int)a1->rawhufftables[v16 + 1].vals,
                     (int)&a1->jEncFmtAcHuffman[a1->rawhufftables[v16 + 1].ident]->huff_class);
          if ( result )
            break;
          v16 += 2;
          v15 += 2;
          v14 += 2;
          v20 += 2;
          if ( v20 >= 2 * a1->maxhuffindex )
          {
            v2 = v19;
            v1 = (int)&a1->state;
            goto LABEL_8;
          }
        }
      }
      return result;
    }
  }
  return result;
}

//----- (0061A250) --------------------------------------------------------  // acclient.c:572860
int __cdecl Encode_Frame(struct _JPEG_PROPERTIES *a1)
{
  int v1; // ebp@0
  struct _JPEG_PROPERTIES *v2; // ebx@1
  struct _STATE *v3; // ecx@1
  struct _SCAN *v4; // edx@1
  signed int v5; // eax@4
  void *v6; // edx@8
  void *v7; // eax@9
  _SCAN *v8; // ecx@11
  void *v9; // eax@13
  void *v11; // eax@27
  int v12; // ebx@29
  void *v13; // eax@29
  void *v14; // esi@29
  int v15; // ebx@30
  int v16; // ecx@32
  struct _JPEG_PROPERTIES *v17; // ebx@35
  int v18; // edx@35
  void *v19; // [sp+0h] [bp-38h]@1
  int v20; // [sp+4h] [bp-34h]@1
  struct _STATE *v21; // [sp+8h] [bp-30h]@1
  int v22; // [sp+Ch] [bp-2Ch]@30
  struct _JPEG_PROPERTIES *v23; // [sp+1Ch] [bp-1Ch]@31
  CPPEH_RECORD ms_exc; // [sp+20h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v19;
  ms_exc.registration.TryLevel = 0;
  v20 = 0;
  v2 = a1;
  v3 = &a1->state;
  v21 = &a1->state;
  v19 = 0;
  v4 = a1->jscan;
  if ( v4 )
  {
    v19 = a1->jscan;
    goto LABEL_3;
  }
  v11 = operator new(0x38u);
  v19 = v11;
  if ( !v11 )
  {
    v20 = -5;
    goto LABEL_17;
  }
  v12 = a1->JPGChannels;
  *(_DWORD *)v11 = v12;
  *((_DWORD *)v11 + 1) = 0;
  *((_DWORD *)v11 + 2) = 1;
  *((_DWORD *)v11 + 3) = 63;
  *((_DWORD *)v11 + 4) = 0;
  *((_DWORD *)v11 + 5) = 0;
  *((_DWORD *)v11 + 6) = 0;
  *((_DWORD *)v11 + 7) = 0;
  *((_DWORD *)v11 + 8) = 0;
  *((_DWORD *)v11 + 9) = 0;
  *((_DWORD *)v11 + 10) = 0;
  *((_DWORD *)v11 + 11) = 0;
  *((_DWORD *)v11 + 12) = 0;
  v13 = operator new(24 * v12);
  v14 = v19;
  *((_DWORD *)v19 + 13) = v13;
  if ( !v13 )
  {
    v20 = -5;
    goto LABEL_17;
  }
  v15 = 0;
  v22 = 0;
  if ( *(_DWORD *)v14 <= 0 )
  {
    v23 = a1;
  }
  else
  {
    v23 = a1;
    while ( 1 )
    {
      v16 = 24 * v15;
      *(_DWORD *)((char *)v13 + v16) = v15;
      *(_DWORD *)(v16 + *((_DWORD *)v14 + 13) + 4) = v23->jframe.comps[v15].hsampling;
      *(_DWORD *)(v16 + *((_DWORD *)v14 + 13) + 8) = v23->jframe.comps[v15].vsampling;
      *(_DWORD *)(v16 + *((_DWORD *)v14 + 13) + 12) = 0;
      *(_DWORD *)(v16 + *((_DWORD *)v14 + 13) + 16) = 0;
      *(_DWORD *)(v16 + *((_DWORD *)v14 + 13) + 20) = 0;
      ++v15;
      v22 = v15;
      if ( v15 >= *(_DWORD *)v14 )
        break;
      v13 = (void *)*((_DWORD *)v14 + 13);
    }
  }
  v20 = EP_Write_SOF(v21, &v23->jframe);
  if ( !v20 )
  {
    v17 = a1;
    v18 = a1->jframe.restart_interv;
    if ( v18 )
    {
      v20 = EP_Write_DRI(v18, v21);
      if ( v20 )
        goto LABEL_17;
      v17 = a1;
    }
    v20 = EP_Write_SOS(v1, v21, v17->JPGChannels, v17->HuffIdentifierDC, v17->HuffIdentifierAC);
    if ( !v20 )
    {
      v20 = Flush_Buffer_To_File((int)v21);
      if ( !v20 )
      {
        v20 = Set_Encode_Fast_Path(a1);
        if ( !v20 )
        {
          v4 = (struct _SCAN *)v19;
          v3 = v21;
          v2 = a1;
LABEL_3:
          if ( v2->jframe.restart_interv )
          {
            v5 = Encode_Scan_WRst(v2, v3, v4);
            v20 = v5;
          }
          else
          {
            v5 = Encode_Scan(v2, v3, v4);
            v20 = v5;
          }
          if ( v5 == 1 || v5 == 2 )
          {
            a1->interrupt = 0;
            a1->jscan = (_SCAN *)v19;
          }
          else if ( !v5 )
          {
            v6 = v19;
            if ( v19 )
            {
              v7 = (void *)*((_DWORD *)v19 + 13);
              if ( v7 )
              {
                operator delete(v7);
                v6 = v19;
                *((_DWORD *)v19 + 13) = 0;
              }
              operator delete(v6);
              v19 = 0;
              v8 = 0;
              a1->jscan = 0;
            }
            else
            {
              v8 = a1->jscan;
            }
            if ( v8 )
            {
              v9 = v8->comps;
              if ( v9 )
              {
                operator delete(v9);
                a1->jscan->comps = 0;
                v8 = a1->jscan;
              }
              operator delete(v8);
              a1->jscan = 0;
            }
            v20 = EP_Write_EOI(v21);
            if ( !v20 )
            {
              v20 = Flush_Buffer_To_File((int)v21);
              ms_exc.registration.TryLevel = -1;
            }
          }
          goto LABEL_17;
        }
      }
    }
  }
LABEL_17:
  if ( v20 < 0 && v19 )
  {
    if ( *((_DWORD *)v19 + 13) )
    {
      operator delete(*((void **)v19 + 13));
      *((_DWORD *)v19 + 13) = 0;
    }
    operator delete(v19);
    v19 = 0;
    a1->jscan = 0;
  }
  return v20;
}

//----- (0061B930) --------------------------------------------------------  // acclient.c:573394
signed int __cdecl Encode_Frame_P(struct _JPEG_PROPERTIES *a1)
{
  int v1; // ecx@1
  int v2; // edx@1
  int v3; // eax@1
  _FRAME_COMPONENT *v4; // edi@2
  __int16 *v5; // eax@4
  int v6; // ecx@6
  struct _SCAN *v7; // eax@8
  struct _JPEG_PROPERTIES *v8; // esi@13
  int v9; // esi@27
  signed int result; // eax@35
  struct _JPEG_PROPERTIES *v11; // edx@39
  struct _JPEG_PROPERTIES *v12; // eax@42
  int v13; // edx@42
  _RAW_DATA_TYPES_STATE *v14; // eax@44
  int v15; // ebx@46
  int v16; // edx@46
  int v17; // eax@46
  _FRAME_COMPONENT *v18; // edi@47
  int v19; // ebx@53
  int v20; // ecx@53
  int v21; // ebx@53
  int v22; // edi@55
  void *v23; // ebx@55
  int v24; // edx@55
  int v25; // esi@57
  int v26; // edi@58
  int v27; // esi@60
  _FRAME_COMPONENT *v28; // esi@61
  int v29[257]; // [sp+0h] [bp-9B0h]@1
  int v30; // [sp+404h] [bp-5ACh]@7
  int v31; // [sp+808h] [bp-1A8h]@1
  __int16 *v32; // [sp+80Ch] [bp-1A4h]@1
  struct _SCAN *v33; // [sp+810h] [bp-1A0h]@1
  struct _STATE *v34; // [sp+814h] [bp-19Ch]@1
  int v35; // [sp+818h] [bp-198h]@1
  int v36; // [sp+81Ch] [bp-194h]@1
  int v37; // [sp+820h] [bp-190h]@1
  int v38; // [sp+824h] [bp-18Ch]@4
  int v39; // [sp+828h] [bp-188h]@4
  int v40; // [sp+82Ch] [bp-184h]@4
  int v41; // [sp+830h] [bp-180h]@46
  int v42; // [sp+834h] [bp-17Ch]@46
  int v43; // [sp+838h] [bp-178h]@53
  int v44; // [sp+83Ch] [bp-174h]@54
  int v45; // [sp+840h] [bp-170h]@55
  int v46; // [sp+844h] [bp-16Ch]@57
  int i; // [sp+848h] [bp-168h]@59
  int v48; // [sp+84Ch] [bp-164h]@60
  int v49; // [sp+850h] [bp-160h]@60
  void *v50; // [sp+854h] [bp-15Ch]@60
  int v51; // [sp+858h] [bp-158h]@6
  unsigned __int8 v52; // [sp+85Ch] [bp-154h]@7
  unsigned __int8 v53; // [sp+86Ch] [bp-144h]@7
  int v54; // [sp+96Ch] [bp-44h]@11
  int v55; // [sp+97Ch] [bp-34h]@1
  int v56; // [sp+980h] [bp-30h]@54
  int v57; // [sp+984h] [bp-2Ch]@59
  int v58; // [sp+988h] [bp-28h]@57
  struct _JPEG_PROPERTIES *v59; // [sp+98Ch] [bp-24h]@44
  int *v60; // [sp+990h] [bp-20h]@56
  CPPEH_RECORD ms_exc; // [sp+998h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)v29;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v55 = (int)a1;
  v34 = &a1->state;
  v35 = 0;
  ms_exc.registration.TryLevel = 0;
  v1 = 0;
  v36 = 0;
  v2 = 0;
  v37 = 0;
  v3 = a1->jframe.ncomps;
  if ( v3 > 0 )
  {
    v4 = a1->jframe.comps;
    do
    {
      v2 += v4[v1].vsampling * v4[v1].hsampling;
      v37 = v2;
      ++v1;
      v36 = v1;
    }
    while ( v1 < v3 );
  }
  v38 = *(_DWORD *)(v55 + 124) * *(_DWORD *)(v55 + 120);
  v39 = v2 << 6;
  v40 = v38 * (v2 << 6);
  v5 = (__int16 *)operator new(2 * v38 * (v2 << 6));
  a1->coef_buffer = v5;
  if ( !v5 )
  {
    v35 = -5;
    goto LABEL_25;
  }
  if ( a1->jscan )
    goto LABEL_6;
  result = sub_61A980((int)a1, (int)&v31);
  v35 = result;
  if ( result )
    return result;
  v11 = a1;
  if ( a1->iotype != 9 && a1->iotype != 8 )
  {
    v35 = EP_Write_SOI(v34);
    if ( v35 )
      goto LABEL_25;
    v11 = a1;
  }
  v35 = EP_Write_SOF2(v34, &v11->jframe);
  if ( !v35 )
  {
    v12 = a1;
    v13 = a1->jframe.restart_interv;
    if ( v13 )
    {
      v35 = EP_Write_DRI(v13, v34);
      if ( v35 )
        goto LABEL_25;
      v12 = a1;
    }
    v35 = Set_Encode_Fast_Path(v12);
    if ( !v35 )
    {
      v59 = a1;
      v14 = a1->raw_coefs;
      if ( v14 && !v14->data_type )
      {
        v15 = 0;
        v41 = 0;
        v16 = 0;
        v42 = 0;
        v17 = v59->jframe.ncomps;
        if ( v17 > 0 )
        {
          v18 = v59->jframe.comps;
          do
          {
            v15 += v18[v16].hsampling * v18[v16].vsampling;
            v41 = v15;
            ++v16;
            v42 = v16;
          }
          while ( v16 < v17 );
        }
        v19 = v15 << 6;
        v39 = v19;
        v20 = v59->numxMCUs;
        v41 = v20 * v19;
        v55 = 0;
        v43 = 0;
        v21 = v59->numyMCUs;
        if ( v21 > 0 )
        {
          do
          {
            v56 = 0;
            v44 = 0;
            if ( v20 > 0 )
            {
              do
              {
                v22 = v39 * 2 * v56;
                v23 = (char *)v59->coef_buffer + v41 * 2 * v55 + v22;
                v32 = (__int16 *)((char *)v59->coef_buffer + v41 * 2 * v55 + v22);
                v24 = 0;
                v45 = 0;
                if ( v17 > 0 )
                {
                  v60 = &v59->jframe.comps->ident;
                  do
                  {
                    v58 = 0;
                    v46 = 0;
                    v25 = v60[4 * v24 + 2];
                    if ( v25 > 0 )
                    {
                      v26 = v60[4 * v24 + 1];
                      do
                      {
                        v57 = 0;
                        for ( i = 0; i < v26; v57 = i )
                        {
                          v60 = &v59->raw_coefs->data_type;
                          v27 = 16 * v57
                              + 16 * v56 * v26
                              + v26 * (v58 << 7) * v20
                              + v60[v24 + 1]
                              + v26 * v20 * (v55 << 7) * v25;
                          v48 = v27;
                          v49 = 0;
                          v50 = v23;
                          do
                          {
                            __g_memcpy(v23, (void *)v27, 0x10u);
                            ++v49;
                            v59 = a1;
                            v20 = a1->numxMCUs;
                            v28 = a1->jframe.comps;
                            v60 = (int *)v28;
                            v24 = v45;
                            v58 = 16 * v45;
                            v26 = v28[v45].hsampling;
                            v27 = v48 + v26 * 16 * v20;
                            v48 += v26 * 16 * v20;
                            v23 = v32 + 8;
                            v32 += 8;
                          }
                          while ( v49 < 8 );
                          v55 = v43;
                          v56 = v44;
                          v25 = *(int *)((char *)v60 + v58 + 8);
                          v58 = v46;
                          ++i;
                        }
                        ++v58;
                        v46 = v58;
                      }
                      while ( v58 < v25 );
                      v17 = v59->jframe.ncomps;
                    }
                    ++v24;
                    v45 = v24;
                  }
                  while ( v24 < v17 );
                }
                ++v56;
                v44 = v56;
              }
              while ( v56 < v20 );
              v21 = v59->numyMCUs;
            }
            ++v55;
            v43 = v55;
          }
          while ( v55 < v21 );
        }
LABEL_6:
        v6 = 0;
        v36 = 0;
        v51 = 0;
        if ( v31 <= 0 )
        {
LABEL_31:
          v35 = EP_Write_EOI(v34);
          if ( !v35 )
          {
            v35 = Flush_Buffer_To_File((int)v34);
            if ( !v35 )
              ms_exc.registration.TryLevel = -1;
          }
        }
        else
        {
          while ( 1 )
          {
            v33 = &a1->jscan[v6];
            __g_memzero(v29, 0x404u);
            __g_memzero(&v30, 0x404u);
            __g_memzero(&v52, 0x10u);
            __g_memzero(&v53, 0x100u);
            v35 = Gather_statistics(a1, v34, v33, (int (*const )[257])v29);
            if ( v35 )
              break;
            v7 = v33;
            if ( v33->start_spec || v33->end_spec )
            {
              if ( v33->comps->comp )
              {
                v54 = 1;
                Make_optimal_huff_table(&v30, &v52, &v53);
                v35 = BuildEncoderHuffmanTable((int)&v52, (int)&v53, (int)&a1->jFmtAcHuffman[1]);
                if ( v35 )
                  goto LABEL_25;
                a1->jEncFmtAcHuffman[1] = &a1->jFmtAcHuffman[1];
                v35 = EP_Write_DHT_Ex(v34, &v52, &v53, 1, 1);
                if ( v35 )
                  goto LABEL_25;
                v7 = v33;
                v8 = a1;
              }
              else
              {
                v54 = 0;
                Make_optimal_huff_table(v29, &v52, &v53);
                v35 = BuildEncoderHuffmanTable((int)&v52, (int)&v53, (int)a1->jFmtAcHuffman);
                if ( v35 )
                  goto LABEL_25;
                a1->jEncFmtAcHuffman[0] = a1->jFmtAcHuffman;
                v35 = EP_Write_DHT_Ex(v34, &v52, &v53, 1, 0);
                if ( v35 )
                  goto LABEL_25;
                v7 = v33;
                v8 = a1;
              }
            }
            else if ( v33->approx_high )
            {
              v8 = a1;
            }
            else
            {
              v33->dc_diff[0] = 0;
              v7->dc_diff[1] = 0;
              v7->dc_diff[2] = 0;
              v7->dc_diff[3] = 0;
              v54 = 0;
              Make_optimal_huff_table(v29, &v52, &v53);
              v35 = BuildEncoderHuffmanTable((int)&v52, (int)&v53, (int)a1->jFmtDcHuffman);
              if ( v35 )
                goto LABEL_25;
              a1->jEncFmtDcHuffman[0] = a1->jFmtDcHuffman;
              v35 = EP_Write_DHT_Ex(v34, &v52, &v53, 0, 0);
              if ( v35 )
                goto LABEL_25;
              v8 = a1;
              if ( a1->JPGChannels == 1 )
              {
                v7 = v33;
              }
              else
              {
                __g_memzero(&v52, 0x10u);
                __g_memzero(&v53, 0x100u);
                v54 = 1;
                Make_optimal_huff_table(&v30, &v52, &v53);
                v35 = BuildEncoderHuffmanTable((int)&v52, (int)&v53, (int)&a1->jFmtDcHuffman[1]);
                if ( v35 )
                  goto LABEL_25;
                a1->jEncFmtDcHuffman[1] = &a1->jFmtDcHuffman[1];
                v35 = EP_Write_DHT_Ex(v34, &v52, &v53, 0, 1);
                if ( v35 )
                  goto LABEL_25;
                v7 = v33;
                v8 = a1;
              }
            }
            v35 = EP_Write_SOS_Ex(
                    v34,
                    v7,
                    (unsigned __int8 *)v8->HuffIdentifierDC,
                    (unsigned __int8 *)v8->HuffIdentifierAC);
            if ( v35 )
              goto LABEL_25;
            v35 = Encode_Scan_P(a1, v34, v33);
            if ( v35 < 0 )
              goto LABEL_25;
            ++v51;
            v6 = v36 + 1;
            v36 = v6;
            if ( v6 >= v31 )
              goto LABEL_31;
          }
        }
        goto LABEL_25;
      }
      v35 = Fill_coeffs_buffer(v59);
      if ( !v35 )
        goto LABEL_6;
    }
  }
LABEL_25:
  if ( a1->jscan )
  {
    v36 = 0;
    if ( v31 > 0 )
    {
      do
      {
        operator delete(a1->jscan[v36].comps);
        v9 = v36 + 1;
        a1->jscan[v36].comps = 0;
        v36 = v9;
      }
      while ( v9 < v31 );
    }
    operator delete(a1->jscan);
    a1->jscan = 0;
  }
  return v35;
}
// 8F75A4: using guessed type void (__cdecl *__g_memzero)(void *, unsigned int);
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);

//----- (0061F930) --------------------------------------------------------  // acclient.c:576710
signed int __cdecl Fill_Bit_Buffer(struct _STATE *a1, int a2)
{
  int v2; // edx@2
  int v3; // edi@4
  char *v4; // eax@5
  char *v5; // edx@5
  int v6; // edi@5
  signed int v7; // eax@5
  int v8; // ecx@5
  int v9; // ecx@5
  int v10; // edi@6
  signed int result; // eax@7
  int v12; // eax@9
  int v13; // edx@12
  int v14; // eax@12

  if ( a1->bitbuf_bits_valid >= 25 )
  {
LABEL_7:
    result = 0;
  }
  else
  {
    v2 = a1->bitbuf_bits_valid;
    while ( 1 )
    {
      if ( a1->unread_marker )
      {
        v14 = v2;
        v13 = a2;
        goto LABEL_13;
      }
      v3 = a1->entropy_bytes_left;
      if ( v3 <= 0 )
      {
        if ( !a1->file )
          return 0;
        result = Buffer_Read_Bytes(a1);
        if ( result )
          return result;
        v3 = a1->entropy_bytes_left;
      }
      v4 = a1->cur_entropy_ptr;
      v5 = v4 + 1;
      v6 = v3 - 1;
      a1->cur_entropy_ptr = v4 + 1;
      v7 = (unsigned __int8)*v4;
      v8 = a1->entropy_bytes_processed;
      a1->entropy_bytes_left = v6;
      v9 = v8 + 1;
      a1->entropy_bytes_processed = v9;
      if ( v7 == 255 )
        break;
LABEL_6:
      v10 = a1->bit_buffer_64 >> 24;
      LODWORD(a1->bit_buffer_64) = v7 | (LODWORD(a1->bit_buffer_64) << 8);
      v2 = a1->bitbuf_bits_valid + 8;
      HIDWORD(a1->bit_buffer_64) = v10;
      a1->bitbuf_bits_valid = v2;
      if ( v2 >= 25 )
        goto LABEL_7;
    }
    do
    {
      if ( v6 <= 0 )
      {
        if ( !a1->file )
          return -21;
        result = Buffer_Read_Bytes(a1);
        if ( result )
          return result;
        v6 = a1->entropy_bytes_left;
        v5 = a1->cur_entropy_ptr;
        v9 = a1->entropy_bytes_processed;
      }
      v12 = (unsigned __int8)*v5++;
      --v6;
      a1->cur_entropy_ptr = v5;
      ++v9;
      a1->entropy_bytes_left = v6;
      a1->entropy_bytes_processed = v9;
    }
    while ( v12 == 255 );
    if ( !v12 )
    {
      v7 = 255;
      goto LABEL_6;
    }
    v13 = a2;
    a1->unread_marker = v12;
    v14 = a1->bitbuf_bits_valid;
LABEL_13:
    if ( v14 >= v13 )
      goto LABEL_7;
    result = 100;
  }
  return result;
}

//----- (0061FE60) --------------------------------------------------------  // acclient.c:577006
int __cdecl Decode_Block_Skip_M5(struct _STATE *a1, struct _HUFFMAN_TABLE *a2, struct _HUFFMAN_TABLE *a3, __int16 *a4)
{
  return own_decode_block_skip_m5((int)a2, (int)a1, (unsigned int)a2, (unsigned int)a3, (signed int)a4);
}

//----- (0061FEA0) --------------------------------------------------------  // acclient.c:577012
signed int __cdecl Decode_Block_Thumb_PX(struct _STATE *a1, struct _HUFFMAN_TABLE *a2, struct _HUFFMAN_TABLE *a3, __int16 *a4, __int16 *a5)
{
  signed int result; // eax@1
  int v6; // eax@5
  bool v7; // zf@5
  bool v8; // sf@5
  unsigned __int8 v9; // of@5
  int v10; // eax@6
  __int16 v11; // ax@8
  int v12; // esi@10
  int v13; // edx@12
  int v14; // eax@12
  int v15; // [sp+10h] [bp-14h]@1

  result = sub_61FB60(a1, (int)&v15, (int)a2);
  if ( result )
  {
    if ( result >= 0 )
      result = 0;
    return result;
  }
  if ( v15 )
  {
    v6 = v15 & 0xF;
    v9 = __OFSUB__(v15 & 0xF, a1->bitbuf_bits_valid);
    v7 = (v15 & 0xF) == a1->bitbuf_bits_valid;
    v8 = (v15 & 0xF) - a1->bitbuf_bits_valid < 0;
    v15 &= 0xFu;
    if ( !((unsigned __int8)(v8 ^ v9) | v7) )
    {
      result = Fill_Bit_Buffer(a1, v6);
      if ( result )
      {
        if ( result >= 0 )
          result = 0;
        return result;
      }
      v6 = v15;
    }
    v10 = GET_BITS(a1, v6);
    if ( !(v10 & (1 << (v15 - 1))) )
      v10 += *(_DWORD *)&lowest_coef[2 * v15];
    v11 = *a4 + v10;
    *a4 = v11;
  }
  else
  {
    v11 = *a4;
  }
  *a5 = v11;
  v12 = 63;
  while ( 1 )
  {
    result = sub_61FB60(a1, (int)&v15, (int)a3);
    if ( result )
      break;
    v13 = (v15 >> 4) & 0xF;
    v14 = v15 & 0xF;
    if ( v15 & 0xF )
    {
      v15 &= 0xFu;
      v12 = v12 - v13 - 1;
      if ( v14 > a1->bitbuf_bits_valid )
      {
        result = Fill_Bit_Buffer(a1, v14);
        if ( result )
        {
          if ( result >= 0 )
            result = 0;
          return result;
        }
        v14 = v15;
      }
      GET_BITS(a1, v14);
    }
    else
    {
      if ( v13 != 15 )
        return 0;
      v15 &= 0xFu;
      v12 -= 16;
    }
    if ( v12 <= 0 )
      return 0;
  }
  if ( result >= 0 )
    result = 0;
  return result;
}

//----- (00620030) --------------------------------------------------------  // acclient.c:577103
signed int __cdecl Decode_Block_Prog_DC(struct _STATE *a1, struct _HUFFMAN_TABLE *a2, __int16 *a3, __int16 *a4, int a5)
{
  signed int result; // eax@1
  int v6; // eax@3
  bool v7; // zf@3
  bool v8; // sf@3
  unsigned __int8 v9; // of@3
  int v10; // eax@4
  __int16 v11; // dx@6
  int v12; // eax@6
  int v13; // [sp+10h] [bp-14h]@1

  v13 = 0;
  result = sub_61FB60(a1, (int)&v13, (int)a2);
  if ( result )
  {
    if ( result >= 0 )
      result = 0;
  }
  else
  {
    if ( !v13 )
    {
      v12 = *a4;
LABEL_7:
      *a3 = v12 << a5;
      return 0;
    }
    v6 = v13 & 0xF;
    v9 = __OFSUB__(v13 & 0xF, a1->bitbuf_bits_valid);
    v7 = (v13 & 0xF) == a1->bitbuf_bits_valid;
    v8 = (v13 & 0xF) - a1->bitbuf_bits_valid < 0;
    v13 &= 0xFu;
    if ( (unsigned __int8)(v8 ^ v9) | v7 )
    {
LABEL_4:
      v10 = GET_BITS(a1, v6);
      if ( !(v10 & (1 << (v13 - 1))) )
        v10 += *(_DWORD *)&lowest_coef[2 * v13];
      v11 = v10 + *a4;
      v12 = v11;
      *a4 = v11;
      goto LABEL_7;
    }
    result = Fill_Bit_Buffer(a1, v6);
    if ( !result )
    {
      v6 = v13;
      goto LABEL_4;
    }
    if ( result >= 0 )
      result = 0;
  }
  return result;
}

//----- (00620110) --------------------------------------------------------  // acclient.c:577160
signed int __cdecl Decode_Block_Prog_DC_SA(struct _STATE *a1, __int16 *a2, int a3)
{
  signed int v3; // ebx@1
  signed int result; // eax@4

  v3 = 1 << a3;
  if ( a1->bitbuf_bits_valid <= 0 && (result = Fill_Bit_Buffer(a1, 1)) != 0 )
  {
    if ( result >= 0 )
      result = 0;
  }
  else
  {
    if ( GET_BITS(a1, 1) )
      *a2 |= v3;
    result = 0;
  }
  return result;
}

//----- (00620180) --------------------------------------------------------  // acclient.c:577181
signed int __cdecl Decode_Block_Prog_AC(struct _STATE *a1, __int16 *a2, struct _HUFFMAN_TABLE *a3, int a4, int a5, int a6)
{
  int v6; // ebx@1
  int v7; // ecx@1
  signed int result; // eax@3
  int v9; // edi@6
  int v10; // edx@6
  int v11; // ebx@7
  int v12; // eax@8
  int v13; // eax@15
  bool v14; // zf@16
  bool v15; // sf@16
  unsigned __int8 v16; // of@16
  int v17; // [sp+10h] [bp-14h]@5

  v6 = a4;
  v7 = a1->Prog_EndOfBlock_Run;
  if ( v7 > 0 )
  {
    a1->Prog_EndOfBlock_Run = v7 - 1;
    return 0;
  }
  if ( a4 > a5 )
    return 0;
  while ( 1 )
  {
    result = sub_61FB60(a1, (int)&v17, (int)a3);
    if ( result )
      break;
    v9 = v17 >> 4;
    v10 = v17 & 0xF;
    if ( v17 & 0xF )
    {
      v17 &= 0xFu;
      v11 = v9 + v6;
      if ( v10 > a1->bitbuf_bits_valid )
      {
        result = Fill_Bit_Buffer(a1, v10);
        if ( result )
        {
          if ( result >= 0 )
            result = 0;
          return result;
        }
        v10 = v17;
      }
      v12 = GET_BITS(a1, v10);
      if ( v12 & (1 << (v17 - 1)) )
        a2[izigzag_index[v11]] = v12 << a6;
      else
        a2[izigzag_index[v11]] = (v12 + *(_DWORD *)&lowest_coef[2 * v17]) << a6;
    }
    else
    {
      if ( v9 != 15 )
      {
        v13 = 1 << v9;
        if ( v9 )
        {
          a1->Prog_EndOfBlock_Run = v13;
          v16 = __OFSUB__(v9, a1->bitbuf_bits_valid);
          v14 = v9 == a1->bitbuf_bits_valid;
          v15 = v9 - a1->bitbuf_bits_valid < 0;
          v17 = 0;
          if ( !((unsigned __int8)(v15 ^ v16) | v14) )
          {
            result = Fill_Bit_Buffer(a1, v9);
            if ( result )
            {
              if ( result >= 0 )
                result = 0;
              return result;
            }
          }
          v13 = a1->Prog_EndOfBlock_Run + GET_BITS(a1, v9);
        }
        a1->Prog_EndOfBlock_Run = v13 - 1;
        return 0;
      }
      v17 &= 0xFu;
      v11 = v6 + 15;
    }
    v6 = v11 + 1;
    if ( v6 > a5 )
      return 0;
  }
  if ( result >= 0 )
    result = 0;
  return result;
}
// 906EE0: using guessed type int izigzag_index[];

//----- (00620330) --------------------------------------------------------  // acclient.c:577274
signed int __cdecl Decode_Block_Prog_AC_SA(struct _STATE *a1, __int16 *a2, struct _HUFFMAN_TABLE *a3, int a4, int a5, int a6)
{
  struct _STATE *v6; // edi@1
  int v7; // esi@1
  int v8; // ebx@1
  int v9; // eax@1
  signed int result; // eax@3
  int v11; // ebp@4
  int v12; // edi@13
  int v13; // edx@16
  int v14; // ebx@28
  int v15; // eax@31
  int v16; // [sp+10h] [bp-1Ch]@3
  int v17; // [sp+14h] [bp-18h]@1
  int v18; // [sp+18h] [bp-14h]@1

  v6 = a1;
  v7 = a4;
  v8 = a5;
  v17 = 1 << a6;
  v9 = a1->Prog_EndOfBlock_Run;
  v18 = -1 << a6;
  if ( v9 || a4 > a5 )
    goto LABEL_26;
  while ( 1 )
  {
    result = sub_61FB60(v6, (int)&v16, (int)a3);
    if ( result )
    {
      if ( result >= 0 )
        result = 0;
      return result;
    }
    v11 = v16 >> 4;
    v16 &= 0xFu;
    if ( !v16 )
      break;
    if ( v6->bitbuf_bits_valid <= 0 )
    {
      result = Fill_Bit_Buffer(v6, 1);
      if ( result )
      {
        if ( result >= 0 )
          result = 0;
        return result;
      }
    }
    if ( GET_BITS(v6, 1) )
      v16 = v17;
    else
      v16 = v18;
    while ( 1 )
    {
LABEL_13:
      v12 = izigzag_index[v7];
      if ( a2[v12] )
      {
        if ( a1->bitbuf_bits_valid <= 0 )
        {
          result = Fill_Bit_Buffer(a1, 1);
          if ( result )
          {
            if ( result >= 0 )
              result = 0;
            return result;
          }
        }
        if ( GET_BITS(a1, 1) )
        {
          v13 = a2[v12];
          if ( !(v17 & v13) )
          {
            if ( v13 < 0 )
              a2[v12] = v18 + v13;
            else
              a2[v12] = v17 + v13;
          }
        }
        goto LABEL_20;
      }
      --v11;
      if ( v11 < 0 )
        break;
LABEL_20:
      ++v7;
      if ( v7 > a5 )
      {
        v6 = a1;
        goto LABEL_22;
      }
    }
    v6 = a1;
LABEL_22:
    if ( v16 )
      a2[izigzag_index[v7]] = v16;
    ++v7;
    if ( v7 > a5 )
    {
      v8 = a5;
      v9 = v6->Prog_EndOfBlock_Run;
      goto LABEL_26;
    }
  }
  if ( v11 == 15 )
    goto LABEL_13;
  v8 = a5;
  v9 = 1 << v11;
  v6->Prog_EndOfBlock_Run = 1 << v11;
  if ( !v11 )
  {
LABEL_26:
    if ( v9 > 0 )
    {
      if ( v7 <= v8 )
      {
        while ( 1 )
        {
          v14 = izigzag_index[v7];
          if ( a2[v14] )
          {
            if ( v6->bitbuf_bits_valid <= 0 )
            {
              result = Fill_Bit_Buffer(v6, 1);
              if ( result )
              {
                if ( result >= 0 )
                  result = 0;
                return result;
              }
            }
            if ( GET_BITS(v6, 1) )
            {
              v15 = a2[v14];
              if ( !(v17 & v15) )
              {
                if ( v15 < 0 )
                  a2[v14] = v18 + v15;
                else
                  a2[v14] = v17 + v15;
              }
            }
          }
          ++v7;
          if ( v7 > a5 )
          {
            v9 = v6->Prog_EndOfBlock_Run;
            break;
          }
        }
      }
      v6->Prog_EndOfBlock_Run = v9 - 1;
    }
    return 0;
  }
  if ( v11 <= v6->bitbuf_bits_valid || (result = Fill_Bit_Buffer(v6, v11)) == 0 )
  {
    v9 = v6->Prog_EndOfBlock_Run + GET_BITS(v6, v11);
    v6->Prog_EndOfBlock_Run = v9;
    goto LABEL_26;
  }
  if ( result >= 0 )
    result = 0;
  return result;
}
// 906EE0: using guessed type int izigzag_index[];

//----- (00621940) --------------------------------------------------------  // acclient.c:578591
signed int __usercall EB_Write_Bits_M5@<eax>(__m64 a1@<mm1>, unsigned __int32 a2, int a3, struct _STATE *a4)
{
  return own_eb_write_bits_m5(a1, a2, a3, (int)a4);
}

//----- (00621970) --------------------------------------------------------  // acclient.c:578597
signed int __usercall EB_Write_Bits_File_M5@<eax>(__m64 a1@<mm1>, unsigned __int32 a2, int a3, struct _STATE *a4)
{
  return own_eb_write_bits_file_m5(a1, a2, a3, (int)a4);
}

//----- (00621A70) --------------------------------------------------------  // acclient.c:578645
signed int __cdecl Set_Encode_Fast_Path(struct _JPEG_PROPERTIES *a1)
{
  void *v1; // edx@1
  signed int result; // eax@1
  int v3; // ebx@2
  int v4; // ebx@4
  int v5; // ebx@12
  int v6; // ebx@17
  int v7; // ebx@24
  _FRAME_COMPONENT *v8; // ebp@37
  int v9; // ebx@37
  _IJL_COLOR v10; // ebp@55
  _FRAME_COMPONENT *v11; // ebp@59
  int v12; // ebx@59
  _FRAME_COMPONENT *v13; // ebp@74
  int v14; // ebx@74
  _FRAME_COMPONENT *v15; // ebp@89
  int v16; // ebx@89
  _FRAME_COMPONENT *v17; // ebp@105
  int v18; // ebx@105
  _IJL_COLOR v19; // ebx@131

  v1 = a1->state.ctx;
  result = 0;
  if ( a1->jinterleaveType )
  {
    a1->fast_processing = 0;
  }
  else
  {
    v3 = a1->upsampling_reqd;
    if ( v3 && a1->cconversion_reqd )
    {
      a1->fast_processing = 0;
      v4 = a1->jframe.ncomps;
      if ( v4 > 0 && v4 <= 255 )
      {
        if ( v4 == 3 )
        {
          v10 = a1->DIBColor;
          if ( v10 != 1 || a1->DIBChannels != 3 )
          {
            if ( v10 != 1 || a1->DIBChannels != 4 )
            {
              if ( v10 == 2 && a1->DIBChannels == 3 )
              {
                v11 = a1->jframe.comps;
                v12 = v11->hsampling;
                if ( v12 != 2
                  || v11->vsampling != 2
                  || v11[1].hsampling != 1
                  || v11[1].vsampling != 1
                  || v11[2].hsampling != 1
                  || v11[2].vsampling != 1 )
                {
                  if ( v12 == 2
                    && v11->vsampling == 1
                    && v11[1].hsampling == 1
                    && v11[1].vsampling == 1
                    && v11[2].hsampling == 1
                    && v11[2].vsampling == 1 )
                  {
                    a1->fast_processing = 6;
                    *((_DWORD *)v1 + 24) = BGR_to_YCbCr_422_MCU;
                  }
                }
                else
                {
                  a1->fast_processing = 4;
                  *((_DWORD *)v1 + 24) = BGR_to_YCbCr_411_MCU;
                }
              }
            }
            else
            {
              v13 = a1->jframe.comps;
              v14 = v13->hsampling;
              if ( v14 != 2
                || v13->vsampling != 2
                || v13[1].hsampling != 1
                || v13[1].vsampling != 1
                || v13[2].hsampling != 1
                || v13[2].vsampling != 1 )
              {
                if ( v14 == 2
                  && v13->vsampling == 1
                  && v13[1].hsampling == 1
                  && v13[1].vsampling == 1
                  && v13[2].hsampling == 1
                  && v13[2].vsampling == 1 )
                {
                  a1->fast_processing = 0;
                  *((_DWORD *)v1 + 24) = CC_SS_RGB_to_YCbCr_General_MCU;
                }
              }
              else
              {
                a1->fast_processing = 0;
                *((_DWORD *)v1 + 24) = CC_SS_RGB_to_YCbCr_General_MCU;
              }
            }
          }
          else
          {
            v15 = a1->jframe.comps;
            v16 = v15->hsampling;
            if ( v16 != 2
              || v15->vsampling != 2
              || v15[1].hsampling != 1
              || v15[1].vsampling != 1
              || v15[2].hsampling != 1
              || v15[2].vsampling != 1 )
            {
              if ( v16 == 2
                && v15->vsampling == 1
                && v15[1].hsampling == 1
                && v15[1].vsampling == 1
                && v15[2].hsampling == 1
                && v15[2].vsampling == 1 )
              {
                a1->fast_processing = 5;
                *((_DWORD *)v1 + 24) = RGB_to_YCbCr_422_MCU;
              }
            }
            else
            {
              a1->fast_processing = 3;
              *((_DWORD *)v1 + 24) = RGB_to_YCbCr_411_MCU;
            }
          }
        }
        else if ( v4 == 4 && a1->DIBColor == 5 && a1->DIBChannels == 4 )
        {
          v8 = a1->jframe.comps;
          v9 = v8->hsampling;
          if ( v9 != 2
            || v8->vsampling != 2
            || v8[1].hsampling != 1
            || v8[1].vsampling != 1
            || v8[2].hsampling != 1
            || v8[2].vsampling != 1
            || v8[3].hsampling != 2
            || v8[3].vsampling != 2 )
          {
            if ( v9 == 2
              && v8->vsampling == 1
              && v8[1].hsampling == 1
              && v8[1].vsampling == 1
              && v8[2].hsampling == 1
              && v8[2].vsampling == 1
              && v8[3].hsampling == 2
              && v8[3].vsampling == 1 )
            {
              a1->fast_processing = 12;
              *((_DWORD *)v1 + 24) = RGBA_FPX_to_YCbCrA_FPX_4224_MCU;
            }
          }
          else
          {
            a1->fast_processing = 11;
            *((_DWORD *)v1 + 24) = RGBA_FPX_to_YCbCrA_FPX_4114_MCU;
          }
        }
      }
      else
      {
        result = -14;
      }
    }
    else if ( !v3 || a1->cconversion_reqd )
    {
      if ( v3 || !a1->cconversion_reqd )
      {
        if ( v3 )
        {
          a1->fast_processing = 0;
        }
        else if ( a1->cconversion_reqd )
        {
          a1->fast_processing = 0;
        }
        else
        {
          v7 = a1->jframe.ncomps;
          if ( v7 != 1 || a1->DIBColor != 4 || a1->JPGColor != 4 )
          {
            if ( v7 != 3 || a1->DIBChannels != 1 || a1->JPGColor != 3 )
            {
              if ( v7 != 3 || a1->DIBChannels != 3 )
              {
                if ( v7 != 3 || a1->DIBChannels != 4 )
                {
                  if ( v7 == 4 )
                  {
                    a1->fast_processing = 14;
                    *((_DWORD *)v1 + 24) = OTHER_to_OTHER_1111_MCU;
                  }
                  else
                  {
                    a1->fast_processing = 0;
                    if ( a1->JPGColor == 255 && a1->DIBColor == 255 )
                      *((_DWORD *)v1 + 24) = Input_Interleave_General_MCU;
                  }
                }
                else
                {
                  a1->fast_processing = 0;
                  *((_DWORD *)v1 + 24) = Input_Interleave_General_MCU;
                }
              }
              else if ( a1->DIBColor == 2 )
              {
                a1->fast_processing = 0;
                *((_DWORD *)v1 + 24) = Input_Interleave_General_MCU;
              }
              else
              {
                a1->fast_processing = 15;
                *((_DWORD *)v1 + 24) = OTHER_to_OTHER_111_MCU;
              }
            }
            else
            {
              a1->fast_processing = 0;
              *((_DWORD *)v1 + 24) = Input_Interleave_General_MCU;
            }
          }
          else
          {
            a1->fast_processing = 20;
            *((_DWORD *)v1 + 24) = Y_to_Y_111_MCU;
          }
        }
      }
      else
      {
        v6 = a1->jframe.ncomps;
        if ( v6 != 1 || a1->DIBChannels != 3 )
        {
          if ( v6 != 3 || a1->DIBChannels != 3 )
          {
            if ( v6 != 3 || a1->DIBChannels != 4 )
            {
              if ( v6 == 4 )
              {
                if ( a1->DIBChannels == 4 )
                {
                  if ( a1->DIBColor == 5 )
                  {
                    a1->fast_processing = 10;
                    *((_DWORD *)v1 + 24) = RGBA_FPX_to_YCbCrA_FPX_1111_MCU;
                  }
                  else
                  {
                    a1->fast_processing = 0;
                  }
                }
                else
                {
                  a1->fast_processing = 0;
                }
              }
              else
              {
                a1->fast_processing = 0;
              }
            }
            else
            {
              a1->fast_processing = 0;
              *((_DWORD *)v1 + 24) = CC_SS_RGB_to_YCbCr_General_MCU;
            }
          }
          else
          {
            v19 = a1->DIBColor;
            if ( v19 == 1 )
            {
              a1->fast_processing = 1;
              *((_DWORD *)v1 + 24) = RGB_to_YCbCr_111_MCU;
            }
            else if ( v19 == 2 )
            {
              a1->fast_processing = 2;
              *((_DWORD *)v1 + 24) = BGR_to_YCbCr_111_MCU;
            }
            else
            {
              a1->fast_processing = 0;
            }
          }
        }
        else
        {
          a1->fast_processing = 0;
          *((_DWORD *)v1 + 24) = CC_RGB_to_YCbCr_General_MCU;
        }
      }
    }
    else
    {
      a1->fast_processing = 0;
      v5 = a1->jframe.ncomps;
      if ( v5 != 3 || a1->DIBChannels != 1 )
      {
        if ( v5 != 3 || a1->DIBChannels != 3 || a1->DIBColor == 2 )
        {
          *((_DWORD *)v1 + 24) = SS_General_MCU;
        }
        else
        {
          v17 = a1->jframe.comps;
          v18 = v17->hsampling;
          if ( v18 == 2
            && v17->vsampling == 2
            && v17[1].hsampling == 1
            && v17[1].vsampling == 1
            && v17[2].hsampling == 1
            && v17[2].vsampling == 1 )
          {
            a1->fast_processing = 16;
            *((_DWORD *)v1 + 24) = OTHER_to_OTHER_411_MCU;
            v17 = a1->jframe.comps;
            v18 = v17->hsampling;
          }
          if ( v18 == 2
            && v17->vsampling == 1
            && v17[1].hsampling == 1
            && v17[1].vsampling == 1
            && v17[2].hsampling == 1
            && v17[2].vsampling == 1 )
          {
            if ( a1->DIBSubsampling == 2 )
            {
              a1->fast_processing = 18;
              *((_DWORD *)v1 + 24) = YCbYCr_to_YCbCr_422_MCU;
            }
            else
            {
              a1->fast_processing = 17;
              *((_DWORD *)v1 + 24) = OTHER_to_OTHER_422_MCU;
            }
          }
        }
      }
      else
      {
        *((_DWORD *)v1 + 24) = SS_General_MCU;
      }
    }
  }
  return result;
}

//----- (0062E870) --------------------------------------------------------  // acclient.c:585984
int __cdecl operator&(int a1, int a2, int a3)
{
  int v3; // ebx@1
  int v4; // ecx@2
  int v5; // edi@4
  int v6; // eax@6
  int v7; // eax@9
  int v8; // eax@12
  int v9; // eax@15
  int v10; // ST0C_4@17
  int result; // eax@17
  int v12; // ecx@18
  int v13; // ebx@18
  int v14; // edi@18
  int v15; // [sp+0h] [bp-34h]@8
  int v16; // [sp+4h] [bp-30h]@11
  int v17; // [sp+8h] [bp-2Ch]@14
  int v18; // [sp+10h] [bp-24h]@4
  int v19; // [sp+1Ch] [bp-18h]@3

  v3 = *(_DWORD *)(a3 + 8);
  if ( *(_DWORD *)a2 > v3
    || (v4 = *(_DWORD *)(a2 + 8), v4 < *(_DWORD *)a3)
    || (v19 = *(_DWORD *)(a2 + 4), v19 > *(_DWORD *)(a3 + 12))
    || (v18 = *(_DWORD *)(a2 + 12), v5 = *(_DWORD *)(a3 + 4), v18 < v5) )
  {
    v12 = dword_9078E0[1];
    *(_DWORD *)a1 = dword_9078E0[0];
    v13 = dword_9078E0[2];
    v14 = dword_9078E0[3];
    *(_DWORD *)(a1 + 4) = v12;
    result = a1;
    *(_DWORD *)(a1 + 8) = v13;
    *(_DWORD *)(a1 + 12) = v14;
  }
  else
  {
    if ( *(_DWORD *)a2 <= *(_DWORD *)a3 )
      v6 = *(_DWORD *)a3;
    else
      v6 = *(_DWORD *)a2;
    v15 = v6;
    if ( v19 <= v5 )
      v7 = *(_DWORD *)(a3 + 4);
    else
      v7 = *(_DWORD *)(a2 + 4);
    v16 = v7;
    if ( v4 >= v3 )
      v8 = *(_DWORD *)(a3 + 8);
    else
      v8 = *(_DWORD *)(a2 + 8);
    v17 = v8;
    if ( v18 >= *(_DWORD *)(a3 + 12) )
      v9 = *(_DWORD *)(a3 + 12);
    else
      v9 = *(_DWORD *)(a2 + 12);
    v10 = v9;
    *(_DWORD *)a1 = v15;
    *(_DWORD *)(a1 + 4) = v16;
    *(_DWORD *)(a1 + 8) = v17;
    result = a1;
    *(_DWORD *)(a1 + 12) = v10;
  }
  return result;
}

//----- (0062E9A0) --------------------------------------------------------  // acclient.c:586051
BOOL __cdecl operator==(int a1, int a2)
{
  return *(_DWORD *)a1 == *(_DWORD *)a2
      && *(_DWORD *)(a1 + 8) == *(_DWORD *)(a2 + 8)
      && *(_DWORD *)(a1 + 4) == *(_DWORD *)(a2 + 4)
      && *(_DWORD *)(a1 + 12) == *(_DWORD *)(a2 + 12);
}

//----- (0062E9D0) --------------------------------------------------------  // acclient.c:586060
BOOL __cdecl operator!=(int a1, int a2)
{
  return *(_DWORD *)a1 != *(_DWORD *)a2
      || *(_DWORD *)(a1 + 8) != *(_DWORD *)(a2 + 8)
      || *(_DWORD *)(a1 + 4) != *(_DWORD *)(a2 + 4)
      || *(_DWORD *)(a1 + 12) != *(_DWORD *)(a2 + 12);
}

//----- (0062EA00) --------------------------------------------------------  // acclient.c:586069
int __cdecl operator-(int a1, int a2, int a3)
{
  int v3; // ecx@2
  int v4; // eax@2
  int v5; // ebp@2
  int result; // eax@2
  int v7; // ST10_4@3
  int v8; // ST14_4@3
  int v9; // edx@3

  if ( (unsigned __int8)operator==(a2, (int)dword_9078E0) )
  {
    v3 = dword_9078E0[1];
    *(_DWORD *)a1 = dword_9078E0[0];
    v4 = dword_9078E0[2];
    v5 = dword_9078E0[3];
    *(_DWORD *)(a1 + 4) = v3;
    *(_DWORD *)(a1 + 8) = v4;
    *(_DWORD *)(a1 + 12) = v5;
    result = a1;
  }
  else
  {
    result = a1;
    v7 = *(_DWORD *)(a2 + 8) - *(_DWORD *)a3;
    v8 = *(_DWORD *)(a2 + 12) - *(_DWORD *)(a3 + 4);
    v9 = *(_DWORD *)(a2 + 4) - *(_DWORD *)(a3 + 4);
    *(_DWORD *)a1 = *(_DWORD *)a2 - *(_DWORD *)a3;
    *(_DWORD *)(a1 + 4) = v9;
    *(_DWORD *)(a1 + 8) = v7;
    *(_DWORD *)(a1 + 12) = v8;
  }
  return result;
}

//----- (00640670) --------------------------------------------------------  // acclient.c:601360
int __cdecl CONVERT_TO_MARKER(unsigned __int8 a1)
{
  return a1;
}

//----- (00640680) --------------------------------------------------------  // acclient.c:601366
signed int __cdecl Get_Marker_Data_Into_Contiguous_Buffer(struct _STATE *a1, unsigned __int32 size, unsigned __int8 **a3, unsigned __int8 **a4, int *a5)
{
  unsigned __int8 *v5; // ebx@3
  unsigned int v6; // ecx@3
  int v7; // edx@5
  unsigned __int32 v8; // eax@5
  struct _STATE *v9; // ebx@5
  unsigned int v10; // eax@11
  signed int v11; // edx@14
  bool v12; // zf@16
  int v14; // [sp+0h] [bp-38h]@1
  void *v15; // [sp+4h] [bp-34h]@1
  int v16; // [sp+8h] [bp-30h]@5
  unsigned __int32 v17; // [sp+Ch] [bp-2Ch]@6
  unsigned __int8 *v18; // [sp+10h] [bp-28h]@10
  CPPEH_RECORD ms_exc; // [sp+20h] [bp-18h]@1
  unsigned __int32 sizea; // [sp+44h] [bp+Ch]@5

  ms_exc.old_esp = (DWORD)&v14;
  ms_exc.registration.TryLevel = 0;
  v14 = 0;
  v15 = 0;
  *a3 = 0;
  if ( size <= a1->entropy_bytes_left )
  {
    v14 = DB_Get_Data(a1, size, a4);
    if ( v14 )
      return v14;
  }
  else
  {
    *a3 = (unsigned __int8 *)operator new(size);
    if ( !*a3 )
      return -5;
    *a4 = *a3;
    v5 = *a3;
    v15 = *a3;
    *a5 = 1;
    v6 = size;
    if ( size >= a1->entropy_bytes_left )
      v6 = a1->entropy_bytes_left;
    v16 = v6;
    __g_memcpy(v5, a1->cur_entropy_ptr, v6);
    v7 = v16;
    v15 = (char *)v15 + v16;
    sizea = size - v16;
    v8 = sizea;
    v9 = a1;
    v9->cur_entropy_ptr += v16;
    v9->entropy_bytes_processed += v7;
    a1->entropy_bytes_left -= v16;
    if ( sizea )
    {
      v17 = sizea;
      while ( v8 <= 0xFFFF )
      {
        if ( v8 >= 0x1000 )
          v8 = 4096;
        v14 = DB_Get_Data(a1, v8, &v18);
        if ( v14 )
        {
          v14 = -21;
          operator delete(*a3);
          *a3 = 0;
          return v14;
        }
        v10 = sizea;
        if ( sizea >= 0x1000 )
          v10 = 4096;
        __g_memcpy(v15, v18, v10);
        if ( sizea >= 0x1000 )
          v11 = 4096;
        else
          v11 = sizea;
        v15 = (char *)v15 + v11;
        v12 = sizea == 4096;
        v8 = sizea - 4096;
        sizea -= 4096;
        if ( v12 )
          break;
      }
    }
  }
  ms_exc.registration.TryLevel = -1;
  return v14;
}
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);

//----- (006408E0) --------------------------------------------------------  // acclient.c:601472
signed int __cdecl DP_Get_Next_Marker(struct _STATE *a1, enum IJL_MARKER *a2)
{
  unsigned __int8 v2; // al@1
  signed int result; // eax@2
  unsigned __int8 *v4; // [sp+10h] [bp-Ch]@5

  v2 = a1->unread_marker;
  if ( a1->unread_marker )
  {
    a1->unread_marker = 0;
    *(_DWORD *)a2 = CONVERT_TO_MARKER(v2);
    result = 0;
  }
  else
  {
    result = DB_Skip_To_Next_Marker(a1);
    if ( !result )
    {
      if ( DB_Get_Data(a1, 1u, &v4) )
      {
        *(_DWORD *)a2 = 256;
        result = 0;
      }
      else
      {
        *(_DWORD *)a2 = CONVERT_TO_MARKER(*v4);
        result = 0;
      }
    }
  }
  return result;
}

//----- (00640960) --------------------------------------------------------  // acclient.c:601506
signed int __cdecl DP_Skip(struct _STATE *a1)
{
  signed int result; // eax@1
  int v2; // edx@4
  int v3; // ebx@4
  int v4; // [sp+10h] [bp-14h]@1
  unsigned __int8 *v5; // [sp+14h] [bp-10h]@9

  result = sub_640860(a1, (int)&v4);
  if ( !result )
  {
    if ( v4 < 2 )
      return -21;
    v2 = v4 - 2;
    v3 = a1->entropy_bytes_left;
    if ( v4 - 2 >= v3 )
    {
      v4 -= 2;
      result = DB_Get_Data(a1, v3, &v5);
      if ( result )
        return -21;
      v2 = v4 - v3;
    }
    if ( v2 > 0 )
    {
      while ( v2 <= 0xFFFF )
      {
        v4 = v2;
        if ( v2 >= 4096 )
          v2 = 4096;
        result = DB_Get_Data(a1, v2, &v5);
        if ( result )
          return -21;
        v2 = v4 - 4096;
        if ( v4 - 4096 <= 0 )
          return result;
      }
    }
  }
  return result;
}

//----- (00640A30) --------------------------------------------------------  // acclient.c:601549
signed int __cdecl DP_Parse_DRI(struct _STATE *a1, int *a2)
{
  signed int v2; // ebp@1
  unsigned __int8 *v4; // [sp+18h] [bp-1Ch]@1
  unsigned __int8 *v5; // [sp+1Ch] [bp-18h]@1
  int v6; // [sp+20h] [bp-14h]@1
  int v7; // [sp+24h] [bp-10h]@1

  v4 = 0;
  v5 = 0;
  v6 = 0;
  *a2 = 0;
  v2 = sub_640860(a1, (int)&v7);
  if ( !v2 )
  {
    if ( v7 >= 2 )
    {
      v7 -= 2;
      v2 = Get_Marker_Data_Into_Contiguous_Buffer(a1, v7, &v5, &v4, &v6);
      if ( !v2 )
        *a2 = v4[1] + (*v4 << 8);
    }
    else
    {
      v2 = -21;
    }
  }
  if ( v6 && v5 )
    operator delete(v5);
  return v2;
}

//----- (00640AE0) --------------------------------------------------------  // acclient.c:601582
signed int __cdecl DP_Parse_SOF(struct _STATE *a1, struct _JPEG_PROPERTIES *a2)
{
  signed int v2; // ebx@1
  unsigned __int8 *v4; // eax@9
  int v5; // edx@9
  int v6; // esi@9
  int v7; // ecx@9
  int v8; // edi@9
  int v9; // esi@9
  int v10; // edi@9
  int v11; // eax@9
  int v12; // edx@13
  _FRAME_COMPONENT *v13; // ebp@14
  unsigned int v14; // eax@14
  int v15; // ecx@14
  unsigned __int8 *v16; // edx@15
  _FRAME_COMPONENT *v17; // edi@15
  int v18; // esi@15
  _FRAME_COMPONENT *v19; // ebp@15
  int v20; // ebp@21
  int v21; // edx@21
  int v22; // edi@21
  unsigned __int8 *v23; // [sp+18h] [bp-34h]@1
  unsigned __int8 *v24; // [sp+1Ch] [bp-30h]@1
  int v25; // [sp+20h] [bp-2Ch]@1
  int v26; // [sp+24h] [bp-28h]@1
  int v27; // [sp+28h] [bp-24h]@14
  int v28; // [sp+2Ch] [bp-20h]@14
  unsigned int v29; // [sp+30h] [bp-1Ch]@13
  int v30; // [sp+34h] [bp-18h]@13

  v23 = 0;
  v24 = 0;
  v25 = 0;
  v2 = sub_640860(a1, (int)&v26);
  if ( !v2 )
  {
    if ( v26 >= 2 )
    {
      v26 -= 2;
      v2 = Get_Marker_Data_Into_Contiguous_Buffer(a1, v26, &v24, &v23, &v25);
      if ( !v2 )
      {
        __g_memzero(a2->jframe.comps, 0x40u);
        v4 = v23++;
        v5 = *v4;
        a2->jframe.precision = v5;
        v23 = v4 + 2;
        v6 = v4[1] << 8;
        a2->jframe.height = v6;
        v23 = v4 + 3;
        v7 = v6 + v4[2];
        a2->jframe.height = v7;
        v23 = v4 + 4;
        v8 = v4[3] << 8;
        a2->jframe.width = v8;
        v23 = v4 + 5;
        v9 = v8 + v4[4];
        v10 = (int)(v4 + 6);
        a2->jframe.width = v9;
        v23 = v4 + 6;
        v11 = v4[5];
        a2->jframe.ncomps = v11;
        if ( v5 == 8 )
        {
          if ( v7 )
          {
            v12 = 0;
            v30 = 0;
            v29 = 0;
            if ( v11 > 0 )
            {
              v13 = a2->jframe.comps;
              v14 = v29;
              v15 = v29;
              v27 = 0;
              v28 = 0;
              do
              {
                v23 = (unsigned __int8 *)(v10 + 1);
                v13[v14].ident = *(_BYTE *)v10;
                v16 = v23;
                a2->jframe.comps[v14].hsampling = (signed int)*v23 >> 4;
                v17 = a2->jframe.comps;
                v18 = v27;
                v23 = v16 + 1;
                v17[v14].vsampling = *v16 & 0xF;
                v10 = (int)(v16 + 2);
                v19 = a2->jframe.comps;
                v23 = v16 + 2;
                v19[v14].quant_sel = v16[1];
                v13 = a2->jframe.comps;
                if ( v18 < v13[v14].hsampling )
                  v27 = v13[v14].hsampling;
                if ( v30 < v13[v14].vsampling )
                  v30 = v13[v14].vsampling;
                ++v14;
                ++v15;
              }
              while ( v15 < a2->jframe.ncomps );
              v12 = v27;
              v2 = v28;
              v7 = a2->jframe.height;
              v9 = a2->jframe.width;
            }
            v20 = (v9 + 8 * v12 - 1) / (8 * v12);
            v21 = v30;
            v22 = 2 * v30;
            a2->jframe.horMCU = v20;
            a2->jframe.totalMCU = v20 * ((v7 + 8 * v21 - 1) / (4 * v22));
          }
          else
          {
            v2 = -16;
          }
        }
        else
        {
          v2 = -29;
        }
      }
    }
    else
    {
      v2 = -21;
    }
  }
  if ( v25 && v24 )
    operator delete(v24);
  return v2;
}
// 8F75A4: using guessed type void (__cdecl *__g_memzero)(void *, unsigned int);

//----- (00640D40) --------------------------------------------------------  // acclient.c:601716
signed int __cdecl DP_Parse_APP14(struct _JPEG_PROPERTIES *a1)
{
  signed int v1; // ebp@1
  int v2; // edx@4
  unsigned __int8 *v4; // edx@10
  unsigned __int8 *v5; // [sp+18h] [bp-1Ch]@1
  unsigned __int8 *v6; // [sp+1Ch] [bp-18h]@1
  int v7; // [sp+20h] [bp-14h]@1
  int v8; // [sp+24h] [bp-10h]@1

  v5 = 0;
  v6 = 0;
  v7 = 0;
  v1 = sub_640860(&a1->state, (int)&v8);
  if ( !v1 )
  {
    if ( v8 >= 2 )
    {
      v2 = v8 - 2;
      v8 = v2;
      if ( v2 >= 12 )
      {
        v1 = Get_Marker_Data_Into_Contiguous_Buffer(&a1->state, v2, &v6, &v5, &v7);
        if ( !v1 )
        {
          v4 = v5++;
          if ( *v4 == 65 )
          {
            v5 = v4 + 2;
            if ( v4[1] == 100 )
            {
              v5 = v4 + 3;
              if ( v4[2] == 111 )
              {
                v5 = v4 + 4;
                if ( v4[3] == 98 )
                {
                  v5 = v4 + 5;
                  if ( v4[4] == 101 )
                  {
                    v5 = v4 + 7;
                    a1->AdobeVersion = v4[6] + (v4[5] << 8);
                    v5 = v4 + 9;
                    a1->AdobeFlags0 = v4[8] + (v4[7] << 8);
                    v5 = v4 + 11;
                    a1->AdobeFlags1 = v4[10] + (v4[9] << 8);
                    v5 = v4 + 12;
                    a1->AdobeXform = v4[11];
                    a1->SawAdobeMarker = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v1 = -21;
    }
  }
  if ( v7 && v6 )
    operator delete(v6);
  return v1;
}

//----- (00640EB0) --------------------------------------------------------  // acclient.c:601784
signed int __cdecl DP_Parse_APP0(struct _JPEG_PROPERTIES *a1)
{
  int v1; // eax@3
  unsigned __int8 *v3; // ecx@15
  int v4; // edx@21
  int v5; // esi@21
  signed int v6; // ecx@21
  int v7; // edi@22
  unsigned __int8 *v8; // eax@22
  int v9; // edx@22
  unsigned int v10; // ebx@27
  _IJL_COLOR v11; // ecx@29
  int i; // esi@30
  signed int v13; // edi@31
  int v14; // edi@37
  int v15; // esi@38
  unsigned __int8 v16; // al@45
  int v17; // esi@49
  int v18; // ebx@49
  void *v19; // eax@52
  int v20; // ecx@53
  unsigned __int8 *v21; // ebx@54
  unsigned __int8 *v22; // ebx@54
  unsigned __int8 *v23; // edi@54
  unsigned __int8 *v24; // ebp@54
  int v25; // ebx@55
  int v26; // edx@55
  int v27; // edi@56
  int v28; // esi@57
  unsigned __int8 *v29; // ecx@58
  int v30; // edi@59
  char v31; // bl@59
  int v32; // ecx@60
  int v33; // edi@65
  unsigned __int8 *v34; // [sp+18h] [bp-34h]@1
  unsigned __int8 *v35; // [sp+1Ch] [bp-30h]@1
  int v36; // [sp+20h] [bp-2Ch]@1
  int v37; // [sp+24h] [bp-28h]@1
  int v38; // [sp+28h] [bp-24h]@32
  int v39; // [sp+2Ch] [bp-20h]@53
  int v40; // [sp+30h] [bp-1Ch]@58
  char v41; // [sp+34h] [bp-18h]@59
  char v42; // [sp+38h] [bp-14h]@59

  v34 = 0;
  v35 = 0;
  v36 = 0;
  if ( sub_640860(&a1->state, (int)&v37) )
    goto LABEL_5;
  if ( v37 < 2 )
    goto LABEL_5;
  v1 = v37 - 2;
  v37 = v1;
  if ( v1 < 14 || v1 > 196622 )
    goto LABEL_5;
  if ( !Get_Marker_Data_Into_Contiguous_Buffer(&a1->state, v1, &v35, &v34, &v36) )
  {
    if ( a1->needframe )
    {
      v3 = v34;
      if ( *v34 != 74 || v34[1] != 70 || v34[2] != 88 || v34[3] != 88 || v34[4] )
      {
        if ( *v34 == 74 && v34[1] == 70 && v34[2] == 73 && v34[3] == 70 && !v34[4] )
        {
          a1->jfif_app0_detected = 1;
          v34 = v3 + 7;
          a1->jfif_app0_version = _byteswap_ushort(*(_WORD *)(v3 + 5));
          v34 = v3 + 8;
          a1->jfif_app0_units = v3[7];
          v34 = v3 + 10;
          v4 = (int)(v3 + 12);
          a1->jfif_app0_Xdensity = _byteswap_ushort(*((_WORD *)v3 + 4));
          v34 = v3 + 12;
          v5 = v3[11] | (v3[10] << 8);
          v6 = 14;
          a1->jfif_app0_Ydensity = v5;
LABEL_22:
          v34 = (unsigned __int8 *)(v4 + 1);
          v7 = *(_BYTE *)v4;
          v8 = (unsigned __int8 *)(v4 + 2);
          v34 = (unsigned __int8 *)(v4 + 2);
          v9 = *(_BYTE *)(v4 + 1);
          if ( v7 && v9 )
          {
            if ( a1->iotype == 20 || a1->iotype == 21 )
            {
              v10 = 3 * v7;
              if ( 3 * v7 * v9 + v6 <= v37 )
              {
                a1->JPGThumbHeight = v9;
                v11 = a1->DIBColor;
                a1->JPGThumbWidth = v7;
                if ( v11 == 1 )
                {
                  v14 = 0;
                  if ( v9 > 0 )
                  {
                    v15 = v9;
                    do
                    {
                      __g_memcpy(&a1->DIBBytes[a1->DIBLineBytes * v14], v8, v10);
                      v8 = &v34[v10];
                      ++v14;
                      v34 += v10;
                    }
                    while ( v14 < v15 );
                  }
                }
                else
                {
                  for ( i = 0; i < v9; ++i )
                  {
                    v13 = 0;
                    if ( (signed int)v10 > 0 )
                    {
                      v38 = v9;
                      do
                      {
                        *(&a1->DIBBytes[v13] + i * a1->DIBLineBytes) = v8[2];
                        *(&a1->DIBBytes[i * a1->DIBLineBytes + 1] + v13) = v34[1];
                        *(&a1->DIBBytes[i * a1->DIBLineBytes + 2] + v13) = *v34;
                        v8 = v34 + 3;
                        v34 += 3;
                        v13 += 3;
                      }
                      while ( v13 < (signed int)v10 );
                      v9 = v38;
                    }
                  }
                }
              }
              else
              {
                a1->JPGThumbWidth = v7;
                a1->JPGThumbHeight = v9;
              }
            }
            else
            {
              a1->JPGThumbWidth = v7;
              a1->JPGThumbHeight = v9;
            }
          }
          goto LABEL_5;
        }
      }
      else
      {
        v34 += 5;
        v16 = v3[5];
        if ( v16 != 16 )
        {
          if ( v16 == 17 )
          {
            v34 = v3 + 7;
            v17 = v3[6];
            v34 = v3 + 8;
            v18 = v3[7];
            if ( (a1->iotype == 20 || a1->iotype == 21) && v18 * v17 + 776 <= v37 )
            {
              a1->JPGThumbHeight = v18;
              a1->JPGThumbWidth = v17;
              v19 = operator new(0x300u);
              if ( v19 )
              {
                v20 = (int)v19;
                v38 = v18;
                v39 = v17;
                do
                {
                  v21 = v34++;
                  *(_BYTE *)v20 = *v21;
                  v22 = v34++;
                  *(_BYTE *)(v20 + 1) = *v22;
                  v23 = v34++;
                  *(_BYTE *)(v20 + 2) = *v23;
                  v24 = v34++;
                  *(_BYTE *)(v20 + 3) = *v24;
                  v20 += 4;
                }
                while ( (signed int)((char *)v19 + 768) > v20 );
                v25 = v38;
                v26 = 0;
                if ( v38 > 0 )
                {
                  v27 = 3 * v39;
                  do
                  {
                    v28 = 0;
                    if ( v27 > 0 )
                    {
                      v29 = v34;
                      v40 = v26;
                      v39 = v27;
                      v38 = v25;
                      do
                      {
                        v30 = 3 * *v29;
                        v41 = *((_BYTE *)v19 + v30);
                        v31 = *((_BYTE *)v19 + v30 + 2);
                        v42 = *((_BYTE *)v19 + v30 + 1);
                        if ( a1->DIBColor == 1 )
                        {
                          v33 = v40;
                          *(&a1->DIBBytes[v40 * a1->DIBLineBytes] + v28) = v41;
                          *(&a1->DIBBytes[v28 + 1] + v33 * a1->DIBLineBytes) = v42;
                          *(&a1->DIBBytes[v28 + 2] + v33 * a1->DIBLineBytes) = v31;
                        }
                        else
                        {
                          v32 = v40;
                          *(&a1->DIBBytes[v40 * a1->DIBLineBytes] + v28) = v31;
                          *(&a1->DIBBytes[v28 + 1] + v32 * a1->DIBLineBytes) = v42;
                          *(&a1->DIBBytes[v28 + 2] + v32 * a1->DIBLineBytes) = v41;
                        }
                        v28 += 3;
                        v29 = v34++ + 1;
                      }
                      while ( v28 < v39 );
                      v26 = v40;
                      v27 = v39;
                      v25 = v38;
                    }
                    ++v26;
                  }
                  while ( v26 < v25 );
                }
                operator delete(v19);
              }
            }
            goto LABEL_5;
          }
          if ( v16 == 19 )
          {
            v4 = (int)(v3 + 6);
            v6 = 8;
            goto LABEL_22;
          }
        }
      }
    }
LABEL_5:
    if ( v36 )
    {
      if ( v35 )
        operator delete(v35);
    }
    return 0;
  }
  if ( v36 && v35 )
    operator delete(v35);
  return -21;
}
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);

//----- (00641350) --------------------------------------------------------  // acclient.c:602040
int __cdecl DP_Parse_COM(struct _JPEG_PROPERTIES *a1)
{
  char *v2; // edx@12
  unsigned __int16 v3; // si@13
  int v4; // ebx@13
  signed int v5; // eax@14
  unsigned __int8 *v6; // edi@15
  int v7; // eax@17
  unsigned __int8 *v8; // edi@18
  int v9; // [sp+0h] [bp-40h]@1
  int v10; // [sp+4h] [bp-3Ch]@1
  unsigned __int8 *v11; // [sp+8h] [bp-38h]@1
  unsigned __int8 *v12; // [sp+Ch] [bp-34h]@1
  int v13; // [sp+10h] [bp-30h]@1
  int v14; // [sp+14h] [bp-2Ch]@14
  CPPEH_RECORD ms_exc; // [sp+28h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v9;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  ms_exc.registration.TryLevel = 0;
  v10 = sub_640860(&a1->state, (int)&v9);
  if ( !v10 )
  {
    if ( v9 >= 2 )
    {
      v9 -= 2;
      v10 = Get_Marker_Data_Into_Contiguous_Buffer(&a1->state, v9, &v12, &v11, &v13);
      if ( v10 )
      {
        v10 = -21;
      }
      else if ( a1->needframe )
      {
        v2 = a1->jpeg_comment;
        if ( v2 )
        {
          v3 = v9;
          v4 = a1->jpeg_comment_size;
          if ( v9 <= v4 )
          {
            v7 = 0;
            v14 = 0;
            if ( v9 > 0 )
            {
              while ( 1 )
              {
                v8 = v11++;
                v2[v7++] = *v8;
                v14 = v7;
                v3 = v9;
                if ( v7 >= v9 )
                  break;
                v2 = a1->jpeg_comment;
              }
            }
            a1->jpeg_comment_size = v3;
          }
          else
          {
            v5 = 0;
            v14 = 0;
            if ( v4 > 0 )
            {
              while ( 1 )
              {
                v6 = v11++;
                v2[v5++] = *v6;
                v14 = v5;
                if ( v5 >= a1->jpeg_comment_size )
                  break;
                v2 = a1->jpeg_comment;
              }
              v3 = v9;
            }
            a1->jpeg_comment_size = v3;
            v10 = -30;
          }
          ms_exc.registration.TryLevel = -1;
        }
      }
    }
    else
    {
      v10 = -21;
    }
  }
  if ( v13 && v12 )
  {
    operator delete(v12);
    v12 = 0;
  }
  return v10;
}

//----- (00641510) --------------------------------------------------------  // acclient.c:602139
signed int __cdecl DP_Parse_DQT(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, enum _DCTTYPE a3)
{
  signed int v3; // edi@1
  int v4; // eax@4
  int v6; // ebp@11
  signed int v7; // eax@13
  int v8; // esi@14
  signed int v9; // edi@14
  unsigned __int8 *v10; // edx@14
  int v11; // ecx@17
  signed int v12; // ebp@17
  signed int v13; // ebp@21
  int v14; // esi@20
  char *v15; // edx@25
  int v16; // esi@27
  int v17; // ebp@29
  int v18; // eax@29
  int v19; // esi@31
  int v20; // ebp@33
  int v21; // eax@33
  int v22; // eax@36
  int v23; // eax@39
  int v24; // eax@41
  unsigned __int8 *v25; // [sp+18h] [bp-3Ch]@1
  unsigned __int8 *v26; // [sp+1Ch] [bp-38h]@1
  int v27; // [sp+20h] [bp-34h]@1
  int v28; // [sp+24h] [bp-30h]@1
  int v29; // [sp+28h] [bp-2Ch]@27
  int v30; // [sp+2Ch] [bp-28h]@17
  int v31; // [sp+30h] [bp-24h]@27
  int v32; // [sp+34h] [bp-20h]@17
  int v33; // [sp+38h] [bp-1Ch]@16
  int v34; // [sp+3Ch] [bp-18h]@17
  int v35; // [sp+40h] [bp-14h]@11

  v25 = 0;
  v26 = 0;
  v27 = 0;
  v3 = sub_640860(a2, (int)&v28);
  if ( !v3 )
  {
    if ( v28 >= 2 )
    {
      v4 = v28 - 2;
      v28 = v4;
      if ( v4 <= 516 )
      {
        v3 = Get_Marker_Data_Into_Contiguous_Buffer(a2, v4, &v26, &v25, &v27);
        if ( !v3 )
        {
          v6 = 0;
          v35 = 0;
          while ( v6 < v28 )
          {
            v7 = *v25 & 0xF;
            if ( v7 > 4 )
            {
              v3 = -7;
              goto LABEL_6;
            }
            v8 = (signed int)*v25 >> 4;
            v9 = v7;
            a1->jFmtQuant[v7].precision = v8;
            v10 = v25++ + 1;
            if ( a1->maxquantindex <= v7 )
              a1->maxquantindex = v7 + 1;
            v33 = (int)v10;
            if ( v8 )
            {
              v34 = 0;
              v11 = (int)&a1->jFmtQuant[v9].elements;
              v30 = v8;
              v32 = v6;
              v12 = 0;
              while ( 1 )
              {
                a1->jFmtQuant[v9].elements[v12] = (*(_WORD *)&v10[2 * v12] << 8) | ((*(_WORD *)&v10[2 * v12] & 0xFF00) >> 8);
                a1->jFmtQuant[v9].elements[v12 + 1] = (*(_WORD *)&v25[2 * v12 + 2] << 8) | ((*(_WORD *)&v25[2 * v12 + 2] & 0xFF00) >> 8);
                v12 += 2;
                if ( v12 >= 64 )
                  break;
                v10 = v25;
              }
              v14 = v30;
              v6 = v32 + 129;
              v25 += 128;
            }
            else
            {
              v34 = 0;
              v11 = (int)&a1->jFmtQuant[v9].elements;
              v30 = 0;
              v32 = v6;
              v13 = 0;
              while ( 1 )
              {
                a1->jFmtQuant[v9].elements[v13] = v10[v13];
                a1->jFmtQuant[v9].elements[v13 + 1] = v25[v13 + 1];
                a1->jFmtQuant[v9].elements[v13 + 2] = v25[v13 + 2];
                a1->jFmtQuant[v9].elements[v13 + 3] = v25[v13 + 3];
                v13 += 4;
                if ( v13 >= 64 )
                  break;
                v10 = v25;
              }
              v14 = v30;
              v6 = v32 + 65;
              v25 += 64;
            }
            v15 = a1->rawquanttables[v7].quantizer;
            if ( v15 )
            {
              a1->rawquanttables[v7].ident = v7;
              if ( v14 )
              {
                v34 = 0;
                v31 = v11;
                v16 = v33;
                v29 = v7;
                v32 = v6;
                while ( 1 )
                {
                  v17 = v34;
                  v15[v34] = *(_BYTE *)(v16 + v34);
                  v18 = v29;
                  a1->rawquanttables[v29].quantizer[v17 + 1] = *(_BYTE *)(v16 + v17 + 1);
                  a1->rawquanttables[v18].quantizer[v17 + 2] = *(_BYTE *)(v16 + v17 + 2);
                  a1->rawquanttables[v18].quantizer[v17 + 3] = *(_BYTE *)(v16 + v17 + 3);
                  v34 = v17 + 4;
                  if ( (unsigned int)(v17 + 4) >= 0x80 )
                    break;
                  v15 = a1->rawquanttables[v29].quantizer;
                }
                v11 = v31;
                v6 = v32;
              }
              else
              {
                v30 = 0;
                v31 = v11;
                v19 = v33;
                v29 = v7;
                v32 = v6;
                while ( 1 )
                {
                  v20 = v30;
                  v15[v30] = *(_BYTE *)(v19 + v30);
                  v21 = v29;
                  a1->rawquanttables[v29].quantizer[v20 + 1] = *(_BYTE *)(v19 + v20 + 1);
                  a1->rawquanttables[v21].quantizer[v20 + 2] = *(_BYTE *)(v19 + v20 + 2);
                  a1->rawquanttables[v21].quantizer[v20 + 3] = *(_BYTE *)(v19 + v20 + 3);
                  v30 = v20 + 4;
                  if ( v20 + 4 >= 64 )
                    break;
                  v15 = a1->rawquanttables[v21].quantizer;
                }
                v11 = v31;
                v6 = v32;
              }
            }
            if ( a3 )
            {
              if ( a3 == 1 )
              {
                FillDecoderQuantTable_IPP(*(_DWORD *)v11);
                v23 = a1->nqtables;
                if ( v23 < 4 )
                  a1->nqtables = v23 + 1;
              }
              else
              {
                FillDecoderQuantTable_AAN(*(_DWORD *)v11);
                v24 = a1->nqtables;
                if ( v24 < 4 )
                  a1->nqtables = v24 + 1;
              }
            }
            else
            {
              FillDecoderQuantTable_AAN(*(_DWORD *)v11);
              v22 = a1->nqtables;
              if ( v22 < 4 )
                a1->nqtables = v22 + 1;
            }
          }
          v3 = v35;
        }
      }
      else
      {
        v3 = -21;
      }
    }
    else
    {
      v3 = -21;
    }
  }
LABEL_6:
  if ( v27 && v26 )
    operator delete(v26);
  return v3;
}

//----- (00641940) --------------------------------------------------------  // acclient.c:602344
signed int __cdecl DP_Parse_DHT(struct _JPEG_PROPERTIES *a1, struct _STATE *a2)
{
  signed int v2; // ebp@1
  int v3; // eax@4
  unsigned __int8 *v5; // ecx@12
  signed int v6; // edx@13
  signed int v7; // eax@13
  unsigned int v8; // ebx@20
  char *v9; // ebp@20
  char *v10; // ebx@20
  int v11; // ecx@20
  int v12; // ebx@20
  int v13; // esi@20
  int v14; // ebx@20
  int v15; // esi@20
  int v16; // ebx@20
  int v17; // esi@20
  int v18; // ebx@20
  int v19; // esi@20
  int v20; // ebx@20
  int v21; // esi@20
  int v22; // ebx@20
  int v23; // edi@20
  int v24; // esi@20
  int v25; // ebx@20
  int v26; // ebp@20
  int v27; // eax@22
  int v28; // edx@22
  int v29; // ebx@26
  char **v30; // ebp@26
  int v31; // esi@26
  int v32; // edx@32
  int v33; // edx@35
  unsigned __int8 *v34; // ecx@37
  unsigned __int8 *v35; // ebx@37
  int v36; // esi@37
  int v37; // edx@37
  int v38; // ebx@37
  int v39; // esi@37
  int v40; // ebx@37
  int v41; // esi@37
  int v42; // ebx@37
  int v43; // esi@37
  int v44; // ebx@37
  int v45; // esi@37
  int v46; // ebx@37
  int v47; // esi@37
  int v48; // ebx@37
  int v49; // esi@37
  int v50; // ebx@37
  int v51; // edx@37
  unsigned __int8 *v52; // [sp+18h] [bp-3Ch]@1
  unsigned __int8 *v53; // [sp+1Ch] [bp-38h]@1
  int v54; // [sp+20h] [bp-34h]@1
  int v55; // [sp+24h] [bp-30h]@1
  int v56; // [sp+28h] [bp-2Ch]@20
  int v57; // [sp+2Ch] [bp-28h]@20
  int v58; // [sp+30h] [bp-24h]@22
  int v59; // [sp+34h] [bp-20h]@22
  int v60; // [sp+38h] [bp-1Ch]@20
  char **v61; // [sp+3Ch] [bp-18h]@22
  int v62; // [sp+44h] [bp-10h]@22

  v52 = 0;
  v53 = 0;
  v54 = 0;
  v2 = sub_640860(a2, (int)&v55);
  if ( !v2 )
  {
    if ( v55 >= 2 )
    {
      v3 = v55 - 2;
      v55 = v3;
      if ( v3 <= 1091 )
      {
        v2 = Get_Marker_Data_Into_Contiguous_Buffer(a2, v3, &v53, &v52, &v54);
        if ( !v2 && v55 > 0 )
        {
          v5 = v52;
          do
          {
            v6 = (*v5 & 0xF0) >> 4;
            v7 = *v5 & 0xF;
            if ( v6 < 0 || v6 > 1 )
            {
              v2 = -6;
              break;
            }
            if ( v7 > 3 )
            {
              v2 = -6;
              break;
            }
            if ( v7 >= a1->maxhuffindex )
              a1->maxhuffindex = v7 + 1;
            if ( a1->rawhufftables[v7].bits )
            {
              if ( a1->rawhufftables[v7].vals )
              {
                v8 = 12 * (v6 + 2 * v7);
                v56 = v8;
                v9 = (char *)a1 + v8;
                v9[14148] = v6;
                v10 = a1->rawhufftables[v8 / 0xC].bits;
                v9[14149] = v7;
                *v10 = v52[1];
                v11 = v52[1];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 1) = v52[2];
                v12 = v11 + v52[2];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 2) = v52[3];
                v13 = v12 + v52[3];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 3) = v52[4];
                v14 = v13 + v52[4];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 4) = v52[5];
                v15 = v14 + v52[5];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 5) = v52[6];
                v16 = v15 + v52[6];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 6) = v52[7];
                v17 = v16 + v52[7];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 7) = v52[8];
                v18 = v17 + v52[8];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 8) = v52[9];
                v19 = v18 + v52[9];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 9) = v52[10];
                v20 = v19 + v52[10];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 10) = v52[11];
                v21 = v20 + v52[11];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 11) = v52[12];
                v22 = v21 + v52[12];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 12) = v52[13];
                v23 = v22 + v52[13];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 13) = v52[14];
                v24 = v23 + v52[14];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 14) = v52[15];
                v25 = v24 + v52[15];
                *(_BYTE *)(*((_DWORD *)v9 + 3535) + 15) = v52[16];
                v5 = v52;
                v26 = v52[16];
                v60 = v26 + v25;
                v57 = 0;
                if ( v26 + v25 > 0 )
                {
                  if ( v26 + v25 < 6 )
                  {
                    v61 = (char **)((char *)&a1->rawhufftables[0].vals + v56);
                  }
                  else
                  {
                    v61 = (char **)((char *)&a1->rawhufftables[0].vals + v56);
                    v62 = v26 + v25 - 6;
                    v59 = v7;
                    v27 = v57;
                    v58 = v6;
                    v28 = v56;
                    while ( 1 )
                    {
                      (*(char **)((char *)&a1->rawhufftables[0].vals + v28))[v27] = v5[v27 + 17];
                      (*(char **)((char *)&a1->rawhufftables[0].vals + v28))[v27 + 1] = v52[v27 + 18];
                      (*(char **)((char *)&a1->rawhufftables[0].vals + v28))[v27 + 2] = v52[v27 + 19];
                      (*(char **)((char *)&a1->rawhufftables[0].vals + v28))[v27 + 3] = v52[v27 + 20];
                      (*(char **)((char *)&a1->rawhufftables[0].vals + v28))[v27 + 4] = v52[v27 + 21];
                      v27 += 5;
                      if ( v27 > v62 )
                        break;
                      v5 = v52;
                    }
                    v57 = v27;
                    v7 = v59;
                    v6 = v58;
                    v5 = v52;
                  }
                  v29 = v57;
                  v30 = v61;
                  v31 = v60;
                  while ( 1 )
                  {
                    (*v30)[v29] = v5[v29 + 17];
                    ++v29;
                    if ( v29 >= v31 )
                      break;
                    v5 = v52;
                  }
                  v5 = v52;
                }
              }
            }
            if ( v6 )
            {
              v2 = BuildDecoderHuffmanTable((int)(v5 + 1), (int)(v5 + 17), v6, v7, (int)&a1->jFmtAcHuffman[v7]);
              if ( v2 )
              {
                v2 = -6;
                break;
              }
              v32 = a1->nhuffActables;
              if ( v32 < 4 )
                a1->nhuffActables = v32 + 1;
            }
            else
            {
              v2 = BuildDecoderHuffmanTable((int)(v5 + 1), (int)(v5 + 17), 0, v7, (int)&a1->jFmtDcHuffman[v7]);
              if ( v2 )
              {
                v2 = -6;
                break;
              }
              v33 = a1->nhuffDctables;
              if ( v33 < 4 )
                a1->nhuffDctables = v33 + 1;
            }
            v34 = v52;
            v35 = v52 + 3;
            v52 += 2;
            v36 = v34[1];
            v52 = v35;
            v37 = v36 + v34[2];
            v52 = v34 + 4;
            v38 = v37 + v34[3];
            v52 = v34 + 5;
            v39 = v38 + v34[4];
            v52 = v34 + 6;
            v40 = v39 + v34[5];
            v52 = v34 + 7;
            v41 = v40 + v34[6];
            v52 = v34 + 8;
            v42 = v41 + v34[7];
            v52 = v34 + 9;
            v43 = v42 + v34[8];
            v52 = v34 + 10;
            v44 = v43 + v34[9];
            v52 = v34 + 11;
            v45 = v44 + v34[10];
            v52 = v34 + 12;
            v46 = v45 + v34[11];
            v52 = v34 + 13;
            v47 = v46 + v34[12];
            v52 = v34 + 14;
            v48 = v47 + v34[13];
            v52 = v34 + 15;
            v49 = v48 + v34[14];
            v52 = v34 + 16;
            v50 = v49 + v34[15];
            v52 = v34 + 17;
            v51 = v50 + v34[16];
            v5 = &v34[v51 + 17];
            v52 = v5;
            v55 = v55 - v51 - 17;
          }
          while ( v55 > 0 );
        }
      }
      else
      {
        v2 = -21;
      }
    }
    else
    {
      v2 = -21;
    }
  }
  if ( v54 && v53 )
    operator delete(v53);
  return v2;
}

//----- (00641EF0) --------------------------------------------------------  // acclient.c:602611
int __cdecl DP_Parse_SOS(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, struct _FRAME *a3, struct _SCAN *a4)
{
  int *v5; // edx@9
  int v6; // edx@9
  unsigned __int8 *v7; // edi@12
  int v8; // ebx@12
  signed int v9; // eax@12
  int v10; // ecx@12
  int v11; // ecx@15
  int v12; // eax@15
  _FRAME_COMPONENT *v13; // edi@16
  int v14; // eax@20
  signed int v15; // ebx@20
  struct _FRAME *v16; // edi@22
  char v17; // cl@22
  struct _JPEG_PROPERTIES *v18; // esi@22
  int v19; // ebx@22
  unsigned __int8 *v20; // eax@23
  unsigned __int8 *v21; // [sp+0h] [bp-70h]@1
  unsigned __int8 *v22; // [sp+4h] [bp-6Ch]@1
  int v23; // [sp+8h] [bp-68h]@1
  int v24; // [sp+Ch] [bp-64h]@1
  int *v25; // [sp+10h] [bp-60h]@1
  void *v26; // [sp+14h] [bp-5Ch]@1
  int v27; // [sp+18h] [bp-58h]@1
  int v28; // [sp+1Ch] [bp-54h]@10
  int v29; // [sp+20h] [bp-50h]@11
  int v30; // [sp+24h] [bp-4Ch]@12
  int v31; // [sp+28h] [bp-48h]@12
  int v32; // [sp+2Ch] [bp-44h]@12
  int v33; // [sp+30h] [bp-40h]@15
  int v34; // [sp+40h] [bp-30h]@10
  struct _SCAN *v35; // [sp+44h] [bp-2Ch]@9
  struct _JPEG_PROPERTIES *v36; // [sp+48h] [bp-28h]@11
  int v37; // [sp+4Ch] [bp-24h]@12
  int v38; // [sp+50h] [bp-20h]@12
  struct _FRAME *v39; // [sp+54h] [bp-1Ch]@11
  CPPEH_RECORD ms_exc; // [sp+58h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v21;
  v21 = 0;
  v22 = 0;
  v23 = 0;
  v24 = 0;
  v25 = 0;
  v26 = a2->ctx;
  ms_exc.registration.TryLevel = 0;
  v24 = sub_640860(a2, (int)&v27);
  if ( !v24 )
  {
    if ( v27 >= 2 )
    {
      *(_DWORD *)v26 = v27 + 2;
      v27 -= 2;
      v24 = Get_Marker_Data_Into_Contiguous_Buffer(a2, v27, &v22, &v21, &v23);
      if ( !v24 )
      {
        v5 = (int *)v21++;
        a4->ncomps = *(_BYTE *)v5;
        a4->comps = (_SCAN_COMPONENT *)operator new(24 * a4->ncomps);
        v35 = a4;
        v6 = (int)&a4->comps->comp;
        if ( v6 )
        {
          v25 = &a4->comps->comp;
          v34 = 0;
          v28 = 0;
          if ( v35->ncomps <= 0 )
          {
LABEL_23:
            v20 = v21++;
            v35->start_spec = *v20;
            v21 = v20 + 2;
            a4->end_spec = v20[1];
            a4->approx_high = (signed int)v20[2] >> 4;
            v21 = v20 + 3;
            a4->approx_low = v20[2] & 0xF;
            ms_exc.registration.TryLevel = -1;
          }
          else
          {
            v29 = v6;
            v39 = a3;
            v36 = a1;
            while ( 1 )
            {
              v7 = v21++;
              v8 = *v7;
              v30 = *v7;
              v9 = (signed int)v7[1] >> 4;
              v38 = v9;
              v31 = v9;
              v21 = v7 + 2;
              v10 = v7[1] & 0xF;
              v37 = v10;
              v32 = v10;
              if ( v9 < 0 || v9 > 4 || v10 > 4 )
                break;
              v11 = 0;
              v33 = 0;
              v12 = v39->ncomps;
              if ( v12 > 0 )
              {
                v13 = v39->comps;
                do
                {
                  if ( v8 == v13[v11].ident )
                    break;
                  ++v11;
                  v33 = v11;
                }
                while ( v11 < v12 );
              }
              if ( v11 >= v12 || (v14 = v11, v15 = v39->comps[v11].quant_sel, v15 < 0) || v15 > 4 )
              {
                v24 = -21;
                operator delete(v35->comps);
                a4->comps = 0;
                goto LABEL_4;
              }
              *(_DWORD *)v6 = v11;
              v16 = v39;
              *(_DWORD *)(v6 + 4) = v39->comps[v14].hsampling;
              *(_DWORD *)(v6 + 8) = v16->comps[v14].vsampling;
              v17 = v38;
              v18 = v36;
              *(_DWORD *)(v6 + 12) = (char *)v36 + 1648 * v38 + 7460;
              *(_DWORD *)(v6 + 16) = (char *)v18 + 1648 * v37 + 868;
              *(_DWORD *)(v6 + 20) = (char *)v18 + 180 * v16->comps[v14].quant_sel + 148;
              v19 = v34;
              v18->HuffIdentifierDC[v34] = v17;
              v18->HuffIdentifierAC[v19] = v37;
              v34 = v19 + 1;
              v28 = v19 + 1;
              v6 += 24;
              v25 = (int *)v6;
              v35 = a4;
              if ( v19 + 1 >= a4->ncomps )
                goto LABEL_23;
            }
            v24 = -21;
            operator delete(v35->comps);
            a4->comps = 0;
          }
        }
        else
        {
          v24 = -5;
        }
      }
    }
    else
    {
      v24 = -21;
    }
  }
LABEL_4:
  if ( v23 && v22 )
  {
    operator delete(v22);
    v22 = 0;
  }
  return v24;
}

//----- (00647FE0) --------------------------------------------------------  // acclient.c:607443
signed int __cdecl Decode_Scan(enum IJL_MARKER *a1, struct _STATE *a2, struct _SCAN *a3, struct _JPEG_PROPERTIES *a4)
{
  _DCTTYPE v4; // eax@1
  int v5; // ecx@2
  int v6; // esi@2
  int v7; // edi@2
  int v8; // edx@2
  int v9; // ecx@4
  int v10; // esi@4
  int v11; // edi@4
  int v12; // edx@4
  int v13; // ecx@5
  int v14; // esi@5
  int v15; // edi@5
  int v16; // edx@5
  int v17; // edi@6
  int v18; // esi@6
  int v19; // ecx@8
  int v20; // edx@8
  int v21; // eax@8
  int v22; // eax@9
  _IJLIOTYPE v23; // eax@21
  int v24; // ebx@28
  _ENTROPYSTRUCT *v26; // eax@42
  _IJLIOTYPE v27; // edx@43
  _ENTROPYSTRUCT *v28; // eax@49
  signed int v29; // edx@49
  signed int v30; // eax@49
  _IJLIOTYPE v31; // eax@56
  void *v32; // [sp+14h] [bp-18h]@1
  int v33; // [sp+18h] [bp-14h]@8

  v32 = a2->ctx;
  *(_DWORD *)a1 = 0;
  v4 = a4->dcttype;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v9 = *((_DWORD *)v32 + 14);
      *((_DWORD *)v32 + 18) = *((_DWORD *)v32 + 13);
      v10 = *((_DWORD *)v32 + 15);
      v11 = *((_DWORD *)v32 + 16);
      *((_DWORD *)v32 + 19) = v9;
      v12 = *((_DWORD *)v32 + 67);
      *((_DWORD *)v32 + 20) = v10;
      *((_DWORD *)v32 + 21) = v11;
      *((_DWORD *)v32 + 68) = v12;
    }
    else
    {
      v13 = *((_DWORD *)v32 + 10);
      *((_DWORD *)v32 + 18) = *((_DWORD *)v32 + 9);
      v14 = *((_DWORD *)v32 + 11);
      v15 = *((_DWORD *)v32 + 12);
      *((_DWORD *)v32 + 19) = v13;
      v16 = *((_DWORD *)v32 + 66);
      *((_DWORD *)v32 + 20) = v14;
      *((_DWORD *)v32 + 21) = v15;
      *((_DWORD *)v32 + 68) = v16;
    }
  }
  else
  {
    v5 = *((_DWORD *)v32 + 10);
    *((_DWORD *)v32 + 18) = *((_DWORD *)v32 + 9);
    v6 = *((_DWORD *)v32 + 11);
    v7 = *((_DWORD *)v32 + 12);
    *((_DWORD *)v32 + 19) = v5;
    v8 = *((_DWORD *)v32 + 66);
    *((_DWORD *)v32 + 20) = v6;
    *((_DWORD *)v32 + 21) = v7;
    *((_DWORD *)v32 + 68) = v8;
  }
  v17 = a4->roi.right;
  v18 = a4->JPGWidth;
  if ( v17 < v18 && v17 )
  {
    v19 = a4->JPGHeight;
    v20 = a4->roi.top;
    v33 = a4->roi.bottom;
    v21 = a4->roi.left;
  }
  else
  {
    v22 = a4->roi.bottom;
    v19 = a4->JPGHeight;
    v33 = a4->roi.bottom;
    if ( v22 < v19 && v22 )
    {
      v20 = a4->roi.top;
      v21 = a4->roi.left;
    }
    else
    {
      v20 = a4->roi.top;
      if ( v20 <= 0 )
      {
        v21 = a4->roi.left;
        if ( v21 <= 0 )
        {
          v31 = a4->iotype;
          if ( a4->iotype == 18 || v31 == 19 )
          {
            if ( a4->progressive_found )
              v24 = sub_643930(a2, a3, a4, 8);
            else
              v24 = sub_646040(a2, a3, a4, 8);
          }
          else if ( v31 == 16 || v31 == 17 )
          {
            if ( a4->progressive_found )
              v24 = sub_643930(a2, a3, a4, 4);
            else
              v24 = sub_646040(a2, a3, a4, 4);
          }
          else if ( v31 != 14 && v31 != 15 )
          {
            if ( a4->progressive_found )
              v24 = sub_643930(a2, a3, a4, 1);
            else
              v24 = sub_646040(a2, a3, a4, 1);
          }
          else if ( a4->progressive_found )
          {
            v24 = sub_643930(a2, a3, a4, 2);
          }
          else
          {
            v24 = sub_646040(a2, a3, a4, 2);
          }
          goto LABEL_33;
        }
      }
      else
      {
        v21 = a4->roi.left;
      }
    }
  }
  if ( v18 >= v17 )
    v18 = a4->roi.right;
  a4->roi.right = v18;
  if ( v19 >= v33 )
    v19 = v33;
  a4->roi.bottom = v19;
  if ( v21 < 0 )
    v21 = 0;
  a4->roi.left = v21;
  if ( v20 < 0 )
    v20 = 0;
  a4->roi.top = v20;
  if ( !a4->rowoffsets )
  {
    v26 = (_ENTROPYSTRUCT *)operator new(0x50000u);
    a4->rowoffsets = v26;
    if ( !v26 )
      return -5;
    v27 = a4->iotype;
    if ( a4->iotype == 2 || v27 == 6 || v27 == 14 || v27 == 16 || v27 == 18 )
      v26->offset = a2->entropy_bytes_processed;
    else
      v26->offset = (unsigned int)a2->cur_entropy_ptr;
    a4->rowoffsets->dcval1 = 0;
    a4->rowoffsets->dcval2 = 0;
    a4->rowoffsets->dcval3 = 0;
    a4->rowoffsets->dcval4 = 0;
    v28 = a4->rowoffsets;
    LODWORD(v28->bit_buffer_64) = 0;
    HIDWORD(v28->bit_buffer_64) = 0;
    a4->rowoffsets->bitbuf_bits_valid = 0;
    a4->rowoffsets->unread_marker = a2->unread_marker;
    v29 = 1;
    v30 = 1;
    do
    {
      v29 += 5;
      a4->rowoffsets[v30].offset = -1;
      a4->rowoffsets[v30 + 1].offset = -1;
      a4->rowoffsets[v30 + 2].offset = -1;
      a4->rowoffsets[v30 + 3].offset = -1;
      a4->rowoffsets[v30 + 4].offset = -1;
      v30 += 5;
    }
    while ( v29 < 8187 );
    a4->rowoffsets[v29].offset = -1;
  }
  v23 = a4->iotype;
  if ( a4->iotype == 18 || v23 == 19 )
  {
    if ( a4->progressive_found )
      v24 = sub_644CE0(a2, a3, a4, 8);
    else
      v24 = sub_646B40(a2, a3, a4, 8);
  }
  else if ( v23 == 16 || v23 == 17 )
  {
    if ( a4->progressive_found )
      v24 = sub_644CE0(a2, a3, a4, 4);
    else
      v24 = sub_646B40(a2, a3, a4, 4);
  }
  else if ( v23 != 14 && v23 != 15 )
  {
    if ( a4->progressive_found )
      v24 = sub_644CE0(a2, a3, a4, 1);
    else
      v24 = sub_646B40(a2, a3, a4, 1);
  }
  else if ( a4->progressive_found )
  {
    v24 = sub_644CE0(a2, a3, a4, 2);
  }
  else
  {
    v24 = sub_646B40(a2, a3, a4, 2);
  }
LABEL_33:
  if ( !v24 )
    DB_Align_Byte(a2);
  (*((void (**)(void))v32 + 6))();
  return v24;
}

//----- (00648570) --------------------------------------------------------  // acclient.c:607694
signed int __cdecl Buffer_Read_Bytes(struct _STATE *a1)
{
  int v1; // ebp@1
  int v2; // eax@2
  unsigned int NumberOfBytesRead; // [sp+10h] [bp-14h]@1

  v1 = 0;
  if ( !ownReadFile(a1->file, a1->JPGBuffer, 0x1000u, &NumberOfBytesRead) )
  {
    v2 = NumberOfBytesRead;
    goto LABEL_5;
  }
  v2 = NumberOfBytesRead;
  if ( NumberOfBytesRead )
  {
LABEL_5:
    a1->entropy_bytes_left = v2;
    a1->cur_entropy_ptr = a1->JPGBuffer;
    a1->end_entropy_ptr = &a1->JPGBuffer[v2];
    return v1;
  }
  return -23;
}

//----- (006485D0) --------------------------------------------------------  // acclient.c:607719
signed int __cdecl DB_Get_Data(struct _STATE *a1, unsigned __int32 a2, unsigned __int8 **a3)
{
  int v3; // ecx@2
  unsigned __int8 *v4; // edx@3
  signed int result; // eax@4

  *a3 = 0;
  if ( a1->file )
  {
    v3 = a1->entropy_bytes_left;
    if ( a2 > v3 )
    {
      result = Buffer_Read_Bytes(a1);
      if ( result )
        return result;
      v3 = a1->entropy_bytes_left;
      if ( a2 > v3 )
        return -24;
    }
  }
  else
  {
    v3 = a1->entropy_bytes_left;
  }
  v4 = (unsigned __int8 *)a1->cur_entropy_ptr;
  if ( a2 <= v3 )
  {
    a1->cur_entropy_ptr = (char *)&v4[a2];
    result = 0;
    a1->entropy_bytes_processed += a2;
    a1->entropy_bytes_left = v3 - a2;
    *a3 = v4;
  }
  else
  {
    result = -5;
  }
  return result;
}

//----- (00648660) --------------------------------------------------------  // acclient.c:607766
signed int __cdecl DB_Skip_To_Next_Marker(struct _STATE *a1)
{
  signed int result; // eax@1
  char *i; // edx@1
  char v3; // bl@5
  int v4; // edx@5
  char *v5; // esi@6
  int v6; // ecx@6
  char *v7; // edi@7

  result = 0;
  for ( i = a1->cur_entropy_ptr; ; i = a1->cur_entropy_ptr )
  {
    while ( 1 )
    {
      if ( i >= a1->end_entropy_ptr )
      {
        if ( !a1->file )
          return -5;
        result = Buffer_Read_Bytes(a1);
        if ( result )
          return result;
      }
      v3 = 0;
      v4 = a1->entropy_bytes_left;
      if ( v4 > 0 )
      {
        v5 = a1->cur_entropy_ptr;
        v6 = a1->entropy_bytes_processed;
        do
        {
          --v4;
          ++v6;
          v7 = v5;
          a1->entropy_bytes_left = v4;
          ++v5;
          a1->entropy_bytes_processed = v6;
          a1->cur_entropy_ptr = v5;
          if ( (unsigned __int8)*v7 == 255 )
            v3 = 1;
        }
        while ( v4 > 0 && !v3 );
      }
      if ( v4 <= 0 )
        break;
LABEL_12:
      i = a1->cur_entropy_ptr;
      if ( (unsigned __int8)*i != 255 )
      {
        if ( *i )
          return result;
        ++a1->entropy_bytes_processed;
        ++i;
        a1->cur_entropy_ptr = i;
        --a1->entropy_bytes_left;
      }
    }
    if ( !a1->file )
      break;
    result = Buffer_Read_Bytes(a1);
    if ( result )
      return result;
    if ( v3 )
      goto LABEL_12;
  }
  return -5;
}

//----- (00648730) --------------------------------------------------------  // acclient.c:607835
signed int __cdecl Set_Decode_Fast_Path(struct _JPEG_PROPERTIES *a1)
{
  _IJL_COLOR v1; // ecx@1
  _IJL_COLOR v2; // eax@5
  int v3; // ebp@8
  int v4; // ebx@8
  int v5; // ecx@8
  _FRAME_COMPONENT *v6; // edi@9
  int v7; // edx@9
  int v8; // ecx@9
  int v9; // ebx@10
  int v10; // ebx@12
  int v11; // edi@19
  int v12; // ebx@20
  int v13; // ebp@20
  int v14; // ebx@21
  signed int v15; // eax@21
  int v16; // eax@21
  signed int result; // eax@60
  _FRAME_COMPONENT *v18; // edx@64
  int v19; // eax@64
  _UPSAMPLING_TYPE v20; // eax@74
  _UPSAMPLING_TYPE v21; // eax@85
  _FRAME_COMPONENT *v22; // edx@91
  int v23; // eax@91
  _UPSAMPLING_TYPE v24; // eax@99
  _UPSAMPLING_TYPE v25; // eax@108
  _IJL_COLOR v26; // eax@113
  _FRAME_COMPONENT *v27; // edx@115
  int v28; // eax@115
  _UPSAMPLING_TYPE v29; // eax@123
  _UPSAMPLING_TYPE v30; // eax@132
  _FRAME_COMPONENT *v31; // edx@136
  int v32; // eax@136
  _UPSAMPLING_TYPE v33; // eax@144
  _UPSAMPLING_TYPE v34; // eax@153
  _FRAME_COMPONENT *v35; // edx@171
  int v36; // eax@171
  _UPSAMPLING_TYPE v37; // eax@181
  _UPSAMPLING_TYPE v38; // eax@192
  _IJL_COLOR v39; // eax@212
  _FRAME_COMPONENT *v40; // edx@229
  _FRAME_COMPONENT *v41; // eax@246
  int v42; // [sp+4h] [bp-28h]@9
  int v43; // [sp+8h] [bp-24h]@9
  void *v44; // [sp+Ch] [bp-20h]@1
  char v45; // [sp+10h] [bp-1Ch]@8
  char v46; // [sp+14h] [bp-18h]@1
  _IJL_COLOR v47; // [sp+18h] [bp-14h]@1

  v1 = a1->JPGColor;
  v44 = a1->state.ctx;
  v46 = 1;
  v47 = a1->JPGColor;
  if ( v1 == 4 || v1 == 1 || v1 == 5 || v1 == 255 || (v2 = a1->DIBColor, v2 == 4) || v2 == 3 )
  {
    v46 = 0;
    a1->cconversion_reqd = 0;
  }
  else
  {
    a1->cconversion_reqd = 1;
  }
  v3 = 0;
  v45 = 0;
  v4 = 0;
  v5 = a1->jframe.ncomps;
  a1->upsampling_reqd = 0;
  a1->jframe.max_hsampling = 0;
  a1->jframe.max_vsampling = 0;
  if ( v5 > 0 )
  {
    v6 = a1->jframe.comps;
    v7 = 0;
    v42 = 0;
    v43 = v5;
    v8 = 0;
    do
    {
      v9 = v6[v7].hsampling;
      if ( v42 < v9 )
      {
        v42 = v6[v7].hsampling;
        a1->jframe.max_hsampling = v9;
      }
      v10 = v6[v7].vsampling;
      if ( v3 < v10 )
      {
        v3 = v6[v7].vsampling;
        a1->jframe.max_vsampling = v10;
      }
      if ( v6[v7].hsampling != 1 || v6[v7].vsampling != 1 )
      {
        if ( a1->DIBColor == 3 )
        {
          v45 = 0;
          a1->upsampling_reqd = 0;
        }
        else
        {
          v45 = 1;
          a1->upsampling_reqd = 1;
        }
      }
      ++v7;
      ++v8;
    }
    while ( v8 < v43 );
    v4 = v42;
    v5 = v43;
  }
  v11 = a1->jinterleaveType;
  if ( v11 == 1 )
  {
    a1->jframe.MCUheight = 8;
    v12 = 8 * v4;
    a1->jframe.MCUwidth = 8;
    v13 = 8 * v3;
  }
  else
  {
    v12 = 8 * v4;
    a1->jframe.MCUwidth = v12;
    v13 = 8 * v3;
    a1->jframe.MCUheight = v13;
  }
  v14 = (a1->JPGWidth + v12 - 1) / v12;
  v15 = a1->JPGHeight + v13 - 1;
  a1->numxMCUs = v14;
  v16 = v15 / v13;
  a1->numyMCUs = v16;
  a1->jframe.horMCU = v14;
  a1->jframe.totalMCU = v14 * v16;
  a1->fast_processing = 0;
  if ( v5 == 3
    && v47 == 3
    && a1->DIBColor == 3
    && ((v41 = a1->jframe.comps, v41->hsampling != 2)
     || v41->vsampling != 1
     || v41[1].hsampling != 1
     || v41[1].vsampling != 1
     || v41[2].hsampling != 1
     || v41[2].vsampling != 1) )
  {
    result = -8;
  }
  else if ( v5 <= 0 || v5 > 255 )
  {
    result = -14;
  }
  else
  {
    if ( v11 && !a1->progressive_found )
    {
      if ( a1->DIBColor == 3 )
        *((_DWORD *)v44 + 40) = YCbCr_422_to_YCbYCr_NI_MCU;
      else
        *((_DWORD *)v44 + 40) = US_General_MCU;
    }
    else if ( v45 && v46 )
    {
      if ( v5 != 3 || a1->DIBChannels != 3 )
      {
        if ( v5 != 3 || a1->DIBChannels != 4 )
        {
          if ( v5 == 4 && a1->DIBChannels == 4 && a1->DIBColor == 5 )
          {
            v18 = a1->jframe.comps;
            v19 = v18->hsampling;
            if ( v19 != 2
              || v18->vsampling != 1
              || v18[1].hsampling != 1
              || v18[1].vsampling != 1
              || v18[2].hsampling != 1
              || v18[2].vsampling != 1
              || v18[3].hsampling != 2
              || v18[3].vsampling != 1 )
            {
              if ( v19 != 2
                || v18->vsampling != 2
                || v18[1].hsampling != 1
                || v18[1].vsampling != 1
                || v18[2].hsampling != 1
                || v18[2].vsampling != 1
                || v18[3].hsampling != 2
                || v18[3].vsampling != 2 )
              {
                *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
              }
              else
              {
                v20 = a1->upsampling_type;
                if ( v20 )
                {
                  if ( v20 == 1 )
                    *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
                }
                else
                {
                  a1->fast_processing = 11;
                  *((_DWORD *)v44 + 40) = YCbCrA_FPX_4114_to_RGBA_FPX_MCU;
                }
              }
            }
            else
            {
              v21 = a1->upsampling_type;
              if ( v21 )
              {
                if ( v21 == 1 )
                  *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
              }
              else
              {
                a1->fast_processing = 12;
                *((_DWORD *)v44 + 40) = YCbCrA_FPX_4224_to_RGBA_FPX_MCU;
              }
            }
          }
        }
        else if ( a1->DIBColor == 5 )
        {
          v22 = a1->jframe.comps;
          v23 = v22->hsampling;
          if ( v23 != 2
            || v22->vsampling != 2
            || v22[1].hsampling != 1
            || v22[1].vsampling != 1
            || v22[2].hsampling != 1
            || v22[2].vsampling != 1 )
          {
            if ( v23 != 2
              || v22->vsampling != 1
              || v22[1].hsampling != 1
              || v22[1].vsampling != 1
              || v22[2].hsampling != 1
              || v22[2].vsampling != 1 )
            {
              *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              v24 = a1->upsampling_type;
              if ( v24 )
              {
                if ( v24 == 1 )
                  *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
              }
              else
              {
                a1->fast_processing = 9;
                *((_DWORD *)v44 + 40) = YCbCr_422_to_RGBA_FPX_MCU;
              }
            }
          }
          else
          {
            v25 = a1->upsampling_type;
            if ( v25 )
            {
              if ( v25 == 1 )
                *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              a1->fast_processing = 8;
              *((_DWORD *)v44 + 40) = YCbCr_411_to_RGBA_FPX_MCU;
            }
          }
        }
      }
      else
      {
        v26 = a1->DIBColor;
        if ( v26 == 1 )
        {
          v31 = a1->jframe.comps;
          v32 = v31->hsampling;
          if ( v32 != 2
            || v31->vsampling != 2
            || v31[1].hsampling != 1
            || v31[1].vsampling != 1
            || v31[2].hsampling != 1
            || v31[2].vsampling != 1 )
          {
            if ( v32 != 2
              || v31->vsampling != 1
              || v31[1].hsampling != 1
              || v31[1].vsampling != 1
              || v31[2].hsampling != 1
              || v31[2].vsampling != 1 )
            {
              *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              v33 = a1->upsampling_type;
              if ( v33 )
              {
                if ( v33 == 1 )
                  *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
              }
              else
              {
                a1->fast_processing = 5;
                *((_DWORD *)v44 + 40) = YCbCr_422_to_RGB_MCU;
              }
            }
          }
          else
          {
            v34 = a1->upsampling_type;
            if ( v34 )
            {
              if ( v34 == 1 )
                *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              a1->fast_processing = 3;
              *((_DWORD *)v44 + 40) = YCbCr_411_to_RGB_MCU;
            }
          }
        }
        else if ( v26 == 2 )
        {
          v27 = a1->jframe.comps;
          v28 = v27->hsampling;
          if ( v28 != 2
            || v27->vsampling != 2
            || v27[1].hsampling != 1
            || v27[1].vsampling != 1
            || v27[2].hsampling != 1
            || v27[2].vsampling != 1 )
          {
            if ( v28 != 2
              || v27->vsampling != 1
              || v27[1].hsampling != 1
              || v27[1].vsampling != 1
              || v27[2].hsampling != 1
              || v27[2].vsampling != 1 )
            {
              *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              v29 = a1->upsampling_type;
              if ( v29 )
              {
                if ( v29 == 1 )
                  *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
              }
              else
              {
                a1->fast_processing = 6;
                *((_DWORD *)v44 + 40) = YCbCr_422_to_BGR_MCU;
              }
            }
          }
          else
          {
            v30 = a1->upsampling_type;
            if ( v30 )
            {
              if ( v30 == 1 )
                *((_DWORD *)v44 + 40) = US_CC_General_YCbCr_MCU;
            }
            else
            {
              a1->fast_processing = 4;
              *((_DWORD *)v44 + 40) = YCbCr_411_to_BGR_MCU;
            }
          }
        }
      }
    }
    else if ( !v45 || v46 )
    {
      if ( v45 || !v46 )
      {
        if ( !v45 && !v46 )
        {
          if ( v5 == 1 && a1->DIBChannels == 1 )
          {
            *((_DWORD *)v44 + 40) = Y_111_to_Y_MCU;
            v5 = a1->jframe.ncomps;
          }
          if ( v5 != 1 || a1->DIBChannels == 1 )
          {
            if ( v5 == 2 )
            {
              *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
            }
            else if ( v5 != 3 || a1->DIBChannels != 1 )
            {
              if ( v5 != 3 || a1->DIBChannels != 2 )
              {
                if ( v5 != 3 || a1->DIBChannels != 3 )
                {
                  if ( v5 != 3 || a1->DIBChannels != 4 )
                  {
                    if ( v5 != 4 || a1->DIBChannels != 3 )
                    {
                      if ( v5 == 4 && a1->DIBChannels == 4 )
                      {
                        a1->fast_processing = 14;
                        *((_DWORD *)v44 + 40) = OTHER_1111_to_OTHER_MCU;
                      }
                    }
                    else
                    {
                      a1->fast_processing = 0;
                      *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
                    }
                  }
                  else if ( a1->DIBColor == 5 )
                  {
                    a1->fast_processing = 13;
                    *((_DWORD *)v44 + 40) = OTHER_111_to_OTHER4_MCU;
                  }
                  else
                  {
                    *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
                  }
                }
                else if ( a1->DIBColor == 2 )
                {
                  a1->fast_processing = 0;
                  *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
                }
                else
                {
                  a1->fast_processing = 15;
                  *((_DWORD *)v44 + 40) = OTHER_111_to_OTHER_MCU;
                }
              }
              else
              {
                v40 = a1->jframe.comps;
                if ( v40->hsampling == 2
                  && v40->vsampling == 1
                  && v40[1].hsampling == 1
                  && v40[1].vsampling == 1
                  && v40[2].hsampling == 1
                  && v40[2].vsampling == 1 )
                {
                  a1->fast_processing = 19;
                  *((_DWORD *)v44 + 40) = YCbCr_422_to_YCbYCr_MCU;
                }
              }
            }
            else
            {
              *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
            }
          }
          else
          {
            *((_DWORD *)v44 + 40) = Output_Interleave_General_MCU;
          }
        }
      }
      else if ( v5 != 3 || a1->DIBChannels != 3 )
      {
        if ( v5 != 3 || a1->DIBChannels != 4 )
        {
          if ( v5 == 4 && a1->DIBChannels == 4 && a1->DIBColor == 5 )
          {
            a1->fast_processing = 10;
            *((_DWORD *)v44 + 40) = YCbCrA_FPX_1111_to_RGBA_FPX_MCU;
          }
        }
        else if ( a1->DIBColor == 5 )
        {
          a1->fast_processing = 7;
          *((_DWORD *)v44 + 40) = YCbCr_111_to_RGBA_FPX_MCU;
        }
      }
      else
      {
        v39 = a1->DIBColor;
        if ( v39 == 1 )
        {
          a1->fast_processing = 1;
          *((_DWORD *)v44 + 40) = YCbCr_111_to_RGB_MCU;
        }
        else if ( v39 == 2 )
        {
          a1->fast_processing = 2;
          *((_DWORD *)v44 + 40) = YCbCr_111_to_BGR_MCU;
        }
      }
    }
    else if ( v5 != 3 || a1->DIBChannels != 1 )
    {
      if ( v5 != 3 || a1->DIBChannels != 3 )
      {
        if ( v5 != 3 || a1->DIBChannels != 4 )
        {
          if ( v5 != 4 || a1->DIBChannels != 3 )
          {
            if ( v5 == 4 && a1->DIBChannels == 4 )
            {
              if ( a1->progressive_found )
                *((_DWORD *)v44 + 40) = US_General_P_MCU;
              else
                *((_DWORD *)v44 + 40) = US_General_MCU;
            }
          }
          else if ( a1->progressive_found )
          {
            *((_DWORD *)v44 + 40) = US_General_P_MCU;
          }
          else
          {
            *((_DWORD *)v44 + 40) = US_General_MCU;
          }
        }
        else if ( a1->progressive_found )
        {
          *((_DWORD *)v44 + 40) = US_General_P_MCU;
        }
        else
        {
          *((_DWORD *)v44 + 40) = US_General_MCU;
        }
      }
      else if ( a1->DIBColor == 2 )
      {
        if ( a1->progressive_found )
          *((_DWORD *)v44 + 40) = US_General_P_MCU;
        else
          *((_DWORD *)v44 + 40) = US_General_MCU;
      }
      else
      {
        v35 = a1->jframe.comps;
        v36 = v35->hsampling;
        if ( v36 != 2
          || v35->vsampling != 2
          || v35[1].hsampling != 1
          || v35[1].vsampling != 1
          || v35[2].hsampling != 1
          || v35[2].vsampling != 1 )
        {
          if ( v36 != 2
            || v35->vsampling != 1
            || v35[1].hsampling != 1
            || v35[1].vsampling != 1
            || v35[2].hsampling != 1
            || v35[2].vsampling != 1 )
          {
            if ( a1->progressive_found )
              *((_DWORD *)v44 + 40) = US_General_P_MCU;
            else
              *((_DWORD *)v44 + 40) = US_General_MCU;
          }
          else
          {
            a1->fast_processing = 17;
            v37 = a1->upsampling_type;
            if ( v37 )
            {
              if ( v37 == 1 )
              {
                if ( a1->progressive_found )
                  *((_DWORD *)v44 + 40) = US_General_P_MCU;
                else
                  *((_DWORD *)v44 + 40) = US_General_MCU;
              }
            }
            else
            {
              *((_DWORD *)v44 + 40) = OTHER_422_to_OTHER_MCU;
            }
          }
        }
        else
        {
          a1->fast_processing = 16;
          v38 = a1->upsampling_type;
          if ( v38 )
          {
            if ( v38 == 1 )
            {
              if ( a1->progressive_found )
                *((_DWORD *)v44 + 40) = US_General_P_MCU;
              else
                *((_DWORD *)v44 + 40) = US_General_MCU;
            }
          }
          else
          {
            *((_DWORD *)v44 + 40) = OTHER_411_to_OTHER_MCU;
          }
        }
      }
    }
    else if ( a1->progressive_found )
    {
      *((_DWORD *)v44 + 40) = US_General_P_MCU;
    }
    else
    {
      *((_DWORD *)v44 + 40) = US_General_MCU;
    }
    result = 0;
  }
  return result;
}

//----- (00649510) --------------------------------------------------------  // acclient.c:608475
int __cdecl EP_Write_APP0(struct _JPEG_PROPERTIES *a1)
{
  void *v1; // esi@1
  int v2; // ecx@1
  int v3; // edx@1
  int v4; // ecx@1
  int v5; // ecx@1
  int v6; // edx@1
  char v7; // al@1
  int v8; // ecx@1
  int v9; // ecx@1
  int v10; // ecx@1
  char *v12; // [sp+10h] [bp-24h]@1
  char v13; // [sp+14h] [bp-20h]@1

  v1 = a1->state.ctx;
  v12 = &v13;
  sub_6494C0(-32, (int)&v12);
  sub_6494E0(16, (int)&v12);
  v2 = (int)v12++;
  *(_BYTE *)v2 = 74;
  v3 = (int)v12++;
  *(_BYTE *)v3 = 70;
  v4 = (int)v12++;
  *(_BYTE *)v4 = 73;
  v5 = (int)v12++;
  *(_BYTE *)v5 = 70;
  v6 = (int)v12++;
  *(_BYTE *)v6 = 0;
  sub_6494E0(a1->jfif_app0_version, (int)&v12);
  v7 = a1->jfif_app0_units;
  v8 = (int)v12++;
  *(_BYTE *)v8 = v7;
  sub_6494E0(a1->jfif_app0_Xdensity, (int)&v12);
  sub_6494E0(a1->jfif_app0_Ydensity, (int)&v12);
  v9 = (int)v12++;
  *(_BYTE *)v9 = 0;
  v10 = (int)v12++;
  *(_BYTE *)v10 = 0;
  return (*((int (__cdecl **)(char *, signed int, _STATE *))v1 + 23))(&v13, 18, &a1->state);
}

//----- (00649630) --------------------------------------------------------  // acclient.c:608518
signed int __cdecl EP_Write_COM(struct _JPEG_PROPERTIES *a1)
{
  signed int v1; // edx@2
  void *v2; // eax@5
  signed int v3; // eax@7
  void *v5; // [sp+0h] [bp-A0h]@1
  void *v6; // [sp+4h] [bp-9Ch]@1
  int v7; // [sp+8h] [bp-98h]@1
  unsigned int v8; // [sp+Ch] [bp-94h]@5
  void *v9; // [sp+10h] [bp-90h]@7
  int i; // [sp+14h] [bp-8Ch]@7
  LPCSTR lpString; // [sp+18h] [bp-88h]@14
  char v12; // [sp+1Ch] [bp-84h]@14
  int v13; // [sp+6Ch] [bp-34h]@14
  int v14; // [sp+70h] [bp-30h]@14
  int v15; // [sp+74h] [bp-2Ch]@14
  CPPEH_RECORD ms_exc; // [sp+88h] [bp-18h]@1

  ms_exc.old_esp = (DWORD)&v5;
  v5 = a1->state.ctx;
  ms_exc.registration.TryLevel = 0;
  v6 = 0;
  v7 = 0;
  if ( a1->jpeg_comment )
  {
    v1 = a1->jpeg_comment_size;
    if ( !a1->jpeg_comment_size )
    {
LABEL_10:
      ms_exc.registration.TryLevel = -1;
      return v7;
    }
    if ( v1 > 65531 )
    {
      a1->jpeg_comment_size = -5;
      v1 = 65531;
    }
    v8 = v1 + 4;
    v2 = operator new(v1 + 4);
    v6 = v2;
    if ( !v2 )
      return -5;
    v9 = v2;
    __g_memzero(v2, v8);
    sub_6494C0(-2, (int)&v9);
    sub_6494E0(v8 - 2, (int)&v9);
    v3 = 0;
    for ( i = 0; v3 < a1->jpeg_comment_size; i = v3 )
    {
      *((_BYTE *)v9 + v3) = a1->jpeg_comment[v3];
      ++v3;
    }
    v7 = (*((int (__cdecl **)(void *, unsigned int, _STATE *, int *))v5 + 23))(v6, v8, &a1->state, &v5);
    if ( !v7 )
    {
      operator delete(v6);
      goto LABEL_10;
    }
  }
  else
  {
    lpString = aIntelRJpegLibr;
    v6 = &v12;
    __g_memzero(&v12, 0x50u);
    v13 = (int)ownGetLibVersion();
    v14 = lstrlenA(lpString);
    v15 = gpfnwsprintf((char *)v6 + 4, lpString, *(_DWORD *)(v13 + 20), &v5);
    v8 = v15 + 5;
    sub_6494C0(-2, (int)&v6);
    sub_6494E0(v8 - 2, (int)&v6);
    if ( v15 <= v14 )
      goto LABEL_10;
    v7 = (*(int (__cdecl **)(char *, unsigned int, _STATE *, void **))((int (__cdecl **)(char *, _DWORD, _DWORD, _DWORD))v5
                                                                     + 23))(
           &v12,
           v8,
           &a1->state,
           &v5);
    if ( !v7 )
      goto LABEL_10;
  }
  return v7;
}
// 8F75A4: using guessed type void (__cdecl *__g_memzero)(void *, unsigned int);
// 8F75B8: using guessed type int (*gpfnwsprintf)(char *, const char *, ...);

//----- (006498D0) --------------------------------------------------------  // acclient.c:608605
int __cdecl EP_Write_SOI(struct _STATE *a1)
{
  void *v1; // ebp@1
  char *v3; // [sp+10h] [bp-14h]@1
  char v4; // [sp+14h] [bp-10h]@1

  v1 = a1->ctx;
  v3 = &v4;
  sub_6494C0(-40, (int)&v3);
  return (*((int (__cdecl **)(char *, signed int, struct _STATE *))v1 + 23))(&v4, 2, a1);
}

//----- (00649920) --------------------------------------------------------  // acclient.c:608618
int __cdecl EP_Write_EOI(struct _STATE *a1)
{
  void *v1; // ebp@1
  char *v3; // [sp+10h] [bp-14h]@1
  char v4; // [sp+14h] [bp-10h]@1

  v1 = a1->ctx;
  v3 = &v4;
  sub_6494C0(-39, (int)&v3);
  return (*((int (__cdecl **)(char *, signed int, struct _STATE *))v1 + 23))(&v4, 2, a1);
}

//----- (00649970) --------------------------------------------------------  // acclient.c:608631
int __cdecl EP_Write_SOF(struct _STATE *a1, struct _FRAME *a2)
{
  int v2; // esi@1
  int v3; // edx@1
  int v4; // ecx@1
  char v5; // al@1
  int v6; // ecx@1
  int v7; // eax@2
  int v8; // eax@2
  int v9; // edx@2
  int v10; // edi@2
  int v11; // eax@2
  signed int v12; // edi@3
  int v13; // edx@4
  int v14; // edx@4
  int v15; // esi@4
  char v16; // cl@4
  int *v17; // esi@4
  int v19; // eax@7
  int v20; // edi@7
  char v21; // bl@7
  int v22; // eax@7
  int v23; // [sp+10h] [bp+8h]@1
  int *v24; // [sp+31Ch] [bp+314h]@1
  int v25; // [sp+320h] [bp+318h]@3

  v2 = (int)a1->ctx;
  v24 = &v23;
  v3 = a2->ncomps;
  sub_6494C0(-64, (int)&v24);
  sub_6494E0((__int16)a1, (int)&v24);
  v4 = (int)v24;
  v24 = (int *)((char *)v24 + 1);
  *(_BYTE *)v4 = 8;
  sub_6494E0(a2->height, (int)&v24);
  sub_6494E0(a2->width, (int)&v24);
  v5 = LOBYTE(a2->ncomps);
  v6 = (int)v24;
  v24 = (int *)((char *)v24 + 1);
  *(_BYTE *)v6 = v5;
  if ( a2->ncomps == 1 )
  {
    v19 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v19 = 0;
    v20 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v20 = 17;
    v21 = LOBYTE(a2->comps->quant_sel);
    v22 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v22 = v21;
  }
  else
  {
    v7 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v7 = 1;
    v8 = a2->comps->vsampling + 16 * a2->comps->hsampling;
    v9 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v9 = v8;
    LOBYTE(v9) = LOBYTE(a2->comps->quant_sel);
    v10 = (int)v24;
    v24 = (int *)((char *)v24 + 1);
    *(_BYTE *)v10 = v9;
    v11 = 2;
    if ( a2->ncomps >= 2 )
    {
      v12 = 2;
      v25 = v2;
      do
      {
        v13 = (int)v24;
        v24 = (int *)((char *)v24 + 1);
        *(_BYTE *)v13 = v11;
        v14 = *((_DWORD *)&a2->comps[v12] - 2) + 16 * *((_DWORD *)&a2->comps[v12] - 3);
        v15 = (int)v24;
        v24 = (int *)((char *)v24 + 1);
        ++v11;
        *(_BYTE *)v15 = v14;
        v16 = *((_BYTE *)&a2->comps[v12] - 4);
        v17 = v24;
        ++v12;
        v24 = (int *)((char *)v24 + 1);
        *(_BYTE *)v17 = v16;
      }
      while ( v11 <= a2->ncomps );
      v2 = v25;
    }
  }
  return (*(int (__cdecl **)(int *, char *, struct _STATE *))(v2 + 92))(&v23, (char *)&a1->bit_buffer_64 + 2, a1);
}

//----- (00649B60) --------------------------------------------------------  // acclient.c:608726
int __cdecl EP_Write_SOF2(struct _STATE *a1, struct _FRAME *a2)
{
  int v2; // esi@1
  int v3; // edx@1
  int v4; // ecx@1
  char v5; // al@1
  int v6; // edx@1
  int v7; // edx@1
  int v8; // eax@2
  int v9; // edi@3
  int v10; // edx@4
  int v11; // edx@4
  int v12; // esi@4
  char v13; // cl@4
  int *v14; // esi@4
  int v16; // eax@7
  int v17; // edi@7
  char v18; // bl@7
  int v19; // eax@7
  int v20; // [sp+10h] [bp+8h]@1
  int *v21; // [sp+31Ch] [bp+314h]@1
  int v22; // [sp+320h] [bp+318h]@3

  v2 = (int)a1->ctx;
  v21 = &v20;
  v3 = a2->ncomps;
  sub_6494C0(-62, (int)&v21);
  sub_6494E0((__int16)a1, (int)&v21);
  v4 = (int)v21;
  v21 = (int *)((char *)v21 + 1);
  *(_BYTE *)v4 = 8;
  sub_6494E0(a2->height, (int)&v21);
  sub_6494E0(a2->width, (int)&v21);
  v5 = LOBYTE(a2->ncomps);
  v6 = (int)v21;
  v21 = (int *)((char *)v21 + 1);
  *(_BYTE *)v6 = v5;
  v7 = a2->ncomps;
  if ( v7 == 1 )
  {
    v16 = (int)v21;
    v21 = (int *)((char *)v21 + 1);
    *(_BYTE *)v16 = 0;
    v17 = (int)v21;
    v21 = (int *)((char *)v21 + 1);
    *(_BYTE *)v17 = 17;
    v18 = LOBYTE(a2->comps->quant_sel);
    v19 = (int)v21;
    v21 = (int *)((char *)v21 + 1);
    *(_BYTE *)v19 = v18;
  }
  else
  {
    v8 = 0;
    if ( v7 > 0 )
    {
      v9 = 0;
      v22 = v2;
      do
      {
        v10 = (int)v21;
        v21 = (int *)((char *)v21 + 1);
        *(_BYTE *)v10 = v8;
        v11 = a2->comps[v9].vsampling + 16 * a2->comps[v9].hsampling;
        v12 = (int)v21;
        v21 = (int *)((char *)v21 + 1);
        ++v8;
        *(_BYTE *)v12 = v11;
        v13 = LOBYTE(a2->comps[v9].quant_sel);
        v14 = v21;
        ++v9;
        v21 = (int *)((char *)v21 + 1);
        *(_BYTE *)v14 = v13;
      }
      while ( v8 < a2->ncomps );
      v2 = v22;
    }
  }
  return (*(int (__cdecl **)(int *, char *, struct _STATE *))(v2 + 92))(&v20, (char *)&a1->bit_buffer_64 + 2, a1);
}

//----- (00649D00) --------------------------------------------------------  // acclient.c:608808
int __cdecl EP_Write_DQT(struct _STATE *a1, int a2, int a3, __int16 *const a4)
{
  __int16 *const v4; // ebx@1
  void *v5; // edi@1
  signed int v6; // ebp@2
  int v7; // ecx@4
  __int16 v8; // ax@6
  int v9; // edx@6
  int v10; // ecx@6
  int v11; // edx@6
  int v12; // eax@6
  int v13; // edx@6
  int v14; // edi@6
  int v15; // edi@7
  signed int v16; // eax@8
  char *v18; // [sp+10h] [bp-A4h]@4
  char v19; // [sp+14h] [bp-A0h]@4
  int v20; // [sp+9Ch] [bp-18h]@5

  v4 = a4;
  v5 = a1->ctx;
  if ( a2 )
    v6 = 131;
  else
    v6 = 67;
  v18 = &v19;
  sub_6494C0(-37, (int)&v18);
  sub_6494E0(v6, (int)&v18);
  v7 = (int)v18++;
  *(_BYTE *)v7 = a3 + 16 * a2;
  if ( a2 )
  {
    v20 = (int)v5;
    do
    {
      v8 = *v4;
      v9 = (*v4 & 0xFF00) >> 8;
      v10 = (int)v18++;
      *(_BYTE *)v10 = v9;
      v11 = (int)v18++;
      *(_BYTE *)v11 = v8;
      LOWORD(v10) = v4[1];
      v12 = (v4[1] & 0xFF00) >> 8;
      v13 = (int)v18++;
      v4 += 2;
      *(_BYTE *)v13 = v12;
      v14 = (int)v18++;
      *(_BYTE *)v14 = v10;
    }
    while ( (signed int)(a4 + 64) > (signed int)v4 );
    v15 = v20;
  }
  else
  {
    v16 = 0;
    v20 = (int)v5;
    do
    {
      v18[v16] = LOBYTE(a4[v16]);
      v18[v16 + 1] = LOBYTE(a4[v16 + 1]);
      v18[v16 + 2] = LOBYTE(a4[v16 + 2]);
      v18[v16 + 3] = LOBYTE(a4[v16 + 3]);
      v16 += 4;
    }
    while ( v16 < 64 );
    v15 = v20;
  }
  return (*(int (__cdecl **)(char *, int, struct _STATE *))(v15 + 92))(&v19, v6 + 2, a1);
}

//----- (00649E70) --------------------------------------------------------  // acclient.c:608879
int __cdecl EP_Write_DHT_Ex(struct _STATE *a1, unsigned __int8 *a2, unsigned __int8 *a3, int a4, int a5)
{
  int v5; // esi@1
  int v6; // ebx@1
  int result; // eax@2
  int v8; // eax@3
  int v9; // edx@3
  int v10; // eax@3
  int v11; // edx@3
  int v12; // edx@3
  int v13; // edx@3
  int v14; // edx@3
  int v15; // edx@3
  int v16; // edx@3
  int v17; // edx@3
  int v18; // edx@3
  int v19; // edx@3
  int v20; // edx@3
  int v21; // edx@3
  int v22; // edx@3
  int v23; // edx@3
  int v24; // ecx@3
  char *v25; // edi@3
  bool v26; // zf@3
  bool v27; // sf@3
  int v28; // edx@5
  unsigned __int8 v29; // bl@6
  int v30; // esi@6
  unsigned __int8 v31; // bl@6
  int v32; // ebp@6
  unsigned __int8 v33; // bl@6
  int v34; // esi@6
  unsigned __int8 v35; // bl@6
  int v36; // esi@6
  unsigned __int8 v37; // bl@6
  int v38; // esi@6
  int v39; // edi@8
  unsigned __int8 v40; // al@9
  int v41; // ebp@9
  char *v42; // [sp+10h] [bp-16Ch]@1
  char v43; // [sp+14h] [bp-168h]@1
  int v44; // [sp+158h] [bp-24h]@1
  void *v45; // [sp+15Ch] [bp-20h]@1
  int v46; // [sp+160h] [bp-1Ch]@1
  int v47; // [sp+164h] [bp-18h]@5

  v45 = a1->ctx;
  v42 = &v43;
  sub_6494C0(-60, (int)&v42);
  v5 = a2[15];
  v44 = *a2
      + a2[1]
      + a2[2]
      + a2[3]
      + a2[4]
      + a2[5]
      + a2[6]
      + a2[7]
      + a2[8]
      + a2[9]
      + a2[10]
      + a2[11]
      + a2[12]
      + a2[13]
      + a2[14];
  v6 = v5 + v44 + 19;
  v46 = v5 + v44;
  sub_6494E0(v5 + v44 + 19, (int)&v42);
  if ( v6 <= 324 )
  {
    v8 = (int)v42++;
    *(_BYTE *)v8 = a5 + 16 * a4;
    LOBYTE(v8) = *a2;
    v9 = (int)v42++;
    *(_BYTE *)v9 = v8;
    LOBYTE(v9) = a2[1];
    v10 = (int)v42++;
    *(_BYTE *)v10 = v9;
    LOBYTE(v10) = a2[2];
    v11 = (int)v42++;
    *(_BYTE *)v11 = v10;
    LOBYTE(v10) = a2[3];
    v12 = (int)v42++;
    *(_BYTE *)v12 = v10;
    LOBYTE(v10) = a2[4];
    v13 = (int)v42++;
    *(_BYTE *)v13 = v10;
    LOBYTE(v10) = a2[5];
    v14 = (int)v42++;
    *(_BYTE *)v14 = v10;
    LOBYTE(v10) = a2[6];
    v15 = (int)v42++;
    *(_BYTE *)v15 = v10;
    LOBYTE(v10) = a2[7];
    v16 = (int)v42++;
    *(_BYTE *)v16 = v10;
    LOBYTE(v10) = a2[8];
    v17 = (int)v42++;
    *(_BYTE *)v17 = v10;
    LOBYTE(v10) = a2[9];
    v18 = (int)v42++;
    *(_BYTE *)v18 = v10;
    LOBYTE(v10) = a2[10];
    v19 = (int)v42++;
    *(_BYTE *)v19 = v10;
    LOBYTE(v10) = a2[11];
    v20 = (int)v42++;
    *(_BYTE *)v20 = v10;
    LOBYTE(v10) = a2[12];
    v21 = (int)v42++;
    *(_BYTE *)v21 = v10;
    LOBYTE(v10) = a2[13];
    v22 = (int)v42++;
    *(_BYTE *)v22 = v10;
    LOBYTE(v10) = a2[14];
    v23 = (int)v42++;
    v24 = 0;
    *(_BYTE *)v23 = v10;
    LOBYTE(v10) = a2[15];
    v25 = v42;
    v26 = v46 == 0;
    v27 = v46 < 0;
    ++v42;
    *v25 = v10;
    if ( !v27 && !v26 )
    {
      if ( v5 + v44 >= 6 )
      {
        v28 = v5 + v44 - 6;
        v47 = v6;
        do
        {
          v29 = a3[v24];
          v30 = (int)v42++;
          *(_BYTE *)v30 = v29;
          v31 = a3[v24 + 1];
          v32 = (int)v42++;
          *(_BYTE *)v32 = v31;
          v33 = a3[v24 + 2];
          v34 = (int)v42++;
          *(_BYTE *)v34 = v33;
          v35 = a3[v24 + 3];
          v36 = (int)v42++;
          *(_BYTE *)v36 = v35;
          v37 = a3[v24 + 4];
          v38 = (int)v42++;
          v24 += 5;
          *(_BYTE *)v38 = v37;
        }
        while ( v24 <= v28 );
        v6 = v47;
      }
      v39 = v46;
      do
      {
        v40 = a3[v24];
        v41 = (int)v42++;
        ++v24;
        *(_BYTE *)v41 = v40;
      }
      while ( v24 < v39 );
    }
    result = (*((int (__cdecl **)(char *, int, struct _STATE *))v45 + 23))(&v43, v6 + 2, a1);
  }
  else
  {
    result = -6;
  }
  return result;
}

//----- (0064A160) --------------------------------------------------------  // acclient.c:609051
int __cdecl EP_Write_DHTs(struct _STATE *a1, struct _JPEG_PROPERTIES *a2)
{
  struct _JPEG_PROPERTIES *v2; // ebp@1
  int v3; // esi@1
  int v4; // ecx@1
  int v5; // ebx@1
  int v6; // edi@1
  int v7; // eax@2
  char *v8; // esi@3
  int result; // eax@5
  int v10; // ebx@7
  char *v11; // edx@8
  int v12; // eax@8
  int v13; // esi@8
  char v14; // dl@9
  char v15; // cl@9
  char v16; // dl@9
  char v17; // dl@9
  char v18; // dl@9
  char v19; // dl@9
  char v20; // dl@9
  char v21; // dl@9
  char v22; // dl@9
  char v23; // dl@9
  char v24; // dl@9
  char v25; // dl@9
  char v26; // dl@9
  char v27; // dl@9
  char v28; // dl@9
  char v29; // dl@9
  char v30; // dl@9
  int v31; // edx@9
  char v32; // al@12
  int v33; // ecx@12
  char v34; // al@12
  int v35; // esi@12
  char v36; // al@12
  int v37; // esi@12
  int v38; // esi@12
  char v39; // al@12
  char *v40; // esi@12
  int v41; // esi@13
  int v42; // ecx@14
  char v43; // al@15
  char *v44; // ebp@15
  int v45; // edx@18
  char *v46; // [sp+10h] [bp-174h]@5
  char v47; // [sp+14h] [bp-170h]@5
  char v48; // [sp+15h] [bp-16Fh]@9
  char v49; // [sp+16h] [bp-16Eh]@9
  char v50; // [sp+17h] [bp-16Dh]@9
  char v51; // [sp+18h] [bp-16Ch]@9
  char v52; // [sp+1Ch] [bp-168h]@9
  char v53; // [sp+20h] [bp-164h]@9
  char v54; // [sp+24h] [bp-160h]@9
  int v55; // [sp+158h] [bp-2Ch]@2
  int v56; // [sp+15Ch] [bp-28h]@2
  int v57; // [sp+160h] [bp-24h]@7
  struct _JPEG_PROPERTIES *v58; // [sp+164h] [bp-20h]@7
  int v59; // [sp+168h] [bp-1Ch]@8
  int v60; // [sp+16Ch] [bp-18h]@8
  int v61; // [sp+170h] [bp-14h]@11

  v2 = a2;
  v3 = (int)a1->ctx;
  v4 = 0;
  v5 = 0;
  v6 = a2->maxhuffindex;
  if ( 2 * v6 > 0 )
  {
    v7 = 0;
    v55 = a2->maxhuffindex;
    v56 = v3;
    do
    {
      v8 = a2->rawhufftables[v7].bits;
      v5 += (unsigned __int8)v8[15]
          + (unsigned __int8)v8[14]
          + (unsigned __int8)v8[13]
          + (unsigned __int8)v8[12]
          + (unsigned __int8)v8[11]
          + (unsigned __int8)v8[10]
          + (unsigned __int8)v8[9]
          + (unsigned __int8)v8[8]
          + (unsigned __int8)v8[7]
          + (unsigned __int8)v8[6]
          + (unsigned __int8)v8[5]
          + (unsigned __int8)v8[4]
          + (unsigned __int8)v8[3]
          + (unsigned __int8)v8[2]
          + (unsigned __int8)v8[1]
          + (unsigned __int8)*v8;
      ++v7;
      ++v4;
    }
    while ( v4 < 2 * v6 );
    LOWORD(v6) = v55;
    v3 = v56;
  }
  v46 = &v47;
  sub_6494C0(-60, (int)&v46);
  sub_6494E0(34 * v6 + v5 + 2, (int)&v46);
  result = (*(int (__cdecl **)(char *, signed int, struct _STATE *))(v3 + 92))(&v47, 4, a1);
  if ( !result && 2 * a2->maxhuffindex > 0 )
  {
    v10 = 0;
    v58 = a2;
    v57 = 0;
    v56 = v3;
    while ( 1 )
    {
      v11 = v2->rawhufftables[v10].bits;
      v12 = (unsigned __int8)v11[14]
          + (unsigned __int8)v11[13]
          + (unsigned __int8)v11[12]
          + (unsigned __int8)v11[11]
          + (unsigned __int8)v11[10]
          + (unsigned __int8)v11[9]
          + (unsigned __int8)v11[8]
          + (unsigned __int8)v11[7]
          + (unsigned __int8)v11[6]
          + (unsigned __int8)v11[5]
          + (unsigned __int8)v11[4]
          + (unsigned __int8)v11[3]
          + (unsigned __int8)v11[2]
          + (unsigned __int8)v11[1]
          + (unsigned __int8)*v11;
      v13 = (unsigned __int8)v11[15];
      v55 = (unsigned __int8)v11[15];
      v59 = v12 + v13;
      v60 = v12 + v13 + 17;
      if ( v60 > 324 )
        break;
      v46 = &v47;
      v14 = v2->rawhufftables[v10].ident + 16 * v2->rawhufftables[v10].hclass;
      v46 = &v48;
      v47 = v14;
      v15 = *v2->rawhufftables[v10].bits;
      v46 = &v49;
      v48 = v15;
      v16 = v2->rawhufftables[v10].bits[1];
      v46 = &v50;
      v49 = v16;
      v17 = v2->rawhufftables[v10].bits[2];
      v46 = &v51;
      v50 = v17;
      v18 = v2->rawhufftables[v10].bits[3];
      v46 = &v51 + 1;
      v51 = v18;
      v19 = v2->rawhufftables[v10].bits[4];
      v46 = &v51 + 2;
      *(&v51 + 1) = v19;
      v20 = v2->rawhufftables[v10].bits[5];
      v46 = &v51 + 3;
      *(&v51 + 2) = v20;
      v21 = v2->rawhufftables[v10].bits[6];
      v46 = &v52;
      *(&v51 + 3) = v21;
      v22 = v2->rawhufftables[v10].bits[7];
      v46 = &v52 + 1;
      v52 = v22;
      v23 = v2->rawhufftables[v10].bits[8];
      v46 = &v52 + 2;
      *(&v52 + 1) = v23;
      v24 = v2->rawhufftables[v10].bits[9];
      v46 = &v52 + 3;
      *(&v52 + 2) = v24;
      v25 = v2->rawhufftables[v10].bits[10];
      v46 = &v53;
      *(&v52 + 3) = v25;
      v26 = v2->rawhufftables[v10].bits[11];
      v46 = &v53 + 1;
      v53 = v26;
      v27 = v2->rawhufftables[v10].bits[12];
      v46 = &v53 + 2;
      *(&v53 + 1) = v27;
      v28 = v2->rawhufftables[v10].bits[13];
      v46 = &v53 + 3;
      *(&v53 + 2) = v28;
      v29 = v2->rawhufftables[v10].bits[14];
      v46 = &v54;
      *(&v53 + 3) = v29;
      v30 = v2->rawhufftables[v10].bits[15];
      v46 = &v54 + 1;
      v54 = v30;
      v31 = 0;
      if ( v12 + v13 > 0 )
      {
        if ( v12 + v55 < 6 )
        {
          v41 = (int)&v58->rawhufftables[0].vals;
        }
        else
        {
          v55 = v12 + v55 - 6;
          v61 = (int)&v58->rawhufftables[0].vals;
          do
          {
            v32 = v2->rawhufftables[v10].vals[v31];
            v33 = (int)v46++;
            *(_BYTE *)v33 = v32;
            v34 = v2->rawhufftables[v10].vals[v31 + 1];
            v35 = (int)v46++;
            *(_BYTE *)v35 = v34;
            v36 = v2->rawhufftables[v10].vals[v31 + 2];
            v37 = (int)v46++;
            *(_BYTE *)v37 = v36;
            LOBYTE(v33) = v2->rawhufftables[v10].vals[v31 + 3];
            v38 = (int)v46++;
            *(_BYTE *)v38 = v33;
            v39 = v2->rawhufftables[v10].vals[v31 + 4];
            v40 = v46;
            v31 += 5;
            ++v46;
            *v40 = v39;
          }
          while ( v31 <= v55 );
          v41 = v61;
        }
        v42 = v59;
        do
        {
          v43 = *(_BYTE *)(v31 + *(_DWORD *)v41);
          v44 = v46;
          ++v31;
          ++v46;
          *v44 = v43;
        }
        while ( v31 < v42 );
        v2 = a2;
      }
      result = (*(int (__cdecl **)(char *, int, struct _STATE *))(v56 + 92))(&v47, v60, a1);
      if ( !result )
      {
        ++v10;
        v58 = (struct _JPEG_PROPERTIES *)((char *)v58 + 12);
        v45 = 2 * v2->maxhuffindex;
        ++v57;
        if ( v57 < v45 )
          continue;
      }
      return result;
    }
    result = -6;
  }
  return result;
}

//----- (0064A680) --------------------------------------------------------  // acclient.c:609300
int __usercall EP_Write_SOS@<eax>(int a1@<ebp>, struct _STATE *a2, int a3, char *a4, char *a5)
{
  int v5; // ebx@1
  int v6; // edx@1
  int v7; // ecx@2
  char v8; // al@2
  int v9; // ecx@2
  signed int v10; // eax@2
  int v11; // esi@5
  char v12; // bl@5
  int v13; // esi@5
  int v14; // esi@5
  char v15; // bl@5
  int v16; // esi@5
  int v17; // esi@5
  char v18; // bl@5
  int v19; // esi@5
  int v20; // edx@8
  int v21; // edx@8
  int v22; // esi@8
  int v23; // ecx@10
  int v24; // esi@10
  int v25; // edx@10
  int v27; // ecx@11
  int v28; // esi@11
  char *v29; // [sp+10h] [bp+Ah]@1
  char v30; // [sp+14h] [bp+Eh]@1
  int v31; // [sp+34h] [bp+2Eh]@4
  int v32; // [sp+38h] [bp+32h]@4
  int v33; // [sp+3Ch] [bp+36h]@4
  void *v34; // [sp+40h] [bp+3Ah]@1
  int v35; // [sp+44h] [bp+3Eh]@4

  v5 = a3;
  v34 = a2->ctx;
  v29 = &v30;
  sub_6494C0(-38, (int)&v29);
  sub_6494E0(a1, (int)&v29);
  v6 = (int)v29++;
  *(_BYTE *)v6 = a3;
  if ( a3 == 1 )
  {
    v27 = (int)v29++;
    *(_BYTE *)v27 = 0;
    v28 = (int)v29++;
    *(_BYTE *)v28 = 0;
  }
  else
  {
    v7 = (int)v29++;
    *(_BYTE *)v7 = 1;
    v8 = *a5 + 16 * *a4;
    v9 = (int)v29++;
    *(_BYTE *)v9 = v8;
    v10 = 2;
    if ( a3 >= 2 )
    {
      if ( a3 - 2 >= 4 )
      {
        v33 = 3;
        v32 = 4;
        v35 = a3 - 4;
        v31 = a1;
        do
        {
          v11 = (int)v29++;
          *(_BYTE *)v11 = v10;
          v12 = a5[v10 - 1] + 16 * a4[v10 - 1];
          v13 = (int)v29++;
          *(_BYTE *)v13 = v12;
          v14 = (int)v29++;
          *(_BYTE *)v14 = v33;
          v15 = a5[v10] + 16 * a4[v10];
          v16 = (int)v29++;
          *(_BYTE *)v16 = v15;
          v17 = (int)v29++;
          *(_BYTE *)v17 = v32;
          v18 = a5[v10 + 1] + 16 * a4[v10 + 1];
          v19 = (int)v29++;
          v10 += 3;
          *(_BYTE *)v19 = v18;
          v33 += 3;
          v32 += 3;
        }
        while ( v10 <= v35 );
        a1 = v31;
        v5 = a3;
      }
      v31 = a1;
      do
      {
        v20 = (int)v29++;
        *(_BYTE *)v20 = v10;
        v21 = (unsigned __int8)a5[v10 - 1] + 16 * (unsigned __int8)a4[v10 - 1];
        v22 = (int)v29++;
        ++v10;
        *(_BYTE *)v22 = v21;
      }
      while ( v10 <= v5 );
      a1 = v31;
    }
  }
  v23 = (int)v29++;
  *(_BYTE *)v23 = 0;
  v24 = (int)v29++;
  *(_BYTE *)v24 = 63;
  v25 = (int)v29++;
  *(_BYTE *)v25 = 0;
  return (*((int (__cdecl **)(char *, int, struct _STATE *))v34 + 23))(&v30, a1 + 2, a2);
}

//----- (0064A8A0) --------------------------------------------------------  // acclient.c:609412
int __cdecl EP_Write_SOS_Ex(struct _STATE *a1, struct _SCAN *a2, unsigned __int8 *a3, unsigned __int8 *a4)
{
  struct _STATE *v4; // ebp@1
  int v5; // esi@1
  int v6; // ecx@1
  char v7; // al@1
  int v8; // edx@1
  int v9; // eax@2
  int v10; // edi@4
  int v11; // edx@4
  int v12; // edi@4
  char v13; // al@6
  int v14; // edx@6
  int v15; // eax@6
  int v16; // ecx@6
  int v17; // edi@6
  char v19; // al@7
  int v20; // edx@7
  int v21; // ecx@7
  unsigned __int8 v22; // al@7
  int v23; // ecx@7
  char v24[6]; // [sp+Eh] [bp+8h]@1
  char v25; // [sp+14h] [bp+Eh]@1
  int v26; // [sp+24h] [bp+1Eh]@3
  struct _STATE *v27; // [sp+28h] [bp+22h]@3

  v4 = a1;
  v5 = (int)a1->ctx;
  v6 = a2->ncomps;
  *(_DWORD *)&v24[2] = &v25;
  sub_6494C0(-38, (int)&v24[2]);
  sub_6494E0((__int16)a1, (int)&v24[2]);
  v7 = LOBYTE(a2->ncomps);
  v8 = (*(_DWORD *)&v24[2])++;
  *(_BYTE *)v8 = v7;
  if ( a2->ncomps == 1 )
  {
    v19 = a2->comps->comp;
    v20 = (*(_DWORD *)&v24[2])++;
    *(_BYTE *)v20 = v19;
    v21 = a2->comps->comp;
    LOBYTE(v20) = 16 * a3[v21];
    v22 = a4[v21];
    v23 = (*(_DWORD *)&v24[2])++;
    *(_BYTE *)v23 = v22 + v20;
  }
  else
  {
    v9 = 0;
    if ( a2->ncomps > 0 )
    {
      v27 = a1;
      v26 = v5;
      do
      {
        v10 = (*(_DWORD *)&v24[2])++;
        *(_BYTE *)v10 = v9;
        v11 = a4[v9] + 16 * a3[v9];
        v12 = (*(_DWORD *)&v24[2])++;
        ++v9;
        *(_BYTE *)v12 = v11;
      }
      while ( v9 < a2->ncomps );
      v4 = v27;
      v5 = v26;
    }
  }
  v13 = LOBYTE(a2->start_spec);
  v14 = (*(_DWORD *)&v24[2])++;
  *(_BYTE *)v14 = v13;
  LOBYTE(v14) = LOBYTE(a2->end_spec);
  v15 = (*(_DWORD *)&v24[2])++;
  *(_BYTE *)v15 = v14;
  v16 = a2->approx_low + 16 * a2->approx_high;
  v17 = (*(_DWORD *)&v24[2])++;
  *(_BYTE *)v17 = v16;
  return (*(int (__cdecl **)(char *, int, struct _STATE *))(v5 + 92))(&v25, (char *)&v4->bit_buffer_64 + 2, a1);
}

//----- (0064A9F0) --------------------------------------------------------  // acclient.c:609492
int __cdecl EP_Write_DRI(int a1, struct _STATE *a2)
{
  void *v2; // ebx@1
  char *v4; // [sp+10h] [bp-1Ch]@1
  char v5; // [sp+14h] [bp-18h]@1

  v2 = a2->ctx;
  v4 = &v5;
  sub_6494C0(-35, (int)&v4);
  sub_6494E0(4, (int)&v4);
  sub_6494E0(a1, (int)&v4);
  return (*((int (__cdecl **)(char *, signed int, struct _STATE *))v2 + 23))(&v5, 6, a2);
}

//----- (0064AA60) --------------------------------------------------------  // acclient.c:609507
int __cdecl EP_Write_RST(int a1, struct _STATE *a2)
{
  void *v2; // ebp@1
  char v3; // dl@2
  int result; // eax@10
  char *v5; // [sp+10h] [bp-14h]@10
  char v6; // [sp+14h] [bp-10h]@10

  v2 = a2->ctx;
  switch ( a1 )
  {
    case 7:
      v3 = -41;
      goto LABEL_10;
    case 6:
      v3 = -42;
      goto LABEL_10;
    case 5:
      v3 = -43;
      goto LABEL_10;
    case 4:
      v3 = -44;
      goto LABEL_10;
    case 3:
      v3 = -45;
      goto LABEL_10;
    case 2:
      v3 = -46;
      goto LABEL_10;
    case 1:
      v3 = -47;
      goto LABEL_10;
    case 0:
      v3 = -48;
LABEL_10:
      v5 = &v6;
      sub_6494C0(v3, (int)&v5);
      result = (*((int (__cdecl **)(char *, signed int, struct _STATE *))v2 + 23))(&v6, 2, a2);
      break;
    default:
      result = -25;
      break;
  }
  return result;
}

//----- (0064AB00) --------------------------------------------------------  // acclient.c:609554
int __cdecl EP_Write_APP14(char a1, struct _JPEG_PROPERTIES *a2)
{
  void *v2; // ebp@1
  int v3; // edx@1
  int v4; // eax@1
  int v5; // edx@1
  int v6; // edx@1
  int v7; // edx@1
  int v8; // edx@1
  char *v10; // [sp+10h] [bp-24h]@1
  char v11; // [sp+14h] [bp-20h]@1

  v2 = a2->state.ctx;
  v10 = &v11;
  sub_6494C0(-18, (int)&v10);
  sub_6494E0(14, (int)&v10);
  v3 = (int)v10++;
  *(_BYTE *)v3 = 65;
  v4 = (int)v10++;
  *(_BYTE *)v4 = 100;
  v5 = (int)v10++;
  *(_BYTE *)v5 = 111;
  v6 = (int)v10++;
  *(_BYTE *)v6 = 98;
  v7 = (int)v10++;
  *(_BYTE *)v7 = 101;
  sub_6494E0(a2->AdobeVersion, (int)&v10);
  sub_6494E0(a2->AdobeFlags0, (int)&v10);
  sub_6494E0(a2->AdobeFlags1, (int)&v10);
  v8 = (int)v10++;
  *(_BYTE *)v8 = a1;
  return (*((int (__cdecl **)(char *, signed int, _STATE *))v2 + 23))(&v11, 16, &a2->state);
}

//----- (0064AC00) --------------------------------------------------------  // acclient.c:609589
signed int __cdecl Encode_Scan(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, struct _SCAN *a3)
{
  struct _JPEG_PROPERTIES *v3; // edi@1
  struct _SCAN *v4; // ebx@1
  signed int v5; // ebp@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // edx@1
  int v9; // esi@2
  int v10; // edx@2
  int v11; // ebx@2
  int v12; // ecx@5
  int v13; // ebp@5
  int v14; // ecx@5
  int v15; // ebp@5
  int v16; // ecx@7
  int v17; // ecx@8
  int v18; // esi@10
  int v19; // eax@11
  int v20; // ecx@11
  int v21; // eax@12
  int v22; // eax@13
  int v23; // ebp@14
  int v24; // ecx@14
  int v25; // edx@15
  _SCAN_COMPONENT *v26; // ecx@16
  int v27; // ebp@17
  int v28; // ebx@17
  int v29; // edi@18
  int v30; // edx@18
  int v31; // esi@19
  int v32; // eax@20
  void *v33; // ebp@22
  signed int v34; // ebx@22
  int v35; // esi@22
  int v36; // edx@31
  int v37; // esi@37
  int v38; // ebx@37
  int v39; // ebp@37
  int v40; // edi@37
  int v41; // esi@40
  int v42; // edx@41
  int v43; // edi@42
  int v44; // ebx@43
  _RAW_DATA_TYPES_STATE *v45; // eax@44
  int v46; // eax@47
  int v47; // edx@53
  int v49; // eax@58
  int v50; // esi@58
  signed int v51; // ebp@58
  int v52; // et2@58
  int v53[4]; // [sp+18h] [bp-A4h]@5
  int v54[4]; // [sp+28h] [bp-94h]@5
  int v55[4]; // [sp+38h] [bp-84h]@5
  int v56[4]; // [sp+48h] [bp-74h]@7
  int v57; // [sp+58h] [bp-64h]@2
  int v58; // [sp+5Ch] [bp-60h]@2
  int v59; // [sp+60h] [bp-5Ch]@16
  int v60; // [sp+64h] [bp-58h]@10
  int v61; // [sp+68h] [bp-54h]@1
  int v62; // [sp+6Ch] [bp-50h]@18
  int v63; // [sp+70h] [bp-4Ch]@16
  int v64; // [sp+74h] [bp-48h]@13
  int v65; // [sp+78h] [bp-44h]@13
  int v66; // [sp+7Ch] [bp-40h]@13
  int v67; // [sp+80h] [bp-3Ch]@13
  int v68; // [sp+84h] [bp-38h]@13
  int v69; // [sp+88h] [bp-34h]@16
  int v70; // [sp+8Ch] [bp-30h]@18
  int v71; // [sp+90h] [bp-2Ch]@18
  unsigned int v72; // [sp+94h] [bp-28h]@18
  int v73; // [sp+98h] [bp-24h]@20
  int v74; // [sp+9Ch] [bp-20h]@20
  int v75; // [sp+A0h] [bp-1Ch]@11
  unsigned int v76; // [sp+A4h] [bp-18h]@18
  int v77; // [sp+A8h] [bp-14h]@11

  v3 = a1;
  v4 = a3;
  v5 = 0;
  v6 = (int)a2->ctx;
  v7 = 0;
  v61 = 0;
  v8 = a3->ncomps;
  if ( a3->ncomps <= 0 )
  {
LABEL_10:
    v18 = v4->curyMCU;
    v60 = a1->numyMCUs;
    if ( v18 < v60 )
    {
      v19 = a1->numxMCUs;
      v57 = v5;
      v77 = v19;
      v75 = v8;
      v58 = v6;
      v20 = v60;
      while ( 1 )
      {
        v21 = v4->curxMCU;
        if ( v21 < v77 )
          break;
LABEL_55:
        ++v18;
        if ( v18 >= v20 )
        {
          v5 = v57;
          v6 = v58;
          goto LABEL_57;
        }
      }
      v68 = v18 << 7;
      v67 = (v61 << 6) - 1;
      v66 = v61 << 6;
      v65 = v21;
      v64 = v18;
      v22 = v75;
      while ( 1 )
      {
        v23 = (int)v3->MCUBuf;
        v24 = (int)&v3->raw_coefs->data_type;
        if ( v24 )
        {
          v25 = 0;
          if ( v22 > 0 )
          {
            v60 = (int)&v4->comps->comp;
            v59 = v23;
            v63 = v24;
            v69 = 16 * v65;
            v26 = (_SCAN_COMPONENT *)v60;
            do
            {
              v27 = 0;
              v28 = v26[v25].vsampling;
              if ( v28 > 0 )
              {
                v62 = v26[v25].hsampling;
                v72 = 16 * v25;
                v71 = 2 * v25;
                v29 = v63;
                v76 = 24 * v25;
                v70 = v25;
                v30 = v62;
                do
                {
                  v31 = 0;
                  if ( v30 > 0 )
                  {
                    v32 = v77;
                    v74 = v27 << 7;
                    v73 = v27;
                    while ( 1 )
                    {
                      v33 = (void *)(v74 * v32 * v30
                                   + v30 * v68 * v32 * v28
                                   + v69 * a1->jframe.comps[v72 / 0x10].hsampling
                                   + *(_DWORD *)(v29 + 2 * v71 + 4)
                                   + 16 * v31);
                      v34 = 0;
                      v75 = v31;
                      v35 = v59;
                      do
                      {
                        __g_memcpy((void *)v35, v33, 0x10u);
                        v32 = a1->numxMCUs;
                        v26 = a3->comps;
                        v30 = v26[v76 / 0x18].hsampling;
                        v33 = (char *)v33 + v30 * 16 * a1->numxMCUs;
                        v35 += 16;
                        ++v34;
                      }
                      while ( v34 < 8 );
                      v59 = v35;
                      v31 = v75 + 1;
                      if ( v75 + 1 >= v30 )
                        break;
                      v29 = (int)&a1->raw_coefs->data_type;
                      v28 = v26[v76 / 0x18].vsampling;
                    }
                    v77 = v32;
                    v27 = v73;
                    v29 = (int)&a1->raw_coefs->data_type;
                    v28 = v26[v76 / 0x18].vsampling;
                  }
                  ++v27;
                }
                while ( v27 < v28 );
                v63 = v29;
                v25 = v70;
                v22 = a3->ncomps;
              }
              ++v25;
            }
            while ( v25 < v22 );
            v24 = v63;
            v4 = a3;
            v3 = a1;
            v23 = (int)a1->MCUBuf;
          }
          if ( *(_DWORD *)v24 )
          {
            v36 = v67;
            if ( v66 )
            {
              do
              {
                *(_WORD *)v23 -= 128;
                v23 += 2;
                --v36;
              }
              while ( v36 != -1 );
              v23 = (int)v3->MCUBuf;
              v24 = (int)&v3->raw_coefs->data_type;
            }
          }
        }
        else
        {
          (*(void (__cdecl **)(struct _JPEG_PROPERTIES *, int, int))(v58 + 96))(v3, v65, v64);
          v24 = (int)&v3->raw_coefs->data_type;
        }
        if ( (!v24 || *(_DWORD *)v24) && v61 > 0 )
        {
          v37 = v23;
          v59 = v23;
          v38 = 0;
          v39 = v61;
          v40 = v58;
          do
          {
            (*(void (__cdecl **)(int))(v40 + 68))(v37);
            v37 += 128;
            ++v38;
          }
          while ( v38 < v39 );
          v58 = v40;
          v23 = v59;
          v4 = a3;
          v3 = a1;
        }
        v41 = 0;
        v22 = v4->ncomps;
        if ( v4->ncomps > 0 )
          break;
LABEL_52:
        if ( v3->interrupt )
        {
          v49 = v65;
          v50 = v64;
          v6 = v58;
          v3->roi.right = v65;
          v51 = v3->numxMCUs;
          v3->roi.bottom = v50;
          v52 = (v49 + 1) % v51;
          v4->curxMCU = v52;
          if ( v52 )
            v4->curyMCU = v50;
          else
            v4->curyMCU = v50 + 1;
          v5 = 1;
          goto LABEL_57;
        }
        v47 = v3->numxMCUs;
        ++v65;
        v77 = v47;
        if ( v65 >= v47 )
        {
          v75 = v22;
          v18 = v64;
          v20 = v3->numyMCUs;
          goto LABEL_55;
        }
      }
      v42 = (int)v4;
      while ( 1 )
      {
        v43 = 0;
        if ( v53[v41] > 0 )
          break;
LABEL_50:
        v42 += 4;
        ++v41;
        if ( v41 >= v22 )
        {
          v3 = a1;
          goto LABEL_52;
        }
      }
      v44 = v58;
      v60 = v42 + 36;
      v62 = v42;
      while ( 1 )
      {
        v45 = a1->raw_coefs;
        if ( !v45 || v45->data_type )
          (*(void (__cdecl **)(int, int))(v44 + 260))(v23, v56[v41]);
        v46 = (*(int (__cdecl **)(struct _STATE *, int, int, int, int))(v44 + 240))(a2, v54[v41], v55[v41], v60, v23);
        if ( v46 )
          break;
        v23 += 128;
        ++v43;
        if ( v43 >= v53[v41] )
        {
          v57 = 0;
          v42 = v62;
          v58 = v44;
          v4 = a3;
          v22 = a3->ncomps;
          goto LABEL_50;
        }
      }
      v5 = v46;
      v6 = v44;
    }
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v11 = v61;
    v57 = 0;
    v58 = v6;
    while ( 1 )
    {
      if ( !a1->jscan )
        a3->dc_diff[v7] = 0;
      v12 = a3->comps[v10].hsampling * a3->comps[v10].vsampling;
      v11 += v12;
      v13 = a1->HuffIdentifierAC[v7];
      v53[v7] = v12;
      v14 = (int)&a1->jEncFmtDcHuffman[a1->HuffIdentifierDC[v7]]->huff_class;
      v54[v7] = v14;
      v15 = (int)&a1->jEncFmtAcHuffman[v13]->huff_class;
      v55[v7] = v15;
      if ( !v14 )
        break;
      if ( !v15 )
      {
        v6 = v58;
        goto LABEL_66;
      }
      v16 = (int)a1->jEncFmtQuant[a1->jframe.comps[v9].quant_sel];
      v56[v7] = v16;
      if ( !v16 )
      {
        v6 = v58;
        v5 = -18;
        goto LABEL_57;
      }
      ++v9;
      ++v10;
      ++v7;
      v17 = a3->ncomps;
      if ( v7 >= a3->ncomps )
      {
        v61 = v11;
        v8 = v17;
        v5 = v57;
        v6 = v58;
        v4 = a3;
        goto LABEL_10;
      }
    }
    v6 = v58;
LABEL_66:
    v5 = -17;
  }
LABEL_57:
  (*(void (**)(void))(v6 + 24))();
  return v5;
}
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);
// 64AC00: using guessed type int var_A4[4];
// 64AC00: using guessed type int var_94[4];
// 64AC00: using guessed type int var_84[4];
// 64AC00: using guessed type int var_74[4];

//----- (0064B1A0) --------------------------------------------------------  // acclient.c:609968
enum _IJLERR __cdecl Fill_coeffs_buffer(struct _JPEG_PROPERTIES *a1)
{
  struct _JPEG_PROPERTIES *v1; // esi@1
  __int16 *v2; // ecx@1
  int v3; // ebx@1
  int v4; // eax@1
  int v5; // ecx@1
  _FRAME_COMPONENT *v6; // edx@2
  int v7; // edi@3
  int v8; // ebp@3
  int v9; // ebx@4
  int v10; // ebp@4
  int v11; // edx@5
  int v12; // ebx@8
  int v13; // ecx@8
  int v14; // ebp@9
  int v15; // eax@9
  _FRAME_COMPONENT *v16; // edx@10
  int v17; // ecx@11
  int v18; // ebx@11
  int v19; // eax@12
  int v20; // ebp@12
  int v21; // edi@13
  int v22; // ecx@14
  int v23; // esi@14
  void *v24; // ebx@16
  signed int v25; // ebp@16
  int v26; // esi@16
  int v27; // eax@25
  int v28; // edi@28
  int v29; // ebp@29
  int v30; // ebx@29
  void *v31; // esi@29
  int v32; // ebp@32
  int v33; // eax@32
  struct _JPEG_PROPERTIES *v34; // edx@33
  void *v35; // esi@33
  int v36; // edi@34
  int v37; // ecx@34
  void *v38; // ST04_4@35
  bool v39; // sf@39
  unsigned __int8 v40; // of@39
  int v42[4]; // [sp+10h] [bp-7Ch]@3
  int v43[4]; // [sp+20h] [bp-6Ch]@3
  unsigned int v44; // [sp+30h] [bp-5Ch]@11
  int v45; // [sp+34h] [bp-58h]@12
  int v46; // [sp+38h] [bp-54h]@10
  int v47; // [sp+3Ch] [bp-50h]@10
  int v48; // [sp+40h] [bp-4Ch]@10
  int v49; // [sp+44h] [bp-48h]@7
  int v50; // [sp+48h] [bp-44h]@10
  int v51; // [sp+4Ch] [bp-40h]@7
  unsigned int v52; // [sp+50h] [bp-3Ch]@5
  int v53; // [sp+54h] [bp-38h]@5
  int v54; // [sp+58h] [bp-34h]@12
  int v55; // [sp+5Ch] [bp-30h]@16
  int v56; // [sp+60h] [bp-2Ch]@14
  int *v57; // [sp+64h] [bp-28h]@10
  int v58; // [sp+68h] [bp-24h]@5
  int v59; // [sp+6Ch] [bp-20h]@5
  void *v60; // [sp+70h] [bp-1Ch]@1
  void *v61; // [sp+74h] [bp-18h]@1

  v1 = a1;
  v2 = a1->coef_buffer;
  v3 = 0;
  v60 = a1->state.ctx;
  v4 = 0;
  v61 = v2;
  v5 = a1->jframe.ncomps;
  if ( v5 > 0 )
  {
    v6 = a1->jframe.comps;
    do
    {
      v7 = v6->quant_sel;
      v8 = v6->hsampling * v6->vsampling;
      v4 += v8;
      ++v6;
      v42[v3] = v8;
      v43[v3++] = (int)a1->jEncFmtQuant[v7];
    }
    while ( v3 < v5 );
  }
  v9 = 0;
  v10 = a1->numyMCUs;
  if ( v10 > 0 )
  {
    v11 = a1->numxMCUs;
    v59 = v4 << 6;
    v58 = (v4 << 6) - 1;
    v52 = v4 << 7;
    v53 = v4;
    do
    {
      if ( v11 > 0 )
      {
        v49 = v9;
        v51 = 0;
        do
        {
          v12 = (int)v1->MCUBuf;
          v13 = (int)&v1->raw_coefs->data_type;
          if ( v13 )
          {
            v14 = 0;
            v15 = v1->jframe.ncomps;
            if ( v15 > 0 )
            {
              v57 = &v1->jframe.comps->ident;
              v46 = v12;
              v47 = v11;
              v48 = v13;
              v16 = (_FRAME_COMPONENT *)v57;
              v50 = 16 * v51;
              do
              {
                v17 = 0;
                v44 = 16 * v14;
                v18 = v16[v14].vsampling;
                if ( v18 > 0 )
                {
                  v19 = v16[v44 / 0x10].hsampling;
                  v45 = 2 * v14;
                  v54 = v14;
                  v20 = v48;
                  do
                  {
                    v21 = 0;
                    if ( v19 > 0 )
                    {
                      v56 = v17;
                      v22 = v47;
                      v23 = v45;
                      while ( 1 )
                      {
                        v24 = (void *)(16 * v21
                                     + v56 * (v22 << 7) * v19
                                     + v19 * v50
                                     + *(_DWORD *)(v20 + 2 * v23 + 4)
                                     + v19 * v49 * (v22 << 7) * v18);
                        v25 = 0;
                        v55 = v21;
                        v26 = v46;
                        do
                        {
                          __g_memcpy((void *)v26, v24, 0x10u);
                          v22 = a1->numxMCUs;
                          v16 = a1->jframe.comps;
                          v19 = v16[v44 / 0x10].hsampling;
                          v24 = (char *)v24 + v19 * 16 * a1->numxMCUs;
                          v26 += 16;
                          ++v25;
                        }
                        while ( v25 < 8 );
                        v46 = v26;
                        v23 = v45;
                        v21 = v55 + 1;
                        if ( v55 + 1 >= v19 )
                          break;
                        v20 = (int)&a1->raw_coefs->data_type;
                        v18 = v16[v44 / 0x10].vsampling;
                      }
                      v47 = v22;
                      v17 = v56;
                      v1 = a1;
                      v20 = (int)&a1->raw_coefs->data_type;
                      v18 = v16[v44 / 0x10].vsampling;
                    }
                    ++v17;
                  }
                  while ( v17 < v18 );
                  v48 = v20;
                  v14 = v54;
                  v15 = v1->jframe.ncomps;
                }
                ++v14;
              }
              while ( v14 < v15 );
              v13 = v48;
              v12 = (int)v1->MCUBuf;
            }
            if ( *(_DWORD *)v13 )
            {
              v27 = v58;
              if ( v59 )
              {
                do
                {
                  *(_WORD *)v12 -= 128;
                  v12 += 2;
                  --v27;
                }
                while ( v27 != -1 );
                v12 = (int)v1->MCUBuf;
              }
            }
          }
          else
          {
            (*((void (__cdecl **)(struct _JPEG_PROPERTIES *, int, int))v60 + 24))(v1, v51, v49);
          }
          v28 = 0;
          if ( v53 > 0 )
          {
            v29 = v12;
            v46 = v12;
            v30 = v53;
            v31 = v60;
            do
            {
              (*((void (__cdecl **)(_DWORD))v31 + 17))(v29);
              v29 += 128;
              ++v28;
            }
            while ( v28 < v30 );
            v12 = v46;
            v1 = a1;
          }
          v32 = 0;
          v33 = v1->jframe.ncomps;
          if ( v33 > 0 )
          {
            v34 = v1;
            v35 = v60;
            do
            {
              v36 = 0;
              v37 = v42[v32];
              if ( v37 > 0 )
              {
                do
                {
                  v38 = (void *)v43[v32];
                  (*((void (__fastcall **)(int, struct _JPEG_PROPERTIES *))v35 + 65))(v37, v34);
                  v12 += 128;
                  ++v36;
                }
                while ( v36 < v42[v32] );
                v34 = a1;
                v33 = a1->jframe.ncomps;
              }
              ++v32;
            }
            while ( v32 < v33 );
            v1 = v34;
          }
          __g_memcpy(v61, v1->MCUBuf, v52);
          v11 = v1->numxMCUs;
          v40 = __OFSUB__(v51 + 1, v11);
          v39 = v51 + 1 - v11 < 0;
          v61 = (char *)v61 + v52;
          ++v51;
        }
        while ( v39 ^ v40 );
        v9 = v49;
        v10 = v1->numyMCUs;
      }
      ++v9;
    }
    while ( v9 < v10 );
  }
  return 0;
}
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);
// 64B1A0: using guessed type int var_7C[4];
// 64B1A0: using guessed type int var_6C[4];

//----- (0064B500) --------------------------------------------------------  // acclient.c:610237
enum _IJLERR __cdecl Gather_statistics(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, struct _SCAN *a3, int (*const a4)[257])
{
  struct _JPEG_PROPERTIES *v4; // eax@1
  int v5; // esi@1
  int v6; // ebp@1
  int v7; // ebx@1
  _FRAME_COMPONENT *v8; // ecx@2
  int v9; // edx@2
  int v10; // edi@3
  int v11; // ebp@4
  int v12; // ecx@4
  int v13; // edx@4
  int *v14; // ebx@6
  int v15; // edi@6
  int v16; // esi@8
  int v17; // ebp@9
  int v18; // ebx@10
  int v19; // ecx@11
  int v20; // ebp@12
  __int16 *v21; // edi@13
  _SCAN_COMPONENT *v22; // esi@22
  signed int v23; // esi@22
  int v24; // ebx@22
  int v25; // eax@24
  int v26; // edi@27
  int v27; // ebx@30
  int v28; // edx@31
  __int16 *v29; // esi@31
  int v30; // edi@31
  int v31; // ecx@32
  int *v32; // ebp@33
  int v33; // ebx@33
  int v34; // edx@36
  int v35; // ecx@36
  __int16 *v36; // esi@37
  int v37; // ebp@37
  int v38; // ebx@38
  int *v39; // esi@50
  unsigned __int8 v41; // [sp+20h] [bp-44Ch]@42
  int v42; // [sp+408h] [bp-64h]@1
  int v43; // [sp+40Ch] [bp-60h]@3
  int v44; // [sp+410h] [bp-5Ch]@25
  int v45; // [sp+414h] [bp-58h]@25
  int v46; // [sp+418h] [bp-54h]@25
  void *v47; // [sp+41Ch] [bp-50h]@1
  int *v48; // [sp+420h] [bp-4Ch]@13
  int v49; // [sp+424h] [bp-48h]@13
  int v50; // [sp+428h] [bp-44h]@7
  int v51; // [sp+42Ch] [bp-40h]@7
  int v52; // [sp+430h] [bp-3Ch]@13
  int v53; // [sp+434h] [bp-38h]@11
  int v54; // [sp+438h] [bp-34h]@9
  int *v55; // [sp+43Ch] [bp-30h]@9
  int v56; // [sp+440h] [bp-2Ch]@11
  __int16 *v57; // [sp+444h] [bp-28h]@11
  int *v58; // [sp+448h] [bp-24h]@31
  int v59; // [sp+44Ch] [bp-20h]@33
  int v60; // [sp+450h] [bp-1Ch]@36
  int v61; // [sp+454h] [bp-18h]@36

  v4 = a1;
  v5 = 0;
  v47 = a2->ctx;
  v6 = 0;
  v7 = a1->jframe.ncomps;
  v42 = 0;
  if ( v7 > 0 )
  {
    v8 = a1->jframe.comps;
    v9 = 0;
    do
    {
      v10 = v8[v9].hsampling * v8[v9].vsampling;
      *(&v43 + v5) = v10;
      v6 += v10;
      ++v9;
      ++v5;
    }
    while ( v5 < v7 );
  }
  v11 = v6 << 6;
  v12 = a1->numxMCUs;
  v13 = v12 * v11;
  if ( a3->start_spec || a3->end_spec )
  {
    v22 = a3->comps;
    v55 = (int *)v22;
    v23 = v22->comp;
    v56 = a1->HuffIdentifierAC[v23];
    v24 = 0;
    v54 = 0;
    if ( v23 > 0 )
    {
      if ( v23 >= 6 )
      {
        v25 = v54;
        v57 = (__int16 *)(v23 - 6);
        do
        {
          v25 += (int)((char *)*(&v47 + v24) + *(&v46 + v24) + *(&v45 + v24) + *(&v44 + v24) + *(&v43 + v24));
          v24 += 5;
        }
        while ( v24 <= v23 - 6 );
        v54 = v25;
        v4 = a1;
      }
      v26 = v54;
      do
        v26 += *(&v43 + v24++);
      while ( v24 < v23 );
      v54 = v26;
    }
    v57 = 0;
    v27 = v4->numyMCUs;
    if ( v27 <= 0 )
    {
      v39 = &(*a4)[257 * v56];
    }
    else
    {
      v28 = 2 * v13;
      v53 = v55[2];
      v54 <<= 7;
      v58 = &(*a4)[257 * v56];
      v29 = v57;
      v30 = v53;
      v52 = v12;
      v50 = 2 * v11;
      do
      {
        v31 = 0;
        if ( v30 > 0 )
        {
          v32 = 0;
          v59 = (_DWORD)v29 * v28;
          v33 = v52;
          v57 = v29;
          v51 = v28;
          while ( (signed int)((char *)v32 + (_DWORD)v57 * 8 * v30) < v4->JPGHeight )
          {
            if ( v33 > 0 )
            {
              v56 = v55[1];
              v34 = 0;
              v61 = 0;
              v48 = v32;
              v60 = v31;
              v35 = v56;
              do
              {
                v36 = (__int16 *)((char *)v4->coef_buffer + v59 + v34 + v54 + v60 * (v30 << 7));
                v37 = 0;
                if ( v35 > 0 )
                {
                  v38 = 0;
                  v49 = v34;
                  while ( v38 + v61 * 8 * v35 < a1->JPGWidth )
                  {
                    if ( a3->approx_high )
                      Gather_Prog_AC_refine(a2, v36, a3->start_spec, a3->end_spec, a3->approx_low, &v41, &v42, v58);
                    else
                      Gather_Prog_AC_first(a2, v36, a3->start_spec, a3->end_spec, a3->approx_low, v58);
                    v36 += 64;
                    v38 += 8;
                    ++v37;
                    v35 = a3->comps->hsampling;
                    v55 = &a3->comps->comp;
                    if ( v37 >= v35 )
                    {
                      v34 = v49;
                      v4 = a1;
                      v33 = a1->numxMCUs;
                      v30 = v55[2];
                      goto LABEL_45;
                    }
                  }
                  v34 = v49;
                  v4 = a1;
                  v33 = a1->numxMCUs;
                  v30 = v55[2];
                }
LABEL_45:
                v34 += v50;
                ++v61;
              }
              while ( v61 < v33 );
              v32 = v48;
              v31 = v60;
            }
            v32 += 2;
            ++v31;
            if ( v31 >= v30 )
            {
              v52 = v33;
              v29 = v57;
              v28 = v51;
              v27 = v4->numyMCUs;
              goto LABEL_49;
            }
          }
          v52 = v33;
          v29 = v57;
          v28 = v51;
          v27 = v4->numyMCUs;
        }
LABEL_49:
        v29 = (__int16 *)((char *)v29 + 1);
      }
      while ( (signed int)v29 < v27 );
      v39 = v58;
    }
    Gather_EOBRUN(a2, v39);
    v42 = 0;
  }
  else
  {
    v14 = 0;
    v15 = a1->numyMCUs;
    if ( v15 > 0 )
    {
      v13 *= 2;
      v50 = 2 * v11;
      v51 = v13;
      do
      {
        v16 = 0;
        if ( v12 > 0 )
        {
          v13 = a3->ncomps;
          v17 = 0;
          v54 = (_DWORD)v14 * v51;
          v55 = v14;
          do
          {
            v18 = 0;
            if ( v13 > 0 )
            {
              v19 = (int)a3;
              v57 = (__int16 *)((char *)v4->coef_buffer + v54 + v17);
              v53 = v17;
              v56 = v16;
              do
              {
                v20 = 0;
                if ( *(&v43 + v18) > 0 )
                {
                  v49 = (int)((char *)v4 + v18);
                  v21 = v57;
                  v48 = (int *)(v19 + 36);
                  v52 = v19;
                  do
                  {
                    Gather_Prog_DC_SA(&(*a4)[257 * *(_BYTE *)(v49 + 14240)], v48, v21, a3->approx_high, a3->approx_low);
                    v21 += 64;
                    ++v20;
                  }
                  while ( v20 < *(&v43 + v18) );
                  v57 = v21;
                  v19 = v52;
                  v4 = a1;
                  v13 = a3->ncomps;
                }
                v19 += 4;
                ++v18;
              }
              while ( v18 < v13 );
              v17 = v53;
              v16 = v56;
              v12 = v4->numxMCUs;
            }
            v17 += v50;
            ++v16;
          }
          while ( v16 < v12 );
          v14 = v55;
          v15 = v4->numyMCUs;
        }
        v14 = (int *)((char *)v14 + 1);
      }
      while ( (signed int)v14 < v15 );
    }
  }
  (*((void (__fastcall **)(int, int))v47 + 6))(v12, v13);
  return 0;
}

//----- (0064BAE0) --------------------------------------------------------  // acclient.c:610524
int __cdecl Encode_Scan_P(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, struct _SCAN *a3)
{
  struct _JPEG_PROPERTIES *v3; // ecx@1
  struct _STATE *v4; // ebx@1
  int v5; // ebp@1
  int v6; // esi@1
  int v7; // edx@1
  int v8; // eax@2
  int *v9; // ebx@2
  int v10; // ecx@3
  int v11; // esi@5
  int v12; // edx@5
  int v13; // ebp@5
  int v14; // eax@6
  int v15; // ebx@7
  int v16; // eax@9
  int v17; // edx@12
  int v18; // eax@12
  int *v19; // ebp@12
  int v20; // edi@13
  int v21; // eax@14
  int v22; // esi@14
  int v23; // ebx@15
  __int16 *v24; // ebp@15
  int v25; // edx@16
  int v26; // esi@17
  _SCAN_COMPONENT *v27; // eax@27
  signed int v28; // eax@27
  int v29; // edx@27
  int *v30; // ecx@29
  int v31; // ecx@32
  int *v32; // edx@32
  int v33; // eax@35
  int v34; // ebp@36
  int *v35; // ebx@36
  int v36; // edx@36
  int v37; // esi@37
  int *v38; // eax@38
  int v39; // edi@38
  int v40; // ebx@40
  int v41; // eax@41
  __int16 *v42; // esi@42
  int v43; // ebp@43
  bool v44; // sf@50
  unsigned __int8 v45; // of@50
  char *v46; // edx@58
  int v47; // eax@65
  char *v48; // eax@66
  signed int v49; // eax@67
  unsigned __int8 v51; // [sp+20h] [bp-44Ch]@47
  int v52; // [sp+408h] [bp-64h]@1
  int v53; // [sp+40Ch] [bp-60h]@3
  int v54; // [sp+410h] [bp-5Ch]@30
  int v55; // [sp+414h] [bp-58h]@30
  int v56; // [sp+418h] [bp-54h]@30
  unsigned int NumberOfBytesWritten; // [sp+41Ch] [bp-50h]@30
  int v58; // [sp+420h] [bp-4Ch]@6
  int v59; // [sp+424h] [bp-48h]@6
  int *v60; // [sp+428h] [bp-44h]@2
  int v61; // [sp+42Ch] [bp-40h]@11
  int v62; // [sp+430h] [bp-3Ch]@29
  _SCAN_COMPONENT *v63; // [sp+434h] [bp-38h]@27
  int v64; // [sp+438h] [bp-34h]@40
  int v65; // [sp+43Ch] [bp-30h]@18
  int v66; // [sp+440h] [bp-2Ch]@18
  int *v67; // [sp+444h] [bp-28h]@18
  int v68; // [sp+448h] [bp-24h]@16
  int v69; // [sp+44Ch] [bp-20h]@14
  int v70; // [sp+450h] [bp-1Ch]@16
  void *v71; // [sp+454h] [bp-18h]@1
  int v72; // [sp+458h] [bp-14h]@1

  v3 = a1;
  v4 = a2;
  v72 = 0;
  v5 = 0;
  v71 = a2->ctx;
  v6 = 0;
  v7 = a1->jframe.ncomps;
  v52 = 0;
  if ( v7 > 0 )
  {
    v60 = &a1->jframe.comps->ident;
    v8 = 0;
    v9 = v60;
    do
    {
      v10 = v9[v8 + 1] * v9[v8 + 2];
      *(&v53 + v5) = v10;
      v6 += v10;
      v8 += 4;
      ++v5;
    }
    while ( v5 < v7 );
    v4 = a2;
    v3 = a1;
  }
  v11 = v6 << 6;
  v12 = 0;
  v13 = v3->numxMCUs * v11;
  if ( a3->ncomps > 0 )
  {
    v14 = 0;
    v58 = v11;
    v59 = v13;
    do
    {
      v15 = a3->comps[v14].comp;
      a3->dc_diff[v12++] = 0;
      a3->comps[v14].dc_table = v3->jEncFmtDcHuffman[v3->HuffIdentifierDC[v15]];
      a3->comps[v14].ac_table = v3->jEncFmtAcHuffman[v3->HuffIdentifierAC[v15]];
      ++v14;
    }
    while ( v12 < a3->ncomps );
    v11 = v58;
    v13 = v59;
    v4 = a2;
  }
  v16 = 8;
  v4->bitbuf_bits_valid = 8;
  if ( a3->start_spec || a3->end_spec )
  {
    v27 = a3->comps;
    v63 = v27;
    v28 = v27->comp;
    v60 = 0;
    v29 = 0;
    v61 = 0;
    if ( v28 > 0 )
    {
      if ( v28 >= 6 )
      {
        v30 = v60;
        v62 = v28 - 6;
        v29 = v61;
        do
        {
          v29 += *(&NumberOfBytesWritten + (_DWORD)v30)
               + *(&v56 + (_DWORD)v30)
               + *(&v55 + (_DWORD)v30)
               + *(&v54 + (_DWORD)v30)
               + *(&v53 + (_DWORD)v30);
          v30 = (int *)((char *)v30 + 5);
        }
        while ( (signed int)v30 <= v28 - 6 );
        v61 = v29;
        v4 = a2;
        v60 = v30;
      }
      v31 = v29;
      v32 = v60;
      do
      {
        v31 += *(&v53 + (_DWORD)v32);
        v32 = (int *)((char *)v32 + 1);
      }
      while ( (signed int)v32 < v28 );
      v61 = v31;
      v3 = a1;
    }
    v60 = 0;
    v33 = v3->numyMCUs;
    if ( v33 > 0 )
    {
      v34 = 2 * v13;
      v62 = v63->vsampling;
      v35 = v60;
      v61 <<= 7;
      v36 = v62;
      v58 = 2 * v11;
      do
      {
        v37 = 0;
        if ( v36 > 0 )
        {
          v38 = 0;
          v68 = (_DWORD)v35 * v34;
          v39 = (int)v63;
          v60 = v35;
          v59 = v34;
          while ( (signed int)((char *)v38 + (_DWORD)v60 * 8 * v36) < v3->JPGHeight )
          {
            v64 = 0;
            v40 = v3->numxMCUs;
            if ( v40 > 0 )
            {
              v66 = *(_DWORD *)(v39 + 4);
              v65 = v64 * v58;
              v67 = v38;
              v41 = v66;
              v69 = v37;
              do
              {
                v42 = (__int16 *)((char *)v3->coef_buffer + v68 + v65 + v61 + v69 * (v36 << 7));
                v70 = 0;
                if ( v41 > 0 )
                {
                  v43 = 0;
                  while ( v43 + v64 * 8 * v41 < a1->JPGWidth )
                  {
                    if ( a3->approx_high )
                      Encode_Prog_AC_refine(
                        a2,
                        *(struct _HUFFMAN_TABLE **)(v39 + 16),
                        v42,
                        a3->start_spec,
                        a3->end_spec,
                        a3->approx_low,
                        &v51,
                        &v52);
                    else
                      Encode_Prog_AC_first(
                        a2,
                        *(struct _HUFFMAN_TABLE **)(v39 + 16),
                        v42,
                        a3->start_spec,
                        a3->end_spec,
                        a3->approx_low);
                    v42 += 64;
                    v43 += 8;
                    v39 = (int)&a3->comps->comp;
                    v41 = *(_DWORD *)(v39 + 4);
                    ++v70;
                    if ( v70 >= v41 )
                    {
                      v3 = a1;
                      v40 = a1->numxMCUs;
                      v36 = *(_DWORD *)(v39 + 8);
                      goto LABEL_50;
                    }
                  }
                  v3 = a1;
                  v40 = a1->numxMCUs;
                  v36 = *(_DWORD *)(v39 + 8);
                }
LABEL_50:
                v45 = __OFSUB__(v64 + 1, v40);
                v44 = v64 + 1 - v40 < 0;
                v65 += v58;
                ++v64;
              }
              while ( v44 ^ v45 );
              v38 = v67;
              v37 = v69;
            }
            v38 += 2;
            ++v37;
            if ( v37 >= v36 )
            {
              v63 = (_SCAN_COMPONENT *)v39;
              v35 = v60;
              v34 = v59;
              v33 = v3->numyMCUs;
              goto LABEL_54;
            }
          }
          v63 = (_SCAN_COMPONENT *)v39;
          v35 = v60;
          v34 = v59;
          v33 = v3->numyMCUs;
        }
LABEL_54:
        v35 = (int *)((char *)v35 + 1);
      }
      while ( (signed int)v35 < v33 );
      v4 = a2;
    }
    Encode_EOBRUN(v4, v63->ac_table);
    Append_BE_bits(v4, &v51, &v52);
    v52 = 0;
    v16 = v4->bitbuf_bits_valid;
  }
  else
  {
    v60 = 0;
    v61 = v3->numyMCUs;
    if ( v61 > 0 )
    {
      v17 = v3->numxMCUs;
      v58 = 2 * v11;
      v18 = v61;
      v59 = 2 * v13;
      v19 = v60;
      do
      {
        v20 = 0;
        if ( v17 > 0 )
        {
          v21 = a3->ncomps;
          v22 = 0;
          v69 = (_DWORD)v19 * v59;
          v60 = v19;
          do
          {
            v23 = 0;
            v24 = (__int16 *)((char *)v3->coef_buffer + v69 + v22);
            if ( v21 > 0 )
            {
              v25 = (int)a3;
              v68 = v22;
              v70 = v20;
              do
              {
                v26 = 0;
                if ( *(&v53 + v23) > 0 )
                {
                  v66 = 24 * v23;
                  v67 = (int *)(v25 + 36);
                  v65 = v25;
                  do
                  {
                    Encode_Prog_DC_SA(
                      a2,
                      *(_HUFFMAN_TABLE **)((char *)&a3->comps->dc_table + v66),
                      v67,
                      v24,
                      a3->approx_high,
                      a3->approx_low);
                    v24 += 64;
                    ++v26;
                  }
                  while ( v26 < *(&v53 + v23) );
                  v25 = v65;
                  v21 = a3->ncomps;
                }
                v25 += 4;
                ++v23;
              }
              while ( v23 < v21 );
              v22 = v68;
              v20 = v70;
              v3 = a1;
              v17 = a1->numxMCUs;
            }
            v22 += v58;
            ++v20;
          }
          while ( v20 < v17 );
          v19 = v60;
          v18 = v3->numyMCUs;
        }
        v19 = (int *)((char *)v19 + 1);
      }
      while ( (signed int)v19 < v18 );
      v4 = a2;
      v16 = a2->bitbuf_bits_valid;
    }
  }
  if ( v16 < 8 )
  {
    v46 = v4->cur_entropy_ptr;
    if ( v46 >= v4->end_entropy_ptr )
    {
      if ( !v4->file )
      {
        v72 = -28;
        goto LABEL_70;
      }
      if ( !ownWriteFile(v4->file, v4->JPGBuffer, 0x1000u, &NumberOfBytesWritten) || NumberOfBytesWritten != 4096 )
      {
        v72 = -23;
        goto LABEL_70;
      }
      v46 = v4->start_entropy_ptr;
    }
    v47 = LOBYTE(v4->bit_buffer_64);
    v4->cur_entropy_ptr = v46 + 1;
    *v46 = v47;
    ++v4->entropy_bytes_processed;
    if ( v47 == 255 )
    {
      v48 = v4->cur_entropy_ptr;
      v4->cur_entropy_ptr = v48 + 1;
      *v48 = 0;
      ++v4->entropy_bytes_processed;
    }
    v49 = v4->processor_type;
    LODWORD(v4->bit_buffer_64) = 0;
    HIDWORD(v4->bit_buffer_64) = 0;
    if ( v49 <= 2 )
      v4->bitbuf_bits_valid = 8;
    else
      v4->bitbuf_bits_valid = 0;
  }
LABEL_70:
  (*((void (**)(void))v71 + 6))();
  return v72;
}

//----- (0064C230) --------------------------------------------------------  // acclient.c:610914
signed int __cdecl Encode_Scan_WRst(struct _JPEG_PROPERTIES *a1, struct _STATE *a2, struct _SCAN *a3)
{
  struct _JPEG_PROPERTIES *v3; // ebx@1
  struct _SCAN *v4; // ebp@1
  signed int v5; // esi@1
  int v6; // ecx@1
  int v7; // eax@1
  int v8; // edi@2
  int v9; // edx@2
  int v10; // ecx@2
  int v11; // ebp@4
  int v12; // ebp@4
  int v13; // edi@6
  int v14; // edx@6
  int v15; // eax@7
  int v16; // eax@7
  int i; // ecx@9
  int v18; // esi@10
  int v19; // eax@10
  int v20; // edx@11
  _SCAN_COMPONENT *v21; // edi@12
  int v22; // eax@13
  int v23; // ebx@13
  int v24; // esi@14
  int v25; // edx@14
  int v26; // ecx@15
  int v27; // eax@16
  void *v28; // ebp@18
  signed int v29; // ebx@18
  int v30; // esi@18
  int v31; // edx@27
  int v32; // edi@33
  int v33; // ebx@33
  int v34; // esi@33
  int v35; // ebp@33
  int v36; // edi@36
  int v37; // eax@37
  int v38; // ebx@38
  int v39; // ebp@39
  _RAW_DATA_TYPES_STATE *v40; // eax@40
  int v41; // eax@43
  unsigned int v42; // edi@48
  unsigned int v43; // esi@48
  int v44; // eax@51
  int v45; // eax@52
  int v46; // edx@55
  int v48; // eax@63
  int v49; // edi@63
  int v50; // et2@63
  int v51[4]; // [sp+18h] [bp-A4h]@4
  int v52[4]; // [sp+28h] [bp-94h]@4
  int v53[4]; // [sp+38h] [bp-84h]@4
  int v54[4]; // [sp+48h] [bp-74h]@4
  int v55; // [sp+58h] [bp-64h]@8
  int v56; // [sp+5Ch] [bp-60h]@7
  int v57; // [sp+60h] [bp-5Ch]@2
  int v58; // [sp+64h] [bp-58h]@2
  unsigned int v59; // [sp+68h] [bp-54h]@14
  int v60; // [sp+6Ch] [bp-50h]@12
  unsigned int v61; // [sp+70h] [bp-4Ch]@14
  int v62; // [sp+74h] [bp-48h]@14
  int v63; // [sp+78h] [bp-44h]@14
  int v64; // [sp+7Ch] [bp-40h]@12
  int v65; // [sp+80h] [bp-3Ch]@1
  int v66; // [sp+84h] [bp-38h]@16
  int v67; // [sp+88h] [bp-34h]@16
  int v68; // [sp+8Ch] [bp-30h]@1
  int v69; // [sp+90h] [bp-2Ch]@12
  int v70; // [sp+94h] [bp-28h]@14
  int *v71; // [sp+98h] [bp-24h]@12
  int v72; // [sp+9Ch] [bp-20h]@9
  int v73; // [sp+A0h] [bp-1Ch]@9
  int v74; // [sp+A4h] [bp-18h]@9
  int v75; // [sp+A8h] [bp-14h]@9

  v3 = a1;
  v4 = a3;
  v65 = 0;
  v5 = 0;
  v6 = (int)a2->ctx;
  v7 = 0;
  v68 = a3->ncomps;
  if ( v68 > 0 )
  {
    v8 = 0;
    v9 = 0;
    v57 = 0;
    v58 = v6;
    v10 = v65;
    do
    {
      if ( !a1->jscan )
      {
        a3->dc_diff[v7] = 0;
        v68 = a3->ncomps;
      }
      v11 = a3->comps[v8].hsampling * a3->comps[v8].vsampling;
      v10 += v11;
      ++v8;
      v51[v7] = v11;
      v52[v7] = (int)&a1->jEncFmtDcHuffman[a1->HuffIdentifierDC[v7]]->huff_class;
      v53[v7] = (int)&a1->jEncFmtAcHuffman[a1->HuffIdentifierAC[v7]]->huff_class;
      v12 = (int)a1->jEncFmtQuant[a1->jframe.comps[v9].quant_sel];
      ++v9;
      v54[v7++] = v12;
    }
    while ( v7 < v68 );
    v65 = v10;
    v5 = v57;
    v6 = v58;
    v4 = a3;
  }
  v13 = v4->curyMCU;
  v14 = a1->numyMCUs;
  if ( v13 < v14 )
  {
    v15 = a1->numxMCUs;
    v57 = v5;
    v56 = v15;
    v16 = v65;
    v58 = v6;
    while ( 1 )
    {
      v55 = v4->curxMCU;
      if ( v55 < v56 )
        break;
LABEL_57:
      ++v13;
      if ( v13 >= v14 )
      {
        v5 = v57;
        v6 = v58;
        goto LABEL_59;
      }
    }
    v75 = v13 << 7;
    v74 = (v16 << 6) - 1;
    v73 = v16 << 6;
    i = v68;
    v72 = v13;
    while ( 1 )
    {
      v18 = (int)v3->MCUBuf;
      v19 = (int)&v3->raw_coefs->data_type;
      if ( v19 )
      {
        v20 = 0;
        if ( i > 0 )
        {
          v71 = &v4->comps->comp;
          v60 = v18;
          v69 = v19;
          v64 = 16 * v55;
          v21 = (_SCAN_COMPONENT *)v71;
          do
          {
            v22 = 0;
            v23 = v21[v20].vsampling;
            if ( v23 > 0 )
            {
              v70 = v21[v20].hsampling;
              v61 = 16 * v20;
              v24 = v69;
              v62 = 2 * v20;
              v59 = 24 * v20;
              v63 = v20;
              v25 = v70;
              do
              {
                v26 = 0;
                if ( v25 > 0 )
                {
                  v67 = v22 << 7;
                  v66 = v22;
                  v27 = v56;
                  while ( 1 )
                  {
                    v28 = (void *)(v67 * v27 * v25
                                 + v25 * v75 * v27 * v23
                                 + v64 * a1->jframe.comps[v61 / 0x10].hsampling
                                 + *(_DWORD *)(v24 + 2 * v62 + 4)
                                 + 16 * v26);
                    v29 = 0;
                    v30 = v60;
                    v68 = v26;
                    do
                    {
                      __g_memcpy((void *)v30, v28, 0x10u);
                      v27 = a1->numxMCUs;
                      v21 = a3->comps;
                      v25 = v21[v59 / 0x18].hsampling;
                      v28 = (char *)v28 + v25 * 16 * a1->numxMCUs;
                      v30 += 16;
                      ++v29;
                    }
                    while ( v29 < 8 );
                    v60 = v30;
                    v26 = v68 + 1;
                    if ( v68 + 1 >= v25 )
                      break;
                    v24 = (int)&a1->raw_coefs->data_type;
                    v23 = v21[v59 / 0x18].vsampling;
                  }
                  v56 = v27;
                  v22 = v66;
                  v24 = (int)&a1->raw_coefs->data_type;
                  v23 = v21[v59 / 0x18].vsampling;
                }
                ++v22;
              }
              while ( v22 < v23 );
              v69 = v24;
              v20 = v63;
              i = a3->ncomps;
            }
            ++v20;
          }
          while ( v20 < i );
          v19 = v69;
          v4 = a3;
          v3 = a1;
          v18 = (int)a1->MCUBuf;
        }
        if ( *(_DWORD *)v19 )
        {
          v31 = v74;
          if ( v73 )
          {
            do
            {
              *(_WORD *)v18 -= 128;
              v18 += 2;
              --v31;
            }
            while ( v31 != -1 );
            v18 = (int)v3->MCUBuf;
            v19 = (int)&v3->raw_coefs->data_type;
          }
        }
      }
      else
      {
        (*(void (__cdecl **)(struct _JPEG_PROPERTIES *, int, int))(v58 + 96))(v3, v55, v72);
        v19 = (int)&v3->raw_coefs->data_type;
      }
      if ( (!v19 || *(_DWORD *)v19) && v65 > 0 )
      {
        v32 = v18;
        v60 = v18;
        v33 = 0;
        v34 = v65;
        v35 = v58;
        do
        {
          (*(void (__cdecl **)(int))(v35 + 68))(v32);
          v32 += 128;
          ++v33;
        }
        while ( v33 < v34 );
        v58 = v35;
        v18 = v60;
        v4 = a3;
        v3 = a1;
      }
      v36 = 0;
      i = v4->ncomps;
      if ( v4->ncomps > 0 )
        break;
LABEL_48:
      v42 = v4->restart_interv + 1;
      v4->restart_interv = v42;
      v43 = v3->jframe.restart_interv;
      if ( !(v42 % v43) )
      {
        if ( (((unsigned __int8)(v42 / v43) - 1) & 7) == 7 )
          v4->restart_interv = 0;
        v44 = EP_Write_RST(((unsigned __int8)(v42 / v43) - 1) & 7, a2);
        v57 = v44;
        if ( v44 )
        {
          v5 = v44;
          v6 = v58;
          goto LABEL_59;
        }
        v45 = 0;
        for ( i = v4->ncomps; v45 < v4->ncomps; ++v45 )
        {
          v4->dc_diff[v45] = 0;
          i = v4->ncomps;
        }
      }
      if ( v3->interrupt )
      {
        v48 = v55;
        v49 = v72;
        v6 = v58;
        v3->roi.right = v55;
        v3->roi.bottom = v49;
        v50 = (v48 + 1) % v3->numxMCUs;
        v4->curxMCU = v50;
        if ( v50 )
          v4->curyMCU = v49;
        else
          v4->curyMCU = v49 + 1;
        v5 = 1;
        goto LABEL_59;
      }
      v46 = v3->numxMCUs;
      ++v55;
      v56 = v46;
      if ( v55 >= v46 )
      {
        v68 = i;
        v13 = v72;
        v16 = v65;
        v14 = v3->numyMCUs;
        goto LABEL_57;
      }
    }
    v37 = (int)v4;
    while ( 1 )
    {
      v38 = 0;
      if ( v51[v36] > 0 )
        break;
LABEL_46:
      v37 += 4;
      ++v36;
      if ( v36 >= i )
      {
        v3 = a1;
        goto LABEL_48;
      }
    }
    v39 = v58;
    v69 = v37 + 36;
    v70 = v37;
    while ( 1 )
    {
      v40 = a1->raw_coefs;
      if ( !v40 || v40->data_type )
        (*(void (__cdecl **)(int, int))(v39 + 260))(v18, v54[v36]);
      v41 = (*(int (__cdecl **)(struct _STATE *, int, int, int, int))(v39 + 240))(a2, v52[v36], v53[v36], v69, v18);
      if ( v41 )
        break;
      v18 += 128;
      ++v38;
      if ( v38 >= v51[v36] )
      {
        v57 = 0;
        v37 = v70;
        v58 = v39;
        v4 = a3;
        i = a3->ncomps;
        goto LABEL_46;
      }
    }
    v5 = v41;
    v6 = v39;
  }
LABEL_59:
  (*(void (**)(void))(v6 + 24))();
  return v5;
}
// 8F75A8: using guessed type void (__cdecl *__g_memcpy)(void *, void *, unsigned int);
// 64C230: using guessed type int var_A4[4];
// 64C230: using guessed type int var_94[4];
// 64C230: using guessed type int var_84[4];
// 64C230: using guessed type int var_74[4];

