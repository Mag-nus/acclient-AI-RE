/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ProfilerUI
   Object     : ENGINE\profilerui\ProfilerUI.obj
   Functions  : 127
   Addresses  : 00417DF0 - 0077E5A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00417DF0) --------------------------------------------------------  // acclient.c:84782
char __thiscall SmartArray<int,1>::grow(SmartArray<QuickButton *,1> *this, unsigned int i_nSize)
{
  SmartArray<QuickButton *,1> *v2; // esi@1
  void *v4; // ebx@5
  int i; // eax@7

  v2 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ProfilerUIWindow *,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](4 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + i + 1) = v2->m_data[i + 1] )
          --i;
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (QuickButton **)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      return 1;
    }
  }
  return 0;
}

//----- (00459970) --------------------------------------------------------  // acclient.c:150085
void __thiscall SurfaceUsageSummary::SurfaceUsageSummary(ProfilerDBObjStat *this)
{
  volatile LONG *v1; // ST00_4@1

  v1 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->DBTypeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v1);
}

//----- (004F5F50) --------------------------------------------------------  // acclient.c:289530
void __thiscall SmartArray<ProfilerUIWindow *,1>::Reset(SmartArray<QuickButton *,1> *this)
{
  SmartArray<QuickButton *,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    operator delete[](v1->m_data);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; v1->m_data[i + 1] = 0 )
      --i;
  }
}

//----- (005D88E0) --------------------------------------------------------  // acclient.c:516658
void __thiscall ProfilerUI::RegisterInputMaps(ProfilerUI *this)
{
  CInputManager *v1; // esi@1
  ProfilerUI *v2; // edi@1
  IInputActionCallback *v3; // eax@3
  bool v4; // al@5
  int v5; // edi@5

  v1 = ICIDM::s_cidm;
  v2 = this;
  if ( ICIDM::s_cidm )
  {
    if ( this )
      v3 = (IInputActionCallback *)&this->vfptr;
    else
      v3 = 0;
    ICIDM::s_cidm->vfptr->RegisterInputMap((ICIDM *)ICIDM::s_cidm, 12u, v3, 4000);
    v4 = v2->m_IsActive;
    v5 = (int)&v2->vfptr;
    if ( v4 )
      v1->vfptr->RegisterInputMap((ICIDM *)v1, 3u, (IInputActionCallback *)v5, 4000);
    else
      v1->vfptr->UnregisterInputMap((ICIDM *)v1, 3u, (IInputActionCallback *)v5);
  }
}

//----- (005D8930) --------------------------------------------------------  // acclient.c:516685
void __thiscall ProfilerUI::UpdateBudgetStat(ProfilerUI *this, const unsigned int i_index, const unsigned int i_value)
{
  const unsigned int v3; // edx@1
  unsigned int v4; // esi@1
  BudgetStatItem *v5; // ecx@1
  unsigned int v6; // edi@1
  double v7; // st7@3
  float i_indexa; // [sp+Ch] [bp+4h]@3
  float i_valuea; // [sp+10h] [bp+8h]@3

  v3 = i_index;
  this->m_budgetStatArray.m_data[i_index].nValue = i_value;
  v4 = this->m_nGraphicsQualityLevel;
  v5 = this->m_budgetStatArray.m_data;
  v6 = *((_DWORD *)&v5->sInfo.strName.m_charbuffer + v4 + 8 * i_index + i_index);
  if ( v4 )
  {
    i_valuea = (double)v5[v3].nValue;
    v7 = (double)v6;
    i_indexa = v7;
    if ( v7 * 1.15 >= i_valuea )
    {
      if ( v5[v3].nValue <= v6 )
      {
        if ( i_indexa * 0.85000002 >= i_valuea )
        {
          if ( i_indexa * 0.25 >= i_valuea )
            v5[v3].nStatus = 1;
          else
            v5[v3].nStatus = 2;
        }
        else
        {
          v5[v3].nStatus = 3;
        }
      }
      else
      {
        v5[v3].nStatus = 4;
      }
    }
    else
    {
      v5[v3].nStatus = 5;
    }
  }
  else
  {
    v5[v3].nStatus = 0;
  }
}

//----- (005D8A10) --------------------------------------------------------  // acclient.c:516738
void __thiscall ProfilerUI::RepositionWindows(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  unsigned int v2; // ebp@1
  unsigned int v3; // ecx@1
  int v4; // eax@1
  const int v5; // ebx@1
  const int v6; // edi@1
  ProfilerUIWindow *v7; // eax@4
  QuickWindow *v8; // esi@5
  int v9; // eax@8
  unsigned int c; // [sp+10h] [bp-Ch]@1
  const unsigned int MaxAutoPosWindowY; // [sp+14h] [bp-8h]@1
  ProfilerUI *v12; // [sp+18h] [bp-4h]@1

  v1 = this;
  v12 = this;
  v2 = RenderDevice::GetDisplayWidth(RenderDevice::render_device) - 8;
  v3 = RenderDevice::GetDisplayHeight(RenderDevice::render_device) - 6;
  v4 = 0;
  MaxAutoPosWindowY = v3;
  v5 = 170;
  v6 = 20;
  c = 0;
  if ( v1->m_Windows.m_num )
  {
    while ( 1 )
    {
      v7 = v1->m_Windows.m_data[v4];
      if ( v7->m_AutoPositionWindow )
      {
        v8 = v7->m_pQuickWindow;
        if ( v8 )
        {
          if ( v6 + v8->m_Height > v3 )
          {
            v5 += 278;
            v6 = 20;
          }
          v9 = v8->m_Width + v5;
          if ( v9 > v2 )
          {
            if ( v5 == 170 )
            {
              QuickWindow::SetPosition(v8, 170, 20);
              goto LABEL_14;
            }
            if ( v9 > v2 )
            {
              v5 = 170;
              v6 = 20;
            }
          }
          QuickWindow::SetPosition(v8, v5, v6);
          v6 += v8->m_Height + 6;
        }
      }
LABEL_14:
      v1 = v12;
      v4 = c++ + 1;
      if ( c >= v12->m_Windows.m_num )
        return;
      v3 = MaxAutoPosWindowY;
    }
  }
}

//----- (005D8AF0) --------------------------------------------------------  // acclient.c:516806
bool __thiscall ProfilerUI::InputLeftMouseCategoryButtonPressed(ProfilerUI *this, const int _X, const int _Y)
{
  ProfilerUI *v3; // edi@1
  bool result; // al@1
  unsigned int v5; // esi@1
  bool WasHandled; // [sp+1h] [bp-1h]@1

  v3 = this;
  result = 0;
  v5 = 0;
  WasHandled = 0;
  if ( this->m_CategoryButtons.m_num )
  {
    do
    {
      if ( QuickButton::LeftMouseButtonPressed(v3->m_CategoryButtons.m_data[v5], _X, _Y) )
        WasHandled = 1;
      ++v5;
    }
    while ( v5 < v3->m_CategoryButtons.m_num );
    result = WasHandled;
  }
  return result;
}

//----- (005D8B40) --------------------------------------------------------  // acclient.c:516832
bool __thiscall ProfilerUI::InputLeftMouseToolbarButtonPressed(ProfilerUI *this, const int _X, const int _Y)
{
  ProfilerUI *v3; // edi@1
  bool result; // al@1
  unsigned int v5; // esi@1
  bool WasHandled; // [sp+1h] [bp-1h]@1

  v3 = this;
  result = 0;
  v5 = 0;
  WasHandled = 0;
  if ( this->m_ToolbarButtons.m_num )
  {
    do
    {
      if ( QuickButton::LeftMouseButtonPressed(v3->m_ToolbarButtons.m_data[v5], _X, _Y) )
        WasHandled = 1;
      ++v5;
    }
    while ( v5 < v3->m_ToolbarButtons.m_num );
    result = WasHandled;
  }
  return result;
}

//----- (005D8B90) --------------------------------------------------------  // acclient.c:516858
void __thiscall ProfilerUI::UpdateDBObjStats(ProfilerUI *this)
{
  ProfilerUI *v1; // edi@1
  int v2; // ebx@1
  ProfilerDBObjStat *v3; // esi@2
  unsigned int v4; // eax@2
  int v5; // esi@2
  HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>Vtbl *v6; // eax@2
  int v7; // ecx@3
  int v8; // ebp@4
  void *(__thiscall *v9)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *, unsigned int); // eax@5
  int v10; // edx@6
  int v11; // edx@8
  unsigned int Index; // [sp+14h] [bp-4h]@1

  v1 = this;
  v2 = 0;
  Index = 0;
  if ( this->m_DBObjStats.m_num )
  {
    do
    {
      v3 = v1->m_DBObjStats.m_data;
      v4 = v3[v2].DBType;
      v5 = (int)&v3[v2];
      v6 = DBCache::GetDBOCache(v4);
      if ( v6 )
      {
        v7 = (char *)v6[67].__vecDelDtor - (char *)v6[66].__vecDelDtor;
        if ( v7 != *(_DWORD *)(v5 + 8) )
        {
          v8 = HIDWORD(Timer::local_time);
          *(_DWORD *)(v5 + 24) = LODWORD(Timer::local_time);
          *(_DWORD *)(v5 + 28) = v8;
          *(_DWORD *)(v5 + 8) = v7;
        }
        v9 = v6[66].__vecDelDtor;
        if ( v9 != *(void *(__thiscall **)(HashTable<IDClass<_tagDataID,32,0>,DBObj *,1> *, unsigned int))(v5 + 12) )
        {
          v10 = HIDWORD(Timer::local_time);
          *(_DWORD *)(v5 + 24) = LODWORD(Timer::local_time);
          *(_DWORD *)(v5 + 28) = v10;
          *(_DWORD *)(v5 + 12) = v9;
        }
        if ( *(_DWORD *)(v5 + 12) + *(_DWORD *)(v5 + 8) )
        {
          v11 = HIDWORD(Timer::local_time);
          *(_DWORD *)(v5 + 16) = LODWORD(Timer::local_time);
          *(_DWORD *)(v5 + 20) = v11;
        }
      }
      ++v2;
      ++Index;
    }
    while ( Index < v1->m_DBObjStats.m_num );
  }
}

//----- (005D8C50) --------------------------------------------------------  // acclient.c:516917
void __userpurge GlobalRegistry::InqTypedVariable(PStringBase<char> *_Name@<eax>, PStringBase<char> *a2@<ecx>, bool *_Value)
{
  GlobalRegistryInstance *v3; // eax@1
  PStringBase<char> *v4; // esi@1
  GlobalRegistryInstance *v5; // eax@2
  int v6; // eax@7
  GRPObject *pObject; // [sp+0h] [bp-4h]@1

  v3 = GlobalRegistry::s_pcGlobalRegistry;
  v4 = a2;
  pObject = 0;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v5 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v5 )
      GlobalRegistryInstance::GlobalRegistryInstance(v5);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v3, v4, &pObject) )
  {
    v6 = ((int (*)(void))pObject->vfptr->AsTypedVariableObject)();
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 16) == 2 )
        *_Value = **(_BYTE **)(v6 + 12);
    }
  }
}

//----- (005D8CC0) --------------------------------------------------------  // acclient.c:516949
void __userpurge GlobalRegistry::InqTypedVariable(PStringBase<char> *_Name@<eax>, PStringBase<char> *a2@<ecx>, unsigned int *_Value)
{
  GlobalRegistryInstance *v3; // eax@1
  PStringBase<char> *v4; // esi@1
  GlobalRegistryInstance *v5; // eax@2
  int v6; // eax@7
  GRPObject *pObject; // [sp+0h] [bp-4h]@1

  v3 = GlobalRegistry::s_pcGlobalRegistry;
  v4 = a2;
  pObject = 0;
  if ( !GlobalRegistry::s_pcGlobalRegistry )
  {
    v5 = (GlobalRegistryInstance *)operator new(0x8100u);
    if ( v5 )
      GlobalRegistryInstance::GlobalRegistryInstance(v5);
    else
      v3 = 0;
    GlobalRegistry::s_pcGlobalRegistry = v3;
  }
  if ( GlobalRegistryInstance::FindObjectByName(v3, v4, &pObject) )
  {
    v6 = ((int (*)(void))pObject->vfptr->AsTypedVariableObject)();
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 16) == 4 )
        *_Value = **(_DWORD **)(v6 + 12);
    }
  }
}

//----- (005D8D30) --------------------------------------------------------  // acclient.c:516981
void *__thiscall BudgetStatItem::vector_deleting_destructor(BudgetStatItem *this, unsigned int a2)
{
  BudgetStatItem *v2; // edi@1
  ProfilerBudget::Status v3; // eax@2
  char *v4; // ebx@2
  int v5; // ecx@2
  int v6; // eax@2
  int v7; // edi@2
  int v8; // esi@4
  int v9; // esi@4
  void *result; // eax@10
  char *v11; // esi@11
  int v12; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = this[-1].nStatus;
    v4 = (char *)&this[-1].nStatus;
    v5 = 9 * v3;
    v6 = v3 - 1;
    v7 = (int)&v2[4 * v5 / 0x24u];
    if ( v6 >= 0 )
    {
      v12 = v6 + 1;
      do
      {
        v8 = *(_DWORD *)(v7 - 36);
        v7 -= 36;
        v9 = v8 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        --v12;
      }
      while ( v12 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v11 = &this->sInfo.strName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)v11 + 1) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (005D8DE0) --------------------------------------------------------  // acclient.c:517034
void *__thiscall ProfilerDBObjStat::vector_deleting_destructor(ProfilerDBObjStat *this, unsigned int a2)
{
  ProfilerDBObjStat *v2; // edi@1
  int v3; // ecx@2
  void *v4; // ebx@2
  int v5; // eax@2
  int v6; // ecx@2
  int v7; // edi@3
  int v8; // esi@4
  int v9; // esi@4
  void *result; // eax@10
  char *v11; // esi@11
  int v12; // [sp+4h] [bp-4h]@3

  v2 = this;
  if ( a2 & 2 )
  {
    v3 = HIDWORD(this[-1].LastLocalTimeChanged);
    v4 = (char *)&v2[-1].LastLocalTimeChanged + 4;
    v5 = (int)&v2[v3];
    v6 = v3 - 1;
    if ( v6 >= 0 )
    {
      v7 = v5 + 4;
      v12 = v6 + 1;
      do
      {
        v8 = *(_DWORD *)(v7 - 32);
        v7 -= 32;
        v9 = v8 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v9 + 4)) && v9 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
        --v12;
      }
      while ( v12 );
    }
    if ( a2 & 1 )
      operator delete[](v4);
    result = v4;
  }
  else
  {
    v11 = &this->DBTypeName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)v11 + 1) && v11 )
      (**(void (__thiscall ***)(char *, signed int))v11)(v11, 1);
    if ( a2 & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (005D8E90) --------------------------------------------------------  // acclient.c:517087
int __thiscall ProfilerDBObjStat::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  v3 = *(_DWORD *)(this + 4);
  if ( v3 != *(_DWORD *)(a2 + 4) )
  {
    v4 = v3 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 - 20 + 4)) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v2 + 4) = v5;
    InterlockedIncrement((volatile LONG *)(v5 - 16));
  }
  *(_DWORD *)(v2 + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(v2 + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v2 + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v2 + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(v2 + 28) = *(_DWORD *)(a2 + 28);
  return v2;
}

//----- (005D8F00) --------------------------------------------------------  // acclient.c:517116
void *__thiscall BudgetStatInfo::operator=(void *this, int a2)
{
  void *v2; // esi@1
  int v3; // eax@1
  int v4; // ebx@2
  int v5; // eax@5

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
  *((_DWORD *)v2 + 1) = *(_DWORD *)(a2 + 4);
  *((_DWORD *)v2 + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)v2 + 3) = *(_DWORD *)(a2 + 12);
  *((_DWORD *)v2 + 4) = *(_DWORD *)(a2 + 16);
  *((_DWORD *)v2 + 5) = *(_DWORD *)(a2 + 20);
  *((_BYTE *)v2 + 24) = *(_BYTE *)(a2 + 24);
  return v2;
}

//----- (005D8F70) --------------------------------------------------------  // acclient.c:517144
void __thiscall BudgetStatInfo::BudgetStatInfo(BudgetStatInfo *this, PStringBase<char> i_strName, unsigned int i_nVLow, unsigned int i_nLow, unsigned int i_nMed, unsigned int i_nHigh, unsigned int i_nVHigh, bool i_bIsMem)
{
  BudgetStatInfo *v8; // esi@1
  volatile LONG *v9; // ST04_4@1
  PSRefBufferCharData<char> *v10; // eax@1
  int v11; // ebx@2

  v8 = this;
  v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  this->strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v9);
  v10 = v8->strName.m_charbuffer;
  if ( v8->strName.m_charbuffer != i_strName.m_charbuffer )
  {
    v11 = (int)&v10[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
    v8->strName.m_charbuffer = i_strName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&i_strName.m_charbuffer[-1]);
  }
  v8->nGraphicLevel[0] = i_nVLow;
  v8->nGraphicLevel[3] = i_nHigh;
  v8->nGraphicLevel[1] = i_nLow;
  v8->nGraphicLevel[2] = i_nMed;
  v8->nGraphicLevel[4] = i_nVHigh;
  v8->bIsMem = i_bIsMem;
  if ( !InterlockedDecrement((volatile LONG *)&i_strName.m_charbuffer[-1])
    && i_strName.m_charbuffer != (PSRefBufferCharData<char> *)20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))&i_strName.m_charbuffer[-2].m_data[12])(
      &i_strName.m_charbuffer[-2].m_data[12],
      1);
}

//----- (005D9010) --------------------------------------------------------  // acclient.c:517178
void __thiscall ProfilerUI::UpdateStats(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  OSSpecificProfilerUIInfo *v2; // ecx@1

  v1 = this;
  v2 = this->m_pOSSpecificProfiler;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->FillInOSSpecificInfo)(v1);
  ProfilerUI::UpdateBudgetStat(v1, 3u, v1->m_nSystemMemoryAllocated);
  ProfilerUI::UpdateBudgetStat(v1, 4u, v1->m_nVirtualMemoryReserved);
  ProfilerUI::UpdateBudgetStat(
    v1,
    5u,
    dword_8F13FC + dword_8F13F8 + dword_8F13F4 + dword_8F13F0 + dword_8F13EC + dword_8F13E8);
  ProfilerUI::UpdateBudgetStat(v1, 0, i_value);
  ProfilerUI::UpdateBudgetStat(v1, 1u, dword_8F1440);
  ProfilerUI::UpdateBudgetStat(v1, 2u, dword_8F1444);
  ProfilerUI::UpdateBudgetStat(v1, 6u, dword_8F148C + dword_8F1488 + dword_8F1484 + dword_8F1480);
  ProfilerUI::UpdateDBObjStats(v1);
}
// 8F13E8: using guessed type int dword_8F13E8;
// 8F13EC: using guessed type int dword_8F13EC;
// 8F13F0: using guessed type int dword_8F13F0;
// 8F13F4: using guessed type int dword_8F13F4;
// 8F13F8: using guessed type int dword_8F13F8;
// 8F13FC: using guessed type int dword_8F13FC;
// 8F1480: using guessed type int dword_8F1480;
// 8F1484: using guessed type int dword_8F1484;
// 8F1488: using guessed type int dword_8F1488;
// 8F148C: using guessed type int dword_8F148C;

//----- (005D90D0) --------------------------------------------------------  // acclient.c:517211
void __thiscall ProfilerUI::RemoveWindow(ProfilerUI *this, const unsigned int _WindowHandle)
{
  ProfilerUI *v2; // edi@1
  unsigned int v3; // ecx@1
  unsigned int v4; // esi@1
  ProfilerUIWindow **v5; // eax@2
  ProfilerUIWindow *v6; // ebx@6
  QuickWindow *v7; // ecx@7
  bool v8; // zf@8
  unsigned int v9; // eax@12
  int v10; // eax@13

  v2 = this;
  v3 = this->m_Windows.m_num;
  v4 = 0;
  if ( v3 )
  {
    v5 = v2->m_Windows.m_data;
    while ( (*v5)->m_WindowHandle != _WindowHandle )
    {
      ++v4;
      ++v5;
      if ( v4 >= v3 )
      {
        ProfilerUI::RepositionWindows(v2);
        return;
      }
    }
    v6 = v2->m_Windows.m_data[v4];
    if ( v6 )
    {
      v7 = v6->m_pQuickWindow;
      if ( v7 )
      {
        v8 = v7->m_cRef-- == 1;
        if ( v8 )
          ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
        v6->m_pQuickWindow = 0;
      }
      operator delete(v6);
    }
    v2->m_Windows.m_data[v4] = 0;
    v9 = v2->m_Windows.m_num;
    if ( v4 < v9 )
    {
      v10 = v9 - 1;
      v2->m_Windows.m_num = v10;
      if ( v4 != v10 )
      {
        v2->m_Windows.m_data[v4] = v2->m_Windows.m_data[v10];
        v2->m_Windows.m_data[v2->m_Windows.m_num] = 0;
      }
    }
  }
  ProfilerUI::RepositionWindows(v2);
}

//----- (005D9180) --------------------------------------------------------  // acclient.c:517269
void __thiscall SmartArray<ProfilerDBObjStat,1>::Reset(SmartArray<ProfilerDBObjStat,1> *this)
{
  SmartArray<ProfilerDBObjStat,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // esi@8
  int v7; // [sp+8h] [bp-24h]@7
  char v8; // [sp+Ch] [bp-20h]@8
  PSRefBufferCharData<char> *v9; // [sp+10h] [bp-1Ch]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      ProfilerDBObjStat::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v7 = v4 + 1;
      do
      {
        v9 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        ProfilerDBObjStat::operator=((int)&v1->m_data[v5], (int)&v8);
        v6 = (int)&v9[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v9[-1]) && v6 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
        --v5;
        --v7;
      }
      while ( v7 );
    }
  }
}

//----- (005D9240) --------------------------------------------------------  // acclient.c:517316
char __thiscall SmartArray<ProfilerDBObjStat,1>::grow(SmartArray<ProfilerDBObjStat,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<ProfilerDBObjStat,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  unsigned int i_nSizea; // [sp+10h] [bp+4h]@9

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ProfilerDBObjStat,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](32 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x20u,
        i_nSize,
        (void *(__thiscall *)(void *))SurfaceUsageSummary::SurfaceUsageSummary);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              ProfilerDBObjStat::operator=(v8 * 32 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v3->m_data )
              ProfilerDBObjStat::vector_deleting_destructor(v3->m_data, 3u);
          }
        }
        v3->m_data = (ProfilerDBObjStat *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005D9310) --------------------------------------------------------  // acclient.c:517380
void BudgetStatInfoArray::~BudgetStatInfoArray()
{
  signed int v1; // edi@1
  void *v2; // ebx@2
  int v3; // esi@3

  v1 = (signed int)&BudgetStatInfoArray::s_BudgetStatInfo;
  do
  {
    v2 = *(void **)v1;
    if ( *(_DWORD *)v1 )
    {
      v3 = *(_DWORD *)v2 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
      {
        if ( v3 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      }
      operator delete(v2);
    }
    *(_DWORD *)v1 = 0;
    v1 += 4;
  }
  while ( v1 < (signed int)&unk_8F10BC );
}
// 8F10A0: using guessed type const struct BudgetStatInfo **BudgetStatInfoArray::s_BudgetStatInfo;

//----- (005D9360) --------------------------------------------------------  // acclient.c:517408
void __thiscall ProfilerUI::RemoveCategoryWindow(ProfilerUI *this, ProfilerTypes::CategoryType _Category)
{
  unsigned int v2; // edi@1
  unsigned int v3; // edx@1
  ProfilerUIWindow **v4; // esi@2
  ProfilerTypes::CategoryType v5; // eax@3

  v2 = this->m_Windows.m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_Windows.m_data;
    while ( 1 )
    {
      v5 = (*v4)->m_Category;
      if ( v5 != 6 && v5 == _Category )
        break;
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        return;
    }
    ProfilerUI::RemoveWindow(this, this->m_Windows.m_data[v3]->m_WindowHandle);
  }
}

//----- (005D93B0) --------------------------------------------------------  // acclient.c:517435
void __thiscall ProfilerUI::UpdateToolbarButtonStates(ProfilerUI *this)
{
  int v1; // ebx@1
  unsigned int v2; // ecx@1
  unsigned int v3; // eax@1
  int v4; // edi@2
  int v5; // eax@2
  char *v6; // esi@3
  PStringBase<char> *v7; // eax@7
  char *v8; // esi@7
  unsigned int v9; // ebx@10
  PSRefBufferCharData<char> *v10; // eax@10
  int v11; // esi@11
  PSRefBufferCharData<char> *v12; // eax@14
  char *v13; // esi@15
  char *v14; // esi@18
  unsigned int v15; // ecx@22
  char *v16; // esi@24
  PStringBase<char> v17; // [sp+8h] [bp-28h]@10
  PStringBase<char> v18; // [sp+Ch] [bp-24h]@3
  PStringBase<char> v19; // [sp+10h] [bp-20h]@7
  unsigned int Flags; // [sp+14h] [bp-1Ch]@7
  PStringBase<char> strButton; // [sp+18h] [bp-18h]@10
  PStringBase<char> v22; // [sp+1Ch] [bp-14h]@24
  int v23; // [sp+20h] [bp-10h]@1
  unsigned int b; // [sp+24h] [bp-Ch]@1
  int Enabled; // [sp+28h] [bp-8h]@3
  bool _Value[4]; // [sp+2Ch] [bp-4h]@24

  v1 = (int)this;
  v2 = this->m_ToolbarButtons.m_num;
  v3 = 0;
  v23 = v1;
  b = 0;
  if ( v2 )
  {
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)(v1 + 60) + 4 * v3);
      v5 = *(_DWORD *)(v4 + 8);
      switch ( v5 )
      {
        case 20:
          PStringBase<char>::PStringBase<char>(&v18, "RenderDevice.Wireframe");
          GlobalRegistry::InqTypedVariable((PStringBase<char> *)&Enabled, &v18, (bool *)&Enabled);
          v6 = &v18.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) )
          {
            if ( v6 )
              (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
          }
          QuickButton::SetCheckedState((QuickButton *)v4, Enabled);
          break;
        case 21:
          Flags = 0;
          PStringBase<char>::PStringBase<char>(&v19, "RenderD3D.AlphaDelayMask");
          GlobalRegistry::InqTypedVariable(v7, &v19, &Flags);
          v8 = &v19.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v19.m_charbuffer[-1]) && v8 )
            (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
          v9 = Flags;
          PStringBase<char>::PStringBase<char>(&strButton, 0, "Delayed Alpha [%x]", Flags);
          PStringBase<char>::PStringBase<char>(&v17, strButton.m_charbuffer->m_data);
          v10 = *(PSRefBufferCharData<char> **)(v4 + 76);
          if ( v10 != v17.m_charbuffer )
          {
            v11 = (int)&v10[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&v10[-1]) && v11 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
            v12 = v17.m_charbuffer;
            *(_DWORD *)(v4 + 76) = v17.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&v12[-1]);
          }
          v13 = &v17.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v17.m_charbuffer[-1]) && v13 )
            (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
          QuickButton::SetCheckedState((QuickButton *)v4, v9 != 0);
          v14 = &strButton.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&strButton.m_charbuffer[-1]) && v14 )
            (**(void (__thiscall ***)(char *, signed int))v14)(v14, 1);
          v1 = v23;
          break;
        default:
          break;
        case 22:
          PStringBase<char>::PStringBase<char>(&v22, "RenderDeviceD3D.AllowDrawPrimUP");
          GlobalRegistry::InqTypedVariable((PStringBase<char> *)_Value, &v22, _Value);
          v16 = &v22.m_charbuffer[-2].m_data[12];
          if ( !InterlockedDecrement((volatile LONG *)&v22.m_charbuffer[-1]) && v16 )
            (**(void (__thiscall ***)(char *, signed int))v16)(v16, 1);
          QuickButton::SetCheckedState((QuickButton *)v4, _Value[0]);
          break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
          QuickButton::SetCheckedState((QuickButton *)v4, *(_DWORD *)(v1 + 84) == v5 - 9);
          break;
      }
      v15 = *(_DWORD *)(v1 + 68);
      v3 = b++ + 1;
    }
    while ( b < v15 );
  }
}

//----- (005D95D0) --------------------------------------------------------  // acclient.c:517543
void __thiscall ProfilerUI::PrintBudgetStat(ProfilerUI *this, const unsigned int i_index, QuickWindow *i_pQuickWindow)
{
  ProfilerUI *v3; // edi@1
  BudgetStatItem *v4; // ecx@1
  const char *v5; // ebp@1
  const unsigned int v6; // esi@1
  unsigned int v7; // eax@1
  char v8; // bl@1
  int v9; // esi@1
  unsigned int budgetStat_28; // [sp+38h] [bp-808h]@1
  char txt1[1024]; // [sp+40h] [bp-800h]@2
  char txt2[1024]; // [sp+440h] [bp-400h]@2

  v3 = this;
  v4 = this->m_budgetStatArray.m_data;
  v5 = v4[i_index].sInfo.strName.m_charbuffer->m_data;
  v6 = (const unsigned int)&v4[i_index];
  InterlockedIncrement((volatile LONG *)v5 - 4);
  v7 = *(_DWORD *)(v6 + 28);
  v8 = *(_BYTE *)(v6 + 24);
  v9 = *(_DWORD *)(v6 + 32);
  budgetStat_28 = v7;
  QuickWindow::RenderText(i_pQuickWindow, 0, v3->m_CurrentYPixel, v5, g_BudgetItemColor[v9]);
  if ( v8 )
  {
    _sprintf(txt1, "%.02f", (double)budgetStat_28 * 0.00000095367432);
    _sprintf(txt2, "%6s MB", txt1);
    QuickWindow::RenderText(i_pQuickWindow, 180, v3->m_CurrentYPixel, txt2, g_BudgetItemColor[v9]);
  }
  else
  {
    _sprintf(txt1, "%9i", budgetStat_28);
    QuickWindow::RenderText(i_pQuickWindow, 180, v3->m_CurrentYPixel, txt1, g_BudgetItemColor[v9]);
  }
  v3->m_CurrentYPixel += 12;
  if ( !InterlockedDecrement((volatile LONG *)v5 - 4) && v5 != (const char *)20 )
    (*(void (__thiscall **)(const char *, signed int))*((void (__thiscall ***)(_DWORD, _DWORD))v5 - 5))(v5 - 20, 1);
}

//----- (005D96F0) --------------------------------------------------------  // acclient.c:517583
void __thiscall BudgetStatItem::BudgetStatItem(BudgetStatItem *this)
{
  BudgetStatItem *v1; // esi@1
  int v2; // ecx@1

  v1 = this;
  PStringBase<char>::PStringBase<char>(&this->sInfo.strName, &name);
  v1->sInfo.bIsMem = 0;
  v2 = (int)v1->sInfo.nGraphicLevel;
  *(_DWORD *)v2 = 0;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
}

//----- (005D9720) --------------------------------------------------------  // acclient.c:517600
void __thiscall ProfilerUI::Think(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1

  v1 = this;
  if ( this->m_WantActivate || this->m_WantDeactivate )
  {
    this->m_WantActivate = 0;
    this->m_WantDeactivate = 0;
    ProfilerUI::RegisterInputMaps(this);
  }
  if ( v1->m_IsActive )
  {
    v1->m_nGraphicsQualityLevel = Render::DetermineOverallGraphicsQuality();
    ProfilerUI::UpdateStats(v1);
    if ( v1->m_IsActive )
      ProfilerUI::UpdateToolbarButtonStates(v1);
  }
}

//----- (005D9770) --------------------------------------------------------  // acclient.c:517621
void __thiscall ProfilerUI::Render(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  const unsigned int v2; // ebx@2
  ProfilerUIWindow *v3; // eax@3
  QuickWindow *v4; // edi@3
  int v5; // eax@3
  const int v6; // edx@5
  const int v7; // edx@5
  const int v8; // edx@5
  const int v9; // edx@5
  const int v10; // edx@5
  const int v11; // edx@5
  const int v12; // edx@5
  const int v13; // ST10_4@5
  const int v14; // ST10_4@5
  const int v15; // ST10_4@5
  const int v16; // ST10_4@5
  const int v17; // ST10_4@5
  const int v18; // eax@5
  const int v19; // eax@5
  const int v20; // eax@5
  const int v21; // eax@5
  const int v22; // eax@5
  const int v23; // eax@5
  const int v24; // eax@5
  const int v25; // ST10_4@5
  const int v26; // ST10_4@5
  const int v27; // ST10_4@5
  const int v28; // ST10_4@5
  const int v29; // ST10_4@5
  const int v30; // ST10_4@5
  const int v31; // ST10_4@5
  const int v32; // ST10_4@5
  char *v33; // eax@6
  const int v34; // eax@7
  const int v35; // eax@7
  const int v36; // eax@7
  const int v37; // ST10_4@8
  const int v38; // ST10_4@8
  const int v39; // ST10_4@8
  const int v40; // ST10_4@10
  const int v41; // ST10_4@10
  const int v42; // ST10_4@10
  int v43; // eax@11
  int v44; // eax@12
  int v45; // ST30_4@13
  unsigned int TotalIndexBufferVideoMemoryAllocated; // ST44_4@13
  unsigned int v47; // ST38_4@13
  unsigned int v48; // ST34_4@13
  unsigned int v49; // ST40_4@13
  const int v50; // ST10_4@13
  const int v51; // ST10_4@13
  const int v52; // edx@13
  const int v53; // ST10_4@13
  const int v54; // ST10_4@13
  const int v55; // edx@13
  const int v56; // ST10_4@13
  const int v57; // ST10_4@13
  const int v58; // edx@13
  const int v59; // ST10_4@13
  const int v60; // ST10_4@13
  const int v61; // edx@13
  const int v62; // ST10_4@13
  const int v63; // ST10_4@13
  const int v64; // edx@13
  const int v65; // ST10_4@13
  const int v66; // ST10_4@13
  const int v67; // edx@13
  const int v68; // ST10_4@13
  const int v69; // ST10_4@13
  const int v70; // edx@13
  const int v71; // ST10_4@13
  const int v72; // ST10_4@13
  const int v73; // edx@13
  const unsigned int v74; // eax@17
  int v75; // ecx@17
  const int v76; // edx@17
  long double v77; // st7@20
  const unsigned int v78; // ecx@20
  int v79; // eax@24
  const int v80; // ST10_4@28
  unsigned int v81; // edi@32
  unsigned int v82; // edi@34
  ProfilerDBObjStat *DBObjStat; // [sp+20h] [bp-54h]@4
  ProfilerDBObjStat *DBObjStata; // [sp+20h] [bp-54h]@19
  unsigned int MyItemValueColor; // [sp+24h] [bp-50h]@20
  unsigned int TotalMeshMemory; // [sp+28h] [bp-4Ch]@18
  unsigned int WindowIndex; // [sp+2Ch] [bp-48h]@2
  unsigned int Index; // [sp+30h] [bp-44h]@3
  unsigned int Indexa; // [sp+30h] [bp-44h]@17
  double CurrentLocalTime; // [sp+3Ch] [bp-38h]@17
  RGBAColor v91; // [sp+44h] [bp-30h]@17
  _MEMORYSTATUS MemoryStatus; // [sp+54h] [bp-20h]@13

  v1 = this;
  if ( this->m_IsActive )
  {
    RenderDeviceD3D::SetFillMode((RenderDeviceD3D *)RenderDevice::render_device, FILLMODE_SOLID);
    v2 = (unsigned __int64)(stru_823AF0.b * 255.0) | (((unsigned int)(unsigned __int64)(stru_823AF0.g * 255.0) | (((unsigned int)(unsigned __int64)(stru_823AF0.r * 255.0) | ((unsigned int)(unsigned __int64)(stru_823AF0.a * 255.0) << 8)) << 8)) << 8);
    RenderDeviceD3D::BeginRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
    WindowIndex = 0;
    if ( v1->m_Windows.m_num )
    {
      while ( 1 )
      {
        v3 = v1->m_Windows.m_data[WindowIndex];
        v4 = v3->m_pQuickWindow;
        Index = (unsigned int)&v1->m_Windows.m_data[WindowIndex]->m_WindowHandle;
        ((void (__thiscall *)(QuickWindow *))v4->vfptr[1].__vecDelDtor)(v3->m_pQuickWindow);
        v1->m_CurrentYPixel = 0;
        v5 = *(_DWORD *)(Index + 8);
        if ( v5 != 6 )
        {
          DBObjStat = (ProfilerDBObjStat *)(&i_value + 34 * v5);
          switch ( v5 )
          {
            case 0:
              _sprintf(txt1, "[%s]", gc_CategoryNames);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
              v1->m_CurrentYPixel += 16;
              ProfilerUI::PrintBudgetStat(v1, 0, v4);
              ProfilerUI::PrintBudgetStat(v1, 1u, v4);
              ProfilerUI::PrintBudgetStat(v1, 2u, v4);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, "UISurfaces Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->NumFree);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v6 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v6;
              QuickWindow::RenderText(v4, 0, v6, "Textures Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat->LastLocalTimeNotEmpty));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v7 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v7;
              QuickWindow::RenderText(v4, 0, v7, "Texture Mem Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)LODWORD(DBObjStat->LastLocalTimeChanged) * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v8 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v8;
              QuickWindow::RenderText(v4, 0, v8, "Vertices Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat->LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v9 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v9;
              QuickWindow::RenderText(v4, 0, v9, "VB Memory Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)DBObjStat[1].DBType * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v10 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v10;
              QuickWindow::RenderText(v4, 0, v10, "Recycled Dynamic Verts", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[1].DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v11 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v11;
              QuickWindow::RenderText(v4, 0, v11, "Indices Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[1].NumActive);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v12 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v12;
              QuickWindow::RenderText(v4, 0, v12, "IB Memory Uploaded", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)DBObjStat[1].NumFree * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v13 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v13;
              QuickWindow::RenderText(v4, 0, v13, "Particles Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", LODWORD(DBObjStat[1].LastLocalTimeNotEmpty));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v14 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v14;
              QuickWindow::RenderText(v4, 0, v14, "Particle Systems", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat[1].LastLocalTimeNotEmpty));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v15 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v15;
              QuickWindow::RenderText(v4, 0, v15, "Material Layers Applied", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", LODWORD(DBObjStat[1].LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v16 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v16;
              QuickWindow::RenderText(v4, 0, v16, "D3D Texture Changes", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat[1].LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v17 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v17;
              QuickWindow::RenderText(v4, 0, v17, "D3D Stream Changes", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[2].DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v1->m_CurrentYPixel += 12;
              ProfilerUI::PrintBudgetStat(v1, 6u, v4);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, "Texture Memory", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)*(signed int *)&DBObjStat[2].DBTypeName.m_charbuffer * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v18 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v18;
              QuickWindow::RenderText(v4, 0, v18, "Surface Memory", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)DBObjStat[2].NumActive * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v19 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v19;
              QuickWindow::RenderText(v4, 0, v19, "Vertex Buffer Memory", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)DBObjStat[2].NumFree * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v20 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v20;
              QuickWindow::RenderText(v4, 0, v20, "Index Buffer Memory", 0xFFCCCCCC);
              _sprintf(txt1, "%.02f", (double)LODWORD(DBObjStat[2].LastLocalTimeNotEmpty) * 0.00000095367432);
              _sprintf(txt2, "%7s MB", txt1);
              QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
              v21 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v21;
              QuickWindow::RenderText(v4, 0, v21, "Sounds Playing", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat[2].LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v22 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v22;
              QuickWindow::RenderText(v4, 0, v22, "Sounds Queued", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[3].DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v23 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v23;
              QuickWindow::RenderText(v4, 0, v23, "UIElements Processed", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[3].DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v24 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v24;
              QuickWindow::RenderText(v4, 0, v24, "AC1: Landscape Surfaces", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", Profiler::CapturedStats.Global.AC1.lsurfCount);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v25 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v25;
              QuickWindow::RenderText(v4, 0, v25, "AC1: Static Lights", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[3].NumActive);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v26 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v26;
              QuickWindow::RenderText(v4, 0, v26, "AC1: Dynamic Lights", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[3].NumFree);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v27 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v27;
              QuickWindow::RenderText(v4, 0, v27, "AC1: Frame Pushes", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", LODWORD(DBObjStat[3].LastLocalTimeNotEmpty));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v28 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v28;
              QuickWindow::RenderText(v4, 0, v28, "AC1: Poly Count", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat[3].LastLocalTimeNotEmpty));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v29 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v29;
              QuickWindow::RenderText(v4, 0, v29, "AC1: Landblocks Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", LODWORD(DBObjStat[3].LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v30 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v30;
              QuickWindow::RenderText(v4, 0, v30, "AC1: EnvCells Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", HIDWORD(DBObjStat[3].LastLocalTimeChanged));
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v31 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v31;
              QuickWindow::RenderText(v4, 0, v31, "AC1: Objects Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[4].DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v32 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v32;
              QuickWindow::RenderText(v4, 0, v32, "AC1: Portals Traversed", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat[4].DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              goto LABEL_29;
            case 1:
              v33 = off_823A64;
              goto LABEL_10;
            case 2:
              _sprintf(txt1, "[%s]", off_823A68);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
              v34 = v1->m_CurrentYPixel + 16;
              v1->m_CurrentYPixel = v34;
              QuickWindow::RenderText(v4, 0, v34, "Triangles Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v35 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v35;
              QuickWindow::RenderText(v4, 0, v35, "Vertices Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v36 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v36;
              QuickWindow::RenderText(v4, 0, v36, "Batches Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->NumActive);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              goto LABEL_29;
            case 3:
              _sprintf(txt1, "[%s]", off_823A6C);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
              v37 = v1->m_CurrentYPixel + 16;
              v1->m_CurrentYPixel = v37;
              QuickWindow::RenderText(v4, 0, v37, "Triangles Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v38 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v38;
              QuickWindow::RenderText(v4, 0, v38, "Vertices Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v39 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v39;
              QuickWindow::RenderText(v4, 0, v39, "Batches Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->NumActive);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              goto LABEL_29;
            case 4:
              v33 = off_823A70;
LABEL_10:
              _sprintf(txt1, "[%s]", v33);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
              v40 = v1->m_CurrentYPixel + 16;
              v1->m_CurrentYPixel = v40;
              QuickWindow::RenderText(v4, 0, v40, "Triangles Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBType);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v41 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v41;
              QuickWindow::RenderText(v4, 0, v41, "Vertices Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->DBTypeName.m_charbuffer);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              v42 = v1->m_CurrentYPixel + 12;
              v1->m_CurrentYPixel = v42;
              QuickWindow::RenderText(v4, 0, v42, "Batches Rendered", 0xFFCCCCCC);
              _sprintf(txt1, "%9i", DBObjStat->NumActive);
              QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, v2);
              goto LABEL_29;
            default:
              _sprintf(txt2, "<Unknown/%i>", v5);
              _sprintf(txt1, "[%s]", txt2);
              QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
              v43 = v1->m_CurrentYPixel + 16;
              break;
          }
          goto LABEL_30;
        }
        v44 = *(_DWORD *)Index;
        if ( *(_DWORD *)Index == v1->m_MemoryCountersStatsWindowHandle )
        {
          v45 = dword_8F13F4 + dword_8F13F0;
          TotalIndexBufferVideoMemoryAllocated = dword_8F13FC + dword_8F13F8;
          v47 = dword_8F1410 + dword_8F1408 + dword_8F140C;
          v48 = (*(int (__stdcall **)(_DWORD))(*LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24)
                                             + 16))(LODWORD(RenderDevice::render_device[1].m_GState.ViewToClipMatrix._24));
          MemoryStatus.dwLength = 32;
          GlobalMemoryStatus(&MemoryStatus);
          v49 = v47
              + dword_8F1438
              + dword_8F1434
              + dword_8F1424
              + dword_8F1420
              + dword_8F1418
              + dword_8F1414
              + dword_8F1400
              + dword_8F1404;
          _sprintf(txt1, "[%s]", "Memory Counters");
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
          v1->m_CurrentYPixel += 16;
          ProfilerUI::PrintBudgetStat(v1, 3u, v4);
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, "  Peak Process Memory", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)v1->m_nPeakSystemMemoryAllocated * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v1->m_CurrentYPixel += 12;
          ProfilerUI::PrintBudgetStat(v1, 4u, v4);
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, "  Peak Virtual Memory", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)v1->m_nPeakVirtualMemoryReserved * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v50 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v50;
          QuickWindow::RenderText(v4, 0, v50, "Memory Available", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)MemoryStatus.dwAvailVirtual * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v51 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v51;
          QuickWindow::RenderText(v4, 0, v51, "Memory Accounted For", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)v49 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v52 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v52;
          QuickWindow::RenderText(v4, 0, v52, "  ImgTex", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1434 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v53 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v53;
          QuickWindow::RenderText(v4, 0, v53, "  D3DXMesh", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1438 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v54 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v54;
          QuickWindow::RenderText(v4, 0, v54, "  Surfaces", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1400 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v55 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v55;
          QuickWindow::RenderText(v4, 0, v55, "  UISurfaces", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1404 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v56 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v56;
          QuickWindow::RenderText(v4, 0, v56, "  Meshes", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)v47 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v57 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v57;
          QuickWindow::RenderText(v4, 0, v57, "    Vertices", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1408 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v58 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v58;
          QuickWindow::RenderText(v4, 0, v58, "    Triangles", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F140C * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v59 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v59;
          QuickWindow::RenderText(v4, 0, v59, "    Topology", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1410 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v60 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v60;
          QuickWindow::RenderText(v4, 0, v60, "  Fonts", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1414 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v61 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v61;
          QuickWindow::RenderText(v4, 0, v61, "  Audio", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1418 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v62 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v62;
          QuickWindow::RenderText(v4, 0, v62, "  Movies", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1420 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v63 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v63;
          QuickWindow::RenderText(v4, 0, v63, "  LandBlocks", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1424 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v1->m_CurrentYPixel += 12;
          ProfilerUI::PrintBudgetStat(v1, 5u, v4);
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, "Video Mem Available", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)v48 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v64 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v64;
          QuickWindow::RenderText(v4, 0, v64, "  Textures", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13E8 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v65 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v65;
          QuickWindow::RenderText(v4, 0, v65, "  Surfaces", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13EC * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v66 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v66;
          QuickWindow::RenderText(v4, 0, v66, "  Vertex Buffers", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)v45 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v67 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v67;
          QuickWindow::RenderText(v4, 0, v67, "    Static", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13F0 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v68 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v68;
          QuickWindow::RenderText(v4, 0, v68, "    Dynamic", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13F4 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v69 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v69;
          QuickWindow::RenderText(v4, 0, v69, "  Index Buffers", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)TotalIndexBufferVideoMemoryAllocated * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v70 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v70;
          QuickWindow::RenderText(v4, 0, v70, "    Static", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13F8 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v71 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v71;
          QuickWindow::RenderText(v4, 0, v71, "    Dynamic", 0xFF999999);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F13FC * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, 0xFFB2B2B2);
          v72 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v72;
          QuickWindow::RenderText(v4, 0, v72, "Compositor Resources", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F142C * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          v73 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v73;
          QuickWindow::RenderText(v4, 0, v73, "Compositor Textures", 0xFFCCCCCC);
          _sprintf(txt1, "%.02f", (double)(unsigned int)dword_8F1430 * 0.00000095367432);
          _sprintf(txt2, "%7s MB", txt1);
          QuickWindow::RenderText(v4, 172, v1->m_CurrentYPixel, txt2, v2);
          goto LABEL_29;
        }
        if ( v44 == v1->m_BlockResourcesStatsWindowHandle )
          break;
        if ( v44 == v1->m_DBObjStatsWindowHandle )
        {
          LODWORD(v91.r) = 1041865114;
          LODWORD(v91.g) = 1048576000;
          LODWORD(v91.b) = 1041865114;
          LODWORD(v91.a) = 1065353216;
          _sprintf(txt1, "[%s]", "Database Objects");
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
          v1->m_CurrentYPixel += 16;
          v74 = RGBAColor::GetColor32(&v91);
          QuickWindow::RenderText(v4, 128, v1->m_CurrentYPixel, "referenced  free", v74);
          v75 = v1->m_CurrentYPixel + 12;
          v1->m_CurrentYPixel = v75;
          CurrentLocalTime = Timer::local_time;
          v76 = v75;
          Indexa = 0;
          if ( v1->m_DBObjStats.m_num )
          {
            TotalMeshMemory = 0;
            do
            {
              DBObjStata = &v1->m_DBObjStats.m_data[TotalMeshMemory];
              if ( CurrentLocalTime - DBObjStata->LastLocalTimeNotEmpty < 3.0 )
              {
                v77 = CurrentLocalTime - DBObjStata->LastLocalTimeChanged;
                v78 = -6710887;
                MyItemValueColor = -5066062;
                if ( v77 >= 1.0 )
                {
                  if ( v77 < 3.0 )
                  {
                    v78 = -3355444;
                    MyItemValueColor = v2;
                  }
                }
                else
                {
                  v78 = -1;
                  MyItemValueColor = -1;
                }
                QuickWindow::RenderText(v4, 0, v76, DBObjStata->DBTypeName.m_charbuffer->m_data, v78);
                _sprintf(txt1, "%9i", DBObjStata->NumActive);
                QuickWindow::RenderText(v4, 140, v1->m_CurrentYPixel, txt1, MyItemValueColor);
                _sprintf(txt1, "%9i", DBObjStata->NumFree);
                QuickWindow::RenderText(v4, 180, v1->m_CurrentYPixel, txt1, MyItemValueColor);
                v79 = v1->m_CurrentYPixel + 12;
                v1->m_CurrentYPixel = v79;
                v76 = v79;
              }
              ++TotalMeshMemory;
              ++Indexa;
            }
            while ( Indexa < v1->m_DBObjStats.m_num );
          }
          goto LABEL_31;
        }
        if ( v44 == v1->m_MemoryProbeStatsWindowHandle )
        {
          _sprintf(txt1, "[%s]", "Memory Probe");
          QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
          v80 = v1->m_CurrentYPixel + 16;
          v1->m_CurrentYPixel = v80;
          QuickWindow::RenderText(v4, 0, v80, "CodeProbe disabled by #define", 0xFFFFFFFF);
LABEL_29:
          v43 = v1->m_CurrentYPixel + 12;
LABEL_30:
          v1->m_CurrentYPixel = v43;
        }
LABEL_31:
        ++WindowIndex;
        if ( WindowIndex >= v1->m_Windows.m_num )
          goto LABEL_32;
      }
      _sprintf(txt1, "[%s]", "Block Resources");
      QuickWindow::RenderText(v4, 0, v1->m_CurrentYPixel, txt1, 0xFF000000);
      v43 = v1->m_CurrentYPixel + 16;
      goto LABEL_30;
    }
LABEL_32:
    ((void (*)(void))v1->m_pToggleToolbarWindow->vfptr[1].__vecDelDtor)();
    ((void (*)(void))v1->m_pStatsToolbarWindow->vfptr[1].__vecDelDtor)();
    v81 = 0;
    if ( v1->m_ToolbarButtons.m_num )
    {
      do
        ((void (*)(void))v1->m_ToolbarButtons.m_data[v81++]->vfptr[1].__vecDelDtor)();
      while ( v81 < v1->m_ToolbarButtons.m_num );
    }
    ((void (*)(void))v1->m_pCategoryWindow->vfptr[1].__vecDelDtor)();
    v82 = 0;
    if ( v1->m_CategoryButtons.m_num )
    {
      do
        ((void (*)(void))v1->m_CategoryButtons.m_data[v82++]->vfptr[1].__vecDelDtor)();
      while ( v82 < v1->m_CategoryButtons.m_num );
    }
    RenderDeviceD3D::EndRenderingDebugText((RenderDeviceD3D *)RenderDevice::render_device);
    RenderDeviceD3D::SetFillMode(
      (RenderDeviceD3D *)RenderDevice::render_device,
      (FillModeType)(3 - (RenderDevice::render_device->m_WireframeMode != 0)));
  }
}
// 823A60: using guessed type const char **gc_CategoryNames;
// 823A64: using guessed type char *off_823A64;
// 823A68: using guessed type char *off_823A68;
// 823A6C: using guessed type char *off_823A6C;
// 823A70: using guessed type char *off_823A70;
// 8F13E0: using guessed type struct ProfilerStats Profiler::CapturedStats;
// 8F13E8: using guessed type int dword_8F13E8;
// 8F13EC: using guessed type int dword_8F13EC;
// 8F13F0: using guessed type int dword_8F13F0;
// 8F13F4: using guessed type int dword_8F13F4;
// 8F13F8: using guessed type int dword_8F13F8;
// 8F13FC: using guessed type int dword_8F13FC;
// 8F1400: using guessed type int dword_8F1400;
// 8F1404: using guessed type int dword_8F1404;
// 8F1408: using guessed type int dword_8F1408;
// 8F140C: using guessed type int dword_8F140C;
// 8F1410: using guessed type int dword_8F1410;
// 8F1414: using guessed type int dword_8F1414;
// 8F1418: using guessed type int dword_8F1418;
// 8F1420: using guessed type int dword_8F1420;
// 8F1424: using guessed type int dword_8F1424;
// 8F142C: using guessed type int dword_8F142C;
// 8F1430: using guessed type int dword_8F1430;
// 8F1434: using guessed type int dword_8F1434;
// 8F1438: using guessed type int dword_8F1438;

//----- (005DB630) --------------------------------------------------------  // acclient.c:518283
char __thiscall ProfilerUI::AddWindow(ProfilerUI *this, ProfilerTypes::CategoryType _Category, RGBAColor *_BackgroundColor, const bool _AutoPositionWindow, const unsigned int _X, const unsigned int _Y, const unsigned int _Width, const unsigned int _Height, unsigned int *o_WindowHandle)
{
  unsigned int *v9; // esi@1
  const unsigned int v10; // ST14_4@1
  ProfilerUI *v11; // ebp@1
  ProfilerUIWindow *v12; // edi@1
  void *v13; // eax@2
  int v14; // ecx@3
  int v15; // eax@4
  unsigned int v16; // eax@5
  char result; // al@7

  v9 = o_WindowHandle;
  v10 = _Height;
  v11 = this;
  v12 = 0;
  *o_WindowHandle = 0;
  o_WindowHandle = 0;
  if ( (QuickWindow::Create((TResult *)&_Height, (QuickWindow **)&o_WindowHandle, _X, _Y, _Width, v10, 6u, 4u)->m_val & 0x80000000) != 0 )
  {
    result = 0;
  }
  else
  {
    QuickWindow::SetColorAndOpacity((QuickWindow *)o_WindowHandle, _BackgroundColor);
    v13 = operator new(0x10u);
    if ( v13 )
    {
      *((_DWORD *)v13 + 3) = o_WindowHandle;
      v14 = dword_823B10;
      *((_BYTE *)v13 + 4) = _AutoPositionWindow;
      *(_DWORD *)v13 = v14;
      *((_DWORD *)v13 + 2) = _Category;
      *v9 = v14;
      dword_823B10 = v14 + 1;
      v12 = (ProfilerUIWindow *)v13;
    }
    v15 = v11->m_Windows.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( v11->m_Windows.m_num < v15
      || (v16 = SmartArray<UIChildFramework *,1>::get_new_size(v15 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v11->m_Windows, v16)) )
      v11->m_Windows.m_data[v11->m_Windows.m_num++] = v12;
    ProfilerUI::RepositionWindows(v11);
    result = 1;
  }
  return result;
}
// 823B10: using guessed type int dword_823B10;

//----- (005DB710) --------------------------------------------------------  // acclient.c:518333
void __thiscall ProfilerUI::RebuildToolbarButtons(ProfilerUI *this)
{
  unsigned int v1; // esi@1
  QuickButton *v2; // eax@2
  unsigned int v4; // eax@7
  char *v5; // esi@7
  unsigned int v6; // edx@7
  int i; // eax@10
  unsigned int v8; // eax@12
  int v9; // ebp@12
  const char *v10; // esi@13
  bool v11; // bl@17
  char *v12; // esi@17
  int v13; // eax@21
  unsigned int v14; // edx@22
  unsigned int v19; // ebp@32
  const char *v20; // esi@33
  bool v21; // bl@37
  char *v22; // esi@37
  int v23; // eax@41
  unsigned int v24; // edx@42
  PSRefBufferCharData<char> *v26; // edi@52
  int v27; // ebp@52
  const char *v28; // esi@53
  bool v29; // bl@57
  unsigned int v30; // esi@57
  int v31; // eax@61
  unsigned int v32; // edx@62
  ProfilerUI *v34; // [sp+10h] [bp-40h]@1
  QuickButton *pNewButton; // [sp+14h] [bp-3Ch]@13
  PStringBase<char> _ButtonLabel; // [sp+18h] [bp-38h]@15
  unsigned int c; // [sp+1Ch] [bp-34h]@12
  const unsigned int ToolbarButtonWidth; // [sp+20h] [bp-30h]@12
  unsigned int _Width; // [sp+24h] [bp-2Ch]@27
  TResult result; // [sp+28h] [bp-28h]@17
  RGBAColor _ColorAndOpacity; // [sp+2Ch] [bp-24h]@21
  const char *GraphicsQualityLevelNames[5]; // [sp+3Ch] [bp-14h]@32

  v34 = this;
  v1 = 0;
  if ( this->m_ToolbarButtons.m_num )
  {
    do
    {
      v2 = this->m_ToolbarButtons.m_data[v1];
      if ( v2 )
      {
        _ZF = v2->m_cRef-- == 1;
        if ( _ZF )
          v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v2, 1u);
        v34->m_ToolbarButtons.m_data[v1] = 0;
        this = v34;
      }
      ++v1;
    }
    while ( v1 < this->m_ToolbarButtons.m_num );
  }
  v4 = this->m_ToolbarButtons.m_sizeAndDeallocate;
  v5 = (char *)&this->m_ToolbarButtons;
  v6 = this->m_ToolbarButtons.m_sizeAndDeallocate & 0x80000000;
  this->m_ToolbarButtons.m_num = 0;
  if ( v6 == 0x80000000 )
  {
    operator delete[](*(void **)v5);
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
  }
  else if ( *(_DWORD *)v5 )
  {
    for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; *(_DWORD *)(*(_DWORD *)v5 + 4 * i + 4) = 0 )
      --i;
  }
  v8 = 0;
  ToolbarButtonWidth = v34->m_pToggleToolbarWindow->m_ClientAreaWidth;
  c = 0;
  v9 = 0;
  do
  {
    v10 = (const char *)(&gc_ToolbarToggleButtonNames)[v8];
    pNewButton = 0;
    if ( v10 && *v10 )
    {
      PStringBase<char>::allocate_ref_buffer(&_ButtonLabel, strlen(v10));
      strcpy(_ButtonLabel.m_charbuffer->m_data, v10);
    }
    else
    {
      _ButtonLabel.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    }
    v11 = (QuickButton::Create(
             &result,
             &pNewButton,
             v34->m_pToggleToolbarWindow->m_ClientAreaX,
             v9 + v34->m_pToggleToolbarWindow->m_ClientAreaY,
             ToolbarButtonWidth,
             0x14u,
             4u,
             2u,
             &_ButtonLabel)->m_val & 0x80000000) == 0;
    v12 = &_ButtonLabel.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_ButtonLabel.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    if ( v11 )
    {
      QuickWindow::SetWindowID((InterpolationManager *)pNewButton, (CPhysicsObj *)(c + 20));
      LODWORD(_ColorAndOpacity.r) = 1056997505;
      LODWORD(_ColorAndOpacity.g) = 1057655435;
      LODWORD(_ColorAndOpacity.b) = 1055319783;
      LODWORD(_ColorAndOpacity.a) = 1060320051;
      QuickWindow::SetColorAndOpacity((QuickWindow *)&pNewButton->vfptr, &_ColorAndOpacity);
      v13 = v34->m_ToolbarButtons.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v34->m_ToolbarButtons.m_num < v13 )
        goto LABEL_75;
      v14 = v13 + 1;
      if ( (unsigned int)(v13 + 1) > 8 )
      {
        if ( v14 <= 0x4000 )
        {
          _Width = v13 + 1;
          __asm { bsr     this, [esp+50h+_Width] }
          if ( v14 > 1 << _EAX )
            v14 = 2 * (1 << _EAX);
        }
        else if ( v14 & 0x3FFF )
        {
          v14 += 0x4000 - (v14 & 0x3FFF);
        }
      }
      else
      {
        v14 = 8;
      }
      if ( SmartArray<int,1>::grow(&v34->m_ToolbarButtons, v14) )
LABEL_75:
        v34->m_ToolbarButtons.m_data[v34->m_ToolbarButtons.m_num++] = pNewButton;
    }
    v8 = c + 1;
    v9 += 20;
    ++c;
  }
  while ( c < 3 );
  v19 = 0;
  GraphicsQualityLevelNames[0] = "VL";
  GraphicsQualityLevelNames[1] = "L";
  GraphicsQualityLevelNames[2] = "M";
  GraphicsQualityLevelNames[3] = "H";
  GraphicsQualityLevelNames[4] = "VH";
  c = 0;
  do
  {
    v20 = GraphicsQualityLevelNames[c];
    pNewButton = 0;
    if ( v20 && *v20 )
    {
      PStringBase<char>::allocate_ref_buffer(&_ButtonLabel, strlen(v20));
      strcpy(_ButtonLabel.m_charbuffer->m_data, v20);
    }
    else
    {
      _ButtonLabel.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    }
    v21 = (QuickButton::Create(
             &result,
             &pNewButton,
             v19 + v34->m_pToggleToolbarWindow->m_ClientAreaX,
             v34->m_pToggleToolbarWindow->m_ClientAreaY + 142,
             0x1Bu,
             0x14u,
             4u,
             2u,
             &_ButtonLabel)->m_val & 0x80000000) == 0;
    v22 = &_ButtonLabel.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_ButtonLabel.m_charbuffer[-1]) && v22 )
      (**(void (__thiscall ***)(char *, signed int))v22)(v22, 1);
    if ( v21 )
    {
      QuickWindow::SetWindowID((InterpolationManager *)pNewButton, (CPhysicsObj *)(c + 10));
      LODWORD(_ColorAndOpacity.r) = 1056997505;
      LODWORD(_ColorAndOpacity.g) = 1057655435;
      LODWORD(_ColorAndOpacity.b) = 1055319783;
      LODWORD(_ColorAndOpacity.a) = 1060320051;
      QuickWindow::SetColorAndOpacity((QuickWindow *)&pNewButton->vfptr, &_ColorAndOpacity);
      v23 = v34->m_ToolbarButtons.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v34->m_ToolbarButtons.m_num < v23 )
        goto LABEL_76;
      v24 = v23 + 1;
      if ( (unsigned int)(v23 + 1) > 8 )
      {
        if ( v24 <= 0x4000 )
        {
          _Width = v23 + 1;
          __asm { bsr     this, [esp+50h+_Width] }
          if ( v24 > 1 << _EAX )
            v24 = 2 * (1 << _EAX);
        }
        else if ( v24 & 0x3FFF )
        {
          v24 += 0x4000 - (v24 & 0x3FFF);
        }
      }
      else
      {
        v24 = 8;
      }
      if ( SmartArray<int,1>::grow(&v34->m_ToolbarButtons, v24) )
LABEL_76:
        v34->m_ToolbarButtons.m_data[v34->m_ToolbarButtons.m_num++] = pNewButton;
    }
    v19 += 27;
    ++c;
  }
  while ( v19 < 0x87 );
  v26 = 0;
  _Width = v34->m_pStatsToolbarWindow->m_ClientAreaWidth;
  _ButtonLabel.m_charbuffer = 0;
  v27 = 0;
  do
  {
    v28 = (const char *)(&gc_ToolbarStatsButtonNames)[(_DWORD)v26];
    pNewButton = 0;
    if ( v28 && *v28 )
    {
      PStringBase<char>::allocate_ref_buffer((PStringBase<char> *)&c, strlen(v28));
      strcpy((char *)c, v28);
    }
    else
    {
      c = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    }
    v29 = (QuickButton::Create(
             &result,
             &pNewButton,
             v34->m_pStatsToolbarWindow->m_ClientAreaX,
             v27 + v34->m_pStatsToolbarWindow->m_ClientAreaY,
             _Width,
             0x14u,
             4u,
             2u,
             (PStringBase<char> *)&c)->m_val & 0x80000000) == 0;
    v30 = c - 20;
    if ( !InterlockedDecrement((volatile LONG *)(c - 20 + 4)) && v30 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    if ( v29 )
    {
      QuickWindow::SetWindowID((InterpolationManager *)pNewButton, (CPhysicsObj *)&v26[1].m_data[14]);
      LODWORD(_ColorAndOpacity.r) = 1056997505;
      LODWORD(_ColorAndOpacity.g) = 1057655435;
      LODWORD(_ColorAndOpacity.b) = 1055319783;
      LODWORD(_ColorAndOpacity.a) = 1060320051;
      QuickWindow::SetColorAndOpacity((QuickWindow *)&pNewButton->vfptr, &_ColorAndOpacity);
      v31 = v34->m_ToolbarButtons.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v34->m_ToolbarButtons.m_num < v31 )
        goto LABEL_77;
      v32 = v31 + 1;
      if ( (unsigned int)(v31 + 1) > 8 )
      {
        if ( v32 <= 0x4000 )
        {
          ToolbarButtonWidth = v31 + 1;
          __asm { bsr     this, [esp+50h+ToolbarButtonWidth] }
          if ( v32 > 1 << _EAX )
            v32 = 2 * (1 << _EAX);
        }
        else if ( v32 & 0x3FFF )
        {
          v32 += 0x4000 - (v32 & 0x3FFF);
        }
      }
      else
      {
        v32 = 8;
      }
      if ( SmartArray<int,1>::grow(&v34->m_ToolbarButtons, v32) )
LABEL_77:
        v34->m_ToolbarButtons.m_data[v34->m_ToolbarButtons.m_num++] = pNewButton;
      v26 = _ButtonLabel.m_charbuffer;
    }
    v26 = (PSRefBufferCharData<char> *)((char *)v26 + 1);
    v27 += 20;
    _ButtonLabel.m_charbuffer = v26;
  }
  while ( (unsigned int)v26 < 4 );
}
// 823A74: using guessed type const char **gc_ToolbarToggleButtonNames;
// 823A80: using guessed type const char **gc_ToolbarStatsButtonNames;

//----- (005DBCC0) --------------------------------------------------------  // acclient.c:518623
void __thiscall ProfilerUI::RebuildCategoryWindow(ProfilerUI *this)
{
  unsigned int v1; // esi@1
  QuickButton *v2; // eax@2
  unsigned int v4; // eax@7
  char *v5; // esi@7
  unsigned int v6; // edx@7
  unsigned int v7; // edi@8
  int v8; // ebp@8
  int i; // eax@10
  const char *v10; // esi@13
  int v11; // ebx@17
  char *v12; // esi@17
  unsigned int v13; // edx@21
  unsigned int v14; // eax@21
  ProfilerUIWindow **v15; // ecx@22
  int v16; // eax@26
  unsigned int v17; // edx@27
  ProfilerUI *v22; // [sp+10h] [bp-2Ch]@1
  QuickButton *pNewButton; // [sp+14h] [bp-28h]@13
  PStringBase<char> _ButtonLabel; // [sp+18h] [bp-24h]@15
  unsigned int c; // [sp+1Ch] [bp-20h]@8
  bool _IsChecked[4]; // [sp+20h] [bp-1Ch]@25
  int v27; // [sp+24h] [bp-18h]@33
  TResult result; // [sp+28h] [bp-14h]@17
  RGBAColor _ColorAndOpacity; // [sp+2Ch] [bp-10h]@21

  v22 = this;
  v1 = 0;
  if ( this->m_CategoryButtons.m_num )
  {
    do
    {
      v2 = this->m_CategoryButtons.m_data[v1];
      if ( v2 )
      {
        _ZF = v2->m_cRef-- == 1;
        if ( _ZF )
          v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,1> *)v2, 1u);
        v22->m_CategoryButtons.m_data[v1] = 0;
        this = v22;
      }
      ++v1;
    }
    while ( v1 < this->m_CategoryButtons.m_num );
  }
  v4 = this->m_CategoryButtons.m_sizeAndDeallocate;
  v5 = (char *)&this->m_CategoryButtons;
  v6 = this->m_CategoryButtons.m_sizeAndDeallocate & 0x80000000;
  this->m_CategoryButtons.m_num = 0;
  if ( v6 == 0x80000000 )
  {
    operator delete[](*(void **)v5);
    v7 = 0;
    *(_DWORD *)v5 = 0;
    *((_DWORD *)v5 + 1) = 0;
    c = 0;
    v8 = 0;
  }
  else
  {
    if ( *(_DWORD *)v5 )
    {
      for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; *(_DWORD *)(*(_DWORD *)v5 + 4 * i + 4) = 0 )
        --i;
    }
    v7 = 0;
    c = 0;
    v8 = 0;
  }
  do
  {
    v10 = (const char *)(&gc_CategoryNames)[v7];
    pNewButton = 0;
    if ( v10 && *v10 )
    {
      PStringBase<char>::allocate_ref_buffer(&_ButtonLabel, strlen(v10));
      strcpy(_ButtonLabel.m_charbuffer->m_data, v10);
    }
    else
    {
      _ButtonLabel.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    }
    v11 = (QuickButton::Create(
             &result,
             &pNewButton,
             v22->m_pCategoryWindow->m_ClientAreaX,
             v22->m_pCategoryWindow->m_ClientAreaY + v8,
             v22->m_pCategoryWindow->m_ClientAreaWidth,
             0x14u,
             4u,
             2u,
             &_ButtonLabel)->m_val & 0x80000000) == 0;
    v12 = &_ButtonLabel.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&_ButtonLabel.m_charbuffer[-1]) && v12 )
      (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
    if ( (_BYTE)v11 )
    {
      LODWORD(_ColorAndOpacity.r) = 1056997505;
      LODWORD(_ColorAndOpacity.g) = 1057655435;
      LODWORD(_ColorAndOpacity.b) = 1055319783;
      LODWORD(_ColorAndOpacity.a) = 1060320051;
      QuickWindow::SetColorAndOpacity((QuickWindow *)&pNewButton->vfptr, &_ColorAndOpacity);
      v13 = v22->m_Windows.m_num;
      v14 = 0;
      if ( v13 )
      {
        v15 = v22->m_Windows.m_data;
        while ( (*v15)->m_Category != v7 )
        {
          ++v14;
          ++v15;
          if ( v14 >= v13 )
            goto LABEL_25;
        }
        _IsChecked[0] = 1;
      }
      else
      {
LABEL_25:
        _IsChecked[0] = 0;
      }
      QuickButton::SetCheckedState(pNewButton, _IsChecked[0]);
      v16 = v22->m_CategoryButtons.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v22->m_CategoryButtons.m_num < v16 )
        goto LABEL_41;
      v17 = v16 + 1;
      if ( (unsigned int)(v16 + 1) > 8 )
      {
        if ( v17 <= 0x4000 )
        {
          v27 = v16 + 1;
          __asm { bsr     this, [esp+3Ch+var_18] }
          if ( v17 > 1 << _EAX )
            v17 = 2 * (1 << _EAX);
        }
        else if ( v17 & 0x3FFF )
        {
          v17 += 0x4000 - (v17 & 0x3FFF);
        }
      }
      else
      {
        v17 = 8;
      }
      if ( SmartArray<int,1>::grow(&v22->m_CategoryButtons, v17) )
LABEL_41:
        v22->m_CategoryButtons.m_data[v22->m_CategoryButtons.m_num++] = pNewButton;
      v7 = c;
    }
    ++v7;
    v8 += 20;
    c = v7;
  }
  while ( v7 < 5 );
}
// 823A60: using guessed type const char **gc_CategoryNames;

//----- (005DBF20) --------------------------------------------------------  // acclient.c:518783
void __thiscall SmartArray<BudgetStatItem,1>::Reset(SmartArray<BudgetStatItem,1> *this)
{
  SmartArray<BudgetStatItem,1> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  BudgetStatItem *v6; // esi@8
  int v7; // esi@8
  char *v8; // esi@8
  int v9; // [sp+8h] [bp-28h]@7
  PStringBase<char> v10; // [sp+Ch] [bp-24h]@8
  int v11; // [sp+10h] [bp-20h]@8
  int v12; // [sp+14h] [bp-1Ch]@8
  int v13; // [sp+18h] [bp-18h]@8
  int v14; // [sp+1Ch] [bp-14h]@8
  int v15; // [sp+20h] [bp-10h]@8
  char v16; // [sp+24h] [bp-Ch]@8
  int v17; // [sp+28h] [bp-8h]@8
  int v18; // [sp+2Ch] [bp-4h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      BudgetStatItem::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v9 = v4 + 1;
      do
      {
        PStringBase<char>::PStringBase<char>(&v10, &name);
        v6 = v1->m_data;
        v11 = 0;
        v12 = 0;
        v13 = 0;
        v14 = 0;
        v7 = (int)&v6[v5];
        v16 = 0;
        v15 = 0;
        BudgetStatInfo::operator=((void *)v7, (int)&v10);
        *(_DWORD *)(v7 + 28) = v17;
        *(_DWORD *)(v7 + 32) = v18;
        v8 = &v10.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&v10.m_charbuffer[-1]) && v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
        --v5;
        --v9;
      }
      while ( v9 );
    }
  }
}

//----- (005DC000) --------------------------------------------------------  // acclient.c:518848
char __thiscall SmartArray<ProfilerDBObjStat,1>::InsertOrderedByIndex(SmartArray<ProfilerDBObjStat,1> *this, ProfilerDBObjStat *i_rData, unsigned int index)
{
  SmartArray<ProfilerDBObjStat,1> *v3; // ebx@1
  unsigned int v4; // ecx@1
  int v5; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // eax@4
  unsigned int v8; // edi@5
  int i; // esi@5
  char result; // al@7

  v3 = this;
  v4 = this->m_num;
  if ( index <= v4
    && ((v5 = v3->m_sizeAndDeallocate & 0x7FFFFFFF, v4 < v5)
     || (v6 = SmartArray<UIChildFramework *,1>::get_new_size(v5 + 1), SmartArray<ProfilerDBObjStat,1>::grow(v3, v6))) )
  {
    v7 = v3->m_num;
    if ( v7 )
    {
      v8 = (unsigned int)&v3->m_data[index].DBType;
      for ( i = (int)&v3->m_data[v7 - 1]; i >= v8; i -= 32 )
        ProfilerDBObjStat::operator=(i + 32, i);
    }
    ProfilerDBObjStat::operator=((int)&v3->m_data[index], (int)i_rData);
    ++v3->m_num;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005DC090) --------------------------------------------------------  // acclient.c:518884
char __thiscall SmartArray<BudgetStatItem,1>::grow(SmartArray<BudgetStatItem,1> *this, unsigned int i_nSize)
{
  SmartArray<BudgetStatItem,1> *v2; // ebx@1
  unsigned int v3; // edi@1
  void *v5; // eax@5
  int v6; // esi@6
  int v7; // eax@8
  int v8; // ebp@9
  int v9; // edi@9
  int v10; // esi@10
  unsigned int v11; // [sp+Ch] [bp-8h]@9
  int v12; // [sp+10h] [bp-4h]@6

  v2 = this;
  v3 = i_nSize;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<BudgetStatItem,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](36 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      v12 = (int)((char *)v5 + 4);
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x24u,
        i_nSize,
        (void *(__thiscall *)(void *))BudgetStatItem::BudgetStatItem);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = -32 - v6;
            v9 = v6 + 36 * v7 + 32;
            v11 = v2->m_num;
            do
            {
              v10 = (int)((char *)v2->m_data + v9 + v8);
              BudgetStatInfo::operator=((void *)(v9 - 32), v10);
              *(_DWORD *)(v9 - 4) = *(_DWORD *)(v10 + 28);
              *(_DWORD *)v9 = *(_DWORD *)(v10 + 32);
              v9 -= 36;
              --v11;
            }
            while ( v11 );
            v6 = v12;
            v3 = i_nSize;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              BudgetStatItem::vector_deleting_destructor(v2->m_data, 3u);
          }
        }
        v2->m_data = (BudgetStatItem *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (005DC1A0) --------------------------------------------------------  // acclient.c:518958
void __thiscall ProfilerUI::ProfilerUI(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1

  v1 = this;
  this->m_cRef = 1;
  this->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ProfilerUI::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&ProfilerUI::vftable;
  this->m_IsActive = 0;
  this->m_WantActivate = 0;
  this->m_WantDeactivate = 0;
  this->m_Windows.m_data = 0;
  this->m_Windows.m_sizeAndDeallocate = 0;
  this->m_Windows.m_num = 0;
  this->m_MemoryCountersStatsWindowHandle = 0;
  this->m_BlockResourcesStatsWindowHandle = 0;
  this->m_DBObjStatsWindowHandle = 0;
  this->m_DPVSStatsWindowHandle = 0;
  this->m_MemoryProbeStatsWindowHandle = 0;
  this->m_pToggleToolbarWindow = 0;
  this->m_pStatsToolbarWindow = 0;
  this->m_pCategoryWindow = 0;
  this->m_ToolbarButtons.m_data = 0;
  this->m_ToolbarButtons.m_sizeAndDeallocate = 0;
  this->m_ToolbarButtons.m_num = 0;
  this->m_CategoryButtons.m_data = 0;
  this->m_CategoryButtons.m_sizeAndDeallocate = 0;
  this->m_CategoryButtons.m_num = 0;
  this->m_nGraphicsQualityLevel = 0;
  this->m_budgetStatArray.m_data = 0;
  this->m_budgetStatArray.m_sizeAndDeallocate = 0;
  this->m_budgetStatArray.m_num = 0;
  this->m_CurrentYPixel = 0;
  this->m_nSystemMemoryAllocated = 0;
  this->m_nPeakSystemMemoryAllocated = 0;
  this->m_nVirtualMemoryReserved = 0;
  this->m_nPeakVirtualMemoryReserved = 0;
  this->m_DBObjStats.m_data = 0;
  this->m_DBObjStats.m_sizeAndDeallocate = 0;
  this->m_DBObjStats.m_num = 0;
  this->m_pOSSpecificProfiler = 0;
  SmartArray<BudgetStatItem,1>::Reset(&this->m_budgetStatArray);
  ProfilerUI::RegisterInputMaps(v1);
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 7E9400: using guessed type void *ProfilerUI::vftable;
// 7E940C: using guessed type int (__thiscall *ProfilerUI::vftable)(void *, char);

//----- (005DC240) --------------------------------------------------------  // acclient.c:519008
ProfilerUI *__thiscall ProfilerUI::vector_deleting_destructor(ProfilerUI *this, unsigned int a2)
{
  return ProfilerUI::vector_deleting_destructor((ProfilerUI *)((char *)this - 8), a2);
}

//----- (005DC250) --------------------------------------------------------  // acclient.c:519014
void __thiscall ProfilerUI::~ProfilerUI(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebp@1
  ProfilerUIWindow *v4; // edi@2
  QuickWindow *v5; // ecx@3
  bool v6; // zf@4
  unsigned int v7; // eax@9
  unsigned int v8; // ecx@9
  int i; // eax@12
  unsigned int j; // edi@14
  QuickButton *v11; // ecx@15
  unsigned int v12; // eax@20
  unsigned int v13; // edx@20
  int k; // eax@23
  QuickWindow *v15; // ecx@25
  QuickWindow *v16; // ecx@29
  unsigned int l; // edi@33
  QuickButton *v18; // ecx@34
  unsigned int v19; // eax@39
  unsigned int v20; // ecx@39
  int m; // eax@42
  QuickWindow *v22; // ecx@44
  int v23; // ebx@48
  ProfilerDBObjStat *v24; // edi@49
  void *v25; // edx@50
  int v26; // ebp@51
  int v27; // edi@52
  int v28; // edi@52
  int v29; // ecx@59
  int v30; // eax@60
  void *v31; // ebx@60
  int v32; // edx@60
  int v33; // eax@60
  int v34; // ebp@60
  int v35; // edi@62
  int v36; // edi@62
  int v37; // [sp+20h] [bp-8h]@51
  int v38; // [sp+20h] [bp-8h]@61
  int v39; // [sp+24h] [bp-4h]@50

  v1 = this;
  v2 = this->m_Windows.m_num;
  v3 = 0;
  this->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)&ProfilerUI::vftable;
  this->vfptr = (IInputActionCallbackVtbl *)&ProfilerUI::vftable;
  this->m_IsActive = 0;
  if ( v2 )
  {
    do
    {
      v4 = v1->m_Windows.m_data[v3];
      if ( v4 )
      {
        v5 = v4->m_pQuickWindow;
        if ( v5 )
        {
          v6 = v5->m_cRef-- == 1;
          if ( v6 )
            ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
          v4->m_pQuickWindow = 0;
        }
        operator delete(v4);
      }
      v1->m_Windows.m_data[v3++] = 0;
    }
    while ( v3 < v1->m_Windows.m_num );
  }
  v7 = v1->m_Windows.m_sizeAndDeallocate;
  v8 = v1->m_Windows.m_sizeAndDeallocate & 0x80000000;
  v1->m_Windows.m_num = 0;
  if ( v8 == 0x80000000 )
  {
    operator delete[](v1->m_Windows.m_data);
    v1->m_Windows.m_data = 0;
    v1->m_Windows.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_Windows.m_data )
  {
    for ( i = (v7 & 0x7FFFFFFF) - 1; i >= 0; v1->m_Windows.m_data[i + 1] = 0 )
      --i;
  }
  for ( j = 0; j < v1->m_ToolbarButtons.m_num; ++j )
  {
    v11 = v1->m_ToolbarButtons.m_data[j];
    if ( v11 )
    {
      v6 = v11->m_cRef-- == 1;
      if ( v6 )
        ((void (__stdcall *)(signed int))v11->vfptr->__vecDelDtor)(1);
      v1->m_ToolbarButtons.m_data[j] = 0;
    }
  }
  v12 = v1->m_ToolbarButtons.m_sizeAndDeallocate;
  v13 = v1->m_ToolbarButtons.m_sizeAndDeallocate & 0x80000000;
  v1->m_ToolbarButtons.m_num = 0;
  if ( v13 == 0x80000000 )
  {
    operator delete[](v1->m_ToolbarButtons.m_data);
    v1->m_ToolbarButtons.m_data = 0;
    v1->m_ToolbarButtons.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_ToolbarButtons.m_data )
  {
    for ( k = (v12 & 0x7FFFFFFF) - 1; k >= 0; v1->m_ToolbarButtons.m_data[k + 1] = 0 )
      --k;
  }
  v15 = v1->m_pToggleToolbarWindow;
  if ( v15 )
  {
    v6 = v15->m_cRef-- == 1;
    if ( v6 )
      ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    v1->m_pToggleToolbarWindow = 0;
  }
  v16 = v1->m_pStatsToolbarWindow;
  if ( v16 )
  {
    v6 = v16->m_cRef-- == 1;
    if ( v6 )
      ((void (__stdcall *)(signed int))v16->vfptr->__vecDelDtor)(1);
    v1->m_pStatsToolbarWindow = 0;
  }
  for ( l = 0; l < v1->m_CategoryButtons.m_num; ++l )
  {
    v18 = v1->m_CategoryButtons.m_data[l];
    if ( v18 )
    {
      v6 = v18->m_cRef-- == 1;
      if ( v6 )
        ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
      v1->m_CategoryButtons.m_data[l] = 0;
    }
  }
  v19 = v1->m_CategoryButtons.m_sizeAndDeallocate;
  v20 = v1->m_CategoryButtons.m_sizeAndDeallocate & 0x80000000;
  v1->m_CategoryButtons.m_num = 0;
  if ( v20 == 0x80000000 )
  {
    operator delete[](v1->m_CategoryButtons.m_data);
    v1->m_CategoryButtons.m_data = 0;
    v1->m_CategoryButtons.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_CategoryButtons.m_data )
  {
    for ( m = (v19 & 0x7FFFFFFF) - 1; m >= 0; v1->m_CategoryButtons.m_data[m + 1] = 0 )
      --m;
  }
  v22 = v1->m_pCategoryWindow;
  if ( v22 )
  {
    v6 = v22->m_cRef-- == 1;
    if ( v6 )
      ((void (__stdcall *)(signed int))v22->vfptr->__vecDelDtor)(1);
    v1->m_pCategoryWindow = 0;
  }
  v23 = (int)&v1->m_budgetStatArray;
  SmartArray<BudgetStatItem,1>::Reset(&v1->m_budgetStatArray);
  SmartArray<ProfilerDBObjStat,1>::Reset(&v1->m_DBObjStats);
  operator delete(v1->m_pOSSpecificProfiler);
  v1->m_pOSSpecificProfiler = 0;
  if ( (v1->m_DBObjStats.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v24 = v1->m_DBObjStats.m_data;
    if ( v24 )
    {
      v25 = (char *)&v24[-1].LastLocalTimeChanged + 4;
      v39 = (int)((char *)&v24[-1].LastLocalTimeChanged + 4);
      if ( HIDWORD(v24[-1].LastLocalTimeChanged) - 1 >= 0 )
      {
        v26 = (int)&v24[HIDWORD(v24[-1].LastLocalTimeChanged)].DBTypeName;
        v37 = HIDWORD(v24[-1].LastLocalTimeChanged);
        do
        {
          v27 = *(_DWORD *)(v26 - 32);
          v26 -= 32;
          v28 = v27 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v28 + 4)) && v28 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v28)(v28, 1);
          --v37;
        }
        while ( v37 );
        v25 = (void *)v39;
      }
      operator delete[](v25);
    }
  }
  if ( (v1->m_budgetStatArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v29 = *(_DWORD *)v23;
    if ( *(_DWORD *)v23 )
    {
      v30 = *(_DWORD *)(v29 - 4);
      v31 = (void *)(v29 - 4);
      v32 = 9 * v30;
      v33 = v30 - 1;
      v34 = v29 + 4 * v32;
      if ( v33 >= 0 )
      {
        v38 = v33 + 1;
        do
        {
          v35 = *(_DWORD *)(v34 - 36);
          v34 -= 36;
          v36 = v35 - 20;
          if ( !InterlockedDecrement((volatile LONG *)(v36 + 4)) && v36 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v36)(v36, 1);
          --v38;
        }
        while ( v38 );
      }
      operator delete[](v31);
    }
  }
  if ( (v1->m_CategoryButtons.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_CategoryButtons.m_data);
  if ( (v1->m_ToolbarButtons.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_ToolbarButtons.m_data);
  if ( (v1->m_Windows.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_Windows.m_data);
  v1->vfptr = (IInputActionCallbackVtbl *)&IInputActionCallback::vftable;
  if ( ICIDM::s_cidm )
    ((void (__stdcall *)(IInputActionCallbackVtbl **))ICIDM::s_cidm->vfptr->UnregisterCallback)(&v1->vfptr);
  v1->vfptr = (ReferenceCountTemplate<1048576,1>Vtbl *)ReferenceCountTemplate<1048576,1>::vftable;
}
// 794824: using guessed type int (__thiscall *IInputActionCallback::vftable)(void *, char);
// 795C4C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char);
// 7E9400: using guessed type void *ProfilerUI::vftable;
// 7E940C: using guessed type int (__thiscall *ProfilerUI::vftable)(void *, char);

//----- (005DC580) --------------------------------------------------------  // acclient.c:519246
char __thiscall ProfilerUI::CreateToolbarWindows(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  char *v2; // edi@1
  QuickWindow *v3; // ecx@2
  QuickWindow *v4; // ecx@3
  char v5; // al@3
  TResult result; // [sp+8h] [bp-14h]@1
  RGBAColor _ColorAndOpacity; // [sp+Ch] [bp-10h]@2

  v1 = this;
  v2 = (char *)&this->m_pToggleToolbarWindow;
  if ( (QuickWindow::Create(&result, &this->m_pToggleToolbarWindow, 8, 24, 0x9Au, 0xAAu, 6u, 4u)->m_val & 0x80000000) != 0
    || (v3 = *(QuickWindow **)v2,
        LODWORD(_ColorAndOpacity.r) = 1052951235,
        LODWORD(_ColorAndOpacity.g) = 1054003923,
        LODWORD(_ColorAndOpacity.b) = 1051766961,
        LODWORD(_ColorAndOpacity.a) = 1060320051,
        QuickWindow::SetColorAndOpacity(v3, &_ColorAndOpacity),
        (QuickWindow::Create(&result, &v1->m_pStatsToolbarWindow, 8, 224, 0x9Au, 0x5Cu, 6u, 4u)->m_val & 0x80000000) != 0) )
  {
    v5 = 0;
  }
  else
  {
    v4 = v1->m_pStatsToolbarWindow;
    LODWORD(_ColorAndOpacity.r) = 1052951235;
    LODWORD(_ColorAndOpacity.g) = 1054003923;
    LODWORD(_ColorAndOpacity.b) = 1051766961;
    LODWORD(_ColorAndOpacity.a) = 1060320051;
    QuickWindow::SetColorAndOpacity(v4, &_ColorAndOpacity);
    ProfilerUI::RebuildToolbarButtons(v1);
    v5 = 1;
  }
  return v5;
}

//----- (005DC650) --------------------------------------------------------  // acclient.c:519284
char __thiscall ProfilerUI::CreateCategoryWindow(ProfilerUI *this)
{
  ProfilerUI *v1; // esi@1
  char *v2; // edi@1
  QuickWindow *v3; // ecx@2
  char v4; // al@2
  TResult result; // [sp+8h] [bp-14h]@1
  RGBAColor _ColorAndOpacity; // [sp+Ch] [bp-10h]@2

  v1 = this;
  v2 = (char *)&this->m_pCategoryWindow;
  if ( (QuickWindow::Create(&result, &this->m_pCategoryWindow, 8, 350, 0x9Au, 0x96u, 6u, 4u)->m_val & 0x80000000) != 0 )
  {
    v4 = 0;
  }
  else
  {
    v3 = *(QuickWindow **)v2;
    LODWORD(_ColorAndOpacity.r) = 1052951235;
    LODWORD(_ColorAndOpacity.g) = 1054003923;
    LODWORD(_ColorAndOpacity.b) = 1051766961;
    LODWORD(_ColorAndOpacity.a) = 1060320051;
    QuickWindow::SetColorAndOpacity(v3, &_ColorAndOpacity);
    ProfilerUI::RebuildCategoryWindow(v1);
    v4 = 1;
  }
  return v4;
}

//----- (005DC6D0) --------------------------------------------------------  // acclient.c:519314
void __thiscall ProfilerUI::AddCategoryWindow(ProfilerUI *this, ProfilerTypes::CategoryType _Category)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  ProfilerUIWindow **v4; // esi@2
  const unsigned int v5; // eax@6
  RGBAColor WindowBackgroundColor; // [sp+Ch] [bp-10h]@5

  v2 = this->m_Windows.m_num;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->m_Windows.m_data;
    while ( (*v4)->m_Category != _Category )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    LODWORD(WindowBackgroundColor.a) = 1060320051;
    if ( _Category )
    {
      LODWORD(WindowBackgroundColor.r) = 1051372203;
      LODWORD(WindowBackgroundColor.g) = 1052951235;
      LODWORD(WindowBackgroundColor.b) = 1054398681;
      v5 = 160;
    }
    else
    {
      LODWORD(WindowBackgroundColor.r) = 1054003923;
      LODWORD(WindowBackgroundColor.g) = 1051766961;
      LODWORD(WindowBackgroundColor.b) = 1052556477;
      v5 = 460;
    }
    ProfilerUI::AddWindow(this, _Category, &WindowBackgroundColor, 1, 0, 0, 0x10Eu, v5, (unsigned int *)&_Category);
  }
}

//----- (005DC770) --------------------------------------------------------  // acclient.c:519358
void __thiscall ProfilerUI::ShowMemoryCountersStatsWindow(ProfilerUI *this, const bool _Show)
{
  ProfilerUI *v2; // esi@1
  RGBAColor WindowBackgroundColor; // [sp+4h] [bp-10h]@3

  v2 = this;
  if ( _Show )
  {
    if ( !this->m_MemoryCountersStatsWindowHandle )
    {
      LODWORD(WindowBackgroundColor.r) = 1054661853;
      LODWORD(WindowBackgroundColor.g) = 1054661853;
      LODWORD(WindowBackgroundColor.b) = 1054661853;
      LODWORD(WindowBackgroundColor.a) = 1060320051;
      ProfilerUI::AddWindow(
        this,
        MoveToObject,
        &WindowBackgroundColor,
        1,
        0,
        0,
        0x10Eu,
        0x168u,
        &this->m_MemoryCountersStatsWindowHandle);
    }
  }
  else if ( this->m_MemoryCountersStatsWindowHandle )
  {
    ProfilerUI::RemoveWindow(this, this->m_MemoryCountersStatsWindowHandle);
    v2->m_MemoryCountersStatsWindowHandle = 0;
  }
}

//----- (005DC7F0) --------------------------------------------------------  // acclient.c:519392
void __thiscall ProfilerUI::ShowBlockResourcesStatsWindow(ProfilerUI *this, const bool _Show)
{
  ProfilerUI *v2; // esi@1
  RGBAColor WindowBackgroundColor; // [sp+4h] [bp-10h]@3

  v2 = this;
  if ( _Show )
  {
    if ( !this->m_BlockResourcesStatsWindowHandle )
    {
      LODWORD(WindowBackgroundColor.r) = 1055977713;
      LODWORD(WindowBackgroundColor.g) = 1055977713;
      LODWORD(WindowBackgroundColor.b) = 1042325665;
      LODWORD(WindowBackgroundColor.a) = 1060320051;
      ProfilerUI::AddWindow(
        this,
        MoveToObject,
        &WindowBackgroundColor,
        1,
        0,
        0,
        0x10Eu,
        0x78u,
        &this->m_BlockResourcesStatsWindowHandle);
    }
  }
  else if ( this->m_BlockResourcesStatsWindowHandle )
  {
    ProfilerUI::RemoveWindow(this, this->m_BlockResourcesStatsWindowHandle);
    v2->m_BlockResourcesStatsWindowHandle = 0;
  }
}

//----- (005DC870) --------------------------------------------------------  // acclient.c:519426
void __thiscall ProfilerUI::ShowDBObjStatsWindow(ProfilerUI *this, const bool _Show)
{
  ProfilerUI *v2; // esi@1
  RGBAColor WindowBackgroundColor; // [sp+4h] [bp-10h]@3

  v2 = this;
  if ( _Show )
  {
    if ( !this->m_DBObjStatsWindowHandle )
    {
      LODWORD(WindowBackgroundColor.r) = 1047589105;
      LODWORD(WindowBackgroundColor.g) = 1055977713;
      LODWORD(WindowBackgroundColor.b) = 1047589105;
      LODWORD(WindowBackgroundColor.a) = 1060320051;
      ProfilerUI::AddWindow(
        this,
        MoveToObject,
        &WindowBackgroundColor,
        1,
        0,
        0,
        0x10Eu,
        0x1B8u,
        &this->m_DBObjStatsWindowHandle);
    }
  }
  else if ( this->m_DBObjStatsWindowHandle )
  {
    ProfilerUI::RemoveWindow(this, this->m_DBObjStatsWindowHandle);
    v2->m_DBObjStatsWindowHandle = 0;
  }
}

//----- (005DC8F0) --------------------------------------------------------  // acclient.c:519460
void __thiscall ProfilerUI::ShowMemoryProbeStatsWindow(ProfilerUI *this, const bool _Show)
{
  ProfilerUI *v2; // esi@1
  RGBAColor WindowBackgroundColor; // [sp+4h] [bp-10h]@3

  v2 = this;
  if ( _Show )
  {
    if ( !this->m_MemoryProbeStatsWindowHandle )
    {
      LODWORD(WindowBackgroundColor.r) = 1042325665;
      LODWORD(WindowBackgroundColor.g) = 1042325665;
      LODWORD(WindowBackgroundColor.b) = 1054661853;
      LODWORD(WindowBackgroundColor.a) = 1060320051;
      ProfilerUI::AddWindow(
        this,
        MoveToObject,
        &WindowBackgroundColor,
        1,
        0,
        0,
        0x10Eu,
        0x2BCu,
        &this->m_MemoryProbeStatsWindowHandle);
    }
  }
  else if ( this->m_MemoryProbeStatsWindowHandle )
  {
    ProfilerUI::RemoveWindow(this, this->m_MemoryProbeStatsWindowHandle);
    v2->m_MemoryProbeStatsWindowHandle = 0;
  }
}

//----- (005DC970) --------------------------------------------------------  // acclient.c:519494
char __thiscall ProfilerUI::InputLeftMouseCategoryButtonReleased(ProfilerUI *this, const int _X, const int _Y)
{
  ProfilerUI *v3; // esi@1
  char v4; // bl@1
  ProfilerTypes::CategoryType v5; // ebp@1
  unsigned int v6; // edi@1
  QuickButton *v7; // edi@6
  unsigned int v8; // edx@7
  unsigned int v9; // eax@7
  ProfilerUIWindow **v10; // ecx@8

  v3 = this;
  v4 = 0;
  v5 = -1;
  v6 = 0;
  if ( !this->m_CategoryButtons.m_num )
    return v4;
  do
  {
    if ( QuickButton::LeftMouseButtonReleased(v3->m_CategoryButtons.m_data[v6], _X, _Y) )
    {
      v5 = v6;
      v4 = 1;
    }
    ++v6;
  }
  while ( v6 < v3->m_CategoryButtons.m_num );
  if ( v5 == -1 )
    return v4;
  v7 = v3->m_CategoryButtons.m_data[v5];
  if ( v7->m_WindowID )
    return v4;
  v8 = v3->m_Windows.m_num;
  v9 = 0;
  if ( !v8 )
  {
LABEL_11:
    ProfilerUI::AddCategoryWindow(v3, v5);
    QuickButton::SetCheckedState(v7, 1);
    return v4;
  }
  v10 = v3->m_Windows.m_data;
  while ( (*v10)->m_Category != v5 )
  {
    ++v9;
    ++v10;
    if ( v9 >= v8 )
      goto LABEL_11;
  }
  ProfilerUI::RemoveCategoryWindow(v3, v5);
  QuickButton::SetCheckedState(v7, 0);
  return v4;
}

//----- (005DCA30) --------------------------------------------------------  // acclient.c:519549
bool __thiscall ProfilerUI::InputLeftMouseToolbarButtonReleased(ProfilerUI *this, const int _X, const int _Y)
{
  ProfilerUI *v3; // esi@1
  signed int v4; // ebp@1
  signed int v5; // edi@1
  const int v6; // ebx@2
  QuickButton *v7; // edi@7
  unsigned int v8; // eax@7
  int v9; // esi@8
  int v11; // esi@11
  char *v12; // esi@14
  char *v13; // esi@17
  char v14; // bp@21
  bool WasHandled; // [sp+Fh] [bp-Dh]@1
  unsigned int Flags; // [sp+10h] [bp-Ch]@11
  PStringBase<char> strCmd; // [sp+14h] [bp-8h]@14
  PStringBase<char> _Command; // [sp+18h] [bp-4h]@17

  v3 = this;
  v4 = -1;
  v5 = 0;
  WasHandled = 0;
  if ( this->m_ToolbarButtons.m_num )
  {
    v6 = _Y;
    do
    {
      if ( QuickButton::LeftMouseButtonReleased(v3->m_ToolbarButtons.m_data[v5], _X, v6) )
      {
        v4 = v5;
        WasHandled = 1;
      }
      ++v5;
    }
    while ( v5 < v3->m_ToolbarButtons.m_num );
    if ( v4 != -1 )
    {
      v7 = v3->m_ToolbarButtons.m_data[v4];
      v8 = v7->m_WindowID;
      switch ( v8 )
      {
        case 0x14u:
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_Y, "Toggle RenderDevice.Wireframe");
          GlobalRegistry::ProcessCommand((PStringBase<char> *)&_Y);
          v9 = _Y - 20;
          if ( InterlockedDecrement((volatile LONG *)(_Y - 20 + 4)) || !v9 )
            return WasHandled;
          (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
          return WasHandled;
        case 0x15u:
          Flags = 0;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_X, "RenderD3D.AlphaDelayMask");
          GlobalRegistry::InqTypedVariable((PStringBase<char> *)&Flags, (PStringBase<char> *)&_X, &Flags);
          v11 = _X - 20;
          if ( !InterlockedDecrement((volatile LONG *)(_X - 20 + 4)) && v11 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v11)(v11, 1);
          PStringBase<char>::PStringBase<char>(&strCmd, 0, "Set RenderD3D.AlphaDelayMask %d", Flags != 0 ? 0 : 0xE);
          GlobalRegistry::ProcessCommand(&strCmd);
          v12 = &strCmd.m_charbuffer[-2].m_data[12];
          if ( InterlockedDecrement((volatile LONG *)&strCmd.m_charbuffer[-1]) || !v12 )
            return WasHandled;
          (**(void (__thiscall ***)(char *, signed int))v12)(v12, 1);
          return WasHandled;
        case 0x16u:
          PStringBase<char>::PStringBase<char>(&_Command, "Toggle RenderDeviceD3D.AllowDrawPrimUP");
          GlobalRegistry::ProcessCommand(&_Command);
          v13 = &_Command.m_charbuffer[-2].m_data[12];
          if ( InterlockedDecrement((volatile LONG *)&_Command.m_charbuffer[-1]) || !v13 )
            return WasHandled;
          (**(void (__thiscall ***)(char *, signed int))v13)(v13, 1);
          return WasHandled;
        case 0xAu:
        case 0xBu:
        case 0xCu:
        case 0xDu:
        case 0xEu:
          Render::SetOverallGraphicsQuality(v8 - 9);
          v3->m_nGraphicsQualityLevel = Render::DetermineOverallGraphicsQuality();
          return WasHandled;
        case 0x1Eu:
          LOBYTE(_Y) = v3->m_MemoryCountersStatsWindowHandle == 0;
          v14 = _Y;
          ProfilerUI::ShowMemoryCountersStatsWindow(v3, _Y);
          break;
        case 0x1Fu:
          LOBYTE(_Y) = v3->m_BlockResourcesStatsWindowHandle == 0;
          v14 = _Y;
          ProfilerUI::ShowBlockResourcesStatsWindow(v3, _Y);
          break;
        case 0x20u:
          LOBYTE(_Y) = v3->m_DBObjStatsWindowHandle == 0;
          v14 = _Y;
          ProfilerUI::ShowDBObjStatsWindow(v3, _Y);
          break;
        case 0x21u:
          LOBYTE(_Y) = v3->m_MemoryProbeStatsWindowHandle == 0;
          v14 = _Y;
          ProfilerUI::ShowMemoryProbeStatsWindow(v3, _Y);
          break;
        default:
          return WasHandled;
      }
      QuickButton::SetCheckedState(v7, v14);
    }
  }
  return WasHandled;
}

//----- (005DCCD0) --------------------------------------------------------  // acclient.c:519658
void __thiscall ProfilerUI::InitDBObjStats(ProfilerUI *this)
{
  SmartArray<ProfilerDBObjStat,1> *v1; // ebp@1
  EnumMapper *v2; // esi@1
  unsigned int v3; // esi@3
  PSRefBufferCharData<char> *v4; // edi@3
  unsigned int v5; // eax@8
  unsigned int v6; // ebx@8
  int v7; // esi@9
  char *v8; // esi@12
  char *v9; // esi@15
  PStringBase<char> result; // [sp+14h] [bp-4Ch]@3
  ProfilerUI *v11; // [sp+18h] [bp-48h]@1
  DBObjGrabber<EnumMapper> pcDBOEnums; // [sp+1Ch] [bp-44h]@1
  EnumMapper::iterator rcIter; // [sp+20h] [bp-40h]@2
  EnumMapper::iterator rcEnd; // [sp+30h] [bp-30h]@2
  ProfilerDBObjStat DBObjStat; // [sp+40h] [bp-20h]@3

  v1 = &this->m_DBObjStats;
  v11 = this;
  SmartArray<ProfilerDBObjStat,1>::Reset(&this->m_DBObjStats);
  v2 = (EnumMapper *)DBObj::GetByEnum(2, 1, 0x24u);
  pcDBOEnums.m_object = v2;
  if ( v2 )
  {
    EnumMapper::begin(v2, &rcIter);
    EnumMapper::end(v2, &rcEnd);
    if ( EnumMapper::iterator::operator!=(&rcIter, &rcEnd) )
    {
      do
      {
        v3 = EnumMapper::iterator::get_enum(&rcIter);
        EnumMapper::iterator::get_string(&rcIter, &result);
        v4 = PStringBase<char>::s_NullBuffer.m_charbuffer;
        DBObjStat.DBTypeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        DBObjStat.DBType = v3;
        if ( v4 != result.m_charbuffer )
        {
          if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v4 != (PSRefBufferCharData<char> *)20 )
            (**(void (__thiscall ***)(char *, signed int))&v4[-2].m_data[12])(&v4[-2].m_data[12], 1);
          v4 = result.m_charbuffer;
          DBObjStat.DBTypeName.m_charbuffer = result.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&result.m_charbuffer[-1]);
        }
        v5 = v11->m_DBObjStats.m_num;
        v6 = 0;
        DBObjStat.NumActive = 0;
        DBObjStat.NumFree = 0;
        *(_QWORD *)&DBObjStat.LastLocalTimeNotEmpty = -4556649414143246336i64;
        *(_QWORD *)&DBObjStat.LastLocalTimeChanged = -4556649414143246336i64;
        if ( v5 )
        {
          v7 = 0;
          do
          {
            if ( __stricmp(v1->m_data[v7].DBTypeName.m_charbuffer->m_data, v4->m_data) >= 0 )
              break;
            ++v6;
            ++v7;
          }
          while ( v6 < v11->m_DBObjStats.m_num );
        }
        SmartArray<ProfilerDBObjStat,1>::InsertOrderedByIndex(v1, &DBObjStat, v6);
        v8 = &DBObjStat.DBTypeName.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&DBObjStat.DBTypeName.m_charbuffer[-1]) && v8 )
          (**(void (__thiscall ***)(char *, signed int))v8)(v8, 1);
        v9 = &result.m_charbuffer[-2].m_data[12];
        if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) )
        {
          if ( v9 )
            (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
        }
        EnumMapper::iterator::operator++(&rcIter);
      }
      while ( EnumMapper::iterator::operator!=(&rcIter, &rcEnd) );
      v2 = pcDBOEnums.m_object;
    }
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&rcEnd);
    gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&rcIter);
    v2->vfptr->Release((Interface *)v2);
  }
}

//----- (005DCE90) --------------------------------------------------------  // acclient.c:519743
ProfilerUI *__thiscall ProfilerUI::vector_deleting_destructor(ProfilerUI *this, unsigned int a2)
{
  ProfilerUI *v2; // esi@1

  v2 = this;
  ProfilerUI::~ProfilerUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005DCEB0) --------------------------------------------------------  // acclient.c:519755
char __thiscall ProfilerUI::OnAction(ProfilerUI *this, InputEvent *i_evt)
{
  unsigned int v2; // esi@1
  char v3; // bl@1
  int v5; // esi@5
  int v6; // edi@5
  ProfilerUI *v7; // ebp@5
  ProfilerUI *v8; // ecx@5
  bool v9; // al@8
  int v10; // [sp-10h] [bp-18h]@5
  int v11; // [sp-Ch] [bp-14h]@5

  v2 = i_evt->m_InputAction;
  v3 = 0;
  if ( i_evt->m_InputAction == 7 || v2 == 10 )
  {
    v5 = i_evt->m_ptMousePos.y;
    v6 = i_evt->m_ptMousePos.x;
    v3 = 0;
    v7 = (ProfilerUI *)((char *)this - 8);
    v11 = i_evt->m_ptMousePos.y;
    v8 = (ProfilerUI *)((char *)this - 8);
    v10 = i_evt->m_ptMousePos.x;
    if ( i_evt->m_fStart )
    {
      if ( ProfilerUI::InputLeftMouseCategoryButtonPressed(v8, v10, v11) )
        v3 = 1;
      v9 = ProfilerUI::InputLeftMouseToolbarButtonPressed(v7, v6, v5);
    }
    else
    {
      if ( ProfilerUI::InputLeftMouseCategoryButtonReleased(v8, v10, v11) )
        v3 = 1;
      v9 = ProfilerUI::InputLeftMouseToolbarButtonReleased(v7, v6, v5);
    }
    if ( v9 )
      v3 = 1;
  }
  else if ( v2 == 87 )
  {
    return 1;
  }
  return v3;
}

//----- (005DCF30) --------------------------------------------------------  // acclient.c:519801
void __thiscall ProfilerUI::AddBudgetStat(ProfilerUI *this, BudgetStatInfo *i_statInfo)
{
  BudgetStatInfo *v2; // eax@1
  bool v3; // cl@1
  char *v4; // esi@2
  unsigned int v5; // edx@6
  unsigned int v6; // edx@8
  unsigned int v7; // edx@10
  unsigned int v8; // edx@12
  unsigned int v9; // eax@14
  int v10; // eax@16
  unsigned int v11; // edx@17
  int v12; // ST14_4@22
  int v18; // esi@25
  int v19; // eax@25
  int v20; // ebp@26
  char *v21; // esi@31
  ProfilerUI *v22; // [sp+4h] [bp-2Ch]@1
  BudgetStatItem newStat; // [sp+Ch] [bp-24h]@1

  v22 = this;
  PStringBase<char>::PStringBase<char>(&newStat.sInfo.strName, &name);
  newStat.sInfo.nGraphicLevel[0] = 0;
  newStat.sInfo.nGraphicLevel[1] = 0;
  newStat.sInfo.nGraphicLevel[2] = 0;
  newStat.sInfo.nGraphicLevel[3] = 0;
  newStat.sInfo.nGraphicLevel[4] = 0;
  v2 = i_statInfo;
  newStat.sInfo.bIsMem = 0;
  v3 = i_statInfo->bIsMem;
  newStat.sInfo.bIsMem = i_statInfo->bIsMem;
  if ( newStat.sInfo.strName.m_charbuffer != i_statInfo->strName.m_charbuffer )
  {
    v4 = &newStat.sInfo.strName.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&newStat.sInfo.strName.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
    newStat.sInfo.strName.m_charbuffer = i_statInfo->strName.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&newStat.sInfo.strName.m_charbuffer[-1]);
    v2 = i_statInfo;
    v3 = newStat.sInfo.bIsMem;
  }
  v5 = v2->nGraphicLevel[0];
  newStat.sInfo.nGraphicLevel[0] = v2->nGraphicLevel[0];
  if ( v3 )
    newStat.sInfo.nGraphicLevel[0] = v5 << 20;
  v6 = v2->nGraphicLevel[1];
  newStat.sInfo.nGraphicLevel[1] = v2->nGraphicLevel[1];
  if ( v3 )
    newStat.sInfo.nGraphicLevel[1] = v6 << 20;
  v7 = v2->nGraphicLevel[2];
  newStat.sInfo.nGraphicLevel[2] = v2->nGraphicLevel[2];
  if ( v3 )
    newStat.sInfo.nGraphicLevel[2] = v7 << 20;
  v8 = v2->nGraphicLevel[3];
  newStat.sInfo.nGraphicLevel[3] = v2->nGraphicLevel[3];
  if ( v3 )
    newStat.sInfo.nGraphicLevel[3] = v8 << 20;
  v9 = v2->nGraphicLevel[4];
  newStat.sInfo.nGraphicLevel[4] = v9;
  if ( v3 )
    newStat.sInfo.nGraphicLevel[4] = v9 << 20;
  newStat.nValue = 0;
  newStat.nStatus = 0;
  v10 = v22->m_budgetStatArray.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( v22->m_budgetStatArray.m_num < v10 )
    goto LABEL_36;
  v11 = v10 + 1;
  if ( (unsigned int)(v10 + 1) > 8 )
  {
    if ( v11 <= 0x4000 )
    {
      v12 = v10 + 1;
      __asm { bsr     this, [esp+34h+var_28] }
      if ( v11 > 1 << _EAX )
        v11 = 2 * (1 << _EAX);
    }
    else if ( v11 & 0x3FFF )
    {
      v11 += 0x4000 - (v11 & 0x3FFF);
    }
  }
  else
  {
    v11 = 8;
  }
  if ( SmartArray<BudgetStatItem,1>::grow(&v22->m_budgetStatArray, v11) )
  {
LABEL_36:
    v18 = (int)&v22->m_budgetStatArray.m_data[v22->m_budgetStatArray.m_num];
    v19 = *(_DWORD *)v18;
    if ( *(_DWORD *)v18 != (_DWORD)newStat.sInfo.strName.m_charbuffer )
    {
      v20 = v19 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v19 - 20 + 4)) && v20 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v20)(v20, 1);
      *(_DWORD *)v18 = newStat.sInfo.strName.m_charbuffer;
      InterlockedIncrement((volatile LONG *)&newStat.sInfo.strName.m_charbuffer[-1]);
    }
    *(_DWORD *)(v18 + 4) = newStat.sInfo.nGraphicLevel[0];
    *(_DWORD *)(v18 + 8) = newStat.sInfo.nGraphicLevel[1];
    *(_DWORD *)(v18 + 12) = newStat.sInfo.nGraphicLevel[2];
    *(_DWORD *)(v18 + 16) = newStat.sInfo.nGraphicLevel[3];
    *(_DWORD *)(v18 + 20) = newStat.sInfo.nGraphicLevel[4];
    *(_BYTE *)(v18 + 24) = newStat.sInfo.bIsMem;
    *(_DWORD *)(v18 + 28) = newStat.nValue;
    *(_DWORD *)(v18 + 32) = newStat.nStatus;
    ++v22->m_budgetStatArray.m_num;
  }
  v21 = &newStat.sInfo.strName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&newStat.sInfo.strName.m_charbuffer[-1]) )
  {
    if ( v21 )
      (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
  }
}

//----- (005DD140) --------------------------------------------------------  // acclient.c:519918
bool __thiscall ProfilerUI::Init(ProfilerUI *this)
{
  ProfilerUI *v1; // edi@1
  unsigned int v2; // esi@1

  v1 = this;
  this->m_IsActive = 0;
  this->m_nGraphicsQualityLevel = Render::DetermineOverallGraphicsQuality();
  v2 = 0;
  do
  {
    ProfilerUI::AddBudgetStat(v1, (BudgetStatInfo *)(&BudgetStatInfoArray::s_BudgetStatInfo)[v2]);
    ++v2;
  }
  while ( v2 < 7 );
  ProfilerUI::InitDBObjStats(v1);
  ProfilerUI::AddCategoryWindow(v1, 0);
  return ProfilerUI::CreateToolbarWindows(v1) && ProfilerUI::CreateCategoryWindow(v1);
}
// 8F10A0: using guessed type const struct BudgetStatInfo **BudgetStatInfoArray::s_BudgetStatInfo;

//----- (005DD1A0) --------------------------------------------------------  // acclient.c:519940
TResult *__cdecl ProfilerUI::Create(TResult *result, ProfilerUI **_pOutObject)
{
  ProfilerUI *v2; // eax@1
  ProfilerUI *v3; // eax@2
  ProfilerUI *v4; // ecx@6
  bool v5; // zf@7
  TResult *v6; // eax@10

  v2 = (ProfilerUI *)operator new(0x88u);
  if ( v2 )
    ProfilerUI::ProfilerUI(v2);
  else
    v3 = 0;
  *_pOutObject = v3;
  if ( !v3 )
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467259;
    return v6;
  }
  if ( !ProfilerUI::Init(v3) )
  {
    v4 = *_pOutObject;
    if ( *_pOutObject )
    {
      v5 = v4->m_cRef-- == 1;
      if ( v5 )
        ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
      *_pOutObject = 0;
    }
    goto LABEL_10;
  }
  v6 = result;
  result->m_val = 0;
  return v6;
}

//----- (006961A0) --------------------------------------------------------  // acclient.c:686000
unsigned int __stdcall SmartArray<UIChildFramework *,1>::get_new_size(unsigned int i_nSize)
{
  unsigned int result; // eax@1
  unsigned int v3; // ST00_4@6
  char v9; // cl@6

  result = i_nSize;
  if ( i_nSize > 8 )
  {
    if ( i_nSize <= 0x4000 )
    {
      v3 = i_nSize;
      __asm { bsr     this, [esp+4+var_4] }
      v9 = _EAX;
      result = i_nSize;
      if ( i_nSize > 1 << v9 )
        result = 2 * (1 << v9);
    }
    else if ( i_nSize & 0x3FFF )
    {
      result = 0x4000 - (i_nSize & 0x3FFF) + i_nSize;
    }
  }
  else
  {
    result = 8;
  }
  return result;
}

//----- (00713BF0) --------------------------------------------------------  // acclient.c:806631
void sub_713BF0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8F0F6C, PFID_A8R8G8B8);
}

//----- (00713C00) --------------------------------------------------------  // acclient.c:806637
void sub_713C00()
{
  LODWORD(dword_8F0FA4) = 1053364187;
}

//----- (00713C10) --------------------------------------------------------  // acclient.c:806643
void sub_713C10()
{
  flt_8F0FA8 = 1000.0 + 1.0;
}

//----- (00713C30) --------------------------------------------------------  // acclient.c:806649
void sub_713C30()
{
  flt_8F0FAC = 24.0 * 8.0;
}

//----- (00713C50) --------------------------------------------------------  // acclient.c:806655
void sub_713C50()
{
  flt_8F0FB0 = 24.0 * 0.5;
}

//----- (00713C70) --------------------------------------------------------  // acclient.c:806661
int _E99_42()
{
  PStringBase<char>::PStringBase<char>(&Render_TextureFiltering_43, "Render.TextureFiltering");
  return atexit(sub_77DF70);
}

//----- (00713C90) --------------------------------------------------------  // acclient.c:806668
int _E102_37()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDetailTextures_43, "Render.LandscapeDetailTextures");
  return atexit(sub_77DFA0);
}

//----- (00713CB0) --------------------------------------------------------  // acclient.c:806675
int _E105_56()
{
  PStringBase<char>::PStringBase<char>(&Render_BuildingDetailTextures_43, "Render.BuildingDetailTextures");
  return atexit(sub_77DFD0);
}

//----- (00713CD0) --------------------------------------------------------  // acclient.c:806682
int sub_713CD0()
{
  PStringBase<char>::PStringBase<char>(&Render_FieldOfView_43, "Render.FieldOfView");
  return atexit(sub_77E000);
}

//----- (00713CF0) --------------------------------------------------------  // acclient.c:806689
int _E111_59()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeTextureDetail_43, "Render.LandscapeTextureDetail");
  return atexit(sub_77E030);
}

//----- (00713D10) --------------------------------------------------------  // acclient.c:806696
int _E114_65()
{
  PStringBase<char>::PStringBase<char>(&Render_EnvironmentTextureDetail_43, "Render.EnvironmentTextureDetail");
  return atexit(sub_77E060);
}

//----- (00713D30) --------------------------------------------------------  // acclient.c:806703
int _E117_83()
{
  PStringBase<char>::PStringBase<char>(&Render_SceneryDrawDistance_43, "Render.SceneryDrawDistance");
  return atexit(sub_77E090);
}

//----- (00713D50) --------------------------------------------------------  // acclient.c:806710
int _E120_75()
{
  PStringBase<char>::PStringBase<char>(&Render_LandscapeDrawDistance_43, "Render.LandscapeDrawDistance");
  return atexit(sub_77E0C0);
}

//----- (00713D70) --------------------------------------------------------  // acclient.c:806717
int _E123_47()
{
  PStringBase<char>::PStringBase<char>(&Render_ScreenBrightness_43, "Render.ScreenBrightness");
  return atexit(sub_77E0F0);
}

//----- (00713D90) --------------------------------------------------------  // acclient.c:806724
int _E126_54()
{
  PStringBase<char>::PStringBase<char>(&Render_AspectRatio_43, "Render.AspectRatio");
  return atexit(sub_77E120);
}

//----- (00713DB0) --------------------------------------------------------  // acclient.c:806731
int _E129_48()
{
  PStringBase<char>::PStringBase<char>(&Render_DisplayAdapter_43, "Render.DisplayAdapter");
  return atexit(sub_77E150);
}

//----- (00713DD0) --------------------------------------------------------  // acclient.c:806738
int _E132_49()
{
  PStringBase<char>::PStringBase<char>(&Render_MaxHardwareClass_43, "Render.MaxHardwareClass");
  return atexit(sub_77E180);
}

//----- (00713DF0) --------------------------------------------------------  // acclient.c:806745
int _E135_56()
{
  PStringBase<char>::PStringBase<char>(&Render_AutomaticDegrades_43, "Render.AutomaticDegrades");
  return atexit(_E136_91);
}

//----- (00713E10) --------------------------------------------------------  // acclient.c:806752
int _E138_44()
{
  PStringBase<char>::PStringBase<char>(&Render_GraphicsPerformance_43, "Render.GraphicsPerformance");
  return atexit(_E139_91);
}

//----- (00713E30) --------------------------------------------------------  // acclient.c:806759
int _E141_46()
{
  PStringBase<char>::PStringBase<char>(&Render_DegradeDistance_43, "Render.DegradeDistance");
  return atexit(_E142_86);
}

//----- (00713E50) --------------------------------------------------------  // acclient.c:806766
int _E144_43()
{
  PStringBase<char>::PStringBase<char>(&Render_MultiPassAlpha_43, "Render.MultiPassAlpha");
  return atexit(_E145_88);
}

//----- (00713E70) --------------------------------------------------------  // acclient.c:806773
int _E147_42()
{
  PStringBase<char>::PStringBase<char>(Render_TextureFiltering_Choices_43, "Bilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F0FFC, "Trilinear");
  PStringBase<char>::PStringBase<char>(&stru_8F1000, "Sharp");
  PStringBase<char>::PStringBase<char>(&stru_8F1004, "Anisotropic");
  return atexit(_E148_84);
}

//----- (00713EC0) --------------------------------------------------------  // acclient.c:806783
int _E150_41()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeTextureDetail_Choices_43, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F100C, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F1010, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F1014, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F1018, "VeryHigh");
  return atexit(_E151_82);
}

//----- (00713F20) --------------------------------------------------------  // acclient.c:806794
int _E153_39()
{
  PStringBase<char>::PStringBase<char>(Render_EnvironmentTextureDetail_Choices_43, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F1020, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F1024, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F1028, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F102C, "VeryHigh");
  return atexit(_E154_83);
}

//----- (00713F80) --------------------------------------------------------  // acclient.c:806805
int _E156_41()
{
  PStringBase<char>::PStringBase<char>(Render_SceneryDrawDistance_Choices_43, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F1034, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F1038, "High");
  return atexit(_E157_79);
}

//----- (00713FC0) --------------------------------------------------------  // acclient.c:806814
int _E159_39()
{
  PStringBase<char>::PStringBase<char>(Render_LandscapeDrawDistance_Choices_43, "VeryLow");
  PStringBase<char>::PStringBase<char>(&stru_8F1040, "Low");
  PStringBase<char>::PStringBase<char>(&stru_8F1044, "Medium");
  PStringBase<char>::PStringBase<char>(&stru_8F1048, "High");
  PStringBase<char>::PStringBase<char>(&stru_8F104C, "VeryHigh");
  PStringBase<char>::PStringBase<char>(&stru_8F1050, "Extreme");
  return atexit(_E160_82);
}

//----- (00714030) --------------------------------------------------------  // acclient.c:806826
int _E162_42()
{
  PStringBase<char>::PStringBase<char>(Render_AspectRatio_Choices_43, "Auto");
  PStringBase<char>::PStringBase<char>(&stru_8F1058, "Normal");
  PStringBase<char>::PStringBase<char>(&stru_8F105C, "Wide");
  return atexit(_E163_75);
}

//----- (00714070) --------------------------------------------------------  // acclient.c:806835
int _E165_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_71, "None");
  return atexit(_E166_77);
}

//----- (00714090) --------------------------------------------------------  // acclient.c:806842
int _E168_38()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_71, "Speed");
  return atexit(_E169_76);
}

//----- (007140B0) --------------------------------------------------------  // acclient.c:806849
int _E171_37()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_71, "Noise");
  return atexit(_E172_74);
}

//----- (007140D0) --------------------------------------------------------  // acclient.c:806856
int _E174_39()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_71, "Sine");
  return atexit(_E175_71);
}

//----- (007140F0) --------------------------------------------------------  // acclient.c:806863
int _E177_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_71, "Square");
  return atexit(_E178_71);
}

//----- (00714110) --------------------------------------------------------  // acclient.c:806870
int _E180_36()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_71, "Bounce");
  return atexit(_E181_71);
}

//----- (00714130) --------------------------------------------------------  // acclient.c:806877
int _E183_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_71, "Perlin");
  return atexit(_E184_68);
}

//----- (00714150) --------------------------------------------------------  // acclient.c:806884
int _E186_35()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_71, "Fractal");
  return atexit(_E187_67);
}

//----- (00714170) --------------------------------------------------------  // acclient.c:806891
int _E189_34()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_71, "FrameLoop");
  return atexit(_E190_68);
}

//----- (00714190) --------------------------------------------------------  // acclient.c:806898
int _E192_28()
{
  return atexit(_E193_54);
}

//----- (007141A0) --------------------------------------------------------  // acclient.c:806904
int _E195_20()
{
  return atexit(_E196_61);
}

//----- (007141B0) --------------------------------------------------------  // acclient.c:806910
int _E198_26()
{
  return atexit(_E199_53);
}

//----- (007141C0) --------------------------------------------------------  // acclient.c:806916
unsigned __int64 _E201_20()
{
  unsigned __int64 result; // rax@1

  result = (unsigned __int64)(stru_823AF0.b * 255.0);
  g_BudgetItemColor[0] = result | (((unsigned int)(unsigned __int64)(stru_823AF0.g * 255.0) | (((unsigned int)(unsigned __int64)(stru_823AF0.r * 255.0) | ((unsigned int)(unsigned __int64)(stru_823AF0.a * 255.0) << 8)) << 8)) << 8);
  g_BudgetItemColor[1] = -11731124;
  g_BudgetItemColor[2] = -1703963;
  g_BudgetItemColor[3] = -256;
  g_BudgetItemColor[4] = -59111;
  g_BudgetItemColor[5] = -3407872;
  return result;
}

//----- (00714250) --------------------------------------------------------  // acclient.c:806931
void _E203_3()
{
  PSRefBufferCharData<char> *v0; // ecx@1
  BudgetStatInfo *v1; // esi@1
  const struct BudgetStatInfo **v2; // eax@2
  PSRefBufferCharData<char> *v3; // ecx@4
  BudgetStatInfo *v4; // esi@4
  int v5; // eax@5
  PSRefBufferCharData<char> *v6; // ecx@7
  BudgetStatInfo *v7; // esi@7
  int v8; // eax@8
  PSRefBufferCharData<char> *v9; // ecx@10
  BudgetStatInfo *v10; // esi@10
  int v11; // eax@11
  PSRefBufferCharData<char> *v12; // ecx@13
  BudgetStatInfo *v13; // esi@13
  int v14; // eax@14
  PSRefBufferCharData<char> *v15; // ecx@16
  BudgetStatInfo *v16; // esi@16
  int v17; // eax@17
  PSRefBufferCharData<char> *v18; // ecx@19
  BudgetStatInfo *v19; // esi@19
  int v20; // eax@20
  PStringBase<char> v21; // [sp-1Ch] [bp-24h]@2
  unsigned int v22; // [sp-18h] [bp-20h]@2
  unsigned int v23; // [sp-14h] [bp-1Ch]@2
  unsigned int v24; // [sp-10h] [bp-18h]@2
  unsigned int v25; // [sp-Ch] [bp-14h]@2
  unsigned int v26; // [sp-8h] [bp-10h]@2
  signed int v27; // [sp-4h] [bp-Ch]@2

  v1 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v1 )
  {
    v27 = 0;
    v26 = 250000;
    v25 = 150000;
    v24 = 80000;
    v23 = 40000;
    v22 = 20000;
    v21.m_charbuffer = v0;
    PStringBase<char>::PStringBase<char>(&v21, "Triangles Rendered");
    BudgetStatInfo::BudgetStatInfo(v1, v21, v22, v23, v24, v25, v26, v27);
    BudgetStatInfoArray::s_BudgetStatInfo = v2;
  }
  else
  {
    BudgetStatInfoArray::s_BudgetStatInfo = 0;
  }
  v4 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v4 )
  {
    v27 = 0;
    v26 = 250000;
    v25 = 150000;
    v24 = 80000;
    v23 = 40000;
    v22 = 20000;
    v21.m_charbuffer = v3;
    PStringBase<char>::PStringBase<char>(&v21, "Vertices Rendered");
    BudgetStatInfo::BudgetStatInfo(v4, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10A4 = v5;
  }
  else
  {
    dword_8F10A4 = 0;
  }
  v7 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v7 )
  {
    v27 = 0;
    v26 = 2000;
    v25 = 1400;
    v24 = 1200;
    v23 = 800;
    v22 = 500;
    v21.m_charbuffer = v6;
    PStringBase<char>::PStringBase<char>(&v21, "Batches Rendered");
    BudgetStatInfo::BudgetStatInfo(v7, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10A8 = v8;
  }
  else
  {
    dword_8F10A8 = 0;
  }
  v10 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v10 )
  {
    v27 = 1;
    v26 = 300;
    v25 = 250;
    v24 = 200;
    v23 = 200;
    v22 = 200;
    v21.m_charbuffer = v9;
    PStringBase<char>::PStringBase<char>(&v21, "Process Mem Used");
    BudgetStatInfo::BudgetStatInfo(v10, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10AC = v11;
  }
  else
  {
    dword_8F10AC = 0;
  }
  v13 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v13 )
  {
    v27 = 1;
    v26 = 300;
    v25 = 250;
    v24 = 200;
    v23 = 200;
    v22 = 200;
    v21.m_charbuffer = v12;
    PStringBase<char>::PStringBase<char>(&v21, "Virtual Mem Reserved");
    BudgetStatInfo::BudgetStatInfo(v13, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10B0 = v14;
  }
  else
  {
    dword_8F10B0 = 0;
  }
  v16 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v16 )
  {
    v27 = 1;
    v26 = 96;
    v25 = 96;
    v24 = 64;
    v23 = 64;
    v22 = 64;
    v21.m_charbuffer = v15;
    PStringBase<char>::PStringBase<char>(&v21, "Total Video Mem Used");
    BudgetStatInfo::BudgetStatInfo(v16, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10B4 = v17;
  }
  else
  {
    dword_8F10B4 = 0;
  }
  v19 = (BudgetStatInfo *)operator new(0x1Cu);
  if ( v19 )
  {
    v27 = 1;
    v26 = 96;
    v25 = 96;
    v24 = 64;
    v23 = 64;
    v22 = 64;
    v21.m_charbuffer = v18;
    PStringBase<char>::PStringBase<char>(&v21, "Video Memory Used");
    BudgetStatInfo::BudgetStatInfo(v19, v21, v22, v23, v24, v25, v26, v27);
    dword_8F10B8 = v20;
  }
  else
  {
    dword_8F10B8 = 0;
  }
}
// 8F10A0: using guessed type const struct BudgetStatInfo **BudgetStatInfoArray::s_BudgetStatInfo;
// 8F10A4: using guessed type int dword_8F10A4;
// 8F10A8: using guessed type int dword_8F10A8;
// 8F10AC: using guessed type int dword_8F10AC;
// 8F10B0: using guessed type int dword_8F10B0;
// 8F10B4: using guessed type int dword_8F10B4;
// 8F10B8: using guessed type int dword_8F10B8;

//----- (00714450) --------------------------------------------------------  // acclient.c:807098
int _E205_17()
{
  return atexit(_E206_24);
}

//----- (00714460) --------------------------------------------------------  // acclient.c:807104
int sub_714460()
{
  return atexit(nullsub_1854);
}

//----- (0077DF70) --------------------------------------------------------  // acclient.c:917099
void __cdecl sub_77DF70()
{
  char *v0; // esi@1

  v0 = &Render_TextureFiltering_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_TextureFiltering_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DFA0) --------------------------------------------------------  // acclient.c:917112
void __cdecl sub_77DFA0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDetailTextures_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDetailTextures_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077DFD0) --------------------------------------------------------  // acclient.c:917125
void __cdecl sub_77DFD0()
{
  char *v0; // esi@1

  v0 = &Render_BuildingDetailTextures_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_BuildingDetailTextures_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E000) --------------------------------------------------------  // acclient.c:917138
void __cdecl sub_77E000()
{
  char *v0; // esi@1

  v0 = &Render_FieldOfView_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_FieldOfView_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E030) --------------------------------------------------------  // acclient.c:917151
void __cdecl sub_77E030()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeTextureDetail_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeTextureDetail_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E060) --------------------------------------------------------  // acclient.c:917164
void __cdecl sub_77E060()
{
  char *v0; // esi@1

  v0 = &Render_EnvironmentTextureDetail_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_EnvironmentTextureDetail_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E090) --------------------------------------------------------  // acclient.c:917177
void __cdecl sub_77E090()
{
  char *v0; // esi@1

  v0 = &Render_SceneryDrawDistance_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_SceneryDrawDistance_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E0C0) --------------------------------------------------------  // acclient.c:917190
void __cdecl sub_77E0C0()
{
  char *v0; // esi@1

  v0 = &Render_LandscapeDrawDistance_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_LandscapeDrawDistance_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E0F0) --------------------------------------------------------  // acclient.c:917203
void __cdecl sub_77E0F0()
{
  char *v0; // esi@1

  v0 = &Render_ScreenBrightness_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_ScreenBrightness_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E120) --------------------------------------------------------  // acclient.c:917216
void __cdecl sub_77E120()
{
  char *v0; // esi@1

  v0 = &Render_AspectRatio_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AspectRatio_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E150) --------------------------------------------------------  // acclient.c:917229
void __cdecl sub_77E150()
{
  char *v0; // esi@1

  v0 = &Render_DisplayAdapter_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DisplayAdapter_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E180) --------------------------------------------------------  // acclient.c:917242
void __cdecl sub_77E180()
{
  char *v0; // esi@1

  v0 = &Render_MaxHardwareClass_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MaxHardwareClass_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E1B0) --------------------------------------------------------  // acclient.c:917255
void __cdecl _E136_91()
{
  char *v0; // esi@1

  v0 = &Render_AutomaticDegrades_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_AutomaticDegrades_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E1E0) --------------------------------------------------------  // acclient.c:917268
void __cdecl _E139_91()
{
  char *v0; // esi@1

  v0 = &Render_GraphicsPerformance_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_GraphicsPerformance_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E210) --------------------------------------------------------  // acclient.c:917281
void __cdecl _E142_86()
{
  char *v0; // esi@1

  v0 = &Render_DegradeDistance_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_DegradeDistance_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E240) --------------------------------------------------------  // acclient.c:917294
void __cdecl _E145_88()
{
  char *v0; // esi@1

  v0 = &Render_MultiPassAlpha_43.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Render_MultiPassAlpha_43.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E270) --------------------------------------------------------  // acclient.c:917307
void __cdecl _E148_84()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeTextureDetail_Choices_43;
  v1 = 4;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E2B0) --------------------------------------------------------  // acclient.c:917332
void __cdecl _E151_82()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_EnvironmentTextureDetail_Choices_43;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E2F0) --------------------------------------------------------  // acclient.c:917357
void __cdecl _E154_83()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_SceneryDrawDistance_Choices_43;
  v1 = 5;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E330) --------------------------------------------------------  // acclient.c:917382
void __cdecl _E157_79()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_LandscapeDrawDistance_Choices_43;
  v1 = 3;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E370) --------------------------------------------------------  // acclient.c:917407
void __cdecl _E160_82()
{
  int v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (int)Render_AspectRatio_Choices_43;
  v1 = 6;
  do
  {
    v2 = *(_DWORD *)(v0 - 4);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E3B0) --------------------------------------------------------  // acclient.c:917432
void __cdecl _E163_75()
{
  PStringBase<char> *v0; // edi@1
  signed int v1; // ebp@1
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // esi@2

  v0 = &waveform_None_71;
  v1 = 3;
  do
  {
    v2 = v0[-1].m_charbuffer;
    --v0;
    v3 = (int)&v2[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

//----- (0077E3F0) --------------------------------------------------------  // acclient.c:917457
void __cdecl _E166_77()
{
  char *v0; // esi@1

  v0 = &waveform_None_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E420) --------------------------------------------------------  // acclient.c:917470
void __cdecl _E169_76()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E450) --------------------------------------------------------  // acclient.c:917483
void __cdecl _E172_74()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E480) --------------------------------------------------------  // acclient.c:917496
void __cdecl _E175_71()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E4B0) --------------------------------------------------------  // acclient.c:917509
void __cdecl _E178_71()
{
  char *v0; // esi@1

  v0 = &waveform_Square_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E4E0) --------------------------------------------------------  // acclient.c:917522
void __cdecl _E181_71()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E510) --------------------------------------------------------  // acclient.c:917535
void __cdecl _E184_68()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E540) --------------------------------------------------------  // acclient.c:917548
void __cdecl _E187_67()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E570) --------------------------------------------------------  // acclient.c:917561
void __cdecl _E190_68()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_71.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_71.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077E5A0) --------------------------------------------------------  // acclient.c:917574
void __cdecl _E206_24()
{
  BudgetStatInfoArray::~BudgetStatInfoArray();
}

