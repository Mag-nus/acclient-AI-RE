/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CryptoSystem
   Object     : CORE\cryptosystem\CryptoSystem.obj
   Functions  : 11
   Addresses  : 0065F700 - 0065FF40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0065F700) --------------------------------------------------------  // acclient.c:629867
void __thiscall CryptoSystem::~CryptoSystem(CryptoSystem *this)
{
  CryptoSystem *v1; // esi@1
  QTIsaac<8,unsigned long> *v2; // ecx@1

  v1 = this;
  v2 = this->pGenerator_;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->pGenerator_ = 0;
}

//----- (0065F720) --------------------------------------------------------  // acclient.c:629880
void __thiscall QTIsaac<8,unsigned long>::srand(QTIsaac<8,unsigned long> *this, unsigned int a, unsigned int b, unsigned int c, unsigned int *s)
{
  unsigned int *v5; // esi@1
  int v6; // edx@1
  signed int v7; // ebx@1
  unsigned int *v8; // eax@1
  unsigned int v9; // edi@4
  int v10; // edx@6
  unsigned int v11; // edi@7
  unsigned int v12; // edx@10
  unsigned int v13; // edx@13
  int v14; // [sp+10h] [bp-4h]@1
  unsigned int *sa; // [sp+24h] [bp+10h]@1

  v5 = s;
  v14 = 4 - (_DWORD)s;
  v6 = -8 - (_DWORD)s;
  v7 = 2;
  v8 = s + 2;
  for ( sa = (unsigned int *)(-8 - (_DWORD)s); ; v6 = (int)sa )
  {
    v9 = v5 ? *(v8 - 2) : 0;
    v10 = (int)((char *)v8 + v6);
    *(unsigned int *)((char *)this->m_rc.randrsl + v10) = v9;
    v11 = v5 ? *(v8 - 1) : 0;
    *(unsigned int *)((char *)this->m_rc.randrsl + v10 + 4) = v11;
    v12 = v5 ? *v8 : 0;
    this->m_rc.randrsl[v7] = v12;
    v13 = v5 ? v8[1] : 0;
    v7 += 4;
    *(unsigned int *)((char *)this->m_rc.randrsl + v14 + (unsigned int)v8) = v13;
    v8 += 4;
    if ( v7 >= 258 )
      break;
  }
  this->m_rc.randa = a;
  this->m_rc.randc = c;
  this->m_rc.randb = b;
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr->randinit)(&this->m_rc, 1);
}

//----- (0065F7D0) --------------------------------------------------------  // acclient.c:629922
void __thiscall QTIsaac<8,unsigned long>::randctx::~randctx(QTIsaac<8,unsigned long>::randctx *this)
{
  QTIsaac<8,unsigned long>::randctx *v1; // esi@1

  v1 = this;
  operator delete[](this->randrsl);
  operator delete[](v1->randmem);
}

//----- (0065F7F0) --------------------------------------------------------  // acclient.c:629932
void __thiscall QTIsaac<8,unsigned long>::QTIsaac<8,unsigned long>(QTIsaac<8,unsigned long> *this, unsigned int a, unsigned int b, unsigned int c)
{
  QTIsaac<8,unsigned long> *v4; // esi@1
  char *v5; // edi@1
  signed int v6; // eax@1
  QTIsaac<8,unsigned long>Vtbl *v7; // eax@3

  v4 = this;
  this->vfptr = (QTIsaac<8,unsigned long>Vtbl *)&QTIsaac<8,unsigned long>::vftable;
  v5 = (char *)&this->m_rc;
  *((_DWORD *)v5 + 1) = operator new[](0x400u);
  *((_DWORD *)v5 + 2) = operator new[](0x400u);
  v6 = 0;
  do
  {
    v4->m_rc.randrsl[v6] = 0;
    v4->m_rc.randrsl[v6 + 1] = 0;
    v4->m_rc.randrsl[v6 + 2] = 0;
    v4->m_rc.randrsl[v6 + 3] = 0;
    v6 += 4;
  }
  while ( v6 < 256 );
  v4->m_rc.randa = a;
  v7 = v4->vfptr;
  v4->m_rc.randb = b;
  v4->m_rc.randc = c;
  v7->randinit(v4, (QTIsaac<8,unsigned long>::randctx *)v5, 1);
}
// 7FDABC: using guessed type int (__thiscall *QTIsaac<8,unsigned long>::vftable)(void *, char);

//----- (0065F870) --------------------------------------------------------  // acclient.c:629963
void __thiscall QTIsaac<8,unsigned long>::randinit(QTIsaac<8,unsigned long> *this, QTIsaac<8,unsigned long>::randctx *ctx, bool bUseSeed)
{
  QTIsaac<8,unsigned long>::randctx *v3; // edi@1
  unsigned int *v4; // ebx@1
  unsigned int *v5; // esi@1
  QTIsaac<8,unsigned long> *v6; // ebp@1
  int v7; // edi@6
  int v8; // esi@6
  int v9; // ebx@6
  unsigned int *v10; // esi@8
  signed int v11; // edi@8
  unsigned int a; // [sp+60h] [bp-2Ch]@1
  unsigned int b; // [sp+64h] [bp-28h]@1
  unsigned int c; // [sp+68h] [bp-24h]@1
  unsigned int d; // [sp+6Ch] [bp-20h]@1
  unsigned int e; // [sp+70h] [bp-1Ch]@1
  unsigned int f; // [sp+74h] [bp-18h]@1
  unsigned int g; // [sp+78h] [bp-14h]@1
  unsigned int h; // [sp+7Ch] [bp-10h]@1
  int v20; // [sp+80h] [bp-Ch]@3
  unsigned int *r; // [sp+84h] [bp-8h]@1
  unsigned int *m; // [sp+88h] [bp-4h]@1
  signed int bUseSeeda; // [sp+94h] [bp+8h]@6

  v3 = ctx;
  v4 = ctx->randmem;
  v5 = ctx->randrsl;
  v6 = this;
  h = -1640531527;
  g = -1640531527;
  f = -1640531527;
  e = -1640531527;
  d = -1640531527;
  c = -1640531527;
  b = -1640531527;
  a = -1640531527;
  m = v4;
  r = v5;
  if ( !bUseSeed )
  {
    ctx->randa = 0;
    ctx->randb = 0;
    ctx->randc = 0;
  }
  v20 = 4;
  do
  {
    v6->vfptr->shuffle(v6, &a, &b, &c, &d, &e, &f, &g, &h);
    --v20;
  }
  while ( v20 );
  if ( bUseSeed )
  {
    v7 = (int)(v4 + 3);
    v8 = (int)(v5 + 2);
    v9 = (char *)v4 - (char *)r;
    bUseSeeda = 32;
    do
    {
      a += *(_DWORD *)(v8 - 8);
      b += *(_DWORD *)(v8 - 4);
      c += *(_DWORD *)v8;
      d += *(_DWORD *)(v8 + 4);
      e += *(_DWORD *)(v8 + 8);
      f += *(_DWORD *)(v8 + 12);
      g += *(_DWORD *)(v8 + 16);
      h += *(_DWORD *)(v8 + 20);
      v6->vfptr->shuffle(v6, &a, &b, &c, &d, &e, &f, &g, &h);
      *(_DWORD *)(v7 - 12) = a;
      *(_DWORD *)(v7 - 8) = b;
      *(_DWORD *)(v9 + v8) = c;
      *(_DWORD *)v7 = d;
      *(_DWORD *)(v7 + 4) = e;
      *(_DWORD *)(v7 + 8) = f;
      *(_DWORD *)(v7 + 12) = g;
      *(_DWORD *)(v7 + 16) = h;
      v8 += 32;
      v7 += 32;
      --bUseSeeda;
    }
    while ( bUseSeeda );
    v10 = m + 2;
    v11 = 32;
    do
    {
      a += *(v10 - 2);
      b += *(v10 - 1);
      c += *v10;
      d += v10[1];
      e += v10[2];
      f += v10[3];
      g += v10[4];
      h += v10[5];
      v6->vfptr->shuffle(v6, &a, &b, &c, &d, &e, &f, &g, &h);
      *(v10 - 2) = a;
      *(v10 - 1) = b;
      *v10 = c;
      v10[1] = d;
      v10[2] = e;
      v10[3] = f;
      v10[4] = g;
      v10[5] = h;
      v10 += 8;
      --v11;
    }
    while ( v11 );
    v3 = ctx;
  }
  else
  {
    v6->vfptr->shuffle(v6, &a, &b, &c, &d, &e, &f, &g, &h);
    v4[4] = a;
    v4[5] = b;
    v4[6] = c;
    v4[7] = d;
    v4[8] = e;
    v4[9] = f;
    v4[10] = g;
    v4[11] = h;
  }
  v6->vfptr->isaac(v6, v3);
  v3->randcnt = 256;
}

//----- (0065FB20) --------------------------------------------------------  // acclient.c:630088
void __stdcall QTIsaac<8,unsigned long>::shuffle(unsigned int *a, unsigned int *b, unsigned int *c, unsigned int *d, unsigned int *e, unsigned int *f, unsigned int *g, unsigned int *h)
{
  unsigned int *v9; // ecx@1
  unsigned int *v10; // eax@1
  unsigned int *v11; // edx@1
  unsigned int *v12; // esi@1
  unsigned int v13; // ebx@1
  unsigned int *v14; // edi@1
  unsigned int v15; // ebx@1
  unsigned int v16; // ebx@1
  unsigned int *v17; // edx@1
  unsigned int v18; // ebx@1
  unsigned int *v19; // edi@1
  unsigned int v20; // ebx@1
  unsigned int v21; // ebx@1
  unsigned int v22; // edx@1

  v9 = b;
  v10 = a;
  *v10 ^= *b << 11;
  v11 = d;
  *v11 += *a;
  v12 = c;
  *v9 += *c;
  v13 = *b ^ (*c >> 2);
  *b = v13;
  v14 = e;
  *v14 += v13;
  *v12 += *d;
  v15 = *c ^ (*d << 8);
  *c = v15;
  *f += v15;
  *v11 += *e;
  v16 = *d ^ *((_WORD *)e + 1);
  *d = v16;
  v17 = g;
  *v17 += v16;
  *v14 += *f;
  v18 = *e ^ (*f << 10);
  *e = v18;
  v19 = h;
  *v19 += v18;
  *f += *g;
  v20 = *f ^ (*g >> 4);
  *f = v20;
  *v10 += v20;
  *v17 += *h;
  v21 = *g ^ (*h << 8);
  *g = v21;
  *v9 += v21;
  *v19 += *a;
  v22 = *h ^ (*a >> 9);
  *h = v22;
  *v12 += v22;
  *v10 += *b;
}

//----- (0065FBE0) --------------------------------------------------------  // acclient.c:630146
QTIsaac<8,unsigned long> *__thiscall QTIsaac<8,unsigned long>::vector_deleting_destructor(QTIsaac<8,unsigned long> *this, unsigned int a2)
{
  QTIsaac<8,unsigned long> *v2; // esi@1

  v2 = this;
  this->vfptr = (QTIsaac<8,unsigned long>Vtbl *)&QTIsaac<8,unsigned long>::vftable;
  QTIsaac<8,unsigned long>::randctx::~randctx(&this->m_rc);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FDABC: using guessed type int (__thiscall *QTIsaac<8,unsigned long>::vftable)(void *, char);

//----- (0065FC10) --------------------------------------------------------  // acclient.c:630160
void __thiscall CryptoSystem::CryptoSystem(CryptoSystem *this, unsigned int seed)
{
  CryptoSystem *v2; // esi@1
  QTIsaac<8,unsigned long> *v3; // eax@1
  QTIsaac<8,unsigned long> *v4; // eax@2

  v2 = this;
  this->lastIter_ = 1;
  this->seed_ = seed;
  this->pGenerator_ = 0;
  v3 = (QTIsaac<8,unsigned long> *)operator new(0x1Cu);
  if ( v3 )
  {
    QTIsaac<8,unsigned long>::QTIsaac<8,unsigned long>(v3, v2->seed_, v2->seed_, v2->seed_);
    v2->pGenerator_ = v4;
  }
  else
  {
    v2->pGenerator_ = 0;
  }
}

//----- (0065FC60) --------------------------------------------------------  // acclient.c:630183
void __stdcall QTIsaac<8,unsigned long>::isaac(QTIsaac<8,unsigned long>::randctx *ctx)
{
  QTIsaac<8,unsigned long>::randctx *v2; // edi@1
  unsigned int *v3; // ecx@1
  int v4; // edx@1
  int v5; // ebp@1
  int v6; // ebx@1
  int v7; // eax@1
  unsigned int v8; // esi@2
  unsigned int x; // ST10_4@2
  unsigned int v10; // edi@2
  int v11; // eax@2
  unsigned int v12; // esi@2
  int v13; // esi@2
  int v14; // ebx@2
  unsigned int v15; // ST10_4@2
  int v16; // ebp@2
  unsigned int v17; // edi@2
  int v18; // edi@2
  int v19; // edx@2
  unsigned int v20; // esi@2
  unsigned int v21; // ST10_4@2
  int v22; // esi@2
  unsigned int v23; // edi@2
  unsigned int v24; // esi@2
  int v25; // esi@2
  unsigned int v26; // ebp@2
  unsigned int v27; // ST10_4@2
  unsigned int v28; // edi@2
  int v29; // esi@2
  int v30; // esi@4
  unsigned int v31; // edi@5
  unsigned int v32; // ST10_4@5
  unsigned int v33; // ebx@5
  int v34; // eax@5
  unsigned int v35; // edi@5
  int v36; // edi@5
  int v37; // esi@5
  unsigned int v38; // ST10_4@5
  int v39; // ebp@5
  unsigned int v40; // ebx@5
  int v41; // ebx@5
  int v42; // edx@5
  unsigned int v43; // edi@5
  unsigned int v44; // ST10_4@5
  int v45; // edi@5
  unsigned int v46; // ebx@5
  unsigned int v47; // edi@5
  int v48; // edi@5
  unsigned int v49; // ebp@5
  unsigned int v50; // ST10_4@5
  unsigned int v51; // ebx@5
  unsigned int v52; // edi@5
  unsigned int b; // [sp+14h] [bp-8h]@1
  unsigned int *mend; // [sp+18h] [bp-4h]@1

  v2 = ctx;
  v3 = ctx->randmem;
  ++v2->randc;
  v4 = (int)ctx->randrsl;
  v5 = ctx->randa;
  v6 = (int)(v3 + 128);
  b = ctx->randc + ctx->randb;
  v7 = (int)v3;
  mend = v3 + 128;
  if ( v3 < v3 + 128 )
  {
    do
    {
      v8 = *(_DWORD *)v7;
      x = v8;
      v10 = *(_DWORD *)v6 + (v5 ^ (v5 << 13));
      v11 = v7 + 4;
      v12 = v10 + b + *(unsigned int *)((char *)v3 + (v8 & 0x3FC));
      *(_DWORD *)(v11 - 4) = v12;
      v13 = x + *(unsigned int *)((char *)v3 + ((v12 >> 8) & 0x3FC));
      v14 = v6 + 4;
      *(_DWORD *)v4 = v13;
      v15 = *(_DWORD *)v11;
      v16 = *(_DWORD *)v14 + (v10 ^ (v10 >> 6));
      v17 = v16 + v13 + *(unsigned int *)((char *)v3 + (*(_DWORD *)v11 & 0x3FC));
      *(_DWORD *)v11 = v17;
      v18 = v15 + *(unsigned int *)((char *)v3 + ((v17 >> 8) & 0x3FC));
      v19 = v4 + 4;
      *(_DWORD *)v19 = v18;
      v20 = *(_DWORD *)(v11 + 4);
      v21 = v20;
      v11 += 4;
      v22 = v18 + *(unsigned int *)((char *)v3 + (v20 & 0x3FC));
      v23 = *(_DWORD *)(v14 + 4) + (v16 ^ 4 * v16);
      v14 += 4;
      v24 = v23 + v22;
      *(_DWORD *)v11 = v24;
      v25 = v21 + *(unsigned int *)((char *)v3 + ((v24 >> 8) & 0x3FC));
      v19 += 4;
      *(_DWORD *)v19 = v25;
      v26 = *(_DWORD *)(v11 + 4);
      v11 += 4;
      v27 = v26;
      v5 = *(_DWORD *)(v14 + 4) + (v23 ^ (v23 >> 16));
      v28 = v5 + v25 + *(unsigned int *)((char *)v3 + (v27 & 0x3FC));
      *(_DWORD *)v11 = v28;
      v29 = v27 + *(unsigned int *)((char *)v3 + ((v28 >> 8) & 0x3FC));
      v19 += 4;
      v7 = v11 + 4;
      *(_DWORD *)v19 = v29;
      v6 = v14 + 8;
      v4 = v19 + 4;
      b = v29;
    }
    while ( v7 < (unsigned int)mend );
    v2 = ctx;
  }
  v30 = (int)v3;
  if ( v3 >= mend )
  {
    v2->randa = v5;
    v2->randb = b;
  }
  else
  {
    do
    {
      v31 = *(_DWORD *)v7;
      v32 = v31;
      v33 = *(_DWORD *)v30 + (v5 ^ (v5 << 13));
      v34 = v7 + 4;
      v35 = v33 + b + *(unsigned int *)((char *)v3 + (v31 & 0x3FC));
      *(_DWORD *)(v34 - 4) = v35;
      v36 = v32 + *(unsigned int *)((char *)v3 + ((v35 >> 8) & 0x3FC));
      v37 = v30 + 4;
      *(_DWORD *)v4 = v36;
      v38 = *(_DWORD *)v34;
      v39 = *(_DWORD *)v37 + (v33 ^ (v33 >> 6));
      v40 = v39 + v36 + *(unsigned int *)((char *)v3 + (*(_DWORD *)v34 & 0x3FC));
      *(_DWORD *)v34 = v40;
      v41 = v38 + *(unsigned int *)((char *)v3 + ((v40 >> 8) & 0x3FC));
      v42 = v4 + 4;
      *(_DWORD *)v42 = v41;
      v43 = *(_DWORD *)(v34 + 4);
      v44 = v43;
      v34 += 4;
      v45 = v41 + *(unsigned int *)((char *)v3 + (v43 & 0x3FC));
      v46 = *(_DWORD *)(v37 + 4) + (v39 ^ 4 * v39);
      v37 += 4;
      v47 = v46 + v45;
      *(_DWORD *)v34 = v47;
      v48 = v44 + *(unsigned int *)((char *)v3 + ((v47 >> 8) & 0x3FC));
      v42 += 4;
      *(_DWORD *)v42 = v48;
      v49 = *(_DWORD *)(v34 + 4);
      v34 += 4;
      v50 = v49;
      v5 = *(_DWORD *)(v37 + 4) + (v46 ^ (v46 >> 16));
      v51 = v5 + v48 + *(unsigned int *)((char *)v3 + (v50 & 0x3FC));
      *(_DWORD *)v34 = v51;
      v52 = v50 + *(unsigned int *)((char *)v3 + ((v51 >> 8) & 0x3FC));
      v42 += 4;
      v30 = v37 + 8;
      *(_DWORD *)v42 = v52;
      v7 = v34 + 4;
      v4 = v42 + 4;
      b = v52;
    }
    while ( v30 < (unsigned int)mend );
    ctx->randa = v5;
    ctx->randb = v52;
  }
}

//----- (0065FF00) --------------------------------------------------------  // acclient.c:630354
unsigned int __thiscall CryptoSystem::GetNextCryptoSeed(CryptoSystem *this, unsigned int iteration)
{
  QTIsaac<8,unsigned long> *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int *v4; // ecx@2
  unsigned int result; // eax@2

  ++this->lastIter_;
  v2 = this->pGenerator_;
  v3 = v2->m_rc.randcnt;
  v2->m_rc.randcnt = v3 - 1;
  if ( v3 )
  {
    result = v2->m_rc.randrsl[v3 - 1];
  }
  else
  {
    v2->vfptr->isaac(v2, &v2->m_rc);
    v4 = v2->m_rc.randrsl;
    v2->m_rc.randcnt = 255;
    result = v4[255];
  }
  return result;
}

//----- (0065FF40) --------------------------------------------------------  // acclient.c:630380
unsigned int __thiscall CryptoSystem::EncryptData(CryptoSystem *this, unsigned int iteration, char *data, unsigned int size, unsigned int *pEncryptSeed)
{
  unsigned int result; // eax@2
  QTIsaac<8,unsigned long> *v6; // esi@3
  unsigned int v7; // eax@3
  unsigned int *v8; // ecx@4
  char *v9; // ecx@6
  unsigned int v10; // edx@6

  if ( pEncryptSeed )
  {
    result = *pEncryptSeed;
  }
  else
  {
    ++this->lastIter_;
    v6 = this->pGenerator_;
    v7 = v6->m_rc.randcnt;
    v6->m_rc.randcnt = v7 - 1;
    if ( v7 )
    {
      result = v6->m_rc.randrsl[v7 - 1];
    }
    else
    {
      v6->vfptr->isaac(v6, &v6->m_rc);
      v8 = v6->m_rc.randrsl;
      v6->m_rc.randcnt = 255;
      result = v8[255];
    }
  }
  v9 = data;
  v10 = (unsigned int)&data[4 * (size >> 2)];
  if ( (unsigned int)data < v10 )
  {
    do
    {
      *(_DWORD *)v9 ^= result;
      v9 += 4;
    }
    while ( (unsigned int)v9 < v10 );
  }
  return result;
}

