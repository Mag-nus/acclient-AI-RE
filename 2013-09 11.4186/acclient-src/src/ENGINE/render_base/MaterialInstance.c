/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : MaterialInstance
   Object     : ENGINE\render_base\MaterialInstance.obj
   Functions  : 829
   Addresses  : 0044CFB0 - 0074AF50 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0044CFB0) --------------------------------------------------------  // acclient.c:138063
char __thiscall MaterialInstance::Refresh(MaterialInstance *this, IDClass<_tagDataID,32,0> sub_did)
{
  char result; // al@1

  result = 1;
  this->m_bNeedRefresh = 1;
  return result;
}

//----- (0044CFC0) --------------------------------------------------------  // acclient.c:138073
void __thiscall MaterialInstance::Begin(MaterialInstance *this)
{
  PSRefBufferCharData<char> *v1; // edi@1
  volatile LONG *v2; // ebp@1
  MaterialInstance *v3; // esi@1
  PSRefBufferCharData<char> *v4; // eax@1
  int v5; // ebx@2
  int v6; // edi@6
  PSRefBufferCharData<char> *v7; // edi@9
  int v8; // edi@10
  volatile LONG *v9; // ST00_4@13

  v1 = PStringBase<char>::s_NullBuffer.m_charbuffer;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v3 = this;
  InterlockedIncrement((volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1]);
  v4 = v3->m_materialName.m_charbuffer;
  if ( v4 != v1 )
  {
    v5 = (int)&v4[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v4[-1]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    v3->m_materialName.m_charbuffer = v1;
    InterlockedIncrement(v2);
  }
  v6 = (int)&v1[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v6 + 4)) && v6 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v6)(v6, 1);
  v3->m_materialID.id = INVALID_DID_43.id;
  v7 = v3->m_materialTypeName.m_charbuffer;
  if ( v7 != PStringBase<char>::s_NullBuffer.m_charbuffer )
  {
    v8 = (int)&v7[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)(v8 + 4)) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
    v3->m_materialTypeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
    InterlockedIncrement(v9);
  }
  v3->m_materialType = 2;
  v3->m_AllowStencilShadows = 1;
  v3->m_WantDiscardGeometry = 0;
  v3->m_pMaterial = 0;
  v3->m_pModifiedMaterial = 0;
  v3->m_bNeedRefresh = 1;
}

//----- (0044D090) --------------------------------------------------------  // acclient.c:138121
void __thiscall MaterialInstance::GetSubDataIDs(MaterialInstance *this, QualifiedDataIDArray *id_array)
{
  MaterialInstance *v2; // esi@1
  unsigned int v3; // eax@1
  QualifiedDataID *v4; // eax@2
  unsigned int v5; // edi@3
  ModifierRef *v6; // eax@4
  IDClass<_tagDataID,32,0> v7; // eax@5
  QualifiedDataID *v8; // eax@6
  QualifiedDataID v9; // [sp+Ch] [bp-8h]@2

  v2 = this;
  v3 = this->m_materialID.id;
  if ( v3 != INVALID_DID_43.id )
  {
    QualifiedDataID::QualifiedDataID(&v9, (IDClass<_tagDataID,32,0>)v3, 0);
    QualifiedDataIDArray::AddQDID(id_array, v4, 0);
  }
  v5 = 0;
  if ( v2->m_aModifierRefs.m_num )
  {
    do
    {
      v6 = v2->m_aModifierRefs.m_data[v5];
      if ( v6 )
      {
        v7.id = v6->id.id;
        if ( v7.id != INVALID_DID_43.id )
        {
          QualifiedDataID::QualifiedDataID(&v9, v7, 0);
          QualifiedDataIDArray::AddQDID(id_array, v8, 0);
        }
      }
      ++v5;
    }
    while ( v5 < v2->m_aModifierRefs.m_num );
  }
}

//----- (0044D110) --------------------------------------------------------  // acclient.c:138161
char __thiscall MaterialInstance::ReleaseSubObjects(MaterialInstance *this)
{
  MaterialInstance *v1; // esi@1
  RenderMaterial *v2; // ecx@1
  RenderMaterial *v3; // ecx@3
  unsigned int i; // edi@5
  MaterialModifier *v5; // ecx@6
  unsigned int v6; // eax@9
  unsigned int v7; // ecx@9
  char result; // al@10
  int j; // eax@12

  v1 = this;
  v2 = this->m_pModifiedMaterial;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pModifiedMaterial = 0;
  }
  v3 = v1->m_pMaterial;
  if ( v3 )
  {
    ((void (*)(void))v3->vfptr->Release)();
    v1->m_pMaterial = 0;
  }
  for ( i = 0; i < v1->m_aModifiers.m_num; ++i )
  {
    v5 = v1->m_aModifiers.m_data[i];
    if ( v5 )
    {
      ((void (*)(void))v5->vfptr->Release)();
      v1->m_aModifiers.m_data[i] = 0;
    }
  }
  v6 = v1->m_aModifiers.m_sizeAndDeallocate;
  v7 = v1->m_aModifiers.m_sizeAndDeallocate & 0x80000000;
  v1->m_aModifiers.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_aModifiers.m_data);
    v1->m_aModifiers.m_data = 0;
    v1->m_aModifiers.m_sizeAndDeallocate = 0;
    result = 1;
  }
  else
  {
    if ( v1->m_aModifiers.m_data )
    {
      for ( j = (v6 & 0x7FFFFFFF) - 1; j >= 0; v1->m_aModifiers.m_data[j + 1] = 0 )
        --j;
    }
    result = 1;
  }
  return result;
}

//----- (0044D1B0) --------------------------------------------------------  // acclient.c:138218
void __thiscall MaterialInstance::MaterialInstance(MaterialInstance *this)
{
  MaterialInstance *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  volatile LONG *v3; // ST00_4@1

  v1 = this;
  DBObj::DBObj((DBObj *)&this->vfptr, INVALID_DID_43);
  v1->vfptr = (InterfaceVtbl *)&MaterialInstance::vftable;
  v2 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_materialName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v2);
  v3 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
  v1->m_materialTypeName.m_charbuffer = PStringBase<char>::s_NullBuffer.m_charbuffer;
  InterlockedIncrement(v3);
  v1->m_aModifierRefs.m_data = 0;
  v1->m_aModifierRefs.m_sizeAndDeallocate = 0;
  v1->m_aModifierRefs.m_num = 0;
  v1->m_aModifiers.m_data = 0;
  v1->m_aModifiers.m_sizeAndDeallocate = 0;
  v1->m_aModifiers.m_num = 0;
  MaterialInstance::Begin(v1);
}
// 79B2E0: using guessed type __int32 (__stdcall *MaterialInstance::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0044D210) --------------------------------------------------------  // acclient.c:138244
signed int MaterialInstance::GetDBOType()
{
  return 33;
}

//----- (0044D230) --------------------------------------------------------  // acclient.c:138250
void __cdecl MaterialInstance::Allocator()
{
  MaterialInstance *v0; // eax@1

  v0 = (MaterialInstance *)operator new(0x68u);
  if ( v0 )
    MaterialInstance::MaterialInstance(v0);
}

//----- (0044D250) --------------------------------------------------------  // acclient.c:138260
void __thiscall MaterialInstance::End(MaterialInstance *this)
{
  MaterialInstance *v1; // esi@1
  RenderMaterial *v2; // ecx@1
  unsigned int i; // ebp@3
  void *v4; // ebx@4
  int v5; // edi@5
  unsigned int v6; // eax@10
  unsigned int v7; // edx@10
  int j; // eax@13

  v1 = this;
  MaterialInstance::ReleaseSubObjects(this);
  v2 = v1->m_pModifiedMaterial;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_pModifiedMaterial = 0;
  }
  for ( i = 0; i < v1->m_aModifierRefs.m_num; ++i )
  {
    v4 = v1->m_aModifierRefs.m_data[i];
    if ( v4 )
    {
      v5 = *(_DWORD *)v4 - 20;
      if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      operator delete(v4);
    }
    v1->m_aModifierRefs.m_data[i] = 0;
  }
  v6 = v1->m_aModifierRefs.m_sizeAndDeallocate;
  v7 = v1->m_aModifierRefs.m_sizeAndDeallocate & 0x80000000;
  v1->m_aModifierRefs.m_num = 0;
  if ( v7 == 0x80000000 )
  {
    operator delete[](v1->m_aModifierRefs.m_data);
    v1->m_aModifierRefs.m_data = 0;
    v1->m_aModifierRefs.m_sizeAndDeallocate = 0;
  }
  else if ( v1->m_aModifierRefs.m_data )
  {
    for ( j = (v6 & 0x7FFFFFFF) - 1; j >= 0; v1->m_aModifierRefs.m_data[j + 1] = 0 )
      --j;
  }
}

//----- (0044D300) --------------------------------------------------------  // acclient.c:138308
char __thiscall MaterialInstance::CopyInto(MaterialInstance *this, DBObj *retval)
{
  char *v2; // esi@1
  InterfaceVtbl *v3; // eax@1
  int v4; // ebx@2
  InterfaceVtbl *v5; // esi@5
  PSRefBufferCharData<char> *v6; // eax@6
  int v7; // edi@6
  int v8; // esi@7
  int v9; // eax@10
  MaterialInstance *v10; // eax@11
  unsigned int v11; // ebx@11
  void *v12; // eax@13
  void *v13; // esi@13
  volatile LONG *v14; // ST00_4@14
  ModifierRef *v15; // edi@14
  int v16; // eax@14
  int v17; // ebx@15
  PSRefBufferCharData<char> *v18; // eax@18
  int v19; // eax@19
  unsigned int v20; // eax@20
  RenderMaterial *v21; // ecx@23
  MaterialInstance *v22; // eax@26
  int v23; // ecx@26
  int v24; // esi@27
  MaterialModifier *v25; // ecx@27
  int v26; // ebx@29
  unsigned int v27; // eax@29
  unsigned int v28; // edx@30
  int v29; // ST1C_4@35
  RenderMaterial *v35; // ecx@40
  MaterialInstance *v37; // [sp+10h] [bp-Ch]@1
  unsigned int im; // [sp+14h] [bp-8h]@11
  unsigned int ima; // [sp+14h] [bp-8h]@26

  v37 = this;
  v2 = (char *)&this->m_materialName;
  v3 = retval[1].vfptr;
  if ( (PSRefBufferCharData<char> *)v3 != this->m_materialName.m_charbuffer )
  {
    v4 = (int)&v3[-1].IUnknown_AddRef;
    if ( !InterlockedDecrement((volatile LONG *)&v3[-1].IUnknown_Release) && v4 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    v5 = *(InterfaceVtbl **)v2;
    retval[1].vfptr = v5;
    InterlockedIncrement((volatile LONG *)&v5[-1].IUnknown_Release);
    this = v37;
  }
  retval[1].m_dataCategory = this->m_materialID.id;
  v6 = *(PSRefBufferCharData<char> **)&retval[1].m_bLoaded;
  v7 = (int)&v37->m_materialTypeName;
  if ( v6 != v37->m_materialTypeName.m_charbuffer )
  {
    v8 = (int)&v6[-2].m_data[12];
    if ( !InterlockedDecrement((volatile LONG *)&v6[-1]) && v8 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v8)(v8, 1);
    v9 = *(_DWORD *)v7;
    *(_DWORD *)&retval[1].m_bLoaded = *(_DWORD *)v7;
    InterlockedIncrement((volatile LONG *)(v9 - 16));
  }
  *((_DWORD *)&retval[1].m_bLoaded + 1) = v37->m_materialType;
  LOBYTE(retval[1].m_pLast) = v37->m_AllowStencilShadows;
  BYTE1(retval[1].m_pLast) = v37->m_WantDiscardGeometry;
  v10 = v37;
  v11 = 0;
  im = 0;
  if ( v37->m_aModifierRefs.m_num )
  {
    while ( v10->m_aModifierRefs.m_data[v11] )
    {
      v12 = operator new(8u);
      v13 = v12;
      if ( !v12 )
        break;
      v14 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
      *(_DWORD *)v12 = PStringBase<char>::s_NullBuffer.m_charbuffer;
      InterlockedIncrement(v14);
      v15 = v37->m_aModifierRefs.m_data[v11];
      v16 = *(_DWORD *)v13;
      if ( *(PSRefBufferCharData<char> **)v13 != v15->name.m_charbuffer )
      {
        v17 = v16 - 20;
        if ( !InterlockedDecrement((volatile LONG *)(v16 - 20 + 4)) && v17 )
          (**(void (__thiscall ***)(_DWORD, _DWORD))v17)(v17, 1);
        v18 = v15->name.m_charbuffer;
        *(_DWORD *)v13 = v15->name.m_charbuffer;
        InterlockedIncrement((volatile LONG *)&v18[-1]);
        v11 = im;
      }
      *((_DWORD *)v13 + 1) = v15->id.id;
      v19 = HIDWORD(retval[1].m_timeStamp) & 0x7FFFFFFF;
      if ( retval[1].m_pNext < (DBObj *)v19
        || (v20 = SmartArray<UIChildFramework *,1>::get_new_size(v19 + 1),
            SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&retval[1].m_timeStamp, v20)) )
        *(_DWORD *)(LODWORD(retval[1].m_timeStamp) + 4 * (unsigned int)retval[1].m_pNext++) = v13;
      v10 = v37;
      ++v11;
      im = v11;
      if ( v11 >= v37->m_aModifierRefs.m_num )
        goto LABEL_23;
    }
    return 0;
  }
LABEL_23:
  retval[1].m_pMaintainer = 0;
  v21 = v37->m_pMaterial;
  if ( v21 )
  {
    if ( !((int (*)(void))v21->vfptr->AddRef)() )
      return 0;
    retval[1].m_pMaintainer = (DBOCache *)v37->m_pMaterial;
  }
  v22 = v37;
  v23 = 0;
  ima = 0;
  if ( v37->m_aModifiers.m_num )
  {
    do
    {
      v24 = v23;
      v25 = v22->m_aModifiers.m_data[v23];
      if ( v25 )
      {
        if ( !((int (*)(void))v25->vfptr->AddRef)() )
          return 0;
        v26 = (int)&v37->m_aModifiers.m_data[v24];
        v27 = retval[1].m_DID.id & 0x7FFFFFFF;
        if ( *(_DWORD *)&retval[1].m_AllowedInFreeList < v27 )
          goto LABEL_47;
        v28 = v27 + 1;
        if ( v27 + 1 > 8 )
        {
          if ( v28 <= 0x4000 )
          {
            v29 = v27 + 1;
            __asm { bsr     this, [esp+1Ch+var_4] }
            if ( v28 > 1 << _EAX )
              v28 = 2 * (1 << _EAX);
          }
          else if ( v28 & 0x3FFF )
          {
            v28 += 0x4000 - (v28 & 0x3FFF);
          }
        }
        else
        {
          v28 = 8;
        }
        if ( SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&retval[1].m_numLinks, v28) )
LABEL_47:
          *(_DWORD *)(retval[1].m_numLinks + 4 * (*(_DWORD *)&retval[1].m_AllowedInFreeList)++) = *(_DWORD *)v26;
      }
      v22 = v37;
      v23 = ima++ + 1;
    }
    while ( ima < v37->m_aModifiers.m_num );
  }
  retval[2].vfptr = 0;
  v35 = v37->m_pModifiedMaterial;
  if ( !v35 )
    goto LABEL_43;
  if ( ((int (*)(void))v35->vfptr->AddRef)() )
  {
    retval[2].vfptr = (InterfaceVtbl *)&v37->m_pModifiedMaterial->vfptr;
LABEL_43:
    LOBYTE(retval[2].m_dataCategory) = v37->m_bNeedRefresh;
    return 1;
  }
  return 0;
}

//----- (0044D5D0) --------------------------------------------------------  // acclient.c:138480
void __thiscall MaterialInstance::Destroy(MaterialInstance *this)
{
  MaterialInstance *v1; // esi@1

  v1 = this;
  MaterialInstance::End(this);
  MaterialInstance::Begin(v1);
}

//----- (0044D5E0) --------------------------------------------------------  // acclient.c:138490
char __thiscall MaterialInstance::GetSubObjects(MaterialInstance *this)
{
  MaterialInstance *v1; // esi@1
  unsigned int v2; // eax@1
  char v3; // bl@1
  QualifiedDataID *v4; // eax@2
  int v5; // eax@2
  unsigned int v6; // edi@4
  ModifierRef *v7; // eax@5
  IDClass<_tagDataID,32,0> v8; // eax@6
  QualifiedDataID *v9; // eax@7
  char result; // al@11
  MaterialModifier *modifier; // [sp+8h] [bp-10h]@2
  QualifiedDataID v12; // [sp+10h] [bp-8h]@7

  v1 = this;
  v2 = this->m_materialID.id;
  v3 = 1;
  if ( v2 == INVALID_DID_43.id )
  {
    result = 0;
  }
  else
  {
    QualifiedDataID::QualifiedDataID((QualifiedDataID *)&modifier, (IDClass<_tagDataID,32,0>)v2, 0x1Fu);
    v5 = DBObj::Get(v4);
    v1->m_pMaterial = (RenderMaterial *)v5;
    if ( !v5 )
      v3 = 0;
    v6 = 0;
    if ( v1->m_aModifierRefs.m_num )
    {
      do
      {
        v7 = v1->m_aModifierRefs.m_data[v6];
        if ( v7 )
        {
          v8.id = v7->id.id;
          if ( v8.id != INVALID_DID_43.id )
          {
            QualifiedDataID::QualifiedDataID(&v12, v8, 0x20u);
            modifier = (MaterialModifier *)DBObj::Get(v9);
            if ( modifier )
              SmartArray<UIElement_Button *,1>::AddToEnd(
                (SmartArray<BSPNODE *,1> *)&v1->m_aModifiers,
                (BSPNODE *const *)&modifier);
            else
              v3 = 0;
          }
        }
        ++v6;
      }
      while ( v6 < v1->m_aModifierRefs.m_num );
    }
    v1->m_bNeedRefresh = 1;
    result = v3;
  }
  return result;
}

//----- (0044D680) --------------------------------------------------------  // acclient.c:138551
void __thiscall MaterialInstance::Serialize(MaterialInstance *this, Archive *io_archive)
{
  Archive *v2; // esi@1
  MaterialInstance *v3; // ebp@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@5
  unsigned int v6; // edi@9
  unsigned int v7; // eax@9
  void *v8; // edi@15
  volatile LONG *v9; // ST00_4@16
  ModifierRef *v10; // ebx@16
  unsigned int v11; // eax@19
  int v12; // eax@24
  unsigned int v13; // eax@25
  bool v14; // bl@28
  unsigned int v15; // eax@28
  bool v16; // zf@33
  bool v17; // bl@37
  unsigned int v18; // eax@37
  bool v19; // zf@42
  unsigned int numModifiers; // [sp+10h] [bp-4h]@9
  Archive *io_archivea; // [sp+18h] [bp+4h]@13

  v2 = io_archive;
  v3 = this;
  DBObj::Serialize((DBObj *)&this->vfptr, io_archive);
  Archive::CheckAlignment(io_archive, 4u);
  v4 = Archive::GetBytes(io_archive, 4u);
  if ( v4 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v4 = v3->m_materialID.id;
    else
      v3->m_materialID.id = *(_DWORD *)v4;
  }
  Archive::CheckAlignment(io_archive, 4u);
  v5 = Archive::GetBytes(io_archive, 4u);
  if ( v5 )
  {
    if ( io_archive->m_flags & 1 )
      *(_DWORD *)v5 = v3->m_materialType;
    else
      v3->m_materialType = *(_DWORD *)v5;
  }
  v6 = v3->m_aModifierRefs.m_num;
  numModifiers = v3->m_aModifierRefs.m_num;
  Archive::CheckAlignment(io_archive, 4u);
  v7 = Archive::GetBytes(io_archive, 4u);
  if ( v7 )
  {
    if ( io_archive->m_flags & 1 )
    {
      *(_DWORD *)v7 = v6;
    }
    else
    {
      numModifiers = *(_DWORD *)v7;
      v6 = *(_DWORD *)v7;
    }
  }
  io_archivea = 0;
  if ( v6 )
  {
    do
    {
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v8 = operator new(8u);
        if ( v8 )
        {
          v9 = (volatile LONG *)&PStringBase<char>::s_NullBuffer.m_charbuffer[-1];
          *(_DWORD *)v8 = PStringBase<char>::s_NullBuffer.m_charbuffer;
          InterlockedIncrement(v9);
          v10 = (ModifierRef *)v8;
        }
        else
        {
          v10 = 0;
        }
      }
      else
      {
        v10 = v3->m_aModifierRefs.m_data[(_DWORD)io_archivea];
      }
      Archive::CheckAlignment(v2, 4u);
      v11 = Archive::GetBytes(v2, 4u);
      if ( v11 )
      {
        if ( v2->m_flags & 1 )
          *(_DWORD *)v11 = v10->id.id;
        else
          v10->id.id = *(_DWORD *)v11;
      }
      if ( ~LOBYTE(v2->m_flags) & 1 )
      {
        v12 = v3->m_aModifierRefs.m_sizeAndDeallocate & 0x7FFFFFFF;
        if ( v3->m_aModifierRefs.m_num < v12
          || (v13 = SmartArray<UIChildFramework *,1>::get_new_size(v12 + 1),
              SmartArray<int,1>::grow((SmartArray<QuickButton *,1> *)&v3->m_aModifierRefs, v13)) )
          v3->m_aModifierRefs.m_data[v3->m_aModifierRefs.m_num++] = v10;
      }
      io_archivea = (Archive *)((char *)io_archivea + 1);
    }
    while ( (unsigned int)io_archivea < numModifiers );
  }
  v14 = v3->m_AllowStencilShadows;
  Archive::CheckAlignment(v2, 1u);
  v15 = Archive::GetBytes(v2, 1u);
  if ( v15 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v15 = v14;
    else
      v14 = *(_BYTE *)v15;
  }
  if ( !(v2->m_flags & 5) )
  {
    v16 = v14 == 0;
    if ( !v14 )
      goto LABEL_37;
    if ( v14 != 1 )
      Archive::RaiseError(v2);
  }
  v16 = v14 == 0;
LABEL_37:
  v3->m_AllowStencilShadows = !v16;
  v17 = v3->m_WantDiscardGeometry;
  Archive::CheckAlignment(v2, 1u);
  v18 = Archive::GetBytes(v2, 1u);
  if ( v18 )
  {
    if ( v2->m_flags & 1 )
      *(_BYTE *)v18 = v17;
    else
      v17 = *(_BYTE *)v18;
  }
  if ( v2->m_flags & 5 )
    goto LABEL_45;
  v19 = v17 == 0;
  if ( v17 )
  {
    if ( v17 != 1 )
      Archive::RaiseError(v2);
LABEL_45:
    v19 = v17 == 0;
  }
  v3->m_WantDiscardGeometry = !v19;
}

//----- (0044D870) --------------------------------------------------------  // acclient.c:138701
void __thiscall MaterialInstance::~MaterialInstance(MaterialInstance *this)
{
  MaterialInstance *v1; // edi@1
  int v2; // esi@5
  int v3; // esi@8

  v1 = this;
  this->vfptr = (InterfaceVtbl *)&MaterialInstance::vftable;
  MaterialInstance::End(this);
  if ( (v1->m_aModifiers.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aModifiers.m_data);
  if ( (v1->m_aModifierRefs.m_sizeAndDeallocate & 0x80000000) == 0x80000000 )
    operator delete[](v1->m_aModifierRefs.m_data);
  v2 = (int)&v1->m_materialTypeName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v2 + 4)) && v2 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v2)(v2, 1);
  v3 = (int)&v1->m_materialName.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) && v3 )
    (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  DBObj::~DBObj((DBObj *)&v1->vfptr);
}
// 79B2E0: using guessed type __int32 (__stdcall *MaterialInstance::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (0044D900) --------------------------------------------------------  // acclient.c:138725
MaterialInstance *__thiscall MaterialInstance::vector_deleting_destructor(MaterialInstance *this, unsigned int a2)
{
  MaterialInstance *v2; // esi@1

  v2 = this;
  MaterialInstance::~MaterialInstance(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (006DACD0) --------------------------------------------------------  // acclient.c:752484
int _E73_48()
{
  PStringBase<char>::PStringBase<char>(&waveform_None_19, "None");
  return atexit(_E74_36);
}

//----- (006DACF0) --------------------------------------------------------  // acclient.c:752491
int _E76_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Speed_19, "Speed");
  return atexit(_E77_50);
}

//----- (006DAD10) --------------------------------------------------------  // acclient.c:752498
int _E79_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_Noise_19, "Noise");
  return atexit(_E80_24);
}

//----- (006DAD30) --------------------------------------------------------  // acclient.c:752505
int _E82_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Sine_19, "Sine");
  return atexit(_E83_14);
}

//----- (006DAD50) --------------------------------------------------------  // acclient.c:752512
int _E85_10()
{
  PStringBase<char>::PStringBase<char>(&waveform_Square_19, "Square");
  return atexit(_E86_11);
}

//----- (006DAD70) --------------------------------------------------------  // acclient.c:752519
int _E88_9()
{
  PStringBase<char>::PStringBase<char>(&waveform_Bounce_19, "Bounce");
  return atexit(_E89_22);
}

//----- (006DAD90) --------------------------------------------------------  // acclient.c:752526
int _E91_23()
{
  PStringBase<char>::PStringBase<char>(&waveform_Perlin_19, "Perlin");
  return atexit(_E92_24);
}

//----- (006DADB0) --------------------------------------------------------  // acclient.c:752533
int _E94_13()
{
  PStringBase<char>::PStringBase<char>(&waveform_Fractal_19, "Fractal");
  return atexit(sub_7464E0);
}

//----- (006DADD0) --------------------------------------------------------  // acclient.c:752540
int _E97_22()
{
  PStringBase<char>::PStringBase<char>(&waveform_FrameLoop_19, "FrameLoop");
  return atexit(_E98_39);
}

//----- (006DADF0) --------------------------------------------------------  // acclient.c:752547
void _E100_18()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_22, PFID_A8R8G8B8);
}

//----- (006DAE00) --------------------------------------------------------  // acclient.c:752553
int _E118_13()
{
  PStringBase<char>::PStringBase<char>(&PHeader_4, "PREPROC_HEADER");
  return atexit(_E119_62);
}

//----- (006DAE20) --------------------------------------------------------  // acclient.c:752560
int _E121_10()
{
  PStringBase<char>::PStringBase<char>(&VertexArray_4, "VertexArray");
  return atexit(_E122_49);
}

//----- (006DAE40) --------------------------------------------------------  // acclient.c:752567
int _E124_13()
{
  PStringBase<char>::PStringBase<char>(&BinaryVertexArray_4, "BinaryVertexArray");
  return atexit(_E125_24);
}

//----- (006DAE60) --------------------------------------------------------  // acclient.c:752574
int _E127_9()
{
  PStringBase<char>::PStringBase<char>(&VertexType_5, "VertexType");
  return atexit(_E128_25);
}

//----- (006DAE80) --------------------------------------------------------  // acclient.c:752581
int _E130_10()
{
  PStringBase<char>::PStringBase<char>(&VertexData_4, "VertexData");
  return atexit(_E131_21);
}

//----- (006DAEA0) --------------------------------------------------------  // acclient.c:752588
int _E133_9()
{
  PStringBase<char>::PStringBase<char>(&Vertex_4, "Vertex");
  return atexit(_E134_20);
}

//----- (006DAEC0) --------------------------------------------------------  // acclient.c:752595
int _E136_8()
{
  PStringBase<char>::PStringBase<char>(&Index_9, "Index");
  return atexit(_E137_20);
}

//----- (006DAEE0) --------------------------------------------------------  // acclient.c:752602
int _E139_7()
{
  PStringBase<char>::PStringBase<char>(&Origin_9, "P");
  return atexit(_E140_15);
}

//----- (006DAF00) --------------------------------------------------------  // acclient.c:752609
int _E142_7()
{
  PStringBase<char>::PStringBase<char>(&Normal_4, "N");
  return atexit(_E143_16);
}

//----- (006DAF20) --------------------------------------------------------  // acclient.c:752616
int _E145_6()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_9, "Diffuse");
  return atexit(_E146_15);
}

//----- (006DAF40) --------------------------------------------------------  // acclient.c:752623
int _E148_6()
{
  PStringBase<char>::PStringBase<char>(&Specular_9, "Specular");
  return atexit(_E149_15);
}

//----- (006DAF60) --------------------------------------------------------  // acclient.c:752630
int _E151_6()
{
  PStringBase<char>::PStringBase<char>(&UVS_4, "UVS");
  return atexit(_E152_14);
}

//----- (006DAF80) --------------------------------------------------------  // acclient.c:752637
int _E154_7()
{
  PStringBase<char>::PStringBase<char>(&VectorS_4, "VectorS");
  return atexit(_E155_12);
}

//----- (006DAFA0) --------------------------------------------------------  // acclient.c:752644
int _E157_6()
{
  PStringBase<char>::PStringBase<char>(&VectorT_4, "VectorT");
  return atexit(_E158_15);
}

//----- (006DAFC0) --------------------------------------------------------  // acclient.c:752651
int _E160_7()
{
  PStringBase<char>::PStringBase<char>(&VectorSxT_4, "VectorSxT");
  return atexit(_E161_12);
}

//----- (006DAFE0) --------------------------------------------------------  // acclient.c:752658
int _E163_5()
{
  PStringBase<char>::PStringBase<char>(&Weights_4, "Weights");
  return atexit(_E164_15);
}

//----- (006DB000) --------------------------------------------------------  // acclient.c:752665
int _E166_6()
{
  PStringBase<char>::PStringBase<char>(&Importance_4, "Importance");
  return atexit(_E167_11);
}

//----- (006DB020) --------------------------------------------------------  // acclient.c:752672
int _E169_4()
{
  PStringBase<char>::PStringBase<char>(&PhysMtl_4, "PhysMtl");
  return atexit(_E170_10);
}

//----- (006DB040) --------------------------------------------------------  // acclient.c:752679
int _E172_4()
{
  PStringBase<char>::PStringBase<char>(&Material_20, "Material");
  return atexit(_E173_9);
}

//----- (006DB060) --------------------------------------------------------  // acclient.c:752686
int _E175_4()
{
  PStringBase<char>::PStringBase<char>(&ID_10, "ID");
  return atexit(_E176_10);
}

//----- (006DB080) --------------------------------------------------------  // acclient.c:752693
int _E178_4()
{
  PStringBase<char>::PStringBase<char>(&FileName_4, "FileName");
  return atexit(_E179_9);
}

//----- (006DB0A0) --------------------------------------------------------  // acclient.c:752700
int _E181_4()
{
  PStringBase<char>::PStringBase<char>(&Polygon_9, "Polygon");
  return atexit(_E182_9);
}

//----- (006DB0C0) --------------------------------------------------------  // acclient.c:752707
int _E184_2()
{
  PStringBase<char>::PStringBase<char>(&ID_11, "ID");
  return atexit(_E185_6);
}

//----- (006DB0E0) --------------------------------------------------------  // acclient.c:752714
int _E187_2()
{
  PStringBase<char>::PStringBase<char>(&Indices_6, "INDICES");
  return atexit(_E188_7);
}

//----- (006DB100) --------------------------------------------------------  // acclient.c:752721
int _E190_2()
{
  PStringBase<char>::PStringBase<char>(&MaterialID_4, "MaterialID");
  return atexit(_E191_6);
}

//----- (006DB120) --------------------------------------------------------  // acclient.c:752728
int _E193_2()
{
  PStringBase<char>::PStringBase<char>(&PhysMaterialID_4, "PhysMaterialID");
  return atexit(_E194_13);
}

//----- (006DB140) --------------------------------------------------------  // acclient.c:752735
int _E196_4()
{
  PStringBase<char>::PStringBase<char>(&Markings_4, "Markings");
  return atexit(_E197_4);
}

//----- (006DB160) --------------------------------------------------------  // acclient.c:752742
int _E199_2()
{
  PStringBase<char>::PStringBase<char>(&Material_21, "Material");
  return atexit(_E200_9);
}

//----- (006DB180) --------------------------------------------------------  // acclient.c:752749
int _E202_2()
{
  PStringBase<char>::PStringBase<char>(&Index_10, "Index");
  return atexit(_E203_8);
}

//----- (006DB1A0) --------------------------------------------------------  // acclient.c:752756
int _E205_3()
{
  PStringBase<char>::PStringBase<char>(&Filename_4, "Filename");
  return atexit(_E206_11);
}

//----- (006DB1C0) --------------------------------------------------------  // acclient.c:752763
int _E208_4()
{
  PStringBase<char>::PStringBase<char>(&Surface_4, "Surface");
  return atexit(_E209_6);
}

//----- (006DB1E0) --------------------------------------------------------  // acclient.c:752770
int _E211_3()
{
  PStringBase<char>::PStringBase<char>(&CellPoly_4, "CellPoly");
  return atexit(_E212_9);
}

//----- (006DB200) --------------------------------------------------------  // acclient.c:752777
int _E214_3()
{
  PStringBase<char>::PStringBase<char>(&Sphere_5, "Sphere");
  return atexit(_E215_5);
}

//----- (006DB220) --------------------------------------------------------  // acclient.c:752784
int _E217_3()
{
  PStringBase<char>::PStringBase<char>(&Side_4, "Side");
  return atexit(_E218_6);
}

//----- (006DB240) --------------------------------------------------------  // acclient.c:752791
int _E220_3()
{
  PStringBase<char>::PStringBase<char>(&Positive_4, "Positive");
  return atexit(_E221_6);
}

//----- (006DB260) --------------------------------------------------------  // acclient.c:752798
int _E223_3()
{
  PStringBase<char>::PStringBase<char>(&Negative_4, "Negative");
  return atexit(_E224_6);
}

//----- (006DB280) --------------------------------------------------------  // acclient.c:752805
int _E226_3()
{
  PStringBase<char>::PStringBase<char>(&Polygon_10, "PolygonIndex");
  return atexit(_E227_6);
}

//----- (006DB2A0) --------------------------------------------------------  // acclient.c:752812
int _E229_3()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_9, "OtherCellMeshIndex");
  return atexit(_E230_6);
}

//----- (006DB2C0) --------------------------------------------------------  // acclient.c:752819
int _E232_3()
{
  PStringBase<char>::PStringBase<char>(&CellPortal_4, "CellPortal");
  return atexit(_E233_5);
}

//----- (006DB2E0) --------------------------------------------------------  // acclient.c:752826
int _E235_3()
{
  PStringBase<char>::PStringBase<char>(&Portal_5, "PortalIndex");
  return atexit(_E236_5);
}

//----- (006DB300) --------------------------------------------------------  // acclient.c:752833
int _E238_3()
{
  PStringBase<char>::PStringBase<char>(&OtherCell_10, "OtherCellID");
  return atexit(_E239_6);
}

//----- (006DB320) --------------------------------------------------------  // acclient.c:752840
int _E241_3()
{
  PStringBase<char>::PStringBase<char>(&OtherPortal_4, "OtherPortalIndex");
  return atexit(_E242_6);
}

//----- (006DB340) --------------------------------------------------------  // acclient.c:752847
int _E244_3()
{
  PStringBase<char>::PStringBase<char>(&ExactMatch_4, "ExactMatch");
  return atexit(_E245_5);
}

//----- (006DB360) --------------------------------------------------------  // acclient.c:752854
int _E247_3()
{
  PStringBase<char>::PStringBase<char>(&StabList_4, "StabList");
  return atexit(_E248_5);
}

//----- (006DB380) --------------------------------------------------------  // acclient.c:752861
int _E250_3()
{
  PStringBase<char>::PStringBase<char>(&Period_4, "Period");
  return atexit(_E251_5);
}

//----- (006DB3A0) --------------------------------------------------------  // acclient.c:752868
int _E253_3()
{
  PStringBase<char>::PStringBase<char>(&GrannyAnimation_4, "GrannyAnimation");
  return atexit(_E254_6);
}

//----- (006DB3C0) --------------------------------------------------------  // acclient.c:752875
int _E256_3()
{
  PStringBase<char>::PStringBase<char>(&Transform_4, "Transform");
  return atexit(_E257_4);
}

//----- (006DB3E0) --------------------------------------------------------  // acclient.c:752882
int _E259_3()
{
  PStringBase<char>::PStringBase<char>(&Scale_14, "Scale");
  return atexit(_E260_5);
}

//----- (006DB400) --------------------------------------------------------  // acclient.c:752889
int _E262_3()
{
  PStringBase<char>::PStringBase<char>(&Weight_4, "Weight");
  return atexit(_E263_3);
}

//----- (006DB420) --------------------------------------------------------  // acclient.c:752896
int _E265_3()
{
  PStringBase<char>::PStringBase<char>(&Offset_4, "Offset");
  return atexit(_E266_3);
}

//----- (006DB440) --------------------------------------------------------  // acclient.c:752903
int _E268_3()
{
  PStringBase<char>::PStringBase<char>(&Quaternion_5, "Quaternion");
  return atexit(_E269_3);
}

//----- (006DB460) --------------------------------------------------------  // acclient.c:752910
int _E271_2()
{
  PStringBase<char>::PStringBase<char>(&Rotation_9, "Rotation");
  return atexit(_E272_2);
}

//----- (006DB480) --------------------------------------------------------  // acclient.c:752917
int _E274_2()
{
  PStringBase<char>::PStringBase<char>(&STime_4, "STime");
  return atexit(_E275_2);
}

//----- (006DB4A0) --------------------------------------------------------  // acclient.c:752924
int _E277_2()
{
  PStringBase<char>::PStringBase<char>(&PhysicsSplines_4, "PhysicsSplines");
  return atexit(_E278_2);
}

//----- (006DB4C0) --------------------------------------------------------  // acclient.c:752931
int _E280_2()
{
  PStringBase<char>::PStringBase<char>(&BoneOpacities_4, "BoneOpacities");
  return atexit(_E281_3);
}

//----- (006DB4E0) --------------------------------------------------------  // acclient.c:752938
int _E283_2()
{
  PStringBase<char>::PStringBase<char>(&LowPt_4, "LowPoint");
  return atexit(_E284_2);
}

//----- (006DB500) --------------------------------------------------------  // acclient.c:752945
int _E286_2()
{
  PStringBase<char>::PStringBase<char>(&Radius_4, "Radius");
  return atexit(_E287_3);
}

//----- (006DB520) --------------------------------------------------------  // acclient.c:752952
int _E289_2()
{
  PStringBase<char>::PStringBase<char>(&Height_4, "Height");
  return atexit(_E290_3);
}

//----- (006DB540) --------------------------------------------------------  // acclient.c:752959
int _E292_2()
{
  PStringBase<char>::PStringBase<char>(&Texture2D_4, "Texture2D");
  return atexit(_E293_2);
}

//----- (006DB560) --------------------------------------------------------  // acclient.c:752966
int _E295_2()
{
  PStringBase<char>::PStringBase<char>(&Texture3D_4, "Texture3D");
  return atexit(_E296_3);
}

//----- (006DB580) --------------------------------------------------------  // acclient.c:752973
int _E298_2()
{
  PStringBase<char>::PStringBase<char>(&TextureCube_4, "TextureCube");
  return atexit(_E299_1);
}

//----- (006DB5A0) --------------------------------------------------------  // acclient.c:752980
int _E301_1()
{
  PStringBase<char>::PStringBase<char>(&TextureMovie2D_4, "TextureMovie2D");
  return atexit(_E302_2);
}

//----- (006DB5C0) --------------------------------------------------------  // acclient.c:752987
int _E304_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFileName_4, "MovieFile");
  return atexit(_E305_1);
}

//----- (006DB5E0) --------------------------------------------------------  // acclient.c:752994
int _E307_1()
{
  PStringBase<char>::PStringBase<char>(&MovieFramesPerSecond_4, "MovieFPS");
  return atexit(_E308_2);
}

//----- (006DB600) --------------------------------------------------------  // acclient.c:753001
int _E310_1()
{
  PStringBase<char>::PStringBase<char>(&Levels_4, "Levels");
  return atexit(_E311_1);
}

//----- (006DB620) --------------------------------------------------------  // acclient.c:753008
int _E313_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_49, "Instance");
  return atexit(_E314_2);
}

//----- (006DB640) --------------------------------------------------------  // acclient.c:753015
int _E316_1()
{
  PStringBase<char>::PStringBase<char>(&Material_22, "Material");
  return atexit(_E317_1);
}

//----- (006DB660) --------------------------------------------------------  // acclient.c:753022
int _E319_1()
{
  PStringBase<char>::PStringBase<char>(&MaterialType_4, "MaterialType");
  return atexit(_E320_2);
}

//----- (006DB680) --------------------------------------------------------  // acclient.c:753029
int _E322_1()
{
  PStringBase<char>::PStringBase<char>(&Modifier_4, "Modifier");
  return atexit(_E323_1);
}

//----- (006DB6A0) --------------------------------------------------------  // acclient.c:753036
int _E325_1()
{
  PStringBase<char>::PStringBase<char>(&AllowStencilShadows_4, "AllowStencilShadows");
  return atexit(_E326_2);
}

//----- (006DB6C0) --------------------------------------------------------  // acclient.c:753043
int _E328_1()
{
  PStringBase<char>::PStringBase<char>(&DiscardGeometry_4, "DiscardGeometry");
  return atexit(_E329_1);
}

//----- (006DB6E0) --------------------------------------------------------  // acclient.c:753050
int _E331_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_50, "Material");
  return atexit(_E332_2);
}

//----- (006DB700) --------------------------------------------------------  // acclient.c:753057
int _E334_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_4, "SortMode");
  return atexit(_E335_1);
}

//----- (006DB720) --------------------------------------------------------  // acclient.c:753064
int _E337_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_None_4, "None");
  return atexit(_E338_1);
}

//----- (006DB740) --------------------------------------------------------  // acclient.c:753071
int _E340_1()
{
  PStringBase<char>::PStringBase<char>(&SortMode_Triangle_4, "Triangle");
  return atexit(_E341_1);
}

//----- (006DB760) --------------------------------------------------------  // acclient.c:753078
int _E343_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_51, "Modifier");
  return atexit(_E344_1);
}

//----- (006DB780) --------------------------------------------------------  // acclient.c:753085
int _E346_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_52, "Property");
  return atexit(_E347_1);
}

//----- (006DB7A0) --------------------------------------------------------  // acclient.c:753092
int _E349_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_DATA_4, "Data");
  return atexit(_E350_1);
}

//----- (006DB7C0) --------------------------------------------------------  // acclient.c:753099
int _E352_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_WAVEFORM_4, "Waveform");
  return atexit(_E353_1);
}

//----- (006DB7E0) --------------------------------------------------------  // acclient.c:753106
int _E355_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_COLOR_4, "Color");
  return atexit(_E356_1);
}

//----- (006DB800) --------------------------------------------------------  // acclient.c:753113
int _E358_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_TEXTURE_4, "Texture");
  return atexit(_E359_1);
}

//----- (006DB820) --------------------------------------------------------  // acclient.c:753120
int _E361_1()
{
  PStringBase<char>::PStringBase<char>(&DataType_BOOL_4, "Bool");
  return atexit(_E362_1);
}

//----- (006DB840) --------------------------------------------------------  // acclient.c:753127
int _E364_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_53, "Layer");
  return atexit(_E365_1);
}

//----- (006DB860) --------------------------------------------------------  // acclient.c:753134
int _E367_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTranslate_4, "UVTranslate");
  return atexit(_E368_1);
}

//----- (006DB880) --------------------------------------------------------  // acclient.c:753141
int _E370_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVRotate_4, "UVRotate");
  return atexit(_E371_1);
}

//----- (006DB8A0) --------------------------------------------------------  // acclient.c:753148
int _E373_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVScale_4, "UVScale");
  return atexit(_E374_1);
}

//----- (006DB8C0) --------------------------------------------------------  // acclient.c:753155
int _E376_1()
{
  PStringBase<char>::PStringBase<char>(&modType_UVTransform_4, "UVTransform");
  return atexit(_E377_1);
}

//----- (006DB8E0) --------------------------------------------------------  // acclient.c:753162
int _E379_1()
{
  PStringBase<char>::PStringBase<char>(&TrueFlags_4, "TrueFlags");
  return atexit(_E380_1);
}

//----- (006DB900) --------------------------------------------------------  // acclient.c:753169
int _E382_1()
{
  PStringBase<char>::PStringBase<char>(&FalseFlags_4, "FalseFlags");
  return atexit(_E383_1);
}

//----- (006DB920) --------------------------------------------------------  // acclient.c:753176
int _E385_1()
{
  PStringBase<char>::PStringBase<char>(&RenderPass_4, "RenderPass");
  return atexit(_E386_1);
}

//----- (006DB940) --------------------------------------------------------  // acclient.c:753183
int _E388_1()
{
  PStringBase<char>::PStringBase<char>(&Blend_4, "Blend");
  return atexit(_E389_1);
}

//----- (006DB960) --------------------------------------------------------  // acclient.c:753190
int _E391_1()
{
  PStringBase<char>::PStringBase<char>(&DepthTest_4, "DepthTest");
  return atexit(_E392_1);
}

//----- (006DB980) --------------------------------------------------------  // acclient.c:753197
int _E394_1()
{
  PStringBase<char>::PStringBase<char>(&DepthWrite_4, "DepthWrite");
  return atexit(_E395_1);
}

//----- (006DB9A0) --------------------------------------------------------  // acclient.c:753204
int _E397_1()
{
  PStringBase<char>::PStringBase<char>(&CullMode_4, "CullMode");
  return atexit(_E398_1);
}

//----- (006DB9C0) --------------------------------------------------------  // acclient.c:753211
int _E400_1()
{
  PStringBase<char>::PStringBase<char>(&DepthFog_4, "DepthFog");
  return atexit(_E401_1);
}

//----- (006DB9E0) --------------------------------------------------------  // acclient.c:753218
int _E403_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestMode_4, "AlphaTestMode");
  return atexit(_E404_1);
}

//----- (006DBA00) --------------------------------------------------------  // acclient.c:753225
int _E406_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaTestRef_4, "AlphaTestRef");
  return atexit(_E407_1);
}

//----- (006DBA20) --------------------------------------------------------  // acclient.c:753232
int _E409_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseLighting_4, "FFUseLighting");
  return atexit(_E410_1);
}

//----- (006DBA40) --------------------------------------------------------  // acclient.c:753239
int _E412_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseDyeColorInTFactor_4, "FFUseDyeColorInTFactor");
  return atexit(_E413_1);
}

//----- (006DBA60) --------------------------------------------------------  // acclient.c:753246
int _E415_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseSpecularLighting_4, "FFUseSpecularLighting");
  return atexit(_E416_1);
}

//----- (006DBA80) --------------------------------------------------------  // acclient.c:753253
int _E418_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseDistanceFog_4, "FFUseDistanceFog");
  return atexit(_E419_1);
}

//----- (006DBAA0) --------------------------------------------------------  // acclient.c:753260
int _E421_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexDiffuse_4, "FFUseVertexDiffuse");
  return atexit(_E422_1);
}

//----- (006DBAC0) --------------------------------------------------------  // acclient.c:753267
int _E424_1()
{
  PStringBase<char>::PStringBase<char>(&FFUseVertexSpecular_4, "FFUseVertexSpecular");
  return atexit(_E425_1);
}

//----- (006DBAE0) --------------------------------------------------------  // acclient.c:753274
int _E427_1()
{
  PStringBase<char>::PStringBase<char>(&ShaderSupportsDynamicLights_4, "ShaderSupportsDynamicLights");
  return atexit(_E428_1);
}

//----- (006DBB00) --------------------------------------------------------  // acclient.c:753281
int _E430_1()
{
  PStringBase<char>::PStringBase<char>(&UsesTransparency_4, "UsesTransparency");
  return atexit(_E431_1);
}

//----- (006DBB20) --------------------------------------------------------  // acclient.c:753288
int _E433_1()
{
  PStringBase<char>::PStringBase<char>(&Ambient_4, "Ambient");
  return atexit(_E434_1);
}

//----- (006DBB40) --------------------------------------------------------  // acclient.c:753295
int _E436_1()
{
  PStringBase<char>::PStringBase<char>(&Diffuse_10, "Diffuse");
  return atexit(_E437_1);
}

//----- (006DBB60) --------------------------------------------------------  // acclient.c:753302
int _E439_1()
{
  PStringBase<char>::PStringBase<char>(&Specular_10, "Specular");
  return atexit(_E440_1);
}

//----- (006DBB80) --------------------------------------------------------  // acclient.c:753309
int _E442_1()
{
  PStringBase<char>::PStringBase<char>(&SpecularPower_4, "SpecularPower");
  return atexit(_E443_1);
}

//----- (006DBBA0) --------------------------------------------------------  // acclient.c:753316
int _E445_1()
{
  PStringBase<char>::PStringBase<char>(&Dye_4, "Dye");
  return atexit(_E446_1);
}

//----- (006DBBC0) --------------------------------------------------------  // acclient.c:753323
int _E448_1()
{
  PStringBase<char>::PStringBase<char>(&Emissive_4, "Emissive");
  return atexit(_E449_1);
}

//----- (006DBBE0) --------------------------------------------------------  // acclient.c:753330
int _E451_1()
{
  PStringBase<char>::PStringBase<char>(&VertexFormat_4, "VertexFormat");
  return atexit(_E452_1);
}

//----- (006DBC00) --------------------------------------------------------  // acclient.c:753337
int _E454_1()
{
  PStringBase<char>::PStringBase<char>(&VertexShader_4, "VertexShader");
  return atexit(_E455_1);
}

//----- (006DBC20) --------------------------------------------------------  // acclient.c:753344
int _E457_1()
{
  PStringBase<char>::PStringBase<char>(&PixelShader_4, "PixelShader");
  return atexit(_E458_1);
}

//----- (006DBC40) --------------------------------------------------------  // acclient.c:753351
int _E460_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_NONE_4, "None");
  return atexit(_E461_1);
}

//----- (006DBC60) --------------------------------------------------------  // acclient.c:753358
int _E463_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_REFLECTIONS_4, "Reflections");
  return atexit(_E464_1);
}

//----- (006DBC80) --------------------------------------------------------  // acclient.c:753365
int _E466_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_VIDEOPOST_4, "VideoPost");
  return atexit(_E467_1);
}

//----- (006DBCA0) --------------------------------------------------------  // acclient.c:753372
int _E469_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_HIGHDETAIL_4, "HighDetail");
  return atexit(_E470_1);
}

//----- (006DBCC0) --------------------------------------------------------  // acclient.c:753379
int _E472_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_SPECULAR_4, "Specular");
  return atexit(_E473_1);
}

//----- (006DBCE0) --------------------------------------------------------  // acclient.c:753386
int _E475_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS1_4, "Class1");
  return atexit(_E476_1);
}

//----- (006DBD00) --------------------------------------------------------  // acclient.c:753393
int _E478_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS2_4, "Class2");
  return atexit(_E479_1);
}

//----- (006DBD20) --------------------------------------------------------  // acclient.c:753400
int _E481_1()
{
  PStringBase<char>::PStringBase<char>(&param_MLF_CLASS3_4, "Class3");
  return atexit(_E482_1);
}

//----- (006DBD40) --------------------------------------------------------  // acclient.c:753407
int _E484_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_Default_4, "Default");
  return atexit(_E485_1);
}

//----- (006DBD60) --------------------------------------------------------  // acclient.c:753414
int _E487_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_DirectionalLightDiffuseAndSpecular_4,
    "DirectionalLightDiffuseAndSpecular");
  return atexit(_E488_1);
}

//----- (006DBD80) --------------------------------------------------------  // acclient.c:753423
int _E490_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_PointLightDiffuseAndSpecular_4, "PointLightDiffuseAndSpecular");
  return atexit(_E491_1);
}

//----- (006DBDA0) --------------------------------------------------------  // acclient.c:753430
int _E493_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_PointLightDiffuseAndSpecularProjector_4,
    "PointLightDiffuseAndSpecularProjector");
  return atexit(_E494_1);
}

//----- (006DBDC0) --------------------------------------------------------  // acclient.c:753439
int _E496_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_4,
    "AmbientLight_DirectionalLightDiffuseAndSpecular");
  return atexit(_E497_1);
}

//----- (006DBDE0) --------------------------------------------------------  // acclient.c:753448
int _E499_1()
{
  PStringBase<char>::PStringBase<char>(
    &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_4,
    "AmbientLight_PointLightDiffuseAndSpecular");
  return atexit(_E500_1);
}

//----- (006DBE00) --------------------------------------------------------  // acclient.c:753457
int _E502_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_DistanceFog_4, "DistanceFog");
  return atexit(_E503_1);
}

//----- (006DBE20) --------------------------------------------------------  // acclient.c:753464
int _E505_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_FixedFunctionGlow_4, "FFGlow");
  return atexit(_E506_1);
}

//----- (006DBE40) --------------------------------------------------------  // acclient.c:753471
int _E508_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_ShaderGlow_4, "ShaderGlow");
  return atexit(_E509_1);
}

//----- (006DBE60) --------------------------------------------------------  // acclient.c:753478
int _E511_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_LandscapeShadowMap_4, "LandscapeShadowMap");
  return atexit(_E512_1);
}

//----- (006DBE80) --------------------------------------------------------  // acclient.c:753485
int _E514_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AlphaBlend_4, "AlphaBlend");
  return atexit(_E515_1);
}

//----- (006DBEA0) --------------------------------------------------------  // acclient.c:753492
int _E517_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_4, "AL_0DL_0PL");
  return atexit(_E518_1);
}

//----- (006DBEC0) --------------------------------------------------------  // acclient.c:753499
int _E520_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_4, "AL_0DL_1PL");
  return atexit(_E521_1);
}

//----- (006DBEE0) --------------------------------------------------------  // acclient.c:753506
int _E523_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_4, "AL_0DL_2PL");
  return atexit(_E524_1);
}

//----- (006DBF00) --------------------------------------------------------  // acclient.c:753513
int _E526_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_4, "AL_0DL_3PL");
  return atexit(_E527_1);
}

//----- (006DBF20) --------------------------------------------------------  // acclient.c:753520
int _E529_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_4, "AL_0DL_4PL");
  return atexit(_E530_1);
}

//----- (006DBF40) --------------------------------------------------------  // acclient.c:753527
int _E532_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_4, "AL_0DL_5PL");
  return atexit(_E533_1);
}

//----- (006DBF60) --------------------------------------------------------  // acclient.c:753534
int _E535_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_4, "AL_0DL_6PL");
  return atexit(_E536_1);
}

//----- (006DBF80) --------------------------------------------------------  // acclient.c:753541
int _E538_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_4, "AL_0DL_7PL");
  return atexit(_E539_1);
}

//----- (006DBFA0) --------------------------------------------------------  // acclient.c:753548
int _E541_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_4, "AL_0DL_8PL");
  return atexit(_E542_1);
}

//----- (006DBFC0) --------------------------------------------------------  // acclient.c:753555
int _E544_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_4, "AL_1DL_0PL");
  return atexit(_E545_1);
}

//----- (006DBFE0) --------------------------------------------------------  // acclient.c:753562
int _E547_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_4, "AL_1DL_1PL");
  return atexit(_E548_1);
}

//----- (006DC000) --------------------------------------------------------  // acclient.c:753569
int _E550_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_4, "AL_1DL_2PL");
  return atexit(_E551_1);
}

//----- (006DC020) --------------------------------------------------------  // acclient.c:753576
int _E553_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_4, "AL_1DL_3PL");
  return atexit(_E554_1);
}

//----- (006DC040) --------------------------------------------------------  // acclient.c:753583
int _E556_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_4, "AL_1DL_4PL");
  return atexit(_E557_1);
}

//----- (006DC060) --------------------------------------------------------  // acclient.c:753590
int _E559_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_4, "AL_1DL_5PL");
  return atexit(_E560_1);
}

//----- (006DC080) --------------------------------------------------------  // acclient.c:753597
int _E562_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_4, "AL_1DL_6PL");
  return atexit(_E563_1);
}

//----- (006DC0A0) --------------------------------------------------------  // acclient.c:753604
int _E565_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_4, "AL_1DL_7PL");
  return atexit(_E566_1);
}

//----- (006DC0C0) --------------------------------------------------------  // acclient.c:753611
int _E568_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_0PL_Fog_4, "AL_0DL_0PL_Fog");
  return atexit(_E569_1);
}

//----- (006DC0E0) --------------------------------------------------------  // acclient.c:753618
int _E571_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_1PL_Fog_4, "AL_0DL_1PL_Fog");
  return atexit(_E572_1);
}

//----- (006DC100) --------------------------------------------------------  // acclient.c:753625
int _E574_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_2PL_Fog_4, "AL_0DL_2PL_Fog");
  return atexit(_E575_1);
}

//----- (006DC120) --------------------------------------------------------  // acclient.c:753632
int _E577_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_3PL_Fog_4, "AL_0DL_3PL_Fog");
  return atexit(_E578_1);
}

//----- (006DC140) --------------------------------------------------------  // acclient.c:753639
int _E580_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_4PL_Fog_4, "AL_0DL_4PL_Fog");
  return atexit(_E581_1);
}

//----- (006DC160) --------------------------------------------------------  // acclient.c:753646
int _E583_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_5PL_Fog_4, "AL_0DL_5PL_Fog");
  return atexit(_E584_1);
}

//----- (006DC180) --------------------------------------------------------  // acclient.c:753653
int _E586_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_6PL_Fog_4, "AL_0DL_6PL_Fog");
  return atexit(_E587_1);
}

//----- (006DC1A0) --------------------------------------------------------  // acclient.c:753660
int _E589_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_7PL_Fog_4, "AL_0DL_7PL_Fog");
  return atexit(_E590_1);
}

//----- (006DC1C0) --------------------------------------------------------  // acclient.c:753667
int _E592_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_0DL_8PL_Fog_4, "AL_0DL_8PL_Fog");
  return atexit(_E593_1);
}

//----- (006DC1E0) --------------------------------------------------------  // acclient.c:753674
int _E595_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_0PL_Fog_4, "AL_1DL_0PL_Fog");
  return atexit(_E596_1);
}

//----- (006DC200) --------------------------------------------------------  // acclient.c:753681
int _E598_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_1PL_Fog_4, "AL_1DL_1PL_Fog");
  return atexit(_E599_1);
}

//----- (006DC220) --------------------------------------------------------  // acclient.c:753688
int _E601_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_2PL_Fog_4, "AL_1DL_2PL_Fog");
  return atexit(_E602_1);
}

//----- (006DC240) --------------------------------------------------------  // acclient.c:753695
int _E604_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_3PL_Fog_4, "AL_1DL_3PL_Fog");
  return atexit(_E605_1);
}

//----- (006DC260) --------------------------------------------------------  // acclient.c:753702
int _E607_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_4PL_Fog_4, "AL_1DL_4PL_Fog");
  return atexit(_E608_1);
}

//----- (006DC280) --------------------------------------------------------  // acclient.c:753709
int _E610_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_5PL_Fog_4, "AL_1DL_5PL_Fog");
  return atexit(_E611_1);
}

//----- (006DC2A0) --------------------------------------------------------  // acclient.c:753716
int _E613_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_6PL_Fog_4, "AL_1DL_6PL_Fog");
  return atexit(_E614_1);
}

//----- (006DC2C0) --------------------------------------------------------  // acclient.c:753723
int _E616_1()
{
  PStringBase<char>::PStringBase<char>(&param_RenderPass_AL_1DL_7PL_Fog_4, "AL_1DL_7PL_Fog");
  return atexit(_E617_1);
}

//----- (006DC2E0) --------------------------------------------------------  // acclient.c:753730
int _E619_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ZERO_4, "Zero");
  return atexit(_E620_1);
}

//----- (006DC300) --------------------------------------------------------  // acclient.c:753737
int _E622_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_ONE_4, "One");
  return atexit(_E623_1);
}

//----- (006DC320) --------------------------------------------------------  // acclient.c:753744
int _E625_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCCOLOR_4, "SrcColor");
  return atexit(_E626_1);
}

//----- (006DC340) --------------------------------------------------------  // acclient.c:753751
int _E628_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCCOLOR_4, "InvSrcColor");
  return atexit(_E629_1);
}

//----- (006DC360) --------------------------------------------------------  // acclient.c:753758
int _E631_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHA_4, "SrcAlpha");
  return atexit(_E632_1);
}

//----- (006DC380) --------------------------------------------------------  // acclient.c:753765
int _E634_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVSRCALPHA_4, "InvSrcAlpha");
  return atexit(_E635_1);
}

//----- (006DC3A0) --------------------------------------------------------  // acclient.c:753772
int _E637_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTALPHA_4, "DstAlpha");
  return atexit(_E638_1);
}

//----- (006DC3C0) --------------------------------------------------------  // acclient.c:753779
int _E640_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTALPHA_4, "InvDstAlpha");
  return atexit(_E641_1);
}

//----- (006DC3E0) --------------------------------------------------------  // acclient.c:753786
int _E643_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_DSTCOLOR_4, "DstColor");
  return atexit(_E644_1);
}

//----- (006DC400) --------------------------------------------------------  // acclient.c:753793
int _E646_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_INVDSTCOLOR_4, "InvDstColor");
  return atexit(_E647_1);
}

//----- (006DC420) --------------------------------------------------------  // acclient.c:753800
int _E649_1()
{
  PStringBase<char>::PStringBase<char>(&param_BLEND_SRCALPHASAT_4, "SrcAlphaSat");
  return atexit(_E650_1);
}

//----- (006DC440) --------------------------------------------------------  // acclient.c:753807
int _E652_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESS_4, "Less");
  return atexit(_E653_1);
}

//----- (006DC460) --------------------------------------------------------  // acclient.c:753814
int _E655_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_EQUAL_4, "Equal");
  return atexit(_E656_1);
}

//----- (006DC480) --------------------------------------------------------  // acclient.c:753821
int _E658_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_LESSEQUAL_4, "LessEqual");
  return atexit(_E659_1);
}

//----- (006DC4A0) --------------------------------------------------------  // acclient.c:753828
int _E661_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATER_4, "Greater");
  return atexit(_E662_1);
}

//----- (006DC4C0) --------------------------------------------------------  // acclient.c:753835
int _E664_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_NOTEQUAL_4, "NotEqual");
  return atexit(_E665_1);
}

//----- (006DC4E0) --------------------------------------------------------  // acclient.c:753842
int _E667_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_GREATEREQUAL_4, "GreaterEqual");
  return atexit(_E668_1);
}

//----- (006DC500) --------------------------------------------------------  // acclient.c:753849
int _E670_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHTEST_ALWAYS_4, "Always");
  return atexit(_E671_1);
}

//----- (006DC520) --------------------------------------------------------  // acclient.c:753856
int _E673_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_ON_4, "On");
  return atexit(_E674_1);
}

//----- (006DC540) --------------------------------------------------------  // acclient.c:753863
int _E676_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHWRITE_OFF_4, "Off");
  return atexit(_E677_1);
}

//----- (006DC560) --------------------------------------------------------  // acclient.c:753870
int _E679_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERDIFFUSE_4, "LayerDiffuse");
  return atexit(_E680_1);
}

//----- (006DC580) --------------------------------------------------------  // acclient.c:753877
int _E682_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_LAYERSPECULAR_4, "LayerSpecular");
  return atexit(_E683_1);
}

//----- (006DC5A0) --------------------------------------------------------  // acclient.c:753884
int _E685_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXDIFFUSE_4, "VertexDiffuse");
  return atexit(_E686_1);
}

//----- (006DC5C0) --------------------------------------------------------  // acclient.c:753891
int _E688_1()
{
  PStringBase<char>::PStringBase<char>(&param_COLORSOURCE_VERTEXSPECULAR_4, "VertexSpecular");
  return atexit(_E689_1);
}

//----- (006DC5E0) --------------------------------------------------------  // acclient.c:753898
int _E691_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_NONE_4, "None");
  return atexit(_E692_1);
}

//----- (006DC600) --------------------------------------------------------  // acclient.c:753905
int _E694_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CW_4, "CW");
  return atexit(_E695_1);
}

//----- (006DC620) --------------------------------------------------------  // acclient.c:753912
int _E697_1()
{
  PStringBase<char>::PStringBase<char>(&param_CULLMODE_CCW_4, "CCW");
  return atexit(_E698_1);
}

//----- (006DC640) --------------------------------------------------------  // acclient.c:753919
int _E700_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_NONE_4, "None");
  return atexit(_E701_1);
}

//----- (006DC660) --------------------------------------------------------  // acclient.c:753926
int _E703_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SIMPLE_4, "Simple");
  return atexit(_E704_1);
}

//----- (006DC680) --------------------------------------------------------  // acclient.c:753933
int _E706_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_DIFFUSE_4, "Diffuse");
  return atexit(_E707_1);
}

//----- (006DC6A0) --------------------------------------------------------  // acclient.c:753940
int _E709_1()
{
  PStringBase<char>::PStringBase<char>(&param_LIGHTMODE_SPECULAR_4, "Specular");
  return atexit(_E710_1);
}

//----- (006DC6C0) --------------------------------------------------------  // acclient.c:753947
int _E712_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_OFF_4, "Off");
  return atexit(_E713_1);
}

//----- (006DC6E0) --------------------------------------------------------  // acclient.c:753954
int _E715_1()
{
  PStringBase<char>::PStringBase<char>(&param_DEPTHFOG_ON_4, "On");
  return atexit(_E716_1);
}

//----- (006DC700) --------------------------------------------------------  // acclient.c:753961
int _E718_1()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_OFF_4, "Off");
  return atexit(_E719_1);
}

//----- (006DC720) --------------------------------------------------------  // acclient.c:753968
int _E721_1()
{
  PStringBase<char>::PStringBase<char>(&param_ALPHATESTMODE_ON_4, "On");
  return atexit(_E722_1);
}

//----- (006DC740) --------------------------------------------------------  // acclient.c:753975
int _E724_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_ORIGIN_4, "Origin");
  return atexit(_E725_1);
}

//----- (006DC760) --------------------------------------------------------  // acclient.c:753982
int _E727_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_NORMAL_4, "Normal");
  return atexit(_E728_1);
}

//----- (006DC780) --------------------------------------------------------  // acclient.c:753989
int _E730_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_POINTSIZE_4, "PointSize");
  return atexit(_E731_1);
}

//----- (006DC7A0) --------------------------------------------------------  // acclient.c:753996
int _E733_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_DIFFUSE_4, "Diffuse");
  return atexit(_E734_1);
}

//----- (006DC7C0) --------------------------------------------------------  // acclient.c:754003
int _E736_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_SPECULAR_4, "Specular");
  return atexit(_E737_1);
}

//----- (006DC7E0) --------------------------------------------------------  // acclient.c:754010
int _E739_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx1_4, "TCPairX1");
  return atexit(_E740_1);
}

//----- (006DC800) --------------------------------------------------------  // acclient.c:754017
int _E742_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx2_4, "TCPairX2");
  return atexit(_E743_1);
}

//----- (006DC820) --------------------------------------------------------  // acclient.c:754024
int _E745_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx3_4, "TCPairX3");
  return atexit(_E746_1);
}

//----- (006DC840) --------------------------------------------------------  // acclient.c:754031
int _E748_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx4_4, "TCPairX4");
  return atexit(_E749_1);
}

//----- (006DC860) --------------------------------------------------------  // acclient.c:754038
int _E751_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx5_4, "TCPairX5");
  return atexit(_E752_1);
}

//----- (006DC880) --------------------------------------------------------  // acclient.c:754045
int _E754_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx6_4, "TCPairX6");
  return atexit(_E755_1);
}

//----- (006DC8A0) --------------------------------------------------------  // acclient.c:754052
int _E757_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx7_4, "TCPairX7");
  return atexit(_E758_1);
}

//----- (006DC8C0) --------------------------------------------------------  // acclient.c:754059
int _E760_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_TCPAIRx8_4, "TCPairX8");
  return atexit(_E761_1);
}

//----- (006DC8E0) --------------------------------------------------------  // acclient.c:754066
int _E763_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_S_4, "VectorS");
  return atexit(_E764_1);
}

//----- (006DC900) --------------------------------------------------------  // acclient.c:754073
int _E766_1()
{
  PStringBase<char>::PStringBase<char>(&param_VF_VECTOR_T_4, "VectorT");
  return atexit(_E767_1);
}

//----- (006DC920) --------------------------------------------------------  // acclient.c:754080
int _E769_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_54, "Stage");
  return atexit(_E770_1);
}

//----- (006DC940) --------------------------------------------------------  // acclient.c:754087
int _E772_1()
{
  PStringBase<char>::PStringBase<char>(&SamplerNodeName_4, "Sampler");
  return atexit(_E773_1);
}

//----- (006DC960) --------------------------------------------------------  // acclient.c:754094
int _E775_1()
{
  PStringBase<char>::PStringBase<char>(&SamplerName_4, "SamplerName");
  return atexit(_E776_1);
}

//----- (006DC980) --------------------------------------------------------  // acclient.c:754101
int _E778_1()
{
  PStringBase<char>::PStringBase<char>(&Texture_4, "Texture");
  return atexit(_E779_1);
}

//----- (006DC9A0) --------------------------------------------------------  // acclient.c:754108
int _E781_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_FrameBuffer_4, "!FrameBuffer");
  return atexit(_E782_1);
}

//----- (006DC9C0) --------------------------------------------------------  // acclient.c:754115
int _E784_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Distortion_4, "!Distortion");
  return atexit(_E785_1);
}

//----- (006DC9E0) --------------------------------------------------------  // acclient.c:754122
int _E787_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_Reflection_4, "!Reflection");
  return atexit(_E788_1);
}

//----- (006DCA00) --------------------------------------------------------  // acclient.c:754129
int _E790_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_NormalizeCube_4, "!NormalizeCube");
  return atexit(_E791_1);
}

//----- (006DCA20) --------------------------------------------------------  // acclient.c:754136
int _E793_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LightProjectorCube_4, "!LightProjectorCube");
  return atexit(_E794_1);
}

//----- (006DCA40) --------------------------------------------------------  // acclient.c:754143
int _E796_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_EnvironmentCube_4, "!EnvironmentCube");
  return atexit(_E797_1);
}

//----- (006DCA60) --------------------------------------------------------  // acclient.c:754150
int _E799_1()
{
  PStringBase<char>::PStringBase<char>(&SpecialTexture_LandscapeShadows_4, "!LandscapeShadows");
  return atexit(_E800_1);
}

//----- (006DCA80) --------------------------------------------------------  // acclient.c:754157
int _E802_1()
{
  PStringBase<char>::PStringBase<char>(&AddressMode_4, "AddressMode");
  return atexit(_E803_1);
}

//----- (006DCAA0) --------------------------------------------------------  // acclient.c:754164
int _E805_1()
{
  PStringBase<char>::PStringBase<char>(&TexFilter_4, "FilterMode");
  return atexit(_E806_1);
}

//----- (006DCAC0) --------------------------------------------------------  // acclient.c:754171
int _E808_1()
{
  PStringBase<char>::PStringBase<char>(&ColorOp_4, "FFColorOp");
  return atexit(_E809_1);
}

//----- (006DCAE0) --------------------------------------------------------  // acclient.c:754178
int _E811_1()
{
  PStringBase<char>::PStringBase<char>(&ColorArg1_4, "FFColorArg1");
  return atexit(_E812_1);
}

//----- (006DCB00) --------------------------------------------------------  // acclient.c:754185
int _E814_1()
{
  PStringBase<char>::PStringBase<char>(&ColorArg2_4, "FFColorArg2");
  return atexit(_E815_1);
}

//----- (006DCB20) --------------------------------------------------------  // acclient.c:754192
int _E817_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaOp_4, "FFAlphaOp");
  return atexit(_E818_1);
}

//----- (006DCB40) --------------------------------------------------------  // acclient.c:754199
int _E820_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg1_4, "FFAlphaArg1");
  return atexit(_E821_1);
}

//----- (006DCB60) --------------------------------------------------------  // acclient.c:754206
int _E823_1()
{
  PStringBase<char>::PStringBase<char>(&AlphaArg2_4, "FFAlphaArg2");
  return atexit(_E824_1);
}

//----- (006DCB80) --------------------------------------------------------  // acclient.c:754213
int _E826_1()
{
  PStringBase<char>::PStringBase<char>(&TexCoord_4, "FFTexCoordIndex");
  return atexit(_E827_1);
}

//----- (006DCBA0) --------------------------------------------------------  // acclient.c:754220
int _E829_1()
{
  PStringBase<char>::PStringBase<char>(&UseProjection_4, "FFUseProjection");
  return atexit(_E830_1);
}

//----- (006DCBC0) --------------------------------------------------------  // acclient.c:754227
int _E832_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG1_4, "SelectArg1");
  return atexit(_E833_1);
}

//----- (006DCBE0) --------------------------------------------------------  // acclient.c:754234
int _E835_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SELECTARG2_4, "SelectArg2");
  return atexit(_E836_1);
}

//----- (006DCC00) --------------------------------------------------------  // acclient.c:754241
int _E838_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE_4, "Modulate");
  return atexit(_E839_1);
}

//----- (006DCC20) --------------------------------------------------------  // acclient.c:754248
int _E841_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE2X_4, "Modulate2X");
  return atexit(_E842_1);
}

//----- (006DCC40) --------------------------------------------------------  // acclient.c:754255
int _E844_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATE4X_4, "Modulate4X");
  return atexit(_E845_1);
}

//----- (006DCC60) --------------------------------------------------------  // acclient.c:754262
int _E847_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADD_4, "Add");
  return atexit(_E848_1);
}

//----- (006DCC80) --------------------------------------------------------  // acclient.c:754269
int _E850_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED_4, "AddSigned");
  return atexit(_E851_1);
}

//----- (006DCCA0) --------------------------------------------------------  // acclient.c:754276
int _E853_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSIGNED2X_4, "AddSigned2X");
  return atexit(_E854_1);
}

//----- (006DCCC0) --------------------------------------------------------  // acclient.c:754283
int _E856_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_SUBTRACT_4, "Subtract");
  return atexit(_E857_1);
}

//----- (006DCCE0) --------------------------------------------------------  // acclient.c:754290
int _E859_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_ADDSMOOTH_4, "AddSmooth");
  return atexit(_E860_1);
}

//----- (006DCD00) --------------------------------------------------------  // acclient.c:754297
int _E862_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDDIFFUSEALPHA_4, "BlendDiffuseAlpha");
  return atexit(_E863_1);
}

//----- (006DCD20) --------------------------------------------------------  // acclient.c:754304
int _E865_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHA_4, "BlendTextureAlpha");
  return atexit(_E866_1);
}

//----- (006DCD40) --------------------------------------------------------  // acclient.c:754311
int _E868_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDFACTORALPHA_4, "BlendFactorAlpha");
  return atexit(_E869_1);
}

//----- (006DCD60) --------------------------------------------------------  // acclient.c:754318
int _E871_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDTEXTUREALPHAPM_4, "BlendTextureAlphaPM");
  return atexit(_E872_1);
}

//----- (006DCD80) --------------------------------------------------------  // acclient.c:754325
int _E874_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BLENDCURRENTALPHA_4, "BlendCurrentAlpha");
  return atexit(_E875_1);
}

//----- (006DCDA0) --------------------------------------------------------  // acclient.c:754332
int _E877_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_PREMODULATE_4, "Premodulate");
  return atexit(_E878_1);
}

//----- (006DCDC0) --------------------------------------------------------  // acclient.c:754339
int _E880_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEALPHA_ADDCOLOR_4, "ModulateAlphaAddColor");
  return atexit(_E881_1);
}

//----- (006DCDE0) --------------------------------------------------------  // acclient.c:754346
int _E883_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATECOLOR_ADDALPHA_4, "ModulateColorAddAlpha");
  return atexit(_E884_1);
}

//----- (006DCE00) --------------------------------------------------------  // acclient.c:754353
int _E886_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_4, "ModulateInvAlphaAddColor");
  return atexit(_E887_1);
}

//----- (006DCE20) --------------------------------------------------------  // acclient.c:754360
int _E889_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_4, "ModulateInvColorAddAlpha");
  return atexit(_E890_1);
}

//----- (006DCE40) --------------------------------------------------------  // acclient.c:754367
int _E892_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAP_4, "BumpEnvMap");
  return atexit(_E893_1);
}

//----- (006DCE60) --------------------------------------------------------  // acclient.c:754374
int _E895_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_BUMPENVMAPLUMINANCE_4, "BumpEnvMapLuminance");
  return atexit(_E896_1);
}

//----- (006DCE80) --------------------------------------------------------  // acclient.c:754381
int _E898_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_DOTPRODUCT3_4, "DotProduct3");
  return atexit(_E899_1);
}

//----- (006DCEA0) --------------------------------------------------------  // acclient.c:754388
int _E901_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_MULTIPLYADD_4, "MultiplyAdd");
  return atexit(_E902_1);
}

//----- (006DCEC0) --------------------------------------------------------  // acclient.c:754395
int _E904_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXOP_LERP_4, "Lerp");
  return atexit(_E905_1);
}

//----- (006DCEE0) --------------------------------------------------------  // acclient.c:754402
int _E907_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_DIFFUSE_4, "Diffuse");
  return atexit(_E908_1);
}

//----- (006DCF00) --------------------------------------------------------  // acclient.c:754409
int _E910_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_SPECULAR_4, "Specular");
  return atexit(_E911_1);
}

//----- (006DCF20) --------------------------------------------------------  // acclient.c:754416
int _E913_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_CURRENT_4, "Current");
  return atexit(_E914_1);
}

//----- (006DCF40) --------------------------------------------------------  // acclient.c:754423
int _E916_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TEXTURE_4, "Texture");
  return atexit(_E917_1);
}

//----- (006DCF60) --------------------------------------------------------  // acclient.c:754430
int _E919_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXARG_TFACTOR_4, "TFactor");
  return atexit(_E920_1);
}

//----- (006DCF80) --------------------------------------------------------  // acclient.c:754437
int _E922_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_WRAP_4, "Wrap");
  return atexit(_E923_1);
}

//----- (006DCFA0) --------------------------------------------------------  // acclient.c:754444
int _E925_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_MIRROR_4, "Mirror");
  return atexit(_E926_1);
}

//----- (006DCFC0) --------------------------------------------------------  // acclient.c:754451
int _E928_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_CLAMP_4, "Clamp");
  return atexit(_E929_1);
}

//----- (006DCFE0) --------------------------------------------------------  // acclient.c:754458
int _E931_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXADDRESS_BORDER_4, "Border");
  return atexit(_E932_1);
}

//----- (006DD000) --------------------------------------------------------  // acclient.c:754465
int _E934_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_NONE_4, "None");
  return atexit(_E935_1);
}

//----- (006DD020) --------------------------------------------------------  // acclient.c:754472
int _E937_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_POINT_4, "Point");
  return atexit(_E938_1);
}

//----- (006DD040) --------------------------------------------------------  // acclient.c:754479
int _E940_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_LINEAR_4, "Linear");
  return atexit(_E941_1);
}

//----- (006DD060) --------------------------------------------------------  // acclient.c:754486
int _E943_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXFILTER_ANISOTROPIC_4, "Anisotropic");
  return atexit(_E944_1);
}

//----- (006DD080) --------------------------------------------------------  // acclient.c:754493
int _E946_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ReflectionVector_4, "ReflectionVector");
  return atexit(_E947_1);
}

//----- (006DD0A0) --------------------------------------------------------  // acclient.c:754500
int _E949_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewNormal_4, "ViewNormal");
  return atexit(_E950_1);
}

//----- (006DD0C0) --------------------------------------------------------  // acclient.c:754507
int _E952_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_ViewOrigin_4, "ViewOrigin");
  return atexit(_E953_1);
}

//----- (006DD0E0) --------------------------------------------------------  // acclient.c:754514
int _E955_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_SphereMap_4, "SphereMap");
  return atexit(_E956_1);
}

//----- (006DD100) --------------------------------------------------------  // acclient.c:754521
int _E958_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapReflection_4, "CubeMapReflection");
  return atexit(_E959_1);
}

//----- (006DD120) --------------------------------------------------------  // acclient.c:754528
int _E961_1()
{
  PStringBase<char>::PStringBase<char>(&param_TEXCOORD_CubeMapFakeLight_4, "CubeMapFakeLight");
  return atexit(_E962_1);
}

//----- (006DD140) --------------------------------------------------------  // acclient.c:754535
int _E964_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_55, "FFModifier");
  return atexit(_E965_1);
}

//----- (006DD160) --------------------------------------------------------  // acclient.c:754542
int _E967_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Origin_4, "Origin");
  return atexit(_E968_1);
}

//----- (006DD180) --------------------------------------------------------  // acclient.c:754549
int _E970_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Normal_4, "Normal");
  return atexit(_E971_1);
}

//----- (006DD1A0) --------------------------------------------------------  // acclient.c:754556
int _E973_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_Diffuse_4, "Diffuse");
  return atexit(_E974_1);
}

//----- (006DD1C0) --------------------------------------------------------  // acclient.c:754563
int _E976_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTranslate_4, "UVTranslate");
  return atexit(_E977_1);
}

//----- (006DD1E0) --------------------------------------------------------  // acclient.c:754570
int _E979_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVRotate_4, "UVRotate");
  return atexit(_E980_1);
}

//----- (006DD200) --------------------------------------------------------  // acclient.c:754577
int _E982_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVScale_4, "UVScale");
  return atexit(_E983_1);
}

//----- (006DD220) --------------------------------------------------------  // acclient.c:754584
int _E985_1()
{
  PStringBase<char>::PStringBase<char>(&ModType_UVTransform_4, "UVTransform");
  return atexit(_E986_1);
}

//----- (006DD240) --------------------------------------------------------  // acclient.c:754591
int _E988_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_texCoordIndex_4, "TexCoordIndex");
  return atexit(_E989_1);
}

//----- (006DD260) --------------------------------------------------------  // acclient.c:754598
int _E991_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVTranslate_translate_4, "Translate");
  return atexit(_E992_1);
}

//----- (006DD280) --------------------------------------------------------  // acclient.c:754605
int _E994_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_texCoordIndex_4, "TexCoordIndex");
  return atexit(_E995_1);
}

//----- (006DD2A0) --------------------------------------------------------  // acclient.c:754612
int _E997_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVRotate_rotate_4, "Rotate");
  return atexit(_E998_1);
}

//----- (006DD2C0) --------------------------------------------------------  // acclient.c:754619
int _E1000_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_texCoordIndex_4, "TexCoordIndex");
  return atexit(_E1001_1);
}

//----- (006DD2E0) --------------------------------------------------------  // acclient.c:754626
int _E1003_1()
{
  PStringBase<char>::PStringBase<char>(&Mod_UVScale_scale_4, "Scale");
  return atexit(_E1004_1);
}

//----- (006DD300) --------------------------------------------------------  // acclient.c:754633
int _E1006_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_56, "PSDesc");
  return atexit(_E1007_1);
}

//----- (006DD320) --------------------------------------------------------  // acclient.c:754640
int _E1009_1()
{
  PStringBase<char>::PStringBase<char>(&PhysicsTimeStep_4, "PhysicsTimeStep");
  return atexit(_E1010_1);
}

//----- (006DD340) --------------------------------------------------------  // acclient.c:754647
int _E1012_1()
{
  PStringBase<char>::PStringBase<char>(&FastForwardTime_4, "FastForwardTime");
  return atexit(_E1013_1);
}

//----- (006DD360) --------------------------------------------------------  // acclient.c:754654
int _E1015_1()
{
  PStringBase<char>::PStringBase<char>(&StartFadeDistance_4, "StartFadeDistance");
  return atexit(_E1016_1);
}

//----- (006DD380) --------------------------------------------------------  // acclient.c:754661
int _E1018_1()
{
  PStringBase<char>::PStringBase<char>(&StopFadeDistance_4, "StopFadeDistance");
  return atexit(_E1019_1);
}

//----- (006DD3A0) --------------------------------------------------------  // acclient.c:754668
int _E1021_1()
{
  PStringBase<char>::PStringBase<char>(&PhysicsDuration_4, "PhysicsDuration");
  return atexit(_E1022_1);
}

//----- (006DD3C0) --------------------------------------------------------  // acclient.c:754675
int _E1024_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleType_4, "ScaleType");
  return atexit(_E1025_1);
}

//----- (006DD3E0) --------------------------------------------------------  // acclient.c:754682
int _E1027_1()
{
  PStringBase<char>::PStringBase<char>(&WorldSpace_4, "WorldSpace");
  return atexit(_E1028_1);
}

//----- (006DD400) --------------------------------------------------------  // acclient.c:754689
int _E1030_1()
{
  PStringBase<char>::PStringBase<char>(&ForceDraw_4, "ForceDraw");
  return atexit(_E1031_1);
}

//----- (006DD420) --------------------------------------------------------  // acclient.c:754696
int _E1033_1()
{
  PStringBase<char>::PStringBase<char>(&NumEmitters_4, "NumEmitters");
  return atexit(_E1034_1);
}

//----- (006DD440) --------------------------------------------------------  // acclient.c:754703
int _E1036_1()
{
  PStringBase<char>::PStringBase<char>(&Material_23, "Material");
  return atexit(_E1037_1);
}

//----- (006DD460) --------------------------------------------------------  // acclient.c:754710
int _E1039_1()
{
  PStringBase<char>::PStringBase<char>(&Version_4, "Version");
  return atexit(_E1040_1);
}

//----- (006DD480) --------------------------------------------------------  // acclient.c:754717
int _E1042_1()
{
  PStringBase<char>::PStringBase<char>(&MaxParticles_4, "MaxParticles");
  return atexit(_E1043_1);
}

//----- (006DD4A0) --------------------------------------------------------  // acclient.c:754724
int _E1045_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_57, "Emitter");
  return atexit(_E1046_1);
}

//----- (006DD4C0) --------------------------------------------------------  // acclient.c:754731
int _E1048_1()
{
  PStringBase<char>::PStringBase<char>(&Origin_10, "Origin");
  return atexit(_E1049_1);
}

//----- (006DD4E0) --------------------------------------------------------  // acclient.c:754738
int _E1051_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_4, "Shape");
  return atexit(_E1052_1);
}

//----- (006DD500) --------------------------------------------------------  // acclient.c:754745
int _E1054_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Point_4, "Point");
  return atexit(_E1055_1);
}

//----- (006DD520) --------------------------------------------------------  // acclient.c:754752
int _E1057_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Line_4, "Line");
  return atexit(_E1058_1);
}

//----- (006DD540) --------------------------------------------------------  // acclient.c:754759
int _E1060_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Quad_4, "Quad");
  return atexit(_E1061_1);
}

//----- (006DD560) --------------------------------------------------------  // acclient.c:754766
int _E1063_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Disc_4, "Disc");
  return atexit(_E1064_1);
}

//----- (006DD580) --------------------------------------------------------  // acclient.c:754773
int _E1066_1()
{
  PStringBase<char>::PStringBase<char>(&Shape_Sphere_4, "Sphere");
  return atexit(_E1067_1);
}

//----- (006DD5A0) --------------------------------------------------------  // acclient.c:754780
int _E1069_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_4, "ParticleShape");
  return atexit(_E1070_1);
}

//----- (006DD5C0) --------------------------------------------------------  // acclient.c:754787
int _E1072_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Triangle_4, "Triangle");
  return atexit(_E1073_1);
}

//----- (006DD5E0) --------------------------------------------------------  // acclient.c:754794
int _E1075_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleShape_Quad_4, "Quad");
  return atexit(_E1076_1);
}

//----- (006DD600) --------------------------------------------------------  // acclient.c:754801
int _E1078_1()
{
  PStringBase<char>::PStringBase<char>(&Streak_4, "Streak");
  return atexit(_E1079_1);
}

//----- (006DD620) --------------------------------------------------------  // acclient.c:754808
int _E1081_1()
{
  PStringBase<char>::PStringBase<char>(&Rotation_10, "Rotation");
  return atexit(_E1082_1);
}

//----- (006DD640) --------------------------------------------------------  // acclient.c:754815
int _E1084_1()
{
  PStringBase<char>::PStringBase<char>(&WorldRotation_4, "WorldRotation");
  return atexit(_E1085_1);
}

//----- (006DD660) --------------------------------------------------------  // acclient.c:754822
int _E1087_1()
{
  PStringBase<char>::PStringBase<char>(&RotateVelocity_4, "RotateVelocity");
  return atexit(_E1088_1);
}

//----- (006DD680) --------------------------------------------------------  // acclient.c:754829
int _E1090_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleScale_4, "ParticleScale");
  return atexit(_E1091_1);
}

//----- (006DD6A0) --------------------------------------------------------  // acclient.c:754836
int _E1093_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_15, "Scale");
  return atexit(_E1094_1);
}

//----- (006DD6C0) --------------------------------------------------------  // acclient.c:754843
int _E1096_1()
{
  PStringBase<char>::PStringBase<char>(&ExplodingDir_4, "ExplodingDir");
  return atexit(_E1097_1);
}

//----- (006DD6E0) --------------------------------------------------------  // acclient.c:754850
int _E1099_1()
{
  PStringBase<char>::PStringBase<char>(&BirthRate_4, "BirthRate");
  return atexit(_E1100_1);
}

//----- (006DD700) --------------------------------------------------------  // acclient.c:754857
int _E1102_1()
{
  PStringBase<char>::PStringBase<char>(&Lifespan_4, "Lifespan");
  return atexit(_E1103_1);
}

//----- (006DD720) --------------------------------------------------------  // acclient.c:754864
int _E1105_1()
{
  PStringBase<char>::PStringBase<char>(&Velocity_4, "Velocity");
  return atexit(_E1106_1);
}

//----- (006DD740) --------------------------------------------------------  // acclient.c:754871
int _E1108_1()
{
  PStringBase<char>::PStringBase<char>(&Direction_4, "Direction");
  return atexit(_E1109_1);
}

//----- (006DD760) --------------------------------------------------------  // acclient.c:754878
int _E1111_1()
{
  PStringBase<char>::PStringBase<char>(&MinSpread_4, "MinSpread");
  return atexit(_E1112_1);
}

//----- (006DD780) --------------------------------------------------------  // acclient.c:754885
int _E1114_1()
{
  PStringBase<char>::PStringBase<char>(&MaxSpread_4, "MaxSpread");
  return atexit(_E1115_1);
}

//----- (006DD7A0) --------------------------------------------------------  // acclient.c:754892
int _E1117_1()
{
  PStringBase<char>::PStringBase<char>(&EmissionLimit_4, "EmissionLimit");
  return atexit(_E1118_1);
}

//----- (006DD7C0) --------------------------------------------------------  // acclient.c:754899
int _E1120_1()
{
  PStringBase<char>::PStringBase<char>(&BlastCount_4, "BlastCount");
  return atexit(_E1121_1);
}

//----- (006DD7E0) --------------------------------------------------------  // acclient.c:754906
int _E1123_1()
{
  PStringBase<char>::PStringBase<char>(&StartTime_4, "StartTime");
  return atexit(_E1124_1);
}

//----- (006DD800) --------------------------------------------------------  // acclient.c:754913
int _E1126_1()
{
  PStringBase<char>::PStringBase<char>(&TimeLimit_4, "TimeLimit");
  return atexit(_E1127_1);
}

//----- (006DD820) --------------------------------------------------------  // acclient.c:754920
int _E1129_1()
{
  PStringBase<char>::PStringBase<char>(&EmissionDistance_4, "EmissionDistance");
  return atexit(_E1130_1);
}

//----- (006DD840) --------------------------------------------------------  // acclient.c:754927
int _E1132_1()
{
  PStringBase<char>::PStringBase<char>(&ParticleSnap_4, "ParticleSnap");
  return atexit(_E1133_1);
}

//----- (006DD860) --------------------------------------------------------  // acclient.c:754934
int _E1135_1()
{
  PStringBase<char>::PStringBase<char>(&InclusiveShape_4, "InclusiveShape");
  return atexit(_E1136_1);
}

//----- (006DD880) --------------------------------------------------------  // acclient.c:754941
int _E1138_1()
{
  PStringBase<char>::PStringBase<char>(&NumKeyframes_4, "NumKeyframes");
  return atexit(_E1139_1);
}

//----- (006DD8A0) --------------------------------------------------------  // acclient.c:754948
int _E1141_1()
{
  PStringBase<char>::PStringBase<char>(&IsActive_4, "IsActive");
  return atexit(_E1142_1);
}

//----- (006DD8C0) --------------------------------------------------------  // acclient.c:754955
int _E1144_1()
{
  PStringBase<char>::PStringBase<char>(&FadeIn_4, "FadeIn");
  return atexit(_E1145_1);
}

//----- (006DD8E0) --------------------------------------------------------  // acclient.c:754962
int _E1147_1()
{
  PStringBase<char>::PStringBase<char>(&FadeOut_4, "FadeOut");
  return atexit(_E1148_1);
}

//----- (006DD900) --------------------------------------------------------  // acclient.c:754969
int _E1150_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainX_4, "ConstrainX");
  return atexit(_E1151_1);
}

//----- (006DD920) --------------------------------------------------------  // acclient.c:754976
int _E1153_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainY_4, "ConstrainY");
  return atexit(_E1154_1);
}

//----- (006DD940) --------------------------------------------------------  // acclient.c:754983
int _E1156_1()
{
  PStringBase<char>::PStringBase<char>(&ConstrainZ_4, "ConstrainZ");
  return atexit(_E1157_1);
}

//----- (006DD960) --------------------------------------------------------  // acclient.c:754990
int _E1159_1()
{
  PStringBase<char>::PStringBase<char>(&NodeName_58, "Keyframe");
  return atexit(_E1160_1);
}

//----- (006DD980) --------------------------------------------------------  // acclient.c:754997
int _E1162_1()
{
  PStringBase<char>::PStringBase<char>(&Time_4, "Time");
  return atexit(_E1163_1);
}

//----- (006DD9A0) --------------------------------------------------------  // acclient.c:755004
int _E1165_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_4, "Flags");
  return atexit(_E1166_1);
}

//----- (006DD9C0) --------------------------------------------------------  // acclient.c:755011
int _E1168_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_None_4, "None");
  return atexit(_E1169_1);
}

//----- (006DD9E0) --------------------------------------------------------  // acclient.c:755018
int _E1171_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendScale_4, "BlendScale");
  return atexit(_E1172_1);
}

//----- (006DDA00) --------------------------------------------------------  // acclient.c:755025
int _E1174_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendColor_4, "BlendColor");
  return atexit(_E1175_1);
}

//----- (006DDA20) --------------------------------------------------------  // acclient.c:755032
int _E1177_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_BlendMass_4, "BlendMass");
  return atexit(_E1178_1);
}

//----- (006DDA40) --------------------------------------------------------  // acclient.c:755039
int _E1180_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetScale_4, "SetScale");
  return atexit(_E1181_1);
}

//----- (006DDA60) --------------------------------------------------------  // acclient.c:755046
int _E1183_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetColor_4, "SetColor");
  return atexit(_E1184_1);
}

//----- (006DDA80) --------------------------------------------------------  // acclient.c:755053
int _E1186_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetMass_4, "SetMass");
  return atexit(_E1187_1);
}

//----- (006DDAA0) --------------------------------------------------------  // acclient.c:755060
int _E1189_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPFlags_4, "SetParticleFlags");
  return atexit(_E1190_1);
}

//----- (006DDAC0) --------------------------------------------------------  // acclient.c:755067
int _E1192_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPCType_4, "SetControllerType");
  return atexit(_E1193_1);
}

//----- (006DDAE0) --------------------------------------------------------  // acclient.c:755074
int _E1195_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetPhysFlags_4, "SetPhysicsFlags");
  return atexit(_E1196_1);
}

//----- (006DDB00) --------------------------------------------------------  // acclient.c:755081
int _E1198_1()
{
  PStringBase<char>::PStringBase<char>(&Flags_SetParams_4, "SetParams");
  return atexit(_E1199_1);
}

//----- (006DDB20) --------------------------------------------------------  // acclient.c:755088
int _E1201_1()
{
  PStringBase<char>::PStringBase<char>(&Scale_16, "Scale");
  return atexit(_E1202_1);
}

//----- (006DDB40) --------------------------------------------------------  // acclient.c:755095
int _E1204_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleX_4, "ScaleX");
  return atexit(_E1205_1);
}

//----- (006DDB60) --------------------------------------------------------  // acclient.c:755102
int _E1207_1()
{
  PStringBase<char>::PStringBase<char>(&ScaleY_4, "ScaleY");
  return atexit(_E1208_1);
}

//----- (006DDB80) --------------------------------------------------------  // acclient.c:755109
int _E1210_1()
{
  PStringBase<char>::PStringBase<char>(&Color_4, "Color");
  return atexit(_E1211_1);
}

//----- (006DDBA0) --------------------------------------------------------  // acclient.c:755116
int _E1213_1()
{
  PStringBase<char>::PStringBase<char>(&Mass_4, "Mass");
  return atexit(_E1214_1);
}

//----- (006DDBC0) --------------------------------------------------------  // acclient.c:755123
int _E1216_1()
{
  PStringBase<char>::PStringBase<char>(&PFlags_4, "ParticleFlags");
  return atexit(_E1217_1);
}

//----- (006DDBE0) --------------------------------------------------------  // acclient.c:755130
int _E1219_1()
{
  PStringBase<char>::PStringBase<char>(&PFlags_None_4, "None");
  return atexit(_E1220_1);
}

//----- (006DDC00) --------------------------------------------------------  // acclient.c:755137
int _E1222_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_4, "ControllerType");
  return atexit(_E1223_1);
}

//----- (006DDC20) --------------------------------------------------------  // acclient.c:755144
int _E1225_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_None_4, "None");
  return atexit(_E1226_1);
}

//----- (006DDC40) --------------------------------------------------------  // acclient.c:755151
int _E1228_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_Physics_4, "Physics");
  return atexit(_E1229_1);
}

//----- (006DDC60) --------------------------------------------------------  // acclient.c:755158
int _E1231_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_Parametric_4, "Parametric");
  return atexit(_E1232_1);
}

//----- (006DDC80) --------------------------------------------------------  // acclient.c:755165
int _E1234_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_AttractRepulse_4, "AttractRepulse");
  return atexit(_E1235_1);
}

//----- (006DDCA0) --------------------------------------------------------  // acclient.c:755172
int _E1237_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFile_4, "PointFile");
  return atexit(_E1238_1);
}

//----- (006DDCC0) --------------------------------------------------------  // acclient.c:755179
int _E1240_1()
{
  PStringBase<char>::PStringBase<char>(&PCType_PointFileLerp_4, "PointFileLerp");
  return atexit(_E1241_1);
}

//----- (006DDCE0) --------------------------------------------------------  // acclient.c:755186
int _E1243_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_4, "PhysicsFlags");
  return atexit(_E1244_1);
}

//----- (006DDD00) --------------------------------------------------------  // acclient.c:755193
int _E1246_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_None_4, "None");
  return atexit(_E1247_1);
}

//----- (006DDD20) --------------------------------------------------------  // acclient.c:755200
int _E1249_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Gravity_4, "Gravity");
  return atexit(_E1250_1);
}

//----- (006DDD40) --------------------------------------------------------  // acclient.c:755207
int _E1252_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Wind_4, "Wind");
  return atexit(_E1253_1);
}

//----- (006DDD60) --------------------------------------------------------  // acclient.c:755214
int _E1255_1()
{
  PStringBase<char>::PStringBase<char>(&PhysFlags_Momentum_4, "Momentum");
  return atexit(_E1256_1);
}

//----- (006DDD80) --------------------------------------------------------  // acclient.c:755221
int _E1258_1()
{
  PStringBase<char>::PStringBase<char>(&PointfileFlags_RandomPoint_4, "RandomPoint");
  return atexit(_E1259_1);
}

//----- (006DDDA0) --------------------------------------------------------  // acclient.c:755228
int _E1261_1()
{
  PStringBase<char>::PStringBase<char>(&Position_5, "Position");
  return atexit(_E1262_1);
}

//----- (006DDDC0) --------------------------------------------------------  // acclient.c:755235
int _E1264_1()
{
  PStringBase<char>::PStringBase<char>(&PointList_4, "PointList");
  return atexit(_E1265_1);
}

//----- (006DDDE0) --------------------------------------------------------  // acclient.c:755242
int _E1267_1()
{
  PStringBase<char>::PStringBase<char>(&Point_10, "pt");
  return atexit(_E1268_1);
}

//----- (006DDE00) --------------------------------------------------------  // acclient.c:755249
int _E1270_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevels_4, "DetailLevels");
  return atexit(_E1271_1);
}

//----- (006DDE20) --------------------------------------------------------  // acclient.c:755256
int _E1273_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Low_4, "Low");
  return atexit(_E1274_1);
}

//----- (006DDE40) --------------------------------------------------------  // acclient.c:755263
int _E1276_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_Medium_4, "Medium");
  return atexit(_E1277_1);
}

//----- (006DDE60) --------------------------------------------------------  // acclient.c:755270
int _E1279_1()
{
  PStringBase<char>::PStringBase<char>(&DetailLevel_High_4, "High");
  return atexit(_E1280_2);
}

//----- (006DDE80) --------------------------------------------------------  // acclient.c:755277
int _E1282_1()
{
  PStringBase<char>::PStringBase<char>(&FadeSpeed_4, "FadeSpeed");
  return atexit(_E1283_1);
}

//----- (006DDEA0) --------------------------------------------------------  // acclient.c:755284
int _E1285_1()
{
  PStringBase<char>::PStringBase<char>(&MaxOpacity_4, "MaxOpacity");
  return atexit(_E1286_1);
}

//----- (006DDEC0) --------------------------------------------------------  // acclient.c:755291
int _E1288_1()
{
  PStringBase<char>::PStringBase<char>(&Point_11, "Point");
  return atexit(_E1289_0);
}

//----- (006DDEE0) --------------------------------------------------------  // acclient.c:755298
int _E1291_0()
{
  PStringBase<char>::PStringBase<char>(&PointAxisPos_4, "AxisPos");
  return atexit(_E1292_1);
}

//----- (006DDF00) --------------------------------------------------------  // acclient.c:755305
int _E1294_1()
{
  PStringBase<char>::PStringBase<char>(&PointTexture_4, "Texture");
  return atexit(_E1295_0);
}

//----- (006DDF20) --------------------------------------------------------  // acclient.c:755312
int _E1297_0()
{
  PStringBase<char>::PStringBase<char>(&PointSize_4, "Size");
  return atexit(_E1298_0);
}

//----- (006DDF40) --------------------------------------------------------  // acclient.c:755319
int _E1300_0()
{
  PStringBase<char>::PStringBase<char>(&UseOcclusion_4, "UseOcclusion");
  return atexit(_E1301_0);
}

//----- (006DDF60) --------------------------------------------------------  // acclient.c:755326
int _E1303_0()
{
  return atexit(_E1304_0);
}

//----- (006DDF70) --------------------------------------------------------  // acclient.c:755332
int _E1306_0()
{
  return atexit(_E1307_0);
}

//----- (006DDF80) --------------------------------------------------------  // acclient.c:755338
int _E1309_0()
{
  return atexit(_E1310_0);
}

//----- (006DDF90) --------------------------------------------------------  // acclient.c:755344
int _E1312_0()
{
  PStringBase<char>::PStringBase<char>(PHEADER_STRINGS_4, "COMPATABILITY_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83B158, "TOOL_VERSION");
  PStringBase<char>::PStringBase<char>(&stru_83B15C, "SOURCE_FILE_NAME");
  PStringBase<char>::PStringBase<char>(&stru_83B160, "PREPROC_OPTIONS");
  return atexit(_E1313_0);
}

//----- (006DDFE0) --------------------------------------------------------  // acclient.c:755354
int _E1_43()
{
  return atexit(_E2_43);
}

//----- (00746390) --------------------------------------------------------  // acclient.c:859730
void __cdecl _E74_36()
{
  char *v0; // esi@1

  v0 = &waveform_None_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_None_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007463C0) --------------------------------------------------------  // acclient.c:859743
void __cdecl _E77_50()
{
  char *v0; // esi@1

  v0 = &waveform_Speed_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Speed_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007463F0) --------------------------------------------------------  // acclient.c:859756
void __cdecl _E80_24()
{
  char *v0; // esi@1

  v0 = &waveform_Noise_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Noise_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746420) --------------------------------------------------------  // acclient.c:859769
void __cdecl _E83_14()
{
  char *v0; // esi@1

  v0 = &waveform_Sine_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Sine_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746450) --------------------------------------------------------  // acclient.c:859782
void __cdecl _E86_11()
{
  char *v0; // esi@1

  v0 = &waveform_Square_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Square_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746480) --------------------------------------------------------  // acclient.c:859795
void __cdecl _E89_22()
{
  char *v0; // esi@1

  v0 = &waveform_Bounce_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Bounce_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007464B0) --------------------------------------------------------  // acclient.c:859808
void __cdecl _E92_24()
{
  char *v0; // esi@1

  v0 = &waveform_Perlin_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Perlin_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007464E0) --------------------------------------------------------  // acclient.c:859821
void __cdecl sub_7464E0()
{
  char *v0; // esi@1

  v0 = &waveform_Fractal_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_Fractal_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746510) --------------------------------------------------------  // acclient.c:859834
void __cdecl _E98_39()
{
  char *v0; // esi@1

  v0 = &waveform_FrameLoop_19.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&waveform_FrameLoop_19.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746540) --------------------------------------------------------  // acclient.c:859847
void __cdecl _E119_62()
{
  char *v0; // esi@1

  v0 = &PHeader_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PHeader_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746570) --------------------------------------------------------  // acclient.c:859860
void __cdecl _E122_49()
{
  char *v0; // esi@1

  v0 = &VertexArray_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexArray_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007465A0) --------------------------------------------------------  // acclient.c:859873
void __cdecl _E125_24()
{
  char *v0; // esi@1

  v0 = &BinaryVertexArray_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BinaryVertexArray_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007465D0) --------------------------------------------------------  // acclient.c:859886
void __cdecl _E128_25()
{
  char *v0; // esi@1

  v0 = &VertexType_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexType_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746600) --------------------------------------------------------  // acclient.c:859899
void __cdecl _E131_21()
{
  char *v0; // esi@1

  v0 = &VertexData_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexData_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746630) --------------------------------------------------------  // acclient.c:859912
void __cdecl _E134_20()
{
  char *v0; // esi@1

  v0 = &Vertex_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Vertex_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746660) --------------------------------------------------------  // acclient.c:859925
void __cdecl _E137_20()
{
  char *v0; // esi@1

  v0 = &Index_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746690) --------------------------------------------------------  // acclient.c:859938
void __cdecl _E140_15()
{
  char *v0; // esi@1

  v0 = &Origin_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007466C0) --------------------------------------------------------  // acclient.c:859951
void __cdecl _E143_16()
{
  char *v0; // esi@1

  v0 = &Normal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Normal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007466F0) --------------------------------------------------------  // acclient.c:859964
void __cdecl _E146_15()
{
  char *v0; // esi@1

  v0 = &Diffuse_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746720) --------------------------------------------------------  // acclient.c:859977
void __cdecl _E149_15()
{
  char *v0; // esi@1

  v0 = &Specular_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746750) --------------------------------------------------------  // acclient.c:859990
void __cdecl _E152_14()
{
  char *v0; // esi@1

  v0 = &UVS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UVS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746780) --------------------------------------------------------  // acclient.c:860003
void __cdecl _E155_12()
{
  char *v0; // esi@1

  v0 = &VectorS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007467B0) --------------------------------------------------------  // acclient.c:860016
void __cdecl _E158_15()
{
  char *v0; // esi@1

  v0 = &VectorT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007467E0) --------------------------------------------------------  // acclient.c:860029
void __cdecl _E161_12()
{
  char *v0; // esi@1

  v0 = &VectorSxT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VectorSxT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746810) --------------------------------------------------------  // acclient.c:860042
void __cdecl _E164_15()
{
  char *v0; // esi@1

  v0 = &Weights_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weights_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746840) --------------------------------------------------------  // acclient.c:860055
void __cdecl _E167_11()
{
  char *v0; // esi@1

  v0 = &Importance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Importance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746870) --------------------------------------------------------  // acclient.c:860068
void __cdecl _E170_10()
{
  char *v0; // esi@1

  v0 = &PhysMtl_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMtl_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007468A0) --------------------------------------------------------  // acclient.c:860081
void __cdecl _E173_9()
{
  char *v0; // esi@1

  v0 = &Material_20.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_20.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007468D0) --------------------------------------------------------  // acclient.c:860094
void __cdecl _E176_10()
{
  char *v0; // esi@1

  v0 = &ID_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746900) --------------------------------------------------------  // acclient.c:860107
void __cdecl _E179_9()
{
  char *v0; // esi@1

  v0 = &FileName_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FileName_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746930) --------------------------------------------------------  // acclient.c:860120
void __cdecl _E182_9()
{
  char *v0; // esi@1

  v0 = &Polygon_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746960) --------------------------------------------------------  // acclient.c:860133
void __cdecl _E185_6()
{
  char *v0; // esi@1

  v0 = &ID_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ID_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746990) --------------------------------------------------------  // acclient.c:860146
void __cdecl _E188_7()
{
  char *v0; // esi@1

  v0 = &Indices_6.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Indices_6.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007469C0) --------------------------------------------------------  // acclient.c:860159
void __cdecl _E191_6()
{
  char *v0; // esi@1

  v0 = &MaterialID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007469F0) --------------------------------------------------------  // acclient.c:860172
void __cdecl _E194_13()
{
  char *v0; // esi@1

  v0 = &PhysMaterialID_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysMaterialID_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746A20) --------------------------------------------------------  // acclient.c:860185
void __cdecl _E197_4()
{
  char *v0; // esi@1

  v0 = &Markings_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Markings_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746A50) --------------------------------------------------------  // acclient.c:860198
void __cdecl _E200_9()
{
  char *v0; // esi@1

  v0 = &Material_21.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_21.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746A80) --------------------------------------------------------  // acclient.c:860211
void __cdecl _E203_8()
{
  char *v0; // esi@1

  v0 = &Index_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Index_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746AB0) --------------------------------------------------------  // acclient.c:860224
void __cdecl _E206_11()
{
  char *v0; // esi@1

  v0 = &Filename_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Filename_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746AE0) --------------------------------------------------------  // acclient.c:860237
void __cdecl _E209_6()
{
  char *v0; // esi@1

  v0 = &Surface_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Surface_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746B10) --------------------------------------------------------  // acclient.c:860250
void __cdecl _E212_9()
{
  char *v0; // esi@1

  v0 = &CellPoly_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPoly_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746B40) --------------------------------------------------------  // acclient.c:860263
void __cdecl _E215_5()
{
  char *v0; // esi@1

  v0 = &Sphere_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sphere_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746B70) --------------------------------------------------------  // acclient.c:860276
void __cdecl _E218_6()
{
  char *v0; // esi@1

  v0 = &Side_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Side_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746BA0) --------------------------------------------------------  // acclient.c:860289
void __cdecl _E221_6()
{
  char *v0; // esi@1

  v0 = &Positive_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Positive_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746BD0) --------------------------------------------------------  // acclient.c:860302
void __cdecl _E224_6()
{
  char *v0; // esi@1

  v0 = &Negative_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Negative_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746C00) --------------------------------------------------------  // acclient.c:860315
void __cdecl _E227_6()
{
  char *v0; // esi@1

  v0 = &Polygon_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Polygon_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746C30) --------------------------------------------------------  // acclient.c:860328
void __cdecl _E230_6()
{
  char *v0; // esi@1

  v0 = &OtherCell_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746C60) --------------------------------------------------------  // acclient.c:860341
void __cdecl _E233_5()
{
  char *v0; // esi@1

  v0 = &CellPortal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CellPortal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746C90) --------------------------------------------------------  // acclient.c:860354
void __cdecl _E236_5()
{
  char *v0; // esi@1

  v0 = &Portal_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Portal_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746CC0) --------------------------------------------------------  // acclient.c:860367
void __cdecl _E239_6()
{
  char *v0; // esi@1

  v0 = &OtherCell_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherCell_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746CF0) --------------------------------------------------------  // acclient.c:860380
void __cdecl _E242_6()
{
  char *v0; // esi@1

  v0 = &OtherPortal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&OtherPortal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746D20) --------------------------------------------------------  // acclient.c:860393
void __cdecl _E245_5()
{
  char *v0; // esi@1

  v0 = &ExactMatch_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExactMatch_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746D50) --------------------------------------------------------  // acclient.c:860406
void __cdecl _E248_5()
{
  char *v0; // esi@1

  v0 = &StabList_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StabList_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746D80) --------------------------------------------------------  // acclient.c:860419
void __cdecl _E251_5()
{
  char *v0; // esi@1

  v0 = &Period_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Period_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746DB0) --------------------------------------------------------  // acclient.c:860432
void __cdecl _E254_6()
{
  char *v0; // esi@1

  v0 = &GrannyAnimation_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&GrannyAnimation_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746DE0) --------------------------------------------------------  // acclient.c:860445
void __cdecl _E257_4()
{
  char *v0; // esi@1

  v0 = &Transform_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Transform_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746E10) --------------------------------------------------------  // acclient.c:860458
void __cdecl _E260_5()
{
  char *v0; // esi@1

  v0 = &Scale_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746E40) --------------------------------------------------------  // acclient.c:860471
void __cdecl _E263_3()
{
  char *v0; // esi@1

  v0 = &Weight_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Weight_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746E70) --------------------------------------------------------  // acclient.c:860484
void __cdecl _E266_3()
{
  char *v0; // esi@1

  v0 = &Offset_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Offset_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746EA0) --------------------------------------------------------  // acclient.c:860497
void __cdecl _E269_3()
{
  char *v0; // esi@1

  v0 = &Quaternion_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Quaternion_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746ED0) --------------------------------------------------------  // acclient.c:860510
void __cdecl _E272_2()
{
  char *v0; // esi@1

  v0 = &Rotation_9.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_9.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746F00) --------------------------------------------------------  // acclient.c:860523
void __cdecl _E275_2()
{
  char *v0; // esi@1

  v0 = &STime_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&STime_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746F30) --------------------------------------------------------  // acclient.c:860536
void __cdecl _E278_2()
{
  char *v0; // esi@1

  v0 = &PhysicsSplines_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsSplines_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746F60) --------------------------------------------------------  // acclient.c:860549
void __cdecl _E281_3()
{
  char *v0; // esi@1

  v0 = &BoneOpacities_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BoneOpacities_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746F90) --------------------------------------------------------  // acclient.c:860562
void __cdecl _E284_2()
{
  char *v0; // esi@1

  v0 = &LowPt_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&LowPt_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746FC0) --------------------------------------------------------  // acclient.c:860575
void __cdecl _E287_3()
{
  char *v0; // esi@1

  v0 = &Radius_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Radius_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00746FF0) --------------------------------------------------------  // acclient.c:860588
void __cdecl _E290_3()
{
  char *v0; // esi@1

  v0 = &Height_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Height_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747020) --------------------------------------------------------  // acclient.c:860601
void __cdecl _E293_2()
{
  char *v0; // esi@1

  v0 = &Texture2D_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture2D_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747050) --------------------------------------------------------  // acclient.c:860614
void __cdecl _E296_3()
{
  char *v0; // esi@1

  v0 = &Texture3D_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture3D_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747080) --------------------------------------------------------  // acclient.c:860627
void __cdecl _E299_1()
{
  char *v0; // esi@1

  v0 = &TextureCube_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureCube_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007470B0) --------------------------------------------------------  // acclient.c:860640
void __cdecl _E302_2()
{
  char *v0; // esi@1

  v0 = &TextureMovie2D_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TextureMovie2D_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007470E0) --------------------------------------------------------  // acclient.c:860653
void __cdecl _E305_1()
{
  char *v0; // esi@1

  v0 = &MovieFileName_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFileName_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747110) --------------------------------------------------------  // acclient.c:860666
void __cdecl _E308_2()
{
  char *v0; // esi@1

  v0 = &MovieFramesPerSecond_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MovieFramesPerSecond_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747140) --------------------------------------------------------  // acclient.c:860679
void __cdecl _E311_1()
{
  char *v0; // esi@1

  v0 = &Levels_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Levels_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747170) --------------------------------------------------------  // acclient.c:860692
void __cdecl _E314_2()
{
  char *v0; // esi@1

  v0 = &NodeName_49.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_49.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007471A0) --------------------------------------------------------  // acclient.c:860705
void __cdecl _E317_1()
{
  char *v0; // esi@1

  v0 = &Material_22.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_22.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007471D0) --------------------------------------------------------  // acclient.c:860718
void __cdecl _E320_2()
{
  char *v0; // esi@1

  v0 = &MaterialType_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaterialType_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747200) --------------------------------------------------------  // acclient.c:860731
void __cdecl _E323_1()
{
  char *v0; // esi@1

  v0 = &Modifier_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Modifier_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747230) --------------------------------------------------------  // acclient.c:860744
void __cdecl _E326_2()
{
  char *v0; // esi@1

  v0 = &AllowStencilShadows_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AllowStencilShadows_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747260) --------------------------------------------------------  // acclient.c:860757
void __cdecl _E329_1()
{
  char *v0; // esi@1

  v0 = &DiscardGeometry_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DiscardGeometry_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747290) --------------------------------------------------------  // acclient.c:860770
void __cdecl _E332_2()
{
  char *v0; // esi@1

  v0 = &NodeName_50.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_50.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007472C0) --------------------------------------------------------  // acclient.c:860783
void __cdecl _E335_1()
{
  char *v0; // esi@1

  v0 = &SortMode_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007472F0) --------------------------------------------------------  // acclient.c:860796
void __cdecl _E338_1()
{
  char *v0; // esi@1

  v0 = &SortMode_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747320) --------------------------------------------------------  // acclient.c:860809
void __cdecl _E341_1()
{
  char *v0; // esi@1

  v0 = &SortMode_Triangle_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SortMode_Triangle_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747350) --------------------------------------------------------  // acclient.c:860822
void __cdecl _E344_1()
{
  char *v0; // esi@1

  v0 = &NodeName_51.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_51.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747380) --------------------------------------------------------  // acclient.c:860835
void __cdecl _E347_1()
{
  char *v0; // esi@1

  v0 = &NodeName_52.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_52.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007473B0) --------------------------------------------------------  // acclient.c:860848
void __cdecl _E350_1()
{
  char *v0; // esi@1

  v0 = &DataType_DATA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_DATA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007473E0) --------------------------------------------------------  // acclient.c:860861
void __cdecl _E353_1()
{
  char *v0; // esi@1

  v0 = &DataType_WAVEFORM_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_WAVEFORM_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747410) --------------------------------------------------------  // acclient.c:860874
void __cdecl _E356_1()
{
  char *v0; // esi@1

  v0 = &DataType_COLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_COLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747440) --------------------------------------------------------  // acclient.c:860887
void __cdecl _E359_1()
{
  char *v0; // esi@1

  v0 = &DataType_TEXTURE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_TEXTURE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747470) --------------------------------------------------------  // acclient.c:860900
void __cdecl _E362_1()
{
  char *v0; // esi@1

  v0 = &DataType_BOOL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DataType_BOOL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007474A0) --------------------------------------------------------  // acclient.c:860913
void __cdecl _E365_1()
{
  char *v0; // esi@1

  v0 = &NodeName_53.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_53.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007474D0) --------------------------------------------------------  // acclient.c:860926
void __cdecl _E368_1()
{
  char *v0; // esi@1

  v0 = &modType_UVTranslate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTranslate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747500) --------------------------------------------------------  // acclient.c:860939
void __cdecl _E371_1()
{
  char *v0; // esi@1

  v0 = &modType_UVRotate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVRotate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747530) --------------------------------------------------------  // acclient.c:860952
void __cdecl _E374_1()
{
  char *v0; // esi@1

  v0 = &modType_UVScale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVScale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747560) --------------------------------------------------------  // acclient.c:860965
void __cdecl _E377_1()
{
  char *v0; // esi@1

  v0 = &modType_UVTransform_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&modType_UVTransform_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747590) --------------------------------------------------------  // acclient.c:860978
void __cdecl _E380_1()
{
  char *v0; // esi@1

  v0 = &TrueFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TrueFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007475C0) --------------------------------------------------------  // acclient.c:860991
void __cdecl _E383_1()
{
  char *v0; // esi@1

  v0 = &FalseFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FalseFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007475F0) --------------------------------------------------------  // acclient.c:861004
void __cdecl _E386_1()
{
  char *v0; // esi@1

  v0 = &RenderPass_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RenderPass_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747620) --------------------------------------------------------  // acclient.c:861017
void __cdecl _E389_1()
{
  char *v0; // esi@1

  v0 = &Blend_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Blend_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747650) --------------------------------------------------------  // acclient.c:861030
void __cdecl _E392_1()
{
  char *v0; // esi@1

  v0 = &DepthTest_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthTest_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747680) --------------------------------------------------------  // acclient.c:861043
void __cdecl _E395_1()
{
  char *v0; // esi@1

  v0 = &DepthWrite_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthWrite_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007476B0) --------------------------------------------------------  // acclient.c:861056
void __cdecl _E398_1()
{
  char *v0; // esi@1

  v0 = &CullMode_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&CullMode_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007476E0) --------------------------------------------------------  // acclient.c:861069
void __cdecl _E401_1()
{
  char *v0; // esi@1

  v0 = &DepthFog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DepthFog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747710) --------------------------------------------------------  // acclient.c:861082
void __cdecl _E404_1()
{
  char *v0; // esi@1

  v0 = &AlphaTestMode_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestMode_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747740) --------------------------------------------------------  // acclient.c:861095
void __cdecl _E407_1()
{
  char *v0; // esi@1

  v0 = &AlphaTestRef_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaTestRef_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747770) --------------------------------------------------------  // acclient.c:861108
void __cdecl _E410_1()
{
  char *v0; // esi@1

  v0 = &FFUseLighting_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseLighting_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007477A0) --------------------------------------------------------  // acclient.c:861121
void __cdecl _E413_1()
{
  char *v0; // esi@1

  v0 = &FFUseDyeColorInTFactor_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDyeColorInTFactor_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007477D0) --------------------------------------------------------  // acclient.c:861134
void __cdecl _E416_1()
{
  char *v0; // esi@1

  v0 = &FFUseSpecularLighting_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseSpecularLighting_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747800) --------------------------------------------------------  // acclient.c:861147
void __cdecl _E419_1()
{
  char *v0; // esi@1

  v0 = &FFUseDistanceFog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseDistanceFog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747830) --------------------------------------------------------  // acclient.c:861160
void __cdecl _E422_1()
{
  char *v0; // esi@1

  v0 = &FFUseVertexDiffuse_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexDiffuse_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747860) --------------------------------------------------------  // acclient.c:861173
void __cdecl _E425_1()
{
  char *v0; // esi@1

  v0 = &FFUseVertexSpecular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FFUseVertexSpecular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747890) --------------------------------------------------------  // acclient.c:861186
void __cdecl _E428_1()
{
  char *v0; // esi@1

  v0 = &ShaderSupportsDynamicLights_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ShaderSupportsDynamicLights_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007478C0) --------------------------------------------------------  // acclient.c:861199
void __cdecl _E431_1()
{
  char *v0; // esi@1

  v0 = &UsesTransparency_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UsesTransparency_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007478F0) --------------------------------------------------------  // acclient.c:861212
void __cdecl _E434_1()
{
  char *v0; // esi@1

  v0 = &Ambient_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Ambient_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747920) --------------------------------------------------------  // acclient.c:861225
void __cdecl _E437_1()
{
  char *v0; // esi@1

  v0 = &Diffuse_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Diffuse_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747950) --------------------------------------------------------  // acclient.c:861238
void __cdecl _E440_1()
{
  char *v0; // esi@1

  v0 = &Specular_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Specular_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747980) --------------------------------------------------------  // acclient.c:861251
void __cdecl _E443_1()
{
  char *v0; // esi@1

  v0 = &SpecularPower_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecularPower_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007479B0) --------------------------------------------------------  // acclient.c:861264
void __cdecl _E446_1()
{
  char *v0; // esi@1

  v0 = &Dye_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Dye_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007479E0) --------------------------------------------------------  // acclient.c:861277
void __cdecl _E449_1()
{
  char *v0; // esi@1

  v0 = &Emissive_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Emissive_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747A10) --------------------------------------------------------  // acclient.c:861290
void __cdecl _E452_1()
{
  char *v0; // esi@1

  v0 = &VertexFormat_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexFormat_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747A40) --------------------------------------------------------  // acclient.c:861303
void __cdecl _E455_1()
{
  char *v0; // esi@1

  v0 = &VertexShader_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&VertexShader_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747A70) --------------------------------------------------------  // acclient.c:861316
void __cdecl _E458_1()
{
  char *v0; // esi@1

  v0 = &PixelShader_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PixelShader_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747AA0) --------------------------------------------------------  // acclient.c:861329
void __cdecl _E461_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_NONE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_NONE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747AD0) --------------------------------------------------------  // acclient.c:861342
void __cdecl _E464_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_REFLECTIONS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_REFLECTIONS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747B00) --------------------------------------------------------  // acclient.c:861355
void __cdecl _E467_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_VIDEOPOST_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_VIDEOPOST_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747B30) --------------------------------------------------------  // acclient.c:861368
void __cdecl _E470_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_HIGHDETAIL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_HIGHDETAIL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747B60) --------------------------------------------------------  // acclient.c:861381
void __cdecl _E473_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_SPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_SPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747B90) --------------------------------------------------------  // acclient.c:861394
void __cdecl _E476_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS1_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS1_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747BC0) --------------------------------------------------------  // acclient.c:861407
void __cdecl _E479_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS2_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS2_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747BF0) --------------------------------------------------------  // acclient.c:861420
void __cdecl _E482_1()
{
  char *v0; // esi@1

  v0 = &param_MLF_CLASS3_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_MLF_CLASS3_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747C20) --------------------------------------------------------  // acclient.c:861433
void __cdecl _E485_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_Default_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_Default_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747C50) --------------------------------------------------------  // acclient.c:861446
void __cdecl _E488_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DirectionalLightDiffuseAndSpecular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DirectionalLightDiffuseAndSpecular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747C80) --------------------------------------------------------  // acclient.c:861459
void __cdecl _E491_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747CB0) --------------------------------------------------------  // acclient.c:861472
void __cdecl _E494_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_PointLightDiffuseAndSpecularProjector_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_PointLightDiffuseAndSpecularProjector_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747CE0) --------------------------------------------------------  // acclient.c:861485
void __cdecl _E497_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747D10) --------------------------------------------------------  // acclient.c:861498
void __cdecl _E500_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747D40) --------------------------------------------------------  // acclient.c:861511
void __cdecl _E503_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_DistanceFog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_DistanceFog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747D70) --------------------------------------------------------  // acclient.c:861524
void __cdecl _E506_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_FixedFunctionGlow_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_FixedFunctionGlow_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747DA0) --------------------------------------------------------  // acclient.c:861537
void __cdecl _E509_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_ShaderGlow_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_ShaderGlow_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747DD0) --------------------------------------------------------  // acclient.c:861550
void __cdecl _E512_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_LandscapeShadowMap_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_LandscapeShadowMap_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747E00) --------------------------------------------------------  // acclient.c:861563
void __cdecl _E515_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AlphaBlend_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AlphaBlend_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747E30) --------------------------------------------------------  // acclient.c:861576
void __cdecl _E518_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747E60) --------------------------------------------------------  // acclient.c:861589
void __cdecl _E521_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747E90) --------------------------------------------------------  // acclient.c:861602
void __cdecl _E524_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747EC0) --------------------------------------------------------  // acclient.c:861615
void __cdecl _E527_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747EF0) --------------------------------------------------------  // acclient.c:861628
void __cdecl _E530_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747F20) --------------------------------------------------------  // acclient.c:861641
void __cdecl _E533_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747F50) --------------------------------------------------------  // acclient.c:861654
void __cdecl _E536_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747F80) --------------------------------------------------------  // acclient.c:861667
void __cdecl _E539_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747FB0) --------------------------------------------------------  // acclient.c:861680
void __cdecl _E542_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00747FE0) --------------------------------------------------------  // acclient.c:861693
void __cdecl _E545_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748010) --------------------------------------------------------  // acclient.c:861706
void __cdecl _E548_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748040) --------------------------------------------------------  // acclient.c:861719
void __cdecl _E551_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748070) --------------------------------------------------------  // acclient.c:861732
void __cdecl _E554_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007480A0) --------------------------------------------------------  // acclient.c:861745
void __cdecl _E557_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007480D0) --------------------------------------------------------  // acclient.c:861758
void __cdecl _E560_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748100) --------------------------------------------------------  // acclient.c:861771
void __cdecl _E563_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748130) --------------------------------------------------------  // acclient.c:861784
void __cdecl _E566_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748160) --------------------------------------------------------  // acclient.c:861797
void __cdecl _E569_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_0PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_0PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748190) --------------------------------------------------------  // acclient.c:861810
void __cdecl _E572_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_1PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_1PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007481C0) --------------------------------------------------------  // acclient.c:861823
void __cdecl _E575_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_2PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_2PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007481F0) --------------------------------------------------------  // acclient.c:861836
void __cdecl _E578_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_3PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_3PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748220) --------------------------------------------------------  // acclient.c:861849
void __cdecl _E581_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_4PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_4PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748250) --------------------------------------------------------  // acclient.c:861862
void __cdecl _E584_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_5PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_5PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748280) --------------------------------------------------------  // acclient.c:861875
void __cdecl _E587_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_6PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_6PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007482B0) --------------------------------------------------------  // acclient.c:861888
void __cdecl _E590_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_7PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_7PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007482E0) --------------------------------------------------------  // acclient.c:861901
void __cdecl _E593_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_0DL_8PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_0DL_8PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748310) --------------------------------------------------------  // acclient.c:861914
void __cdecl _E596_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_0PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_0PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748340) --------------------------------------------------------  // acclient.c:861927
void __cdecl _E599_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_1PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_1PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748370) --------------------------------------------------------  // acclient.c:861940
void __cdecl _E602_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_2PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_2PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007483A0) --------------------------------------------------------  // acclient.c:861953
void __cdecl _E605_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_3PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_3PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007483D0) --------------------------------------------------------  // acclient.c:861966
void __cdecl _E608_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_4PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_4PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748400) --------------------------------------------------------  // acclient.c:861979
void __cdecl _E611_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_5PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_5PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748430) --------------------------------------------------------  // acclient.c:861992
void __cdecl _E614_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_6PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_6PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748460) --------------------------------------------------------  // acclient.c:862005
void __cdecl _E617_1()
{
  char *v0; // esi@1

  v0 = &param_RenderPass_AL_1DL_7PL_Fog_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_RenderPass_AL_1DL_7PL_Fog_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748490) --------------------------------------------------------  // acclient.c:862018
void __cdecl _E620_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ZERO_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ZERO_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007484C0) --------------------------------------------------------  // acclient.c:862031
void __cdecl _E623_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_ONE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_ONE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007484F0) --------------------------------------------------------  // acclient.c:862044
void __cdecl _E626_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748520) --------------------------------------------------------  // acclient.c:862057
void __cdecl _E629_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748550) --------------------------------------------------------  // acclient.c:862070
void __cdecl _E632_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748580) --------------------------------------------------------  // acclient.c:862083
void __cdecl _E635_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVSRCALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVSRCALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007485B0) --------------------------------------------------------  // acclient.c:862096
void __cdecl _E638_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007485E0) --------------------------------------------------------  // acclient.c:862109
void __cdecl _E641_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748610) --------------------------------------------------------  // acclient.c:862122
void __cdecl _E644_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_DSTCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_DSTCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748640) --------------------------------------------------------  // acclient.c:862135
void __cdecl _E647_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_INVDSTCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_INVDSTCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748670) --------------------------------------------------------  // acclient.c:862148
void __cdecl _E650_1()
{
  char *v0; // esi@1

  v0 = &param_BLEND_SRCALPHASAT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_BLEND_SRCALPHASAT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007486A0) --------------------------------------------------------  // acclient.c:862161
void __cdecl _E653_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007486D0) --------------------------------------------------------  // acclient.c:862174
void __cdecl _E656_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_EQUAL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_EQUAL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748700) --------------------------------------------------------  // acclient.c:862187
void __cdecl _E659_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_LESSEQUAL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_LESSEQUAL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748730) --------------------------------------------------------  // acclient.c:862200
void __cdecl _E662_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748760) --------------------------------------------------------  // acclient.c:862213
void __cdecl _E665_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_NOTEQUAL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_NOTEQUAL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748790) --------------------------------------------------------  // acclient.c:862226
void __cdecl _E668_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_GREATEREQUAL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_GREATEREQUAL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007487C0) --------------------------------------------------------  // acclient.c:862239
void __cdecl _E671_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHTEST_ALWAYS_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHTEST_ALWAYS_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007487F0) --------------------------------------------------------  // acclient.c:862252
void __cdecl _E674_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_ON_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_ON_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748820) --------------------------------------------------------  // acclient.c:862265
void __cdecl _E677_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHWRITE_OFF_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHWRITE_OFF_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748850) --------------------------------------------------------  // acclient.c:862278
void __cdecl _E680_1()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERDIFFUSE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERDIFFUSE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748880) --------------------------------------------------------  // acclient.c:862291
void __cdecl _E683_1()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_LAYERSPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_LAYERSPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007488B0) --------------------------------------------------------  // acclient.c:862304
void __cdecl _E686_1()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXDIFFUSE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXDIFFUSE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007488E0) --------------------------------------------------------  // acclient.c:862317
void __cdecl _E689_1()
{
  char *v0; // esi@1

  v0 = &param_COLORSOURCE_VERTEXSPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_COLORSOURCE_VERTEXSPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748910) --------------------------------------------------------  // acclient.c:862330
void __cdecl _E692_1()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_NONE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_NONE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748940) --------------------------------------------------------  // acclient.c:862343
void __cdecl _E695_1()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CW_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CW_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748970) --------------------------------------------------------  // acclient.c:862356
void __cdecl _E698_1()
{
  char *v0; // esi@1

  v0 = &param_CULLMODE_CCW_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_CULLMODE_CCW_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007489A0) --------------------------------------------------------  // acclient.c:862369
void __cdecl _E701_1()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_NONE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_NONE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007489D0) --------------------------------------------------------  // acclient.c:862382
void __cdecl _E704_1()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SIMPLE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SIMPLE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748A00) --------------------------------------------------------  // acclient.c:862395
void __cdecl _E707_1()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_DIFFUSE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_DIFFUSE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748A30) --------------------------------------------------------  // acclient.c:862408
void __cdecl _E710_1()
{
  char *v0; // esi@1

  v0 = &param_LIGHTMODE_SPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_LIGHTMODE_SPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748A60) --------------------------------------------------------  // acclient.c:862421
void __cdecl _E713_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_OFF_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_OFF_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748A90) --------------------------------------------------------  // acclient.c:862434
void __cdecl _E716_1()
{
  char *v0; // esi@1

  v0 = &param_DEPTHFOG_ON_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_DEPTHFOG_ON_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748AC0) --------------------------------------------------------  // acclient.c:862447
void __cdecl _E719_1()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_OFF_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_OFF_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748AF0) --------------------------------------------------------  // acclient.c:862460
void __cdecl _E722_1()
{
  char *v0; // esi@1

  v0 = &param_ALPHATESTMODE_ON_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_ALPHATESTMODE_ON_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748B20) --------------------------------------------------------  // acclient.c:862473
void __cdecl _E725_1()
{
  char *v0; // esi@1

  v0 = &param_VF_ORIGIN_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_ORIGIN_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748B50) --------------------------------------------------------  // acclient.c:862486
void __cdecl _E728_1()
{
  char *v0; // esi@1

  v0 = &param_VF_NORMAL_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_NORMAL_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748B80) --------------------------------------------------------  // acclient.c:862499
void __cdecl _E731_1()
{
  char *v0; // esi@1

  v0 = &param_VF_POINTSIZE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_POINTSIZE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748BB0) --------------------------------------------------------  // acclient.c:862512
void __cdecl _E734_1()
{
  char *v0; // esi@1

  v0 = &param_VF_DIFFUSE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_DIFFUSE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748BE0) --------------------------------------------------------  // acclient.c:862525
void __cdecl _E737_1()
{
  char *v0; // esi@1

  v0 = &param_VF_SPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_SPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748C10) --------------------------------------------------------  // acclient.c:862538
void __cdecl _E740_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx1_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx1_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748C40) --------------------------------------------------------  // acclient.c:862551
void __cdecl _E743_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx2_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx2_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748C70) --------------------------------------------------------  // acclient.c:862564
void __cdecl _E746_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx3_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx3_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748CA0) --------------------------------------------------------  // acclient.c:862577
void __cdecl _E749_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx4_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx4_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748CD0) --------------------------------------------------------  // acclient.c:862590
void __cdecl _E752_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx5_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx5_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748D00) --------------------------------------------------------  // acclient.c:862603
void __cdecl _E755_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx6_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx6_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748D30) --------------------------------------------------------  // acclient.c:862616
void __cdecl _E758_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx7_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx7_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748D60) --------------------------------------------------------  // acclient.c:862629
void __cdecl _E761_1()
{
  char *v0; // esi@1

  v0 = &param_VF_TCPAIRx8_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_TCPAIRx8_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748D90) --------------------------------------------------------  // acclient.c:862642
void __cdecl _E764_1()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_S_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_S_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748DC0) --------------------------------------------------------  // acclient.c:862655
void __cdecl _E767_1()
{
  char *v0; // esi@1

  v0 = &param_VF_VECTOR_T_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_VF_VECTOR_T_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748DF0) --------------------------------------------------------  // acclient.c:862668
void __cdecl _E770_1()
{
  char *v0; // esi@1

  v0 = &NodeName_54.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_54.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748E20) --------------------------------------------------------  // acclient.c:862681
void __cdecl _E773_1()
{
  char *v0; // esi@1

  v0 = &SamplerNodeName_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerNodeName_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748E50) --------------------------------------------------------  // acclient.c:862694
void __cdecl _E776_1()
{
  char *v0; // esi@1

  v0 = &SamplerName_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SamplerName_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748E80) --------------------------------------------------------  // acclient.c:862707
void __cdecl _E779_1()
{
  char *v0; // esi@1

  v0 = &Texture_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Texture_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748EB0) --------------------------------------------------------  // acclient.c:862720
void __cdecl _E782_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_FrameBuffer_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_FrameBuffer_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748EE0) --------------------------------------------------------  // acclient.c:862733
void __cdecl _E785_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Distortion_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Distortion_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748F10) --------------------------------------------------------  // acclient.c:862746
void __cdecl _E788_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_Reflection_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_Reflection_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748F40) --------------------------------------------------------  // acclient.c:862759
void __cdecl _E791_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_NormalizeCube_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_NormalizeCube_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748F70) --------------------------------------------------------  // acclient.c:862772
void __cdecl _E794_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LightProjectorCube_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LightProjectorCube_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748FA0) --------------------------------------------------------  // acclient.c:862785
void __cdecl _E797_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_EnvironmentCube_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_EnvironmentCube_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00748FD0) --------------------------------------------------------  // acclient.c:862798
void __cdecl _E800_1()
{
  char *v0; // esi@1

  v0 = &SpecialTexture_LandscapeShadows_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&SpecialTexture_LandscapeShadows_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749000) --------------------------------------------------------  // acclient.c:862811
void __cdecl _E803_1()
{
  char *v0; // esi@1

  v0 = &AddressMode_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AddressMode_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749030) --------------------------------------------------------  // acclient.c:862824
void __cdecl _E806_1()
{
  char *v0; // esi@1

  v0 = &TexFilter_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexFilter_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749060) --------------------------------------------------------  // acclient.c:862837
void __cdecl _E809_1()
{
  char *v0; // esi@1

  v0 = &ColorOp_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorOp_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749090) --------------------------------------------------------  // acclient.c:862850
void __cdecl _E812_1()
{
  char *v0; // esi@1

  v0 = &ColorArg1_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg1_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007490C0) --------------------------------------------------------  // acclient.c:862863
void __cdecl _E815_1()
{
  char *v0; // esi@1

  v0 = &ColorArg2_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ColorArg2_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007490F0) --------------------------------------------------------  // acclient.c:862876
void __cdecl _E818_1()
{
  char *v0; // esi@1

  v0 = &AlphaOp_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaOp_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749120) --------------------------------------------------------  // acclient.c:862889
void __cdecl _E821_1()
{
  char *v0; // esi@1

  v0 = &AlphaArg1_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg1_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749150) --------------------------------------------------------  // acclient.c:862902
void __cdecl _E824_1()
{
  char *v0; // esi@1

  v0 = &AlphaArg2_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&AlphaArg2_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749180) --------------------------------------------------------  // acclient.c:862915
void __cdecl _E827_1()
{
  char *v0; // esi@1

  v0 = &TexCoord_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TexCoord_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007491B0) --------------------------------------------------------  // acclient.c:862928
void __cdecl _E830_1()
{
  char *v0; // esi@1

  v0 = &UseProjection_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseProjection_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007491E0) --------------------------------------------------------  // acclient.c:862941
void __cdecl _E833_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG1_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG1_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749210) --------------------------------------------------------  // acclient.c:862954
void __cdecl _E836_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SELECTARG2_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SELECTARG2_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749240) --------------------------------------------------------  // acclient.c:862967
void __cdecl _E839_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749270) --------------------------------------------------------  // acclient.c:862980
void __cdecl _E842_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE2X_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE2X_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007492A0) --------------------------------------------------------  // acclient.c:862993
void __cdecl _E845_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATE4X_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATE4X_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007492D0) --------------------------------------------------------  // acclient.c:863006
void __cdecl _E848_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADD_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADD_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749300) --------------------------------------------------------  // acclient.c:863019
void __cdecl _E851_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749330) --------------------------------------------------------  // acclient.c:863032
void __cdecl _E854_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSIGNED2X_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSIGNED2X_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749360) --------------------------------------------------------  // acclient.c:863045
void __cdecl _E857_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_SUBTRACT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_SUBTRACT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749390) --------------------------------------------------------  // acclient.c:863058
void __cdecl _E860_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_ADDSMOOTH_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_ADDSMOOTH_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007493C0) --------------------------------------------------------  // acclient.c:863071
void __cdecl _E863_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDDIFFUSEALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDDIFFUSEALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007493F0) --------------------------------------------------------  // acclient.c:863084
void __cdecl _E866_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749420) --------------------------------------------------------  // acclient.c:863097
void __cdecl _E869_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDFACTORALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDFACTORALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749450) --------------------------------------------------------  // acclient.c:863110
void __cdecl _E872_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDTEXTUREALPHAPM_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDTEXTUREALPHAPM_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749480) --------------------------------------------------------  // acclient.c:863123
void __cdecl _E875_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BLENDCURRENTALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BLENDCURRENTALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007494B0) --------------------------------------------------------  // acclient.c:863136
void __cdecl _E878_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_PREMODULATE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_PREMODULATE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007494E0) --------------------------------------------------------  // acclient.c:863149
void __cdecl _E881_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEALPHA_ADDCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEALPHA_ADDCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749510) --------------------------------------------------------  // acclient.c:863162
void __cdecl _E884_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATECOLOR_ADDALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATECOLOR_ADDALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749540) --------------------------------------------------------  // acclient.c:863175
void __cdecl _E887_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVALPHA_ADDCOLOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVALPHA_ADDCOLOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749570) --------------------------------------------------------  // acclient.c:863188
void __cdecl _E890_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MODULATEINVCOLOR_ADDALPHA_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MODULATEINVCOLOR_ADDALPHA_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007495A0) --------------------------------------------------------  // acclient.c:863201
void __cdecl _E893_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAP_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAP_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007495D0) --------------------------------------------------------  // acclient.c:863214
void __cdecl _E896_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_BUMPENVMAPLUMINANCE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_BUMPENVMAPLUMINANCE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749600) --------------------------------------------------------  // acclient.c:863227
void __cdecl _E899_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_DOTPRODUCT3_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_DOTPRODUCT3_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749630) --------------------------------------------------------  // acclient.c:863240
void __cdecl _E902_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_MULTIPLYADD_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_MULTIPLYADD_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749660) --------------------------------------------------------  // acclient.c:863253
void __cdecl _E905_1()
{
  char *v0; // esi@1

  v0 = &param_TEXOP_LERP_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXOP_LERP_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749690) --------------------------------------------------------  // acclient.c:863266
void __cdecl _E908_1()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_DIFFUSE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_DIFFUSE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007496C0) --------------------------------------------------------  // acclient.c:863279
void __cdecl _E911_1()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_SPECULAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_SPECULAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007496F0) --------------------------------------------------------  // acclient.c:863292
void __cdecl _E914_1()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_CURRENT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_CURRENT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749720) --------------------------------------------------------  // acclient.c:863305
void __cdecl _E917_1()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TEXTURE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TEXTURE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749750) --------------------------------------------------------  // acclient.c:863318
void __cdecl _E920_1()
{
  char *v0; // esi@1

  v0 = &param_TEXARG_TFACTOR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXARG_TFACTOR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749780) --------------------------------------------------------  // acclient.c:863331
void __cdecl _E923_1()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_WRAP_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_WRAP_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007497B0) --------------------------------------------------------  // acclient.c:863344
void __cdecl _E926_1()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_MIRROR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_MIRROR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007497E0) --------------------------------------------------------  // acclient.c:863357
void __cdecl _E929_1()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_CLAMP_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_CLAMP_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749810) --------------------------------------------------------  // acclient.c:863370
void __cdecl _E932_1()
{
  char *v0; // esi@1

  v0 = &param_TEXADDRESS_BORDER_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXADDRESS_BORDER_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749840) --------------------------------------------------------  // acclient.c:863383
void __cdecl _E935_1()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_NONE_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_NONE_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749870) --------------------------------------------------------  // acclient.c:863396
void __cdecl _E938_1()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_POINT_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_POINT_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007498A0) --------------------------------------------------------  // acclient.c:863409
void __cdecl _E941_1()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_LINEAR_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_LINEAR_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007498D0) --------------------------------------------------------  // acclient.c:863422
void __cdecl _E944_1()
{
  char *v0; // esi@1

  v0 = &param_TEXFILTER_ANISOTROPIC_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXFILTER_ANISOTROPIC_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749900) --------------------------------------------------------  // acclient.c:863435
void __cdecl _E947_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ReflectionVector_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ReflectionVector_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749930) --------------------------------------------------------  // acclient.c:863448
void __cdecl _E950_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewNormal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewNormal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749960) --------------------------------------------------------  // acclient.c:863461
void __cdecl _E953_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_ViewOrigin_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_ViewOrigin_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749990) --------------------------------------------------------  // acclient.c:863474
void __cdecl _E956_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_SphereMap_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_SphereMap_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007499C0) --------------------------------------------------------  // acclient.c:863487
void __cdecl _E959_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapReflection_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapReflection_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007499F0) --------------------------------------------------------  // acclient.c:863500
void __cdecl _E962_1()
{
  char *v0; // esi@1

  v0 = &param_TEXCOORD_CubeMapFakeLight_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&param_TEXCOORD_CubeMapFakeLight_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749A20) --------------------------------------------------------  // acclient.c:863513
void __cdecl _E965_1()
{
  char *v0; // esi@1

  v0 = &NodeName_55.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_55.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749A50) --------------------------------------------------------  // acclient.c:863526
void __cdecl _E968_1()
{
  char *v0; // esi@1

  v0 = &ModType_Origin_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Origin_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749A80) --------------------------------------------------------  // acclient.c:863539
void __cdecl _E971_1()
{
  char *v0; // esi@1

  v0 = &ModType_Normal_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Normal_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749AB0) --------------------------------------------------------  // acclient.c:863552
void __cdecl _E974_1()
{
  char *v0; // esi@1

  v0 = &ModType_Diffuse_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_Diffuse_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749AE0) --------------------------------------------------------  // acclient.c:863565
void __cdecl _E977_1()
{
  char *v0; // esi@1

  v0 = &ModType_UVTranslate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTranslate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749B10) --------------------------------------------------------  // acclient.c:863578
void __cdecl _E980_1()
{
  char *v0; // esi@1

  v0 = &ModType_UVRotate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVRotate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749B40) --------------------------------------------------------  // acclient.c:863591
void __cdecl _E983_1()
{
  char *v0; // esi@1

  v0 = &ModType_UVScale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVScale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749B70) --------------------------------------------------------  // acclient.c:863604
void __cdecl _E986_1()
{
  char *v0; // esi@1

  v0 = &ModType_UVTransform_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ModType_UVTransform_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749BA0) --------------------------------------------------------  // acclient.c:863617
void __cdecl _E989_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_texCoordIndex_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_texCoordIndex_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749BD0) --------------------------------------------------------  // acclient.c:863630
void __cdecl _E992_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVTranslate_translate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVTranslate_translate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749C00) --------------------------------------------------------  // acclient.c:863643
void __cdecl _E995_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_texCoordIndex_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_texCoordIndex_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749C30) --------------------------------------------------------  // acclient.c:863656
void __cdecl _E998_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVRotate_rotate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVRotate_rotate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749C60) --------------------------------------------------------  // acclient.c:863669
void __cdecl _E1001_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_texCoordIndex_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_texCoordIndex_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749C90) --------------------------------------------------------  // acclient.c:863682
void __cdecl _E1004_1()
{
  char *v0; // esi@1

  v0 = &Mod_UVScale_scale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mod_UVScale_scale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749CC0) --------------------------------------------------------  // acclient.c:863695
void __cdecl _E1007_1()
{
  char *v0; // esi@1

  v0 = &NodeName_56.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_56.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749CF0) --------------------------------------------------------  // acclient.c:863708
void __cdecl _E1010_1()
{
  char *v0; // esi@1

  v0 = &PhysicsTimeStep_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsTimeStep_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749D20) --------------------------------------------------------  // acclient.c:863721
void __cdecl _E1013_1()
{
  char *v0; // esi@1

  v0 = &FastForwardTime_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FastForwardTime_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749D50) --------------------------------------------------------  // acclient.c:863734
void __cdecl _E1016_1()
{
  char *v0; // esi@1

  v0 = &StartFadeDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartFadeDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749D80) --------------------------------------------------------  // acclient.c:863747
void __cdecl _E1019_1()
{
  char *v0; // esi@1

  v0 = &StopFadeDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StopFadeDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749DB0) --------------------------------------------------------  // acclient.c:863760
void __cdecl _E1022_1()
{
  char *v0; // esi@1

  v0 = &PhysicsDuration_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysicsDuration_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749DE0) --------------------------------------------------------  // acclient.c:863773
void __cdecl _E1025_1()
{
  char *v0; // esi@1

  v0 = &ScaleType_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleType_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749E10) --------------------------------------------------------  // acclient.c:863786
void __cdecl _E1028_1()
{
  char *v0; // esi@1

  v0 = &WorldSpace_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldSpace_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749E40) --------------------------------------------------------  // acclient.c:863799
void __cdecl _E1031_1()
{
  char *v0; // esi@1

  v0 = &ForceDraw_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ForceDraw_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749E70) --------------------------------------------------------  // acclient.c:863812
void __cdecl _E1034_1()
{
  char *v0; // esi@1

  v0 = &NumEmitters_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumEmitters_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749EA0) --------------------------------------------------------  // acclient.c:863825
void __cdecl _E1037_1()
{
  char *v0; // esi@1

  v0 = &Material_23.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Material_23.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749ED0) --------------------------------------------------------  // acclient.c:863838
void __cdecl _E1040_1()
{
  char *v0; // esi@1

  v0 = &Version_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Version_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749F00) --------------------------------------------------------  // acclient.c:863851
void __cdecl _E1043_1()
{
  char *v0; // esi@1

  v0 = &MaxParticles_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxParticles_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749F30) --------------------------------------------------------  // acclient.c:863864
void __cdecl _E1046_1()
{
  char *v0; // esi@1

  v0 = &NodeName_57.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_57.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749F60) --------------------------------------------------------  // acclient.c:863877
void __cdecl _E1049_1()
{
  char *v0; // esi@1

  v0 = &Origin_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Origin_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749F90) --------------------------------------------------------  // acclient.c:863890
void __cdecl _E1052_1()
{
  char *v0; // esi@1

  v0 = &Shape_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749FC0) --------------------------------------------------------  // acclient.c:863903
void __cdecl _E1055_1()
{
  char *v0; // esi@1

  v0 = &Shape_Point_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Point_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00749FF0) --------------------------------------------------------  // acclient.c:863916
void __cdecl _E1058_1()
{
  char *v0; // esi@1

  v0 = &Shape_Line_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Line_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A020) --------------------------------------------------------  // acclient.c:863929
void __cdecl _E1061_1()
{
  char *v0; // esi@1

  v0 = &Shape_Quad_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Quad_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A050) --------------------------------------------------------  // acclient.c:863942
void __cdecl _E1064_1()
{
  char *v0; // esi@1

  v0 = &Shape_Disc_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Disc_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A080) --------------------------------------------------------  // acclient.c:863955
void __cdecl _E1067_1()
{
  char *v0; // esi@1

  v0 = &Shape_Sphere_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Shape_Sphere_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A0B0) --------------------------------------------------------  // acclient.c:863968
void __cdecl _E1070_1()
{
  char *v0; // esi@1

  v0 = &ParticleShape_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A0E0) --------------------------------------------------------  // acclient.c:863981
void __cdecl _E1073_1()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Triangle_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Triangle_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A110) --------------------------------------------------------  // acclient.c:863994
void __cdecl _E1076_1()
{
  char *v0; // esi@1

  v0 = &ParticleShape_Quad_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleShape_Quad_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A140) --------------------------------------------------------  // acclient.c:864007
void __cdecl _E1079_1()
{
  char *v0; // esi@1

  v0 = &Streak_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Streak_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A170) --------------------------------------------------------  // acclient.c:864020
void __cdecl _E1082_1()
{
  char *v0; // esi@1

  v0 = &Rotation_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Rotation_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A1A0) --------------------------------------------------------  // acclient.c:864033
void __cdecl _E1085_1()
{
  char *v0; // esi@1

  v0 = &WorldRotation_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&WorldRotation_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A1D0) --------------------------------------------------------  // acclient.c:864046
void __cdecl _E1088_1()
{
  char *v0; // esi@1

  v0 = &RotateVelocity_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&RotateVelocity_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A200) --------------------------------------------------------  // acclient.c:864059
void __cdecl _E1091_1()
{
  char *v0; // esi@1

  v0 = &ParticleScale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleScale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A230) --------------------------------------------------------  // acclient.c:864072
void __cdecl _E1094_1()
{
  char *v0; // esi@1

  v0 = &Scale_15.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_15.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A260) --------------------------------------------------------  // acclient.c:864085
void __cdecl _E1097_1()
{
  char *v0; // esi@1

  v0 = &ExplodingDir_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ExplodingDir_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A290) --------------------------------------------------------  // acclient.c:864098
void __cdecl _E1100_1()
{
  char *v0; // esi@1

  v0 = &BirthRate_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BirthRate_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A2C0) --------------------------------------------------------  // acclient.c:864111
void __cdecl _E1103_1()
{
  char *v0; // esi@1

  v0 = &Lifespan_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Lifespan_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A2F0) --------------------------------------------------------  // acclient.c:864124
void __cdecl _E1106_1()
{
  char *v0; // esi@1

  v0 = &Velocity_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Velocity_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A320) --------------------------------------------------------  // acclient.c:864137
void __cdecl _E1109_1()
{
  char *v0; // esi@1

  v0 = &Direction_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Direction_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A350) --------------------------------------------------------  // acclient.c:864150
void __cdecl _E1112_1()
{
  char *v0; // esi@1

  v0 = &MinSpread_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MinSpread_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A380) --------------------------------------------------------  // acclient.c:864163
void __cdecl _E1115_1()
{
  char *v0; // esi@1

  v0 = &MaxSpread_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxSpread_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A3B0) --------------------------------------------------------  // acclient.c:864176
void __cdecl _E1118_1()
{
  char *v0; // esi@1

  v0 = &EmissionLimit_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionLimit_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A3E0) --------------------------------------------------------  // acclient.c:864189
void __cdecl _E1121_1()
{
  char *v0; // esi@1

  v0 = &BlastCount_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&BlastCount_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A410) --------------------------------------------------------  // acclient.c:864202
void __cdecl _E1124_1()
{
  char *v0; // esi@1

  v0 = &StartTime_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&StartTime_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A440) --------------------------------------------------------  // acclient.c:864215
void __cdecl _E1127_1()
{
  char *v0; // esi@1

  v0 = &TimeLimit_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&TimeLimit_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A470) --------------------------------------------------------  // acclient.c:864228
void __cdecl _E1130_1()
{
  char *v0; // esi@1

  v0 = &EmissionDistance_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&EmissionDistance_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A4A0) --------------------------------------------------------  // acclient.c:864241
void __cdecl _E1133_1()
{
  char *v0; // esi@1

  v0 = &ParticleSnap_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ParticleSnap_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A4D0) --------------------------------------------------------  // acclient.c:864254
void __cdecl _E1136_1()
{
  char *v0; // esi@1

  v0 = &InclusiveShape_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&InclusiveShape_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A500) --------------------------------------------------------  // acclient.c:864267
void __cdecl _E1139_1()
{
  char *v0; // esi@1

  v0 = &NumKeyframes_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NumKeyframes_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A530) --------------------------------------------------------  // acclient.c:864280
void __cdecl _E1142_1()
{
  char *v0; // esi@1

  v0 = &IsActive_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&IsActive_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A560) --------------------------------------------------------  // acclient.c:864293
void __cdecl _E1145_1()
{
  char *v0; // esi@1

  v0 = &FadeIn_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeIn_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A590) --------------------------------------------------------  // acclient.c:864306
void __cdecl _E1148_1()
{
  char *v0; // esi@1

  v0 = &FadeOut_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeOut_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A5C0) --------------------------------------------------------  // acclient.c:864319
void __cdecl _E1151_1()
{
  char *v0; // esi@1

  v0 = &ConstrainX_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainX_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A5F0) --------------------------------------------------------  // acclient.c:864332
void __cdecl _E1154_1()
{
  char *v0; // esi@1

  v0 = &ConstrainY_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainY_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A620) --------------------------------------------------------  // acclient.c:864345
void __cdecl _E1157_1()
{
  char *v0; // esi@1

  v0 = &ConstrainZ_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ConstrainZ_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A650) --------------------------------------------------------  // acclient.c:864358
void __cdecl _E1160_1()
{
  char *v0; // esi@1

  v0 = &NodeName_58.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&NodeName_58.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A680) --------------------------------------------------------  // acclient.c:864371
void __cdecl _E1163_1()
{
  char *v0; // esi@1

  v0 = &Time_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Time_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A6B0) --------------------------------------------------------  // acclient.c:864384
void __cdecl _E1166_1()
{
  char *v0; // esi@1

  v0 = &Flags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A6E0) --------------------------------------------------------  // acclient.c:864397
void __cdecl _E1169_1()
{
  char *v0; // esi@1

  v0 = &Flags_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A710) --------------------------------------------------------  // acclient.c:864410
void __cdecl _E1172_1()
{
  char *v0; // esi@1

  v0 = &Flags_BlendScale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendScale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A740) --------------------------------------------------------  // acclient.c:864423
void __cdecl _E1175_1()
{
  char *v0; // esi@1

  v0 = &Flags_BlendColor_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendColor_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A770) --------------------------------------------------------  // acclient.c:864436
void __cdecl _E1178_1()
{
  char *v0; // esi@1

  v0 = &Flags_BlendMass_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_BlendMass_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A7A0) --------------------------------------------------------  // acclient.c:864449
void __cdecl _E1181_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetScale_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetScale_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A7D0) --------------------------------------------------------  // acclient.c:864462
void __cdecl _E1184_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetColor_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetColor_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A800) --------------------------------------------------------  // acclient.c:864475
void __cdecl _E1187_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetMass_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetMass_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A830) --------------------------------------------------------  // acclient.c:864488
void __cdecl _E1190_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetPFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A860) --------------------------------------------------------  // acclient.c:864501
void __cdecl _E1193_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetPCType_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPCType_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A890) --------------------------------------------------------  // acclient.c:864514
void __cdecl _E1196_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetPhysFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetPhysFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A8C0) --------------------------------------------------------  // acclient.c:864527
void __cdecl _E1199_1()
{
  char *v0; // esi@1

  v0 = &Flags_SetParams_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Flags_SetParams_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A8F0) --------------------------------------------------------  // acclient.c:864540
void __cdecl _E1202_1()
{
  char *v0; // esi@1

  v0 = &Scale_16.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Scale_16.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A920) --------------------------------------------------------  // acclient.c:864553
void __cdecl _E1205_1()
{
  char *v0; // esi@1

  v0 = &ScaleX_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleX_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A950) --------------------------------------------------------  // acclient.c:864566
void __cdecl _E1208_1()
{
  char *v0; // esi@1

  v0 = &ScaleY_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&ScaleY_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A980) --------------------------------------------------------  // acclient.c:864579
void __cdecl _E1211_1()
{
  char *v0; // esi@1

  v0 = &Color_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Color_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A9B0) --------------------------------------------------------  // acclient.c:864592
void __cdecl _E1214_1()
{
  char *v0; // esi@1

  v0 = &Mass_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Mass_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074A9E0) --------------------------------------------------------  // acclient.c:864605
void __cdecl _E1217_1()
{
  char *v0; // esi@1

  v0 = &PFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AA10) --------------------------------------------------------  // acclient.c:864618
void __cdecl _E1220_1()
{
  char *v0; // esi@1

  v0 = &PFlags_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PFlags_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AA40) --------------------------------------------------------  // acclient.c:864631
void __cdecl _E1223_1()
{
  char *v0; // esi@1

  v0 = &PCType_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AA70) --------------------------------------------------------  // acclient.c:864644
void __cdecl _E1226_1()
{
  char *v0; // esi@1

  v0 = &PCType_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AAA0) --------------------------------------------------------  // acclient.c:864657
void __cdecl _E1229_1()
{
  char *v0; // esi@1

  v0 = &PCType_Physics_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Physics_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AAD0) --------------------------------------------------------  // acclient.c:864670
void __cdecl _E1232_1()
{
  char *v0; // esi@1

  v0 = &PCType_Parametric_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_Parametric_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AB00) --------------------------------------------------------  // acclient.c:864683
void __cdecl _E1235_1()
{
  char *v0; // esi@1

  v0 = &PCType_AttractRepulse_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_AttractRepulse_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AB30) --------------------------------------------------------  // acclient.c:864696
void __cdecl _E1238_1()
{
  char *v0; // esi@1

  v0 = &PCType_PointFile_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFile_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AB60) --------------------------------------------------------  // acclient.c:864709
void __cdecl _E1241_1()
{
  char *v0; // esi@1

  v0 = &PCType_PointFileLerp_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PCType_PointFileLerp_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AB90) --------------------------------------------------------  // acclient.c:864722
void __cdecl _E1244_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ABC0) --------------------------------------------------------  // acclient.c:864735
void __cdecl _E1247_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_None_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_None_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ABF0) --------------------------------------------------------  // acclient.c:864748
void __cdecl _E1250_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Gravity_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Gravity_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AC20) --------------------------------------------------------  // acclient.c:864761
void __cdecl _E1253_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Wind_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Wind_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AC50) --------------------------------------------------------  // acclient.c:864774
void __cdecl _E1256_1()
{
  char *v0; // esi@1

  v0 = &PhysFlags_Momentum_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PhysFlags_Momentum_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AC80) --------------------------------------------------------  // acclient.c:864787
void __cdecl _E1259_1()
{
  char *v0; // esi@1

  v0 = &PointfileFlags_RandomPoint_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointfileFlags_RandomPoint_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ACB0) --------------------------------------------------------  // acclient.c:864800
void __cdecl _E1262_1()
{
  char *v0; // esi@1

  v0 = &Position_5.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Position_5.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ACE0) --------------------------------------------------------  // acclient.c:864813
void __cdecl _E1265_1()
{
  char *v0; // esi@1

  v0 = &PointList_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointList_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AD10) --------------------------------------------------------  // acclient.c:864826
void __cdecl _E1268_1()
{
  char *v0; // esi@1

  v0 = &Point_10.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_10.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AD40) --------------------------------------------------------  // acclient.c:864839
void __cdecl _E1271_1()
{
  char *v0; // esi@1

  v0 = &DetailLevels_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevels_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AD70) --------------------------------------------------------  // acclient.c:864852
void __cdecl _E1274_1()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Low_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Low_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ADA0) --------------------------------------------------------  // acclient.c:864865
void __cdecl _E1277_1()
{
  char *v0; // esi@1

  v0 = &DetailLevel_Medium_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_Medium_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074ADD0) --------------------------------------------------------  // acclient.c:864878
void __cdecl _E1280_2()
{
  char *v0; // esi@1

  v0 = &DetailLevel_High_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&DetailLevel_High_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AE00) --------------------------------------------------------  // acclient.c:864891
void __cdecl _E1283_1()
{
  char *v0; // esi@1

  v0 = &FadeSpeed_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&FadeSpeed_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AE30) --------------------------------------------------------  // acclient.c:864904
void __cdecl _E1286_1()
{
  char *v0; // esi@1

  v0 = &MaxOpacity_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&MaxOpacity_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AE60) --------------------------------------------------------  // acclient.c:864917
void __cdecl _E1289_0()
{
  char *v0; // esi@1

  v0 = &Point_11.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Point_11.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AE90) --------------------------------------------------------  // acclient.c:864930
void __cdecl _E1292_1()
{
  char *v0; // esi@1

  v0 = &PointAxisPos_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointAxisPos_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AEC0) --------------------------------------------------------  // acclient.c:864943
void __cdecl _E1295_0()
{
  char *v0; // esi@1

  v0 = &PointTexture_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointTexture_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AEF0) --------------------------------------------------------  // acclient.c:864956
void __cdecl _E1298_0()
{
  char *v0; // esi@1

  v0 = &PointSize_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&PointSize_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AF20) --------------------------------------------------------  // acclient.c:864969
void __cdecl _E1301_0()
{
  char *v0; // esi@1

  v0 = &UseOcclusion_4.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&UseOcclusion_4.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (0074AF50) --------------------------------------------------------  // acclient.c:864982
void __cdecl _E1313_0()
{
  char *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = (char *)&unk_83B164;
  v1 = 4;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    v0 -= 4;
    v3 = v2 - 20;
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
    --v1;
  }
  while ( v1 );
}

