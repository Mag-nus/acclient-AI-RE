/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCFactory
   Object     : AC\accfactory\ACCFactory.obj
   Functions  : 28
   Addresses  : 00557300 - 00707C00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00557300) --------------------------------------------------------  // acclient.c:390617
ACCFactory *__thiscall CFactory::vector_deleting_destructor(ACCFactory *this, unsigned int a2)
{
  ACCFactory *v2; // esi@1

  v2 = this;
  this->vfptr = (CFactoryVtbl *)&CFactory::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7CA8C4: using guessed type int (__thiscall *CFactory::vftable)(void *, char);

//----- (00557320) --------------------------------------------------------  // acclient.c:390630
void ACCFactory::MakeCommandInterpreter_Internal()
{
  ACCmdInterp *v1; // eax@1

  v1 = (ACCmdInterp *)operator new(0x140u);
  if ( v1 )
    ACCmdInterp::ACCmdInterp(v1);
}

//----- (00557340) --------------------------------------------------------  // acclient.c:390640
void ACCFactory::Make_Client_Cache_Internal()
{
  gmCLCache *v1; // eax@1

  v1 = (gmCLCache *)operator new(0x308u);
  if ( v1 )
    gmCLCache::gmCLCache(v1);
}

//----- (00557360) --------------------------------------------------------  // acclient.c:390650
void __stdcall ACCFactory::MakeCWeenieObject_Internal(unsigned int iid)
{
  ACCWeenieObject *v2; // eax@1

  v2 = (ACCWeenieObject *)operator new(0x150u);
  if ( v2 )
    ACCWeenieObject::ACCWeenieObject(v2, iid);
}

//----- (00557380) --------------------------------------------------------  // acclient.c:390660
void ACCFactory::MakeGlobalEventHandler_Internal()
{
  gmGlobalEventHandler *v1; // eax@1

  v1 = (gmGlobalEventHandler *)operator new(8u);
  if ( v1 )
    gmGlobalEventHandler::gmGlobalEventHandler(v1);
}

//----- (005573A0) --------------------------------------------------------  // acclient.c:390670
void ACCFactory::MakeCCommunicationSystem_Internal()
{
  gmCCommunicationSystem *v1; // eax@1

  v1 = (gmCCommunicationSystem *)operator new(0x88u);
  if ( v1 )
    gmCCommunicationSystem::gmCCommunicationSystem(v1);
}

//----- (005573C0) --------------------------------------------------------  // acclient.c:390680
void __stdcall ACCFactory::MakeSmartBox_Internal(NIList<NetBlob *> *q)
{
  ACSmartBox *v2; // eax@1

  v2 = (ACSmartBox *)operator new(0x118u);
  if ( v2 )
    ACSmartBox::ACSmartBox(v2, q);
}

//----- (005573E0) --------------------------------------------------------  // acclient.c:390690
TResult *__thiscall ClassFactoryPlugin<ClientObjMaintSystem>::QueryInterface(ClassFactoryPlugin<ClientObjMaintSystem> *this, TResult *result, Turbine_GUID *_rInterfaceType, void **_ppOutInterface)
{
  ClassFactoryPlugin<ClientObjMaintSystem> *v4; // esi@1
  TResult *v5; // eax@10

  v4 = this;
  if ( (_rInterfaceType->m_data1 == 1244181156
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&stru_7CB8B8.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&stru_7CB8B8.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&stru_7CB8B8.m_data4[4]
     || _rInterfaceType->m_data1 == -559038737
     && *(_DWORD *)&_rInterfaceType->m_data2 == *(_DWORD *)&stru_7CBA98.m_data2
     && *(_DWORD *)&_rInterfaceType->m_data4[0] == *(_DWORD *)&stru_7CBA98.m_data4[0]
     && *(_DWORD *)&_rInterfaceType->m_data4[4] == *(_DWORD *)&stru_7CBA98.m_data4[4])
    && this )
  {
    this->vfptr->AddRef((Interface *)this);
    *_ppOutInterface = v4;
    v5 = result;
    result->m_val = 0;
  }
  else
  {
    v5 = result;
    result->m_val = -2147467262;
  }
  return v5;
}

//----- (00557470) --------------------------------------------------------  // acclient.c:390720
unsigned int __thiscall ClassFactoryPlugin<ClientObjMaintSystem>::Release(ClassFactoryPlugin<ClientObjMaintSystem> *this)
{
  ClassFactoryPlugin<ClientObjMaintSystem> *v1; // esi@1
  char *v2; // ebx@1
  unsigned int v3; // edi@1

  v1 = this;
  v2 = (char *)&this->m_cTurbineRefCount;
  v3 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v3 && v1 )
  {
    *(_DWORD *)v2 = &ReferenceCountTemplate<1048576,2>::vftable;
    operator delete(v1);
  }
  return v3;
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);

//----- (005574A0) --------------------------------------------------------  // acclient.c:390739
TResult *__stdcall ClassFactoryPlugin<ClientObjMaintSystem>::CreateInstance(TResult *result, Interface *_pOuterInterface, Turbine_GUID *_rInterfaceType, void **_ppvObject)
{
  TResult *v5; // eax@2
  int v6; // eax@3
  Interface *v7; // ecx@3
  void **v8; // ST08_4@4
  Interface *v9; // ecx@4
  bool v10; // zf@4
  TResult *v11; // esi@4
  int v12; // [sp+8h] [bp-Ch]@3
  InterfacePtr<Interface> spInterface; // [sp+Ch] [bp-8h]@3

  if ( _pOuterInterface )
  {
    v5 = result;
    result->m_val = -2147221232;
    return v5;
  }
  ClientObjMaintSystem::Allocate();
  spInterface.m_pInterface = 0;
  spInterface.m_trStatus.m_val = 0;
  spInterface.m_trStatus.m_val = *(_DWORD *)InterfacePtr<Interface>::_QueryInterface(&spInterface, (int)&v12, v6);
  v7 = spInterface.m_pInterface;
  if ( _ppvObject )
  {
    v8 = _ppvObject;
    *_ppvObject = 0;
    ((void (__stdcall *)(Interface **, Turbine_GUID *, void **))v7->vfptr->QueryInterface)(
      &_pOuterInterface,
      _rInterfaceType,
      v8);
    ((void (*)(void))spInterface.m_pInterface->vfptr->Release)();
    v9 = spInterface.m_pInterface;
    v10 = (_DWORD)spInterface.m_pInterface == 0;
    v11 = result;
    result->m_val = (unsigned int)_pOuterInterface;
    if ( !v10 )
    {
      ((void (*)(void))v9->vfptr->Release)();
      return result;
    }
  }
  else
  {
    v11 = result;
    result->m_val = -2147467261;
    if ( v7 )
      ((void (*)(void))v7->vfptr->Release)();
  }
  return v11;
}

//----- (00557550) --------------------------------------------------------  // acclient.c:390792
int __thiscall InterfacePtr<Interface>::_QueryInterface(InterfacePtr<Interface> *this, int a2, int a3)
{
  InterfacePtr<Interface> *v3; // esi@1
  int v4; // eax@2
  int v5; // edi@2
  Interface *v6; // ecx@2
  int result; // eax@5
  int v8; // ebx@6
  InterfacePtr<Interface> *v9; // [sp+4h] [bp-4h]@1

  v9 = this;
  v3 = this;
  if ( a3 )
  {
    v4 = *(_DWORD *)a3;
    a3 = 0;
    v5 = *(_DWORD *)(*(int (__stdcall **)(int *, Turbine_GUID *, int *))(v4 + 12))(&v9, &stru_7CBA98, &a3);
    v6 = v3->m_pInterface;
    if ( v5 >= 0 )
    {
      v8 = a3;
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = (Interface *)v8;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
    else
    {
      if ( v6 )
        ((void (*)(void))v6->vfptr->Release)();
      result = a2;
      v3->m_pInterface = 0;
      v3->m_trStatus.m_val = 0;
      *(_DWORD *)a2 = v5;
    }
  }
  else
  {
    InterfacePtr<Interface>::operator=(this, 0);
    result = a2;
    *(_DWORD *)a2 = -2147467262;
  }
  return result;
}

//----- (005575F0) --------------------------------------------------------  // acclient.c:390840
void __thiscall ACCFactory::Init(unsigned int this)
{
  void *v1; // eax@1
  void *v2; // esi@1
  Interface *v3; // ST08_4@2
  InterfaceSystem *v4; // eax@2
  struct CFactory *v5; // eax@3
  TResult result; // [sp+0h] [bp-4h]@1

  result.m_val = this;
  v1 = operator new(0xCu);
  v2 = v1;
  if ( v1 )
  {
    v3 = (Interface *)v1;
    *(_DWORD *)v1 = &ClassFactoryPlugin<ClientObjMaintSystem>::vftable;
    *((_DWORD *)v1 + 2) = 1;
    *((_DWORD *)v1 + 1) = &ReferenceCountTemplate<1048576,2>::vftable;
    v4 = InterfaceSystem::GetInstance();
    InterfaceSystem::RegisterClassA(v4, &result, &CObjectMaint_Factory_ClassType_1, v3, 0);
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 20))(v2);
  }
  v5 = (struct CFactory *)operator new(4u);
  if ( v5 )
  {
    v5->vfptr = (CFactoryVtbl *)&ACCFactory::vftable;
    CFactory::global_cfactory = v5;
  }
  else
  {
    CFactory::global_cfactory = 0;
  }
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7CBAB4: using guessed type int (__thiscall *ACCFactory::vftable)(void *, char);
// 7CBAD4: using guessed type __int32 (__stdcall *ClassFactoryPlugin<ClientObjMaintSystem>::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 845FC4: using guessed type struct CFactory *CFactory::global_cfactory;

//----- (00707AB0) --------------------------------------------------------  // acclient.c:794872
int _E89_8()
{
  return atexit(_E90_4);
}

//----- (00707AC0) --------------------------------------------------------  // acclient.c:794878
int _E92_4()
{
  return atexit(nullsub_1292);
}

//----- (00707AD0) --------------------------------------------------------  // acclient.c:794884
int sub_707AD0()
{
  return atexit(_E96_8);
}

//----- (00707AE0) --------------------------------------------------------  // acclient.c:794890
void _E98_13()
{
  LODWORD(dword_86FE98) = 1053364187;
}

//----- (00707AF0) --------------------------------------------------------  // acclient.c:794896
void sub_707AF0()
{
  flt_86FE9C = 1000.0 + 1.0;
}

//----- (00707B10) --------------------------------------------------------  // acclient.c:794902
void _E102_30()
{
  flt_86FEA0 = 24.0 * 8.0;
}

//----- (00707B30) --------------------------------------------------------  // acclient.c:794908
void _E104_14()
{
  flt_86FEA4 = 24.0 * 0.5;
}

//----- (00707B50) --------------------------------------------------------  // acclient.c:794914
void sub_707B50()
{
  flt_86FEA8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00707B70) --------------------------------------------------------  // acclient.c:794920
void _E108_83()
{
  dbl_86FEB0 = 1.0 / 30.0;
}

//----- (00707B90) --------------------------------------------------------  // acclient.c:794926
void _E110_65()
{
  dbl_86FEB8 = 1.0 / 5.0;
}

//----- (00707BB0) --------------------------------------------------------  // acclient.c:794932
void _E112_96()
{
  PixelFormatDesc::PixelFormatDesc(&stru_86FEC0, PFID_A8R8G8B8);
}

//----- (00707BC0) --------------------------------------------------------  // acclient.c:794938
void _E118_71()
{
  dword_86FEF8 = 1024;
}

//----- (00707BD0) --------------------------------------------------------  // acclient.c:794944
void _E120_64()
{
  dword_86FEFC = 0x7FFF;
}

//----- (00707BE0) --------------------------------------------------------  // acclient.c:794950
int _E122_27()
{
  const int result; // eax@1

  result = dword_86FEF8;
  dword_86FF00 = dword_86FEF8;
  return result;
}

//----- (00707BF0) --------------------------------------------------------  // acclient.c:794960
int _E124_62()
{
  return atexit(_E125_60);
}

//----- (00707C00) --------------------------------------------------------  // acclient.c:794966
int sub_707C00()
{
  return atexit(nullsub_1290);
}

