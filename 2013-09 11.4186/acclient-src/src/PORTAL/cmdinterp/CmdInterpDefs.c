/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CmdInterpDefs
   Object     : PORTAL\cmdinterp\CmdInterpDefs.obj
   Functions  : 5
   Addresses  : 006B4960 - 006B4B80 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B4960) --------------------------------------------------------  // acclient.c:718294
int __thiscall CommandList::RemoveCommand(CommandList *this, unsigned int command, float speed, int mouse)
{
  int v4; // ebx@1
  CommandList *v5; // esi@1
  CommandListElement *v6; // eax@2
  CommandListElement *v8; // ecx@4
  int v9; // ebx@4
  CommandListElement *v10; // ecx@6
  bool v11; // zf@6
  CommandListElement *v12; // eax@13
  CommandListElement *v13; // ecx@18
  CommandListElement *v14; // ecx@20

  v4 = 0;
  v5 = this;
  if ( !mouse )
  {
    v12 = this->head;
    if ( !this->head )
      return v4;
    while ( v12->command != command || v12 == this->mouse_command )
    {
      v12 = v12->next;
      if ( !v12 )
        return 0;
    }
    v13 = v12->prev;
    v4 = v12 == v5->head;
    if ( v13 )
    {
      v13->next = v12->next;
    }
    else
    {
      v14 = v12->next;
      v11 = v12->next == 0;
      v5->head = v12->next;
      if ( v11 )
      {
LABEL_24:
        v12->next = 0;
        v12->prev = 0;
        operator delete(v12);
        return v4;
      }
      v14->prev = 0;
    }
    if ( v12->next )
      v12->next->prev = v12->prev;
    goto LABEL_24;
  }
  v6 = this->mouse_command;
  if ( !v6 )
    return 0;
  v8 = v6->prev;
  v9 = v6 == v5->head;
  if ( v8 )
  {
    v8->next = v6->next;
    goto LABEL_8;
  }
  v10 = v6->next;
  v11 = v6->next == 0;
  v5->head = v6->next;
  if ( !v11 )
  {
    v10->prev = 0;
LABEL_8:
    if ( v6->next )
      v6->next->prev = v6->prev;
  }
  v6->next = 0;
  v6->prev = 0;
  if ( v5->mouse_command )
    operator delete(v5->mouse_command);
  v5->mouse_command = 0;
  return v9;
}

//----- (006B4A50) --------------------------------------------------------  // acclient.c:718380
int __thiscall CommandList::HeadIsMouse(CommandList *this)
{
  int result; // eax@2

  if ( this->head )
    result = this->head == this->mouse_command;
  else
    result = 0;
  return result;
}

//----- (006B4A70) --------------------------------------------------------  // acclient.c:718392
void __thiscall CommandList::ClearAllCommands(CommandList *this)
{
  CommandList *v1; // esi@1
  void *v2; // eax@2
  CommandListElement *v3; // ecx@2
  CommandListElement *v4; // ecx@4
  bool v5; // zf@4

  v1 = this;
  if ( this->head )
  {
    while ( 1 )
    {
      v2 = v1->head;
      v3 = v1->head->prev;
      if ( v3 )
        break;
      v4 = *(CommandListElement **)v2;
      v5 = *(_DWORD *)v2 == 0;
      v1->head = *(CommandListElement **)v2;
      if ( !v5 )
      {
        v4->prev = 0;
LABEL_6:
        if ( *(_DWORD *)v2 )
          *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
      }
      *(_DWORD *)v2 = 0;
      *((_DWORD *)v2 + 1) = 0;
      if ( v2 )
        operator delete(v2);
      if ( !v1->head )
        goto LABEL_11;
    }
    v3->next = *(CommandListElement **)v2;
    goto LABEL_6;
  }
LABEL_11:
  v1->mouse_command = 0;
}

//----- (006B4AD0) --------------------------------------------------------  // acclient.c:718434
void __thiscall CommandList::ClearKeyboardCommands(CommandList *this)
{
  CommandList *v1; // esi@1
  void *v2; // eax@2
  int v3; // ecx@3
  int v4; // ecx@5
  bool v5; // zf@5
  void *v6; // eax@14
  int v7; // ecx@14
  CommandListElement *v8; // ecx@16

  v1 = this;
  if ( this->head )
  {
    do
    {
      v2 = v1->head;
      if ( v1->head == v1->mouse_command )
        break;
      v3 = *((_DWORD *)v2 + 1);
      if ( v3 )
      {
        *(_DWORD *)v3 = *(_DWORD *)v2;
        goto LABEL_7;
      }
      v4 = *(_DWORD *)v2;
      v5 = *(_DWORD *)v2 == 0;
      v1->head = *(CommandListElement **)v2;
      if ( !v5 )
      {
        *(_DWORD *)(v4 + 4) = 0;
LABEL_7:
        if ( *(_DWORD *)v2 )
          *(_DWORD *)(*(_DWORD *)v2 + 4) = *((_DWORD *)v2 + 1);
      }
      *(_DWORD *)v2 = 0;
      *((_DWORD *)v2 + 1) = 0;
      if ( v2 )
        operator delete(v2);
    }
    while ( v1->head );
    if ( v1->head && v1->head->next )
    {
      while ( 1 )
      {
        v6 = v1->head->next;
        v7 = *((_DWORD *)v6 + 1);
        if ( v7 )
          break;
        v8 = *(CommandListElement **)v6;
        v5 = *(_DWORD *)v6 == 0;
        v1->head = *(CommandListElement **)v6;
        if ( !v5 )
        {
          v8->prev = 0;
LABEL_18:
          if ( *(_DWORD *)v6 )
            *(_DWORD *)(*(_DWORD *)v6 + 4) = *((_DWORD *)v6 + 1);
        }
        *(_DWORD *)v6 = 0;
        *((_DWORD *)v6 + 1) = 0;
        if ( v6 )
          operator delete(v6);
        if ( !v1->head->next )
          return;
      }
      *(_DWORD *)v7 = *(_DWORD *)v6;
      goto LABEL_18;
    }
  }
}

//----- (006B4B80) --------------------------------------------------------  // acclient.c:718507
void __thiscall CommandList::AddCommand(CommandList *this, unsigned int command, float speed, int mouse, int hold_run)
{
  CommandList *v5; // esi@1
  void *v6; // eax@1
  void *v7; // edi@2
  CommandListElement *v8; // eax@5
  CommandListElement *v9; // ecx@6
  CommandListElement *v10; // ecx@8
  bool v11; // zf@8

  v5 = this;
  v6 = operator new(0x14u);
  if ( v6 )
  {
    *(_DWORD *)v6 = 0;
    *((_DWORD *)v6 + 1) = 0;
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 3) = 1065353216;
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  *((_DWORD *)v7 + 2) = command;
  *((float *)v7 + 3) = speed;
  *((_DWORD *)v7 + 4) = hold_run;
  if ( mouse )
  {
    v8 = v5->mouse_command;
    if ( !v8 )
    {
LABEL_14:
      v5->mouse_command = (CommandListElement *)v7;
      goto LABEL_15;
    }
    v9 = v8->prev;
    if ( v9 )
    {
      v9->next = v8->next;
    }
    else
    {
      v10 = v8->next;
      v11 = v8->next == 0;
      v5->head = v8->next;
      if ( v11 )
      {
LABEL_12:
        v8->next = 0;
        v8->prev = 0;
        if ( v5->mouse_command )
          operator delete(v5->mouse_command);
        goto LABEL_14;
      }
      v10->prev = 0;
    }
    if ( v8->next )
      v8->next->prev = v8->prev;
    goto LABEL_12;
  }
LABEL_15:
  *((_DWORD *)v7 + 1) = 0;
  *(_DWORD *)v7 = v5->head;
  if ( v5->head )
    v5->head->prev = (CommandListElement *)v7;
  v5->head = (CommandListElement *)v7;
}

