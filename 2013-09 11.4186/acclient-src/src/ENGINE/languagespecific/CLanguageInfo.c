/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CLanguageInfo
   Object     : ENGINE\languagespecific\CLanguageInfo.obj
   Functions  : 22
   Addresses  : 00421CC0 - 006C4AF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00421CC0) --------------------------------------------------------  // acclient.c:93446
char __thiscall CLanguageInfoInterface::GetNumDecDigits(CLanguageInfoInterface *this, unsigned __int16 *_digits)
{
  char result; // al@2

  if ( this->m_pLanguageInfo )
  {
    *_digits = this->m_pLanguageInfo->numDecimalDigits;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00421CE0) --------------------------------------------------------  // acclient.c:93463
char __thiscall CLanguageInfoInterface::GetLeadingZero(CLanguageInfoInterface *this, bool *_zero)
{
  char result; // al@2

  if ( this->m_pLanguageInfo )
  {
    *_zero = this->m_pLanguageInfo->leadingZero;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00421D00) --------------------------------------------------------  // acclient.c:93480
char __thiscall CLanguageInfoInterface::GetBase(CLanguageInfoInterface *this, unsigned __int16 *_base)
{
  char result; // al@2

  if ( this->m_pLanguageInfo )
  {
    *_base = this->m_pLanguageInfo->base;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00421D20) --------------------------------------------------------  // acclient.c:93497
char __thiscall CLanguageInfoInterface::GetGroupingSize(CLanguageInfoInterface *this, unsigned __int16 *_size)
{
  char result; // al@2

  if ( this->m_pLanguageInfo )
  {
    *_size = this->m_pLanguageInfo->groupingSize;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00421D40) --------------------------------------------------------  // acclient.c:93514
char __thiscall CLanguageInfoInterface::IsNumberSingular(CLanguageInfoInterface *this, int num)
{
  CLanguageInfo *v2; // eax@1

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    if ( num )
    {
      if ( num == 1 )
      {
        if ( v2->isOneSingular )
          return 1;
      }
      else if ( num == -1 )
      {
        if ( v2->isNegativeOneSingular )
          return 1;
      }
      else
      {
        if ( num > 1 && v2->isTwoOrMoreSingular )
          return 1;
        if ( num < -1 && v2->isNegativeTwoOrLessSingular )
          return 1;
      }
    }
    else if ( v2->isZeroSingular )
    {
      return 1;
    }
  }
  return 0;
}

//----- (00421DA0) --------------------------------------------------------  // acclient.c:93550
char __cdecl CLanguageInfoInterface::Startup()
{
  CLanguageInfoInterface *v0; // eax@1
  CLanguageInfoInterface *v1; // esi@1
  int v2; // eax@2

  v0 = (CLanguageInfoInterface *)operator new(4u);
  v1 = v0;
  if ( v0 )
  {
    v0->m_pLanguageInfo = 0;
    CLanguageInfoInterface::m_instance = v0;
    v2 = DBObj::GetByEnum(1, 4, 0x30u);
    if ( v2 )
    {
      v1->m_pLanguageInfo = (CLanguageInfo *)v2;
      return 1;
    }
  }
  else
  {
    CLanguageInfoInterface::m_instance = 0;
  }
  return 0;
}

//----- (00421DF0) --------------------------------------------------------  // acclient.c:93577
char __cdecl CLanguageInfoInterface::Shutdown()
{
  CLanguageInfoInterface *v0; // esi@1

  v0 = CLanguageInfoInterface::m_instance;
  if ( CLanguageInfoInterface::m_instance )
  {
    if ( CLanguageInfoInterface::m_instance->m_pLanguageInfo )
    {
      ((void (*)(void))CLanguageInfoInterface::m_instance->m_pLanguageInfo->vfptr->Release)();
      v0->m_pLanguageInfo = 0;
    }
    operator delete(v0);
  }
  CLanguageInfoInterface::m_instance = 0;
  return 1;
}

//----- (00421E30) --------------------------------------------------------  // acclient.c:93596
void __cdecl Serializer::SerializeObject(bool *io_object, Archive *io_archive)
{
  bool v2; // bl@1
  unsigned int v3; // eax@1
  bool v4; // zf@6

  v2 = *io_object;
  Archive::CheckAlignment(io_archive, 1u);
  v3 = Archive::GetBytes(io_archive, 1u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_BYTE *)v3 = v2;
    else
      v2 = *(_BYTE *)v3;
  }
  if ( io_archive->m_flags & 5 )
    goto LABEL_9;
  v4 = v2 == 0;
  if ( v2 )
  {
    if ( v2 != 1 )
      Archive::RaiseError(io_archive);
LABEL_9:
    v4 = v2 == 0;
  }
  *io_object = !v4;
}

//----- (00421E80) --------------------------------------------------------  // acclient.c:93626
void __thiscall CLanguageInfo::CLanguageInfo(CLanguageInfo *this)
{
  CLanguageInfo *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  volatile LONG *v6; // ST00_4@1
  volatile LONG *v7; // ST00_4@1
  volatile LONG *v8; // ST00_4@1
  volatile LONG *v9; // ST00_4@1
  volatile LONG *v10; // ST00_4@1
  volatile LONG *v11; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_15);
  v1->vfptr = (InterfaceVtbl *)&CLanguageInfo::vftable;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->numerals.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->decimalSeperator.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->groupingSeperator.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->negativeNumberFormat.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v5);
  v6 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->treasurePrefixLetters.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v6);
  v7 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->treasureMiddleLetters.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v7);
  v8 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->treasureSuffixLetters.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v8);
  v9 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->malePlayerLetters.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v9);
  v10 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->femalePlayerLetters.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v10);
  v11 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_additionalSettings.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v11);
}
// 795B20: using guessed type __int32 (__stdcall *CLanguageInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00421F60) --------------------------------------------------------  // acclient.c:93683
void __thiscall CLanguageInfo::~CLanguageInfo(CLanguageInfo *this)
{
  CLanguageInfo *v1; // esi@1
  char *v2; // edi@1
  int v3; // edi@4
  int v4; // edi@7
  int v5; // edi@10
  int v6; // edi@13
  int v7; // edi@16
  int v8; // edi@19
  int v9; // edi@22
  int v10; // edi@25
  int v11; // edi@28

  v1 = this;
  v2 = (char *)&this->m_additionalSettings.m_charbuffer[-1].m_data[6];
  this->vfptr = (InterfaceVtbl *)&CLanguageInfo::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->femalePlayerLetters.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->malePlayerLetters.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = (int)&v1->treasureSuffixLetters.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  v6 = (int)&v1->treasureMiddleLetters.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v7 = (int)&v1->treasurePrefixLetters.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  v8 = (int)&v1->negativeNumberFormat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  v9 = (int)&v1->groupingSeperator.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  v10 = (int)&v1->decimalSeperator.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v10 + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = (int)&v1->numerals.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)(v11 + 4)) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 795B20: using guessed type __int32 (__stdcall *CLanguageInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (004220B0) --------------------------------------------------------  // acclient.c:93734
void __cdecl CLanguageInfo::Allocator()
{
  CLanguageInfo *v0; // eax@1

  v0 = (CLanguageInfo *)operator new(0xB8u);
  if ( v0 )
    CLanguageInfo::CLanguageInfo(v0);
}

//----- (004220D0) --------------------------------------------------------  // acclient.c:93744
CLanguageInfo *__thiscall CLanguageInfo::vector_deleting_destructor(CLanguageInfo *this, unsigned int a2)
{
  CLanguageInfo *v2; // esi@1

  v2 = this;
  CLanguageInfo::~CLanguageInfo(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004220F0) --------------------------------------------------------  // acclient.c:93756
char __thiscall CLanguageInfoInterface::GetNumerals(CLanguageInfoInterface *this, PStringBase<unsigned short> *_nums)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = _nums->m_charbuffer;
    if ( _nums->m_charbuffer != v2->numerals.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->numerals.m_charbuffer;
      _nums->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00422140) --------------------------------------------------------  // acclient.c:93790
char __thiscall CLanguageInfoInterface::GetGroupingSeperator(CLanguageInfoInterface *this, PStringBase<unsigned short> *_sep)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = _sep->m_charbuffer;
    if ( _sep->m_charbuffer != v2->groupingSeperator.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->groupingSeperator.m_charbuffer;
      _sep->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00422190) --------------------------------------------------------  // acclient.c:93824
char __thiscall CLanguageInfoInterface::GetDecimalSeperator(CLanguageInfoInterface *this, PStringBase<unsigned short> *_dec)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = _dec->m_charbuffer;
    if ( _dec->m_charbuffer != v2->decimalSeperator.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->decimalSeperator.m_charbuffer;
      _dec->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004221E0) --------------------------------------------------------  // acclient.c:93858
char __thiscall CLanguageInfoInterface::GetNegNumFormat(CLanguageInfoInterface *this, PStringBase<unsigned short> *_neg)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = _neg->m_charbuffer;
    if ( _neg->m_charbuffer != v2->negativeNumberFormat.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->negativeNumberFormat.m_charbuffer;
      _neg->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00422230) --------------------------------------------------------  // acclient.c:93892
char __thiscall CLanguageInfoInterface::GetMaleMetaLetters(CLanguageInfoInterface *this, PStringBase<unsigned short> *letters)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = letters->m_charbuffer;
    if ( letters->m_charbuffer != v2->malePlayerLetters.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->malePlayerLetters.m_charbuffer;
      letters->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00422280) --------------------------------------------------------  // acclient.c:93926
char __thiscall CLanguageInfoInterface::GetFemaleMetaLetters(CLanguageInfoInterface *this, PStringBase<unsigned short> *letters)
{
  CLanguageInfo *v2; // edi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@2
  int v4; // esi@3
  PSRefBufferCharData<unsigned short> *v5; // edi@6
  char result; // al@7

  v2 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v3 = letters->m_charbuffer;
    if ( letters->m_charbuffer != v2->femalePlayerLetters.m_charbuffer )
    {
      v4 = (int)&v3[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v3[-1].m_data[8]) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = v2->femalePlayerLetters.m_charbuffer;
      letters->m_charbuffer = v5;
      InterlockedIncrement((volatile LONG *)&v5[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004222D0) --------------------------------------------------------  // acclient.c:93960
char __thiscall CLanguageInfoInterface::GetTreasureMetaLetters(CLanguageInfoInterface *this, PStringBase<unsigned short> *pre, PStringBase<unsigned short> *mid, PStringBase<unsigned short> *suffix)
{
  CLanguageInfoInterface *v4; // ebp@1
  CLanguageInfo *v5; // esi@1
  PSRefBufferCharData<unsigned short> *v6; // eax@2
  int v7; // edi@3
  PSRefBufferCharData<unsigned short> *v8; // esi@6
  PSRefBufferCharData<unsigned short> *v9; // eax@7
  int v10; // esi@7
  int v11; // edi@8
  PSRefBufferCharData<unsigned short> *v12; // esi@11
  PSRefBufferCharData<unsigned short> *v13; // eax@12
  int v14; // esi@12
  int v15; // edi@13
  PSRefBufferCharData<unsigned short> *v16; // esi@16
  char result; // al@17

  v4 = this;
  v5 = this->m_pLanguageInfo;
  if ( this->m_pLanguageInfo )
  {
    v6 = pre->m_charbuffer;
    if ( pre->m_charbuffer != v5->treasurePrefixLetters.m_charbuffer )
    {
      v7 = (int)&v6[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v6[-1].m_data[8]) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      v8 = v5->treasurePrefixLetters.m_charbuffer;
      pre->m_charbuffer = v8;
      InterlockedIncrement((volatile LONG *)&v8[-1].m_data[8]);
    }
    v9 = mid->m_charbuffer;
    v10 = (int)&v4->m_pLanguageInfo->treasureMiddleLetters;
    if ( mid->m_charbuffer != *(PSRefBufferCharData<unsigned short> **)v10 )
    {
      v11 = (int)&v9[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v9[-1].m_data[8]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = *(PSRefBufferCharData<unsigned short> **)v10;
      mid->m_charbuffer = v12;
      InterlockedIncrement((volatile LONG *)&v12[-1].m_data[8]);
    }
    v13 = suffix->m_charbuffer;
    v14 = (int)&v4->m_pLanguageInfo->treasureSuffixLetters;
    if ( suffix->m_charbuffer != *(PSRefBufferCharData<unsigned short> **)v14 )
    {
      v15 = (int)&v13[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&v13[-1].m_data[8]) )
      {
        if ( v15 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
      }
      v16 = *(PSRefBufferCharData<unsigned short> **)v14;
      suffix->m_charbuffer = v16;
      InterlockedIncrement((volatile LONG *)&v16[-1].m_data[8]);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004223B0) --------------------------------------------------------  // acclient.c:94026
void __thiscall PStringBase<unsigned short>::Serialize(PStringBase<unsigned short> *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  PStringBase<unsigned short> *v3; // ebx@1
  unsigned int v4; // ebp@4
  unsigned int v5; // edi@4

  v2 = io_archive;
  v3 = this;
  if ( io_archive->m_flags & 1 )
    io_archive = (Archive *)(*(_DWORD *)&this->m_charbuffer[-1].m_data[14] - 1);
  SB_As32Bit_Compressed::Serialize((const int *)&io_archive, (unsigned int *)&io_archive, v2);
  if ( !((v2->m_flags >> 2) & 1) )
  {
    v4 = (unsigned int)io_archive;
    v5 = 2 * (_DWORD)io_archive;
    if ( ~LOBYTE(v2->m_flags) & 1 )
    {
      if ( v5 > Archive::GetSizeLeft(v2) )
      {
        Archive::RaiseError(v2);
        return;
      }
      ReferenceCountTemplate<268435456,0>::Release((ReferenceCountTemplate<268435456,0> *)&v3->m_charbuffer[-1].m_data[6]);
      PStringBase<unsigned short>::allocate_ref_buffer(v3, v4);
      v3->m_charbuffer->m_data[v5 / 2] = 0;
    }
    Serializer::SerializeBytes((char *)v3->m_charbuffer, v5, v2);
  }
}

//----- (00422450) --------------------------------------------------------  // acclient.c:94058
void __thiscall CLanguageInfo::Serialize(CLanguageInfo *this, Archive *io_archive)
{
  CLanguageInfo *v2; // edi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@5
  unsigned int v5; // eax@9
  unsigned int v6; // eax@13
  unsigned int v7; // eax@17
  unsigned int v8; // eax@21
  unsigned int v9; // eax@25
  unsigned int v10; // eax@29
  unsigned int v11; // eax@33
  unsigned int v12; // eax@37
  unsigned int v13; // eax@41
  unsigned int v14; // eax@45
  unsigned int v15; // eax@49
  unsigned int v16; // eax@53
  unsigned int v17; // eax@57
  unsigned int v18; // eax@61
  unsigned int v19; // eax@65
  unsigned int v20; // eax@69
  unsigned int v21; // eax@73
  unsigned int v22; // eax@77
  unsigned int v23; // eax@81
  unsigned int v24; // eax@85
  unsigned int v25; // eax@89

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->version;
    else
      v2->version = *(_DWORD *)v3;
  }
  Archive::CheckAlignment(io_archive, 2u);
  v4 = Archive::GetBytes(io_archive, 2u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_WORD *)v4 = v2->base;
    else
      v2->base = *(_WORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 2u);
  v5 = Archive::GetBytes(io_archive, 2u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_WORD *)v5 = v2->numDecimalDigits;
    else
      v2->numDecimalDigits = *(_WORD *)v5;
  }
  Serializer::SerializeObject(&v2->leadingZero, io_archive);
  Archive::CheckAlignment(io_archive, 2u);
  v6 = Archive::GetBytes(io_archive, 2u);
  if ( v6 )
  {
    if ( io_archive->m_flags & 1 )
      *(_WORD *)v6 = v2->groupingSize;
    else
      v2->groupingSize = *(_WORD *)v6;
  }
  PStringBase<unsigned short>::Serialize(&v2->numerals, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->decimalSeperator, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->groupingSeperator, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->negativeNumberFormat, io_archive);
  Serializer::SerializeObject(&v2->isZeroSingular, io_archive);
  Serializer::SerializeObject(&v2->isOneSingular, io_archive);
  Serializer::SerializeObject(&v2->isNegativeOneSingular, io_archive);
  Serializer::SerializeObject(&v2->isTwoOrMoreSingular, io_archive);
  Serializer::SerializeObject(&v2->isNegativeTwoOrLessSingular, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->treasurePrefixLetters, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->treasureMiddleLetters, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->treasureSuffixLetters, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->malePlayerLetters, io_archive);
  PStringBase<unsigned short>::Serialize(&v2->femalePlayerLetters, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v7 = v2->m_ImeEnabledSetting;
    else
      v2->m_ImeEnabledSetting = *(_DWORD *)v7;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v8 = Archive::GetBytes(io_archive, 4u);
  if ( v8 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v8 = v2->m_symbolColor;
    else
      v2->m_symbolColor = *(_DWORD *)v8;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v9 = Archive::GetBytes(io_archive, 4u);
  if ( v9 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v9 = v2->m_symbolColorText;
    else
      v2->m_symbolColorText = *(_DWORD *)v9;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v10 = Archive::GetBytes(io_archive, 4u);
  if ( v10 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v10 = v2->m_symbolHeight;
    else
      v2->m_symbolHeight = *(_DWORD *)v10;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v11 = Archive::GetBytes(io_archive, 4u);
  if ( v11 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v11 = v2->m_symbolTranslucence;
    else
      v2->m_symbolTranslucence = *(_DWORD *)v11;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v12 = Archive::GetBytes(io_archive, 4u);
  if ( v12 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v12 = v2->m_symbolPlacement;
    else
      v2->m_symbolPlacement = *(_DWORD *)v12;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v13 = Archive::GetBytes(io_archive, 4u);
  if ( v13 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v13 = v2->m_candColorBase;
    else
      v2->m_candColorBase = *(_DWORD *)v13;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v14 = Archive::GetBytes(io_archive, 4u);
  if ( v14 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v14 = v2->m_candColorBorder;
    else
      v2->m_candColorBorder = *(_DWORD *)v14;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v15 = Archive::GetBytes(io_archive, 4u);
  if ( v15 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v15 = v2->m_candColorText;
    else
      v2->m_candColorText = *(_DWORD *)v15;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v16 = Archive::GetBytes(io_archive, 4u);
  if ( v16 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v16 = v2->m_compColorInput;
    else
      v2->m_compColorInput = *(_DWORD *)v16;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v17 = Archive::GetBytes(io_archive, 4u);
  if ( v17 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v17 = v2->m_compColorTargetConv;
    else
      v2->m_compColorTargetConv = *(_DWORD *)v17;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v18 = Archive::GetBytes(io_archive, 4u);
  if ( v18 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v18 = v2->m_compColorConverted;
    else
      v2->m_compColorConverted = *(_DWORD *)v18;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v19 = Archive::GetBytes(io_archive, 4u);
  if ( v19 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v19 = v2->m_compColorTargetNotConv;
    else
      v2->m_compColorTargetNotConv = *(_DWORD *)v19;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v20 = Archive::GetBytes(io_archive, 4u);
  if ( v20 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v20 = v2->m_compColorInputErr;
    else
      v2->m_compColorInputErr = *(_DWORD *)v20;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v21 = Archive::GetBytes(io_archive, 4u);
  if ( v21 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v21 = v2->m_compTranslucence;
    else
      v2->m_compTranslucence = *(_DWORD *)v21;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v22 = Archive::GetBytes(io_archive, 4u);
  if ( v22 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v22 = v2->m_compColorText;
    else
      v2->m_compColorText = *(_DWORD *)v22;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v23 = Archive::GetBytes(io_archive, 4u);
  if ( v23 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v23 = v2->m_otherIME;
    else
      v2->m_otherIME = *(_DWORD *)v23;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v24 = Archive::GetBytes(io_archive, 4u);
  if ( v24 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v24 = v2->m_wordWrapOnSpace;
    else
      v2->m_wordWrapOnSpace = *(_DWORD *)v24;
  }
  PStringBase<unsigned short>::Serialize(&v2->m_additionalSettings, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v25 = Archive::GetBytes(io_archive, 4u);
  if ( v25 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v25 = v2->m_additionalFlags;
    else
      v2->m_additionalFlags = *(_DWORD *)v25;
  }
}

//----- (006C4AF0) --------------------------------------------------------  // acclient.c:733043
int _E1_15()
{
  return atexit(_E2_15);
}

