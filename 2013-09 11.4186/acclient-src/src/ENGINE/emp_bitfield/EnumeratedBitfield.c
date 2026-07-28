/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EnumeratedBitfield
   Object     : ENGINE\emp_bitfield\EnumeratedBitfield.obj
   Functions  : 7
   Addresses  : 00676EA0 - 00677430 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00676EA0) --------------------------------------------------------  // acclient.c:653536
bool __thiscall EnumeratedBitfield<unsigned __int64>::InitByDataID(EnumeratedBitfield<unsigned __int64> *this, IDClass<_tagDataID,32,0> i_did)
{
  EnumeratedBitfield<unsigned __int64> *v2; // esi@1
  EnumMapper *v3; // edi@1
  QualifiedDataID *v4; // eax@1
  QualifiedDataID v6; // [sp+8h] [bp-8h]@1

  v2 = this;
  v3 = this->m_enumMapper.m_object;
  QualifiedDataID::QualifiedDataID(&v6, i_did, 0x24u);
  v2->m_enumMapper.m_object = (EnumMapper *)DBObj::Get(v4);
  if ( v3 )
    v3->vfptr->Release((Interface *)v3);
  return v2->m_enumMapper.m_object != 0;
}

//----- (00676EE0) --------------------------------------------------------  // acclient.c:653553
char __userpurge EnumeratedBitfield<unsigned long>::FromFileNode@<al>(EnumeratedBitfield<unsigned long> *this@<ecx>, int a2@<edi>, PFileNode *i_pcFileNode, unsigned int *o_eNum)
{
  PFileNode *v4; // esi@1
  char v5; // bl@2
  char result; // al@3
  PFileNode *i; // esi@4
  char v8; // al@5
  PFileNode *v9; // ecx@5
  PSRefBufferCharData<char> *v10; // ecx@7
  unsigned int v11; // eax@9
  int v12; // eax@14
  PStringBase<char> v13; // [sp-8h] [bp-2Ch]@7
  PFileNode *v14; // [sp-4h] [bp-28h]@3
  PStringBase<char> *v15; // [sp+10h] [bp-14h]@1
  unsigned int iIndex; // [sp+14h] [bp-10h]@7
  PFileNodeIter cIter; // [sp+18h] [bp-Ch]@4

  v4 = i_pcFileNode;
  v15 = (PStringBase<char> *)this;
  if ( i_pcFileNode )
  {
    v5 = 1;
    if ( this->m_enumMapper.m_object )
    {
      v14 = i_pcFileNode;
      *o_eNum = 0;
      PFileNodeIter::PFileNodeIter(&cIter, v14);
      for ( i = PFileNodeIter::Curr(&cIter); i; i = (PFileNode *)PFileNodeIter::Next(&cIter) )
      {
        i_pcFileNode = (PFileNode *)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        v8 = PFileNode::GetNameAsPString(i, a2, (PStringBase<char> *)&i_pcFileNode);
        a2 = (int)i_pcFileNode;
        if ( v8 )
        {
          v14 = (PFileNode *)&iIndex;
          v13.m_charbuffer = (PSRefBufferCharData<char> *)i_pcFileNode;
          InterlockedIncrement((volatile LONG *)&i_pcFileNode[-1].m_bProcessed);
          if ( EnumMapper::GetEnum(
                 (PStringBase<char>)v15->m_charbuffer,
                 (unsigned int *)v13.m_charbuffer,
                 (unsigned int *)v14) )
          {
            v11 = iIndex;
            if ( iIndex )
              v11 = 1 << (iIndex - 1);
            *o_eNum |= v11;
          }
          else
          {
            v14 = (PFileNode *)a2;
            v13.m_charbuffer = v10;
            PStringBase<char>::PStringBase<char>(&v13, "invalid emp value '%s'");
            PFileNode::ReportError(a2, i, v13);
            v5 = 0;
          }
        }
        else
        {
          v14 = v9;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v14, "expecting a string node");
          PFileNode::ReportError(a2, i, (PStringBase<char>)v14);
          v5 = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)(a2 - 20 + 4)) && a2 != 20 )
        {
          v12 = *(_DWORD *)(a2 - 20);
          v14 = (PFileNode *)1;
          (*(void (__thiscall **)(int, signed int))v12)(a2 - 20, 1);
        }
      }
      PFileNodeIter::~PFileNodeIter(&cIter);
      result = v5;
    }
    else
    {
      v14 = (PFileNode *)this;
      PStringBase<char>::PStringBase<char>(
        (PStringBase<char> *)&v14,
        "This Enumerated must be initializedprior to reading a filenode.");
      PFileNode::ReportError(a2, v4, (PStringBase<char>)v14);
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00677030) --------------------------------------------------------  // acclient.c:653645
char __userpurge EnumeratedBitfield<unsigned __int64>::FromFileNode@<al>(EnumeratedBitfield<unsigned __int64> *this@<ecx>, int a2@<edi>, PFileNode *i_pcFileNode, unsigned __int64 *o_eNum)
{
  PFileNode *v4; // esi@1
  unsigned __int64 *v6; // ebx@5
  PFileNode *i; // esi@5
  char v8; // al@6
  PFileNode *v9; // ecx@6
  PSRefBufferCharData<char> *v10; // ecx@8
  signed __int64 v11; // rax@10
  int v12; // ecx@13
  int v13; // eax@13
  int v14; // edx@16
  PStringBase<char> v15; // [sp-8h] [bp-2Ch]@8
  PFileNode *v16; // [sp-4h] [bp-28h]@3
  PStringBase<char> *v17; // [sp+10h] [bp-14h]@1
  unsigned int iIndex; // [sp+14h] [bp-10h]@8
  PFileNodeIter cIter; // [sp+18h] [bp-Ch]@5
  char i_pcFileNodea; // [sp+28h] [bp+4h]@2

  v4 = i_pcFileNode;
  v17 = (PStringBase<char> *)this;
  if ( !i_pcFileNode )
    return 0;
  i_pcFileNodea = 1;
  if ( !this->m_enumMapper.m_object )
  {
    v16 = (PFileNode *)this;
    PStringBase<char>::PStringBase<char>(
      (PStringBase<char> *)&v16,
      "This Enumerated must be initializedprior to reading a filenode.");
    PFileNode::ReportError(a2, v4, (PStringBase<char>)v16);
    return 0;
  }
  v6 = o_eNum;
  v16 = v4;
  *(_DWORD *)o_eNum = 0;
  *((_DWORD *)v6 + 1) = 0;
  PFileNodeIter::PFileNodeIter(&cIter, v16);
  for ( i = PFileNodeIter::Curr(&cIter); i; i = (PFileNode *)PFileNodeIter::Next(&cIter) )
  {
    o_eNum = (unsigned __int64 *)PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
    v8 = PFileNode::GetNameAsPString(i, a2, (PStringBase<char> *)&o_eNum);
    a2 = (int)o_eNum;
    if ( v8 )
    {
      v16 = (PFileNode *)&iIndex;
      v15.m_charbuffer = (PSRefBufferCharData<char> *)o_eNum;
      InterlockedIncrement((volatile LONG *)o_eNum - 4);
      if ( EnumMapper::GetEnum(
             (PStringBase<char>)v17->m_charbuffer,
             (unsigned int *)v15.m_charbuffer,
             (unsigned int *)v16) )
      {
        LODWORD(v11) = iIndex;
        if ( iIndex )
          v11 = 1i64 << ((unsigned __int8)iIndex - 1);
        else
          HIDWORD(v11) = 0;
        v12 = v11 | *(_DWORD *)v6;
        v13 = HIDWORD(v11) | *((_DWORD *)v6 + 1);
        *(_DWORD *)v6 = v12;
        *((_DWORD *)v6 + 1) = v13;
      }
      else
      {
        v16 = (PFileNode *)a2;
        v15.m_charbuffer = v10;
        PStringBase<char>::PStringBase<char>(&v15, "invalid emp value '%s'");
        PFileNode::ReportError(a2, i, v15);
        i_pcFileNodea = 0;
      }
    }
    else
    {
      v16 = v9;
      PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v16, "expecting a string node");
      PFileNode::ReportError(a2, i, (PStringBase<char>)v16);
      i_pcFileNodea = 0;
    }
    if ( !InterlockedDecrement((volatile LONG *)(a2 - 20 + 4)) && a2 != 20 )
    {
      v14 = *(_DWORD *)(a2 - 20);
      v16 = (PFileNode *)1;
      (*(void (__thiscall **)(int, signed int))v14)(a2 - 20, 1);
    }
  }
  PFileNodeIter::~PFileNodeIter(&cIter);
  return i_pcFileNodea;
}

//----- (00677190) --------------------------------------------------------  // acclient.c:653737
bool __thiscall EnumeratedBitfield<unsigned long>::InqStrings(EnumeratedBitfield<unsigned long> *this, unsigned int i_enum, PStringBaseArray<char> *o_strings)
{
  unsigned int *v3; // ebp@1
  bool result; // al@2
  PStringBase<char> *v5; // edi@3
  unsigned int i; // ebx@3
  unsigned int v7; // esi@8
  bool retval; // [sp+7h] [bp-1h]@3

  v3 = (unsigned int *)this;
  SmartArray<PStringBase<char>,1>::SetNElements((SmartArray<PStringBase<char>,1> *)&o_strings->m_data, 0, 1);
  if ( *v3 )
  {
    retval = 1;
    v5 = (PStringBase<char> *)1;
    for ( i = i_enum; i; v5 = (PStringBase<char> *)((char *)v5 + 1) )
    {
      if ( i & 1 )
      {
        i_enum = (unsigned int)PStringBase<char>::s_NullBuffer.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
        if ( EnumMapper::GetString(*v3, v5, (PStringBase<char> *)&i_enum) )
          SmartArray<PStringBase<char>,1>::AddToEnd(
            (SmartArray<PStringBase<char>,1> *)&o_strings->m_data,
            (PStringBase<char> *)&i_enum);
        else
          retval = 0;
        v7 = i_enum - 20;
        if ( !InterlockedDecrement((volatile LONG *)(i_enum - 20 + 4)) )
        {
          if ( v7 )
            (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
        }
      }
      i >>= 1;
    }
    result = retval;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00677240) --------------------------------------------------------  // acclient.c:653783
char __thiscall EnumeratedBitfield<unsigned long>::ToFileNode(EnumeratedBitfield<unsigned long> *this, unsigned int i_eNum, PFileNode *o_rcFileNode)
{
  PStringBase<char> *v3; // ecx@4
  PStringBase<char> *v4; // ebx@4
  PStringBase<char> v5; // esi@5
  volatile LONG *v6; // edi@5
  PFileNode *v7; // eax@5
  int v8; // esi@5
  PFileNode *v9; // edi@5
  PStringBase<char> *v11; // ecx@16
  bool v12; // zf@16
  PStringBaseArray<char> strArray; // [sp+10h] [bp-Ch]@3
  unsigned int i_eNuma; // [sp+20h] [bp+4h]@4

  if ( !o_rcFileNode || !this->m_enumMapper.m_object )
    return 0;
  strArray.m_data = 0;
  strArray.m_sizeAndDeallocate = 0;
  strArray.m_num = 0;
  if ( !EnumeratedBitfield<unsigned long>::InqStrings(this, i_eNum, &strArray) )
  {
    if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      v11 = strArray.m_data;
      v12 = (_DWORD)strArray.m_data == 0;
LABEL_19:
      if ( !v12 )
        PStringBase<unsigned short>::vector_deleting_destructor(v11, 3u);
    }
    return 0;
  }
  v3 = strArray.m_data;
  i_eNuma = (unsigned int)&strArray.m_data[strArray.m_num];
  v4 = strArray.m_data;
  if ( strArray.m_data != &strArray.m_data[strArray.m_num] )
  {
    while ( 1 )
    {
      v5.m_charbuffer = v4->m_charbuffer;
      v6 = (volatile LONG *)&v4->m_charbuffer[-1];
      InterlockedIncrement(v6);
      InterlockedIncrement(v6);
      v7 = PFileNode::MakeSubNodeAsPString(o_rcFileNode, v5);
      v8 = (int)&v5.m_charbuffer[-2].m_data[12];
      v9 = v7;
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      if ( !v9 )
        break;
      ++v4;
      if ( v4 == (PStringBase<char> *)i_eNuma )
      {
        v3 = strArray.m_data;
        goto LABEL_11;
      }
    }
    if ( (strArray.m_sizeAndDeallocate & 0x80000000) != 0x80000000 )
      return 0;
    v11 = strArray.m_data;
    v12 = (_DWORD)strArray.m_data == 0;
    goto LABEL_19;
  }
LABEL_11:
  if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v3 )
      PStringBase<unsigned short>::vector_deleting_destructor(v3, 3u);
  }
  return 1;
}

//----- (00677360) --------------------------------------------------------  // acclient.c:653855
bool __thiscall EnumeratedBitfield<unsigned __int64>::InqStrings(EnumeratedBitfield<unsigned __int64> *this, unsigned __int64 i_enum, PStringBaseArray<char> *o_strings)
{
  unsigned int *v3; // esi@1
  bool result; // al@2
  unsigned int v5; // edi@3
  PStringBase<char> *v6; // ebp@3
  unsigned int v7; // ebx@3
  int v8; // esi@10
  bool retval; // [sp+7h] [bp-5h]@3
  EnumeratedBitfield<unsigned __int64> *v10; // [sp+8h] [bp-4h]@1

  v3 = (unsigned int *)this;
  v10 = this;
  SmartArray<PStringBase<char>,1>::SetNElements((SmartArray<PStringBase<char>,1> *)&o_strings->m_data, 0, 1);
  if ( *v3 )
  {
    v5 = i_enum;
    retval = 1;
    v6 = (PStringBase<char> *)1;
    v7 = HIDWORD(i_enum);
    if ( i_enum )
    {
      while ( 1 )
      {
        if ( v5 & 1 )
        {
          LODWORD(i_enum) = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
          if ( EnumMapper::GetString(*v3, v6, (PStringBase<char> *)&i_enum) )
            SmartArray<PStringBase<char>,1>::AddToEnd(
              (SmartArray<PStringBase<char>,1> *)&o_strings->m_data,
              (PStringBase<char> *)&i_enum);
          else
            retval = 0;
          v8 = i_enum - 20;
          if ( !InterlockedDecrement((volatile LONG *)(i_enum - 20 + 4)) )
          {
            if ( v8 )
              (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
          }
        }
        v5 = __PAIR__(v7, v5) >> 1;
        v7 >>= 1;
        v6 = (PStringBase<char> *)((char *)v6 + 1);
        if ( !(v7 | v5) )
          break;
        v3 = (unsigned int *)v10;
      }
    }
    result = retval;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00677430) --------------------------------------------------------  // acclient.c:653914
char __thiscall EnumeratedBitfield<unsigned __int64>::ToFileNode(EnumeratedBitfield<unsigned __int64> *this, unsigned __int64 i_eNum, PFileNode *o_rcFileNode)
{
  PStringBase<char> *v3; // ecx@4
  PStringBase<char> *v4; // ebx@4
  PStringBase<char> v5; // esi@5
  volatile LONG *v6; // edi@5
  PFileNode *v7; // edi@5
  int v8; // esi@5
  PStringBase<char> *v10; // ecx@16
  bool v11; // zf@16
  PStringBaseArray<char> strArray; // [sp+10h] [bp-Ch]@3
  PStringBase<char> *end; // [sp+20h] [bp+4h]@4

  if ( !o_rcFileNode || !this->m_enumMapper.m_object )
    return 0;
  strArray.m_data = 0;
  strArray.m_sizeAndDeallocate = 0;
  strArray.m_num = 0;
  if ( !EnumeratedBitfield<unsigned __int64>::InqStrings(this, i_eNum, &strArray) )
  {
    if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    {
      v10 = strArray.m_data;
      v11 = (_DWORD)strArray.m_data == 0;
LABEL_19:
      if ( !v11 )
        PStringBase<unsigned short>::vector_deleting_destructor(v10, 3u);
    }
    return 0;
  }
  v3 = strArray.m_data;
  end = &strArray.m_data[strArray.m_num];
  v4 = strArray.m_data;
  if ( strArray.m_data != &strArray.m_data[strArray.m_num] )
  {
    while ( 1 )
    {
      v5.m_charbuffer = v4->m_charbuffer;
      v6 = (volatile LONG *)&v4->m_charbuffer[-1];
      InterlockedIncrement(v6);
      InterlockedIncrement(v6);
      v7 = PFileNode::MakeSubNodeAsPString(o_rcFileNode, v5);
      v8 = (int)&v5.m_charbuffer[-2].m_data[12];
      if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
      if ( !v7 )
        break;
      ++v4;
      if ( v4 == end )
      {
        v3 = strArray.m_data;
        goto LABEL_11;
      }
    }
    if ( (strArray.m_sizeAndDeallocate & 0x80000000) != 0x80000000 )
      return 0;
    v10 = strArray.m_data;
    v11 = (_DWORD)strArray.m_data == 0;
    goto LABEL_19;
  }
LABEL_11:
  if ( (strArray.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
  {
    if ( v3 )
      PStringBase<unsigned short>::vector_deleting_destructor(v3, 3u);
  }
  return 1;
}

