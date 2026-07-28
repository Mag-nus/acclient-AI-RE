/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : CPortalSummonSpell
   Object     : AC\accspells\CPortalSummonSpell.obj
   Functions  : 5
   Addresses  : 00598F20 - 00598FD0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00598F20) --------------------------------------------------------  // acclient.c:451176
int PortalSummonSpell::pack_size()
{
  return EtherealHook::pack_size() + 8;
}

//----- (00598F30) --------------------------------------------------------  // acclient.c:451182
void __thiscall PortalSummonSpell::PortalSummonSpell(PortalSummonSpell *this)
{
  PortalSummonSpell *v1; // esi@1

  v1 = this;
  Spell::Spell((Spell *)&this->vfptr);
  LODWORD(v1->_portal_lifetime) = LODWORD(dbl_7E4DA0);
  v1->vfptr = (PackObjVtbl *)&PortalSummonSpell::vftable;
  HIDWORD(v1->_portal_lifetime) = HIDWORD(dbl_7E4DA0);
}
// 7E4DA8: using guessed type int (__thiscall *PortalSummonSpell::vftable)(void *, char);

//----- (00598F60) --------------------------------------------------------  // acclient.c:451195
void __stdcall PortalSummonSpell::SetEqual(Spell *dst, Spell *src)
{
  if ( dst )
  {
    if ( src )
    {
      Spell::operator=((int)dst, (int)src);
      dst[1].vfptr = src[1].vfptr;
      dst[1]._spell_id = src[1]._spell_id;
    }
  }
}

//----- (00598F90) --------------------------------------------------------  // acclient.c:451209
unsigned int __thiscall PortalSummonSpell::Pack(PortalSummonSpell *this, void **addr, unsigned int size)
{
  PortalSummonSpell *v3; // esi@1
  unsigned int v4; // ebx@1

  v3 = this;
  v4 = ((int (*)(void))this->vfptr[3].UnPack)();
  if ( size >= v4 )
  {
    Spell::Pack((Spell *)&v3->vfptr, addr, size);
    *(double *)*addr = v3->_portal_lifetime;
    *addr = (char *)*addr + 8;
  }
  return v4;
}

//----- (00598FD0) --------------------------------------------------------  // acclient.c:451226
int __thiscall PortalSummonSpell::UnPack(PortalSummonSpell *this, void **addr, unsigned int size)
{
  PortalSummonSpell *v3; // edi@1
  int result; // eax@2
  void *v5; // ebx@3
  void *v6; // ecx@5

  v3 = this;
  if ( size >= ((int (*)(void))this->vfptr[3].UnPack)() )
  {
    v5 = *addr;
    result = Spell::UnPack((Spell *)&v3->vfptr, addr, size);
    if ( result )
    {
      v6 = *addr;
      LODWORD(v3->_portal_lifetime) = *(_DWORD *)*addr;
      HIDWORD(v3->_portal_lifetime) = *((_DWORD *)v6 + 1);
      *addr = (char *)*addr + 8;
      result = 1;
    }
    else
    {
      *addr = v5;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

