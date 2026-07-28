/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DataError
   Object     : ENGINE\dataerror\DataError.obj
   Functions  : 19
   Addresses  : 00413110 - 006C44A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00413110) --------------------------------------------------------  // acclient.c:78973
unsigned int __cdecl compute_str_hash(char *i_pstr)
{
  char *v1; // edx@1
  char v2; // cl@1
  unsigned int result; // eax@1

  v1 = i_pstr;
  v2 = *i_pstr;
  result = 0;
  if ( *i_pstr )
  {
    do
    {
      result = v2 + 16 * result;
      if ( result & 0xF0000000 )
        result = (result ^ ((result & 0xF0000000) >> 24)) & 0xFFFFFFF;
      v2 = (v1++)[1];
    }
    while ( v2 );
    if ( result == -1 )
      result = -2;
  }
  return result;
}

//----- (00413160) --------------------------------------------------------  // acclient.c:78999
IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *__thiscall IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vector_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *v2; // esi@1
  HashSetData<PStringBase<char> > **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable;
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
// 794EF8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable)(void *, char);

//----- (004131A0) --------------------------------------------------------  // acclient.c:79020
unsigned int __thiscall PStringBase<char>::hash(PStringBase<char> *this)
{
  PSRefBufferCharData<char> *v1; // esi@1
  unsigned int result; // eax@1

  v1 = this->m_charbuffer;
  result = *(_DWORD *)&this->m_charbuffer[-1].m_data[8];
  if ( result == -1 )
  {
    result = compute_str_hash(this->m_charbuffer->m_data);
    *(_DWORD *)&v1[-1].m_data[8] = result;
  }
  return result;
}

//----- (004131C0) --------------------------------------------------------  // acclient.c:79036
int __cdecl _STL::distance(const unsigned int *const *__first, const unsigned int *const *__last)
{
  return *__last - *__first;
}

//----- (004131D0) --------------------------------------------------------  // acclient.c:79042
void __cdecl _STL::advance(const unsigned int **__i, int __n)
{
  *__i += __n;
}

//----- (004131F0) --------------------------------------------------------  // acclient.c:79048
PStringBase<char> *__cdecl GetFileName(PStringBase<char> *result, IDClass<_tagDataID,32,0> data_id)
{
  PSRefBufferCharData<char> *v2; // eax@1
  char *v3; // esi@1
  PStringBase<char> filename; // [sp+0h] [bp-4h]@1

  filename.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::sprintf(&filename, "'<unknowable file>' (did=0x%08X)", data_id.id);
  v2 = filename.m_charbuffer;
  result->m_charbuffer = filename.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v2[-1]);
  v3 = &filename.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&filename.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  return result;
}

//----- (00413260) --------------------------------------------------------  // acclient.c:79067
void IError::ReportDataErrorFrom(IDClass<_tagDataID,32,0> source_id, const char *fmt, ...)
{
  PSRefBufferCharData<char> *v2; // ebx@1
  char *v3; // esi@1
  char *v4; // esi@4
  PStringBase<char> error; // [sp+Ch] [bp-Ch]@1
  PStringBase<char> error_text; // [sp+10h] [bp-8h]@1
  PStringBase<char> source_filename; // [sp+14h] [bp-4h]@1
  va_list va; // [sp+24h] [bp+Ch]@1

  va_start(va, fmt);
  GetFileName(&source_filename, source_id);
  error_text.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  PStringBase<char>::vsprintf(&error_text, fmt, va);
  error.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v2 = source_filename.m_charbuffer;
  PStringBase<char>::sprintf(
    &error,
    "Error in file \"%s\": %s\n",
    source_filename.m_charbuffer,
    error_text.m_charbuffer);
  IError::ReportDataError(&error);
  v3 = &error.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&error.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = &error_text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&error_text.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) && v2 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v2[-2].m_data[12])(&v2[-2].m_data[12], 1);
}

//----- (00413340) --------------------------------------------------------  // acclient.c:79102
void __thiscall IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>(IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *v2; // esi@1
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
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashSetData<PStringBase<char> > **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashSetData<PStringBase<char> > **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 794EF8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable)(void *, char);

//----- (004133D0) --------------------------------------------------------  // acclient.c:79135
void __thiscall HashSet<PStringBase<char>>::~HashSet<PStringBase<char>>(HashSet<PStringBase<char> > *this)
{
  char *v1; // esi@1
  void *v2; // eax@1

  v1 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<PStringBase<char> >Vtbl *)HashSet<PStringBase<char>>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v2 = (void *)*((_DWORD *)v1 + 24);
  *(_DWORD *)v1 = &IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable;
  if ( v2 != v1 + 4 )
    operator delete[](v2);
  *((_DWORD *)v1 + 24) = 0;
  *((_DWORD *)v1 + 25) = 0;
  *((_DWORD *)v1 + 26) = 0;
  *((_DWORD *)v1 + 27) = 0;
}
// 794EF8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable)(void *, char);
// 794F38: using guessed type int (__thiscall *HashSet<PStringBase<char>>::vftable[2])(void *, char);

//----- (00413410) --------------------------------------------------------  // acclient.c:79156
HashSet<PStringBase<char> > *__thiscall HashSet<PStringBase<char>>::vector_deleting_destructor(HashSet<PStringBase<char> > *this, unsigned int a2)
{
  HashSet<PStringBase<char> > *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashSet<PStringBase<char> >Vtbl *)HashSet<PStringBase<char>>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable;
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
// 794EF8: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable)(void *, char);
// 794F38: using guessed type int (__thiscall *HashSet<PStringBase<char>>::vftable[2])(void *, char);

//----- (00413470) --------------------------------------------------------  // acclient.c:79182
Logger::LoggerWriteResult __thiscall InteractiveOutputHandler::Write(InteractiveOutputHandler *this, Logger::LoggingSeverity ls, unsigned int lc, const char *szMsg)
{
  InteractiveOutputHandler *v4; // esi@1
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v5; // ecx@2
  const char *v6; // esi@3
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+4h] [bp-Ch]@2

  v4 = this;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&szMsg, szMsg);
  if ( !v4->m_fIgnoreAll )
    v5 = IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
           (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v4->m_setReportedErrors.m_intrusiveTable,
           &result,
           (PStringBase<char> *)&szMsg)->m_currElement;
  v6 = szMsg - 20;
  if ( !InterlockedDecrement((volatile LONG *)szMsg - 4) && v6 )
    (**(void (__thiscall ***)(const char *, signed int))v6)(v6, 1);
  return 0;
}

//----- (00413530) --------------------------------------------------------  // acclient.c:79240
char __thiscall InteractiveOutputHandler::ResetReportedErrors(InteractiveOutputHandler *this)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_setReportedErrors.m_intrusiveTable);
  return 1;
}

//----- (00413540) --------------------------------------------------------  // acclient.c:79247
IInteractiveOutputHandler *__cdecl Logger::GetInteractiveOutputHandler()
{
  struct IInteractiveOutputHandler *v0; // esi@1
  void *v1; // eax@2

  v0 = g_plohInteractive;
  if ( !g_plohInteractive )
  {
    v1 = operator new(0x80u);
    v0 = (struct IInteractiveOutputHandler *)v1;
    if ( v1 )
    {
      *((_DWORD *)v1 + 1) = 1;
      *(_DWORD *)v1 = &InteractiveOutputHandler::vftable;
      *((_BYTE *)v1 + 8) = 0;
      *((_BYTE *)v1 + 9) = 0;
      *((_DWORD *)v1 + 3) = HashSet<PStringBase<char>>::vftable;
      IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>(
        (IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char> > *,1> *)((char *)v1 + 16),
        0x17u);
    }
    else
    {
      v0 = 0;
    }
    g_plohInteractive = v0;
  }
  InterlockedIncrement((volatile LONG *)&v0->m_cRef);
  return g_plohInteractive;
}
// 794F38: using guessed type int (__thiscall *HashSet<PStringBase<char>>::vftable[2])(void *, char);
// 794F3C: using guessed type int (__thiscall *InteractiveOutputHandler::vftable)(void *, char);
// 836B9C: using guessed type struct IInteractiveOutputHandler *g_plohInteractive;

//----- (004135A0) --------------------------------------------------------  // acclient.c:79282
void __cdecl IError::AddDataErrorHandlers(LegacyDataErrorMode mode, PStringBase<char> *filename)
{
  Logger::ITextFileOutputHandler *v2; // esi@1
  Logger::ILoggingOutputHandler *v3; // eax@7
  Logger::ILoggingOutputHandler *v4; // esi@8
  TimestamppedTextFileOutputHandler *v5; // eax@14
  Logger::ILoggingOutputHandler *v6; // eax@15
  ReferenceCountTemplate<1048576,0> *v7; // esi@15
  Logger::ILoggingOutputHandler *v8; // esi@17

  v2 = Logger::GetTextFileOutputHandler();
  IError::DefaultAllIErrorCategoriesToProvidedHandler((Logger::ILoggingOutputHandler *)&v2->vfptr);
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
  if ( mode )
  {
    if ( mode == 1 )
    {
      v3 = Logger::GetOutputDebugStringOutputHandler();
    }
    else
    {
      if ( mode != 2 )
        return;
      v3 = Logger::GetConsoleOutputHandler();
    }
    v4 = v3;
    IError::DefaultAllIErrorCategoriesToProvidedHandler(v3);
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
    {
      if ( v4 )
        v4->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v4, 1u);
    }
  }
  else if ( *(_DWORD *)&filename->m_charbuffer[-1].m_data[12] == 1 )
  {
    v8 = (Logger::ILoggingOutputHandler *)Logger::GetInteractiveOutputHandler();
    IError::DefaultAllIErrorCategoriesToProvidedHandler(v8);
    ReferenceCountTemplate<1048576,0>::Release((ReferenceCountTemplate<1048576,0> *)&v8->vfptr);
  }
  else
  {
    v5 = (TimestamppedTextFileOutputHandler *)operator new(0x18u);
    if ( v5 )
    {
      TimestamppedTextFileOutputHandler::TimestamppedTextFileOutputHandler(v5, filename->m_charbuffer->m_data);
      v7 = (ReferenceCountTemplate<1048576,0> *)v6;
      IError::DefaultAllIErrorCategoriesToProvidedHandler(v6);
      ReferenceCountTemplate<1048576,0>::Release(v7);
    }
    else
    {
      IError::DefaultAllIErrorCategoriesToProvidedHandler(0);
      ReferenceCountTemplate<1048576,0>::Release(0);
    }
  }
}

//----- (00413680) --------------------------------------------------------  // acclient.c:79341
InteractiveOutputHandler *__thiscall InteractiveOutputHandler::scalar_deleting_destructor(InteractiveOutputHandler *this, unsigned int a2)
{
  InteractiveOutputHandler *v2; // esi@1

  v2 = this;
  HashSet<PStringBase<char>>::~HashSet<PStringBase<char>>(&this->m_setReportedErrors);
  v2->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (006C4470) --------------------------------------------------------  // acclient.c:732609
int _E73_9()
{
  return atexit(_E74_12);
}

//----- (006C4480) --------------------------------------------------------  // acclient.c:732615
int _E76_4()
{
  return atexit(_E77_32);
}

//----- (006C4490) --------------------------------------------------------  // acclient.c:732621
int _E79_4()
{
  return atexit(_E80_6);
}

//----- (006C44A0) --------------------------------------------------------  // acclient.c:732627
int _E1_4()
{
  return atexit(_E2_4);
}

