/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIFlow
   Object     : ENGINE\uiflow\UIFlow.obj
   Functions  : 29
   Addresses  : 004793C0 - 0075EDF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004793C0) --------------------------------------------------------  // acclient.c:182419
void __thiscall UIFlow::QueueUIMode(UIFlow *this, const unsigned int newMode)
{
  UIFlow *v2; // esi@1

  v2 = this;
  this->_nextMode = 0;
  StringInfo::Reset(&this->_nextText);
  v2->_nextMode = newMode;
}

//----- (004793F0) --------------------------------------------------------  // acclient.c:182430
void __thiscall UIFlow::QueueUIModeWithError(UIFlow *this, const unsigned int newMode, StringInfo *newText)
{
  UIFlow *v3; // esi@1
  StringInfo *v4; // edi@1

  v3 = this;
  v4 = &this->_nextText;
  this->_nextMode = 0;
  StringInfo::Reset(&this->_nextText);
  v3->_nextMode = newMode;
  StringInfo::operator=(v4, (int)newText);
}

//----- (00479430) --------------------------------------------------------  // acclient.c:182444
void __thiscall UIFlow::Update(UIFlow *this)
{
  UIMainFramework *v1; // ecx@1

  v1 = this->_curUI;
  if ( v1 )
    ((void (*)(void))v1->vfptr[5].OnAction)();
}

//----- (00479440) --------------------------------------------------------  // acclient.c:182454
void __thiscall UIFlow::~UIFlow(UIFlow *this)
{
  UIFlow *v1; // esi@1
  char *v2; // ebx@1
  unsigned int v3; // ecx@1
  UIPersistantData *v4; // edi@3

  v1 = this;
  v2 = (char *)&this[-1]._nextText.m_strComment;
  this[-1]._nextText.m_strEnglish.m_charbuffer = (PSRefBufferCharData<char> *)&gmUIFlow::vftable;
  this[-1]._nextText.m_strComment.m_charbuffer = (PSRefBufferCharData<char> *)&CObjectMaint::vftable;
  this->vfptr = (InterfaceVtbl *)&UIFlow::vftable;
  UIFlow::m_instance = 0;
  v3 = this->_curMode;
  if ( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = (UIPersistantData *)v1->_nextMode;
  v1->_curMode = 0;
  if ( v4 )
  {
    UIPersistantData::~UIPersistantData(v4);
    operator delete(v4);
  }
  v1->_nextMode = 0;
  UIListener::UnRegisterForGlobalMessage((UIListener *)v1, 3u);
  StringInfo::~StringInfo((StringInfo *)&v1->_curUI);
  v1->m_hashElementsRegisteredWith.m_intrusiveTable.m_numElements = (unsigned int)&ReferenceCountTemplate<1048576,2>::vftable;
  UIListener::~UIListener((UIListener *)(v1 != (UIFlow *)8 ? (unsigned int)v1 : 0));
  NoticeHandler::~NoticeHandler((NoticeHandler *)(v1 != (UIFlow *)8 ? (unsigned int)v2 : 0));
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79E1F4: using guessed type int (__stdcall *UIFlow::vftable)(char);
// 79E20C: using guessed type __int32 (__stdcall *gmUIFlow::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (004794E0) --------------------------------------------------------  // acclient.c:182491
TResult *__thiscall UIFlow::QueryInterface(UIFlow *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppObject)
{
  TResult *v4; // eax@6

  if ( i_rcInterface->m_data1 == -559038737
    && *(_DWORD *)&i_rcInterface->m_data2 == *(_DWORD *)&Interface_InterfaceType_26.m_data2
    && *(_DWORD *)&i_rcInterface->m_data4[0] == *(_DWORD *)&Interface_InterfaceType_26.m_data4[0]
    && *(_DWORD *)&i_rcInterface->m_data4[4] == *(_DWORD *)&Interface_InterfaceType_26.m_data4[4]
    && this )
  {
    *o_ppObject = this;
    ((void (*)(void))this->vfptr->AddRef)();
    v4 = result;
    result->m_val = 0;
  }
  else
  {
    v4 = result;
    result->m_val = -2147467262;
  }
  return v4;
}

//----- (00479540) --------------------------------------------------------  // acclient.c:182515
LONG __thiscall UIFlow::AddRef(UIFlow *this)
{
  return InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}

//----- (00479550) --------------------------------------------------------  // acclient.c:182521
unsigned int __thiscall UIFlow::Release(UIFlow *this)
{
  UIFlow *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
    v1->vfptr->__vecDelDtor(&v1->vfptr, 1);
  return v2;
}

//----- (00479580) --------------------------------------------------------  // acclient.c:182534
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *__thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vector_deleting_destructor(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *v2; // esi@1
  HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E238: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable)(void *, char);

//----- (004795C0) --------------------------------------------------------  // acclient.c:182555
void __thiscall UIFlow::UIFlow(UIFlow *this)
{
  UIFlow *v1; // esi@1
  UIListener *v2; // edi@1
  UIPersistantData *v3; // eax@1
  UIPersistantData *v4; // eax@2

  v1 = this;
  v2 = (UIListener *)&this->vfptr;
  this->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  UIListener::UIListener((UIListener *)&this->vfptr);
  v1->vfptr = (InterfaceVtbl *)&gmUIFlow::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&CObjectMaint::vftable;
  v2->vfptr = (IInputActionCallbackVtbl *)&UIFlow::vftable;
  v1->m_cTurbineRefCount.m_cRef = 1;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v1->_curMode = 0;
  v1->_nextMode = 0;
  v1->_curUI = 0;
  v1->_data = 0;
  StringInfo::StringInfo(&v1->_nextText);
  UIListener::RegisterForGlobalMessage(v2, 3u);
  v3 = (UIPersistantData *)operator new(0x50u);
  if ( v3 )
  {
    UIPersistantData::UIPersistantData(v3);
    v1->_data = v4;
    UIFlow::m_instance = v1;
  }
  else
  {
    v1->_data = 0;
    UIFlow::m_instance = v1;
  }
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 79E1F4: using guessed type int (__stdcall *UIFlow::vftable)(char);
// 79E20C: using guessed type __int32 (__stdcall *gmUIFlow::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CBD20: using guessed type bool (__thiscall *CObjectMaint::vftable)(DBObj *this);
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (00479670) --------------------------------------------------------  // acclient.c:182597
int __thiscall UIFlow::vector_deleting_destructor(UIFlow *this, char a2)
{
  UIFlow *v2; // esi@1
  int result; // eax@1

  v2 = this;
  UIFlow::~UIFlow(this);
  result = (int)&v2[-1]._nextText.m_strEnglish;
  if ( a2 & 1 )
  {
    operator delete(&v2[-1]._nextText.m_strEnglish);
    result = (int)&v2[-1]._nextText.m_strEnglish;
  }
  return result;
}

//----- (004796A0) --------------------------------------------------------  // acclient.c:182614
void __thiscall UIFlow::UseNewMode(UIFlow *this)
{
  UIFlow *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@2
  HashTableData<unsigned long,RenderVertexStreamD3D *> *v4; // eax@2
  UIMainFramework *v5; // ecx@7
  int (*v6)(void); // ebx@7
  UIMainFramework *v7; // ecx@9
  int v8; // eax@12
  StringInfo *v9; // ecx@12
  StringInfo copy; // [sp+10h] [bp-90h]@11

  v1 = this;
  v2 = this->_nextMode;
  if ( v2 )
  {
    v3 = this->_nextMode;
    v4 = stru_818F8C.m_buckets[v2 % stru_818F8C.m_numBuckets];
    if ( v4 )
    {
      while ( v4->m_hashKey != v3 )
      {
        v4 = v4->m_hashNext;
        if ( !v4 )
          return;
      }
      if ( v4 )
      {
        v5 = v1->_curUI;
        v6 = (int (*)(void))v4->m_data;
        if ( v5 )
          ((void (__stdcall *)(_DWORD))v5->vfptr[3].__vecDelDtor)(0);
        v7 = v1->_curUI;
        if ( v7 )
          ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
        v1->_curMode = v1->_nextMode;
        v1->_curUI = 0;
        v1->_nextMode = 0;
        StringInfo::StringInfo(&copy, &v1->_nextText);
        StringInfo::Reset(&v1->_nextText);
        if ( v6 )
        {
          v8 = v6();
          v9 = &copy;
          if ( !v8 )
          {
LABEL_17:
            StringInfo::~StringInfo(v9);
            return;
          }
          v1->_curUI = (UIMainFramework *)v8;
          if ( StringInfo::IsValid(&copy, 1) )
            ((void (__stdcall *)(StringInfo *))v1->_curUI->vfptr[5].__vecDelDtor)(&copy);
          ((void (__stdcall *)(signed int))v1->_curUI->vfptr[3].__vecDelDtor)(1);
        }
        v9 = &copy;
        goto LABEL_17;
      }
    }
  }
}

//----- (004797A0) --------------------------------------------------------  // acclient.c:182678
void __thiscall UIFlow::ListenToGlobalMessage(UIFlow *this, unsigned int messageID, int data_int)
{
  if ( messageID == 3 )
  {
    if ( this->m_cTurbineRefCount.m_cRef )
      UIFlow::UseNewMode((UIFlow *)((char *)this - 8));
  }
}

//----- (004797C0) --------------------------------------------------------  // acclient.c:182688
void __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 79E238: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable)(void *, char);

//----- (00479850) --------------------------------------------------------  // acclient.c:182721
void __cdecl UIFlow::RegisterFrameworkClass(unsigned int mode, UIMainFramework *(__cdecl *createMethod)())
{
  void *v2; // eax@1
  void *v3; // esi@2

  v2 = operator new(0xCu);
  if ( v2 )
  {
    *(_DWORD *)v2 = mode;
    *((_DWORD *)v2 + 1) = 0;
    *((_DWORD *)v2 + 2) = createMethod;
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  if ( !IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::add(
          &stru_818F8C,
          (HashTableData<unsigned long,RenderVertexStreamD3D *> *)v3) )
  {
    if ( v3 )
      operator delete(v3);
  }
}

//----- (004798A0) --------------------------------------------------------  // acclient.c:182748
HashTable<unsigned long,UIMainFramework * (__cdecl*)(void),0> *__thiscall HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vector_deleting_destructor(HashTable<unsigned long,UIMainFramework * (__cdecl*)(void),0> *this, unsigned int a2)
{
  HashTable<unsigned long,UIMainFramework * (__cdecl*)(void),0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<unsigned long,UIMainFramework * (__cdecl*)(void),0>Vtbl *)&HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79E238: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable)(void *, char);
// 79E23C: using guessed type int (__thiscall *HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable)(void *, char);

//----- (006EC440) --------------------------------------------------------  // acclient.c:768121
int _E73_79()
{
  return atexit(_E74_60);
}

//----- (006EC450) --------------------------------------------------------  // acclient.c:768127
int _E76_46()
{
  return atexit(_E77_74);
}

//----- (006EC460) --------------------------------------------------------  // acclient.c:768133
int _E79_39()
{
  return atexit(_E80_39);
}

//----- (006EC470) --------------------------------------------------------  // acclient.c:768139
void _E98_2()
{
  LODWORD(dword_83D740) = 1053364187;
}

//----- (006EC480) --------------------------------------------------------  // acclient.c:768145
void _E100_29()
{
  outside_val_27 = 1000.0 + 1.0;
}

//----- (006EC4A0) --------------------------------------------------------  // acclient.c:768151
void _E102_9()
{
  block_length_27 = 24.0 * 8.0;
}

//----- (006EC4C0) --------------------------------------------------------  // acclient.c:768157
void _E104_4()
{
  half_square_length_27 = 24.0 * 0.5;
}

//----- (006EC4E0) --------------------------------------------------------  // acclient.c:768163
void _E106_18()
{
  DEFAULT_VIEW_RADIUS_12 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006EC500) --------------------------------------------------------  // acclient.c:768169
void _E108_11()
{
  MIN_QUANTUM_12 = 1.0 / 30.0;
}

//----- (006EC520) --------------------------------------------------------  // acclient.c:768175
void _E110_2()
{
  MAX_QUANTUM_12 = 1.0 / 5.0;
}

//----- (006EC540) --------------------------------------------------------  // acclient.c:768181
void _E112_15()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_47, PFID_A8R8G8B8);
}

//----- (006EC550) --------------------------------------------------------  // acclient.c:768187
int _E114_14()
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>(
    (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl*)(void)> *,0> *)&stru_818F8C,
    0x17u);
  return atexit(sub_75EDF0);
}

//----- (006EC570) --------------------------------------------------------  // acclient.c:768196
int _E1_86()
{
  return atexit(_E2_86);
}

//----- (0075EDF0) --------------------------------------------------------  // acclient.c:887051
void __cdecl sub_75EDF0()
{
  UIFlow::_frameworkCreateMethodTable = &HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents(&stru_818F8C);
  stru_818F8C.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>Vtbl *)&IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable;
  if ( (HashTableData<unsigned long,RenderVertexStreamD3D *> **)stru_818F8C.m_buckets != stru_818F8C.m_aInplaceBuckets )
    operator delete[](stru_818F8C.m_buckets);
  stru_818F8C.m_buckets = 0;
  stru_818F8C.m_firstInterestingBucket = 0;
  stru_818F8C.m_numBuckets = 0;
  stru_818F8C.m_numElements = 0;
}
// 79E238: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable)(void *, char);
// 79E23C: using guessed type int (__thiscall *HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable)(void *, char);
// 818F88: using guessed type int (__thiscall **UIFlow::_frameworkCreateMethodTable)(void *, char);

