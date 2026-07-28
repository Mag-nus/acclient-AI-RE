/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTag_IIDString
   Object     : ENGINE\uielement_util_tag\TextTag_IIDString.obj
   Functions  : 5
   Addresses  : 00478840 - 00478910 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478840) --------------------------------------------------------  // acclient.c:181788
char __thiscall TextTag_IIDString::HandleClick(TextTag_IIDString *this, unsigned int _button)
{
  ECM_UI::SendNotice_TextTag_IIDStringClick(this->m_type, this->m_IID, &this->m_string);
  return 1;
}

//----- (00478860) --------------------------------------------------------  // acclient.c:181795
void __thiscall TextTag_IIDString::TextTag_IIDString(TextTag_IIDString *this)
{
  TextTag_IIDString *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  TextTag::TextTag((TextTag *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IIDString::vftable;
  v1->m_IID = 0;
  v2 = (volatile LONG *)(PStringBase<unsigned short>::s_NullBuffer - 8);
  v1->m_string.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement(v2);
}
// 79E0C8: using guessed type int (__thiscall *TextTag_IIDString::vftable)(void *, char);

//----- (00478890) --------------------------------------------------------  // acclient.c:181811
TextTag *__thiscall TextTag_IIDString::vector_deleting_destructor(TextTag_IIDString *this, unsigned int a2)
{
  TextTag *v2; // edi@1
  char *v3; // esi@1

  v2 = (TextTag *)this;
  v3 = (char *)&this->m_string.m_charbuffer[-1].m_data[6];
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IIDString::vftable;
  if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  TextTag::~TextTag(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E0C8: using guessed type int (__thiscall *TextTag_IIDString::vftable)(void *, char);

//----- (004788E0) --------------------------------------------------------  // acclient.c:181829
char __thiscall TextTag_IIDString::BuildStartTagData(TextTag_IIDString *this, PStringBase<unsigned short> *_txt)
{
  char result; // al@2

  if ( *(_DWORD *)&this->m_string.m_charbuffer[-1].m_data[14] == 1 )
  {
    result = 0;
  }
  else
  {
    PStringBase<unsigned short>::sprintf(_txt, L"0x%08X:%ls", this->m_IID, this->m_string.m_charbuffer);
    result = 1;
  }
  return result;
}

//----- (00478910) --------------------------------------------------------  // acclient.c:181846
char __thiscall TextTag_IIDString::ParseStartTag(TextTag_IIDString *this, PStringBase<unsigned short> _txt)
{
  TextTag_IIDString *v2; // edi@1
  char *v3; // esi@2
  char result; // al@4
  PSRefBufferCharData<unsigned short> *v5; // esi@5
  char *v6; // esi@6
  char *v7; // esi@9
  PStringBase<unsigned short> v8; // ST04_4@12
  int v9; // esi@13
  char *v10; // esi@16
  unsigned int v11; // esi@20
  unsigned int v12; // eax@21
  PStringBase<unsigned short> paramStr; // [sp+8h] [bp-18h]@23
  PStringBase<unsigned short> iidStr; // [sp+Ch] [bp-14h]@5
  PStringBaseIter_Const<unsigned short> iter; // [sp+10h] [bp-10h]@1

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
  v8.m_charbuffer = iidStr.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&iidStr.m_charbuffer[-1].m_data[8]);
  if ( !PSUtils::is_uint32(v8) )
  {
    v9 = (int)&v5[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    v10 = (char *)&_txt.m_charbuffer[-1].m_data[6];
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]) && v10 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
    return 0;
  }
  v11 = iter.curr + 1;
  if ( v11 <= iter.vfptr->GetStrLen(&iter) )
    v12 = v11;
  else
    v12 = iter.vfptr->GetStrLen(&iter);
  iter.curr = v12;
  iter.mark = v12;
  iter.curr = iter.vfptr->GetStrLen(&iter);
  PStringBaseIter_Common<unsigned short>::GetSubString((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, &paramStr);
  if ( *(_DWORD *)&paramStr.m_charbuffer[-1].m_data[14] == 1 )
  {
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&paramStr);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&iidStr);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
    result = 0;
  }
  else
  {
    v2->m_IID = PStringBase<unsigned short>::to_uint32(&iidStr);
    PStringBase<unsigned short>::operator=(&v2->m_string, (const unsigned __int16 *)&paramStr);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&paramStr);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&iidStr);
    iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Common<unsigned short>::vftable;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
    result = 1;
  }
  return result;
}
// 794478: using guessed type void *PStringBaseIter_Common<unsigned short>::vftable;
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

