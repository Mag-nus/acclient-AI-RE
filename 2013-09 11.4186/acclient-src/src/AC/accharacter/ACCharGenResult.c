/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ACCharGenResult
   Object     : AC\accharacter\ACCharGenResult.obj
   Functions  : 25
   Addresses  : 0049B620 - 0070F630 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0049B620) --------------------------------------------------------  // acclient.c:213043
void __thiscall DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>(DBObjGrabber<ACCharGenData> *this)
{
  DBObjGrabber<ACCharGenData> *v1; // esi@1
  ACCharGenData *v2; // ecx@1

  v1 = this;
  v2 = this->m_object;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Release)();
    v1->m_object = 0;
  }
}

//----- (0051D470) --------------------------------------------------------  // acclient.c:331308
unsigned int __thiscall PhysicsDesc::get_parent_location_id(ACCharGenResult *this)
{
  return this->startArea;
}

//----- (005C7030) --------------------------------------------------------  // acclient.c:498179
void __thiscall ACCharGenResult::ACCharGenResult(ACCharGenResult *this)
{
  ACCharGenResult *v1; // esi@1
  volatile LONG *v2; // ST00_4@1
  unsigned int v3; // edx@1

  v1 = this;
  this->vfptr = (PackObjVtbl *)&ACCharGenResult::vftable;
  this->heritageGroup = 0;
  this->gender = 0;
  this->eyesStrip = 0;
  this->noseStrip = 0;
  this->mouthStrip = 0;
  this->hairColor = 0;
  this->eyeColor = 0;
  this->hairStyle = 0;
  this->headgearStyle = 0;
  this->shirtStyle = 0;
  this->trousersStyle = 0;
  this->footwearStyle = 0;
  this->headgearColor = 0;
  this->shirtColor = 0;
  this->trousersColor = 0;
  this->footwearColor = 0;
  *(_QWORD *)&this->skinShade = 0i64;
  *(_QWORD *)&this->hairShade = 0i64;
  *(_QWORD *)&this->headgearShade = 0i64;
  *(_QWORD *)&this->shirtShade = 0i64;
  *(_QWORD *)&this->trousersShade = 0i64;
  *(_QWORD *)&this->footwearShade = 0i64;
  this->templateNum = 0;
  this->strength = 0;
  this->endurance = 0;
  this->coordination = 0;
  this->quickness = 0;
  this->focus = 0;
  this->self = 0;
  this->numSkills = 0;
  this->skillAdvancementClasses = 0;
  v2 = (volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4);
  this->name.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement(v2);
  v1->slot = -1;
  v3 = stru_8EF8DC.id;
  v1->startArea = 0;
  v1->isAdmin = 0;
  v1->isEnvoy = 0;
  v1->classID.id = v3;
}
// 7E7868: using guessed type int (__thiscall *ACCharGenResult::vftable)(void *, char);
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (005C7110) --------------------------------------------------------  // acclient.c:498232
AC1Legacy::PStringBase<char> *__thiscall ACCharGenResult::GetName(ACCharGenResult *this)
{
  return &this->name;
}

//----- (005C7120) --------------------------------------------------------  // acclient.c:498238
int __thiscall ACCharGenResult::GetSlot(ACCharGenResult *this)
{
  return this->slot;
}

//----- (005C7130) --------------------------------------------------------  // acclient.c:498244
int __thiscall ACCharGenResult::IsEnvoy(ACCharGenResult *this)
{
  return this->isEnvoy;
}

//----- (005C7140) --------------------------------------------------------  // acclient.c:498250
int __thiscall UIElement::GetParent(ACCharGenResult *this)
{
  return this->isAdmin;
}

//----- (005C7150) --------------------------------------------------------  // acclient.c:498256
IDClass<_tagDataID,32,0> *__thiscall ACCharGenResult::GetClassID(ACCharGenResult *this, IDClass<_tagDataID,32,0> *result)
{
  IDClass<_tagDataID,32,0> *v2; // eax@1

  v2 = result;
  result->id = this->classID.id;
  return v2;
}

//----- (005C7160) --------------------------------------------------------  // acclient.c:498266
void __thiscall ACCharGenResult::SetName(ACCharGenResult *this, AC1Legacy::PStringBase<char> *newname)
{
  ACCharGenResult *v2; // edi@1
  AC1Legacy::PSRefBuffer<char> *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // eax@5

  v2 = this;
  v3 = this->name.m_buffer;
  if ( v3 != newname->m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) )
    {
      if ( v3 )
        v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
    }
    v4 = newname->m_buffer;
    v2->name.m_buffer = newname->m_buffer;
    InterlockedIncrement((volatile LONG *)&v4->m_cRef);
  }
}

//----- (005C71B0) --------------------------------------------------------  // acclient.c:498288
void __thiscall ACCharGenResult::~ACCharGenResult(ACCharGenResult *this)
{
  ACCharGenResult *v1; // esi@1
  SKILL_ADVANCEMENT_CLASS *v2; // eax@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@3

  v1 = this;
  v2 = this->skillAdvancementClasses;
  this->vfptr = (PackObjVtbl *)&ACCharGenResult::vftable;
  if ( v2 )
    operator delete[](v2);
  v3 = v1->name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v1->vfptr = (PackObjVtbl *)&PackObj::vftable;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7868: using guessed type int (__thiscall *ACCharGenResult::vftable)(void *, char);

//----- (005C7200) --------------------------------------------------------  // acclient.c:498308
void __thiscall ACCharGenResult::CG_Pack(ACCharGenResult *this, void **buffer_vpr, char *end)
{
  char *v3; // eax@1
  ACCharGenResult *v4; // edi@1
  char *v5; // ebx@1
  char *v6; // eax@1
  unsigned int v7; // ebx@1
  char *v8; // edx@1
  unsigned int v9; // ebx@1
  char *v10; // edx@1
  int v11; // ecx@1
  char *v12; // edx@1
  int v13; // ebx@1
  char *v14; // edx@1
  int v15; // ecx@1
  char *v16; // edx@1
  int v17; // ebx@1
  char *v18; // edx@1
  int v19; // ecx@1
  char *v20; // edx@1
  int v21; // ebx@1
  char *v22; // edx@1
  int v23; // ebx@1
  char *v24; // eax@1
  char *v25; // edx@1
  int v26; // ecx@1
  char *v27; // eax@1
  int v28; // ebx@1
  char *v29; // edx@1
  int v30; // ecx@1
  char *v31; // eax@1
  int v32; // ebx@1
  char *v33; // edx@1
  int v34; // ecx@1
  char *v35; // eax@1
  char *v36; // edx@1
  int v37; // ebx@1
  char *v38; // ecx@1
  char *v39; // eax@1
  char *v40; // edx@1
  char *v41; // ecx@1
  char *v42; // eax@1
  char *v43; // edx@1
  int v44; // ecx@1
  char *v45; // edx@1
  int v46; // ebx@1
  char *v47; // edx@1
  int v48; // ecx@1
  char *v49; // edx@1
  int v50; // ebx@1
  char *v51; // edx@1
  int v52; // ecx@1
  char *v53; // edx@1
  int v54; // ebx@1
  char *v55; // edx@1
  int v56; // ecx@1
  char *v57; // edx@1
  int v58; // ebx@1
  char *v59; // ecx@1
  char *v60; // eax@1
  char *v61; // ecx@1
  unsigned int v62; // eax@1
  char *v63; // eax@3
  char *v64; // edx@3
  char *v65; // ecx@3

  *(_DWORD *)*buffer_vpr = 1;
  v3 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v3;
  v4 = this;
  *(_DWORD *)v3 = this->heritageGroup;
  v5 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v5;
  v6 = v5;
  v7 = this->heritageGroup;
  *(_DWORD *)v6 = this->gender;
  v8 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v8;
  v9 = this->gender + v7;
  *(_DWORD *)v8 = this->eyesStrip;
  v10 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v10;
  v11 = this->eyesStrip;
  *(_DWORD *)v10 = v4->noseStrip;
  v12 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v12;
  v13 = v4->noseStrip + v11 + v9;
  *(_DWORD *)v12 = v4->mouthStrip;
  v14 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v14;
  v15 = v4->mouthStrip;
  *(_DWORD *)v14 = v4->hairColor;
  v16 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v16;
  v17 = v4->hairColor + v15 + v13;
  *(_DWORD *)v16 = v4->eyeColor;
  v18 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v18;
  v19 = v4->eyeColor;
  *(_DWORD *)v18 = v4->hairStyle;
  v20 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v20;
  v21 = v4->hairStyle + v19 + v17;
  *(_DWORD *)v20 = v4->headgearStyle;
  v22 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v22;
  v23 = v4->headgearStyle + v21;
  *(_DWORD *)v22 = v4->headgearColor;
  v24 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v24;
  *(_DWORD *)v24 = v4->shirtStyle;
  v25 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v25;
  v26 = v4->shirtStyle;
  *(_DWORD *)v25 = v4->shirtColor;
  v27 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v27;
  v28 = v26 + v23;
  *(_DWORD *)v27 = v4->trousersStyle;
  v29 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v29;
  v30 = v4->trousersStyle;
  *(_DWORD *)v29 = v4->trousersColor;
  v31 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v31;
  v32 = v30 + v28;
  *(_DWORD *)v31 = v4->footwearStyle;
  v33 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v33;
  v34 = v4->footwearStyle;
  *(_DWORD *)v33 = v4->footwearColor;
  v35 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v35;
  *(double *)v35 = v4->skinShade;
  v36 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v36;
  v37 = v34 + v32;
  *(double *)v36 = v4->hairShade;
  v38 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v38;
  *(double *)v38 = v4->headgearShade;
  v39 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v39;
  *(double *)v39 = v4->shirtShade;
  v40 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v40;
  *(double *)v40 = v4->trousersShade;
  v41 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v41;
  *(double *)v41 = v4->footwearShade;
  v42 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v42;
  *(_DWORD *)v42 = v4->templateNum;
  v43 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v43;
  v44 = v4->templateNum;
  *(_DWORD *)v43 = v4->strength;
  v45 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v45;
  v46 = v4->strength + v44 + v37;
  *(_DWORD *)v45 = v4->endurance;
  v47 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v47;
  v48 = v4->endurance;
  *(_DWORD *)v47 = v4->coordination;
  v49 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v49;
  v50 = v4->coordination + v48 + v46;
  *(_DWORD *)v49 = v4->quickness;
  v51 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v51;
  v52 = v4->quickness;
  *(_DWORD *)v51 = v4->focus;
  v53 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v53;
  v54 = v4->focus + v52 + v50;
  *(_DWORD *)v53 = v4->self;
  v55 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v55;
  v56 = v4->self;
  *(_DWORD *)v55 = v4->slot;
  v57 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v57;
  v58 = v56 + v54;
  *(_DWORD *)v57 = v4->classID.id;
  v59 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v59;
  *(_DWORD *)v59 = v4->numSkills;
  v60 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v60;
  v61 = v60;
  v62 = 0;
  if ( v4->numSkills )
  {
    do
    {
      *(_DWORD *)v61 = v4->skillAdvancementClasses[v62];
      v61 = (char *)*buffer_vpr + 4;
      *buffer_vpr = v61;
      ++v62;
    }
    while ( v62 < v4->numSkills );
  }
  AC1Legacy::PStringBase<char>::Pack(&v4->name, buffer_vpr, end - v61);
  *(_DWORD *)*buffer_vpr = v4->startArea;
  v63 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v63;
  *(_DWORD *)v63 = v4->isAdmin;
  v64 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v64;
  *(_DWORD *)v64 = v4->isEnvoy;
  v65 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v65;
  *(_DWORD *)v65 = v58;
  *buffer_vpr = (char *)*buffer_vpr + 4;
}

//----- (005C74E0) --------------------------------------------------------  // acclient.c:498526
int __thiscall ACCharGenResult::GetPackSize(ACCharGenResult *this)
{
  int v1; // esi@1
  void *addr; // [sp+0h] [bp-4h]@1

  addr = this;
  v1 = this->numSkills;
  addr = 0;
  return AC1Legacy::PStringBase<char>::Pack(&this->name, &addr, 0) + 4 * v1 + 156 + 16;
}

//----- (005C7510) --------------------------------------------------------  // acclient.c:498538
ACCharGenResult *__thiscall ACCharGenResult::vector_deleting_destructor(ACCharGenResult *this, unsigned int a2)
{
  ACCharGenResult *v2; // esi@1
  SKILL_ADVANCEMENT_CLASS *v3; // eax@1
  AC1Legacy::PSRefBuffer<char> *v4; // edi@3

  v2 = this;
  v3 = this->skillAdvancementClasses;
  this->vfptr = (PackObjVtbl *)&ACCharGenResult::vftable;
  if ( v3 )
    operator delete[](v3);
  v4 = v2->name.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7E7868: using guessed type int (__thiscall *ACCharGenResult::vftable)(void *, char);

//----- (005C7570) --------------------------------------------------------  // acclient.c:498561
unsigned int __thiscall ACCharGenResult::Pack(ACCharGenResult *this, void **addr, unsigned int size)
{
  ACCharGenResult *v3; // esi@1
  int v4; // edi@1
  unsigned int v5; // edi@1
  void *v7; // [sp+0h] [bp-4h]@1

  v7 = this;
  v3 = this;
  v4 = this->numSkills;
  v7 = 0;
  v5 = 4 * v4 + 156 + AC1Legacy::PStringBase<char>::Pack(&this->name, &v7, 0) + 16;
  if ( size >= v5 )
    ACCharGenResult::CG_Pack(v3, addr, (char *)*addr + size);
  return v5;
}

//----- (005C75D0) --------------------------------------------------------  // acclient.c:498579
int __thiscall ACCharGenResult::CG_UnPack(ACCharGenResult *this, void **buffer_vpr, char *end)
{
  void *v3; // ebx@1
  ACCharGenResult *v4; // edi@1
  int v5; // ecx@1
  signed int v6; // ecx@2
  char *v7; // eax@2
  char *v8; // ebx@3
  unsigned int v9; // ecx@3
  unsigned int v10; // ebx@3
  char *v11; // edx@3
  unsigned int v12; // ecx@3
  char *v13; // edx@3
  int v14; // ebx@3
  int v15; // ecx@3
  char *v16; // edx@3
  int v17; // ebx@3
  char *v18; // edx@3
  int v19; // ecx@3
  char *v20; // edx@3
  int v21; // ebx@3
  int v22; // ecx@3
  char *v23; // edx@3
  int v24; // ebx@3
  char *v25; // edx@3
  int v26; // ecx@3
  char *v27; // edx@3
  int v28; // ebx@3
  int v29; // ecx@3
  char *v30; // eax@3
  int v31; // ebx@3
  char *v32; // edx@3
  int v33; // ecx@3
  char *v34; // eax@3
  char *v35; // edx@3
  int v36; // ebx@3
  char *v37; // eax@3
  char *v38; // edx@3
  int v39; // ecx@3
  char *v40; // eax@3
  int v41; // ebx@3
  char *v42; // edx@3
  char *v43; // ecx@3
  char *v44; // eax@3
  char *v45; // edx@3
  char *v46; // ecx@3
  char *v47; // eax@3
  char *v48; // edx@3
  int v49; // ebx@3
  char *v50; // edx@3
  int v51; // ecx@3
  char *v52; // edx@3
  int v53; // ebx@3
  int v54; // ecx@3
  char *v55; // edx@3
  int v56; // ebx@3
  char *v57; // edx@3
  int v58; // ecx@3
  char *v59; // edx@3
  int v60; // ebx@3
  int v61; // ecx@3
  char *v62; // edx@3
  int v63; // ebx@3
  char *v64; // eax@3
  unsigned int v65; // ecx@3
  signed int v66; // eax@5
  int v67; // ecx@5
  void *v68; // eax@6
  int v69; // ecx@6
  unsigned int v70; // eax@6
  unsigned int v71; // ecx@8
  signed int v72; // eax@11
  char *v73; // ecx@12
  int v74; // eax@12
  char *v75; // ecx@13
  int v76; // eax@13
  unsigned int size; // [sp+Ch] [bp-Ch]@1
  int result_f; // [sp+10h] [bp-8h]@1
  int packsum_l; // [sp+14h] [bp-4h]@1

  v3 = *buffer_vpr;
  v4 = this;
  v5 = this->numSkills;
  packsum_l = 0;
  result_f = 0;
  size = 4 * v5 + 156;
  if ( AC1Legacy::PStringBase<char>::Pack(&v4->name, (void **)&result_f, 0) + size + 16 > (_BYTE *)v3 - end + 1 )
    return 0;
  v6 = *(_DWORD *)*buffer_vpr;
  v7 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v7;
  result_f = v6 >= 1 && v6 <= 1;
  if ( v6 != 1 )
    goto LABEL_21;
  v4->heritageGroup = *(_DWORD *)v7;
  v8 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v8;
  v9 = *(_DWORD *)v8;
  v10 = v4->heritageGroup;
  v4->gender = v9;
  v11 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v11;
  v12 = v4->gender;
  v4->eyesStrip = *(_DWORD *)v11;
  v13 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v13;
  v4->noseStrip = *(_DWORD *)v13;
  v14 = v12 + v10;
  v15 = v4->eyesStrip;
  v16 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v16;
  v17 = v4->noseStrip + v15 + v14;
  v4->mouthStrip = *(_DWORD *)v16;
  v18 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v18;
  v19 = v4->mouthStrip;
  v4->hairColor = *(_DWORD *)v18;
  v20 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v20;
  v4->eyeColor = *(_DWORD *)v20;
  v21 = v19 + v17;
  v22 = v4->hairColor;
  v23 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v23;
  v24 = v4->eyeColor + v22 + v21;
  v4->hairStyle = *(_DWORD *)v23;
  v25 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v25;
  v26 = v4->hairStyle;
  v4->headgearStyle = *(_DWORD *)v25;
  v27 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v27;
  v4->headgearColor = *(_DWORD *)v27;
  v28 = v26 + v24;
  v29 = v4->headgearStyle;
  v30 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v30;
  v31 = v29 + v28;
  v4->shirtStyle = *(_DWORD *)v30;
  v32 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v32;
  v33 = v4->shirtStyle;
  v4->shirtColor = *(_DWORD *)v32;
  v34 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v34;
  v4->trousersStyle = *(_DWORD *)v34;
  v35 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v35;
  v36 = v4->trousersStyle + v33 + v31;
  v4->trousersColor = *(_DWORD *)v35;
  v37 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v37;
  v4->footwearStyle = *(_DWORD *)v37;
  v38 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v38;
  v39 = v4->footwearStyle;
  v4->footwearColor = *(_DWORD *)v38;
  v40 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v40;
  v41 = v39 + v36;
  LODWORD(v4->skinShade) = *(_DWORD *)v40;
  HIDWORD(v4->skinShade) = *((_DWORD *)v40 + 1);
  v42 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v42;
  LODWORD(v4->hairShade) = *(_DWORD *)v42;
  HIDWORD(v4->hairShade) = *((_DWORD *)v42 + 1);
  v43 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v43;
  LODWORD(v4->headgearShade) = *(_DWORD *)v43;
  HIDWORD(v4->headgearShade) = *((_DWORD *)v43 + 1);
  v44 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v44;
  LODWORD(v4->shirtShade) = *(_DWORD *)v44;
  HIDWORD(v4->shirtShade) = *((_DWORD *)v44 + 1);
  v45 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v45;
  LODWORD(v4->trousersShade) = *(_DWORD *)v45;
  HIDWORD(v4->trousersShade) = *((_DWORD *)v45 + 1);
  v46 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v46;
  LODWORD(v4->footwearShade) = *(_DWORD *)v46;
  HIDWORD(v4->footwearShade) = *((_DWORD *)v46 + 1);
  v47 = (char *)*buffer_vpr + 8;
  *buffer_vpr = v47;
  v4->templateNum = *(_DWORD *)v47;
  v48 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v48;
  v49 = v4->templateNum + v41;
  v4->strength = *(_DWORD *)v48;
  v50 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v50;
  v51 = v4->strength;
  v4->endurance = *(_DWORD *)v50;
  v52 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v52;
  v4->coordination = *(_DWORD *)v52;
  v53 = v51 + v49;
  v54 = v4->endurance;
  v55 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v55;
  v56 = v4->coordination + v54 + v53;
  v4->quickness = *(_DWORD *)v55;
  v57 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v57;
  v58 = v4->quickness;
  v4->focus = *(_DWORD *)v57;
  v59 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v59;
  v4->self = *(_DWORD *)v59;
  v60 = v58 + v56;
  v61 = v4->focus;
  v62 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v62;
  v63 = v4->self + v61 + v60;
  v4->slot = *(_DWORD *)v62;
  v64 = (char *)*buffer_vpr + 4;
  *buffer_vpr = v64;
  v65 = *(_DWORD *)v64;
  *buffer_vpr = v64 + 4;
  v4->classID.id = v65;
  v4->numSkills = *(_DWORD *)*buffer_vpr;
  *buffer_vpr = (char *)*buffer_vpr + 4;
  if ( v4->skillAdvancementClasses )
  {
    operator delete[](v4->skillAdvancementClasses);
    v4->skillAdvancementClasses = 0;
  }
  v66 = end - (_BYTE *)*buffer_vpr;
  v67 = v4->numSkills;
  size = end - (_BYTE *)*buffer_vpr;
  if ( v67 > 0 )
  {
    v68 = operator new[](4 * v67);
    v69 = v4->numSkills;
    v4->skillAdvancementClasses = (SKILL_ADVANCEMENT_CLASS *)v68;
    v70 = 0;
    if ( v69 )
    {
      while ( size >= 4 )
      {
        v4->skillAdvancementClasses[v70] = *(_DWORD *)*buffer_vpr;
        v71 = size - 4;
        *buffer_vpr = (char *)*buffer_vpr + 4;
        size = v71;
        ++v70;
        if ( v70 >= v4->numSkills )
          goto LABEL_9;
      }
      return 0;
    }
LABEL_9:
    v66 = size;
  }
  if ( !AC1Legacy::PStringBase<char>::UnPack(&v4->name, buffer_vpr, v66) )
    return 0;
  v72 = end - (_BYTE *)*buffer_vpr;
  if ( (unsigned int)v72 < 4 )
    return 0;
  v4->startArea = *(_DWORD *)*buffer_vpr;
  v73 = (char *)*buffer_vpr + 4;
  v74 = v72 - 4;
  *buffer_vpr = v73;
  if ( (unsigned int)v74 < 4 )
    return 0;
  v4->isAdmin = *(_DWORD *)v73;
  v75 = (char *)*buffer_vpr + 4;
  v76 = v74 - 4;
  *buffer_vpr = v75;
  if ( (unsigned int)v76 < 4 )
    return 0;
  v4->isEnvoy = *(_DWORD *)v75;
  *buffer_vpr = (char *)*buffer_vpr + 4;
  size = v76 - 4;
  if ( !PackObj::UNPACK_TYPE(&packsum_l, buffer_vpr, &size) )
    return 0;
  if ( packsum_l != v63 )
LABEL_21:
    result_f = 0;
  return (unsigned __int8)result_f & (end >= *buffer_vpr);
}

//----- (005C79D0) --------------------------------------------------------  // acclient.c:498861
BOOL __thiscall ACCharGenResult::UnPack(ACCharGenResult *this, void **addr, unsigned int size)
{
  return ACCharGenResult::CG_UnPack(this, addr, (char *)*addr + size) != 0;
}

//----- (005C79F0) --------------------------------------------------------  // acclient.c:498867
int __cdecl ACCharGenResult::VerifyCharacterGenerationResult(ACCharGenResult *this, ACCharGenResult *cgr)
{
  int v2; // eax@1
  int v3; // edi@1
  unsigned int v4; // eax@2
  unsigned int v5; // eax@6
  int v6; // eax@8
  int v7; // eax@10
  int v8; // eax@12
  int v9; // eax@14
  int v10; // eax@16
  int v11; // eax@18
  int v12; // eax@20
  int v13; // eax@23
  int v14; // eax@25
  int v15; // eax@27
  int v16; // eax@29
  int v17; // eax@31
  int v18; // eax@33
  int v19; // eax@35
  int v20; // ebp@49
  int v21; // ebx@51
  int v22; // edi@53
  int v23; // edx@55
  int v24; // ecx@57
  int v25; // eax@59
  int v26; // ebp@62
  int v27; // edx@63
  int v28; // ebx@63
  unsigned int v29; // ecx@63
  SKILL_ADVANCEMENT_CLASS *v30; // edi@64
  unsigned int v31; // ebx@71
  int v32; // edi@71
  int v33; // eax@74
  AC1Legacy::PSRefBuffer<char> *v34; // eax@83
  int v35; // eax@85
  char *v36; // edx@85
  char v37; // cl@86
  int v38; // eax@88
  bool v39; // bl@94
  unsigned int v40; // edi@100
  unsigned int v41; // edi@101
  unsigned int v42; // edi@102
  DBObjGrabber<ACCharGenData> cgData; // [sp+Ch] [bp-1DCh]@1
  PStringBase<char> rhs; // [sp+10h] [bp-1D8h]@92
  Sex_CG sex; // [sp+14h] [bp-1D4h]@8
  HeritageGroup_CG hg; // [sp+F0h] [bp-F8h]@4
  char v47; // [sp+1B0h] [bp-38h]@101
  char v48; // [sp+1B4h] [bp-34h]@102
  IDClass<_tagDataID,32,0> v49; // [sp+1B8h] [bp-30h]@102
  char v50; // [sp+1BCh] [bp-2Ch]@100
  IDClass<_tagDataID,32,0> result; // [sp+1C0h] [bp-28h]@101
  char tempName[33]; // [sp+1C4h] [bp-24h]@85

  v2 = DBObj::GetByEnum(14, 2, 0x10000002u);
  v3 = v2;
  cgData.m_object = (ACCharGenData *)v2;
  if ( v2 )
  {
    v4 = this->heritageGroup;
    if ( v4 && v4 <= *(_DWORD *)(v3 + 172) )
    {
      ACCharGenData::GetHG((ACCharGenData *)v3, &hg, this->heritageGroup);
      if ( this->heritageGroup == 4 && !cgr )
        goto LABEL_82;
      v5 = this->gender;
      if ( v5 != 1 && v5 != 2 )
        goto LABEL_82;
      HeritageGroup_CG::GetSX(&hg, &sex, this->gender);
      v6 = this->eyesStrip;
      if ( v6 < (signed int)sex.mEyeStripList.m_num && v6 >= 0 )
      {
        v7 = this->noseStrip;
        if ( v7 >= (signed int)sex.mNoseStripList.m_num )
          goto LABEL_81;
        if ( v7 < 0 )
          goto LABEL_81;
        v8 = this->mouthStrip;
        if ( v8 >= (signed int)sex.mMouthStripList.m_num )
          goto LABEL_81;
        if ( v8 < 0 )
          goto LABEL_81;
        v9 = this->hairColor;
        if ( v9 >= (signed int)sex.mHairColorList.m_num )
          goto LABEL_81;
        if ( v9 < 0 )
          goto LABEL_81;
        v10 = this->eyeColor;
        if ( v10 >= (signed int)sex.mEyeColorList.m_num )
          goto LABEL_81;
        if ( v10 < 0 )
          goto LABEL_81;
        v11 = this->hairStyle;
        if ( v11 >= (signed int)sex.mHairStyleList.m_num )
          goto LABEL_81;
        if ( v11 < 0 )
          goto LABEL_81;
        v12 = this->headgearStyle;
        if ( v12 >= (signed int)sex.mHeadgearList.m_num )
          goto LABEL_81;
        if ( v12 < -1 )
          goto LABEL_81;
        if ( v12 > -1 )
        {
          v13 = ClothingTable::Get(sex.mHeadgearList.m_data[v12].clothingTable);
          if ( !v13 || !ClothingTable::GetCloPaletteTemplate((ClothingTable *)v13, this->headgearColor) )
            goto LABEL_81;
        }
        v14 = this->shirtStyle;
        if ( v14 >= (signed int)sex.mShirtList.m_num )
          goto LABEL_81;
        if ( v14 < 0 )
          goto LABEL_81;
        v15 = ClothingTable::Get(sex.mShirtList.m_data[v14].clothingTable);
        if ( !v15 )
          goto LABEL_81;
        if ( !ClothingTable::GetCloPaletteTemplate((ClothingTable *)v15, this->shirtColor) )
          goto LABEL_81;
        v16 = this->trousersStyle;
        if ( v16 >= (signed int)sex.mPantsList.m_num )
          goto LABEL_81;
        if ( v16 < 0 )
          goto LABEL_81;
        v17 = ClothingTable::Get(sex.mPantsList.m_data[v16].clothingTable);
        if ( !v17 )
          goto LABEL_81;
        if ( !ClothingTable::GetCloPaletteTemplate((ClothingTable *)v17, this->trousersColor) )
          goto LABEL_81;
        v18 = this->footwearStyle;
        if ( v18 >= (signed int)sex.mFootwearList.m_num )
          goto LABEL_81;
        if ( v18 < 0 )
          goto LABEL_81;
        v19 = ClothingTable::Get(sex.mFootwearList.m_data[v18].clothingTable);
        if ( !v19 )
          goto LABEL_81;
        if ( !ClothingTable::GetCloPaletteTemplate((ClothingTable *)v19, this->footwearColor) )
          goto LABEL_81;
        if ( this->skinShade > 1.0 )
          goto LABEL_81;
        if ( this->skinShade < 0.0 )
          goto LABEL_81;
        if ( this->hairShade > 1.0 )
          goto LABEL_81;
        if ( this->hairShade < 0.0 )
          goto LABEL_81;
        if ( this->headgearShade > 1.0 )
          goto LABEL_81;
        if ( this->headgearShade < 0.0 )
          goto LABEL_81;
        if ( this->shirtShade > 1.0 )
          goto LABEL_81;
        if ( this->shirtShade < 0.0 )
          goto LABEL_81;
        if ( this->trousersShade > 1.0 )
          goto LABEL_81;
        if ( this->trousersShade < 0.0 )
          goto LABEL_81;
        if ( this->footwearShade > 1.0 )
          goto LABEL_81;
        if ( this->footwearShade < 0.0 )
          goto LABEL_81;
        v20 = this->strength;
        if ( v20 < 10 )
          goto LABEL_81;
        if ( v20 > 100 )
          goto LABEL_81;
        v21 = this->endurance;
        if ( v21 < 10 )
          goto LABEL_81;
        if ( v21 > 100 )
          goto LABEL_81;
        v22 = this->coordination;
        if ( v22 < 10 )
          goto LABEL_81;
        if ( v22 > 100 )
          goto LABEL_81;
        v23 = this->quickness;
        if ( v23 < 10 )
          goto LABEL_81;
        if ( v23 > 100 )
          goto LABEL_81;
        v24 = this->focus;
        if ( v24 < 10 )
          goto LABEL_81;
        if ( v24 > 100 )
          goto LABEL_81;
        v25 = this->self;
        if ( v25 < 10 )
          goto LABEL_81;
        if ( v25 > 100 )
          goto LABEL_81;
        if ( v24 + v25 + v20 + v21 + v22 + v23 > hg.numAttributeCredits )
          goto LABEL_81;
        v26 = DBCache::GetFromEnumStatic(4, 2, 0x10000004u);
        if ( !v26 )
          goto LABEL_81;
        v27 = this->numSkills;
        v28 = 0;
        v29 = 0;
        if ( v27 )
        {
          v30 = this->skillAdvancementClasses;
          do
          {
            if ( *v30 )
            {
              if ( *v30 <= 0 || *v30 > 3 )
              {
                (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 20))(v26);
                goto LABEL_81;
              }
              ++v28;
            }
            ++v29;
            ++v30;
          }
          while ( v29 < v27 );
        }
        if ( v28 != *(_DWORD *)(v26 + 72) )
          goto LABEL_80;
        v31 = 0;
        v32 = 0;
        if ( !v27 )
          goto LABEL_83;
        while ( this->skillAdvancementClasses[v32] != 2 )
        {
          if ( this->skillAdvancementClasses[v32] == 3 )
          {
            v33 = ACCharGenData::GetSkillSpecializedCost(cgData.m_object, v32, this->heritageGroup, this->gender);
LABEL_77:
            v31 += v33;
          }
          ++v32;
          if ( (unsigned int)v32 >= this->numSkills )
          {
            if ( v31 > hg.numSkillCredits )
            {
LABEL_80:
              (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 20))(v26);
              goto LABEL_81;
            }
LABEL_83:
            (*(void (__thiscall **)(int))(*(_DWORD *)v26 + 20))(v26);
            v34 = this->name.m_buffer;
            if ( v34->m_len != 1 && v34->m_len - 1 <= 0x20 )
            {
              v35 = (int)v34->m_data;
              v36 = &tempName[-v35];
              do
              {
                v37 = *(_BYTE *)v35;
                v36[v35] = *(_BYTE *)v35;
                ++v35;
              }
              while ( v37 );
              ACCharGenData::FormatName(tempName);
              if ( !strcmp(tempName, this->name.m_buffer->m_data) )
              {
                v38 = this->templateNum;
                if ( v38 < (signed int)hg.mTemplateList.m_num
                  && (v38 >= 0 || v38 == -1)
                  && this->startArea < cgData.m_object->mStartAreaList.m_num )
                {
                  PStringBase<char>::PStringBase<char>(&rhs, "Sanamar");
                  v39 = PStringBase<char>::operator==(
                          &cgData.m_object->mStartAreaList.m_data[this->startArea].name,
                          &rhs)
                     && !cgr;
                  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&rhs);
                  if ( !v39
                    && (!(*(int (__thiscall **)(ACCharGenResult *))&this->vfptr[2].gap4[0])(this)
                     || ((int (__thiscall *)(ACCharGenResult *))this->vfptr[2].__vecDelDtor)(this)) )
                  {
                    if ( !((int (__thiscall *)(ACCharGenResult *))this->vfptr[2].__vecDelDtor)(this)
                      || (v40 = WClassIDToDataID((IDClass<_tagDataID,32,0> *)&rhs, 0x10000004u)->id,
                          *(_DWORD *)((int (__thiscall *)(ACCharGenResult *, char *))this->vfptr[1].Pack)(this, &v50) == v40)
                      || (v41 = WClassIDToDataID(&result, 0x10000092u)->id,
                          *(_DWORD *)((int (__thiscall *)(ACCharGenResult *, char *))this->vfptr[1].Pack)(this, &v47) == v41)
                      || (v42 = WClassIDToDataID(&v49, 0x10000093u)->id,
                          *(_DWORD *)((int (__thiscall *)(_DWORD, char *))this->vfptr[1].Pack)(this, &v48) == v42) )
                    {
                      Sex_CG::~Sex_CG(&sex);
                      HeritageGroup_CG::~HeritageGroup_CG(&hg);
                      DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>(&cgData);
                      return 1;
                    }
                  }
                }
              }
            }
LABEL_81:
            Sex_CG::~Sex_CG(&sex);
LABEL_82:
            HeritageGroup_CG::~HeritageGroup_CG(&hg);
            DBObjGrabber<StringTable>::~DBObjGrabber<StringTable>(&cgData);
            return 0;
          }
        }
        v33 = ACCharGenData::GetSkillTrainedCost(cgData.m_object, v32, this->heritageGroup, this->gender);
        goto LABEL_77;
      }
      Sex_CG::~Sex_CG(&sex);
      HeritageGroup_CG::~HeritageGroup_CG(&hg);
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
      v2 = 0;
    }
    else
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 20))(v3);
      v2 = 0;
    }
  }
  return v2;
}

//----- (005C80E0) --------------------------------------------------------  // acclient.c:499184
int __thiscall ACCharGenResult::VerifyCharacterGenerationResult(ACCharGenResult *this, const int has_throne_of_destiny)
{
  return ACCharGenResult::VerifyCharacterGenerationResult(this, (ACCharGenResult *)has_throne_of_destiny);
}

//----- (0070F5A0) --------------------------------------------------------  // acclient.c:802537
void sub_70F5A0()
{
  flt_8EF8E0 = 1000.0 + 1.0;
}

//----- (0070F5C0) --------------------------------------------------------  // acclient.c:802543
void sub_70F5C0()
{
  flt_8EF8E4 = 24.0 * 8.0;
}

//----- (0070F5E0) --------------------------------------------------------  // acclient.c:802549
void sub_70F5E0()
{
  flt_8EF8E8 = 24.0 * 0.5;
}

//----- (0070F600) --------------------------------------------------------  // acclient.c:802555
int sub_70F600()
{
  return atexit(nullsub_1701);
}

//----- (0070F610) --------------------------------------------------------  // acclient.c:802561
int sub_70F610()
{
  return atexit(nullsub_1702);
}

//----- (0070F620) --------------------------------------------------------  // acclient.c:802567
int sub_70F620()
{
  return atexit(nullsub_1703);
}

//----- (0070F630) --------------------------------------------------------  // acclient.c:802573
int sub_70F630()
{
  return atexit(nullsub_1700);
}

