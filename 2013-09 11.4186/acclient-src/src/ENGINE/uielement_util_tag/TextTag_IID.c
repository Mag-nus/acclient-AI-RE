/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTag_IID
   Object     : ENGINE\uielement_util_tag\TextTag_IID.obj
   Functions  : 5
   Addresses  : 00478E60 - 00478F60 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478E60) --------------------------------------------------------  // acclient.c:182117
void __thiscall TextTag_IID::TextTag_IID(TextTag_IID *this)
{
  TextTag_IID *v1; // esi@1

  v1 = this;
  TextTag::TextTag((TextTag *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IID::vftable;
  v1->m_IID = 0;
}
// 79E118: using guessed type int (__thiscall *TextTag_IID::vftable)(void *, char);

//----- (00478E80) --------------------------------------------------------  // acclient.c:182129
char __thiscall TextTag_IID::HandleClick(TextTag_IID *this, unsigned int _button)
{
  ECM_UI::SendNotice_TextTag_IIDClick(this->m_type, this->m_IID);
  return 1;
}

//----- (00478EA0) --------------------------------------------------------  // acclient.c:182136
TextTag_IID *__thiscall TextTag_IID::scalar_deleting_destructor(TextTag_IID *this, unsigned int a2)
{
  TextTag_IID *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_IID::vftable;
  TextTag::~TextTag((TextTag *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E118: using guessed type int (__thiscall *TextTag_IID::vftable)(void *, char);

//----- (00478ED0) --------------------------------------------------------  // acclient.c:182150
char __thiscall TextTag_DID::ParseStartTag(TextTag_IID *this, PStringBase<unsigned short> _txt)
{
  TextTag_IID *v2; // edi@1
  char result; // al@5

  v2 = this;
  InterlockedIncrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8]);
  if ( PSUtils::is_uint32(_txt) )
  {
    *__errno() = 0;
    v2->m_IID = _wcstoul(_txt.m_charbuffer->m_data, 0, 0);
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8])
      && _txt.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&_txt.m_charbuffer[-1].m_data[6])(&_txt.m_charbuffer[-1].m_data[6], 1);
    result = 1;
  }
  else
  {
    if ( !InterlockedDecrement((volatile LONG *)&_txt.m_charbuffer[-1].m_data[8])
      && _txt.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&_txt.m_charbuffer[-1].m_data[6])(&_txt.m_charbuffer[-1].m_data[6], 1);
    result = 0;
  }
  return result;
}

//----- (00478F60) --------------------------------------------------------  // acclient.c:182177
char __thiscall TextTag_IID::BuildStartTagData(TextTag_IID *this, PStringBase<unsigned short> *_txt)
{
  PStringBase<unsigned short>::sprintf(_txt, L"0x%08X", this->m_IID);
  return 1;
}

