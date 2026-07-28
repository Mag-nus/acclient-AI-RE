/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StructPropertyValue
   Object     : ENGINE\property\StructPropertyValue.obj
   Functions  : 6
   Addresses  : 0042BE40 - 0042C0C0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042BE40) --------------------------------------------------------  // acclient.c:104950
char __thiscall StructPropertyValue::ToFileNode(StructPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v3; // eax@2
  HashTableData<unsigned long,HeritageGroup_CG> *v4; // esi@2
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // ebx@2
  HashTableData<unsigned long,HeritageGroup_CG> **v6; // edi@2
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+10h] [bp-Ch]@2

  if ( _node )
  {
    v3 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
           (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&this->m_value.m_intrusiveTable,
           &result);
    v4 = v3->m_currElement;
    v5 = v3->m_currHashTable;
    v6 = v3->m_currBucket;
    if ( !v4 )
      return 1;
LABEL_3:
    while ( BaseProperty::ToFileNode((BaseProperty *)&v4->m_data, _node) )
    {
      v4 = v4->m_hashNext;
      if ( !v4 )
      {
        while ( 1 )
        {
          ++v6;
          if ( v6 == &v5->m_buckets[v5->m_numBuckets] )
            return 1;
          if ( *v6 )
          {
            v4 = *v6;
            if ( *v6 )
              goto LABEL_3;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

//----- (0042BEC0) --------------------------------------------------------  // acclient.c:104994
char __thiscall StructPropertyValue::GetValueAsString(StructPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  char result; // al@2

  if ( rawValue )
  {
    PStringBase<char>::sprintf(_value, "%d", this->m_value.m_intrusiveTable.m_numElements);
    result = 1;
  }
  else
  {
    PStringBase<char>::sprintf(_value, "Struct [%d items]", this->m_value.m_intrusiveTable.m_numElements);
    result = 1;
  }
  return result;
}

//----- (0042BF00) --------------------------------------------------------  // acclient.c:105012
char __thiscall StructPropertyValue::Compare(StructPropertyValue *this, BasePropertyValue *_p)
{
  StructPropertyValue *v2; // esi@1
  int v3; // eax@1
  int v4; // edi@1
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *v5; // eax@3
  HashTableData<unsigned long,BaseProperty> *v6; // esi@3
  HashTableData<unsigned long,BaseProperty> **v7; // edx@3
  int v8; // eax@4
  BaseProperty *v10; // eax@9
  HashIterator<unsigned long,BaseProperty,1> cur; // [sp+8h] [bp-18h]@3
  IntrusiveHashIterator<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> result; // [sp+14h] [bp-Ch]@3

  v2 = this;
  v3 = ((int (*)(void))_p->vfptr[74].__vecDelDtor)();
  v4 = v3;
  if ( !v3 || v2->m_value.m_intrusiveTable.m_numElements != *(_DWORD *)(v3 + 112) )
    return 0;
  v5 = IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::begin(
         (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> *)&v2->m_value.m_intrusiveTable,
         &result);
  v6 = (HashTableData<unsigned long,BaseProperty> *)v5->m_currElement;
  v7 = (HashTableData<unsigned long,BaseProperty> **)v5->m_currBucket;
  cur.m_iter.m_currHashTable = (IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *)v5->m_currHashTable;
  cur.m_iter.m_currBucket = v7;
  cur.m_iter.m_currElement = v6;
  if ( v6 )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(v4 + 100) + 4 * (v6->m_hashKey % *(_DWORD *)(v4 + 108)));
      if ( !v8 )
        break;
      while ( *(_DWORD *)v8 != v6->m_hashKey )
      {
        v8 = *(_DWORD *)(v8 + 4);
        if ( !v8 )
          return 0;
      }
      if ( !v8 )
        break;
      v10 = (BaseProperty *)(v8 + 8);
      if ( !v10 || !BaseProperty::Compare(&v6->m_data, v10) )
        break;
      HashSetIterator<UIListener *>::operator++((HashIterator<unsigned long,unsigned long,0> *)&cur);
      v6 = cur.m_iter.m_currElement;
      if ( !cur.m_iter.m_currElement )
        return 1;
    }
    return 0;
  }
  return 1;
}

//----- (0042BFB0) --------------------------------------------------------  // acclient.c:105067
char __thiscall IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::add(IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *this, HashTableData<unsigned long,BaseProperty> *data)
{
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1> *v2; // esi@1
  unsigned int v3; // edi@1
  HashTableData<unsigned long,BaseProperty> *v4; // eax@1
  unsigned int v5; // edx@6
  HashTableData<unsigned long,BaseProperty> **v6; // eax@6
  int v7; // eax@6
  char result; // al@8

  v2 = this;
  v3 = this->m_numBuckets;
  v4 = this->m_buckets[data->m_hashKey % v3];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->m_hashKey != data->m_hashKey )
  {
    v4 = v4->m_hashNext;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 )
  {
    result = 0;
  }
  else
  {
LABEL_4:
    if ( (signed int)(2 * v3) < (signed int)(this->m_numElements + 1) )
      IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::grow(this);
    v5 = data->m_hashKey % v2->m_numBuckets;
    v6 = v2->m_buckets;
    data->m_hashNext = v6[v5];
    v6[v5] = data;
    v7 = (int)&v6[v5];
    if ( (HashTableData<unsigned long,BaseProperty> **)v7 < v2->m_firstInterestingBucket )
      v2->m_firstInterestingBucket = (HashTableData<unsigned long,BaseProperty> **)v7;
    ++v2->m_numElements;
    result = 1;
  }
  return result;
}

//----- (0042C030) --------------------------------------------------------  // acclient.c:105111
char __thiscall HashTable<unsigned long,BaseProperty,1>::add(HashTable<unsigned long,BaseProperty,1> *this, const unsigned int *_key, BaseProperty *_data)
{
  HashTable<unsigned long,BaseProperty,1> *v3; // edi@1
  void *v4; // esi@1
  int v5; // ecx@2
  int v6; // ecx@6
  bool v7; // zf@7
  int v8; // ecx@10
  char result; // al@15

  v3 = this;
  v4 = operator new(0x10u);
  if ( v4 )
  {
    *(_DWORD *)v4 = *_key;
    v5 = (int)((char *)v4 + 8);
    *((_DWORD *)v4 + 1) = 0;
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    BaseProperty::operator=((char *)v4 + 8, (int)_data);
  }
  else
  {
    v4 = 0;
  }
  if ( IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::add(
         &v3->m_intrusiveTable,
         (HashTableData<unsigned long,BaseProperty> *)v4) )
  {
    result = 1;
  }
  else
  {
    if ( v4 )
    {
      v6 = *((_DWORD *)v4 + 2);
      if ( v6 )
      {
        v7 = (*(_DWORD *)(v6 + 4))-- == 1;
        if ( v7 )
          (**(void (__stdcall ***)(_DWORD))v6)(1);
        *((_DWORD *)v4 + 2) = 0;
      }
      v8 = *((_DWORD *)v4 + 3);
      if ( v8 )
      {
        v7 = (*(_DWORD *)(v8 + 4))-- == 1;
        if ( v7 )
          (**(void (__stdcall ***)(_DWORD))v8)(1);
        *((_DWORD *)v4 + 3) = 0;
      }
      operator delete(v4);
    }
    result = 0;
  }
  return result;
}

//----- (0042C0C0) --------------------------------------------------------  // acclient.c:105170
bool __thiscall StructPropertyValue::FromFileNode(StructPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  PFileNode *v3; // esi@1
  unsigned int v4; // eax@6
  int v5; // edi@6
  unsigned int v6; // ebx@6
  PStringBase<char> *v7; // ebp@6
  ReferenceCountTemplate<1048576,0>Vtbl *v8; // eax@7
  PFileNode *v9; // eax@7
  PStringBase<char> *v10; // ecx@7
  unsigned int v11; // eax@11
  unsigned int v12; // eax@13
  PSRefBufferCharData<char> *v13; // ecx@13
  char *v14; // esi@13
  int v15; // edx@15
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> *v16; // ecx@18
  HashTableData<unsigned long,AvailableProperty> *v17; // edx@18
  IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>Vtbl *v18; // edx@19
  HashTableData<unsigned long,AvailableProperty> **v19; // ecx@22
  int v20; // edx@22
  HashTableData<unsigned long,AvailableProperty> *v21; // eax@23
  HashTable<unsigned long,StringInfoData *,0> *v22; // esi@27
  HashTableData<unsigned long,AvailableProperty> *v23; // edi@27
  HashTableData<unsigned long,AvailableProperty> **v24; // esi@28
  unsigned int v25; // ecx@29
  MasterProperty *v26; // ebp@29
  HashTableData<unsigned long,BasePropertyDesc *> *v27; // eax@29
  PStringBase<char> *v28; // ecx@33
  PStringBase<char> *v29; // ecx@34
  BasePropertyDesc *v30; // eax@38
  HashTableData<unsigned long,BaseProperty> *v31; // eax@40
  char *v32; // esi@45
  int v33; // edx@47
  HashTableData<unsigned long,AvailableProperty> **v34; // eax@50
  bool result; // al@55
  PStringBase<char> v36; // [sp-6h] [bp-40h]@13
  PStringBase<char> *v37; // [sp-2h] [bp-3Ch]@7
  int v38; // [sp+12h] [bp-28h]@2
  MasterPropertyGrabber rMPR; // [sp+16h] [bp-24h]@2
  StructPropertyValue *v40; // [sp+1Ah] [bp-20h]@1
  unsigned int _key; // [sp+1Eh] [bp-1Ch]@33
  HashIterator<unsigned long,AvailableProperty,0> rIter; // [sp+22h] [bp-18h]@7
  HashIterator<unsigned long,AvailableProperty,0> rEnd; // [sp+2Eh] [bp-Ch]@27

  v3 = _node;
  v40 = this;
  if ( _node && (BYTE2(v38) = 1, MasterPropertyGrabber::MasterPropertyGrabber(&rMPR), rMPR.m_object) )
  {
    if ( ProgramTypeSystem::s_eProgramType == -2147483646
      || (BYTE3(v38) = 0, ProgramTypeSystem::s_eProgramType == -2147483647) )
      BYTE3(v38) = 1;
    v4 = PFileNode::GetNumSubNodes(v3);
    v5 = (int)_desc;
    v6 = v4;
    v7 = 0;
    if ( v4 )
    {
      while ( 1 )
      {
        rIter.m_iter.m_currHashTable = 0;
        rIter.m_iter.m_currBucket = 0;
        v8 = v3->vfptr;
        v37 = v7;
        v9 = (PFileNode *)v8[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v3, (unsigned int)v7);
        if ( !BaseProperty::FromFileNode((BaseProperty *)&rIter, v9) )
          break;
        if ( !BYTE3(v38) || !BaseProperty::IsToolOnly((BaseProperty *)&rIter) )
        {
          v11 = (unsigned int)BaseProperty::GetPropertyName((BaseProperty *)&rIter);
          if ( !*(_BYTE *)(v5 + 182) && !AvailablePropertySet::contains((AvailablePropertySet *)(v5 + 44), v11) )
          {
            PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_desc, "<UNKNOWN>");
            v37 = (PStringBase<char> *)&_desc;
            v12 = (unsigned int)BaseProperty::GetPropertyName((BaseProperty *)&rIter);
            MasterProperty::InqPropertyNameString(rMPR.m_object, v12, v37);
            v37 = (PStringBase<char> *)_desc;
            v36.m_charbuffer = v13;
            PStringBase<char>::PStringBase<char>(&v36, "property '%s' is not an available property for this struct.");
            PFileNode::ReportError(v5, v3, v36);
            v14 = (char *)&_desc[-1].m_bRecorded;
            BYTE2(v38) = 0;
            if ( !InterlockedDecrement((volatile LONG *)&_desc[-1].m_nMinElements) && v14 )
            {
              v15 = *(_DWORD *)v14;
              v37 = (PStringBase<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v15)(v14, 1);
            }
            v3 = _node;
            goto LABEL_17;
          }
          _key = (unsigned int)BaseProperty::GetPropertyName((BaseProperty *)&rIter);
          if ( !HashTable<unsigned long,BaseProperty,1>::add(
                  (HashTable<unsigned long,BaseProperty,1> *)&v40->m_value.vfptr,
                  &_key,
                  (BaseProperty *)&rIter) )
          {
            v37 = v28;
            v29 = (PStringBase<char> *)&v37;
            v36.m_charbuffer = (PSRefBufferCharData<char> *)"cannot add duplicates to Property structures";
            goto LABEL_36;
          }
          goto LABEL_17;
        }
        BaseProperty::~BaseProperty((BaseProperty *)&rIter);
LABEL_25:
        v7 = (PStringBase<char> *)((char *)v7 + 1);
        if ( (unsigned int)v7 >= v6 )
          goto LABEL_26;
      }
      v37 = v10;
      v29 = (PStringBase<char> *)&v37;
      v36.m_charbuffer = (PSRefBufferCharData<char> *)"failed to read property";
LABEL_36:
      PStringBase<char>::PStringBase<char>(v29, v36.m_charbuffer->m_data);
      PFileNode::ReportError(v5, v3, (PStringBase<char>)v37);
      BYTE2(v38) = 0;
LABEL_17:
      if ( (_DWORD)rIter.m_iter.m_currHashTable )
      {
        v16 = rIter.m_iter.m_currHashTable;
        v17 = (HashTableData<unsigned long,AvailableProperty> *)((char *)rIter.m_iter.m_currHashTable->m_aInplaceBuckets[0]
                                                               - 1);
        rIter.m_iter.m_currHashTable->m_aInplaceBuckets[0] = v17;
        if ( !v17 )
        {
          v18 = v16->vfptr;
          v37 = (PStringBase<char> *)1;
          ((void (__stdcall *)(signed int))v18->__vecDelDtor)(1);
        }
        rIter.m_iter.m_currHashTable = 0;
      }
      if ( rIter.m_iter.m_currBucket )
      {
        v19 = rIter.m_iter.m_currBucket;
        v20 = *((_DWORD *)rIter.m_iter.m_currBucket + 1) - 1;
        *((_DWORD *)rIter.m_iter.m_currBucket + 1) = v20;
        if ( !v20 )
        {
          v21 = *v19;
          v37 = (PStringBase<char> *)1;
          ((void (__stdcall *)(signed int))v21->m_hashKey)(1);
        }
        rIter.m_iter.m_currBucket = 0;
      }
      goto LABEL_25;
    }
LABEL_26:
    if ( !*(_BYTE *)(v5 + 182) )
    {
      v22 = (HashTable<unsigned long,StringInfoData *,0> *)BasePropertyDesc::GetAvailablePropertySet((BasePropertyDesc *)v5);
      HashTable<unsigned long,BaseProperty,1>::begin(v22, (HashIterator<unsigned long,StringInfoData *,0> *)&rIter);
      AvailablePropertySet::end((AvailablePropertySet *)v22, &rEnd);
      v23 = rIter.m_iter.m_currElement;
      if ( rIter.m_iter.m_currElement != rEnd.m_iter.m_currElement )
      {
        v24 = rIter.m_iter.m_currBucket;
        do
        {
          v25 = v23->m_hashKey;
          v26 = rMPR.m_object;
          v27 = rMPR.m_object->m_properties.m_intrusiveTable.m_buckets[v23->m_hashKey
                                                                     % rMPR.m_object->m_properties.m_intrusiveTable.m_numBuckets];
          if ( v27 )
          {
            while ( v27->m_hashKey != v25 )
            {
              v27 = v27->m_hashNext;
              if ( !v27 )
                goto LABEL_49;
            }
            if ( v27 )
            {
              v30 = v27->m_data;
              if ( v30 )
              {
                if ( v30->m_bRequired )
                {
                  v31 = v40->m_value.m_intrusiveTable.m_buckets[v25 % v40->m_value.m_intrusiveTable.m_numBuckets];
                  if ( !v31 )
                    goto LABEL_45;
                  while ( v31->m_hashKey != v25 )
                  {
                    v31 = v31->m_hashNext;
                    if ( !v31 )
                      goto LABEL_45;
                  }
                  if ( !v31 )
                  {
LABEL_45:
                    PStringBase<char>::PStringBase<char>((PStringBase<char> *)&_desc, "<UNKNOWN>");
                    MasterProperty::InqPropertyNameString(
                      v26,
                      rIter.m_iter.m_currElement->m_hashKey,
                      (PStringBase<char> *)&_desc);
                    v37 = (PStringBase<char> *)_desc;
                    v36.m_charbuffer = (PSRefBufferCharData<char> *)_desc;
                    PStringBase<char>::PStringBase<char>(
                      &v36,
                      "property '%s' is an available property for this struct, it has been marked in its definition as being required, but it has not been set in this struct.");
                    PFileNode::ReportError((int)v23, _node, v36);
                    v32 = (char *)&_desc[-1].m_bRecorded;
                    if ( !InterlockedDecrement((volatile LONG *)&_desc[-1].m_nMinElements) )
                    {
                      if ( v32 )
                      {
                        v33 = *(_DWORD *)v32;
                        v37 = (PStringBase<char> *)1;
                        (*(void (__thiscall **)(char *, signed int))v33)(v32, 1);
                      }
                    }
                    v24 = rIter.m_iter.m_currBucket;
                    v23 = rIter.m_iter.m_currElement;
                  }
                }
              }
            }
          }
LABEL_49:
          v23 = v23->m_hashNext;
          rIter.m_iter.m_currElement = v23;
          if ( !v23 )
          {
            v34 = &rIter.m_iter.m_currHashTable->m_buckets[rIter.m_iter.m_currHashTable->m_numBuckets];
            while ( 1 )
            {
              ++v24;
              rIter.m_iter.m_currBucket = v24;
              if ( v24 == v34 )
                break;
              if ( *v24 )
              {
                v23 = *v24;
                rIter.m_iter.m_currElement = *v24;
                break;
              }
            }
          }
        }
        while ( v23 != rEnd.m_iter.m_currElement );
      }
    }
    ((void (*)(void))rMPR.m_object->vfptr->Release)();
    result = BYTE2(v38);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 836720: using guessed type enum ProgramType ProgramTypeSystem::s_eProgramType;

