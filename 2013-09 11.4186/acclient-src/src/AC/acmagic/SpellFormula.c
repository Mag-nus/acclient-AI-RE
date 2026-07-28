/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : SpellFormula
   Object     : AC\acmagic\SpellFormula.obj
   Functions  : 22
   Addresses  : 005BC880 - 0070EC10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BC880) --------------------------------------------------------  // acclient.c:487705
int __thiscall SpellFormula::Complete(SpellFormula *this)
{
  signed int v1; // eax@1
  char *v2; // ecx@1

  v1 = 0;
  v2 = (char *)this->_comps;
  while ( *(_DWORD *)v2 )
  {
    ++v1;
    v2 += 4;
    if ( v1 >= 5 )
      return 1;
  }
  return 0;
}

//----- (005BC8A0) --------------------------------------------------------  // acclient.c:487723
int __thiscall SpellFormula::SetComponent(SpellFormula *this, const int num, const unsigned int comp)
{
  int result; // eax@2

  if ( num < 8 )
  {
    this->_comps[num] = comp;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BC8C0) --------------------------------------------------------  // acclient.c:487740
int __thiscall SpellFormula::GetNumSpellComponents(SpellFormula *this)
{
  int result; // eax@1

  result = 0;
  if ( this->_comps[0] )
    result = 1;
  if ( this->_comps[1] )
    ++result;
  if ( this->_comps[2] )
    ++result;
  if ( this->_comps[3] )
    ++result;
  if ( this->_comps[4] )
    ++result;
  if ( this->_comps[5] )
    ++result;
  if ( this->_comps[6] )
    ++result;
  if ( this->_comps[7] )
    ++result;
  return result;
}

//----- (005BC910) --------------------------------------------------------  // acclient.c:487765
signed int __thiscall SpellFormula::GetTargetingType(SpellFormula *this)
{
  signed int v1; // eax@1
  char *v2; // edx@1

  v1 = 5;
  v2 = (char *)&this->_comps[5];
  do
  {
    if ( !*(_DWORD *)v2 )
      break;
    ++v1;
    v2 += 4;
  }
  while ( v1 < 8 );
  return SpellComponentTable::GetTargetTypeFromComponentID(*((_DWORD *)&this->vfptr + v1));
}

//----- (005BC940) --------------------------------------------------------  // acclient.c:487784
signed int __thiscall SpellFormula::GetPowerLevelOfPowerComponent(SpellFormula *this)
{
  return MagicSystem::DeterminePowerLevelOfComponent(this->_comps[0]);
}

//----- (005BC950) --------------------------------------------------------  // acclient.c:487790
unsigned int __thiscall SpellFormula::FindMostPowerfulPowerComponent(SpellFormula *this, unsigned int *power_lvl)
{
  const unsigned int *v2; // esi@1
  unsigned int v3; // ebp@1
  unsigned int v4; // edi@1
  signed int v5; // eax@1
  signed int v6; // ebx@18
  signed int v7; // eax@20
  unsigned int result; // eax@23

  v2 = this->_comps;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( this->_comps[0] )
    v5 = 1;
  if ( this->_comps[1] )
    ++v5;
  if ( this->_comps[2] )
    ++v5;
  if ( this->_comps[3] )
    ++v5;
  if ( this->_comps[4] )
    ++v5;
  if ( this->_comps[5] )
    ++v5;
  if ( this->_comps[6] )
    ++v5;
  if ( this->_comps[7] )
    ++v5;
  if ( v5 )
  {
    v6 = v5;
    do
    {
      if ( *v2 )
      {
        v7 = MagicSystem::DeterminePowerLevelOfComponent(*v2);
        if ( v7 > v4 )
        {
          v3 = *v2;
          v4 = v7;
        }
      }
      ++v2;
      --v6;
    }
    while ( v6 );
    *power_lvl = v4;
    result = v3;
  }
  else
  {
    *power_lvl = 0;
    result = 0;
  }
  return result;
}

//----- (005BC9F0) --------------------------------------------------------  // acclient.c:487850
int __thiscall SpellFormula::Decrypt(SpellFormula *this, const unsigned int key)
{
  unsigned int v2; // eax@1
  unsigned int v3; // eax@3
  unsigned int v4; // eax@5
  unsigned int v5; // eax@7
  unsigned int v6; // eax@9
  unsigned int v7; // eax@11
  unsigned int v8; // eax@13
  unsigned int v9; // eax@15

  v2 = this->_comps[0];
  if ( v2 )
    this->_comps[0] = v2 - key;
  v3 = this->_comps[1];
  if ( v3 )
    this->_comps[1] = v3 - key;
  v4 = this->_comps[2];
  if ( v4 )
    this->_comps[2] = v4 - key;
  v5 = this->_comps[3];
  if ( v5 )
    this->_comps[3] = v5 - key;
  v6 = this->_comps[4];
  if ( v6 )
    this->_comps[4] = v6 - key;
  v7 = this->_comps[5];
  if ( v7 )
    this->_comps[5] = v7 - key;
  v8 = this->_comps[6];
  if ( v8 )
    this->_comps[6] = v8 - key;
  v9 = this->_comps[7];
  if ( v9 )
    this->_comps[7] = v9 - key;
  return 1;
}

//----- (005BCA60) --------------------------------------------------------  // acclient.c:487889
signed int __thiscall SpellFormula::Pack(SpellFormula *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // esi@2
  char *v5; // edx@2
  char *v6; // esi@2
  char *v7; // edx@2
  char *v8; // esi@2
  char *v9; // edx@2

  if ( size >= 0x20 )
  {
    *(_DWORD *)*addr = this->_comps[0];
    v3 = (char *)*addr + 4;
    *addr = v3;
    *(_DWORD *)v3 = this->_comps[1];
    v4 = (char *)*addr + 4;
    *addr = v4;
    *(_DWORD *)v4 = this->_comps[2];
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = this->_comps[3];
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = this->_comps[4];
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = this->_comps[5];
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = this->_comps[6];
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = this->_comps[7];
    *addr = (char *)*addr + 4;
  }
  return 32;
}

//----- (005BCAE0) --------------------------------------------------------  // acclient.c:487929
int __thiscall SpellFormula::UnPack(SpellFormula *this, void **addr, unsigned int size)
{
  void *v3; // edx@1
  int result; // eax@2
  char *v5; // esi@3
  char *v6; // esi@3
  char *v7; // esi@3
  char *v8; // esi@3
  char *v9; // esi@3
  char *v10; // esi@3
  char *v11; // esi@3
  char *v12; // esi@3

  v3 = *addr;
  if ( size >= 0x20 )
  {
    this->_comps[0] = *(_DWORD *)v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    this->_comps[1] = *(_DWORD *)v5;
    v6 = (char *)*addr + 4;
    *addr = v6;
    this->_comps[2] = *(_DWORD *)v6;
    v7 = (char *)*addr + 4;
    *addr = v7;
    this->_comps[3] = *(_DWORD *)v7;
    v8 = (char *)*addr + 4;
    *addr = v8;
    this->_comps[4] = *(_DWORD *)v8;
    v9 = (char *)*addr + 4;
    *addr = v9;
    this->_comps[5] = *(_DWORD *)v9;
    v10 = (char *)*addr + 4;
    *addr = v10;
    this->_comps[6] = *(_DWORD *)v10;
    v11 = (char *)*addr + 4;
    *addr = v11;
    this->_comps[7] = *(_DWORD *)v11;
    v12 = (char *)*addr + 4;
    *addr = v12;
    result = v12 - (_BYTE *)v3 == 32;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005BCB70) --------------------------------------------------------  // acclient.c:487979
int __thiscall SpellFormula::RandomizeVersion1(SpellFormula *this, AC1Legacy::PStringBase<char> *account_name)
{
  SpellFormula *v2; // ebx@1
  unsigned int v3; // ebp@1
  signed int v4; // edi@1
  AC1Legacy::PSRefBuffer<char> *v5; // esi@17
  unsigned int v6; // eax@17
  unsigned int v7; // edx@19
  signed int v8; // esi@19
  signed int v9; // eax@19
  unsigned int v10; // edx@21
  int v11; // eax@21
  int v12; // eax@27
  int v13; // eax@30
  unsigned int v14; // edi@34
  int v15; // ebp@41
  unsigned int x; // [sp+10h] [bp-18h]@30
  unsigned int a; // [sp+14h] [bp-14h]@21
  int accent1; // [sp+18h] [bp-10h]@17
  int accent2; // [sp+1Ch] [bp-Ch]@17
  int accent3; // [sp+20h] [bp-8h]@17
  unsigned int seed; // [sp+24h] [bp-4h]@19
  AC1Legacy::PStringBase<char> *account_namea; // [sp+2Ch] [bp+4h]@25

  v2 = this;
  v3 = 0;
  v4 = 0;
  if ( this->_comps[0] )
    v4 = 1;
  if ( this->_comps[1] )
    ++v4;
  if ( this->_comps[2] )
    ++v4;
  if ( this->_comps[3] )
    ++v4;
  if ( this->_comps[4] )
    ++v4;
  if ( this->_comps[5] )
    ++v4;
  if ( this->_comps[6] )
    ++v4;
  if ( this->_comps[7] )
    ++v4;
  v5 = account_name->m_buffer;
  v6 = account_name->m_buffer->m_hash;
  accent3 = 0;
  accent2 = 0;
  accent1 = 0;
  if ( v6 == -1 )
  {
    v6 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v5->m_hash = v6;
  }
  v7 = v6 % 0x13D573;
  v8 = v2->_comps[0];
  v9 = 1;
  seed = v7;
  if ( (unsigned int)v4 > 5 )
  {
    v9 = 2;
    accent1 = 1;
  }
  v10 = v2->_comps[v9];
  v11 = v9 + 1;
  a = v10;
  if ( (unsigned int)v4 > 6 )
  {
    ++v11;
    accent2 = 1;
  }
  if ( v11 < 0 || v11 >= 8 )
    account_namea = 0;
  else
    account_namea = (AC1Legacy::PStringBase<char> *)v2->_comps[v11];
  v12 = v11 + 1;
  if ( v12 >= 0 && v12 < 8 )
    v3 = v2->_comps[v12];
  v13 = v12 + 1;
  x = v3;
  if ( (unsigned int)v4 > 7 )
  {
    ++v13;
    accent3 = 1;
  }
  if ( v13 < 0 || v13 >= 8 )
    v14 = 0;
  else
    v14 = v2->_comps[v13];
  if ( accent1 )
  {
    if ( !(v8 + v10) )
      v8 = 1;
    v2->_comps[1] = (unsigned int)((char *)account_namea + 2 * v10 + v3 + v14 + v8) % 0xC
                  + MagicSystem::GetLowestTaperID();
  }
  if ( accent2 )
  {
    v15 = (int)((char *)account_namea + v3);
    if ( !(v8 + v15) )
      v8 = 1;
    v2->_comps[3] = (v8 + a + v14 + 2 * v15) * (seed / (v8 + v15)) % 0xC + MagicSystem::GetLowestTaperID();
  }
  if ( accent3 )
  {
    if ( !(v14 + v8) )
      v8 = 1;
    v2->_comps[6] = (unsigned int)((char *)account_namea + 2 * v14 + x + a + v8) * (seed / (v14 + v8)) % 0xC
                  + MagicSystem::GetLowestTaperID();
  }
  return 1;
}

//----- (005BCD40) --------------------------------------------------------  // acclient.c:488092
int __thiscall SpellFormula::RandomizeVersion2(SpellFormula *this, AC1Legacy::PStringBase<char> *account_name)
{
  SpellFormula *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // ebx@3
  unsigned int v6; // ebp@3
  unsigned int v7; // edi@3
  unsigned int v8; // ST14_4@3
  unsigned int p1; // ST1C_4@3
  unsigned int c; // ST10_4@3
  unsigned int x; // ST18_4@3
  signed int v12; // ecx@3
  int result; // eax@3
  AC1Legacy::PStringBase<char> *account_namea; // [sp+24h] [bp+4h]@3

  v2 = this;
  v3 = account_name->m_buffer;
  v4 = account_name->m_buffer->m_hash;
  if ( v4 == -1 )
  {
    v4 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v3->m_hash = v4;
  }
  v5 = v2->_comps[0];
  v6 = v2->_comps[1];
  v7 = v2->_comps[2];
  v8 = v4;
  p1 = v2->_comps[0];
  c = v2->_comps[4];
  x = v2->_comps[5];
  account_namea = (AC1Legacy::PStringBase<char> *)v2->_comps[7];
  v2->_comps[3] = (unsigned int)((char *)account_namea + 2 * v5 + 2 * c * x + v5 + v7 + v6) % 0xC
                + MagicSystem::GetLowestTaperID();
  v12 = MagicSystem::GetLowestTaperID();
  result = 1;
  v2->_comps[6] = (unsigned int)((char *)account_namea + 2 * p1 * v7 + 2 * x + p1 * v7 + c)
                * (v8 % 0x13D573
                 / (v6 * (_DWORD)account_namea + 2 * c))
                % 0xC
                + v12;
  return result;
}

//----- (005BCE20) --------------------------------------------------------  // acclient.c:488137
int __thiscall SpellFormula::RandomizeVersion3(SpellFormula *this, AC1Legacy::PStringBase<char> *account_name)
{
  AC1Legacy::PStringBase<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  unsigned int v4; // eax@1
  SpellFormula *v5; // ebx@1
  unsigned int v6; // edx@3
  AC1Legacy::PSRefBuffer<char> *v7; // ebp@3
  unsigned int v8; // eax@3
  unsigned int v9; // edx@5
  AC1Legacy::PSRefBuffer<char> *v10; // ebp@5
  unsigned int v11; // eax@5
  unsigned int v12; // edx@7
  AC1Legacy::PSRefBuffer<char> *v13; // ebp@7
  unsigned int v14; // eax@7
  unsigned int v15; // edx@9
  AC1Legacy::PSRefBuffer<char> *v16; // ebp@9
  unsigned int v17; // eax@9
  unsigned int v18; // edi@9
  unsigned int v19; // edx@11
  AC1Legacy::PSRefBuffer<char> *v20; // ebp@11
  unsigned int v21; // eax@11
  unsigned int v22; // edx@13
  AC1Legacy::PStringBase<char> v23; // ebp@13
  unsigned int v24; // eax@13
  unsigned int v25; // ST24_4@15
  unsigned int v26; // ST14_4@15
  unsigned int v27; // ST10_4@15
  unsigned int v28; // ST20_4@15
  unsigned int s4; // ST1C_4@15
  unsigned int v30; // ST18_4@15
  signed int v31; // ecx@15
  int result; // eax@15
  unsigned int s2; // [sp+10h] [bp-1Ch]@5
  unsigned int s1; // [sp+14h] [bp-18h]@3
  unsigned int s6; // [sp+18h] [bp-14h]@13
  unsigned int s3; // [sp+20h] [bp-Ch]@7
  SpellFormula *v37; // [sp+28h] [bp-4h]@1
  AC1Legacy::PStringBase<char> *account_namea; // [sp+30h] [bp+4h]@11
  unsigned int account_nameb; // [sp+30h] [bp+4h]@15

  v2 = account_name;
  v3 = account_name->m_buffer;
  v4 = account_name->m_buffer->m_hash;
  v5 = this;
  v37 = this;
  if ( v4 == -1 )
  {
    v4 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v3->m_hash = v4;
  }
  v6 = v4 % 0x13D573;
  v7 = account_name->m_buffer;
  v8 = account_name->m_buffer->m_hash;
  s1 = v6;
  if ( v8 == -1 )
  {
    v8 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v7->m_hash = v8;
  }
  v9 = v8 % 0x4AEFD;
  v10 = account_name->m_buffer;
  v11 = account_name->m_buffer->m_hash;
  s2 = v9;
  if ( v11 == -1 )
  {
    v11 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v10->m_hash = v11;
  }
  v12 = v11 % 0x96A7F;
  v13 = account_name->m_buffer;
  v14 = account_name->m_buffer->m_hash;
  s3 = v12;
  if ( v14 == -1 )
  {
    v14 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v13->m_hash = v14;
  }
  v15 = v14 % 0x100A03;
  v16 = account_name->m_buffer;
  v17 = account_name->m_buffer->m_hash;
  v18 = v15;
  if ( v17 == -1 )
  {
    v17 = AC1Legacy::PStringBase<char>::compute_hash(account_name);
    v16->m_hash = v17;
  }
  v19 = v17 % 0xEB2EF;
  v20 = account_name->m_buffer;
  v21 = account_name->m_buffer->m_hash;
  account_namea = (AC1Legacy::PStringBase<char> *)v19;
  if ( v21 == -1 )
  {
    v21 = AC1Legacy::PStringBase<char>::compute_hash(v2);
    v20->m_hash = v21;
  }
  v22 = v21 % 0x121E7D;
  v23.m_buffer = v2->m_buffer;
  v24 = v2->m_buffer->m_hash;
  s6 = v22;
  if ( v24 == -1 )
  {
    v24 = AC1Legacy::PStringBase<char>::compute_hash(v2);
    v23.m_buffer->m_hash = v24;
  }
  v25 = v24;
  v26 = (s1 + v5->_comps[0]) % 0xC;
  v27 = (s2 + v5->_comps[1]) % 0xC;
  v28 = (s3 + v5->_comps[2]) % 0xC;
  s4 = (v18 + v5->_comps[4]) % 0xC;
  account_nameb = (unsigned int)((char *)account_namea + v5->_comps[5]) % 0xC;
  v30 = (s6 + v5->_comps[7]) % 0xC;
  v5->_comps[3] = (v26 + v27 + v28 + s4 + account_nameb + v28 * account_nameb + v26 * v27 + v30 * (s4 + 1)) % 0xC
                + MagicSystem::GetLowestTaperID();
  v31 = MagicSystem::GetLowestTaperID();
  result = 1;
  v37->_comps[6] = (v26
                  + v27
                  + v28
                  + s4
                  + v25 % 0x65039 % 0xC
                  + v30 * (s4 * (v26 * v27 * v28 * account_nameb + 7) + 1)
                  + account_nameb
                  + 4 * v26 * v27
                  + v26 * v27
                  + 11 * v28 * account_nameb)
                 % 0xC
                 + v31;
  return result;
}

//----- (005BD050) --------------------------------------------------------  // acclient.c:488269
int __thiscall SpellFormula::RandomizeForName(SpellFormula *this, AC1Legacy::PStringBase<char> *account_name, const int spell_version)
{
  int result; // eax@4

  switch ( spell_version )
  {
    case 1:
      result = SpellFormula::RandomizeVersion1(this, account_name);
      break;
    case 2:
      result = SpellFormula::RandomizeVersion2(this, account_name);
      break;
    case 3:
      result = SpellFormula::RandomizeVersion3(this, account_name);
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0070EB50) --------------------------------------------------------  // acclient.c:801713
int sub_70EB50()
{
  return atexit(nullsub_1590);
}

//----- (0070EB60) --------------------------------------------------------  // acclient.c:801719
int _E4_8()
{
  return atexit(_E5_8);
}

//----- (0070EB70) --------------------------------------------------------  // acclient.c:801725
int _E7_8()
{
  Outside_CellID_8.id = Invalid_CellID_8.id + 1;
  return atexit(_E8_8);
}

//----- (0070EB90) --------------------------------------------------------  // acclient.c:801732
int _E10_7()
{
  In_Limbo_CellID_7.id = Outside_CellID_8.id + 1;
  return atexit(_E11_7);
}

//----- (0070EBB0) --------------------------------------------------------  // acclient.c:801739
int _E13_7()
{
  First_Interior_CellID_7.id = In_Limbo_CellID_7.id + 1;
  return atexit(_E14_7);
}

//----- (0070EBD0) --------------------------------------------------------  // acclient.c:801746
int _E16_7()
{
  Last_Interior_CellID_7.id = Invalid_CellID_8.id - 1;
  return atexit(_E17_7);
}

//----- (0070EBF0) --------------------------------------------------------  // acclient.c:801753
int _E21_9()
{
  return atexit(_E22_9);
}

//----- (0070EC00) --------------------------------------------------------  // acclient.c:801759
int _E40_9()
{
  return atexit(_E41_9);
}

//----- (0070EC10) --------------------------------------------------------  // acclient.c:801765
int _E43_12()
{
  return atexit(_E44_12);
}

