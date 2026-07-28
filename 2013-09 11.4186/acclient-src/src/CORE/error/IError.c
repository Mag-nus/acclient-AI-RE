/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : IError
   Object     : CORE\error\IError.obj
   Functions  : 8
   Addresses  : 00659EF0 - 00714B90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00659EF0) --------------------------------------------------------  // acclient.c:623836
void IError::ReportGenericError(const char *fmt, ...)
{
  va_list va; // [sp+8h] [bp+8h]@1

  va_start(va, fmt);
  Logger::LogVAList(sev_Error, LC_IError_GeneralError, fmt, va);
}

//----- (00659F10) --------------------------------------------------------  // acclient.c:623845
void IError::ReportDataError(const char *fmt, ...)
{
  va_list va; // [sp+8h] [bp+8h]@1

  va_start(va, fmt);
  Logger::LogVAList(sev_Error, LC_IError_DataError, fmt, va);
}

//----- (00659F30) --------------------------------------------------------  // acclient.c:623854
void __cdecl IError::DefaultAllIErrorCategoriesToProvidedHandler(Logger::ILoggingOutputHandler *i_pHandler)
{
  Logger::AddCategoryHandler(LC_IError_CriticalError, i_pHandler);
  Logger::AddCategoryHandler(LC_IError_GeneralError, i_pHandler);
  Logger::AddCategoryHandler(LC_IError_DataError, i_pHandler);
  Logger::AddCategoryHandler(LC_IError_UserError, i_pHandler);
}

//----- (00659F70) --------------------------------------------------------  // acclient.c:623863
void __cdecl IError::ReportDataError(PStringBase<char> *error_text)
{
  Logger::Log(sev_Error, LC_IError_DataError, error_text->m_charbuffer->m_data);
}

//----- (00714B30) --------------------------------------------------------  // acclient.c:807540
unsigned int sub_714B30()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("IError::CriticalError");
  LC_IError_CriticalError = result;
  return result;
}

//----- (00714B50) --------------------------------------------------------  // acclient.c:807550
unsigned int _E75_1()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("IError::GeneralError");
  LC_IError_GeneralError = result;
  return result;
}

//----- (00714B70) --------------------------------------------------------  // acclient.c:807560
unsigned int _E77_25()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("IError::DataError");
  LC_IError_DataError = result;
  return result;
}

//----- (00714B90) --------------------------------------------------------  // acclient.c:807570
unsigned int _E79_77()
{
  unsigned int result; // eax@1

  result = Logger::CreateLoggingCategory("IError::UserError");
  LC_IError_UserError = result;
  return result;
}

