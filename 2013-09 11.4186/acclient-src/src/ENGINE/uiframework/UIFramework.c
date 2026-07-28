/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIFramework
   Object     : ENGINE\uiframework\UIFramework.obj
   Functions  : 16
   Addresses  : 006A0910 - 0078FF40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006A0910) --------------------------------------------------------  // acclient.c:697112
int UIFramework::GetPersistantData()
{
  return ((int (*)(void))UIFlow::m_instance->vfptr[1].QueryInterface)();
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (006A0920) --------------------------------------------------------  // acclient.c:697119
void __stdcall UIFramework::QueueUIMode(const unsigned int newMode)
{
  UIFlow::m_instance->vfptr[1].IUnknown_AddRef((Interface *)newMode);
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (006A0930) --------------------------------------------------------  // acclient.c:697126
void __thiscall UIFramework::Show(UIFramework *this, int shown)
{
  UIFramework *v2; // esi@1
  unsigned int v3; // edi@4
  UIChildFramework *v4; // ecx@5

  v2 = this;
  if ( !this->m_bCanForceHide || !this->m_bIsForcedHidden )
    this->m_shown = shown;
  v3 = 0;
  if ( this->m_children.m_num )
  {
    do
    {
      v4 = v2->m_children.m_data[v3];
      if ( v4 )
      {
        LOBYTE(shown) = v4->m_shown;
        if ( v4->m_bCanForceHide )
        {
          if ( v4->m_bIsForcedHidden )
            LOBYTE(shown) = 0;
        }
        ((void (__stdcall *)(_DWORD))v4->vfptr[3].__vecDelDtor)(shown);
      }
      ++v3;
    }
    while ( v3 < v2->m_children.m_num );
  }
}

//----- (006A09A0) --------------------------------------------------------  // acclient.c:697158
void __thiscall UIFramework::ForceHidden(UIFramework *this, int hide)
{
  UIFramework *v2; // esi@1
  int v3; // eax@1
  unsigned int v4; // edi@1
  UIChildFramework *v5; // ecx@2

  v2 = this;
  v3 = this->m_children.m_num;
  v4 = 0;
  this->m_bIsForcedHidden = hide;
  if ( v3 )
  {
    do
    {
      v5 = v2->m_children.m_data[v4];
      if ( v5 )
        ((void (__stdcall *)(_DWORD))v5->vfptr[3].OnLoseFocus)(hide);
      v3 = v2->m_children.m_num;
      ++v4;
    }
    while ( v4 < v3 );
  }
  if ( UIElementManager::s_pInstance )
  {
    LOBYTE(v3) = v2->m_bIsForcedHidden == 0;
    UIElementManager::SetVisible(UIElementManager::s_pInstance, v3);
  }
}

//----- (006A0A10) --------------------------------------------------------  // acclient.c:697189
unsigned int __thiscall UIFramework::FindChild(UIFramework *this, UIChildFramework *child)
{
  unsigned int v2; // edx@1
  unsigned int result; // eax@1
  UIChildFramework **v4; // ecx@2

  v2 = this->m_children.m_num;
  result = 0;
  if ( v2 )
  {
    v4 = this->m_children.m_data;
    while ( *v4 != child )
    {
      ++result;
      ++v4;
      if ( result >= v2 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    result = -1;
  }
  return result;
}

//----- (006A0A40) --------------------------------------------------------  // acclient.c:697217
signed int __thiscall UIFramework::ListenToElementMessage(UIFramework *this, UIElementMessageInfo *i_rMsg)
{
  UIFramework *v2; // edi@1
  unsigned int v3; // esi@1
  int v4; // ebp@1
  UIChildFramework *v5; // ecx@3
  int v6; // eax@3

  v2 = this;
  v3 = this->m_children.m_num;
  v4 = 0;
  while ( 1 )
  {
    if ( !v3 )
      return v4;
    v5 = v2->m_children.m_data[v3-- - 1];
    v6 = ((int (__stdcall *)(UIElementMessageInfo *))v5->vfptr[1].__vecDelDtor)(i_rMsg);
    if ( v6 == 2 )
      break;
    if ( v6 )
      v4 = v6;
    if ( v4 == 2 )
      return v4;
  }
  return 2;
}

//----- (006A0A90) --------------------------------------------------------  // acclient.c:697245
void __thiscall UIFramework::RemoveChild(UIFramework *this, UIChildFramework *child)
{
  UIFramework *v2; // esi@1
  int v3; // eax@1
  unsigned int v4; // ecx@2
  int v5; // ecx@3

  v2 = this;
  v3 = ((int (__stdcall *)(_DWORD))this->vfptr[4].OnLoseFocus)(child);
  if ( v3 != -1 )
  {
    v4 = v2->m_children.m_num;
    if ( v3 < v4 )
    {
      v5 = v4 - 1;
      v2->m_children.m_num = v5;
      if ( v3 != v5 )
      {
        v2->m_children.m_data[v3] = v2->m_children.m_data[v5];
        v2->m_children.m_data[v2->m_children.m_num] = 0;
      }
    }
  }
}

//----- (006A0AE0) --------------------------------------------------------  // acclient.c:697271
void __thiscall UIFramework::UIFramework(UIFramework *this)
{
  UIFramework *v1; // esi@1

  v1 = this;
  UIListener::UIListener((UIListener *)&this->vfptr);
  v1->m_bCanForceHide = 0;
  v1->m_bIsForcedHidden = 0;
  v1->vfptr = (IInputActionCallbackVtbl *)&UIFramework::vftable;
  v1->m_shown = 1;
  v1->m_children.m_data = 0;
  v1->m_children.m_sizeAndDeallocate = 0;
  v1->m_children.m_num = 0;
}
// 8017BC: using guessed type int (__thiscall *UIFramework::vftable)(void *, char);

//----- (006A0B10) --------------------------------------------------------  // acclient.c:697288
void __thiscall UIFramework::~UIFramework(UIFramework *this)
{
  UIListener *v1; // esi@1

  v1 = (UIListener *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIFramework::vftable;
  if ( (this->m_children.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_children.m_data);
  UIListener::~UIListener(v1);
}
// 8017BC: using guessed type int (__thiscall *UIFramework::vftable)(void *, char);

//----- (006A0B50) --------------------------------------------------------  // acclient.c:697301
UIListener *__thiscall UIFramework::vector_deleting_destructor(UIFramework *this, unsigned int a2)
{
  UIListener *v2; // esi@1

  v2 = (UIListener *)this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIFramework::vftable;
  if ( (this->m_children.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](this->m_children.m_data);
  UIListener::~UIListener(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 8017BC: using guessed type int (__thiscall *UIFramework::vftable)(void *, char);

//----- (006A0BA0) --------------------------------------------------------  // acclient.c:697317
void __thiscall UIFramework::AddChild(UIFramework *this, UIChildFramework *child)
{
  UIFramework *v2; // esi@1
  unsigned int v3; // eax@2
  unsigned int v4; // ecx@2
  int v5; // esi@2
  int v6; // eax@2
  unsigned int v7; // eax@3

  v2 = this;
  if ( ((int (__stdcall *)(_DWORD))this->vfptr[4].OnLoseFocus)(child) == -1 )
  {
    v3 = v2->m_children.m_sizeAndDeallocate;
    v4 = v2->m_children.m_num;
    v5 = (int)&v2->m_children;
    v6 = v3 & 0x7FFFFFFF;
    if ( v4 < v6
      || (v7 = SmartArray<UIChildFramework *,1>::get_new_size(v6 + 1),
          SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v5, v7)) )
      *(_DWORD *)(*(_DWORD *)v5 + 4 * (*(_DWORD *)(v5 + 8))++) = child;
  }
}

//----- (00721600) --------------------------------------------------------  // acclient.c:819098
int sub_721600()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_50, "Misc.TooltipEnable");
  return atexit(sub_78FF10);
}

//----- (00721620) --------------------------------------------------------  // acclient.c:819105
int sub_721620()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_50, "Misc.TooltipDelay");
  return atexit(sub_78FF40);
}

//----- (00721640) --------------------------------------------------------  // acclient.c:819112
int sub_721640()
{
  return atexit(nullsub_363);
}

//----- (0078FF10) --------------------------------------------------------  // acclient.c:936451
void __cdecl sub_78FF10()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0078FF40) --------------------------------------------------------  // acclient.c:936464
void __cdecl sub_78FF40()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

