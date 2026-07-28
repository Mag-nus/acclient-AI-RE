/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : IterationList
   Object     : ENGINE\diskcon\IterationList.obj
   Functions  : 6
   Addresses  : 0066FF50 - 006702E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0066FF50) --------------------------------------------------------  // acclient.c:646594
int __cdecl CompareInts(const void *a, const void *b)
{
  int result; // eax@2

  if ( *(_DWORD *)a <= *(_DWORD *)b )
    result = (*(_DWORD *)a >= *(_DWORD *)b) - 1;
  else
    result = 1;
  return result;
}

//----- (0066FF80) --------------------------------------------------------  // acclient.c:646606
void __thiscall CMostlyConsecutiveIntSet::Sort(CMostlyConsecutiveIntSet *this)
{
  CMostlyConsecutiveIntSet *v1; // esi@1
  unsigned int v2; // eax@2
  char v3; // dl@3
  int v4; // eax@3
  unsigned int v5; // ecx@5
  int v6; // ecx@6

  v1 = this;
  if ( !this->m_bSorted )
  {
    v2 = this->m_Ints.m_num;
    if ( v2 )
    {
      _qsort(this->m_Ints.m_data, v2, 4u, CompareInts);
      v3 = 0;
      v4 = v1->m_Ints.m_num - 1;
      if ( v1->m_Ints.m_num > 1 )
      {
        do
        {
          if ( v1->m_Ints.m_data[v4] == v1->m_Ints.m_data[v4 - 1] )
          {
            v5 = v1->m_Ints.m_num;
            if ( v4 < v5 )
            {
              v6 = v5 - 1;
              v1->m_Ints.m_num = v6;
              if ( v4 != v6 )
              {
                v1->m_Ints.m_data[v4] = v1->m_Ints.m_data[v6];
                v1->m_Ints.m_data[v1->m_Ints.m_num] = 0;
              }
            }
            v3 = 1;
          }
          --v4;
        }
        while ( v4 );
        if ( v3 )
          _qsort(v1->m_Ints.m_data, v1->m_Ints.m_num, 4u, CompareInts);
      }
    }
    v1->m_bSorted = 1;
  }
}

//----- (00670020) --------------------------------------------------------  // acclient.c:646655
void __thiscall CMostlyConsecutiveIntSet::CMostlyConsecutiveIntSet(CMostlyConsecutiveIntSet *this)
{
  this->vfptr = (CMostlyConsecutiveIntSetVtbl *)&CMostlyConsecutiveIntSet::vftable;
  this->m_Ints.m_data = 0;
  this->m_Ints.m_sizeAndDeallocate = 0;
  this->m_Ints.m_num = 0;
  this->m_bSorted = 1;
}
// 7FDB44: using guessed type void (__thiscall *CMostlyConsecutiveIntSet::vftable)(CMostlyConsecutiveIntSet *this, struct Archive *);

//----- (00670040) --------------------------------------------------------  // acclient.c:646666
char __thiscall SmartArray<int,1>::SetNElements(SmartArray<int,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<int,1> *v3; // esi@1
  unsigned int v4; // eax@3
  char result; // al@5
  unsigned int i; // eax@7

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
      this->m_data[i] = 0;
    goto LABEL_9;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (006700A0) --------------------------------------------------------  // acclient.c:646695
void __thiscall CMostlyConsecutiveIntSet::Serialize(CMostlyConsecutiveIntSet *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  char v3; // al@1
  CMostlyConsecutiveIntSet *v4; // ebp@1
  unsigned int v5; // ebx@2
  unsigned int v6; // edi@2
  unsigned int v7; // eax@2
  unsigned int v8; // eax@9
  int v9; // edx@10
  int v10; // ecx@10
  int v11; // ebp@13
  unsigned int v12; // eax@14
  int v13; // ebx@18
  unsigned int v14; // eax@18
  int v15; // ecx@20
  int v16; // ebp@23
  int v17; // ebp@23
  unsigned int v18; // eax@23
  const unsigned int v19; // edi@29
  Archive *v20; // ecx@29
  unsigned int v21; // ebp@29
  unsigned int v22; // eax@29
  unsigned int v23; // eax@32
  int v24; // edi@35
  Archive *v25; // ebx@35
  unsigned int v26; // eax@36
  unsigned int v27; // eax@41
  int v28; // eax@45
  CMostlyConsecutiveIntSet *v29; // [sp+10h] [bp-4h]@1
  Archive *io_archivea; // [sp+18h] [bp+4h]@2
  Archive *io_archiveb; // [sp+18h] [bp+4h]@29

  v2 = io_archive;
  v3 = LOBYTE(io_archive->m_flags);
  v4 = this;
  v29 = this;
  if ( v3 & 1 )
  {
    CMostlyConsecutiveIntSet::Sort(this);
    v5 = v4->m_Ints.m_num;
    io_archivea = (Archive *)v4->m_Ints.m_num;
    v6 = 0;
    Archive::CheckAlignment(v2, 4u);
    v7 = Archive::GetBytes(v2, 4u);
    if ( v7 )
    {
      if ( v2->m_flags & 1 )
      {
        *(_DWORD *)v7 = v5;
      }
      else
      {
        io_archivea = *(Archive **)v7;
        v5 = *(_DWORD *)v7;
      }
    }
    if ( !v5 )
      return;
    while ( 1 )
    {
      v8 = v6;
      if ( v6 < v5 )
      {
        v9 = (int)&v4->m_Ints.m_data[v6];
        v10 = *(_DWORD *)v9;
        do
        {
          if ( v10 != *(_DWORD *)v9 )
            break;
          ++v8;
          ++v10;
          v9 += 4;
        }
        while ( v8 < v5 );
      }
      v11 = v6 - v8;
      if ( (signed int)(v6 - v8) >= -2 )
      {
        v16 = v29->m_Ints.m_data[v6++];
        v17 = v16 & 0x7FFFFFFF;
        Archive::CheckAlignment(v2, 4u);
        v18 = Archive::GetBytes(v2, 4u);
        if ( v18 && v2->m_flags & 1 )
          *(_DWORD *)v18 = v17;
      }
      else
      {
        Archive::CheckAlignment(v2, 4u);
        v12 = Archive::GetBytes(v2, 4u);
        if ( v12 )
        {
          if ( v2->m_flags & 1 )
            *(_DWORD *)v12 = v11;
          else
            v11 = *(_DWORD *)v12;
        }
        v13 = (int)&v29->m_Ints.m_data[v6];
        Archive::CheckAlignment(v2, 4u);
        v14 = Archive::GetBytes(v2, 4u);
        if ( v14 )
        {
          if ( v2->m_flags & 1 )
          {
            v15 = *(_DWORD *)v13;
            v5 = (unsigned int)io_archivea;
            *(_DWORD *)v14 = v15;
            v6 -= v11;
            goto LABEL_26;
          }
          *(_DWORD *)v13 = *(_DWORD *)v14;
        }
        v5 = (unsigned int)io_archivea;
        v6 -= v11;
      }
LABEL_26:
      if ( v6 >= v5 )
        return;
      v4 = v29;
    }
  }
  if ( !(~v3 & 1) )
    return;
  v19 = 0;
  v20 = io_archive;
  io_archiveb = 0;
  v21 = 0;
  Archive::CheckAlignment(v20, 4u);
  v22 = Archive::GetBytes(v2, 4u);
  if ( v22 )
  {
    if ( v2->m_flags & 1 )
    {
      *(_DWORD *)v22 = 0;
    }
    else
    {
      v23 = *(_DWORD *)v22;
      io_archiveb = (Archive *)v23;
      if ( v23 > 0x186A0 )
        goto LABEL_55;
      v19 = v23;
    }
  }
  SmartArray<int,1>::SetNElements(&v29->m_Ints, v19, 1);
  if ( !v19 )
  {
LABEL_53:
    v29->m_bSorted = 1;
    return;
  }
  v24 = (int)io_archiveb;
  v25 = io_archiveb;
  while ( 1 )
  {
    Archive::CheckAlignment(v2, 4u);
    v26 = Archive::GetBytes(v2, 4u);
    if ( v26 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v26 = v24;
      else
        v24 = *(_DWORD *)v26;
    }
    if ( v24 >= 0 )
    {
      if ( v24 & 0x40000000 )
        v24 |= 0x80000000;
      v29->m_Ints.m_data[v21++] = v24;
      goto LABEL_52;
    }
    v24 = -v24;
    Archive::CheckAlignment(v2, 4u);
    v27 = Archive::GetBytes(v2, 4u);
    if ( v27 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v27 = v25;
      else
        v25 = *(Archive **)v27;
    }
    v28 = 0;
    if ( v24 > 0 )
      break;
LABEL_52:
    if ( v21 >= (unsigned int)io_archiveb )
      goto LABEL_53;
  }
  while ( v21 < (unsigned int)io_archiveb )
  {
    v29->m_Ints.m_data[v21++] = (int)v25;
    v25 = (Archive *)((char *)v25 + 1);
    ++v28;
    if ( v28 >= v24 )
      goto LABEL_52;
  }
LABEL_55:
  Archive::RaiseError(v2);
}

//----- (006702E0) --------------------------------------------------------  // acclient.c:646896
char __thiscall CMostlyConsecutiveIntSet::Add(CMostlyConsecutiveIntSet *this, int NewInt)
{
  char *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // eax@2

  v2 = (char *)&this->m_Ints;
  this->m_bSorted = 0;
  v3 = this->m_Ints.m_sizeAndDeallocate & 0x7FFFFFFF;
  if ( this->m_Ints.m_num < v3
    || (v4 = SmartArray<UIChildFramework *,1>::get_new_size(v3 + 1),
        SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v2, v4)) )
    *(_DWORD *)(*(_DWORD *)v2 + 4 * (*((_DWORD *)v2 + 2))++) = NewInt;
  return 1;
}

