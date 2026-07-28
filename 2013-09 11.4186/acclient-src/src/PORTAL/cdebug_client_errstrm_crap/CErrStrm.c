/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CErrStrm
   Object     : PORTAL\cdebug_client_errstrm_crap\CErrStrm.obj
   Functions  : 8
   Addresses  : 00554B80 - 007727D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00554B80) --------------------------------------------------------  // acclient.c:387925
int __thiscall ErrorStream::operator<<(ErrorStream *this, ErrorStream *(__cdecl *f)(ErrorStream *))
{
  return f(this);
}

//----- (00554B90) --------------------------------------------------------  // acclient.c:387931
void __thiscall ErrorStream::output(ErrorStream *this)
{
  ErrorStream *v1; // edi@1
  PSRefBufferCharData<char> *v2; // eax@1
  int v3; // esi@2
  volatile LONG *v4; // ST00_4@5

  v1 = this;
  IError::ReportDataError(this->m_strBuffer.m_charbuffer->m_data);
  v2 = v1->m_strBuffer.m_charbuffer;
  if ( v1->m_strBuffer.m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v1->m_strBuffer.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v4);
  }
}

//----- (00554BE0) --------------------------------------------------------  // acclient.c:387956
ErrorStream *__cdecl endp(ErrorStream *out)
{
  ErrorStream::output(out);
  return out;
}

//----- (00554BF0) --------------------------------------------------------  // acclient.c:387963
ErrorStream *__thiscall ErrorStream::operator<<(ErrorStream *this, const char *input)
{
  ErrorStream *v2; // esi@1

  v2 = this;
  if ( input && *input )
    PStringBase<char>::append_n_chars(&this->m_strBuffer, input, strlen(input));
  return v2;
}

//----- (00554C20) --------------------------------------------------------  // acclient.c:387974
ErrorStream *__thiscall ErrorStream::operator<<(ErrorStream *this, IDClass<_tagDataID,32,0> did)
{
  ErrorStream *v2; // esi@1

  v2 = this;
  PStringBase<char>::sprintf_append(&this->m_strBuffer, "0x%08X", did.id);
  return v2;
}

//----- (00554C40) --------------------------------------------------------  // acclient.c:387984
void PopupError(const char *fmt, ...)
{
  PStringBase<unsigned short> v1; // ST08_4@1
  char *v2; // esi@1
  PStringBase<unsigned short> strWide; // [sp+4h] [bp-404h]@1
  char buf[1024]; // [sp+8h] [bp-400h]@1
  va_list va; // [sp+410h] [bp+8h]@1

  va_start(va, fmt);
  __vsnprintf(buf, 0x400u, fmt, va);
  PStringBase<unsigned short>::PStringBase<unsigned short>(&strWide, 0, buf);
  v1.m_charbuffer = strWide.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&strWide.m_charbuffer[-1].m_data[8]);
  PlatformString::DisplayFinalString(v1, 0);
  v2 = (char *)&strWide.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&strWide.m_charbuffer[-1].m_data[8]) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}

//----- (00706ED0) --------------------------------------------------------  // acclient.c:794175
int sub_706ED0()
{
  perr.m_strBuffer.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(_E74_78);
}

//----- (007727D0) --------------------------------------------------------  // acclient.c:906419
void __cdecl _E74_78()
{
  char *v0; // esi@1

  v0 = &perr.m_strBuffer.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&perr.m_strBuffer.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

