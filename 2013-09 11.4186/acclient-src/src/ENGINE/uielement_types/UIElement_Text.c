/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : UIElement_Text
   Object     : ENGINE\uielement_types\UIElement_Text.obj
   Functions  : 119
   Addresses  : 00466390 - 0075E080 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00466390) --------------------------------------------------------  // acclient.c:163049
BOOL __thiscall Box2D::IsValid(Box2D *this)
{
  return this->m_x1 - this->m_x0 + 1 > 0 && this->m_y1 - this->m_y0 + 1 > 0;
}

//----- (004663B0) --------------------------------------------------------  // acclient.c:163055
BOOL __cdecl NameInputFilter(unsigned __int16 ch)
{
  return ch < 0x100u && _isalpha(ch) || ch == 39 || ch == 32 || ch == 45;
}

//----- (004663F0) --------------------------------------------------------  // acclient.c:163061
bool __cdecl NumberInputFilter(unsigned __int16 ch)
{
  return _isdigit(ch) != 0;
}

//----- (00466410) --------------------------------------------------------  // acclient.c:163067
char __thiscall UIElement_Text::ClearSelection(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1

  v1 = this;
  UIElement_Text::SetSelecting(this, 0);
  v1->m_nSelectionStart = 0;
  v1->m_nSelectionEnd = 0;
  return 1;
}

//----- (00466440) --------------------------------------------------------  // acclient.c:163079
void __thiscall UIElement_Text::ScrollPage(UIElement_Text *this, int i_bUp)
{
  UIElement_Text *v2; // esi@1
  int v3; // eax@1

  v2 = this;
  v3 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[26].OnAction)(1, i_bUp, 1);
  UIElement_Scrollable::SetScrollableXY(
    (UIElement_Scrollable *)&v2->vfptr,
    v2->m_iScrollableX,
    v3 + v2->m_iScrollableY,
    0);
}

//----- (00466480) --------------------------------------------------------  // acclient.c:163094
ListIterator<Glyph> *__thiscall ListIterator<Glyph>::scalar_deleting_destructor(ListIterator<Glyph> *this, unsigned int a2)
{
  ListIterator<Glyph> *v2; // esi@1

  v2 = this;
  this->vfptr = (ListIterator<Glyph>Vtbl *)ListIterator<Glyph>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79C13C: using guessed type int (__thiscall *ListIterator<Glyph>::vftable[2])(void *, char);

//----- (004664A0) --------------------------------------------------------  // acclient.c:163107
void __thiscall SmartArray<Glyph,1>::Reset(SmartArray<Glyph,1> *this)
{
  SmartArray<Glyph,1> *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  Glyph *v4; // ecx@2
  TextTag *v5; // eax@3
  void *v6; // ebp@3
  int v7; // edx@3
  int v8; // eax@3
  Glyph *v9; // esi@3
  int v10; // ebx@4
  int v11; // eax@9
  int v12; // esi@10
  int v13; // ebx@10
  int v14; // eax@11
  Glyph v15; // [sp+Ch] [bp-24h]@11

  v1 = this;
  v2 = this->m_sizeAndDeallocate;
  v3 = this->m_sizeAndDeallocate & 0x80000000;
  v1->m_num = 0;
  if ( v3 == 0x80000000 )
  {
    v4 = v1->m_data;
    if ( v1->m_data )
    {
      v5 = v4[-1].m_tag;
      v6 = &v4[-1].m_tag;
      v7 = 9 * (_DWORD)v5;
      v8 = (int)((char *)&v5[-1].m_format + 3);
      v9 = &v4[4 * v7 / 0x24u];
      if ( v8 >= 0 )
      {
        v10 = v8 + 1;
        do
        {
          --v9;
          Glyph::~Glyph(v9);
          --v10;
        }
        while ( v10 );
      }
      operator delete[](v6);
    }
    v1->m_data = 0;
    v1->m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_data )
  {
    v11 = (v2 & 0x7FFFFFFF) - 1;
    if ( v11 >= 0 )
    {
      v12 = v11;
      v13 = v11 + 1;
      do
      {
        Glyph::Glyph(&v15);
        Glyph::operator=((int)&v1->m_data[v12], v14);
        Glyph::~Glyph(&v15);
        --v12;
        --v13;
      }
      while ( v13 );
    }
  }
}

//----- (00466550) --------------------------------------------------------  // acclient.c:163176
BOOL __thiscall Box2D::Intersection(Box2D *this, Box2D *_rhs, Box2D *_result)
{
  int v3; // edx@1
  Box2D *v4; // esi@1
  int v5; // eax@1
  bool v6; // sf@1
  unsigned __int8 v7; // of@1
  int *v8; // eax@1
  int v9; // ebx@3
  Box2D *v10; // edx@3
  Box2D *v11; // eax@3
  int v12; // edi@3
  Box2D **v13; // eax@3
  Box2D *v14; // ebp@5
  Box2D *v15; // eax@5
  int v16; // edi@5
  Box2D **v17; // eax@5
  int v18; // eax@7
  int v19; // ecx@7
  Box2D *v20; // esi@7
  Box2D **v21; // ecx@7
  int v22; // ecx@9
  int v24; // [sp+10h] [bp-4h]@1

  v3 = this->m_x0;
  v4 = _rhs;
  v5 = _rhs->m_x0;
  _rhs = (Box2D *)v5;
  v7 = __OFSUB__(v3, v5);
  v6 = v3 - v5 < 0;
  v24 = v3;
  v8 = (int *)&_rhs;
  if ( !(v6 ^ v7) )
    v8 = &v24;
  v9 = *v8;
  v10 = _result;
  _result->m_x0 = *v8;
  v11 = (Box2D *)v4->m_y0;
  v12 = this->m_y0;
  _rhs = v11;
  v7 = __OFSUB__(v12, v11);
  v6 = v12 - (signed int)v11 < 0;
  _result = (Box2D *)v12;
  v13 = &_rhs;
  if ( !(v6 ^ v7) )
    v13 = &_result;
  v14 = *v13;
  v10->m_y0 = (int)*v13;
  v15 = (Box2D *)v4->m_x1;
  v16 = this->m_x1;
  _rhs = v15;
  v7 = __OFSUB__(v15, v16);
  v6 = (signed int)((char *)v15 - v16) < 0;
  _result = (Box2D *)v16;
  v17 = &_rhs;
  if ( !(v6 ^ v7) )
    v17 = &_result;
  v18 = (int)*v17;
  v10->m_x1 = v18;
  v19 = this->m_y1;
  v20 = (Box2D *)v4->m_y1;
  _result = (Box2D *)v19;
  v7 = __OFSUB__(v20, v19);
  v6 = (signed int)((char *)v20 - v19) < 0;
  _rhs = v20;
  v21 = &_rhs;
  if ( !(v6 ^ v7) )
    v21 = &_result;
  v22 = (int)*v21;
  v10->m_y1 = v22;
  return v18 - v9 + 1 > 0 && v22 - (signed int)v14 + 1 > 0;
}

//----- (00466600) --------------------------------------------------------  // acclient.c:163250
void __thiscall UIElement_Text::SetNoIme(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 8;
  else
    this->m_bitField = v2 & 0xFFFFFFF7;
}

//----- (00466630) --------------------------------------------------------  // acclient.c:163262
void __thiscall UIElement_Text::SetOutline(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x10;
  else
    this->m_bitField = v2 & 0xFFFFFFEF;
}

//----- (00466660) --------------------------------------------------------  // acclient.c:163274
char __thiscall UIElement_Text::IMETurnOn(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  char v2; // al@2
  Font *v3; // ST00_4@3
  Box2D result; // [sp+4h] [bp-10h]@3

  v1 = this;
  if ( this->m_bitField & 8 )
  {
    v2 = 0;
  }
  else
  {
    UIRegion::GetScreenClipBox((UIRegion *)&this->vfptr, &result);
    v3 = v1->m_curFontObj;
    v2 = DBObj::InitLoad();
  }
  return v2;
}

//----- (004666A0) --------------------------------------------------------  // acclient.c:163296
void __thiscall UIElement_Text::CleanupStringDownloads(UIElement_Text *this)
{
  UIElement_Text *v1; // edi@1
  unsigned int v2; // eax@1
  unsigned int v3; // esi@2
  StringDownload *v4; // ecx@3

  v1 = this;
  v2 = this->m_downloadQueue.m_num;
  if ( v2 )
  {
    v3 = 0;
    if ( v2 )
    {
      do
      {
        v4 = v1->m_downloadQueue.m_data[v3];
        if ( v4 )
          ((void (__stdcall *)(signed int))v4->vfptr[1].OnContextFinished)(1);
        v1->m_downloadQueue.m_data[v3++] = 0;
      }
      while ( v3 < v1->m_downloadQueue.m_num );
    }
    v1->m_downloadQueue.m_num = 0;
    UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
  }
}

//----- (00466700) --------------------------------------------------------  // acclient.c:163325
PStringBase<unsigned short> *__thiscall UIElement_Text::GetText(UIElement_Text *this, PStringBase<unsigned short> *result)
{
  UIElement_Text *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  char *v4; // esi@1
  PStringBase<unsigned short> ret; // [sp+0h] [bp-4h]@1

  ret.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  GlyphList::InqText(&v2->m_glyphList, 0, &ret);
  v3 = ret.m_charbuffer;
  result->m_charbuffer = ret.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1].m_data[8]);
  v4 = (char *)&ret.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&ret.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (00466770) --------------------------------------------------------  // acclient.c:163346
PStringBase<unsigned short> *__thiscall UIElement_Text::GetPreParsedText(UIElement_Text *this, PStringBase<unsigned short> *result)
{
  UIElement_Text *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@1
  char *v4; // esi@1
  PStringBase<unsigned short> ret; // [sp+0h] [bp-4h]@1

  ret.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  GlyphList::InqText(&v2->m_glyphList, 1, &ret);
  v3 = ret.m_charbuffer;
  result->m_charbuffer = ret.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1].m_data[8]);
  v4 = (char *)&ret.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&ret.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (004667E0) --------------------------------------------------------  // acclient.c:163367
void __thiscall UIElement_Text::SetSelecting(UIElement_Text *this, bool _b)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // ecx@4
  bool v4; // zf@4

  v2 = this;
  if ( _b != ((this->m_bitField & 0x80) == -128) )
  {
    if ( _b )
    {
      this->m_bitField |= 0x80u;
    }
    else
    {
      v3 = this->m_bitField & 0xFFFFFF7F;
      v4 = (v2->m_bitField & 0x40) == 0;
      v2->m_bitField = v3;
      if ( !v4 )
        v2->m_bitField = v3 & 0xFFFFFFBF;
      UIElement_Text::SetSelecting(v2, 0);
      v2->m_nSelectionStart = 0;
      v2->m_nSelectionEnd = 0;
    }
  }
}

//----- (00466850) --------------------------------------------------------  // acclient.c:163395
void __thiscall UIElement_Text::SetDirty(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@2

  if ( _b != ((this->m_bitField & 0x100) == 256) )
  {
    v2 = this->m_bitField;
    if ( _b )
    {
      this->m_bitField = v2 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    }
    else
    {
      this->m_bitField = v2 & 0xFFFFFEFF;
    }
  }
}

//----- (004668A0) --------------------------------------------------------  // acclient.c:163415
void __thiscall UIElement_Text::DetermineMarginValues(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  int v2; // edx@1
  int v3; // ecx@1
  int v4; // eax@1
  bool v5; // sf@1
  unsigned __int8 v6; // of@1
  int *v7; // edx@1
  int v8; // edx@3
  int v9; // eax@3
  int v10; // edi@3
  int *v11; // eax@3
  int v12; // eax@5
  int *v13; // eax@5
  int v14; // eax@7
  int v15; // ecx@7
  int nSurfHeight; // [sp+8h] [bp-18h]@1
  int nSurfWidth; // [sp+Ch] [bp-14h]@1
  Box2D surfaceBox; // [sp+10h] [bp-10h]@1

  v1 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[4].OnAction)(&surfaceBox);
  v2 = v1->m_margU;
  v3 = surfaceBox.m_x1 - surfaceBox.m_x0 + 1;
  v4 = surfaceBox.m_y1 - surfaceBox.m_y0 + 1;
  v6 = __OFSUB__(v4, v2);
  v5 = v4 - v2 < 0;
  nSurfWidth = surfaceBox.m_x1 - surfaceBox.m_x0 + 1;
  nSurfHeight = surfaceBox.m_y1 - surfaceBox.m_y0 + 1;
  v7 = &nSurfHeight;
  if ( !(v5 ^ v6) )
    v7 = &v1->m_margU;
  v8 = *v7;
  v9 = v4 - v8;
  v1->m_margU = v8;
  v10 = v1->m_margD;
  nSurfHeight = v9;
  v6 = __OFSUB__(v9, v10);
  v5 = v9 - v10 < 0;
  v11 = &nSurfHeight;
  if ( !(v5 ^ v6) )
    v11 = &v1->m_margD;
  v1->m_margD = *v11;
  v12 = v1->m_margL;
  v6 = __OFSUB__(v3, v12);
  v5 = v3 - v12 < 0;
  v13 = &nSurfWidth;
  if ( !(v5 ^ v6) )
    v13 = &v1->m_margL;
  v14 = *v13;
  v15 = v3 - v14;
  v1->m_margL = v14;
  v6 = __OFSUB__(v15, v1->m_margR);
  v5 = v15 - v1->m_margR < 0;
  nSurfWidth = v15;
  if ( v5 ^ v6 )
    v1->m_margR = nSurfWidth;
  else
    v1->m_margR = v1->m_margR;
}

//----- (00466960) --------------------------------------------------------  // acclient.c:163478
void __thiscall UIElement_Text::SetFontDIDHelper(UIElement_Text *this, unsigned int _property, Font **_font, unsigned int _fontDIDNum)
{
  Font **v4; // edi@1
  IInputActionCallbackVtbl *v5; // eax@2
  int v6; // esi@12
  BasePropertyDesc *v7; // ecx@18
  unsigned int v8; // edx@18
  BasePropertyValue *v9; // ecx@22
  unsigned int v10; // edx@22
  BaseProperty prop; // [sp+1Ch] [bp-10h]@2
  BaseProperty p; // [sp+24h] [bp-8h]@6

  v4 = _font;
  if ( !*_font )
    return;
  v5 = this->vfptr;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v5[17].OnAction)(_property, &prop) )
  {
    if ( !prop.m_pcPropertyValue
      || !(unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&_font) )
      goto LABEL_26;
    if ( _fontDIDNum < (unsigned int)_font )
    {
      p.m_pcPropertyDesc = 0;
      p.m_pcPropertyValue = 0;
      if ( prop.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD))prop.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                              _fontDIDNum,
                              &p)
        && p.m_pcPropertyValue
        && (unsigned __int8)((int (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&_property) )
      {
        if ( _property != INVALID_DID_56.id && _property != (*v4)->m_DID.id )
        {
          v6 = FontLocal::GetGlobalOrLocalFont((IDClass<_tagDataID,32,0>)_property);
          if ( v6 )
          {
            if ( *v4 )
            {
              ((void (*)(void))(*v4)->vfptr->Release)();
              *v4 = 0;
            }
            *v4 = (Font *)v6;
          }
        }
        BaseProperty::~BaseProperty(&p);
        goto LABEL_17;
      }
      BaseProperty::~BaseProperty(&p);
LABEL_26:
      BaseProperty::~BaseProperty(&prop);
      return;
    }
  }
LABEL_17:
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v7 = prop.m_pcPropertyDesc;
    v8 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v8;
    if ( !v8 )
      ((void (__stdcall *)(_DWORD))v7->vfptr->__vecDelDtor)(1);
    prop.m_pcPropertyDesc = 0;
  }
  if ( prop.m_pcPropertyValue )
  {
    v9 = prop.m_pcPropertyValue;
    v10 = prop.m_pcPropertyValue->m_cRef - 1;
    prop.m_pcPropertyValue->m_cRef = v10;
    if ( !v10 )
      ((void (__stdcall *)(_DWORD))v9->vfptr->__vecDelDtor)(1);
  }
}

//----- (00466AC0) --------------------------------------------------------  // acclient.c:163555
void __thiscall UIElement_Text::SetFontColorHelper(UIElement_Text *this, unsigned int _property, RGBAColor *_color, unsigned int _fontColorNum)
{
  IInputActionCallbackVtbl *v4; // eax@1
  BasePropertyValue *v5; // ecx@2
  BasePropertyDesc *v6; // ecx@11
  unsigned int v7; // edx@11
  int v8; // eax@15
  int v9; // esi@16
  BasePropertyDesc *v10; // ecx@22
  unsigned int v11; // edx@22
  BaseProperty prop; // [sp+1Ch] [bp-10h]@1
  BaseProperty p; // [sp+24h] [bp-8h]@5

  v4 = this->vfptr;
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( !(unsigned __int8)((int (__stdcall *)(unsigned int, BaseProperty *))v4[17].OnAction)(_property, &prop) )
    goto LABEL_10;
  v5 = prop.m_pcPropertyValue;
  if ( prop.m_pcPropertyValue )
  {
    if ( (unsigned __int8)((int (__stdcall *)(_DWORD))prop.m_pcPropertyValue->vfptr[60].__vecDelDtor)(&_property) )
    {
      if ( _fontColorNum < _property )
      {
        p.m_pcPropertyDesc = 0;
        p.m_pcPropertyValue = 0;
        if ( !prop.m_pcPropertyValue
          || !(unsigned __int8)((int (__stdcall *)(_DWORD, _DWORD))prop.m_pcPropertyValue->vfptr[61].__vecDelDtor)(
                                 _fontColorNum,
                                 &p)
          || !p.m_pcPropertyValue
          || !(unsigned __int8)((int (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[38].__vecDelDtor)(_color) )
        {
          BaseProperty::~BaseProperty(&p);
          BaseProperty::~BaseProperty(&prop);
          return;
        }
        BaseProperty::~BaseProperty(&p);
      }
LABEL_10:
      if ( (_DWORD)prop.m_pcPropertyDesc )
      {
        v6 = prop.m_pcPropertyDesc;
        v7 = prop.m_pcPropertyDesc->m_cRef - 1;
        prop.m_pcPropertyDesc->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(_DWORD))v6->vfptr->__vecDelDtor)(1);
        prop.m_pcPropertyDesc = 0;
      }
      if ( prop.m_pcPropertyValue )
      {
        v5 = prop.m_pcPropertyValue;
        v8 = (int)&prop.m_pcPropertyValue->m_cRef;
        goto LABEL_16;
      }
      return;
    }
    v5 = prop.m_pcPropertyValue;
  }
  if ( (_DWORD)prop.m_pcPropertyDesc )
  {
    v10 = prop.m_pcPropertyDesc;
    v11 = prop.m_pcPropertyDesc->m_cRef - 1;
    prop.m_pcPropertyDesc->m_cRef = v11;
    if ( !v11 )
      ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
    v5 = prop.m_pcPropertyValue;
    prop.m_pcPropertyDesc = 0;
  }
  if ( v5 )
  {
    v8 = (int)&v5->m_cRef;
LABEL_16:
    v9 = *(_DWORD *)v8 - 1;
    *(_DWORD *)v8 = v9;
    if ( !v9 )
      ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  }
}

//----- (00466BF0) --------------------------------------------------------  // acclient.c:163637
void __thiscall UIElement_Text::SetFontDID(UIElement_Text *this, IDClass<_tagDataID,32,0> _did)
{
  UIElement_Text *v2; // esi@1
  BasePropertyValue *v3; // ecx@2
  char v4; // al@7
  BaseProperty *v5; // ecx@7
  BasePropertyDesc *v6; // ecx@13
  unsigned int v7; // edx@13
  int v8; // eax@17
  BasePropertyDesc *v9; // ecx@19
  unsigned int v10; // edx@19
  int v11; // esi@24
  BaseProperty p; // [sp+10h] [bp-10h]@1
  BaseProperty prop; // [sp+18h] [bp-8h]@4

  v2 = this;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  if ( !BaseProperty::SetPropertyName(&p, 0x18u) )
  {
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v9 = p.m_pcPropertyDesc;
      v10 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v10;
      if ( !v10 )
        ((void (__stdcall *)(signed int))v9->vfptr->__vecDelDtor)(1);
      p.m_pcPropertyDesc = 0;
    }
    if ( !p.m_pcPropertyValue )
      return;
    v3 = p.m_pcPropertyValue;
    v8 = (int)&p.m_pcPropertyValue->m_cRef;
LABEL_24:
    v11 = *(_DWORD *)v8 - 1;
    *(_DWORD *)v8 = v11;
    if ( !v11 )
      ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
    return;
  }
  v3 = p.m_pcPropertyValue;
  if ( !p.m_pcPropertyValue )
  {
LABEL_12:
    if ( (_DWORD)p.m_pcPropertyDesc )
    {
      v6 = p.m_pcPropertyDesc;
      v7 = p.m_pcPropertyDesc->m_cRef - 1;
      p.m_pcPropertyDesc->m_cRef = v7;
      if ( !v7 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
      v3 = p.m_pcPropertyValue;
      p.m_pcPropertyDesc = 0;
    }
    if ( !v3 )
      return;
    v8 = (int)&v3->m_cRef;
    goto LABEL_24;
  }
  BaseProperty::CheckCopyOnWrite(&p);
  if ( !(unsigned __int8)((int (__stdcall *)(unsigned int))p.m_pcPropertyValue->vfptr[45].__vecDelDtor)(_did.id) )
  {
    v3 = p.m_pcPropertyValue;
    goto LABEL_12;
  }
  prop.m_pcPropertyDesc = 0;
  prop.m_pcPropertyValue = 0;
  if ( BaseProperty::SetPropertyName(&prop, 0x1Au)
    && prop.m_pcPropertyValue
    && (BaseProperty::CheckCopyOnWrite(&prop),
        (unsigned __int8)((int (__stdcall *)(_DWORD, BaseProperty *))prop.m_pcPropertyValue->vfptr[62].__vecDelDtor)(
                           0,
                           &p)) )
  {
    v4 = ((int (__thiscall *)(UIElement_Text *, BaseProperty *))v2->vfptr[17].OnLoseFocus)(v2, &prop);
    v5 = &prop;
    if ( v4 )
    {
      BaseProperty::~BaseProperty(&prop);
      BaseProperty::~BaseProperty(&p);
      return;
    }
  }
  else
  {
    v5 = &prop;
  }
  BaseProperty::~BaseProperty(v5);
  BaseProperty::~BaseProperty(&p);
}

//----- (00466D50) --------------------------------------------------------  // acclient.c:163729
void __thiscall UIElement_Text::SetFontDIDWithoutChangingExistingText(UIElement_Text *this, IDClass<_tagDataID,32,0> _did)
{
  s_bChangeTextInDoFontRest = 0;
  UIElement_Text::SetFontDID(this, _did);
  s_bChangeTextInDoFontRest = 1;
}

//----- (00466D70) --------------------------------------------------------  // acclient.c:163737
void __thiscall UIElement_Text::ChangeExistingTextToNewFont(UIElement_Text *this, Font *i_pNewFont)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // ecx@1

  v2 = this;
  GlyphList::ChangeExistingGlyphsToNewFont(&this->m_glyphList, i_pNewFont);
  v3 = v2->m_bitField;
  if ( !(v3 & 0x100) )
  {
    v2->m_bitField = v3 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v2->vfptr);
  }
}

//----- (00466DB0) --------------------------------------------------------  // acclient.c:163753
char __thiscall UIElement_Text::MoveBeginEndLine(UIElement_Text *this, bool i_bBegin, unsigned int i_nStart, unsigned int *o_nPos)
{
  unsigned int v4; // ebp@1
  UIElement_Text *v5; // edi@1
  GlyphList *v6; // esi@1
  char result; // al@1
  unsigned int nStartPosition; // [sp+Ch] [bp-8h]@1
  unsigned int nCurrentLine; // [sp+10h] [bp-4h]@1

  v4 = i_nStart;
  v5 = this;
  v6 = &this->m_glyphList;
  nCurrentLine = 0;
  nStartPosition = 0;
  result = GlyphList::FindCurrentLine(&this->m_glyphList, i_nStart, &nCurrentLine, &nStartPosition);
  if ( result )
  {
    if ( i_bBegin )
    {
      *o_nPos = nStartPosition;
    }
    else
    {
      *(_DWORD *)&i_bBegin = 0;
      result = GlyphList::FindNextLine(v6, v4, (unsigned int *)&i_bBegin, &nStartPosition);
      if ( result )
      {
        if ( nCurrentLine == v5->m_glyphList.m_glyphLines.m_num - 1 )
          *o_nPos = v5->m_glyphList.m_glyphList._num_elements;
        else
          *o_nPos = nStartPosition - 1;
      }
    }
  }
  return result;
}

//----- (00466E60) --------------------------------------------------------  // acclient.c:163791
char __thiscall UIElement_Text::SetSelectionStart(UIElement_Text *this, unsigned int i_nPos)
{
  bool v2; // cf@2
  unsigned int *v3; // edx@2
  unsigned int v4; // edx@4
  unsigned int v5; // eax@4
  unsigned int v6; // edx@4
  char result; // al@6

  if ( SLOBYTE(this->m_bitField) >= 0 )
  {
    result = 0;
  }
  else
  {
    this->m_nSelectionStart = i_nPos;
    v2 = this->m_glyphList.m_glyphList._num_elements < this->m_nSelectionStart;
    i_nPos = this->m_glyphList.m_glyphList._num_elements;
    v3 = &i_nPos;
    if ( !v2 )
      v3 = &this->m_nSelectionStart;
    v4 = *v3;
    this->m_nSelectionStart = v4;
    v5 = v4;
    v6 = this->m_bitField;
    this->m_nSelectionEnd = v5;
    if ( !(v6 & 0x100) )
    {
      this->m_bitField = v6 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    }
    result = 1;
  }
  return result;
}

//----- (00466EC0) --------------------------------------------------------  // acclient.c:163828
char __thiscall UIElement_Text::SetSelectionEnd(UIElement_Text *this, unsigned int i_nPos)
{
  bool v2; // cf@2
  unsigned int *v3; // edx@2
  unsigned int v4; // edx@4
  char result; // al@6

  if ( SLOBYTE(this->m_bitField) >= 0 )
  {
    result = 0;
  }
  else
  {
    this->m_nSelectionEnd = i_nPos;
    v2 = this->m_glyphList.m_glyphList._num_elements < this->m_nSelectionEnd;
    i_nPos = this->m_glyphList.m_glyphList._num_elements;
    v3 = &i_nPos;
    if ( !v2 )
      v3 = &this->m_nSelectionEnd;
    this->m_nSelectionEnd = *v3;
    v4 = this->m_bitField;
    if ( !(v4 & 0x100) )
    {
      this->m_bitField = v4 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    }
    result = 1;
  }
  return result;
}

//----- (00466F20) --------------------------------------------------------  // acclient.c:163860
bool __thiscall UIElement_Text::GetSelection(UIElement_Text *this, unsigned int *o_nStart, unsigned int *o_nEnd)
{
  bool result; // al@1
  char *v4; // edx@2
  unsigned int v5; // ebp@2
  unsigned int *v6; // ecx@2
  unsigned int *v7; // esi@2

  *o_nStart = 0;
  *o_nEnd = 0;
  result = (this->m_bitField & 0x80) == -128;
  if ( (this->m_bitField & 0x80) == -128 )
  {
    v4 = (char *)&this->m_nSelectionEnd;
    v5 = this->m_nSelectionStart;
    v6 = &this->m_nSelectionStart;
    v7 = (unsigned int *)v4;
    if ( *(_DWORD *)v4 >= v5 )
      v7 = v6;
    *o_nStart = *v7;
    if ( *v6 < *(_DWORD *)v4 )
      v6 = (unsigned int *)v4;
    *o_nEnd = *v6;
  }
  return result;
}

//----- (00466F80) --------------------------------------------------------  // acclient.c:163888
void __thiscall UIElement_Text::RecalculateTruncation(UIElement_Text *this, int *io_iPaperWidth, int *io_iPaperHeight)
{
  UIElement_Text *v3; // esi@1
  int v4; // eax@2
  int v5; // ebp@4
  int v6; // eax@5
  unsigned int v7; // ebx@10
  PStringBase<unsigned short> *v8; // eax@11
  char *v9; // edi@11
  bool v10; // zf@15
  int v11; // eax@17
  int v12; // edx@18
  PSRefBufferCharData<unsigned short> *v13; // eax@18
  int v14; // ecx@18
  int v15; // eax@18
  unsigned int v16; // ecx@19
  int v17; // ebp@19
  char *v18; // edi@20
  int v19; // eax@21
  bool v20; // sf@23
  unsigned __int8 v21; // of@23
  int *v22; // eax@23
  int v23; // edx@25
  int v24; // eax@25
  int v25; // edx@26
  int v26; // eax@26
  bool _val; // [sp+Bh] [bp-A1h]@1
  PStringBase<unsigned short> result; // [sp+Ch] [bp-A0h]@11
  int cxThisLine; // [sp+10h] [bp-9Ch]@21
  unsigned int nLine; // [sp+14h] [bp-98h]@15
  int cxPaperSize; // [sp+18h] [bp-94h]@19
  StringInfo siTooltip; // [sp+1Ch] [bp-90h]@11

  v3 = this;
  UIElement::GetAttribute_Bool((UIElement *)&this->vfptr, 0xD0u, &_val);
  if ( v3->m_bitField & 2 )
    v4 = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
  else
    v4 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
  v5 = v4;
  if ( v3->m_bitField & 2 )
    v6 = *io_iPaperWidth;
  else
    v6 = *io_iPaperHeight;
  if ( v6 > v5 )
  {
    v7 = 0;
    if ( _val )
    {
      StringInfo::StringInfo(&siTooltip);
      v8 = UIElement_Text::GetText(v3, &result);
      StringInfo::SetLiteralValue(&siTooltip, v8, 1);
      v9 = (char *)&result.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) && v9 )
        (**(void (__thiscall ***)(char *, signed int))v9)(v9, 1);
      UIElement::SetTooltip((UIElement *)&v3->vfptr, &siTooltip);
      *((_DWORD *)&v3->0 + 41) |= 0x20u;
      StringInfo::~StringInfo(&siTooltip);
    }
    v10 = (v3->m_bitField & 2) == 0;
    nLine = 0;
    if ( v10 )
      GlyphList::FindCompleteLineFromY(&v3->m_glyphList, v5, &nLine);
    v11 = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
    GlyphList::FindPosFromLineAndPixels(
      &v3->m_glyphList,
      nLine,
      v11 - v3->m_margR - v3->m_margL - v3->m_cxTrailer,
      0,
      &v3->m_nTruncationPos);
    if ( v3->m_bitField & 2 )
    {
      GlyphList::FindPixelsFromPos(&v3->m_glyphList, v3->m_nTruncationPos, (int *)&result);
      v12 = v3->m_cxTrailer;
      v13 = result.m_charbuffer;
      v14 = v3->m_margL + v3->m_margR;
      v3->m_cxAdjustedLineNumber = 0;
      v15 = (int)((char *)v13 + v12);
      v3->m_cxAdjustedLineSize = v15;
      *io_iPaperWidth = v15 + v14;
    }
    else
    {
      v16 = nLine;
      cxPaperSize = 0;
      v17 = 0;
      result.m_charbuffer = 0;
      do
      {
        v18 = (char *)result.m_charbuffer + (unsigned int)v3->m_glyphList.m_glyphLines.m_data;
        if ( v7 == v16 )
        {
          GlyphList::FindPixelsFromPos(&v3->m_glyphList, v3->m_nTruncationPos, &cxThisLine);
          v19 = v3->m_cxTrailer + cxThisLine;
          v16 = nLine;
          v3->m_cxAdjustedLineSize = v19;
        }
        else
        {
          v19 = *((_DWORD *)v18 + 2);
        }
        cxThisLine = v19;
        v21 = __OFSUB__(cxPaperSize, v19);
        v20 = cxPaperSize - v19 < 0;
        v22 = &cxThisLine;
        if ( !(v20 ^ v21) )
          v22 = &cxPaperSize;
        v23 = *v22;
        v24 = *((_DWORD *)v18 + 3);
        cxPaperSize = v23;
        v17 += v24;
        ++v7;
        result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)result.m_charbuffer + 16);
      }
      while ( v7 <= v16 );
      v25 = cxPaperSize;
      v26 = v3->m_margL + v3->m_margR;
      v3->m_cxAdjustedLineNumber = v16;
      *io_iPaperWidth = v25 + v26;
      *io_iPaperHeight = v17 + v3->m_margU + v3->m_margD;
    }
  }
  else
  {
    v3->m_nTruncationPos = -1;
    v3->m_cxAdjustedLineNumber = -1;
    if ( _val )
    {
      *((_DWORD *)&v3->0 + 41) &= 0xFFFFFFDF;
      UIElement::ClearTooltip((UIElement *)&v3->vfptr);
    }
  }
}

//----- (00467200) --------------------------------------------------------  // acclient.c:164023
char __thiscall UIElement_Text::SetHorizontalJustification(UIElement_Text *this, unsigned int i_eJustification)
{
  unsigned int v2; // edx@1

  v2 = this->m_bitField;
  this->m_eHorizontalJustification = i_eJustification;
  if ( !(v2 & 0x100) )
  {
    this->m_bitField = v2 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
  }
  return 1;
}

//----- (00467230) --------------------------------------------------------  // acclient.c:164038
char __thiscall UIElement_Text::SetVerticalJustification(UIElement_Text *this, unsigned int i_eJustification)
{
  unsigned int v2; // edx@1

  v2 = this->m_bitField;
  this->m_eVerticalJustification = i_eJustification;
  if ( !(v2 & 0x100) )
  {
    this->m_bitField = v2 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
  }
  return 1;
}

//----- (00467260) --------------------------------------------------------  // acclient.c:164053
int __thiscall UIElement_Text::CalcJustification(UIElement_Text *this, unsigned int i_uiTextSize, bool i_bHorizontal)
{
  bool v3; // bl@1
  int v4; // edi@1
  UIElement_Text *v5; // esi@1
  int v6; // eax@2
  int v7; // ecx@2
  int v8; // edx@2
  int v9; // eax@2
  int v10; // ecx@2
  bool v11; // sf@2
  unsigned __int8 v12; // of@2
  bool *v13; // eax@2
  unsigned int v14; // eax@4
  unsigned int v15; // ecx@4
  int v16; // eax@5
  int v17; // ecx@5
  int v18; // edx@5
  int v19; // eax@5
  int v20; // ecx@5
  bool *v21; // eax@5
  int v22; // ecx@8
  int v23; // ecx@9
  unsigned int v24; // ecx@11
  int result; // eax@15
  int v26; // [sp+Ch] [bp-24h]@2
  char v27; // [sp+10h] [bp-20h]@2
  char v28; // [sp+20h] [bp-10h]@5

  v3 = i_bHorizontal;
  v4 = 0;
  v5 = this;
  if ( i_bHorizontal )
  {
    v6 = ((int (__stdcall *)(char *))this->vfptr[4].OnAction)(&v27);
    v7 = *(_DWORD *)(v6 + 8);
    v8 = *(_DWORD *)v6;
    v9 = v5->m_iScrollableWidth;
    v10 = v7 - v8 + 1;
    v26 = v9;
    v12 = __OFSUB__(v9, v10);
    v11 = v9 - v10 < 0;
    *(_DWORD *)&i_bHorizontal = v10;
    v13 = &i_bHorizontal;
    if ( !(v11 ^ v12) )
      v13 = (bool *)&v26;
    v14 = *(_DWORD *)v13 - v5->m_margR - v5->m_margL;
    v15 = v5->m_eHorizontalJustification;
  }
  else
  {
    v16 = ((int (__stdcall *)(char *))this->vfptr[4].OnAction)(&v28);
    v17 = *(_DWORD *)(v16 + 12);
    v18 = *(_DWORD *)(v16 + 4);
    v19 = v5->m_iScrollableHeight;
    v20 = v17 - v18 + 1;
    v26 = v19;
    v12 = __OFSUB__(v19, v20);
    v11 = v19 - v20 < 0;
    *(_DWORD *)&i_bHorizontal = v20;
    v21 = &i_bHorizontal;
    if ( !(v11 ^ v12) )
      v21 = (bool *)&v26;
    v14 = *(_DWORD *)v21 - v5->m_margD - v5->m_margU;
    v15 = v5->m_eVerticalJustification;
  }
  v22 = v15 - 1;
  if ( v22 )
  {
    v23 = v22 - 2;
    if ( v23 && v23 != 2 )
      goto LABEL_14;
    v24 = i_uiTextSize;
  }
  else
  {
    v14 >>= 1;
    v24 = i_uiTextSize >> 1;
  }
  v4 = v14 - v24;
LABEL_14:
  if ( v3 )
    result = v5->m_margL + v4;
  else
    result = v5->m_margU + v4;
  return result;
}

//----- (00467350) --------------------------------------------------------  // acclient.c:164142
char __thiscall UIElement_Text::RegisterInputMaps(UIElement_Text *this, int i_nPriority)
{
  UIElement_Text *v2; // esi@1
  char result; // al@2
  char v4; // bl@3
  char v5; // bl@4

  v2 = this;
  if ( ICIDM::s_cidm )
  {
    ((void (__stdcall *)(UIElement_Text *))ICIDM::s_cidm->vfptr->UnregisterCallback)(this);
    v4 = UIElement_Scrollable::RegisterInputMaps((UIElement_Scrollable *)&v2->vfptr, i_nPriority);
    if ( v2->m_bitField & 1 )
    {
      v5 = ((int (__stdcall *)(signed int, UIElement_Text *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
             1,
             v2,
             i_nPriority - 10) | v4;
      v4 = ((int (__stdcall *)(signed int, UIElement_Text *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
             7,
             v2,
             i_nPriority) | v5;
    }
    if ( v2->m_bitField & 5 )
      v4 |= ((int (__stdcall *)(signed int, UIElement_Text *, int))ICIDM::s_cidm->vfptr->RegisterInputMap)(
              8,
              v2,
              i_nPriority);
    result = v4;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004673D0) --------------------------------------------------------  // acclient.c:164180
char __thiscall UIElement_Text::UnregisterInputMaps(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  char result; // al@2
  char v3; // bl@3
  char v4; // bl@4

  v1 = this;
  if ( ICIDM::s_cidm )
  {
    v3 = UIElement_Scrollable::UnregisterInputMaps((UIElement_Scrollable *)&this->vfptr);
    if ( v1->m_bitField & 1 )
    {
      v4 = ((int (__stdcall *)(signed int, UIElement_Text *))ICIDM::s_cidm->vfptr->UnregisterInputMap)(1, v1) | v3;
      v3 = ((int (__stdcall *)(signed int, UIElement_Text *))ICIDM::s_cidm->vfptr->UnregisterInputMap)(7, v1) | v4;
    }
    if ( v1->m_bitField & 5 )
      v3 |= ((int (__stdcall *)(signed int, _DWORD))ICIDM::s_cidm->vfptr->UnregisterInputMap)(8, v1);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00467440) --------------------------------------------------------  // acclient.c:164208
void __thiscall UIElement_Text::AdjustToScrollableXYChange(UIElement_Text *this)
{
  unsigned int v1; // edx@1

  v1 = this->m_bitField;
  if ( !(v1 & 0x100) )
  {
    this->m_bitField = v1 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
  }
}

//----- (00467460) --------------------------------------------------------  // acclient.c:164221
char __thiscall UIElement_Text::GetShouldBeMouseVisible(UIElement_Text *this)
{
  char result; // al@2

  if ( this->m_bitField & 5 )
    result = 1;
  else
    result = UIElement::GetShouldBeMouseVisible((UIElement *)&this->vfptr);
  return result;
}

//----- (00467480) --------------------------------------------------------  // acclient.c:164233
void __thiscall UIElement_Text::SetTruncateTextToFit(UIElement_Text *this, bool _b)
{
  bool v2; // al@1
  bool v3; // zf@5
  unsigned int v4; // eax@5
  unsigned int v5; // eax@6
  unsigned int v6; // edx@8

  v2 = _b;
  if ( _b && this->m_bitField & 5 )
    v2 = 0;
  if ( v2 != ((this->m_bitField & 0x800) == 2048) )
  {
    v3 = v2 == 0;
    v4 = this->m_bitField;
    if ( v3 )
      v5 = v4 & 0xFFFFF7FF;
    else
      v5 = v4 | 0x800;
    this->m_bitField = v5;
    v6 = this->m_bitField;
    if ( !(v6 & 0x100) )
    {
      this->m_bitField = v6 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    }
  }
}

//----- (004674F0) --------------------------------------------------------  // acclient.c:164263
void __thiscall UIElement_Text::SetLoseFocusOnEscape(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x1000;
  else
    this->m_bitField = v2 & 0xFFFFEFFF;
}

//----- (00467520) --------------------------------------------------------  // acclient.c:164275
void __thiscall UIElement_Text::SetLoseFocusOnAcceptInput(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
    this->m_bitField = v2 | 0x2000;
  else
    this->m_bitField = v2 & 0xFFFFDFFF;
}

//----- (00467550) --------------------------------------------------------  // acclient.c:164287
void __thiscall UIElement_Text::ResizeToPaper(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  unsigned int v2; // eax@2
  int v3; // eax@5
  IInputActionCallbackVtbl *v4; // edx@5
  int max_width; // [sp+4h] [bp-Ch]@1
  int iPaperWidth; // [sp+8h] [bp-8h]@4
  int iPaperHeight; // [sp+Ch] [bp-4h]@4

  v1 = this;
  if ( UIElement::GetAttribute_Int((UIElement *)&this->vfptr, 0x3Du, &max_width) )
  {
    v2 = max_width;
  }
  else
  {
    v2 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
    max_width = v2;
  }
  if ( GlyphList::Recalculate(
         &v1->m_glyphList,
         v2 - v1->m_margR - v1->m_margL,
         (v1->m_bitField & 2) == 2,
         &iPaperWidth,
         &iPaperHeight) )
  {
    v3 = v1->m_margL + v1->m_margR + iPaperWidth;
    v4 = v1->vfptr;
    iPaperHeight += v1->m_margU + v1->m_margD;
    iPaperWidth = v3;
    ((void (__thiscall *)(UIElement_Text *, int, int))v4[4].__vecDelDtor)(v1, v3, iPaperHeight);
  }
}

//----- (00467600) --------------------------------------------------------  // acclient.c:164323
void __thiscall SmartArray<Glyph,1>::~SmartArray<Glyph,1>(SmartArray<Glyph,1> *this)
{
  Glyph *v1; // ecx@2
  TextTag *v2; // eax@3
  void *v3; // ebx@3
  int v4; // edx@3
  int v5; // eax@3
  Glyph *v6; // esi@3
  int v7; // edi@4

  if ( (this->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    v1 = this->m_data;
    if ( v1 )
    {
      v2 = v1[-1].m_tag;
      v3 = &v1[-1].m_tag;
      v4 = 9 * (_DWORD)v2;
      v5 = (int)((char *)&v2[-1].m_format + 3);
      v6 = &v1[4 * v4 / 0x24u];
      if ( v5 >= 0 )
      {
        v7 = v5 + 1;
        do
        {
          --v6;
          Glyph::~Glyph(v6);
          --v7;
        }
        while ( v7 );
      }
      operator delete[](v3);
    }
  }
}

//----- (00467650) --------------------------------------------------------  // acclient.c:164360
char __thiscall SmartArray<Glyph,1>::grow(SmartArray<Glyph,1> *this, unsigned int i_nSize)
{
  unsigned int v2; // ebp@1
  SmartArray<Glyph,1> *v3; // edi@1
  void *v5; // eax@5
  int v6; // ebx@6
  int v7; // eax@8
  int v8; // esi@9
  Glyph *v9; // esi@12
  TextTag *v10; // eax@13
  void *v11; // ecx@13
  int v12; // edx@13
  int v13; // eax@13
  Glyph *v14; // esi@13
  int v15; // [sp+Ch] [bp-4h]@13
  unsigned int i_nSizea; // [sp+14h] [bp+4h]@9
  unsigned int i_nSizeb; // [sp+14h] [bp+4h]@14

  v2 = i_nSize;
  v3 = this;
  if ( i_nSize >= this->m_num )
  {
    if ( i_nSize <= (this->m_sizeAndDeallocate & 0x7FFFFFFF) )
      return 1;
    if ( !i_nSize )
    {
      SmartArray<Glyph,1>::Reset(this);
      return 1;
    }
    v5 = operator new[](36 * i_nSize + 4);
    if ( v5 )
    {
      v6 = (int)((char *)v5 + 4);
      *(_DWORD *)v5 = i_nSize;
      vector_constructor_iterator((char *)v5 + 4, 0x24u, i_nSize, (void *(__thiscall *)(void *))Glyph::Glyph);
      if ( v6 )
      {
        if ( v3->m_data )
        {
          v7 = v3->m_num - 1;
          if ( v7 >= 0 )
          {
            v8 = v7;
            i_nSizea = v3->m_num;
            do
            {
              Glyph::operator=(v8 * 36 + v6, (int)&v3->m_data[v8]);
              --v8;
              --i_nSizea;
            }
            while ( i_nSizea );
          }
          if ( (v3->m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
          {
            v9 = v3->m_data;
            if ( v3->m_data )
            {
              v10 = v9[-1].m_tag;
              v11 = &v9[-1].m_tag;
              v12 = 9 * (_DWORD)v10;
              v13 = (int)((char *)&v10[-1].m_format + 3);
              v15 = (int)&v9[-1].m_tag;
              v14 = &v9[4 * v12 / 0x24u];
              if ( v13 >= 0 )
              {
                i_nSizeb = v13 + 1;
                do
                {
                  --v14;
                  Glyph::~Glyph(v14);
                  --i_nSizeb;
                }
                while ( i_nSizeb );
                v11 = (void *)v15;
              }
              operator delete[](v11);
            }
          }
        }
        v3->m_data = (Glyph *)v6;
        v3->m_sizeAndDeallocate = v2 | 0x80000000;
        return 1;
      }
    }
  }
  return 0;
}

//----- (00467760) --------------------------------------------------------  // acclient.c:164449
void __thiscall UIElement_Text::~UIElement_Text(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  Font *v2; // ecx@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&UIElement_Text::vftable;
  this->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  UIElement_Text::CleanupStringDownloads(this);
  GlyphList::Flush(&v1->m_glyphList);
  v2 = v1->m_curFontObj;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_curFontObj = 0;
  }
  if ( (v1->m_downloadQueue.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_downloadQueue.m_data);
  GlyphList::~GlyphList(&v1->m_glTruncate);
  GlyphList::~GlyphList(&v1->m_glyphList);
  UIElement_Scrollable::~UIElement_Scrollable((UIElement_Scrollable *)&v1->vfptr);
}
// 79C140: using guessed type int (__thiscall *UIElement_Text::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (004677E0) --------------------------------------------------------  // acclient.c:164475
UIElement_Text *__thiscall UIElement_Text::DynamicCast(UIElement_Text *this, unsigned int i_eType)
{
  UIElement_Text *result; // eax@1

  result = this;
  if ( i_eType != 12 )
    result = (UIElement_Text *)(i_eType != 10 ? 0 : (unsigned int)this);
  return result;
}

//----- (00467800) --------------------------------------------------------  // acclient.c:164486
char __thiscall UIElement_Text::InqAvailableProperties(UIElement_Text *this, AvailablePropertySet *_set)
{
  AvailablePropertySet *v2; // edi@1
  char v3; // bl@1
  AvailablePropertySet *v4; // esi@3
  char result; // al@4

  v2 = _set;
  v3 = 1;
  if ( !UIElement_Scrollable::InqAvailableProperties((UIElement_Scrollable *)&this->vfptr, _set) )
    v3 = 0;
  MasterPropertyGrabber::MasterPropertyGrabber((MasterPropertyGrabber *)&_set);
  v4 = _set;
  if ( _set )
  {
    if ( !MasterProperty::InqAvailablePropertiesByPropertyGroup((MasterProperty *)_set, 0x13u, v2) )
      v3 = 0;
    ((void (__thiscall *)(AvailablePropertySet *))v4->m_reqHash.vfptr[5].__vecDelDtor)(v4);
    result = v3;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00467850) --------------------------------------------------------  // acclient.c:164514
void __thiscall UIElement_Text::ClearAllText(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  unsigned int v2; // edx@1
  unsigned int v3; // ecx@2
  bool v4; // zf@2
  unsigned int v5; // ecx@5

  v1 = this;
  UIElement_Text::CleanupStringDownloads(this);
  GlyphList::Flush(&v1->m_glyphList);
  v2 = 0;
  if ( SLOBYTE(v1->m_bitField) < 0 )
  {
    v3 = v1->m_bitField & 0xFFFFFF7F;
    v4 = (v1->m_bitField & 0x40) == 0;
    v1->m_bitField = v3;
    if ( !v4 )
      v1->m_bitField = v3 & 0xFFFFFFBF;
    UIElement_Text::SetSelecting(v1, 0);
    v1->m_nSelectionStart = v2;
    v1->m_nSelectionEnd = v2;
  }
  v5 = v1->m_bitField;
  v1->m_nCursorPos = v2;
  if ( !(v5 & 0x100) )
  {
    v1->m_bitField = v5 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v1->vfptr);
  }
}

//----- (004678D0) --------------------------------------------------------  // acclient.c:164547
void __thiscall UIElement_Text::SelectAll(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@4

  v1 = this;
  v2 = this->m_bitField;
  if ( v2 & 4 )
  {
    if ( (v2 & 0x80u) == 0 )
      this->m_bitField = v2 | 0x80;
    UIElement_Text::SetSelectionStart(this, 0);
    UIElement_Text::SetSelectionEnd(v1, v1->m_glyphList.m_glyphList._num_elements);
    v3 = v1->m_bitField;
    if ( !(v3 & 0x100) )
    {
      v1->m_bitField = v3 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v1->vfptr);
    }
  }
}

//----- (00467930) --------------------------------------------------------  // acclient.c:164571
void __thiscall UIElement_Text::Deselect(UIElement_Text *this)
{
  UIElement_Text *v1; // edx@1
  unsigned int v2; // ecx@2
  bool v3; // zf@2
  unsigned int v4; // ecx@5

  v1 = this;
  if ( SLOBYTE(this->m_bitField) < 0 )
  {
    v2 = this->m_bitField & 0xFFFFFF7F;
    v3 = (v1->m_bitField & 0x40) == 0;
    v1->m_bitField = v2;
    if ( !v3 )
      v1->m_bitField = v2 & 0xFFFFFFBF;
    UIElement_Text::SetSelecting(v1, 0);
    v1->m_nSelectionStart = 0;
    v1->m_nSelectionEnd = 0;
  }
  v4 = v1->m_bitField;
  if ( !(v4 & 0x100) )
  {
    v1->m_bitField = v4 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v1->vfptr);
  }
}

//----- (004679A0) --------------------------------------------------------  // acclient.c:164599
PStringBase<unsigned short> *__thiscall UIElement_Text::GetSelectedText(UIElement_Text *this, PStringBase<unsigned short> *result)
{
  UIElement_Text *v2; // esi@1
  PSRefBufferCharData<unsigned short> *v3; // eax@3
  char *v4; // esi@3
  PStringBase<unsigned short> text; // [sp+Ch] [bp-Ch]@1
  unsigned int end; // [sp+10h] [bp-8h]@1
  unsigned int start; // [sp+14h] [bp-4h]@1

  text.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
  v2 = this;
  InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
  if ( UIElement_Text::GetSelection(v2, &start, &end) )
    GlyphList::InqText(&v2->m_glyphList, start, end, 0, &text);
  v3 = text.m_charbuffer;
  result->m_charbuffer = text.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3[-1].m_data[8]);
  v4 = (char *)&text.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&text.m_charbuffer[-1].m_data[8]) && v4 )
    (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  return result;
}

//----- (00467A30) --------------------------------------------------------  // acclient.c:164623
void __thiscall UIElement_Text::ResizeTo(UIElement_Text *this, const int _width, const int _height)
{
  UIElement_Text *v3; // esi@1
  int v4; // edi@1
  int v5; // ebx@1
  unsigned int v6; // ecx@3

  v3 = this;
  v4 = UIRegion::GetWidth((UIRegion *)&this->vfptr);
  v5 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
  UIElement_Scrollable::ResizeTo((UIElement_Scrollable *)&v3->vfptr, _width, _height);
  if ( v4 != UIRegion::GetWidth((UIRegion *)&v3->vfptr) || v5 != UIRegion::GetHeight((UIRegion *)&v3->vfptr) )
  {
    UIElement_Text::DetermineMarginValues(v3);
    v6 = v3->m_bitField;
    if ( !(v6 & 0x100) )
    {
      v3->m_bitField = v6 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v3->vfptr);
    }
  }
}

//----- (00467AA0) --------------------------------------------------------  // acclient.c:164647
void __thiscall UIElement_Text::DrawSelf(UIElement_Text *this, Box2D *i_rectObjectSelf, Box2D *i_rectObjectClip, SmartArray<Box2D,1> *i_aObjectBoxes, UISurface *_surface)
{
  UIElement_Text *v5; // esi@1
  int v6; // ecx@2
  int v7; // eax@2
  int v8; // edi@2
  int v9; // edx@2
  int v10; // edx@3
  int v11; // eax@4
  int v12; // ecx@4
  int v13; // edi@5
  int v14; // ebx@5
  int v15; // ebp@5
  int v16; // eax@5
  bool v17; // zf@6
  Font *v18; // eax@8
  int v19; // ecx@8
  int v20; // ebx@8
  int v21; // eax@9
  unsigned int v22; // eax@13
  int v23; // edi@15
  Font *v24; // eax@15
  int v25; // edi@15
  int v26; // eax@16
  int v27; // ecx@18
  bool v28; // cf@18
  int *v29; // eax@18
  int v30; // eax@20
  ListNode<Glyph> *v31; // ebx@20
  int v32; // ecx@20
  int v33; // eax@20
  int v34; // ecx@20
  unsigned int v35; // edx@20
  Font *v36; // ebp@24
  unsigned int v37; // eax@26
  int v38; // ebp@27
  unsigned int v39; // ecx@28
  unsigned int v40; // eax@29
  int v41; // eax@31
  int v42; // eax@34
  const unsigned __int16 v43; // bp@38
  unsigned int v44; // ST18_4@38
  unsigned int v45; // eax@38
  signed int v46; // ecx@39
  signed int v47; // ebp@40
  int v48; // eax@43
  const unsigned __int16 v49; // bp@47
  unsigned int v50; // ST18_4@47
  unsigned int v51; // eax@47
  unsigned int v52; // ebx@57
  unsigned int v53; // eax@59
  int v54; // eax@61
  bool v55; // sf@64
  unsigned __int8 v56; // of@64
  int v57; // edi@66
  unsigned int v58; // eax@67
  int v59; // eax@71
  int v60; // edi@71
  int v61; // ecx@71
  int v62; // ebx@71
  int v63; // edi@71
  int v64; // edi@74
  int v65; // ebx@74
  unsigned int v66; // ST18_4@74
  DiskSpace *v67; // ecx@74
  unsigned int v68; // ST14_4@74
  bool bDrawingTruncator; // [sp+13h] [bp-C1h]@20
  int yPos; // [sp+14h] [bp-C0h]@20
  bool selecting; // [sp+1Bh] [bp-B9h]@4
  int curHeight; // [sp+1Ch] [bp-B8h]@20
  int y; // [sp+20h] [bp-B4h]@5
  int ePass; // [sp+24h] [bp-B0h]@6
  int v75; // [sp+28h] [bp-ACh]@18
  unsigned int current; // [sp+2Ch] [bp-A8h]@20
  Font *font; // [sp+30h] [bp-A4h]@24
  int cursorX; // [sp+34h] [bp-A0h]@8
  unsigned int nLineNumber; // [sp+38h] [bp-9Ch]@20
  int charWidth; // [sp+3Ch] [bp-98h]@38
  Box2D clippedCursorBox; // [sp+40h] [bp-94h]@50
  int cursorY; // [sp+50h] [bp-84h]@8
  int cursorHeight; // [sp+54h] [bp-80h]@11
  Box2D cursorBox; // [sp+58h] [bp-7Ch]@4
  unsigned int selend; // [sp+68h] [bp-6Ch]@4
  unsigned int selstart; // [sp+6Ch] [bp-68h]@4
  int iObjectX0; // [sp+70h] [bp-64h]@2
  int iObjectY0; // [sp+74h] [bp-60h]@2
  Box2D rectClipBoxSize; // [sp+78h] [bp-5Ch]@5
  SurfaceWindow winDest; // [sp+88h] [bp-4Ch]@5
  Box2D selected; // [sp+B4h] [bp-20h]@50
  Box2D rectSurfaceBox; // [sp+C4h] [bp-10h]@71

  v5 = this;
  UIRegion::DrawSelf((UIRegion *)&this->vfptr, i_rectObjectSelf, i_rectObjectClip, i_aObjectBoxes, _surface);
  if ( _surface )
  {
    v6 = i_rectObjectClip->m_x0;
    v7 = i_rectObjectSelf->m_x0;
    v8 = i_rectObjectSelf->m_y0;
    v9 = i_rectObjectClip->m_x1 - i_rectObjectClip->m_x0 + 1;
    iObjectX0 = i_rectObjectSelf->m_x0;
    iObjectY0 = v8;
    if ( v9 > 0 )
    {
      v10 = i_rectObjectClip->m_y0;
      if ( i_rectObjectClip->m_y1 - v10 + 1 > 0 )
      {
        v11 = v7 - v5->m_iScrollableX - v6;
        v12 = v5->m_iScrollableY;
        cursorBox.m_x0 = v11;
        cursorBox.m_y0 = v8 - v12 - v10;
        selecting = UIElement_Text::GetSelection(v5, &selstart, &selend);
        if ( v5->m_glyphList.m_glyphLines.m_num )
        {
          v13 = i_rectObjectClip->m_x1;
          v14 = i_rectObjectClip->m_x0;
          v15 = i_rectObjectClip->m_y1;
          rectClipBoxSize.m_x0 = 0;
          rectClipBoxSize.m_y0 = 0;
          v16 = i_rectObjectClip->m_y0;
          rectClipBoxSize.m_y1 = v15 - v16;
          rectClipBoxSize.m_x1 = v13 - v14;
          y = v16;
          UISurface::PrepareSurface(_surface);
          SurfaceWindow::SurfaceWindow(&winDest, _surface->m_pLocalSurface, v14, y, v13, v15);
          if ( SurfaceWindow::Lock(&winDest, 0) )
          {
            UISurface::PrepareSurface(_surface);
            v17 = (v5->m_bitField & 0x10) == 0;
            ePass = 1;
            if ( !v17 )
              ePass = 0;
            v18 = v5->m_curFontObj;
            v19 = 0;
            v20 = 0;
            cursorX = 0;
            cursorY = 0;
            if ( v18 )
              v21 = v18->maxCharHeight;
            else
              v21 = 0;
            cursorHeight = v21;
            if ( ePass < 2 )
            {
              do
              {
                if ( v5->m_cxAdjustedLineNumber )
                  v22 = v5->m_glyphList.m_glyphLines.m_data->m_nLineWidth;
                else
                  v22 = v5->m_cxAdjustedLineSize;
                v23 = UIElement_Text::CalcJustification(v5, v22, 1);
                v24 = v5->m_curFontObj;
                v25 = cursorBox.m_x0 + v23;
                if ( v24 )
                  v26 = v24->maxCharHeight;
                else
                  v26 = 12;
                v27 = v5->m_iScrollableHeight;
                y = v26;
                v28 = v27 < (unsigned int)v26;
                v75 = v27;
                v29 = &y;
                if ( !v28 )
                  v29 = &v75;
                v30 = UIElement_Text::CalcJustification(v5, *v29, 0);
                v31 = v5->m_glyphList.m_glyphList._head;
                v32 = v30;
                v33 = v5->m_glyphList.m_glyphLines.m_data->m_nLineHeight;
                v34 = cursorBox.m_y0 + v32;
                v35 = 0;
                yPos = v34;
                nLineNumber = 0;
                current = 0;
                curHeight = v33;
                bDrawingTruncator = 0;
                if ( v31 )
                {
                  v75 = 0;
                  do
                  {
                    if ( v35 == v5->m_nTruncationPos )
                    {
                      v31 = v5->m_glTruncate.m_glyphList._head;
                      bDrawingTruncator = 1;
                    }
                    font = v31->data.m_font;
                    v36 = font;
                    if ( font )
                    {
                      if ( !bDrawingTruncator )
                      {
                        v37 = nLineNumber + 1;
                        if ( v5->m_glyphList.m_glyphLines.m_num > nLineNumber + 1 )
                        {
                          v38 = (int)((char *)&v5->m_glyphList.m_glyphLines.m_data[1] + v75);
                          if ( current >= *(unsigned int *)((char *)&v5->m_glyphList.m_glyphLines.m_data[1].m_nIndex
                                                          + v75) )
                          {
                            v75 += 16;
                            v39 = v5->m_cxAdjustedLineNumber;
                            ++nLineNumber;
                            yPos += curHeight;
                            if ( v37 == v39 )
                              v40 = v5->m_cxAdjustedLineSize;
                            else
                              v40 = *(_DWORD *)(v38 + 8);
                            v41 = UIElement_Text::CalcJustification(v5, v40, 1);
                            v25 = cursorBox.m_x0 + v41;
                            curHeight = *(_DWORD *)(v38 + 12);
                          }
                          v36 = font;
                        }
                      }
                      if ( current == v5->m_nCursorPos )
                      {
                        v42 = v36->maxCharHeight;
                        cursorX = v25;
                        cursorY = yPos;
                        cursorHeight = v42;
                      }
                      if ( !(unsigned __int8)Glyph::IsNewLine(&v31->data) )
                      {
                        if ( ePass )
                        {
                          v49 = v31->data.m_data;
                          v50 = v5->m_curOutlineColor;
                          v51 = RGBAColor::GetColor32(&v31->data.m_color);
                          charWidth = SurfaceWindow::DrawCharacter(&winDest, v25, yPos, font, v49, v51, 0x1000u, v50);
                          if ( selecting && current >= selstart && current < selend )
                          {
                            clippedCursorBox.m_x0 = 0;
                            clippedCursorBox.m_y0 = 0;
                            clippedCursorBox.m_x1 = 0;
                            clippedCursorBox.m_y1 = 0;
                            Box2D::Box2D(&selected, v25, yPos, charWidth, curHeight);
                            if ( (unsigned __int8)Box2D::Intersection(&rectClipBoxSize, &selected, &clippedCursorBox) )
                              SurfaceWindow::NotColorBits(
                                &winDest,
                                clippedCursorBox.m_x0,
                                clippedCursorBox.m_y0,
                                clippedCursorBox.m_x1 + 1,
                                clippedCursorBox.m_y1 + 1);
                          }
                        }
                        else if ( v36->m_pBackgroundSurface )
                        {
                          v43 = v31->data.m_data;
                          v44 = v5->m_curOutlineColor;
                          v45 = RGBAColor::GetColor32(&v31->data.m_color);
                          charWidth = SurfaceWindow::DrawCharacter(&winDest, v25, yPos, font, v43, v45, 0x7000u, v44);
                        }
                        else
                        {
                          v46 = -1;
                          y = -1;
                          do
                          {
                            v47 = -1;
                            do
                            {
                              if ( v47 || v46 )
                              {
                                v48 = SurfaceWindow::DrawCharacter(
                                        &winDest,
                                        v25 + v47,
                                        yPos + v46,
                                        font,
                                        v31->data.m_data,
                                        v5->m_curOutlineColor,
                                        0x9000u,
                                        0xFF000000);
                                v46 = y;
                                charWidth = v48;
                              }
                              ++v47;
                            }
                            while ( v47 <= 1 );
                            ++v46;
                            y = v46;
                          }
                          while ( v46 <= 1 );
                        }
                        v25 += charWidth;
                      }
                    }
                    v31 = v31->next;
                    v35 = current++ + 1;
                  }
                  while ( v31 );
                  v34 = yPos;
                }
                if ( v35 == v5->m_nCursorPos )
                {
                  if ( v5->m_glyphList.m_glyphLines.m_num > nLineNumber + 1 )
                  {
                    v52 = (unsigned int)&v5->m_glyphList.m_glyphLines.m_data[nLineNumber + 1];
                    if ( v35 >= *(_DWORD *)(v52 + 4) )
                    {
                      yPos = curHeight + v34;
                      if ( nLineNumber + 1 == v5->m_cxAdjustedLineNumber )
                        v53 = v5->m_cxAdjustedLineSize;
                      else
                        v53 = *(_DWORD *)(v52 + 8);
                      v54 = UIElement_Text::CalcJustification(v5, v53, 1);
                      v25 = cursorBox.m_x0 + v54;
                      curHeight = *(_DWORD *)(v52 + 12);
                    }
                  }
                  cursorY = yPos;
                  cursorX = v25;
                  if ( curHeight )
                    cursorHeight = curHeight;
                }
                v56 = __OFSUB__(ePass + 1, 2);
                v55 = ePass++ - 1 < 0;
              }
              while ( v55 ^ v56 );
              v20 = cursorY;
              v19 = cursorX;
            }
            cursorBox.m_x0 = v19;
            cursorBox.m_x1 = v19;
            v57 = cursorHeight + v20 - 1;
            cursorBox.m_y0 = v20;
            cursorBox.m_y1 = cursorHeight + v20 - 1;
            if ( UIElement::GetHasFocus((UIElement *)&v5->vfptr) )
            {
              v58 = v5->m_bitField;
              if ( v58 & 1 )
              {
                if ( BYTE1(v58) & 2 )
                {
                  clippedCursorBox.m_x0 = 0;
                  clippedCursorBox.m_y0 = 0;
                  clippedCursorBox.m_x1 = 0;
                  clippedCursorBox.m_y1 = 0;
                  if ( (unsigned __int8)Box2D::Intersection(&rectClipBoxSize, &cursorBox, &clippedCursorBox) )
                    SurfaceWindow::FillArea(
                      &winDest,
                      &v5->m_curFontColor,
                      clippedCursorBox.m_x0,
                      clippedCursorBox.m_y0,
                      clippedCursorBox.m_x1,
                      clippedCursorBox.m_y1);
                }
              }
            }
            v5->vfptr[4].OnAction((IInputActionCallback *)v5, (InputEvent *)&rectSurfaceBox);
            v59 = v20 + i_rectObjectClip->m_y0 + rectSurfaceBox.m_y0 - iObjectY0;
            v60 = v57 - v20;
            v61 = cursorX + rectSurfaceBox.m_x0 + i_rectObjectClip->m_x0 - iObjectX0;
            v62 = (int)&v5->m_lastCursor.m_x0;
            v63 = v59 + v60;
            if ( &v5->m_lastCursor != &selected )
            {
              *(_DWORD *)v62 = v61;
              v5->m_lastCursor.m_x1 = v61;
              v5->m_lastCursor.m_y0 = v59;
              v5->m_lastCursor.m_y1 = v63;
            }
            if ( UIElement::GetHasFocus((UIElement *)&v5->vfptr) )
            {
              v64 = v5->m_lastCursor.m_y0;
              v65 = *(_DWORD *)v62;
              v66 = v64 + UIRegion::GetScreenY0((UIRegion *)&v5->vfptr);
              v68 = v65 + UIRegion::GetScreenX0((UIRegion *)&v5->vfptr);
              gmNoticeHandler::RecvNotice_PrevSpellSelection(v67);
            }
            SurfaceWindow::Unlock(&winDest);
          }
          winDest.vfptr = (SurfaceWindowVtbl *)SurfaceWindow::vftable;
          SurfaceWindow::End(&winDest);
        }
      }
    }
  }
}
// 798D14: using guessed type int (__thiscall *SurfaceWindow::vftable[2])(void *, char);

//----- (004680D0) --------------------------------------------------------  // acclient.c:165026
void __thiscall UIElement_Text::SetEditable(UIElement_Text *this, bool _editable)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // eax@6
  unsigned int v4; // edx@7
  bool v5; // zf@7
  unsigned int v6; // eax@9

  v2 = this;
  if ( _editable != ((this->m_bitField & 1) == 1) )
  {
    if ( _editable )
    {
      v3 = this->m_bitField;
      if ( BYTE1(v3) & 8 )
      {
        v4 = this->m_bitField & 0xFFFFF7FF;
        v5 = (this->m_bitField & 0x100) == 0;
        this->m_bitField = v4;
        if ( v5 )
        {
          this->m_bitField = v4 | 0x100;
          UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
        }
      }
    }
    else if ( UIElement::GetHasFocus((UIElement *)&this->vfptr) && !(v2->m_bitField & 4) )
    {
      ((void (__thiscall *)(UIElement_Text *))v2->vfptr[22].__vecDelDtor)(v2);
    }
    v6 = v2->m_bitField;
    if ( _editable )
      v2->m_bitField = v6 | 1;
    else
      v2->m_bitField = v6 & 0xFFFFFFFE;
  }
}

//----- (00468170) --------------------------------------------------------  // acclient.c:165065
void __thiscall UIElement_Text::SetOneLine(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@2
  unsigned int v3; // eax@3
  unsigned int v4; // edx@5

  if ( _b != ((this->m_bitField & 2) == 2) )
  {
    v2 = this->m_bitField;
    if ( _b )
      v3 = v2 | 2;
    else
      v3 = v2 & 0xFFFFFFFD;
    this->m_bitField = v3;
    v4 = this->m_bitField;
    if ( !(v4 & 0x100) )
    {
      this->m_bitField = v4 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
    }
  }
}

//----- (004681C0) --------------------------------------------------------  // acclient.c:165089
void __thiscall UIElement_Text::SetSelectable(UIElement_Text *this, bool _b)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // eax@6
  unsigned int v4; // edx@7
  bool v5; // zf@7
  unsigned int v6; // eax@9
  unsigned int v7; // eax@10
  unsigned int v8; // edx@15

  v2 = this;
  if ( _b != ((this->m_bitField & 4) == 4) )
  {
    if ( _b )
    {
      v3 = this->m_bitField;
      if ( BYTE1(v3) & 8 )
      {
        v4 = this->m_bitField & 0xFFFFF7FF;
        v5 = (this->m_bitField & 0x100) == 0;
        this->m_bitField = v4;
        if ( v5 )
        {
          this->m_bitField = v4 | 0x100;
          UIRegion::MakeRootDirtyHere((UIRegion *)&this->vfptr);
        }
      }
    }
    else if ( UIElement::GetHasFocus((UIElement *)&this->vfptr) && !(v2->m_bitField & 1) )
    {
      ((void (__thiscall *)(UIElement_Text *))v2->vfptr[22].__vecDelDtor)(v2);
    }
    v6 = v2->m_bitField;
    if ( _b )
      v7 = v6 | 4;
    else
      v7 = v6 & 0xFFFFFFFB;
    v2->m_bitField = v7;
    if ( (v7 & 0x80u) != 0 )
    {
      v2->m_bitField = v7 & 0xFFFFFF7F;
      if ( v7 & 0x40 )
        v2->m_bitField = v7 & 0xFFFFFF3F;
      UIElement_Text::SetSelecting(v2, 0);
      v2->m_nSelectionStart = v8;
      v2->m_nSelectionEnd = v8;
    }
  }
}

//----- (00468290) --------------------------------------------------------  // acclient.c:165140
void __thiscall UIElement_Text::SetFontDIDNum(UIElement_Text *this, unsigned int _fontDIDNum)
{
  UIElement_Text::SetFontDIDHelper(this, 0x1Au, &this->m_curFontObj, _fontDIDNum);
}

//----- (004682B0) --------------------------------------------------------  // acclient.c:165146
void __thiscall UIElement_Text::SetFontColorNum(UIElement_Text *this, unsigned int _fontColorNum)
{
  UIElement_Text *v2; // esi@1

  v2 = this;
  UIElement_Text::SetFontColorHelper(this, 0x1Bu, &this->m_curFontColor, _fontColorNum);
  UIElement_Text::SetFontColorHelper(v2, 0x1Du, &v2->m_curTagFontColor, _fontColorNum);
}

//----- (004682E0) --------------------------------------------------------  // acclient.c:165156
char __thiscall UIElement_Text::MoveUpDown(UIElement_Text *this, bool i_bUp, unsigned int i_nStart, unsigned int *o_nPos)
{
  unsigned int v4; // ebp@1
  UIElement_Text *v5; // edi@1
  GlyphList *v6; // esi@1
  char v7; // bl@4
  char v8; // al@6
  int v10; // eax@11
  int v11; // eax@11
  unsigned int nCurrentLine; // [sp+10h] [bp-14h]@1
  unsigned int nNewLine; // [sp+14h] [bp-10h]@5
  unsigned int nNewPos; // [sp+18h] [bp-Ch]@5
  int nNewLineWidth; // [sp+1Ch] [bp-8h]@11
  unsigned int nStartPosition; // [sp+20h] [bp-4h]@1

  v4 = i_nStart;
  v5 = this;
  v6 = &this->m_glyphList;
  nCurrentLine = 0;
  nStartPosition = 0;
  if ( !GlyphList::FindCurrentLine(&this->m_glyphList, i_nStart, &nCurrentLine, &nStartPosition) )
    goto LABEL_4;
  if ( !i_bUp )
  {
    if ( nCurrentLine != v5->m_glyphList.m_glyphLines.m_num - 1 )
      goto LABEL_4;
LABEL_8:
    *o_nPos = v4;
    return 1;
  }
  if ( !nCurrentLine )
    goto LABEL_8;
LABEL_4:
  v7 = 0;
  i_nStart = 0;
  if ( GlyphList::FindPixelsFromPos(v6, v4, (int *)&i_nStart) )
  {
    nNewLine = 0;
    nNewPos = 0;
    if ( i_bUp )
      v8 = GlyphList::FindPrevLine(v6, v4, &nNewLine, &nNewPos);
    else
      v8 = GlyphList::FindNextLine(v6, v4, &nNewLine, &nNewPos);
    v7 = v8;
    if ( v8 )
    {
      *(_DWORD *)&i_bUp = 0;
      GlyphList::GetGlyphLineWidth(v6, nCurrentLine, (int *)&i_bUp);
      v10 = UIElement_Text::CalcJustification(v5, i_bUp, 1);
      i_nStart += v10;
      nNewLineWidth = 0;
      GlyphList::GetGlyphLineWidth(v6, nNewLine, &nNewLineWidth);
      v11 = UIElement_Text::CalcJustification(v5, nNewLineWidth, 1);
      i_nStart -= v11;
      v7 = GlyphList::FindPosFromLineAndPixels(v6, nNewLine, i_nStart, 1, o_nPos);
    }
  }
  return v7;
}

//----- (00468420) --------------------------------------------------------  // acclient.c:165217
char __thiscall UIElement_Text::RecalculateGlyphList(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  unsigned int v2; // ecx@1
  char result; // al@1
  char v4; // bl@2
  int v5; // edx@2
  unsigned int v6; // eax@2
  unsigned int v7; // eax@5
  int iPaperHeight; // [sp+8h] [bp-18h]@2
  int iPaperWidth; // [sp+Ch] [bp-14h]@2
  Box2D surfBox; // [sp+10h] [bp-10h]@2

  v1 = this;
  v2 = this->m_bitField;
  result = 0;
  if ( BYTE1(v2) & 1 )
  {
    iPaperWidth = 0;
    iPaperHeight = 0;
    v1->vfptr[4].OnAction((IInputActionCallback *)v1, (InputEvent *)&surfBox);
    v4 = GlyphList::Recalculate(
           &v1->m_glyphList,
           surfBox.m_x1 - v1->m_margR - v1->m_margL - surfBox.m_x0 + 1,
           (v1->m_bitField & 2) == 2,
           &iPaperWidth,
           &iPaperHeight);
    v5 = v1->m_margU;
    iPaperWidth += v1->m_margL + v1->m_margR;
    v6 = v1->m_bitField;
    iPaperHeight += v5 + v1->m_margD;
    if ( BYTE1(v6) & 8 )
    {
      UIElement_Text::RecalculateTruncation(v1, &iPaperWidth, &iPaperHeight);
    }
    else
    {
      v1->m_nTruncationPos = -1;
      v1->m_cxAdjustedLineNumber = -1;
    }
    UIElement_Scrollable::ResizeScrollableArea((UIElement_Scrollable *)&v1->vfptr, iPaperWidth, iPaperHeight);
    UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&v1->vfptr, v1->m_iScrollableX, v1->m_iScrollableY, 1);
    v7 = v1->m_bitField;
    if ( BYTE1(v7) & 1 )
      v1->m_bitField = v7 & 0xFFFFFEFF;
    result = v4;
  }
  return result;
}

//----- (00468540) --------------------------------------------------------  // acclient.c:165268
void __thiscall UIElement_Text::SetFitToText(UIElement_Text *this, bool _b)
{
  unsigned int v2; // eax@1

  v2 = this->m_bitField;
  if ( _b )
  {
    this->m_bitField = v2 | 0x400;
    UIElement_Text::ResizeToPaper(this);
  }
  else
  {
    this->m_bitField = v2 & 0xFFFFFBFF;
  }
}

//----- (00468570) --------------------------------------------------------  // acclient.c:165285
void __userpurge UIElement_Text::UIElement_Text(UIElement_Text *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Text *v4; // esi@1
  unsigned int v5; // ebx@1
  unsigned __int64 v6; // rax@1
  int v7; // eax@1

  v4 = this;
  UIElement_Scrollable::UIElement_Scrollable((UIElement_Scrollable *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (CInputHandlerVtbl *)&CInputHandler::vftable;
  v4->vfptr = (IInputActionCallbackVtbl *)&UIElement_Text::vftable;
  v4->vfptr = (CInputHandlerVtbl *)&UIOption_Menu::vftable;
  GlyphList::GlyphList(&v4->m_glyphList);
  v4->m_nCursorPos = 0;
  v4->m_nSelectionStart = 0;
  v4->m_nSelectionEnd = 0;
  GlyphList::GlyphList(&v4->m_glTruncate);
  v4->m_nTruncationPos = -1;
  v4->m_cxAdjustedLineNumber = -1;
  v4->m_cxTrailer = 0;
  v4->m_cyTrailer = 0;
  v4->m_cxAdjustedLineSize = 0;
  v4->m_bitField = 768;
  v4->m_eHorizontalJustification = 2;
  v4->m_eVerticalJustification = 4;
  v4->m_filter = 0;
  v4->m_curFontColor = RGBAColor_White_36;
  v4->m_curFontObj = 0;
  v4->m_curTagFontColor = RGBAColor_White_36;
  v5 = ((unsigned int)(unsigned __int64)(RGBAColor_Black_37.g * 255.0) | (((unsigned int)(unsigned __int64)(RGBAColor_Black_37.r * 255.0) | ((unsigned int)(unsigned __int64)(RGBAColor_Black_37.a * 255.0) << 8)) << 8)) << 8;
  v6 = (unsigned __int64)(RGBAColor_Black_37.b * 255.0);
  LODWORD(v4->m_lastCursorMoveTime) = LODWORD(INVALID_TIME_6);
  v4->m_curOutlineColor = v6 | v5;
  v4->m_margU = 0;
  v4->m_margD = 0;
  v4->m_margL = 0;
  v4->m_margR = 0;
  HIDWORD(v4->m_lastCursorMoveTime) = HIDWORD(INVALID_TIME_6);
  v4->m_lastFlashFlipTime = INVALID_TIME_6;
  v4->m_lastCursor.m_x0 = 0;
  v4->m_lastCursor.m_y0 = 0;
  v4->m_lastCursor.m_x1 = 0;
  v4->m_lastCursor.m_y1 = 0;
  v4->m_downloadQueue.m_data = 0;
  v4->m_downloadQueue.m_sizeAndDeallocate = 0;
  v4->m_downloadQueue.m_num = 0;
  v7 = DBObj::GetByEnum(24, 9, 0x2Eu);
  v4->m_curFontObj = (Font *)v7;
  if ( !v7 )
    v4->m_curFontObj = (Font *)DBObj::GetByEnum(3, 9, 0x2Eu);
  UIElement_Text::DetermineMarginValues(v4);
  UIElement_Text::ClearAllText(v4);
}
// 79BA88: using guessed type void (__thiscall *CInputHandler::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);
// 79C140: using guessed type int (__thiscall *UIElement_Text::vftable)(void *, char);
// 7C126C: using guessed type void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *);

//----- (00468770) --------------------------------------------------------  // acclient.c:165343
UIElement_Text *__thiscall UIElement_Text::vector_deleting_destructor(UIElement_Text *this, unsigned int a2)
{
  UIElement_Text *v2; // esi@1

  v2 = this;
  UIElement_Text::~UIElement_Text(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (00468790) --------------------------------------------------------  // acclient.c:165355
void __usercall UIElement_Text::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  UIElement_Text *v3; // eax@1

  v3 = (UIElement_Text *)operator new(0x710u);
  if ( v3 )
    UIElement_Text::UIElement_Text(v3, a1, _layout, _full_desc);
}

//----- (004687C0) --------------------------------------------------------  // acclient.c:165365
int __thiscall UIElement_Text::ListenToElementMessage(UIElement_Text *this, UIElementMessageInfo *i_rMsg)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // ecx@3
  ICIDMVtbl *v4; // eax@6
  int v6; // [sp-8h] [bp-10h]@6

  v2 = this;
  if ( (UIElement_Text *)i_rMsg->pElement == this && i_rMsg->idMessage == 47 )
  {
    v3 = this->m_bitField;
    if ( v2->m_bitField & 1 || v3 & 4 )
    {
      if ( (v2->m_bitField & 1) == 1 )
      {
        v4 = ICIDM::s_cidm->vfptr;
        v6 = (int)&v2->vfptr;
        if ( i_rMsg->dwParam1 )
        {
          ((void (__stdcall *)(int, signed int))v4->RegisterInputHandler)(v6, 2);
          UIElement_Text::IMETurnOn(v2);
          KeyStone::LoseFocus();
        }
        else
        {
          ((void (__stdcall *)(int, signed int))v4->UnregisterInputHandler)(v6, 2);
          DBObj::InitLoad();
        }
      }
      if ( i_rMsg->dwParam1 )
      {
        ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->SetTextMode)(1);
        UIListener::RegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
        return UIElement_Scrollable::ListenToElementMessage((UIElement_Scrollable *)&v2->vfptr, i_rMsg);
      }
      UIElement_Text::Deselect(v2);
      ((void (__stdcall *)(_DWORD))ICIDM::s_cidm->vfptr->SetTextMode)(0);
      UIListener::UnRegisterForGlobalMessage((UIListener *)&v2->vfptr, 3u);
    }
  }
  return UIElement_Scrollable::ListenToElementMessage((UIElement_Scrollable *)&v2->vfptr, i_rMsg);
}

//----- (004688A0) --------------------------------------------------------  // acclient.c:165409
void __thiscall UIElement_Text::Copy(UIElement_Text *this)
{
  PSRefBufferCharData<unsigned short> *v1; // esi@2
  PSRefBufferCharData<unsigned short> *v2; // ecx@2
  int v3; // esi@2
  int v4; // edx@4
  PStringBase<unsigned short> v5; // [sp-8h] [bp-Ch]@2
  PStringBase<unsigned short> cpy; // [sp+0h] [bp-4h]@1

  cpy.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  if ( SLOBYTE(this->m_bitField) < 0 )
  {
    UIElement_Text::GetSelectedText(this, &cpy);
    v1 = cpy.m_charbuffer;
    v5.m_charbuffer = v2;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v5, cpy.m_charbuffer->m_data);
    Device::SendStringToClipboard(v5);
    v3 = (int)&v1[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
      {
        v4 = *(_DWORD *)v3;
        v5.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(int, signed int))v4)(v3, 1);
      }
    }
  }
}

//----- (004688F0) --------------------------------------------------------  // acclient.c:165440
unsigned int __thiscall UIElement_Text::DeterminePositionFromXY(UIElement_Text *this, int i_x, int i_y)
{
  UIElement_Text *v3; // esi@1
  int v4; // ebx@1
  int v5; // ST08_4@1
  int v6; // eax@1
  void *v7; // eax@2
  unsigned int result; // eax@4
  unsigned int nPos; // [sp+Ch] [bp-Ch]@1
  unsigned int nLine; // [sp+10h] [bp-8h]@1
  int nLineWidth; // [sp+14h] [bp-4h]@1

  v3 = this;
  UIElement_Text::RecalculateGlyphList(this);
  v4 = v3->m_iScrollableX;
  v5 = i_y + v3->m_iScrollableY;
  nLine = 0;
  nLineWidth = 0;
  GlyphList::FindLineFromY(&v3->m_glyphList, v5, &nLine);
  GlyphList::GetGlyphLineWidth(&v3->m_glyphList, nLine, &nLineWidth);
  v6 = UIElement_Text::CalcJustification(v3, nLineWidth, 1);
  nPos = 0;
  if ( GlyphList::FindPosFromLineAndPixels(&v3->m_glyphList, nLine, v4 + i_x - v6, 1, &nPos) )
  {
    i_y = v3->m_glyphList.m_glyphList._num_elements;
    v7 = &i_y;
    if ( i_y >= nPos )
      v7 = &nPos;
    result = *(_DWORD *)v7;
  }
  else
  {
    result = nPos;
  }
  return result;
}

//----- (004689B0) --------------------------------------------------------  // acclient.c:165478
int __thiscall UIElement_Text::InqScrollDelta(UIElement_Text *this, bool i_bHorizontal, bool i_bIncrement, bool i_bPage)
{
  int v4; // edi@1
  UIElement_Text *v5; // esi@1
  unsigned int v6; // eax@1
  bool v7; // al@1
  bool v8; // bl@1
  char v9; // al@3
  int v10; // eax@7
  bool v11; // sf@9
  unsigned __int8 v12; // of@9
  int *v13; // eax@9
  int v14; // eax@14
  int v15; // eax@16
  void *v16; // eax@16
  unsigned int nCurrentLine; // [sp+10h] [bp-Ch]@1
  int iDelta; // [sp+14h] [bp-8h]@1
  unsigned int nCurrentPos; // [sp+18h] [bp-4h]@1

  v4 = 0;
  v5 = this;
  iDelta = 0;
  v6 = UIElement_Text::DeterminePositionFromXY(this, 0, 0);
  nCurrentLine = 0;
  nCurrentPos = 0;
  v7 = GlyphList::FindCurrentLine(&v5->m_glyphList, v6, &nCurrentLine, &nCurrentPos);
  v8 = i_bHorizontal;
  if ( v7 )
  {
    *(_DWORD *)&i_bHorizontal = 0;
    v9 = v8 ? GlyphList::GetGlyphLineWidth(&v5->m_glyphList, nCurrentLine, (int *)&i_bHorizontal) : GlyphList::GetGlyphLineHeight(&v5->m_glyphList, nCurrentLine, (int *)&i_bHorizontal);
    if ( v9 )
    {
      if ( v8 )
        v10 = UIRegion::GetWidth((UIRegion *)&v5->vfptr);
      else
        v10 = UIRegion::GetHeight((UIRegion *)&v5->vfptr);
      iDelta = v10;
      v12 = __OFSUB__(i_bHorizontal, v10);
      v11 = i_bHorizontal - v10 < 0;
      v13 = (int *)&i_bHorizontal;
      if ( !(v11 ^ v12) )
        v13 = &iDelta;
      v4 = *v13;
      iDelta = *v13;
    }
  }
  if ( i_bPage )
  {
    if ( v8 )
      v14 = UIRegion::GetWidth((UIRegion *)&v5->vfptr);
    else
      v14 = UIRegion::GetHeight((UIRegion *)&v5->vfptr);
    v15 = v14 - v4;
    *(_DWORD *)&i_bHorizontal = v15;
    v12 = __OFSUB__(v15, v4);
    v11 = v15 - v4 < 0;
    v16 = &iDelta;
    if ( !(v11 ^ v12) )
      v16 = &i_bHorizontal;
    v4 = *(_DWORD *)v16;
  }
  if ( i_bIncrement )
    v4 = -v4;
  return v4;
}

//----- (00468A90) --------------------------------------------------------  // acclient.c:165546
void __cdecl UIElement_Text::Register()
{
  UIElement::RegisterElementClass(0xCu, (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))UIElement_Text::Create);
}

//----- (00468AA0) --------------------------------------------------------  // acclient.c:165552
bool __thiscall UIElement_Text::IsPositionInView(UIElement_Text *this, const int *_nPos)
{
  unsigned int v2; // edi@1
  UIElement_Text *v3; // esi@1
  int v4; // eax@3
  int v5; // ecx@3
  int v6; // edi@3
  int v7; // esi@3
  int v8; // eax@3
  bool result; // al@5
  int v10; // eax@6
  Font *v11; // ecx@6
  int v12; // eax@6
  const int *v13; // ecx@7
  bool v14; // sf@9
  unsigned __int8 v15; // of@9
  void *v16; // ecx@9
  int v17; // esi@11
  int v18; // ecx@11
  int x; // [sp+Ch] [bp-Ch]@1
  int y; // [sp+10h] [bp-8h]@1
  int nVisibleHeight; // [sp+14h] [bp-4h]@6

  v2 = *_nPos;
  v3 = this;
  x = 0;
  y = 0;
  UIElement_Text::RecalculateGlyphList(this);
  if ( GlyphList::FindXYFromPosition(&v3->m_glyphList, v2, &x, &y) )
  {
    if ( v3->m_bitField & 2 )
    {
      v4 = UIRegion::GetWidth((UIRegion *)&v3->vfptr);
      v5 = v3->m_margR;
      v6 = v3->m_margL;
      v7 = v3->m_iScrollableX;
      v8 = v4 - v5 - v6;
      if ( x >= v7 && x + 2 <= v8 + v7 )
        return 1;
    }
    else
    {
      v10 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
      v11 = v3->m_curFontObj;
      v12 = v10 - v3->m_margD - v3->m_margU;
      nVisibleHeight = v12;
      if ( v11 )
        v13 = (const int *)v11->maxCharHeight;
      else
        v13 = 0;
      _nPos = v13;
      v15 = __OFSUB__(v13, v12);
      v14 = (signed int)((char *)v13 - v12) < 0;
      v16 = &_nPos;
      if ( !(v14 ^ v15) )
        v16 = &nVisibleHeight;
      v17 = v3->m_iScrollableY;
      v18 = *(_DWORD *)v16;
      if ( y >= v17 && y + v18 <= v12 + v17 )
        return 1;
    }
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00468B90) --------------------------------------------------------  // acclient.c:165623
char __thiscall UIElement_Text::SetCursorPosition(UIElement_Text *this, unsigned int i_nPos, UIElement_Text::CursorMovementFlags i_selMode)
{
  UIElement_Text *v3; // esi@1
  char v4; // al@2
  unsigned int v5; // ecx@5
  unsigned int v6; // eax@8
  unsigned int v7; // eax@13
  UIElement_Text::CursorMovementFlags *v8; // edi@13
  bool v9; // cf@13
  UIElement_Text::CursorMovementFlags *v10; // eax@13
  bool v11; // bl@17
  unsigned int v12; // edx@23
  char v13; // al@23
  unsigned int v14; // eax@26

  v3 = this;
  if ( ICIDM::s_cidm )
    v4 = ((int (*)(void))ICIDM::s_cidm->vfptr->ShiftKeyDown)();
  else
    v4 = 0;
  if ( i_selMode == 1 || ((v5 = v3->m_bitField, v5 & 0x40) || v4) && i_selMode == ctm_Default )
  {
    v6 = v3->m_bitField;
    if ( (v6 & 0x80u) == 0 && v6 & 4 )
    {
      v3->m_bitField = v6 | 0x80;
      UIElement_Text::SetSelectionStart(v3, v3->m_nCursorPos);
    }
  }
  else if ( (v5 & 0x80u) != 0 )
  {
    UIElement_Text::SetSelecting(v3, 0);
  }
  v7 = v3->m_glyphList.m_glyphList._num_elements;
  v8 = (UIElement_Text::CursorMovementFlags *)&v3->m_nCursorPos;
  i_selMode = v7;
  v9 = v7 < i_nPos;
  v3->m_nCursorPos = i_nPos;
  v10 = &i_selMode;
  if ( !v9 )
    v10 = (UIElement_Text::CursorMovementFlags *)&v3->m_nCursorPos;
  *v8 = *v10;
  v11 = UIElement_Scrollable::GetScrollbarPointer_((UIElement_Scrollable *)&v3->vfptr, 1)
     || UIElement_Scrollable::GetScrollbarPointer_((UIElement_Scrollable *)&v3->vfptr, 0);
  i_selMode = *v8;
  if ( !UIElement_Text::IsPositionInView(v3, (const int *)&i_selMode) && (v11 || v3->m_bitField & 5) )
    UIElement_Text::ScrollToPosition(v3, *v8);
  v12 = Timer::cur_time.Param;
  v13 = LOBYTE(v3->m_bitField);
  LODWORD(v3->m_lastCursorMoveTime) = Timer::cur_time.Cmd;
  HIDWORD(v3->m_lastCursorMoveTime) = v12;
  if ( v13 < 0 )
    UIElement_Text::SetSelectionEnd(v3, *v8);
  if ( UIElement::GetHasFocus((UIElement *)&v3->vfptr) )
  {
    v14 = v3->m_bitField;
    if ( v14 & 1 )
    {
      if ( !(BYTE1(v14) & 1) )
      {
        v3->m_bitField = v14 | 0x100;
        UIRegion::MakeRootDirtyHere((UIRegion *)&v3->vfptr);
      }
    }
  }
  return 1;
}

//----- (00468CD0) --------------------------------------------------------  // acclient.c:165692
char __thiscall UIElement_Text::SetCursorPositionFromXY(UIElement_Text *this, int i_x, int i_y, UIElement_Text::CursorMovementFlags i_selMode)
{
  UIElement_Text *v4; // esi@1
  unsigned int v5; // eax@1

  v4 = this;
  v5 = UIElement_Text::DeterminePositionFromXY(this, i_x, i_y);
  return UIElement_Text::SetCursorPosition(v4, v5, i_selMode);
}

//----- (00468D00) --------------------------------------------------------  // acclient.c:165703
char __thiscall UIElement_Text::MoveCursor(UIElement_Text *this, TextDefs::Direction _dir)
{
  UIElement_Text *v2; // esi@1
  unsigned int v3; // eax@1
  char result; // al@2
  unsigned int nPos; // [sp+0h] [bp-4h]@1

  nPos = (unsigned int)this;
  v2 = this;
  v3 = this->m_nCursorPos;
  nPos = this->m_nCursorPos;
  switch ( _dir )
  {
    case 0:
      goto $L127508;
    case 1:
      return UIElement_Text::SetCursorPosition(this, this->m_glyphList.m_glyphList._num_elements, 0);
    case 2:
      result = UIElement_Text::MoveBeginEndLine(this, 1, v3, &nPos);
      goto LABEL_15;
    case 3:
      result = UIElement_Text::MoveBeginEndLine(this, 0, v3, &nPos);
      goto LABEL_15;
    case 4:
      UIElement_Text::ScrollPage(this, 1);
      goto LABEL_8;
    case 5:
      UIElement_Text::ScrollPage(this, 0);
LABEL_8:
      nPos = UIElement_Text::DeterminePositionFromXY(v2, 0, 0);
      return UIElement_Text::SetCursorPosition(v2, nPos, 0);
    case 6:
      result = GlyphList::FindPrevWord(&this->m_glyphList, v3, &nPos);
      goto LABEL_15;
    case 7:
      result = GlyphList::FindNextWord(&this->m_glyphList, v3, &nPos);
      goto LABEL_15;
    case 8:
      if ( v3 )
      {
        nPos = v3 - 1;
        result = UIElement_Text::SetCursorPosition(this, v3 - 1, 0);
      }
      else
      {
$L127508:
        nPos = 0;
        result = UIElement_Text::SetCursorPosition(this, 0, 0);
      }
      return result;
    case 9:
      nPos = v3 + 1;
      return UIElement_Text::SetCursorPosition(this, v3 + 1, 0);
    case 10:
      result = UIElement_Text::MoveUpDown(this, 1, v3, &nPos);
      goto LABEL_15;
    case 11:
      result = UIElement_Text::MoveUpDown(this, 0, v3, &nPos);
LABEL_15:
      if ( result )
        result = UIElement_Text::SetCursorPosition(v2, nPos, 0);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00468E70) --------------------------------------------------------  // acclient.c:165773
void __thiscall UIElement_Text::MoveCursorToEnd(UIElement_Text *this)
{
  UIElement_Text::SetCursorPosition(this, this->m_glyphList.m_glyphList._num_elements, 0);
}

//----- (00468E90) --------------------------------------------------------  // acclient.c:165779
void __thiscall UIElement_Text::MoveCursorToPosition(UIElement_Text *this, int i_nPos)
{
  UIElement_Text::SetCursorPosition(this, i_nPos, 0);
}

//----- (00468EA0) --------------------------------------------------------  // acclient.c:165785
char __thiscall UIElement_Text::InqGlyphs(UIElement_Text *this, PStringBase<unsigned short> *_text, SmartArray<Glyph,1> *_glyphs)
{
  PStringBase<unsigned short> *v3; // eax@1
  TextTag *v4; // ebx@1
  unsigned int v5; // edi@1
  int v6; // edx@1
  PSRefBufferCharData<unsigned short> *v7; // eax@2
  unsigned int v8; // ecx@2
  int v9; // eax@3
  PSRefBufferCharData<unsigned short> *v10; // eax@6
  unsigned int v11; // ecx@6
  unsigned int v12; // ebp@6
  int v13; // eax@8
  __int16 v14; // bx@10
  unsigned int v15; // edi@11
  int v16; // ecx@11
  char *v17; // esi@14
  TextTag *v18; // esi@21
  PSRefBufferCharData<unsigned short> *v19; // ST0C_4@22
  unsigned int v20; // edx@26
  char *v21; // esi@28
  UIElement_Text *v22; // esi@34
  int v23; // edx@34
  PSRefBufferCharData<unsigned short> *v24; // eax@36
  unsigned int v25; // ecx@36
  int v26; // eax@37
  SmartArray<Glyph,1> *v27; // ecx@39
  unsigned int v28; // eax@39
  unsigned int v29; // edx@40
  int v35; // edx@50
  char *v37; // esi@52
  PStringBase<unsigned short> tag_txt; // [sp+10h] [bp-38h]@6
  TextTag *curTag; // [sp+14h] [bp-34h]@1
  UIElement_Text *v40; // [sp+18h] [bp-30h]@1
  unsigned int index; // [sp+1Ch] [bp-2Ch]@1
  wchar_t Source[2]; // [sp+20h] [bp-28h]@10
  Glyph newGlyph; // [sp+24h] [bp-24h]@39

  v3 = _text;
  v40 = this;
  v4 = 0;
  v5 = 0;
  v6 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14] - 1;
  curTag = 0;
  index = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = v3->m_charbuffer;
      v8 = *(_DWORD *)&v7[-1].m_data[14];
      if ( v5 < v8 )
        v9 = (int)((char *)v7 + 2 * v5);
      else
        v9 = (int)((char *)v7 + 2 * v8 - 2);
      if ( *(_WORD *)v9 != 60 )
        goto LABEL_32;
      tag_txt.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
      InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
      v10 = _text->m_charbuffer;
      v11 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14];
      v12 = v5;
      if ( v5 < v11 - 1 )
      {
        while ( 1 )
        {
          if ( v12 < v11 )
            v13 = (int)((char *)v10 + 2 * v12);
          else
            v13 = (int)((char *)v10 + 2 * v11 - 2);
          v14 = *(_WORD *)v13;
          *(_DWORD *)Source = *(_WORD *)v13;
          if ( Source[0] )
          {
            v15 = *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[14];
            v16 = v15 + 1;
            if ( *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[8] != 1
              || (unsigned int)v16 > *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[10] )
            {
              v17 = (char *)&tag_txt.m_charbuffer[-1].m_data[6];
              PStringBase<unsigned short>::allocate_ref_buffer(&tag_txt, v15);
              _wcscpy(tag_txt.m_charbuffer->m_data, (const wchar_t *)v17 + 10);
              if ( !InterlockedDecrement((volatile LONG *)v17 + 1) && v17 )
                (**(void (__thiscall ***)(char *, signed int))v17)(v17, 1);
            }
            else
            {
              *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[14] = v16;
              *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[12] = -1;
            }
            _wcsncpy((wchar_t *)tag_txt.m_charbuffer + v15 - 1, Source, 1u);
            v5 = index;
            tag_txt.m_charbuffer->m_data[*(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[14] - 1] = 0;
          }
          if ( v14 == 62 )
            break;
          v10 = _text->m_charbuffer;
          v11 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14];
          ++v12;
          if ( v12 >= v11 - 1 )
            goto LABEL_28;
        }
        v18 = curTag;
        if ( curTag )
        {
          v19 = tag_txt.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&tag_txt.m_charbuffer[-1].m_data[8]);
          v18->vfptr[1].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v18, (unsigned int)v19);
          if ( !InterlockedDecrement((volatile LONG *)&v18->m_cRef) )
            v18->vfptr->__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v18, 1u);
          curTag = 0;
LABEL_26:
          v20 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14] - 1;
          index = v5 + *(_DWORD *)&tag_txt.m_charbuffer[-1].m_data[14] - 1;
          if ( index >= v20 )
          {
            v37 = (char *)&tag_txt.m_charbuffer[-1].m_data[6];
            if ( !InterlockedDecrement((volatile LONG *)&tag_txt.m_charbuffer[-1].m_data[8]) && v37 )
              (**(void (__thiscall ***)(char *, signed int))v37)(v37, 1);
            return 1;
          }
          v5 = index;
          goto LABEL_28;
        }
        curTag = (TextTag *)TextTagFactory::MakeTag(&tag_txt);
        if ( curTag )
          goto LABEL_26;
      }
LABEL_28:
      v21 = (char *)&tag_txt.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&tag_txt.m_charbuffer[-1].m_data[8]) && v21 )
        (**(void (__thiscall ***)(char *, signed int))v21)(v21, 1);
      v4 = curTag;
LABEL_32:
      if ( v4 && v4->m_type == 268435457 )
      {
        v22 = v40;
        v23 = (int)&v40->m_curTagFontColor;
      }
      else
      {
        v22 = v40;
        v23 = (int)&v40->m_curFontColor;
      }
      v24 = _text->m_charbuffer;
      v25 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14];
      if ( v5 < v25 )
        v26 = (int)((char *)v24 + 2 * v5);
      else
        v26 = (int)((char *)v24 + 2 * v25 - 2);
      Glyph::Glyph(&newGlyph, *(_WORD *)v26, (RGBAColor *)v23, v22->m_curFontObj, v4);
      v27 = _glyphs;
      v28 = _glyphs->m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( _glyphs->m_num >= v28 )
      {
        v29 = v28 + 1;
        if ( v28 + 1 > 8 )
        {
          if ( v29 <= 0x4000 )
          {
            *(_DWORD *)Source = v28 + 1;
            __asm { bsr     this, dword ptr [esp+48h+Source] }
            v27 = _glyphs;
            if ( v29 > 1 << _EAX )
              v29 = 2 * (1 << _EAX);
          }
          else if ( v29 & 0x3FFF )
          {
            v29 += 0x4000 - (v29 & 0x3FFF);
          }
        }
        else
        {
          v29 = 8;
        }
        if ( !SmartArray<Glyph,1>::grow(v27, v29) )
          goto LABEL_50;
        v27 = _glyphs;
      }
      Glyph::operator=((int)&v27->m_data[v27->m_num], (int)&newGlyph);
      ++_glyphs->m_num;
LABEL_50:
      Glyph::~Glyph(&newGlyph);
      v3 = _text;
      ++v5;
      v35 = *(_DWORD *)&_text->m_charbuffer[-1].m_data[14] - 1;
      index = v5;
      if ( v5 >= v35 )
        return 1;
    }
  }
  return 1;
}

//----- (004691B0) --------------------------------------------------------  // acclient.c:165980
void __thiscall UIElement_Text::ScrollToPosition(UIElement_Text *this, const int i_iPos)
{
  bool v2; // bp@1
  UIElement_Text *v3; // esi@1
  int v4; // edi@2
  int v5; // eax@2
  char v6; // cl@2
  int v7; // eax@2
  void *v8; // eax@3
  int v9; // edx@5
  int v10; // ebx@5
  int v11; // eax@5
  const int v12; // ecx@7
  bool v13; // zf@7
  bool v14; // sf@7
  void *v15; // ecx@7
  Font *v16; // ecx@9
  const int v17; // ecx@10
  unsigned __int8 v18; // of@12
  void *v19; // ecx@12
  int v20; // ecx@14
  int v21; // ecx@15
  CInputManager *v22; // ebx@18
  int v23; // edi@19
  int v24; // ebx@19
  int v25; // edi@19
  int v26; // ebx@19
  int iX; // [sp+8h] [bp-Ch]@1
  int iY; // [sp+Ch] [bp-8h]@1
  int nVisibleHeight; // [sp+10h] [bp-4h]@2

  v2 = 0;
  v3 = this;
  iX = 0;
  iY = 0;
  UIElement_Text::RecalculateGlyphList(this);
  if ( GlyphList::FindXYFromPosition(&v3->m_glyphList, i_iPos, &iX, &iY) )
  {
    v4 = UIRegion::GetWidth((UIRegion *)&v3->vfptr) - v3->m_margR - v3->m_margL;
    v5 = UIRegion::GetHeight((UIRegion *)&v3->vfptr);
    v6 = LOBYTE(v3->m_bitField);
    v7 = v5 - v3->m_margD - v3->m_margU;
    nVisibleHeight = v7;
    if ( v6 & 2 )
    {
      i_iPos = v3->m_iScrollableHeight - v7;
      iY = 0;
      v8 = (void *)&i_iPos;
      if ( i_iPos <= 0 )
        v8 = &iY;
      v9 = *(_DWORD *)v8;
      v10 = iX;
      v11 = v4 + v3->m_iScrollableX;
      iY = v9;
      if ( iX + 2 > v11 )
      {
        v10 = 2 - v4 + iX;
        iX += 2 - v4;
      }
    }
    else
    {
      v12 = v3->m_iScrollableWidth - v4;
      i_iPos = v12;
      v13 = v12 == 0;
      v14 = v12 < 0;
      iX = 0;
      v15 = (void *)&i_iPos;
      if ( v14 || v13 )
        v15 = &iX;
      v10 = *(_DWORD *)v15;
      v16 = v3->m_curFontObj;
      iX = v10;
      if ( v16 )
        v17 = v16->maxCharHeight;
      else
        v17 = 0;
      i_iPos = v17;
      v18 = __OFSUB__(v17, v7);
      v14 = v17 - v7 < 0;
      v19 = (void *)&i_iPos;
      if ( !(v14 ^ v18) )
        v19 = &nVisibleHeight;
      v20 = *(_DWORD *)v19;
      v9 = iY;
      if ( v20 + iY > v7 + v3->m_iScrollableY )
      {
        v21 = v20 - v7;
        v9 = v21 + iY;
        iY += v21;
      }
      v2 = 0;
    }
    UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&v3->vfptr, v10, v9, v2);
    if ( v3->m_bitField & 0x40 )
    {
      v22 = ICIDM::s_cidm;
      if ( ICIDM::s_cidm )
      {
        v23 = ICIDM::s_cidm->vfptr->GetMouseX((ICIDM *)ICIDM::s_cidm);
        v24 = v22->vfptr->GetMouseY((ICIDM *)v22);
        v25 = v23 - v3->m_margL - UIRegion::GetScreenX0((UIRegion *)&v3->vfptr);
        v26 = v24 - v3->m_margU - UIRegion::GetScreenY0((UIRegion *)&v3->vfptr);
        i_iPos = UIElement_Text::DeterminePositionFromXY(v3, v25, v26);
        if ( UIElement_Text::IsPositionInView(v3, &i_iPos) )
          UIElement_Text::SetCursorPositionFromXY(v3, v25, v26, 0);
      }
    }
  }
}

//----- (00469350) --------------------------------------------------------  // acclient.c:166092
bool __thiscall UIElement_Text::IsAtVerticalEnd(UIElement_Text *this)
{
  unsigned int v1; // eax@1
  bool result; // al@2
  int _nPos; // [sp+0h] [bp-4h]@1

  _nPos = (int)this;
  v1 = this->m_glyphList.m_glyphList._num_elements;
  if ( v1 )
  {
    _nPos = v1 - 1;
    result = UIElement_Text::IsPositionInView(this, &_nPos);
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (00469370) --------------------------------------------------------  // acclient.c:166113
void __thiscall UIElement_Text::MouseDown(UIElement_Text *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIElement_Text *v4; // esi@1
  bool v5; // al@1
  unsigned int v6; // ebx@1
  int v7; // ebp@7
  int v8; // edi@7
  unsigned int v9; // eax@12
  unsigned int v10; // edi@13
  bool bPrevInFocus; // [sp+13h] [bp-1h]@1

  v4 = this;
  v5 = UIElement::GetHasFocus((UIElement *)&this->vfptr);
  v6 = _button;
  bPrevInFocus = v5;
  UIElement_Scrollable::MouseDown((UIElement_Scrollable *)&v4->vfptr, _xWindow, _yWindow, _button);
  if ( !((v4->m_nFlags >> 19) & 1) && !((v4->m_nFlags >> 18) & 1) && (v6 == 7 || v6 == 5 || v6 == 6) )
  {
    if ( *((_BYTE *)&v4->0 + 164) & 1 )
    {
      v7 = _xWindow - v4->m_margL - UIRegion::GetScreenX0((UIRegion *)&v4->vfptr);
      v8 = _yWindow - v4->m_margU - UIRegion::GetScreenY0((UIRegion *)&v4->vfptr);
      if ( v6 == 7 )
      {
        if ( v4->m_bitField & 5 )
        {
          LOBYTE(_button) = 0;
          UIElement::GetAttribute_Bool((UIElement *)&v4->vfptr, 0xD1u, (bool *)&_button);
          if ( bPrevInFocus || !(_BYTE)_button )
          {
            v9 = UIElement_Text::DeterminePositionFromXY(v4, v7, v8);
            if ( SLOBYTE(v4->m_bitField) >= 0 )
              v10 = v4->m_nCursorPos;
            else
              v10 = v4->m_nSelectionStart;
            UIElement_Text::SetCursorPosition(v4, v9, ctm_DontSelectText);
            ((void (__thiscall *)(UIElement_Text *))v4->vfptr[21].__vecDelDtor)(v4);
            if ( v4->m_bitField & 4 )
            {
              UIElement_Text::SetSelecting(v4, 1);
              if ( !(v4->m_bitField & 0x40) )
                v4->m_bitField |= 0x40u;
              if ( ICIDM::s_cidm && (unsigned __int8)((int (*)(void))ICIDM::s_cidm->vfptr->ShiftKeyDown)() )
              {
                UIElement_Text::SetSelectionStart(v4, v10);
                UIElement_Text::SetSelectionEnd(v4, v4->m_nCursorPos);
              }
              else
              {
                UIElement_Text::SetSelectionStart(v4, v4->m_nCursorPos);
              }
            }
          }
          else
          {
            UIElement_Text::SelectAll(v4);
          }
        }
      }
    }
  }
}

//----- (004694F0) --------------------------------------------------------  // acclient.c:166177
void __thiscall UIElement_Text::MouseUp(UIElement_Text *this, unsigned int _xWindow, unsigned int _yWindow, unsigned int _button)
{
  UIElement_Text *v4; // esi@1
  HashSetData<unsigned long> *v5; // edx@1
  bool v6; // zf@1
  int v7; // ebp@7
  int v8; // edi@7
  unsigned int v9; // eax@8
  unsigned int v10; // edi@11
  bool bMouseDownHere; // [sp+Fh] [bp-25h]@5
  Glyph click; // [sp+10h] [bp-24h]@11

  v4 = this;
  v5 = v4->m_mouseDownTable.m_intrusiveTable.m_buckets[_button % v4->m_mouseDownTable.m_intrusiveTable.m_numBuckets];
  v6 = v5 == 0;
  if ( v5 )
  {
    do
    {
      if ( v5->m_hashKey == _button )
        break;
      v5 = v5->m_hashNext;
    }
    while ( v5 );
    v6 = v5 == 0;
  }
  bMouseDownHere = !v6;
  UIElement::MouseUp((UIElement *)&this->vfptr, _xWindow, _yWindow, _button);
  if ( v4->m_bitField & 0x40 || bMouseDownHere )
  {
    v7 = _xWindow - v4->m_margL - UIRegion::GetScreenX0((UIRegion *)&v4->vfptr);
    v8 = _yWindow - v4->m_margU - UIRegion::GetScreenY0((UIRegion *)&v4->vfptr);
    if ( v4->m_bitField & 0x40 )
    {
      v9 = UIElement_Text::DeterminePositionFromXY(v4, v7, v8);
      UIElement_Text::SetCursorPosition(v4, v9, 0);
      if ( v4->m_bitField & 0x40 )
        v4->m_bitField &= 0xFFFFFFBF;
    }
    if ( bMouseDownHere )
    {
      v10 = UIElement_Text::DeterminePositionFromXY(v4, v7, v8);
      Glyph::Glyph(&click);
      if ( GlyphList::InqGlyph(&v4->m_glyphList, v10, &click) )
      {
        if ( click.m_tag )
          ((void (__stdcall *)(_DWORD))click.m_tag->vfptr[5].__vecDelDtor)(_button);
      }
      Glyph::~Glyph(&click);
    }
  }
}

//----- (004695F0) --------------------------------------------------------  // acclient.c:166231
void __userpurge UIElement_Text::MouseMove(UIElement_Text *this@<ecx>, int a2@<edi>, int i_xWindow, int i_yWindow)
{
  UIElement_Text *v4; // esi@1
  int v5; // edi@3
  unsigned int v6; // eax@3
  unsigned int v7; // eax@3

  v4 = this;
  if ( this->m_bitField & 0x40 )
  {
    v5 = i_xWindow - this->m_margL - UIRegion::GetScreenX0((UIRegion *)&this->vfptr);
    v6 = UIRegion::GetScreenY0((UIRegion *)&v4->vfptr);
    v7 = UIElement_Text::DeterminePositionFromXY(v4, v5, i_yWindow - v4->m_margU - v6);
    UIElement_Text::SetCursorPosition(v4, v7, 0);
  }
  else
  {
    UIElement::MouseMove((UIElement *)&this->vfptr, a2, i_xWindow, i_yWindow);
  }
}

//----- (00469660) --------------------------------------------------------  // acclient.c:166253
char __thiscall UIElement_Text::InqSizewMargins(UIElement_Text *this, StringInfo *_info, int *_width, int *_height, UIElement_Text::UIText_InqSize_Flag i_eFlag)
{
  int *v5; // ebx@1
  int *v6; // edi@1
  UIElement_Text *v7; // esi@1
  int *v8; // esi@2
  int v10; // eax@9
  UIRegion *v11; // eax@11
  int v12; // eax@15
  int *v13; // esi@15
  SmartArray<Glyph,1> glyphs; // [sp+10h] [bp-40h]@5
  GlyphList tmp; // [sp+1Ch] [bp-34h]@5

  v5 = _height;
  v6 = _width;
  v7 = this;
  *_width = 0;
  *v5 = 0;
  StringInfo::GetString(_info, (PStringBase<unsigned short> *)&_height, 0);
  if ( *(_height - 1) != 1 )
  {
    glyphs.m_data = 0;
    glyphs.m_sizeAndDeallocate = 0;
    glyphs.m_num = 0;
    UIElement_Text::InqGlyphs(v7, (PStringBase<unsigned short> *)&_height, &glyphs);
    GlyphList::GlyphList(&tmp);
    GlyphList::AddText(&tmp, 0, &glyphs);
    _width = 0;
    if ( i_eFlag == 1 )
    {
      v10 = UIRegion::GetWidth((UIRegion *)&v7->vfptr);
      _width = (int *)v10;
      goto LABEL_15;
    }
    if ( i_eFlag == 2 )
    {
      v11 = (UIRegion *)((int (__thiscall *)(UIElement_Text *))v7->vfptr[13].OnAction)(v7);
      if ( v11 )
      {
        v10 = UIRegion::GetWidth(v11);
        _width = (int *)v10;
        goto LABEL_15;
      }
    }
    else
    {
      if ( i_eFlag == 3 )
      {
        v10 = v7->m_desc.m_width;
        _width = (int *)v7->m_desc.m_width;
        goto LABEL_15;
      }
      if ( UIElement::GetAttribute_Int((UIElement *)&v7->vfptr, 0x3Du, (int *)&_width) )
      {
        v10 = (int)_width;
        goto LABEL_15;
      }
    }
    v10 = RenderDevice::GetDisplayWidth(RenderDevice::render_device);
    _width = (int *)v10;
LABEL_15:
    v12 = v10 - v7->m_margR - v7->m_margL;
    *v6 = 0;
    *v5 = 0;
    GlyphList::Recalculate(&tmp, v12, (v7->m_bitField & 2) == 2, v6, v5);
    *v6 += v7->m_margL + v7->m_margR;
    *v5 += v7->m_margU + v7->m_margD;
    GlyphList::~GlyphList(&tmp);
    SmartArray<Glyph,1>::~SmartArray<Glyph,1>(&glyphs);
    v13 = _height - 5;
    if ( !InterlockedDecrement(_height - 4) && v13 )
      (*(void (__thiscall **)(_DWORD, _DWORD))*v13)(v13, 1);
    return 1;
  }
  v8 = _height - 5;
  if ( !InterlockedDecrement(_height - 4) && v8 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))*v8)(v8, 1);
    return 1;
  }
  return 1;
}

//----- (00469800) --------------------------------------------------------  // acclient.c:166337
void __thiscall UIElement_Text::DeleteSection(UIElement_Text *this, unsigned int i_nStart, unsigned int i_nEnd, int i_bKeepCurrentTextInView)
{
  UIElement_Text *v4; // esi@1
  unsigned int v5; // eax@1
  unsigned int v6; // edi@1
  unsigned int v7; // ebp@2
  unsigned int v8; // eax@5
  unsigned int v9; // eax@10
  int v10; // ebx@12
  unsigned int v11; // ecx@13
  unsigned int v12; // eax@13
  unsigned int v13; // ecx@22
  int v14; // ecx@25
  int v15; // eax@25
  unsigned int v16; // [sp-10h] [bp-18h]@14
  int oldScroll; // [sp+10h] [bp+8h]@13

  v4 = this;
  v5 = this->m_glyphList.m_glyphList._num_elements;
  v6 = i_nStart;
  if ( i_nStart >= v5 )
    return;
  v7 = i_nEnd;
  if ( i_nEnd > v5 || i_nStart >= i_nEnd )
    return;
  if ( !(_BYTE)i_bKeepCurrentTextInView )
    goto LABEL_12;
  UIElement_Text::RecalculateGlyphList(this);
  v8 = UIElement_Text::DeterminePositionFromXY(v4, v4->m_iScrollableX, v4->m_iScrollableY);
  if ( i_nStart > v8 && i_nEnd > v8 || !v4->m_iScrollableY || UIElement_Text::IsAtVerticalEnd(v4) )
  {
    LOBYTE(i_bKeepCurrentTextInView) = 0;
LABEL_12:
    v10 = i_bKeepCurrentTextInView;
    goto LABEL_13;
  }
  LOBYTE(i_bKeepCurrentTextInView) = 1;
  if ( v4->m_bitField & 2 )
    v9 = v4->m_iScrollableX;
  else
    v9 = v4->m_iScrollableY;
  i_nStart = v9;
  if ( (v4->m_bitField & 2) == 2 )
    v10 = v4->m_iScrollableWidth;
  else
    v10 = v4->m_iScrollableHeight;
LABEL_13:
  v11 = GlyphList::Delete(&v4->m_glyphList, v6, i_nEnd);
  v12 = v4->m_nCursorPos;
  oldScroll = v11;
  if ( v12 > v7 )
  {
    v16 = v12 - v11;
LABEL_21:
    UIElement_Text::SetCursorPosition(v4, v16, 0);
    goto LABEL_22;
  }
  if ( v12 > v6 )
  {
    v16 = v6;
    goto LABEL_21;
  }
LABEL_22:
  v13 = v4->m_bitField;
  if ( !(v13 & 0x100) )
  {
    v4->m_bitField = v13 | 0x100;
    UIRegion::MakeRootDirtyHere((UIRegion *)&v4->vfptr);
  }
  if ( (_BYTE)i_bKeepCurrentTextInView )
  {
    UIElement_Text::RecalculateGlyphList(v4);
    v14 = v4->m_iScrollableX;
    v15 = v4->m_iScrollableY;
    if ( v4->m_bitField & 2 )
      v14 = i_nStart + v4->m_iScrollableWidth - v10;
    else
      v15 = i_nStart + v4->m_iScrollableHeight - v10;
    UIElement_Scrollable::SetScrollableXY((UIElement_Scrollable *)&v4->vfptr, v14, v15, 0);
  }
  if ( oldScroll )
    UIElement::BroadcastElementMessage((UIElement *)&v4->vfptr, 0x44u, 0, 0);
}

//----- (00469970) --------------------------------------------------------  // acclient.c:166422
void __thiscall UIElement_Text::BeheadText(UIElement_Text *this, unsigned int i_cPosition, int bKeepCurrentTextInView)
{
  UIElement_Text::DeleteSection(this, 0, i_cPosition, bKeepCurrentTextInView);
}

//----- (00469990) --------------------------------------------------------  // acclient.c:166428
void __thiscall UIElement_Text::DeleteChar(UIElement_Text *this)
{
  UIElement_Text::DeleteSection(this, this->m_nCursorPos, this->m_nCursorPos + 1, 0);
}

//----- (004699B0) --------------------------------------------------------  // acclient.c:166434
void __thiscall UIElement_Text::DeleteSelection(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  unsigned int v2; // ecx@3
  bool v3; // zf@3
  unsigned int nEnd; // [sp+4h] [bp-8h]@1
  unsigned int nStart; // [sp+8h] [bp-4h]@1

  v1 = this;
  if ( UIElement_Text::GetSelection(this, &nStart, &nEnd) )
  {
    UIElement_Text::DeleteSection(v1, nStart, nEnd, 0);
    if ( SLOBYTE(v1->m_bitField) < 0 )
    {
      v2 = v1->m_bitField & 0xFFFFFF7F;
      v3 = (v1->m_bitField & 0x40) == 0;
      v1->m_bitField = v2;
      if ( !v3 )
        v1->m_bitField = v2 & 0xFFFFFFBF;
      UIElement_Text::SetSelecting(v1, 0);
      v1->m_nSelectionStart = 0;
      v1->m_nSelectionEnd = 0;
    }
  }
}

//----- (00469A30) --------------------------------------------------------  // acclient.c:166461
void __thiscall UIElement_Text::AddText_Internal(UIElement_Text *this, PStringBase<unsigned short> _text, unsigned int i_atfFlags)
{
  UIElement_Text *v3; // esi@1
  char *v4; // esi@2
  char v5; // bl@3
  unsigned int v6; // eax@9
  ICMDCommandEnum v7; // edx@10
  unsigned int v8; // eax@10
  unsigned int v9; // ecx@12
  LONG v10; // eax@2
  SmartArray<Glyph,1> glyphs; // [sp+4h] [bp-Ch]@7

  v3 = this;
  if ( *(_DWORD *)&_text.m_charbuffer[-1].m_data[14] == 1 )
  {
    v4 = (char *)&_text.m_charbuffer[-1].m_data[6];
    v10 = InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]);
  }
  else
  {
    v5 = i_atfFlags;
    if ( this->m_bitField & 1 )
    {
      UIElement_Text::DeleteSelection(this);
    }
    else if ( !(i_atfFlags & 1) )
    {
      UIElement_Text::SetSelecting(this, 0);
    }
    glyphs.m_data = 0;
    glyphs.m_sizeAndDeallocate = 0;
    glyphs.m_num = 0;
    UIElement_Text::InqGlyphs(v3, &_text, &glyphs);
    if ( v5 & 2 )
    {
      GlyphList::AddText(&v3->m_glyphList, v3->m_glyphList.m_glyphList._num_elements, &glyphs);
    }
    else
    {
      v6 = GlyphList::AddText(&v3->m_glyphList, v3->m_nCursorPos, &glyphs);
      UIElement_Text::SetCursorPosition(v3, v6 + v3->m_nCursorPos, ctm_DontSelectText);
    }
    v7 = (signed int)Timer::cur_time.Cmd;
    HIDWORD(v3->m_lastCursorMoveTime) = Timer::cur_time.Param;
    v8 = v3->m_bitField;
    LODWORD(v3->m_lastCursorMoveTime) = v7;
    if ( BYTE1(v8) & 4 )
      UIElement_Text::ResizeToPaper(v3);
    v9 = v3->m_bitField;
    if ( !(v9 & 0x100) )
    {
      v3->m_bitField = v9 | 0x100;
      UIRegion::MakeRootDirtyHere((UIRegion *)&v3->vfptr);
    }
    SmartArray<Glyph,1>::~SmartArray<Glyph,1>(&glyphs);
    v4 = (char *)&_text.m_charbuffer[-1].m_data[6];
    v10 = InterlockedDecrement((volatile LONG *)&_text.m_charbuffer[-1].m_data[8]);
  }
  if ( !v10 )
  {
    if ( v4 )
      (**(void (__thiscall ***)(char *, signed int))v4)(v4, 1);
  }
}

//----- (00469B60) --------------------------------------------------------  // acclient.c:166527
void __thiscall UIElement_Text::Cut(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1

  v1 = this;
  if ( SLOBYTE(this->m_bitField) < 0 )
  {
    UIElement_Text::Copy(this);
    if ( v1->m_bitField & 1 )
      UIElement_Text::DeleteSelection(v1);
  }
}

//----- (00469B90) --------------------------------------------------------  // acclient.c:166541
void __thiscall UIElement_Text::CharacterHandler(UIElement_Text *this, wchar_t charToHandle)
{
  UIElement_Text *v2; // esi@1
  int v3; // ecx@2
  int v4; // ebx@2
  PSRefBufferCharData<unsigned short> *v5; // ecx@5
  int v6; // edi@5
  Graphic *v7; // eax@9
  PSRefBufferCharData<unsigned short> *v8; // ecx@11
  PStringBase<unsigned short> v9; // [sp-14h] [bp-18h]@5
  unsigned int v10; // [sp-10h] [bp-14h]@5
  unsigned __int16 str[2]; // [sp+0h] [bp-4h]@1

  *(_DWORD *)str = this;
  v2 = this;
  if ( !SceneTool::m_pDebugConsole->m_IsInputActive )
  {
    v3 = this->m_ptTilingOffset.x;
    v4 = charToHandle;
    if ( v3 & 1 )
    {
      switch ( charToHandle )
      {
        case 0xAu:
        case 0xDu:
          if ( !(v3 & 2) )
          {
            PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&charToHandle);
            *(_DWORD *)str = 10;
            PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&charToHandle, str, 1u);
            v10 = 0;
            v9.m_charbuffer = v5;
            v6 = (int)&v2[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[20];
            PStringBase<unsigned short>::PStringBase<unsigned short>(
              (CaseInsensitiveStringBase<PStringBase<char> > *)&v9,
              (PStringBase<char> *)&charToHandle);
            UIElement_Text::AddText_Internal((UIElement_Text *)((char *)v2 - 1544), v9, v10);
            if ( v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11] != v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
              goto LABEL_14;
            v10 = *(_DWORD *)(v6 + 1564);
            goto LABEL_13;
          }
          break;
        default:
          if ( charToHandle > 0x1Fu && charToHandle != 127 )
          {
            v7 = v2->m_image;
            if ( !v7 || (unsigned __int8)((int (__cdecl *)(_DWORD))v7)(charToHandle) )
            {
              PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&charToHandle);
              *(_DWORD *)str = v4;
              PStringBase<unsigned short>::append_n_chars((PStringBase<unsigned short> *)&charToHandle, str, 1u);
              v10 = 0;
              v9.m_charbuffer = v8;
              v6 = (int)&v2[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[20];
              PStringBase<unsigned short>::PStringBase<unsigned short>(
                (CaseInsensitiveStringBase<PStringBase<char> > *)&v9,
                (PStringBase<char> *)&charToHandle);
              UIElement_Text::AddText_Internal((UIElement_Text *)((char *)v2 - 1544), v9, v10);
              if ( v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[11] == v2->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
              {
                v10 = *(_DWORD *)(v6 + 1564);
LABEL_13:
                UIElement_Text::ScrollToPosition((UIElement_Text *)v6, v10);
              }
LABEL_14:
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&charToHandle);
            }
          }
          break;
        case 9u:
        case 0x1Bu:
          break;
      }
    }
    UIElement::BroadcastElementMessage(
      (UIElement *)&v2[-1].m_children.m_ihlIntrusive.m_hash.m_aInplaceBuckets[20],
      0x12u,
      (unsigned __int16)v4,
      0);
  }
}

//----- (00469CE0) --------------------------------------------------------  // acclient.c:166625
void __thiscall UIElement_Text::AppendText(UIElement_Text *this, PStringBase<unsigned short> *_text)
{
  UIElement_Text *v2; // esi@1
  PStringBase<unsigned short> v3; // ST04_4@1

  v2 = this;
  v3.m_charbuffer = _text->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_text->m_charbuffer[-1].m_data[8]);
  UIElement_Text::AddText_Internal(v2, v3, 3u);
}

//----- (00469D10) --------------------------------------------------------  // acclient.c:166637
void __thiscall UIElement_Text::AppendStringInfo(UIElement_Text *this, StringInfo *_info)
{
  UIElement_Text *v2; // esi@1
  PStringBase<unsigned short> v3; // ST04_4@1
  char *v4; // esi@1

  v2 = this;
  v3.m_charbuffer = StringInfo::GetString(_info, (PStringBase<unsigned short> *)&_info, 0)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v3.m_charbuffer[-1].m_data[8]);
  UIElement_Text::AddText_Internal(v2, v3, 3u);
  v4 = (char *)&_info[-1].m_variables.m_intrusiveTable.m_numElements;
  if ( !InterlockedDecrement((volatile LONG *)&_info[-1].m_LiteralValue) )
  {
    if ( v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
  }
}

//----- (00469D70) --------------------------------------------------------  // acclient.c:166656
void __thiscall UIElement_Text::AppendTextWithFont(UIElement_Text *this, PStringBase<unsigned short> *_text, int _fontDIDNum, int _fontColorNum)
{
  UIElement_Text *v4; // esi@1
  PStringBase<unsigned short> v5; // ST04_4@1

  v4 = this;
  UIElement_Text::SetFontDIDHelper(this, 0x1Au, &this->m_curFontObj, _fontDIDNum);
  UIElement_Text::SetFontColorHelper(v4, 0x1Bu, &v4->m_curFontColor, _fontColorNum);
  UIElement_Text::SetFontColorHelper(v4, 0x1Du, &v4->m_curTagFontColor, _fontColorNum);
  v5.m_charbuffer = _text->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&_text->m_charbuffer[-1].m_data[8]);
  UIElement_Text::AddText_Internal(v4, v5, 3u);
}

//----- (00469DE0) --------------------------------------------------------  // acclient.c:166671
void __thiscall UIElement_Text::AppendStringInfoWithFont(UIElement_Text *this, StringInfo *_info, int _fontDIDNum, int _fontColorNum)
{
  UIElement_Text *v4; // esi@1
  int v5; // edi@1
  PStringBase<unsigned short> v6; // ST04_4@1
  int v7; // esi@1

  v4 = this;
  UIElement_Text::SetFontDIDHelper(this, 0x1Au, &this->m_curFontObj, _fontDIDNum);
  v5 = _fontColorNum;
  UIElement_Text::SetFontColorHelper(v4, 0x1Bu, &v4->m_curFontColor, _fontColorNum);
  UIElement_Text::SetFontColorHelper(v4, 0x1Du, &v4->m_curTagFontColor, v5);
  v6.m_charbuffer = StringInfo::GetString(_info, (PStringBase<unsigned short> *)&_fontDIDNum, 0)->m_charbuffer;
  InterlockedIncrement((volatile LONG *)&v6.m_charbuffer[-1].m_data[8]);
  UIElement_Text::AddText_Internal(v4, v6, 3u);
  v7 = _fontDIDNum - 20;
  if ( !InterlockedDecrement((volatile LONG *)(_fontDIDNum - 20 + 4)) )
  {
    if ( v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
}

//----- (00469E70) --------------------------------------------------------  // acclient.c:166695
void __thiscall UIElement_Text::CheckStringDownloads(UIElement_Text *this)
{
  UIElement_Text *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // edi@2
  StringDownload *v4; // ebx@3
  unsigned int v5; // eax@5
  StringDownload **v6; // edx@6
  int v7; // ecx@6
  int v8; // eax@6
  int v9; // ecx@6
  unsigned int v10; // esi@9
  PSRefBufferCharData<unsigned short> *v11; // ecx@9
  AsyncCacheCallbackVtbl *v12; // eax@9
  unsigned int v13; // eax@10
  PStringBase<unsigned short> v14; // [sp-8h] [bp-20h]@9
  unsigned int v15; // [sp-4h] [bp-1Ch]@9
  bool bTextAdded; // [sp+13h] [bp-5h]@2
  unsigned int index; // [sp+14h] [bp-4h]@2

  v1 = this;
  v2 = this->m_downloadQueue.m_num;
  if ( v2 )
  {
    v3 = 0;
    bTextAdded = 0;
    index = 0;
    if ( v2 )
    {
      do
      {
        v4 = v1->m_downloadQueue.m_data[v3];
        if ( v4 )
        {
          if ( v4->m_prefetchContext.m_id != INVALID_ASYNCCONTEXT_4.m_id )
            break;
          v5 = v1->m_downloadQueue.m_num;
          if ( v3 < v5 )
          {
            v6 = v1->m_downloadQueue.m_data;
            v7 = v5 - 1;
            v1->m_downloadQueue.m_num = v5 - 1;
            v8 = (int)&v6[v3];
            v9 = (int)&v6[v7];
            if ( v8 < (unsigned int)v9 )
            {
              qmemcpy((void *)v8, (const void *)(v8 + 4), 4 * (((unsigned int)(v9 - v8 - 1) >> 2) + 1));
              v3 = index;
            }
            v1->m_downloadQueue.m_data[v1->m_downloadQueue.m_num] = 0;
          }
          --v3;
          UIElement_Text::SetFontDIDHelper(v1, 0x1Au, &v1->m_curFontObj, v4->m_fontDIDNum);
          v10 = v4->m_fontColorNum;
          UIElement_Text::SetFontColorHelper(v1, 0x1Bu, &v1->m_curFontColor, v4->m_fontColorNum);
          UIElement_Text::SetFontColorHelper(v1, 0x1Du, &v1->m_curTagFontColor, v10);
          v15 = 0;
          v14.m_charbuffer = v11;
          StringInfo::GetString(&v4->m_info, &v14, 0);
          UIElement_Text::AddText_Internal(v1, v14, v15);
          v12 = v4->vfptr;
          v15 = 1;
          bTextAdded = 1;
          ((void (__thiscall *)(StringDownload *, signed int))v12[1].OnContextFinished)(v4, 1);
        }
        v13 = v1->m_downloadQueue.m_num;
        ++v3;
        index = v3;
      }
      while ( v3 < v13 );
    }
    if ( !v1->m_downloadQueue.m_num )
      UIListener::UnRegisterForGlobalMessage((UIListener *)&v1->vfptr, 3u);
    if ( bTextAdded )
      UIElement::BroadcastElementMessage((UIElement *)&v1->vfptr, 0x13u, 0, 0);
  }
}

//----- (00469FC0) --------------------------------------------------------  // acclient.c:166774
void __thiscall UIElement_Text::Global_Loop(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  long double v2; // st7@3
  char v3; // al@6
  ICMDCommandEnum v4; // edx@8
  bool v5; // zf@8
  unsigned int v6; // eax@8
  unsigned int v7; // eax@9
  double now; // [sp+8h] [bp-8h]@3

  v1 = this;
  UIElement_Text::CheckStringDownloads(this);
  if ( v1->m_bitField & 5 && UIElement::GetHasFocus((UIElement *)&v1->vfptr) )
  {
    now = *(double *)&Timer::cur_time;
    v2 = (double)GetCaretBlinkTime() * 0.001;
    if ( v1->m_lastCursorMoveTime > v1->m_lastFlashFlipTime )
      goto LABEL_16;
    if ( v2 > now - v1->m_lastFlashFlipTime )
      return;
    if ( v1->m_bitField & 0x200 )
      v3 = 0;
    else
LABEL_16:
      v3 = 1;
    v4 = (signed int)Timer::cur_time.Cmd;
    HIDWORD(v1->m_lastFlashFlipTime) = Timer::cur_time.Param;
    LODWORD(v1->m_lastFlashFlipTime) = v4;
    v5 = v3 == 0;
    v6 = v1->m_bitField;
    if ( v5 )
      v7 = v6 & 0xFFFFFDFF;
    else
      v7 = v6 | 0x200;
    v1->m_bitField = v7;
    if ( v1->m_lastCursor.m_x1 - v1->m_lastCursor.m_x0 + 1 > 0 && v1->m_lastCursor.m_y1 - v1->m_lastCursor.m_y0 + 1 > 0 )
      UIRegion::AddDirtyRect((UIRegion *)&v1->vfptr, &v1->m_lastCursor);
  }
}

//----- (0046A0C0) --------------------------------------------------------  // acclient.c:166816
void __thiscall UIElement_Text::SetStringInfo(UIElement_Text *this, StringInfo *_info)
{
  UIElement_Text *v2; // esi@1

  v2 = this;
  UIElement_Text::ClearAllText(this);
  UIElement_Text::AppendStringInfo(v2, _info);
}

//----- (0046A0E0) --------------------------------------------------------  // acclient.c:166826
void __thiscall UIElement_Text::SetStringInfoWithFont(UIElement_Text *this, StringInfo *_info, int _fontDIDNum, int _fontColorNum)
{
  UIElement_Text *v4; // esi@1

  v4 = this;
  UIElement_Text::ClearAllText(this);
  UIElement_Text::AppendStringInfoWithFont(v4, _info, _fontDIDNum, _fontColorNum);
}

//----- (0046A110) --------------------------------------------------------  // acclient.c:166836
void __thiscall UIElement_Text::Paste(UIElement_Text *this)
{
  UIElement_Text *v1; // ebp@1
  char *v2; // esi@6
  char *v3; // esi@9
  PSRefBufferCharData<unsigned short> *v4; // ecx@12
  unsigned int v5; // eax@12
  unsigned int v6; // esi@12
  bool v7; // cf@13
  int v8; // eax@14
  char *v9; // esi@19
  PStringBase<unsigned short> txt; // [sp+Ch] [bp-Ch]@2
  PStringBase<unsigned short> search; // [sp+10h] [bp-8h]@6
  PStringBase<unsigned short> str; // [sp+14h] [bp-4h]@6

  v1 = this;
  if ( this->m_bitField & 1 )
  {
    txt.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( Device::GetStringFromClipboard() && *(_DWORD *)&txt.m_charbuffer[-1].m_data[14] != 1 )
    {
      if ( SLOBYTE(v1->m_bitField) < 0 )
        UIElement_Text::DeleteSelection(v1);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&str, L"\n");
      PStringBase<unsigned short>::PStringBase<unsigned short>(&search, L"\r\n");
      PStringBase<unsigned short>::replace(&txt, &search, &str);
      v2 = (char *)&search.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&search.m_charbuffer[-1].m_data[8]) && v2 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
      v3 = (char *)&str.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1].m_data[8]) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = txt.m_charbuffer;
      v5 = *(_DWORD *)&txt.m_charbuffer[-1].m_data[14];
      v6 = 0;
      if ( v5 )
      {
        v7 = v5 > 0;
        do
        {
          v8 = (int)((char *)v4 + 2 * v5 - 2);
          if ( v7 )
            v8 = (int)((char *)v4 + 2 * v6);
          v1->vfptr->CharacterHandler((CInputHandler *)&v1->vfptr, *(_WORD *)v8);
          v4 = txt.m_charbuffer;
          v5 = *(_DWORD *)&txt.m_charbuffer[-1].m_data[14];
          ++v6;
          v7 = v6 < v5;
        }
        while ( v6 < v5 );
      }
      str.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v1->m_nCursorPos;
      if ( !UIElement_Text::IsPositionInView(v1, (const int *)&str) )
        UIElement_Text::ScrollToPosition(v1, v1->m_nCursorPos);
    }
    v9 = (char *)&txt.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&txt.m_charbuffer[-1].m_data[8]) )
    {
      if ( v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
    }
  }
}

//----- (0046A260) --------------------------------------------------------  // acclient.c:166902
bool __thiscall UIElement_Text::OnAction(UIElement_Text *this, InputEvent *i_evt)
{
  UIElement_Text *v2; // esi@1
  bool result; // al@1
  unsigned int v4; // eax@26
  unsigned int v5; // eax@29
  unsigned int v6; // eax@31

  v2 = this;
  result = UIElement::OnAction((UIElement *)&this->vfptr, i_evt);
  if ( !result && i_evt->m_fStart )
  {
    switch ( i_evt->m_InputAction )
    {
      case 0x1Eu:
        UIElement_Text::MoveCursor(v2, END|LENEXT);
        goto LABEL_5;
      case 0x1Fu:
        UIElement_Text::MoveCursor(v2, BADCODE|LENEXT);
        return 1;
      case 0x16u:
        UIElement_Text::MoveCursor(v2, END);
        return 1;
      case 0x18u:
        UIElement_Text::MoveCursor(v2, LIT);
        return 1;
      case 0x17u:
        UIElement_Text::MoveCursor(v2, BADCODE);
        return 1;
      case 0x19u:
        UIElement_Text::MoveCursor(v2, WASH);
        return 1;
      case 0x20u:
        UIElement_Text::MoveCursor(v2, DISTEXT);
        return 1;
      case 0x21u:
        UIElement_Text::MoveCursor(v2, COPY);
        return 1;
      case 0x1Au:
        UIElement_Text::MoveCursor(v2, LENEXT);
        return 1;
      case 0x1Cu:
        UIElement_Text::MoveCursor(v2, 0);
        return 1;
      case 0x1Bu:
        UIElement_Text::MoveCursor(v2, DIST);
        return 1;
      case 0x1Du:
        UIElement_Text::MoveCursor(v2, LEN);
        return 1;
      case 0x22u:
        UIElement_Text::Copy(v2);
        return 1;
      case 0x23u:
        UIElement_Text::Cut(v2);
        return 1;
      case 0x24u:
        UIElement_Text::Paste(v2);
        return 1;
      case 0x26u:
        if ( SLOBYTE(v2->m_bitField) < 0 && v2->m_nSelectionStart != v2->m_nSelectionEnd )
          goto LABEL_23;
        goto LABEL_28;
      case 0x28u:
        if ( SLOBYTE(v2->m_bitField) < 0 && v2->m_nSelectionStart != v2->m_nSelectionEnd )
        {
LABEL_23:
          UIElement_Text::DeleteSelection(v2);
          result = 1;
        }
        else
        {
          v4 = v2->m_nCursorPos;
          if ( v4 )
          {
            UIElement_Text::SetCursorPosition(v2, v4 - 1, 0);
LABEL_28:
            UIElement_Text::DeleteChar(v2);
            result = 1;
          }
          else
          {
LABEL_5:
            result = 1;
          }
        }
        break;
      case 0x27u:
        v5 = v2->m_bitField;
        if ( !(BYTE1(v5) & 0x10) )
          goto LABEL_5;
        ((void (__thiscall *)(UIElement_Text *))v2->vfptr[22].__vecDelDtor)(v2);
        return 1;
      case 0x25u:
        v6 = v2->m_bitField;
        if ( !(BYTE1(v6) & 0x20) )
          goto LABEL_5;
        ((void (__thiscall *)(UIElement_Text *))v2->vfptr[22].__vecDelDtor)(v2);
        result = 1;
        break;
      default:
        return result;
    }
  }
  return result;
}

//----- (0046A4A0) --------------------------------------------------------  // acclient.c:167010
void __thiscall UIElement_Text::ListenToGlobalMessage(UIElement_Text *this, unsigned int _messageID, int _data)
{
  if ( _messageID == 3 )
    UIElement_Text::Global_Loop(this);
}

//----- (0046A4B0) --------------------------------------------------------  // acclient.c:167017
void __thiscall UIElement_Text::SetText(UIElement_Text *this, PStringBase<unsigned short> *_text)
{
  UIElement_Text *v2; // esi@1
  StringInfo _info; // [sp+4h] [bp-90h]@1

  v2 = this;
  StringInfo::StringInfo(&_info);
  StringInfo::SetLiteralValue(&_info, _text, 1);
  UIElement_Text::ClearAllText(v2);
  UIElement_Text::AppendStringInfo(v2, &_info);
  StringInfo::~StringInfo(&_info);
}

//----- (0046A500) --------------------------------------------------------  // acclient.c:167031
void __thiscall UIElement_Text::SetTextWithFont(UIElement_Text *this, PStringBase<unsigned short> *_text, int _fontDIDNum, int _fontColorNum)
{
  UIElement_Text *v4; // esi@1
  StringInfo _info; // [sp+4h] [bp-90h]@1

  v4 = this;
  StringInfo::StringInfo(&_info);
  StringInfo::SetLiteralValue(&_info, _text, 1);
  UIElement_Text::ClearAllText(v4);
  UIElement_Text::AppendStringInfoWithFont(v4, &_info, _fontDIDNum, _fontColorNum);
  StringInfo::~StringInfo(&_info);
}

//----- (0046A560) --------------------------------------------------------  // acclient.c:167045
void __thiscall UIElement_Text::DoFontReset(UIElement_Text *this)
{
  UIElement_Text *v1; // esi@1
  PStringBase<unsigned short> *v2; // eax@2
  char *v3; // esi@2
  PStringBase<unsigned short> result; // [sp+0h] [bp-4h]@1

  result.m_charbuffer = (PSRefBufferCharData<unsigned short> *)this;
  v1 = this;
  UIElement_Text::SetFontDIDHelper(this, 0x1Au, &this->m_curFontObj, 0);
  UIElement_Text::SetFontColorHelper(v1, 0x1Bu, &v1->m_curFontColor, 0);
  UIElement_Text::SetFontColorHelper(v1, 0x1Du, &v1->m_curTagFontColor, 0);
  if ( s_bChangeTextInDoFontRest )
  {
    v2 = UIElement_Text::GetPreParsedText(v1, &result);
    UIElement_Text::SetText(v1, v2);
    v3 = (char *)&result.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1].m_data[8]) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}

//----- (0046A5E0) --------------------------------------------------------  // acclient.c:167071
void __thiscall UIElement_Text::MatchElement(UIElement_Text *this, UIElement *_elem)
{
  UIElement *v2; // edi@1
  UIElement_Text *v3; // esi@1
  UIElement_Text *v4; // eax@1
  PStringBase<unsigned short> *v5; // eax@2
  char *v6; // esi@2

  v2 = _elem;
  v3 = this;
  UIElement::MatchElement((UIElement *)&this->vfptr, _elem);
  v4 = (UIElement_Text *)v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)12);
  if ( v4 )
  {
    v5 = UIElement_Text::GetPreParsedText(v4, (PStringBase<unsigned short> *)&_elem);
    UIElement_Text::SetText(v3, v5);
    v6 = (char *)&_elem[-1].m_hashListeners.m_intrusiveTable.m_numElements;
    if ( !InterlockedDecrement((volatile LONG *)&_elem[-1].m_iterListeners) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
  }
}

//----- (0046A640) --------------------------------------------------------  // acclient.c:167097
void __userpurge UIElement_Text::OnSetAttribute(UIElement_Text *this@<ecx>, int a2@<ebx>, BaseProperty *_attribute)
{
  UIElement_Text *v3; // edi@1
  BasePropertyValue *v4; // ecx@2
  BasePropertyValue *v5; // ecx@6
  IInputActionCallbackVtbl *v6; // esi@9
  int v7; // eax@9
  BasePropertyValue *v8; // ecx@10
  BasePropertyValue *v9; // ecx@13
  BasePropertyValue *v10; // ecx@16
  BasePropertyValue *v11; // ecx@19
  BasePropertyValue *v12; // ecx@22
  BasePropertyValue *v13; // ecx@25
  BasePropertyValue *v14; // ecx@28
  BasePropertyValue *v15; // ecx@31
  BasePropertyValue *v16; // ecx@35
  BasePropertyValue *v17; // ecx@38
  BasePropertyValue *v18; // ecx@41
  BasePropertyValue *v19; // ecx@44
  BasePropertyValue *v20; // ecx@47
  BasePropertyValue *v21; // ecx@54
  BasePropertyValue *v22; // ecx@57
  char v23; // al@59
  PStringBase<unsigned short> *v24; // eax@60
  BasePropertyValue *v25; // ecx@62
  BasePropertyValue *v26; // ecx@65
  unsigned int b; // [sp+8h] [bp-ACh]@7
  bool v28; // [sp+Fh] [bp-A5h]@26
  RGBAColor glyphs; // [sp+10h] [bp-A4h]@2
  PStringBase<unsigned short> result; // [sp+20h] [bp-94h]@60
  StringInfo _info; // [sp+24h] [bp-90h]@47

  v3 = this;
  UIElement_Scrollable::OnSetAttribute((UIElement_Scrollable *)&this->vfptr, a2, _attribute);
  switch ( BaseProperty::GetPropertyName(_attribute) )
  {
    case 0x22u:
      glyphs = RGBAColor_Black_37;
      v4 = _attribute->m_pcPropertyValue;
      if ( v4 )
        ((void (__stdcall *)(__int128 *))v4->vfptr[38].__vecDelDtor)(&glyphs);
      v3->m_curOutlineColor = RGBAColor::GetColor32(&glyphs);
      goto $L126298;
    case 0x1Au:
    case 0x1Bu:
    case 0x1Du:
$L126298:
      UIElement_Text::DoFontReset(v3);
      return;
    case 0x16u:
      v5 = _attribute->m_pcPropertyValue;
      if ( v5 )
        ((void (__stdcall *)(int *))v5->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetEditable(v3, b);
      goto LABEL_9;
    case 0x20u:
      v8 = _attribute->m_pcPropertyValue;
      if ( v8 )
        ((void (__stdcall *)(int *))v8->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetOneLine(v3, b);
      return;
    case 0x27u:
      v9 = _attribute->m_pcPropertyValue;
      if ( v9 )
        ((void (__stdcall *)(int *))v9->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetSelectable(v3, b);
LABEL_9:
      v6 = v3->vfptr;
      v7 = ((int (__thiscall *)(UIElement_Text *))v3->vfptr[24].OnAction)(v3);
      ((void (__thiscall *)(UIElement_Text *, int))v6[22].OnLoseFocus)(v3, v7);
      return;
    case 0x15u:
      v10 = _attribute->m_pcPropertyValue;
      if ( v10 )
        ((void (__stdcall *)(int *))v10->vfptr[42].__vecDelDtor)(&b);
      UIElement_Text::SetVerticalJustification(v3, b);
      return;
    case 0x14u:
      v11 = _attribute->m_pcPropertyValue;
      if ( v11 )
        ((void (__stdcall *)(int *))v11->vfptr[42].__vecDelDtor)(&b);
      UIElement_Text::SetHorizontalJustification(v3, b);
      return;
    case 0x1Fu:
      v12 = _attribute->m_pcPropertyValue;
      if ( v12 )
        ((void (__stdcall *)(int *))v12->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetNoIme(v3, b);
      return;
    case 0x28u:
      v13 = _attribute->m_pcPropertyValue;
      if ( v13 )
        ((void (__stdcall *)(char *))v13->vfptr[28].__vecDelDtor)(&v28);
      v3->m_glyphList.m_bTrimFromTop = v28;
      return;
    case 0x21u:
      v14 = _attribute->m_pcPropertyValue;
      if ( v14 )
        ((void (__stdcall *)(int *))v14->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetOutline(v3, b);
      return;
    case 0x25u:
      v15 = _attribute->m_pcPropertyValue;
      if ( v15 )
        ((void (__stdcall *)(int *))v15->vfptr[30].__vecDelDtor)(&b);
      v3->m_margU = b;
      goto LABEL_34;
    case 0x26u:
      v16 = _attribute->m_pcPropertyValue;
      if ( v16 )
        ((void (__stdcall *)(int *))v16->vfptr[30].__vecDelDtor)(&b);
      v3->m_margD = b;
      goto LABEL_34;
    case 0x23u:
      v17 = _attribute->m_pcPropertyValue;
      if ( v17 )
        ((void (__stdcall *)(int *))v17->vfptr[30].__vecDelDtor)(&b);
      v3->m_margL = b;
      goto LABEL_34;
    case 0x24u:
      v18 = _attribute->m_pcPropertyValue;
      if ( v18 )
        ((void (__stdcall *)(int *))v18->vfptr[30].__vecDelDtor)(&b);
      v3->m_margR = b;
LABEL_34:
      UIElement_Text::DetermineMarginValues(v3);
      UIElement_Text::SetDirty(v3, 1);
      break;
    case 0x1Eu:
      v19 = _attribute->m_pcPropertyValue;
      if ( v19 )
        ((void (__stdcall *)(int *))v19->vfptr[30].__vecDelDtor)(&b);
      v3->m_glyphList.m_nMaxCharacters = b;
      break;
    case 0x17u:
      StringInfo::StringInfo(&_info);
      v20 = _attribute->m_pcPropertyValue;
      if ( v20 )
        ((void (__stdcall *)(StringInfo *))v20->vfptr[48].__vecDelDtor)(&_info);
      if ( _info.m_Override == 1 || _info.m_stringID || _info.m_tableID.id != INVALID_DID_56.id )
      {
        UIElement_Text::SetStringInfo(v3, &_info);
        StringInfo::~StringInfo(&_info);
      }
      else
      {
        UIElement_Text::ClearAllText(v3);
        StringInfo::~StringInfo(&_info);
      }
      break;
    case 0x29u:
      v21 = _attribute->m_pcPropertyValue;
      LOBYTE(b) = 0;
      if ( v21 )
        ((void (__stdcall *)(int *))v21->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetFitToText(v3, b);
      break;
    case 0xC7u:
      StringInfo::StringInfo(&_info);
      v22 = _attribute->m_pcPropertyValue;
      if ( v22 )
        ((void (__stdcall *)(StringInfo *))v22->vfptr[48].__vecDelDtor)(&_info);
      v23 = StringInfo::IsValid(&_info, 1);
      UIElement_Text::SetTruncateTextToFit(v3, v23);
      GlyphList::Flush(&v3->m_glTruncate);
      if ( StringInfo::IsValid(&_info, 1) )
      {
        UIElement_Text::SetFontDIDNum(v3, 0);
        UIElement_Text::SetFontColorNum(v3, 0);
        *(_QWORD *)&glyphs.r = 0i64;
        LODWORD(glyphs.b) = 0;
        v24 = StringInfo::GetString(&_info, &result, 0);
        UIElement_Text::InqGlyphs(v3, v24, (SmartArray<Glyph,1> *)&glyphs);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&result);
        GlyphList::AddText(&v3->m_glTruncate, 0, (SmartArray<Glyph,1> *)&glyphs);
        GlyphList::Recalculate(&v3->m_glTruncate, 0x7FFFFFFF, 1, &v3->m_cxTrailer, &v3->m_cyTrailer);
        SmartArray<Glyph,1>::~SmartArray<Glyph,1>((SmartArray<Glyph,1> *)&glyphs);
        StringInfo::~StringInfo(&_info);
      }
      else
      {
        v3->m_cxTrailer = 0;
        v3->m_cyTrailer = 0;
        StringInfo::~StringInfo(&_info);
      }
      break;
    case 0xCBu:
      v25 = _attribute->m_pcPropertyValue;
      LOBYTE(b) = 0;
      if ( v25 )
        ((void (__stdcall *)(int *))v25->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetLoseFocusOnEscape(v3, b);
      break;
    case 0xCCu:
      v26 = _attribute->m_pcPropertyValue;
      LOBYTE(b) = 0;
      if ( v26 )
        ((void (__stdcall *)(int *))v26->vfptr[28].__vecDelDtor)(&b);
      UIElement_Text::SetLoseFocusOnAcceptInput(v3, b);
      break;
    default:
      return;
  }
}

//----- (006EB890) --------------------------------------------------------  // acclient.c:767353
int _E73_64()
{
  PStringBase<char>::PStringBase<char>(&Display_Resolution_9, "Display.Resolution");
  return atexit(_E74_48);
}

//----- (006EB8B0) --------------------------------------------------------  // acclient.c:767360
int _E76_34()
{
  PStringBase<char>::PStringBase<char>(&Display_FullScreen_9, "Display.FullScreen");
  return atexit(_E77_62);
}

//----- (006EB8D0) --------------------------------------------------------  // acclient.c:767367
int _E79_33()
{
  PStringBase<char>::PStringBase<char>(&Display_RefreshRate_9, "Display.RefreshRate");
  return atexit(_E80_34);
}

//----- (006EB8F0) --------------------------------------------------------  // acclient.c:767374
int _E82_23()
{
  PStringBase<char>::PStringBase<char>(&Display_SyncToRefresh_9, "Display.SyncToRefresh");
  return atexit(_E83_23);
}

//----- (006EB910) --------------------------------------------------------  // acclient.c:767381
void _E85_18()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_40, PFID_A8R8G8B8);
}

//----- (006EB920) --------------------------------------------------------  // acclient.c:767387
void _E103_18()
{
  LODWORD(dword_83D364) = 1053364187;
}

//----- (006EB930) --------------------------------------------------------  // acclient.c:767393
void _E105_10()
{
  outside_val_25 = 1000.0 + 1.0;
}

//----- (006EB950) --------------------------------------------------------  // acclient.c:767399
void _E107_3()
{
  block_length_25 = 24.0 * 8.0;
}

//----- (006EB970) --------------------------------------------------------  // acclient.c:767405
void _E109_14()
{
  half_square_length_25 = 24.0 * 0.5;
}

//----- (006EB990) --------------------------------------------------------  // acclient.c:767411
int _E111_12()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipEnable_5, "Misc.TooltipEnable");
  return atexit(sub_75DF90);
}

//----- (006EB9B0) --------------------------------------------------------  // acclient.c:767418
int _E114_13()
{
  PStringBase<char>::PStringBase<char>(&Misc_TooltipDelay_5, "Misc.TooltipDelay");
  return atexit(sub_75DFC0);
}

//----- (006EB9D0) --------------------------------------------------------  // acclient.c:767425
int _E1_56()
{
  return atexit(_E2_56);
}

//----- (0075DF90) --------------------------------------------------------  // acclient.c:886228
void __cdecl sub_75DF90()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipEnable_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipEnable_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DFC0) --------------------------------------------------------  // acclient.c:886241
void __cdecl sub_75DFC0()
{
  char *v0; // esi@1

  v0 = &Misc_TooltipDelay_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Misc_TooltipDelay_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075DFF0) --------------------------------------------------------  // acclient.c:886254
void __cdecl _E74_48()
{
  char *v0; // esi@1

  v0 = &Display_Resolution_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_Resolution_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E020) --------------------------------------------------------  // acclient.c:886267
void __cdecl _E77_62()
{
  char *v0; // esi@1

  v0 = &Display_FullScreen_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_FullScreen_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E050) --------------------------------------------------------  // acclient.c:886280
void __cdecl _E80_34()
{
  char *v0; // esi@1

  v0 = &Display_RefreshRate_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_RefreshRate_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0075E080) --------------------------------------------------------  // acclient.c:886293
void __cdecl _E83_23()
{
  char *v0; // esi@1

  v0 = &Display_SyncToRefresh_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Display_SyncToRefresh_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

