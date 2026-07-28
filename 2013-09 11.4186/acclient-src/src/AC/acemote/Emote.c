/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : Emote
   Object     : AC\acemote\Emote.obj
   Functions  : 13
   Addresses  : 005CDA00 - 007100F0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CDA00) --------------------------------------------------------  // acclient.c:505772
int __thiscall Emote::IsValid(Emote *this)
{
  int result; // eax@2
  int v2; // ecx@20
  int v3; // ecx@31
  bool v4; // cf@54
  bool v5; // zf@54
  unsigned int v6; // edx@57
  unsigned int v7; // esi@57
  unsigned int v8; // eax@59
  unsigned int v9; // ecx@59
  unsigned int v10; // eax@65
  unsigned int v11; // ecx@66
  unsigned int v12; // edx@69

  if ( this->delay >= 0.0 )
  {
    switch ( this->type )
    {
      case 1u:
      case 0xAu:
      case 0xDu:
      case 0x10u:
      case 0x12u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Au:
      case 0x1Fu:
      case 0x20u:
      case 0x21u:
      case 0x23u:
      case 0x24u:
      case 0x25u:
      case 0x26u:
      case 0x27u:
      case 0x28u:
      case 0x29u:
      case 0x2Au:
      case 0x2Bu:
      case 0x2Cu:
      case 0x2Du:
      case 0x2Eu:
      case 0x33u:
      case 0x3Au:
      case 0x3Cu:
      case 0x3Du:
      case 0x40u:
      case 0x41u:
      case 0x43u:
      case 0x44u:
      case 0x46u:
      case 0x4Bu:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x53u:
      case 0x54u:
      case 0x55u:
      case 0x56u:
      case 0x58u:
      case 0x6Au:
      case 0x6Bu:
      case 0x6Cu:
      case 0x6Du:
      case 0x72u:
        if ( this->extent == 0.0 )
          goto $L87484;
        goto LABEL_25;
      case 2u:
        if ( this->amount64 || this->heroxp64 )
          goto $L87481_0;
        return 0;
      case 0x3Eu:
        if ( this->amount64 )
          goto $L87481_0;
        return 0;
      case 0x70u:
      case 0x71u:
        if ( this->amount64 )
          goto $L87481_0;
        return 0;
      case 0x22u:
      case 0x2Fu:
      case 0x30u:
      case 0x77u:
      case 0x78u:
        if ( this->amount )
          goto $L87481_0;
        return 0;
      case 0xEu:
      case 0x13u:
      case 0x1Bu:
      case 0x49u:
        if ( this->spellid )
          goto $L87481_0;
        return 0;
      case 3u:
        if ( this->cprof.wcid.id != stru_8EFEEC.id )
          goto $L87481_0;
        return 0;
      case 0x4Au:
        if ( this->cprof.wcid.id == stru_8EFEEC.id )
          goto $L87484;
        v2 = this->cprof.stack_size;
        if ( !v2 )
          goto $L87484;
        if ( v2 >= -1 )
          goto $L87481_0;
        return 0;
      case 0x4Cu:
        if ( this->cprof.wcid.id == stru_8EFEEC.id || this->cprof.stack_size < 1 )
          goto $L87484;
LABEL_25:
        if ( this->msg.m_buffer->m_len != 1 )
          goto $L87481_0;
        return 0;
      case 0x59u:
        if ( this->amount < 1 )
          goto $L87484;
        if ( this->msg.m_buffer->m_len != 1 )
          goto $L87481_0;
        return 0;
      case 0x38u:
        if ( this->wealth_rating > 8 )
          goto $L87484;
        v3 = this->treasure_type;
        if ( v3 < 0 )
          goto $L87484;
        if ( v3 <= 3 )
          goto $L87481_0;
        return 0;
      case 5u:
      case 0x34u:
        if ( this->extent < 0.0 )
          goto $L87484;
        if ( this->motion )
          goto $L87481_0;
        return 0;
      case 4u:
      case 0xBu:
        if ( this->frame.m_fOrigin.x != 0.0 || this->frame.m_fOrigin.y != 0.0 )
          goto $L87484;
        if ( this->frame.m_fOrigin.z == 0.0 )
          goto $L87481_0;
        return 0;
      case 7u:
        if ( this->extent < 0.0 || this->extent > 1.0 )
          goto $L87484;
        if ( this->pscript )
          goto $L87481_0;
        return 0;
      case 8u:
      case 0x11u:
        if ( this->extent >= 0.0 )
          goto $L87481_0;
        return 0;
      case 9u:
        if ( this->extent <= 0.0 || this->extent > 1.0 )
          goto $L87484;
        if ( this->sound )
          goto $L87481_0;
        return 0;
      case 0x1Cu:
      case 0x1Du:
      case 0x36u:
      case 0x37u:
        if ( this->amount )
          goto $L87468;
        goto $L87484;
      case 0x35u:
      case 0x45u:
      case 0x5Bu:
      case 0x5Cu:
      case 0x5Du:
      case 0x5Eu:
      case 0x5Fu:
      case 0x60u:
      case 0x61u:
      case 0x62u:
      case 0x6Eu:
      case 0x73u:
      case 0x76u:
$L87468:
        if ( this->stat )
          goto $L87481_0;
        return 0;
      case 0x6Fu:
        v4 = this->amount < 1;
        v5 = this->amount == 1;
        goto LABEL_55;
      default:
        goto $L87484;
      case 0x31u:
        v6 = HIDWORD(this->min64);
        v7 = LODWORD(this->min64);
        if ( !v6 && !v7 )
          goto $L87481_0;
        v8 = LODWORD(this->max64);
        v9 = HIDWORD(this->max64);
        if ( !v9 && !v8 )
          goto $L87481_0;
        if ( v6 < v9 )
          goto $L87481_0;
        if ( v6 > v9 )
          goto $L87484;
        v4 = v7 < v8;
        v5 = v7 == v8;
        goto LABEL_55;
      case 0x32u:
        if ( !this->stat )
          goto $L87484;
        v10 = this->min;
        if ( !v10 )
          goto $L87481_0;
        v11 = this->max;
        if ( !v11 )
          goto $L87481_0;
        v4 = v10 < v11;
        v5 = v10 == v11;
        goto LABEL_55;
      case 0x1Eu:
      case 0x3Bu:
      case 0x47u:
      case 0x52u:
        if ( this->msg.m_buffer->m_len == 1 )
          goto $L87484;
        v12 = this->min;
        v4 = v12 < this->max;
        v5 = v12 == this->max;
LABEL_55:
        if ( !v4 && !v5 )
          goto $L87484;
        goto $L87481_0;
      case 0x66u:
      case 0x67u:
      case 0x68u:
      case 0x69u:
      case 0x79u:
        if ( this->msg.m_buffer->m_len != 1 )
          goto $L87481_0;
$L87484:
        result = 0;
        break;
      case 6u:
      case 0xCu:
      case 0xFu:
      case 0x39u:
      case 0x3Fu:
      case 0x42u:
      case 0x48u:
      case 0x4Du:
      case 0x4Eu:
      case 0x57u:
      case 0x5Au:
      case 0x63u:
      case 0x64u:
      case 0x65u:
      case 0x74u:
      case 0x75u:
$L87481_0:
        result = 1;
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005CDDA0) --------------------------------------------------------  // acclient.c:506048
void __thiscall Emote::Emote(Emote *this)
{
  Emote *v1; // esi@1
  int v2; // ecx@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  int v5; // ecx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&Emote::vftable;
  CreationProfile::CreationProfile(&this->cprof);
  v2 = (int)&v1->frame;
  *(_DWORD *)v2 = 1065353216;
  *(_DWORD *)(v2 + 4) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 52) = 0;
  *(_DWORD *)(v2 + 56) = 0;
  *(_DWORD *)(v2 + 60) = 0;
  Frame::cache(&v1->frame);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->teststring.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->msg.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (int)&v1->mPosition.frame;
  v1->mPosition.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->mPosition.objcell_id = 0;
  *(_DWORD *)v5 = 1065353216;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  *(_DWORD *)(v5 + 60) = 0;
  Frame::cache(&v1->mPosition.frame);
  v1->type = 0;
  LODWORD(v1->delay) = 0;
  v1->amount = 0;
  LODWORD(v1->amount64) = 0;
  HIDWORD(v1->amount64) = 0;
  LODWORD(v1->heroxp64) = 0;
  HIDWORD(v1->heroxp64) = 0;
  v1->max = 0;
  v1->min = 0;
  LODWORD(v1->max64) = 0;
  HIDWORD(v1->max64) = 0;
  LODWORD(v1->min64) = 0;
  HIDWORD(v1->min64) = 0;
  LODWORD(v1->fmax) = 0;
  HIDWORD(v1->fmax) = 0;
  LODWORD(v1->fmin) = 0;
  HIDWORD(v1->fmin) = 0;
  v1->stat = 0;
  v1->motion = 0;
  v1->pscript = 0;
  v1->sound = 0;
  v1->spellid = 0;
  LODWORD(v1->percent) = 0;
  HIDWORD(v1->percent) = 0;
  v1->display = 0;
  v1->wealth_rating = 0;
  v1->treasure_class = 0;
  v1->treasure_type = 0;
  LODWORD(v1->extent) = 1065353216;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E8454: using guessed type int (__thiscall *Emote::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005CDEB0) --------------------------------------------------------  // acclient.c:506120
void __thiscall Emote::~Emote(Emote *this)
{
  Emote *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@4

  v1 = this;
  v2 = this->msg.m_buffer;
  this->vfptr = (PackObjVtbl *)&Emote::vftable;
  this->mPosition.vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  v3 = v1->teststring.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->cprof.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E8454: using guessed type int (__thiscall *Emote::vftable)(void *, char);

//----- (005CDF10) --------------------------------------------------------  // acclient.c:506142
Emote *__thiscall Emote::scalar_deleting_destructor(Emote *this, unsigned int a2)
{
  Emote *v2; // esi@1

  v2 = this;
  Emote::~Emote(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (005CDF30) --------------------------------------------------------  // acclient.c:506154
int __thiscall Emote::operator=(int this, int a2)
{
  int v2; // esi@1
  int v3; // ebx@2
  int v4; // eax@6
  int v5; // ebx@7
  int v6; // eax@11

  v2 = this;
  if ( this != a2 )
  {
    *(_DWORD *)(this + 4) = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(this + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
    *(_DWORD *)(this + 36) = *(_DWORD *)(a2 + 36);
    *(_DWORD *)(this + 56) = *(_DWORD *)(a2 + 56);
    *(_DWORD *)(this + 60) = *(_DWORD *)(a2 + 60);
    *(_DWORD *)(this + 40) = *(_DWORD *)(a2 + 40);
    *(_DWORD *)(this + 44) = *(_DWORD *)(a2 + 44);
    *(_DWORD *)(this + 48) = *(_DWORD *)(a2 + 48);
    *(_DWORD *)(this + 52) = *(_DWORD *)(a2 + 52);
    *(_DWORD *)(this + 64) = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(this + 68) = *(_DWORD *)(a2 + 68);
    *(_DWORD *)(this + 72) = *(_DWORD *)(a2 + 72);
    *(_DWORD *)(this + 76) = *(_DWORD *)(a2 + 76);
    *(_DWORD *)(this + 80) = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(this + 84) = *(_DWORD *)(a2 + 84);
    *(_DWORD *)(this + 88) = *(_DWORD *)(a2 + 88);
    *(_DWORD *)(this + 92) = *(_DWORD *)(a2 + 92);
    CreationProfile::operator=(this + 96, a2 + 96);
    Frame::operator=(v2 + 124, a2 + 124);
    *(_DWORD *)(v2 + 188) = *(_DWORD *)(a2 + 188);
    v3 = *(_DWORD *)(v2 + 192);
    if ( v3 != *(_DWORD *)(a2 + 192) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
      v4 = *(_DWORD *)(a2 + 192);
      *(_DWORD *)(v2 + 192) = v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    v5 = *(_DWORD *)(v2 + 196);
    if ( v5 != *(_DWORD *)(a2 + 196) )
    {
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      v6 = *(_DWORD *)(a2 + 196);
      *(_DWORD *)(v2 + 196) = v6;
      InterlockedIncrement((volatile LONG *)(v6 + 4));
    }
    *(_DWORD *)(v2 + 200) = *(_DWORD *)(a2 + 200);
    *(_DWORD *)(v2 + 204) = *(_DWORD *)(a2 + 204);
    *(_DWORD *)(v2 + 208) = *(_DWORD *)(a2 + 208);
    *(_DWORD *)(v2 + 212) = *(_DWORD *)(a2 + 212);
    *(_DWORD *)(v2 + 216) = *(_DWORD *)(a2 + 216);
    *(_DWORD *)(v2 + 220) = *(_DWORD *)(a2 + 220);
    *(_DWORD *)(v2 + 228) = *(_DWORD *)(a2 + 228);
    Frame::operator=(v2 + 232, a2 + 232);
  }
  return v2;
}

//----- (005CE0E0) --------------------------------------------------------  // acclient.c:506221
int __thiscall Emote::pack_size(Emote *this)
{
  Emote *v1; // esi@1
  unsigned int v2; // ecx@1
  int result; // eax@1
  int v4; // edi@6
  int v5; // esi@6
  int v6; // edi@13
  void *foo; // [sp+0h] [bp-4h]@1

  foo = this;
  v1 = this;
  v2 = this->type - 1;
  foo = 0;
  result = 12;
  switch ( v2 )
  {
    case 0u:
    case 7u:
    case 9u:
    case 0xCu:
    case 0xFu:
    case 0x10u:
    case 0x11u:
    case 0x13u:
    case 0x14u:
    case 0x15u:
    case 0x16u:
    case 0x17u:
    case 0x18u:
    case 0x19u:
    case 0x1Eu:
    case 0x32u:
    case 0x39u:
    case 0x3Bu:
    case 0x3Cu:
    case 0x3Fu:
    case 0x40u:
    case 0x42u:
    case 0x43u:
    case 0x4Eu:
    case 0x4Fu:
    case 0x50u:
    case 0x52u:
    case 0x57u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 12;
      break;
    case 0x1Du:
    case 0x3Au:
    case 0x46u:
    case 0x51u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 20;
      break;
    case 1u:
    case 0x3Du:
      result = 28;
      break;
    case 2u:
    case 0x49u:
      result = ((int (__thiscall *)(int, void **, _DWORD))v1->cprof.vfptr->Pack)(&v1->cprof, &foo, 0) + 12;
      break;
    case 0x4Bu:
      v4 = (int)&v1->cprof;
      v5 = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0);
      result = v5 + (*(int (__thiscall **)(int, void **, _DWORD))(*(_DWORD *)v4 + 12))(v4, &foo, 0) + 12;
      break;
    case 0x58u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 16;
      break;
    case 0x37u:
    case 0x72u:
    case 0x75u:
      result = 24;
      break;
    case 3u:
    case 5u:
    case 0xAu:
    case 0x56u:
      result = Frame::Pack(&v1->frame, &foo, 0) + 12;
      break;
    case 0x1Bu:
    case 0x1Cu:
    case 0x34u:
    case 0x35u:
    case 0x36u:
    case 0x44u:
    case 0x6Fu:
    case 0x70u:
      result = 20;
      break;
    case 4u:
    case 6u:
    case 8u:
    case 0xDu:
    case 0x12u:
    case 0x1Au:
    case 0x21u:
    case 0x2Eu:
    case 0x2Fu:
    case 0x33u:
    case 0x48u:
    case 0x59u:
    case 0x6Du:
    case 0x6Eu:
    case 0x76u:
    case 0x77u:
      result = 16;
      break;
    case 0x1Fu:
    case 0x20u:
    case 0x22u:
    case 0x2Cu:
    case 0x2Du:
    case 0x45u:
    case 0x53u:
    case 0x54u:
    case 0x55u:
    case 0x65u:
    case 0x66u:
    case 0x67u:
    case 0x68u:
    case 0x69u:
    case 0x6Au:
    case 0x6Bu:
    case 0x6Cu:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 16;
      break;
    case 0x25u:
    case 0x4Au:
      v6 = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 12;
      result = v6 + AC1Legacy::PStringBase<char>::Pack(&v1->teststring, &foo, 0) + 4;
      break;
    case 0x23u:
    case 0x26u:
    case 0x27u:
    case 0x28u:
    case 0x29u:
    case 0x2Au:
    case 0x2Bu:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 24;
      break;
    case 0x78u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 12;
      break;
    case 0x71u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 32;
      break;
    case 0x24u:
      result = AC1Legacy::PStringBase<char>::Pack(&v1->msg, &foo, 0) + 32;
      break;
    case 0x30u:
      result = 40;
      break;
    case 0x31u:
      result = 36;
      break;
    case 0x3Eu:
    case 0x62u:
    case 0x63u:
      result = ((int (__thiscall *)(int, void **, _DWORD))v1->mPosition.vfptr->Pack)(&v1->mPosition, &foo, 0) + 12;
      break;
    default:
      return result;
  }
  return result;
}

//----- (005CE380) --------------------------------------------------------  // acclient.c:506389
int __thiscall Emote::Pack(Emote *this, void **addr, unsigned int size)
{
  Emote *v3; // edi@1
  int v4; // ebp@1
  char *v5; // edx@2
  char *v6; // ecx@2
  char *v7; // eax@2
  char *v9; // ecx@5
  char *v10; // ecx@6
  char *v11; // ecx@7
  char *v12; // ecx@8
  char *v13; // ecx@9
  char *v14; // edx@16
  char *v15; // ecx@16
  char *v16; // ecx@21
  char *v17; // edx@25
  char *v18; // ecx@25
  void *v19; // eax@26
  char *v20; // edx@26
  char *v21; // ecx@26
  char *v22; // edx@27
  char *v23; // ecx@27
  char *v24; // ebx@28
  char *v25; // edx@28
  char *v26; // ecx@28
  char *v27; // eax@29
  char *v28; // ebx@29
  char *v29; // edx@29

  v3 = this;
  v4 = Emote::pack_size(this);
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->type;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->delay;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->extent;
    v7 = (char *)*addr + 4;
    *addr = v7;
    switch ( v3->type )
    {
      case 1u:
      case 8u:
      case 0xAu:
      case 0xDu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Au:
      case 0x1Fu:
      case 0x33u:
      case 0x3Au:
      case 0x3Cu:
      case 0x3Du:
      case 0x40u:
      case 0x41u:
      case 0x43u:
      case 0x44u:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x53u:
      case 0x58u:
      case 0x79u:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        return v4;
      case 0x20u:
      case 0x21u:
      case 0x46u:
      case 0x54u:
      case 0x55u:
      case 0x56u:
      case 0x66u:
      case 0x67u:
      case 0x68u:
      case 0x69u:
      case 0x6Au:
      case 0x6Bu:
      case 0x6Cu:
      case 0x6Du:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        *(_DWORD *)*addr = v3->amount;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x35u:
      case 0x36u:
      case 0x37u:
      case 0x45u:
        *(_DWORD *)v7 = v3->stat;
        v9 = (char *)*addr + 4;
        *addr = v9;
        *(_DWORD *)v9 = v3->amount;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x73u:
        *(_DWORD *)v7 = v3->stat;
        v10 = (char *)*addr + 4;
        *addr = v10;
        *(_DWORD *)v10 = LODWORD(v3->amount64);
        *((_DWORD *)v10 + 1) = HIDWORD(v3->amount64);
        *addr = (char *)*addr + 8;
        return v4;
      case 0x76u:
        *(_DWORD *)v7 = v3->stat;
        v11 = (char *)*addr + 4;
        *addr = v11;
        *(double *)v11 = v3->percent;
        *addr = (char *)*addr + 8;
        return v4;
      case 0x1Eu:
      case 0x3Bu:
      case 0x47u:
      case 0x52u:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        *(_DWORD *)*addr = v3->min;
        v12 = (char *)*addr + 4;
        *addr = v12;
        *(_DWORD *)v12 = v3->max;
        *addr = (char *)*addr + 4;
        return v4;
      case 2u:
      case 0x3Eu:
        *(_DWORD *)v7 = LODWORD(v3->amount64);
        *((_DWORD *)v7 + 1) = HIDWORD(v3->amount64);
        v13 = (char *)*addr + 8;
        *addr = v13;
        *(_DWORD *)v13 = LODWORD(v3->heroxp64);
        *((_DWORD *)v13 + 1) = HIDWORD(v3->heroxp64);
        *addr = (char *)*addr + 8;
        return v4;
      case 0x70u:
      case 0x71u:
        *(_DWORD *)v7 = LODWORD(v3->amount64);
        *((_DWORD *)v7 + 1) = HIDWORD(v3->amount64);
        *addr = (char *)*addr + 8;
        return v4;
      case 0x22u:
      case 0x2Fu:
      case 0x30u:
      case 0x5Au:
      case 0x6Fu:
      case 0x77u:
      case 0x78u:
        *(_DWORD *)v7 = v3->amount;
        *addr = (char *)*addr + 4;
        return v4;
      case 0xEu:
      case 0x13u:
      case 0x1Bu:
      case 0x49u:
        *(_DWORD *)v7 = v3->spellid;
        *addr = (char *)*addr + 4;
        return v4;
      case 3u:
      case 0x4Au:
        ((void (__thiscall *)(int, void **, unsigned int))v3->cprof.vfptr->Pack)(&v3->cprof, addr, size);
        return v4;
      case 0x4Cu:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->cprof.vfptr->Pack)(&v3->cprof, addr, size);
        return v4;
      case 0x59u:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        *(_DWORD *)*addr = v3->amount;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x38u:
        *(_DWORD *)v7 = v3->wealth_rating;
        v14 = (char *)*addr + 4;
        *addr = v14;
        *(_DWORD *)v14 = v3->treasure_class;
        v15 = (char *)*addr + 4;
        *addr = v15;
        *(_DWORD *)v15 = v3->treasure_type;
        *addr = (char *)*addr + 4;
        return v4;
      case 5u:
      case 0x34u:
        *(_DWORD *)v7 = v3->motion;
        *addr = (char *)*addr + 4;
        return v4;
      case 4u:
      case 6u:
      case 0xBu:
      case 0x57u:
        Frame::Pack(&v3->frame, addr, size);
        return v4;
      case 7u:
        *(_DWORD *)v7 = v3->pscript;
        *addr = (char *)*addr + 4;
        return v4;
      case 9u:
        *(_DWORD *)v7 = v3->sound;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x1Cu:
      case 0x1Du:
        *(_DWORD *)v7 = v3->amount;
        v16 = (char *)*addr + 4;
        *addr = v16;
        *(_DWORD *)v16 = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x23u:
      case 0x2Du:
      case 0x2Eu:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        v7 = (char *)*addr;
        goto $L87288;
      case 0x6Eu:
$L87288:
        *(_DWORD *)v7 = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x26u:
      case 0x4Bu:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        AC1Legacy::PStringBase<char>::Pack(&v3->teststring, addr, size);
        *(_DWORD *)*addr = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x24u:
      case 0x27u:
      case 0x28u:
      case 0x29u:
      case 0x2Au:
      case 0x2Bu:
      case 0x2Cu:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        *(_DWORD *)*addr = v3->min;
        v17 = (char *)*addr + 4;
        *addr = v17;
        *(_DWORD *)v17 = v3->max;
        v18 = (char *)*addr + 4;
        *addr = v18;
        *(_DWORD *)v18 = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x72u:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        v19 = *addr;
        *(_DWORD *)v19 = LODWORD(v3->min64);
        *((_DWORD *)v19 + 1) = HIDWORD(v3->min64);
        v20 = (char *)*addr + 8;
        *addr = v20;
        *(_DWORD *)v20 = LODWORD(v3->max64);
        *((_DWORD *)v20 + 1) = HIDWORD(v3->max64);
        v21 = (char *)*addr + 8;
        *addr = v21;
        *(_DWORD *)v21 = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x25u:
        AC1Legacy::PStringBase<char>::Pack(&v3->msg, addr, size);
        *(double *)*addr = v3->fmin;
        v22 = (char *)*addr + 8;
        *addr = v22;
        *(double *)v22 = v3->fmax;
        v23 = (char *)*addr + 8;
        *addr = v23;
        *(_DWORD *)v23 = v3->stat;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x31u:
        *(double *)v7 = v3->percent;
        v24 = (char *)*addr + 8;
        *addr = v24;
        *(_DWORD *)v24 = LODWORD(v3->min64);
        *((_DWORD *)v24 + 1) = HIDWORD(v3->min64);
        v25 = (char *)*addr + 8;
        *addr = v25;
        *(_DWORD *)v25 = LODWORD(v3->max64);
        *((_DWORD *)v25 + 1) = HIDWORD(v3->max64);
        v26 = (char *)*addr + 8;
        goto LABEL_30;
      case 0x32u:
        *(_DWORD *)v7 = v3->stat;
        v27 = (char *)*addr + 4;
        *addr = v27;
        *(double *)v27 = v3->percent;
        v28 = (char *)*addr + 8;
        *addr = v28;
        *(_DWORD *)v28 = v3->min;
        v29 = (char *)*addr + 4;
        *addr = v29;
        *(_DWORD *)v29 = v3->max;
        v26 = (char *)*addr + 4;
LABEL_30:
        *addr = v26;
        *(_DWORD *)v26 = v3->display;
        *addr = (char *)*addr + 4;
        return v4;
      case 0x3Fu:
        ((void (__thiscall *)(int, void **, unsigned int))v3->mPosition.vfptr->Pack)(&v3->mPosition, addr, size);
        return v4;
      case 0x63u:
      case 0x64u:
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))v3->mPosition.vfptr->Pack)(&v3->mPosition, addr, size);
        return v4;
      default:
        return v4;
    }
  }
  return v4;
}

//----- (005CE8C0) --------------------------------------------------------  // acclient.c:506705
void __thiscall Emote::Emote(Emote *this, Emote *rhs)
{
  int v2; // esi@1
  int v3; // ecx@1
  volatile LONG *v4; // ST00_4@1
  volatile LONG *v5; // ST00_4@1
  int v6; // ecx@1

  v2 = (int)this;
  this->vfptr = (PackObjVtbl *)&Emote::vftable;
  CreationProfile::CreationProfile(&this->cprof);
  v3 = v2 + 124;
  *(_DWORD *)v3 = 1065353216;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 52) = 0;
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  Frame::cache((Frame *)(v2 + 124));
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  *(_DWORD *)(v2 + 192) = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  *(_DWORD *)(v2 + 196) = AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v5);
  v6 = v2 + 232;
  *(_DWORD *)(v2 + 224) = &Position::vftable;
  *(_DWORD *)(v2 + 228) = 0;
  *(_DWORD *)v6 = 1065353216;
  *(_DWORD *)(v6 + 4) = 0;
  *(_DWORD *)(v6 + 8) = 0;
  *(_DWORD *)(v6 + 12) = 0;
  *(_DWORD *)(v6 + 52) = 0;
  *(_DWORD *)(v6 + 56) = 0;
  *(_DWORD *)(v6 + 60) = 0;
  Frame::cache((Frame *)(v2 + 232));
  Emote::operator=(v2, (int)rhs);
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 7E8454: using guessed type int (__thiscall *Emote::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005CE970) --------------------------------------------------------  // acclient.c:506749
int __thiscall Emote::UnPack(Emote *this, void **addr, unsigned int size)
{
  Emote *v3; // edi@1
  char *v4; // edx@2
  char *v5; // ecx@2
  char *v6; // eax@2
  int v7; // eax@4
  int result; // eax@7
  char *v9; // ecx@8
  char *v10; // ecx@9
  char *v11; // ecx@11
  char *v12; // ecx@14
  char *v13; // ecx@16
  unsigned int v14; // eax@23
  int v15; // ecx@25
  int v16; // eax@31
  char *v17; // edx@32
  char *v18; // ecx@32
  char *v19; // ecx@42
  int v20; // eax@52
  char *v21; // edx@57
  char *v22; // ecx@57
  void *v23; // eax@60
  char *v24; // edx@60
  char *v25; // ecx@60
  void *v26; // eax@63
  char *v27; // edx@63
  char *v28; // ecx@63
  char *v29; // ebx@64
  char *v30; // edx@64
  char *v31; // ecx@64
  char *v32; // eax@65
  char *v33; // ebx@65
  char *v34; // edx@65
  void *foo; // [sp+10h] [bp-8h]@1
  unsigned int calcSize; // [sp+14h] [bp-4h]@29

  v3 = this;
  foo = 0;
  if ( size < 0xC )
  {
LABEL_28:
    result = 0;
  }
  else
  {
    this->type = *(_DWORD *)*addr;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->delay) = *(_DWORD *)v4;
    v5 = (char *)*addr + 4;
    *addr = v5;
    LODWORD(v3->extent) = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    switch ( v3->type )
    {
      case 1u:
      case 8u:
      case 0xAu:
      case 0xDu:
      case 0x10u:
      case 0x11u:
      case 0x12u:
      case 0x14u:
      case 0x15u:
      case 0x16u:
      case 0x17u:
      case 0x18u:
      case 0x19u:
      case 0x1Au:
      case 0x1Fu:
      case 0x33u:
      case 0x3Au:
      case 0x3Cu:
      case 0x3Du:
      case 0x40u:
      case 0x41u:
      case 0x43u:
      case 0x44u:
      case 0x4Fu:
      case 0x50u:
      case 0x51u:
      case 0x53u:
      case 0x58u:
      case 0x79u:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12 )
          goto LABEL_28;
        v7 = AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size);
        goto LABEL_27;
      case 0x20u:
      case 0x21u:
      case 0x46u:
      case 0x54u:
      case 0x55u:
      case 0x56u:
      case 0x59u:
      case 0x66u:
      case 0x67u:
      case 0x68u:
      case 0x69u:
      case 0x6Au:
      case 0x6Bu:
      case 0x6Cu:
      case 0x6Du:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v3->amount = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x35u:
      case 0x36u:
      case 0x37u:
      case 0x45u:
        v3->stat = *(_DWORD *)v6;
        v9 = (char *)*addr + 4;
        *addr = v9;
        v3->amount = *(_DWORD *)v9;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x73u:
        v3->stat = *(_DWORD *)v6;
        v10 = (char *)*addr + 4;
        *addr = v10;
        v6 = v10;
        goto LABEL_10;
      case 0x76u:
        v3->stat = *(_DWORD *)v6;
        v11 = (char *)*addr + 4;
        *addr = v11;
        LODWORD(v3->percent) = *(_DWORD *)v11;
        HIDWORD(v3->percent) = *((_DWORD *)v11 + 1);
        *addr = (char *)*addr + 8;
        return Emote::IsValid(v3);
      case 0x1Eu:
      case 0x3Bu:
      case 0x47u:
      case 0x52u:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 20
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v3->min = *(_DWORD *)*addr;
        v12 = (char *)*addr + 4;
        *addr = v12;
        v3->max = *(_DWORD *)v12;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 2u:
      case 0x3Eu:
        if ( size < 0x1C )
          goto LABEL_28;
        LODWORD(v3->amount64) = *(_DWORD *)v6;
        HIDWORD(v3->amount64) = *((_DWORD *)v6 + 1);
        v13 = (char *)*addr + 8;
        *addr = v13;
        LODWORD(v3->heroxp64) = *(_DWORD *)v13;
        HIDWORD(v3->heroxp64) = *((_DWORD *)v13 + 1);
        *addr = (char *)*addr + 8;
        return Emote::IsValid(v3);
      case 0x70u:
      case 0x71u:
        if ( size < 0x14 )
          goto LABEL_28;
LABEL_10:
        LODWORD(v3->amount64) = *(_DWORD *)v6;
        HIDWORD(v3->amount64) = *((_DWORD *)v6 + 1);
        *addr = (char *)*addr + 8;
        return Emote::IsValid(v3);
      case 0x22u:
      case 0x2Fu:
      case 0x30u:
      case 0x5Au:
      case 0x77u:
      case 0x78u:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->amount = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0xEu:
      case 0x13u:
      case 0x1Bu:
      case 0x49u:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->spellid = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 3u:
      case 0x4Au:
        v14 = ((int (__thiscall *)(int, void **, _DWORD))v3->cprof.vfptr->Pack)(&v3->cprof, &foo, 0) + 12;
        goto LABEL_24;
      default:
        goto LABEL_28;
      case 0x4Cu:
        calcSize = AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12;
        if ( size < calcSize || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v16 = ((int (__thiscall *)(CreationProfile *, void **, _DWORD))v3->cprof.vfptr->Pack)(&v3->cprof, &foo, 0);
        v14 = calcSize + v16;
LABEL_24:
        if ( size < v14 )
          goto LABEL_28;
        v15 = (int)&v3->cprof;
        goto LABEL_26;
      case 0x38u:
        v3->wealth_rating = *(_DWORD *)v6;
        v17 = (char *)*addr + 4;
        *addr = v17;
        v3->treasure_class = *(_DWORD *)v17;
        v18 = (char *)*addr + 4;
        *addr = v18;
        v3->treasure_type = *(_DWORD *)v18;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 5u:
      case 0x34u:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->motion = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 4u:
      case 6u:
      case 0xBu:
      case 0x57u:
        if ( size < Frame::Pack(&v3->frame, &foo, 0) + 12 )
          goto LABEL_28;
        Frame::UnPack(&v3->frame, addr, size);
        return Emote::IsValid(v3);
      case 7u:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->pscript = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 9u:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->sound = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x1Cu:
      case 0x1Du:
        if ( size < 0x14 )
          goto LABEL_28;
        v3->amount = *(_DWORD *)v6;
        v19 = (char *)*addr + 4;
        *addr = v19;
        v3->stat = *(_DWORD *)v19;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x6Eu:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->stat = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x6Fu:
        if ( size < 0x10 )
          goto LABEL_28;
        v3->amount = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x23u:
      case 0x2Du:
      case 0x2Eu:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v3->stat = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x26u:
      case 0x4Bu:
        calcSize = AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12;
        if ( size < calcSize )
          goto LABEL_28;
        if ( !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v20 = AC1Legacy::PStringBase<char>::Pack(&v3->teststring, &foo, 0);
        if ( size < calcSize + v20 || !AC1Legacy::PStringBase<char>::UnPack(&v3->teststring, addr, size) )
          goto LABEL_28;
        v3->stat = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x24u:
      case 0x27u:
      case 0x28u:
      case 0x29u:
      case 0x2Au:
      case 0x2Bu:
      case 0x2Cu:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v3->min = *(_DWORD *)*addr;
        v21 = (char *)*addr + 4;
        *addr = v21;
        v3->max = *(_DWORD *)v21;
        v22 = (char *)*addr + 4;
        *addr = v22;
        v3->stat = *(_DWORD *)v22;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x72u:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v23 = *addr;
        LODWORD(v3->min64) = *(_DWORD *)*addr;
        HIDWORD(v3->min64) = *((_DWORD *)v23 + 1);
        v24 = (char *)*addr + 8;
        *addr = v24;
        LODWORD(v3->max64) = *(_DWORD *)v24;
        HIDWORD(v3->max64) = *((_DWORD *)v24 + 1);
        v25 = (char *)*addr + 8;
        *addr = v25;
        v3->stat = *(_DWORD *)v25;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x25u:
        if ( size < AC1Legacy::PStringBase<char>::Pack(&v3->msg, &foo, 0) + 12
          || !AC1Legacy::PStringBase<char>::UnPack(&v3->msg, addr, size) )
          goto LABEL_28;
        v26 = *addr;
        LODWORD(v3->fmin) = *(_DWORD *)*addr;
        HIDWORD(v3->fmin) = *((_DWORD *)v26 + 1);
        v27 = (char *)*addr + 8;
        *addr = v27;
        LODWORD(v3->fmax) = *(_DWORD *)v27;
        HIDWORD(v3->fmax) = *((_DWORD *)v27 + 1);
        v28 = (char *)*addr + 8;
        *addr = v28;
        v3->stat = *(_DWORD *)v28;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x31u:
        LODWORD(v3->percent) = *(_DWORD *)v6;
        HIDWORD(v3->percent) = *((_DWORD *)v6 + 1);
        v29 = (char *)*addr + 8;
        *addr = v29;
        LODWORD(v3->min64) = *(_DWORD *)v29;
        HIDWORD(v3->min64) = *((_DWORD *)v29 + 1);
        v30 = (char *)*addr + 8;
        *addr = v30;
        LODWORD(v3->max64) = *(_DWORD *)v30;
        HIDWORD(v3->max64) = *((_DWORD *)v30 + 1);
        v31 = (char *)*addr + 8;
        goto LABEL_66;
      case 0x32u:
        v3->stat = *(_DWORD *)v6;
        v32 = (char *)*addr + 4;
        *addr = v32;
        LODWORD(v3->percent) = *(_DWORD *)v32;
        HIDWORD(v3->percent) = *((_DWORD *)v32 + 1);
        v33 = (char *)*addr + 8;
        *addr = v33;
        v3->min = *(_DWORD *)v33;
        v34 = (char *)*addr + 4;
        *addr = v34;
        v3->max = *(_DWORD *)v34;
        v31 = (char *)*addr + 4;
LABEL_66:
        *addr = v31;
        v3->display = *(_DWORD *)v31;
        *addr = (char *)*addr + 4;
        return Emote::IsValid(v3);
      case 0x3Fu:
        if ( size < ((int (__thiscall *)(int, void **, _DWORD))v3->mPosition.vfptr->Pack)(&v3->mPosition, &foo, 0) + 12 )
          goto LABEL_28;
        v15 = (int)&v3->mPosition;
LABEL_26:
        v7 = (*(int (__stdcall **)(void **, unsigned int))(*(_DWORD *)v15 + 16))(addr, size);
LABEL_27:
        if ( !v7 )
          goto LABEL_28;
        goto $L87390;
      case 0x63u:
      case 0x64u:
        if ( size >= ((int (__thiscall *)(Position *, void **, _DWORD))v3->mPosition.vfptr->Pack)(
                       &v3->mPosition,
                       &foo,
                       0)
                   + 12
          && ((int (__thiscall *)(int, void **, unsigned int))v3->mPosition.vfptr->UnPack)(&v3->mPosition, addr, size) )
          goto $L87390;
        goto LABEL_28;
      case 0u:
      case 0xCu:
      case 0xFu:
      case 0x39u:
      case 0x42u:
      case 0x48u:
      case 0x4Du:
      case 0x4Eu:
      case 0x65u:
      case 0x74u:
      case 0x75u:
$L87390:
        result = Emote::IsValid(v3);
        break;
    }
  }
  return result;
}

//----- (00710090) --------------------------------------------------------  // acclient.c:803313
void sub_710090()
{
  flt_8EFEE0 = 1000.0 + 1.0;
}

//----- (007100B0) --------------------------------------------------------  // acclient.c:803319
void sub_7100B0()
{
  flt_8EFEE4 = 24.0 * 8.0;
}

//----- (007100D0) --------------------------------------------------------  // acclient.c:803325
void sub_7100D0()
{
  flt_8EFEE8 = 24.0 * 0.5;
}

//----- (007100F0) --------------------------------------------------------  // acclient.c:803331
int sub_7100F0()
{
  return atexit(nullsub_1837);
}

