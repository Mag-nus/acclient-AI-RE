/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : InterfaceEnumerator
   Object     : PORTAL\newnet\InterfaceEnumerator.obj
   Functions  : 2
   Addresses  : 005AB540 - 005AB5E0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005AB540) --------------------------------------------------------  // acclient.c:469152
void __thiscall InterfaceEnumerator::InterfaceEnumerator(InterfaceEnumerator *this)
{
  InterfaceEnumerator *v1; // esi@1
  char **v2; // edi@1
  char *i; // eax@1
  int v4; // edx@3
  void *v5; // eax@4
  int v6; // ecx@4
  int v7; // eax@4
  char MyName[256]; // [sp+8h] [bp-100h]@1

  v1 = this;
  NetInitializer::NetInitializer();
  v1->numInterfaces_ = 0;
  v1->interfaces_ = 0;
  gethostname(MyName, 256);
  v2 = gethostbyname(MyName)->h_addr_list;
  v1->numInterfaces_ = 0;
  for ( i = *v2; i; i = v2[v4] )
  {
    if ( !*(_DWORD *)i )
      break;
    v4 = v1->numInterfaces_ + 1;
    v1->numInterfaces_ = v4;
  }
  v5 = operator new[](4 * v1->numInterfaces_);
  v6 = v1->numInterfaces_;
  v1->interfaces_ = (in_addr *)v5;
  v7 = 0;
  if ( v6 > 0 )
  {
    do
    {
      v1->interfaces_[v7].S_un.S_addr = *(_DWORD *)v2[v7];
      ++v7;
    }
    while ( v7 < v1->numInterfaces_ );
  }
}

//----- (005AB5E0) --------------------------------------------------------  // acclient.c:469193
void __thiscall InterfaceEnumerator::~InterfaceEnumerator(InterfaceEnumerator *this)
{
  operator delete[](this->interfaces_);
  NetInitializer::~NetInitializer();
}

