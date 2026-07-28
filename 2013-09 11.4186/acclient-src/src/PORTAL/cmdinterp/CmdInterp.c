/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CmdInterp
   Object     : PORTAL\cmdinterp\CmdInterp.obj
   Functions  : 77
   Addresses  : 006B3140 - 00790A40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B3140) --------------------------------------------------------  // acclient.c:716821
void __thiscall CommandInterpreter::SetSmartBox(CommandInterpreter *this, SmartBox *i_smartbox)
{
  this->smartbox = i_smartbox;
  if ( i_smartbox )
    this->player = i_smartbox->player;
  else
    this->player = 0;
}

//----- (006B3170) --------------------------------------------------------  // acclient.c:716831
void __thiscall CommandInterpreter::LoseControlToServer(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  IInputActionCallbackVtbl *v2; // eax@2

  v1 = this;
  if ( this->autonomy_level )
  {
    v2 = this->vfptr;
    this->controlled_by_server = 1;
    ((void (__stdcall *)(_DWORD, _DWORD))v2[17].__vecDelDtor)(0, 0);
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnLoseFocus)(v1);
  }
}

//----- (006B31A0) --------------------------------------------------------  // acclient.c:716847
void __thiscall CommandInterpreter::ClearAllCommands(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1

  v1 = this;
  CommandList::ClearAllCommands(&this->SubstateList);
  CommandList::ClearAllCommands(&v1->TurnList);
  CommandList::ClearAllCommands(&v1->SidestepList);
}

//----- (006B31C0) --------------------------------------------------------  // acclient.c:716858
void __thiscall CommandInterpreter::NewPlayer(CommandInterpreter *this, int autonomous_movement)
{
  this->player = this->smartbox->player;
  if ( autonomous_movement )
    ((void (*)(void))this->vfptr[2].OnAction)();
  else
    ((void (*)(void))this->vfptr[8].OnAction)();
}

//----- (006B31F0) --------------------------------------------------------  // acclient.c:716868
void __thiscall CommandInterpreter::LoseKeyboardFocus(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  IInputActionCallbackVtbl *v2; // edx@1

  v1 = this;
  CommandList::ClearKeyboardCommands(&this->SubstateList);
  CommandList::ClearKeyboardCommands(&v1->TurnList);
  CommandList::ClearKeyboardCommands(&v1->SidestepList);
  ((void (__thiscall *)(CommandInterpreter *, _DWORD))v1->vfptr[2].OnLoseFocus)(v1, 0);
  v2 = v1->vfptr;
  v1->hold_sidestep = 0;
  ((void (__thiscall *)(CommandInterpreter *))v2[6].OnLoseFocus)(v1);
  if ( v1->autonomy_level )
  {
    if ( !v1->controlled_by_server )
    {
      ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[2].OnAction)(v1);
      ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnAction)(v1);
    }
  }
}

//----- (006B3250) --------------------------------------------------------  // acclient.c:716892
void __thiscall CommandInterpreter::Disable(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  bool v2; // zf@1

  v1 = this;
  ((void (*)(void))this->vfptr[3].OnAction)();
  ((void (__thiscall *)(CommandInterpreter *, _DWORD))v1->vfptr[2].OnLoseFocus)(v1, 0);
  v2 = v1->autonomy_level == 0;
  v1->hold_sidestep = 0;
  if ( !v2 && v1->player && !v1->controlled_by_server )
  {
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[2].OnAction)(v1);
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnAction)(v1);
  }
  v1->enabled = 0;
}

//----- (006B3290) --------------------------------------------------------  // acclient.c:716911
void __thiscall CommandInterpreter::Enable(CommandInterpreter *this)
{
  IInputActionCallbackVtbl *v1; // eax@1
  int v2; // ST00_4@1

  v1 = this->vfptr;
  v2 = this->hold_run;
  this->enabled = 1;
  ((void (__stdcall *)(int))v1[2].OnLoseFocus)(v2);
}

//----- (006B32B0) --------------------------------------------------------  // acclient.c:716923
void __thiscall CommandInterpreter::PlayerTeleported(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1

  v1 = this;
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[17].__vecDelDtor)(0, 1);
  ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnAction)(v1);
}

//----- (006B32D0) --------------------------------------------------------  // acclient.c:716933
void __thiscall CommandInterpreter::TakeControlFromServer(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // eax@4

  v1 = this;
  if ( this->controlled_by_server && this->autonomy_level && !((int (*)(void))this->vfptr[10].__vecDelDtor)() )
  {
    v1->controlled_by_server = 0;
    v2 = v1->player;
    if ( v2 )
    {
      v2->last_move_was_autonomous = 1;
      CPhysicsObj::StopCompletely(v1->player, 1);
      CPhysicsObj::StopInterpolating(v1->player);
    }
    ((void (__thiscall *)(CommandInterpreter *, _DWORD))v1->vfptr[2].OnLoseFocus)(v1, v1->hold_run);
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[2].OnAction)(v1);
  }
}

//----- (006B3330) --------------------------------------------------------  // acclient.c:716955
void __thiscall CommandInterpreter::HandleLogOff(CommandInterpreter *this)
{
  ((void (*)(void))this->vfptr[11].__vecDelDtor)();
}

//----- (006B3340) --------------------------------------------------------  // acclient.c:716961
void __thiscall CommandInterpreter::ApplyHoldKeysToCommand(CommandInterpreter *this, unsigned int *cmd, float *speed)
{
  if ( this->hold_sidestep )
  {
    if ( *cmd == 1694498829 )
    {
      *cmd = 1694498831;
    }
    else if ( *cmd == 1694498830 )
    {
      *cmd = 1694498832;
    }
  }
}

//----- (006B3370) --------------------------------------------------------  // acclient.c:716977
void __thiscall CommandInterpreter::SetHoldRun(CommandInterpreter *this, int new_value)
{
  CommandInterpreter *v2; // esi@1
  IInputActionCallbackVtbl *v3; // edx@3
  int v4; // eax@3
  int v5; // ST04_4@4
  CMotionInterp *v6; // eax@4

  v2 = this;
  if ( this->smartbox && this->player )
  {
    v3 = this->vfptr;
    this->hold_run = new_value != 0;
    v4 = (this->hold_run == 0) != (((int (*)(void))v3[5].__vecDelDtor)() == 0);
    if ( v2->autonomy_level )
    {
      v5 = v4;
      v6 = CPhysicsObj::get_minterp(v2->player);
      CMotionInterp::set_hold_run(v6, v5, 1);
    }
    else if ( v4 )
    {
      ((void (__thiscall *)(CommandInterpreter *, signed int, signed int, _DWORD))v2->vfptr[19].OnAction)(
        v2,
        -2063597567,
        1065353216,
        0);
    }
    else
    {
      ((void (__thiscall *)(CommandInterpreter *, signed int, _DWORD))v2->vfptr[19].OnLoseFocus)(v2, -2063597567, 0);
    }
  }
}

//----- (006B3410) --------------------------------------------------------  // acclient.c:717013
void __thiscall CommandInterpreter::SetHoldSidestep(CommandInterpreter *this, int new_value)
{
  CommandInterpreter *v2; // esi@1
  IInputActionCallbackVtbl *v3; // eax@1

  v2 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[4].__vecDelDtor)(&this->TurnList);
  v3 = v2->vfptr;
  v2->hold_sidestep = new_value;
  ((void (__thiscall *)(CommandInterpreter *))v3[2].OnAction)(v2);
}

//----- (006B3430) --------------------------------------------------------  // acclient.c:717026
void __usercall CommandInterpreter::ApplyCurrentMovement(CommandInterpreter *this@<ecx>, int a2@<edi>)
{
  CommandInterpreter *v2; // esi@1
  signed int v3; // [sp-18h] [bp-1Ch]@3
  float v4; // [sp-10h] [bp-14h]@3
  signed int v5; // [sp-Ch] [bp-10h]@3
  signed int v6; // [sp-8h] [bp-Ch]@3

  v2 = this;
  if ( !this->player )
    return;
  if ( this->auto_run )
  {
    v6 = 1;
    v5 = 1;
    v4 = this->autorun_speed;
    v3 = 1157627909;
LABEL_8:
    ((void (__thiscall *)(CommandInterpreter *, signed int, signed int, float, signed int, signed int))v2->vfptr[13].OnAction)(
      v2,
      v3,
      1,
      LODWORD(v4),
      v5,
      v6);
    goto LABEL_9;
  }
  if ( CommandList::GetHead((ChatDisplayInfo *)&this->SubstateList) )
  {
    ((void (__thiscall *)(CommandInterpreter *, int))v2->vfptr[3].OnLoseFocus)(v2, &v2->SubstateList);
  }
  else if ( !v2->transient_state )
  {
    v6 = 0;
    v5 = 0;
    v4 = 1.0;
    v3 = 1090519043;
    goto LABEL_8;
  }
LABEL_9:
  if ( CommandList::GetHead((ChatDisplayInfo *)&v2->TurnList) )
  {
    ((void (__thiscall *)(CommandInterpreter *, int, int))v2->vfptr[3].OnLoseFocus)(v2, &v2->TurnList, a2);
  }
  else
  {
    ((void (__thiscall *)(CommandInterpreter *, signed int, _DWORD, signed int, _DWORD, _DWORD, int))v2->vfptr[13].OnAction)(
      v2,
      1694498831,
      0,
      1065353216,
      0,
      0,
      a2);
    ((void (__thiscall *)(CommandInterpreter *, signed int, _DWORD, signed int, _DWORD, _DWORD))v2->vfptr[13].OnAction)(
      v2,
      1694498829,
      0,
      1065353216,
      0,
      0);
  }
  if ( CommandList::GetHead((ChatDisplayInfo *)&v2->SidestepList) )
    ((void (__thiscall *)(CommandInterpreter *))v2->vfptr[3].OnLoseFocus)(v2);
  else
    ((void (__thiscall *)(CommandInterpreter *, signed int, _DWORD, signed int, _DWORD))v2->vfptr[13].OnAction)(
      v2,
      1694498831,
      0,
      1065353216,
      0);
}
// 6B3430: could not find valid save-restore pair for edi

//----- (006B3510) --------------------------------------------------------  // acclient.c:717101
void __thiscall CommandInterpreter::ApplyListHeadMovement(CommandInterpreter *this, CommandList *list)
{
  CommandList *v2; // ebx@1
  CommandInterpreter *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@1
  unsigned int v6; // eax@2
  int v7; // eax@2
  IInputActionCallbackVtbl *v8; // edx@2
  unsigned int cmd; // [sp+8h] [bp-4h]@1

  cmd = (unsigned int)this;
  v2 = list;
  v3 = this;
  v4 = CommandList::GetHead((ChatDisplayInfo *)list);
  v5 = v4;
  if ( v4 )
  {
    v6 = *(_DWORD *)(v4 + 8);
    list = *(CommandList **)(v5 + 12);
    cmd = v6;
    v7 = CommandList::HeadIsMouse(v2);
    v8 = v3->vfptr;
    if ( v7 )
    {
      ((void (__thiscall *)(CommandInterpreter *, unsigned int, signed int, CommandList *, signed int, _DWORD))v8[13].OnAction)(
        v3,
        cmd,
        1,
        list,
        1,
        *(_DWORD *)(v5 + 16));
    }
    else
    {
      ((void (__thiscall *)(CommandInterpreter *, unsigned int *, CommandList **))v8[4].OnAction)(v3, &cmd, &list);
      ((void (__thiscall *)(CommandInterpreter *, unsigned int, signed int, CommandList *, _DWORD, _DWORD))v3->vfptr[13].OnAction)(
        v3,
        cmd,
        1,
        list,
        0,
        0);
    }
  }
}

//----- (006B35A0) --------------------------------------------------------  // acclient.c:717149
void __thiscall CommandInterpreter::StopListHeadMovement(CommandInterpreter *this, CommandList *list)
{
  CommandList *v2; // ebx@1
  CommandInterpreter *v3; // esi@1
  unsigned int v4; // eax@1
  unsigned int v5; // edi@1
  unsigned int v6; // eax@2
  int v7; // eax@2
  IInputActionCallbackVtbl *v8; // edx@2
  unsigned int cmd; // [sp+8h] [bp-4h]@1

  cmd = (unsigned int)this;
  v2 = list;
  v3 = this;
  v4 = CommandList::GetHead((ChatDisplayInfo *)list);
  v5 = v4;
  if ( v4 )
  {
    v6 = *(_DWORD *)(v4 + 8);
    list = *(CommandList **)(v5 + 12);
    cmd = v6;
    v7 = CommandList::HeadIsMouse(v2);
    v8 = v3->vfptr;
    if ( v7 )
    {
      ((void (__thiscall *)(CommandInterpreter *, unsigned int, _DWORD, CommandList *, signed int, _DWORD))v8[13].OnAction)(
        v3,
        cmd,
        0,
        list,
        1,
        *(_DWORD *)(v5 + 16));
    }
    else
    {
      ((void (__thiscall *)(CommandInterpreter *, unsigned int *, CommandList **))v8[4].OnAction)(v3, &cmd, &list);
      ((void (__thiscall *)(CommandInterpreter *, unsigned int, _DWORD, CommandList *, _DWORD, _DWORD))v3->vfptr[13].OnAction)(
        v3,
        cmd,
        0,
        list,
        0,
        0);
    }
  }
}

//----- (006B3630) --------------------------------------------------------  // acclient.c:717197
int __thiscall CommandInterpreter::HandleSelectLeft(CommandInterpreter *this, int start)
{
  CommandInterpreter *v2; // esi@1
  int result; // eax@3

  v2 = this;
  this->mouseleft_down = start;
  if ( ICIDM::s_cidm->m_UseMouseTurning && ((int (__thiscall *)(CommandInterpreter *))this->vfptr[17].OnLoseFocus)(this) )
  {
    ((void (__thiscall *)(CommandInterpreter *, signed int, int, signed int, signed int, signed int))v2->vfptr[13].OnAction)(
      v2,
      1157627909,
      start,
      1065353216,
      1,
      1);
    ((void (__thiscall *)(CommandInterpreter *))v2->vfptr[6].OnAction)(v2);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B3690) --------------------------------------------------------  // acclient.c:717224
void __userpurge CommandInterpreter::HandleKeyboardCommand(CommandInterpreter *this@<ecx>, int a2@<edi>, CmdStruct *cmdstruct, unsigned int cmd)
{
  CommandInterpreter *v4; // esi@1
  CmdStruct *v5; // eax@3
  unsigned int v6; // ecx@4
  unsigned int v7; // edx@4
  int v8; // ecx@4
  unsigned int v9; // ecx@9
  int v10; // edx@9
  int v11; // ecx@9
  bool v12; // cf@9
  IInputActionCallbackVtbl *v13; // edx@13
  IInputActionCallbackVtbl *v14; // eax@16
  CMotionInterp *v15; // eax@21
  int start; // [sp+1Ch] [bp-10h]@4
  float speed; // [sp+20h] [bp-Ch]@3
  int mouse; // [sp+24h] [bp-8h]@13
  int new_hold_run; // [sp+28h] [bp-4h]@13
  void *retaddr; // [sp+2Ch] [bp+0h]@16

  v4 = this;
  if ( !((int (*)(void))this->vfptr[12].__vecDelDtor)() || !v4->player )
    return;
  v5 = cmdstruct;
  cmdstruct = (CmdStruct *)cmdstruct->command;
  speed = 1.0;
  if ( cmdstruct == (CmdStruct *)150995143 )
  {
    v6 = v5->curr;
    start = *(_DWORD *)&v5->args[v6];
    v7 = v5->size;
    v8 = v6 + 4;
    v5->curr = v8;
    if ( v8 >= v7 )
    {
      LODWORD(v4->autorun_speed) = 1065353216;
    }
    else
    {
      LODWORD(v4->autorun_speed) = *(_DWORD *)&v5->args[v8];
      v5->curr += 4;
    }
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[16].OnLoseFocus)(v4);
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[6].OnAction)(v4);
    return;
  }
  if ( (unsigned int)cmdstruct & 0x8000000 )
    return;
  v9 = v5->curr;
  v10 = *(_DWORD *)&v5->args[v9];
  v11 = v9 + 4;
  v12 = v11 < v5->size;
  start = v10;
  v5->curr = v11;
  if ( v12 )
  {
    speed = *(float *)&v5->args[v11];
    v5->curr = v11 + 4;
  }
  if ( v4->controlled_by_server && !v10 )
  {
    v13 = v4->vfptr;
    new_hold_run = 0;
    mouse = 0;
    ((void (__thiscall *)(CommandInterpreter *, CmdStruct **, int *, float *, int *, int *))v13[1].OnLoseFocus)(
      v4,
      &cmdstruct,
      &start,
      &speed,
      &mouse,
      &new_hold_run);
    return;
  }
  ((void (__thiscall *)(CommandInterpreter *, int))v4->vfptr[8].OnLoseFocus)(v4, a2);
  if ( cmd == -2063597567 )
  {
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[2].OnLoseFocus)(v4);
LABEL_21:
    v15 = CPhysicsObj::get_minterp(v4->player);
    if ( CMotionInterp::is_standing_still(v15) )
      return;
    goto LABEL_22;
  }
  if ( cmd == -2063597566 )
  {
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[3].__vecDelDtor)(v4);
    goto LABEL_21;
  }
  v14 = v4->vfptr;
  retaddr = 0;
  new_hold_run = 0;
  if ( !((int (__thiscall *)(CommandInterpreter *, unsigned int *, float *, int *, void **))v14[2].__vecDelDtor)(
          v4,
          &cmd,
          &speed,
          &mouse,
          &retaddr) )
  {
LABEL_22:
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[6].OnAction)(v4);
    return;
  }
  ((void (__thiscall *)(CommandInterpreter *, CmdStruct **, float *))v4->vfptr[4].OnAction)(v4, &cmdstruct, &speed);
  ((void (__thiscall *)(CommandInterpreter *, CmdStruct *, int, _DWORD, int, int))v4->vfptr[13].OnAction)(
    v4,
    cmdstruct,
    start,
    LODWORD(speed),
    new_hold_run,
    mouse);
  if ( cmdstruct != (CmdStruct *)620757051 )
    ((void (__thiscall *)(CommandInterpreter *))v4->vfptr[6].OnAction)(v4);
}
// 6B3690: could not find valid save-restore pair for edi

//----- (006B3870) --------------------------------------------------------  // acclient.c:717340
void __thiscall CommandInterpreter::HandleMouseMovementCommand(CommandInterpreter *this, CmdStruct *cmdstruct)
{
  CommandInterpreter *v2; // esi@1
  CmdStruct *v3; // eax@3
  unsigned int v4; // ecx@3
  int v5; // edx@3
  unsigned int v6; // ecx@3
  unsigned int v7; // ecx@5
  CmdStruct *v8; // edx@5
  IInputActionCallbackVtbl *v9; // eax@5
  IInputActionCallbackVtbl *v10; // edx@5
  float speed; // [sp+14h] [bp-10h]@3
  int mouse_command; // [sp+18h] [bp-Ch]@5
  int start; // [sp+1Ch] [bp-8h]@3
  unsigned int cmd; // [sp+20h] [bp-4h]@3

  v2 = this;
  if ( ((int (*)(void))this->vfptr[12].__vecDelDtor)() && v2->player )
  {
    v3 = cmdstruct;
    cmd = cmdstruct->command;
    v4 = cmdstruct->curr;
    speed = 1.0;
    v5 = *(_DWORD *)&cmdstruct->args[v4];
    v6 = v4 + 4;
    start = v5;
    cmdstruct->curr = v6;
    if ( v5 )
    {
      speed = *(float *)&v3->args[v6];
      v3->curr = v6 + 4;
    }
    v7 = v3->curr;
    v8 = *(CmdStruct **)&v3->args[v7];
    v3->curr = v7 + 4;
    v9 = v2->vfptr;
    cmdstruct = v8;
    ((void (__thiscall *)(CommandInterpreter *))v9[8].OnLoseFocus)(v2);
    v10 = v2->vfptr;
    mouse_command = 1;
    if ( ((int (__thiscall *)(CommandInterpreter *, unsigned int *, int *, float *, int *, CmdStruct **))v10[2].__vecDelDtor)(
           v2,
           &cmd,
           &start,
           &speed,
           &mouse_command,
           &cmdstruct) )
    {
      ((void (__thiscall *)(CommandInterpreter *, unsigned int, int, _DWORD, int, CmdStruct *))v2->vfptr[13].OnAction)(
        v2,
        cmd,
        start,
        LODWORD(speed),
        mouse_command,
        cmdstruct);
      ((void (__thiscall *)(CommandInterpreter *))v2->vfptr[6].OnAction)(v2);
    }
  }
}

//----- (006B3950) --------------------------------------------------------  // acclient.c:717401
CommandList *__thiscall CommandInterpreter::WhichList(CommandInterpreter *this, unsigned int cmd)
{
  CommandList *result; // eax@1

  result = 0;
  switch ( cmd )
  {
    case 0x6500000Du:
    case 0x6500000Eu:
      result = &this->TurnList;
      break;
    case 0x6500000Fu:
    case 0x65000010u:
      result = &this->SidestepList;
      break;
    default:
      if ( cmd & 0x40000000 )
      {
        if ( cmd & 0x4000000 )
          result = &this->SubstateList;
      }
      break;
  }
  return result;
}

//----- (006B39A0) --------------------------------------------------------  // acclient.c:717428
void __thiscall CommandInterpreter::AddCommand(CommandInterpreter *this, unsigned int cmd, float speed, int mouse, int new_hold_run)
{
  CommandInterpreter *v5; // esi@1
  CommandList *v6; // ebx@1

  v5 = this;
  v6 = (CommandList *)((int (__stdcall *)(_DWORD))this->vfptr[1].__vecDelDtor)(cmd);
  if ( v6 )
  {
    CommandList::AddCommand(v6, cmd, speed, mouse, new_hold_run);
    if ( cmd & 0x40000000 )
    {
      if ( v6 == &v5->SubstateList )
        ((void (__thiscall *)(CommandInterpreter *))v5->vfptr[6].__vecDelDtor)(v5);
      v5->transient_state = 0;
    }
  }
  else if ( cmd & 0x40000000 )
  {
    if ( !(cmd & 0x4000000) )
    {
      ((void (__thiscall *)(_DWORD))v5->vfptr[6].__vecDelDtor)(v5);
      if ( cmd != 1090519043 )
        v5->transient_state = 1;
    }
  }
}

//----- (006B3A20) --------------------------------------------------------  // acclient.c:717457
int __thiscall CommandInterpreter::NukeCommand(CommandInterpreter *this, unsigned int *cmd, int *start, float *speed, int *mouse, int *new_hold_run)
{
  CommandInterpreter *v6; // esi@1
  ChatDisplayInfo *v7; // edi@1
  unsigned int v8; // eax@6
  unsigned int v9; // esi@6
  int result; // eax@8

  v6 = this;
  v7 = (ChatDisplayInfo *)((int (__stdcall *)(unsigned int))this->vfptr[1].__vecDelDtor)(*cmd);
  if ( v7 )
  {
    if ( !CommandList::RemoveCommand((CommandList *)v7, *cmd, *speed, *mouse)
      || v6->transient_state
      || v6->auto_run && (CommandList *)v7 == &v6->SubstateList )
    {
      result = 0;
    }
    else
    {
      v8 = CommandList::GetHead(v7);
      v9 = v8;
      if ( v8 )
      {
        *cmd = *(_DWORD *)(v8 + 8);
        *(_DWORD *)speed = *(_DWORD *)(v8 + 12);
        *start = 1;
        *mouse = CommandList::HeadIsMouse((CommandList *)v7);
        *new_hold_run = *(_DWORD *)(v9 + 16);
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

//----- (006B3AD0) --------------------------------------------------------  // acclient.c:717498
int __thiscall CommandInterpreter::BookkeepCommandAndModifyIfNecessary(CommandInterpreter *this, unsigned int *cmd, int *start, float *speed, int *mouse, int *new_hold_run)
{
  int result; // eax@2

  if ( *cmd == 620757051 )
  {
    result = 1;
  }
  else if ( *start )
  {
    ((void (__stdcall *)(unsigned int, _DWORD, int, int))this->vfptr[1].OnAction)(
      *cmd,
      *(_DWORD *)speed,
      *mouse,
      *new_hold_run);
    result = 1;
  }
  else
  {
    result = ((int (__stdcall *)(unsigned int *, int *, float *, int *, int *))this->vfptr[1].OnLoseFocus)(
               cmd,
               start,
               speed,
               mouse,
               new_hold_run);
  }
  return result;
}

//----- (006B3B40) --------------------------------------------------------  // acclient.c:717528
BOOL __thiscall CommandInterpreter::UsePositionFromServer(CommandInterpreter *this)
{
  return this->autonomy_level != 2;
}

//----- (006B3B50) --------------------------------------------------------  // acclient.c:717534
int __thiscall CommandInterpreter::StopCompletely(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  int result; // eax@3

  v1 = this;
  if ( this->smartbox && this->player )
  {
    ((void (*)(void))this->vfptr[3].OnAction)();
    ((void (__thiscall *)(CommandInterpreter *, _DWORD, _DWORD))v1->vfptr[17].__vecDelDtor)(v1, 0, 0);
    CPhysicsObj::StopCompletely(v1->player, 1);
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnAction)(v1);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B3B90) --------------------------------------------------------  // acclient.c:717556
int __thiscall CommandInterpreter::MaybeStopCompletely(CommandInterpreter *this)
{
  int result; // eax@2

  if ( this->controlled_by_server )
    result = 1;
  else
    result = ((int (*)(void))this->vfptr[15].OnLoseFocus)();
  return result;
}

//----- (006B3BB0) --------------------------------------------------------  // acclient.c:717568
int __thiscall CommandInterpreter::SetAutonomyLevel(CommandInterpreter *this, unsigned int new_level)
{
  int result; // eax@2
  IInputActionCallbackVtbl *v3; // edx@3

  if ( new_level <= 2 )
  {
    v3 = this->vfptr;
    this->autonomy_level = new_level;
    ((void (__stdcall *)(unsigned int))v3[19].__vecDelDtor)(new_level);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B3BF0) --------------------------------------------------------  // acclient.c:717594
void __thiscall CommandInterpreter::UseTime(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // ecx@3

  v1 = this;
  if ( ((int (*)(void))this->vfptr[14].OnAction)() )
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[7].OnAction)(v1);
  v2 = v1->player;
  if ( v2
    && v1->enabled
    && v1->controlled_by_server
    && !CPhysicsObj::motions_pending(v2)
    && !CPhysicsObj::IsMovingTo(v1->player)
    && (CommandList::GetHead((ChatDisplayInfo *)&v1->SubstateList)
     || CommandList::GetHead((ChatDisplayInfo *)&v1->TurnList)
     || CommandList::GetHead((ChatDisplayInfo *)&v1->SidestepList)
     || v1->auto_run) )
    ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[8].OnLoseFocus)(v1);
}

//----- (006B3C70) --------------------------------------------------------  // acclient.c:717616
void __thiscall CommandInterpreter::HandleExhaustion(CommandInterpreter *this)
{
  CPhysicsObj *v1; // ecx@1

  v1 = this->player;
  if ( v1 )
    CPhysicsObj::report_exhaustion(v1);
}

//----- (006B3C80) --------------------------------------------------------  // acclient.c:717626
void __thiscall CommandInterpreter::UpdateToggleRun(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1

  v1 = this;
  ((void (__stdcall *)(_DWORD))this->vfptr[2].OnLoseFocus)(this->hold_run);
  ((void (__thiscall *)(CommandInterpreter *))v1->vfptr[6].OnAction)(v1);
}

//----- (006B3CA0) --------------------------------------------------------  // acclient.c:717636
int __thiscall CommandInterpreter::IsStandingStill(CommandInterpreter *this)
{
  CPhysicsObj *v1; // ecx@1
  CMotionInterp *v2; // eax@2
  int result; // eax@2

  v1 = this->player;
  if ( v1 )
  {
    v2 = CPhysicsObj::get_minterp(v1);
    result = CMotionInterp::is_standing_still(v2);
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (006B3CC0) --------------------------------------------------------  // acclient.c:717656
void __thiscall CommandInterpreter::ToggleAutoRun(CommandInterpreter *this)
{
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[17].__vecDelDtor)(this->auto_run == 0, 1);
}

//----- (006B3CE0) --------------------------------------------------------  // acclient.c:717662
BOOL __thiscall CommandInterpreter::IsActive(CommandInterpreter *this)
{
  return this->enabled && this->player;
}

//----- (006B3D00) --------------------------------------------------------  // acclient.c:717668
void __thiscall CommandInterpreter::MovePlayer_NonAutonomous(CommandInterpreter *this, unsigned int cmd, int start, float speed, HoldKey key)
{
  if ( start )
  {
    if ( cmd == 620757051 )
      ((void (*)(void))this->vfptr[5].OnAction)();
    else
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr[19].OnAction)(cmd, LODWORD(speed), key);
  }
  else if ( cmd == 620757051 )
  {
    ((void (__stdcall *)(_DWORD))this->vfptr[5].OnLoseFocus)(0);
  }
  else
  {
    ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[19].OnLoseFocus)(cmd, key);
  }
}

//----- (006B3D60) --------------------------------------------------------  // acclient.c:717688
void __thiscall CommandInterpreter::HandleNewForwardMovement(CommandInterpreter *this)
{
  ((void (__stdcall *)(_DWORD, _DWORD))this->vfptr[17].__vecDelDtor)(0, 1);
}

//----- (006B3D70) --------------------------------------------------------  // acclient.c:717694
int __thiscall CommandInterpreter::PlayerIsDead(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  int result; // eax@3

  v1 = this;
  v2 = this->player;
  if ( v2 && CPhysicsObj::InqInterpretedMotionState(v2) )
    result = *(_DWORD *)(CPhysicsObj::InqInterpretedMotionState(v1->player) + 8) == 1073741841;
  else
    result = 0;
  return result;
}

//----- (006B3DD0) --------------------------------------------------------  // acclient.c:717722
BOOL __thiscall Plane::operator==(Plane *this, Plane *p)
{
  return fabs(this->N.x - p->N.x) <= 0.00019999999
      && fabs(this->N.y - p->N.y) <= 0.00019999999
      && fabs(this->N.z - p->N.z) <= 0.00019999999
      && fabs(this->d - p->d) < 0.00019999999;
}

//----- (006B3E40) --------------------------------------------------------  // acclient.c:717731
void __thiscall CommandInterpreter::CommandInterpreter(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  char *v2; // ecx@1
  int v3; // edx@1

  v1 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&CommandInterpreter::vftable;
  this->SubstateList.head = 0;
  this->SubstateList.mouse_command = 0;
  this->SubstateList.current = 0;
  this->TurnList.head = 0;
  this->TurnList.mouse_command = 0;
  this->TurnList.current = 0;
  this->SidestepList.head = 0;
  this->SidestepList.mouse_command = 0;
  this->SidestepList.current = 0;
  this->autonomy_level = 2;
  this->hold_run = 0;
  this->hold_sidestep = 0;
  this->transient_state = 0;
  this->auto_run = 0;
  this->mouselook_active = 0;
  this->mouseleft_down = 0;
  LODWORD(this->autorun_speed) = 1065353216;
  this->controlled_by_server = 1;
  this->enabled = 1;
  this->action_stamp = 1;
  *(_QWORD *)&this->last_sent_position_time = Timer::cur_time;
  v2 = (char *)&this->last_sent_position.frame;
  v1->last_sent_position.vfptr = (PackObjVtbl *)&Position::vftable;
  v1->last_sent_position.objcell_id = 0;
  *(_DWORD *)v2 = 1065353216;
  *((_DWORD *)v2 + 1) = 0;
  *((_DWORD *)v2 + 2) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 13) = 0;
  *((_DWORD *)v2 + 14) = 0;
  *((_DWORD *)v2 + 15) = 0;
  Frame::cache((Frame *)v2);
  v3 = (int)&v1->last_sent_contact_plane;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  LODWORD(v1->time_between_position_events) = 0;
  HIDWORD(v1->time_between_position_events) = 1072693248;
}
// 796910: using guessed type int (__thiscall *Position::vftable)(void *, char);
// 803CC0: using guessed type int (__thiscall *CommandInterpreter::vftable)(void *, char);

//----- (006B3F10) --------------------------------------------------------  // acclient.c:717783
CommandInterpreter *__thiscall CommandInterpreter::vector_deleting_destructor(CommandInterpreter *this, unsigned int a2)
{
  CommandInterpreter *v2; // esi@1

  v2 = this;
  this->vfptr = (IInputActionCallbackVtbl *)&CommandInterpreter::vftable;
  this->last_sent_position.vfptr = (PackObjVtbl *)&PackObj::vftable;
  IInputActionCallback::~IInputActionCallback((IInputActionCallback *)&this->vfptr);
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803CC0: using guessed type int (__thiscall *CommandInterpreter::vftable)(void *, char);

//----- (006B3F40) --------------------------------------------------------  // acclient.c:717799
void __thiscall CommandInterpreter::MovePlayer(CommandInterpreter *this, unsigned int cmd, int start, float speed, int mouse, int new_hold_run)
{
  CommandInterpreter *v6; // esi@1
  CPhysicsObj *v7; // ecx@1
  signed int v8; // edi@1
  unsigned int v9; // ebp@8
  unsigned int v10; // ebx@8
  unsigned int v11; // eax@8
  unsigned int v12; // eax@10
  int v13; // eax@12
  signed int v14; // ebx@47
  HoldKey v15; // edi@57
  unsigned int v16; // ecx@64
  int start_sidestep_right; // [sp+8h] [bp-D8h]@12
  int cancel_turn_left; // [sp+Ch] [bp-D4h]@12
  int start_sidestep_left; // [sp+10h] [bp-D0h]@12
  int cancel_sidestep_left; // [sp+14h] [bp-CCh]@12
  int cancel_sidestep_right; // [sp+18h] [bp-C8h]@12
  int start_turn_left; // [sp+1Ch] [bp-C4h]@12
  int start_turn_right; // [sp+20h] [bp-C0h]@12
  MovementParameters params; // [sp+24h] [bp-BCh]@6
  StringInfo siError; // [sp+50h] [bp-90h]@71

  v6 = this;
  v7 = this->player;
  v8 = 0;
  if ( !v7 || !CPhysicsObj::InqInterpretedMotionState(v7) )
    return;
  if ( ((int (__thiscall *)(CommandInterpreter *))v6->vfptr[10].__vecDelDtor)(v6) )
  {
    ((void (__thiscall *)(CommandInterpreter *))v6->vfptr[9].OnAction)(v6);
    ((void (__thiscall *)(CommandInterpreter *, _DWORD, _DWORD))v6->vfptr[17].__vecDelDtor)(v6, 0, 0);
    return;
  }
  if ( !ICIDM::s_cidm->m_UseMouseTurning )
    goto LABEL_55;
  MovementParameters::MovementParameters(&params);
  params.hold_key_to_apply = 0;
  if ( mouse )
  {
    params.bitfield &= 0xFFFFF7FF;
    params.hold_key_to_apply = (new_hold_run != 0) + 1;
  }
  v9 = 2147483648;
  v10 = 2147483648;
  v11 = CommandList::GetHead((ChatDisplayInfo *)&v6->TurnList);
  if ( v11 )
    v9 = *(_DWORD *)(v11 + 8);
  v12 = CommandList::GetHead((ChatDisplayInfo *)&v6->SidestepList);
  if ( v12 )
    v10 = *(_DWORD *)(v12 + 8);
  v13 = ((int (__thiscall *)(CommandInterpreter *))v6->vfptr[17].OnLoseFocus)(v6);
  cancel_sidestep_right = 0;
  cancel_sidestep_left = 0;
  cancel_turn_left = 0;
  start_sidestep_right = 0;
  start_sidestep_left = 0;
  start_turn_right = 0;
  start_turn_left = 0;
  if ( !mouse )
  {
    if ( !v13 )
    {
      v14 = cmd;
      goto LABEL_59;
    }
    if ( cmd != 1694498829 )
    {
      if ( cmd == 1694498830 )
      {
        if ( start )
        {
          cancel_turn_left = 1;
          start_sidestep_left = 1;
        }
        else
        {
          cancel_sidestep_left = 1;
        }
      }
      else
      {
        v8 = 1;
        cancel_turn_left = 1;
      }
      goto LABEL_38;
    }
    if ( !start )
    {
      cancel_sidestep_right = 1;
      goto LABEL_38;
    }
LABEL_31:
    v8 = 1;
    start_sidestep_right = 1;
    goto LABEL_38;
  }
  if ( !v13 )
  {
    if ( v9 == 1694498829 )
    {
      cancel_sidestep_right = 1;
      start_turn_right = 1;
    }
    else if ( v9 == 1694498830 )
    {
      cancel_sidestep_left = 1;
      start_turn_left = 1;
    }
    goto LABEL_38;
  }
  if ( cmd != 201326785 )
    goto LABEL_38;
  if ( v9 == 1694498829 )
  {
    v8 = 1;
    if ( v10 == 1694498832 )
      start_sidestep_left = 1;
    else
      start_sidestep_right = 1;
    goto LABEL_38;
  }
  if ( v9 == 1694498830 )
  {
    if ( v10 != 1694498831 )
    {
      cancel_turn_left = 1;
      start_sidestep_left = 1;
      goto LABEL_38;
    }
    goto LABEL_31;
  }
  if ( v6->mouseleft_down )
  {
    start = 1;
    cmd = 1157627909;
  }
LABEL_38:
  ((void (__thiscall *)(CommandInterpreter *))v6->vfptr[8].OnLoseFocus)(v6);
  if ( cancel_sidestep_right )
    CPhysicsObj::StopMotion(v6->player, 0x6500000Fu, &params, 1);
  if ( cancel_sidestep_left )
    CPhysicsObj::StopMotion(v6->player, 0x65000010u, &params, 1);
  if ( v8 )
    CPhysicsObj::StopMotion(v6->player, 0x6500000Du, &params, 1);
  if ( cancel_turn_left )
    CPhysicsObj::StopMotion(v6->player, 0x6500000Eu, &params, 1);
  if ( start_turn_right )
  {
    start = 1;
    v14 = 1694498829;
  }
  else
  {
    v14 = cmd;
  }
  if ( start_turn_left )
  {
    v14 = 1694498830;
    start = 1;
  }
  if ( start_sidestep_right )
  {
    v14 = 1694498831;
    start = 1;
    speed = 1.0;
  }
  if ( start_sidestep_left )
  {
    start = 1;
    cmd = 1694498832;
    speed = 1.0;
LABEL_55:
    v14 = cmd;
  }
  if ( mouse )
  {
    v15 = (new_hold_run != 0) + 1;
    goto LABEL_60;
  }
LABEL_59:
  v15 = 0;
LABEL_60:
  if ( v6->autonomy_level )
  {
    if ( start )
    {
      if ( v14 != 620757051 )
      {
        MovementParameters::MovementParameters(&params);
        params.action_stamp = v6->action_stamp;
        v16 = params.bitfield | 0x1000;
        params.speed = speed;
        params.bitfield |= 0x1000u;
        params.hold_key_to_apply = v15;
        if ( mouse )
          params.bitfield = v16 & 0xFFFFF7FF;
        if ( v14 & 0x10000000 )
          ((void (__thiscall *)(CommandInterpreter *))v6->vfptr[15].OnLoseFocus)(v6);
        switch ( CPhysicsObj::DoMotion(v6->player, v14, &params, 1) )
        {
          case 0:
            if ( v14 & 0x10000000 )
              ++v6->action_stamp;
            return;
          case 63:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &cant_crouch_combat_1, 1);
            goto LABEL_72;
          case 64:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &cant_sit_combat_1, 1);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
            goto LABEL_73;
          case 65:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &cant_lie_down_combat_1, 1);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
            goto LABEL_73;
          case 62:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &too_tired_1, 1);
LABEL_72:
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
            goto LABEL_73;
          case 66:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &cant_emote_combat_1, 1);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
            goto LABEL_73;
          case 68:
            StringInfo::StringInfo(&siError);
            StringInfo::SetLiteralValue(&siError, &cant_emote_position_1, 1);
            ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
LABEL_73:
            StringInfo::~StringInfo(&siError);
            break;
          default:
            return;
        }
      }
    }
    else if ( v14 != 620757051 )
    {
      MovementParameters::MovementParameters(&params);
      params.hold_key_to_apply = 0;
      if ( mouse )
      {
        params.bitfield &= 0xFFFFF7FF;
        params.hold_key_to_apply = (new_hold_run != 0) + 1;
      }
      CPhysicsObj::StopMotion(v6->player, v14, &params, 1);
    }
  }
  else
  {
    ((void (__thiscall *)(CommandInterpreter *, signed int, int, _DWORD, HoldKey))v6->vfptr[4].OnLoseFocus)(
      v6,
      v14,
      start,
      LODWORD(speed),
      v15);
  }
}

//----- (006B4510) --------------------------------------------------------  // acclient.c:718065
void __thiscall CommandInterpreter::StopDrift(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  MovementParameters params; // [sp+4h] [bp-2Ch]@1

  v1 = this;
  MovementParameters::MovementParameters(&params);
  params.bitfield &= 0xFFFFF7FF;
  v2 = v1->player;
  params.hold_key_to_apply = 1;
  CPhysicsObj::StopMotion(v2, 0x6500000Du, &params, 1);
  CPhysicsObj::StopMotion(v1->player, 0x6500000Eu, &params, 1);
}

//----- (006B4570) --------------------------------------------------------  // acclient.c:718081
int __thiscall CommandInterpreter::TurnToHeading(CommandInterpreter *this, float new_heading, int run)
{
  CommandInterpreter *v3; // esi@1
  int result; // eax@4
  MovementParameters params; // [sp+4h] [bp-2Ch]@2

  v3 = this;
  if ( ((int (*)(void))this->vfptr[12].__vecDelDtor)() )
  {
    MovementParameters::MovementParameters(&params);
    params.desired_heading = new_heading;
    LODWORD(params.speed) = 1065353216;
    params.bitfield &= 0xFFFEFFFF;
    if ( run )
      params.hold_key_to_apply = 2;
    CPhysicsObj::TurnToHeading(v3->player, &params);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B45E0) --------------------------------------------------------  // acclient.c:718107
int __thiscall CommandInterpreter::ShouldSendPositionEvent(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // ecx@4
  int result; // eax@5
  unsigned int v4; // edx@7

  v1 = this;
  if ( ((int (*)(void))this->vfptr[12].__vecDelDtor)()
    && v1->autonomy_level == 2
    && v1->smartbox
    && (v2 = v1->player) != 0 )
  {
    if ( v1->time_between_position_events + v1->last_sent_position_time < COERCE_DOUBLE(Timer::cur_time.Cmd) )
    {
      result = v1->last_sent_position.objcell_id != v2->m_position.objcell_id
            || !Frame::is_equal(&v1->last_sent_position.frame, &v2->m_position.frame);
    }
    else
    {
      v4 = v1->last_sent_position.objcell_id;
      result = v4 != v2->m_position.objcell_id;
      if ( v4 == v2->m_position.objcell_id )
        result = Plane::operator==(&v1->last_sent_contact_plane, &v2->contact_plane) == 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B4680) --------------------------------------------------------  // acclient.c:718141
void __thiscall CommandInterpreter::SendMovementEvent(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // ecx@1
  CPhysicsObj *v3; // ecx@4
  unsigned __int16 v4; // bx@5
  unsigned __int16 v5; // bp@5
  unsigned __int16 v6; // di@5
  CMotionInterp *v7; // eax@5
  CPhysicsObj *v8; // ecx@5
  int v9; // edx@5
  unsigned int v10; // eax@5
  int v11; // eax@7
  int v12; // ST0C_4@9
  int v13; // ST08_4@9
  int v14; // eax@9
  unsigned int v15; // edx@9
  Position *p; // [sp+4h] [bp-9Ch]@4
  unsigned __int16 _instance_timestamp; // [sp+8h] [bp-98h]@5
  MoveToStatePack mtsp; // [sp+Ch] [bp-94h]@9

  v1 = this;
  v2 = this->player;
  if ( v2 )
  {
    if ( v1->smartbox )
    {
      if ( CPhysicsObj::InqRawMotionState(v2) )
      {
        v3 = v1->player;
        p = &v3->m_position;
        if ( v1->autonomy_level )
        {
          v4 = v3->update_times[4];
          v5 = v3->update_times[5];
          v6 = v3->update_times[6];
          _instance_timestamp = v3->update_times[8];
          v7 = CPhysicsObj::get_minterp(v3);
          v8 = v1->player;
          v9 = v7->standing_longjump;
          v10 = v8->transient_state;
          v11 = v10 & 1 && v10 & 2;
          v12 = v9;
          v13 = v11;
          v14 = CPhysicsObj::InqRawMotionState(v8);
          MoveToStatePack::MoveToStatePack(&mtsp, (RawMotionState *)v14, p, v13, v12, _instance_timestamp, v5, v4, v6);
          v1->vfptr[20].__vecDelDtor((IInputActionCallback *)v1, (unsigned int)&mtsp);
          v15 = Timer::cur_time.Param;
          LODWORD(v1->last_sent_position_time) = Timer::cur_time.Cmd;
          HIDWORD(v1->last_sent_position_time) = v15;
          mtsp.position.vfptr = (PackObjVtbl *)&PackObj::vftable;
          RawMotionState::~RawMotionState(&mtsp.raw_motion_state);
        }
      }
    }
  }
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);

//----- (006B4770) --------------------------------------------------------  // acclient.c:718201
void __thiscall CommandInterpreter::SendPositionEvent(CommandInterpreter *this)
{
  CommandInterpreter *v1; // esi@1
  CPhysicsObj *v2; // eax@2
  unsigned int v3; // ecx@3
  int v4; // ebp@5
  CPhysicsObj *v5; // eax@6
  unsigned __int16 v6; // cx@6
  unsigned __int16 v7; // dx@6
  unsigned __int16 v8; // bx@6
  unsigned __int16 v9; // di@6
  unsigned int v10; // eax@6
  int v11; // eax@8
  unsigned int v12; // eax@10
  AutonomousPositionPack app; // [sp+4h] [bp-58h]@10

  v1 = this;
  if ( this->smartbox )
  {
    v2 = this->player;
    if ( v2 )
    {
      v3 = v2->transient_state;
      if ( v3 & 1 )
      {
        if ( v3 & 2 )
        {
          v4 = (int)&v2->m_position;
          if ( Position::IsValid(&v2->m_position) )
          {
            v5 = v1->player;
            v6 = v5->update_times[6];
            v7 = v5->update_times[4];
            v8 = v5->update_times[8];
            v9 = v5->update_times[5];
            v10 = v5->transient_state;
            v11 = v10 & 1 && v10 & 2;
            AutonomousPositionPack::AutonomousPositionPack(&app, (Position *)v4, v11, v8, v9, v7, v6);
            v1->vfptr[20].OnAction((IInputActionCallback *)v1, (InputEvent *)&app);
            v12 = Timer::cur_time.Param;
            LODWORD(v1->last_sent_position_time) = Timer::cur_time.Cmd;
            HIDWORD(v1->last_sent_position_time) = v12;
            Position::operator=((int)&v1->last_sent_position, v4);
            Plane::operator=((int)&v1->last_sent_contact_plane, (int)&v1->player->contact_plane);
          }
        }
      }
    }
  }
}

//----- (006B4850) --------------------------------------------------------  // acclient.c:718253
void __thiscall CommandInterpreter::SetAutoRun(CommandInterpreter *this, int val, int apply_movement)
{
  CommandInterpreter *v3; // esi@1
  char *v4; // edi@3
  char *v5; // edi@7
  PStringBase<unsigned short> _value; // [sp+8h] [bp-94h]@3
  StringInfo siError; // [sp+Ch] [bp-90h]@3

  v3 = this;
  if ( (val == 0) != (this->auto_run == 0) )
  {
    this->auto_run = val;
    this->transient_state = 0;
    if ( val )
    {
      ((void (__thiscall *)(_DWORD))this->vfptr[8].OnLoseFocus)(this);
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"AutoRun ON");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      v4 = (char *)&_value.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v4 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v4)(v4, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    else
    {
      StringInfo::StringInfo(&siError);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&_value, L"AutoRun OFF");
      StringInfo::SetLiteralValue(&siError, &_value, 1);
      v5 = (char *)&_value.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&_value.m_charbuffer[-1].m_data[8]) && v5 )
        (**(void (__thiscall ***)(_DWORD, _DWORD))v5)(v5, 1);
      ECM_UI::SendNotice_DisplayStringInfo(0x1Au, &siError);
    }
    StringInfo::~StringInfo(&siError);
    if ( apply_movement )
      ((void (__thiscall *)(CommandInterpreter *))v3->vfptr[2].OnAction)(v3);
  }
}

//----- (00723340) --------------------------------------------------------  // acclient.c:821114
void sub_723340()
{
  flt_8FA78C = 1000.0 + 1.0;
}

//----- (00723360) --------------------------------------------------------  // acclient.c:821120
void sub_723360()
{
  flt_8FA790 = 24.0 * 8.0;
}

//----- (00723380) --------------------------------------------------------  // acclient.c:821126
void sub_723380()
{
  flt_8FA794 = 24.0 * 0.5;
}

//----- (007233A0) --------------------------------------------------------  // acclient.c:821132
int _E101_48()
{
  const int result; // eax@1

  result = LOWEST_DATA_RATE_48;
  dword_8FA79C = LOWEST_DATA_RATE_48;
  return result;
}

//----- (007233B0) --------------------------------------------------------  // acclient.c:821142
void sub_7233B0()
{
  flt_8FA7A0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007233D0) --------------------------------------------------------  // acclient.c:821148
void _E105_62()
{
  dbl_8FA7A8 = 1.0 / 30.0;
}

//----- (007233F0) --------------------------------------------------------  // acclient.c:821154
void _E107_50()
{
  dbl_8FA7B0 = 1.0 / 5.0;
}

//----- (00723410) --------------------------------------------------------  // acclient.c:821160
void sub_723410()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8FA7B8, PFID_A8R8G8B8);
}

//----- (00723420) --------------------------------------------------------  // acclient.c:821166
int _E111_66()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't sit down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_sit_combat_1, v0);
  _wcscpy(cant_sit_combat_1.m_charbuffer->m_data, L"You can't sit down while in combat mode");
  return atexit(sub_790860);
}

//----- (00723460) --------------------------------------------------------  // acclient.c:821177
int _E114_72()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't lie down while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_lie_down_combat_1, v0);
  _wcscpy(cant_lie_down_combat_1.m_charbuffer->m_data, L"You can't lie down while in combat mode");
  return atexit(sub_790890);
}

//----- (007234A0) --------------------------------------------------------  // acclient.c:821188
int sub_7234A0()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't crouch while in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_crouch_combat_1, v0);
  _wcscpy(cant_crouch_combat_1.m_charbuffer->m_data, L"You can't crouch while in combat mode");
  return atexit(sub_7908C0);
}

//----- (007234E0) --------------------------------------------------------  // acclient.c:821199
int _E120_84()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_position_1, v0);
  _wcscpy(cant_emote_position_1.m_charbuffer->m_data, L"You can't use chat emotes from this position");
  return atexit(sub_7908F0);
}

//----- (00723520) --------------------------------------------------------  // acclient.c:821210
int _E123_54()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't use chat emotes in combat mode");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_emote_combat_1, v0);
  _wcscpy(cant_emote_combat_1.m_charbuffer->m_data, L"You can't use chat emotes in combat mode");
  return atexit(sub_790920);
}

//----- (00723560) --------------------------------------------------------  // acclient.c:821221
int _E126_62()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump from this position");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_position_1, v0);
  _wcscpy(cant_jump_position_1.m_charbuffer->m_data, L"You can't jump from this position");
  return atexit(sub_790950);
}

//----- (007235A0) --------------------------------------------------------  // acclient.c:821232
int _E129_56()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You can't jump while in the air");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_in_air_1, v0);
  _wcscpy(cant_jump_in_air_1.m_charbuffer->m_data, L"You can't jump while in the air");
  return atexit(sub_790980);
}

//----- (007235E0) --------------------------------------------------------  // acclient.c:821243
int _E132_56()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too loaded down to jump");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_load_1, v0);
  _wcscpy(cant_jump_load_1.m_charbuffer->m_data, L"You're too loaded down to jump");
  return atexit(sub_7909B0);
}

//----- (00723620) --------------------------------------------------------  // acclient.c:821254
int _E135_64()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You're too tired to jump!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_stamina_1, v0);
  _wcscpy(cant_jump_stamina_1.m_charbuffer->m_data, L"You're too tired to jump!");
  return atexit(_E136_98);
}

//----- (00723660) --------------------------------------------------------  // acclient.c:821265
int _E138_50()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You've jumped too recently!");
  PStringBase<unsigned short>::allocate_ref_buffer(&cant_jump_recent_1, v0);
  _wcscpy(cant_jump_recent_1.m_charbuffer->m_data, L"You've jumped too recently!");
  return atexit(_E139_98);
}

//----- (007236A0) --------------------------------------------------------  // acclient.c:821276
int _E141_52()
{
  unsigned int v0; // eax@1

  v0 = _wcslen(L"You are too tired to move!");
  PStringBase<unsigned short>::allocate_ref_buffer(&too_tired_1, v0);
  _wcscpy(too_tired_1.m_charbuffer->m_data, L"You are too tired to move!");
  return atexit(_E142_92);
}

//----- (007236E0) --------------------------------------------------------  // acclient.c:821287
int sub_7236E0()
{
  return atexit(nullsub_1039);
}

//----- (00790860) --------------------------------------------------------  // acclient.c:936633
void __cdecl sub_790860()
{
  char *v0; // esi@1

  v0 = (char *)&cant_sit_combat_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_sit_combat_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790890) --------------------------------------------------------  // acclient.c:936646
void __cdecl sub_790890()
{
  char *v0; // esi@1

  v0 = (char *)&cant_lie_down_combat_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_lie_down_combat_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007908C0) --------------------------------------------------------  // acclient.c:936659
void __cdecl sub_7908C0()
{
  char *v0; // esi@1

  v0 = (char *)&cant_crouch_combat_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_crouch_combat_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007908F0) --------------------------------------------------------  // acclient.c:936672
void __cdecl sub_7908F0()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_position_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_position_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790920) --------------------------------------------------------  // acclient.c:936685
void __cdecl sub_790920()
{
  char *v0; // esi@1

  v0 = (char *)&cant_emote_combat_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_emote_combat_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790950) --------------------------------------------------------  // acclient.c:936698
void __cdecl sub_790950()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_position_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_position_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790980) --------------------------------------------------------  // acclient.c:936711
void __cdecl sub_790980()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_in_air_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_in_air_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007909B0) --------------------------------------------------------  // acclient.c:936724
void __cdecl sub_7909B0()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_load_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_load_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (007909E0) --------------------------------------------------------  // acclient.c:936737
void __cdecl _E136_98()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_stamina_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_stamina_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790A10) --------------------------------------------------------  // acclient.c:936750
void __cdecl _E139_98()
{
  char *v0; // esi@1

  v0 = (char *)&cant_jump_recent_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&cant_jump_recent_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

//----- (00790A40) --------------------------------------------------------  // acclient.c:936763
void __cdecl _E142_92()
{
  char *v0; // esi@1

  v0 = (char *)&too_tired_1.m_charbuffer[-1].m_data[6];
  if ( !InterlockedDecrement((volatile LONG *)&too_tired_1.m_charbuffer[-1].m_data[8]) )
  {
    if ( v0 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))v0)(v0, 1);
  }
}

