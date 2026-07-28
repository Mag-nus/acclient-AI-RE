/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Glyph
   Object     : ENGINE\uielement_types\Glyph.obj
   Functions  : 11
   Addresses  : 004747D0 - 006EC150 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004747D0) --------------------------------------------------------  // acclient.c:177561
BOOL __thiscall Glyph::IsWhiteSpace(Glyph *this)
{
  unsigned __int16 v1; // ax@1

  v1 = this->m_data;
  return this->m_data == 9 || v1 == 13 || v1 == 32;
}

//----- (004747F0) --------------------------------------------------------  // acclient.c:177570
BOOL __thiscall Glyph::IsNewLine(Glyph *this)
{
  return this->m_data == 10;
}

//----- (00474800) --------------------------------------------------------  // acclient.c:177576
void __thiscall Glyph::Glyph(Glyph *this)
{
  this->m_data = 0;
  this->m_width = 0;
  this->m_height = 0;
  this->m_font = 0;
  this->m_tag = 0;
}

//----- (00474820) --------------------------------------------------------  // acclient.c:177586
void __thiscall Glyph::~Glyph(Glyph *this)
{
  Glyph *v1; // esi@1
  TextTag *v2; // edi@1
  Font *v3; // ecx@6

  v1 = this;
  v2 = this->m_tag;
  if ( v2 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, 1u);
    v1->m_tag = 0;
  }
  v3 = v1->m_font;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_font = 0;
  }
}

//----- (00474870) --------------------------------------------------------  // acclient.c:177609
int __thiscall Glyph::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ecx@2
  int v4; // ecx@2
  int v5; // ebx@4
  int v6; // eax@9
  int v7; // eax@11

  v2 = this;
  if ( this != a2 )
  {
    *(_WORD *)this = *(_WORD *)a2;
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    v3 = this + 12;
    *(_DWORD *)v3 = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(v3 + 4) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(v3 + 12) = *(_DWORD *)(a2 + 24);
    v4 = *(_DWORD *)(v2 + 28);
    if ( v4 )
    {
      (*(void (**)(void))(*(_DWORD *)v4 + 20))();
      *(_DWORD *)(v2 + 28) = 0;
    }
    v5 = *(_DWORD *)(v2 + 32);
    if ( v5 )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      *(_DWORD *)(v2 + 32) = 0;
    }
    v6 = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(v2 + 28) = v6;
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(a2 + 32);
    if ( v6 )
      (*(void (**)(void))(*(_DWORD *)v6 + 16))();
    v7 = *(_DWORD *)(v2 + 32);
    if ( v7 )
      InterlockedIncrement((volatile LONG *)(v7 + 4));
  }
  return v2;
}

//----- (00474920) --------------------------------------------------------  // acclient.c:177655
void __thiscall Glyph::SetTag(Glyph *this, TextTag *_pTag)
{
  Glyph *v2; // edi@1
  TextTag *v3; // esi@1

  v2 = this;
  v3 = this->m_tag;
  if ( v3 )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
    }
    v2->m_tag = 0;
    v2->m_tag = _pTag;
  }
  else
  {
    this->m_tag = _pTag;
  }
}

//----- (00474970) --------------------------------------------------------  // acclient.c:177679
void __thiscall Glyph::Glyph(Glyph *this, Glyph *_rhs)
{
  this->m_data = 0;
  this->m_width = 0;
  this->m_height = 0;
  this->m_font = 0;
  this->m_tag = 0;
  Glyph::operator=((int)this, (int)_rhs);
}

//----- (004749A0) --------------------------------------------------------  // acclient.c:177690
void __thiscall Glyph::SetFont(Glyph *this, Font *_font)
{
  Glyph *v2; // esi@1
  bool v3; // zf@1
  Font *v4; // ecx@1
  bool v5; // bl@1
  int v6; // eax@6
  int v7; // ebx@6
  int v8; // edi@9
  Font *v9; // ecx@12
  Font *v10; // ecx@19
  char v11; // al@20
  Font *v12; // ecx@20

  v2 = this;
  v3 = this->m_data == 10;
  v4 = this->m_font;
  v5 = v3;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->Release)();
    v2->m_font = 0;
  }
  if ( _font )
  {
    if ( Font::ContainsChar(_font, v2->m_data) || v5 )
    {
      v2->m_font = _font;
      _font->vfptr->AddRef((Interface *)_font);
    }
    else
    {
      v6 = DBObj::GetByEnum(20, 9, 0x2Eu);
      v7 = v6;
      if ( v6 && Font::ContainsChar((Font *)v6, v2->m_data) )
        v2->m_font = (Font *)v7;
      v8 = DBObj::GetByEnum(22, 9, 0x2Eu);
      if ( v8 && Font::ContainsChar((Font *)v8, v2->m_data) )
        v2->m_font = (Font *)v8;
      v9 = v2->m_font;
      if ( v9 )
        ((void (*)(void))v9->vfptr->AddRef)();
      if ( v8 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 20))(v8);
      if ( v7 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 20))(v7);
    }
  }
  v10 = v2->m_font;
  if ( v10 )
  {
    v11 = Font::GetCharWidthA(v10, v2->m_data);
    v12 = v2->m_font;
    v2->m_width = (unsigned __int8)v11;
    v2->m_height = v12->maxCharHeight;
  }
}

//----- (00474A90) --------------------------------------------------------  // acclient.c:177749
void __thiscall Glyph::Glyph(Glyph *this, const unsigned __int16 _character, RGBAColor *_color, Font *_font, TextTag *_tag)
{
  Glyph *v5; // esi@1
  TextTag *v6; // eax@1

  v5 = this;
  this->m_data = _character;
  this->m_width = 0;
  this->m_height = 0;
  this->m_color = *_color;
  this->m_font = 0;
  this->m_tag = _tag;
  Glyph::SetFont(this, _font);
  v6 = v5->m_tag;
  if ( v6 )
    InterlockedIncrement((volatile LONG *)&v6->m_cRef);
}

//----- (00474B00) --------------------------------------------------------  // acclient.c:177768
void __thiscall Glyph::Glyph(Glyph *this, const unsigned __int16 _character, RGBAColor *_color, Font *_font, TextTag *_tag, const unsigned int _width, const unsigned int _height)
{
  Glyph *v7; // esi@1
  TextTag *v8; // eax@1

  v7 = this;
  this->m_data = _character;
  this->m_width = _width;
  this->m_height = _height;
  this->m_color = *_color;
  this->m_font = 0;
  this->m_tag = _tag;
  Glyph::SetFont(this, _font);
  v8 = v7->m_tag;
  if ( v8 )
    InterlockedIncrement((volatile LONG *)&v8->m_cRef);
}

//----- (006EC150) --------------------------------------------------------  // acclient.c:767903
int _E1_72()
{
  return atexit(_E2_72);
}

