/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CScriptManager
   Object     : PORTAL\cphysobj\CScriptManager.obj
   Functions  : 7
   Addresses  : 0051B2F0 - 006FC8E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0051B2F0) --------------------------------------------------------  // acclient.c:329058
void __thiscall ScriptManager::ScriptManager(ScriptManager *this, CPhysicsObj *_physobj)
{
  this->physobj = _physobj;
  this->curr_data = 0;
  this->last_data = 0;
  this->hook_index = -1;
  *(_QWORD *)&this->next_hook_time = 0i64;
}

//----- (0051B310) --------------------------------------------------------  // acclient.c:329068
int __thiscall ScriptManager::AddScriptInternal(ScriptManager *this, PhysicsScript *script)
{
  ScriptManager *v2; // esi@1
  void *v3; // eax@1
  ScriptData *v4; // ecx@4
  unsigned int v5; // edi@6
  ScriptData *v6; // ecx@7
  int result; // eax@8
  long double v8; // st7@9

  v2 = this;
  v3 = operator new(0x10u);
  if ( v3 )
  {
    *(_DWORD *)v3 = 0;
    *((_DWORD *)v3 + 1) = 0;
    *((_DWORD *)v3 + 2) = 0;
    *((_DWORD *)v3 + 3) = 0;
  }
  else
  {
    v3 = 0;
  }
  v4 = v2->last_data;
  if ( v4 )
  {
    *(double *)v3 = v4->script->length + v4->start_time;
  }
  else
  {
    v5 = Timer::cur_time.Param;
    *(_DWORD *)v3 = Timer::cur_time.Cmd;
    *((_DWORD *)v3 + 1) = v5;
  }
  *((_DWORD *)v3 + 2) = script;
  v6 = v2->last_data;
  if ( v6 )
  {
    v6->next_data = (ScriptData *)v3;
    v2->last_data = (ScriptData *)v3;
    result = 1;
  }
  else
  {
    v2->curr_data = (ScriptData *)v3;
    v2->last_data = (ScriptData *)v3;
    v2->hook_index = -1;
    v8 = *(double *)**(_DWORD **)(*((_DWORD *)v3 + 2) + 56) + *(double *)v3;
    result = 1;
    v2->next_hook_time = v8;
  }
  return result;
}

//----- (0051B3A0) --------------------------------------------------------  // acclient.c:329123
int __thiscall ScriptManager::AddScript(ScriptManager *this, IDClass<_tagDataID,32,0> script_id)
{
  ScriptManager *v2; // esi@1
  QualifiedDataID *v3; // eax@1
  int v4; // eax@1
  bool v5; // zf@2
  int result; // eax@2
  QualifiedDataID v7; // [sp+8h] [bp-8h]@1

  v2 = this;
  QualifiedDataID::QualifiedDataID(&v7, script_id, 0x2Bu);
  v4 = DBObj::Get(v3);
  if ( !v4 || (v5 = ScriptManager::AddScriptInternal(v2, (PhysicsScript *)v4) == 0, result = 1, v5) )
    result = 0;
  return result;
}

//----- (0051B3F0) --------------------------------------------------------  // acclient.c:329141
CAnimHook *__thiscall ScriptManager::NextHook(ScriptManager *this)
{
  int v1; // eax@1
  int v2; // edx@1
  ScriptData *v3; // eax@1
  PhysicsScript *v4; // esi@1
  int v5; // edi@1
  CAnimHook *result; // eax@2
  ScriptData *v7; // esi@5

  v1 = this->hook_index + 1;
  this->hook_index = v1;
  v2 = v1;
  v3 = this->curr_data;
  v4 = v3->script;
  v5 = v4->script_data.num_in_array;
  if ( v2 < v5 )
  {
    if ( v2 + 1 >= v5 )
    {
      v7 = v3->next_data;
      if ( v7 )
      {
        this->next_hook_time = (*v7->script->script_data.data)->start_time + v7->start_time;
        result = v3->script->script_data.data[v2]->hook;
      }
      else
      {
        LODWORD(this->next_hook_time) = 0;
        HIDWORD(this->next_hook_time) = -1074790400;
        result = v3->script->script_data.data[v2]->hook;
      }
    }
    else
    {
      this->next_hook_time = v4->script_data.data[v2 + 1]->start_time + v3->start_time;
      result = v3->script->script_data.data[v2]->hook;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051B480) --------------------------------------------------------  // acclient.c:329188
void __thiscall ScriptManager::UpdateScripts(ScriptManager *this)
{
  ScriptManager *v1; // esi@1
  CAnimHook *v2; // eax@3
  ScriptData *v3; // eax@5
  ScriptData *v4; // edi@5
  ScriptData *v5; // eax@5
  PhysicsScript *v6; // ecx@9

  v1 = this;
  while ( v1->curr_data )
  {
    if ( COERCE_DOUBLE(Timer::cur_time.Cmd) < v1->next_hook_time )
      break;
    v2 = ScriptManager::NextHook(v1);
    if ( v2 )
    {
      v2->vfptr->Execute(v2, v1->physobj);
    }
    else
    {
      v3 = v1->curr_data;
      v4 = v3;
      v5 = v3->next_data;
      v1->curr_data = v5;
      v1->hook_index = -1;
      if ( v5 )
      {
        v1->next_hook_time = (*v5->script->script_data.data)->start_time + v5->start_time;
      }
      else
      {
        LODWORD(v1->next_hook_time) = 0;
        HIDWORD(v1->next_hook_time) = -1074790400;
        v1->last_data = 0;
      }
      if ( v4 )
      {
        v6 = v4->script;
        if ( v6 )
          ((void (*)(void))v6->vfptr->Release)();
        operator delete(v4);
      }
    }
  }
}

//----- (0051B510) --------------------------------------------------------  // acclient.c:329236
void __thiscall ScriptManager::~ScriptManager(ScriptManager *this)
{
  ScriptManager *v1; // esi@1
  ScriptData *v2; // eax@2
  ScriptData *v3; // edi@2
  ScriptData *v4; // eax@2
  PhysicsScript *v5; // ecx@6

  v1 = this;
  while ( v1->curr_data )
  {
    v2 = v1->curr_data;
    v3 = v2;
    v4 = v2->next_data;
    v1->curr_data = v4;
    v1->hook_index = -1;
    if ( v4 )
    {
      v1->next_hook_time = (*v4->script->script_data.data)->start_time + v4->start_time;
    }
    else
    {
      LODWORD(v1->next_hook_time) = 0;
      HIDWORD(v1->next_hook_time) = -1074790400;
      v1->last_data = 0;
    }
    if ( v3 )
    {
      v5 = v3->script;
      if ( v5 )
        ((void (*)(void))v5->vfptr->Release)();
      operator delete(v3);
    }
  }
}

//----- (006FC8E0) --------------------------------------------------------  // acclient.c:784895
int sub_6FC8E0()
{
  return atexit(nullsub_1105);
}

