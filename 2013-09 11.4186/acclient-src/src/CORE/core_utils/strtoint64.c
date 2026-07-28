/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : strtoint64
   Object     : CORE\core_utils\strtoint64.obj
   Functions  : 3
   Addresses  : 0065CB80 - 0065CE50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065CB80) --------------------------------------------------------  // acclient.c:626762
int __cdecl strtoxint64(const char *nptr, const char **endptr, int ibase, int flags)
{
  const char v4; // bl@1
  unsigned int v5; // ebp@1
  const char *v6; // edi@1
  int v7; // ST0C_4@2
  int v8; // ecx@9
  int v9; // esi@26
  unsigned __int64 v10; // rax@34
  const char *v11; // edi@35
  _BYTE c[5]; // [sp+13h] [bp-21h]@1
  unsigned __int64 maxval; // [sp+1Ch] [bp-18h]@24
  unsigned __int64 v15; // [sp+24h] [bp-10h]@24
  __int64 v16; // [sp+2Ch] [bp-8h]@24

  v4 = *nptr;
  v5 = 0;
  c[4] = 0;
  *(_DWORD *)c = *nptr;
  v6 = nptr + 1;
  if ( _isspace(*(int *)c) )
  {
    do
    {
      v7 = *v6;
      c[0] = *v6++;
    }
    while ( _isspace(v7) );
    v4 = c[0];
  }
  if ( v4 == 45 )
  {
    flags |= 2u;
    c[0] = *v6;
LABEL_8:
    v4 = c[0];
    ++v6;
    goto LABEL_9;
  }
  if ( v4 == 43 )
  {
    c[0] = *v6;
    goto LABEL_8;
  }
LABEL_9:
  v8 = ibase;
  if ( ibase < 0 || ibase == 1 || ibase > 36 )
  {
    if ( endptr )
      *endptr = nptr;
    return 0;
  }
  if ( ibase )
  {
    if ( ibase != 16 || v4 != 48 )
      goto LABEL_24;
  }
  else
  {
    if ( v4 != 48 )
    {
      ibase = 10;
      v8 = 10;
      goto LABEL_24;
    }
    if ( *v6 != 120 && *v6 != 88 )
    {
      ibase = 8;
      v8 = 8;
      goto LABEL_24;
    }
    ibase = 16;
    v8 = 16;
  }
  if ( *v6 == 120 || *v6 == 88 )
  {
    c[0] = v6[1];
    v6 += 2;
  }
LABEL_24:
  v16 = v8;
  v15 = 0xFFFFFFFFFFFFFFFFui64 % v8;
  maxval = 0xFFFFFFFFFFFFFFFFui64 / v8;
  while ( 1 )
  {
    if ( _isdigit((unsigned __int8)c[0]) )
    {
      v9 = (char)c[0] - 48;
    }
    else
    {
      if ( !_isalpha((unsigned __int8)c[0]) )
        break;
      v9 = _toupper((char)c[0]) - 55;
    }
    if ( v9 >= (unsigned int)ibase )
      break;
    flags |= 8u;
    if ( __PAIR__(v5, *(unsigned int *)&c[1]) < maxval
      || __PAIR__(v5, *(unsigned int *)&c[1]) == maxval && (unsigned int)v9 <= v15 )
    {
      v10 = (unsigned int)v9 + v16 * __PAIR__(v5, *(unsigned int *)&c[1]);
      v5 = HIDWORD(v10);
      *(_DWORD *)&c[1] = v10;
      c[0] = *v6++;
    }
    else
    {
      flags |= 4u;
      c[0] = *v6++;
    }
  }
  v11 = v6 - 1;
  if ( flags & 8 )
  {
    if ( flags & 4
      || !(flags & 1)
      && (flags & 2 && (v5 > 0x80000000 || v5 >= 0x80000000 && *(_DWORD *)&c[1])
       || !(flags & 2) && v5 >= 0x7FFFFFFF && (v5 > 0x7FFFFFFF || *(_DWORD *)&c[1] > 0xFFFFFFFF)) )
    {
      *__errno() = 34;
      if ( flags & 1 )
      {
        *(_DWORD *)&c[1] = -1;
      }
      else if ( flags & 2 )
      {
        *(_DWORD *)&c[1] = 0;
      }
      else
      {
        *(_DWORD *)&c[1] = -1;
      }
    }
  }
  else
  {
    if ( endptr )
      v11 = nptr;
    *(_DWORD *)&c[1] = 0;
  }
  if ( endptr )
    *endptr = v11;
  if ( flags & 2 )
    *(_DWORD *)&c[1] = -*(_DWORD *)&c[1];
  return *(_DWORD *)&c[1];
}

//----- (0065CE30) --------------------------------------------------------  // acclient.c:626911
int __cdecl strtoint64(const char *nptr, const char **endptr, int ibase)
{
  return strtoxint64(nptr, endptr, ibase, 0);
}

//----- (0065CE50) --------------------------------------------------------  // acclient.c:626917
int __cdecl strtouint64(const char *nptr, const char **endptr, int ibase)
{
  return strtoxint64(nptr, endptr, ibase, 1);
}

