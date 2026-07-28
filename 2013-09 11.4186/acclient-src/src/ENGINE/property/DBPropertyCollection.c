/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DBPropertyCollection
   Object     : ENGINE\property\DBPropertyCollection.obj
   Functions  : 13
   Addresses  : 00681450 - 0077F510 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00681450) --------------------------------------------------------  // acclient.c:664532
void __thiscall DBPropertyCollection::DBPropertyCollection(DBPropertyCollection *this)
{
  DBPropertyCollection *v1; // esi@1

  v1 = this;
  PropertyCollection::PropertyCollection((PropertyCollection *)&this->vfptr);
  DBObj::DBObj((DBObj *)&v1->vfptr, stru_8F79BC);
  v1->vfptr = (InterfaceVtbl *)&DBPropertyCollection::vftable;
  v1->vfptr = (PropertyCollectionVtbl *)&DBPropertyCollection::vftable;
}
// 7FE7E0: using guessed type int (__thiscall *DBPropertyCollection::vftable)(void *, char);
// 7FE7E8: using guessed type __int32 (__stdcall *DBPropertyCollection::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00681480) --------------------------------------------------------  // acclient.c:664546
signed int DBPropertyCollection::GetDBOType()
{
  return 49;
}

//----- (00681490) --------------------------------------------------------  // acclient.c:664552
void __thiscall DBPropertyCollection::Serialize(DBPropertyCollection *this, Archive *_io_archive)
{
  DBPropertyCollection *v2; // esi@1

  v2 = this;
  DBObj::Serialize((DBObj *)this, _io_archive);
  PropertyCollection::Serialize(
    (PropertyCollection *)&v2[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[9],
    _io_archive);
}

//----- (006814B0) --------------------------------------------------------  // acclient.c:664564
void __thiscall DBPropertyCollection::GetSubDataIDs(DBPropertyCollection *this, QualifiedDataIDArray *_id_array)
{
  PropertyCollection::GetSubDataIDs(
    (PropertyCollection *)&this[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[9],
    _id_array);
}

//----- (006814D0) --------------------------------------------------------  // acclient.c:664572
PropertyCollection *__thiscall DBPropertyCollection::vector_deleting_destructor(DBPropertyCollection *this, unsigned int a2)
{
  return DBPropertyCollection::scalar_deleting_destructor((DBPropertyCollection *)((char *)this - 120), a2);
}

//----- (006814E0) --------------------------------------------------------  // acclient.c:664578
void __thiscall DBPropertyCollection::Destroy(DBPropertyCollection *this)
{
  DBPropertyCollection::Destroy((DBPropertyCollection *)((char *)this - 120));
}

//----- (00681500) --------------------------------------------------------  // acclient.c:664584
PropertyCollection *__thiscall DBPropertyCollection::scalar_deleting_destructor(DBPropertyCollection *this, unsigned int a2)
{
  PropertyCollection *v2; // esi@1
  DBObj *v3; // ecx@1

  v2 = (PropertyCollection *)this;
  v3 = (DBObj *)&this->vfptr;
  v2->vfptr = (PropertyCollectionVtbl *)&DBPropertyCollection::vftable;
  v3->vfptr = (InterfaceVtbl *)&DBPropertyCollection::vftable;
  DBObj::~DBObj(v3);
  PropertyCollection::~PropertyCollection(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FE7E0: using guessed type int (__thiscall *DBPropertyCollection::vftable)(void *, char);
// 7FE7E8: using guessed type __int32 (__stdcall *DBPropertyCollection::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00681540) --------------------------------------------------------  // acclient.c:664603
char __thiscall DBPropertyCollection::CopyInto(DBPropertyCollection *this, DBObj *_retval)
{
  char result; // al@2

  if ( _retval )
  {
    HashTable<unsigned long,BaseProperty,1>::operator=(
      (int)&_retval[-3].m_pLast,
      (int)&this[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[10]);
    result = 1;
  }
  else
  {
    HashTable<unsigned long,BaseProperty,1>::operator=(
      4,
      (int)&this[-1].m_hashProperties.m_intrusiveTable.m_aInplaceBuckets[10]);
    result = 1;
  }
  return result;
}

//----- (00715490) --------------------------------------------------------  // acclient.c:808263
int sub_715490()
{
  PStringBase<char>::PStringBase<char>(&PHeader_12, "PREPROC_HEADER");
  return atexit(sub_77F4E0);
}

//----- (007154B0) --------------------------------------------------------  // acclient.c:808270
int _E76_95()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES, "Properties");
  return atexit(sub_77F510);
}

//----- (007154D0) --------------------------------------------------------  // acclient.c:808277
int sub_7154D0()
{
  return atexit(nullsub_178);
}

//----- (0077F4E0) --------------------------------------------------------  // acclient.c:918051
void __cdecl sub_77F4E0()
{
  char *v0; // esi@1

  v0 = &PHeader_12.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_12.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0077F510) --------------------------------------------------------  // acclient.c:918064
void __cdecl sub_77F510()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

