/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTag_IIDEnum
   Object     : ENGINE\uielement_util_tag\TextTag_IIDEnum.obj
   Functions  : 5
   Addresses  : 00478B20 - 00478C30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478B20) --------------------------------------------------------  // acclient.c:181944
void __thiscall TextTag_IIDEnum::TextTag_IIDEnum(TextTag_IIDEnum *this)
{
  TextTag_IIDEnum *v1; // esi@1

  v1 = this;
  TextTag::TextTag((TextTag *)&this->vfptr);
  v1->m_IID = 0;
  v1->m_enum = 0;
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IIDEnum::vftable;
}
// 79E0FC: using guessed type int (__thiscall *TextTag_IIDEnum::vftable)(void *, char);

//----- (00478B40) --------------------------------------------------------  // acclient.c:181957
char __thiscall TextTag_IIDEnum::HandleClick(TextTag_IIDEnum *this, unsigned int _button)
{
  ECM_UI::SendNotice_TextTag_IIDEnumClick(this->m_type, this->m_IID, this->m_enum);
  return 1;
}

//----- (00478B60) --------------------------------------------------------  // acclient.c:181964
TextTag_IIDEnum *__thiscall TextTag_IIDEnum::scalar_deleting_destructor(TextTag_IIDEnum *this, unsigned int a2)
{
  TextTag_IIDEnum *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IIDEnum::vftable;
  TextTag::~TextTag((TextTag *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E0FC: using guessed type int (__thiscall *TextTag_IIDEnum::vftable)(void *, char);

//----- (00478B90) --------------------------------------------------------  // acclient.c:181978
char __thiscall TextTag_IIDEnum::BuildStartTagData(TextTag_IIDEnum *this, PStringBase<unsigned short> *_txt)
{
  TextTag_IIDEnum *v2; // esi@1
  char *v3; // esi@3
  char *v5; // esi@7
  PStringBase<unsigned short> enumStr; // [sp+0h] [bp-4h]@1

  enumStr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v2 = this;
  if ( !this->m_enum )
    return 0;
  enumStr.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( !EnumMapper::InqString(0x18u, v2->m_enum, &enumStr) )
  {
    v3 = (char *)&enumStr.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&enumStr.m_charbuffer[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    return 0;
  }
  PStringBase<unsigned short>::sprintf(_txt, L"0x%08X:%ls", v2->m_IID, enumStr.m_charbuffer);
  v5 = (char *)&enumStr.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&enumStr.m_charbuffer[-1].m_data[8]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  return 1;
}

//----- (00478C30) --------------------------------------------------------  // acclient.c:182009
char __thiscall TextTag_IIDEnum::ParseStartTag(TextTag_IIDEnum *this, PStringBase<unsigned short> _txt)
{
  TextTag_IIDEnum *v2; // edi@1
  char *v3; // esi@2
  char result; // al@4
  PSRefBufferCharData<unsigned short> *v5; // esi@5
  char *v6; // esi@6
  char *v7; // esi@9
  int v8; // esi@13
  char *v9; // esi@16
  unsigned int v10; // esi@20
  unsigned int v11; // eax@21
  PSRefBufferCharData<unsigned short> *v12; // ecx@23
  PStringBase<unsigned short> v13; // [sp-8h] [bp-2Ch]@24
  unsigned int *v14; // [sp-4h] [bp-28h]@12
  PStringBase<unsigned short> enumStr; // [sp+8h] [bp-1Ch]@23
  PStringBase<unsigned short> iidStr; // [sp+Ch] [bp-18h]@5
  unsigned int enumEnum; // [sp+10h] [bp-14h]@24
  PStringBaseIter_Const<unsigned short> iter; // [sp+14h] [bp-10h]@1

  v2 = this;
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
  iter.pstring_ptr = &_txt;
  iter.curr = 0;
  iter.mark = 0;
  if ( !PStringBaseIter_Common<unsigned short>::FindChar(
          (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
          0x3Au,
          0) )
  {
    v3 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v3 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      return 0;
    }
    return 0;
  }
  PStringBaseIter_Common<unsigned short>::GetSubString((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, &iidStr);
  v5 = iidStr.m_charbuffer;
  if ( *(_DWORD *)&iidStr.m_charbuffer[-1].m_data[14] == 1 )
  {
    v6 = (char *)&iidStr.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&iidStr.m_charbuffer[-1].m_data[8]) && v6 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    v7 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v7 )
    {
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      return 0;
    }
    return 0;
  }
  v14 = (unsigned int *)iidStr.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&iidStr.m_charbuffer[-1].m_data[8]);
  if ( !PSUtils::is_uint32((PStringBase<unsigned short>)v14) )
  {
    v8 = (int)&v5[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    return 0;
  }
  v10 = iter.curr + 1;
  if ( v10 <= iter.vfptr->GetStrLen(&iter) )
    v11 = v10;
  else
    v11 = iter.vfptr->GetStrLen(&iter);
  iter.curr = v11;
  iter.mark = v11;
  iter.curr = iter.vfptr->GetStrLen(&iter);
  PStringBaseIter_Common<unsigned short>::GetSubString((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, &enumStr);
  if ( *(_DWORD *)&enumStr.m_charbuffer[-1].m_data[14] != 1
    && (v14 = &enumEnum,
        v13.m_charbuffer = v12,
        enumEnum = 0,
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (CaseInsensitiveStringBase<PStringBase<char> > *)&v13,
          (PStringBase<char> *)&enumStr),
        EnumMapper::InqEnum(0x18u, v13, v14)) )
  {
    v2->m_IID = PStringBase<unsigned short>::to_uint32(&iidStr);
    v2->m_enum = enumEnum;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&enumStr);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&iidStr);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
    result = 1;
  }
  else
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&enumStr);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&iidStr);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
    result = 0;
  }
  return result;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

