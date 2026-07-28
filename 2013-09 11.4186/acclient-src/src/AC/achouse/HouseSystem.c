/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HouseSystem
   Object     : AC\achouse\HouseSystem.obj
   Functions  : 6
   Addresses  : 005BB1D0 - 0070E8C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005BB1D0) --------------------------------------------------------  // acclient.c:486142
BOOL __cdecl HouseSystem::HasPurchaseWaitPeriodExpired(int purchase_time)
{
  return Timer::get_real_time() - purchase_time > 2592000;
}

//----- (005BB1F0) --------------------------------------------------------  // acclient.c:486148
double __cdecl HouseSystem::GetRentPeriod(const unsigned int *type)
{
  double result; // st7@2

  if ( *type == 4 )
    result = 7776000.0;
  else
    result = 2592000.0;
  return result;
}

//----- (005BB210) --------------------------------------------------------  // acclient.c:486160
char __cdecl HouseSystem::IsTradeNote(IDClass<_tagDataID,32,0> *wcid, unsigned int *amount)
{
  char v2; // bl@1
  int v3; // esi@1

  v2 = 0;
  *amount = 0;
  v3 = DBObj::GetByEnum(10, 268435457, 0x28u);
  if ( v3 )
  {
    v2 = DualEnumIDMap::DIDToEnum((DualEnumIDMap *)v3, (IDClass<_tagDataID,32,0>)wcid->id, amount);
    (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
  }
  return v2;
}

//----- (005BB260) --------------------------------------------------------  // acclient.c:486177
int __cdecl HouseSystem::ConvertTime(int time, AC1Legacy::PStringBase<char> *spew)
{
  struct tm *v2; // eax@3
  AC1Legacy::PSRefBuffer<char> *v3; // esi@5
  unsigned int v4; // eax@5
  AC1Legacy::PStringBase<char> v6; // [sp+4h] [bp-204h]@2
  char buf[512]; // [sp+8h] [bp-200h]@4

  if ( time )
  {
    v2 = _localtime(&time);
    if ( !v2 )
      return 0;
    _strftime(buf, 0x200u, "%c", v2);
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v6, buf);
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v6, "N/A");
  }
  v3 = v6.m_buffer;
  v4 = v6.m_buffer->m_len;
  if ( v4 != 1 && v6.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(spew, v6.m_buffer->m_data, v4 - 1);
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005BB310) --------------------------------------------------------  // acclient.c:486208
int __cdecl HouseSystem::ConstructRentWarningMessage(const unsigned int *type, AC1Legacy::PStringBase<char> *spew)
{
  AC1Legacy::PSRefBuffer<char> *v2; // ecx@0
  double v3; // st7@2
  int v4; // esi@4
  AC1Legacy::PStringBase<char> *v5; // ebx@4
  const unsigned int *v6; // esi@4
  const unsigned int v7; // eax@4
  const unsigned int *v8; // esi@9
  const unsigned int v9; // eax@9
  const unsigned int *v10; // esi@14
  const unsigned int v11; // eax@14
  AC1Legacy::PSRefBuffer<char> *v12; // esi@19
  AC1Legacy::PStringBase<char> rentstr; // [sp+Ch] [bp-4h]@1

  rentstr.m_buffer = v2;
  if ( *type == 4 )
    v3 = 7776000.0;
  else
    v3 = 2592000.0;
  v4 = (unsigned __int64)(v3 * 0.00001157407407407407);
  rentstr.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::operator=(&rentstr, v4);
  v5 = spew;
  AC1Legacy::PStringBase<char>::set(spew, "Warning!  You have not paid your maintenance costs for the last ");
  type = (const unsigned int *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::operator=((AC1Legacy::PStringBase<char> *)&type, v4);
  v6 = type;
  v7 = type[2];
  if ( v7 != 1 && type != (const unsigned int *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v5, (const char *)type + 20, v7 - 1);
  if ( !InterlockedDecrement((volatile LONG *)v6 + 1) )
    (**(void (__thiscall ***)(const unsigned int *, signed int))v6)(v6, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>(
    (AC1Legacy::PStringBase<char> *)&type,
    " day maintenance period.  Please pay these costs by this deadline");
  v8 = type;
  v9 = type[2];
  if ( v9 != 1 && type != (const unsigned int *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v5, (const char *)type + 20, v9 - 1);
  if ( !InterlockedDecrement((volatile LONG *)v8 + 1) )
    (**(void (__thiscall ***)(const unsigned int *, signed int))v8)(v8, 1);
  AC1Legacy::PStringBase<char>::PStringBase<char>(
    (AC1Legacy::PStringBase<char> *)&type,
    " or you will lose your house, and all your items within it.");
  v10 = type;
  v11 = type[2];
  if ( v11 != 1 && type != (const unsigned int *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    AC1Legacy::PStringBase<char>::append_n_chars(v5, (const char *)type + 20, v11 - 1);
  if ( !InterlockedDecrement((volatile LONG *)v10 + 1) )
    (**(void (__thiscall ***)(const unsigned int *, signed int))v10)(v10, 1);
  v12 = rentstr.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&rentstr.m_buffer->m_cRef) && v12 )
    v12->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v12, 1u);
  return 1;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (0070E8C0) --------------------------------------------------------  // acclient.c:801543
int sub_70E8C0()
{
  return atexit(nullsub_1559);
}

