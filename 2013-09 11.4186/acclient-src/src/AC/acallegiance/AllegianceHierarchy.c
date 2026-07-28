/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : AllegianceHierarchy
   Object     : AC\acallegiance\AllegianceHierarchy.obj
   Functions  : 29
   Addresses  : 0041BC20 - 0070E750 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0041BC20) --------------------------------------------------------  // acclient.c:89183
signed int EnumMapper::GetDBOType()
{
  return 36;
}

//----- (005B6C20) --------------------------------------------------------  // acclient.c:481658
void __thiscall AllegianceHierarchy::Clear(AllegianceHierarchy *this, AllegianceNode **node)
{
  AllegianceNode **v2; // ebx@1
  AllegianceHierarchy *v3; // edi@1
  AllegianceNode *v4; // eax@2
  AllegianceNode **v5; // esi@3

  v2 = node;
  v3 = this;
  if ( *node )
  {
    v4 = (*node)->_vassal;
    node = (AllegianceNode **)v4;
    if ( v4 )
    {
      do
      {
        v5 = (AllegianceNode **)v4->_peer;
        AllegianceHierarchy::Clear(v3, (AllegianceNode **)&node);
        v4 = (AllegianceNode *)v5;
        node = v5;
      }
      while ( v5 );
    }
    if ( *v2 )
      ((void (__stdcall *)(_DWORD))(*v2)->vfptr->__vecDelDtor)(1);
    *v2 = 0;
  }
}

//----- (005B6C80) --------------------------------------------------------  // acclient.c:481689
int __thiscall AllegianceHierarchy::GetNodePackSize(AllegianceHierarchy *this, AllegianceNode *node)
{
  AllegianceNode *v2; // ebx@1
  AllegianceHierarchy *v3; // ebp@1
  int result; // eax@2
  PackObjVtbl *v5; // eax@3
  AllegianceNode *v6; // esi@3
  AllegianceNode *v7; // ecx@3
  int v8; // edi@3
  AllegianceNode *i; // esi@3
  unsigned int v10; // eax@4

  v2 = node;
  v3 = this;
  if ( node )
  {
    v5 = node->vfptr;
    v6 = node->_patron;
    v7 = node;
    node = 0;
    v8 = (v6 != 0 ? 4 : 0) + ((int (__thiscall *)(AllegianceNode *, AllegianceNode **, _DWORD))v5->Pack)(v7, &node, 0);
    for ( i = v2->_vassal; i; v8 += v10 )
    {
      v10 = AllegianceHierarchy::GetNodePackSize(v3, i);
      i = i->_peer;
    }
    result = v8;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6CE0) --------------------------------------------------------  // acclient.c:481725
AllegianceNode *__thiscall AllegianceHierarchy::Search(AllegianceHierarchy *this, const unsigned int id, AllegianceNode *node)
{
  AllegianceNode *result; // eax@1
  AllegianceHierarchy *v4; // ebx@1
  AllegianceNode *v5; // esi@3

  result = node;
  v4 = this;
  if ( node && id != node->_data._id )
  {
    v5 = node->_vassal;
    if ( v5 )
    {
      while ( 1 )
      {
        result = AllegianceHierarchy::Search(v4, id, v5);
        if ( result )
          break;
        v5 = v5->_peer;
        if ( !v5 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = 0;
    }
  }
  return result;
}

//----- (005B6D20) --------------------------------------------------------  // acclient.c:481758
unsigned int __thiscall AllegianceHierarchy::GetMonarchID(AllegianceHierarchy *this)
{
  AllegianceNode *v1; // eax@1
  unsigned int result; // eax@2

  v1 = this->m_pMonarch;
  if ( v1 )
    result = v1->_data._id;
  else
    result = 0;
  return result;
}

//----- (005B6D30) --------------------------------------------------------  // acclient.c:481772
int __thiscall AllegianceHierarchy::PackNode(AllegianceHierarchy *this, AllegianceNode *node, void **addr, unsigned int size)
{
  int result; // eax@2
  AllegianceNode *v5; // eax@3
  signed int v6; // ebx@4
  int v7; // eax@6
  AllegianceNode *v8; // esi@6
  int i; // ebx@6
  unsigned int v10; // eax@7
  AllegianceHierarchy *v11; // [sp+8h] [bp-4h]@1

  v11 = this;
  if ( node )
  {
    v5 = node->_patron;
    if ( v5 )
    {
      *(_DWORD *)*addr = v5->_data._id;
      *addr = (char *)*addr + 4;
      v6 = 4;
    }
    else
    {
      v6 = 0;
    }
    v7 = ((int (__thiscall *)(_DWORD, _DWORD, _DWORD))node->vfptr->Pack)(node, addr, size);
    v8 = node->_vassal;
    for ( i = v7 + v6; v8; i += v10 )
    {
      v10 = AllegianceHierarchy::PackNode(v11, v8, addr, size);
      v8 = v8->_peer;
    }
    result = i;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6DA0) --------------------------------------------------------  // acclient.c:481814
int __thiscall AllegianceHierarchy::LookUp(AllegianceHierarchy *this, const unsigned int id, AllegianceData *retval)
{
  AllegianceNode *v3; // eax@2
  int result; // eax@3

  if ( id && (v3 = AllegianceHierarchy::Search(this, id, this->m_pMonarch)) != 0 )
  {
    AllegianceData::operator=((int)retval, (int)&v3->_data);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6DD0) --------------------------------------------------------  // acclient.c:481832
unsigned int __thiscall AllegianceHierarchy::GetPatron(AllegianceHierarchy *this, const unsigned int id, AllegianceData *retval)
{
  AllegianceNode *v3; // eax@2
  AllegianceNode *v4; // eax@3
  unsigned int result; // eax@4

  if ( id && (v3 = AllegianceHierarchy::Search(this, id, this->m_pMonarch)) != 0 && (v4 = v3->_patron) != 0 )
  {
    AllegianceData::operator=((int)retval, (int)&v4->_data);
    result = retval->_id;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6E10) --------------------------------------------------------  // acclient.c:481851
unsigned int __thiscall AllegianceHierarchy::GetFirstVassal(AllegianceHierarchy *this, unsigned int id, AllegianceData *retval)
{
  AllegianceNode *v3; // eax@2
  AllegianceNode *v4; // eax@3
  unsigned int result; // eax@4

  if ( id && (v3 = AllegianceHierarchy::Search(this, id, this->m_pMonarch)) != 0 && (v4 = v3->_vassal) != 0 )
  {
    AllegianceData::operator=((int)retval, (int)&v4->_data);
    result = retval->_id;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6E50) --------------------------------------------------------  // acclient.c:481870
unsigned int __thiscall AllegianceHierarchy::GetNextVassal(AllegianceHierarchy *this, unsigned int vassal_id, AllegianceData *retval)
{
  AllegianceNode *v3; // eax@2
  AllegianceNode *v4; // eax@3
  unsigned int result; // eax@4

  if ( vassal_id && (v3 = AllegianceHierarchy::Search(this, vassal_id, this->m_pMonarch)) != 0 && (v4 = v3->_peer) != 0 )
  {
    AllegianceData::operator=((int)retval, (int)&v4->_data);
    result = retval->_id;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (005B6E90) --------------------------------------------------------  // acclient.c:481889
int __thiscall AllegianceHierarchy::Add(AllegianceHierarchy *this, const unsigned int patron, AllegianceData *new_data)
{
  unsigned int v3; // ebx@1
  AllegianceHierarchy *v4; // edi@1
  AllegianceNode *v5; // edx@2
  AllegianceNode *v6; // eax@3
  AllegianceNode *v7; // eax@4
  int result; // eax@7
  AllegianceNode *v9; // esi@10
  AllegianceNode *v10; // ebx@16
  AllegianceNode *v11; // eax@16
  int v12; // eax@17

  v3 = new_data->_id;
  v4 = this;
  if ( !v3 )
    return 0;
  v5 = this->m_pMonarch;
  if ( v5 )
  {
    if ( patron )
      v9 = AllegianceHierarchy::Search(this, patron, v5);
    else
      v9 = 0;
    if ( v9
      && v9->_data._id != v3
      && !AllegianceHierarchy::Search(v4, v3, v5)
      && (v10 = v9->_vassal, (v11 = (AllegianceNode *)operator new(0x48u)) != 0)
      && (AllegianceNode::AllegianceNode(v11, new_data), v12) )
    {
      *(_DWORD *)(v12 + 4) = v9;
      *(_DWORD *)(v12 + 8) = v10;
      v9->_vassal = (AllegianceNode *)v12;
      ++v4->m_total;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    v6 = (AllegianceNode *)operator new(0x48u);
    if ( v6 )
      AllegianceNode::AllegianceNode(v6, new_data);
    else
      v7 = 0;
    v4->m_pMonarch = v7;
    if ( !v7 )
      return 0;
    ++v4->m_total;
    result = 1;
  }
  return result;
}

//----- (005B6F50) --------------------------------------------------------  // acclient.c:481947
int __thiscall AllegianceHierarchy::Copy(AllegianceHierarchy *this, AllegianceNode *node, int copy_node)
{
  AllegianceHierarchy *v3; // ebx@1
  int result; // eax@2
  int v5; // edi@3
  AllegianceNode *v6; // eax@4
  const unsigned int v7; // eax@5
  AllegianceNode *i; // esi@8
  int v9; // eax@9

  v3 = this;
  if ( node )
  {
    v5 = 1;
    if ( copy_node )
    {
      v6 = node->_patron;
      if ( v6 )
        v7 = v6->_data._id;
      else
        v7 = 0;
      v5 = AllegianceHierarchy::Add(this, v7, &node->_data);
    }
    for ( i = node->_vassal; i; v5 &= v9 )
    {
      v9 = AllegianceHierarchy::Copy(v3, i, 1);
      i = i->_peer;
    }
    result = v5;
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (005B6FC0) --------------------------------------------------------  // acclient.c:481985
int __thiscall AllegianceHierarchy::GetPackSize(AllegianceHierarchy *this)
{
  AllegianceHierarchy *v1; // esi@1
  int v2; // edi@1
  int v3; // edi@1
  int v4; // edi@1
  int v5; // edi@1
  int v6; // edi@1
  int v7; // edi@1
  int v8; // edi@1
  void *mem; // [sp+18h] [bp-4h]@1

  mem = this;
  v1 = this;
  v2 = ((int (*)(void))this->vfptr[1].__vecDelDtor)();
  mem = 0;
  v3 = AC1Legacy::PStringBase<char>::Pack(&v1->m_motd, &mem, 0) + v2;
  v4 = AC1Legacy::PStringBase<char>::Pack(&v1->m_motdSetBy, &mem, 0) + v3;
  v5 = ((int (__stdcall *)(void **, _DWORD))v1->m_AllegianceOfficers.vfptr->Pack)(&mem, 0) + v4;
  v6 = ((int (__stdcall *)(void **, _DWORD))v1->m_OfficerTitles.vfptr->Pack)(&mem, 0) + v5;
  v7 = ((int (__stdcall *)(void **, _DWORD))v1->m_BindPoint.vfptr->Pack)(&mem, 0) + v6;
  v8 = AC1Legacy::PStringBase<char>::Pack(&v1->m_AllegianceName, &mem, 0) + v7;
  return v8 + AllegianceHierarchy::GetNodePackSize(v1, v1->m_pMonarch);
}

//----- (005B7060) --------------------------------------------------------  // acclient.c:482011
unsigned int __thiscall AllegianceHierarchy::Pack(AllegianceHierarchy *this, void **addr, unsigned int size)
{
  AllegianceHierarchy *v3; // edi@1
  unsigned int v4; // ebp@1
  void **v5; // esi@2
  char *v6; // eax@2
  char *v7; // edx@2
  char *v8; // ecx@2
  char *v9; // edx@2
  char *v10; // ecx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->GetPackSize)();
  if ( size >= v4 )
  {
    v5 = addr;
    *(_DWORD *)*addr = v3->m_total & 0xFFFF | 0xB0000;
    *addr = (char *)*addr + 4;
    ((void (__stdcall *)(void **, unsigned int))v3->m_AllegianceOfficers.vfptr->Pack)(addr, size);
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_OfficerTitles.vfptr->Pack)(&v3->m_OfficerTitles, addr, size);
    *(_DWORD *)*addr = v3->m_monarchBroadcastTime;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(_DWORD *)v6 = v3->m_monarchBroadcastsToday;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(_DWORD *)v7 = v3->m_spokesBroadcastTime;
    v8 = (char *)*addr + 4;
    *addr = v8;
    *(_DWORD *)v8 = v3->m_spokesBroadcastsToday;
    *v5 = (char *)*v5 + 4;
    AC1Legacy::PStringBase<char>::Pack(&v3->m_motd, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->m_motdSetBy, addr, size);
    *(_DWORD *)*addr = v3->m_chatRoomID;
    *v5 = (char *)*v5 + 4;
    ((void (__thiscall *)(int, void **, unsigned int))v3->m_BindPoint.vfptr->Pack)(&v3->m_BindPoint, addr, size);
    AC1Legacy::PStringBase<char>::Pack(&v3->m_AllegianceName, addr, size);
    *(_DWORD *)*addr = v3->m_NameLastSetTime;
    v9 = (char *)*addr + 4;
    *addr = v9;
    *(_DWORD *)v9 = v3->m_isLocked;
    v10 = (char *)*addr + 4;
    *addr = v10;
    *(_DWORD *)v10 = v3->m_ApprovedVassal;
    *v5 = (char *)*v5 + 4;
    AllegianceHierarchy::PackNode(v3, v3->m_pMonarch, addr, size);
  }
  return v4;
}

//----- (005B7170) --------------------------------------------------------  // acclient.c:482062
PSmartArray<AC1Legacy::PStringBase<char> > *__thiscall PSmartArray<AC1Legacy::PStringBase<char>>::scalar_deleting_destructor(PSmartArray<AC1Legacy::PStringBase<char> > *this, unsigned int a2)
{
  PSmartArray<AC1Legacy::PStringBase<char> > *v2; // esi@1
  AC1Legacy::PStringBase<char> *v3; // ecx@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackObj::vftable;
  v3 = this->m_data;
  if ( v3 )
    AC1Legacy::PStringBase<char>::vector_deleting_destructor(v3, 3u);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (005B71A0) --------------------------------------------------------  // acclient.c:482079
int __thiscall AC1Legacy::SmartArray<AC1Legacy::PStringBase<char>>::grow(AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *this, unsigned int _size)
{
  AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *v2; // esi@1
  unsigned int v3; // edi@3
  AC1Legacy::PStringBase<char> *v4; // ecx@4
  bool v5; // zf@4
  void *v7; // eax@7
  int v8; // ebx@8

  v2 = this;
  if ( _size < this->m_num )
    return 0;
  if ( _size <= this->m_size )
    return 1;
  v3 = 0;
  if ( _size )
  {
    v7 = operator new[](4 * _size + 4);
    if ( v7 )
    {
      v8 = (int)((char *)v7 + 4);
      *(_DWORD *)v7 = _size;
      vector_constructor_iterator(
        (char *)v7 + 4,
        4u,
        _size,
        (void *(__thiscall *)(void *))AC1Legacy::PStringBase<char>::PStringBase<char>);
      if ( v8 )
      {
        if ( v2->m_data )
        {
          if ( v2->m_num )
          {
            do
            {
              AC1Legacy::PStringBase<unsigned short>::operator=(
                (AC1Legacy::PStringBase<unsigned short> *)(4 * v3 + v8),
                (AC1Legacy::PStringBase<unsigned short> *)&v2->m_data[v3]);
              ++v3;
            }
            while ( v3 < v2->m_num );
          }
          if ( v2->m_data )
            AC1Legacy::PStringBase<char>::vector_deleting_destructor(v2->m_data, 3u);
        }
        v2->m_data = (AC1Legacy::PStringBase<char> *)v8;
        v2->m_size = _size;
        return 1;
      }
    }
    return 0;
  }
  v4 = this->m_data;
  v5 = v2->m_data == 0;
  v2->m_num = 0;
  v2->m_size = 0;
  if ( !v5 )
    AC1Legacy::PStringBase<char>::vector_deleting_destructor(v4, 3u);
  v2->m_data = 0;
  return 1;
}

//----- (005B7270) --------------------------------------------------------  // acclient.c:482142
AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *__thiscall AC1Legacy::SmartArray<AC1Legacy::PStringBase<char>>::operator=(AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *this, int a2)
{
  int v2; // edi@1
  AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *v3; // ebp@1
  int v4; // ecx@3
  AC1Legacy::PStringBase<char> *v5; // ebx@3
  unsigned int v6; // esi@3
  int v7; // eax@3
  AC1Legacy::PSRefBuffer<char> *v8; // edi@4
  AC1Legacy::PSRefBuffer<char> *v9; // eax@8
  int v11; // [sp+8h] [bp-4h]@3

  v2 = a2;
  v3 = this;
  if ( this->m_size >= *(_DWORD *)(a2 + 4)
    || (this->m_num = 0, AC1Legacy::SmartArray<AC1Legacy::PStringBase<char>>::grow(this, *(_DWORD *)(a2 + 4))) )
  {
    v4 = *(_DWORD *)(a2 + 8);
    v5 = v3->m_data;
    v6 = *(_DWORD *)a2;
    v7 = *(_DWORD *)a2 + 4 * v4;
    v11 = *(_DWORD *)a2 + 4 * v4;
    if ( *(_DWORD *)a2 < (unsigned int)v7 )
    {
      do
      {
        v8 = v5->m_buffer;
        if ( v5->m_buffer != *(AC1Legacy::PSRefBuffer<char> **)v6 )
        {
          if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
            v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
          v9 = *(AC1Legacy::PSRefBuffer<char> **)v6;
          v5->m_buffer = *(AC1Legacy::PSRefBuffer<char> **)v6;
          InterlockedIncrement((volatile LONG *)&v9->m_cRef);
          v7 = v11;
        }
        v6 += 4;
        ++v5;
      }
      while ( v6 < v7 );
      v2 = a2;
    }
    v3->m_num = *(_DWORD *)(v2 + 8);
  }
  return v3;
}

//----- (005B7300) --------------------------------------------------------  // acclient.c:482190
int __thiscall PSmartArray<AC1Legacy::PStringBase<char>>::StreamPack(PSmartArray<AC1Legacy::PStringBase<char> > *this, STREAMTYPE op, void **addr, unsigned int *size)
{
  unsigned int *v4; // ebp@1
  PSmartArray<AC1Legacy::PStringBase<char> > *v5; // esi@1
  unsigned int v6; // eax@3
  unsigned int v7; // ST0C_4@3
  unsigned int v8; // ebp@3
  unsigned int v9; // edi@5
  unsigned int arraySize; // [sp+10h] [bp-4h]@1

  v4 = size;
  v5 = this;
  arraySize = this->m_num;
  if ( !STREAMPACK(op, &arraySize, addr, size) )
    return 0;
  if ( op == 2 )
  {
    v6 = arraySize;
    v7 = arraySize;
    v5->m_num = 0;
    v8 = v6;
    if ( !AC1Legacy::SmartArray<AC1Legacy::PStringBase<char>>::grow(
            (AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *)&v5->m_data,
            v7) )
      return 0;
    v5->m_num = v8;
    v4 = size;
  }
  v9 = 0;
  if ( !v5->m_num )
    return 1;
  while ( STREAMPACK(op, &v5->m_data[v9], addr, v4) )
  {
    ++v9;
    if ( v9 >= v5->m_num )
      return 1;
  }
  return 0;
}

//----- (005B73A0) --------------------------------------------------------  // acclient.c:482231
int __cdecl STREAMPACK(STREAMTYPE op, AC1Legacy::PStringBase<char> *obj, void **addr, unsigned int *size)
{
  int result; // eax@4
  void *v5; // esi@5

  if ( op )
  {
    if ( op == 1 )
    {
      *size -= AC1Legacy::PStringBase<char>::Pack(obj, addr, *size);
      result = 1;
    }
    else if ( op == 2 )
    {
      v5 = *addr;
      result = AC1Legacy::PStringBase<char>::UnPack(obj, addr, *size);
      *size += (_BYTE *)v5 - (_BYTE *)*addr;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    *size -= AC1Legacy::PStringBase<char>::GetPackSize(obj);
    result = 1;
  }
  return result;
}

//----- (005B7410) --------------------------------------------------------  // acclient.c:482263
void __thiscall AllegianceHierarchy::Clear(AllegianceHierarchy *this)
{
  AllegianceHierarchy *v1; // esi@1
  AC1Legacy::PSRefBuffer<char> *v2; // edi@1
  volatile LONG *v3; // ST00_4@5
  AC1Legacy::PSRefBuffer<char> *v4; // edi@6
  volatile LONG *v5; // ST00_4@10
  AC1Legacy::PStringBase<char> *v6; // ecx@11
  AC1Legacy::PSRefBuffer<char> *v7; // edi@13
  volatile LONG *v8; // ST00_4@17

  v1 = this;
  AllegianceHierarchy::Clear(this, &this->m_pMonarch);
  v1->m_total = 0;
  v1->m_monarchBroadcastTime = 0;
  v1->m_spokesBroadcastTime = 0;
  v1->m_monarchBroadcastsToday = 0;
  v1->m_spokesBroadcastsToday = 0;
  v2 = v1->m_motd.m_buffer;
  if ( v2 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_motd.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v3);
  }
  v4 = v1->m_motdSetBy.m_buffer;
  if ( v4 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    v5 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_motdSetBy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v5);
  }
  v1->m_chatRoomID = 0;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_AllegianceOfficers.m_intrusiveTable);
  v6 = v1->m_OfficerTitles.m_data;
  v1->m_OfficerTitles.m_num = 0;
  v1->m_OfficerTitles.m_size = 0;
  if ( v6 )
    AC1Legacy::PStringBase<char>::vector_deleting_destructor(v6, 3u);
  v1->m_OfficerTitles.m_data = 0;
  v7 = v1->m_AllegianceName.m_buffer;
  if ( v7 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v7->m_cRef) && v7 )
      v7->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v7, 1u);
    v8 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_AllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v8);
  }
  v1->m_NameLastSetTime = 0;
  v1->m_isLocked = 0;
  v1->m_ApprovedVassal = 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B7520) --------------------------------------------------------  // acclient.c:482323
int __thiscall AllegianceHierarchy::UnPack(AllegianceHierarchy *this, void **addr, unsigned int size)
{
  unsigned int v3; // ebp@1
  AllegianceHierarchy *v4; // edi@1
  void **v5; // esi@2
  unsigned int v6; // ecx@2
  void *v7; // ebx@2
  __int16 v8; // ax@2
  signed int v9; // ecx@2
  int v10; // ebx@3
  int result; // eax@7
  int v12; // eax@11
  unsigned int v13; // ebx@12
  bool v14; // sf@14
  unsigned __int8 v15; // of@14
  int v16; // edx@19
  int v17; // eax@20
  int v18; // eax@21
  int v19; // eax@25
  unsigned int v20; // ecx@26
  const unsigned int v21; // ebx@41
  __int16 v22; // bp@41
  void *v23; // edx@42
  int v24; // eax@42
  unsigned int v25; // ecx@43
  AllegianceNode *v26; // edi@51
  void *start; // [sp+10h] [bp-40h]@2
  __int16 packed_nodes; // [sp+14h] [bp-3Ch]@2
  AllegianceData data; // [sp+18h] [bp-38h]@41

  v3 = size;
  v4 = this;
  if ( size < 4 )
    return 0;
  AllegianceHierarchy::Clear(this);
  v5 = addr;
  v6 = *(_DWORD *)*addr;
  v7 = *addr;
  *addr = (char *)*addr + 4;
  v8 = v6;
  v9 = v6 >> 16;
  v4->m_oldVersion = v9;
  packed_nodes = v8;
  start = v7;
  if ( v3 <= (_BYTE *)*v5 - (_BYTE *)v7 )
    v10 = 0;
  else
    v10 = v3 - ((_BYTE *)*v5 - (_BYTE *)v7);
  if ( v9 < 6 )
  {
    if ( v9 >= 1 && (unsigned int)v10 >= 4 )
      *v5 = (char *)*v5 + 4;
  }
  else if ( !((int (__thiscall *)(int, void **, int))v4->m_AllegianceOfficers.vfptr->UnPack)(
               &v4->m_AllegianceOfficers.vfptr,
               v5,
               v10) )
  {
    return 0;
  }
  v12 = (_BYTE *)*v5 - (_BYTE *)start;
  if ( v3 <= v12 )
    v13 = 0;
  else
    v13 = v3 - v12;
  v15 = __OFSUB__(v4->m_oldVersion, 9);
  v14 = v4->m_oldVersion - 9 < 0;
  addr = (void **)v13;
  if ( !(v14 ^ v15) )
  {
    if ( !((int (__thiscall *)(int, void **, unsigned int))v4->m_OfficerTitles.vfptr->UnPack)(
            &v4->m_OfficerTitles,
            v5,
            v13) )
      return 0;
    v3 = size;
  }
  if ( v4->m_oldVersion >= 2 && v13 >= 4 )
  {
    v4->m_monarchBroadcastTime = *(_DWORD *)*v5;
    v16 = (int)((char *)*v5 + 4);
    v13 -= 4;
    *v5 = (void *)v16;
    addr = (void **)v13;
    if ( v13 >= 4 )
    {
      v4->m_monarchBroadcastsToday = *(_DWORD *)v16;
      v13 -= 4;
      v17 = (int)((char *)*v5 + 4);
      *v5 = (void *)v17;
      addr = (void **)v13;
      if ( v13 >= 4 )
      {
        v4->m_spokesBroadcastTime = *(_DWORD *)v17;
        v13 -= 4;
        v18 = (int)((char *)*v5 + 4);
        *v5 = (void *)v18;
        addr = (void **)v13;
        if ( v13 >= 4 )
        {
          v4->m_spokesBroadcastsToday = *(_DWORD *)v18;
          v13 -= 4;
          *v5 = (char *)*v5 + 4;
          addr = (void **)v13;
        }
      }
    }
  }
  if ( v4->m_oldVersion >= 3 )
  {
    if ( !AC1Legacy::PStringBase<char>::UnPack(&v4->m_motd, v5, v13) )
      return 0;
    v19 = (_BYTE *)*v5 - (_BYTE *)start;
    v20 = v3 <= v19 ? 0 : v3 - v19;
    if ( !AC1Legacy::PStringBase<char>::UnPack(&v4->m_motdSetBy, v5, v20) )
      return 0;
    v13 = PackObj::GET_SIZE_LEFT(*v5, start, v3);
    addr = (void **)v13;
  }
  if ( v4->m_oldVersion >= 4 )
  {
    PackObj::UNPACK_TYPE((int *)&v4->m_chatRoomID, v5, (unsigned int *)&addr);
    v13 = (unsigned int)addr;
  }
  if ( v4->m_oldVersion >= 7
    && !((int (__thiscall *)(int, void **, unsigned int))v4->m_BindPoint.vfptr->UnPack)(&v4->m_BindPoint, v5, v13) )
    return 0;
  if ( v4->m_oldVersion >= 8 )
  {
    if ( !AC1Legacy::PStringBase<char>::UnPack(&v4->m_AllegianceName, v5, v13) )
      return 0;
    addr = (void **)PackObj::GET_SIZE_LEFT(*v5, start, v3);
    PackObj::UNPACK_TYPE(&v4->m_NameLastSetTime, v5, (unsigned int *)&addr);
  }
  if ( v4->m_oldVersion >= 10 )
    PackObj::UNPACK_TYPE(&v4->m_isLocked, v5, (unsigned int *)&addr);
  if ( v4->m_oldVersion >= 11 )
    PackObj::UNPACK_TYPE((int *)&v4->m_ApprovedVassal, v5, (unsigned int *)&addr);
  v21 = 0;
  AllegianceData::AllegianceData(&data);
  v22 = 0;
  if ( packed_nodes <= 0 )
  {
LABEL_51:
    v26 = v4->m_pMonarch;
    if ( v26 )
      AllegianceData::SetMayPassupExperience(&v26->_data, 0);
    AllegianceData::~AllegianceData(&data);
    result = 1;
  }
  else
  {
    while ( 1 )
    {
      v23 = *v5;
      v24 = (_BYTE *)*v5 - (_BYTE *)start;
      if ( size <= v24 )
        v25 = 0;
      else
        v25 = size - v24;
      if ( v22 )
      {
        if ( v25 < 4 )
          break;
        v21 = *(_DWORD *)v23;
        *v5 = (char *)v23 + 4;
        v25 -= 4;
      }
      if ( !AllegianceData::UnPack(&data, v5, v25) || !AllegianceHierarchy::Add(v4, v21, &data) )
        break;
      ++v22;
      if ( v22 >= packed_nodes )
        goto LABEL_51;
    }
    AllegianceData::~AllegianceData(&data);
    result = 0;
  }
  return result;
}

//----- (005B77F0) --------------------------------------------------------  // acclient.c:482504
void __thiscall AllegianceHierarchy::AllegianceHierarchy(AllegianceHierarchy *this)
{
  AllegianceHierarchy *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1
  volatile LONG *v4; // ST00_4@1
  int v5; // ecx@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@1
  volatile LONG *v7; // ST00_4@5
  AC1Legacy::PSRefBuffer<char> *v8; // ebp@6
  volatile LONG *v9; // ST00_4@10
  AC1Legacy::PSRefBuffer<char> *v10; // ebp@11
  volatile LONG *v11; // ST00_4@15

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AllegianceHierarchy::vftable;
  this->m_oldVersion = 0;
  this->m_pMonarch = 0;
  this->m_total = 0;
  this->m_monarchBroadcastTime = 0;
  this->m_spokesBroadcastTime = 0;
  this->m_monarchBroadcastsToday = 0;
  this->m_spokesBroadcastsToday = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->m_motd.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->m_motdSetBy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v3);
  v4 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  v1->m_AllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v4);
  v1->m_NameLastSetTime = 0;
  v1->m_chatRoomID = 0;
  v1->m_AllegianceOfficers.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>(
    &v1->m_AllegianceOfficers.m_intrusiveTable,
    0x17u);
  v1->m_AllegianceOfficers.vfptr = (PackObjVtbl *)&StreamPackObj::vftable;
  v1->m_AllegianceOfficers.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)PHashTable<unsigned long,unsigned long>::vftable;
  v1->m_AllegianceOfficers.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned long>::vftable;
  v1->m_OfficerTitles.m_data = 0;
  v1->m_OfficerTitles.m_size = 0;
  v1->m_OfficerTitles.m_num = 0;
  v1->m_OfficerTitles.vfptr = (PackObjVtbl *)&PSmartArray<AC1Legacy::PStringBase<char>>::vftable;
  v5 = (int)&v1->m_BindPoint.frame;
  v1->m_BindPoint.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->m_BindPoint.objcell_id = 0;
  *(_DWORD *)v5 = 1065353216;
  *(_DWORD *)(v5 + 4) = 0;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_DWORD *)(v5 + 52) = 0;
  *(_DWORD *)(v5 + 56) = 0;
  *(_DWORD *)(v5 + 60) = 0;
  Frame::cache(&v1->m_BindPoint.frame);
  v1->m_isLocked = 0;
  v1->m_ApprovedVassal = 0;
  v6 = v1->m_motd.m_buffer;
  if ( v6 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    v7 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_motd.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v7);
  }
  v8 = v1->m_motdSetBy.m_buffer;
  if ( v8 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
      v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
    v9 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_motdSetBy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v9);
  }
  v10 = v1->m_AllegianceName.m_buffer;
  if ( v10 != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v10->m_cRef) )
    {
      if ( v10 )
        v10->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v10, 1u);
    }
    v11 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
    v1->m_AllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement(v11);
  }
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7C9DC0: using guessed type int (__thiscall *StreamPackObj::vftable)(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;
// 7E61AC: using guessed type int (__thiscall *PHashTable<unsigned long,unsigned long>::vftable[2])(void *, char);
// 7E6D88: using guessed type int (__thiscall *PSmartArray<AC1Legacy::PStringBase<char>>::vftable)(void *, char);
// 7E6DA0: using guessed type int (__thiscall *AllegianceHierarchy::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005B7990) --------------------------------------------------------  // acclient.c:482603
AllegianceHierarchy *__thiscall AllegianceHierarchy::operator=(AllegianceHierarchy *this, int a2)
{
  AllegianceHierarchy *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // ebx@2
  int v4; // eax@6
  AC1Legacy::PSRefBuffer<char> *v5; // ebx@7
  int v6; // eax@11
  int v7; // eax@13
  AC1Legacy::PSRefBuffer<char> *v8; // ebx@15
  int v9; // eax@19

  v2 = this;
  if ( this != (AllegianceHierarchy *)a2 )
  {
    AllegianceHierarchy::Clear(this);
    v2->m_monarchBroadcastTime = *(_DWORD *)(a2 + 16);
    v2->m_spokesBroadcastTime = *(_DWORD *)(a2 + 20);
    v2->m_monarchBroadcastsToday = *(_DWORD *)(a2 + 24);
    v2->m_spokesBroadcastsToday = *(_DWORD *)(a2 + 28);
    v3 = v2->m_motd.m_buffer;
    if ( v3 != *(AC1Legacy::PSRefBuffer<char> **)(a2 + 32) )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
      v4 = *(_DWORD *)(a2 + 32);
      v2->m_motd.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v4;
      InterlockedIncrement((volatile LONG *)(v4 + 4));
    }
    v5 = v2->m_motdSetBy.m_buffer;
    if ( v5 != *(AC1Legacy::PSRefBuffer<char> **)(a2 + 36) )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
        v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
      v6 = *(_DWORD *)(a2 + 36);
      v2->m_motdSetBy.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v6;
      InterlockedIncrement((volatile LONG *)(v6 + 4));
    }
    v2->m_chatRoomID = *(_DWORD *)(a2 + 48);
    HashTable<unsigned long,unsigned long,0>::operator=((int)&v2->m_AllegianceOfficers, a2 + 52);
    if ( a2 == -172 )
      v7 = 0;
    else
      v7 = a2 + 176;
    AC1Legacy::SmartArray<AC1Legacy::PStringBase<char>>::operator=(
      (AC1Legacy::SmartArray<AC1Legacy::PStringBase<char> > *)&v2->m_OfficerTitles.m_data,
      v7);
    v8 = v2->m_AllegianceName.m_buffer;
    if ( v8 != *(AC1Legacy::PSRefBuffer<char> **)(a2 + 40) )
    {
      if ( !InterlockedDecrement((volatile LONG *)&v8->m_cRef) && v8 )
        v8->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v8, 1u);
      v9 = *(_DWORD *)(a2 + 40);
      v2->m_AllegianceName.m_buffer = (AC1Legacy::PSRefBuffer<char> *)v9;
      InterlockedIncrement((volatile LONG *)(v9 + 4));
    }
    v2->m_NameLastSetTime = *(_DWORD *)(a2 + 44);
    v2->m_isLocked = *(_DWORD *)(a2 + 260);
    v2->m_ApprovedVassal = *(_DWORD *)(a2 + 264);
    AllegianceHierarchy::Copy(v2, *(AllegianceNode **)(a2 + 8), 1);
  }
  return v2;
}

//----- (005B7AC0) --------------------------------------------------------  // acclient.c:482667
void __thiscall AllegianceHierarchy::~AllegianceHierarchy(AllegianceHierarchy *this)
{
  AllegianceHierarchy *v1; // esi@1
  AC1Legacy::PStringBase<char> *v2; // ecx@1
  void *v3; // eax@3
  AC1Legacy::PSRefBuffer<char> *v4; // edi@5
  AC1Legacy::PSRefBuffer<char> *v5; // edi@8
  AC1Legacy::PSRefBuffer<char> *v6; // edi@11

  v1 = this;
  this->vfptr = (PackObjVtbl *)&AllegianceHierarchy::vftable;
  AllegianceHierarchy::Clear(this);
  v1->m_BindPoint.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_OfficerTitles.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v2 = v1->m_OfficerTitles.m_data;
  if ( v2 )
    AC1Legacy::PStringBase<char>::vector_deleting_destructor(v2, 3u);
  v1->m_AllegianceOfficers.vfptr = (PackObjVtbl *)&PHashTable<unsigned long,unsigned long>::vftable;
  v1->m_AllegianceOfficers.vfptr = (PackObjVtbl *)&PackObj::vftable;
  v1->m_AllegianceOfficers.vfptr = (HashTable<unsigned long,unsigned long,0>Vtbl *)HashTable<unsigned long,unsigned long,0>::vftable;
  IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::delete_contents((IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> *)&v1->m_AllegianceOfficers.m_intrusiveTable);
  v3 = v1->m_AllegianceOfficers.m_intrusiveTable.m_buckets;
  v1->m_AllegianceOfficers.m_intrusiveTable.vfptr = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>Vtbl *)IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable;
  if ( v3 != v1->m_AllegianceOfficers.m_intrusiveTable.m_aInplaceBuckets )
    operator delete[](v3);
  v1->m_AllegianceOfficers.m_intrusiveTable.m_buckets = 0;
  v1->m_AllegianceOfficers.m_intrusiveTable.m_firstInterestingBucket = 0;
  v1->m_AllegianceOfficers.m_intrusiveTable.m_numBuckets = 0;
  v1->m_AllegianceOfficers.m_intrusiveTable.m_numElements = 0;
  v4 = v1->m_AllegianceName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v5 = v1->m_motdSetBy.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v5->m_cRef) && v5 )
    v5->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v5, 1u);
  v6 = v1->m_motd.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 79C9A8: using guessed type int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char);
// 79C9AC: using guessed type int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char);
// 7E6194: using guessed type void *PHashTable<unsigned long,unsigned long>::vftable;
// 7E6DA0: using guessed type int (__thiscall *AllegianceHierarchy::vftable)(void *, char);

//----- (005B7BA0) --------------------------------------------------------  // acclient.c:482714
AllegianceHierarchy *__thiscall AllegianceHierarchy::scalar_deleting_destructor(AllegianceHierarchy *this, unsigned int a2)
{
  AllegianceHierarchy *v2; // esi@1

  v2 = this;
  AllegianceHierarchy::~AllegianceHierarchy(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (0070E6F0) --------------------------------------------------------  // acclient.c:801441
void sub_70E6F0()
{
  flt_8EF408 = 1000.0 + 1.0;
}

//----- (0070E710) --------------------------------------------------------  // acclient.c:801447
void sub_70E710()
{
  flt_8EF40C = 24.0 * 8.0;
}

//----- (0070E730) --------------------------------------------------------  // acclient.c:801453
void sub_70E730()
{
  flt_8EF410 = 24.0 * 0.5;
}

//----- (0070E750) --------------------------------------------------------  // acclient.c:801459
int sub_70E750()
{
  return atexit(nullsub_1552);
}

