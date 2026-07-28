/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmCG3DView
   Object     : GAME\game_ui_misc\gmCG3DView.obj
   Functions  : 24
   Addresses  : 004EE590 - 006F79D0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004EE590) --------------------------------------------------------  // acclient.c:282964
void __thiscall gmCG3DView::SetPlayerHeading(gmCG3DView *this, float _fHeading)
{
  this->m_fHeading = _fHeading;
  CPhysicsObj::set_heading(this->m_pPlayerObject, _fHeading, 1);
}

//----- (004EE5B0) --------------------------------------------------------  // acclient.c:282971
void __thiscall gmCG3DView::SetCamera(gmCG3DView *this, AC1Legacy::Vector3 *_vectPosition, AC1Legacy::Vector3 *_vectDirection)
{
  this->m_vectPosition = _vectPosition->0;
  this->m_vectDirection = _vectDirection->0;
  UIElement_Viewport::SetCamera(this->m_pViewport, &this->m_vectPosition, &this->m_vectDirection);
}

//----- (004EE600) --------------------------------------------------------  // acclient.c:282979
void __thiscall gmCG3DView::StartAnimation(gmCG3DView *this)
{
  gmCG3DView *v1; // esi@1
  unsigned int v2; // edx@1

  v1 = this;
  CPhysicsObj::clear_sequence_anims(this->m_pPlayerObject);
  CPhysicsObj::set_sequence_animation(v1->m_pPlayerObject, v1->m_didAnimation, 1, 0, 30.0);
  v2 = Timer::cur_time.Param;
  LODWORD(v1->m_dLastAnimTime) = Timer::cur_time.Cmd;
  HIDWORD(v1->m_dLastAnimTime) = v2;
}

//----- (004EE640) --------------------------------------------------------  // acclient.c:282993
void __thiscall gmCG3DView::StopAnimation(gmCG3DView *this)
{
  gmCG3DView *v1; // esi@1

  v1 = this;
  CPhysicsObj::clear_sequence_anims(this->m_pPlayerObject);
  CPhysicsObj::set_sequence_animation(v1->m_pPlayerObject, v1->m_didAnimationRest, 1, 0, 0.0);
}

//----- (004EE660) --------------------------------------------------------  // acclient.c:283003
int __cdecl ClothingTable::Get(IDClass<_tagDataID,32,0> did)
{
  QualifiedDataID *v1; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, did, 0x19u);
  return DBObj::Get(v1);
}

//----- (004EE680) --------------------------------------------------------  // acclient.c:283013
void __thiscall gmCG3DView::gmCG3DView(gmCG3DView *this)
{
  gmCG3DView *v1; // esi@1
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v1 = this;
  this->m_pViewport = 0;
  this->m_pPlayerObject = 0;
  this->m_pbgObject = 0;
  this->m_alternateSetupID.id = stru_840CBC.id;
  LODWORD(this->m_fHeading) = 0;
  LODWORD(this->m_vectPosition.x) = 0;
  LODWORD(this->m_vectPosition.y) = 0;
  LODWORD(this->m_vectPosition.z) = 0;
  LODWORD(this->m_vectDirection.x) = 0;
  LODWORD(this->m_vectDirection.y) = 0;
  LODWORD(this->m_vectDirection.z) = 0;
  this->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435462, 7)->id;
  v1->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435461, 7)->id;
  v1->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435463, 7)->id;
  v1->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435464, 7)->id;
  v1->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435465, 7)->id;
  v1->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435466, 7)->id;
  v1->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435467, 7)->id;
  v1->m_SetupID.id = HUMAN_SETUP_ID.id;
}

//----- (004EE760) --------------------------------------------------------  // acclient.c:283042
void __thiscall gmCG3DView::Initialize(gmCG3DView *this, UIElement_Viewport *_pViewport)
{
  gmCG3DView *v2; // esi@1
  CPlayerSystem *v3; // eax@1
  CharGenState *v4; // eax@1
  CharGenState *v5; // edi@1
  unsigned int v6; // ebx@1
  IDClass<_tagDataID,32,0> v7; // eax@2
  unsigned int v8; // edi@4
  IDClass<_tagDataID,32,0> result; // [sp+0h] [bp-4h]@1

  result.id = (unsigned int)this;
  v2 = this;
  this->m_pViewport = _pViewport;
  v3 = CPlayerSystem::GetPlayerSystem();
  v2->m_pPlayerSystem = v3;
  CPlayerSystem::GetCharGenState(v3);
  v5 = v4;
  CharGenState::GetSetupID(v4, (IDClass<_tagDataID,32,0> *)&_pViewport);
  v6 = stru_840CBC.id;
  if ( CharGenState::GetSetupID(v5, &result)->id == v6 )
  {
    v7.id = HUMAN_SETUP_ID.id;
    _pViewport = (UIElement_Viewport *)HUMAN_SETUP_ID.id;
  }
  else
  {
    v7.id = (unsigned int)_pViewport;
  }
  v8 = v5->mHeritageGroup;
  v2->m_pPlayerObject = CPhysicsObj::makeObject(v7, 0, 1);
  if ( v8 == 12 )
  {
    v2->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435473, 7)->id;
    v2->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435473, 7)->id;
    v2->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
    v2->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
    v2->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
    v2->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
    v2->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
  }
  else if ( v8 == 13 )
  {
    v2->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435475, 7)->id;
    v2->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435475, 7)->id;
    v2->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
    v2->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
    v2->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
    v2->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
    v2->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
  }
  else
  {
    v2->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435462, 7)->id;
    v2->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435461, 7)->id;
    v2->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435463, 7)->id;
    v2->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435464, 7)->id;
    v2->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435465, 7)->id;
    v2->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435466, 7)->id;
    v2->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435467, 7)->id;
  }
  CreatureMode::UseSharpMode((CreatureMode *)&v2->m_pViewport->creature_mode_objects);
}

//----- (004EE9D0) --------------------------------------------------------  // acclient.c:283107
void __thiscall gmCG3DView::Update(gmCG3DView *this)
{
  gmCG3DView *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@1
  unsigned int v4; // eax@1
  unsigned int v5; // eax@3
  CPhysicsObj *v6; // ecx@9
  CPhysicsObj *v7; // eax@11
  CreatureMode *v8; // ecx@11
  int v9; // eax@12
  UIElement_Viewport *v10; // ecx@17
  unsigned int v11; // eax@17
  CPhysicsObj *v12; // ecx@18
  CPhysicsObj *v13; // eax@21
  CreatureMode *v14; // ecx@21
  int v15; // eax@22
  int v16; // eax@24
  QualifiedDataID *v17; // eax@25
  int v18; // ebx@25
  const unsigned int v19; // ebp@26
  int v20; // eax@26
  ShadePackage *v21; // eax@26
  int v22; // eax@27
  QualifiedDataID *v23; // eax@28
  int v24; // ebx@28
  const unsigned int v25; // ebp@29
  int v26; // eax@29
  ShadePackage *v27; // eax@29
  int v28; // eax@30
  QualifiedDataID *v29; // eax@31
  int v30; // ebx@31
  const unsigned int v31; // ebp@32
  int v32; // eax@32
  ShadePackage *v33; // eax@32
  int v34; // eax@33
  QualifiedDataID *v35; // eax@34
  int v36; // ebx@34
  const unsigned int v37; // ebp@35
  int v38; // eax@35
  ShadePackage *v39; // eax@35
  int v40; // eax@36
  EyesStrip_CG *v41; // ebx@37
  int v42; // ebx@38
  int v43; // eax@41
  int v44; // eax@43
  QualifiedDataID *v45; // eax@45
  int v46; // ebp@45
  void *v47; // ebx@45
  unsigned int v48; // ecx@46
  int v49; // eax@48
  QualifiedDataID *v50; // eax@49
  int v51; // ebp@49
  void *v52; // ebx@49
  unsigned int v53; // edx@50
  int v54; // edi@53
  unsigned int v55; // edi@54
  void *v56; // eax@54
  IDClass<_tagDataID,32,0> result; // [sp+14h] [bp-20Ch]@13
  int v58; // [sp+18h] [bp-208h]@26
  IDClass<_tagDataID,32,0> setupID; // [sp+1Ch] [bp-204h]@1
  QualifiedDataID v60; // [sp+20h] [bp-200h]@25
  Vector3 direction; // [sp+28h] [bp-1F8h]@17
  ObjDesc changes; // [sp+34h] [bp-1ECh]@22
  ShadePackage v63; // [sp+60h] [bp-1C0h]@26
  Sex_CG curSX; // [sp+80h] [bp-1A0h]@3
  HeritageGroup_CG curHG; // [sp+160h] [bp-C0h]@3

  v1 = this;
  setupID.id = 0;
  CPlayerSystem::GetCharGenState(this->m_pPlayerSystem);
  v3 = v2;
  v4 = *(_DWORD *)(v2 + 212);
  if ( v4 && *(_DWORD *)(v3 + 216) )
  {
    ACCharGenData::GetHG(*(ACCharGenData **)(v3 + 596), &curHG, v4);
    HeritageGroup_CG::GetSX(&curHG, &curSX, *(_DWORD *)(v3 + 216));
    CharGenState::GetSetupID((CharGenState *)v3, &setupID);
    v5 = v1->m_alternateSetupID.id;
    if ( v5 == stru_840CBC.id )
      v5 = setupID.id;
    else
      setupID.id = v1->m_alternateSetupID.id;
    if ( v5 == stru_840CBC.id )
    {
      v5 = HUMAN_SETUP_ID.id;
      setupID.id = HUMAN_SETUP_ID.id;
    }
    if ( v1->m_SetupID.id != v5 )
    {
      CreatureMode::RemoveObject((CreatureMode *)&v1->m_pViewport->creature_mode_objects, v1->m_pPlayerObject);
      v6 = v1->m_pPlayerObject;
      v1->m_SetupID.id = setupID.id;
      if ( v6 )
        ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
      v7 = CPhysicsObj::makeObject(v1->m_SetupID, 0, 1);
      v8 = (CreatureMode *)&v1->m_pViewport->creature_mode_objects;
      v1->m_pPlayerObject = v7;
      CreatureMode::AddObject(v8, v7);
    }
    v9 = *(_DWORD *)(v3 + 212);
    if ( v9 == 12 )
    {
      v1->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435473, 7)->id;
      v1->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435473, 7)->id;
      v1->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
      v1->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
      v1->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
      v1->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
      v1->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435474, 7)->id;
    }
    else if ( v9 == 13 )
    {
      v1->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435475, 7)->id;
      v1->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435475, 7)->id;
      v1->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
      v1->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
      v1->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
      v1->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
      v1->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435476, 7)->id;
    }
    else
    {
      v1->m_didAnimation.id = DBObj::GetDIDByEnum(&result, 268435462, 7)->id;
      v1->m_didAnimationRest.id = DBObj::GetDIDByEnum(&result, 268435461, 7)->id;
      v1->m_didAnimArray[0].id = DBObj::GetDIDByEnum(&result, 268435463, 7)->id;
      v1->m_didAnimArray[1].id = DBObj::GetDIDByEnum(&result, 268435464, 7)->id;
      v1->m_didAnimArray[2].id = DBObj::GetDIDByEnum(&result, 268435465, 7)->id;
      v1->m_didAnimArray[3].id = DBObj::GetDIDByEnum(&result, 268435466, 7)->id;
      v1->m_didAnimArray[4].id = DBObj::GetDIDByEnum(&result, 268435467, 7)->id;
    }
    CreatureMode::RemoveAllObjects((CreatureMode *)&v1->m_pViewport->creature_mode_objects);
    v10 = v1->m_pViewport;
    LODWORD(direction.x) = 1050253722;
    LODWORD(direction.y) = 1072902963;
    LODWORD(direction.z) = 1059481190;
    UIElement_Viewport::SetLight(v10, DISTANT_LIGHT, 2.0, &direction);
    CPhysicsObj::set_heading(v1->m_pPlayerObject, v1->m_fHeading, 1);
    v1->m_pPlayerObject->m_bExaminationObject = 1;
    v11 = curHG.environmentSetupID.id;
    if ( v1->m_bgSetupID.id != curHG.environmentSetupID.id )
    {
      v12 = v1->m_pbgObject;
      if ( v12 )
      {
        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
        v11 = curHG.environmentSetupID.id;
        v1->m_pbgObject = 0;
      }
    }
    v1->m_bgSetupID.id = v11;
    if ( v11 != stru_840CBC.id )
    {
      v13 = CPhysicsObj::makeObject((IDClass<_tagDataID,32,0>)v11, 0, 1);
      v14 = (CreatureMode *)&v1->m_pViewport->creature_mode_objects;
      v1->m_pbgObject = v13;
      CreatureMode::AddObject(v14, v13);
    }
    ObjDesc::ObjDesc(&changes);
    changes.paletteID.id = curSX.basePalette.id;
    ObjDesc::operator+=(&changes, &curSX.objDesc);
    v15 = *(_DWORD *)(v3 + 240);
    if ( v15 != -1 )
      ObjDesc::operator+=(&changes, &curSX.mHairStyleList.m_data[v15].objDesc);
    v16 = *(_DWORD *)(v3 + 244);
    if ( v16 != -1 )
    {
      QualifiedDataID::QualifiedDataID(&v60, curSX.mHeadgearList.m_data[v16].clothingTable, 0x19u);
      v18 = DBObj::Get(v17);
      if ( v18 )
      {
        v19 = CharGenState::GetHeadgearPaletteTemplateID((CharGenState *)v3, *(_DWORD *)(v3 + 248));
        v20 = *(_DWORD *)(v3 + 348);
        result.id = *(_DWORD *)(v3 + 344);
        v58 = v20;
        ShadePackage::ShadePackage(&v63, COERCE_CONST_LONG_DOUBLE(__PAIR__(v20, result.id)));
        ClothingTable::BuildObjDesc((ClothingTable *)v18, v1->m_SetupID, v19, v21, &changes);
        (*(void (__thiscall **)(int))(*(_DWORD *)v18 + 20))(v18);
      }
    }
    v22 = *(_DWORD *)(v3 + 260);
    if ( v22 != -1 )
    {
      QualifiedDataID::QualifiedDataID(&v60, curSX.mPantsList.m_data[v22].clothingTable, 0x19u);
      v24 = DBObj::Get(v23);
      if ( v24 )
      {
        v25 = CharGenState::GetTrousersPaletteTemplateID((CharGenState *)v3, *(_DWORD *)(v3 + 264));
        v26 = *(_DWORD *)(v3 + 364);
        result.id = *(_DWORD *)(v3 + 360);
        v58 = v26;
        ShadePackage::ShadePackage(&v63, COERCE_CONST_LONG_DOUBLE(__PAIR__(v26, result.id)));
        ClothingTable::BuildObjDesc((ClothingTable *)v24, v1->m_SetupID, v25, v27, &changes);
        (*(void (__thiscall **)(int))(*(_DWORD *)v24 + 20))(v24);
      }
    }
    v28 = *(_DWORD *)(v3 + 252);
    if ( v28 != -1 )
    {
      QualifiedDataID::QualifiedDataID(&v60, curSX.mShirtList.m_data[v28].clothingTable, 0x19u);
      v30 = DBObj::Get(v29);
      if ( v30 )
      {
        v31 = CharGenState::GetShirtPaletteTemplateID((CharGenState *)v3, *(_DWORD *)(v3 + 256));
        v32 = *(_DWORD *)(v3 + 356);
        result.id = *(_DWORD *)(v3 + 352);
        v58 = v32;
        ShadePackage::ShadePackage(&v63, COERCE_CONST_LONG_DOUBLE(__PAIR__(v32, result.id)));
        ClothingTable::BuildObjDesc((ClothingTable *)v30, v1->m_SetupID, v31, v33, &changes);
        (*(void (__thiscall **)(int))(*(_DWORD *)v30 + 20))(v30);
      }
    }
    v34 = *(_DWORD *)(v3 + 268);
    if ( v34 != -1 )
    {
      QualifiedDataID::QualifiedDataID(&v60, curSX.mFootwearList.m_data[v34].clothingTable, 0x19u);
      v36 = DBObj::Get(v35);
      if ( v36 )
      {
        v37 = CharGenState::GetFootwearPaletteTemplateID((CharGenState *)v3, *(_DWORD *)(v3 + 272));
        v38 = *(_DWORD *)(v3 + 372);
        result.id = *(_DWORD *)(v3 + 368);
        v58 = v38;
        ShadePackage::ShadePackage(&v63, COERCE_CONST_LONG_DOUBLE(__PAIR__(v38, result.id)));
        ClothingTable::BuildObjDesc((ClothingTable *)v36, v1->m_SetupID, v37, v39, &changes);
        (*(void (__thiscall **)(int))(*(_DWORD *)v36 + 20))(v36);
      }
    }
    v40 = *(_DWORD *)(v3 + 220);
    if ( v40 != -1 )
    {
      v41 = &curSX.mEyeStripList.m_data[v40];
      if ( CharGenState::GetBaldState((CharGenState *)v3) )
        v42 = (int)&v41->objDesc_Bald;
      else
        v42 = (int)&v41->objDesc;
      ObjDesc::operator+=(&changes, (ObjDesc *)v42);
    }
    v43 = *(_DWORD *)(v3 + 224);
    if ( v43 != -1 )
      ObjDesc::operator+=(&changes, &curSX.mNoseStripList.m_data[v43].objDesc);
    v44 = *(_DWORD *)(v3 + 228);
    if ( v44 != -1 )
      ObjDesc::operator+=(&changes, &curSX.mMouthStripList.m_data[v44].objDesc);
    QualifiedDataID::QualifiedDataID((QualifiedDataID *)&direction, curSX.skinPalSet, 0x18u);
    v46 = DBObj::Get(v45);
    v47 = operator new(0x18u);
    if ( v47 )
    {
      v48 = *(_DWORD *)(v3 + 328);
      v60.ID.id = *(_DWORD *)(v3 + 332);
      v60.Type = v48;
      *((_DWORD *)v47 + 1) = PalSet::GetPaletteID((PalSet *)v46, &result, COERCE_LONG_DOUBLE(__PAIR__(v60.ID.id, v48)))->id;
      *(_DWORD *)v47 = &Subpalette::vftable;
      *((_DWORD *)v47 + 2) = 0;
      *((_DWORD *)v47 + 3) = 192;
      *((_DWORD *)v47 + 4) = 0;
      *((_DWORD *)v47 + 5) = 0;
    }
    else
    {
      v47 = 0;
    }
    ObjDesc::AddSubpalette(&changes, (Subpalette *)v47);
    (*(void (__thiscall **)(int))(*(_DWORD *)v46 + 20))(v46);
    v49 = *(_DWORD *)(v3 + 232);
    if ( v49 != -1 )
    {
      QualifiedDataID::QualifiedDataID((QualifiedDataID *)&direction, curSX.mHairColorList.m_data[v49], 0x18u);
      v51 = DBObj::Get(v50);
      v52 = operator new(0x18u);
      if ( v52 )
      {
        v53 = *(_DWORD *)(v3 + 336);
        v60.ID.id = *(_DWORD *)(v3 + 340);
        v60.Type = v53;
        *((_DWORD *)v52 + 1) = PalSet::GetPaletteID(
                                 (PalSet *)v51,
                                 &result,
                                 COERCE_LONG_DOUBLE(__PAIR__(v60.ID.id, v53)))->id;
        *(_DWORD *)v52 = &Subpalette::vftable;
        *((_DWORD *)v52 + 2) = 192;
        *((_DWORD *)v52 + 3) = 64;
        *((_DWORD *)v52 + 4) = 0;
        *((_DWORD *)v52 + 5) = 0;
      }
      else
      {
        v52 = 0;
      }
      ObjDesc::AddSubpalette(&changes, (Subpalette *)v52);
      (*(void (__thiscall **)(int))(*(_DWORD *)v51 + 20))(v51);
    }
    v54 = *(_DWORD *)(v3 + 236);
    if ( v54 != -1 )
    {
      v55 = curSX.mEyeColorList.m_data[v54].id;
      v56 = operator new(0x18u);
      if ( v56 )
      {
        *(_DWORD *)v56 = &Subpalette::vftable;
        *((_DWORD *)v56 + 1) = v55;
        *((_DWORD *)v56 + 2) = 256;
        *((_DWORD *)v56 + 3) = 64;
        *((_DWORD *)v56 + 4) = 0;
        *((_DWORD *)v56 + 5) = 0;
      }
      else
      {
        v56 = 0;
      }
      ObjDesc::AddSubpalette(&changes, (Subpalette *)v56);
    }
    CPhysicsObj::DoObjDescChangesFromDefault(v1->m_pPlayerObject, &changes);
    CreatureMode::AddObject((CreatureMode *)&v1->m_pViewport->creature_mode_objects, v1->m_pPlayerObject);
    UIElement_Viewport::SetCamera(v1->m_pViewport, &v1->m_vectPosition, &v1->m_vectDirection);
    ObjDesc::~ObjDesc(&changes);
    Sex_CG::~Sex_CG(&curSX);
    HeritageGroup_CG::~HeritageGroup_CG(&curHG);
  }
}
// 7C3674: using guessed type int (__thiscall *Subpalette::vftable)(void *, char);

//----- (006F7880) --------------------------------------------------------  // acclient.c:780341
void sub_6F7880()
{
  flt_840CC0 = 1000.0 + 1.0;
}

//----- (006F78A0) --------------------------------------------------------  // acclient.c:780347
void sub_6F78A0()
{
  flt_840CC4 = 24.0 * 8.0;
}

//----- (006F78C0) --------------------------------------------------------  // acclient.c:780353
void sub_6F78C0()
{
  flt_840CC8 = 24.0 * 0.5;
}

//----- (006F78E0) --------------------------------------------------------  // acclient.c:780359
int sub_6F78E0()
{
  return atexit(nullsub_536);
}

//----- (006F78F0) --------------------------------------------------------  // acclient.c:780365
int sub_6F78F0()
{
  return atexit(nullsub_537);
}

//----- (006F7900) --------------------------------------------------------  // acclient.c:780371
int sub_6F7900()
{
  return atexit(nullsub_538);
}

//----- (006F7910) --------------------------------------------------------  // acclient.c:780377
void _E106_79()
{
  DEFAULT_VIEW_RADIUS_81 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F7930) --------------------------------------------------------  // acclient.c:780383
void _E108_61()
{
  MIN_QUANTUM_81 = 1.0 / 30.0;
}

//----- (006F7950) --------------------------------------------------------  // acclient.c:780389
void _E110_51()
{
  MAX_QUANTUM_81 = 1.0 / 5.0;
}

//----- (006F7970) --------------------------------------------------------  // acclient.c:780395
void _E112_71()
{
  PixelFormatDesc::PixelFormatDesc(&stru_840CE0, PFID_A8R8G8B8);
}

//----- (006F7980) --------------------------------------------------------  // acclient.c:780401
int _E114_37()
{
  return atexit(nullsub_533);
}

//----- (006F7990) --------------------------------------------------------  // acclient.c:780407
void _E120_45()
{
  dword_840D18 = 1024;
}

//----- (006F79A0) --------------------------------------------------------  // acclient.c:780413
void _E122_24()
{
  dword_840D1C = 0x7FFF;
}

//----- (006F79B0) --------------------------------------------------------  // acclient.c:780419
int _E124_50()
{
  const int result; // eax@1

  result = dword_840D18;
  INITIAL_MAX_DATA_RATE_54 = dword_840D18;
  return result;
}

//----- (006F79C0) --------------------------------------------------------  // acclient.c:780429
int _E126_27()
{
  return atexit(_E127_98);
}

//----- (006F79D0) --------------------------------------------------------  // acclient.c:780435
int sub_6F79D0()
{
  return atexit(nullsub_535);
}

