/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DiskDev
   Object     : ENGINE\diskcon\DiskDev.obj
   Functions  : 10
   Addresses  : 00676B90 - 00714F10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00676B90) --------------------------------------------------------  // acclient.c:653362
int __thiscall DiskFileInfo_t::operator=(int this, int a2)
{
  int v2; // esi@1

  v2 = this;
  *(_DWORD *)this = *(_DWORD *)a2;
  *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
  *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
  *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
  *(_BYTE *)(this + 44) = *(_BYTE *)(a2 + 44);
  *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
  *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
  *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
  DatIDStamp::DatIDStamp((DatIDStamp *)(this + 60), (DatIDStamp *)(a2 + 60));
  return v2;
}

//----- (00676C10) --------------------------------------------------------  // acclient.c:653387
int __thiscall DiskDev::Close(DiskDev *this)
{
  DiskDev *v1; // esi@1
  int result; // eax@3

  v1 = this;
  if ( this->_fd != (void *)-1 && CloseHandle(this->_fd) )
  {
    v1->_fd = (void *)-1;
    result = 0;
  }
  else
  {
    result = -104;
  }
  return result;
}

//----- (00676C40) --------------------------------------------------------  // acclient.c:653406
void __thiscall DiskDev::~DiskDev(DiskDev *this)
{
  DiskDev *v1; // esi@1

  v1 = this;
  if ( this->_fd != (void *)-1 )
  {
    if ( CloseHandle(this->_fd) )
      v1->_fd = (void *)-1;
  }
}

//----- (00676C60) --------------------------------------------------------  // acclient.c:653419
int __thiscall DiskDev::SyncRead(DiskDev *this, void *buf, unsigned int size, int off)
{
  DiskDev *v4; // edi@1
  int result; // eax@2
  void *v6; // ST00_4@3

  v4 = this;
  if ( SetFilePointer(this->_fd, off, 0, 0) == -1 )
  {
    result = -105;
  }
  else
  {
    v6 = v4->_fd;
    off = 0;
    ReadFile(v6, buf, size, (LPDWORD)&off, 0);
    result = off == size ? 0 : 0xFFFFFF9A;
  }
  return result;
}

//----- (00676CC0) --------------------------------------------------------  // acclient.c:653441
int __thiscall DiskDev::SyncWrite(DiskDev *this, void *buf, unsigned int size, int off)
{
  DiskDev *v4; // esi@1
  int result; // eax@2

  v4 = this;
  if ( SetFilePointer(this->_fd, off, 0, 0) == -1 )
  {
    result = -105;
  }
  else
  {
    if ( !WriteFile(v4->_fd, buf, size, (LPDWORD)&off, 0) )
      GetLastError();
    result = off == size ? 0 : 0xFFFFFF99;
  }
  return result;
}

//----- (00676D20) --------------------------------------------------------  // acclient.c:653461
int __thiscall DiskDev::Open_File(DiskDev *this, PStringBase<unsigned short> *file_cp, PStringBase<unsigned short> *path_cp, DiskFileInfo_t *header_p, unsigned int open_flags_l)
{
  DiskDev *v5; // ebp@1
  PSRefBufferCharData<unsigned short> *v6; // eax@1
  unsigned int v7; // esi@1
  DWORD v8; // edx@1
  DWORD v9; // eax@3
  DWORD v10; // ecx@5
  HANDLE v11; // eax@7
  int v12; // edi@8
  int v13; // esi@12
  char v15; // [sp+1h] [bp-1B1h]@7
  int v16; // [sp+2h] [bp-1B0h]@7
  int v17; // [sp+6h] [bp-1ACh]@11
  bool create_f; // [sp+1Dh] [bp-195h]@1
  PStringBase<unsigned short> full_path; // [sp+1Eh] [bp-194h]@1
  DiskHeaderBlock_t EmptyHeader; // [sp+22h] [bp-190h]@1

  v5 = this;
  DiskFileInfo_t::DiskFileInfo_t(&EmptyHeader.FileInfo_);
  memset(&EmptyHeader, 0, 0x100u);
  v6 = path_cp->m_charbuffer;
  qmemcpy(&EmptyHeader, "\nFile Header Structure Default Constructor v1.3\n", 0x31u);
  v7 = open_flags_l & 8;
  create_f = v7 == 8;
  full_path.m_charbuffer = v6;
  EmptyHeader.acVersionStr_[255] = 26;
  InterlockedIncrement((volatile LONG *)&v6[-1].m_data[8]);
  PSUtils::path_append(&full_path, file_cp);
  v8 = 3;
  if ( v7 == 8 )
    v8 = 2;
  v9 = -1073741824;
  if ( open_flags_l & 4 )
    v9 = 2147483648;
  v10 = 0;
  if ( (v9 & 0x80000000) != 0 )
    v10 = 1;
  v11 = CreateFileW(full_path.m_charbuffer->m_data, v9, v10, 0, v8, 0, 0);
  v5->_fd = v11;
  if ( v11 == (HANDLE)-1 )
  {
    v12 = -2;
  }
  else
  {
    v12 = 0;
    if ( v15 )
    {
      if ( *(_DWORD *)&EmptyHeader.FileInfo_.id_vnum._maj_vnum.Data2 )
      {
        DiskFileInfo_t::operator=(
          (int)&EmptyHeader.acTransactionRecord[36],
          *(int *)&EmptyHeader.FileInfo_.id_vnum._maj_vnum.Data2);
        v12 = DiskDev::SyncWrite(v5, &v17, 0x190u, 0);
      }
    }
    else
    {
      v13 = *(_DWORD *)&EmptyHeader.FileInfo_.id_vnum._maj_vnum.Data2;
      if ( *(_DWORD *)&EmptyHeader.FileInfo_.id_vnum._maj_vnum.Data2 )
      {
        v12 = DiskDev::SyncRead(v5, &v17, 0x190u, 0);
        DiskFileInfo_t::operator=(v13, (int)&EmptyHeader.acTransactionRecord[36]);
        SetFilePointer(v5->_fd, 0, 0, 2u);
      }
    }
  }
  if ( !InterlockedDecrement((volatile LONG *)(v16 - 20 + 4)) && v16 != 20 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))(v16 - 20))(v16 - 20, 1);
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&EmptyHeader.FileInfo_.btreeRoot_);
  return v12;
}

//----- (00714EE0) --------------------------------------------------------  // acclient.c:807829
int sub_714EE0()
{
  return atexit(nullsub_76);
}

//----- (00714EF0) --------------------------------------------------------  // acclient.c:807835
int _E76_91()
{
  return atexit(nullsub_77);
}

//----- (00714F00) --------------------------------------------------------  // acclient.c:807841
int _E79_86()
{
  return atexit(_E80_83);
}

//----- (00714F10) --------------------------------------------------------  // acclient.c:807847
int sub_714F10()
{
  return atexit(nullsub_79);
}

