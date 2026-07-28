/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DbgHelpWrapper
   Object     : CORE\dbghelpwrapper\DbgHelpWrapper.obj
   Functions  : 10
   Addresses  : 0040E520 - 006C3B10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040E520) --------------------------------------------------------  // acclient.c:74043
void __cdecl DbgHelpWrapper::FreeDbgHelpFunctions()
{
  if ( g_hDbgHelp )
  {
    G_StackWalk = 0;
    G_SymFunctionTableAccess = 0;
    G_SymSetOptions = 0;
    G_SymGetOptions = 0;
    G_SymInitialize = 0;
    G_SymCleanup = 0;
    G_SymUnloadModule = 0;
    G_SymLoadModule = 0;
    G_SymGetModuleInfo = 0;
    G_SymGetSymFromAddr = 0;
    G_SymGetLineFromAddr = 0;
    FreeLibrary(g_hDbgHelp);
    g_hDbgHelp = 0;
  }
}
// 836830: using guessed type int (__stdcall *G_StackWalk)(unsigned __int32, void *, void *, struct _tagSTACKFRAME *, void *, int (__stdcall *)(void *, unsigned __int32, void *, unsigned __int32, unsigned __int32 *), void *(__stdcall *)(void *, unsigned __int32), unsigned __int32 (__stdcall *)(void *, unsigned __int32), unsigned __int32 (__stdcall *)(void *, void *, struct _tagADDRESS *));
// 836834: using guessed type void *(__stdcall *G_SymFunctionTableAccess)(void *, unsigned __int32);
// 836838: using guessed type unsigned __int32 (__stdcall *G_SymSetOptions)(unsigned __int32);
// 83683C: using guessed type unsigned __int32 (__stdcall *G_SymGetOptions)();
// 836840: using guessed type int (__stdcall *G_SymInitialize)(void *, char *, int);
// 836844: using guessed type int (__stdcall *G_SymCleanup)(void *);
// 836848: using guessed type int (__stdcall *G_SymUnloadModule)(void *, unsigned __int32);
// 83684C: using guessed type unsigned __int32 (__stdcall *G_SymLoadModule)(void *, void *, char *, char *, unsigned __int32, unsigned __int32);
// 836850: using guessed type int (__stdcall *G_SymGetModuleInfo)(void *, unsigned __int32, struct _IMAGEHLP_MODULE *);
// 836854: using guessed type int (__stdcall *G_SymGetSymFromAddr)(void *, unsigned __int32, unsigned __int32 *, struct _IMAGEHLP_SYMBOL *);
// 836858: using guessed type int (__stdcall *G_SymGetLineFromAddr)(void *, unsigned __int32, unsigned __int32 *, struct _IMAGEHLP_LINE *);

//----- (006C3A50) --------------------------------------------------------  // acclient.c:732061
int _E1_2()
{
  return atexit(_E2_2);
}

//----- (006C3A60) --------------------------------------------------------  // acclient.c:732067
int _E4_0()
{
  return atexit(_E5_0);
}

//----- (006C3A70) --------------------------------------------------------  // acclient.c:732073
int _E7_0()
{
  Outside_CellID_0.id = Invalid_CellID_0.id + 1;
  return atexit(_E8_0);
}

//----- (006C3A90) --------------------------------------------------------  // acclient.c:732080
int _E10_0()
{
  In_Limbo_CellID_0.id = Outside_CellID_0.id + 1;
  return atexit(_E11_0);
}

//----- (006C3AB0) --------------------------------------------------------  // acclient.c:732087
int _E13_0()
{
  First_Interior_CellID_0.id = In_Limbo_CellID_0.id + 1;
  return atexit(_E14_0);
}

//----- (006C3AD0) --------------------------------------------------------  // acclient.c:732094
int _E16_0()
{
  Last_Interior_CellID_0.id = Invalid_CellID_0.id - 1;
  return atexit(_E17_0);
}

//----- (006C3AF0) --------------------------------------------------------  // acclient.c:732101
int _E21_1()
{
  return atexit(_E22_1);
}

//----- (006C3B00) --------------------------------------------------------  // acclient.c:732107
int _E40_0()
{
  return atexit(_E41_0);
}

//----- (006C3B10) --------------------------------------------------------  // acclient.c:732113
int _E43_0()
{
  return atexit(_E44_0);
}

