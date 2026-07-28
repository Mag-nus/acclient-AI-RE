/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : StateDesc
   Object     : ENGINE\uielement_desc\StateDesc.obj
   Functions  : 123
   Addresses  : 0069BED0 - 007889A0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0069BED0) --------------------------------------------------------  // acclient.c:692165
void __thiscall StateDesc::GetSubDataIDs(StateDesc *this, QualifiedDataIDArray *_id_array)
{
  StateDesc *v2; // esi@1
  unsigned int v3; // edi@1
  MediaDesc *v4; // ecx@2

  v2 = this;
  PropertyCollection::GetSubDataIDs(&this->m_properties, _id_array);
  v3 = 0;
  if ( v2->m_media.m_num )
  {
    do
    {
      v4 = v2->m_media.m_data[v3];
      if ( v4 )
        (*((void (__stdcall **)(QualifiedDataIDArray *))&v4->vfptr->__vecDelDtor + 2))(_id_array);
      ++v3;
    }
    while ( v3 < v2->m_media.m_num );
  }
}

//----- (0069BF20) --------------------------------------------------------  // acclient.c:692188
void __thiscall StateDesc::UpdateSizeAndPosition(StateDesc *this, Box2D *_oldParent, Box2D *_newParent, unsigned int _leftEdge, unsigned int _topEdge, unsigned int _rightEdge, unsigned int _bottomEdge)
{
  StateDesc *v7; // edi@1
  int v8; // eax@1
  int v9; // ebp@1
  int v10; // ecx@1
  Box2D *v11; // ecx@1
  int v12; // eax@1
  int v13; // esi@1
  int v14; // ebx@1
  int v15; // ecx@1
  int v16; // edx@1
  int v17; // ebx@1
  int v18; // edx@1
  int v19; // ebx@1
  int v20; // edx@4
  double v21; // st7@5
  int v22; // esi@16
  int v23; // ecx@24
  unsigned __int64 v24; // rax@30
  signed int v25; // [sp+10h] [bp-3Ch]@1
  float width_propor; // [sp+14h] [bp-38h]@1
  float width_propora; // [sp+14h] [bp-38h]@2
  int v28; // [sp+18h] [bp-34h]@1
  int v29; // [sp+1Ch] [bp-30h]@1
  int v30; // [sp+20h] [bp-2Ch]@1
  int currentPosition; // [sp+2Ch] [bp-20h]@1
  int currentPosition_4; // [sp+30h] [bp-1Ch]@1
  int currentPosition_8; // [sp+34h] [bp-18h]@1
  int currentPosition_12; // [sp+38h] [bp-14h]@1
  signed int originalPosition_8; // [sp+44h] [bp-8h]@1
  int originalPosition_12; // [sp+48h] [bp-4h]@1
  int _oldParenta; // [sp+50h] [bp+4h]@1
  int _newParenta; // [sp+54h] [bp+8h]@1

  v7 = this;
  v8 = this->m_y;
  v9 = this->m_x;
  originalPosition_12 = this->m_height + v8 - 1;
  currentPosition_12 = this->m_height + v8 - 1;
  v10 = this->m_width + v9 - 1;
  originalPosition_8 = v10;
  currentPosition_8 = v10;
  v11 = _oldParent;
  _oldParenta = _newParent->m_x1;
  v28 = _newParent->m_x0;
  width_propor = *(float *)&v11->m_x0;
  v25 = v8;
  currentPosition_4 = v8;
  v12 = v11->m_x1;
  v13 = _oldParenta + v11->m_x0 - _newParent->m_x0 - v12;
  v14 = v11->m_y1;
  v15 = v11->m_y0;
  v30 = v14;
  v16 = _newParent->m_y1;
  _newParenta = _newParent->m_y0;
  v29 = v16;
  v17 = v16 - _newParenta;
  v18 = v30;
  v19 = v15 + v17 - v30;
  currentPosition = v9;
  if ( v12 - LODWORD(width_propor) == -1 )
  {
    width_propora = 0.0;
  }
  else
  {
    v18 = v30;
    width_propora = (double)(_oldParenta - v28 + 1) / (double)(v12 - LODWORD(width_propor) + 1);
  }
  v20 = v18 - v15;
  if ( v20 == -1 )
    v21 = 0.0;
  else
    v21 = (double)(v29 - _newParenta + 1) / (double)(v20 + 1);
  switch ( _leftEdge )
  {
    case 2u:
      currentPosition = v13 + v9;
      break;
    case 3u:
      currentPosition = (_oldParenta - v28 + 1) / 2 - (originalPosition_8 - v9 + 1) / 2;
      break;
    case 4u:
      currentPosition = (unsigned __int64)((double)v9 * width_propora);
      break;
  }
  switch ( _rightEdge )
  {
    case 1u:
      currentPosition_8 = v13 + originalPosition_8;
      break;
    case 3u:
      currentPosition_8 = (_oldParenta - v28 + 1) / 2 + (originalPosition_8 - v9 + 1) / 2 - 1;
      break;
    case 4u:
      v22 = (unsigned __int64)((double)originalPosition_8 * width_propora);
      goto LABEL_20;
  }
  v22 = currentPosition_8;
LABEL_20:
  if ( _topEdge == 2 )
  {
    v23 = v19 + v25;
    goto LABEL_26;
  }
  if ( _topEdge == 3 )
  {
    v23 = (v29 - _newParenta + 1) / 2 - (originalPosition_12 - v25 + 1) / 2;
LABEL_26:
    currentPosition_4 = v23;
    goto LABEL_27;
  }
  if ( _topEdge == 4 )
    currentPosition_4 = (unsigned __int64)((double)v25 * v21);
LABEL_27:
  if ( _bottomEdge == 1 )
  {
    currentPosition_12 = v19 + originalPosition_12;
    goto LABEL_33;
  }
  if ( _bottomEdge == 3 )
  {
    currentPosition_12 = (v29 - _newParenta + 1) / 2 + (originalPosition_12 - v25 + 1) / 2 - 1;
    goto LABEL_33;
  }
  if ( _bottomEdge != 4 )
  {
LABEL_33:
    LODWORD(v24) = currentPosition_12;
    goto LABEL_34;
  }
  v24 = (unsigned __int64)((double)originalPosition_12 * v21);
LABEL_34:
  v7->m_width = v22 - currentPosition + 1;
  v7->m_x = currentPosition;
  v7->m_y = currentPosition_4;
  v7->m_height = v24 - currentPosition_4 + 1;
}

//----- (0069C180) --------------------------------------------------------  // acclient.c:692329
void __thiscall StateDesc::StateDesc(StateDesc *this)
{
  StateDesc *v1; // esi@1

  v1 = this;
  this->vfptr = (StateDescVtbl *)&StateDesc::vftable;
  this->m_uiIncorporationFlags = 0;
  this->m_stateID = 0;
  this->m_bIsCode = 0;
  this->m_bPassToChildren = 0;
  this->m_x = 0;
  this->m_y = 0;
  this->m_width = 0;
  this->m_height = 0;
  this->m_zLevel = 0;
  PropertyCollection::PropertyCollection(&this->m_properties);
  v1->m_media.m_data = 0;
  v1->m_media.m_sizeAndDeallocate = 0;
  v1->m_media.m_num = 0;
}
// 800E44: using guessed type int (__thiscall *StateDesc::vftable)(void *, char);

//----- (0069C1D0) --------------------------------------------------------  // acclient.c:692352
char __stdcall StateDesc::PositionToFileNode(PFileNode *_file_node)
{
  return 1;
}

//----- (0069C1E0) --------------------------------------------------------  // acclient.c:692358
void __thiscall StateDesc::CleanupMedia(StateDesc *this)
{
  StateDesc *v1; // esi@1
  unsigned int v2; // edi@1
  MediaDesc *v3; // ecx@2
  unsigned int v4; // eax@5
  unsigned int v5; // ecx@5
  int i; // eax@8

  v1 = this;
  v2 = 0;
  if ( this->m_media.m_num )
  {
    do
    {
      v3 = v1->m_media.m_data[v2];
      if ( v3 )
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
      ++v2;
    }
    while ( v2 < v1->m_media.m_num );
  }
  v4 = v1->m_media.m_sizeAndDeallocate;
  v5 = v1->m_media.m_sizeAndDeallocate & 0x80000000;
  v1->m_media.m_num = 0;
  if ( v5 == 0x80000000 )
  {
    operator delete[](v1->m_media.m_data);
    v1->m_media.m_data = 0;
    v1->m_media.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_media.m_data )
  {
    for ( i = (v4 & 0x7FFFFFFF) - 1; i >= 0; v1->m_media.m_data[i + 1] = 0 )
      --i;
  }
}

//----- (0069C290) --------------------------------------------------------  // acclient.c:692397
void __thiscall StateDesc::~StateDesc(StateDesc *this)
{
  StateDesc *v1; // esi@1

  v1 = this;
  this->vfptr = (StateDescVtbl *)&StateDesc::vftable;
  StateDesc::CleanupMedia(this);
  if ( (v1->m_media.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_media.m_data);
  PropertyCollection::~PropertyCollection(&v1->m_properties);
}
// 800E44: using guessed type int (__thiscall *StateDesc::vftable)(void *, char);

//----- (0069C2D0) --------------------------------------------------------  // acclient.c:692411
char __thiscall StateDesc::ToFileNode(StateDesc *this, PFileNode *_file_node)
{
  StateDesc *v2; // esi@1
  PFileNode *v3; // eax@3
  void *v4; // ecx@4
  PFileNode *v5; // edi@4
  PFileNode *v6; // eax@8
  StateDescVtbl *v7; // eax@10
  void *v8; // ecx@10
  PFileNode *v9; // eax@12
  unsigned int v10; // ebp@14
  MediaDesc *v11; // edi@15
  PFileNode *v12; // eax@16
  MediaDescVtbl *v13; // edx@17
  void *v15; // [sp-4h] [bp-14h]@3

  v2 = this;
  if ( _file_node )
  {
    if ( !this->m_stateID
      || (v15 = KW_STATEID_1.m_charbuffer,
          InterlockedIncrement((volatile LONG *)&KW_STATEID_1.m_charbuffer[-1]),
          (v3 = PFileNode::MakeSubNode(_file_node, (PStringBase<char>)v15)) != 0)
      && (v5 = FileNodeUtils::MakeSubNodeAsEnum(v3, 0x14u, v2->m_stateID)) != 0
      && (!v2->m_bIsCode
       || (v15 = v4,
           PStringBase<unsigned short>::PStringBase<unsigned short>(
             (CaseInsensitiveStringBase<PStringBase<char> > *)&v15,
             &KW_CODE_1),
           PFileNode::MakeSubNode(v5, (PStringBase<char>)v15))) )
    {
      if ( !(v2->m_uiIncorporationFlags & 1)
        || (v15 = KW_PASSTOCHILDREN_1.m_charbuffer,
            InterlockedIncrement((volatile LONG *)&KW_PASSTOCHILDREN_1.m_charbuffer[-1]),
            (v6 = PFileNode::MakeSubNode(_file_node, (PStringBase<char>)v15)) != 0)
        && PFileNode::MakeSubNodeAsBool(v6, v2->m_bPassToChildren) )
      {
        v7 = v2->vfptr;
        v15 = _file_node;
        if ( v7->PositionToFileNode(v2, _file_node) )
        {
          if ( !v2->m_properties.m_hashProperties.m_intrusiveTable.m_numElements
            || (v15 = v8,
                PStringBase<unsigned short>::PStringBase<unsigned short>(
                  (CaseInsensitiveStringBase<PStringBase<char> > *)&v15,
                  &KW_PROPERTIES_2),
                (v9 = PFileNode::MakeSubNode(_file_node, (PStringBase<char>)v15)) != 0)
            && PropertyCollection::ToFileNode(&v2->m_properties, v9) )
          {
            v10 = 0;
            if ( !v2->m_media.m_num )
              return 1;
            while ( 1 )
            {
              v11 = v2->m_media.m_data[v10];
              if ( v11 )
              {
                v15 = KW_MEDIA_1.m_charbuffer;
                InterlockedIncrement((volatile LONG *)&KW_MEDIA_1.m_charbuffer[-1]);
                v12 = PFileNode::MakeSubNode(_file_node, (PStringBase<char>)v15);
                if ( !v12 )
                  break;
                v13 = v11->vfptr;
                v15 = v12;
                if ( !v13->ToFileNode(v11, v12) )
                  break;
              }
              ++v10;
              if ( v10 >= v2->m_media.m_num )
                return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

//----- (0069C440) --------------------------------------------------------  // acclient.c:692491
char __userpurge StateDesc::CheckFFN@<al>(StateDesc *this@<ecx>, int a2@<edi>, PFileNode *_file_node)
{
  char result; // al@1
  PStringBase<char> v4; // [sp-4h] [bp-4h]@2

  result = 1;
  if ( !this->m_stateID )
  {
    v4.m_charbuffer = (PSRefBufferCharData<char> *)this;
    PStringBase<char>::PStringBase<char>(&v4, "StateDesc::CheckFFN, you must use the StateID keyword in States.");
    PFileNode::ReportError(a2, _file_node, v4);
    result = 0;
  }
  return result;
}

//----- (0069C470) --------------------------------------------------------  // acclient.c:692508
void __cdecl SB_Container<SB_TypeAlloc<MediaDescResolver,SB_Default>,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(const int *_class, SmartArray<MediaDesc *,1> *_obj, Archive *_arc)
{
  SmartArray<MediaDesc *,1> *v3; // ebp@1
  unsigned int v4; // eax@2
  unsigned int v5; // edi@2
  unsigned int v6; // eax@4
  MediaDesc **v7; // edi@9
  unsigned int v8; // ebx@10
  unsigned int v9; // eax@13
  MediaDesc *v10; // eax@18
  unsigned int nElements; // [sp+Ch] [bp-4h]@1

  v3 = _obj;
  nElements = _obj->m_num;
  SB_As32Bit_Compressed::Serialize(_class, &nElements, _arc);
  LOBYTE(_obj) = 0;
  if ( ~LOBYTE(_arc->m_flags) & 1 )
  {
    v4 = Archive::GetSizeLeft(_arc);
    v5 = nElements;
    if ( nElements > v4 )
    {
      Archive::RaiseError(_arc);
      return;
    }
    v6 = v3->m_num;
    if ( nElements <= v6 )
    {
      if ( nElements < v6 )
      {
        v3->m_num = nElements;
        SmartArray<MediaDesc *,1>::shrink((SmartArray<int,1> *)v3);
      }
    }
    else
    {
      SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v3, nElements);
      v3->m_num = v5;
    }
    LOBYTE(_obj) = 1;
  }
  v7 = v3->m_data;
  if ( v3->m_data != &v3->m_data[v3->m_num] )
  {
    v8 = (unsigned int)_obj;
    while ( 1 )
    {
      if ( _arc->m_flags & 1 )
        v8 = (*v7)->m_type;
      Archive::CheckAlignment(_arc, 4u);
      v9 = Archive::GetBytes(_arc, 4u);
      if ( v9 )
      {
        if ( _arc->m_flags & 1 )
          *(_DWORD *)v9 = v8;
        else
          v8 = *(_DWORD *)v9;
      }
      if ( ~LOBYTE(_arc->m_flags) & 1 )
      {
        MediaDesc::CreateMediaType(v8);
        *v7 = v10;
      }
      if ( *v7 )
        (*((void (__stdcall **)(Archive *))&(*v7)->vfptr->__vecDelDtor + 1))(_arc);
      if ( (_arc->m_flags >> 2) & 1 )
        break;
      ++v7;
      if ( v7 == &v3->m_data[v3->m_num] )
        return;
    }
    if ( (_BYTE)_obj )
    {
      if ( v3->m_num )
      {
        v3->m_num = 0;
        SmartArray<MediaDesc *,1>::shrink((SmartArray<int,1> *)v3);
      }
    }
  }
}

//----- (0069C5A0) --------------------------------------------------------  // acclient.c:692591
StateDesc *__thiscall StateDesc::vector_deleting_destructor(StateDesc *this, unsigned int a2)
{
  StateDesc *v2; // esi@1

  v2 = this;
  this->vfptr = (StateDescVtbl *)&StateDesc::vftable;
  StateDesc::CleanupMedia(this);
  if ( (v2->m_media.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v2->m_media.m_data);
  PropertyCollection::~PropertyCollection(&v2->m_properties);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 800E44: using guessed type int (__thiscall *StateDesc::vftable)(void *, char);

//----- (0069C5F0) --------------------------------------------------------  // acclient.c:692608
void __thiscall StateDesc::Serialize(StateDesc *this, Archive *_io_archive)
{
  Archive *v2; // esi@1
  StateDesc *v3; // edi@1
  int v4; // ebp@1
  unsigned int v5; // eax@4
  unsigned int v6; // eax@9
  unsigned int v7; // eax@13
  unsigned int v8; // eax@17
  unsigned int v9; // eax@21
  unsigned int v10; // eax@25
  unsigned int v11; // eax@31

  v2 = _io_archive;
  v3 = this;
  v4 = Archive::GetVersionByToken(_io_archive, 0x55494C20u);
  if ( !(v2->m_flags & 1) || v4 )
  {
    Archive::CheckAlignment(v2, 4u);
    v5 = Archive::GetBytes(v2, 4u);
    if ( v5 )
    {
      if ( v2->m_flags & 1 )
        *(_DWORD *)v5 = v3->m_stateID;
      else
        v3->m_stateID = *(_DWORD *)v5;
    }
    Serializer::SerializeObject(&v3->m_bPassToChildren, v2);
    if ( v4 )
    {
      if ( v4 )
      {
        Archive::CheckAlignment(v2, 4u);
        v11 = Archive::GetBytes(v2, 4u);
        if ( v11 )
        {
          if ( v2->m_flags & 1 )
            *(_DWORD *)v11 = v3->m_uiIncorporationFlags;
          else
            v3->m_uiIncorporationFlags = *(_DWORD *)v11;
        }
      }
    }
    else
    {
      Archive::CheckAlignment(v2, 4u);
      v6 = Archive::GetBytes(v2, 4u);
      if ( v6 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v6 = v3->m_x;
        else
          v3->m_x = *(_DWORD *)v6;
      }
      Archive::CheckAlignment(v2, 4u);
      v7 = Archive::GetBytes(v2, 4u);
      if ( v7 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v7 = v3->m_y;
        else
          v3->m_y = *(_DWORD *)v7;
      }
      Archive::CheckAlignment(v2, 4u);
      v8 = Archive::GetBytes(v2, 4u);
      if ( v8 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v8 = v3->m_width;
        else
          v3->m_width = *(_DWORD *)v8;
      }
      Archive::CheckAlignment(v2, 4u);
      v9 = Archive::GetBytes(v2, 4u);
      if ( v9 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v9 = v3->m_height;
        else
          v3->m_height = *(_DWORD *)v9;
      }
      Archive::CheckAlignment(v2, 4u);
      v10 = Archive::GetBytes(v2, 4u);
      if ( v10 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v10 = v3->m_zLevel;
        else
          v3->m_zLevel = *(_DWORD *)v10;
      }
      Serializer::SerializeObject((bool *)&_io_archive, v2);
      v3->m_uiIncorporationFlags |= 0x3Eu;
    }
    PropertyCollection::Serialize(&v3->m_properties, v2);
    SB_Container<SB_TypeAlloc<MediaDescResolver,SB_Default>,&char const * const SB_DEFAULT_ITEM_NAME>::Serialize(
      (const int *)&_io_archive,
      &v3->m_media,
      v2);
  }
  else
  {
    Archive::RaiseError(v2);
  }
}

//----- (0069C790) --------------------------------------------------------  // acclient.c:692714
char __thiscall StateDesc::InqProperty(StateDesc *this, const unsigned int _name, BaseProperty *_property)
{
  return HashTable<unsigned long,BaseProperty,1>::find(
           (HashTable<unsigned long,BaseProperty,1> *)&this->m_properties.m_hashProperties.vfptr,
           &_name,
           _property);
}

//----- (0069C7B0) --------------------------------------------------------  // acclient.c:692723
char __thiscall StateDesc::FromFileNode(StateDesc *this, PFileNode *_file_node)
{
  PFileNode *v2; // esi@1
  StateDesc *v3; // edi@1
  char v4; // bl@2
  ReferenceCountTemplate<1048576,0>Vtbl *v5; // eax@3
  int v6; // edi@3
  StateDescVtbl *v7; // edx@4
  PStringBase<char> *v8; // eax@7
  char *v9; // esi@7
  PSRefBufferCharData<char> *v10; // ecx@7
  int v11; // edx@9
  char *v12; // esi@10
  int v13; // eax@12
  char *v14; // esi@13
  int v15; // edx@15
  char *v16; // esi@16
  int v17; // edx@18
  StateDescVtbl *v18; // eax@22
  char v19; // al@24
  PStringBase<char> v20; // [sp+0h] [bp-34h]@3
  int v21; // [sp+14h] [bp-20h]@4
  PStringBase<char> strName; // [sp+18h] [bp-1Ch]@7
  unsigned int index; // [sp+1Ch] [bp-18h]@2
  PStringBase<char> result; // [sp+20h] [bp-14h]@7
  PStringBase<char> rhs; // [sp+24h] [bp-10h]@7
  StateDesc *v26; // [sp+28h] [bp-Ch]@1
  PStringBase<char> v27; // [sp+2Ch] [bp-8h]@7
  unsigned int num; // [sp+30h] [bp-4h]@2

  v2 = _file_node;
  v3 = this;
  v26 = this;
  if ( _file_node )
  {
    v4 = 1;
    num = PFileNode::GetNumSubNodes(_file_node);
    index = 0;
    if ( num )
    {
      do
      {
        v5 = v2->vfptr;
        v20.m_charbuffer = (PSRefBufferCharData<char> *)index;
        v6 = (int)v5[3].__vecDelDtor((ReferenceCountTemplate<1048576,0> *)v2, index);
        if ( v6 )
        {
          v7 = v26->vfptr;
          v20.m_charbuffer = (PSRefBufferCharData<char> *)((char *)&v21 + 3);
          BYTE3(v21) = 0;
          if ( !(unsigned __int8)((int (__stdcall *)(int, char *))v7->HandleNode)(v6, (char *)&v21 + 3) )
            v4 = 0;
          if ( !BYTE3(v21) )
          {
            strName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
            InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
            PFileNode::GetNameAsPString((PFileNode *)v6, v6, &strName);
            PStringBase<char>::PStringBase<char>(&rhs, "] ignored");
            v20.m_charbuffer = (PSRefBufferCharData<char> *)&strName;
            PStringBase<char>::PStringBase<char>(&v27, "Unknown Keyword: [");
            PStringBase<char>::operator+(v8, &result, (PStringBase<char> *)v20.m_charbuffer);
            v9 = &v27.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&v27.m_charbuffer[-1]) && v9 )
            {
              v11 = *(_DWORD *)v9;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v11)(v9, 1);
            }
            v20.m_charbuffer = v10;
            PStringBase<char>::operator+(&result, &v20, &rhs);
            PFileNode::ReportError(v6, (PFileNode *)v6, v20);
            v12 = &result.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&result.m_charbuffer[-1]) && v12 )
            {
              v13 = *(_DWORD *)v12;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v13)(v12, 1);
            }
            v14 = &rhs.m_charbuffer[-2].m_data[12];
            if ( !InterlockedDecrement((volatile LONG *)&rhs.m_charbuffer[-1]) && v14 )
            {
              v15 = *(_DWORD *)v14;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v15)(v14, 1);
            }
            v16 = &strName.m_charbuffer[-2].m_data[12];
            v4 = 0;
            if ( !InterlockedDecrement((volatile LONG *)&strName.m_charbuffer[-1]) && v16 )
            {
              v17 = *(_DWORD *)v16;
              v20.m_charbuffer = (PSRefBufferCharData<char> *)1;
              (*(void (__thiscall **)(char *, signed int))v17)(v16, 1);
            }
            v2 = _file_node;
          }
        }
        ++index;
      }
      while ( index < num );
      v3 = v26;
    }
    v18 = v3->vfptr;
    v20.m_charbuffer = (PSRefBufferCharData<char> *)v2;
    if ( !v18->CheckFFN(v3, v2) )
      v4 = 0;
    v19 = v4;
  }
  else
  {
    v19 = 0;
  }
  return v19;
}

//----- (0069C950) --------------------------------------------------------  // acclient.c:692838
char __thiscall StateDesc::LoadMedia(StateDesc *this, PFileNode *_node)
{
  PFileNode *v2; // esi@1
  int v3; // edi@1
  PSRefBufferCharData<char> *v4; // ecx@3
  PStringBase<char> v6; // [sp-4h] [bp-Ch]@4

  v2 = _node;
  v3 = (int)this;
  if ( !_node )
    return 0;
  _node = (PFileNode *)MediaDesc::CreateFromFileNode(_node);
  if ( !_node )
    return 0;
  if ( !SmartArray<UIElement_Button *,1>::AddToEnd((SmartArray<BSPNODE *,1> *)(v3 + 156), (BSPNODE *const *)&_node) )
  {
    v6.m_charbuffer = v4;
    PStringBase<char>::PStringBase<char>(&v6, "StateDesc::LoadMedia, failed adding desc");
    PFileNode::ReportError(v3, v2, v6);
    return 0;
  }
  return 1;
}

//----- (0069C9B0) --------------------------------------------------------  // acclient.c:692863
void __thiscall StateDesc::ConcatenateMedia(StateDesc *this, StateDesc *_rhs)
{
  StateDesc *v2; // esi@1
  unsigned int v3; // ebx@2
  int v4; // eax@6
  int v5; // edi@6
  unsigned int v6; // eax@7
  unsigned int v7; // ecx@7
  int v8; // esi@7
  int v9; // eax@7
  unsigned int v10; // eax@8
  StateDesc *v11; // [sp+8h] [bp-4h]@1

  v2 = this;
  v11 = this;
  if ( this != _rhs )
  {
    v3 = 0;
    if ( _rhs->m_media.m_num )
    {
      while ( 1 )
      {
        if ( _rhs->m_media.m_data[v3] )
        {
          MediaDesc::CreateMediaType(_rhs->m_media.m_data[v3]);
          v5 = v4;
          if ( v4 )
          {
            v6 = v2->m_media.m_sizeAndDeallocate;
            v7 = v2->m_media.m_num;
            v8 = (int)&v2->m_media;
            v9 = v6 & 0x7FFFFFFF;
            if ( v7 < v9
              || (v10 = SmartArray<UIChildFramework *,1>::get_new_size(v9 + 1),
                  SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)v8, v10)) )
              *(_DWORD *)(*(_DWORD *)v8 + 4 * (*(_DWORD *)(v8 + 8))++) = v5;
          }
        }
        ++v3;
        if ( v3 >= _rhs->m_media.m_num )
          break;
        v2 = v11;
      }
    }
  }
}

//----- (0069CA40) --------------------------------------------------------  // acclient.c:692911
bool __thiscall StateDesc::ContainsProperty(StateDesc *this, const unsigned int _property)
{
  return PropertyCollection::ContainsProperty(&this->m_properties, _property);
}

//----- (0069CA50) --------------------------------------------------------  // acclient.c:692917
void __thiscall StateDesc::SetMediaImage(StateDesc *this, IDClass<_tagDataID,32,0> _imageID, unsigned int _drawMode)
{
  MD_Data_Image *v3; // eax@1
  int v4; // eax@2
  MediaDesc *v5; // edi@2
  unsigned int v6; // ecx@3
  int v7; // eax@5
  unsigned int v8; // eax@6
  StateDesc *v9; // [sp+0h] [bp-4h]@1

  v9 = this;
  v3 = (MD_Data_Image *)operator new(0x10u);
  if ( v3 )
  {
    MD_Data_Image::MD_Data_Image(v3);
    v5 = (MediaDesc *)v4;
    if ( v4 )
    {
      *(_DWORD *)(v4 + 8) = _imageID.id;
      *(_DWORD *)(v4 + 12) = _drawMode;
      v6 = 0;
      if ( v9->m_media.m_num )
      {
        do
          v9->m_media.m_data[v6++] = 0;
        while ( v6 < v9->m_media.m_num );
      }
      v9->m_media.m_num = 0;
      v7 = v9->m_media.m_sizeAndDeallocate & 0x7FFFFFFF;
      if ( v9->m_media.m_num < v7
        || (v8 = SmartArray<UIChildFramework *,1>::get_new_size(v7 + 1),
            SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v9->m_media, v8)) )
        v9->m_media.m_data[v9->m_media.m_num++] = v5;
    }
  }
}

//----- (0069CB00) --------------------------------------------------------  // acclient.c:692955
char __thiscall StateDesc::HandleNode(StateDesc *this, PFileNode *_node, bool *_handled)
{
  int v3; // edi@1
  char v4; // bl@2
  int v5; // eax@3
  PSRefBufferCharData<char> *v6; // ecx@3
  PFileNode *v7; // ebp@3
  char result; // al@6
  int v9; // eax@8
  PSRefBufferCharData<char> *v10; // ecx@8
  PStringBase<char> *v11; // ecx@17
  PStringBase<char> v12; // [sp-8h] [bp-90h]@4
  PStringBase<char> *v13; // [sp-4h] [bp-8Ch]@2
  PropertyCollection prop; // [sp+10h] [bp-78h]@15

  v3 = (int)this;
  if ( _node )
  {
    v4 = 1;
    v13 = &KW_STATEID_1;
    *_handled = 1;
    if ( PFileNode::IsKeyword(_node, (int)this, v13) )
    {
      v5 = PFileNode::GetOnlyChild(_node);
      v7 = (PFileNode *)v5;
      if ( v5 )
      {
        if ( FileNodeUtils::GetNameAsEnum((PFileNode *)v5, 0x14u, (unsigned int *)(v3 + 8)) )
        {
          *(_BYTE *)(v3 + 12) = PFileNode::FindSubNode(v7, &KW_CODE_1) != 0;
          return 1;
        }
        return 0;
      }
      v13 = (PStringBase<char> *)KW_STATEID_1.m_charbuffer;
      v12.m_charbuffer = v6;
      PStringBase<char>::PStringBase<char>(&v12, "StateDesc::HandleNode, %s expects one string");
LABEL_11:
      PFileNode::ReportError(v3, _node, v12);
      return 0;
    }
    if ( PFileNode::IsKeyword(_node, v3, &KW_PASSTOCHILDREN_1) )
    {
      v9 = PFileNode::GetLeaf(_node);
      if ( !v9 || !PFileNode::GetNameAsBool((PFileNode *)v9, v3, (bool *)(v3 + 13)) )
      {
        v13 = (PStringBase<char> *)KW_PASSTOCHILDREN_1.m_charbuffer;
        v12.m_charbuffer = v10;
        PStringBase<char>::PStringBase<char>(&v12, "StateDesc::HandleNode, %s expects a bool");
        goto LABEL_11;
      }
      *(_DWORD *)(v3 + 4) |= 1u;
      result = 1;
    }
    else if ( PFileNode::IsKeyword(_node, v3, &KW_PROPERTIES_2) )
    {
      PropertyCollection::PropertyCollection(&prop);
      if ( !PropertyCollection::FromFileNode(&prop, _node) )
        v4 = 0;
      if ( !PropertyCollection::UpdateCollection((PropertyCollection *)(v3 + 36), &prop, 1) )
      {
        v13 = v11;
        PStringBase<char>::PStringBase<char>(
          (PStringBase<char> *)&v13,
          "StateDesc::HandleNode, error updating property collection");
        PFileNode::ReportError(v3, _node, (PStringBase<char>)v13);
        v4 = 0;
      }
      PropertyCollection::~PropertyCollection(&prop);
      result = v4;
    }
    else
    {
      if ( PFileNode::IsKeyword(_node, v3, &KW_MEDIA_1) )
      {
        if ( !StateDesc::LoadMedia((StateDesc *)v3, _node) )
          return 0;
      }
      else
      {
        *_handled = 0;
      }
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0069CCA0) --------------------------------------------------------  // acclient.c:693048
char __thiscall StateDesc::Incorporate(StateDesc *this, StateDesc *_desc)
{
  unsigned int v2; // eax@1
  StateDesc *v3; // edi@1

  v2 = _desc->m_uiIncorporationFlags;
  v3 = this;
  v3->m_uiIncorporationFlags |= v2;
  if ( v2 & 1 )
    this->m_bPassToChildren = _desc->m_bPassToChildren;
  if ( _desc->m_uiIncorporationFlags & 2 )
    this->m_x = _desc->m_x;
  if ( _desc->m_uiIncorporationFlags & 4 )
    this->m_y = _desc->m_y;
  if ( _desc->m_uiIncorporationFlags & 8 )
    this->m_width = _desc->m_width;
  if ( _desc->m_uiIncorporationFlags & 0x10 )
    this->m_height = _desc->m_height;
  if ( _desc->m_uiIncorporationFlags & 0x20 )
    this->m_zLevel = _desc->m_zLevel;
  StateDesc::ConcatenateMedia(this, _desc);
  PropertyCollection::UpdateCollection(&v3->m_properties, &_desc->m_properties, 1);
  return 1;
}

//----- (0069CD20) --------------------------------------------------------  // acclient.c:693074
StateDesc *__thiscall StateDesc::operator=(StateDesc *this, StateDesc *_rhs)
{
  StateDesc *v2; // esi@1

  v2 = this;
  if ( this != _rhs )
  {
    this->m_uiIncorporationFlags = _rhs->m_uiIncorporationFlags;
    this->m_stateID = _rhs->m_stateID;
    this->m_bIsCode = _rhs->m_bIsCode;
    this->m_bPassToChildren = _rhs->m_bPassToChildren;
    this->m_x = _rhs->m_x;
    this->m_y = _rhs->m_y;
    this->m_width = _rhs->m_width;
    this->m_height = _rhs->m_height;
    this->m_zLevel = _rhs->m_zLevel;
    PropertyCollection::operator=(&this->m_properties, &_rhs->m_properties);
    StateDesc::CleanupMedia(v2);
    StateDesc::ConcatenateMedia(v2, _rhs);
  }
  return v2;
}

//----- (0069CD90) --------------------------------------------------------  // acclient.c:693098
void __thiscall StateDesc::StateDesc(StateDesc *this, StateDesc *_rhs)
{
  StateDesc *v2; // esi@1

  v2 = this;
  this->vfptr = (StateDescVtbl *)&StateDesc::vftable;
  PropertyCollection::PropertyCollection(&this->m_properties);
  v2->m_media.m_data = 0;
  v2->m_media.m_sizeAndDeallocate = 0;
  v2->m_media.m_num = 0;
  StateDesc::operator=(v2, _rhs);
}
// 800E44: using guessed type int (__thiscall *StateDesc::vftable)(void *, char);

//----- (0071C140) --------------------------------------------------------  // acclient.c:814319
int sub_71C140()
{
  KW_NULL_5.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  return atexit(sub_788040);
}

//----- (0071C160) --------------------------------------------------------  // acclient.c:814327
int sub_71C160()
{
  PStringBase<char>::PStringBase<char>(&KW_BASE_1, "Base");
  return atexit(sub_788070);
}

//----- (0071C180) --------------------------------------------------------  // acclient.c:814334
int _E79_97()
{
  PStringBase<char>::PStringBase<char>(&KW_BOTTOMEDGE_1, "BottomEdge");
  return atexit(_E80_94);
}

//----- (0071C1A0) --------------------------------------------------------  // acclient.c:814341
int _E82_62()
{
  PStringBase<char>::PStringBase<char>(&KW_CHILD_1, "Child");
  return atexit(_E83_58);
}

//----- (0071C1C0) --------------------------------------------------------  // acclient.c:814348
int _E85_45()
{
  PStringBase<char>::PStringBase<char>(&KW_CODE_1, "Code");
  return atexit(_E86_37);
}

//----- (0071C1E0) --------------------------------------------------------  // acclient.c:814355
int _E88_34()
{
  PStringBase<char>::PStringBase<char>(&KW_DEFAULTSTATE_1, "DefaultState");
  return atexit(_E89_47);
}

//----- (0071C200) --------------------------------------------------------  // acclient.c:814362
int sub_71C200()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYHEIGHT_1, "DisplayHeight");
  return atexit(_E92_56);
}

//----- (0071C220) --------------------------------------------------------  // acclient.c:814369
int _E94_47()
{
  PStringBase<char>::PStringBase<char>(&KW_DISPLAYWIDTH_1, "DisplayWidth");
  return atexit(sub_788190);
}

//----- (0071C240) --------------------------------------------------------  // acclient.c:814376
int sub_71C240()
{
  PStringBase<char>::PStringBase<char>(&KW_DRAWMODE_1, "DrawMode");
  return atexit(sub_7881C0);
}

//----- (0071C260) --------------------------------------------------------  // acclient.c:814383
int sub_71C260()
{
  PStringBase<char>::PStringBase<char>(&KW_DURATION_1, "Duration");
  return atexit(sub_7881F0);
}

//----- (0071C280) --------------------------------------------------------  // acclient.c:814390
int sub_71C280()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENT_1, "Element");
  return atexit(sub_788220);
}

//----- (0071C2A0) --------------------------------------------------------  // acclient.c:814397
int sub_71C2A0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTHEADER_1, "ElementHeader");
  return atexit(sub_788250);
}

//----- (0071C2C0) --------------------------------------------------------  // acclient.c:814404
int _E109_95()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTWHEADER_1, "ElementWHeader");
  return atexit(sub_788280);
}

//----- (0071C2E0) --------------------------------------------------------  // acclient.c:814411
int sub_71C2E0()
{
  PStringBase<char>::PStringBase<char>(&KW_ELEMENTID_1, "ElementID");
  return atexit(_E113_80);
}

//----- (0071C300) --------------------------------------------------------  // acclient.c:814418
int sub_71C300()
{
  PStringBase<char>::PStringBase<char>(&KW_ENDALPHA_1, "EndAlpha");
  return atexit(_E116_72);
}

//----- (0071C320) --------------------------------------------------------  // acclient.c:814425
int _E118_90()
{
  PStringBase<char>::PStringBase<char>(&KW_ENGINETYPE_1, "EngineType");
  return atexit(_E119_95);
}

//----- (0071C340) --------------------------------------------------------  // acclient.c:814432
int _E121_81()
{
  PStringBase<char>::PStringBase<char>(&KW_EVENTID_1, "EventID");
  return atexit(sub_788340);
}

//----- (0071C360) --------------------------------------------------------  // acclient.c:814439
int _E124_81()
{
  PStringBase<char>::PStringBase<char>(&KW_FILE_1, "File");
  return atexit(_E125_75);
}

//----- (0071C380) --------------------------------------------------------  // acclient.c:814446
int _E127_68()
{
  PStringBase<char>::PStringBase<char>(&KW_FRAMES_1, "Frames");
  return atexit(_E128_73);
}

//----- (0071C3A0) --------------------------------------------------------  // acclient.c:814453
int _E130_61()
{
  PStringBase<char>::PStringBase<char>(&KW_HEADER_1, "PREPROC_HEADER");
  return atexit(_E131_62);
}

//----- (0071C3C0) --------------------------------------------------------  // acclient.c:814460
int _E133_54()
{
  PStringBase<char>::PStringBase<char>(&KW_HEIGHT_1, "Height");
  return atexit(_E134_46);
}

//----- (0071C3E0) --------------------------------------------------------  // acclient.c:814467
int _E136_38()
{
  PStringBase<char>::PStringBase<char>(&KW_JUMPITEMINDEX_1, "JumpItemIndex");
  return atexit(_E137_45);
}

//----- (0071C400) --------------------------------------------------------  // acclient.c:814474
int _E139_38()
{
  PStringBase<char>::PStringBase<char>(&KW_LEFTEDGE_1, "LeftEdge");
  return atexit(_E140_39);
}

//----- (0071C420) --------------------------------------------------------  // acclient.c:814481
int _E142_35()
{
  PStringBase<char>::PStringBase<char>(&KW_MAXDURATION_1, "MaxDuration");
  return atexit(_E143_39);
}

//----- (0071C440) --------------------------------------------------------  // acclient.c:814488
int _E145_37()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIA_1, "Media");
  return atexit(_E146_39);
}

//----- (0071C460) --------------------------------------------------------  // acclient.c:814495
int _E148_36()
{
  PStringBase<char>::PStringBase<char>(&KW_MEDIATYPE_1, "MediaType");
  return atexit(_E149_38);
}

//----- (0071C480) --------------------------------------------------------  // acclient.c:814502
int _E151_34()
{
  PStringBase<char>::PStringBase<char>(&KW_MINDURATION_1, "MinDuration");
  return atexit(_E152_39);
}

//----- (0071C4A0) --------------------------------------------------------  // acclient.c:814509
int _E154_35()
{
  PStringBase<char>::PStringBase<char>(&KW_NO_DB_FILE_1, "NoDBFile");
  return atexit(_E155_35);
}

//----- (0071C4C0) --------------------------------------------------------  // acclient.c:814516
int _E157_32()
{
  PStringBase<char>::PStringBase<char>(&KW_STRETCH_TO_FULL_SCREEN_1, "StretchToFullScreen");
  return atexit(_E158_36);
}

//----- (0071C4E0) --------------------------------------------------------  // acclient.c:814523
int _E160_35()
{
  PStringBase<char>::PStringBase<char>(&KW_PASSTOCHILDREN_1, "PassToChildren");
  return atexit(_E161_33);
}

//----- (0071C500) --------------------------------------------------------  // acclient.c:814530
int _E163_28()
{
  PStringBase<char>::PStringBase<char>(&KW_PROBABILITY_1, "Probability");
  return atexit(_E164_35);
}

//----- (0071C520) --------------------------------------------------------  // acclient.c:814537
int _E166_30()
{
  PStringBase<char>::PStringBase<char>(&KW_PROPERTIES_2, "Properties");
  return atexit(_E167_31);
}

//----- (0071C540) --------------------------------------------------------  // acclient.c:814544
int _E169_28()
{
  PStringBase<char>::PStringBase<char>(&KW_REMOVE_1, "Remove");
  return atexit(_E170_31);
}

//----- (0071C560) --------------------------------------------------------  // acclient.c:814551
int _E172_26()
{
  PStringBase<char>::PStringBase<char>(&KW_RIGHTEDGE_1, "RightEdge");
  return atexit(_E173_26);
}

//----- (0071C580) --------------------------------------------------------  // acclient.c:814558
int _E175_23()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDNAME_1, "SoundName");
  return atexit(_E176_28);
}

//----- (0071C5A0) --------------------------------------------------------  // acclient.c:814565
int _E178_23()
{
  PStringBase<char>::PStringBase<char>(&KW_SOUNDTABLE_1, "SoundTable");
  return atexit(_E179_27);
}

//----- (0071C5C0) --------------------------------------------------------  // acclient.c:814572
int _E181_23()
{
  PStringBase<char>::PStringBase<char>(&KW_STARTALPHA_1, "StartAlpha");
  return atexit(_E182_27);
}

//----- (0071C5E0) --------------------------------------------------------  // acclient.c:814579
int _E184_21()
{
  PStringBase<char>::PStringBase<char>(&KW_STATE_1, "State");
  return atexit(_E185_24);
}

//----- (0071C600) --------------------------------------------------------  // acclient.c:814586
int _E187_20()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEHEADER_1, "StateHeader");
  return atexit(_E188_25);
}

//----- (0071C620) --------------------------------------------------------  // acclient.c:814593
int _E190_21()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEWHEADER_1, "StateWHeader");
  return atexit(_E191_24);
}

//----- (0071C640) --------------------------------------------------------  // acclient.c:814600
int _E193_20()
{
  PStringBase<char>::PStringBase<char>(&KW_STATEID_1, "StateID");
  return atexit(_E194_31);
}

//----- (0071C660) --------------------------------------------------------  // acclient.c:814607
int _E196_27()
{
  PStringBase<char>::PStringBase<char>(&KW_TOPEDGE_1, "TopEdge");
  return atexit(_E197_21);
}

//----- (0071C680) --------------------------------------------------------  // acclient.c:814614
int _E199_19()
{
  PStringBase<char>::PStringBase<char>(&KW_TYPE_1, "Type");
  return atexit(_E200_25);
}

//----- (0071C6A0) --------------------------------------------------------  // acclient.c:814621
int _E202_23()
{
  PStringBase<char>::PStringBase<char>(&KW_WIDTH_1, "Width");
  return atexit(_E203_24);
}

//----- (0071C6C0) --------------------------------------------------------  // acclient.c:814628
int _E205_21()
{
  PStringBase<char>::PStringBase<char>(&KW_X_1, "X");
  return atexit(_E206_28);
}

//----- (0071C6E0) --------------------------------------------------------  // acclient.c:814635
int _E208_25()
{
  PStringBase<char>::PStringBase<char>(&KW_XHOTSPOT_1, "XHotspot");
  return atexit(_E209_22);
}

//----- (0071C700) --------------------------------------------------------  // acclient.c:814642
int _E211_20()
{
  PStringBase<char>::PStringBase<char>(&KW_Y_1, "Y");
  return atexit(_E212_25);
}

//----- (0071C720) --------------------------------------------------------  // acclient.c:814649
int _E214_22()
{
  PStringBase<char>::PStringBase<char>(&KW_YHOTSPOT_1, "YHotspot");
  return atexit(_E215_22);
}

//----- (0071C740) --------------------------------------------------------  // acclient.c:814656
int _E217_19()
{
  PStringBase<char>::PStringBase<char>(&KW_ZLEVEL_1, "ZLevel");
  return atexit(_E218_22);
}

//----- (0071C760) --------------------------------------------------------  // acclient.c:814663
int _E220_19()
{
  PStringBase<char>::PStringBase<char>(&KW_COMMENTS_1, "Comments");
  return atexit(_E221_22);
}

//----- (0071C780) --------------------------------------------------------  // acclient.c:814670
int _E223_20()
{
  PStringBase<char>::PStringBase<char>(&KW_HAS_ALPHA_1, "HasAlpha");
  return atexit(_E224_22);
}

//----- (00788040) --------------------------------------------------------  // acclient.c:927689
void __cdecl sub_788040()
{
  char *v0; // esi@1

  v0 = &KW_NULL_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NULL_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788070) --------------------------------------------------------  // acclient.c:927702
void __cdecl sub_788070()
{
  char *v0; // esi@1

  v0 = &KW_BASE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BASE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007880A0) --------------------------------------------------------  // acclient.c:927715
void __cdecl _E80_94()
{
  char *v0; // esi@1

  v0 = &KW_BOTTOMEDGE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_BOTTOMEDGE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007880D0) --------------------------------------------------------  // acclient.c:927728
void __cdecl _E83_58()
{
  char *v0; // esi@1

  v0 = &KW_CHILD_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CHILD_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788100) --------------------------------------------------------  // acclient.c:927741
void __cdecl _E86_37()
{
  char *v0; // esi@1

  v0 = &KW_CODE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_CODE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788130) --------------------------------------------------------  // acclient.c:927754
void __cdecl _E89_47()
{
  char *v0; // esi@1

  v0 = &KW_DEFAULTSTATE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DEFAULTSTATE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788160) --------------------------------------------------------  // acclient.c:927767
void __cdecl _E92_56()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYHEIGHT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYHEIGHT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788190) --------------------------------------------------------  // acclient.c:927780
void __cdecl sub_788190()
{
  char *v0; // esi@1

  v0 = &KW_DISPLAYWIDTH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DISPLAYWIDTH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007881C0) --------------------------------------------------------  // acclient.c:927793
void __cdecl sub_7881C0()
{
  char *v0; // esi@1

  v0 = &KW_DRAWMODE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DRAWMODE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007881F0) --------------------------------------------------------  // acclient.c:927806
void __cdecl sub_7881F0()
{
  char *v0; // esi@1

  v0 = &KW_DURATION_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_DURATION_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788220) --------------------------------------------------------  // acclient.c:927819
void __cdecl sub_788220()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788250) --------------------------------------------------------  // acclient.c:927832
void __cdecl sub_788250()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTHEADER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTHEADER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788280) --------------------------------------------------------  // acclient.c:927845
void __cdecl sub_788280()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTWHEADER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTWHEADER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007882B0) --------------------------------------------------------  // acclient.c:927858
void __cdecl _E113_80()
{
  char *v0; // esi@1

  v0 = &KW_ELEMENTID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ELEMENTID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007882E0) --------------------------------------------------------  // acclient.c:927871
void __cdecl _E116_72()
{
  char *v0; // esi@1

  v0 = &KW_ENDALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENDALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788310) --------------------------------------------------------  // acclient.c:927884
void __cdecl _E119_95()
{
  char *v0; // esi@1

  v0 = &KW_ENGINETYPE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ENGINETYPE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788340) --------------------------------------------------------  // acclient.c:927897
void __cdecl sub_788340()
{
  char *v0; // esi@1

  v0 = &KW_EVENTID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_EVENTID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788370) --------------------------------------------------------  // acclient.c:927910
void __cdecl _E125_75()
{
  char *v0; // esi@1

  v0 = &KW_FILE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FILE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007883A0) --------------------------------------------------------  // acclient.c:927923
void __cdecl _E128_73()
{
  char *v0; // esi@1

  v0 = &KW_FRAMES_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_FRAMES_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007883D0) --------------------------------------------------------  // acclient.c:927936
void __cdecl _E131_62()
{
  char *v0; // esi@1

  v0 = &KW_HEADER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEADER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788400) --------------------------------------------------------  // acclient.c:927949
void __cdecl _E134_46()
{
  char *v0; // esi@1

  v0 = &KW_HEIGHT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HEIGHT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788430) --------------------------------------------------------  // acclient.c:927962
void __cdecl _E137_45()
{
  char *v0; // esi@1

  v0 = &KW_JUMPITEMINDEX_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_JUMPITEMINDEX_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788460) --------------------------------------------------------  // acclient.c:927975
void __cdecl _E140_39()
{
  char *v0; // esi@1

  v0 = &KW_LEFTEDGE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_LEFTEDGE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788490) --------------------------------------------------------  // acclient.c:927988
void __cdecl _E143_39()
{
  char *v0; // esi@1

  v0 = &KW_MAXDURATION_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MAXDURATION_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007884C0) --------------------------------------------------------  // acclient.c:928001
void __cdecl _E146_39()
{
  char *v0; // esi@1

  v0 = &KW_MEDIA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007884F0) --------------------------------------------------------  // acclient.c:928014
void __cdecl _E149_38()
{
  char *v0; // esi@1

  v0 = &KW_MEDIATYPE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MEDIATYPE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788520) --------------------------------------------------------  // acclient.c:928027
void __cdecl _E152_39()
{
  char *v0; // esi@1

  v0 = &KW_MINDURATION_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_MINDURATION_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788550) --------------------------------------------------------  // acclient.c:928040
void __cdecl _E155_35()
{
  char *v0; // esi@1

  v0 = &KW_NO_DB_FILE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_NO_DB_FILE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788580) --------------------------------------------------------  // acclient.c:928053
void __cdecl _E158_36()
{
  char *v0; // esi@1

  v0 = &KW_STRETCH_TO_FULL_SCREEN_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STRETCH_TO_FULL_SCREEN_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007885B0) --------------------------------------------------------  // acclient.c:928066
void __cdecl _E161_33()
{
  char *v0; // esi@1

  v0 = &KW_PASSTOCHILDREN_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PASSTOCHILDREN_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007885E0) --------------------------------------------------------  // acclient.c:928079
void __cdecl _E164_35()
{
  char *v0; // esi@1

  v0 = &KW_PROBABILITY_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROBABILITY_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788610) --------------------------------------------------------  // acclient.c:928092
void __cdecl _E167_31()
{
  char *v0; // esi@1

  v0 = &KW_PROPERTIES_2.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_PROPERTIES_2.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788640) --------------------------------------------------------  // acclient.c:928105
void __cdecl _E170_31()
{
  char *v0; // esi@1

  v0 = &KW_REMOVE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_REMOVE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788670) --------------------------------------------------------  // acclient.c:928118
void __cdecl _E173_26()
{
  char *v0; // esi@1

  v0 = &KW_RIGHTEDGE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_RIGHTEDGE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007886A0) --------------------------------------------------------  // acclient.c:928131
void __cdecl _E176_28()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDNAME_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDNAME_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007886D0) --------------------------------------------------------  // acclient.c:928144
void __cdecl _E179_27()
{
  char *v0; // esi@1

  v0 = &KW_SOUNDTABLE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_SOUNDTABLE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788700) --------------------------------------------------------  // acclient.c:928157
void __cdecl _E182_27()
{
  char *v0; // esi@1

  v0 = &KW_STARTALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STARTALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788730) --------------------------------------------------------  // acclient.c:928170
void __cdecl _E185_24()
{
  char *v0; // esi@1

  v0 = &KW_STATE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788760) --------------------------------------------------------  // acclient.c:928183
void __cdecl _E188_25()
{
  char *v0; // esi@1

  v0 = &KW_STATEHEADER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEHEADER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788790) --------------------------------------------------------  // acclient.c:928196
void __cdecl _E191_24()
{
  char *v0; // esi@1

  v0 = &KW_STATEWHEADER_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEWHEADER_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007887C0) --------------------------------------------------------  // acclient.c:928209
void __cdecl _E194_31()
{
  char *v0; // esi@1

  v0 = &KW_STATEID_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_STATEID_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007887F0) --------------------------------------------------------  // acclient.c:928222
void __cdecl _E197_21()
{
  char *v0; // esi@1

  v0 = &KW_TOPEDGE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TOPEDGE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788820) --------------------------------------------------------  // acclient.c:928235
void __cdecl _E200_25()
{
  char *v0; // esi@1

  v0 = &KW_TYPE_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_TYPE_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788850) --------------------------------------------------------  // acclient.c:928248
void __cdecl _E203_24()
{
  char *v0; // esi@1

  v0 = &KW_WIDTH_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_WIDTH_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788880) --------------------------------------------------------  // acclient.c:928261
void __cdecl _E206_28()
{
  char *v0; // esi@1

  v0 = &KW_X_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_X_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007888B0) --------------------------------------------------------  // acclient.c:928274
void __cdecl _E209_22()
{
  char *v0; // esi@1

  v0 = &KW_XHOTSPOT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_XHOTSPOT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007888E0) --------------------------------------------------------  // acclient.c:928287
void __cdecl _E212_25()
{
  char *v0; // esi@1

  v0 = &KW_Y_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_Y_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788910) --------------------------------------------------------  // acclient.c:928300
void __cdecl _E215_22()
{
  char *v0; // esi@1

  v0 = &KW_YHOTSPOT_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_YHOTSPOT_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788940) --------------------------------------------------------  // acclient.c:928313
void __cdecl _E218_22()
{
  char *v0; // esi@1

  v0 = &KW_ZLEVEL_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_ZLEVEL_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00788970) --------------------------------------------------------  // acclient.c:928326
void __cdecl _E221_22()
{
  char *v0; // esi@1

  v0 = &KW_COMMENTS_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_COMMENTS_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007889A0) --------------------------------------------------------  // acclient.c:928339
void __cdecl _E224_22()
{
  char *v0; // esi@1

  v0 = &KW_HAS_ALPHA_1.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&KW_HAS_ALPHA_1.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

