/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : gmMiniGameUI
   Object     : GAME\game_ui_misc\gmMiniGameUI.obj
   Functions  : 89
   Addresses  : 004A7B20 - 006F1560 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (004A7B20) --------------------------------------------------------  // acclient.c:223306
BOOL __thiscall TCoord::operator!=(TCoord *this, TCoord *A)
{
  return this->x != A->x || this->y != A->y;
}

//----- (004A7B40) --------------------------------------------------------  // acclient.c:223312
int __thiscall TCoord::IsValid(TCoord *this)
{
  int v1; // eax@1
  int v2; // ecx@2
  int result; // eax@5

  v1 = this->x;
  result = 0;
  if ( this->x >= 0 )
  {
    v2 = this->y;
    if ( v2 >= 0 && v1 < 8 && v2 < 8 )
      result = 1;
  }
  return result;
}

//----- (004A7B60) --------------------------------------------------------  // acclient.c:223330
void __thiscall GameBoardGrid::PrepareNewMove(GameBoardGrid *this)
{
  char *v1; // eax@1
  signed int v2; // ecx@1

  v1 = (char *)this->m_rgPreviousBoard;
  v2 = 8;
  do
  {
    *(_DWORD *)v1 = *((_DWORD *)v1 - 90);
    *((_DWORD *)v1 + 1) = *((_DWORD *)v1 - 89);
    *((_DWORD *)v1 + 2) = *((_DWORD *)v1 - 88);
    *((_DWORD *)v1 + 3) = *((_DWORD *)v1 - 87);
    *((_DWORD *)v1 + 4) = *((_DWORD *)v1 - 86);
    *((_DWORD *)v1 + 5) = *((_DWORD *)v1 - 85);
    *((_DWORD *)v1 + 6) = *((_DWORD *)v1 - 84);
    *((_DWORD *)v1 + 7) = *((_DWORD *)v1 - 83);
    v1 += 32;
    --v2;
  }
  while ( v2 );
}

//----- (004A7BC0) --------------------------------------------------------  // acclient.c:223354
void __userpurge gmMiniGameUI::gmMiniGameUI(gmMiniGameUI *this@<ecx>, int a2@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMiniGameUI *v4; // esi@1

  v4 = this;
  UIElement_Field::UIElement_Field((UIElement_Field *)&this->vfptr, a2, _layout, _full_desc);
  v4->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v4->m_pResignButton = 0;
  v4->m_pPassButton = 0;
  v4->m_pStalemateButton = 0;
  v4->m_idCurrentGame = 0;
  v4->m_state = 0;
  v4->m_fStalemate = 0;
  v4->m_pGameBoard = 0;
  v4->m_uiResignDialogContext = 0;
  v4->vfptr = (IInputActionCallbackVtbl *)&gmMiniGameUI::vftable;
  v4->vfptr = (NoticeHandlerVtbl *)&gmMiniGameUI::vftable;
  v4->m_iTeam = -1;
}
// 7ADCC0: using guessed type bool (__thiscall *gmMiniGameUI::vftable)(DBCache *this);
// 7ADF68: using guessed type int (__thiscall *gmMiniGameUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7C30) --------------------------------------------------------  // acclient.c:223378
gmMiniGameUI *__thiscall gmMiniGameUI::DynamicCast(gmMiniGameUI *this, unsigned int i_eType)
{
  gmMiniGameUI *result; // eax@1

  result = this;
  if ( i_eType != 268435486 )
    result = (gmMiniGameUI *)(i_eType != 3 ? 0 : (unsigned int)this);
  return result;
}

//----- (004A7C50) --------------------------------------------------------  // acclient.c:223389
signed int gmMiniGameUI::GetUIElementType()
{
  return 268435486;
}

//----- (004A7C60) --------------------------------------------------------  // acclient.c:223395
void __thiscall gmMiniGameUI::~gmMiniGameUI(gmMiniGameUI *this)
{
  gmMiniGameUI *v1; // esi@1
  GameBoardGrid *v2; // ecx@1
  GlobalEventHandler *v3; // eax@3

  v1 = this;
  v2 = this->m_pGameBoard;
  v1->vfptr = (IInputActionCallbackVtbl *)&gmMiniGameUI::vftable;
  v1->vfptr = (NoticeHandlerVtbl *)&gmMiniGameUI::vftable;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v1->m_pGameBoard = 0;
  v3 = GlobalEventHandler::GetGlobalEventHandler();
  if ( v3 )
    v3->vfptr->UnRegisterAllNoticeHandlers((NoticeRegistrar *)v3, (NoticeHandler *)&v1->vfptr);
  v1->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler((NoticeHandler *)&v1->vfptr);
  UIElement_Field::~UIElement_Field((UIElement_Field *)&v1->vfptr);
}
// 7ADCC0: using guessed type bool (__thiscall *gmMiniGameUI::vftable)(DBCache *this);
// 7ADF68: using guessed type int (__thiscall *gmMiniGameUI::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);

//----- (004A7CC0) --------------------------------------------------------  // acclient.c:223420
void __usercall gmMiniGameUI::Create(int a1@<edi>, LayoutDesc *_layout, ElementDesc *_full_desc)
{
  gmMiniGameUI *v3; // eax@1

  v3 = (gmMiniGameUI *)operator new(0x620u);
  if ( v3 )
    gmMiniGameUI::gmMiniGameUI(v3, a1, _layout, _full_desc);
}

//----- (004A7CF0) --------------------------------------------------------  // acclient.c:223430
void __thiscall gmMiniGameUI::RecvNotice_EndGame(gmMiniGameUI *this)
{
  ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7][3].m_hashKey)(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7],
    0);
}

//----- (004A7D10) --------------------------------------------------------  // acclient.c:223438
char __thiscall gmMiniGameUI::DoMove(gmMiniGameUI *this, int x0, int y0, int x1, int y1)
{
  gmMiniGameUI *v5; // esi@1

  v5 = this;
  CM_Game::Event_Move(x0, y0, x1, y1);
  v5->m_state = 4;
  return 1;
}

//----- (004A7D40) --------------------------------------------------------  // acclient.c:223449
void __thiscall GameBoardGrid::Draw(GameBoardGrid *this)
{
  GameBoardGrid *v1; // edi@1
  signed int v2; // ebp@1
  signed int v3; // ebx@2
  unsigned int v4; // eax@2
  UIElement *v5; // esi@6
  TChessPiece<CBasePiece> *v6; // eax@7
  UIElement *v7; // ecx@10
  signed int v8; // eax@12
  signed int v9; // edx@13
  int i; // [sp+10h] [bp-4h]@2

  v1 = this;
  v2 = 0;
  do
  {
    v3 = 0;
    v4 = 7 - v2;
    for ( i = 7 - v2; ; v4 = i )
    {
      if ( !v1->m_gameUI->m_iTeam )
        v4 = v2 + 8 * (7 - v3);
      v5 = UIElement_ListBox::GetItem(v1->m_pieceListBox, v4);
      if ( v5 )
      {
        v6 = v1->m_Board[0][v3 + 8 * v2];
        if ( v6 )
        {
          UIElement::SetMediaImage(v5, v6->m_didIcon, 3u);
          v5->vfptr[2].__vecDelDtor((IInputActionCallback *)v5, 1u);
        }
        else
        {
          v5->vfptr[2].__vecDelDtor((IInputActionCallback *)v5, 0);
        }
        v7 = UIElement::GetChildRecursive(v5, 0x10000179u);
        if ( v7 )
        {
          if ( v1->m_coordSelected.x != v2
            || (v8 = v1->m_coordSelected.y, v8 != v3)
            || (v9 = v1->m_coordSelected.x, v9 < 0)
            || v8 < 0
            || v9 >= 8
            || v8 >= 8 )
            ((void (__stdcall *)(_DWORD))v7->vfptr[2].__vecDelDtor)(0);
          else
            ((void (__stdcall *)(signed int))v7->vfptr[2].__vecDelDtor)(1);
        }
      }
      ++v3;
      i += 8;
      if ( v3 >= 8 )
        break;
    }
    ++v2;
  }
  while ( v2 < 8 );
}

//----- (004A7E40) --------------------------------------------------------  // acclient.c:223510
int __thiscall TChessPiece<CBasePiece>::bCanAttack(TChessPiece<CBasePiece> *this, int dx, int dy)
{
  return ((int (__stdcall *)(int, int))this->vfptr->bCanGoTo)(dx, dy);
}

//----- (004A7E50) --------------------------------------------------------  // acclient.c:223516
int __thiscall TChessPiece<CBasePiece>::UnPack(TChessPiece<CBasePiece> *this, void **addr, unsigned int size)
{
  TChessPiece<CBasePiece> *v3; // ebx@1
  int v4; // ecx@2
  char *v5; // eax@2
  char *v6; // eax@4
  int result; // eax@7

  v3 = this;
  result = 0;
  if ( size >= 4 )
  {
    v4 = *(_DWORD *)*addr;
    v5 = (char *)*addr + 4;
    *addr = v5;
    if ( v4 == v3->m_Type && size - 4 >= 4 )
    {
      v3->m_Player = *(_DWORD *)v5;
      v6 = (char *)*addr + 4;
      *addr = v6;
      if ( size - 8 >= 4 )
      {
        v3->m_bMoved = *(_DWORD *)v6;
        *addr = (char *)*addr + 4;
        if ( TCoord::UnPack(&v3->m_CurPos, addr, size - 12) )
        {
          if ( TCoord::UnPack(&v3->m_LastKnownGoodPos, addr, size - 12) )
            result = 1;
        }
      }
    }
  }
  return result;
}

//----- (004A7ED0) --------------------------------------------------------  // acclient.c:223552
int __thiscall TCoord::UnPack(TCoord *this, void **addr, unsigned int size)
{
  int *v3; // esi@2
  int result; // eax@3

  if ( size < 4 || (this->x = *(_DWORD *)*addr, v3 = (int *)((char *)*addr + 4), *addr = v3, size - 4 < 4) )
  {
    result = 0;
  }
  else
  {
    this->y = *v3;
    *addr = (char *)*addr + 4;
    result = 1;
  }
  return result;
}

//----- (004A7F10) --------------------------------------------------------  // acclient.c:223571
int __thiscall CChessLogic<CBasePiece>::SanityCheckBoard(CChessLogic<CBasePiece> *this)
{
  TChessPiece<CBasePiece> *v1; // edx@3
  TChessPiece<CBasePiece> *v2; // eax@4
  int result; // eax@7

  result = 0;
  if ( this->m_Pieces[0].m_num )
  {
    if ( this->m_Pieces[1].m_num )
    {
      v1 = *this->m_Pieces[0].m_data;
      if ( v1 )
      {
        v2 = *this->m_Pieces[1].m_data;
        if ( v2 )
        {
          if ( v1->m_Type == 6 && v2->m_Type == 6 )
            result = 1;
        }
      }
    }
  }
  return result;
}

//----- (004A7F60) --------------------------------------------------------  // acclient.c:223598
int __stdcall CChessLogic<CBasePiece>::ConvertMoveToVector(TCoord *From, TCoord *To, DirectionNumber *Dir, int *Dist)
{
  int v5; // edi@1
  signed int v6; // ecx@1
  signed int v7; // esi@1
  int *v8; // ebx@4
  int v9; // edi@4
  int v10; // eax@4
  int v12; // eax@10
  signed int v13; // edi@14
  int v14; // eax@14
  signed int v15; // ecx@14
  int v16; // ebx@14
  int v17; // eax@14
  DirectionNumber v18; // edx@14

  v5 = From->y;
  v6 = To->x - From->x;
  v7 = To->y - v5;
  if ( To->x == From->x )
  {
    if ( To->y == v5 )
      return 0;
    v12 = To->y - v5;
    goto LABEL_13;
  }
  if ( To->y == v5 || v6 == v7 )
  {
    v12 = To->x - From->x;
LABEL_13:
    v8 = Dist;
    *Dist = abs(v12);
    goto LABEL_14;
  }
  v8 = Dist;
  v9 = abs(v7);
  v10 = abs(v6);
  if ( v9 >= v10 )
    *Dist = v10;
  else
    *Dist = v9;
  if ( v6 % *Dist || v7 % *Dist )
    return 0;
LABEL_14:
  v13 = *v8;
  v14 = v6 / *v8;
  v15 = (signed int)&unk_822BC4;
  v16 = v14;
  v17 = v7 / v13;
  v18 = 0;
  do
  {
    if ( *(_DWORD *)(v15 - 12) == v16 && *(_DWORD *)(v15 - 8) == v17 )
      *Dir = v18;
    if ( *(_DWORD *)(v15 - 4) == v16 && *(_DWORD *)v15 == v17 )
      *Dir = v18 + 1;
    if ( *(_DWORD *)(v15 + 4) == v16 && *(_DWORD *)(v15 + 8) == v17 )
      *Dir = v18 + 2;
    if ( *(_DWORD *)(v15 + 12) == v16 && *(_DWORD *)(v15 + 16) == v17 )
      *Dir = v18 + 3;
    if ( *(_DWORD *)(v15 + 20) == v16 && *(_DWORD *)(v15 + 24) == v17 )
      *Dir = v18 + 4;
    if ( *(_DWORD *)(v15 + 28) == v16 && *(_DWORD *)(v15 + 32) == v17 )
      *Dir = v18 + 5;
    if ( *(_DWORD *)(v15 + 36) == v16 && *(_DWORD *)(v15 + 40) == v17 )
      *Dir = v18 + 6;
    if ( *(_DWORD *)(v15 + 44) == v16 && *(_DWORD *)(v15 + 48) == v17 )
      *Dir = v18 + 7;
    v15 += 64;
    v18 += 8;
  }
  while ( v15 < (signed int)&CombatSystem::AUGMENTATION_CRITICAL_DEFENSE_PK_AVOID_CHANCE );
  return v18 != 16;
}

//----- (004A8090) --------------------------------------------------------  // acclient.c:223674
void __thiscall GameBoardGrid::UndoMoves(GameBoardGrid *this)
{
  char *v1; // eax@1
  signed int v2; // edx@1

  v1 = (char *)this->m_Board;
  v2 = 8;
  do
  {
    *(_DWORD *)v1 = *((_DWORD *)v1 + 90);
    *((_DWORD *)v1 + 1) = *((_DWORD *)v1 + 91);
    *((_DWORD *)v1 + 2) = *((_DWORD *)v1 + 92);
    *((_DWORD *)v1 + 3) = *((_DWORD *)v1 + 93);
    *((_DWORD *)v1 + 4) = *((_DWORD *)v1 + 94);
    *((_DWORD *)v1 + 5) = *((_DWORD *)v1 + 95);
    *((_DWORD *)v1 + 6) = *((_DWORD *)v1 + 96);
    *((_DWORD *)v1 + 7) = *((_DWORD *)v1 + 97);
    v1 += 32;
    --v2;
  }
  while ( v2 );
  GameBoardGrid::Draw(this);
}

//----- (004A8100) --------------------------------------------------------  // acclient.c:223699
gmMiniGameUI *__thiscall gmMiniGameUI::scalar_deleting_destructor(gmMiniGameUI *this, unsigned int a2)
{
  gmMiniGameUI *v2; // esi@1

  v2 = this;
  gmMiniGameUI::~gmMiniGameUI(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A8120) --------------------------------------------------------  // acclient.c:223711
void __cdecl gmMiniGameUI::Register()
{
  UIElement::RegisterElementClass(
    0x1000001Eu,
    (UIElement *(__cdecl *)(LayoutDesc *, ElementDesc *))gmMiniGameUI::Create);
}

//----- (004A8140) --------------------------------------------------------  // acclient.c:223719
IDClass<_tagDataID,32,0> *__stdcall GameBoardGrid::GetPieceDID(IDClass<_tagDataID,32,0> *result, int which, BaseProperty *prop)
{
  BasePropertyValue *v4; // ecx@1
  BasePropertyDesc *v5; // eax@1
  BasePropertyValue *v6; // edx@1
  BasePropertyValue *v7; // ecx@3
  BasePropertyDesc *v8; // eax@5
  bool v9; // zf@5
  IDClass<_tagDataID,32,0> *v10; // esi@5
  int v11; // edx@6
  int v13; // edx@14
  int v14; // eax@18
  BasePropertyValue *v15; // ecx@18
  int v16; // edx@18
  BaseProperty iconProp; // [sp+10h] [bp-8h]@1

  v4 = prop->m_pcPropertyValue;
  v5 = 0;
  v6 = 0;
  iconProp.m_pcPropertyDesc = 0;
  iconProp.m_pcPropertyValue = 0;
  if ( !v4 )
    goto LABEL_13;
  if ( !(unsigned __int8)((int (__stdcall *)(int, BaseProperty *))v4->vfptr[61].__vecDelDtor)(which, &iconProp) )
  {
    v6 = iconProp.m_pcPropertyValue;
    v5 = iconProp.m_pcPropertyDesc;
LABEL_13:
    v10 = result;
    result->id = stru_83EE74.id;
    if ( v5 )
    {
      v13 = v5->m_cRef - 1;
      v5->m_cRef = v13;
      if ( !v13 )
        ((void (__stdcall *)(signed int))v5->vfptr->__vecDelDtor)(1);
      v6 = iconProp.m_pcPropertyValue;
      iconProp.m_pcPropertyDesc = 0;
    }
    if ( v6 )
    {
      v14 = (int)&v6->m_cRef;
      v15 = v6;
      v16 = v6->m_cRef - 1;
      *(_DWORD *)v14 = v16;
      if ( !v16 )
        ((void (__stdcall *)(signed int))v15->vfptr->__vecDelDtor)(1);
    }
    return v10;
  }
  prop = (BaseProperty *)stru_83EE74.id;
  v7 = iconProp.m_pcPropertyValue;
  if ( iconProp.m_pcPropertyValue )
  {
    ((void (__stdcall *)(BaseProperty **))iconProp.m_pcPropertyValue->vfptr[44].__vecDelDtor)(&prop);
    v7 = iconProp.m_pcPropertyValue;
  }
  v8 = iconProp.m_pcPropertyDesc;
  v9 = (_DWORD)iconProp.m_pcPropertyDesc == 0;
  v10 = result;
  result->id = (unsigned int)prop;
  if ( !v9 )
  {
    v11 = v8->m_cRef - 1;
    v8->m_cRef = v11;
    if ( !v11 )
      ((void (__stdcall *)(signed int))v8->vfptr->__vecDelDtor)(1);
    v7 = iconProp.m_pcPropertyValue;
    iconProp.m_pcPropertyDesc = 0;
  }
  if ( v7 )
  {
    v9 = v7->m_cRef-- == 1;
    if ( v9 )
    {
      ((void (__stdcall *)(signed int))v7->vfptr->__vecDelDtor)(1);
      return result;
    }
  }
  return v10;
}

//----- (004A8250) --------------------------------------------------------  // acclient.c:223802
void __thiscall CChessLogic<CBasePiece>::CChessLogic<CBasePiece>(CChessLogic<CBasePiece> *this)
{
  char *v1; // eax@1
  signed int v2; // esi@1

  this->vfptr = (CChessLogic<CBasePiece>Vtbl *)&CChessLogic<CBasePiece>::vftable;
  v1 = (char *)this->m_Pieces;
  v2 = 2;
  do
  {
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    v1 += 12;
    --v2;
  }
  while ( v2 );
  this->m_CurPlayer = 0;
  this->m_bLastMoveWasCheck = 0;
  this->m_EnPassantAttackSite.x = -1;
  this->m_EnPassantAttackSite.y = -1;
  this->m_EnPassantVictimPos.x = -1;
  this->m_EnPassantVictimPos.y = -1;
  memset(this->m_Board, 0, sizeof(this->m_Board));
}
// 7AE0B4: using guessed type int (__thiscall *CChessLogic<CBasePiece>::vftable)(void *, char);

//----- (004A82B0) --------------------------------------------------------  // acclient.c:223830
unsigned int __thiscall TChessPiece<CBasePiece>::Pack(TChessPiece<CBasePiece> *this, void **addr, unsigned int size)
{
  TChessPiece<CBasePiece> *v3; // esi@1
  unsigned int result; // eax@1
  unsigned int v5; // edx@1
  char *v6; // edi@3
  char *v7; // edi@4
  char *v8; // ebx@7
  char *v9; // edi@9

  v3 = this;
  result = ((int (*)(void))this->vfptr->GetPackSize)();
  v5 = size;
  if ( result <= size )
  {
    if ( size >= 4 )
    {
      *(_DWORD *)*addr = v3->m_Type;
      v6 = (char *)*addr + 4;
      v5 = size - 4;
      *addr = v6;
      if ( size - 4 >= 4 )
      {
        *(_DWORD *)v6 = v3->m_Player;
        v7 = (char *)*addr + 4;
        v5 = size - 8;
        *addr = v7;
        if ( size - 8 >= 4 )
        {
          *(_DWORD *)v7 = v3->m_bMoved;
          *addr = (char *)*addr + 4;
          v5 = size - 12;
        }
      }
    }
    if ( v5 >= 8 )
    {
      *(_DWORD *)*addr = v3->m_CurPos.x;
      v8 = (char *)*addr + 4;
      *addr = v8;
      *(_DWORD *)v8 = v3->m_CurPos.y;
      *addr = (char *)*addr + 4;
    }
    if ( v5 - 8 >= 8 )
    {
      *(_DWORD *)*addr = v3->m_LastKnownGoodPos.x;
      v9 = (char *)*addr + 4;
      *addr = v9;
      *(_DWORD *)v9 = v3->m_LastKnownGoodPos.y;
      *addr = (char *)*addr + 4;
    }
  }
  return result;
}

//----- (004A8350) --------------------------------------------------------  // acclient.c:223886
void __thiscall TPawnPiece<CBasePiece>::TPawnPiece<CBasePiece>(TPawnPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 1;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TPawnPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE0C0: using guessed type int (__stdcall *TPawnPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A83A0) --------------------------------------------------------  // acclient.c:223901
BOOL __thiscall TPawnPiece<CBasePiece>::bCanGoTo(TPawnPiece<CBasePiece> *this, int dx, int dy)
{
  return !dx && (dy == 1 || dy == 2 && !this->m_bMoved);
}

//----- (004A83D0) --------------------------------------------------------  // acclient.c:223907
int __stdcall TPawnPiece<CBasePiece>::bCanAttack(int dx, int dy)
{
  int result; // eax@1

  result = 1;
  if ( abs(dx) != 1 || dy != 1 )
    result = 0;
  return result;
}

//----- (004A83F0) --------------------------------------------------------  // acclient.c:223918
void __thiscall TRookPiece<CBasePiece>::TRookPiece<CBasePiece>(TRookPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 2;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TRookPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE0D4: using guessed type int (__stdcall *TRookPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A8440) --------------------------------------------------------  // acclient.c:223933
int __stdcall TRookPiece<CBasePiece>::bCanGoTo(int dx, int dy)
{
  return (dy != 0) ^ (dx != 0);
}

//----- (004A8460) --------------------------------------------------------  // acclient.c:223939
void __thiscall TKnightPiece<CBasePiece>::TKnightPiece<CBasePiece>(TKnightPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 3;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TKnightPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE0E8: using guessed type int (__stdcall *TKnightPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A84B0) --------------------------------------------------------  // acclient.c:223954
BOOL __stdcall TKnightPiece<CBasePiece>::bCanGoTo(int dx, int dy)
{
  int v3; // ecx@1

  v3 = abs(dx);
  return v3 == 1 && abs(dy) == 2 || v3 == 2 && abs(dy) == 1;
}

//----- (004A8500) --------------------------------------------------------  // acclient.c:223963
void __thiscall TBishopPiece<CBasePiece>::TBishopPiece<CBasePiece>(TBishopPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 4;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TBishopPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE0FC: using guessed type int (__stdcall *TBishopPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A8550) --------------------------------------------------------  // acclient.c:223978
BOOL __stdcall TBishopPiece<CBasePiece>::bCanGoTo(int dx, int dy)
{
  return abs(dx) == abs(dy);
}

//----- (004A8570) --------------------------------------------------------  // acclient.c:223984
void __thiscall TQueenPiece<CBasePiece>::TQueenPiece<CBasePiece>(TQueenPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 5;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TQueenPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE110: using guessed type int (__stdcall *TQueenPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A85C0) --------------------------------------------------------  // acclient.c:223999
BOOL __stdcall TQueenPiece<CBasePiece>::bCanGoTo(int dx, int dy)
{
  return !dx || !dy || abs(dx) == abs(dy);
}

//----- (004A8600) --------------------------------------------------------  // acclient.c:224005
void __thiscall TKingPiece<CBasePiece>::TKingPiece<CBasePiece>(TKingPiece<CBasePiece> *this, int Player, TCoord *StartingPos)
{
  this->m_didIcon.id = stru_83EE74.id;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)&TChessPiece<CBasePiece>::vftable;
  this->m_Type = 6;
  this->m_Player = Player;
  this->m_CurPos = *StartingPos;
  this->m_LastKnownGoodPos = *StartingPos;
  this->m_bMoved = 0;
  this->vfptr = (TChessPiece<CBasePiece>Vtbl *)TKingPiece<CBasePiece>::vftable;
}
// 7AE0A0: using guessed type int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int);
// 7AE124: using guessed type int (__stdcall *TKingPiece<CBasePiece>::vftable[2])(int, int dy);

//----- (004A8650) --------------------------------------------------------  // acclient.c:224020
BOOL __stdcall TKingPiece<CBasePiece>::bCanGoTo(int dx, int dy)
{
  return abs(dx) < 2 && abs(dy) < 2;
}

//----- (004A8680) --------------------------------------------------------  // acclient.c:224026
void __thiscall CChessLogic<CBasePiece>::TryPiecePos(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pPiece, TCoord NewPos)
{
  int v3; // edx@2
  int v4; // esi@3
  int v5; // edx@6
  TChessPiece<CBasePiece> *v6; // esi@6
  char *v7; // edx@6

  if ( pPiece )
  {
    v3 = pPiece->m_CurPos.x;
    if ( v3 >= 0 )
    {
      v4 = pPiece->m_CurPos.y;
      if ( v4 >= 0 && v3 < 8 && v4 < 8 )
      {
        v5 = v4 + 8 * v3;
        v6 = this->m_Board[0][v5];
        v7 = (char *)this->m_Board + 4 * v5;
        if ( v6 == pPiece )
          *(_DWORD *)v7 = 0;
      }
    }
    pPiece->m_CurPos = NewPos;
    if ( NewPos.x >= 0 && NewPos.y >= 0 && NewPos.x < 8 && NewPos.y < 8 )
      this->m_Board[0][NewPos.y + 8 * NewPos.x] = pPiece;
  }
}

//----- (004A86F0) --------------------------------------------------------  // acclient.c:224056
void __thiscall CChessLogic<CBasePiece>::UndoTryPiecePos(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pPiece)
{
  int v2; // edx@2
  int v3; // esi@3
  int v4; // edx@6
  TChessPiece<CBasePiece> *v5; // esi@6
  char *v6; // edx@6
  signed int v7; // edx@8
  int v8; // esi@8

  if ( pPiece )
  {
    v2 = pPiece->m_CurPos.x;
    if ( v2 >= 0 )
    {
      v3 = pPiece->m_CurPos.y;
      if ( v3 >= 0 && v2 < 8 && v3 < 8 )
      {
        v4 = v3 + 8 * v2;
        v5 = this->m_Board[0][v4];
        v6 = (char *)this->m_Board + 4 * v4;
        if ( v5 == pPiece )
          *(_DWORD *)v6 = 0;
      }
    }
    pPiece->m_CurPos.x = pPiece->m_LastKnownGoodPos.x;
    v7 = pPiece->m_LastKnownGoodPos.y;
    pPiece->m_CurPos.y = v7;
    v8 = pPiece->m_CurPos.x;
    if ( v8 >= 0 && v7 >= 0 && v8 < 8 && v7 < 8 )
      this->m_Board[0][v7 + 8 * v8] = pPiece;
  }
}

//----- (004A8760) --------------------------------------------------------  // acclient.c:224091
void __thiscall CChessLogic<CBasePiece>::~CChessLogic<CBasePiece>(CChessLogic<CBasePiece> *this)
{
  CChessLogic<CBasePiece> *v1; // ebx@1
  char *v2; // esi@1
  signed int v3; // ebp@1
  unsigned int v4; // edi@2
  int v5; // esi@7
  signed int v6; // edi@7
  void *v7; // ecx@8

  v1 = this;
  this->vfptr = (CChessLogic<CBasePiece>Vtbl *)&CChessLogic<CBasePiece>::vftable;
  memset(this->m_Board, 0, sizeof(this->m_Board));
  v2 = (char *)&this->m_Pieces[0].m_num;
  v3 = 2;
  do
  {
    v4 = 0;
    if ( *(_DWORD *)v2 )
    {
      do
      {
        if ( *(_DWORD *)(*((_DWORD *)v2 - 2) + 4 * v4) )
          operator delete(*(void **)(*((_DWORD *)v2 - 2) + 4 * v4));
        ++v4;
      }
      while ( v4 < *(_DWORD *)v2 );
    }
    v2 += 12;
    --v3;
  }
  while ( v3 );
  v5 = (int)&v1->m_CurPlayer;
  v6 = 2;
  do
  {
    v7 = *(void **)(v5 - 12);
    v5 -= 12;
    operator delete[](v7);
    --v6;
  }
  while ( v6 );
}
// 7AE0B4: using guessed type int (__thiscall *CChessLogic<CBasePiece>::vftable)(void *, char);

//----- (004A87E0) --------------------------------------------------------  // acclient.c:224137
CChessLogic<CBasePiece> *__thiscall CChessLogic<CBasePiece>::scalar_deleting_destructor(CChessLogic<CBasePiece> *this, unsigned int a2)
{
  CChessLogic<CBasePiece> *v2; // esi@1

  v2 = this;
  CChessLogic<CBasePiece>::~CChessLogic<CBasePiece>(this);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A8800) --------------------------------------------------------  // acclient.c:224149
int __thiscall AC1Legacy::SmartArray<TChessPiece<CBasePiece> *>::InsertOrderedByIndex(AC1Legacy::SmartArray<TChessPiece<CBasePiece> *> *this, TChessPiece<CBasePiece> *const *_data, unsigned int index)
{
  AC1Legacy::SmartArray<TChessPiece<CBasePiece> *> *v3; // esi@1
  unsigned int v4; // ecx@1
  unsigned int v5; // eax@2
  unsigned int v6; // eax@4
  unsigned int v7; // edx@7
  unsigned int v8; // ecx@8
  int i; // eax@8
  int result; // eax@10

  v3 = this;
  v4 = this->m_num;
  if ( index <= v4
    && ((v5 = v3->m_size, v4 < v5)
     || (!v5 ? (v6 = 8) : (v6 = 2 * v5),
         AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v3, v6))) )
  {
    v7 = v3->m_num;
    if ( v7 )
    {
      v8 = (unsigned int)&v3->m_data[index];
      for ( i = (int)&v3->m_data[v7 - 1]; i >= v8; i -= 4 )
        *(_DWORD *)(i + 4) = *(_DWORD *)i;
    }
    v3->m_data[index] = *_data;
    ++v3->m_num;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004A8870) --------------------------------------------------------  // acclient.c:224186
void __thiscall CChessLogic<CBasePiece>::CommitPiecePos(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pPiece, TCoord NewPos)
{
  int v3; // eax@2
  int v4; // ecx@2

  if ( pPiece )
  {
    CChessLogic<CBasePiece>::TryPiecePos(this, pPiece, NewPos);
    v3 = pPiece->m_CurPos.x;
    v4 = pPiece->m_CurPos.y;
    pPiece->m_bMoved = 1;
    pPiece->m_LastKnownGoodPos.x = v3;
    pPiece->m_LastKnownGoodPos.y = v4;
  }
}

//----- (004A88A0) --------------------------------------------------------  // acclient.c:224203
int __thiscall CChessLogic<CBasePiece>::TestCanGetThere(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pMovingPiece, TCoord *To, int bEnableEnPassant)
{
  int v4; // eax@1
  CChessLogic<CBasePiece> *v5; // ebx@1
  int v6; // edx@2
  int result; // eax@5
  TChessPiece<CBasePiece> *v8; // edi@6
  char *v9; // esi@6
  int v10; // ebp@6
  int v11; // ecx@7
  int v12; // ecx@14
  int v13; // edx@14
  TChessPiece<CBasePiece> *v14; // eax@14
  bool v15; // zf@14
  int v16; // eax@15
  signed int v17; // edi@26
  int v18; // eax@28
  int v19; // ecx@29
  int bAttack; // [sp+10h] [bp-8h]@6
  int bEnPassant; // [sp+14h] [bp-4h]@6

  v4 = To->x;
  v5 = this;
  if ( To->x < 0 )
    return -104;
  v6 = To->y;
  if ( v6 < 0 || v4 >= 8 || v6 >= 8 )
    return -104;
  v8 = pMovingPiece;
  v9 = (char *)&pMovingPiece->m_CurPos;
  v10 = v4 - pMovingPiece->m_CurPos.x;
  bAttack = 0;
  bEnPassant = 0;
  if ( pMovingPiece->m_Player )
  {
    v11 = pMovingPiece->m_CurPos.y - v6;
    pMovingPiece = (TChessPiece<CBasePiece> *)(pMovingPiece->m_CurPos.y - v6);
  }
  else
  {
    v11 = v6 - pMovingPiece->m_CurPos.y;
    pMovingPiece = (TChessPiece<CBasePiece> *)(v6 - pMovingPiece->m_CurPos.y);
  }
  if ( !bEnableEnPassant || v4 != v5->m_EnPassantAttackSite.x || v6 != v5->m_EnPassantAttackSite.y || v8->m_Type != 1 )
    goto LABEL_17;
  if ( !v8->vfptr->bCanAttack(v8, v10, v11) )
  {
    v11 = (int)pMovingPiece;
LABEL_17:
    v16 = (int)v5->m_Board[0][To->y + 8 * To->x];
    goto LABEL_18;
  }
  v12 = v5->m_EnPassantVictimPos.x;
  v13 = v5->m_EnPassantVictimPos.y;
  v14 = v5->m_Board[0][v13 + 8 * v12];
  v15 = v14->m_Type == 1;
  bEnableEnPassant = (int)v5->m_Board[0][v13 + 8 * v12];
  if ( !v15 )
  {
    v11 = (int)pMovingPiece;
    goto LABEL_24;
  }
  CChessLogic<CBasePiece>::TryPiecePos(v5, v14, v5->m_EnPassantAttackSite);
  v11 = (int)pMovingPiece;
  v16 = bEnableEnPassant;
  bEnPassant = 1;
LABEL_18:
  if ( v16 )
  {
    if ( *(_DWORD *)(v16 + 12) == v8->m_Player )
      return -105;
    bAttack = 1;
    if ( !v8->vfptr->bCanAttack(v8, v10, v11) )
      return -100;
    goto LABEL_26;
  }
LABEL_24:
  if ( !v8->vfptr->bCanGoTo(v8, v10, v11) )
    return -100;
LABEL_26:
  v17 = 1;
  if ( abs(v10) <= 1 && abs(pMovingPiece) <= 1
    || (CChessLogic<CBasePiece>::ConvertMoveToVector((TCoord *)v9, To, (DirectionNumber *)&pMovingPiece, (int *)&To),
        v18 = *((_DWORD *)v9 + 1),
        (signed int)To <= 1) )
  {
LABEL_32:
    if ( bAttack )
      result = (bEnPassant != 0) + 2;
    else
      result = 1;
  }
  else
  {
    v19 = 8 * *(_DWORD *)v9;
    while ( 1 )
    {
      v19 += 8 * (_DWORD)(&Directions)[(_DWORD)pMovingPiece];
      v18 += dword_822BBC[2 * (signed int)pMovingPiece];
      if ( v5->m_Board[0][v19 + v18] )
        break;
      ++v17;
      if ( v17 >= (signed int)To )
        goto LABEL_32;
    }
    result = -107;
  }
  return result;
}
// 822BB8: using guessed type struct TCoord *Directions;
// 822BBC: using guessed type int dword_822BBC[];

//----- (004A8A90) --------------------------------------------------------  // acclient.c:224316
void __thiscall GameBoardGrid::CommitMoves(GameBoardGrid *this)
{
  GameBoardGrid *v1; // ebx@1
  char *v2; // edi@1
  signed int v3; // ebp@2
  int v4; // eax@3
  int v5; // esi@4
  int v6; // ecx@6
  unsigned int v7; // eax@6
  int v8; // edx@6
  signed int v9; // [sp+10h] [bp-4h]@1

  v1 = this;
  v2 = (char *)this->m_rgPreviousBoard;
  v9 = 8;
  do
  {
    v3 = 8;
    do
    {
      v4 = *((_DWORD *)v2 - 90);
      if ( v4 )
      {
        v5 = *(_DWORD *)v2;
        if ( *(_DWORD *)v2 )
        {
          if ( v4 != v5 )
          {
            v6 = (int)&v1->m_Pieces[*(_DWORD *)(v5 + 12)];
            v7 = *(_DWORD *)v6;
            v8 = *(_DWORD *)v6 + 4 * v1->m_Pieces[*(_DWORD *)(v5 + 12)].m_num;
            if ( *(_DWORD *)v6 < (unsigned int)v8 )
            {
              while ( *(_DWORD *)v7 != v5 )
              {
                v7 += 4;
                if ( v7 >= v8 )
                  goto LABEL_11;
              }
              *(_DWORD *)v7 = *(_DWORD *)(v8 - 4);
              --*(_DWORD *)(v6 + 8);
            }
LABEL_11:
            operator delete((void *)v5);
          }
        }
      }
      *(_DWORD *)v2 = 0;
      v2 += 4;
      --v3;
    }
    while ( v3 );
    --v9;
  }
  while ( v9 );
  v1->m_coordSelected.x = -1;
  v1->m_coordSelected.y = -1;
  GameBoardGrid::Draw(v1);
}

//----- (004A8B40) --------------------------------------------------------  // acclient.c:224377
void __thiscall GameBoardGrid::ClearAllPieces(GameBoardGrid *this)
{
  char *v1; // eax@1
  signed int v2; // esi@1
  signed int v3; // edx@2
  char *v4; // esi@5
  signed int v5; // ebp@5
  unsigned int i; // edi@6
  void *v7; // ST00_4@10

  v1 = (char *)this->m_rgPreviousBoard;
  v2 = 8;
  do
  {
    v3 = 8;
    do
    {
      *((_DWORD *)v1 - 90) = 0;
      *(_DWORD *)v1 = 0;
      v1 += 4;
      --v3;
    }
    while ( v3 );
    --v2;
  }
  while ( v2 );
  v4 = (char *)&this->m_Pieces[0].m_num;
  v5 = 2;
  do
  {
    for ( i = 0; i < *(_DWORD *)v4; ++i )
    {
      if ( *(_DWORD *)(*((_DWORD *)v4 - 2) + 4 * i) )
        operator delete(*(void **)(*((_DWORD *)v4 - 2) + 4 * i));
    }
    v7 = (void *)*((_DWORD *)v4 - 2);
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v4 - 1) = 0;
    operator delete[](v7);
    *((_DWORD *)v4 - 2) = 0;
    v4 += 12;
    --v5;
  }
  while ( v5 );
}

//----- (004A8BD0) --------------------------------------------------------  // acclient.c:224424
void __thiscall GameBoardGrid::GameBoardGrid(GameBoardGrid *this, gmMiniGameUI *_gameUI)
{
  GameBoardGrid *v2; // esi@1
  UIElement *v3; // ecx@1
  UIElement *v4; // eax@1
  int v5; // eax@2
  signed int v6; // edi@4
  UIElement_ListBox *v7; // ecx@6
  BasePropertyDesc *v8; // ecx@9
  unsigned int v9; // edx@9
  BasePropertyValue *v10; // ecx@12
  unsigned int v11; // edx@13
  IDClass<_tagDataID,32,0> result; // [sp+Ch] [bp-34h]@7
  IDClass<_tagDataID,32,0> v13; // [sp+10h] [bp-30h]@7
  IDClass<_tagDataID,32,0> v14; // [sp+14h] [bp-2Ch]@7
  IDClass<_tagDataID,32,0> v15; // [sp+18h] [bp-28h]@7
  IDClass<_tagDataID,32,0> v16; // [sp+1Ch] [bp-24h]@7
  IDClass<_tagDataID,32,0> v17; // [sp+20h] [bp-20h]@7
  IDClass<_tagDataID,32,0> v18; // [sp+24h] [bp-1Ch]@7
  IDClass<_tagDataID,32,0> v19; // [sp+28h] [bp-18h]@7
  IDClass<_tagDataID,32,0> v20; // [sp+2Ch] [bp-14h]@7
  IDClass<_tagDataID,32,0> v21; // [sp+30h] [bp-10h]@7
  IDClass<_tagDataID,32,0> v22; // [sp+34h] [bp-Ch]@7
  BaseProperty iconArrayProp; // [sp+38h] [bp-8h]@6

  v2 = this;
  CChessLogic<CBasePiece>::CChessLogic<CBasePiece>((CChessLogic<CBasePiece> *)&this->vfptr);
  v3 = (UIElement *)_gameUI;
  v2->vfptr = (CChessLogic<CBasePiece>Vtbl *)&GameBoardGrid::vftable;
  v2->m_pieceListBox = 0;
  v2->m_coordSelected.x = -1;
  v2->m_coordSelected.y = -1;
  v2->m_gameUI = (gmMiniGameUI *)v3;
  v4 = UIElement::GetChildRecursive(v3, 0x10000174u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)5);
  else
    v5 = 0;
  v2->m_pieceListBox = (UIElement_ListBox *)v5;
  v6 = 64;
  do
  {
    UIElement_ListBox::AddItemFromTemplateListByID(v2->m_pieceListBox, 0x10000178u, 0);
    --v6;
  }
  while ( v6 );
  v7 = v2->m_pieceListBox;
  iconArrayProp.m_pcPropertyDesc = 0;
  iconArrayProp.m_pcPropertyValue = 0;
  if ( (unsigned __int8)((int (__stdcall *)(signed int, BaseProperty *))v7->vfptr[17].OnAction)(
                          268435489,
                          &iconArrayProp) )
  {
    v2->m_didWhitePawn.id = GameBoardGrid::GetPieceDID((IDClass<_tagDataID,32,0> *)&_gameUI, 0, &iconArrayProp)->id;
    v2->m_didWhiteRook.id = GameBoardGrid::GetPieceDID(&result, 3, &iconArrayProp)->id;
    v2->m_didWhiteBishop.id = GameBoardGrid::GetPieceDID(&v13, 1, &iconArrayProp)->id;
    v2->m_didWhiteKnight.id = GameBoardGrid::GetPieceDID(&v14, 2, &iconArrayProp)->id;
    v2->m_didWhiteQueen.id = GameBoardGrid::GetPieceDID(&v15, 4, &iconArrayProp)->id;
    v2->m_didWhiteKing.id = GameBoardGrid::GetPieceDID(&v16, 5, &iconArrayProp)->id;
    v2->m_didBlackPawn.id = GameBoardGrid::GetPieceDID(&v17, 6, &iconArrayProp)->id;
    v2->m_didBlackRook.id = GameBoardGrid::GetPieceDID(&v18, 9, &iconArrayProp)->id;
    v2->m_didBlackBishop.id = GameBoardGrid::GetPieceDID(&v19, 7, &iconArrayProp)->id;
    v2->m_didBlackKnight.id = GameBoardGrid::GetPieceDID(&v20, 8, &iconArrayProp)->id;
    v2->m_didBlackQueen.id = GameBoardGrid::GetPieceDID(&v21, 10, &iconArrayProp)->id;
    v2->m_didBlackKing.id = GameBoardGrid::GetPieceDID(&v22, 11, &iconArrayProp)->id;
  }
  if ( (_DWORD)iconArrayProp.m_pcPropertyDesc )
  {
    v8 = iconArrayProp.m_pcPropertyDesc;
    v9 = iconArrayProp.m_pcPropertyDesc->m_cRef - 1;
    iconArrayProp.m_pcPropertyDesc->m_cRef = v9;
    if ( !v9 )
      ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
    iconArrayProp.m_pcPropertyDesc = 0;
  }
  v10 = iconArrayProp.m_pcPropertyValue;
  if ( iconArrayProp.m_pcPropertyValue )
  {
    v11 = iconArrayProp.m_pcPropertyValue->m_cRef - 1;
    iconArrayProp.m_pcPropertyValue->m_cRef = v11;
    if ( !v11 )
      ((void (__stdcall *)(_DWORD))v10->vfptr->__vecDelDtor)(1);
  }
}
// 7AE138: using guessed type int (__thiscall *GameBoardGrid::vftable)(void *, char);

//----- (004A8E00) --------------------------------------------------------  // acclient.c:224511
void __thiscall GameBoardGrid::CreatePiece(GameBoardGrid *this, int x, int y, int iPlayer, ChessPieceType type)
{
  int v5; // ebp@1
  int v6; // esi@1
  int v7; // edi@1
  GameBoardGrid *v8; // ebx@1
  TPawnPiece<CBasePiece> *v9; // eax@2
  int v10; // eax@3
  unsigned int v11; // eax@6
  TRookPiece<CBasePiece> *v12; // eax@8
  int v13; // eax@9
  TKnightPiece<CBasePiece> *v14; // eax@14
  int v15; // eax@15
  TBishopPiece<CBasePiece> *v16; // eax@20
  int v17; // eax@21
  TQueenPiece<CBasePiece> *v18; // eax@26
  int v19; // eax@27
  TKingPiece<CBasePiece> *v20; // eax@32
  int v21; // eax@33
  unsigned int v22; // eax@41
  int v23; // edi@41
  unsigned int v24; // eax@43
  TCoord coord; // [sp+10h] [bp-8h]@1

  v5 = x;
  coord.y = y;
  v6 = 0;
  v7 = iPlayer;
  v8 = this;
  coord.x = x;
  x = 0;
  switch ( type )
  {
    case 1:
      v9 = (TPawnPiece<CBasePiece> *)operator new(0x24u);
      if ( v9 )
      {
        TPawnPiece<CBasePiece>::TPawnPiece<CBasePiece>(v9, v7, &coord);
        v6 = v10;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackPawn.id;
      else
        v11 = v8->m_didWhitePawn.id;
      goto LABEL_38;
    case 2:
      v12 = (TRookPiece<CBasePiece> *)operator new(0x24u);
      if ( v12 )
      {
        TRookPiece<CBasePiece>::TRookPiece<CBasePiece>(v12, v7, &coord);
        v6 = v13;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackRook.id;
      else
        v11 = v8->m_didWhiteRook.id;
      goto LABEL_38;
    case 3:
      v14 = (TKnightPiece<CBasePiece> *)operator new(0x24u);
      if ( v14 )
      {
        TKnightPiece<CBasePiece>::TKnightPiece<CBasePiece>(v14, v7, &coord);
        v6 = v15;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackKnight.id;
      else
        v11 = v8->m_didWhiteKnight.id;
      goto LABEL_38;
    case 4:
      v16 = (TBishopPiece<CBasePiece> *)operator new(0x24u);
      if ( v16 )
      {
        TBishopPiece<CBasePiece>::TBishopPiece<CBasePiece>(v16, v7, &coord);
        v6 = v17;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackBishop.id;
      else
        v11 = v8->m_didWhiteBishop.id;
      goto LABEL_38;
    case 5:
      v18 = (TQueenPiece<CBasePiece> *)operator new(0x24u);
      if ( v18 )
      {
        TQueenPiece<CBasePiece>::TQueenPiece<CBasePiece>(v18, v7, &coord);
        v6 = v19;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackQueen.id;
      else
        v11 = v8->m_didWhiteQueen.id;
      goto LABEL_38;
    case 6:
      v20 = (TKingPiece<CBasePiece> *)operator new(0x24u);
      if ( v20 )
      {
        TKingPiece<CBasePiece>::TKingPiece<CBasePiece>(v20, v7, &coord);
        v6 = v21;
      }
      else
      {
        v6 = 0;
      }
      x = v6;
      if ( v7 )
        v11 = v8->m_didBlackKing.id;
      else
        v11 = v8->m_didWhiteKing.id;
LABEL_38:
      *(_DWORD *)(v6 + 4) = v11;
      break;
    default:
      break;
  }
  v8->m_Board[0][y + 8 * v5] = (TChessPiece<CBasePiece> *)v6;
  if ( *(_DWORD *)(v6 + 8) == 6 )
  {
    AC1Legacy::SmartArray<TChessPiece<CBasePiece> *>::InsertOrderedByIndex(
      &v8->m_Pieces[v7],
      (TChessPiece<CBasePiece> *const *)&x,
      0);
  }
  else
  {
    v22 = v8->m_Pieces[v7].m_size;
    v23 = (int)&v8->m_Pieces[v7];
    if ( *(_DWORD *)(v23 + 8) < v22
      || (!v22 ? (v24 = 8) : (v24 = 2 * v22),
          AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v23, v24)) )
      *(_DWORD *)(*(_DWORD *)v23 + 4 * (*(_DWORD *)(v23 + 8))++) = v6;
  }
}

//----- (004A9030) --------------------------------------------------------  // acclient.c:224671
int __thiscall CChessLogic<CBasePiece>::IsPlayerInCheck(CChessLogic<CBasePiece> *this, int Player)
{
  CChessLogic<CBasePiece> *v2; // esi@1
  TChessPiece<CBasePiece> *v3; // eax@1
  char *v4; // ebx@2
  int v5; // edi@2
  TCoord *v6; // ebp@3
  int result; // eax@6
  int Playera; // [sp+14h] [bp+4h]@2

  v2 = this;
  v3 = *this->m_Pieces[Player == 1].m_data;
  if ( v3 && (v4 = (char *)this + 12 * (Player == 0), v5 = 0, Playera = *((_DWORD *)v4 + 67), *((_DWORD *)v4 + 67) > 0) )
  {
    v6 = &v3->m_CurPos;
    while ( CChessLogic<CBasePiece>::TestCanGetThere(
              v2,
              *(TChessPiece<CBasePiece> **)(*((_DWORD *)v4 + 65) + 4 * v5),
              v6,
              0) <= 0 )
    {
      ++v5;
      if ( v5 >= Playera )
        goto LABEL_6;
    }
    result = 1;
  }
  else
  {
LABEL_6:
    result = 0;
  }
  return result;
}

//----- (004A90B0) --------------------------------------------------------  // acclient.c:224707
int __thiscall CChessLogic<CBasePiece>::DoesMoveSelfCheck(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pMovingPiece, TCoord *To)
{
  CChessLogic<CBasePiece> *v3; // esi@1
  TCoord v4; // ST04_8@1
  TChessPiece<CBasePiece> *v5; // edi@1
  int v6; // ebp@1

  v3 = this;
  v4.y = To->y;
  v5 = this->m_Board[0][v4.y + 8 * To->x];
  v4.x = To->x;
  CChessLogic<CBasePiece>::TryPiecePos(this, pMovingPiece, v4);
  CChessLogic<CBasePiece>::TryPiecePos(v3, v5, HEAVEN);
  v6 = CChessLogic<CBasePiece>::IsPlayerInCheck(v3, pMovingPiece->m_Player);
  CChessLogic<CBasePiece>::UndoTryPiecePos(v3, pMovingPiece);
  CChessLogic<CBasePiece>::UndoTryPiecePos(v3, v5);
  return v6;
}

//----- (004A9120) --------------------------------------------------------  // acclient.c:224727
void __thiscall gmMiniGameUI::PostInit(gmMiniGameUI *this)
{
  gmMiniGameUI *v1; // edi@1
  UIElement *v2; // eax@1
  int v3; // eax@2
  UIElement *v4; // eax@4
  int v5; // eax@5
  UIElement *v6; // eax@7
  int v7; // eax@8
  UIElement_Button *v8; // ecx@10
  GlobalEventHandler *v9; // eax@10
  GlobalEventHandler *v10; // esi@10
  GameBoardGrid *v11; // eax@12
  GameBoardGrid *v12; // eax@13

  v1 = this;
  UIElement::PostInit((UIElement *)&this->vfptr);
  v2 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000175u);
  if ( v2 )
    v3 = v2->vfptr[12].OnAction((IInputActionCallback *)v2, (InputEvent *)1);
  else
    v3 = 0;
  v1->m_pResignButton = (UIElement_Button *)v3;
  v4 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000176u);
  if ( v4 )
    v5 = v4->vfptr[12].OnAction((IInputActionCallback *)v4, (InputEvent *)1);
  else
    v5 = 0;
  v1->m_pPassButton = (UIElement_Button *)v5;
  v6 = UIElement::GetChildRecursive((UIElement *)&v1->vfptr, 0x10000177u);
  if ( v6 )
    v7 = v6->vfptr[12].OnAction((IInputActionCallback *)v6, (InputEvent *)1);
  else
    v7 = 0;
  v8 = v1->m_pResignButton;
  v1->m_pStalemateButton = (UIElement_Button *)v7;
  ((void (__stdcall *)(signed int))v8->vfptr[2].__vecDelDtor)(1);
  ((void (__stdcall *)(_DWORD))v1->m_pPassButton->vfptr[2].__vecDelDtor)(0);
  ((void (__stdcall *)(signed int))v1->m_pStalemateButton->vfptr[2].__vecDelDtor)(1);
  v9 = GlobalEventHandler::GetGlobalEventHandler();
  v10 = v9;
  if ( v9 )
  {
    v9->vfptr->RegisterNoticeHandler(
      (NoticeRegistrar *)v9,
      (unsigned int)((char *)&loc_4DD218 + 1),
      (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD250, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD21A, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 5100091u, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, (unsigned int)&loc_4DD23C, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 5100093u, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 5100094u, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 5100095u, (NoticeHandler *)&v1->vfptr);
    v10->vfptr->RegisterNoticeHandler((NoticeRegistrar *)v10, 5100096u, (NoticeHandler *)&v1->vfptr);
  }
  v11 = (GameBoardGrid *)operator new(0x274u);
  if ( v11 )
  {
    GameBoardGrid::GameBoardGrid(v11, v1);
    v1->m_pGameBoard = v12;
  }
  else
  {
    v1->m_pGameBoard = 0;
  }
}

//----- (004A9280) --------------------------------------------------------  // acclient.c:224796
CChessLogic<CBasePiece> *__thiscall GameBoardGrid::scalar_deleting_destructor(GameBoardGrid *this, unsigned int a2)
{
  CChessLogic<CBasePiece> *v2; // esi@1

  v2 = (CChessLogic<CBasePiece> *)this;
  this->vfptr = (CChessLogic<CBasePiece>Vtbl *)&GameBoardGrid::vftable;
  GameBoardGrid::ClearAllPieces(this);
  CChessLogic<CBasePiece>::~CChessLogic<CBasePiece>(v2);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 7AE138: using guessed type int (__thiscall *GameBoardGrid::vftable)(void *, char);

//----- (004A92B0) --------------------------------------------------------  // acclient.c:224811
void __thiscall GameBoardGrid::Reset(GameBoardGrid *this)
{
  char *v1; // esi@1
  signed int v2; // edi@1
  GameBoardGrid *v3; // [sp+10h] [bp-204h]@1
  GameBoardGrid::Reset::__l2::__unnamed rgDefaultPieces[32]; // [sp+14h] [bp-200h]@1

  v3 = this;
  GameBoardGrid::ClearAllPieces(this);
  rgDefaultPieces[3].type = 5;
  rgDefaultPieces[5].x = 5;
  rgDefaultPieces[0].iSide = 0;
  rgDefaultPieces[0].type = 2;
  rgDefaultPieces[1].x = 1;
  rgDefaultPieces[1].y = 0;
  rgDefaultPieces[1].iSide = 0;
  rgDefaultPieces[1].type = 3;
  rgDefaultPieces[2].x = 2;
  rgDefaultPieces[2].y = 0;
  rgDefaultPieces[2].iSide = 0;
  rgDefaultPieces[2].type = 4;
  rgDefaultPieces[3].x = 3;
  rgDefaultPieces[3].y = 0;
  rgDefaultPieces[3].iSide = 0;
  rgDefaultPieces[4].x = 4;
  rgDefaultPieces[4].y = 0;
  rgDefaultPieces[4].iSide = 0;
  rgDefaultPieces[4].type = 6;
  rgDefaultPieces[5].y = 0;
  rgDefaultPieces[5].iSide = 0;
  rgDefaultPieces[5].type = 4;
  rgDefaultPieces[6].x = 6;
  rgDefaultPieces[6].y = 0;
  rgDefaultPieces[6].iSide = 0;
  rgDefaultPieces[6].type = 3;
  rgDefaultPieces[7].x = 7;
  rgDefaultPieces[7].y = 0;
  rgDefaultPieces[7].iSide = 0;
  rgDefaultPieces[7].type = 2;
  rgDefaultPieces[8].x = 0;
  rgDefaultPieces[8].y = 1;
  rgDefaultPieces[8].iSide = 0;
  rgDefaultPieces[8].type = 1;
  rgDefaultPieces[9].x = 1;
  rgDefaultPieces[9].y = 1;
  rgDefaultPieces[9].iSide = 0;
  rgDefaultPieces[9].type = 1;
  rgDefaultPieces[10].x = 2;
  rgDefaultPieces[10].y = 1;
  rgDefaultPieces[10].iSide = 0;
  rgDefaultPieces[10].type = 1;
  rgDefaultPieces[11].x = 3;
  rgDefaultPieces[11].y = 1;
  rgDefaultPieces[11].iSide = 0;
  rgDefaultPieces[11].type = 1;
  rgDefaultPieces[12].x = 4;
  rgDefaultPieces[12].y = 1;
  rgDefaultPieces[12].iSide = 0;
  rgDefaultPieces[12].type = 1;
  rgDefaultPieces[13].x = 5;
  rgDefaultPieces[13].y = 1;
  rgDefaultPieces[13].iSide = 0;
  rgDefaultPieces[13].type = 1;
  rgDefaultPieces[14].x = 6;
  rgDefaultPieces[14].y = 1;
  rgDefaultPieces[14].iSide = 0;
  rgDefaultPieces[14].type = 1;
  rgDefaultPieces[15].x = 7;
  rgDefaultPieces[15].y = 1;
  rgDefaultPieces[15].iSide = 0;
  rgDefaultPieces[15].type = 1;
  rgDefaultPieces[16].x = 0;
  rgDefaultPieces[16].y = 6;
  rgDefaultPieces[16].iSide = 1;
  rgDefaultPieces[24].x = 0;
  rgDefaultPieces[20].x = 4;
  rgDefaultPieces[23].x = 7;
  rgDefaultPieces[24].y = 7;
  rgDefaultPieces[25].y = 7;
  rgDefaultPieces[26].y = 7;
  rgDefaultPieces[26].type = 4;
  rgDefaultPieces[27].y = 7;
  rgDefaultPieces[28].x = 4;
  rgDefaultPieces[28].y = 7;
  rgDefaultPieces[29].y = 7;
  rgDefaultPieces[29].type = 4;
  rgDefaultPieces[30].y = 7;
  rgDefaultPieces[31].x = 7;
  rgDefaultPieces[31].y = 7;
  rgDefaultPieces[16].type = 1;
  rgDefaultPieces[17].x = 1;
  rgDefaultPieces[17].y = 6;
  rgDefaultPieces[17].iSide = 1;
  rgDefaultPieces[17].type = 1;
  rgDefaultPieces[18].x = 2;
  rgDefaultPieces[18].y = 6;
  rgDefaultPieces[18].iSide = 1;
  rgDefaultPieces[18].type = 1;
  rgDefaultPieces[19].x = 3;
  rgDefaultPieces[19].y = 6;
  rgDefaultPieces[19].iSide = 1;
  rgDefaultPieces[19].type = 1;
  rgDefaultPieces[20].y = 6;
  rgDefaultPieces[20].iSide = 1;
  rgDefaultPieces[20].type = 1;
  rgDefaultPieces[21].x = 5;
  rgDefaultPieces[21].y = 6;
  rgDefaultPieces[21].iSide = 1;
  rgDefaultPieces[21].type = 1;
  rgDefaultPieces[22].x = 6;
  rgDefaultPieces[22].y = 6;
  rgDefaultPieces[22].iSide = 1;
  rgDefaultPieces[22].type = 1;
  rgDefaultPieces[23].y = 6;
  rgDefaultPieces[23].iSide = 1;
  rgDefaultPieces[23].type = 1;
  rgDefaultPieces[24].iSide = 1;
  rgDefaultPieces[24].type = 2;
  rgDefaultPieces[25].x = 1;
  rgDefaultPieces[25].iSide = 1;
  rgDefaultPieces[25].type = 3;
  rgDefaultPieces[26].x = 2;
  rgDefaultPieces[26].iSide = 1;
  rgDefaultPieces[27].x = 3;
  rgDefaultPieces[27].iSide = 1;
  rgDefaultPieces[27].type = 5;
  rgDefaultPieces[28].iSide = 1;
  rgDefaultPieces[28].type = 6;
  rgDefaultPieces[29].x = 5;
  rgDefaultPieces[29].iSide = 1;
  rgDefaultPieces[30].x = 6;
  rgDefaultPieces[30].iSide = 1;
  rgDefaultPieces[30].type = 3;
  rgDefaultPieces[31].iSide = 1;
  rgDefaultPieces[31].type = 2;
  v1 = (char *)&rgDefaultPieces[0].iSide;
  v2 = 32;
  do
  {
    GameBoardGrid::CreatePiece(v3, *((_DWORD *)v1 - 2), *((_DWORD *)v1 - 1), *(_DWORD *)v1, *((ChessPieceType *)v1 + 1));
    v1 += 16;
    --v2;
  }
  while ( v2 );
  GameBoardGrid::Draw(v3);
}

//----- (004A9670) --------------------------------------------------------  // acclient.c:224959
signed int __thiscall CChessLogic<CBasePiece>::HandleCastling(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pKing, TCoord *To)
{
  TChessPiece<CBasePiece> *v3; // esi@1
  CChessLogic<CBasePiece> *v4; // edi@1
  signed int result; // eax@2
  int v6; // eax@7
  int v7; // ebx@7
  signed int v8; // ecx@7
  int v9; // eax@9
  int v10; // ebp@10
  int v11; // ebx@12
  int v12; // ebp@20
  int v13; // eax@20
  TCoord KingDest; // [sp+8h] [bp-10h]@20
  TCoord RookDest; // [sp+10h] [bp-8h]@20
  int pKinga; // [sp+1Ch] [bp+4h]@9

  v3 = pKing;
  v4 = this;
  if ( pKing )
  {
    if ( this->m_bLastMoveWasCheck )
    {
      result = -108;
    }
    else if ( pKing->m_bMoved )
    {
      result = -110;
    }
    else
    {
      v6 = pKing->m_CurPos.x;
      v7 = pKing->m_CurPos.y;
      v8 = 1;
      if ( To->x < v6 )
        v8 = -1;
      v9 = v8 + v6;
      pKinga = v9;
      if ( v9 >= 0 )
      {
        v10 = (int)((char *)v4->m_Board + 4 * (v7 + 8 * v9));
        while ( v9 < 8 )
        {
          v11 = *(_DWORD *)v10;
          if ( *(_DWORD *)v10 )
          {
            if ( *(_DWORD *)(v11 + 8) == 2 && *(_DWORD *)(v11 + 12) == v3->m_Player )
            {
              if ( *(_DWORD *)(v11 + 32) )
              {
                result = -110;
              }
              else
              {
                v12 = v3->m_CurPos.y;
                RookDest.x = v3->m_CurPos.x;
                KingDest.y = v12;
                v13 = v3->m_CurPos.x + 2 * v8;
                RookDest.y = v12;
                RookDest.x = pKinga;
                KingDest.x = v13;
                if ( CChessLogic<CBasePiece>::DoesMoveSelfCheck(v4, v3, &RookDest) )
                {
                  result = -109;
                }
                else if ( CChessLogic<CBasePiece>::DoesMoveSelfCheck(v4, v3, &KingDest) )
                {
                  result = -106;
                }
                else
                {
                  CChessLogic<CBasePiece>::CommitPiecePos(
                    v4,
                    (TChessPiece<CBasePiece> *)v11,
                    (TCoord)__PAIR__(v12, RookDest.x));
                  CChessLogic<CBasePiece>::CommitPiecePos(v4, v3, KingDest);
                  v4->vfptr->MovePiece(v4, (TChessPiece<CBasePiece> *)v11);
                  result = 1;
                }
              }
            }
            else
            {
              result = -107;
            }
            return result;
          }
          v9 += v8;
          v10 += 32 * v8;
          if ( v9 < 0 )
            break;
        }
      }
      result = -102;
    }
  }
  else
  {
    result = -102;
  }
  return result;
}

//----- (004A97E0) --------------------------------------------------------  // acclient.c:225063
signed int __thiscall CChessLogic<CBasePiece>::TestMoveAndSelfCheck(CChessLogic<CBasePiece> *this, TChessPiece<CBasePiece> *pMovingPiece, TCoord *To)
{
  CChessLogic<CBasePiece> *v3; // esi@1
  int v4; // edi@1
  bool v5; // zf@2
  signed int result; // eax@2

  v3 = this;
  v4 = CChessLogic<CBasePiece>::TestCanGetThere(this, pMovingPiece, To, 1);
  if ( v4 <= 0 || (v5 = CChessLogic<CBasePiece>::DoesMoveSelfCheck(v3, pMovingPiece, To) == 0, result = -106, v5) )
    result = v4;
  return result;
}

//----- (004A9820) --------------------------------------------------------  // acclient.c:225078
int __thiscall CChessLogic<CBasePiece>::IsPlayerInCheckMate(CChessLogic<CBasePiece> *this, int Player)
{
  CChessLogic<CBasePiece> *v2; // ebx@1
  TChessPiece<CBasePiece> *v3; // edi@1
  int v4; // ebp@2
  int v5; // edx@2
  signed int v6; // esi@2
  int v7; // eax@3
  int v8; // edi@7
  int v9; // esi@8
  signed int v11; // ebp@11
  int v12; // edi@12
  int v13; // esi@13
  int v14; // edx@14
  int v15; // eax@14
  TChessPiece<CBasePiece> *v16; // edi@14
  signed int v17; // ecx@15
  signed int v18; // eax@16
  int v19; // eax@19
  int v20; // edx@26
  int v21; // ebp@26
  signed int v22; // ecx@27
  signed int v23; // eax@28
  int v24; // eax@31
  TChessPiece<CBasePiece> *v25; // ecx@31
  int v26; // eax@31
  int v27; // eax@38
  signed int v28; // ecx@38
  signed int v29; // edx@39
  int v30; // ecx@42
  signed int v31; // ecx@44
  signed int v32; // edx@44
  signed int v33; // ecx@45
  signed int v34; // edx@50
  signed int v35; // ecx@51
  int v36; // ecx@54
  signed int v37; // ecx@56
  signed int v38; // edx@56
  signed int v39; // ecx@57
  int v40; // edx@64
  bool v41; // sf@64
  unsigned __int8 v42; // of@64
  char *v43; // [sp+10h] [bp-24h]@1
  int v44; // [sp+14h] [bp-20h]@11
  int i; // [sp+18h] [bp-1Ch]@2
  int ia; // [sp+18h] [bp-1Ch]@11
  int Dist; // [sp+1Ch] [bp-18h]@2
  TCoord KingPos; // [sp+20h] [bp-14h]@2
  DirectionNumber Dir; // [sp+28h] [bp-Ch]@11
  TCoord Pos; // [sp+2Ch] [bp-8h]@3
  int Playera; // [sp+38h] [bp+4h]@12

  v2 = this;
  v3 = *this->m_Pieces[Player].m_data;
  v43 = (char *)this + 12 * Player;
  if ( v3 )
  {
    v4 = v3->m_CurPos.x;
    v5 = v3->m_CurPos.y;
    i = (int)((char *)this + 12 * (Player == 0));
    Dist = this->m_Pieces[Player == 0].m_num;
    KingPos.x = v4;
    KingPos.y = v5;
    v6 = (signed int)&Directions;
    while ( 1 )
    {
      v7 = *(_DWORD *)(v6 + 4) + KingPos.y;
      Pos.x = v4 + *(_DWORD *)v6;
      Pos.y = v7;
      if ( CChessLogic<CBasePiece>::TestCanGetThere(v2, v3, &Pos, 1) > 0
        && !CChessLogic<CBasePiece>::DoesMoveSelfCheck(v2, v3, &Pos) )
        break;
      v6 += 8;
      if ( v6 >= (signed int)&unk_822BF8 )
      {
        if ( !CChessLogic<CBasePiece>::IsPlayerInCheck(v2, Player) )
          return 0;
        v8 = 0;
        if ( Dist <= 0 )
          return 0;
        while ( 1 )
        {
          v9 = *(_DWORD *)(*(_DWORD *)(i + 260) + 4 * v8);
          if ( CChessLogic<CBasePiece>::TestCanGetThere(
                 v2,
                 *(TChessPiece<CBasePiece> **)(*(_DWORD *)(i + 260) + 4 * v8),
                 &KingPos,
                 0) > 0 )
            break;
          ++v8;
          if ( v8 >= Dist )
            return 0;
        }
        v11 = *(_DWORD *)(v9 + 16);
        Pos.y = *(_DWORD *)(v9 + 20);
        Pos.x = v11;
        CChessLogic<CBasePiece>::ConvertMoveToVector(&Pos, &KingPos, &Dir, &Dist);
        v44 = *((_DWORD *)v43 + 67);
        ia = 0;
        if ( Dist > 0 )
        {
          do
          {
            v12 = 0;
            for ( Playera = 0; v12 < v44; Playera = v12 )
            {
              v13 = *(_DWORD *)(*((_DWORD *)v43 + 65) + 4 * v12);
              if ( CChessLogic<CBasePiece>::TestCanGetThere(
                     v2,
                     *(TChessPiece<CBasePiece> **)(*((_DWORD *)v43 + 65) + 4 * v12),
                     &Pos,
                     1) > 0 )
              {
                v14 = Pos.y;
                v15 = Pos.y + 8 * v11;
                v16 = v2->m_Board[0][v15];
                KingPos.x = (int)((char *)v2->m_Board + 4 * v15);
                if ( v13 )
                {
                  v17 = *(_DWORD *)(v13 + 16);
                  if ( v17 >= 0 )
                  {
                    v18 = *(_DWORD *)(v13 + 20);
                    if ( v18 >= 0 && v17 < 8 && v18 < 8 )
                    {
                      v19 = (int)((char *)v2->m_Board + 4 * (v18 + 8 * v17));
                      if ( *(_DWORD *)v19 == v13 )
                        *(_DWORD *)v19 = 0;
                    }
                  }
                  *(_DWORD *)(v13 + 16) = v11;
                  *(_DWORD *)(v13 + 20) = v14;
                  if ( v11 >= 0 && v14 >= 0 && v11 < 8 && v14 < 8 )
                    *(_DWORD *)KingPos.x = v13;
                }
                v20 = HEAVEN.x;
                v21 = HEAVEN.y;
                if ( v16 )
                {
                  v22 = v16->m_CurPos.x;
                  if ( v22 >= 0 )
                  {
                    v23 = v16->m_CurPos.y;
                    if ( v23 >= 0 && v22 < 8 && v23 < 8 )
                    {
                      v24 = v23 + 8 * v22;
                      v25 = v2->m_Board[0][v24];
                      v26 = (int)((char *)v2->m_Board + 4 * v24);
                      if ( v25 == v16 )
                        *(_DWORD *)v26 = 0;
                    }
                  }
                  v16->m_CurPos.x = v20;
                  v16->m_CurPos.y = v21;
                  if ( v20 >= 0 && v21 >= 0 && v20 < 8 && v21 < 8 )
                    v2->m_Board[0][v21 + 8 * v20] = v16;
                }
                v27 = CChessLogic<CBasePiece>::IsPlayerInCheck(v2, *(_DWORD *)(v13 + 12));
                v28 = *(_DWORD *)(v13 + 16);
                if ( v28 >= 0 )
                {
                  v29 = *(_DWORD *)(v13 + 20);
                  if ( v29 >= 0 && v28 < 8 && v29 < 8 )
                  {
                    v30 = (int)((char *)v2->m_Board + 4 * (v29 + 8 * v28));
                    if ( *(_DWORD *)v30 == v13 )
                      *(_DWORD *)v30 = 0;
                  }
                }
                v31 = *(_DWORD *)(v13 + 24);
                *(_DWORD *)(v13 + 20) = *(_DWORD *)(v13 + 28);
                v32 = v31;
                *(_DWORD *)(v13 + 16) = v31;
                if ( v31 >= 0 )
                {
                  v33 = *(_DWORD *)(v13 + 20);
                  if ( v33 >= 0 && v32 < 8 && v33 < 8 )
                    v2->m_Board[0][v33 + 8 * v32] = (TChessPiece<CBasePiece> *)v13;
                }
                if ( v16 )
                {
                  v34 = v16->m_CurPos.x;
                  if ( v34 >= 0 )
                  {
                    v35 = v16->m_CurPos.y;
                    if ( v35 >= 0 && v34 < 8 && v35 < 8 )
                    {
                      v36 = (int)((char *)v2->m_Board + 4 * (v35 + 8 * v34));
                      if ( *(TChessPiece<CBasePiece> **)v36 == v16 )
                        *(_DWORD *)v36 = 0;
                    }
                  }
                  v37 = v16->m_LastKnownGoodPos.x;
                  v16->m_CurPos.y = v16->m_LastKnownGoodPos.y;
                  v38 = v37;
                  v16->m_CurPos.x = v37;
                  if ( v37 >= 0 )
                  {
                    v39 = v16->m_CurPos.y;
                    if ( v39 >= 0 && v38 < 8 && v39 < 8 )
                      v2->m_Board[0][v39 + 8 * v38] = v16;
                  }
                }
                if ( !v27 )
                  return 0;
                v11 = Pos.x;
                v12 = Playera;
              }
              ++v12;
            }
            v40 = dword_822BBC[2 * Dir];
            v11 += (signed int)&(&Directions)[Dir]->x;
            v42 = __OFSUB__(ia + 1, Dist);
            v41 = ia + 1 - Dist < 0;
            Pos.x = v11;
            Pos.y += v40;
            ++ia;
          }
          while ( v41 ^ v42 );
        }
        return 1;
      }
    }
  }
  return 0;
}
// 822BB8: using guessed type struct TCoord *Directions;
// 822BBC: using guessed type int dword_822BBC[];

//----- (004A9B70) --------------------------------------------------------  // acclient.c:225308
void __cdecl gmMiniGameUI::MiniGameQuitDialogCallback(PropertyCollection *i_rcResults)
{
  unsigned int v1; // edx@1
  HashTableData<unsigned long,BaseProperty> **v2; // eax@1
  HashTableData<unsigned long,BaseProperty> *v3; // eax@1
  BasePropertyDesc *v4; // ecx@9
  unsigned int v5; // edx@9
  BasePropertyValue *v6; // ecx@13
  unsigned int v7; // edx@13
  int confirm; // [sp+4h] [bp-Ch]@1
  BaseProperty p; // [sp+8h] [bp-8h]@1

  v1 = 0x92 % i_rcResults->m_hashProperties.m_intrusiveTable.m_numBuckets;
  v2 = i_rcResults->m_hashProperties.m_intrusiveTable.m_buckets;
  LOBYTE(confirm) = 0;
  p.m_pcPropertyDesc = 0;
  p.m_pcPropertyValue = 0;
  v3 = v2[v1];
  if ( v3 )
  {
    while ( v3->m_hashKey != 146 )
    {
      v3 = v3->m_hashNext;
      if ( !v3 )
        return;
    }
    if ( v3 )
    {
      BaseProperty::operator=(&p, (int)&v3->m_data);
      if ( p.m_pcPropertyValue )
        ((void (__stdcall *)(int *))p.m_pcPropertyValue->vfptr[28].__vecDelDtor)(&confirm);
      CM_Game::SendNotice_TryToQuitGame(confirm);
      if ( (_DWORD)p.m_pcPropertyDesc )
      {
        v4 = p.m_pcPropertyDesc;
        v5 = p.m_pcPropertyDesc->m_cRef - 1;
        p.m_pcPropertyDesc->m_cRef = v5;
        if ( !v5 )
          ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
        p.m_pcPropertyDesc = 0;
      }
      if ( p.m_pcPropertyValue )
      {
        v6 = p.m_pcPropertyValue;
        v7 = p.m_pcPropertyValue->m_cRef - 1;
        p.m_pcPropertyValue->m_cRef = v7;
        if ( !v7 )
          ((void (__stdcall *)(signed int))v6->vfptr->__vecDelDtor)(1);
      }
    }
  }
}

//----- (004A9C30) --------------------------------------------------------  // acclient.c:225362
signed int __thiscall CChessLogic<CBasePiece>::ComputeCheckResult(CChessLogic<CBasePiece> *this, int Player)
{
  CChessLogic<CBasePiece> *v2; // edi@1
  signed int v3; // esi@1

  v2 = this;
  v3 = 0;
  if ( CChessLogic<CBasePiece>::IsPlayerInCheck(this, Player) )
    v3 = CChessLogic<CBasePiece>::IsPlayerInCheckMate(v2, Player) != 0 ? 2048 : 1024;
  v2->m_bLastMoveWasCheck = v3 > 1023;
  return v3;
}

//----- (004A9C80) --------------------------------------------------------  // acclient.c:225376
void __thiscall gmMiniGameUI::RecvNotice_OpponentOffersStalemate(gmMiniGameUI *this, unsigned int idGame, int iTeam, int fOn)
{
  ClientSystem *v4; // eax@3
  ClientSystem *v5; // eax@4

  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
  {
    if ( fOn )
    {
      v4 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(
        v4,
        "Your opponent has declared a stalemate.  To agree, press your stalemate button.\n",
        0,
        1,
        0);
    }
    else
    {
      v5 = (ClientSystem *)ClientUISystem::GetUISystem();
      ClientSystem::AddTextToScroll(v5, "Your opponent has retracted their offer of stalemate.\n", 0, 1, 0);
    }
  }
}

//----- (004A9CC0) --------------------------------------------------------  // acclient.c:225402
void __stdcall gmMiniGameUI::SetInfoText(const char *szText)
{
  ClientSystem *v2; // esi@1
  const char *v3; // esi@1

  v2 = (ClientSystem *)ClientUISystem::GetUISystem();
  PStringBase<unsigned short>::PStringBase<unsigned short>((PStringBase<unsigned short> *)&szText, 0, szText);
  ClientSystem::AddTextToScroll(v2, (PStringBase<unsigned short> *)&szText, 0, 1, 0);
  v3 = szText - 20;
  if ( !InterlockedDecrement((volatile LONG *)szText - 4) )
  {
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
}

//----- (004A9D10) --------------------------------------------------------  // acclient.c:225419
ChessMoveResult __thiscall GameBoardGrid::DoPromotion(GameBoardGrid *this, int x, int y, ChessMoveResult result)
{
  int v4; // ebp@1
  GameBoardGrid *v5; // esi@1
  char *v6; // ebx@1
  int v7; // ecx@1
  int v8; // edi@2
  int v9; // esi@2
  unsigned int v10; // eax@2
  int v11; // edx@2
  TQueenPiece<CBasePiece> *v12; // eax@7
  int v13; // eax@8
  int v14; // ebp@8
  TChessPiece<CBasePiece> *v15; // eax@11
  unsigned int v16; // eax@15
  unsigned int v17; // eax@17
  signed int v18; // eax@21
  ChessMoveResult v19; // eax@21
  CChessLogic<CBasePiece> *v20; // [sp+Ch] [bp-Ch]@1
  TCoord StartingPos; // [sp+10h] [bp-8h]@7

  v4 = y;
  v5 = this;
  v6 = (char *)this->m_Board + 4 * (y + 8 * x);
  v7 = *(_DWORD *)v6;
  v20 = (CChessLogic<CBasePiece> *)v5;
  if ( *(_DWORD *)v6 )
  {
    v8 = *(_DWORD *)(v7 + 12);
    v9 = (int)&v5->m_Pieces[v8];
    *(_DWORD *)v6 = 0;
    v10 = *(_DWORD *)v9;
    v11 = *(_DWORD *)v9 + 4 * *(_DWORD *)(v9 + 8);
    if ( *(_DWORD *)v9 < (unsigned int)v11 )
    {
      while ( *(_DWORD *)v10 != v7 )
      {
        v10 += 4;
        if ( v10 >= v11 )
          goto LABEL_7;
      }
      *(_DWORD *)v10 = *(_DWORD *)(v11 - 4);
      --*(_DWORD *)(v9 + 8);
    }
LABEL_7:
    operator delete((void *)v7);
    StartingPos.x = x;
    StartingPos.y = v4;
    v12 = (TQueenPiece<CBasePiece> *)operator new(0x24u);
    if ( v12 )
    {
      TQueenPiece<CBasePiece>::TQueenPiece<CBasePiece>(v12, v8, &StartingPos);
      v14 = v13;
    }
    else
    {
      v14 = 0;
    }
    x = v14;
    if ( v8 )
      v15 = v20[1].m_Board[1][3];
    else
      v15 = v20[1].m_Board[0][5];
    *(_DWORD *)(v14 + 4) = v15;
    *(_DWORD *)v6 = v14;
    if ( *(_DWORD *)(v14 + 8) == 6 )
    {
      AC1Legacy::SmartArray<TChessPiece<CBasePiece> *>::InsertOrderedByIndex(
        (AC1Legacy::SmartArray<TChessPiece<CBasePiece> *> *)v9,
        (TChessPiece<CBasePiece> *const *)&x,
        0);
    }
    else
    {
      v16 = *(_DWORD *)(v9 + 4);
      if ( *(_DWORD *)(v9 + 8) < v16
        || (!v16 ? (v17 = 8) : (v17 = 2 * v16),
            AC1Legacy::SmartArray<SkyTimeOfDay *>::grow((AC1Legacy::SmartArray<Season *> *)v9, v17)) )
        *(_DWORD *)(*(_DWORD *)v9 + 4 * (*(_DWORD *)(v9 + 8))++) = v14;
    }
    v18 = CChessLogic<CBasePiece>::ComputeCheckResult(v20, v8 == 0);
    v19 = v18 | result;
  }
  else
  {
    v19 = result;
  }
  return v19;
}

//----- (004A9E40) --------------------------------------------------------  // acclient.c:225510
signed int __thiscall CChessLogic<CBasePiece>::Move(CChessLogic<CBasePiece> *this, TCoord *From, TCoord *To)
{
  int v3; // edi@1
  CChessLogic<CBasePiece> *v4; // esi@1
  int v5; // eax@2
  TCoord *v6; // ebx@5
  int v7; // ebp@5
  int v8; // eax@6
  TChessPiece<CBasePiece> *v10; // edi@11
  int v11; // ecx@11
  signed int v12; // ebp@18
  signed int v13; // eax@19
  __int64 v14; // rax@24
  __int64 v15; // rax@25
  int v16; // ebx@26
  int v17; // eax@29
  int v18; // [sp+10h] [bp-4h]@2
  TCoord *Toa; // [sp+1Ch] [bp+8h]@11

  v3 = From->x;
  v4 = this;
  if ( From->x >= 0 )
  {
    v5 = From->y;
    v18 = From->y;
    if ( v5 >= 0 && v3 < 8 && v5 < 8 )
    {
      v6 = To;
      v7 = To->x;
      if ( To->x >= 0 )
      {
        v8 = To->y;
        if ( v8 >= 0 && v7 < 8 && v8 < 8 )
        {
          if ( !CChessLogic<CBasePiece>::SanityCheckBoard(this) )
            return -111;
          v10 = v4->m_Board[0][v18 + 8 * v3];
          v11 = To->y;
          Toa = (TCoord *)v4->m_Board[0][v11 + 8 * v7];
          if ( !v10 )
            return -102;
          if ( v10->m_Player != v4->m_CurPlayer )
            return -103;
          if ( v10->m_Type != 6 || abs(v7 - From->x) != 2 || v11 != From->y )
          {
            v13 = CChessLogic<CBasePiece>::TestMoveAndSelfCheck(v4, v10, v6);
            v12 = v13;
            if ( v13 <= 0 )
              return v12;
            if ( (v13 & 0x3FF) == 3 )
              Toa = (TCoord *)v4->m_Board[0][v4->m_EnPassantVictimPos.y + 8 * v4->m_EnPassantVictimPos.x];
          }
          else
          {
            v12 = CChessLogic<CBasePiece>::HandleCastling(v4, v10, v6);
          }
          if ( v12 > 0 )
          {
            CChessLogic<CBasePiece>::CommitPiecePos(v4, v10, *v6);
            CChessLogic<CBasePiece>::CommitPiecePos(v4, (TChessPiece<CBasePiece> *)Toa, HEAVEN);
            v4->m_EnPassantAttackSite = HEAVEN;
            if ( v10->m_Type == 1 )
            {
              v14 = v6->y - From->y;
              if ( (HIDWORD(v14) ^ (unsigned int)v14) - HIDWORD(v14) == 2 )
              {
                v4->m_EnPassantAttackSite.x = From->x;
                v15 = v6->y + From->y;
                v4->m_EnPassantAttackSite.y = ((signed int)v15 - HIDWORD(v15)) >> 1;
                v4->m_EnPassantVictimPos.x = v6->x;
                v4->m_EnPassantVictimPos.y = v6->y;
              }
              v16 = v6->y;
              if ( !v16 || v16 == 7 )
                v12 |= 0x1000u;
            }
            v17 = v4->m_CurPlayer == 0;
            v4->m_CurPlayer = v17;
            v12 |= CChessLogic<CBasePiece>::ComputeCheckResult(v4, v17);
            if ( Toa )
            {
              v4->vfptr->AttackPiece(v4, v10, (TChessPiece<CBasePiece> *)Toa);
              return v12;
            }
            v4->vfptr->MovePiece(v4, v10);
          }
          return v12;
        }
      }
    }
  }
  return -104;
}

//----- (004AA060) --------------------------------------------------------  // acclient.c:225605
void __thiscall gmMiniGameUI::RecvNotice_JoinGameResponse(gmMiniGameUI *this, unsigned int idGame, int iTeam)
{
  gmMiniGameUI *v3; // esi@1
  GameBoardGrid *v4; // ecx@5

  v3 = this;
  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]
    && this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)1 )
  {
    if ( iTeam == -1 )
    {
      gmMiniGameUI::SetInfoText("You could not join that game.\n");
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = 0;
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] = 0;
    }
    else
    {
      gmMiniGameUI::SetInfoText("You have joined the game, waiting for all players to be ready.\n");
      v4 = (GameBoardGrid *)v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5];
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)2;
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] = (HashSetData<UIElement *> *)iTeam;
      GameBoardGrid::Reset(v4);
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[4] = 0;
    }
  }
}

//----- (004AA0D0) --------------------------------------------------------  // acclient.c:225633
void __thiscall gmMiniGameUI::RecvNotice_StartGame(gmMiniGameUI *this, unsigned int idGame, int iTeam)
{
  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]
    && this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)2 )
  {
    if ( (HashSetData<UIElement *> *)iTeam == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] )
    {
      this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)3;
      gmMiniGameUI::SetInfoText("The game has begun, it is your turn to move.\n");
    }
    else
    {
      this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)5;
      gmMiniGameUI::SetInfoText("The game has begun, waiting for your opponent to move.\n");
    }
  }
}

//----- (004AA120) --------------------------------------------------------  // acclient.c:225652
char __thiscall gmMiniGameUI::TryToJoinGame(gmMiniGameUI *this, unsigned int idGame)
{
  gmMiniGameUI *v2; // esi@1
  unsigned int v3; // ecx@1
  char *v4; // esi@2
  char *v5; // esi@7
  UIElement_Button *v7; // ecx@12
  PStringBase<unsigned short> _value; // [sp+4h] [bp-94h]@2
  StringInfo siError; // [sp+8h] [bp-90h]@2

  v2 = this;
  v3 = this->m_idCurrentGame;
  if ( v3 == idGame )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You are already playing this game.");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v4 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_11:
    StringInfo::~StringInfo(&siError);
    return 0;
  }
  if ( v3 )
  {
    StringInfo::StringInfo(&siError);
    PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You are already playing another game.");
    StringInfo::SetLiteralValue(&siError, &_value, 1);
    v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
    if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v5 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    goto LABEL_11;
  }
  v2->m_idCurrentGame = idGame;
  v2->m_state = 1;
  CM_Game::Event_Join(idGame, 0xFFFFFFFF);
  v7 = v2->m_pResignButton;
  if ( v7 )
    ((void (__stdcall *)(signed int))v7->vfptr[13].__vecDelDtor)(1);
  gmMiniGameUI::SetInfoText("Attempting to join game, please wait...\n");
  return 1;
}

//----- (004AA240) --------------------------------------------------------  // acclient.c:225702
void __stdcall gmMiniGameUI::ShowMoveResult(int cmr)
{
  __int16 v2; // si@1
  int v3; // esi@6
  int v4; // eax@6
  int v5; // esi@26
  int v6; // eax@26
  int v7; // esi@31
  int v8; // eax@31
  AC1Legacy::PSRefBuffer<char> *v9; // esi@36
  AC1Legacy::PStringBase<char> str; // [sp+8h] [bp-4h]@1

  str.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  v2 = cmr;
  if ( cmr <= 0 )
  {
    switch ( cmr )
    {
      case -3:
        gmMiniGameUI::SetInfoText("Its not your turn, please wait for your opponents move.\n");
        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&str);
        return;
      case -100:
        AC1Legacy::PStringBase<char>::set(&str, "The selected piece cannot move that direction");
        break;
      case -101:
        AC1Legacy::PStringBase<char>::set(&str, "The selected piece cannot move that far");
        break;
      case -102:
        AC1Legacy::PStringBase<char>::set(&str, "You tried to move an empty square");
        break;
      case -103:
        AC1Legacy::PStringBase<char>::set(&str, "The selected piece is not yours");
        break;
      case -104:
        AC1Legacy::PStringBase<char>::set(&str, "You cannot move off the board");
        break;
      case -105:
        AC1Legacy::PStringBase<char>::set(&str, "You cannot attack your own pieces");
        break;
      case -106:
        AC1Legacy::PStringBase<char>::set(&str, "That move would put you in check");
        break;
      case -107:
        AC1Legacy::PStringBase<char>::set(&str, "You can only move through empty squares");
        break;
      case -108:
        AC1Legacy::PStringBase<char>::set(&str, "You cannot castle out of check");
        break;
      case -109:
        AC1Legacy::PStringBase<char>::set(&str, "You cannot castle through check");
        break;
      case -110:
        AC1Legacy::PStringBase<char>::set(&str, "You cannot castle after moving the King or Rook");
        break;
      default:
        AC1Legacy::PStringBase<char>::set(&str, "That move is invalid");
        break;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&cmr, ", try again.  ");
    v5 = cmr;
    v6 = *(_DWORD *)(cmr + 8);
    if ( v6 != 1 && cmr != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&str, (const char *)(cmr + 20), v6 - 1);
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&cmr, "It is your turn to move.\n");
    v7 = cmr;
    v8 = *(_DWORD *)(cmr + 8);
    if ( v8 != 1 && cmr != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&str, (const char *)(cmr + 20), v8 - 1);
    if ( !InterlockedDecrement((volatile LONG *)(v7 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v7)(v7, 1);
  }
  else if ( cmr & 0x800 )
  {
    AC1Legacy::PStringBase<char>::set(&str, "You have checkmated your opponent!\n");
  }
  else
  {
    AC1Legacy::PStringBase<char>::set(&str, "Move in progress.");
    if ( v2 & 0x400 )
      AC1Legacy::PStringBase<char>::PStringBase<char>(
        (AC1Legacy::PStringBase<char> *)&cmr,
        "  Your opponent is in Check.\n");
    else
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&cmr, "\n");
    v3 = cmr;
    v4 = *(_DWORD *)(cmr + 8);
    if ( v4 != 1 && cmr != AC1Legacy::PStringBase<char>::s_NullBuffer )
      AC1Legacy::PStringBase<char>::append_n_chars(&str, (const char *)(cmr + 20), v4 - 1);
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
  }
  v9 = str.m_buffer;
  gmMiniGameUI::SetInfoText(str.m_buffer->m_data);
  if ( !InterlockedDecrement((volatile LONG *)&v9->m_cRef) )
  {
    if ( v9 )
      v9->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v9, 1u);
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004AA4D0) --------------------------------------------------------  // acclient.c:225808
void __stdcall gmMiniGameUI::ShowOpponentMoveResult(int cmr)
{
  __int16 v2; // si@1
  int v3; // edi@3
  AC1Legacy::PSRefBuffer<char> *v4; // esi@5
  unsigned int v5; // eax@5
  AC1Legacy::PStringBase<char> v6; // [sp+8h] [bp-4h]@5

  v2 = cmr;
  if ( cmr & 0x800 )
  {
    gmMiniGameUI::SetInfoText("You have been checkmated!\n");
  }
  else
  {
    v3 = AC1Legacy::PStringBase<char>::s_NullBuffer;
    cmr = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    if ( v2 & 0x400 )
    {
      AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&cmr, "You are in check!  ");
      v3 = cmr;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v6, "It is your turn to move.\n");
    v4 = v6.m_buffer;
    v5 = v6.m_buffer->m_len;
    if ( v5 != 1 && v6.m_buffer != (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      AC1Legacy::PStringBase<char>::append_n_chars((AC1Legacy::PStringBase<char> *)&cmr, v6.m_buffer->m_data, v5 - 1);
      v3 = cmr;
    }
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    gmMiniGameUI::SetInfoText((const char *)(v3 + 20));
    if ( !InterlockedDecrement((volatile LONG *)(v3 + 4)) )
    {
      if ( v3 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v3)(v3, 1);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004AA5A0) --------------------------------------------------------  // acclient.c:225852
void __thiscall gmMiniGameUI::GotoDefaultState(gmMiniGameUI *this, const char *szText)
{
  gmMiniGameUI *v2; // esi@1
  UIElement_Button *v3; // ecx@1
  GameBoardGrid *v4; // eax@3

  v2 = this;
  this->m_idCurrentGame = 0;
  this->m_state = 0;
  this->m_iTeam = -1;
  this->m_fStalemate = 0;
  gmMiniGameUI::SetInfoText(szText);
  v3 = v2->m_pStalemateButton;
  if ( v3 )
    ((void (__stdcall *)(signed int))v3->vfptr[13].__vecDelDtor)(1);
  v4 = v2->m_pGameBoard;
  v4->m_CurPlayer = 0;
  v4->m_bLastMoveWasCheck = 0;
  v4->m_EnPassantAttackSite.x = -1;
  v4->m_EnPassantAttackSite.y = -1;
  v4->m_EnPassantVictimPos.x = -1;
  v4->m_EnPassantVictimPos.y = -1;
  v4->m_coordSelected.x = -1;
  v4->m_coordSelected.y = -1;
}

//----- (004AA620) --------------------------------------------------------  // acclient.c:225879
void __thiscall GameBoardGrid::HandleMousePresses(GameBoardGrid *this, UIElementMessageInfo *i_rMsg)
{
  int v2; // esi@1
  int v3; // edi@1
  GameBoardGrid *v4; // ebp@1
  UIElement_ListBox *v5; // ecx@2
  UIElement *v6; // eax@3
  signed int v7; // eax@4
  gmMiniGameUI *v8; // eax@10
  int *v9; // ebx@15
  int v10; // eax@17
  int v11; // ecx@20
  gmMiniGameUI *v12; // ecx@20
  gmMiniGameUI *v13; // ecx@21
  TChessPiece<CBasePiece> *v14; // eax@23
  int v15; // eax@25
  TCoord coord; // [sp+10h] [bp-8h]@14
  UIElementMessageInfo *i_rMsga; // [sp+1Ch] [bp+4h]@11
  int i_rMsgb; // [sp+1Ch] [bp+4h]@17

  v2 = -1;
  v3 = -1;
  v4 = this;
  if ( i_rMsg->idElement == 268435828 )
  {
    v5 = this->m_pieceListBox;
    if ( v5 )
    {
      v6 = UIElement_ListBox::GetItemUnderMouse(v5);
      if ( v6 )
      {
        v7 = UIElement_ListBox::WhatNum(v4->m_pieceListBox, v6);
        v2 = v7 % 8;
        v3 = v7 / 8;
      }
    }
  }
  if ( i_rMsg->dwParam1 == 7 && v2 >= 0 && v2 <= 7 && v3 >= 0 && v3 <= 7 )
  {
    v8 = v4->m_gameUI;
    if ( v8->m_state == 3 )
    {
      i_rMsga = (UIElementMessageInfo *)v8->m_iTeam;
      if ( i_rMsga )
        v2 = 7 - v2;
      else
        v3 = 7 - v3;
      coord.x = v2;
      coord.y = v3;
      if ( TCoord::IsValid(&coord) )
      {
        v9 = &v4->m_coordSelected.x;
        if ( TCoord::IsValid(&v4->m_coordSelected) )
        {
          if ( TCoord::operator!=(&v4->m_coordSelected, &coord) )
          {
            GameBoardGrid::PrepareNewMove(v4);
            v10 = CChessLogic<CBasePiece>::Move((CChessLogic<CBasePiece> *)&v4->vfptr, &v4->m_coordSelected, &coord);
            i_rMsgb = v10;
            if ( v10 <= 0 )
            {
              *v9 = -1;
              v4->m_coordSelected.y = -1;
              v13 = v4->m_gameUI;
              gmMiniGameUI::ShowMoveResult(v10);
              GameBoardGrid::Draw(v4);
            }
            else
            {
              if ( BYTE1(v10) & 0x10 )
                i_rMsgb = GameBoardGrid::DoPromotion(v4, v2, v3, (ChessMoveResult)v10);
              gmMiniGameUI::DoMove(v4->m_gameUI, *v9, v4->m_coordSelected.y, v2, v3);
              v11 = coord.y;
              *v9 = coord.x;
              v4->m_coordSelected.y = v11;
              v12 = v4->m_gameUI;
              gmMiniGameUI::ShowMoveResult(i_rMsgb);
              GameBoardGrid::Draw(v4);
            }
          }
          else
          {
            *v9 = -1;
            v4->m_coordSelected.y = -1;
            GameBoardGrid::Draw(v4);
          }
        }
        else
        {
          v14 = v4->m_Board[0][v3 + 8 * v2];
          if ( v14 && (UIElementMessageInfo *)v14->m_Player == i_rMsga )
          {
            v15 = coord.y;
            *v9 = coord.x;
            v4->m_coordSelected.y = v15;
            GameBoardGrid::Draw(v4);
          }
        }
      }
    }
  }
}

//----- (004AA810) --------------------------------------------------------  // acclient.c:225983
void __thiscall GameBoardGrid::OpponentMove(GameBoardGrid *this, GameMoveData *move)
{
  int v2; // edx@1
  GameBoardGrid *v3; // esi@1
  int v4; // ecx@1
  int v5; // eax@1
  int v6; // ebx@1
  gmMiniGameUI *v7; // ecx@4
  TCoord to; // [sp+Ch] [bp-10h]@1
  TCoord from; // [sp+14h] [bp-8h]@1

  v2 = move->m_xTo;
  v3 = this;
  v4 = move->m_yGrid;
  from.x = move->m_xGrid;
  v5 = move->m_yTo;
  from.y = v4;
  to.x = v2;
  to.y = v5;
  GameBoardGrid::PrepareNewMove(v3);
  v6 = CChessLogic<CBasePiece>::Move((CChessLogic<CBasePiece> *)&v3->vfptr, &from, &to);
  GameBoardGrid::CommitMoves(v3);
  if ( v6 > 0 )
  {
    if ( BYTE1(v6) & 0x10 )
      v6 = GameBoardGrid::DoPromotion(v3, move->m_xTo, move->m_yTo, (ChessMoveResult)v6);
    v7 = v3->m_gameUI;
    gmMiniGameUI::ShowOpponentMoveResult(v6);
    GameBoardGrid::Draw(v3);
  }
}

//----- (004AA890) --------------------------------------------------------  // acclient.c:226016
void __thiscall gmMiniGameUI::RecvNotice_BeginGame(gmMiniGameUI *this, unsigned int idGame)
{
  gmMiniGameUI *v2; // esi@1

  v2 = (gmMiniGameUI *)((char *)this - 1528);
  ((void (__thiscall *)(_DWORD, _DWORD))this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7][3].m_hashKey)(
    &this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7],
    1);
  gmMiniGameUI::TryToJoinGame(v2, idGame);
}

//----- (004AA8C0) --------------------------------------------------------  // acclient.c:226028
void __thiscall gmMiniGameUI::RecvNotice_MoveResponse(gmMiniGameUI *this, unsigned int idGame, int iMoveResult)
{
  gmMiniGameUI *v3; // esi@1
  GameBoardGrid *v4; // ecx@3

  v3 = this;
  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]
    && this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)4 )
  {
    v4 = (GameBoardGrid *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5];
    if ( iMoveResult <= 0 )
    {
      GameBoardGrid::UndoMoves(v4);
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)3;
      gmMiniGameUI::ShowMoveResult(iMoveResult);
    }
    else
    {
      GameBoardGrid::CommitMoves(v4);
      v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)5;
      gmMiniGameUI::SetInfoText("Waiting for your opponent to move.\n");
    }
  }
}

//----- (004AA920) --------------------------------------------------------  // acclient.c:226054
void __thiscall gmMiniGameUI::RecvNotice_OpponentTurn(gmMiniGameUI *this, unsigned int idGame, int iTeam, GameMoveData *move)
{
  gmMiniGameUI *v4; // esi@1

  v4 = this;
  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2]
    && this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] == (HashSetData<UIElement *> *)5 )
  {
    GameBoardGrid::OpponentMove(
      (GameBoardGrid *)this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[5],
      move);
    v4->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[3] = (HashSetData<UIElement *> *)3;
  }
}

//----- (004AA950) --------------------------------------------------------  // acclient.c:226070
void __thiscall gmMiniGameUI::RecvNotice_GameOver(gmMiniGameUI *this, unsigned int idGame, int iTeamWinner)
{
  gmMiniGameUI *v3; // ebp@1
  unsigned int v4; // edi@2
  int v5; // esi@10
  int v6; // eax@10

  v3 = this;
  if ( (HashSetData<UIElement *> *)idGame == this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[2] )
  {
    v4 = AC1Legacy::PStringBase<char>::s_NullBuffer;
    idGame = AC1Legacy::PStringBase<char>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
    if ( iTeamWinner == -2 )
    {
      CM_Game::SendNotice_EndGame();
    }
    else
    {
      if ( iTeamWinner == -1 )
      {
        AC1Legacy::PStringBase<char>::set(
          (AC1Legacy::PStringBase<char> *)&idGame,
          "The game has ended in a stalemate.  ");
      }
      else if ( (HashSetData<UIElement *> *)iTeamWinner == v3->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[1] )
      {
        AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&idGame, "You are victorious!  ");
      }
      else
      {
        AC1Legacy::PStringBase<char>::set((AC1Legacy::PStringBase<char> *)&idGame, "You have been defeated!  ");
      }
      v4 = idGame;
    }
    AC1Legacy::PStringBase<char>::PStringBase<char>(
      (AC1Legacy::PStringBase<char> *)&iTeamWinner,
      "To join a game, select and use the game board.\n");
    v5 = iTeamWinner;
    v6 = *(_DWORD *)(iTeamWinner + 8);
    if ( v6 != 1 && iTeamWinner != AC1Legacy::PStringBase<char>::s_NullBuffer )
    {
      AC1Legacy::PStringBase<char>::append_n_chars(
        (AC1Legacy::PStringBase<char> *)&idGame,
        (const char *)(iTeamWinner + 20),
        v6 - 1);
      v4 = idGame;
    }
    if ( !InterlockedDecrement((volatile LONG *)(v5 + 4)) )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
    gmMiniGameUI::GotoDefaultState((gmMiniGameUI *)((char *)v3 - 1528), (const char *)(v4 + 20));
    if ( !InterlockedDecrement((volatile LONG *)(v4 + 4)) )
    {
      if ( v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
    }
  }
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (004AAA30) --------------------------------------------------------  // acclient.c:226131
int __thiscall gmMiniGameUI::ListenToElementMessage(gmMiniGameUI *this, UIElementMessageInfo *i_rMsg)
{
  unsigned int v2; // eax@1
  gmMiniGameUI *v3; // esi@1
  int v4; // ST04_4@6
  StringInfo *v6; // ecx@11
  GameBoardGrid *v7; // ecx@22
  BaseProperty p; // [sp+Ch] [bp-134h]@14
  PStringBase<unsigned short> v9; // [sp+14h] [bp-12Ch]@14
  PStringBase<unsigned short> v10; // [sp+18h] [bp-128h]@10
  PStringBase<unsigned short> _value; // [sp+1Ch] [bp-124h]@7
  StringInfo siError; // [sp+20h] [bp-120h]@7
  StringInfo v13; // [sp+B0h] [bp-90h]@14

  v2 = i_rMsg->idMessage;
  v3 = this;
  if ( v2 == 1 )
  {
    if ( i_rMsg->idElement == 268435829 )
    {
      if ( !this->m_uiResignDialogContext )
      {
        StringInfo::StringInfo(&v13);
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          &v9,
          L"If a game is in progress, resigning will be recorded as your loss. Are you sure you want to resign?");
        StringInfo::SetLiteralValue(&v13, &v9, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v9);
        PropertyCollection::PropertyCollection((PropertyCollection *)&siError);
        p.m_pcPropertyDesc = 0;
        p.m_pcPropertyValue = 0;
        BaseProperty::SetPropertyName(&p, 0x8Eu);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
        }
        PropertyCollection::AddProperty((PropertyCollection *)&siError, &p);
        BaseProperty::SetPropertyName(&p, 0xC3u);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[43].__vecDelDtor)(1);
        }
        PropertyCollection::AddProperty((PropertyCollection *)&siError, &p);
        BaseProperty::SetPropertyName(&p, 0xC5u);
        if ( p.m_pcPropertyValue )
        {
          BaseProperty::CheckCopyOnWrite(&p);
          ((void (__stdcall *)(_DWORD))p.m_pcPropertyValue->vfptr[49].__vecDelDtor)(&v13);
        }
        PropertyCollection::AddProperty((PropertyCollection *)&siError, &p);
        v3->m_uiResignDialogContext = DialogFactory::MakeCallbackDialogInCurrentUI(
                                        (PropertyCollection *)&siError,
                                        gmMiniGameUI::MiniGameQuitDialogCallback);
        BaseProperty::~BaseProperty(&p);
        PropertyCollection::~PropertyCollection((PropertyCollection *)&siError);
        v6 = &v13;
        goto LABEL_12;
      }
    }
    else
    {
      if ( i_rMsg->idElement == 268435830 )
      {
        if ( this->m_idCurrentGame )
        {
          CM_Game::Event_MovePass();
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&v10, L"You are not currently playing a game.");
        StringInfo::SetLiteralValue(&siError, &v10, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&v10);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
        goto LABEL_11;
      }
      if ( i_rMsg->idElement == 268435831 )
      {
        if ( this->m_idCurrentGame )
        {
          v4 = this->m_fStalemate == 0;
          this->m_fStalemate = v4;
          CM_Game::Event_Stalemate(v4);
          return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
        }
        StringInfo::StringInfo(&siError);
        PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"You are not currently playing a game.");
        StringInfo::SetLiteralValue(&siError, &_value, 1);
        PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_value);
        ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_11:
        v6 = &siError;
LABEL_12:
        StringInfo::~StringInfo(v6);
        return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
      }
    }
  }
  else if ( v2 == 28 )
  {
    v7 = this->m_pGameBoard;
    if ( v7 )
      GameBoardGrid::HandleMousePresses(v7, i_rMsg);
  }
  return UIElement::ListenToElementMessage((UIElement *)&v3->vfptr, i_rMsg);
}

//----- (004AACD0) --------------------------------------------------------  // acclient.c:226240
void __thiscall gmMiniGameUI::RecvNotice_TryToQuitGame(gmMiniGameUI *this, bool bQuitting)
{
  char *v2; // esi@2

  this->m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[6] = 0;
  if ( bQuitting )
  {
    v2 = (char *)&this[-1].m_hashElementsRegisteredWith.m_intrusiveTable.m_aInplaceBuckets[7];
    CM_Game::Event_Quit();
    if ( *((_DWORD *)v2 + 387) )
    {
      gmMiniGameUI::GotoDefaultState((gmMiniGameUI *)v2, "To join a game, select and use the game board.\n");
      CM_Game::SendNotice_EndGame();
    }
  }
}

//----- (006F1420) --------------------------------------------------------  // acclient.c:773483
void _E91_75()
{
  outside_val_67 = 1000.0 + 1.0;
}

//----- (006F1440) --------------------------------------------------------  // acclient.c:773489
void _E93_51()
{
  block_length_67 = 24.0 * 8.0;
}

//----- (006F1460) --------------------------------------------------------  // acclient.c:773495
void _E95_51()
{
  half_square_length_67 = 24.0 * 0.5;
}

//----- (006F1480) --------------------------------------------------------  // acclient.c:773501
int _E97_76()
{
  return atexit(_E98_88);
}

//----- (006F1490) --------------------------------------------------------  // acclient.c:773507
int _E100_69()
{
  return atexit(nullsub_820);
}

//----- (006F14A0) --------------------------------------------------------  // acclient.c:773513
int _E103_61()
{
  return atexit(_E104_76);
}

//----- (006F14B0) --------------------------------------------------------  // acclient.c:773519
void _E109_29()
{
  DEFAULT_VIEW_RADIUS_39 = 0.00019999999 * 3.0 + 0.1;
}

//----- (006F14D0) --------------------------------------------------------  // acclient.c:773525
void _E111_18()
{
  MIN_QUANTUM_39 = 1.0 / 30.0;
}

//----- (006F14F0) --------------------------------------------------------  // acclient.c:773531
void _E113_6()
{
  MAX_QUANTUM_39 = 1.0 / 5.0;
}

//----- (006F1510) --------------------------------------------------------  // acclient.c:773537
void _E115_33()
{
  PixelFormatDesc::PixelFormatDesc(&PixelFormatDesc_A8R8G8B8_74, PFID_A8R8G8B8);
}

//----- (006F1520) --------------------------------------------------------  // acclient.c:773543
void _E118_34()
{
  LOWEST_DATA_RATE_77 = 1024;
}

//----- (006F1530) --------------------------------------------------------  // acclient.c:773549
void _E120_24()
{
  HIGHEST_DATA_RATE_77 = 0x7FFF;
}

//----- (006F1540) --------------------------------------------------------  // acclient.c:773555
int _E122_10()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_77;
  INITIAL_MAX_DATA_RATE_25 = LOWEST_DATA_RATE_77;
  return result;
}

//----- (006F1550) --------------------------------------------------------  // acclient.c:773565
int _E124_34()
{
  return atexit(_E125_42);
}

//----- (006F1560) --------------------------------------------------------  // acclient.c:773571
int sub_6F1560()
{
  return atexit(nullsub_818);
}

