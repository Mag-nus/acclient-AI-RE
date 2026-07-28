/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIGlobals
   Object     : GAME\game_ui_misc\UIGlobals.obj
   Functions  : 3
   Addresses  : 004EE470 - 004EE540 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EE470) --------------------------------------------------------  // acclient.c:282905
void __cdecl UIGlobals::Init()
{
  signed int v0; // ebp@2
  int v1; // ebx@2
  void *v2; // esi@2
  signed int v3; // edi@2
  signed int v4; // ecx@4
  int i; // [sp+0h] [bp-4h]@2

  if ( !UIGlobals::s_pLevelArray )
  {
    v0 = 0;
    v1 = 0;
    v2 = operator new[](0xC8u);
    v3 = 0;
    UIGlobals::s_pLevelArray = v2;
    i = 0;
    do
    {
      *((_WORD *)v2 + v3) = (unsigned __int64)(sin((double)i * 3.141592 * 0.0101010101010101) * 1024.0);
      v2 = UIGlobals::s_pLevelArray;
      v0 += *((_WORD *)UIGlobals::s_pLevelArray + v3++);
      i = v3;
    }
    while ( v3 < 100 );
    v4 = 0;
    while ( 1 )
    {
      v1 += *(_WORD *)((char *)v2 + v4);
      v4 += 2;
      *(_WORD *)((char *)v2 + v4 - 2) = (v1 << 10) / v0;
      if ( v4 >= 200 )
        break;
      v2 = UIGlobals::s_pLevelArray;
    }
  }
}

//----- (004EE520) --------------------------------------------------------  // acclient.c:282944
void __cdecl UIGlobals::Cleanup()
{
  operator delete[](UIGlobals::s_pLevelArray);
  UIGlobals::s_pLevelArray = 0;
}

//----- (004EE540) --------------------------------------------------------  // acclient.c:282951
__int16 __cdecl UIGlobals::GetAnimLevel(float i_fPercentage)
{
  double v1; // st7@1

  v1 = i_fPercentage;
  if ( i_fPercentage < 0.0 )
    v1 = 0.0;
  if ( v1 > 1.0 )
    v1 = 1.0;
  return *((_WORD *)UIGlobals::s_pLevelArray - (unsigned __int64)(v1 * -99.0));
}

