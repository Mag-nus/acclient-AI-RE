/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UserPreferences
   Object     : ENGINE\globalregistry\UserPreferences.obj
   Functions  : 106
   Addresses  : 00436DC0 - 00729330 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00436DC0) --------------------------------------------------------  // acclient.c:116111
bool __cdecl UserPreferences::IsPreferenceRegistered(PStringBase<char> *_Name, GRVDataType _ExpectedDataType)
{
  GRPObject *v2; // ecx@0
  GlobalRegistryInstance *v3; // eax@1
  GlobalRegistryInstance *v4; // eax@2
  int v5; // eax@7
  int v6; // esi@7
  bool result; // al@11
  GRPObject *pFoundObject; // [sp+0h] [bp-4h]@1

  pFoundObject = v2;
  v3 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v4 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v4 )
      GlobalRegistryInstance::GlobalRegistryInstance(v4);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  result = 0;
  if ( GlobalRegistryInstance::FindObjectByName(v3, _Name, &pFoundObject) )
  {
    v5 = ((int (*)(void))pFoundObject->vfptr->AsTypedVariableObject)();
    v6 = v5;
    if ( v5 )
    {
      if ( (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 72))(v5)
        && (_ExpectedDataType == GRVDataType_Unknown || *(_DWORD *)(v6 + 16) == _ExpectedDataType) )
        result = 1;
    }
  }
  return result;
}

//----- (00436E40) --------------------------------------------------------  // acclient.c:116148
char __cdecl UserPreferences::FindPreference(PStringBase<char> *_Name, GRPVariableObject **_pFoundVariable)
{
  GRPVariableObject **v2; // edi@1
  GlobalRegistryInstance *v3; // eax@1
  GlobalRegistryInstance *v4; // eax@2
  int v5; // eax@7
  int v6; // esi@7
  char result; // al@9

  v2 = _pFoundVariable;
  *_pFoundVariable = 0;
  v3 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v4 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v4 )
      GlobalRegistryInstance::GlobalRegistryInstance(v4);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v3, _Name, (GRPObject **)&_pFoundVariable)
    && (v5 = ((int (*)(void))(*_pFoundVariable)[4].m_Name.m_charbuffer)(), (v6 = v5) != 0)
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 72))(v5) )
  {
    *v2 = (GRPVariableObject *)v6;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00436EC0) --------------------------------------------------------  // acclient.c:116184
bool __cdecl UserPreferences::InqValue(PStringBase<char> *i_str, bool *o_bValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  bool result; // al@10
  int v6; // eax@12
  int v7; // ecx@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 2 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6;
      result = v6 != 0;
      if ( result )
      {
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 16) == 2 )
            *o_bValue = **(_BYTE **)(v7 + 12);
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00436F80) --------------------------------------------------------  // acclient.c:116235
bool __cdecl UserPreferences::InqValue(PStringBase<char> *i_str, int *o_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  bool result; // al@10
  int v6; // eax@12
  int v7; // ecx@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 3 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6;
      result = v6 != 0;
      if ( result )
      {
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 16) == 3 )
            *o_nValue = **(_DWORD **)(v7 + 12);
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437040) --------------------------------------------------------  // acclient.c:116286
bool __cdecl UserPreferences::InqValue(PStringBase<char> *i_str, unsigned int *o_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  bool result; // al@10
  int v6; // eax@12
  int v7; // ecx@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 4 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6;
      result = v6 != 0;
      if ( result )
      {
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 16) == 4 )
            *o_nValue = **(_DWORD **)(v7 + 12);
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437100) --------------------------------------------------------  // acclient.c:116337
bool __cdecl UserPreferences::InqValue(PStringBase<char> *i_str, float *o_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  bool result; // al@10
  int v6; // eax@12
  int v7; // ecx@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 9 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6;
      result = v6 != 0;
      if ( result )
      {
        if ( v7 )
        {
          if ( *(_DWORD *)(v7 + 16) == 9 )
            *(_DWORD *)o_nValue = **(_DWORD **)(v7 + 12);
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437210) --------------------------------------------------------  // acclient.c:116407
char __usercall UserPreferences::SetDefaultFile@<al>(unsigned int a1@<esi>, PStringBase<char> *i_str)
{
  char *v2; // esi@3
  char *v3; // esi@8
  char *v4; // esi@12
  PStringBase<char> strFile; // [sp+10h] [bp-4h]@1

  strFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !PSUtils::GetLongPathNameA(a1, i_str, &strFile) && strFile.m_charbuffer != i_str->m_charbuffer )
  {
    v2 = &strFile.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strFile.m_charbuffer[-1]) && v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    strFile.m_charbuffer = i_str->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strFile.m_charbuffer[-1]);
  }
  PSUtils::cleanup_filename(&strFile, 0);
  if ( UserPreferences::sm_strDefaultFile.m_charbuffer != strFile.m_charbuffer )
  {
    v3 = &UserPreferences::sm_strDefaultFile.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    UserPreferences::sm_strDefaultFile.m_charbuffer = strFile.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strFile.m_charbuffer[-1]);
  }
  v4 = &strFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strFile.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  return 1;
}

//----- (004372E0) --------------------------------------------------------  // acclient.c:116440
void __thiscall GRPTypedVariableObject::SetVariable(GRPTypedVariableObject *this, const __int32 *a2)
{
  GRPTypedVariableObject *v2; // esi@1
  const __int32 *v3; // esi@3

  v2 = this;
  if ( this->m_Type == 3 )
  {
    *(_DWORD *)this->m_pVariable = *a2;
    if ( this->m_OnChangedCallbackFunction )
    {
      a2 = (const __int32 *)this->m_Name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)a2 - 4);
      v2->m_OnChangedCallbackFunction((PStringBase<char> *)&a2);
      v3 = a2 - 5;
      if ( !InterlockedDecrement((volatile LONG *)a2 - 4) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
    }
  }
}

//----- (00437340) --------------------------------------------------------  // acclient.c:116465
void __thiscall GRPTypedVariableObject::SetVariable(GRPTypedVariableObject *this, const unsigned __int32 *a2)
{
  GRPTypedVariableObject *v2; // esi@1
  const unsigned __int32 *v3; // esi@3

  v2 = this;
  if ( this->m_Type == 4 )
  {
    *(_DWORD *)this->m_pVariable = *a2;
    if ( this->m_OnChangedCallbackFunction )
    {
      a2 = (const unsigned __int32 *)this->m_Name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)a2 - 4);
      v2->m_OnChangedCallbackFunction((PStringBase<char> *)&a2);
      v3 = a2 - 5;
      if ( !InterlockedDecrement((volatile LONG *)a2 - 4) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
    }
  }
}

//----- (004373A0) --------------------------------------------------------  // acclient.c:116490
void __thiscall GRPTypedVariableObject::SetVariable(GRPTypedVariableObject *this, const float *a2)
{
  GRPTypedVariableObject *v2; // esi@1
  const float *v3; // esi@3

  v2 = this;
  if ( this->m_Type == 9 )
  {
    *(_DWORD *)this->m_pVariable = *(_DWORD *)a2;
    if ( this->m_OnChangedCallbackFunction )
    {
      a2 = (const float *)this->m_Name.m_charbuffer;
      InterlockedIncrement((volatile LONG *)a2 - 4);
      v2->m_OnChangedCallbackFunction((PStringBase<char> *)&a2);
      v3 = a2 - 5;
      if ( !InterlockedDecrement((volatile LONG *)a2 - 4) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
    }
  }
}

//----- (00437400) --------------------------------------------------------  // acclient.c:116515
void __thiscall GRPTypedVariableObject::SetVariable(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebp@2
  int v4; // edi@2
  int v5; // eax@2
  int v6; // ebx@3
  int v7; // eax@6
  int v8; // esi@8

  v2 = this;
  if ( *(_DWORD *)(this + 16) == 13 )
  {
    v3 = a2;
    v4 = *(_DWORD *)(this + 12);
    v5 = *(_DWORD *)v4;
    if ( *(_DWORD *)v4 != *(_DWORD *)a2 )
    {
      v6 = v5 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v5 - 20 + 4)) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = *(_DWORD *)v3;
      *(_DWORD *)v4 = *(_DWORD *)v3;
      InterlockedIncrement((volatile LONG *)(v7 - 16));
    }
    if ( *(_DWORD *)(v2 + 20) )
    {
      a2 = *(_DWORD *)(v2 + 4);
      InterlockedIncrement((volatile LONG *)(a2 - 16));
      (*(void (__cdecl **)(int *))(v2 + 20))(&a2);
      v8 = a2 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(a2 - 20 + 4)) )
      {
        if ( v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      }
    }
  }
}

//----- (004374A0) --------------------------------------------------------  // acclient.c:116556
void __thiscall GRPTypedVariableObject::InqVariable(int this, int a2)
{
  int v2; // eax@2
  int v3; // esi@2
  int v4; // edi@3
  int v5; // eax@6

  if ( *(_DWORD *)(this + 16) == 13 )
  {
    v2 = *(_DWORD *)a2;
    v3 = *(_DWORD *)(this + 12);
    if ( *(_DWORD *)a2 != *(_DWORD *)v3 )
    {
      v4 = v2 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v2 - 20 + 4)) )
      {
        if ( v4 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      }
      v5 = *(_DWORD *)v3;
      *(_DWORD *)a2 = *(_DWORD *)v3;
      InterlockedIncrement((volatile LONG *)(v5 - 16));
    }
  }
}

//----- (004374F0) --------------------------------------------------------  // acclient.c:116583
void *__thiscall _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(_STL::pair<PStringBase<char>,PStringBase<char> > *this, unsigned int a2)
{
  _STL::pair<PStringBase<char>,PStringBase<char> > *v2; // esi@1
  PSRefBufferCharData<char> *v3; // eax@2
  char *v4; // ebx@2
  _STL::pair<PStringBase<char>,PStringBase<char> > *v5; // edi@2
  int v6; // eax@2
  PSRefBufferCharData<char> *v7; // esi@4
  int v8; // esi@4
  int v9; // esi@7
  void *result; // eax@13
  int v11; // [sp+8h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].second.m_charbuffer;
    v4 = (char *)&this[-1].second;
    v5 = &this[(_DWORD)v3];
    v6 = (int)&v3[-1].m_data[15];
    if ( v6 >= 0 )
    {
      v11 = v6 + 1;
      do
      {
        v7 = v5[-1].second.m_charbuffer;
        --v5;
        v8 = (int)&v7[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
        v9 = (int)&v5->first.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        --v11;
      }
      while ( v11 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    _STL::pair<PStringBase<char>,PStringBase<char>>::~pair<PStringBase<char>,PStringBase<char>>((DiskConInitInfo *)this);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (00437590) --------------------------------------------------------  // acclient.c:116635
void *__thiscall _STL::pair<PStringBase<char>,PStringBase<char>>::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // edi@2
  int v5; // eax@5
  int v6; // eax@6
  int v7; // edi@7
  int v8; // eax@10

  v2 = this;
  v3 = *(_DWORD *)this;
  if ( *(_DWORD *)this != *(_DWORD *)a2 )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)a2;
    *(_DWORD *)v2 = *(_DWORD *)a2;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  v6 = *((_DWORD *)v2 + 1);
  if ( v6 != *(_DWORD *)(a2 + 4) )
  {
    v7 = v6 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v6 - 20 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 4);
    *((_DWORD *)v2 + 1) = v8;
    InterlockedIncrement((volatile LONG *)(v8 - 16));
  }
  return v2;
}

//----- (00437610) --------------------------------------------------------  // acclient.c:116670
void __thiscall _STL::pair<PStringBase<char>,PStringBase<char>>::pair<PStringBase<char>,PStringBase<char>>(_STL::pair<PStringBase<char>,PStringBase<char> > *this)
{
  _STL::pair<PStringBase<char>,PStringBase<char> > *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->first.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->second.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
}

//----- (00437640) --------------------------------------------------------  // acclient.c:116686
void __thiscall SmartArray<_STL::pair<PStringBase<char>,PStringBase<char>>,1>::Reset(SmartArray<_STL::pair<PStringBase<char>,PStringBase<char> >,1> *this)
{
  SmartArray<_STL::pair<PStringBase<char>,PStringBase<char> >,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // esi@7
  int v5; // esi@10
  int iElement; // [sp+8h] [bp-Ch]@6
  PSRefBufferCharData<char> *v7; // [sp+Ch] [bp-8h]@7
  PSRefBufferCharData<char> *v8; // [sp+10h] [bp-4h]@7

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( iElement = (v2 & 0x7FFFFFFF) - 1; iElement >= 0; --iElement )
    {
      v7 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v8 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      _STL::pair<PStringBase<char>,PStringBase<char>>::operator=(&v1->m_data[iElement], (int)&v7);
      v4 = (int)&v8[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      v5 = (int)&v7[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
  }
}

//----- (00437720) --------------------------------------------------------  // acclient.c:116728
char __cdecl UserPreferences::SetValue(PStringBase<char> *i_str, const bool i_bValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  GRPTypedVariableObject *v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 2 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = (GRPTypedVariableObject *)((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::SetVariable(v6, &i_bValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004377E0) --------------------------------------------------------  // acclient.c:116773
char __cdecl UserPreferences::SetValue(PStringBase<char> *i_str, const int i_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  GRPTypedVariableObject *v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 3 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = (GRPTypedVariableObject *)((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::SetVariable(v6, (const __int32 *)&i_nValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004378A0) --------------------------------------------------------  // acclient.c:116818
char __cdecl UserPreferences::SetValue(PStringBase<char> *i_str, const unsigned int i_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  GRPTypedVariableObject *v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 4 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = (GRPTypedVariableObject *)((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::SetVariable(v6, (const unsigned __int32 *)&i_nValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437960) --------------------------------------------------------  // acclient.c:116863
char __cdecl UserPreferences::SetValue(PStringBase<char> *i_str, const float i_nValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  GRPTypedVariableObject *v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 9 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = (GRPTypedVariableObject *)((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::SetVariable(v6, &i_nValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437A20) --------------------------------------------------------  // acclient.c:116908
char __cdecl UserPreferences::SetValue(PStringBase<char> *i_str, PStringBase<char> *i_strValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  int v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 13 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::SetVariable(v6, (int)i_strValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437AE0) --------------------------------------------------------  // acclient.c:116953
char __cdecl UserPreferences::InqValue(PStringBase<char> *i_str, PStringBase<char> *o_strValue)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  int v6; // eax@12
  bool v7; // bl@12
  GRPVariableObject *_pFoundVariable; // [sp+0h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+4h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 13 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6 != 0;
      if ( v6 )
        GRPTypedVariableObject::InqVariable(v6, (int)o_strValue);
      result = v7;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00437BA0) --------------------------------------------------------  // acclient.c:116998
char __thiscall SmartArray<_STL::pair<PStringBase<char>,PStringBase<char>>,1>::grow(SmartArray<_STL::pair<PStringBase<char>,PStringBase<char> >,1> *this, unsigned int i_nSize)
{
  SmartArray<_STL::pair<PStringBase<char>,PStringBase<char> >,1> *v2; // esi@1
  void *v4; // eax@5
  int v5; // ebp@6
  int i; // edi@8

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<_STL::pair<PStringBase<char>,PStringBase<char>>,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize + 4);
    if ( v4 )
    {
      v5 = (int)((char *)v4 + 4);
      *(_DWORD *)v4 = i_nSize;
      vector_constructor_iterator(
        (char *)v4 + 4,
        8u,
        i_nSize,
        (void *(__thiscall *)(void *))_STL::pair<PStringBase<char>,PStringBase<char>>::pair<PStringBase<char>,PStringBase<char>>);
      if ( v5 )
      {
        if ( v2->m_data )
        {
          for ( i = v2->m_num - 1; i >= 0; --i )
            _STL::pair<PStringBase<char>,PStringBase<char>>::operator=((void *)(8 * i + v5), (int)&v2->m_data[i]);
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(v2->m_data, 3u);
          }
        }
        v2->m_data = (_STL::pair<PStringBase<char>,PStringBase<char> > *)v5;
        v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00437C60) --------------------------------------------------------  // acclient.c:117047
void __thiscall UserPreferences::Cleanup(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@1
  char *v2; // esi@4
  PStringBase<char> _Name; // [sp+4h] [bp-4h]@1

  _Name.m_charbuffer = this;
  PStringBase<char>::PStringBase<char>(&_Name, "LoadPreferences");
  GlobalRegistry::UnregisterCommand(&_Name);
  v1 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "SavePreferences");
  GlobalRegistry::UnregisterCommand(&_Name);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) )
  {
    if ( v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  }
}

//----- (00437CE0) --------------------------------------------------------  // acclient.c:117070
char __cdecl UserPreferences::FindDefaultFile(PStringBase<char> *o_strFile)
{
  PSRefBufferCharData<char> *v1; // eax@2
  int v2; // esi@3
  volatile LONG *v3; // ST20_4@6
  char v4; // bl@7
  char *v5; // esi@10
  LONG v6; // eax@10
  char v7; // al@13
  LONG (__stdcall *v8)(volatile LONG *); // edi@13
  char *v9; // esi@13
  PSRefBufferCharData<char> *v10; // eax@14
  int v11; // esi@15
  PSRefBufferCharData<char> *v12; // eax@18
  char v13; // al@19
  char *v14; // esi@19
  LONG v15; // eax@13
  char *v16; // esi@26
  PStringBase<char> strDefaultPath; // [sp+10h] [bp-14h]@1
  PStringBase<char> strDefaultFile; // [sp+14h] [bp-10h]@1
  PStringBase<char> strDirectory; // [sp+18h] [bp-Ch]@14
  PStringBase<char> result; // [sp+1Ch] [bp-8h]@13
  PStringBase<char> strExecutable; // [sp+20h] [bp-4h]@14

  PStringBase<char>::PStringBase<char>(&strDefaultFile, "UserPreferences.ini");
  strDefaultPath.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( *(_DWORD *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1].m_data[12] == 1 )
  {
    if ( UserPreferences::sm_bTools && ProjectSettings::sm_bInitialized )
    {
      ProjectSettings::CompleteProjectPath(&result, &DATA_PATH_1);
      PStringBase<char>::sprintf(&strDefaultPath, "%s\\%s", result.m_charbuffer, strDefaultFile.m_charbuffer);
      PSUtils::cleanup_filename(&strDefaultPath, 0);
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)o_strFile,
        (const unsigned __int16 *)&strDefaultPath);
      v7 = PSUtils::check_access(&strDefaultPath, 0);
      v8 = InterlockedDecrement;
      v9 = &result.m_charbuffer[-2].m_data[12];
      v4 = v7;
      v15 = InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]);
    }
    else
    {
      strDirectory.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      PSUtils::get_process_name(&strExecutable);
      PSUtils::get_directory(&strDirectory, &strExecutable);
      PStringBase<char>::sprintf(&strDefaultPath, "%s%s", strDirectory.m_charbuffer, strDefaultFile.m_charbuffer);
      PSUtils::cleanup_filename(&strDefaultPath, 0);
      v10 = o_strFile->m_charbuffer;
      v8 = InterlockedDecrement;
      if ( o_strFile->m_charbuffer != strDefaultPath.m_charbuffer )
      {
        v11 = (int)&v10[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
        v12 = strDefaultPath.m_charbuffer;
        o_strFile->m_charbuffer = strDefaultPath.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v12[-1]);
      }
      v13 = PSUtils::check_access(&strDefaultPath, 0);
      v14 = &strExecutable.m_charbuffer[-2].m_data[12];
      v4 = v13;
      if ( !InterlockedDecrement((volatile LONG *)&strExecutable.m_charbuffer[-1]) && v14 )
        (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
      v9 = &strDirectory.m_charbuffer[-2].m_data[12];
      v15 = InterlockedDecrement((volatile LONG *)&strDirectory.m_charbuffer[-1]);
    }
    if ( !v15 && v9 )
      (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
    v16 = &strDefaultPath.m_charbuffer[-2].m_data[12];
    if ( !v8((volatile LONG *)&strDefaultPath.m_charbuffer[-1]) && v16 )
      (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
    v5 = &strDefaultFile.m_charbuffer[-2].m_data[12];
    v6 = v8((volatile LONG *)&strDefaultFile.m_charbuffer[-1]);
  }
  else
  {
    v1 = o_strFile->m_charbuffer;
    if ( o_strFile->m_charbuffer != UserPreferences::sm_strDefaultFile.m_charbuffer )
    {
      v2 = (int)&v1[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v1[-1]) && v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
      v3 = (volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1];
      o_strFile->m_charbuffer = UserPreferences::sm_strDefaultFile.m_charbuffer;
      InterlockedIncrement(v3);
    }
    v4 = PSUtils::check_access(o_strFile, 0);
    if ( !InterlockedDecrement((volatile LONG *)&strDefaultPath.m_charbuffer[-1])
      && strDefaultPath.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&strDefaultPath.m_charbuffer[-2].m_data[12])(
        &strDefaultPath.m_charbuffer[-2].m_data[12],
        1);
    v5 = &strDefaultFile.m_charbuffer[-2].m_data[12];
    v6 = InterlockedDecrement((volatile LONG *)&strDefaultFile.m_charbuffer[-1]);
  }
  if ( !v6 && v5 )
    (**(void (__thiscall ***)(char *, signed int))v5)(v5, 1);
  return v4;
}
// 817AFC: using guessed type bool UserPreferences::sm_bTools;
// 836CD0: using guessed type bool ProjectSettings::sm_bInitialized;

//----- (00437F30) --------------------------------------------------------  // acclient.c:117177
char __cdecl UserPreferences::Save()
{
  char v0; // bl@1
  bool v1; // bl@3
  char *v2; // esi@5
  GlobalRegistryInstance *v3; // eax@9
  GlobalRegistryInstance *v4; // eax@10
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@14
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v6; // ebx@14
  HashTableData<unsigned long,HeritageGroup_CG> **v7; // edi@14
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // esi@14
  GlobalRegistryInstance *v9; // eax@15
  GlobalRegistryInstance *v10; // eax@16
  GRPVariableObject *v11; // ebp@19
  unsigned int v12; // eax@22
  PSRefBufferCharData<char> *v13; // ebx@30
  unsigned int v14; // eax@30
  int v15; // ecx@31
  int v16; // ebp@31
  int v17; // edx@32
  PSRefBufferCharData<char> *v18; // esi@38
  PStringBase<char> *v19; // edi@40
  int v20; // esi@41
  char *v21; // edi@45
  PSRefBufferCharData<char> **v22; // ebp@48
  char *v23; // edi@49
  LONG (__stdcall *v24)(volatile LONG *); // ebp@53
  char *v25; // edi@53
  int v26; // esi@58
  char *v27; // edi@63
  char *v28; // edi@66
  int v29; // esi@69
  int v30; // esi@72
  LONG v31; // eax@72
  char *v32; // esi@81
  bool bRet; // [sp+Fh] [bp-39h]@1
  PStringBase<char> CategoryName; // [sp+10h] [bp-38h]@38
  PStringBase<char> DefaultFile; // [sp+14h] [bp-34h]@1
  PStringBase<char> ValueAsString; // [sp+18h] [bp-30h]@3
  unsigned int p; // [sp+1Ch] [bp-2Ch]@28
  PStringBase<char> FullName; // [sp+20h] [bp-28h]@30
  GRPVariableObject *pVariableObject; // [sp+24h] [bp-24h]@29
  PStringBase<char> v41; // [sp+28h] [bp-20h]@40
  PStringBase<char> v42; // [sp+2Ch] [bp-1Ch]@48
  SmartArray<GRPVariableObject const *,1> m_PreferenceObjects; // [sp+30h] [bp-18h]@9
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+3Ch] [bp-Ch]@14

  DefaultFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v0 = UserPreferences::FindDefaultFile(&DefaultFile);
  bRet = v0;
  if ( v0 )
    goto LABEL_9;
  if ( *(_DWORD *)&DefaultFile.m_charbuffer[-1].m_data[12] != 1 )
  {
    ValueAsString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v1 = PSUtils::get_directory(&ValueAsString, &DefaultFile);
    bRet = v1;
    if ( v1 )
    {
      bRet = PSUtils::create_directory(&ValueAsString);
      v1 = bRet;
    }
    v2 = &ValueAsString.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&ValueAsString.m_charbuffer[-1]) && v2 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    if ( !v1 )
    {
LABEL_80:
      v0 = bRet;
      goto LABEL_81;
    }
LABEL_9:
    v3 = GlobalRegistry::s_pcGlobalRegistry;
    m_PreferenceObjects.m_data = 0;
    m_PreferenceObjects.m_sizeAndDeallocate = 0;
    m_PreferenceObjects.m_num = 0;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v4 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v4 )
        GlobalRegistryInstance::GlobalRegistryInstance(v4);
      else
        v3 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v3;
    }
    v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_ObjectHash.m_intrusiveTable,
           &result);
    v6 = v5->m_currHashTable;
    v7 = v5->m_currBucket;
    v8 = v5->m_currElement;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v9 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v9 )
      {
        GlobalRegistryInstance::GlobalRegistryInstance(v9);
        GlobalRegistry::s_pcGlobalRegistry = v10;
      }
      else
      {
        GlobalRegistry::s_pcGlobalRegistry = 0;
      }
    }
    if ( v8 )
    {
      do
      {
LABEL_19:
        v11 = (GRPVariableObject *)(*((int (**)(void))v8->m_data.vfptr->Serialize + 12))();
        if ( v11 )
        {
          if ( (unsigned __int8)(*(int (__thiscall **)(GRPVariableObject *))&v11->vfptr[1].gap0[0])(v11) )
          {
            if ( m_PreferenceObjects.m_num < (m_PreferenceObjects.m_sizeAndDeallocate & 0x7FFFFFFF)
              || (v12 = SmartArray<UIChildFramework *,1>::get_new_size((m_PreferenceObjects.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
                  SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&m_PreferenceObjects, v12)) )
              m_PreferenceObjects.m_data[m_PreferenceObjects.m_num++] = v11;
          }
        }
        v8 = v8->m_hashNext;
      }
      while ( v8 );
      while ( 1 )
      {
        ++v7;
        if ( v7 == &v6->m_buckets[v6->m_numBuckets] )
          break;
        if ( *v7 )
        {
          v8 = *v7;
          if ( *v7 )
            goto LABEL_19;
          break;
        }
      }
    }
    p = 0;
    if ( m_PreferenceObjects.m_num )
    {
      while ( 1 )
      {
        pVariableObject = m_PreferenceObjects.m_data[p];
        if ( pVariableObject )
          break;
LABEL_77:
        ++p;
        if ( p >= m_PreferenceObjects.m_num )
          goto LABEL_78;
      }
      FullName.m_charbuffer = pVariableObject->m_Name.m_charbuffer;
      v13 = FullName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&FullName.m_charbuffer[-1]);
      v14 = *(_DWORD *)&v13[-1].m_data[12];
      if ( v14 <= 1 )
      {
        v30 = (int)&v13[-2].m_data[12];
        v31 = InterlockedDecrement((volatile LONG *)&v13[-1]);
LABEL_74:
        if ( !v31 && v30 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
        goto LABEL_77;
      }
      v15 = v14 - 2;
      v16 = -1;
      if ( ((v14 - 2) & 0x80000000) == 0 )
      {
        while ( 1 )
        {
          v17 = (int)((char *)v13 + v14 - 1);
          if ( v15 < v14 )
            v17 = (int)((char *)v13 + v15);
          if ( *(_BYTE *)v17 == 46 )
            break;
          --v15;
          if ( v15 < 0 )
            goto LABEL_38;
        }
        v16 = v15;
      }
LABEL_38:
      v18 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      CategoryName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      if ( v16 <= 0 )
      {
        if ( v18 != v13 )
        {
          v26 = (int)&v18[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v26 + 4)) && v26 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v26)(v26, 1);
          v18 = v13;
          InterlockedIncrement((volatile LONG *)&v13[-1]);
        }
        PStringBase<char>::set(&CategoryName, "Default");
        v24 = InterlockedDecrement;
      }
      else
      {
        if ( v16 >= *(_DWORD *)&v13[-1].m_data[12] - 2 )
        {
          v24 = InterlockedDecrement;
LABEL_66:
          v28 = &CategoryName.m_charbuffer[-2].m_data[12];
          if ( !v24((volatile LONG *)&CategoryName.m_charbuffer[-1]) && v28 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
          v29 = (int)&v18[-2].m_data[12];
          if ( !v24((volatile LONG *)(v29 + 4)) && v29 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v29)(v29, 1);
          v30 = (int)&v13[-2].m_data[12];
          v31 = v24((volatile LONG *)&v13[-1]);
          goto LABEL_74;
        }
        v19 = PStringBase<char>::substring(&FullName, &v41, v16 + 1, *(_DWORD *)&v13[-1].m_data[12] - 2);
        if ( v18 != v19->m_charbuffer )
        {
          v20 = (int)&v18[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)(v20 + 4)) && v20 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
          v18 = v19->m_charbuffer;
          InterlockedIncrement((volatile LONG *)&v19->m_charbuffer[-1]);
        }
        v21 = &v41.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v41.m_charbuffer[-1]) && v21 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
        v22 = (PSRefBufferCharData<char> **)PStringBase<char>::substring(&FullName, &v42, 0, v16 - 1);
        if ( CategoryName.m_charbuffer != *v22 )
        {
          v23 = &CategoryName.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&CategoryName.m_charbuffer[-1]) && v23 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
          CategoryName.m_charbuffer = *v22;
          InterlockedIncrement((volatile LONG *)&CategoryName.m_charbuffer[-1]);
        }
        v24 = InterlockedDecrement;
        v25 = &v42.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v42.m_charbuffer[-1]) && v25 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v25)(v25, 1);
      }
      ValueAsString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      ((void (__stdcall *)(_DWORD))pVariableObject->vfptr[1].AsGeneric)(&ValueAsString);
      WritePrivateProfileStringA(
        CategoryName.m_charbuffer->m_data,
        v18->m_data,
        ValueAsString.m_charbuffer->m_data,
        DefaultFile.m_charbuffer->m_data);
      v27 = &ValueAsString.m_charbuffer[-2].m_data[12];
      if ( !v24((volatile LONG *)&ValueAsString.m_charbuffer[-1]) && v27 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v27)(v27, 1);
      goto LABEL_66;
    }
LABEL_78:
    if ( (m_PreferenceObjects.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
      operator delete[](m_PreferenceObjects.m_data);
    goto LABEL_80;
  }
LABEL_81:
  v32 = &DefaultFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DefaultFile.m_charbuffer[-1]) && v32 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
  return v0;
}

//----- (004383C0) --------------------------------------------------------  // acclient.c:117445
char __thiscall UserPreferences::ConsoleCommand_SavePreferences(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@1
  char *v2; // esi@5
  PStringBase<char> _Text; // [sp+4h] [bp-4h]@1

  _Text.m_charbuffer = this;
  PStringBase<char>::PStringBase<char>(&_Text, "Saving preferences...\n");
  GlobalRegistry::OutputText(&_Text);
  v1 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  if ( !UserPreferences::Save() )
  {
    PStringBase<char>::PStringBase<char>(&_Text, "Error while saving preferences!\n");
    GlobalRegistry::OutputText(&_Text);
    v2 = &_Text.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
  }
  return 1;
}

//----- (00438450) --------------------------------------------------------  // acclient.c:117472
char __cdecl UserPreferences::InqChoiceValues(PStringBase<char> *i_str, SmartArray<unsigned long,1> *o_array)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  char result; // al@10
  int v6; // eax@12
  int v7; // ebp@12
  bool v8; // cl@12
  int v9; // eax@13
  unsigned int v10; // edi@13
  int v11; // ebx@14
  unsigned int v12; // eax@14
  unsigned int v13; // eax@15
  char v14; // al@15
  bool v15; // [sp+3h] [bp-9h]@12
  unsigned int nEnums; // [sp+4h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+8h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 4 )
  {
    nEnums = 0;
    result = UserPreferences::FindPreference(i_str, (GRPVariableObject **)&nEnums);
    if ( result )
    {
      v6 = (*(int (**)(void))(*(_DWORD *)nEnums + 68))();
      v7 = v6;
      v8 = v6 != 0;
      v15 = v6 != 0;
      if ( v6 )
      {
        v9 = *(_DWORD *)(v6 + 36);
        v10 = 0;
        nEnums = *(_DWORD *)(v7 + 36);
        if ( v9 )
        {
          do
          {
            v11 = *(_DWORD *)(v7 + 32) + 4 * v10;
            v12 = o_array->m_sizeAndDeallocate & 0x7FFFFFFF;
            if ( o_array->m_num < v12
              || (v13 = SmartArray<UIChildFramework *,1>::get_new_size(v12 + 1),
                  v14 = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)o_array, v13),
                  v8 = v15,
                  v14) )
              o_array->m_data[o_array->m_num++] = *(_DWORD *)v11;
            ++v10;
          }
          while ( v10 < nEnums );
        }
      }
      result = v8;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00438560) --------------------------------------------------------  // acclient.c:117547
bool __cdecl UserPreferences::InqChoiceStrings(PStringBase<char> *i_str, SmartArray<PStringBase<char>,1> *o_array)
{
  GlobalRegistryInstance *v2; // eax@1
  GlobalRegistryInstance *v3; // eax@2
  int v4; // esi@7
  bool result; // al@10
  int v6; // eax@12
  int v7; // edi@12
  unsigned int v8; // ebp@14
  unsigned int v9; // esi@14
  bool v10; // [sp+3h] [bp-9h]@12
  GRPVariableObject *_pFoundVariable; // [sp+4h] [bp-8h]@11
  GRPObject *_pFoundObject; // [sp+8h] [bp-4h]@6

  v2 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v3 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v3 )
      GlobalRegistryInstance::GlobalRegistryInstance(v3);
    else
      v2 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v2;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v2, i_str, &_pFoundObject)
    && (v4 = ((int (*)(void))_pFoundObject->vfptr->AsTypedVariableObject)()) != 0
    && (unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v4 + 72))(v4)
    && *(_DWORD *)(v4 + 16) == 4 )
  {
    _pFoundVariable = 0;
    result = UserPreferences::FindPreference(i_str, &_pFoundVariable);
    if ( result )
    {
      v6 = ((int (*)(void))_pFoundVariable->vfptr->AsTypedVariableObject)();
      v7 = v6;
      result = v6 != 0;
      v10 = result;
      if ( result )
      {
        if ( v7 )
        {
          v8 = *(_DWORD *)(v7 + 28);
          v9 = 0;
          if ( v8 )
          {
            do
              SmartArray<PStringBase<char>,1>::AddToEnd(o_array, (PStringBase<char> *)(*(_DWORD *)(v7 + 24) + 4 * v9++));
            while ( v9 < v8 );
            result = v10;
          }
        }
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00438640) --------------------------------------------------------  // acclient.c:117609
char __cdecl UserPreferences::Load()
{
  void *v0; // esi@2
  int v1; // edi@2
  unsigned int v2; // eax@2
  char *v3; // esi@6
  LONG v4; // eax@6
  PSRefBufferCharData<char> *v6; // ebx@20
  char *v7; // esi@20
  unsigned int v8; // eax@20
  ListNode<PStringBase<char> > *j; // esi@27
  int v10; // ecx@29
  unsigned int v11; // eax@35
  int v12; // esi@37
  int v13; // esi@40
  char *v14; // esi@43
  char *v15; // esi@46
  char *v16; // esi@52
  unsigned int i; // esi@64
  char *v18; // esi@73
  char *v19; // esi@89
  char bRet; // [sp+13h] [bp-5Dh]@1
  PStringBase<char> strDefaultFile; // [sp+14h] [bp-5Ch]@1
  PStringBase<char> strValue; // [sp+18h] [bp-58h]@24
  PStringBase<char> strKey; // [sp+1Ch] [bp-54h]@24
  PStringBase<char> strPreference; // [sp+20h] [bp-50h]@23
  PStringBase<char> strFullname; // [sp+24h] [bp-4Ch]@34
  unsigned int iPreference; // [sp+28h] [bp-48h]@22
  unsigned int iSection; // [sp+2Ch] [bp-44h]@19
  char *preferenceBuffer; // [sp+30h] [bp-40h]@19
  PSRefBufferCharData<char> *v29; // [sp+34h] [bp-3Ch]@34
  PSRefBufferCharData<char> *v30; // [sp+38h] [bp-38h]@34
  SmartArray<_STL::pair<PStringBase<char>,PStringBase<char> >,1> NameValuePairs; // [sp+3Ch] [bp-34h]@2
  PStringBaseArray<char> sectionArray; // [sp+48h] [bp-28h]@7
  PStringBaseArray<char> preferenceArray; // [sp+54h] [bp-1Ch]@21
  List<PStringBase<char> > keyValue; // [sp+60h] [bp-10h]@23

  strDefaultFile.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  UserPreferences::sm_bPrefsLoadedOK = 0;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  bRet = UserPreferences::FindDefaultFile(&strDefaultFile);
  if ( !bRet )
  {
LABEL_73:
    v18 = &strDefaultFile.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&strDefaultFile.m_charbuffer[-1]) && v18 )
      (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    return bRet;
  }
  NameValuePairs.m_data = 0;
  NameValuePairs.m_sizeAndDeallocate = 0;
  NameValuePairs.m_num = 0;
  v0 = operator new[](0x4000u);
  memset(v0, 0, 0x4000u);
  v1 = (int)((char *)v0 + 0x4000);
  v2 = GetPrivateProfileSectionNamesA((LPSTR)v0, 0x4000u, strDefaultFile.m_charbuffer->m_data);
  if ( !v2 )
  {
    operator delete[](v0);
    if ( (NameValuePairs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)NameValuePairs.m_data )
      _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(NameValuePairs.m_data, 3u);
    v3 = &strDefaultFile.m_charbuffer[-2].m_data[12];
    v4 = InterlockedDecrement((volatile LONG *)&strDefaultFile.m_charbuffer[-1]);
LABEL_15:
    if ( !v4 )
    {
      if ( v3 )
        (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
    }
    return 0;
  }
  sectionArray.m_data = 0;
  sectionArray.m_sizeAndDeallocate = 0;
  sectionArray.m_num = 0;
  if ( !PSUtils::explode((const char *)v0, v2, &sectionArray) )
  {
    operator delete[](v0);
    if ( (sectionArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)sectionArray.m_data )
      PStringBase<unsigned short>::vector_deleting_destructor(sectionArray.m_data, 3u);
    if ( (NameValuePairs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)NameValuePairs.m_data )
      _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(NameValuePairs.m_data, 3u);
    v3 = &strDefaultFile.m_charbuffer[-2].m_data[12];
    v4 = InterlockedDecrement((volatile LONG *)&strDefaultFile.m_charbuffer[-1]);
    goto LABEL_15;
  }
  operator delete[](v0);
  preferenceBuffer = (char *)operator new[](0x4000u);
  iSection = 0;
  if ( sectionArray.m_num <= 0 )
  {
LABEL_64:
    operator delete[](preferenceBuffer);
    for ( i = 0; i < NameValuePairs.m_num; ++i )
      GlobalRegistry::SetGlobalVariable(v1, &NameValuePairs.m_data[i].first, &NameValuePairs.m_data[i].second);
    if ( (sectionArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)sectionArray.m_data )
      PStringBase<unsigned short>::vector_deleting_destructor(sectionArray.m_data, 3u);
    if ( (NameValuePairs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)NameValuePairs.m_data )
      _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(NameValuePairs.m_data, 3u);
    UserPreferences::sm_bPrefsLoadedOK = 1;
    goto LABEL_73;
  }
  while ( 1 )
  {
    v6 = sectionArray.m_data[iSection].m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v6[-1]);
    v7 = preferenceBuffer;
    memset(preferenceBuffer, 0, 0x4000u);
    v8 = GetPrivateProfileSectionA(v6->m_data, v7, 0x4000u, strDefaultFile.m_charbuffer->m_data);
    v1 = 0;
    if ( v8 )
      break;
LABEL_60:
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
    ++iSection;
    if ( iSection >= sectionArray.m_num )
      goto LABEL_64;
  }
  preferenceArray.m_data = 0;
  preferenceArray.m_sizeAndDeallocate = 0;
  preferenceArray.m_num = 0;
  if ( PSUtils::explode(v7, v8, &preferenceArray) )
  {
    iPreference = 0;
    if ( preferenceArray.m_num > 0 )
    {
      while ( 1 )
      {
        strPreference.m_charbuffer = preferenceArray.m_data[iPreference].m_charbuffer;
        InterlockedIncrement((volatile LONG *)&strPreference.m_charbuffer[-1]);
        keyValue.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
        keyValue._head = 0;
        keyValue._tail = 0;
        keyValue._num_elements = 0;
        if ( !PSUtils::explode(&strPreference, 61, &keyValue) )
          goto LABEL_52;
        strKey.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        strValue.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( keyValue._num_elements == 2 )
          break;
        if ( keyValue._num_elements > 2 )
        {
          List<PStringBase<char>>::pop_front(&keyValue, &strKey);
          for ( j = keyValue._head; j; j = j->next )
          {
            v10 = *(_DWORD *)&j->data.m_charbuffer[-1].m_data[12];
            if ( v10 != 1 )
              PStringBase<char>::append_n_chars(&strValue, j->data.m_charbuffer->m_data, v10 - 1);
          }
          goto LABEL_34;
        }
        if ( keyValue._num_elements == 1 )
        {
          List<PStringBase<char>>::pop_front(&keyValue, &strKey);
          PStringBase<char>::set(&strValue, &name);
LABEL_34:
          strFullname.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          v1 = (int)strKey.m_charbuffer;
          PStringBase<char>::sprintf(&strFullname, "%s.%s", v6, strKey.m_charbuffer);
          v29 = strFullname.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&strFullname.m_charbuffer[-1]);
          v30 = strValue.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&strValue.m_charbuffer[-1]);
          if ( NameValuePairs.m_num < (NameValuePairs.m_sizeAndDeallocate & 0x7FFFFFFF)
            || (v11 = SmartArray<UIChildFramework *,1>::get_new_size((NameValuePairs.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
                SmartArray<_STL::pair<PStringBase<char>,PStringBase<char>>,1>::grow(&NameValuePairs, v11)) )
            _STL::pair<PStringBase<char>,PStringBase<char>>::operator=(
              &NameValuePairs.m_data[NameValuePairs.m_num++],
              (int)&v29);
          v12 = (int)&v30[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v30[-1]) && v12 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
          v13 = (int)&v29[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v29[-1]) && v13 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
          v14 = &strFullname.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&strFullname.m_charbuffer[-1]) && v14 )
            (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
          v15 = &strValue.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&strValue.m_charbuffer[-1]) && v15 )
            (**(void (__thiscall ***)(char *, signed int))v15)(v15, 1);
          if ( !InterlockedDecrement((volatile LONG *)(v1 - 20 + 4)) && v1 != 20 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))(v1 - 20))(v1 - 20, 1);
LABEL_52:
          keyValue.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
          List<PStringBase<char>>::flush(&keyValue);
          v16 = &strPreference.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&strPreference.m_charbuffer[-1]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
          goto LABEL_56;
        }
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strValue);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strKey);
        keyValue.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
        List<PStringBase<char>>::flush(&keyValue);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&strPreference);
LABEL_56:
        ++iPreference;
        if ( iPreference >= preferenceArray.m_num )
          goto LABEL_57;
      }
      List<PStringBase<char>>::pop_front(&keyValue, &strKey);
      List<PStringBase<char>>::pop_front(&keyValue, &strValue);
      goto LABEL_34;
    }
LABEL_57:
    if ( (preferenceArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)preferenceArray.m_data )
      PStringBase<unsigned short>::vector_deleting_destructor(preferenceArray.m_data, 3u);
    goto LABEL_60;
  }
  operator delete[](v7);
  if ( (preferenceArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)preferenceArray.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor(preferenceArray.m_data, 3u);
  if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v6 != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(char *, signed int))&v6[-2].m_data[12])(&v6[-2].m_data[12], 1);
  if ( (sectionArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)sectionArray.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor(sectionArray.m_data, 3u);
  if ( (NameValuePairs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)NameValuePairs.m_data )
    _STL::pair<PStringBase<char>,PStringBase<char>>::vector_deleting_destructor(NameValuePairs.m_data, 3u);
  v19 = &strDefaultFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&strDefaultFile.m_charbuffer[-1]) && v19 )
    (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
  return 0;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);
// 817AFD: using guessed type bool UserPreferences::sm_bPrefsLoadedOK;

//----- (00438C50) --------------------------------------------------------  // acclient.c:117840
char __thiscall UserPreferences::ConsoleCommand_LoadPreferences(PSRefBufferCharData<char> *this)
{
  char *v1; // esi@1
  char *v2; // esi@5
  PStringBase<char> _Text; // [sp+4h] [bp-4h]@1

  _Text.m_charbuffer = this;
  PStringBase<char>::PStringBase<char>(&_Text, "Loading preferences...\n");
  GlobalRegistry::OutputText(&_Text);
  v1 = &_Text.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v1 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v1)(v1, 1);
  if ( UserPreferences::Load() )
  {
    PStringBase<char>::PStringBase<char>(&_Text, "Error while loading preferences!\n");
    GlobalRegistry::OutputText(&_Text);
    v2 = &_Text.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) )
    {
      if ( v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
    }
  }
  return 1;
}

//----- (00438CE0) --------------------------------------------------------  // acclient.c:117867
char __cdecl UserPreferences::Initialize(const bool i_bTools, PStringBase<char> *i_str)
{
  char *v2; // esi@1
  char *v3; // esi@4
  char *v4; // esi@7
  unsigned int v5; // esi@10
  char v6; // al@15
  int v7; // esi@15
  char v8; // bl@15
  PStringBase<char> _Name; // [sp+Ch] [bp-8h]@1
  PStringBase<char> _Description; // [sp+10h] [bp-4h]@1

  UserPreferences::sm_bTools = i_bTools;
  UserPreferences::sm_bPrefsLoadedOK = 1;
  PStringBase<char>::PStringBase<char>(&_Description, "Loads user preferences from disk");
  PStringBase<char>::PStringBase<char>(&_Name, "LoadPreferences");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())UserPreferences::ConsoleCommand_LoadPreferences,
    &_Name,
    &_Description);
  v2 = &_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  PStringBase<char>::PStringBase<char>(&_Name, "Saves user preferences to disk");
  PStringBase<char>::PStringBase<char>(&_Description, "SavePreferences");
  GlobalRegistry::RegisterCommand(
    (bool (__cdecl *)())UserPreferences::ConsoleCommand_SavePreferences,
    &_Description,
    &_Name);
  v4 = &_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Description.m_charbuffer[-1]) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  v5 = (unsigned int)&_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&_Name.m_charbuffer[-1]) && v5 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
  *(_DWORD *)&i_bTools = i_str->m_charbuffer;
  InterlockedIncrement((volatile LONG *)(i_bTools - 16));
  if ( *(_DWORD *)(i_bTools - 4) == 1 )
    UserPreferences::FindDefaultFile((PStringBase<char> *)&i_bTools);
  v6 = UserPreferences::SetDefaultFile(v5, (PStringBase<char> *)&i_bTools);
  v7 = i_bTools - 20;
  v8 = v6;
  if ( !InterlockedDecrement((volatile LONG *)(i_bTools - 20 + 4)) && v7 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  return v8;
}
// 817AFC: using guessed type bool UserPreferences::sm_bTools;
// 817AFD: using guessed type bool UserPreferences::sm_bPrefsLoadedOK;

//----- (006C5EC0) --------------------------------------------------------  // acclient.c:734219
int _E73_28()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_6, "None");
  return atexit(_E74_30);
}

//----- (006C5EE0) --------------------------------------------------------  // acclient.c:734226
int _E76_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_6, "Speed");
  return atexit(_E77_46);
}

//----- (006C5F00) --------------------------------------------------------  // acclient.c:734233
int _E79_18()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_6, "Noise");
  return atexit(_E80_20);
}

//----- (006C5F20) --------------------------------------------------------  // acclient.c:734240
int _E82_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_6, "Sine");
  return atexit(_E83_10);
}

//----- (006C5F40) --------------------------------------------------------  // acclient.c:734247
int _E85_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_6, "Square");
  return atexit(_E86_7);
}

//----- (006C5F60) --------------------------------------------------------  // acclient.c:734254
int _E88_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_6, "Bounce");
  return atexit(_E89_18);
}

//----- (006C5F80) --------------------------------------------------------  // acclient.c:734261
int _E91_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_6, "Perlin");
  return atexit(_E92_16);
}

//----- (006C5FA0) --------------------------------------------------------  // acclient.c:734268
int _E94_6()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_6, "Fractal");
  return atexit(sub_728DC0);
}

//----- (006C5FC0) --------------------------------------------------------  // acclient.c:734275
int _E97_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_6, "FrameLoop");
  return atexit(_E98_31);
}

//----- (006C5FE0) --------------------------------------------------------  // acclient.c:734282
int _E100_10()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"ProjectSetting");
  PStringBase<unsigned short>::allocate_ref_buffer(&PROJECTSETTING_1, v0);
  _wcscpy(PROJECTSETTING_1.m_charbuffer->m_data, L"ProjectSetting");
  return atexit(_E101_59);
}

//----- (006C6020) --------------------------------------------------------  // acclient.c:734293
int _E103_6()
{
  PStringBase<char>::PStringBase<char>(&NAME_1, "name");
  return atexit(_E104_29);
}

//----- (006C6040) --------------------------------------------------------  // acclient.c:734300
int _E106_8()
{
  PStringBase<char>::PStringBase<char>(&VALUE_1, "value");
  return atexit(_E107_61);
}

//----- (006C6060) --------------------------------------------------------  // acclient.c:734307
int _E109_5()
{
  PStringBase<char>::PStringBase<char>(&BRANCH_1, "branch");
  return atexit(sub_728EB0);
}

//----- (006C6080) --------------------------------------------------------  // acclient.c:734314
int _E112_7()
{
  PStringBase<char>::PStringBase<char>(&BRANCHBASEDIR_1, "branchbasedir");
  return atexit(_E113_41);
}

//----- (006C60A0) --------------------------------------------------------  // acclient.c:734321
int _E115_5()
{
  PStringBase<char>::PStringBase<char>(&PROJECTNAME_1, "projectname");
  return atexit(_E116_33);
}

//----- (006C60C0) --------------------------------------------------------  // acclient.c:734328
int _E118_7()
{
  PStringBase<char>::PStringBase<char>(&LONGNAME_1, "longname");
  return atexit(_E119_58);
}

//----- (006C60E0) --------------------------------------------------------  // acclient.c:734335
int _E121_6()
{
  PStringBase<char>::PStringBase<char>(&ENUMDB_1, "enumdb");
  return atexit(_E122_45);
}

//----- (006C6100) --------------------------------------------------------  // acclient.c:734342
int _E124_7()
{
  PStringBase<char>::PStringBase<char>(&DIDNAME_1, "didname");
  return atexit(_E125_21);
}

//----- (006C6120) --------------------------------------------------------  // acclient.c:734349
int _E127_6()
{
  PStringBase<char>::PStringBase<char>(&RCS_1, "rcs");
  return atexit(_E128_22);
}

//----- (006C6140) --------------------------------------------------------  // acclient.c:734356
int _E130_6()
{
  PStringBase<char>::PStringBase<char>(&PREPROC_KEYS_BASE_PATH_1, "SOFTWARE\\Turbine\\Preproc");
  return atexit(_E131_18);
}

//----- (006C6160) --------------------------------------------------------  // acclient.c:734363
int _E133_6()
{
  PStringBase<char>::PStringBase<char>(&CURRENT_PROJECT_1, "CURRENT_PROJECT");
  return atexit(_E134_17);
}

//----- (006C6180) --------------------------------------------------------  // acclient.c:734370
int _E136_4()
{
  PStringBase<char>::PStringBase<char>(&DATA_GAME_PATH_1, "data/game");
  return atexit(_E137_17);
}

//----- (006C61A0) --------------------------------------------------------  // acclient.c:734377
int _E139_4()
{
  PStringBase<char>::PStringBase<char>(&DATA_ENGINE_PATH_1, "data/engine");
  return atexit(_E140_12);
}

//----- (006C61C0) --------------------------------------------------------  // acclient.c:734384
int _E142_4()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_GAME_PATH_1, "src/game");
  return atexit(_E143_13);
}

//----- (006C61E0) --------------------------------------------------------  // acclient.c:734391
int _E145_3()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_ENGINE_PATH_1, "src/engine");
  return atexit(_E146_12);
}

//----- (006C6200) --------------------------------------------------------  // acclient.c:734398
int _E148_3()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_BIN_PATH_1, "tools/bin");
  return atexit(_E149_12);
}

//----- (006C6220) --------------------------------------------------------  // acclient.c:734405
int _E151_3()
{
  PStringBase<char>::PStringBase<char>(&CONFIG_TOOLS_PATH_1, "config/tools");
  return atexit(_E152_11);
}

//----- (006C6240) --------------------------------------------------------  // acclient.c:734412
int _E154_4()
{
  PStringBase<char>::PStringBase<char>(&OUTPUT_INI_PATH_1, "output/ini");
  return atexit(_E155_9);
}

//----- (006C6260) --------------------------------------------------------  // acclient.c:734419
int _E157_3()
{
  PStringBase<char>::PStringBase<char>(&DATA_PATH_1, "data");
  return atexit(_E158_12);
}

//----- (006C6280) --------------------------------------------------------  // acclient.c:734426
int _E160_4()
{
  PStringBase<char>::PStringBase<char>(&DOC_PATH_1, "doc");
  return atexit(_E161_9);
}

//----- (006C62A0) --------------------------------------------------------  // acclient.c:734433
int _E163_2()
{
  PStringBase<char>::PStringBase<char>(&EXPORT_PATH_1, "export");
  return atexit(_E164_12);
}

//----- (006C62C0) --------------------------------------------------------  // acclient.c:734440
int _E166_3()
{
  PStringBase<char>::PStringBase<char>(&SDK_PATH_1, "sdk");
  return atexit(_E167_8);
}

//----- (006C62E0) --------------------------------------------------------  // acclient.c:734447
int _E169_1()
{
  PStringBase<char>::PStringBase<char>(&SOURCE_PATH_1, "src");
  return atexit(_E170_7);
}

//----- (006C6300) --------------------------------------------------------  // acclient.c:734454
int _E172_1()
{
  PStringBase<char>::PStringBase<char>(&TOOLS_PATH_1, "tools");
  return atexit(_E173_6);
}

//----- (006C6320) --------------------------------------------------------  // acclient.c:734461
int _E175_1()
{
  PStringBase<char>::PStringBase<char>(&PORTAL_PATH_1, "portal");
  return atexit(_E176_7);
}

//----- (006C6340) --------------------------------------------------------  // acclient.c:734468
int _E178_1()
{
  PStringBase<char>::PStringBase<char>(&AC_PATH_1, "ac");
  return atexit(_E179_6);
}

//----- (006C6360) --------------------------------------------------------  // acclient.c:734475
int _E181_1()
{
  PStringBase<char>::PStringBase<char>(&UserPreferences::sm_strDefaultFile, &name);
  return atexit(_E182_6);
}

//----- (00728C70) --------------------------------------------------------  // acclient.c:826669
void __cdecl _E74_30()
{
  char *v0; // esi@1

  v0 = &waveform_None_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728CA0) --------------------------------------------------------  // acclient.c:826682
void __cdecl _E77_46()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728CD0) --------------------------------------------------------  // acclient.c:826695
void __cdecl _E80_20()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728D00) --------------------------------------------------------  // acclient.c:826708
void __cdecl _E83_10()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728D30) --------------------------------------------------------  // acclient.c:826721
void __cdecl _E86_7()
{
  char *v0; // esi@1

  v0 = &waveform_Square_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728D60) --------------------------------------------------------  // acclient.c:826734
void __cdecl _E89_18()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728D90) --------------------------------------------------------  // acclient.c:826747
void __cdecl _E92_16()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728DC0) --------------------------------------------------------  // acclient.c:826760
void __cdecl sub_728DC0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728DF0) --------------------------------------------------------  // acclient.c:826773
void __cdecl _E98_31()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728E20) --------------------------------------------------------  // acclient.c:826786
void __cdecl _E101_59()
{
  char *v0; // esi@1

  v0 = (char *)&PROJECTSETTING_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTSETTING_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728E50) --------------------------------------------------------  // acclient.c:826799
void __cdecl _E104_29()
{
  char *v0; // esi@1

  v0 = &NAME_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NAME_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728E80) --------------------------------------------------------  // acclient.c:826812
void __cdecl _E107_61()
{
  char *v0; // esi@1

  v0 = &VALUE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VALUE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728EB0) --------------------------------------------------------  // acclient.c:826825
void __cdecl sub_728EB0()
{
  char *v0; // esi@1

  v0 = &BRANCH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728EE0) --------------------------------------------------------  // acclient.c:826838
void __cdecl _E113_41()
{
  char *v0; // esi@1

  v0 = &BRANCHBASEDIR_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BRANCHBASEDIR_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728F10) --------------------------------------------------------  // acclient.c:826851
void __cdecl _E116_33()
{
  char *v0; // esi@1

  v0 = &PROJECTNAME_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PROJECTNAME_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728F40) --------------------------------------------------------  // acclient.c:826864
void __cdecl _E119_58()
{
  char *v0; // esi@1

  v0 = &LONGNAME_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LONGNAME_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728F70) --------------------------------------------------------  // acclient.c:826877
void __cdecl _E122_45()
{
  char *v0; // esi@1

  v0 = &ENUMDB_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ENUMDB_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728FA0) --------------------------------------------------------  // acclient.c:826890
void __cdecl _E125_21()
{
  char *v0; // esi@1

  v0 = &DIDNAME_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DIDNAME_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728FD0) --------------------------------------------------------  // acclient.c:826903
void __cdecl _E128_22()
{
  char *v0; // esi@1

  v0 = &RCS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RCS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729000) --------------------------------------------------------  // acclient.c:826916
void __cdecl _E131_18()
{
  char *v0; // esi@1

  v0 = &PREPROC_KEYS_BASE_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PREPROC_KEYS_BASE_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729030) --------------------------------------------------------  // acclient.c:826929
void __cdecl _E134_17()
{
  char *v0; // esi@1

  v0 = &CURRENT_PROJECT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CURRENT_PROJECT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729060) --------------------------------------------------------  // acclient.c:826942
void __cdecl _E137_17()
{
  char *v0; // esi@1

  v0 = &DATA_GAME_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_GAME_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729090) --------------------------------------------------------  // acclient.c:826955
void __cdecl _E140_12()
{
  char *v0; // esi@1

  v0 = &DATA_ENGINE_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_ENGINE_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007290C0) --------------------------------------------------------  // acclient.c:826968
void __cdecl _E143_13()
{
  char *v0; // esi@1

  v0 = &SOURCE_GAME_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_GAME_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007290F0) --------------------------------------------------------  // acclient.c:826981
void __cdecl _E146_12()
{
  char *v0; // esi@1

  v0 = &SOURCE_ENGINE_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_ENGINE_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729120) --------------------------------------------------------  // acclient.c:826994
void __cdecl _E149_12()
{
  char *v0; // esi@1

  v0 = &TOOLS_BIN_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_BIN_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729150) --------------------------------------------------------  // acclient.c:827007
void __cdecl _E152_11()
{
  char *v0; // esi@1

  v0 = &CONFIG_TOOLS_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CONFIG_TOOLS_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729180) --------------------------------------------------------  // acclient.c:827020
void __cdecl _E155_9()
{
  char *v0; // esi@1

  v0 = &OUTPUT_INI_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OUTPUT_INI_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007291B0) --------------------------------------------------------  // acclient.c:827033
void __cdecl _E158_12()
{
  char *v0; // esi@1

  v0 = &DATA_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DATA_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007291E0) --------------------------------------------------------  // acclient.c:827046
void __cdecl _E161_9()
{
  char *v0; // esi@1

  v0 = &DOC_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DOC_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729210) --------------------------------------------------------  // acclient.c:827059
void __cdecl _E164_12()
{
  char *v0; // esi@1

  v0 = &EXPORT_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EXPORT_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729240) --------------------------------------------------------  // acclient.c:827072
void __cdecl _E167_8()
{
  char *v0; // esi@1

  v0 = &SDK_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SDK_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729270) --------------------------------------------------------  // acclient.c:827085
void __cdecl _E170_7()
{
  char *v0; // esi@1

  v0 = &SOURCE_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SOURCE_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007292A0) --------------------------------------------------------  // acclient.c:827098
void __cdecl _E173_6()
{
  char *v0; // esi@1

  v0 = &TOOLS_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TOOLS_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007292D0) --------------------------------------------------------  // acclient.c:827111
void __cdecl _E176_7()
{
  char *v0; // esi@1

  v0 = &PORTAL_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PORTAL_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729300) --------------------------------------------------------  // acclient.c:827124
void __cdecl _E179_6()
{
  char *v0; // esi@1

  v0 = &AC_PATH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AC_PATH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00729330) --------------------------------------------------------  // acclient.c:827137
void __cdecl _E182_6()
{
  char *v0; // esi@1

  v0 = &UserPreferences::sm_strDefaultFile.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UserPreferences::sm_strDefaultFile.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

