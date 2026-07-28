/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CSpellBook
   Object     : AC\accqualities\CSpellBook.obj
   Functions  : 18
   Addresses  : 005954A0 - 00595C10 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005954A0) --------------------------------------------------------  // acclient.c:446895
PackableHashIterator<unsigned long,SpellBookPage> *__thiscall PackableHashIterator<unsigned long,SpellBookPage>::scalar_deleting_destructor(PackableHashIterator<unsigned long,SpellBookPage> *this, unsigned int a2)
{
  PackableHashIterator<unsigned long,SpellBookPage> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackableHashIterator<unsigned long,SpellBookPage>Vtbl *)PackableHashIterator<unsigned long,SpellBookPage>::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7E4704: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SpellBookPage>::vftable[2])(void *, char);

//----- (005954C0) --------------------------------------------------------  // acclient.c:446908
PackableHashIterator<unsigned long,SpellBookPage> *__thiscall PackableHashTable<unsigned long,SpellBookPage>::begin(PackableHashTable<unsigned long,SpellBookPage> *this, PackableHashIterator<unsigned long,SpellBookPage> *result)
{
  unsigned int v2; // edx@1
  unsigned int v3; // eax@1
  PackableHashData<unsigned long,SpellBookPage> **v4; // edi@2
  PackableHashData<unsigned long,SpellBookPage> **v5; // esi@2
  PackableHashData<unsigned long,SpellBookPage> **v6; // ecx@5
  PackableHashIterator<unsigned long,SpellBookPage> *v7; // eax@5
  PackableHashData<unsigned long,SpellBookPage> *v8; // ecx@6

  v2 = this->_table_size;
  v3 = 0;
  if ( v2 )
  {
    v4 = this->_buckets;
    v5 = this->_buckets;
    while ( !*v5 )
    {
      ++v3;
      ++v5;
      if ( v3 >= v2 )
        goto LABEL_5;
    }
    v8 = v4[v3];
    v7 = result;
    result->_buckets = v4;
    result->_current = v8;
    result->vfptr = (PackableHashIterator<unsigned long,SpellBookPage>Vtbl *)PackableHashIterator<unsigned long,SpellBookPage>::vftable;
    result->_table_size = v2;
  }
  else
  {
LABEL_5:
    v6 = this->_buckets;
    v7 = result;
    result->_current = 0;
    result->_buckets = v6;
    result->vfptr = (PackableHashIterator<unsigned long,SpellBookPage>Vtbl *)PackableHashIterator<unsigned long,SpellBookPage>::vftable;
    result->_table_size = v2;
  }
  return v7;
}
// 7E4704: using guessed type int (__thiscall *PackableHashIterator<unsigned long,SpellBookPage>::vftable[2])(void *, char);

//----- (00595520) --------------------------------------------------------  // acclient.c:446953
int __thiscall CSpellBook::Exists(CSpellBook *this, const unsigned int newSpell)
{
  unsigned int v2; // esi@1
  PackableHashData<unsigned long,SpellBookPage> **v3; // ecx@2
  PackableHashData<unsigned long,SpellBookPage> *v4; // edx@3
  int result; // eax@6

  v2 = this->_spellbook._table_size;
  if ( v2 && (v3 = this->_spellbook._buckets) != 0 && (v4 = v3[newSpell % v2]) != 0 )
  {
    while ( newSpell != v4->_key )
    {
      v4 = v4->_next;
      if ( !v4 )
        goto LABEL_6;
    }
    result = &v4->_data != 0;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (00595570) --------------------------------------------------------  // acclient.c:446980
int __thiscall CSpellBook::TranscribeSpells(CSpellBook *this, PackableList<unsigned long> *list)
{
  PackableHashData<unsigned long,SpellBookPage> **v2; // ebp@1
  PackableHashData<unsigned long,SpellBookPage> *v3; // esi@1
  void *v4; // eax@3
  PackableLLNode<unsigned long> *v5; // ecx@6
  unsigned int v6; // edx@9
  unsigned int v7; // eax@11
  PackableHashIterator<unsigned long,SpellBookPage> iter; // [sp+10h] [bp-10h]@1

  PackableHashTable<unsigned long,SpellBookPage>::begin(&this->_spellbook, &iter);
  v2 = iter._buckets;
  v3 = iter._current;
  while ( v3 )
  {
    v4 = operator new(0xCu);
    if ( v4 )
    {
      *(_DWORD *)v4 = v3->_key;
      *((_DWORD *)v4 + 1) = 0;
      *((_DWORD *)v4 + 2) = 0;
    }
    else
    {
      v4 = 0;
    }
    v5 = list->head;
    if ( v5 )
    {
      v5->prev = (PackableLLNode<unsigned long> *)v4;
      *((_DWORD *)v4 + 1) = v5;
    }
    else
    {
      list->tail = (PackableLLNode<unsigned long> *)v4;
    }
    v6 = list->curNum + 1;
    list->head = (PackableLLNode<unsigned long> *)v4;
    list->curNum = v6;
    if ( v3->_next )
    {
      v3 = v3->_next;
    }
    else
    {
      v7 = v3->_hashVal + 1;
      if ( v7 >= iter._table_size )
      {
LABEL_14:
        v3 = 0;
      }
      else
      {
        while ( !v2[v7] )
        {
          ++v7;
          if ( v7 >= iter._table_size )
            goto LABEL_14;
        }
        v3 = v2[v7];
      }
    }
  }
  return 1;
}

//----- (00595610) --------------------------------------------------------  // acclient.c:447047
signed int __thiscall PackableHashTable<unsigned long,SpellBookPage>::Pack(PackableHashTable<unsigned long,SpellBookPage> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,SpellBookPage> *v3; // ebp@1
  signed int result; // eax@1
  unsigned int v5; // ebx@1
  unsigned int v6; // ecx@2
  PackableHashData<unsigned long,SpellBookPage> *v7; // esi@3
  unsigned int retVal; // [sp+8h] [bp-4h]@1
  unsigned int sizea; // [sp+14h] [bp+8h]@2

  v3 = this;
  result = PackableHashTable<unsigned long,SpellBookPage>::pack_size(this);
  v5 = size;
  retVal = result;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_currNum | (v3->_table_size << 16);
    *addr = (char *)*addr + 4;
    v6 = 0;
    sizea = 0;
    if ( v3->_table_size )
    {
      do
      {
        v7 = v3->_buckets[v6];
        if ( v7 )
        {
          do
          {
            if ( v5 >= 4 )
            {
              *(_DWORD *)*addr = v7->_key;
              *addr = (char *)*addr + 4;
            }
            ((void (__thiscall *)(int, void **, unsigned int))v7->_data.vfptr->Pack)(&v7->_data, addr, v5);
            v7 = v7->_next;
          }
          while ( v7 );
          result = retVal;
          v6 = sizea;
        }
        ++v6;
        sizea = v6;
      }
      while ( v6 < v3->_table_size );
    }
  }
  return result;
}

//----- (005956A0) --------------------------------------------------------  // acclient.c:447098
signed int __thiscall PackableHashTable<unsigned long,SpellBookPage>::pack_size(PackableHashTable<unsigned long,SpellBookPage> *this)
{
  PackableHashTable<unsigned long,SpellBookPage> *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // ebx@1
  signed int v4; // edi@1
  PackableHashData<unsigned long,SpellBookPage> *i; // esi@2
  int v6; // eax@3
  void *addr; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = this->_table_size;
  v3 = 0;
  v4 = 4;
  addr = 0;
  if ( v2 )
  {
    do
    {
      for ( i = v1->_buckets[v3]; i; v4 += v6 + 4 )
      {
        v6 = ((int (__thiscall *)(int, void **, _DWORD))i->_data.vfptr->Pack)(&i->_data, &addr, 0);
        i = i->_next;
      }
      ++v3;
    }
    while ( v3 < v1->_table_size );
  }
  return v4;
}

//----- (00595700) --------------------------------------------------------  // acclient.c:447130
void __thiscall PackableHashTable<unsigned long,SpellBookPage>::EmptyContents(PackableHashTable<unsigned long,SpellBookPage> *this)
{
  PackableHashTable<unsigned long,SpellBookPage> *v1; // edi@1
  unsigned int v2; // ebx@2
  PackableHashData<unsigned long,SpellBookPage> *v3; // eax@3
  PackableHashData<unsigned long,SpellBookPage> *v4; // esi@4

  v1 = this;
  if ( this->_buckets )
  {
    v2 = 0;
    if ( this->_table_size )
    {
      do
      {
        v3 = v1->_buckets[v2];
        if ( v3 )
        {
          do
          {
            v4 = v3->_next;
            v3->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
            operator delete(v3);
            v3 = v4;
          }
          while ( v4 );
        }
        v1->_buckets[v2++] = 0;
      }
      while ( v2 < v1->_table_size );
    }
  }
  v1->_currNum = 0;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00595760) --------------------------------------------------------  // acclient.c:447167
int __thiscall PackableHashTable<unsigned long,SpellBookPage>::add(PackableHashTable<unsigned long,SpellBookPage> *this, const unsigned int *key, SpellBookPage *data)
{
  PackableHashTable<unsigned long,SpellBookPage> *v3; // esi@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,SpellBookPage> **v5; // ebx@2
  PackableHashData<unsigned long,SpellBookPage> *v6; // edx@3
  void *v7; // eax@8
  unsigned int v8; // edi@9
  const unsigned int v9; // edx@9

  v3 = this;
  v4 = this->_table_size;
  if ( !v4 )
    goto LABEL_8;
  v5 = this->_buckets;
  if ( !v5 )
    goto LABEL_8;
  v6 = v5[*key % v4];
  if ( !v6 )
    goto LABEL_8;
  while ( *key != v6->_key )
  {
    v6 = v6->_next;
    if ( !v6 )
      goto LABEL_8;
  }
  if ( v6 == (PackableHashData<unsigned long,SpellBookPage> *)-4 )
  {
LABEL_8:
    v7 = operator new(0x14u);
    if ( v7 )
    {
      v8 = v3->_table_size;
      *(_DWORD *)v7 = *key;
      *((_DWORD *)v7 + 1) = &SpellBookPage::vftable;
      *((_DWORD *)v7 + 2) = LODWORD(data->_casting_likelihood);
      *((_DWORD *)v7 + 3) = 0;
      v9 = *key % v8;
      *((_DWORD *)v7 + 4) = v9;
      *((_DWORD *)v7 + 3) = v3->_buckets[v9];
      v3->_buckets[v9] = (PackableHashData<unsigned long,SpellBookPage> *)v7;
      ++v3->_currNum;
      return 1;
    }
  }
  return 0;
}
// 7E4394: using guessed type int (__thiscall *SpellBookPage::vftable)(void *, char);

//----- (00595800) --------------------------------------------------------  // acclient.c:447217
int __thiscall PackableHashTable<unsigned long,SpellBookPage>::remove(PackableHashTable<unsigned long,SpellBookPage> *this, const unsigned int *key, SpellBookPage *retval)
{
  PackableHashTable<unsigned long,SpellBookPage> *v3; // ebx@1
  unsigned int v4; // edi@1
  PackableHashData<unsigned long,SpellBookPage> **v5; // ecx@2
  PackableHashData<unsigned long,SpellBookPage> *v6; // eax@3
  PackableHashData<unsigned long,SpellBookPage> *v7; // ecx@3
  int result; // eax@6

  v3 = this;
  v4 = this->_table_size;
  if ( v4 && (v5 = this->_buckets) != 0 && (v6 = 0, (v7 = v5[*key % v4]) != 0) )
  {
    while ( v7->_key != *key )
    {
      v6 = v7;
      v7 = v7->_next;
      if ( !v7 )
        goto LABEL_6;
    }
    retval->_casting_likelihood = v7->_data._casting_likelihood;
    if ( v6 )
      v6->_next = v7->_next;
    else
      v3->_buckets[*key % v3->_table_size] = v7->_next;
    v7->_data.vfptr = (PackObjVtbl *)&PackObj::vftable;
    operator delete(v7);
    --v3->_currNum;
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (00595890) --------------------------------------------------------  // acclient.c:447257
int __thiscall CSpellBook::AddSpell(CSpellBook *this, const unsigned int newSpell, SpellBookPage *page)
{
  int result; // eax@2

  if ( newSpell )
    result = PackableHashTable<unsigned long,SpellBookPage>::add(&this->_spellbook, &newSpell, page);
  else
    result = 0;
  return result;
}

//----- (005958C0) --------------------------------------------------------  // acclient.c:447269
int __thiscall CSpellBook::RemoveSpell(CSpellBook *this, const unsigned int newSpell, SpellBookPage *page)
{
  return PackableHashTable<unsigned long,SpellBookPage>::remove(&this->_spellbook, &newSpell, page);
}

//----- (005958E0) --------------------------------------------------------  // acclient.c:447275
void __thiscall CSpellBook::Prune(CSpellBook *this)
{
  PackableHashTable<unsigned long,SpellBookPage> *v1; // esi@1
  PackableHashData<unsigned long,SpellBookPage> *v2; // ebx@1
  PackableHashData<unsigned long,SpellBookPage> **v3; // ebp@2
  PackableHashData<unsigned long,SpellBookPage> *v4; // eax@4
  unsigned int v5; // ecx@4
  unsigned int v6; // eax@5
  PackableHashTable<unsigned long,SpellBookPage> *v7; // [sp+10h] [bp-30h]@1
  unsigned int id; // [sp+14h] [bp-2Ch]@4
  SpellBookPage retval; // [sp+18h] [bp-28h]@12
  PackableHashIterator<unsigned long,SpellBookPage> iter; // [sp+20h] [bp-20h]@1
  char buff[16]; // [sp+30h] [bp-10h]@11

  v1 = &this->_spellbook;
  v7 = &this->_spellbook;
  PackableHashTable<unsigned long,SpellBookPage>::begin(&this->_spellbook, &iter);
  v2 = iter._current;
  if ( iter._current )
  {
    v3 = iter._buckets;
    while ( 1 )
    {
      v4 = v2->_next;
      v5 = v2->_key;
      id = v2->_key;
      if ( !v4 )
      {
        v6 = v2->_hashVal + 1;
        if ( v6 >= iter._table_size )
        {
LABEL_8:
          v4 = 0;
        }
        else
        {
          while ( !v3[v6] )
          {
            ++v6;
            if ( v6 >= iter._table_size )
              goto LABEL_8;
          }
          v4 = v3[v6];
        }
      }
      v2 = v4;
      if ( v5 && v5 < 0x2000 )
      {
        UIObject::DynamicCast_UIViewportObject();
        if ( !memcmp(buff, "Unknown", 8u) )
          PackableHashTable<unsigned long,SpellBookPage>::remove(v7, &id, &retval);
      }
      else
      {
        PackableHashTable<unsigned long,SpellBookPage>::remove(v1, &id, &retval);
      }
      if ( !v2 )
        break;
      v1 = v7;
    }
  }
}

//----- (005959B0) --------------------------------------------------------  // acclient.c:447339
void __thiscall PackableHashTable<unsigned long,SpellBookPage>::~PackableHashTable<unsigned long,SpellBookPage>(PackableHashTable<unsigned long,SpellBookPage> *this)
{
  PackableHashTable<unsigned long,SpellBookPage> *v1; // esi@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellBookPage>::vftable;
  PackableHashTable<unsigned long,SpellBookPage>::EmptyContents(this);
  if ( v1->_buckets )
  {
    operator delete[](v1->_buckets);
    v1->_buckets = 0;
  }
  v1->_table_size = 0;
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4708: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellBookPage>::vftable)(void *, char);

//----- (005959F0) --------------------------------------------------------  // acclient.c:447358
int __thiscall PackableHashTable<unsigned long,SpellBookPage>::UnPack(PackableHashTable<unsigned long,SpellBookPage> *this, void **addr, unsigned int size)
{
  PackableHashTable<unsigned long,SpellBookPage> *v3; // edi@1
  int result; // eax@2
  unsigned int v5; // eax@5
  unsigned int v6; // ecx@5
  unsigned int v7; // eax@5
  unsigned int v8; // ebx@5
  unsigned int v9; // edx@12
  unsigned int i; // [sp+Ch] [bp-1Ch]@10
  unsigned int toUnPack; // [sp+10h] [bp-18h]@5
  unsigned int tempKey; // [sp+14h] [bp-14h]@12
  void *start_addr; // [sp+18h] [bp-10h]@3
  unsigned int blob_size; // [sp+1Ch] [bp-Ch]@3
  SpellBookPage tempData; // [sp+20h] [bp-8h]@10

  v3 = this;
  if ( size < 4 )
    return 0;
  start_addr = *addr;
  blob_size = size;
  PackableHashTable<unsigned long,SpellBookPage>::EmptyContents(this);
  if ( v3->_buckets )
  {
    operator delete[](v3->_buckets);
    v3->_buckets = 0;
  }
  v3->_table_size = 0;
  v5 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v6 = v5 >> 16;
  v7 = (unsigned __int16)v5;
  v8 = size - 4;
  v3->_table_size = v6;
  toUnPack = v7;
  if ( v6 )
  {
    if ( v6 > 0x10000
      || v7 > 0x10000
      || !PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v3) )
      return 0;
    tempData.vfptr = (PackObjVtbl *)&SpellBookPage::vftable;
    LODWORD(tempData._casting_likelihood) = 0;
    i = 0;
    if ( toUnPack )
    {
      while ( v8 >= 4 )
      {
        v9 = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        tempKey = v9;
        if ( !((int (__thiscall *)(SpellBookPage *, void **, unsigned int))tempData.vfptr->UnPack)(&tempData, addr, v8)
          || !PackableHashTable<unsigned long,SpellBookPage>::add(v3, &tempKey, &tempData)
          && !v3->m_fThrowawayDuplicateKeysOnUnPack )
          break;
        ++i;
        if ( i >= toUnPack )
          goto LABEL_16;
      }
      return 0;
    }
LABEL_16:
    result = blob_size >= (_BYTE *)*addr - (_BYTE *)start_addr;
  }
  else
  {
    result = v7 == 0;
  }
  return result;
}
// 7E4394: using guessed type int (__thiscall *SpellBookPage::vftable)(void *, char);

//----- (00595B30) --------------------------------------------------------  // acclient.c:447431
PackableHashTable<unsigned long,SpellBookPage> *__thiscall PackableHashTable<unsigned long,SpellBookPage>::vector_deleting_destructor(PackableHashTable<unsigned long,SpellBookPage> *this, unsigned int a2)
{
  PackableHashTable<unsigned long,SpellBookPage> *v2; // esi@1

  v2 = this;
  this->vfptr = (PackObjVtbl *)&PackableHashTable<unsigned long,SpellBookPage>::vftable;
  PackableHashTable<unsigned long,SpellBookPage>::EmptyContents(this);
  if ( v2->_buckets )
  {
    operator delete[](v2->_buckets);
    v2->_buckets = 0;
  }
  v2->_table_size = 0;
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E4708: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellBookPage>::vftable)(void *, char);

//----- (00595B80) --------------------------------------------------------  // acclient.c:447453
void __thiscall CSpellBook::CSpellBook(CSpellBook *this)
{
  CSpellBook *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->_spellbook;
  v1->vfptr = (PackObjVtbl *)&CSpellBook::vftable;
  *(_DWORD *)v2 = &PackableHashTable<unsigned long,SpellBookPage>::vftable;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 64;
  *((_DWORD *)v2 + 4) = 0;
  PackableHashTable<unsigned long,CContractTracker>::Init((PackableHashTable<IDClass<_tagDataID,32,0>,long> *)v2);
}
// 7E4708: using guessed type int (__thiscall *PackableHashTable<unsigned long,SpellBookPage>::vftable)(void *, char);
// 7E471C: using guessed type int (__thiscall *CSpellBook::vftable)(void *, char);

//----- (00595BB0) --------------------------------------------------------  // acclient.c:447472
int __thiscall CSpellBook::UnPack(CSpellBook *this, void **addr, unsigned int size)
{
  CSpellBook *v3; // edi@1
  char *v4; // esi@1
  int v5; // eax@1
  int result; // eax@2
  int v7; // esi@3
  CSpellBook *v8; // [sp+0h] [bp-4h]@1

  v8 = this;
  v3 = this;
  v4 = (char *)&this->_spellbook;
  PackableHashTable<unsigned long,SpellBookPage>::EmptyContents(&this->_spellbook);
  v5 = *(_DWORD *)v4;
  v8 = 0;
  if ( size >= (*(int (__thiscall **)(char *, int *, _DWORD))(v5 + 12))(v4, &v8, 0) )
  {
    v7 = (*(int (__thiscall **)(char *, void **, unsigned int))(*(_DWORD *)v4 + 16))(v4, addr, size);
    CSpellBook::Prune(v3);
    result = v7;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00595C10) --------------------------------------------------------  // acclient.c:447501
CSpellBook *__thiscall CSpellBook::scalar_deleting_destructor(CSpellBook *this, unsigned int a2)
{
  CSpellBook *v2; // esi@1

  v2 = this;
  PackableHashTable<unsigned long,SpellBookPage>::~PackableHashTable<unsigned long,SpellBookPage>(&this->_spellbook);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

