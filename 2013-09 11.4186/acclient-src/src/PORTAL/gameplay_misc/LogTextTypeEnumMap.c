/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : LogTextTypeEnumMap
   Object     : PORTAL\gameplay_misc\LogTextTypeEnumMap.obj
   Functions  : 3
   Addresses  : 006AFF40 - 006B0590 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006AFF40) --------------------------------------------------------  // acclient.c:713310
int __cdecl LogTextTypeEnumMapper::IsLegalChannel(const unsigned int ltt)
{
  int result; // eax@2

  switch ( ltt )
  {
    case 2u:
    case 3u:
    case 6u:
    case 7u:
    case 0xCu:
    case 0x10u:
    case 0x11u:
    case 0x12u:
    case 0x13u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
    case 0x19u:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (006AFF90) --------------------------------------------------------  // acclient.c:713340
signed int __cdecl LogTextTypeEnumMapper::LogTextTypeToString(const unsigned int ltt, char *buf, const unsigned int size)
{
  signed int result; // eax@2

  switch ( ltt )
  {
    case 0u:
      result = 8;
      if ( size >= 8 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Default";
        *((_DWORD *)buf + 1) = *(_DWORD *)"ult";
        result = 0;
      }
      break;
    case 2u:
      result = 7;
      if ( size >= 7 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Speech";
        *((_WORD *)buf + 2) = 26723;
        buf[6] = 0;
        result = 0;
      }
      break;
    case 3u:
      result = 5;
      if ( size >= 5 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Tell";
        buf[4] = 0;
        result = 0;
      }
      break;
    case 4u:
      result = 19;
      if ( size >= 0x13 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Speech_Direct_Send";
        *((_DWORD *)buf + 1) = 1147103331;
        *((_DWORD *)buf + 2) = 1667592809;
        *((_DWORD *)buf + 3) = 1699962740;
        *((_WORD *)buf + 8) = 25710;
        buf[18] = 0;
        result = 0;
      }
      break;
    case 0x14u:
      result = 16;
      if ( size >= 0x10 )
      {
        *(_DWORD *)buf = *(_DWORD *)"World_Broadcast";
        *((_DWORD *)buf + 1) = 1916952420;
        *((_DWORD *)buf + 2) = 1667522927;
        *((_DWORD *)buf + 3) = 7631713;
        result = 0;
      }
      break;
    case 5u:
      result = 7;
      if ( size >= 7 )
      {
        *(_DWORD *)buf = *(_DWORD *)"System";
        *((_WORD *)buf + 2) = 28005;
        buf[6] = 0;
        result = 0;
      }
      break;
    case 6u:
      result = 7;
      if ( size >= 7 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Combat";
        *((_WORD *)buf + 2) = 29793;
        buf[6] = 0;
        result = 0;
      }
      break;
    case 0x15u:
      result = 13;
      if ( size >= 0xD )
      {
        *(_DWORD *)buf = *(_DWORD *)"Combat_Enemy";
        *((_DWORD *)buf + 1) = 1163883617;
        *((_DWORD *)buf + 2) = 2037212526;
        buf[12] = 0;
        result = 0;
      }
      break;
    case 0x16u:
      result = 12;
      if ( size >= 0xC )
      {
        *(_DWORD *)buf = *(_DWORD *)"Combat_Self";
        *((_DWORD *)buf + 1) = 1398764641;
        *((_DWORD *)buf + 2) = 6712421;
        result = 0;
      }
      break;
    case 7u:
      result = 6;
      if ( size >= 6 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Magic";
        *((_WORD *)buf + 2) = 99;
        result = 0;
      }
      break;
    case 8u:
      result = 8;
      if ( size >= 8 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Channel";
        *((_DWORD *)buf + 1) = 7103854;
        result = 0;
      }
      break;
    case 9u:
      result = 13;
      if ( size >= 0xD )
      {
        *(_DWORD *)buf = *(_DWORD *)"Channel_Send";
        *((_DWORD *)buf + 1) = 1600939374;
        *((_DWORD *)buf + 2) = 1684956499;
        buf[12] = 0;
        result = 0;
      }
      break;
    case 0xAu:
      result = 7;
      if ( size >= 7 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Social";
        *((_WORD *)buf + 2) = 27745;
        buf[6] = 0;
        result = 0;
      }
      break;
    case 0xBu:
      result = 12;
      if ( size >= 0xC )
      {
        *(_DWORD *)buf = *(_DWORD *)"Social_Send";
        *((_DWORD *)buf + 1) = 1398762593;
        *((_DWORD *)buf + 2) = (char *)&loc_646E5F + 6;
        result = 0;
      }
      break;
    case 0xCu:
      result = 6;
      if ( size >= 6 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Emote";
        *((_WORD *)buf + 2) = 101;
        result = 0;
      }
      break;
    case 0xDu:
      result = 12;
      if ( size >= 0xC )
      {
        *(_DWORD *)buf = *(_DWORD *)"Advancement";
        *((_DWORD *)buf + 1) = 1835361134;
        *((_DWORD *)buf + 2) = 7630437;
        result = 0;
      }
      break;
    case 0xEu:
      result = 6;
      if ( size >= 6 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Abuse";
        *((_WORD *)buf + 2) = 101;
        result = 0;
      }
      break;
    case 0xFu:
      result = 5;
      if ( size >= 5 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Help";
        buf[4] = aHelp[4];
        result = 0;
      }
      break;
    case 1u:
      result = 4;
      if ( size >= 4 )
      {
        *(_DWORD *)buf = 7105601;
        result = 0;
      }
      break;
    case 0x11u:
      result = 13;
      if ( size >= 0xD )
      {
        *(_DWORD *)buf = *(_DWORD *)"Spellcasting";
        *((_DWORD *)buf + 1) = 1935762284;
        *((_DWORD *)buf + 2) = 1735289204;
        buf[12] = 0;
        result = 0;
      }
      break;
    case 0x10u:
      result = 10;
      if ( size >= 0xA )
      {
        *(_DWORD *)buf = *(_DWORD *)"Appraisal";
        *((_DWORD *)buf + 1) = 1634953569;
        *((_WORD *)buf + 4) = 108;
        result = 0;
      }
      break;
    case 0x12u:
      result = 11;
      if ( size >= 0xB )
      {
        *(_DWORD *)buf = *(_DWORD *)"Allegiance";
        *((_DWORD *)buf + 1) = 1851877735;
        *((_WORD *)buf + 4) = 25955;
        buf[10] = 0;
        result = 0;
      }
      break;
    case 0x13u:
      result = 11;
      if ( size >= 0xB )
      {
        *(_DWORD *)buf = *(_DWORD *)"Fellowship";
        *((_DWORD *)buf + 1) = 1752397679;
        *((_WORD *)buf + 4) = 28777;
        buf[10] = 0;
        result = 0;
      }
      break;
    case 0x17u:
      result = 7;
      if ( size >= 7 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Recall";
        *((_WORD *)buf + 2) = 27756;
        buf[6] = 0;
        result = 0;
      }
      break;
    case 0x18u:
      result = 6;
      if ( size >= 6 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Craft";
        *((_WORD *)buf + 2) = 116;
        result = 0;
      }
      break;
    case 0x19u:
      result = 10;
      if ( size >= 0xA )
      {
        *(_DWORD *)buf = *(_DWORD *)"Salvaging";
        *((_DWORD *)buf + 1) = 1852401505;
        *((_WORD *)buf + 4) = 103;
        result = 0;
      }
      break;
    case 0x1Fu:
      result = 11;
      if ( size >= 0xB )
      {
        *(_DWORD *)buf = *(_DWORD *)"Admin_Tell";
        *((_DWORD *)buf + 1) = 1700028270;
        *((_WORD *)buf + 4) = 27756;
        buf[10] = 0;
        result = 0;
      }
      break;
    default:
      result = 8;
      if ( size >= 8 )
      {
        *(_DWORD *)buf = *(_DWORD *)"Unknown";
        *((_DWORD *)buf + 1) = *(_DWORD *)"own";
        result = 0;
      }
      break;
  }
  return result;
}

//----- (006B0590) --------------------------------------------------------  // acclient.c:713630
int __cdecl LogTextTypeEnumMapper::LogTextTypeFromString(const char *const buf, unsigned int *ltt)
{
  int result; // eax@2

  if ( buf )
  {
    if ( !__stricmp(buf, "Default") )
    {
      *ltt = 0;
      result = 1;
    }
    else if ( !__stricmp(buf, "Speech") )
    {
      *ltt = 2;
      result = 1;
    }
    else if ( !__stricmp(buf, "Tell") )
    {
      *ltt = 3;
      result = 1;
    }
    else if ( !__stricmp(buf, "Speech_Direct_Send") )
    {
      *ltt = 4;
      result = 1;
    }
    else if ( !__stricmp(buf, "World_Broadcast") )
    {
      *ltt = 20;
      result = 1;
    }
    else if ( !__stricmp(buf, "System") )
    {
      *ltt = 5;
      result = 1;
    }
    else if ( !__stricmp(buf, "Combat") )
    {
      *ltt = 6;
      result = 1;
    }
    else if ( !__stricmp(buf, "Combat_Enemy") )
    {
      *ltt = 21;
      result = 1;
    }
    else if ( !__stricmp(buf, "Combat_Self") )
    {
      *ltt = 22;
      result = 1;
    }
    else if ( !__stricmp(buf, "Magic") )
    {
      *ltt = 7;
      result = 1;
    }
    else if ( !__stricmp(buf, "Channel") )
    {
      *ltt = 8;
      result = 1;
    }
    else if ( !__stricmp(buf, "Channel_Send") )
    {
      *ltt = 9;
      result = 1;
    }
    else if ( !__stricmp(buf, "Social") )
    {
      *ltt = 10;
      result = 1;
    }
    else if ( !__stricmp(buf, "Social_Send") )
    {
      *ltt = 11;
      result = 1;
    }
    else if ( !__stricmp(buf, "Emote") )
    {
      *ltt = 12;
      result = 1;
    }
    else if ( !__stricmp(buf, "Advancement") )
    {
      *ltt = 13;
      result = 1;
    }
    else if ( !__stricmp(buf, "Abuse") )
    {
      *ltt = 14;
      result = 1;
    }
    else if ( !__stricmp(buf, "Help") )
    {
      *ltt = 15;
      result = 1;
    }
    else if ( !__stricmp(buf, "All") )
    {
      *ltt = 1;
      result = 1;
    }
    else if ( !__stricmp(buf, "Spellcasting") )
    {
      *ltt = 17;
      result = 1;
    }
    else if ( !__stricmp(buf, "Appraisal") )
    {
      *ltt = 16;
      result = 1;
    }
    else if ( !__stricmp(buf, "Assessment") )
    {
      *ltt = 16;
      result = 1;
    }
    else if ( !__stricmp(buf, "Allegiance") )
    {
      *ltt = 18;
      result = 1;
    }
    else if ( !__stricmp(buf, "Fellowship") )
    {
      *ltt = 19;
      result = 1;
    }
    else if ( !__stricmp(buf, "Recall") )
    {
      *ltt = 23;
      result = 1;
    }
    else if ( !__stricmp(buf, "Craft") )
    {
      *ltt = 24;
      result = 1;
    }
    else if ( !__stricmp(buf, "Salvaging") )
    {
      *ltt = 25;
      result = 1;
    }
    else if ( !__stricmp(buf, "Admin_Tell") )
    {
      *ltt = 31;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

