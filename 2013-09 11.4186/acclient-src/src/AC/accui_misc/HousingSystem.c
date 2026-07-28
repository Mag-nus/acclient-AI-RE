/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : HousingSystem
   Object     : AC\accui_misc\HousingSystem.obj
   Functions  : 30
   Addresses  : 005858A0 - 00709B40 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005858A0) --------------------------------------------------------  // acclient.c:430488
void __thiscall ACCWeenieObject::SetRestrictions(ACCWeenieObject *this, RestrictionDB *db)
{
  ACCWeenieObject *v2; // esi@1
  int v3; // ecx@1
  RestrictionDB *v4; // eax@2
  RestrictionDB *v5; // eax@3

  v2 = this;
  v3 = (int)this->pwd._db;
  if ( v3 )
  {
    RestrictionDB::operator=(v3, (int)db);
  }
  else
  {
    v4 = (RestrictionDB *)operator new(0x84u);
    if ( v4 )
    {
      RestrictionDB::RestrictionDB(v4, db);
      v2->pwd._db = v5;
    }
    else
    {
      v2->pwd._db = 0;
    }
  }
}

//----- (005858F0) --------------------------------------------------------  // acclient.c:430517
void __thiscall ClientHousingSystem::~ClientHousingSystem(ClientHousingSystem *this)
{
  ClientHousingSystem *v1; // eax@1
  NoticeHandler *v2; // ecx@1

  v1 = this;
  v2 = (NoticeHandler *)&this->vfptr;
  v1->vfptr = (InterfaceVtbl *)&ClientHousingSystem::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  v1->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  v2->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  NoticeHandler::~NoticeHandler(v2);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E1D24: using guessed type __int32 (__stdcall *ClientHousingSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);

//----- (00585920) --------------------------------------------------------  // acclient.c:430535
void ClientHousingSystem::OnShutdown()
{
  if ( ClientHousingSystem::s_pHousingSystem )
  {
    ((void (*)(void))ClientHousingSystem::s_pHousingSystem->vfptr->Release)();
    ClientHousingSystem::s_pHousingSystem = 0;
  }
}
// 8709AC: using guessed type struct ClientHousingSystem *ClientHousingSystem::s_pHousingSystem;

//----- (00585940) --------------------------------------------------------  // acclient.c:430546
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_HouseProfile(unsigned int lord, HouseProfile *prof)
{
  CM_House::SendNotice_UpdateHouseProfile(lord, prof);
  return 0;
}

//----- (00585960) --------------------------------------------------------  // acclient.c:430553
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_HouseTransaction(unsigned int etype)
{
  CM_House::SendNotice_FailedHouseTransaction(etype);
  return 0;
}

//----- (00585980) --------------------------------------------------------  // acclient.c:430560
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_HouseData(HouseData *data)
{
  CM_House::SendNotice_UpdateHouseData(data);
  return 0;
}

//----- (005859A0) --------------------------------------------------------  // acclient.c:430567
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_UpdateRentTime(int rent_time)
{
  CM_House::SendNotice_UpdateRentTime(rent_time);
  return 0;
}

//----- (005859C0) --------------------------------------------------------  // acclient.c:430574
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_UpdateRentPayment(HousePaymentList *rent)
{
  CM_House::SendNotice_UpdateRentPayment(rent);
  return 0;
}

//----- (005859E0) --------------------------------------------------------  // acclient.c:430581
unsigned int __stdcall ClientHousingSystem::Handle_House__Recv_UpdateRestrictions(char wts, unsigned int sender, RestrictionDB *db)
{
  unsigned int v4; // eax@3
  HashBaseData<unsigned long> *v5; // esi@6

  if ( sender )
  {
    if ( SmartBox::smartbox )
      v4 = SmartBox::smartbox->player_id;
    else
      v4 = 0;
    if ( sender != v4 )
    {
      v5 = ClientObjMaintSystem::GetWeenieObject(sender);
      if ( v5 )
      {
        if ( ACCWeenieObject::UpdateHouseRestrictionTS((ACCWeenieObject *)v5, wts) )
          ACCWeenieObject::SetRestrictions((ACCWeenieObject *)v5, db);
      }
    }
  }
  return 0;
}

//----- (00585A40) --------------------------------------------------------  // acclient.c:430606
TResult *__thiscall ClientHousingSystem::QueryInterface(ClientHousingSystem *this, TResult *result, Turbine_GUID *i_rcInterface, void **o_ppvInterface)
{
  _GUID *v4; // eax@2
  int v5; // edx@4
  TResult *v6; // eax@10
  int v7; // esi@12
  int v8; // edx@12
  char *v9; // esi@12

  if ( _S127_19 & 1 )
  {
    v4 = Offsets_12[0].key;
  }
  else
  {
    v4 = (_GUID *)&ClientHousingSystem_InterfaceType_63;
    _S127_19 |= 1u;
    Offsets_12[0].key = (_GUID *)&ClientHousingSystem_InterfaceType_63;
    dword_870A38 = 0;
    dword_870A3C = (int)&ClientSystem_InterfaceType_91;
    dword_870A40 = 0;
    dword_870A44 = (int)&stru_7E1D10;
    dword_870A48 = 0;
    dword_870A4C = 0;
    dword_870A50 = 0;
  }
  v5 = (int)Offsets_12;
  if ( v4 )
  {
    while ( v4->Data1 != i_rcInterface->m_data1
         || *(_DWORD *)&v4->Data2 != *(_DWORD *)&i_rcInterface->m_data2
         || *(_DWORD *)&v4->Data4[0] != *(_DWORD *)&i_rcInterface->m_data4[0]
         || *(_DWORD *)&v4->Data4[4] != *(_DWORD *)&i_rcInterface->m_data4[4] )
    {
      v4 = *(_GUID **)(v5 + 8);
      v5 += 8;
      if ( !v4 )
        goto LABEL_10;
    }
    if ( o_ppvInterface )
    {
      v7 = *(_DWORD *)(v5 + 4);
      v8 = *(int *)((char *)&this->vfptr + v7);
      v9 = (char *)this + v7;
      (*(void (__thiscall **)(char *))(v8 + 16))(v9);
      *o_ppvInterface = v9;
    }
    v6 = result;
    result->m_val = 0;
  }
  else
  {
LABEL_10:
    v6 = result;
    result->m_val = -2147467262;
  }
  return v6;
}
// 870A38: using guessed type int dword_870A38;
// 870A3C: using guessed type int dword_870A3C;
// 870A40: using guessed type int dword_870A40;
// 870A44: using guessed type int dword_870A44;
// 870A48: using guessed type int dword_870A48;
// 870A4C: using guessed type int dword_870A4C;
// 870A50: using guessed type int dword_870A50;

//----- (00585B10) --------------------------------------------------------  // acclient.c:430673
unsigned int __thiscall ClientHousingSystem::Release(ClientHousingSystem *this)
{
  ClientHousingSystem *v1; // esi@1
  unsigned int v2; // edi@1

  v1 = this;
  v2 = ReferenceCountTemplate<1048576,2>::Release((ReferenceCountTemplate<1048576,2> *)&this->m_cTurbineRefCount.vfptr);
  if ( !v2 && v1 )
  {
    ClientHousingSystem::~ClientHousingSystem(v1);
    operator delete(v1);
  }
  return v2;
}

//----- (00585B40) --------------------------------------------------------  // acclient.c:430689
void __thiscall ClientHousingSystem::ClientHousingSystem(ClientHousingSystem *this)
{
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (InterfaceVtbl *)&ClientHousingSystem::vftable;
  this->vfptr = (NoticeHandlerVtbl *)&ClientHousingSystem::vftable;
  this->m_cTurbineRefCount.m_cRef = 1;
  this->m_cTurbineRefCount.vfptr = (ReferenceCountTemplate<1048576,2>Vtbl *)&ReferenceCountTemplate<1048576,2>::vftable;
  ClientHousingSystem::s_pHousingSystem = this;
  InterlockedIncrement((volatile LONG *)&this->m_cTurbineRefCount.m_cRef);
}
// 792B6C: using guessed type int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char);
// 7BF328: using guessed type bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this);
// 7E1D24: using guessed type __int32 (__stdcall *ClientHousingSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject);
// 8709AC: using guessed type struct ClientHousingSystem *ClientHousingSystem::s_pHousingSystem;

//----- (00585B80) --------------------------------------------------------  // acclient.c:430705
unsigned int __thiscall ClientHousingSystem::Handle_House__Recv_UpdateHAR(ClientHousingSystem *this, HAR *har)
{
  ClientSystem *v2; // esi@1
  char *v3; // esi@1
  AC1Legacy::PSRefBuffer<char> *v4; // esi@4
  AC1Legacy::PStringBase<char> spew; // [sp+4h] [bp-4h]@1

  spew.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v2 = (ClientSystem *)this;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  HAR::Dump(har, &spew, 0);
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&har,
    0,
    spew.m_buffer->m_data);
  ClientSystem::AddTextToScroll(v2, (PStringBase<unsigned short> *)&har, 0, 1, 0);
  v3 = (char *)&har[-1]._roommate_list;
  if ( !InterlockedDecrement((volatile LONG *)&har[-1]._roommate_list._head) && v3 )
    (**(void (__thiscall ***)(char *, signed int))v3)(v3, 1);
  v4 = spew.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&spew.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00585C20) --------------------------------------------------------  // acclient.c:430732
void __thiscall ClientHousingSystem::DisplayListOfCoords(ClientHousingSystem *this, PackableList<unsigned long> *coords)
{
  PackableLLNode<unsigned long> *v2; // eax@1
  int v3; // ecx@3
  int v4; // eax@5
  unsigned __int64 v5; // st7@7
  char *v6; // esi@7
  PStringBase<unsigned short> i_text; // [sp+24h] [bp-84h]@7
  int px; // [sp+28h] [bp-80h]@3
  int py; // [sp+2Ch] [bp-7Ch]@3
  int v10; // [sp+30h] [bp-78h]@7
  ClientSystem *v11; // [sp+34h] [bp-74h]@1
  PackableLLIter<unsigned long> iter; // [sp+38h] [bp-70h]@2
  char coordString[100]; // [sp+40h] [bp-68h]@7

  v2 = coords->head;
  v11 = (ClientSystem *)this;
  if ( v2 )
  {
    iter._current = v2;
    do
    {
      LandDefs::gid_to_lcoord(iter._current->data, &px, &py);
      v3 = (int)"E";
      if ( px < 1024 )
        v3 = (int)"W";
      v4 = (int)"N";
      if ( py < 1024 )
        v4 = (int)"S";
      v10 = py - 1024;
      *(double *)&v5 = fabs((double)(py - 1024) * 0.1 + 0.5);
      __snprintf(
        coordString,
        0x63u,
        "     %.1f%s, %.1f%s\n",
        v5,
        v5 >> 32,
        v4,
        fabs((double)(px - 1024) * 0.1 + 0.5),
        v3);
      PStringBase<unsigned short>::PStringBase<unsigned short>(&i_text, 0, coordString);
      ClientSystem::AddTextToScroll(v11, &i_text, 0, 1, 0);
      v6 = (char *)&i_text.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&i_text.m_charbuffer[-1].m_data[8]) )
      {
        if ( v6 )
          (**(void (__thiscall ***)(char *, signed int))v6)(v6, 1);
      }
      iter._current = iter._current->next;
    }
    while ( iter._current );
  }
}

//----- (00585D50) --------------------------------------------------------  // acclient.c:430787
unsigned int __thiscall ClientHousingSystem::Handle_House__Recv_AvailableHouses(ClientHousingSystem *this, unsigned int houseType, PackableList<unsigned long> *houses, int nHouses)
{
  AC1Legacy::PSRefBuffer<char> *v4; // edi@1
  ClientSystem *v5; // ebx@1
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@7
  char *v7; // esi@7
  AC1Legacy::PStringBase<char> text; // [sp+10h] [bp-4h]@1

  v4 = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  v5 = (ClientSystem *)this;
  text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  switch ( houseType )
  {
    case 1u:
      AC1Legacy::PStringBase<char>::set(&text, "cottages");
      goto LABEL_6;
    case 2u:
      AC1Legacy::PStringBase<char>::set(&text, "villas");
      goto LABEL_6;
    case 3u:
      AC1Legacy::PStringBase<char>::set(&text, "mansions");
      goto LABEL_6;
    case 4u:
      AC1Legacy::PStringBase<char>::set(&text, "apartments");
LABEL_6:
      v4 = text.m_buffer;
      break;
    default:
      break;
  }
  text.m_buffer = (AC1Legacy::PSRefBuffer<char> *)AC1Legacy::PStringBase<char>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<char>::s_NullBuffer + 4));
  AC1Legacy::PStringBase<char>::sprintf(&text, "There are %d %s available.\n", nHouses, v4->m_data);
  v6 = text.m_buffer;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (PStringBase<unsigned short> *)&text,
    0,
    text.m_buffer->m_data);
  ClientSystem::AddTextToScroll(v5, (PStringBase<unsigned short> *)&text, 0, 1, 0);
  v7 = (char *)&text.m_buffer[-1].m_cRef;
  if ( !InterlockedDecrement((volatile LONG *)&text.m_buffer[-1].m_cRef + 1) && v7 )
    (**(void (__thiscall ***)(char *, signed int))v7)(v7, 1);
  if ( houseType != 4 )
  {
    ClientHousingSystem::DisplayListOfCoords((ClientHousingSystem *)v5, houses);
    if ( nHouses > 400 )
      ClientSystem::AddTextToScroll(
        v5,
        "There were too many houses to display all the locations. Only the first 400 locations are displayed here.",
        0,
        1,
        0);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
    v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
  if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  return 0;
}
// 8EE10C: using guessed type int AC1Legacy::PStringBase<char>::s_NullBuffer;

//----- (00709A00) --------------------------------------------------------  // acclient.c:796852
void sub_709A00()
{
  flt_8709CC = 1000.0 + 1.0;
}

//----- (00709A20) --------------------------------------------------------  // acclient.c:796858
void sub_709A20()
{
  flt_8709D0 = 24.0 * 8.0;
}

//----- (00709A40) --------------------------------------------------------  // acclient.c:796864
void sub_709A40()
{
  flt_8709D4 = 24.0 * 0.5;
}

//----- (00709A60) --------------------------------------------------------  // acclient.c:796870
int sub_709A60()
{
  return atexit(nullsub_1355);
}

//----- (00709A70) --------------------------------------------------------  // acclient.c:796876
int sub_709A70()
{
  return atexit(nullsub_1356);
}

//----- (00709A80) --------------------------------------------------------  // acclient.c:796882
int sub_709A80()
{
  return atexit(nullsub_1357);
}

//----- (00709A90) --------------------------------------------------------  // acclient.c:796888
void sub_709A90()
{
  flt_8709D8 = 0.00019999999 * 3.0 + 0.1;
}

//----- (00709AB0) --------------------------------------------------------  // acclient.c:796894
void _E108_95()
{
  dbl_8709E0 = 1.0 / 30.0;
}

//----- (00709AD0) --------------------------------------------------------  // acclient.c:796900
void _E110_79()
{
  dbl_8709E8 = 1.0 / 5.0;
}

//----- (00709AF0) --------------------------------------------------------  // acclient.c:796906
void sub_709AF0()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8709F0, PFID_A8R8G8B8);
}

//----- (00709B00) --------------------------------------------------------  // acclient.c:796912
void _E115_78()
{
  dword_870A28 = 1024;
}

//----- (00709B10) --------------------------------------------------------  // acclient.c:796918
void _E117_74()
{
  dword_870A2C = 0x7FFF;
}

//----- (00709B20) --------------------------------------------------------  // acclient.c:796924
int _E119_28()
{
  const int result; // eax@1

  result = dword_870A28;
  dword_870A30 = dword_870A28;
  return result;
}

//----- (00709B30) --------------------------------------------------------  // acclient.c:796934
int _E121_69()
{
  return atexit(_E122_96);
}

//----- (00709B40) --------------------------------------------------------  // acclient.c:796940
int sub_709B40()
{
  return atexit(nullsub_1354);
}

