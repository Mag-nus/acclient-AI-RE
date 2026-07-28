/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArgParser
   Object     : CORE\core_utils\ArgParser.obj
   Functions  : 72
   Addresses  : 00407250 - 0065E6C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00407250) --------------------------------------------------------  // acclient.c:66547
void __stdcall ArgumentParser::AppendOutputText(const char *Text, ArgumentParser::OutputTextType i_eFormattingHint)
{
  int v3; // ecx@4

  if ( Text && *Text )
  {
    switch ( i_eFormattingHint )
    {
      case 1:
        v3 = (int)"\x1B[0m\x1B[1m";
        goto LABEL_6;
      case 2:
      case 3:
        v3 = (int)"\x1B[4m";
LABEL_6:
        color_printf("%s%s%s", v3, Text, "\x1B[0m");
        break;
      default:
        _fputs(Text, (FILE *)__iob[0]._ptr + 1);
        break;
    }
  }
}

//----- (004072C0) --------------------------------------------------------  // acclient.c:66572
void __thiscall IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // esi@1
  char *v3; // eax@2
  unsigned int v4; // ecx@4

  v2 = this;
  this->m_numBuckets = _numBuckets;
  if ( _numBuckets > 0x17 )
    v3 = (char *)operator new[](4 * _numBuckets);
  else
    v3 = (char *)this->m_aInplaceBuckets;
  v4 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)&v3[v4];
  v2->m_buckets = (HashTableData<unsigned short,long> **)v3;
  memset(v3, 0, v4);
}

//----- (00407310) --------------------------------------------------------  // acclient.c:66591
unsigned int __thiscall PStringBase<unsigned short>::operator[](PStringBase<unsigned short> *this, unsigned int index)
{
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned int result; // eax@2

  v2 = this->m_charbuffer;
  v3 = *(_DWORD *)&this->m_charbuffer[-1].m_data[14];
  if ( index < v3 )
    result = (unsigned int)((char *)v2 + 2 * index);
  else
    result = (unsigned int)((char *)v2 + 2 * v3 - 2);
  return result;
}

//----- (00407330) --------------------------------------------------------  // acclient.c:66607
int __cdecl SortCommandLineArgs(const void *_a, const void *_b)
{
  return __stricmp(*(const char **)(*(_DWORD *)_a + 8), *(const char **)(*(_DWORD *)_b + 8));
}

//----- (00407350) --------------------------------------------------------  // acclient.c:66613
int __thiscall ArgumentParser::ParseArgs(ArgumentParser *this, SmartArray<PStringBase<unsigned short>,1> *args, bool fSkipArgv0)
{
  unsigned int v3; // eax@1
  ArgumentParserVtbl *v4; // eax@2
  int result; // eax@2

  v3 = args->m_num;
  if ( v3 )
  {
    result = (*(int (__stdcall **)(PStringBase<unsigned short> *, unsigned int, _DWORD))&this->vfptr->gap4[8])(
               args->m_data,
               v3,
               fSkipArgv0);
  }
  else
  {
    v4 = this->vfptr;
    args = (SmartArray<PStringBase<unsigned short>,1> *)&word_794320;
    result = (*(int (__stdcall **)(SmartArray<PStringBase<unsigned short>,1> **, _DWORD, _DWORD))&v4->gap4[8])(
               &args,
               0,
               fSkipArgv0);
  }
  return result;
}

//----- (00407390) --------------------------------------------------------  // acclient.c:66640
int __thiscall ArgumentParser::ParseArgs(ArgumentParser *this, SmartArray<PStringBase<char>,1> *args, bool fSkipArgv0)
{
  unsigned int v3; // eax@1
  ArgumentParserVtbl *v4; // eax@2
  int result; // eax@2

  v3 = args->m_num;
  if ( v3 )
  {
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->ParseArgs)(args->m_data, v3, fSkipArgv0);
  }
  else
  {
    v4 = this->vfptr;
    args = (SmartArray<PStringBase<char>,1> *)&word_794320;
    result = (*(int (__stdcall **)(SmartArray<PStringBase<char>,1> **, _DWORD, _DWORD))&v4->gap4[8])(
               &args,
               0,
               fSkipArgv0);
  }
  return result;
}

//----- (004073D0) --------------------------------------------------------  // acclient.c:66664
unsigned int __thiscall CaseInsensitiveStringBase<PStringBase<unsigned short>>::case_insensitive_hash(CaseInsensitiveStringBase<PStringBase<unsigned short> > *this)
{
  PSRefBufferCharData<unsigned short> *v1; // edi@1
  wint_t v2; // ax@1
  unsigned int i; // esi@1

  v1 = this->m_charbuffer;
  v2 = this->m_charbuffer->m_data[0];
  for ( i = 0; v2; v1 = (PSRefBufferCharData<unsigned short> *)((char *)v1 + 2) )
  {
    i = _towlower(v2) + 16 * i;
    if ( i & 0xF0000000 )
      i = (i ^ ((i & 0xF0000000) >> 24)) & 0xFFFFFFF;
    v2 = v1->m_data[1];
  }
  return i;
}

//----- (00407420) --------------------------------------------------------  // acclient.c:66683
IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::scalar_deleting_destructor(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v2; // esi@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable;
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
// 794324: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable[2])(void *, char);

//----- (00407460) --------------------------------------------------------  // acclient.c:66704
IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *__thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::scalar_deleting_destructor(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // esi@1
  HashTableData<unsigned short,long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>Vtbl *)&IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable;
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
// 794328: using guessed type int (__thiscall *IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable)(void *, char);

//----- (004074A0) --------------------------------------------------------  // acclient.c:66725
int __thiscall CommandLineArg::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // ebx@7
  int v8; // eax@10

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_BYTE *)(this + 4) = *(_BYTE *)(a2 + 4);
  v3 = *(_DWORD *)(this + 8);
  if ( v3 != *(_DWORD *)(a2 + 8) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *(_DWORD *)(v2 + 12);
  if ( v6 != *(_DWORD *)(a2 + 12) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 12) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  return v2;
}

//----- (00407540) --------------------------------------------------------  // acclient.c:66765
PStringBase<char> *__thiscall PStringBase<unsigned short>::vector_deleting_destructor(PStringBase<char> *this, unsigned int a2)
{
  PStringBase<char> *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@2
  PStringBase<char> *v4; // ebx@2
  PStringBase<char> *v5; // edi@2
  int v6; // eax@2
  PSRefBufferCharData<char> *v7; // esi@4
  int v8; // esi@4
  PStringBase<char> *result; // eax@10
  char *v10; // esi@11
  int v11; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].m_charbuffer;
    v4 = this - 1;
    v5 = &this[(_DWORD)v3];
    v6 = (int)&v3[-1].m_data[15];
    if ( v6 >= 0 )
    {
      v11 = v6 + 1;
      do
      {
        v7 = v5[-1].m_charbuffer;
        --v5;
        v8 = (int)&v7[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        --v11;
      }
      while ( v11 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v10 = &this->m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)v10 + 1) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004075F0) --------------------------------------------------------  // acclient.c:66816
unsigned int __stdcall SmartArray<char *,1>::get_new_size(unsigned int i_nSize)
{
  unsigned int v2; // edx@1
  unsigned int result; // eax@2

  v2 = i_nSize;
  if ( i_nSize > 8 )
  {
    if ( i_nSize <= 0x4000 )
    {
      __asm { bsr     eax, [esp+4+i_nSize] }
      _CF = i_nSize < 1 << _EAX;
      _ZF = i_nSize == 1 << _EAX;
      result = 2 * (1 << _EAX);
      if ( _CF || _ZF )
        result = i_nSize;
    }
    else
    {
      if ( i_nSize & 0x3FFF )
        v2 = 0x4000 - (i_nSize & 0x3FFF) + i_nSize;
      result = v2;
    }
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (00407650) --------------------------------------------------------  // acclient.c:66848
void __thiscall SmartArray<PStringBase<unsigned short>,1>::Reset(SmartArray<PStringBase<unsigned short>,1> *this)
{
  SmartArray<PStringBase<unsigned short>,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  wchar_t *v4; // esi@7
  volatile LONG *v5; // edi@7
  int v6; // ebx@7
  int v7; // eax@7
  int v8; // ebp@8
  int v9; // esi@12
  int iElement; // [sp+8h] [bp-8h]@6
  SmartArray<PStringBase<unsigned short>,1> *v11; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v11 = v1;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( iElement = (v2 & 0x7FFFFFFF) - 1; iElement >= 0; --iElement )
    {
      v4 = PStringBase<unsigned short>::s_NullBuffer;
      v5 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v6 = (int)&v1->m_data[iElement];
      v7 = *(_DWORD *)v6;
      if ( *(wchar_t **)v6 != v4 )
      {
        v8 = v7 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v7 - 20 + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        *(_DWORD *)v6 = v4;
        InterlockedIncrement(v5);
        v1 = v11;
      }
      v9 = (int)(v4 - 10);
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
  }
}

//----- (00407720) --------------------------------------------------------  // acclient.c:66900
void __thiscall SmartArray<unsigned short *,1>::Reset(SmartArray<unsigned short *,1> *this)
{
  SmartArray<unsigned short *,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v1->m_data[i + 1] = 0 )
      --i;
  }
}

//----- (00407790) --------------------------------------------------------  // acclient.c:66925
void __thiscall SmartArray<PStringBase<char>,1>::Reset(SmartArray<PStringBase<char>,1> *this)
{
  SmartArray<PStringBase<char>,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  PSRefBufferCharData<char> *v4; // esi@7
  volatile LONG *v5; // edi@7
  int v6; // ebx@7
  int v7; // eax@7
  int v8; // ebp@8
  int v9; // esi@12
  int iElement; // [sp+8h] [bp-8h]@6
  SmartArray<PStringBase<char>,1> *v11; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v11 = v1;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      PStringBase<unsigned short>::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( iElement = (v2 & 0x7FFFFFFF) - 1; iElement >= 0; --iElement )
    {
      v4 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      v5 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v6 = (int)&v1->m_data[iElement];
      v7 = *(_DWORD *)v6;
      if ( *(PSRefBufferCharData<char> **)v6 != v4 )
      {
        v8 = v7 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v7 - 20 + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        *(_DWORD *)v6 = v4;
        InterlockedIncrement(v5);
        v1 = v11;
      }
      v9 = (int)&v4[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
  }
}

//----- (00407860) --------------------------------------------------------  // acclient.c:66977
void __thiscall CommandLineArg::CommandLineArg(CommandLineArg *this)
{
  CommandLineArg *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->ArgType = 0;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->LongVersion.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->Description.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
}

//----- (004078A0) --------------------------------------------------------  // acclient.c:66994
void __thiscall ArgumentParser::AppendArgumentText(ArgumentParser *this, PStringBase<char> i_strShort, PStringBase<char> i_strLong, PStringBase<char> i_strDescription)
{
  ArgumentParser *v4; // esi@1
  PSRefBufferCharData<char> *v5; // eax@3
  PSRefBufferCharData<char> *v6; // edi@6
  int v7; // ebx@9
  int v8; // ebx@13
  char *v9; // eax@15
  int v10; // edx@16
  int v11; // eax@17
  int v12; // eax@17
  ArgumentParserVtbl *v13; // edx@17
  char dash; // [sp+4Bh] [bp-105h]@2
  char szOut[256]; // [sp+50h] [bp-100h]@7

  v4 = this;
  if ( *(_DWORD *)&this->m_CmdChars.m_charbuffer[-1].m_data[12] == 1 )
  {
    dash = 32;
  }
  else
  {
    v5 = this->m_CmdChars.m_charbuffer;
    if ( !*(_DWORD *)&v5[-1].m_data[12] )
      v5 = (PSRefBufferCharData<char> *)((char *)v5 - 1);
    dash = v5->m_data[0];
  }
  v6 = i_strShort.m_charbuffer;
  if ( *(_DWORD *)&i_strShort.m_charbuffer[-1].m_data[12] == 1 )
    _sprintf(szOut, "  ");
  else
    _sprintf(szOut, "%c%s", dash, i_strShort.m_charbuffer);
  v7 = v4->vfptr->AppendAndWordWrap(v4, szOut, 22, 0, ottShortVersion);
  if ( *(_DWORD *)&i_strShort.m_charbuffer[-1].m_data[12] == 1 || *(_DWORD *)&i_strLong.m_charbuffer[-1].m_data[12] == 1 )
    _sprintf(szOut, "  ");
  else
    _sprintf(szOut, ", ");
  v8 = v4->vfptr->AppendAndWordWrap(v4, szOut, 22, v7, 0);
  if ( *(_DWORD *)&i_strLong.m_charbuffer[-1].m_data[12] != 1 )
  {
    _sprintf(szOut, "%c%c%s", dash, dash, i_strLong.m_charbuffer);
    v8 = v4->vfptr->AppendAndWordWrap(v4, szOut, 22, v8, ottLongVersion);
  }
  v9 = szOut;
  if ( (unsigned int)v8 < 0x14 )
  {
    v10 = 20 - v8;
    memset(szOut, 0x20u, 20 - v8);
    v6 = i_strShort.m_charbuffer;
    v8 = 20;
    v9 = &szOut[v10];
  }
  *v9 = 58;
  v11 = (int)(v9 + 1);
  *(_BYTE *)v11 = 32;
  *(_BYTE *)(v11 + 1) = 0;
  v12 = v4->vfptr->AppendAndWordWrap(v4, szOut, 22, v8, 0);
  v4->vfptr->AppendAndWordWrap(v4, (const char *)i_strDescription.m_charbuffer, 22, v12, ottDescription);
  v13 = v4->vfptr;
  szOut[0] = 10;
  szOut[1] = 0;
  v13->AppendOutputText(v4, szOut, 0);
  if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
  if ( !InterlockedDecrement((volatile LONG *)&i_strLong.m_charbuffer[-1])
    && i_strLong.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&i_strLong.m_charbuffer[-2].m_data[12])(
      &i_strLong.m_charbuffer[-2].m_data[12],
      1);
  if ( !InterlockedDecrement((volatile LONG *)&i_strDescription.m_charbuffer[-1])
    && i_strDescription.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&i_strDescription.m_charbuffer[-2].m_data[12])(
      &i_strDescription.m_charbuffer[-2].m_data[12],
      1);
}

//----- (00407A80) --------------------------------------------------------  // acclient.c:67071
void __thiscall ArgumentParser::SetErrorText(ArgumentParser *this, PStringBase<char> *ErrorText)
{
  ArgumentParser *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_ErrorText.m_charbuffer;
  if ( v3 != ErrorText->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = ErrorText->m_charbuffer;
    v2->m_ErrorText.m_charbuffer = ErrorText->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00407AD0) --------------------------------------------------------  // acclient.c:67095
void *__thiscall CommandLineArg::vector_deleting_destructor(CommandLineArg *this, unsigned int a2)
{
  char v2; // bl@1
  CommandLineArg *v3; // esi@1
  unsigned int v4; // eax@2
  char *v5; // edi@2
  int v6; // ecx@2
  int v7; // eax@2
  int v8; // ecx@2
  int v9; // edi@3
  int v10; // ebx@3
  int v11; // esi@4
  int v12; // esi@4
  int v13; // esi@7
  void *result; // eax@14
  int v15; // [sp+8h] [bp-4h]@2

  v2 = a2;
  v3 = this;
  if ( a2 & 2 )
  {
    v4 = this[-1].UserData;
    v5 = (char *)&this[-1].UserData;
    v6 = 7 * v4;
    v7 = v4 - 1;
    v15 = (int)&v3[-1].UserData;
    v8 = (int)&v3[4 * v6 / 0x1Cu].ArgType;
    if ( v7 >= 0 )
    {
      v9 = v8 + 8;
      v10 = v7 + 1;
      do
      {
        v11 = *(_DWORD *)(v9 - 24);
        v9 -= 28;
        v12 = v11 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        v13 = *(_DWORD *)v9 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v13 + 4)) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        --v10;
      }
      while ( v10 );
      v2 = a2;
      v5 = (char *)v15;
    }
    if ( v2 & 1 )
      operator delete[](v5);
    result = v5;
  }
  else
  {
    CommandLineArg::~CommandLineArg(this);
    if ( a2 & 1 )
      operator delete(v3);
    result = v3;
  }
  return result;
}

//----- (00407B90) --------------------------------------------------------  // acclient.c:67157
void __thiscall PStringBase<unsigned short>::set(PStringBase<unsigned short> *this, const unsigned __int16 *str)
{
  PStringBase<unsigned short> *v2; // esi@1
  unsigned int v3; // edi@3
  PStringBase<unsigned short> v4; // eax@3
  int v5; // ebx@6
  PSRefBufferCharData<unsigned short> *v6; // ecx@12
  int v7; // edi@13
  wchar_t *v8; // edx@16

  v2 = this;
  if ( str && *str )
  {
    v3 = _wcslen(str);
    v4.m_charbuffer = v2->m_charbuffer;
    if ( *(_DWORD *)&v2->m_charbuffer[-1].m_data[8] != 1 || *(_DWORD *)&v4.m_charbuffer[-1].m_data[10] <= v3 )
    {
      v5 = (int)&v4.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v4.m_charbuffer[-1].m_data[8]) )
      {
        if ( v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      }
      PStringBase<unsigned short>::allocate_ref_buffer(v2, v3);
    }
    else
    {
      *(_DWORD *)&v4.m_charbuffer[-1].m_data[12] = -1;
      *(_DWORD *)&v2->m_charbuffer[-1].m_data[14] = v3 + 1;
    }
    _wcsncpy(v2->m_charbuffer->m_data, str, v3 + 1);
  }
  else
  {
    v6 = this->m_charbuffer;
    if ( (wchar_t *)(v2->m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 ? v2->m_charbuffer : 0) != PStringBase<unsigned short>::s_NullBuffer )
    {
      v7 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = PStringBase<unsigned short>::s_NullBuffer;
      v2->m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)v8 - 4);
    }
  }
}

//----- (00407C60) --------------------------------------------------------  // acclient.c:67205
bool __thiscall SmartArray<Logger::ILoggingOutputHandler *,1>::grow(SmartArray<unsigned short *,1> *this, unsigned int i_nSize)
{
  SmartArray<unsigned short *,1> *v2; // esi@1
  bool result; // al@5
  void *v4; // ebx@6
  int i; // eax@8

  v2 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<unsigned short *,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + i + 1) = v2->m_data[i + 1] )
          --i;
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (wchar_t **)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00407D00) --------------------------------------------------------  // acclient.c:67249
bool __thiscall SmartArray<PStringBase<unsigned short>,1>::grow(SmartArray<PStringBase<unsigned short>,1> *this, unsigned int i_nSize)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // esi@1
  bool result; // al@5
  void *v4; // eax@6
  int v5; // ebx@7
  int i; // edi@9

  v2 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<PStringBase<unsigned short>,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize + 4);
    if ( v4
      && (v5 = (int)((char *)v4 + 4),
          *(_DWORD *)v4 = i_nSize,
          vector_constructor_iterator(
            (char *)v4 + 4,
            4u,
            i_nSize,
            (void *(__thiscall *)(void *))PStringBase<unsigned short>::PStringBase<unsigned short>),
          v5) )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; --i )
          PStringBase<unsigned short>::operator=(
            (PStringBase<unsigned short> *)(4 * i + v5),
            (const unsigned __int16 *)&v2->m_data[i]);
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        {
          if ( v2->m_data )
            PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)v2->m_data, 3u);
        }
      }
      v2->m_data = (PStringBase<unsigned short> *)v5;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00407DD0) --------------------------------------------------------  // acclient.c:67307
bool __thiscall SmartArray<PStringBase<unsigned short>,1>::SetNElements(SmartArray<PStringBase<unsigned short>,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<PStringBase<unsigned short>,1> *v3; // ebp@1
  const unsigned int v4; // esi@1
  unsigned int v5; // eax@3
  bool result; // al@5
  wchar_t *v7; // esi@8
  volatile LONG *v8; // edi@8
  PSRefBufferCharData<unsigned short> *v9; // eax@8
  int v10; // ebx@8
  int v11; // ebp@9
  int v12; // esi@13
  SmartArray<PStringBase<unsigned short>,1> *v13; // [sp+8h] [bp-4h]@1
  const unsigned int i_bGrowExactlya; // [sp+14h] [bp+8h]@7

  v3 = this;
  v4 = i_nSize;
  v13 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    i_bGrowExactlya = i_nSize;
    if ( i_nSize < this->m_num )
    {
      do
      {
        v7 = PStringBase<unsigned short>::s_NullBuffer;
        v8 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        v9 = v3->m_data[i_bGrowExactlya].m_charbuffer;
        v10 = (int)&v3->m_data[i_bGrowExactlya];
        if ( (wchar_t *)v9 != v7 )
        {
          v11 = (int)&v9[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&v9[-1].m_data[8]) && v11 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
          *(_DWORD *)v10 = v7;
          InterlockedIncrement(v8);
          v3 = v13;
        }
        v12 = (int)(v7 - 10);
        if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        ++i_bGrowExactlya;
      }
      while ( i_bGrowExactlya < v3->m_num );
      v4 = i_nSize;
    }
    goto LABEL_18;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<char *,1>::get_new_size(i_nSize);
  result = SmartArray<PStringBase<unsigned short>,1>::grow(v3, v5);
  if ( result )
  {
LABEL_18:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}

//----- (00407EB0) --------------------------------------------------------  // acclient.c:67371
void __thiscall PStringBase<char>::break_reference(PStringBase<char> *this)
{
  void **v1; // esi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // ebx@3

  v1 = (void **)this;
  v2 = this->m_charbuffer;
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[0] == 1 )
  {
    *(_DWORD *)&v2[-1].m_data[8] = -1;
  }
  else
  {
    v3 = (int)&v2[-2].m_data[12];
    PStringBase<char>::allocate_ref_buffer(this, *(_DWORD *)&v2[-1].m_data[12] - 1);
    qmemcpy(*v1, (const void *)(v3 + 20), *((_DWORD *)*v1 - 1));
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (00407F10) --------------------------------------------------------  // acclient.c:67397
void __thiscall SmartArray<CommandLineArg,1>::Reset(SmartArray<CommandLineArg,1> *this)
{
  SmartArray<CommandLineArg,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // esi@8
  int v7; // esi@11
  int v8; // [sp+8h] [bp-20h]@7
  int v9; // [sp+Ch] [bp-1Ch]@8
  PSRefBufferCharData<char> *v10; // [sp+14h] [bp-14h]@8
  PSRefBufferCharData<char> *v11; // [sp+18h] [bp-10h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      CommandLineArg::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v8 = v4 + 1;
      do
      {
        v10 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v9 = 0;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v11 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        CommandLineArg::operator=((int)&v1->m_data[v5].ArgType, (int)&v9);
        v6 = (int)&v11[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v11[-1]) && v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
        v7 = (int)&v10[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v7 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        --v5;
        --v8;
      }
      while ( v8 );
    }
  }
}

//----- (00408010) --------------------------------------------------------  // acclient.c:67452
bool __thiscall SmartArray<PStringBase<char>,1>::grow(SmartArray<PStringBase<char>,1> *this, unsigned int i_nSize)
{
  SmartArray<PStringBase<char>,1> *v2; // esi@1
  bool result; // al@5
  void *v4; // eax@6
  int v5; // ebx@7
  int i; // edi@9

  v2 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<PStringBase<char>,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize + 4);
    if ( v4
      && (v5 = (int)((char *)v4 + 4),
          *(_DWORD *)v4 = i_nSize,
          vector_constructor_iterator(
            (char *)v4 + 4,
            4u,
            i_nSize,
            (void *(__thiscall *)(void *))PStringBase<char>::PStringBase<char>),
          v5) )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; --i )
          PStringBase<unsigned short>::operator=(
            (PStringBase<unsigned short> *)(4 * i + v5),
            (const unsigned __int16 *)&v2->m_data[i]);
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        {
          if ( v2->m_data )
            PStringBase<unsigned short>::vector_deleting_destructor(v2->m_data, 3u);
        }
      }
      v2->m_data = (PStringBase<char> *)v5;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (004080E0) --------------------------------------------------------  // acclient.c:67510
void __thiscall PStringBase<unsigned short>::break_reference(PStringBase<unsigned short> *this)
{
  void **v1; // esi@1
  PSRefBufferCharData<unsigned short> *v2; // eax@1
  int v3; // ebx@3

  v1 = (void **)this;
  v2 = this->m_charbuffer;
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[8] == 1 )
  {
    *(_DWORD *)&v2[-1].m_data[12] = -1;
  }
  else
  {
    v3 = (int)&v2[-1].m_data[6];
    PStringBase<unsigned short>::allocate_ref_buffer(this, *(_DWORD *)&v2[-1].m_data[14] - 1);
    qmemcpy(*v1, (const void *)(v3 + 20), 2 * *((_DWORD *)*v1 - 1));
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (00408140) --------------------------------------------------------  // acclient.c:67536
char __stdcall ArgumentParser::EvaluateCommandLineArg(CommandLineArg *ArgData, PStringBase<char> *param)
{
  char v3; // bl@1
  void *v4; // ecx@2
  char result; // al@3
  void *v6; // ecx@4
  void *v7; // esi@6
  PStringBase<unsigned short> *v8; // esi@8
  void *v9; // eax@10
  void *v10; // eax@13
  void *v11; // eax@16
  void *v12; // esi@19

  v3 = 1;
  switch ( ArgData->ArgType & 0xFF )
  {
    case 0x11:
      v4 = ArgData->VariableToModify;
      if ( !v4 )
        goto LABEL_23;
      result = 1;
      *(_DWORD *)v4 = ArgData->ValueToStore;
      break;
    case 0x71:
      v6 = ArgData->VariableToModify;
      if ( !v6 )
        goto LABEL_23;
      *(_BYTE *)v6 = ArgData->ValueToStore != 0;
      result = 1;
      break;
    case 0x22:
      v7 = ArgData->VariableToModify;
      if ( !v7 )
        goto LABEL_23;
      *(_DWORD *)v7 = _strtol(param->m_charbuffer->m_data, 0, 0);
      result = 1;
      break;
    case 0x32:
      v8 = (PStringBase<unsigned short> *)ArgData->VariableToModify;
      if ( !v8 )
        goto LABEL_23;
      param = (PStringBase<char> *)param->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&param[-4]);
      PStringBase<unsigned short>::operator=(v8, (const unsigned __int16 *)&param);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&param);
      result = 1;
      break;
    case 0x42:
      v9 = ArgData->VariableToModify;
      if ( !v9 || _sscanf(param->m_charbuffer->m_data, "%f", v9) == 1 )
        goto LABEL_23;
      result = 0;
      break;
    case 0x52:
      v10 = ArgData->VariableToModify;
      if ( !v10 || _sscanf(param->m_charbuffer->m_data, "%lf", v10) == 1 )
        goto LABEL_23;
      result = 0;
      break;
    case 0x62:
      v11 = ArgData->VariableToModify;
      if ( !v11 || _sscanf(param->m_charbuffer->m_data, "%hu", v11) == 1 )
        goto LABEL_23;
      result = 0;
      break;
    case 0x82:
      v12 = ArgData->VariableToModify;
      if ( v12 )
      {
        if ( _sscanf(param->m_charbuffer->m_data, "%d", &param) != 1 )
          v3 = 0;
        *(_BYTE *)v12 = param != 0;
      }
      goto LABEL_23;
    default:
LABEL_23:
      result = v3;
      break;
  }
  return result;
}

//----- (00408360) --------------------------------------------------------  // acclient.c:67619
IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *__thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::find_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this, IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *result, CaseInsensitiveStringBase<PStringBase<unsigned short> > *_key)
{
  const wchar_t **v3; // edi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v4; // ebx@1
  unsigned int v5; // esi@1
  unsigned int v6; // edx@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v7; // eax@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v8; // esi@1
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v9; // edx@1
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v10; // eax@5
  CaseInsensitiveStringBase<PStringBase<unsigned short> > *_keya; // [sp+14h] [bp+8h]@1

  v3 = (const wchar_t **)_key;
  v4 = this;
  v5 = this->m_numBuckets;
  v6 = CaseInsensitiveStringBase<PStringBase<unsigned short>>::case_insensitive_hash(_key) % v5;
  v7 = v4->m_buckets;
  v8 = v7[v6];
  v9 = &v7[v6];
  _keya = (CaseInsensitiveStringBase<PStringBase<unsigned short> > *)v9;
  if ( v8 )
  {
    do
    {
      if ( !__wcsicmp(v8->m_hashKey.m_charbuffer->m_data, *v3) )
        break;
      v8 = v8->m_hashNext;
    }
    while ( v8 );
    v9 = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)_keya;
  }
  v10 = result;
  result->m_currElement = v8;
  result->m_currHashTable = v4;
  result->m_currBucket = v9;
  return v10;
}

//----- (004083C0) --------------------------------------------------------  // acclient.c:67658
void PStringBase<char>::PStringBase<char>(PStringBase<char> *this, _Formatted __formal, const char *fmt, ...)
{
  int v3; // esi@1
  va_list va; // [sp+18h] [bp+10h]@1

  va_start(va, fmt);
  v3 = __vscprintf(fmt, va);
  PStringBase<char>::allocate_ref_buffer(this, v3);
  __vsnprintf(this->m_charbuffer->m_data, v3 + 1, fmt, va);
}

//----- (00408410) --------------------------------------------------------  // acclient.c:67670
PStringBase<unsigned short> *__thiscall PStringBase<unsigned short>::operator+(PStringBase<unsigned short> *this, PStringBase<unsigned short> *result, PStringBase<unsigned short> *rhs)
{
  wchar_t *v3; // esi@1
  const wchar_t **v4; // edi@1
  int v5; // esi@1
  PSRefBufferCharData<unsigned short> *v6; // esi@4
  int v7; // esi@4
  PStringBase<unsigned short> retstr; // [sp+4h] [bp-4h]@1

  v3 = PStringBase<unsigned short>::s_NullBuffer;
  v4 = (const wchar_t **)this;
  retstr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  v5 = (int)(v3 - 10);
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  PStringBase<unsigned short>::allocate_ref_buffer(
    &retstr,
    *(_DWORD *)&rhs->m_charbuffer[-1].m_data[14] + *((_DWORD *)*v4 - 1) - 2);
  v6 = retstr.m_charbuffer;
  _wcscpy(retstr.m_charbuffer->m_data, *v4);
  _wcscpy((wchar_t *)v6 + *((_DWORD *)*v4 - 1) - 1, rhs->m_charbuffer->m_data);
  result->m_charbuffer = v6;
  InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
  v7 = (int)&v6[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return result;
}

//----- (004084C0) --------------------------------------------------------  // acclient.c:67701
void __thiscall PStringBase<char>::SetAtIndex(PStringBase<char> *this, unsigned int nIndex, const char zCharacter)
{
  PStringBase<char> *v3; // edi@1
  PSRefBufferCharData<char> *v4; // eax@1
  unsigned int v5; // ecx@1
  unsigned int v6; // ebx@3

  v3 = this;
  v4 = this->m_charbuffer;
  v5 = *(_DWORD *)&this->m_charbuffer[-1].m_data[12];
  if ( nIndex < v5 && v4->m_data[nIndex] != zCharacter )
  {
    v6 = v5 - 1;
    if ( nIndex == v5 - 1 )
    {
      PStringBase<char>::append_n_chars(v3, &zCharacter, 1u);
    }
    else
    {
      PStringBase<char>::break_reference(v3);
      v3->m_charbuffer->m_data[nIndex] = zCharacter;
      if ( !zCharacter && v6 > nIndex )
        *(_DWORD *)&v3->m_charbuffer[-1].m_data[12] = nIndex + 1;
    }
  }
}

//----- (00408520) --------------------------------------------------------  // acclient.c:67729
PStringBase<char> *__thiscall PStringBase<char>::operator+=(PStringBase<char> *this, PStringBase<char> *rhs)
{
  PStringBase<char> *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  v3 = *(_DWORD *)&rhs->m_charbuffer[-1].m_data[12];
  if ( v3 != 1 )
    PStringBase<char>::append_n_chars(v2, rhs->m_charbuffer->m_data, v3 - 1);
  return v2;
}

//----- (00408550) --------------------------------------------------------  // acclient.c:67742
PStringBase<unsigned short> *__thiscall PStringBase<unsigned short>::operator+=(PStringBase<unsigned short> *this, PStringBase<unsigned short> *rhs)
{
  PStringBase<unsigned short> *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  v3 = *(_DWORD *)&rhs->m_charbuffer[-1].m_data[14];
  if ( v3 != 1 )
    PStringBase<unsigned short>::append_n_chars(v2, rhs->m_charbuffer->m_data, v3 - 1);
  return v2;
}

//----- (00408580) --------------------------------------------------------  // acclient.c:67755
bool __thiscall SmartArray<CommandLineArg,1>::grow(SmartArray<CommandLineArg,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<CommandLineArg,1> *v3; // edi@1
  bool result; // al@5
  void *v5; // eax@6
  int v6; // ebx@7
  int v7; // eax@9
  int v8; // esi@10
  unsigned int i_nSizea; // [sp+Ch] [bp+4h]@10

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<CommandLineArg,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](28 * i_nSize + 4);
    if ( v5
      && (v6 = (int)((char *)v5 + 4),
          *(_DWORD *)v5 = i_nSize,
          vector_constructor_iterator(
            (char *)v5 + 4,
            0x1Cu,
            i_nSize,
            (void *(__thiscall *)(void *))CommandLineArg::CommandLineArg),
          v6) )
    {
      if ( v3->m_data )
      {
        v7 = v3->m_num - 1;
        if ( v7 >= 0 )
        {
          v8 = v7;
          i_nSizea = v3->m_num;
          do
          {
            CommandLineArg::operator=(v8 * 28 + v6, (int)&v3->m_data[v8].ArgType);
            --v8;
            --i_nSizea;
          }
          while ( i_nSizea );
        }
        if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
        {
          if ( v3->m_data )
            CommandLineArg::vector_deleting_destructor(v3->m_data, 3u);
        }
      }
      v3->m_data = (CommandLineArg *)v6;
      v3->m_sizeAndDeallocate = v2 | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (00408660) --------------------------------------------------------  // acclient.c:67826
bool __thiscall SmartArray<PStringBase<char>,1>::SetNElements(SmartArray<PStringBase<char>,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<PStringBase<char>,1> *v3; // ebp@1
  const unsigned int v4; // esi@1
  unsigned int v5; // eax@3
  bool result; // al@5
  PSRefBufferCharData<char> *v7; // esi@8
  volatile LONG *v8; // edi@8
  PSRefBufferCharData<char> *v9; // eax@8
  int v10; // ebx@8
  int v11; // ebp@9
  int v12; // esi@13
  SmartArray<PStringBase<char>,1> *v13; // [sp+8h] [bp-4h]@1
  const unsigned int i_bGrowExactlya; // [sp+14h] [bp+8h]@7

  v3 = this;
  v4 = i_nSize;
  v13 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    i_bGrowExactlya = i_nSize;
    if ( i_nSize < this->m_num )
    {
      do
      {
        v7 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        v8 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v9 = v3->m_data[i_bGrowExactlya].m_charbuffer;
        v10 = (int)&v3->m_data[i_bGrowExactlya];
        if ( v9 != v7 )
        {
          v11 = (int)&v9[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v11 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
          *(_DWORD *)v10 = v7;
          InterlockedIncrement(v8);
          v3 = v13;
        }
        v12 = (int)&v7[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v12 + 4)) && v12 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
        ++i_bGrowExactlya;
      }
      while ( i_bGrowExactlya < v3->m_num );
      v4 = i_nSize;
    }
    goto LABEL_18;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<char *,1>::get_new_size(i_nSize);
  result = SmartArray<PStringBase<char>,1>::grow(v3, v5);
  if ( result )
  {
LABEL_18:
    v3->m_num = v4;
    result = 1;
  }
  return result;
}

//----- (00408740) --------------------------------------------------------  // acclient.c:67890
void __thiscall PStringBase<unsigned short>::SetAtIndex(PStringBase<unsigned short> *this, unsigned int nIndex, const unsigned __int16 zCharacter)
{
  PStringBase<unsigned short> *v3; // edi@1
  PSRefBufferCharData<unsigned short> *v4; // eax@1
  unsigned int v5; // ecx@1
  unsigned int v6; // ebx@3

  v3 = this;
  v4 = this->m_charbuffer;
  v5 = *(_DWORD *)&this->m_charbuffer[-1].m_data[14];
  if ( nIndex < v5 && v4->m_data[nIndex] != zCharacter )
  {
    v6 = v5 - 1;
    if ( nIndex == v5 - 1 )
    {
      PStringBase<unsigned short>::append_n_chars(v3, &zCharacter, 1u);
    }
    else
    {
      PStringBase<unsigned short>::break_reference(v3);
      v3->m_charbuffer->m_data[nIndex] = zCharacter;
      if ( !zCharacter && v6 > nIndex )
        *(_DWORD *)&v3->m_charbuffer[-1].m_data[14] = nIndex + 1;
    }
  }
}

//----- (004087B0) --------------------------------------------------------  // acclient.c:67918
int __thiscall ArgumentParser::AppendAndWordWrap(ArgumentParser *this, const char *Text, int nIndent, int iCursorX, ArgumentParser::OutputTextType i_eFormattingHint)
{
  ArgumentParser *v5; // edi@1
  const char *v6; // ebx@3
  const char *v7; // ebp@3
  int v8; // esi@3
  int v9; // eax@5
  int v10; // ebx@8
  int v11; // eax@8
  int v12; // edx@8
  char v13; // cl@9
  int v14; // ecx@14
  bool v15; // zf@14
  const char v16; // al@16
  ArgumentParserVtbl *v17; // eax@25
  ArgumentParserVtbl *v18; // eax@31
  int v19; // esi@33
  bool bInWord; // [sp+1Fh] [bp-119h]@3
  int x; // [sp+20h] [bp-118h]@3
  char str[4]; // [sp+24h] [bp-114h]@3
  int nRightMargin; // [sp+28h] [bp-110h]@1
  int v25; // [sp+2Ch] [bp-10Ch]@4
  const char *p; // [sp+30h] [bp-108h]@3
  unsigned int v27; // [sp+34h] [bp-104h]@5
  char Out[256]; // [sp+38h] [bp-100h]@25

  v5 = this;
  nRightMargin = ((int (*)(void))this->vfptr->GetCharactersToWrapUsageTo)();
  if ( nRightMargin < 0 )
    nRightMargin = 0x7FFFFFFF;
  x = (int)PStringBase<char>::s_NullBuffer.m_charbuffer;
  v6 = Text - 1;
  v7 = 0;
  bInWord = 0;
  p = Text - 1;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  str[0] = 10;
  PStringBase<char>::append_n_chars((PStringBase<char> *)&x, str, 1u);
  v8 = x;
  if ( nIndent > 0 )
  {
    v25 = nIndent;
    do
    {
      str[0] = 32;
      v27 = *(_DWORD *)(v8 - 4);
      v9 = v27 + 1;
      if ( *(_DWORD *)(v8 - 16) != 1 || (unsigned int)v9 > *(_DWORD *)(v8 - 12) )
      {
        v10 = v8 - 20;
        PStringBase<char>::allocate_ref_buffer((PStringBase<char> *)&x, v27);
        v8 = x;
        v11 = v10 + 20;
        v12 = x - (v10 + 20);
        do
        {
          v13 = *(_BYTE *)v11;
          *(_BYTE *)(v12 + v11) = *(_BYTE *)v11;
          ++v11;
        }
        while ( v13 );
        if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
        v6 = p;
      }
      else
      {
        *(_DWORD *)(v8 - 4) = v9;
        *(_DWORD *)(v8 - 8) = -1;
      }
      _strncpy((char *)(v27 + v8 - 1), str, 1u);
      v14 = *(_DWORD *)(v8 - 4);
      v15 = v25-- == 1;
      *(_BYTE *)(v14 + v8 - 1) = 0;
    }
    while ( !v15 );
  }
  x = iCursorX;
  do
  {
    v16 = (v6++)[1];
    if ( !v16 || _strchr(" \t\n", v16) )
    {
      if ( bInWord )
      {
        if ( (signed int)&v6[x - (_DWORD)v7] >= nRightMargin )
        {
          v5->vfptr->AppendOutputText(v5, (const char *)v8, 0);
          x = nIndent;
        }
        if ( v7 < v6 )
        {
          x += v6 - v7;
          do
          {
            v17 = v5->vfptr;
            Out[0] = *v7;
            Out[1] = 0;
            v17->AppendOutputText(v5, Out, i_eFormattingHint);
            ++v7;
          }
          while ( v7 < v6 );
        }
        bInWord = 0;
      }
      if ( *v6 == 10 )
      {
        v5->vfptr->AppendOutputText(v5, (const char *)v8, 0);
        x = nIndent;
      }
      else
      {
        if ( !*v6 )
          break;
        if ( x < nRightMargin - 1 )
        {
          Out[0] = *v6;
          v18 = v5->vfptr;
          Out[1] = 0;
          v18->AppendOutputText(v5, Out, i_eFormattingHint);
          ++x;
        }
      }
    }
    else if ( !bInWord )
    {
      bInWord = 1;
      v7 = v6;
    }
  }
  while ( *v6 );
  v19 = v8 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v19 + 4)) && v19 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v19)(v19, 1);
  return x;
}

//----- (00408A00) --------------------------------------------------------  // acclient.c:68056
char __thiscall ArgumentParser::IsCommandLineArgument(ArgumentParser *this, PStringBase<unsigned short> *Token, bool bLookingForParameter)
{
  PStringBase<unsigned short> *v3; // ebx@1
  int *v4; // eax@1
  ArgumentParser *v5; // esi@1
  int v6; // ecx@1
  PSRefBufferCharData<unsigned short> *v7; // edx@1
  const char *v9; // eax@9
  PStringBase<unsigned short> *v10; // eax@11
  const unsigned __int16 *v11; // eax@11
  int v12; // esi@11
  PStringBase<unsigned short> *v13; // esi@14

  v3 = Token;
  v4 = (int *)Token->m_charbuffer;
  v5 = this;
  v6 = *(_DWORD *)&Token->m_charbuffer[-1].m_data[14];
  v7 = (PSRefBufferCharData<unsigned short> *)((char *)Token->m_charbuffer + 2 * v6 - 2);
  if ( v6 )
    v7 = Token->m_charbuffer;
  if ( !v7->m_data[0] )
    return 0;
  if ( !v6 )
    v4 = (int *)((char *)v4 - 2);
  if ( _strchr(v5->m_CmdChars.m_charbuffer->m_data, *(_WORD *)v4) )
    return 1;
  if ( !bLookingForParameter )
  {
    v9 = v5->m_CmdChars.m_charbuffer->m_data;
    if ( *((_DWORD *)v9 - 1) == 1 || _strchr(v9, 32) )
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&Token, L" ");
      v11 = (const unsigned __int16 *)PStringBase<unsigned short>::operator+(
                                        v10,
                                        (PStringBase<unsigned short> *)&bLookingForParameter,
                                        v3);
      PStringBase<unsigned short>::operator=(v3, v11);
      v12 = bLookingForParameter - 20;
      if ( !InterlockedDecrement((volatile LONG *)(bLookingForParameter - 20 + 4)) && v12 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
      v13 = Token - 5;
      if ( !InterlockedDecrement((volatile LONG *)&Token[-4]) )
      {
        if ( v13 )
          (*(void (__thiscall **)(PStringBase<unsigned short> *, signed int))&v13->m_charbuffer->m_data[0])(v13, 1);
      }
      return 1;
    }
  }
  return 0;
}

//----- (00408AE0) --------------------------------------------------------  // acclient.c:68109
bool __thiscall PStringBase<char>::allocate(PStringBase<char> *this, unsigned int num_chars)
{
  PStringBase<char> *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@1
  char *v4; // edi@1
  int v5; // ecx@3
  int v6; // edi@5
  bool result; // al@6

  v2 = this;
  v3 = this->m_charbuffer;
  v4 = &this->m_charbuffer[-2].m_data[12];
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[0] != 1 || *((_DWORD *)v4 + 4) < num_chars + 1 )
  {
    if ( PStringBase<char>::allocate_ref_buffer(this, num_chars) )
    {
      if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
      *(_DWORD *)&v2->m_charbuffer[-1].m_data[12] = 1;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    LOBYTE(num_chars) = 0;
    v5 = *(_DWORD *)&v3[-1].m_data[12];
    if ( v5 && v3->m_data[0] )
    {
      v6 = v5 - 1;
      if ( v5 == 1 )
      {
        PStringBase<char>::append_n_chars(v2, (const char *)&num_chars, 1u);
        return 1;
      }
      PStringBase<char>::break_reference(v2);
      v2->m_charbuffer->m_data[0] = num_chars;
      if ( !(_BYTE)num_chars )
      {
        if ( v6 )
          *(_DWORD *)&v2->m_charbuffer[-1].m_data[12] = 1;
      }
    }
    result = 1;
  }
  return result;
}

//----- (00408B90) --------------------------------------------------------  // acclient.c:68161
bool __thiscall SmartArray<PStringBase<unsigned short>,1>::AddToEnd(SmartArray<PStringBase<unsigned short>,1> *this, PStringBase<unsigned short> *i_rData)
{
  SmartArray<PStringBase<unsigned short>,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  bool result; // al@2
  int v6; // edi@3
  PSRefBufferCharData<unsigned short> *v7; // eax@3
  int v8; // ebx@4
  PSRefBufferCharData<unsigned short> *v9; // eax@7

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<char *,1>::get_new_size(v3 + 1),
        (result = SmartArray<PStringBase<unsigned short>,1>::grow(v2, v4)) != 0) )
  {
    v6 = (int)&v2->m_data[v2->m_num];
    v7 = *(PSRefBufferCharData<unsigned short> **)v6;
    if ( *(PSRefBufferCharData<unsigned short> **)v6 != i_rData->m_charbuffer )
    {
      v8 = (int)&v7[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1].m_data[8]) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
      v9 = i_rData->m_charbuffer;
      *(_DWORD *)v6 = i_rData->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v9[-1].m_data[8]);
    }
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (00408C10) --------------------------------------------------------  // acclient.c:68199
bool __thiscall PStringBase<unsigned short>::allocate(PStringBase<unsigned short> *this, unsigned int num_chars)
{
  PStringBase<unsigned short> *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  char *v4; // edi@1
  int v5; // ecx@3
  int v6; // edi@5
  bool result; // al@6

  v2 = this;
  v3 = this->m_charbuffer;
  v4 = (char *)&this->m_charbuffer[-1].m_data[6];
  if ( *(_DWORD *)&this->m_charbuffer[-1].m_data[8] != 1 || *((_DWORD *)v4 + 4) < num_chars + 1 )
  {
    if ( PStringBase<unsigned short>::allocate_ref_buffer(this, num_chars) )
    {
      if ( !InterlockedDecrement((volatile LONG *)v4 + 1) && v4 )
        (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
      *(_DWORD *)&v2->m_charbuffer[-1].m_data[14] = 1;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    num_chars = 0;
    v5 = *(_DWORD *)&v3[-1].m_data[14];
    if ( v5 && v3->m_data[0] )
    {
      v6 = v5 - 1;
      if ( v5 == 1 )
      {
        PStringBase<unsigned short>::append_n_chars(v2, (const unsigned __int16 *)&num_chars, 1u);
        return 1;
      }
      PStringBase<unsigned short>::break_reference(v2);
      v2->m_charbuffer->m_data[0] = num_chars;
      if ( !(_WORD)num_chars )
      {
        if ( v6 )
          *(_DWORD *)&v2->m_charbuffer[-1].m_data[14] = 1;
      }
    }
    result = 1;
  }
  return result;
}

//----- (00408CD0) --------------------------------------------------------  // acclient.c:68251
int __thiscall ArgumentParser::CommandLineArgList::FindByShortCmd(ArgumentParser::CommandLineArgList *this, wchar_t ShortCmd)
{
  HashTableData<unsigned short,long> *v2; // edx@1
  int result; // eax@4

  v2 = this->m_ShortNamesHash.m_intrusiveTable.m_buckets[ShortCmd % this->m_ShortNamesHash.m_intrusiveTable.m_numBuckets];
  if ( !v2 )
    goto LABEL_4;
  while ( v2->m_hashKey != ShortCmd )
  {
    v2 = v2->m_hashNext;
    if ( !v2 )
      goto LABEL_4;
  }
  if ( v2 )
    result = v2->m_data;
  else
LABEL_4:
    result = -1;
  return result;
}

//----- (00408D20) --------------------------------------------------------  // acclient.c:68274
PStringBase<char> *__thiscall PStringBase<unsigned short>::to_spstring(PStringBase<unsigned short> *this, PStringBase<char> *result, const unsigned __int16 i_targetCodePage)
{
  PSRefBufferCharData<char> *v3; // esi@1
  PStringBase<unsigned short> *v4; // ebx@1
  PSRefBufferCharData<char> *v5; // edi@1
  const unsigned __int16 *v6; // ecx@1
  int v7; // esi@2
  const char *v9; // ebp@6
  int *v10; // ebx@6
  int v11; // eax@16
  int v12; // esi@16
  unsigned int v13; // ebp@19
  signed int i; // edi@19
  const unsigned __int16 *v15; // eax@20
  unsigned int v16; // ecx@20
  int v17; // eax@21
  unsigned __int16 v18; // bx@23
  PSRefBufferCharData<char> *v19; // esi@24
  int v20; // eax@24
  int v21; // esi@26
  char *v22; // esi@31
  int v23; // edi@31
  int v24; // esi@31
  const unsigned __int16 *v25; // eax@34
  int v26; // ecx@34
  char *v27; // esi@34
  int v28; // eax@34
  DWORD v29; // ST10_4@35
  DWORD v30; // eax@35
  int v31; // esi@37
  char *v32; // [sp+0h] [bp-4Ch]@35
  int v33; // [sp+4h] [bp-48h]@34
  volatile LONG *v34; // [sp+Ch] [bp-40h]@24
  int v35; // [sp+10h] [bp-3Ch]@37
  char *v36; // [sp+20h] [bp-2Ch]@19
  signed int v37; // [sp+24h] [bp-28h]@17
  const unsigned __int16 **v38; // [sp+28h] [bp-24h]@19
  volatile LONG *v39; // [sp+2Ch] [bp-20h]@2
  int v40; // [sp+30h] [bp-1Ch]@31
  PSRefBufferCharData<char> *v41; // [sp+34h] [bp-18h]@24
  PStringBase<char> ret_str; // [sp+40h] [bp-Ch]@1
  int fCouldNotConvertACharacter; // [sp+44h] [bp-8h]@6
  PStringBase<unsigned short> *v44; // [sp+48h] [bp-4h]@1

  v3 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v4 = this;
  v5 = PStringBase<char>::s_NullBuffer.m_charbuffer - 1;
  v44 = this;
  ret_str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v6 = v4->m_charbuffer->m_data;
  if ( *(_DWORD *)&v4->m_charbuffer[-1].m_data[14] != 1 )
  {
    fCouldNotConvertACharacter = 0;
    v9 = "?";
    v10 = &fCouldNotConvertACharacter;
    if ( (signed int)i_targetCodePage > 52936 )
    {
      if ( (signed int)i_targetCodePage > 57011 )
      {
        if ( (signed int)i_targetCodePage < 65000 || (signed int)i_targetCodePage > 65001 )
          goto LABEL_16;
      }
      else if ( (signed int)i_targetCodePage < 57002 && i_targetCodePage != 54936 )
      {
        goto LABEL_16;
      }
    }
    else if ( i_targetCodePage != 52936 )
    {
      switch ( i_targetCodePage )
      {
        case 0xC42Cu:
        case 0xC42Du:
        case 0xC42Eu:
        case 0xC431u:
        case 0xC433u:
        case 0xC435u:
          goto $L62521;
        default:
          break;
      }
LABEL_16:
      v11 = WideCharToMultiByte(i_targetCodePage, 0, v6, *((_DWORD *)v6 - 1), 0, 0, v9, v10);
      v12 = v11;
      if ( v11 )
      {
        if ( !v37 )
        {
          PStringBase<char>::allocate_ref_buffer((PStringBase<char> *)&v36, v11);
          v25 = *v38;
          v26 = *((_DWORD *)*v38 - 1);
          v33 = v12;
          v27 = v36;
          v28 = WideCharToMultiByte(i_targetCodePage, 0, v25, v26, v36, v33, v9, v10);
          if ( v28 )
          {
            *((_DWORD *)v27 - 1) = v28;
          }
          else
          {
            v29 = GetLastError();
            v30 = GetLastError();
            PStringBase<char>::sprintf(
              (PStringBase<char> *)&v32,
              "Failed conversion to codepage %hu! GetLastError %d (0x%08x)\n",
              i_targetCodePage,
              v30,
              v29);
            v27 = v32;
          }
          v23 = v35;
          *(_DWORD *)v35 = v27;
          InterlockedIncrement((volatile LONG *)v27 - 4);
          v31 = (int)(v27 - 20);
          if ( !InterlockedDecrement((volatile LONG *)(v31 + 4)) && v31 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v31)(v31, 1);
          return (PStringBase<char> *)v23;
        }
      }
      else
      {
        v37 = 1;
      }
      v13 = *((_DWORD *)*v38 - 1) - 1;
      PStringBase<char>::allocate((PStringBase<char> *)&v36, v13);
      for ( i = 0; i < (signed int)v13; ++i )
      {
        v15 = *v38;
        v16 = *((_DWORD *)*v38 - 1);
        if ( i < v16 )
          v17 = (int)&v15[i];
        else
          v17 = (int)&v15[v16 - 1];
        v18 = *(_WORD *)v17;
        if ( *(_WORD *)v17 <= 0x7Fu )
        {
          LOBYTE(v41) = *(_WORD *)v17;
          PStringBase<char>::append_n_chars((PStringBase<char> *)&v36, (const char *)&v41, 1u);
        }
        else
        {
          v41 = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          v34 = (volatile LONG *)v18;
          PStringBase<char>::sprintf((PStringBase<char> *)&v41, "<%04x>", v18);
          v19 = v41;
          v20 = *(_DWORD *)&v41[-1].m_data[12];
          if ( v20 != 1 )
            PStringBase<char>::append_n_chars((PStringBase<char> *)&v36, v41->m_data, v20 - 1);
          v21 = (int)&v19[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v21 + 4)) && v21 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
        }
      }
      v22 = v36;
      v23 = v40;
      v34 = (volatile LONG *)(v36 - 16);
      *(_DWORD *)v40 = v36;
      InterlockedIncrement(v34);
      v24 = (int)(v22 - 20);
      if ( !InterlockedDecrement((volatile LONG *)(v24 + 4)) && v24 )
      {
        (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
        return (PStringBase<char> *)v23;
      }
      return (PStringBase<char> *)v23;
    }
$L62521:
    v10 = 0;
    v9 = 0;
    goto LABEL_16;
  }
  v39 = (volatile LONG *)v5;
  result->m_charbuffer = v3;
  InterlockedIncrement(v39);
  v7 = (int)&v3[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  return result;
}

//----- (00408FC0) --------------------------------------------------------  // acclient.c:68460
bool __thiscall SmartArray<CommandLineArg,1>::AddToEnd(SmartArray<CommandLineArg,1> *this, CommandLineArg *i_rData)
{
  SmartArray<CommandLineArg,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  bool result; // al@2

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<char *,1>::get_new_size(v3 + 1), (result = SmartArray<CommandLineArg,1>::grow(v2, v4)) != 0) )
  {
    CommandLineArg::operator=((int)&v2->m_data[v2->m_num].ArgType, (int)i_rData);
    result = 1;
    ++v2->m_num;
  }
  return result;
}

//----- (00409010) --------------------------------------------------------  // acclient.c:68480
int __thiscall ArgumentParser::CommandLineArgList::FindByLongCmd(ArgumentParser::CommandLineArgList *this, PStringBase<unsigned short> *LongCmd)
{
  PSRefBufferCharData<unsigned short> *v2; // esi@1
  ArgumentParser::CommandLineArgList *v3; // edi@1
  volatile LONG *v4; // ST04_4@1
  int v5; // ebx@1
  int v6; // esi@3
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> result; // [sp+Ch] [bp-Ch]@1

  v2 = LongCmd->m_charbuffer;
  v3 = this;
  v4 = (volatile LONG *)&LongCmd->m_charbuffer[-1].m_data[8];
  v5 = -1;
  LongCmd = (PStringBase<unsigned short> *)LongCmd->m_charbuffer;
  InterlockedIncrement(v4);
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::find_internal(
    &v3->m_LongNamesHash.m_intrusiveTable,
    &result,
    (CaseInsensitiveStringBase<PStringBase<unsigned short> > *)&LongCmd);
  if ( result.m_currElement )
    v5 = result.m_currElement->m_data;
  v6 = (int)&v2[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return v5;
}

//----- (00409080) --------------------------------------------------------  // acclient.c:68508
void __thiscall ArgumentParser::DisplayUsage(ArgumentParser *this, ArgumentParser::CommandLineArgList *UnsortedArgs)
{
  ArgumentParser::CommandLineArgList *v2; // ebx@1
  unsigned int v3; // eax@1
  int v4; // esi@1
  unsigned int v5; // edi@1
  CommandLineArg *v6; // ebp@3
  unsigned int v7; // edx@4
  bool v13; // al@11
  CommandLineArg **v14; // ebx@15
  CommandLineArg *v15; // eax@16
  char v16; // cl@16
  PSRefBufferCharData<char> *v17; // eax@16
  ArgumentParserVtbl *v18; // ebx@16
  int v19; // ecx@16
  int v20; // [sp-Ch] [bp-44h]@16
  PSRefBufferCharData<char> *v21; // [sp-8h] [bp-40h]@16
  PSRefBufferCharData<char> *v22; // [sp-4h] [bp-3Ch]@16
  int v23; // [sp+10h] [bp-28h]@2
  ArgumentParser *v24; // [sp+14h] [bp-24h]@1
  unsigned int v25; // [sp+18h] [bp-20h]@9
  SmartArray<CommandLineArg const *,1> SortedArgs; // [sp+1Ch] [bp-1Ch]@1
  char szShort[16]; // [sp+28h] [bp-10h]@16
  ArgumentParser::CommandLineArgList *UnsortedArgsa; // [sp+3Ch] [bp+4h]@1

  v2 = UnsortedArgs;
  v3 = UnsortedArgs->m_num;
  v4 = 0;
  v24 = this;
  SortedArgs.m_data = 0;
  SortedArgs.m_sizeAndDeallocate = 0;
  SortedArgs.m_num = 0;
  SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)&SortedArgs, v3);
  v5 = SortedArgs.m_num;
  UnsortedArgsa = 0;
  if ( v2->m_num > 0 )
  {
    v23 = 0;
    do
    {
      v6 = (CommandLineArg *)((char *)v2->m_data + v4);
      if ( v5 < (SortedArgs.m_sizeAndDeallocate & 0x7FFFFFFF) )
        goto LABEL_21;
      v7 = (SortedArgs.m_sizeAndDeallocate & 0x7FFFFFFF) + 1;
      if ( v7 > 8 )
      {
        if ( v7 <= 0x4000 )
        {
          v25 = (SortedArgs.m_sizeAndDeallocate & 0x7FFFFFFF) + 1;
          __asm { bsr     eax, [esp+38h+var_20] }
          if ( v7 > 1 << _EAX )
            v7 = 2 * (1 << _EAX);
        }
        else if ( (LOWORD(SortedArgs.m_sizeAndDeallocate) + 1) & 0x3FFF )
        {
          v7 = 0x4000
             - ((LOWORD(SortedArgs.m_sizeAndDeallocate) + 1) & 0x3FFF)
             + (SortedArgs.m_sizeAndDeallocate & 0x7FFFFFFF)
             + 1;
        }
      }
      else
      {
        v7 = 8;
      }
      v13 = SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)&SortedArgs, v7);
      v5 = SortedArgs.m_num;
      if ( v13 )
      {
LABEL_21:
        SortedArgs.m_data[v5++] = v6;
        SortedArgs.m_num = v5;
      }
      v4 = v23 + 28;
      _CF = (unsigned int)((char *)&UnsortedArgsa->m_data + 1) < v2->m_num;
      UnsortedArgsa = (ArgumentParser::CommandLineArgList *)((char *)UnsortedArgsa + 1);
      v23 += 28;
    }
    while ( _CF );
    v4 = 0;
  }
  v14 = SortedArgs.m_data;
  _qsort(SortedArgs.m_data, v5, 4u, SortCommandLineArgs);
  if ( v5 > 0 )
  {
    do
    {
      v15 = v14[v4];
      v16 = v15->ShortVersion;
      v17 = v15->Description.m_charbuffer;
      szShort[0] = v16;
      szShort[1] = 0;
      v22 = v17;
      InterlockedIncrement((volatile LONG *)&v17[-1]);
      v21 = v14[v4]->LongVersion.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v21[-1]);
      v18 = v24->vfptr;
      v20 = v19;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v20, szShort);
      ((void (__thiscall *)(ArgumentParser *, int, PSRefBufferCharData<char> *, PSRefBufferCharData<char> *))v18->AppendArgumentText)(
        v24,
        v20,
        v21,
        v22);
      v14 = SortedArgs.m_data;
      ++v4;
    }
    while ( v4 < v5 );
  }
  if ( (SortedArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v14);
}

//----- (00409200) --------------------------------------------------------  // acclient.c:68622
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794324: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable[2])(void *, char);

//----- (004092A0) --------------------------------------------------------  // acclient.c:68660
void __thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6
  unsigned int __val; // [sp+0h] [bp-4h]@1

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>Vtbl *)&IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  __val = _numBuckets;
  v4 = _STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
         g_bucketSizesBegin,
         g_bucketSizesEnd,
         &__val);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned short,long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794328: using guessed type int (__thiscall *IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable)(void *, char);

//----- (00409340) --------------------------------------------------------  // acclient.c:68698
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::grow(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::resize_internal(
           v2,
           *v3);
}

//----- (004093A0) --------------------------------------------------------  // acclient.c:68720
char __thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::grow(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this)
{
  unsigned int *v1; // esi@1
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // edi@1
  unsigned int *v3; // eax@1
  unsigned int __val; // [sp+Ch] [bp-4h]@1

  v1 = g_bucketSizesEnd;
  v2 = this;
  __val = this->m_numBuckets;
  v3 = (unsigned int *)_STL::__lower_bound<unsigned long const *,unsigned long,_STL::__less_2<unsigned long,unsigned long>,int>(
                         g_bucketSizesBegin,
                         g_bucketSizesEnd,
                         &__val);
  if ( v3 != v1 || (--v3, v3 != v1) )
    ++v3;
  return IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::resize_internal(v2, *v3);
}

//----- (00409400) --------------------------------------------------------  // acclient.c:68740
bool __cdecl ConvertCommandLineToArgListTemplate<char>(const char *i_pszCmdLine, SmartBuffer *o_sb, SmartArray<char *,1> *argv)
{
  bool result; // al@2
  unsigned int v4; // eax@3
  char v5; // cl@3
  char *v6; // ebp@3
  bool v7; // dl@3
  const char *v8; // ebx@3
  unsigned int v9; // esi@3
  const char v10; // al@5
  unsigned int v11; // eax@14
  unsigned int v12; // eax@15
  bool i_pszCmdLinea; // [sp+8h] [bp+4h]@3

  if ( i_pszCmdLine )
  {
    SmartBuffer::ReconfigureAllocation(o_sb, strlen(i_pszCmdLine) + 1, 1u);
    v4 = SmartBuffer::GetBuffer(o_sb);
    v5 = 0;
    v6 = (char *)v4;
    v7 = 0;
    v8 = i_pszCmdLine - 1;
    i_pszCmdLinea = 0;
    v9 = v4;
    while ( 1 )
    {
      v10 = (v8++)[1];
      if ( v10 && (v10 != 32 || v7) )
      {
        if ( v10 == 34 )
        {
          i_pszCmdLinea = v7 == 0;
        }
        else
        {
          if ( !v5 )
          {
            v6 = (char *)v9;
            v5 = 1;
          }
          *(_BYTE *)v9++ = v10;
        }
      }
      else if ( v5 )
      {
        *(_BYTE *)v9 = 0;
        v11 = argv->m_sizeAndDeallocate & 0x7FFFFFFF;
        ++v9;
        if ( argv->m_num < v11
          || (v12 = SmartArray<char *,1>::get_new_size(v11 + 1),
              SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)argv, v12)) )
          argv->m_data[argv->m_num++] = v6;
        v5 = 0;
      }
      if ( !*v8 )
        break;
      v7 = i_pszCmdLinea;
    }
    result = i_pszCmdLinea == 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004094D0) --------------------------------------------------------  // acclient.c:68808
bool __cdecl ConvertCommandLineToArgListTemplate<unsigned short>(const unsigned __int16 *i_pszCmdLine, SmartBuffer *o_sb, SmartArray<unsigned short *,1> *argv)
{
  bool result; // al@2
  size_t v4; // eax@3
  unsigned int v5; // eax@3
  char v6; // cl@3
  wchar_t *v7; // ebp@3
  bool v8; // dl@3
  const unsigned __int16 *v9; // ebx@3
  unsigned int v10; // edi@3
  const unsigned __int16 v11; // ax@5
  unsigned int v12; // eax@14
  unsigned int v13; // eax@15
  bool i_pszCmdLinea; // [sp+8h] [bp+4h]@3

  if ( i_pszCmdLine )
  {
    v4 = _wcslen(i_pszCmdLine);
    SmartBuffer::ReconfigureAllocation(o_sb, 2 * v4 + 2, 1u);
    v5 = SmartBuffer::GetBuffer(o_sb);
    v6 = 0;
    v7 = (wchar_t *)v5;
    v8 = 0;
    v9 = i_pszCmdLine - 1;
    i_pszCmdLinea = 0;
    v10 = v5;
    while ( 1 )
    {
      v11 = v9[1];
      ++v9;
      if ( v11 && (v11 != 32 || v8) )
      {
        if ( v11 == 34 )
        {
          i_pszCmdLinea = v8 == 0;
        }
        else
        {
          if ( !v6 )
          {
            v7 = (wchar_t *)v10;
            v6 = 1;
          }
          *(_WORD *)v10 = v11;
          v10 += 2;
        }
      }
      else if ( v6 )
      {
        *(_WORD *)v10 = 0;
        v12 = argv->m_sizeAndDeallocate & 0x7FFFFFFF;
        v10 += 2;
        if ( argv->m_num < v12
          || (v13 = SmartArray<char *,1>::get_new_size(v12 + 1),
              SmartArray<Logger::ILoggingOutputHandler *,1>::grow(argv, v13)) )
          argv->m_data[argv->m_num++] = v7;
        v6 = 0;
      }
      if ( !*v9 )
        break;
      v8 = i_pszCmdLinea;
    }
    result = i_pszCmdLinea == 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004095B0) --------------------------------------------------------  // acclient.c:68880
char __thiscall ArgumentParser::EvaluateCommandLineArg(ArgumentParser *this, CommandLineArg *ArgData, PStringBase<unsigned short> *param)
{
  CommandLineArg *v3; // edi@1
  int v4; // eax@1
  ArgumentParser *v5; // esi@1
  char v6; // bl@1
  PStringBase<unsigned short> *v7; // edi@3
  PStringBase<unsigned short> *v8; // esi@4
  volatile LONG *v9; // ST04_4@4
  int v10; // esi@4
  ArgumentParserVtbl *v11; // ebx@5
  PStringBase<char> *v12; // eax@5
  char v13; // al@5
  LONG v14; // eax@4

  v3 = ArgData;
  v4 = ArgData->ArgType & 0xFF;
  v5 = this;
  v6 = 1;
  if ( v4 == 50 || v4 != 58 )
  {
    v11 = this->vfptr;
    v12 = PStringBase<unsigned short>::to_spstring(param, (PStringBase<char> *)&ArgData, 0);
    v13 = (*(int (__thiscall **)(ArgumentParser *, CommandLineArg *, PStringBase<char> *))&v11->gap3C[0])(v5, v3, v12);
    v10 = (int)&ArgData[-1].LongVersion;
    v6 = v13;
    v14 = InterlockedDecrement((volatile LONG *)&ArgData[-1].Description);
  }
  else
  {
    v7 = (PStringBase<unsigned short> *)ArgData->VariableToModify;
    if ( !v7 )
      return v6;
    v9 = (volatile LONG *)&param->m_charbuffer[-1].m_data[8];
    param = (PStringBase<unsigned short> *)param->m_charbuffer;
    v8 = param;
    InterlockedIncrement(v9);
    PStringBase<unsigned short>::operator=(v7, (const unsigned __int16 *)&param);
    v10 = (int)&v8[-5];
    v14 = InterlockedDecrement((volatile LONG *)(v10 + 4));
  }
  if ( !v14 && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  return v6;
}

//----- (00409650) --------------------------------------------------------  // acclient.c:68927
char __thiscall ArgumentParser::ParseCommandLine(ArgumentParser *this, const char *commandline, bool fSkipArgv0)
{
  const char *v3; // edi@1
  ArgumentParser *v4; // esi@1
  const char *v5; // esi@3
  char **v7; // edi@10
  char v8; // bl@10
  SmartArray<char *,1> rgArgs; // [sp+Ch] [bp-18h]@2
  SmartBuffer sbArguments; // [sp+18h] [bp-Ch]@2

  v3 = commandline;
  v4 = this;
  if ( !commandline )
    return 0;
  SmartBuffer::SmartBuffer(&sbArguments);
  rgArgs.m_data = 0;
  rgArgs.m_sizeAndDeallocate = 0;
  rgArgs.m_num = 0;
  if ( !ConvertCommandLineToArgListTemplate<char>(v3, &sbArguments, &rgArgs) )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&commandline, "Unmatched quote");
    v4->vfptr->SetErrorText(v4, (PStringBase<char> *)&commandline);
    v5 = commandline - 20;
    if ( !InterlockedDecrement((volatile LONG *)commandline - 4) && v5 )
      (**(void (__thiscall ***)(const char *, signed int))v5)(v5, 1);
    if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](rgArgs.m_data);
    SmartBuffer::ReleaseMasterBuffer(&sbArguments);
    return 0;
  }
  v7 = rgArgs.m_data;
  v8 = ((int (__thiscall *)(ArgumentParser *, char **, unsigned int, _DWORD))v4->vfptr->ParseArgs)(
         v4,
         rgArgs.m_data,
         rgArgs.m_num,
         fSkipArgv0);
  if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v7);
  SmartBuffer::ReleaseMasterBuffer(&sbArguments);
  return v8;
}

//----- (00409750) --------------------------------------------------------  // acclient.c:68970
char __thiscall ArgumentParser::ParseCommandLine(ArgumentParser *this, const wchar_t *commandline, bool fSkipArgv0)
{
  const unsigned __int16 *v3; // edi@1
  ArgumentParser *v4; // esi@1
  const wchar_t *v5; // esi@3
  wchar_t **v7; // edi@10
  char v8; // bl@10
  SmartArray<unsigned short *,1> rgArgs; // [sp+Ch] [bp-18h]@2
  SmartBuffer sbArguments; // [sp+18h] [bp-Ch]@2

  v3 = commandline;
  v4 = this;
  if ( !commandline )
    return 0;
  SmartBuffer::SmartBuffer(&sbArguments);
  rgArgs.m_data = 0;
  rgArgs.m_sizeAndDeallocate = 0;
  rgArgs.m_num = 0;
  if ( !ConvertCommandLineToArgListTemplate<unsigned short>(v3, &sbArguments, &rgArgs) )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&commandline, "Unmatched quote");
    v4->vfptr->SetErrorText(v4, (PStringBase<char> *)&commandline);
    v5 = commandline - 10;
    if ( !InterlockedDecrement((volatile LONG *)commandline - 4) && v5 )
      (**(void (__thiscall ***)(const wchar_t *, signed int))v5)(v5, 1);
    if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](rgArgs.m_data);
    SmartBuffer::ReleaseMasterBuffer(&sbArguments);
    return 0;
  }
  v7 = rgArgs.m_data;
  v8 = (*(int (__thiscall **)(ArgumentParser *, wchar_t **, unsigned int, _DWORD))&v4->vfptr->gap4[8])(
         v4,
         rgArgs.m_data,
         rgArgs.m_num,
         fSkipArgv0);
  if ( (rgArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v7);
  SmartBuffer::ReleaseMasterBuffer(&sbArguments);
  return v8;
}

//----- (00409850) --------------------------------------------------------  // acclient.c:69013
char __thiscall ArgumentParser::ParseArgs(ArgumentParser *this, char **argv, int argc, bool fSkipArgv0)
{
  int v4; // ebx@1
  ArgumentParser *v5; // esi@1
  int v6; // edi@1
  char **v7; // ebx@2
  PStringBase<unsigned short> *v8; // eax@3
  char **v9; // esi@3
  char v10; // bl@8
  ArgumentParser *v12; // [sp+Ch] [bp-10h]@1
  SmartArray<PStringBase<unsigned short>,1> argv_wide; // [sp+10h] [bp-Ch]@1

  v4 = argc;
  v5 = this;
  v6 = 0;
  v12 = this;
  argv_wide.m_data = 0;
  argv_wide.m_sizeAndDeallocate = 0;
  argv_wide.m_num = 0;
  SmartArray<PStringBase<unsigned short>,1>::grow(&argv_wide, argc);
  if ( v4 > 0 )
  {
    v7 = argv;
    do
    {
      PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&argv, 0, v7[v6]);
      SmartArray<PStringBase<unsigned short>,1>::AddToEnd(&argv_wide, v8);
      v9 = argv - 5;
      if ( !InterlockedDecrement((volatile LONG *)argv - 4) && v9 )
        (*(void (__thiscall **)(char **, signed int))*v9)(v9, 1);
      ++v6;
    }
    while ( v6 < argc );
    v5 = v12;
  }
  v10 = (*(int (__thiscall **)(ArgumentParser *, SmartArray<PStringBase<unsigned short>,1> *, _DWORD))&v5->vfptr->gap4[0])(
          v5,
          &argv_wide,
          fSkipArgv0);
  if ( (argv_wide.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)argv_wide.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor((PStringBase<char> *)argv_wide.m_data, 3u);
  return v10;
}

//----- (00409910) --------------------------------------------------------  // acclient.c:69058
void __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::add_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this, HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *data)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v2; // esi@1
  unsigned int v3; // ebx@3
  unsigned int v4; // edx@3
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v5; // eax@3
  int v6; // eax@3

  v2 = this;
  if ( (signed int)(2 * this->m_numBuckets) < (signed int)(this->m_numElements + 1) )
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::grow(this);
  v3 = v2->m_numBuckets;
  v4 = CaseInsensitiveStringBase<PStringBase<unsigned short>>::case_insensitive_hash(&data->m_hashKey) % v3;
  v5 = v2->m_buckets;
  data->m_hashNext = v5[v4];
  v5[v4] = data;
  v6 = (int)&v5[v4];
  if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v6 < v2->m_firstInterestingBucket )
    v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v6;
  ++v2->m_numElements;
}

//----- (00409960) --------------------------------------------------------  // acclient.c:69081
char __thiscall IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::resize_internal(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v4; // edi@3
  int v5; // ecx@4
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v6; // eax@5
  int v7; // eax@6
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v8; // ebx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v9; // ecx@7
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v10; // eax@9
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v11; // edx@10
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v12; // ebx@18
  unsigned int v13; // ebp@20
  unsigned int v14; // edx@20
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v15; // eax@20
  int v16; // eax@20

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_26;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_26:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(
      (IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *)v2,
      _numBuckets);
    if ( v4 )
    {
      do
      {
        v12 = v4->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::grow(v2);
        v13 = v2->m_numBuckets;
        v14 = CaseInsensitiveStringBase<PStringBase<unsigned short>>::case_insensitive_hash(&v4->m_hashKey) % v13;
        v15 = v2->m_buckets;
        v4->m_hashNext = v15[v14];
        v15[v14] = v4;
        v16 = (int)&v15[v14];
        if ( (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v16 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v16;
        ++v2->m_numElements;
        v4 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (00409A70) --------------------------------------------------------  // acclient.c:69188
char __thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::resize_internal(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // esi@1
  char result; // al@2
  HashTableData<unsigned short,long> *v4; // edi@3
  int v5; // ecx@4
  HashTableData<unsigned short,long> **v6; // eax@5
  int v7; // eax@6
  HashTableData<unsigned short,long> **v8; // ebp@7
  HashTableData<unsigned short,long> *v9; // ecx@7
  HashTableData<unsigned short,long> *v10; // eax@9
  HashTableData<unsigned short,long> *v11; // edx@10
  HashTableData<unsigned short,long> *v12; // ebp@18
  unsigned int v13; // edx@20
  HashTableData<unsigned short,long> **v14; // eax@20
  int v15; // eax@20

  v2 = this;
  if ( _numBuckets == this->m_numBuckets )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    if ( this->m_numElements )
    {
      do
      {
        v5 = (int)&v2->m_buckets[v2->m_numBuckets];
        if ( v2->m_firstInterestingBucket == (HashTableData<unsigned short,long> **)v5 )
        {
LABEL_7:
          v8 = 0;
          v9 = 0;
        }
        else
        {
          while ( 1 )
          {
            v6 = v2->m_firstInterestingBucket;
            if ( *v6 )
              break;
            v7 = (int)(v6 + 1);
            v2->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)v7;
            if ( v7 == v5 )
              goto LABEL_7;
          }
          v9 = *v2->m_firstInterestingBucket;
          v8 = v2->m_firstInterestingBucket;
        }
        v10 = *v8;
        if ( *v8 == v9 )
          goto LABEL_26;
        do
        {
          v11 = v10;
          v10 = v10->m_hashNext;
        }
        while ( v10 != v9 );
        if ( v11 )
          v11->m_hashNext = v10->m_hashNext;
        else
LABEL_26:
          *v8 = v10->m_hashNext;
        --v2->m_numElements;
        v9->m_hashNext = v4;
        v4 = v9;
      }
      while ( v2->m_numElements );
    }
    if ( (HashTableData<unsigned short,long> **)v2->m_buckets != v2->m_aInplaceBuckets )
      operator delete[](v2->m_buckets);
    v2->m_buckets = 0;
    v2->m_firstInterestingBucket = 0;
    v2->m_numBuckets = 0;
    v2->m_numElements = 0;
    IntrusiveHashTable<int,CAsyncStateHandler *,1>::init(v2, _numBuckets);
    if ( v4 )
    {
      do
      {
        v12 = v4->m_hashNext;
        if ( (signed int)(2 * v2->m_numBuckets) < (signed int)(v2->m_numElements + 1) )
          IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::grow(v2);
        v13 = v4->m_hashKey % v2->m_numBuckets;
        v14 = v2->m_buckets;
        v4->m_hashNext = v14[v13];
        v14[v13] = v4;
        v15 = (int)&v14[v13];
        if ( (HashTableData<unsigned short,long> **)v15 < v2->m_firstInterestingBucket )
          v2->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)v15;
        ++v2->m_numElements;
        v4 = v12;
      }
      while ( v12 );
    }
    result = 1;
  }
  return result;
}

//----- (00409B70) --------------------------------------------------------  // acclient.c:69291
char __thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::add(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this, HashTableData<unsigned short,long> *data)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned short,long> *v4; // edx@1
  unsigned int v5; // edx@6
  HashTableData<unsigned short,long> **v6; // eax@6
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
      IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned short,long> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (00409BF0) --------------------------------------------------------  // acclient.c:69335
void __thiscall IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::delete_contents(IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *this)
{
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<unsigned short,long> **v3; // eax@3
  int v4; // eax@4
  HashTableData<unsigned short,long> **v5; // edi@5
  void *v6; // ecx@5
  void *v7; // eax@7
  void *v8; // edx@8

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<unsigned short,long> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<unsigned short,long> **)v4;
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
      *v5 = (HashTableData<unsigned short,long> *)*((_DWORD *)v7 + 1);
    --v1->m_numElements;
    if ( v6 )
      operator delete(v6);
  }
}

//----- (00409C70) --------------------------------------------------------  // acclient.c:69392
char __thiscall HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long,1>::add(HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1> *this, CaseInsensitiveStringBase<PStringBase<unsigned short> > *_key, const int *_data)
{
  HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1> *v3; // edi@1
  void *v4; // esi@1
  PSRefBufferCharData<unsigned short> *v5; // eax@2
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v6; // edi@4
  char v7; // al@5
  int v8; // edi@7
  IntrusiveHashIterator<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> result; // [sp+8h] [bp-Ch]@4

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    v5 = _key->m_charbuffer;
    *(_DWORD *)v4 = _key->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
  }
  else
  {
    v4 = 0;
  }
  v6 = &v3->m_intrusiveTable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::find_internal(
    v6,
    &result,
    (CaseInsensitiveStringBase<PStringBase<unsigned short> > *)v4);
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
    IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::add_internal(
      v6,
      (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *)v4);
    v7 = 1;
  }
  return v7;
}

//----- (00409D10) --------------------------------------------------------  // acclient.c:69446
char __thiscall HashTable<unsigned short,long,1>::add(HashTable<unsigned short,long,1> *this, const unsigned __int16 *_key, const int *_data)
{
  HashTable<unsigned short,long,1> *v3; // edi@1
  void *v4; // eax@1
  void *v5; // esi@2
  char result; // al@7

  v3 = this;
  v4 = operator new(0xCu);
  if ( v4 )
  {
    *(_WORD *)v4 = *_key;
    *((_DWORD *)v4 + 1) = 0;
    *((_DWORD *)v4 + 2) = *_data;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  if ( IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned short,long> *)v5) )
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

//----- (00409D70) --------------------------------------------------------  // acclient.c:69482
char __thiscall ArgumentParser::CommandLineArgList::add(ArgumentParser::CommandLineArgList *this, CommandLineArg *data)
{
  CommandLineArg *v2; // edi@1
  ArgumentParser::CommandLineArgList *v3; // esi@1
  char *v4; // ebx@1
  ArgumentParser::CommandLineArgList *v5; // ecx@1
  int v6; // ebp@3
  int v7; // eax@3
  bool v8; // zf@5
  CommandLineArg *v9; // ebx@5
  volatile LONG *v10; // ST04_4@7
  int v11; // ebx@10
  char result; // al@13
  char *v13; // esi@14
  int _data; // [sp+Ch] [bp-8h]@4
  unsigned __int16 _key[2]; // [sp+10h] [bp-4h]@4

  v2 = data;
  v3 = this;
  v4 = (char *)&data->LongVersion;
  PStringBase<char>::to_wpstring(&data->LongVersion, (PStringBase<unsigned short> *)&data, 0);
  if ( ArgumentParser::CommandLineArgList::FindByShortCmd(v3, v2->ShortVersion) >= 0
    || ArgumentParser::CommandLineArgList::FindByLongCmd(v5, (PStringBase<unsigned short> *)&data) >= 0 )
  {
    v13 = (char *)&data[-1].LongVersion;
    if ( !InterlockedDecrement((volatile LONG *)&data[-1].Description) && v13 )
      (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
    result = 0;
  }
  else
  {
    v6 = v3->m_num;
    SmartArray<CommandLineArg,1>::AddToEnd((SmartArray<CommandLineArg,1> *)&v3->m_data, v2);
    LOBYTE(v7) = v2->ShortVersion;
    if ( (_BYTE)v7 )
    {
      LOWORD(v7) = (char)v7;
      _data = v6;
      *(_DWORD *)_key = v7;
      HashTable<unsigned short,long,1>::add(
        (HashTable<unsigned short,long,1> *)&v3->m_ShortNamesHash.vfptr,
        _key,
        &_data);
    }
    v8 = *(_DWORD *)(*(_DWORD *)v4 - 4) == 1;
    v9 = data;
    if ( !v8 || !v2->ShortVersion )
    {
      v10 = (volatile LONG *)&data[-1].Description;
      data = (CommandLineArg *)v6;
      *(_DWORD *)_key = v9;
      InterlockedIncrement(v10);
      HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long,1>::add(
        (HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1> *)&v3->m_LongNamesHash.vfptr,
        (CaseInsensitiveStringBase<PStringBase<unsigned short> > *)_key,
        (const int *)&data);
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1].Description) && v9 != (CommandLineArg *)20 )
        (*(void (__thiscall **)(PStringBase<char> *, signed int))v9[-1].LongVersion.m_charbuffer)(
          &v9[-1].LongVersion,
          1);
    }
    v11 = (int)&v9[-1].LongVersion;
    if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) )
    {
      if ( v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    }
    result = 1;
  }
  return result;
}

//----- (00409E90) --------------------------------------------------------  // acclient.c:69555
AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *__thiscall AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::scalar_deleting_destructor(AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *this, unsigned int a2)
{
  AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1>Vtbl *)AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable;
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
// 794324: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable[2])(void *, char);
// 7943B8: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable[2])(void *, char);

//----- (00409EF0) --------------------------------------------------------  // acclient.c:69581
AutoGrowHashTable<unsigned short,long> *__thiscall HashTable<unsigned short,long,1>::scalar_deleting_destructor(AutoGrowHashTable<unsigned short,long> *this, unsigned int a2)
{
  AutoGrowHashTable<unsigned short,long> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned short,long,1>Vtbl *)&HashTable<unsigned short,long,1>::vftable;
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::delete_contents(&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable;
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
// 794328: using guessed type int (__thiscall *IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable)(void *, char);
// 7943BC: using guessed type int (__thiscall *HashTable<unsigned short,long,1>::vftable)(void *, char);

//----- (00409F50) --------------------------------------------------------  // acclient.c:69607
void __thiscall ArgumentParser::CommandLineArgList::CommandLineArgList(ArgumentParser::CommandLineArgList *this)
{
  ArgumentParser::CommandLineArgList *v1; // esi@1

  v1 = this;
  this->m_data = 0;
  this->m_sizeAndDeallocate = 0;
  this->m_num = 0;
  this->m_LongNamesHash.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1>Vtbl *)AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable;
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>(
    &this->m_LongNamesHash.m_intrusiveTable,
    0);
  v1->m_LongNamesHash.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1>Vtbl *)AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable;
  v1->m_ShortNamesHash.vfptr = (HashTable<unsigned short,long,1>Vtbl *)&HashTable<unsigned short,long,1>::vftable;
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>(
    &v1->m_ShortNamesHash.m_intrusiveTable,
    0);
  v1->m_ShortNamesHash.vfptr = (HashTable<unsigned short,long,1>Vtbl *)&HashTable<unsigned short,long,1>::vftable;
}
// 7943B8: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable[2])(void *, char);
// 7943BC: using guessed type int (__thiscall *HashTable<unsigned short,long,1>::vftable)(void *, char);

//----- (00409FB0) --------------------------------------------------------  // acclient.c:69630
void __thiscall ArgumentParser::CommandLineArgList::~CommandLineArgList(ArgumentParser::CommandLineArgList *this)
{
  ArgumentParser::CommandLineArgList *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  void *v4; // eax@3

  v1 = this;
  v2 = (char *)&this->m_ShortNamesHash.m_intrusiveTable;
  this->m_ShortNamesHash.vfptr = (HashTable<unsigned short,long,1>Vtbl *)&HashTable<unsigned short,long,1>::vftable;
  IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::delete_contents(&this->m_ShortNamesHash.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = &IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->m_LongNamesHash.vfptr = (HashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long,1>Vtbl *)AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::delete_contents(&v1->m_LongNamesHash.m_intrusiveTable);
  v4 = v1->m_LongNamesHash.m_intrusiveTable.m_buckets;
  v1->m_LongNamesHash.m_intrusiveTable.vfptr = (IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1>Vtbl *)IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable;
  if ( v4 != v1->m_LongNamesHash.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_LongNamesHash.m_intrusiveTable.m_buckets = 0;
  v1->m_LongNamesHash.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_LongNamesHash.m_intrusiveTable.m_numBuckets = 0;
  v1->m_LongNamesHash.m_intrusiveTable.m_numElements = 0;
  if ( (v1->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v1->m_data )
      CommandLineArg::vector_deleting_destructor(v1->m_data, 3u);
  }
}
// 794324: using guessed type int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable[2])(void *, char);
// 794328: using guessed type int (__thiscall *IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable)(void *, char);
// 7943B8: using guessed type int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable[2])(void *, char);
// 7943BC: using guessed type int (__thiscall *HashTable<unsigned short,long,1>::vftable)(void *, char);

//----- (0040A050) --------------------------------------------------------  // acclient.c:69671
void __thiscall ArgumentParser::Usage(ArgumentParser *this)
{
  ArgumentParser *v1; // esi@1
  ArgumentParser::CommandLineArgList Args; // [sp+8h] [bp-F4h]@1

  v1 = this;
  ArgumentParser::CommandLineArgList::CommandLineArgList(&Args);
  v1->vfptr->BuildCommandLineArgs(v1, &Args);
  v1->vfptr->DisplayUsage(v1, &Args);
  v1->vfptr->FinishOutputText(v1);
  ArgumentParser::CommandLineArgList::~CommandLineArgList(&Args);
}

//----- (0040A0A0) --------------------------------------------------------  // acclient.c:69685
char __thiscall ArgumentParser::ParseArgs(ArgumentParser *this, wchar_t **argv, int argc, bool fSkipArgv0)
{
  ArgumentParser *v4; // esi@1
  int v5; // eax@1
  int v6; // eax@4
  wchar_t **v7; // ecx@5
  const wchar_t *v8; // edi@5
  unsigned int v9; // eax@7
  ArgumentParserVtbl *v10; // eax@9
  unsigned __int16 v11; // bp@9
  bool v12; // bl@9
  bool v13; // al@9
  PSRefBufferCharData<unsigned short> *v14; // ecx@9
  int v15; // edx@10
  bool v16; // zf@10
  PSRefBufferCharData<unsigned short> *v17; // edx@10
  int v18; // edi@15
  int v19; // edx@15
  int v20; // edi@16
  char *v21; // edi@19
  unsigned int v22; // eax@24
  char *v23; // edi@24
  int v24; // eax@29
  unsigned int v25; // eax@32
  PSRefBufferCharData<unsigned short> *v26; // ebp@32
  int v27; // ebp@34
  int v28; // edi@39
  char *v29; // edi@40
  PSRefBufferCharData<char> *v30; // edi@44
  int v31; // eax@46
  int v32; // eax@47
  PSRefBufferCharData<unsigned short> *v33; // edx@47
  PSRefBufferCharData<unsigned short> *v34; // eax@51
  CommandLineArg *v35; // eax@56
  int v36; // edi@62
  int v37; // edi@68
  PSRefBufferCharData<char> *v38; // eax@74
  char v40; // [sp+2Dh] [bp-11Dh]@1
  int idxArgs; // [sp+2Eh] [bp-11Ch]@1
  PStringBase<unsigned short> ArgStr; // [sp+32h] [bp-118h]@7
  PStringBase<unsigned short> LongCmd; // [sp+36h] [bp-114h]@32
  PStringBase<char> v44; // [sp+3Ah] [bp-110h]@44
  PStringBase<char> v45; // [sp+3Eh] [bp-10Ch]@60
  PStringBase<char> v46; // [sp+42h] [bp-108h]@40
  PStringBase<char> v47; // [sp+46h] [bp-104h]@54
  PStringBase<char> Err; // [sp+4Ah] [bp-100h]@45
  int bLookingForParameters; // [sp+4Eh] [bp-FCh]@9
  int idxDefault; // [sp+52h] [bp-F8h]@1
  ArgumentParser::CommandLineArgList Args; // [sp+56h] [bp-F4h]@1

  v4 = this;
  ArgumentParser::CommandLineArgList::CommandLineArgList(&Args);
  v4->vfptr->BuildCommandLineArgs(v4, &Args);
  v40 = 1;
  idxDefault = ArgumentParser::CommandLineArgList::FindByLongCmd(&Args, &PStringBase<unsigned short>::null_string);
  v5 = 0;
  idxArgs = -1;
  if ( fSkipArgv0 )
    v5 = 1;
  v4->m_argv = argv;
  v4->m_argc = argc;
  v4->m_CurArg = v5;
  if ( v5 > argc )
  {
LABEL_73:
    v40 = v4->vfptr->OnCommandLineEvaluationDone(v4);
    if ( !v40 )
      goto LABEL_74;
    goto LABEL_77;
  }
  do
  {
    v6 = v4->m_CurArg;
    if ( v6 < v4->m_argc && (v7 = v4->m_argv, (v8 = v7[v6]) != 0) && *v8 )
    {
      v9 = _wcslen(v7[v6]);
      PStringBase<unsigned short>::allocate_ref_buffer(&ArgStr, v9);
      _wcscpy(ArgStr.m_charbuffer->m_data, v8);
    }
    else
    {
      ArgStr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    }
    v10 = v4->vfptr;
    v11 = 0;
    v12 = idxArgs >= 0;
    LOBYTE(bLookingForParameters) = idxArgs >= 0;
    v13 = v10->IsCommandLineArgument(v4, &ArgStr, bLookingForParameters);
    v14 = ArgStr.m_charbuffer;
    if ( v13 )
    {
      v15 = *(_DWORD *)&ArgStr.m_charbuffer[-1].m_data[14];
      v16 = v15 == 0;
      v17 = (PSRefBufferCharData<unsigned short> *)((char *)ArgStr.m_charbuffer + 2 * v15 - 2);
      if ( !v16 )
        v17 = ArgStr.m_charbuffer;
      v11 = v17->m_data[0];
    }
    if ( v12 )
    {
      if ( !v13 )
        goto LABEL_80;
      v18 = idxArgs;
      v19 = Args.m_data[idxArgs].ArgType & 0xF;
      if ( v19 == 3 )
      {
        idxArgs = (int)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        v40 &= v4->vfptr->EvaluateCommandLineArg(v4, &Args.m_data[v18], (PStringBase<char> *)&idxArgs);
        v20 = idxArgs - 20;
        if ( !InterlockedDecrement((volatile LONG *)(idxArgs - 20 + 4)) && v20 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
        v21 = (char *)&ArgStr.m_charbuffer[-1].m_data[6];
        idxArgs = -1;
        if ( !InterlockedDecrement((volatile LONG *)&ArgStr.m_charbuffer[-1].m_data[8]) && v21 )
          (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
        continue;
      }
      if ( v19 == 2 )
        goto LABEL_80;
    }
    if ( !v13 )
    {
LABEL_80:
      v31 = idxArgs;
      if ( idxArgs < 0 )
      {
        v32 = *(_DWORD *)&ArgStr.m_charbuffer[-1].m_data[14];
        v33 = (PSRefBufferCharData<unsigned short> *)((char *)ArgStr.m_charbuffer + 2 * v32 - 2);
        if ( v32 )
          v33 = ArgStr.m_charbuffer;
        if ( !v33->m_data[0] || idxDefault < 0 )
        {
          v16 = v32 == 0;
          v34 = (PSRefBufferCharData<unsigned short> *)((char *)ArgStr.m_charbuffer + 2 * v32 - 2);
          if ( !v16 )
            v34 = ArgStr.m_charbuffer;
          if ( !v34->m_data[0] )
            goto LABEL_68;
          PStringBase<char>::PStringBase<char>(&v47, 0, "Argument '%ls' unknown", ArgStr.m_charbuffer);
          v4->vfptr->SetErrorText(v4, &v47);
          v30 = v47.m_charbuffer;
          goto LABEL_61;
        }
        idxArgs = idxDefault;
        v31 = idxDefault;
      }
      v35 = &Args.m_data[v31];
      if ( (v35->ArgType & 0xF) != 2 )
        goto LABEL_81;
      if ( !*(_DWORD *)&ArgStr.m_charbuffer[-1].m_data[14] )
        v14 = (PSRefBufferCharData<unsigned short> *)((char *)ArgStr.m_charbuffer - 2);
      if ( v14->m_data[0] )
      {
LABEL_81:
        v40 &= v4->vfptr->EvaluateCommandLineArg(v4, v35, (PStringBase<char> *)&ArgStr);
LABEL_66:
        idxArgs = -1;
        goto LABEL_67;
      }
      PStringBase<char>::PStringBase<char>(&v45, 0, "Argument %ls requires parameter", v4->m_argv[v4->m_CurArg - 1]);
      v4->vfptr->SetErrorText(v4, &v45);
      v30 = v45.m_charbuffer;
      goto LABEL_61;
    }
    v22 = *(_DWORD *)&ArgStr.m_charbuffer[-1].m_data[14];
    v23 = (char *)ArgStr.m_charbuffer + 2 * v22 - 2;
    if ( v22 > 1 )
      v23 = (char *)&ArgStr.m_charbuffer->m_data[1];
    if ( *(_WORD *)v23 == v11 )
    {
      v23 += 2;
    }
    else if ( _wcslen((const wchar_t *)v23) == 1 )
    {
      v24 = ArgumentParser::CommandLineArgList::FindByShortCmd(&Args, *(_WORD *)v23);
      idxArgs = v24;
      if ( v24 != -1 )
        goto LABEL_38;
    }
    if ( v23 && *(_WORD *)v23 )
    {
      v25 = _wcslen((const wchar_t *)v23);
      PStringBase<unsigned short>::allocate_ref_buffer(&LongCmd, v25);
      v26 = LongCmd.m_charbuffer;
      _wcscpy(LongCmd.m_charbuffer->m_data, (const wchar_t *)v23);
    }
    else
    {
      v26 = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      LongCmd.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    }
    idxArgs = ArgumentParser::CommandLineArgList::FindByLongCmd(&Args, &LongCmd);
    v27 = (int)&v26[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v27 + 4)) && v27 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
    v24 = idxArgs;
LABEL_38:
    if ( v24 < 0 )
    {
      if ( *(_WORD *)v23 == 63 )
      {
        v40 = 0;
        PStringBase<char>::PStringBase<char>(&v44, &name);
        v4->vfptr->SetErrorText(v4, &v44);
        v30 = v44.m_charbuffer;
LABEL_62:
        v36 = (int)&v30[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v36 + 4)) && v36 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
        goto LABEL_67;
      }
      PStringBase<char>::PStringBase<char>(&Err, 0, "Unrecognized argument '%ls'", v23);
      v4->vfptr->SetErrorText(v4, &Err);
      v30 = Err.m_charbuffer;
LABEL_61:
      v40 = 0;
      goto LABEL_62;
    }
    v28 = v24;
    if ( (Args.m_data[v24].ArgType & 0xF) == 1 )
    {
      PStringBase<char>::PStringBase<char>(&v46, &name);
      v40 &= (*(int (__thiscall **)(ArgumentParser *, CommandLineArg *, PStringBase<char> *))&v4->vfptr->gap3C[0])(
               v4,
               &Args.m_data[v28],
               &v46);
      v29 = &v46.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v46.m_charbuffer[-1]) && v29 )
        (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
      goto LABEL_66;
    }
LABEL_67:
    v14 = ArgStr.m_charbuffer;
LABEL_68:
    ++v4->m_CurArg;
    v37 = (int)&v14[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&v14[-1].m_data[8]) && v37 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v37)(v37, 1);
  }
  while ( v4->m_CurArg <= v4->m_argc );
  if ( v40 )
    goto LABEL_73;
LABEL_74:
  v38 = v4->m_ErrorText.m_charbuffer;
  if ( *(_DWORD *)&v38[-1].m_data[12] != 1 )
  {
    v4->vfptr->AppendOutputText(v4, (const char *)v38, ottErrorText);
    v4->vfptr->AppendOutputText(v4, "\n\n", 0);
  }
  v4->vfptr->DisplayUsage(v4, &Args);
  v4->vfptr->FinishOutputText(v4);
LABEL_77:
  ArgumentParser::CommandLineArgList::~CommandLineArgList(&Args);
  return v40;
}

//----- (0065E6C0) --------------------------------------------------------  // acclient.c:628428
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::delete_contents(IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *this)
{
  IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short> >,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *,1> *v1; // esi@1
  int v2; // ecx@2
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v3; // eax@3
  int v4; // eax@4
  HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **v5; // edx@5
  void *v6; // ebx@5
  void *v7; // eax@7
  void *v8; // ecx@8
  int v9; // edi@13

  v1 = this;
  while ( v1->m_numElements )
  {
    v2 = (int)&v1->m_buckets[v1->m_numBuckets];
    if ( v1->m_firstInterestingBucket == (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v2 )
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
        v1->m_firstInterestingBucket = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> **)v4;
        if ( v4 == v2 )
          goto LABEL_5;
      }
      v6 = *v1->m_firstInterestingBucket;
      v5 = v1->m_firstInterestingBucket;
    }
    v7 = *v5;
    if ( *v5 == v6 )
      goto LABEL_20;
    do
    {
      v8 = v7;
      v7 = (void *)*((_DWORD *)v7 + 1);
    }
    while ( v7 != v6 );
    if ( v8 )
      *((_DWORD *)v8 + 1) = *((_DWORD *)v7 + 1);
    else
LABEL_20:
      *v5 = (HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short> >,long> *)*((_DWORD *)v7 + 1);
    --v1->m_numElements;
    if ( v6 )
    {
      v9 = *(_DWORD *)v6 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) )
      {
        if ( v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      }
      operator delete(v6);
    }
  }
}

