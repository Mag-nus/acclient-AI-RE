/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : trees
   Object     : _runtime\msvcrt\trees.obj
   Functions  : 15
   Addresses  : 00611D94 - 00613031 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00611D94) --------------------------------------------------------  // acclient.c:567342
void __userpurge init_block(internal_state *s@<eax>)
{
  char *v1; // ecx@1
  signed int v2; // esi@1
  char *v3; // ecx@3
  signed int v4; // esi@3
  char *v5; // ecx@5
  signed int v6; // esi@5

  v1 = (char *)s->dyn_ltree;
  v2 = 286;
  do
  {
    *(_WORD *)v1 = 0;
    v1 += 4;
    --v2;
  }
  while ( v2 );
  v3 = (char *)s->dyn_dtree;
  v4 = 30;
  do
  {
    *(_WORD *)v3 = 0;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  v5 = (char *)s->bl_tree;
  v6 = 19;
  do
  {
    *(_WORD *)v5 = 0;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  s->dyn_ltree[256].fc.freq = 1;
  s->static_len = 0;
  s->opt_len = 0;
  s->matches = 0;
  s->last_lit = 0;
}

//----- (00611DF4) --------------------------------------------------------  // acclient.c:567386
void __userpurge pqdownheap(internal_state *s@<eax>, ct_data_s *tree@<edi>, int k)
{
  int v3; // edx@1
  int v4; // ecx@1
  bool v5; // sf@1
  unsigned __int8 v6; // of@1
  int v7; // esi@3
  unsigned __int16 v8; // bx@3
  unsigned __int16 v9; // dx@3
  int v10; // esi@7
  unsigned __int16 v11; // dx@7
  unsigned __int16 v12; // bx@7
  int v13; // edx@10
  int v; // [sp+0h] [bp-4h]@1

  v = s->heap[k];
  v3 = s->heap_len;
  v4 = 2 * k;
  v6 = __OFSUB__(2 * k, v3);
  v5 = 2 * k - v3 < 0;
  if ( 2 * k <= v3 )
  {
    do
    {
      if ( v5 ^ v6 )
      {
        v7 = s->heap[v4 + 1];
        v8 = tree[v7].fc.freq;
        v9 = tree[s->heap[v4]].fc.freq;
        if ( v8 < v9 || v8 == v9 && (unsigned __int8)s->depth[v7] <= s->depth[s->heap[v4]] )
          ++v4;
      }
      v10 = s->heap[v4];
      v11 = tree[v].fc.freq;
      v12 = tree[v10].fc.freq;
      if ( v11 < v12 || v11 == v12 && (unsigned __int8)s->depth[v] <= s->depth[v10] )
        break;
      s->heap[k] = v10;
      v13 = s->heap_len;
      k = v4;
      v4 *= 2;
      v6 = __OFSUB__(v4, v13);
      v5 = v4 - v13 < 0;
    }
    while ( v4 <= v13 );
  }
  s->heap[k] = v;
}

//----- (00611EA8) --------------------------------------------------------  // acclient.c:567436
void __userpurge gen_bitlen(internal_state *s@<edx>, tree_desc_s *desc@<eax>)
{
  ct_data_s *v2; // ebx@1
  static_tree_desc_s *v3; // eax@1
  int v4; // eax@1
  signed int v5; // eax@2
  int v6; // esi@3
  int v7; // ecx@3
  int v8; // ecx@3
  int v9; // edi@8
  int v10; // ecx@12
  char *i; // edi@12
  char *v12; // esi@19
  int v13; // ecx@21
  int v14; // esi@21
  ct_data_s *stree; // [sp+8h] [bp-28h]@1
  ct_data_s *streea; // [sp+8h] [bp-28h]@20
  const int *extra; // [sp+Ch] [bp-24h]@1
  int max_code; // [sp+10h] [bp-20h]@1
  int v19; // [sp+14h] [bp-1Ch]@2
  int base; // [sp+18h] [bp-18h]@1
  int n; // [sp+1Ch] [bp-14h]@2
  int na; // [sp+1Ch] [bp-14h]@18
  int xbits; // [sp+20h] [bp-10h]@6
  int xbitsa; // [sp+20h] [bp-10h]@17
  int v25; // [sp+24h] [bp-Ch]@3
  int max_length; // [sp+28h] [bp-8h]@1
  int overflow; // [sp+2Ch] [bp-4h]@1
  int overflowa; // [sp+2Ch] [bp-4h]@16

  overflow = 0;
  max_code = desc->max_code;
  v2 = desc->dyn_tree;
  v3 = desc->stat_desc;
  stree = v3->static_tree;
  extra = v3->extra_bits;
  base = v3->extra_base;
  max_length = v3->max_length;
  memset(s->bl_count, 0, sizeof(s->bl_count));
  v2[s->heap[s->heap_max]].dl.dad = 0;
  v4 = s->heap_max + 1;
  if ( v4 < 573 )
  {
    n = (int)&s->heap[v4];
    v19 = 573 - v4;
    v5 = 573;
    do
    {
      v6 = *(_DWORD *)n;
      v7 = *(_DWORD *)n;
      v25 = v7 * 4;
      v8 = v2[v2[v7].dl.dad].dl.dad + 1;
      if ( v8 > max_length )
      {
        v8 = max_length;
        ++overflow;
      }
      *(unsigned __int16 *)((char *)&v2->dl.dad + v25) = v8;
      if ( v6 <= max_code )
      {
        ++s->bl_count[v8];
        xbits = 0;
        if ( v6 >= base )
          xbits = extra[v6 - base];
        v9 = *(unsigned __int16 *)((char *)&v2->fc.freq + v25);
        s->opt_len += v9 * (v8 + xbits);
        if ( stree )
          s->static_len += v9 * (xbits + *(unsigned __int16 *)((char *)&stree->dl.dad + v25));
      }
      n += 4;
      --v19;
    }
    while ( v19 );
    if ( overflow )
    {
      do
      {
        v10 = max_length - 1;
        for ( i = (char *)&s->bl_count[max_length - 1]; !*(_WORD *)i; i -= 2 )
          --v10;
        --s->bl_count[v10];
        overflow -= 2;
        s->bl_count[v10 + 1] += 2;
        --s->bl_count[max_length];
      }
      while ( overflow > 0 );
      overflowa = max_length;
      if ( max_length )
      {
        xbitsa = (int)&s->bl_count[max_length];
        do
        {
          na = *(_WORD *)xbitsa;
          if ( *(_WORD *)xbitsa )
          {
            v12 = (char *)&s->heap[v5];
            do
            {
              v12 -= 4;
              --v5;
              streea = (ct_data_s *)v12;
              if ( *(_DWORD *)v12 <= max_code )
              {
                v13 = (int)&v2[*(_DWORD *)v12];
                v14 = *(_WORD *)(v13 + 2);
                if ( v14 != overflowa )
                {
                  s->opt_len += *(_WORD *)v13 * (overflowa - v14);
                  *(_WORD *)(v13 + 2) = overflowa;
                }
                --na;
                v12 = (char *)streea;
              }
            }
            while ( na );
          }
          --overflowa;
          xbitsa -= 2;
        }
        while ( overflowa );
      }
    }
  }
}

//----- (00612062) --------------------------------------------------------  // acclient.c:567562
void __userpurge scan_tree(ct_data_s *tree@<eax>, int max_code@<ecx>, internal_state *s)
{
  int v3; // esi@1
  int v4; // ecx@1
  signed int v5; // edx@1
  signed int v6; // ebx@1
  signed int v7; // edi@1
  int v8; // esi@4
  int v9; // eax@5
  signed int v10; // [sp-4h] [bp-18h]@20
  int prevlen; // [sp+Ch] [bp-8h]@1
  char *v12; // [sp+10h] [bp-4h]@4

  prevlen = -1;
  v3 = max_code;
  v4 = tree->dl.dad;
  v5 = 7;
  v6 = 0;
  v7 = 4;
  if ( !tree->dl.dad )
  {
    v5 = 138;
    v7 = 3;
  }
  tree[v3 + 1].dl.dad = -1;
  if ( v3 >= 0 )
  {
    v12 = (char *)&tree[1].dl;
    v8 = v3 + 1;
    do
    {
      v9 = v4;
      v4 = *(_WORD *)v12;
      ++v6;
      if ( v6 < v5 && v9 == v4 )
        goto LABEL_23;
      if ( v6 >= v7 )
      {
        if ( v9 )
        {
          if ( v9 != prevlen )
            ++s->bl_tree[v9].fc.freq;
          ++s->bl_tree[16].fc.freq;
        }
        else if ( v6 > 10 )
        {
          ++s->bl_tree[18].fc.freq;
        }
        else
        {
          ++s->bl_tree[17].fc.freq;
        }
      }
      else
      {
        s->bl_tree[v9].fc.freq += v6;
      }
      v6 = 0;
      prevlen = v9;
      if ( v4 )
      {
        if ( v9 != v4 )
        {
          v5 = 7;
          v10 = 4;
          goto LABEL_22;
        }
        v5 = 6;
      }
      else
      {
        v5 = 138;
      }
      v10 = 3;
LABEL_22:
      v7 = v10;
LABEL_23:
      v12 += 4;
      --v8;
    }
    while ( v8 );
  }
}

//----- (00612122) --------------------------------------------------------  // acclient.c:567647
void __userpurge send_tree(internal_state *s@<eax>, ct_data_s *tree@<ecx>, int max_code@<edx>)
{
  signed int v3; // edi@1
  signed int v4; // esi@1
  signed int v5; // ebx@1
  int v6; // edx@5
  int v7; // edi@8
  int v8; // ecx@8
  unsigned __int16 v9; // si@9
  int v10; // edx@9
  char *v11; // ecx@9
  int v12; // edx@9
  unsigned __int16 v13; // si@9
  int v14; // ecx@9
  __int16 v15; // bx@10
  int v16; // ecx@10
  int v17; // edi@15
  int v18; // ecx@15
  unsigned __int16 v19; // si@16
  int v20; // edx@16
  char *v21; // ecx@16
  int v22; // edx@16
  unsigned __int16 v23; // si@16
  int v24; // ecx@16
  __int16 v25; // bx@17
  int v26; // ecx@17
  int v27; // ecx@19
  unsigned __int16 v28; // si@20
  int v29; // edi@20
  char *v30; // ecx@20
  int v31; // ebx@20
  int v32; // ecx@20
  int v33; // esi@22
  int v34; // edi@23
  char *v35; // ecx@23
  int v36; // ebx@23
  unsigned __int16 v37; // si@23
  int v38; // ebx@23
  int v39; // ecx@24
  int v40; // ecx@25
  unsigned __int16 v41; // si@27
  int v42; // edi@27
  char *v43; // ecx@27
  int v44; // ebx@27
  int v45; // ecx@27
  int v46; // esi@29
  int v47; // edi@30
  char *v48; // ecx@30
  int v49; // ebx@30
  unsigned __int16 v50; // si@34
  int v51; // edi@34
  char *v52; // ecx@34
  int v53; // ebx@34
  int v54; // ecx@34
  int v55; // esi@36
  int v56; // edi@37
  char *v57; // ecx@37
  int v58; // ebx@37
  signed int v59; // [sp-4h] [bp-28h]@44
  int v60; // [sp+Ch] [bp-18h]@4
  int prevlen; // [sp+10h] [bp-14h]@1
  int len; // [sp+14h] [bp-10h]@5
  int lena; // [sp+14h] [bp-10h]@19
  int lenb; // [sp+14h] [bp-10h]@26
  int lenc; // [sp+14h] [bp-10h]@33
  char *v66; // [sp+18h] [bp-Ch]@4
  int nextlen; // [sp+1Ch] [bp-8h]@1
  int count; // [sp+20h] [bp-4h]@5

  prevlen = -1;
  nextlen = tree->dl.dad;
  v3 = 7;
  v4 = 0;
  v5 = 4;
  if ( !tree->dl.dad )
  {
    v3 = 138;
    v5 = 3;
  }
  if ( max_code >= 0 )
  {
    v66 = (char *)&tree[1].dl;
    v60 = max_code + 1;
    do
    {
      v6 = nextlen;
      ++v4;
      len = nextlen;
      nextlen = *(_WORD *)v66;
      count = v4;
      if ( v4 < v3 && v6 == *(_WORD *)v66 )
        goto LABEL_47;
      if ( v4 >= v5 )
      {
        if ( v6 )
        {
          if ( v6 != prevlen )
          {
            v17 = s->bl_tree[v6].dl.dad;
            v18 = s->bi_valid;
            if ( v18 <= 16 - v17 )
            {
              v25 = s->bl_tree[v6].fc.freq << v18;
              v26 = s->bi_valid;
              s->bi_buf |= v25;
              v24 = v17 + v26;
            }
            else
            {
              v19 = s->bl_tree[v6].fc.freq;
              v20 = s->bl_tree[v6].fc.freq << v18;
              v21 = s->pending_buf;
              s->bi_buf |= v20;
              v21[s->pending++] = LOBYTE(s->bi_buf);
              s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
              v22 = s->bi_valid;
              ++s->pending;
              v23 = v19 >> (16 - v22);
              v24 = v22 + v17 - 16;
              v6 = len;
              s->bi_buf = v23;
              v4 = count;
            }
            --v4;
            s->bi_valid = v24;
            count = v4;
          }
          v27 = s->bi_valid;
          lena = s->bl_tree[16].dl.dad;
          if ( v27 <= 16 - lena )
          {
            s->bi_buf |= s->bl_tree[16].fc.freq << v27;
            v32 = lena + v27;
          }
          else
          {
            v28 = s->bl_tree[16].fc.freq;
            v29 = s->bl_tree[16].fc.freq << v27;
            v30 = s->pending_buf;
            s->bi_buf |= v29;
            v30[s->pending++] = LOBYTE(s->bi_buf);
            s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
            v31 = s->bi_valid;
            ++s->pending;
            v32 = v31 + lena - 16;
            s->bi_buf = v28 >> (16 - v31);
            v4 = count;
          }
          v33 = v4 - 3;
          s->bi_valid = v32;
          if ( v32 > 14 )
          {
            v34 = v33 << v32;
            v35 = s->pending_buf;
            s->bi_buf |= v34;
            v35[s->pending++] = LOBYTE(s->bi_buf);
            s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
            v36 = s->bi_valid;
            ++s->pending;
            v37 = (unsigned __int16)v33 >> (16 - v36);
            v38 = v36 - 14;
LABEL_31:
            s->bi_buf = v37;
            s->bi_valid = v38;
            goto LABEL_40;
          }
          s->bi_buf |= v33 << v32;
          v39 = v32 + 2;
        }
        else
        {
          v40 = s->bi_valid;
          if ( v4 > 10 )
          {
            lenc = s->bl_tree[18].dl.dad;
            if ( v40 <= 16 - lenc )
            {
              s->bi_buf |= s->bl_tree[18].fc.freq << v40;
              v54 = lenc + v40;
            }
            else
            {
              v50 = s->bl_tree[18].fc.freq;
              v51 = s->bl_tree[18].fc.freq << v40;
              v52 = s->pending_buf;
              s->bi_buf |= v51;
              v52[s->pending++] = LOBYTE(s->bi_buf);
              s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
              v53 = s->bi_valid;
              ++s->pending;
              v54 = v53 + lenc - 16;
              s->bi_buf = v50 >> (16 - v53);
              v4 = count;
            }
            v55 = v4 - 11;
            s->bi_valid = v54;
            if ( v54 > 9 )
            {
              v56 = v55 << v54;
              v57 = s->pending_buf;
              s->bi_buf |= v56;
              v57[s->pending++] = LOBYTE(s->bi_buf);
              s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
              v58 = s->bi_valid;
              ++s->pending;
              v37 = (unsigned __int16)v55 >> (16 - v58);
              v38 = v58 - 9;
              goto LABEL_31;
            }
            s->bi_buf |= v55 << v54;
            v39 = v54 + 7;
          }
          else
          {
            lenb = s->bl_tree[17].dl.dad;
            if ( v40 <= 16 - lenb )
            {
              s->bi_buf |= s->bl_tree[17].fc.freq << v40;
              v45 = lenb + v40;
            }
            else
            {
              v41 = s->bl_tree[17].fc.freq;
              v42 = s->bl_tree[17].fc.freq << v40;
              v43 = s->pending_buf;
              s->bi_buf |= v42;
              v43[s->pending++] = LOBYTE(s->bi_buf);
              s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
              v44 = s->bi_valid;
              ++s->pending;
              v45 = v44 + lenb - 16;
              s->bi_buf = v41 >> (16 - v44);
              v4 = count;
            }
            v46 = v4 - 3;
            s->bi_valid = v45;
            if ( v45 > 13 )
            {
              v47 = v46 << v45;
              v48 = s->pending_buf;
              s->bi_buf |= v47;
              v48[s->pending++] = LOBYTE(s->bi_buf);
              s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
              v49 = s->bi_valid;
              ++s->pending;
              v37 = (unsigned __int16)v46 >> (16 - v49);
              v38 = v49 - 13;
              goto LABEL_31;
            }
            s->bi_buf |= v46 << v45;
            v39 = v45 + 3;
          }
        }
        s->bi_valid = v39;
      }
      else
      {
        do
        {
          v7 = s->bl_tree[v6].dl.dad;
          v8 = s->bi_valid;
          if ( v8 <= 16 - v7 )
          {
            v15 = s->bl_tree[v6].fc.freq << v8;
            v16 = s->bi_valid;
            s->bi_buf |= v15;
            v14 = v7 + v16;
          }
          else
          {
            v9 = s->bl_tree[v6].fc.freq;
            v10 = s->bl_tree[v6].fc.freq << v8;
            v11 = s->pending_buf;
            s->bi_buf |= v10;
            v11[s->pending++] = LOBYTE(s->bi_buf);
            s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
            v12 = s->bi_valid;
            ++s->pending;
            v13 = v9 >> (16 - v12);
            v14 = v12 + v7 - 16;
            v6 = len;
            s->bi_buf = v13;
            v4 = count;
          }
          --v4;
          s->bi_valid = v14;
          count = v4;
        }
        while ( v4 );
      }
LABEL_40:
      v4 = 0;
      prevlen = v6;
      if ( nextlen )
      {
        if ( v6 != nextlen )
        {
          v3 = 7;
          v59 = 4;
          goto LABEL_46;
        }
        v3 = 6;
      }
      else
      {
        v3 = 138;
      }
      v59 = 3;
LABEL_46:
      v5 = v59;
LABEL_47:
      v66 += 4;
      --v60;
    }
    while ( v60 );
  }
}

//----- (006125C1) --------------------------------------------------------  // acclient.c:567966
void __userpurge send_all_trees(internal_state *s@<eax>, int lcodes, int dcodes, int blcodes)
{
  int v4; // ecx@1
  int v5; // ebx@1
  int v6; // edx@2
  int v7; // ecx@2
  int v8; // edx@2
  int v9; // ecx@4
  int v10; // edx@5
  int v11; // ecx@5
  int v12; // edx@5
  int v13; // ecx@7
  int v14; // edx@8
  int v15; // ecx@8
  int v16; // edx@8
  int i; // edi@10
  int v18; // ecx@11
  int v19; // edx@11
  unsigned __int16 v20; // si@12
  int v21; // edx@12
  int v22; // ecx@12
  int v23; // edx@12
  internal_state *v24; // eax@15

  v4 = s->bi_valid;
  v5 = blcodes;
  if ( v4 <= 11 )
  {
    s->bi_buf |= (lcodes - 257) << v4;
    s->bi_valid = v4 + 5;
  }
  else
  {
    v6 = (lcodes - 257) << v4;
    v7 = s->pending;
    s->bi_buf |= v6;
    s->pending_buf[v7] = LOBYTE(s->bi_buf);
    ++s->pending;
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
    v8 = s->bi_valid;
    ++s->pending;
    v5 = blcodes;
    s->bi_valid = v8 - 11;
    s->bi_buf = (unsigned __int16)(lcodes - 257) >> (16 - v8);
  }
  v9 = s->bi_valid;
  if ( v9 <= 11 )
  {
    s->bi_buf |= (dcodes - 1) << v9;
    s->bi_valid = v9 + 5;
  }
  else
  {
    v10 = (dcodes - 1) << v9;
    v11 = s->pending;
    s->bi_buf |= v10;
    s->pending_buf[v11] = LOBYTE(s->bi_buf);
    ++s->pending;
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
    v12 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v12 - 11;
    s->bi_buf = (unsigned __int16)(dcodes - 1) >> (16 - v12);
  }
  v13 = s->bi_valid;
  if ( v13 <= 12 )
  {
    s->bi_buf |= (v5 - 4) << v13;
    s->bi_valid = v13 + 4;
  }
  else
  {
    v14 = (v5 - 4) << v13;
    v15 = s->pending;
    s->bi_buf |= v14;
    s->pending_buf[v15] = LOBYTE(s->bi_buf);
    ++s->pending;
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
    v16 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v16 - 12;
    s->bi_buf = (unsigned __int16)(v5 - 4) >> (16 - v16);
  }
  for ( i = 0; i < v5; ++i )
  {
    v18 = s->bi_valid;
    v19 = (unsigned __int8)bl_order[i];
    if ( v18 <= 13 )
    {
      s->bi_buf |= s->bl_tree[v19].dl.dad << v18;
      s->bi_valid = v18 + 3;
    }
    else
    {
      v20 = s->bl_tree[v19].dl.dad;
      v21 = s->bl_tree[v19].dl.dad << v18;
      v22 = s->pending;
      s->bi_buf |= v21;
      s->pending_buf[v22] = LOBYTE(s->bi_buf);
      ++s->pending;
      s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
      v23 = s->bi_valid;
      ++s->pending;
      v5 = blcodes;
      s->bi_valid = v23 - 13;
      s->bi_buf = v20 >> (16 - v23);
    }
  }
  send_tree(s, s->dyn_ltree, lcodes - 1);
  send_tree(v24, v24->dyn_dtree, dcodes - 1);
}

//----- (006127FE) --------------------------------------------------------  // acclient.c:568079
void __userpurge compress_block(internal_state *s@<eax>, ct_data_s *ltree, ct_data_s *dtree)
{
  ct_data_s *v3; // ebx@1
  int v4; // ecx@1
  unsigned int v5; // edi@2
  int v6; // esi@2
  int v7; // ecx@3
  int v8; // esi@3
  int v9; // edi@3
  int v10; // esi@4
  int v11; // edx@4
  char *v12; // ecx@4
  int v13; // edx@4
  int v14; // ecx@4
  int v15; // edx@6
  int v16; // ecx@6
  int v17; // ecx@6
  int v18; // ebx@6
  int v19; // ecx@6
  unsigned __int16 v20; // di@7
  int v21; // edx@7
  char *v22; // ecx@7
  int v23; // edx@7
  int v24; // ecx@7
  int v25; // ecx@9
  int v26; // esi@10
  int v27; // ecx@10
  int v28; // edx@11
  char *v29; // ecx@11
  int v30; // edx@11
  int v31; // ecx@11
  unsigned int v32; // edi@14
  int v33; // ecx@15
  int v34; // esi@17
  ct_data_s *v35; // edx@17
  int v36; // ebx@17
  int v37; // ecx@17
  unsigned __int16 v38; // si@18
  int v39; // edx@18
  char *v40; // ecx@18
  int v41; // edx@18
  int v42; // ecx@18
  int v43; // edx@20
  int v44; // edi@21
  int v45; // edx@22
  char *v46; // ecx@22
  int v47; // edx@22
  int v48; // edx@26
  int v49; // ecx@26
  unsigned __int16 v50; // si@27
  int v51; // edx@27
  char *v52; // ecx@27
  int v53; // edx@27
  int v54; // ecx@27
  int lx; // [sp+Ch] [bp-10h]@2
  unsigned int dist; // [sp+10h] [bp-Ch]@2
  int len; // [sp+14h] [bp-8h]@6
  int lena; // [sp+14h] [bp-8h]@17
  int extra; // [sp+18h] [bp-4h]@6
  int extraa; // [sp+18h] [bp-4h]@9
  int extrab; // [sp+18h] [bp-4h]@17
  int extrac; // [sp+18h] [bp-4h]@20
  ct_data_s *ltreea; // [sp+24h] [bp+8h]@26

  v3 = ltree;
  v4 = 0;
  if ( s->last_lit )
  {
    do
    {
      v5 = s->d_buf[v4];
      v6 = s->l_buf[v4];
      dist = s->d_buf[v4];
      lx = v4 + 1;
      if ( s->d_buf[v4] )
      {
        v15 = (unsigned __int8)d3dx__length_code[v6];
        v16 = v15;
        extra = v16 * 4;
        v17 = v3[v16 + 257].dl.dad;
        v18 = 16 - v17;
        len = v17;
        v19 = s->bi_valid;
        if ( v19 <= v18 )
        {
          s->bi_buf |= ltree[v15 + 257].fc.freq << v19;
          v24 = len + v19;
        }
        else
        {
          v20 = ltree[v15 + 257].fc.freq;
          v21 = ltree[v15 + 257].fc.freq << v19;
          v22 = s->pending_buf;
          s->bi_buf |= v21;
          v22[s->pending++] = LOBYTE(s->bi_buf);
          s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
          v23 = s->bi_valid;
          ++s->pending;
          v24 = v23 + len - 16;
          s->bi_buf = v20 >> (16 - v23);
          v5 = dist;
        }
        s->bi_valid = v24;
        v25 = extra;
        extraa = *(const int *)((char *)extra_lbits + extra);
        if ( extraa )
        {
          v26 = v6 - *(const int *)((char *)base_length + v25);
          v27 = s->bi_valid;
          if ( v27 <= 16 - extraa )
          {
            s->bi_buf |= v26 << v27;
            v31 = extraa + v27;
          }
          else
          {
            v28 = v26 << v27;
            v29 = s->pending_buf;
            s->bi_buf |= v28;
            v29[s->pending++] = LOBYTE(s->bi_buf);
            s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
            v30 = s->bi_valid;
            ++s->pending;
            v31 = v30 + extraa - 16;
            s->bi_buf = (unsigned __int16)v26 >> (16 - v30);
          }
          s->bi_valid = v31;
        }
        v32 = v5 - 1;
        if ( v32 >= 0x100 )
          v33 = (unsigned __int8)byte_7F5190[v32 >> 7];
        else
          v33 = (unsigned __int8)d3dx__dist_code[v32];
        v34 = 4 * v33;
        v35 = &dtree[v33];
        v36 = 16 - v35->dl.dad;
        lena = v35->dl.dad;
        v37 = s->bi_valid;
        extrab = v34;
        if ( v37 <= v36 )
        {
          s->bi_buf |= v35->fc.freq << v37;
          v42 = lena + v37;
        }
        else
        {
          v38 = v35->fc.freq;
          v39 = v35->fc.freq << v37;
          v40 = s->pending_buf;
          s->bi_buf |= v39;
          v40[s->pending++] = LOBYTE(s->bi_buf);
          s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
          v41 = s->bi_valid;
          ++s->pending;
          v42 = v41 + lena - 16;
          s->bi_buf = v38 >> (16 - v41);
          v34 = extrab;
        }
        v3 = ltree;
        s->bi_valid = v42;
        v43 = *(const int *)((char *)extra_dbits + v34);
        extrac = *(const int *)((char *)extra_dbits + v34);
        if ( !v43 )
          goto LABEL_25;
        v44 = v32 - *(const int *)((char *)base_dist + v34);
        if ( v42 <= 16 - v43 )
        {
          s->bi_buf |= v44 << v42;
          v14 = v43 + v42;
        }
        else
        {
          v45 = v44 << v42;
          v46 = s->pending_buf;
          s->bi_buf |= v45;
          v46[s->pending++] = LOBYTE(s->bi_buf);
          s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
          v47 = s->bi_valid;
          ++s->pending;
          v14 = v47 + extrac - 16;
          s->bi_buf = (unsigned __int16)v44 >> (16 - v47);
        }
      }
      else
      {
        v7 = s->bi_valid;
        v8 = (int)&v3[v6];
        v9 = *(_WORD *)(v8 + 2);
        if ( v7 <= 16 - v9 )
        {
          s->bi_buf |= *(_WORD *)v8 << v7;
          v14 = v9 + v7;
        }
        else
        {
          v10 = *(_WORD *)v8;
          v11 = v10 << v7;
          v12 = s->pending_buf;
          s->bi_buf |= v11;
          v12[s->pending++] = LOBYTE(s->bi_buf);
          s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
          v13 = s->bi_valid;
          ++s->pending;
          v3 = ltree;
          v14 = v13 + v9 - 16;
          s->bi_buf = (unsigned __int16)v10 >> (16 - v13);
        }
      }
      s->bi_valid = v14;
LABEL_25:
      v4 = lx;
    }
    while ( lx < s->last_lit );
  }
  v48 = v3[256].dl.dad;
  v49 = s->bi_valid;
  ltreea = (ct_data_s *)v3[256].dl.dad;
  if ( v49 <= 16 - v48 )
  {
    s->bi_buf |= v3[256].fc.freq << v49;
    v54 = v48 + v49;
  }
  else
  {
    v50 = v3[256].fc.freq;
    v51 = v3[256].fc.freq << v49;
    v52 = s->pending_buf;
    s->bi_buf |= v51;
    v52[s->pending++] = LOBYTE(s->bi_buf);
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
    v53 = s->bi_valid;
    ++s->pending;
    v54 = (int)((char *)&ltreea[-4] + v53);
    s->bi_buf = v50 >> (16 - v53);
  }
  s->bi_valid = v54;
  s->last_eob_len = v3[256].dl.dad;
}

//----- (00612BB4) --------------------------------------------------------  // acclient.c:568319
void __userpurge set_data_type(internal_state *s@<ecx>)
{
  unsigned int v1; // edx@1
  unsigned int v2; // edi@1
  char *v3; // eax@1
  signed int v4; // esi@1
  char *v5; // eax@3
  signed int v6; // esi@3
  char *v7; // eax@5
  signed int v8; // esi@5

  v1 = 0;
  v2 = 0;
  v3 = (char *)s->dyn_ltree;
  v4 = 7;
  do
  {
    v2 += *(_WORD *)v3;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  v5 = (char *)&s->dyn_ltree[7];
  v6 = 121;
  do
  {
    v1 += *(_WORD *)v5;
    v5 += 4;
    --v6;
  }
  while ( v6 );
  v7 = (char *)&s->dyn_ltree[128];
  v8 = 128;
  do
  {
    v2 += *(_WORD *)v7;
    v7 += 4;
    --v8;
  }
  while ( v8 );
  s->data_type = v1 >> 2 >= v2;
}

//----- (00612C0B) --------------------------------------------------------  // acclient.c:568363
void __userpurge bi_windup(internal_state *s@<eax>)
{
  int v1; // ecx@1

  v1 = s->bi_valid;
  if ( v1 > 8 )
  {
    s->pending_buf[s->pending++] = LOBYTE(s->bi_buf);
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
LABEL_5:
    ++s->pending;
    goto LABEL_6;
  }
  if ( v1 > 0 )
  {
    s->pending_buf[s->pending] = LOBYTE(s->bi_buf);
    goto LABEL_5;
  }
LABEL_6:
  s->bi_buf = 0;
  s->bi_valid = 0;
}

//----- (00612C62) --------------------------------------------------------  // acclient.c:568387
void __userpurge copy_block(internal_state *s@<eax>, char *buf@<edx>, unsigned int len@<ecx>, int header)
{
  unsigned int v4; // ebx@1
  char *v5; // edi@1
  int v6; // eax@1
  int headera; // [sp+10h] [bp+8h]@4

  v4 = len;
  v5 = buf;
  bi_windup(s);
  *(_DWORD *)(v6 + 5804) = 8;
  if ( header )
  {
    *(_BYTE *)((*(_DWORD *)(v6 + 20))++ + *(_DWORD *)(v6 + 8)) = v4;
    *(_BYTE *)((*(_DWORD *)(v6 + 20))++ + *(_DWORD *)(v6 + 8)) = BYTE1(v4);
    *(_BYTE *)((*(_DWORD *)(v6 + 20))++ + *(_DWORD *)(v6 + 8)) = ~(_BYTE)v4;
    *(_BYTE *)((*(_DWORD *)(v6 + 20))++ + *(_DWORD *)(v6 + 8)) = ~BYTE1(v4);
  }
  if ( v4 )
  {
    do
    {
      headera = v4;
      *(_BYTE *)((*(_DWORD *)(v6 + 20))++ + *(_DWORD *)(v6 + 8)) = *v5++;
      --v4;
    }
    while ( headera != 1 );
  }
}

//----- (00612CDE) --------------------------------------------------------  // acclient.c:568418
void __userpurge gen_codes(ct_data_s *tree@<edi>, int max_code, unsigned __int16 *bl_count)
{
  int v3; // ebx@1
  unsigned __int16 v4; // cx@1
  signed int v5; // edx@1
  int v6; // edx@4
  unsigned __int16 *v7; // eax@5
  unsigned int v8; // esi@5
  unsigned int v9; // eax@5
  int v10; // ecx@6
  unsigned __int16 next_code[16]; // [sp+8h] [bp-24h]@2

  v3 = 0;
  v4 = 0;
  v5 = 1;
  do
  {
    v4 = 2 * (v4 + *(unsigned __int16 *)((char *)&next_code[v5] + (char *)bl_count - (char *)&next_code[1]));
    next_code[v5++] = v4;
  }
  while ( v5 <= 15 );
  if ( max_code >= 0 )
  {
    do
    {
      v6 = tree[v3].dl.dad;
      if ( tree[v3].dl.dad )
      {
        v7 = &next_code[v6];
        v8 = (*v7)++;
        v9 = 0;
        do
        {
          v10 = v8 & 1;
          v8 >>= 1;
          v9 = 2 * (v10 | v9);
          --v6;
        }
        while ( v6 > 0 );
        tree[v3].fc.freq = v9 >> 1;
      }
      ++v3;
    }
    while ( v3 <= max_code );
  }
}

//----- (00612D63) --------------------------------------------------------  // acclient.c:568466
void __userpurge build_tree(internal_state *s@<eax>, tree_desc_s *desc)
{
  internal_state *v2; // esi@1
  static_tree_desc_s *v3; // eax@1
  int v4; // ecx@1
  ct_data_s *v5; // ebx@1
  signed int v6; // eax@1
  ct_data_s *v7; // edi@1
  signed int v8; // eax@8
  signed int i; // ebx@13
  int v10; // eax@17
  int v11; // ecx@17
  int v12; // ebx@17
  int v13; // eax@17
  char v14; // bl@17
  char v15; // al@17
  int v16; // [sp+Ch] [bp-14h]@17
  int v17; // [sp+10h] [bp-10h]@17
  int node; // [sp+14h] [bp-Ch]@16
  signed int max_code; // [sp+18h] [bp-8h]@1
  int elems; // [sp+1Ch] [bp-4h]@1

  max_code = -1;
  v2 = s;
  v3 = desc->stat_desc;
  v4 = v3->elems;
  v5 = v3->static_tree;
  v6 = 0;
  v7 = desc->dyn_tree;
  elems = v4;
  v2->heap_len = 0;
  for ( v2->heap_max = 573; v6 < v4; ++v6 )
  {
    if ( v7[v6].fc.freq )
    {
      ++v2->heap_len;
      v2->heap[v2->heap_len] = v6;
      max_code = v6;
      v2->depth[v6] = 0;
    }
    else
    {
      v7[v6].dl.dad = 0;
    }
  }
  while ( v2->heap_len < 2 )
  {
    if ( max_code >= 2 )
    {
      v8 = 0;
    }
    else
    {
      ++max_code;
      v8 = max_code;
    }
    ++v2->heap_len;
    v2->heap[v2->heap_len] = v8;
    v7[v8].fc.freq = 1;
    v2->depth[v8] = 0;
    --v2->opt_len;
    if ( v5 )
      v2->static_len -= v5[v8].dl.dad;
  }
  desc->max_code = max_code;
  for ( i = v2->heap_len / 2; i >= 1; --i )
    pqdownheap(v2, v7, i);
  node = elems;
  do
  {
    v10 = v2->heap_len;
    v11 = v2->heap[v10];
    v12 = v2->heap[1];
    v2->heap_len = v10 - 1;
    v2->heap[1] = v11;
    pqdownheap(v2, v7, 1);
    --v2->heap_max;
    v13 = v2->heap[1];
    v2->heap[v2->heap_max--] = v12;
    v2->heap[v2->heap_max] = v13;
    v17 = (int)&v7[v13];
    v16 = (int)&v7[v12];
    v7[node].fc.freq = v7[v12].fc.freq + *(_WORD *)v17;
    v14 = v2->depth[v12];
    v15 = v2->depth[v13];
    if ( (unsigned __int8)v14 >= (unsigned __int8)v15 )
      v15 = v14;
    v2->depth[node] = v15 + 1;
    *(_WORD *)(v17 + 2) = node;
    *(_WORD *)(v16 + 2) = node;
    v2->heap[1] = node++;
    pqdownheap(v2, v7, 1);
  }
  while ( v2->heap_len >= 2 );
  --v2->heap_max;
  v2->heap[v2->heap_max] = v2->heap[1];
  gen_bitlen(v2, desc);
  gen_codes(v7, max_code, v2->bl_count);
}

//----- (00612F4B) --------------------------------------------------------  // acclient.c:568567
int __userpurge build_bl_tree@<eax>(internal_state *s@<esi>)
{
  int result; // eax@1
  internal_state *v2; // [sp+0h] [bp-4h]@0

  scan_tree(s->dyn_ltree, s->l_desc.max_code, v2);
  scan_tree(s->dyn_dtree, s->d_desc.max_code, s);
  build_tree(s, &s->bl_desc);
  result = 18;
  do
  {
    if ( s->bl_tree[(unsigned __int8)bl_order[result]].dl.dad )
      break;
    --result;
  }
  while ( result >= 3 );
  s->opt_len += 3 * result + 17;
  return result;
}

//----- (00612FA3) --------------------------------------------------------  // acclient.c:568588
void __stdcall d3dx__tr_stored_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int v4; // ecx@1
  int v5; // edx@2
  char *v6; // ecx@2
  int v7; // edx@2

  v4 = s->bi_valid;
  if ( v4 <= 13 )
  {
    s->bi_buf |= eof << v4;
    s->bi_valid = v4 + 3;
  }
  else
  {
    v5 = eof << v4;
    v6 = s->pending_buf;
    s->bi_buf |= v5;
    v6[s->pending++] = LOBYTE(s->bi_buf);
    s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
    v7 = s->bi_valid;
    ++s->pending;
    s->bi_valid = v7 - 13;
    s->bi_buf = (unsigned __int16)eof >> (16 - v7);
  }
  copy_block(s, buf, stored_len, 1);
}

//----- (00613031) --------------------------------------------------------  // acclient.c:568617
void __stdcall d3dx__tr_flush_block(internal_state *s, char *buf, unsigned int stored_len, int eof)
{
  int v4; // eax@1
  unsigned int v5; // edx@4
  unsigned int v6; // ecx@4
  bool v7; // zf@11
  int v8; // ecx@11
  int v9; // eax@12
  int v10; // edx@13
  char *v11; // ecx@13
  int v12; // edx@13
  int v13; // edx@16
  int v14; // edi@17
  char *v15; // ecx@17
  int v16; // ebx@17
  internal_state *v17; // eax@20

  v4 = 0;
  if ( s->level <= 0 )
  {
    v6 = stored_len + 5;
LABEL_7:
    v5 = v6;
    goto LABEL_8;
  }
  if ( s->data_type == 2 )
    set_data_type(s);
  build_tree(s, &s->l_desc);
  build_tree(s, &s->d_desc);
  v4 = build_bl_tree(s);
  v5 = (s->opt_len + 10) >> 3;
  v6 = (s->static_len + 10) >> 3;
  if ( v6 <= v5 )
    goto LABEL_7;
LABEL_8:
  if ( stored_len + 4 <= v5 && buf )
  {
    d3dx__tr_stored_block(s, buf, stored_len, eof);
  }
  else
  {
    v7 = v6 == v5;
    v8 = s->bi_valid;
    if ( v7 )
    {
      v9 = eof + 2;
      if ( v8 <= 13 )
      {
        s->bi_buf |= v9 << v8;
        s->bi_valid = v8 + 3;
      }
      else
      {
        v10 = v9 << v8;
        v11 = s->pending_buf;
        s->bi_buf |= v10;
        v11[s->pending++] = LOBYTE(s->bi_buf);
        s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
        v12 = s->bi_valid;
        ++s->pending;
        s->bi_valid = v12 - 13;
        s->bi_buf = (unsigned __int16)v9 >> (16 - v12);
      }
      compress_block(s, static_ltree, static_dtree);
    }
    else
    {
      v13 = eof + 4;
      if ( v8 <= 13 )
      {
        s->bi_buf |= v13 << v8;
        s->bi_valid = v8 + 3;
      }
      else
      {
        v14 = v13 << v8;
        v15 = s->pending_buf;
        s->bi_buf |= v14;
        v15[s->pending++] = LOBYTE(s->bi_buf);
        s->pending_buf[s->pending] = HIBYTE(s->bi_buf);
        v16 = s->bi_valid;
        ++s->pending;
        s->bi_valid = v16 - 13;
        s->bi_buf = (unsigned __int16)v13 >> (16 - v16);
      }
      send_all_trees(s, s->l_desc.max_code + 1, s->d_desc.max_code + 1, v4 + 1);
      compress_block(s, s->dyn_ltree, s->dyn_dtree);
    }
  }
  init_block(s);
  if ( eof )
    bi_windup(v17);
}

