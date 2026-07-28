/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : vlong
   Object     : PORTAL\vlong\vlong.obj
   Functions  : 25
   Addresses  : 005B0280 - 005B0F10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005B0280) --------------------------------------------------------  // acclient.c:474897
void __thiscall AC1Legacy::flex_unit::reserve(AC1Legacy::flex_unit *this, unsigned int x)
{
  AC1Legacy::flex_unit *v2; // esi@1
  void *v3; // edi@2
  unsigned int v4; // eax@2

  v2 = this;
  if ( x > this->z )
  {
    v3 = operator new[](4 * x);
    v4 = 0;
    if ( v2->n )
    {
      do
      {
        *((_DWORD *)v3 + v4) = v2->a[v4];
        ++v4;
      }
      while ( v4 < v2->n );
    }
    operator delete[](v2->a);
    v2->a = (unsigned int *)v3;
    v2->z = x;
  }
}

//----- (005B02E0) --------------------------------------------------------  // acclient.c:474924
void __thiscall AC1Legacy::flex_unit::set(AC1Legacy::flex_unit *this, unsigned int i, unsigned int x)
{
  AC1Legacy::flex_unit *v3; // esi@1
  unsigned int *v4; // ecx@4
  unsigned int v5; // eax@5
  int v6; // eax@6
  unsigned int j; // eax@9

  v3 = this;
  if ( i >= this->n )
  {
    if ( x )
    {
      AC1Legacy::flex_unit::reserve(this, i + 1);
      for ( j = v3->n; j < i; ++j )
        v3->a[j] = 0;
      v3->a[i] = x;
      v3->n = i + 1;
    }
  }
  else
  {
    this->a[i] = x;
    if ( !x && this->n )
    {
      v4 = this->a;
      do
      {
        v5 = v3->n;
        if ( v4[v5 - 1] )
          break;
        v6 = v5 - 1;
        v3->n = v6;
      }
      while ( v6 );
    }
  }
}

//----- (005B0360) --------------------------------------------------------  // acclient.c:474964
unsigned int __cdecl do_inner(unsigned int n, unsigned int m, unsigned int *a, unsigned int *ya)
{
  unsigned int *v4; // edi@1
  unsigned int *v5; // esi@1
  unsigned __int64 v6; // rax@2
  unsigned __int64 v7; // kr00_8@2
  unsigned int c; // [sp+8h] [bp-4h]@1

  c = 0;
  v4 = a;
  v5 = ya;
  do
  {
    v6 = m * (unsigned __int64)*v5;
    ++v5;
    v7 = c + v6 + *v4;
    *v4 = v7;
    ++v4;
    c = HIDWORD(v7);
    --n;
  }
  while ( n );
  return HIDWORD(v7);
}

//----- (005B03A0) --------------------------------------------------------  // acclient.c:474990
void __thiscall AC1Legacy::flex_unit::fast_mul(AC1Legacy::flex_unit *this, AC1Legacy::flex_unit *x, AC1Legacy::flex_unit *y, unsigned int keep)
{
  char v4; // si@1
  unsigned int v5; // edi@1
  AC1Legacy::flex_unit *v6; // ebx@1
  unsigned int v7; // eax@1
  unsigned int v8; // eax@3
  int v9; // ebp@5
  unsigned int v10; // esi@6
  unsigned int i; // eax@8
  int v12; // esi@13
  int v13; // eax@16
  unsigned int min; // [sp+0h] [bp-4h]@3

  v4 = keep;
  v5 = (keep + 31) >> 5;
  v6 = this;
  AC1Legacy::flex_unit::reserve(this, v5);
  v7 = 0;
  if ( v5 )
  {
    do
      v6->a[v7++] = 0;
    while ( v7 < v5 );
  }
  v8 = x->n;
  min = x->n;
  if ( v8 > v5 )
  {
    min = (keep + 31) >> 5;
    v8 = (keep + 31) >> 5;
  }
  v9 = 0;
  if ( v8 )
  {
    do
    {
      v10 = v9 + y->n;
      if ( v10 > v5 )
        v10 = (keep + 31) >> 5;
      for ( i = do_inner(v10 - v9, x->a[v9], &v6->a[v9], y->a); i; i = v6->a[v10++] < i )
      {
        if ( v10 >= v5 )
          break;
        v6->a[v10] += i;
      }
      ++v9;
    }
    while ( v9 < min );
    v4 = keep;
  }
  v12 = v4 & 0x1F;
  if ( v12 )
    v6->a[v5 - 1] &= (1 << v12) - 1;
  if ( v5 )
  {
    v13 = (int)&v6->a[v5 - 1];
    do
    {
      if ( *(_DWORD *)v13 )
        break;
      --v5;
      v13 -= 4;
    }
    while ( v5 );
  }
  v6->n = v5;
}

//----- (005B04A0) --------------------------------------------------------  // acclient.c:475060
unsigned int __thiscall AC1Legacy::vlong_value::bits(AC1Legacy::vlong_value *this)
{
  unsigned int result; // eax@1
  unsigned int v2; // edx@2
  unsigned int v3; // esi@3
  int v4; // eax@5
  unsigned int v5; // ecx@5

  result = this->n;
  if ( result )
  {
    v2 = result - 1;
    if ( result - 1 < result )
      v3 = this->a[v2];
    else
      v3 = 0;
    v4 = 32 * v2;
    v5 = 32;
    do
    {
      v5 >>= 1;
      if ( v3 >= 1 << v5 )
      {
        v4 += v5;
        v3 >>= v5;
      }
    }
    while ( v5 > 8 );
    result = LOBYTE((&bittab)[v3]) + v4;
  }
  return result;
}
// 821360: using guessed type unsigned __int8 *bittab;

//----- (005B04F0) --------------------------------------------------------  // acclient.c:475095
int __thiscall AC1Legacy::vlong_value::cf(AC1Legacy::vlong_value *this, AC1Legacy::vlong_value *x)
{
  unsigned int v2; // ebp@1
  unsigned int v3; // edi@1
  int result; // eax@2
  unsigned int v5; // eax@5
  unsigned int v6; // esi@7
  unsigned int v7; // edx@10
  unsigned int v8; // edx@14

  v2 = x->n;
  v3 = this->n;
  if ( v3 <= v2 )
  {
    if ( v3 >= v2 )
    {
      v5 = this->n;
      if ( v3 )
      {
        while ( 1 )
        {
          --v5;
          if ( v5 < v3 )
            v6 = this->a[v5];
          else
            v6 = 0;
          if ( v5 < v2 )
            v7 = x->a[v5];
          else
            v7 = 0;
          if ( v6 > v7 )
            return 1;
          v8 = v5 < v3 ? this->a[v5] : 0;
          if ( v5 < v2 && v8 < x->a[v5] )
            break;
          if ( !v5 )
            goto LABEL_19;
        }
        result = -1;
      }
      else
      {
LABEL_19:
        result = 0;
      }
    }
    else
    {
      result = -1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005B0580) --------------------------------------------------------  // acclient.c:475154
void __thiscall AC1Legacy::vlong_value::add(AC1Legacy::vlong_value *this, AC1Legacy::vlong_value *x)
{
  AC1Legacy::vlong_value *v2; // edi@1
  unsigned int v3; // ebp@1
  int v4; // ebx@1
  unsigned int v5; // esi@3
  int v6; // ebp@3
  unsigned int v7; // eax@5
  int v8; // eax@7
  int v9; // ebx@7
  unsigned int v10; // ecx@8
  unsigned int v11; // eax@10

  v2 = this;
  v3 = this->n;
  v4 = 0;
  if ( v3 < x->n )
    v3 = x->n;
  AC1Legacy::flex_unit::reserve((AC1Legacy::flex_unit *)&this->a, v3);
  v5 = 0;
  v6 = v3 + 1;
  if ( v6 )
  {
    do
    {
      if ( v5 < v2->n )
        v7 = v2->a[v5];
      else
        v7 = 0;
      v8 = v4 + v7;
      v9 = v8 < (unsigned int)v4;
      if ( v5 < x->n )
        v10 = x->a[v5];
      else
        v10 = 0;
      v11 = v10 + v8;
      v4 = (v11 < v10) + v9;
      AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)&v2->a, v5++, v11);
    }
    while ( v5 < v6 );
  }
}

//----- (005B05F0) --------------------------------------------------------  // acclient.c:475198
void __thiscall AC1Legacy::vlong_value::subtract(AC1Legacy::vlong_value *this, AC1Legacy::vlong_value *x)
{
  AC1Legacy::vlong_value *v2; // ebx@1
  unsigned int v3; // ebp@1
  unsigned int v4; // esi@1
  unsigned int v5; // edi@1
  unsigned int v6; // edx@3
  int v7; // edx@5
  unsigned int v8; // ecx@7

  v2 = this;
  v3 = this->n;
  v4 = 0;
  v5 = 0;
  if ( v3 )
  {
    do
    {
      if ( v5 < x->n )
        v6 = x->a[v5];
      else
        v6 = 0;
      v7 = v4 + v6;
      if ( v7 >= v4 )
      {
        if ( v5 < v2->n )
          v8 = v2->a[v5];
        else
          v8 = 0;
        v4 = v8 < v8 - v7;
        AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)&v2->a, v5, v8 - v7);
      }
      ++v5;
    }
    while ( v5 < v3 );
  }
}

//----- (005B0650) --------------------------------------------------------  // acclient.c:475237
void __thiscall AC1Legacy::vlong_value::copy(AC1Legacy::vlong_value *this, AC1Legacy::vlong_value *x)
{
  AC1Legacy::flex_unit *v2; // edi@1
  unsigned int i; // esi@1
  unsigned int v4; // eax@3

  v2 = (AC1Legacy::flex_unit *)this;
  this->n = 0;
  for ( i = x->n; i; AC1Legacy::flex_unit::set(v2, i, v4) )
  {
    --i;
    if ( i < x->n )
      v4 = x->a[i];
    else
      v4 = 0;
  }
}

//----- (005B0690) --------------------------------------------------------  // acclient.c:475256
void __thiscall AC1Legacy::vlong::store(AC1Legacy::vlong *this, unsigned int *a, unsigned int n)
{
  unsigned int v3; // eax@1
  AC1Legacy::vlong_value *v4; // edx@2
  unsigned int v5; // edx@3

  v3 = 0;
  if ( n )
  {
    do
    {
      v4 = this->value;
      if ( v3 < v4->n )
        v5 = v4->a[v3];
      else
        v5 = 0;
      a[v3++] = v5;
    }
    while ( v3 < n );
  }
}

//----- (005B06C0) --------------------------------------------------------  // acclient.c:475279
void __thiscall AC1Legacy::vlong::docopy(AC1Legacy::vlong *this)
{
  AC1Legacy::vlong *v1; // edi@1
  AC1Legacy::vlong_value *v2; // eax@1
  unsigned int v3; // ecx@1
  AC1Legacy::vlong_value *v4; // esi@1
  void *v5; // eax@2

  v1 = this;
  v2 = this->value;
  v3 = v2->share;
  v4 = 0;
  if ( v3 )
  {
    v2->share = v3 - 1;
    v5 = operator new(0x10u);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      v4 = (AC1Legacy::vlong_value *)v5;
    }
    AC1Legacy::vlong_value::copy(v4, v1->value);
    v1->value = v4;
  }
}

//----- (005B0700) --------------------------------------------------------  // acclient.c:475309
BOOL __thiscall AC1Legacy::vlong::bit(AC1Legacy::vlong *this, unsigned int i)
{
  AC1Legacy::vlong_value *v2; // edx@1
  unsigned int v3; // edx@2

  v2 = this->value;
  if ( i >> 5 < v2->n )
    v3 = v2->a[i >> 5];
  else
    v3 = 0;
  return (v3 & (1 << (i & 0x1F))) != 0;
}

//----- (005B0740) --------------------------------------------------------  // acclient.c:475323
void __thiscall AC1Legacy::vlong::setbit(AC1Legacy::vlong *this, unsigned int i)
{
  AC1Legacy::vlong *v2; // esi@1
  AC1Legacy::vlong_value *v3; // eax@1
  unsigned int v4; // ecx@1
  void *v5; // eax@2
  AC1Legacy::vlong_value *v6; // edi@3
  AC1Legacy::vlong_value *v7; // edx@6
  unsigned int v8; // esi@7

  v2 = this;
  v3 = this->value;
  v4 = v3->share;
  if ( v4 )
  {
    v3->share = v4 - 1;
    v5 = operator new(0x10u);
    if ( v5 )
    {
      *((_DWORD *)v5 + 1) = 0;
      *(_DWORD *)v5 = 0;
      *((_DWORD *)v5 + 2) = 0;
      *((_DWORD *)v5 + 3) = 0;
      v6 = (AC1Legacy::vlong_value *)v5;
    }
    else
    {
      v6 = 0;
    }
    AC1Legacy::vlong_value::copy(v6, v2->value);
    v2->value = v6;
  }
  v7 = v2->value;
  if ( i >> 5 < v7->n )
    v8 = v7->a[i >> 5];
  else
    v8 = 0;
  AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)&v7->a, i >> 5, v8 | (1 << (i & 0x1F)));
}

//----- (005B07D0) --------------------------------------------------------  // acclient.c:475364
unsigned int __thiscall AC1Legacy::vlong::GetPackSize(AC1Legacy::vlong *this)
{
  return 4 * this->value->n + 4;
}

//----- (005B07E0) --------------------------------------------------------  // acclient.c:475370
void __thiscall AC1Legacy::vlong::load(AC1Legacy::vlong *this, unsigned int *a, unsigned int n)
{
  AC1Legacy::vlong *v3; // edi@1
  AC1Legacy::vlong_value *v4; // eax@1
  unsigned int v5; // ecx@1
  unsigned int v6; // esi@1
  void *v7; // eax@2
  AC1Legacy::vlong_value *v8; // ebx@3

  v3 = this;
  v4 = this->value;
  v5 = v4->share;
  v6 = 0;
  if ( v5 )
  {
    v4->share = v5 - 1;
    v7 = operator new(0x10u);
    if ( v7 )
    {
      *((_DWORD *)v7 + 1) = 0;
      *(_DWORD *)v7 = 0;
      *((_DWORD *)v7 + 2) = 0;
      *((_DWORD *)v7 + 3) = 0;
      v8 = (AC1Legacy::vlong_value *)v7;
    }
    else
    {
      v8 = 0;
    }
    AC1Legacy::vlong_value::copy(v8, v3->value);
    v3->value = v8;
  }
  v3->value->n = 0;
  if ( n )
  {
    do
    {
      AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)&v3->value->a, v6, a[v6]);
      ++v6;
    }
    while ( v6 < n );
  }
}

//----- (005B0850) --------------------------------------------------------  // acclient.c:475415
void __thiscall AC1Legacy::vlong::vlong(AC1Legacy::vlong *this, unsigned int x)
{
  AC1Legacy::vlong *v2; // esi@1
  void *v3; // eax@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  v3 = operator new(0x10u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 0;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
  }
  else
  {
    v3 = 0;
  }
  v2->negative = 0;
  v2->value = (AC1Legacy::vlong_value *)v3;
  *((_DWORD *)v3 + 2) = 0;
  AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)v3, 0, x);
}
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B08A0) --------------------------------------------------------  // acclient.c:475442
void __thiscall AC1Legacy::vlong::vlong(AC1Legacy::vlong *this, AC1Legacy::vlong *x)
{
  AC1Legacy::vlong *v2; // eax@1
  AC1Legacy::vlong_value *v3; // ecx@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  this->negative = x->negative;
  v3 = x->value;
  v2->value = v3;
  ++v3->share;
}
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B08C0) --------------------------------------------------------  // acclient.c:475457
AC1Legacy::vlong *__thiscall AC1Legacy::vlong::operator=(AC1Legacy::vlong *this, AC1Legacy::vlong *x)
{
  AC1Legacy::vlong *v2; // edi@1
  AC1Legacy::vlong_value *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int i; // eax@4
  AC1Legacy::vlong_value *v6; // eax@7

  v2 = this;
  v3 = this->value;
  v4 = v3->share;
  if ( v4 )
  {
    v3->share = v4 - 1;
  }
  else if ( v3 )
  {
    for ( i = v3->z; i; v3->a[i] = 0 )
      --i;
    operator delete[](v3->a);
    operator delete(v3);
  }
  v6 = x->value;
  v2->value = v6;
  ++v6->share;
  v2->negative = x->negative;
  return v2;
}

//----- (005B0920) --------------------------------------------------------  // acclient.c:475487
void __thiscall AC1Legacy::vlong::~vlong(AC1Legacy::vlong *this)
{
  AC1Legacy::vlong *v1; // edi@1
  AC1Legacy::vlong_value *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int i; // eax@4

  v1 = this;
  v2 = this->value;
  this->vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  v3 = v2->share;
  if ( v3 )
  {
    v2->share = v3 - 1;
    this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  }
  else
  {
    if ( v2 )
    {
      for ( i = v2->z; i; v2->a[i] = 0 )
        --i;
      operator delete[](v2->a);
      operator delete(v2);
    }
    v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B0980) --------------------------------------------------------  // acclient.c:475519
AC1Legacy::vlong *__thiscall AC1Legacy::vlong::operator+=(AC1Legacy::vlong *this, AC1Legacy::vlong *x)
{
  AC1Legacy::vlong *v2; // esi@1
  int v3; // edi@1
  AC1Legacy::vlong_value *v4; // eax@2
  unsigned int v5; // ecx@2
  AC1Legacy::vlong_value *v6; // edi@2
  void *v7; // eax@3
  AC1Legacy::vlong *result; // eax@6
  int v9; // ecx@7
  AC1Legacy::vlong tmp; // [sp+Ch] [bp-Ch]@9

  v2 = this;
  v3 = this->negative;
  if ( v3 == x->negative )
  {
    v4 = this->value;
    v5 = v4->share;
    v6 = 0;
    if ( v5 )
    {
      v4->share = v5 - 1;
      v7 = operator new(0x10u);
      if ( v7 )
      {
        *((_DWORD *)v7 + 1) = 0;
        *(_DWORD *)v7 = 0;
        *((_DWORD *)v7 + 2) = 0;
        *((_DWORD *)v7 + 3) = 0;
        v6 = (AC1Legacy::vlong_value *)v7;
      }
      AC1Legacy::vlong_value::copy(v6, v2->value);
      v2->value = v6;
    }
    AC1Legacy::vlong_value::add(v2->value, x->value);
    result = v2;
  }
  else if ( AC1Legacy::vlong_value::cf(this->value, x->value) < 0 )
  {
    tmp.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
    tmp.negative = v3;
    tmp.value = (AC1Legacy::vlong_value *)v9;
    ++*(_DWORD *)(v9 + 12);
    AC1Legacy::vlong::operator=(v2, x);
    AC1Legacy::vlong::operator+=(v2, &tmp);
    AC1Legacy::vlong::~vlong(&tmp);
    result = v2;
  }
  else
  {
    AC1Legacy::vlong::docopy(v2);
    AC1Legacy::vlong_value::subtract(v2->value, x->value);
    result = v2;
  }
  return result;
}
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B0A60) --------------------------------------------------------  // acclient.c:475578
AC1Legacy::vlong *__thiscall AC1Legacy::vlong::operator*(AC1Legacy::vlong *this, AC1Legacy::vlong *result, AC1Legacy::vlong *x)
{
  AC1Legacy::vlong *v3; // ebx@1
  void *v4; // eax@1
  void *v5; // esi@2
  AC1Legacy::vlong_value *v6; // ebx@4
  AC1Legacy::vlong_value *v7; // edi@4
  unsigned int v8; // ebp@4
  unsigned int v9; // eax@4
  int v10; // eax@4
  AC1Legacy::vlong *v12; // [sp+10h] [bp-10h]@1
  AC1Legacy::vlong resulta; // [sp+14h] [bp-Ch]@1

  v3 = this;
  v12 = this;
  resulta.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 + 2) = 0;
    *((_DWORD *)v4 + 3) = 0;
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  *((_DWORD *)v5 + 2) = 0;
  v6 = v3->value;
  v7 = x->value;
  resulta.value = (AC1Legacy::vlong_value *)v5;
  v8 = AC1Legacy::vlong_value::bits(v6);
  v9 = AC1Legacy::vlong_value::bits(v7);
  AC1Legacy::flex_unit::fast_mul(
    (AC1Legacy::flex_unit *)v5,
    (AC1Legacy::flex_unit *)&v6->a,
    (AC1Legacy::flex_unit *)&v7->a,
    v9 + v8);
  v10 = v12->negative ^ x->negative;
  result->negative = v10;
  resulta.negative = v10;
  result->vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  result->value = (AC1Legacy::vlong_value *)v5;
  ++*((_DWORD *)v5 + 3);
  AC1Legacy::vlong::~vlong(&resulta);
  return result;
}
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B0B10) --------------------------------------------------------  // acclient.c:475630
int __thiscall AC1Legacy::vlong::read_from_hex_string(AC1Legacy::vlong *this, const char *str)
{
  AC1Legacy::vlong *v2; // edi@1
  void *v3; // eax@1
  bool v4; // zf@4
  void *v5; // eax@7
  void *v6; // esi@8
  AC1Legacy::vlong *v7; // eax@10
  AC1Legacy::vlong_value *v8; // edi@10
  AC1Legacy::vlong *v9; // ebp@10
  unsigned int v10; // eax@10
  unsigned int i; // eax@13
  AC1Legacy::vlong_value *v12; // eax@16
  AC1Legacy::vlong *v13; // ecx@16
  AC1Legacy::vlong_value *v14; // eax@16
  unsigned int v15; // ecx@16
  void **v16; // edi@18
  unsigned int j; // eax@18
  int v18; // eax@21
  int k; // eax@23
  const char v20; // cl@26
  unsigned int v21; // esi@26
  void *v22; // eax@26
  void *v23; // edi@27
  AC1Legacy::vlong *v24; // ebp@29
  AC1Legacy::vlong_value *v25; // eax@29
  unsigned int v26; // ecx@29
  char *v27; // eax@29
  void **v28; // esi@31
  unsigned int l; // eax@31
  AC1Legacy::vlong_value *v30; // esi@34
  unsigned int v31; // eax@34
  unsigned int m; // eax@37
  int v33; // eax@40
  void *v34; // esi@40
  int n; // eax@42
  int v36; // eax@45
  int ii; // eax@47
  const char v38; // cl@50
  char tmp[2]; // [sp+8h] [bp-4Ch]@4
  AC1Legacy::vlong *v41; // [sp+Ch] [bp-48h]@1
  unsigned int curDigit; // [sp+10h] [bp-44h]@26
  int v43; // [sp+14h] [bp-40h]@29
  AC1Legacy::vlong x; // [sp+18h] [bp-3Ch]@1
  AC1Legacy::vlong v45; // [sp+24h] [bp-30h]@5
  AC1Legacy::vlong v46; // [sp+30h] [bp-24h]@5
  AC1Legacy::vlong result; // [sp+3Ch] [bp-18h]@10
  void *v48; // [sp+4Ch] [bp-8h]@29
  int v49; // [sp+50h] [bp-4h]@29

  v2 = this;
  v41 = this;
  x.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
  v3 = operator new(0x10u);
  if ( v3 )
  {
    *((_DWORD *)v3 + 1) = 0;
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
  }
  else
  {
    v3 = 0;
  }
  x.value = (AC1Legacy::vlong_value *)v3;
  *((_DWORD *)v3 + 2) = 0;
  x.negative = 0;
  AC1Legacy::vlong::operator=(v2, &x);
  AC1Legacy::vlong::~vlong(&x);
  v4 = *str == 0;
  tmp[1] = 0;
  if ( !v4 )
  {
    v45.negative = 0;
    v46.negative = 0;
    while ( 1 )
    {
      v45.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
      v5 = operator new(0x10u);
      if ( v5 )
      {
        *((_DWORD *)v5 + 1) = 0;
        *(_DWORD *)v5 = 0;
        *((_DWORD *)v5 + 2) = 0;
        *((_DWORD *)v5 + 3) = 0;
        v6 = v5;
      }
      else
      {
        v6 = 0;
      }
      v45.value = (AC1Legacy::vlong_value *)v6;
      *((_DWORD *)v6 + 2) = 0;
      AC1Legacy::flex_unit::reserve((AC1Legacy::flex_unit *)v6, 1u);
      **(_DWORD **)v6 = 16;
      *((_DWORD *)v6 + 2) = 1;
      v7 = AC1Legacy::vlong::operator*(v2, &result, &v45);
      v8 = v2->value;
      v9 = v7;
      v10 = v8->share;
      if ( v10 )
      {
        v8->share = v10 - 1;
      }
      else if ( v8 )
      {
        for ( i = v8->z; i; v8->a[i] = 0 )
          --i;
        operator delete[](v8->a);
        operator delete(v8);
      }
      v12 = v9->value;
      v13 = v41;
      v41->value = v12;
      ++v12->share;
      v14 = result.value;
      v13->negative = v9->negative;
      result.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
      v15 = v14->share;
      if ( v15 )
      {
        v14->share = v15 - 1;
      }
      else
      {
        v16 = (void **)v14;
        for ( j = v14->z; j; *((_DWORD *)*v16 + j) = 0 )
          --j;
        operator delete[](*v16);
        operator delete(v16);
      }
      result.vfptr = (PackObjVtbl *)&PackObj::vftable;
      v18 = *((_DWORD *)v6 + 3);
      if ( v18 )
      {
        *((_DWORD *)v6 + 3) = v18 - 1;
      }
      else
      {
        for ( k = *((_DWORD *)v6 + 1); k; *(_DWORD *)(*(_DWORD *)v6 + 4 * k) = 0 )
          --k;
        operator delete[](*(void **)v6);
        operator delete(v6);
      }
      v20 = *str;
      v45.vfptr = (PackObjVtbl *)&PackObj::vftable;
      curDigit = 0;
      tmp[0] = v20;
      _sscanf(tmp, "%x", &curDigit);
      v21 = curDigit;
      v46.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
      v22 = operator new(0x10u);
      if ( v22 )
      {
        *((_DWORD *)v22 + 1) = 0;
        *(_DWORD *)v22 = 0;
        *((_DWORD *)v22 + 2) = 0;
        *((_DWORD *)v22 + 3) = 0;
        v23 = v22;
      }
      else
      {
        v23 = 0;
      }
      v46.value = (AC1Legacy::vlong_value *)v23;
      *((_DWORD *)v23 + 2) = 0;
      AC1Legacy::flex_unit::set((AC1Legacy::flex_unit *)v23, 0, v21);
      x.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
      v24 = v41;
      v25 = v41->value;
      x.negative = v41->negative;
      x.value = v25;
      ++v25->share;
      AC1Legacy::vlong::operator+=(&x, &v46);
      v49 = x.negative;
      v26 = x.value->share;
      v48 = x.value;
      v27 = (char *)&x.value->share;
      ++v26;
      *(_DWORD *)v27 = v26;
      v43 = (int)v27;
      x.vfptr = (PackObjVtbl *)&AC1Legacy::vlong::vftable;
      if ( v26 )
      {
        --x.value->share;
      }
      else
      {
        v28 = (void **)&x.value->a;
        for ( l = x.value->z; l; *((_DWORD *)*v28 + l) = 0 )
          --l;
        operator delete[](*v28);
        operator delete(v28);
      }
      v30 = v24->value;
      x.vfptr = (PackObjVtbl *)&PackObj::vftable;
      v31 = v30->share;
      if ( v31 )
      {
        v30->share = v31 - 1;
      }
      else if ( v30 )
      {
        for ( m = v30->z; m; v30->a[m] = 0 )
          --m;
        operator delete[](v30->a);
        operator delete(v30);
      }
      v33 = v43;
      v34 = v48;
      v24->value = (AC1Legacy::vlong_value *)v48;
      v4 = (*(_DWORD *)v33)++ == -1;
      v24->negative = v49;
      if ( v4 )
      {
        for ( n = *((_DWORD *)v34 + 1); n; *(_DWORD *)(*(_DWORD *)v34 + 4 * n) = 0 )
          --n;
        operator delete[](*(void **)v34);
        operator delete(v34);
      }
      else
      {
        --*(_DWORD *)v33;
      }
      v36 = *((_DWORD *)v23 + 3);
      if ( v36 )
      {
        *((_DWORD *)v23 + 3) = v36 - 1;
      }
      else
      {
        for ( ii = *((_DWORD *)v23 + 1); ii; *(_DWORD *)(*(_DWORD *)v23 + 4 * ii) = 0 )
          --ii;
        operator delete[](*(void **)v23);
        operator delete(v23);
      }
      v38 = str[1];
      v46.vfptr = (PackObjVtbl *)&PackObj::vftable;
      ++str;
      if ( !v38 )
        break;
      v2 = v41;
    }
  }
  return 1;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E6280: using guessed type int (__thiscall *AC1Legacy::vlong::vftable)(void *, char);

//----- (005B0E70) --------------------------------------------------------  // acclient.c:475881
unsigned int __thiscall AC1Legacy::vlong::Pack(AC1Legacy::vlong *this, void **addr, unsigned int size)
{
  AC1Legacy::vlong *v3; // ebx@1
  unsigned int v4; // ebp@1
  unsigned int v5; // edi@2
  char *v6; // edx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    v5 = v3->value->n;
    *(_DWORD *)*addr = v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    AC1Legacy::vlong::store(v3, (unsigned int *)v6, v5);
    *addr = (char *)*addr + 4 * v5;
  }
  return v4;
}

//----- (005B0EC0) --------------------------------------------------------  // acclient.c:475903
int __thiscall AC1Legacy::vlong::UnPack(AC1Legacy::vlong *this, void **addr, unsigned int size)
{
  int result; // eax@2
  unsigned int v4; // edx@3
  int v5; // ebx@3
  char *v6; // esi@3

  if ( size >= 4 )
  {
    v4 = *(_DWORD *)*addr;
    v5 = 4 * v4;
    v6 = (char *)*addr + 4;
    *addr = v6;
    if ( size - 4 >= 4 * v4 )
    {
      AC1Legacy::vlong::load(this, (unsigned int *)v6, v4);
      *addr = &v6[v5];
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

//----- (005B0F10) --------------------------------------------------------  // acclient.c:475935
AC1Legacy::vlong *__thiscall AC1Legacy::vlong::vector_deleting_destructor(AC1Legacy::vlong *this, unsigned int a2)
{
  AC1Legacy::vlong *v2; // esi@1

  v2 = this;
  AC1Legacy::vlong::~vlong(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

