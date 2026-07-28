/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Waveform
   Object     : ENGINE\engine_shared_geometry\Waveform.obj
   Functions  : 28
   Addresses  : 005B0F30 - 00777970 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B0F30) --------------------------------------------------------  // acclient.c:475947
void __thiscall Waveform::SetDefaults(Waveform *this)
{
  this->type = 1;
  LODWORD(this->base) = 0;
  LODWORD(this->amplitude) = 1065353216;
  LODWORD(this->phase) = 0;
  LODWORD(this->frequency) = 1065353216;
  LODWORD(this->roughness) = 0;
  LODWORD(this->base_vel) = 0;
  LODWORD(this->amplitude_vel) = 0;
  LODWORD(this->phase_vel) = 0;
  LODWORD(this->frequency_vel) = 0;
  LODWORD(this->roughness_vel) = 0;
}

//----- (005B0F60) --------------------------------------------------------  // acclient.c:475963
double __thiscall Waveform::GetValueForPhase(Waveform *this, const float p, const long double time)
{
  double result; // st7@2
  int nNumFrames; // ST34_4@11
  double v6; // st6@7
  char v7; // c0@7
  int v8; // ST34_4@14
  float final_amp; // [sp+24h] [bp-14h]@3
  float final_freq; // [sp+28h] [bp-10h]@3
  float final_phase; // [sp+2Ch] [bp-Ch]@3
  int nFramesPerSecond; // [sp+30h] [bp-8h]@3

  if ( this->type == 1 )
  {
    result = this->base;
  }
  else
  {
    final_amp = this->amplitude_vel * time + this->amplitude;
    final_phase = (p + this->phase) * 3.141592653589793 + this->phase_vel * time;
    final_freq = this->frequency_vel * time + this->frequency;
    result = this->base_vel * time + this->base;
    *(float *)&nFramesPerSecond = result;
    switch ( this->type )
    {
      case 2:
        result = result + final_freq * time + final_phase;
        break;
      case 3:
        result = Random::RollDice(-1.0, 1.0) * final_amp + *(float *)&nFramesPerSecond;
        break;
      case 4:
        result = result + sin(final_freq * time + final_phase) * final_amp;
        break;
      case 5:
        v6 = final_amp;
        if ( !v7 )
          goto LABEL_15;
        result = result - v6;
        break;
      case 6:
        result = result + fabs(sin(final_freq * time + final_phase)) * final_amp;
        break;
      case 7:
        result = PerlinNoise::Noise(final_freq * time + final_phase) * final_amp + *(float *)&nFramesPerSecond;
        break;
      case 8:
        *(float *)&nNumFrames = this->roughness_vel * time + this->roughness;
        result = PerlinNoise::fBm1(final_freq * time + final_phase, 1.0 - *(float *)&nNumFrames, 2.0, 6.0) * final_amp
               + *(float *)&nFramesPerSecond;
        break;
      case 9:
        if ( (signed int)(unsigned __int64)final_amp > 0 && (signed int)(unsigned __int64)final_freq > 0 )
        {
          v8 = (unsigned __int64)final_amp;
          v6 = (double)(signed int)(unsigned __int64)((time
                                                     - (double)(signed int)(unsigned __int64)(time
                                                                                            / (1.0
                                                                                             / (double)(signed int)(unsigned __int64)final_freq
                                                                                             * (double)v8))
                                                     * (1.0
                                                      / (double)(signed int)(unsigned __int64)final_freq
                                                      * (double)v8))
                                                    / (1.0
                                                     / (double)(signed int)(unsigned __int64)final_freq
                                                     * (double)v8)
                                                    * (double)v8)
             * final_phase;
LABEL_15:
          result = result + v6;
        }
        break;
      default:
        return result;
    }
  }
  return result;
}

//----- (005B1180) --------------------------------------------------------  // acclient.c:476043
double __thiscall Waveform::GetValue(Waveform *this, const long double time)
{
  return Waveform::GetValueForPhase(this, 0.0, time);
}

//----- (005B11A0) --------------------------------------------------------  // acclient.c:476049
void __thiscall Waveform::Waveform(Waveform *this)
{
  this->type = 1;
  LODWORD(this->base) = 0;
  LODWORD(this->amplitude) = 1065353216;
  LODWORD(this->phase) = 0;
  LODWORD(this->frequency) = 1065353216;
  LODWORD(this->roughness) = 0;
  LODWORD(this->base_vel) = 0;
  LODWORD(this->amplitude_vel) = 0;
  LODWORD(this->phase_vel) = 0;
  LODWORD(this->frequency_vel) = 0;
  LODWORD(this->roughness_vel) = 0;
}

//----- (005B11D0) --------------------------------------------------------  // acclient.c:476065
void __thiscall Waveform::Waveform(Waveform *this, const float _base)
{
  LODWORD(this->phase) = 0;
  LODWORD(this->roughness) = 0;
  LODWORD(this->base_vel) = 0;
  LODWORD(this->amplitude_vel) = 0;
  LODWORD(this->phase_vel) = 0;
  LODWORD(this->frequency_vel) = 0;
  LODWORD(this->roughness_vel) = 0;
  this->type = 1;
  LODWORD(this->amplitude) = 1065353216;
  LODWORD(this->frequency) = 1065353216;
  this->base = _base;
}

//----- (005B1210) --------------------------------------------------------  // acclient.c:476081
void __thiscall Waveform::Serialize(Waveform *this, Archive *_ar)
{
  Waveform *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  v3 = Archive::GetBytes(_ar, 0x2Cu);
  if ( v3 )
  {
    if ( _ar->m_flags & 1 )
      qmemcpy((void *)v3, v2, 0x2Cu);
    else
      qmemcpy(v2, (const void *)v3, 0x2Cu);
  }
}

//----- (005B1250) --------------------------------------------------------  // acclient.c:476098
char __thiscall Waveform::Parse(Waveform *this, PFileNode *baseNode)
{
  PFileNode *v2; // edi@1
  Waveform *v3; // esi@1
  PFileNode *v4; // ebx@2
  int v5; // ecx@3
  char result; // al@4
  int v7; // ecx@20
  int v8; // ecx@23
  char *v9; // esi@24
  int v10; // eax@26
  int v11; // eax@27
  int v12; // esi@27
  int v13; // ecx@28
  int v14; // eax@30
  int v15; // ecx@31
  int v16; // ecx@34
  int v17; // eax@36
  int v18; // ecx@37
  int v19; // eax@39
  int v20; // ecx@40
  int v21; // ecx@43
  int v22; // eax@45
  int v23; // ecx@46
  int v24; // eax@48
  int v25; // ecx@49
  int v26; // ecx@52
  int v27; // [sp-4h] [bp-48h]@2
  PStringBase<char> name; // [sp+10h] [bp-34h]@6
  float *o_name; // [sp+14h] [bp-30h]@2
  float *v30; // [sp+18h] [bp-2Ch]@2
  float *v31; // [sp+1Ch] [bp-28h]@2
  float *v32; // [sp+20h] [bp-24h]@2
  float *v33; // [sp+24h] [bp-20h]@2
  float *v34; // [sp+28h] [bp-1Ch]@2
  float *v35; // [sp+2Ch] [bp-18h]@2
  float *v36; // [sp+30h] [bp-14h]@2
  float *v37; // [sp+34h] [bp-10h]@2
  PFileNodeIter iter; // [sp+38h] [bp-Ch]@2
  char baseNodea; // [sp+48h] [bp+4h]@2

  v2 = baseNode;
  v3 = this;
  if ( !baseNode )
    return 0;
  LODWORD(this->amplitude) = 1065353216;
  o_name = &this->amplitude;
  LODWORD(this->phase) = 0;
  v30 = &this->phase;
  LODWORD(this->frequency) = 1065353216;
  v31 = &this->frequency;
  LODWORD(this->roughness) = 0;
  v32 = &this->roughness;
  v33 = &this->base_vel;
  LODWORD(this->base_vel) = 0;
  v34 = &this->amplitude_vel;
  LODWORD(this->amplitude_vel) = 0;
  v35 = &this->phase_vel;
  LODWORD(this->phase_vel) = 0;
  v36 = &this->frequency_vel;
  LODWORD(this->frequency_vel) = 0;
  v27 = (int)baseNode;
  baseNodea = 1;
  this->type = 1;
  LODWORD(this->base) = 0;
  v37 = &this->roughness_vel;
  LODWORD(this->roughness_vel) = 0;
  PFileNodeIter::PFileNodeIter(&iter, (PFileNode *)v27);
  v4 = PFileNodeIter::Curr(&iter);
  if ( v4 )
  {
    name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PFileNode::GetNameAsPString(v2, (int)v2, &name);
    if ( !__stricmp(name.m_charbuffer->m_data, waveform_Speed_69.m_charbuffer->m_data) )
    {
      v3->type = 2;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Noise_69.m_charbuffer->m_data) )
    {
      v3->type = 3;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Sine_69.m_charbuffer->m_data) )
    {
      v3->type = 4;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Square_69.m_charbuffer->m_data) )
    {
      v3->type = 5;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Bounce_69.m_charbuffer->m_data) )
    {
      v3->type = 6;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Perlin_69.m_charbuffer->m_data) )
    {
      v3->type = 7;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_Fractal_69.m_charbuffer->m_data) )
    {
      v3->type = 8;
    }
    else if ( !__stricmp(name.m_charbuffer->m_data, waveform_FrameLoop_69.m_charbuffer->m_data) )
    {
      v3->type = 9;
    }
    else
    {
      v27 = v7;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Unknown wave type");
      PFileNode::ReportError((int)v2, v2, (PStringBase<char>)v27);
      v3->type = 1;
      baseNodea = 0;
    }
    if ( !PFileNode::GetNameAsFloat(v4, (int)v2, &v3->base) )
    {
      v27 = v8;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform base value");
      PFileNode::ReportError((int)v2, v4, (PStringBase<char>)v27);
      v9 = &name.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&name.m_charbuffer[-1]) && v9 )
      {
        v10 = *(_DWORD *)v9;
        v27 = 1;
        (*(void (__thiscall **)(char *, signed int))v10)(v9, 1);
      }
      goto LABEL_55;
    }
    v11 = PFileNodeIter::Next(&iter);
    v12 = v11;
    if ( v11 )
    {
      if ( !PFileNode::GetNameAsFloat((PFileNode *)v11, (int)v2, o_name) )
      {
        v27 = v13;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform amplitude value");
LABEL_54:
        PFileNode::ReportError((int)v2, (PFileNode *)v12, (PStringBase<char>)v27);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&name);
LABEL_55:
        PFileNodeIter::~PFileNodeIter(&iter);
        return 0;
      }
      v14 = PFileNodeIter::Next(&iter);
      v12 = v14;
      if ( v14 )
      {
        if ( !PFileNode::GetNameAsFloat((PFileNode *)v14, (int)v2, v30) )
        {
          v27 = v15;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform phase value");
          goto LABEL_54;
        }
        v12 = PFileNodeIter::Next(&iter);
        if ( v12 )
        {
          if ( !PFileNode::GetNameAsFloat((PFileNode *)v12, (int)v2, v31) )
          {
            v27 = v16;
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform frequency value");
            goto LABEL_54;
          }
          v17 = PFileNodeIter::Next(&iter);
          v12 = v17;
          if ( v17 )
          {
            if ( !PFileNode::GetNameAsFloat((PFileNode *)v17, (int)v2, v32) )
            {
              v27 = v18;
              PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform roughness value");
              goto LABEL_54;
            }
            v19 = PFileNodeIter::Next(&iter);
            v12 = v19;
            if ( v19 )
            {
              if ( !PFileNode::GetNameAsFloat((PFileNode *)v19, (int)v2, v33) )
              {
                v27 = v20;
                PStringBase<char>::PStringBase<char>(
                  (PStringBase<char> *)&v27,
                  "Error parsing waveform base velocity value");
                goto LABEL_54;
              }
              v12 = PFileNodeIter::Next(&iter);
              if ( v12 )
              {
                if ( !PFileNode::GetNameAsFloat((PFileNode *)v12, (int)v2, v34) )
                {
                  v27 = v21;
                  PStringBase<char>::PStringBase<char>(
                    (PStringBase<char> *)&v27,
                    "Error parsing waveform amplitude velocity value");
                  goto LABEL_54;
                }
                v22 = PFileNodeIter::Next(&iter);
                v12 = v22;
                if ( v22 )
                {
                  if ( !PFileNode::GetNameAsFloat((PFileNode *)v22, (int)v2, v35) )
                  {
                    v27 = v23;
                    PStringBase<char>::PStringBase<char>(
                      (PStringBase<char> *)&v27,
                      "Error parsing waveform phase velocity value");
                    goto LABEL_54;
                  }
                  v24 = PFileNodeIter::Next(&iter);
                  v12 = v24;
                  if ( v24 )
                  {
                    if ( !PFileNode::GetNameAsFloat((PFileNode *)v24, (int)v2, v36) )
                    {
                      v27 = v25;
                      PStringBase<char>::PStringBase<char>(
                        (PStringBase<char> *)&v27,
                        "Error parsing waveform frequency velocity value");
                      goto LABEL_54;
                    }
                    v12 = PFileNodeIter::Next(&iter);
                    if ( v12 && !PFileNode::GetNameAsFloat((PFileNode *)v12, (int)v2, v37) )
                    {
                      v27 = v26;
                      PStringBase<char>::PStringBase<char>(
                        (PStringBase<char> *)&v27,
                        "Error parsing waveform roughness velocity value");
                      goto LABEL_54;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&name);
    PFileNodeIter::~PFileNodeIter(&iter);
    return baseNodea;
  }
  v27 = (int)&v3->base;
  v3->type = 1;
  if ( PFileNode::GetNameAsFloat(v2, (int)v2, (float *)v27) )
  {
    PFileNodeIter::~PFileNodeIter(&iter);
    result = 1;
  }
  else
  {
    v27 = v5;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v27, "Error parsing waveform base value");
    PFileNode::ReportError((int)v2, v2, (PStringBase<char>)v27);
    PFileNodeIter::~PFileNodeIter(&iter);
    result = 0;
  }
  return result;
}

//----- (005B16F0) --------------------------------------------------------  // acclient.c:476357
void __thiscall Waveform::GetTypeString(Waveform *this, PStringBase<char> *dest)
{
  WaveformType v2; // eax@1
  PSRefBufferCharData<char> *v3; // eax@2
  int v4; // esi@3

  v2 = this->type;
  if ( this->type == 1 )
  {
    v3 = dest->m_charbuffer;
    if ( dest->m_charbuffer != waveform_None_69.m_charbuffer )
    {
      v4 = (int)&v3[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      dest->m_charbuffer = waveform_None_69.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&waveform_None_69.m_charbuffer[-1]);
    }
  }
  else
  {
    switch ( v2 )
    {
      case 2:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Speed_69);
        break;
      case 3:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Noise_69);
        break;
      case 4:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Sine_69);
        break;
      case 5:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Square_69);
        break;
      case 6:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Bounce_69);
        break;
      case 7:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Perlin_69);
        break;
      case 8:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_Fractal_69);
        break;
      case 9:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)dest,
          (const unsigned __int16 *)&waveform_FrameLoop_69);
        break;
      default:
        PStringBase<char>::set(dest, "Unknown");
        break;
    }
  }
}

//----- (005B17F0) --------------------------------------------------------  // acclient.c:476431
void __thiscall Waveform::Output(Waveform *this, PFileNode *baseNode)
{
  Waveform *v2; // edi@1
  int v3; // eax@1
  int v4; // esi@1
  int v5; // ecx@2
  void *v6; // eax@4
  PStringBase<char> v7; // ebp@7
  volatile LONG *v8; // ST2C_4@7
  int v9; // ebp@7
  int v10; // ebp@10
  int v11; // ecx@10
  void *v12; // eax@12
  int v13; // ebp@15
  int v14; // ecx@15
  void *v15; // eax@17
  int v16; // ebp@20
  int v17; // ecx@20
  void *v18; // eax@22
  int v19; // ebp@25
  int v20; // ecx@25
  void *v21; // eax@27
  int v22; // ebp@30
  int v23; // ecx@30
  void *v24; // eax@32
  int v25; // ebp@35
  int v26; // ecx@35
  void *v27; // eax@37
  int v28; // ebp@40
  int v29; // ecx@40
  void *v30; // eax@42
  int v31; // ebp@45
  int v32; // ecx@45
  void *v33; // eax@47
  int v34; // ebp@50
  int v35; // ecx@50
  void *v36; // eax@52
  int v37; // esi@55
  int v38; // ecx@55
  void *v39; // eax@57
  char *v40; // esi@60
  volatile LONG *lpAddend; // [sp+2Ch] [bp-4h]@2
  volatile LONG *lpAddenda; // [sp+2Ch] [bp-4h]@10
  volatile LONG *lpAddendb; // [sp+2Ch] [bp-4h]@15
  volatile LONG *lpAddendc; // [sp+2Ch] [bp-4h]@20
  volatile LONG *lpAddendd; // [sp+2Ch] [bp-4h]@25
  volatile LONG *lpAddende; // [sp+2Ch] [bp-4h]@30
  volatile LONG *lpAddendf; // [sp+2Ch] [bp-4h]@35
  volatile LONG *lpAddendg; // [sp+2Ch] [bp-4h]@40
  volatile LONG *lpAddendh; // [sp+2Ch] [bp-4h]@45
  volatile LONG *lpAddendi; // [sp+2Ch] [bp-4h]@50
  volatile LONG *lpAddendj; // [sp+2Ch] [bp-4h]@55

  v2 = this;
  v3 = ((int (*)(void))baseNode->vfptr[1].__vecDelDtor)();
  v4 = v3;
  if ( v2->type == 1 )
  {
    lpAddend = (volatile LONG *)LODWORD(v2->base);
    v5 = *(_DWORD *)(v3 + 8);
    if ( v5 )
      (**(void (__stdcall ***)(_DWORD))v5)(1);
    *(_DWORD *)(v4 + 8) = 0;
    v6 = operator new(8u);
    if ( v6 )
    {
      *(_DWORD *)v6 = &FileNodeName_Float::vftable;
      *((_DWORD *)v6 + 1) = lpAddend;
      *(_DWORD *)(v4 + 8) = v6;
    }
    else
    {
      *(_DWORD *)(v4 + 8) = 0;
    }
  }
  else
  {
    baseNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    Waveform::GetTypeString(v2, (PStringBase<char> *)&baseNode);
    v7.m_charbuffer = (PSRefBufferCharData<char> *)baseNode;
    v8 = (volatile LONG *)&baseNode[-1].m_bProcessed;
    InterlockedIncrement((volatile LONG *)&baseNode[-1].m_bProcessed);
    InterlockedIncrement(v8);
    PFileNode::SetNameAsPString((PFileNode *)v4, v7);
    v9 = (int)&v7.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    lpAddenda = (volatile LONG *)LODWORD(v2->base);
    v11 = *(_DWORD *)(v10 + 8);
    if ( v11 )
      (**(void (__stdcall ***)(_DWORD))v11)(1);
    *(_DWORD *)(v10 + 8) = 0;
    v12 = operator new(8u);
    if ( v12 )
    {
      *(_DWORD *)v12 = &FileNodeName_Float::vftable;
      *((_DWORD *)v12 + 1) = lpAddenda;
    }
    else
    {
      v12 = 0;
    }
    *(_DWORD *)(v10 + 8) = v12;
    v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    v14 = *(_DWORD *)(v13 + 8);
    lpAddendb = (volatile LONG *)LODWORD(v2->amplitude);
    if ( v14 )
      (**(void (__stdcall ***)(_DWORD))v14)(1);
    *(_DWORD *)(v13 + 8) = 0;
    v15 = operator new(8u);
    if ( v15 )
    {
      *(_DWORD *)v15 = &FileNodeName_Float::vftable;
      *((_DWORD *)v15 + 1) = lpAddendb;
    }
    else
    {
      v15 = 0;
    }
    *(_DWORD *)(v13 + 8) = v15;
    v16 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    v17 = *(_DWORD *)(v16 + 8);
    lpAddendc = (volatile LONG *)LODWORD(v2->phase);
    if ( v17 )
      (**(void (__stdcall ***)(_DWORD))v17)(1);
    *(_DWORD *)(v16 + 8) = 0;
    v18 = operator new(8u);
    if ( v18 )
    {
      *(_DWORD *)v18 = &FileNodeName_Float::vftable;
      *((_DWORD *)v18 + 1) = lpAddendc;
    }
    else
    {
      v18 = 0;
    }
    *(_DWORD *)(v16 + 8) = v18;
    v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    v20 = *(_DWORD *)(v19 + 8);
    lpAddendd = (volatile LONG *)LODWORD(v2->frequency);
    if ( v20 )
      (**(void (__stdcall ***)(_DWORD))v20)(1);
    *(_DWORD *)(v19 + 8) = 0;
    v21 = operator new(8u);
    if ( v21 )
    {
      *(_DWORD *)v21 = &FileNodeName_Float::vftable;
      *((_DWORD *)v21 + 1) = lpAddendd;
    }
    else
    {
      v21 = 0;
    }
    *(_DWORD *)(v19 + 8) = v21;
    v22 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 4))(v4);
    v23 = *(_DWORD *)(v22 + 8);
    lpAddende = (volatile LONG *)LODWORD(v2->roughness);
    if ( v23 )
      (**(void (__stdcall ***)(_DWORD))v23)(1);
    *(_DWORD *)(v22 + 8) = 0;
    v24 = operator new(8u);
    if ( v24 )
    {
      *(_DWORD *)v24 = &FileNodeName_Float::vftable;
      *((_DWORD *)v24 + 1) = lpAddende;
    }
    else
    {
      v24 = 0;
    }
    *(_DWORD *)(v22 + 8) = v24;
    v25 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 4))(v4);
    v26 = *(_DWORD *)(v25 + 8);
    lpAddendf = (volatile LONG *)LODWORD(v2->base_vel);
    if ( v26 )
      (**(void (__stdcall ***)(_DWORD))v26)(1);
    *(_DWORD *)(v25 + 8) = 0;
    v27 = operator new(8u);
    if ( v27 )
    {
      *(_DWORD *)v27 = &FileNodeName_Float::vftable;
      *((_DWORD *)v27 + 1) = lpAddendf;
    }
    else
    {
      v27 = 0;
    }
    *(_DWORD *)(v25 + 8) = v27;
    v28 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 4))(v4);
    v29 = *(_DWORD *)(v28 + 8);
    lpAddendg = (volatile LONG *)LODWORD(v2->amplitude_vel);
    if ( v29 )
      (**(void (__stdcall ***)(_DWORD))v29)(1);
    *(_DWORD *)(v28 + 8) = 0;
    v30 = operator new(8u);
    if ( v30 )
    {
      *(_DWORD *)v30 = &FileNodeName_Float::vftable;
      *((_DWORD *)v30 + 1) = lpAddendg;
    }
    else
    {
      v30 = 0;
    }
    *(_DWORD *)(v28 + 8) = v30;
    v31 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 4))(v4);
    v32 = *(_DWORD *)(v31 + 8);
    lpAddendh = (volatile LONG *)LODWORD(v2->phase_vel);
    if ( v32 )
      (**(void (__stdcall ***)(_DWORD))v32)(1);
    *(_DWORD *)(v31 + 8) = 0;
    v33 = operator new(8u);
    if ( v33 )
    {
      *(_DWORD *)v33 = &FileNodeName_Float::vftable;
      *((_DWORD *)v33 + 1) = lpAddendh;
    }
    else
    {
      v33 = 0;
    }
    *(_DWORD *)(v31 + 8) = v33;
    v34 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 4))(v4);
    v35 = *(_DWORD *)(v34 + 8);
    lpAddendi = (volatile LONG *)LODWORD(v2->frequency_vel);
    if ( v35 )
      (**(void (__stdcall ***)(_DWORD))v35)(1);
    *(_DWORD *)(v34 + 8) = 0;
    v36 = operator new(8u);
    if ( v36 )
    {
      *(_DWORD *)v36 = &FileNodeName_Float::vftable;
      *((_DWORD *)v36 + 1) = lpAddendi;
    }
    else
    {
      v36 = 0;
    }
    *(_DWORD *)(v34 + 8) = v36;
    v37 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)v4 + 4))(v4);
    v38 = *(_DWORD *)(v37 + 8);
    lpAddendj = (volatile LONG *)LODWORD(v2->roughness_vel);
    if ( v38 )
      (**(void (__stdcall ***)(_DWORD))v38)(1);
    *(_DWORD *)(v37 + 8) = 0;
    v39 = operator new(8u);
    if ( v39 )
    {
      *(_DWORD *)v39 = &FileNodeName_Float::vftable;
      *((_DWORD *)v39 + 1) = lpAddendj;
    }
    else
    {
      v39 = 0;
    }
    *(_DWORD *)(v37 + 8) = v39;
    v40 = (char *)&baseNode[-1].sub_nodes.m_num;
    if ( !InterlockedDecrement((volatile LONG *)&baseNode[-1].m_bProcessed) && v40 )
      (**(void (__thiscall ***)(char *, signed int))v40)(v40, 1);
  }
}
// 7970D0: using guessed type int (__thiscall *FileNodeName_Float::vftable)(void *, char);

//----- (005B1B80) --------------------------------------------------------  // acclient.c:476697
PStringBase<char> *__thiscall Waveform::ToString(Waveform *this, PStringBase<char> *result)
{
  Waveform *v2; // esi@1
  char *v3; // esi@3
  PSRefBufferCharData<char> *v4; // eax@8
  char *v5; // esi@8
  PStringBase<char> strReturn; // [sp+30h] [bp-8h]@1
  PStringBase<char> strWaveformType; // [sp+34h] [bp-4h]@3

  v2 = this;
  PStringBase<char>::PStringBase<char>(&strReturn, &name);
  if ( v2->type == 1 )
  {
    PStringBase<char>::sprintf(&strReturn, "%.3f", v2->base);
  }
  else if ( v2->type == 2 )
  {
    PStringBase<char>::sprintf(&strReturn, "[Speed] Base:%.3f, Velocity:%.3f", v2->base, v2->frequency);
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&strWaveformType, &name);
    Waveform::GetTypeString(v2, &strWaveformType);
    PStringBase<char>::sprintf(
      &strReturn,
      "[%s] Base:%.3f, Amp:%.3f, Phase:%.3f, Freq:%.3f",
      strWaveformType.m_charbuffer,
      v2->base,
      v2->amplitude,
      v2->phase,
      v2->frequency);
    v3 = &strWaveformType.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strWaveformType.m_charbuffer[-1]) && v3 )
      (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  }
  v4 = strReturn.m_charbuffer;
  result->m_charbuffer = strReturn.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v4[-1]);
  v5 = &strReturn.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strReturn.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return result;
}

//----- (0070E330) --------------------------------------------------------  // acclient.c:801214
int sub_70E330()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_69, "None");
  return atexit(_E74_93);
}

//----- (0070E350) --------------------------------------------------------  // acclient.c:801221
int _E76_76()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_69, "Speed");
  return atexit(sub_777820);
}

//----- (0070E370) --------------------------------------------------------  // acclient.c:801228
int _E79_71()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_69, "Noise");
  return atexit(_E80_69);
}

//----- (0070E390) --------------------------------------------------------  // acclient.c:801235
int _E82_47()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_69, "Sine");
  return atexit(_E83_45);
}

//----- (0070E3B0) --------------------------------------------------------  // acclient.c:801242
int _E85_33()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_69, "Square");
  return atexit(_E86_26);
}

//----- (0070E3D0) --------------------------------------------------------  // acclient.c:801249
int _E88_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_69, "Bounce");
  return atexit(_E89_36);
}

//----- (0070E3F0) --------------------------------------------------------  // acclient.c:801256
int sub_70E3F0()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_69, "Perlin");
  return atexit(_E92_41);
}

//----- (0070E410) --------------------------------------------------------  // acclient.c:801263
int _E94_32()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_69, "Fractal");
  return atexit(sub_777940);
}

//----- (0070E430) --------------------------------------------------------  // acclient.c:801270
int sub_70E430()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_69, "FrameLoop");
  return atexit(sub_777970);
}

//----- (007777F0) --------------------------------------------------------  // acclient.c:911151
void __cdecl _E74_93()
{
  char *v0; // esi@1

  v0 = &waveform_None_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777820) --------------------------------------------------------  // acclient.c:911164
void __cdecl sub_777820()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777850) --------------------------------------------------------  // acclient.c:911177
void __cdecl _E80_69()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777880) --------------------------------------------------------  // acclient.c:911190
void __cdecl _E83_45()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007778B0) --------------------------------------------------------  // acclient.c:911203
void __cdecl _E86_26()
{
  char *v0; // esi@1

  v0 = &waveform_Square_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007778E0) --------------------------------------------------------  // acclient.c:911216
void __cdecl _E89_36()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777910) --------------------------------------------------------  // acclient.c:911229
void __cdecl _E92_41()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777940) --------------------------------------------------------  // acclient.c:911242
void __cdecl sub_777940()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00777970) --------------------------------------------------------  // acclient.c:911255
void __cdecl sub_777970()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_69.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_69.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

