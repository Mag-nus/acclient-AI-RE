/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CrashCleaners
   Object     : CORE\debug_common\CrashCleaners.obj
   Functions  : 10
   Addresses  : 0040DFE0 - 00725D90 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (0040DFE0) --------------------------------------------------------  // acclient.c:73635
char __thiscall CPluginManager::RemovePluginPrototype(CPluginManager *this, CPluginPrototype *pPlugin)
{
  unsigned int v2; // eax@1
  CPluginPrototype **v3; // edx@2
  char result; // al@5
  unsigned int v5; // edx@6
  unsigned int v6; // edx@7

  v2 = 0;
  if ( this->m_Plugins.m_num )
  {
    v3 = this->m_Plugins.m_data;
    while ( *v3 != pPlugin )
    {
      ++v2;
      ++v3;
      if ( v2 >= this->m_Plugins.m_num )
        goto LABEL_5;
    }
    pPlugin->m_pManager = 0;
    v5 = this->m_Plugins.m_num;
    if ( v2 < v5 )
    {
      v6 = v5 - 1;
      this->m_Plugins.m_num = v6;
      if ( v2 != v6 )
      {
        this->m_Plugins.m_data[v2] = this->m_Plugins.m_data[v6];
        this->m_Plugins.m_data[this->m_Plugins.m_num] = 0;
      }
    }
    result = 1;
  }
  else
  {
LABEL_5:
    result = 0;
  }
  return result;
}

//----- (0040E040) --------------------------------------------------------  // acclient.c:73677
void __cdecl CrashCleaners::CallCrashCleaners()
{
  unsigned int v0; // esi@2

  if ( !s_fCrashCleanersCalled )
  {
    v0 = 0;
    s_fCrashCleanersCalled = 1;
    if ( G_crashCleaners.m_Plugins.m_num )
    {
      do
        ((void (*)(void))G_crashCleaners.m_Plugins.m_data[v0++]->vfptr[1].__vecDelDtor)();
      while ( v0 < G_crashCleaners.m_Plugins.m_num );
    }
  }
}

//----- (0040E080) --------------------------------------------------------  // acclient.c:73695
void __thiscall CPluginManager::~CPluginManager(CPluginManager *this)
{
  unsigned int v1; // eax@1
  CPluginPrototype *v2; // esi@2
  unsigned int v3; // eax@3

  v1 = 0;
  if ( this->m_Plugins.m_num )
  {
    do
    {
      v2 = this->m_Plugins.m_data[v1++];
      v2->m_pManager = 0;
    }
    while ( v1 < this->m_Plugins.m_num );
  }
  v3 = this->m_Plugins.m_sizeAndDeallocate & 0x80000000;
  this->m_Plugins.m_num = 0;
  if ( v3 == 0x80000000 )
    operator delete[](this->m_Plugins.m_data);
}

//----- (0040E0C0) --------------------------------------------------------  // acclient.c:73718
void __thiscall CrashCleaner::~CrashCleaner(CrashCleaner *this)
{
  CrashCleaner *v1; // esi@1
  CPluginManager *v2; // ecx@1

  v1 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&CrashCleaner::vftable;
  CPluginManager::RemovePluginPrototype(&G_crashCleaners, (CPluginPrototype *)&this->vfptr);
  v2 = v1->m_pManager;
  v1->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v2 )
  {
    CPluginManager::RemovePluginPrototype(v2, (CPluginPrototype *)&v1->vfptr);
    v1->m_pManager = 0;
  }
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 794540: using guessed type int (__thiscall *CrashCleaner::vftable)(void *, char);

//----- (0040E0F0) --------------------------------------------------------  // acclient.c:73738
CPluginPrototype *__thiscall CPluginPrototype::vector_deleting_destructor(CPluginPrototype *this, unsigned int a2)
{
  CPluginPrototype *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  v3 = this->m_pManager;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, v2);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);

//----- (0040E130) --------------------------------------------------------  // acclient.c:73758
CrashCleaner *__thiscall CrashCleaner::scalar_deleting_destructor(CrashCleaner *this, unsigned int a2)
{
  CrashCleaner *v2; // esi@1
  CPluginManager *v3; // ecx@1

  v2 = this;
  this->vfptr = (CPluginPrototypeVtbl *)&CrashCleaner::vftable;
  CPluginManager::RemovePluginPrototype(&G_crashCleaners, (CPluginPrototype *)&this->vfptr);
  v3 = v2->m_pManager;
  v2->vfptr = (CPluginPrototypeVtbl *)&CPluginPrototype::vftable;
  if ( v3 )
  {
    CPluginManager::RemovePluginPrototype(v3, (CPluginPrototype *)&v2->vfptr);
    v2->m_pManager = 0;
  }
  if ( a2 & 1 )
    operator delete(v2);
  return v2;
}
// 794538: using guessed type int (__thiscall *CPluginPrototype::vftable)(void *, char);
// 794540: using guessed type int (__thiscall *CrashCleaner::vftable)(void *, char);

//----- (0040E180) --------------------------------------------------------  // acclient.c:73781
char __thiscall CPluginManager::AddPluginPrototype(CPluginManager *this, CPluginPrototype *pPlugin)
{
  CPluginManager *v2; // esi@1
  char result; // al@2
  unsigned int v4; // eax@3
  unsigned int v5; // eax@4

  v2 = this;
  if ( pPlugin->m_pManager )
  {
    result = 0;
  }
  else
  {
    v4 = this->m_Plugins.m_sizeAndDeallocate & 0x7FFFFFFF;
    if ( this->m_Plugins.m_num < v4
      || (v5 = SmartArray<char *,1>::get_new_size(v4 + 1),
          SmartArray<Logger::ILoggingOutputHandler *,1>::grow((SmartArray<unsigned short *,1> *)v2, v5)) )
      v2->m_Plugins.m_data[v2->m_Plugins.m_num++] = pPlugin;
    pPlugin->vfptr->OnPluggedIn(pPlugin, v2);
    result = 1;
  }
  return result;
}

//----- (0040E1E0) --------------------------------------------------------  // acclient.c:73807
void __thiscall CrashCleaner::CrashCleaner(CrashCleaner *this)
{
  this->m_pManager = 0;
  this->vfptr = (CPluginPrototypeVtbl *)&CrashCleaner::vftable;
  CPluginManager::AddPluginPrototype(&G_crashCleaners, (CPluginPrototype *)&this->vfptr);
}
// 794540: using guessed type int (__thiscall *CrashCleaner::vftable)(void *, char);

//----- (006C3A30) --------------------------------------------------------  // acclient.c:732049
int _E73_4()
{
  return atexit(_E74_7);
}

//----- (00725D90) --------------------------------------------------------  // acclient.c:823669
void __cdecl _E74_7()
{
  CPluginManager::~CPluginManager(&G_crashCleaners);
}

