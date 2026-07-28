/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellBookPage
   Object     : AC\acqualities\SpellBookPage.obj
   Functions  : 2
   Addresses  : 005CC230 - 005CC260 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CC230) --------------------------------------------------------  // acclient.c:503925
signed int __thiscall SpellBookPage::Pack(SpellBookPage *this, void **addr, unsigned int size)
{
  if ( size >= 4 )
  {
    *(float *)*addr = this->_casting_likelihood + 2.0;
    *addr = (char *)*addr + 4;
  }
  return 4;
}

//----- (005CC260) --------------------------------------------------------  // acclient.c:503936
int __thiscall SpellBookPage::UnPack(SpellBookPage *this, void **addr, unsigned int size)
{
  int result; // eax@2
  double v4; // st7@3
  char *v5; // esi@3

  if ( size >= 4 )
  {
    v4 = *(float *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    if ( v4 < 2.0 )
    {
      *addr = v5 + 4;
      LODWORD(this->_casting_likelihood) = *((_DWORD *)v5 + 1);
      *addr = (char *)*addr + 4;
      result = 1;
    }
    else
    {
      result = 1;
      this->_casting_likelihood = v4 - 2.0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

