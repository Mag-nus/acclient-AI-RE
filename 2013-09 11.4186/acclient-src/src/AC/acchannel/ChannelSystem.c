/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : ChannelSystem
   Object     : AC\acchannel\ChannelSystem.obj
   Functions  : 24
   Addresses  : 005CF1F0 - 00778DF0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (005CF1F0) --------------------------------------------------------  // acclient.c:507158
int __cdecl ChannelSystem::GetChannelID(AC1Legacy::PStringBase<char> *name)
{
  AC1Legacy::PSRefBuffer<char> *v1; // ecx@0
  AC1Legacy::PStringBase<char> *v2; // esi@1
  int result; // eax@2
  AC1Legacy::PSRefBuffer<char> *v4; // ebp@4
  bool v5; // bl@4
  AC1Legacy::PSRefBuffer<char> *v6; // ebp@8
  bool v7; // bl@8
  AC1Legacy::PStringBase<char> *v8; // ebp@13
  AC1Legacy::PStringBase<char> *v9; // ebp@19
  bool v10; // bl@19
  int v11; // ebx@23
  int v12; // ebx@24
  char v13; // bl@25
  AC1Legacy::PSRefBuffer<char> *v14; // ebp@27
  AC1Legacy::PStringBase<char> *v15; // ebp@32
  int v16; // ebx@33
  bool v17; // bl@34
  int v18; // ebx@42
  bool v19; // bl@43
  int v20; // ebx@48
  int v21; // ebx@49
  bool v22; // bl@50
  int v23; // ebx@55
  int v24; // ebx@56
  int v25; // ebx@57
  int v26; // ebx@58
  int v27; // ebx@59
  int v28; // ebx@60
  bool v29; // bl@61
  int v30; // ebx@66
  int v31; // ebx@67
  int v32; // ebx@68
  bool v33; // bl@69
  int v34; // ebx@74
  bool v35; // bl@75
  int v36; // ebx@80
  bool v37; // bl@81
  int v38; // ebx@85
  int v39; // ebx@88
  bool v40; // bl@89
  int v41; // ebx@94
  bool v42; // bl@95
  int v43; // ebx@99
  int v44; // ebx@102
  bool v45; // bl@103
  int v46; // ebx@108
  bool v47; // bl@109
  int v48; // ebx@114
  bool v49; // bl@115
  int v50; // ebx@120
  bool v51; // bl@121
  int v52; // esi@126
  bool v53; // bl@127
  AC1Legacy::PStringBase<char> v54; // [sp+14h] [bp-4h]@1

  v54.m_buffer = v1;
  v2 = name;
  if ( name->m_buffer->m_len == 1 )
  {
    result = 0;
  }
  else
  {
    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "allegiance");
    if ( !__stricmp(v2->m_buffer->m_data, (const char *)&name[5]) )
      goto LABEL_132;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "a");
    v4 = v54.m_buffer;
    v5 = __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v4->m_cRef) && v4 )
      v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
    if ( v5 )
      goto LABEL_132;
    AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "ab");
    v6 = v54.m_buffer;
    v7 = __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) == 0;
    if ( !InterlockedDecrement((volatile LONG *)&v6->m_cRef) && v6 )
      v6->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v6, 1u);
    if ( v7 )
LABEL_132:
      v7 = 1;
    v8 = name;
    if ( !InterlockedDecrement((volatile LONG *)&name[1]) && v8 )
      ((void (__thiscall *)(_DWORD, _DWORD))v8->m_buffer->vfptr)(v8, 1);
    if ( v7 )
    {
      result = 0x2000000;
    }
    else
    {
      AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "co-vassals");
      if ( !__stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
        goto LABEL_133;
      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "covassals");
      v9 = name;
      v10 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]) == 0;
      if ( !InterlockedDecrement((volatile LONG *)&v9[1]) && v9 )
        ((void (__thiscall *)(_DWORD, _DWORD))v9->m_buffer->vfptr)(v9, 1);
      if ( v10
        || (AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "covassal"),
            v11 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]),
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name),
            !v11)
        || (AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "c"),
            v12 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]),
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name),
            !v12) )
LABEL_133:
        v13 = 1;
      else
        v13 = 0;
      v14 = v54.m_buffer;
      if ( !InterlockedDecrement((volatile LONG *)&v54.m_buffer->m_cRef) && v14 )
        v14->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v14, 1u);
      if ( v13 )
      {
        result = 0x1000000;
      }
      else
      {
        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "monarch");
        v15 = name;
        v17 = 1;
        if ( __stricmp(v2->m_buffer->m_data, (const char *)&name[5]) )
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "m");
          v16 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
          if ( v16 )
            v17 = 0;
        }
        if ( !InterlockedDecrement((volatile LONG *)&v15[1]) && v15 )
          ((void (__thiscall *)(_DWORD, _DWORD))v15->m_buffer->vfptr)(v15, 1);
        if ( v17 )
        {
          result = 0x4000;
        }
        else
        {
          AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "patron");
          v19 = 1;
          if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "p");
            v18 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
            if ( v18 )
              v19 = 0;
          }
          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
          if ( v19 )
          {
            result = 0x2000;
          }
          else
          {
            AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "vassals");
            v22 = 1;
            if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
            {
              AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "vassal");
              v20 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
              CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
              if ( v20 )
              {
                AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "v");
                v21 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                if ( v21 )
                  v22 = 0;
              }
            }
            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
            if ( v22 )
            {
              result = 4096;
            }
            else
            {
              AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "fellowship");
              v29 = 1;
              if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
              {
                AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "fellows");
                v23 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                if ( v23 )
                {
                  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "fellow");
                  v24 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                  if ( v24 )
                  {
                    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "f");
                    v25 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                    if ( v25 )
                    {
                      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "group");
                      v26 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                      if ( v26 )
                      {
                        AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "g");
                        v27 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                        if ( v27 )
                        {
                          AC1Legacy::PStringBase<char>::PStringBase<char>(
                            (AC1Legacy::PStringBase<char> *)&name,
                            "party");
                          v28 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                          if ( v28 )
                            v29 = 0;
                        }
                      }
                    }
                  }
                }
              }
              CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
              if ( v29 )
              {
                result = 2048;
              }
              else
              {
                AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "av");
                v33 = 1;
                if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                {
                  AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "av1");
                  v30 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                  if ( v30 )
                  {
                    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "advocate");
                    v31 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                    if ( v31 )
                    {
                      AC1Legacy::PStringBase<char>::PStringBase<char>(
                        (AC1Legacy::PStringBase<char> *)&name,
                        "advocate1");
                      v32 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                      if ( v32 )
                        v33 = 0;
                    }
                  }
                }
                CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                if ( v33 )
                {
                  result = 8;
                }
                else
                {
                  AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "av2");
                  v35 = 1;
                  if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                  {
                    AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "advocate2");
                    v34 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                    if ( v34 )
                      v35 = 0;
                  }
                  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                  if ( v35 )
                  {
                    result = 16;
                  }
                  else
                  {
                    AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "av3");
                    v37 = 1;
                    if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                    {
                      AC1Legacy::PStringBase<char>::PStringBase<char>(
                        (AC1Legacy::PStringBase<char> *)&name,
                        "advocate3");
                      v36 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                      if ( v36 )
                        v37 = 0;
                    }
                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                    if ( v37 )
                    {
                      result = 32;
                    }
                    else
                    {
                      AC1Legacy::PStringBase<char>::PStringBase<char>((AC1Legacy::PStringBase<char> *)&name, "abuse");
                      v38 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                      if ( v38 )
                      {
                        AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "ad");
                        v40 = 1;
                        if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                        {
                          AC1Legacy::PStringBase<char>::PStringBase<char>(
                            (AC1Legacy::PStringBase<char> *)&name,
                            "admin");
                          v39 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                          if ( v39 )
                            v40 = 0;
                        }
                        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                        if ( v40 )
                        {
                          result = 2;
                        }
                        else
                        {
                          AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "au");
                          v42 = 1;
                          if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                          {
                            AC1Legacy::PStringBase<char>::PStringBase<char>(
                              (AC1Legacy::PStringBase<char> *)&name,
                              "audit");
                            v41 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                            if ( v41 )
                              v42 = 0;
                          }
                          CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                          if ( v42 )
                          {
                            result = 4;
                          }
                          else
                          {
                            AC1Legacy::PStringBase<char>::PStringBase<char>(
                              (AC1Legacy::PStringBase<char> *)&name,
                              "help");
                            v43 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                            CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                            if ( v43 )
                            {
                              AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "sent");
                              v45 = 1;
                              if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                              {
                                AC1Legacy::PStringBase<char>::PStringBase<char>(
                                  (AC1Legacy::PStringBase<char> *)&name,
                                  "sentinel");
                                v44 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                                CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                                if ( v44 )
                                  v45 = 0;
                              }
                              CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                              if ( v45 )
                              {
                                result = 512;
                              }
                              else
                              {
                                AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "celestialhand");
                                v47 = 1;
                                if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                                {
                                  AC1Legacy::PStringBase<char>::PStringBase<char>(
                                    (AC1Legacy::PStringBase<char> *)&name,
                                    "celhan");
                                  v46 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                                  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                                  if ( v46 )
                                    v47 = 0;
                                }
                                CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                                if ( v47 )
                                {
                                  result = 0x8000000;
                                }
                                else
                                {
                                  AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "eldrytchweb");
                                  v49 = 1;
                                  if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                                  {
                                    AC1Legacy::PStringBase<char>::PStringBase<char>(
                                      (AC1Legacy::PStringBase<char> *)&name,
                                      "eldweb");
                                    v48 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                                    if ( v48 )
                                      v49 = 0;
                                  }
                                  CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                                  if ( v49 )
                                  {
                                    result = 0x10000000;
                                  }
                                  else
                                  {
                                    AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "radiantblood");
                                    v51 = 1;
                                    if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                                    {
                                      AC1Legacy::PStringBase<char>::PStringBase<char>(
                                        (AC1Legacy::PStringBase<char> *)&name,
                                        "radblo");
                                      v50 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                                      if ( v50 )
                                        v51 = 0;
                                    }
                                    CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                                    if ( v51 )
                                    {
                                      result = 0x20000000;
                                    }
                                    else
                                    {
                                      AC1Legacy::PStringBase<char>::PStringBase<char>(&v54, "olthoi");
                                      v53 = 1;
                                      if ( __stricmp(v2->m_buffer->m_data, v54.m_buffer->m_data) )
                                      {
                                        AC1Legacy::PStringBase<char>::PStringBase<char>(
                                          (AC1Legacy::PStringBase<char> *)&name,
                                          "ol");
                                        v52 = __stricmp(v2->m_buffer->m_data, (const char *)&name[5]);
                                        CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&name);
                                        if ( v52 )
                                          v53 = 0;
                                      }
                                      CLogonHeader::HandshakeWireData::~HandshakeWireData((CLogonHeader::HandshakeWireData *)&v54);
                                      result = v53 != 0 ? 0x40000000 : 0;
                                    }
                                  }
                                }
                              }
                            }
                            else
                            {
                              result = 1024;
                            }
                          }
                        }
                      }
                      else
                      {
                        result = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (005CFC70) --------------------------------------------------------  // acclient.c:507625
int __cdecl ChannelSystem::GetGlobalChannelName(ChatTypeEnum chatType, AC1Legacy::PStringBase<unsigned short> *globalName)
{
  int result; // eax@2

  switch ( chatType )
  {
    case 1:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::Allegiance_GlobalChannelName);
      result = 1;
      break;
    case 2:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::General_GlobalChannelName);
      result = 1;
      break;
    case 3:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::Trade_GlobalChannelName);
      result = 1;
      break;
    case 4:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::LFG_GlobalChannelName);
      result = 1;
      break;
    case 5:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::Roleplay_GlobalChannelName);
      result = 1;
      break;
    case 6:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::Society_GlobalChannelName);
      result = 1;
      break;
    case 7:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::SocietyCelHan_GlobalChannelName);
      result = 1;
      break;
    case 8:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::SocietyEldWeb_GlobalChannelName);
      result = 1;
      break;
    case 9:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::SocietyRadBlo_GlobalChannelName);
      result = 1;
      break;
    case 10:
      AC1Legacy::PStringBase<unsigned short>::operator=(globalName, &ChannelSystem::Olthoi_GlobalChannelName);
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (005CFD80) --------------------------------------------------------  // acclient.c:507679
int __cdecl ChannelSystem::GetChannelName(const unsigned int id, AC1Legacy::PStringBase<char> *name)
{
  int result; // eax@6

  if ( id > 0x1000 )
  {
    if ( id > 0x4000000 )
    {
      if ( id > 0x20000000 )
      {
        if ( id == 0x40000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Olthoi");
          return 1;
        }
      }
      else
      {
        if ( id == 0x20000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Radiant Blood");
          return 1;
        }
        if ( id == 0x8000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Celestial Hand");
          return 1;
        }
        if ( id == 0x10000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Eldrytch Web");
          return 1;
        }
      }
    }
    else
    {
      if ( id == 0x4000000 )
      {
        AC1Legacy::PStringBase<char>::set(name, "FellowBroadcast");
        return 1;
      }
      if ( id > 0x1000000 )
      {
        if ( id == 0x2000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Allegiance");
          return 1;
        }
      }
      else
      {
        if ( id == 0x1000000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Co-vassals");
          return 1;
        }
        if ( id == 0x2000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Patron");
          return 1;
        }
        if ( id == 0x4000 )
        {
          AC1Legacy::PStringBase<char>::set(name, "Monarch");
          return 1;
        }
      }
    }
    return 0;
  }
  if ( id == 4096 )
  {
    AC1Legacy::PStringBase<char>::set(name, "Vassals");
    return 1;
  }
  if ( id > 0x10 )
  {
    if ( id > 0x400 )
    {
      if ( id == 2048 )
      {
        AC1Legacy::PStringBase<char>::set(name, "Fellowship");
        return 1;
      }
    }
    else
    {
      if ( id == 1024 )
      {
        AC1Legacy::PStringBase<char>::set(name, "Help");
        return 1;
      }
      if ( id == 32 )
      {
        AC1Legacy::PStringBase<char>::set(name, "Advocate 3");
        return 1;
      }
      if ( id == 512 )
      {
        AC1Legacy::PStringBase<char>::set(name, "Sentinel");
        return 1;
      }
    }
    return 0;
  }
  if ( id == 16 )
  {
    AC1Legacy::PStringBase<char>::set(name, "Advocate 2");
    result = 1;
  }
  else
  {
    switch ( id )
    {
      case 1u:
        AC1Legacy::PStringBase<char>::set(name, "Abuse");
        result = 1;
        break;
      case 4u:
        AC1Legacy::PStringBase<char>::set(name, "Audit");
        result = 1;
        break;
      case 2u:
        AC1Legacy::PStringBase<char>::set(name, "Admin");
        result = 1;
        break;
      case 8u:
        AC1Legacy::PStringBase<char>::set(name, "Advocate 1");
        result = 1;
        break;
      default:
        return 0;
    }
  }
  return result;
}

//----- (005CFFD0) --------------------------------------------------------  // acclient.c:507818
int __cdecl ChannelSystem::GetGlobalChannelName(ChatTypeEnum chatType, AC1Legacy::PStringBase<char> *globalName)
{
  AC1Legacy::PSRefBuffer<char> *v2; // esi@1
  AC1Legacy::PSRefBuffer<char> *v3; // edi@1
  AC1Legacy::PSRefBuffer<unsigned short> *v4; // esi@9
  AC1Legacy::PStringBase<unsigned short> wideName; // [sp+10h] [bp-Ch]@1
  int retval; // [sp+14h] [bp-8h]@1
  AC1Legacy::PStringBase<char> result; // [sp+18h] [bp-4h]@1

  wideName.m_buffer = (AC1Legacy::PSRefBuffer<unsigned short> *)AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;
  InterlockedIncrement((volatile LONG *)(AC1Legacy::PStringBase<unsigned short>::s_NullBuffer + 4));
  retval = ChannelSystem::GetGlobalChannelName(chatType, &wideName);
  AC1Legacy::PStringBase<unsigned short>::to_spstring(&wideName, &result, 0);
  v2 = globalName->m_buffer;
  v3 = result.m_buffer;
  if ( globalName->m_buffer != result.m_buffer )
  {
    if ( !InterlockedDecrement((volatile LONG *)&v2->m_cRef) && v2 )
      v2->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v2, 1u);
    globalName->m_buffer = v3;
    InterlockedIncrement((volatile LONG *)&v3->m_cRef);
  }
  if ( !InterlockedDecrement((volatile LONG *)&v3->m_cRef) && v3 )
    v3->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v3, 1u);
  v4 = wideName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&wideName.m_buffer->m_cRef) && v4 )
    v4->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v4, 1u);
  return retval;
}
// 8EE11C: using guessed type int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer;

//----- (00710100) --------------------------------------------------------  // acclient.c:803337
int sub_710100()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::Allegiance_GlobalChannelName,
    L"Allegiance");
  return atexit(_E74_94);
}

//----- (00710120) --------------------------------------------------------  // acclient.c:803346
int _E76_77()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::General_GlobalChannelName,
    L"General");
  return atexit(sub_778C70);
}

//----- (00710140) --------------------------------------------------------  // acclient.c:803355
int _E79_72()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&ChannelSystem::Trade_GlobalChannelName, L"Trade");
  return atexit(_E80_70);
}

//----- (00710160) --------------------------------------------------------  // acclient.c:803362
int _E82_48()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(&ChannelSystem::LFG_GlobalChannelName, L"LFG");
  return atexit(_E83_46);
}

//----- (00710180) --------------------------------------------------------  // acclient.c:803369
int _E85_34()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::Roleplay_GlobalChannelName,
    L"Roleplay");
  return atexit(_E86_27);
}

//----- (007101A0) --------------------------------------------------------  // acclient.c:803378
int _E88_24()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::Society_GlobalChannelName,
    L"Society");
  return atexit(_E89_37);
}

//----- (007101C0) --------------------------------------------------------  // acclient.c:803387
int sub_7101C0()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::SocietyCelHan_GlobalChannelName,
    L"Celestial Hand");
  return atexit(_E92_42);
}

//----- (007101E0) --------------------------------------------------------  // acclient.c:803396
int _E94_33()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::SocietyEldWeb_GlobalChannelName,
    L"Eldrytch Web");
  return atexit(sub_778D90);
}

//----- (00710200) --------------------------------------------------------  // acclient.c:803405
int sub_710200()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::SocietyRadBlo_GlobalChannelName,
    L"Radiant Blood");
  return atexit(sub_778DC0);
}

//----- (00710220) --------------------------------------------------------  // acclient.c:803414
int sub_710220()
{
  AC1Legacy::PStringBase<unsigned short>::PStringBase<unsigned short>(
    &ChannelSystem::Olthoi_GlobalChannelName,
    L"Olthoi");
  return atexit(sub_778DF0);
}

//----- (00778C40) --------------------------------------------------------  // acclient.c:911359
void __cdecl _E74_94()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::Allegiance_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::Allegiance_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778C70) --------------------------------------------------------  // acclient.c:911372
void __cdecl sub_778C70()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::General_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::General_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778CA0) --------------------------------------------------------  // acclient.c:911385
void __cdecl _E80_70()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::Trade_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::Trade_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778CD0) --------------------------------------------------------  // acclient.c:911398
void __cdecl _E83_46()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::LFG_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::LFG_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778D00) --------------------------------------------------------  // acclient.c:911411
void __cdecl _E86_27()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::Roleplay_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::Roleplay_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778D30) --------------------------------------------------------  // acclient.c:911424
void __cdecl _E89_37()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::Society_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::Society_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778D60) --------------------------------------------------------  // acclient.c:911437
void __cdecl _E92_42()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::SocietyCelHan_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::SocietyCelHan_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778D90) --------------------------------------------------------  // acclient.c:911450
void __cdecl sub_778D90()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::SocietyEldWeb_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::SocietyEldWeb_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778DC0) --------------------------------------------------------  // acclient.c:911463
void __cdecl sub_778DC0()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::SocietyRadBlo_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::SocietyRadBlo_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

//----- (00778DF0) --------------------------------------------------------  // acclient.c:911476
void __cdecl sub_778DF0()
{
  AC1Legacy::PSRefBuffer<unsigned short> *v0; // esi@1

  v0 = ChannelSystem::Olthoi_GlobalChannelName.m_buffer;
  if ( !InterlockedDecrement((volatile LONG *)&ChannelSystem::Olthoi_GlobalChannelName.m_buffer->m_cRef) )
  {
    if ( v0 )
      v0->vfptr->__vecDelDtor((ReferenceCountTemplate<268435456,0> *)v0, 1u);
  }
}

