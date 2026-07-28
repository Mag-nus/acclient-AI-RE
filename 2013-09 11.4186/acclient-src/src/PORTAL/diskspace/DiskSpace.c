/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

/* Module     : DiskSpace
   Object     : PORTAL\diskspace\DiskSpace.obj
   Functions  : 2
   Addresses  : 00509670 - 005D58B0 */

#include "../../../include/acclient_prologue.h"
#include "../../../include/acclient_types.h"
#include "../../../include/acclient_protos.h"
#include "../../../include/acclient_data.h"

//----- (00509670) --------------------------------------------------------  // acclient.c:311136
void DeleteLeafTransactInfo::DynamicCast_DeleteLeaf()
{
  ;
}

//----- (005D58B0) --------------------------------------------------------  // acclient.c:514228
DWORD __stdcall DiskSpace::GetDriveFreeBytes(char *path, unsigned __int64 *freeBytes)
{
  HMODULE v3; // eax@1
  BOOL v4; // eax@2
  DWORD result; // eax@3
  unsigned int v6; // edx@7
  int v7; // [sp+0h] [bp-24h]@2
  int v8; // [sp+4h] [bp-20h]@2
  _ULARGE_INTEGER bytesAvailableToCaller; // [sp+Ch] [bp-18h]@2
  _ULARGE_INTEGER totalBytesOnDisk; // [sp+14h] [bp-10h]@2
  _ULARGE_INTEGER totalFreeBytesOnDisk; // [sp+1Ch] [bp-8h]@2
  void *retaddr; // [sp+24h] [bp+0h]@2

  v3 = GetModuleHandleA("kernel32.dll");
  if ( GetProcAddress(v3, "GetDiskFreeSpaceExA") )
  {
    if ( GetDiskFreeSpaceExA(
           (LPCSTR)totalFreeBytesOnDisk.HighPart,
           (PULARGE_INTEGER)&v8,
           &bytesAvailableToCaller,
           &totalBytesOnDisk) )
    {
      v6 = totalBytesOnDisk.HighPart;
      *(_DWORD *)retaddr = totalBytesOnDisk.LowPart;
      *((_DWORD *)retaddr + 1) = v6;
      result = 0;
    }
    else
    {
      *(_DWORD *)retaddr = 0;
      *((_DWORD *)retaddr + 1) = 0;
      result = GetLastError();
    }
  }
  else
  {
    bytesAvailableToCaller.LowPart = 0;
    v8 = 0;
    v7 = 0;
    totalBytesOnDisk.LowPart = 0;
    v4 = GetDiskFreeSpaceA(
           (LPCSTR)totalFreeBytesOnDisk.HighPart,
           &bytesAvailableToCaller.LowPart,
           (LPDWORD)&v8,
           (LPDWORD)&v7,
           &totalBytesOnDisk.LowPart);
    *((_DWORD *)retaddr + 1) = 0;
    if ( v4 )
    {
      *(_DWORD *)retaddr = bytesAvailableToCaller.LowPart * v8 * v7;
      result = 0;
    }
    else
    {
      *(_DWORD *)retaddr = 0;
      result = GetLastError();
    }
  }
  return result;
}

