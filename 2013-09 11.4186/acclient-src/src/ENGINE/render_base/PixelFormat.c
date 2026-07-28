/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : PixelFormat
   Object     : ENGINE\render_base\PixelFormat.obj
   Functions  : 4
   Addresses  : 0043CFB0 - 006C6AB0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0043CFB0) --------------------------------------------------------  // acclient.c:121846
void __thiscall PixelFormatDesc::CalcBitOffsets(PixelFormatDesc *this)
{
  PixelFormatDesc *v1; // eax@1
  unsigned int v2; // esi@1
  char v3; // cl@1
  unsigned int v4; // esi@5
  char v5; // cl@5
  unsigned int v6; // esi@9
  char v7; // cl@9
  unsigned int v8; // edi@13
  char v9; // cl@13
  char v10; // dl@17
  int v11; // esi@17
  signed int v12; // ebp@17
  char v13; // dl@19
  int v14; // esi@19
  signed int v15; // ebp@19
  char v16; // dl@21
  int v17; // esi@21
  signed int v18; // ebp@21
  char v19; // dl@23
  int v20; // esi@23
  signed int v21; // ebp@23
  char v22; // [sp+10h] [bp-10h]@5
  char v23; // [sp+11h] [bp-Fh]@9
  char v24; // [sp+12h] [bp-Eh]@13
  unsigned int v25; // [sp+14h] [bp-Ch]@1
  unsigned int v26; // [sp+18h] [bp-8h]@5
  unsigned int v27; // [sp+1Ch] [bp-4h]@9

  v1 = this;
  v2 = this->redBitMask;
  v3 = 0;
  v25 = v2;
  while ( !((v2 >> v3) & 1) )
  {
    ++v3;
    if ( (unsigned __int8)v3 >= 0x20u )
    {
      v3 = 0;
      break;
    }
  }
  v4 = v1->greenBitMask;
  v22 = v3;
  v1->redBitOffset = v3;
  v5 = 0;
  v26 = v4;
  while ( !((v4 >> v5) & 1) )
  {
    ++v5;
    if ( (unsigned __int8)v5 >= 0x20u )
    {
      v5 = 0;
      break;
    }
  }
  v6 = v1->blueBitMask;
  v23 = v5;
  v1->greenBitOffset = v5;
  v7 = 0;
  v27 = v6;
  while ( !((v6 >> v7) & 1) )
  {
    ++v7;
    if ( (unsigned __int8)v7 >= 0x20u )
    {
      v7 = 0;
      break;
    }
  }
  v8 = v1->alphaBitMask;
  v24 = v7;
  v1->blueBitOffset = v7;
  v9 = 0;
  while ( !((v8 >> v9) & 1) )
  {
    ++v9;
    if ( (unsigned __int8)v9 >= 0x20u )
    {
      v9 = 0;
      break;
    }
  }
  v10 = 0;
  v1->alphaBitOffset = v9;
  v11 = 0;
  v12 = 32;
  do
  {
    v10 += (v25 >> v11++) & 1;
    --v12;
  }
  while ( v12 );
  v1->redBitCount = v10;
  v13 = 0;
  v14 = 0;
  v15 = 32;
  do
  {
    v13 += (v26 >> v14++) & 1;
    --v15;
  }
  while ( v15 );
  v1->greenBitCount = v13;
  v16 = 0;
  v17 = 0;
  v18 = 32;
  do
  {
    v16 += (v27 >> v17++) & 1;
    --v18;
  }
  while ( v18 );
  v1->blueBitCount = v16;
  v19 = 0;
  v20 = 0;
  v21 = 32;
  do
  {
    v19 += (v8 >> v20++) & 1;
    --v21;
  }
  while ( v21 );
  v1->alphaBitCount = v19;
  v1->redMax = v25 >> v22;
  v1->greenMax = v26 >> v23;
  v1->blueMax = v27 >> v24;
  v1->alphaMax = v8 >> v9;
}

//----- (0043D0F0) --------------------------------------------------------  // acclient.c:121978
bool __thiscall PixelFormatDesc::SetFormat(PixelFormatDesc *this, PixelFormatID _format)
{
  bool result; // al@6

  this->format = _format;
  this->flags = 0;
  this->fourCC = 0;
  this->bitsPerPixel = 0;
  this->alphaBitMask = 0;
  this->blueBitMask = 0;
  this->greenBitMask = 0;
  this->redBitMask = 0;
  this->alphaBitOffset = 0;
  this->blueBitOffset = 0;
  this->greenBitOffset = 0;
  this->redBitOffset = 0;
  if ( (signed int)_format <= 41 )
  {
    if ( _format == 41 )
    {
      this->flags = 64;
      this->bitsPerPixel = 8;
      PixelFormatDesc::CalcBitOffsets(this);
      return 1;
    }
    switch ( _format )
    {
      case 21:
        this->flags = 3;
        this->bitsPerPixel = 32;
        this->alphaBitMask = -16777216;
        goto LABEL_38;
      case 22:
        this->bitsPerPixel = 32;
        goto LABEL_37;
      case 23:
        this->flags = 1;
        this->redBitMask = 63488;
        this->greenBitMask = 2016;
        this->bitsPerPixel = 16;
        this->blueBitMask = 31;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 24:
        this->flags = 1;
        goto LABEL_9;
      case 25:
        this->flags = 3;
        this->alphaBitMask = 0x8000;
LABEL_9:
        this->redBitMask = 31744;
        this->greenBitMask = 992;
        this->bitsPerPixel = 16;
        this->blueBitMask = 31;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 26:
        this->flags = 3;
        this->alphaBitMask = 61440;
        goto LABEL_12;
      case 30:
        this->flags = 1;
LABEL_12:
        this->bitsPerPixel = 16;
        this->redBitMask = 3840;
        this->greenBitMask = 240;
        this->blueBitMask = 15;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 31:
        this->flags = 3;
        this->bitsPerPixel = 32;
        this->alphaBitMask = -1073741824;
        this->blueBitMask = 1072693248;
        this->greenBitMask = 1047552;
        this->redBitMask = 1023;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 32:
        this->flags = 3;
        this->alphaBitMask = -16777216;
        goto LABEL_16;
      case 33:
        this->flags = 1;
LABEL_16:
        this->bitsPerPixel = 32;
        this->blueBitMask = 16711680;
        this->greenBitMask = 65280;
        this->redBitMask = 255;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 35:
        this->flags = 3;
        this->bitsPerPixel = 32;
        this->alphaBitMask = -1073741824;
        this->redBitMask = 1072693248;
        this->greenBitMask = 1047552;
        this->blueBitMask = 1023;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      case 20:
        goto $L94082;
      case 28:
        goto $L94152;
      default:
        return 0;
    }
    return 0;
  }
  if ( (signed int)_format > 241 )
  {
    if ( (signed int)_format <= 827611204 )
    {
      if ( _format == 827611204 )
      {
        this->flags = 4;
        this->fourCC = 827611204;
        this->bitsPerPixel = 4;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      }
      if ( (signed int)_format > 244 )
      {
        if ( _format == 500 )
        {
          this->flags = 17;
          PixelFormatDesc::CalcBitOffsets(this);
          return 1;
        }
        return 0;
      }
      if ( _format == 244 )
      {
$L94152:
        this->flags = 2;
        this->alphaBitMask = 255;
        this->bitsPerPixel = 8;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      }
      if ( _format == 242 )
      {
        this->flags = 1;
        this->bitsPerPixel = 24;
        this->redBitMask = 255;
        this->greenBitMask = 65280;
        this->blueBitMask = 16711680;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      }
      if ( _format == 243 )
      {
$L94082:
        this->bitsPerPixel = 24;
LABEL_37:
        this->flags = 1;
LABEL_38:
        this->redBitMask = 16711680;
        this->greenBitMask = 65280;
        this->blueBitMask = 255;
        PixelFormatDesc::CalcBitOffsets(this);
        return 1;
      }
      return 0;
    }
    if ( (signed int)_format > 877942852 )
    {
      if ( _format != 894720068 )
        return 0;
      this->fourCC = 894720068;
    }
    else if ( _format == 877942852 )
    {
      this->fourCC = 877942852;
    }
    else if ( _format == 844388420 )
    {
      this->fourCC = 844388420;
    }
    else
    {
      if ( _format != 861165636 )
        return 0;
      this->fourCC = 861165636;
    }
    this->flags = 4;
    this->bitsPerPixel = 8;
    PixelFormatDesc::CalcBitOffsets(this);
    return 1;
  }
  if ( _format == 241 )
  {
    this->flags = 3;
    this->bitsPerPixel = 32;
    this->redBitMask = 255;
    this->greenBitMask = 65280;
    this->blueBitMask = 16711680;
    this->alphaBitMask = -16777216;
    PixelFormatDesc::CalcBitOffsets(this);
    result = 1;
  }
  else
  {
    switch ( _format )
    {
      case 101:
        this->flags = 64;
        this->bitsPerPixel = 16;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 60:
        this->flags = 9;
        this->bitsPerPixel = 16;
        this->redBitMask = 65280;
        this->greenBitMask = 255;
        this->blueBitMask = 0;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 71:
        this->flags = 2;
        this->bitsPerPixel = 32;
        this->alphaBitMask = -1;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 73:
        this->flags = 2;
        this->bitsPerPixel = 16;
        this->alphaBitMask = 65534;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 70:
      case 80:
        this->flags = 2;
        this->bitsPerPixel = 16;
        this->alphaBitMask = 0xFFFF;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 75:
      case 77:
      case 79:
        this->flags = 2;
        this->bitsPerPixel = 32;
        this->alphaBitMask = -256;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      case 240:
        this->flags = 3;
        this->bitsPerPixel = 32;
        this->redBitMask = -16777216;
        this->greenBitMask = 16711680;
        this->blueBitMask = 65280;
        this->alphaBitMask = 255;
        PixelFormatDesc::CalcBitOffsets(this);
        result = 1;
        break;
      default:
        return 0;
    }
  }
  return result;
}

//----- (0043D630) --------------------------------------------------------  // acclient.c:122247
void __thiscall PixelFormatDesc::PixelFormatDesc(PixelFormatDesc *this, PixelFormatID _format)
{
  PixelFormatDesc::SetFormat(this, _format);
}

//----- (006C6AB0) --------------------------------------------------------  // acclient.c:734841
bool _E73_32()
{
  return PixelFormatDesc::SetFormat(&PixelFormatDesc_A8R8G8B8_6, PFID_A8R8G8B8);
}

