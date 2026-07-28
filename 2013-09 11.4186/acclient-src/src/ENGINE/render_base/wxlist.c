/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : wxlist
   Object     : ENGINE\render_base\wxlist.obj
   Functions  : 6
   Addresses  : 006C2650 - 006C27D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006C2650) --------------------------------------------------------  // acclient.c:730815
void __thiscall CBaseList::CBaseList(CBaseList *this, char *pName)
{
  this->m_pFirst = 0;
  this->m_pLast = 0;
  this->m_Count = 0;
  this->m_Cache.m_iCacheSize = 10;
  this->m_Cache.m_iUsed = 0;
  this->m_Cache.m_pHead = 0;
}

//----- (006C2670) --------------------------------------------------------  // acclient.c:730826
void __thiscall CBaseList::RemoveAll(CBaseList *this)
{
  CBaseList *v1; // edi@1
  CBaseList::CNode *v2; // esi@1
  void *v3; // eax@2

  v1 = this;
  v2 = this->m_pFirst;
  if ( this->m_pFirst )
  {
    do
    {
      v3 = v2;
      v2 = v2->m_pNext;
      operator delete(v3);
    }
    while ( v2 );
  }
  v1->m_Count = 0;
  v1->m_pLast = 0;
  v1->m_pFirst = 0;
}

//----- (006C26B0) --------------------------------------------------------  // acclient.c:730850
CBaseList::CNode *__thiscall CBaseList::FindI(CBaseList *this, void *pObj)
{
  CBaseList::CNode *result; // eax@1

  result = this->m_pFirst;
  if ( this->m_pFirst )
  {
    while ( result->m_pObject != pObj )
    {
      if ( result )
        result = result->m_pNext;
      else
        result = this->m_pFirst;
      if ( !result )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    result = 0;
  }
  return result;
}

//----- (006C26E0) --------------------------------------------------------  // acclient.c:730876
__POSITION *__thiscall CBaseList::AddTailI(CBaseList *this, void *pObject)
{
  CBaseList *v2; // esi@1
  __POSITION *result; // eax@1
  CBaseList::CNode *v4; // ecx@4
  int v5; // ecx@5
  int v6; // ecx@6

  v2 = this;
  result = (__POSITION *)this->m_Cache.m_pHead;
  if ( result && (this->m_Cache.m_pHead = (CBaseList::CNode *)result[1].unused, --this->m_Cache.m_iUsed, result)
    || (result = (__POSITION *)operator new(0xCu)) != 0 )
  {
    result[2].unused = (int)pObject;
    result[1].unused = 0;
    result->unused = (int)v2->m_pLast;
    v4 = v2->m_pLast;
    if ( v4 )
    {
      v4->m_pNext = (CBaseList::CNode *)result;
      v6 = v2->m_Count + 1;
      v2->m_pLast = (CBaseList::CNode *)result;
      v2->m_Count = v6;
    }
    else
    {
      v5 = v2->m_Count + 1;
      v2->m_pFirst = (CBaseList::CNode *)result;
      v2->m_pLast = (CBaseList::CNode *)result;
      v2->m_Count = v5;
    }
  }
  return result;
}

//----- (006C2750) --------------------------------------------------------  // acclient.c:730912
int __thiscall CBaseList::AddTail(CBaseList *this, CBaseList *pList)
{
  CBaseList::CNode *v2; // edi@1
  CBaseList *v3; // esi@1
  void *v4; // ebx@2
  void *v5; // eax@2
  CBaseList::CNode *v6; // ecx@5
  int v7; // ecx@8
  int result; // eax@9

  v2 = pList->m_pFirst;
  v3 = this;
  if ( pList->m_pFirst )
  {
    while ( 1 )
    {
      v4 = v2->m_pObject;
      v5 = v3->m_Cache.m_pHead;
      v2 = v2->m_pNext;
      if ( !v5 || (v3->m_Cache.m_pHead = (CBaseList::CNode *)*((_DWORD *)v5 + 1), --v3->m_Cache.m_iUsed, !v5) )
      {
        v5 = operator new(0xCu);
        if ( !v5 )
          break;
      }
      *((_DWORD *)v5 + 2) = v4;
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)v5 = v3->m_pLast;
      v6 = v3->m_pLast;
      if ( v6 )
        v6->m_pNext = (CBaseList::CNode *)v5;
      else
        v3->m_pFirst = (CBaseList::CNode *)v5;
      v7 = v3->m_Count + 1;
      v3->m_pLast = (CBaseList::CNode *)v5;
      v3->m_Count = v7;
      if ( !v2 )
        goto LABEL_9;
    }
    result = 0;
  }
  else
  {
LABEL_9:
    result = 1;
  }
  return result;
}

//----- (006C27D0) --------------------------------------------------------  // acclient.c:730962
void __thiscall CBaseList::~CBaseList(CBaseList *this)
{
  CBaseList *v1; // esi@1
  CBaseList::CNode *v2; // esi@1
  void *v3; // eax@2

  v1 = this;
  CBaseList::RemoveAll(this);
  v2 = v1->m_Cache.m_pHead;
  while ( v2 )
  {
    v3 = v2;
    v2 = v2->m_pNext;
    operator delete(v3);
  }
}

