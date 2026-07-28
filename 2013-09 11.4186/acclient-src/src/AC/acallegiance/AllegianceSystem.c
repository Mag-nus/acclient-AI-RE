/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceSystem
   Object     : AC\acallegiance\AllegianceSystem.obj
   Functions  : 18
   Addresses  : 005B7BC0 - 005B8DD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B7BC0) --------------------------------------------------------  // acclient.c:482726
int __cdecl AllegianceSystem::GetAluvianMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Yeoman");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Baronet");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Baron");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Reeve");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Thane");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Ealdor");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duke");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Aetheling");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "King");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "High King");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B7CD0) --------------------------------------------------------  // acclient.c:482780
int __cdecl AllegianceSystem::GetAluvianFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Yeoman");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Baronet");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Baroness");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Reeve");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Thane");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Ealdor");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duchess");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Aetheling");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Queen");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "High Queen");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B7DE0) --------------------------------------------------------  // acclient.c:482834
int __cdecl AllegianceSystem::GetGharundimMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Sayyid");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Shayk");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Maulan");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Mu'allim");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Naquib");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Qadi");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Mushir");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Amir");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Malik");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Sultan");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B7EF0) --------------------------------------------------------  // acclient.c:482888
int __cdecl AllegianceSystem::GetGharundimFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Sayyida");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Shayka");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Maulana");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Mu'allima");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Naquiba");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Qadiya");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Mushira");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Amira");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Malika");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Sultana");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8000) --------------------------------------------------------  // acclient.c:482942
int __cdecl AllegianceSystem::GetShoMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Jinin");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Jo-chueh");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Nan-chueh");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Shi-chueh");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Ta-chueh");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Kun-chueh");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Kou");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Taikou");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Ou");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Koutei");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8110) --------------------------------------------------------  // acclient.c:482996
int __cdecl AllegianceSystem::GetShoFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Jinin");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Jo-chueh");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Nan-chueh");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Shi-chueh");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Ta-chueh");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Kun-chueh");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Kou");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Taikou");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Jo-ou");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Koutei");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8220) --------------------------------------------------------  // acclient.c:483050
int __cdecl AllegianceSystem::GetViamontianMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Squire");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Banner");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Baron");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Viscount");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Count");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Marquis");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duke");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Grand Duke");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "King");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "High King");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8330) --------------------------------------------------------  // acclient.c:483104
int __cdecl AllegianceSystem::GetViamontianFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Dame");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Banner");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Baroness");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Viscountess");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Countess");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Marquise");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duchess");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Grand Duchess");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Queen");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "High Queen");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8440) --------------------------------------------------------  // acclient.c:483158
int __cdecl AllegianceSystem::GetShadowboundMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Tenebrous");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Shade");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Squire");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Knight");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Void Knight");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Void Lord");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duke");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Archduke");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Highborn");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "King");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8550) --------------------------------------------------------  // acclient.c:483212
int __cdecl AllegianceSystem::GetShadowboundFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Tenebrous");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Shade");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Squire");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Knight");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Void Knight");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Void Lady");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Duchess");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Archduchess");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Highborn");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Queen");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8660) --------------------------------------------------------  // acclient.c:483266
int __cdecl AllegianceSystem::GetGearknightMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Tribunus");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Praefectus");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Optio");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Centurion");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Principes");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Legatus");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Consul");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Dux");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Secondus");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Primus");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8770) --------------------------------------------------------  // acclient.c:483320
int __cdecl AllegianceSystem::GetTumerokMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Xutua");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Tuona");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Ona");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Nuona");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Turea");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Rea");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Nurea");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Kauh");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Sutah");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Tah");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8880) --------------------------------------------------------  // acclient.c:483374
int __cdecl AllegianceSystem::GetLugianMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Laigus");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Raigus");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Amploth");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Arintoth");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Obeloth");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Lithos");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Kantos");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Gigas");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Extas");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Tiatus");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8990) --------------------------------------------------------  // acclient.c:483428
int __cdecl AllegianceSystem::GetEmpyreanMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Ensign");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Corporal");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Lieutenant");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Commander");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Captain");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Commodore");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Admiral");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Warlord");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Ipharsin");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Aulin");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8AA0) --------------------------------------------------------  // acclient.c:483482
int __cdecl AllegianceSystem::GetEmpyreanFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Ensign");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Corporal");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Lieutenant");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Commander");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Captain");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Commodore");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Admiral");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Warlord");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Ipharsia");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Aulia");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8BB0) --------------------------------------------------------  // acclient.c:483536
int __cdecl AllegianceSystem::GetUndeadMaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Neophyte");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Acolyte");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Adept");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Esquire");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Squire");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Knight");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Count");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Viscount");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Highness");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Annointed");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8CC0) --------------------------------------------------------  // acclient.c:483590
int __cdecl AllegianceSystem::GetUndeadFemaleTitle(unsigned int rank, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@2

  switch ( rank )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(title, "Neophyte");
      result = 1;
      break;
    case 2u:
      AC1Legacy::PStringBase<char>::set(title, "Acolyte");
      result = 1;
      break;
    case 3u:
      AC1Legacy::PStringBase<char>::set(title, "Adept");
      result = 1;
      break;
    case 4u:
      AC1Legacy::PStringBase<char>::set(title, "Esquire");
      result = 1;
      break;
    case 5u:
      AC1Legacy::PStringBase<char>::set(title, "Squire");
      result = 1;
      break;
    case 6u:
      AC1Legacy::PStringBase<char>::set(title, "Knight");
      result = 1;
      break;
    case 7u:
      AC1Legacy::PStringBase<char>::set(title, "Countess");
      result = 1;
      break;
    case 8u:
      AC1Legacy::PStringBase<char>::set(title, "Viscountess");
      result = 1;
      break;
    case 9u:
      AC1Legacy::PStringBase<char>::set(title, "Highness");
      result = 1;
      break;
    case 0xAu:
      AC1Legacy::PStringBase<char>::set(title, "Annointed");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005B8DD0) --------------------------------------------------------  // acclient.c:483644
int __cdecl AllegianceSystem::GetTitle(unsigned int rank, unsigned int hg, unsigned int g, AC1Legacy::PStringBase<char> *title)
{
  int result; // eax@4

  if ( g == 1 )
  {
    switch ( hg )
    {
      case 1u:
        result = AllegianceSystem::GetAluvianMaleTitle(rank, title);
        break;
      case 2u:
        result = AllegianceSystem::GetGharundimMaleTitle(rank, title);
        break;
      case 3u:
        result = AllegianceSystem::GetShoMaleTitle(rank, title);
        break;
      case 4u:
        result = AllegianceSystem::GetViamontianMaleTitle(rank, title);
        break;
      case 5u:
      case 0xAu:
        result = AllegianceSystem::GetShadowboundMaleTitle(rank, title);
        break;
      case 6u:
        result = AllegianceSystem::GetGearknightMaleTitle(rank, title);
        break;
      case 7u:
        result = AllegianceSystem::GetTumerokMaleTitle(rank, title);
        break;
      case 8u:
        result = AllegianceSystem::GetLugianMaleTitle(rank, title);
        break;
      case 9u:
        result = AllegianceSystem::GetEmpyreanMaleTitle(rank, title);
        break;
      case 0xBu:
        result = AllegianceSystem::GetUndeadMaleTitle(rank, title);
        break;
      default:
        goto LABEL_25;
    }
  }
  else if ( g == 2 )
  {
    switch ( hg )
    {
      case 1u:
        result = AllegianceSystem::GetAluvianFemaleTitle(rank, title);
        break;
      case 2u:
        result = AllegianceSystem::GetGharundimFemaleTitle(rank, title);
        break;
      case 3u:
        result = AllegianceSystem::GetShoFemaleTitle(rank, title);
        break;
      case 4u:
        result = AllegianceSystem::GetViamontianFemaleTitle(rank, title);
        break;
      case 5u:
      case 0xAu:
        result = AllegianceSystem::GetShadowboundFemaleTitle(rank, title);
        break;
      case 7u:
        result = AllegianceSystem::GetTumerokMaleTitle(rank, title);
        break;
      case 6u:
        result = AllegianceSystem::GetGearknightMaleTitle(rank, title);
        break;
      case 8u:
        result = AllegianceSystem::GetLugianMaleTitle(rank, title);
        break;
      case 9u:
        result = AllegianceSystem::GetEmpyreanFemaleTitle(rank, title);
        break;
      case 0xBu:
        result = AllegianceSystem::GetUndeadFemaleTitle(rank, title);
        break;
      default:
        goto LABEL_25;
    }
  }
  else
  {
LABEL_25:
    result = 0;
  }
  return result;
}

