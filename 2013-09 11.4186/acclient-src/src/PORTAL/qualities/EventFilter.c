/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : EventFilter
   Object     : PORTAL\qualities\EventFilter.obj
   Functions  : 4
   Addresses  : 006B1D70 - 006B1E70 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (006B1D70) --------------------------------------------------------  // acclient.c:715196
void __thiscall EventFilter::EventFilter(EventFilter *this)
{
  this->vfptr = (PackObjVtbl *)&EventFilter::vftable;
  this->num_events = 0;
  this->event_filter = 0;
}
// 803BDC: using guessed type int (__thiscall *EventFilter::vftable)(void *, char);

//----- (006B1D90) --------------------------------------------------------  // acclient.c:715205
unsigned int __thiscall EventFilter::Pack(EventFilter *this, void **addr, unsigned int size)
{
  unsigned int v3; // esi@1
  unsigned int result; // eax@1
  char *v5; // esi@2
  char *v6; // edi@2
  unsigned int v7; // esi@2

  v3 = this->num_events;
  result = 4 * v3 + 4;
  if ( size >= result )
  {
    *(_DWORD *)*addr = v3;
    v5 = (char *)*addr + 4;
    *addr = v5;
    v6 = v5;
    v7 = 0;
    if ( this->num_events )
    {
      do
      {
        *(_DWORD *)v6 = this->event_filter[v7];
        v6 = (char *)*addr + 4;
        *addr = v6;
        ++v7;
      }
      while ( v7 < this->num_events );
    }
  }
  return result;
}

//----- (006B1DE0) --------------------------------------------------------  // acclient.c:715238
int __thiscall EventFilter::UnPack(EventFilter *this, void **addr, unsigned int size)
{
  EventFilter *v3; // esi@1
  int result; // eax@2
  unsigned int v5; // ebx@3
  unsigned int v6; // eax@8

  v3 = this;
  if ( size >= 4 * this->num_events + 4 )
  {
    v5 = *(_DWORD *)*addr;
    *addr = (char *)*addr + 4;
    if ( v5 != this->num_events )
    {
      if ( this->event_filter )
      {
        operator delete[](this->event_filter);
        v3->event_filter = 0;
        v3->num_events = 0;
      }
      if ( v5 )
      {
        v3->event_filter = (unsigned int *)operator new[](4 * v5);
        v3->num_events = v5;
      }
    }
    v6 = 0;
    if ( v3->num_events )
    {
      do
      {
        v3->event_filter[v6] = *(_DWORD *)*addr;
        *addr = (char *)*addr + 4;
        ++v6;
      }
      while ( v6 < v3->num_events );
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (006B1E70) --------------------------------------------------------  // acclient.c:715285
EventFilter *__thiscall EventFilter::scalar_deleting_destructor(EventFilter *this, unsigned int a2)
{
  EventFilter *v2; // esi@1
  unsigned int *v3; // eax@1

  v2 = this;
  v3 = this->event_filter;
  this->vfptr = (PackObjVtbl *)&EventFilter::vftable;
  if ( v3 )
  {
    operator delete[](v3);
    v2->event_filter = 0;
    v2->num_events = 0;
  }
  v2->vfptr = (PackObjVtbl *)&PackObj::vftable;
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 79285C: using guessed type int (__thiscall *PackObj::vftable)(void *, char);
// 803BDC: using guessed type int (__thiscall *EventFilter::vftable)(void *, char);

