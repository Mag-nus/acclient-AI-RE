/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ClientSystem
   Object     : AC\accui_misc\ClientSystem.obj
   Functions  : 16
   Addresses  : 00563C50 - 00708660 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00563C50) --------------------------------------------------------  // acclient.c:401101
void __thiscall ClientSystem::AddTextToScroll(ClientSystem *this, PStringBase<unsigned short> *i_text, unsigned int i_logTextType, bool i_sendToAPI, unsigned int i_nOverrideDestination)
{
  unsigned __int16 *v5; // esi@1
  IACPlugin *v6; // eax@5
  PSRefBufferCharData<unsigned short> *v7; // ecx@7
  CPlayerSystem *v8; // eax@7
  ListNode<PStringBase<unsigned short> > *i; // edi@8
  char *v10; // esi@11
  int v11; // edx@13
  char *v12; // esi@14
  int v13; // edx@16
  CPlayerSystem *v14; // eax@20
  struct tm *v15; // eax@21
  int v16; // eax@23
  char *v17; // esi@24
  int v18; // eax@26
  char *v19; // esi@27
  int v20; // edx@29
  char *v21; // esi@30
  char *v22; // esi@31
  int v23; // eax@33
  int v24; // edx@37
  PStringBase<unsigned short> v25; // [sp+0h] [bp-95Ch]@7
  PStringBase<unsigned short> tmp; // [sp+14h] [bp-948h]@10
  PStringBase<unsigned short> strFinalString; // [sp+18h] [bp-944h]@7
  PStringBase<unsigned short> strPrefix; // [sp+1Ch] [bp-940h]@19
  int bEat; // [sp+20h] [bp-93Ch]@1
  PStringBase<unsigned short> str; // [sp+24h] [bp-938h]@11
  ClientSystem *v31; // [sp+28h] [bp-934h]@1
  List<PStringBase<unsigned short> > explodedList; // [sp+2Ch] [bp-930h]@8
  StringInfo siPrefix; // [sp+3Ch] [bp-920h]@31
  StringInfo siMessage; // [sp+CCh] [bp-890h]@31
  wchar_t time[1024]; // [sp+15Ch] [bp-800h]@21

  v5 = 0;
  v31 = this;
  bEat = 0;
  if ( !i_sendToAPI )
    goto LABEL_40;
  if ( APIManager::APIIsReady() )
  {
    if ( i_text->m_charbuffer )
      v5 = SysAllocString(i_text->m_charbuffer->m_data);
    v6 = APIManager::GetACPlugin();
    ((void (__stdcall *)(IACPlugin *, unsigned __int16 *, unsigned int, int *))v6->vfptr[2].AddRef)(
      v6,
      v5,
      i_logTextType,
      &bEat);
    SysFreeString(v5);
  }
  if ( !bEat )
  {
LABEL_40:
    strFinalString.m_charbuffer = i_text->m_charbuffer;
    InterlockedIncrement((volatile LONG *)&strFinalString.m_charbuffer[-1].m_data[8]);
    v25.m_charbuffer = v7;
    PStringBase<unsigned short>::PStringBase<unsigned short>(&v25, L"\n");
    PStringBase<unsigned short>::trim(&strFinalString, 1, 1, v25);
    v8 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::FilterLanguage((PlayerModule *)&v8->playerModule.vfptr) )
    {
      explodedList.vfptr = (List<PStringBase<unsigned short> >Vtbl *)&List<PStringBase<unsigned short>>::vftable;
      explodedList._head = 0;
      explodedList._tail = 0;
      explodedList._num_elements = 0;
      PSUtils::explode(&strFinalString, 0x20u, &explodedList);
      for ( i = explodedList._head; i; i = i->next )
      {
        tmp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
        InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
        if ( TabooTableAdaptor::CheckCensorsW(&i->data, 1u, 1u, &tmp) )
        {
          PStringBase<unsigned short>::PStringBase<unsigned short>(&str, L"****");
          PStringBase<unsigned short>::replace(&strFinalString, &i->data, &str);
          v10 = (char *)&str.m_charbuffer[-1].m_data[6];
          if ( !InterlockedDecrement((volatile LONG *)&str.m_charbuffer[-1].m_data[8]) )
          {
            if ( v10 )
            {
              v11 = *(_DWORD *)v10;
              v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
              (*(void (__thiscall **)(char *, signed int))v11)(v10, 1);
            }
          }
        }
        v12 = (char *)&tmp.m_charbuffer[-1].m_data[6];
        if ( !InterlockedDecrement((volatile LONG *)&tmp.m_charbuffer[-1].m_data[8]) )
        {
          if ( v12 )
          {
            v13 = *(_DWORD *)v12;
            v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
            (*(void (__thiscall **)(char *, signed int))v13)(v12, 1);
          }
        }
      }
      explodedList.vfptr = (List<PStringBase<unsigned short> >Vtbl *)&List<PStringBase<unsigned short>>::vftable;
      List<PStringBase<unsigned short>>::flush(&explodedList);
    }
    strPrefix.m_charbuffer = (PSRefBufferCharData<unsigned short> *)PStringBase<unsigned short>::s_NullBuffer;
    InterlockedIncrement((volatile LONG *)PStringBase<unsigned short>::s_NullBuffer - 4);
    if ( i_logTextType == 26 )
      goto LABEL_41;
    v14 = CPlayerSystem::GetPlayerSystem();
    if ( (unsigned __int8)PlayerModule::DisplayTimeStamps((PlayerModule *)&v14->playerModule.vfptr) )
    {
      tmp.m_charbuffer = (PSRefBufferCharData<unsigned short> *)Timer::get_real_time();
      v15 = _localtime((const time_t *)&tmp);
      _wcsftime(time, 0x400u, L"%#H:%M:%S ", v15);
      PStringBase<unsigned short>::set(&strPrefix, time);
    }
    if ( ClientSystem::s_pLogFile
      && (v25.m_charbuffer = strFinalString.m_charbuffer,
          v16 = _fprintf(ClientSystem::s_pLogFile, "%ls%ls\n", strPrefix.m_charbuffer, strFinalString.m_charbuffer),
          v16 > 2048) )
    {
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)v16;
      PStringBase<unsigned short>::PStringBase<unsigned short>(
        &tmp,
        0,
        L"Wrote long string (%d characters) to log file instead of to the screen.\n",
        v16);
      ClientSystem::AddTextToScroll(v31, &tmp, i_logTextType, 1, 0);
      v17 = (char *)&tmp.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&tmp.m_charbuffer[-1].m_data[8]) && v17 )
      {
        v18 = *(_DWORD *)v17;
        v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(char *, signed int))v18)(v17, 1);
      }
      v19 = (char *)&strPrefix.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strPrefix.m_charbuffer[-1].m_data[8]) && v19 )
      {
        v20 = *(_DWORD *)v19;
        v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(char *, signed int))v20)(v19, 1);
      }
      v21 = (char *)&strFinalString.m_charbuffer[-1].m_data[6];
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)strFinalString.m_charbuffer - 16);
    }
    else
    {
LABEL_41:
      StringInfo::StringInfo(&siMessage);
      StringInfo::SetLiteralValue(&siMessage, &strFinalString, 1);
      StringInfo::StringInfo(&siPrefix);
      StringInfo::SetLiteralValue(&siPrefix, &strPrefix, 1);
      ECM_UI::SendNotice_DisplayFinalStringInfo(i_logTextType, &siMessage, &siPrefix, i_nOverrideDestination);
      StringInfo::~StringInfo(&siPrefix);
      StringInfo::~StringInfo(&siMessage);
      v22 = (char *)&strPrefix.m_charbuffer[-1].m_data[6];
      if ( !InterlockedDecrement((volatile LONG *)&strPrefix.m_charbuffer[-1].m_data[8]) && v22 )
      {
        v23 = *(_DWORD *)v22;
        v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
        (*(void (__thiscall **)(char *, signed int))v23)(v22, 1);
      }
      v21 = (char *)&strFinalString.m_charbuffer[-1].m_data[6];
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)((char *)strFinalString.m_charbuffer - 16);
    }
    if ( !InterlockedDecrement((volatile LONG *)v25.m_charbuffer) && v21 )
    {
      v24 = *(_DWORD *)v21;
      v25.m_charbuffer = (PSRefBufferCharData<unsigned short> *)1;
      (*(void (__thiscall **)(char *, signed int))v24)(v21, 1);
    }
  }
}
// 794488: using guessed type int (__thiscall *List<PStringBase<unsigned short>>::vftable)(void *, char);

//----- (00708520) --------------------------------------------------------  // acclient.c:795572
void sub_708520()
{
  flt_8702D4 = 1000.0 + 1.0;
}

//----- (00708540) --------------------------------------------------------  // acclient.c:795578
void sub_708540()
{
  flt_8702D8 = 24.0 * 8.0;
}

//----- (00708560) --------------------------------------------------------  // acclient.c:795584
void sub_708560()
{
  flt_8702DC = 24.0 * 0.5;
}

//----- (00708580) --------------------------------------------------------  // acclient.c:795590
int sub_708580()
{
  return atexit(nullsub_1325);
}

//----- (00708590) --------------------------------------------------------  // acclient.c:795596
int sub_708590()
{
  return atexit(nullsub_1326);
}

//----- (007085A0) --------------------------------------------------------  // acclient.c:795602
int sub_7085A0()
{
  return atexit(nullsub_1327);
}

//----- (007085B0) --------------------------------------------------------  // acclient.c:795608
void sub_7085B0()
{
  flt_8702E0 = 0.00019999999 * 3.0 + 0.1;
}

//----- (007085D0) --------------------------------------------------------  // acclient.c:795614
void _E108_87()
{
  dbl_8702E8 = 1.0 / 30.0;
}

//----- (007085F0) --------------------------------------------------------  // acclient.c:795620
void _E110_70()
{
  dbl_8702F0 = 1.0 / 5.0;
}

//----- (00708610) --------------------------------------------------------  // acclient.c:795626
void sub_708610()
{
  PixelFormatDesc::PixelFormatDesc(&stru_8702F8, PFID_A8R8G8B8);
}

//----- (00708620) --------------------------------------------------------  // acclient.c:795632
void _E115_71()
{
  dword_870330 = 1024;
}

//----- (00708630) --------------------------------------------------------  // acclient.c:795638
void _E117_67()
{
  dword_870334 = 0x7FFF;
}

//----- (00708640) --------------------------------------------------------  // acclient.c:795644
int _E119_21()
{
  const int result; // eax@1

  result = dword_870330;
  dword_870338 = dword_870330;
  return result;
}

//----- (00708650) --------------------------------------------------------  // acclient.c:795654
int _E121_62()
{
  return atexit(_E122_89);
}

//----- (00708660) --------------------------------------------------------  // acclient.c:795660
int sub_708660()
{
  return atexit(nullsub_1324);
}

