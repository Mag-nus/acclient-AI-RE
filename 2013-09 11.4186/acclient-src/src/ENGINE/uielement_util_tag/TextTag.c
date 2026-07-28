/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTag
   Object     : ENGINE\uielement_util_tag\TextTag.obj
   Functions  : 6
   Addresses  : 00478F80 - 00479230 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478F80) --------------------------------------------------------  // acclient.c:182184
void __thiscall TextTag::TextTag(TextTag *this)
{
  this->m_cRef = 1;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag::vftable;
  this->m_type = 0;
  this->m_format = 0;
}
// 79E134: using guessed type int (__thiscall *TextTag::vftable)(void *, char);

//----- (00478FA0) --------------------------------------------------------  // acclient.c:182194
void __thiscall TextTag::~TextTag(TextTag *this)
{
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)TimerInstance<TimeSource_QueryPerformanceCounter>::vftable;
}
// 7942F4: using guessed type int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char);

//----- (00478FB0) --------------------------------------------------------  // acclient.c:182201
bool __stdcall TextTag::ParseStartTag(PStringBase<unsigned short> _txt)
{
  if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8])
    && _txt.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))&_txt.m_charbuffer[-1].m_data[6])(
      &_txt.m_charbuffer[-1].m_data[6],
      1);
  return 0;
}

//----- (00478FE0) --------------------------------------------------------  // acclient.c:182212
char __thiscall TextTag::BuildStartTag(TextTag *this, PStringBase<unsigned short> *_txt)
{
  TextTag *v2; // esi@1
  char *v3; // esi@2
  LONG (__stdcall *v5)(volatile LONG *); // edi@6
  char *v6; // esi@6
  char *v7; // esi@8
  LONG v8; // eax@6
  char *v9; // esi@15
  char *v10; // esi@19
  char *v11; // esi@22
  char *v12; // esi@25
  PStringBase<unsigned short> sType; // [sp+Ch] [bp-Ch]@1
  PStringBase<unsigned short> sFormat; // [sp+10h] [bp-8h]@5
  PStringBase<unsigned short> sData; // [sp+14h] [bp-4h]@7

  sType.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !EnumMapper::InqString(0x18u, v2->m_type, &sType) )
  {
    v3 = (char *)&sType.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&sType.m_charbuffer[-1].m_data[8]) && v3 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      return 0;
    }
    return 0;
  }
  sFormat.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !EnumMapper::InqString(0x18u, v2->m_format, &sFormat) )
  {
    v5 = InterlockedDecrement;
    v6 = (char *)&sFormat.m_charbuffer[-1].m_data[6];
    v8 = InterlockedDecrement((volatile LONG *)&sFormat.m_charbuffer[-1].m_data[8]);
LABEL_12:
    if ( !v8 && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v9 = (char *)&sType.m_charbuffer[-1].m_data[6];
    if ( !v5((volatile LONG *)&sType.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    return 0;
  }
  sData.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !(unsigned __int8)v2->vfptr[6].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, (unsigned int)&sData) )
  {
    v5 = InterlockedDecrement;
    v7 = (char *)&sData.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&sData.m_charbuffer[-1].m_data[8]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v6 = (char *)&sFormat.m_charbuffer[-1].m_data[6];
    v8 = InterlockedDecrement((volatile LONG *)&sFormat.m_charbuffer[-1].m_data[8]);
    goto LABEL_12;
  }
  PStringBase<unsigned short>::sprintf(
    _txt,
    L"<%ls:%ls%:%ls>",
    sType.m_charbuffer,
    sFormat.m_charbuffer,
    sData.m_charbuffer);
  v10 = (char *)&sData.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&sData.m_charbuffer[-1].m_data[8]) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  v11 = (char *)&sFormat.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&sFormat.m_charbuffer[-1].m_data[8]) && v11 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
  v12 = (char *)&sType.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&sType.m_charbuffer[-1].m_data[8]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  return 1;
}

//----- (00479190) --------------------------------------------------------  // acclient.c:182287
char __thiscall TextTag::BuildEndTag(TextTag *this, PStringBase<unsigned short> *_txt)
{
  TextTag *v2; // esi@1
  char *v3; // esi@3
  char *v5; // esi@7
  PStringBase<unsigned short> typeStr; // [sp+0h] [bp-4h]@1

  typeStr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  if ( !this->m_type )
    return 0;
  typeStr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !EnumMapper::InqString(0x18u, v2->m_type, &typeStr) )
  {
    v3 = (char *)&typeStr.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    return 0;
  }
  PStringBase<unsigned short>::sprintf(_txt, L"<\\%ls>", typeStr.m_charbuffer);
  v5 = (char *)&typeStr.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&typeStr.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (00479230) --------------------------------------------------------  // acclient.c:182318
bool __thiscall TextTag::ParseEndTag(TextTag *this, PStringBase<unsigned short> _txt)
{
  TextTag *v2; // ebx@1
  unsigned int v3; // eax@1
  char *v4; // esi@2
  PSRefBufferCharData<unsigned short> *v6; // edx@5
  unsigned __int16 v7; // si@7
  char *v8; // edx@8
  bool v9; // cf@12
  bool v10; // zf@12
  char *v11; // eax@12
  int v12; // eax@15
  bool v13; // bl@22
  char *v14; // esi@23
  PStringBase<unsigned short> v15; // [sp-8h] [bp-2Ch]@18
  unsigned int *v16; // [sp-4h] [bp-28h]@18
  PStringBase<unsigned short> typeStr; // [sp+Ch] [bp-18h]@17
  unsigned int typeEnum; // [sp+10h] [bp-14h]@18
  PStringBaseIter_Const<unsigned short> iter; // [sp+14h] [bp-10h]@15

  v2 = this;
  v3 = *(_DWORD *)&_txt.m_charbuffer[-1].m_data[14];
  if ( v3 - 1 >= 2 )
  {
    v6 = (PSRefBufferCharData<unsigned short> *)((char *)_txt.m_charbuffer + 2 * v3 - 2);
    if ( v3 )
      v6 = _txt.m_charbuffer;
    v7 = v6->m_data[0];
    if ( v3 - 2 < v3 )
      v8 = (char *)_txt.m_charbuffer + 2 * (v3 - 2);
    else
      v8 = (char *)_txt.m_charbuffer + 2 * v3 - 2;
    if ( v7 == 60 && *(_WORD *)v8 == 62 )
    {
      v9 = v3 < 1;
      v10 = v3 == 1;
      v11 = (char *)_txt.m_charbuffer + 2 * v3 - 2;
      if ( !v9 && !v10 )
        v11 = (char *)&_txt.m_charbuffer->m_data[1];
      if ( *(_WORD *)v11 == 92 )
      {
        iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
        iter.pstring_ptr = &_txt;
        iter.mark = 0;
        iter.curr = 0;
        PStringBaseIter_Common<unsigned short>::Next((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, 2);
        iter.mark = iter.curr;
        v12 = iter.vfptr->GetStrLen(&iter);
        if ( (unsigned int)v12 >= 1 )
        {
          iter.curr = v12 - 1;
          PStringBaseIter_Common<unsigned short>::GetSubString(
            (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
            &typeStr);
          if ( *(_DWORD *)&typeStr.m_charbuffer[-1].m_data[14] != 1 )
          {
            v16 = &typeEnum;
            v15.m_charbuffer = typeStr.m_charbuffer;
            typeEnum = 0;
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (CaseInsensitiveStringBase<PStringBase<char> > *)&v15,
              (PStringBase<char> *)&typeStr);
            if ( EnumMapper::InqEnum(0x18u, v15, v16) )
            {
              v13 = v2->m_type == typeEnum;
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&typeStr);
              iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
              return v13;
            }
          }
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&typeStr);
        }
        else
        {
          iter.curr = 0;
        }
        iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
      }
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
      return 0;
    }
    v14 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v14 )
      (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
  }
  else
  {
    v4 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v4 )
    {
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
      return 0;
    }
  }
  return 0;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

