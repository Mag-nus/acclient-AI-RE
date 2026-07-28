/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIPersistantData
   Object     : ENGINE\uiflow\UIPersistantData.obj
   Functions  : 7
   Addresses  : 00479900 - 006EC580 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00479900) --------------------------------------------------------  // acclient.c:182774
void __thiscall UIPersistantData::RecvNotice_CharacterSet(UIPersistantData *this, CharacterSet *charSet)
{
  UIPersistantData *v2; // esi@1

  v2 = this;
  CharacterSet::operator=((int)&this->_charSet, (int)charSet);
  v2->_receivedSet = 1;
  ((void (*)(void))UIFlow::m_instance->vfptr[1].AddRef)();
}
// 83D72C: using guessed type struct UIFlow *UIFlow::m_instance;

//----- (00479930) --------------------------------------------------------  // acclient.c:182786
void __thiscall CharacterSet::CharacterSet(CharacterSet *this)
{
  CharacterSet *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&CharacterSet::vftable;
  this->set_.m_data = 0;
  this->set_.m_size = 0;
  this->set_.m_num = 0;
  this->delSet_.m_data = 0;
  this->delSet_.m_size = 0;
  this->delSet_.m_num = 0;
  this->status_ = 0;
  this->numAllowedCharacters_ = 5;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->account_.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->account_.fIsDarkMajestyExpansion_ = 0;
  v1->account_.m_fIsThroneOfDestinyExpansion = 0;
  v1->account_.m_fPreOrderedThroneOfDestinyExpansion = 0;
  v1->name = 0;
}
// 79E250: using guessed type int (__thiscall *CharacterSet::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00479980) --------------------------------------------------------  // acclient.c:182813
void __thiscall CharacterSet::~CharacterSet(CharacterSet *this)
{
  CharacterSet *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  CharacterIdentity *v3; // ecx@4
  CharacterIdentity *v4; // ecx@8

  v1 = this;
  v2 = this->account_.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->delSet_.m_data;
  if ( v3 )
  {
    if ( v3[-1].secondsGreyedOut_ )
      ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(3);
    else
      operator delete[](&v3[-1].secondsGreyedOut_);
  }
  v4 = v1->set_.m_data;
  if ( v4 )
  {
    if ( v4[-1].secondsGreyedOut_ )
    {
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(3);
      v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
      return;
    }
    operator delete[](&v4[-1].secondsGreyedOut_);
  }
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00479A00) --------------------------------------------------------  // acclient.c:182848
void __thiscall UIPersistantData::UIPersistantData(UIPersistantData *this)
{
  UIPersistantData *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&UIPersistantData::vftable;
  CharacterSet::CharacterSet(&this->_charSet);
  v1->_receivedSet = 0;
  v1->m_iidSelectedAvatar = 0;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v2, 100006u, (NoticeHandler *)v1);
}
// 79E268: using guessed type bool (__thiscall *UIPersistantData::vftable)(DBObj *this);

//----- (00479A40) --------------------------------------------------------  // acclient.c:182865
void __thiscall UIPersistantData::~UIPersistantData(UIPersistantData *this)
{
  UIPersistantData *v1; // esi@1
  GlobalEventHandler *v2; // eax@1

  v1 = this;
  this->vfptr = (NoticeHandlerVtbl *)&UIPersistantData::vftable;
  v2 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v2 )
    v2->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v2, (NoticeHandler *)v1);
  CharacterSet::~CharacterSet(&v1->_charSet);
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
}
// 79E268: using guessed type bool (__thiscall *UIPersistantData::vftable)(DBObj *this);

//----- (00479A70) --------------------------------------------------------  // acclient.c:182881
CharacterSet *__thiscall CharacterSet::vector_deleting_destructor(CharacterSet *this, unsigned int a2)
{
  CharacterSet *v2; // esi@1

  v2 = this;
  CharacterSet::~CharacterSet(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006EC580) --------------------------------------------------------  // acclient.c:768202
int _E1_87()
{
  return atexit(_E2_87);
}

