/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : VersionedArchive
   Object     : CORE\serialize\VersionedArchive.obj
   Functions  : 3
   Addresses  : 0065D7D0 - 00714C30 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065D7D0) --------------------------------------------------------  // acclient.c:627258
BOOL __thiscall AutoStoreVersionArchive::tagSerializeVersionRow::InitializeArchive(AutoStoreVersionArchive::tagSerializeVersionRow *this, Archive *io_rcArchive)
{
  AutoStoreVersionArchive::tagSerializeVersionRow *v2; // esi@1
  Archive *v3; // edi@1
  IDClass<_tagVersionHandle,32,0> *v4; // eax@1
  IDClass<_tagVersionHandle,32,0> v5; // edx@1
  IDClass<_tagVersionHandle,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v2 = this;
  v3 = io_rcArchive;
  v4 = Archive::PushVersionRow(io_rcArchive, &result, &this->m_rowInitialData);
  v5.id = v4->id;
  v2->m_hVersionRow.id = v4->id;
  v2->m_hSerialize = 0;
  if ( v5.id != INVALID_VERSIONHANDLE_29.id
    && Archive::GetVersionRowByHandle(v3, v5, (ArchiveVersionRow **)&io_rcArchive) )
    v2->m_hSerialize = ArchiveVersionRow::SerializeHeader((ArchiveVersionRow *)io_rcArchive, v3);
  return ~(unsigned __int8)(v3->m_flags >> 2) & 1 && v2->m_hSerialize != -1;
}

//----- (0065D850) --------------------------------------------------------  // acclient.c:627280
void __thiscall AutoStoreVersionArchive::OnSerializingDone(AutoStoreVersionArchive *this)
{
  AutoStoreVersionArchive *v1; // esi@1
  char v2; // al@1
  ArchiveVersionRow *pRow; // [sp+0h] [bp-4h]@1

  pRow = (ArchiveVersionRow *)this;
  v1 = this;
  v2 = ~(unsigned __int8)(this->m_flags >> 2);
  this->m_bOnSerializingDoneCalled = 1;
  if ( v2 & 1 )
  {
    if ( Archive::GetVersionRowByHandle((Archive *)&this->vfptr, this->m_SerializeVersionRow.m_hVersionRow, &pRow) )
      ArchiveVersionRow::SerializeFooter(pRow, v1->m_SerializeVersionRow.m_hSerialize, (Archive *)&v1->vfptr);
  }
}

//----- (00714C30) --------------------------------------------------------  // acclient.c:807608
int _E21_29()
{
  return atexit(_E22_29);
}

