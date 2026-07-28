/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : cdirsnd
   Object     : PORTAL\sound\cdirsnd.obj
   Functions  : 3
   Addresses  : 00553D00 - 00553E40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00553D00) --------------------------------------------------------  // acclient.c:387097
BOOL __thiscall CDirSound::DirectSoundOK(CDirSound *this)
{
  return this->m_pDirectSoundObj != 0;
}

//----- (00553D10) --------------------------------------------------------  // acclient.c:387103
void __thiscall CDirSound::CDirSound(CDirSound *this, HWND__ *hWnd)
{
  CDirSound *v2; // esi@1
  char *v3; // edi@1
  char *v4; // ebx@1
  char *v5; // ebp@1
  IDirectSound *v6; // eax@4
  int v7; // eax@6
  _DSBUFFERDESC dsBD; // [sp+10h] [bp-24h]@4

  v2 = this;
  v3 = (char *)&this->m_pDirectSoundObj;
  v4 = (char *)&this->m_lpDs3dListener;
  v5 = (char *)&this->m_3DSoundBuffer;
  this->m_hWindow = hWnd;
  this->m_pDirectSoundObj = 0;
  this->m_lpDs3dListener = 0;
  this->m_3DSoundBuffer = 0;
  if ( !DirectSoundCreate(0, &this->m_pDirectSoundObj, 0) )
  {
    if ( (*(int (__stdcall **)(_DWORD, HWND__ *, signed int))(**(_DWORD **)v3 + 24))(*(_DWORD *)v3, v2->m_hWindow, 2) )
    {
      *(_DWORD *)v3 = 0;
    }
    else
    {
      memset(&dsBD, 0, sizeof(dsBD));
      v6 = v2->m_pDirectSoundObj;
      dsBD.dwSize = 36;
      dsBD.dwFlags = 17;
      dsBD.dwBufferBytes = 0;
      if ( !((int (__stdcall *)(IDirectSound *, _DSBUFFERDESC *, char *, _DWORD))v6->vfptr[1].QueryInterface)(
              v6,
              &dsBD,
              v5,
              0)
        && !(*(int (__stdcall **)(_DWORD, GUID *, char *))**(int (__stdcall ****)(_DWORD, _DWORD, _DWORD))v5)(
              *(_DWORD *)v5,
              &IID_IDirectSound3DListener,
              v4) )
      {
        (*(void (__stdcall **)(_DWORD, signed int, signed int))(**(_DWORD **)v4 + 60))(*(_DWORD *)v4, 1008981770, 1);
        (*(void (__stdcall **)(_DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int, _DWORD, signed int))(**(_DWORD **)v4 + 52))(
          *(_DWORD *)v4,
          -1082130432,
          0,
          0,
          0,
          1065353216,
          0,
          1);
        (*(void (__stdcall **)(_DWORD))(**(_DWORD **)v4 + 68))(*(_DWORD *)v4);
        v7 = *(_DWORD *)v5;
        v2->m_defaultFormat.wFormatTag = 1;
        v2->m_defaultFormat.nChannels = 2;
        v2->m_defaultFormat.wBitsPerSample = 16;
        v2->m_defaultFormat.nSamplesPerSec = 11025;
        v2->m_defaultFormat.nBlockAlign = 4;
        v2->m_defaultFormat.nAvgBytesPerSec = 44100;
        v2->m_defaultFormat.cbSize = 0;
        (*(void (__stdcall **)(int, CDirSound *))(*(_DWORD *)v7 + 56))(v7, v2);
        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, signed int))(**(_DWORD **)v5 + 48))(*(_DWORD *)v5, 0, 0, 1);
      }
    }
  }
}

//----- (00553E40) --------------------------------------------------------  // acclient.c:387171
void __thiscall CDirSound::~CDirSound(CDirSound *this)
{
  CDirSound *v1; // esi@1
  IDirectSound3DListener *v2; // eax@1
  IDirectSoundBuffer *v3; // eax@3
  IDirectSound *v4; // eax@5

  v1 = this;
  v2 = this->m_lpDs3dListener;
  if ( v2 )
  {
    v2->vfptr->Release((IUnknown *)v2);
    v1->m_lpDs3dListener = 0;
  }
  v3 = v1->m_3DSoundBuffer;
  if ( v3 )
  {
    v3->vfptr->Release((IUnknown *)v1->m_3DSoundBuffer);
    v1->m_3DSoundBuffer = 0;
  }
  v4 = v1->m_pDirectSoundObj;
  if ( v4 )
  {
    v4->vfptr->Release((IUnknown *)v1->m_pDirectSoundObj);
    v1->m_pDirectSoundObj = 0;
  }
}

