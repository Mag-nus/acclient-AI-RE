/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : FontMapper
   Object     : ENGINE\render_base\FontMapper.obj
   Functions  : 8
   Addresses  : 0044B520 - 00740C20 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044B520) --------------------------------------------------------  // acclient.c:136120
int __cdecl Font::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0x2Eu);
  return DBObj::Get(v1);
}

//----- (0044B540) --------------------------------------------------------  // acclient.c:136130
int __cdecl FontLocal::GetGlobalOrLocalFont(IDClass<_tagDataID,32,0> did)
{
  int v1; // eax@1
  QualifiedDataID *v3; // eax@4
  QualifiedDataID v4; // [sp+4h] [bp-8h]@4

  v1 = MasterDBMap::DivineType(did) - 46;
  if ( v1 )
  {
    if ( v1 != 1 )
      return 0;
    QualifiedDataID::QualifiedDataID(&v4, did, 0x2Fu);
  }
  else
  {
    QualifiedDataID::QualifiedDataID(&v4, did, 0x2Eu);
  }
  return DBObj::Get(v3);
}

//----- (0044B650) --------------------------------------------------------  // acclient.c:136205
char __cdecl FontMapper::Startup()
{
  SmartArray<QualifiedDataID,1>::Reset(&FontMapper::fonts);
  return 1;
}

//----- (0044B660) --------------------------------------------------------  // acclient.c:136212
void __cdecl FontMapper::Shutdown()
{
  unsigned int v0; // esi@1
  unsigned int v1; // ecx@2

  v0 = 0;
  if ( FontMapper::fonts.m_num )
  {
    do
    {
      v1 = FontMapper::fonts.m_data[v0].ID.id;
      if ( v1 )
      {
        (*(void (**)(void))(*(_DWORD *)v1 + 20))();
        FontMapper::fonts.m_data[v0].ID.id = 0;
      }
      ++v0;
    }
    while ( v0 < FontMapper::fonts.m_num );
  }
  SmartArray<QualifiedDataID,1>::Reset(&FontMapper::fonts);
}

//----- (0044B6B0) --------------------------------------------------------  // acclient.c:136236
unsigned int __cdecl FontMapper::GetFontByDataID(IDClass<_tagDataID,32,0> dataID)
{
  unsigned int v2; // eax@3
  int v3; // eax@6
  QualifiedDataID *v4; // eax@8
  int v5; // edi@11
  unsigned int v6; // eax@14
  QualifiedDataID v7; // [sp+4h] [bp-8h]@8

  if ( dataID.id == INVALID_DID_40.id )
    return 0;
  v2 = 0;
  if ( !FontMapper::fonts.m_num )
  {
LABEL_6:
    v3 = MasterDBMap::DivineType(dataID) - 46;
    if ( v3 )
    {
      if ( v3 != 1 )
        return 0;
      QualifiedDataID::QualifiedDataID(&v7, dataID, 0x2Fu);
    }
    else
    {
      QualifiedDataID::QualifiedDataID(&v7, dataID, 0x2Eu);
    }
    v5 = DBObj::Get(v4);
    if ( v5 )
    {
      if ( FontMapper::fonts.m_num < (FontMapper::fonts.m_sizeAndDeallocate & 0x7FFFFFFF)
        || (v6 = SmartArray<UIChildFramework *,1>::get_new_size((FontMapper::fonts.m_sizeAndDeallocate & 0x7FFFFFFF) + 1),
            SmartArray<FontReference,1>::grow(&FontMapper::fonts, v6)) )
      {
        FontMapper::fonts.m_data[FontMapper::fonts.m_num].Type = dataID.id;
        FontMapper::fonts.m_data[FontMapper::fonts.m_num++].ID.id = v5;
      }
      return v5;
    }
    return 0;
  }
  while ( FontMapper::fonts.m_data[v2].Type != dataID.id )
  {
    ++v2;
    if ( v2 >= FontMapper::fonts.m_num )
      goto LABEL_6;
  }
  return FontMapper::fonts.m_data[v2].ID.id;
}

//----- (006D6F60) --------------------------------------------------------  // acclient.c:749119
int _E73_44()
{
  return atexit(_E74_35);
}

//----- (006D6F70) --------------------------------------------------------  // acclient.c:749125
int _E1_40()
{
  return atexit(_E2_40);
}

//----- (00740C20) --------------------------------------------------------  // acclient.c:853610
void __cdecl _E74_35()
{
  if ( (FontMapper::fonts.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( (_DWORD)FontMapper::fonts.m_data )
      operator delete[](&FontMapper::fonts.m_data[-1].ID);
  }
}

