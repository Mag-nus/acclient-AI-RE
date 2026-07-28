/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBFile2IDTable
   Object     : ENGINE\dbfiledb\DBFile2IDTable.obj
   Functions  : 2
   Addresses  : 0067B310 - 00714FC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0067B310) --------------------------------------------------------  // acclient.c:658196
void __thiscall DBFile2IDTable::Serialize(DBFile2IDTable *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  DBFile2IDTable *v3; // ebp@1
  char v4; // al@3
  unsigned int v5; // edi@4
  unsigned int v6; // eax@4
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@7
  HashTableData<unsigned long,HeritageGroup_CG> *v8; // edi@7
  HeritageGroup_CGVtbl *v9; // ebx@10
  unsigned int v10; // eax@10
  void (__thiscall *v11)(HeritageGroup_CG *, Archive *); // ebp@14
  unsigned int v12; // eax@14
  int v13; // ecx@17
  void (__thiscall *v14)(HeritageGroup_CG *, Archive *); // eax@18
  int v15; // eax@19
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **v16; // ebx@20
  HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *v17; // ebp@20
  TFileEntry *v18; // edi@23
  unsigned int v19; // eax@23
  char *v20; // edi@26
  int v21; // ecx@35
  unsigned int v22; // eax@40
  Archive *v23; // ecx@42
  int v24; // ebp@46
  unsigned int v25; // eax@47
  int v26; // eax@51
  unsigned int v27; // eax@51
  unsigned int v28; // eax@57
  char *v29; // edi@61
  unsigned int dbtype; // [sp+10h] [bp-2Ch]@0
  unsigned int nDIDs; // [sp+14h] [bp-28h]@0
  IDClass<_tagDataID,32,0> did; // [sp+18h] [bp-24h]@0
  unsigned int v33; // [sp+1Ch] [bp-20h]@56
  TDBTypeEntry *pDBEntry; // [sp+20h] [bp-1Ch]@10
  TDBTypeEntry *pDBEntrya; // [sp+20h] [bp-1Ch]@46
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *i; // [sp+24h] [bp-18h]@7
  HashTableData<unsigned long,HeritageGroup_CG> **i_4; // [sp+28h] [bp-14h]@7
  HashTableData<unsigned long,HeritageGroup_CG> *i_8; // [sp+2Ch] [bp-10h]@7
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+30h] [bp-Ch]@7

  v2 = io_archive;
  v3 = this;
  if ( ~LOBYTE(io_archive->m_flags) & 1 )
    ((void (__thiscall *)(TReadOnlyFile2IDTableVtbl **))this->vfptr[1].GetDIDByFileName)(&this->vfptr);
  DBObj::Serialize((DBObj *)&v3->vfptr, v2);
  v4 = LOBYTE(v2->m_flags);
  if ( v4 & 1 )
  {
    v5 = v3->m_CacheByDID.m_intrusiveTable.m_numElements;
    Archive::CheckAlignment(v2, 4u);
    v6 = Archive::GetBytes(v2, 4u);
    if ( v6 && v2->m_flags & 1 )
      *(_DWORD *)v6 = v5;
    v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v3->m_CacheByDID.m_intrusiveTable,
           &result);
    v8 = v7->m_currElement;
    i = v7->m_currHashTable;
    i_4 = v7->m_currBucket;
    i_8 = v7->m_currElement;
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = v8->m_data.vfptr;
        pDBEntry = (TDBTypeEntry *)v8->m_data.vfptr;
        Archive::CheckAlignment(v2, 4u);
        v10 = Archive::GetBytes(v2, 4u);
        if ( v10 )
        {
          if ( v2->m_flags & 1 )
            *(_DWORD *)v10 = v8->m_hashKey;
          else
            v8->m_hashKey = *(_DWORD *)v10;
        }
        PStringBase<char>::Serialize((PStringBase<char> *)&v9[3], v2);
        v11 = v9[33].Serialize;
        Archive::CheckAlignment(v2, 4u);
        v12 = Archive::GetBytes(v2, 4u);
        if ( v12 && v2->m_flags & 1 )
          *(_DWORD *)v12 = v11;
        v13 = (int)((char *)v9[30].Serialize + 4 * (unsigned int)v9[32].Serialize);
        if ( v9[31].Serialize == (void (__thiscall *)(HeritageGroup_CG *, Archive *))v13 )
        {
LABEL_20:
          v16 = 0;
          v17 = 0;
        }
        else
        {
          while ( 1 )
          {
            v14 = v9[31].Serialize;
            if ( *(_DWORD *)v14 )
              break;
            v15 = (int)((char *)v14 + 4);
            v9[31].Serialize = (void (__thiscall *)(HeritageGroup_CG *, Archive *))v15;
            if ( v15 == v13 )
              goto LABEL_20;
          }
          v16 = (HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> **)v9[31].Serialize;
          v17 = *v16;
        }
        if ( v17 )
        {
          do
          {
LABEL_23:
            v18 = v17->m_data;
            io_archive = (Archive *)v18->m_did.id;
            Archive::CheckAlignment(v2, 4u);
            v19 = Archive::GetBytes(v2, 4u);
            if ( v19 && v2->m_flags & 1 )
              *(_DWORD *)v19 = io_archive;
            io_archive = (Archive *)v18->m_pFileName.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&io_archive[-1].m_buffer.m_masterBuffer);
            PStringBase<char>::Serialize((PStringBase<char> *)&io_archive, v2);
            v20 = (char *)&io_archive[-1].m_buffer.m_size;
            if ( !InterlockedDecrement((volatile LONG *)&io_archive[-1].m_buffer.m_masterBuffer) )
            {
              if ( v20 )
                (**(void (__thiscall ***)(char *, signed int))v20)(v20, 1);
            }
            v17 = v17->m_hashNext;
          }
          while ( v17 );
          while ( 1 )
          {
            ++v16;
            if ( v16 == &pDBEntry->DIDs.m_intrusiveTable.m_buckets[pDBEntry->DIDs.m_intrusiveTable.m_numBuckets] )
              break;
            if ( *v16 )
            {
              v17 = *v16;
              if ( *v16 )
                goto LABEL_23;
              break;
            }
          }
          v8 = i_8;
        }
        i_8 = v8->m_hashNext;
        if ( !v8->m_hashNext )
          break;
LABEL_9:
        v8 = i_8;
      }
      while ( 1 )
      {
        v21 = (int)(i_4 + 1);
        ++i_4;
        if ( i_4 == &i->m_buckets[i->m_numBuckets] )
          break;
        if ( *(_DWORD *)v21 )
        {
          i_8 = *(HashTableData<unsigned long,HeritageGroup_CG> **)v21;
          if ( *(_DWORD *)v21 )
            goto LABEL_9;
          return;
        }
      }
    }
  }
  else if ( ~v4 & 1 )
  {
    Archive::CheckAlignment(v2, 4u);
    v22 = Archive::GetBytes(v2, 4u);
    if ( v22 )
    {
      if ( v2->m_flags & 1 )
      {
        v23 = io_archive;
        *(_DWORD *)v22 = io_archive;
      }
      else
      {
        v23 = *(Archive **)v22;
      }
    }
    else
    {
      v23 = io_archive;
    }
    if ( v23 )
    {
      v24 = (int)&v3->vfptr;
      pDBEntrya = (TDBTypeEntry *)v23;
      do
      {
        Archive::CheckAlignment(v2, 4u);
        v25 = Archive::GetBytes(v2, 4u);
        if ( v25 )
        {
          if ( v2->m_flags & 1 )
            *(_DWORD *)v25 = dbtype;
          else
            dbtype = *(_DWORD *)v25;
        }
        v26 = (*(int (__thiscall **)(int, unsigned int))(*(_DWORD *)v24 + 100))(v24, dbtype);
        PStringBase<char>::Serialize((PStringBase<char> *)(v26 + 12), v2);
        Archive::CheckAlignment(v2, 4u);
        v27 = Archive::GetBytes(v2, 4u);
        if ( v27 )
        {
          if ( v2->m_flags & 1 )
            *(_DWORD *)v27 = nDIDs;
          else
            nDIDs = *(_DWORD *)v27;
        }
        if ( nDIDs )
        {
          v33 = nDIDs;
          do
          {
            io_archive = (Archive *)PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            Archive::CheckAlignment(v2, 4u);
            v28 = Archive::GetBytes(v2, 4u);
            if ( v28 )
            {
              if ( v2->m_flags & 1 )
                *(_DWORD *)v28 = did.id;
              else
                did.id = *(_DWORD *)v28;
            }
            PStringBase<char>::Serialize((PStringBase<char> *)&io_archive, v2);
            InterlockedIncrement((volatile LONG *)&io_archive[-1].m_buffer.m_masterBuffer);
            (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 48))(v24);
            v29 = (char *)&io_archive[-1].m_buffer.m_size;
            if ( !InterlockedDecrement((volatile LONG *)&io_archive[-1].m_buffer.m_masterBuffer) && v29 )
              (**(void (__thiscall ***)(char *, signed int))v29)(v29, 1);
            --v33;
          }
          while ( v33 );
        }
        pDBEntrya = (TDBTypeEntry *)((char *)pDBEntrya - 1);
      }
      while ( pDBEntrya );
    }
  }
}

//----- (00714FC0) --------------------------------------------------------  // acclient.c:807913
int sub_714FC0()
{
  return atexit(nullsub_129);
}

