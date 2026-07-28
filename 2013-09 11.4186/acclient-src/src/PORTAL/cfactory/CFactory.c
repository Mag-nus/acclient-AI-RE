/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CFactory
   Object     : PORTAL\cfactory\CFactory.obj
   Functions  : 25
   Addresses  : 0054AE80 - 00705880 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0054AE80) --------------------------------------------------------  // acclient.c:378594
void __cdecl CFactory::CleanUp()
{
  if ( CFactory::global_cfactory )
    ((void (__stdcall *)(_DWORD))CFactory::global_cfactory->vfptr->__vecDelDtor)(1);
  CFactory::global_cfactory = 0;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AEA0) --------------------------------------------------------  // acclient.c:378603
void CFactory::MakeCommandInterpreter_Internal()
{
  CommandInterpreter *v1; // eax@1

  v1 = (CommandInterpreter *)operator new(0xC8u);
  if ( v1 )
    CommandInterpreter::CommandInterpreter(v1);
}

//----- (0054AEC0) --------------------------------------------------------  // acclient.c:378613
int __cdecl CFactory::MakeCommandInterpreter()
{
  int result; // eax@2

  if ( CFactory::global_cfactory )
    result = ((int (*)(void))CFactory::global_cfactory->vfptr->MakeCommandInterpreter_Internal)();
  else
    result = 0;
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AEE0) --------------------------------------------------------  // acclient.c:378626
int __cdecl CFactory::Make_Client_Cache()
{
  int result; // eax@1

  result = 0;
  if ( CFactory::global_cfactory )
    result = ((int (*)(void))CFactory::global_cfactory->vfptr->Make_Client_Cache_Internal)();
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AF00) --------------------------------------------------------  // acclient.c:378638
void CFactory::Make_Client_Cache_Internal()
{
  CLCache *v1; // eax@1

  v1 = (CLCache *)operator new(0x308u);
  if ( v1 )
    CLCache::CLCache(v1);
}

//----- (0054AF20) --------------------------------------------------------  // acclient.c:378648
int __cdecl CFactory::MakeCWeenieObject(unsigned int iid)
{
  int result; // eax@1

  result = 0;
  if ( CFactory::global_cfactory )
    result = ((int (__stdcall *)(_DWORD))CFactory::global_cfactory->vfptr->MakeCWeenieObject_Internal)(iid);
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AF40) --------------------------------------------------------  // acclient.c:378660
int __cdecl CFactory::MakeGlobalEventHandler()
{
  int result; // eax@2

  if ( CFactory::global_cfactory )
    result = ((int (*)(void))CFactory::global_cfactory->vfptr->MakeGlobalEventHandler_Internal)();
  else
    result = 0;
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AF60) --------------------------------------------------------  // acclient.c:378673
int __cdecl CFactory::MakeQualityRegistrar()
{
  int result; // eax@2

  if ( CFactory::global_cfactory )
    result = ((int (*)(void))CFactory::global_cfactory->vfptr->MakeQualityRegistrar_Internal)();
  else
    result = 0;
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AF80) --------------------------------------------------------  // acclient.c:378686
void CFactory::MakeQualityRegistrar_Internal()
{
  QualityRegistrar *v1; // eax@1

  v1 = (QualityRegistrar *)operator new(0x16Cu);
  if ( v1 )
    QualityRegistrar::QualityRegistrar(v1);
}

//----- (0054AFA0) --------------------------------------------------------  // acclient.c:378696
int __cdecl CFactory::MakeCCommunicationSystem()
{
  int result; // eax@2

  if ( CFactory::global_cfactory )
    result = ((int (*)(void))CFactory::global_cfactory->vfptr->MakeCCommunicationSystem_Internal)();
  else
    result = 0;
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054AFC0) --------------------------------------------------------  // acclient.c:378709
void CFactory::MakeCCommunicationSystem_Internal()
{
  CCommunicationSystem *v1; // eax@1

  v1 = (CCommunicationSystem *)operator new(0x14u);
  if ( v1 )
    CCommunicationSystem::CCommunicationSystem(v1);
}

//----- (0054AFE0) --------------------------------------------------------  // acclient.c:378719
int __cdecl CFactory::MakeSmartBox(NIList<NetBlob *> *q)
{
  int result; // eax@2

  if ( CFactory::global_cfactory )
    result = ((int (__stdcall *)(_DWORD))CFactory::global_cfactory->vfptr->MakeSmartBox_Internal)(q);
  else
    result = 0;
  return result;
}
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (0054B000) --------------------------------------------------------  // acclient.c:378732
void __stdcall CFactory::MakeSmartBox_Internal(NIList<NetBlob *> *q)
{
  SmartBox *v2; // eax@1

  v2 = (SmartBox *)operator new(0x118u);
  if ( v2 )
    SmartBox::SmartBox(v2, q);
}

//----- (00705770) --------------------------------------------------------  // acclient.c:792812
int _E89_7()
{
  return atexit(_E90_3);
}

//----- (00705780) --------------------------------------------------------  // acclient.c:792818
int _E92_3()
{
  return atexit(nullsub_1221);
}

//----- (00705790) --------------------------------------------------------  // acclient.c:792824
int sub_705790()
{
  return atexit(_E96_7);
}

//----- (007057A0) --------------------------------------------------------  // acclient.c:792830
void _E98_10()
{
  LODWORD(dword_845FE4) = 1053364187;
}

//----- (007057B0) --------------------------------------------------------  // acclient.c:792836
void sub_7057B0()
{
  flt_845FE8 = 1000.0 + 1.0;
}

//----- (007057D0) --------------------------------------------------------  // acclient.c:792842
void _E102_27()
{
  flt_845FEC = 24.0 * 8.0;
}

//----- (007057F0) --------------------------------------------------------  // acclient.c:792848
void _E104_13()
{
  flt_845FF0 = 24.0 * 0.5;
}

//----- (00705810) --------------------------------------------------------  // acclient.c:792854
void sub_705810()
{
  flt_845FF4 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00705830) --------------------------------------------------------  // acclient.c:792860
void _E108_82()
{
  dbl_845FF8 = 1.0 / 30.0;
}

//----- (00705850) --------------------------------------------------------  // acclient.c:792866
void _E110_64()
{
  dbl_846000 = 1.0 / 5.0;
}

//----- (00705870) --------------------------------------------------------  // acclient.c:792872
void _E112_93()
{
  PixelFormatDesc::PixelFormatDesc(&stru_846008, PFID_A8R8G8B8);
}

//----- (00705880) --------------------------------------------------------  // acclient.c:792878
int sub_705880()
{
  return atexit(nullsub_1219);
}

