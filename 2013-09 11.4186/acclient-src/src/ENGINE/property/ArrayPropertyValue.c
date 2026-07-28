/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ArrayPropertyValue
   Object     : ENGINE\property\ArrayPropertyValue.obj
   Functions  : 6
   Addresses  : 0042B700 - 0042B8A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0042B700) --------------------------------------------------------  // acclient.c:104424
char __thiscall ArrayPropertyValue::ToFileNode(ArrayPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  ArrayPropertyValue *v3; // edi@1
  unsigned int v4; // ebx@2
  unsigned int v5; // esi@2

  v3 = this;
  if ( _node )
  {
    v4 = this->m_value.m_num;
    v5 = 0;
    if ( !v4 )
      return 1;
    while ( BaseProperty::ToFileNode(&v3->m_value.m_data[v5], _node) )
    {
      ++v5;
      if ( v5 >= v4 )
        return 1;
    }
  }
  return 0;
}

//----- (0042B740) --------------------------------------------------------  // acclient.c:104448
void __cdecl _STL::swap(BaseProperty *__a, BaseProperty *__b)
{
  BasePropertyDesc *v2; // ecx@2
  unsigned int v3; // edx@2
  BasePropertyValue *v4; // ecx@6
  unsigned int v5; // edx@6
  BaseProperty __tmp; // [sp+8h] [bp-8h]@1

  __tmp.m_pcPropertyDesc = 0;
  __tmp.m_pcPropertyValue = 0;
  BaseProperty::operator=(&__tmp, (int)__a);
  BaseProperty::operator=(__a, (int)__b);
  BaseProperty::operator=(__b, (int)&__tmp);
  if ( (_DWORD)__tmp.m_pcPropertyDesc )
  {
    v2 = __tmp.m_pcPropertyDesc;
    v3 = __tmp.m_pcPropertyDesc->m_cRef - 1;
    __tmp.m_pcPropertyDesc->m_cRef = v3;
    if ( !v3 )
      ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    __tmp.m_pcPropertyDesc = 0;
  }
  if ( __tmp.m_pcPropertyValue )
  {
    v4 = __tmp.m_pcPropertyValue;
    v5 = __tmp.m_pcPropertyValue->m_cRef - 1;
    __tmp.m_pcPropertyValue->m_cRef = v5;
    if ( !v5 )
      ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  }
}

//----- (0042B7D0) --------------------------------------------------------  // acclient.c:104481
char __thiscall ArrayPropertyValue::Compare(ArrayPropertyValue *this, BasePropertyValue *_p)
{
  ArrayPropertyValue *v2; // ebx@1
  int v3; // eax@1
  int v4; // edi@1
  unsigned int v5; // ebp@2
  unsigned int v6; // esi@3

  v2 = this;
  v3 = ((int (*)(void))_p->vfptr[66].__vecDelDtor)();
  v4 = v3;
  if ( v3 )
  {
    v5 = v2->m_value.m_num;
    if ( v5 == *(_DWORD *)(v3 + 8) )
    {
      v6 = 0;
      if ( !v5 )
        return 1;
      while ( BaseProperty::Compare(&v2->m_value.m_data[v6], (BaseProperty *)(8 * v6 + *(_DWORD *)v4)) )
      {
        ++v6;
        if ( v6 >= v5 )
          return 1;
      }
    }
  }
  return 0;
}

//----- (0042B840) --------------------------------------------------------  // acclient.c:104512
char __thiscall ArrayPropertyValue::SwapArrayElements(ArrayPropertyValue *this, const unsigned int _index1, const unsigned int _index2)
{
  _STL::swap(&this->m_value.m_data[_index1], &this->m_value.m_data[_index2]);
  return 1;
}

//----- (0042B860) --------------------------------------------------------  // acclient.c:104519
char __thiscall ArrayPropertyValue::GetValueAsString(ArrayPropertyValue *this, BasePropertyDesc *_desc, PStringBase<char> *_value, bool rawValue)
{
  char result; // al@2

  if ( rawValue )
  {
    PStringBase<char>::sprintf(_value, "%d", this->m_value.m_num);
    result = 1;
  }
  else
  {
    PStringBase<char>::sprintf(_value, "Array [%d items]", this->m_value.m_num);
    result = 1;
  }
  return result;
}

//----- (0042B8A0) --------------------------------------------------------  // acclient.c:104537
bool __thiscall ArrayPropertyValue::FromFileNode(ArrayPropertyValue *this, BasePropertyDesc *_desc, PFileNode *_node)
{
  unsigned int v3; // ecx@2
  unsigned int v4; // eax@5
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // edx@6
  PFileNode *v6; // eax@6
  PStringBase<char> *v7; // ecx@6
  unsigned int v8; // eax@10
  unsigned int v9; // eax@13
  char *v10; // esi@13
  int v11; // eax@15
  char *v12; // esi@16
  int v13; // edx@18
  int v14; // esi@19
  int v15; // eax@19
  unsigned int v16; // eax@20
  BasePropertyDesc *v17; // ecx@23
  unsigned int v18; // esi@23
  ReferenceCountTemplate<1048576,1>Vtbl *v19; // eax@24
  BasePropertyValue *v20; // ecx@27
  unsigned int v21; // esi@27
  ReferenceCountTemplate<1048576,1>Vtbl *v22; // edx@28
  bool result; // al@31
  PStringBase<char> v24; // [sp-Ch] [bp-3Ch]@13
  PSRefBufferCharData<char> *v25; // [sp-8h] [bp-38h]@13
  PStringBase<char> *v26; // [sp-4h] [bp-34h]@6
  int v27; // [sp+10h] [bp-20h]@3
  PStringBase<char> strArrayPropertyName; // [sp+14h] [bp-1Ch]@13
  PStringBase<char> strPropertyName; // [sp+18h] [bp-18h]@13
  unsigned int iq; // [sp+1Ch] [bp-14h]@5
  ArrayPropertyValue *v31; // [sp+20h] [bp-10h]@1
  unsigned int nElements; // [sp+24h] [bp-Ch]@2
  BaseProperty p; // [sp+28h] [bp-8h]@6

  v31 = this;
  if ( _node )
  {
    v3 = PFileNode::GetNumSubNodes(_node);
    nElements = v3;
    if ( ProgramTypeSystem::s_eProgramType == -2147483646
      || (BYTE3(v27) = 0, ProgramTypeSystem::s_eProgramType == -2147483647) )
      BYTE3(v27) = 1;
    v4 = 0;
    BYTE2(v27) = 1;
    iq = 0;
    if ( v3 > 0 )
    {
      do
      {
        v5 = _node->vfptr;
        v26 = (PStringBase<char> *)v4;
        p.m_pcPropertyDesc = 0;
        p.m_pcPropertyValue = 0;
        v6 = (PFileNode *)v5[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)_node, v4);
        if ( BaseProperty::FromFileNode(&p, v6) )
        {
          if ( !BYTE3(v27) || !BaseProperty::IsToolOnly(&p) )
          {
            v8 = (unsigned int)BaseProperty::GetPropertyName(&p);
            if ( _desc->m_bAllAvailable
              || AvailablePropertySet::contains(&_desc->m_availableProperties, v8)
              || _desc->m_bAllAvailable )
            {
              v14 = (int)&v31->m_value;
              v15 = v31->m_value.m_sizeAndDeallocate & 0x7FFFFFFF;
              if ( v31->m_value.m_num < v15
                || (v16 = SmartArray<UIChildFramework *,1>::get_new_size(v15 + 1),
                    SmartArray<BaseProperty,1>::grow((SmartArray<BaseProperty,1> *)v14, v16)) )
                BaseProperty::operator=((void *)(*(_DWORD *)v14 + 8 * (*(_DWORD *)(v14 + 8))++), (int)&p);
            }
            else
            {
              PStringBase<char>::PStringBase<char>(&strPropertyName, "<UNKNOWN>");
              PStringBase<char>::PStringBase<char>(&strArrayPropertyName, "<UNKNOWN>");
              MasterProperty::InqPropertyNameStringStatic(_desc->m_propertyName, &strArrayPropertyName);
              v26 = &strPropertyName;
              v9 = (unsigned int)BaseProperty::GetPropertyName(&p);
              MasterProperty::InqPropertyNameStringStatic(v9, v26);
              v26 = (PStringBase<char> *)strArrayPropertyName.m_charbuffer;
              v25 = strPropertyName.m_charbuffer;
              v24.m_charbuffer = strPropertyName.m_charbuffer;
              PStringBase<char>::PStringBase<char>(&v24, "[%s] is not an available property for [%s]");
              PFileNode::ReportError((int)_node, _node, v24);
              v10 = &strArrayPropertyName.m_charbuffer[-2].m_data[12];
              BYTE2(v27) = 0;
              if ( !InterlockedDecrement((volatile LONG *)&strArrayPropertyName.m_charbuffer[-1]) && v10 )
              {
                v11 = *(_DWORD *)v10;
                v26 = (PStringBase<char> *)1;
                (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
              }
              v12 = &strPropertyName.m_charbuffer[-2].m_data[12];
              if ( !InterlockedDecrement((volatile LONG *)&strPropertyName.m_charbuffer[-1]) && v12 )
              {
                v13 = *(_DWORD *)v12;
                v26 = (PStringBase<char> *)1;
                (*(void (__thiscall **)(char *, signed int))v13)(v12, 1);
              }
            }
          }
        }
        else
        {
          v26 = v7;
          PStringBase<char>::PStringBase<char>((PStringBase<char> *)&v26, "failed to read property");
          PFileNode::ReportError((int)_node, _node, (PStringBase<char>)v26);
          BYTE2(v27) = 0;
        }
        if ( (_DWORD)p.m_pcPropertyDesc )
        {
          v17 = p.m_pcPropertyDesc;
          v18 = p.m_pcPropertyDesc->m_cRef - 1;
          p.m_pcPropertyDesc->m_cRef = v18;
          if ( !v18 )
          {
            v19 = v17->vfptr;
            v26 = (PStringBase<char> *)1;
            ((void (__stdcall *)(signed int))v19->__vecDelDtor)(1);
          }
          p.m_pcPropertyDesc = 0;
        }
        if ( p.m_pcPropertyValue )
        {
          v20 = p.m_pcPropertyValue;
          v21 = p.m_pcPropertyValue->m_cRef - 1;
          p.m_pcPropertyValue->m_cRef = v21;
          if ( !v21 )
          {
            v22 = v20->vfptr;
            v26 = (PStringBase<char> *)1;
            ((void (__stdcall *)(signed int))v22->__vecDelDtor)(1);
          }
          p.m_pcPropertyValue = 0;
        }
        v4 = iq++ + 1;
      }
      while ( iq < nElements );
    }
    result = BYTE2(v27);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 836720: using guessed type enum ProgramType ProgramTypeSystem::s_eProgramType;

