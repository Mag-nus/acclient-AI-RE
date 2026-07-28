/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CliDatEvents
   Object     : ENGINE\engine_events\CliDatEvents.obj
   Functions  : 13
   Addresses  : 00677C70 - 00714F90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00677C70) --------------------------------------------------------  // acclient.c:654451
void __thiscall CAllIterationList::PTaggedIterationList::Serialize(CAllIterationList::PTaggedIterationList *this, Archive *io_archive)
{
  CAllIterationList::PTaggedIterationList *v2; // esi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_archive, 8u);
  v3 = Archive::GetBytes(io_archive, 8u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v3 = LODWORD(v2->idDatFile);
      *(_DWORD *)(v3 + 4) = HIDWORD(v2->idDatFile);
      ((void (__stdcall *)(_DWORD))v2->List.vfptr->Serialize)(io_archive);
      return;
    }
    LODWORD(v2->idDatFile) = *(_DWORD *)v3;
    HIDWORD(v2->idDatFile) = *(_DWORD *)(v3 + 4);
  }
  v2->List.vfptr->Serialize(&v2->List, io_archive);
}

//----- (00677CD0) --------------------------------------------------------  // acclient.c:654475
void __thiscall CAllIterationList::PTaggedIterationList::PTaggedIterationList(CAllIterationList::PTaggedIterationList *this)
{
  this->vfptr = (CAllIterationList::PTaggedIterationListVtbl *)&CAllIterationList::PTaggedIterationList::vftable;
  CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&this->List);
}
// 7FE12C: using guessed type void (__thiscall *CAllIterationList::PTaggedIterationList::vftable)(CAllIterationList::PTaggedIterationList *this, struct Archive *);

//----- (00677CF0) --------------------------------------------------------  // acclient.c:654483
void __thiscall SmartArray<CAllIterationList::PTaggedIterationList,1>::Reset(SmartArray<CAllIterationList::PTaggedIterationList,1> *this)
{
  SmartArray<CAllIterationList::PTaggedIterationList,1> *v1; // ebx@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int v4; // eax@6
  int v5; // edi@7
  int v6; // ebp@7
  int v7; // esi@8
  int v8; // [sp+10h] [bp-20h]@0
  int v9; // [sp+14h] [bp-1Ch]@0
  CMostlyConsecutiveIntSet v10; // [sp+18h] [bp-18h]@8

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    if ( v1->m_data )
      CAllIterationList::PTaggedIterationList::vector_deleting_destructor(v1->m_data, 3u);
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v4 = (v2 & 0x7FFFFFFF) - 1;
    if ( v4 >= 0 )
    {
      v5 = v4;
      v6 = v4 + 1;
      do
      {
        CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&v10);
        v7 = (int)&v1->m_data[v5];
        *(_DWORD *)(v7 + 8) = v8;
        *(_DWORD *)(v7 + 12) = v9;
        SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v7 + 20), (int)&v10.m_Ints);
        *(_BYTE *)(v7 + 32) = v10.m_bSorted;
        if ( (v10.m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v10.m_Ints.m_data);
        --v5;
        --v6;
      }
      while ( v6 );
    }
  }
}

//----- (00677DB0) --------------------------------------------------------  // acclient.c:654533
char __thiscall SmartArray<CAllIterationList::PTaggedIterationList,1>::grow(SmartArray<CAllIterationList::PTaggedIterationList,1> *this, unsigned int i_nSize)
{
  SmartArray<CAllIterationList::PTaggedIterationList,1> *v2; // ebx@1
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
      SmartArray<CAllIterationList::PTaggedIterationList,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](40 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      v12 = (int)((char *)v5 + 4);
      vector_constructor_iterator(
        (char *)v5 + 4,
        0x28u,
        i_nSize,
        (void *(__thiscall *)(void *))CAllIterationList::PTaggedIterationList::PTaggedIterationList);
      if ( v6 )
      {
        if ( v2->m_data )
        {
          v7 = v2->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = -32 - v6;
            v9 = v6 + 40 * v7 + 32;
            v11 = v2->m_num;
            do
            {
              v10 = (int)((char *)v2->m_data + v9 + v8);
              *(_DWORD *)(v9 - 24) = *(_DWORD *)(v10 + 8);
              *(_DWORD *)(v9 - 20) = *(_DWORD *)(v10 + 12);
              SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v9 - 12), v10 + 20);
              *(_BYTE *)v9 = *(_BYTE *)(v10 + 32);
              v9 -= 40;
              --v11;
            }
            while ( v11 );
            v3 = i_nSize;
            v6 = v12;
          }
          if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            if ( v2->m_data )
              CAllIterationList::PTaggedIterationList::vector_deleting_destructor(v2->m_data, 3u);
          }
        }
        v2->m_data = (CAllIterationList::PTaggedIterationList *)v6;
        v2->m_sizeAndDeallocate = v3 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00677EC0) --------------------------------------------------------  // acclient.c:654608
char __thiscall SmartArray<CAllIterationList::PTaggedIterationList,1>::SetNElements(SmartArray<CAllIterationList::PTaggedIterationList,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  const unsigned int v3; // ebx@1
  SmartArray<CAllIterationList::PTaggedIterationList,1> *v4; // edi@1
  unsigned int v5; // eax@3
  char result; // al@5
  const unsigned int v7; // ebp@7
  const unsigned int v8; // ebx@8
  int v9; // esi@9
  int v10; // [sp+10h] [bp-20h]@0
  int v11; // [sp+14h] [bp-1Ch]@0
  CMostlyConsecutiveIntSet v12; // [sp+18h] [bp-18h]@9

  v3 = i_nSize;
  v4 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v7 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      v8 = i_nSize;
      do
      {
        CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&v12);
        v9 = (int)&v4->m_data[v8];
        *(_DWORD *)(v9 + 8) = v10;
        *(_DWORD *)(v9 + 12) = v11;
        SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v9 + 20), (int)&v12.m_Ints);
        *(_BYTE *)(v9 + 32) = v12.m_bSorted;
        if ( (v12.m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v12.m_Ints.m_data);
        ++v7;
        ++v8;
      }
      while ( v7 < v4->m_num );
      v3 = i_nSize;
    }
    goto LABEL_13;
  }
  if ( i_bGrowExactly )
    v5 = i_nSize;
  else
    v5 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<CAllIterationList::PTaggedIterationList,1>::grow(v4, v5);
  if ( result )
  {
LABEL_13:
    v4->m_num = v3;
    result = 1;
  }
  return result;
}

//----- (00677F90) --------------------------------------------------------  // acclient.c:654662
void __thiscall SmartArray<CAllIterationList::PTaggedIterationList,1>::Serialize(SmartArray<CAllIterationList::PTaggedIterationList,1> *this, Archive *io_rcArchive)
{
  SmartArray<CAllIterationList::PTaggedIterationList,1> *v2; // esi@1
  unsigned int v3; // ebx@1
  unsigned int v4; // eax@1
  int v5; // ebp@1
  unsigned int i; // ebx@9

  v2 = this;
  v3 = this->m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  v5 = 0;
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
  {
    if ( v3 > Archive::GetSizeLeft(io_rcArchive) )
    {
      Archive::RaiseError(io_rcArchive);
      return;
    }
    v2->m_num = 0;
    SmartArray<CAllIterationList::PTaggedIterationList,1>::SetNElements(v2, v3, 1);
  }
  for ( i = 0; i < v2->m_num; ++v5 )
  {
    v2->m_data[v5].vfptr->Serialize(&v2->m_data[v5], io_rcArchive);
    ++i;
  }
}

//----- (00678020) --------------------------------------------------------  // acclient.c:654700
char __thiscall SmartArray<CAllIterationList::PTaggedIterationList,1>::AddToEnd(SmartArray<CAllIterationList::PTaggedIterationList,1> *this, CAllIterationList::PTaggedIterationList *i_rData)
{
  SmartArray<CAllIterationList::PTaggedIterationList,1> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2
  char result; // al@2
  int v6; // edi@3

  v2 = this;
  v3 = this->m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        (result = SmartArray<CAllIterationList::PTaggedIterationList,1>::grow(v2, v4)) != 0) )
  {
    v6 = (int)&v2->m_data[v2->m_num];
    *(_QWORD *)(v6 + 8) = i_rData->idDatFile;
    SmartArray<int,1>::operator=((SmartArray<QuickButton *,1> *)(v6 + 20), (int)&i_rData->List.m_Ints);
    *(_BYTE *)(v6 + 32) = i_rData->List.m_bSorted;
    ++v2->m_num;
    result = 1;
  }
  return result;
}

//----- (00678090) --------------------------------------------------------  // acclient.c:654725
void __thiscall CAllIterationList::Serialize(CAllIterationList *this, Archive *io_archive)
{
  SmartArray<CAllIterationList::PTaggedIterationList,1>::Serialize(&this->m_Lists, io_archive);
}

//----- (006780A0) --------------------------------------------------------  // acclient.c:654731
int __thiscall CAllIterationList::AddIterationList(CAllIterationList *this, unsigned __int64 idDatFile)
{
  CAllIterationList *v2; // edi@1
  int v3; // esi@1
  int v4; // eax@3
  CAllIterationList::PTaggedIterationList i_rData; // [sp+8h] [bp-28h]@1

  v2 = this;
  i_rData.vfptr = (CAllIterationList::PTaggedIterationListVtbl *)&CAllIterationList::PTaggedIterationList::vftable;
  CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(&i_rData.List);
  v3 = (int)&v2->m_Lists;
  SmartArray<CAllIterationList::PTaggedIterationList,1>::AddToEnd(&v2->m_Lists, &i_rData);
  if ( (i_rData.List.m_Ints.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](i_rData.List.m_Ints.m_data);
  v4 = 40 * (v2->m_Lists.m_num - 1);
  *(_QWORD *)(v4 + *(_DWORD *)v3 + 8) = idDatFile;
  return v4 + *(_DWORD *)v3 + 16;
}
// 7FE12C: using guessed type void (__thiscall *CAllIterationList::PTaggedIterationList::vftable)(CAllIterationList::PTaggedIterationList *this, struct Archive *);

//----- (00714F60) --------------------------------------------------------  // acclient.c:807877
int sub_714F60()
{
  return atexit(nullsub_118);
}

//----- (00714F70) --------------------------------------------------------  // acclient.c:807883
int _E76_93()
{
  return atexit(nullsub_119);
}

//----- (00714F80) --------------------------------------------------------  // acclient.c:807889
int _E79_88()
{
  return atexit(_E80_85);
}

//----- (00714F90) --------------------------------------------------------  // acclient.c:807895
int sub_714F90()
{
  return atexit(nullsub_117);
}

