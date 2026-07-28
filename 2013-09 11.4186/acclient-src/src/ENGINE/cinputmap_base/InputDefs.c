/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : InputDefs
   Object     : ENGINE\cinputmap_base\InputDefs.obj
   Functions  : 36
   Addresses  : 0068A020 - 0077FAC0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0068A020) --------------------------------------------------------  // acclient.c:673574
char __cdecl SubControlIndexToStringInfo(SubControlIndex i_sci, StringInfo *o_si)
{
  char result; // al@2

  switch ( i_sci )
  {
    case 1:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_PositiveAxis, 3);
      result = 1;
      break;
    case 2:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_NegativeAxis, 3);
      result = 1;
      break;
    case 3:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_POVUp, 3);
      result = 1;
      break;
    case 4:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_POVRight, 3);
      result = 1;
      break;
    case 5:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_POVDown, 3);
      result = 1;
      break;
    case 6:
      StringInfo::SetStringIDandTableEnum(o_si, ID_sci_POVLeft, 3);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0068A0D0) --------------------------------------------------------  // acclient.c:673612
BOOL __thiscall QualifiedControl::IsExactlyEqual(QualifiedControl *this, QualifiedControl *rhs)
{
  return this->m_key.m_dwKey == rhs->m_key.m_dwKey
      && this->m_metamode == rhs->m_metamode
      && this->m_activation == rhs->m_activation;
}

//----- (0068A100) --------------------------------------------------------  // acclient.c:673620
bool __thiscall QualifiedControl::IsConflicting(QualifiedControl *this, QualifiedControl *rhs)
{
  return this->m_key.m_dwKey == rhs->m_key.m_dwKey
      && this->m_metamode == rhs->m_metamode
      && rhs->m_activation & this->m_activation;
}

//----- (0068A130) --------------------------------------------------------  // acclient.c:673628
unsigned int __cdecl BitUtils::CountHighBits(unsigned int i_bits)
{
  return (((((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
             + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) & 0xF0F0F0F)
           + ((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
              + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) & 0xFF00FF)
         + ((((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
              + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) & 0xF0F0F0F)
            + ((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
               + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) >> 8) & 0xFF00FF)) & 0xFFFF)
       + (((((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
             + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) & 0xF0F0F0F)
           + ((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
              + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) & 0xFF00FF)
         + ((((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
              + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) & 0xF0F0F0F)
            + ((((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) & 0x33333333)
               + ((((i_bits & 0x55555555) + ((i_bits >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F)) >> 8) & 0xFF00FF)) >> 16);
}

//----- (0068A190) --------------------------------------------------------  // acclient.c:673649
void __thiscall ControlSpecification::Serialize(ControlSpecification *this, Archive *io_archive)
{
  ControlSpecification *v2; // edi@1
  unsigned int v3; // eax@1

  v2 = this;
  Archive::CheckAlignment(io_archive, 4u);
  v3 = Archive::GetBytes(io_archive, 4u);
  if ( v3 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v3 = v2->m_dwKey;
    else
      v2->m_dwKey = *(_DWORD *)v3;
  }
}

//----- (0068A1D0) --------------------------------------------------------  // acclient.c:673667
bool __thiscall QualifiedControl::operator==(QualifiedControl *this, QualifiedControl *rhs)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // edi@1
  char v4; // dl@1
  unsigned int v6; // eax@8
  unsigned int v7; // edx@8
  unsigned int v8; // eax@10
  unsigned int v9; // ecx@10
  bool v10; // zf@12

  v2 = rhs->m_activation;
  v3 = this->m_activation;
  v4 = (rhs->m_activation >> 31) & 1;
  if ( !((this->m_activation >> 31) & 1) )
  {
    v6 = rhs->m_key.m_dwKey;
    v10 = v4 == 0;
    v7 = this->m_key.m_dwKey;
    if ( v10 )
    {
      if ( v7 != v6 )
        return 0;
      v8 = this->m_metamode;
      v9 = rhs->m_metamode;
    }
    else
    {
      if ( v7 != v6 )
        return 0;
      v9 = this->m_metamode;
      v8 = v9 & rhs->m_metamode;
    }
    v10 = v8 == v9;
    goto LABEL_16;
  }
  if ( !v4 )
  {
    if ( rhs->m_key.m_dwKey == this->m_key.m_dwKey )
    {
      v10 = (rhs->m_metamode & this->m_metamode) == rhs->m_metamode;
LABEL_16:
      if ( v10 && v2 & v3 )
        return 1;
    }
    return 0;
  }
  return this->m_key.m_dwKey == rhs->m_key.m_dwKey && this->m_metamode == rhs->m_metamode && v3 == v2;
}

//----- (0068A270) --------------------------------------------------------  // acclient.c:673718
bool __thiscall QualifiedControl::IsBetterMatch(QualifiedControl *this, QualifiedControl *lhs, QualifiedControl *rhs)
{
  unsigned int v4; // eax@6
  unsigned int v5; // edi@6
  unsigned int v6; // edx@7
  unsigned int v7; // eax@8
  bool v8; // bl@8
  unsigned int v9; // esi@10
  unsigned int v10; // ebp@10
  unsigned int v11; // eax@10

  if ( lhs->m_key.m_dwKey == rhs->m_key.m_dwKey
    && lhs->m_metamode == rhs->m_metamode
    && lhs->m_activation == rhs->m_activation )
    return 0;
  if ( rhs->m_key.m_dwKey == this->m_key.m_dwKey )
  {
    v4 = rhs->m_metamode;
    v5 = v4 & this->m_metamode;
    if ( v5 == v4 )
    {
      v6 = rhs->m_activation;
      if ( v6 & this->m_activation )
      {
        v7 = lhs->m_activation;
        v8 = 1;
        if ( v6 >= v7 )
        {
          if ( v6 != v7 )
            return v8;
          v9 = this->m_metamode & lhs->m_metamode;
          v10 = BitUtils::CountHighBits(v5);
          v11 = BitUtils::CountHighBits(v9);
          if ( v10 >= v11 )
          {
            if ( v10 == v11 )
              v8 = v5 > v9;
            return v8;
          }
        }
      }
    }
  }
  return 0;
}

//----- (0068A300) --------------------------------------------------------  // acclient.c:673765
int __thiscall PFileNode::MakeSubNodeAsUInt32(PFileNode *this, unsigned int i_name)
{
  int result; // eax@1
  PFileNode *v3; // esi@1
  IFileNodeName *v4; // ecx@2
  void *v5; // eax@4

  result = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  v3 = (PFileNode *)result;
  if ( result )
  {
    v4 = *(IFileNodeName **)(result + 8);
    if ( v4 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
    v3->m_pcName = 0;
    v5 = operator new(8u);
    if ( v5 )
    {
      *(_DWORD *)v5 = &FileNodeName_UInt32::vftable;
      *((_DWORD *)v5 + 1) = i_name;
      v3->m_pcName = (IFileNodeName *)v5;
      result = (int)v3;
    }
    else
    {
      v3->m_pcName = 0;
      result = (int)v3;
    }
  }
  return result;
}
// 797108: using guessed type int (__thiscall *FileNodeName_UInt32::vftable)(void *, char);

//----- (0068A360) --------------------------------------------------------  // acclient.c:673799
IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0> *__thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vector_deleting_destructor(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0> *this, unsigned int a2)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0> *v2; // esi@1
  HashTableData<PStringBase<char>,unsigned long> **v3; // eax@1

  v2 = this;
  v3 = this->m_buckets;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v3 != this->m_aInplaceBuckets )
    operator delete[](v3);
  v2->m_buckets = 0;
  v2->m_firstInterestingBucket = 0;
  v2->m_numBuckets = 0;
  v2->m_numElements = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FF098: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable)(void *, char);

//----- (0068A430) --------------------------------------------------------  // acclient.c:673858
char __cdecl StringToDeviceType(PStringBase<char> *i_str, DeviceType *o_dt)
{
  int v2; // eax@1
  char *v3; // esi@1
  bool v4; // bl@1
  char result; // al@5
  int v6; // eax@6
  char *v7; // esi@6
  bool v8; // bl@6
  int v9; // eax@11
  char *v10; // esi@11
  bool v11; // bl@11
  int v12; // eax@16
  char *v13; // edi@16
  bool v14; // bl@16
  PStringBase<char> v15; // [sp+10h] [bp-4h]@1

  PStringBase<char>::PStringBase<char>(&v15, "Keyboard");
  v2 = __stricmp(i_str->m_charbuffer->m_data, v15.m_charbuffer->m_data);
  v3 = &v15.m_charbuffer[-2].m_data[12];
  v4 = v2 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( v4 )
  {
    *o_dt = 1;
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&v15, "Mouse");
    v6 = __stricmp(i_str->m_charbuffer->m_data, v15.m_charbuffer->m_data);
    v7 = &v15.m_charbuffer[-2].m_data[12];
    v8 = v6 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      *o_dt = 2;
      result = 1;
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&v15, "Joystick");
      v9 = __stricmp(i_str->m_charbuffer->m_data, v15.m_charbuffer->m_data);
      v10 = &v15.m_charbuffer[-2].m_data[12];
      v11 = v9 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      if ( v11 )
      {
        *o_dt = 3;
        result = 1;
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&v15, "Virtual");
        v12 = __stricmp(i_str->m_charbuffer->m_data, v15.m_charbuffer->m_data);
        v13 = &v15.m_charbuffer[-2].m_data[12];
        v14 = v12 == 0;
        if ( !InterlockedDecrement((volatile LONG *)&v15.m_charbuffer[-1]) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        if ( v14 )
        {
          *o_dt = 4;
          result = 1;
        }
        else
        {
          *o_dt = 0;
          result = 0;
        }
      }
    }
  }
  return result;
}

//----- (0068A5C0) --------------------------------------------------------  // acclient.c:673937
char __cdecl StringToSubControlIndex(PStringBase<char> *i_str, SubControlIndex *o_sci)
{
  int v2; // eax@1
  char *v3; // ebp@1
  bool v4; // bl@1
  char result; // al@5
  int v6; // eax@6
  char *v7; // ebp@6
  bool v8; // bl@6
  int v9; // eax@11
  char *v10; // ebp@11
  bool v11; // bl@11
  int v12; // eax@16
  char *v13; // ebp@16
  bool v14; // bl@16
  int v15; // ebx@21
  int v16; // ebx@23
  int v17; // esi@25
  PStringBase<char> v18; // [sp+10h] [bp-4h]@1

  PStringBase<char>::PStringBase<char>(&v18, "AxisPositive");
  v2 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
  v3 = &v18.m_charbuffer[-2].m_data[12];
  v4 = v2 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  if ( v4 )
  {
    *o_sci = 1;
    result = 1;
  }
  else
  {
    PStringBase<char>::PStringBase<char>(&v18, "AxisNegative");
    v6 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
    v7 = &v18.m_charbuffer[-2].m_data[12];
    v8 = v6 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) && v7 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
    if ( v8 )
    {
      *o_sci = 2;
      result = 1;
    }
    else
    {
      PStringBase<char>::PStringBase<char>(&v18, "POVUp");
      v9 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
      v10 = &v18.m_charbuffer[-2].m_data[12];
      v11 = v9 == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) && v10 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
      if ( v11 )
      {
        *o_sci = 3;
        result = 1;
      }
      else
      {
        PStringBase<char>::PStringBase<char>(&v18, "POVRight");
        v12 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
        v13 = &v18.m_charbuffer[-2].m_data[12];
        v14 = v12 == 0;
        if ( !InterlockedDecrement((volatile LONG *)&v18.m_charbuffer[-1]) && v13 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v13)(v13, 1);
        if ( v14 )
        {
          *o_sci = 4;
          result = 1;
        }
        else
        {
          PStringBase<char>::PStringBase<char>(&v18, "POVDown");
          v15 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
          PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v18);
          if ( v15 )
          {
            PStringBase<char>::PStringBase<char>(&v18, "POVLeft");
            v16 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
            PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v18);
            if ( v16 )
            {
              PStringBase<char>::PStringBase<char>(&v18, "None");
              v17 = __stricmp(i_str->m_charbuffer->m_data, v18.m_charbuffer->m_data);
              PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v18);
              if ( v17 )
              {
                *o_sci = 0;
                result = 0;
              }
              else
              {
                *o_sci = 0;
                result = 1;
              }
            }
            else
            {
              *o_sci = 6;
              result = 1;
            }
          }
          else
          {
            *o_sci = 5;
            result = 1;
          }
        }
      }
    }
  }
  return result;
}

//----- (0068A800) --------------------------------------------------------  // acclient.c:674052
PStringBase<char> *__thiscall ControlNameMapper::GetNameBySemantic(ControlNameMapper *this, PStringBase<char> *result, DeviceType i_dt, unsigned int i_dwSemantic)
{
  volatile LONG *v4; // ST04_4@4
  char *v6; // ecx@5
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v7; // eax@6
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v8; // edx@9
  HashTableData<unsigned long,HeritageGroup_CG> **v9; // ecx@9
  HashTableData<unsigned long,HeritageGroup_CG> *v10; // eax@9
  volatile LONG *v11; // ST00_4@15
  PSRefBufferCharData<char> *v12; // eax@16
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> v13; // [sp+4h] [bp-Ch]@6

  if ( i_dt == 1 )
  {
    v6 = (char *)&this->m_hashKeyboardSemantics.m_intrusiveTable;
LABEL_8:
    v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)v6,
           &v13);
    goto LABEL_9;
  }
  if ( i_dt != 2 )
  {
    if ( i_dt != 3 )
    {
      v4 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
      result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
      InterlockedIncrement(v4);
      return result;
    }
    v6 = (char *)&this->m_hashJoystickSemantics.m_intrusiveTable;
    goto LABEL_8;
  }
  v7 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_hashMouseSemantics.m_intrusiveTable,
         &v13);
LABEL_9:
  v8 = v7->m_currHashTable;
  v9 = v7->m_currBucket;
  v10 = v7->m_currElement;
  if ( v10 )
  {
    do
    {
LABEL_10:
      if ( v10->m_data.vfptr == (HeritageGroup_CGVtbl *)i_dwSemantic )
      {
        v12 = (PSRefBufferCharData<char> *)v10->m_hashKey;
        result->m_charbuffer = v12;
        InterlockedIncrement((volatile LONG *)&v12[-1]);
        return result;
      }
      v10 = v10->m_hashNext;
    }
    while ( v10 );
    while ( 1 )
    {
      ++v9;
      if ( v9 == &v8->m_buckets[v8->m_numBuckets] )
        break;
      if ( *v9 )
      {
        v10 = *v9;
        if ( *v9 )
          goto LABEL_10;
        break;
      }
    }
  }
  v11 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
  result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
  InterlockedIncrement(v11);
  return result;
}

//----- (0068A8D0) --------------------------------------------------------  // acclient.c:674128
char __cdecl DeviceTypeToString(DeviceType i_dt, PStringBase<char> *o_str)
{
  char result; // al@2

  switch ( i_dt )
  {
    case 1:
      PStringBase<char>::set(o_str, "Keyboard");
      result = 1;
      break;
    case 2:
      PStringBase<char>::set(o_str, "Mouse");
      result = 1;
      break;
    case 3:
      PStringBase<char>::set(o_str, "Joystick");
      result = 1;
      break;
    case 4:
      PStringBase<char>::set(o_str, "Virtual");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0068A940) --------------------------------------------------------  // acclient.c:674158
char __cdecl ControlActivationTypeToString(unsigned int i_cat, PStringBase<char> *o_str)
{
  char result; // al@2

  switch ( i_cat & 0x7FFFFFFF )
  {
    case 1u:
      PStringBase<char>::set(o_str, "Down");
      result = 1;
      break;
    case 2u:
      PStringBase<char>::set(o_str, "Up");
      result = 1;
      break;
    case 3u:
      PStringBase<char>::set(o_str, "Click");
      result = 1;
      break;
    case 4u:
      PStringBase<char>::set(o_str, "Tap");
      result = 1;
      break;
    case 8u:
      PStringBase<char>::set(o_str, "DblClickDown");
      result = 1;
      break;
    case 0x10u:
      PStringBase<char>::set(o_str, "DblClickUp");
      result = 1;
      break;
    case 0x18u:
      PStringBase<char>::set(o_str, "DblClick");
      result = 1;
      break;
    case 0x20u:
      PStringBase<char>::set(o_str, "NearbyDown");
      result = 1;
      break;
    case 0x40u:
      PStringBase<char>::set(o_str, "NearbyUp");
      result = 1;
      break;
    case 0x60u:
      PStringBase<char>::set(o_str, "MouseDblClick");
      result = 1;
      break;
    case 0x80u:
      PStringBase<char>::set(o_str, "Analog");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0068AAD0) --------------------------------------------------------  // acclient.c:674216
char __cdecl SubControlIndexToString(SubControlIndex i_sci, PStringBase<char> *o_str)
{
  char result; // al@2

  switch ( i_sci )
  {
    case 0:
      PStringBase<char>::set(o_str, "None");
      result = 1;
      break;
    case 1:
      PStringBase<char>::set(o_str, "AxisPositive");
      result = 1;
      break;
    case 2:
      PStringBase<char>::set(o_str, "AxisNegative");
      result = 1;
      break;
    case 3:
      PStringBase<char>::set(o_str, "POVUp");
      result = 1;
      break;
    case 4:
      PStringBase<char>::set(o_str, "POVRight");
      result = 1;
      break;
    case 5:
      PStringBase<char>::set(o_str, "POVDown");
      result = 1;
      break;
    case 6:
      PStringBase<char>::set(o_str, "POVLeft");
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0068AB80) --------------------------------------------------------  // acclient.c:674258
char __thiscall ControlSpecification::ToFileNode(ControlSpecification *this, PFileNode *i_pNode, DeviceType i_dt)
{
  ControlSpecification *v3; // esi@1
  DeviceType v4; // edi@1
  volatile LONG *v5; // ebx@1
  int v6; // edi@1
  DeviceType v7; // ST08_4@6
  __int32 v8; // esi@6
  __int32 v10; // esi@13

  v3 = this;
  PFileNode::MakeSubNodeAsUInt32(i_pNode, this->m_dwKey & 0xFF);
  ControlNameMapper::GetNameBySemantic(&g_ControlNameMapper, (PStringBase<char> *)&i_dt, i_dt, *((_WORD *)&v3->1 + 1));
  v4 = i_dt;
  v5 = (volatile LONG *)(i_dt - 16);
  InterlockedIncrement((volatile LONG *)(i_dt - 16));
  InterlockedIncrement(v5);
  PFileNode::MakeSubNodeAsPString(i_pNode, (PStringBase<char>)v4);
  v6 = v4 - 20;
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  if ( !BYTE1(v3->m_dwKey) )
    goto LABEL_9;
  i_dt = (DeviceType)PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( SubControlIndexToString((SubControlIndex)BYTE1(v3->m_dwKey), (PStringBase<char> *)&i_dt) )
  {
    v7 = i_dt;
    InterlockedIncrement((volatile LONG *)(i_dt - 16));
    PFileNode::MakeSubNode(i_pNode, (PStringBase<char>)v7);
    v8 = i_dt - 20;
    if ( !InterlockedDecrement((volatile LONG *)(i_dt - 20 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
LABEL_9:
    if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) )
    {
      if ( v6 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
    }
    return 1;
  }
  v10 = i_dt - 20;
  if ( !InterlockedDecrement((volatile LONG *)(i_dt - 20 + 4)) && v10 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v10)(v10, 1);
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  return 0;
}

//----- (0068ACB0) --------------------------------------------------------  // acclient.c:674308
PStringBase<char> *__thiscall ControlSpecification::GetDIKName(ControlSpecification *this, PStringBase<char> *result)
{
  ControlSpecification *v2; // esi@1
  volatile LONG *v3; // ST08_4@2
  PStringBase<char> *v4; // eax@2
  DeviceType v5; // eax@3

  v2 = this;
  if ( ICIDM::s_cidm )
  {
    v5 = ((int (__stdcall *)(unsigned int))ICIDM::s_cidm->vfptr->GetDeviceTypeFromKey)(this->m_dwKey);
    ControlNameMapper::GetNameBySemantic(&g_ControlNameMapper, result, v5, *((_WORD *)&v2->1 + 1));
    v4 = result;
  }
  else
  {
    v3 = (volatile LONG *)&PStringBase<char>::null_string.m_charbuffer[-1];
    result->m_charbuffer = PStringBase<char>::null_string.m_charbuffer;
    InterlockedIncrement(v3);
    v4 = result;
  }
  return v4;
}

//----- (0068AD10) --------------------------------------------------------  // acclient.c:674333
char __thiscall HashTable<PStringBase<char>,unsigned long,0>::find(HashTable<PStringBase<char>,unsigned long,0> *this, PStringBase<char> *_key, unsigned int *_retval)
{
  char v3; // al@2
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+0h] [bp-Ch]@1

  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable,
    &result,
    _key);
  if ( result.m_currElement )
  {
    *_retval = (unsigned int)result.m_currElement->m_data;
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  return v3;
}

//----- (0068AD50) --------------------------------------------------------  // acclient.c:674355
UIPreferenceItem *__thiscall ControlNameMapper::GetSemanticByName(ControlNameMapper *this, PStringBase<char> *strName)
{
  ControlNameMapper *v2; // esi@1
  HashTableData<PStringBase<char>,UIPreferenceItem *> *v3; // eax@1
  UIPreferenceItem *v4; // eax@4
  unsigned int retval; // [sp+8h] [bp-10h]@1
  IntrusiveHashIterator<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> result; // [sp+Ch] [bp-Ch]@1

  v2 = this;
  retval = -1;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
    (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_hashKeyboardSemantics.m_intrusiveTable,
    &result,
    strName);
  v3 = result.m_currElement;
  if ( result.m_currElement
    || (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v2->m_hashMouseSemantics.m_intrusiveTable,
          &result,
          strName),
        (v3 = result.m_currElement) != 0)
    || (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::find_internal(
          (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v2->m_hashJoystickSemantics.m_intrusiveTable,
          &result,
          strName),
        (v3 = result.m_currElement) != 0) )
  {
    v4 = v3->m_data;
  }
  else
  {
    HashTable<PStringBase<char>,unsigned long,0>::find(&v2->m_hashVirtualSemantics, strName, &retval);
    v4 = (UIPreferenceItem *)retval;
  }
  return v4;
}

//----- (0068ADD0) --------------------------------------------------------  // acclient.c:674393
void __thiscall IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>(IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0> *this, unsigned int _numBuckets)
{
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0> *v2; // esi@1
  unsigned int *v3; // edi@1
  const unsigned int *v4; // eax@1
  unsigned int v5; // eax@3
  void *v6; // edi@6
  unsigned int v7; // ecx@6

  v2 = this;
  this->m_buckets = 0;
  this->m_firstInterestingBucket = 0;
  this->m_numBuckets = 0;
  this->m_numElements = 0;
  this->vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  v3 = g_bucketSizesEnd;
  v4 = _STL::__lower_bound(g_bucketSizesBegin, g_bucketSizesEnd, &_numBuckets);
  if ( v4 == v3 )
    --v4;
  v5 = *v4;
  v2->m_numBuckets = v5;
  if ( v5 > 0x17 )
    v2->m_buckets = (HashTableData<PStringBase<char>,unsigned long> **)operator new[](4 * v5);
  else
    v2->m_buckets = v2->m_aInplaceBuckets;
  v6 = v2->m_buckets;
  v7 = 4 * v2->m_numBuckets;
  v2->m_firstInterestingBucket = (HashTableData<PStringBase<char>,unsigned long> **)((char *)v6 + v7);
  memset(v6, 0, v7);
}
// 7FF098: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable)(void *, char);

//----- (0068AE60) --------------------------------------------------------  // acclient.c:674426
char __cdecl StringToControlActivationType(PStringBase<char> *i_str, unsigned int *o_cat)
{
  PSRefBufferCharData<char> *v2; // esi@2
  int v3; // eax@2
  char *v4; // ebp@2
  bool v5; // bl@2
  unsigned int *v6; // eax@6
  unsigned int v7; // ecx@6
  int v8; // eax@7
  char *v9; // ebp@7
  bool v10; // bl@7
  int v11; // eax@12
  char *v12; // ebp@12
  bool v13; // bl@12
  int v14; // eax@17
  char *v15; // ebp@17
  bool v16; // bl@17
  int v17; // eax@22
  char *v18; // ebp@22
  bool v19; // bl@22
  int v20; // eax@27
  char *v21; // ebp@27
  bool v22; // bl@27
  int v23; // eax@32
  char *v24; // ebp@32
  bool v25; // bl@32
  int v26; // ebx@37
  int v27; // ebx@39
  int v28; // ebx@41
  int v29; // ebx@43
  char *v30; // esi@46
  int v32; // esi@50
  PStringBase<char> str; // [sp+1Ch] [bp-40h]@1
  PStringBase<char> v34; // [sp+20h] [bp-3Ch]@2
  PStringBase<char> v35; // [sp+24h] [bp-38h]@7
  PStringBase<char> v36; // [sp+28h] [bp-34h]@12
  PStringBase<char> v37; // [sp+2Ch] [bp-30h]@17
  PStringBase<char> v38; // [sp+30h] [bp-2Ch]@22
  PStringBase<char> v39; // [sp+34h] [bp-28h]@27
  PStringBase<char> v40; // [sp+38h] [bp-24h]@32
  PStringBase<char> v41; // [sp+3Ch] [bp-20h]@37
  PStringBase<char> v42; // [sp+40h] [bp-1Ch]@39
  PStringBase<char> v43; // [sp+44h] [bp-18h]@41
  PStringBase<char> v44; // [sp+48h] [bp-14h]@43
  List<PStringBase<char> > list; // [sp+4Ch] [bp-10h]@1

  *o_cat = 0;
  list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  list._head = 0;
  list._tail = 0;
  list._num_elements = 0;
  PSUtils::explode(i_str, 47, &list);
  str.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  if ( !List<PStringBase<char>>::pop_front(&list, &str) )
  {
LABEL_46:
    v30 = &str.m_charbuffer[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1]) )
    {
      if ( v30 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v30)(v30, 1);
    }
    list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
    List<PStringBase<char>>::flush(&list);
    return 1;
  }
  while ( 1 )
  {
    PStringBase<char>::allocate_ref_buffer(&v34, strlen("Down"));
    strcpy(v34.m_charbuffer->m_data, "Down");
    v2 = str.m_charbuffer;
    v3 = __stricmp(str.m_charbuffer->m_data, v34.m_charbuffer->m_data);
    v4 = &v34.m_charbuffer[-2].m_data[12];
    v5 = v3 == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v34.m_charbuffer[-1]) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    if ( !v5 )
      break;
    v6 = o_cat;
    v7 = *o_cat | 1;
LABEL_45:
    *v6 = v7;
    if ( !List<PStringBase<char>>::pop_front(&list, &str) )
      goto LABEL_46;
  }
  PStringBase<char>::PStringBase<char>(&v35, "Up");
  v8 = __stricmp(v2->m_data, v35.m_charbuffer->m_data);
  v9 = &v35.m_charbuffer[-2].m_data[12];
  v10 = v8 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v35.m_charbuffer[-1]) && v9 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  if ( v10 )
  {
    v6 = o_cat;
    v7 = *o_cat | 2;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v36, "Click");
  v11 = __stricmp(v2->m_data, v36.m_charbuffer->m_data);
  v12 = &v36.m_charbuffer[-2].m_data[12];
  v13 = v11 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v36.m_charbuffer[-1]) && v12 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v12)(v12, 1);
  if ( v13 )
  {
    v6 = o_cat;
    v7 = *o_cat | 3;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v37, "Tap");
  v14 = __stricmp(v2->m_data, v37.m_charbuffer->m_data);
  v15 = &v37.m_charbuffer[-2].m_data[12];
  v16 = v14 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v37.m_charbuffer[-1]) && v15 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v15)(v15, 1);
  if ( v16 )
  {
    v6 = o_cat;
    v7 = *o_cat | 4;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v38, "DblClickDown");
  v17 = __stricmp(v2->m_data, v38.m_charbuffer->m_data);
  v18 = &v38.m_charbuffer[-2].m_data[12];
  v19 = v17 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v38.m_charbuffer[-1]) && v18 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v18)(v18, 1);
  if ( v19 )
  {
    v6 = o_cat;
    v7 = *o_cat | 8;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v39, "DblClickUp");
  v20 = __stricmp(v2->m_data, v39.m_charbuffer->m_data);
  v21 = &v39.m_charbuffer[-2].m_data[12];
  v22 = v20 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v39.m_charbuffer[-1]) && v21 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v21)(v21, 1);
  if ( v22 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x10;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v40, "DblClick");
  v23 = __stricmp(v2->m_data, v40.m_charbuffer->m_data);
  v24 = &v40.m_charbuffer[-2].m_data[12];
  v25 = v23 == 0;
  if ( !InterlockedDecrement((volatile LONG *)&v40.m_charbuffer[-1]) && v24 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v24)(v24, 1);
  if ( v25 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x18;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v41, "NearbyDown");
  v26 = __stricmp(v2->m_data, v41.m_charbuffer->m_data);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v41);
  if ( !v26 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x20;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v42, "NearbyUp");
  v27 = __stricmp(v2->m_data, v42.m_charbuffer->m_data);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v42);
  if ( !v27 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x40;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v43, "MouseDblClick");
  v28 = __stricmp(v2->m_data, v43.m_charbuffer->m_data);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v43);
  if ( !v28 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x60;
    goto LABEL_45;
  }
  PStringBase<char>::PStringBase<char>(&v44, "Analog");
  v29 = __stricmp(v2->m_data, v44.m_charbuffer->m_data);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v44);
  if ( !v29 )
  {
    v6 = o_cat;
    v7 = *o_cat | 0x80;
    goto LABEL_45;
  }
  v32 = (int)&v2[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v32 + 4)) && v32 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v32)(v32, 1);
  list.vfptr = (List<PStringBase<char> >Vtbl *)&List<PStringBase<char>>::vftable;
  List<PStringBase<char>>::flush(&list);
  return 0;
}
// 794074: using guessed type int (__thiscall *List<PStringBase<char>>::vftable)(void *, char);

//----- (0068B2B0) --------------------------------------------------------  // acclient.c:674630
char __userpurge ControlSpecification::FromFileNode@<al>(ControlSpecification *this@<ecx>, int a2@<edi>, PFileNode *i_pNode)
{
  PFileNode *v3; // esi@1
  ControlSpecification *v4; // ebx@1
  unsigned int v5; // eax@2
  void *v6; // ecx@2
  int v7; // edi@4
  PFileNode *v8; // ebp@6
  UIPreferenceItem *v9; // eax@6
  int v10; // edi@6
  ReferenceCountTemplate<1048576,0>Vtbl *v11; // eax@8
  PFileNode *v12; // esi@8
  char result; // al@10
  char v14; // al@12
  PFileNode *v15; // esi@14
  void *v16; // ecx@14
  int v17; // esi@14
  int v18; // edx@16
  void *v19; // [sp-8h] [bp-24h]@10
  void *v20; // [sp-4h] [bp-20h]@10
  PStringBase<char> o_name; // [sp+10h] [bp-Ch]@9
  unsigned int uDevice; // [sp+14h] [bp-8h]@4
  SubControlIndex sci; // [sp+18h] [bp-4h]@8

  v3 = i_pNode;
  v4 = this;
  if ( !i_pNode )
    return 0;
  v5 = PFileNode::GetNumSubNodes(i_pNode);
  if ( v5 < 2 || v5 > 3 )
  {
    v20 = (void *)v5;
    v19 = v6;
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&v19,
      "ERROR - Must have 2 or 3 sub nodes, has %d instead.\n");
    PFileNode::ReportError(a2, v3, (PStringBase<char>)v19);
    return 0;
  }
  v7 = (int)v3->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 0);
  uDevice = -1;
  if ( !PFileNode::GetNameAsUInt32((PFileNode *)v7, v7, &uDevice) || uDevice >= 0x100 )
  {
    i_pNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    PFileNode::GetNameAsPString((PFileNode *)v7, v7, (PStringBase<char> *)&i_pNode);
    v15 = i_pNode;
    v20 = i_pNode;
    v19 = v16;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "ERROR - invalid device index \"%s\"\n");
    PFileNode::ReportError(v7, (PFileNode *)v7, (PStringBase<char>)v19);
    v17 = (int)&v15[-1].sub_nodes.m_num;
    if ( !InterlockedDecrement((volatile LONG *)(v17 + 4)) && v17 )
    {
      v18 = *(_DWORD *)v17;
      v20 = (void *)1;
      (*(void (__thiscall **)(int, signed int))v18)(v17, 1);
      return 0;
    }
    return 0;
  }
  v8 = (PFileNode *)v3->vfptr[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 1u);
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&i_pNode);
  PFileNode::GetNameAsPString(v8, v7, (PStringBase<char> *)&i_pNode);
  v9 = ControlNameMapper::GetSemanticByName(&g_ControlNameMapper, (PStringBase<char> *)&i_pNode);
  v10 = (int)v9;
  if ( v9 == (UIPreferenceItem *)-1 || HIWORD(v9) )
  {
    v20 = i_pNode;
    v19 = i_pNode;
    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "ERROR - invalid device constant name \"%s\"\n");
    PFileNode::ReportError(v10, v8, (PStringBase<char>)v19);
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_pNode);
    result = 0;
  }
  else
  {
    v11 = v3->vfptr;
    sci = 0;
    v12 = (PFileNode *)v11[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, 2u);
    if ( v12 )
    {
      PStringBase<char>::PStringBase<char>(&o_name);
      PFileNode::GetNameAsPString(v12, v10, &o_name);
      if ( !StringToSubControlIndex(&o_name, &sci) )
      {
        v20 = o_name.m_charbuffer;
        v19 = o_name.m_charbuffer;
        PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v19, "ERROR - invalid sub control index \"%s\"\n");
        PFileNode::ReportError(v10, v12, (PStringBase<char>)v19);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&o_name);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_pNode);
        return 0;
      }
      PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&o_name);
    }
    v14 = sci;
    LOBYTE(v4->m_dwKey) = uDevice;
    BYTE1(v4->m_dwKey) = v14;
    *((_WORD *)&v4->1 + 1) = v10;
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&i_pNode);
    result = 1;
  }
  return result;
}

//----- (0068B610) --------------------------------------------------------  // acclient.c:674857
void __thiscall ControlNameMapper::AddKeySemantic(ControlNameMapper *this, const char *pszName, unsigned int dwValue)
{
  ControlNameMapper *v3; // esi@1
  unsigned int v4; // eax@1
  bool v5; // cf@1
  bool v6; // zf@1
  const char *v7; // eax@1
  HashTable<PStringBase<char>,UIPreferenceItem *,0> *v8; // ecx@4
  const char *v9; // esi@9

  v3 = this;
  PStringBase<char>::PStringBase<char>((PStringBase<char> *)&pszName, pszName);
  v4 = *((_DWORD *)pszName - 1);
  v5 = v4 < 2;
  v6 = v4 == 2;
  v7 = &pszName[v4 - 1];
  if ( !v5 && !v6 )
    v7 = pszName + 2;
  switch ( *v7 )
  {
    case 75:
      v8 = (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)v3;
      goto LABEL_8;
    case 77:
      HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
        (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)&v3->m_hashMouseSemantics,
        (PStringBase<char> *)&pszName,
        (UIPreferenceItem *const *)&dwValue);
      break;
    case 74:
      HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
        (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)&v3->m_hashJoystickSemantics,
        (PStringBase<char> *)&pszName,
        (UIPreferenceItem *const *)&dwValue);
      break;
    case 86:
      v8 = (HashTable<PStringBase<char>,UIPreferenceItem *,0> *)&v3->m_hashVirtualSemantics;
LABEL_8:
      HashTable<PStringBase<char>,UIPreferenceItem *,0>::add(
        v8,
        (PStringBase<char> *)&pszName,
        (UIPreferenceItem *const *)&dwValue);
      break;
    default:
      break;
  }
  v9 = pszName - 20;
  if ( !InterlockedDecrement((volatile LONG *)pszName - 4) )
  {
    if ( v9 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v9)(v9, 1);
  }
}

//----- (0068B6D0) --------------------------------------------------------  // acclient.c:674912
HashTable<PStringBase<char>,unsigned long,0> *__thiscall HashTable<PStringBase<char>,unsigned long,0>::scalar_deleting_destructor(HashTable<PStringBase<char>,unsigned long,0> *this, unsigned int a2)
{
  HashTable<PStringBase<char>,unsigned long,0> *v2; // edi@1
  char *v3; // esi@1
  void *v4; // eax@1

  v2 = this;
  v3 = (char *)&this->m_intrusiveTable;
  this->vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_intrusiveTable);
  v4 = (void *)*((_DWORD *)v3 + 24);
  *(_DWORD *)v3 = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v4 != v3 + 4 )
    operator delete[](v4);
  *((_DWORD *)v3 + 24) = 0;
  *((_DWORD *)v3 + 25) = 0;
  *((_DWORD *)v3 + 26) = 0;
  *((_DWORD *)v3 + 27) = 0;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7FF098: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable)(void *, char);
// 7FF228: using guessed type int (__thiscall *HashTable<PStringBase<char>,unsigned long,0>::vftable)(void *, char);

//----- (0068B730) --------------------------------------------------------  // acclient.c:674938
void __thiscall ControlNameMapper::~ControlNameMapper(ControlNameMapper *this)
{
  ControlNameMapper *v1; // edi@1
  char *v2; // esi@1
  void *v3; // eax@1
  void *v4; // eax@3
  void *v5; // eax@5
  void *v6; // eax@7

  v1 = this;
  v2 = (char *)&this->m_hashVirtualSemantics.m_intrusiveTable;
  this->m_hashVirtualSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&this->m_hashVirtualSemantics.m_intrusiveTable);
  v3 = (void *)*((_DWORD *)v2 + 24);
  *(_DWORD *)v2 = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v3 != v2 + 4 )
    operator delete[](v3);
  *((_DWORD *)v2 + 24) = 0;
  *((_DWORD *)v2 + 25) = 0;
  *((_DWORD *)v2 + 26) = 0;
  *((_DWORD *)v2 + 27) = 0;
  v1->m_hashJoystickSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v1->m_hashJoystickSemantics.m_intrusiveTable);
  v4 = v1->m_hashJoystickSemantics.m_intrusiveTable.m_buckets;
  v1->m_hashJoystickSemantics.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v4 != v1->m_hashJoystickSemantics.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v4);
  v1->m_hashJoystickSemantics.m_intrusiveTable.m_buckets = 0;
  v1->m_hashJoystickSemantics.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashJoystickSemantics.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashJoystickSemantics.m_intrusiveTable.m_numElements = 0;
  v1->m_hashMouseSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v1->m_hashMouseSemantics.m_intrusiveTable);
  v5 = v1->m_hashMouseSemantics.m_intrusiveTable.m_buckets;
  v1->m_hashMouseSemantics.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v5 != v1->m_hashMouseSemantics.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v5);
  v1->m_hashMouseSemantics.m_intrusiveTable.m_buckets = 0;
  v1->m_hashMouseSemantics.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashMouseSemantics.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashMouseSemantics.m_intrusiveTable.m_numElements = 0;
  v1->m_hashKeyboardSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::delete_contents((IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0> *)&v1->m_hashKeyboardSemantics.m_intrusiveTable);
  v6 = v1->m_hashKeyboardSemantics.m_intrusiveTable.m_buckets;
  v1->m_hashKeyboardSemantics.m_intrusiveTable.vfptr = (IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>Vtbl *)&IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable;
  if ( v6 != v1->m_hashKeyboardSemantics.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v6);
  v1->m_hashKeyboardSemantics.m_intrusiveTable.m_buckets = 0;
  v1->m_hashKeyboardSemantics.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_hashKeyboardSemantics.m_intrusiveTable.m_numBuckets = 0;
  v1->m_hashKeyboardSemantics.m_intrusiveTable.m_numElements = 0;
}
// 7FF098: using guessed type int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable)(void *, char);
// 7FF228: using guessed type int (__thiscall *HashTable<PStringBase<char>,unsigned long,0>::vftable)(void *, char);

//----- (0068B820) --------------------------------------------------------  // acclient.c:674994
void __thiscall ControlNameMapper::LoadSemantics(ControlNameMapper *this)
{
  ControlNameMapper *v1; // esi@1

  v1 = this;
  ControlNameMapper::AddKeySemantic(this, "DIK_ESCAPE", 1u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_1", 2u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_2", 3u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_3", 4u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_4", 5u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_5", 6u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_6", 7u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_7", 8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_8", 9u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_9", 0xAu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_0", 0xBu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MINUS", 0xCu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_EQUALS", 0xDu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_BACK", 0xEu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_TAB", 0xFu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_Q", 0x10u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_W", 0x11u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_E", 0x12u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_R", 0x13u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_T", 0x14u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_Y", 0x15u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_U", 0x16u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_I", 0x17u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_O", 0x18u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_P", 0x19u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LBRACKET", 0x1Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RBRACKET", 0x1Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RETURN", 0x1Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LCONTROL", 0x1Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_A", 0x1Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_S", 0x1Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_D", 0x20u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F", 0x21u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_G", 0x22u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_H", 0x23u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_J", 0x24u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_K", 0x25u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_L", 0x26u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SEMICOLON", 0x27u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_APOSTROPHE", 0x28u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_GRAVE", 0x29u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LSHIFT", 0x2Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_BACKSLASH", 0x2Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_Z", 0x2Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_X", 0x2Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_C", 0x2Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_V", 0x2Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_B", 0x30u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_N", 0x31u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_M", 0x32u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_COMMA", 0x33u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PERIOD", 0x34u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SLASH", 0x35u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RSHIFT", 0x36u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MULTIPLY", 0x37u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LMENU", 0x38u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SPACE", 0x39u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_CAPITAL", 0x3Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F1", 0x3Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F2", 0x3Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F3", 0x3Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F4", 0x3Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F5", 0x3Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F6", 0x40u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F7", 0x41u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F8", 0x42u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F9", 0x43u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F10", 0x44u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F11", 0x57u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F12", 0x58u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F13", 0x64u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F14", 0x65u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_F15", 0x66u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMLOCK", 0x45u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SCROLL", 0x46u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD7", 0x47u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD8", 0x48u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD9", 0x49u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SUBTRACT", 0x4Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD4", 0x4Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD5", 0x4Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD6", 0x4Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_ADD", 0x4Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD1", 0x4Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD2", 0x50u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD3", 0x51u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPAD0", 0x52u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_DECIMAL", 0x53u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADENTER", 0x9Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RCONTROL", 0x9Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADCOMMA", 0xB3u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_DIVIDE", 0xB5u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_SYSRQ", 0xB7u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RMENU", 0xB8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PAUSE", 0xC5u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_HOME", 0xC7u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_UP", 0xC8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PRIOR", 0xC9u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LEFT", 0xCBu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RIGHT", 0xCDu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_END", 0xCFu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_DOWN", 0xD0u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NEXT", 0xD1u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_INSERT", 0xD2u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_DELETE", 0xD3u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LWIN", 0xDBu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RWIN", 0xDCu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_APPS", 0xDDu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MUTE", 0xA0u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_CALCULATOR", 0xA1u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PLAYPAUSE", 0xA2u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MEDIASTOP", 0xA4u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_VOLUMEDOWN", 0xAEu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_VOLUMEUP", 0xB0u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBHOME", 0xB2u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBSEARCH", 0xE5u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBFAVORITES", 0xE6u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBREFRESH", 0xE7u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBSTOP", 0xE8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBFORWARD", 0xE9u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_WEBBACK", 0xEAu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MYCOMPUTER", 0xEBu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MAIL", 0xECu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_MEDIASELECT", 0xEDu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_OEM_102", 0x56u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_ABNT_C1", 0x73u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_YEN", 0x7Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_ABNT_C2", 0x7Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADEQUALS", 0x8Du);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PREVTRACK", 0x90u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_AT", 0x91u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_COLON", 0x92u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_UNDERLINE", 0x93u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_STOP", 0x95u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_AX", 0x96u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_UNLABELED", 0x97u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NEXTTRACK", 0x99u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_BACKSPACE", 0xEu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADSTAR", 0x37u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LALT", 0x38u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_CAPSLOCK", 0x3Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADMINUS", 0x4Au);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADPLUS", 0x4Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADPERIOD", 0x53u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_NUMPADSLASH", 0xB5u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RALT", 0xB8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_UPARROW", 0xC8u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PGUP", 0xC9u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_LEFTARROW", 0xCBu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_RIGHTARROW", 0xCDu);
  ControlNameMapper::AddKeySemantic(v1, "DIK_DOWNARROW", 0xD0u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_PGDN", 0xD1u);
  ControlNameMapper::AddKeySemantic(v1, "DIK_CIRCUMFLEX", 0x90u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_WHEEL", 8u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_X", 0);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_Y", 4u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_Z", 8u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON0", 0xCu);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON1", 0xDu);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON2", 0xEu);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON3", 0xFu);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON4", 0x10u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON5", 0x11u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON6", 0x12u);
  ControlNameMapper::AddKeySemantic(v1, "DIMOFS_BUTTON7", 0x13u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_X", 0);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_Y", 4u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_Z", 8u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_RX", 0xCu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_RY", 0x10u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_RZ", 0x14u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_SLIDER0", 0x18u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_SLIDER1", 0x1Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_SLIDER(0)", 0x18u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_SLIDER(1)", 0x1Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV0", 0x20u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV1", 0x24u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV2", 0x28u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV3", 0x2Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV(0)", 0x20u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV(1)", 0x24u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV(2)", 0x28u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_POV(3)", 0x2Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON0", 0x30u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON1", 0x31u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON2", 0x32u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON3", 0x33u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON4", 0x34u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON5", 0x35u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON6", 0x36u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON7", 0x37u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON8", 0x38u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON9", 0x39u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON10", 0x3Au);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON11", 0x3Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON12", 0x3Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON13", 0x3Du);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON14", 0x3Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON15", 0x3Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON16", 0x40u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON17", 0x41u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON18", 0x42u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON19", 0x43u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON20", 0x44u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON21", 0x45u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON22", 0x46u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON23", 0x47u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON24", 0x48u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON25", 0x49u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON26", 0x4Au);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON27", 0x4Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON28", 0x4Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON29", 0x4Du);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON30", 0x4Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON31", 0x4Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(0)", 0x30u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(1)", 0x31u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(2)", 0x32u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(3)", 0x33u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(4)", 0x34u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(5)", 0x35u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(6)", 0x36u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(7)", 0x37u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(8)", 0x38u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(9)", 0x39u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(10)", 0x3Au);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(11)", 0x3Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(12)", 0x3Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(13)", 0x3Du);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(14)", 0x3Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(15)", 0x3Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(16)", 0x40u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(17)", 0x41u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(18)", 0x42u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(19)", 0x43u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(20)", 0x44u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(21)", 0x45u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(22)", 0x46u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(23)", 0x47u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(24)", 0x48u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(25)", 0x49u);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(26)", 0x4Au);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(27)", 0x4Bu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(28)", 0x4Cu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(29)", 0x4Du);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(30)", 0x4Eu);
  ControlNameMapper::AddKeySemantic(v1, "DIJOFS_BUTTON(31)", 0x4Fu);
  ControlNameMapper::AddKeySemantic(v1, "DIV_MOUSELOOK", 1u);
}

//----- (0068C660) --------------------------------------------------------  // acclient.c:675250
void __thiscall ControlNameMapper::ControlNameMapper(ControlNameMapper *this)
{
  ControlNameMapper *v1; // esi@1

  v1 = this;
  this->m_hashKeyboardSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>(
    &this->m_hashKeyboardSemantics.m_intrusiveTable,
    0x17u);
  v1->m_hashMouseSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>(
    &v1->m_hashMouseSemantics.m_intrusiveTable,
    0x17u);
  v1->m_hashJoystickSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>(
    &v1->m_hashJoystickSemantics.m_intrusiveTable,
    0x17u);
  v1->m_hashVirtualSemantics.vfptr = (HashTable<PStringBase<char>,unsigned long,0>Vtbl *)&HashTable<PStringBase<char>,unsigned long,0>::vftable;
  IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>(
    &v1->m_hashVirtualSemantics.m_intrusiveTable,
    0x17u);
  ControlNameMapper::LoadSemantics(v1);
}
// 7FF228: using guessed type int (__thiscall *HashTable<PStringBase<char>,unsigned long,0>::vftable)(void *, char);

//----- (00715BE0) --------------------------------------------------------  // acclient.c:808767
int sub_715BE0()
{
  ControlNameMapper::ControlNameMapper(&g_ControlNameMapper);
  return atexit(sub_77FAC0);
}

//----- (00715C00) --------------------------------------------------------  // acclient.c:808774
unsigned int sub_715C00()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_PositiveAxis");
  ID_sci_PositiveAxis = result;
  return result;
}

//----- (00715C20) --------------------------------------------------------  // acclient.c:808784
unsigned int _E78_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_NegativeAxis");
  ID_sci_NegativeAxis = result;
  return result;
}

//----- (00715C40) --------------------------------------------------------  // acclient.c:808794
unsigned int _E80_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_POVUp");
  ID_sci_POVUp = result;
  return result;
}

//----- (00715C60) --------------------------------------------------------  // acclient.c:808804
unsigned int _E82_55()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_POVRight");
  ID_sci_POVRight = result;
  return result;
}

//----- (00715C80) --------------------------------------------------------  // acclient.c:808814
unsigned int _E84_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_POVDown");
  ID_sci_POVDown = result;
  return result;
}

//----- (00715CA0) --------------------------------------------------------  // acclient.c:808824
unsigned int _E86_0()
{
  unsigned int result; // eax@1

  result = compute_str_hash("ID_sci_POVLeft");
  ID_sci_POVLeft = result;
  return result;
}

//----- (00715CC0) --------------------------------------------------------  // acclient.c:808834
int sub_715CC0()
{
  return atexit(nullsub_238);
}

//----- (0077FAC0) --------------------------------------------------------  // acclient.c:918298
void __cdecl sub_77FAC0()
{
  ControlNameMapper::~ControlNameMapper(&g_ControlNameMapper);
}

