/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : File2IDTable
   Object     : ENGINE\filedb_core\File2IDTable.obj
   Functions  : 62
   Addresses  : 00678280 - 00714FB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00678280) --------------------------------------------------------  // acclient.c:654878
unsigned __int64 __cdecl FileTime2TimeType(_FILETIME *ft)
{
  unsigned __int64 v1; // rax@1

  v1 = ft->dwLowDateTime + ((unsigned __int64)ft->dwHighDateTime << 32) + 717324288;
  HIDWORD(v1) -= 27111903;
  return v1 / 0x989680;
}

//----- (006782C0) --------------------------------------------------------  // acclient.c:654888
char __stdcall TFile2IDTable::GetFileWriteTimeByEntry(TFileEntry *pEntry, int *FileWriteTime)
{
  *FileWriteTime = pEntry->m_tFileWriteTime;
  return 1;
}

//----- (006782E0) --------------------------------------------------------  // acclient.c:654895
bool __thiscall TFile2IDTable::GetFileWriteTimeByDID(TFile2IDTable *this, IDClass<_tagDataID,32,0> did, unsigned int dbtype, int *FileWriteTime)
{
  TFile2IDTable *v4; // esi@1
  TReadOnlyFile2IDTableVtbl *v5; // eax@1
  bool result; // al@2
  TFileEntry *pEntry; // [sp+Ch] [bp-4h]@1

  pEntry = (TFileEntry *)this;
  v4 = this;
  v5 = this->vfptr;
  pEntry = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, unsigned int, TFileEntry **))v5[2].GetDBTypeString)(
                          did.id,
                          dbtype,
                          &pEntry) )
  {
    result = ((int (__thiscall *)(TFile2IDTable *, TFileEntry *, int *))v4->vfptr[2].GetDBTypes)(
               v4,
               pEntry,
               FileWriteTime);
  }
  else
  {
    *FileWriteTime = (unsigned __int64)-1.0;
    result = 0;
  }
  return result;
}

//----- (00678340) --------------------------------------------------------  // acclient.c:654925
IDClass<_tagDataID,32,0> *__thiscall TFile2IDTable::GetHighestDID(TFile2IDTable *this, IDClass<_tagDataID,32,0> *result, unsigned int _dbtype)
{
  int v3; // eax@1
  unsigned int v4; // ecx@2
  IDClass<_tagDataID,32,0> *v5; // eax@2

  v3 = ((int (__stdcall *)(unsigned int))this->vfptr[2].GetDIDs)(_dbtype);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v3 + 16);
    v5 = result;
    result->id = v4;
  }
  else
  {
    v5 = result;
    result->id = stru_8F7704.id;
  }
  return v5;
}

//----- (00678370) --------------------------------------------------------  // acclient.c:654947
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *__thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v2; // esi@1
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable;
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
// 7FE138: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable[7])(void *, char);

//----- (006783B0) --------------------------------------------------------  // acclient.c:654968
IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *v2; // esi@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable;
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
// 7FE13C: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable[6])(void *, char);

//----- (006783F0) --------------------------------------------------------  // acclient.c:654989
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *v2; // esi@1
  HashTableData<unsigned long,TDBTypeEntry *> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable;
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
// 7FE140: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable[5])(void *, char);

//----- (00678430) --------------------------------------------------------  // acclient.c:655010
PStringBase<char> *__thiscall TFileEntry::GetFileName(TFileEntry *this, PStringBase<char> *result)
{
  PSRefBufferCharData<char> *v2; // eax@1

  v2 = this->m_pFileName.m_charbuffer;
  result->m_charbuffer = v2;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  return result;
}

//----- (00678450) --------------------------------------------------------  // acclient.c:655021
void __thiscall TFileEntry::SetPath(TFileEntry *this, PStringBase<char> *pNewPath)
{
  TFileEntry *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_pPath.m_charbuffer;
  if ( v3 != pNewPath->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = pNewPath->m_charbuffer;
    v2->m_pPath.m_charbuffer = pNewPath->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (006784A0) --------------------------------------------------------  // acclient.c:655045
void __thiscall TFileEntry::SetFileName(TFileEntry *this, PStringBase<char> *i_strFileName)
{
  TFileEntry *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_pFileName.m_charbuffer;
  if ( v3 != i_strFileName->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = i_strFileName->m_charbuffer;
    v2->m_pFileName.m_charbuffer = i_strFileName->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (006784F0) --------------------------------------------------------  // acclient.c:655069
void __thiscall TFileEntry::~TFileEntry(TFileEntry *this)
{
  TFileEntry *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4

  v1 = this;
  v2 = &this->m_pFileName.m_charbuffer[-2].m_data[12];
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)TFileEntry::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_pPath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7FE144: using guessed type int (__thiscall *TFileEntry::vftable[4])(void *, char);

//----- (00678550) --------------------------------------------------------  // acclient.c:655089
TFileEntry *__thiscall TFileEntry::vector_deleting_destructor(TFileEntry *this, unsigned int a2)
{
  TFileEntry *v2; // esi@1

  v2 = this;
  TFileEntry::~TFileEntry(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00678570) --------------------------------------------------------  // acclient.c:655101
void __thiscall TFileEntry::TFileEntry(TFileEntry *this, PStringBase<char> pContainingPath, PStringBase<char> pName)
{
  TFileEntry *v3; // esi@1

  v3 = this;
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)TFileEntry::vftable;
  this->m_pPath.m_charbuffer = pContainingPath.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&pContainingPath.m_charbuffer[-1]);
  v3->m_pFileName.m_charbuffer = pName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&pName.m_charbuffer[-1]);
  v3->m_did.id = stru_8F7704.id;
  v3->m_dbtype = 0;
  v3->m_EntryType = 0;
  v3->m_bAuthoritative = 1;
  v3->m_tFileWriteTime = (unsigned __int64)-1.0;
  if ( !InterlockedDecrement((volatile LONG *)&pContainingPath.m_charbuffer[-1])
    && pContainingPath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&pContainingPath.m_charbuffer[-2].m_data[12])(
      &pContainingPath.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&pName.m_charbuffer[-1])
    && pName.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&pName.m_charbuffer[-2].m_data[12])(&pName.m_charbuffer[-2].m_data[12], 1);
}
// 7FE144: using guessed type int (__thiscall *TFileEntry::vftable[4])(void *, char);

//----- (00678610) --------------------------------------------------------  // acclient.c:655129
IDClass<_tagDataID,32,0> *__thiscall TFile2IDTable::GetDIDByFileName(TFile2IDTable *this, IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, unsigned int _dbtype)
{
  char *v4; // edi@1
  TFile2IDTable *v5; // esi@1
  PSRefBufferCharData<char> *v6; // ST04_4@1
  char v7; // al@1
  char *v8; // esi@1
  LONG v9; // eax@2
  TFileEntry *pEntry; // [sp+10h] [bp-4h]@1

  v4 = &_FileName.m_charbuffer[-2].m_data[12];
  v5 = this;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  PSUtils::strip_directory(&_FileName);
  pEntry = 0;
  v6 = _FileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  v7 = ((int (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, TFileEntry **, signed int))v5->vfptr[2].GetFullPathByFileName)(
         v5,
         v6,
         &pEntry,
         1);
  v8 = &_FileName.m_charbuffer[-2].m_data[12];
  if ( v7 )
  {
    result->id = pEntry->m_did.id;
    v9 = InterlockedDecrement((volatile LONG *)v8 + 1);
  }
  else
  {
    result->id = stru_8F7704.id;
    v9 = InterlockedDecrement((volatile LONG *)v8 + 1);
  }
  if ( !v9 && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (006786D0) --------------------------------------------------------  // acclient.c:655170
char __thiscall TFile2IDTable::GetFileNameByDID(TFile2IDTable *this, IDClass<_tagDataID,32,0> _did, unsigned int _dbtype, PStringBase<char> *_FileName)
{
  TReadOnlyFile2IDTableVtbl *v4; // eax@1
  PSRefBufferCharData<char> *v5; // esi@2
  PSRefBufferCharData<char> *v6; // eax@2
  int v7; // ebx@3
  int v8; // esi@7
  char result; // al@10
  TFileEntry *pEntry; // [sp+Ch] [bp-4h]@1

  pEntry = (TFileEntry *)this;
  v4 = this->vfptr;
  pEntry = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, unsigned int, TFileEntry **))v4[2].GetDBTypeString)(
                          _did.id,
                          _dbtype,
                          &pEntry) )
  {
    v5 = pEntry->m_pFileName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
    v6 = _FileName->m_charbuffer;
    if ( _FileName->m_charbuffer != v5 )
    {
      v7 = (int)&v6[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      _FileName->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1]);
    }
    v8 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
    {
      if ( v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00678770) --------------------------------------------------------  // acclient.c:655215
bool __thiscall TFile2IDTable::GetFullPathByDID(TFile2IDTable *this, IDClass<_tagDataID,32,0> _did, unsigned int _dbtype, PStringBase<char> *_FullPath)
{
  TFile2IDTable *v4; // esi@1
  TReadOnlyFile2IDTableVtbl *v5; // eax@1
  bool result; // al@2
  PSRefBufferCharData<char> *v7; // eax@3
  int v8; // esi@4
  volatile LONG *v9; // ST04_4@7
  TFileEntry *pEntry; // [sp+Ch] [bp-4h]@1

  pEntry = (TFileEntry *)this;
  v4 = this;
  v5 = this->vfptr;
  pEntry = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, unsigned int, TFileEntry **))v5[2].GetDBTypeString)(
                          _did.id,
                          _dbtype,
                          &pEntry) )
  {
    result = (int)v4->vfptr[2].GetHighestDID(
                    (TReadOnlyFile2IDTable *)v4,
                    (IDClass<_tagDataID,32,0> *)pEntry,
                    (unsigned int)_FullPath);
  }
  else
  {
    v7 = _FullPath->m_charbuffer;
    if ( _FullPath->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v8 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      _FullPath->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v9);
    }
    result = 0;
  }
  return result;
}

//----- (00678800) --------------------------------------------------------  // acclient.c:655260
bool __thiscall TFile2IDTable::GetFullPathByFileName(TFile2IDTable *this, PStringBase<char> _FileName, unsigned int _dbtype, PStringBase<char> *_FullPath)
{
  char *v4; // ebp@1
  TFile2IDTable *v5; // esi@1
  PSRefBufferCharData<char> *v6; // ST04_4@1
  PSRefBufferCharData<char> *v7; // ST04_4@2
  char v8; // al@2
  char *v9; // esi@2
  bool v10; // bl@2
  bool result; // al@8
  PStringBase<char> *v12; // ebx@9
  PSRefBufferCharData<char> *v13; // eax@9
  int v14; // esi@10
  volatile LONG *v15; // ST0C_4@13
  char *v16; // esi@14
  TFileEntry *pEntry; // [sp+18h] [bp-8h]@1
  TFileEntry *pFileEntry; // [sp+1Ch] [bp-4h]@2

  v4 = &_FileName.m_charbuffer[-2].m_data[12];
  v5 = this;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  PSUtils::strip_directory(&_FileName);
  pEntry = 0;
  v6 = _FileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  if ( (unsigned __int8)((int (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, TFileEntry **, signed int))v5->vfptr[2].GetFullPathByFileName)(
                          v5,
                          v6,
                          &pEntry,
                          1) )
  {
    pFileEntry = 0;
    v7 = pEntry->m_pFileName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v7[-1]);
    ((void (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, TFileEntry **, signed int))v5->vfptr[2].GetFullPathByFileName)(
      v5,
      v7,
      &pFileEntry,
      1);
    v8 = (int)v5->vfptr[2].GetHighestDID(
                (TReadOnlyFile2IDTable *)v5,
                (IDClass<_tagDataID,32,0> *)pEntry,
                (unsigned int)_FullPath);
    v9 = &_FileName.m_charbuffer[-2].m_data[12];
    v10 = v8;
    if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    }
    result = v10;
  }
  else
  {
    v12 = _FullPath;
    v13 = _FullPath->m_charbuffer;
    if ( _FullPath->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v14 = (int)&v13[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v13[-1]) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      v15 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      v12->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v15);
    }
    v16 = &_FileName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    result = 0;
  }
  return result;
}

//----- (00678960) --------------------------------------------------------  // acclient.c:655338
char __thiscall TFile2IDTable::GetFileWriteTimeByFileName(TFile2IDTable *this, PStringBase<char> FileName, unsigned int dbtype, int *FileWriteTime)
{
  TFile2IDTable *v4; // esi@1
  char *v5; // edi@1
  PSRefBufferCharData<char> *v6; // ST04_4@1
  PSRefBufferCharData<char> *v7; // ST04_4@2
  char result; // al@5
  TFileEntry *pEntry; // [sp+18h] [bp-4h]@1

  v4 = this;
  pEntry = 0;
  v5 = &FileName.m_charbuffer[-2].m_data[12];
  v6 = FileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
  if ( (unsigned __int8)((int (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, TFileEntry **, signed int))v4->vfptr[2].GetFullPathByFileName)(
                          v4,
                          v6,
                          &pEntry,
                          1) )
  {
    FileName.m_charbuffer = 0;
    v7 = pEntry->m_pFileName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v7[-1]);
    ((void (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, PStringBase<char> *, signed int))v4->vfptr[2].GetFullPathByFileName)(
      v4,
      v7,
      &FileName,
      1);
    LOBYTE(FileWriteTime) = ((int (__thiscall *)(TFile2IDTable *, TFileEntry *, int *))v4->vfptr[2].GetDBTypes)(
                              v4,
                              pEntry,
                              FileWriteTime);
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    result = (char)FileWriteTime;
  }
  else
  {
    *FileWriteTime = (unsigned __int64)-1.0;
    if ( !InterlockedDecrement((volatile LONG *)v5 + 1) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    result = 0;
  }
  return result;
}

//----- (00678A30) --------------------------------------------------------  // acclient.c:655388
PStringBase<char> *__thiscall TFile2IDTable::GetDBTypeString(TFile2IDTable *this, PStringBase<char> *result, unsigned int _dbtype)
{
  int v3; // eax@1
  PSRefBufferCharData<char> *v4; // eax@2
  PStringBase<char> *v5; // eax@2
  volatile LONG *v6; // ST00_4@3

  v3 = ((int (__stdcall *)(unsigned int))this->vfptr[2].GetDIDs)(_dbtype);
  if ( v3 )
  {
    v4 = *(PSRefBufferCharData<char> **)(v3 + 12);
    result->m_charbuffer = v4;
    InterlockedIncrement((volatile LONG *)&v4[-1]);
    v5 = result;
  }
  else
  {
    v6 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v6);
    v5 = result;
  }
  return v5;
}

//----- (00678A80) --------------------------------------------------------  // acclient.c:655414
char __stdcall TFile2IDTable::SanitizeEntry(PStringBase<char> *i_strFullPath, TFileEntry **io_pEntry)
{
  char v3; // bl@1
  const char **v4; // esi@1
  TFileEntry **v5; // esi@3
  PStringBase<char> *v6; // esi@3
  char *v7; // esi@6
  PStringBase<char> strCheck; // [sp+10h] [bp-4h]@1

  strCheck.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v3 = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v4 = (const char **)i_strFullPath;
  if ( PSUtils::GetLongPathNameA((unsigned int)i_strFullPath, i_strFullPath, &strCheck) )
  {
    PSUtils::cleanup_filename(&strCheck, 1);
    if ( strcmp(strCheck.m_charbuffer->m_data, *v4) )
    {
      i_strFullPath = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PSUtils::get_directory((PStringBase<char> *)&i_strFullPath, &strCheck);
      PSUtils::strip_directory(&strCheck);
      v5 = io_pEntry;
      TFileEntry::SetPath(*io_pEntry, (PStringBase<char> *)&i_strFullPath);
      TFileEntry::SetFileName(*v5, &strCheck);
      v6 = i_strFullPath - 5;
      v3 = 1;
      if ( !InterlockedDecrement((volatile LONG *)&i_strFullPath[-4]) )
      {
        if ( v6 )
          (*(void (__thiscall **)(_DWORD, _DWORD))&v6->m_charbuffer->m_data[0])(v6, 1);
      }
    }
  }
  v7 = &strCheck.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strCheck.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return v3;
}

//----- (00678B90) --------------------------------------------------------  // acclient.c:655455
bool __stdcall TFile2IDTable::ReformatDirectoryName(PStringBase<char> _DirPath, char *_Result)
{
  bool v3; // bl@1
  char *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@1
  char v6; // cl@2
  char v7; // cl@12

  v3 = 0;
  v4 = _Result;
  v5 = _DirPath.m_charbuffer;
  if ( !_DirPath.m_charbuffer->m_data[0] )
    goto LABEL_16;
  do
  {
    v6 = v5->m_data[0];
    if ( v5->m_data[0] == 58 )
      v3 = v3 == 0;
    if ( v5 != _DirPath.m_charbuffer )
    {
      if ( v6 != 47 )
        goto LABEL_10;
      if ( v5->m_data[1] == 47 )
        goto LABEL_12;
    }
    if ( v6 != 47 )
    {
LABEL_10:
      *v4 = v6;
      goto LABEL_11;
    }
    if ( v5->m_data[1] == 47 )
      goto LABEL_12;
    *v4 = 92;
LABEL_11:
    ++v4;
LABEL_12:
    v7 = v5->m_data[1];
    v5 = (PSRefBufferCharData<char> *)((char *)v5 + 1);
  }
  while ( v7 );
  if ( v4 > _Result && *(v4 - 1) == 92 )
    --v4;
LABEL_16:
  *v4 = 0;
  if ( !InterlockedDecrement((volatile LONG *)&_DirPath.m_charbuffer[-1])
    && _DirPath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&_DirPath.m_charbuffer[-2].m_data[12])(
      &_DirPath.m_charbuffer[-2].m_data[12],
      1);
  return v3;
}

//----- (00678C20) --------------------------------------------------------  // acclient.c:655509
char __thiscall TFile2IDTable::AssignSoonToExistFilePath(TFile2IDTable *this, PStringBase<char> FileName)
{
  TFile2IDTable *v2; // edi@1
  char v3; // bl@1
  PSRefBufferCharData<char> *v4; // ecx@1
  PSRefBufferCharData<char> *v5; // ST04_4@2
  char *v6; // esi@4
  int v7; // edx@6
  char *v8; // esi@7
  int v9; // edx@9
  char *v10; // esi@10
  int v11; // edx@12
  PStringBase<char> v13; // [sp-4h] [bp-120h]@1
  signed int v14; // [sp+0h] [bp-11Ch]@2
  PStringBase<char> NamePart; // [sp+10h] [bp-10Ch]@1
  PStringBase<char> PathPart; // [sp+14h] [bp-108h]@1
  char WorkingBuffer[260]; // [sp+18h] [bp-104h]@1

  NamePart.m_charbuffer = FileName.m_charbuffer;
  v2 = this;
  v3 = 0;
  InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
  PathPart.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PSUtils::strip_directory(&NamePart);
  PSUtils::get_directory(&PathPart, &FileName);
  v13.m_charbuffer = PathPart.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PathPart.m_charbuffer[-1]);
  if ( TFile2IDTable::ReformatDirectoryName(v13, WorkingBuffer) )
  {
    v14 = (unsigned __int64)-1.0;
    v13.m_charbuffer = v4;
    PStringBase<char>::PStringBase<char>(&v13, WorkingBuffer);
    v5 = NamePart.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&NamePart.m_charbuffer[-1]);
    if ( (unsigned __int8)((int (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, PStringBase<char>, signed int))v2->vfptr[2].GetFullPathByDID)(
                            v2,
                            v5,
                            v13.m_charbuffer,
                            v14) )
      v3 = 1;
  }
  v6 = &PathPart.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PathPart.m_charbuffer[-1]) && v6 )
  {
    v7 = *(_DWORD *)v6;
    v14 = 1;
    (*(void (__thiscall **)(char *, signed int))v7)(v6, 1);
  }
  v8 = &NamePart.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NamePart.m_charbuffer[-1]) && v8 )
  {
    v9 = *(_DWORD *)v8;
    v14 = 1;
    (*(void (__thiscall **)(char *, signed int))v9)(v8, 1);
  }
  v10 = &FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName.m_charbuffer[-1]) && v10 )
  {
    v11 = *(_DWORD *)v10;
    v14 = 1;
    (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
  }
  return v3;
}

//----- (00678D40) --------------------------------------------------------  // acclient.c:655576
char __thiscall TFile2IDTable::RegisterDBType(TFile2IDTable *this, unsigned int _dbtype, PStringBase<char> _DBTypeString, PStringBase<char> _RootEngPath, PStringBase<char> _RootGamePath)
{
  TFile2IDTable *v5; // edi@1
  int v6; // esi@1
  char result; // al@11
  PSRefBufferCharData<char> *v8; // eax@12
  int v9; // ebx@13
  char *v10; // ebx@17
  TFileEntry **v11; // ecx@17
  TReadOnlyFile2IDTableVtbl *v12; // ebx@18
  PSRefBufferCharData<char> *v13; // ebx@18
  int v14; // ebx@18
  int v15; // edx@20
  TReadOnlyFile2IDTableVtbl *v16; // ebx@23
  PSRefBufferCharData<char> *v17; // edi@23
  int v18; // eax@25
  char *v19; // esi@27
  int v20; // edx@29
  char *v21; // esi@30
  int v22; // edx@32
  int v23; // edx@35
  TFileEntry **v24; // [sp+8h] [bp-12Ch]@18
  void *v25; // [sp+Ch] [bp-128h]@18
  signed int v26; // [sp+10h] [bp-124h]@17
  TFileEntry *pFileEntry; // [sp+24h] [bp-110h]@18
  char *v28; // [sp+28h] [bp-10Ch]@17
  unsigned __int16 rhs[2]; // [sp+2Ch] [bp-108h]@18
  char WorkingBuffer[260]; // [sp+30h] [bp-104h]@17

  v5 = this;
  v6 = ((int (__stdcall *)(unsigned int))this->vfptr[2].GetDIDs)(_dbtype);
  if ( *(_BYTE *)(v6 + 1) )
  {
    if ( !InterlockedDecrement((volatile LONG *)&_DBTypeString.m_charbuffer[-1])
      && _DBTypeString.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&_DBTypeString.m_charbuffer[-2].m_data[12])(
        &_DBTypeString.m_charbuffer[-2].m_data[12],
        1);
    if ( !InterlockedDecrement((volatile LONG *)&_RootEngPath.m_charbuffer[-1])
      && _RootEngPath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&_RootEngPath.m_charbuffer[-2].m_data[12])(
        &_RootEngPath.m_charbuffer[-2].m_data[12],
        1);
    if ( !InterlockedDecrement((volatile LONG *)&_RootGamePath.m_charbuffer[-1])
      && _RootGamePath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&_RootGamePath.m_charbuffer[-2].m_data[12])(
        &_RootGamePath.m_charbuffer[-2].m_data[12],
        1);
    result = 0;
  }
  else
  {
    v8 = *(PSRefBufferCharData<char> **)(v6 + 12);
    if ( v8 != _DBTypeString.m_charbuffer )
    {
      v9 = (int)&v8[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      *(_DWORD *)(v6 + 12) = _DBTypeString.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&_DBTypeString.m_charbuffer[-1]);
    }
    v26 = (signed int)WorkingBuffer;
    v10 = &_RootGamePath.m_charbuffer[-2].m_data[12];
    *(_BYTE *)(v6 + 1) = 1;
    *(_BYTE *)v6 = 0;
    v28 = &_RootGamePath.m_charbuffer[-2].m_data[12];
    InterlockedIncrement((volatile LONG *)&_RootGamePath.m_charbuffer[-1]);
    if ( TFile2IDTable::ReformatDirectoryName(_RootGamePath, (char *)v26) )
    {
      v12 = v5->vfptr;
      v26 = 2;
      v25 = &pFileEntry;
      v24 = v11;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v24, WorkingBuffer);
      ((void (__thiscall *)(TFile2IDTable *, TFileEntry **, void *, signed int))v12[2].GetFullPathByFileName)(
        v5,
        v24,
        v25,
        v26);
      *(_BYTE *)v6 = pFileEntry->m_EntryType == 3;
      v13 = pFileEntry->m_pPath.m_charbuffer;
      *(_DWORD *)rhs = v13;
      v14 = (int)&v13[-2].m_data[12];
      InterlockedIncrement((volatile LONG *)(v14 + 4));
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v6 + 4), rhs);
      if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
      {
        v15 = *(_DWORD *)v14;
        v26 = 1;
        (*(void (__thiscall **)(int, signed int))v15)(v14, 1);
      }
      v10 = v28;
    }
    v26 = (signed int)WorkingBuffer;
    v25 = _RootEngPath.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&_RootEngPath.m_charbuffer[-1]);
    if ( TFile2IDTable::ReformatDirectoryName((PStringBase<char>)v25, (char *)v26) )
    {
      v16 = v5->vfptr;
      v26 = 2;
      v25 = &pFileEntry;
      v24 = &pFileEntry;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v24, WorkingBuffer);
      ((void (__thiscall *)(TFile2IDTable *, TFileEntry **, void *, signed int))v16[2].GetFullPathByFileName)(
        v5,
        v24,
        v25,
        v26);
      *(_BYTE *)v6 &= pFileEntry->m_EntryType == 3;
      v17 = pFileEntry->m_pPath.m_charbuffer;
      *(_DWORD *)rhs = v17;
      InterlockedIncrement((volatile LONG *)&v17[-1]);
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v6 + 8), rhs);
      if ( !InterlockedDecrement((volatile LONG *)&v17[-1]) && v17 != (PSRefBufferCharData<char> *)20 )
      {
        v18 = *(_DWORD *)&v17[-2].m_data[12];
        v26 = 1;
        (*(void (__thiscall **)(char *, signed int))v18)(&v17[-2].m_data[12], 1);
      }
      v10 = v28;
    }
    v19 = &_DBTypeString.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_DBTypeString.m_charbuffer[-1])
      && _DBTypeString.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    {
      v20 = *(_DWORD *)v19;
      v26 = 1;
      (*(void (__thiscall **)(char *, signed int))v20)(v19, 1);
    }
    v21 = &_RootEngPath.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_RootEngPath.m_charbuffer[-1])
      && _RootEngPath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    {
      v22 = *(_DWORD *)v21;
      v26 = 1;
      (*(void (__thiscall **)(char *, signed int))v22)(v21, 1);
    }
    if ( !InterlockedDecrement((volatile LONG *)v10 + 1) && v10 )
    {
      v23 = *(_DWORD *)v10;
      v26 = 1;
      (*(void (__thiscall **)(char *, signed int))v23)(v10, 1);
    }
    result = 1;
  }
  return result;
}

//----- (00679010) --------------------------------------------------------  // acclient.c:655764
char __stdcall TFile2IDTable::GetFullPathByEntry(TFileEntry *pEntry, PStringBase<char> *_FullPath)
{
  PSRefBufferCharData<char> *v3; // esi@1
  PStringBase<char> *v4; // ebp@1
  PSRefBufferCharData<char> *v5; // eax@1
  int v6; // ebx@2
  int v7; // esi@6
  PStringBase<char> *v8; // esi@10
  PSRefBufferCharData<char> *v9; // eax@10
  int v10; // esi@12
  PSRefBufferCharData<char> *v11; // esi@15
  int v12; // eax@15
  int v13; // esi@17

  v3 = pEntry->m_pPath.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1]);
  v4 = _FullPath;
  v5 = _FullPath->m_charbuffer;
  if ( _FullPath->m_charbuffer != v3 )
  {
    v6 = (int)&v5[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v5[-1]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v4->m_charbuffer = v3;
    InterlockedIncrement((volatile LONG *)&v3[-1]);
  }
  v7 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  if ( *(_DWORD *)&v4->m_charbuffer[-1].m_data[12] != 1 )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_FullPath, "\\");
    v8 = _FullPath;
    v9 = _FullPath[-1].m_charbuffer;
    if ( v9 != (PSRefBufferCharData<char> *)1 )
    {
      PStringBase<char>::append_n_chars(v4, (const char *)_FullPath, (unsigned int)&v9[-1].m_data[15]);
      v8 = _FullPath;
    }
    v10 = (int)&v8[-5];
    if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  }
  v11 = pEntry->m_pFileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v11[-1]);
  v12 = *(_DWORD *)&v11[-1].m_data[12];
  if ( v12 != 1 )
    PStringBase<char>::append_n_chars(v4, v11->m_data, v12 - 1);
  v13 = (int)&v11[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
  return 1;
}

//----- (00679110) --------------------------------------------------------  // acclient.c:655819
bool __thiscall TFile2IDTable::IsDBTypeRegistered(TFile2IDTable *this, unsigned int dbtype)
{
  HashTableData<unsigned long,TDBTypeEntry *> *v2; // eax@1
  bool result; // al@4
  TDBTypeEntry *v4; // eax@6

  v2 = this->m_CacheByDID.m_intrusiveTable.m_buckets[dbtype % this->m_CacheByDID.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != dbtype )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 && (v4 = v2->m_data) != 0 )
    result = v4->bRegistered;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (00679160) --------------------------------------------------------  // acclient.c:655843
bool __thiscall TFile2IDTable::IsDBDirSearched(TFile2IDTable *this, unsigned int dbtype)
{
  HashTableData<unsigned long,TDBTypeEntry *> *v2; // eax@1
  bool result; // al@4
  TDBTypeEntry *v4; // eax@6

  v2 = this->m_CacheByDID.m_intrusiveTable.m_buckets[dbtype % this->m_CacheByDID.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != dbtype )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 && (v4 = v2->m_data) != 0 )
    result = v4->bRecursed;
  else
LABEL_4:
    result = 0;
  return result;
}

//----- (006791B0) --------------------------------------------------------  // acclient.c:655867
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::grow(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00679200) --------------------------------------------------------  // acclient.c:655887
void __thiscall TDBTypeEntry::~TDBTypeEntry(TDBTypeEntry *this)
{
  TDBTypeEntry *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  int v4; // esi@3
  int v5; // esi@6
  int v6; // esi@9

  v1 = this;
  v2 = (char *)&this->DIDs.m_intrusiveTable;
  this->DIDs.vfptr = (HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>Vtbl *)AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->DIDs.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v4 = (int)&v1->TypeName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = (int)&v1->pRootEngPath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = (int)&v1->pRootGamePath.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
  {
    if ( v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  }
}
// 7FE138: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable[7])(void *, char);
// 7FE148: using guessed type int (__thiscall *AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable[3])(void *, char);

//----- (006792A0) --------------------------------------------------------  // acclient.c:655925
char __thiscall TFile2IDTable::FindEntryByDID(TFile2IDTable *this, IDClass<_tagDataID,32,0> _did, unsigned int _dbtype, TFileEntry **_pEntry)
{
  int v4; // eax@1
  int v5; // eax@1
  char result; // al@4

  v4 = ((int (__stdcall *)(unsigned int))this->vfptr[2].GetDIDs)(_dbtype);
  v5 = *(_DWORD *)(*(_DWORD *)(v4 + 120) + 4 * (_did.id % *(_DWORD *)(v4 + 128)));
  if ( !v5 )
    goto LABEL_4;
  while ( *(_DWORD *)v5 != _did.id )
  {
    v5 = *(_DWORD *)(v5 + 4);
    if ( !v5 )
      goto LABEL_4;
  }
  if ( v5 )
  {
    *_pEntry = *(TFileEntry **)(v5 + 8);
    result = 1;
  }
  else
  {
LABEL_4:
    result = 0;
  }
  return result;
}

//----- (006792F0) --------------------------------------------------------  // acclient.c:655955
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::grow(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00679340) --------------------------------------------------------  // acclient.c:655975
void __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>Vtbl *)IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE138: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable[7])(void *, char);

//----- (006793D0) --------------------------------------------------------  // acclient.c:656008
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE13C: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable[6])(void *, char);

//----- (00679460) --------------------------------------------------------  // acclient.c:656041
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::add_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *this, HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *v2; // esi@1
  unsigned int v3; // ebx@3
  unsigned int v4; // edx@3
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v5; // eax@3
  int v6; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::grow(this);
  v3 = v2->m_numBuckets;
  v4 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&data->m_hashKey) % v3;
  v5 = v2->m_buckets;
  data->m_hashNext = v5[v4];
  v5[v4] = data;
  v6 = (int)&v5[v4];
  if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v6 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v6;
  ++v2->m_numElements;
}

//----- (006794B0) --------------------------------------------------------  // acclient.c:656064
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,TDBTypeEntry *> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,TDBTypeEntry *> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FE140: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable[5])(void *, char);

//----- (00679540) --------------------------------------------------------  // acclient.c:656097
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::grow(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::resize_internal(v2, *v3);
}

//----- (00679590) --------------------------------------------------------  // acclient.c:656115
char __thiscall TFile2IDTable::GetDBTypes(TFile2IDTable *this, SmartArray<unsigned long,1> *_A)
{
  SmartArray<unsigned long,1> *v2; // eax@1
  unsigned int v3; // ecx@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v4; // eax@3
  HashTableData<unsigned long,HeritageGroup_CG> *v5; // edi@3
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebp@3
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // ebx@3
  SmartArray<unsigned long,1> *v8; // ecx@4
  unsigned int v9; // eax@4
  unsigned int v10; // edx@5
  int v11; // ST18_4@10
  TFile2IDTable *v18; // [sp+0h] [bp-14h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+8h] [bp-Ch]@3

  v2 = _A;
  v18 = this;
  v3 = 0;
  if ( _A->m_num )
  {
    do
    {
      v2->m_data[v3] = 0;
      v2 = _A;
      ++v3;
    }
    while ( v3 < _A->m_num );
  }
  v2->m_num = 0;
  v4 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v18->m_CacheByDID.m_intrusiveTable,
         &result);
  v5 = v4->m_currElement;
  v6 = v4->m_currHashTable;
  v7 = v4->m_currBucket;
  if ( !v5 )
    return 1;
  do
  {
LABEL_4:
    v8 = _A;
    v9 = _A->m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( _A->m_num < v9 )
      goto LABEL_14;
    v10 = v9 + 1;
    if ( v9 + 1 > 8 )
    {
      if ( v10 <= 0x4000 )
      {
        v11 = v9 + 1;
        __asm { bsr     this, [esp+24h+var_10] }
        v8 = _A;
        if ( v10 > 1 << _EAX )
          v10 = 2 * (1 << _EAX);
      }
      else if ( v10 & 0x3FFF )
      {
        v10 += 0x4000 - (v10 & 0x3FFF);
      }
    }
    else
    {
      v10 = 8;
    }
    if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v8, v10) )
    {
      v8 = _A;
LABEL_14:
      v8->m_data[v8->m_num] = v5->m_hashKey;
      ++_A->m_num;
    }
    v5 = v5->m_hashNext;
  }
  while ( v5 );
  while ( 1 )
  {
    ++v7;
    if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
      return 1;
    if ( *v7 )
    {
      v5 = *v7;
      if ( *v7 )
        goto LABEL_4;
      return 1;
    }
  }
}

//----- (006796B0) --------------------------------------------------------  // acclient.c:656205
char __thiscall TFile2IDTable::GetDIDs(TFile2IDTable *this, SmartArray<IDClass<_tagDataID,32,0>,1> *_A, unsigned int _dbtype)
{
  SmartArray<IDClass<_tagDataID,32,0>,1> *v3; // ecx@1
  unsigned int v4; // eax@1
  HashTableData<unsigned long,TDBTypeEntry *> *v5; // edx@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@8
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@8
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v9; // ebp@8
  HashTableData<unsigned long,HeritageGroup_CG> **v10; // ebx@8
  SmartArray<IDClass<_tagDataID,32,0>,1> *v11; // ecx@9
  unsigned int v12; // eax@9
  unsigned int v13; // edx@10
  int v14; // ST18_4@15
  TFile2IDTable *v20; // [sp+4h] [bp-14h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+Ch] [bp-Ch]@8

  v20 = this;
  v3 = _A;
  v4 = 0;
  if ( _A->m_num )
  {
    do
    {
      v3->m_data[v4].id = (unsigned int)_A;
      v3 = _A;
      ++v4;
    }
    while ( v4 < _A->m_num );
  }
  v3->m_num = 0;
  v5 = v20->m_CacheByDID.m_intrusiveTable.m_buckets[_dbtype % v20->m_CacheByDID.m_intrusiveTable.m_numBuckets];
  if ( !v5 )
    return 0;
  while ( v5->m_hashKey != _dbtype )
  {
    v5 = v5->m_hashNext;
    if ( !v5 )
      return 0;
  }
  if ( !v5 )
    return 0;
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v5->m_data->DIDs.m_intrusiveTable,
         &result);
  v8 = v7->m_currElement;
  v9 = v7->m_currHashTable;
  v10 = v7->m_currBucket;
  if ( !v8 )
    return 1;
  do
  {
LABEL_9:
    v11 = _A;
    v12 = _A->m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( _A->m_num < v12 )
      goto LABEL_19;
    v13 = v12 + 1;
    if ( v12 + 1 > 8 )
    {
      if ( v13 <= 0x4000 )
      {
        v14 = v12 + 1;
        __asm { bsr     this, [esp+24h+var_10] }
        v11 = _A;
        if ( v13 > 1 << _EAX )
          v13 = 2 * (1 << _EAX);
      }
      else if ( v13 & 0x3FFF )
      {
        v13 += 0x4000 - (v13 & 0x3FFF);
      }
    }
    else
    {
      v13 = 8;
    }
    if ( SmartArray<IDClass<_tagDataID,32,0>,1>::grow(v11, v13) )
    {
      v11 = _A;
LABEL_19:
      v11->m_data[v11->m_num].id = v8->m_hashKey;
      ++_A->m_num;
    }
    v8 = v8->m_hashNext;
  }
  while ( v8 );
  while ( 1 )
  {
    ++v10;
    if ( v10 == &v9->m_buckets[v9->m_numBuckets] )
      return 1;
    if ( *v10 )
    {
      v8 = *v10;
      if ( *v10 )
        goto LABEL_9;
      return 1;
    }
  }
}

//----- (00679800) --------------------------------------------------------  // acclient.c:656307
char __thiscall TFile2IDTable::GetFilePaths(TFile2IDTable *this, SmartArray<PStringBase<char>,1> *_aFilePaths)
{
  TFile2IDTable *v2; // esi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v4; // ecx@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v5; // eax@1
  TFileEntry *v6; // esi@2
  PSRefBufferCharData<char> *v7; // ebx@3
  PSRefBufferCharData<char> *v8; // edi@3
  PStringBase<char> *v9; // eax@3
  PStringBase<char> *v10; // eax@3
  char *v11; // esi@3
  char *v12; // esi@6
  int v13; // edi@9
  int v14; // ebx@12
  char *v15; // esi@15
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v16; // eax@20
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v17; // edx@22
  PStringBase<char> rhs; // [sp+10h] [bp-2Ch]@3
  PStringBase<char> v20; // [sp+14h] [bp-28h]@3
  PStringBase<char> v21; // [sp+18h] [bp-24h]@3
  PStringBase<char> v22; // [sp+1Ch] [bp-20h]@3
  PStringBase<char> v23; // [sp+20h] [bp-1Ch]@3
  HashIterator<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> cur; // [sp+24h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+30h] [bp-Ch]@1

  v2 = this;
  SmartArray<PStringBase<char>,1>::SetNElements(_aFilePaths, 0, 1);
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_CacheByFileName.m_intrusiveTable,
         &result);
  cur.m_iter.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *)v3->m_currHashTable;
  v4 = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v3->m_currBucket;
  v5 = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *)v3->m_currElement;
  cur.m_iter.m_currBucket = v4;
  cur.m_iter.m_currElement = v5;
  if ( v5 )
  {
    do
    {
LABEL_2:
      v6 = cur.m_iter.m_currElement->m_data;
      if ( v6 )
      {
        PStringBase<char>::PStringBase<char>(&rhs, "\\");
        v20.m_charbuffer = v6->m_pFileName.m_charbuffer;
        v7 = v20.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v20.m_charbuffer[-1]);
        v21.m_charbuffer = v6->m_pPath.m_charbuffer;
        v8 = v21.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v21.m_charbuffer[-1]);
        v9 = PStringBase<char>::operator+(&v21, &v23, &rhs);
        v10 = PStringBase<char>::operator+(v9, &v22, &v20);
        SmartArray<PStringBase<char>,1>::AddToEnd(_aFilePaths, v10);
        v11 = &v22.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v22.m_charbuffer[-1]) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
        v12 = &v23.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v23.m_charbuffer[-1]) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        v13 = (int)&v8[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        v14 = (int)&v7[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
        v15 = &rhs.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v15 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
        v4 = cur.m_iter.m_currBucket;
      }
      cur.m_iter.m_currElement = cur.m_iter.m_currElement->m_hashNext;
    }
    while ( cur.m_iter.m_currElement );
    v16 = &cur.m_iter.m_currHashTable->m_buckets[cur.m_iter.m_currHashTable->m_numBuckets];
    while ( 1 )
    {
      ++v4;
      cur.m_iter.m_currBucket = v4;
      if ( v4 == v16 )
        break;
      v17 = *v4;
      if ( *v4 )
      {
        cur.m_iter.m_currElement = *v4;
        if ( v17 )
          goto LABEL_2;
        return 1;
      }
    }
  }
  return 1;
}

//----- (00679990) --------------------------------------------------------  // acclient.c:656402
char __thiscall TFile2IDTable::RemoveFilenameFromCache(TFile2IDTable *this, PStringBase<char> *i_strFilename)
{
  TFile2IDTable *v2; // esi@1
  PSRefBufferCharData<char> *v3; // ebx@1
  bool (__thiscall *v4)(ClientCommunicationSystem *, int, char **); // ebp@1
  char v5; // bl@10
  char *v6; // esi@11
  PStringBase<char> NamePart; // [sp+14h] [bp-10h]@1
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+18h] [bp-Ch]@1

  NamePart.m_charbuffer = i_strFilename->m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&NamePart.m_charbuffer[-1]);
  PSUtils::strip_directory(&NamePart);
  v3 = NamePart.m_charbuffer;
  v4 = 0;
  i_strFilename = (PStringBase<char> *)NamePart.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&NamePart.m_charbuffer[-1]);
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v2->m_CacheByFileName.m_intrusiveTable,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)&i_strFilename);
  if ( result.m_currElement )
  {
    v4 = result.m_currElement->func;
    LOBYTE(i_strFilename) = 1;
  }
  else
  {
    LOBYTE(i_strFilename) = 0;
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v3 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v3[-2].m_data[12])(&v3[-2].m_data[12], 1);
  if ( (_BYTE)i_strFilename )
  {
    if ( !v4 )
    {
      v5 = 0;
      goto LABEL_11;
    }
    TFileEntry::SetPath((TFileEntry *)v4, &PStringBase<char>::null_string);
    *((_BYTE *)v4 + 28) = 0;
  }
  v5 = 1;
LABEL_11:
  v6 = &NamePart.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NamePart.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return v5;
}

//----- (00679A70) --------------------------------------------------------  // acclient.c:656454
char __thiscall TFile2IDTable::RemoveDirectoryFromCache(TFile2IDTable *this, PStringBase<char> *i_strDirectory)
{
  PSRefBufferCharData<char> *v2; // edi@1
  TFile2IDTable *v3; // esi@1
  TFileEntry *v4; // ebp@1
  volatile LONG *v5; // ST04_4@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v6; // esi@1
  char v7; // bl@2
  int v8; // edi@4
  FileEntryType v9; // eax@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v10; // eax@12
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v11; // ebp@12
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v12; // ecx@12
  TFileEntry *v13; // edi@13
  const char *v14; // esi@15
  char *v15; // eax@15
  int v16; // eax@16
  bool v17; // bl@18
  int v18; // esi@18
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v19; // eax@25
  TFileEntry *pExistingEntry; // [sp+10h] [bp-20h]@1
  CaseInsensitiveStringBase<PStringBase<char> > _key; // [sp+14h] [bp-1Ch]@1
  HashIterator<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> iter; // [sp+18h] [bp-18h]@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+24h] [bp-Ch]@12

  v2 = i_strDirectory->m_charbuffer;
  v3 = this;
  v4 = 0;
  v5 = (volatile LONG *)&i_strDirectory->m_charbuffer[-1];
  pExistingEntry = 0;
  _key.m_charbuffer = i_strDirectory->m_charbuffer;
  InterlockedIncrement(v5);
  v6 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v3->m_CacheByFileName.m_intrusiveTable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v6,
    (IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&iter,
    &_key);
  if ( iter.m_iter.m_currElement )
  {
    pExistingEntry = iter.m_iter.m_currElement->m_data;
    v7 = 1;
    v4 = iter.m_iter.m_currElement->m_data;
  }
  else
  {
    v7 = 0;
  }
  v8 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  if ( v7 && v4 )
  {
    v9 = v4->m_EntryType;
    if ( v9 == 3 || v9 == 2 )
      v4->m_EntryType = 2;
    v10 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
            (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v6,
            &result);
    v11 = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *)v10->m_currElement;
    v12 = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v10->m_currBucket;
    iter.m_iter.m_currHashTable = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *)v10->m_currHashTable;
    iter.m_iter.m_currBucket = v12;
    if ( v11 )
    {
      do
      {
LABEL_13:
        v13 = v11->m_data;
        if ( v13 && v13 != pExistingEntry )
        {
          v14 = v13->m_pPath.m_charbuffer->m_data;
          InterlockedIncrement((volatile LONG *)v14 - 4);
          v15 = _strstr(v14, i_strDirectory->m_charbuffer->m_data);
          if ( v15 )
            v16 = v15 - v14;
          else
            v16 = -1;
          v17 = v16 == 0;
          v18 = (int)(v14 - 20);
          if ( !InterlockedDecrement((volatile LONG *)(v18 + 4)) && v18 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
          if ( v17 )
          {
            TFileEntry::SetPath(v13, &PStringBase<char>::null_string);
            v13->m_bAuthoritative = 0;
          }
          v12 = iter.m_iter.m_currBucket;
        }
        v11 = v11->m_hashNext;
      }
      while ( v11 );
      v19 = &iter.m_iter.m_currHashTable->m_buckets[iter.m_iter.m_currHashTable->m_numBuckets];
      while ( 1 )
      {
        ++v12;
        iter.m_iter.m_currBucket = v12;
        if ( v12 == v19 )
          break;
        if ( *v12 )
        {
          v11 = *v12;
          if ( *v12 )
            goto LABEL_13;
          return 1;
        }
      }
    }
  }
  return 1;
}

//----- (00679BD0) --------------------------------------------------------  // acclient.c:656566
char __thiscall HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>::grow(HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+0h] [bp-4h]@1

  __val = (unsigned int)this;
  v1 = g_bucketSizesEnd;
  v2 = &this->m_intrusiveTable;
  __val = this->m_intrusiveTable.m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (00679C20) --------------------------------------------------------  // acclient.c:656586
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::add(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *this, HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *data)
{
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey.id % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey.id != data->m_hashKey.id )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::grow(this);
    v5 = data->m_hashKey.id % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00679CA0) --------------------------------------------------------  // acclient.c:656630
char __thiscall IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::resize_internal(IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v9; // ebx@7
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v10; // ecx@7
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v11; // eax@9
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v12; // edx@10
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v5->m_hashKey.id % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00679DE0) --------------------------------------------------------  // acclient.c:656748
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::resize_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v9; // ebx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v10; // ecx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v11; // eax@9
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v12; // edx@10
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  unsigned int v16; // ebx@23
  unsigned int v17; // edx@23
  HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **v18; // eax@23
  int v19; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::resize_internal(
            v3,
            *v15);
        }
        v16 = v3->m_numBuckets;
        v17 = CaseInsensitiveStringBase<PStringBase<char>>::case_insensitive_hash(&v5->m_hashKey) % v16;
        v18 = v3->m_buckets;
        v5->m_hashNext = v18[v17];
        v18[v17] = v5;
        v19 = (int)&v18[v17];
        if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v19 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> **)v19;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (00679F20) --------------------------------------------------------  // acclient.c:656868
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::resize_internal(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *this, unsigned int _numBuckets)
{
  unsigned int v2; // ebp@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *v3; // esi@1
  char result; // al@2
  HashTableData<unsigned long,TDBTypeEntry *> *v5; // edi@3
  int v6; // ecx@4
  HashTableData<unsigned long,TDBTypeEntry *> **v7; // eax@5
  int v8; // eax@6
  HashTableData<unsigned long,TDBTypeEntry *> **v9; // ebx@7
  HashTableData<unsigned long,TDBTypeEntry *> *v10; // ecx@7
  HashTableData<unsigned long,TDBTypeEntry *> *v11; // eax@9
  HashTableData<unsigned long,TDBTypeEntry *> *v12; // edx@10
  HashTableData<unsigned long,TDBTypeEntry *> *v13; // ebp@18
  unsigned int *v14; // ebx@19
  unsigned int *v15; // eax@19
  int v16; // edx@23
  HashTableData<unsigned long,TDBTypeEntry *> **v17; // eax@23
  int v18; // eax@23

  v2 = _numBuckets;
  v3 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v5 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v6 = (int)&v3->m_buckets[v3->m_numBuckets];
        if ( v3->m_firstInterestingBucket == (HashTableData<unsigned long,TDBTypeEntry *> **)v6 )
        {
LABEL_7:
          v9 = 0;
          v10 = 0;
        }
        else
        {
          while ( 1 )
          {
            v7 = v3->m_firstInterestingBucket;
            if ( *v7 )
              break;
            v8 = (int)(v7 + 1);
            v3->m_firstInterestingBucket = (HashTableData<unsigned long,TDBTypeEntry *> **)v8;
            if ( v8 == v6 )
              goto LABEL_7;
          }
          v10 = *v3->m_firstInterestingBucket;
          v9 = v3->m_firstInterestingBucket;
        }
        v11 = *v9;
        if ( *v9 == v10 )
          goto LABEL_29;
        do
        {
          v12 = v11;
          v11 = v11->m_hashNext;
        }
        while ( v11 != v10 );
        if ( v12 )
          v12->m_hashNext = v11->m_hashNext;
        else
LABEL_29:
          *v9 = v11->m_hashNext;
        --v3->m_numElements;
        v10->m_hashNext = v5;
        v5 = v10;
      }
      while ( v3->m_numElements );
    }
    if ( (HashTableData<unsigned long,TDBTypeEntry *> **)v3->m_buckets != v3->m_aInplaceBuckets )
      operator delete[](v3->m_buckets);
    v3->m_buckets = 0;
    v3->m_firstInterestingBucket = 0;
    v3->m_numBuckets = 0;
    v3->m_numElements = 0;
    IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::init(
      (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v3,
      v2);
    if ( v5 )
    {
      do
      {
        v13 = v5->m_hashNext;
        if ( (signed int)(2 * v3->m_numBuckets) < (signed int)(v3->m_numElements + 1) )
        {
          v14 = g_bucketSizesEnd;
          _numBuckets = v3->m_numBuckets;
          v15 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
          if ( v15 != v14 || (--v15, v15 != v14) )
            ++v15;
          IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::resize_internal(v3, *v15);
        }
        v16 = v5->m_hashKey % v3->m_numBuckets;
        v17 = v3->m_buckets;
        v5->m_hashNext = v17[v16];
        v17[v16] = v5;
        v18 = (int)&v17[v16];
        if ( (HashTableData<unsigned long,TDBTypeEntry *> **)v18 < v3->m_firstInterestingBucket )
          v3->m_firstInterestingBucket = (HashTableData<unsigned long,TDBTypeEntry *> **)v18;
        ++v3->m_numElements;
        v5 = v13;
      }
      while ( v13 );
    }
    result = 1;
  }
  return result;
}

//----- (0067A060) --------------------------------------------------------  // acclient.c:656984
AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *> *__thiscall AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor(AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *> *this, unsigned int a2)
{
  AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>Vtbl *)AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable;
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
// 7FE138: using guessed type int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable[7])(void *, char);
// 7FE148: using guessed type int (__thiscall *AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable[3])(void *, char);

//----- (0067A0C0) --------------------------------------------------------  // acclient.c:657010
char __thiscall HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>::add(HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1> *this, IDClass<_tagDataID,32,0> *_key, TFileEntry *const *_data)
{
  HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = _key->id;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (0067A120) --------------------------------------------------------  // acclient.c:657046
AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *__thiscall HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor(AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *this, unsigned int a2)
{
  AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1>Vtbl *)HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable;
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
// 7FE13C: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable[6])(void *, char);
// 7FE14C: using guessed type int (__thiscall *HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable[2])(void *, char);

//----- (0067A180) --------------------------------------------------------  // acclient.c:657072
char __thiscall HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::add(HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> *this, CaseInsensitiveStringBase<PStringBase<char> > *_key, TFileEntry *const *_data)
{
  HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> *v3; // edi@1
  void *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@2
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v6; // edi@4
  char v7; // al@5
  int v8; // edi@7
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    v5 = _key->m_charbuffer;
    *(_DWORD *)v4 = _key->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
  }
  else
  {
    v4 = 0;
  }
  v6 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v3->m_intrusiveTable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v6,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)v4);
  if ( result.m_currElement )
  {
    if ( v4 )
    {
      v8 = *(_DWORD *)v4 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      operator delete(v4);
    }
    v7 = 0;
  }
  else
  {
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::add_internal(
      (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1> *)v6,
      (HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *)v4);
    v7 = 1;
  }
  return v7;
}

//----- (0067A220) --------------------------------------------------------  // acclient.c:657126
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *this, HashTableData<unsigned long,TDBTypeEntry *> *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,TDBTypeEntry *> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,TDBTypeEntry *> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,TDBTypeEntry *> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,TDBTypeEntry *> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0067A2A0) --------------------------------------------------------  // acclient.c:657170
void __thiscall TDBTypeEntry::TDBTypeEntry(TDBTypeEntry *this)
{
  TDBTypeEntry *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->pRootGamePath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->pRootEngPath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->TypeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->DIDs.vfptr = (HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>Vtbl *)AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable;
  IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>(
    &v1->DIDs.m_intrusiveTable,
    0x800u);
  v1->DIDs.vfptr = (HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>Vtbl *)AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable;
}
// 7FE148: using guessed type int (__thiscall *AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable[3])(void *, char);

//----- (0067A300) --------------------------------------------------------  // acclient.c:657196
char __thiscall TFile2IDTable::AssignDIDToFileName(TFile2IDTable *this, PStringBase<char> _FileName, IDClass<_tagDataID,32,0> _did, unsigned int _dbtype)
{
  TFile2IDTable *v4; // esi@1
  char v5; // bl@1
  int v6; // eax@1
  unsigned int v7; // edi@1
  PSRefBufferCharData<char> *v8; // ST04_4@2
  char *v9; // esi@4
  char *v10; // esi@7
  unsigned int v12; // ebp@11
  int v13; // esi@11
  IDClass<_tagDataID,32,0> *v14; // ecx@16
  char *v15; // esi@19
  char *v16; // esi@22
  char *v17; // esi@26
  char *v18; // esi@29
  PStringBase<char> NamePart; // [sp+10h] [bp-4h]@2

  v4 = this;
  v5 = 0;
  v6 = MasterDBMap::DivineType(&_FileName);
  v7 = _dbtype;
  if ( v6 != _dbtype )
  {
LABEL_22:
    v16 = &_FileName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) && v16 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
    return v5;
  }
  NamePart.m_charbuffer = _FileName.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  PSUtils::strip_directory(&NamePart);
  _dbtype = 0;
  v8 = NamePart.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&NamePart.m_charbuffer[-1]);
  ((void (__thiscall *)(TFile2IDTable *, PSRefBufferCharData<char> *, unsigned int *, signed int))v4->vfptr[2].GetFullPathByFileName)(
    v4,
    v8,
    &_dbtype,
    4);
  if ( _dbtype )
  {
    if ( *(_DWORD *)(_dbtype + 16) != stru_8F7704.id )
    {
      v9 = &NamePart.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&NamePart.m_charbuffer[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      v10 = &_FileName.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) )
      {
        if ( v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      }
      return 1;
    }
    v12 = _did.id;
    *(_DWORD *)(_dbtype + 16) = _did.id;
    *(_DWORD *)(_dbtype + 20) = v7;
    *(_DWORD *)(_dbtype + 24) = 5;
    v13 = ((int (__thiscall *)(TFile2IDTable *, unsigned int))v4->vfptr[2].GetDIDs)(v4, v7);
    if ( !HashSet<unsigned long>::contains((HashTable<unsigned long,unsigned long,0> *)(v13 + 20), &_did.id) )
    {
      if ( 2 * *(_DWORD *)(v13 + 128) < *(_DWORD *)(v13 + 132) )
        HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>::grow((HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1> *)(v13 + 20));
      if ( HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1>::add(
             (HashTable<IDClass<_tagDataID,32,0>,TFileEntry *,1> *)(v13 + 20),
             &_did,
             (TFileEntry *const *)&_dbtype) )
        ++*(_DWORD *)(_dbtype + 4);
      v14 = (IDClass<_tagDataID,32,0> *)(v13 + 16);
      if ( v12 >= *(_DWORD *)(v13 + 16) )
        v14 = &_did;
      *(_DWORD *)(v13 + 16) = v14->id;
      v5 = 1;
    }
    v15 = &NamePart.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&NamePart.m_charbuffer[-1]) && v15 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
    goto LABEL_22;
  }
  v17 = &NamePart.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NamePart.m_charbuffer[-1]) && v17 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
  v18 = &_FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  return 0;
}

//----- (0067A4F0) --------------------------------------------------------  // acclient.c:657287
char __thiscall TFile2IDTable::AssignNonAuthoritativePathToFileName(TFile2IDTable *this, PStringBase<char> FileName, PStringBase<char> FilePath)
{
  TFile2IDTable *v3; // ebp@1
  int v4; // eax@1
  PStringBase<char> v5; // ebx@1
  unsigned int v6; // ST0C_4@2
  PStringBase<char> v7; // ST08_4@2
  char *v8; // edi@3
  TFileEntry *v9; // edi@7
  PStringBase<char> v10; // ST0C_4@8
  int v11; // eax@8
  char *v12; // edi@10
  bool v13; // bl@10
  bool v14; // zf@13
  char *v15; // esi@15
  int v16; // ebx@18
  char v18; // [sp+1Ch] [bp-1Ah]@1
  bool v19; // [sp+1Dh] [bp-19h]@3
  TFileEntry *pNewEntry; // [sp+1Eh] [bp-18h]@3
  unsigned int dbtype; // [sp+22h] [bp-14h]@1
  TFileEntry *pThrowAway; // [sp+26h] [bp-10h]@15
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+2Ah] [bp-Ch]@3

  v3 = this;
  v18 = 0;
  v4 = MasterDBMap::DivineType(&FileName);
  v5.m_charbuffer = FilePath.m_charbuffer;
  dbtype = v4;
  if ( v4 )
  {
    v6 = v4;
    v7.m_charbuffer = FilePath.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&FilePath.m_charbuffer[-1]);
    if ( MasterDBMap::VerifyDirectory(v7, v6) )
    {
      pNewEntry = (TFileEntry *)FileName.m_charbuffer;
      v8 = &FileName.m_charbuffer[-2].m_data[12];
      InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
      v19 = IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
              (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v3->m_CacheByFileName.m_intrusiveTable,
              &result,
              (CaseInsensitiveStringBase<PStringBase<char> > *)&pNewEntry)->m_currElement == 0;
      if ( !InterlockedDecrement((volatile LONG *)v8 + 1) && v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      if ( v19 )
      {
        v9 = (TFileEntry *)operator new(0x24u);
        if ( v9 )
        {
          v10.m_charbuffer = FileName.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
          InterlockedIncrement((volatile LONG *)&v5.m_charbuffer[-1]);
          TFileEntry::TFileEntry(v9, v5, v10);
        }
        else
        {
          v11 = 0;
        }
        *(_DWORD *)(v11 + 20) = dbtype;
        *(_DWORD *)(v11 + 24) = 4;
        pNewEntry = (TFileEntry *)v11;
        *(_BYTE *)(v11 + 28) = 0;
        v12 = &FileName.m_charbuffer[-2].m_data[12];
        dbtype = (unsigned int)FileName.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
        v13 = HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::add(
                (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> *)&v3->m_CacheByFileName.vfptr,
                (CaseInsensitiveStringBase<PStringBase<char> > *)&dbtype,
                &pNewEntry) == 0;
        if ( !InterlockedDecrement((volatile LONG *)v12 + 1) && v12 )
          (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
        v14 = v13 == 0;
        v5.m_charbuffer = FilePath.m_charbuffer;
        if ( v14 )
          v18 = 1;
      }
    }
  }
  pThrowAway = 0;
  InterlockedIncrement((volatile LONG *)&v5.m_charbuffer[-1]);
  v3->vfptr[2].GetFullPathByFileName(
    (TReadOnlyFile2IDTable *)v3,
    (PStringBase<char>)v5.m_charbuffer,
    (unsigned int)&pThrowAway,
    (PStringBase<char> *)2);
  v15 = &FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
  v16 = (int)&v5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v16 + 4)) && v16 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v16)(v16, 1);
  return v18;
}

//----- (0067A6B0) --------------------------------------------------------  // acclient.c:657382
bool __thiscall TFile2IDTable::FindEntryByName(TFile2IDTable *this, PStringBase<char> _FileName, TFileEntry **_pEntry, FileEntryType _TypeToAllocate)
{
  char *v4; // edi@1
  TFile2IDTable *v5; // ebx@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *v6; // ebx@1
  TFileEntry *v7; // edi@11
  PStringBase<char> v8; // ST0C_4@12
  PStringBase<char> v9; // ST08_4@12
  TFileEntry *v10; // eax@12
  TFileEntry *v11; // edi@12
  TFileEntry *v12; // edi@14
  PStringBase<char> v13; // ST0C_4@15
  PStringBase<char> v14; // ST08_4@15
  TFileEntry *v15; // eax@15
  int v16; // eax@17
  char *v17; // ebp@20
  char v18; // bl@22
  PSRefBufferCharData<char> *v19; // ST04_4@27
  char *v20; // ebp@28
  FileEntryType v21; // ecx@31
  PSRefBufferCharData<char> *v22; // ebp@31
  bool v23; // bl@35
  char *v24; // esi@35
  char v26; // [sp+13h] [bp-31h]@3
  PStringBase<char> strDirectory; // [sp+14h] [bp-30h]@17
  TFileEntry *pNewEntry; // [sp+18h] [bp-2Ch]@12
  TFileEntry *pThrowAway; // [sp+1Ch] [bp-28h]@1
  TFile2IDTable *v30; // [sp+20h] [bp-24h]@1
  CaseInsensitiveStringBase<PStringBase<char> > _key; // [sp+24h] [bp-20h]@20
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+28h] [bp-1Ch]@1
  PStringBaseIter<char> iter; // [sp+34h] [bp-10h]@17

  v4 = &_FileName.m_charbuffer[-2].m_data[12];
  pThrowAway = (TFileEntry *)_FileName.m_charbuffer;
  v5 = this;
  v30 = this;
  InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
  v6 = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v5->m_CacheByFileName.m_intrusiveTable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
    v6,
    &result,
    (CaseInsensitiveStringBase<PStringBase<char> > *)&pThrowAway);
  if ( result.m_currElement )
  {
    *_pEntry = (TFileEntry *)result.m_currElement->func;
LABEL_4:
    v26 = 0;
    goto LABEL_5;
  }
  v26 = 1;
  if ( _TypeToAllocate == 1 )
    goto LABEL_4;
LABEL_5:
  if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  if ( v26 )
  {
    if ( _TypeToAllocate != 3 && _TypeToAllocate != 2 )
    {
      v7 = (TFileEntry *)operator new(0x24u);
      if ( v7 )
      {
        v8.m_charbuffer = _FileName.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
        v9.m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1]);
        TFileEntry::TFileEntry(v7, v9, v8);
        v11 = v10;
        pNewEntry = v10;
      }
      else
      {
        v11 = 0;
        pNewEntry = 0;
      }
LABEL_31:
      v21 = _TypeToAllocate;
      v11->m_did.id = stru_8F7704.id;
      v11->m_EntryType = v21;
      v11->m_bAuthoritative = 0;
      v22 = _FileName.m_charbuffer;
      _TypeToAllocate = (FileEntryType)_FileName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
      HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::add(
        (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> *)&v30->m_CacheByFileName.vfptr,
        (CaseInsensitiveStringBase<PStringBase<char> > *)&_TypeToAllocate,
        &pNewEntry);
      if ( !InterlockedDecrement((volatile LONG *)&v22[-1]) && v22 != (PSRefBufferCharData<char> *)20 )
        (**(void (__thiscall ***)(char *, signed int))&v22[-2].m_data[12])(&v22[-2].m_data[12], 1);
      *_pEntry = v11;
      goto LABEL_35;
    }
    v12 = (TFileEntry *)operator new(0x24u);
    if ( v12 )
    {
      v13.m_charbuffer = _FileName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
      v14.m_charbuffer = _FileName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
      TFileEntry::TFileEntry(v12, v14, v13);
      v11 = v15;
    }
    else
    {
      v11 = 0;
    }
    strDirectory.m_charbuffer = _FileName.m_charbuffer;
    pNewEntry = v11;
    InterlockedIncrement((volatile LONG *)&_FileName.m_charbuffer[-1]);
    PSUtils::get_directory(&strDirectory, &_FileName);
    iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Const<char>::vftable;
    iter.pstring_ptr = &strDirectory;
    iter.curr = 0;
    iter.mark = 0;
    v16 = PStringBaseIter_Const<char>::vftable(&iter);
    if ( (unsigned int)v16 >= 1 )
      iter.curr = v16 - 1;
    else
      iter.curr = 0;
    PStringBaseIter<char>::Truncate(&iter);
    pThrowAway = 0;
    v17 = &strDirectory.m_charbuffer[-2].m_data[12];
    _key.m_charbuffer = strDirectory.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strDirectory.m_charbuffer[-1]);
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
      v6,
      &result,
      &_key);
    if ( result.m_currElement )
    {
      pThrowAway = (TFileEntry *)result.m_currElement->func;
    }
    else if ( *(_DWORD *)&strDirectory.m_charbuffer[-1].m_data[12] > 3u )
    {
      v18 = 1;
LABEL_23:
      if ( !InterlockedDecrement((volatile LONG *)v17 + 1) && v17 )
        (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
      if ( v18 )
      {
        v19 = strDirectory.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&strDirectory.m_charbuffer[-1]);
        ((void (__stdcall *)(PSRefBufferCharData<char> *, TFileEntry **, signed int))v30->vfptr[2].GetFullPathByFileName)(
          v19,
          &pThrowAway,
          2);
      }
      v20 = &strDirectory.m_charbuffer[-2].m_data[12];
      iter.vfptr = (PStringBaseIter_Common<char>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
      if ( !InterlockedDecrement((volatile LONG *)&strDirectory.m_charbuffer[-1]) && v20 )
        (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
      goto LABEL_31;
    }
    v18 = 0;
    goto LABEL_23;
  }
LABEL_35:
  v23 = *_pEntry != 0;
  v24 = &_FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_FileName.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
  return v23;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79448C: using guessed type int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD);

//----- (0067A9A0) --------------------------------------------------------  // acclient.c:657549
bool __thiscall TFile2IDTable::AssignPathToFileNameInternal(TFile2IDTable *this, PStringBase<char> FileName, PStringBase<char> FilePath, int tFileWriteTime)
{
  int v4; // eax@1
  int v5; // ebx@1
  unsigned int v6; // ST18_4@2
  PStringBase<char> v7; // ST14_4@2
  char *v8; // edi@3
  bool (__thiscall *v9)(ClientCommunicationSystem *, int, char **); // esi@3
  int v10; // edi@11
  PSRefBufferCharData<char> *v11; // ebx@11
  PStringBase<char> *v12; // ST18_4@14
  PStringBase<char> *v13; // eax@14
  int v14; // edi@16
  PStringBase<char> *v15; // eax@16
  char *v16; // ebx@16
  char *v17; // edi@22
  int v18; // esi@27
  int v19; // edx@33
  void *v20; // ecx@33
  TFileEntry *v21; // esi@34
  PStringBase<char> v22; // ST18_4@35
  PStringBase<char> v23; // ST14_4@35
  int v24; // eax@35
  int v25; // esi@35
  int v26; // eax@37
  PSRefBufferCharData<char> *v27; // esi@37
  int v28; // esi@37
  PStringBase<char> *v29; // eax@37
  char *v30; // edi@37
  int v31; // esi@43
  char *v32; // esi@46
  bool v33; // bl@46
  char *v34; // esi@51
  PSRefBufferCharData<char> *v35; // edi@55
  PSRefBufferCharData<char> *v36; // ST10_4@55
  char *v37; // esi@55
  bool bRetval; // [sp+2Dh] [bp-51h]@1
  TFile2IDTable *v40; // [sp+2Eh] [bp-50h]@1
  PStringBase<char> cleanPath; // [sp+32h] [bp-4Ch]@13
  TFileEntry *pNewEntry; // [sp+36h] [bp-48h]@3
  PStringBase<char> rhs; // [sp+3Ah] [bp-44h]@11
  PStringBase<char> FullName; // [sp+3Eh] [bp-40h]@3
  PStringBase<char> v45; // [sp+42h] [bp-3Ch]@14
  PStringBase<char> v46; // [sp+46h] [bp-38h]@14
  TFileEntry *pThrowAway; // [sp+4Ah] [bp-34h]@55
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> result; // [sp+4Eh] [bp-30h]@3
  _WIN32_FILE_ATTRIBUTE_DATA FileData; // [sp+5Ah] [bp-24h]@25

  v40 = this;
  bRetval = 0;
  v4 = MasterDBMap::DivineType(&FileName);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4;
    v7.m_charbuffer = FilePath.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&FilePath.m_charbuffer[-1]);
    if ( MasterDBMap::VerifyDirectory(v7, v6) )
    {
      v8 = &FileName.m_charbuffer[-2].m_data[12];
      v9 = 0;
      pNewEntry = 0;
      FullName.m_charbuffer = FileName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
      IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::find_internal(
        (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,ClientCommunicationSystem::CmdHashData *,1> *)&v40->m_CacheByFileName.m_intrusiveTable,
        &result,
        (CaseInsensitiveStringBase<PStringBase<char> > *)&FullName);
      if ( result.m_currElement )
      {
        v9 = result.m_currElement->func;
        pNewEntry = (TFileEntry *)result.m_currElement->func;
      }
      if ( !InterlockedDecrement((volatile LONG *)v8 + 1) && v8 )
        (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
      if ( v9 )
      {
        if ( !*((_DWORD *)v9 + 5) )
          *((_DWORD *)v9 + 5) = v5;
        v10 = *((_DWORD *)v9 + 2);
        v11 = (PSRefBufferCharData<char> *)(v10 - 20);
        FullName.m_charbuffer = (PSRefBufferCharData<char> *)*((_DWORD *)v9 + 2);
        rhs.m_charbuffer = (PSRefBufferCharData<char> *)(v10 - 20);
        InterlockedIncrement((volatile LONG *)(v10 - 20 + 4));
        if ( *(_DWORD *)(v10 - 4) != 1 && *((_BYTE *)v9 + 28) )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (CaseInsensitiveStringBase<PStringBase<char> > *)&cleanPath,
            &FilePath);
          PStringBase<unsigned short>::PStringBase<unsigned short>(
            (CaseInsensitiveStringBase<PStringBase<char> > *)&tFileWriteTime,
            &FullName);
          PSUtils::cleanup_directory_name(&cleanPath, 0);
          PSUtils::cleanup_directory_name((PStringBase<char> *)&tFileWriteTime, 0);
          PStringBase<char>::tolower(&cleanPath);
          PStringBase<char>::tolower((PStringBase<char> *)&tFileWriteTime);
          if ( !__stricmp((const char *)tFileWriteTime, cleanPath.m_charbuffer->m_data) )
          {
            *((_BYTE *)v9 + 28) = 1;
            PStringBase<char>::PStringBase<char>(&rhs, "\\");
            v12 = TFileEntry::GetFileName((TFileEntry *)v9, &v46);
            v13 = PStringBase<char>::operator+(&FilePath, &v45, &rhs);
            PStringBase<char>::operator+(v13, &FullName, v12);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v45);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v46);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
            TFile2IDTable::SanitizeEntry(&FullName, &pNewEntry);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&FullName);
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&tFileWriteTime);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&cleanPath);
        }
        else
        {
          PStringBase<char>::PStringBase<char>(&FullName, "\\");
          v14 = *((_DWORD *)v9 + 3) - 20;
          v46.m_charbuffer = (PSRefBufferCharData<char> *)*((_DWORD *)v9 + 3);
          InterlockedIncrement((volatile LONG *)(v14 + 4));
          v15 = PStringBase<char>::operator+(&FilePath, &v45, &FullName);
          PStringBase<char>::operator+(v15, (PStringBase<char> *)&tFileWriteTime, &v46);
          v16 = &v45.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v45.m_charbuffer[-1]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
          if ( !InterlockedDecrement((volatile LONG *)(v14 + 4)) && v14 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
          v17 = &FullName.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&FullName.m_charbuffer[-1]) && v17 )
            (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
          if ( GetFileAttributesExA((LPCSTR)tFileWriteTime, 0, &FileData) )
            *((_DWORD *)v9 + 8) = FileTime2TimeType(&FileData.ftLastWriteTime);
          TFileEntry::SetPath((TFileEntry *)v9, &FilePath);
          *((_BYTE *)v9 + 28) = 1;
          TFile2IDTable::SanitizeEntry((PStringBase<char> *)&tFileWriteTime, &pNewEntry);
          v18 = tFileWriteTime - 20;
          bRetval = 1;
          if ( !InterlockedDecrement((volatile LONG *)(tFileWriteTime - 20 + 4)) && v18 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
          v11 = rhs.m_charbuffer;
        }
        if ( !InterlockedDecrement((volatile LONG *)&v11->m_data[4]) && v11 )
        {
          v19 = *(_DWORD *)&v11->m_data[0];
          v20 = v11;
LABEL_54:
          (*(void (__thiscall **)(void *, signed int))v19)(v20, 1);
          goto LABEL_55;
        }
      }
      else
      {
        v21 = (TFileEntry *)operator new(0x24u);
        if ( v21 )
        {
          v22.m_charbuffer = FileName.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
          v23.m_charbuffer = FilePath.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&FilePath.m_charbuffer[-1]);
          TFileEntry::TFileEntry(v21, v23, v22);
          v25 = v24;
        }
        else
        {
          v25 = 0;
        }
        v26 = tFileWriteTime;
        *(_DWORD *)(v25 + 20) = v5;
        *(_DWORD *)(v25 + 24) = 4;
        *(_BYTE *)(v25 + 28) = 1;
        pNewEntry = (TFileEntry *)v25;
        *(_DWORD *)(v25 + 32) = v26;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&tFileWriteTime, "\\");
        v27 = *(PSRefBufferCharData<char> **)(v25 + 12);
        v46.m_charbuffer = v27;
        v28 = (int)&v27[-2].m_data[12];
        InterlockedIncrement((volatile LONG *)(v28 + 4));
        v29 = PStringBase<char>::operator+(&FilePath, &v45, (PStringBase<char> *)&tFileWriteTime);
        PStringBase<char>::operator+(v29, &FullName, &v46);
        v30 = &v45.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v45.m_charbuffer[-1]) && v30 )
          (**(void (__thiscall ***)(char *, signed int))v30)(v30, 1);
        if ( !InterlockedDecrement((volatile LONG *)(v28 + 4)) && v28 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
        v31 = tFileWriteTime - 20;
        if ( !InterlockedDecrement((volatile LONG *)(tFileWriteTime - 20 + 4)) && v31 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
        TFile2IDTable::SanitizeEntry(&FullName, &pNewEntry);
        tFileWriteTime = (int)FileName.m_charbuffer;
        v32 = &FileName.m_charbuffer[-2].m_data[12];
        InterlockedIncrement((volatile LONG *)&FileName.m_charbuffer[-1]);
        v33 = HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::add(
                (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1> *)&v40->m_CacheByFileName.vfptr,
                (CaseInsensitiveStringBase<PStringBase<char> > *)&tFileWriteTime,
                &pNewEntry) == 0;
        if ( !InterlockedDecrement((volatile LONG *)v32 + 1) && v32 )
          (**(void (__thiscall ***)(char *, signed int))v32)(v32, 1);
        if ( !v33 )
          bRetval = 1;
        v34 = &FullName.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&FullName.m_charbuffer[-1]) && v34 )
        {
          v19 = *(_DWORD *)v34;
          v20 = v34;
          goto LABEL_54;
        }
      }
    }
  }
LABEL_55:
  v35 = FilePath.m_charbuffer;
  pThrowAway = 0;
  v36 = FilePath.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&FilePath.m_charbuffer[-1]);
  ((void (__stdcall *)(PSRefBufferCharData<char> *, TFileEntry **, signed int))v40->vfptr[2].GetFullPathByFileName)(
    v36,
    &pThrowAway,
    2);
  v37 = &FileName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName.m_charbuffer[-1]) && v37 )
    (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v35[-1]) && v35 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v35[-2].m_data[12])(&v35[-2].m_data[12], 1);
  return bRetval;
}

//----- (0067AE80) --------------------------------------------------------  // acclient.c:657774
char __thiscall HashTable<unsigned long,TDBTypeEntry *,1>::add(HashTable<unsigned long,TDBTypeEntry *,1> *this, const unsigned int *_key, TDBTypeEntry *const *_data)
{
  HashTable<unsigned long,TDBTypeEntry *,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,TDBTypeEntry *> *)v5) )
  {
    result = 1;
  }
  else
  {
    if ( v5 )
      operator delete(v5);
    result = 0;
  }
  return result;
}

//----- (0067AEE0) --------------------------------------------------------  // acclient.c:657810
void __thiscall TFile2IDTable::Clear(TFile2IDTable *this)
{
  TFile2IDTable *v1; // ebx@1
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *v2; // ebp@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@1
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@1
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // edx@1
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@1
  HeritageGroup_CGVtbl *v7; // ecx@2
  bool v8; // zf@3
  HashTableData<unsigned long,TDBTypeEntry *> **v9; // eax@9
  unsigned int v10; // edx@9
  int v11; // ebx@9
  int v12; // ecx@9
  int v13; // eax@10
  int v14; // eax@11
  int v15; // ecx@12
  int v16; // eax@12
  int v17; // ebp@14
  int v18; // ebx@15
  int v19; // ecx@15
  int v20; // edx@15
  int v21; // eax@15
  int v22; // ebx@15
  int v23; // ecx@15
  int v24; // eax@16
  int v25; // eax@17
  int v26; // eax@18
  int v27; // edi@18
  int v28; // esi@20
  int v29; // ecx@21
  int v30; // ecx@31
  int v31; // [sp+10h] [bp-20h]@9
  TDBTypeEntry *pDBEntry; // [sp+14h] [bp-1Ch]@15
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *typ; // [sp+18h] [bp-18h]@1
  int typ_4; // [sp+1Ch] [bp-14h]@14
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+24h] [bp-Ch]@1

  v1 = this;
  v2 = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_CacheByFileName.m_intrusiveTable;
  v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_CacheByFileName.m_intrusiveTable,
         &result);
  v4 = v3->m_currElement;
  v5 = v3->m_currHashTable;
  v6 = v3->m_currBucket;
  typ = v3->m_currHashTable;
  if ( v4 )
  {
    do
    {
LABEL_2:
      v7 = v4->m_data.vfptr;
      if ( v7 )
      {
        v8 = v7[1].Serialize-- == (void (__thiscall *)(HeritageGroup_CG *, Archive *))1;
        if ( v8 )
        {
          (*(void (__stdcall **)(signed int))v7->Serialize)(1);
          v5 = typ;
        }
      }
      v4 = v4->m_hashNext;
    }
    while ( v4 );
    while ( 1 )
    {
      ++v6;
      if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
        break;
      if ( *v6 )
      {
        v4 = *v6;
        if ( *v6 )
          goto LABEL_2;
        break;
      }
    }
  }
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents(v2);
  v9 = v1->m_CacheByDID.m_intrusiveTable.m_buckets;
  v10 = v1->m_CacheByDID.m_intrusiveTable.m_numBuckets;
  v11 = (int)&v1->m_CacheByDID.m_intrusiveTable;
  v12 = (int)&v9[v10];
  v31 = v11;
  if ( *(_DWORD *)(v11 + 100) == v12 )
  {
LABEL_12:
    v15 = 0;
    v16 = 0;
  }
  else
  {
    while ( 1 )
    {
      v13 = *(_DWORD *)(v11 + 100);
      if ( *(_DWORD *)v13 )
        break;
      v14 = v13 + 4;
      *(_DWORD *)(v11 + 100) = v14;
      if ( v14 == v12 )
        goto LABEL_12;
    }
    v15 = *(_DWORD *)(v11 + 100);
    v16 = *(_DWORD *)v15;
  }
  typ_4 = v15;
  v17 = v16;
  if ( v16 )
  {
    do
    {
LABEL_15:
      v18 = *(_DWORD *)(v17 + 8);
      v19 = *(_DWORD *)(v18 + 128);
      v20 = *(_DWORD *)(v18 + 120);
      v21 = *(_DWORD *)(v18 + 124);
      pDBEntry = *(TDBTypeEntry **)(v17 + 8);
      v22 = v18 + 24;
      v23 = v20 + 4 * v19;
      if ( v21 == v23 )
      {
LABEL_18:
        v26 = 0;
        v27 = 0;
      }
      else
      {
        while ( 1 )
        {
          v24 = *(_DWORD *)(v22 + 100);
          if ( *(_DWORD *)v24 )
            break;
          v25 = v24 + 4;
          *(_DWORD *)(v22 + 100) = v25;
          if ( v25 == v23 )
            goto LABEL_18;
        }
        v26 = *(_DWORD *)(v22 + 100);
        v27 = *(_DWORD *)v26;
      }
      v28 = v26;
      if ( v27 )
      {
        do
        {
LABEL_21:
          v29 = *(_DWORD *)(v27 + 8);
          if ( v29 )
          {
            v8 = (*(_DWORD *)(v29 + 4))-- == 1;
            if ( v8 )
              (**(void (__stdcall ***)(_DWORD))v29)(1);
          }
          v27 = *(_DWORD *)(v27 + 4);
        }
        while ( v27 );
        while ( 1 )
        {
          v28 += 4;
          if ( v28 == *(_DWORD *)(v22 + 96) + 4 * *(_DWORD *)(v22 + 104) )
            break;
          if ( *(_DWORD *)v28 )
          {
            v27 = *(_DWORD *)v28;
            if ( *(_DWORD *)v28 )
              goto LABEL_21;
            break;
          }
        }
      }
      IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v22);
      if ( pDBEntry )
      {
        TDBTypeEntry::~TDBTypeEntry(pDBEntry);
        operator delete(pDBEntry);
      }
      v17 = *(_DWORD *)(v17 + 4);
    }
    while ( v17 );
    while ( 1 )
    {
      v30 = typ_4 + 4;
      typ_4 += 4;
      if ( typ_4 == *(_DWORD *)(v31 + 96) + 4 * *(_DWORD *)(v31 + 104) )
        break;
      if ( *(_DWORD *)v30 )
      {
        v17 = *(_DWORD *)v30;
        if ( *(_DWORD *)v30 )
          goto LABEL_15;
        break;
      }
    }
    v11 = v31;
  }
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)v11);
}

//----- (0067B080) --------------------------------------------------------  // acclient.c:658010
TDBTypeEntry *__thiscall TFile2IDTable::GetDBTypeEntry(TFile2IDTable *this, unsigned int _dbtype)
{
  TFile2IDTable *v2; // edi@1
  HashTableData<unsigned long,TDBTypeEntry *> *v3; // eax@1
  TDBTypeEntry *v4; // eax@4
  int v5; // eax@5
  int v6; // esi@5
  TDBTypeEntry *result; // eax@7
  PSRefBufferCharData<char> *v8; // eax@9
  int v9; // edi@10
  volatile LONG *v10; // ST04_4@13
  PSRefBufferCharData<char> *v11; // eax@14
  int v12; // edi@15
  volatile LONG *v13; // ST04_4@18
  TFile2IDTable *v14; // [sp+8h] [bp-8h]@1
  TDBTypeEntry *pTypeEntry; // [sp+Ch] [bp-4h]@9

  v2 = this;
  v14 = this;
  v3 = this->m_CacheByDID.m_intrusiveTable.m_buckets[_dbtype % this->m_CacheByDID.m_intrusiveTable.m_numBuckets];
  if ( !v3 )
    goto LABEL_4;
  while ( v3->m_hashKey != _dbtype )
  {
    v3 = v3->m_hashNext;
    if ( !v3 )
      goto LABEL_4;
  }
  if ( v3 )
  {
    result = v3->m_data;
  }
  else
  {
LABEL_4:
    v4 = (TDBTypeEntry *)operator new(0x88u);
    if ( v4 )
    {
      TDBTypeEntry::TDBTypeEntry(v4);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    *(_BYTE *)v6 = 0;
    *(_BYTE *)(v6 + 1) = 0;
    v8 = *(PSRefBufferCharData<char> **)(v6 + 4);
    pTypeEntry = (TDBTypeEntry *)v6;
    if ( v8 != PStringBase<char>::null_string.m_charbuffer )
    {
      v9 = (int)&v8[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      v10 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
      *(_DWORD *)(v6 + 4) = PStringBase<char>::null_string.m_charbuffer;
      InterlockedIncrement(v10);
      v2 = v14;
    }
    v11 = *(PSRefBufferCharData<char> **)(v6 + 8);
    if ( v11 != PStringBase<char>::null_string.m_charbuffer )
    {
      v12 = (int)&v11[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) )
      {
        if ( v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
      }
      v13 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
      *(_DWORD *)(v6 + 8) = PStringBase<char>::null_string.m_charbuffer;
      InterlockedIncrement(v13);
      v2 = v14;
    }
    *(_DWORD *)(v6 + 16) = 0;
    HashTable<unsigned long,TDBTypeEntry *,1>::add(
      (HashTable<unsigned long,TDBTypeEntry *,1> *)&v2->m_CacheByDID.vfptr,
      &_dbtype,
      &pTypeEntry);
    result = (TDBTypeEntry *)v6;
  }
  return result;
}

//----- (0067B190) --------------------------------------------------------  // acclient.c:658094
AutoGrowHashTable<unsigned long,TDBTypeEntry *> *__thiscall AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor(AutoGrowHashTable<unsigned long,TDBTypeEntry *> *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned long,TDBTypeEntry *> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,TDBTypeEntry *,1>Vtbl *)&HashTable<unsigned long,TDBTypeEntry *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable;
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
// 7FE140: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable[5])(void *, char);
// 7FE150: using guessed type int (__thiscall *HashTable<unsigned long,TDBTypeEntry *,1>::vftable)(void *, char);

//----- (0067B1F0) --------------------------------------------------------  // acclient.c:658120
void __thiscall TFile2IDTable::~TFile2IDTable(TFile2IDTable *this)
{
  TFile2IDTable *v1; // edi@1
  void *v2; // eax@1
  void *v3; // eax@3

  v1 = this;
  this->vfptr = (TReadOnlyFile2IDTableVtbl *)&DBFile2IDTable::vftable;
  TFile2IDTable::Clear(this);
  v1->m_CacheByDID.vfptr = (HashTable<unsigned long,TDBTypeEntry *,1>Vtbl *)&HashTable<unsigned long,TDBTypeEntry *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_CacheByDID.m_intrusiveTable);
  v2 = v1->m_CacheByDID.m_intrusiveTable.m_buckets;
  v1->m_CacheByDID.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable;
  if ( v2 != v1->m_CacheByDID.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v2);
  v1->m_CacheByDID.m_intrusiveTable.m_buckets = 0;
  v1->m_CacheByDID.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_CacheByDID.m_intrusiveTable.m_numBuckets = 0;
  v1->m_CacheByDID.m_intrusiveTable.m_numElements = 0;
  v1->m_CacheByFileName.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1>Vtbl *)HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v1->m_CacheByFileName.m_intrusiveTable);
  v3 = v1->m_CacheByFileName.m_intrusiveTable.m_buckets;
  v1->m_CacheByFileName.m_intrusiveTable.vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char> >,HashTableData<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable;
  if ( v3 != v1->m_CacheByFileName.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_CacheByFileName.m_intrusiveTable.m_buckets = 0;
  v1->m_CacheByFileName.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_CacheByFileName.m_intrusiveTable.m_numBuckets = 0;
  v1->m_CacheByFileName.m_intrusiveTable.m_numElements = 0;
}
// 7C5860: using guessed type int (__stdcall *DBFile2IDTable::vftable)(IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, PStringBase<char> FileNameCopy);
// 7FE13C: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable[6])(void *, char);
// 7FE140: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable[5])(void *, char);
// 7FE14C: using guessed type int (__thiscall *HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable[2])(void *, char);
// 7FE150: using guessed type int (__thiscall *HashTable<unsigned long,TDBTypeEntry *,1>::vftable)(void *, char);

//----- (0067B280) --------------------------------------------------------  // acclient.c:658157
void __thiscall TFile2IDTable::TFile2IDTable(TFile2IDTable *this, unsigned int _ExpectedTableSize)
{
  TFile2IDTable *v2; // esi@1
  unsigned int v3; // eax@1
  bool v4; // zf@1
  unsigned int *v5; // edi@2
  unsigned int *v6; // eax@2

  v2 = this;
  this->vfptr = (TReadOnlyFile2IDTableVtbl *)&DBFile2IDTable::vftable;
  this->m_CacheByFileName.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1>Vtbl *)HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>(
    &this->m_CacheByFileName.m_intrusiveTable,
    0);
  v2->m_CacheByFileName.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<char> >,TFileEntry *,1>Vtbl *)HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable;
  v2->m_CacheByDID.vfptr = (HashTable<unsigned long,TDBTypeEntry *,1>Vtbl *)&HashTable<unsigned long,TDBTypeEntry *,1>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>(
    &v2->m_CacheByDID.m_intrusiveTable,
    0);
  v3 = _ExpectedTableSize;
  v4 = _ExpectedTableSize == 0;
  v2->m_CacheByDID.vfptr = (HashTable<unsigned long,TDBTypeEntry *,1>Vtbl *)&HashTable<unsigned long,TDBTypeEntry *,1>::vftable;
  if ( !v4 )
  {
    v5 = g_bucketSizesEnd;
    _ExpectedTableSize = v3;
    v6 = (unsigned int *)_STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_ExpectedTableSize);
    if ( v6 == v5 )
      --v6;
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::resize_internal(
      &v2->m_CacheByFileName.m_intrusiveTable,
      *v6);
  }
}
// 7C5860: using guessed type int (__stdcall *DBFile2IDTable::vftable)(IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, PStringBase<char> FileNameCopy);
// 7FE14C: using guessed type int (__thiscall *HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable[2])(void *, char);
// 7FE150: using guessed type int (__thiscall *HashTable<unsigned long,TDBTypeEntry *,1>::vftable)(void *, char);

//----- (00714FB0) --------------------------------------------------------  // acclient.c:807907
int sub_714FB0()
{
  return atexit(nullsub_124);
}

