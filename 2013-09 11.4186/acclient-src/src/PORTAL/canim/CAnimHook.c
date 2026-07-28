/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CAnimHook
   Object     : PORTAL\canim\CAnimHook.obj
   Functions  : 116
   Addresses  : 004F70B0 - 007683E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004F70B0) --------------------------------------------------------  // acclient.c:290357
int DBFile2IDTable::GetDBOType()
{
  return 21;
}

//----- (004FDA70) --------------------------------------------------------  // acclient.c:297797
int UIElement_GroupBox::GetUIElementType()
{
  return 17;
}

//----- (005247E0) --------------------------------------------------------  // acclient.c:339651
CreateBlockingParticleHook *__thiscall SetOmegaHook::vector_deleting_destructor(CreateBlockingParticleHook *this, unsigned int a2)
{
  CreateBlockingParticleHook *v2; // esi@1

  v2 = this;
  this->vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);

//----- (00524800) --------------------------------------------------------  // acclient.c:339664
int __stdcall DefaultScriptHook::UnPack(void **addr, unsigned int size)
{
  return 1;
}

//----- (005267B0) --------------------------------------------------------  // acclient.c:341992
void __thiscall AttackCone::~AttackCone(AttackCone *this)
{
  AttackCone *v1; // esi@1

  v1 = this;
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&this->right);
  gmNoticeHandler::RecvNotice_PrevSpellSelection((DiskSpace *)&v1->left);
}

//----- (005267D0) --------------------------------------------------------  // acclient.c:342002
void __thiscall AttackHook::AttackHook(AttackHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&AttackHook::vftable;
  DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
  DeleteLeafTransactInfo::DynamicCast_DeleteLeaf();
}
// 7C85EC: using guessed type int (__thiscall *AttackHook::vftable)(void *, char);

//----- (00526810) --------------------------------------------------------  // acclient.c:342019
AttackHook *__thiscall AttackHook::scalar_deleting_destructor(AttackHook *this, unsigned int a2)
{
  AttackHook *v2; // esi@1

  v2 = this;
  this->vfptr = (CAnimHookVtbl *)&AttackHook::vftable;
  AttackCone::~AttackCone(&this->attack_cone);
  v2->vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);
// 7C85EC: using guessed type int (__thiscall *AttackHook::vftable)(void *, char);

//----- (00526860) --------------------------------------------------------  // acclient.c:342047
int DefaultScriptPartHook::GetType()
{
  return 18;
}

//----- (00526870) --------------------------------------------------------  // acclient.c:342053
int LuminousPartHook::GetType()
{
  return 9;
}

//----- (005268A0) --------------------------------------------------------  // acclient.c:342071
int DestroyParticleHook::GetType()
{
  return 14;
}

//----- (005268C0) --------------------------------------------------------  // acclient.c:342083
void __thiscall TextureVelocityPartHook::TextureVelocityPartHook(TextureVelocityPartHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&TextureVelocityPartHook::vftable;
  this->part_index = -1;
  LODWORD(this->u_speed) = 0;
  LODWORD(this->v_speed) = 0;
}
// 7C8774: using guessed type int (__thiscall *TextureVelocityPartHook::vftable)(void *, char);

//----- (00526900) --------------------------------------------------------  // acclient.c:342101
void __thiscall TextureVelocityHook::TextureVelocityHook(TextureVelocityHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&TextureVelocityHook::vftable;
  LODWORD(this->u_speed) = 0;
  LODWORD(this->v_speed) = 0;
}
// 7C8790: using guessed type int (__thiscall *TextureVelocityHook::vftable)(void *, char);

//----- (00526920) --------------------------------------------------------  // acclient.c:342112
int MessageDialog::GetUIElementType()
{
  return 23;
}

//----- (00526940) --------------------------------------------------------  // acclient.c:342124
void __thiscall CAnimHook::add_to_list(CAnimHook *this, CAnimHook **start)
{
  CAnimHook *v2; // eax@1

  v2 = *start;
  if ( *start )
  {
    for ( ; v2->next_hook; v2 = v2->next_hook )
      ;
    v2->next_hook = this;
  }
  else
  {
    *start = this;
  }
}

//----- (00526970) --------------------------------------------------------  // acclient.c:342142
int __cdecl CAnimHook::PackSize(CAnimHook *hook)
{
  int result; // eax@1

  result = ((int (*)(void))hook->vfptr->pack_size)() + 8;
  if ( result & 3 )
    result += 4 - (result & 3);
  return result;
}

//----- (005269A0) --------------------------------------------------------  // acclient.c:342153
void __cdecl CAnimHook::PackHook(CAnimHook *hook, void **addr, unsigned int size)
{
  char *v3; // ecx@1
  char *v4; // eax@1
  unsigned int v5; // ecx@1

  *(_DWORD *)*addr = hook->vfptr->GetType(hook);
  v3 = (char *)*addr + 4;
  *addr = v3;
  v4 = v3;
  v5 = size;
  *(_DWORD *)v4 = hook->direction_;
  *addr = (char *)*addr + 4;
  hook->vfptr->Pack(hook, addr, v5);
  PackObj::ALIGN_PTR(addr, &size);
}

//----- (00526A00) --------------------------------------------------------  // acclient.c:342177
void __thiscall SoundHook::SoundHook(SoundHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&SoundHook::vftable;
  this->gid_.id = stru_8445C4.id;
}
// 7C87C8: using guessed type int (__thiscall *SoundHook::vftable)(void *, char);

//----- (00526A20) --------------------------------------------------------  // acclient.c:342187
void __thiscall SoundHook::Execute(SoundHook *this, CPhysicsObj *physobj)
{
  SoundManager::PlaySoundA(this->gid_, physobj);
}

//----- (00526A40) --------------------------------------------------------  // acclient.c:342193
void __thiscall SoundTweakedHook::SoundTweakedHook(SoundTweakedHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&SoundTweakedHook::vftable;
  this->gid_.id = stru_8445C4.id;
  LODWORD(this->prio) = 1063675494;
  LODWORD(this->prob) = 1065353216;
  LODWORD(this->vol) = 1065353216;
}
// 7C87E4: using guessed type int (__thiscall *SoundTweakedHook::vftable)(void *, char);

//----- (00526A80) --------------------------------------------------------  // acclient.c:342206
void __thiscall SoundTweakedHook::Execute(SoundTweakedHook *this, CPhysicsObj *physobj)
{
  SoundManager::PlaySoundA(this->gid_, physobj, this->prio, this->prob, this->vol);
}

//----- (00526AB0) --------------------------------------------------------  // acclient.c:342218
void __thiscall SoundTableHook::Execute(SoundTableHook *this, CPhysicsObj *physobj)
{
  SoundManager::PlaySoundA(this->sound_type_, physobj);
}

//----- (00526AD0) --------------------------------------------------------  // acclient.c:342224
int __thiscall SoundTableHook::Pack(SoundHook *this, void **addr, unsigned int size)
{
  SoundHook *v3; // esi@1
  int result; // eax@1

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  *(_DWORD *)*addr = v3->gid_.id;
  *addr = (char *)*addr + 4;
  return result;
}

//----- (00526AF0) --------------------------------------------------------  // acclient.c:342237
int __thiscall SoundTableHook::UnPack(SoundTableHook *this, void **addr, unsigned int size)
{
  SoundType v3; // esi@1

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  this->sound_type_ = v3;
  return 1;
}

//----- (00526B10) --------------------------------------------------------  // acclient.c:342248
int __thiscall ReplaceObjectHook::pack_size(ReplaceObjectHook *this)
{
  PackObjVtbl *v1; // eax@1
  void *pDummy; // [sp+0h] [bp-4h]@1

  pDummy = this;
  v1 = this->ap_change.vfptr;
  pDummy = 0;
  return ((int (__thiscall *)(AnimPartChange *, void **, _DWORD))v1->Pack)(&this->ap_change, &pDummy, 0);
}

//----- (00526B30) --------------------------------------------------------  // acclient.c:342260
int __thiscall ReplaceObjectHook::Pack(ReplaceObjectHook *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(_DWORD, _DWORD))this->ap_change.vfptr->Pack)(addr, size);
}

//----- (00526B40) --------------------------------------------------------  // acclient.c:342266
int __thiscall ReplaceObjectHook::UnPack(ReplaceObjectHook *this, void **addr, unsigned int size)
{
  return ((int (__stdcall *)(void **, unsigned int))this->ap_change.vfptr->UnPack)(addr, size);
}

//----- (00526B50) --------------------------------------------------------  // acclient.c:342272
int AttackHook::pack_size()
{
  signed int v1; // edi@1

  v1 = TextureVelocityHook::pack_size();
  return v1 + TextureVelocityHook::pack_size() + 12;
}

//----- (00526B70) --------------------------------------------------------  // acclient.c:342281
void __thiscall AttackHook::Execute(AttackHook *this, CPhysicsObj *object)
{
  CPhysicsObj::attack(object, &this->attack_cone);
}

//----- (00526B80) --------------------------------------------------------  // acclient.c:342287
unsigned int __thiscall NoDrawHook::Pack(SetLightHook *this, void **addr, unsigned int size)
{
  SetLightHook *v3; // esi@1
  unsigned int result; // eax@1

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->_lights_on;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00526BA0) --------------------------------------------------------  // acclient.c:342303
int __thiscall DestroyParticleHook::UnPack(SetLightHook *this, void **addr, unsigned int size)
{
  this->_lights_on = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (00526BC0) --------------------------------------------------------  // acclient.c:342311
void __thiscall EtherealHook::Execute(EtherealHook *this, CPhysicsObj *object)
{
  CPhysicsObj::set_ethereal(object, this->ethereal, 0);
}

//----- (00526BE0) --------------------------------------------------------  // acclient.c:342317
void __thiscall NoDrawHook::Execute(NoDrawHook *this, CPhysicsObj *object)
{
  CPhysicsObj::set_nodraw(object, this->_no_draw, 0);
}

//----- (00526C00) --------------------------------------------------------  // acclient.c:342323
void __thiscall DefaultScriptPartHook::Execute(DefaultScriptPartHook *this, CPhysicsObj *object)
{
  CPhysicsObj::play_default_script(object, this->_part_index);
}

//----- (00526C10) --------------------------------------------------------  // acclient.c:342329
void __stdcall DefaultScriptHook::Execute(CPhysicsObj *object)
{
  CPhysicsObj::play_default_script(object);
}

//----- (00526C20) --------------------------------------------------------  // acclient.c:342335
void __stdcall AnimDoneHook::Execute(CPhysicsObj *object)
{
  CPhysicsObj::Hook_AnimDone(object);
}

//----- (00526C30) --------------------------------------------------------  // acclient.c:342341
void __thiscall TransparentHook::Execute(TransparentHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetTranslucency2(object, this->start, this->end, this->time);
}

//----- (00526C50) --------------------------------------------------------  // acclient.c:342347
unsigned int __thiscall DiffuseHook::Pack(DiffuseHook *this, void **addr, unsigned int size)
{
  DiffuseHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edx@2
  char *v6; // edx@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(float *)*addr = v3->start;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->end;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->time;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00526C90) --------------------------------------------------------  // acclient.c:342371
int __thiscall LuminousHook::UnPack(TextureVelocityPartHook *this, void **addr, unsigned int size)
{
  char *v3; // edx@1
  char *v4; // edx@1

  this->part_index = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  LODWORD(this->u_speed) = *(_DWORD *)v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  LODWORD(this->v_speed) = *(_DWORD *)v4;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (00526CC0) --------------------------------------------------------  // acclient.c:342388
void __thiscall TransparentPartHook::Execute(TransparentPartHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetPartTranslucency(object, this->part, this->start, this->end, this->time);
}

//----- (00526CF0) --------------------------------------------------------  // acclient.c:342394
int __thiscall TransparentPartHook::UnPack(DiffusePartHook *this, void **addr, unsigned int size)
{
  char *v3; // edx@1
  char *v4; // edx@1
  char *v5; // edx@1

  this->part = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  LODWORD(this->start) = *(_DWORD *)v3;
  v4 = (char *)*addr + 4;
  *addr = v4;
  LODWORD(this->end) = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  LODWORD(this->time) = *(_DWORD *)v5;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (00526D30) --------------------------------------------------------  // acclient.c:342415
void __thiscall LuminousPartHook::Execute(LuminousPartHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetPartLuminosity(object, this->part, this->start, this->end, this->time);
}

//----- (00526D60) --------------------------------------------------------  // acclient.c:342421
void __thiscall LuminousHook::Execute(LuminousHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetLuminosity(object, this->start, this->end, this->time);
}

//----- (00526D80) --------------------------------------------------------  // acclient.c:342427
void __thiscall DiffusePartHook::Execute(DiffusePartHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetPartDiffusion(object, this->part, this->start, this->end, this->time);
}

//----- (00526DB0) --------------------------------------------------------  // acclient.c:342433
unsigned int __thiscall DiffusePartHook::Pack(DiffusePartHook *this, void **addr, unsigned int size)
{
  DiffusePartHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edi@2
  char *v6; // edx@2
  char *v7; // edi@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->part;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->start;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->end;
    v7 = (char *)*addr + 4;
    *addr = v7;
    *(float *)v7 = v3->time;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00526E00) --------------------------------------------------------  // acclient.c:342461
void __thiscall DiffuseHook::Execute(DiffuseHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetDiffusion(object, this->start, this->end, this->time);
}

//----- (00526E20) --------------------------------------------------------  // acclient.c:342467
void __thiscall CallPESHook::Execute(CallPESHook *this, CPhysicsObj *object)
{
  CPhysicsObj::CallPES(object, this->pes, this->pause);
}

//----- (00526E40) --------------------------------------------------------  // acclient.c:342473
void __thiscall ScaleHook::Execute(ScaleHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetScale(object, this->end, this->time);
}

//----- (00526E60) --------------------------------------------------------  // acclient.c:342479
unsigned int __thiscall TextureVelocityHook::Pack(TextureVelocityHook *this, void **addr, unsigned int size)
{
  TextureVelocityHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edx@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(float *)*addr = v3->u_speed;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->v_speed;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00526E90) --------------------------------------------------------  // acclient.c:342499
int __thiscall ScaleHook::UnPack(TextureVelocityHook *this, void **addr, unsigned int size)
{
  char *v3; // edx@1

  LODWORD(this->u_speed) = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  LODWORD(this->v_speed) = *(_DWORD *)v3;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (00526EC0) --------------------------------------------------------  // acclient.c:342512
void __thiscall CreateParticleHook::Execute(CreateParticleHook *this, CPhysicsObj *object)
{
  CPhysicsObj::create_particle_emitter(object, this->emitter_info_id, this->part_index, &this->offset, this->emitter_id);
}

//----- (00526EF0) --------------------------------------------------------  // acclient.c:342524
void __thiscall CreateBlockingParticleHook::Execute(CreateBlockingParticleHook *this, CPhysicsObj *object)
{
  CPhysicsObj::create_blocking_particle_emitter(
    object,
    this->emitter_info_id,
    this->part_index,
    &this->offset,
    this->emitter_id);
}

//----- (00526F10) --------------------------------------------------------  // acclient.c:342535
void __thiscall DestroyParticleHook::Execute(DestroyParticleHook *this, CPhysicsObj *object)
{
  CPhysicsObj::destroy_particle_emitter(object, this->emitter_id);
}

//----- (00526F20) --------------------------------------------------------  // acclient.c:342541
void __thiscall StopParticleHook::Execute(StopParticleHook *this, CPhysicsObj *object)
{
  CPhysicsObj::stop_particle_emitter(object, this->emitter_id);
}

//----- (00526F30) --------------------------------------------------------  // acclient.c:342547
void __thiscall SetOmegaHook::Execute(SetOmegaHook *this, CPhysicsObj *object)
{
  CPhysicsObj::set_omega(object, &this->axis, 1);
}

//----- (00526F50) --------------------------------------------------------  // acclient.c:342553
void __thiscall TextureVelocityPartHook::Execute(TextureVelocityPartHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetPartTextureVelocity(object, this->part_index, this->u_speed, this->v_speed);
}

//----- (00526F70) --------------------------------------------------------  // acclient.c:342559
unsigned int __thiscall TextureVelocityPartHook::Pack(TextureVelocityPartHook *this, void **addr, unsigned int size)
{
  TextureVelocityPartHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edx@2
  char *v6; // edi@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->part_index;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->u_speed;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->v_speed;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00526FB0) --------------------------------------------------------  // acclient.c:342583
void __thiscall TextureVelocityHook::Execute(TextureVelocityHook *this, CPhysicsObj *object)
{
  CPhysicsObj::SetTextureVelocity(object, this->u_speed, this->v_speed);
}

//----- (00526FD0) --------------------------------------------------------  // acclient.c:342589
void __thiscall SetLightHook::Execute(SetLightHook *this, CPhysicsObj *object)
{
  CPhysicsObj::set_lights(object, this->_lights_on, 0);
}

//----- (00526FF0) --------------------------------------------------------  // acclient.c:342595
unsigned int __thiscall AttackCone::Pack(AttackCone *this, void **addr, unsigned int size)
{
  AttackCone *v3; // edi@1
  signed int v4; // ebx@1
  unsigned int v5; // ebp@1
  char *v6; // ecx@2

  v3 = this;
  v4 = TextureVelocityHook::pack_size();
  v5 = v4 + TextureVelocityHook::pack_size() + 12;
  if ( size >= v5 )
  {
    *(_DWORD *)*addr = v3->part_index;
    *addr = (char *)*addr + 4;
    Vec2D::Pack(&v3->left, addr, size);
    Vec2D::Pack(&v3->right, addr, size);
    *(float *)*addr = v3->radius;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->height;
    *addr = (char *)*addr + 4;
  }
  return v5;
}

//----- (00527060) --------------------------------------------------------  // acclient.c:342621
int __thiscall AttackCone::UnPack(AttackCone *this, void **addr, unsigned int size)
{
  void **v3; // esi@1
  AttackCone *v4; // edi@1
  char *v5; // ecx@1

  v3 = addr;
  v4 = this;
  this->part_index = *(_DWORD *)*addr;
  *v3 = (char *)*v3 + 4;
  Vec2D::UnPack(&this->left, addr, size);
  Vec2D::UnPack(&v4->right, addr, size);
  LODWORD(v4->radius) = *(_DWORD *)*addr;
  v5 = (char *)*addr + 4;
  *addr = v5;
  LODWORD(v4->height) = *(_DWORD *)v5;
  *v3 = (char *)*v3 + 4;
  return 1;
}

//----- (005270C0) --------------------------------------------------------  // acclient.c:342642
void __thiscall ReplaceObjectHook::ReplaceObjectHook(ReplaceObjectHook *this)
{
  this->next_hook = 0;
  this->direction_ = -2;
  this->vfptr = (CAnimHookVtbl *)&ReplaceObjectHook::vftable;
  this->ap_change.vfptr = (PackObjVtbl *)&AnimPartChange::vftable;
  this->ap_change.part_index = 0;
  this->ap_change.part_id.id = stru_8445C4.id;
  this->ap_change.prev = 0;
  this->ap_change.next = 0;
}
// 7C881C: using guessed type int (__thiscall *AnimPartChange::vftable)(void *, char);
// 7C8830: using guessed type int (__thiscall *ReplaceObjectHook::vftable)(void *, char);

//----- (005270F0) --------------------------------------------------------  // acclient.c:342657
int ReplaceObjectHook::GetType()
{
  return 5;
}

//----- (00527100) --------------------------------------------------------  // acclient.c:342663
ReplaceObjectHook *__thiscall ReplaceObjectHook::scalar_deleting_destructor(ReplaceObjectHook *this, unsigned int a2)
{
  ReplaceObjectHook *v2; // esi@1

  v2 = this;
  this->ap_change.vfptr = (PackObjVtbl *)&PackObj::vftable;
  this->vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
  if ( a2 & 1 )
    operator delete(this);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);

//----- (00527130) --------------------------------------------------------  // acclient.c:342678
void __thiscall CreateParticleHook::CreateParticleHook(CreateParticleHook *this)
{
  CreateParticleHook *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->offset;
  v1->next_hook = 0;
  v1->direction_ = -2;
  v1->vfptr = (CAnimHookVtbl *)&CreateParticleHook::vftable;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
}
// 7C884C: using guessed type int (__thiscall *CreateParticleHook::vftable)(void *, char);

//----- (00527180) --------------------------------------------------------  // acclient.c:342706
void __thiscall CreateBlockingParticleHook::CreateBlockingParticleHook(CreateBlockingParticleHook *this)
{
  CreateBlockingParticleHook *v1; // esi@1
  char *v2; // ecx@1

  v1 = this;
  v2 = (char *)&this->offset;
  v1->next_hook = 0;
  v1->direction_ = -2;
  v1->vfptr = (CAnimHookVtbl *)&CreateParticleHook::vftable;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v1->vfptr = (CAnimHookVtbl *)&CreateBlockingParticleHook::vftable;
}
// 7C884C: using guessed type int (__thiscall *CreateParticleHook::vftable)(void *, char);
// 7C8868: using guessed type int (__thiscall *CreateBlockingParticleHook::vftable)(void *, char);

//----- (005271C0) --------------------------------------------------------  // acclient.c:342730
int CallPESHook::GetType()
{
  return 19;
}

//----- (005271D0) --------------------------------------------------------  // acclient.c:342736
CAnimHook *__cdecl CAnimHook::UnPackHook(void **addr, unsigned int size)
{
  int v2; // ecx@1
  char *v3; // eax@1
  int v4; // ebp@1
  void *v5; // esi@1
  void *v6; // eax@2
  unsigned int v7; // ST04_4@3
  void *v8; // eax@5
  void *v9; // eax@7
  void *v10; // eax@9
  SoundHook *v11; // eax@11
  void *v12; // eax@12
  void *v13; // eax@13
  ReplaceObjectHook *v14; // eax@15
  void *v15; // eax@16
  void *v16; // eax@17
  void *v17; // eax@19
  void *v18; // eax@21
  void *v19; // eax@23
  void *v20; // eax@25
  void *v21; // eax@27
  void *v22; // eax@29
  CreateParticleHook *v23; // eax@31
  void *v24; // eax@32
  CreateBlockingParticleHook *v25; // eax@33
  void *v26; // eax@34
  void *v27; // eax@35
  void *v28; // eax@37
  void *v29; // eax@39
  SoundTweakedHook *v30; // eax@41
  void *v31; // eax@42
  void *v32; // eax@43
  TextureVelocityHook *v33; // eax@45
  void *v34; // eax@46
  TextureVelocityPartHook *v35; // eax@47
  void *v36; // eax@48
  void *v37; // eax@49
  AttackHook *v38; // eax@51
  void *v39; // eax@52
  void *v40; // eax@53

  v2 = *(_DWORD *)*addr;
  v3 = (char *)*addr + 4;
  *addr = v3;
  v4 = *(_DWORD *)v3;
  v5 = 0;
  *addr = v3 + 4;
  switch ( v2 )
  {
    case 0:
      v6 = operator new(0xCu);
      if ( v6 )
      {
        v5 = v6;
        v7 = size;
        *((_DWORD *)v6 + 1) = 0;
        *((_DWORD *)v6 + 2) = -2;
        *(_DWORD *)v6 = &NOOPHook::vftable;
        (*(void (__thiscall **)(void *, void **, unsigned int))(*(_DWORD *)v6 + 24))(v6, addr, v7);
      }
      else
      {
        v5 = 0;
        (*(void (__thiscall **)(_DWORD, void **, unsigned int))(v0 + 24))(0, addr, size);
      }
      goto LABEL_57;
    case 16:
      v8 = operator new(0x10u);
      if ( !v8 )
        goto LABEL_55;
      *((_DWORD *)v8 + 1) = 0;
      *((_DWORD *)v8 + 2) = -2;
      *(_DWORD *)v8 = &NoDrawHook::vftable;
      v5 = v8;
      goto LABEL_56;
    case 17:
      v9 = operator new(0xCu);
      if ( !v9 )
        goto LABEL_55;
      *((_DWORD *)v9 + 1) = 0;
      *((_DWORD *)v9 + 2) = -2;
      *(_DWORD *)v9 = &DefaultScriptHook::vftable;
      v5 = v9;
      goto LABEL_56;
    case 18:
      v10 = operator new(0x10u);
      if ( !v10 )
        goto LABEL_55;
      *((_DWORD *)v10 + 1) = 0;
      *((_DWORD *)v10 + 2) = -2;
      *(_DWORD *)v10 = &DefaultScriptPartHook::vftable;
      v5 = v10;
      goto LABEL_56;
    case 1:
      v11 = (SoundHook *)operator new(0x10u);
      if ( !v11 )
        goto LABEL_55;
      SoundHook::SoundHook(v11);
      v5 = v12;
      goto LABEL_56;
    case 2:
      v13 = operator new(0x10u);
      if ( !v13 )
        goto LABEL_55;
      *((_DWORD *)v13 + 1) = 0;
      *((_DWORD *)v13 + 2) = -2;
      *(_DWORD *)v13 = &SoundTableHook::vftable;
      *((_DWORD *)v13 + 3) = 0;
      v5 = v13;
      goto LABEL_56;
    case 5:
      v14 = (ReplaceObjectHook *)operator new(0x20u);
      if ( !v14 )
        goto LABEL_55;
      ReplaceObjectHook::ReplaceObjectHook(v14);
      v5 = v15;
      goto LABEL_56;
    case 20:
      v16 = operator new(0x18u);
      if ( !v16 )
        goto LABEL_55;
      *((_DWORD *)v16 + 1) = 0;
      *((_DWORD *)v16 + 2) = -2;
      *(_DWORD *)v16 = &TransparentHook::vftable;
      v5 = v16;
      goto LABEL_56;
    case 7:
      v17 = operator new(0x1Cu);
      if ( !v17 )
        goto LABEL_55;
      *((_DWORD *)v17 + 1) = 0;
      *((_DWORD *)v17 + 2) = -2;
      *(_DWORD *)v17 = &TransparentPartHook::vftable;
      v5 = v17;
      goto LABEL_56;
    case 9:
      v18 = operator new(0x1Cu);
      if ( !v18 )
        goto LABEL_55;
      *((_DWORD *)v18 + 1) = 0;
      *((_DWORD *)v18 + 2) = -2;
      *(_DWORD *)v18 = &LuminousPartHook::vftable;
      v5 = v18;
      goto LABEL_56;
    case 8:
      v19 = operator new(0x18u);
      if ( !v19 )
        goto LABEL_55;
      *((_DWORD *)v19 + 1) = 0;
      *((_DWORD *)v19 + 2) = -2;
      *(_DWORD *)v19 = &LuminousHook::vftable;
      v5 = v19;
      goto LABEL_56;
    case 11:
      v20 = operator new(0x1Cu);
      if ( !v20 )
        goto LABEL_55;
      *((_DWORD *)v20 + 1) = 0;
      *((_DWORD *)v20 + 2) = -2;
      *(_DWORD *)v20 = &DiffusePartHook::vftable;
      v5 = v20;
      goto LABEL_56;
    case 10:
      v21 = operator new(0x18u);
      if ( !v21 )
        goto LABEL_55;
      *((_DWORD *)v21 + 1) = 0;
      *((_DWORD *)v21 + 2) = -2;
      *(_DWORD *)v21 = &DiffuseHook::vftable;
      v5 = v21;
      goto LABEL_56;
    case 12:
      v22 = operator new(0x14u);
      if ( !v22 )
        goto LABEL_55;
      *((_DWORD *)v22 + 1) = 0;
      *((_DWORD *)v22 + 2) = -2;
      *(_DWORD *)v22 = &ScaleHook::vftable;
      v5 = v22;
      goto LABEL_56;
    case 13:
      v23 = (CreateParticleHook *)operator new(0x58u);
      if ( !v23 )
        goto LABEL_55;
      CreateParticleHook::CreateParticleHook(v23);
      v5 = v24;
      goto LABEL_56;
    case 26:
      v25 = (CreateBlockingParticleHook *)operator new(0x58u);
      if ( !v25 )
        goto LABEL_55;
      CreateBlockingParticleHook::CreateBlockingParticleHook(v25);
      v5 = v26;
      goto LABEL_56;
    case 14:
      v27 = operator new(0x10u);
      if ( !v27 )
        goto LABEL_55;
      *((_DWORD *)v27 + 1) = 0;
      *((_DWORD *)v27 + 2) = -2;
      *(_DWORD *)v27 = &DestroyParticleHook::vftable;
      v5 = v27;
      goto LABEL_56;
    case 15:
      v28 = operator new(0x10u);
      if ( !v28 )
        goto LABEL_55;
      *((_DWORD *)v28 + 1) = 0;
      *((_DWORD *)v28 + 2) = -2;
      *(_DWORD *)v28 = &StopParticleHook::vftable;
      v5 = v28;
      goto LABEL_56;
    case 19:
      v29 = operator new(0x14u);
      if ( !v29 )
        goto LABEL_55;
      *((_DWORD *)v29 + 1) = 0;
      *((_DWORD *)v29 + 2) = -2;
      *(_DWORD *)v29 = &CallPESHook::vftable;
      v5 = v29;
      goto LABEL_56;
    case 21:
      v30 = (SoundTweakedHook *)operator new(0x1Cu);
      if ( !v30 )
        goto LABEL_55;
      SoundTweakedHook::SoundTweakedHook(v30);
      v5 = v31;
      goto LABEL_56;
    case 22:
      v32 = operator new(0x18u);
      if ( !v32 )
        goto LABEL_55;
      *((_DWORD *)v32 + 1) = 0;
      *((_DWORD *)v32 + 2) = -2;
      *(_DWORD *)v32 = &SetOmegaHook::vftable;
      v5 = v32;
      goto LABEL_56;
    case 23:
      v33 = (TextureVelocityHook *)operator new(0x14u);
      if ( !v33 )
        goto LABEL_55;
      TextureVelocityHook::TextureVelocityHook(v33);
      v5 = v34;
      goto LABEL_56;
    case 24:
      v35 = (TextureVelocityPartHook *)operator new(0x18u);
      if ( !v35 )
        goto LABEL_55;
      TextureVelocityPartHook::TextureVelocityPartHook(v35);
      v5 = v36;
      goto LABEL_56;
    case 25:
      v37 = operator new(0x10u);
      if ( !v37 )
        goto LABEL_55;
      *((_DWORD *)v37 + 1) = 0;
      *((_DWORD *)v37 + 2) = -2;
      *(_DWORD *)v37 = &SetLightHook::vftable;
      v5 = v37;
      goto LABEL_56;
    case 3:
      v38 = (AttackHook *)operator new(0x28u);
      if ( !v38 )
        goto LABEL_55;
      AttackHook::AttackHook(v38);
      v5 = v39;
      goto LABEL_56;
    case 6:
      v40 = operator new(0x10u);
      if ( v40 )
      {
        *((_DWORD *)v40 + 1) = 0;
        *((_DWORD *)v40 + 2) = -2;
        *(_DWORD *)v40 = &EtherealHook::vftable;
        v5 = v40;
      }
      else
      {
LABEL_55:
        v5 = 0;
      }
LABEL_56:
      (*(void (__thiscall **)(void *, void **, unsigned int))(*(_DWORD *)v5 + 24))(v5, addr, size);
LABEL_57:
      *((_DWORD *)v5 + 2) = v4;
      break;
    default:
      break;
  }
  PackObj::ALIGN_PTR(addr, &size);
  return (CAnimHook *)v5;
}
// 7C85D0: using guessed type int (__thiscall *NOOPHook::vftable)(void *, char);
// 7C8608: using guessed type int (__thiscall *EtherealHook::vftable)(void *, char);
// 7C8624: using guessed type int (__thiscall *NoDrawHook::vftable)(void *, char);
// 7C8640: using guessed type int (__thiscall *DefaultScriptPartHook::vftable)(void *, char);
// 7C865C: using guessed type int (__thiscall *DefaultScriptHook::vftable)(void *, char);
// 7C8678: using guessed type int (__thiscall *TransparentHook::vftable)(void *, char);
// 7C8694: using guessed type int (__thiscall *TransparentPartHook::vftable)(void *, char);
// 7C86B0: using guessed type int (__thiscall *LuminousPartHook::vftable)(void *, char);
// 7C86CC: using guessed type int (__thiscall *LuminousHook::vftable)(void *, char);
// 7C86E8: using guessed type int (__thiscall *DiffusePartHook::vftable)(void *, char);
// 7C8704: using guessed type int (__thiscall *DiffuseHook::vftable)(void *, char);
// 7C8720: using guessed type int (__thiscall *ScaleHook::vftable)(void *, char);
// 7C873C: using guessed type int (__thiscall *DestroyParticleHook::vftable)(void *, char);
// 7C8758: using guessed type int (__thiscall *StopParticleHook::vftable)(void *, char);
// 7C87AC: using guessed type int (__thiscall *SetLightHook::vftable)(void *, char);
// 7C8800: using guessed type int (__thiscall *SoundTableHook::vftable)(void *, char);
// 7C8884: using guessed type int (__thiscall *CallPESHook::vftable)(void *, char);
// 7C88A0: using guessed type int (__thiscall *SetOmegaHook::vftable)(void *, char);

//----- (00527680) --------------------------------------------------------  // acclient.c:343049
SoundHook *__thiscall SoundHook::scalar_deleting_destructor(SoundHook *this, unsigned int a2)
{
  SoundHook *v2; // esi@1
  unsigned int v3; // ST00_4@1

  v2 = this;
  v3 = this->gid_.id;
  this->vfptr = (CAnimHookVtbl *)&SoundHook::vftable;
  SoundManager::DestroySound((IDClass<_tagDataID,32,0>)v3);
  v2->vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);
// 7C87C8: using guessed type int (__thiscall *SoundHook::vftable)(void *, char);

//----- (005276C0) --------------------------------------------------------  // acclient.c:343067
int __thiscall SoundHook::UnPack(SoundHook *this, void **addr, unsigned int size)
{
  unsigned int v3; // edx@1

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  this->gid_.id = v3;
  SoundManager::CreateSound((IDClass<_tagDataID,32,0>)v3);
  return 1;
}

//----- (005276F0) --------------------------------------------------------  // acclient.c:343079
SoundTweakedHook *__thiscall SoundTweakedHook::scalar_deleting_destructor(SoundTweakedHook *this, unsigned int a2)
{
  SoundTweakedHook *v2; // esi@1
  unsigned int v3; // ST00_4@1

  v2 = this;
  v3 = this->gid_.id;
  this->vfptr = (CAnimHookVtbl *)&SoundTweakedHook::vftable;
  SoundManager::DestroySound((IDClass<_tagDataID,32,0>)v3);
  v2->vfptr = (CAnimHookVtbl *)&CAnimHook::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7C84A0: using guessed type int (__thiscall *CAnimHook::vftable)(void *, char);
// 7C87E4: using guessed type int (__thiscall *SoundTweakedHook::vftable)(void *, char);

//----- (00527730) --------------------------------------------------------  // acclient.c:343097
int __thiscall SoundTweakedHook::Pack(SoundTweakedHook *this, void **addr, unsigned int size)
{
  SoundTweakedHook *v3; // esi@1
  int result; // eax@1
  char *v5; // edi@1
  char *v6; // edx@1
  char *v7; // edi@1

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  *(_DWORD *)*addr = v3->gid_.id;
  v5 = (char *)*addr + 4;
  *addr = v5;
  *(float *)v5 = v3->prob;
  v6 = (char *)*addr + 4;
  *addr = v6;
  *(float *)v6 = v3->prio;
  v7 = (char *)*addr + 4;
  *addr = v7;
  *(float *)v7 = v3->vol;
  *addr = (char *)*addr + 4;
  return result;
}

//----- (00527780) --------------------------------------------------------  // acclient.c:343122
int __thiscall SoundTweakedHook::UnPack(SoundTweakedHook *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  char *v4; // edx@1
  char *v5; // esi@1

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  this->gid_.id = v3;
  LODWORD(this->prob) = *(_DWORD *)*addr;
  v4 = (char *)*addr + 4;
  *addr = v4;
  LODWORD(this->prio) = *(_DWORD *)v4;
  v5 = (char *)*addr + 4;
  *addr = v5;
  LODWORD(this->vol) = *(_DWORD *)v5;
  *addr = (char *)*addr + 4;
  SoundManager::CreateSound(this->gid_);
  return 1;
}

//----- (005277D0) --------------------------------------------------------  // acclient.c:343144
unsigned int __thiscall AttackHook::Pack(AttackHook *this, void **addr, unsigned int size)
{
  return AttackCone::Pack(&this->attack_cone, addr, size);
}

//----- (005277E0) --------------------------------------------------------  // acclient.c:343150
int __thiscall AttackHook::UnPack(AttackHook *this, void **addr, unsigned int size)
{
  return AttackCone::UnPack(&this->attack_cone, addr, size);
}

//----- (005277F0) --------------------------------------------------------  // acclient.c:343156
unsigned int __thiscall CallPESHook::Pack(CallPESHook *this, void **addr, unsigned int size)
{
  CallPESHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edi@2

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3->pes.id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->pause;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00527820) --------------------------------------------------------  // acclient.c:343176
int __thiscall CallPESHook::UnPack(CallPESHook *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1

  v3 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  this->pes.id = v3;
  LODWORD(this->pause) = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (00527850) --------------------------------------------------------  // acclient.c:343189
unsigned int __thiscall CreateParticleHook::Pack(CreateParticleHook *this, void **addr, unsigned int size)
{
  CreateParticleHook *v3; // edi@1
  unsigned int v4; // ebx@1
  char *v5; // edx@2

  v3 = this;
  v4 = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= v4 )
  {
    *(_DWORD *)*addr = v3->emitter_info_id.id;
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(_DWORD *)v5 = v3->part_index;
    *addr = (char *)*addr + 4;
    Frame::Pack(&v3->offset, addr, size);
    *(_DWORD *)*addr = v3->emitter_id;
    *addr = (char *)*addr + 4;
  }
  return v4;
}

//----- (005278A0) --------------------------------------------------------  // acclient.c:343212
int __thiscall CreateParticleHook::UnPack(CreateParticleHook *this, void **addr, unsigned int size)
{
  CreateParticleHook *v3; // edi@1
  unsigned int v4; // ecx@1

  v3 = this;
  v4 = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  v3->emitter_info_id.id = v4;
  v3->part_index = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  Frame::UnPack(&v3->offset, addr, size);
  v3->emitter_id = *(_DWORD *)*addr;
  *addr = (char *)*addr + 4;
  return 1;
}

//----- (005278F0) --------------------------------------------------------  // acclient.c:343230
unsigned int __thiscall SetOmegaHook::Pack(SetOmegaHook *this, void **addr, unsigned int size)
{
  SetOmegaHook *v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // edx@3
  char *v6; // edi@3

  v3 = this;
  result = ((int (*)(void))this->vfptr->pack_size)();
  if ( size >= result && size >= 0xC )
  {
    *(_DWORD *)*addr = LODWORD(v3->axis.x);
    v5 = (char *)*addr + 4;
    *addr = v5;
    *(float *)v5 = v3->axis.y;
    v6 = (char *)*addr + 4;
    *addr = v6;
    *(float *)v6 = v3->axis.z;
    *addr = (char *)*addr + 4;
  }
  return result;
}

//----- (00527940) --------------------------------------------------------  // acclient.c:343254
int __thiscall SetOmegaHook::UnPack(SetOmegaHook *this, void **addr, unsigned int size)
{
  char *v3; // edx@2
  char *v4; // edx@2

  if ( size >= 0xC )
  {
    LODWORD(this->axis.x) = *(_DWORD *)*addr;
    v3 = (char *)*addr + 4;
    *addr = v3;
    LODWORD(this->axis.y) = *(_DWORD *)v3;
    v4 = (char *)*addr + 4;
    *addr = v4;
    LODWORD(this->axis.z) = *(_DWORD *)v4;
    *addr = (char *)*addr + 4;
  }
  return 1;
}

//----- (00527980) --------------------------------------------------------  // acclient.c:343274
void __thiscall ReplaceObjectHook::GetSubDataIDs(ReplaceObjectHook *this, QualifiedDataIDArray *id_array)
{
  QualifiedDataID *v2; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, this->ap_change.part_id, 0);
  QualifiedDataIDArray::AddQDID(id_array, v2, 0);
}

//----- (005279B0) --------------------------------------------------------  // acclient.c:343284
void __thiscall CreateParticleHook::GetSubDataIDs(CallPESHook *this, QualifiedDataIDArray *id_array)
{
  QualifiedDataID *v2; // eax@1
  QualifiedDataID v3; // [sp+0h] [bp-8h]@1

  QualifiedDataID::QualifiedDataID(&v3, this->pes, 0);
  QualifiedDataIDArray::AddQDID(id_array, v2, 0);
}

//----- (0067F670) --------------------------------------------------------  // acclient.c:662530
int MenuDialog::GetUIElementType()
{
  return 22;
}

//----- (00682760) --------------------------------------------------------  // acclient.c:665892
int TransparentHook::GetType()
{
  return 20;
}

//----- (006B0A90) --------------------------------------------------------  // acclient.c:713841
signed int UIElement_Text::GetUIElementType()
{
  return 12;
}

//----- (006FD870) --------------------------------------------------------  // acclient.c:785802
int sub_6FD870()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_13;
  INITIAL_MAX_DATA_RATE_82 = LOWEST_DATA_RATE_13;
  return result;
}

//----- (006FD880) --------------------------------------------------------  // acclient.c:785812
void sub_6FD880()
{
  flt_8445CC = 1000.0 + 1.0;
}

//----- (006FD8A0) --------------------------------------------------------  // acclient.c:785818
void _E99_24()
{
  flt_8445D0 = 24.0 * 8.0;
}

//----- (006FD8C0) --------------------------------------------------------  // acclient.c:785824
void _E101_22()
{
  flt_8445D4 = 24.0 * 0.5;
}

//----- (006FD8E0) --------------------------------------------------------  // acclient.c:785830
void sub_6FD8E0()
{
  flt_8445D8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006FD900) --------------------------------------------------------  // acclient.c:785836
void _E105_28()
{
  dbl_8445E0 = 1.0 / 30.0;
}

//----- (006FD920) --------------------------------------------------------  // acclient.c:785842
void _E107_22()
{
  dbl_8445E8 = 1.0 / 5.0;
}

//----- (006FD940) --------------------------------------------------------  // acclient.c:785848
int _E109_64()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundDisabled_14, "Sound.SoundDisabled");
  return atexit(sub_768260);
}

//----- (006FD960) --------------------------------------------------------  // acclient.c:785855
int _E112_87()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundVolume_14, "Sound.SoundVolume");
  return atexit(_E113_64);
}

//----- (006FD980) --------------------------------------------------------  // acclient.c:785862
int _E115_65()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundDisabled_14, "Sound.AmbientSoundDisabled");
  return atexit(_E116_56);
}

//----- (006FD9A0) --------------------------------------------------------  // acclient.c:785869
int _E118_65()
{
  PStringBase<char>::PStringBase<char>(&Sound_AmbientSoundVolume_14, "Sound.AmbientSoundVolume");
  return atexit(_E119_84);
}

//----- (006FD9C0) --------------------------------------------------------  // acclient.c:785876
int _E121_58()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundDisabled_14, "Sound.InterfaceSoundDisabled");
  return atexit(_E122_86);
}

//----- (006FD9E0) --------------------------------------------------------  // acclient.c:785883
int _E124_60()
{
  PStringBase<char>::PStringBase<char>(&Sound_InterfaceSoundVolume_14, "Sound.InterfaceSoundVolume");
  return atexit(_E125_58);
}

//----- (006FDA00) --------------------------------------------------------  // acclient.c:785890
int _E127_48()
{
  PStringBase<char>::PStringBase<char>(&Sound_SoundFeatures_14, "Sound.SoundFeatures");
  return atexit(_E128_57);
}

//----- (006FDA20) --------------------------------------------------------  // acclient.c:785897
int _E130_47()
{
  PStringBase<char>::PStringBase<char>(&Sound_PlaySoundOnlyWhenActive_14, "Sound.PlaySoundOnlyWhenActive");
  return atexit(_E131_49);
}

//----- (006FDA40) --------------------------------------------------------  // acclient.c:785904
int _E133_36()
{
  PStringBase<char>::PStringBase<char>(Sound_SoundFeatures_Choices_14, "Stereo");
  PStringBase<char>::PStringBase<char>(&stru_844614, "Mono");
  return atexit(_E134_34);
}

//----- (006FDA70) --------------------------------------------------------  // acclient.c:785912
int _E136_26()
{
  return atexit(_E137_33);
}

//----- (006FDA80) --------------------------------------------------------  // acclient.c:785918
int _E139_25()
{
  return atexit(_E140_28);
}

//----- (006FDA90) --------------------------------------------------------  // acclient.c:785924
int _E142_24()
{
  return atexit(_E143_28);
}

//----- (006FDAA0) --------------------------------------------------------  // acclient.c:785930
void _E145_25()
{
  VOL_MIN_DIST_SQ_11 = 5.0 * 5.0;
}

//----- (006FDAC0) --------------------------------------------------------  // acclient.c:785936
void _E147_22()
{
  INV_LOG_OF_2_11 = 1.0 / __FYL2X__(2.0, 0.69314718055994528623);
}

//----- (006FDAE0) --------------------------------------------------------  // acclient.c:785942
int sub_6FDAE0()
{
  return atexit(nullsub_1128);
}

//----- (00768260) --------------------------------------------------------  // acclient.c:894972
void __cdecl sub_768260()
{
  char *v0; // esi@1

  v0 = &Sound_SoundDisabled_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundDisabled_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768290) --------------------------------------------------------  // acclient.c:894985
void __cdecl _E113_64()
{
  char *v0; // esi@1

  v0 = &Sound_SoundVolume_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundVolume_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007682C0) --------------------------------------------------------  // acclient.c:894998
void __cdecl _E116_56()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundDisabled_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundDisabled_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007682F0) --------------------------------------------------------  // acclient.c:895011
void __cdecl _E119_84()
{
  char *v0; // esi@1

  v0 = &Sound_AmbientSoundVolume_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_AmbientSoundVolume_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768320) --------------------------------------------------------  // acclient.c:895024
void __cdecl _E122_86()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundDisabled_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundDisabled_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768350) --------------------------------------------------------  // acclient.c:895037
void __cdecl _E125_58()
{
  char *v0; // esi@1

  v0 = &Sound_InterfaceSoundVolume_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_InterfaceSoundVolume_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00768380) --------------------------------------------------------  // acclient.c:895050
void __cdecl _E128_57()
{
  char *v0; // esi@1

  v0 = &Sound_SoundFeatures_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_SoundFeatures_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007683B0) --------------------------------------------------------  // acclient.c:895063
void __cdecl _E131_49()
{
  char *v0; // esi@1

  v0 = &Sound_PlaySoundOnlyWhenActive_14.m_charbuffer[-2].m_data[12];
  if ( !InterlockedDecrement((volatile LONG *)&Sound_PlaySoundOnlyWhenActive_14.m_charbuffer[-1]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007683E0) --------------------------------------------------------  // acclient.c:895076
void __cdecl _E134_34()
{
  const float *v0; // edi@1
  signed int v1; // ebp@1
  int v2; // esi@2
  int v3; // esi@2

  v0 = &VOL_MIN_DIST_SQ_11;
  v1 = 2;
  do
  {
    v2 = *((_DWORD *)v0 - 1);
    --v0;
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

