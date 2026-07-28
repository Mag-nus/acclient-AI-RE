/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PageData
   Object     : AC\acbook\PageData.obj
   Functions  : 20
   Addresses  : 00426670 - 005D26A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00426670) --------------------------------------------------------  // acclient.c:98558
AC1Legacy::PStringBase<char> *__thiscall StructPropertyValue::GetHash(PageData *this)
{
  return &this->authorName;
}

//----- (005D1DC0) --------------------------------------------------------  // acclient.c:510061
PageData *__thiscall PageDataList::Get(PageDataList *this, int _pos)
{
  PageData *result; // eax@3
  int v3; // ecx@3

  if ( _pos < this->numPages && _pos >= 0 )
  {
    result = this->first;
    v3 = 0;
    if ( _pos <= 0 )
      return result;
    while ( result )
    {
      result = result->next;
      ++v3;
      if ( v3 >= _pos )
        return result;
    }
  }
  return 0;
}

//----- (005D1DF0) --------------------------------------------------------  // acclient.c:510084
void __thiscall PageDataList::PageDataList(PageDataList *this)
{
  this->vfptr = (PackObjVtbl *)&PageDataList::vftable;
  this->first = 0;
  this->last = 0;
  this->numPages = 0;
  this->maxNumPages = 0;
  this->maxNumCharsPerPage = 0;
  this->packWithText = 1;
}
// 7E8984: using guessed type int (__thiscall *PageDataList::vftable)(void *, char);

//----- (005D1E20) --------------------------------------------------------  // acclient.c:510097
void __thiscall PageDataList::Insert(PageDataList *this, PageData *_pd, int _pos)
{
  PageData *v3; // edx@2
  PageData *v4; // edx@6
  PageData *v5; // eax@10
  int v6; // esi@10

  if ( !_pos )
  {
    _pd->prev = 0;
    _pd->next = this->first;
    v3 = this->first;
    if ( v3 )
    {
      v3->prev = _pd;
      this->first = _pd;
      ++this->numPages;
    }
    else
    {
      this->last = _pd;
      this->first = _pd;
      ++this->numPages;
    }
    return;
  }
  if ( _pos < this->numPages )
  {
    if ( _pos >= 0 )
    {
      v5 = this->first;
      v6 = 0;
      if ( _pos <= 0 )
      {
LABEL_15:
        _pd->prev = v5->prev;
        _pd->next = v5;
        v5->prev->next = _pd;
        v5->prev = _pd;
        ++this->numPages;
        return;
      }
      while ( v5 )
      {
        v5 = v5->next;
        ++v6;
        if ( v6 >= _pos )
          goto LABEL_15;
      }
    }
    v5 = 0;
    goto LABEL_15;
  }
  _pd->prev = this->last;
  _pd->next = 0;
  v4 = this->last;
  if ( v4 )
  {
    v4->next = _pd;
    this->last = _pd;
    ++this->numPages;
  }
  else
  {
    this->first = _pd;
    this->last = _pd;
    ++this->numPages;
  }
}

//----- (005D1ED0) --------------------------------------------------------  // acclient.c:510168
PageData *__thiscall PageDataList::Remove(PageDataList *this, int _pos)
{
  PageData *result; // eax@3
  int v3; // edx@3
  PageData *v4; // edx@7
  PageData *v5; // edx@11

  if ( _pos >= this->numPages || _pos < 0 )
    return 0;
  result = this->first;
  v3 = 0;
  if ( _pos > 0 )
  {
    while ( result )
    {
      result = result->next;
      ++v3;
      if ( v3 >= _pos )
        goto LABEL_6;
    }
    return 0;
  }
LABEL_6:
  if ( result )
  {
    v4 = result->prev;
    if ( v4 )
      v4->next = result->next;
    else
      this->first = result->next;
    v5 = result->next;
    if ( v5 )
    {
      v5->prev = result->prev;
      --this->numPages;
    }
    else
    {
      this->last = result->prev;
      --this->numPages;
    }
  }
  return result;
}

//----- (005D1F40) --------------------------------------------------------  // acclient.c:510214
void __thiscall PageDataList::Delete(PageDataList *this, int _pos)
{
  PageData *v2; // eax@1

  v2 = PageDataList::Remove(this, _pos);
  if ( v2 )
    v2->vfptr->__vecDelDtor((PackObj *)v2, 1u);
}

//----- (005D1F60) --------------------------------------------------------  // acclient.c:510224
void __thiscall PageDataList::Flush(PageDataList *this)
{
  PageDataList *v1; // esi@1
  PageData *v2; // ecx@3
  PageData *v3; // eax@4
  PageData *v4; // eax@7

  v1 = this;
  while ( v1->first )
  {
    if ( v1->numPages > 0 )
    {
      v2 = v1->first;
      if ( v2 )
      {
        v3 = v2->prev;
        if ( v3 )
          v3->next = v2->next;
        else
          v1->first = v2->next;
        v4 = v2->next;
        if ( v4 )
          v4->prev = v2->prev;
        else
          v1->last = v2->prev;
        --v1->numPages;
        ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (005D1FC0) --------------------------------------------------------  // acclient.c:510257
void __thiscall PageData::PageData(PageData *this)
{
  PageData *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PageData::vftable;
  this->authorID = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->authorName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->authorAccount.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v1->textIncluded = 1;
  v1->ignoreAuthor = 0;
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->pageText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v1->prev = 0;
  v1->next = 0;
}
// 7CC420: using guessed type int (__thiscall *PageData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D2020) --------------------------------------------------------  // acclient.c:510285
void __thiscall PageData::PageData(PageData *this, unsigned int _authorID, AC1Legacy::PStringBase<char> *_authorName, AC1Legacy::PStringBase<char> *_authorAccount, AC1Legacy::PStringBase<char> *_pageText, const int _ignoreAuthor)
{
  PageData *v6; // esi@1
  AC1Legacy::PSRefBuffer<char> *v7; // eax@1
  AC1Legacy::PSRefBuffer<char> *v8; // eax@1
  AC1Legacy::PSRefBuffer<char> *v9; // eax@1

  v6 = this;
  this->authorID = _authorID;
  this->vfptr = (PackObjVtbl *)&PageData::vftable;
  v7 = _authorName->m_buffer;
  this->authorName.m_buffer = _authorName->m_buffer;
  InterlockedIncrement((volatile LONG *)&v7->m_cRef);
  v8 = _authorAccount->m_buffer;
  v6->authorAccount.m_buffer = _authorAccount->m_buffer;
  InterlockedIncrement((volatile LONG *)&v8->m_cRef);
  v6->ignoreAuthor = _ignoreAuthor;
  v6->textIncluded = 1;
  v9 = _pageText->m_buffer;
  v6->pageText.m_buffer = _pageText->m_buffer;
  InterlockedIncrement((volatile LONG *)&v9->m_cRef);
  v6->prev = 0;
  v6->next = 0;
}
// 7CC420: using guessed type int (__thiscall *PageData::vftable)(void *, char);

//----- (005D2090) --------------------------------------------------------  // acclient.c:510312
void __thiscall PageDataList::~PageDataList(PageDataList *this)
{
  PageDataList *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PageDataList::vftable;
  PageDataList::Flush(this);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8984: using guessed type int (__thiscall *PageDataList::vftable)(void *, char);

//----- (005D20B0) --------------------------------------------------------  // acclient.c:510325
int __thiscall PageDataList::UnPack(PageDataList *this, void **addr, unsigned int size)
{
  void **v3; // edi@1
  PageDataList *v4; // ebx@1
  char *v5; // edx@1
  char *v6; // ecx@1
  char *v7; // eax@1
  void **v8; // ecx@1
  void *v9; // eax@3
  PageData *v10; // esi@3
  volatile LONG *v11; // ST04_4@4
  volatile LONG *v12; // ST04_4@4
  volatile LONG *v13; // ST04_4@4
  PageData *v14; // eax@6
  int v15; // ecx@9
  bool v16; // zf@9
  void **addra; // [sp+10h] [bp+4h]@2
  unsigned int sizea; // [sp+14h] [bp+8h]@1

  v3 = addr;
  v4 = this;
  sizea = (unsigned int)((char *)*addr + size);
  PageDataList::Flush(this);
  v4->maxNumPages = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  v4->maxNumCharsPerPage = *(_DWORD *)v5;
  v6 = (char *)*addr + 4;
  v7 = v6;
  *addr = v6;
  v8 = *(void ***)v6;
  *addr = v7 + 4;
  if ( (signed int)v8 > 0 )
  {
    addra = v8;
    do
    {
      v9 = operator new(0x24u);
      v10 = (PageData *)v9;
      if ( v9 )
      {
        *(_DWORD *)v9 = &PageData::vftable;
        *((_DWORD *)v9 + 1) = 0;
        v11 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
        *((_DWORD *)v9 + 2) = AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement(v11);
        v12 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
        v10->authorAccount.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement(v12);
        v10->textIncluded = 1;
        v10->ignoreAuthor = 0;
        v13 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
        v10->pageText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
        InterlockedIncrement(v13);
        v10->prev = 0;
        v10->next = 0;
      }
      else
      {
        v10 = 0;
      }
      ((void (__thiscall *)(PageData *, void **, int))v10->vfptr->UnPack)(v10, v3, sizea - (_DWORD)*v3);
      v10->prev = v4->last;
      v10->next = 0;
      v14 = v4->last;
      if ( v14 )
        v14->next = v10;
      else
        v4->first = v10;
      v15 = v4->numPages + 1;
      v16 = addra == (void **)1;
      v4->last = v10;
      v4->numPages = v15;
      addra = (void **)((char *)addra - 1);
    }
    while ( !v16 );
  }
  return 1;
}
// 7CC420: using guessed type int (__thiscall *PageData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D21C0) --------------------------------------------------------  // acclient.c:510408
int __thiscall PageData::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@1
  int v4; // eax@5
  int v5; // ebx@6
  int v6; // eax@10
  int v7; // ebx@11
  int v8; // eax@15
  int v9; // ecx@16

  v2 = this;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  v3 = *(_DWORD *)(this + 8);
  if ( v3 != *(_DWORD *)(a2 + 8) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    v4 = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(v2 + 8) = v4;
    InterlockedIncrement((volatile LONG *)(v4 + 4));
  }
  v5 = *(_DWORD *)(v2 + 12);
  if ( v5 != *(_DWORD *)(a2 + 12) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v6 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v2 + 12) = v6;
    InterlockedIncrement((volatile LONG *)(v6 + 4));
  }
  v7 = *(_DWORD *)(v2 + 24);
  if ( v7 != *(_DWORD *)(a2 + 24) )
  {
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    v8 = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(v2 + 24) = v8;
    InterlockedIncrement((volatile LONG *)(v8 + 4));
  }
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(a2 + 20);
  v9 = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v2 + 32) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 16) = v9;
  return v2;
}

//----- (005D2280) --------------------------------------------------------  // acclient.c:510457
PageDataList *__thiscall PageDataList::vector_deleting_destructor(PageDataList *this, unsigned int a2)
{
  PageDataList *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PageDataList::vftable;
  PageDataList::Flush(this);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8984: using guessed type int (__thiscall *PageDataList::vftable)(void *, char);

//----- (005D22B0) --------------------------------------------------------  // acclient.c:510473
void __thiscall PageData::PageData(PageData *this, PageData *_pd, int _includeText)
{
  PageData *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@1
  AC1Legacy::PSRefBuffer<char> *v5; // eax@1
  int v6; // eax@3
  int v7; // ebx@5
  volatile LONG *v8; // ST00_4@5
  AC1Legacy::PSRefBuffer<char> *v9; // edi@10
  int _includeTexta; // [sp+18h] [bp+8h]@6

  v3 = this;
  this->vfptr = (PackObjVtbl *)&PageData::vftable;
  this->authorID = _pd->authorID;
  v4 = _pd->authorName.m_buffer;
  this->authorName.m_buffer = v4;
  InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  v5 = _pd->authorAccount.m_buffer;
  v3->authorAccount.m_buffer = v5;
  InterlockedIncrement((volatile LONG *)&v5->m_cRef);
  v6 = _pd->textIncluded && _includeText;
  v3->textIncluded = v6;
  v3->ignoreAuthor = _pd->ignoreAuthor;
  v7 = (int)&v3->pageText;
  v8 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v3->pageText.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v8);
  v3->prev = 0;
  v3->next = 0;
  if ( _includeText )
  {
    _includeTexta = *(_DWORD *)v7;
    if ( *(AC1Legacy::PSRefBuffer<char> **)v7 != _pd->pageText.m_buffer )
    {
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v7 + 4)) )
      {
        if ( _includeTexta )
          (**(void (__stdcall ***)(_DWORD))_includeTexta)(1);
      }
      v9 = _pd->pageText.m_buffer;
      *(_DWORD *)v7 = v9;
      InterlockedIncrement((volatile LONG *)&v9->m_cRef);
    }
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(&v3->pageText, &name);
  }
}
// 7CC420: using guessed type int (__thiscall *PageData::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005D2380) --------------------------------------------------------  // acclient.c:510526
int __thiscall PageData::Pack(PageData *this, void **addr, unsigned int size)
{
  PageData *v3; // ebx@1
  AC1Legacy::PStringBase<char> *v4; // esi@1
  int v5; // ebp@1
  int v6; // ebp@1
  int v7; // eax@1
  void *v8; // edi@1
  int result; // eax@1
  char *v10; // eax@2
  char *v11; // edx@2
  char *v12; // ecx@2
  char *v13; // eax@2
  AC1Legacy::PStringBase<char> *v14; // ecx@2
  char *v15; // ebx@2
  unsigned int packed_size; // [sp+10h] [bp-8h]@1
  AC1Legacy::PStringBase<char> *v17; // [sp+14h] [bp-4h]@1

  v3 = this;
  v4 = &this->pageText;
  packed_size = 0;
  v17 = &this->pageText;
  v5 = AC1Legacy::PStringBase<char>::Pack(&this->authorName, (void **)&packed_size, 0);
  v6 = AC1Legacy::PStringBase<char>::Pack(&v3->authorAccount, (void **)&packed_size, 0) + v5;
  v7 = AC1Legacy::PStringBase<char>::Pack(v4, (void **)&packed_size, 0);
  v8 = *addr;
  result = v7 + v6 + 16;
  packed_size = result;
  if ( size >= result )
  {
    *(_DWORD *)v8 = v3->authorID;
    v10 = (char *)*addr + 4;
    *addr = v10;
    AC1Legacy::PStringBase<char>::Pack(&v3->authorName, addr, size + (_BYTE *)v8 - v10);
    AC1Legacy::PStringBase<char>::Pack(&v3->authorAccount, addr, size + (_BYTE *)v8 - (_BYTE *)*addr);
    *(_DWORD *)*addr = -65534;
    v11 = (char *)*addr + 4;
    *addr = v11;
    *(_DWORD *)v11 = v3->textIncluded;
    v12 = (char *)*addr + 4;
    *addr = v12;
    v13 = v12;
    v14 = v17;
    *(_DWORD *)v13 = v3->ignoreAuthor;
    v15 = (char *)*addr + 4;
    *addr = v15;
    AC1Legacy::PStringBase<char>::Pack(v14, addr, size + (_BYTE *)v8 - v15);
    result = packed_size;
  }
  return result;
}

//----- (005D2460) --------------------------------------------------------  // acclient.c:510579
int __thiscall PageData::UnPack(PageData *this, void **addr, unsigned int size)
{
  PageData *v3; // edi@1
  char *v4; // ebx@1
  char *v5; // eax@1
  int v6; // ecx@1
  char *v7; // eax@1
  int v8; // edx@1
  char *v9; // ecx@3
  AC1Legacy::PStringBase<char> *v10; // ecx@5
  int result; // eax@6

  v3 = this;
  v4 = (char *)*addr + size;
  this->authorID = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  AC1Legacy::PStringBase<char>::UnPack(&this->authorName, addr, v4 - v5);
  AC1Legacy::PStringBase<char>::UnPack(&v3->authorAccount, addr, v4 - (_BYTE *)*addr);
  v6 = *(_DWORD *)*addr;
  v7 = (char *)*addr + 4;
  v8 = *(_DWORD *)*addr >> 16;
  *addr = v7;
  if ( v8 == 0xFFFF )
  {
    if ( (unsigned __int16)v6 == 2 )
    {
      v3->textIncluded = *(_DWORD *)v7;
      v9 = (char *)*addr + 4;
      *addr = v9;
      v3->ignoreAuthor = *(_DWORD *)v9;
      *addr = (char *)*addr + 4;
    }
  }
  else
  {
    v3->textIncluded = v6;
    v3->ignoreAuthor = 0;
  }
  v10 = &v3->pageText;
  if ( v3->textIncluded )
  {
    AC1Legacy::PStringBase<char>::UnPack(v10, addr, v4 - (_BYTE *)*addr);
    result = 1;
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(v10, &name);
    result = 1;
  }
  return result;
}

//----- (005D2510) --------------------------------------------------------  // acclient.c:510633
int __thiscall PageData::PackNoText(PageData *this, void **addr, unsigned int size)
{
  PageData *v3; // ebx@1
  int v4; // edi@1
  int result; // eax@1
  void *v6; // edi@1
  char *v7; // eax@2
  char *v8; // edx@2
  char *v9; // ecx@2
  unsigned int packed_size; // [sp+10h] [bp-4h]@1

  v3 = this;
  packed_size = 0;
  v4 = AC1Legacy::PStringBase<char>::Pack(&this->authorName, (void **)&packed_size, 0);
  result = v4 + AC1Legacy::PStringBase<char>::Pack(&v3->authorAccount, (void **)&packed_size, 0) + 16;
  v6 = *addr;
  packed_size = result;
  if ( size >= result )
  {
    *(_DWORD *)v6 = v3->authorID;
    v7 = (char *)*addr + 4;
    *addr = v7;
    AC1Legacy::PStringBase<char>::Pack(&v3->authorName, addr, size + (_BYTE *)v6 - v7);
    AC1Legacy::PStringBase<char>::Pack(&v3->authorAccount, addr, size + (_BYTE *)v6 - (_BYTE *)*addr);
    *(_DWORD *)*addr = -65534;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = 0;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->ignoreAuthor;
    *addr = (char *)*addr + 4;
    result = packed_size;
  }
  return result;
}

//----- (005D25C0) --------------------------------------------------------  // acclient.c:510671
int __thiscall PageDataList::operator=(int this, int a2)
{
  int v2; // esi@1
  int i; // edi@1
  PageData *v4; // eax@2
  int v5; // eax@3
  int v6; // ecx@5
  int v7; // ecx@8

  v2 = this;
  *(_DWORD *)(this + 4) = 0;
  *(_DWORD *)(this + 8) = 0;
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  for ( i = *(_DWORD *)(a2 + 4); i; i = *(_DWORD *)(i + 32) )
  {
    v4 = (PageData *)operator new(0x24u);
    if ( v4 )
      PageData::PageData(v4, (PageData *)i, 1);
    else
      v5 = 0;
    *(_DWORD *)(v5 + 28) = *(_DWORD *)(v2 + 8);
    *(_DWORD *)(v5 + 32) = 0;
    v6 = *(_DWORD *)(v2 + 8);
    if ( v6 )
      *(_DWORD *)(v6 + 32) = v5;
    else
      *(_DWORD *)(v2 + 4) = v5;
    v7 = *(_DWORD *)(v2 + 12) + 1;
    *(_DWORD *)(v2 + 8) = v5;
    *(_DWORD *)(v2 + 12) = v7;
  }
  return v2;
}

//----- (005D2640) --------------------------------------------------------  // acclient.c:510709
signed int __thiscall PageDataList::pack_size(PageDataList *this)
{
  PageDataList *v1; // ebx@1
  PageData *v2; // esi@1
  signed int i; // edi@1
  int v4; // eax@4
  void *nullPtr; // [sp+0h] [bp-4h]@1

  nullPtr = this;
  v1 = this;
  v2 = this->first;
  nullPtr = 0;
  for ( i = 12; v2; i += v4 )
  {
    if ( v1->packWithText && v2->textIncluded )
      v4 = ((int (__thiscall *)(PageData *, void **, _DWORD))v2->vfptr->Pack)(v2, &nullPtr, 0);
    else
      v4 = PageData::PackNoText(v2, &nullPtr, 0);
    v2 = v2->next;
  }
  return i;
}

//----- (005D26A0) --------------------------------------------------------  // acclient.c:510733
signed int __thiscall PageDataList::Pack(PageDataList *this, void **addr, unsigned int size)
{
  PageDataList *v3; // ebx@1
  signed int result; // eax@1
  unsigned int v5; // edx@1
  void *v6; // ebp@1
  char *v7; // edi@2
  char *v8; // ecx@2
  PageData *v9; // edi@2
  unsigned int packed_size; // [sp+10h] [bp-4h]@1

  v3 = this;
  result = PageDataList::pack_size(this);
  v5 = size;
  v6 = *addr;
  packed_size = result;
  if ( size >= result )
  {
    *(_DWORD *)v6 = v3->maxNumPages;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->maxNumCharsPerPage;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->numPages;
    *addr = (char *)*addr + 4;
    v9 = v3->first;
    if ( v9 )
    {
      while ( 1 )
      {
        if ( v3->packWithText && v9->textIncluded )
          ((void (__thiscall *)(PageData *, void **, int))v9->vfptr->Pack)(v9, addr, v5 + (_BYTE *)v6 - (_BYTE *)*addr);
        else
          PageData::PackNoText(v9, addr, v5 + (_BYTE *)v6 - (_BYTE *)*addr);
        v9 = v9->next;
        if ( !v9 )
          break;
        v5 = size;
      }
      result = packed_size;
    }
  }
  return result;
}

