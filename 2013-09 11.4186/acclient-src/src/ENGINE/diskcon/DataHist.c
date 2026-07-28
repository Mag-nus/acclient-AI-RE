/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DataHist
   Object     : ENGINE\diskcon\DataHist.obj
   Functions  : 7
   Addresses  : 00671650 - 00714D90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00671650) --------------------------------------------------------  // acclient.c:648004
char __thiscall SmartArray<QualifiedDataID,1>::SetNElements(SmartArray<QualifiedDataID,1> *this, const unsigned int i_nSize, bool i_bGrowExactly)
{
  SmartArray<QualifiedDataID,1> *v3; // edi@1
  unsigned int v4; // eax@3
  char result; // al@5
  const unsigned int v6; // esi@7
  int v7; // eax@8
  QualifiedDataID *v8; // ecx@9

  v3 = this;
  if ( (this->m_sizeAndDeallocate & 0x7FFFFFFF) >= i_nSize )
  {
    v6 = i_nSize;
    if ( i_nSize < this->m_num )
    {
      DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
      do
      {
        v8 = v3->m_data;
        v8[v6].Type = *(_DWORD *)v7;
        v8[v6++].ID.id = *(_DWORD *)(v7 + 4);
      }
      while ( v6 < v3->m_num );
    }
    goto LABEL_10;
  }
  if ( i_bGrowExactly )
    v4 = i_nSize;
  else
    v4 = SmartArray<UIChildFramework *,1>::get_new_size(i_nSize);
  result = SmartArray<FontReference,1>::grow(v3, v4);
  if ( result )
  {
LABEL_10:
    v3->m_num = i_nSize;
    result = 1;
  }
  return result;
}

//----- (006716D0) --------------------------------------------------------  // acclient.c:648045
void __cdecl SerializeIDs(SmartArray<QualifiedDataID,1> *IDs, DATFILE_TYPE dfType, Archive *io_archive)
{
  SmartArray<QualifiedDataID,1> *v3; // ebx@1
  unsigned int v4; // esi@1
  unsigned int v5; // eax@1
  signed int v6; // ebp@7
  int v7; // esi@8
  unsigned int v8; // eax@8
  int v9; // eax@14
  unsigned int IDsa; // [sp+14h] [bp+4h]@1

  v3 = IDs;
  v4 = IDs->m_num;
  IDsa = IDs->m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v5 = v4;
    }
    else
    {
      IDsa = *(_DWORD *)v5;
      v4 = *(_DWORD *)v5;
    }
  }
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    SmartArray<QualifiedDataID,1>::SetNElements(v3, v4, 1);
  v6 = 0;
  if ( (signed int)v4 > 0 )
  {
    do
    {
      v7 = (int)&v3->m_data[v6].ID;
      Archive::CheckAlignment(io_archive, 4u);
      v8 = Archive::GetBytes(io_archive, 4u);
      if ( v8 )
      {
        if ( io_archive->m_flags & 1 )
          *(_DWORD *)v8 = *(_DWORD *)v7;
        else
          *(_DWORD *)v7 = *(_DWORD *)v8;
      }
      if ( !(~LOBYTE(io_archive->m_flags) & 1) )
        goto LABEL_22;
      if ( dfType != 2 )
      {
        v9 = MasterDBMap::DivineType(v3->m_data[v6].ID);
        if ( v9 )
          goto LABEL_21;
        if ( dfType == 1 )
        {
          v9 = 6;
          goto LABEL_21;
        }
        if ( dfType != 2 )
        {
          if ( dfType == 3 )
            v9 = 37;
          goto LABEL_21;
        }
      }
      v9 = 1;
LABEL_21:
      v3->m_data[v6].Type = v9;
LABEL_22:
      ++v6;
    }
    while ( v6 < (signed int)IDsa );
  }
}

//----- (006717B0) --------------------------------------------------------  // acclient.c:648120
void __thiscall MissingIteration::Serialize(MissingIteration *this, Archive *io_archive)
{
  MissingIteration *v2; // esi@1
  unsigned int v3; // eax@1
  DATFILE_TYPE v4; // ebp@5
  unsigned int v5; // eax@5

  v2 = this;
  Archive::CheckAlignment(io_archive, 8u);
  v3 = Archive::GetBytes(io_archive, 8u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v3 = LODWORD(v2->idDatFile);
      *(_DWORD *)(v3 + 4) = HIDWORD(v2->idDatFile);
    }
    else
    {
      LODWORD(v2->idDatFile) = *(_DWORD *)v3;
      HIDWORD(v2->idDatFile) = *(_DWORD *)(v3 + 4);
    }
  }
  v4 = v2->idDatFile >> 32;
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v2->idIteration;
    else
      v2->idIteration = *(_DWORD *)v5;
  }
  SerializeIDs(&v2->IDsToDownload, v4, io_archive);
  SerializeIDs(&v2->IDsToPurge, v4, io_archive);
}

//----- (00714D60) --------------------------------------------------------  // acclient.c:807685
int sub_714D60()
{
  return atexit(nullsub_69);
}

//----- (00714D70) --------------------------------------------------------  // acclient.c:807691
int _E76_85()
{
  return atexit(nullsub_70);
}

//----- (00714D80) --------------------------------------------------------  // acclient.c:807697
int _E79_80()
{
  return atexit(_E80_77);
}

//----- (00714D90) --------------------------------------------------------  // acclient.c:807703
int sub_714D90()
{
  return atexit(nullsub_68);
}

