/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GlobalRegistry
   Object     : ENGINE\globalregistry\GlobalRegistry.obj
   Functions  : 49
   Addresses  : 00434FE0 - 00728C20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00434FE0) --------------------------------------------------------  // acclient.c:114324
void __cdecl GlobalRegistry::UnregisterConsoleCallbackObject(IConsoleCallbackObject *io_pConsoleCallbackObject)
{
  GlobalRegistryInstance *v1; // eax@1
  GlobalRegistryInstance *v2; // eax@2

  v1 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v2 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v2 )
      GlobalRegistryInstance::GlobalRegistryInstance(v2);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  SmartArray<UIElement *,1>::RemoveUnOrdered(
    (SmartArray<bool (__cdecl*)(void),1> *)&v1->m_ConsoleCallbackObjects,
    (bool (__cdecl *const *)())&io_pConsoleCallbackObject);
}

//----- (00435020) --------------------------------------------------------  // acclient.c:114345
void __thiscall GRPWithArgsCommand::~GRPWithArgsCommand(GRPShadowVariableObject *this)
{
  GRPShadowVariableObject *v1; // edi@1
  char *v2; // esi@1
  int v3; // esi@4
  int v4; // esi@7

  v1 = this;
  v2 = &this->m_ValueString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v2 + 1) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->m_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00435090) --------------------------------------------------------  // acclient.c:114368
void __thiscall FixedArray<PStringBase<char>>::Create(FixedArray<PStringBase<char> > *this, unsigned int i_numElements)
{
  unsigned int v2; // edi@1
  FixedArray<PStringBase<char> > *v3; // ebx@1
  void *v4; // eax@1
  int v5; // ebp@2
  int v6; // esi@2
  volatile LONG *v7; // ST00_4@3
  FixedArray<PStringBase<char> > *v8; // [sp+0h] [bp-4h]@1

  v2 = i_numElements;
  v3 = this;
  v8 = this;
  this->m_num = i_numElements;
  v4 = operator new[](4 * i_numElements + 4);
  if ( v4 )
  {
    v5 = (int)((char *)v4 + 4);
    *(_DWORD *)v4 = i_numElements;
    v6 = (int)((char *)v4 + 4);
    if ( ((i_numElements - 1) & 0x80000000) == 0 )
    {
      do
      {
        v7 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
        *(_DWORD *)v6 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement(v7);
        v6 += 4;
        --v2;
      }
      while ( v2 );
      v3 = v8;
    }
    v3->m_data = (PStringBase<char> *)v5;
  }
  else
  {
    v3->m_data = 0;
  }
}

//----- (00435100) --------------------------------------------------------  // acclient.c:114410
void __thiscall GRPNoArgsCommand::GRPNoArgsCommand(GRPNoArgsCommand *this)
{
  GRPNoArgsCommand *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (GRPGenericVtbl *)GRPGeneric::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_Description.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->vfptr = (GRPGenericVtbl *)GRPNoArgsCommand::vftable;
  v1->m_FunctionPointerNoArgs = 0;
}
// 798930: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPGeneric::vftable[2])(DeleteLeafTransactInfo *__hidden this);
// 798978: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPNoArgsCommand::vftable[6])(DeleteLeafTransactInfo *__hidden this);

//----- (00435150) --------------------------------------------------------  // acclient.c:114431
void __thiscall GRPWithArgsCommand::GRPWithArgsCommand(GRPWithArgsCommand *this)
{
  GRPWithArgsCommand *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  this->vfptr = (GRPGenericVtbl *)GRPGeneric::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_Description.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->vfptr = (GRPGenericVtbl *)GRPWithArgsCommand::vftable;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_Usage.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
  v1->m_FunctionPointerWithArgs = 0;
}
// 798930: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPGeneric::vftable[2])(DeleteLeafTransactInfo *__hidden this);
// 7989C0: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPWithArgsCommand::vftable[4])(DeleteLeafTransactInfo *__hidden this);

//----- (004351B0) --------------------------------------------------------  // acclient.c:114456
void __thiscall GRPShadowVariableObject::GRPShadowVariableObject(GRPShadowVariableObject *this)
{
  GRPShadowVariableObject *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  this->vfptr = (GRPGenericVtbl *)GRPGeneric::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_Description.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->vfptr = (GRPGenericVtbl *)GRPShadowVariableObject::vftable;
  v4 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_ValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v4);
}
// 798930: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPGeneric::vftable[2])(DeleteLeafTransactInfo *__hidden this);
// 798A08: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPShadowVariableObject::vftable[2])(DeleteLeafTransactInfo *__hidden this);

//----- (00435200) --------------------------------------------------------  // acclient.c:114480
void __thiscall GRPShadowVariableObject::ConvertToString(GRPShadowVariableObject *this, PStringBase<char> *_String)
{
  PSRefBufferCharData<char> *v2; // eax@1
  GRPShadowVariableObject *v3; // edi@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = _String->m_charbuffer;
  v3 = this;
  if ( _String->m_charbuffer != this->m_ValueString.m_charbuffer )
  {
    v4 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v2[-1]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    v5 = v3->m_ValueString.m_charbuffer;
    _String->m_charbuffer = v5;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
}

//----- (00435250) --------------------------------------------------------  // acclient.c:114504
char __thiscall GRPShadowVariableObject::SetFromString(GRPShadowVariableObject *this, PStringBase<char> *_String)
{
  GRPShadowVariableObject *v2; // edi@1
  PSRefBufferCharData<char> *v3; // eax@1
  int v4; // esi@2
  PSRefBufferCharData<char> *v5; // eax@5

  v2 = this;
  v3 = this->m_ValueString.m_charbuffer;
  if ( v3 != _String->m_charbuffer )
  {
    v4 = (int)&v3[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = _String->m_charbuffer;
    v2->m_ValueString.m_charbuffer = _String->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v5[-1]);
  }
  return 1;
}

//----- (004352A0) --------------------------------------------------------  // acclient.c:114526
void __cdecl GlobalRegistry::OutputText(PStringBase<char> *_Text)
{
  PStringBase<char> *v1; // ebx@1
  int v2; // eax@1
  int v3; // ebp@2
  GlobalRegistryInstance *v4; // eax@2
  unsigned int v5; // edi@2
  unsigned int v6; // edx@3
  int v7; // esi@3
  GlobalRegistryInstance *v8; // eax@6
  bool v9; // cf@10
  int v10; // edx@10
  GlobalRegistryInstance *v11; // ecx@10
  unsigned int v12; // eax@11
  unsigned int v13; // eax@16
  unsigned int i; // esi@21
  GlobalRegistryInstance *v15; // eax@23

  v1 = _Text;
  v2 = *(_DWORD *)&_Text->m_charbuffer[-1].m_data[12];
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = GlobalRegistry::s_pcGlobalRegistry;
    v5 = 0;
    if ( v3 )
    {
      do
      {
        v6 = *(_DWORD *)&v1->m_charbuffer[-1].m_data[12];
        v7 = (int)((char *)v1->m_charbuffer + v6 - 1);
        if ( v5 < v6 )
          v7 = (int)((char *)v1->m_charbuffer + v5);
        if ( !v4 )
        {
          v8 = (GlobalRegistryInstance *)operator new(0x8100u);
          if ( v8 )
            GlobalRegistryInstance::GlobalRegistryInstance(v8);
          else
            v4 = 0;
          GlobalRegistry::s_pcGlobalRegistry = v4;
        }
        v9 = v4->m_Characters.m_nNumElements < 0x8000;
        v10 = (int)&v4->m_Characters.m_nNumElements;
        v11 = v4;
        if ( v4->m_Characters.m_nNumElements == 0x8000 )
        {
          v4->m_Characters.m_aMemory[v4->m_Characters.m_nStartIndex] = 0;
          v12 = v4->m_Characters.m_nStartIndex;
          if ( v11->m_Characters.m_nStartIndex == 0x7FFF )
            v11->m_Characters.m_nStartIndex = 0;
          else
            v11->m_Characters.m_nStartIndex = v12 + 1;
          v1 = _Text;
          --*(_DWORD *)v10;
          v4 = GlobalRegistry::s_pcGlobalRegistry;
          v9 = *(_DWORD *)v10 < 0x8000u;
        }
        if ( v9 )
        {
          v11->m_Characters.m_aMemory[v11->m_Characters.m_nEndIndex] = *(_BYTE *)v7;
          v13 = v11->m_Characters.m_nEndIndex;
          if ( v13 == 0x7FFF )
            v11->m_Characters.m_nEndIndex = 0;
          else
            v11->m_Characters.m_nEndIndex = v13 + 1;
          ++*(_DWORD *)v10;
          v4 = GlobalRegistry::s_pcGlobalRegistry;
        }
        ++v5;
      }
      while ( v5 < v3 );
    }
    for ( i = 0; ; ++i )
    {
      if ( !v4 )
      {
        v15 = (GlobalRegistryInstance *)operator new(0x8100u);
        if ( v15 )
          GlobalRegistryInstance::GlobalRegistryInstance(v15);
        else
          v4 = 0;
        GlobalRegistry::s_pcGlobalRegistry = v4;
      }
      if ( i >= v4->m_ConsoleCallbackObjects.m_num )
        break;
      ((void (__stdcall *)(PStringBase<char> *))v4->m_ConsoleCallbackObjects.m_data[i]->vfptr->ConsoleCallback_OnTextAdded)(v1);
      v4 = GlobalRegistry::s_pcGlobalRegistry;
    }
  }
}

//----- (004353C0) --------------------------------------------------------  // acclient.c:114619
GRPNoArgsCommand *__thiscall GRPNoArgsCommand::scalar_deleting_destructor(GRPNoArgsCommand *this, unsigned int a2)
{
  GRPNoArgsCommand *v2; // edi@1
  char *v3; // esi@1
  int v4; // esi@4

  v2 = this;
  v3 = &this->m_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)v3 + 1) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v2->m_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) && v4 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00435420) --------------------------------------------------------  // acclient.c:114638
void __thiscall PStringBase<char>::trim(PStringBase<char> *this, bool pre, bool post, PStringBase<char> filter)
{
  const char *v4; // edi@1
  unsigned int v5; // esi@1
  const char v6; // al@2
  PSRefBufferCharData<char> *v7; // ebx@3
  PStringBase<char> v8; // eax@11
  PSRefBufferCharData<char> *v9; // ebp@16
  PSRefBufferCharData<char> *v10; // eax@16
  int v11; // ebx@17
  volatile LONG *v12; // ST04_4@20
  PStringBase<char> *v13; // [sp+10h] [bp-4h]@1

  v4 = this->m_charbuffer->m_data;
  v5 = *(_DWORD *)&this->m_charbuffer[-1].m_data[12] - 1;
  v13 = this;
  if ( pre && (v6 = *v4) != 0 )
  {
    do
    {
      v7 = filter.m_charbuffer;
      if ( !_strchr(filter.m_charbuffer->m_data, v6) )
        break;
      v6 = (v4++)[1];
      --v5;
    }
    while ( v6 );
  }
  else
  {
    v7 = filter.m_charbuffer;
  }
  if ( post && v5 )
  {
    do
    {
      if ( !_strchr(v7->m_data, v4[v5 - 1]) )
        break;
      --v5;
    }
    while ( v5 );
  }
  v8.m_charbuffer = v13->m_charbuffer;
  if ( (PSRefBufferCharData<char> *)v4 != v13->m_charbuffer || v5 != *(_DWORD *)&v8.m_charbuffer[-1].m_data[12] - 1 )
  {
    v9 = v13->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&v8.m_charbuffer[-1]);
    v10 = v13->m_charbuffer;
    if ( v13->m_charbuffer != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v11 = (int)&v10[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      v13->m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v12);
      v7 = filter.m_charbuffer;
    }
    if ( v5 )
      PStringBase<char>::append_n_chars(v13, v4, v5);
    if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v9 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v9[-2].m_data[12])(&v9[-2].m_data[12], 1);
    if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) && v7 != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))&v7[-2].m_data[12])(&v7[-2].m_data[12], 1);
  }
  else if ( !InterlockedDecrement((volatile LONG *)&v7[-1]) && v7 != (PSRefBufferCharData<char> *)20 )
  {
    (**(void (__thiscall ***)(_DWORD, _DWORD))&v7[-2].m_data[12])(&v7[-2].m_data[12], 1);
  }
}

//----- (00435570) --------------------------------------------------------  // acclient.c:114710
void __thiscall GRPTypedVariableObject::GRPTypedVariableObject(GRPTypedVariableObject *this)
{
  GRPTypedVariableObject *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  this->vfptr = (GRPGenericVtbl *)GRPGeneric::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->m_Name.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_Description.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->m_pVariable = 0;
  v1->m_Type = 0;
  v1->m_OnChangedCallbackFunction = 0;
  v1->vfptr = (GRPGenericVtbl *)GRPTypedVariableObject::vftable;
  v1->m_Choices.m_data = 0;
  v1->m_Choices.m_num = 0;
  v1->m_ChoiceValues.m_data = 0;
  v1->m_ChoiceValues.m_num = 0;
  v1->m_IsGlobal = 0;
}
// 798930: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPGeneric::vftable[2])(DeleteLeafTransactInfo *__hidden this);
// 798A60: using guessed type const struct DeleteLeafTransactInfo *(__thiscall *GRPTypedVariableObject::vftable[2])(DeleteLeafTransactInfo *__hidden this);

//----- (004355D0) --------------------------------------------------------  // acclient.c:114738
bool __thiscall GRPTypedVariableObject::IsGlobal(GRPTypedVariableObject *this)
{
  return this->m_IsGlobal;
}

//----- (004355E0) --------------------------------------------------------  // acclient.c:114744
void __thiscall GRPTypedVariableObject::ConvertToString(GRPTypedVariableObject *this, PStringBase<char> *_String)
{
  GRPTypedVariableObject *v2; // esi@1
  const unsigned int v3; // edx@5
  unsigned int v4; // eax@3
  int v5; // ecx@18
  const unsigned __int16 *v6; // eax@29
  PStringBase<char> result; // [sp+24h] [bp-4h]@29

  v2 = this;
  if ( !this->m_Choices.m_num )
    goto LABEL_13;
  switch ( this->m_Type )
  {
    case 3:
      v4 = GRPTypedVariableObject::GetChoiceIndexForValue(this, *(_DWORD *)this->m_pVariable);
      break;
    case 4:
      v4 = GRPTypedVariableObject::GetChoiceIndexForValue(this, *(_DWORD *)this->m_pVariable);
      break;
    case 5:
      v3 = *(_WORD *)this->m_pVariable;
      goto LABEL_9;
    case 6:
      v4 = GRPTypedVariableObject::GetChoiceIndexForValue(this, *(_WORD *)this->m_pVariable);
      break;
    case 7:
      v4 = GRPTypedVariableObject::GetChoiceIndexForValue(this, *(_BYTE *)this->m_pVariable);
      break;
    case 8:
      v3 = *(_BYTE *)this->m_pVariable;
LABEL_9:
      v4 = GRPTypedVariableObject::GetChoiceIndexForValue(this, v3);
      break;
    default:
      goto LABEL_13;
  }
  if ( v4 == -1 )
    goto LABEL_13;
  if ( v4 < v2->m_Choices.m_num )
  {
    PStringBase<unsigned short>::operator=(
      (PStringBase<unsigned short> *)_String,
      (const unsigned __int16 *)&v2->m_Choices.m_data[v4]);
  }
  else
  {
LABEL_13:
    switch ( v2->m_Type )
    {
      case 1:
        PStringBase<char>::sprintf(_String, "0x%08X", *(_DWORD *)v2->m_pVariable);
        return;
      case 2:
        if ( *(_BYTE *)v2->m_pVariable == 1 )
          PStringBase<char>::set(_String, "True");
        else
          PStringBase<char>::set(_String, "False");
        return;
      case 3:
      case 4:
        v5 = *(_DWORD *)v2->m_pVariable;
        goto LABEL_19;
      case 5:
        v5 = *(_WORD *)v2->m_pVariable;
        goto LABEL_19;
      case 6:
        v5 = *(_WORD *)v2->m_pVariable;
        goto LABEL_19;
      case 7:
        v5 = *(_BYTE *)v2->m_pVariable;
        goto LABEL_19;
      case 8:
        v5 = *(_BYTE *)v2->m_pVariable;
LABEL_19:
        PStringBase<char>::sprintf(_String, "%i", v5);
        break;
      case 9:
        PStringBase<char>::sprintf(_String, "%.2f", *(float *)v2->m_pVariable);
        break;
      case 0xA:
        PStringBase<char>::sprintf(_String, "%.2f", *(double *)v2->m_pVariable);
        break;
      case 0xB:
        PStringBase<char>::sprintf(
          _String,
          "%.2f %.2f %.2f",
          *(float *)v2->m_pVariable,
          *((float *)v2->m_pVariable + 1),
          *((float *)v2->m_pVariable + 2));
        break;
      case 0xC:
        PStringBase<char>::sprintf(
          _String,
          "%.2f %.2f %.2f %.2f",
          *(float *)v2->m_pVariable,
          *((float *)v2->m_pVariable + 1),
          *((float *)v2->m_pVariable + 2),
          *((float *)v2->m_pVariable + 3));
        break;
      case 0xD:
        PStringBase<unsigned short>::operator=(
          (PStringBase<unsigned short> *)_String,
          (const unsigned __int16 *)v2->m_pVariable);
        break;
      case 0xE:
        v6 = (const unsigned __int16 *)Waveform::ToString((Waveform *)v2->m_pVariable, &result);
        PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)_String, v6);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        break;
      default:
        return;
    }
  }
}

//----- (00435830) --------------------------------------------------------  // acclient.c:114861
unsigned int __thiscall GRPTypedVariableObject::GetChoiceIndexForValue(GRPTypedVariableObject *this, const unsigned int _Value)
{
  unsigned int v2; // edx@1
  unsigned int v3; // esi@1
  const unsigned int result; // eax@2
  unsigned int *v5; // ecx@3

  v2 = this->m_ChoiceValues.m_num;
  v3 = this->m_Choices.m_num;
  if ( v2 != v3 )
  {
    result = _Value;
    if ( _Value < v3 )
      return result;
    return -1;
  }
  result = 0;
  if ( !v2 )
    return -1;
  v5 = this->m_ChoiceValues.m_data;
  while ( _Value != *v5 )
  {
    ++result;
    ++v5;
    if ( result >= v2 )
      return -1;
  }
  return result;
}

//----- (00435870) --------------------------------------------------------  // acclient.c:114892
char __thiscall GRPTypedVariableObject::SetFromString(GRPTypedVariableObject *this, PStringBase<char> *_String)
{
  GRPTypedVariableObject *v2; // esi@1
  unsigned int v3; // eax@1
  PStringBase<char> *v4; // ebp@1
  __int32 v5; // ebx@2
  PStringBase<char> v6; // ebp@5
  __int32 v7; // eax@5
  PSRefBufferCharData<char> *v8; // eax@12
  char v9; // bl@18
  void *v10; // ebx@19
  char v11; // al@20
  void *v12; // ebx@21
  void *v13; // ebx@22
  void *v14; // ebx@23
  void *v15; // ebx@24
  void *v16; // ebx@25
  void *v17; // ebx@26
  void *v18; // ebx@27
  void *v19; // edi@28
  int v20; // ecx@29
  int v21; // edx@29
  PStringBase<char> *v22; // esi@36
  int v23; // esi@40
  PStringBase<char> FinalString; // [sp+10h] [bp-10h]@1
  int v26; // [sp+14h] [bp-Ch]@28
  int v27; // [sp+18h] [bp-8h]@28
  int v28; // [sp+1Ch] [bp-4h]@28

  FinalString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v3 = v2->m_Choices.m_num;
  v4 = _String;
  if ( v3 )
  {
    v5 = 0;
    if ( v3 )
    {
      while ( PStringBase<char>::cmp(v4, &v2->m_Choices.m_data[v5], 0) )
      {
        ++v5;
        if ( v5 >= v2->m_Choices.m_num )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      v6.m_charbuffer = v4->m_charbuffer;
      *__errno() = 0;
      v7 = _strtol(v6.m_charbuffer->m_data, 0, 0);
      if ( v7 < 0 || v7 >= (signed int)v2->m_Choices.m_num )
        v5 = 0;
      else
        v5 = v7;
    }
    if ( v2->m_ChoiceValues.m_num == v2->m_Choices.m_num )
      PStringBase<char>::sprintf(&FinalString, "%i", v2->m_ChoiceValues.m_data[v5]);
    else
      PStringBase<char>::sprintf(&FinalString, "%i", v5);
  }
  else
  {
    v8 = FinalString.m_charbuffer;
    if ( FinalString.m_charbuffer == _String->m_charbuffer )
      goto LABEL_18;
    if ( !InterlockedDecrement((volatile LONG *)&FinalString.m_charbuffer[-1])
      && FinalString.m_charbuffer != (PSRefBufferCharData<char> *)20 )
      (**(void (__thiscall ***)(char *, signed int))&FinalString.m_charbuffer[-2].m_data[12])(
        &FinalString.m_charbuffer[-2].m_data[12],
        1);
    FinalString.m_charbuffer = v4->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&FinalString.m_charbuffer[-1]);
  }
  v8 = FinalString.m_charbuffer;
LABEL_18:
  v9 = 0;
  switch ( v2->m_Type )
  {
    case 1:
    case 4:
      v10 = v2->m_pVariable;
      *__errno() = 0;
      *(_DWORD *)v10 = _strtoul(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 2:
      v11 = GRStrings::StringToBool(&FinalString, (bool *)v2->m_pVariable);
      goto LABEL_34;
    case 3:
      v12 = v2->m_pVariable;
      *__errno() = 0;
      *(_DWORD *)v12 = _strtol(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 5:
      v13 = v2->m_pVariable;
      *__errno() = 0;
      *(_WORD *)v13 = _strtol(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 6:
      v14 = v2->m_pVariable;
      *__errno() = 0;
      *(_WORD *)v14 = _strtoul(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 7:
      v15 = v2->m_pVariable;
      *__errno() = 0;
      *(_BYTE *)v15 = _strtol(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 8:
      v16 = v2->m_pVariable;
      *__errno() = 0;
      *(_BYTE *)v16 = _strtoul(v8->m_data, 0, 0);
      v9 = 1;
      goto LABEL_35;
    case 9:
      v17 = v2->m_pVariable;
      *__errno() = 0;
      *(float *)v17 = _strtod(v8->m_data, 0);
      v9 = 1;
      goto LABEL_35;
    case 0xA:
      v18 = v2->m_pVariable;
      *__errno() = 0;
      *(double *)v18 = _strtod(v8->m_data, 0);
      v9 = 1;
      goto LABEL_35;
    case 0xB:
      v19 = v2->m_pVariable;
      if ( _sscanf(v8->m_data, "%f %f %f", &v26, &v27, &v28) == 3 )
      {
        v20 = v27;
        v21 = v28;
        *(_DWORD *)v19 = v26;
        *((_DWORD *)v19 + 1) = v20;
        *((_DWORD *)v19 + 2) = v21;
        v9 = 1;
LABEL_35:
        if ( v2->m_OnChangedCallbackFunction )
        {
          _String = (PStringBase<char> *)v2->m_Name.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&_String[-4]);
          v2->m_OnChangedCallbackFunction((PStringBase<char> *)&_String);
          v22 = _String - 5;
          if ( !InterlockedDecrement((volatile LONG *)&_String[-4]) )
          {
            if ( v22 )
              (*(void (__thiscall **)(PStringBase<char> *, signed int))&v22->m_charbuffer->m_data[0])(v22, 1);
          }
        }
      }
      else
      {
        v9 = 0;
      }
      goto LABEL_39;
    case 0xC:
      v11 = GRStrings::StringToRGBAColor(&FinalString, (RGBAColor *)v2->m_pVariable);
      goto LABEL_34;
    case 0xD:
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)v2->m_pVariable,
        (const unsigned __int16 *)&FinalString);
      v9 = 1;
      goto LABEL_35;
    case 0xE:
      v11 = GRStrings::StringToWaveform(&FinalString, (Waveform *)v2->m_pVariable);
LABEL_34:
      v9 = v11;
      if ( v11 )
        goto LABEL_35;
LABEL_39:
      v8 = FinalString.m_charbuffer;
      break;
    default:
      break;
  }
  v23 = (int)&v8[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v8[-1]) && v23 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v23)(v23, 1);
  return v9;
}

//----- (00435BD0) --------------------------------------------------------  // acclient.c:115081
char __cdecl GRStrings::StringToRGBAColor(PStringBase<char> *_String, RGBAColor *_Value)
{
  int v2; // eax@1
  float v3; // edx@3
  float v4; // ecx@3
  float v5; // edx@3
  RGBAColor Color; // [sp+0h] [bp-10h]@1

  v2 = _sscanf(_String->m_charbuffer->m_data, "%f %f %f %f", &Color, &Color.g, &Color.b, &Color.a);
  if ( v2 == 3 )
  {
    LODWORD(Color.a) = 1065353216;
LABEL_3:
    v3 = Color.g;
    LODWORD(_Value->r) = (_DWORD)Color.r;
    v4 = Color.b;
    _Value->g = v3;
    v5 = Color.a;
    _Value->b = v4;
    _Value->a = v5;
    return 1;
  }
  if ( v2 == 4 )
    goto LABEL_3;
  return 0;
}

//----- (00435C40) --------------------------------------------------------  // acclient.c:115109
char __cdecl GRStrings::StringToWaveform(PStringBase<char> *_String, Waveform *_Value)
{
  PSRefBufferCharData<char> *v2; // esi@1

  v2 = _String->m_charbuffer;
  *__errno() = 0;
  _Value->base = _strtod(v2->m_data, 0);
  _Value->type = 1;
  return 1;
}

//----- (00435C70) --------------------------------------------------------  // acclient.c:115121
char __cdecl GRStrings::StringToBool(PStringBase<char> *_String, bool *_Value)
{
  char v2; // al@2
  char *v3; // esi@2
  char v4; // bl@2
  char v5; // al@6
  char *v6; // esi@6
  char v7; // bl@6
  char v8; // al@10
  char *v9; // esi@10
  char v10; // bl@10
  char *v11; // esi@15
  PStringBase<char> v13; // [sp+10h] [bp-10h]@2
  PStringBase<char> v14; // [sp+14h] [bp-Ch]@6
  PStringBase<char> v15; // [sp+18h] [bp-8h]@10
  PStringBase<char> rhs; // [sp+1Ch] [bp-4h]@1

  PStringBase<char>::PStringBase<char>(&rhs, "False");
  if ( (unsigned __int8)PStringBase<char>::eq(_String, &rhs, 0) )
    goto LABEL_21;
  PStringBase<char>::PStringBase<char>(&v13, "0");
  v2 = PStringBase<char>::eq(_String, &v13, 0);
  v3 = &v13.m_charbuffer[-2].m_data[12];
  v4 = v2;
  if ( !InterlockedDecrement((volatile LONG *)&v13.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  if ( v4 )
    goto LABEL_21;
  PStringBase<char>::PStringBase<char>(&v14, "Off");
  v5 = PStringBase<char>::eq(_String, &v14, 0);
  v6 = &v14.m_charbuffer[-2].m_data[12];
  v7 = v5;
  if ( !InterlockedDecrement((volatile LONG *)&v14.m_charbuffer[-1]) && v6 )
    (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
  if ( v7 )
    goto LABEL_21;
  PStringBase<char>::PStringBase<char>(&v15, "No");
  v8 = PStringBase<char>::eq(_String, &v15, 0);
  v9 = &v15.m_charbuffer[-2].m_data[12];
  v10 = v8;
  if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
  if ( v10 )
LABEL_21:
    v10 = 1;
  v11 = &rhs.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v11 )
    (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
  *_Value = v10 == 0;
  return 1;
}

//----- (00435DA0) --------------------------------------------------------  // acclient.c:115174
void __thiscall GRPTypedVariableObject::~GRPTypedVariableObject(GRPTypedVariableObject *this)
{
  GRPTypedVariableObject *v1; // esi@1
  PStringBase<char> *v2; // ecx@1
  int v3; // edi@3
  int v4; // esi@6

  v1 = this;
  operator delete[](this->m_ChoiceValues.m_data);
  v1->m_ChoiceValues.m_data = 0;
  v1->m_ChoiceValues.m_num = 0;
  v2 = v1->m_Choices.m_data;
  if ( v2 )
    PStringBase<unsigned short>::vector_deleting_destructor(v2, 3u);
  v1->m_Choices.m_data = 0;
  v1->m_Choices.m_num = 0;
  v3 = (int)&v1->m_Description.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  v4 = (int)&v1->m_Name.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00435E20) --------------------------------------------------------  // acclient.c:115202
void __cdecl GlobalRegistry::RegisterConsoleCallbackObject(IConsoleCallbackObject *io_pConsoleCallbackObject)
{
  GlobalRegistryInstance *v1; // eax@1
  GlobalRegistryInstance *v2; // eax@2
  unsigned int v3; // ecx@6
  int v4; // esi@6
  int v5; // eax@6
  unsigned int v6; // eax@7

  v1 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v2 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v2 )
      GlobalRegistryInstance::GlobalRegistryInstance(v2);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  v3 = v1->m_ConsoleCallbackObjects.m_num;
  v4 = (int)&v1->m_ConsoleCallbackObjects;
  v5 = v1->m_ConsoleCallbackObjects.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v3 < v5
    || (v6 = SmartArray<UIChildFramework *,1>::get_new_size(v5 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v4, v6)) )
    *(_DWORD *)(*(_DWORD *)v4 + 4 * (*(_DWORD *)(v4 + 8))++) = io_pConsoleCallbackObject;
}

//----- (00435E90) --------------------------------------------------------  // acclient.c:115231
void __cdecl GlobalRegistry::ProcessCommand(PStringBase<char> *_Command)
{
  PStringBase<char> *v1; // esi@1
  PSRefBufferCharData<char> *v2; // ecx@1
  signed int v3; // ebp@1
  char *v4; // esi@2
  bool v5; // zf@6
  ListNode<PStringBase<char> > *v6; // edi@7
  char *v7; // esi@11
  int v8; // edx@13
  GlobalRegistryInstance *v9; // eax@17
  GlobalRegistryInstance *v10; // eax@18
  int v11; // esi@23
  int v12; // eax@23
  int v13; // edi@23
  char *v14; // esi@28
  int v15; // eax@30
  char *v16; // esi@36
  int v17; // eax@38
  PStringBase<char> *v18; // esi@39
  char *v19; // esi@49
  int v20; // edx@51
  int v21; // edx@55
  PSRefBufferCharData<char> *v22; // [sp-4h] [bp-40h]@1
  PStringBase<char> CommandString; // [sp+10h] [bp-2Ch]@7
  GRPCommand *pFoundCommand; // [sp+14h] [bp-28h]@22
  PStringBase<char> TrimmedCommand; // [sp+18h] [bp-24h]@1
  PStringBase<char> _Text; // [sp+1Ch] [bp-20h]@28
  PStringBaseArray<char> CommandArgs; // [sp+20h] [bp-1Ch]@7
  List<PStringBase<char> > Args; // [sp+2Ch] [bp-10h]@1

  v1 = _Command;
  TrimmedCommand.m_charbuffer = _Command->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&TrimmedCommand.m_charbuffer[-1]);
  v22 = v2;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v22, " ");
  PStringBase<char>::trim(&TrimmedCommand, 1, 1, (PStringBase<char>)v22);
  v3 = 0;
  Args.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  Args._head = 0;
  Args._tail = 0;
  Args._num_elements = 0;
  if ( !PSUtils::explode(v1, 32, &Args) )
  {
    Args.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&Args);
    v4 = &TrimmedCommand.m_charbuffer[-2].m_data[12];
    v22 = TrimmedCommand.m_charbuffer - 1;
    goto LABEL_5;
  }
  if ( Args._num_elements < 1 )
  {
    Args.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&Args);
    v4 = &TrimmedCommand.m_charbuffer[-2].m_data[12];
    v22 = TrimmedCommand.m_charbuffer - 1;
LABEL_5:
    if ( !InterlockedDecrement((volatile LONG *)v22) )
    {
      v5 = v4 == 0;
LABEL_54:
      if ( !v5 )
      {
        v21 = *(_DWORD *)v4;
        v22 = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v21)(v4, 1);
      }
    }
    return;
  }
  CommandString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v6 = Args._head;
  CommandArgs.m_data = 0;
  CommandArgs.m_sizeAndDeallocate = 0;
  CommandArgs.m_num = 0;
  while ( v6 )
  {
    if ( v3 )
    {
      SmartArray<PStringBase<char>,1>::AddToEnd((SmartArray<PStringBase<char>,1> *)&CommandArgs.m_data, &v6->data);
LABEL_16:
      v6 = v6->next;
      ++v3;
    }
    else
    {
      if ( CommandString.m_charbuffer == v6->data.m_charbuffer )
        goto LABEL_16;
      v7 = &CommandString.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&CommandString.m_charbuffer[-1]) && v7 )
      {
        v8 = *(_DWORD *)v7;
        v22 = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v8)(v7, 1);
      }
      CommandString.m_charbuffer = v6->data.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&CommandString.m_charbuffer[-1]);
      v6 = v6->next;
      v3 = 1;
    }
  }
  v9 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v10 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v10 )
      GlobalRegistryInstance::GlobalRegistryInstance(v10);
    else
      v9 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v9;
  }
  if ( GlobalRegistryInstance::FindCommandByName(v9, &CommandString, &pFoundCommand) )
  {
    v11 = ((int (*)(void))pFoundCommand->vfptr->AsNoArgsCommand)();
    v12 = ((int (*)(void))pFoundCommand->vfptr->AsWithArgsCommand)();
    v13 = v12;
    if ( v11 )
    {
      if ( (unsigned __int8)(*(int (**)(void))(v11 + 12))() )
        goto LABEL_46;
LABEL_28:
      PStringBase<char>::PStringBase<char>(&_Text, "Command failed.\n\n");
      GlobalRegistry::OutputText(&_Text);
      v14 = &_Text.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v14 )
      {
        v15 = *(_DWORD *)v14;
        v22 = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v15)(v14, 1);
      }
      _Command = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
      v22 = pFoundCommand->m_Name.m_charbuffer;
      PStringBase<char>::sprintf((PStringBase<char> *)&_Command, "         Name: %s\n", v22);
      GlobalRegistry::OutputText((PStringBase<char> *)&_Command);
      if ( *(_DWORD *)&pFoundCommand->m_Description.m_charbuffer[-1].m_data[12] != 1 )
      {
        v22 = pFoundCommand->m_Description.m_charbuffer;
        PStringBase<char>::sprintf((PStringBase<char> *)&_Command, "  Description: %s\n", v22);
        GlobalRegistry::OutputText((PStringBase<char> *)&_Command);
      }
      if ( v13 && *(_DWORD *)(*(_DWORD *)(v13 + 12) - 4) != 1 )
      {
        v22 = *(PSRefBufferCharData<char> **)(v13 + 12);
        PStringBase<char>::sprintf((PStringBase<char> *)&_Command, "        Usage: %s\n", v22);
        GlobalRegistry::OutputText((PStringBase<char> *)&_Command);
      }
      PStringBase<char>::PStringBase<char>(&_Text, "\n");
      GlobalRegistry::OutputText(&_Text);
      v16 = &_Text.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&_Text.m_charbuffer[-1]) && v16 )
      {
        v17 = *(_DWORD *)v16;
        v22 = (PSRefBufferCharData<char> *)1;
        (*(void (__thiscall **)(char *, signed int))v17)(v16, 1);
      }
      v18 = _Command - 5;
      if ( !InterlockedDecrement((volatile LONG *)&_Command[-4]) && v18 )
      {
        v22 = (PSRefBufferCharData<char> *)1;
        goto LABEL_45;
      }
    }
    else
    {
      if ( !v12 )
        goto LABEL_28;
      v22 = (PSRefBufferCharData<char> *)&CommandArgs;
      if ( !(unsigned __int8)(*(int (__cdecl **)(PStringBaseArray<char> *))(v12 + 16))(&CommandArgs) )
        goto LABEL_28;
    }
  }
  else
  {
    _Command = (PStringBase<char> *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v22 = CommandString.m_charbuffer;
    PStringBase<char>::sprintf(
      (PStringBase<char> *)&_Command,
      "Unrecognized command: %s\n\n",
      CommandString.m_charbuffer);
    GlobalRegistry::OutputText((PStringBase<char> *)&_Command);
    v18 = _Command - 5;
    if ( !InterlockedDecrement((volatile LONG *)&_Command[-4]) && v18 )
    {
      v22 = (PSRefBufferCharData<char> *)1;
LABEL_45:
      (*(void (__thiscall **)(PStringBase<char> *, PSRefBufferCharData<char> *))&v18->m_charbuffer->m_data[0])(v18, v22);
    }
  }
LABEL_46:
  if ( (CommandArgs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 && (_DWORD)CommandArgs.m_data )
    PStringBase<unsigned short>::vector_deleting_destructor(CommandArgs.m_data, 3u);
  v19 = &CommandString.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CommandString.m_charbuffer[-1]) && v19 )
  {
    v20 = *(_DWORD *)v19;
    v22 = (PSRefBufferCharData<char> *)1;
    (*(void (__thiscall **)(char *, signed int))v20)(v19, 1);
  }
  Args.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(&Args);
  v4 = &TrimmedCommand.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrimmedCommand.m_charbuffer[-1]) )
  {
    v5 = v4 == 0;
    goto LABEL_54;
  }
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (00436220) --------------------------------------------------------  // acclient.c:115444
char __thiscall HashTable<PStringBase<char>,GRPCommand *,0>::remove(HashTable<PStringBase<char>,GRPObject *,0> *this, PStringBase<char> *_key, GRPObject **_retval)
{
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v3; // eax@1
  void *v4; // edi@1
  int v5; // esi@2
  char result; // al@5

  v3 = IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::remove(
         (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable,
         _key);
  v4 = v3;
  if ( v3 )
  {
    *_retval = (GRPObject *)v3->m_data;
    v5 = (int)&v3->m_hashKey.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
    {
      if ( v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    }
    operator delete(v4);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00436280) --------------------------------------------------------  // acclient.c:115475
void __cdecl GlobalRegistry::RegisterCommand(bool (__cdecl *_FunctionPointer)(), PStringBase<char> *_Name, PStringBase<char> *_Description)
{
  const unsigned __int16 *v3; // edi@1
  char *v4; // eax@1
  int v5; // eax@2
  bool v6; // bl@4
  char *v7; // esi@4
  GlobalRegistryInstance *v8; // eax@9
  GlobalRegistryInstance *v9; // eax@10
  GRPNoArgsCommand *v10; // eax@15
  int v11; // eax@16
  int v12; // esi@16
  int v13; // eax@18
  PStringBase<char> LowerCaseName; // [sp+Ch] [bp-Ch]@18
  PStringBase<char> v15; // [sp+10h] [bp-8h]@1
  GRPCommand *pFoundCommand; // [sp+14h] [bp-4h]@14

  PStringBase<char>::PStringBase<char>(&v15, " ");
  v3 = (const unsigned __int16 *)_Name;
  v4 = _strstr(_Name->m_charbuffer->m_data, v15.m_charbuffer->m_data);
  if ( v4 )
    v5 = (int)&v4[-*(_DWORD *)v3];
  else
    v5 = -1;
  v6 = v5 == -1;
  v7 = &v15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  if ( v6 && _FunctionPointer )
  {
    v8 = GlobalRegistry::s_pcGlobalRegistry;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v9 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v9 )
        GlobalRegistryInstance::GlobalRegistryInstance(v9);
      else
        v8 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v8;
    }
    if ( !GlobalRegistryInstance::FindCommandByName(v8, (PStringBase<char> *)v3, &pFoundCommand) )
    {
      v10 = (GRPNoArgsCommand *)operator new(0x10u);
      if ( v10 )
      {
        GRPNoArgsCommand::GRPNoArgsCommand(v10);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v12 + 4), v3);
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)(v12 + 8),
        (const unsigned __int16 *)_Description);
      *(_DWORD *)(v12 + 12) = _FunctionPointer;
      LowerCaseName.m_charbuffer = *(PSRefBufferCharData<char> **)v3;
      InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
      PStringBase<char>::break_reference(&LowerCaseName);
      __strlwr(LowerCaseName.m_charbuffer->m_data);
      _Name = (PStringBase<char> *)v12;
      GlobalRegistry::GetRegistry();
      if ( !HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
              (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)(v13 + 32780),
              &LowerCaseName,
              (UIPreferenceItem *const *)&_Name) )
        GRPNoArgsCommand::scalar_deleting_destructor((GRPNoArgsCommand *)v12, 1u);
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&LowerCaseName);
    }
  }
}

//----- (004363D0) --------------------------------------------------------  // acclient.c:115549
void __cdecl GlobalRegistry::RegisterCommand(bool (__cdecl *_FunctionPointer)(PStringBaseArray<char> *), PStringBase<char> *_Name, PStringBase<char> *_Description, PStringBase<char> *_Usage)
{
  const unsigned __int16 *v4; // edi@1
  char *v5; // eax@1
  int v6; // eax@2
  bool v7; // bl@4
  char *v8; // esi@4
  GlobalRegistryInstance *v9; // eax@9
  GlobalRegistryInstance *v10; // eax@10
  GRPWithArgsCommand *v11; // eax@15
  int v12; // eax@16
  int v13; // esi@16
  PStringBase<char> *v14; // ST04_4@18
  int v15; // eax@18
  PStringBase<char> LowerCaseName; // [sp+Ch] [bp-Ch]@18
  PStringBase<char> v17; // [sp+10h] [bp-8h]@1
  GRPCommand *pFoundCommand; // [sp+14h] [bp-4h]@14

  PStringBase<char>::PStringBase<char>(&v17, " ");
  v4 = (const unsigned __int16 *)_Name;
  v5 = _strstr(_Name->m_charbuffer->m_data, v17.m_charbuffer->m_data);
  if ( v5 )
    v6 = (int)&v5[-*(_DWORD *)v4];
  else
    v6 = -1;
  v7 = v6 == -1;
  v8 = &v17.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&v17.m_charbuffer[-1]) && v8 )
    (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
  if ( v7 && _FunctionPointer )
  {
    v9 = GlobalRegistry::s_pcGlobalRegistry;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v10 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v10 )
        GlobalRegistryInstance::GlobalRegistryInstance(v10);
      else
        v9 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v9;
    }
    if ( !GlobalRegistryInstance::FindCommandByName(v9, (PStringBase<char> *)v4, &pFoundCommand) )
    {
      v11 = (GRPWithArgsCommand *)operator new(0x14u);
      if ( v11 )
      {
        GRPWithArgsCommand::GRPWithArgsCommand(v11);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v13 + 4), v4);
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)(v13 + 8),
        (const unsigned __int16 *)_Description);
      v14 = _Usage;
      *(_DWORD *)(v13 + 16) = _FunctionPointer;
      PStringBase<unsigned short>::operator=((PStringBase<unsigned short> *)(v13 + 12), (const unsigned __int16 *)v14);
      LowerCaseName.m_charbuffer = *(PSRefBufferCharData<char> **)v4;
      InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
      PStringBase<char>::break_reference(&LowerCaseName);
      __strlwr(LowerCaseName.m_charbuffer->m_data);
      _Name = (PStringBase<char> *)v13;
      GlobalRegistry::GetRegistry();
      if ( !HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
              (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)(v15 + 32780),
              &LowerCaseName,
              (UIPreferenceItem *const *)&_Name) )
      {
        GRPWithArgsCommand::~GRPWithArgsCommand((GRPShadowVariableObject *)v13);
        operator delete((void *)v13);
      }
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&LowerCaseName);
    }
  }
}

//----- (00436530) --------------------------------------------------------  // acclient.c:115629
void __cdecl GlobalRegistry::UnregisterCommand(PStringBase<char> *_Name)
{
  GlobalRegistryInstance *v1; // eax@1
  GlobalRegistryInstance *v2; // eax@2
  GlobalRegistryInstance *v3; // eax@7
  GlobalRegistryInstance *v4; // eax@8
  GRPCommand *v5; // ebx@12
  char *v6; // esi@13
  int v7; // esi@16
  char *v8; // esi@20
  GlobalRegistryInstance *v9; // esi@25
  PStringBase<char> LowerCaseName; // [sp+8h] [bp-Ch]@7
  GRPCommand *pFoundCommand; // [sp+Ch] [bp-8h]@6
  GRPCommand *pRemovedCommand; // [sp+10h] [bp-4h]@12

  v1 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v2 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v2 )
      GlobalRegistryInstance::GlobalRegistryInstance(v2);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  if ( GlobalRegistryInstance::FindCommandByName(v1, _Name, &pFoundCommand) )
  {
    LowerCaseName.m_charbuffer = _Name->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
    PStringBase<char>::break_reference(&LowerCaseName);
    __strlwr(LowerCaseName.m_charbuffer->m_data);
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
    HashTable<PStringBase<char>,GRPCommand *,0>::remove(
      (HashTable<PStringBase<char>,GRPObject *,0> *)&v3->m_CommandHash,
      &LowerCaseName,
      (GRPObject **)&pRemovedCommand);
    v5 = pFoundCommand;
    if ( pFoundCommand )
    {
      v6 = &pFoundCommand->m_Description.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)v6 + 1) && v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
      v7 = (int)&v5->m_Name.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
      operator delete(v5);
    }
    v8 = &LowerCaseName.m_charbuffer[-2].m_data[12];
    pFoundCommand = 0;
    if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
  }
  if ( GlobalRegistry::s_pcGlobalRegistry && GlobalRegistryInstance::IsEmpty(GlobalRegistry::s_pcGlobalRegistry) )
  {
    v9 = GlobalRegistry::s_pcGlobalRegistry;
    if ( GlobalRegistry::s_pcGlobalRegistry )
    {
      GlobalRegistryInstance::~GlobalRegistryInstance(GlobalRegistry::s_pcGlobalRegistry);
      operator delete(v9);
    }
    GlobalRegistry::s_pcGlobalRegistry = 0;
  }
}

//----- (004366A0) --------------------------------------------------------  // acclient.c:115703
void __cdecl GlobalRegistry::RegisterVariableInternal(void *_pVariable, GRVDataType _Type, PStringBase<char> *_Name, PStringBase<char> *_Description, void (__cdecl *_OnChangedCallbackFP)(PStringBase<char> *), const unsigned int _NumChoices, PStringBase<char> *_pChoiceStrings, const unsigned int *_pChoiceValues)
{
  unsigned int v8; // ebp@1
  PSRefBufferCharData<char> **v9; // edi@3
  char *v10; // eax@3
  unsigned int v11; // eax@4
  bool v12; // bl@6
  const unsigned int v13; // esi@6
  GlobalRegistryInstance *v14; // eax@12
  GRPShadowVariableObject *v15; // ebx@12
  GRPTypedVariableObject *v16; // eax@14
  int v17; // eax@15
  int v18; // esi@15
  unsigned int v19; // edi@18
  const unsigned int *v20; // edi@20
  unsigned int v21; // eax@21
  GlobalRegistryInstance *v22; // eax@25
  GlobalRegistryInstance *v23; // eax@26
  char *v24; // ebx@30
  GlobalRegistryInstance *v25; // eax@33
  GlobalRegistryInstance *v26; // eax@34
  char *v27; // esi@39
  char *v28; // esi@42
  char *v29; // esi@45
  LONG v30; // eax@42
  PStringBase<char> LowerCaseName; // [sp+10h] [bp-14h]@33
  PStringBase<char> _key; // [sp+14h] [bp-10h]@25
  PStringBase<char> ShadowValueString; // [sp+18h] [bp-Ch]@24
  GRPObject *pFoundObject; // [sp+1Ch] [bp-8h]@12
  GRPObject *pRemovedObject; // [sp+20h] [bp-4h]@30

  v8 = _NumChoices;
  if ( !_NumChoices || _pChoiceStrings )
  {
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_NumChoices, " ");
    v9 = (PSRefBufferCharData<char> **)_Name;
    v10 = _strstr(_Name->m_charbuffer->m_data, (const char *)_NumChoices);
    if ( v10 )
      v11 = v10 - (char *)_Name->m_charbuffer;
    else
      v11 = -1;
    v12 = v11 == -1;
    v13 = _NumChoices - 20;
    if ( !InterlockedDecrement((volatile LONG *)(_NumChoices - 20 + 4)) && v13 )
      (**(void (__thiscall ***)(const unsigned int, signed int))v13)(v13, 1);
    if ( v12 )
    {
      if ( _pVariable )
      {
        if ( _Type )
        {
          GlobalRegistry::GetRegistry();
          v15 = 0;
          if ( !GlobalRegistryInstance::FindObjectByName(v14, _Name, &pFoundObject)
            || (v15 = (GRPShadowVariableObject *)((int (*)(void))pFoundObject->vfptr->AsShadowVariableObject)()) != 0 )
          {
            v16 = (GRPTypedVariableObject *)operator new(0x2Cu);
            if ( v16 )
            {
              GRPTypedVariableObject::GRPTypedVariableObject(v16);
              v18 = v17;
            }
            else
            {
              v18 = 0;
            }
            PStringBase<unsigned short>::operator=(
              (PStringBase<unsigned short> *)(v18 + 4),
              (const unsigned __int16 *)_Name);
            PStringBase<unsigned short>::operator=(
              (PStringBase<unsigned short> *)(v18 + 8),
              (const unsigned __int16 *)_Description);
            *(_DWORD *)(v18 + 12) = _pVariable;
            *(_DWORD *)(v18 + 16) = _Type;
            *(_DWORD *)(v18 + 20) = _OnChangedCallbackFP;
            *(_BYTE *)(v18 + 40) = 0;
            if ( v8 )
            {
              FixedArray<PStringBase<char>>::Create((FixedArray<PStringBase<char> > *)(v18 + 24), v8);
              v19 = 0;
              if ( v8 )
              {
                do
                {
                  PStringBase<unsigned short>::operator=(
                    (PStringBase<unsigned short> *)(4 * v19 + *(_DWORD *)(v18 + 24)),
                    (const unsigned __int16 *)&_pChoiceStrings[v19]);
                  ++v19;
                }
                while ( v19 < v8 );
              }
              v20 = _pChoiceValues;
              if ( _pChoiceValues )
              {
                *(_DWORD *)(v18 + 36) = v8;
                *(_DWORD *)(v18 + 32) = operator new[](4 * v8);
                v21 = 0;
                if ( v8 )
                {
                  do
                  {
                    *(_DWORD *)(*(_DWORD *)(v18 + 32) + 4 * v21) = v20[v21];
                    ++v21;
                  }
                  while ( v21 < v8 );
                }
              }
              v9 = (PSRefBufferCharData<char> **)_Name;
            }
            ShadowValueString.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
            LOBYTE(_NumChoices) = 0;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            if ( v15 )
            {
              *(_BYTE *)(v18 + 40) = 1;
              ((void (__thiscall *)(GRPShadowVariableObject *, PStringBase<char> *))v15->vfptr[1].AsGeneric)(
                v15,
                &ShadowValueString);
              _key.m_charbuffer = *v9;
              LOBYTE(_NumChoices) = 1;
              InterlockedIncrement((volatile LONG *)&_key.m_charbuffer[-1]);
              PStringBase<char>::break_reference(&_key);
              __strlwr(_key.m_charbuffer->m_data);
              v22 = GlobalRegistry::s_pcGlobalRegistry;
              if ( !GlobalRegistry::s_pcGlobalRegistry )
              {
                v23 = (GlobalRegistryInstance *)operator new(0x8100u);
                if ( v23 )
                  GlobalRegistryInstance::GlobalRegistryInstance(v23);
                else
                  v22 = 0;
                GlobalRegistry::s_pcGlobalRegistry = v22;
              }
              HashTable<PStringBase<char>,GRPCommand *,0>::remove(&v22->m_ObjectHash, &_key, &pRemovedObject);
              GRPWithArgsCommand::~GRPWithArgsCommand(v15);
              operator delete(v15);
              v24 = &_key.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&_key.m_charbuffer[-1]) && v24 )
                (**(void (__thiscall ***)(char *, signed int))v24)(v24, 1);
            }
            LowerCaseName.m_charbuffer = *v9;
            InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
            PStringBase<char>::break_reference(&LowerCaseName);
            __strlwr(LowerCaseName.m_charbuffer->m_data);
            v25 = GlobalRegistry::s_pcGlobalRegistry;
            _key.m_charbuffer = (PSRefBufferCharData<char> *)v18;
            if ( !GlobalRegistry::s_pcGlobalRegistry )
            {
              v26 = (GlobalRegistryInstance *)operator new(0x8100u);
              if ( v26 )
                GlobalRegistryInstance::GlobalRegistryInstance(v26);
              else
                v25 = 0;
              GlobalRegistry::s_pcGlobalRegistry = v25;
            }
            if ( HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
                   (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)&v25->m_ObjectHash,
                   &LowerCaseName,
                   (UIPreferenceItem *const *)&_key) )
            {
              if ( (_BYTE)_NumChoices )
                (*(void (__thiscall **)(int, PStringBase<char> *))(*(_DWORD *)v18 + 80))(v18, &ShadowValueString);
              v29 = &LowerCaseName.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v29 )
                (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
              v28 = &ShadowValueString.m_charbuffer[-2].m_data[12];
              v30 = InterlockedDecrement((volatile LONG *)&ShadowValueString.m_charbuffer[-1]);
            }
            else
            {
              GRPTypedVariableObject::~GRPTypedVariableObject((GRPTypedVariableObject *)v18);
              operator delete((void *)v18);
              v27 = &LowerCaseName.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v27 )
                (**(void (__thiscall ***)(char *, signed int))v27)(v27, 1);
              v28 = &ShadowValueString.m_charbuffer[-2].m_data[12];
              v30 = InterlockedDecrement((volatile LONG *)&ShadowValueString.m_charbuffer[-1]);
            }
            if ( !v30 )
            {
              if ( v28 )
                (**(void (__thiscall ***)(char *, signed int))v28)(v28, 1);
            }
          }
        }
      }
    }
  }
}

//----- (004369F0) --------------------------------------------------------  // acclient.c:115894
void __cdecl GlobalRegistry::UnregisterVariable(PStringBase<char> *_Name)
{
  GlobalRegistryInstance *v1; // eax@1
  GlobalRegistryInstance *v2; // eax@2
  GRPTypedVariableObject *v3; // esi@7
  int v4; // edi@8
  GRPShadowVariableObject *v5; // eax@9
  int v6; // eax@10
  GlobalRegistryInstance *v7; // eax@13
  GlobalRegistryInstance *v8; // eax@14
  int v9; // eax@19
  char *v10; // esi@21
  GlobalRegistryInstance *v11; // esi@26
  PStringBase<char> LowerCaseName; // [sp+4h] [bp-Ch]@13
  GRPObject *pFoundObject; // [sp+8h] [bp-8h]@6
  GRPObject *pRemovedObject; // [sp+Ch] [bp-4h]@18

  v1 = GlobalRegistry::s_pcGlobalRegistry;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v2 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v2 )
      GlobalRegistryInstance::GlobalRegistryInstance(v2);
    else
      v1 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v1;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v1, _Name, &pFoundObject) )
  {
    v3 = (GRPTypedVariableObject *)((int (*)(void))pFoundObject->vfptr->AsTypedVariableObject)();
    if ( !v3 )
      return;
    v4 = 0;
    if ( (unsigned __int8)(*(int (__thiscall **)(GRPTypedVariableObject *))&v3->vfptr[1].gap0[0])(v3) )
    {
      v5 = (GRPShadowVariableObject *)operator new(0x10u);
      if ( v5 )
      {
        GRPShadowVariableObject::GRPShadowVariableObject(v5);
        v4 = v6;
      }
      else
      {
        v4 = 0;
      }
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)(v4 + 4),
        (const unsigned __int16 *)&v3->m_Name);
      PStringBase<unsigned short>::operator=(
        (PStringBase<unsigned short> *)(v4 + 8),
        (const unsigned __int16 *)&v3->m_Description);
      ((void (__thiscall *)(GRPTypedVariableObject *, int))v3->vfptr[1].AsGeneric)(v3, v4 + 12);
    }
    LowerCaseName.m_charbuffer = _Name->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
    PStringBase<char>::break_reference(&LowerCaseName);
    __strlwr(LowerCaseName.m_charbuffer->m_data);
    v7 = GlobalRegistry::s_pcGlobalRegistry;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v8 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v8 )
        GlobalRegistryInstance::GlobalRegistryInstance(v8);
      else
        v7 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v7;
    }
    HashTable<PStringBase<char>,GRPCommand *,0>::remove(&v7->m_ObjectHash, &LowerCaseName, &pRemovedObject);
    GRPTypedVariableObject::~GRPTypedVariableObject(v3);
    operator delete(v3);
    if ( v4 )
    {
      pRemovedObject = (GRPObject *)v4;
      GlobalRegistry::GetRegistry();
      if ( !HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
              (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)(v9 + 32896),
              &LowerCaseName,
              (UIPreferenceItem *const *)&pRemovedObject) )
      {
        GRPWithArgsCommand::~GRPWithArgsCommand((GRPShadowVariableObject *)v4);
        operator delete((void *)v4);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&LowerCaseName);
        return;
      }
    }
    v10 = &LowerCaseName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v10 )
      (**(void (__thiscall ***)(char *, signed int))v10)(v10, 1);
  }
  if ( GlobalRegistry::s_pcGlobalRegistry && GlobalRegistryInstance::IsEmpty(GlobalRegistry::s_pcGlobalRegistry) )
  {
    v11 = GlobalRegistry::s_pcGlobalRegistry;
    if ( GlobalRegistry::s_pcGlobalRegistry )
    {
      GlobalRegistryInstance::~GlobalRegistryInstance(GlobalRegistry::s_pcGlobalRegistry);
      operator delete(v11);
    }
    GlobalRegistry::s_pcGlobalRegistry = 0;
  }
}

//----- (00436BC0) --------------------------------------------------------  // acclient.c:115996
void __usercall GlobalRegistry::SetGlobalVariable(int a1@<edi>, PStringBase<char> *_Name, PStringBase<char> *_ValueString)
{
  GlobalRegistryInstance *v3; // eax@1
  GlobalRegistryInstance *v4; // eax@2
  int v5; // esi@8
  int v6; // edi@8
  GRPShadowVariableObject *v7; // eax@12
  UIPreferenceItem *v8; // eax@13
  UIPreferenceItem *v9; // esi@13
  PSRefBufferCharData<char> *v10; // eax@15
  int v11; // edi@16
  PSRefBufferCharData<char> *v12; // eax@19
  PSRefBufferCharData<char> *v13; // eax@20
  int v14; // edi@21
  volatile LONG *v15; // ST00_4@24
  GlobalRegistryInstance *v16; // eax@25
  GlobalRegistryInstance *v17; // eax@26
  char *v18; // esi@31
  char *v19; // esi@34
  PStringBase<char> LowerCaseName; // [sp+Ch] [bp-Ch]@25
  GRPObject *pFoundObject; // [sp+10h] [bp-8h]@6
  UIPreferenceItem *_data; // [sp+14h] [bp-4h]@25

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
  if ( GlobalRegistryInstance::FindObjectByName(v3, _Name, &pFoundObject)
    && ((int (*)(void))pFoundObject->vfptr->AsVariableObject)() )
  {
    v5 = ((int (__stdcall *)(int))pFoundObject->vfptr->AsVariableObject)(a1);
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 68))(v5);
    if ( v6 )
    {
      if ( !(unsigned __int8)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 72))(v6) )
        *(_BYTE *)(v6 + 40) = 1;
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 80))(v5);
  }
  else
  {
    v7 = (GRPShadowVariableObject *)operator new(0x10u);
    if ( v7 )
    {
      GRPShadowVariableObject::GRPShadowVariableObject(v7);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    v10 = v9->m_strPreference.m_charbuffer;
    if ( v10 != _Name->m_charbuffer )
    {
      v11 = (int)&v10[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
      v12 = _Name->m_charbuffer;
      v9->m_strPreference.m_charbuffer = _Name->m_charbuffer;
      InterlockedIncrement((volatile LONG *)&v12[-1]);
    }
    v13 = (PSRefBufferCharData<char> *)v9->m_dataType;
    if ( v13 != PStringBase<char>::s_NullBuffer.m_charbuffer )
    {
      v14 = (int)&v13[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&v13[-1]) && v14 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v14)(v14, 1);
      v15 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      v9->m_dataType = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v15);
    }
    v9->vfptr->InqCachedInteger(v9, (int *)_ValueString);
    LowerCaseName.m_charbuffer = _Name->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]);
    PStringBase<char>::break_reference(&LowerCaseName);
    __strlwr(LowerCaseName.m_charbuffer->m_data);
    v16 = GlobalRegistry::s_pcGlobalRegistry;
    _data = v9;
    if ( !GlobalRegistry::s_pcGlobalRegistry )
    {
      v17 = (GlobalRegistryInstance *)operator new(0x8100u);
      if ( v17 )
        GlobalRegistryInstance::GlobalRegistryInstance(v17);
      else
        v16 = 0;
      GlobalRegistry::s_pcGlobalRegistry = v16;
    }
    if ( HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
           (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)&v16->m_ObjectHash,
           &LowerCaseName,
           &_data) )
    {
      v19 = &LowerCaseName.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v19 )
        (**(void (__thiscall ***)(char *, signed int))v19)(v19, 1);
    }
    else
    {
      GRPWithArgsCommand::~GRPWithArgsCommand((GRPShadowVariableObject *)v9);
      operator delete(v9);
      v18 = &LowerCaseName.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)&LowerCaseName.m_charbuffer[-1]) && v18 )
        (**(void (__thiscall ***)(char *, signed int))v18)(v18, 1);
    }
  }
}
// 436BC0: could not find valid save-restore pair for edi

//----- (006C5D90) --------------------------------------------------------  // acclient.c:734150
int _E73_27()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_5, "None");
  return atexit(_E74_29);
}

//----- (006C5DB0) --------------------------------------------------------  // acclient.c:734157
int _E76_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_5, "Speed");
  return atexit(_E77_45);
}

//----- (006C5DD0) --------------------------------------------------------  // acclient.c:734164
int _E79_17()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_5, "Noise");
  return atexit(_E80_19);
}

//----- (006C5DF0) --------------------------------------------------------  // acclient.c:734171
int _E82_8()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_5, "Sine");
  return atexit(_E83_9);
}

//----- (006C5E10) --------------------------------------------------------  // acclient.c:734178
int _E85_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_5, "Square");
  return atexit(_E86_6);
}

//----- (006C5E30) --------------------------------------------------------  // acclient.c:734185
int _E88_4()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_5, "Bounce");
  return atexit(_E89_17);
}

//----- (006C5E50) --------------------------------------------------------  // acclient.c:734192
int _E91_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_5, "Perlin");
  return atexit(_E92_15);
}

//----- (006C5E70) --------------------------------------------------------  // acclient.c:734199
int _E94_5()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_5, "Fractal");
  return atexit(sub_728BC0);
}

//----- (006C5E90) --------------------------------------------------------  // acclient.c:734206
int _E97_7()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_5, "FrameLoop");
  return atexit(_E98_30);
}

//----- (006C5EB0) --------------------------------------------------------  // acclient.c:734213
int _E100_9()
{
  return atexit(_E101_58);
}

//----- (00728A70) --------------------------------------------------------  // acclient.c:826528
void __cdecl _E74_29()
{
  char *v0; // esi@1

  v0 = &waveform_None_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728AA0) --------------------------------------------------------  // acclient.c:826541
void __cdecl _E77_45()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728AD0) --------------------------------------------------------  // acclient.c:826554
void __cdecl _E80_19()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728B00) --------------------------------------------------------  // acclient.c:826567
void __cdecl _E83_9()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728B30) --------------------------------------------------------  // acclient.c:826580
void __cdecl _E86_6()
{
  char *v0; // esi@1

  v0 = &waveform_Square_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728B60) --------------------------------------------------------  // acclient.c:826593
void __cdecl _E89_17()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728B90) --------------------------------------------------------  // acclient.c:826606
void __cdecl _E92_15()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728BC0) --------------------------------------------------------  // acclient.c:826619
void __cdecl sub_728BC0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728BF0) --------------------------------------------------------  // acclient.c:826632
void __cdecl _E98_30()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00728C20) --------------------------------------------------------  // acclient.c:826645
void __cdecl _E101_58()
{
  GlobalRegistryInstance *v0; // esi@4

  if ( GlobalRegistry::s_pcGlobalRegistry )
  {
    GlobalRegistryInstance::CheckForLeakedData(GlobalRegistry::s_pcGlobalRegistry);
    if ( GlobalRegistry::s_pcGlobalRegistry )
    {
      if ( GlobalRegistryInstance::IsEmpty(GlobalRegistry::s_pcGlobalRegistry) )
      {
        v0 = GlobalRegistry::s_pcGlobalRegistry;
        if ( GlobalRegistry::s_pcGlobalRegistry )
        {
          GlobalRegistryInstance::~GlobalRegistryInstance(GlobalRegistry::s_pcGlobalRegistry);
          operator delete(v0);
        }
        GlobalRegistry::s_pcGlobalRegistry = 0;
      }
    }
  }
}

