/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : GameTime
   Object     : PORTAL\gametime\GameTime.obj
   Functions  : 15
   Addresses  : 00502690 - 005A6EC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00502690) --------------------------------------------------------  // acclient.c:303501
int __thiscall AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(AC1Legacy::SmartArray<Season *> *this, unsigned int _size)
{
  AC1Legacy::SmartArray<Season *> *v2; // esi@1
  Season **v3; // ST00_4@4
  void *v5; // edi@5
  unsigned int v6; // eax@7

  v2 = this;
  if ( _size >= this->m_num )
  {
    if ( _size <= this->m_size )
      return 1;
    if ( !_size )
    {
      v3 = this->m_data;
      this->m_num = 0;
      this->m_size = 0;
      operator delete[](v3);
      v2->m_data = 0;
      return 1;
    }
    v5 = operator new[](4 * _size);
    if ( v5 )
    {
      if ( v2->m_data )
      {
        v6 = 0;
        if ( v2->m_num )
        {
          do
          {
            *((_DWORD *)v5 + v6) = v2->m_data[v6];
            ++v6;
          }
          while ( v6 < v2->m_num );
        }
        operator delete[](v2->m_data);
      }
      v2->m_data = (Season **)v5;
      v2->m_size = _size;
      return 1;
    }
  }
  return 0;
}

//----- (005A6400) --------------------------------------------------------  // acclient.c:463202
void __thiscall GameTime::CalcDayBegin(GameTime *this, long double time)
{
  GameTime *v2; // esi@1
  long double total_time; // ST0C_8@1
  double v4; // st7@1
  unsigned __int64 v5; // rax@1
  double v6; // st7@1
  unsigned __int64 v7; // rax@1
  int v8; // ecx@1
  int v9; // ecx@2
  double offset_in_year; // [sp+14h] [bp-8h]@1

  v2 = this;
  total_time = time + this->zero_time_of_year;
  v4 = _floor(total_time / this->year_length);
  v5 = (unsigned __int64)v4;
  v6 = total_time - v4 * v2->year_length;
  v2->current_year = v2->zero_year + v5;
  offset_in_year = v6;
  v7 = (unsigned __int64)_floor(v6 / v2->day_length);
  HIDWORD(v7) = 0;
  v8 = v2->seasons.m_num - 1;
  v2->current_day = v7;
  if ( v8 )
  {
    v9 = (int)(v2->seasons.m_data + 1);
    do
    {
      if ( (signed int)v7 < *(_DWORD *)(*(_DWORD *)v9 + 4) )
        break;
      ++HIDWORD(v7);
      v9 += 4;
    }
    while ( HIDWORD(v7) < v2->seasons.m_num - 1 );
  }
  v2->current_season = HIDWORD(v7);
  v2->time_of_day_begin = time - (offset_in_year - (double)(signed int)v7 * v2->day_length);
}

//----- (005A64A0) --------------------------------------------------------  // acclient.c:463242
void __thiscall GameTime::CalcTimeOfDay(GameTime *this, long double time)
{
  unsigned int v2; // eax@1
  long double v3; // st7@1
  int v4; // edi@1
  int v5; // edx@1
  TimeOfDay **v6; // esi@2
  TimeOfDay **v7; // eax@5
  int v8; // eax@7

  v2 = this->times_of_day.m_num;
  v3 = (time - this->time_of_day_begin) / this->day_length;
  v4 = v2 - 1;
  v5 = 0;
  if ( v2 != 1 )
  {
    v6 = this->times_of_day.m_data + 1;
    do
    {
      if ( v3 < (*v6)->begin )
        break;
      ++v5;
      ++v6;
    }
    while ( v5 < this->times_of_day.m_num - 1 );
  }
  v7 = this->times_of_day.m_data;
  this->current_time_of_day = v5;
  if ( v5 == v4 )
  {
    this->time_of_next_event = this->day_length + this->time_of_day_begin;
    this->present_time_in_day_unit = (v3 - v7[v5]->begin) / (this->day_length - v7[v5]->begin);
  }
  else
  {
    v8 = (int)&v7[v5];
    this->time_of_next_event = *(float *)(*(_DWORD *)(v8 + 4) + 4) * this->day_length + this->time_of_day_begin;
    this->present_time_in_day_unit = (v3 - *(float *)(*(_DWORD *)v8 + 4))
                                   / (*(float *)(*(_DWORD *)(v8 + 4) + 4) - *(float *)(*(_DWORD *)v8 + 4));
  }
}

//----- (005A6530) --------------------------------------------------------  // acclient.c:463285
void __thiscall GameTime::GetDateTimeString(GameTime *this, char *date_string, char *time_string, const int year, const int season, const int weekday, const int day, const int time_of_day)
{
  GameTime *v8; // edi@1
  TimeOfDay *v9; // edx@1
  int v10; // ecx@1
  int v11; // eax@1
  int v12; // esi@1
  char v13; // dl@2
  int v14; // eax@4
  char *v15; // edx@4
  char v16; // cl@5
  Season *v17; // eax@8
  const char *v18; // ebx@8
  unsigned int v19; // kr00_4@8
  unsigned int v20; // kr04_4@8
  int v21; // ecx@8
  int v22; // eax@8
  int v23; // edi@8
  char v24; // dl@9
  char year_str[20]; // [sp+Ch] [bp-28h]@8
  char day_str[20]; // [sp+20h] [bp-14h]@8
  char *time_stringa; // [sp+3Ch] [bp+8h]@8

  v8 = this;
  v9 = this->times_of_day.m_data[time_of_day];
  v10 = (int)v9->time_of_day_name.m_buffer->m_data;
  v11 = (int)v9->time_of_day_name.m_buffer->m_data;
  v12 = (int)&v9->time_of_day_name.m_buffer->m_data[1];
  do
    v13 = *(_BYTE *)v11++;
  while ( v13 );
  if ( (unsigned int)(v11 - v12) >= 0x1E )
  {
    *(_WORD *)time_string = 32;
  }
  else
  {
    v14 = v10;
    v15 = &time_string[-v10];
    do
    {
      v16 = *(_BYTE *)v14;
      v15[v14] = *(_BYTE *)v14;
      ++v14;
    }
    while ( v16 );
  }
  v17 = v8->seasons.m_data[season];
  v18 = v17->season_name.m_buffer->m_data;
  _sprintf(day_str, "%d", day - v17->begin + 1);
  _sprintf(year_str, "%d", year);
  time_stringa = (char *)strlen(v18);
  v19 = strlen(day_str);
  v20 = strlen(year_str);
  v21 = (int)v8->year_spec.m_buffer->m_data;
  v22 = (int)v8->year_spec.m_buffer->m_data;
  v23 = (int)&v8->year_spec.m_buffer->m_data[1];
  do
    v24 = *(_BYTE *)v22++;
  while ( v24 );
  if ( (unsigned int)(&time_stringa[v20 + 9] + v22 - v23 + v19) >= 0x3C )
    *(_WORD *)date_string = 32;
  else
    _sprintf(date_string, "%s %s, %s %s", v18, day_str, year_str, v21);
}

//----- (005A6660) --------------------------------------------------------  // acclient.c:463352
void __thiscall GameTime::GameTime(GameTime *this)
{
  GameTime *v1; // esi@1
  volatile LONG *v2; // ST00_4@1

  v1 = this;
  *(_QWORD *)&this->zero_time_of_year = 0i64;
  this->zero_year = 0;
  LODWORD(this->day_length) = 0;
  this->days_per_year = 0;
  this->times_of_day.m_data = 0;
  this->times_of_day.m_size = 0;
  this->times_of_day.m_num = 0;
  this->days_of_the_week.m_data = 0;
  this->days_of_the_week.m_size = 0;
  this->days_of_the_week.m_num = 0;
  this->seasons.m_data = 0;
  this->seasons.m_size = 0;
  this->seasons.m_num = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->year_spec.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  LODWORD(v1->year_length) = 0;
  HIDWORD(v1->year_length) = 0;
  LODWORD(v1->present_time_of_day) = 0;
  LODWORD(v1->time_of_day_begin) = 0;
  LODWORD(v1->time_of_next_event) = 0;
  HIDWORD(v1->time_of_next_event) = 0;
  v1->current_year = 0;
  v1->current_day = 0;
  v1->current_season = 0;
  v1->current_week_day = 0;
  v1->current_time_of_day = 0;
  LODWORD(v1->clock_offset) = 0;
  HIDWORD(v1->clock_offset) = 0;
  LODWORD(v1->time_zero_start_delta) = 0;
  HIDWORD(v1->time_zero_start_delta) = 0;
  HIDWORD(v1->time_of_day_begin) = -1074790400;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005A66F0) --------------------------------------------------------  // acclient.c:463394
void __thiscall GameTime::UseTime(GameTime *this)
{
  GameTime *v1; // esi@1
  long double v2; // st7@3
  long double time; // [sp+Ch] [bp-8h]@1

  v1 = this;
  time = COERCE_DOUBLE(Timer::cur_time.Cmd) + this->clock_offset + this->time_zero_start_delta;
  if ( this->time_of_day_begin < 0.0 )
    GameTime::CalcDayBegin(this, time);
  v2 = (time - v1->time_of_day_begin) / v1->day_length;
  v1->present_time_of_day = v2;
  if ( time >= v1->time_of_next_event )
  {
    if ( v2 >= 1.0 )
    {
      GameTime::CalcDayBegin(v1, time);
      v1->present_time_of_day = (time - v1->time_of_day_begin) / v1->day_length;
    }
    GameTime::CalcTimeOfDay(v1, time);
    GameTime::global_next_event = v1->time_of_next_event - v1->clock_offset + v1->time_zero_start_delta;
  }
}
// 8ED9B0: using guessed type double GameTime::global_next_event;

//----- (005A67A0) --------------------------------------------------------  // acclient.c:463420
void __thiscall GameTime::GetDateTimeString(GameTime *this, char *date_string, char *time_string)
{
  GameTime::GetDateTimeString(
    this,
    date_string,
    time_string,
    this->current_year,
    this->current_season,
    this->current_week_day,
    this->current_day,
    this->current_time_of_day);
}

//----- (005A67D0) --------------------------------------------------------  // acclient.c:463434
void __thiscall GameTime::Destroy(GameTime *this)
{
  GameTime *v1; // esi@1
  unsigned int v2; // ecx@1
  unsigned int v3; // eax@1
  void *v4; // ebp@2
  int v5; // ebx@3
  void *v6; // ST00_4@8
  unsigned int v7; // eax@8
  void *v8; // ebp@9
  int v9; // ebx@10
  void *v10; // ST00_4@15
  unsigned int v11; // eax@15
  void *v12; // ebp@16
  int v13; // ebx@17
  void *v14; // ST00_4@22
  unsigned int iq; // [sp+10h] [bp-4h]@1
  unsigned int iqa; // [sp+10h] [bp-4h]@8
  unsigned int iqb; // [sp+10h] [bp-4h]@15

  v1 = this;
  v2 = this->seasons.m_num;
  v3 = 0;
  LODWORD(v1->zero_time_of_year) = 0;
  HIDWORD(v1->zero_time_of_year) = 0;
  v1->zero_year = 0;
  LODWORD(v1->day_length) = 0;
  LODWORD(v1->year_length) = 0;
  HIDWORD(v1->year_length) = 0;
  v1->days_per_year = 0;
  LODWORD(v1->present_time_of_day) = 0;
  LODWORD(v1->time_of_day_begin) = 0;
  HIDWORD(v1->time_of_day_begin) = -1074790400;
  LODWORD(v1->time_of_next_event) = 0;
  HIDWORD(v1->time_of_next_event) = 0;
  v1->current_year = 0;
  v1->current_day = 0;
  v1->current_season = 0;
  v1->current_week_day = 0;
  v1->current_time_of_day = 0;
  LODWORD(v1->clock_offset) = 0;
  HIDWORD(v1->clock_offset) = 0;
  iq = 0;
  if ( v2 )
  {
    do
    {
      v4 = v1->seasons.m_data[v3];
      if ( v4 )
      {
        v5 = *(_DWORD *)v4;
        if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v4 + 4)) && v5 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
        operator delete(v4);
        v3 = iq;
      }
      ++v3;
      iq = v3;
    }
    while ( v3 < v1->seasons.m_num );
  }
  v6 = v1->seasons.m_data;
  v1->seasons.m_num = 0;
  v1->seasons.m_size = 0;
  operator delete[](v6);
  v1->seasons.m_data = 0;
  v7 = 0;
  for ( iqa = 0; v7 < v1->times_of_day.m_num; iqa = v7 )
  {
    v8 = v1->times_of_day.m_data[v7];
    if ( v8 )
    {
      v9 = *(_DWORD *)v8;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v8 + 4)) && v9 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
      operator delete(v8);
      v7 = iqa;
    }
    ++v7;
  }
  v10 = v1->times_of_day.m_data;
  v1->times_of_day.m_num = 0;
  v1->times_of_day.m_size = 0;
  operator delete[](v10);
  v1->times_of_day.m_data = 0;
  v11 = 0;
  for ( iqb = 0; v11 < v1->days_of_the_week.m_num; iqb = v11 )
  {
    v12 = v1->days_of_the_week.m_data[v11];
    if ( v12 )
    {
      v13 = *(_DWORD *)v12;
      if ( !InterlockedDecrement((volatile LONG *)(*(_DWORD *)v12 + 4)) && v13 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
      operator delete(v12);
      v11 = iqb;
    }
    ++v11;
  }
  v14 = v1->days_of_the_week.m_data;
  v1->days_of_the_week.m_num = 0;
  v1->days_of_the_week.m_size = 0;
  operator delete[](v14);
  v1->days_of_the_week.m_data = 0;
}

//----- (005A6950) --------------------------------------------------------  // acclient.c:463541
int __thiscall GameTime::pack_size(GameTime *this)
{
  unsigned int v1; // eax@1
  signed int v2; // edx@1
  int v3; // esi@3
  int v4; // eax@3
  int v5; // edx@4
  int v6; // esi@6
  int v7; // edx@7
  int v8; // eax@9
  TimeOfDay **v9; // ebx@10
  unsigned int v10; // ebp@10
  int v11; // edx@11
  signed int v12; // esi@11
  int v13; // edi@13
  int v14; // edx@13
  int v15; // esi@14
  int v16; // edi@16
  int v17; // esi@17
  int v18; // eax@20
  WeekDay **v19; // ebx@21
  unsigned int v20; // ebp@21
  int v21; // edx@22
  signed int v22; // esi@22
  int v23; // edi@24
  int v24; // edx@24
  int v25; // esi@25
  int v26; // edi@27
  int v27; // esi@28
  int result; // eax@31
  Season **v29; // edi@32
  unsigned int v30; // ebx@32
  int v31; // ecx@33
  signed int v32; // edx@33
  int v33; // esi@35
  int v34; // ecx@35
  int v35; // edx@36
  int v36; // esi@38
  int v37; // edx@39

  v1 = this->year_spec.m_buffer->m_len - 1;
  v2 = 0;
  if ( v1 >= 0xFFFF )
    v2 = 4;
  v3 = v2 + v1 + 2;
  v4 = ((_BYTE)v2 + (_BYTE)v1 + 2) & 3;
  if ( v4 )
    v5 = 4 - v4;
  else
    v5 = 0;
  v6 = v5 + v3 + 20;
  if ( v6 & 3 )
    v7 = 4 - (v6 & 3);
  else
    v7 = 0;
  v8 = v6 + v7 + 4;
  if ( this->times_of_day.m_num )
  {
    v9 = this->times_of_day.m_data;
    v10 = this->times_of_day.m_num;
    do
    {
      v11 = (*v9)->time_of_day_name.m_buffer->m_len - 1;
      v12 = 0;
      if ( (unsigned int)v11 >= 0xFFFF )
        v12 = 4;
      v13 = v12 + v11 + 2;
      v14 = ((_BYTE)v12 + (_BYTE)v11 + 2) & 3;
      if ( v14 )
        v15 = 4 - v14;
      else
        v15 = 0;
      v16 = v15 + v13 + 8;
      if ( v16 & 3 )
        v17 = 4 - (v16 & 3);
      else
        v17 = 0;
      v8 += v16 + v17;
      ++v9;
      --v10;
    }
    while ( v10 );
  }
  v18 = v8 + 4;
  if ( this->days_of_the_week.m_num )
  {
    v19 = this->days_of_the_week.m_data;
    v20 = this->days_of_the_week.m_num;
    do
    {
      v21 = (*v19)->week_day_name.m_buffer->m_len - 1;
      v22 = 0;
      if ( (unsigned int)v21 >= 0xFFFF )
        v22 = 4;
      v23 = v22 + v21 + 2;
      v24 = ((_BYTE)v22 + (_BYTE)v21 + 2) & 3;
      if ( v24 )
        v25 = 4 - v24;
      else
        v25 = 0;
      v26 = v25 + v23;
      if ( v26 & 3 )
        v27 = 4 - (v26 & 3);
      else
        v27 = 0;
      v18 += v26 + v27;
      ++v19;
      --v20;
    }
    while ( v20 );
  }
  result = v18 + 4;
  if ( this->seasons.m_num )
  {
    v29 = this->seasons.m_data;
    v30 = this->seasons.m_num;
    do
    {
      v31 = (*v29)->season_name.m_buffer->m_len - 1;
      v32 = 0;
      if ( (unsigned int)v31 >= 0xFFFF )
        v32 = 4;
      v33 = v32 + v31 + 2;
      v34 = ((_BYTE)v32 + (_BYTE)v31 + 2) & 3;
      if ( v34 )
        v35 = 4 - v34;
      else
        v35 = 0;
      v36 = v35 + v33 + 4;
      if ( v36 & 3 )
        v37 = 4 - (v36 & 3);
      else
        v37 = 0;
      result += v36 + v37;
      ++v29;
      --v30;
    }
    while ( v30 );
  }
  return result;
}

//----- (005A6AC0) --------------------------------------------------------  // acclient.c:463684
unsigned int __thiscall GameTime::Pack(GameTime *this, void **addr, unsigned int *size)
{
  unsigned int *v3; // esi@1
  GameTime *v4; // ebx@1
  unsigned int v5; // eax@4
  unsigned int v6; // eax@5
  unsigned int v7; // eax@7
  unsigned int v8; // ebp@9
  TimeOfDay *v9; // ecx@10
  int v10; // eax@11
  int v11; // ecx@13
  int v12; // edx@13
  int v13; // eax@14
  unsigned int v14; // ebp@18
  unsigned int v15; // ebx@20
  int v16; // ecx@21
  unsigned int v17; // edx@21
  int v18; // eax@21
  int v19; // ecx@22
  unsigned int v20; // ebp@26
  unsigned int v21; // ebx@28
  Season *v22; // ecx@29
  int v23; // ecx@31
  int v24; // edx@31
  int v25; // eax@32
  GameTime *v27; // [sp+10h] [bp-4h]@1
  unsigned int *sizea; // [sp+1Ch] [bp+8h]@7

  v3 = size;
  v4 = this;
  v27 = this;
  if ( *size >= 8 )
  {
    *(_QWORD *)*addr = *(_QWORD *)&this->zero_time_of_year;
    *addr = (char *)*addr + 8;
    *size -= 8;
  }
  if ( *size >= 4 )
  {
    *(_DWORD *)*addr = this->zero_year;
    *addr = (char *)*addr + 4;
    v5 = *size - 4;
    *size = v5;
    if ( v5 >= 4 )
    {
      *(float *)*addr = this->day_length;
      *addr = (char *)*addr + 4;
      v6 = *size - 4;
      *size = v6;
      if ( v6 >= 4 )
      {
        *(_DWORD *)*addr = this->days_per_year;
        *addr = (char *)*addr + 4;
        *size -= 4;
      }
    }
  }
  *size -= AC1Legacy::PStringBase<char>::Pack(&this->year_spec, addr, *size);
  PackObj::ALIGN_PTR(addr, size);
  v7 = v4->times_of_day.m_num;
  sizea = (unsigned int *)v4->times_of_day.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v7;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v8 = 0;
  if ( v7 )
  {
    do
    {
      v9 = v4->times_of_day.m_data[v8];
      if ( *v3 >= 4 )
      {
        *(float *)*addr = v9->begin;
        *addr = (char *)*addr + 4;
        v10 = *v3 - 4;
        *v3 = v10;
        if ( (unsigned int)v10 >= 4 )
        {
          *(_DWORD *)*addr = v9->is_night;
          *addr = (char *)*addr + 4;
          *v3 -= 4;
        }
      }
      v11 = *v3 - AC1Legacy::PStringBase<char>::Pack(&v9->time_of_day_name, addr, *v3);
      *v3 = v11;
      v12 = (signed int)*addr % 4;
      if ( v12 )
      {
        v13 = 4 - v12;
        if ( v11 >= (unsigned int)(4 - v12) )
        {
          *v3 = v11 - v13;
          if ( 4 != v12 )
          {
            do
            {
              *(_BYTE *)*addr = 0;
              --v13;
              *addr = (char *)*addr + 1;
            }
            while ( v13 );
          }
        }
      }
      ++v8;
    }
    while ( v8 < (unsigned int)sizea );
  }
  v14 = v4->days_of_the_week.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v14;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v15 = 0;
  if ( v14 )
  {
    do
    {
      v16 = *v3 - AC1Legacy::PStringBase<char>::Pack(&v27->days_of_the_week.m_data[v15]->week_day_name, addr, *v3);
      *v3 = v16;
      v17 = v16;
      v18 = (signed int)*addr % 4;
      if ( v18 )
      {
        v19 = 4 - v18;
        if ( v17 >= 4 - v18 )
        {
          *v3 = v17 - v19;
          if ( 4 != v18 )
          {
            do
            {
              *(_BYTE *)*addr = 0;
              --v19;
              *addr = (char *)*addr + 1;
            }
            while ( v19 );
          }
        }
      }
      ++v15;
    }
    while ( v15 < v14 );
  }
  v20 = v27->seasons.m_num;
  if ( *v3 >= 4 )
  {
    *(_DWORD *)*addr = v20;
    *addr = (char *)*addr + 4;
    *v3 -= 4;
  }
  v21 = 0;
  if ( v20 )
  {
    do
    {
      v22 = v27->seasons.m_data[v21];
      if ( *v3 >= 4 )
      {
        *(_DWORD *)*addr = v22->begin;
        *addr = (char *)*addr + 4;
        *v3 -= 4;
      }
      v23 = *v3 - AC1Legacy::PStringBase<char>::Pack(&v22->season_name, addr, *v3);
      *v3 = v23;
      v24 = (signed int)*addr % 4;
      if ( v24 )
      {
        v25 = 4 - v24;
        if ( v23 >= (unsigned int)(4 - v24) )
        {
          *v3 = v23 - v25;
          if ( 4 != v24 )
          {
            do
            {
              *(_BYTE *)*addr = 0;
              --v25;
              *addr = (char *)*addr + 1;
            }
            while ( v25 );
          }
        }
      }
      ++v21;
    }
    while ( v21 < v20 );
  }
  return *v3;
}

//----- (005A6CE0) --------------------------------------------------------  // acclient.c:463881
int __thiscall Season::UnPack(Season *this, void **addr, unsigned int *size)
{
  Season *v3; // edi@1
  int result; // eax@3
  int v5; // eax@4
  signed int v6; // ecx@4
  int v7; // edx@6
  int v8; // ecx@6
  int v9; // eax@7

  v3 = this;
  if ( *size >= 4 )
  {
    this->begin = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    *size -= 4;
  }
  result = AC1Legacy::PStringBase<char>::UnPack(&this->season_name, addr, *size);
  if ( result )
  {
    v5 = v3->season_name.m_buffer->m_len - 1;
    v6 = 0;
    if ( (unsigned int)v5 >= 0xFFFF )
      v6 = 4;
    v7 = v6 + v5 + 2;
    v8 = ((_BYTE)v6 + (_BYTE)v5 + 2) & 3;
    if ( v8 )
      v9 = 4 - v8;
    else
      v9 = 0;
    *size -= v7 + v9;
    PackObj::ALIGN_PTR(addr, size);
    result = *size > 0;
  }
  return result;
}

//----- (005A6D60) --------------------------------------------------------  // acclient.c:463919
int __thiscall WeekDay::UnPack(WeekDay *this, void **addr, unsigned int *size)
{
  WeekDay *v3; // esi@1
  int result; // eax@1
  int v5; // eax@2
  signed int v6; // ecx@2
  int v7; // edx@4
  int v8; // ecx@4
  int v9; // eax@5

  v3 = this;
  result = AC1Legacy::PStringBase<char>::UnPack(&this->week_day_name, addr, *size);
  if ( result )
  {
    v5 = v3->week_day_name.m_buffer->m_len - 1;
    v6 = 0;
    if ( (unsigned int)v5 >= 0xFFFF )
      v6 = 4;
    v7 = v6 + v5 + 2;
    v8 = ((_BYTE)v6 + (_BYTE)v5 + 2) & 3;
    if ( v8 )
      v9 = 4 - v8;
    else
      v9 = 0;
    *size -= v7 + v9;
    PackObj::ALIGN_PTR(addr, size);
    result = *size > 0;
  }
  return result;
}

//----- (005A6DD0) --------------------------------------------------------  // acclient.c:463951
int __thiscall TimeOfDay::UnPack(TimeOfDay *this, void **addr, unsigned int *size)
{
  TimeOfDay *v3; // ebx@1
  unsigned int v4; // eax@2
  int result; // eax@4
  int v6; // eax@5
  signed int v7; // ecx@5
  int v8; // edx@7
  int v9; // ecx@7
  int v10; // eax@8

  v3 = this;
  if ( *size >= 4 )
  {
    LODWORD(this->begin) = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v4 = *size - 4;
    *size = v4;
    if ( v4 >= 4 )
    {
      this->is_night = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      *size -= 4;
    }
  }
  result = AC1Legacy::PStringBase<char>::UnPack(&this->time_of_day_name, addr, *size);
  if ( result )
  {
    v6 = v3->time_of_day_name.m_buffer->m_len - 1;
    v7 = 0;
    if ( (unsigned int)v6 >= 0xFFFF )
      v7 = 4;
    v8 = v7 + v6 + 2;
    v9 = ((_BYTE)v7 + (_BYTE)v6 + 2) & 3;
    if ( v9 )
      v10 = 4 - v9;
    else
      v10 = 0;
    *size -= v8 + v10;
    PackObj::ALIGN_PTR(addr, size);
    result = *size > 0;
  }
  return result;
}

//----- (005A6E70) --------------------------------------------------------  // acclient.c:463997
void __thiscall GameTime::~GameTime(GameTime *this)
{
  GameTime *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1

  v1 = this;
  GameTime::Destroy(this);
  v2 = v1->year_spec.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
    v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
  operator delete[](v1->seasons.m_data);
  operator delete[](v1->days_of_the_week.m_data);
  operator delete[](v1->times_of_day.m_data);
}

//----- (005A6EC0) --------------------------------------------------------  // acclient.c:464013
int __thiscall GameTime::UnPack(GameTime *this, void **addr, unsigned int *size)
{
  void **v3; // ebx@1
  unsigned int *v4; // esi@1
  GameTime *v5; // ebp@1
  void *v6; // eax@2
  unsigned int v7; // eax@4
  unsigned int v8; // eax@5
  char *v9; // edi@7
  int v10; // eax@8
  signed int v11; // ecx@8
  int v12; // eax@10
  int v13; // ecx@11
  unsigned int v14; // edi@14
  int v15; // ebp@17
  void *v16; // edi@18
  volatile LONG *v17; // ST04_4@19
  unsigned int v18; // eax@22
  unsigned int v19; // eax@24
  unsigned int v20; // ecx@31
  WeekDay *v21; // edi@34
  volatile LONG *v22; // ST04_4@35
  unsigned int v23; // eax@38
  unsigned int v24; // eax@40
  unsigned int v25; // ecx@47
  void *v26; // edi@50
  volatile LONG *v27; // ST04_4@51
  unsigned int v28; // eax@54
  unsigned int v29; // eax@56
  GameTime *v31; // [sp+10h] [bp-4h]@1
  void **addra; // [sp+18h] [bp+4h]@17
  void **addrb; // [sp+18h] [bp+4h]@33
  void **addrc; // [sp+18h] [bp+4h]@49
  int iq; // [sp+1Ch] [bp+8h]@7

  v3 = addr;
  v4 = size;
  v5 = this;
  v31 = this;
  if ( *size >= 8 )
  {
    v6 = *addr;
    LODWORD(this->zero_time_of_year) = *(_DWORD *)*addr;
    HIDWORD(this->zero_time_of_year) = *((_DWORD *)v6 + 1);
    *addr = (char *)*addr + 8;
    *size -= 8;
  }
  if ( *size >= 4 )
  {
    this->zero_year = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    v7 = *size - 4;
    *size = v7;
    if ( v7 >= 4 )
    {
      LODWORD(this->day_length) = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      v8 = *size - 4;
      *size = v8;
      if ( v8 >= 4 )
      {
        this->days_per_year = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        *size -= 4;
      }
    }
  }
  iq = this->days_per_year;
  v9 = (char *)&this->year_spec;
  this->year_length = this->day_length * (double)iq;
  if ( AC1Legacy::PStringBase<char>::UnPack(&this->year_spec, addr, *v4) )
  {
    v10 = *(_DWORD *)(*(_DWORD *)v9 + 8) - 1;
    v11 = 0;
    if ( (unsigned int)v10 >= 0xFFFF )
      v11 = 4;
    v12 = v11 + v10 + 2;
    v13 = v12 & 3 ? 4 - (v12 & 3) : 0;
    *v4 -= v12 + v13;
    PackObj::ALIGN_PTR(addr, v4);
    if ( *v4 < 4 )
    {
      v14 = iq;
    }
    else
    {
      v14 = *(_DWORD *)*addr;
      *addr = (char *)*addr + 4;
      iq = v14;
      *v4 -= 4;
    }
    if ( v14 <= *v4 )
    {
      v15 = (int)&v5->times_of_day;
      AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v15, v14);
      addra = 0;
      if ( v14 )
      {
        while ( 1 )
        {
          v16 = operator new(0xCu);
          if ( v16 )
          {
            v17 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
            *(_DWORD *)v16 = AC1Legacy::PStringBase<char>::s_NullBuffer;
            InterlockedIncrement(v17);
            *((_DWORD *)v16 + 1) = 0;
          }
          else
          {
            v16 = 0;
          }
          if ( !TimeOfDay::UnPack((TimeOfDay *)v16, v3, v4) )
            break;
          v18 = *(_DWORD *)(v15 + 4);
          if ( *(_DWORD *)(v15 + 8) < v18
            || (!v18 ? (v19 = 8) : (v19 = 2 * v18),
                AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v15, v19)) )
            *(_DWORD *)(*(_DWORD *)v15 + 4 * (*(_DWORD *)(v15 + 8))++) = v16;
          addra = (void **)((char *)addra + 1);
          if ( (unsigned int)addra >= iq )
          {
            v14 = iq;
            goto LABEL_30;
          }
        }
      }
      else
      {
LABEL_30:
        if ( *v4 >= 4 )
        {
          v20 = *(_DWORD *)*v3;
          *v3 = (char *)*v3 + 4;
          iq = v20;
          *v4 -= 4;
          v14 = v20;
        }
        if ( v14 <= *v4 )
        {
          AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)&v31->days_of_the_week, v14);
          addrb = 0;
          if ( v14 )
          {
            while ( 1 )
            {
              v21 = (WeekDay *)operator new(4u);
              if ( v21 )
              {
                v22 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
                v21->week_day_name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
                InterlockedIncrement(v22);
              }
              else
              {
                v21 = 0;
              }
              if ( !WeekDay::UnPack(v21, v3, v4) )
                break;
              v23 = v31->days_of_the_week.m_size;
              if ( v31->days_of_the_week.m_num < v23
                || (!v23 ? (v24 = 8) : (v24 = 2 * v23),
                    AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
                      (AC1Legacy::SmartArray<Season *> *)&v31->days_of_the_week,
                      v24)) )
                v31->days_of_the_week.m_data[v31->days_of_the_week.m_num++] = v21;
              addrb = (void **)((char *)addrb + 1);
              if ( (unsigned int)addrb >= iq )
              {
                v14 = iq;
                goto LABEL_46;
              }
            }
          }
          else
          {
LABEL_46:
            if ( *v4 >= 4 )
            {
              v25 = *(_DWORD *)*v3;
              *v3 = (char *)*v3 + 4;
              iq = v25;
              *v4 -= 4;
              v14 = v25;
            }
            if ( v14 <= *v4 )
            {
              AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(&v31->seasons, v14);
              addrc = 0;
              if ( !v14 )
                return *v4 > 0;
              while ( 1 )
              {
                v26 = operator new(8u);
                if ( v26 )
                {
                  v27 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
                  *(_DWORD *)v26 = AC1Legacy::PStringBase<char>::s_NullBuffer;
                  InterlockedIncrement(v27);
                  *((_DWORD *)v26 + 1) = 0;
                }
                else
                {
                  v26 = 0;
                }
                if ( !Season::UnPack((Season *)v26, v3, v4) )
                  break;
                v28 = v31->seasons.m_size;
                if ( v31->seasons.m_num < v28
                  || (!v28 ? (v29 = 8) : (v29 = 2 * v28), AC1Legacy::SmartArray<SkyTimeOfDay *>::grow(
                                                            &v31->seasons,
                                                            v29)) )
                  v31->seasons.m_data[v31->seasons.m_num++] = (Season *)v26;
                addrc = (void **)((char *)addrc + 1);
                if ( (unsigned int)addrc >= iq )
                  return *v4 > 0;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

