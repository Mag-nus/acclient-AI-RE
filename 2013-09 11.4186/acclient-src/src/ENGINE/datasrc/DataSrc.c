/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DataSrc
   Object     : ENGINE\datasrc\DataSrc.obj
   Functions  : 5
   Addresses  : 0066FEC0 - 0066FF20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0066FEC0) --------------------------------------------------------  // acclient.c:646546
void __thiscall DataSource::DataSource(DataSource *this)
{
  this->vfptr = (DataSourceVtbl *)&DataSource::vftable;
  this->pData = 0;
  this->pStartData = 0;
}
// 7FDB3C: using guessed type int (__thiscall *DataSource::vftable)(void *, char);

//----- (0066FEE0) --------------------------------------------------------  // acclient.c:646555
void __thiscall DataSource::Open(DataSource *this, char *_pData, int _dataSize)
{
  this->pStartData = _pData;
  this->pData = _pData;
  this->dataSize = _dataSize;
}

//----- (0066FF00) --------------------------------------------------------  // acclient.c:646563
void __thiscall DataSource::Close(DataSource *this)
{
  this->pData = 0;
  this->pStartData = 0;
}

//----- (0066FF10) --------------------------------------------------------  // acclient.c:646570
void __thiscall DataSource::~DataSource(DataSource *this)
{
  this->vfptr = (DataSourceVtbl *)&DataSource::vftable;
  this->pData = 0;
  this->pStartData = 0;
}
// 7FDB3C: using guessed type int (__thiscall *DataSource::vftable)(void *, char);

//----- (0066FF20) --------------------------------------------------------  // acclient.c:646579
DataSource *__thiscall DataSource::scalar_deleting_destructor(DataSource *this, unsigned int a2)
{
  DataSource *v2; // esi@1

  v2 = this;
  this->pData = 0;
  this->pStartData = 0;
  this->vfptr = (DataSourceVtbl *)&DataSource::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7FDB3C: using guessed type int (__thiscall *DataSource::vftable)(void *, char);

