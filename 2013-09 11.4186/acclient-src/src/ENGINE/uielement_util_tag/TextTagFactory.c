/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : TextTagFactory
   Object     : ENGINE\uielement_util_tag\TextTagFactory.obj
   Functions  : 1
   Addresses  : 00478480 - 00478480 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00478480) --------------------------------------------------------  // acclient.c:181555
ReferenceCountTemplate<1048576,0> *__cdecl TextTagFactory::MakeTag(PStringBase<unsigned short> *_txt)
{
  PSRefBufferCharData<unsigned short> *v1; // ecx@1
  unsigned int v2; // eax@1
  PSRefBufferCharData<unsigned short> *v3; // edx@2
  unsigned __int16 v4; // si@4
  int v5; // edx@4
  bool v6; // cf@4
  int v7; // eax@4
  PSRefBufferCharData<unsigned short> *v8; // ecx@9
  unsigned int v9; // esi@11
  unsigned int v10; // eax@12
  TextTag_IID *v11; // eax@18
  int v12; // eax@19
  TextTag_IIDEnum *v13; // eax@20
  TextTag_IIDString *v14; // eax@22
  TextTag_DID *v15; // eax@24
  ReferenceCountTemplate<1048576,0> *v16; // esi@26
  unsigned int v17; // edi@27
  unsigned int v18; // eax@28
  int v19; // eax@30
  unsigned int *v20; // ecx@32
  ReferenceCountTemplate<1048576,0>Vtbl *v21; // edi@33
  PStringBase<unsigned short> v23; // [sp-8h] [bp-34h]@10
  unsigned int *v24; // [sp-4h] [bp-30h]@10
  PStringBase<unsigned short> formatStr; // [sp+Ch] [bp-20h]@15
  PStringBase<unsigned short> data; // [sp+10h] [bp-1Ch]@32
  unsigned int formatEnum; // [sp+14h] [bp-18h]@16
  unsigned int typeEnum; // [sp+18h] [bp-14h]@10
  PStringBaseIter_Const<unsigned short> iter; // [sp+1Ch] [bp-10h]@8

  v1 = _txt->m_charbuffer;
  v2 = *(_DWORD *)&_txt->m_charbuffer[-1].m_data[14];
  if ( v2 - 1 < 2 )
    return 0;
  v3 = (PSRefBufferCharData<unsigned short> *)((char *)v1 + 2 * v2 - 2);
  if ( v2 )
    v3 = _txt->m_charbuffer;
  v4 = v3->m_data[0];
  v5 = v2 - 2;
  v6 = v2 - 2 < v2;
  v7 = (int)((char *)v1 + 2 * v2 - 2);
  if ( v6 )
    v7 = (int)((char *)v1 + 2 * v5);
  if ( v4 != 60 )
    return 0;
  if ( *(_WORD *)v7 != 62 )
    return 0;
  iter.vfptr = (PStringBaseIter_Common<unsigned short>Vtbl *)&PStringBaseIter_Const<unsigned short>::vftable;
  iter.pstring_ptr = _txt;
  iter.mark = 0;
  iter.curr = 0;
  PStringBaseIter_Common<unsigned short>::Next((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, 1);
  iter.mark = iter.curr;
  if ( !PStringBaseIter_Common<unsigned short>::FindChar(
          (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
          0x3Au,
          0) )
    return 0;
  PStringBaseIter_Common<unsigned short>::GetSubString(
    (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
    (PStringBase<unsigned short> *)&_txt);
  if ( _txt[-1].m_charbuffer == (PSRefBufferCharData<unsigned short> *)1
    || (v24 = &typeEnum,
        v23.m_charbuffer = v8,
        typeEnum = 0,
        PStringBase<unsigned short>::PStringBase<unsigned short>(
          (CaseInsensitiveStringBase<PStringBase<char> > *)&v23,
          (PStringBase<char> *)&_txt),
        !EnumMapper::InqEnum(0x18u, v23, v24))
    || ((v9 = iter.curr + 1, v9 <= iter.vfptr->GetStrLen(&iter)) ? (v10 = v9) : (v10 = iter.vfptr->GetStrLen(&iter)),
        iter.curr = v10,
        iter.mark = v10,
        !PStringBaseIter_Common<unsigned short>::FindChar(
           (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
           0x3Au,
           0)) )
  {
LABEL_37:
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
    return 0;
  }
  PStringBaseIter_Common<unsigned short>::GetSubString(
    (PStringBaseIter_Common<unsigned short> *)&iter.vfptr,
    &formatStr);
  if ( *(_DWORD *)&formatStr.m_charbuffer[-1].m_data[14] == 1 )
    goto LABEL_36;
  v24 = &formatEnum;
  v23.m_charbuffer = formatStr.m_charbuffer;
  formatEnum = 0;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (CaseInsensitiveStringBase<PStringBase<char> > *)&v23,
    (PStringBase<char> *)&formatStr);
  if ( !EnumMapper::InqEnum(0x18u, v23, v24) )
    goto LABEL_36;
  switch ( formatEnum )
  {
    case 2u:
      v11 = (TextTag_IID *)operator new(0x14u);
      if ( !v11 )
        goto LABEL_36;
      TextTag_IID::TextTag_IID(v11);
      break;
    case 3u:
      v13 = (TextTag_IIDEnum *)operator new(0x18u);
      if ( !v13 )
        goto LABEL_36;
      TextTag_IIDEnum::TextTag_IIDEnum(v13);
      break;
    case 4u:
      v14 = (TextTag_IIDString *)operator new(0x18u);
      if ( !v14 )
        goto LABEL_36;
      TextTag_IIDString::TextTag_IIDString(v14);
      break;
    case 1u:
      v15 = (TextTag_DID *)operator new(0x14u);
      if ( !v15 )
        goto LABEL_36;
      TextTag_DID::TextTag_DID(v15);
      break;
    default:
      goto LABEL_36;
  }
  v16 = (ReferenceCountTemplate<1048576,0> *)v12;
  if ( !v12 )
  {
LABEL_36:
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&formatStr);
    goto LABEL_37;
  }
  *(_DWORD *)(v12 + 8) = typeEnum;
  *(_DWORD *)(v12 + 12) = formatEnum;
  v17 = iter.curr + 1;
  if ( v17 <= iter.vfptr->GetStrLen(&iter) )
    v18 = v17;
  else
    v18 = iter.vfptr->GetStrLen(&iter);
  iter.curr = v18;
  iter.mark = v18;
  v19 = iter.vfptr->GetStrLen(&iter);
  if ( (unsigned int)v19 < 1 )
  {
    iter.curr = 0;
    goto LABEL_36;
  }
  iter.curr = v19 - 1;
  PStringBaseIter_Common<unsigned short>::GetSubString((PStringBaseIter_Common<unsigned short> *)&iter.vfptr, &data);
  if ( *(_DWORD *)&data.m_charbuffer[-1].m_data[14] == 1 )
  {
LABEL_35:
    PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&data);
    goto LABEL_36;
  }
  v21 = v16->vfptr;
  v24 = v20;
  PStringBase<unsigned short>::PStringBase<unsigned short>(
    (CaseInsensitiveStringBase<PStringBase<char> > *)&v24,
    (PStringBase<char> *)&data);
  if ( !(unsigned __int8)v21[2].__vecDelDtor(v16, (unsigned int)v24) )
  {
    ReferenceCountTemplate<1048576,0>::Release(v16);
    goto LABEL_35;
  }
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&data);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&formatStr);
  PStringBase<char>::~PStringBase<char>((CaseInsensitiveStringBase<PStringBase<char> > *)&_txt);
  return v16;
}
// 79449C: using guessed type int (*PStringBaseIter_Const<unsigned short>::vftable)();

