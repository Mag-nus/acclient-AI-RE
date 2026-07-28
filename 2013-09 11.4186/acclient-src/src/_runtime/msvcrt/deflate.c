/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : deflate
   Object     : _runtime\msvcrt\deflate.obj
   Functions  : 6
   Addresses  : 00601CBB - 00602387 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00601CBB) --------------------------------------------------------  // acclient.c:556275
void __userpurge flush_pending(z_stream_s *strm@<eax>)
{
  internal_state *v1; // esi@1
  unsigned int v2; // edx@1
  internal_state *v3; // ecx@4
  internal_state *v4; // eax@4

  v1 = strm->state;
  v2 = v1->pending;
  if ( v2 > strm->avail_out )
    v2 = strm->avail_out;
  if ( v2 )
  {
    qmemcpy(strm->next_out, v1->pending_out, v2);
    v3 = strm->state;
    strm->next_out += v2;
    v3->pending_out += v2;
    strm->total_out += v2;
    strm->avail_out -= v2;
    strm->state->pending -= v2;
    v4 = strm->state;
    if ( !v4->pending )
      v4->pending_out = v4->pending_buf;
  }
}

//----- (00601D0F) --------------------------------------------------------  // acclient.c:556302
unsigned int __userpurge longest_match@<eax>(internal_state *s@<ecx>, unsigned int cur_match)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@1
  int v4; // edx@1
  unsigned int v5; // edi@1
  unsigned int v6; // eax@8
  char *v7; // esi@9
  int v8; // esi@12
  int v9; // edx@13
  int v10; // esi@13
  int v11; // esi@14
  int v12; // esi@15
  int v13; // esi@16
  int v14; // esi@17
  int v15; // esi@18
  int v16; // esi@19
  int v17; // esi@20
  int v18; // eax@23
  unsigned int v19; // esi@26
  unsigned int result; // eax@28
  unsigned int v21; // [sp+Ch] [bp-18h]@6
  char *strend; // [sp+10h] [bp-14h]@4
  unsigned int limit; // [sp+14h] [bp-10h]@2
  int nice_match; // [sp+18h] [bp-Ch]@1
  unsigned int chain_length; // [sp+1Ch] [bp-8h]@1
  char scan_end; // [sp+22h] [bp-2h]@4
  char scan_end1; // [sp+23h] [bp-1h]@4

  chain_length = s->max_chain_length;
  v2 = s->strstart;
  nice_match = s->nice_match;
  v3 = s->w_size;
  v4 = (int)&s->window[v2];
  v5 = s->prev_length;
  if ( v2 <= v3 - 262 )
    limit = 0;
  else
    limit = v2 - v3 + 262;
  strend = (char *)(v4 + 258);
  scan_end1 = *(_BYTE *)(v5 + v4 - 1);
  scan_end = *(_BYTE *)(v5 + v4);
  if ( v5 >= s->good_match )
    chain_length >>= 2;
  v21 = s->lookahead;
  if ( nice_match > s->lookahead )
    nice_match = s->lookahead;
  v6 = cur_match;
  do
  {
    v7 = &s->window[v6];
    if ( v7[v5] == scan_end && v7[v5 - 1] == scan_end1 && *v7 == *(_BYTE *)v4 )
    {
      v8 = (int)(v7 + 1);
      if ( *(_BYTE *)v8 == *(_BYTE *)(v4 + 1) )
      {
        v9 = v4 + 2;
        v10 = v8 + 1;
        do
        {
          ++v9;
          v11 = v10 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v11 )
            break;
          ++v9;
          v12 = v11 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v12 )
            break;
          ++v9;
          v13 = v12 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v13 )
            break;
          ++v9;
          v14 = v13 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v14 )
            break;
          ++v9;
          v15 = v14 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v15 )
            break;
          ++v9;
          v16 = v15 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v16 )
            break;
          ++v9;
          v17 = v16 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v17 )
            break;
          ++v9;
          v10 = v17 + 1;
          if ( *(_BYTE *)v9 != *(_BYTE *)v10 )
            break;
        }
        while ( v9 < (unsigned int)strend );
        v18 = v9 - (_DWORD)strend + 258;
        v4 = (int)(strend - 258);
        if ( v18 > (signed int)v5 )
        {
          s->match_start = cur_match;
          v5 = v18;
          if ( v18 >= nice_match )
            break;
          scan_end1 = *(_BYTE *)(v18 + v4 - 1);
          scan_end = *(_BYTE *)(v18 + v4);
        }
      }
    }
    v19 = cur_match & s->w_mask;
    v6 = s->prev[v19];
    cur_match = s->prev[v19];
    if ( v6 <= limit )
      break;
    --chain_length;
  }
  while ( chain_length );
  result = v21;
  if ( v5 <= v21 )
    result = v5;
  return result;
}

//----- (00601E5B) --------------------------------------------------------  // acclient.c:556424
void __userpurge fill_window(internal_state *s@<ebx>)
{
  unsigned int v1; // edx@1
  unsigned int v2; // ecx@2
  unsigned int v3; // esi@2
  int v4; // eax@2
  unsigned int v5; // ecx@9
  unsigned __int16 *v6; // eax@9
  int v7; // eax@9
  unsigned int v8; // esi@11
  unsigned __int16 *v9; // eax@11
  z_stream_s *v10; // esi@14
  unsigned int v11; // ecx@15
  char *v12; // edi@15
  unsigned int v13; // ecx@18
  internal_state *v14; // eax@19
  int v15; // eax@20
  z_stream_s *v16; // eax@21
  unsigned int v17; // edi@22
  char *v18; // esi@23
  unsigned int v19; // eax@23
  unsigned int v20; // ecx@23
  z_stream_s *v21; // [sp+8h] [bp-Ch]@14
  unsigned int wsize; // [sp+Ch] [bp-8h]@1
  unsigned int more; // [sp+10h] [bp-4h]@2
  unsigned int morea; // [sp+10h] [bp-4h]@15

  v1 = s->w_size;
  wsize = s->w_size;
  do
  {
    v2 = s->strstart;
    v3 = s->lookahead;
    v4 = s->window_size - v2 - v3;
    more = s->window_size - v2 - v3;
    if ( s->window_size - v2 == v3 )
    {
      if ( !v2 && !v3 )
      {
        v4 = v1;
        goto LABEL_14;
      }
    }
    else if ( v4 == -1 )
    {
      v4 = -2;
      goto LABEL_14;
    }
    if ( v2 >= v1 + s->w_size - 262 )
    {
      qmemcpy(s->window, &s->window[v1], v1);
      v5 = s->hash_size;
      v6 = s->head;
      s->match_start -= v1;
      s->strstart -= v1;
      s->block_start -= v1;
      v7 = (int)&v6[v5];
      do
      {
        v7 -= 2;
        --v5;
        *(_WORD *)v7 = (*(_WORD *)v7 - v1) & (unsigned int)~((*(_WORD *)v7 - (unsigned __int64)v1) >> 32);
      }
      while ( v5 );
      v8 = v1;
      v9 = &s->prev[v1];
      do
      {
        --v9;
        --v8;
        *v9 = (*v9 - v1) & (unsigned int)~((*v9 - (unsigned __int64)v1) >> 32);
      }
      while ( v8 );
      v4 = v1 + more;
    }
LABEL_14:
    v10 = s->strm;
    v21 = s->strm;
    if ( !s->strm->avail_in )
      break;
    v11 = v10->avail_in;
    v12 = &s->window[s->strstart] + s->lookahead;
    morea = v10->avail_in;
    if ( v11 > v4 )
      morea = v4;
    if ( morea )
    {
      v14 = v10->state;
      v10->avail_in = v11 - morea;
      if ( !v14->noheader )
      {
        v15 = d3dx_adler32(v10->adler, v10->next_in, morea);
        v1 = wsize;
        v10->adler = v15;
      }
      qmemcpy(v12, v10->next_in, morea);
      v13 = morea;
      v16 = v21;
      v16->next_in += morea;
      v16->total_in += morea;
    }
    else
    {
      v13 = 0;
    }
    s->lookahead += v13;
    v17 = s->lookahead;
    if ( v17 >= 3 )
    {
      v18 = &s->window[s->strstart];
      v19 = (unsigned __int8)*v18;
      v20 = s->hash_shift;
      s->ins_h = v19;
      s->ins_h = s->hash_mask & ((unsigned __int8)v18[1] ^ (v19 << v20));
    }
  }
  while ( v17 < 0x106 && s->strm->avail_in );
}

//----- (00601FB5) --------------------------------------------------------  // acclient.c:556544
int __stdcall deflate_stored(internal_state *s, int flush)
{
  unsigned int v2; // esi@1
  unsigned int v3; // eax@3
  bool v4; // zf@5
  int v5; // edx@5
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@5
  char *v8; // ecx@8
  int v9; // ecx@11
  unsigned int v10; // edx@11
  char *v11; // eax@13
  int v13; // esi@19
  char *v14; // eax@20

  v2 = 0xFFFF;
  if ( s->pending_buf_size - 5 < 0xFFFF )
    v2 = s->pending_buf_size - 5;
  while ( 1 )
  {
    v3 = s->lookahead;
    if ( v3 <= 1 )
    {
      fill_window(s);
      v3 = s->lookahead;
      if ( !v3 )
        break;
    }
    v4 = v3 + s->strstart == 0;
    s->strstart += v3;
    v5 = s->block_start;
    v6 = s->strstart;
    s->lookahead = 0;
    v7 = v5 + v2;
    if ( !v4 && v6 < v7
      || ((s->lookahead = v6 - v7, s->strstart = v7, v5 < 0) ? (v8 = 0) : (v8 = &s->window[v5]),
          d3dx__tr_flush_block(s, v8, v2, 0),
          s->block_start = s->strstart,
          flush_pending(s->strm),
          s->strm->avail_out) )
    {
      v9 = s->block_start;
      v10 = s->strstart - v9;
      if ( v10 < s->w_size - 262 )
        continue;
      v11 = v9 < 0 ? 0 : &s->window[v9];
      d3dx__tr_flush_block(s, v11, v10, 0);
      s->block_start = s->strstart;
      flush_pending(s->strm);
      if ( s->strm->avail_out )
        continue;
    }
    return 0;
  }
  if ( !flush )
    return 0;
  v13 = s->block_start;
  if ( v13 < 0 )
    v14 = 0;
  else
    v14 = &s->window[v13];
  d3dx__tr_flush_block(s, v14, s->strstart - v13, flush == 4);
  s->block_start = s->strstart;
  flush_pending(s->strm);
  if ( !s->strm->avail_out )
  {
    if ( flush == 4 )
      return 2;
    return 0;
  }
  return 2 * (flush == 4) + 1;
}

//----- (006020DB) --------------------------------------------------------  // acclient.c:556618
int __stdcall deflate_fast(internal_state *s, int flush)
{
  unsigned int v2; // edi@1
  unsigned int v3; // eax@2
  unsigned int v4; // edx@7
  unsigned int v5; // eax@7
  unsigned __int16 *v6; // ecx@7
  unsigned __int16 v7; // ax@13
  char v8; // cl@13
  unsigned __int16 v9; // ax@13
  char *v10; // ecx@13
  int v11; // eax@14
  unsigned int v12; // eax@16
  int v13; // ebx@16
  unsigned int v14; // edx@19
  int v15; // eax@19
  unsigned int v16; // edx@19
  unsigned __int16 *v17; // ecx@19
  unsigned int v18; // eax@19
  unsigned int v20; // eax@21
  char *v21; // ecx@21
  int v22; // edx@21
  unsigned int v23; // eax@21
  unsigned int v24; // ecx@21
  char v25; // al@22
  int v26; // ecx@25
  char *v27; // eax@26
  int result; // eax@29
  int v29; // ecx@31
  char *v30; // eax@32

  v2 = 0;
  while ( 1 )
  {
    v3 = s->lookahead;
    if ( v3 < 0x106 )
    {
      fill_window(s);
      v3 = s->lookahead;
      if ( v3 < 0x106 && !flush )
        return 0;
      if ( !v3 )
        break;
    }
    if ( v3 >= 3 )
    {
      v4 = s->strstart;
      v5 = s->hash_mask & (s->window[v4 + 2] ^ (s->ins_h << s->hash_shift));
      v6 = s->head;
      s->ins_h = v5;
      v2 = v6[v5];
      s->prev[v4 & s->w_mask] = v2;
      s->head[s->ins_h] = LOWORD(s->strstart);
    }
    if ( v2 && s->strstart - v2 <= s->w_size - 262 && s->strategy != 2 )
      s->match_length = longest_match(s, v2);
    if ( s->match_length < 3 )
    {
      v25 = s->window[s->strstart];
      s->d_buf[s->last_lit] = 0;
      s->l_buf[s->last_lit++] = v25;
      ++s->dyn_ltree[(unsigned __int8)v25].fc.freq;
      v13 = s->last_lit == s->lit_bufsize - 1;
      --s->lookahead;
    }
    else
    {
      v7 = LOWORD(s->strstart) - LOWORD(s->match_start);
      v8 = LOBYTE(s->match_length) - 3;
      s->d_buf[s->last_lit] = v7;
      s->l_buf[s->last_lit++] = v8;
      v9 = v7 - 1;
      v10 = (char *)&s->dyn_ltree[(unsigned __int8)d3dx__length_code[(unsigned __int8)v8] + 257];
      ++*(_WORD *)v10;
      if ( v9 >= 0x100u )
        v11 = (unsigned __int8)byte_7F5190[(unsigned int)v9 >> 7];
      else
        v11 = (unsigned __int8)d3dx__dist_code[v9];
      ++s->dyn_dtree[v11].fc.freq;
      v12 = s->match_length;
      v13 = s->last_lit == s->lit_bufsize - 1;
      s->lookahead -= v12;
      if ( v12 > s->max_lazy_match || s->lookahead < 3 )
      {
        s->strstart += v12;
        v20 = s->strstart;
        v21 = s->window;
        s->match_length = 0;
        v22 = (int)&v21[v20];
        v23 = (unsigned __int8)v21[v20];
        v24 = s->hash_shift;
        s->ins_h = v23;
        s->ins_h = s->hash_mask & (*(_BYTE *)(v22 + 1) ^ (v23 << v24));
        goto LABEL_24;
      }
      s->match_length = v12 - 1;
      do
      {
        ++s->strstart;
        v14 = s->strstart;
        v15 = s->window[v14 + 2];
        v16 = s->w_mask & v14;
        v17 = s->head;
        v18 = s->hash_mask & ((s->ins_h << s->hash_shift) ^ v15);
        s->ins_h = v18;
        v2 = v17[v18];
        s->prev[v16] = v2;
        s->head[s->ins_h] = LOWORD(s->strstart);
      }
      while ( s->match_length-- != 1 );
    }
    ++s->strstart;
LABEL_24:
    if ( v13 )
    {
      v26 = s->block_start;
      v27 = v26 < 0 ? 0 : &s->window[v26];
      d3dx__tr_flush_block(s, v27, s->strstart - v26, 0);
      s->block_start = s->strstart;
      flush_pending(s->strm);
      if ( !s->strm->avail_out )
        return 0;
    }
  }
  v29 = s->block_start;
  if ( v29 < 0 )
    v30 = 0;
  else
    v30 = &s->window[v29];
  d3dx__tr_flush_block(s, v30, s->strstart - v29, flush == 4);
  s->block_start = s->strstart;
  flush_pending(s->strm);
  if ( s->strm->avail_out )
  {
    result = 2 * (flush == 4) + 1;
  }
  else
  {
    if ( flush != 4 )
      return 0;
    result = 2;
  }
  return result;
}

//----- (00602387) --------------------------------------------------------  // acclient.c:556764
int __stdcall deflate_slow(internal_state *s, int flush)
{
  unsigned int v2; // eax@2
  int result; // eax@5
  unsigned int v4; // edx@9
  unsigned int v5; // eax@9
  unsigned __int16 *v6; // ecx@9
  unsigned int v7; // eax@9
  unsigned int v8; // eax@15
  unsigned int v9; // eax@20
  unsigned int v10; // ebx@22
  char v11; // cl@22
  unsigned __int16 v12; // ax@22
  unsigned __int16 v13; // ax@22
  char *v14; // ecx@22
  int v15; // eax@23
  unsigned int v16; // eax@25
  int v17; // edi@25
  unsigned int v18; // edx@26
  unsigned int v19; // eax@27
  unsigned __int16 *v20; // ecx@27
  unsigned int v21; // eax@27
  unsigned int v23; // eax@29
  int v24; // edx@30
  char *v25; // ecx@31
  char v26; // al@37
  int v27; // ecx@38
  char *v28; // eax@39
  char v29; // cl@45
  int v30; // ecx@46
  char *v31; // eax@47
  unsigned int hash_head; // [sp+Ch] [bp-4h]@1

  hash_head = 0;
  while ( 1 )
  {
    v2 = s->lookahead;
    if ( v2 < 0x106 )
    {
      fill_window(s);
      v2 = s->lookahead;
      if ( v2 < 0x106 && !flush )
        return 0;
      if ( !v2 )
        break;
    }
    if ( v2 >= 3 )
    {
      v4 = s->strstart;
      v5 = s->hash_mask & (s->window[v4 + 2] ^ (s->ins_h << s->hash_shift));
      v6 = s->head;
      s->ins_h = v5;
      v7 = v6[v5];
      s->prev[v4 & s->w_mask] = v7;
      hash_head = v7;
      s->head[s->ins_h] = LOWORD(s->strstart);
    }
    s->prev_length = s->match_length;
    s->prev_match = s->match_start;
    s->match_length = 2;
    if ( hash_head && s->prev_length < s->max_lazy_match && s->strstart - hash_head <= s->w_size - 262 )
    {
      if ( s->strategy != 2 )
        s->match_length = longest_match(s, hash_head);
      v8 = s->match_length;
      if ( v8 <= 5 && (s->strategy == 1 || v8 == 3 && s->strstart - s->match_start > 0x1000) )
        s->match_length = 2;
    }
    v9 = s->prev_length;
    if ( v9 < 3 || s->match_length > v9 )
    {
      if ( s->match_available )
      {
        v26 = s->window[s->strstart - 1];
        s->d_buf[s->last_lit] = 0;
        s->l_buf[s->last_lit++] = v26;
        ++s->dyn_ltree[(unsigned __int8)v26].fc.freq;
        if ( s->last_lit == s->lit_bufsize - 1 )
        {
          v27 = s->block_start;
          if ( v27 < 0 )
            v28 = 0;
          else
            v28 = &s->window[v27];
          d3dx__tr_flush_block(s, v28, s->strstart - v27, 0);
          s->block_start = s->strstart;
          flush_pending(s->strm);
        }
        ++s->strstart;
        --s->lookahead;
        goto LABEL_34;
      }
      ++s->strstart;
      --s->lookahead;
      s->match_available = 1;
    }
    else
    {
      v10 = s->strstart + s->lookahead - 3;
      v11 = LOBYTE(s->prev_length) - 3;
      v12 = LOWORD(s->strstart) - LOWORD(s->prev_match) - 1;
      s->d_buf[s->last_lit] = v12;
      s->l_buf[s->last_lit++] = v11;
      v13 = v12 - 1;
      v14 = (char *)&s->dyn_ltree[(unsigned __int8)d3dx__length_code[(unsigned __int8)v11] + 257];
      ++*(_WORD *)v14;
      if ( v13 >= 0x100u )
        v15 = (unsigned __int8)byte_7F5190[(unsigned int)v13 >> 7];
      else
        v15 = (unsigned __int8)d3dx__dist_code[v13];
      ++s->dyn_dtree[v15].fc.freq;
      v16 = s->prev_length;
      v17 = s->last_lit == s->lit_bufsize - 1;
      s->lookahead += 1 - v16;
      s->prev_length = v16 - 2;
      do
      {
        ++s->strstart;
        v18 = s->strstart;
        if ( v18 <= v10 )
        {
          v19 = s->hash_mask & (s->window[v18 + 2] ^ (s->ins_h << s->hash_shift));
          v20 = s->head;
          s->ins_h = v19;
          v21 = v20[v19];
          s->prev[v18 & s->w_mask] = v21;
          hash_head = v21;
          s->head[s->ins_h] = LOWORD(s->strstart);
        }
      }
      while ( s->prev_length-- != 1 );
      s->match_available = 0;
      ++s->strstart;
      v23 = s->strstart;
      s->match_length = 2;
      if ( v17 )
      {
        v24 = s->block_start;
        if ( v24 < 0 )
          v25 = 0;
        else
          v25 = &s->window[v24];
        d3dx__tr_flush_block(s, v25, v23 - v24, 0);
        s->block_start = s->strstart;
        flush_pending(s->strm);
LABEL_34:
        if ( !s->strm->avail_out )
          return 0;
      }
    }
  }
  if ( s->match_available )
  {
    v29 = s->window[s->strstart - 1];
    s->d_buf[s->last_lit] = 0;
    s->l_buf[s->last_lit++] = v29;
    ++s->dyn_ltree[(unsigned __int8)v29].fc.freq;
    s->match_available = 0;
  }
  v30 = s->block_start;
  if ( v30 < 0 )
    v31 = 0;
  else
    v31 = &s->window[v30];
  d3dx__tr_flush_block(s, v31, s->strstart - v30, flush == 4);
  s->block_start = s->strstart;
  flush_pending(s->strm);
  if ( s->strm->avail_out )
  {
    result = 2 * (flush == 4) + 1;
  }
  else
  {
    if ( flush != 4 )
      return 0;
    result = 2;
  }
  return result;
}

