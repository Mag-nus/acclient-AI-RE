/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTag_DID
   Object     : ENGINE\uielement_util_tag\TextTag_DID.obj
   Functions  : 6
   Addresses  : 00478740 - 006EC430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478740) --------------------------------------------------------  // acclient.c:181727
char __thiscall TextTag_DID::HandleClick(TextTag_DID *this, unsigned int _button)
{
  ECM_UI::SendNotice_TextTag_DIDClick(this->m_type, this->m_DID);
  return 1;
}

//----- (00478760) --------------------------------------------------------  // acclient.c:181734
void __thiscall TextTag_DID::TextTag_DID(TextTag_DID *this)
{
  TextTag_DID *v1; // esi@1

  v1 = this;
  TextTag::TextTag((TextTag *)&this->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_DID::vftable;
  v1->m_DID.id = INVALID_DID_85.id;
}
// 79E09C: using guessed type int (__thiscall *TextTag_DID::vftable)(void *, char);

//----- (00478780) --------------------------------------------------------  // acclient.c:181746
unsigned __int32 __thiscall PStringBase<unsigned short>::to_uint32(PStringBase<unsigned short> *this)
{
  PSRefBufferCharData<unsigned short> *v1; // esi@1

  v1 = this->m_charbuffer;
  *__errno() = 0;
  return _wcstoul(v1->m_data, 0, 0);
}

//----- (004787A0) --------------------------------------------------------  // acclient.c:181756
TextTag_DID *__thiscall TextTag_DID::scalar_deleting_destructor(TextTag_DID *this, unsigned int a2)
{
  TextTag_DID *v2; // esi@1

  v2 = this;
  this->vfptr = (ReferenceCountTemplate<1048576,0>Vtbl *)&TextTag_DID::vftable;
  TextTag::~TextTag((TextTag *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E09C: using guessed type int (__thiscall *TextTag_DID::vftable)(void *, char);

//----- (004787D0) --------------------------------------------------------  // acclient.c:181770
bool __cdecl PSUtils::is_uint32(PStringBase<unsigned short> str)
{
  bool v1; // bl@3
  const unsigned __int16 *end; // [sp+0h] [bp-4h]@1

  end = 0;
  *__errno() = 0;
  _wcstoul(str.m_charbuffer->m_data, (wchar_t **)&end, 0);
  v1 = !*end && *__errno() != 34;
  if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1].m_data[8])
    && str.m_charbuffer != (PSRefBufferCharData<unsigned short> *)20 )
    (**(void (__thiscall ***)(unsigned __int16 *, signed int))&str.m_charbuffer[-1].m_data[6])(
      &str.m_charbuffer[-1].m_data[6],
      1);
  return v1;
}

//----- (006EC430) --------------------------------------------------------  // acclient.c:768115
int _E1_85()
{
  return atexit(_E2_85);
}

