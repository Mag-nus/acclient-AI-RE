/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArchiveVersionRow
   Object     : CORE\serialize\ArchiveVersionRow.obj
   Functions  : 9
   Addresses  : 00410050 - 00410430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00410050) --------------------------------------------------------  // acclient.c:75914
void __cdecl Serializer::SerializeObject<unsigned long>(unsigned int *io_object, Archive *io_archive)
{
  unsigned int *v2; // eax@1

  Archive::CheckAlignment(io_archive, 4u);
  v2 = (unsigned int *)Archive::GetBytes(io_archive, 4u);
  if ( v2 )
  {
    if ( io_archive->m_flags & 1 )
      *v2 = *io_object;
    else
      *io_object = *v2;
  }
}

//----- (00410090) --------------------------------------------------------  // acclient.c:75930
void __thiscall SmartArray<ArchiveVersionRow::VersionEntry,1>::Reset(SmartArray<ArchiveVersionRow::VersionEntry,1> *this)
{
  SmartArray<ArchiveVersionRow::VersionEntry,1> *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  int i; // eax@4
  void *v5; // edx@5

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
    for ( i = (v2 & 0x7FFFFFFF) - 1; i >= 0; *((_DWORD *)v5 + 2 * i + 3) = 0 )
    {
      v5 = v1->m_data;
      --i;
      *((_DWORD *)v5 + 2 * i + 2) = 0;
    }
  }
}

//----- (004100F0) --------------------------------------------------------  // acclient.c:75960
unsigned int __thiscall ArchiveVersionRow::GetVersionByToken(ArchiveVersionRow *this, unsigned int i_tokVersion)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  ArchiveVersionRow::VersionEntry *v4; // edi@2
  ArchiveVersionRow::VersionEntry *v5; // ecx@2
  unsigned int result; // eax@5

  v2 = this->m_aVersions.m_num;
  v3 = 0;
  if ( !v2 )
    goto LABEL_11;
  v4 = this->m_aVersions.m_data;
  v5 = this->m_aVersions.m_data;
  while ( v5->tokVersion != i_tokVersion )
  {
    ++v3;
    ++v5;
    if ( v3 >= v2 )
      return 0;
  }
  if ( v3 != -1 )
    result = v4[v3].iVersion;
  else
LABEL_11:
    result = 0;
  return result;
}

//----- (00410130) --------------------------------------------------------  // acclient.c:75990
bool __thiscall SmartArray<ArchiveVersionRow::VersionEntry,1>::grow(SmartArray<ArchiveVersionRow::VersionEntry,1> *this, unsigned int i_nSize)
{
  SmartArray<ArchiveVersionRow::VersionEntry,1> *v2; // esi@1
  bool result; // al@5
  void *v4; // edi@6
  int i; // eax@8
  void *v6; // edx@9

  v2 = this;
  if ( i_nSize < this->m_num )
  {
    result = 0;
  }
  else
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<ArchiveVersionRow::VersionEntry,1>::Reset(this);
      return 1;
    }
    v4 = operator new[](8 * i_nSize);
    if ( v4 )
    {
      if ( v2->m_data )
      {
        for ( i = v2->m_num - 1; i >= 0; *((_DWORD *)v4 + 2 * i + 3) = *((_DWORD *)v6 + 2 * i + 3) )
        {
          --i;
          v6 = v2->m_data;
          *((_DWORD *)v4 + 2 * i + 2) = v2->m_data[i + 1].tokVersion;
        }
        if ( (v2->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          operator delete[](v2->m_data);
      }
      v2->m_data = (ArchiveVersionRow::VersionEntry *)v4;
      v2->m_sizeAndDeallocate = i_nSize | 0x80000000;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (004101E0) --------------------------------------------------------  // acclient.c:76039
bool __thiscall SmartArray<ArchiveVersionRow::VersionEntry,1>::SetNElements(SmartArray<ArchiveVersionRow::VersionEntry,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<ArchiveVersionRow::VersionEntry,1> *v3; // esi@1
  unsigned int v4; // eax@3
  bool result; // al@5
  unsigned int i; // eax@7
  ArchiveVersionRow::VersionEntry *v7; // edx@8

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    for ( i = i_nSize; i < this->m_num; ++i )
    {
      v7 = this->m_data;
      v7[i].tokVersion = 0;
      v7[i].iVersion = 0;
    }
    goto LABEL_9;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<char *,1>::get_new_size(i_nSize);
  result = SmartArray<ArchiveVersionRow::VersionEntry,1>::grow(v3, v4);
  if ( result )
  {
LABEL_9:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (00410240) --------------------------------------------------------  // acclient.c:76073
bool __thiscall ArchiveVersionRow::SetVersion(ArchiveVersionRow *this, unsigned int i_tokVersion, unsigned int i_iVersion)
{
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  ArchiveVersionRow::VersionEntry *v5; // edx@2
  char *v6; // esi@7
  unsigned int v7; // ebx@7
  unsigned int v8; // eax@8
  bool result; // al@10

  v3 = this->m_aVersions.m_num;
  v4 = 0;
  if ( !v3 )
    goto LABEL_7;
  v5 = this->m_aVersions.m_data;
  while ( v5->tokVersion != i_tokVersion )
  {
    ++v4;
    ++v5;
    if ( v4 >= v3 )
      goto LABEL_7;
  }
  if ( v4 != -1 )
  {
    result = this->m_aVersions.m_data[v4].iVersion == i_iVersion;
  }
  else
  {
LABEL_7:
    v6 = (char *)&this->m_aVersions;
    v7 = this->m_aVersions.m_num + 1;
    if ( (this->m_aVersions.m_sizeAndDeallocate & 0x7FFFFFFF) >= v7
      || (v8 = SmartArray<char *,1>::get_new_size(this->m_aVersions.m_num + 1),
          SmartArray<ArchiveVersionRow::VersionEntry,1>::grow((SmartArray<ArchiveVersionRow::VersionEntry,1> *)v6, v8)) )
      *((_DWORD *)v6 + 2) = v7;
    *(_DWORD *)(*(_DWORD *)v6 + 8 * v3) = i_tokVersion;
    *(_DWORD *)(*(_DWORD *)v6 + 8 * v3 + 4) = i_iVersion;
    result = 1;
  }
  return result;
}

//----- (004102D0) --------------------------------------------------------  // acclient.c:76116
void __thiscall ArchiveVersionRow::SerializeRow(ArchiveVersionRow *this, Archive *io_rcArchive)
{
  ArchiveVersionRow *v2; // ebx@1
  unsigned int v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@8
  int v6; // ebp@9
  unsigned int v7; // eax@9

  v2 = this;
  v3 = this->m_aVersions.m_num;
  Archive::CheckAlignment(io_rcArchive, 4u);
  v4 = Archive::GetBytes(io_rcArchive, 4u);
  if ( v4 )
  {
    if ( io_rcArchive->m_flags & 1 )
      *(_DWORD *)v4 = v3;
    else
      v3 = *(_DWORD *)v4;
  }
  if ( !((io_rcArchive->m_flags >> 2) & 1) )
  {
    if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
      SmartArray<ArchiveVersionRow::VersionEntry,1>::SetNElements(
        (SmartArray<ArchiveVersionRow::VersionEntry,1> *)&v2->m_aVersions.m_data,
        v3,
        1);
    v5 = v2->m_aVersions.m_num;
    while ( v5 )
    {
      --v5;
      v6 = (int)&v2->m_aVersions.m_data[v5];
      Archive::CheckAlignment(io_rcArchive, 8u);
      v7 = Archive::GetBytes(io_rcArchive, 8u);
      if ( v7 )
      {
        if ( io_rcArchive->m_flags & 1 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          *(_DWORD *)(v7 + 4) = *(_DWORD *)(v6 + 4);
        }
        else
        {
          *(_DWORD *)v6 = *(_DWORD *)v7;
          *(_DWORD *)(v6 + 4) = *(_DWORD *)(v7 + 4);
        }
      }
    }
  }
}

//----- (00410370) --------------------------------------------------------  // acclient.c:76168
signed int __thiscall ArchiveVersionRow::SerializeHeader(ArchiveVersionRow *this, Archive *io_rcArchive)
{
  ArchiveVersionRow *v2; // ebx@1
  signed int result; // eax@1
  unsigned int v4; // ebp@2
  signed int v5; // edi@2
  unsigned int v6; // eax@2
  unsigned int v7; // ebx@8
  ArchiveVersionRow *v8; // [sp+0h] [bp-4h]@1

  v2 = this;
  result = -1;
  v8 = this;
  if ( ~(unsigned __int8)(io_rcArchive->m_flags >> 2) & 1 )
  {
    v4 = Archive::GetSizeUsed(io_rcArchive);
    v5 = 1298622819;
    Archive::CheckAlignment(io_rcArchive, 4u);
    v6 = Archive::GetBytes(io_rcArchive, 4u);
    if ( v6 )
    {
      if ( io_rcArchive->m_flags & 1 )
        *(_DWORD *)v6 = 1298622819;
      else
        v5 = *(_DWORD *)v6;
    }
    if ( ~LOBYTE(io_rcArchive->m_flags) & 1 )
    {
      if ( v5 < 0 )
      {
        v7 = Archive::GetSizeUsed(io_rcArchive);
        Archive::SetCurrentPosition(io_rcArchive, v5 & 0x3FFFFFFF);
        ArchiveVersionRow::SerializeRow(v8, io_rcArchive);
        Archive::SetCurrentPosition(io_rcArchive, v7);
        return v4;
      }
      if ( !ArchiveVersionRow::SetVersion(v2, 0x436F7265u, v5 & 0x3FFFFFFF) )
        Archive::RaiseError(io_rcArchive);
    }
    result = v4;
  }
  return result;
}

//----- (00410430) --------------------------------------------------------  // acclient.c:76213
bool __thiscall ArchiveVersionRow::SerializeFooter(ArchiveVersionRow *this, unsigned int i_hSerialize, Archive *io_rcArchive)
{
  Archive *v3; // edi@1
  ArchiveVersionRow *v4; // ebx@1
  unsigned int v5; // eax@3
  unsigned int v6; // esi@3
  int v7; // ebx@5
  bool result; // al@7
  unsigned int v9; // eax@12

  v3 = io_rcArchive;
  v4 = this;
  if ( ~(unsigned __int8)(io_rcArchive->m_flags >> 2) & 1 && i_hSerialize != -1 )
  {
    v5 = Archive::PeekBytes(io_rcArchive, i_hSerialize, 4u);
    v6 = v5;
    if ( !v5 )
      return ~(unsigned __int8)(v3->m_flags >> 2) & 1;
    if ( ~LOBYTE(v3->m_flags) & 1 )
    {
      v7 = *(_DWORD *)v5;
      if ( *(_DWORD *)v5 >= 0 )
        return ~(unsigned __int8)(v3->m_flags >> 2) & 1;
      if ( Archive::GetSizeUsed(v3) == (v7 & 0x3FFFFFFF) )
      {
        Serializer::SerializeObject<unsigned long>((unsigned int *)&io_rcArchive, v3);
        Archive::GetBytes(v3, 8 * (_DWORD)io_rcArchive);
        return ~(unsigned __int8)(v3->m_flags >> 2) & 1;
      }
      if ( v7 >= 0 )
        return ~(unsigned __int8)(v3->m_flags >> 2) & 1;
      goto LABEL_9;
    }
    if ( *(_DWORD *)v5 != 1298622819
      || (v9 = v4->m_aVersions.m_num, v9 < 1)
      || v9 == 1 && v4->m_aVersions.m_data->tokVersion != 1131377253 )
    {
LABEL_9:
      Archive::RaiseError(v3);
      return ~(unsigned __int8)(v3->m_flags >> 2) & 1;
    }
    if ( v9 == 1 )
    {
      *(_DWORD *)v6 = 224880995;
      *(_DWORD *)v6 = v4->m_aVersions.m_data->iVersion & 0x3FFFFFFF;
      result = ~(unsigned __int8)(v3->m_flags >> 2) & 1;
    }
    else
    {
      *(_DWORD *)v6 = -1922602653;
      *(_DWORD *)v6 ^= (Archive::GetSizeUsed(v3) ^ *(_DWORD *)v6) & 0x3FFFFFFF;
      ArchiveVersionRow::SerializeRow(v4, v3);
      result = ~(unsigned __int8)(v3->m_flags >> 2) & 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

