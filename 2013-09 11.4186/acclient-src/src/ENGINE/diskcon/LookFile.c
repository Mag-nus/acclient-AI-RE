/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LookFile
   Object     : ENGINE\diskcon\LookFile.obj
   Functions  : 8
   Addresses  : 00671850 - 00714DD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00671850) --------------------------------------------------------  // acclient.c:648158
PStringBase<unsigned short> *__thiscall LookFile::GetFoundPath(LookFile *this, PStringBase<unsigned short> *result)
{
  PSRefBufferCharData<unsigned short> *v2; // eax@1

  v2 = this->_path.m_charbuffer;
  result->m_charbuffer = this->_path.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1].m_data[8]);
  return result;
}

//----- (00671870) --------------------------------------------------------  // acclient.c:648169
char __thiscall LookFile::IsFileHere(LookFile *this, PStringBase<unsigned short> *file, PStringBase<unsigned short> *path)
{
  PStringBase<unsigned short> *v3; // edi@1
  PStringBase<unsigned short> *v4; // esi@1
  PStringBase<unsigned short> *v5; // ebp@2
  int v6; // eax@2
  bool v7; // zf@6
  PStringBase<unsigned short> **v8; // eax@6
  HANDLE v9; // eax@8
  int v11; // [sp+0h] [bp-18h]@8

  v3 = file;
  v4 = (PStringBase<unsigned short> *)this;
  if ( *(_DWORD *)&file->m_charbuffer[-1].m_data[14] == 1 )
    return 0;
  v5 = path;
  v6 = *(_DWORD *)&path->m_charbuffer[-1].m_data[14];
  if ( v6 == 1 )
    goto LABEL_21;
  if ( *(_DWORD *)&this->_path.m_charbuffer[-1].m_data[14] != 1 )
    return 0;
  if ( v6 == 1 )
  {
LABEL_21:
    if ( *(_DWORD *)&this->_path.m_charbuffer[-1].m_data[14] != 1 )
    {
      v7 = v6 == 1;
      v8 = (PStringBase<unsigned short> **)this;
      if ( v7 )
        goto LABEL_8;
      goto LABEL_7;
    }
    return 0;
  }
LABEL_7:
  v8 = (PStringBase<unsigned short> **)path;
LABEL_8:
  file = *v8;
  InterlockedIncrement((volatile LONG *)&file[-4]);
  PSUtils::path_append((PStringBase<unsigned short> *)&file, v3);
  v9 = CreateFileW((LPCWSTR)file, 0x80000000, 3u, 0, 3u, 0x80u, 0);
  if ( v9 == (HANDLE)-1 )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v11 - 20 + 4)) && v11 != 20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))(v11 - 20))(v11 - 20, 1);
    return 0;
  }
  CloseHandle(v9);
  if ( *(_DWORD *)&v4->m_charbuffer[-1].m_data[14] == 1 )
    PStringBase<unsigned short>::operator=(v4, (const unsigned __int16 *)v5);
  if ( !InterlockedDecrement((volatile LONG *)(v11 - 20 + 4)) && v11 != 20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))(v11 - 20))(v11 - 20, 1);
  return 1;
}

//----- (00671960) --------------------------------------------------------  // acclient.c:648225
char __thiscall LookFile::LookForFile(LookFile *this, PStringBase<unsigned short> file, PStringBase<unsigned short> path, bool try_all_f)
{
  LookFile *v4; // esi@1
  char *v5; // esi@2
  char *v6; // esi@5
  char v7; // al@8
  PSRefBufferCharData<unsigned short> *v8; // eax@9
  int v9; // ebx@9
  int v10; // edi@10
  volatile LONG *v11; // ST10_4@13
  const unsigned __int16 *v12; // eax@18
  PStringBase<unsigned short> *v13; // ST08_4@23
  PStringBase<unsigned short> *v14; // eax@23
  bool v15; // bl@23
  int v16; // esi@25
  char *v17; // esi@28
  char *v18; // esi@31
  char found; // [sp+11h] [bp-Dh]@14
  PStringBase<unsigned short> result; // [sp+12h] [bp-Ch]@18
  PStringBase<unsigned short> v21; // [sp+16h] [bp-8h]@23
  char v22; // [sp+1Ah] [bp-4h]@23

  v4 = this;
  if ( *(_DWORD *)&file.m_charbuffer[-1].m_data[14] == 1 )
  {
    v5 = (char *)&file.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&file.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
    v6 = (char *)&path.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&path.m_charbuffer[-1].m_data[8]) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
    }
    v7 = 0;
  }
  else
  {
    v8 = this->_path.m_charbuffer;
    v9 = (int)InterlockedIncrement;
    if ( (wchar_t *)this->_path.m_charbuffer != PStringBase<unsigned short>::s_NullBuffer )
    {
      v10 = (int)&v8[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1].m_data[8]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      v11 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      v4->_path.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement(v11);
    }
    found = 0;
    if ( *(_DWORD *)&path.m_charbuffer[-1].m_data[14] == 1 || (found = LookFile::IsFileHere(v4, &file, &path)) == 0 )
    {
      if ( try_all_f )
      {
        PStringBase<unsigned short>::allocate(&path, 0x106u);
        *(_DWORD *)&try_all_f = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        PStringBase<char>::allocate((PStringBase<char> *)&try_all_f, 0x105u);
        if ( !PSUtils::get_cwd((PStringBase<char> *)&try_all_f)
          || (v12 = (const unsigned __int16 *)PStringBase<char>::to_wpstring(
                                                (PStringBase<char> *)&try_all_f,
                                                &result,
                                                0),
              PStringBase<unsigned short>::operator=(&path, v12),
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result),
              (found = LookFile::IsFileHere(v4, &file, &path)) == 0) )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&result, L"PROJECT_DAT");
          LOBYTE(v9) = PSUtils::GetEnvironmentVariableA(&result, &path);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
          if ( !(_BYTE)v9 || (found = LookFile::IsFileHere(v4, &file, &path)) == 0 )
          {
            if ( *(_DWORD *)&v4->_key_path.m_charbuffer[-1].m_data[12] != 1
              && *(_DWORD *)&v4->_key.m_charbuffer[-1].m_data[12] != 1 )
            {
              v13 = PStringBase<char>::to_wpstring(&v4->_key, &v21, 0);
              v14 = PStringBase<char>::to_wpstring(&v4->_key_path, &result, 0);
              v15 = RegEdit::QueryWStrValue((RegEdit *)&v22, v9, v14, v13, &path, (HKEY__ *)0x80000002);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v21);
              if ( v15 )
                found = LookFile::IsFileHere(v4, &file, &path);
            }
          }
        }
        v16 = try_all_f - 20;
        if ( !InterlockedDecrement((volatile LONG *)(try_all_f - 20 + 4)) && v16 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
      }
    }
    v17 = (char *)&file.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&file.m_charbuffer[-1].m_data[8]) && v17 )
      (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
    v18 = (char *)&path.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&path.m_charbuffer[-1].m_data[8]) && v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    v7 = found;
  }
  return v7;
}

//----- (00671BD0) --------------------------------------------------------  // acclient.c:648327
char __thiscall LookFile::LookForFile(LookFile *this, PStringBase<char> file, PStringBase<char> path, bool try_all_f)
{
  LookFile *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // ecx@1
  char v6; // bl@1
  char *v7; // esi@1
  int v8; // edx@3
  char *v9; // esi@4
  int v10; // edx@6
  PStringBase<unsigned short> v12; // [sp-Ch] [bp-18h]@1
  PStringBase<unsigned short> v13; // [sp-8h] [bp-14h]@1
  signed int v14; // [sp-4h] [bp-10h]@1

  v14 = try_all_f;
  v13.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v4 = this;
  PStringBase<char>::to_wpstring(&path, &v13, 0);
  v12.m_charbuffer = v5;
  PStringBase<char>::to_wpstring(&file, &v12, 0);
  v6 = LookFile::LookForFile(v4, v12, v13, v14);
  v7 = &file.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&file.m_charbuffer[-1]) && v7 )
  {
    v8 = *(_DWORD *)v7;
    v14 = 1;
    (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
  }
  v9 = &path.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&path.m_charbuffer[-1]) && v9 )
  {
    v10 = *(_DWORD *)v9;
    v14 = 1;
    (*(void (__thiscall **)(char *, signed int))v10)(v9, 1);
  }
  return v6;
}

//----- (00714DA0) --------------------------------------------------------  // acclient.c:807709
int sub_714DA0()
{
  return atexit(nullsub_80);
}

//----- (00714DB0) --------------------------------------------------------  // acclient.c:807715
int _E76_86()
{
  return atexit(nullsub_81);
}

//----- (00714DC0) --------------------------------------------------------  // acclient.c:807721
int _E79_81()
{
  return atexit(_E80_78);
}

//----- (00714DD0) --------------------------------------------------------  // acclient.c:807727
int sub_714DD0()
{
  return atexit(nullsub_83);
}

