/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CCellPortal
   Object     : PORTAL\cgeometry\CCellPortal.obj
   Functions  : 15
   Addresses  : 0053BA10 - 00700990 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0053BA10) --------------------------------------------------------  // acclient.c:362329
void __thiscall CCellPortal::CCellPortal(CCellPortal *this)
{
  this->other_cell_id = 0;
  this->other_cell_ptr = 0;
  this->portal = 0;
  this->portal_side = 0;
  this->other_portal_id = -1;
  this->exact_match = -1;
}

//----- (0053BA30) --------------------------------------------------------  // acclient.c:362340
RenderVertexStreamD3D *__thiscall CCellPortal::GetOtherCell(CCellPortal *this, int do_not_load)
{
  return CEnvCell::GetVisible(this->other_cell_id);
}

//----- (0053BA40) --------------------------------------------------------  // acclient.c:362346
signed int __thiscall CCellPortal::Pack(CCellPortal *this, void **addr, unsigned int size)
{
  signed __int16 v3; // dx@2
  char *v4; // edx@8
  char *v5; // esi@8
  char *v6; // edx@8

  if ( size >= 8 )
  {
    v3 = 0;
    if ( this->exact_match )
      v3 = 1;
    if ( !this->portal_side )
      v3 |= 2u;
    if ( this->other_cell_id == -1 )
      v3 |= 4u;
    *(_WORD *)*addr = v3;
    v4 = (char *)*addr + 2;
    *addr = v4;
    *(_WORD *)v4 = this->portal->poly_id;
    v5 = (char *)*addr + 2;
    *addr = v5;
    *(_WORD *)v5 = LOWORD(this->other_cell_id);
    v6 = (char *)*addr + 2;
    *addr = v6;
    *(_WORD *)v6 = LOWORD(this->other_portal_id);
    *addr = (char *)*addr + 2;
  }
  return 8;
}

//----- (0053BAB0) --------------------------------------------------------  // acclient.c:362378
int __thiscall CCellPortal::UnPack(CCellPortal *this, unsigned int block_mask, unsigned __int16 *poly_id, void **addr, unsigned int size)
{
  __int16 v5; // dx@1
  unsigned __int16 v6; // di@1
  unsigned __int16 v7; // di@1
  __int16 v8; // dx@4

  v5 = *(_WORD *)*addr;
  *addr = (char *)*addr + 2;
  this->exact_match = v5 & 1;
  this->portal_side = ((unsigned int)(unsigned __int8)~(_BYTE)v5 >> 1) & 1;
  v6 = *(_WORD *)*addr;
  *addr = (char *)*addr + 2;
  *poly_id = v6;
  v7 = *(_WORD *)*addr;
  *addr = (char *)*addr + 2;
  if ( v5 & 4 )
    this->other_cell_id = -1;
  else
    this->other_cell_id = block_mask | v7;
  v8 = *(_WORD *)*addr;
  *addr = (char *)*addr + 2;
  this->other_portal_id = v8;
  return 1;
}

//----- (00700890) --------------------------------------------------------  // acclient.c:788402
int _E89_2()
{
  return atexit(_E90_1);
}

//----- (007008A0) --------------------------------------------------------  // acclient.c:788408
int _E92_1()
{
  return atexit(nullsub_1193);
}

//----- (007008B0) --------------------------------------------------------  // acclient.c:788414
int sub_7008B0()
{
  return atexit(_E96_5);
}

//----- (007008C0) --------------------------------------------------------  // acclient.c:788420
void _E98_8()
{
  LODWORD(dword_8452F8) = 1053364187;
}

//----- (007008D0) --------------------------------------------------------  // acclient.c:788426
void sub_7008D0()
{
  flt_8452FC = 1000.0 + 1.0;
}

//----- (007008F0) --------------------------------------------------------  // acclient.c:788432
void _E102_21()
{
  flt_845300 = 24.0 * 8.0;
}

//----- (00700910) --------------------------------------------------------  // acclient.c:788438
void _E104_11()
{
  flt_845304 = 24.0 * 0.5;
}

//----- (00700930) --------------------------------------------------------  // acclient.c:788444
void _E106_98()
{
  flt_845308 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00700950) --------------------------------------------------------  // acclient.c:788450
void _E108_76()
{
  dbl_845310 = 1.0 / 30.0;
}

//----- (00700970) --------------------------------------------------------  // acclient.c:788456
void _E110_62()
{
  dbl_845318 = 1.0 / 5.0;
}

//----- (00700990) --------------------------------------------------------  // acclient.c:788462
int sub_700990()
{
  return atexit(nullsub_1191);
}

