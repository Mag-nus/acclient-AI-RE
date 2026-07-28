/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBWave
   Object     : PORTAL\sound\DBWave.obj
   Functions  : 8
   Addresses  : 005268B0 - 00706A00 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005268B0) --------------------------------------------------------  // acclient.c:342077
signed int StopParticleHook::GetType()
{
  return 15;
}

//----- (00551AA0) --------------------------------------------------------  // acclient.c:384658
void __thiscall DBWave::DBWave(DBWave *this, IDClass<_tagDataID,32,0> id)
{
  DBWave *v2; // esi@1

  v2 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, id);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2->vfptr = (InterfaceVtbl *)&SerializeUsingPackDBObj::vftable;
  v2->vfptr = (PackObjVtbl *)&SerializeUsingPackDBObj::vftable;
  WaveFile::WaveFile((WaveFile *)&v2->vfptr);
  v2->vfptr = (WaveFileVtbl *)&DBWave::vftable;
  v2->vfptr = (InterfaceVtbl *)&DBWave::vftable;
  v2->vfptr = (PackObjVtbl *)&DBWave::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C58CC: using guessed type void *SerializeUsingPackDBObj::vftable;
// 7C58E0: using guessed type __int32 (__stdcall *SerializeUsingPackDBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CB104: using guessed type void *DBWave::vftable;
// 7CB118: using guessed type __int32 (__stdcall *DBWave::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CB170: using guessed type void *DBWave::vftable;

//----- (00551AF0) --------------------------------------------------------  // acclient.c:384680
DBWave *__thiscall DBWave::vector_deleting_destructor(DBWave *this, unsigned int a2)
{
  return DBWave::scalar_deleting_destructor((DBWave *)((char *)this - 48), a2);
}

//----- (00551B00) --------------------------------------------------------  // acclient.c:384686
DBWave *__thiscall DBWave::vector_deleting_destructor(DBWave *this, unsigned int a2)
{
  return DBWave::scalar_deleting_destructor((DBWave *)((char *)this - 56), a2);
}

//----- (00551B10) --------------------------------------------------------  // acclient.c:384692
unsigned int __thiscall DBWave::Pack(DBWave *this, void **addr, unsigned int size)
{
  DBWave *v3; // ebx@1
  unsigned int result; // eax@1
  char *v5; // esi@2
  char *v6; // ecx@2
  char *v7; // esi@2

  v3 = this;
  result = this->m_mmckiFmt.fccType + this->m_mmckiFmt.cksize + 8;
  if ( size >= result )
  {
    *(_DWORD *)*addr = this->m_mmckiFmt.fccType;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->m_mmckiFmt.cksize;
    v6 = (char *)*addr + 4;
    *addr = v6;
    qmemcpy(v6, *((const void **)&v3->m_bLoaded + 1), v3->m_mmckiFmt.fccType);
    v7 = (char *)*addr + v3->m_mmckiFmt.fccType;
    *addr = v7;
    qmemcpy(v7, LODWORD(v3->m_timeStamp), v3->m_mmckiFmt.cksize);
    *addr = (char *)*addr + v3->m_mmckiFmt.cksize;
  }
  return result;
}

//----- (00551B90) --------------------------------------------------------  // acclient.c:384720
int __thiscall DBWave::UnPack(DBWave *this, void **addr, unsigned int size)
{
  DBWave *v3; // ebx@1
  char *v4; // eax@1
  void *v5; // eax@1
  void *v6; // eax@2
  char *v8; // edx@5

  v3 = this;
  WaveFile::ReleaseAll((WaveFile *)&this->m_bLoaded);
  v3->m_mmckiFmt.fccType = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  v3->m_mmckiFmt.cksize = *(_DWORD *)v4;
  *addr = (char *)*addr + 4;
  v5 = operator new[](v3->m_mmckiFmt.cksize);
  LODWORD(v3->m_timeStamp) = v5;
  if ( !v5 )
    return 0;
  v6 = operator new[](v3->m_mmckiFmt.fccType);
  *((_DWORD *)&v3->m_bLoaded + 1) = v6;
  if ( !v6 )
  {
    operator delete[](LODWORD(v3->m_timeStamp));
    LODWORD(v3->m_timeStamp) = 0;
    return 0;
  }
  qmemcpy(v6, *addr, v3->m_mmckiFmt.fccType);
  v8 = (char *)*addr + v3->m_mmckiFmt.fccType;
  *addr = v8;
  qmemcpy(LODWORD(v3->m_timeStamp), v8, v3->m_mmckiFmt.cksize);
  *addr = (char *)*addr + v3->m_mmckiFmt.cksize;
  return 1;
}

//----- (00551C60) --------------------------------------------------------  // acclient.c:384756
DBWave *__thiscall DBWave::scalar_deleting_destructor(DBWave *this, unsigned int a2)
{
  DBWave *v2; // esi@1
  WaveFile *v3; // ecx@1

  v2 = this;
  v3 = (WaveFile *)&this->vfptr;
  v2->vfptr = (InterfaceVtbl *)&DBWave::vftable;
  v2->vfptr = (PackObjVtbl *)&DBWave::vftable;
  v3->vfptr = (WaveFileVtbl *)&DBWave::vftable;
  WaveFile::~WaveFile(v3);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  DBObj::~DBObj((DBObj *)&v2->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7CB104: using guessed type void *DBWave::vftable;
// 7CB118: using guessed type __int32 (__stdcall *DBWave::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 7CB170: using guessed type void *DBWave::vftable;

//----- (00706A00) --------------------------------------------------------  // acclient.c:793893
int sub_706A00()
{
  return atexit(nullsub_1253);
}

