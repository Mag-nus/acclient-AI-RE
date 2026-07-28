/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MMapUtil
   Object     : ENGINE\engine_utils\MMapUtil.obj
   Functions  : 5
   Addresses  : 006BC1A0 - 006BC270 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006BC1A0) --------------------------------------------------------  // acclient.c:723932
void __thiscall MMapUtil::MMapUtil(MMapUtil *this)
{
  MMapUtil *v1; // esi@1

  v1 = this;
  DataSource::DataSource((DataSource *)&this->vfptr);
  v1->fFileOpen_ = 0;
  v1->fFileAlreadyExisted_ = 0;
  v1->loadDataFileAddr_ = 0;
  v1->loadDataFile_ = 0;
  v1->loadDataFileMapping_ = 0;
  v1->vfptr = (DataSourceVtbl *)&MMapUtil::vftable;
}
// 806A80: using guessed type int (__thiscall *MMapUtil::vftable)(void *, char);

//----- (006BC1D0) --------------------------------------------------------  // acclient.c:723948
void __thiscall MMapUtil::~MMapUtil(MMapUtil *this)
{
  MMapUtil *v1; // esi@1
  bool v2; // al@1
  const void *v3; // eax@2

  v1 = this;
  v2 = this->fFileOpen_;
  this->vfptr = (DataSourceVtbl *)&MMapUtil::vftable;
  if ( v2 )
  {
    CloseHandle(this->loadDataFile_);
    v3 = v1->loadDataFileAddr_;
    if ( v3 )
    {
      if ( !UnmapViewOfFile(v3) )
        GetLastError();
      if ( !CloseHandle(v1->loadDataFileMapping_) )
        GetLastError();
    }
    v1->fFileOpen_ = 0;
  }
  DataSource::~DataSource((DataSource *)&v1->vfptr);
}
// 806A80: using guessed type int (__thiscall *MMapUtil::vftable)(void *, char);

//----- (006BC240) --------------------------------------------------------  // acclient.c:723981
bool __thiscall MMapUtil::GetFileAlreadyExisted(MMapUtil *this)
{
  return this->fFileAlreadyExisted_;
}

//----- (006BC250) --------------------------------------------------------  // acclient.c:723987
MMapUtil *__thiscall MMapUtil::vector_deleting_destructor(MMapUtil *this, unsigned int a2)
{
  MMapUtil *v2; // esi@1

  v2 = this;
  MMapUtil::~MMapUtil(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006BC270) --------------------------------------------------------  // acclient.c:723999
char *__thiscall MMapUtil::MMap(MMapUtil *this, const char *filename, bool readOnly, bool fMustAlreadyExist, bool nukeOldFile, int sizeNeeded, unsigned int fileOffsetHighOrder32Bits, unsigned int fileOffsetLowOrder32Bits)
{
  const char *v8; // ebp@1
  MMapUtil *v9; // esi@1
  bool v10; // al@1
  const char *v11; // edi@1
  volatile LONG *v12; // ST1C_4@1
  char *result; // eax@6
  bool v14; // bl@9
  HANDLE v15; // ecx@11
  void *v16; // ST08_4@16
  HANDLE v17; // eax@17
  LPVOID v18; // eax@19
  int v19; // eax@21
  DWORD v20; // [sp-1Ch] [bp-28h]@9
  DWORD v21; // [sp-10h] [bp-1Ch]@9

  v8 = filename;
  v9 = this;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&filename, filename);
  v10 = PSUtils::check_access((PStringBase<char> *)&filename, 0);
  v11 = filename - 20;
  v12 = (volatile LONG *)(filename - 16);
  v9->fFileAlreadyExisted_ = v10;
  if ( !InterlockedDecrement(v12) && v11 )
    (**(void (__thiscall ***)(const char *, signed int))v11)(v11, 1);
  if ( fMustAlreadyExist && !v9->fFileAlreadyExisted_ )
    return 0;
  if ( !v9->fFileAlreadyExisted_ || nukeOldFile )
  {
    v14 = readOnly;
    v21 = 2;
    v20 = readOnly != 0 ? 2147483648 : -1073741824;
  }
  else
  {
    v14 = readOnly;
    v21 = 3;
    v20 = readOnly != 0 ? 2147483648 : -1073741824;
  }
  v15 = CreateFileA(v8, v20, 1u, 0, v21, 0x8000000u, 0);
  v9->loadDataFile_ = v15;
  if ( v15 == (HANDLE)-1 )
  {
    GetLastError();
    return 0;
  }
  v9->fFileOpen_ = 1;
  if ( !v14 )
  {
    if ( sizeNeeded )
    {
      SetFilePointer(v15, sizeNeeded, 0, 0);
      v16 = v9->loadDataFile_;
      *(_DWORD *)&readOnly = 0;
      WriteFile(v16, &readOnly, 4u, (LPDWORD)&fMustAlreadyExist, 0);
      if ( fMustAlreadyExist != 4 )
        return 0;
    }
  }
  v17 = CreateFileMappingA(v9->loadDataFile_, 0, 2 * (v14 == 0) + 2, 0, 0, 0);
  v9->loadDataFileMapping_ = v17;
  if ( v17 )
  {
    v18 = MapViewOfFileEx(v17, v14 != 0 ? 4 : 983071, fileOffsetHighOrder32Bits, fileOffsetLowOrder32Bits, 0, 0);
    v9->loadDataFileAddr_ = (char *)v18;
    if ( v18 )
    {
      v19 = GetFileSize(v9->loadDataFile_, 0);
      DataSource::Open((DataSource *)&v9->vfptr, v9->loadDataFileAddr_, v19);
      result = v9->loadDataFileAddr_;
    }
    else
    {
      GetLastError();
      CloseHandle(v9->loadDataFile_);
      CloseHandle(v9->loadDataFileMapping_);
      result = 0;
    }
  }
  else
  {
    GetLastError();
    CloseHandle(v9->loadDataFile_);
    result = 0;
  }
  return result;
}

