/* Extracted from acclient.c -- Hex-Rays decompilation of acclient.exe 11.4186
   (Asheron's Call, September 2013).  Split by original .obj module using the
   symbol and module records in the shipped acclient.pdb.
   GENERATED FILE -- regenerate with tools/split_acclient.py rather than editing.
   Every function keeps its original acclient.c line number, so existing
   acclient.c:NNNNN citations still resolve. */

// Data declarations

_UNKNOWN loc_4C4B3E; // weak
_UNKNOWN loc_4DD1E0; // weak
_UNKNOWN loc_4DD1E3; // weak
_UNKNOWN loc_4DD1E5; // weak
_UNKNOWN loc_4DD1E7; // weak
_UNKNOWN loc_4DD1E9; // weak
_UNKNOWN loc_4DD1EC; // weak
_UNKNOWN loc_4DD1EE; // weak
_UNKNOWN loc_4DD1F0; // weak
_UNKNOWN loc_4DD1F3; // weak
_UNKNOWN loc_4DD1F5; // weak
_UNKNOWN loc_4DD1F7; // weak
_UNKNOWN loc_4DD1F9; // weak
_UNKNOWN loc_4DD1FD; // weak
_UNKNOWN loc_4DD1FF; // weak
_UNKNOWN loc_4DD200; // weak
_UNKNOWN loc_4DD203; // weak
_UNKNOWN loc_4DD205; // weak
_UNKNOWN loc_4DD207; // weak
_UNKNOWN loc_4DD20C; // weak
_UNKNOWN loc_4DD20F; // weak
_UNKNOWN loc_4DD211; // weak
_UNKNOWN loc_4DD213; // weak
_UNKNOWN loc_4DD216; // weak
_UNKNOWN loc_4DD218; // weak
_UNKNOWN loc_4DD21A; // weak
_UNKNOWN loc_4DD21C; // weak
_UNKNOWN loc_4DD21D; // weak
_UNKNOWN loc_4DD21E; // weak
char byte_4DD224 = 'ê'; // weak
char byte_4DD225 = 'ê'; // weak
char byte_4DD226 = 'ê'; // weak
char byte_4DD227 = 'ê'; // weak
char byte_4DD228 = 'ê'; // weak
char byte_4DD229[3] = { 'ê', 'ê', 'ê' }; // weak
char byte_4DD22C = 'ê'; // weak
char byte_4DD22D = 'ê'; // weak
char byte_4DD22E = 'ê'; // weak
char byte_4DD22F = 'ê'; // weak
_UNKNOWN loc_4DD231; // weak
_UNKNOWN loc_4DD232; // weak
_UNKNOWN loc_4DD236; // weak
_UNKNOWN loc_4DD239; // weak
_UNKNOWN loc_4DD23A; // weak
_UNKNOWN loc_4DD23C; // weak
_UNKNOWN loc_4DD242; // weak
_UNKNOWN loc_4DD245; // weak
_UNKNOWN loc_4DD24B; // weak
_UNKNOWN loc_4DD250; // weak
_UNKNOWN loc_4DD255; // weak
_UNKNOWN loc_4DD258; // weak
_UNKNOWN loc_4DD25A; // weak
_UNKNOWN loc_4DD260; // weak
_UNKNOWN loc_4DD264; // weak
_UNKNOWN loc_4DD26A; // weak
_UNKNOWN loc_4DD26D; // weak
_UNKNOWN loc_4DD273; // weak
_UNKNOWN loc_4DD275; // weak
_UNKNOWN loc_4DD277; // weak
_UNKNOWN loc_4DD279; // weak
_UNKNOWN loc_4DD27F; // weak
_UNKNOWN loc_600040; // weak
_UNKNOWN loc_6209DA; // weak
_UNKNOWN loc_646E5F; // weak
_UNKNOWN loc_650100; // weak
// extern FILE __iob[];
// extern int __adjust_fdiv; weak
// extern int __acmdln; weak
Turbine_GUID Client_ClassType = { 2211288139u, 48160u, 19688u, "¶'£\b\x06?\x05" }; // idb
Turbine_GUID Interface_InterfaceType_0 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *PackObj::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
char name = '\0'; // idb
Turbine_GUID IObjectFactory_InterfaceType_0 = { 1244181156u, 45353u, 18515u, "ó∏\x13€Güv," }; // idb
Turbine_GUID Client_ClassType_0 = { 2211288139u, 48160u, 19688u, "¶'£\b\x06?\x05" }; // idb
Turbine_GUID Interface_InterfaceType_1 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
void (__thiscall *Archive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer) = &Archive::InitForPacking; // weak
void (__thiscall *TransientArchive::vftable)(Archive *this, ArchiveInitializer *i_rInitializer, SmartBuffer *i_buffer) = &Archive::InitForPacking; // weak
int (__thiscall *ReferenceCountTemplate<1048576,2>::vftable)(void *, char) = &Turbine_RefCount::scalar_deleting_destructor; // weak
bool (__thiscall *gmClient::vftable)(DBObj *this) = &DBObj::InitLoad; // weak
int (*gmClient::vftable)() = &gmClient::vector_deleting_destructor; // weak
int (*gmClient::vftable)() = &gmClient::vector_deleting_destructor; // weak
int (__stdcall *gmClient::vftable)(char) = &gmClient::scalar_deleting_destructor; // weak
void (__thiscall *gmClient::vftable)(ArgumentParser *__hidden this) = &ArgumentParser::Usage; // weak
__int32 (__stdcall *gmClient::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *ClassFactoryForceClient_ClassType::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *List<PStringBase<char>>::vftable)(void *, char) = &List<PStringBase<char>>::vector_deleting_destructor; // weak
char c_szPath[24] = "\\Microsoft Shared\\MSLU\\"; // weak
bool (__thiscall *Turbine::Debug::vftable)(Turbine::Debug *__hidden this) = &Turbine::Debug::InitDebug; // weak
Turbine_GUID IObjectFactory_InterfaceType_1 = { 1244181156u, 45353u, 18515u, "ó∏\x13€Güv," }; // idb
int (__thiscall *IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<Turbine_GUID,HashTableData<Turbine_GUID,Interface *> *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<Turbine_GUID,Interface *>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<Turbine_GUID,Interface *,1>::vftable)(void *, char) = &AutoGrowHashTable<Turbine_GUID,Interface *>::vector_deleting_destructor; // weak
PStringSimple<char> s_SPString_Null = { &unk_81735C }; // idb
PStringSimple<char> s_SPString_Whitespace = { &unk_817374 }; // idb
PStringSimple<unsigned short> s_WPString_Null = { &unk_817390 }; // idb
PStringSimple<unsigned short> s_WPString_Whitespace = { &asc_8173A8 }; // idb
int (__thiscall *TimerInstance<TimeSource_QueryPerformanceCounter>::vftable[2])(void *, char) =
{
  &PreciseTimerInstance::vector_deleting_destructor,
  &GrowBuffer::scalar_deleting_destructor
}; // weak
int (__thiscall *GrowBuffer::vftable)(void *, char) = &GrowBuffer::scalar_deleting_destructor; // weak
unsigned __int16 word_794320 = 0u; // idb
int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,HashTableData<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::vftable)(void *, char) = &IntrusiveHashTable<unsigned short,HashTableData<unsigned short,long> *,1>::scalar_deleting_destructor; // weak
int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::vftable[2])(void *, char) =
{
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<unsigned short>>,long>::scalar_deleting_destructor,
  &HashTable<unsigned short,long,1>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned short,long,1>::vftable)(void *, char) = &HashTable<unsigned short,long,1>::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vftable)(void *, char) = &IntrusiveHashTable<IDClass<_tagVersionHandle,32,0>,InArchiveVersionStack::VersionRowHolder *,1>::vector_deleting_destructor; // weak
unsigned __int32 (__thiscall *ArchiveVersionRow::vftable)(ArchiveVersionRow *this, unsigned __int32) = &ArchiveVersionRow::GetVersionByToken; // weak
__int32 (__stdcall *InArchiveVersionStack::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *PStringBaseIter_Common<unsigned short>::vftable = &_purecall; // weak
int (__thiscall *List<PStringBase<unsigned short>>::vftable)(void *, char) = &List<PStringBase<unsigned short>>::vector_deleting_destructor; // weak
int (__thiscall *PStringBaseIter_Const<char>::vftable)(_DWORD) = &PStringBaseIter<char>::GetStrLen; // weak
int (*PStringBaseIter_Const<unsigned short>::vftable)() = &PStringBaseIter<char>::GetStrLen; // weak
int (__thiscall *CPluginPrototype::vftable)(void *, char) = &CPluginPrototype::vector_deleting_destructor; // weak
int (__thiscall *CrashCleaner::vftable)(void *, char) = &CrashCleaner::scalar_deleting_destructor; // weak
int (__thiscall *DialogBoxGateway::vftable)(void *, char) = &DialogBoxGateway::vector_deleting_destructor; // weak
const unsigned int cat_DefaultHandler = 0u; // idb
int (__thiscall *ConsoleOutputHandler::vftable)(void *, char) = &PreciseTimerInstance::vector_deleting_destructor; // weak
int (__thiscall *OutputDebugStringOutputHandler::vftable)(void *, char) = &PreciseTimerInstance::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,LogController::CategoryHandler *,0>::vector_deleting_destructor,
  &TextFileOutputHandler::scalar_deleting_destructor
}; // weak
int (__thiscall *TextFileOutputHandler::vftable)(void *, char) = &TextFileOutputHandler::scalar_deleting_destructor; // weak
int (__thiscall *TimestamppedTextFileOutputHandler::vftable)(void *, char) = &TextFileOutputHandler::scalar_deleting_destructor; // weak
const unsigned __int32 g_numBucketSizes = 23u; // weak
Turbine_GUID InArchiveVersionStack_InterfaceType_0 = { 2879860738u, 46296u, 17603u, "Ω.œÏáç—*" }; // idb
Turbine_GUID Interface_InterfaceType_3 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
Turbine_GUID UIFlow_ClassType_0 = { 1575365287u, 26701u, 17415u, "¢¨\x11\x13òSUc" }; // idb
Turbine_GUID Interface_InterfaceType_4 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *IInputActionCallback::vftable)(void *, char) = &IInputActionCallback::scalar_deleting_destructor; // weak
int (__thiscall *NetError::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *CDDDStatusPlugin::vftable)(void *, char) = &CDDDStatusPlugin::vector_deleting_destructor; // weak
void (__thiscall *ArgumentParser::vftable)(ArgumentParser *__hidden this) = &ArgumentParser::Usage; // weak
int (*Client::vftable)() = &Client::vector_deleting_destructor; // weak
int (*Client::vftable)() = &Client::vector_deleting_destructor; // weak
int (__stdcall *Client::vftable)(char) = &Client::scalar_deleting_destructor; // weak
void (__thiscall *Client::vftable)(ArgumentParser *__hidden this) = &ArgumentParser::Usage; // weak
__int32 (__stdcall *Client::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *LinkStatusHolder::vftable)(void *, char) = &LinkStatusHolder::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vftable)(void *, char) = &IntrusiveHashTable<PStringBase<char>,HashSetData<PStringBase<char>> *,1>::vector_deleting_destructor; // weak
int (__thiscall *HashSet<PStringBase<char>>::vftable[2])(void *, char) =
{
  &HashSet<PStringBase<char>>::vector_deleting_destructor,
  &InteractiveOutputHandler::scalar_deleting_destructor
}; // weak
int (__thiscall *InteractiveOutputHandler::vftable)(void *, char) = &InteractiveOutputHandler::scalar_deleting_destructor; // weak
Turbine_GUID Interface_InterfaceType_6 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
bool (__thiscall *MasterDBMap::vftable)(MasterDBMap *__hidden this) = &MasterDBMap::InitDBTypeDef_Internal; // weak
int (__thiscall *TDynamicCircularArray<AsyncCache::CCallbackHandler *>::vftable)(void *, char) = &TDynamicCircularArray<AsyncCache::CCallbackHandler *>::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vftable[8])(void *, char) =
{
  &IntrusiveHashTable<QualifiedDataID,DBObjSaveInfo *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor,
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vftable[7])(void *, char) =
{
  &IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,CAsyncGetRequest *> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor,
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::vftable[6])(void *, char) =
{
  &IntrusiveHashTable<AsyncContext,HashTableData<AsyncContext,AsyncCache::CCallbackHandler *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor,
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vftable[5])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBOCache *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor,
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1>::vector_deleting_destructor,
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *QualifiedDataIDArray::vftable[3])(void *, char) =
{
  &QualifiedDataIDArray::vector_deleting_destructor,
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,DBOCache *,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,DBOCache *,0>::vector_deleting_destructor,
  &HashSet<QualifiedDataID>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashSet<QualifiedDataID>::vftable)(void *, char) = &HashSet<QualifiedDataID>::scalar_deleting_destructor; // weak
void (__thiscall *DBCachePrefetchCallback::vftable)(DBCachePrefetchCallback *this, AsyncContext hContext, AsyncResult Result, unsigned __int32) = &DBCachePrefetchCallback::OnContextFinished; // weak
struct DBObj *(__thiscall *DBCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *) = &AsyncCache::BlockingGet; // weak
__int32 (__stdcall *DBCache::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID Interface_InterfaceType_7 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *DBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<char>> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,PStringBase<char>,0>::vector_deleting_destructor,
  &HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IDClass<_tagDataID,32,0>> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,PStringBase<char>,0>::vector_deleting_destructor,
  &HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,PStringBase<char>,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,PStringBase<char>,0>::vector_deleting_destructor,
  &HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::vftable)(void *, char) = &HashTable<unsigned long,IDClass<_tagDataID,32,0>,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *EnumIDMap::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,DBObj *> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,float,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,float> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,float,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,float,0>::vftable)(void *, char) = &HashTable<unsigned long,float,0>::vector_deleting_destructor; // weak
float FLOAT_0_0 =  0.0; // weak
int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::vftable)(void *, char) = &HashTable<IDClass<_tagDataID,32,0>,DBObj *,1>::scalar_deleting_destructor; // weak
bool (__thiscall *Archive::SetVersionRow::vftable)(Archive::SetVersionRow *this, struct Archive *) = &Archive::SetVersionRow::InitializeArchive; // weak
int (__thiscall *AsyncCache::CAsyncRequest::vftable)(void *, char) = &AsyncCache::CAsyncRequest::scalar_deleting_destructor; // weak
int (__thiscall *AsyncCache::CCallbackHandler::vftable[2])(void *, char) =
{
  &AsyncCache::CCallbackHandler::vector_deleting_destructor,
  &CAsyncGetRequest::scalar_deleting_destructor
}; // weak
int (__thiscall *CAsyncGetRequest::vftable)(void *, char) = &CAsyncGetRequest::scalar_deleting_destructor; // weak
int (__thiscall *CAsyncPurgeRequest::vftable)(void *, char) = &CAsyncPurgeRequest::scalar_deleting_destructor; // weak
int (__thiscall *CAsyncSaveRequest::vftable)(void *, char) = &CAsyncSaveRequest::vector_deleting_destructor; // weak
int (__thiscall *HashTable<AsyncContext,AsyncCache::CCallbackHandler *,1>::vftable[2])(void *, char) =
{
  &AutoGrowHashTable<AsyncContext,AsyncCache::CCallbackHandler *>::scalar_deleting_destructor,
  &AutoGrowHashTable<QualifiedDataID,CAsyncGetRequest *>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<QualifiedDataID,CAsyncGetRequest *,1>::vftable)(void *, char) = &AutoGrowHashTable<QualifiedDataID,CAsyncGetRequest *>::scalar_deleting_destructor; // weak
struct DBObj *(__thiscall *AsyncCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *) = &AsyncCache::BlockingGet; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::vftable[6])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,ArchiveVersionRow,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::scalar_deleting_destructor,
  &AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor,
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,ArchiveVersionRow,0>::vftable[5])(void *, char) =
{
  &HashTable<unsigned long,ArchiveVersionRow,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::scalar_deleting_destructor,
  &AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor,
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::scalar_deleting_destructor,
  &AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor,
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long> *,1>::scalar_deleting_destructor,
  &AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor,
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>,1>::vftable[2])(void *, char) =
{
  &AutoGrowHashTable<unsigned long,CaseInsensitiveStringBase<PStringBase<char>>>::vector_deleting_destructor,
  &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor
}; // weak
int (__thiscall *AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::vftable)(void *, char) = &AutoGrowHashTable<CaseInsensitiveStringBase<PStringBase<char>>,unsigned long>::scalar_deleting_destructor; // weak
__int32 (__stdcall *EnumMapper::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DBTypeDef,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,DBTypeDef,0>::vftable)(void *, char) = &HashTable<unsigned long,DBTypeDef,0>::vector_deleting_destructor; // weak
const unsigned int DB_TYPE_LAND_BLOCK = 1u; // idb
const unsigned int DB_TYPE_LBI = 2u; // idb
const unsigned int DB_TYPE_CELL = 3u; // idb
const unsigned int DB_TYPE_LBO = 4u; // idb
const unsigned int DB_TYPE_INSTANTIATION = 5u; // idb
const unsigned int DB_TYPE_GFXOBJ = 6u; // idb
const unsigned int DB_TYPE_SETUP = 7u; // idb
const unsigned int DB_TYPE_ANIM = 8u; // idb
const unsigned int DB_TYPE_ANIMATION_HOOK = 9u; // idb
const unsigned int DB_TYPE_PALETTE = 10u; // idb
const unsigned int DB_TYPE_SURFACETEXTURE = 11u; // idb
const unsigned int DB_TYPE_RENDERSURFACE = 12u; // idb
const unsigned int DB_TYPE_SURFACE = 13u; // idb
const unsigned int DB_TYPE_MTABLE = 14u; // idb
const unsigned int DB_TYPE_WAVE = 15u; // idb
const unsigned int DB_TYPE_ENVIRONMENT = 16u; // idb
const unsigned int DB_TYPE_CHAT_POSE_TABLE = 17u; // idb
const unsigned int DB_TYPE_OBJECT_HIERARCHY = 18u; // idb
const unsigned int DB_TYPE_BADDATA = 19u; // idb
const unsigned int DB_TYPE_TABOO_TABLE = 20u; // idb
const unsigned int DB_TYPE_FILE2ID_TABLE = 21u; // idb
const unsigned int DB_TYPE_NAME_FILTER_TABLE = 22u; // idb
const unsigned int DB_TYPE_MONITOREDPROPERTIES = 23u; // idb
const unsigned int DB_TYPE_PAL_SET = 24u; // idb
const unsigned int DB_TYPE_CLOTHING = 25u; // idb
const unsigned int DB_TYPE_DEGRADEINFO = 26u; // idb
const unsigned int DB_TYPE_SCENE = 27u; // idb
const unsigned int DB_TYPE_REGION = 28u; // idb
const unsigned int DB_TYPE_KEYMAP = 29u; // idb
const unsigned int DB_TYPE_RENDERTEXTURE = 30u; // idb
const unsigned int DB_TYPE_RENDERMATERIAL = 31u; // idb
const unsigned int DB_TYPE_MATERIALMODIFIER = 32u; // idb
const unsigned int DB_TYPE_MATERIALINSTANCE = 33u; // idb
const unsigned int DB_TYPE_STABLE = 34u; // idb
const unsigned int DB_TYPE_UI_LAYOUT = 35u; // idb
const unsigned int DB_TYPE_ENUM_MAPPER = 36u; // idb
const unsigned int DB_TYPE_STRING_TABLE = 37u; // idb
const unsigned int DB_TYPE_DID_MAPPER = 38u; // idb
const unsigned int DB_TYPE_ACTIONMAP = 39u; // idb
const unsigned int DB_TYPE_DUAL_DID_MAPPER = 40u; // idb
const unsigned int DB_TYPE_STRING = 41u; // idb
const unsigned int DB_TYPE_PARTICLE_EMITTER = 42u; // idb
const unsigned int DB_TYPE_PHYSICS_SCRIPT = 43u; // idb
const unsigned int DB_TYPE_PHYSICS_SCRIPT_TABLE = 44u; // idb
const unsigned int DB_TYPE_MASTER_PROPERTY = 45u; // idb
const unsigned int DB_TYPE_FONT = 46u; // idb
const unsigned int DB_TYPE_FONT_LOCAL = 47u; // idb
const unsigned int DB_TYPE_STRING_STATE = 48u; // idb
const unsigned int DB_TYPE_DBPROPERTIES = 49u; // idb
const unsigned int DB_TYPE_RENDER_MESH = 67u; // idb
__int32 (__stdcall *CLanguageInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
unsigned int _STL::_Stl_prime<bool>::_M_list = 53u; // idb
const long double INVALID_TIME_3 = -1.0; // idb
int (__thiscall *ReferenceCountTemplate<1048576,1>::vftable[2])(void *, char) =
{
  &TriStatePropertyValue::scalar_deleting_destructor,
  &TriStatePropertyValue::scalar_deleting_destructor
}; // weak
int (__thiscall *Bitfield32PropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *Bitfield64PropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *BoolPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_Bool::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *IFileNodeName::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *ColorPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *DataFilePropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *EnumPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *FloatPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *InstanceIDPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *IntegerPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *LongIntegerPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *Position::vftable)(void *, char) = &Position::vector_deleting_destructor; // weak
int (__thiscall *PositionPropertyValue::vftable)(void *, char) = &PositionPropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *StringInfoPropertyValue::vftable)(void *, char) = &StringInfoPropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *TriStatePropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *TimeStampPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_Double::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *VectorPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *WaveformPropertyValue::vftable)(void *, char) = &TriStatePropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BasePropertyDesc *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::scalar_deleting_destructor,
  &FileNodeName_UInt32::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,BaseProperty> *,1>::scalar_deleting_destructor,
  &FileNodeName_UInt32::scalar_deleting_destructor
}; // weak
int (__thiscall *FileNodeName_Float::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_Hex::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_UInt32::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_Int32::vftable)(void *, char) = &FileNodeName_UInt32::scalar_deleting_destructor; // weak
int (__thiscall *FileNodeName_PString::vftable)(void *, char) = &FileNodeName_PString::scalar_deleting_destructor; // weak
int (__thiscall *StringPropertyValue::vftable)(void *, char) = &StringPropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *StringTokenPropertyValue::vftable)(void *, char) = &StringTokenPropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *ArrayPropertyValue::vftable)(void *, char) = &ArrayPropertyValue::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,BasePropertyDesc *,0>::vftable)(void *, char) = &HashTable<unsigned long,BasePropertyDesc *,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *MasterProperty::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *AutoGrowHashTable<unsigned long,BaseProperty>::vftable)(void *, char) = &HashTable<unsigned long,BaseProperty,1>::scalar_deleting_destructor; // weak
int (__thiscall *StructPropertyValue::vftable)(void *, char) = &StructPropertyValue::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue>> *,0>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable)(void *, char) = &HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::scalar_deleting_destructor; // weak
const float Const_DefaultPredictedExpirationTime =  1.5; // idb
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,AvailableProperty,0>::vector_deleting_destructor,
  &BasePropertyDesc::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,AvailableProperty,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,AvailableProperty,0>::vector_deleting_destructor,
  &BasePropertyDesc::vector_deleting_destructor
}; // weak
int (__thiscall *BasePropertyDesc::vftable)(void *, char) = &BasePropertyDesc::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringInfoData *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PStringBase<unsigned short>> *,0>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,StringInfoData *,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,StringInfoData *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,PStringBase<unsigned short>,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,PStringBase<unsigned short>,0>::vftable)(void *, char) = &HashTable<unsigned long,PStringBase<unsigned short>,0>::vector_deleting_destructor; // weak
int (__thiscall *StringInfoData::vftable)(void *, char) = &Double_StringInfoData::scalar_deleting_destructor; // weak
void (__thiscall *Formatted_StringInfoData::vftable)(Formatted_StringInfoData *this, struct Archive *) = &Formatted_StringInfoData::Serialize; // weak
int (__thiscall *StringInfo_StringInfoData::vftable)(void *, char) = &StringInfo_StringInfoData::vector_deleting_destructor; // weak
int (__thiscall *Double_StringInfoData::vftable)(void *, char) = &Double_StringInfoData::scalar_deleting_destructor; // weak
int (__thiscall *LInt_StringInfoData::vftable)(void *, char) = &Double_StringInfoData::scalar_deleting_destructor; // weak
int (__thiscall *ULInt_StringInfoData::vftable)(void *, char) = &Double_StringInfoData::scalar_deleting_destructor; // weak
int (__stdcall *Formatted_Double_StringInfoData::vftable)(int) = &Formatted_Double_StringInfoData::Serialize; // weak
int (__thiscall *Formatted_Double_StringInfoData::vftable)(void *, char) = &Formatted_Double_StringInfoData::vector_deleting_destructor; // weak
int (__thiscall *Formatted_LInt_StringInfoData::vftable)(void *, char) = &Formatted_LInt_StringInfoData::vector_deleting_destructor; // weak
int (__stdcall *Formatted_LInt_StringInfoData::vftable)(int) = &Formatted_LInt_StringInfoData::Serialize; // weak
int (__thiscall *Formatted_ULInt_StringInfoData::vftable)(void *, char) = &Formatted_LInt_StringInfoData::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StringTableString *> *,0>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,StringTableString *,0>::vftable)(void *, char) = &HashTable<unsigned long,StringTableString *,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *StringTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
IDClass<_tagDataID,32,0> MovementRunLock = { { 48u } }; // idb
int (__thiscall *ICIDM::vftable)(void *, char) = &ICIDM::vector_deleting_destructor; // weak
int (__thiscall *List<CInputHandler *>::vftable[2])(void *, char) =
{
  &List<CInputHandler *>::vector_deleting_destructor,
  &List<CInputManager::InputMapEntry>::vector_deleting_destructor
}; // weak
int (__thiscall *List<CInputManager::InputMapEntry>::vftable)(void *, char) = &List<CInputManager::InputMapEntry>::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,ActionState *,1>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,ActionState *,1>::scalar_deleting_destructor; // weak
int (__thiscall *CInputManager::vftable)(void *, char) = &CInputManager::scalar_deleting_destructor; // weak
Turbine_GUID GlobalRegistryCommands_ClassType_3 = { 1353238229u, 48427u, 18898u, "¶¶\fˇ\x16µ3‘" }; // idb
Turbine_GUID Interface_InterfaceType_14 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPCommand *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vftable)(void *, char) = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,GRPObject *> *,0>::vector_deleting_destructor; // weak
char aHelp[] = "Help"; // idb
__int32 (__stdcall *GlobalRegistryCommands::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *HashTable<PStringBase<char>,GRPCommand *,0>::vftable[2])(void *, char) =
{
  &HashTable<PStringBase<char>,GRPCommand *,0>::scalar_deleting_destructor,
  &HashTable<PStringBase<char>,GRPObject *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<PStringBase<char>,GRPObject *,0>::vftable)(void *, char) = &HashTable<PStringBase<char>,GRPObject *,0>::vector_deleting_destructor; // weak
int (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(char) = &RefCountInterface<GlobalRegistryCommands>::vector_deleting_destructor; // weak
__int32 (__stdcall *RefCountInterface<GlobalRegistryCommands>::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const struct DeleteLeafTransactInfo *(__thiscall *GRPGeneric::vftable[2])(DeleteLeafTransactInfo *__hidden this) =
{
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf
}; // weak
const struct DeleteLeafTransactInfo *(__thiscall *GRPNoArgsCommand::vftable[6])(DeleteLeafTransactInfo *__hidden this) =
{
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf
}; // weak
const struct DeleteLeafTransactInfo *(__thiscall *GRPWithArgsCommand::vftable[4])(DeleteLeafTransactInfo *__hidden this) =
{
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf
}; // weak
const struct DeleteLeafTransactInfo *(__thiscall *GRPShadowVariableObject::vftable[2])(DeleteLeafTransactInfo *__hidden this) =
{
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf
}; // weak
const struct DeleteLeafTransactInfo *(__thiscall *GRPTypedVariableObject::vftable[2])(DeleteLeafTransactInfo *__hidden this) =
{
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf,
  &DeleteLeafTransactInfo::DynamicCast_DeleteLeaf
}; // weak
int (__thiscall *SurfaceWindow::vftable[2])(void *, char) =
{
  &SurfaceWindow::scalar_deleting_destructor,
  &Device::DeviceDialogBoxGateway::scalar_deleting_destructor
}; // weak
int (__thiscall *Device::DeviceDialogBoxGateway::vftable)(void *, char) = &Device::DeviceDialogBoxGateway::scalar_deleting_destructor; // weak
int (__thiscall *GlobalEventHandler::vftable)(void *, char) = &GlobalEventHandler::scalar_deleting_destructor; // weak
int (__thiscall *NoticeRegistrar::vftable)(void *, char) = &NoticeRegistrar::vector_deleting_destructor; // weak
int (__thiscall *List<NoticeHandler *>::vftable[3])(void *, char) =
{
  &List<NoticeHandler *>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,List<NoticeHandler *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<NoticeHandler *> *> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,List<NoticeHandler *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,List<NoticeHandler *> *,0>::vftable)(void *, char) = &HashTable<unsigned long,List<NoticeHandler *> *,0>::vector_deleting_destructor; // weak
int (__thiscall *UISurface::vftable)(void *, char) = &UISurface::vector_deleting_destructor; // weak
void *RenderSurface::vftable = &RenderSurface::vector_deleting_destructor; // weak
__int32 (__stdcall *RenderSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *FileNodeName_Binary::vftable)(void *, char) = &FileNodeName_Binary::vector_deleting_destructor; // weak
int (__thiscall *RenderMeshMaterialArray::vftable[3])(void *, char) =
{
  &RenderMeshMaterialArray::scalar_deleting_destructor,
  &RenderMeshVerticesArray::scalar_deleting_destructor,
  &RenderMeshIndicesArray::scalar_deleting_destructor
}; // weak
int (__thiscall *RenderMeshVerticesArray::vftable[2])(void *, char) =
{
  &RenderMeshVerticesArray::scalar_deleting_destructor,
  &RenderMeshIndicesArray::scalar_deleting_destructor
}; // weak
int (__thiscall *RenderMeshIndicesArray::vftable)(void *, char) = &RenderMeshIndicesArray::scalar_deleting_destructor; // weak
__int32 (__stdcall *RenderMesh::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
bool (__thiscall *AutoStoreVersionArchive::tagSerializeVersionRow::vftable)(AutoStoreVersionArchive::tagSerializeVersionRow *this, struct Archive *) = &AutoStoreVersionArchive::tagSerializeVersionRow::InitializeArchive; // weak
void (__thiscall *AutoStoreVersionArchive::vftable[2])(AutoStoreVersionArchive *this, ArchiveInitializer *i_rInitializer, const struct SmartBuffer *) =
{
  &AutoStoreVersionArchive::InitForPacking,
  &AutoStoreVersionArchive::InitForUnpacking
}; // weak
int (__thiscall *GraphicsResource::vftable)(void *, char) = &GraphicsResource::scalar_deleting_destructor; // weak
int (__thiscall *VertexArray::vftable)(void *, char) = &VertexArray::vector_deleting_destructor; // weak
int (__thiscall *RenderVertexBuffer::vftable)(void *, char) = &RenderVertexBuffer::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vftable)(void *, char) = &IntrusiveHashTable<UIObject *,HashList<UIObject *,UIObject *,1>::HashListData *,1>::vector_deleting_destructor; // weak
__int32 (__stdcall *RenderMaterial::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *RenderTexture::vftable = &RenderTexture::vector_deleting_destructor; // weak
__int32 (__stdcall *RenderTexture::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *RenderIndexBuffer::vftable)(void *, char) = &RenderIndexBuffer::vector_deleting_destructor; // weak
__int32 (__stdcall *MaterialInstance::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *RenderMeshFragment::vftable[2])(void *, char) =
{
  &RenderMeshFragment::vector_deleting_destructor,
  &RenderMeshFragmentTopology::vector_deleting_destructor
}; // weak
int (__thiscall *RenderMeshFragmentTopology::vftable)(void *, char) = &RenderMeshFragmentTopology::vector_deleting_destructor; // weak
int (__thiscall *RenderMeshBatch::vftable)(void *, char) = &RenderMeshBatch::scalar_deleting_destructor; // weak
__int32 (__stdcall *MaterialModifier::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *LM_UVTranslate::vftable)(ProjectileSpell *__hidden this) = &ProjectileSpell::IsProjectileSpell; // weak
unsigned __int32 (__thiscall *LM_UVRotate::vftable)(CLandBlockInfo *__hidden this) = &CLandBlockInfo::GetDBOType; // weak
enum NodeNameType (__thiscall *LM_UVScale::vftable)(FileNodeName_Double *__hidden this) = &FileNodeName_Double::GetType; // weak
unsigned int (__thiscall *LM_UVTransform::vftable)(EtherealHook *__hidden this) = &EtherealHook::pack_size; // weak
Turbine_GUID CObjectMaint_InterfaceType_4 = { 4194796813u, 53636u, 18433u, "á¿AígÑ´\v" }; // idb
Turbine_GUID CObjectMaint_Factory_ClassType = { 396186599u, 3782u, 17588u, "•HH§–Ä1" }; // idb
Turbine_GUID Interface_InterfaceType_21 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *SmartBox::vftable)(void *, char) = &SmartBox::scalar_deleting_destructor; // weak
const float F_EPSILON_37 =  0.00019999999; // idb
void (__thiscall *CInputHandler::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
int (__stdcall *CameraManager::vftable)(char) = &CameraManager::scalar_deleting_destructor; // weak
void (__thiscall *CameraManager::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
const float CAMERA_MOUSELOOK_LIMIT =  0.80000001; // idb
const float CAMERA_DEFAULT_PIVOT_Z =  1.5; // idb
int (__thiscall *CameraSet::vftable)(void *, char) = &CameraSet::vector_deleting_destructor; // weak
const unsigned int Element_mouse_click_UIElementMessage = 25u; // idb
const unsigned int Element_mouse_press_UIElementMessage = 28u; // idb
const unsigned int Element_mouse_release_UIElementMessage = 29u; // idb
const unsigned int Element_mouse_tap_UIElementMessage = 64u; // idb
const long double INVALID_TIME_4 = -1.0; // idb
int (__thiscall *ElementDesc::vftable)(void *, char) = &NonDBObjElementDesc::scalar_deleting_destructor; // weak
int (__thiscall *List<UIElementMessageInfo>::vftable[10])(void *, char) =
{
  &List<UIElementMessageInfo>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vftable[9])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::vftable[8])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIMessageData,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::vftable[7])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SmartArray<UIElement *,1>> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vftable[6])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &)> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vftable[5])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashSetData<unsigned long> *,1>::vector_deleting_destructor,
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vftable[4])(void *, char) =
{
  &HashTable<unsigned long,UIElement * (__cdecl *)(LayoutDesc const &,ElementDesc const &),0>::vector_deleting_destructor,
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashSet<unsigned long>::vftable[3])(void *, char) =
{
  &HashSet<unsigned long>::vector_deleting_destructor,
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *AutoGrowHashTable<unsigned long,SmartArray<UIElement *,1>>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,SmartArray<UIElement *,1>,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,SmartArray<UIMessageData,1>,1>::vftable)(void *, char) = &AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>::scalar_deleting_destructor; // weak
int (__stdcall *UIElementManager::vftable)(char) = &UIElementManager::vector_deleting_destructor; // weak
void (__thiscall *UIElementManager::vftable)(UIElementManager *this, InputEvent *i_evt) = &UIElementManager::ActionHandler; // weak
int (__thiscall *HashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>,1>::vftable)(void *, char) = &AutoGrowHashTable<unsigned long,AutoGrowHashTable<unsigned long,SmartArray<UIMessageData,1>>>::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<UIListener *,HashSetData<UIListener *> *,1>::scalar_deleting_destructor,
  &HashSet<UIListener *>::vector_deleting_destructor,
  &UIElement::vector_deleting_destructor
}; // weak
int (__thiscall *HashSet<UIListener *>::vftable[2])(void *, char) =
{
  &HashSet<UIListener *>::vector_deleting_destructor,
  &UIElement::vector_deleting_destructor
}; // weak
int (__thiscall *UIElement::vftable)(void *, char) = &UIElement::vector_deleting_destructor; // weak
int (__thiscall *PropertyCollection::vftable)(void *, char) = &PropertyCollection::vector_deleting_destructor; // weak
const long double INVALID_TIME_5 = -1.0; // idb
int (__thiscall *MediaMachine::vftable)(void *, char) = &MediaMachine::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<UIElement *,HashSetData<UIElement *> *,1>::vector_deleting_destructor,
  &HashSet<UIElement *>::vector_deleting_destructor,
  &UIListener::scalar_deleting_destructor
}; // weak
int (__thiscall *HashSet<UIElement *>::vftable[2])(void *, char) =
{
  &HashSet<UIElement *>::vector_deleting_destructor,
  &UIListener::scalar_deleting_destructor
}; // weak
int (__thiscall *UIListener::vftable)(void *, char) = &UIListener::scalar_deleting_destructor; // weak
const long double INVALID_TIME_6 = -1.0; // idb
int (__thiscall *ListIterator<Glyph>::vftable[2])(void *, char) =
{
  &ListIterator<Glyph>::scalar_deleting_destructor,
  &UIElement_Text::vector_deleting_destructor
}; // weak
int (__thiscall *UIElement_Text::vftable)(void *, char) = &UIElement_Text::vector_deleting_destructor; // weak
int (__thiscall *UIElement_GroupBox::vftable)(void *, char) = &UIElement_GroupBox::vector_deleting_destructor; // weak
int (__thiscall *UIElement_ColorPicker::vftable)(void *, char) = &UIElement_ColorPicker::scalar_deleting_destructor; // weak
void (__thiscall *UIElement_Browser::vftable)(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int) = &gmNoticeHandler::RecvNotice_BookAddPageResponse; // weak
bool (__thiscall *UIElement_Browser::vftable)(AsyncCache *this, const struct QualifiedDataID *i_nMin, struct DBOCache *) = &AsyncCache::AsyncGetFromOtherSources; // weak
int (__thiscall *UIElement_Browser::vftable)(void *, char) = &UIElement_Browser::vector_deleting_destructor; // weak
int (__thiscall *UIElement_Resizebar::vftable)(void *, char) = &UIElement_Resizebar::vector_deleting_destructor; // weak
int (__thiscall *UIElement_Viewport::vftable)(void *, char) = &UIElement_Viewport::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned long> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,unsigned long,0>::scalar_deleting_destructor,
  &UIElement_Panel::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,unsigned long,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,unsigned long,0>::scalar_deleting_destructor,
  &UIElement_Panel::vector_deleting_destructor
}; // weak
int (__thiscall *UIElement_Panel::vftable)(void *, char) = &UIElement_Panel::vector_deleting_destructor; // weak
int (__thiscall *UIElement_Dragbar::vftable)(void *, char) = &UIElement_Dragbar::scalar_deleting_destructor; // weak
int (__thiscall *UIElement_Menu::vftable)(void *, char) = &UIElement_Menu::scalar_deleting_destructor; // weak
int (__thiscall *UIElement_ListBox::vftable)(void *, char) = &UIElement_ListBox::vector_deleting_destructor; // weak
const long double INVALID_TIME_7 = -1.0; // idb
int (__thiscall *UIElement_Meter::vftable)(void *, char) = &UIElement_Meter::vector_deleting_destructor; // weak
const long double INVALID_TIME_8 = -1.0; // idb
int (__thiscall *UIElement_Scrollbar::vftable)(void *, char) = &UIElement_Scrollbar::scalar_deleting_destructor; // weak
int (__thiscall *UIElement_Button::vftable)(void *, char) = &UIElement_Button::scalar_deleting_destructor; // weak
int (__thiscall *UIElement_Field::vftable)(void *, char) = &UIElement_Field::scalar_deleting_destructor; // weak
int (__thiscall *GlyphLine::vftable[3])(void *, char) =
{
  &GlyphLine::vector_deleting_destructor,
  &List<Glyph>::scalar_deleting_destructor,
  &GlyphList::scalar_deleting_destructor
}; // weak
int (__thiscall *List<Glyph>::vftable[2])(void *, char) =
{
  &List<Glyph>::scalar_deleting_destructor,
  &GlyphList::scalar_deleting_destructor
}; // weak
int (__thiscall *GlyphList::vftable)(void *, char) = &GlyphList::scalar_deleting_destructor; // weak
int (__thiscall *UIElement_Scrollable::vftable)(void *, char) = &UIElement_Scrollable::vector_deleting_destructor; // weak
int (__thiscall *WaitDialog::vftable)(void *, char) = &WaitDialog::vector_deleting_destructor; // weak
int (__thiscall *TextInputDialog::vftable)(void *, char) = &TextInputDialog::scalar_deleting_destructor; // weak
int (__thiscall *MessageDialog::vftable)(void *, char) = &MessageDialog::scalar_deleting_destructor; // weak
int (__thiscall *MenuDialog::vftable)(void *, char) = &MenuDialog::vector_deleting_destructor; // weak
int (__thiscall *ConfirmationTextInputDialog::vftable)(void *, char) = &ConfirmationTextInputDialog::scalar_deleting_destructor; // weak
int (__thiscall *ConfirmationMenuDialog::vftable)(void *, char) = &ConfirmationMenuDialog::vector_deleting_destructor; // weak
int (__thiscall *ConfirmationDialog::vftable)(void *, char) = &ConfirmationDialog::vector_deleting_destructor; // weak
const long double INVALID_TIME_10 = -1.0; // idb
int (__thiscall *Dialog::vftable)(void *, char) = &Dialog::vector_deleting_destructor; // weak
int (__thiscall *List<DialogInfo>::vftable[8])(void *, char) =
{
  &List<DialogInfo>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::vftable[7])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<DialogInfo>> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::vftable[6])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DialogInfo> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::vftable[5])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,void (__cdecl *)(PropertyCollection const &)> *,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,List<DialogInfo>,0>::vftable[4])(void *, char) =
{
  &HashTable<unsigned long,List<DialogInfo>,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,DialogInfo,0>::vftable[3])(void *, char) =
{
  &HashTable<unsigned long,DialogInfo,0>::scalar_deleting_destructor,
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vector_deleting_destructor,
  &TextTag_DID::scalar_deleting_destructor
}; // weak
int (__thiscall *TextTag_DID::vftable)(void *, char) = &TextTag_DID::scalar_deleting_destructor; // weak
int (__thiscall *TextTag_IIDString::vftable)(void *, char) = &TextTag_IIDString::vector_deleting_destructor; // weak
int (__thiscall *TextTag_IIDEnum::vftable)(void *, char) = &TextTag_IIDEnum::scalar_deleting_destructor; // weak
int (__thiscall *TextTag_IID::vftable)(void *, char) = &TextTag_IID::scalar_deleting_destructor; // weak
int (__thiscall *TextTag::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
Turbine_GUID Interface_InterfaceType_26 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__stdcall *UIFlow::vftable)(char) = &UIFlow::vector_deleting_destructor; // weak
__int32 (__stdcall *gmUIFlow::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIMainFramework * (__cdecl *)(void)> *,0>::vector_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable)(void *, char) = &HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vector_deleting_destructor; // weak
int (__thiscall *CharacterSet::vftable)(void *, char) = &CharacterSet::vector_deleting_destructor; // weak
bool (__thiscall *UIPersistantData::vftable)(DBObj *this) = &DBObj::InitLoad; // weak
int (__thiscall *gmGlobalEventHandler::vftable)(void *, char) = &gmGlobalEventHandler::scalar_deleting_destructor; // weak
Turbine_GUID UIFlow_ClassType_1 = { 1575365287u, 26701u, 17415u, "¢¨\x11\x13òSUc" }; // idb
Turbine_GUID IObjectFactory_InterfaceType_13 = { 1244181156u, 45353u, 18515u, "ó∏\x13€Güv," }; // idb
Turbine_GUID Interface_InterfaceType_29 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
bool (__thiscall *gmUIFlow::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__stdcall *gmUIFlow::vftable)(char) = &gmUIFlow::vector_deleting_destructor; // weak
bool (__thiscall *gmUIFlow::vftable)(DBObj *this) = &DBObj::InitLoad; // weak
__int32 (__stdcall *ClassFactoryForceUIFlow_ClassType::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
bool (__thiscall *gmCGSummaryPage::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCGSummaryPage::vftable)(void *, char) = &gmCGSummaryPage::scalar_deleting_destructor; // weak
int (__thiscall *gmCGTownPage::vftable)(void *, char) = &gmCGTownPage::vector_deleting_destructor; // weak
void (__thiscall *Skill_CG::vftable)(Skill_CG *this, struct Archive *) = &Skill_CG::Serialize; // weak
void (__thiscall *HairStyle_CG::vftable)(HairStyle_CG *this, struct Archive *) = &HairStyle_CG::Serialize; // weak
void (__thiscall *EyesStrip_CG::vftable)(EyesStrip_CG *this, struct Archive *) = &EyesStrip_CG::Serialize; // weak
void (__thiscall *FaceStrip_CG::vftable)(FaceStrip_CG *this, struct Archive *) = &FaceStrip_CG::Serialize; // weak
bool (__thiscall *gmCGAppearancePage::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCGAppearancePage::vftable)(void *, char) = &gmCGAppearancePage::vector_deleting_destructor; // weak
void (__thiscall *Style_CG::vftable)(Style_CG *this, struct Archive *) = &Style_CG::Serialize; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Sex_CG> *,0>::vector_deleting_destructor; // weak
void (__thiscall *Template_CG::vftable)(Template_CG *this, struct Archive *) = &Template_CG::Serialize; // weak
void (__thiscall *Sex_CG::vftable)(Sex_CG *this, struct Archive *) = &Sex_CG::Serialize; // weak
int (__thiscall *HashTable<unsigned long,Sex_CG,0>::vftable)(void *, char) = &HashTable<unsigned long,Sex_CG,0>::vector_deleting_destructor; // weak
void (__thiscall *HeritageGroup_CG::vftable)(HeritageGroup_CG *this, struct Archive *) = &HeritageGroup_CG::Serialize; // weak
int (__thiscall *SkillFormula::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned int,HashTableData<unsigned int,gmCGSkillsPage::tagSkillRecord> *,0>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned int,gmCGSkillsPage::tagSkillRecord,0>::scalar_deleting_destructor,
  &gmCGSkillsPage::scalar_deleting_destructor
}; // weak
int (__thiscall *gmCGSkillsPage::vftable)(void *, char) = &gmCGSkillsPage::scalar_deleting_destructor; // weak
int (__thiscall *gmCGProfessionPage::vftable)(void *, char) = &gmCGProfessionPage::vector_deleting_destructor; // weak
int (__thiscall *gmCGHeritagePage::vftable)(void *, char) = &gmCGHeritagePage::vector_deleting_destructor; // weak
void *UIOption_Menu::vftable = &UIOption_Menu::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_Menu::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
void *UIOption_CheckboxSlider::vftable = &UIOption_CheckboxSlider::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_CheckboxSlider::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
Turbine_GUID CPlayerModule_InterfaceType_8 = { 4204615439u, 51729u, 19767u, "´\"2À\x1A\v\bz" }; // idb
Turbine_GUID CPlayerModule_ClassType = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
void *UIOption_Slider::vftable = &UIOption_Slider::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_Slider::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
Turbine_GUID CPlayerModule_ClassType_0 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
bool (__thiscall *UIOption_CheckboxBitfield64::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
void *UIOption_CheckboxBitfield64::vftable = &UIOption_CheckboxBitfield64::vector_deleting_destructor; // weak
Turbine_GUID CPlayerModule_ClassType_1 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
void *UIOption_CheckboxBitfield::vftable = &UIOption_CheckboxBitfield::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_CheckboxBitfield::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
Turbine_GUID CPlayerModule_ClassType_2 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
void *UIOption_Checkbox::vftable = &UIOption_Checkbox::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_Checkbox::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *List<unsigned long>::vftable[2])(void *, char) =
{
  &List<unsigned long>::scalar_deleting_destructor,
  &List<QualifiedControl>::vector_deleting_destructor
}; // weak
int (__thiscall *List<QualifiedControl>::vftable)(void *, char) = &List<QualifiedControl>::vector_deleting_destructor; // weak
void (__thiscall *UIOption_ActionKeyMap::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
void *UIOption_ActionKeyMap::vftable = &UIOption_ActionKeyMap::vector_deleting_destructor; // weak
bool (__thiscall *UIOption_ActionKeyMap::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *SpellComponentBase::vftable)(void *, char) = &SpellComponentBase::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,SpellComponentRegion *> *,0>::vector_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::vftable)(void *, char) = &HashTable<IDClass<_tagDataID,32,0>,SpellComponentRegion *,0>::scalar_deleting_destructor; // weak
bool (__thiscall *gmSpellComponentUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSpellComponentUI::vftable)(void *, char) = &gmSpellComponentUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_InterfaceType_10 = { 59337336u, 41374u, 19810u, "Ç]\x02±z,7+" }; // idb
Turbine_GUID PlayerDesc_ClassType = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *SpellFormula::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
bool (__thiscall *gmSpellbookUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSpellbookUI::vftable)(void *, char) = &gmSpellbookUI::vector_deleting_destructor; // weak
int (__thiscall *PackableList<unsigned long>::vftable)(void *, char) = &PackableList<unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *CSpellBase::vftable)(void *, char) = &CSpellBase::scalar_deleting_destructor; // weak
int (__thiscall *AC1Legacy::List<FriendData>::vftable[2])(void *, char) =
{
  &AC1Legacy::List<FriendData>::scalar_deleting_destructor,
  &AC1Legacy::List<unsigned long>::vector_deleting_destructor
}; // weak
int (__thiscall *AC1Legacy::List<unsigned long>::vftable)(void *, char) = &AC1Legacy::List<unsigned long>::vector_deleting_destructor; // weak
void *PList<unsigned long>::vftable = &PList<unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *FriendData::vftable)(void *, char) = &FriendData::vector_deleting_destructor; // weak
void *PList<FriendData>::vftable = &FriendDataList::vector_deleting_destructor; // weak
int (__thiscall *FriendDataList::vftable)(void *, char) = &PList<FriendData>::scalar_deleting_destructor; // weak
bool (__thiscall *gmSquelchUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSquelchUI::vftable)(void *, char) = &gmSquelchUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmFriendsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFriendsUI::vftable)(void *, char) = &gmFriendsUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFellowshipUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFellowshipUI::vftable)(void *, char) = &gmFellowshipUI::vector_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,Fellow>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,Fellow>::vector_deleting_destructor,
  &Fellow::vector_deleting_destructor
}; // weak
int (__thiscall *Fellow::vftable)(void *, char) = &Fellow::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_0 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void (__thiscall *QualityChangeHandler::vftable[2])(gmNoticeHandler *this, CPortalPoly *portal, __int32 check, int) =
{
  &gmNoticeHandler::RecvNotice_BookAddPageResponse,
  &gmNoticeHandler::RecvNotice_BookAddPageResponse
}; // weak
void (__thiscall *gmAllegianceUI::vftable[2])(gmAllegianceUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmAllegianceUI::OnQualityRemoved, &gmAllegianceUI::OnQualityRemoved }; // weak
bool (__thiscall *gmAllegianceUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmAllegianceUI::vftable)(void *, char) = &gmAllegianceUI::vector_deleting_destructor; // weak
int (__thiscall *gmPageListUI::vftable)(void *, char) = &gmPageListUI::vector_deleting_destructor; // weak
int (__thiscall *gmJournalUI::vftable)(void *, char) = &gmJournalUI::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,CContractTracker>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,CContractTracker>::scalar_deleting_destructor,
  &PackableHashTable<unsigned long,CContractTracker>::scalar_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,CContractTracker>::vftable)(void *, char) = &PackableHashTable<unsigned long,CContractTracker>::scalar_deleting_destructor; // weak
bool (__thiscall *gmContractsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmContractsUI::vftable)(void *, char) = &gmContractsUI::vector_deleting_destructor; // weak
int (__thiscall *CharacterTitleTable::vftable)(void *, char) = &CharacterTitleTable::scalar_deleting_destructor; // weak
bool (__thiscall *gmCharacterTitleUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCharacterTitleUI::vftable)(void *, char) = &gmCharacterTitleUI::vector_deleting_destructor; // weak
int (__thiscall *PList<unsigned long>::vftable)(void *, char) = &PList<unsigned long>::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_1 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *Skill::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
bool (__thiscall *gmSkillUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSkillUI::vftable)(void *, char) = &gmSkillUI::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,SkillBase>::vftable)(void *, char) = &PackableHashIterator<unsigned long,SkillBase>::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_2 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *Attribute::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *SecondaryAttribute::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
bool (__thiscall *gmAttributeUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmAttributeUI::vftable)(void *, char) = &gmAttributeUI::scalar_deleting_destructor; // weak
int (__thiscall *gmGameplayOptionsUI::vftable)(void *, char) = &gmGameplayOptionsUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmConfigUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmConfigUI::vftable)(void *, char) = &gmConfigUI::vector_deleting_destructor; // weak
const unsigned int Option_TextType_Property = 268435583u; // idb
int (__thiscall *ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable[2])(void *, char) =
{
  &ListIterator<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::scalar_deleting_destructor,
  &List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vector_deleting_destructor
}; // weak
int (__thiscall *List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vftable)(void *, char) = &List<DualHashData<UIOption_Slider *,UIOption_Slider *> *>::vector_deleting_destructor; // weak
void (__thiscall *gmChatOptionsUI::vftable)(gmChatOptionsUI *this, const struct UIOption *) = &gmChatOptionsUI::OnOptionChanged; // weak
int (__thiscall *gmChatOptionsUI::vftable)(void *, char) = &gmChatOptionsUI::vector_deleting_destructor; // weak
int (__thiscall *gmCharacterSettingsUI::vftable)(void *, char) = &gmCharacterSettingsUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_3 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
gmMapUI::LocationRolloverInfo s_rgLocations[53] =
{
  { 178u, 20u, 11u, 12u, L"Aerlinthe Island" },
  { 18u, 74u, 5u, 5u, L"Ahurenga" },
  { 141u, 166u, 7u, 6u, L"Al-Arqas" },
  { 129u, 121u, 7u, 6u, L"Al-Jalima" },
  { 190u, 88u, 9u, 8u, L"Arwic" },
  { 19u, 201u, 7u, 6u, L"Ayan Baqur" },
  { 200u, 190u, 7u, 6u, L"Baishi" },
  { 184u, 53u, 5u, 5u, L"Bandit Castle" },
  { 34u, 84u, 5u, 5u, L"Bluespire" },
  { 44u, 235u, 5u, 5u, L"Candeth Keep" },
  { 180u, 97u, 9u, 8u, L"Cragstone" },
  { 91u, 102u, 5u, 5u, L"Danby's Outpost" },
  { 211u, 138u, 9u, 8u, L"Dryreach" },
  { 199u, 106u, 9u, 8u, L"Eastham" },
  { 56u, 13u, 5u, 5u, L"Fiun Outpost" },
  { 37u, 127u, 9u, 8u, L"Fort Tethana" },
  { 156u, 94u, 9u, 8u, L"Glenden Wood" },
  { 43u, 79u, 5u, 5u, L"Greenspire" },
  { 224u, 177u, 7u, 6u, L"Hebian-to" },
  { 164u, 77u, 9u, 8u, L"Holtburg" },
  { 182u, 230u, 7u, 6u, L"Kara" },
  { 155u, 185u, 7u, 6u, L"Khayyaban" },
  { 224u, 218u, 7u, 6u, L"Kryst" },
  { 212u, 195u, 7u, 6u, L"Lin" },
  { 159u, 224u, 5u, 5u, L"Linvak Tukal" },
  { 185u, 126u, 9u, 8u, L"Lytelthorpe" },
  { 235u, 220u, 7u, 6u, L"MacNiall's Freehold" },
  { 223u, 203u, 7u, 6u, L"Mayoi" },
  { 141u, 53u, 5u, 5u, L"Mt Esper-Crater Village" },
  { 224u, 191u, 7u, 6u, L"Nanto" },
  { 142u, 46u, 5u, 5u, L"Neydisa" },
  { 240u, 128u, 5u, 5u, L"Oolutanga's Refuge" },
  { 74u, 79u, 5u, 5u, L"Plateau Village" },
  { 148u, 218u, 7u, 6u, L"Qalaba'r" },
  { 26u, 83u, 5u, 5u, L"Redspire" },
  { 193u, 114u, 9u, 8u, L"Rithwic" },
  { 146u, 133u, 7u, 6u, L"Samsur" },
  { 50u, 42u, 5u, 5u, L"Sanamar" },
  { 195u, 163u, 7u, 6u, L"Sawato" },
  { 213u, 171u, 7u, 6u, L"Shoushi" },
  { 41u, 25u, 5u, 5u, L"Silyun" },
  { 6u, 239u, 15u, 16u, L"Singularity Caul Island" },
  { 100u, 48u, 5u, 5u, L"Stonehold" },
  { 32u, 76u, 5u, 5u, L"Timaru" },
  { 239u, 163u, 7u, 6u, L"Tou-Tou" },
  { 131u, 148u, 7u, 6u, L"Tufa" },
  { 112u, 244u, 5u, 5u, L"Ulgrim's Island" },
  { 159u, 160u, 7u, 6u, L"Uziz" },
  { 63u, 203u, 7u, 6u, L"Wai Jhou" },
  { 144u, 181u, 7u, 6u, L"Xarabydun" },
  { 175u, 145u, 7u, 6u, L"Yanshi" },
  { 121u, 156u, 7u, 6u, L"Yaraq" },
  { 123u, 112u, 7u, 6u, L"Zaikhal" }
}; // idb
bool (__thiscall *gmMapUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmMapUI::vftable)(void *, char) = &gmMapUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_4 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmHouseUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmHouseUI::vftable)(void *, char) = &gmHouseUI::scalar_deleting_destructor; // weak
int (__thiscall *HousePayment::vftable)(void *, char) = &HousePayment::scalar_deleting_destructor; // weak
const float LIGHT_LOW_MIN =  0.0; // idb
const float LIGHT_LOW_MAX =  0.34999999; // idb
const float LIGHT_HIGH_MIN =  0.99000001; // idb
const float LIGHT_HIGH_MAX =  1.0; // idb
Turbine_GUID PlayerDesc_ClassType_5 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *InventoryPlacement::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
bool (__thiscall *ItemListDragHandler::vftable)(ItemListDragHandler *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &ItemListDragHandler::OnItemListDragOver; // weak
bool (__thiscall *gmPaperDollUI::vftable)(gmPaperDollUI *this, UIElement_UIItem *_catchElement, UI_SLOT_SIDE slotSide, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmPaperDollUI::OnItemListDragOver; // weak
void (__thiscall *gmPaperDollUI::vftable[2])(gmPaperDollUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmPaperDollUI::OnQualityChanged, &gmPaperDollUI::OnQualityChanged }; // weak
bool (__thiscall *gmPaperDollUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmPaperDollUI::vftable)(void *, char) = &gmPaperDollUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmInventoryUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmInventoryUI::vftable)(void *, char) = &gmInventoryUI::vector_deleting_destructor; // weak
bool (__thiscall *gmBackpackUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmBackpackUI::vftable)(void *, char) = &gmBackpackUI::vector_deleting_destructor; // weak
int (__thiscall *gm3DItemsUI::vftable)(void *, char) = &gm3DItemsUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_6 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void (__thiscall *gmVitaeUI::vftable[2])(gmVitaeUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmVitaeUI::OnQualityRemoved, &gmVitaeUI::OnQualityRemoved }; // weak
bool (__thiscall *gmVitaeUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmVitaeUI::vftable)(void *, char) = &gmVitaeUI::vector_deleting_destructor; // weak
int (__thiscall *gmUrgentAssistanceUI::vftable)(void *, char) = &gmUrgentAssistanceUI::vector_deleting_destructor; // weak
bool (__thiscall *gmMiniGameUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmMiniGameUI::vftable)(void *, char) = &gmMiniGameUI::scalar_deleting_destructor; // weak
int (__thiscall *TChessPiece<CBasePiece>::vftable)(DefaultScriptHook *this, void **addr, unsigned int) = &DefaultScriptHook::UnPack; // weak
int (__thiscall *CChessLogic<CBasePiece>::vftable)(void *, char) = &CChessLogic<CBasePiece>::scalar_deleting_destructor; // weak
int (__stdcall *TPawnPiece<CBasePiece>::vftable[2])(int, int dy) = { &TPawnPiece<CBasePiece>::bCanGoTo, &TPawnPiece<CBasePiece>::bCanAttack }; // weak
int (__stdcall *TRookPiece<CBasePiece>::vftable[2])(int, int dy) = { &TRookPiece<CBasePiece>::bCanGoTo, &TChessPiece<CBasePiece>::bCanAttack }; // weak
int (__stdcall *TKnightPiece<CBasePiece>::vftable[2])(int, int dy) = { &TKnightPiece<CBasePiece>::bCanGoTo, &TChessPiece<CBasePiece>::bCanAttack }; // weak
int (__stdcall *TBishopPiece<CBasePiece>::vftable[2])(int, int dy) = { &TBishopPiece<CBasePiece>::bCanGoTo, &TChessPiece<CBasePiece>::bCanAttack }; // weak
int (__stdcall *TQueenPiece<CBasePiece>::vftable[2])(int, int dy) = { &TQueenPiece<CBasePiece>::bCanGoTo, &TChessPiece<CBasePiece>::bCanAttack }; // weak
int (__stdcall *TKingPiece<CBasePiece>::vftable[2])(int, int dy) = { &TKingPiece<CBasePiece>::bCanGoTo, &TChessPiece<CBasePiece>::bCanAttack }; // weak
int (__thiscall *GameBoardGrid::vftable)(void *, char) = &GameBoardGrid::scalar_deleting_destructor; // weak
bool (__thiscall *gmLinkStatusUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmLinkStatusUI::vftable)(void *, char) = &gmLinkStatusUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_7 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
const long double MISSILE_RANGE_CAP =  85.0; // idb
const float RADAR_OUTDOOR_RADIUS =  75.0; // idb
bool (__thiscall *gmExaminationUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmExaminationUI::vftable)(void *, char) = &gmExaminationUI::scalar_deleting_destructor; // weak
void (__thiscall *ExamineSubUI::vftable)(ExamineSubUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &ExamineSubUI::Init; // weak
int (__thiscall *ArmorProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
void (__thiscall *ItemExamineUI::vftable)(ExamineSubUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &ExamineSubUI::Init; // weak
void (__thiscall *SpellExamineUI::vftable)(ExamineSubUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &ExamineSubUI::Init; // weak
void (__thiscall *BasicCreatureExamineUI::vftable)(BasicCreatureExamineUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &BasicCreatureExamineUI::Init; // weak
void (__thiscall *CreatureExamineUI::vftable)(BasicCreatureExamineUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &BasicCreatureExamineUI::Init; // weak
void (__thiscall *CharExamineUI::vftable)(BasicCreatureExamineUI *this, unsigned __int32 _objid, struct ACCWeenieObject *) = &BasicCreatureExamineUI::Init; // weak
Turbine_GUID PlayerDesc_ClassType_8 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *PackableList<Enchantment>::vftable)(void *, char) = &PackableList<Enchantment>::vector_deleting_destructor; // weak
bool (__thiscall *gmEffectsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmEffectsUI::vftable)(void *, char) = &gmEffectsUI::vector_deleting_destructor; // weak
int (__thiscall *StatMod::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *Enchantment::vftable)(void *, char) = &Enchantment::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_9 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void (__thiscall *gmCharacterInfoUI::vftable[2])(gmCharacterInfoUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmCharacterInfoUI::OnQualityChanged, &gmCharacterInfoUI::OnQualityChanged }; // weak
bool (__thiscall *gmCharacterInfoUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCharacterInfoUI::vftable)(void *, char) = &gmCharacterInfoUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_10 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void *ObjectRangeHandler::vftable = &_purecall; // weak
void (__thiscall *gmBookUI::vftable)(gmBookUI *this, unsigned __int32) = &gmBookUI::OnObjectRangeExit; // weak
bool (__thiscall *gmBookUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmBookUI::vftable)(void *, char) = &gmBookUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmAbuseUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmAbuseUI::vftable)(void *, char) = &gmAbuseUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmPanelUI::vftable)(void *, char) = &gmPanelUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_11 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID CPlayerModule_ClassType_3 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
bool (__thiscall *gmToolbarUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmToolbarUI::vftable)(void *, char) = &gmToolbarUI::scalar_deleting_destructor; // weak
int (__thiscall *gmIndicatorsUI::vftable)(void *, char) = &gmIndicatorsUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_12 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void (__thiscall *gmFloatyVitalsUI::vftable[2])(gmVitalsUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmVitalsUI::OnQualityChanged, &gmVitalsUI::OnQualityChanged }; // weak
bool (__thiscall *gmVitalsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmVitalsUI::vftable)(void *, char) = &gmVitalsUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_13 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID ClientObjMaintSystem_InterfaceType_31 = { 1609975359u, 15348u, 19208u, "∞A…XÇ\bæ\x1A" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
void (__thiscall *VendorSubUI::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
bool (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &VendorSellUI::OnItemListDragOver; // weak
void (__thiscall *VendorSellUI::vftable)(VendorSellUI *this, bool _updating) = &VendorSellUI::OpenVendor; // weak
int (__thiscall *PackableList<ItemProfile>::vftable)(void *, char) = &PackableList<ItemProfile>::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char) = &PackableHashIterator<IDClass<_tagDataID,32,0>,long>::scalar_deleting_destructor; // weak
void (__thiscall *VendorItemsUI::vftable)(VendorItemsUI *this, bool _updating) = &VendorItemsUI::OpenVendor; // weak
void (__thiscall *VendorBuyUI::vftable)(VendorBuyUI *this, bool _updating) = &VendorBuyUI::OpenVendor; // weak
void (__thiscall *gmVendorUI::vftable)(gmVendorUI *this, unsigned __int32) = &gmVendorUI::OnObjectRangeExit; // weak
void (__thiscall *gmVendorUI::vftable[2])(gmVendorUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmVendorUI::OnQualityChanged, &gmVendorUI::OnQualityRemoved }; // weak
bool (__thiscall *gmVendorUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmVendorUI::vftable)(void *, char) = &gmVendorUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_14 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID CPlayerModule_ClassType_4 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
bool (__thiscall *SpellCastSubMenu::vftable)(SpellCastSubMenu *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &SpellCastSubMenu::OnItemListDragOver; // weak
bool (__thiscall *gmSpellcastingUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSpellcastingUI::vftable)(void *, char) = &gmSpellcastingUI::vector_deleting_destructor; // weak
bool (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmSlumlordUI::OnItemListDragOver; // weak
void (__thiscall *gmSlumlordUI::vftable)(gmSlumlordUI *this, unsigned __int32) = &gmSlumlordUI::OnObjectRangeExit; // weak
bool (__thiscall *gmSlumlordUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSlumlordUI::vftable)(void *, char) = &gmSlumlordUI::scalar_deleting_destructor; // weak
Turbine_GUID ClientObjMaintSystem_ClassType_0 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
bool (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmSecureTradeUI::OnItemListDragOver; // weak
void (__thiscall *gmSecureTradeUI::vftable)(gmSecureTradeUI *this, unsigned __int32) = &gmSecureTradeUI::OnObjectRangeExit; // weak
bool (__thiscall *gmSecureTradeUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSecureTradeUI::vftable)(void *, char) = &gmSecureTradeUI::vector_deleting_destructor; // weak
bool (__thiscall *gmSalvageUI::vftable)(gmSalvageUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmSalvageUI::OnItemListDragOver; // weak
bool (__thiscall *gmSalvageUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSalvageUI::vftable)(void *, char) = &gmSalvageUI::vector_deleting_destructor; // weak
bool (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmExternalContainerUI::OnItemListDragOver; // weak
void (__thiscall *gmExternalContainerUI::vftable)(gmExternalContainerUI *this, unsigned __int32) = &gmExternalContainerUI::OnObjectRangeExit; // weak
bool (__thiscall *gmExternalContainerUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmExternalContainerUI::vftable)(void *, char) = &gmExternalContainerUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_15 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
const float USE_POWER_BAR_LEVEL = -1.0; // idb
bool (__thiscall *gmCombatUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCombatUI::vftable)(void *, char) = &gmCombatUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmEnvPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmEnvPanelUI::vftable)(void *, char) = &gmEnvPanelUI::scalar_deleting_destructor; // weak
int (__thiscall *gmAdminQualitiesUI::vftable)(void *, char) = &gmAdminQualitiesUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_16 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__stdcall *gmMainChatUI::vftable)(char) = &gmMainChatUI::vector_deleting_destructor; // weak
bool (__thiscall *gmMainChatUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyChatUI::vftable)(ChatInterface *this, char) = &gmFloatyChatUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatyChatUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyVitalsUI::vftable)(void *, char) = &gmFloatyVitalsUI::vector_deleting_destructor; // weak
bool (__thiscall *gmToolbarUI::vftable)(gmToolbarUI *this, UIElement_UIItem *_catchElement, unsigned __int32 _dropItemID, unsigned __int32 _dropSpellID, enum DropItemFlags) = &gmToolbarUI::OnItemListDragOver; // weak
bool (__thiscall *gmFloatyToolbarUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyToolbarUI::vftable)(void *, char) = &gmFloatyToolbarUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatySideVitalsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatySideVitalsUI::vftable)(void *, char) = &gmFloatySideVitalsUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatyPowerBarUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyPowerBarUI::vftable)(void *, char) = &gmFloatyPowerBarUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatyPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyPanelUI::vftable)(void *, char) = &gmFloatyPanelUI::vector_deleting_destructor; // weak
int (__stdcall *gmFloatyMainChatUI::vftable)(char) = &gmFloatyMainChatUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmFloatyMainChatUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
bool (__thiscall *gmFloatyIndicatorsUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyIndicatorsUI::vftable)(void *, char) = &gmFloatyIndicatorsUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatyExaminationUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyExaminationUI::vftable)(void *, char) = &gmFloatyExaminationUI::vector_deleting_destructor; // weak
bool (__thiscall *gmFloatyEnvPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyEnvPanelUI::vftable)(void *, char) = &gmFloatyEnvPanelUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmFloatyCombatPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmFloatyCombatPanelUI::vftable)(void *, char) = &gmFloatyCombatPanelUI::scalar_deleting_destructor; // weak
bool (__thiscall *gmSpewBoxUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSpewBoxUI::vftable)(void *, char) = &gmSpewBoxUI::vector_deleting_destructor; // weak
bool (__thiscall *gmSmartBoxUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmSmartBoxUI::vftable)(void *, char) = &gmSmartBoxUI::scalar_deleting_destructor; // weak
Turbine_GUID CObjectMaint_ClassType = { 2458606552u, 10574u, 17473u, "ôç◊¬\x04|Øâ" }; // idb
Turbine_GUID PlayerDesc_ClassType_17 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
const float RADAR_OUTDOOR_RADIUS_0 =  75.0; // idb
void (__thiscall *gmRadarUI::vftable[2])(gmRadarUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmRadarUI::OnQualityChanged, &gmRadarUI::OnQualityRemoved }; // weak
bool (__thiscall *gmRadarUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmRadarUI::vftable)(void *, char) = &gmRadarUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_18 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmPowerbarUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmPowerbarUI::vftable)(void *, char) = &gmPowerbarUI::vector_deleting_destructor; // weak
const unsigned int Movement = 1u; // idb
const unsigned int Camera = 2u; // idb
const unsigned int UI = 3u; // idb
const unsigned int Combat = 4u; // idb
const unsigned int Emote_0 = 5u; // idb
const unsigned int CharacterSettings = 7u; // idb
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vftable[5])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,UIElement_ListBox *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::scalar_deleting_destructor,
  &HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,ActionMapValue,1>::HashListData *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::scalar_deleting_destructor,
  &HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,List<unsigned long>,1>::HashListData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::scalar_deleting_destructor,
  &HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,List<unsigned long>,1>,1>::HashListData *,1>::scalar_deleting_destructor,
  &HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,UIElement_ListBox *,0>::vftable)(void *, char) = &HashTable<unsigned long,UIElement_ListBox *,0>::vector_deleting_destructor; // weak
bool (__thiscall *gmKeyboardUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
void (__thiscall *gmKeyboardUI::vftable)(gmKeyboardUI *this, const struct UIOption *) = &gmKeyboardUI::OnOptionChanged; // weak
int (__thiscall *gmKeyboardUI::vftable)(void *, char) = &gmKeyboardUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_19 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmBarberUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmBarberUI::vftable)(void *, char) = &gmBarberUI::scalar_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_20 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *ClientHousingSystem::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *UIElement_UIItem::vftable)(void *, char) = &UIElement_UIItem::scalar_deleting_destructor; // weak
int (__thiscall *List<UIElement_UIItem *>::vftable)(void *, char) = &List<UIElement_UIItem *>::scalar_deleting_destructor; // weak
bool (__thiscall *UIElement_ItemList::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *UIElement_ItemList::vftable)(void *, char) = &UIElement_ItemList::scalar_deleting_destructor; // weak
bool (__thiscall *UIElement_SmartBoxWrapper::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *UIElement_SmartBoxWrapper::vftable)(void *, char) = &UIElement_SmartBoxWrapper::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_21 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmUIElement_VitaeIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmUIElement_VitaeIndicator::vftable)(void *, char) = &gmUIElement_VitaeIndicator::vector_deleting_destructor; // weak
bool (__thiscall *gmUIElement_PortalStormIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmUIElement_PortalStormIndicator::vftable)(void *, char) = &gmUIElement_PortalStormIndicator::vector_deleting_destructor; // weak
bool (__thiscall *gmUIElement_MiniGameIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmUIElement_MiniGameIndicator::vftable)(void *, char) = &gmUIElement_MiniGameIndicator::vector_deleting_destructor; // weak
void (__thiscall *UIOption_Menu::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
int (__thiscall *gmUIElement_LinkStatusIndicator::vftable)(void *, char) = &gmUIElement_LinkStatusIndicator::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_22 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmUIElement_EffectsIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmUIElement_EffectsIndicator::vftable)(void *, char) = &gmUIElement_EffectsIndicator::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_23 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
bool (__thiscall *gmUIElement_BurdenIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmUIElement_BurdenIndicator::vftable)(void *, char) = &gmUIElement_BurdenIndicator::vector_deleting_destructor; // weak
const long double INVALID_TIME_61 = -1.0; // idb
int (__thiscall *gmUIMainFramework::vftable)(void *, char) = &gmUIMainFramework::vector_deleting_destructor; // weak
int (__thiscall *gmCreditsUI::vftable)(void *, char) = &gmCreditsUI::vector_deleting_destructor; // weak
bool (__thiscall *gmCharGenMainUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCharGenMainUI::vftable)(void *, char) = &gmCharGenMainUI::vector_deleting_destructor; // weak
int (__thiscall *gmDisconnectedUI::vftable)(void *, char) = &gmDisconnectedUI::scalar_deleting_destructor; // weak
int (__thiscall *gmEpilogueUI::vftable)(void *, char) = &gmEpilogueUI::vector_deleting_destructor; // weak
bool (__thiscall *gmGamePlayUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmGamePlayUI::vftable)(void *, char) = &gmGamePlayUI::vector_deleting_destructor; // weak
bool (__thiscall *gmCharacterManagementUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCharacterManagementUI::vftable)(void *, char) = &gmCharacterManagementUI::scalar_deleting_destructor; // weak
void (__thiscall *gmIntroUI::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
int (__thiscall *gmIntroUI::vftable)(void *, char) = &gmIntroUI::scalar_deleting_destructor; // weak
void *gmDataPatchUI::vftable = &gmDataPatchUI::vector_deleting_destructor; // weak
int (__thiscall *gmDataPatchUI::vftable)(void *, char) = &gmDataPatchUI::scalar_deleting_destructor; // weak
int (__thiscall *Subpalette::vftable)(void *, char) = &Subpalette::vector_deleting_destructor; // weak
const float DIALOG_CONFIRM_TIME =  10.0; // idb
bool (__thiscall *UIOption::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
Turbine_GUID PlayerDesc_ClassType_24 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
void (__thiscall *gmStatManagementUI::vftable[2])(gmStatManagementUI *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &gmStatManagementUI::OnQualityRemoved, &gmStatManagementUI::OnQualityRemoved }; // weak
int (__thiscall *gmStatManagementUI::vftable)(void *, char) = &gmStatManagementUI::vector_deleting_destructor; // weak
Turbine_GUID PlayerDesc_ClassType_25 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
int (__thiscall *Attribute2ndBase::vftable)(void *, char) = &Attribute2ndBase::vector_deleting_destructor; // weak
void (__thiscall *InfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &InfoRegion::OnQualityRemoved, &InfoRegion::OnQualityRemoved }; // weak
int (__thiscall *SkillBase::vftable)(void *, char) = &SkillBase::vector_deleting_destructor; // weak
void (__thiscall *AttributeInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &InfoRegion::OnQualityRemoved, &InfoRegion::OnQualityRemoved }; // weak
void (__thiscall *Attribute2ndInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &InfoRegion::OnQualityRemoved, &InfoRegion::OnQualityRemoved }; // weak
void (__thiscall *SkillInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &InfoRegion::OnQualityRemoved, &InfoRegion::OnQualityRemoved }; // weak
void (__thiscall *EffectInfoRegion::vftable[2])(InfoRegion *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &InfoRegion::OnQualityRemoved, &InfoRegion::OnQualityRemoved }; // weak
void (__thiscall *gmConfigUI::vftable)(PlayerOptionPage *this, const struct UIOption *) = &PlayerOptionPage::OnOptionChanged; // weak
int (__thiscall *PlayerOptionPage::vftable)(void *, char) = &PlayerOptionPage::vector_deleting_destructor; // weak
void *OptionPage::vftable = &_purecall; // weak
int (__thiscall *OptionPage::vftable)(void *, char) = &OptionPage::vector_deleting_destructor; // weak
int (__stdcall *ChatInterface::vftable)(char) = &ChatInterface::scalar_deleting_destructor; // weak
bool (__thiscall *ChatInterface::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
bool (__thiscall *gmCombatPanelUI::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *gmCombatPanelUI::vftable)(void *, char) = &gmCombatPanelUI::scalar_deleting_destructor; // weak
const float min_dist =  8.0; // idb
void (__thiscall *VividTargetIndicator::vftable[2])(VividTargetIndicator *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) =
{
  &VividTargetIndicator::OnQualityRemoved,
  &VividTargetIndicator::OnQualityRemoved
}; // weak
bool (__thiscall *VividTargetIndicator::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
Turbine_GUID CLCache_InterfaceType_13 = { 277031508u, 17503u, 17448u, "∏Gïå¥ô^Á" }; // idb
__int32 (__stdcall *DBFile2IDTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__stdcall *DBFile2IDTable::vftable)(IDClass<_tagDataID,32,0> *result, PStringBase<char> _FileName, PStringBase<char> FileNameCopy) = &TFile2IDTable::GetDIDByFileName; // weak
void (__thiscall *DDD_EndDDDMessage::vftable)(FakeMessageData *this, struct Archive *) = &FakeMessageData::Serialize; // weak
void *SerializeUsingPackDBObj::vftable = &SerializeUsingPackDBObj::vector_deleting_destructor; // weak
__int32 (__stdcall *SerializeUsingPackDBObj::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *Font::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *FontLocal::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *DDD_DataMessage::vftable)(DDD_DataMessage *this, struct Archive *) = &DDD_DataMessage::Serialize; // weak
void (__thiscall *DDD_RequestDataMessage::vftable)(DDD_RequestDataMessage *this, struct Archive *) = &DDD_RequestDataMessage::Serialize; // weak
int (__thiscall *DDD_ErrorMessage::vftable)(_DWORD, _DWORD) = &DDD_ErrorMessage::Serialize; // weak
int (__thiscall *IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<QualifiedDataID,HashTableData<QualifiedDataID,MissingIteration *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vector_deleting_destructor,
  &CLCache::CAsyncBeginDDDRequest::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,DiskController *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vector_deleting_destructor,
  &CLCache::CAsyncBeginDDDRequest::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,unsigned long> *,0>::vector_deleting_destructor,
  &CLCache::CAsyncBeginDDDRequest::scalar_deleting_destructor
}; // weak
int (__thiscall *CLCache::CAsyncBeginDDDRequest::vftable)(void *, char) = &CLCache::CAsyncBeginDDDRequest::scalar_deleting_destructor; // weak
int (__thiscall *DDD_InterrogationMessage::vftable)(_DWORD, _DWORD) = &DDD_InterrogationMessage::Serialize; // weak
int (__thiscall *LongNIValHash<unsigned long>::vftable[2])(void *, char) =
{
  &LongNIValHash<unsigned long>::vector_deleting_destructor,
  &LongNIValHash<LongHash<MotionData> *>::vector_deleting_destructor
}; // weak
int (__thiscall *LongNIValHash<LongHash<MotionData> *>::vftable)(void *, char) = &LongNIValHash<LongHash<MotionData> *>::vector_deleting_destructor; // weak
void (__thiscall *MissingIteration::vftable)(MissingIteration *this, struct Archive *) = &MissingIteration::Serialize; // weak
int (__thiscall *CThreadsafeDiskController::vftable)(void *, char) = &CThreadsafeDiskController::scalar_deleting_destructor; // weak
void (__thiscall *CAllIterationList::vftable)(CAllIterationList *this, struct Archive *) = &CAllIterationList::Serialize; // weak
int (__thiscall *DDD_BeginDDDMessage::vftable)(_DWORD, _DWORD) = &DDD_BeginDDDMessage::Serialize; // weak
int (__thiscall *List<AsyncCache::CAsyncRequest *>::vftable)(void *, char) = &List<AsyncCache::CAsyncRequest *>::scalar_deleting_destructor; // weak
int (__stdcall *CMotionTable::vftable)(int) = &CMotionTable::vector_deleting_destructor; // weak
__int32 (__stdcall *CMotionTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *DDD_InterrogationResponseMessage::vftable)(DDD_InterrogationResponseMessage *this, struct Archive *) = &DDD_InterrogationResponseMessage::Serialize; // weak
int (__thiscall *HashTable<unsigned __int64,DiskController *,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned __int64,DiskController *,0>::vector_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vftable)(void *, char) = &HashTable<IDClass<_tagDataID,32,0>,unsigned long,0>::vector_deleting_destructor; // weak
__int32 (__stdcall *DualEnumIDMap::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *CLCache::vftable = &CLCache::vector_deleting_destructor; // weak
DBObj *(__thiscall *gmCLCache::vftable)(CLCache *this, unsigned __int32 type, QualifiedDataID *qdid) = &CLCache::BlockingGet; // weak
__int32 (__stdcall *CLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *HashTable<QualifiedDataID,MissingIteration *,1>::vftable[2])(void *, char) =
{
  &AutoGrowHashTable<QualifiedDataID,MissingIteration *>::scalar_deleting_destructor,
  &DBOCache::scalar_deleting_destructor
}; // weak
int (__thiscall *CLOCache::vftable)(void *, char) = &DBOCache::scalar_deleting_destructor; // weak
__int32 (__stdcall *IQueuedUIEventDeliverer::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *cWObjHierRootNode::vftable = &cWObjHierRootNode::vector_deleting_destructor; // weak
__int32 (__stdcall *cWObjHierRootNode::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vftable)(void *, char) = &PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,AC1Legacy::PStringBase<char>>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::vftable)(void *, char) = &PackableHashTable<AC1Legacy::PStringBase<char>,ChatEmoteData>::scalar_deleting_destructor; // weak
int (__thiscall *ChatEmoteData::vftable)(void *, char) = &ChatEmoteData::scalar_deleting_destructor; // weak
void *ChatPoseTable::vftable = &ChatPoseTable::vector_deleting_destructor; // weak
__int32 (__stdcall *ChatPoseTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,int>::vftable)(void *, char) = &PackableHashTable<IDClass<_tagDataID,32,0>,int>::vector_deleting_destructor; // weak
void *BadData::vftable = &BadData::vector_deleting_destructor; // weak
__int32 (__stdcall *BadData::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CharacterIdentity::vftable)(void *, char) = &CharacterIdentity::vector_deleting_destructor; // weak
void *CRegionDesc::vftable = &CRegionDesc::vector_deleting_destructor; // weak
__int32 (__stdcall *CRegionDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const unsigned int dword_7C614C[4] = { 15u, 10u, 5u, 0u }; // idb
int (__thiscall *LongHashData::vftable[2])(void *, char) =
{
  &HashBaseData<unsigned long>::scalar_deleting_destructor,
  &LongNIValHash<SurfInfo *>::vector_deleting_destructor
}; // weak
int (__thiscall *LongNIValHash<SurfInfo *>::vftable)(void *, char) = &LongNIValHash<SurfInfo *>::vector_deleting_destructor; // weak
const int ImageShift[5] = { 0, 1, 2, 4, 8 }; // idb
const float LSCAPE_LIGHT_MINIMUM =  0.2; // idb
Turbine_GUID CObjectMaint_InterfaceType_71 = { 4194796813u, 53636u, 18433u, "á¿AígÑ´\v" }; // idb
Turbine_GUID CObjectMaint_ClassType_0 = { 2458606552u, 10574u, 17473u, "ôç◊¬\x04|Øâ" }; // idb
Turbine_GUID stru_7C6690 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *AC1Legacy::PQueueArray<double>::vftable[5])(void *, char) =
{
  &AC1Legacy::PQueueArray<double>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,CLostCell *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vector_deleting_destructor,
  &LongHash<CObjectInventory>::vector_deleting_destructor,
  &HashTable<unsigned long,double,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,CLostCell *,0>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,CLostCell *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vector_deleting_destructor,
  &LongHash<CObjectInventory>::vector_deleting_destructor,
  &HashTable<unsigned long,double,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,double> *,0>::vector_deleting_destructor,
  &LongHash<CObjectInventory>::vector_deleting_destructor,
  &HashTable<unsigned long,double,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *LongHash<CWeenieObject>::vftable[2])(void *, char) =
{
  &LongHash<CObjectInventory>::vector_deleting_destructor,
  &HashTable<unsigned long,double,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,double,0>::vftable)(void *, char) = &HashTable<unsigned long,double,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *CObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const float z_for_landing =  0.0871557; // idb
const float DEFAULT_FRICTION =  0.94999999; // idb
const float DEFAULT_ELASTICITY =  0.050000001; // idb
const float DEFAULT_TRANSLUCENCY =  0.0; // idb
const float DUMMY_SPHERE_RADIUS =  0.1; // idb
void *PhysicsObjHook::vftable = &_purecall; // weak
int (__thiscall *CShadowObj::vftable)(void *, char) = &CShadowObj::vector_deleting_destructor; // weak
int (__thiscall *CPhysicsObj::vftable[2])(void *, char) =
{
  &CPhysicsObj::scalar_deleting_destructor,
  &LongNIValHash<CPhysicsObj::CollisionRecord>::vector_deleting_destructor
}; // weak
int (__thiscall *LongNIValHash<CPhysicsObj::CollisionRecord>::vftable)(void *, char) = &LongNIValHash<CPhysicsObj::CollisionRecord>::vector_deleting_destructor; // weak
int (__thiscall *PositionPack::vftable)(void *, char) = &PositionPack::vector_deleting_destructor; // weak
int (__thiscall *MoveToStatePack::vftable)(void *, char) = &MoveToStatePack::vector_deleting_destructor; // weak
int (__thiscall *AutonomousPositionPack::vftable)(void *, char) = &Attribute2ndBase::vector_deleting_destructor; // weak
int (__thiscall *JumpPack::vftable)(void *, char) = &JumpPack::scalar_deleting_destructor; // weak
int (__thiscall *PhysicsTimestampPack::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
void *ParticleEmitterInfo::vftable = &ParticleEmitterInfo::vector_deleting_destructor; // weak
__int32 (__stdcall *ParticleEmitterInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *FPHook::vftable)(FPHook *this, struct CPhysicsObj *) = &FPHook::Execute; // weak
const float DEFAULT_FRICTION_0 =  0.94999999; // idb
const float DEFAULT_ELASTICITY_0 =  0.050000001; // idb
const float DEFAULT_TRANSLUCENCY_0 =  0.0; // idb
int (__thiscall *PhysicsDesc::vftable)(void *, char) = &PhysicsDesc::vector_deleting_destructor; // weak
void *GfxObjDegradeInfo::vftable = &GfxObjDegradeInfo::vector_deleting_destructor; // weak
__int32 (__stdcall *GfxObjDegradeInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const unsigned int command_ids[408] =
{
  2147483648u,
  2231369729u,
  2231369730u,
  1090519043u,
  1073741828u,
  1157627909u,
  1157627910u,
  1140850695u,
  1073741832u,
  1073741833u,
  1073741834u,
  1073741835u,
  1073741836u,
  1694498829u,
  1694498830u,
  1694498831u,
  1694498832u,
  1073741841u,
  1090519058u,
  1090519059u,
  1090519060u,
  1073741845u,
  1073741846u,
  1073741847u,
  1073741848u,
  1073741849u,
  1073741850u,
  1073741851u,
  1073741852u,
  1073741853u,
  1073741854u,
  1073741855u,
  1073741856u,
  1073741857u,
  1073741858u,
  1073741859u,
  1073741860u,
  1073741861u,
  1073741862u,
  1073741863u,
  1073741864u,
  1073741865u,
  1073741866u,
  1073741867u,
  1073741868u,
  1073741869u,
  1073741870u,
  1073741871u,
  1073741872u,
  1073741873u,
  1073741874u,
  1073741875u,
  1073741876u,
  1073741877u,
  1073741878u,
  1073741879u,
  1073741880u,
  1073741881u,
  536870970u,
  620757051u,
  2147483708u,
  2147483709u,
  2147483710u,
  2147483711u,
  2147483712u,
  2147483713u,
  2147483714u,
  2147483715u,
  2147483716u,
  2147483717u,
  2147483718u,
  2147483719u,
  2147483720u,
  2147483721u,
  268435530u,
  268435531u,
  318767180u,
  268435533u,
  268435534u,
  268435535u,
  268435536u,
  268435537u,
  268435538u,
  268435539u,
  268435540u,
  268435541u,
  268435542u,
  268435543u,
  268435544u,
  268435545u,
  268435546u,
  268435547u,
  268435548u,
  268435549u,
  268435550u,
  268435551u,
  268435552u,
  268435553u,
  268435554u,
  268435555u,
  268435556u,
  268435557u,
  268435558u,
  268435559u,
  268435560u,
  268435561u,
  268435562u,
  268435563u,
  268435564u,
  268435565u,
  268435566u,
  268435567u,
  268435568u,
  268435569u,
  268435570u,
  268435571u,
  268435572u,
  268435573u,
  268435574u,
  268435575u,
  268435576u,
  318767225u,
  318767226u,
  318767227u,
  318767228u,
  318767229u,
  318767230u,
  318767231u,
  318767232u,
  318767233u,
  318767234u,
  318767235u,
  318767236u,
  318767237u,
  318767238u,
  318767239u,
  318767240u,
  318767241u,
  318767242u,
  318767243u,
  318767244u,
  318767245u,
  318767246u,
  318767247u,
  318767248u,
  318767249u,
  318767250u,
  318767251u,
  318767252u,
  318767253u,
  318767254u,
  318767255u,
  318767256u,
  318767257u,
  318767258u,
  301990043u,
  268435612u,
  268435613u,
  268435614u,
  268435615u,
  268435616u,
  268435617u,
  134217890u,
  150995107u,
  150995108u,
  150995109u,
  150995110u,
  150995111u,
  150995112u,
  134217897u,
  150995114u,
  150995115u,
  150995116u,
  150995117u,
  150995118u,
  150995119u,
  150995120u,
  150995121u,
  218103986u,
  218103987u,
  218103988u,
  134217909u,
  134217910u,
  134217911u,
  150995128u,
  150995129u,
  218103994u,
  218103995u,
  218103996u,
  218103997u,
  218103998u,
  218103999u,
  150995136u,
  201326785u,
  150995138u,
  150995139u,
  150995140u,
  218104005u,
  150995142u,
  150995143u,
  150995144u,
  150995145u,
  318767306u,
  318767307u,
  318767308u,
  268435661u,
  268435662u,
  268435663u,
  268435664u,
  268435665u,
  268435666u,
  1073742035u,
  301990100u,
  150995157u,
  150995158u,
  150995159u,
  150995160u,
  150995161u,
  150995162u,
  150995163u,
  150995164u,
  150995165u,
  150995166u,
  301990111u,
  1073742048u,
  1073742049u,
  268435682u,
  268435683u,
  1073742052u,
  1073742053u,
  1073742054u,
  150995175u,
  2147483880u,
  2147483881u,
  1124073706u,
  1124073707u,
  1124073708u,
  1124073709u,
  1124073710u,
  1124073711u,
  1124073712u,
  1124073713u,
  1124073714u,
  1124073715u,
  1124073716u,
  1124073717u,
  1124073718u,
  1124073719u,
  1124073720u,
  1107296505u,
  1124073722u,
  1124073723u,
  1124073724u,
  1124073725u,
  150995198u,
  150995199u,
  150995200u,
  150995201u,
  150995202u,
  150995203u,
  150995204u,
  150995205u,
  150995206u,
  150995207u,
  150995208u,
  150995209u,
  150995210u,
  150995211u,
  150995212u,
  150995213u,
  268435726u,
  150995215u,
  150995216u,
  150995217u,
  150995218u,
  150995219u,
  150995220u,
  1124073749u,
  318767382u,
  1124073751u,
  1124073752u,
  1124073753u,
  150995226u,
  268435739u,
  268435740u,
  268435741u,
  268435742u,
  268435743u,
  268435744u,
  268435745u,
  268435746u,
  268435747u,
  268435748u,
  268435749u,
  268435750u,
  268435751u,
  268435752u,
  268435753u,
  268435754u,
  268435755u,
  268435756u,
  268435757u,
  268435758u,
  268435759u,
  268435760u,
  268435761u,
  318767410u,
  1073742131u,
  1073742132u,
  1073742133u,
  1073742134u,
  268435767u,
  2147483960u,
  2147483961u,
  1124073786u,
  1124073787u,
  1124073788u,
  1124073789u,
  1124073790u,
  1124073791u,
  1124073792u,
  1124073793u,
  1124073794u,
  1124073795u,
  1124073796u,
  1124073797u,
  1124073798u,
  318767431u,
  318767432u,
  318767433u,
  318767434u,
  318767435u,
  318767436u,
  318767437u,
  318767438u,
  318767439u,
  268435792u,
  150995281u,
  150995282u,
  150995283u,
  150995284u,
  150995285u,
  150995286u,
  150995287u,
  150995288u,
  150995289u,
  150995290u,
  150995291u,
  150995292u,
  150995293u,
  150995294u,
  150995295u,
  150995296u,
  150995297u,
  268435810u,
  268435811u,
  268435812u,
  150995301u,
  150995302u,
  150995303u,
  150995304u,
  150995305u,
  150995306u,
  150995307u,
  150995308u,
  150995309u,
  268435822u,
  268435823u,
  268435824u,
  268435825u,
  268435826u,
  268435827u,
  268435828u,
  268435829u,
  268435830u,
  268435831u,
  268435832u,
  268435833u,
  268435834u,
  268435835u,
  268435836u,
  268435837u,
  268435838u,
  268435839u,
  268435840u,
  268435841u,
  268435842u,
  268435843u,
  268435844u,
  268435845u,
  268435846u,
  268435847u,
  268435848u,
  268435849u,
  268435850u,
  268435851u,
  268435852u,
  268435853u,
  268435854u,
  268435855u,
  268435856u,
  268435857u,
  268435858u,
  268435859u,
  268435860u,
  268435861u,
  268435862u,
  268435863u
}; // idb
int (__thiscall *RawMotionState::vftable)(void *, char) = &RawMotionState::scalar_deleting_destructor; // weak
int (__thiscall *InterpretedMotionState::vftable)(void *, char) = &InterpretedMotionState::scalar_deleting_destructor; // weak
void *CAnimation::vftable = &CAnimation::vector_deleting_destructor; // weak
__int32 (__stdcall *CAnimation::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PlacementType::vftable[2])(void *, char) =
{
  &PlacementType::vector_deleting_destructor,
  &LongHash<LocationType>::scalar_deleting_destructor
}; // weak
int (__thiscall *LongHash<LocationType>::vftable)(void *, char) = &LongHash<LocationType>::scalar_deleting_destructor; // weak
void *CSetup::vftable = &CSetup::vector_deleting_destructor; // weak
__int32 (__stdcall *CSetup::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *PhysicsScript::vftable = &PhysicsScript::vector_deleting_destructor; // weak
__int32 (__stdcall *PhysicsScript::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,PhysicsScriptTableData *> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,PhysicsScriptTableData *,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,PhysicsScriptTableData *,0>::vftable)(void *, char) = &HashTable<unsigned long,PhysicsScriptTableData *,0>::scalar_deleting_destructor; // weak
void *PhysicsScriptTable::vftable = &PhysicsScriptTable::vector_deleting_destructor; // weak
__int32 (__stdcall *PhysicsScriptTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *MotionData::vftable = &MotionData::vector_deleting_destructor; // weak
int (__thiscall *MotionData::vftable)(void *, char) = &MotionData::vector_deleting_destructor; // weak
const unsigned int command_ids_0[408] =
{
  2147483648u,
  2231369729u,
  2231369730u,
  1090519043u,
  1073741828u,
  1157627909u,
  1157627910u,
  1140850695u,
  1073741832u,
  1073741833u,
  1073741834u,
  1073741835u,
  1073741836u,
  1694498829u,
  1694498830u,
  1694498831u,
  1694498832u,
  1073741841u,
  1090519058u,
  1090519059u,
  1090519060u,
  1073741845u,
  1073741846u,
  1073741847u,
  1073741848u,
  1073741849u,
  1073741850u,
  1073741851u,
  1073741852u,
  1073741853u,
  1073741854u,
  1073741855u,
  1073741856u,
  1073741857u,
  1073741858u,
  1073741859u,
  1073741860u,
  1073741861u,
  1073741862u,
  1073741863u,
  1073741864u,
  1073741865u,
  1073741866u,
  1073741867u,
  1073741868u,
  1073741869u,
  1073741870u,
  1073741871u,
  1073741872u,
  1073741873u,
  1073741874u,
  1073741875u,
  1073741876u,
  1073741877u,
  1073741878u,
  1073741879u,
  1073741880u,
  1073741881u,
  536870970u,
  620757051u,
  2147483708u,
  2147483709u,
  2147483710u,
  2147483711u,
  2147483712u,
  2147483713u,
  2147483714u,
  2147483715u,
  2147483716u,
  2147483717u,
  2147483718u,
  2147483719u,
  2147483720u,
  2147483721u,
  268435530u,
  268435531u,
  318767180u,
  268435533u,
  268435534u,
  268435535u,
  268435536u,
  268435537u,
  268435538u,
  268435539u,
  268435540u,
  268435541u,
  268435542u,
  268435543u,
  268435544u,
  268435545u,
  268435546u,
  268435547u,
  268435548u,
  268435549u,
  268435550u,
  268435551u,
  268435552u,
  268435553u,
  268435554u,
  268435555u,
  268435556u,
  268435557u,
  268435558u,
  268435559u,
  268435560u,
  268435561u,
  268435562u,
  268435563u,
  268435564u,
  268435565u,
  268435566u,
  268435567u,
  268435568u,
  268435569u,
  268435570u,
  268435571u,
  268435572u,
  268435573u,
  268435574u,
  268435575u,
  268435576u,
  318767225u,
  318767226u,
  318767227u,
  318767228u,
  318767229u,
  318767230u,
  318767231u,
  318767232u,
  318767233u,
  318767234u,
  318767235u,
  318767236u,
  318767237u,
  318767238u,
  318767239u,
  318767240u,
  318767241u,
  318767242u,
  318767243u,
  318767244u,
  318767245u,
  318767246u,
  318767247u,
  318767248u,
  318767249u,
  318767250u,
  318767251u,
  318767252u,
  318767253u,
  318767254u,
  318767255u,
  318767256u,
  318767257u,
  318767258u,
  301990043u,
  268435612u,
  268435613u,
  268435614u,
  268435615u,
  268435616u,
  268435617u,
  134217890u,
  150995107u,
  150995108u,
  150995109u,
  150995110u,
  150995111u,
  150995112u,
  134217897u,
  150995114u,
  150995115u,
  150995116u,
  150995117u,
  150995118u,
  150995119u,
  150995120u,
  150995121u,
  218103986u,
  218103987u,
  218103988u,
  134217909u,
  134217910u,
  134217911u,
  150995128u,
  150995129u,
  218103994u,
  218103995u,
  218103996u,
  218103997u,
  218103998u,
  218103999u,
  150995136u,
  201326785u,
  150995138u,
  150995139u,
  150995140u,
  218104005u,
  150995142u,
  150995143u,
  150995144u,
  150995145u,
  318767306u,
  318767307u,
  318767308u,
  268435661u,
  268435662u,
  268435663u,
  268435664u,
  268435665u,
  268435666u,
  1073742035u,
  301990100u,
  150995157u,
  150995158u,
  150995159u,
  150995160u,
  150995161u,
  150995162u,
  150995163u,
  150995164u,
  150995165u,
  150995166u,
  301990111u,
  1073742048u,
  1073742049u,
  268435682u,
  268435683u,
  1073742052u,
  1073742053u,
  1073742054u,
  150995175u,
  2147483880u,
  2147483881u,
  1124073706u,
  1124073707u,
  1124073708u,
  1124073709u,
  1124073710u,
  1124073711u,
  1124073712u,
  1124073713u,
  1124073714u,
  1124073715u,
  1124073716u,
  1124073717u,
  1124073718u,
  1124073719u,
  1124073720u,
  1107296505u,
  1124073722u,
  1124073723u,
  1124073724u,
  1124073725u,
  150995198u,
  150995199u,
  150995200u,
  150995201u,
  150995202u,
  150995203u,
  150995204u,
  150995205u,
  150995206u,
  150995207u,
  150995208u,
  150995209u,
  150995210u,
  150995211u,
  150995212u,
  150995213u,
  268435726u,
  150995215u,
  150995216u,
  150995217u,
  150995218u,
  150995219u,
  150995220u,
  1124073749u,
  318767382u,
  1124073751u,
  1124073752u,
  1124073753u,
  150995226u,
  268435739u,
  268435740u,
  268435741u,
  268435742u,
  268435743u,
  268435744u,
  268435745u,
  268435746u,
  268435747u,
  268435748u,
  268435749u,
  268435750u,
  268435751u,
  268435752u,
  268435753u,
  268435754u,
  268435755u,
  268435756u,
  268435757u,
  268435758u,
  268435759u,
  268435760u,
  268435761u,
  318767410u,
  1073742131u,
  1073742132u,
  1073742133u,
  1073742134u,
  268435767u,
  2147483960u,
  2147483961u,
  1124073786u,
  1124073787u,
  1124073788u,
  1124073789u,
  1124073790u,
  1124073791u,
  1124073792u,
  1124073793u,
  1124073794u,
  1124073795u,
  1124073796u,
  1124073797u,
  1124073798u,
  318767431u,
  318767432u,
  318767433u,
  318767434u,
  318767435u,
  318767436u,
  318767437u,
  318767438u,
  318767439u,
  268435792u,
  150995281u,
  150995282u,
  150995283u,
  150995284u,
  150995285u,
  150995286u,
  150995287u,
  150995288u,
  150995289u,
  150995290u,
  150995291u,
  150995292u,
  150995293u,
  150995294u,
  150995295u,
  150995296u,
  150995297u,
  268435810u,
  268435811u,
  268435812u,
  150995301u,
  150995302u,
  150995303u,
  150995304u,
  150995305u,
  150995306u,
  150995307u,
  150995308u,
  150995309u,
  268435822u,
  268435823u,
  268435824u,
  268435825u,
  268435826u,
  268435827u,
  268435828u,
  268435829u,
  268435830u,
  268435831u,
  268435832u,
  268435833u,
  268435834u,
  268435835u,
  268435836u,
  268435837u,
  268435838u,
  268435839u,
  268435840u,
  268435841u,
  268435842u,
  268435843u,
  268435844u,
  268435845u,
  268435846u,
  268435847u,
  268435848u,
  268435849u,
  268435850u,
  268435851u,
  268435852u,
  268435853u,
  268435854u,
  268435855u,
  268435856u,
  268435857u,
  268435858u,
  268435859u,
  268435860u,
  268435861u,
  268435862u,
  268435863u
}; // idb
int (__thiscall *MovementParameters::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *CAnimHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *CSequence::vftable)(void *, char) = &CSequence::scalar_deleting_destructor; // weak
int (__thiscall *AnimData::vftable)(void *, char) = &AnimData::vector_deleting_destructor; // weak
int (__thiscall *AnimSequenceNode::vftable)(void *, char) = &AnimSequenceNode::vector_deleting_destructor; // weak
int (__thiscall *NOOPHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *AttackHook::vftable)(void *, char) = &AttackHook::scalar_deleting_destructor; // weak
int (__thiscall *EtherealHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *NoDrawHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *DefaultScriptPartHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *DefaultScriptHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *TransparentHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *TransparentPartHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *LuminousPartHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *LuminousHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *DiffusePartHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *DiffuseHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *ScaleHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *DestroyParticleHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *StopParticleHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *TextureVelocityPartHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *TextureVelocityHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *SetLightHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *SoundHook::vftable)(void *, char) = &SoundHook::scalar_deleting_destructor; // weak
int (__thiscall *SoundTweakedHook::vftable)(void *, char) = &SoundTweakedHook::scalar_deleting_destructor; // weak
int (__thiscall *SoundTableHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *AnimPartChange::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ReplaceObjectHook::vftable)(void *, char) = &ReplaceObjectHook::scalar_deleting_destructor; // weak
int (__thiscall *CreateParticleHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *CreateBlockingParticleHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *CallPESHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
int (__thiscall *SetOmegaHook::vftable)(void *, char) = &SetOmegaHook::vector_deleting_destructor; // weak
void *CObjCell::vftable = &CObjCell::vector_deleting_destructor; // weak
__int32 (__stdcall *CObjCell::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *CObjCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32) = &CPartCell::add_part; // weak
int (__thiscall *LongNIValHash<GlobalVoyeurInfo>::vftable)(void *, char) = &LongNIValHash<GlobalVoyeurInfo>::vector_deleting_destructor; // weak
const int ptrue = 1; // idb
void (__thiscall *CEnvCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32) = &CPartCell::add_part; // weak
void *CEnvCell::vftable = &CEnvCell::vector_deleting_destructor; // weak
__int32 (__stdcall *CEnvCell::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,CEnvCell *> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,CEnvCell *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,CEnvCell *,0>::vftable)(void *, char) = &HashTable<unsigned long,CEnvCell *,0>::vector_deleting_destructor; // weak
void (__thiscall *CPartCell::vftable)(CPartCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32) = &CPartCell::add_part; // weak
void *CLandBlockInfo::vftable = &CLandBlockInfo::vector_deleting_destructor; // weak
__int32 (__stdcall *CLandBlockInfo::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<unsigned long,unsigned long>::vftable)(void *, char) = &PackableHashTable<unsigned long,unsigned long>::vector_deleting_destructor; // weak
void *CLandBlock::vftable = &CLandBlock::vector_deleting_destructor; // weak
__int32 (__stdcall *CLandBlock::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *CEnvironment::vftable = &CEnvironment::vector_deleting_destructor; // weak
__int32 (__stdcall *CEnvironment::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
SURFCHAR TERRAIN_SURF_CHAR[32] =
{
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  WATER,
  WATER,
  WATER,
  WATER,
  WATER,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID
}; // idb
const unsigned int SW_Corner[4] = { 0u, 3u, 2u, 1u }; // idb
const unsigned int SE_Corner[4] = { 1u, 0u, 3u, 2u }; // idb
const unsigned int NE_Corner[4] = { 2u, 1u, 0u, 3u }; // idb
const unsigned int NW_Corner[4] = { 3u, 2u, 1u, 0u }; // idb
SURFCHAR TERRAIN_SURF_CHAR_0[32] =
{
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  WATER,
  WATER,
  WATER,
  WATER,
  WATER,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID,
  SOLID
}; // idb
void (__thiscall *CLandCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts) = &CSortCell::add_part; // weak
void *CLandCell::vftable = &CLandCell::vector_deleting_destructor; // weak
__int32 (__stdcall *CLandCell::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *CSortCell::vftable)(CSortCell *this, CPhysicsPart *part, ClipPlaneList **planes, Frame *frame, unsigned __int32 num_shadow_parts) = &CSortCell::add_part; // weak
void *CSortCell::vftable = &CSortCell::vector_deleting_destructor; // weak
__int32 (__stdcall *CSortCell::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *CGfxObj::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
char byte_7C96BC[] = { '\x01' }; // weak
char byte_7C96BD[] = { '\x02' }; // weak
char byte_7C96C4[] = { '\0' }; // weak
void *CSurface::vftable = &CSurface::vector_deleting_destructor; // weak
__int32 (__stdcall *CSurface::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const float z_for_landing_0 =  0.0871557; // idb
int (__thiscall *DragDropInfo::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
const float z_for_landing_1 =  0.0871557; // idb
const float z_for_landing_2 =  0.0871557; // idb
int (__thiscall *BSPNODE::vftable)(void *, char) = &BSPNODE::vector_deleting_destructor; // weak
int (__thiscall *BSPLEAF::vftable)(void *, char) = &BSPLEAF::scalar_deleting_destructor; // weak
int (__thiscall *BSPPORTAL::vftable)(void *, char) = &BSPPORTAL::scalar_deleting_destructor; // weak
void *Palette::vftable = &Palette::vector_deleting_destructor; // weak
__int32 (__stdcall *Palette::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,ImgTex *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<ImgTex *,HashSetData<ImgTex *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<enum  PixelFormatID,HashTableData<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ImgTex *> *,0>::vector_deleting_destructor; // weak
void *ImgTex::vftable = &ImgTex::vector_deleting_destructor; // weak
__int32 (__stdcall *ImgTex::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *HashSet<ImgTex *>::vftable[5])(void *, char) =
{
  &HashSet<ImgTex *>::scalar_deleting_destructor,
  &HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,ImgTex *,0>::vector_deleting_destructor,
  &HashTable<unsigned __int64,ImgTex *,1>::vector_deleting_destructor,
  &PackObj::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable[4])(void *, char) =
{
  &HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,ImgTex *,0>::vector_deleting_destructor,
  &HashTable<unsigned __int64,ImgTex *,1>::vector_deleting_destructor,
  &PackObj::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,ImgTex *,0>::vftable[3])(void *, char) =
{
  &HashTable<unsigned long,ImgTex *,0>::vector_deleting_destructor,
  &HashTable<unsigned __int64,ImgTex *,1>::vector_deleting_destructor,
  &PackObj::scalar_deleting_destructor
}; // weak
int (__thiscall *AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable[2])(void *, char) =
{
  &HashTable<unsigned __int64,ImgTex *,1>::vector_deleting_destructor,
  &PackObj::scalar_deleting_destructor
}; // weak
int (__thiscall *StreamPackObj::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *NetAuthenticator::vftable)(void *, char) = &NetAuthenticator::scalar_deleting_destructor; // weak
int (__thiscall *PQueueArray<double,void *>::vftable)(void *, char) = &PQueueArray<double,void *>::scalar_deleting_destructor; // weak
unsigned __int64 (__thiscall *PacketController::vftable)(PacketController *__hidden this) = &PacketController::GetNonEphemeralID; // weak
int (__thiscall *List<PerfMonCounterInfo::PerfMonCounterNameHelp>::vftable[2])(void *, char) =
{
  &List<PerfMonCounterInfo::PerfMonCounterNameHelp>::scalar_deleting_destructor,
  &PerfMonCounter<unsigned __int64>::scalar_deleting_destructor
}; // weak
int (__thiscall *PerfMonCounter<unsigned __int64>::vftable)(void *, char) = &PerfMonCounter<unsigned __int64>::scalar_deleting_destructor; // weak
int (__thiscall *CClientsideLoginStateHandler::vftable)(void *, char) = &CClientsideLoginStateHandler::vector_deleting_destructor; // weak
int (__thiscall *AC1Legacy::PSRefBuffer<char>::vftable[2])(void *, char) =
{
  &AC1Legacy::PSRefBuffer<unsigned short>::scalar_deleting_destructor,
  &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor
}; // weak
int (__thiscall *CEchoResponseHeader::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
int (__thiscall *NetPacket::vftable[2])(void *, char) =
{
  &CNetLayerPacket::scalar_deleting_destructor,
  &CPackObjHeader<NetError,1048576,7>::vector_deleting_destructor
}; // weak
int (__thiscall *CPackObjHeader<NetError,1048576,7>::vftable)(void *, char) = &CPackObjHeader<NetError,1048576,7>::vector_deleting_destructor; // weak
void (__thiscall *SharedNet::vftable)(SharedNet *this, NetPerfCounter WhichCounter, int) = &SharedNet::AddToPerfCounter; // weak
int (__stdcall *ClientNet::vftable)(char) = &ClientNet::scalar_deleting_destructor; // weak
void (__thiscall *ClientNet::vftable)(ClientNet *this, NetPerfCounter WhichCounter, int) = &ClientNet::AddToPerfCounter; // weak
int (__thiscall *PQueueArray<unsigned long,void *>::vftable[2])(void *, char) =
{
  &PQueueArray<unsigned long,void *>::scalar_deleting_destructor,
  &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor
}; // weak
int (__thiscall *CTimeSyncHeader::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
int (__thiscall *CEchoRequestHeader::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,int> *,0>::vector_deleting_destructor,
  &CPackObjHeader<NetError,2097152,2>::scalar_deleting_destructor
}; // weak
int (__thiscall *CPackObjHeader<NetError,2097152,2>::vftable)(void *, char) = &CPackObjHeader<NetError,2097152,2>::scalar_deleting_destructor; // weak
int (__thiscall *COnePrimHeader<256,96,CServerSwitchStruct>::vftable)(void *, char) = &COnePrimHeader<524288,536870919,unsigned __int64>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,int,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,int,0>::vector_deleting_destructor,
  &FlowQueue::vector_deleting_destructor
}; // weak
int (__thiscall *FlowQueue::vftable)(void *, char) = &FlowQueue::vector_deleting_destructor; // weak
int (__thiscall *ClientFlowQueue::vftable)(void *, char) = &ClientFlowQueue::scalar_deleting_destructor; // weak
int (__thiscall *BlobFrag::vftable[2])(void *, char) =
{
  &BlobFrag::vector_deleting_destructor,
  &NetKeyExch::scalar_deleting_destructor
}; // weak
int (__thiscall *NetKeyExch::vftable)(void *, char) = &NetKeyExch::scalar_deleting_destructor; // weak
int (__thiscall *HashBaseData<unsigned __int64>::vftable)(void *, char) = &ArrivedEphInfo::scalar_deleting_destructor; // weak
void *NetBlob::vftable = &NetBlob::vector_deleting_destructor; // weak
void *NetBlob::vftable = &NetBlob::vector_deleting_destructor; // weak
int (__thiscall *NetBlob::vftable)(void *, char) = &NetBlob::vector_deleting_destructor; // weak
int (__thiscall *UI64Hash<NetBlob>::vftable[2])(void *, char) =
{
  &UI64Hash<NetBlob>::vector_deleting_destructor,
  &Indicator::vector_deleting_destructor
}; // weak
int (__thiscall *Indicator::vftable)(void *, char) = &Indicator::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,unsigned __int64> *,0>::vector_deleting_destructor,
  &HashTable<unsigned __int64,unsigned __int64,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned __int64,unsigned __int64,0>::vftable)(void *, char) = &HashTable<unsigned __int64,unsigned __int64,0>::vector_deleting_destructor; // weak
int (__thiscall *CFactory::vftable)(void *, char) = &CFactory::vector_deleting_destructor; // weak
const float IDEAL_OBJECT_SORT_DISTANCE =  25.0; // idb
const float IDEAL_PARTICLE_SORT_DISTANCE =  16.0; // idb
const unsigned int Render_LandscapeTextureDetail_Values[5] = { 4u, 3u, 2u, 1u, 0u }; // idb
const unsigned int Render_EnvironmentTextureDetail_Values[5] = { 4u, 3u, 2u, 1u, 0u }; // idb
const unsigned int Render_LandscapeDrawDistance_Values[6] = { 3u, 5u, 8u, 11u, 15u, 25u }; // idb
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::vftable)(void *, char) = &IntrusiveHashTable<IDClass<_tagDataID,32,0>,SoundBufRef *,0>::scalar_deleting_destructor; // weak
void (__thiscall *AmbientSound::vftable)(gmNoticeHandler *this) = &gmNoticeHandler::RecvNotice_PrevSpellSelection; // weak
void (__thiscall *IntermitSound::vftable)(IntermitSound *__hidden this) = &IntermitSound::ResetCount; // weak
void (__thiscall *ConstantSound::vftable)(ConstantSound *__hidden this) = &ConstantSound::ResetCount; // weak
void *DBWave::vftable = &DBWave::vector_deleting_destructor; // weak
__int32 (__stdcall *DBWave::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *DBWave::vftable = &DBWave::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,SoundTableData *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,SoundTableData *,0>::scalar_deleting_destructor,
  &SoundTableData::scalar_deleting_destructor
}; // weak
int (__thiscall *SoundTableData::vftable)(void *, char) = &SoundTableData::scalar_deleting_destructor; // weak
void *CSoundTable::vftable = &CSoundTable::vector_deleting_destructor; // weak
__int32 (__stdcall *CSoundTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *WaveFile::vftable)(void *, char) = &WaveFile::scalar_deleting_destructor; // weak
const float MAX_INTERPOLATED_VELOCITY =  7.5; // idb
const float BIG_DISTANCE =  999999.0; // idb
int (__stdcall *CCommunicationSystem::vftable)(AC1Legacy::PStringBase<char> accountName) = &CCommunicationSystem::StartupTurbineChat_Internal; // weak
int (__thiscall *AC1ClientChatManager::vftable)(void *, char) = &AC1ClientChatManager::vector_deleting_destructor; // weak
GUID _GUID_2933bf95_7b36_11d2_b20e_00c04f983e60 = { 691257237u, 31542u, 4562u, "≤\x0E¿Oò>`" };
GUID _GUID_00000000_0000_0000_c000_000000000046 = { 0u, 0u, 0u, "¿F" };
GUID _GUID_88d969c0_f192_11d4_a65f_0040963251e5 = { 2295949760u, 61842u, 4564u, "¶_@ñ2QÂ" };
Turbine_GUID stru_7CB8B8 = { 1244181156u, 45353u, 18515u, "ó∏\x13€Güv," }; // idb
Turbine_GUID CObjectMaint_Factory_ClassType_1 = { 396186599u, 3782u, 17588u, "•HH§–Ä1" }; // idb
Turbine_GUID stru_7CBA98 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *ACCFactory::vftable)(void *, char) = &CFactory::vector_deleting_destructor; // weak
__int32 (__stdcall *ClassFactoryPlugin<ClientObjMaintSystem>::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID CObjectMaint_InterfaceType_79 = { 4194796813u, 53636u, 18433u, "á¿AígÑ´\v" }; // idb
Turbine_GUID ClientSystem_InterfaceType_78 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientObjMaintSystem_InterfaceType_68 = { 1609975359u, 15348u, 19208u, "∞A…XÇ\bæ\x1A" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType_1 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
Turbine_GUID stru_7CBCD0 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ACCObjectMaint::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
bool (__thiscall *CObjectMaint::vftable)(DBObj *this) = &DBObj::InitLoad; // weak
__int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *ClientObjMaintSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
__int32 (__stdcall *ClientSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *ACSmartBox::vftable)(void *, char) = &SmartBox::scalar_deleting_destructor; // weak
__int32 (__stdcall *APIManager::IAsheronsCallImpl::vftable)(APIManager::IAsheronsCallImpl *this, _GUID *riid, void **ppvObject) = &APIManager::IAsheronsCallImpl::QueryInterface; // weak
Turbine_GUID IQueuedUIEventDeliverer_InterfaceType_61 = { 311239165u, 36159u, 19530u, "Ä_û‰U\x15\x1FN" }; // idb
Turbine_GUID CObjectMaint_ClassType_1 = { 2458606552u, 10574u, 17473u, "ôç◊¬\x04|Øâ" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType_2 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
Turbine_GUID UIQueueManager_InterfaceType_52 = { 3911729874u, 10161u, 18342u, "û\x18ÌMIõÌ=" }; // idb
Turbine_GUID stru_7CC3D0 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *WOrderHdr::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<ContentProfile>::vftable)(void *, char) = &PackableList<ContentProfile>::vector_deleting_destructor; // weak
int (__thiscall *ContentProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PageData::vftable)(void *, char) = &PageData::scalar_deleting_destructor; // weak
__int32 (__stdcall *UIQueueManager::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_81 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID CPlayerModule_ClassType_5 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
Turbine_GUID PlayerDesc_ClassType_26 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID CPlayerSystem_InterfaceType_78 = { 3410493918u, 53250u, 18520u, "πøæAl©≠Ù" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType_3 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
const float RADAR_OUTDOOR_RADIUS_1 =  75.0; // idb
const float RADAR_INDOOR_RADIUS =  25.0; // idb
Turbine_GUID stru_7CC6B4 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *PackableList<InventoryPlacement>::vftable)(void *, char) = &PackableList<InventoryPlacement>::scalar_deleting_destructor; // weak
int (__thiscall *List<ObjectRangeInfo>::vftable)(void *, char) = &List<ObjectRangeInfo>::vector_deleting_destructor; // weak
int (__thiscall *CContractTrackerTable::vftable)(void *, char) = &CContractTrackerTable::vector_deleting_destructor; // weak
void (__thiscall *CPlayerSystem::vftable)(CPlayerSystem *this, unsigned __int32) = &CPlayerSystem::OnObjectRangeExit; // weak
void (__thiscall *CPlayerSystem::vftable[2])(CPlayerSystem *this, CWeenieObject *cwobj, StatType stype, unsigned __int32) = { &CPlayerSystem::OnQualityRemoved, &CPlayerSystem::OnQualityRemoved }; // weak
int (__stdcall *CPlayerSystem::vftable)(char) = &CPlayerSystem::scalar_deleting_destructor; // weak
bool (__thiscall *CPlayerSystem::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
__int32 (__stdcall *CPlayerSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *ClientCharGenState::vftable)(ClientCharGenState *__hidden this) = &ClientCharGenState::UpdateTrueFacePal; // weak
Turbine_GUID PlayerDesc_ClassType_27 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID ClientSystem_InterfaceType_83 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType_4 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
Turbine_GUID ClientUISystem_InterfaceType_55 = { 733782278u, 25770u, 17785u, "§©≈¬´Üüø" }; // idb
Turbine_GUID stru_7CDB58 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__stdcall *ClientUISystem::vftable)(char) = &ClientUISystem::scalar_deleting_destructor; // weak
bool (__thiscall *ClientUISystem::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
__int32 (__stdcall *ClientUISystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_84 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientMagicSystem_InterfaceType_58 = { 2759382443u, 15093u, 19181u, "£w<ddìëÃ" }; // idb
Turbine_GUID PlayerDesc_ClassType_28 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID stru_7CE758 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,Graphic *> *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vftable)(void *, char) = &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,Graphic *> *,1>::vector_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,Graphic *,1>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,Graphic *,1>::vector_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vftable)(void *, char) = &HashTable<IDClass<_tagDataID,32,0>,Graphic *,1>::vector_deleting_destructor; // weak
__int32 (__stdcall *ClientMagicSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_85 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientFellowshipSystem_InterfaceType_57 = { 1663730255u, 16884u, 17008u, "†PÈåxﬂsV" }; // idb
Turbine_GUID stru_7CEC00 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ClientFellowshipSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<unsigned long,long>::vftable)(void *, char) = &PackableHashTable<unsigned long,long>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,Fellow>::vftable)(void *, char) = &PackableHashTable<unsigned long,Fellow>::scalar_deleting_destructor; // weak
int (__thiscall *CFellowship::vftable)(void *, char) = &CFellowship::vector_deleting_destructor; // weak
Turbine_GUID ClientSystem_InterfaceType_86 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientAllegianceSystem_InterfaceType_58 = { 1842945150u, 22472u, 17978u, "ÖÓ∆v2Î*x" }; // idb
Turbine_GUID stru_7CEE48 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ClientAllegianceSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_87 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientCombatSystem_InterfaceType_60 = { 2188753425u, 41192u, 19756u, "¶õΩÂkç]\x13" }; // idb
Turbine_GUID PlayerDesc_ClassType_29 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
const float MIN_JUMP_EXTENT =  0.001; // idb
Turbine_GUID stru_7CF1C8 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
void (__thiscall *ClientCombatSystem::vftable)(ClientCombatSystem *this, CWeenieObject *cwobj, enum StatType mode, unsigned __int32) = &ClientCombatSystem::OnQualityChanged; // weak
int (__stdcall *ClientCombatSystem::vftable)(char) = &ClientCombatSystem::vector_deleting_destructor; // weak
bool (__thiscall *ClientCombatSystem::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
__int32 (__stdcall *ClientCombatSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_88 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientTradeSystem_InterfaceType_60 = { 3923857602u, 61176u, 17887u, "≤6<C7Õˇ¢" }; // idb
Turbine_GUID ClientObjMaintSystem_ClassType_5 = { 3986246646u, 58538u, 17282u, "™\x11\x17˛\x11pjÔ" }; // idb
Turbine_GUID stru_7CFCD8 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ClientTradeSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_89 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID PlayerDesc_ClassType_30 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID ClientCommunicationSystem_InterfaceType_63 = { 4171407636u, 14226u, 18463u, "å.Âx®:èã" }; // idb
Turbine_GUID stru_7D0008 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vftable)(void *, char) = &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,ClientCommunicationSystem::CmdHashData *,1>::vector_deleting_destructor; // weak
void (__thiscall *ClientCommunicationSystem::vftable)(ClientCommunicationSystem *this, CWeenieObject *cwobj, enum StatType bAFK, unsigned __int32) = &ClientCommunicationSystem::OnQualityChanged; // weak
bool (__thiscall *ClientCommunicationSystem::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
__int32 (__stdcall *ClientCommunicationSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_90 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientMiniGameSystem_InterfaceType_62 = { 469858046u, 61836u, 19916u, "ë\x02>*Ñ\x03\a" }; // idb
Turbine_GUID stru_7E1B00 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ClientMiniGameSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
Turbine_GUID ClientSystem_InterfaceType_91 = { 3122473047u, 40502u, 16476u, "ãPÍ@Í¬jç" }; // idb
Turbine_GUID ClientHousingSystem_InterfaceType_63 = { 1988481844u, 45165u, 17197u, "≤˙πÙ\x01ß◊U" }; // idb
Turbine_GUID stru_7E1D10 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *ClientHousingSystem::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0>> *,1>::scalar_deleting_destructor,
  &HashSet<IDClass<_tagDataID,32,0>>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashSet<IDClass<_tagDataID,32,0>>::vftable)(void *, char) = &HashSet<IDClass<_tagDataID,32,0>>::scalar_deleting_destructor; // weak
int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
int (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
__int32 (__stdcall *CCommunicationSystem::ChatInterfaceProvider::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
int (__thiscall *PackableHashIterator<unsigned long,SquelchInfo>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,SquelchInfo>::scalar_deleting_destructor,
  &SquelchInfo::vector_deleting_destructor
}; // weak
int (__thiscall *SquelchInfo::vftable)(void *, char) = &SquelchInfo::vector_deleting_destructor; // weak
int (__thiscall *gmCCommunicationSystem::vftable)(AC1Legacy::PStringBase<char> accountName, AC1Legacy::PStringBase<char> accountName) = &gmCCommunicationSystem::StartupTurbineChat_Internal; // weak
int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(int) = &RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vector_deleting_destructor; // weak
int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
int (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, int, int) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
__int32 (__stdcall *RefCountIUnknown<gmCCommunicationSystem::uiChatInterfaceProvider>::vftable)(CCommunicationSystem::ChatInterfaceProvider *this, _GUID *riid, void **ppvObject) = &CCommunicationSystem::ChatInterfaceProvider::QueryInterface; // weak
GUID IID_IAsheronsCall = { 2448402605u, 46937u, 16866u, "•\x18‰¯Œ\x12»T" };
void *gmCLCache::vftable = &gmCLCache::vector_deleting_destructor; // weak
__int32 (__stdcall *gmCLCache::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
bool (__thiscall *gmMasterDBMap::vftable)(gmMasterDBMap *__hidden this) = &gmMasterDBMap::InitDBTypeDef_Internal; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0>::scalar_deleting_destructor,
  &Render::vector_deleting_destructor
}; // weak
int (__thiscall *Render::vftable)(void *, char) = &Render::vector_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,RenderVertexStreamD3D *,0>::vftable)(void *, char) = &HashTable<unsigned long,RenderVertexStreamD3D *,0>::scalar_deleting_destructor; // weak
int (__thiscall *D3DPolyRender::vftable)(void *, char) = &D3DPolyRender::scalar_deleting_destructor; // weak
RenderVertexStreamD3D *Motion_Ready = (RenderVertexStreamD3D *)0x41000003; // idb
RenderVertexStreamD3D *Motion_Crouch = (RenderVertexStreamD3D *)0x41000012; // idb
RenderVertexStreamD3D *Motion_Sitting = (RenderVertexStreamD3D *)0x41000013; // idb
RenderVertexStreamD3D *Motion_Sleeping = (RenderVertexStreamD3D *)0x41000014; // idb
RenderVertexStreamD3D *Motion_Cheer = (RenderVertexStreamD3D *)0x1300004C; // idb
RenderVertexStreamD3D *Motion_ShakeFist = (RenderVertexStreamD3D *)0x13000079; // idb
RenderVertexStreamD3D *Motion_Beckon = (RenderVertexStreamD3D *)0x1300007A; // idb
RenderVertexStreamD3D *Motion_BeSeeingYou = (RenderVertexStreamD3D *)0x1300007B; // idb
RenderVertexStreamD3D *Motion_BlowKiss = (RenderVertexStreamD3D *)0x1300007C; // idb
RenderVertexStreamD3D *Motion_BowDeep = (RenderVertexStreamD3D *)0x1300007D; // idb
RenderVertexStreamD3D *Motion_ClapHands = (RenderVertexStreamD3D *)0x1300007E; // idb
RenderVertexStreamD3D *Motion_Cry = (RenderVertexStreamD3D *)0x1300007F; // idb
RenderVertexStreamD3D *Motion_Laugh = (RenderVertexStreamD3D *)0x13000080; // idb
RenderVertexStreamD3D *Motion_MimeEat = (RenderVertexStreamD3D *)0x13000081; // idb
RenderVertexStreamD3D *Motion_MimeDrink = (RenderVertexStreamD3D *)0x13000082; // idb
RenderVertexStreamD3D *Motion_Nod = (RenderVertexStreamD3D *)0x13000083; // idb
RenderVertexStreamD3D *Motion_Point = (RenderVertexStreamD3D *)0x13000084; // idb
RenderVertexStreamD3D *Motion_ShakeHead = (RenderVertexStreamD3D *)0x13000085; // idb
RenderVertexStreamD3D *Motion_Shrug = (RenderVertexStreamD3D *)0x13000086; // idb
RenderVertexStreamD3D *Motion_Wave = (RenderVertexStreamD3D *)0x13000087; // idb
RenderVertexStreamD3D *Motion_Akimbo = (RenderVertexStreamD3D *)0x13000088; // idb
RenderVertexStreamD3D *Motion_HeartyLaugh = (RenderVertexStreamD3D *)0x13000089; // idb
RenderVertexStreamD3D *Motion_Salute = (RenderVertexStreamD3D *)0x1300008A; // idb
RenderVertexStreamD3D *Motion_ScratchHead = (RenderVertexStreamD3D *)0x1300008B; // idb
RenderVertexStreamD3D *Motion_SmackHead = (RenderVertexStreamD3D *)0x1300008C; // idb
RenderVertexStreamD3D *Motion_TapFoot = (RenderVertexStreamD3D *)0x1300008D; // idb
RenderVertexStreamD3D *Motion_WaveHigh = (RenderVertexStreamD3D *)0x1300008E; // idb
RenderVertexStreamD3D *Motion_WaveLow = (RenderVertexStreamD3D *)0x1300008F; // idb
RenderVertexStreamD3D *Motion_YawnStretch = (RenderVertexStreamD3D *)0x13000090; // idb
RenderVertexStreamD3D *Motion_Cringe = (RenderVertexStreamD3D *)0x13000091; // idb
RenderVertexStreamD3D *Motion_Kneel = (RenderVertexStreamD3D *)0x13000092; // idb
RenderVertexStreamD3D *Motion_Plead = (RenderVertexStreamD3D *)0x13000093; // idb
RenderVertexStreamD3D *Motion_Shiver = (RenderVertexStreamD3D *)0x13000094; // idb
RenderVertexStreamD3D *Motion_Shoo = (RenderVertexStreamD3D *)0x13000095; // idb
RenderVertexStreamD3D *Motion_Slouch = (RenderVertexStreamD3D *)0x13000096; // idb
RenderVertexStreamD3D *Motion_Spit = (RenderVertexStreamD3D *)0x13000097; // idb
RenderVertexStreamD3D *Motion_Surrender = (RenderVertexStreamD3D *)0x13000098; // idb
RenderVertexStreamD3D *Motion_Woah = (RenderVertexStreamD3D *)0x13000099; // idb
RenderVertexStreamD3D *Motion_Winded = (RenderVertexStreamD3D *)0x1300009A; // idb
RenderVertexStreamD3D *Motion_YMCA = (RenderVertexStreamD3D *)0x1200009B; // idb
RenderVertexStreamD3D *Motion_Pray = (RenderVertexStreamD3D *)0x130000CA; // idb
RenderVertexStreamD3D *Motion_Mock = (RenderVertexStreamD3D *)0x130000CB; // idb
RenderVertexStreamD3D *Motion_Teapot = (RenderVertexStreamD3D *)0x130000CC; // idb
RenderVertexStreamD3D *Motion_ShakeFistState = (RenderVertexStreamD3D *)0x430000EA; // idb
RenderVertexStreamD3D *Motion_PrayState = (RenderVertexStreamD3D *)0x430000EB; // idb
RenderVertexStreamD3D *Motion_BowDeepState = (RenderVertexStreamD3D *)0x430000EC; // idb
RenderVertexStreamD3D *Motion_ClapHandsState = (RenderVertexStreamD3D *)0x430000ED; // idb
RenderVertexStreamD3D *Motion_CrossArmsState = (RenderVertexStreamD3D *)0x430000EE; // idb
RenderVertexStreamD3D *Motion_ShiverState = (RenderVertexStreamD3D *)0x430000EF; // idb
RenderVertexStreamD3D *Motion_PointState = (RenderVertexStreamD3D *)0x430000F0; // idb
RenderVertexStreamD3D *Motion_WaveState = (RenderVertexStreamD3D *)0x430000F1; // idb
RenderVertexStreamD3D *Motion_AkimboState = (RenderVertexStreamD3D *)0x430000F2; // idb
RenderVertexStreamD3D *Motion_SaluteState = (RenderVertexStreamD3D *)0x430000F3; // idb
RenderVertexStreamD3D *Motion_ScratchHeadState = (RenderVertexStreamD3D *)0x430000F4; // idb
RenderVertexStreamD3D *Motion_TapFootState = (RenderVertexStreamD3D *)0x430000F5; // idb
RenderVertexStreamD3D *Motion_LeanState = (RenderVertexStreamD3D *)0x430000F6; // idb
RenderVertexStreamD3D *Motion_KneelState = (RenderVertexStreamD3D *)0x430000F7; // idb
RenderVertexStreamD3D *Motion_PleadState = (RenderVertexStreamD3D *)0x430000F8; // idb
RenderVertexStreamD3D *Motion_ATOYOT = (RenderVertexStreamD3D *)0x420000F9; // idb
RenderVertexStreamD3D *Motion_SlouchState = (RenderVertexStreamD3D *)0x430000FA; // idb
RenderVertexStreamD3D *Motion_SurrenderState = (RenderVertexStreamD3D *)0x430000FB; // idb
RenderVertexStreamD3D *Motion_WoahState = (RenderVertexStreamD3D *)0x430000FC; // idb
RenderVertexStreamD3D *Motion_WindedState = (RenderVertexStreamD3D *)0x430000FD; // idb
RenderVertexStreamD3D *Motion_SnowAngelState = (RenderVertexStreamD3D *)0x43000115; // idb
RenderVertexStreamD3D *Motion_WarmHands = (RenderVertexStreamD3D *)0x13000116; // idb
RenderVertexStreamD3D *Motion_CurtseyState = (RenderVertexStreamD3D *)0x43000117; // idb
RenderVertexStreamD3D *Motion_AFKState = (RenderVertexStreamD3D *)0x43000118; // idb
RenderVertexStreamD3D *Motion_MeditateState = (RenderVertexStreamD3D *)0x43000119; // idb
RenderVertexStreamD3D *Motion_Helper = (RenderVertexStreamD3D *)0x13000132; // idb
RenderVertexStreamD3D *Motion_SitState = (RenderVertexStreamD3D *)0x4300013A; // idb
RenderVertexStreamD3D *Motion_SitCrossleggedState = (RenderVertexStreamD3D *)0x4300013B; // idb
RenderVertexStreamD3D *Motion_SitBackState = (RenderVertexStreamD3D *)0x4300013C; // idb
RenderVertexStreamD3D *Motion_PointLeftState = (RenderVertexStreamD3D *)0x4300013D; // idb
RenderVertexStreamD3D *Motion_PointRightState = (RenderVertexStreamD3D *)0x4300013E; // idb
RenderVertexStreamD3D *Motion_TalktotheHandState = (RenderVertexStreamD3D *)0x4300013F; // idb
RenderVertexStreamD3D *Motion_PointDownState = (RenderVertexStreamD3D *)0x43000140; // idb
RenderVertexStreamD3D *Motion_DrudgeDanceState = (RenderVertexStreamD3D *)0x43000141; // idb
RenderVertexStreamD3D *Motion_PossumState = (RenderVertexStreamD3D *)0x43000142; // idb
RenderVertexStreamD3D *Motion_ReadState = (RenderVertexStreamD3D *)0x43000143; // idb
RenderVertexStreamD3D *Motion_ThinkerState = (RenderVertexStreamD3D *)0x43000144; // idb
RenderVertexStreamD3D *Motion_HaveASeatState = (RenderVertexStreamD3D *)0x43000145; // idb
RenderVertexStreamD3D *Motion_AtEaseState = (RenderVertexStreamD3D *)0x43000146; // idb
RenderVertexStreamD3D *Motion_NudgeLeft = (RenderVertexStreamD3D *)0x13000147; // idb
RenderVertexStreamD3D *Motion_NudgeRight = (RenderVertexStreamD3D *)0x13000148; // idb
RenderVertexStreamD3D *Motion_PointLeft = (RenderVertexStreamD3D *)0x13000149; // idb
RenderVertexStreamD3D *Motion_PointRight = (RenderVertexStreamD3D *)0x1300014A; // idb
RenderVertexStreamD3D *Motion_PointDown = (RenderVertexStreamD3D *)0x1300014B; // idb
RenderVertexStreamD3D *Motion_Knock = (RenderVertexStreamD3D *)0x1300014C; // idb
RenderVertexStreamD3D *Motion_ScanHorizon = (RenderVertexStreamD3D *)0x1300014D; // idb
RenderVertexStreamD3D *Motion_DrudgeDance = (RenderVertexStreamD3D *)0x1300014E; // idb
RenderVertexStreamD3D *Motion_HaveASeat = (RenderVertexStreamD3D *)0x1300014F; // idb
const unsigned int Ready = 268435604u; // idb
const unsigned int Crouch = 268435605u; // idb
const unsigned int Sitting = 268435606u; // idb
const unsigned int Sleeping = 268435607u; // idb
const unsigned int AFKState = 268435608u; // idb
const unsigned int Akimbo = 268435609u; // idb
const unsigned int ATOYOT = 268435610u; // idb
const unsigned int AkimboState = 268435611u; // idb
const unsigned int AtEaseState = 268435612u; // idb
const unsigned int Beckon = 268435613u; // idb
const unsigned int BeSeeingYou = 268435614u; // idb
const unsigned int BlowKiss = 268435615u; // idb
const unsigned int BowDeep = 268435616u; // idb
const unsigned int BowDeepState = 268435617u; // idb
const unsigned int Cheer = 268435618u; // idb
const unsigned int ClapHands = 268435619u; // idb
const unsigned int ClapHandsState = 268435620u; // idb
const unsigned int Cringe = 268435621u; // idb
const unsigned int CrossArmsState = 268435622u; // idb
const unsigned int Cry = 268435623u; // idb
const unsigned int CurtseyState = 268435624u; // idb
const unsigned int DrudgeDance = 268435625u; // idb
const unsigned int DrudgeDanceState = 268435626u; // idb
const unsigned int HaveASeat = 268435627u; // idb
const unsigned int HaveASeatState = 268435628u; // idb
const unsigned int HeartyLaugh = 268435629u; // idb
const unsigned int Helper = 268435630u; // idb
const unsigned int Kneel = 268435631u; // idb
const unsigned int KneelState = 268435632u; // idb
const unsigned int Knock = 268435633u; // idb
const unsigned int Laugh = 268435634u; // idb
const unsigned int LeanState = 268435635u; // idb
const unsigned int MeditateState = 268435636u; // idb
const unsigned int MimeDrink = 268435637u; // idb
const unsigned int MimeEat = 268435638u; // idb
const unsigned int Mock = 268435639u; // idb
const unsigned int Nod = 268435640u; // idb
const unsigned int NudgeLeft = 268435641u; // idb
const unsigned int NudgeRight = 268435642u; // idb
const unsigned int Plead = 268435643u; // idb
const unsigned int PleadState = 268435644u; // idb
const unsigned int Point = 268435645u; // idb
const unsigned int PointState = 268435646u; // idb
const unsigned int PointDown = 268435647u; // idb
const unsigned int PointDownState = 268435648u; // idb
const unsigned int PointLeft = 268435649u; // idb
const unsigned int PointLeftState = 268435650u; // idb
const unsigned int PointRight = 268435651u; // idb
const unsigned int PointRightState = 268435652u; // idb
const unsigned int PossumState = 268435653u; // idb
const unsigned int Pray = 268435654u; // idb
const unsigned int PrayState = 268435655u; // idb
const unsigned int ReadState = 268435656u; // idb
const unsigned int Salute = 268435657u; // idb
const unsigned int SaluteState = 268435658u; // idb
const unsigned int ScanHorizon = 268435659u; // idb
const unsigned int ScratchHead = 268435660u; // idb
const unsigned int ScratchHeadState = 268435661u; // idb
const unsigned int ShakeFist = 268435662u; // idb
const unsigned int ShakeFistState = 268435663u; // idb
const unsigned int ShakeHead = 268435664u; // idb
const unsigned int Shiver = 268435665u; // idb
const unsigned int ShiverState = 268435666u; // idb
const unsigned int Shoo = 268435667u; // idb
const unsigned int Shrug = 268435668u; // idb
const unsigned int SitState = 268435669u; // idb
const unsigned int SitBackState = 268435670u; // idb
const unsigned int SitCrossleggedState = 268435671u; // idb
const unsigned int Slouch = 268435672u; // idb
const unsigned int SlouchState = 268435673u; // idb
const unsigned int SmackHead = 268435674u; // idb
const unsigned int SnowAngelState = 268435675u; // idb
const unsigned int Spit = 268435676u; // idb
const unsigned int Surrender = 268435677u; // idb
const unsigned int SurrenderState = 268435678u; // idb
const unsigned int TalktotheHandState = 268435679u; // idb
const unsigned int TapFoot = 268435680u; // idb
const unsigned int TapFootState = 268435681u; // idb
const unsigned int Teapot = 268435682u; // idb
const unsigned int ThinkerState = 268435683u; // idb
const unsigned int WarmHands = 268435684u; // idb
const unsigned int Wave = 268435685u; // idb
const unsigned int WaveState = 268435686u; // idb
const unsigned int WaveLow = 268435687u; // idb
const unsigned int WaveHigh = 268435688u; // idb
const unsigned int Winded = 268435689u; // idb
const unsigned int WindedState = 268435690u; // idb
const unsigned int Woah = 268435691u; // idb
const unsigned int WoahState = 268435692u; // idb
const unsigned int YawnStretch = 268435693u; // idb
const unsigned int YMCA = 268435694u; // idb
bool (__thiscall *ACCmdInterp::vftable)(DBCache *this) = &DBCache::IsLoader; // weak
int (__thiscall *ACCmdInterp::vftable)(void *, char) = &ACCmdInterp::vector_deleting_destructor; // weak
Turbine_GUID CPlayerModule_ClassType_6 = { 3128500390u, 33844u, 18824u, "ù\n¸ø\te´£" }; // idb
void *CWeenieObject::vftable = &CWeenieObject::vector_deleting_destructor; // weak
int (__thiscall *CWeenieObject::vftable)(void *, char) = &CWeenieObject::scalar_deleting_destructor; // weak
void *ACCWeenieObject::vftable = &ACCWeenieObject::vector_deleting_destructor; // weak
int (__thiscall *ACCWeenieObject::vftable)(void *, char) = &ACCWeenieObject::scalar_deleting_destructor; // weak
int (__thiscall *IconData::vftable)(void *, char) = &IconData::scalar_deleting_destructor; // weak
int (__thiscall *ArmorCache::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *BodyPart::vftable)(void *, char) = &BodyPart::vector_deleting_destructor; // weak
int (__thiscall *SpellBookPage::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<long,BodyPart>::vftable)(void *, char) = &PackableHashTable<long,BodyPart>::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<CreationProfile>::vftable)(void *, char) = &PackableList<CreationProfile>::scalar_deleting_destructor; // weak
int (__thiscall *Body::vftable)(void *, char) = &Body::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,__int64>::vftable)(void *, char) = &PackableHashTable<unsigned long,__int64>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,int>::vftable)(void *, char) = &PackableHashTable<unsigned long,int>::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,double>::vftable)(void *, char) = &PackableHashTable<unsigned long,double>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vftable)(void *, char) = &PackableHashTable<unsigned long,IDClass<_tagDataID,32,0>>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::vftable)(void *, char) = &PackableHashTable<unsigned long,AC1Legacy::PStringBase<char>>::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,Position>::vftable)(void *, char) = &PackableHashTable<unsigned long,Position>::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,Skill>::vftable)(void *, char) = &PackableHashTable<unsigned long,Skill>::vector_deleting_destructor; // weak
Turbine_GUID stru_7E451C = { 59337336u, 41374u, 19810u, "Ç]\x02±z,7+" }; // idb
Turbine_GUID PlayerDesc_ClassType_31 = { 3633350567u, 12392u, 18229u, "™í3}&¨Y≥" }; // idb
Turbine_GUID stru_7E453C = { 3735928559u, 0u, 0u, "´Õ" }; // idb
__int32 (__stdcall *CACQualities::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *PlayerDesc::vftable = &CACQualities::vector_deleting_destructor; // weak
void *PlayerDesc::vftable = &PlayerDesc::vector_deleting_destructor; // weak
__int32 (__stdcall *PlayerDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CEnchantmentRegistry::vftable)(void *, char) = &CEnchantmentRegistry::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,PackableList<EmoteSet>>::vftable)(void *, char) = &PackableHashTable<unsigned long,PackableList<EmoteSet>>::vector_deleting_destructor; // weak
int (__thiscall *PackableList<EmoteSet>::vftable)(void *, char) = &PackableList<EmoteSet>::vector_deleting_destructor; // weak
int (__thiscall *CEmoteTable::vftable)(void *, char) = &CEmoteTable::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,SpellBookPage>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,SpellBookPage>::scalar_deleting_destructor,
  &PackableHashTable<unsigned long,SpellBookPage>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,SpellBookPage>::vftable)(void *, char) = &PackableHashTable<unsigned long,SpellBookPage>::vector_deleting_destructor; // weak
int (__thiscall *CSpellBook::vftable)(void *, char) = &CSpellBook::scalar_deleting_destructor; // weak
void *CBaseQualities::vftable = &_purecall; // weak
int (__thiscall *PackableList<Emote>::vftable)(void *, char) = &PackableList<Emote>::scalar_deleting_destructor; // weak
int (__thiscall *EmoteSet::vftable)(void *, char) = &EmoteSet::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,CSpellBase>::vftable[3])(void *, char) =
{
  &PackableHashIterator<unsigned long,CSpellBase>::scalar_deleting_destructor,
  &AC1Legacy::List<SpellSetTierList>::vector_deleting_destructor,
  &PackableHashTable<unsigned long,CSpellBase>::vector_deleting_destructor
}; // weak
int (__thiscall *AC1Legacy::List<SpellSetTierList>::vftable[2])(void *, char) =
{
  &AC1Legacy::List<SpellSetTierList>::vector_deleting_destructor,
  &PackableHashTable<unsigned long,CSpellBase>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,CSpellBase>::vftable)(void *, char) = &PackableHashTable<unsigned long,CSpellBase>::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,SpellSet> *,0>::vector_deleting_destructor,
  &SpellSetTierList::scalar_deleting_destructor
}; // weak
int (__thiscall *SpellSetTierList::vftable)(void *, char) = &SpellSetTierList::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,SpellSet,0>::vftable)(void *, char) = &HashTable<unsigned long,SpellSet,0>::vector_deleting_destructor; // weak
void *PList<SpellSetTierList>::vftable = &PList<SpellSetTierList>::vector_deleting_destructor; // weak
int (__thiscall *PList<SpellSetTierList>::vftable[2])(void *, char) =
{
  &PList<SpellSetTierList>::vector_deleting_destructor,
  &SpellSet::scalar_deleting_destructor
}; // weak
int (__thiscall *SpellSet::vftable)(void *, char) = &SpellSet::scalar_deleting_destructor; // weak
void *PHashTable<unsigned long,SpellSet>::vftable = &PHashTable<unsigned long,SpellSet>::vector_deleting_destructor; // weak
int (__thiscall *PHashTable<unsigned long,SpellSet>::vftable)(void *, char) = &PHashTable<unsigned long,SpellSet>::vector_deleting_destructor; // weak
void *CSpellTable::vftable = &CSpellTable::vector_deleting_destructor; // weak
__int32 (__stdcall *CSpellTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *MetaSpell::vftable)(void *, char) = &MetaSpell::vector_deleting_destructor; // weak
int (__thiscall *Spell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *DispelSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *FellowshipDispelSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *FellowshipPortalSendingSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
const float INVALID_ENCHANTMENT_DEGRADE_LIMIT = -666.0; // idb
int (__thiscall *EnchantmentSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *FellowshipEnchantmentSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *BoostSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *FellowshipBoostSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ProjectileSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ProjectileLifeSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ProjectileEnchantmentSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
const long double dbl_7E4DA0 = -1.0; // idb
int (__thiscall *PortalSummonSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PortalSendingSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *TransferSpell::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *CAllegianceData::vftable)(void *, char) = &CAllegianceData::scalar_deleting_destructor; // weak
int (__thiscall *CAllegianceProfile::vftable)(void *, char) = &CAllegianceProfile::vector_deleting_destructor; // weak
int (__thiscall *CContractTracker::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vftable)(void *, char) = &PackableHashTable<AC1Legacy::CaseInsensitiveStringBase<AC1Legacy::PStringBase<char>>,QuestDef>::vector_deleting_destructor; // weak
int (__thiscall *QuestDef::vftable)(void *, char) = &QuestDef::vector_deleting_destructor; // weak
void *CQuestDefDB::vftable = &CQuestDefDB::vector_deleting_destructor; // weak
__int32 (__stdcall *CQuestDefDB::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashIterator<unsigned long,CContract>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,CContract>::scalar_deleting_destructor,
  &PackableHashTable<unsigned long,CContract>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,CContract>::vftable)(void *, char) = &PackableHashTable<unsigned long,CContract>::vector_deleting_destructor; // weak
void *CContractTable::vftable = &CContractTable::vector_deleting_destructor; // weak
__int32 (__stdcall *CContractTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CContract::vftable)(void *, char) = &CContract::scalar_deleting_destructor; // weak
Turbine_GUID CPlayerModule_InterfaceType_97 = { 4204615439u, 51729u, 19767u, "´\"2À\x1A\v\bz" }; // idb
Turbine_GUID stru_7E5308 = { 3735928559u, 0u, 0u, "´Õ" }; // idb
int (__stdcall *CPlayerModule::vftable)(char) = &CPlayerModule::scalar_deleting_destructor; // weak
__int32 (__stdcall *CPlayerModule::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *RenderVertexStreamD3D::vftable)(void *, char) = &RenderVertexStreamD3D::scalar_deleting_destructor; // weak
int (__thiscall *RenderDevice::vftable)(void *, char) = &RenderDevice::scalar_deleting_destructor; // weak
int (__thiscall *RenderDeviceD3D::vftable)(void *, char) = &RenderDeviceD3D::scalar_deleting_destructor; // weak
int (__thiscall *RenderIndexBufferD3D::vftable)(void *, char) = &RenderIndexBufferD3D::vector_deleting_destructor; // weak
int (__thiscall *RenderVertexBufferD3D::vftable)(void *, char) = &RenderVertexBufferD3D::vector_deleting_destructor; // weak
void *Scene::vftable = &Scene::vector_deleting_destructor; // weak
__int32 (__stdcall *Scene::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *CChatEvent::vftable = &CCliDatEvent::vector_deleting_destructor; // weak
void *CChatEvent::vftable = &CChatEvent::vector_deleting_destructor; // weak
int (__thiscall *CChatEvent::vftable[4])(void *, char) =
{
  &CCliDatEvent::vector_deleting_destructor,
  &PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor,
  &PackableHashIterator<unsigned long,CloPaletteTemplate>::vector_deleting_destructor,
  &PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vftable[3])(void *, char) =
{
  &PackableHashIterator<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor,
  &PackableHashIterator<unsigned long,CloPaletteTemplate>::vector_deleting_destructor,
  &PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashIterator<unsigned long,CloPaletteTemplate>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,CloPaletteTemplate>::vector_deleting_destructor,
  &PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vftable)(void *, char) = &PackableHashTable<IDClass<_tagDataID,32,0>,ClothingBase>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,CloPaletteTemplate>::vftable)(void *, char) = &PackableHashTable<unsigned long,CloPaletteTemplate>::vector_deleting_destructor; // weak
void *ClothingTable::vftable = &ClothingTable::vector_deleting_destructor; // weak
__int32 (__stdcall *ClothingTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CloObjectEffect::vftable)(void *, char) = &CloObjectEffect::vector_deleting_destructor; // weak
int (__thiscall *CloTextureEffect::vftable)(void *, char) = &CloTextureEffect::vector_deleting_destructor; // weak
int (__thiscall *CloPaletteTemplate::vftable)(void *, char) = &CloPaletteTemplate::vector_deleting_destructor; // weak
int (__thiscall *CloSubpalEffect::vftable)(void *, char) = &CloSubpalEffect::vector_deleting_destructor; // weak
int (__thiscall *TextureMapChange::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ClothingBase::vftable)(void *, char) = &ClothingBase::vector_deleting_destructor; // weak
int (__thiscall *NetInitializer::AllSocketsCrashCleaner::vftable)(void *, char) = &NetInitializer::AllSocketsCrashCleaner::vector_deleting_destructor; // weak
int (__thiscall *CLogonHeader::vftable)(void *, char) = &CLogonHeader::scalar_deleting_destructor; // weak
int (__thiscall *ObjDesc::vftable)(void *, char) = &ObjDesc::scalar_deleting_destructor; // weak
void *PalSet::vftable = &PalSet::vector_deleting_destructor; // weak
__int32 (__stdcall *PalSet::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PublicWeenieDesc::vftable)(void *, char) = &PublicWeenieDesc::scalar_deleting_destructor; // weak
int (__thiscall *VisualDesc::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *IDList::vftable)(void *, char) = &IDList::scalar_deleting_destructor; // weak
__int32 (__stdcall *String::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *OldHashTable<unsigned long,unsigned long>::vftable)(void *, char) = &OldHashTable<unsigned long,unsigned long>::vector_deleting_destructor; // weak
void *OldPHashTable<unsigned long,unsigned long>::vftable = &OldPHashTable<unsigned long,unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *OldPHashTable<unsigned long,unsigned long>::vftable)(void *, char) = &OldPHashTable<unsigned long,unsigned long>::scalar_deleting_destructor; // weak
void *PHashTable<unsigned long,unsigned long>::vftable = &PHashTable<unsigned long,unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *PHashTable<unsigned long,unsigned long>::vftable[2])(void *, char) =
{
  &PHashTable<unsigned long,unsigned long>::scalar_deleting_destructor,
  &RestrictionDB::scalar_deleting_destructor
}; // weak
int (__thiscall *RestrictionDB::vftable)(void *, char) = &RestrictionDB::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,GuestInfo>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,GuestInfo>::vector_deleting_destructor,
  &PackableHashTable<unsigned long,GuestInfo>::scalar_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,GuestInfo>::vftable)(void *, char) = &PackableHashTable<unsigned long,GuestInfo>::scalar_deleting_destructor; // weak
int (__thiscall *GuestInfo::vftable)(void *, char) = &GuestInfo::scalar_deleting_destructor; // weak
int (__thiscall *HAR::vftable)(void *, char) = &HAR::vector_deleting_destructor; // weak
int (__thiscall *AC1Legacy::vlong::vftable)(void *, char) = &AC1Legacy::vlong::vector_deleting_destructor; // weak
int (__thiscall *HookAppraisalProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *AppraisalProfile::vftable)(void *, char) = &AppraisalProfile::scalar_deleting_destructor; // weak
int (__thiscall *PSmartArray<unsigned long>::vftable)(void *, char) = &PSmartArray<unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *CreatureAppraisalProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *WeaponProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *AllegianceData::vftable)(void *, char) = &AllegianceData::vector_deleting_destructor; // weak
int (__thiscall *AllegianceProfile::vftable)(void *, char) = &AllegianceProfile::scalar_deleting_destructor; // weak
int (__thiscall *PSmartArray<AC1Legacy::PStringBase<char>>::vftable)(void *, char) = &PSmartArray<AC1Legacy::PStringBase<char>>::scalar_deleting_destructor; // weak
int (__thiscall *AllegianceHierarchy::vftable)(void *, char) = &AllegianceHierarchy::scalar_deleting_destructor; // weak
int (__thiscall *AllegianceNode::vftable)(void *, char) = &AllegianceNode::scalar_deleting_destructor; // weak
const long double dbl_7E72C8 = -1.0; // idb
int (__thiscall *Trade::vftable)(void *, char) = &Trade::vector_deleting_destructor; // weak
int (__thiscall *HousePaymentList::vftable)(void *, char) = &PackableList<HousePayment>::vector_deleting_destructor; // weak
int (__thiscall *HouseData::vftable)(void *, char) = &HouseData::vector_deleting_destructor; // weak
int (__thiscall *HouseProfile::vftable)(void *, char) = &HouseProfile::scalar_deleting_destructor; // weak
int (__thiscall *PackableHashIterator<unsigned long,SpellComponentBase>::vftable[2])(void *, char) =
{
  &PackableHashIterator<unsigned long,SpellComponentBase>::scalar_deleting_destructor,
  &PackableHashTable<unsigned long,SpellComponentBase>::scalar_deleting_destructor
}; // weak
int (__thiscall *PackableHashTable<unsigned long,SpellComponentBase>::vftable)(void *, char) = &PackableHashTable<unsigned long,SpellComponentBase>::scalar_deleting_destructor; // weak
void *SpellComponentTable::vftable = &SpellComponentTable::vector_deleting_destructor; // weak
__int32 (__stdcall *SpellComponentTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *ACWTimeStamper::vftable)(void *, char) = &ACWTimeStamper::scalar_deleting_destructor; // weak
__int32 (__stdcall *CharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0>::vector_deleting_destructor; // weak
void (__thiscall *ACCharGenStartArea::vftable)(ACCharGenStartArea *this, struct Archive *) = &ACCharGenStartArea::Serialize; // weak
int (__thiscall *HashTable<unsigned long,HeritageGroup_CG,0>::vftable)(void *, char) = &HashTable<unsigned long,HeritageGroup_CG,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *ACCharGenData::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *List<SkillRecord *>::vftable)(void *, char) = &List<SkillRecord *>::scalar_deleting_destructor; // weak
void (__thiscall *CharGenState::vftable)(gmNoticeHandler *this) = &gmNoticeHandler::RecvNotice_PrevSpellSelection; // weak
int (__thiscall *ACCharGenResult::vftable)(void *, char) = &ACCharGenResult::vector_deleting_destructor; // weak
int (__thiscall *SalvageResult::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<SalvageResult>::vftable)(void *, char) = &PackableList<SalvageResult>::vector_deleting_destructor; // weak
int (__thiscall *SalvageOperationsResultData::vftable)(void *, char) = &SalvageOperationsResultData::scalar_deleting_destructor; // weak
void *ExperienceTable::vftable = &ExperienceTable::vector_deleting_destructor; // weak
__int32 (__stdcall *ExperienceTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CombatManeuver::vftable)(void *, char) = &Subpalette::vector_deleting_destructor; // weak
void *CombatManeuverTable::vftable = &CombatManeuverTable::vector_deleting_destructor; // weak
__int32 (__stdcall *CombatManeuverTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
const float INVALID_ENCHANTMENT_DEGRADE_LIMIT_0 = -666.0; // idb
void *Attribute2ndTable::vftable = &Attribute2ndTable::vector_deleting_destructor; // weak
__int32 (__stdcall *Attribute2ndTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<unsigned long,SkillBase>::vftable)(void *, char) = &PackableHashTable<unsigned long,SkillBase>::vector_deleting_destructor; // weak
void *SkillTable::vftable = &SkillTable::vector_deleting_destructor; // weak
__int32 (__stdcall *SkillTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *ACQualityFilter::vftable = &ACQualityFilter::vector_deleting_destructor; // weak
__int32 (__stdcall *ACQualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__stdcall *QualityFilter::vftable)(int) = &QualityFilter::vector_deleting_destructor; // weak
__int32 (__stdcall *QualityFilter::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *CreationProfile::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *AttributeCache::vftable)(void *, char) = &AttributeCache::scalar_deleting_destructor; // weak
int (__thiscall *ChatRoomTracker::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *Emote::vftable)(void *, char) = &Emote::scalar_deleting_destructor; // weak
int (__thiscall *GeneratorProfile::vftable)(void *, char) = &GeneratorProfile::vector_deleting_destructor; // weak
int (__thiscall *PackableList<GeneratorProfile>::vftable)(void *, char) = &PackableList<GeneratorProfile>::scalar_deleting_destructor; // weak
int (__thiscall *GeneratorTable::vftable)(void *, char) = &GeneratorTable::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,GeneratorRegistryNode>::vftable)(void *, char) = &PackableHashTable<unsigned long,GeneratorRegistryNode>::scalar_deleting_destructor; // weak
int (__thiscall *GeneratorRegistry::vftable)(void *, char) = &GeneratorRegistry::vector_deleting_destructor; // weak
int (__thiscall *PackableList<GeneratorQueueNode>::vftable)(void *, char) = &PackableList<GeneratorQueueNode>::vector_deleting_destructor; // weak
int (__thiscall *GeneratorQueue::vftable)(void *, char) = &GeneratorQueue::vector_deleting_destructor; // weak
int (__thiscall *GeneratorRegistryNode::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *GeneratorQueueNode::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *BodyPartSelectionData::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ItemProfile::vftable)(void *, char) = &ItemProfile::scalar_deleting_destructor; // weak
int (__thiscall *VendorProfile::vftable)(void *, char) = &VendorProfile::scalar_deleting_destructor; // weak
int (__thiscall *PageDataList::vftable)(void *, char) = &PageDataList::vector_deleting_destructor; // weak
void *QuestDefDB::vftable = &QuestDefDB::vector_deleting_destructor; // weak
__int32 (__stdcall *QuestDefDB::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PackableHashTable<IDClass<_tagDataID,32,0>,long>::vftable)(void *, char) = &PackableHashTable<IDClass<_tagDataID,32,0>,long>::scalar_deleting_destructor; // weak
int (__thiscall *PackUsingSerialize<PackObj>::vftable)(void *, char) = &PackUsingSerialize<PackObj>::scalar_deleting_destructor; // weak
int (__thiscall *PackObjPropertyCollection::vftable)(void *, char) = &PackObjPropertyCollection::vector_deleting_destructor; // weak
void *PackObjPropertyCollection::vftable = &PackObjPropertyCollection::vector_deleting_destructor; // weak
int (__thiscall *PlayerModule::vftable)(void *, char) = &PlayerModule::vector_deleting_destructor; // weak
int (__thiscall *CShortCutData::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *ShortCutManager::vftable)(void *, char) = &ShortCutManager::scalar_deleting_destructor; // weak
const unsigned int DB_TYPE_WEENIE_DEF = 268435457u; // idb
const unsigned int DB_TYPE_CHAR_GEN_0 = 268435458u; // idb
const unsigned int DB_TYPE_ATTRIBUTE_2ND_TABLE_0 = 268435459u; // idb
const unsigned int DB_TYPE_SKILL_TABLE_0 = 268435460u; // idb
const unsigned int DB_TYPE_SPELL_TABLE_0 = 268435461u; // idb
const unsigned int DB_TYPE_SPELLCOMPONENT_TABLE_0 = 268435462u; // idb
const unsigned int DB_TYPE_W_TREASURE_SYSTEM = 268435463u; // idb
const unsigned int DB_TYPE_W_CRAFT_TABLE = 268435464u; // idb
const unsigned int DB_TYPE_XP_TABLE_0 = 268435465u; // idb
const unsigned int DB_TYPE_QUEST_DEF_DB_0 = 268435466u; // idb
const unsigned int DB_TYPE_GAME_EVENT_DB = 268435467u; // idb
const unsigned int DB_TYPE_QUALITY_FILTER_0 = 268435468u; // idb
const unsigned int DB_TYPE_COMBAT_TABLE_0 = 268435469u; // idb
const unsigned int DB_TYPE_MUTATE_FILTER = 268435470u; // idb
const unsigned int DB_TYPE_CONTRACT_TABLE_0 = 268435472u; // idb
void *ProfilerUI::vftable = &ProfilerUI::vector_deleting_destructor; // weak
int (__thiscall *ProfilerUI::vftable)(void *, char) = &ProfilerUI::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vftable)(void *, char) = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,UIPreferenceItem *> *,0>::vector_deleting_destructor; // weak
int (__thiscall *UIPreferenceItem::vftable)(void *, char) = &UIPreferenceItem::scalar_deleting_destructor; // weak
int (__thiscall *UIPreferenceItemBool::vftable)(void *, char) = &UIPreferenceItemBool::vector_deleting_destructor; // weak
int (__thiscall *UIPreferenceItemEnum::vftable)(void *, char) = &UIPreferenceItemEnum::scalar_deleting_destructor; // weak
int (__thiscall *UIPreferenceItemFloat::vftable)(void *, char) = &UIPreferenceItemFloat::vector_deleting_destructor; // weak
int (__thiscall *UIPreferenceItemInt::vftable)(void *, char) = &UIPreferenceItemInt::vector_deleting_destructor; // weak
int (__thiscall *UIPreferenceItemString::vftable)(void *, char) = &UIPreferenceItemString::vector_deleting_destructor; // weak
int (__thiscall *HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable)(void *, char) = &HashTable<PStringBase<char>,UIPreferenceItem *,0>::vector_deleting_destructor; // weak
int (__thiscall *_com_error::vftable)(void *, char) = &_com_error::scalar_deleting_destructor; // weak
int dword_7EC2B0[] = { 8 }; // weak
char byte_7EC2C0[] = { '\x04' }; // weak
int (__stdcall *D3DXMesh::GXTri3Mesh<unsigned short,1,65535>::vftable)(int, int, int) = &D3DXMesh::GXTri3Mesh<unsigned short,1,65535>::QueryInterface; // weak
int (__stdcall *D3DXMesh::GXTri3Mesh<unsigned int,0,4294967295>::vftable)(int, int, int) = &D3DXMesh::GXTri3Mesh<unsigned short,1,65535>::QueryInterface; // weak
float flt_7EC5C0[] = {  0.0 }; // weak
float flt_7EC5C4[] = {  0.0065130978 }; // weak
float flt_7EC9C0[] = {  0.0 }; // weak
float flt_7EC9C4[] = {  0.0022629909 }; // weak
int (__thiscall *D3DXTex::CCodec::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodecDXT::vftable)(void *, char) = &D3DXTex::CCodec_DXT5::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_R8G8B8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8R8G8B8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_X8R8G8B8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_R5G6B5::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_X1R5G5B5::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A1R5G5B5::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A4R4G4B4::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_R3G3B2::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8R3G3B2::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_X4R4G4B4::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A2B10G10R10::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8B8G8R8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_X8B8G8R8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_G16R16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A2R10G10B10::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A16B16G16R16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8P8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_P8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_L8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A8L8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A4L4::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_L16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_V8U8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_L6V5U5::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_X8L8V8U8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_Q8W8V8U8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_V16U16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A2W10V10U10::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_Q16W16V16U16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_CxV8U8::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_R32F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_R16F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_G16R16F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A16B16G16R16F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_G32R32F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_A32B32G32R32F::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_D3DX_A16L16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_D3DX_R16G16B16::vftable)(void *, char) = &D3DXTex::CCodec_G16R16::scalar_deleting_destructor; // weak
int (__thiscall *D3DXTex::CCodec_UYVY::vftable)(void *, char) = &D3DXTex::CCodec_G8R8_G8B8::vector_deleting_destructor; // weak
char aGenuineintel[13] = "GenuineIntel"; // weak
GUID IID_ID3DXMesh = { 1075897794u, 5123u, 18729u, "à?‚ËI˙¡ï" };
GUID IID_ID3DXBaseMesh = { 2128167901u, 21224u, 16565u, "®ÿvh\\@c0" };
GUID IID_ID3DXBuffer = { 2342910728u, 20885u, 16610u, "¨X\ròú:\x01\x02" };
GUID IID_IDirect3DVolumeTexture9 = { 622350956u, 59273u, 16657u, "ßπGÔ2ç\x13Ê" };
GUID IID_IDirect3DTexture9 = { 2244153895u, 15845u, 20224u, "õ:Ò\x1A√å\x18µ" };
__int32 (__stdcall *D3DXCore::CBuffer::vftable)(D3DXCore::CBuffer *this, const struct _GUID *, void **) = &D3DXCore::CBuffer::QueryInterface; // weak
_UNKNOWN unk_7F1A4C; // weak
_UNKNOWN unk_7F1A6C; // weak
_UNKNOWN unk_7F1A8C; // weak
_UNKNOWN unk_7F1AA4; // weak
_UNKNOWN unk_7F1AC4; // weak
_UNKNOWN unk_7F1AD4; // weak
_UNKNOWN unk_7F1AE4; // weak
_UNKNOWN unk_7F1AF0; // weak
_UNKNOWN unk_7F1B00; // weak
_UNKNOWN unk_7F1B10; // weak
_UNKNOWN unk_7F1B20; // weak
_UNKNOWN unk_7F1B40; // weak
const union __m64 const3dn_0_1 = { 4575657221408423936ui64 }; // weak
const union __m64 const3dn_1_N1 = { 13799029259328552960ui64 }; // weak
const union __m64 const3dn_1_1 = { 4575657222473777152ui64 }; // weak
const union __m64 const3dn_2_2 = { 4611686019501129728ui64 }; // weak
const union __m64 const3dn_3_2 = { 4611686019505324032ui64 }; // weak
const union __m64 const3dn_SignBitLo = { 2147483648ui64 }; // weak
const union __m64 const3dn_SignBitHi = { 9223372036854775808ui64 }; // weak
const union __m64 const3dn_SignBits = { 9223372039002259456ui64 }; // weak
const union __m64 const3dn_SignMaskHi = { 9223372036854775807ui64 }; // weak
const union __m64 const3dn_SignMasks = { 9223372034707292159ui64 }; // weak
const union __m64 const3dn_epsilon = { 3746994890844667904ui64 }; // weak
const union __m64 const3dn_dwordLo = { 4294967295ui64 }; // weak
const union __m64 const3dn_halves = { 4539628425446424576ui64 }; // weak
const union __m64 const3dn_FltMin = { 36028797027352576ui64 }; // weak
const union __m64 g_negate_low = { 2147483648ui64 }; // weak
const union __m64 g_negate_high = { 9223372036854775808ui64 }; // weak
const union __m64 g_const_1 = { 4575657222473777152ui64 }; // weak
const union __m64 g_const_half = { 4539628425446424576ui64 }; // weak
const union __m64 g_const_2 = { 4611686019501129728ui64 }; // weak
const union __m64 g_const_3 = { 4629700418014806016ui64 }; // weak
const union __m64 g_const_0_1 = { 4575657221408423936ui64 }; // weak
const union __m64 g_const_1_0 = { 1065353216ui64 }; // weak
const union __m64 g_const_nh_nl = { 9223372039002259456ui64 }; // weak
const union __m64 g_const_n2 = { 13835058058503389184ui64 }; // weak
const union __m64 g_const_n2_1 = { 4575657224629649408ui64 }; // weak
const union __m64 g_const_niner = { 4575656500919271256ui64 }; // weak
char aAuthenticamd[13] = "AuthenticAMD"; // weak
char aUnknownvendr[13] = "UnknownVendr"; // weak
__int128 xmmword_7F47B0 = 0x800000000000000080000000i64; // weak
__int128 xmmword_7F47C0 = 0x800000008000000000000000i64; // weak
__int128 xmmword_7F47D0 = 0x80000000000000008000000000000000i64; // weak
__int128 xmmword_7F47E0 = 0x40400000404000004040000040400000i64; // weak
__int128 xmmword_7F47F0 = 0x3F0000003F0000003F0000003F000000i64; // weak
__int128 xmmword_7F4810 = 0x40400000404000004040000040400000i64; // weak
__int128 xmmword_7F4820 = 0x3F0000003F0000003F0000003F000000i64; // weak
_UNKNOWN unk_7F4840; // weak
_UNKNOWN unk_7F4850; // weak
int dword_7F4860[] = { 1 }; // weak
__int64 qword_7F4870 = -4719772406288220160i64; // weak
const int extra_lbits[29] =
{
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  4,
  4,
  4,
  4,
  5,
  5,
  5,
  5,
  0
}; // idb
const int extra_dbits[30] =
{
  0,
  0,
  0,
  0,
  1,
  1,
  2,
  2,
  3,
  3,
  4,
  4,
  5,
  5,
  6,
  6,
  7,
  7,
  8,
  8,
  9,
  9,
  10,
  10,
  11,
  11,
  12,
  12,
  13,
  13
}; // idb
char bl_order[19] =
{
  '\x10',
  '\x11',
  '\x12',
  '\0',
  '\b',
  '\a',
  '\t',
  '\x06',
  '\n',
  '\x05',
  '\v',
  '\x04',
  '\f',
  '\x03',
  '\r',
  '\x02',
  '\x0E',
  '\x01',
  '\x0F'
}; // idb
ct_data_s static_ltree[288] =
{
  { { 12u }, { 8u } },
  { { 140u }, { 8u } },
  { { 76u }, { 8u } },
  { { 204u }, { 8u } },
  { { 44u }, { 8u } },
  { { 172u }, { 8u } },
  { { 108u }, { 8u } },
  { { 236u }, { 8u } },
  { { 28u }, { 8u } },
  { { 156u }, { 8u } },
  { { 92u }, { 8u } },
  { { 220u }, { 8u } },
  { { 60u }, { 8u } },
  { { 188u }, { 8u } },
  { { 124u }, { 8u } },
  { { 252u }, { 8u } },
  { { 2u }, { 8u } },
  { { 130u }, { 8u } },
  { { 66u }, { 8u } },
  { { 194u }, { 8u } },
  { { 34u }, { 8u } },
  { { 162u }, { 8u } },
  { { 98u }, { 8u } },
  { { 226u }, { 8u } },
  { { 18u }, { 8u } },
  { { 146u }, { 8u } },
  { { 82u }, { 8u } },
  { { 210u }, { 8u } },
  { { 50u }, { 8u } },
  { { 178u }, { 8u } },
  { { 114u }, { 8u } },
  { { 242u }, { 8u } },
  { { 10u }, { 8u } },
  { { 138u }, { 8u } },
  { { 74u }, { 8u } },
  { { 202u }, { 8u } },
  { { 42u }, { 8u } },
  { { 170u }, { 8u } },
  { { 106u }, { 8u } },
  { { 234u }, { 8u } },
  { { 26u }, { 8u } },
  { { 154u }, { 8u } },
  { { 90u }, { 8u } },
  { { 218u }, { 8u } },
  { { 58u }, { 8u } },
  { { 186u }, { 8u } },
  { { 122u }, { 8u } },
  { { 250u }, { 8u } },
  { { 6u }, { 8u } },
  { { 134u }, { 8u } },
  { { 70u }, { 8u } },
  { { 198u }, { 8u } },
  { { 38u }, { 8u } },
  { { 166u }, { 8u } },
  { { 102u }, { 8u } },
  { { 230u }, { 8u } },
  { { 22u }, { 8u } },
  { { 150u }, { 8u } },
  { { 86u }, { 8u } },
  { { 214u }, { 8u } },
  { { 54u }, { 8u } },
  { { 182u }, { 8u } },
  { { 118u }, { 8u } },
  { { 246u }, { 8u } },
  { { 14u }, { 8u } },
  { { 142u }, { 8u } },
  { { 78u }, { 8u } },
  { { 206u }, { 8u } },
  { { 46u }, { 8u } },
  { { 174u }, { 8u } },
  { { 110u }, { 8u } },
  { { 238u }, { 8u } },
  { { 30u }, { 8u } },
  { { 158u }, { 8u } },
  { { 94u }, { 8u } },
  { { 222u }, { 8u } },
  { { 62u }, { 8u } },
  { { 190u }, { 8u } },
  { { 126u }, { 8u } },
  { { 254u }, { 8u } },
  { { 1u }, { 8u } },
  { { 129u }, { 8u } },
  { { 65u }, { 8u } },
  { { 193u }, { 8u } },
  { { 33u }, { 8u } },
  { { 161u }, { 8u } },
  { { 97u }, { 8u } },
  { { 225u }, { 8u } },
  { { 17u }, { 8u } },
  { { 145u }, { 8u } },
  { { 81u }, { 8u } },
  { { 209u }, { 8u } },
  { { 49u }, { 8u } },
  { { 177u }, { 8u } },
  { { 113u }, { 8u } },
  { { 241u }, { 8u } },
  { { 9u }, { 8u } },
  { { 137u }, { 8u } },
  { { 73u }, { 8u } },
  { { 201u }, { 8u } },
  { { 41u }, { 8u } },
  { { 169u }, { 8u } },
  { { 105u }, { 8u } },
  { { 233u }, { 8u } },
  { { 25u }, { 8u } },
  { { 153u }, { 8u } },
  { { 89u }, { 8u } },
  { { 217u }, { 8u } },
  { { 57u }, { 8u } },
  { { 185u }, { 8u } },
  { { 121u }, { 8u } },
  { { 249u }, { 8u } },
  { { 5u }, { 8u } },
  { { 133u }, { 8u } },
  { { 69u }, { 8u } },
  { { 197u }, { 8u } },
  { { 37u }, { 8u } },
  { { 165u }, { 8u } },
  { { 101u }, { 8u } },
  { { 229u }, { 8u } },
  { { 21u }, { 8u } },
  { { 149u }, { 8u } },
  { { 85u }, { 8u } },
  { { 213u }, { 8u } },
  { { 53u }, { 8u } },
  { { 181u }, { 8u } },
  { { 117u }, { 8u } },
  { { 245u }, { 8u } },
  { { 13u }, { 8u } },
  { { 141u }, { 8u } },
  { { 77u }, { 8u } },
  { { 205u }, { 8u } },
  { { 45u }, { 8u } },
  { { 173u }, { 8u } },
  { { 109u }, { 8u } },
  { { 237u }, { 8u } },
  { { 29u }, { 8u } },
  { { 157u }, { 8u } },
  { { 93u }, { 8u } },
  { { 221u }, { 8u } },
  { { 61u }, { 8u } },
  { { 189u }, { 8u } },
  { { 125u }, { 8u } },
  { { 253u }, { 8u } },
  { { 19u }, { 9u } },
  { { 275u }, { 9u } },
  { { 147u }, { 9u } },
  { { 403u }, { 9u } },
  { { 83u }, { 9u } },
  { { 339u }, { 9u } },
  { { 211u }, { 9u } },
  { { 467u }, { 9u } },
  { { 51u }, { 9u } },
  { { 307u }, { 9u } },
  { { 179u }, { 9u } },
  { { 435u }, { 9u } },
  { { 115u }, { 9u } },
  { { 371u }, { 9u } },
  { { 243u }, { 9u } },
  { { 499u }, { 9u } },
  { { 11u }, { 9u } },
  { { 267u }, { 9u } },
  { { 139u }, { 9u } },
  { { 395u }, { 9u } },
  { { 75u }, { 9u } },
  { { 331u }, { 9u } },
  { { 203u }, { 9u } },
  { { 459u }, { 9u } },
  { { 43u }, { 9u } },
  { { 299u }, { 9u } },
  { { 171u }, { 9u } },
  { { 427u }, { 9u } },
  { { 107u }, { 9u } },
  { { 363u }, { 9u } },
  { { 235u }, { 9u } },
  { { 491u }, { 9u } },
  { { 27u }, { 9u } },
  { { 283u }, { 9u } },
  { { 155u }, { 9u } },
  { { 411u }, { 9u } },
  { { 91u }, { 9u } },
  { { 347u }, { 9u } },
  { { 219u }, { 9u } },
  { { 475u }, { 9u } },
  { { 59u }, { 9u } },
  { { 315u }, { 9u } },
  { { 187u }, { 9u } },
  { { 443u }, { 9u } },
  { { 123u }, { 9u } },
  { { 379u }, { 9u } },
  { { 251u }, { 9u } },
  { { 507u }, { 9u } },
  { { 7u }, { 9u } },
  { { 263u }, { 9u } },
  { { 135u }, { 9u } },
  { { 391u }, { 9u } },
  { { 71u }, { 9u } },
  { { 327u }, { 9u } },
  { { 199u }, { 9u } },
  { { 455u }, { 9u } },
  { { 39u }, { 9u } },
  { { 295u }, { 9u } },
  { { 167u }, { 9u } },
  { { 423u }, { 9u } },
  { { 103u }, { 9u } },
  { { 359u }, { 9u } },
  { { 231u }, { 9u } },
  { { 487u }, { 9u } },
  { { 23u }, { 9u } },
  { { 279u }, { 9u } },
  { { 151u }, { 9u } },
  { { 407u }, { 9u } },
  { { 87u }, { 9u } },
  { { 343u }, { 9u } },
  { { 215u }, { 9u } },
  { { 471u }, { 9u } },
  { { 55u }, { 9u } },
  { { 311u }, { 9u } },
  { { 183u }, { 9u } },
  { { 439u }, { 9u } },
  { { 119u }, { 9u } },
  { { 375u }, { 9u } },
  { { 247u }, { 9u } },
  { { 503u }, { 9u } },
  { { 15u }, { 9u } },
  { { 271u }, { 9u } },
  { { 143u }, { 9u } },
  { { 399u }, { 9u } },
  { { 79u }, { 9u } },
  { { 335u }, { 9u } },
  { { 207u }, { 9u } },
  { { 463u }, { 9u } },
  { { 47u }, { 9u } },
  { { 303u }, { 9u } },
  { { 175u }, { 9u } },
  { { 431u }, { 9u } },
  { { 111u }, { 9u } },
  { { 367u }, { 9u } },
  { { 239u }, { 9u } },
  { { 495u }, { 9u } },
  { { 31u }, { 9u } },
  { { 287u }, { 9u } },
  { { 159u }, { 9u } },
  { { 415u }, { 9u } },
  { { 95u }, { 9u } },
  { { 351u }, { 9u } },
  { { 223u }, { 9u } },
  { { 479u }, { 9u } },
  { { 63u }, { 9u } },
  { { 319u }, { 9u } },
  { { 191u }, { 9u } },
  { { 447u }, { 9u } },
  { { 127u }, { 9u } },
  { { 383u }, { 9u } },
  { { 255u }, { 9u } },
  { { 511u }, { 9u } },
  { { 0u }, { 7u } },
  { { 64u }, { 7u } },
  { { 32u }, { 7u } },
  { { 96u }, { 7u } },
  { { 16u }, { 7u } },
  { { 80u }, { 7u } },
  { { 48u }, { 7u } },
  { { 112u }, { 7u } },
  { { 8u }, { 7u } },
  { { 72u }, { 7u } },
  { { 40u }, { 7u } },
  { { 104u }, { 7u } },
  { { 24u }, { 7u } },
  { { 88u }, { 7u } },
  { { 56u }, { 7u } },
  { { 120u }, { 7u } },
  { { 4u }, { 7u } },
  { { 68u }, { 7u } },
  { { 36u }, { 7u } },
  { { 100u }, { 7u } },
  { { 20u }, { 7u } },
  { { 84u }, { 7u } },
  { { 52u }, { 7u } },
  { { 116u }, { 7u } },
  { { 3u }, { 8u } },
  { { 131u }, { 8u } },
  { { 67u }, { 8u } },
  { { 195u }, { 8u } },
  { { 35u }, { 8u } },
  { { 163u }, { 8u } },
  { { 99u }, { 8u } },
  { { 227u }, { 8u } }
}; // idb
ct_data_s static_dtree[30] =
{
  { { 0u }, { 5u } },
  { { 16u }, { 5u } },
  { { 8u }, { 5u } },
  { { 24u }, { 5u } },
  { { 4u }, { 5u } },
  { { 20u }, { 5u } },
  { { 12u }, { 5u } },
  { { 28u }, { 5u } },
  { { 2u }, { 5u } },
  { { 18u }, { 5u } },
  { { 10u }, { 5u } },
  { { 26u }, { 5u } },
  { { 6u }, { 5u } },
  { { 22u }, { 5u } },
  { { 14u }, { 5u } },
  { { 30u }, { 5u } },
  { { 1u }, { 5u } },
  { { 17u }, { 5u } },
  { { 9u }, { 5u } },
  { { 25u }, { 5u } },
  { { 5u }, { 5u } },
  { { 21u }, { 5u } },
  { { 13u }, { 5u } },
  { { 29u }, { 5u } },
  { { 3u }, { 5u } },
  { { 19u }, { 5u } },
  { { 11u }, { 5u } },
  { { 27u }, { 5u } },
  { { 7u }, { 5u } },
  { { 23u }, { 5u } }
}; // idb
char d3dx__dist_code[] = { '\0' }; // weak
char byte_7F5190[] = { '\0' }; // weak
char d3dx__length_code[] = { '\0' }; // weak
const int base_length[29] =
{
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7,
  8,
  10,
  12,
  14,
  16,
  20,
  24,
  28,
  32,
  40,
  48,
  56,
  64,
  80,
  96,
  112,
  128,
  160,
  192,
  224,
  0
}; // idb
const int base_dist[30] =
{
  0,
  1,
  2,
  3,
  4,
  6,
  8,
  12,
  16,
  24,
  32,
  48,
  64,
  96,
  128,
  192,
  256,
  384,
  512,
  768,
  1024,
  1536,
  2048,
  3072,
  4096,
  6144,
  8192,
  12288,
  16384,
  24576
}; // idb
GUID IID_IDirectSound3DBuffer = { 664468102u, 18817u, 4558u, "•! Ø\vÂ`" };
GUID IID_IDirectSound3DListener = { 664468100u, 18817u, 4558u, "•! Ø\vÂ`" };
GUID GUID_SysKeyboard = { 1864182625u, 54688u, 4559u, "ø«DEST" };
GUID GUID_SysMouse = { 1864182624u, 54688u, 4559u, "ø«DEST" };
GUID IID_IDirectInput8A = { 3212410928u, 18490u, 19874u, "™ô]dÌ6ó" };
int (__thiscall *FileNodeName_UInt64::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeName_Int64::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeName_CellID::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeName_InstanceID::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeName_Guid::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeName_LongHex::vftable)(void *, char) = &FileNodeName_Int64::vector_deleting_destructor; // weak
int (__thiscall *FileNodeFileInfo::vftable)(void *, char) = &FileNodeFileInfo::scalar_deleting_destructor; // weak
int (__stdcall *PFileNode::vftable)(char) = &PFileNode::scalar_deleting_destructor; // weak
unsigned int g_TurbineCorePackVersion = 2u; // idb
int (__thiscall *SharedCriticalSection::vftable)(void *, char) = &SharedCriticalSection::vector_deleting_destructor; // weak
int (__thiscall *PortalThread::vftable)(void *, char) = &PortalThread::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<int,CAsyncStateHandler *,1>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<int,CAsyncStateHandler *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vector_deleting_destructor,
  &CAsyncStateHandler::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<AsyncContext,CAsyncStateMachine::CAsyncStateData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vector_deleting_destructor,
  &CAsyncStateHandler::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,1>::vector_deleting_destructor,
  &CAsyncStateHandler::vector_deleting_destructor
}; // weak
int (__thiscall *CAsyncStateHandler::vftable)(void *, char) = &CAsyncStateHandler::vector_deleting_destructor; // weak
int (__thiscall *CAsyncStateMachine::CAsyncStateData::vftable[3])(void *, char) =
{
  &CAsyncStateMachine::CAsyncStateData::vector_deleting_destructor,
  &HashTable<PStringBase<char>,unsigned long,1>::scalar_deleting_destructor,
  &CAsyncStateMachine::scalar_deleting_destructor
}; // weak
int (__thiscall *AutoGrowHashTable<PStringBase<char>,unsigned long>::vftable[2])(void *, char) =
{
  &HashTable<PStringBase<char>,unsigned long,1>::scalar_deleting_destructor,
  &CAsyncStateMachine::scalar_deleting_destructor
}; // weak
int (__thiscall *CAsyncStateMachine::vftable)(void *, char) = &CAsyncStateMachine::scalar_deleting_destructor; // weak
int (__thiscall *QTIsaac<8,unsigned long>::vftable)(void *, char) = &QTIsaac<8,unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *DataSource::vftable)(void *, char) = &DataSource::scalar_deleting_destructor; // weak
void (__thiscall *CMostlyConsecutiveIntSet::vftable)(CMostlyConsecutiveIntSet *this, struct Archive *) = &CMostlyConsecutiveIntSet::Serialize; // weak
int (__thiscall *DiskConBase::vftable)(void *, char) = &DiskConBase::vector_deleting_destructor; // weak
int (__thiscall *DiskController::vftable)(void *, char) = &DiskController::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vftable)(void *, char) = &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashList<IDClass<_tagDataID,32,0>,bool,1>::HashListData *,1>::vector_deleting_destructor; // weak
void (__thiscall *DiskTransactInfo::vftable)(DiskTransactInfo *this, struct Archive *) = &DiskTransactInfo::Serialize; // weak
void (__thiscall *MergeNodesTransactInfo::vftable)(MergeNodesTransactInfo *this, struct Archive *) = &MergeNodesTransactInfo::Serialize; // weak
void (__thiscall *SplitNodeTransactInfo::vftable)(SplitNodeTransactInfo *this, struct Archive *) = &SplitNodeTransactInfo::Serialize; // weak
void (__thiscall *LRUDeleteTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *) = &LRUDeleteTransactInfo::Serialize; // weak
void (__thiscall *DeleteLeafTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *) = &LRUDeleteTransactInfo::Serialize; // weak
void (__thiscall *DeleteInternalTransactInfo::vftable)(DeleteInternalTransactInfo *this, struct Archive *) = &DeleteInternalTransactInfo::Serialize; // weak
void (__thiscall *RotateEntryTransactInfo::vftable)(RotateEntryTransactInfo *this, struct Archive *) = &RotateEntryTransactInfo::Serialize; // weak
void (__thiscall *LRUExpandTransactInfo::vftable)(LRUDeleteTransactInfo *this, struct Archive *) = &LRUDeleteTransactInfo::Serialize; // weak
void (__thiscall *AddObjectTransactInfo::vftable)(AddObjectTransactInfo *this, struct Archive *) = &AddObjectTransactInfo::Serialize; // weak
void (__thiscall *UpdateObjectTransactInfo::vftable)(UpdateObjectTransactInfo *this, struct Archive *) = &UpdateObjectTransactInfo::Serialize; // weak
struct DBObj *(__thiscall *ThreadedCache::vftable)(AsyncCache *this, unsigned __int32 type, const struct QualifiedDataID *) = &AsyncCache::BlockingGet; // weak
__int32 (__stdcall *ThreadedCache::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *ThreadedCache::vftable = &ThreadedCache::vector_deleting_destructor; // weak
void (__thiscall *CAllIterationList::PTaggedIterationList::vftable)(CAllIterationList::PTaggedIterationList *this, struct Archive *) = &CAllIterationList::PTaggedIterationList::Serialize; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::vftable[7])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,TFileEntry *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::scalar_deleting_destructor,
  &TFileEntry::vector_deleting_destructor,
  &AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor,
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::vftable[6])(void *, char) =
{
  &IntrusiveHashTable<CaseInsensitiveStringBase<PStringBase<char>>,HashTableData<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *> *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::scalar_deleting_destructor,
  &TFileEntry::vector_deleting_destructor,
  &AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor,
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::vftable[5])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,TDBTypeEntry *> *,1>::scalar_deleting_destructor,
  &TFileEntry::vector_deleting_destructor,
  &AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor,
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *TFileEntry::vftable[4])(void *, char) =
{
  &TFileEntry::vector_deleting_destructor,
  &AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor,
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::vftable[3])(void *, char) =
{
  &AutoGrowHashTable<IDClass<_tagDataID,32,0>,TFileEntry *>::scalar_deleting_destructor,
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vftable[2])(void *, char) =
{
  &HashTable<CaseInsensitiveStringBase<PStringBase<char>>,TFileEntry *,1>::vector_deleting_destructor,
  &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,TDBTypeEntry *,1>::vftable)(void *, char) = &AutoGrowHashTable<unsigned long,TDBTypeEntry *>::vector_deleting_destructor; // weak
int (__thiscall *List<StringTableMetaLanguage::Node const *>::vftable)(void *, char) = &List<StringTableMetaLanguage::Node const *>::vector_deleting_destructor; // weak
char yytranslate[262] =
{
  '\0',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\b',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\t',
  '\v',
  '\n',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x02',
  '\x01',
  '\x03',
  '\x04',
  '\x05',
  '\x06',
  '\a'
}; // idb
const __int16 yyr1[24] =
{
  0,
  12,
  12,
  13,
  13,
  14,
  14,
  14,
  14,
  15,
  15,
  15,
  15,
  17,
  16,
  18,
  16,
  19,
  20,
  20,
  21,
  21,
  22,
  23
}; // idb
const __int16 yyr2[24] = { 0, 0, 1, 1, 2, 1, 1, 1, 1, 2, 3, 1, 2, 0, 4, 0, 5, 1, 1, 3, 1, 2, 1, 1 }; // idb
const __int16 yydefact[34] =
{
  1,
  22,
  11,
  0,
  17,
  0,
  13,
  2,
  3,
  6,
  7,
  8,
  5,
  9,
  0,
  15,
  12,
  0,
  4,
  10,
  0,
  0,
  18,
  20,
  0,
  14,
  0,
  23,
  21,
  16,
  19,
  0,
  0,
  0
}; // idb
const __int16 yypact[34] =
{
  1,
  32768,
  32768,
  10,
  32768,
  65533,
  32768,
  1,
  32768,
  32768,
  32768,
  32768,
  32768,
  32768,
  65534,
  32768,
  32768,
  9,
  32768,
  32768,
  9,
  65529,
  2,
  14,
  5,
  32768,
  9,
  32768,
  32768,
  32768,
  32768,
  16,
  21,
  32768
}; // idb
const __int16 yytable[23] =
{
  12,
  16,
  19,
  25,
  1,
  2,
  3,
  12,
  4,
  5,
  6,
  24,
  1,
  26,
  13,
  29,
  32,
  30,
  14,
  15,
  27,
  33,
  18
}; // idb
const __int16 yycheck[23] = { 0, 4, 4, 10, 3, 4, 5, 7, 7, 8, 9, 20, 3, 11, 4, 10, 0, 26, 8, 9, 6, 0, 7 }; // idb
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,NameFilterLanguageData> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,NameFilterLanguageData,0>::scalar_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,NameFilterLanguageData,0>::vftable)(void *, char) = &HashTable<unsigned long,NameFilterLanguageData,0>::scalar_deleting_destructor; // weak
__int32 (__stdcall *NameFilterTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *DBPropertyCollection::vftable)(void *, char) = &DBPropertyCollection::scalar_deleting_destructor; // weak
__int32 (__stdcall *DBPropertyCollection::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,List<PStringBase<char>>> *,0>::vector_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,HashTable<unsigned long,List<PStringBase<char>>,0>,0>::vector_deleting_destructor,
  &HashTable<unsigned long,List<PStringBase<char>>,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,List<PStringBase<char>>,0>::vftable)(void *, char) = &HashTable<unsigned long,List<PStringBase<char>>,0>::vector_deleting_destructor; // weak
__int32 (__stdcall *TabooTable::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *PerfMonCounterInfo::vftable)(void *, char) = &PerfMonCounterInfo::vector_deleting_destructor; // weak
int (__thiscall *List<PerfMonCounterInfo *>::vftable[2])(void *, char) =
{
  &List<PerfMonCounterInfo *>::scalar_deleting_destructor,
  &PerfMonCounterManager::vector_deleting_destructor
}; // weak
int (__thiscall *PerfMonCounterManager::vftable)(void *, char) = &PerfMonCounterManager::vector_deleting_destructor; // weak
_MIDL_PROC_FORMAT_STRING _MIDL_ProcFormatString = { 0, "N\x0FP\x01\x02S\bN\x0FN\bQ\x01\x06S\bN\x0FN\bQ\x01\x10S\b" }; // idb
_MIDL_TYPE_FORMAT_STRING _MIDL_TypeFormatString = { 0, "\x11\b\b\\\x1B\x03\x04)\x04\b[\x1B\a\b)\x04\v[" }; // idb
_MIDL_STUB_DESC turbineperfmonrpcserverapi_StubDesc =
{
  &turbineperfmonrpcserverapi___RpcServerInterface,
  &MIDL_user_allocate,
  &MIDL_user_free,
  { NULL },
  NULL,
  NULL,
  NULL,
  NULL,
  (const char *)0x7FEC96,
  1,
  65537u,
  NULL,
  100663643,
  NULL,
  NULL,
  NULL,
  1u,
  NULL,
  NULL,
  0u
}; // idb
int (__thiscall *AC1Legacy::PStringBaseIter<char>::vftable)(_DWORD) = &AC1Legacy::PStringBaseIter<char>::GetStrLen; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,HashList<unsigned long,ActionMapValue,1>,1>::HashListData *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,InputMapConflictsValue,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,InputMapConflictsValue> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,InputMapConflictsValue,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,InputMapConflictsValue,0>::vftable)(void *, char) = &HashTable<unsigned long,InputMapConflictsValue,0>::vector_deleting_destructor; // weak
__int32 (__stdcall *ActionMap::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
GUID GUID_Virtual = { 3364175888u, 19766u, 17499u, "ÖÌ]¶,∫'‰" };
Turbine_GUID INVALID_GUID_0 = { 0u, 0u, 0u, "" }; // idb
int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,enum  ControlType> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<ControlSpecification,HashTableData<ControlSpecification,CInputManager_WIN32::RecentControlState> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vftable)(void *, char) = &IntrusiveHashTable<ControlSpecification,PriorityHash<ControlSpecification,CInputManager_WIN32::ButtonHistoryEntry,1>::PriorityHashData *,1>::vector_deleting_destructor; // weak
int (__thiscall *HashTable<ControlSpecification,enum  ControlType,0>::vftable[2])(void *, char) =
{
  &HashTable<ControlSpecification,enum  ControlType,0>::vector_deleting_destructor,
  &HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vftable)(void *, char) = &HashTable<ControlSpecification,CInputManager_WIN32::RecentControlState,0>::vector_deleting_destructor; // weak
int (__thiscall *CInputManager_WIN32::vftable)(void *, char) = &CInputManager_WIN32::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vftable)(void *, char) = &IntrusiveHashTable<PStringBase<char>,HashTableData<PStringBase<char>,unsigned long> *,0>::vector_deleting_destructor; // weak
int (__thiscall *HashTable<PStringBase<char>,unsigned long,0>::vftable)(void *, char) = &HashTable<PStringBase<char>,unsigned long,0>::scalar_deleting_destructor; // weak
GUID GUID_Virtual_0 = { 3364175888u, 19766u, 17499u, "ÖÌ]¶,∫'‰" };
int (__thiscall *IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<QualifiedControl,HashList<QualifiedControl,unsigned long,1>::HashListData *,1>::scalar_deleting_destructor,
  &IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<ControlSpecification,HashList<ControlSpecification,unsigned long,1>::HashListData *,1>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::scalar_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashList<unsigned long,CInputMap *,1>::HashListData *,1>::scalar_deleting_destructor; // weak
char aGuid_virtual[] = "GUID_Virtual"; // idb
__int32 (__stdcall *CMasterInputMap::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void (__thiscall *IConsoleCallbackObject::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
void *DebugConsole::vftable = &DebugConsole::vector_deleting_destructor; // weak
int (__stdcall *DebugConsole::vftable)(PStringBase<char> *_Text) = &DebugConsole::ConsoleCallback_OnTextAdded; // weak
void (__thiscall *DebugConsole::vftable)(gmNoticeHandler *this, const struct HousePaymentList *) = &gmNoticeHandler::RecvNotice_UpdateRentPayment; // weak
int (__thiscall *DebugConsole::vftable)(void *, char) = &DebugConsole::vector_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned __int64,HashTableData<unsigned __int64,SmartArray<QualityChangeHandler *,1> *> *,0>::vector_deleting_destructor,
  &IntrusiveHashTable<unsigned long,QualityHandler *,1>::scalar_deleting_destructor,
  &HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vector_deleting_destructor,
  &QualityRegistrar::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,QualityHandler *,1>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,QualityHandler *,1>::scalar_deleting_destructor,
  &HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vector_deleting_destructor,
  &QualityRegistrar::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned __int64,SmartArray<QualityChangeHandler *,1> *,0>::vector_deleting_destructor,
  &QualityRegistrar::vector_deleting_destructor
}; // weak
int (__thiscall *QualityRegistrar::vftable)(void *, char) = &QualityRegistrar::vector_deleting_destructor; // weak
int (__thiscall *Graphic::vftable)(void *, char) = &Graphic::vector_deleting_destructor; // weak
int (__thiscall *UIObject::vftable)(void *, char) = &UIObject::scalar_deleting_destructor; // weak
int (__thiscall *UISurfaceObject::vftable)(void *, char) = &UISurfaceObject::vector_deleting_destructor; // weak
int (__thiscall *UIRectangleObject::vftable)(void *, char) = &UIObject::scalar_deleting_destructor; // weak
int (__thiscall *UIViewportObject::vftable)(void *, char) = &UIObject::scalar_deleting_destructor; // weak
void *RenderTextureD3D::vftable = &RenderTextureD3D::vector_deleting_destructor; // weak
__int32 (__stdcall *RenderTextureD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
void *RenderSurfaceD3D::vftable = &RenderSurfaceD3D::vector_deleting_destructor; // weak
__int32 (__stdcall *RenderSurfaceD3D::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *TextureBasedFont::vftable)(void *, char) = &TextureBasedFont::vector_deleting_destructor; // weak
int (__thiscall *RenderIndexStreamD3D::vftable)(void *, char) = &RenderIndexStreamD3D::vector_deleting_destructor; // weak
int (__thiscall *QuickWindow::vftable)(void *, char) = &QuickWindow::vector_deleting_destructor; // weak
int (__thiscall *QuickButton::vftable)(void *, char) = &QuickButton::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::vftable[4])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ElementDesc> *,0>::scalar_deleting_destructor,
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,ElementDesc,0>::scalar_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vector_deleting_destructor
}; // weak
int (__thiscall *IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vftable[3])(void *, char) =
{
  &IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,ElementDesc,0>::scalar_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,ElementDesc,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,ElementDesc,0>::scalar_deleting_destructor,
  &HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable)(void *, char) = &HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vector_deleting_destructor; // weak
__int32 (__stdcall *NonDBObjLayoutDesc::vftable)(Interface *this, _GUID *iid, void **ppvObject) = &Interface::IUnknown_QueryInterface; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::vftable)(void *, char) = &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,StateDesc> *,0>::scalar_deleting_destructor; // weak
int (__thiscall *HashTable<unsigned long,StateDesc,0>::vftable[2])(void *, char) =
{
  &HashTable<unsigned long,StateDesc,0>::vector_deleting_destructor,
  &StateDesc::vector_deleting_destructor
}; // weak
int (__thiscall *StateDesc::vftable)(void *, char) = &StateDesc::vector_deleting_destructor; // weak
int (__thiscall *MD_Data_Image::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_Movie::vftable)(void *, char) = &MD_Data_Movie::scalar_deleting_destructor; // weak
int (__thiscall *MediaDesc::vftable)(void *, char) = &MediaDesc::vector_deleting_destructor; // weak
int (__thiscall *MD_Data_Cursor::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_State::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_Message::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
const long double dbl_801380 = -1.0; // idb
int (__thiscall *MD_Data_Fade::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_Jump::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_Sound::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
const long double dbl_801578 = -1.0; // idb
int (__thiscall *MD_Data_Pause::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
int (__thiscall *MD_Data_Alpha::vftable)(void *, char) = &MD_Data_Pause::scalar_deleting_destructor; // weak
const long double dbl_801698 = -1.0; // idb
int (__thiscall *MD_Data_Anim::vftable)(void *, char) = &MD_Data_Anim::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<UIRegion *,HashList<UIRegion *,UIRegion *,1>::HashListData *,1>::vector_deleting_destructor,
  &UIRegion::vector_deleting_destructor
}; // weak
int (__thiscall *UIRegion::vftable)(void *, char) = &UIRegion::vector_deleting_destructor; // weak
int (__thiscall *UIFramework::vftable)(void *, char) = &UIFramework::vector_deleting_destructor; // weak
int (__thiscall *UIMainFramework::vftable)(void *, char) = &UIMainFramework::scalar_deleting_destructor; // weak
int (__thiscall *GamePlayUI::vftable)(void *, char) = &GamePlayUI::scalar_deleting_destructor; // weak
int (__thiscall *OrderHdr::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<AC1Legacy::PStringBase<char>>::vftable)(void *, char) = &PackableList<AC1Legacy::PStringBase<char>>::scalar_deleting_destructor; // weak
int (__thiscall *GameMoveData::vftable)(void *, char) = &PackObj::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<AdminAccountData>::vftable)(void *, char) = &PackableList<AdminAccountData>::scalar_deleting_destructor; // weak
int (__thiscall *PackableList<AdminPlayerData>::vftable)(void *, char) = &PackableList<AdminPlayerData>::vector_deleting_destructor; // weak
int (__thiscall *AdminAccountData::vftable)(void *, char) = &AdminAccountData::vector_deleting_destructor; // weak
int (__thiscall *AdminPlayerData::vftable)(void *, char) = &AdminPlayerData::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vftable)(void *, char) = &PackableHashTable<AC1Legacy::PStringBase<char>,unsigned long>::vector_deleting_destructor; // weak
int (__thiscall *PackableHashTable<unsigned long,SquelchInfo>::vftable)(void *, char) = &PackableHashTable<unsigned long,SquelchInfo>::scalar_deleting_destructor; // weak
int (__thiscall *SquelchDB::vftable)(void *, char) = &SquelchDB::scalar_deleting_destructor; // weak
int (__thiscall *EventFilter::vftable)(void *, char) = &EventFilter::scalar_deleting_destructor; // weak
int (__thiscall *IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vftable[2])(void *, char) =
{
  &IntrusiveHashTable<unsigned long,HashTableData<unsigned long,unsigned char> *,0>::vector_deleting_destructor,
  &HashTable<unsigned long,unsigned char,0>::vector_deleting_destructor
}; // weak
int (__thiscall *HashTable<unsigned long,unsigned char,0>::vftable)(void *, char) = &HashTable<unsigned long,unsigned char,0>::vector_deleting_destructor; // weak
void *PHashTable<unsigned long,unsigned char>::vftable = &PHashTable<unsigned long,unsigned char>::vector_deleting_destructor; // weak
int (__thiscall *WTimeStamper::vftable)(void *, char) = &WTimeStamper::scalar_deleting_destructor; // weak
int (__thiscall *PHashTable<unsigned long,unsigned char>::vftable)(void *, char) = &PHashTable<unsigned long,unsigned char>::scalar_deleting_destructor; // weak
int (__thiscall *CommandInterpreter::vftable)(void *, char) = &CommandInterpreter::vector_deleting_destructor; // weak
const char *const command_strings[408] =
{
  "Invalid",
  "HoldRun",
  "HoldSidestep",
  "Ready",
  "Stop",
  "WalkForward",
  "WalkBackwards",
  "RunForward",
  "Fallen",
  "Interpolating",
  "Hover",
  "On",
  "Off",
  "TurnRight",
  "TurnLeft",
  "SideStepRight",
  "SideStepLeft",
  "Dead",
  "Crouch",
  "Sitting",
  "Sleeping",
  "Falling",
  "Reload",
  "Unload",
  "Pickup",
  "StoreInBackpack",
  "Eat",
  "Drink",
  "Reading",
  "JumpCharging",
  "AimLevel",
  "AimHigh15",
  "AimHigh30",
  "AimHigh45",
  "AimHigh60",
  "AimHigh75",
  "AimHigh90",
  "AimLow15",
  "AimLow30",
  "AimLow45",
  "AimLow60",
  "AimLow75",
  "AimLow90",
  "MagicBlast",
  "MagicSelfHead",
  "MagicSelfHeart",
  "MagicBonus",
  "MagicClap",
  "MagicHarm",
  "MagicHeal",
  "MagicThrowMissile",
  "MagicRecoilMissile",
  "MagicPenalty",
  "MagicTransfer",
  "MagicVision",
  "MagicEnchantItem",
  "MagicPortal",
  "MagicPray",
  "StopTurning",
  "Jump",
  "HandCombat",
  "NonCombat",
  "SwordCombat",
  "BowCombat",
  "SwordShieldCombat",
  "CrossbowCombat",
  "UnusedCombat",
  "SlingCombat",
  "2HandedSwordCombat",
  "2HandedStaffCombat",
  "DualWieldCombat",
  "ThrownWeaponCombat",
  "Graze",
  "Magi",
  "Hop",
  "Jumpup",
  "Cheer",
  "ChestBeat",
  "TippedLeft",
  "TippedRight",
  "FallDown",
  "Twitch1",
  "Twitch2",
  "Twitch3",
  "Twitch4",
  "StaggerBackward",
  "StaggerForward",
  "Sanctuary",
  "ThrustMed",
  "ThrustLow",
  "ThrustHigh",
  "SlashHigh",
  "SlashMed",
  "SlashLow",
  "BackhandHigh",
  "BackhandMed",
  "BackhandLow",
  "Shoot",
  "AttackHigh1",
  "AttackMed1",
  "AttackLow1",
  "AttackHigh2",
  "AttackMed2",
  "AttackLow2",
  "AttackHigh3",
  "AttackMed3",
  "AttackLow3",
  "HeadThrow",
  "FistSlam",
  "BreatheFlame_",
  "SpinAttack",
  "MagicPowerUp01",
  "MagicPowerUp02",
  "MagicPowerUp03",
  "MagicPowerUp04",
  "MagicPowerUp05",
  "MagicPowerUp06",
  "MagicPowerUp07",
  "MagicPowerUp08",
  "MagicPowerUp09",
  "MagicPowerUp10",
  "ShakeFist",
  "Beckon",
  "BeSeeingYou",
  "BlowKiss",
  "BowDeep",
  "ClapHands",
  "Cry",
  "Laugh",
  "MimeEat",
  "MimeDrink",
  "Nod",
  "Point",
  "ShakeHead",
  "Shrug",
  "Wave",
  "Akimbo",
  "HeartyLaugh",
  "Salute",
  "ScratchHead",
  "SmackHead",
  "TapFoot",
  "WaveHigh",
  "WaveLow",
  "YawnStretch",
  "Cringe",
  "Kneel",
  "Plead",
  "Shiver",
  "Shoo",
  "Slouch",
  "Spit",
  "Surrender",
  "Woah",
  "Winded",
  "YMCA",
  "EnterGame",
  "ExitGame",
  "OnCreation",
  "OnDestruction",
  "EnterPortal",
  "ExitPortal",
  "Cancel",
  "UseSelected",
  "AutosortSelected",
  "DropSelected",
  "GiveSelected",
  "SplitSelected",
  "ExamineSelected",
  "CreateShortcutToSelected",
  "PreviousCompassItem",
  "NextCompassItem",
  "ClosestCompassItem",
  "PreviousSelection",
  "LastAttacker",
  "PreviousFellow",
  "NextFellow",
  "ToggleCombat",
  "HighAttack",
  "MediumAttack",
  "LowAttack",
  "EnterChat",
  "ToggleChat",
  "SavePosition",
  "OptionsPanel",
  "ResetView",
  "CameraLeftRotate",
  "CameraRightRotate",
  "CameraRaise",
  "CameraLower",
  "CameraCloser",
  "CameraFarther",
  "FloorView",
  "MouseLook",
  "PreviousItem",
  "NextItem",
  "ClosestItem",
  "ShiftView",
  "MapView",
  "AutoRun",
  "DecreasePowerSetting",
  "IncreasePowerSetting",
  "Pray",
  "Mock",
  "Teapot",
  "SpecialAttack1",
  "SpecialAttack2",
  "SpecialAttack3",
  "MissileAttack1",
  "MissileAttack2",
  "MissileAttack3",
  "CastSpell",
  "Flatulence",
  "FirstPersonView",
  "AllegiancePanel",
  "FellowshipPanel",
  "SpellbookPanel",
  "SpellComponentsPanel",
  "HousePanel",
  "AttributesPanel",
  "SkillsPanel",
  "MapPanel",
  "InventoryPanel",
  "Demonet",
  "UseMagicStaff",
  "UseMagicWand",
  "Blink",
  "Bite",
  "TwitchSubstate1",
  "TwitchSubstate2",
  "TwitchSubstate3",
  "CaptureScreenshotToFile",
  "BowNoAmmo",
  "CrossBowNoAmmo",
  "ShakeFistState",
  "PrayState",
  "BowDeepState",
  "ClapHandsState",
  "CrossArmsState",
  "ShiverState",
  "PointState",
  "WaveState",
  "AkimboState",
  "SaluteState",
  "ScratchHeadState",
  "TapFootState",
  "LeanState",
  "KneelState",
  "PleadState",
  "ATOYOT",
  "SlouchState",
  "SurrenderState",
  "WoahState",
  "WindedState",
  "AutoCreateShortcuts",
  "AutoRepeatAttacks",
  "AutoTarget",
  "AdvancedCombatInterface",
  "IgnoreAllegianceRequests",
  "IgnoreFellowshipRequests",
  "InvertMouseLook",
  "LetPlayersGiveYouItems",
  "AutoTrackCombatTargets",
  "DisplayTooltips",
  "AttemptToDeceivePlayers",
  "RunAsDefaultMovement",
  "StayInChatModeAfterSend",
  "RightClickToMouseLook",
  "VividTargetIndicator",
  "SelectSelf",
  "SkillHealSelf",
  "NextMonster",
  "PreviousMonster",
  "ClosestMonster",
  "NextPlayer",
  "PreviousPlayer",
  "ClosestPlayer",
  "SnowAngelState",
  "WarmHands",
  "CurtseyState",
  "AFKState",
  "MeditateState",
  "TradePanel",
  "LogOut",
  "DoubleSlashLow",
  "DoubleSlashMed",
  "DoubleSlashHigh",
  "TripleSlashLow",
  "TripleSlashMed",
  "TripleSlashHigh",
  "DoubleThrustLow",
  "DoubleThrustMed",
  "DoubleThrustHigh",
  "TripleThrustLow",
  "TripleThrustMed",
  "TripleThrustHigh",
  "MagicPowerUp01Purple",
  "MagicPowerUp02Purple",
  "MagicPowerUp03Purple",
  "MagicPowerUp04Purple",
  "MagicPowerUp05Purple",
  "MagicPowerUp06Purple",
  "MagicPowerUp07Purple",
  "MagicPowerUp08Purple",
  "MagicPowerUp09Purple",
  "MagicPowerUp10Purple",
  "Helper",
  "Pickup5",
  "Pickup10",
  "Pickup15",
  "Pickup20",
  "HouseRecall",
  "AtlatlCombat",
  "ThrownShieldCombat",
  "SitState",
  "SitCrossleggedState",
  "SitBackState",
  "PointLeftState",
  "PointRightState",
  "TalktotheHandState",
  "PointDownState",
  "DrudgeDanceState",
  "PossumState",
  "ReadState",
  "ThinkerState",
  "HaveASeatState",
  "AtEaseState",
  "NudgeLeft",
  "NudgeRight",
  "PointLeft",
  "PointRight",
  "PointDown",
  "Knock",
  "ScanHorizon",
  "DrudgeDance",
  "HaveASeat",
  "LifestoneRecall",
  "CharacterOptionsPanel",
  "SoundAndGraphicsPanel",
  "HelpfulSpellsPanel",
  "HarmfulSpellsPanel",
  "CharacterInformationPanel",
  "LinkStatusPanel",
  "VitaePanel",
  "ShareFellowshipXP",
  "ShareFellowshipLoot",
  "AcceptCorpseLooting",
  "IgnoreTradeRequests",
  "DisableWeather",
  "DisableHouseEffect",
  "SideBySideVitals",
  "ShowRadarCoordinates",
  "ShowSpellDurations",
  "MuteOnLosingFocus",
  "Fishing",
  "MarketplaceRecall",
  "EnterPKLite",
  "AllegianceChat",
  "AutomaticallyAcceptFellowshipRequests",
  "Reply",
  "MonarchReply",
  "PatronReply",
  "ToggleCraftingChanceOfSuccessDialog",
  "UseClosestUnopenedCorpse",
  "UseNextUnopenedCorpse",
  "IssueSlashCommand",
  "AllegianceHometownRecall",
  "PKArenaRecall",
  "OffhandSlashHigh",
  "OffhandSlashMed",
  "OffhandSlashLow",
  "OffhandThrustHigh",
  "OffhandThrustMed",
  "OffhandThrustLow",
  "OffhandDoubleSlashLow",
  "OffhandDoubleSlashMed",
  "OffhandDoubleSlashHigh",
  "OffhandTripleSlashLow",
  "OffhandTripleSlashMed",
  "OffhandTripleSlashHigh",
  "OffhandDoubleThrustLow",
  "OffhandDoubleThrustMed",
  "OffhandDoubleThrustHigh",
  "OffhandTripleThrustLow",
  "OffhandTripleThrustMed",
  "OffhandTripleThrustHigh",
  "OffhandKick",
  "AttackHigh4",
  "AttackMed4",
  "AttackLow4",
  "AttackHigh5",
  "AttackMed5",
  "AttackLow5",
  "AttackHigh6",
  "AttackMed6",
  "AttackLow6",
  "PunchFastHigh",
  "PunchFastMed",
  "PunchFastLow",
  "PunchSlowHigh",
  "PunchSlowMed",
  "PunchSlowLow",
  "OffhandPunchFastHigh",
  "OffhandPunchFastMed",
  "OffhandPunchFastLow",
  "OffhandPunchSlowHigh",
  "OffhandPunchSlowMed",
  "OffhandPunchSlowLow"
}; // idb
const unsigned int command_ids_1[408] =
{
  2147483648u,
  2231369729u,
  2231369730u,
  1090519043u,
  1073741828u,
  1157627909u,
  1157627910u,
  1140850695u,
  1073741832u,
  1073741833u,
  1073741834u,
  1073741835u,
  1073741836u,
  1694498829u,
  1694498830u,
  1694498831u,
  1694498832u,
  1073741841u,
  1090519058u,
  1090519059u,
  1090519060u,
  1073741845u,
  1073741846u,
  1073741847u,
  1073741848u,
  1073741849u,
  1073741850u,
  1073741851u,
  1073741852u,
  1073741853u,
  1073741854u,
  1073741855u,
  1073741856u,
  1073741857u,
  1073741858u,
  1073741859u,
  1073741860u,
  1073741861u,
  1073741862u,
  1073741863u,
  1073741864u,
  1073741865u,
  1073741866u,
  1073741867u,
  1073741868u,
  1073741869u,
  1073741870u,
  1073741871u,
  1073741872u,
  1073741873u,
  1073741874u,
  1073741875u,
  1073741876u,
  1073741877u,
  1073741878u,
  1073741879u,
  1073741880u,
  1073741881u,
  536870970u,
  620757051u,
  2147483708u,
  2147483709u,
  2147483710u,
  2147483711u,
  2147483712u,
  2147483713u,
  2147483714u,
  2147483715u,
  2147483716u,
  2147483717u,
  2147483718u,
  2147483719u,
  2147483720u,
  2147483721u,
  268435530u,
  268435531u,
  318767180u,
  268435533u,
  268435534u,
  268435535u,
  268435536u,
  268435537u,
  268435538u,
  268435539u,
  268435540u,
  268435541u,
  268435542u,
  268435543u,
  268435544u,
  268435545u,
  268435546u,
  268435547u,
  268435548u,
  268435549u,
  268435550u,
  268435551u,
  268435552u,
  268435553u,
  268435554u,
  268435555u,
  268435556u,
  268435557u,
  268435558u,
  268435559u,
  268435560u,
  268435561u,
  268435562u,
  268435563u,
  268435564u,
  268435565u,
  268435566u,
  268435567u,
  268435568u,
  268435569u,
  268435570u,
  268435571u,
  268435572u,
  268435573u,
  268435574u,
  268435575u,
  268435576u,
  318767225u,
  318767226u,
  318767227u,
  318767228u,
  318767229u,
  318767230u,
  318767231u,
  318767232u,
  318767233u,
  318767234u,
  318767235u,
  318767236u,
  318767237u,
  318767238u,
  318767239u,
  318767240u,
  318767241u,
  318767242u,
  318767243u,
  318767244u,
  318767245u,
  318767246u,
  318767247u,
  318767248u,
  318767249u,
  318767250u,
  318767251u,
  318767252u,
  318767253u,
  318767254u,
  318767255u,
  318767256u,
  318767257u,
  318767258u,
  301990043u,
  268435612u,
  268435613u,
  268435614u,
  268435615u,
  268435616u,
  268435617u,
  134217890u,
  150995107u,
  150995108u,
  150995109u,
  150995110u,
  150995111u,
  150995112u,
  134217897u,
  150995114u,
  150995115u,
  150995116u,
  150995117u,
  150995118u,
  150995119u,
  150995120u,
  150995121u,
  218103986u,
  218103987u,
  218103988u,
  134217909u,
  134217910u,
  134217911u,
  150995128u,
  150995129u,
  218103994u,
  218103995u,
  218103996u,
  218103997u,
  218103998u,
  218103999u,
  150995136u,
  201326785u,
  150995138u,
  150995139u,
  150995140u,
  218104005u,
  150995142u,
  150995143u,
  150995144u,
  150995145u,
  318767306u,
  318767307u,
  318767308u,
  268435661u,
  268435662u,
  268435663u,
  268435664u,
  268435665u,
  268435666u,
  1073742035u,
  301990100u,
  150995157u,
  150995158u,
  150995159u,
  150995160u,
  150995161u,
  150995162u,
  150995163u,
  150995164u,
  150995165u,
  150995166u,
  301990111u,
  1073742048u,
  1073742049u,
  268435682u,
  268435683u,
  1073742052u,
  1073742053u,
  1073742054u,
  150995175u,
  2147483880u,
  2147483881u,
  1124073706u,
  1124073707u,
  1124073708u,
  1124073709u,
  1124073710u,
  1124073711u,
  1124073712u,
  1124073713u,
  1124073714u,
  1124073715u,
  1124073716u,
  1124073717u,
  1124073718u,
  1124073719u,
  1124073720u,
  1107296505u,
  1124073722u,
  1124073723u,
  1124073724u,
  1124073725u,
  150995198u,
  150995199u,
  150995200u,
  150995201u,
  150995202u,
  150995203u,
  150995204u,
  150995205u,
  150995206u,
  150995207u,
  150995208u,
  150995209u,
  150995210u,
  150995211u,
  150995212u,
  150995213u,
  268435726u,
  150995215u,
  150995216u,
  150995217u,
  150995218u,
  150995219u,
  150995220u,
  1124073749u,
  318767382u,
  1124073751u,
  1124073752u,
  1124073753u,
  150995226u,
  268435739u,
  268435740u,
  268435741u,
  268435742u,
  268435743u,
  268435744u,
  268435745u,
  268435746u,
  268435747u,
  268435748u,
  268435749u,
  268435750u,
  268435751u,
  268435752u,
  268435753u,
  268435754u,
  268435755u,
  268435756u,
  268435757u,
  268435758u,
  268435759u,
  268435760u,
  268435761u,
  318767410u,
  1073742131u,
  1073742132u,
  1073742133u,
  1073742134u,
  268435767u,
  2147483960u,
  2147483961u,
  1124073786u,
  1124073787u,
  1124073788u,
  1124073789u,
  1124073790u,
  1124073791u,
  1124073792u,
  1124073793u,
  1124073794u,
  1124073795u,
  1124073796u,
  1124073797u,
  1124073798u,
  318767431u,
  318767432u,
  318767433u,
  318767434u,
  318767435u,
  318767436u,
  318767437u,
  318767438u,
  318767439u,
  268435792u,
  150995281u,
  150995282u,
  150995283u,
  150995284u,
  150995285u,
  150995286u,
  150995287u,
  150995288u,
  150995289u,
  150995290u,
  150995291u,
  150995292u,
  150995293u,
  150995294u,
  150995295u,
  150995296u,
  150995297u,
  268435810u,
  268435811u,
  268435812u,
  150995301u,
  150995302u,
  150995303u,
  150995304u,
  150995305u,
  150995306u,
  150995307u,
  150995308u,
  150995309u,
  268435822u,
  268435823u,
  268435824u,
  268435825u,
  268435826u,
  268435827u,
  268435828u,
  268435829u,
  268435830u,
  268435831u,
  268435832u,
  268435833u,
  268435834u,
  268435835u,
  268435836u,
  268435837u,
  268435838u,
  268435839u,
  268435840u,
  268435841u,
  268435842u,
  268435843u,
  268435844u,
  268435845u,
  268435846u,
  268435847u,
  268435848u,
  268435849u,
  268435850u,
  268435851u,
  268435852u,
  268435853u,
  268435854u,
  268435855u,
  268435856u,
  268435857u,
  268435858u,
  268435859u,
  268435860u,
  268435861u,
  268435862u,
  268435863u
}; // idb
int (__thiscall *CObjectInventory::vftable)(void *, char) = &CObjectInventory::vector_deleting_destructor; // weak
int (__thiscall *CBuildingObj::vftable)(void *, char) = &CBuildingObj::scalar_deleting_destructor; // weak
int (__thiscall *TurbineDwExceptionFilter::WatsonCrashReportHelper::vftable)(void *, char) = &TurbineDwExceptionFilter::WatsonCrashReportHelper::vector_deleting_destructor; // weak
const float RADAR_DEFAULT_OBVIOUS_DISTANCE =  10.0; // idb
int (__thiscall *OldPublicWeenieDesc::vftable)(void *, char) = &OldPublicWeenieDesc::vector_deleting_destructor; // weak
int (__thiscall *GenericQualitiesData::vftable)(void *, char) = &GenericQualitiesData::vector_deleting_destructor; // weak
GUID GUID_NULL = { 0u, 0u, 0u, "" };
_UNKNOWN c_dfDIMouse2; // weak
const DIDATAFORMAT c_dfDIKeyboard = { 24u, 16u, 2u, 256u, 256u, &c_rgodfDIKeyboard };
const DIDATAFORMAT c_dfDIJoystick2 = { 24u, 16u, 1u, 272u, 164u, &c_rgodfDIJoy2 };
int (__thiscall *OutputStream::vftable[2])(void *, char) =
{
  &OutputStream::vector_deleting_destructor,
  &List<PFileNode *>::scalar_deleting_destructor
}; // weak
int (__thiscall *List<PFileNode *>::vftable)(void *, char) = &List<PFileNode *>::scalar_deleting_destructor; // weak
int (__thiscall *MMapUtil::vftable)(void *, char) = &MMapUtil::vector_deleting_destructor; // weak
GUID _GUID_56a868a9_0ad4_11ce_b03a_0020af0ba770 = { 1453877417u, 2772u, 4558u, "∞: Ø\vßp" };
GUID _GUID_56a868b1_0ad4_11ce_b03a_0020af0ba770 = { 1453877425u, 2772u, 4558u, "∞: Ø\vßp" };
GUID _GUID_56a868b2_0ad4_11ce_b03a_0020af0ba770 = { 1453877426u, 2772u, 4558u, "∞: Ø\vßp" };
GUID _GUID_56a868b6_0ad4_11ce_b03a_0020af0ba770 = { 1453877430u, 2772u, 4558u, "∞: Ø\vßp" };
int (__thiscall *MovieTheatre::vftable)(void *, char) = &MovieTheatre::vector_deleting_destructor; // weak
int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int) = &CBaseVideoRenderer::QueryInterface; // weak
int (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, int, int) = &CBaseInputPin::QueryInterface; // weak
__int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv) = &CBaseVideoRenderer::QueryInterface; // weak
__int32 (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv) = &CBaseVideoRenderer::NonDelegatingQueryInterface; // weak
GUID _GUID_71771540_2017_11cf_ae26_0020afd79767 = { 1903629632u, 8215u, 4559u, "Æ& Ø◊óg" };
__int32 (__stdcall *CBaseRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv) = &CBaseVideoRenderer::QueryInterface; // weak
__int32 (__stdcall *CBaseRenderer::vftable)(CBaseRenderer *this, _GUID *riid, void **ppv) = &CBaseRenderer::NonDelegatingQueryInterface; // weak
int (__stdcall *CRendererInputPin::vftable)(CBaseInputPin *this, int, int) = &CBaseInputPin::QueryInterface; // weak
int (__stdcall *CRendererInputPin::vftable)(CBaseVideoRenderer *this, int, int) = &CBaseInputPin::QueryInterface; // weak
__int32 (__stdcall *CRendererInputPin::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv) = &CBaseVideoRenderer::QueryInterface; // weak
__int32 (__stdcall *CRendererInputPin::vftable)(CBaseInputPin *this, _GUID *riid, void **ppv) = &CBaseInputPin::NonDelegatingQueryInterface; // weak
int (__stdcall *CTextureRenderer::vftable)(CBaseVideoRenderer *this, int, int) = &CBaseVideoRenderer::QueryInterface; // weak
__int32 (__stdcall *CBaseVideoRenderer::vftable)(CBaseVideoRenderer *this, _GUID *riid, void **ppv) = &CBaseVideoRenderer::NonDelegatingQueryInterface; // weak
__int32 (__stdcall *CEnumPins::vftable)(CEnumPins *this, _GUID *riid, void **ppv) = &CEnumPins::QueryInterface; // weak
__int32 (__stdcall *CEnumMediaTypes::vftable)(CEnumMediaTypes *this, _GUID *riid, void **ppv) = &CEnumMediaTypes::QueryInterface; // weak
__int32 (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv) = &CPosPassThru::NonDelegatingQueryInterface; // weak
__int32 (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv) = &CPosPassThru::QueryInterface; // weak
__int32 (__stdcall *CRendererPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv) = &CPosPassThru::NonDelegatingQueryInterface; // weak
int (__stdcall *CPosPassThru::vftable)(CPosPassThru *this, int, int) = &CPosPassThru::QueryInterface; // weak
__int32 (__stdcall *CRendererPosPassThru::vftable)(CPosPassThru *this, _GUID *riid, void **ppv) = &CPosPassThru::QueryInterface; // weak
GUID IID_IQualityControl = { 1807783595u, 3302u, 4561u, "∫Æ¿O¬‚\r" };
GUID IID_IPersist = { 268u, 0u, 0u, "¿F" };
GUID IID_IMediaEventSink = { 1453877410u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IFilterMapper = { 1453877411u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IMediaSeeking = { 917977216u, 49864u, 4559u, "ãFÄ_lÔ`" };
GUID IID_IAMovieSetup = { 2748894912u, 32346u, 4559u, "ª≈Ä_lÔ " };
GUID IID_IMemInputPin = { 1453877405u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IMemAllocator = { 1453877404u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IMediaSample2 = { 917977220u, 49864u, 4559u, "ãFÄ_lÔ`" };
GUID IID_IBaseFilter = { 1453877397u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IMediaFilter = { 1453877401u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IEnumMediaTypes = { 2311262272u, 33899u, 4558u, "ó”™UYZ" };
GUID IID_IEnumPins = { 1453877394u, 2772u, 4558u, "∞: Ø\vßp" };
GUID IID_IPin = { 1453877393u, 2772u, 4558u, "∞: Ø\vßp" };
GUID LIBID_QuartzTypeLib = { 1453877424u, 2772u, 4558u, "∞: Ø\vßp" };
const GUID TIME_FORMAT_MEDIA_TIME = { 2071483764u, 35970u, 4559u, "º\f™¨tˆ" };
GUID IID_IQualProp = { 466676912u, 63714u, 4558u, "™∆ Ø\vô£" };
const GUID FORMAT_VideoInfo = { 89694080u, 50006u, 4558u, "ø\x01™UYZ" };
GUID CLSID_MemoryAllocator = { 509942976u, 45465u, 4560u, "Ç\x12¿O√,E" };
GUID CLSID_FilterGraph = { 3828804531u, 21071u, 4558u, "üS Ø\vßp" };
GUID CLSID_FilterMapper = { 3828804530u, 21071u, 4558u, "üS Ø\vßp" };
const GUID MEDIASUBTYPE_RGB24 = { 3828804477u, 21071u, 4558u, "üS Ø\vßp" };
const GUID MEDIATYPE_Video = { 1935960438u, 0u, 16u, "Ä™8õq" };
_UNKNOWN __rtc_izz; // weak
_UNKNOWN __rtc_tzz; // weak
_UNKNOWN _TI1_AV_com_error__; // weak
_UNKNOWN __xc_a; // weak
_UNKNOWN __xc_z; // weak
_UNKNOWN __xi_a; // weak
_UNKNOWN __xi_z; // weak
IDClass<_tagCellID,16,65535> Invalid_CellID = { { 65535u } }; // idb
unsigned int gmClient::sm_nFontFace = 2u; // idb
unsigned int gmClient::sm_nFontSize = 1u; // idb
int _STL::_STLP_mutex_spin<0>::__max = 30; // weak
LPCSTR m_rgDLLMap = "unicows.dll"; // idb
volatile LONG dword_8172A4 = 0; // idb
char *off_8172A8 = "kernel32.dll"; // weak
volatile LONG hDll = 0; // idb
unsigned __int32 Turbine::Debug::DebugFlags = 4294967295u; // weak
bool s_bBackupStackAvailable = true; // idb
wchar_t *PStringBase<unsigned short>::s_NullBuffer = &unk_817390; // idb
PStringBase<char> PStringBase<char>::s_NullBuffer = { &unk_81735C }; // idb
PStringBase<char> PStringBase<char>::null_string = { &unk_81735C }; // idb
ArchiveInitializer Archive::SetCurrentCoreVersion = { &Archive::tagSetCurrentCoreVersion::vftable }; // idb
volatile LONG DialogBoxGateways::s_nDialogThreadPrepares = 4294967295; // idb
volatile LONG DialogBoxGateways::s_nReportThreadPrepares = 4294967295; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_0 = { { 65535u } }; // idb
struct Turbine::Debug *Turbine::Debug::s_pDebug = &g_commonDebug; // weak
unsigned int *g_bucketSizesBegin = &g_bucketSizeArray; // idb
unsigned int *g_bucketSizesEnd = &g_numBucketSizes; // idb
int DBCache::s_EngDataPackVer = 4294967295; // idb
__int32 DBCache::s_EngCellPackVer = 4294967295; // weak
int DBCache::s_GameDataPackVer = 4294967295; // idb
__int32 DBCache::s_GameCellPackVer = 4294967295; // weak
__int32 DBCache::s_GameDidPackVer = 4294967295; // weak
int (__thiscall *(*DBCache::s_ObjCache)[2])(void *, char) = &HashTable<unsigned long,DBOCache *,0>::vftable; // weak
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> stru_81760C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
DBCachePrefetchCallback s_PrefetchCallback =
{
  { &DBCachePrefetchCallback::vftable },
  { 0u },
  {
    &HashSet<QualifiedDataID>::vftable,
    {
      NULL,
      {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
      },
      NULL,
      NULL,
      0u,
      0u
    }
  }
}; // idb
_UNKNOWN unk_817684; // weak
int (__thiscall **off_817688)(void *, char) = &HashSet<QualifiedDataID>::vftable; // weak
IntrusiveHashTable<QualifiedDataID,HashSetData<QualifiedDataID> *,1> stru_81768C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
HashTable<unsigned long,ArchiveVersionRow,0> s_CachedVersionRows =
{
  &HashTable<unsigned long,ArchiveVersionRow,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,ArchiveVersionRow> *,0> stru_817734 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
HashTable<unsigned long,DBTypeDef,0> MasterDBMap::sm_DBTypeDefHash =
{
  &HashTable<unsigned long,DBTypeDef,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,DBTypeDef> *,0> stru_8177AC =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
RGBAColor RGBAColor_Black_4 = {  0.0,  0.0,  0.0,  1.0 }; // idb
HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0> s_AllocatedDefaultPropertyValues =
{
  &HashTable<unsigned long,IntrusiveSmartPointer<BasePropertyValue>,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,IntrusiveSmartPointer<BasePropertyValue> > *,0> stru_8178E4 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
AvailablePropertySet BasePropertyDesc::s_allAvailableProperties =
{
  {
    &HashTable<unsigned long,AvailableProperty,0>::vftable,
    {
      NULL,
      {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
      },
      NULL,
      NULL,
      0u,
      0u
    }
  }
}; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,AvailableProperty> *,0> stru_81796C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
__int32 Random::_seed = 1; // weak
__int32 Random::_idum2 = 123456789; // weak
double CInputManager::sm_timeKeyRepeatDelay =  0.25; // weak
double CInputManager::sm_timeKeyRepeatSpeed =  0.025; // weak
bool UserPreferences::sm_bTools = true; // weak
bool UserPreferences::sm_bPrefsLoadedOK = true; // weak
bool Device::m_bIsMinimized = true; // weak
bool Device::m_bSysKeysEnabled = true; // weak
bool Device::m_bAllowFullScreenMode = true; // weak
unsigned int Device::m_nForcedWidth = 1024u; // idb
unsigned int Device::m_nForcedHeight = 768u; // idb
bool Device::m_fMouseIsShown = true; // weak
struct DisplayPrefs Device::m_DisplayPrefs = { 67109632u, true, 0u, false, false, false }; // weak
char byte_817B68 = '\x01'; // weak
int dword_817B6C = 0; // weak
char byte_817B70 = '\0'; // weak
char byte_817B71 = '\0'; // weak
char byte_817B72 = '\0'; // weak
unsigned __int32 SceneTool::sceneTimestamp = 268435456u; // weak
bool SceneTool::m_RenderUIObjects = true; // weak
unsigned __int32 SceneTool::m_ScreenShotWidth = 1u; // weak
unsigned __int32 SceneTool::m_ScreenShotHeight = 1u; // weak
unsigned __int32 SceneTool::m_ScreenShotMaxX = 9u; // weak
unsigned __int32 SceneTool::m_ScreenShotMaxY = 9u; // weak
Position SceneTool::m_CameraPosition =
{
  { &Position::vftable },
  0u,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  }
}; // idb
_UNKNOWN unk_817C7C; // weak
Frame stru_817C80 =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
struct Position SceneTool::m_WorldPosition =
{
  { &Position::vftable },
  0u,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  }
}; // weak
int dword_817CC4 = 0; // weak
Frame stru_817CC8 =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
RGBAColor RGBAColor_White_8 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_Black_9 = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_Black_11 = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_Black_19 = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_White_19 = {  1.0,  1.0,  1.0,  1.0 }; // idb
bool HACK_formatConversion = true; // weak
float SmartBox::s_fViewerLightFalloff =  10.0; // weak
unsigned int command_line_autonomy_level = 2u; // weak
int SmartBox::click_object_index = 4294967295; // weak
LIGHTINFO viewer_light =
{
  0,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  },
  { {  0.0,  0.0,  0.0 } },
  {  0.0,  0.0,  0.0 },
   0.0,
   0.0,
   0.0
}; // idb
Frame stru_818684 =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
RGBColor stru_8186D0 = {  0.0,  0.0,  0.0 }; // idb
_UNKNOWN unk_8186DC; // weak
_UNKNOWN unk_8186E0; // weak
_UNKNOWN unk_8186E4; // weak
Vector3 Vector3_OneVector___1 = {  1.0,  1.0,  1.0 }; // idb
Vector3 Vector3_OneVector___2 = {  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_White_34 = {  1.0,  1.0,  1.0,  1.0 }; // idb
bool s_bChangeTextInDoFontRest = true; // idb
RGBAColor RGBAColor_White_36 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_Black_37 = {  0.0,  0.0,  0.0,  1.0 }; // idb
HashTable<unsigned long,List<DialogInfo>,0> DialogFactory::s_hashDialogQueues =
{
  &HashTable<unsigned long,List<DialogInfo>,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
HashTable<unsigned long,unsigned long,0> DialogFactory::s_hashCurInfos =
{
  &HashTable<unsigned long,DialogInfo,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> stru_818E2C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
HashTable<unsigned long,unsigned long,0> DialogFactory::s_hashCallbacks =
{
  &HashTable<unsigned long,void (__cdecl *)(PropertyCollection const &),0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> stru_818EA4 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
List<DialogInfo> DialogFactory::s_listNonQueuedInfos = { &List<DialogInfo>::vftable, NULL, NULL, 0u }; // idb
int (__thiscall **UIFlow::_frameworkCreateMethodTable)(void *, char) = &HashTable<unsigned long,UIMainFramework * (__cdecl *)(void),0>::vftable; // weak
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,RenderVertexStreamD3D *> *,0> stru_818F8C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
RGBAColor RGBAColor_RadarBlue = {  0.25,  0.66000003,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarGold = {  1.0,  0.67000002,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarYellow = {  1.0,  1.0,  0.5,  1.0 }; // idb
RGBAColor RGBAColor_RadarWhite = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarRed = {  1.0,  0.25,  0.38999999,  1.0 }; // idb
RGBAColor RGBAColor_RadarPurple = {  0.75,  0.38999999,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarPink = {  1.0,  0.66000003,  0.75,  1.0 }; // idb
RGBAColor RGBAColor_RadarCyan = {  0.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarBrightGreen = {  0.0,  1.0,  0.0,  1.0 }; // idb
wchar_t *pcProfessions = L"Custom"; // idb
wchar_t *pcGender = L"?"; // idb
unsigned __int16 *pcHeritage = &a__0; // idb
unsigned __int16 *pcTown = &aHoltburg; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_1 = { { 65535u } }; // idb
RGBAColor RGBAColor_HitTest_Head = {  0.0,  0.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Chest = {  0.0,  1.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Abdomen = {  1.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Upper_Arm = {  0.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Lower_Arm = {  1.0,  0.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Upper_Leg = {  1.0,  1.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Lower_Leg = {  0.0,  0.0,  0.50196081,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Hand = {  0.0,  0.50196081,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_HitTest_Foot = {  0.50196081,  0.0,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarBlue_0 = {  0.25,  0.66000003,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarGold_0 = {  1.0,  0.67000002,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarYellow_0 = {  1.0,  1.0,  0.5,  1.0 }; // idb
RGBAColor RGBAColor_RadarWhite_0 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarRed_0 = {  1.0,  0.25,  0.38999999,  1.0 }; // idb
RGBAColor RGBAColor_RadarPurple_0 = {  0.75,  0.38999999,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarPink_0 = {  1.0,  0.66000003,  0.75,  1.0 }; // idb
RGBAColor RGBAColor_RadarGreen_0 = {  0.0,  0.5,  0.25,  1.0 }; // idb
RGBAColor RGBAColor_RadarCyan_0 = {  0.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarBrightGreen_0 = {  0.0,  1.0,  0.0,  1.0 }; // idb
IDClass<_tagDataID,32,0> BALD_TEXTURE_57 = { { 83890359u } }; // idb
IDClass<_tagDataID,32,0> EmpyreanMaleFloatMotionDID = { { 150995467u } }; // idb
IDClass<_tagDataID,32,0> EmpyreanFemaleFloatMotionDID = { { 150995466u } }; // idb
IDClass<_tagDataID,32,0> EmpyreanMaleMotionDID = { { 150995470u } }; // idb
IDClass<_tagDataID,32,0> EmpyreanFemaleMotionDID = { { 150995469u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_UNDEAD_SETUP = { { 33561102u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_SETUP = { { 33561244u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_NOFLAME_SETUP = { { 33561246u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_SETUP = { { 33561245u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP = { { 33561238u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_UNDEAD_SETUP = { { 33561100u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_SETUP = { { 33561248u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP = { { 33561247u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_SETUP = { { 33561249u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP = { { 33561250u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CROWN_SETUP = { { 33560943u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_NOCROWN_SETUP = { { 33561183u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CROWN_SETUP = { { 33560944u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_NOCROWN_SETUP = { { 33561182u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CROWN_SETUP = { { 33560942u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_NOCROWN_SETUP = { { 33561181u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CROWN_SETUP = { { 33560941u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_NOCROWN_SETUP = { { 33561180u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_PES = { { 855642836u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_PES = { { 855642835u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_PES = { { 855642837u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_PES = { { 855642838u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CROWN_PES = { { 855642710u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_NOCROWN_PES = { { 855642811u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CROWN_PES = { { 855642711u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_NOCROWN_PES = { { 855642810u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CROWN_PES = { { 855642709u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CROWN_PES = { { 855642708u } }; // idb
IDClass<_tagDataID,32,0> HUMAN_SETUP_ID = { { 33554433u } }; // idb
RGBAColor colorBrightRed = {  1.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor colorWhite = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor colorYellow = {  1.0,  1.0,  0.24699999,  1.0 }; // idb
RGBAColor colorTan = {  0.824,  0.824,  0.39199999,  1.0 }; // idb
RGBAColor colorBrightPurple = {  1.0,  0.498,  1.0,  1.0 }; // idb
RGBAColor colorDarkRed = {  1.0,  0.24699999,  0.24699999,  1.0 }; // idb
RGBAColor colorLightRed = {  0.95999998,  0.45899999,  0.447,  1.0 }; // idb
RGBAColor colorLightBlue = {  0.24699999,  0.74900001,  1.0,  1.0 }; // idb
RGBAColor colorPink = {  1.0,  0.588,  0.588,  1.0 }; // idb
RGBAColor colorCyan = {  0.24699999,  0.86299998,  0.86299998,  1.0 }; // idb
RGBAColor colorBlueGrey = {  0.70599997,  0.86299998,  0.94099998,  1.0 }; // idb
RGBAColor colorGrey = {  0.824,  0.824,  0.78399998,  1.0 }; // idb
RGBAColor colorOrange = {  0.93300003,  0.57300001,  0.118,  1.0 }; // idb
RGBAColor colorGreen = {  0.5,  1.0,  0.498,  1.0 }; // idb
unsigned int s_BlitMethod = 4u; // idb
RGBAColor RGBAColor_RadarBlue_1 = {  0.25,  0.66000003,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarGold_1 = {  1.0,  0.67000002,  0.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarYellow_1 = {  1.0,  1.0,  0.5,  1.0 }; // idb
RGBAColor RGBAColor_RadarWhite_1 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarRed_1 = {  1.0,  0.25,  0.38999999,  1.0 }; // idb
RGBAColor RGBAColor_RadarPurple_1 = {  0.75,  0.38999999,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarPink_1 = {  1.0,  0.66000003,  0.75,  1.0 }; // idb
RGBAColor RGBAColor_RadarCyan_1 = {  0.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor RGBAColor_RadarBrightGreen_1 = {  0.0,  1.0,  0.0,  1.0 }; // idb
int GenItemHolder::splitSize = 1; // idb
unsigned int GenItemHolder::maxSplitSize = 1u; // idb
const int LOWEST_DATA_RATE = 1024; // idb
bool LScape::m_fFogEnabled = true; // weak
bool LScape::weather_enabled = true; // weak
int yoffarr[8] = { 0, 0, 0, 0, 0, 1, 0, 4294967295 }; // idb
int dword_81CC70[] = { 0 }; // weak
int dword_81CC74[] = { 0 }; // weak
int dword_81CC78[] = { 0 }; // weak
int jyarr[8] = { 0, 4294967295, 0, 1, 0, 1, 0, 4294967295 }; // idb
int dword_81CC90[] = { 4294967295 }; // weak
int dword_81CC94[] = { 0 }; // weak
int dword_81CC98[] = { 1 }; // weak
int iyarr[8] = { 1, 0, 4294967295, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81CCB0[] = { 0 }; // weak
int dword_81CCB4[] = { 4294967295 }; // weak
int dword_81CCB8[] = { 0 }; // weak
int xoffarr[8] = { 0, 0, 0, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81CCD0[] = { 0 }; // weak
int dword_81CCD4[] = { 0 }; // weak
int dword_81CCD8[] = { 0 }; // weak
int ixarr[8] = { 0, 4294967295, 0, 1, 0, 4294967295, 0, 1 }; // idb
int dword_81CCF0[] = { 4294967295 }; // weak
int dword_81CCF4[] = { 0 }; // weak
int dword_81CCF8[] = { 1 }; // weak
int jxarr[8] = { 4294967295, 0, 1, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81CD10[] = { 0 }; // weak
int dword_81CD14[] = { 1 }; // weak
int dword_81CD18[] = { 0 }; // weak
bool GameSky::s_weatherEnabled = true; // weak
const int LOWEST_DATA_RATE_0 = 1024; // idb
const int LOWEST_DATA_RATE_1 = 1024; // idb
const int LOWEST_DATA_RATE_2 = 1024; // idb
const int LOWEST_DATA_RATE_3 = 1024; // idb
const int LOWEST_DATA_RATE_4 = 1024; // idb
const int LOWEST_DATA_RATE_5 = 1024; // idb
const int LOWEST_DATA_RATE_6 = 1024; // idb
const int LOWEST_DATA_RATE_7 = 1024; // idb
const int LOWEST_DATA_RATE_8 = 1024; // idb
const int LOWEST_DATA_RATE_9 = 1024; // idb
const int LOWEST_DATA_RATE_10 = 1024; // idb
const int LOWEST_DATA_RATE_11 = 1024; // idb
const int LOWEST_DATA_RATE_12 = 1024; // idb
CAnimHook anim_done_hook = { &AnimDoneHook::vftable, NULL, 4294967294 }; // idb
const int LOWEST_DATA_RATE_13 = 1024; // idb
const int LOWEST_DATA_RATE_14 = 1024; // idb
const int LOWEST_DATA_RATE_15 = 1024; // idb
int CEnvCell::master_incell_timestamp = 1; // weak
const int LOWEST_DATA_RATE_16 = 1024; // idb
HashTable<unsigned long,RenderVertexStreamD3D *,0> CEnvCell::visible_cell_table =
{
  &HashTable<unsigned long,CEnvCell *,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
int (__thiscall **CEnvCell::cell_flush_table)(void *, char) = &HashTable<unsigned long,CEnvCell *,0>::vftable; // weak
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> stru_81DDA4 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
const int LOWEST_DATA_RATE_17 = 1024; // idb
int use_scene_files = 1; // weak
const int LOWEST_DATA_RATE_18 = 1024; // idb
int yoffarr_0[8] = { 0, 0, 0, 0, 0, 1, 0, 4294967295 }; // idb
int dword_81DF8C[] = { 0 }; // weak
int dword_81DF90[] = { 0 }; // weak
int dword_81DF94[] = { 0 }; // weak
int jyarr_0[8] = { 0, 4294967295, 0, 1, 0, 1, 0, 4294967295 }; // idb
int dword_81DFAC[] = { 4294967295 }; // weak
int dword_81DFB0[] = { 0 }; // weak
int dword_81DFB4[] = { 1 }; // weak
int iyarr_0[8] = { 1, 0, 4294967295, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81DFCC[] = { 0 }; // weak
int dword_81DFD0[] = { 4294967295 }; // weak
int dword_81DFD4[] = { 0 }; // weak
int xoffarr_0[8] = { 0, 0, 0, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81DFEC[] = { 0 }; // weak
int dword_81DFF0[] = { 0 }; // weak
int dword_81DFF4[] = { 0 }; // weak
int ixarr_0[8] = { 0, 4294967295, 0, 1, 0, 4294967295, 0, 1 }; // idb
int dword_81E00C[] = { 4294967295 }; // weak
int dword_81E010[] = { 0 }; // weak
int dword_81E014[] = { 1 }; // weak
int jxarr_0[8] = { 4294967295, 0, 1, 0, 1, 0, 4294967295, 0 }; // idb
int dword_81E02C[] = { 0 }; // weak
int dword_81E030[] = { 1 }; // weak
int dword_81E034[] = { 0 }; // weak
const int LOWEST_DATA_RATE_19 = 1024; // idb
const int LOWEST_DATA_RATE_20 = 1024; // idb
const int LOWEST_DATA_RATE_21 = 1024; // idb
const int LOWEST_DATA_RATE_22 = 1024; // idb
unsigned __int32 CVertexArray::vertex_size = 32u; // weak
int Palette::curr_solid_index = 4294967295; // weak
unsigned __int32 ImgTex::min_tex_size = 8u; // weak
HashTable<unsigned long,RenderVertexStreamD3D *,0> ImgTex::temp_buffer_table =
{
  &HashTable<enum  PixelFormatID,HashTable<unsigned long,ImgTex *,0> *,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<enum PixelFormatID,HashTableData<enum PixelFormatID,HashTable<unsigned long,ImgTex *,0> *> *,0> stru_81E984 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
HashTable<unsigned __int64,ImgTex *,1> ImgTex::texture_table =
{
  &AutoGrowHashTable<unsigned __int64,ImgTex *>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
HashSet<ImgTex *> ImgTex::custom_texture_table =
{
  &HashSet<ImgTex *>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> stru_81EA74 =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
const int LOWEST_DATA_RATE_23 = 1024; // idb
const int LOWEST_DATA_RATE_24 = 1024; // idb
const int LOWEST_DATA_RATE_25 = 1024; // idb
const int LOWEST_DATA_RATE_26 = 1024; // idb
const int LOWEST_DATA_RATE_27 = 1024; // idb
const int LOWEST_DATA_RATE_28 = 1024; // idb
const int LOWEST_DATA_RATE_29 = 1024; // idb
const int LOWEST_DATA_RATE_30 = 1024; // idb
const int LOWEST_DATA_RATE_31 = 1024; // idb
const int LOWEST_DATA_RATE_32 = 1024; // idb
const int LOWEST_DATA_RATE_33 = 1024; // idb
const int LOWEST_DATA_RATE_34 = 1024; // idb
const int LOWEST_DATA_RATE_35 = 1024; // idb
const int LOWEST_DATA_RATE_36 = 1024; // idb
float Render::s_rDegradeDistance =  50.0; // weak
float Render::max_framerate =  20.0; // weak
float Render::min_framerate =  8.0; // weak
float Render::ideal_framerate =  10.0; // weak
bool Render::auto_update_deg_mul = true; // weak
int Render::force_level = 4294967295; // weak
float Render::object_scale =  1.0; // weak
float Render::fov =  1.1781294; // weak
float Render::scale =  4000.0; // weak
float Render::vdst =  0.0625; // weak
float Render::znear =  0.1; // idb
float Render::zfar =  4000.0; // idb
int Render::FrameEraNext = 1; // weak
int Render::CachedMatrixFrameEra = 4294967295; // weak
int Render::max_static_lights = 40; // idb
int Render::max_dynamic_lights = 7; // idb
enum Render::LightingType Render::lighting_type = FULL_LIGHTING; // weak
BlendMode Render::curr_detail_src_blend = BLEND_SRCALPHA; // idb
BlendMode Render::curr_detail_dst_blend = BLEND_INVSRCALPHA; // idb
float Render::landscape_detail_tiling =  2.0; // weak
float Render::environment_detail_tiling =  2.0; // weak
float Render::building_detail_tiling =  2.0; // weak
float Render::object_detail_tiling =  2.0; // weak
float Render::curr_detail_tiling =  2.0; // idb
float Render::TextureUSize =  1.0; // weak
float Render::TextureVSize =  1.0; // weak
IDClass<_tagCellID,16,65535> Invalid_CellID_2 = { { 65535u } }; // idb
struct Vector3 Render::object_scale_vec = {  1.0,  1.0,  1.0 }; // weak
int dword_81EEB4 = 1065353216; // weak
int dword_81EEB8 = 1065353216; // weak
Frame simple_clip_plane_list_frame =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
Position Render::viewer_pos =
{
  { &Position::vftable },
  0u,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  }
}; // idb
unsigned int dword_81EF04 = 0u; // idb
Frame stru_81EF08 =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
struct Position Render::player_pos =
{
  { &Position::vftable },
  0u,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  }
}; // weak
unsigned int cell_from = 0u; // idb
Frame stru_81EF50 =
{
   1.0,
   0.0,
   0.0,
   0.0,
  {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
  { {  0.0,  0.0,  0.0 } }
}; // idb
struct RenderPrefs Render::m_RenderPrefs = { 1u, false, true, false, 2u, 1u, 1u, 8u, 1u, 0u, 0u,  0.0,  90.0, 2u }; // weak
char byte_81EF94 = '\0'; // weak
char byte_81EF95 = '\x01'; // weak
char byte_81EF96 = '\0'; // weak
int dword_81EF98 = 2; // weak
int dword_81EF9C = 1; // weak
int dword_81EFA0 = 1; // weak
int mid_radius = 8; // idb
int dword_81EFA8 = 1; // weak
int dword_81EFAC = 0; // weak
float fBrightness =  0.0; // idb
float degrees =  90.0; // idb
struct RGBColor Render::diffuse = {  1.0,  1.0,  1.0 }; // weak
float flt_81EFC4 =  1.0; // weak
float flt_81EFC8 =  1.0; // weak
int doSun = 1; // idb
int doStatic = 1; // idb
int doDynamic = 1; // idb
int lightCacheing = 1; // idb
bool IsFirstTime = true; // idb
unsigned int Current_Render_EnvironmentTextureDetail = 4294967295u; // idb
unsigned int Current_Render_LandscapeTextureDetail = 4294967295u; // idb
int newmethod = 1; // idb
RGBAColor stru_81F040 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor stru_81F050 = {  0.0,  0.0,  0.0,  1.0 }; // idb
int SoundManager::VOL_MIN = 4294967246; // weak
bool SoundManager::effect_sounds_enabled = true; // weak
float SoundManager::effect_sound_volume =  1.0; // idb
bool SoundManager::ambient_sounds_enabled = true; // weak
float SoundManager::ambient_sound_volume =  1.0; // weak
bool SoundManager::interface_sounds_enabled = true; // weak
_UNKNOWN SoundManager::interface_sound_volume; // weak
bool SoundManager::s_bPlaySoundOnlyWhenActive = true; // weak
Position SoundManager::player_position_ =
{
  { &Position::vftable },
  0u,
  {
     1.0,
     0.0,
     0.0,
     0.0,
    {  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0,  0.0 },
    { {  0.0,  0.0,  0.0 } }
  }
}; // idb
float Ambient::ambient_sound_min_dist =  20.0; // weak
float Ambient::ambient_sound_min_dist_sq =  400.0; // weak
float Ambient::ambient_sound_max_dist_sq =  14400.0; // weak
float Ambient::ambient_sound_min_vol =  0.029999999; // weak
const float upper_bound =  0.39269909; // idb
int SoundBuf::useDatabase = 1; // weak
unsigned int uMIDIDeviceID = 4294967295u; // idb
unsigned int dwQueuedTempoMultiplier = 100u; // idb
HANDLE hInFile = (HANDLE)0xFFFFFFFF; // idb
const int LOWEST_DATA_RATE_37 = 1024; // idb
int InterpolationManager::fUseAdjustedSpeed_ = 1; // weak
const int LOWEST_DATA_RATE_38 = 1024; // idb
const int LOWEST_DATA_RATE_39 = 1024; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_3 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_4 = { { 65535u } }; // idb
volatile LONG ATL::g_pfnGetThreadACP = 5610064; // idb
const int LOWEST_DATA_RATE_40 = 1024; // idb
const int LOWEST_DATA_RATE_41 = 1024; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_5 = { { 65535u } }; // idb
PackableHashIterator<unsigned long,SquelchInfo> global_Squelch_Iter = { &PackableHashIterator<unsigned long,SquelchInfo>::vftable, NULL, NULL, 0u }; // idb
int (__thiscall *(*ACCWeenieObject::iconDataTable)[2])(void *, char) = &LongHash<CWeenieObject>::vftable; // weak
int dword_8206C0 = 0; // weak
int dword_8206C4 = 0; // weak
void *dword_8206C8 = NULL; // idb
int dword_8206CC = 0; // weak
int dword_8206D0 = 0; // weak
HashSet<unsigned long> ACCWeenieObject::m_openedCorpses =
{
  &HashSet<unsigned long>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashSetData<IDClass<_tagDataID,32,0> > *,1> stru_8206DC =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
float rangeAdjust =  1.5; // idb
float ambientBoostFactor =  1.0; // idb
Matrix4 Matrix4_IdentityMatrix___5 =
{
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0
}; // idb
unsigned __int32 D3DPolyRender::s_AlphaDelayMask = 14u; // weak
__int32 D3DPolyRender::s_256AlphaTestRef = 100; // weak
__int32 D3DPolyRender::s_ddsAlphaTestRef = 200; // weak
__int32 curr_alpha = 255; // weak
__int32 curr_color = 4294967295; // weak
RGBAColor stru_820DF0 = {  1.0,  1.0,  1.0,  1.0 }; // idb
int colorSel = 4294967295; // idb
int maxZ2 = 6; // idb
int maxZ1 = 7; // idb
DepthTestMode zfuncVal = DEPTHTEST_LESS; // idb
unsigned int testRef = 20u; // idb
float static_light_factor =  1.3; // idb
float diffuseVal =  1.0; // idb
int onlyOnce = 1; // idb
int skipNoTexture = 1; // idb
int gfxobjs = 1; // idb
int noFadeDetail = 1; // idb
int trydetailing = 1; // idb
int trysinglepass = 1; // idb
__int32 RenderDeviceD3D::building_view = 4294967295; // weak
__int32 RenderDeviceD3D::backup_building_view = 4294967295; // weak
bool RenderDeviceD3D::s_bAllowDrawPrimitiveUP = true; // weak
RGBAColor Color = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor AmbientLightBoost = {  0.0,  0.0,  0.0,  1.0 }; // idb
float flush =  0.75; // idb
int alwaysDrawObjects = 1; // idb
int cliplandscape = 1; // idb
RGBAColor stru_820FC0 = {  0.0,  0.0,  0.0,  1.0 }; // idb
const int LOWEST_DATA_RATE_42 = 1024; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_UNDEAD_SETUP_0 = { { 33561102u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_UNDEAD_GEN_SETUP_0 = { { 33561103u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_SETUP_0 = { { 33561244u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_NOFLAME_SETUP_0 = { { 33561246u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_SETUP_0 = { { 33561245u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_NOFLAME_SETUP_0 = { { 33561238u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_UNDEAD_SETUP_0 = { { 33561100u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_UNDEAD_GEN_SETUP_0 = { { 33561101u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_SETUP_0 = { { 33561248u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_NOFLAME_SETUP_0 = { { 33561247u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_SETUP_0 = { { 33561249u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_NOFLAME_SETUP_0 = { { 33561250u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CROWN_SETUP_0 = { { 33560943u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CROWN_GEN_SETUP_0 = { { 33560946u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_NOCROWN_SETUP_0 = { { 33561183u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_VOID_SETUP_0 = { { 33561199u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CROWN_SETUP_0 = { { 33560944u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CROWN_GEN_SETUP_0 = { { 33560944u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_NOCROWN_SETUP_0 = { { 33561182u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_VOID_SETUP_0 = { { 33561198u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CROWN_SETUP_0 = { { 33560942u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CROWN_GEN_SETUP_0 = { { 33560945u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_NOCROWN_SETUP_0 = { { 33561181u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_VOID_SETUP_0 = { { 33561200u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CROWN_SETUP_0 = { { 33560941u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CROWN_GEN_SETUP_0 = { { 33560941u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_NOCROWN_SETUP_0 = { { 33561180u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_VOID_SETUP_0 = { { 33561201u } }; // idb
IDClass<_tagDataID,32,0> HUMAN_MALE_CLOTHING_DEFAULT_0 = { { 33554433u } }; // idb
IDClass<_tagDataID,32,0> HUMAN_FEMALE_CLOTHING_DEFAULT_0 = { { 33554510u } }; // idb
IDClass<_tagDataID,32,0> ANAKSHAY_MALE_SETUP_0 = { { 33561251u } }; // idb
IDClass<_tagDataID,32,0> ANAKSHAY_FEMALE_SETUP_0 = { { 33561252u } }; // idb
float PhysicsGlobals::gravity = -9.8000002; // weak
NetError ID_NetError_None = { { &NetError::vftable }, 0u, 0 }; // idb
const int LOWEST_DATA_RATE_43 = 1024; // idb
const int LOWEST_DATA_RATE_44 = 1024; // idb
const int LOWEST_DATA_RATE_45 = 1024; // idb
const int LOWEST_DATA_RATE_46 = 1024; // idb
unsigned __int8 *bittab = (unsigned __int8 *)0x2020100; // weak
int start = 1; // idb
bool first = true; // idb
char *rgWorkmanshipStrings = &name; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_6 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_7 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_8 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_9 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_10 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_11 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_12 = { { 65535u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_UNDEAD_SETUP_1 = { { 33561102u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_SETUP_1 = { { 33561244u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_UNDEAD_SETUP_1 = { { 33561100u } }; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_SETUP_1 = { { 33561248u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CROWN_SETUP_1 = { { 33560943u } }; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CROWN_SETUP_1 = { { 33560944u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CROWN_SETUP_1 = { { 33560942u } }; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CROWN_SETUP_1 = { { 33560941u } }; // idb
unsigned int startAtrb = 1u; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_13 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_14 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_15 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_16 = { { 65535u } }; // idb
struct TCoord *Directions = (struct TCoord *)1; // weak
int dword_822BBC[] = { 0 }; // weak
_UNKNOWN unk_822BC4; // weak
_UNKNOWN unk_822BF8; // weak
TCoord HEAVEN = { 4294967286, 4294967276 }; // idb
_UNKNOWN CombatSystem::AUGMENTATION_CRITICAL_DEFENSE_PK_AVOID_CHANCE; // weak
double CombatSystem::ElementalModPKModifier =  0.25; // weak
IDClass<_tagCellID,16,65535> Invalid_CellID_17 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_18 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_19 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_20 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_21 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_22 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_23 = { { 65535u } }; // idb
const char **gc_CategoryNames = &aFrameStats; // weak
char *off_823A64 = "*World"; // weak
char *off_823A68 = "*Landscape"; // weak
char *off_823A6C = "*Sky Objects"; // weak
char *off_823A70 = "*Engine UI"; // weak
const char **gc_ToolbarToggleButtonNames = &aWireframe; // weak
const char **gc_ToolbarStatsButtonNames = &aMemoryCounters; // weak
RGBAColor stru_823AF0 = {  1.0,  1.0,  1.0,  1.0 }; // idb
int dword_823B10 = 1; // weak
IDClass<_tagCellID,16,65535> Invalid_CellID_24 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_25 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_26 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_27 = { { 65535u } }; // idb
HashTable<PStringBase<char>,UIPreferenceItem *,0> UIPreferences::m_uiPreferences =
{
  &HashTable<PStringBase<char>,UIPreferenceItem *,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
int __defaultmatherr = 1; // weak
int (__stdcall *g_D3DXFastTable)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec2Transform; // weak
int (__stdcall *off_8241DC)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec3Transform; // weak
int (__stdcall *off_8241E0)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec4Transform; // weak
int (__stdcall *off_8241E4)(_DWORD, _DWORD, _DWORD) = &init_D3DXMatrixMultiply; // weak
int (__stdcall *off_8241E8)(_DWORD, _DWORD, _DWORD) = &init_D3DXMatrixMultiplyTranspose; // weak
int (__stdcall *off_8241EC)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec2TransformNormal; // weak
int (__stdcall *off_8241F0)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec3TransformNormal; // weak
int (__stdcall *off_8241F4)(_DWORD, _DWORD) = &init_D3DXVec3Normalize; // weak
int (__stdcall *off_8241F8)(_DWORD, _DWORD) = &init_D3DXVec4Normalize; // weak
int (__stdcall *off_8241FC)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec2TransformCoord; // weak
int (__stdcall *off_824200)(_DWORD, _DWORD, _DWORD) = &init_D3DXVec3TransformCoord; // weak
int (__stdcall *off_824204)(_DWORD) = &init_D3DXMatrixDeterminant; // weak
int (__stdcall *off_824208)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixDecompose; // weak
int (__stdcall *off_82420C)(_DWORD, _DWORD, _DWORD) = &init_D3DXPlaneFromPointNormal; // weak
int (__stdcall *off_824210)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXPlaneFromPoints; // weak
int (__stdcall *off_824214)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3Project; // weak
int (__stdcall *off_824218)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3Unproject; // weak
int (__stdcall *off_82421C)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec4Cross; // weak
int (__stdcall *off_824220)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2Hermite; // weak
int (__stdcall *off_824224)(_DWORD, _DWORD, _DWORD) = &init_D3DXMatrixInverse; // weak
int (__stdcall *off_824228)(_DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionMultiply; // weak
int (__stdcall *off_82422C)(_DWORD, _DWORD) = &init_D3DXQuaternionNormalize; // weak
int (__stdcall *off_824230)(_DWORD, _DWORD) = &init_D3DXPlaneNormalize; // weak
int (__stdcall *off_824234)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXPlaneIntersectLine; // weak
int (__stdcall *off_824238)(_DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionToAxisAngle; // weak
int (__stdcall *off_82423C)(_DWORD, _DWORD) = &init_D3DXQuaternionRotationMatrix; // weak
int (__stdcall *off_824240)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionRotationYawPitchRoll; // weak
int (__stdcall *off_824244)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixTranslation; // weak
int (__stdcall *off_824248)(_DWORD, _DWORD, _DWORD) = &init_D3DXMatrixShadow; // weak
int (__stdcall *off_82424C)(_DWORD, _DWORD) = &init_D3DXMatrixReflect; // weak
int (__stdcall *off_824250)(_DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionRotationAxis; // weak
int (__stdcall *off_824254)(_DWORD, _DWORD) = &init_D3DXMatrixRotationX; // weak
int (__stdcall *off_824258)(_DWORD, _DWORD) = &init_D3DXMatrixRotationY; // weak
int (__stdcall *off_82425C)(_DWORD, _DWORD) = &init_D3DXMatrixRotationZ; // weak
int (__stdcall *off_824260)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixScaling; // weak
int (__stdcall *off_824264)(_DWORD, _DWORD, _DWORD) = &init_D3DXPlaneTransform; // weak
int (__stdcall *off_824268)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionSlerp; // weak
int (__stdcall *off_82426C)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionBaryCentric; // weak
int (__stdcall *off_824270)(_DWORD, _DWORD) = &init_D3DXMatrixTranspose; // weak
int (__stdcall *off_824274)(_DWORD, _DWORD) = &init_D3DXMatrixRotationQuaternion; // weak
int (__stdcall *off_824278)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixTransformation; // weak
int (__stdcall *off_82427C)(_DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixRotationYawPitchRoll; // weak
int (__stdcall *off_824280)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixAffineTransformation; // weak
int (__stdcall *off_824284)(_DWORD, _DWORD, _DWORD) = &init_D3DXMatrixRotationAxis; // weak
int (__stdcall *off_824288)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionSquad; // weak
int (__stdcall *off_82428C)(_DWORD, _DWORD) = &init_D3DXQuaternionInverse; // weak
int (__stdcall *off_824290)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXQuaternionSquadSetup; // weak
int (__stdcall *off_824294)(_DWORD, _DWORD) = &init_D3DXVec2Normalize; // weak
int (__stdcall *off_824298)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2CatmullRom; // weak
int (__stdcall *off_82429C)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2BaryCentric; // weak
int (__stdcall *off_8242A0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3Hermite; // weak
int (__stdcall *off_8242A4)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3CatmullRom; // weak
int (__stdcall *off_8242A8)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3BaryCentric; // weak
int (__stdcall *off_8242AC)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec4Hermite; // weak
int (__stdcall *off_8242B0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec4CatmullRom; // weak
int (__stdcall *off_8242B4)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec4BaryCentric; // weak
int (__stdcall *off_8242B8)(_DWORD, _DWORD) = &init_D3DXQuaternionLn; // weak
int (__stdcall *off_8242BC)(_DWORD, _DWORD) = &init_D3DXQuaternionExp; // weak
int (__stdcall *off_8242C0)(_DWORD, _DWORD, _DWORD) = &init_D3DXFloat32To16Array; // weak
int (__stdcall *off_8242C4)(_DWORD, _DWORD, _DWORD) = &init_D3DXFloat16To32Array; // weak
int (__stdcall *off_8242C8)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2TransformArray; // weak
int (__stdcall *off_8242CC)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2TransformCoordArray; // weak
int (__stdcall *off_8242D0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec2TransformNormalArray; // weak
int (__stdcall *off_8242D4)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3TransformArray; // weak
int (__stdcall *off_8242D8)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3TransformCoordArray; // weak
int (__stdcall *off_8242DC)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3TransformNormalArray; // weak
int (__stdcall *off_8242E0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec4TransformArray; // weak
int (__stdcall *off_8242E4)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3ProjectArray; // weak
int (__stdcall *off_8242E8)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXVec3UnprojectArray; // weak
int (__stdcall *off_8242EC)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXPlaneTransformArray; // weak
int (__stdcall *off_8242F0)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXPSGPUpdateSkinnedMesh; // weak
int (__stdcall *off_8242F4)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXPSGPTessellateNPatch; // weak
int (__stdcall *off_8242F8)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixTransformation2D; // weak
int (__stdcall *off_8242FC)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD) = &init_D3DXMatrixAffineTransformation2D; // weak
_UNKNOWN g_D3DXFastTableC; // weak
int dword_824428 = 4294967295; // weak
__int32 (__stdcall *D3DXTex::g_pBoxFilter2D_A8R8G8B8)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int) = &sub_5EF387; // weak
__int32 (__stdcall *D3DXTex::g_pBoxFilter2D_X8R8G8B8)(unsigned int *, unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int) = &sub_5EF3C1; // weak
_UNKNOWN unk_824C68; // weak
_UNKNOWN unk_824CE8; // weak
int dword_824D68 = 4294967295; // weak
_UNKNOWN g_CpuOptimization; // weak
float flt_825AA8 = -1.4100952; // weak
float flt_825AAC =  2.1192613; // weak
float flt_826AB0 =  0.29703665; // weak
float flt_826AB4 =  1.0; // weak
float flt_826AB8 =  0.10078278; // weak
float flt_826AC0 =  3.3665881; // weak
float flt_826AC4 =  1.0; // weak
float flt_826AC8 =  9.9223299; // weak
int dword_827CC0 = 1056964608; // weak
int dword_827CD0 = 1077936128; // weak
__int128 xmmword_827CE0 = 0x3F800000BF800000BF800000BF800000i64; // weak
__int128 xmmword_827CF0 = 0x3F800000C00000003F80000040000000i64; // weak
__int128 xmmword_827D00 = 0xBF80000040400000C0000000C0400000i64; // weak
__int128 xmmword_827D10 = 4575657221408423936i64; // weak
int dword_827D20 = 1065353216; // weak
__int128 xmmword_827D30 = 0x3F000000BFC000003FC00000BF000000i64; // weak
__int128 xmmword_827D40 = 0xBF00000040000000C02000003F800000i64; // weak
__int128 xmmword_827D50 = 0x3F000000BF000000i64; // weak
__int128 xmmword_827D60 = 4575657221408423936i64; // weak
__int128 xmmword_827D70 = 0x80000000800000008000000080000000i64; // weak
__int128 xmmword_827D80 = 0xFFFFFFFFFFFFFFFFFFFFFFFFi64; // weak
__int128 xmmword_827D90 = 0xC0000000C0000000C0000000i64; // weak
__int128 xmmword_827DA0 = 0x3F8000000000000000000000i64; // weak
__int128 xmmword_827DB0 = 0x3F80000000000000i64; // weak
__int128 xmmword_827DC0 = 4575657221408423936i64; // weak
__int128 xmmword_827DD0 = 1065353216i64; // weak
__int128 xmmword_827DE0 = 0x40400000404000004040000040400000i64; // weak
__int128 xmmword_827DF0 = 0x3EAAAAAB3EAAAAAB3EAAAAAB3EAAAAABi64; // weak
int dword_827E00 = 1065353216; // weak
int dword_827E10 = 1086324736; // weak
__int128 xmmword_827E20 = 0x3E8000003E8000003E8000003E800000i64; // weak
__int128 xmmword_827E30 = 0x3E2AAA7E3E2AAA7E3E2AAA7E3E2AAA7Ei64; // weak
__int128 xmmword_827E40 = 0x80000000000000008000000000000000i64; // weak
int dword_827E50 = 1056964608; // weak
int dword_827E60 = 1077936128; // weak
_UNKNOWN unk_827E70; // weak
__int128 xmmword_827FA0 = 0x80000000800000008000000080000000i64; // weak
__int128 xmmword_827FB0 = 0xFFFFFFFFFFFFFFFFFFFFFFFFi64; // weak
__int128 xmmword_827FC0 = 0xC0000000C0000000C0000000i64; // weak
__int128 xmmword_827FD0 = 0x3F8000000000000000000000i64; // weak
__int128 xmmword_827FE0 = 0x3F80000000000000i64; // weak
__int128 xmmword_827FF0 = 4575657221408423936i64; // weak
__int128 xmmword_828000 = 1065353216i64; // weak
__int128 xmmword_828010 = 0x80000000000000008000000000000000i64; // weak
_UNKNOWN unk_828020; // weak
float AMDSSE_two =  2.0; // idb
float AMDSSE_two_0 =  2.0; // idb
unsigned int AMDX3D_MaskExponentF16 = 31744u; // idb
unsigned int AMDX3D_F16toF32ExpBias = 114688u; // idb
unsigned int AMDX3D_MaskSignF16 = 32768u; // idb
unsigned int AMDX3D_ExpIncF16 = 1024u; // idb
unsigned int AMDX3D_NormalizeF16 = 947912704u; // idb
unsigned int AMDX3D_MaskLargest16 = 1199566847u; // idb
unsigned int AMDX3D_MaskSmallest16 = 947912704u; // idb
unsigned int AMDX3D_MaskSignF32 = 2147483648u; // idb
unsigned int AMDX3D_One16 = 1u; // idb
unsigned int AMDX3D_BiasDiff = 3355447295u; // idb
unsigned int AMDX3D_Mask32 = 2147483647u; // idb
unsigned int AMDX3D_OneShift23 = 8388608u; // idb
unsigned int AMDX3D_Inf16 = 32767u; // idb
__int128 xmmword_8310C0 = 0x3F8000003F8000003F8000003F800000i64; // weak
__int128 xmmword_8310D0 = 0xBF000000BF000000BF000000BF000000i64; // weak
__int128 xmmword_8310E0 = 0x3F8000003F8000003F8000003F800000i64; // weak
__int128 xmmword_8310F0 = 0x3D2AAAA53D2AAAA53D2AAAA53D2AAAA5i64; // weak
__int128 xmmword_831100 = 0xBE2AAAA3BE2AAAA3BE2AAAA3BE2AAAA3i64; // weak
__int128 xmmword_831110 = 0xBAB6061ABAB6061ABAB6061ABAB6061Ai64; // weak
__int128 xmmword_831120 = 0x3C08839D3C08839D3C08839D3C08839Di64; // weak
int dword_831130 = 2; // weak
__int128 xmmword_831140 = 0x100000001100000001i64; // weak
__int128 xmmword_831150 = 0x7FFFFF007FFFFF7FFFFF007FFFFFi64; // weak
__int128 xmmword_831160 = 0x37CCF5CE37CCF5CE37CCF5CE37CCF5CEi64; // weak
__int128 xmmword_831170 = 0xB94CA1F0B94CA1F0B94CA1F0B94CA1F0i64; // weak
__int128 xmmword_831180 = 0x4B0000004B0000004B0000004B000000i64; // weak
__int128 xmmword_831190 = 0x2C34611A2C34611A2C34611A2C34611Ai64; // weak
__int128 xmmword_8311A0 = 0x33A2200033A2200033A2200033A22000i64; // weak
__int128 xmmword_8311B0 = 0x39FDA00039FDA00039FDA00039FDA000i64; // weak
__int128 xmmword_8311C0 = 0x3FC900003FC900003FC900003FC90000i64; // weak
__int128 xmmword_8311D0 = 0x3F22F9833F22F9833F22F9833F22F983i64; // weak
__int128 xmmword_8311E0 = 0x80000000800000008000000080000000i64; // weak
__int128 xmmword_8311F0 = 0x7FFFFFFF7FFFFFFF7FFFFFFF7FFFFFFFi64; // weak
__int128 xmmword_831200 = 0x3F8000003F8000003F8000003F800000i64; // weak
__int128 xmmword_831210 = 0xBF000000BF000000BF000000BF000000i64; // weak
__int128 xmmword_831220 = 0x3F8000003F8000003F8000003F800000i64; // weak
__int128 xmmword_831230 = 0x3D2AAAA53D2AAAA53D2AAAA53D2AAAA5i64; // weak
__int128 xmmword_831240 = 0xBE2AAAA3BE2AAAA3BE2AAAA3BE2AAAA3i64; // weak
__int128 xmmword_831250 = 0xBAB6061ABAB6061ABAB6061ABAB6061Ai64; // weak
__int128 xmmword_831260 = 0x3C08839D3C08839D3C08839D3C08839Di64; // weak
__int128 xmmword_831270 = 0x200000002200000002i64; // weak
__int128 xmmword_831280 = 0x100000001100000001i64; // weak
__int128 xmmword_831290 = 0x7FFFFF007FFFFF7FFFFF007FFFFFi64; // weak
__int128 xmmword_8312A0 = 0x37CCF5CE37CCF5CE37CCF5CE37CCF5CEi64; // weak
__int128 xmmword_8312B0 = 0xB94CA1F0B94CA1F0B94CA1F0B94CA1F0i64; // weak
__int128 xmmword_8312C0 = 0x4B0000004B0000004B0000004B000000i64; // weak
__int128 xmmword_8312D0 = 0x2C34611A2C34611A2C34611A2C34611Ai64; // weak
__int128 xmmword_8312E0 = 0x33A2200033A2200033A2200033A22000i64; // weak
__int128 xmmword_8312F0 = 0x39FDA00039FDA00039FDA00039FDA000i64; // weak
__int128 xmmword_831300 = 0x3FC900003FC900003FC900003FC90000i64; // weak
__int128 xmmword_831310 = 0x3F22F9833F22F9833F22F9833F22F983i64; // weak
__int128 xmmword_831320 = 0x80000000800000008000000080000000i64; // weak
__int128 xmmword_831330 = 0x7FFFFFFF7FFFFFFF7FFFFFFF7FFFFFFFi64; // weak
__int64 sign_mask = 9223372034707292159i64; // idb
const char *const ijlkey = "Software\\Intel Corporation\\PLSuite\\IJLib"; // weak
char *usecpu = "USECPU"; // weak
_UNKNOWN unk_8322E0; // weak
int dword_832300 = 1000; // weak
__int64 qword_832320 = 7061751969500652032i64; // weak
__int64 qword_832328 = 5008079202860156288i64; // weak
__int64 qword_832330 = 6521311767753153152i64; // weak
__int64 qword_832338 = 6016900912788820864i64; // weak
__int64 qword_832340 = -9223231297218904064i64; // weak
__int64 qword_832348 = 6917634582367985664i64; // weak
__int64 qword_832350 = -4611474908973580288i64; // weak
__int64 qword_832358 = -2305596714850918400i64; // weak
__int64 qword_832360 = 281479271743489i64; // weak
__int64 qword_832370 = 6485282420969986560i64; // weak
__int64 qword_832378 = -6025626770212869024i64; // weak
__int64 qword_832380 = 4990064529468572992i64; // weak
__int64 qword_832388 = 8520940514218899008i64; // weak
__int64 qword_8323B0 = 36029346783166592i64; // weak
__int128 xmmword_8323D0 = 0x10001000100011000100010001i64; // weak
__int128 xmmword_8323E0 = 0x80000000800008000000080000i64; // weak
__int128 xmmword_8323F0 = 0x32EC32EC32EC32EC32EC32EC32EC32ECi64; // weak
__int128 xmmword_832400 = 0x6A0A6A0A6A0A6A0A6A0A6A0A6A0A6A0Ai64; // weak
__int128 xmmword_832410 = 0xAB0EAB0EAB0EAB0EAB0EAB0EAB0EAB0Ei64; // weak
__int128 xmmword_832430 = 0x5A825A825A825A825A825A825A825A82i64; // weak
__int64 qword_832440 = 5422994505513058304i64; // weak
__int64 qword_832448 = 1272322184919924736i64; // weak
__int64 qword_832450 = -1272184147311111265i64; // weak
__int64 qword_832458 = -3623243500459270819i64; // weak
__int64 qword_832460 = -6396463553414414336i64; // weak
__int64 qword_832468 = 5422916315633467392i64; // weak
__int64 qword_832470 = -3623407959052049757i64; // weak
__int64 qword_832478 = -6396436095195851873i64; // weak
__int64 qword_832480 = 7521709710815615173i64; // weak
__int64 qword_832488 = 1764924792106211525i64; // weak
__int64 qword_832490 = -1764733333053672452i64; // weak
__int64 qword_832498 = -5025589613507063819i64; // weak
__int64 qword_8324A0 = -8872296051449833275i64; // weak
__int64 qword_8324A8 = 7521601258596443963i64; // weak
__int64 qword_8324B0 = -5025708777374732277i64; // weak
__int64 qword_8324B8 = -8872257967291534340i64; // weak
__int64 qword_8324C0 = 7085415641332536223i64; // weak
__int64 qword_8324C8 = 1662463450911036319i64; // weak
__int64 qword_8324D0 = -1662283098777096895i64; // weak
__int64 qword_8324D8 = -4733973682026720577i64; // weak
__int64 qword_8324E0 = -8357482768545786977i64; // weak
__int64 qword_8324E8 = 7085313481240456289i64; // weak
__int64 qword_8324F0 = -4734102264757670591i64; // weak
__int64 qword_8324F8 = -8357446892040262335i64; // weak
__int64 qword_832500 = 6376648893781920578i64; // weak
__int64 qword_832508 = 1496104515399732034i64; // weak
__int64 qword_832510 = -1495942202344709548i64; // weak
__int64 qword_832518 = -4260520014963222714i64; // weak
__int64 qword_832520 = -7521509311709820094i64; // weak
__int64 qword_832528 = 6376556951417042110i64; // weak
__int64 qword_832530 = -4260663892072716102i64; // weak
__int64 qword_832538 = -7521477025861311916i64; // weak
__int128 xmmword_832540 = 0xCDB7A73BAC61DD5D4B4258C540004000i64; // weak
__int128 xmmword_832550 = 0xEE584B4222A3539F11A8324940004000i64; // weak
__int128 xmmword_832560 = 0xA73B4B42DD5D539FA73B3249C0004000i64; // weak
__int128 xmmword_832570 = 0xCDB711A8AC6122A34B4211A84000C000i64; // weak
__int128 xmmword_832580 = 0xBA4184DF8C04CFF568627B2158C558C5i64; // weak
__int128 xmmword_832590 = 0xE7826862300B73FC187E45BF58C558C5i64; // weak
__int128 xmmword_8325A0 = 0x84DF6862CFF573FC84DF45BFA73B58C5i64; // weak
__int128 xmmword_8325B0 = 0xBA41187E8C04300B6862187E58C5A73Bi64; // weak
__int128 xmmword_8325C0 = 0xBE4D8C0492BFD2BF625473FC539F539Fi64; // weak
__int128 xmmword_8325D0 = 0xE8EE62542D416D41171241B3539F539Fi64; // weak
__int128 xmmword_8325E0 = 0x8C046254D2BF6D418C0441B3AC61539Fi64; // weak
__int128 xmmword_8325F0 = 0xBE4D171292BF2D4162541712539FAC61i64; // weak
__int128 xmmword_832600 = 0xC4DF979E9DACD746587E68624B424B42i64; // weak
__int128 xmmword_832610 = 0xEB3D587E28BA625414C33B214B424B42i64; // weak
__int128 xmmword_832620 = 0x979E587ED7466254979E3B21B4BE4B42i64; // weak
__int128 xmmword_832630 = 0xC4DF14C39DAC28BA587E14C34B42B4BEi64; // weak
int dword_832640[] = { 0 }; // weak
int dword_832740[] = { 0 }; // weak
__int64 qword_832B40 = 255i64; // weak
__int64 qword_832B50 = 16711935i64; // weak
__int64 qword_832B60 = -256i64; // weak
__int64 qword_832B78 = -4278190081i64; // weak
__int64 qword_832B80 = 65535i64; // weak
__int64 qword_832B88 = 16711680i64; // weak
__int64 qword_832B90 = 4278190080i64; // weak
__int64 qword_832B98 = 281479271743489i64; // weak
__int64 qword_832BA0 = 562958543486978i64; // weak
__int64 qword_832BA8 = 844437815230467i64; // weak
__int64 qword_832BB0 = 1125917086973956i64; // weak
__int64 qword_832BB8 = 2251834173947912i64; // weak
__int64 qword_832BC0 = 4222189076152335i64; // weak
__int64 qword_832BC8 = 71777214294589695i64; // weak
__int128 xmmword_832BE0 = 0x10001000100011000100010001i64; // weak
__int128 xmmword_832BF0 = 0x8000000080080000000800i64; // weak
__int128 xmmword_832C00 = 0x1000100010001010001000100010i64; // weak
__int128 xmmword_832C10 = 0xF000F000F000FF000F000F000Fi64; // weak
__int128 xmmword_832C20 = 0x8000800080008080008000800080i64; // weak
__int128 xmmword_832C30 = 0i64; // weak
__int128 xmmword_832C40 = 0x32EC32EC32EC32EC32EC32EC32EC32ECi64; // weak
__int128 xmmword_832C50 = 0x6A0A6A0A6A0A6A0A6A0A6A0A6A0A6A0Ai64; // weak
__int128 xmmword_832C60 = 0xAB0EAB0EAB0EAB0EAB0EAB0EAB0EAB0Ei64; // weak
__int128 xmmword_832C70 = 0xB505B505B505B505B505B505B505B505i64; // weak
__int64 qword_832C90 = -4611615648609452032i64; // weak
__int64 qword_832C98 = -6025496742388870241i64; // weak
__int64 qword_832CA0 = 4611756390392807424i64; // weak
__int64 qword_832CA8 = -2495649084478595747i64; // weak
__int64 qword_832CB0 = -6396436098066065211i64; // weak
__int64 qword_832CB8 = -3623165313175499966i64; // weak
__int64 qword_832CC0 = 5422916314855912009i64; // weak
__int64 qword_832CC8 = -6396292658624288965i64; // weak
__int64 qword_832CD0 = -6396421241128527675i64; // weak
__int64 qword_832CD8 = -8357502183883967492i64; // weak
__int64 qword_832CE0 = 6396616451687143621i64; // weak
__int64 qword_832CE8 = -3461706787810652171i64; // weak
__int64 qword_832CF0 = -8872257969610327263i64; // weak
__int64 qword_832CF8 = -5025481163226060702i64; // weak
__int64 qword_832D00 = 7521601257518024127i64; // weak
__int64 qword_832D08 = -8872167950809660193i64; // weak
__int64 qword_832D10 = -6025442882677156961i64; // weak
__int64 qword_832D18 = -7872523865664950975i64; // weak
__int64 qword_832D20 = 6025626771701978015i64; // weak
__int64 qword_832D28 = -3260726254323510593i64; // weak
__int64 qword_832D30 = -8357446894473743364i64; // weak
__int64 qword_832D38 = -4733871524009581996i64; // weak
__int64 qword_832D40 = 7085313480224555443i64; // weak
__int64 qword_832D48 = -8357345768921330684i64; // weak
__int64 qword_832D50 = -5422814153204937918i64; // weak
__int64 qword_832D58 = -7085243333748301228i64; // weak
__int64 qword_832D60 = 5422979651179793218i64; // weak
__int64 qword_832D68 = -2934484743475636410i64; // weak
__int64 qword_832D70 = -7521477028480980894i64; // weak
__int64 qword_832D78 = -4260428074895320962i64; // weak
__int64 qword_832D80 = 6376556950502718241i64; // weak
__int64 qword_832D88 = -7521357864120707170i64; // weak
__int64 qword_832D90 = 2495908988640509952i64; // weak
__int64 qword_832D98 = -6025323719631355904i64; // weak
__int64 qword_832DA0 = -6025464453986959360i64; // weak
__int64 qword_832DA8 = -2495768248346230784i64; // weak
__int64 qword_832DB0 = -1272184146629601083i64; // weak
__int64 qword_832DB8 = -3623243503055130039i64; // weak
__int64 qword_832DC0 = -3623407959138422199i64; // weak
__int64 qword_832DC8 = -6396436097647111768i64; // weak
__int64 qword_832DD0 = 3461958343642077381i64; // weak
__int64 qword_832DD8 = -8357371135841838907i64; // weak
__int64 qword_832DE0 = -8357457401872033595i64; // weak
__int64 qword_832DE8 = -3461763133486618821i64; // weak
__int64 qword_832DF0 = -1764733332108444895i64; // weak
__int64 qword_832DF8 = -5025589615445260865i64; // weak
__int64 qword_832E00 = -5025708777494592065i64; // weak
__int64 qword_832E08 = -8872257969029244802i64; // weak
__int64 qword_832E10 = 3260979549390853023i64; // weak
__int64 qword_832E18 = -7872384090249276513i64; // weak
__int64 qword_832E20 = -7872481677719678049i64; // weak
__int64 qword_832E28 = -3260795660995023775i64; // weak
__int64 qword_832E30 = -1662283097886657540i64; // weak
__int64 qword_832E38 = -4733973684101693005i64; // weak
__int64 qword_832E40 = -4734102264870583885i64; // weak
__int64 qword_832E48 = -8357446893926344942i64; // weak
__int64 qword_832E50 = 2934740855674915650i64; // weak
__int64 qword_832E58 = -7085089384940549310i64; // weak
__int64 qword_832E60 = -7085205363308999870i64; // weak
__int64 qword_832E68 = -2934575358695656258i64; // weak
__int64 qword_832E70 = -1495942201543333790i64; // weak
__int64 qword_832E78 = -4260520017260233951i64; // weak
__int64 qword_832E80 = -4260663892174292191i64; // weak
__int64 qword_832E88 = -7521477027988368189i64; // weak
__int128 xmmword_832E90 = 0xDD5D4000539FC00022A34000539F4000i64; // weak
__int128 xmmword_832EA0 = 0xAC61C00022A34000AC614000DD5D4000i64; // weak
__int128 xmmword_832EB0 = 0xA73B4B424B4211A8EE584B424B4258C5i64; // weak
__int128 xmmword_832EC0 = 0xCDB7A73B11A83249CDB711A8A73B3249i64; // weak
__int128 xmmword_832ED0 = 0xCFF558C573FCA73B300B58C573FC58C5i64; // weak
__int128 xmmword_832EE0 = 0x8C04A73B300B58C58C0458C5CFF558C5i64; // weak
__int128 xmmword_832EF0 = 0x84DF68626862187EE782686268627B21i64; // weak
__int128 xmmword_832F00 = 0xBA4184DF187E45BFBA41187E84DF45BFi64; // weak
__int128 xmmword_832F10 = 0xD2BF539F6D41AC612D41539F6D41539Fi64; // weak
__int128 xmmword_832F20 = 0x92BFAC612D41539F92BF539FD2BF539Fi64; // weak
__int128 xmmword_832F30 = 0x8C04625462541712E8EE6254625473FCi64; // weak
__int128 xmmword_832F40 = 0xBE4D8C04171241B3BE4D17128C0441B3i64; // weak
__int128 xmmword_832F50 = 0xD7464B426254B4BE28BA4B4262544B42i64; // weak
__int128 xmmword_832F60 = 0x9DACB4BE28BA4B429DAC4B42D7464B42i64; // weak
__int128 xmmword_832F70 = 0x979E587E587E14C3EB3D587E587E6862i64; // weak
__int128 xmmword_832F80 = 0xC4DF979E14C33B21C4DF14C3979E3B21i64; // weak
__int64 qword_832F90 = 255i64; // weak
__int64 qword_832F98 = 65280i64; // weak
__int64 qword_832FA0 = 16711935i64; // weak
__int64 qword_832FA8 = 4278255360i64; // weak
__int64 qword_832FB0 = 124563882061i64; // weak
__int64 qword_832FB8 = 554045276117i64; // weak
__int64 qword_832FC0 = 281389070352512i64; // weak
__int64 qword_832FC8 = 330722312221i64; // weak
__int64 qword_832FD0 = 281294582513792i64; // weak
__int64 qword_832FD8 = 554043834347i64; // weak
__int64 qword_832FE0 = 140187732574080i64; // weak
__int64 qword_832FE8 = 549755814016i64; // weak
__int64 qword_832FF0 = 1099511628032i64; // weak
__int64 qword_832FF8 = 2199023256064i64; // weak
__int64 qword_833000 = 36029346783166592i64; // weak
__int64 qword_833008 = -1i64; // weak
__int64 qword_833010 = -72057589759737856i64; // weak
__int64 qword_833020 = 281470681808895i64; // weak
int dword_833040 = 0; // weak
__int64 qword_833048 = -1i64; // weak
__int64 qword_833050 = -72057589759737856i64; // weak
__int64 qword_833058 = 140187732574080i64; // weak
__int64 qword_833060 = 549755814016i64; // weak
__int64 qword_833068 = 2199023256064i64; // weak
__int64 qword_833070 = 124563882061i64; // weak
__int64 qword_833078 = 554045276117i64; // weak
__int64 qword_833080 = 281389070352512i64; // weak
__int64 qword_833090 = 1616816936894600816i64; // weak
__int64 qword_833098 = 2044665429944704096i64; // weak
__int64 qword_8330A0 = 24770583935320247i64; // weak
__int64 qword_8330A8 = 24770175913427032i64; // weak
__int64 qword_8330B0 = 51510706729058487i64; // weak
__int64 qword_8330B8 = 63895794685772003i64; // weak
__int64 qword_8330C0 = 50384789642084531i64; // weak
__int64 qword_8330C8 = 2391850107830112i64; // weak
__int64 qword_8330D0 = -281474976710656i64; // weak
__int64 qword_8330D8 = 281470681743360i64; // weak
__int64 qword_8330E0 = 4294901760i64; // weak
__int64 qword_8330E8 = 65535i64; // weak
__int64 qword_8330F0 = -281470681808896i64; // weak
__int64 qword_8330F8 = 281470681808895i64; // weak
__int64 qword_833100 = -281474976645121i64; // weak
__int64 qword_833108 = 1616816936894600816i64; // weak
__int64 qword_833110 = 2044665429944704096i64; // weak
__int64 qword_833118 = 24770175913427032i64; // weak
__int64 qword_833120 = 51510706729058487i64; // weak
__int64 qword_833128 = 63895794685772003i64; // weak
__int64 qword_833130 = 50384789642084531i64; // weak
__int64 qword_833138 = -8649576541405673482i64; // weak
__int64 qword_833140 = -72057589759737856i64; // weak
__int64 qword_833148 = 71777214294589695i64; // weak
void (__cdecl *g_aBlitFunctions[8][3][3])(BlitArgs *) =
{
  {
    {
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_ARGB_BlitFormat_XRGB__BlitFormat_ARGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_ARGB_BlitFormat_XRGB__BlitFormat_ARGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_XRGB__BlitFormat_XRGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_XRGB__BlitFormat_XRGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_RGB_BlitFormat_XRGB__BlitFormat_RGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_RGB_BlitFormat_XRGB__BlitFormat_RGB_BlitFormat_XRGB_,
      &BlitLoopNoScale__BlitOp_SrcCopy_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  {
    {
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  {
    {
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_XRGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_ARGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_XRGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_XRGB_,
      &BlitLoopNoScale_FourChannelAlpha_BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  {
    {
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Colorize_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  {
    {
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Multiply_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  {
    {
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_ARGB_BlitFormat_ARGB__BlitFormat_ARGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_ARGB_BlitFormat_RGB__BlitFormat_ARGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_XRGB_BlitFormat_ARGB__BlitFormat_XRGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_XRGB_BlitFormat_RGB__BlitFormat_XRGB_BlitFormat_RGB_
    },
    {
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_RGB_BlitFormat_ARGB__BlitFormat_RGB_BlitFormat_ARGB_,
      &BlitLoopNoScale__BlitOp_Screen_BlitFormat_RGB_BlitFormat_RGB__BlitFormat_RGB_BlitFormat_RGB_
    }
  },
  { { NULL, NULL, NULL }, { NULL, NULL, NULL }, { NULL, NULL, NULL } },
  { { NULL, NULL, NULL }, { NULL, NULL, NULL }, { NULL, NULL, NULL } }
}; // idb
void (__cdecl *g_aColoringFunctions[8][3][3])(BlitArgs *) =
{
  {
    {
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale_FromA8__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_SrcCopy_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale_FromA8__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_ThreeChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_XRGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_XRGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_A_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_XRGB_,
      &ColoringLoopNoScale_FourChannelAlpha_BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale_FromA8__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_ARGB_,
      &ColoringLoopNoScale_FromA8__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Colorize_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Multiply_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Screen_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  {
    {
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_Fill_BlitFormat_ARGB__BlitFormat_Fill_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_Fill_BlitFormat_RGB__BlitFormat_Fill_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_A_BlitFormat_ARGB__BlitFormat_A_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_A_BlitFormat_RGB__BlitFormat_A_BlitFormat_RGB_
    },
    {
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_AXXX_BlitFormat_ARGB__BlitFormat_AXXX_BlitFormat_ARGB_,
      &ColoringLoopNoScale__BlitOp_Grayscale_BlitFormat_AXXX_BlitFormat_RGB__BlitFormat_AXXX_BlitFormat_RGB_
    }
  },
  { { NULL, NULL, NULL }, { NULL, NULL, NULL }, { NULL, NULL, NULL } }
}; // idb
void (__cdecl *g_aAlphaConvertFunctions[3][3])(AlphaConvertArgs *) =
{
  {
    NULL,
    &AlphaConvert<ACvtFormat_Fill,ACvtFormat_A>,
    &AlphaConvert<ACvtFormat_Fill,ACvtFormat_AXXX>
  },
  {
    NULL,
    &AlphaConvert<ACvtFormat_A,ACvtFormat_A>,
    &AlphaConvert<ACvtFormat_A,ACvtFormat_AXXX>
  },
  {
    NULL,
    &AlphaConvert<ACvtFormat_AXXX,ACvtFormat_A>,
    &AlphaConvert<ACvtFormat_AXXX,ACvtFormat_AXXX>
  }
}; // idb
IDClass<_tagDataID,32,0> stru_8333B8 = { { 4294901761u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_28 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_29 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_30 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_31 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_32 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_33 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_34 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_35 = { { 65535u } }; // idb
RGBAColor color = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor color = {  1.0,  1.0,  1.0,  1.0 }; // idb
Matrix4 Matrix4_IdentityMatrix___36 =
{
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0,
   0.0,
   0.0,
   0.0,
   0.0,
   1.0
}; // idb
RGBAColor cColor = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor stru_834548 = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor stru_8345AC = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor stru_834630 = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor stru_834788 = {  1.0,  1.0,  1.0,  1.0 }; // idb
RGBAColor stru_8349DC = {  0.0,  0.0,  0.0,  1.0 }; // idb
RGBAColor stru_8349EC = {  1.0,  1.0,  1.0,  1.0 }; // idb
bool LayoutDesc::s_bUseDescCache = true; // weak
HashTable<unsigned long,unsigned long,0> LayoutDesc::s_DescCache =
{
  &HashTable<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0>,0>::vftable,
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  }
}; // idb
IntrusiveHashTable<IDClass<_tagDataID,32,0>,HashTableData<IDClass<_tagDataID,32,0>,HashTable<unsigned long,ElementDesc,0> > *,0> stru_834A7C =
{
  NULL,
  {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
  },
  NULL,
  NULL,
  0u,
  0u
}; // idb
const int LOWEST_DATA_RATE_47 = 1024; // idb
const int LOWEST_DATA_RATE_48 = 1024; // idb
const int LOWEST_DATA_RATE_49 = 1024; // idb
const int LOWEST_DATA_RATE_50 = 1024; // idb
float zFightTerrainAdjust =  0.0099999998; // idb
float ACRender::back_object_scale =  1.0; // weak
enum Render::LightingType ACRender::back_lighting_type = FULL_LIGHTING; // weak
float ACRender::backup_detail_tiling =  1.0; // weak
struct Vector3 ACRender::back_object_scale_vec = {  1.0,  1.0,  1.0 }; // weak
int overrideColor = 1; // idb
int trysinglepass_0 = 1; // idb
int ignore_clipmap = 1; // idb
int overrideColor_0 = 1; // idb
int trysinglepass_1 = 1; // idb
int ignore_clipmap_0 = 1; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_36 = { { 65535u } }; // idb
IDClass<_tagCellID,16,65535> Invalid_CellID_37 = { { 65535u } }; // idb
int __security_cookie = 3141592654; // weak
IDClass<_tagCellID,16,65535> Invalid_CellID_38 = { { 65535u } }; // idb
int (__stdcall *advapi32_RegEnumValueW_Ptr)() = &advapi32_RegEnumValueW_Thunk; // idb
int (__stdcall *advapi32_RegQueryValueExW_Ptr)() = &advapi32_RegQueryValueExW_Thunk; // idb
int (__stdcall *advapi32_RegSetValueExW_Ptr)() = &advapi32_RegSetValueExW_Thunk; // idb
int (__stdcall *gdi32_ExtTextOutW_Ptr)() = &gdi32_ExtTextOutW_Thunk; // idb
int (__stdcall *gdi32_GetObjectW_Ptr)() = &gdi32_GetObjectW_Thunk; // idb
int (__stdcall *gdi32_GetTextMetricsW_Ptr)() = &gdi32_GetTextMetricsW_Thunk; // idb
int (__stdcall *kernel32_FindResourceW_Ptr)() = &kernel32_FindResourceW_Thunk; // idb
int (__stdcall *kernel32_GetCurrentDirectoryW_Ptr)() = &kernel32_GetCurrentDirectoryW_Thunk; // idb
int (__stdcall *kernel32_GetTempFileNameW_Ptr)() = &kernel32_GetTempFileNameW_Thunk; // idb
int (__stdcall *kernel32_lstrcatW_Ptr)() = &kernel32_lstrcatW_Thunk; // idb
int (__stdcall *kernel32_lstrlenW_Ptr)() = &kernel32_lstrlenW_Thunk; // idb
int (__stdcall *user32_MessageBoxW_Ptr)() = &user32_MessageBoxW_Thunk; // idb
int (__stdcall *user32_wsprintfW_Ptr)() = &user32_wsprintfW_Thunk; // idb
int (__stdcall *version_VerQueryValueW_Ptr)() = &version_VerQueryValueW_Thunk; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> Outside_CellID = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID = { { 0u } }; // idb
const int LOWEST_DATA_RATE_51 = 0; // idb
const int HIGHEST_DATA_RATE_51 = 0; // idb
const int INITIAL_MAX_DATA_RATE = 0; // idb
const float dword_83646C =  0.0; // idb
const float outside_val =  0.0; // idb
const float block_length =  0.0; // idb
const float half_square_length =  0.0; // idb
const float DEFAULT_VIEW_RADIUS =  0.0; // idb
const long double MIN_QUANTUM =  0.0; // idb
const long double MAX_QUANTUM =  0.0; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8 =
{
  PFID_UNKNOWN,
  0u,
  0u,
  '\0',
  0u,
  0u,
  0u,
  0u,
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  0u,
  0u,
  0u,
  0u
}; // idb
PStringBase<char> Display_Resolution = { NULL }; // idb
PStringBase<char> Display_FullScreen = { NULL }; // idb
PStringBase<char> Display_RefreshRate = { NULL }; // idb
PStringBase<char> Display_SyncToRefresh = { NULL }; // idb
const int LOWEST_DATA_RATE_52 = 0; // idb
const int HIGHEST_DATA_RATE_52 = 0; // idb
const int INITIAL_MAX_DATA_RATE_0 = 0; // idb
const float dword_836504 =  0.0; // idb
const float outside_val_0 =  0.0; // idb
const float block_length_0 =  0.0; // idb
const float half_square_length_0 =  0.0; // idb
const float DEFAULT_VIEW_RADIUS_0 =  0.0; // idb
const long double MIN_QUANTUM_0 =  0.0; // idb
const long double MAX_QUANTUM_0 =  0.0; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_0 =
{
  PFID_UNKNOWN,
  0u,
  0u,
  '\0',
  0u,
  0u,
  0u,
  0u,
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  0u,
  0u,
  0u,
  0u
}; // idb
PStringBase<char> Input_KeymapFile = { NULL }; // idb
PStringBase<char> UI_ChatFontFace = { NULL }; // idb
PStringBase<char> UI_ChatFontSize = { NULL }; // idb
PStringBase<char> UI_ChatFontFace_Choices[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836570 = { NULL }; // idb
PStringBase<char> stru_836574 = { NULL }; // idb
PStringBase<char> stru_836578 = { NULL }; // idb
PStringBase<char> stru_83657C = { NULL }; // idb
PStringBase<char> UI_ChatFontSize_Choices[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836584 = { NULL }; // idb
PStringBase<char> stru_836588 = { NULL }; // idb
PStringBase<char> stru_83658C = { NULL }; // idb
PStringBase<char> stru_836590 = { NULL }; // idb
PStringBase<char> Display_Resolution_0 = { NULL }; // idb
PStringBase<char> Display_FullScreen_0 = { NULL }; // idb
PStringBase<char> Display_RefreshRate_0 = { NULL }; // idb
PStringBase<char> Display_SyncToRefresh_0 = { NULL }; // idb
PStringBase<char> Camera_AlignToSlope = { NULL }; // idb
PStringBase<char> Camera_Stiffness = { NULL }; // idb
PStringBase<char> Camera_AdjustmentSpeed = { NULL }; // idb
PStringBase<char> Sound_SoundDisabled = { NULL }; // idb
PStringBase<char> Sound_SoundVolume = { NULL }; // idb
PStringBase<char> Sound_AmbientSoundDisabled = { NULL }; // idb
PStringBase<char> Sound_AmbientSoundVolume = { NULL }; // idb
PStringBase<char> Sound_InterfaceSoundDisabled = { NULL }; // idb
PStringBase<char> Sound_InterfaceSoundVolume = { NULL }; // idb
PStringBase<char> Sound_SoundFeatures = { NULL }; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive = { NULL }; // idb
PStringBase<char> Sound_SoundFeatures_Choices[2] = { { NULL }, { NULL } }; // idb
PStringBase<char> stru_8365D4 = { NULL }; // idb
PStringBase<char> Misc_TooltipEnable = { NULL }; // idb
PStringBase<char> Misc_TooltipDelay = { NULL }; // idb
PStringBase<char> Render_TextureFiltering = { NULL }; // idb
PStringBase<char> Render_LandscapeDetailTextures = { NULL }; // idb
PStringBase<char> Render_BuildingDetailTextures = { NULL }; // idb
PStringBase<char> Render_FieldOfView = { NULL }; // idb
PStringBase<char> Render_LandscapeTextureDetail = { NULL }; // idb
PStringBase<char> Render_EnvironmentTextureDetail = { NULL }; // idb
PStringBase<char> Render_SceneryDrawDistance = { NULL }; // idb
PStringBase<char> Render_LandscapeDrawDistance = { NULL }; // idb
PStringBase<char> Render_ScreenBrightness = { NULL }; // idb
PStringBase<char> Render_AspectRatio = { NULL }; // idb
PStringBase<char> Render_DisplayAdapter = { NULL }; // idb
PStringBase<char> Render_MaxHardwareClass = { NULL }; // idb
PStringBase<char> Render_AutomaticDegrades = { NULL }; // idb
PStringBase<char> Render_GraphicsPerformance = { NULL }; // idb
PStringBase<char> Render_DegradeDistance = { NULL }; // idb
PStringBase<char> Render_MultiPassAlpha = { NULL }; // idb
PStringBase<char> Render_TextureFiltering_Choices[4] = { { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836624 = { NULL }; // idb
PStringBase<char> stru_836628 = { NULL }; // idb
PStringBase<char> stru_83662C = { NULL }; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836634 = { NULL }; // idb
PStringBase<char> stru_836638 = { NULL }; // idb
PStringBase<char> stru_83663C = { NULL }; // idb
PStringBase<char> stru_836640 = { NULL }; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836648 = { NULL }; // idb
PStringBase<char> stru_83664C = { NULL }; // idb
PStringBase<char> stru_836650 = { NULL }; // idb
PStringBase<char> stru_836654 = { NULL }; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices[3] = { { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_83665C = { NULL }; // idb
PStringBase<char> stru_836660 = { NULL }; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices[6] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836668 = { NULL }; // idb
PStringBase<char> stru_83666C = { NULL }; // idb
PStringBase<char> stru_836670 = { NULL }; // idb
PStringBase<char> stru_836674 = { NULL }; // idb
PStringBase<char> stru_836678 = { NULL }; // idb
PStringBase<char> Render_AspectRatio_Choices[3] = { { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836680 = { NULL }; // idb
PStringBase<char> stru_836684 = { NULL }; // idb
PStringBase<char> Input_MouseLookSensitivity = { NULL }; // idb
PStringBase<char> Input_MouseLookSmoothingAmount = { NULL }; // idb
PStringBase<char> Input_InvertMouseLookYAxis = { NULL }; // idb
PStringBase<char> Input_UseMouseTurning = { NULL }; // idb
PStringBase<char> waveform_None = { NULL }; // idb
PStringBase<char> waveform_Speed = { NULL }; // idb
PStringBase<char> waveform_Noise = { NULL }; // idb
PStringBase<char> waveform_Sine = { NULL }; // idb
PStringBase<char> waveform_Square = { NULL }; // idb
PStringBase<char> waveform_Bounce = { NULL }; // idb
PStringBase<char> waveform_Perlin = { NULL }; // idb
PStringBase<char> waveform_Fractal = { NULL }; // idb
PStringBase<char> waveform_FrameLoop = { NULL }; // idb
volatile int _STL::_Node_Alloc_Lock<1,0>::_S_lock = 0; // idb
int _STL::__node_alloc<1,0>::_S_free_list[] = { 0 }; // weak
int dword_8366CC = 0; // weak
int _STL::__node_alloc<1,0>::_S_heap_size = 0; // weak
int _STL::__node_alloc<1,0>::_S_start_free = 0; // weak
int _STL::__node_alloc<1,0>::_S_end_free = 0; // weak
int _STL::_STLP_mutex_spin<0>::__last = 0; // weak
GODOTUNICODE UniPlatform = PlatformUntested; // idb
HANDLE m_hinst = NULL; // idb
enum ProgramType ProgramTypeSystem::s_eProgramType = Undef_ProgramType; // weak
bool s_bDebugAborting = false; // weak
LPTOP_LEVEL_EXCEPTION_FILTER G_oldFilter = NULL; // idb
PStringBase<char> g_strProjectName = { NULL }; // idb
PStringBase<char> g_strEmailAssertions = { NULL }; // idb
EmergencyMemoryPool g_EmergencyMemoryPool = { NULL }; // idb
const unsigned int LC_DebugAssert = 0u; // idb
bool S_inDebugExecptionHandler = false; // idb
InterfaceSystem *InterfaceSystem::s_pInterfaceSystem = NULL; // idb
bool InterfaceSystem::s_bInterfaceSystemDestroyed = false; // weak
PStringBase<char> PStringBase<char>::whitespace_string = { NULL }; // idb
PStringBase<unsigned short> PStringBase<unsigned short>::null_string = { NULL }; // idb
void *PStringBase<unsigned short>::whitespace_string = NULL; // idb
int dword_836754[] = { 0 }; // weak
struct GrowBuffer::FreeGrowBuffer *GrowBuffer::m_FreeList = NULL; // weak
int dword_83675C[] = { 0 }; // weak
CSpinLock<1048576,0> *GrowBuffer::m_pFreeListLock = NULL; // idb
unsigned __int32 GrowBuffer::m_nFreeListEntries = 0u; // weak
int GrowBuffer::GrowExact::_3::local_static_guard = 0; // weak
IDClass<_tagVersionHandle,32,0> INVALID_VERSIONHANDLE_0 = { { 0u } }; // idb
TransientArchive archive = { { NULL, 0u, { 0u }, { 0u, 0u, NULL }, 0u, NULL, NULL } }; // idb
_DWORD dword_8367B0 = 0; // idb
_UNKNOWN unk_8367B4; // weak
SmartBuffer stru_8367B8 = { 0u, 0u, NULL }; // idb
_UNKNOWN unk_8367C4; // weak
_UNKNOWN unk_8367C8; // weak
_UNKNOWN unk_8367CC; // weak
unsigned int _S83_6 = 0u; // idb
PStringBase<char> DirSeps = { NULL }; // idb
unsigned int _S73 = 0u; // idb
PStringBase<unsigned short> DirSeps_0 = { NULL }; // idb
unsigned int dword_8367E0 = 0u; // idb
PStringBase<char> template_cleanup_filename<char>::_2::forward_slash = { NULL }; // idb
PStringBase<char> template_cleanup_filename<char>::_2::back_slash = { NULL }; // idb
int template_cleanup_filename<char>::_2::local_static_guard = 0; // weak
PStringBase<char> ignore1 = { NULL }; // idb
PStringBase<char> ignore2 = { NULL }; // idb
bool s_fCrashCleanersCalled = false; // idb
CPluginManager G_crashCleaners = { { NULL, 0u, 0u } }; // idb
unsigned __int64 DialogBoxGateways::s_qwDialogContext = 0ui64; // weak
int dword_83680C = 0; // weak
unsigned __int64 DialogBoxGateways::s_qwReportContext = 0ui64; // weak
int dword_836814 = 0; // weak
CPluginManager G_dialogBoxGateways = { { NULL, 0u, 0u } }; // idb
HMODULE g_hDbgHelp = NULL; // idb
int (__stdcall *G_StackWalk)(unsigned __int32, void *, void *, struct _tagSTACKFRAME *, void *, int (__stdcall *)(void *, unsigned __int32, void *, unsigned __int32, unsigned __int32 *), void *(__stdcall *)(void *, unsigned __int32), unsigned __int32 (__stdcall *)(void *, unsigned __int32), unsigned __int32 (__stdcall *)(void *, void *, struct _tagADDRESS *)) = NULL; // weak
void *(__stdcall *G_SymFunctionTableAccess)(void *, unsigned __int32) = NULL; // weak
unsigned __int32 (__stdcall *G_SymSetOptions)(unsigned __int32) = NULL; // weak
unsigned __int32 (__stdcall *G_SymGetOptions)() = NULL; // weak
int (__stdcall *G_SymInitialize)(void *, char *, int) = NULL; // weak
int (__stdcall *G_SymCleanup)(void *) = NULL; // weak
int (__stdcall *G_SymUnloadModule)(void *, unsigned __int32) = NULL; // weak
unsigned __int32 (__stdcall *G_SymLoadModule)(void *, void *, char *, char *, unsigned __int32, unsigned __int32) = NULL; // weak
int (__stdcall *G_SymGetModuleInfo)(void *, unsigned __int32, struct _IMAGEHLP_MODULE *) = NULL; // weak
int (__stdcall *G_SymGetSymFromAddr)(void *, unsigned __int32, unsigned __int32 *, struct _IMAGEHLP_SYMBOL *) = NULL; // weak
int (__stdcall *G_SymGetLineFromAddr)(void *, unsigned __int32, unsigned __int32 *, struct _IMAGEHLP_LINE *) = NULL; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_0 = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_0 = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_0 = { { 0u } }; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_0 = { { 0u } }; // idb
bool g_fSegmentInitialized = false; // weak
bool g_fInitialized = false; // weak
LogController g_LogController =
{
  {
    NULL,
    {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL
    },
    NULL,
    NULL,
    0u,
    0u
  },
  0u,
  { { 0u, NULL }, false, { NULL, 0u, 0u }, { NULL, 0u, 0u } },
  { false, false, false, false, false, false },
  NULL,
  NULL,
  NULL
}; // idb
struct PreciseTimerInstance *Timer::s_pcTimerInstance = NULL; // weak
CICMDCommandStruct Timer::cur_time = { 0, 0u }; // idb
long double Timer::local_time =  0.0; // idb
bool Timer::initialized_ = false; // weak
Turbine::Debug g_commonDebug = { NULL }; // idb
ANSIColorStatus s_ConsoleColor = { false, NULL, 0u, 0u }; // idb
IDClass<_tagVersionHandle,32,0> INVALID_VERSIONHANDLE_2 = { { 0u } }; // idb
bool bComplainedAlready = false; // idb
bool bComplainedAlready_0 = false; // idb
gmClient *Client::m_instance = NULL; // idb
const int LOWEST_DATA_RATE_53 = 0; // idb
const int HIGHEST_DATA_RATE_53 = 0; // idb
const int INITIAL_MAX_DATA_RATE_1 = 0; // idb
PStringBase<char> Net_BindInterface = { NULL }; // idb
PStringBase<char> Net_ComputeUniquePort = { NULL }; // idb
PStringBase<char> Net_UserSpecifiedPort = { NULL }; // idb
PStringBase<char> waveform_None_0 = { NULL }; // idb
PStringBase<char> waveform_Speed_0 = { NULL }; // idb
PStringBase<char> waveform_Noise_0 = { NULL }; // idb
PStringBase<char> waveform_Sine_0 = { NULL }; // idb
PStringBase<char> waveform_Square_0 = { NULL }; // idb
PStringBase<char> waveform_Bounce_0 = { NULL }; // idb
PStringBase<char> waveform_Perlin_0 = { NULL }; // idb
PStringBase<char> waveform_Fractal_0 = { NULL }; // idb
PStringBase<char> waveform_FrameLoop_0 = { NULL }; // idb
PStringBase<char> Display_Resolution_1 = { NULL }; // idb
PStringBase<char> Display_FullScreen_1 = { NULL }; // idb
PStringBase<char> Display_RefreshRate_1 = { NULL }; // idb
PStringBase<char> Display_SyncToRefresh_1 = { NULL }; // idb
const float dword_836A50 =  0.0; // idb
const float outside_val_1 =  0.0; // idb
const float block_length_1 =  0.0; // idb
const float half_square_length_1 =  0.0; // idb
const float DEFAULT_VIEW_RADIUS_1 =  0.0; // idb
const long double MIN_QUANTUM_1 =  0.0; // idb
const long double MAX_QUANTUM_1 =  0.0; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_1 =
{
  PFID_UNKNOWN,
  0u,
  0u,
  '\0',
  0u,
  0u,
  0u,
  0u,
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  0u,
  0u,
  0u,
  0u
}; // idb
PStringBase<char> Misc_TooltipEnable_0 = { NULL }; // idb
PStringBase<char> Misc_TooltipDelay_0 = { NULL }; // idb
PStringBase<char> Sound_SoundDisabled_0 = { NULL }; // idb
PStringBase<char> Sound_SoundVolume_0 = { NULL }; // idb
PStringBase<char> Sound_AmbientSoundDisabled_0 = { NULL }; // idb
PStringBase<char> Sound_AmbientSoundVolume_0 = { NULL }; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_0 = { NULL }; // idb
PStringBase<char> Sound_InterfaceSoundVolume_0 = { NULL }; // idb
PStringBase<char> Sound_SoundFeatures_0 = { NULL }; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_0 = { NULL }; // idb
PStringBase<char> Sound_SoundFeatures_Choices_0[2] = { { NULL }, { NULL } }; // idb
PStringBase<char> stru_836ADC = { NULL }; // idb
const float VOL_MIN_DIST_SQ =  0.0; // idb
const long double INV_LOG_OF_2 =  0.0; // idb
PStringBase<char> Render_TextureFiltering_0 = { NULL }; // idb
PStringBase<char> Render_LandscapeDetailTextures_0 = { NULL }; // idb
PStringBase<char> Render_BuildingDetailTextures_0 = { NULL }; // idb
PStringBase<char> Render_FieldOfView_0 = { NULL }; // idb
PStringBase<char> Render_LandscapeTextureDetail_0 = { NULL }; // idb
PStringBase<char> Render_EnvironmentTextureDetail_0 = { NULL }; // idb
PStringBase<char> Render_SceneryDrawDistance_0 = { NULL }; // idb
PStringBase<char> Render_LandscapeDrawDistance_0 = { NULL }; // idb
PStringBase<char> Render_ScreenBrightness_0 = { NULL }; // idb
PStringBase<char> Render_AspectRatio_0 = { NULL }; // idb
PStringBase<char> Render_DisplayAdapter_0 = { NULL }; // idb
PStringBase<char> Render_MaxHardwareClass_0 = { NULL }; // idb
PStringBase<char> Render_AutomaticDegrades_0 = { NULL }; // idb
PStringBase<char> Render_GraphicsPerformance_0 = { NULL }; // idb
PStringBase<char> Render_DegradeDistance_0 = { NULL }; // idb
PStringBase<char> Render_MultiPassAlpha_0 = { NULL }; // idb
PStringBase<char> Render_TextureFiltering_Choices_0[4] = { { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B34 = { NULL }; // idb
PStringBase<char> stru_836B38 = { NULL }; // idb
PStringBase<char> stru_836B3C = { NULL }; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_0[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B44 = { NULL }; // idb
PStringBase<char> stru_836B48 = { NULL }; // idb
PStringBase<char> stru_836B4C = { NULL }; // idb
PStringBase<char> stru_836B50 = { NULL }; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_0[5] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B58 = { NULL }; // idb
PStringBase<char> stru_836B5C = { NULL }; // idb
PStringBase<char> stru_836B60 = { NULL }; // idb
PStringBase<char> stru_836B64 = { NULL }; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_0[3] = { { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B6C = { NULL }; // idb
PStringBase<char> stru_836B70 = { NULL }; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_0[6] = { { NULL }, { NULL }, { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B78 = { NULL }; // idb
PStringBase<char> stru_836B7C = { NULL }; // idb
PStringBase<char> stru_836B80 = { NULL }; // idb
PStringBase<char> stru_836B84 = { NULL }; // idb
PStringBase<char> stru_836B88 = { NULL }; // idb
PStringBase<char> Render_AspectRatio_Choices_0[3] = { { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836B90 = { NULL }; // idb
PStringBase<char> stru_836B94 = { NULL }; // idb
_UNKNOWN unk_836B98; // weak
struct IInteractiveOutputHandler *g_plohInteractive = NULL; // weak
bool DBCache::s_bCacheInitialized = false; // weak
DBCache *DBCache::s_pCache = NULL; // idb
IDClass<_tagDataID,32,0> INVALID_DID_5 = { { 0u } }; // idb
PStringBase<unsigned short> PROJECTSETTING = { NULL }; // idb
PStringBase<char> NAME = { NULL }; // idb
PStringBase<char> VALUE = { NULL }; // idb
PStringBase<char> BRANCH = { NULL }; // idb
PStringBase<char> BRANCHBASEDIR = { NULL }; // idb
PStringBase<char> PROJECTNAME = { NULL }; // idb
PStringBase<char> LONGNAME = { NULL }; // idb
PStringBase<char> ENUMDB = { NULL }; // idb
PStringBase<char> DIDNAME = { NULL }; // idb
PStringBase<char> RCS = { NULL }; // idb
PStringBase<char> PREPROC_KEYS_BASE_PATH = { NULL }; // idb
PStringBase<char> CURRENT_PROJECT = { NULL }; // idb
PStringBase<char> DATA_GAME_PATH = { NULL }; // idb
PStringBase<char> DATA_ENGINE_PATH = { NULL }; // idb
PStringBase<char> SOURCE_GAME_PATH = { NULL }; // idb
PStringBase<char> SOURCE_ENGINE_PATH = { NULL }; // idb
PStringBase<char> TOOLS_BIN_PATH = { NULL }; // idb
PStringBase<char> CONFIG_TOOLS_PATH = { NULL }; // idb
PStringBase<char> OUTPUT_INI_PATH = { NULL }; // idb
PStringBase<char> DATA_PATH = { NULL }; // idb
PStringBase<char> DOC_PATH = { NULL }; // idb
PStringBase<char> EXPORT_PATH = { NULL }; // idb
PStringBase<char> SDK_PATH = { NULL }; // idb
PStringBase<char> SOURCE_PATH = { NULL }; // idb
PStringBase<char> TOOLS_PATH = { NULL }; // idb
PStringBase<char> PORTAL_PATH = { NULL }; // idb
PStringBase<char> AC_PATH = { NULL }; // idb
AsyncContext INVALID_ASYNCCONTEXT_1 = { 0u }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_6 = { { 0u } }; // idb
PStringBase<char> PHEADER_STRINGS[4] = { { NULL }, { NULL }, { NULL }, { NULL } }; // idb
PStringBase<char> stru_836C30 = { NULL }; // idb
PStringBase<char> stru_836C34 = { NULL }; // idb
PStringBase<char> stru_836C38 = { NULL }; // idb
_UNKNOWN unk_836C3C; // weak
IDClass<_tagDataID,32,0> INVALID_DID_7 = { { 0u } }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_8 = { { 0u } }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_9 = { { 0u } }; // idb
AsyncContext INVALID_ASYNCCONTEXT_2 = { 0u }; // idb
int s_dwDominantDBObjSubDataIDFlags = 0; // idb
IDClass<_tagDataID,32,0> INVALID_DID_10 = { { 0u } }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_11 = { { 0u } }; // idb
void *MasterDBMap::sm_mmap = NULL; // idb
IDClass<_tagDataID,32,0> INVALID_DID_12 = { { 0u } }; // idb
PStringBase<char> MasterDBMap::sm_game_data_dir = { NULL }; // idb
PStringBase<char> MasterDBMap::sm_engine_data_dir = { NULL }; // idb
DBTypeDef INVALID_DBTypeDef =
{
  { { 0u } },
  { { 0u } },
  { NULL, 0u, 0u },
  0u,
  0,
  false,
  false,
  false,
  false,
  { NULL },
  false,
  false,
  false,
  false,
  false,
  false,
  false,
  { false, false, 0u, 0u }
}; // idb
unsigned int _S82_1 = 0u; // idb
IDClass<_tagDataID,32,0> INVALID_DID_14 = { { 0u } }; // idb
_UNKNOWN INVALID_QDID; // weak
CLanguageInfoInterface *CLanguageInfoInterface::m_instance = NULL; // idb
IDClass<_tagDataID,32,0> INVALID_DID_15 = { { 0u } }; // idb
bool ProjectSettings::sm_bInitialized = false; // weak
PStringBase<unsigned short> PROJECTSETTING_0 = { NULL }; // idb
PStringBase<char> NAME_0 = { NULL }; // idb
PStringBase<char> VALUE_0 = { NULL }; // idb
PStringBase<char> BRANCH_0 = { NULL }; // idb
PStringBase<char> BRANCHBASEDIR_0 = { NULL }; // idb
PStringBase<char> PROJECTNAME_0 = { NULL }; // idb
PStringBase<char> LONGNAME_0 = { NULL }; // idb
PStringBase<char> ENUMDB_0 = { NULL }; // idb
PStringBase<char> DIDNAME_0 = { NULL }; // idb
PStringBase<char> RCS_0 = { NULL }; // idb
PStringBase<char> PREPROC_KEYS_BASE_PATH_0 = { NULL }; // idb
PStringBase<char> CURRENT_PROJECT_0 = { NULL }; // idb
PStringBase<char> DATA_GAME_PATH_0 = { NULL }; // idb
PStringBase<char> DATA_ENGINE_PATH_0 = { NULL }; // idb
PStringBase<char> SOURCE_GAME_PATH_0 = { NULL }; // idb
PStringBase<char> SOURCE_ENGINE_PATH_0 = { NULL }; // idb
PStringBase<char> TOOLS_BIN_PATH_0 = { NULL }; // idb
PStringBase<char> CONFIG_TOOLS_PATH_0 = { NULL }; // idb
PStringBase<char> OUTPUT_INI_PATH_0 = { NULL }; // idb
PStringBase<char> DATA_PATH_0 = { NULL }; // idb
PStringBase<char> DOC_PATH_0 = { NULL }; // idb
PStringBase<char> EXPORT_PATH_0 = { NULL }; // idb
PStringBase<char> SDK_PATH_0 = { NULL }; // idb
PStringBase<char> SOURCE_PATH_0 = { NULL }; // idb
PStringBase<char> TOOLS_PATH_0 = { NULL }; // idb
PStringBase<char> PORTAL_PATH_0 = { NULL }; // idb
PStringBase<char> AC_PATH_0 = { NULL }; // idb
PStringBase<char> ProjectSettings::sm_settingsFilePath = { NULL }; // idb
int ProjectSettings::sm_settingsFile = 0; // weak
_STL::hash_map<PStringBase<char>,PStringBase<char>,_STL::hash<PStringBase<char> >,_STL::equal_to<PStringBase<char> >,_STL::allocator<_STL::pair<PStringBase<char> const ,PStringBase<char> > > > ProjectSettings::sm_settings = { { , {  }, {  }, { { NULL, NULL, { , NULL } } }, { , 0u } } }; // idb
Vector3 Vector3_ZeroVector___4 = {  0.0,  0.0,  0.0 }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_16 = { { 0u } }; // idb
const float outside_val_2 =  0.0; // idb
const float block_length_2 =  0.0; // idb
const float half_square_length_2 =  0.0; // idb
PStringBase<char> KW_TRUE = { NULL }; // idb
PStringBase<char> KW_FALSE = { NULL }; // idb
PStringBase<char> KW_UNDEF = { NULL }; // idb
PStringBase<char> waveform_None_1 = { NULL }; // idb
PStringBase<char> waveform_Speed_1 = { NULL }; // idb
PStringBase<char> waveform_Noise_1 = { NULL }; // idb
PStringBase<char> waveform_Sine_1 = { NULL }; // idb
PStringBase<char> waveform_Square_1 = { NULL }; // idb
PStringBase<char> waveform_Bounce_1 = { NULL }; // idb
PStringBase<char> waveform_Perlin_1 = { NULL }; // idb
PStringBase<char> waveform_Fractal_1 = { NULL }; // idb
PStringBase<char> waveform_FrameLoop_1 = { NULL }; // idb
int MasterPropertyGrabber::s_spcMasterPropertyList = 0; // weak
const float outside_val_3 =  0.0; // idb
const float block_length_3 =  0.0; // idb
const float half_square_length_3 =  0.0; // idb
PStringBase<char> KW_TRUE_0 = { NULL }; // idb
PStringBase<char> KW_FALSE_0 = { NULL }; // idb
PStringBase<char> KW_UNDEF_0 = { NULL }; // idb
PStringBase<char> Type = { NULL }; // idb
PStringBase<char> Group = { NULL }; // idb
PStringBase<char> Default = { NULL }; // idb
PStringBase<char> Min = { NULL }; // idb
PStringBase<char> Max = { NULL }; // idb
PStringBase<char> Available = { NULL }; // idb
PStringBase<char> AllAvailable = { NULL }; // idb
PStringBase<char> Required = { NULL }; // idb
PStringBase<char> ClassOnly = { NULL }; // idb
PStringBase<char> InstanceOnly = { NULL }; // idb
PStringBase<char> ClientOnlyData = { NULL }; // idb
PStringBase<char> ServerOnlyData = { NULL }; // idb
PStringBase<char> NetPredictedSharedVisually = { NULL }; // idb
PStringBase<char> NetPredictedSharedPrivately = { NULL }; // idb
PStringBase<char> PredictionTimeout = { NULL }; // idb
PStringBase<char> NetSharedVisually = { NULL }; // idb
PStringBase<char> NetSharedPrivately = { NULL }; // idb
PStringBase<char> WorldSharedWithServers = { NULL }; // idb
PStringBase<char> WorldSharedWithServersAndClients = { NULL }; // idb
PStringBase<char> NoCheckpoint = { NULL }; // idb
PStringBase<char> NoReplay = { NULL }; // idb
PStringBase<char> AbsoluteTimeStamp = { NULL }; // idb
PStringBase<char> Groupable = { NULL }; // idb
PStringBase<char> MinElements = { NULL }; // idb
PStringBase<char> MaxElements = { NULL }; // idb
PStringBase<char> HelpString = { NULL }; // idb
PStringBase<char> Global = { NULL }; // idb
PStringBase<char> Internal = { NULL }; // idb
PStringBase<char> PropagateToChildren = { NULL }; // idb
PStringBase<char> Provider = { NULL }; // idb
PStringBase<char> ReadOnly = { NULL }; // idb
PStringBase<char> Recorded = { NULL }; // idb
PStringBase<char> ToolOnly = { NULL }; // idb
PStringBase<char> KW_NULL = { NULL }; // idb
PStringBase<char> KW_NULL_0 = { NULL }; // idb
__int32 *Random::_iv = NULL; // weak
__int32 Random::_iy = 0; // weak
IDClass<_tagDataID,32,0> INVALID_DID_23 = { { 0u } }; // idb
PStringBase<char> KW_NULL_1 = { NULL }; // idb
PStringBase<char> KW_STRINGTABLE = { NULL }; // idb
PStringBase<char> KW_STRINGTOKEN = { NULL }; // idb
PStringBase<char> KW_STRINGENGLISH = { NULL }; // idb
PStringBase<char> KW_STRINGCOMMENT = { NULL }; // idb
PStringBase<char> KW_LITERAL = { NULL }; // idb
IDClass<_tagDataID,32,0> INVALID_DID_25 = { { 0u } }; // idb
struct StringTableGen *MasterStringTableGen::s_pStringTableGen = NULL; // weak
_UNKNOWN CIme::g_UseIme; // weak
bool CIme::g_bOSImeEnabled = false; // weak
PixelFormatDesc PixelFormatDesc_A8R8G8B8_2 =
{
  PFID_UNKNOWN,
  0u,
  0u,
  '\0',
  0u,
  0u,
  0u,
  0u,
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  '\0',
  0u,
  0u,
  0u,
  0u
}; // idb
PStringBase<char> waveform_None_2 = { NULL }; // idb
PStringBase<char> waveform_Speed_2 = { NULL }; // idb
PStringBase<char> waveform_Noise_2 = { NULL }; // idb
PStringBase<char> waveform_Sine_2 = { NULL }; // idb
PStringBase<char> waveform_Square_2 = { NULL }; // idb
PStringBase<char> waveform_Bounce_2 = { NULL }; // idb
PStringBase<char> waveform_Perlin_2 = { NULL }; // idb
PStringBase<char> waveform_Fractal_2 = { NULL }; // idb
PStringBase<char> waveform_FrameLoop_2 = { NULL }; // idb
const float dword_836FDC =  0.0; // idb
const float outside_val_4 =  0.0; // idb
const float block_length_4 =  0.0; // idb
const float half_square_length_4 =  0.0; // idb
PStringBase<char> International_UseIME = { NULL }; // idb
CInputManager *ICIDM::s_cidm = NULL; // idb
PStringBase<char> Display_Resolution_2; // idb
PStringBase<char> Display_FullScreen_2; // idb
PStringBase<char> Display_RefreshRate_2; // idb
PStringBase<char> Display_SyncToRefresh_2; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_3; // idb
PStringBase<char> Input_MouseLookSensitivity_0; // idb
PStringBase<char> Input_MouseLookSmoothingAmount_0; // idb
PStringBase<char> Input_InvertMouseLookYAxis_0; // idb
PStringBase<char> Input_UseMouseTurning_0; // idb
PStringBase<char> waveform_None_3; // idb
PStringBase<char> waveform_Speed_3; // idb
PStringBase<char> waveform_Noise_3; // idb
PStringBase<char> waveform_Sine_3; // idb
PStringBase<char> waveform_Square_3; // idb
PStringBase<char> waveform_Bounce_3; // idb
PStringBase<char> waveform_Perlin_3; // idb
PStringBase<char> waveform_Fractal_3; // idb
PStringBase<char> waveform_FrameLoop_3; // idb
unsigned __int32 lcat_InputManager; // weak
QIOffset Offsets[2]; // idb
int dword_837088; // weak
int dword_83708C; // weak
int dword_837090; // weak
unsigned int dword_837094; // idb
PStringBase<char> waveform_None_4; // idb
PStringBase<char> waveform_Speed_4; // idb
PStringBase<char> waveform_Noise_4; // idb
PStringBase<char> waveform_Sine_4; // idb
PStringBase<char> waveform_Square_4; // idb
PStringBase<char> waveform_Bounce_4; // idb
PStringBase<char> waveform_Perlin_4; // idb
PStringBase<char> waveform_Fractal_4; // idb
PStringBase<char> waveform_FrameLoop_4; // idb
_UNKNOWN s_ClassRegistrarGlobalRegistryCommands_ClassType; // weak
GlobalRegistryInstance *GlobalRegistry::s_pcGlobalRegistry; // idb
PStringBase<char> waveform_None_5; // idb
PStringBase<char> waveform_Speed_5; // idb
PStringBase<char> waveform_Noise_5; // idb
PStringBase<char> waveform_Sine_5; // idb
PStringBase<char> waveform_Square_5; // idb
PStringBase<char> waveform_Bounce_5; // idb
PStringBase<char> waveform_Perlin_5; // idb
PStringBase<char> waveform_Fractal_5; // idb
PStringBase<char> waveform_FrameLoop_5; // idb
PStringBase<char> waveform_None_6; // idb
PStringBase<char> waveform_Speed_6; // idb
PStringBase<char> waveform_Noise_6; // idb
PStringBase<char> waveform_Sine_6; // idb
PStringBase<char> waveform_Square_6; // idb
PStringBase<char> waveform_Bounce_6; // idb
PStringBase<char> waveform_Perlin_6; // idb
PStringBase<char> waveform_Fractal_6; // idb
PStringBase<char> waveform_FrameLoop_6; // idb
PStringBase<unsigned short> PROJECTSETTING_1; // idb
PStringBase<char> NAME_1; // idb
PStringBase<char> VALUE_1; // idb
PStringBase<char> BRANCH_1; // idb
PStringBase<char> BRANCHBASEDIR_1; // idb
PStringBase<char> PROJECTNAME_1; // idb
PStringBase<char> LONGNAME_1; // idb
PStringBase<char> ENUMDB_1; // idb
PStringBase<char> DIDNAME_1; // idb
PStringBase<char> RCS_1; // idb
PStringBase<char> PREPROC_KEYS_BASE_PATH_1; // idb
PStringBase<char> CURRENT_PROJECT_1; // idb
PStringBase<char> DATA_GAME_PATH_1; // idb
PStringBase<char> DATA_ENGINE_PATH_1; // idb
PStringBase<char> SOURCE_GAME_PATH_1; // idb
PStringBase<char> SOURCE_ENGINE_PATH_1; // idb
PStringBase<char> TOOLS_BIN_PATH_1; // idb
PStringBase<char> CONFIG_TOOLS_PATH_1; // idb
PStringBase<char> OUTPUT_INI_PATH_1; // idb
PStringBase<char> DATA_PATH_1; // idb
PStringBase<char> DOC_PATH_1; // idb
PStringBase<char> EXPORT_PATH_1; // idb
PStringBase<char> SDK_PATH_1; // idb
PStringBase<char> SOURCE_PATH_1; // idb
PStringBase<char> TOOLS_PATH_1; // idb
PStringBase<char> PORTAL_PATH_1; // idb
PStringBase<char> AC_PATH_1; // idb
PStringBase<char> UserPreferences::sm_strDefaultFile; // idb
bool Device::m_bIsDone; // weak
bool Device::m_bIsReady; // weak
bool Device::m_bIsInitialized; // weak
bool Device::m_bIsActiveApp; // weak
bool Device::m_bIsWithinEventLoop; // weak
bool Device::m_bToggleFullScreenMode; // weak
bool Device::m_bTrackLeaveCalled; // weak
unsigned __int32 Device::m_nOSVersion; // weak
bool Device::m_bUseForcedResolution; // weak
HWND Device::m_hWnd; // idb
bool Device::m_bIsChildWnd; // weak
struct Device::DeviceDialogBoxGateway *Device::sm_pDeviceDialogGateway; // weak
PStringBase<char> Display_Resolution_3; // idb
PStringBase<char> Display_FullScreen_3; // idb
PStringBase<char> Display_RefreshRate_3; // idb
PStringBase<char> Display_SyncToRefresh_3; // idb
PStringBase<char> waveform_None_7; // idb
PStringBase<char> waveform_Speed_7; // idb
PStringBase<char> waveform_Noise_7; // idb
PStringBase<char> waveform_Sine_7; // idb
PStringBase<char> waveform_Square_7; // idb
PStringBase<char> waveform_Bounce_7; // idb
PStringBase<char> waveform_Perlin_7; // idb
PStringBase<char> waveform_Fractal_7; // idb
PStringBase<char> waveform_FrameLoop_7; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_4; // idb
const float dword_837234; // idb
const float outside_val_5; // idb
const float block_length_5; // idb
const float half_square_length_5; // idb
PStringBase<char> Render_TextureFiltering_1; // idb
PStringBase<char> Render_LandscapeDetailTextures_1; // idb
PStringBase<char> Render_BuildingDetailTextures_1; // idb
PStringBase<char> Render_FieldOfView_1; // idb
PStringBase<char> Render_LandscapeTextureDetail_1; // idb
PStringBase<char> Render_EnvironmentTextureDetail_1; // idb
PStringBase<char> Render_SceneryDrawDistance_1; // idb
PStringBase<char> Render_LandscapeDrawDistance_1; // idb
PStringBase<char> Render_ScreenBrightness_1; // idb
PStringBase<char> Render_AspectRatio_1; // idb
PStringBase<char> Render_DisplayAdapter_1; // idb
PStringBase<char> Render_MaxHardwareClass_1; // idb
PStringBase<char> Render_AutomaticDegrades_1; // idb
PStringBase<char> Render_GraphicsPerformance_1; // idb
PStringBase<char> Render_DegradeDistance_1; // idb
PStringBase<char> Render_MultiPassAlpha_1; // idb
PStringBase<char> Render_TextureFiltering_Choices_1[4]; // idb
PStringBase<char> stru_83728C; // idb
PStringBase<char> stru_837290; // idb
PStringBase<char> stru_837294; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_1[5]; // idb
PStringBase<char> stru_83729C; // idb
PStringBase<char> stru_8372A0; // idb
PStringBase<char> stru_8372A4; // idb
PStringBase<char> stru_8372A8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_1[5]; // idb
PStringBase<char> stru_8372B0; // idb
PStringBase<char> stru_8372B4; // idb
PStringBase<char> stru_8372B8; // idb
PStringBase<char> stru_8372BC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_1[3]; // idb
PStringBase<char> stru_8372C4; // idb
PStringBase<char> stru_8372C8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_1[6]; // idb
PStringBase<char> stru_8372D0; // idb
PStringBase<char> stru_8372D4; // idb
PStringBase<char> stru_8372D8; // idb
PStringBase<char> stru_8372DC; // idb
PStringBase<char> stru_8372E0; // idb
PStringBase<char> Render_AspectRatio_Choices_1[3]; // idb
PStringBase<char> stru_8372E8; // idb
PStringBase<char> stru_8372EC; // idb
const float DEFAULT_VIEW_RADIUS_2; // idb
const long double MIN_QUANTUM_2; // idb
const long double MAX_QUANTUM_2; // idb
PStringBase<char> Misc_TooltipEnable_1; // idb
PStringBase<char> Misc_TooltipDelay_1; // idb
PStringBase<char> sErrorTitle; // idb
unsigned int lastTime; // idb
RGBAColor RGBAColor_Null_1; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_5; // idb
struct GlobalEventHandler *GlobalEventHandler::geh; // weak
PlatformString::StringAccessor g_StringAccessor; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_6; // idb
float flt_8373B4[]; // weak
float *SceneTool::m_LastFrameTimes; // weak
_UNKNOWN unk_837404; // weak
double SceneTool::m_LastFlipTime; // weak
float SceneTool::m_FramesPerSecond; // weak
unsigned __int32 SceneTool::m_CachedMaterialConditions; // weak
bool SceneTool::m_DebugHUDVisible; // weak
double SceneTool::m_dLastOldResourcePurgeTime; // weak
struct RenderSurface *SceneTool::m_pScreenShotSurface; // weak
unsigned __int32 SceneTool::m_ScreenShotMinX; // weak
unsigned __int32 SceneTool::m_ScreenShotMinY; // weak
RenderMaterial *SceneTool::m_pDefaultMaterial; // idb
RenderMaterial *SceneTool::m_pPrimMaterial; // idb
RenderMaterial *SceneTool::m_pPrimObjectMaterial; // idb
RenderVertexBuffer *SceneTool::m_pPrimVertexBuffer; // idb
struct RenderMesh *SceneTool::m_pCylinderMesh; // weak
struct RenderMesh *SceneTool::m_pSphereMesh; // weak
DebugConsole *SceneTool::m_pDebugConsole; // idb
ProfilerUI *SceneTool::m_pProfilerUI; // idb
bool st_init; // idb
bool g_bMatrixStored; // idb
AC1Legacy::Vector3 Legacy_Vector3_ZeroVector___8; // idb
Vector3 Vector3_ZeroVector___6; // idb
const float outside_val_6; // idb
const float block_length_6; // idb
const float half_square_length_6; // idb
PStringBase<char> waveform_None_8; // idb
PStringBase<char> waveform_Speed_8; // idb
PStringBase<char> waveform_Noise_8; // idb
PStringBase<char> waveform_Sine_8; // idb
PStringBase<char> waveform_Square_8; // idb
PStringBase<char> waveform_Bounce_8; // idb
PStringBase<char> waveform_Perlin_8; // idb
PStringBase<char> waveform_Fractal_8; // idb
PStringBase<char> waveform_FrameLoop_8; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_7; // idb
PStringBase<char> Render_TextureFiltering_2; // idb
PStringBase<char> Render_LandscapeDetailTextures_2; // idb
PStringBase<char> Render_BuildingDetailTextures_2; // idb
PStringBase<char> Render_FieldOfView_2; // idb
PStringBase<char> Render_LandscapeTextureDetail_2; // idb
PStringBase<char> Render_EnvironmentTextureDetail_2; // idb
PStringBase<char> Render_SceneryDrawDistance_2; // idb
PStringBase<char> Render_LandscapeDrawDistance_2; // idb
PStringBase<char> Render_ScreenBrightness_2; // idb
PStringBase<char> Render_AspectRatio_2; // idb
PStringBase<char> Render_DisplayAdapter_2; // idb
PStringBase<char> Render_MaxHardwareClass_2; // idb
PStringBase<char> Render_AutomaticDegrades_2; // idb
PStringBase<char> Render_GraphicsPerformance_2; // idb
PStringBase<char> Render_DegradeDistance_2; // idb
PStringBase<char> Render_MultiPassAlpha_2; // idb
PStringBase<char> Render_TextureFiltering_Choices_2[4]; // idb
PStringBase<char> stru_83753C; // idb
PStringBase<char> stru_837540; // idb
PStringBase<char> stru_837544; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_2[5]; // idb
PStringBase<char> stru_83754C; // idb
PStringBase<char> stru_837550; // idb
PStringBase<char> stru_837554; // idb
PStringBase<char> stru_837558; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_2[5]; // idb
PStringBase<char> stru_837560; // idb
PStringBase<char> stru_837564; // idb
PStringBase<char> stru_837568; // idb
PStringBase<char> stru_83756C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_2[3]; // idb
PStringBase<char> stru_837574; // idb
PStringBase<char> stru_837578; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_2[6]; // idb
PStringBase<char> stru_837580; // idb
PStringBase<char> stru_837584; // idb
PStringBase<char> stru_837588; // idb
PStringBase<char> stru_83758C; // idb
PStringBase<char> stru_837590; // idb
PStringBase<char> Render_AspectRatio_Choices_2[3]; // idb
PStringBase<char> stru_837598; // idb
PStringBase<char> stru_83759C; // idb
const float DEFAULT_VIEW_RADIUS_3; // idb
const long double MIN_QUANTUM_3; // idb
const long double MAX_QUANTUM_3; // idb
struct Matrix4 SceneTool::m_worldMatrix; // weak
int dword_8375BC; // weak
int dword_8375C0; // weak
int dword_8375C4; // weak
int dword_8375C8; // weak
int dword_8375CC; // weak
int dword_8375D0; // weak
int dword_8375D4; // weak
int dword_8375D8; // weak
int dword_8375DC; // weak
int dword_8375E0; // weak
int dword_8375E4; // weak
int dword_8375E8; // weak
int dword_8375EC; // weak
int dword_8375F0; // weak
int dword_8375F4; // weak
struct Matrix4 SceneTool::m_viewMatrix; // weak
int dword_8375FC; // weak
int dword_837600; // weak
int dword_837604; // weak
int dword_837608; // weak
int dword_83760C; // weak
int dword_837610; // weak
int dword_837614; // weak
int dword_837618; // weak
int dword_83761C; // weak
int dword_837620; // weak
int dword_837624; // weak
int dword_837628; // weak
int dword_83762C; // weak
int dword_837630; // weak
int dword_837634; // weak
Matrix4 SceneTool::m_projMatrix; // idb
_UNKNOWN SceneTool::m_oldViewMatrix; // weak
_UNKNOWN SceneTool::m_oldProjMatrix; // weak
_UNKNOWN SceneTool::m_oldWorldMatrix; // weak
struct Vector3 SceneTool::m_vWorldOffset; // weak
const long double RAD_STEP; // idb
unsigned int _S218_12; // idb
Vector3 octahedron[24]; // idb
int dword_837764; // weak
int dword_837770; // weak
int dword_83777C; // weak
int dword_837788; // weak
int dword_837794; // weak
int dword_8377A0; // weak
int dword_8377AC; // weak
int dword_8377B8; // weak
int dword_8377C4; // weak
int dword_8377D0; // weak
int dword_8377DC; // weak
int dword_8377E8; // weak
int dword_8377F4; // weak
int dword_837800; // weak
int dword_83780C; // weak
int dword_837818; // weak
int dword_837824; // weak
int dword_837830; // weak
int dword_83783C; // weak
int dword_837848; // weak
int dword_837854; // weak
int dword_837860; // weak
int dword_83786C; // weak
Vector3 ZMIN; // idb
Vector3 ZMAX; // idb
Vector3 YMIN; // idb
Vector3 YMAX; // idb
Vector3 XMIN; // idb
Vector3 XMAX; // idb
unsigned int _S219_32; // idb
long double s_LastThinkLocalTime; // idb
char txt[1024]; // idb
__int32 UISurface::s_nBytesConsumed; // weak
PixelFormatDesc PixelFormatDesc_A8R8G8B8_8; // idb
const float dword_837D2C; // idb
const float outside_val_7; // idb
const float block_length_7; // idb
const float half_square_length_7; // idb
PStringBase<char> Render_TextureFiltering_3; // idb
PStringBase<char> Render_LandscapeDetailTextures_3; // idb
PStringBase<char> Render_BuildingDetailTextures_3; // idb
PStringBase<char> Render_FieldOfView_3; // idb
PStringBase<char> Render_LandscapeTextureDetail_3; // idb
PStringBase<char> Render_EnvironmentTextureDetail_3; // idb
PStringBase<char> Render_SceneryDrawDistance_3; // idb
PStringBase<char> Render_LandscapeDrawDistance_3; // idb
PStringBase<char> Render_ScreenBrightness_3; // idb
PStringBase<char> Render_AspectRatio_3; // idb
PStringBase<char> Render_DisplayAdapter_3; // idb
PStringBase<char> Render_MaxHardwareClass_3; // idb
PStringBase<char> Render_AutomaticDegrades_3; // idb
PStringBase<char> Render_GraphicsPerformance_3; // idb
PStringBase<char> Render_DegradeDistance_3; // idb
PStringBase<char> Render_MultiPassAlpha_3; // idb
PStringBase<char> Render_TextureFiltering_Choices_3[4]; // idb
PStringBase<char> stru_837D80; // idb
PStringBase<char> stru_837D84; // idb
PStringBase<char> stru_837D88; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_3[5]; // idb
PStringBase<char> stru_837D90; // idb
PStringBase<char> stru_837D94; // idb
PStringBase<char> stru_837D98; // idb
PStringBase<char> stru_837D9C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_3[5]; // idb
PStringBase<char> stru_837DA4; // idb
PStringBase<char> stru_837DA8; // idb
PStringBase<char> stru_837DAC; // idb
PStringBase<char> stru_837DB0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_3[3]; // idb
PStringBase<char> stru_837DB8; // idb
PStringBase<char> stru_837DBC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_3[6]; // idb
PStringBase<char> stru_837DC4; // idb
PStringBase<char> stru_837DC8; // idb
PStringBase<char> stru_837DCC; // idb
PStringBase<char> stru_837DD0; // idb
PStringBase<char> stru_837DD4; // idb
PStringBase<char> Render_AspectRatio_Choices_3[3]; // idb
PStringBase<char> stru_837DDC; // idb
PStringBase<char> stru_837DE0; // idb
PStringBase<char> waveform_None_9; // idb
PStringBase<char> waveform_Speed_9; // idb
PStringBase<char> waveform_Noise_9; // idb
PStringBase<char> waveform_Sine_9; // idb
PStringBase<char> waveform_Square_9; // idb
PStringBase<char> waveform_Bounce_9; // idb
PStringBase<char> waveform_Perlin_9; // idb
PStringBase<char> waveform_Fractal_9; // idb
PStringBase<char> waveform_FrameLoop_9; // idb
FastSmartArray<unsigned char> refRow; // idb
unsigned int dword_837E14; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_9; // idb
const float dword_837E64; // idb
const float outside_val_8; // idb
const float block_length_8; // idb
const float half_square_length_8; // idb
IDClass<_tagDataID,32,0> INVALID_DID_32; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_10; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_11; // idb
IDClass<_tagDataID,32,0> INVALID_DID_33; // idb
const float dword_837F18; // idb
const float outside_val_9; // idb
const float block_length_9; // idb
const float half_square_length_9; // idb
PStringBase<char> Render_TextureFiltering_4; // idb
PStringBase<char> Render_LandscapeDetailTextures_4; // idb
PStringBase<char> Render_BuildingDetailTextures_4; // idb
PStringBase<char> Render_FieldOfView_4; // idb
PStringBase<char> Render_LandscapeTextureDetail_4; // idb
PStringBase<char> Render_EnvironmentTextureDetail_4; // idb
PStringBase<char> Render_SceneryDrawDistance_4; // idb
PStringBase<char> Render_LandscapeDrawDistance_4; // idb
PStringBase<char> Render_ScreenBrightness_4; // idb
PStringBase<char> Render_AspectRatio_4; // idb
PStringBase<char> Render_DisplayAdapter_4; // idb
PStringBase<char> Render_MaxHardwareClass_4; // idb
PStringBase<char> Render_AutomaticDegrades_4; // idb
PStringBase<char> Render_GraphicsPerformance_4; // idb
PStringBase<char> Render_DegradeDistance_4; // idb
PStringBase<char> Render_MultiPassAlpha_4; // idb
PStringBase<char> Render_TextureFiltering_Choices_4[4]; // idb
PStringBase<char> stru_837F6C; // idb
PStringBase<char> stru_837F70; // idb
PStringBase<char> stru_837F74; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_4[5]; // idb
PStringBase<char> stru_837F7C; // idb
PStringBase<char> stru_837F80; // idb
PStringBase<char> stru_837F84; // idb
PStringBase<char> stru_837F88; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_4[5]; // idb
PStringBase<char> stru_837F90; // idb
PStringBase<char> stru_837F94; // idb
PStringBase<char> stru_837F98; // idb
PStringBase<char> stru_837F9C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_4[3]; // idb
PStringBase<char> stru_837FA4; // idb
PStringBase<char> stru_837FA8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_4[6]; // idb
PStringBase<char> stru_837FB0; // idb
PStringBase<char> stru_837FB4; // idb
PStringBase<char> stru_837FB8; // idb
PStringBase<char> stru_837FBC; // idb
PStringBase<char> stru_837FC0; // idb
PStringBase<char> Render_AspectRatio_Choices_4[3]; // idb
PStringBase<char> stru_837FC8; // idb
PStringBase<char> stru_837FCC; // idb
PStringBase<char> waveform_None_10; // idb
PStringBase<char> waveform_Speed_10; // idb
PStringBase<char> waveform_Noise_10; // idb
PStringBase<char> waveform_Sine_10; // idb
PStringBase<char> waveform_Square_10; // idb
PStringBase<char> waveform_Bounce_10; // idb
PStringBase<char> waveform_Perlin_10; // idb
PStringBase<char> waveform_Fractal_10; // idb
PStringBase<char> waveform_FrameLoop_10; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_12; // idb
const float dword_838048; // idb
const float outside_val_10; // idb
const float block_length_10; // idb
const float half_square_length_10; // idb
IDClass<_tagDataID,32,0> INVALID_DID_34; // idb
PStringBase<char> Render_TextureFiltering_5; // idb
PStringBase<char> Render_LandscapeDetailTextures_5; // idb
PStringBase<char> Render_BuildingDetailTextures_5; // idb
PStringBase<char> Render_FieldOfView_5; // idb
PStringBase<char> Render_LandscapeTextureDetail_5; // idb
PStringBase<char> Render_EnvironmentTextureDetail_5; // idb
PStringBase<char> Render_SceneryDrawDistance_5; // idb
PStringBase<char> Render_LandscapeDrawDistance_5; // idb
PStringBase<char> Render_ScreenBrightness_5; // idb
PStringBase<char> Render_AspectRatio_5; // idb
PStringBase<char> Render_DisplayAdapter_5; // idb
PStringBase<char> Render_MaxHardwareClass_5; // idb
PStringBase<char> Render_AutomaticDegrades_5; // idb
PStringBase<char> Render_GraphicsPerformance_5; // idb
PStringBase<char> Render_DegradeDistance_5; // idb
PStringBase<char> Render_MultiPassAlpha_5; // idb
PStringBase<char> Render_TextureFiltering_Choices_5[4]; // idb
PStringBase<char> stru_8380A0; // idb
PStringBase<char> stru_8380A4; // idb
PStringBase<char> stru_8380A8; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_5[5]; // idb
PStringBase<char> stru_8380B0; // idb
PStringBase<char> stru_8380B4; // idb
PStringBase<char> stru_8380B8; // idb
PStringBase<char> stru_8380BC; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_5[5]; // idb
PStringBase<char> stru_8380C4; // idb
PStringBase<char> stru_8380C8; // idb
PStringBase<char> stru_8380CC; // idb
PStringBase<char> stru_8380D0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_5[3]; // idb
PStringBase<char> stru_8380D8; // idb
PStringBase<char> stru_8380DC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_5[6]; // idb
PStringBase<char> stru_8380E4; // idb
PStringBase<char> stru_8380E8; // idb
PStringBase<char> stru_8380EC; // idb
PStringBase<char> stru_8380F0; // idb
PStringBase<char> stru_8380F4; // idb
PStringBase<char> Render_AspectRatio_Choices_5[3]; // idb
PStringBase<char> stru_8380FC; // idb
PStringBase<char> stru_838100; // idb
PStringBase<char> waveform_None_11; // idb
PStringBase<char> waveform_Speed_11; // idb
PStringBase<char> waveform_Noise_11; // idb
PStringBase<char> waveform_Sine_11; // idb
PStringBase<char> waveform_Square_11; // idb
PStringBase<char> waveform_Bounce_11; // idb
PStringBase<char> waveform_Perlin_11; // idb
PStringBase<char> waveform_Fractal_11; // idb
PStringBase<char> waveform_FrameLoop_11; // idb
PStringBase<char> PHeader; // idb
PStringBase<char> VertexArray; // idb
PStringBase<char> BinaryVertexArray; // idb
PStringBase<char> VertexType_0; // idb
PStringBase<char> VertexData; // idb
PStringBase<char> Vertex; // idb
PStringBase<char> Index; // idb
PStringBase<char> Origin; // idb
PStringBase<char> Normal; // idb
PStringBase<char> Diffuse; // idb
PStringBase<char> Specular; // idb
PStringBase<char> UVS; // idb
PStringBase<char> VectorS; // idb
PStringBase<char> VectorT; // idb
PStringBase<char> VectorSxT; // idb
PStringBase<char> Weights; // idb
PStringBase<char> Importance; // idb
PStringBase<char> PhysMtl; // idb
PStringBase<char> Material; // idb
PStringBase<char> ID; // idb
PStringBase<char> FileName; // idb
PStringBase<char> Polygon; // idb
PStringBase<char> ID_0; // idb
PStringBase<char> Indices; // idb
PStringBase<char> MaterialID; // idb
PStringBase<char> PhysMaterialID; // idb
PStringBase<char> Markings; // idb
PStringBase<char> Material_0; // idb
PStringBase<char> Index_0; // idb
PStringBase<char> Filename; // idb
PStringBase<char> Surface; // idb
PStringBase<char> CellPoly; // idb
PStringBase<char> Sphere; // idb
PStringBase<char> Side; // idb
PStringBase<char> Positive; // idb
PStringBase<char> Negative; // idb
PStringBase<char> Polygon_0; // idb
PStringBase<char> OtherCell; // idb
PStringBase<char> CellPortal; // idb
PStringBase<char> Portal; // idb
PStringBase<char> OtherCell_0; // idb
PStringBase<char> OtherPortal; // idb
PStringBase<char> ExactMatch; // idb
PStringBase<char> StabList; // idb
PStringBase<char> Period; // idb
PStringBase<char> GrannyAnimation; // idb
PStringBase<char> Transform; // idb
PStringBase<char> Scale; // idb
PStringBase<char> Weight; // idb
PStringBase<char> Offset; // idb
PStringBase<char> Quaternion_0; // idb
PStringBase<char> Rotation; // idb
PStringBase<char> STime; // idb
PStringBase<char> PhysicsSplines; // idb
PStringBase<char> BoneOpacities; // idb
PStringBase<char> LowPt; // idb
PStringBase<char> Radius; // idb
PStringBase<char> Height; // idb
PStringBase<char> Texture2D; // idb
PStringBase<char> Texture3D; // idb
PStringBase<char> TextureCube; // idb
PStringBase<char> TextureMovie2D; // idb
PStringBase<char> MovieFileName; // idb
PStringBase<char> MovieFramesPerSecond; // idb
PStringBase<char> Levels; // idb
PStringBase<char> NodeName; // idb
PStringBase<char> Material_1; // idb
PStringBase<char> MaterialType; // idb
PStringBase<char> Modifier; // idb
PStringBase<char> AllowStencilShadows; // idb
PStringBase<char> DiscardGeometry; // idb
PStringBase<char> NodeName_0; // idb
PStringBase<char> SortMode; // idb
PStringBase<char> SortMode_None; // idb
PStringBase<char> SortMode_Triangle; // idb
PStringBase<char> NodeName_1; // idb
PStringBase<char> NodeName_2; // idb
PStringBase<char> DataType_DATA; // idb
PStringBase<char> DataType_WAVEFORM; // idb
PStringBase<char> DataType_COLOR; // idb
PStringBase<char> DataType_TEXTURE; // idb
PStringBase<char> DataType_BOOL; // idb
PStringBase<char> NodeName_3; // idb
PStringBase<char> modType_UVTranslate; // idb
PStringBase<char> modType_UVRotate; // idb
PStringBase<char> modType_UVScale; // idb
PStringBase<char> modType_UVTransform; // idb
PStringBase<char> TrueFlags; // idb
PStringBase<char> FalseFlags; // idb
PStringBase<char> RenderPass; // idb
PStringBase<char> Blend; // idb
PStringBase<char> DepthTest; // idb
PStringBase<char> DepthWrite; // idb
PStringBase<char> CullMode; // idb
PStringBase<char> DepthFog; // idb
PStringBase<char> AlphaTestMode; // idb
PStringBase<char> AlphaTestRef; // idb
PStringBase<char> FFUseLighting; // idb
PStringBase<char> FFUseDyeColorInTFactor; // idb
PStringBase<char> FFUseSpecularLighting; // idb
PStringBase<char> FFUseDistanceFog; // idb
PStringBase<char> FFUseVertexDiffuse; // idb
PStringBase<char> FFUseVertexSpecular; // idb
PStringBase<char> ShaderSupportsDynamicLights; // idb
PStringBase<char> UsesTransparency; // idb
PStringBase<char> Ambient; // idb
PStringBase<char> Diffuse_0; // idb
PStringBase<char> Specular_0; // idb
PStringBase<char> SpecularPower; // idb
PStringBase<char> Dye; // idb
PStringBase<char> Emissive; // idb
PStringBase<char> VertexFormat; // idb
PStringBase<char> VertexShader; // idb
PStringBase<char> PixelShader; // idb
PStringBase<char> param_MLF_NONE; // idb
PStringBase<char> param_MLF_REFLECTIONS; // idb
PStringBase<char> param_MLF_VIDEOPOST; // idb
PStringBase<char> param_MLF_HIGHDETAIL; // idb
PStringBase<char> param_MLF_SPECULAR; // idb
PStringBase<char> param_MLF_CLASS1; // idb
PStringBase<char> param_MLF_CLASS2; // idb
PStringBase<char> param_MLF_CLASS3; // idb
PStringBase<char> param_RenderPass_Default; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular; // idb
PStringBase<char> param_RenderPass_DistanceFog; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow; // idb
PStringBase<char> param_RenderPass_ShaderGlow; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap; // idb
PStringBase<char> param_RenderPass_AlphaBlend; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog; // idb
PStringBase<char> param_BLEND_ZERO; // idb
PStringBase<char> param_BLEND_ONE; // idb
PStringBase<char> param_BLEND_SRCCOLOR; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR; // idb
PStringBase<char> param_BLEND_SRCALPHA; // idb
PStringBase<char> param_BLEND_INVSRCALPHA; // idb
PStringBase<char> param_BLEND_DSTALPHA; // idb
PStringBase<char> param_BLEND_INVDSTALPHA; // idb
PStringBase<char> param_BLEND_DSTCOLOR; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR; // idb
PStringBase<char> param_BLEND_SRCALPHASAT; // idb
PStringBase<char> param_DEPTHTEST_LESS; // idb
PStringBase<char> param_DEPTHTEST_EQUAL; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL; // idb
PStringBase<char> param_DEPTHTEST_GREATER; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS; // idb
PStringBase<char> param_DEPTHWRITE_ON; // idb
PStringBase<char> param_DEPTHWRITE_OFF; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR; // idb
PStringBase<char> param_CULLMODE_NONE; // idb
PStringBase<char> param_CULLMODE_CW; // idb
PStringBase<char> param_CULLMODE_CCW; // idb
PStringBase<char> param_LIGHTMODE_NONE; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR; // idb
PStringBase<char> param_DEPTHFOG_OFF; // idb
PStringBase<char> param_DEPTHFOG_ON; // idb
PStringBase<char> param_ALPHATESTMODE_OFF; // idb
PStringBase<char> param_ALPHATESTMODE_ON; // idb
PStringBase<char> param_VF_ORIGIN; // idb
PStringBase<char> param_VF_NORMAL; // idb
PStringBase<char> param_VF_POINTSIZE; // idb
PStringBase<char> param_VF_DIFFUSE; // idb
PStringBase<char> param_VF_SPECULAR; // idb
PStringBase<char> param_VF_TCPAIRx1; // idb
PStringBase<char> param_VF_TCPAIRx2; // idb
PStringBase<char> param_VF_TCPAIRx3; // idb
PStringBase<char> param_VF_TCPAIRx4; // idb
PStringBase<char> param_VF_TCPAIRx5; // idb
PStringBase<char> param_VF_TCPAIRx6; // idb
PStringBase<char> param_VF_TCPAIRx7; // idb
PStringBase<char> param_VF_TCPAIRx8; // idb
PStringBase<char> param_VF_VECTOR_S; // idb
PStringBase<char> param_VF_VECTOR_T; // idb
PStringBase<char> NodeName_4; // idb
PStringBase<char> SamplerNodeName; // idb
PStringBase<char> SamplerName; // idb
PStringBase<char> Texture; // idb
PStringBase<char> SpecialTexture_FrameBuffer; // idb
PStringBase<char> SpecialTexture_Distortion; // idb
PStringBase<char> SpecialTexture_Reflection; // idb
PStringBase<char> SpecialTexture_NormalizeCube; // idb
PStringBase<char> SpecialTexture_LightProjectorCube; // idb
PStringBase<char> SpecialTexture_EnvironmentCube; // idb
PStringBase<char> SpecialTexture_LandscapeShadows; // idb
PStringBase<char> AddressMode; // idb
PStringBase<char> TexFilter; // idb
PStringBase<char> ColorOp; // idb
PStringBase<char> ColorArg1; // idb
PStringBase<char> ColorArg2; // idb
PStringBase<char> AlphaOp; // idb
PStringBase<char> AlphaArg1; // idb
PStringBase<char> AlphaArg2; // idb
PStringBase<char> TexCoord; // idb
PStringBase<char> UseProjection; // idb
PStringBase<char> param_TEXOP_SELECTARG1; // idb
PStringBase<char> param_TEXOP_SELECTARG2; // idb
PStringBase<char> param_TEXOP_MODULATE; // idb
PStringBase<char> param_TEXOP_MODULATE2X; // idb
PStringBase<char> param_TEXOP_MODULATE4X; // idb
PStringBase<char> param_TEXOP_ADD; // idb
PStringBase<char> param_TEXOP_ADDSIGNED; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X; // idb
PStringBase<char> param_TEXOP_SUBTRACT; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA; // idb
PStringBase<char> param_TEXOP_PREMODULATE; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD; // idb
PStringBase<char> param_TEXOP_LERP; // idb
PStringBase<char> param_TEXARG_DIFFUSE; // idb
PStringBase<char> param_TEXARG_SPECULAR; // idb
PStringBase<char> param_TEXARG_CURRENT; // idb
PStringBase<char> param_TEXARG_TEXTURE; // idb
PStringBase<char> param_TEXARG_TFACTOR; // idb
PStringBase<char> param_TEXADDRESS_WRAP; // idb
PStringBase<char> param_TEXADDRESS_MIRROR; // idb
PStringBase<char> param_TEXADDRESS_CLAMP; // idb
PStringBase<char> param_TEXADDRESS_BORDER; // idb
PStringBase<char> param_TEXFILTER_NONE; // idb
PStringBase<char> param_TEXFILTER_POINT; // idb
PStringBase<char> param_TEXFILTER_LINEAR; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector; // idb
PStringBase<char> param_TEXCOORD_ViewNormal; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin; // idb
PStringBase<char> param_TEXCOORD_SphereMap; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight; // idb
PStringBase<char> NodeName_5; // idb
PStringBase<char> ModType_Origin; // idb
PStringBase<char> ModType_Normal; // idb
PStringBase<char> ModType_Diffuse; // idb
PStringBase<char> ModType_UVTranslate; // idb
PStringBase<char> ModType_UVRotate; // idb
PStringBase<char> ModType_UVScale; // idb
PStringBase<char> ModType_UVTransform; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex; // idb
PStringBase<char> Mod_UVTranslate_translate; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex; // idb
PStringBase<char> Mod_UVRotate_rotate; // idb
PStringBase<char> Mod_UVScale_texCoordIndex; // idb
PStringBase<char> Mod_UVScale_scale; // idb
PStringBase<char> NodeName_6; // idb
PStringBase<char> PhysicsTimeStep; // idb
PStringBase<char> FastForwardTime; // idb
PStringBase<char> StartFadeDistance; // idb
PStringBase<char> StopFadeDistance; // idb
PStringBase<char> PhysicsDuration; // idb
PStringBase<char> ScaleType; // idb
PStringBase<char> WorldSpace; // idb
PStringBase<char> ForceDraw; // idb
PStringBase<char> NumEmitters; // idb
PStringBase<char> Material_2; // idb
PStringBase<char> Version; // idb
PStringBase<char> MaxParticles; // idb
PStringBase<char> NodeName_7; // idb
PStringBase<char> Origin_0; // idb
PStringBase<char> Shape; // idb
PStringBase<char> Shape_Point; // idb
PStringBase<char> Shape_Line; // idb
PStringBase<char> Shape_Quad; // idb
PStringBase<char> Shape_Disc; // idb
PStringBase<char> Shape_Sphere; // idb
PStringBase<char> ParticleShape; // idb
PStringBase<char> ParticleShape_Triangle; // idb
PStringBase<char> ParticleShape_Quad; // idb
PStringBase<char> Streak; // idb
PStringBase<char> Rotation_0; // idb
PStringBase<char> WorldRotation; // idb
PStringBase<char> RotateVelocity; // idb
PStringBase<char> ParticleScale; // idb
PStringBase<char> Scale_0; // idb
PStringBase<char> ExplodingDir; // idb
PStringBase<char> BirthRate; // idb
PStringBase<char> Lifespan; // idb
PStringBase<char> Velocity; // idb
PStringBase<char> Direction; // idb
PStringBase<char> MinSpread; // idb
PStringBase<char> MaxSpread; // idb
PStringBase<char> EmissionLimit; // idb
PStringBase<char> BlastCount; // idb
PStringBase<char> StartTime; // idb
PStringBase<char> TimeLimit; // idb
PStringBase<char> EmissionDistance; // idb
PStringBase<char> ParticleSnap; // idb
PStringBase<char> InclusiveShape; // idb
PStringBase<char> NumKeyframes; // idb
PStringBase<char> IsActive; // idb
PStringBase<char> FadeIn; // idb
PStringBase<char> FadeOut; // idb
PStringBase<char> ConstrainX; // idb
PStringBase<char> ConstrainY; // idb
PStringBase<char> ConstrainZ; // idb
PStringBase<char> NodeName_8; // idb
PStringBase<char> Time; // idb
PStringBase<char> Flags; // idb
PStringBase<char> Flags_None; // idb
PStringBase<char> Flags_BlendScale; // idb
PStringBase<char> Flags_BlendColor; // idb
PStringBase<char> Flags_BlendMass; // idb
PStringBase<char> Flags_SetScale; // idb
PStringBase<char> Flags_SetColor; // idb
PStringBase<char> Flags_SetMass; // idb
PStringBase<char> Flags_SetPFlags; // idb
PStringBase<char> Flags_SetPCType; // idb
PStringBase<char> Flags_SetPhysFlags; // idb
PStringBase<char> Flags_SetParams; // idb
PStringBase<char> Scale_1; // idb
PStringBase<char> ScaleX; // idb
PStringBase<char> ScaleY; // idb
PStringBase<char> Color; // idb
PStringBase<char> Mass; // idb
PStringBase<char> PFlags; // idb
PStringBase<char> PFlags_None; // idb
PStringBase<char> PCType; // idb
PStringBase<char> PCType_None; // idb
PStringBase<char> PCType_Physics; // idb
PStringBase<char> PCType_Parametric; // idb
PStringBase<char> PCType_AttractRepulse; // idb
PStringBase<char> PCType_PointFile; // idb
PStringBase<char> PCType_PointFileLerp; // idb
PStringBase<char> PhysFlags; // idb
PStringBase<char> PhysFlags_None; // idb
PStringBase<char> PhysFlags_Gravity; // idb
PStringBase<char> PhysFlags_Wind; // idb
PStringBase<char> PhysFlags_Momentum; // idb
PStringBase<char> PointfileFlags_RandomPoint; // idb
PStringBase<char> Position_0; // idb
PStringBase<char> PointList; // idb
PStringBase<char> Point_0; // idb
PStringBase<char> DetailLevels; // idb
PStringBase<char> DetailLevel_Low; // idb
PStringBase<char> DetailLevel_Medium; // idb
PStringBase<char> DetailLevel_High; // idb
PStringBase<char> FadeSpeed; // idb
PStringBase<char> MaxOpacity; // idb
PStringBase<char> Point_1; // idb
PStringBase<char> PointAxisPos; // idb
PStringBase<char> PointTexture; // idb
PStringBase<char> PointSize; // idb
PStringBase<char> UseOcclusion; // idb
PStringBase<char> PreprocHeader; // idb
PStringBase<char> MeshAppearanceType; // idb
PStringBase<char> Fragment; // idb
PStringBase<char> FragmentType; // idb
PStringBase<char> FragmentType_LevelOfDetailModel; // idb
PStringBase<char> FragmentType_OccludeModel; // idb
PStringBase<char> FragmentType_ShadowLODModel; // idb
PStringBase<char> FragmentTopology; // idb
PStringBase<char> FragmentMOPP; // idb
PStringBase<char> MaterialBatch; // idb
PStringBase<char> FragmentBatch; // idb
PStringBase<char> PrimitivesType; // idb
PStringBase<char> PrimitivesType_PointList; // idb
PStringBase<char> PrimitivesType_LineList; // idb
PStringBase<char> PrimitivesType_LineStrip; // idb
PStringBase<char> PrimitivesType_TriangleList; // idb
PStringBase<char> PrimitivesType_TriangleStrip; // idb
PStringBase<char> PrimitivesType_TriangleFan; // idb
PStringBase<char> Material_3; // idb
PStringBase<char> Vertices; // idb
PStringBase<char> Indices_0; // idb
PStringBase<char> ExportMeshAppearanceType; // idb
PStringBase<char> MeshDegradeType; // idb
PStringBase<char> DegradeLevel; // idb
PStringBase<char> NumDegradeLevels; // idb
PStringBase<char> CellMesh; // idb
PStringBase<char> MaterialArray; // idb
PStringBase<char> Render; // idb
PStringBase<char> RenderMesh; // idb
PStringBase<char> RenderMeshVersion; // idb
PStringBase<char> Sphere_0; // idb
PStringBase<char> DetailedBSP; // idb
PStringBase<char> PolygonArray; // idb
PStringBase<char> BinaryPolygonArray; // idb
PStringBase<char> Physics; // idb
PStringBase<char> BSPTree; // idb
PStringBase<char> BinaryBSPTree; // idb
PStringBase<char> Cell; // idb
PStringBase<char> CellBSP; // idb
PStringBase<char> Portals; // idb
PStringBase<char> Portal_0; // idb
PStringBase<char> NonPortals; // idb
PStringBase<char> NonPortal; // idb
PStringBase<char> Info; // idb
PStringBase<char> CellVolumeInfo; // idb
PStringBase<char> CellStructure; // idb
PStringBase<char> CellRotation; // idb
PStringBase<char> CellGridSize; // idb
PStringBase<char> CellNeverCull; // idb
PStringBase<char> CellDrawSky; // idb
PStringBase<char> DegradeArray; // idb
PStringBase<char> OccludeMeshArray; // idb
PStringBase<char> DegradeMesh; // idb
PStringBase<char> BSP; // idb
PStringBase<char> BumpMap; // idb
PStringBase<char> UVSets; // idb
PStringBase<char> PhysicsMesh; // idb
PStringBase<char> PhysicsMaterials; // idb
PStringBase<char> PhysicsMaterialArray; // idb
PStringBase<char> PathMapMeshArray; // idb
PStringBase<char> PathMapPolygonArray; // idb
PStringBase<char> PathMapPolygon; // idb
PStringBase<char> VertexSetArray; // idb
PStringBase<char> VertexSets; // idb
PStringBase<char> VertexSet; // idb
PStringBase<char> Set; // idb
PStringBase<char> ID_1; // idb
PStringBase<char> Name; // idb
PStringBase<char> Indices_1; // idb
PStringBase<char> MorphMeshArray; // idb
PStringBase<char> MorphMesh; // idb
PStringBase<char> MorphTargets; // idb
PStringBase<char> Target; // idb
PStringBase<char> Name_0; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_13; // idb
SmartArray<GraphicsResource *,1> GraphicsResource::s_Resources; // idb
PStringBase<char> waveform_None_12; // idb
PStringBase<char> waveform_Speed_12; // idb
PStringBase<char> waveform_Noise_12; // idb
PStringBase<char> waveform_Sine_12; // idb
PStringBase<char> waveform_Square_12; // idb
PStringBase<char> waveform_Bounce_12; // idb
PStringBase<char> waveform_Perlin_12; // idb
PStringBase<char> waveform_Fractal_12; // idb
PStringBase<char> waveform_FrameLoop_12; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_14; // idb
const float dword_838948; // idb
const float outside_val_11; // idb
const float block_length_11; // idb
const float half_square_length_11; // idb
PStringBase<char> Render_TextureFiltering_6; // idb
PStringBase<char> Render_LandscapeDetailTextures_6; // idb
PStringBase<char> Render_BuildingDetailTextures_6; // idb
PStringBase<char> Render_FieldOfView_6; // idb
PStringBase<char> Render_LandscapeTextureDetail_6; // idb
PStringBase<char> Render_EnvironmentTextureDetail_6; // idb
PStringBase<char> Render_SceneryDrawDistance_6; // idb
PStringBase<char> Render_LandscapeDrawDistance_6; // idb
PStringBase<char> Render_ScreenBrightness_6; // idb
PStringBase<char> Render_AspectRatio_6; // idb
PStringBase<char> Render_DisplayAdapter_6; // idb
PStringBase<char> Render_MaxHardwareClass_6; // idb
PStringBase<char> Render_AutomaticDegrades_6; // idb
PStringBase<char> Render_GraphicsPerformance_6; // idb
PStringBase<char> Render_DegradeDistance_6; // idb
PStringBase<char> Render_MultiPassAlpha_6; // idb
PStringBase<char> Render_TextureFiltering_Choices_6[4]; // idb
PStringBase<char> stru_8389A0; // idb
PStringBase<char> stru_8389A4; // idb
PStringBase<char> stru_8389A8; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_6[5]; // idb
PStringBase<char> stru_8389B0; // idb
PStringBase<char> stru_8389B4; // idb
PStringBase<char> stru_8389B8; // idb
PStringBase<char> stru_8389BC; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_6[5]; // idb
PStringBase<char> stru_8389C4; // idb
PStringBase<char> stru_8389C8; // idb
PStringBase<char> stru_8389CC; // idb
PStringBase<char> stru_8389D0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_6[3]; // idb
PStringBase<char> stru_8389D8; // idb
PStringBase<char> stru_8389DC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_6[6]; // idb
PStringBase<char> stru_8389E4; // idb
PStringBase<char> stru_8389E8; // idb
PStringBase<char> stru_8389EC; // idb
PStringBase<char> stru_8389F0; // idb
PStringBase<char> stru_8389F4; // idb
PStringBase<char> Render_AspectRatio_Choices_6[3]; // idb
PStringBase<char> stru_8389FC; // idb
PStringBase<char> stru_838A00; // idb
const float DEFAULT_VIEW_RADIUS_4; // idb
const long double MIN_QUANTUM_4; // idb
const long double MAX_QUANTUM_4; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_15; // idb
const float dword_838A6C; // idb
const float outside_val_12; // idb
const float block_length_12; // idb
const float half_square_length_12; // idb
IDClass<_tagDataID,32,0> INVALID_DID_36; // idb
PStringBase<char> Render_TextureFiltering_7; // idb
PStringBase<char> Render_LandscapeDetailTextures_7; // idb
PStringBase<char> Render_BuildingDetailTextures_7; // idb
PStringBase<char> Render_FieldOfView_7; // idb
PStringBase<char> Render_LandscapeTextureDetail_7; // idb
PStringBase<char> Render_EnvironmentTextureDetail_7; // idb
PStringBase<char> Render_SceneryDrawDistance_7; // idb
PStringBase<char> Render_LandscapeDrawDistance_7; // idb
PStringBase<char> Render_ScreenBrightness_7; // idb
PStringBase<char> Render_AspectRatio_7; // idb
PStringBase<char> Render_DisplayAdapter_7; // idb
PStringBase<char> Render_MaxHardwareClass_7; // idb
PStringBase<char> Render_AutomaticDegrades_7; // idb
PStringBase<char> Render_GraphicsPerformance_7; // idb
PStringBase<char> Render_DegradeDistance_7; // idb
PStringBase<char> Render_MultiPassAlpha_7; // idb
PStringBase<char> Render_TextureFiltering_Choices_7[4]; // idb
PStringBase<char> stru_838AC4; // idb
PStringBase<char> stru_838AC8; // idb
PStringBase<char> stru_838ACC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_7[5]; // idb
PStringBase<char> stru_838AD4; // idb
PStringBase<char> stru_838AD8; // idb
PStringBase<char> stru_838ADC; // idb
PStringBase<char> stru_838AE0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_7[5]; // idb
PStringBase<char> stru_838AE8; // idb
PStringBase<char> stru_838AEC; // idb
PStringBase<char> stru_838AF0; // idb
PStringBase<char> stru_838AF4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_7[3]; // idb
PStringBase<char> stru_838AFC; // idb
PStringBase<char> stru_838B00; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_7[6]; // idb
PStringBase<char> stru_838B08; // idb
PStringBase<char> stru_838B0C; // idb
PStringBase<char> stru_838B10; // idb
PStringBase<char> stru_838B14; // idb
PStringBase<char> stru_838B18; // idb
PStringBase<char> Render_AspectRatio_Choices_7[3]; // idb
PStringBase<char> stru_838B20; // idb
PStringBase<char> stru_838B24; // idb
PStringBase<char> waveform_None_13; // idb
PStringBase<char> waveform_Speed_13; // idb
PStringBase<char> waveform_Noise_13; // idb
PStringBase<char> waveform_Sine_13; // idb
PStringBase<char> waveform_Square_13; // idb
PStringBase<char> waveform_Bounce_13; // idb
PStringBase<char> waveform_Perlin_13; // idb
PStringBase<char> waveform_Fractal_13; // idb
PStringBase<char> waveform_FrameLoop_13; // idb
PStringBase<char> PHeader_0; // idb
PStringBase<char> VertexArray_0; // idb
PStringBase<char> BinaryVertexArray_0; // idb
PStringBase<char> VertexType_1; // idb
PStringBase<char> VertexData_0; // idb
PStringBase<char> Vertex_0; // idb
PStringBase<char> Index_1; // idb
PStringBase<char> Origin_1; // idb
PStringBase<char> Normal_0; // idb
PStringBase<char> Diffuse_1; // idb
PStringBase<char> Specular_1; // idb
PStringBase<char> UVS_0; // idb
PStringBase<char> VectorS_0; // idb
PStringBase<char> VectorT_0; // idb
PStringBase<char> VectorSxT_0; // idb
PStringBase<char> Weights_0; // idb
PStringBase<char> Importance_0; // idb
PStringBase<char> PhysMtl_0; // idb
PStringBase<char> Material_4; // idb
PStringBase<char> ID_2; // idb
PStringBase<char> FileName_0; // idb
PStringBase<char> Polygon_1; // idb
PStringBase<char> ID_3; // idb
PStringBase<char> Indices_2; // idb
PStringBase<char> MaterialID_0; // idb
PStringBase<char> PhysMaterialID_0; // idb
PStringBase<char> Markings_0; // idb
PStringBase<char> Material_5; // idb
PStringBase<char> Index_2; // idb
PStringBase<char> Filename_0; // idb
PStringBase<char> Surface_0; // idb
PStringBase<char> CellPoly_0; // idb
PStringBase<char> Sphere_1; // idb
PStringBase<char> Side_0; // idb
PStringBase<char> Positive_0; // idb
PStringBase<char> Negative_0; // idb
PStringBase<char> Polygon_2; // idb
PStringBase<char> OtherCell_1; // idb
PStringBase<char> CellPortal_0; // idb
PStringBase<char> Portal_1; // idb
PStringBase<char> OtherCell_2; // idb
PStringBase<char> OtherPortal_0; // idb
PStringBase<char> ExactMatch_0; // idb
PStringBase<char> StabList_0; // idb
PStringBase<char> Period_0; // idb
PStringBase<char> GrannyAnimation_0; // idb
PStringBase<char> Transform_0; // idb
PStringBase<char> Scale_2; // idb
PStringBase<char> Weight_0; // idb
PStringBase<char> Offset_0; // idb
PStringBase<char> Quaternion_1; // idb
PStringBase<char> Rotation_1; // idb
PStringBase<char> STime_0; // idb
PStringBase<char> PhysicsSplines_0; // idb
PStringBase<char> BoneOpacities_0; // idb
PStringBase<char> LowPt_0; // idb
PStringBase<char> Radius_0; // idb
PStringBase<char> Height_0; // idb
PStringBase<char> Texture2D_0; // idb
PStringBase<char> Texture3D_0; // idb
PStringBase<char> TextureCube_0; // idb
PStringBase<char> TextureMovie2D_0; // idb
PStringBase<char> MovieFileName_0; // idb
PStringBase<char> MovieFramesPerSecond_0; // idb
PStringBase<char> Levels_0; // idb
PStringBase<char> NodeName_9; // idb
PStringBase<char> Material_6; // idb
PStringBase<char> MaterialType_0; // idb
PStringBase<char> Modifier_0; // idb
PStringBase<char> AllowStencilShadows_0; // idb
PStringBase<char> DiscardGeometry_0; // idb
PStringBase<char> NodeName_10; // idb
PStringBase<char> SortMode_0; // idb
PStringBase<char> SortMode_None_0; // idb
PStringBase<char> SortMode_Triangle_0; // idb
PStringBase<char> NodeName_11; // idb
PStringBase<char> NodeName_12; // idb
PStringBase<char> DataType_DATA_0; // idb
PStringBase<char> DataType_WAVEFORM_0; // idb
PStringBase<char> DataType_COLOR_0; // idb
PStringBase<char> DataType_TEXTURE_0; // idb
PStringBase<char> DataType_BOOL_0; // idb
PStringBase<char> NodeName_13; // idb
PStringBase<char> modType_UVTranslate_0; // idb
PStringBase<char> modType_UVRotate_0; // idb
PStringBase<char> modType_UVScale_0; // idb
PStringBase<char> modType_UVTransform_0; // idb
PStringBase<char> TrueFlags_0; // idb
PStringBase<char> FalseFlags_0; // idb
PStringBase<char> RenderPass_0; // idb
PStringBase<char> Blend_0; // idb
PStringBase<char> DepthTest_0; // idb
PStringBase<char> DepthWrite_0; // idb
PStringBase<char> CullMode_0; // idb
PStringBase<char> DepthFog_0; // idb
PStringBase<char> AlphaTestMode_0; // idb
PStringBase<char> AlphaTestRef_0; // idb
PStringBase<char> FFUseLighting_0; // idb
PStringBase<char> FFUseDyeColorInTFactor_0; // idb
PStringBase<char> FFUseSpecularLighting_0; // idb
PStringBase<char> FFUseDistanceFog_0; // idb
PStringBase<char> FFUseVertexDiffuse_0; // idb
PStringBase<char> FFUseVertexSpecular_0; // idb
PStringBase<char> ShaderSupportsDynamicLights_0; // idb
PStringBase<char> UsesTransparency_0; // idb
PStringBase<char> Ambient_0; // idb
PStringBase<char> Diffuse_2; // idb
PStringBase<char> Specular_2; // idb
PStringBase<char> SpecularPower_0; // idb
PStringBase<char> Dye_0; // idb
PStringBase<char> Emissive_0; // idb
PStringBase<char> VertexFormat_0; // idb
PStringBase<char> VertexShader_0; // idb
PStringBase<char> PixelShader_0; // idb
PStringBase<char> param_MLF_NONE_0; // idb
PStringBase<char> param_MLF_REFLECTIONS_0; // idb
PStringBase<char> param_MLF_VIDEOPOST_0; // idb
PStringBase<char> param_MLF_HIGHDETAIL_0; // idb
PStringBase<char> param_MLF_SPECULAR_0; // idb
PStringBase<char> param_MLF_CLASS1_0; // idb
PStringBase<char> param_MLF_CLASS2_0; // idb
PStringBase<char> param_MLF_CLASS3_0; // idb
PStringBase<char> param_RenderPass_Default_0; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_0; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_0; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_0; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_0; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_0; // idb
PStringBase<char> param_RenderPass_DistanceFog_0; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_0; // idb
PStringBase<char> param_RenderPass_ShaderGlow_0; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_0; // idb
PStringBase<char> param_RenderPass_AlphaBlend_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_0; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_0; // idb
PStringBase<char> param_BLEND_ZERO_0; // idb
PStringBase<char> param_BLEND_ONE_0; // idb
PStringBase<char> param_BLEND_SRCCOLOR_0; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_0; // idb
PStringBase<char> param_BLEND_SRCALPHA_0; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_0; // idb
PStringBase<char> param_BLEND_DSTALPHA_0; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_0; // idb
PStringBase<char> param_BLEND_DSTCOLOR_0; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_0; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_0; // idb
PStringBase<char> param_DEPTHTEST_LESS_0; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_0; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_0; // idb
PStringBase<char> param_DEPTHTEST_GREATER_0; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_0; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_0; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_0; // idb
PStringBase<char> param_DEPTHWRITE_ON_0; // idb
PStringBase<char> param_DEPTHWRITE_OFF_0; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_0; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_0; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_0; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_0; // idb
PStringBase<char> param_CULLMODE_NONE_0; // idb
PStringBase<char> param_CULLMODE_CW_0; // idb
PStringBase<char> param_CULLMODE_CCW_0; // idb
PStringBase<char> param_LIGHTMODE_NONE_0; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_0; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_0; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_0; // idb
PStringBase<char> param_DEPTHFOG_OFF_0; // idb
PStringBase<char> param_DEPTHFOG_ON_0; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_0; // idb
PStringBase<char> param_ALPHATESTMODE_ON_0; // idb
PStringBase<char> param_VF_ORIGIN_0; // idb
PStringBase<char> param_VF_NORMAL_0; // idb
PStringBase<char> param_VF_POINTSIZE_0; // idb
PStringBase<char> param_VF_DIFFUSE_0; // idb
PStringBase<char> param_VF_SPECULAR_0; // idb
PStringBase<char> param_VF_TCPAIRx1_0; // idb
PStringBase<char> param_VF_TCPAIRx2_0; // idb
PStringBase<char> param_VF_TCPAIRx3_0; // idb
PStringBase<char> param_VF_TCPAIRx4_0; // idb
PStringBase<char> param_VF_TCPAIRx5_0; // idb
PStringBase<char> param_VF_TCPAIRx6_0; // idb
PStringBase<char> param_VF_TCPAIRx7_0; // idb
PStringBase<char> param_VF_TCPAIRx8_0; // idb
PStringBase<char> param_VF_VECTOR_S_0; // idb
PStringBase<char> param_VF_VECTOR_T_0; // idb
PStringBase<char> NodeName_14; // idb
PStringBase<char> SamplerNodeName_0; // idb
PStringBase<char> SamplerName_0; // idb
PStringBase<char> Texture_0; // idb
PStringBase<char> SpecialTexture_FrameBuffer_0; // idb
PStringBase<char> SpecialTexture_Distortion_0; // idb
PStringBase<char> SpecialTexture_Reflection_0; // idb
PStringBase<char> SpecialTexture_NormalizeCube_0; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_0; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_0; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_0; // idb
PStringBase<char> AddressMode_0; // idb
PStringBase<char> TexFilter_0; // idb
PStringBase<char> ColorOp_0; // idb
PStringBase<char> ColorArg1_0; // idb
PStringBase<char> ColorArg2_0; // idb
PStringBase<char> AlphaOp_0; // idb
PStringBase<char> AlphaArg1_0; // idb
PStringBase<char> AlphaArg2_0; // idb
PStringBase<char> TexCoord_0; // idb
PStringBase<char> UseProjection_0; // idb
PStringBase<char> param_TEXOP_SELECTARG1_0; // idb
PStringBase<char> param_TEXOP_SELECTARG2_0; // idb
PStringBase<char> param_TEXOP_MODULATE_0; // idb
PStringBase<char> param_TEXOP_MODULATE2X_0; // idb
PStringBase<char> param_TEXOP_MODULATE4X_0; // idb
PStringBase<char> param_TEXOP_ADD_0; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_0; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_0; // idb
PStringBase<char> param_TEXOP_SUBTRACT_0; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_0; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_0; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_0; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_0; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_0; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_0; // idb
PStringBase<char> param_TEXOP_PREMODULATE_0; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_0; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_0; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_0; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_0; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_0; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_0; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_0; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_0; // idb
PStringBase<char> param_TEXOP_LERP_0; // idb
PStringBase<char> param_TEXARG_DIFFUSE_0; // idb
PStringBase<char> param_TEXARG_SPECULAR_0; // idb
PStringBase<char> param_TEXARG_CURRENT_0; // idb
PStringBase<char> param_TEXARG_TEXTURE_0; // idb
PStringBase<char> param_TEXARG_TFACTOR_0; // idb
PStringBase<char> param_TEXADDRESS_WRAP_0; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_0; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_0; // idb
PStringBase<char> param_TEXADDRESS_BORDER_0; // idb
PStringBase<char> param_TEXFILTER_NONE_0; // idb
PStringBase<char> param_TEXFILTER_POINT_0; // idb
PStringBase<char> param_TEXFILTER_LINEAR_0; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_0; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_0; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_0; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_0; // idb
PStringBase<char> param_TEXCOORD_SphereMap_0; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_0; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_0; // idb
PStringBase<char> NodeName_15; // idb
PStringBase<char> ModType_Origin_0; // idb
PStringBase<char> ModType_Normal_0; // idb
PStringBase<char> ModType_Diffuse_0; // idb
PStringBase<char> ModType_UVTranslate_0; // idb
PStringBase<char> ModType_UVRotate_0; // idb
PStringBase<char> ModType_UVScale_0; // idb
PStringBase<char> ModType_UVTransform_0; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_0; // idb
PStringBase<char> Mod_UVTranslate_translate_0; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_0; // idb
PStringBase<char> Mod_UVRotate_rotate_0; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_0; // idb
PStringBase<char> Mod_UVScale_scale_0; // idb
PStringBase<char> NodeName_16; // idb
PStringBase<char> PhysicsTimeStep_0; // idb
PStringBase<char> FastForwardTime_0; // idb
PStringBase<char> StartFadeDistance_0; // idb
PStringBase<char> StopFadeDistance_0; // idb
PStringBase<char> PhysicsDuration_0; // idb
PStringBase<char> ScaleType_0; // idb
PStringBase<char> WorldSpace_0; // idb
PStringBase<char> ForceDraw_0; // idb
PStringBase<char> NumEmitters_0; // idb
PStringBase<char> Material_7; // idb
PStringBase<char> Version_0; // idb
PStringBase<char> MaxParticles_0; // idb
PStringBase<char> NodeName_17; // idb
PStringBase<char> Origin_2; // idb
PStringBase<char> Shape_0; // idb
PStringBase<char> Shape_Point_0; // idb
PStringBase<char> Shape_Line_0; // idb
PStringBase<char> Shape_Quad_0; // idb
PStringBase<char> Shape_Disc_0; // idb
PStringBase<char> Shape_Sphere_0; // idb
PStringBase<char> ParticleShape_0; // idb
PStringBase<char> ParticleShape_Triangle_0; // idb
PStringBase<char> ParticleShape_Quad_0; // idb
PStringBase<char> Streak_0; // idb
PStringBase<char> Rotation_2; // idb
PStringBase<char> WorldRotation_0; // idb
PStringBase<char> RotateVelocity_0; // idb
PStringBase<char> ParticleScale_0; // idb
PStringBase<char> Scale_3; // idb
PStringBase<char> ExplodingDir_0; // idb
PStringBase<char> BirthRate_0; // idb
PStringBase<char> Lifespan_0; // idb
PStringBase<char> Velocity_0; // idb
PStringBase<char> Direction_0; // idb
PStringBase<char> MinSpread_0; // idb
PStringBase<char> MaxSpread_0; // idb
PStringBase<char> EmissionLimit_0; // idb
PStringBase<char> BlastCount_0; // idb
PStringBase<char> StartTime_0; // idb
PStringBase<char> TimeLimit_0; // idb
PStringBase<char> EmissionDistance_0; // idb
PStringBase<char> ParticleSnap_0; // idb
PStringBase<char> InclusiveShape_0; // idb
PStringBase<char> NumKeyframes_0; // idb
PStringBase<char> IsActive_0; // idb
PStringBase<char> FadeIn_0; // idb
PStringBase<char> FadeOut_0; // idb
PStringBase<char> ConstrainX_0; // idb
PStringBase<char> ConstrainY_0; // idb
PStringBase<char> ConstrainZ_0; // idb
PStringBase<char> NodeName_18; // idb
PStringBase<char> Time_0; // idb
PStringBase<char> Flags_0; // idb
PStringBase<char> Flags_None_0; // idb
PStringBase<char> Flags_BlendScale_0; // idb
PStringBase<char> Flags_BlendColor_0; // idb
PStringBase<char> Flags_BlendMass_0; // idb
PStringBase<char> Flags_SetScale_0; // idb
PStringBase<char> Flags_SetColor_0; // idb
PStringBase<char> Flags_SetMass_0; // idb
PStringBase<char> Flags_SetPFlags_0; // idb
PStringBase<char> Flags_SetPCType_0; // idb
PStringBase<char> Flags_SetPhysFlags_0; // idb
PStringBase<char> Flags_SetParams_0; // idb
PStringBase<char> Scale_4; // idb
PStringBase<char> ScaleX_0; // idb
PStringBase<char> ScaleY_0; // idb
PStringBase<char> Color_0; // idb
PStringBase<char> Mass_0; // idb
PStringBase<char> PFlags_0; // idb
PStringBase<char> PFlags_None_0; // idb
PStringBase<char> PCType_0; // idb
PStringBase<char> PCType_None_0; // idb
PStringBase<char> PCType_Physics_0; // idb
PStringBase<char> PCType_Parametric_0; // idb
PStringBase<char> PCType_AttractRepulse_0; // idb
PStringBase<char> PCType_PointFile_0; // idb
PStringBase<char> PCType_PointFileLerp_0; // idb
PStringBase<char> PhysFlags_0; // idb
PStringBase<char> PhysFlags_None_0; // idb
PStringBase<char> PhysFlags_Gravity_0; // idb
PStringBase<char> PhysFlags_Wind_0; // idb
PStringBase<char> PhysFlags_Momentum_0; // idb
PStringBase<char> PointfileFlags_RandomPoint_0; // idb
PStringBase<char> Position_1; // idb
PStringBase<char> PointList_0; // idb
PStringBase<char> Point_2; // idb
PStringBase<char> DetailLevels_0; // idb
PStringBase<char> DetailLevel_Low_0; // idb
PStringBase<char> DetailLevel_Medium_0; // idb
PStringBase<char> DetailLevel_High_0; // idb
PStringBase<char> FadeSpeed_0; // idb
PStringBase<char> MaxOpacity_0; // idb
PStringBase<char> Point_3; // idb
PStringBase<char> PointAxisPos_0; // idb
PStringBase<char> PointTexture_0; // idb
PStringBase<char> PointSize_0; // idb
PStringBase<char> UseOcclusion_0; // idb
PStringBase<char> PHEADER_STRINGS_0[4]; // idb
PStringBase<char> stru_83917C; // idb
PStringBase<char> stru_839180; // idb
PStringBase<char> stru_839184; // idb
_UNKNOWN unk_839188; // weak
RenderIndexBuffer *RenderUI::s_pUISurfaceIB; // idb
bool RenderUI::s_bCurrentlyRendering; // weak
unsigned __int32 RenderUI::s_sceneID; // weak
PixelFormatDesc PixelFormatDesc_A8R8G8B8_16; // idb
const float dword_8391E8; // idb
const float outside_val_13; // idb
const float block_length_13; // idb
const float half_square_length_13; // idb
PStringBase<char> Render_TextureFiltering_8; // idb
PStringBase<char> Render_LandscapeDetailTextures_8; // idb
PStringBase<char> Render_BuildingDetailTextures_8; // idb
PStringBase<char> Render_FieldOfView_8; // idb
PStringBase<char> Render_LandscapeTextureDetail_8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_8; // idb
PStringBase<char> Render_SceneryDrawDistance_8; // idb
PStringBase<char> Render_LandscapeDrawDistance_8; // idb
PStringBase<char> Render_ScreenBrightness_8; // idb
PStringBase<char> Render_AspectRatio_8; // idb
PStringBase<char> Render_DisplayAdapter_8; // idb
PStringBase<char> Render_MaxHardwareClass_8; // idb
PStringBase<char> Render_AutomaticDegrades_8; // idb
PStringBase<char> Render_GraphicsPerformance_8; // idb
PStringBase<char> Render_DegradeDistance_8; // idb
PStringBase<char> Render_MultiPassAlpha_8; // idb
PStringBase<char> Render_TextureFiltering_Choices_8[4]; // idb
PStringBase<char> stru_839240; // idb
PStringBase<char> stru_839244; // idb
PStringBase<char> stru_839248; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_8[5]; // idb
PStringBase<char> stru_839250; // idb
PStringBase<char> stru_839254; // idb
PStringBase<char> stru_839258; // idb
PStringBase<char> stru_83925C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_8[5]; // idb
PStringBase<char> stru_839264; // idb
PStringBase<char> stru_839268; // idb
PStringBase<char> stru_83926C; // idb
PStringBase<char> stru_839270; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_8[3]; // idb
PStringBase<char> stru_839278; // idb
PStringBase<char> stru_83927C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_8[6]; // idb
PStringBase<char> stru_839284; // idb
PStringBase<char> stru_839288; // idb
PStringBase<char> stru_83928C; // idb
PStringBase<char> stru_839290; // idb
PStringBase<char> stru_839294; // idb
PStringBase<char> Render_AspectRatio_Choices_8[3]; // idb
PStringBase<char> stru_83929C; // idb
PStringBase<char> stru_8392A0; // idb
PStringBase<char> waveform_None_14; // idb
PStringBase<char> waveform_Speed_14; // idb
PStringBase<char> waveform_Noise_14; // idb
PStringBase<char> waveform_Sine_14; // idb
PStringBase<char> waveform_Square_14; // idb
PStringBase<char> waveform_Bounce_14; // idb
PStringBase<char> waveform_Perlin_14; // idb
PStringBase<char> waveform_Fractal_14; // idb
PStringBase<char> waveform_FrameLoop_14; // idb
HashList<unsigned long,ActionMapValue,1> RenderUI::s_hlObjects; // idb
PStringBase<char> waveform_None_15; // idb
PStringBase<char> waveform_Speed_15; // idb
PStringBase<char> waveform_Noise_15; // idb
PStringBase<char> waveform_Sine_15; // idb
PStringBase<char> waveform_Square_15; // idb
PStringBase<char> waveform_Bounce_15; // idb
PStringBase<char> waveform_Perlin_15; // idb
PStringBase<char> waveform_Fractal_15; // idb
PStringBase<char> waveform_FrameLoop_15; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_17; // idb
PStringBase<char> PHeader_1; // idb
PStringBase<char> VertexArray_1; // idb
PStringBase<char> BinaryVertexArray_1; // idb
PStringBase<char> VertexType_2; // idb
PStringBase<char> VertexData_1; // idb
PStringBase<char> Vertex_1; // idb
PStringBase<char> Index_3; // idb
PStringBase<char> Origin_3; // idb
PStringBase<char> Normal_1; // idb
PStringBase<char> Diffuse_3; // idb
PStringBase<char> Specular_3; // idb
PStringBase<char> UVS_1; // idb
PStringBase<char> VectorS_1; // idb
PStringBase<char> VectorT_1; // idb
PStringBase<char> VectorSxT_1; // idb
PStringBase<char> Weights_1; // idb
PStringBase<char> Importance_1; // idb
PStringBase<char> PhysMtl_1; // idb
PStringBase<char> Material_8; // idb
PStringBase<char> ID_4; // idb
PStringBase<char> FileName_1; // idb
PStringBase<char> Polygon_3; // idb
PStringBase<char> ID_5; // idb
PStringBase<char> Indices_3; // idb
PStringBase<char> MaterialID_1; // idb
PStringBase<char> PhysMaterialID_1; // idb
PStringBase<char> Markings_1; // idb
PStringBase<char> Material_9; // idb
PStringBase<char> Index_4; // idb
PStringBase<char> Filename_1; // idb
PStringBase<char> Surface_1; // idb
PStringBase<char> CellPoly_1; // idb
PStringBase<char> Sphere_2; // idb
PStringBase<char> Side_1; // idb
PStringBase<char> Positive_1; // idb
PStringBase<char> Negative_1; // idb
PStringBase<char> Polygon_4; // idb
PStringBase<char> OtherCell_3; // idb
PStringBase<char> CellPortal_1; // idb
PStringBase<char> Portal_2; // idb
PStringBase<char> OtherCell_4; // idb
PStringBase<char> OtherPortal_1; // idb
PStringBase<char> ExactMatch_1; // idb
PStringBase<char> StabList_1; // idb
PStringBase<char> Period_1; // idb
PStringBase<char> GrannyAnimation_1; // idb
PStringBase<char> Transform_1; // idb
PStringBase<char> Scale_5; // idb
PStringBase<char> Weight_1; // idb
PStringBase<char> Offset_1; // idb
PStringBase<char> Quaternion_2; // idb
PStringBase<char> Rotation_3; // idb
PStringBase<char> STime_1; // idb
PStringBase<char> PhysicsSplines_1; // idb
PStringBase<char> BoneOpacities_1; // idb
PStringBase<char> LowPt_1; // idb
PStringBase<char> Radius_1; // idb
PStringBase<char> Height_1; // idb
PStringBase<char> Texture2D_1; // idb
PStringBase<char> Texture3D_1; // idb
PStringBase<char> TextureCube_1; // idb
PStringBase<char> TextureMovie2D_1; // idb
PStringBase<char> MovieFileName_1; // idb
PStringBase<char> MovieFramesPerSecond_1; // idb
PStringBase<char> Levels_1; // idb
PStringBase<char> NodeName_19; // idb
PStringBase<char> Material_10; // idb
PStringBase<char> MaterialType_1; // idb
PStringBase<char> Modifier_1; // idb
PStringBase<char> AllowStencilShadows_1; // idb
PStringBase<char> DiscardGeometry_1; // idb
PStringBase<char> NodeName_20; // idb
PStringBase<char> SortMode_1; // idb
PStringBase<char> SortMode_None_1; // idb
PStringBase<char> SortMode_Triangle_1; // idb
PStringBase<char> NodeName_21; // idb
PStringBase<char> NodeName_22; // idb
PStringBase<char> DataType_DATA_1; // idb
PStringBase<char> DataType_WAVEFORM_1; // idb
PStringBase<char> DataType_COLOR_1; // idb
PStringBase<char> DataType_TEXTURE_1; // idb
PStringBase<char> DataType_BOOL_1; // idb
PStringBase<char> NodeName_23; // idb
PStringBase<char> modType_UVTranslate_1; // idb
PStringBase<char> modType_UVRotate_1; // idb
PStringBase<char> modType_UVScale_1; // idb
PStringBase<char> modType_UVTransform_1; // idb
PStringBase<char> TrueFlags_1; // idb
PStringBase<char> FalseFlags_1; // idb
PStringBase<char> RenderPass_1; // idb
PStringBase<char> Blend_1; // idb
PStringBase<char> DepthTest_1; // idb
PStringBase<char> DepthWrite_1; // idb
PStringBase<char> CullMode_1; // idb
PStringBase<char> DepthFog_1; // idb
PStringBase<char> AlphaTestMode_1; // idb
PStringBase<char> AlphaTestRef_1; // idb
PStringBase<char> FFUseLighting_1; // idb
PStringBase<char> FFUseDyeColorInTFactor_1; // idb
PStringBase<char> FFUseSpecularLighting_1; // idb
PStringBase<char> FFUseDistanceFog_1; // idb
PStringBase<char> FFUseVertexDiffuse_1; // idb
PStringBase<char> FFUseVertexSpecular_1; // idb
PStringBase<char> ShaderSupportsDynamicLights_1; // idb
PStringBase<char> UsesTransparency_1; // idb
PStringBase<char> Ambient_1; // idb
PStringBase<char> Diffuse_4; // idb
PStringBase<char> Specular_4; // idb
PStringBase<char> SpecularPower_1; // idb
PStringBase<char> Dye_1; // idb
PStringBase<char> Emissive_1; // idb
PStringBase<char> VertexFormat_1; // idb
PStringBase<char> VertexShader_1; // idb
PStringBase<char> PixelShader_1; // idb
PStringBase<char> param_MLF_NONE_1; // idb
PStringBase<char> param_MLF_REFLECTIONS_1; // idb
PStringBase<char> param_MLF_VIDEOPOST_1; // idb
PStringBase<char> param_MLF_HIGHDETAIL_1; // idb
PStringBase<char> param_MLF_SPECULAR_1; // idb
PStringBase<char> param_MLF_CLASS1_1; // idb
PStringBase<char> param_MLF_CLASS2_1; // idb
PStringBase<char> param_MLF_CLASS3_1; // idb
PStringBase<char> param_RenderPass_Default_1; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_1; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_1; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_1; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_1; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_1; // idb
PStringBase<char> param_RenderPass_DistanceFog_1; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_1; // idb
PStringBase<char> param_RenderPass_ShaderGlow_1; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_1; // idb
PStringBase<char> param_RenderPass_AlphaBlend_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_1; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_1; // idb
PStringBase<char> param_BLEND_ZERO_1; // idb
PStringBase<char> param_BLEND_ONE_1; // idb
PStringBase<char> param_BLEND_SRCCOLOR_1; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_1; // idb
PStringBase<char> param_BLEND_SRCALPHA_1; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_1; // idb
PStringBase<char> param_BLEND_DSTALPHA_1; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_1; // idb
PStringBase<char> param_BLEND_DSTCOLOR_1; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_1; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_1; // idb
PStringBase<char> param_DEPTHTEST_LESS_1; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_1; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_1; // idb
PStringBase<char> param_DEPTHTEST_GREATER_1; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_1; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_1; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_1; // idb
PStringBase<char> param_DEPTHWRITE_ON_1; // idb
PStringBase<char> param_DEPTHWRITE_OFF_1; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_1; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_1; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_1; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_1; // idb
PStringBase<char> param_CULLMODE_NONE_1; // idb
PStringBase<char> param_CULLMODE_CW_1; // idb
PStringBase<char> param_CULLMODE_CCW_1; // idb
PStringBase<char> param_LIGHTMODE_NONE_1; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_1; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_1; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_1; // idb
PStringBase<char> param_DEPTHFOG_OFF_1; // idb
PStringBase<char> param_DEPTHFOG_ON_1; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_1; // idb
PStringBase<char> param_ALPHATESTMODE_ON_1; // idb
PStringBase<char> param_VF_ORIGIN_1; // idb
PStringBase<char> param_VF_NORMAL_1; // idb
PStringBase<char> param_VF_POINTSIZE_1; // idb
PStringBase<char> param_VF_DIFFUSE_1; // idb
PStringBase<char> param_VF_SPECULAR_1; // idb
PStringBase<char> param_VF_TCPAIRx1_1; // idb
PStringBase<char> param_VF_TCPAIRx2_1; // idb
PStringBase<char> param_VF_TCPAIRx3_1; // idb
PStringBase<char> param_VF_TCPAIRx4_1; // idb
PStringBase<char> param_VF_TCPAIRx5_1; // idb
PStringBase<char> param_VF_TCPAIRx6_1; // idb
PStringBase<char> param_VF_TCPAIRx7_1; // idb
PStringBase<char> param_VF_TCPAIRx8_1; // idb
PStringBase<char> param_VF_VECTOR_S_1; // idb
PStringBase<char> param_VF_VECTOR_T_1; // idb
PStringBase<char> NodeName_24; // idb
PStringBase<char> SamplerNodeName_1; // idb
PStringBase<char> SamplerName_1; // idb
PStringBase<char> Texture_1; // idb
PStringBase<char> SpecialTexture_FrameBuffer_1; // idb
PStringBase<char> SpecialTexture_Distortion_1; // idb
PStringBase<char> SpecialTexture_Reflection_1; // idb
PStringBase<char> SpecialTexture_NormalizeCube_1; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_1; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_1; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_1; // idb
PStringBase<char> AddressMode_1; // idb
PStringBase<char> TexFilter_1; // idb
PStringBase<char> ColorOp_1; // idb
PStringBase<char> ColorArg1_1; // idb
PStringBase<char> ColorArg2_1; // idb
PStringBase<char> AlphaOp_1; // idb
PStringBase<char> AlphaArg1_1; // idb
PStringBase<char> AlphaArg2_1; // idb
PStringBase<char> TexCoord_1; // idb
PStringBase<char> UseProjection_1; // idb
PStringBase<char> param_TEXOP_SELECTARG1_1; // idb
PStringBase<char> param_TEXOP_SELECTARG2_1; // idb
PStringBase<char> param_TEXOP_MODULATE_1; // idb
PStringBase<char> param_TEXOP_MODULATE2X_1; // idb
PStringBase<char> param_TEXOP_MODULATE4X_1; // idb
PStringBase<char> param_TEXOP_ADD_1; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_1; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_1; // idb
PStringBase<char> param_TEXOP_SUBTRACT_1; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_1; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_1; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_1; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_1; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_1; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_1; // idb
PStringBase<char> param_TEXOP_PREMODULATE_1; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_1; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_1; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_1; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_1; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_1; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_1; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_1; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_1; // idb
PStringBase<char> param_TEXOP_LERP_1; // idb
PStringBase<char> param_TEXARG_DIFFUSE_1; // idb
PStringBase<char> param_TEXARG_SPECULAR_1; // idb
PStringBase<char> param_TEXARG_CURRENT_1; // idb
PStringBase<char> param_TEXARG_TEXTURE_1; // idb
PStringBase<char> param_TEXARG_TFACTOR_1; // idb
PStringBase<char> param_TEXADDRESS_WRAP_1; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_1; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_1; // idb
PStringBase<char> param_TEXADDRESS_BORDER_1; // idb
PStringBase<char> param_TEXFILTER_NONE_1; // idb
PStringBase<char> param_TEXFILTER_POINT_1; // idb
PStringBase<char> param_TEXFILTER_LINEAR_1; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_1; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_1; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_1; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_1; // idb
PStringBase<char> param_TEXCOORD_SphereMap_1; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_1; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_1; // idb
PStringBase<char> NodeName_25; // idb
PStringBase<char> ModType_Origin_1; // idb
PStringBase<char> ModType_Normal_1; // idb
PStringBase<char> ModType_Diffuse_1; // idb
PStringBase<char> ModType_UVTranslate_1; // idb
PStringBase<char> ModType_UVRotate_1; // idb
PStringBase<char> ModType_UVScale_1; // idb
PStringBase<char> ModType_UVTransform_1; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_1; // idb
PStringBase<char> Mod_UVTranslate_translate_1; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_1; // idb
PStringBase<char> Mod_UVRotate_rotate_1; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_1; // idb
PStringBase<char> Mod_UVScale_scale_1; // idb
PStringBase<char> NodeName_26; // idb
PStringBase<char> PhysicsTimeStep_1; // idb
PStringBase<char> FastForwardTime_1; // idb
PStringBase<char> StartFadeDistance_1; // idb
PStringBase<char> StopFadeDistance_1; // idb
PStringBase<char> PhysicsDuration_1; // idb
PStringBase<char> ScaleType_1; // idb
PStringBase<char> WorldSpace_1; // idb
PStringBase<char> ForceDraw_1; // idb
PStringBase<char> NumEmitters_1; // idb
PStringBase<char> Material_11; // idb
PStringBase<char> Version_1; // idb
PStringBase<char> MaxParticles_1; // idb
PStringBase<char> NodeName_27; // idb
PStringBase<char> Origin_4; // idb
PStringBase<char> Shape_1; // idb
PStringBase<char> Shape_Point_1; // idb
PStringBase<char> Shape_Line_1; // idb
PStringBase<char> Shape_Quad_1; // idb
PStringBase<char> Shape_Disc_1; // idb
PStringBase<char> Shape_Sphere_1; // idb
PStringBase<char> ParticleShape_1; // idb
PStringBase<char> ParticleShape_Triangle_1; // idb
PStringBase<char> ParticleShape_Quad_1; // idb
PStringBase<char> Streak_1; // idb
PStringBase<char> Rotation_4; // idb
PStringBase<char> WorldRotation_1; // idb
PStringBase<char> RotateVelocity_1; // idb
PStringBase<char> ParticleScale_1; // idb
PStringBase<char> Scale_6; // idb
PStringBase<char> ExplodingDir_1; // idb
PStringBase<char> BirthRate_1; // idb
PStringBase<char> Lifespan_1; // idb
PStringBase<char> Velocity_1; // idb
PStringBase<char> Direction_1; // idb
PStringBase<char> MinSpread_1; // idb
PStringBase<char> MaxSpread_1; // idb
PStringBase<char> EmissionLimit_1; // idb
PStringBase<char> BlastCount_1; // idb
PStringBase<char> StartTime_1; // idb
PStringBase<char> TimeLimit_1; // idb
PStringBase<char> EmissionDistance_1; // idb
PStringBase<char> ParticleSnap_1; // idb
PStringBase<char> InclusiveShape_1; // idb
PStringBase<char> NumKeyframes_1; // idb
PStringBase<char> IsActive_1; // idb
PStringBase<char> FadeIn_1; // idb
PStringBase<char> FadeOut_1; // idb
PStringBase<char> ConstrainX_1; // idb
PStringBase<char> ConstrainY_1; // idb
PStringBase<char> ConstrainZ_1; // idb
PStringBase<char> NodeName_28; // idb
PStringBase<char> Time_1; // idb
PStringBase<char> Flags_1; // idb
PStringBase<char> Flags_None_1; // idb
PStringBase<char> Flags_BlendScale_1; // idb
PStringBase<char> Flags_BlendColor_1; // idb
PStringBase<char> Flags_BlendMass_1; // idb
PStringBase<char> Flags_SetScale_1; // idb
PStringBase<char> Flags_SetColor_1; // idb
PStringBase<char> Flags_SetMass_1; // idb
PStringBase<char> Flags_SetPFlags_1; // idb
PStringBase<char> Flags_SetPCType_1; // idb
PStringBase<char> Flags_SetPhysFlags_1; // idb
PStringBase<char> Flags_SetParams_1; // idb
PStringBase<char> Scale_7; // idb
PStringBase<char> ScaleX_1; // idb
PStringBase<char> ScaleY_1; // idb
PStringBase<char> Color_1; // idb
PStringBase<char> Mass_1; // idb
PStringBase<char> PFlags_1; // idb
PStringBase<char> PFlags_None_1; // idb
PStringBase<char> PCType_1; // idb
PStringBase<char> PCType_None_1; // idb
PStringBase<char> PCType_Physics_1; // idb
PStringBase<char> PCType_Parametric_1; // idb
PStringBase<char> PCType_AttractRepulse_1; // idb
PStringBase<char> PCType_PointFile_1; // idb
PStringBase<char> PCType_PointFileLerp_1; // idb
PStringBase<char> PhysFlags_1; // idb
PStringBase<char> PhysFlags_None_1; // idb
PStringBase<char> PhysFlags_Gravity_1; // idb
PStringBase<char> PhysFlags_Wind_1; // idb
PStringBase<char> PhysFlags_Momentum_1; // idb
PStringBase<char> PointfileFlags_RandomPoint_1; // idb
PStringBase<char> Position_2; // idb
PStringBase<char> PointList_1; // idb
PStringBase<char> Point_4; // idb
PStringBase<char> DetailLevels_1; // idb
PStringBase<char> DetailLevel_Low_1; // idb
PStringBase<char> DetailLevel_Medium_1; // idb
PStringBase<char> DetailLevel_High_1; // idb
PStringBase<char> FadeSpeed_1; // idb
PStringBase<char> MaxOpacity_1; // idb
PStringBase<char> Point_5; // idb
PStringBase<char> PointAxisPos_1; // idb
PStringBase<char> PointTexture_1; // idb
PStringBase<char> PointSize_1; // idb
PStringBase<char> UseOcclusion_1; // idb
IDClass<_tagDataID,32,0> INVALID_DID_38; // idb
PStringBase<char> PHEADER_STRINGS_1[4]; // idb
PStringBase<char> stru_8399E0; // idb
PStringBase<char> stru_8399E4; // idb
PStringBase<char> stru_8399E8; // idb
_UNKNOWN unk_8399EC; // weak
PixelFormatDesc PixelFormatDesc_A8R8G8B8_18; // idb
PStringBase<char> waveform_None_16; // idb
PStringBase<char> waveform_Speed_16; // idb
PStringBase<char> waveform_Noise_16; // idb
PStringBase<char> waveform_Sine_16; // idb
PStringBase<char> waveform_Square_16; // idb
PStringBase<char> waveform_Bounce_16; // idb
PStringBase<char> waveform_Perlin_16; // idb
PStringBase<char> waveform_Fractal_16; // idb
PStringBase<char> waveform_FrameLoop_16; // idb
const float dword_839A64; // idb
const float outside_val_14; // idb
const float block_length_14; // idb
const float half_square_length_14; // idb
PStringBase<char> Render_TextureFiltering_9; // idb
PStringBase<char> Render_LandscapeDetailTextures_9; // idb
PStringBase<char> Render_BuildingDetailTextures_9; // idb
PStringBase<char> Render_FieldOfView_9; // idb
PStringBase<char> Render_LandscapeTextureDetail_9; // idb
PStringBase<char> Render_EnvironmentTextureDetail_9; // idb
PStringBase<char> Render_SceneryDrawDistance_9; // idb
PStringBase<char> Render_LandscapeDrawDistance_9; // idb
PStringBase<char> Render_ScreenBrightness_9; // idb
PStringBase<char> Render_AspectRatio_9; // idb
PStringBase<char> Render_DisplayAdapter_9; // idb
PStringBase<char> Render_MaxHardwareClass_9; // idb
PStringBase<char> Render_AutomaticDegrades_9; // idb
PStringBase<char> Render_GraphicsPerformance_9; // idb
PStringBase<char> Render_DegradeDistance_9; // idb
PStringBase<char> Render_MultiPassAlpha_9; // idb
PStringBase<char> Render_TextureFiltering_Choices_9[4]; // idb
PStringBase<char> stru_839ABC; // idb
PStringBase<char> stru_839AC0; // idb
PStringBase<char> stru_839AC4; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_9[5]; // idb
PStringBase<char> stru_839ACC; // idb
PStringBase<char> stru_839AD0; // idb
PStringBase<char> stru_839AD4; // idb
PStringBase<char> stru_839AD8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_9[5]; // idb
PStringBase<char> stru_839AE0; // idb
PStringBase<char> stru_839AE4; // idb
PStringBase<char> stru_839AE8; // idb
PStringBase<char> stru_839AEC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_9[3]; // idb
PStringBase<char> stru_839AF4; // idb
PStringBase<char> stru_839AF8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_9[6]; // idb
PStringBase<char> stru_839B00; // idb
PStringBase<char> stru_839B04; // idb
PStringBase<char> stru_839B08; // idb
PStringBase<char> stru_839B0C; // idb
PStringBase<char> stru_839B10; // idb
PStringBase<char> Render_AspectRatio_Choices_9[3]; // idb
PStringBase<char> stru_839B18; // idb
PStringBase<char> stru_839B1C; // idb
PStringBase<char> PHeader_2; // idb
PStringBase<char> VertexArray_2; // idb
PStringBase<char> BinaryVertexArray_2; // idb
PStringBase<char> VertexType_3; // idb
PStringBase<char> VertexData_2; // idb
PStringBase<char> Vertex_2; // idb
PStringBase<char> Index_5; // idb
PStringBase<char> Origin_5; // idb
PStringBase<char> Normal_2; // idb
PStringBase<char> Diffuse_5; // idb
PStringBase<char> Specular_5; // idb
PStringBase<char> UVS_2; // idb
PStringBase<char> VectorS_2; // idb
PStringBase<char> VectorT_2; // idb
PStringBase<char> VectorSxT_2; // idb
PStringBase<char> Weights_2; // idb
PStringBase<char> Importance_2; // idb
PStringBase<char> PhysMtl_2; // idb
PStringBase<char> Material_12; // idb
PStringBase<char> ID_6; // idb
PStringBase<char> FileName_2; // idb
PStringBase<char> Polygon_5; // idb
PStringBase<char> ID_7; // idb
PStringBase<char> Indices_4; // idb
PStringBase<char> MaterialID_2; // idb
PStringBase<char> PhysMaterialID_2; // idb
PStringBase<char> Markings_2; // idb
PStringBase<char> Material_13; // idb
PStringBase<char> Index_6; // idb
PStringBase<char> Filename_2; // idb
PStringBase<char> Surface_2; // idb
PStringBase<char> CellPoly_2; // idb
PStringBase<char> Sphere_3; // idb
PStringBase<char> Side_2; // idb
PStringBase<char> Positive_2; // idb
PStringBase<char> Negative_2; // idb
PStringBase<char> Polygon_6; // idb
PStringBase<char> OtherCell_5; // idb
PStringBase<char> CellPortal_2; // idb
PStringBase<char> Portal_3; // idb
PStringBase<char> OtherCell_6; // idb
PStringBase<char> OtherPortal_2; // idb
PStringBase<char> ExactMatch_2; // idb
PStringBase<char> StabList_2; // idb
PStringBase<char> Period_2; // idb
PStringBase<char> GrannyAnimation_2; // idb
PStringBase<char> Transform_2; // idb
PStringBase<char> Scale_8; // idb
PStringBase<char> Weight_2; // idb
PStringBase<char> Offset_2; // idb
PStringBase<char> Quaternion_3; // idb
PStringBase<char> Rotation_5; // idb
PStringBase<char> STime_2; // idb
PStringBase<char> PhysicsSplines_2; // idb
PStringBase<char> BoneOpacities_2; // idb
PStringBase<char> LowPt_2; // idb
PStringBase<char> Radius_2; // idb
PStringBase<char> Height_2; // idb
PStringBase<char> Texture2D_2; // idb
PStringBase<char> Texture3D_2; // idb
PStringBase<char> TextureCube_2; // idb
PStringBase<char> TextureMovie2D_2; // idb
PStringBase<char> MovieFileName_2; // idb
PStringBase<char> MovieFramesPerSecond_2; // idb
PStringBase<char> Levels_2; // idb
PStringBase<char> NodeName_29; // idb
PStringBase<char> Material_14; // idb
PStringBase<char> MaterialType_2; // idb
PStringBase<char> Modifier_2; // idb
PStringBase<char> AllowStencilShadows_2; // idb
PStringBase<char> DiscardGeometry_2; // idb
PStringBase<char> NodeName_30; // idb
PStringBase<char> SortMode_2; // idb
PStringBase<char> SortMode_None_2; // idb
PStringBase<char> SortMode_Triangle_2; // idb
PStringBase<char> NodeName_31; // idb
PStringBase<char> NodeName_32; // idb
PStringBase<char> DataType_DATA_2; // idb
PStringBase<char> DataType_WAVEFORM_2; // idb
PStringBase<char> DataType_COLOR_2; // idb
PStringBase<char> DataType_TEXTURE_2; // idb
PStringBase<char> DataType_BOOL_2; // idb
PStringBase<char> NodeName_33; // idb
PStringBase<char> modType_UVTranslate_2; // idb
PStringBase<char> modType_UVRotate_2; // idb
PStringBase<char> modType_UVScale_2; // idb
PStringBase<char> modType_UVTransform_2; // idb
PStringBase<char> TrueFlags_2; // idb
PStringBase<char> FalseFlags_2; // idb
PStringBase<char> RenderPass_2; // idb
PStringBase<char> Blend_2; // idb
PStringBase<char> DepthTest_2; // idb
PStringBase<char> DepthWrite_2; // idb
PStringBase<char> CullMode_2; // idb
PStringBase<char> DepthFog_2; // idb
PStringBase<char> AlphaTestMode_2; // idb
PStringBase<char> AlphaTestRef_2; // idb
PStringBase<char> FFUseLighting_2; // idb
PStringBase<char> FFUseDyeColorInTFactor_2; // idb
PStringBase<char> FFUseSpecularLighting_2; // idb
PStringBase<char> FFUseDistanceFog_2; // idb
PStringBase<char> FFUseVertexDiffuse_2; // idb
PStringBase<char> FFUseVertexSpecular_2; // idb
PStringBase<char> ShaderSupportsDynamicLights_2; // idb
PStringBase<char> UsesTransparency_2; // idb
PStringBase<char> Ambient_2; // idb
PStringBase<char> Diffuse_6; // idb
PStringBase<char> Specular_6; // idb
PStringBase<char> SpecularPower_2; // idb
PStringBase<char> Dye_2; // idb
PStringBase<char> Emissive_2; // idb
PStringBase<char> VertexFormat_2; // idb
PStringBase<char> VertexShader_2; // idb
PStringBase<char> PixelShader_2; // idb
PStringBase<char> param_MLF_NONE_2; // idb
PStringBase<char> param_MLF_REFLECTIONS_2; // idb
PStringBase<char> param_MLF_VIDEOPOST_2; // idb
PStringBase<char> param_MLF_HIGHDETAIL_2; // idb
PStringBase<char> param_MLF_SPECULAR_2; // idb
PStringBase<char> param_MLF_CLASS1_2; // idb
PStringBase<char> param_MLF_CLASS2_2; // idb
PStringBase<char> param_MLF_CLASS3_2; // idb
PStringBase<char> param_RenderPass_Default_2; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_2; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_2; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_2; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_2; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_2; // idb
PStringBase<char> param_RenderPass_DistanceFog_2; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_2; // idb
PStringBase<char> param_RenderPass_ShaderGlow_2; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_2; // idb
PStringBase<char> param_RenderPass_AlphaBlend_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_2; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_2; // idb
PStringBase<char> param_BLEND_ZERO_2; // idb
PStringBase<char> param_BLEND_ONE_2; // idb
PStringBase<char> param_BLEND_SRCCOLOR_2; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_2; // idb
PStringBase<char> param_BLEND_SRCALPHA_2; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_2; // idb
PStringBase<char> param_BLEND_DSTALPHA_2; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_2; // idb
PStringBase<char> param_BLEND_DSTCOLOR_2; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_2; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_2; // idb
PStringBase<char> param_DEPTHTEST_LESS_2; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_2; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_2; // idb
PStringBase<char> param_DEPTHTEST_GREATER_2; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_2; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_2; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_2; // idb
PStringBase<char> param_DEPTHWRITE_ON_2; // idb
PStringBase<char> param_DEPTHWRITE_OFF_2; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_2; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_2; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_2; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_2; // idb
PStringBase<char> param_CULLMODE_NONE_2; // idb
PStringBase<char> param_CULLMODE_CW_2; // idb
PStringBase<char> param_CULLMODE_CCW_2; // idb
PStringBase<char> param_LIGHTMODE_NONE_2; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_2; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_2; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_2; // idb
PStringBase<char> param_DEPTHFOG_OFF_2; // idb
PStringBase<char> param_DEPTHFOG_ON_2; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_2; // idb
PStringBase<char> param_ALPHATESTMODE_ON_2; // idb
PStringBase<char> param_VF_ORIGIN_2; // idb
PStringBase<char> param_VF_NORMAL_2; // idb
PStringBase<char> param_VF_POINTSIZE_2; // idb
PStringBase<char> param_VF_DIFFUSE_2; // idb
PStringBase<char> param_VF_SPECULAR_2; // idb
PStringBase<char> param_VF_TCPAIRx1_2; // idb
PStringBase<char> param_VF_TCPAIRx2_2; // idb
PStringBase<char> param_VF_TCPAIRx3_2; // idb
PStringBase<char> param_VF_TCPAIRx4_2; // idb
PStringBase<char> param_VF_TCPAIRx5_2; // idb
PStringBase<char> param_VF_TCPAIRx6_2; // idb
PStringBase<char> param_VF_TCPAIRx7_2; // idb
PStringBase<char> param_VF_TCPAIRx8_2; // idb
PStringBase<char> param_VF_VECTOR_S_2; // idb
PStringBase<char> param_VF_VECTOR_T_2; // idb
PStringBase<char> NodeName_34; // idb
PStringBase<char> SamplerNodeName_2; // idb
PStringBase<char> SamplerName_2; // idb
PStringBase<char> Texture_2; // idb
PStringBase<char> SpecialTexture_FrameBuffer_2; // idb
PStringBase<char> SpecialTexture_Distortion_2; // idb
PStringBase<char> SpecialTexture_Reflection_2; // idb
PStringBase<char> SpecialTexture_NormalizeCube_2; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_2; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_2; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_2; // idb
PStringBase<char> AddressMode_2; // idb
PStringBase<char> TexFilter_2; // idb
PStringBase<char> ColorOp_2; // idb
PStringBase<char> ColorArg1_2; // idb
PStringBase<char> ColorArg2_2; // idb
PStringBase<char> AlphaOp_2; // idb
PStringBase<char> AlphaArg1_2; // idb
PStringBase<char> AlphaArg2_2; // idb
PStringBase<char> TexCoord_2; // idb
PStringBase<char> UseProjection_2; // idb
PStringBase<char> param_TEXOP_SELECTARG1_2; // idb
PStringBase<char> param_TEXOP_SELECTARG2_2; // idb
PStringBase<char> param_TEXOP_MODULATE_2; // idb
PStringBase<char> param_TEXOP_MODULATE2X_2; // idb
PStringBase<char> param_TEXOP_MODULATE4X_2; // idb
PStringBase<char> param_TEXOP_ADD_2; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_2; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_2; // idb
PStringBase<char> param_TEXOP_SUBTRACT_2; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_2; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_2; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_2; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_2; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_2; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_2; // idb
PStringBase<char> param_TEXOP_PREMODULATE_2; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_2; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_2; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_2; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_2; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_2; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_2; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_2; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_2; // idb
PStringBase<char> param_TEXOP_LERP_2; // idb
PStringBase<char> param_TEXARG_DIFFUSE_2; // idb
PStringBase<char> param_TEXARG_SPECULAR_2; // idb
PStringBase<char> param_TEXARG_CURRENT_2; // idb
PStringBase<char> param_TEXARG_TEXTURE_2; // idb
PStringBase<char> param_TEXARG_TFACTOR_2; // idb
PStringBase<char> param_TEXADDRESS_WRAP_2; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_2; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_2; // idb
PStringBase<char> param_TEXADDRESS_BORDER_2; // idb
PStringBase<char> param_TEXFILTER_NONE_2; // idb
PStringBase<char> param_TEXFILTER_POINT_2; // idb
PStringBase<char> param_TEXFILTER_LINEAR_2; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_2; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_2; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_2; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_2; // idb
PStringBase<char> param_TEXCOORD_SphereMap_2; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_2; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_2; // idb
PStringBase<char> NodeName_35; // idb
PStringBase<char> ModType_Origin_2; // idb
PStringBase<char> ModType_Normal_2; // idb
PStringBase<char> ModType_Diffuse_2; // idb
PStringBase<char> ModType_UVTranslate_2; // idb
PStringBase<char> ModType_UVRotate_2; // idb
PStringBase<char> ModType_UVScale_2; // idb
PStringBase<char> ModType_UVTransform_2; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_2; // idb
PStringBase<char> Mod_UVTranslate_translate_2; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_2; // idb
PStringBase<char> Mod_UVRotate_rotate_2; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_2; // idb
PStringBase<char> Mod_UVScale_scale_2; // idb
PStringBase<char> NodeName_36; // idb
PStringBase<char> PhysicsTimeStep_2; // idb
PStringBase<char> FastForwardTime_2; // idb
PStringBase<char> StartFadeDistance_2; // idb
PStringBase<char> StopFadeDistance_2; // idb
PStringBase<char> PhysicsDuration_2; // idb
PStringBase<char> ScaleType_2; // idb
PStringBase<char> WorldSpace_2; // idb
PStringBase<char> ForceDraw_2; // idb
PStringBase<char> NumEmitters_2; // idb
PStringBase<char> Material_15; // idb
PStringBase<char> Version_2; // idb
PStringBase<char> MaxParticles_2; // idb
PStringBase<char> NodeName_37; // idb
PStringBase<char> Origin_6; // idb
PStringBase<char> Shape_2; // idb
PStringBase<char> Shape_Point_2; // idb
PStringBase<char> Shape_Line_2; // idb
PStringBase<char> Shape_Quad_2; // idb
PStringBase<char> Shape_Disc_2; // idb
PStringBase<char> Shape_Sphere_2; // idb
PStringBase<char> ParticleShape_2; // idb
PStringBase<char> ParticleShape_Triangle_2; // idb
PStringBase<char> ParticleShape_Quad_2; // idb
PStringBase<char> Streak_2; // idb
PStringBase<char> Rotation_6; // idb
PStringBase<char> WorldRotation_2; // idb
PStringBase<char> RotateVelocity_2; // idb
PStringBase<char> ParticleScale_2; // idb
PStringBase<char> Scale_9; // idb
PStringBase<char> ExplodingDir_2; // idb
PStringBase<char> BirthRate_2; // idb
PStringBase<char> Lifespan_2; // idb
PStringBase<char> Velocity_2; // idb
PStringBase<char> Direction_2; // idb
PStringBase<char> MinSpread_2; // idb
PStringBase<char> MaxSpread_2; // idb
PStringBase<char> EmissionLimit_2; // idb
PStringBase<char> BlastCount_2; // idb
PStringBase<char> StartTime_2; // idb
PStringBase<char> TimeLimit_2; // idb
PStringBase<char> EmissionDistance_2; // idb
PStringBase<char> ParticleSnap_2; // idb
PStringBase<char> InclusiveShape_2; // idb
PStringBase<char> NumKeyframes_2; // idb
PStringBase<char> IsActive_2; // idb
PStringBase<char> FadeIn_2; // idb
PStringBase<char> FadeOut_2; // idb
PStringBase<char> ConstrainX_2; // idb
PStringBase<char> ConstrainY_2; // idb
PStringBase<char> ConstrainZ_2; // idb
PStringBase<char> NodeName_38; // idb
PStringBase<char> Time_2; // idb
PStringBase<char> Flags_2; // idb
PStringBase<char> Flags_None_2; // idb
PStringBase<char> Flags_BlendScale_2; // idb
PStringBase<char> Flags_BlendColor_2; // idb
PStringBase<char> Flags_BlendMass_2; // idb
PStringBase<char> Flags_SetScale_2; // idb
PStringBase<char> Flags_SetColor_2; // idb
PStringBase<char> Flags_SetMass_2; // idb
PStringBase<char> Flags_SetPFlags_2; // idb
PStringBase<char> Flags_SetPCType_2; // idb
PStringBase<char> Flags_SetPhysFlags_2; // idb
PStringBase<char> Flags_SetParams_2; // idb
PStringBase<char> Scale_10; // idb
PStringBase<char> ScaleX_2; // idb
PStringBase<char> ScaleY_2; // idb
PStringBase<char> Color_2; // idb
PStringBase<char> Mass_2; // idb
PStringBase<char> PFlags_2; // idb
PStringBase<char> PFlags_None_2; // idb
PStringBase<char> PCType_2; // idb
PStringBase<char> PCType_None_2; // idb
PStringBase<char> PCType_Physics_2; // idb
PStringBase<char> PCType_Parametric_2; // idb
PStringBase<char> PCType_AttractRepulse_2; // idb
PStringBase<char> PCType_PointFile_2; // idb
PStringBase<char> PCType_PointFileLerp_2; // idb
PStringBase<char> PhysFlags_2; // idb
PStringBase<char> PhysFlags_None_2; // idb
PStringBase<char> PhysFlags_Gravity_2; // idb
PStringBase<char> PhysFlags_Wind_2; // idb
PStringBase<char> PhysFlags_Momentum_2; // idb
PStringBase<char> PointfileFlags_RandomPoint_2; // idb
PStringBase<char> Position_3; // idb
PStringBase<char> PointList_2; // idb
PStringBase<char> Point_6; // idb
PStringBase<char> DetailLevels_2; // idb
PStringBase<char> DetailLevel_Low_2; // idb
PStringBase<char> DetailLevel_Medium_2; // idb
PStringBase<char> DetailLevel_High_2; // idb
PStringBase<char> FadeSpeed_2; // idb
PStringBase<char> MaxOpacity_2; // idb
PStringBase<char> Point_7; // idb
PStringBase<char> PointAxisPos_2; // idb
PStringBase<char> PointTexture_2; // idb
PStringBase<char> PointSize_2; // idb
PStringBase<char> UseOcclusion_2; // idb
PStringBase<char> PHEADER_STRINGS_2[4]; // idb
PStringBase<char> stru_83A150; // idb
PStringBase<char> stru_83A154; // idb
PStringBase<char> stru_83A158; // idb
PStringBase<unsigned short> PROJECTSETTING_2; // idb
PStringBase<char> NAME_2; // idb
PStringBase<char> VALUE_2; // idb
PStringBase<char> BRANCH_2; // idb
PStringBase<char> BRANCHBASEDIR_2; // idb
PStringBase<char> PROJECTNAME_2; // idb
PStringBase<char> LONGNAME_2; // idb
PStringBase<char> ENUMDB_2; // idb
PStringBase<char> DIDNAME_2; // idb
PStringBase<char> RCS_2; // idb
PStringBase<char> PREPROC_KEYS_BASE_PATH_2; // idb
PStringBase<char> CURRENT_PROJECT_2; // idb
PStringBase<char> DATA_GAME_PATH_2; // idb
PStringBase<char> DATA_ENGINE_PATH_2; // idb
PStringBase<char> SOURCE_GAME_PATH_2; // idb
PStringBase<char> SOURCE_ENGINE_PATH_2; // idb
PStringBase<char> TOOLS_BIN_PATH_2; // idb
PStringBase<char> CONFIG_TOOLS_PATH_2; // idb
PStringBase<char> OUTPUT_INI_PATH_2; // idb
PStringBase<char> DATA_PATH_2; // idb
PStringBase<char> DOC_PATH_2; // idb
PStringBase<char> EXPORT_PATH_2; // idb
PStringBase<char> SDK_PATH_2; // idb
PStringBase<char> SOURCE_PATH_2; // idb
PStringBase<char> TOOLS_PATH_2; // idb
PStringBase<char> PORTAL_PATH_2; // idb
PStringBase<char> AC_PATH_2; // idb
IDClass<_tagDataID,32,0> INVALID_DID_40; // idb
SmartArray<QualifiedDataID,1> FontMapper::fonts; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_19; // idb
IDClass<_tagDataID,32,0> INVALID_DID_41; // idb
PStringBase<char> PHeader_3; // idb
PStringBase<char> VertexArray_3; // idb
PStringBase<char> BinaryVertexArray_3; // idb
PStringBase<char> VertexType_4; // idb
PStringBase<char> VertexData_3; // idb
PStringBase<char> Vertex_3; // idb
PStringBase<char> Index_7; // idb
PStringBase<char> Origin_7; // idb
PStringBase<char> Normal_3; // idb
PStringBase<char> Diffuse_7; // idb
PStringBase<char> Specular_7; // idb
PStringBase<char> UVS_3; // idb
PStringBase<char> VectorS_3; // idb
PStringBase<char> VectorT_3; // idb
PStringBase<char> VectorSxT_3; // idb
PStringBase<char> Weights_3; // idb
PStringBase<char> Importance_3; // idb
PStringBase<char> PhysMtl_3; // idb
PStringBase<char> Material_16; // idb
PStringBase<char> ID_8; // idb
PStringBase<char> FileName_3; // idb
PStringBase<char> Polygon_7; // idb
PStringBase<char> ID_9; // idb
PStringBase<char> Indices_5; // idb
PStringBase<char> MaterialID_3; // idb
PStringBase<char> PhysMaterialID_3; // idb
PStringBase<char> Markings_3; // idb
PStringBase<char> Material_17; // idb
PStringBase<char> Index_8; // idb
PStringBase<char> Filename_3; // idb
PStringBase<char> Surface_3; // idb
PStringBase<char> CellPoly_3; // idb
PStringBase<char> Sphere_4; // idb
PStringBase<char> Side_3; // idb
PStringBase<char> Positive_3; // idb
PStringBase<char> Negative_3; // idb
PStringBase<char> Polygon_8; // idb
PStringBase<char> OtherCell_7; // idb
PStringBase<char> CellPortal_3; // idb
PStringBase<char> Portal_4; // idb
PStringBase<char> OtherCell_8; // idb
PStringBase<char> OtherPortal_3; // idb
PStringBase<char> ExactMatch_3; // idb
PStringBase<char> StabList_3; // idb
PStringBase<char> Period_3; // idb
PStringBase<char> GrannyAnimation_3; // idb
PStringBase<char> Transform_3; // idb
PStringBase<char> Scale_11; // idb
PStringBase<char> Weight_3; // idb
PStringBase<char> Offset_3; // idb
PStringBase<char> Quaternion_4; // idb
PStringBase<char> Rotation_7; // idb
PStringBase<char> STime_3; // idb
PStringBase<char> PhysicsSplines_3; // idb
PStringBase<char> BoneOpacities_3; // idb
PStringBase<char> LowPt_3; // idb
PStringBase<char> Radius_3; // idb
PStringBase<char> Height_3; // idb
PStringBase<char> Texture2D_3; // idb
PStringBase<char> Texture3D_3; // idb
PStringBase<char> TextureCube_3; // idb
PStringBase<char> TextureMovie2D_3; // idb
PStringBase<char> MovieFileName_3; // idb
PStringBase<char> MovieFramesPerSecond_3; // idb
PStringBase<char> Levels_3; // idb
PStringBase<char> NodeName_39; // idb
PStringBase<char> Material_18; // idb
PStringBase<char> MaterialType_3; // idb
PStringBase<char> Modifier_3; // idb
PStringBase<char> AllowStencilShadows_3; // idb
PStringBase<char> DiscardGeometry_3; // idb
PStringBase<char> NodeName_40; // idb
PStringBase<char> SortMode_3; // idb
PStringBase<char> SortMode_None_3; // idb
PStringBase<char> SortMode_Triangle_3; // idb
PStringBase<char> NodeName_41; // idb
PStringBase<char> NodeName_42; // idb
PStringBase<char> DataType_DATA_3; // idb
PStringBase<char> DataType_WAVEFORM_3; // idb
PStringBase<char> DataType_COLOR_3; // idb
PStringBase<char> DataType_TEXTURE_3; // idb
PStringBase<char> DataType_BOOL_3; // idb
PStringBase<char> NodeName_43; // idb
PStringBase<char> modType_UVTranslate_3; // idb
PStringBase<char> modType_UVRotate_3; // idb
PStringBase<char> modType_UVScale_3; // idb
PStringBase<char> modType_UVTransform_3; // idb
PStringBase<char> TrueFlags_3; // idb
PStringBase<char> FalseFlags_3; // idb
PStringBase<char> RenderPass_3; // idb
PStringBase<char> Blend_3; // idb
PStringBase<char> DepthTest_3; // idb
PStringBase<char> DepthWrite_3; // idb
PStringBase<char> CullMode_3; // idb
PStringBase<char> DepthFog_3; // idb
PStringBase<char> AlphaTestMode_3; // idb
PStringBase<char> AlphaTestRef_3; // idb
PStringBase<char> FFUseLighting_3; // idb
PStringBase<char> FFUseDyeColorInTFactor_3; // idb
PStringBase<char> FFUseSpecularLighting_3; // idb
PStringBase<char> FFUseDistanceFog_3; // idb
PStringBase<char> FFUseVertexDiffuse_3; // idb
PStringBase<char> FFUseVertexSpecular_3; // idb
PStringBase<char> ShaderSupportsDynamicLights_3; // idb
PStringBase<char> UsesTransparency_3; // idb
PStringBase<char> Ambient_3; // idb
PStringBase<char> Diffuse_8; // idb
PStringBase<char> Specular_8; // idb
PStringBase<char> SpecularPower_3; // idb
PStringBase<char> Dye_3; // idb
PStringBase<char> Emissive_3; // idb
PStringBase<char> VertexFormat_3; // idb
PStringBase<char> VertexShader_3; // idb
PStringBase<char> PixelShader_3; // idb
PStringBase<char> param_MLF_NONE_3; // idb
PStringBase<char> param_MLF_REFLECTIONS_3; // idb
PStringBase<char> param_MLF_VIDEOPOST_3; // idb
PStringBase<char> param_MLF_HIGHDETAIL_3; // idb
PStringBase<char> param_MLF_SPECULAR_3; // idb
PStringBase<char> param_MLF_CLASS1_3; // idb
PStringBase<char> param_MLF_CLASS2_3; // idb
PStringBase<char> param_MLF_CLASS3_3; // idb
PStringBase<char> param_RenderPass_Default_3; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_3; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_3; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_3; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_3; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_3; // idb
PStringBase<char> param_RenderPass_DistanceFog_3; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_3; // idb
PStringBase<char> param_RenderPass_ShaderGlow_3; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_3; // idb
PStringBase<char> param_RenderPass_AlphaBlend_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_3; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_3; // idb
PStringBase<char> param_BLEND_ZERO_3; // idb
PStringBase<char> param_BLEND_ONE_3; // idb
PStringBase<char> param_BLEND_SRCCOLOR_3; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_3; // idb
PStringBase<char> param_BLEND_SRCALPHA_3; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_3; // idb
PStringBase<char> param_BLEND_DSTALPHA_3; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_3; // idb
PStringBase<char> param_BLEND_DSTCOLOR_3; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_3; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_3; // idb
PStringBase<char> param_DEPTHTEST_LESS_3; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_3; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_3; // idb
PStringBase<char> param_DEPTHTEST_GREATER_3; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_3; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_3; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_3; // idb
PStringBase<char> param_DEPTHWRITE_ON_3; // idb
PStringBase<char> param_DEPTHWRITE_OFF_3; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_3; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_3; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_3; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_3; // idb
PStringBase<char> param_CULLMODE_NONE_3; // idb
PStringBase<char> param_CULLMODE_CW_3; // idb
PStringBase<char> param_CULLMODE_CCW_3; // idb
PStringBase<char> param_LIGHTMODE_NONE_3; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_3; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_3; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_3; // idb
PStringBase<char> param_DEPTHFOG_OFF_3; // idb
PStringBase<char> param_DEPTHFOG_ON_3; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_3; // idb
PStringBase<char> param_ALPHATESTMODE_ON_3; // idb
PStringBase<char> param_VF_ORIGIN_3; // idb
PStringBase<char> param_VF_NORMAL_3; // idb
PStringBase<char> param_VF_POINTSIZE_3; // idb
PStringBase<char> param_VF_DIFFUSE_3; // idb
PStringBase<char> param_VF_SPECULAR_3; // idb
PStringBase<char> param_VF_TCPAIRx1_3; // idb
PStringBase<char> param_VF_TCPAIRx2_3; // idb
PStringBase<char> param_VF_TCPAIRx3_3; // idb
PStringBase<char> param_VF_TCPAIRx4_3; // idb
PStringBase<char> param_VF_TCPAIRx5_3; // idb
PStringBase<char> param_VF_TCPAIRx6_3; // idb
PStringBase<char> param_VF_TCPAIRx7_3; // idb
PStringBase<char> param_VF_TCPAIRx8_3; // idb
PStringBase<char> param_VF_VECTOR_S_3; // idb
PStringBase<char> param_VF_VECTOR_T_3; // idb
PStringBase<char> NodeName_44; // idb
PStringBase<char> SamplerNodeName_3; // idb
PStringBase<char> SamplerName_3; // idb
PStringBase<char> Texture_3; // idb
PStringBase<char> SpecialTexture_FrameBuffer_3; // idb
PStringBase<char> SpecialTexture_Distortion_3; // idb
PStringBase<char> SpecialTexture_Reflection_3; // idb
PStringBase<char> SpecialTexture_NormalizeCube_3; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_3; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_3; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_3; // idb
PStringBase<char> AddressMode_3; // idb
PStringBase<char> TexFilter_3; // idb
PStringBase<char> ColorOp_3; // idb
PStringBase<char> ColorArg1_3; // idb
PStringBase<char> ColorArg2_3; // idb
PStringBase<char> AlphaOp_3; // idb
PStringBase<char> AlphaArg1_3; // idb
PStringBase<char> AlphaArg2_3; // idb
PStringBase<char> TexCoord_3; // idb
PStringBase<char> UseProjection_3; // idb
PStringBase<char> param_TEXOP_SELECTARG1_3; // idb
PStringBase<char> param_TEXOP_SELECTARG2_3; // idb
PStringBase<char> param_TEXOP_MODULATE_3; // idb
PStringBase<char> param_TEXOP_MODULATE2X_3; // idb
PStringBase<char> param_TEXOP_MODULATE4X_3; // idb
PStringBase<char> param_TEXOP_ADD_3; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_3; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_3; // idb
PStringBase<char> param_TEXOP_SUBTRACT_3; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_3; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_3; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_3; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_3; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_3; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_3; // idb
PStringBase<char> param_TEXOP_PREMODULATE_3; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_3; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_3; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_3; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_3; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_3; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_3; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_3; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_3; // idb
PStringBase<char> param_TEXOP_LERP_3; // idb
PStringBase<char> param_TEXARG_DIFFUSE_3; // idb
PStringBase<char> param_TEXARG_SPECULAR_3; // idb
PStringBase<char> param_TEXARG_CURRENT_3; // idb
PStringBase<char> param_TEXARG_TEXTURE_3; // idb
PStringBase<char> param_TEXARG_TFACTOR_3; // idb
PStringBase<char> param_TEXADDRESS_WRAP_3; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_3; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_3; // idb
PStringBase<char> param_TEXADDRESS_BORDER_3; // idb
PStringBase<char> param_TEXFILTER_NONE_3; // idb
PStringBase<char> param_TEXFILTER_POINT_3; // idb
PStringBase<char> param_TEXFILTER_LINEAR_3; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_3; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_3; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_3; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_3; // idb
PStringBase<char> param_TEXCOORD_SphereMap_3; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_3; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_3; // idb
PStringBase<char> NodeName_45; // idb
PStringBase<char> ModType_Origin_3; // idb
PStringBase<char> ModType_Normal_3; // idb
PStringBase<char> ModType_Diffuse_3; // idb
PStringBase<char> ModType_UVTranslate_3; // idb
PStringBase<char> ModType_UVRotate_3; // idb
PStringBase<char> ModType_UVScale_3; // idb
PStringBase<char> ModType_UVTransform_3; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_3; // idb
PStringBase<char> Mod_UVTranslate_translate_3; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_3; // idb
PStringBase<char> Mod_UVRotate_rotate_3; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_3; // idb
PStringBase<char> Mod_UVScale_scale_3; // idb
PStringBase<char> NodeName_46; // idb
PStringBase<char> PhysicsTimeStep_3; // idb
PStringBase<char> FastForwardTime_3; // idb
PStringBase<char> StartFadeDistance_3; // idb
PStringBase<char> StopFadeDistance_3; // idb
PStringBase<char> PhysicsDuration_3; // idb
PStringBase<char> ScaleType_3; // idb
PStringBase<char> WorldSpace_3; // idb
PStringBase<char> ForceDraw_3; // idb
PStringBase<char> NumEmitters_3; // idb
PStringBase<char> Material_19; // idb
PStringBase<char> Version_3; // idb
PStringBase<char> MaxParticles_3; // idb
PStringBase<char> NodeName_47; // idb
PStringBase<char> Origin_8; // idb
PStringBase<char> Shape_3; // idb
PStringBase<char> Shape_Point_3; // idb
PStringBase<char> Shape_Line_3; // idb
PStringBase<char> Shape_Quad_3; // idb
PStringBase<char> Shape_Disc_3; // idb
PStringBase<char> Shape_Sphere_3; // idb
PStringBase<char> ParticleShape_3; // idb
PStringBase<char> ParticleShape_Triangle_3; // idb
PStringBase<char> ParticleShape_Quad_3; // idb
PStringBase<char> Streak_3; // idb
PStringBase<char> Rotation_8; // idb
PStringBase<char> WorldRotation_3; // idb
PStringBase<char> RotateVelocity_3; // idb
PStringBase<char> ParticleScale_3; // idb
PStringBase<char> Scale_12; // idb
PStringBase<char> ExplodingDir_3; // idb
PStringBase<char> BirthRate_3; // idb
PStringBase<char> Lifespan_3; // idb
PStringBase<char> Velocity_3; // idb
PStringBase<char> Direction_3; // idb
PStringBase<char> MinSpread_3; // idb
PStringBase<char> MaxSpread_3; // idb
PStringBase<char> EmissionLimit_3; // idb
PStringBase<char> BlastCount_3; // idb
PStringBase<char> StartTime_3; // idb
PStringBase<char> TimeLimit_3; // idb
PStringBase<char> EmissionDistance_3; // idb
PStringBase<char> ParticleSnap_3; // idb
PStringBase<char> InclusiveShape_3; // idb
PStringBase<char> NumKeyframes_3; // idb
PStringBase<char> IsActive_3; // idb
PStringBase<char> FadeIn_3; // idb
PStringBase<char> FadeOut_3; // idb
PStringBase<char> ConstrainX_3; // idb
PStringBase<char> ConstrainY_3; // idb
PStringBase<char> ConstrainZ_3; // idb
PStringBase<char> NodeName_48; // idb
PStringBase<char> Time_3; // idb
PStringBase<char> Flags_3; // idb
PStringBase<char> Flags_None_3; // idb
PStringBase<char> Flags_BlendScale_3; // idb
PStringBase<char> Flags_BlendColor_3; // idb
PStringBase<char> Flags_BlendMass_3; // idb
PStringBase<char> Flags_SetScale_3; // idb
PStringBase<char> Flags_SetColor_3; // idb
PStringBase<char> Flags_SetMass_3; // idb
PStringBase<char> Flags_SetPFlags_3; // idb
PStringBase<char> Flags_SetPCType_3; // idb
PStringBase<char> Flags_SetPhysFlags_3; // idb
PStringBase<char> Flags_SetParams_3; // idb
PStringBase<char> Scale_13; // idb
PStringBase<char> ScaleX_3; // idb
PStringBase<char> ScaleY_3; // idb
PStringBase<char> Color_3; // idb
PStringBase<char> Mass_3; // idb
PStringBase<char> PFlags_3; // idb
PStringBase<char> PFlags_None_3; // idb
PStringBase<char> PCType_3; // idb
PStringBase<char> PCType_None_3; // idb
PStringBase<char> PCType_Physics_3; // idb
PStringBase<char> PCType_Parametric_3; // idb
PStringBase<char> PCType_AttractRepulse_3; // idb
PStringBase<char> PCType_PointFile_3; // idb
PStringBase<char> PCType_PointFileLerp_3; // idb
PStringBase<char> PhysFlags_3; // idb
PStringBase<char> PhysFlags_None_3; // idb
PStringBase<char> PhysFlags_Gravity_3; // idb
PStringBase<char> PhysFlags_Wind_3; // idb
PStringBase<char> PhysFlags_Momentum_3; // idb
PStringBase<char> PointfileFlags_RandomPoint_3; // idb
PStringBase<char> Position_4; // idb
PStringBase<char> PointList_3; // idb
PStringBase<char> Point_8; // idb
PStringBase<char> DetailLevels_3; // idb
PStringBase<char> DetailLevel_Low_3; // idb
PStringBase<char> DetailLevel_Medium_3; // idb
PStringBase<char> DetailLevel_High_3; // idb
PStringBase<char> FadeSpeed_3; // idb
PStringBase<char> MaxOpacity_3; // idb
PStringBase<char> Point_9; // idb
PStringBase<char> PointAxisPos_3; // idb
PStringBase<char> PointTexture_3; // idb
PStringBase<char> PointSize_3; // idb
PStringBase<char> UseOcclusion_3; // idb
PStringBase<char> PHEADER_STRINGS_3[4]; // idb
PStringBase<char> stru_83A864; // idb
PStringBase<char> stru_83A868; // idb
PStringBase<char> stru_83A86C; // idb
const float dword_83A870; // idb
const float outside_val_15; // idb
const float block_length_15; // idb
const float half_square_length_15; // idb
PStringBase<char> Render_TextureFiltering_10; // idb
PStringBase<char> Render_LandscapeDetailTextures_10; // idb
PStringBase<char> Render_BuildingDetailTextures_10; // idb
PStringBase<char> Render_FieldOfView_10; // idb
PStringBase<char> Render_LandscapeTextureDetail_10; // idb
PStringBase<char> Render_EnvironmentTextureDetail_10; // idb
PStringBase<char> Render_SceneryDrawDistance_10; // idb
PStringBase<char> Render_LandscapeDrawDistance_10; // idb
PStringBase<char> Render_ScreenBrightness_10; // idb
PStringBase<char> Render_AspectRatio_10; // idb
PStringBase<char> Render_DisplayAdapter_10; // idb
PStringBase<char> Render_MaxHardwareClass_10; // idb
PStringBase<char> Render_AutomaticDegrades_10; // idb
PStringBase<char> Render_GraphicsPerformance_10; // idb
PStringBase<char> Render_DegradeDistance_10; // idb
PStringBase<char> Render_MultiPassAlpha_10; // idb
PStringBase<char> Render_TextureFiltering_Choices_10[4]; // idb
PStringBase<char> stru_83A8C4; // idb
PStringBase<char> stru_83A8C8; // idb
PStringBase<char> stru_83A8CC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_10[5]; // idb
PStringBase<char> stru_83A8D4; // idb
PStringBase<char> stru_83A8D8; // idb
PStringBase<char> stru_83A8DC; // idb
PStringBase<char> stru_83A8E0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_10[5]; // idb
PStringBase<char> stru_83A8E8; // idb
PStringBase<char> stru_83A8EC; // idb
PStringBase<char> stru_83A8F0; // idb
PStringBase<char> stru_83A8F4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_10[3]; // idb
PStringBase<char> stru_83A8FC; // idb
PStringBase<char> stru_83A900; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_10[6]; // idb
PStringBase<char> stru_83A908; // idb
PStringBase<char> stru_83A90C; // idb
PStringBase<char> stru_83A910; // idb
PStringBase<char> stru_83A914; // idb
PStringBase<char> stru_83A918; // idb
PStringBase<char> Render_AspectRatio_Choices_10[3]; // idb
PStringBase<char> stru_83A920; // idb
PStringBase<char> stru_83A924; // idb
PStringBase<char> waveform_None_17; // idb
PStringBase<char> waveform_Speed_17; // idb
PStringBase<char> waveform_Noise_17; // idb
PStringBase<char> waveform_Sine_17; // idb
PStringBase<char> waveform_Square_17; // idb
PStringBase<char> waveform_Bounce_17; // idb
PStringBase<char> waveform_Perlin_17; // idb
PStringBase<char> waveform_Fractal_17; // idb
PStringBase<char> waveform_FrameLoop_17; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_20; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_21; // idb
const float dword_83A9D8; // idb
const float outside_val_16; // idb
const float block_length_16; // idb
const float half_square_length_16; // idb
PStringBase<char> Render_TextureFiltering_11; // idb
PStringBase<char> Render_LandscapeDetailTextures_11; // idb
PStringBase<char> Render_BuildingDetailTextures_11; // idb
PStringBase<char> Render_FieldOfView_11; // idb
PStringBase<char> Render_LandscapeTextureDetail_11; // idb
PStringBase<char> Render_EnvironmentTextureDetail_11; // idb
PStringBase<char> Render_SceneryDrawDistance_11; // idb
PStringBase<char> Render_LandscapeDrawDistance_11; // idb
PStringBase<char> Render_ScreenBrightness_11; // idb
PStringBase<char> Render_AspectRatio_11; // idb
PStringBase<char> Render_DisplayAdapter_11; // idb
PStringBase<char> Render_MaxHardwareClass_11; // idb
PStringBase<char> Render_AutomaticDegrades_11; // idb
PStringBase<char> Render_GraphicsPerformance_11; // idb
PStringBase<char> Render_DegradeDistance_11; // idb
PStringBase<char> Render_MultiPassAlpha_11; // idb
PStringBase<char> Render_TextureFiltering_Choices_11[4]; // idb
PStringBase<char> stru_83AA30; // idb
PStringBase<char> stru_83AA34; // idb
PStringBase<char> stru_83AA38; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_11[5]; // idb
PStringBase<char> stru_83AA40; // idb
PStringBase<char> stru_83AA44; // idb
PStringBase<char> stru_83AA48; // idb
PStringBase<char> stru_83AA4C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_11[5]; // idb
PStringBase<char> stru_83AA54; // idb
PStringBase<char> stru_83AA58; // idb
PStringBase<char> stru_83AA5C; // idb
PStringBase<char> stru_83AA60; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_11[3]; // idb
PStringBase<char> stru_83AA68; // idb
PStringBase<char> stru_83AA6C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_11[6]; // idb
PStringBase<char> stru_83AA74; // idb
PStringBase<char> stru_83AA78; // idb
PStringBase<char> stru_83AA7C; // idb
PStringBase<char> stru_83AA80; // idb
PStringBase<char> stru_83AA84; // idb
PStringBase<char> Render_AspectRatio_Choices_11[3]; // idb
PStringBase<char> stru_83AA8C; // idb
PStringBase<char> stru_83AA90; // idb
PStringBase<char> waveform_None_18; // idb
PStringBase<char> waveform_Speed_18; // idb
PStringBase<char> waveform_Noise_18; // idb
PStringBase<char> waveform_Sine_18; // idb
PStringBase<char> waveform_Square_18; // idb
PStringBase<char> waveform_Bounce_18; // idb
PStringBase<char> waveform_Perlin_18; // idb
PStringBase<char> waveform_Fractal_18; // idb
PStringBase<char> waveform_FrameLoop_18; // idb
PStringBase<char> waveform_None_19; // idb
PStringBase<char> waveform_Speed_19; // idb
PStringBase<char> waveform_Noise_19; // idb
PStringBase<char> waveform_Sine_19; // idb
PStringBase<char> waveform_Square_19; // idb
PStringBase<char> waveform_Bounce_19; // idb
PStringBase<char> waveform_Perlin_19; // idb
PStringBase<char> waveform_Fractal_19; // idb
PStringBase<char> waveform_FrameLoop_19; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_22; // idb
PStringBase<char> PHeader_4; // idb
PStringBase<char> VertexArray_4; // idb
PStringBase<char> BinaryVertexArray_4; // idb
PStringBase<char> VertexType_5; // idb
PStringBase<char> VertexData_4; // idb
PStringBase<char> Vertex_4; // idb
PStringBase<char> Index_9; // idb
PStringBase<char> Origin_9; // idb
PStringBase<char> Normal_4; // idb
PStringBase<char> Diffuse_9; // idb
PStringBase<char> Specular_9; // idb
PStringBase<char> UVS_4; // idb
PStringBase<char> VectorS_4; // idb
PStringBase<char> VectorT_4; // idb
PStringBase<char> VectorSxT_4; // idb
PStringBase<char> Weights_4; // idb
PStringBase<char> Importance_4; // idb
PStringBase<char> PhysMtl_4; // idb
PStringBase<char> Material_20; // idb
PStringBase<char> ID_10; // idb
PStringBase<char> FileName_4; // idb
PStringBase<char> Polygon_9; // idb
PStringBase<char> ID_11; // idb
PStringBase<char> Indices_6; // idb
PStringBase<char> MaterialID_4; // idb
PStringBase<char> PhysMaterialID_4; // idb
PStringBase<char> Markings_4; // idb
PStringBase<char> Material_21; // idb
PStringBase<char> Index_10; // idb
PStringBase<char> Filename_4; // idb
PStringBase<char> Surface_4; // idb
PStringBase<char> CellPoly_4; // idb
PStringBase<char> Sphere_5; // idb
PStringBase<char> Side_4; // idb
PStringBase<char> Positive_4; // idb
PStringBase<char> Negative_4; // idb
PStringBase<char> Polygon_10; // idb
PStringBase<char> OtherCell_9; // idb
PStringBase<char> CellPortal_4; // idb
PStringBase<char> Portal_5; // idb
PStringBase<char> OtherCell_10; // idb
PStringBase<char> OtherPortal_4; // idb
PStringBase<char> ExactMatch_4; // idb
PStringBase<char> StabList_4; // idb
PStringBase<char> Period_4; // idb
PStringBase<char> GrannyAnimation_4; // idb
PStringBase<char> Transform_4; // idb
PStringBase<char> Scale_14; // idb
PStringBase<char> Weight_4; // idb
PStringBase<char> Offset_4; // idb
PStringBase<char> Quaternion_5; // idb
PStringBase<char> Rotation_9; // idb
PStringBase<char> STime_4; // idb
PStringBase<char> PhysicsSplines_4; // idb
PStringBase<char> BoneOpacities_4; // idb
PStringBase<char> LowPt_4; // idb
PStringBase<char> Radius_4; // idb
PStringBase<char> Height_4; // idb
PStringBase<char> Texture2D_4; // idb
PStringBase<char> Texture3D_4; // idb
PStringBase<char> TextureCube_4; // idb
PStringBase<char> TextureMovie2D_4; // idb
PStringBase<char> MovieFileName_4; // idb
PStringBase<char> MovieFramesPerSecond_4; // idb
PStringBase<char> Levels_4; // idb
PStringBase<char> NodeName_49; // idb
PStringBase<char> Material_22; // idb
PStringBase<char> MaterialType_4; // idb
PStringBase<char> Modifier_4; // idb
PStringBase<char> AllowStencilShadows_4; // idb
PStringBase<char> DiscardGeometry_4; // idb
PStringBase<char> NodeName_50; // idb
PStringBase<char> SortMode_4; // idb
PStringBase<char> SortMode_None_4; // idb
PStringBase<char> SortMode_Triangle_4; // idb
PStringBase<char> NodeName_51; // idb
PStringBase<char> NodeName_52; // idb
PStringBase<char> DataType_DATA_4; // idb
PStringBase<char> DataType_WAVEFORM_4; // idb
PStringBase<char> DataType_COLOR_4; // idb
PStringBase<char> DataType_TEXTURE_4; // idb
PStringBase<char> DataType_BOOL_4; // idb
PStringBase<char> NodeName_53; // idb
PStringBase<char> modType_UVTranslate_4; // idb
PStringBase<char> modType_UVRotate_4; // idb
PStringBase<char> modType_UVScale_4; // idb
PStringBase<char> modType_UVTransform_4; // idb
PStringBase<char> TrueFlags_4; // idb
PStringBase<char> FalseFlags_4; // idb
PStringBase<char> RenderPass_4; // idb
PStringBase<char> Blend_4; // idb
PStringBase<char> DepthTest_4; // idb
PStringBase<char> DepthWrite_4; // idb
PStringBase<char> CullMode_4; // idb
PStringBase<char> DepthFog_4; // idb
PStringBase<char> AlphaTestMode_4; // idb
PStringBase<char> AlphaTestRef_4; // idb
PStringBase<char> FFUseLighting_4; // idb
PStringBase<char> FFUseDyeColorInTFactor_4; // idb
PStringBase<char> FFUseSpecularLighting_4; // idb
PStringBase<char> FFUseDistanceFog_4; // idb
PStringBase<char> FFUseVertexDiffuse_4; // idb
PStringBase<char> FFUseVertexSpecular_4; // idb
PStringBase<char> ShaderSupportsDynamicLights_4; // idb
PStringBase<char> UsesTransparency_4; // idb
PStringBase<char> Ambient_4; // idb
PStringBase<char> Diffuse_10; // idb
PStringBase<char> Specular_10; // idb
PStringBase<char> SpecularPower_4; // idb
PStringBase<char> Dye_4; // idb
PStringBase<char> Emissive_4; // idb
PStringBase<char> VertexFormat_4; // idb
PStringBase<char> VertexShader_4; // idb
PStringBase<char> PixelShader_4; // idb
PStringBase<char> param_MLF_NONE_4; // idb
PStringBase<char> param_MLF_REFLECTIONS_4; // idb
PStringBase<char> param_MLF_VIDEOPOST_4; // idb
PStringBase<char> param_MLF_HIGHDETAIL_4; // idb
PStringBase<char> param_MLF_SPECULAR_4; // idb
PStringBase<char> param_MLF_CLASS1_4; // idb
PStringBase<char> param_MLF_CLASS2_4; // idb
PStringBase<char> param_MLF_CLASS3_4; // idb
PStringBase<char> param_RenderPass_Default_4; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_4; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_4; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_4; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_4; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_4; // idb
PStringBase<char> param_RenderPass_DistanceFog_4; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_4; // idb
PStringBase<char> param_RenderPass_ShaderGlow_4; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_4; // idb
PStringBase<char> param_RenderPass_AlphaBlend_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_4; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_4; // idb
PStringBase<char> param_BLEND_ZERO_4; // idb
PStringBase<char> param_BLEND_ONE_4; // idb
PStringBase<char> param_BLEND_SRCCOLOR_4; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_4; // idb
PStringBase<char> param_BLEND_SRCALPHA_4; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_4; // idb
PStringBase<char> param_BLEND_DSTALPHA_4; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_4; // idb
PStringBase<char> param_BLEND_DSTCOLOR_4; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_4; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_4; // idb
PStringBase<char> param_DEPTHTEST_LESS_4; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_4; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_4; // idb
PStringBase<char> param_DEPTHTEST_GREATER_4; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_4; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_4; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_4; // idb
PStringBase<char> param_DEPTHWRITE_ON_4; // idb
PStringBase<char> param_DEPTHWRITE_OFF_4; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_4; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_4; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_4; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_4; // idb
PStringBase<char> param_CULLMODE_NONE_4; // idb
PStringBase<char> param_CULLMODE_CW_4; // idb
PStringBase<char> param_CULLMODE_CCW_4; // idb
PStringBase<char> param_LIGHTMODE_NONE_4; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_4; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_4; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_4; // idb
PStringBase<char> param_DEPTHFOG_OFF_4; // idb
PStringBase<char> param_DEPTHFOG_ON_4; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_4; // idb
PStringBase<char> param_ALPHATESTMODE_ON_4; // idb
PStringBase<char> param_VF_ORIGIN_4; // idb
PStringBase<char> param_VF_NORMAL_4; // idb
PStringBase<char> param_VF_POINTSIZE_4; // idb
PStringBase<char> param_VF_DIFFUSE_4; // idb
PStringBase<char> param_VF_SPECULAR_4; // idb
PStringBase<char> param_VF_TCPAIRx1_4; // idb
PStringBase<char> param_VF_TCPAIRx2_4; // idb
PStringBase<char> param_VF_TCPAIRx3_4; // idb
PStringBase<char> param_VF_TCPAIRx4_4; // idb
PStringBase<char> param_VF_TCPAIRx5_4; // idb
PStringBase<char> param_VF_TCPAIRx6_4; // idb
PStringBase<char> param_VF_TCPAIRx7_4; // idb
PStringBase<char> param_VF_TCPAIRx8_4; // idb
PStringBase<char> param_VF_VECTOR_S_4; // idb
PStringBase<char> param_VF_VECTOR_T_4; // idb
PStringBase<char> NodeName_54; // idb
PStringBase<char> SamplerNodeName_4; // idb
PStringBase<char> SamplerName_4; // idb
PStringBase<char> Texture_4; // idb
PStringBase<char> SpecialTexture_FrameBuffer_4; // idb
PStringBase<char> SpecialTexture_Distortion_4; // idb
PStringBase<char> SpecialTexture_Reflection_4; // idb
PStringBase<char> SpecialTexture_NormalizeCube_4; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_4; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_4; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_4; // idb
PStringBase<char> AddressMode_4; // idb
PStringBase<char> TexFilter_4; // idb
PStringBase<char> ColorOp_4; // idb
PStringBase<char> ColorArg1_4; // idb
PStringBase<char> ColorArg2_4; // idb
PStringBase<char> AlphaOp_4; // idb
PStringBase<char> AlphaArg1_4; // idb
PStringBase<char> AlphaArg2_4; // idb
PStringBase<char> TexCoord_4; // idb
PStringBase<char> UseProjection_4; // idb
PStringBase<char> param_TEXOP_SELECTARG1_4; // idb
PStringBase<char> param_TEXOP_SELECTARG2_4; // idb
PStringBase<char> param_TEXOP_MODULATE_4; // idb
PStringBase<char> param_TEXOP_MODULATE2X_4; // idb
PStringBase<char> param_TEXOP_MODULATE4X_4; // idb
PStringBase<char> param_TEXOP_ADD_4; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_4; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_4; // idb
PStringBase<char> param_TEXOP_SUBTRACT_4; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_4; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_4; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_4; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_4; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_4; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_4; // idb
PStringBase<char> param_TEXOP_PREMODULATE_4; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_4; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_4; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_4; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_4; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_4; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_4; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_4; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_4; // idb
PStringBase<char> param_TEXOP_LERP_4; // idb
PStringBase<char> param_TEXARG_DIFFUSE_4; // idb
PStringBase<char> param_TEXARG_SPECULAR_4; // idb
PStringBase<char> param_TEXARG_CURRENT_4; // idb
PStringBase<char> param_TEXARG_TEXTURE_4; // idb
PStringBase<char> param_TEXARG_TFACTOR_4; // idb
PStringBase<char> param_TEXADDRESS_WRAP_4; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_4; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_4; // idb
PStringBase<char> param_TEXADDRESS_BORDER_4; // idb
PStringBase<char> param_TEXFILTER_NONE_4; // idb
PStringBase<char> param_TEXFILTER_POINT_4; // idb
PStringBase<char> param_TEXFILTER_LINEAR_4; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_4; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_4; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_4; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_4; // idb
PStringBase<char> param_TEXCOORD_SphereMap_4; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_4; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_4; // idb
PStringBase<char> NodeName_55; // idb
PStringBase<char> ModType_Origin_4; // idb
PStringBase<char> ModType_Normal_4; // idb
PStringBase<char> ModType_Diffuse_4; // idb
PStringBase<char> ModType_UVTranslate_4; // idb
PStringBase<char> ModType_UVRotate_4; // idb
PStringBase<char> ModType_UVScale_4; // idb
PStringBase<char> ModType_UVTransform_4; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_4; // idb
PStringBase<char> Mod_UVTranslate_translate_4; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_4; // idb
PStringBase<char> Mod_UVRotate_rotate_4; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_4; // idb
PStringBase<char> Mod_UVScale_scale_4; // idb
PStringBase<char> NodeName_56; // idb
PStringBase<char> PhysicsTimeStep_4; // idb
PStringBase<char> FastForwardTime_4; // idb
PStringBase<char> StartFadeDistance_4; // idb
PStringBase<char> StopFadeDistance_4; // idb
PStringBase<char> PhysicsDuration_4; // idb
PStringBase<char> ScaleType_4; // idb
PStringBase<char> WorldSpace_4; // idb
PStringBase<char> ForceDraw_4; // idb
PStringBase<char> NumEmitters_4; // idb
PStringBase<char> Material_23; // idb
PStringBase<char> Version_4; // idb
PStringBase<char> MaxParticles_4; // idb
PStringBase<char> NodeName_57; // idb
PStringBase<char> Origin_10; // idb
PStringBase<char> Shape_4; // idb
PStringBase<char> Shape_Point_4; // idb
PStringBase<char> Shape_Line_4; // idb
PStringBase<char> Shape_Quad_4; // idb
PStringBase<char> Shape_Disc_4; // idb
PStringBase<char> Shape_Sphere_4; // idb
PStringBase<char> ParticleShape_4; // idb
PStringBase<char> ParticleShape_Triangle_4; // idb
PStringBase<char> ParticleShape_Quad_4; // idb
PStringBase<char> Streak_4; // idb
PStringBase<char> Rotation_10; // idb
PStringBase<char> WorldRotation_4; // idb
PStringBase<char> RotateVelocity_4; // idb
PStringBase<char> ParticleScale_4; // idb
PStringBase<char> Scale_15; // idb
PStringBase<char> ExplodingDir_4; // idb
PStringBase<char> BirthRate_4; // idb
PStringBase<char> Lifespan_4; // idb
PStringBase<char> Velocity_4; // idb
PStringBase<char> Direction_4; // idb
PStringBase<char> MinSpread_4; // idb
PStringBase<char> MaxSpread_4; // idb
PStringBase<char> EmissionLimit_4; // idb
PStringBase<char> BlastCount_4; // idb
PStringBase<char> StartTime_4; // idb
PStringBase<char> TimeLimit_4; // idb
PStringBase<char> EmissionDistance_4; // idb
PStringBase<char> ParticleSnap_4; // idb
PStringBase<char> InclusiveShape_4; // idb
PStringBase<char> NumKeyframes_4; // idb
PStringBase<char> IsActive_4; // idb
PStringBase<char> FadeIn_4; // idb
PStringBase<char> FadeOut_4; // idb
PStringBase<char> ConstrainX_4; // idb
PStringBase<char> ConstrainY_4; // idb
PStringBase<char> ConstrainZ_4; // idb
PStringBase<char> NodeName_58; // idb
PStringBase<char> Time_4; // idb
PStringBase<char> Flags_4; // idb
PStringBase<char> Flags_None_4; // idb
PStringBase<char> Flags_BlendScale_4; // idb
PStringBase<char> Flags_BlendColor_4; // idb
PStringBase<char> Flags_BlendMass_4; // idb
PStringBase<char> Flags_SetScale_4; // idb
PStringBase<char> Flags_SetColor_4; // idb
PStringBase<char> Flags_SetMass_4; // idb
PStringBase<char> Flags_SetPFlags_4; // idb
PStringBase<char> Flags_SetPCType_4; // idb
PStringBase<char> Flags_SetPhysFlags_4; // idb
PStringBase<char> Flags_SetParams_4; // idb
PStringBase<char> Scale_16; // idb
PStringBase<char> ScaleX_4; // idb
PStringBase<char> ScaleY_4; // idb
PStringBase<char> Color_4; // idb
PStringBase<char> Mass_4; // idb
PStringBase<char> PFlags_4; // idb
PStringBase<char> PFlags_None_4; // idb
PStringBase<char> PCType_4; // idb
PStringBase<char> PCType_None_4; // idb
PStringBase<char> PCType_Physics_4; // idb
PStringBase<char> PCType_Parametric_4; // idb
PStringBase<char> PCType_AttractRepulse_4; // idb
PStringBase<char> PCType_PointFile_4; // idb
PStringBase<char> PCType_PointFileLerp_4; // idb
PStringBase<char> PhysFlags_4; // idb
PStringBase<char> PhysFlags_None_4; // idb
PStringBase<char> PhysFlags_Gravity_4; // idb
PStringBase<char> PhysFlags_Wind_4; // idb
PStringBase<char> PhysFlags_Momentum_4; // idb
PStringBase<char> PointfileFlags_RandomPoint_4; // idb
PStringBase<char> Position_5; // idb
PStringBase<char> PointList_4; // idb
PStringBase<char> Point_10; // idb
PStringBase<char> DetailLevels_4; // idb
PStringBase<char> DetailLevel_Low_4; // idb
PStringBase<char> DetailLevel_Medium_4; // idb
PStringBase<char> DetailLevel_High_4; // idb
PStringBase<char> FadeSpeed_4; // idb
PStringBase<char> MaxOpacity_4; // idb
PStringBase<char> Point_11; // idb
PStringBase<char> PointAxisPos_4; // idb
PStringBase<char> PointTexture_4; // idb
PStringBase<char> PointSize_4; // idb
PStringBase<char> UseOcclusion_4; // idb
IDClass<_tagDataID,32,0> INVALID_DID_43; // idb
PStringBase<char> PHEADER_STRINGS_4[4]; // idb
PStringBase<char> stru_83B158; // idb
PStringBase<char> stru_83B15C; // idb
PStringBase<char> stru_83B160; // idb
_UNKNOWN unk_83B164; // weak
PStringBase<char> waveform_None_20; // idb
PStringBase<char> waveform_Speed_20; // idb
PStringBase<char> waveform_Noise_20; // idb
PStringBase<char> waveform_Sine_20; // idb
PStringBase<char> waveform_Square_20; // idb
PStringBase<char> waveform_Bounce_20; // idb
PStringBase<char> waveform_Perlin_20; // idb
PStringBase<char> waveform_Fractal_20; // idb
PStringBase<char> waveform_FrameLoop_20; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_23; // idb
PStringBase<char> PHeader_5; // idb
PStringBase<char> PreprocHeader_0; // idb
PStringBase<char> MeshAppearanceType_0; // idb
PStringBase<char> Fragment_0; // idb
PStringBase<char> FragmentType_0; // idb
PStringBase<char> FragmentType_LevelOfDetailModel_0; // idb
PStringBase<char> FragmentType_OccludeModel_0; // idb
PStringBase<char> FragmentType_ShadowLODModel_0; // idb
PStringBase<char> FragmentTopology_0; // idb
PStringBase<char> FragmentMOPP_0; // idb
PStringBase<char> MaterialBatch_0; // idb
PStringBase<char> FragmentBatch_0; // idb
PStringBase<char> PrimitivesType_0; // idb
PStringBase<char> PrimitivesType_PointList_0; // idb
PStringBase<char> PrimitivesType_LineList_0; // idb
PStringBase<char> PrimitivesType_LineStrip_0; // idb
PStringBase<char> PrimitivesType_TriangleList_0; // idb
PStringBase<char> PrimitivesType_TriangleStrip_0; // idb
PStringBase<char> PrimitivesType_TriangleFan_0; // idb
PStringBase<char> Material_24; // idb
PStringBase<char> Vertices_0; // idb
PStringBase<char> Indices_7; // idb
PStringBase<char> ExportMeshAppearanceType_0; // idb
PStringBase<char> MeshDegradeType_0; // idb
PStringBase<char> DegradeLevel_0; // idb
PStringBase<char> NumDegradeLevels_0; // idb
PStringBase<char> CellMesh_0; // idb
PStringBase<char> MaterialArray_0; // idb
PStringBase<char> Render_0; // idb
PStringBase<char> RenderMesh_0; // idb
PStringBase<char> RenderMeshVersion_0; // idb
PStringBase<char> Sphere_6; // idb
PStringBase<char> DetailedBSP_0; // idb
PStringBase<char> PolygonArray_0; // idb
PStringBase<char> BinaryPolygonArray_0; // idb
PStringBase<char> Physics_0; // idb
PStringBase<char> BSPTree_0; // idb
PStringBase<char> BinaryBSPTree_0; // idb
PStringBase<char> Cell_0; // idb
PStringBase<char> CellBSP_0; // idb
PStringBase<char> Portals_0; // idb
PStringBase<char> Portal_6; // idb
PStringBase<char> NonPortals_0; // idb
PStringBase<char> NonPortal_0; // idb
PStringBase<char> Info_0; // idb
PStringBase<char> CellVolumeInfo_0; // idb
PStringBase<char> CellStructure_0; // idb
PStringBase<char> CellRotation_0; // idb
PStringBase<char> CellGridSize_0; // idb
PStringBase<char> CellNeverCull_0; // idb
PStringBase<char> CellDrawSky_0; // idb
PStringBase<char> DegradeArray_0; // idb
PStringBase<char> OccludeMeshArray_0; // idb
PStringBase<char> DegradeMesh_0; // idb
PStringBase<char> BSP_0; // idb
PStringBase<char> BumpMap_0; // idb
PStringBase<char> UVSets_0; // idb
PStringBase<char> PhysicsMesh_0; // idb
PStringBase<char> PhysicsMaterials_0; // idb
PStringBase<char> PhysicsMaterialArray_0; // idb
PStringBase<char> PathMapMeshArray_0; // idb
PStringBase<char> PathMapPolygonArray_0; // idb
PStringBase<char> PathMapPolygon_0; // idb
PStringBase<char> VertexSetArray_0; // idb
PStringBase<char> VertexSets_0; // idb
PStringBase<char> VertexSet_0; // idb
PStringBase<char> Set_0; // idb
PStringBase<char> ID_12; // idb
PStringBase<char> Name_1; // idb
PStringBase<char> Indices_8; // idb
PStringBase<char> MorphMeshArray_0; // idb
PStringBase<char> MorphMesh_0; // idb
PStringBase<char> MorphTargets_0; // idb
PStringBase<char> Target_0; // idb
PStringBase<char> Name_2; // idb
PStringBase<char> waveform_None_21; // idb
PStringBase<char> waveform_Speed_21; // idb
PStringBase<char> waveform_Noise_21; // idb
PStringBase<char> waveform_Sine_21; // idb
PStringBase<char> waveform_Square_21; // idb
PStringBase<char> waveform_Bounce_21; // idb
PStringBase<char> waveform_Perlin_21; // idb
PStringBase<char> waveform_Fractal_21; // idb
PStringBase<char> waveform_FrameLoop_21; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_24; // idb
PStringBase<char> PHeader_6; // idb
PStringBase<char> PreprocHeader_1; // idb
PStringBase<char> MeshAppearanceType_1; // idb
PStringBase<char> Fragment_1; // idb
PStringBase<char> FragmentType_1; // idb
PStringBase<char> FragmentType_LevelOfDetailModel_1; // idb
PStringBase<char> FragmentType_OccludeModel_1; // idb
PStringBase<char> FragmentType_ShadowLODModel_1; // idb
PStringBase<char> FragmentTopology_1; // idb
PStringBase<char> FragmentMOPP_1; // idb
PStringBase<char> MaterialBatch_1; // idb
PStringBase<char> FragmentBatch_1; // idb
PStringBase<char> PrimitivesType_1; // idb
PStringBase<char> PrimitivesType_PointList_1; // idb
PStringBase<char> PrimitivesType_LineList_1; // idb
PStringBase<char> PrimitivesType_LineStrip_1; // idb
PStringBase<char> PrimitivesType_TriangleList_1; // idb
PStringBase<char> PrimitivesType_TriangleStrip_1; // idb
PStringBase<char> PrimitivesType_TriangleFan_1; // idb
PStringBase<char> Material_25; // idb
PStringBase<char> Vertices_1; // idb
PStringBase<char> Indices_9; // idb
PStringBase<char> ExportMeshAppearanceType_1; // idb
PStringBase<char> MeshDegradeType_1; // idb
PStringBase<char> DegradeLevel_1; // idb
PStringBase<char> NumDegradeLevels_1; // idb
PStringBase<char> CellMesh_1; // idb
PStringBase<char> MaterialArray_1; // idb
PStringBase<char> Render_1; // idb
PStringBase<char> RenderMesh_1; // idb
PStringBase<char> RenderMeshVersion_1; // idb
PStringBase<char> Sphere_7; // idb
PStringBase<char> DetailedBSP_1; // idb
PStringBase<char> PolygonArray_1; // idb
PStringBase<char> BinaryPolygonArray_1; // idb
PStringBase<char> Physics_1; // idb
PStringBase<char> BSPTree_1; // idb
PStringBase<char> BinaryBSPTree_1; // idb
PStringBase<char> Cell_1; // idb
PStringBase<char> CellBSP_1; // idb
PStringBase<char> Portals_1; // idb
PStringBase<char> Portal_7; // idb
PStringBase<char> NonPortals_1; // idb
PStringBase<char> NonPortal_1; // idb
PStringBase<char> Info_1; // idb
PStringBase<char> CellVolumeInfo_1; // idb
PStringBase<char> CellStructure_1; // idb
PStringBase<char> CellRotation_1; // idb
PStringBase<char> CellGridSize_1; // idb
PStringBase<char> CellNeverCull_1; // idb
PStringBase<char> CellDrawSky_1; // idb
PStringBase<char> DegradeArray_1; // idb
PStringBase<char> OccludeMeshArray_1; // idb
PStringBase<char> DegradeMesh_1; // idb
PStringBase<char> BSP_1; // idb
PStringBase<char> BumpMap_1; // idb
PStringBase<char> UVSets_1; // idb
PStringBase<char> PhysicsMesh_1; // idb
PStringBase<char> PhysicsMaterials_1; // idb
PStringBase<char> PhysicsMaterialArray_1; // idb
PStringBase<char> PathMapMeshArray_1; // idb
PStringBase<char> PathMapPolygonArray_1; // idb
PStringBase<char> PathMapPolygon_1; // idb
PStringBase<char> VertexSetArray_1; // idb
PStringBase<char> VertexSets_1; // idb
PStringBase<char> VertexSet_1; // idb
PStringBase<char> Set_1; // idb
PStringBase<char> ID_13; // idb
PStringBase<char> Name_3; // idb
PStringBase<char> Indices_10; // idb
PStringBase<char> MorphMeshArray_1; // idb
PStringBase<char> MorphMesh_1; // idb
PStringBase<char> MorphTargets_1; // idb
PStringBase<char> Target_1; // idb
PStringBase<char> Name_4; // idb
IDClass<_tagDataID,32,0> INVALID_DID_44; // idb
IDClass<_tagDataID,32,0> INVALID_DID_45; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_25; // idb
const float dword_83B508; // idb
const float outside_val_17; // idb
const float block_length_17; // idb
const float half_square_length_17; // idb
PStringBase<char> Render_TextureFiltering_12; // idb
PStringBase<char> Render_LandscapeDetailTextures_12; // idb
PStringBase<char> Render_BuildingDetailTextures_12; // idb
PStringBase<char> Render_FieldOfView_12; // idb
PStringBase<char> Render_LandscapeTextureDetail_12; // idb
PStringBase<char> Render_EnvironmentTextureDetail_12; // idb
PStringBase<char> Render_SceneryDrawDistance_12; // idb
PStringBase<char> Render_LandscapeDrawDistance_12; // idb
PStringBase<char> Render_ScreenBrightness_12; // idb
PStringBase<char> Render_AspectRatio_12; // idb
PStringBase<char> Render_DisplayAdapter_12; // idb
PStringBase<char> Render_MaxHardwareClass_12; // idb
PStringBase<char> Render_AutomaticDegrades_12; // idb
PStringBase<char> Render_GraphicsPerformance_12; // idb
PStringBase<char> Render_DegradeDistance_12; // idb
PStringBase<char> Render_MultiPassAlpha_12; // idb
PStringBase<char> Render_TextureFiltering_Choices_12[4]; // idb
PStringBase<char> stru_83B55C; // idb
PStringBase<char> stru_83B560; // idb
PStringBase<char> stru_83B564; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_12[5]; // idb
PStringBase<char> stru_83B56C; // idb
PStringBase<char> stru_83B570; // idb
PStringBase<char> stru_83B574; // idb
PStringBase<char> stru_83B578; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_12[5]; // idb
PStringBase<char> stru_83B580; // idb
PStringBase<char> stru_83B584; // idb
PStringBase<char> stru_83B588; // idb
PStringBase<char> stru_83B58C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_12[3]; // idb
PStringBase<char> stru_83B594; // idb
PStringBase<char> stru_83B598; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_12[6]; // idb
PStringBase<char> stru_83B5A0; // idb
PStringBase<char> stru_83B5A4; // idb
PStringBase<char> stru_83B5A8; // idb
PStringBase<char> stru_83B5AC; // idb
PStringBase<char> stru_83B5B0; // idb
PStringBase<char> Render_AspectRatio_Choices_12[3]; // idb
PStringBase<char> stru_83B5B8; // idb
PStringBase<char> stru_83B5BC; // idb
PStringBase<char> waveform_None_22; // idb
PStringBase<char> waveform_Speed_22; // idb
PStringBase<char> waveform_Noise_22; // idb
PStringBase<char> waveform_Sine_22; // idb
PStringBase<char> waveform_Square_22; // idb
PStringBase<char> waveform_Bounce_22; // idb
PStringBase<char> waveform_Perlin_22; // idb
PStringBase<char> waveform_Fractal_22; // idb
PStringBase<char> waveform_FrameLoop_22; // idb
PStringBase<char> PHeader_7; // idb
PStringBase<char> VertexArray_5; // idb
PStringBase<char> BinaryVertexArray_5; // idb
PStringBase<char> VertexType_6; // idb
PStringBase<char> VertexData_5; // idb
PStringBase<char> Vertex_5; // idb
PStringBase<char> Index_11; // idb
PStringBase<char> Origin_11; // idb
PStringBase<char> Normal_5; // idb
PStringBase<char> Diffuse_11; // idb
PStringBase<char> Specular_11; // idb
PStringBase<char> UVS_5; // idb
PStringBase<char> VectorS_5; // idb
PStringBase<char> VectorT_5; // idb
PStringBase<char> VectorSxT_5; // idb
PStringBase<char> Weights_5; // idb
PStringBase<char> Importance_5; // idb
PStringBase<char> PhysMtl_5; // idb
PStringBase<char> Material_26; // idb
PStringBase<char> ID_14; // idb
PStringBase<char> FileName_5; // idb
PStringBase<char> Polygon_11; // idb
PStringBase<char> ID_15; // idb
PStringBase<char> Indices_11; // idb
PStringBase<char> MaterialID_5; // idb
PStringBase<char> PhysMaterialID_5; // idb
PStringBase<char> Markings_5; // idb
PStringBase<char> Material_27; // idb
PStringBase<char> Index_12; // idb
PStringBase<char> Filename_5; // idb
PStringBase<char> Surface_5; // idb
PStringBase<char> CellPoly_5; // idb
PStringBase<char> Sphere_8; // idb
PStringBase<char> Side_5; // idb
PStringBase<char> Positive_5; // idb
PStringBase<char> Negative_5; // idb
PStringBase<char> Polygon_12; // idb
PStringBase<char> OtherCell_11; // idb
PStringBase<char> CellPortal_5; // idb
PStringBase<char> Portal_8; // idb
PStringBase<char> OtherCell_12; // idb
PStringBase<char> OtherPortal_5; // idb
PStringBase<char> ExactMatch_5; // idb
PStringBase<char> StabList_5; // idb
PStringBase<char> Period_5; // idb
PStringBase<char> GrannyAnimation_5; // idb
PStringBase<char> Transform_5; // idb
PStringBase<char> Scale_17; // idb
PStringBase<char> Weight_5; // idb
PStringBase<char> Offset_5; // idb
PStringBase<char> Quaternion_6; // idb
PStringBase<char> Rotation_11; // idb
PStringBase<char> STime_5; // idb
PStringBase<char> PhysicsSplines_5; // idb
PStringBase<char> BoneOpacities_5; // idb
PStringBase<char> LowPt_5; // idb
PStringBase<char> Radius_5; // idb
PStringBase<char> Height_5; // idb
PStringBase<char> Texture2D_5; // idb
PStringBase<char> Texture3D_5; // idb
PStringBase<char> TextureCube_5; // idb
PStringBase<char> TextureMovie2D_5; // idb
PStringBase<char> MovieFileName_5; // idb
PStringBase<char> MovieFramesPerSecond_5; // idb
PStringBase<char> Levels_5; // idb
PStringBase<char> NodeName_59; // idb
PStringBase<char> Material_28; // idb
PStringBase<char> MaterialType_5; // idb
PStringBase<char> Modifier_5; // idb
PStringBase<char> AllowStencilShadows_5; // idb
PStringBase<char> DiscardGeometry_5; // idb
PStringBase<char> NodeName_60; // idb
PStringBase<char> SortMode_5; // idb
PStringBase<char> SortMode_None_5; // idb
PStringBase<char> SortMode_Triangle_5; // idb
PStringBase<char> NodeName_61; // idb
PStringBase<char> NodeName_62; // idb
PStringBase<char> DataType_DATA_5; // idb
PStringBase<char> DataType_WAVEFORM_5; // idb
PStringBase<char> DataType_COLOR_5; // idb
PStringBase<char> DataType_TEXTURE_5; // idb
PStringBase<char> DataType_BOOL_5; // idb
PStringBase<char> NodeName_63; // idb
PStringBase<char> modType_UVTranslate_5; // idb
PStringBase<char> modType_UVRotate_5; // idb
PStringBase<char> modType_UVScale_5; // idb
PStringBase<char> modType_UVTransform_5; // idb
PStringBase<char> TrueFlags_5; // idb
PStringBase<char> FalseFlags_5; // idb
PStringBase<char> RenderPass_5; // idb
PStringBase<char> Blend_5; // idb
PStringBase<char> DepthTest_5; // idb
PStringBase<char> DepthWrite_5; // idb
PStringBase<char> CullMode_5; // idb
PStringBase<char> DepthFog_5; // idb
PStringBase<char> AlphaTestMode_5; // idb
PStringBase<char> AlphaTestRef_5; // idb
PStringBase<char> FFUseLighting_5; // idb
PStringBase<char> FFUseDyeColorInTFactor_5; // idb
PStringBase<char> FFUseSpecularLighting_5; // idb
PStringBase<char> FFUseDistanceFog_5; // idb
PStringBase<char> FFUseVertexDiffuse_5; // idb
PStringBase<char> FFUseVertexSpecular_5; // idb
PStringBase<char> ShaderSupportsDynamicLights_5; // idb
PStringBase<char> UsesTransparency_5; // idb
PStringBase<char> Ambient_5; // idb
PStringBase<char> Diffuse_12; // idb
PStringBase<char> Specular_12; // idb
PStringBase<char> SpecularPower_5; // idb
PStringBase<char> Dye_5; // idb
PStringBase<char> Emissive_5; // idb
PStringBase<char> VertexFormat_5; // idb
PStringBase<char> VertexShader_5; // idb
PStringBase<char> PixelShader_5; // idb
PStringBase<char> param_MLF_NONE_5; // idb
PStringBase<char> param_MLF_REFLECTIONS_5; // idb
PStringBase<char> param_MLF_VIDEOPOST_5; // idb
PStringBase<char> param_MLF_HIGHDETAIL_5; // idb
PStringBase<char> param_MLF_SPECULAR_5; // idb
PStringBase<char> param_MLF_CLASS1_5; // idb
PStringBase<char> param_MLF_CLASS2_5; // idb
PStringBase<char> param_MLF_CLASS3_5; // idb
PStringBase<char> param_RenderPass_Default_5; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_5; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_5; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_5; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_5; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_5; // idb
PStringBase<char> param_RenderPass_DistanceFog_5; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_5; // idb
PStringBase<char> param_RenderPass_ShaderGlow_5; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_5; // idb
PStringBase<char> param_RenderPass_AlphaBlend_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_5; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_5; // idb
PStringBase<char> param_BLEND_ZERO_5; // idb
PStringBase<char> param_BLEND_ONE_5; // idb
PStringBase<char> param_BLEND_SRCCOLOR_5; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_5; // idb
PStringBase<char> param_BLEND_SRCALPHA_5; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_5; // idb
PStringBase<char> param_BLEND_DSTALPHA_5; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_5; // idb
PStringBase<char> param_BLEND_DSTCOLOR_5; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_5; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_5; // idb
PStringBase<char> param_DEPTHTEST_LESS_5; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_5; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_5; // idb
PStringBase<char> param_DEPTHTEST_GREATER_5; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_5; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_5; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_5; // idb
PStringBase<char> param_DEPTHWRITE_ON_5; // idb
PStringBase<char> param_DEPTHWRITE_OFF_5; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_5; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_5; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_5; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_5; // idb
PStringBase<char> param_CULLMODE_NONE_5; // idb
PStringBase<char> param_CULLMODE_CW_5; // idb
PStringBase<char> param_CULLMODE_CCW_5; // idb
PStringBase<char> param_LIGHTMODE_NONE_5; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_5; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_5; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_5; // idb
PStringBase<char> param_DEPTHFOG_OFF_5; // idb
PStringBase<char> param_DEPTHFOG_ON_5; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_5; // idb
PStringBase<char> param_ALPHATESTMODE_ON_5; // idb
PStringBase<char> param_VF_ORIGIN_5; // idb
PStringBase<char> param_VF_NORMAL_5; // idb
PStringBase<char> param_VF_POINTSIZE_5; // idb
PStringBase<char> param_VF_DIFFUSE_5; // idb
PStringBase<char> param_VF_SPECULAR_5; // idb
PStringBase<char> param_VF_TCPAIRx1_5; // idb
PStringBase<char> param_VF_TCPAIRx2_5; // idb
PStringBase<char> param_VF_TCPAIRx3_5; // idb
PStringBase<char> param_VF_TCPAIRx4_5; // idb
PStringBase<char> param_VF_TCPAIRx5_5; // idb
PStringBase<char> param_VF_TCPAIRx6_5; // idb
PStringBase<char> param_VF_TCPAIRx7_5; // idb
PStringBase<char> param_VF_TCPAIRx8_5; // idb
PStringBase<char> param_VF_VECTOR_S_5; // idb
PStringBase<char> param_VF_VECTOR_T_5; // idb
PStringBase<char> NodeName_64; // idb
PStringBase<char> SamplerNodeName_5; // idb
PStringBase<char> SamplerName_5; // idb
PStringBase<char> Texture_5; // idb
PStringBase<char> SpecialTexture_FrameBuffer_5; // idb
PStringBase<char> SpecialTexture_Distortion_5; // idb
PStringBase<char> SpecialTexture_Reflection_5; // idb
PStringBase<char> SpecialTexture_NormalizeCube_5; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_5; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_5; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_5; // idb
PStringBase<char> AddressMode_5; // idb
PStringBase<char> TexFilter_5; // idb
PStringBase<char> ColorOp_5; // idb
PStringBase<char> ColorArg1_5; // idb
PStringBase<char> ColorArg2_5; // idb
PStringBase<char> AlphaOp_5; // idb
PStringBase<char> AlphaArg1_5; // idb
PStringBase<char> AlphaArg2_5; // idb
PStringBase<char> TexCoord_5; // idb
PStringBase<char> UseProjection_5; // idb
PStringBase<char> param_TEXOP_SELECTARG1_5; // idb
PStringBase<char> param_TEXOP_SELECTARG2_5; // idb
PStringBase<char> param_TEXOP_MODULATE_5; // idb
PStringBase<char> param_TEXOP_MODULATE2X_5; // idb
PStringBase<char> param_TEXOP_MODULATE4X_5; // idb
PStringBase<char> param_TEXOP_ADD_5; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_5; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_5; // idb
PStringBase<char> param_TEXOP_SUBTRACT_5; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_5; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_5; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_5; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_5; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_5; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_5; // idb
PStringBase<char> param_TEXOP_PREMODULATE_5; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_5; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_5; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_5; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_5; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_5; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_5; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_5; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_5; // idb
PStringBase<char> param_TEXOP_LERP_5; // idb
PStringBase<char> param_TEXARG_DIFFUSE_5; // idb
PStringBase<char> param_TEXARG_SPECULAR_5; // idb
PStringBase<char> param_TEXARG_CURRENT_5; // idb
PStringBase<char> param_TEXARG_TEXTURE_5; // idb
PStringBase<char> param_TEXARG_TFACTOR_5; // idb
PStringBase<char> param_TEXADDRESS_WRAP_5; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_5; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_5; // idb
PStringBase<char> param_TEXADDRESS_BORDER_5; // idb
PStringBase<char> param_TEXFILTER_NONE_5; // idb
PStringBase<char> param_TEXFILTER_POINT_5; // idb
PStringBase<char> param_TEXFILTER_LINEAR_5; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_5; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_5; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_5; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_5; // idb
PStringBase<char> param_TEXCOORD_SphereMap_5; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_5; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_5; // idb
PStringBase<char> NodeName_65; // idb
PStringBase<char> ModType_Origin_5; // idb
PStringBase<char> ModType_Normal_5; // idb
PStringBase<char> ModType_Diffuse_5; // idb
PStringBase<char> ModType_UVTranslate_5; // idb
PStringBase<char> ModType_UVRotate_5; // idb
PStringBase<char> ModType_UVScale_5; // idb
PStringBase<char> ModType_UVTransform_5; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_5; // idb
PStringBase<char> Mod_UVTranslate_translate_5; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_5; // idb
PStringBase<char> Mod_UVRotate_rotate_5; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_5; // idb
PStringBase<char> Mod_UVScale_scale_5; // idb
PStringBase<char> NodeName_66; // idb
PStringBase<char> PhysicsTimeStep_5; // idb
PStringBase<char> FastForwardTime_5; // idb
PStringBase<char> StartFadeDistance_5; // idb
PStringBase<char> StopFadeDistance_5; // idb
PStringBase<char> PhysicsDuration_5; // idb
PStringBase<char> ScaleType_5; // idb
PStringBase<char> WorldSpace_5; // idb
PStringBase<char> ForceDraw_5; // idb
PStringBase<char> NumEmitters_5; // idb
PStringBase<char> Material_29; // idb
PStringBase<char> Version_5; // idb
PStringBase<char> MaxParticles_5; // idb
PStringBase<char> NodeName_67; // idb
PStringBase<char> Origin_12; // idb
PStringBase<char> Shape_5; // idb
PStringBase<char> Shape_Point_5; // idb
PStringBase<char> Shape_Line_5; // idb
PStringBase<char> Shape_Quad_5; // idb
PStringBase<char> Shape_Disc_5; // idb
PStringBase<char> Shape_Sphere_5; // idb
PStringBase<char> ParticleShape_5; // idb
PStringBase<char> ParticleShape_Triangle_5; // idb
PStringBase<char> ParticleShape_Quad_5; // idb
PStringBase<char> Streak_5; // idb
PStringBase<char> Rotation_12; // idb
PStringBase<char> WorldRotation_5; // idb
PStringBase<char> RotateVelocity_5; // idb
PStringBase<char> ParticleScale_5; // idb
PStringBase<char> Scale_18; // idb
PStringBase<char> ExplodingDir_5; // idb
PStringBase<char> BirthRate_5; // idb
PStringBase<char> Lifespan_5; // idb
PStringBase<char> Velocity_5; // idb
PStringBase<char> Direction_5; // idb
PStringBase<char> MinSpread_5; // idb
PStringBase<char> MaxSpread_5; // idb
PStringBase<char> EmissionLimit_5; // idb
PStringBase<char> BlastCount_5; // idb
PStringBase<char> StartTime_5; // idb
PStringBase<char> TimeLimit_5; // idb
PStringBase<char> EmissionDistance_5; // idb
PStringBase<char> ParticleSnap_5; // idb
PStringBase<char> InclusiveShape_5; // idb
PStringBase<char> NumKeyframes_5; // idb
PStringBase<char> IsActive_5; // idb
PStringBase<char> FadeIn_5; // idb
PStringBase<char> FadeOut_5; // idb
PStringBase<char> ConstrainX_5; // idb
PStringBase<char> ConstrainY_5; // idb
PStringBase<char> ConstrainZ_5; // idb
PStringBase<char> NodeName_68; // idb
PStringBase<char> Time_5; // idb
PStringBase<char> Flags_5; // idb
PStringBase<char> Flags_None_5; // idb
PStringBase<char> Flags_BlendScale_5; // idb
PStringBase<char> Flags_BlendColor_5; // idb
PStringBase<char> Flags_BlendMass_5; // idb
PStringBase<char> Flags_SetScale_5; // idb
PStringBase<char> Flags_SetColor_5; // idb
PStringBase<char> Flags_SetMass_5; // idb
PStringBase<char> Flags_SetPFlags_5; // idb
PStringBase<char> Flags_SetPCType_5; // idb
PStringBase<char> Flags_SetPhysFlags_5; // idb
PStringBase<char> Flags_SetParams_5; // idb
PStringBase<char> Scale_19; // idb
PStringBase<char> ScaleX_5; // idb
PStringBase<char> ScaleY_5; // idb
PStringBase<char> Color_5; // idb
PStringBase<char> Mass_5; // idb
PStringBase<char> PFlags_5; // idb
PStringBase<char> PFlags_None_5; // idb
PStringBase<char> PCType_5; // idb
PStringBase<char> PCType_None_5; // idb
PStringBase<char> PCType_Physics_5; // idb
PStringBase<char> PCType_Parametric_5; // idb
PStringBase<char> PCType_AttractRepulse_5; // idb
PStringBase<char> PCType_PointFile_5; // idb
PStringBase<char> PCType_PointFileLerp_5; // idb
PStringBase<char> PhysFlags_5; // idb
PStringBase<char> PhysFlags_None_5; // idb
PStringBase<char> PhysFlags_Gravity_5; // idb
PStringBase<char> PhysFlags_Wind_5; // idb
PStringBase<char> PhysFlags_Momentum_5; // idb
PStringBase<char> PointfileFlags_RandomPoint_5; // idb
PStringBase<char> Position_6; // idb
PStringBase<char> PointList_5; // idb
PStringBase<char> Point_12; // idb
PStringBase<char> DetailLevels_5; // idb
PStringBase<char> DetailLevel_Low_5; // idb
PStringBase<char> DetailLevel_Medium_5; // idb
PStringBase<char> DetailLevel_High_5; // idb
PStringBase<char> FadeSpeed_5; // idb
PStringBase<char> MaxOpacity_5; // idb
PStringBase<char> Point_13; // idb
PStringBase<char> PointAxisPos_5; // idb
PStringBase<char> PointTexture_5; // idb
PStringBase<char> PointSize_5; // idb
PStringBase<char> UseOcclusion_5; // idb
PStringBase<char> waveform_None_23; // idb
PStringBase<char> waveform_Speed_23; // idb
PStringBase<char> waveform_Noise_23; // idb
PStringBase<char> waveform_Sine_23; // idb
PStringBase<char> waveform_Square_23; // idb
PStringBase<char> waveform_Bounce_23; // idb
PStringBase<char> waveform_Perlin_23; // idb
PStringBase<char> waveform_Fractal_23; // idb
PStringBase<char> waveform_FrameLoop_23; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_26; // idb
PStringBase<char> PHeader_8; // idb
PStringBase<char> VertexArray_6; // idb
PStringBase<char> BinaryVertexArray_6; // idb
PStringBase<char> VertexType_7; // idb
PStringBase<char> VertexData_6; // idb
PStringBase<char> Vertex_6; // idb
PStringBase<char> Index_13; // idb
PStringBase<char> Origin_13; // idb
PStringBase<char> Normal_6; // idb
PStringBase<char> Diffuse_13; // idb
PStringBase<char> Specular_13; // idb
PStringBase<char> UVS_6; // idb
PStringBase<char> VectorS_6; // idb
PStringBase<char> VectorT_6; // idb
PStringBase<char> VectorSxT_6; // idb
PStringBase<char> Weights_6; // idb
PStringBase<char> Importance_6; // idb
PStringBase<char> PhysMtl_6; // idb
PStringBase<char> Material_30; // idb
PStringBase<char> ID_16; // idb
PStringBase<char> FileName_6; // idb
PStringBase<char> Polygon_13; // idb
PStringBase<char> ID_17; // idb
PStringBase<char> Indices_12; // idb
PStringBase<char> MaterialID_6; // idb
PStringBase<char> PhysMaterialID_6; // idb
PStringBase<char> Markings_6; // idb
PStringBase<char> Material_31; // idb
PStringBase<char> Index_14; // idb
PStringBase<char> Filename_6; // idb
PStringBase<char> Surface_6; // idb
PStringBase<char> CellPoly_6; // idb
PStringBase<char> Sphere_9; // idb
PStringBase<char> Side_6; // idb
PStringBase<char> Positive_6; // idb
PStringBase<char> Negative_6; // idb
PStringBase<char> Polygon_14; // idb
PStringBase<char> OtherCell_13; // idb
PStringBase<char> CellPortal_6; // idb
PStringBase<char> Portal_9; // idb
PStringBase<char> OtherCell_14; // idb
PStringBase<char> OtherPortal_6; // idb
PStringBase<char> ExactMatch_6; // idb
PStringBase<char> StabList_6; // idb
PStringBase<char> Period_6; // idb
PStringBase<char> GrannyAnimation_6; // idb
PStringBase<char> Transform_6; // idb
PStringBase<char> Scale_20; // idb
PStringBase<char> Weight_6; // idb
PStringBase<char> Offset_6; // idb
PStringBase<char> Quaternion_7; // idb
PStringBase<char> Rotation_13; // idb
PStringBase<char> STime_6; // idb
PStringBase<char> PhysicsSplines_6; // idb
PStringBase<char> BoneOpacities_6; // idb
PStringBase<char> LowPt_6; // idb
PStringBase<char> Radius_6; // idb
PStringBase<char> Height_6; // idb
PStringBase<char> Texture2D_6; // idb
PStringBase<char> Texture3D_6; // idb
PStringBase<char> TextureCube_6; // idb
PStringBase<char> TextureMovie2D_6; // idb
PStringBase<char> MovieFileName_6; // idb
PStringBase<char> MovieFramesPerSecond_6; // idb
PStringBase<char> Levels_6; // idb
PStringBase<char> NodeName_69; // idb
PStringBase<char> Material_32; // idb
PStringBase<char> MaterialType_6; // idb
PStringBase<char> Modifier_6; // idb
PStringBase<char> AllowStencilShadows_6; // idb
PStringBase<char> DiscardGeometry_6; // idb
PStringBase<char> NodeName_70; // idb
PStringBase<char> SortMode_6; // idb
PStringBase<char> SortMode_None_6; // idb
PStringBase<char> SortMode_Triangle_6; // idb
PStringBase<char> NodeName_71; // idb
PStringBase<char> NodeName_72; // idb
PStringBase<char> DataType_DATA_6; // idb
PStringBase<char> DataType_WAVEFORM_6; // idb
PStringBase<char> DataType_COLOR_6; // idb
PStringBase<char> DataType_TEXTURE_6; // idb
PStringBase<char> DataType_BOOL_6; // idb
PStringBase<char> NodeName_73; // idb
PStringBase<char> modType_UVTranslate_6; // idb
PStringBase<char> modType_UVRotate_6; // idb
PStringBase<char> modType_UVScale_6; // idb
PStringBase<char> modType_UVTransform_6; // idb
PStringBase<char> TrueFlags_6; // idb
PStringBase<char> FalseFlags_6; // idb
PStringBase<char> RenderPass_6; // idb
PStringBase<char> Blend_6; // idb
PStringBase<char> DepthTest_6; // idb
PStringBase<char> DepthWrite_6; // idb
PStringBase<char> CullMode_6; // idb
PStringBase<char> DepthFog_6; // idb
PStringBase<char> AlphaTestMode_6; // idb
PStringBase<char> AlphaTestRef_6; // idb
PStringBase<char> FFUseLighting_6; // idb
PStringBase<char> FFUseDyeColorInTFactor_6; // idb
PStringBase<char> FFUseSpecularLighting_6; // idb
PStringBase<char> FFUseDistanceFog_6; // idb
PStringBase<char> FFUseVertexDiffuse_6; // idb
PStringBase<char> FFUseVertexSpecular_6; // idb
PStringBase<char> ShaderSupportsDynamicLights_6; // idb
PStringBase<char> UsesTransparency_6; // idb
PStringBase<char> Ambient_6; // idb
PStringBase<char> Diffuse_14; // idb
PStringBase<char> Specular_14; // idb
PStringBase<char> SpecularPower_6; // idb
PStringBase<char> Dye_6; // idb
PStringBase<char> Emissive_6; // idb
PStringBase<char> VertexFormat_6; // idb
PStringBase<char> VertexShader_6; // idb
PStringBase<char> PixelShader_6; // idb
PStringBase<char> param_MLF_NONE_6; // idb
PStringBase<char> param_MLF_REFLECTIONS_6; // idb
PStringBase<char> param_MLF_VIDEOPOST_6; // idb
PStringBase<char> param_MLF_HIGHDETAIL_6; // idb
PStringBase<char> param_MLF_SPECULAR_6; // idb
PStringBase<char> param_MLF_CLASS1_6; // idb
PStringBase<char> param_MLF_CLASS2_6; // idb
PStringBase<char> param_MLF_CLASS3_6; // idb
PStringBase<char> param_RenderPass_Default_6; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_6; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_6; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_6; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_6; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_6; // idb
PStringBase<char> param_RenderPass_DistanceFog_6; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_6; // idb
PStringBase<char> param_RenderPass_ShaderGlow_6; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_6; // idb
PStringBase<char> param_RenderPass_AlphaBlend_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_6; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_6; // idb
PStringBase<char> param_BLEND_ZERO_6; // idb
PStringBase<char> param_BLEND_ONE_6; // idb
PStringBase<char> param_BLEND_SRCCOLOR_6; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_6; // idb
PStringBase<char> param_BLEND_SRCALPHA_6; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_6; // idb
PStringBase<char> param_BLEND_DSTALPHA_6; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_6; // idb
PStringBase<char> param_BLEND_DSTCOLOR_6; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_6; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_6; // idb
PStringBase<char> param_DEPTHTEST_LESS_6; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_6; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_6; // idb
PStringBase<char> param_DEPTHTEST_GREATER_6; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_6; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_6; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_6; // idb
PStringBase<char> param_DEPTHWRITE_ON_6; // idb
PStringBase<char> param_DEPTHWRITE_OFF_6; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_6; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_6; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_6; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_6; // idb
PStringBase<char> param_CULLMODE_NONE_6; // idb
PStringBase<char> param_CULLMODE_CW_6; // idb
PStringBase<char> param_CULLMODE_CCW_6; // idb
PStringBase<char> param_LIGHTMODE_NONE_6; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_6; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_6; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_6; // idb
PStringBase<char> param_DEPTHFOG_OFF_6; // idb
PStringBase<char> param_DEPTHFOG_ON_6; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_6; // idb
PStringBase<char> param_ALPHATESTMODE_ON_6; // idb
PStringBase<char> param_VF_ORIGIN_6; // idb
PStringBase<char> param_VF_NORMAL_6; // idb
PStringBase<char> param_VF_POINTSIZE_6; // idb
PStringBase<char> param_VF_DIFFUSE_6; // idb
PStringBase<char> param_VF_SPECULAR_6; // idb
PStringBase<char> param_VF_TCPAIRx1_6; // idb
PStringBase<char> param_VF_TCPAIRx2_6; // idb
PStringBase<char> param_VF_TCPAIRx3_6; // idb
PStringBase<char> param_VF_TCPAIRx4_6; // idb
PStringBase<char> param_VF_TCPAIRx5_6; // idb
PStringBase<char> param_VF_TCPAIRx6_6; // idb
PStringBase<char> param_VF_TCPAIRx7_6; // idb
PStringBase<char> param_VF_TCPAIRx8_6; // idb
PStringBase<char> param_VF_VECTOR_S_6; // idb
PStringBase<char> param_VF_VECTOR_T_6; // idb
PStringBase<char> NodeName_74; // idb
PStringBase<char> SamplerNodeName_6; // idb
PStringBase<char> SamplerName_6; // idb
PStringBase<char> Texture_6; // idb
PStringBase<char> SpecialTexture_FrameBuffer_6; // idb
PStringBase<char> SpecialTexture_Distortion_6; // idb
PStringBase<char> SpecialTexture_Reflection_6; // idb
PStringBase<char> SpecialTexture_NormalizeCube_6; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_6; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_6; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_6; // idb
PStringBase<char> AddressMode_6; // idb
PStringBase<char> TexFilter_6; // idb
PStringBase<char> ColorOp_6; // idb
PStringBase<char> ColorArg1_6; // idb
PStringBase<char> ColorArg2_6; // idb
PStringBase<char> AlphaOp_6; // idb
PStringBase<char> AlphaArg1_6; // idb
PStringBase<char> AlphaArg2_6; // idb
PStringBase<char> TexCoord_6; // idb
PStringBase<char> UseProjection_6; // idb
PStringBase<char> param_TEXOP_SELECTARG1_6; // idb
PStringBase<char> param_TEXOP_SELECTARG2_6; // idb
PStringBase<char> param_TEXOP_MODULATE_6; // idb
PStringBase<char> param_TEXOP_MODULATE2X_6; // idb
PStringBase<char> param_TEXOP_MODULATE4X_6; // idb
PStringBase<char> param_TEXOP_ADD_6; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_6; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_6; // idb
PStringBase<char> param_TEXOP_SUBTRACT_6; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_6; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_6; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_6; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_6; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_6; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_6; // idb
PStringBase<char> param_TEXOP_PREMODULATE_6; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_6; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_6; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_6; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_6; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_6; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_6; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_6; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_6; // idb
PStringBase<char> param_TEXOP_LERP_6; // idb
PStringBase<char> param_TEXARG_DIFFUSE_6; // idb
PStringBase<char> param_TEXARG_SPECULAR_6; // idb
PStringBase<char> param_TEXARG_CURRENT_6; // idb
PStringBase<char> param_TEXARG_TEXTURE_6; // idb
PStringBase<char> param_TEXARG_TFACTOR_6; // idb
PStringBase<char> param_TEXADDRESS_WRAP_6; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_6; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_6; // idb
PStringBase<char> param_TEXADDRESS_BORDER_6; // idb
PStringBase<char> param_TEXFILTER_NONE_6; // idb
PStringBase<char> param_TEXFILTER_POINT_6; // idb
PStringBase<char> param_TEXFILTER_LINEAR_6; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_6; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_6; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_6; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_6; // idb
PStringBase<char> param_TEXCOORD_SphereMap_6; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_6; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_6; // idb
PStringBase<char> NodeName_75; // idb
PStringBase<char> ModType_Origin_6; // idb
PStringBase<char> ModType_Normal_6; // idb
PStringBase<char> ModType_Diffuse_6; // idb
PStringBase<char> ModType_UVTranslate_6; // idb
PStringBase<char> ModType_UVRotate_6; // idb
PStringBase<char> ModType_UVScale_6; // idb
PStringBase<char> ModType_UVTransform_6; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_6; // idb
PStringBase<char> Mod_UVTranslate_translate_6; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_6; // idb
PStringBase<char> Mod_UVRotate_rotate_6; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_6; // idb
PStringBase<char> Mod_UVScale_scale_6; // idb
PStringBase<char> NodeName_76; // idb
PStringBase<char> PhysicsTimeStep_6; // idb
PStringBase<char> FastForwardTime_6; // idb
PStringBase<char> StartFadeDistance_6; // idb
PStringBase<char> StopFadeDistance_6; // idb
PStringBase<char> PhysicsDuration_6; // idb
PStringBase<char> ScaleType_6; // idb
PStringBase<char> WorldSpace_6; // idb
PStringBase<char> ForceDraw_6; // idb
PStringBase<char> NumEmitters_6; // idb
PStringBase<char> Material_33; // idb
PStringBase<char> Version_6; // idb
PStringBase<char> MaxParticles_6; // idb
PStringBase<char> NodeName_77; // idb
PStringBase<char> Origin_14; // idb
PStringBase<char> Shape_6; // idb
PStringBase<char> Shape_Point_6; // idb
PStringBase<char> Shape_Line_6; // idb
PStringBase<char> Shape_Quad_6; // idb
PStringBase<char> Shape_Disc_6; // idb
PStringBase<char> Shape_Sphere_6; // idb
PStringBase<char> ParticleShape_6; // idb
PStringBase<char> ParticleShape_Triangle_6; // idb
PStringBase<char> ParticleShape_Quad_6; // idb
PStringBase<char> Streak_6; // idb
PStringBase<char> Rotation_14; // idb
PStringBase<char> WorldRotation_6; // idb
PStringBase<char> RotateVelocity_6; // idb
PStringBase<char> ParticleScale_6; // idb
PStringBase<char> Scale_21; // idb
PStringBase<char> ExplodingDir_6; // idb
PStringBase<char> BirthRate_6; // idb
PStringBase<char> Lifespan_6; // idb
PStringBase<char> Velocity_6; // idb
PStringBase<char> Direction_6; // idb
PStringBase<char> MinSpread_6; // idb
PStringBase<char> MaxSpread_6; // idb
PStringBase<char> EmissionLimit_6; // idb
PStringBase<char> BlastCount_6; // idb
PStringBase<char> StartTime_6; // idb
PStringBase<char> TimeLimit_6; // idb
PStringBase<char> EmissionDistance_6; // idb
PStringBase<char> ParticleSnap_6; // idb
PStringBase<char> InclusiveShape_6; // idb
PStringBase<char> NumKeyframes_6; // idb
PStringBase<char> IsActive_6; // idb
PStringBase<char> FadeIn_6; // idb
PStringBase<char> FadeOut_6; // idb
PStringBase<char> ConstrainX_6; // idb
PStringBase<char> ConstrainY_6; // idb
PStringBase<char> ConstrainZ_6; // idb
PStringBase<char> NodeName_78; // idb
PStringBase<char> Time_6; // idb
PStringBase<char> Flags_6; // idb
PStringBase<char> Flags_None_6; // idb
PStringBase<char> Flags_BlendScale_6; // idb
PStringBase<char> Flags_BlendColor_6; // idb
PStringBase<char> Flags_BlendMass_6; // idb
PStringBase<char> Flags_SetScale_6; // idb
PStringBase<char> Flags_SetColor_6; // idb
PStringBase<char> Flags_SetMass_6; // idb
PStringBase<char> Flags_SetPFlags_6; // idb
PStringBase<char> Flags_SetPCType_6; // idb
PStringBase<char> Flags_SetPhysFlags_6; // idb
PStringBase<char> Flags_SetParams_6; // idb
PStringBase<char> Scale_22; // idb
PStringBase<char> ScaleX_6; // idb
PStringBase<char> ScaleY_6; // idb
PStringBase<char> Color_6; // idb
PStringBase<char> Mass_6; // idb
PStringBase<char> PFlags_6; // idb
PStringBase<char> PFlags_None_6; // idb
PStringBase<char> PCType_6; // idb
PStringBase<char> PCType_None_6; // idb
PStringBase<char> PCType_Physics_6; // idb
PStringBase<char> PCType_Parametric_6; // idb
PStringBase<char> PCType_AttractRepulse_6; // idb
PStringBase<char> PCType_PointFile_6; // idb
PStringBase<char> PCType_PointFileLerp_6; // idb
PStringBase<char> PhysFlags_6; // idb
PStringBase<char> PhysFlags_None_6; // idb
PStringBase<char> PhysFlags_Gravity_6; // idb
PStringBase<char> PhysFlags_Wind_6; // idb
PStringBase<char> PhysFlags_Momentum_6; // idb
PStringBase<char> PointfileFlags_RandomPoint_6; // idb
PStringBase<char> Position_7; // idb
PStringBase<char> PointList_6; // idb
PStringBase<char> Point_14; // idb
PStringBase<char> DetailLevels_6; // idb
PStringBase<char> DetailLevel_Low_6; // idb
PStringBase<char> DetailLevel_Medium_6; // idb
PStringBase<char> DetailLevel_High_6; // idb
PStringBase<char> FadeSpeed_6; // idb
PStringBase<char> MaxOpacity_6; // idb
PStringBase<char> Point_15; // idb
PStringBase<char> PointAxisPos_6; // idb
PStringBase<char> PointTexture_6; // idb
PStringBase<char> PointSize_6; // idb
PStringBase<char> UseOcclusion_6; // idb
PStringBase<char> PHEADER_STRINGS_5[4]; // idb
PStringBase<char> stru_83C2AC; // idb
PStringBase<char> stru_83C2B0; // idb
PStringBase<char> stru_83C2B4; // idb
IDClass<_tagDataID,32,0> INVALID_DID_46; // idb
PStringBase<char> waveform_None_24; // idb
PStringBase<char> waveform_Speed_24; // idb
PStringBase<char> waveform_Noise_24; // idb
PStringBase<char> waveform_Sine_24; // idb
PStringBase<char> waveform_Square_24; // idb
PStringBase<char> waveform_Bounce_24; // idb
PStringBase<char> waveform_Perlin_24; // idb
PStringBase<char> waveform_Fractal_24; // idb
PStringBase<char> waveform_FrameLoop_24; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_27; // idb
PStringBase<char> PHeader_9; // idb
PStringBase<char> VertexArray_7; // idb
PStringBase<char> BinaryVertexArray_7; // idb
PStringBase<char> VertexType_8; // idb
PStringBase<char> VertexData_7; // idb
PStringBase<char> Vertex_7; // idb
PStringBase<char> Index_15; // idb
PStringBase<char> Origin_15; // idb
PStringBase<char> Normal_7; // idb
PStringBase<char> Diffuse_15; // idb
PStringBase<char> Specular_15; // idb
PStringBase<char> UVS_7; // idb
PStringBase<char> VectorS_7; // idb
PStringBase<char> VectorT_7; // idb
PStringBase<char> VectorSxT_7; // idb
PStringBase<char> Weights_7; // idb
PStringBase<char> Importance_7; // idb
PStringBase<char> PhysMtl_7; // idb
PStringBase<char> Material_34; // idb
PStringBase<char> ID_18; // idb
PStringBase<char> FileName_7; // idb
PStringBase<char> Polygon_15; // idb
PStringBase<char> ID_19; // idb
PStringBase<char> Indices_13; // idb
PStringBase<char> MaterialID_7; // idb
PStringBase<char> PhysMaterialID_7; // idb
PStringBase<char> Markings_7; // idb
PStringBase<char> Material_35; // idb
PStringBase<char> Index_16; // idb
PStringBase<char> Filename_7; // idb
PStringBase<char> Surface_7; // idb
PStringBase<char> CellPoly_7; // idb
PStringBase<char> Sphere_10; // idb
PStringBase<char> Side_7; // idb
PStringBase<char> Positive_7; // idb
PStringBase<char> Negative_7; // idb
PStringBase<char> Polygon_16; // idb
PStringBase<char> OtherCell_15; // idb
PStringBase<char> CellPortal_7; // idb
PStringBase<char> Portal_10; // idb
PStringBase<char> OtherCell_16; // idb
PStringBase<char> OtherPortal_7; // idb
PStringBase<char> ExactMatch_7; // idb
PStringBase<char> StabList_7; // idb
PStringBase<char> Period_7; // idb
PStringBase<char> GrannyAnimation_7; // idb
PStringBase<char> Transform_7; // idb
PStringBase<char> Scale_23; // idb
PStringBase<char> Weight_7; // idb
PStringBase<char> Offset_7; // idb
PStringBase<char> Quaternion_8; // idb
PStringBase<char> Rotation_15; // idb
PStringBase<char> STime_7; // idb
PStringBase<char> PhysicsSplines_7; // idb
PStringBase<char> BoneOpacities_7; // idb
PStringBase<char> LowPt_7; // idb
PStringBase<char> Radius_7; // idb
PStringBase<char> Height_7; // idb
PStringBase<char> Texture2D_7; // idb
PStringBase<char> Texture3D_7; // idb
PStringBase<char> TextureCube_7; // idb
PStringBase<char> TextureMovie2D_7; // idb
PStringBase<char> MovieFileName_7; // idb
PStringBase<char> MovieFramesPerSecond_7; // idb
PStringBase<char> Levels_7; // idb
PStringBase<char> NodeName_79; // idb
PStringBase<char> Material_36; // idb
PStringBase<char> MaterialType_7; // idb
PStringBase<char> Modifier_7; // idb
PStringBase<char> AllowStencilShadows_7; // idb
PStringBase<char> DiscardGeometry_7; // idb
PStringBase<char> NodeName_80; // idb
PStringBase<char> SortMode_7; // idb
PStringBase<char> SortMode_None_7; // idb
PStringBase<char> SortMode_Triangle_7; // idb
PStringBase<char> NodeName_81; // idb
PStringBase<char> NodeName_82; // idb
PStringBase<char> DataType_DATA_7; // idb
PStringBase<char> DataType_WAVEFORM_7; // idb
PStringBase<char> DataType_COLOR_7; // idb
PStringBase<char> DataType_TEXTURE_7; // idb
PStringBase<char> DataType_BOOL_7; // idb
PStringBase<char> NodeName_83; // idb
PStringBase<char> modType_UVTranslate_7; // idb
PStringBase<char> modType_UVRotate_7; // idb
PStringBase<char> modType_UVScale_7; // idb
PStringBase<char> modType_UVTransform_7; // idb
PStringBase<char> TrueFlags_7; // idb
PStringBase<char> FalseFlags_7; // idb
PStringBase<char> RenderPass_7; // idb
PStringBase<char> Blend_7; // idb
PStringBase<char> DepthTest_7; // idb
PStringBase<char> DepthWrite_7; // idb
PStringBase<char> CullMode_7; // idb
PStringBase<char> DepthFog_7; // idb
PStringBase<char> AlphaTestMode_7; // idb
PStringBase<char> AlphaTestRef_7; // idb
PStringBase<char> FFUseLighting_7; // idb
PStringBase<char> FFUseDyeColorInTFactor_7; // idb
PStringBase<char> FFUseSpecularLighting_7; // idb
PStringBase<char> FFUseDistanceFog_7; // idb
PStringBase<char> FFUseVertexDiffuse_7; // idb
PStringBase<char> FFUseVertexSpecular_7; // idb
PStringBase<char> ShaderSupportsDynamicLights_7; // idb
PStringBase<char> UsesTransparency_7; // idb
PStringBase<char> Ambient_7; // idb
PStringBase<char> Diffuse_16; // idb
PStringBase<char> Specular_16; // idb
PStringBase<char> SpecularPower_7; // idb
PStringBase<char> Dye_7; // idb
PStringBase<char> Emissive_7; // idb
PStringBase<char> VertexFormat_7; // idb
PStringBase<char> VertexShader_7; // idb
PStringBase<char> PixelShader_7; // idb
PStringBase<char> param_MLF_NONE_7; // idb
PStringBase<char> param_MLF_REFLECTIONS_7; // idb
PStringBase<char> param_MLF_VIDEOPOST_7; // idb
PStringBase<char> param_MLF_HIGHDETAIL_7; // idb
PStringBase<char> param_MLF_SPECULAR_7; // idb
PStringBase<char> param_MLF_CLASS1_7; // idb
PStringBase<char> param_MLF_CLASS2_7; // idb
PStringBase<char> param_MLF_CLASS3_7; // idb
PStringBase<char> param_RenderPass_Default_7; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_7; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_7; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_7; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_7; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_7; // idb
PStringBase<char> param_RenderPass_DistanceFog_7; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_7; // idb
PStringBase<char> param_RenderPass_ShaderGlow_7; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_7; // idb
PStringBase<char> param_RenderPass_AlphaBlend_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_7; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_7; // idb
PStringBase<char> param_BLEND_ZERO_7; // idb
PStringBase<char> param_BLEND_ONE_7; // idb
PStringBase<char> param_BLEND_SRCCOLOR_7; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_7; // idb
PStringBase<char> param_BLEND_SRCALPHA_7; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_7; // idb
PStringBase<char> param_BLEND_DSTALPHA_7; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_7; // idb
PStringBase<char> param_BLEND_DSTCOLOR_7; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_7; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_7; // idb
PStringBase<char> param_DEPTHTEST_LESS_7; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_7; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_7; // idb
PStringBase<char> param_DEPTHTEST_GREATER_7; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_7; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_7; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_7; // idb
PStringBase<char> param_DEPTHWRITE_ON_7; // idb
PStringBase<char> param_DEPTHWRITE_OFF_7; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_7; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_7; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_7; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_7; // idb
PStringBase<char> param_CULLMODE_NONE_7; // idb
PStringBase<char> param_CULLMODE_CW_7; // idb
PStringBase<char> param_CULLMODE_CCW_7; // idb
PStringBase<char> param_LIGHTMODE_NONE_7; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_7; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_7; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_7; // idb
PStringBase<char> param_DEPTHFOG_OFF_7; // idb
PStringBase<char> param_DEPTHFOG_ON_7; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_7; // idb
PStringBase<char> param_ALPHATESTMODE_ON_7; // idb
PStringBase<char> param_VF_ORIGIN_7; // idb
PStringBase<char> param_VF_NORMAL_7; // idb
PStringBase<char> param_VF_POINTSIZE_7; // idb
PStringBase<char> param_VF_DIFFUSE_7; // idb
PStringBase<char> param_VF_SPECULAR_7; // idb
PStringBase<char> param_VF_TCPAIRx1_7; // idb
PStringBase<char> param_VF_TCPAIRx2_7; // idb
PStringBase<char> param_VF_TCPAIRx3_7; // idb
PStringBase<char> param_VF_TCPAIRx4_7; // idb
PStringBase<char> param_VF_TCPAIRx5_7; // idb
PStringBase<char> param_VF_TCPAIRx6_7; // idb
PStringBase<char> param_VF_TCPAIRx7_7; // idb
PStringBase<char> param_VF_TCPAIRx8_7; // idb
PStringBase<char> param_VF_VECTOR_S_7; // idb
PStringBase<char> param_VF_VECTOR_T_7; // idb
PStringBase<char> NodeName_84; // idb
PStringBase<char> SamplerNodeName_7; // idb
PStringBase<char> SamplerName_7; // idb
PStringBase<char> Texture_7; // idb
PStringBase<char> SpecialTexture_FrameBuffer_7; // idb
PStringBase<char> SpecialTexture_Distortion_7; // idb
PStringBase<char> SpecialTexture_Reflection_7; // idb
PStringBase<char> SpecialTexture_NormalizeCube_7; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_7; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_7; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_7; // idb
PStringBase<char> AddressMode_7; // idb
PStringBase<char> TexFilter_7; // idb
PStringBase<char> ColorOp_7; // idb
PStringBase<char> ColorArg1_7; // idb
PStringBase<char> ColorArg2_7; // idb
PStringBase<char> AlphaOp_7; // idb
PStringBase<char> AlphaArg1_7; // idb
PStringBase<char> AlphaArg2_7; // idb
PStringBase<char> TexCoord_7; // idb
PStringBase<char> UseProjection_7; // idb
PStringBase<char> param_TEXOP_SELECTARG1_7; // idb
PStringBase<char> param_TEXOP_SELECTARG2_7; // idb
PStringBase<char> param_TEXOP_MODULATE_7; // idb
PStringBase<char> param_TEXOP_MODULATE2X_7; // idb
PStringBase<char> param_TEXOP_MODULATE4X_7; // idb
PStringBase<char> param_TEXOP_ADD_7; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_7; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_7; // idb
PStringBase<char> param_TEXOP_SUBTRACT_7; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_7; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_7; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_7; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_7; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_7; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_7; // idb
PStringBase<char> param_TEXOP_PREMODULATE_7; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_7; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_7; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_7; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_7; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_7; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_7; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_7; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_7; // idb
PStringBase<char> param_TEXOP_LERP_7; // idb
PStringBase<char> param_TEXARG_DIFFUSE_7; // idb
PStringBase<char> param_TEXARG_SPECULAR_7; // idb
PStringBase<char> param_TEXARG_CURRENT_7; // idb
PStringBase<char> param_TEXARG_TEXTURE_7; // idb
PStringBase<char> param_TEXARG_TFACTOR_7; // idb
PStringBase<char> param_TEXADDRESS_WRAP_7; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_7; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_7; // idb
PStringBase<char> param_TEXADDRESS_BORDER_7; // idb
PStringBase<char> param_TEXFILTER_NONE_7; // idb
PStringBase<char> param_TEXFILTER_POINT_7; // idb
PStringBase<char> param_TEXFILTER_LINEAR_7; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_7; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_7; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_7; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_7; // idb
PStringBase<char> param_TEXCOORD_SphereMap_7; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_7; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_7; // idb
PStringBase<char> NodeName_85; // idb
PStringBase<char> ModType_Origin_7; // idb
PStringBase<char> ModType_Normal_7; // idb
PStringBase<char> ModType_Diffuse_7; // idb
PStringBase<char> ModType_UVTranslate_7; // idb
PStringBase<char> ModType_UVRotate_7; // idb
PStringBase<char> ModType_UVScale_7; // idb
PStringBase<char> ModType_UVTransform_7; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_7; // idb
PStringBase<char> Mod_UVTranslate_translate_7; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_7; // idb
PStringBase<char> Mod_UVRotate_rotate_7; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_7; // idb
PStringBase<char> Mod_UVScale_scale_7; // idb
PStringBase<char> NodeName_86; // idb
PStringBase<char> PhysicsTimeStep_7; // idb
PStringBase<char> FastForwardTime_7; // idb
PStringBase<char> StartFadeDistance_7; // idb
PStringBase<char> StopFadeDistance_7; // idb
PStringBase<char> PhysicsDuration_7; // idb
PStringBase<char> ScaleType_7; // idb
PStringBase<char> WorldSpace_7; // idb
PStringBase<char> ForceDraw_7; // idb
PStringBase<char> NumEmitters_7; // idb
PStringBase<char> Material_37; // idb
PStringBase<char> Version_7; // idb
PStringBase<char> MaxParticles_7; // idb
PStringBase<char> NodeName_87; // idb
PStringBase<char> Origin_16; // idb
PStringBase<char> Shape_7; // idb
PStringBase<char> Shape_Point_7; // idb
PStringBase<char> Shape_Line_7; // idb
PStringBase<char> Shape_Quad_7; // idb
PStringBase<char> Shape_Disc_7; // idb
PStringBase<char> Shape_Sphere_7; // idb
PStringBase<char> ParticleShape_7; // idb
PStringBase<char> ParticleShape_Triangle_7; // idb
PStringBase<char> ParticleShape_Quad_7; // idb
PStringBase<char> Streak_7; // idb
PStringBase<char> Rotation_16; // idb
PStringBase<char> WorldRotation_7; // idb
PStringBase<char> RotateVelocity_7; // idb
PStringBase<char> ParticleScale_7; // idb
PStringBase<char> Scale_24; // idb
PStringBase<char> ExplodingDir_7; // idb
PStringBase<char> BirthRate_7; // idb
PStringBase<char> Lifespan_7; // idb
PStringBase<char> Velocity_7; // idb
PStringBase<char> Direction_7; // idb
PStringBase<char> MinSpread_7; // idb
PStringBase<char> MaxSpread_7; // idb
PStringBase<char> EmissionLimit_7; // idb
PStringBase<char> BlastCount_7; // idb
PStringBase<char> StartTime_7; // idb
PStringBase<char> TimeLimit_7; // idb
PStringBase<char> EmissionDistance_7; // idb
PStringBase<char> ParticleSnap_7; // idb
PStringBase<char> InclusiveShape_7; // idb
PStringBase<char> NumKeyframes_7; // idb
PStringBase<char> IsActive_7; // idb
PStringBase<char> FadeIn_7; // idb
PStringBase<char> FadeOut_7; // idb
PStringBase<char> ConstrainX_7; // idb
PStringBase<char> ConstrainY_7; // idb
PStringBase<char> ConstrainZ_7; // idb
PStringBase<char> NodeName_88; // idb
PStringBase<char> Time_7; // idb
PStringBase<char> Flags_7; // idb
PStringBase<char> Flags_None_7; // idb
PStringBase<char> Flags_BlendScale_7; // idb
PStringBase<char> Flags_BlendColor_7; // idb
PStringBase<char> Flags_BlendMass_7; // idb
PStringBase<char> Flags_SetScale_7; // idb
PStringBase<char> Flags_SetColor_7; // idb
PStringBase<char> Flags_SetMass_7; // idb
PStringBase<char> Flags_SetPFlags_7; // idb
PStringBase<char> Flags_SetPCType_7; // idb
PStringBase<char> Flags_SetPhysFlags_7; // idb
PStringBase<char> Flags_SetParams_7; // idb
PStringBase<char> Scale_25; // idb
PStringBase<char> ScaleX_7; // idb
PStringBase<char> ScaleY_7; // idb
PStringBase<char> Color_7; // idb
PStringBase<char> Mass_7; // idb
PStringBase<char> PFlags_7; // idb
PStringBase<char> PFlags_None_7; // idb
PStringBase<char> PCType_7; // idb
PStringBase<char> PCType_None_7; // idb
PStringBase<char> PCType_Physics_7; // idb
PStringBase<char> PCType_Parametric_7; // idb
PStringBase<char> PCType_AttractRepulse_7; // idb
PStringBase<char> PCType_PointFile_7; // idb
PStringBase<char> PCType_PointFileLerp_7; // idb
PStringBase<char> PhysFlags_7; // idb
PStringBase<char> PhysFlags_None_7; // idb
PStringBase<char> PhysFlags_Gravity_7; // idb
PStringBase<char> PhysFlags_Wind_7; // idb
PStringBase<char> PhysFlags_Momentum_7; // idb
PStringBase<char> PointfileFlags_RandomPoint_7; // idb
PStringBase<char> Position_8; // idb
PStringBase<char> PointList_7; // idb
PStringBase<char> Point_16; // idb
PStringBase<char> DetailLevels_7; // idb
PStringBase<char> DetailLevel_Low_7; // idb
PStringBase<char> DetailLevel_Medium_7; // idb
PStringBase<char> DetailLevel_High_7; // idb
PStringBase<char> FadeSpeed_7; // idb
PStringBase<char> MaxOpacity_7; // idb
PStringBase<char> Point_17; // idb
PStringBase<char> PointAxisPos_7; // idb
PStringBase<char> PointTexture_7; // idb
PStringBase<char> PointSize_7; // idb
PStringBase<char> UseOcclusion_7; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_28; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_29; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_30; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_31; // idb
int static_camera; // weak
unsigned __int32 SmartBox::click_object_id; // weak
bool SmartBox::lookingForObject; // weak
unsigned int SmartBox::m_cxWindowFindPos; // idb
unsigned __int32 SmartBox::m_cyWindowFindPos; // weak
SmartBox *SmartBox::smartbox; // idb
PStringBase<char> Display_Resolution_4; // idb
PStringBase<char> Display_FullScreen_4; // idb
PStringBase<char> Display_RefreshRate_4; // idb
PStringBase<char> Display_SyncToRefresh_4; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_32; // idb
const float dword_83CAD4; // idb
const float outside_val_18; // idb
const float block_length_18; // idb
const float half_square_length_18; // idb
PStringBase<char> Render_TextureFiltering_13; // idb
PStringBase<char> Render_LandscapeDetailTextures_13; // idb
PStringBase<char> Render_BuildingDetailTextures_13; // idb
PStringBase<char> Render_FieldOfView_13; // idb
PStringBase<char> Render_LandscapeTextureDetail_13; // idb
PStringBase<char> Render_EnvironmentTextureDetail_13; // idb
PStringBase<char> Render_SceneryDrawDistance_13; // idb
PStringBase<char> Render_LandscapeDrawDistance_13; // idb
PStringBase<char> Render_ScreenBrightness_13; // idb
PStringBase<char> Render_AspectRatio_13; // idb
PStringBase<char> Render_DisplayAdapter_13; // idb
PStringBase<char> Render_MaxHardwareClass_13; // idb
PStringBase<char> Render_AutomaticDegrades_13; // idb
PStringBase<char> Render_GraphicsPerformance_13; // idb
PStringBase<char> Render_DegradeDistance_13; // idb
PStringBase<char> Render_MultiPassAlpha_13; // idb
PStringBase<char> Render_TextureFiltering_Choices_13[4]; // idb
PStringBase<char> stru_83CB2C; // idb
PStringBase<char> stru_83CB30; // idb
PStringBase<char> stru_83CB34; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_13[5]; // idb
PStringBase<char> stru_83CB3C; // idb
PStringBase<char> stru_83CB40; // idb
PStringBase<char> stru_83CB44; // idb
PStringBase<char> stru_83CB48; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_13[5]; // idb
PStringBase<char> stru_83CB50; // idb
PStringBase<char> stru_83CB54; // idb
PStringBase<char> stru_83CB58; // idb
PStringBase<char> stru_83CB5C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_13[3]; // idb
PStringBase<char> stru_83CB64; // idb
PStringBase<char> stru_83CB68; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_13[6]; // idb
PStringBase<char> stru_83CB70; // idb
PStringBase<char> stru_83CB74; // idb
PStringBase<char> stru_83CB78; // idb
PStringBase<char> stru_83CB7C; // idb
PStringBase<char> stru_83CB80; // idb
PStringBase<char> Render_AspectRatio_Choices_13[3]; // idb
PStringBase<char> stru_83CB88; // idb
PStringBase<char> stru_83CB8C; // idb
PStringBase<char> waveform_None_25; // idb
PStringBase<char> waveform_Speed_25; // idb
PStringBase<char> waveform_Noise_25; // idb
PStringBase<char> waveform_Sine_25; // idb
PStringBase<char> waveform_Square_25; // idb
PStringBase<char> waveform_Bounce_25; // idb
PStringBase<char> waveform_Perlin_25; // idb
PStringBase<char> waveform_Fractal_25; // idb
PStringBase<char> waveform_FrameLoop_25; // idb
const int LOWEST_DATA_RATE_54; // idb
const int HIGHEST_DATA_RATE_54; // idb
const int INITIAL_MAX_DATA_RATE_2; // idb
const float DEFAULT_VIEW_RADIUS_5; // idb
const long double MIN_QUANTUM_5; // idb
const long double MAX_QUANTUM_5; // idb
PStringBase<char> Sound_SoundDisabled_1; // idb
PStringBase<char> Sound_SoundVolume_1; // idb
PStringBase<char> Sound_AmbientSoundDisabled_1; // idb
PStringBase<char> Sound_AmbientSoundVolume_1; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_1; // idb
PStringBase<char> Sound_InterfaceSoundVolume_1; // idb
PStringBase<char> Sound_SoundFeatures_1; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_1; // idb
PStringBase<char> Sound_SoundFeatures_Choices_1[2]; // idb
PStringBase<char> stru_83CBFC; // idb
const float VOL_MIN_DIST_SQ_0; // idb
const long double INV_LOG_OF_2_0; // idb
float SmartBox::s_fViewerLightIntensity; // weak
AC1Legacy::Vector3 viewer_sphere; // idb
int dword_83CC20; // weak
unsigned int error_count; // idb
const float outside_val_19; // idb
const float block_length_19; // idb
const float half_square_length_19; // idb
const float DEFAULT_VIEW_RADIUS_6; // idb
const long double MIN_QUANTUM_6; // idb
const long double MAX_QUANTUM_6; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_33; // idb
PStringBase<char> Sound_SoundDisabled_2; // idb
PStringBase<char> Sound_SoundVolume_2; // idb
PStringBase<char> Sound_AmbientSoundDisabled_2; // idb
PStringBase<char> Sound_AmbientSoundVolume_2; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_2; // idb
PStringBase<char> Sound_InterfaceSoundVolume_2; // idb
PStringBase<char> Sound_SoundFeatures_2; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_2; // idb
PStringBase<char> Sound_SoundFeatures_Choices_2[2]; // idb
PStringBase<char> stru_83CCC4; // idb
const float VOL_MIN_DIST_SQ_1; // idb
const long double INV_LOG_OF_2_1; // idb
PStringBase<char> Render_TextureFiltering_14; // idb
PStringBase<char> Render_LandscapeDetailTextures_14; // idb
PStringBase<char> Render_BuildingDetailTextures_14; // idb
PStringBase<char> Render_FieldOfView_14; // idb
PStringBase<char> Render_LandscapeTextureDetail_14; // idb
PStringBase<char> Render_EnvironmentTextureDetail_14; // idb
PStringBase<char> Render_SceneryDrawDistance_14; // idb
PStringBase<char> Render_LandscapeDrawDistance_14; // idb
PStringBase<char> Render_ScreenBrightness_14; // idb
PStringBase<char> Render_AspectRatio_14; // idb
PStringBase<char> Render_DisplayAdapter_14; // idb
PStringBase<char> Render_MaxHardwareClass_14; // idb
PStringBase<char> Render_AutomaticDegrades_14; // idb
PStringBase<char> Render_GraphicsPerformance_14; // idb
PStringBase<char> Render_DegradeDistance_14; // idb
PStringBase<char> Render_MultiPassAlpha_14; // idb
PStringBase<char> Render_TextureFiltering_Choices_14[4]; // idb
PStringBase<char> stru_83CD1C; // idb
PStringBase<char> stru_83CD20; // idb
PStringBase<char> stru_83CD24; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_14[5]; // idb
PStringBase<char> stru_83CD2C; // idb
PStringBase<char> stru_83CD30; // idb
PStringBase<char> stru_83CD34; // idb
PStringBase<char> stru_83CD38; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_14[5]; // idb
PStringBase<char> stru_83CD40; // idb
PStringBase<char> stru_83CD44; // idb
PStringBase<char> stru_83CD48; // idb
PStringBase<char> stru_83CD4C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_14[3]; // idb
PStringBase<char> stru_83CD54; // idb
PStringBase<char> stru_83CD58; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_14[6]; // idb
PStringBase<char> stru_83CD60; // idb
PStringBase<char> stru_83CD64; // idb
PStringBase<char> stru_83CD68; // idb
PStringBase<char> stru_83CD6C; // idb
PStringBase<char> stru_83CD70; // idb
PStringBase<char> Render_AspectRatio_Choices_14[3]; // idb
PStringBase<char> stru_83CD78; // idb
PStringBase<char> stru_83CD7C; // idb
PStringBase<char> waveform_None_26; // idb
PStringBase<char> waveform_Speed_26; // idb
PStringBase<char> waveform_Noise_26; // idb
PStringBase<char> waveform_Sine_26; // idb
PStringBase<char> waveform_Square_26; // idb
PStringBase<char> waveform_Bounce_26; // idb
PStringBase<char> waveform_Perlin_26; // idb
PStringBase<char> waveform_Fractal_26; // idb
PStringBase<char> waveform_FrameLoop_26; // idb
PStringBase<char> Display_Resolution_5; // idb
PStringBase<char> Display_FullScreen_5; // idb
PStringBase<char> Display_RefreshRate_5; // idb
PStringBase<char> Display_SyncToRefresh_5; // idb
const float dword_83CDC8; // idb
const float outside_val_20; // idb
const float block_length_20; // idb
const float half_square_length_20; // idb
const float DEFAULT_VIEW_RADIUS_7; // idb
const long double MIN_QUANTUM_7; // idb
const long double MAX_QUANTUM_7; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_34; // idb
PStringBase<char> Render_TextureFiltering_15; // idb
PStringBase<char> Render_LandscapeDetailTextures_15; // idb
PStringBase<char> Render_BuildingDetailTextures_15; // idb
PStringBase<char> Render_FieldOfView_15; // idb
PStringBase<char> Render_LandscapeTextureDetail_15; // idb
PStringBase<char> Render_EnvironmentTextureDetail_15; // idb
PStringBase<char> Render_SceneryDrawDistance_15; // idb
PStringBase<char> Render_LandscapeDrawDistance_15; // idb
PStringBase<char> Render_ScreenBrightness_15; // idb
PStringBase<char> Render_AspectRatio_15; // idb
PStringBase<char> Render_DisplayAdapter_15; // idb
PStringBase<char> Render_MaxHardwareClass_15; // idb
PStringBase<char> Render_AutomaticDegrades_15; // idb
PStringBase<char> Render_GraphicsPerformance_15; // idb
PStringBase<char> Render_DegradeDistance_15; // idb
PStringBase<char> Render_MultiPassAlpha_15; // idb
PStringBase<char> Render_TextureFiltering_Choices_15[4]; // idb
PStringBase<char> stru_83CE6C; // idb
PStringBase<char> stru_83CE70; // idb
PStringBase<char> stru_83CE74; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_15[5]; // idb
PStringBase<char> stru_83CE7C; // idb
PStringBase<char> stru_83CE80; // idb
PStringBase<char> stru_83CE84; // idb
PStringBase<char> stru_83CE88; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_15[5]; // idb
PStringBase<char> stru_83CE90; // idb
PStringBase<char> stru_83CE94; // idb
PStringBase<char> stru_83CE98; // idb
PStringBase<char> stru_83CE9C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_15[3]; // idb
PStringBase<char> stru_83CEA4; // idb
PStringBase<char> stru_83CEA8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_15[6]; // idb
PStringBase<char> stru_83CEB0; // idb
PStringBase<char> stru_83CEB4; // idb
PStringBase<char> stru_83CEB8; // idb
PStringBase<char> stru_83CEBC; // idb
PStringBase<char> stru_83CEC0; // idb
PStringBase<char> Render_AspectRatio_Choices_15[3]; // idb
PStringBase<char> stru_83CEC8; // idb
PStringBase<char> stru_83CECC; // idb
_UNKNOWN unk_83CED0; // weak
const float outside_val_21; // idb
const float block_length_21; // idb
const float half_square_length_21; // idb
const float DEFAULT_VIEW_RADIUS_8; // idb
const long double MIN_QUANTUM_8; // idb
const long double MAX_QUANTUM_8; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_35; // idb
const int LOWEST_DATA_RATE_55; // idb
const int HIGHEST_DATA_RATE_55; // idb
const int INITIAL_MAX_DATA_RATE_3; // idb
PStringBase<char> Camera_AlignToSlope_0; // idb
PStringBase<char> Camera_Stiffness_0; // idb
PStringBase<char> Camera_AdjustmentSpeed_0; // idb
PStringBase<char> waveform_None_27; // idb
PStringBase<char> waveform_Speed_27; // idb
PStringBase<char> waveform_Noise_27; // idb
PStringBase<char> waveform_Sine_27; // idb
PStringBase<char> waveform_Square_27; // idb
PStringBase<char> waveform_Bounce_27; // idb
PStringBase<char> waveform_Perlin_27; // idb
PStringBase<char> waveform_Fractal_27; // idb
PStringBase<char> waveform_FrameLoop_27; // idb
float s_LastDeltaY; // idb
float s_LastDeltaX; // idb
long double s_LastFilterRealLocalTime; // idb
float t; // idb
const float outside_val_22; // idb
const float block_length_22; // idb
const float half_square_length_22; // idb
const float DEFAULT_VIEW_RADIUS_9; // idb
const long double MIN_QUANTUM_9; // idb
const long double MAX_QUANTUM_9; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_36; // idb
PStringBase<char> Display_Resolution_6; // idb
PStringBase<char> Display_FullScreen_6; // idb
PStringBase<char> Display_RefreshRate_6; // idb
PStringBase<char> Display_SyncToRefresh_6; // idb
const int LOWEST_DATA_RATE_56; // idb
const int HIGHEST_DATA_RATE_56; // idb
const int INITIAL_MAX_DATA_RATE_4; // idb
const float angle; // idb
UIElementManager *UIElementManager::s_pInstance; // idb
PStringBase<char> Misc_TooltipEnable_2; // idb
PStringBase<char> Misc_TooltipDelay_2; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_37; // idb
const float dword_83D098; // idb
const float outside_val_23; // idb
const float block_length_23; // idb
const float half_square_length_23; // idb
IDClass<_tagDataID,32,0> INVALID_DID_52; // idb
PStringBase<char> Render_TextureFiltering_16; // idb
PStringBase<char> Render_LandscapeDetailTextures_16; // idb
PStringBase<char> Render_BuildingDetailTextures_16; // idb
PStringBase<char> Render_FieldOfView_16; // idb
PStringBase<char> Render_LandscapeTextureDetail_16; // idb
PStringBase<char> Render_EnvironmentTextureDetail_16; // idb
PStringBase<char> Render_SceneryDrawDistance_16; // idb
PStringBase<char> Render_LandscapeDrawDistance_16; // idb
PStringBase<char> Render_ScreenBrightness_16; // idb
PStringBase<char> Render_AspectRatio_16; // idb
PStringBase<char> Render_DisplayAdapter_16; // idb
PStringBase<char> Render_MaxHardwareClass_16; // idb
PStringBase<char> Render_AutomaticDegrades_16; // idb
PStringBase<char> Render_GraphicsPerformance_16; // idb
PStringBase<char> Render_DegradeDistance_16; // idb
PStringBase<char> Render_MultiPassAlpha_16; // idb
PStringBase<char> Render_TextureFiltering_Choices_16[4]; // idb
PStringBase<char> stru_83D0F0; // idb
PStringBase<char> stru_83D0F4; // idb
PStringBase<char> stru_83D0F8; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_16[5]; // idb
PStringBase<char> stru_83D100; // idb
PStringBase<char> stru_83D104; // idb
PStringBase<char> stru_83D108; // idb
PStringBase<char> stru_83D10C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_16[5]; // idb
PStringBase<char> stru_83D114; // idb
PStringBase<char> stru_83D118; // idb
PStringBase<char> stru_83D11C; // idb
PStringBase<char> stru_83D120; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_16[3]; // idb
PStringBase<char> stru_83D128; // idb
PStringBase<char> stru_83D12C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_16[6]; // idb
PStringBase<char> stru_83D134; // idb
PStringBase<char> stru_83D138; // idb
PStringBase<char> stru_83D13C; // idb
PStringBase<char> stru_83D140; // idb
PStringBase<char> stru_83D144; // idb
PStringBase<char> Render_AspectRatio_Choices_16[3]; // idb
PStringBase<char> stru_83D14C; // idb
PStringBase<char> stru_83D150; // idb
PStringBase<char> waveform_None_28; // idb
PStringBase<char> waveform_Speed_28; // idb
PStringBase<char> waveform_Noise_28; // idb
PStringBase<char> waveform_Sine_28; // idb
PStringBase<char> waveform_Square_28; // idb
PStringBase<char> waveform_Bounce_28; // idb
PStringBase<char> waveform_Perlin_28; // idb
PStringBase<char> waveform_Fractal_28; // idb
PStringBase<char> waveform_FrameLoop_28; // idb
PStringBase<char> Display_Resolution_7; // idb
PStringBase<char> Display_FullScreen_7; // idb
PStringBase<char> Display_RefreshRate_7; // idb
PStringBase<char> Display_SyncToRefresh_7; // idb
const float DEFAULT_VIEW_RADIUS_10; // idb
const long double MIN_QUANTUM_10; // idb
const long double MAX_QUANTUM_10; // idb
CTimestamp<unsigned long,0> s_tsMsgSerialNumber; // idb
unsigned int _S216_31; // idb
RGBAColor RGBAColor_Null_2; // idb
IDClass<_tagDataID,32,0> INVALID_DID_53; // idb
PStringBase<char> Display_Resolution_8; // idb
PStringBase<char> Display_FullScreen_8; // idb
PStringBase<char> Display_RefreshRate_8; // idb
PStringBase<char> Display_SyncToRefresh_8; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_38; // idb
PStringBase<char> waveform_None_29; // idb
PStringBase<char> waveform_Speed_29; // idb
PStringBase<char> waveform_Noise_29; // idb
PStringBase<char> waveform_Sine_29; // idb
PStringBase<char> waveform_Square_29; // idb
PStringBase<char> waveform_Bounce_29; // idb
PStringBase<char> waveform_Perlin_29; // idb
PStringBase<char> waveform_Fractal_29; // idb
PStringBase<char> waveform_FrameLoop_29; // idb
PStringBase<char> Misc_TooltipEnable_3; // idb
PStringBase<char> Misc_TooltipDelay_3; // idb
PStringBase<char> waveform_None_30; // idb
PStringBase<char> waveform_Speed_30; // idb
PStringBase<char> waveform_Noise_30; // idb
PStringBase<char> waveform_Sine_30; // idb
PStringBase<char> waveform_Square_30; // idb
PStringBase<char> waveform_Bounce_30; // idb
PStringBase<char> waveform_Perlin_30; // idb
PStringBase<char> waveform_Fractal_30; // idb
PStringBase<char> waveform_FrameLoop_30; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_39; // idb
IDClass<_tagDataID,32,0> INVALID_DID_54; // idb
PStringBase<char> Sound_SoundDisabled_3; // idb
PStringBase<char> Sound_SoundVolume_3; // idb
PStringBase<char> Sound_AmbientSoundDisabled_3; // idb
PStringBase<char> Sound_AmbientSoundVolume_3; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_3; // idb
PStringBase<char> Sound_InterfaceSoundVolume_3; // idb
PStringBase<char> Sound_SoundFeatures_3; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_3; // idb
PStringBase<char> Sound_SoundFeatures_Choices_3[2]; // idb
PStringBase<char> stru_83D2D4; // idb
const float dword_83D2D8; // idb
const float outside_val_24; // idb
const float block_length_24; // idb
const float half_square_length_24; // idb
const float VOL_MIN_DIST_SQ_2; // idb
const long double INV_LOG_OF_2_2; // idb
PStringBase<char> Misc_TooltipEnable_4; // idb
PStringBase<char> Misc_TooltipDelay_4; // idb
IDClass<_tagDataID,32,0> INVALID_DID_56; // idb
PStringBase<char> Display_Resolution_9; // idb
PStringBase<char> Display_FullScreen_9; // idb
PStringBase<char> Display_RefreshRate_9; // idb
PStringBase<char> Display_SyncToRefresh_9; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_40; // idb
const float dword_83D364; // idb
const float outside_val_25; // idb
const float block_length_25; // idb
const float half_square_length_25; // idb
PStringBase<char> Misc_TooltipEnable_5; // idb
PStringBase<char> Misc_TooltipDelay_5; // idb
AsyncContext INVALID_ASYNCCONTEXT_4; // idb
PStringBase<char> Misc_TooltipEnable_6; // idb
PStringBase<char> Misc_TooltipDelay_6; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_41; // idb
PStringBase<char> Misc_TooltipEnable_7; // idb
PStringBase<char> Misc_TooltipDelay_7; // idb
PStringBase<char> waveform_None_31; // idb
PStringBase<char> waveform_Speed_31; // idb
PStringBase<char> waveform_Noise_31; // idb
PStringBase<char> waveform_Sine_31; // idb
PStringBase<char> waveform_Square_31; // idb
PStringBase<char> waveform_Bounce_31; // idb
PStringBase<char> waveform_Perlin_31; // idb
PStringBase<char> waveform_Fractal_31; // idb
PStringBase<char> waveform_FrameLoop_31; // idb
unsigned __int32 UIElement_Browser::sm_cVisibleWindows; // weak
PixelFormatDesc PixelFormatDesc_A8R8G8B8_42; // idb
PStringBase<char> Display_Resolution_10; // idb
PStringBase<char> Display_FullScreen_10; // idb
PStringBase<char> Display_RefreshRate_10; // idb
PStringBase<char> Display_SyncToRefresh_10; // idb
HMODULE hModule; // idb
int dword_83D46C; // weak
HRESULT (__stdcall *pfnRedirectWindowDC)(HWND__ *, bool, IAlternateDCProvider *); // idb
const float outside_val_26; // idb
const float block_length_26; // idb
const float half_square_length_26; // idb
const float DEFAULT_VIEW_RADIUS_11; // idb
const long double MIN_QUANTUM_11; // idb
const long double MAX_QUANTUM_11; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_43; // idb
const int LOWEST_DATA_RATE_57; // idb
const int HIGHEST_DATA_RATE_57; // idb
const int INITIAL_MAX_DATA_RATE_5; // idb
PStringBase<char> Display_Resolution_11; // idb
PStringBase<char> Display_FullScreen_11; // idb
PStringBase<char> Display_RefreshRate_11; // idb
PStringBase<char> Display_SyncToRefresh_11; // idb
IDClass<_tagDataID,32,0> INVALID_DID_64; // idb
PStringBase<char> waveform_None_32; // idb
PStringBase<char> waveform_Speed_32; // idb
PStringBase<char> waveform_Noise_32; // idb
PStringBase<char> waveform_Sine_32; // idb
PStringBase<char> waveform_Square_32; // idb
PStringBase<char> waveform_Bounce_32; // idb
PStringBase<char> waveform_Perlin_32; // idb
PStringBase<char> waveform_Fractal_32; // idb
PStringBase<char> waveform_FrameLoop_32; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_44; // idb
PStringBase<char> Misc_TooltipEnable_8; // idb
PStringBase<char> Misc_TooltipDelay_8; // idb
PStringBase<char> Misc_TooltipEnable_9; // idb
PStringBase<char> Misc_TooltipDelay_9; // idb
IDClass<_tagDataID,32,0> INVALID_DID_66; // idb
PStringBase<char> Misc_TooltipEnable_10; // idb
PStringBase<char> Misc_TooltipDelay_10; // idb
PStringBase<char> Misc_TooltipEnable_11; // idb
PStringBase<char> Misc_TooltipDelay_11; // idb
PStringBase<char> Misc_TooltipEnable_12; // idb
PStringBase<char> Misc_TooltipDelay_12; // idb
PStringBase<char> Misc_TooltipEnable_13; // idb
PStringBase<char> Misc_TooltipDelay_13; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_45; // idb
PStringBase<char> Misc_TooltipEnable_14; // idb
PStringBase<char> Misc_TooltipDelay_14; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_46; // idb
PStringBase<char> waveform_None_33; // idb
PStringBase<char> waveform_Speed_33; // idb
PStringBase<char> waveform_Noise_33; // idb
PStringBase<char> waveform_Sine_33; // idb
PStringBase<char> waveform_Square_33; // idb
PStringBase<char> waveform_Bounce_33; // idb
PStringBase<char> waveform_Perlin_33; // idb
PStringBase<char> waveform_Fractal_33; // idb
PStringBase<char> waveform_FrameLoop_33; // idb
unsigned __int32 DialogFactory::s_globalContext; // weak
IDClass<_tagDataID,32,0> INVALID_DID_85; // idb
struct UIFlow *UIFlow::m_instance; // weak
const float dword_83D740; // idb
const float outside_val_27; // idb
const float block_length_27; // idb
const float half_square_length_27; // idb
const float DEFAULT_VIEW_RADIUS_12; // idb
const long double MIN_QUANTUM_12; // idb
const long double MAX_QUANTUM_12; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_47; // idb
const float outside_val_28; // idb
const float block_length_28; // idb
const float half_square_length_28; // idb
const float outside_val_29; // idb
const float block_length_29; // idb
const float half_square_length_29; // idb
PStringBase<char> Misc_TooltipEnable_15; // idb
PStringBase<char> Misc_TooltipDelay_15; // idb
const float DEFAULT_VIEW_RADIUS_13; // idb
const long double MIN_QUANTUM_13; // idb
const long double MAX_QUANTUM_13; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_48; // idb
RGBAColor RGBAColor_RadarDefault; // idb
RGBAColor RGBAColor_RadarAdmin; // idb
RGBAColor RGBAColor_RadarAdvocate; // idb
RGBAColor RGBAColor_RadarCreature; // idb
RGBAColor RGBAColor_RadarLifeStone; // idb
RGBAColor RGBAColor_RadarNPC; // idb
RGBAColor RGBAColor_RadarPlayerKiller; // idb
RGBAColor RGBAColor_RadarPortal; // idb
RGBAColor RGBAColor_RadarSentinel; // idb
RGBAColor RGBAColor_RadarVendor; // idb
RGBAColor RGBAColor_RadarFellowship; // idb
RGBAColor RGBAColor_RadarFellowshipLeader; // idb
RGBAColor RGBAColor_RadarPKLite; // idb
const int LOWEST_DATA_RATE_58; // idb
const int HIGHEST_DATA_RATE_58; // idb
const int INITIAL_MAX_DATA_RATE_6; // idb
PStringBase<char> Display_Resolution_12; // idb
PStringBase<char> Display_FullScreen_12; // idb
PStringBase<char> Display_RefreshRate_12; // idb
PStringBase<char> Display_SyncToRefresh_12; // idb
const float outside_val_30; // idb
const float block_length_30; // idb
const float half_square_length_30; // idb
const float DEFAULT_VIEW_RADIUS_14; // idb
const long double MIN_QUANTUM_14; // idb
const long double MAX_QUANTUM_14; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_49; // idb
const float outside_val_31; // idb
const float block_length_31; // idb
const float half_square_length_31; // idb
const float DEFAULT_VIEW_RADIUS_15; // idb
const long double MIN_QUANTUM_15; // idb
const long double MAX_QUANTUM_15; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_50; // idb
const float outside_val_32; // idb
const float block_length_32; // idb
const float half_square_length_32; // idb
const float DEFAULT_VIEW_RADIUS_16; // idb
const long double MIN_QUANTUM_16; // idb
const long double MAX_QUANTUM_16; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_51; // idb
const int LOWEST_DATA_RATE_59; // idb
const int HIGHEST_DATA_RATE_59; // idb
const int INITIAL_MAX_DATA_RATE_7; // idb
const float outside_val_33; // idb
const float block_length_33; // idb
const float half_square_length_33; // idb
const float DEFAULT_VIEW_RADIUS_17; // idb
const long double MIN_QUANTUM_17; // idb
const long double MAX_QUANTUM_17; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_52; // idb
const int LOWEST_DATA_RATE_60; // idb
const int HIGHEST_DATA_RATE_60; // idb
const int INITIAL_MAX_DATA_RATE_8; // idb
const float outside_val_34; // idb
const float block_length_34; // idb
const float half_square_length_34; // idb
const float DEFAULT_VIEW_RADIUS_18; // idb
const long double MIN_QUANTUM_18; // idb
const long double MAX_QUANTUM_18; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_53; // idb
const int LOWEST_DATA_RATE_61; // idb
const int HIGHEST_DATA_RATE_61; // idb
const int INITIAL_MAX_DATA_RATE_9; // idb
const float outside_val_35; // idb
const float block_length_35; // idb
const float half_square_length_35; // idb
const float DEFAULT_VIEW_RADIUS_19; // idb
const long double MIN_QUANTUM_19; // idb
const long double MAX_QUANTUM_19; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_54; // idb
const int LOWEST_DATA_RATE_62; // idb
const int HIGHEST_DATA_RATE_62; // idb
const int INITIAL_MAX_DATA_RATE_10; // idb
int cUseTimes; // idb
const float outside_val_36; // idb
const float block_length_36; // idb
const float half_square_length_36; // idb
PStringBase<char> waveform_None_34; // idb
PStringBase<char> waveform_Speed_34; // idb
PStringBase<char> waveform_Noise_34; // idb
PStringBase<char> waveform_Sine_34; // idb
PStringBase<char> waveform_Square_34; // idb
PStringBase<char> waveform_Bounce_34; // idb
PStringBase<char> waveform_Perlin_34; // idb
PStringBase<char> waveform_Fractal_34; // idb
PStringBase<char> waveform_FrameLoop_34; // idb
const float outside_val_37; // idb
const float block_length_37; // idb
const float half_square_length_37; // idb
const float outside_val_38; // idb
const float block_length_38; // idb
const float half_square_length_38; // idb
const float outside_val_39; // idb
const float block_length_39; // idb
const float half_square_length_39; // idb
const float outside_val_40; // idb
const float block_length_40; // idb
const float half_square_length_40; // idb
const float outside_val_41; // idb
const float block_length_41; // idb
const float half_square_length_41; // idb
const float outside_val_42; // idb
const float block_length_42; // idb
const float half_square_length_42; // idb
const float DEFAULT_VIEW_RADIUS_20; // idb
const long double MIN_QUANTUM_20; // idb
const long double MAX_QUANTUM_20; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_55; // idb
const int LOWEST_DATA_RATE_63; // idb
const int HIGHEST_DATA_RATE_63; // idb
const int INITIAL_MAX_DATA_RATE_11; // idb
const unsigned int ID_ActionKeyMap_Binding; // idb
const unsigned int ID_ActionKeyMap_ButtonLabel; // idb
const unsigned int ID_ActionKeyMap_MapInstructions; // idb
const unsigned int ID_ActionKeyMap_NonUserBindableBinding; // idb
const unsigned int ID_ActionKeyMap_OverwriteExistingBinding; // idb
const unsigned int ID_ActionKeyMap_OverwriteExistingBindings; // idb
const unsigned int ID_ActionKeyMap_TT_ExistingBinding; // idb
const unsigned int ID_ActionKeyMap_TT_NewBinding; // idb
const unsigned int ACTION; // idb
const unsigned int BINDINGS; // idb
const unsigned int KEY; // idb
const unsigned int LABEL; // idb
const unsigned int VALUE_3; // idb
IDClass<_tagDataID,32,0> clsID; // idb
const float outside_val_43; // idb
const float block_length_43; // idb
const float half_square_length_43; // idb
const float DEFAULT_VIEW_RADIUS_21; // idb
const long double MIN_QUANTUM_21; // idb
const long double MAX_QUANTUM_21; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_56; // idb
const int LOWEST_DATA_RATE_64; // idb
const int HIGHEST_DATA_RATE_64; // idb
const int INITIAL_MAX_DATA_RATE_12; // idb
const unsigned int ID_SpellComp_Category_Alchemical; // idb
const unsigned int ID_SpellComp_Category_Gems; // idb
const unsigned int ID_SpellComp_Category_Herbs; // idb
const unsigned int ID_SpellComp_Category_Peas; // idb
const unsigned int ID_SpellComp_Category_Scarabs; // idb
const unsigned int ID_SpellComp_Category_Talismans; // idb
const unsigned int ID_SpellComp_Category_Tapers; // idb
IDClass<_tagDataID,32,0> stru_83DF0C; // idb
const float outside_val_44; // idb
const float block_length_44; // idb
const float half_square_length_44; // idb
const float DEFAULT_VIEW_RADIUS_22; // idb
const long double MIN_QUANTUM_22; // idb
const long double MAX_QUANTUM_22; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_57; // idb
const int LOWEST_DATA_RATE_65; // idb
const int HIGHEST_DATA_RATE_65; // idb
const int INITIAL_MAX_DATA_RATE_13; // idb
PStringBase<char> Misc_TooltipEnable_16; // idb
PStringBase<char> Misc_TooltipDelay_16; // idb
const float outside_val_45; // idb
const float block_length_45; // idb
const float half_square_length_45; // idb
const float DEFAULT_VIEW_RADIUS_23; // idb
const long double MIN_QUANTUM_23; // idb
const long double MAX_QUANTUM_23; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_58; // idb
const int LOWEST_DATA_RATE_66; // idb
const int HIGHEST_DATA_RATE_66; // idb
const int INITIAL_MAX_DATA_RATE_14; // idb
PStringBase<char> Misc_TooltipEnable_17; // idb
PStringBase<char> Misc_TooltipDelay_17; // idb
const float outside_val_46; // idb
const float block_length_46; // idb
const float half_square_length_46; // idb
const float DEFAULT_VIEW_RADIUS_24; // idb
const long double MIN_QUANTUM_24; // idb
const long double MAX_QUANTUM_24; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_59; // idb
const int LOWEST_DATA_RATE_67; // idb
const int HIGHEST_DATA_RATE_67; // idb
const int INITIAL_MAX_DATA_RATE_15; // idb
PStringBase<char> Misc_TooltipEnable_18; // idb
PStringBase<char> Misc_TooltipDelay_18; // idb
const float outside_val_47; // idb
const float block_length_47; // idb
const float half_square_length_47; // idb
const float DEFAULT_VIEW_RADIUS_25; // idb
const long double MIN_QUANTUM_25; // idb
const long double MAX_QUANTUM_25; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_60; // idb
const int LOWEST_DATA_RATE_68; // idb
const int HIGHEST_DATA_RATE_68; // idb
const int INITIAL_MAX_DATA_RATE_16; // idb
PStringBase<char> Misc_TooltipEnable_19; // idb
PStringBase<char> Misc_TooltipDelay_19; // idb
const unsigned int ID_Fellowship_CloseFellowshipButtonText; // idb
const unsigned int ID_Fellowship_Error_CantDismissSelf; // idb
const unsigned int ID_Fellowship_Error_CantRecruitSelf; // idb
const unsigned int ID_Fellowship_Error_DismisseeNotInFellowship; // idb
const unsigned int ID_Fellowship_Error_PlayerAlreadyInFellowship; // idb
const unsigned int ID_Fellowship_Error_SelfAlreadyLeader; // idb
const unsigned int ID_Fellowship_FellowHealthStatus; // idb
const unsigned int ID_Fellowship_FellowManaStatus; // idb
const unsigned int ID_Fellowship_FellowName; // idb
const unsigned int ID_Fellowship_FellowshipRequest; // idb
const unsigned int ID_Fellowship_FellowStaminaStatus; // idb
const unsigned int ID_Fellowship_FellowStats; // idb
const unsigned int ID_Fellowship_OpenFellowshipButtonText; // idb
const unsigned int ID_Cur; // idb
const unsigned int ID_Experience; // idb
const unsigned int ID_Level; // idb
const unsigned int ID_Max; // idb
const unsigned int ID_Player; // idb
const unsigned int ID_Name; // idb
const float outside_val_48; // idb
const float block_length_48; // idb
const float half_square_length_48; // idb
const float DEFAULT_VIEW_RADIUS_26; // idb
const long double MIN_QUANTUM_26; // idb
const long double MAX_QUANTUM_26; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_61; // idb
const int LOWEST_DATA_RATE_69; // idb
const int HIGHEST_DATA_RATE_69; // idb
const int INITIAL_MAX_DATA_RATE_17; // idb
PStringBase<char> Misc_TooltipEnable_20; // idb
PStringBase<char> Misc_TooltipDelay_20; // idb
const unsigned int ID_Allegiance_AcceptSwearConfirmation; // idb
const unsigned int ID_Allegiance_BreakConfirmation; // idb
const unsigned int ID_Allegiance_CharacterName; // idb
const unsigned int ID_Allegiance_Followers; // idb
const unsigned int ID_Allegiance_KickConfirmation; // idb
const unsigned int ID_Allegiance_MonarchLabel; // idb
const unsigned int ID_Allegiance_PatronSlashMonarchLabel; // idb
const unsigned int ID_Allegiance_Rank; // idb
const unsigned int ID_Allegiance_RankBuffed; // idb
const unsigned int ID_Allegiance_SwearConfirmation; // idb
const unsigned int ID_Allegiance_VassalExperiencePassedUp; // idb
const unsigned int ID_Name_0; // idb
const unsigned int ID_Player_0; // idb
const unsigned int ID_Rank; // idb
const unsigned int ID_RankBuff; // idb
const unsigned int ID_Title; // idb
const unsigned int ID_Followers; // idb
const unsigned int ID_Value; // idb
const float outside_val_49; // idb
const float block_length_49; // idb
const float half_square_length_49; // idb
PStringBase<char> Misc_TooltipEnable_21; // idb
PStringBase<char> Misc_TooltipDelay_21; // idb
gmJournalUI *g_JournalPanel; // idb
const float outside_val_50; // idb
const float block_length_50; // idb
const float half_square_length_50; // idb
const float DEFAULT_VIEW_RADIUS_27; // idb
const long double MIN_QUANTUM_27; // idb
const long double MAX_QUANTUM_27; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_62; // idb
const int LOWEST_DATA_RATE_70; // idb
const int HIGHEST_DATA_RATE_70; // idb
const int INITIAL_MAX_DATA_RATE_18; // idb
PStringBase<char> Misc_TooltipEnable_22; // idb
PStringBase<char> Misc_TooltipDelay_22; // idb
PStringBase<char> waveform_None_35; // idb
PStringBase<char> waveform_Speed_35; // idb
PStringBase<char> waveform_Noise_35; // idb
PStringBase<char> waveform_Sine_35; // idb
PStringBase<char> waveform_Square_35; // idb
PStringBase<char> waveform_Bounce_35; // idb
PStringBase<char> waveform_Perlin_35; // idb
PStringBase<char> waveform_Fractal_35; // idb
PStringBase<char> waveform_FrameLoop_35; // idb
_STL::vector<PageInfo,_STL::allocator<PageInfo> > g_JournalPages; // idb
const float outside_val_51; // idb
const float block_length_51; // idb
const float half_square_length_51; // idb
const float DEFAULT_VIEW_RADIUS_28; // idb
const long double MIN_QUANTUM_28; // idb
const long double MAX_QUANTUM_28; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_63; // idb
const int LOWEST_DATA_RATE_71; // idb
const int HIGHEST_DATA_RATE_71; // idb
const int INITIAL_MAX_DATA_RATE_19; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_1; // idb
PStringBase<char> Misc_TooltipEnable_23; // idb
PStringBase<char> Misc_TooltipDelay_23; // idb
const float outside_val_52; // idb
const float block_length_52; // idb
const float half_square_length_52; // idb
const float DEFAULT_VIEW_RADIUS_29; // idb
const long double MIN_QUANTUM_29; // idb
const long double MAX_QUANTUM_29; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_64; // idb
const int LOWEST_DATA_RATE_72; // idb
const int HIGHEST_DATA_RATE_72; // idb
const int INITIAL_MAX_DATA_RATE_20; // idb
PStringBase<char> Misc_TooltipEnable_24; // idb
PStringBase<char> Misc_TooltipDelay_24; // idb
const float outside_val_53; // idb
const float block_length_53; // idb
const float half_square_length_53; // idb
const unsigned int ID_StatManagement_Header_XPToLevelMeterInfinity; // idb
const unsigned int ID_StatManagement_Footer_DefaultSkillTitle; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsLabel; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsValue; // idb
const unsigned int ID_StatManagement_Footer_ExperienceLabel; // idb
const unsigned int ID_StatManagement_Footer_ExperienceValue; // idb
const unsigned int ID_StatManagement_Footer_XPToRaiseLabel; // idb
const unsigned int ID_StatManagement_Footer_XPToRaiseValue; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsToRaiseLabel; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsToRaiseValue; // idb
const unsigned int ID_AvailableExperience; // idb
const unsigned int ID_SkillCredits; // idb
const unsigned int ID_XPToRaise; // idb
const unsigned int ID_SkillCreditsToRaise; // idb
const float outside_val_54; // idb
const float block_length_54; // idb
const float half_square_length_54; // idb
const unsigned int ID_StatManagement_Header_XPToLevelMeterInfinity_0; // idb
const unsigned int ID_StatManagement_Footer_DefaultAttributeTitle; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsLabel_0; // idb
const unsigned int ID_StatManagement_Footer_SkillCreditsValue_0; // idb
const unsigned int ID_StatManagement_Footer_ExperienceLabel_0; // idb
const unsigned int ID_StatManagement_Footer_ExperienceValue_0; // idb
const unsigned int ID_StatManagement_Footer_XPToRaiseLabel_0; // idb
const unsigned int ID_StatManagement_Footer_XPToRaiseValue_0; // idb
const unsigned int ID_AvailableExperience_0; // idb
const unsigned int ID_SkillCredits_0; // idb
const unsigned int ID_XPToRaise_0; // idb
const float outside_val_55; // idb
const float block_length_55; // idb
const float half_square_length_55; // idb
PStringBase<char> Misc_TooltipEnable_25; // idb
PStringBase<char> Misc_TooltipDelay_25; // idb
PStringBase<char> Camera_AlignToSlope_1; // idb
PStringBase<char> Camera_Stiffness_1; // idb
PStringBase<char> Camera_AdjustmentSpeed_1; // idb
PStringBase<char> Input_MouseLookSensitivity_1; // idb
PStringBase<char> Input_MouseLookSmoothingAmount_1; // idb
PStringBase<char> Input_InvertMouseLookYAxis_1; // idb
PStringBase<char> Input_UseMouseTurning_1; // idb
const float outside_val_56; // idb
const float block_length_56; // idb
const float half_square_length_56; // idb
PStringBase<char> Camera_AlignToSlope_2; // idb
PStringBase<char> Camera_Stiffness_2; // idb
PStringBase<char> Camera_AdjustmentSpeed_2; // idb
PStringBase<char> Sound_SoundDisabled_4; // idb
PStringBase<char> Sound_SoundVolume_4; // idb
PStringBase<char> Sound_AmbientSoundDisabled_4; // idb
PStringBase<char> Sound_AmbientSoundVolume_4; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_4; // idb
PStringBase<char> Sound_InterfaceSoundVolume_4; // idb
PStringBase<char> Sound_SoundFeatures_4; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_4; // idb
PStringBase<char> Sound_SoundFeatures_Choices_4[2]; // idb
PStringBase<char> stru_83E5CC; // idb
PStringBase<char> Misc_TooltipEnable_26; // idb
PStringBase<char> Misc_TooltipDelay_26; // idb
PStringBase<char> Display_Resolution_13; // idb
PStringBase<char> Display_FullScreen_13; // idb
PStringBase<char> Display_RefreshRate_13; // idb
PStringBase<char> Display_SyncToRefresh_13; // idb
PStringBase<char> Render_TextureFiltering_17; // idb
PStringBase<char> Render_LandscapeDetailTextures_17; // idb
PStringBase<char> Render_BuildingDetailTextures_17; // idb
PStringBase<char> Render_FieldOfView_17; // idb
PStringBase<char> Render_LandscapeTextureDetail_17; // idb
PStringBase<char> Render_EnvironmentTextureDetail_17; // idb
PStringBase<char> Render_SceneryDrawDistance_17; // idb
PStringBase<char> Render_LandscapeDrawDistance_17; // idb
PStringBase<char> Render_ScreenBrightness_17; // idb
PStringBase<char> Render_AspectRatio_17; // idb
PStringBase<char> Render_DisplayAdapter_17; // idb
PStringBase<char> Render_MaxHardwareClass_17; // idb
PStringBase<char> Render_AutomaticDegrades_17; // idb
PStringBase<char> Render_GraphicsPerformance_17; // idb
PStringBase<char> Render_DegradeDistance_17; // idb
PStringBase<char> Render_MultiPassAlpha_17; // idb
PStringBase<char> Render_TextureFiltering_Choices_17[4]; // idb
PStringBase<char> stru_83E62C; // idb
PStringBase<char> stru_83E630; // idb
PStringBase<char> stru_83E634; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_17[5]; // idb
PStringBase<char> stru_83E63C; // idb
PStringBase<char> stru_83E640; // idb
PStringBase<char> stru_83E644; // idb
PStringBase<char> stru_83E648; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_17[5]; // idb
PStringBase<char> stru_83E650; // idb
PStringBase<char> stru_83E654; // idb
PStringBase<char> stru_83E658; // idb
PStringBase<char> stru_83E65C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_17[3]; // idb
PStringBase<char> stru_83E664; // idb
PStringBase<char> stru_83E668; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_17[6]; // idb
PStringBase<char> stru_83E670; // idb
PStringBase<char> stru_83E674; // idb
PStringBase<char> stru_83E678; // idb
PStringBase<char> stru_83E67C; // idb
PStringBase<char> stru_83E680; // idb
PStringBase<char> Render_AspectRatio_Choices_17[3]; // idb
PStringBase<char> stru_83E688; // idb
PStringBase<char> stru_83E68C; // idb
PStringBase<char> Input_MouseLookSensitivity_2; // idb
PStringBase<char> Input_MouseLookSmoothingAmount_2; // idb
PStringBase<char> Input_InvertMouseLookYAxis_2; // idb
PStringBase<char> Input_UseMouseTurning_2; // idb
PStringBase<char> waveform_None_36; // idb
PStringBase<char> waveform_Speed_36; // idb
PStringBase<char> waveform_Noise_36; // idb
PStringBase<char> waveform_Sine_36; // idb
PStringBase<char> waveform_Square_36; // idb
PStringBase<char> waveform_Bounce_36; // idb
PStringBase<char> waveform_Perlin_36; // idb
PStringBase<char> waveform_Fractal_36; // idb
PStringBase<char> waveform_FrameLoop_36; // idb
PStringBase<char> Input_KeymapFile_0; // idb
PStringBase<char> UI_ChatFontFace_0; // idb
PStringBase<char> UI_ChatFontSize_0; // idb
PStringBase<char> UI_ChatFontFace_Choices_0[5]; // idb
PStringBase<char> stru_83E6D4; // idb
PStringBase<char> stru_83E6D8; // idb
PStringBase<char> stru_83E6DC; // idb
PStringBase<char> stru_83E6E0; // idb
PStringBase<char> UI_ChatFontSize_Choices_0[5]; // idb
PStringBase<char> stru_83E6E8; // idb
PStringBase<char> stru_83E6EC; // idb
PStringBase<char> stru_83E6F0; // idb
PStringBase<char> stru_83E6F4; // idb
const int LOWEST_DATA_RATE_73; // idb
const int HIGHEST_DATA_RATE_73; // idb
const int INITIAL_MAX_DATA_RATE_21; // idb
const float DEFAULT_VIEW_RADIUS_30; // idb
const long double MIN_QUANTUM_30; // idb
const long double MAX_QUANTUM_30; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_65; // idb
const unsigned int ID_Sound_SoundSection; // idb
const unsigned int ID_Camera_CameraSection; // idb
const unsigned int ID_Graphics_GraphicsSection; // idb
const unsigned int ID_Graphics_TextureSection; // idb
const unsigned int ID_Input_InputSection; // idb
const unsigned int ID_UI_UISection; // idb
const unsigned int ID_Graphics_Value_Dark; // idb
const unsigned int ID_Graphics_Value_Bright; // idb
const unsigned int ID_Graphics_Value_Speed; // idb
const unsigned int ID_Graphics_Value_Detail; // idb
const unsigned int ID_Graphics_Value_Close; // idb
const unsigned int ID_Graphics_Value_Far; // idb
const unsigned int ID_Graphics_Value_Narrow; // idb
const unsigned int ID_Graphics_Value_Wide; // idb
const unsigned int ID_Graphics_Value_Slow; // idb
const unsigned int ID_Graphics_Value_Fast; // idb
const unsigned int ID_Graphics_Value_Soft; // idb
const unsigned int ID_Graphics_Value_Hard; // idb
const float outside_val_57; // idb
const float block_length_57; // idb
const float half_square_length_57; // idb
const float DEFAULT_VIEW_RADIUS_31; // idb
const long double MIN_QUANTUM_31; // idb
const long double MAX_QUANTUM_31; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_66; // idb
const unsigned int ID_ChatOption_GeneralOptions_Section; // idb
const unsigned int ID_ChatOption_MainChatWindow_Section; // idb
const unsigned int ID_ChatOption_FloatyChatWindow1_Section; // idb
const unsigned int ID_ChatOption_FloatyChatWindow2_Section; // idb
const unsigned int ID_ChatOption_FloatyChatWindow3_Section; // idb
const unsigned int ID_ChatOption_FloatyChatWindow4_Section; // idb
const unsigned int ID_UI_Value_Transparent; // idb
const unsigned int ID_UI_Value_Opaque; // idb
const unsigned int ID_ChatOption_TextFilter_Combat; // idb
const unsigned int ID_ChatOption_TextFilter_Combat_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_AreaSpeech; // idb
const unsigned int ID_ChatOption_TextFilter_AreaSpeech_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Gameplay; // idb
const unsigned int ID_ChatOption_TextFilter_Gameplay_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Magic; // idb
const unsigned int ID_ChatOption_TextFilter_Magic_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Tells; // idb
const unsigned int ID_ChatOption_TextFilter_Tells_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Allegience; // idb
const unsigned int ID_ChatOption_TextFilter_Allegience_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Fellowship; // idb
const unsigned int ID_ChatOption_TextFilter_Fellowship_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_General; // idb
const unsigned int ID_ChatOption_TextFilter_General_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Trade; // idb
const unsigned int ID_ChatOption_TextFilter_Trade_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_LFG; // idb
const unsigned int ID_ChatOption_TextFilter_LFG_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Roleplay; // idb
const unsigned int ID_ChatOption_TextFilter_Roleplay_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Society; // idb
const unsigned int ID_ChatOption_TextFilter_Society_Desc; // idb
const unsigned int ID_ChatOption_TextFilter_Error; // idb
const unsigned int ID_ChatOption_TextFilter_Error_Desc; // idb
unsigned int ID_PlayerOption_HearSocietyChat_Help; // idb
unsigned int ID_PlayerOption_HearSocietyChat; // idb
unsigned int _S121_37; // idb
unsigned int ID_PlayerOption_HearRoleplayChat_Help; // idb
unsigned int ID_PlayerOption_HearRoleplayChat; // idb
unsigned int ID_PlayerOption_HearLFGChat_Help; // idb
unsigned int ID_PlayerOption_HearLFGChat; // idb
unsigned int ID_PlayerOption_HearTradeChat_Help; // idb
unsigned int ID_PlayerOption_HearTradeChat; // idb
unsigned int ID_PlayerOption_HearGeneralChat_Help; // idb
unsigned int ID_PlayerOption_HearGeneralChat; // idb
unsigned int ID_PlayerOption_HearAllegianceChat_Help; // idb
unsigned int ID_PlayerOption_HearAllegianceChat; // idb
unsigned int ID_PlayerOption_StayInChatMode_Help; // idb
unsigned int ID_PlayerOption_StayInChatMode; // idb
unsigned int ID_PlayerOption_UseFastMissiles_Help; // idb
unsigned int ID_PlayerOption_UseFastMissiles; // idb
unsigned int ID_PlayerOption_LeadMissileTargets_Help; // idb
unsigned int ID_PlayerOption_LeadMissileTargets; // idb
unsigned int ID_PlayerOption_UseChargeAttack_Help; // idb
unsigned int ID_PlayerOption_UseChargeAttack; // idb
unsigned int ID_PlayerOption_AutoRepeatAttack_Help; // idb
unsigned int ID_PlayerOption_AutoRepeatAttack; // idb
unsigned int ID_PlayerOption_AutoTarget_Help; // idb
unsigned int ID_PlayerOption_AutoTarget; // idb
unsigned int ID_PlayerOption_AdvancedCombatUI_Help; // idb
unsigned int ID_PlayerOption_AdvancedCombatUI; // idb
unsigned int ID_PlayerOption_ToggleRun_Help; // idb
unsigned int ID_PlayerOption_ToggleRun; // idb
unsigned int ID_PlayerOption_DisplayNumberCharacterTitles_Help; // idb
unsigned int ID_PlayerOption_DisplayNumberCharacterTitles; // idb
unsigned int ID_PlayerOption_DisplayNumberDeaths_Help; // idb
unsigned int ID_PlayerOption_DisplayNumberDeaths; // idb
unsigned int ID_PlayerOption_DisplayFishingSkill_Help; // idb
unsigned int ID_PlayerOption_DisplayFishingSkill; // idb
unsigned int dword_83E924; // idb
unsigned int ID_PlayerOption_DisplayChessRank_Help; // idb
unsigned int ID_PlayerOption_DisplayChessRank; // idb
unsigned int ID_PlayerOption_DisplayAge_Help; // idb
unsigned int ID_PlayerOption_DisplayAge; // idb
unsigned int ID_PlayerOption_DisplayDateOfBirth_Help; // idb
unsigned int ID_PlayerOption_DisplayDateOfBirth; // idb
unsigned int ID_PlayerOption_DragItemOnPlayerOpensSecureTrade_Help; // idb
unsigned int ID_PlayerOption_DragItemOnPlayerOpensSecureTrade; // idb
unsigned int ID_PlayerOption_IgnoreTradeRequests_Help; // idb
unsigned int ID_PlayerOption_IgnoreTradeRequests; // idb
unsigned int ID_PlayerOption_AllowGive_Help; // idb
unsigned int ID_PlayerOption_AllowGive; // idb
unsigned int ID_PlayerOption_UseDeception_Help; // idb
unsigned int ID_PlayerOption_UseDeception; // idb
unsigned int ID_PlayerOption_AcceptLootPermits_Help; // idb
unsigned int ID_PlayerOption_AcceptLootPermits; // idb
unsigned int ID_PlayerOption_FellowshipAutoAcceptRequests_Help; // idb
unsigned int ID_PlayerOption_FellowshipAutoAcceptRequests; // idb
unsigned int ID_PlayerOption_FellowshipShareLoot_Help; // idb
unsigned int ID_PlayerOption_FellowshipShareLoot; // idb
unsigned int ID_PlayerOption_FellowshipShareXP_Help; // idb
unsigned int ID_PlayerOption_FellowshipShareXP; // idb
unsigned int ID_PlayerOption_DisplayAllegianceLogonNotifications_Help; // idb
unsigned int ID_PlayerOption_DisplayAllegianceLogonNotifications; // idb
unsigned int ID_PlayerOption_IgnoreFellowshipRequests_Help; // idb
unsigned int ID_PlayerOption_IgnoreFellowshipRequests; // idb
unsigned int ID_PlayerOption_IgnoreAllegianceRequests_Help; // idb
unsigned int ID_PlayerOption_IgnoreAllegianceRequests; // idb
unsigned int ID_PlayerOption_ShowCloak_Help; // idb
unsigned int ID_PlayerOption_ShowCloak; // idb
unsigned int ID_PlayerOption_ShowHelm_Help; // idb
unsigned int ID_PlayerOption_ShowHelm; // idb
unsigned int dword_83E9A8; // idb
unsigned int ID_PlayerOption_FilterLanguage_Help; // idb
unsigned int ID_PlayerOption_FilterLanguage; // idb
unsigned int ID_PlayerOption_DisplayTimeStamps_Help; // idb
unsigned int ID_PlayerOption_DisplayTimeStamps; // idb
unsigned int ID_PlayerOption_ConfirmVolatileRareUse_Help; // idb
unsigned int ID_PlayerOption_ConfirmVolatileRareUse; // idb
unsigned int ID_PlayerOption_UseCraftSuccessDialog_Help; // idb
unsigned int ID_PlayerOption_UseCraftSuccessDialog; // idb
unsigned int ID_PlayerOption_DisableHouseRestrictionEffects_Help; // idb
unsigned int ID_PlayerOption_DisableHouseRestrictionEffects; // idb
unsigned int ID_PlayerOption_PersistentAtDay_Help; // idb
unsigned int ID_PlayerOption_PersistentAtDay; // idb
unsigned int ID_PlayerOption_DisableDistanceFog_Help; // idb
unsigned int ID_PlayerOption_DisableDistanceFog; // idb
unsigned int ID_PlayerOption_DisableMostWeatherEffects_Help; // idb
unsigned int ID_PlayerOption_DisableMostWeatherEffects; // idb
unsigned int ID_PlayerOption_SpellDuration_Help; // idb
unsigned int ID_PlayerOption_SpellDuration; // idb
unsigned int ID_PlayerOption_SideBySideVitals_Help; // idb
unsigned int ID_PlayerOption_SideBySideVitals; // idb
unsigned int ID_PlayerOption_CoordinatesOnRadar_Help; // idb
unsigned int ID_PlayerOption_CoordinatesOnRadar; // idb
unsigned int ID_PlayerOption_ShowTooltips_Help; // idb
unsigned int ID_PlayerOption_ShowTooltips; // idb
unsigned int ID_PlayerOption_VividTargetingIndicator_Help; // idb
unsigned int ID_PlayerOption_VividTargetingIndicator; // idb
unsigned int ID_PlayerOption_MainPackPreferred_Help; // idb
unsigned int ID_PlayerOption_MainPackPreferred; // idb
unsigned int ID_PlayerOption_SalvageMultiple_Help; // idb
unsigned int ID_PlayerOption_SalvageMultiple; // idb
unsigned int ID_PlayerOption_ViewCombatTarget_Help; // idb
unsigned int ID_PlayerOption_ViewCombatTarget; // idb
unsigned int _S118_53; // idb
const float outside_val_58; // idb
const float block_length_58; // idb
const float half_square_length_58; // idb
const unsigned int ID_CharacterOption_UIBehavior_Section; // idb
const unsigned int ID_CharacterOption_UIDisplay_Section; // idb
const unsigned int ID_CharacterOption_Grouping_Section; // idb
const unsigned int ID_CharacterOption_OtherPlayers_Section; // idb
const unsigned int ID_CharacterOption_CharacterBehavior_Section; // idb
const unsigned int ID_CharacterOption_Chat_Section; // idb
IDClass<_tagDataID,32,0> stru_83EA94; // idb
const float outside_val_59; // idb
const float block_length_59; // idb
const float half_square_length_59; // idb
PStringBase<char> Misc_TooltipEnable_27; // idb
PStringBase<char> Misc_TooltipDelay_27; // idb
const float DEFAULT_VIEW_RADIUS_32; // idb
const long double MIN_QUANTUM_32; // idb
const long double MAX_QUANTUM_32; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_67; // idb
IDClass<_tagDataID,32,0> stru_83EB14; // idb
const float outside_val_60; // idb
const float block_length_60; // idb
const float half_square_length_60; // idb
const float DEFAULT_VIEW_RADIUS_33; // idb
const long double MIN_QUANTUM_33; // idb
const long double MAX_QUANTUM_33; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_68; // idb
const int LOWEST_DATA_RATE_74; // idb
const int HIGHEST_DATA_RATE_74; // idb
const int INITIAL_MAX_DATA_RATE_22; // idb
const float outside_val_61; // idb
const float block_length_61; // idb
const float half_square_length_61; // idb
const float DEFAULT_VIEW_RADIUS_34; // idb
const long double MIN_QUANTUM_34; // idb
const long double MAX_QUANTUM_34; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_69; // idb
const int LOWEST_DATA_RATE_75; // idb
const int HIGHEST_DATA_RATE_75; // idb
const int INITIAL_MAX_DATA_RATE_23; // idb
PStringBase<char> Misc_TooltipEnable_28; // idb
PStringBase<char> Misc_TooltipDelay_28; // idb
const float outside_val_62; // idb
const float block_length_62; // idb
const float half_square_length_62; // idb
const float DEFAULT_VIEW_RADIUS_35; // idb
const long double MIN_QUANTUM_35; // idb
const long double MAX_QUANTUM_35; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_70; // idb
const float outside_val_63; // idb
const float block_length_63; // idb
const float half_square_length_63; // idb
const float DEFAULT_VIEW_RADIUS_36; // idb
const long double MIN_QUANTUM_36; // idb
const long double MAX_QUANTUM_36; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_71; // idb
PStringBase<char> Misc_TooltipEnable_29; // idb
PStringBase<char> Misc_TooltipDelay_29; // idb
const float outside_val_64; // idb
const float block_length_64; // idb
const float half_square_length_64; // idb
const float DEFAULT_VIEW_RADIUS_37; // idb
const long double MIN_QUANTUM_37; // idb
const long double MAX_QUANTUM_37; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_72; // idb
PStringBase<char> Misc_TooltipEnable_30; // idb
PStringBase<char> Misc_TooltipDelay_30; // idb
const float outside_val_65; // idb
const float block_length_65; // idb
const float half_square_length_65; // idb
const unsigned int ID_Vitae_Text_Vitae; // idb
const unsigned int ID_Vitae_Text_Skills; // idb
const unsigned int ID_Vitae_Text_Experience; // idb
const unsigned int ID_Vitae_Text_Full; // idb
const unsigned int ID_Percentage; // idb
const unsigned int ID_Experience_0; // idb
const float outside_val_66; // idb
const float block_length_66; // idb
const float half_square_length_66; // idb
const float DEFAULT_VIEW_RADIUS_38; // idb
const long double MIN_QUANTUM_38; // idb
const long double MAX_QUANTUM_38; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_73; // idb
const int LOWEST_DATA_RATE_76; // idb
const int HIGHEST_DATA_RATE_76; // idb
const int INITIAL_MAX_DATA_RATE_24; // idb
IDClass<_tagDataID,32,0> stru_83EE74; // idb
const float outside_val_67; // idb
const float block_length_67; // idb
const float half_square_length_67; // idb
const float DEFAULT_VIEW_RADIUS_39; // idb
const long double MIN_QUANTUM_39; // idb
const long double MAX_QUANTUM_39; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_74; // idb
const int LOWEST_DATA_RATE_77; // idb
const int HIGHEST_DATA_RATE_77; // idb
const int INITIAL_MAX_DATA_RATE_25; // idb
const float outside_val_68; // idb
const float block_length_68; // idb
const float half_square_length_68; // idb
const int LOWEST_DATA_RATE_78; // idb
const int HIGHEST_DATA_RATE_78; // idb
const int INITIAL_MAX_DATA_RATE_26; // idb
const float DEFAULT_VIEW_RADIUS_40; // idb
const long double MIN_QUANTUM_40; // idb
const long double MAX_QUANTUM_40; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_75; // idb
const unsigned int ID_LinkStatus_Colors; // idb
const unsigned int ID_LinkStatus_Disconnect; // idb
const unsigned int ID_LinkStatus_Info; // idb
const unsigned int ID_LinkStatus_PacketLoss; // idb
const unsigned int ID_LinkStatus_Ping; // idb
const unsigned int ID_PacketLoss; // idb
const unsigned int ID_Ping; // idb
char g_szPecentText[260]; // idb
AC1Legacy::Vector3 Legacy_Vector3_ZeroVector___85; // idb
IDClass<_tagDataID,32,0> i_iconID; // idb
const float outside_val_69; // idb
const float block_length_69; // idb
const float half_square_length_69; // idb
const float DEFAULT_VIEW_RADIUS_41; // idb
const long double MIN_QUANTUM_41; // idb
const long double MAX_QUANTUM_41; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_76; // idb
const int LOWEST_DATA_RATE_79; // idb
const int HIGHEST_DATA_RATE_79; // idb
const int INITIAL_MAX_DATA_RATE_27; // idb
const unsigned int ID_Examine_Item_AugmentationCost; // idb
const unsigned int ID_AugmentationCost; // idb
SmartArray<BSPNODE *,1> BasicCreatureExamineUI::m_rgTokens; // idb
void *BasicCreatureExamineUI::m_floatyRgTokens; // idb
int dword_83F124; // weak
const float outside_val_70; // idb
const float block_length_70; // idb
const float half_square_length_70; // idb
const float DEFAULT_VIEW_RADIUS_42; // idb
const long double MIN_QUANTUM_42; // idb
const long double MAX_QUANTUM_42; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_77; // idb
const unsigned int ID_Effects_Title_Positive; // idb
const unsigned int ID_Effects_Title_Negative; // idb
const unsigned int ID_Effects_Info_NoSpells; // idb
const unsigned int ID_Effects_Info_SelectASpell; // idb
const float outside_val_71; // idb
const float block_length_71; // idb
const float half_square_length_71; // idb
const unsigned int ID_CharacterInfo_Birth; // idb
const unsigned int ID_CharacterInfo_Played; // idb
const unsigned int ID_CharacterInfo_Deaths_None; // idb
const unsigned int ID_CharacterInfo_Deaths_One; // idb
const unsigned int ID_CharacterInfo_Deaths_Two; // idb
const unsigned int ID_CharacterInfo_Deaths_Many; // idb
const unsigned int ID_CharacterInfo_Resists; // idb
const unsigned int ID_CharacterInfo_Innates; // idb
const unsigned int ID_CharacterInfo_Chess; // idb
const unsigned int ID_CharacterInfo_Fishing; // idb
const unsigned int ID_CharacterInfo_Load_None; // idb
const unsigned int ID_CharacterInfo_Load_Burdened; // idb
const unsigned int ID_CharacterInfo_Load_Augmentations; // idb
const unsigned int ID_BirthDate; // idb
const unsigned int ID_TimePlayed; // idb
const unsigned int ID_NumberOfDeaths; // idb
const unsigned int ID_Resists; // idb
const unsigned int ID_RegenerationBonus; // idb
const unsigned int ID_Strength; // idb
const unsigned int ID_Endurance; // idb
const unsigned int ID_Coordination; // idb
const unsigned int ID_Quickness; // idb
const unsigned int ID_Focus; // idb
const unsigned int ID_Self; // idb
const unsigned int ID_NumAugmentations; // idb
const unsigned int ID_ChessRank; // idb
const unsigned int ID_FishingSkill; // idb
const unsigned int ID_Burden; // idb
const unsigned int ID_BurdenPenalty; // idb
const unsigned int ID_AdditionalLoad; // idb
const unsigned int ID_CharacterInfo_Mastery_Melee; // idb
const unsigned int ID_CharacterInfo_Mastery_Ranged; // idb
const unsigned int ID_CharacterInfo_Mastery_Summoning; // idb
const unsigned int ID_Mastery; // idb
const float outside_val_72; // idb
const float block_length_72; // idb
const float half_square_length_72; // idb
const int LOWEST_DATA_RATE_80; // idb
const int HIGHEST_DATA_RATE_80; // idb
const int INITIAL_MAX_DATA_RATE_28; // idb
const float DEFAULT_VIEW_RADIUS_43; // idb
const long double MIN_QUANTUM_43; // idb
const long double MAX_QUANTUM_43; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_78; // idb
const float outside_val_73; // idb
const float block_length_73; // idb
const float half_square_length_73; // idb
const float DEFAULT_VIEW_RADIUS_44; // idb
const long double MIN_QUANTUM_44; // idb
const long double MAX_QUANTUM_44; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_79; // idb
const int LOWEST_DATA_RATE_81; // idb
const int HIGHEST_DATA_RATE_81; // idb
const int INITIAL_MAX_DATA_RATE_29; // idb
const unsigned int ID_Abuse_PageThree_WaitText; // idb
const unsigned int ID_Abuse_Response_NoSuchCharacter; // idb
const unsigned int ID_Abuse_Response_Self; // idb
const unsigned int ID_Abuse_Response_Success; // idb
const float outside_val_74; // idb
const float block_length_74; // idb
const float half_square_length_74; // idb
const int LOWEST_DATA_RATE_82; // idb
const int HIGHEST_DATA_RATE_82; // idb
const int INITIAL_MAX_DATA_RATE_30; // idb
const float DEFAULT_VIEW_RADIUS_45; // idb
const long double MIN_QUANTUM_45; // idb
const long double MAX_QUANTUM_45; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_80; // idb
IDClass<_tagDataID,32,0> WClassIDHelper::IsCoinstack::_2::didCoinstack; // idb
int WClassIDHelper::IsCoinstack::_2::local_static_guard; // weak
const float outside_val_75; // idb
const float block_length_75; // idb
const float half_square_length_75; // idb
const float DEFAULT_VIEW_RADIUS_46; // idb
const long double MIN_QUANTUM_46; // idb
const long double MAX_QUANTUM_46; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_81; // idb
const int LOWEST_DATA_RATE_83; // idb
const int HIGHEST_DATA_RATE_83; // idb
const int INITIAL_MAX_DATA_RATE_31; // idb
PStringBase<char> Misc_TooltipEnable_31; // idb
PStringBase<char> Misc_TooltipDelay_31; // idb
const unsigned int ID_Toolbar_TT_Show; // idb
const unsigned int ID_Toolbar_TT_Hide; // idb
const unsigned int token_value; // idb
const float outside_val_76; // idb
const float block_length_76; // idb
const float half_square_length_76; // idb
const float outside_val_77; // idb
const float block_length_77; // idb
const float half_square_length_77; // idb
const unsigned int ID_Vitals_VitalBarLabel; // idb
const unsigned int ID_Cur_0; // idb
const unsigned int ID_Max_0; // idb
unsigned int gmVendorUI::m_curDialogContext; // idb
IDClass<_tagDataID,32,0> stru_83F540; // idb
const float outside_val_78; // idb
const float block_length_78; // idb
const float half_square_length_78; // idb
const float DEFAULT_VIEW_RADIUS_47; // idb
const long double MIN_QUANTUM_47; // idb
const long double MAX_QUANTUM_47; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_82; // idb
const int LOWEST_DATA_RATE_84; // idb
const int HIGHEST_DATA_RATE_84; // idb
const int INITIAL_MAX_DATA_RATE_32; // idb
PStringBase<char> Misc_TooltipEnable_32; // idb
PStringBase<char> Misc_TooltipDelay_32; // idb
const float outside_val_79; // idb
const float block_length_79; // idb
const float half_square_length_79; // idb
const float DEFAULT_VIEW_RADIUS_48; // idb
const long double MIN_QUANTUM_48; // idb
const long double MAX_QUANTUM_48; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_83; // idb
const int LOWEST_DATA_RATE_85; // idb
const int HIGHEST_DATA_RATE_85; // idb
const int INITIAL_MAX_DATA_RATE_33; // idb
PStringBase<char> Misc_TooltipEnable_33; // idb
PStringBase<char> Misc_TooltipDelay_33; // idb
const float outside_val_80; // idb
const float block_length_80; // idb
const float half_square_length_80; // idb
const float DEFAULT_VIEW_RADIUS_49; // idb
const long double MIN_QUANTUM_49; // idb
const long double MAX_QUANTUM_49; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_84; // idb
const int LOWEST_DATA_RATE_86; // idb
const int HIGHEST_DATA_RATE_86; // idb
const int INITIAL_MAX_DATA_RATE_34; // idb
IDClass<_tagDataID,32,0> stru_83F6EC; // idb
const float outside_val_81; // idb
const float block_length_81; // idb
const float half_square_length_81; // idb
const float DEFAULT_VIEW_RADIUS_50; // idb
const long double MIN_QUANTUM_50; // idb
const long double MAX_QUANTUM_50; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_85; // idb
const int LOWEST_DATA_RATE_87; // idb
const int HIGHEST_DATA_RATE_87; // idb
const int INITIAL_MAX_DATA_RATE_35; // idb
const unsigned int ID_SecureTrade_TotalItemsLabel; // idb
const unsigned int ID_Items; // idb
const float outside_val_82; // idb
const float block_length_82; // idb
const float half_square_length_82; // idb
const float DEFAULT_VIEW_RADIUS_51; // idb
const long double MIN_QUANTUM_51; // idb
const long double MAX_QUANTUM_51; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_86; // idb
const int LOWEST_DATA_RATE_88; // idb
const int HIGHEST_DATA_RATE_88; // idb
const int INITIAL_MAX_DATA_RATE_36; // idb
const float outside_val_83; // idb
const float block_length_83; // idb
const float half_square_length_83; // idb
const float DEFAULT_VIEW_RADIUS_52; // idb
const long double MIN_QUANTUM_52; // idb
const long double MAX_QUANTUM_52; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_87; // idb
const int LOWEST_DATA_RATE_89; // idb
const int HIGHEST_DATA_RATE_89; // idb
const int INITIAL_MAX_DATA_RATE_37; // idb
const float outside_val_84; // idb
const float block_length_84; // idb
const float half_square_length_84; // idb
const float DEFAULT_VIEW_RADIUS_53; // idb
const long double MIN_QUANTUM_53; // idb
const long double MAX_QUANTUM_53; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_88; // idb
const int LOWEST_DATA_RATE_90; // idb
const int HIGHEST_DATA_RATE_90; // idb
const int INITIAL_MAX_DATA_RATE_38; // idb
const float outside_val_85; // idb
const float block_length_85; // idb
const float half_square_length_85; // idb
const float DEFAULT_VIEW_RADIUS_54; // idb
const long double MIN_QUANTUM_54; // idb
const long double MAX_QUANTUM_54; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_89; // idb
const int LOWEST_DATA_RATE_91; // idb
const int HIGHEST_DATA_RATE_91; // idb
const int INITIAL_MAX_DATA_RATE_39; // idb
const float outside_val_86; // idb
const float block_length_86; // idb
const float half_square_length_86; // idb
const float DEFAULT_VIEW_RADIUS_55; // idb
const long double MIN_QUANTUM_55; // idb
const long double MAX_QUANTUM_55; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_90; // idb
const int LOWEST_DATA_RATE_92; // idb
const int HIGHEST_DATA_RATE_92; // idb
const int INITIAL_MAX_DATA_RATE_40; // idb
long double nextCheckChatSelectedTime; // idb
const float outside_val_87; // idb
const float block_length_87; // idb
const float half_square_length_87; // idb
const float DEFAULT_VIEW_RADIUS_56; // idb
const long double MIN_QUANTUM_56; // idb
const long double MAX_QUANTUM_56; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_91; // idb
PStringBase<char> Misc_TooltipEnable_34; // idb
PStringBase<char> Misc_TooltipDelay_34; // idb
const int LOWEST_DATA_RATE_93; // idb
const int HIGHEST_DATA_RATE_93; // idb
const int INITIAL_MAX_DATA_RATE_41; // idb
PStringBase<char> Input_KeymapFile_1; // idb
PStringBase<char> UI_ChatFontFace_1; // idb
PStringBase<char> UI_ChatFontSize_1; // idb
PStringBase<char> UI_ChatFontFace_Choices_1[5]; // idb
PStringBase<char> stru_83FAAC; // idb
PStringBase<char> stru_83FAB0; // idb
PStringBase<char> stru_83FAB4; // idb
PStringBase<char> stru_83FAB8; // idb
PStringBase<char> UI_ChatFontSize_Choices_1[5]; // idb
PStringBase<char> stru_83FAC0; // idb
PStringBase<char> stru_83FAC4; // idb
PStringBase<char> stru_83FAC8; // idb
PStringBase<char> stru_83FACC; // idb
const unsigned int ID_CmdPrefix; // idb
const unsigned int ID_AliasPrefix; // idb
const unsigned int ID_AssistedTell; // idb
const unsigned int ID_Chat_ChatTargetMenu; // idb
const unsigned int ID_Chat_ChatTargetMenuAllegiance; // idb
const unsigned int ID_Chat_ChatTargetMenuFellows; // idb
const unsigned int ID_Chat_ChatTargetMenuMonarch; // idb
const unsigned int ID_Chat_ChatTargetMenuPatron; // idb
const unsigned int ID_Chat_ChatTargetMenuSelected; // idb
const unsigned int ID_Chat_ChatTargetMenuVassals; // idb
const unsigned int ID_Chat_SquelchSelected; // idb
const unsigned int ID_Chat_SquelchSelectedNoSelection; // idb
const unsigned int ID_Chat_TellToAll; // idb
const unsigned int ID_Chat_TellToAllegiance; // idb
const unsigned int ID_Chat_TellToFellows; // idb
const unsigned int ID_Chat_TellToMonarch; // idb
const unsigned int ID_Chat_TellToPatron; // idb
const unsigned int ID_Chat_TellToSelected; // idb
const unsigned int ID_Chat_TellToSelectedNoSelection; // idb
const unsigned int ID_Chat_TellToVassals; // idb
const unsigned int ID_Chat_ChatTargetMenuGeneral; // idb
const unsigned int ID_Chat_ChatTargetMenuTrade; // idb
const unsigned int ID_Chat_ChatTargetMenuLFG; // idb
const unsigned int ID_Chat_ChatTargetMenuRoleplay; // idb
const unsigned int ID_Chat_ChatTargetMenuSociety; // idb
const unsigned int ID_Chat_ChatTargetMenuOlthoi; // idb
const unsigned int ID_Chat_TellToGeneral; // idb
const unsigned int ID_Chat_TellToTrade; // idb
const unsigned int ID_Chat_TellToLFG; // idb
const unsigned int ID_Chat_TellToRoleplay; // idb
const unsigned int ID_Chat_TellToSociety; // idb
const unsigned int ID_Chat_TellToOlthoi; // idb
const unsigned int PREFIX; // idb
const unsigned int TARGET; // idb
const unsigned int VALUE_4; // idb
const float outside_val_88; // idb
const float block_length_88; // idb
const float half_square_length_88; // idb
const float DEFAULT_VIEW_RADIUS_57; // idb
const long double MIN_QUANTUM_57; // idb
const long double MAX_QUANTUM_57; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_92; // idb
const float outside_val_89; // idb
const float block_length_89; // idb
const float half_square_length_89; // idb
const float DEFAULT_VIEW_RADIUS_58; // idb
const long double MIN_QUANTUM_58; // idb
const long double MAX_QUANTUM_58; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_93; // idb
const float outside_val_90; // idb
const float block_length_90; // idb
const float half_square_length_90; // idb
const float DEFAULT_VIEW_RADIUS_59; // idb
const long double MIN_QUANTUM_59; // idb
const long double MAX_QUANTUM_59; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_94; // idb
const float outside_val_91; // idb
const float block_length_91; // idb
const float half_square_length_91; // idb
const float DEFAULT_VIEW_RADIUS_60; // idb
const long double MIN_QUANTUM_60; // idb
const long double MAX_QUANTUM_60; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_95; // idb
const float outside_val_92; // idb
const float block_length_92; // idb
const float half_square_length_92; // idb
const float DEFAULT_VIEW_RADIUS_61; // idb
const long double MIN_QUANTUM_61; // idb
const long double MAX_QUANTUM_61; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_96; // idb
const float outside_val_93; // idb
const float block_length_93; // idb
const float half_square_length_93; // idb
const float DEFAULT_VIEW_RADIUS_62; // idb
const long double MIN_QUANTUM_62; // idb
const long double MAX_QUANTUM_62; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_97; // idb
const float outside_val_94; // idb
const float block_length_94; // idb
const float half_square_length_94; // idb
const float DEFAULT_VIEW_RADIUS_63; // idb
const long double MIN_QUANTUM_63; // idb
const long double MAX_QUANTUM_63; // idb
PixelFormatDesc PixelFormatDesc_A8R8G8B8_98; // idb
const float outside_val_95; // idb
const float block_length_95; // idb
const float half_square_length_95; // idb
const float DEFAULT_VIEW_RADIUS_64; // idb
const long double MIN_QUANTUM_64; // idb
const long double MAX_QUANTUM_64; // idb
PixelFormatDesc stru_83FEE8; // idb
const float outside_val_96; // idb
const float block_length_96; // idb
const float half_square_length_96; // idb
const float DEFAULT_VIEW_RADIUS_65; // idb
const long double MIN_QUANTUM_65; // idb
const long double MAX_QUANTUM_65; // idb
PixelFormatDesc stru_83FF60; // idb
const float outside_val_97; // idb
const float block_length_97; // idb
const float half_square_length_97; // idb
const float DEFAULT_VIEW_RADIUS_66; // idb
const long double MIN_QUANTUM_66; // idb
const long double MAX_QUANTUM_66; // idb
PixelFormatDesc stru_83FFD8; // idb
const float outside_val_98; // idb
const float block_length_98; // idb
const float half_square_length_98; // idb
const float DEFAULT_VIEW_RADIUS_67; // idb
const long double MIN_QUANTUM_67; // idb
const long double MAX_QUANTUM_67; // idb
PixelFormatDesc stru_840050; // idb
const float flt_8400A8; // idb
const float flt_8400AC; // idb
const float flt_8400B0; // idb
PStringBase<char> Misc_TooltipEnable_35; // idb
PStringBase<char> Misc_TooltipDelay_35; // idb
const float flt_8400E0; // idb
const float flt_8400E4; // idb
const float flt_8400E8; // idb
const int LOWEST_DATA_RATE_94; // idb
const int HIGHEST_DATA_RATE_94; // idb
const int INITIAL_MAX_DATA_RATE_42; // idb
const float DEFAULT_VIEW_RADIUS_68; // idb
const long double MIN_QUANTUM_68; // idb
const long double MAX_QUANTUM_68; // idb
PixelFormatDesc stru_840110; // idb
PStringBase<char> Misc_TooltipEnable_36; // idb
PStringBase<char> Misc_TooltipDelay_36; // idb
PStringBase<char> Sound_SoundDisabled_5; // idb
PStringBase<char> Sound_SoundVolume_5; // idb
PStringBase<char> Sound_AmbientSoundDisabled_5; // idb
PStringBase<char> Sound_AmbientSoundVolume_5; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_5; // idb
PStringBase<char> Sound_InterfaceSoundVolume_5; // idb
PStringBase<char> Sound_SoundFeatures_5; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_5; // idb
PStringBase<char> Sound_SoundFeatures_Choices_5[2]; // idb
PStringBase<char> stru_840174; // idb
const float VOL_MIN_DIST_SQ_3; // idb
const long double INV_LOG_OF_2_3; // idb
PStringBase<char> Render_TextureFiltering_18; // idb
PStringBase<char> Render_LandscapeDetailTextures_18; // idb
PStringBase<char> Render_BuildingDetailTextures_18; // idb
PStringBase<char> Render_FieldOfView_18; // idb
PStringBase<char> Render_LandscapeTextureDetail_18; // idb
PStringBase<char> Render_EnvironmentTextureDetail_18; // idb
PStringBase<char> Render_SceneryDrawDistance_18; // idb
PStringBase<char> Render_LandscapeDrawDistance_18; // idb
PStringBase<char> Render_ScreenBrightness_18; // idb
PStringBase<char> Render_AspectRatio_18; // idb
PStringBase<char> Render_DisplayAdapter_18; // idb
PStringBase<char> Render_MaxHardwareClass_18; // idb
PStringBase<char> Render_AutomaticDegrades_18; // idb
PStringBase<char> Render_GraphicsPerformance_18; // idb
PStringBase<char> Render_DegradeDistance_18; // idb
PStringBase<char> Render_MultiPassAlpha_18; // idb
PStringBase<char> Render_TextureFiltering_Choices_18[4]; // idb
PStringBase<char> stru_8401CC; // idb
PStringBase<char> stru_8401D0; // idb
PStringBase<char> stru_8401D4; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_18[5]; // idb
PStringBase<char> stru_8401DC; // idb
PStringBase<char> stru_8401E0; // idb
PStringBase<char> stru_8401E4; // idb
PStringBase<char> stru_8401E8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_18[5]; // idb
PStringBase<char> stru_8401F0; // idb
PStringBase<char> stru_8401F4; // idb
PStringBase<char> stru_8401F8; // idb
PStringBase<char> stru_8401FC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_18[3]; // idb
PStringBase<char> stru_840204; // idb
PStringBase<char> stru_840208; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_18[6]; // idb
PStringBase<char> stru_840210; // idb
PStringBase<char> stru_840214; // idb
PStringBase<char> stru_840218; // idb
PStringBase<char> stru_84021C; // idb
PStringBase<char> stru_840220; // idb
PStringBase<char> Render_AspectRatio_Choices_18[3]; // idb
PStringBase<char> stru_840228; // idb
PStringBase<char> stru_84022C; // idb
PStringBase<char> waveform_None_37; // idb
PStringBase<char> waveform_Speed_37; // idb
PStringBase<char> waveform_Noise_37; // idb
PStringBase<char> waveform_Sine_37; // idb
PStringBase<char> waveform_Square_37; // idb
PStringBase<char> waveform_Bounce_37; // idb
PStringBase<char> waveform_Perlin_37; // idb
PStringBase<char> waveform_Fractal_37; // idb
PStringBase<char> waveform_FrameLoop_37; // idb
const unsigned int ID_SmartBox_FPS; // idb
const unsigned int fps_var; // idb
const unsigned int deg_var; // idb
RGBAColor RGBAColor_Null_4; // idb
const float flt_840290; // idb
const float flt_840294; // idb
const float flt_840298; // idb
PixelFormatDesc stru_84029C; // idb
RGBAColor RGBAColor_RadarDefault_0; // idb
RGBAColor RGBAColor_RadarAdmin_0; // idb
RGBAColor RGBAColor_RadarAdvocate_0; // idb
RGBAColor RGBAColor_RadarCreature_0; // idb
RGBAColor RGBAColor_RadarLifeStone_0; // idb
RGBAColor RGBAColor_RadarNPC_0; // idb
RGBAColor RGBAColor_RadarPlayerKiller_0; // idb
RGBAColor RGBAColor_RadarPortal_0; // idb
RGBAColor RGBAColor_RadarSentinel_0; // idb
RGBAColor RGBAColor_RadarVendor_0; // idb
RGBAColor RGBAColor_RadarFellowship_0; // idb
RGBAColor RGBAColor_RadarFellowshipLeader_0; // idb
RGBAColor RGBAColor_RadarPKLite_0; // idb
const float DEFAULT_VIEW_RADIUS_69; // idb
const long double MIN_QUANTUM_69; // idb
const long double MAX_QUANTUM_69; // idb
PStringBase<char> waveform_None_38; // idb
PStringBase<char> waveform_Speed_38; // idb
PStringBase<char> waveform_Noise_38; // idb
PStringBase<char> waveform_Sine_38; // idb
PStringBase<char> waveform_Square_38; // idb
PStringBase<char> waveform_Bounce_38; // idb
PStringBase<char> waveform_Perlin_38; // idb
PStringBase<char> waveform_Fractal_38; // idb
PStringBase<char> waveform_FrameLoop_38; // idb
PStringBase<char> Misc_TooltipEnable_37; // idb
PStringBase<char> Misc_TooltipDelay_37; // idb
const int LOWEST_DATA_RATE_95; // idb
const int HIGHEST_DATA_RATE_95; // idb
const int INITIAL_MAX_DATA_RATE_43; // idb
const float sin_r_angle; // idb
const float cos_r_angle; // idb
const float flt_840418; // idb
const float flt_84041C; // idb
const float flt_840420; // idb
const float DEFAULT_VIEW_RADIUS_70; // idb
const long double MIN_QUANTUM_70; // idb
const long double MAX_QUANTUM_70; // idb
PixelFormatDesc stru_840438; // idb
const float flt_840490; // idb
const float flt_840494; // idb
const float flt_840498; // idb
PStringBase<char> waveform_None_39; // idb
PStringBase<char> waveform_Speed_39; // idb
PStringBase<char> waveform_Noise_39; // idb
PStringBase<char> waveform_Sine_39; // idb
PStringBase<char> waveform_Square_39; // idb
PStringBase<char> waveform_Bounce_39; // idb
PStringBase<char> waveform_Perlin_39; // idb
PStringBase<char> waveform_Fractal_39; // idb
PStringBase<char> waveform_FrameLoop_39; // idb
const int LOWEST_DATA_RATE_96; // idb
const int HIGHEST_DATA_RATE_96; // idb
const int INITIAL_MAX_DATA_RATE_44; // idb
const float DEFAULT_VIEW_RADIUS_71; // idb
const long double MIN_QUANTUM_71; // idb
const long double MAX_QUANTUM_71; // idb
PixelFormatDesc stru_8404E0; // idb
const unsigned int ID_KeyMapCantOverwriteReadOnlyKeymap_Label; // idb
const unsigned int ID_KeyMapLoadKeymap_Label; // idb
const unsigned int ID_KeyMapOverwriteKeymap_Label; // idb
const unsigned int ID_KeyMapSaveKeymap_Label; // idb
const unsigned int KEYMAP; // idb
IDClass<_tagDataID,32,0> script_id; // idb
const float flt_840550; // idb
const float flt_840554; // idb
const float flt_840558; // idb
const float DEFAULT_VIEW_RADIUS_72; // idb
const long double MIN_QUANTUM_72; // idb
const long double MAX_QUANTUM_72; // idb
PixelFormatDesc stru_840570; // idb
const int LOWEST_DATA_RATE_97; // idb
const int HIGHEST_DATA_RATE_97; // idb
const int INITIAL_MAX_DATA_RATE_45; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CLOTHING_DEFAULT; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_SKELETON_NOFLAME_PES; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_ZOMBIE_NOFLAME_PES; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_SKELETON_NOFLAME_PES; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_ZOMBIE_NOFLAME_PES; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_NOCROWN_PES; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_NOCROWN_PES; // idb
IDClass<_tagDataID,32,0> stru_840604; // idb
const float flt_840608; // idb
const float flt_84060C; // idb
const float flt_840610; // idb
const float DEFAULT_VIEW_RADIUS_73; // idb
const long double MIN_QUANTUM_73; // idb
const long double MAX_QUANTUM_73; // idb
PixelFormatDesc stru_840628; // idb
PStringBase<char> Misc_TooltipEnable_38; // idb
PStringBase<char> Misc_TooltipDelay_38; // idb
const int LOWEST_DATA_RATE_98; // idb
const int HIGHEST_DATA_RATE_98; // idb
const int INITIAL_MAX_DATA_RATE_46; // idb
const float flt_840698; // idb
const float flt_84069C; // idb
const float flt_8406A0; // idb
const float DEFAULT_VIEW_RADIUS_74; // idb
const long double MIN_QUANTUM_74; // idb
const long double MAX_QUANTUM_74; // idb
PixelFormatDesc stru_8406B8; // idb
PStringBase<char> Misc_TooltipEnable_39; // idb
PStringBase<char> Misc_TooltipDelay_39; // idb
const int dword_8406F8; // idb
const int dword_8406FC; // idb
const int INITIAL_MAX_DATA_RATE_47; // idb
PixelFormatDesc stru_840724; // idb
const float dword_840760; // idb
const float flt_840764; // idb
const float flt_840768; // idb
const float flt_84076C; // idb
PStringBase<char> Misc_TooltipEnable_40; // idb
PStringBase<char> Misc_TooltipDelay_40; // idb
const float DEFAULT_VIEW_RADIUS_75; // idb
const long double MIN_QUANTUM_75; // idb
const long double MAX_QUANTUM_75; // idb
const int dword_840790; // idb
const int dword_840794; // idb
const int INITIAL_MAX_DATA_RATE_48; // idb
const float flt_8407BC; // idb
const float flt_8407C0; // idb
const float flt_8407C4; // idb
const float flt_8407E8; // idb
const float flt_8407EC; // idb
const float flt_8407F0; // idb
const float flt_840814; // idb
const float flt_840818; // idb
const float flt_84081C; // idb
const float flt_840840; // idb
const float flt_840844; // idb
const float flt_840848; // idb
const int dword_84084C; // idb
const int dword_840850; // idb
const int INITIAL_MAX_DATA_RATE_49; // idb
const float DEFAULT_VIEW_RADIUS_76; // idb
const long double MIN_QUANTUM_76; // idb
const long double MAX_QUANTUM_76; // idb
PixelFormatDesc stru_840870; // idb
const float flt_8408C8; // idb
const float flt_8408CC; // idb
const float flt_8408D0; // idb
const float flt_8408F4; // idb
const float flt_8408F8; // idb
const float flt_8408FC; // idb
IDClass<_tagDataID,32,0> stru_840904; // idb
PStringBase<char> Misc_TooltipEnable_41; // idb
PStringBase<char> Misc_TooltipDelay_41; // idb
const unsigned int ID_Wait_PleaseWait; // idb
const float flt_840938; // idb
const float flt_84093C; // idb
const float flt_840940; // idb
const float DEFAULT_VIEW_RADIUS_77; // idb
const long double MIN_QUANTUM_77; // idb
const long double MAX_QUANTUM_77; // idb
PixelFormatDesc stru_840958; // idb
PStringBase<char> Display_Resolution_14; // idb
PStringBase<char> Display_FullScreen_14; // idb
PStringBase<char> Display_RefreshRate_14; // idb
PStringBase<char> Display_SyncToRefresh_14; // idb
const float flt_8409C0; // idb
const float flt_8409C4; // idb
const float flt_8409C8; // idb
PStringBase<char> Display_Resolution_15; // idb
PStringBase<char> Display_FullScreen_15; // idb
PStringBase<char> Display_RefreshRate_15; // idb
PStringBase<char> Display_SyncToRefresh_15; // idb
const float flt_840A00; // idb
const float flt_840A04; // idb
const float flt_840A08; // idb
PStringBase<char> Display_Resolution_16; // idb
PStringBase<char> Display_FullScreen_16; // idb
PStringBase<char> Display_RefreshRate_16; // idb
PStringBase<char> Display_SyncToRefresh_16; // idb
const int dword_840A1C; // idb
const int dword_840A20; // idb
const int INITIAL_MAX_DATA_RATE_50; // idb
const float DEFAULT_VIEW_RADIUS_78; // idb
const long double MIN_QUANTUM_78; // idb
const long double MAX_QUANTUM_78; // idb
PixelFormatDesc stru_840A40; // idb
const float flt_840A98; // idb
const float flt_840A9C; // idb
const float flt_840AA0; // idb
const float DEFAULT_VIEW_RADIUS_79; // idb
const long double MIN_QUANTUM_79; // idb
const long double MAX_QUANTUM_79; // idb
PixelFormatDesc stru_840AB8; // idb
const int dword_840AF0; // idb
const int dword_840AF4; // idb
const int INITIAL_MAX_DATA_RATE_51; // idb
PStringBase<char> Display_Resolution_17; // idb
PStringBase<char> Display_FullScreen_17; // idb
PStringBase<char> Display_RefreshRate_17; // idb
PStringBase<char> Display_SyncToRefresh_17; // idb
PStringBase<char> Misc_TooltipEnable_42; // idb
PStringBase<char> Misc_TooltipDelay_42; // idb
PStringBase<char> waveform_None_40; // idb
PStringBase<char> waveform_Speed_40; // idb
PStringBase<char> waveform_Noise_40; // idb
PStringBase<char> waveform_Sine_40; // idb
PStringBase<char> waveform_Square_40; // idb
PStringBase<char> waveform_Bounce_40; // idb
PStringBase<char> waveform_Perlin_40; // idb
PStringBase<char> waveform_Fractal_40; // idb
PStringBase<char> waveform_FrameLoop_40; // idb
const unsigned int ID_Wait_PleaseWait_0; // idb
const unsigned int ID_Client_EndCharacterSessionConfirm; // idb
const unsigned int ID_Client_LogoffConfirm; // idb
const float flt_840B68; // idb
const float flt_840B6C; // idb
const float flt_840B70; // idb
const int dword_840B74; // idb
const int dword_840B78; // idb
const int INITIAL_MAX_DATA_RATE_52; // idb
const float DEFAULT_VIEW_RADIUS_80; // idb
const long double MIN_QUANTUM_80; // idb
const long double MAX_QUANTUM_80; // idb
PixelFormatDesc stru_840B98; // idb
const unsigned int ID_CharacterManagement_CG_VERIFICATION_RESPONSE_NAME_IN_USE; // idb
const unsigned int ID_CharacterManagement_CG_VERIFICATION_RESPONSE_CORRUPT; // idb
const unsigned int ID_CharacterManagement_CG_VERIFICATION_RESPONSE_DATABASE_DOWN; // idb
const unsigned int ID_Character_EnteringWorld; // idb
const unsigned int ID_CharacterManagement_DeleteCharacterConfirmation; // idb
const unsigned int ID_CharacterManagement_DeleteCharacterResponse; // idb
const unsigned int ID_CharacterManagement_PleaseWait; // idb
const unsigned int ID_Player_1; // idb
const float flt_840C10; // idb
const float flt_840C14; // idb
const float flt_840C18; // idb
const float flt_840C3C; // idb
const float flt_840C40; // idb
const float flt_840C44; // idb
PStringBase<char> Display_Resolution_18; // idb
PStringBase<char> Display_FullScreen_18; // idb
PStringBase<char> Display_RefreshRate_18; // idb
PStringBase<char> Display_SyncToRefresh_18; // idb
const int dword_840C58; // idb
const int dword_840C5C; // idb
const int INITIAL_MAX_DATA_RATE_53; // idb
const unsigned int ID_Progress; // idb
const unsigned int ID_DataPatch_PatchProgress; // idb
const unsigned int ID_DataPatch_PatchRate; // idb
const unsigned int ID_DataPatch_Interrogation; // idb
const unsigned int ID_DataPatch_Patching; // idb
const unsigned int ID_DataPatch_PatchingDone; // idb
const unsigned int ID_DataPatch_Waiting; // idb
const unsigned int token_error; // idb
const unsigned int token_host; // idb
const unsigned int token_port; // idb
const unsigned int token_percent; // idb
const unsigned int token_rate; // idb
const unsigned int token_total; // idb
const unsigned int token_so_far; // idb
void *UIGlobals::s_pLevelArray; // idb
IDClass<_tagDataID,32,0> stru_840CBC; // idb
const float flt_840CC0; // idb
const float flt_840CC4; // idb
const float flt_840CC8; // idb
const float DEFAULT_VIEW_RADIUS_81; // idb
const long double MIN_QUANTUM_81; // idb
const long double MAX_QUANTUM_81; // idb
PixelFormatDesc stru_840CE0; // idb
const int dword_840D18; // idb
const int dword_840D1C; // idb
const int INITIAL_MAX_DATA_RATE_54; // idb
const float flt_840D48; // idb
const float flt_840D4C; // idb
const float flt_840D50; // idb
const float DEFAULT_VIEW_RADIUS_82; // idb
const long double MIN_QUANTUM_82; // idb
const long double MAX_QUANTUM_82; // idb
PixelFormatDesc stru_840D68; // idb
const int dword_840DA0; // idb
const int dword_840DA4; // idb
const int INITIAL_MAX_DATA_RATE_55; // idb
const float flt_840DD0; // idb
const float flt_840DD4; // idb
const float flt_840DD8; // idb
const float DEFAULT_VIEW_RADIUS_83; // idb
const long double MIN_QUANTUM_83; // idb
const long double MAX_QUANTUM_83; // idb
PixelFormatDesc stru_840DF0; // idb
const unsigned int ID_StatManagement_Header_PKStatus_NPK; // idb
const unsigned int ID_StatManagement_Header_PKStatus_PK; // idb
const unsigned int ID_StatManagement_Header_PKStatus_PKL; // idb
const unsigned int ID_StatManagement_Header_TotalXPValue; // idb
const unsigned int ID_StatManagement_Header_XPToLevelMeterValue; // idb
const unsigned int ID_StatManagement_Header_XPToLevelMeterInfinity_1; // idb
const unsigned int ID_TotalExperience; // idb
const unsigned int ID_ExperienceToLevel; // idb
IDClass<_tagDataID,32,0> stru_840E64; // idb
const float flt_840E68; // idb
const float flt_840E6C; // idb
const float flt_840E70; // idb
const float DEFAULT_VIEW_RADIUS_84; // idb
const long double MIN_QUANTUM_84; // idb
const long double MAX_QUANTUM_84; // idb
PixelFormatDesc stru_840E88; // idb
const float flt_840EE0; // idb
const float flt_840EE4; // idb
const float flt_840EE8; // idb
PStringBase<char> Camera_AlignToSlope_3; // idb
PStringBase<char> Camera_Stiffness_3; // idb
PStringBase<char> Camera_AdjustmentSpeed_3; // idb
PStringBase<char> Sound_SoundDisabled_6; // idb
PStringBase<char> Sound_SoundVolume_6; // idb
PStringBase<char> Sound_AmbientSoundDisabled_6; // idb
PStringBase<char> Sound_AmbientSoundVolume_6; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_6; // idb
PStringBase<char> Sound_InterfaceSoundVolume_6; // idb
PStringBase<char> Sound_SoundFeatures_6; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_6; // idb
PStringBase<char> Sound_SoundFeatures_Choices_6[2]; // idb
PStringBase<char> stru_840F1C; // idb
PStringBase<char> Misc_TooltipEnable_43; // idb
PStringBase<char> Misc_TooltipDelay_43; // idb
PStringBase<char> Display_Resolution_19; // idb
PStringBase<char> Display_FullScreen_19; // idb
PStringBase<char> Display_RefreshRate_19; // idb
PStringBase<char> Display_SyncToRefresh_19; // idb
const float DEFAULT_VIEW_RADIUS_85; // idb
const long double MIN_QUANTUM_85; // idb
const long double MAX_QUANTUM_85; // idb
PixelFormatDesc stru_840F50; // idb
const int dword_840F88; // idb
const int dword_840F8C; // idb
const int INITIAL_MAX_DATA_RATE_56; // idb
PStringBase<char> Render_TextureFiltering_19; // idb
PStringBase<char> Render_LandscapeDetailTextures_19; // idb
PStringBase<char> Render_BuildingDetailTextures_19; // idb
PStringBase<char> Render_FieldOfView_19; // idb
PStringBase<char> Render_LandscapeTextureDetail_19; // idb
PStringBase<char> Render_EnvironmentTextureDetail_19; // idb
PStringBase<char> Render_SceneryDrawDistance_19; // idb
PStringBase<char> Render_LandscapeDrawDistance_19; // idb
PStringBase<char> Render_ScreenBrightness_19; // idb
PStringBase<char> Render_AspectRatio_19; // idb
PStringBase<char> Render_DisplayAdapter_19; // idb
PStringBase<char> Render_MaxHardwareClass_19; // idb
PStringBase<char> Render_AutomaticDegrades_19; // idb
PStringBase<char> Render_GraphicsPerformance_19; // idb
PStringBase<char> Render_DegradeDistance_19; // idb
PStringBase<char> Render_MultiPassAlpha_19; // idb
PStringBase<char> Render_TextureFiltering_Choices_19[4]; // idb
PStringBase<char> stru_840FD8; // idb
PStringBase<char> stru_840FDC; // idb
PStringBase<char> stru_840FE0; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_19[5]; // idb
PStringBase<char> stru_840FE8; // idb
PStringBase<char> stru_840FEC; // idb
PStringBase<char> stru_840FF0; // idb
PStringBase<char> stru_840FF4; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_19[5]; // idb
PStringBase<char> stru_840FFC; // idb
PStringBase<char> stru_841000; // idb
PStringBase<char> stru_841004; // idb
PStringBase<char> stru_841008; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_19[3]; // idb
PStringBase<char> stru_841010; // idb
PStringBase<char> stru_841014; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_19[6]; // idb
PStringBase<char> stru_84101C; // idb
PStringBase<char> stru_841020; // idb
PStringBase<char> stru_841024; // idb
PStringBase<char> stru_841028; // idb
PStringBase<char> stru_84102C; // idb
PStringBase<char> Render_AspectRatio_Choices_19[3]; // idb
PStringBase<char> stru_841034; // idb
PStringBase<char> stru_841038; // idb
PStringBase<char> Input_MouseLookSensitivity_3; // idb
PStringBase<char> Input_MouseLookSmoothingAmount_3; // idb
PStringBase<char> Input_InvertMouseLookYAxis_3; // idb
PStringBase<char> Input_UseMouseTurning_3; // idb
PStringBase<char> waveform_None_41; // idb
PStringBase<char> waveform_Speed_41; // idb
PStringBase<char> waveform_Noise_41; // idb
PStringBase<char> waveform_Sine_41; // idb
PStringBase<char> waveform_Square_41; // idb
PStringBase<char> waveform_Bounce_41; // idb
PStringBase<char> waveform_Perlin_41; // idb
PStringBase<char> waveform_Fractal_41; // idb
PStringBase<char> waveform_FrameLoop_41; // idb
const float flt_841090; // idb
const float flt_841094; // idb
const float flt_841098; // idb
const float flt_8410C0; // idb
const float flt_8410C4; // idb
const float flt_8410C8; // idb
const float DEFAULT_VIEW_RADIUS_86; // idb
const long double MIN_QUANTUM_86; // idb
const long double MAX_QUANTUM_86; // idb
PixelFormatDesc stru_8410E0; // idb
const int dword_841118; // idb
const int dword_84111C; // idb
const int INITIAL_MAX_DATA_RATE_57; // idb
PStringBase<char> Input_KeymapFile_2; // idb
PStringBase<char> UI_ChatFontFace_2; // idb
PStringBase<char> UI_ChatFontSize_2; // idb
_DWORD UI_ChatFontFace_Choices_2; // idb
PStringBase<char> stru_841134; // idb
PStringBase<char> stru_841138; // idb
PStringBase<char> stru_84113C; // idb
PStringBase<char> stru_841140; // idb
_DWORD UI_ChatFontSize_Choices_2; // idb
PStringBase<char> stru_841148; // idb
PStringBase<char> stru_84114C; // idb
PStringBase<char> stru_841150; // idb
PStringBase<char> stru_841154; // idb
PStringBase<char> waveform_None_42; // idb
PStringBase<char> waveform_Speed_42; // idb
PStringBase<char> waveform_Noise_42; // idb
PStringBase<char> waveform_Sine_42; // idb
PStringBase<char> waveform_Square_42; // idb
PStringBase<char> waveform_Bounce_42; // idb
PStringBase<char> waveform_Perlin_42; // idb
PStringBase<char> waveform_Fractal_42; // idb
PStringBase<char> waveform_FrameLoop_42; // idb
PStringBase<char> Misc_TooltipEnable_44; // idb
PStringBase<char> Misc_TooltipDelay_44; // idb
const unsigned int ID_CmdPrefix_0; // idb
const unsigned int ID_AliasPrefix_0; // idb
const unsigned int ID_AssistedTell_0; // idb
const unsigned int PREFIX_0; // idb
const unsigned int TARGET_0; // idb
const float flt_8411B8; // idb
const float flt_8411BC; // idb
const float flt_8411C0; // idb
const float DEFAULT_VIEW_RADIUS_87; // idb
const long double MIN_QUANTUM_87; // idb
const long double MAX_QUANTUM_87; // idb
PixelFormatDesc stru_8411D8; // idb
const int dword_841210; // idb
const int dword_841214; // idb
const int INITIAL_MAX_DATA_RATE_58; // idb
VividTargetIndicator *VividTargetIndicator::s_pVTInstance; // idb
const float flt_841254; // idb
const float flt_841258; // idb
const float flt_84125C; // idb
const int dword_841260; // idb
const int dword_841264; // idb
const int INITIAL_MAX_DATA_RATE_59; // idb
const float DEFAULT_VIEW_RADIUS_88; // idb
const long double MIN_QUANTUM_88; // idb
const long double MAX_QUANTUM_88; // idb
PixelFormatDesc stru_841280; // idb
RGBAColor RGBAColor_RadarDefault_1; // idb
RGBAColor RGBAColor_RadarAdmin_1; // idb
RGBAColor RGBAColor_RadarAdvocate_1; // idb
RGBAColor RGBAColor_RadarCreature_1; // idb
RGBAColor RGBAColor_RadarLifeStone_1; // idb
RGBAColor RGBAColor_RadarNPC_1; // idb
RGBAColor RGBAColor_RadarPlayerKiller_1; // idb
RGBAColor RGBAColor_RadarPortal_1; // idb
RGBAColor RGBAColor_RadarSentinel_1; // idb
RGBAColor RGBAColor_RadarVendor_1; // idb
RGBAColor RGBAColor_RadarFellowship_1; // idb
RGBAColor RGBAColor_RadarFellowshipLeader_1; // idb
RGBAColor RGBAColor_RadarPKLite_1; // idb
IDClass<_tagDataID,32,0> id; // idb
const float dword_8413A8; // idb
const float flt_8413AC; // idb
const float flt_8413B0; // idb
const float flt_8413B4; // idb
const float DEFAULT_VIEW_RADIUS_89; // idb
const long double MIN_QUANTUM_89; // idb
const long double MAX_QUANTUM_89; // idb
PixelFormatDesc stru_8413D0; // idb
PStringBase<char> waveform_None_43; // idb
PStringBase<char> waveform_Speed_43; // idb
PStringBase<char> waveform_Noise_43; // idb
PStringBase<char> waveform_Sine_43; // idb
PStringBase<char> waveform_Square_43; // idb
PStringBase<char> waveform_Bounce_43; // idb
PStringBase<char> waveform_Perlin_43; // idb
PStringBase<char> waveform_Fractal_43; // idb
PStringBase<char> waveform_FrameLoop_43; // idb
const int dword_84142C; // idb
const int dword_841430; // idb
const int INITIAL_MAX_DATA_RATE_60; // idb
AsyncContext INVALID_ASYNCCONTEXT_6; // idb
UIQueueManager *IQueuedUIEventDeliverer::s_pInstance; // idb
const int INITIAL_MAX_DATA_RATE_61; // idb
IDClass<_tagDataID,32,0> stru_841450; // idb
CRegionDesc *CRegionDesc::current_region; // idb
const float flt_84147C; // idb
const float flt_841480; // idb
const float flt_841484; // idb
IDClass<_tagDataID,32,0> stru_841488; // idb
PStringBase<char> Sound_SoundDisabled_7; // idb
PStringBase<char> Sound_SoundVolume_7; // idb
PStringBase<char> Sound_AmbientSoundDisabled_7; // idb
PStringBase<char> Sound_AmbientSoundVolume_7; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_7; // idb
PStringBase<char> Sound_InterfaceSoundVolume_7; // idb
PStringBase<char> Sound_SoundFeatures_7; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_7; // idb
PStringBase<char> Sound_SoundFeatures_Choices_7[2]; // idb
PStringBase<char> stru_8414B0; // idb
const float VOL_MIN_DIST_SQ_4; // idb
const long double INV_LOG_OF_2_4; // idb
PixelFormatDesc stru_8414D0; // idb
IDClass<_tagDataID,32,0> stru_841508; // idb
const float dword_84150C; // idb
const float flt_841510; // idb
const float flt_841514; // idb
const float flt_841518; // idb
IDClass<_tagDataID,32,0> stru_84152C; // idb
IDClass<_tagDataID,32,0> stru_841540; // idb
const float dword_841544; // idb
const float flt_841548; // idb
const float flt_84154C; // idb
const float flt_841550; // idb
PStringBase<char> Sound_SoundDisabled_8; // idb
PStringBase<char> Sound_SoundVolume_8; // idb
PStringBase<char> Sound_AmbientSoundDisabled_8; // idb
PStringBase<char> Sound_AmbientSoundVolume_8; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_8; // idb
PStringBase<char> Sound_InterfaceSoundVolume_8; // idb
PStringBase<char> Sound_SoundFeatures_8; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_8; // idb
PStringBase<char> Sound_SoundFeatures_Choices_8[2]; // idb
PStringBase<char> stru_841578; // idb
const float VOL_MIN_DIST_SQ_5; // idb
const long double INV_LOG_OF_2_5; // idb
const float flt_841598; // idb
const float flt_84159C; // idb
const float flt_8415A0; // idb
IDClass<_tagDataID,32,0> stru_8415A4; // idb
PStringBase<char> Sound_SoundDisabled_9; // idb
PStringBase<char> Sound_SoundVolume_9; // idb
PStringBase<char> Sound_AmbientSoundDisabled_9; // idb
PStringBase<char> Sound_AmbientSoundVolume_9; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_9; // idb
PStringBase<char> Sound_InterfaceSoundVolume_9; // idb
PStringBase<char> Sound_SoundFeatures_9; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_9; // idb
PStringBase<char> Sound_SoundFeatures_Choices_9[2]; // idb
PStringBase<char> stru_8415CC; // idb
const float VOL_MIN_DIST_SQ_6; // idb
const long double INV_LOG_OF_2_6; // idb
const float flt_8415F0; // idb
const float flt_8415F4; // idb
const float flt_8415F8; // idb
IDClass<_tagDataID,32,0> stru_8415FC; // idb
PStringBase<char> Sound_SoundDisabled_10; // idb
PStringBase<char> Sound_SoundVolume_10; // idb
PStringBase<char> Sound_AmbientSoundDisabled_10; // idb
PStringBase<char> Sound_AmbientSoundVolume_10; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_10; // idb
PStringBase<char> Sound_InterfaceSoundVolume_10; // idb
PStringBase<char> Sound_SoundFeatures_10; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_10; // idb
PStringBase<char> Sound_SoundFeatures_Choices_10[2]; // idb
PStringBase<char> stru_841624; // idb
const float VOL_MIN_DIST_SQ_7; // idb
const long double INV_LOG_OF_2_7; // idb
const float flt_84164C; // idb
const float flt_841650; // idb
const float flt_841654; // idb
const float flt_841668; // idb
const float flt_84166C; // idb
const float flt_841670; // idb
PixelFormatDesc stru_841674; // idb
IDClass<_tagDataID,32,0> stru_8416AC; // idb
const float dword_8416C4; // idb
const float flt_8416C8; // idb
const float flt_8416CC; // idb
const float flt_8416D0; // idb
PStringBase<char> Sound_SoundDisabled_11; // idb
PStringBase<char> Sound_SoundVolume_11; // idb
PStringBase<char> Sound_AmbientSoundDisabled_11; // idb
PStringBase<char> Sound_AmbientSoundVolume_11; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_11; // idb
PStringBase<char> Sound_InterfaceSoundVolume_11; // idb
PStringBase<char> Sound_SoundFeatures_11; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_11; // idb
PStringBase<char> Sound_SoundFeatures_Choices_11[2]; // idb
PStringBase<char> stru_8416F8; // idb
const float VOL_MIN_DIST_SQ_8; // idb
const long double INV_LOG_OF_2_8; // idb
char *TexMerge::tex_data; // idb
const float flt_84171C; // idb
const float flt_841720; // idb
const float flt_841724; // idb
PixelFormatDesc stru_841728; // idb
IDClass<_tagDataID,32,0> stru_841760; // idb
RGBAUnion LScape::sunlight_color; // idb
RGBAUnion LScape::ambient_color; // idb
float LScape::ambient_level; // idb
struct RGBAUnion LScape::m_override_fog_color; // weak
struct RGBAUnion LScape::m_override_ambient_color; // weak
ViewIntervalType *block_interval; // idb
double LScape::next_tick; // weak
double LScape::next_light_tick; // weak
bool LScape::m_fAlwaysDaylight; // weak
bool LScape::m_override_enabled; // weak
float LScape::m_override_ambient_level; // weak
float LScape::m_override_fog_min; // weak
float LScape::m_override_fog_max; // weak
float LScape::m_override_transition; // weak
PStringBase<char> Display_Resolution_20; // idb
PStringBase<char> Display_FullScreen_20; // idb
PStringBase<char> Display_RefreshRate_20; // idb
PStringBase<char> Display_SyncToRefresh_20; // idb
PixelFormatDesc stru_8417D4; // idb
const float dword_84180C; // idb
const float flt_841810; // idb
const float flt_841814; // idb
const float flt_841818; // idb
IDClass<_tagDataID,32,0> stru_84181C; // idb
PStringBase<char> Render_TextureFiltering_20; // idb
PStringBase<char> Render_LandscapeDetailTextures_20; // idb
PStringBase<char> Render_BuildingDetailTextures_20; // idb
PStringBase<char> Render_FieldOfView_20; // idb
PStringBase<char> Render_LandscapeTextureDetail_20; // idb
PStringBase<char> Render_EnvironmentTextureDetail_20; // idb
PStringBase<char> Render_SceneryDrawDistance_20; // idb
PStringBase<char> Render_LandscapeDrawDistance_20; // idb
PStringBase<char> Render_ScreenBrightness_20; // idb
PStringBase<char> Render_AspectRatio_20; // idb
PStringBase<char> Render_DisplayAdapter_20; // idb
PStringBase<char> Render_MaxHardwareClass_20; // idb
PStringBase<char> Render_AutomaticDegrades_20; // idb
PStringBase<char> Render_GraphicsPerformance_20; // idb
PStringBase<char> Render_DegradeDistance_20; // idb
PStringBase<char> Render_MultiPassAlpha_20; // idb
PStringBase<char> Render_TextureFiltering_Choices_20[4]; // idb
PStringBase<char> stru_841864; // idb
PStringBase<char> stru_841868; // idb
PStringBase<char> stru_84186C; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_20[5]; // idb
PStringBase<char> stru_841874; // idb
PStringBase<char> stru_841878; // idb
PStringBase<char> stru_84187C; // idb
PStringBase<char> stru_841880; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_20[5]; // idb
PStringBase<char> stru_841888; // idb
PStringBase<char> stru_84188C; // idb
PStringBase<char> stru_841890; // idb
PStringBase<char> stru_841894; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_20[3]; // idb
PStringBase<char> stru_84189C; // idb
PStringBase<char> stru_8418A0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_20[6]; // idb
PStringBase<char> stru_8418A8; // idb
PStringBase<char> stru_8418AC; // idb
PStringBase<char> stru_8418B0; // idb
PStringBase<char> stru_8418B4; // idb
PStringBase<char> stru_8418B8; // idb
PStringBase<char> Render_AspectRatio_Choices_20[3]; // idb
PStringBase<char> stru_8418C0; // idb
PStringBase<char> stru_8418C4; // idb
PStringBase<char> waveform_None_44; // idb
PStringBase<char> waveform_Speed_44; // idb
PStringBase<char> waveform_Noise_44; // idb
PStringBase<char> waveform_Sine_44; // idb
PStringBase<char> waveform_Square_44; // idb
PStringBase<char> waveform_Bounce_44; // idb
PStringBase<char> waveform_Perlin_44; // idb
PStringBase<char> waveform_Fractal_44; // idb
PStringBase<char> waveform_FrameLoop_44; // idb
const float DEFAULT_VIEW_RADIUS_90; // idb
const long double MIN_QUANTUM_90; // idb
const long double MAX_QUANTUM_90; // idb
const int dword_841900; // idb
const int dword_841904; // idb
const int INITIAL_MAX_DATA_RATE_62; // idb
PStringBase<char> Sound_SoundDisabled_12; // idb
PStringBase<char> Sound_SoundVolume_12; // idb
PStringBase<char> Sound_AmbientSoundDisabled_12; // idb
PStringBase<char> Sound_AmbientSoundVolume_12; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_12; // idb
PStringBase<char> Sound_InterfaceSoundVolume_12; // idb
PStringBase<char> Sound_SoundFeatures_12; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_12; // idb
PStringBase<char> Sound_SoundFeatures_Choices_12[2]; // idb
PStringBase<char> stru_841930; // idb
const float VOL_MIN_DIST_SQ_9; // idb
const long double INV_LOG_OF_2_9; // idb
AC1Legacy::Vector3 LScape::sunlight; // idb
float LScape::min_ambient; // weak
int block_int_size; // idb
double GameSky::s_timeAdjustment; // weak
int dword_841964; // weak
PStringBase<char> Display_Resolution_21; // idb
PStringBase<char> Display_FullScreen_21; // idb
PStringBase<char> Display_RefreshRate_21; // idb
PStringBase<char> Display_SyncToRefresh_21; // idb
PixelFormatDesc stru_841990; // idb
const float dword_8419CC; // idb
const float flt_8419D0; // idb
const float flt_8419D4; // idb
const float flt_8419D8; // idb
const float DEFAULT_VIEW_RADIUS_91; // idb
const long double MIN_QUANTUM_91; // idb
const long double MAX_QUANTUM_91; // idb
const int dword_8419F0; // idb
const int dword_8419F4; // idb
const int INITIAL_MAX_DATA_RATE_63; // idb
PStringBase<char> Render_TextureFiltering_21; // idb
PStringBase<char> Render_LandscapeDetailTextures_21; // idb
PStringBase<char> Render_BuildingDetailTextures_21; // idb
PStringBase<char> Render_FieldOfView_21; // idb
PStringBase<char> Render_LandscapeTextureDetail_21; // idb
PStringBase<char> Render_EnvironmentTextureDetail_21; // idb
PStringBase<char> Render_SceneryDrawDistance_21; // idb
PStringBase<char> Render_LandscapeDrawDistance_21; // idb
PStringBase<char> Render_ScreenBrightness_21; // idb
PStringBase<char> Render_AspectRatio_21; // idb
PStringBase<char> Render_DisplayAdapter_21; // idb
PStringBase<char> Render_MaxHardwareClass_21; // idb
PStringBase<char> Render_AutomaticDegrades_21; // idb
PStringBase<char> Render_GraphicsPerformance_21; // idb
PStringBase<char> Render_DegradeDistance_21; // idb
PStringBase<char> Render_MultiPassAlpha_21; // idb
PStringBase<char> Render_TextureFiltering_Choices_21[4]; // idb
PStringBase<char> stru_841A40; // idb
PStringBase<char> stru_841A44; // idb
PStringBase<char> stru_841A48; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_21[5]; // idb
PStringBase<char> stru_841A50; // idb
PStringBase<char> stru_841A54; // idb
PStringBase<char> stru_841A58; // idb
PStringBase<char> stru_841A5C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_21[5]; // idb
PStringBase<char> stru_841A64; // idb
PStringBase<char> stru_841A68; // idb
PStringBase<char> stru_841A6C; // idb
PStringBase<char> stru_841A70; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_21[3]; // idb
PStringBase<char> stru_841A78; // idb
PStringBase<char> stru_841A7C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_21[6]; // idb
PStringBase<char> stru_841A84; // idb
PStringBase<char> stru_841A88; // idb
PStringBase<char> stru_841A8C; // idb
PStringBase<char> stru_841A90; // idb
PStringBase<char> stru_841A94; // idb
PStringBase<char> Render_AspectRatio_Choices_21[3]; // idb
PStringBase<char> stru_841A9C; // idb
PStringBase<char> stru_841AA0; // idb
PStringBase<char> waveform_None_45; // idb
PStringBase<char> waveform_Speed_45; // idb
PStringBase<char> waveform_Noise_45; // idb
PStringBase<char> waveform_Sine_45; // idb
PStringBase<char> waveform_Square_45; // idb
PStringBase<char> waveform_Bounce_45; // idb
PStringBase<char> waveform_Perlin_45; // idb
PStringBase<char> waveform_Fractal_45; // idb
PStringBase<char> waveform_FrameLoop_45; // idb
CObjectMaint *CObjectMaint::s_pcInstance; // idb
const float flt_841AE8; // idb
const float flt_841AEC; // idb
const float flt_841AF0; // idb
const float DEFAULT_VIEW_RADIUS_92; // idb
const long double MIN_QUANTUM_92; // idb
const long double MAX_QUANTUM_92; // idb
const int INITIAL_MAX_DATA_RATE_64; // idb
PixelFormatDesc stru_841B14; // idb
QIOffset Offsets_0[3]; // idb
int dword_841B50; // weak
int dword_841B54; // weak
int dword_841B58; // weak
int dword_841B5C; // weak
int dword_841B60; // weak
unsigned int dword_841B64; // idb
DArray<CPhysicsObj *> object_list; // idb
unsigned int _S112_35; // idb
long double last_radar_update; // idb
CObjectMaint *CWeenieObject::objMaint; // idb
const int INITIAL_MAX_DATA_RATE_65; // idb
long double last_update; // idb
const float flt_841BC4; // idb
const float flt_841BC8; // idb
const float flt_841BCC; // idb
PStringBase<char> Display_Resolution_22; // idb
PStringBase<char> Display_FullScreen_22; // idb
PStringBase<char> Display_RefreshRate_22; // idb
PStringBase<char> Display_SyncToRefresh_22; // idb
const int dword_841BE4; // idb
const int dword_841BE8; // idb
const int INITIAL_MAX_DATA_RATE_66; // idb
const float DEFAULT_VIEW_RADIUS_93; // idb
const long double MIN_QUANTUM_93; // idb
const long double MAX_QUANTUM_93; // idb
PixelFormatDesc stru_841C08; // idb
AC1Legacy::SmartArray<Season *> CPhysics::static_animating_objects; // idb
AC1Legacy::SmartArray<Season *> CPhysics::texture_velocity_gids; // idb
int CTransition::transition_level; // weak
const float flt_841C78; // idb
const float flt_841C7C; // idb
const float flt_841C80; // idb
const float DEFAULT_VIEW_RADIUS_94; // idb
const long double MIN_QUANTUM_94; // idb
const long double MAX_QUANTUM_94; // idb
const int INITIAL_MAX_DATA_RATE_67; // idb
CTransition transit[10]; // idb
unsigned int dword_843B70; // idb
const float flt_843B90; // idb
const float flt_843B94; // idb
const float flt_843B98; // idb
const int INITIAL_MAX_DATA_RATE_68; // idb
const float flt_843BC0; // idb
const float flt_843BC4; // idb
const float flt_843BC8; // idb
const float DEFAULT_VIEW_RADIUS_95; // idb
const long double MIN_QUANTUM_95; // idb
const long double MAX_QUANTUM_95; // idb
unsigned __int32 CPhysicsPart::viewcone_check_object_id; // weak
int CPhysicsPart::selected_object_in_view; // weak
int CPhysicsPart::creature_mode; // weak
unsigned __int32 CPhysicsPart::player_iid; // weak
Vector3 stru_843C08; // idb
PixelFormatDesc stru_843C14; // idb
const float dword_843C4C; // idb
const float flt_843C50; // idb
const float flt_843C54; // idb
const float flt_843C58; // idb
IDClass<_tagDataID,32,0> stru_843C5C; // idb
PStringBase<char> Render_TextureFiltering_22; // idb
PStringBase<char> Render_LandscapeDetailTextures_22; // idb
PStringBase<char> Render_BuildingDetailTextures_22; // idb
PStringBase<char> Render_FieldOfView_22; // idb
PStringBase<char> Render_LandscapeTextureDetail_22; // idb
PStringBase<char> Render_EnvironmentTextureDetail_22; // idb
PStringBase<char> Render_SceneryDrawDistance_22; // idb
PStringBase<char> Render_LandscapeDrawDistance_22; // idb
PStringBase<char> Render_ScreenBrightness_22; // idb
PStringBase<char> Render_AspectRatio_22; // idb
PStringBase<char> Render_DisplayAdapter_22; // idb
PStringBase<char> Render_MaxHardwareClass_22; // idb
PStringBase<char> Render_AutomaticDegrades_22; // idb
PStringBase<char> Render_GraphicsPerformance_22; // idb
PStringBase<char> Render_DegradeDistance_22; // idb
PStringBase<char> Render_MultiPassAlpha_22; // idb
PStringBase<char> Render_TextureFiltering_Choices_22[4]; // idb
PStringBase<char> stru_843CA4; // idb
PStringBase<char> stru_843CA8; // idb
PStringBase<char> stru_843CAC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_22[5]; // idb
PStringBase<char> stru_843CB4; // idb
PStringBase<char> stru_843CB8; // idb
PStringBase<char> stru_843CBC; // idb
PStringBase<char> stru_843CC0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_22[5]; // idb
PStringBase<char> stru_843CC8; // idb
PStringBase<char> stru_843CCC; // idb
PStringBase<char> stru_843CD0; // idb
PStringBase<char> stru_843CD4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_22[3]; // idb
PStringBase<char> stru_843CDC; // idb
PStringBase<char> stru_843CE0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_22[6]; // idb
PStringBase<char> stru_843CE8; // idb
PStringBase<char> stru_843CEC; // idb
PStringBase<char> stru_843CF0; // idb
PStringBase<char> stru_843CF4; // idb
PStringBase<char> stru_843CF8; // idb
PStringBase<char> Render_AspectRatio_Choices_22[3]; // idb
PStringBase<char> stru_843D00; // idb
PStringBase<char> stru_843D04; // idb
PStringBase<char> waveform_None_46; // idb
PStringBase<char> waveform_Speed_46; // idb
PStringBase<char> waveform_Noise_46; // idb
PStringBase<char> waveform_Sine_46; // idb
PStringBase<char> waveform_Square_46; // idb
PStringBase<char> waveform_Bounce_46; // idb
PStringBase<char> waveform_Perlin_46; // idb
PStringBase<char> waveform_Fractal_46; // idb
PStringBase<char> waveform_FrameLoop_46; // idb
const int dword_843D2C; // idb
const int dword_843D30; // idb
const int INITIAL_MAX_DATA_RATE_69; // idb
const float DEFAULT_VIEW_RADIUS_96; // idb
const long double MIN_QUANTUM_96; // idb
const long double MAX_QUANTUM_96; // idb
CObjectMaint *CPhysicsObj::obj_maint; // idb
struct CPhysicsObj *CPhysicsObj::player_object; // weak
const int INITIAL_MAX_DATA_RATE_70; // idb
const float flt_843D78; // idb
const float flt_843D7C; // idb
const float flt_843D80; // idb
IDClass<_tagDataID,32,0> stru_843D84; // idb
const float DEFAULT_VIEW_RADIUS_97; // idb
const long double MIN_QUANTUM_97; // idb
const long double MAX_QUANTUM_97; // idb
PixelFormatDesc stru_843DA0; // idb
PStringBase<char> Sound_SoundDisabled_13; // idb
PStringBase<char> Sound_SoundVolume_13; // idb
PStringBase<char> Sound_AmbientSoundDisabled_13; // idb
PStringBase<char> Sound_AmbientSoundVolume_13; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_13; // idb
PStringBase<char> Sound_InterfaceSoundVolume_13; // idb
PStringBase<char> Sound_SoundFeatures_13; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_13; // idb
PStringBase<char> Sound_SoundFeatures_Choices_13[2]; // idb
PStringBase<char> stru_843DFC; // idb
const float VOL_MIN_DIST_SQ_10; // idb
const long double INV_LOG_OF_2_10; // idb
PStringBase<char> Render_TextureFiltering_23; // idb
PStringBase<char> Render_LandscapeDetailTextures_23; // idb
PStringBase<char> Render_BuildingDetailTextures_23; // idb
PStringBase<char> Render_FieldOfView_23; // idb
PStringBase<char> Render_LandscapeTextureDetail_23; // idb
PStringBase<char> Render_EnvironmentTextureDetail_23; // idb
PStringBase<char> Render_SceneryDrawDistance_23; // idb
PStringBase<char> Render_LandscapeDrawDistance_23; // idb
PStringBase<char> Render_ScreenBrightness_23; // idb
PStringBase<char> Render_AspectRatio_23; // idb
PStringBase<char> Render_DisplayAdapter_23; // idb
PStringBase<char> Render_MaxHardwareClass_23; // idb
PStringBase<char> Render_AutomaticDegrades_23; // idb
PStringBase<char> Render_GraphicsPerformance_23; // idb
PStringBase<char> Render_DegradeDistance_23; // idb
PStringBase<char> Render_MultiPassAlpha_23; // idb
PStringBase<char> Render_TextureFiltering_Choices_23[4]; // idb
PStringBase<char> stru_843E54; // idb
PStringBase<char> stru_843E58; // idb
PStringBase<char> stru_843E5C; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_23[5]; // idb
PStringBase<char> stru_843E64; // idb
PStringBase<char> stru_843E68; // idb
PStringBase<char> stru_843E6C; // idb
PStringBase<char> stru_843E70; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_23[5]; // idb
PStringBase<char> stru_843E78; // idb
PStringBase<char> stru_843E7C; // idb
PStringBase<char> stru_843E80; // idb
PStringBase<char> stru_843E84; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_23[3]; // idb
PStringBase<char> stru_843E8C; // idb
PStringBase<char> stru_843E90; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_23[6]; // idb
PStringBase<char> stru_843E98; // idb
PStringBase<char> stru_843E9C; // idb
PStringBase<char> stru_843EA0; // idb
PStringBase<char> stru_843EA4; // idb
PStringBase<char> stru_843EA8; // idb
PStringBase<char> Render_AspectRatio_Choices_23[3]; // idb
PStringBase<char> stru_843EB0; // idb
PStringBase<char> stru_843EB4; // idb
PStringBase<char> waveform_None_47; // idb
PStringBase<char> waveform_Speed_47; // idb
PStringBase<char> waveform_Noise_47; // idb
PStringBase<char> waveform_Sine_47; // idb
PStringBase<char> waveform_Square_47; // idb
PStringBase<char> waveform_Bounce_47; // idb
PStringBase<char> waveform_Perlin_47; // idb
PStringBase<char> waveform_Fractal_47; // idb
PStringBase<char> waveform_FrameLoop_47; // idb
CSphere dummy_sphere; // idb
CELLARRAY cell_array; // idb
unsigned int _S247_1; // idb
CELLARRAY cell_array_0; // idb
unsigned int _S249_15; // idb
const float flt_843F3C; // idb
const float flt_843F40; // idb
const float flt_843F44; // idb
const float flt_843F6C; // idb
const float flt_843F70; // idb
const float flt_843F74; // idb
IDClass<_tagDataID,32,0> stru_843F78; // idb
const float DEFAULT_VIEW_RADIUS_98; // idb
const long double MIN_QUANTUM_98; // idb
const long double MAX_QUANTUM_98; // idb
CSphere default_sorting_sphere; // idb
unsigned int _S118_54; // idb
const float flt_843FC4; // idb
const float flt_843FC8; // idb
const float flt_843FCC; // idb
IDClass<_tagDataID,32,0> stru_843FD0; // idb
const int dword_843FD4; // idb
const int dword_843FD8; // idb
const int INITIAL_MAX_DATA_RATE_71; // idb
const float flt_843FE0; // idb
const long double dbl_843FE8; // idb
const long double dbl_843FF0; // idb
const float flt_844014; // idb
const float flt_844018; // idb
const float flt_84401C; // idb
const int INITIAL_MAX_DATA_RATE_72; // idb
const float flt_844028; // idb
const long double dbl_844030; // idb
const long double dbl_844038; // idb
const float flt_84406C; // idb
const float flt_844070; // idb
const float flt_844074; // idb
const int INITIAL_MAX_DATA_RATE_73; // idb
const float flt_844080; // idb
const long double dbl_844088; // idb
const long double dbl_844090; // idb
const int INITIAL_MAX_DATA_RATE_74; // idb
const float flt_8440B8; // idb
const float flt_8440BC; // idb
const float flt_8440C0; // idb
const float flt_8440C8; // idb
const long double dbl_8440D0; // idb
const long double dbl_8440D8; // idb
IDClass<_tagDataID,32,0> stru_844110; // idb
const int INITIAL_MAX_DATA_RATE_75; // idb
const float flt_844138; // idb
const float flt_84413C; // idb
const float flt_844140; // idb
const float flt_844148; // idb
const long double dbl_844150; // idb
const long double dbl_844158; // idb
const int INITIAL_MAX_DATA_RATE_76; // idb
const float flt_844180; // idb
const float flt_844184; // idb
const float flt_844188; // idb
const float flt_844190; // idb
const long double dbl_844198; // idb
const long double dbl_8441A0; // idb
const float flt_8441B8; // idb
const float flt_8441BC; // idb
const float flt_8441C0; // idb
IDClass<_tagDataID,32,0> stru_8441E4; // idb
const float dword_8441E8; // idb
const float flt_8441EC; // idb
const float flt_8441F0; // idb
const float flt_8441F4; // idb
const int dword_8441F8; // idb
const int dword_8441FC; // idb
const int INITIAL_MAX_DATA_RATE_77; // idb
const float flt_844204; // idb
const long double dbl_844208; // idb
const long double dbl_844210; // idb
PixelFormatDesc stru_844234; // idb
IDClass<_tagDataID,32,0> stru_84426C; // idb
const float dword_844270; // idb
const float flt_844274; // idb
const float flt_844278; // idb
const float flt_84427C; // idb
const float flt_844280; // idb
const long double dbl_844288; // idb
const long double dbl_844290; // idb
const int dword_844298; // idb
const int dword_84429C; // idb
const int INITIAL_MAX_DATA_RATE_78; // idb
const float flt_8442B8; // idb
const float flt_8442BC; // idb
const float flt_8442C0; // idb
IDClass<_tagDataID,32,0> stru_8442C4; // idb
const float flt_8442C8; // idb
const long double dbl_8442D0; // idb
const long double dbl_8442D8; // idb
int degrades_disabled; // weak
PixelFormatDesc stru_844300; // idb
const float dword_844338; // idb
const float flt_84433C; // idb
const float flt_844340; // idb
const float flt_844344; // idb
IDClass<_tagDataID,32,0> stru_844348; // idb
PStringBase<char> Render_TextureFiltering_24; // idb
PStringBase<char> Render_LandscapeDetailTextures_24; // idb
PStringBase<char> Render_BuildingDetailTextures_24; // idb
PStringBase<char> Render_FieldOfView_24; // idb
PStringBase<char> Render_LandscapeTextureDetail_24; // idb
PStringBase<char> Render_EnvironmentTextureDetail_24; // idb
PStringBase<char> Render_SceneryDrawDistance_24; // idb
PStringBase<char> Render_LandscapeDrawDistance_24; // idb
PStringBase<char> Render_ScreenBrightness_24; // idb
PStringBase<char> Render_AspectRatio_24; // idb
PStringBase<char> Render_DisplayAdapter_24; // idb
PStringBase<char> Render_MaxHardwareClass_24; // idb
PStringBase<char> Render_AutomaticDegrades_24; // idb
PStringBase<char> Render_GraphicsPerformance_24; // idb
PStringBase<char> Render_DegradeDistance_24; // idb
PStringBase<char> Render_MultiPassAlpha_24; // idb
PStringBase<char> Render_TextureFiltering_Choices_24[4]; // idb
PStringBase<char> stru_844390; // idb
PStringBase<char> stru_844394; // idb
PStringBase<char> stru_844398; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_24[5]; // idb
PStringBase<char> stru_8443A0; // idb
PStringBase<char> stru_8443A4; // idb
PStringBase<char> stru_8443A8; // idb
PStringBase<char> stru_8443AC; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_24[5]; // idb
PStringBase<char> stru_8443B4; // idb
PStringBase<char> stru_8443B8; // idb
PStringBase<char> stru_8443BC; // idb
PStringBase<char> stru_8443C0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_24[3]; // idb
PStringBase<char> stru_8443C8; // idb
PStringBase<char> stru_8443CC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_24[6]; // idb
PStringBase<char> stru_8443D4; // idb
PStringBase<char> stru_8443D8; // idb
PStringBase<char> stru_8443DC; // idb
PStringBase<char> stru_8443E0; // idb
PStringBase<char> stru_8443E4; // idb
PStringBase<char> Render_AspectRatio_Choices_24[3]; // idb
PStringBase<char> stru_8443EC; // idb
PStringBase<char> stru_8443F0; // idb
PStringBase<char> waveform_None_48; // idb
PStringBase<char> waveform_Speed_48; // idb
PStringBase<char> waveform_Noise_48; // idb
PStringBase<char> waveform_Sine_48; // idb
PStringBase<char> waveform_Square_48; // idb
PStringBase<char> waveform_Bounce_48; // idb
PStringBase<char> waveform_Perlin_48; // idb
PStringBase<char> waveform_Fractal_48; // idb
PStringBase<char> waveform_FrameLoop_48; // idb
const float flt_844434; // idb
const float flt_844438; // idb
const float flt_84443C; // idb
const int INITIAL_MAX_DATA_RATE_79; // idb
const float flt_844448; // idb
const long double dbl_844450; // idb
const long double dbl_844458; // idb
IDClass<_tagDataID,32,0> stru_844470; // idb
const float flt_844494; // idb
const float flt_844498; // idb
const float flt_84449C; // idb
IDClass<_tagDataID,32,0> stru_8444A0; // idb
const float flt_8444A4; // idb
const long double dbl_8444A8; // idb
const long double dbl_8444B0; // idb
IDClass<_tagDataID,32,0> stru_8444C8; // idb
IDClass<_tagDataID,32,0> stru_8444D0; // idb
int MovementParameters::set_moveto_flags::_2::normal_bitfield; // weak
const float flt_84450C; // idb
const float flt_844510; // idb
const float flt_844514; // idb
const int INITIAL_MAX_DATA_RATE_80; // idb
const float flt_844520; // idb
const long double dbl_844528; // idb
const long double dbl_844530; // idb
const int INITIAL_MAX_DATA_RATE_81; // idb
const float flt_84455C; // idb
const float flt_844560; // idb
const float flt_844564; // idb
const float flt_844568; // idb
const long double dbl_844570; // idb
const long double dbl_844578; // idb
IDClass<_tagDataID,32,0> stru_844590; // idb
IDClass<_tagDataID,32,0> stru_8445C4; // idb
const int INITIAL_MAX_DATA_RATE_82; // idb
const float flt_8445CC; // idb
const float flt_8445D0; // idb
const float flt_8445D4; // idb
const float flt_8445D8; // idb
const long double dbl_8445E0; // idb
const long double dbl_8445E8; // idb
PStringBase<char> Sound_SoundDisabled_14; // idb
PStringBase<char> Sound_SoundVolume_14; // idb
PStringBase<char> Sound_AmbientSoundDisabled_14; // idb
PStringBase<char> Sound_AmbientSoundVolume_14; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_14; // idb
PStringBase<char> Sound_InterfaceSoundVolume_14; // idb
PStringBase<char> Sound_SoundFeatures_14; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_14; // idb
PStringBase<char> Sound_SoundFeatures_Choices_14[2]; // idb
PStringBase<char> stru_844614; // idb
const float VOL_MIN_DIST_SQ_11; // idb
const long double INV_LOG_OF_2_11; // idb
const float flt_844644; // idb
const float flt_844648; // idb
const float flt_84464C; // idb
const int INITIAL_MAX_DATA_RATE_83; // idb
const float flt_844658; // idb
const long double dbl_844660; // idb
const long double dbl_844668; // idb
const int INITIAL_MAX_DATA_RATE_84; // idb
const float flt_844690; // idb
const float flt_844694; // idb
const float flt_844698; // idb
const float flt_8446A0; // idb
const long double dbl_8446A8; // idb
const long double dbl_8446B0; // idb
const float flt_8446C8; // idb
const float flt_8446CC; // idb
const float flt_8446D0; // idb
CObjectMaint *CObjCell::obj_maint; // idb
LScape *CObjCell::landscape; // idb
PixelFormatDesc stru_8446FC; // idb
const float dword_844734; // idb
const float flt_844738; // idb
const float flt_84473C; // idb
const float flt_844740; // idb
IDClass<_tagDataID,32,0> stru_844744; // idb
PStringBase<char> Render_TextureFiltering_25; // idb
PStringBase<char> Render_LandscapeDetailTextures_25; // idb
PStringBase<char> Render_BuildingDetailTextures_25; // idb
PStringBase<char> Render_FieldOfView_25; // idb
PStringBase<char> Render_LandscapeTextureDetail_25; // idb
PStringBase<char> Render_EnvironmentTextureDetail_25; // idb
PStringBase<char> Render_SceneryDrawDistance_25; // idb
PStringBase<char> Render_LandscapeDrawDistance_25; // idb
PStringBase<char> Render_ScreenBrightness_25; // idb
PStringBase<char> Render_AspectRatio_25; // idb
PStringBase<char> Render_DisplayAdapter_25; // idb
PStringBase<char> Render_MaxHardwareClass_25; // idb
PStringBase<char> Render_AutomaticDegrades_25; // idb
PStringBase<char> Render_GraphicsPerformance_25; // idb
PStringBase<char> Render_DegradeDistance_25; // idb
PStringBase<char> Render_MultiPassAlpha_25; // idb
PStringBase<char> Render_TextureFiltering_Choices_25[4]; // idb
PStringBase<char> stru_84478C; // idb
PStringBase<char> stru_844790; // idb
PStringBase<char> stru_844794; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_25[5]; // idb
PStringBase<char> stru_84479C; // idb
PStringBase<char> stru_8447A0; // idb
PStringBase<char> stru_8447A4; // idb
PStringBase<char> stru_8447A8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_25[5]; // idb
PStringBase<char> stru_8447B0; // idb
PStringBase<char> stru_8447B4; // idb
PStringBase<char> stru_8447B8; // idb
PStringBase<char> stru_8447BC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_25[3]; // idb
PStringBase<char> stru_8447C4; // idb
PStringBase<char> stru_8447C8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_25[6]; // idb
PStringBase<char> stru_8447D0; // idb
PStringBase<char> stru_8447D4; // idb
PStringBase<char> stru_8447D8; // idb
PStringBase<char> stru_8447DC; // idb
PStringBase<char> stru_8447E0; // idb
PStringBase<char> Render_AspectRatio_Choices_25[3]; // idb
PStringBase<char> stru_8447E8; // idb
PStringBase<char> stru_8447EC; // idb
PStringBase<char> waveform_None_49; // idb
PStringBase<char> waveform_Speed_49; // idb
PStringBase<char> waveform_Noise_49; // idb
PStringBase<char> waveform_Sine_49; // idb
PStringBase<char> waveform_Square_49; // idb
PStringBase<char> waveform_Bounce_49; // idb
PStringBase<char> waveform_Perlin_49; // idb
PStringBase<char> waveform_Fractal_49; // idb
PStringBase<char> waveform_FrameLoop_49; // idb
const int dword_844814; // idb
const int dword_844818; // idb
const int INITIAL_MAX_DATA_RATE_85; // idb
const float flt_844820; // idb
const long double dbl_844828; // idb
const long double dbl_844830; // idb
CSphere sphere[10]; // idb
unsigned int _S213_35; // idb
const int INITIAL_MAX_DATA_RATE_86; // idb
const float flt_844900; // idb
const float flt_844904; // idb
const float flt_844908; // idb
const float flt_844910; // idb
const long double dbl_844918; // idb
const long double dbl_844920; // idb
PStringBase<char> Display_Resolution_23; // idb
PStringBase<char> Display_FullScreen_23; // idb
PStringBase<char> Display_RefreshRate_23; // idb
PStringBase<char> Display_SyncToRefresh_23; // idb
PixelFormatDesc stru_844938; // idb
PStringBase<char> Render_TextureFiltering_26; // idb
PStringBase<char> Render_LandscapeDetailTextures_26; // idb
PStringBase<char> Render_BuildingDetailTextures_26; // idb
PStringBase<char> Render_FieldOfView_26; // idb
PStringBase<char> Render_LandscapeTextureDetail_26; // idb
PStringBase<char> Render_EnvironmentTextureDetail_26; // idb
PStringBase<char> Render_SceneryDrawDistance_26; // idb
PStringBase<char> Render_LandscapeDrawDistance_26; // idb
PStringBase<char> Render_ScreenBrightness_26; // idb
PStringBase<char> Render_AspectRatio_26; // idb
PStringBase<char> Render_DisplayAdapter_26; // idb
PStringBase<char> Render_MaxHardwareClass_26; // idb
PStringBase<char> Render_AutomaticDegrades_26; // idb
PStringBase<char> Render_GraphicsPerformance_26; // idb
PStringBase<char> Render_DegradeDistance_26; // idb
PStringBase<char> Render_MultiPassAlpha_26; // idb
PStringBase<char> Render_TextureFiltering_Choices_26[4]; // idb
PStringBase<char> stru_8449B4; // idb
PStringBase<char> stru_8449B8; // idb
PStringBase<char> stru_8449BC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_26[5]; // idb
PStringBase<char> stru_8449C4; // idb
PStringBase<char> stru_8449C8; // idb
PStringBase<char> stru_8449CC; // idb
PStringBase<char> stru_8449D0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_26[5]; // idb
PStringBase<char> stru_8449D8; // idb
PStringBase<char> stru_8449DC; // idb
PStringBase<char> stru_8449E0; // idb
PStringBase<char> stru_8449E4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_26[3]; // idb
PStringBase<char> stru_8449EC; // idb
PStringBase<char> stru_8449F0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_26[6]; // idb
PStringBase<char> stru_8449F8; // idb
PStringBase<char> stru_8449FC; // idb
PStringBase<char> stru_844A00; // idb
PStringBase<char> stru_844A04; // idb
PStringBase<char> stru_844A08; // idb
PStringBase<char> Render_AspectRatio_Choices_26[3]; // idb
PStringBase<char> stru_844A10; // idb
PStringBase<char> stru_844A14; // idb
PStringBase<char> waveform_None_50; // idb
PStringBase<char> waveform_Speed_50; // idb
PStringBase<char> waveform_Noise_50; // idb
PStringBase<char> waveform_Sine_50; // idb
PStringBase<char> waveform_Square_50; // idb
PStringBase<char> waveform_Bounce_50; // idb
PStringBase<char> waveform_Perlin_50; // idb
PStringBase<char> waveform_Fractal_50; // idb
PStringBase<char> waveform_FrameLoop_50; // idb
unsigned __int32 lcat_BlockAndCellLoading; // weak
const int INITIAL_MAX_DATA_RATE_87; // idb
const float flt_844A60; // idb
const float flt_844A64; // idb
const float flt_844A68; // idb
const float flt_844A70; // idb
const long double dbl_844A78; // idb
const long double dbl_844A80; // idb
const float flt_844AA4; // idb
const float flt_844AA8; // idb
const float flt_844AAC; // idb
IDClass<_tagDataID,32,0> stru_844AB0; // idb
const float flt_844AB4; // idb
const long double dbl_844AB8; // idb
const long double dbl_844AC0; // idb
const float flt_844AE8; // idb
const float flt_844AEC; // idb
const float flt_844AF0; // idb
IDClass<_tagDataID,32,0> stru_844AF4; // idb
const float flt_844AF8; // idb
const long double dbl_844B00; // idb
const long double dbl_844B08; // idb
const int INITIAL_MAX_DATA_RATE_88; // idb
PixelFormatDesc stru_844B14; // idb
PStringBase<char> Sound_SoundDisabled_15; // idb
PStringBase<char> Sound_SoundVolume_15; // idb
PStringBase<char> Sound_AmbientSoundDisabled_15; // idb
PStringBase<char> Sound_AmbientSoundVolume_15; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_15; // idb
PStringBase<char> Sound_InterfaceSoundVolume_15; // idb
PStringBase<char> Sound_SoundFeatures_15; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_15; // idb
PStringBase<char> Sound_SoundFeatures_Choices_15[2]; // idb
PStringBase<char> stru_844B70; // idb
const float VOL_MIN_DIST_SQ_12; // idb
const long double INV_LOG_OF_2_12; // idb
Position obj_pos; // idb
_UNKNOWN unk_844B84; // weak
Frame stru_844B88; // idb
Frame obj_frame; // idb
unsigned int _S151_8; // idb
IDClass<_tagDataID,32,0> stru_844C28; // idb
PixelFormatDesc stru_844C2C; // idb
const float flt_844C84; // idb
const float flt_844C88; // idb
const float flt_844C8C; // idb
const float flt_844C94; // idb
const long double dbl_844C98; // idb
const long double dbl_844CA0; // idb
struct CVec2Duv *CLandBlockStruct::land_uvs; // weak
int dword_844CAC; // weak
int dword_844CB0; // weak
int dword_844CB4; // weak
int dword_844CB8; // weak
int dword_844CBC; // weak
int dword_844CC0; // weak
int dword_844CC4; // weak
const float flt_844CE8; // idb
const float flt_844CEC; // idb
const float flt_844CF0; // idb
PixelFormatDesc stru_844CF4; // idb
PStringBase<char> Render_TextureFiltering_27; // idb
PStringBase<char> Render_LandscapeDetailTextures_27; // idb
PStringBase<char> Render_BuildingDetailTextures_27; // idb
PStringBase<char> Render_FieldOfView_27; // idb
PStringBase<char> Render_LandscapeTextureDetail_27; // idb
PStringBase<char> Render_EnvironmentTextureDetail_27; // idb
PStringBase<char> Render_SceneryDrawDistance_27; // idb
PStringBase<char> Render_LandscapeDrawDistance_27; // idb
PStringBase<char> Render_ScreenBrightness_27; // idb
PStringBase<char> Render_AspectRatio_27; // idb
PStringBase<char> Render_DisplayAdapter_27; // idb
PStringBase<char> Render_MaxHardwareClass_27; // idb
PStringBase<char> Render_AutomaticDegrades_27; // idb
PStringBase<char> Render_GraphicsPerformance_27; // idb
PStringBase<char> Render_DegradeDistance_27; // idb
PStringBase<char> Render_MultiPassAlpha_27; // idb
PStringBase<char> Render_TextureFiltering_Choices_27[4]; // idb
PStringBase<char> stru_844D70; // idb
PStringBase<char> stru_844D74; // idb
PStringBase<char> stru_844D78; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_27[5]; // idb
PStringBase<char> stru_844D80; // idb
PStringBase<char> stru_844D84; // idb
PStringBase<char> stru_844D88; // idb
PStringBase<char> stru_844D8C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_27[5]; // idb
PStringBase<char> stru_844D94; // idb
PStringBase<char> stru_844D98; // idb
PStringBase<char> stru_844D9C; // idb
PStringBase<char> stru_844DA0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_27[3]; // idb
PStringBase<char> stru_844DA8; // idb
PStringBase<char> stru_844DAC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_27[6]; // idb
PStringBase<char> stru_844DB4; // idb
PStringBase<char> stru_844DB8; // idb
PStringBase<char> stru_844DBC; // idb
PStringBase<char> stru_844DC0; // idb
PStringBase<char> stru_844DC4; // idb
PStringBase<char> Render_AspectRatio_Choices_27[3]; // idb
PStringBase<char> stru_844DCC; // idb
PStringBase<char> stru_844DD0; // idb
PStringBase<char> waveform_None_51; // idb
PStringBase<char> waveform_Speed_51; // idb
PStringBase<char> waveform_Noise_51; // idb
PStringBase<char> waveform_Sine_51; // idb
PStringBase<char> waveform_Square_51; // idb
PStringBase<char> waveform_Bounce_51; // idb
PStringBase<char> waveform_Perlin_51; // idb
PStringBase<char> waveform_Fractal_51; // idb
PStringBase<char> waveform_FrameLoop_51; // idb
const int dword_844DF8; // idb
const int dword_844DFC; // idb
const int INITIAL_MAX_DATA_RATE_89; // idb
const float flt_844E04; // idb
const long double dbl_844E08; // idb
const long double dbl_844E10; // idb
const int dword_844E38; // idb
const int dword_844E3C; // idb
const int INITIAL_MAX_DATA_RATE_90; // idb
const float dword_844E44; // idb
const float flt_844E48; // idb
const float flt_844E4C; // idb
const float flt_844E50; // idb
const float flt_844E54; // idb
const long double dbl_844E58; // idb
const long double dbl_844E60; // idb
const int INITIAL_MAX_DATA_RATE_91; // idb
const float flt_844E88; // idb
const float flt_844E8C; // idb
const float flt_844E90; // idb
const float flt_844E98; // idb
const long double dbl_844EA0; // idb
const long double dbl_844EA8; // idb
AC1Legacy::Vector3 stru_844EB4; // idb
IDClass<_tagDataID,32,0> AnID; // idb
PixelFormatDesc stru_844ED0; // idb
const int dword_844F08; // idb
const int dword_844F0C; // idb
const int INITIAL_MAX_DATA_RATE_92; // idb
const float dword_844F14; // idb
const float flt_844F18; // idb
const float flt_844F1C; // idb
const float flt_844F20; // idb
const float flt_844F24; // idb
const long double dbl_844F28; // idb
const long double dbl_844F30; // idb
PStringBase<char> Render_TextureFiltering_28; // idb
PStringBase<char> Render_LandscapeDetailTextures_28; // idb
PStringBase<char> Render_BuildingDetailTextures_28; // idb
PStringBase<char> Render_FieldOfView_28; // idb
PStringBase<char> Render_LandscapeTextureDetail_28; // idb
PStringBase<char> Render_EnvironmentTextureDetail_28; // idb
PStringBase<char> Render_SceneryDrawDistance_28; // idb
PStringBase<char> Render_LandscapeDrawDistance_28; // idb
PStringBase<char> Render_ScreenBrightness_28; // idb
PStringBase<char> Render_AspectRatio_28; // idb
PStringBase<char> Render_DisplayAdapter_28; // idb
PStringBase<char> Render_MaxHardwareClass_28; // idb
PStringBase<char> Render_AutomaticDegrades_28; // idb
PStringBase<char> Render_GraphicsPerformance_28; // idb
PStringBase<char> Render_DegradeDistance_28; // idb
PStringBase<char> Render_MultiPassAlpha_28; // idb
PStringBase<char> Render_TextureFiltering_Choices_28[4]; // idb
PStringBase<char> stru_844F7C; // idb
PStringBase<char> stru_844F80; // idb
PStringBase<char> stru_844F84; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_28[5]; // idb
PStringBase<char> stru_844F8C; // idb
PStringBase<char> stru_844F90; // idb
PStringBase<char> stru_844F94; // idb
PStringBase<char> stru_844F98; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_28[5]; // idb
PStringBase<char> stru_844FA0; // idb
PStringBase<char> stru_844FA4; // idb
PStringBase<char> stru_844FA8; // idb
PStringBase<char> stru_844FAC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_28[3]; // idb
PStringBase<char> stru_844FB4; // idb
PStringBase<char> stru_844FB8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_28[6]; // idb
PStringBase<char> stru_844FC0; // idb
PStringBase<char> stru_844FC4; // idb
PStringBase<char> stru_844FC8; // idb
PStringBase<char> stru_844FCC; // idb
PStringBase<char> stru_844FD0; // idb
PStringBase<char> Render_AspectRatio_Choices_28[3]; // idb
PStringBase<char> stru_844FD8; // idb
PStringBase<char> stru_844FDC; // idb
PStringBase<char> waveform_None_52; // idb
PStringBase<char> waveform_Speed_52; // idb
PStringBase<char> waveform_Noise_52; // idb
PStringBase<char> waveform_Sine_52; // idb
PStringBase<char> waveform_Square_52; // idb
PStringBase<char> waveform_Bounce_52; // idb
PStringBase<char> waveform_Perlin_52; // idb
PStringBase<char> waveform_Fractal_52; // idb
PStringBase<char> waveform_FrameLoop_52; // idb
PStringBase<char> Display_Resolution_24; // idb
PStringBase<char> Display_FullScreen_24; // idb
PStringBase<char> Display_RefreshRate_24; // idb
PStringBase<char> Display_SyncToRefresh_24; // idb
IDClass<_tagDataID,32,0> stru_845060; // idb
PixelFormatDesc stru_845064; // idb
const float dword_84509C; // idb
const float flt_8450A0; // idb
const float flt_8450A4; // idb
const float flt_8450A8; // idb
const float flt_8450CC; // idb
const float flt_8450D0; // idb
const float flt_8450D4; // idb
const int INITIAL_MAX_DATA_RATE_93; // idb
const float flt_8450E0; // idb
const long double dbl_8450E8; // idb
const long double dbl_8450F0; // idb
struct CVertexArray *CPolygon::pack_verts; // weak
const float flt_845118; // idb
const float flt_84511C; // idb
const float flt_845120; // idb
const int INITIAL_MAX_DATA_RATE_94; // idb
const float flt_845148; // idb
const float flt_84514C; // idb
const float flt_845150; // idb
const float flt_845158; // idb
const long double dbl_845160; // idb
const long double dbl_845168; // idb
PixelFormatDesc stru_845170; // idb
PStringBase<char> Render_TextureFiltering_29; // idb
PStringBase<char> Render_LandscapeDetailTextures_29; // idb
PStringBase<char> Render_BuildingDetailTextures_29; // idb
PStringBase<char> Render_FieldOfView_29; // idb
PStringBase<char> Render_LandscapeTextureDetail_29; // idb
PStringBase<char> Render_EnvironmentTextureDetail_29; // idb
PStringBase<char> Render_SceneryDrawDistance_29; // idb
PStringBase<char> Render_LandscapeDrawDistance_29; // idb
PStringBase<char> Render_ScreenBrightness_29; // idb
PStringBase<char> Render_AspectRatio_29; // idb
PStringBase<char> Render_DisplayAdapter_29; // idb
PStringBase<char> Render_MaxHardwareClass_29; // idb
PStringBase<char> Render_AutomaticDegrades_29; // idb
PStringBase<char> Render_GraphicsPerformance_29; // idb
PStringBase<char> Render_DegradeDistance_29; // idb
PStringBase<char> Render_MultiPassAlpha_29; // idb
PStringBase<char> Render_TextureFiltering_Choices_29[4]; // idb
PStringBase<char> stru_8451EC; // idb
PStringBase<char> stru_8451F0; // idb
PStringBase<char> stru_8451F4; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_29[5]; // idb
PStringBase<char> stru_8451FC; // idb
PStringBase<char> stru_845200; // idb
PStringBase<char> stru_845204; // idb
PStringBase<char> stru_845208; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_29[5]; // idb
PStringBase<char> stru_845210; // idb
PStringBase<char> stru_845214; // idb
PStringBase<char> stru_845218; // idb
PStringBase<char> stru_84521C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_29[3]; // idb
PStringBase<char> stru_845224; // idb
PStringBase<char> stru_845228; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_29[6]; // idb
PStringBase<char> stru_845230; // idb
PStringBase<char> stru_845234; // idb
PStringBase<char> stru_845238; // idb
PStringBase<char> stru_84523C; // idb
PStringBase<char> stru_845240; // idb
PStringBase<char> Render_AspectRatio_Choices_29[3]; // idb
PStringBase<char> stru_845248; // idb
PStringBase<char> stru_84524C; // idb
PStringBase<char> waveform_None_53; // idb
PStringBase<char> waveform_Speed_53; // idb
PStringBase<char> waveform_Noise_53; // idb
PStringBase<char> waveform_Sine_53; // idb
PStringBase<char> waveform_Square_53; // idb
PStringBase<char> waveform_Bounce_53; // idb
PStringBase<char> waveform_Perlin_53; // idb
PStringBase<char> waveform_Fractal_53; // idb
PStringBase<char> waveform_FrameLoop_53; // idb
const float flt_845294; // idb
const float flt_845298; // idb
const float flt_84529C; // idb
const int INITIAL_MAX_DATA_RATE_95; // idb
const float flt_8452A8; // idb
const long double dbl_8452B0; // idb
const long double dbl_8452B8; // idb
const float dword_8452F8; // idb
const float flt_8452FC; // idb
const float flt_845300; // idb
const float flt_845304; // idb
const float flt_845308; // idb
const long double dbl_845310; // idb
const long double dbl_845318; // idb
const float dword_845340; // idb
const float flt_845344; // idb
const float flt_845348; // idb
const float flt_84534C; // idb
const float flt_845350; // idb
const long double dbl_845358; // idb
const long double dbl_845360; // idb
struct CPolygon *BSPNODE::pack_poly; // weak
enum BSPTreeType BSPNODE::pack_tree_type; // weak
Vector3 stru_84538C; // idb
PixelFormatDesc stru_845398; // idb
const float dword_8453D0; // idb
const float flt_8453D4; // idb
const float flt_8453D8; // idb
const float flt_8453DC; // idb
PStringBase<char> Render_TextureFiltering_30; // idb
PStringBase<char> Render_LandscapeDetailTextures_30; // idb
PStringBase<char> Render_BuildingDetailTextures_30; // idb
PStringBase<char> Render_FieldOfView_30; // idb
PStringBase<char> Render_LandscapeTextureDetail_30; // idb
PStringBase<char> Render_EnvironmentTextureDetail_30; // idb
PStringBase<char> Render_SceneryDrawDistance_30; // idb
PStringBase<char> Render_LandscapeDrawDistance_30; // idb
PStringBase<char> Render_ScreenBrightness_30; // idb
PStringBase<char> Render_AspectRatio_30; // idb
PStringBase<char> Render_DisplayAdapter_30; // idb
PStringBase<char> Render_MaxHardwareClass_30; // idb
PStringBase<char> Render_AutomaticDegrades_30; // idb
PStringBase<char> Render_GraphicsPerformance_30; // idb
PStringBase<char> Render_DegradeDistance_30; // idb
PStringBase<char> Render_MultiPassAlpha_30; // idb
PStringBase<char> Render_TextureFiltering_Choices_30[4]; // idb
PStringBase<char> stru_845428; // idb
PStringBase<char> stru_84542C; // idb
PStringBase<char> stru_845430; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_30[5]; // idb
PStringBase<char> stru_845438; // idb
PStringBase<char> stru_84543C; // idb
PStringBase<char> stru_845440; // idb
PStringBase<char> stru_845444; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_30[5]; // idb
PStringBase<char> stru_84544C; // idb
PStringBase<char> stru_845450; // idb
PStringBase<char> stru_845454; // idb
PStringBase<char> stru_845458; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_30[3]; // idb
PStringBase<char> stru_845460; // idb
PStringBase<char> stru_845464; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_30[6]; // idb
PStringBase<char> stru_84546C; // idb
PStringBase<char> stru_845470; // idb
PStringBase<char> stru_845474; // idb
PStringBase<char> stru_845478; // idb
PStringBase<char> stru_84547C; // idb
PStringBase<char> Render_AspectRatio_Choices_30[3]; // idb
PStringBase<char> stru_845484; // idb
PStringBase<char> stru_845488; // idb
PStringBase<char> waveform_None_54; // idb
PStringBase<char> waveform_Speed_54; // idb
PStringBase<char> waveform_Noise_54; // idb
PStringBase<char> waveform_Sine_54; // idb
PStringBase<char> waveform_Square_54; // idb
PStringBase<char> waveform_Bounce_54; // idb
PStringBase<char> waveform_Perlin_54; // idb
PStringBase<char> waveform_Fractal_54; // idb
PStringBase<char> waveform_FrameLoop_54; // idb
PixelFormatDesc stru_8454CC; // idb
const float dword_845504; // idb
const float flt_845508; // idb
const float flt_84550C; // idb
const float flt_845510; // idb
PStringBase<char> Render_TextureFiltering_31; // idb
PStringBase<char> Render_LandscapeDetailTextures_31; // idb
PStringBase<char> Render_BuildingDetailTextures_31; // idb
PStringBase<char> Render_FieldOfView_31; // idb
PStringBase<char> Render_LandscapeTextureDetail_31; // idb
PStringBase<char> Render_EnvironmentTextureDetail_31; // idb
PStringBase<char> Render_SceneryDrawDistance_31; // idb
PStringBase<char> Render_LandscapeDrawDistance_31; // idb
PStringBase<char> Render_ScreenBrightness_31; // idb
PStringBase<char> Render_AspectRatio_31; // idb
PStringBase<char> Render_DisplayAdapter_31; // idb
PStringBase<char> Render_MaxHardwareClass_31; // idb
PStringBase<char> Render_AutomaticDegrades_31; // idb
PStringBase<char> Render_GraphicsPerformance_31; // idb
PStringBase<char> Render_DegradeDistance_31; // idb
PStringBase<char> Render_MultiPassAlpha_31; // idb
PStringBase<char> Render_TextureFiltering_Choices_31[4]; // idb
PStringBase<char> stru_84555C; // idb
PStringBase<char> stru_845560; // idb
PStringBase<char> stru_845564; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_31[5]; // idb
PStringBase<char> stru_84556C; // idb
PStringBase<char> stru_845570; // idb
PStringBase<char> stru_845574; // idb
PStringBase<char> stru_845578; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_31[5]; // idb
PStringBase<char> stru_845580; // idb
PStringBase<char> stru_845584; // idb
PStringBase<char> stru_845588; // idb
PStringBase<char> stru_84558C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_31[3]; // idb
PStringBase<char> stru_845594; // idb
PStringBase<char> stru_845598; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_31[6]; // idb
PStringBase<char> stru_8455A0; // idb
PStringBase<char> stru_8455A4; // idb
PStringBase<char> stru_8455A8; // idb
PStringBase<char> stru_8455AC; // idb
PStringBase<char> stru_8455B0; // idb
PStringBase<char> Render_AspectRatio_Choices_31[3]; // idb
PStringBase<char> stru_8455B8; // idb
PStringBase<char> stru_8455BC; // idb
PStringBase<char> waveform_None_55; // idb
PStringBase<char> waveform_Speed_55; // idb
PStringBase<char> waveform_Noise_55; // idb
PStringBase<char> waveform_Sine_55; // idb
PStringBase<char> waveform_Square_55; // idb
PStringBase<char> waveform_Bounce_55; // idb
PStringBase<char> waveform_Perlin_55; // idb
PStringBase<char> waveform_Fractal_55; // idb
PStringBase<char> waveform_FrameLoop_55; // idb
const float flt_8455E4; // idb
const long double dbl_8455E8; // idb
const long double dbl_8455F0; // idb
const int dword_8455F8; // idb
const int dword_8455FC; // idb
const int INITIAL_MAX_DATA_RATE_96; // idb
PixelFormatDesc stru_845620; // idb
const float dword_845658; // idb
const float flt_84565C; // idb
const float flt_845660; // idb
const float flt_845664; // idb
PStringBase<char> Render_TextureFiltering_32; // idb
PStringBase<char> Render_LandscapeDetailTextures_32; // idb
PStringBase<char> Render_BuildingDetailTextures_32; // idb
PStringBase<char> Render_FieldOfView_32; // idb
PStringBase<char> Render_LandscapeTextureDetail_32; // idb
PStringBase<char> Render_EnvironmentTextureDetail_32; // idb
PStringBase<char> Render_SceneryDrawDistance_32; // idb
PStringBase<char> Render_LandscapeDrawDistance_32; // idb
PStringBase<char> Render_ScreenBrightness_32; // idb
PStringBase<char> Render_AspectRatio_32; // idb
PStringBase<char> Render_DisplayAdapter_32; // idb
PStringBase<char> Render_MaxHardwareClass_32; // idb
PStringBase<char> Render_AutomaticDegrades_32; // idb
PStringBase<char> Render_GraphicsPerformance_32; // idb
PStringBase<char> Render_DegradeDistance_32; // idb
PStringBase<char> Render_MultiPassAlpha_32; // idb
PStringBase<char> Render_TextureFiltering_Choices_32[4]; // idb
PStringBase<char> stru_8456B0; // idb
PStringBase<char> stru_8456B4; // idb
PStringBase<char> stru_8456B8; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_32[5]; // idb
PStringBase<char> stru_8456C0; // idb
PStringBase<char> stru_8456C4; // idb
PStringBase<char> stru_8456C8; // idb
PStringBase<char> stru_8456CC; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_32[5]; // idb
PStringBase<char> stru_8456D4; // idb
PStringBase<char> stru_8456D8; // idb
PStringBase<char> stru_8456DC; // idb
PStringBase<char> stru_8456E0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_32[3]; // idb
PStringBase<char> stru_8456E8; // idb
PStringBase<char> stru_8456EC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_32[6]; // idb
PStringBase<char> stru_8456F4; // idb
PStringBase<char> stru_8456F8; // idb
PStringBase<char> stru_8456FC; // idb
PStringBase<char> stru_845700; // idb
PStringBase<char> stru_845704; // idb
PStringBase<char> Render_AspectRatio_Choices_32[3]; // idb
PStringBase<char> stru_84570C; // idb
PStringBase<char> stru_845710; // idb
PStringBase<char> waveform_None_56; // idb
PStringBase<char> waveform_Speed_56; // idb
PStringBase<char> waveform_Noise_56; // idb
PStringBase<char> waveform_Sine_56; // idb
PStringBase<char> waveform_Square_56; // idb
PStringBase<char> waveform_Bounce_56; // idb
PStringBase<char> waveform_Perlin_56; // idb
PStringBase<char> waveform_Fractal_56; // idb
PStringBase<char> waveform_FrameLoop_56; // idb
struct Palette *Palette::solid_color_palette; // weak
PStringBase<char> Display_Resolution_25; // idb
PStringBase<char> Display_FullScreen_25; // idb
PStringBase<char> Display_RefreshRate_25; // idb
PStringBase<char> Display_SyncToRefresh_25; // idb
IDClass<_tagDataID,32,0> stru_84575C; // idb
enum ImageScaleType ImgTex::fLandTextureScale; // weak
enum ImageScaleType ImgTex::fClipmapTextureScale; // weak
enum ImageScaleType ImgTex::fRGBATextureScale; // weak
enum ImageScaleType ImgTex::fIndexedTextureScale; // weak
enum ImageScaleType ImgTex::fCurrentTextureScale; // weak
PixelFormatDesc stru_845790; // idb
const float dword_8457C8; // idb
const float flt_8457CC; // idb
const float flt_8457D0; // idb
const float flt_8457D4; // idb
IDClass<_tagDataID,32,0> stru_8457D8; // idb
PStringBase<char> Render_TextureFiltering_33; // idb
PStringBase<char> Render_LandscapeDetailTextures_33; // idb
PStringBase<char> Render_BuildingDetailTextures_33; // idb
PStringBase<char> Render_FieldOfView_33; // idb
PStringBase<char> Render_LandscapeTextureDetail_33; // idb
PStringBase<char> Render_EnvironmentTextureDetail_33; // idb
PStringBase<char> Render_SceneryDrawDistance_33; // idb
PStringBase<char> Render_LandscapeDrawDistance_33; // idb
PStringBase<char> Render_ScreenBrightness_33; // idb
PStringBase<char> Render_AspectRatio_33; // idb
PStringBase<char> Render_DisplayAdapter_33; // idb
PStringBase<char> Render_MaxHardwareClass_33; // idb
PStringBase<char> Render_AutomaticDegrades_33; // idb
PStringBase<char> Render_GraphicsPerformance_33; // idb
PStringBase<char> Render_DegradeDistance_33; // idb
PStringBase<char> Render_MultiPassAlpha_33; // idb
PStringBase<char> Render_TextureFiltering_Choices_33[4]; // idb
PStringBase<char> stru_845820; // idb
PStringBase<char> stru_845824; // idb
PStringBase<char> stru_845828; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_33[5]; // idb
PStringBase<char> stru_845830; // idb
PStringBase<char> stru_845834; // idb
PStringBase<char> stru_845838; // idb
PStringBase<char> stru_84583C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_33[5]; // idb
PStringBase<char> stru_845844; // idb
PStringBase<char> stru_845848; // idb
PStringBase<char> stru_84584C; // idb
PStringBase<char> stru_845850; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_33[3]; // idb
PStringBase<char> stru_845858; // idb
PStringBase<char> stru_84585C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_33[6]; // idb
PStringBase<char> stru_845864; // idb
PStringBase<char> stru_845868; // idb
PStringBase<char> stru_84586C; // idb
PStringBase<char> stru_845870; // idb
PStringBase<char> stru_845874; // idb
PStringBase<char> Render_AspectRatio_Choices_33[3]; // idb
PStringBase<char> stru_84587C; // idb
PStringBase<char> stru_845880; // idb
PStringBase<char> waveform_None_57; // idb
PStringBase<char> waveform_Speed_57; // idb
PStringBase<char> waveform_Noise_57; // idb
PStringBase<char> waveform_Sine_57; // idb
PStringBase<char> waveform_Square_57; // idb
PStringBase<char> waveform_Bounce_57; // idb
PStringBase<char> waveform_Perlin_57; // idb
PStringBase<char> waveform_Fractal_57; // idb
PStringBase<char> waveform_FrameLoop_57; // idb
PStringBase<char> Display_Resolution_26; // idb
PStringBase<char> Display_FullScreen_26; // idb
PStringBase<char> Display_RefreshRate_26; // idb
PStringBase<char> Display_SyncToRefresh_26; // idb
PStringBase<char> PHeader_10; // idb
PStringBase<char> VertexArray_8; // idb
PStringBase<char> BinaryVertexArray_8; // idb
PStringBase<char> VertexType_9; // idb
PStringBase<char> VertexData_8; // idb
PStringBase<char> Vertex_8; // idb
PStringBase<char> Index_17; // idb
PStringBase<char> Origin_17; // idb
PStringBase<char> Normal_8; // idb
PStringBase<char> Diffuse_17; // idb
PStringBase<char> Specular_17; // idb
PStringBase<char> UVS_8; // idb
PStringBase<char> VectorS_8; // idb
PStringBase<char> VectorT_8; // idb
PStringBase<char> VectorSxT_8; // idb
PStringBase<char> Weights_8; // idb
PStringBase<char> Importance_8; // idb
PStringBase<char> PhysMtl_8; // idb
PStringBase<char> Material_38; // idb
PStringBase<char> ID_20; // idb
PStringBase<char> FileName_8; // idb
PStringBase<char> Polygon_17; // idb
PStringBase<char> ID_21; // idb
PStringBase<char> Indices_14; // idb
PStringBase<char> MaterialID_8; // idb
PStringBase<char> PhysMaterialID_8; // idb
PStringBase<char> Markings_8; // idb
PStringBase<char> Material_39; // idb
PStringBase<char> Index_18; // idb
PStringBase<char> Filename_8; // idb
PStringBase<char> Surface_8; // idb
PStringBase<char> CellPoly_8; // idb
PStringBase<char> Sphere_11; // idb
PStringBase<char> Side_8; // idb
PStringBase<char> Positive_8; // idb
PStringBase<char> Negative_8; // idb
PStringBase<char> Polygon_18; // idb
PStringBase<char> OtherCell_17; // idb
PStringBase<char> CellPortal_8; // idb
PStringBase<char> Portal_11; // idb
PStringBase<char> OtherCell_18; // idb
PStringBase<char> OtherPortal_8; // idb
PStringBase<char> ExactMatch_8; // idb
PStringBase<char> StabList_8; // idb
PStringBase<char> Period_8; // idb
PStringBase<char> GrannyAnimation_8; // idb
PStringBase<char> Transform_8; // idb
PStringBase<char> Scale_26; // idb
PStringBase<char> Weight_8; // idb
PStringBase<char> Offset_8; // idb
PStringBase<char> Quaternion_9; // idb
PStringBase<char> Rotation_17; // idb
PStringBase<char> STime_8; // idb
PStringBase<char> PhysicsSplines_8; // idb
PStringBase<char> BoneOpacities_8; // idb
PStringBase<char> LowPt_8; // idb
PStringBase<char> Radius_8; // idb
PStringBase<char> Height_8; // idb
PStringBase<char> Texture2D_8; // idb
PStringBase<char> Texture3D_8; // idb
PStringBase<char> TextureCube_8; // idb
PStringBase<char> TextureMovie2D_8; // idb
PStringBase<char> MovieFileName_8; // idb
PStringBase<char> MovieFramesPerSecond_8; // idb
PStringBase<char> Levels_8; // idb
PStringBase<char> NodeName_89; // idb
PStringBase<char> Material_40; // idb
PStringBase<char> MaterialType_8; // idb
PStringBase<char> Modifier_8; // idb
PStringBase<char> AllowStencilShadows_8; // idb
PStringBase<char> DiscardGeometry_8; // idb
PStringBase<char> NodeName_90; // idb
PStringBase<char> SortMode_8; // idb
PStringBase<char> SortMode_None_8; // idb
PStringBase<char> SortMode_Triangle_8; // idb
PStringBase<char> NodeName_91; // idb
PStringBase<char> NodeName_92; // idb
PStringBase<char> DataType_DATA_8; // idb
PStringBase<char> DataType_WAVEFORM_8; // idb
PStringBase<char> DataType_COLOR_8; // idb
PStringBase<char> DataType_TEXTURE_8; // idb
PStringBase<char> DataType_BOOL_8; // idb
PStringBase<char> NodeName_93; // idb
PStringBase<char> modType_UVTranslate_8; // idb
PStringBase<char> modType_UVRotate_8; // idb
PStringBase<char> modType_UVScale_8; // idb
PStringBase<char> modType_UVTransform_8; // idb
PStringBase<char> TrueFlags_8; // idb
PStringBase<char> FalseFlags_8; // idb
PStringBase<char> RenderPass_8; // idb
PStringBase<char> Blend_8; // idb
PStringBase<char> DepthTest_8; // idb
PStringBase<char> DepthWrite_8; // idb
PStringBase<char> CullMode_8; // idb
PStringBase<char> DepthFog_8; // idb
PStringBase<char> AlphaTestMode_8; // idb
PStringBase<char> AlphaTestRef_8; // idb
PStringBase<char> FFUseLighting_8; // idb
PStringBase<char> FFUseDyeColorInTFactor_8; // idb
PStringBase<char> FFUseSpecularLighting_8; // idb
PStringBase<char> FFUseDistanceFog_8; // idb
PStringBase<char> FFUseVertexDiffuse_8; // idb
PStringBase<char> FFUseVertexSpecular_8; // idb
PStringBase<char> ShaderSupportsDynamicLights_8; // idb
PStringBase<char> UsesTransparency_8; // idb
PStringBase<char> Ambient_8; // idb
PStringBase<char> Diffuse_18; // idb
PStringBase<char> Specular_18; // idb
PStringBase<char> SpecularPower_8; // idb
PStringBase<char> Dye_8; // idb
PStringBase<char> Emissive_8; // idb
PStringBase<char> VertexFormat_8; // idb
PStringBase<char> VertexShader_8; // idb
PStringBase<char> PixelShader_8; // idb
PStringBase<char> param_MLF_NONE_8; // idb
PStringBase<char> param_MLF_REFLECTIONS_8; // idb
PStringBase<char> param_MLF_VIDEOPOST_8; // idb
PStringBase<char> param_MLF_HIGHDETAIL_8; // idb
PStringBase<char> param_MLF_SPECULAR_8; // idb
PStringBase<char> param_MLF_CLASS1_8; // idb
PStringBase<char> param_MLF_CLASS2_8; // idb
PStringBase<char> param_MLF_CLASS3_8; // idb
PStringBase<char> param_RenderPass_Default_8; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_8; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_8; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_8; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_8; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_8; // idb
PStringBase<char> param_RenderPass_DistanceFog_8; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_8; // idb
PStringBase<char> param_RenderPass_ShaderGlow_8; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_8; // idb
PStringBase<char> param_RenderPass_AlphaBlend_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_8; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_8; // idb
PStringBase<char> param_BLEND_ZERO_8; // idb
PStringBase<char> param_BLEND_ONE_8; // idb
PStringBase<char> param_BLEND_SRCCOLOR_8; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_8; // idb
PStringBase<char> param_BLEND_SRCALPHA_8; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_8; // idb
PStringBase<char> param_BLEND_DSTALPHA_8; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_8; // idb
PStringBase<char> param_BLEND_DSTCOLOR_8; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_8; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_8; // idb
PStringBase<char> param_DEPTHTEST_LESS_8; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_8; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_8; // idb
PStringBase<char> param_DEPTHTEST_GREATER_8; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_8; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_8; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_8; // idb
PStringBase<char> param_DEPTHWRITE_ON_8; // idb
PStringBase<char> param_DEPTHWRITE_OFF_8; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_8; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_8; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_8; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_8; // idb
PStringBase<char> param_CULLMODE_NONE_8; // idb
PStringBase<char> param_CULLMODE_CW_8; // idb
PStringBase<char> param_CULLMODE_CCW_8; // idb
PStringBase<char> param_LIGHTMODE_NONE_8; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_8; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_8; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_8; // idb
PStringBase<char> param_DEPTHFOG_OFF_8; // idb
PStringBase<char> param_DEPTHFOG_ON_8; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_8; // idb
PStringBase<char> param_ALPHATESTMODE_ON_8; // idb
PStringBase<char> param_VF_ORIGIN_8; // idb
PStringBase<char> param_VF_NORMAL_8; // idb
PStringBase<char> param_VF_POINTSIZE_8; // idb
PStringBase<char> param_VF_DIFFUSE_8; // idb
PStringBase<char> param_VF_SPECULAR_8; // idb
PStringBase<char> param_VF_TCPAIRx1_8; // idb
PStringBase<char> param_VF_TCPAIRx2_8; // idb
PStringBase<char> param_VF_TCPAIRx3_8; // idb
PStringBase<char> param_VF_TCPAIRx4_8; // idb
PStringBase<char> param_VF_TCPAIRx5_8; // idb
PStringBase<char> param_VF_TCPAIRx6_8; // idb
PStringBase<char> param_VF_TCPAIRx7_8; // idb
PStringBase<char> param_VF_TCPAIRx8_8; // idb
PStringBase<char> param_VF_VECTOR_S_8; // idb
PStringBase<char> param_VF_VECTOR_T_8; // idb
PStringBase<char> NodeName_94; // idb
PStringBase<char> SamplerNodeName_8; // idb
PStringBase<char> SamplerName_8; // idb
PStringBase<char> Texture_8; // idb
PStringBase<char> SpecialTexture_FrameBuffer_8; // idb
PStringBase<char> SpecialTexture_Distortion_8; // idb
PStringBase<char> SpecialTexture_Reflection_8; // idb
PStringBase<char> SpecialTexture_NormalizeCube_8; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_8; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_8; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_8; // idb
PStringBase<char> AddressMode_8; // idb
PStringBase<char> TexFilter_8; // idb
PStringBase<char> ColorOp_8; // idb
PStringBase<char> ColorArg1_8; // idb
PStringBase<char> ColorArg2_8; // idb
PStringBase<char> AlphaOp_8; // idb
PStringBase<char> AlphaArg1_8; // idb
PStringBase<char> AlphaArg2_8; // idb
PStringBase<char> TexCoord_8; // idb
PStringBase<char> UseProjection_8; // idb
PStringBase<char> param_TEXOP_SELECTARG1_8; // idb
PStringBase<char> param_TEXOP_SELECTARG2_8; // idb
PStringBase<char> param_TEXOP_MODULATE_8; // idb
PStringBase<char> param_TEXOP_MODULATE2X_8; // idb
PStringBase<char> param_TEXOP_MODULATE4X_8; // idb
PStringBase<char> param_TEXOP_ADD_8; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_8; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_8; // idb
PStringBase<char> param_TEXOP_SUBTRACT_8; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_8; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_8; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_8; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_8; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_8; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_8; // idb
PStringBase<char> param_TEXOP_PREMODULATE_8; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_8; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_8; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_8; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_8; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_8; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_8; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_8; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_8; // idb
PStringBase<char> param_TEXOP_LERP_8; // idb
PStringBase<char> param_TEXARG_DIFFUSE_8; // idb
PStringBase<char> param_TEXARG_SPECULAR_8; // idb
PStringBase<char> param_TEXARG_CURRENT_8; // idb
PStringBase<char> param_TEXARG_TEXTURE_8; // idb
PStringBase<char> param_TEXARG_TFACTOR_8; // idb
PStringBase<char> param_TEXADDRESS_WRAP_8; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_8; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_8; // idb
PStringBase<char> param_TEXADDRESS_BORDER_8; // idb
PStringBase<char> param_TEXFILTER_NONE_8; // idb
PStringBase<char> param_TEXFILTER_POINT_8; // idb
PStringBase<char> param_TEXFILTER_LINEAR_8; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_8; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_8; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_8; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_8; // idb
PStringBase<char> param_TEXCOORD_SphereMap_8; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_8; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_8; // idb
PStringBase<char> NodeName_95; // idb
PStringBase<char> ModType_Origin_8; // idb
PStringBase<char> ModType_Normal_8; // idb
PStringBase<char> ModType_Diffuse_8; // idb
PStringBase<char> ModType_UVTranslate_8; // idb
PStringBase<char> ModType_UVRotate_8; // idb
PStringBase<char> ModType_UVScale_8; // idb
PStringBase<char> ModType_UVTransform_8; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_8; // idb
PStringBase<char> Mod_UVTranslate_translate_8; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_8; // idb
PStringBase<char> Mod_UVRotate_rotate_8; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_8; // idb
PStringBase<char> Mod_UVScale_scale_8; // idb
PStringBase<char> NodeName_96; // idb
PStringBase<char> PhysicsTimeStep_8; // idb
PStringBase<char> FastForwardTime_8; // idb
PStringBase<char> StartFadeDistance_8; // idb
PStringBase<char> StopFadeDistance_8; // idb
PStringBase<char> PhysicsDuration_8; // idb
PStringBase<char> ScaleType_8; // idb
PStringBase<char> WorldSpace_8; // idb
PStringBase<char> ForceDraw_8; // idb
PStringBase<char> NumEmitters_8; // idb
PStringBase<char> Material_41; // idb
PStringBase<char> Version_8; // idb
PStringBase<char> MaxParticles_8; // idb
PStringBase<char> NodeName_97; // idb
PStringBase<char> Origin_18; // idb
PStringBase<char> Shape_8; // idb
PStringBase<char> Shape_Point_8; // idb
PStringBase<char> Shape_Line_8; // idb
PStringBase<char> Shape_Quad_8; // idb
PStringBase<char> Shape_Disc_8; // idb
PStringBase<char> Shape_Sphere_8; // idb
PStringBase<char> ParticleShape_8; // idb
PStringBase<char> ParticleShape_Triangle_8; // idb
PStringBase<char> ParticleShape_Quad_8; // idb
PStringBase<char> Streak_8; // idb
PStringBase<char> Rotation_18; // idb
PStringBase<char> WorldRotation_8; // idb
PStringBase<char> RotateVelocity_8; // idb
PStringBase<char> ParticleScale_8; // idb
PStringBase<char> Scale_27; // idb
PStringBase<char> ExplodingDir_8; // idb
PStringBase<char> BirthRate_8; // idb
PStringBase<char> Lifespan_8; // idb
PStringBase<char> Velocity_8; // idb
PStringBase<char> Direction_8; // idb
PStringBase<char> MinSpread_8; // idb
PStringBase<char> MaxSpread_8; // idb
PStringBase<char> EmissionLimit_8; // idb
PStringBase<char> BlastCount_8; // idb
PStringBase<char> StartTime_8; // idb
PStringBase<char> TimeLimit_8; // idb
PStringBase<char> EmissionDistance_8; // idb
PStringBase<char> ParticleSnap_8; // idb
PStringBase<char> InclusiveShape_8; // idb
PStringBase<char> NumKeyframes_8; // idb
PStringBase<char> IsActive_8; // idb
PStringBase<char> FadeIn_8; // idb
PStringBase<char> FadeOut_8; // idb
PStringBase<char> ConstrainX_8; // idb
PStringBase<char> ConstrainY_8; // idb
PStringBase<char> ConstrainZ_8; // idb
PStringBase<char> NodeName_98; // idb
PStringBase<char> Time_8; // idb
PStringBase<char> Flags_8; // idb
PStringBase<char> Flags_None_8; // idb
PStringBase<char> Flags_BlendScale_8; // idb
PStringBase<char> Flags_BlendColor_8; // idb
PStringBase<char> Flags_BlendMass_8; // idb
PStringBase<char> Flags_SetScale_8; // idb
PStringBase<char> Flags_SetColor_8; // idb
PStringBase<char> Flags_SetMass_8; // idb
PStringBase<char> Flags_SetPFlags_8; // idb
PStringBase<char> Flags_SetPCType_8; // idb
PStringBase<char> Flags_SetPhysFlags_8; // idb
PStringBase<char> Flags_SetParams_8; // idb
PStringBase<char> Scale_28; // idb
PStringBase<char> ScaleX_8; // idb
PStringBase<char> ScaleY_8; // idb
PStringBase<char> Color_8; // idb
PStringBase<char> Mass_8; // idb
PStringBase<char> PFlags_8; // idb
PStringBase<char> PFlags_None_8; // idb
PStringBase<char> PCType_8; // idb
PStringBase<char> PCType_None_8; // idb
PStringBase<char> PCType_Physics_8; // idb
PStringBase<char> PCType_Parametric_8; // idb
PStringBase<char> PCType_AttractRepulse_8; // idb
PStringBase<char> PCType_PointFile_8; // idb
PStringBase<char> PCType_PointFileLerp_8; // idb
PStringBase<char> PhysFlags_8; // idb
PStringBase<char> PhysFlags_None_8; // idb
PStringBase<char> PhysFlags_Gravity_8; // idb
PStringBase<char> PhysFlags_Wind_8; // idb
PStringBase<char> PhysFlags_Momentum_8; // idb
PStringBase<char> PointfileFlags_RandomPoint_8; // idb
PStringBase<char> Position_9; // idb
PStringBase<char> PointList_8; // idb
PStringBase<char> Point_18; // idb
PStringBase<char> DetailLevels_8; // idb
PStringBase<char> DetailLevel_Low_8; // idb
PStringBase<char> DetailLevel_Medium_8; // idb
PStringBase<char> DetailLevel_High_8; // idb
PStringBase<char> FadeSpeed_8; // idb
PStringBase<char> MaxOpacity_8; // idb
PStringBase<char> Point_19; // idb
PStringBase<char> PointAxisPos_8; // idb
PStringBase<char> PointTexture_8; // idb
PStringBase<char> PointSize_8; // idb
PStringBase<char> UseOcclusion_8; // idb
PStringBase<char> PHEADER_STRINGS_6[4]; // idb
PStringBase<char> stru_845EE8; // idb
PStringBase<char> stru_845EEC; // idb
PStringBase<char> stru_845EF0; // idb
_UNKNOWN unk_845EF4; // weak
struct PacketController *PacketController::pcontrol_; // weak
const int INITIAL_MAX_DATA_RATE_97; // idb
SharedNet *SharedNet::s_pNet; // idb
const int INITIAL_MAX_DATA_RATE_98; // idb
AsyncContext INVALID_ASYNCCONTEXT_7; // idb
const int dword_845F1C; // idb
unsigned int Proto_UI::eventCounter_; // weak
unsigned __int16 Proto_UI::m_UnorderedStamp; // idb
const int dword_845F40; // idb
const int dword_845F48; // idb
PerfMonCounter<unsigned __int64> *FlowQueue::m_pBlobsDequeuedCounter; // idb
const int dword_845F58; // idb
NetInterface *NetInterface::netInterface_; // idb
const int dword_845F68; // idb
const int dword_845F74; // idb
const int dword_845F80; // idb
const int dword_845F8C; // idb
const int dword_845F98; // idb
const int dword_845FA4; // idb
const int dword_845FB0; // idb
const int dword_845FB8; // idb
struct CFactory *CFactory::global_cfactory; // weak
const float dword_845FE4; // idb
const float flt_845FE8; // idb
const float flt_845FEC; // idb
const float flt_845FF0; // idb
const float flt_845FF4; // idb
const long double dbl_845FF8; // idb
const long double dbl_846000; // idb
PixelFormatDesc stru_846008; // idb
struct view_vertex *Render::portal_vertex; // weak
struct view_type *Render::portal_view; // weak
double Render::tx; // weak
int Render::portal_npnts; // weak
float Render::PolyCurrentMod; // weak
struct HWLightUsage *Render::curLightUsage; // weak
int dword_84605C[]; // weak
int dword_846060[]; // weak
int dword_846064; // weak
int dword_846068; // weak
int dword_84606C; // weak
int dword_846070; // weak
int dword_846074; // weak
int dword_846078; // weak
int dword_84607C; // weak
int dword_846080; // weak
int dword_846084; // weak
int dword_846088; // weak
int dword_84608C; // weak
int dword_846090; // weak
int dword_846094; // weak
int dword_846098; // weak
int dword_84609C; // weak
int dword_8460A0; // weak
int dword_8460A4; // weak
int dword_8460A8; // weak
int dword_8460AC; // weak
int dword_8460B0; // weak
int dword_8460B4; // weak
int Render::PolyCurrentPos; // weak
float Render::ymin; // weak
float Render::xmax; // weak
int dword_8460C4[]; // weak
int *Render::static_light_used; // weak
_UNKNOWN Render::PolyList; // weak
int Render::portal_inmask; // weak
_UNKNOWN degmulhist; // weak
_UNKNOWN unk_8661C4; // weak
int dword_866234[]; // weak
int *Render::dynamic_light_used; // weak
float Render::local_object_radius; // weak
struct HWLightUsage *Render::prevLightUsage; // weak
int dword_86626C; // weak
int dword_866270; // weak
int dword_866274; // weak
int dword_866278; // weak
int dword_86627C; // weak
int dword_866280; // weak
int dword_866284; // weak
int dword_866288; // weak
int dword_86628C; // weak
int dword_866290; // weak
int dword_866294; // weak
int dword_866298; // weak
int dword_86629C; // weak
int dword_8662A0; // weak
int dword_8662A4; // weak
int dword_8662A8; // weak
int dword_8662AC; // weak
int dword_8662B0; // weak
int dword_8662B4; // weak
int dword_8662B8; // weak
int dword_8662BC; // weak
int dword_8662C0; // weak
int dword_8662C4; // weak
double Render::xinvscale; // weak
double Render::bh; // weak
struct polyListEntry *Render::PolyNext; // weak
int Render::portal_view_num; // weak
double Render::yinvscale; // weak
double Render::bw; // weak
float Render::ymax; // weak
float Render::xmin; // weak
struct CPolygon *Render::PolyCurrent; // weak
double Render::ty; // weak
float Render::s_rUserSuppliedDegradeBias; // weak
float Render::deg_mul; // weak
int Render::selection_x; // idb
int Render::selection_y; // idb
struct portal_view_type *Render::PortalList; // weak
AC1Legacy::Vector3 *Render::FrameCurrent; // idb
int Render::FramePushCount; // weak
int Render::pushLevelOffset; // weak
int Render::FrameEra; // weak
int Render::useSunlight; // weak
bool Render::check_curr_object; // weak
bool Render::check_curr_object_polys; // weak
bool Render::check_selection; // weak
D3DPolyRender *Render::m_pRenderer; // idb
unsigned __int32 Render::m_CacheOverallGraphicsQuality; // weak
bool Render::sm_WantSafeRenderSettings; // weak
int InitState; // idb
struct CSurface *Render::landscape_detail_surface; // weak
struct CSurface *Render::building_detail_surface; // weak
struct CSurface *Render::environment_detail_surface; // weak
struct CSurface *Render::object_detail_surface; // weak
CSurface *Render::curr_detail_surface; // idb
struct CMaterial *Render::curr_material; // weak
CSurface **Render::curr_surfaces; // idb
struct CSurface *Render::curr_surface; // weak
unsigned __int32 Render::curr_surface_type; // weak
int Render::curr_texture_is_set; // weak
char *Render::UVIndexTbl; // weak
AC1Legacy::Vector3 Render::selection_ray; // idb
struct RGBColor Render::luminosity; // weak
float flt_8663FC; // weak
float flt_866400; // weak
float Render::object_distance_2dsq; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_1; // idb
struct DrawParms Render::viewer_world_space; // weak
int dword_866410; // weak
int dword_866414; // weak
Plane plane; // idb
struct Vector3 Render::Zaxis; // weak
float flt_86642C; // weak
float flt_866430; // weak
PStringBase<char> Render_LandscapeDetailTextures_34; // idb
PStringBase<char> Render_AspectRatio_34; // idb
PStringBase<char> Render_FieldOfView_34; // idb
PStringBase<char> Render_MultiPassAlpha_34; // idb
PStringBase<char> Display_SyncToRefresh_27; // idb
PStringBase<char> Render_ScreenBrightness_34; // idb
PStringBase<char> Render_AutomaticDegrades_34; // idb
PStringBase<char> Render_TextureFiltering_34; // idb
const float flt_866454; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_1; // idb
_UNKNOWN Render::FrameStack; // weak
int dword_866480; // weak
_UNKNOWN unk_866484; // weak
_UNKNOWN unk_8664C0; // weak
_UNKNOWN unk_8665C0; // weak
_UNKNOWN unk_867268; // weak
PStringBase<char> Render_EnvironmentTextureDetail_Choices_34[5]; // idb
PStringBase<char> stru_867274; // idb
PStringBase<char> stru_867278; // idb
PStringBase<char> stru_86727C; // idb
PStringBase<char> stru_867280; // idb
PStringBase<char> Render_EnvironmentTextureDetail_34; // idb
PStringBase<char> waveform_None_58; // idb
PStringBase<char> waveform_Sine_58; // idb
PStringBase<char> waveform_Noise_58; // idb
PStringBase<char> waveform_Bounce_58; // idb
PStringBase<char> Display_Resolution_27; // idb
PStringBase<char> Render_BuildingDetailTextures_34; // idb
LightParms Render::world_lights; // idb
PStringBase<char> Render_DisplayAdapter_34; // idb
const long double dbl_86B0F0; // idb
PStringBase<char> Render_LandscapeDrawDistance_34; // idb
PStringBase<char> Render_GraphicsPerformance_34; // idb
const float flt_86B100; // idb
PStringBase<char> Display_RefreshRate_27; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_34[3]; // idb
PStringBase<char> stru_86B10C; // idb
PStringBase<char> stru_86B110; // idb
struct Vector3 Render::local_object_center; // weak
float flt_86B118; // weak
float flt_86B11C; // weak
const float flt_86B120; // idb
PixelFormatDesc stru_86B124; // idb
PStringBase<char> waveform_Fractal_58; // idb
PStringBase<char> Render_AspectRatio_Choices_34[3]; // idb
PStringBase<char> stru_86B168; // idb
PStringBase<char> stru_86B16C; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_2; // idb
const float flt_86B174; // idb
PStringBase<char> waveform_FrameLoop_58; // idb
struct Vector3 Render::Yaxis; // weak
float flt_86B180; // weak
float flt_86B184; // weak
const float dword_86B188; // idb
struct Render::MouseSelectData Render::m_MouseSelectData; // weak
double dbl_86B198; // weak
int dword_86B1A0; // weak
int dword_86B1A4; // weak
char byte_86B1A8; // weak
double dbl_86B1B0; // weak
int dword_86B1B8; // weak
int dword_86B1BC; // weak
struct Vector3 Render::Xaxis; // weak
float flt_86B1C4; // weak
float flt_86B1C8; // weak
PStringBase<char> Render_LandscapeTextureDetail_34; // idb
PStringBase<char> Display_FullScreen_27; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_1; // idb
PStringBase<char> waveform_Perlin_58; // idb
const long double dbl_86B1E0; // idb
PStringBase<char> Render_DegradeDistance_34; // idb
PStringBase<char> Render_MaxHardwareClass_34; // idb
PStringBase<char> waveform_Speed_58; // idb
float Render::particle_distance_2dsq; // weak
SmartArray<bool (__cdecl*)(void),1> Render::m_RGRCallbacks; // idb
PStringBase<char> waveform_Square_58; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_34[5]; // idb
PStringBase<char> stru_86B214; // idb
PStringBase<char> stru_86B218; // idb
PStringBase<char> stru_86B21C; // idb
PStringBase<char> stru_86B220; // idb
_UNKNOWN unk_86B224; // weak
LightParms Render::viewer_lights; // idb
_UNKNOWN Render::portal_obj_plane; // weak
_UNKNOWN unk_86F094; // weak
ClipPlaneList simple_clip_plane_list; // idb
PStringBase<char> Render_SceneryDrawDistance_34; // idb
PStringBase<char> Render_TextureFiltering_Choices_34[4]; // idb
PStringBase<char> stru_86F298; // idb
PStringBase<char> stru_86F29C; // idb
PStringBase<char> stru_86F2A0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_34[6]; // idb
PStringBase<char> stru_86F2A8; // idb
PStringBase<char> stru_86F2AC; // idb
PStringBase<char> stru_86F2B0; // idb
PStringBase<char> stru_86F2B4; // idb
PStringBase<char> stru_86F2B8; // idb
bool Current_Render_EnvironmentDetailTextures; // idb
bool Current_Render_LandscapeDetailTextures; // idb
unsigned int Current_Render_LandscapeDrawDistance; // idb
float Current_Render_FieldOfView; // idb
unsigned int Current_Render_AspectRatio; // idb
float Current_Render_ScreenBrightness; // idb
bool Current_Display_Antialiasing; // idb
bool Current_Display_SyncToRefresh; // idb
unsigned int Current_Display_RefreshRate; // idb
bool Current_Display_FullScreen; // idb
unsigned int Current_Display_Resolution; // idb
portal_view_type window; // idb
_UNKNOWN unk_86F2E4; // weak
_UNKNOWN unk_86F2E8; // weak
_UNKNOWN unk_86F2EC; // weak
view_type unk_86F2F0; // idb
void *dword_86F2F4; // idb
_UNKNOWN unk_86F2F8; // weak
_UNKNOWN unk_86F2FC; // weak
_UNKNOWN unk_86F300; // weak
DArray<view_vertex> stru_86F304; // idb
_UNKNOWN unk_86F318; // weak
_UNKNOWN unk_86F320; // weak
unsigned int _S273_14; // idb
RenderDevice *RenderDevice::render_device; // idb
PixelFormatDesc stru_86F340; // idb
PStringBase<char> waveform_None_59; // idb
PStringBase<char> waveform_Speed_59; // idb
PStringBase<char> waveform_Noise_59; // idb
PStringBase<char> waveform_Sine_59; // idb
PStringBase<char> waveform_Square_59; // idb
PStringBase<char> waveform_Bounce_59; // idb
PStringBase<char> waveform_Perlin_59; // idb
PStringBase<char> waveform_Fractal_59; // idb
PStringBase<char> waveform_FrameLoop_59; // idb
unsigned __int32 SoundManager::s_SoundFeatures; // weak
int SoundManager::curr_playing_buffer_; // weak
bool SoundManager::s_bInittedPrefs; // weak
PStringBase<char> Sound_SoundDisabled_16; // idb
PStringBase<char> Sound_SoundVolume_16; // idb
PStringBase<char> Sound_AmbientSoundDisabled_16; // idb
PStringBase<char> Sound_AmbientSoundVolume_16; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_16; // idb
PStringBase<char> Sound_InterfaceSoundVolume_16; // idb
PStringBase<char> Sound_SoundFeatures_16; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_16; // idb
PStringBase<char> Sound_SoundFeatures_Choices_16[2]; // idb
PStringBase<char> stru_86F3EC; // idb
IDClass<_tagDataID,32,0> stru_86F3F0; // idb
const float dword_86F3F4; // idb
const float flt_86F3F8; // idb
const float flt_86F3FC; // idb
const float flt_86F400; // idb
const float VOL_MIN_DIST_SQ_13; // idb
const long double INV_LOG_OF_2_13; // idb
const float flt_86F410; // idb
const long double dbl_86F418; // idb
const long double dbl_86F420; // idb
PixelFormatDesc stru_86F428; // idb
const int dword_86F460; // idb
const int dword_86F464; // idb
const int dword_86F468; // idb
PStringBase<char> Display_Resolution_28; // idb
PStringBase<char> Display_FullScreen_28; // idb
PStringBase<char> Display_RefreshRate_28; // idb
PStringBase<char> Display_SyncToRefresh_28; // idb
PStringBase<char> waveform_None_60; // idb
PStringBase<char> waveform_Speed_60; // idb
PStringBase<char> waveform_Noise_60; // idb
PStringBase<char> waveform_Sine_60; // idb
PStringBase<char> waveform_Square_60; // idb
PStringBase<char> waveform_Bounce_60; // idb
PStringBase<char> waveform_Perlin_60; // idb
PStringBase<char> waveform_Fractal_60; // idb
PStringBase<char> waveform_FrameLoop_60; // idb
IntrusiveHashTable<unsigned long,HashTableData<unsigned long,HeritageGroup_CG> *,0> SoundManager::sound_hash_; // idb
struct SoundPlayingData *SoundManager::playing_sounds_; // weak
float flt_86F514[]; // weak
int dword_86F518[]; // weak
int dword_86F51C[]; // weak
const float flt_86F62C; // idb
const float flt_86F630; // idb
const float flt_86F634; // idb
PStringBase<char> Sound_SoundDisabled_17; // idb
PStringBase<char> Sound_SoundVolume_17; // idb
PStringBase<char> Sound_AmbientSoundDisabled_17; // idb
PStringBase<char> Sound_AmbientSoundVolume_17; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_17; // idb
PStringBase<char> Sound_InterfaceSoundVolume_17; // idb
PStringBase<char> Sound_SoundFeatures_17; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_17; // idb
PStringBase<char> Sound_SoundFeatures_Choices_17[2]; // idb
PStringBase<char> stru_86F660; // idb
const float VOL_MIN_DIST_SQ_14; // idb
const long double INV_LOG_OF_2_14; // idb
const float flt_86F670; // idb
const long double dbl_86F678; // idb
const long double dbl_86F680; // idb
PStringBase<char> Sound_SoundDisabled_18; // idb
PStringBase<char> Sound_SoundVolume_18; // idb
PStringBase<char> Sound_AmbientSoundDisabled_18; // idb
PStringBase<char> Sound_AmbientSoundVolume_18; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_18; // idb
PStringBase<char> Sound_InterfaceSoundVolume_18; // idb
PStringBase<char> Sound_SoundFeatures_18; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_18; // idb
PStringBase<char> Sound_SoundFeatures_Choices_18[2]; // idb
PStringBase<char> stru_86F6C8; // idb
const float dword_86F6CC; // idb
const float flt_86F6D0; // idb
const float flt_86F6D4; // idb
const float flt_86F6D8; // idb
const float VOL_MIN_DIST_SQ_15; // idb
const long double INV_LOG_OF_2_15; // idb
HACMSTREAM phas; // idb
PStringBase<char> Sound_SoundDisabled_19; // idb
PStringBase<char> Sound_SoundVolume_19; // idb
PStringBase<char> Sound_AmbientSoundDisabled_19; // idb
PStringBase<char> Sound_AmbientSoundVolume_19; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_19; // idb
PStringBase<char> Sound_InterfaceSoundVolume_19; // idb
PStringBase<char> Sound_SoundFeatures_19; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_19; // idb
PStringBase<char> Sound_SoundFeatures_Choices_19[2]; // idb
PStringBase<char> stru_86F720; // idb
IDClass<_tagDataID,32,0> stru_86F724; // idb
const float dword_86F728; // idb
const float flt_86F72C; // idb
const float flt_86F730; // idb
const float flt_86F734; // idb
const float VOL_MIN_DIST_SQ_16; // idb
const long double INV_LOG_OF_2_16; // idb
CDirSound *pDirSound; // idb
PStringBase<char> Display_Resolution_29; // idb
PStringBase<char> Display_FullScreen_29; // idb
PStringBase<char> Display_RefreshRate_29; // idb
PStringBase<char> Display_SyncToRefresh_29; // idb
char pending[80]; // idb
midihdr_tag ciStreamBuffers; // idb
int dword_86F7F0[]; // weak
int dword_86F7F4[]; // weak
int dword_86F7F8[]; // weak
int dword_86F7FC[]; // weak
int dword_86F800[]; // weak
unsigned int dwVolPctCache; // idb
unsigned __int32 *dwVolCache; // weak
unsigned __int32 dwProgressBytes; // weak
unsigned __int32 dwCurrentTempo; // weak
unsigned __int32 dwTempoMultiplier; // weak
unsigned __int32 dwBufferTickLength; // weak
int nEmptyBuffers; // weak
int nCurrentBuffer; // weak
unsigned int uCallbackStatus; // weak
int bFileOpen; // weak
int bPlaying; // weak
int bBuffersPrepared; // weak
int bPaused; // weak
int bLooped; // weak
int bInsertTempo; // weak
HMIDIOUT hStream; // idb
int b_BuffersAllocated; // weak
int pending_loop; // idb
int is_pending; // weak
void (__cdecl *midiEventCallback)(unsigned __int8, int, unsigned __int32); // weak
void (__cdecl *midiStartCallback)(); // weak
int MidiIsSetup; // idb
HANDLE hBufferReturnEvent; // idb
int nWaitingBuffers; // idb
struct INFILESTATE ifs; // weak
int dword_86FA88; // weak
int dword_86FA8C; // weak
int dword_86FA90; // weak
HLOCAL hMem; // idb
unsigned int tkCurrentTime; // idb
int bInsertTempo; // idb
unsigned int dwMallocBlocks; // idb
unsigned int tkNext; // idb
INTRACKSTATE *ptsTrack; // idb
INTRACKSTATE *ptsFound; // idb
TEMPEVENT teTemp; // idb
unsigned int dwStatus; // idb
ErrorStream perr; // idb
void *AC1Legacy::Version::FileVersion_; // idb
void *AC1Legacy::Version::BuildVersion_; // idb
void *AC1Legacy::Version::VerboseVersionString_; // idb
LPVOID AC1Legacy::Resource::abData; // idb
const float flt_86FAE8; // idb
const float flt_86FAEC; // idb
const float flt_86FAF0; // idb
const float flt_86FB14; // idb
const float flt_86FB18; // idb
const float flt_86FB1C; // idb
const int dword_86FB24; // idb
const float flt_86FB28; // idb
const long double dbl_86FB30; // idb
const long double dbl_86FB38; // idb
AC1Legacy::Vector3 stru_86FB44; // idb
const float flt_86FB5C; // idb
const float flt_86FB60; // idb
const float flt_86FB64; // idb
const int dword_86FB6C; // idb
const float flt_86FB70; // idb
const long double dbl_86FB78; // idb
const long double dbl_86FB80; // idb
const float flt_86FBA4; // idb
const float flt_86FBA8; // idb
const float flt_86FBAC; // idb
const int dword_86FBB4; // idb
const float flt_86FBB8; // idb
const long double dbl_86FBC0; // idb
const long double dbl_86FBC8; // idb
ChatRoomTracker *CCommunicationSystem::s_pInstance; // idb
const int dword_86FBE8; // idb
const int dword_86FBEC; // idb
const int dword_86FBF0; // idb
AC1ClientChatManager *s_pAC1ClientChatManager; // idb
const int dword_86FC0C; // idb
const int dword_86FC10; // idb
const int dword_86FC14; // idb
struct IKeystone *KeyStone::m_lpKeystone; // weak
HMODULE KeyStone::m_hKeystoneLib; // idb
struct IKeystone *(__cdecl static *KeyStone::m_fnKeystoneCreate)(HWND, struct IDirect3DDevice9 *, const unsigned __int16 *, __int32 (__cdecl static *)(struct IDirect3DDevice9 *, const void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned __int32, enum _D3DFORMAT, enum _D3DPOOL, unsigned __int32, unsigned __int32, unsigned __int32, struct _D3DXIMAGE_INFO *, struct tagPALETTEENTRY *, struct IDirect3DTexture9 **), __int32 (__cdecl static *)(unsigned int, unsigned __int32, unsigned __int32, enum _D3DPOOL, struct IDirect3DVertexBuffer9 **), void *(__cdecl static *)(unsigned __int32), void (__cdecl static *)(void *)); // weak
HMODULE KeyStone::m_hAC2HelpPluginLib; // idb
HMODULE KeyStone::m_hAC2PluginManagerLib; // idb
__int32 (__cdecl static *KeyStone::m_fnAC2HelpPluginExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *); // weak
int (*KeyStone::m_fnAC2HelpPluginTerminate)(void); // weak
__int32 (__cdecl static *KeyStone::m_fnAC2PluginManagerExecute)(struct IKeystone *, unsigned __int16 *(__cdecl static *)(const unsigned __int16 *), void *); // weak
int (*KeyStone::m_fnAC2PluginManagerTerminate)(void); // weak
HACCEL KeyStone::m_hDummyAccel; // idb
bool fMSXML4Initted; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_2; // idb
PStringBase<char> Render_LandscapeDetailTextures_35; // idb
PStringBase<char> Render_AspectRatio_35; // idb
PStringBase<char> Render_FieldOfView_35; // idb
PStringBase<char> Render_MultiPassAlpha_35; // idb
PStringBase<char> Display_SyncToRefresh_30; // idb
PStringBase<char> Render_ScreenBrightness_35; // idb
PStringBase<char> Render_AutomaticDegrades_35; // idb
PStringBase<char> Render_TextureFiltering_35; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_2; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_35[5]; // idb
PStringBase<char> stru_86FCE0; // idb
PStringBase<char> stru_86FCE4; // idb
PStringBase<char> stru_86FCE8; // idb
PStringBase<char> stru_86FCEC; // idb
PStringBase<char> Render_EnvironmentTextureDetail_35; // idb
PStringBase<char> waveform_None_61; // idb
PStringBase<char> waveform_Sine_61; // idb
PStringBase<char> waveform_Noise_61; // idb
PStringBase<char> waveform_Bounce_61; // idb
PStringBase<char> Display_Resolution_30; // idb
PStringBase<char> Render_BuildingDetailTextures_35; // idb
PStringBase<char> Render_DisplayAdapter_35; // idb
PStringBase<char> Render_LandscapeDrawDistance_35; // idb
const float flt_86FD14; // idb
PStringBase<char> Render_GraphicsPerformance_35; // idb
PixelFormatDesc stru_86FD1C; // idb
PStringBase<char> Display_RefreshRate_30; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_35[3]; // idb
PStringBase<char> stru_86FD5C; // idb
PStringBase<char> stru_86FD60; // idb
const float dword_86FD64; // idb
const float flt_86FD68; // idb
PStringBase<char> waveform_Fractal_61; // idb
PStringBase<char> Render_AspectRatio_Choices_35[3]; // idb
PStringBase<char> stru_86FD78; // idb
PStringBase<char> stru_86FD7C; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_3; // idb
const float flt_86FD84; // idb
PStringBase<char> waveform_FrameLoop_61; // idb
PStringBase<char> Render_LandscapeTextureDetail_35; // idb
PStringBase<char> Display_FullScreen_30; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_2; // idb
PStringBase<char> waveform_Perlin_61; // idb
PStringBase<char> Render_DegradeDistance_35; // idb
PStringBase<char> Render_MaxHardwareClass_35; // idb
PStringBase<char> waveform_Speed_61; // idb
PStringBase<char> waveform_Square_61; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_35[5]; // idb
PStringBase<char> stru_86FDB8; // idb
PStringBase<char> stru_86FDBC; // idb
PStringBase<char> stru_86FDC0; // idb
PStringBase<char> stru_86FDC4; // idb
PStringBase<char> Render_SceneryDrawDistance_35; // idb
PStringBase<char> Render_TextureFiltering_Choices_35[4]; // idb
PStringBase<char> stru_86FDD0; // idb
PStringBase<char> stru_86FDD4; // idb
PStringBase<char> stru_86FDD8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_35[6]; // idb
PStringBase<char> stru_86FDE0; // idb
PStringBase<char> stru_86FDE4; // idb
PStringBase<char> stru_86FDE8; // idb
PStringBase<char> stru_86FDEC; // idb
PStringBase<char> stru_86FDF0; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_3; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_3; // idb
int pXMLDoc; // weak
IDClass<_tagCellID,16,65535> Outside_CellID_4; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_3; // idb
const float dword_86FE98; // idb
const float flt_86FE9C; // idb
const float flt_86FEA0; // idb
const float flt_86FEA4; // idb
const float flt_86FEA8; // idb
const long double dbl_86FEB0; // idb
const long double dbl_86FEB8; // idb
PixelFormatDesc stru_86FEC0; // idb
const int dword_86FEF8; // idb
const int dword_86FEFC; // idb
const int dword_86FF00; // idb
QIOffset Offsets_1[5]; // idb
int dword_86FF08; // weak
int dword_86FF0C; // weak
int dword_86FF10; // weak
int dword_86FF14; // weak
int dword_86FF18; // weak
int dword_86FF1C; // weak
int dword_86FF20; // weak
int dword_86FF24; // weak
int dword_86FF28; // weak
unsigned int _S127_15; // idb
const float flt_86FF50; // idb
const float flt_86FF54; // idb
const float flt_86FF58; // idb
const float flt_86FF5C; // idb
const long double dbl_86FF60; // idb
const long double dbl_86FF68; // idb
PixelFormatDesc stru_86FF70; // idb
const int dword_86FFA8; // idb
const int dword_86FFAC; // idb
const int dword_86FFB0; // idb
const float flt_86FFD4; // idb
const float flt_86FFD8; // idb
const float flt_86FFDC; // idb
const float flt_86FFE4; // idb
const long double dbl_86FFE8; // idb
const long double dbl_86FFF0; // idb
PixelFormatDesc stru_86FFF8; // idb
const int dword_870030; // idb
const int dword_870034; // idb
const int dword_870038; // idb
APIManager *APIManager::m_pCliAPI; // idb
int APIManager::m_UIReady; // weak
const float flt_870068; // idb
const float flt_87006C; // idb
const float flt_870070; // idb
const int dword_870074; // idb
const float flt_870078; // idb
const long double dbl_870080; // idb
const long double dbl_870088; // idb
PixelFormatDesc stru_870090; // idb
PStringBase<char> Display_Resolution_31; // idb
PStringBase<char> Display_FullScreen_31; // idb
PStringBase<char> Display_RefreshRate_31; // idb
PStringBase<char> Display_SyncToRefresh_31; // idb
QIOffset Offsets_2[4]; // idb
int dword_8700DC; // weak
int dword_8700E0; // weak
int dword_8700E4; // weak
int dword_8700E8; // weak
int dword_8700EC; // weak
int dword_8700F0; // weak
int dword_8700F4; // weak
unsigned int _S127_16; // idb
const float flt_870120; // idb
const float flt_870124; // idb
const float flt_870128; // idb
const float flt_87012C; // idb
const long double dbl_870130; // idb
const long double dbl_870138; // idb
PixelFormatDesc stru_870140; // idb
const int dword_870178; // idb
const int dword_87017C; // idb
const int dword_870180; // idb
struct CPlayerSystem *CPlayerSystem::s_pPlayerSystem; // weak
const float flt_8701AC; // idb
const float flt_8701B0; // idb
const float flt_8701B4; // idb
const float flt_8701B8; // idb
const long double dbl_8701C0; // idb
const long double dbl_8701C8; // idb
PixelFormatDesc stru_8701D0; // idb
const int dword_870208; // idb
const int dword_87020C; // idb
const int dword_870210; // idb
PStringBase<char> Misc_TooltipEnable_45; // idb
PStringBase<char> Misc_TooltipDelay_45; // idb
PStringBase<char> Sound_SoundDisabled_20; // idb
PStringBase<char> Sound_SoundVolume_20; // idb
PStringBase<char> Sound_AmbientSoundDisabled_20; // idb
PStringBase<char> Sound_AmbientSoundVolume_20; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_20; // idb
PStringBase<char> Sound_InterfaceSoundVolume_20; // idb
PStringBase<char> Sound_SoundFeatures_20; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_20; // idb
PStringBase<char> Sound_SoundFeatures_Choices_20[2]; // idb
PStringBase<char> stru_870240; // idb
const float VOL_MIN_DIST_SQ_17; // idb
const long double INV_LOG_OF_2_17; // idb
QIOffset Offsets_3[4]; // idb
int dword_870254; // weak
int dword_870258; // weak
int dword_87025C; // weak
int dword_870260; // weak
int dword_870264; // weak
int dword_870268; // weak
int dword_87026C; // weak
unsigned int _S164_45; // idb
long double lastCheckLinkStatusTime; // idb
IDClass<_tagDataID,32,0> hairPalID; // idb
IDClass<_tagDataID,32,0> eyesPalID; // idb
IDClass<_tagDataID,32,0> skinPalID; // idb
unsigned int dword_87028C; // idb
IDClass<_tagDataID,32,0> stru_8702A0; // idb
const float flt_8702A4; // idb
const float flt_8702A8; // idb
const float flt_8702AC; // idb
FILE *ClientSystem::s_pLogFile; // idb
const float flt_8702D4; // idb
const float flt_8702D8; // idb
const float flt_8702DC; // idb
const float flt_8702E0; // idb
const long double dbl_8702E8; // idb
const long double dbl_8702F0; // idb
PixelFormatDesc stru_8702F8; // idb
const int dword_870330; // idb
const int dword_870334; // idb
const int dword_870338; // idb
ClientUISystem *ClientUISystem::s_pUISystem; // idb
IDClass<_tagDataID,32,0> stru_870360; // idb
const float flt_870364; // idb
const float flt_870368; // idb
const float flt_87036C; // idb
const int dword_870370; // idb
const float flt_870374; // idb
const long double dbl_870378; // idb
const long double dbl_870380; // idb
PixelFormatDesc stru_870388; // idb
PStringBase<char> Display_Resolution_32; // idb
PStringBase<char> Display_FullScreen_32; // idb
PStringBase<char> Display_RefreshRate_32; // idb
PStringBase<char> Display_SyncToRefresh_32; // idb
PStringBase<char> Misc_TooltipEnable_46; // idb
PStringBase<char> Misc_TooltipDelay_46; // idb
PStringBase<char> Sound_SoundDisabled_21; // idb
PStringBase<char> Sound_SoundVolume_21; // idb
PStringBase<char> Sound_AmbientSoundDisabled_21; // idb
PStringBase<char> Sound_AmbientSoundVolume_21; // idb
PStringBase<char> Sound_InterfaceSoundDisabled_21; // idb
PStringBase<char> Sound_InterfaceSoundVolume_21; // idb
PStringBase<char> Sound_SoundFeatures_21; // idb
PStringBase<char> Sound_PlaySoundOnlyWhenActive_21; // idb
PStringBase<char> Sound_SoundFeatures_Choices_21[2]; // idb
PStringBase<char> stru_8703FC; // idb
const float VOL_MIN_DIST_SQ_18; // idb
const long double INV_LOG_OF_2_18; // idb
QIOffset Offsets_4[4]; // idb
int dword_870414; // weak
int dword_870418; // weak
int dword_87041C; // weak
int dword_870420; // weak
int dword_870424; // weak
int dword_870428; // weak
int dword_87042C; // weak
unsigned int _S176_44; // idb
ClientMagicSystem *ClientMagicSystem::s_pMagicSystem; // idb
unsigned __int32 ClientMagicSystem::targetingSpell; // weak
RGBAColor ClientMagicSystem::s_NullColor; // idb
const float flt_870470; // idb
const float flt_870474; // idb
const float flt_870478; // idb
const float flt_87047C; // idb
const long double dbl_870480; // idb
const long double dbl_870488; // idb
PixelFormatDesc stru_870490; // idb
const int dword_8704C8; // idb
const int dword_8704CC; // idb
const int dword_8704D0; // idb
QIOffset Offsets_5[4]; // idb
int dword_8704D8; // weak
int dword_8704DC; // weak
int dword_8704E0; // weak
int dword_8704E4; // weak
int dword_8704E8; // weak
int dword_8704EC; // weak
int dword_8704F0; // weak
unsigned int _S129_81; // idb
struct ClientFellowshipSystem *ClientFellowshipSystem::s_pFellowshipSystem; // weak
const float flt_87051C; // idb
const float flt_870520; // idb
const float flt_870524; // idb
const float flt_870528; // idb
const long double dbl_870530; // idb
const long double dbl_870538; // idb
PixelFormatDesc stru_870540; // idb
const int dword_870578; // idb
const int dword_87057C; // idb
const int dword_870580; // idb
QIOffset Offsets_6[4]; // idb
int dword_870588; // weak
int dword_87058C; // weak
int dword_870590; // weak
int dword_870594; // weak
int dword_870598; // weak
int dword_87059C; // weak
int dword_8705A0; // weak
unsigned int _S127_17; // idb
struct ClientAllegianceSystem *ClientAllegianceSystem::s_pAllegianceSystem; // weak
const float flt_8705C8; // idb
const float flt_8705CC; // idb
const float flt_8705D0; // idb
const float flt_8705D8; // idb
const long double dbl_8705E0; // idb
const long double dbl_8705E8; // idb
PixelFormatDesc stru_8705F0; // idb
const int dword_870628; // idb
const int dword_87062C; // idb
const int dword_870630; // idb
QIOffset Offsets_7[4]; // idb
int dword_870638; // weak
int dword_87063C; // weak
int dword_870640; // weak
int dword_870644; // weak
int dword_870648; // weak
int dword_87064C; // weak
int dword_870650; // weak
unsigned int _S124_11; // idb
struct ClientCombatSystem *ClientCombatSystem::s_pCombatSystem; // weak
IDClass<_tagDataID,32,0> stru_870678; // idb
const float flt_87067C; // idb
const float flt_870680; // idb
const float flt_870684; // idb
const float flt_870688; // idb
const long double dbl_870690; // idb
const long double dbl_870698; // idb
PixelFormatDesc stru_8706A0; // idb
const int dword_8706D8; // idb
const int dword_8706DC; // idb
const int dword_8706E0; // idb
PStringBase<unsigned short> cant_sit_combat; // idb
PStringBase<unsigned short> cant_lie_down_combat; // idb
PStringBase<unsigned short> cant_crouch_combat; // idb
PStringBase<unsigned short> cant_emote_position; // idb
PStringBase<unsigned short> cant_emote_combat; // idb
PStringBase<unsigned short> cant_jump_position; // idb
PStringBase<unsigned short> cant_jump_in_air; // idb
PStringBase<unsigned short> cant_jump_load; // idb
PStringBase<unsigned short> cant_jump_stamina; // idb
PStringBase<unsigned short> cant_jump_recent; // idb
PStringBase<unsigned short> too_tired; // idb
QIOffset Offsets_8[4]; // idb
int dword_870714; // weak
int dword_870718; // weak
int dword_87071C; // weak
int dword_870720; // weak
int dword_870724; // weak
int dword_870728; // weak
int dword_87072C; // weak
unsigned int _S160_6; // idb
struct ClientTradeSystem *ClientTradeSystem::s_pTradeSystem; // weak
const float flt_87075C; // idb
const float flt_870760; // idb
const float flt_870764; // idb
const float flt_870768; // idb
const long double dbl_870770; // idb
const long double dbl_870778; // idb
PixelFormatDesc stru_870780; // idb
const int dword_8707B8; // idb
const int dword_8707BC; // idb
const int dword_8707C0; // idb
QIOffset Offsets_9[4]; // idb
int dword_8707C8; // weak
int dword_8707CC; // weak
int dword_8707D0; // weak
int dword_8707D4; // weak
int dword_8707D8; // weak
int dword_8707DC; // weak
int dword_8707E0; // weak
unsigned int _S127_18; // idb
struct ClientCommunicationSystem *ClientCommunicationSystem::s_pCommunicationSystem; // weak
IDClass<_tagDataID,32,0> i_wcid; // idb
const float flt_87080C; // idb
const float flt_870810; // idb
const float flt_870814; // idb
const float flt_870818; // idb
const long double dbl_870820; // idb
const long double dbl_870828; // idb
PixelFormatDesc stru_870830; // idb
const int dword_870868; // idb
const int dword_87086C; // idb
const int dword_870870; // idb
PStringBase<unsigned short> cant_sit_combat_0; // idb
PStringBase<unsigned short> cant_lie_down_combat_0; // idb
PStringBase<unsigned short> cant_crouch_combat_0; // idb
PStringBase<unsigned short> cant_emote_position_0; // idb
PStringBase<unsigned short> cant_emote_combat_0; // idb
PStringBase<unsigned short> cant_jump_position_0; // idb
PStringBase<unsigned short> cant_jump_in_air_0; // idb
PStringBase<unsigned short> cant_jump_load_0; // idb
PStringBase<unsigned short> cant_jump_stamina_0; // idb
PStringBase<unsigned short> cant_jump_recent_0; // idb
PStringBase<unsigned short> too_tired_0; // idb
PStringBase<char> Misc_TooltipEnable_47; // idb
PStringBase<char> Misc_TooltipDelay_47; // idb
PStringBase<char> waveform_None_62; // idb
PStringBase<char> waveform_Speed_62; // idb
PStringBase<char> waveform_Noise_62; // idb
PStringBase<char> waveform_Sine_62; // idb
PStringBase<char> waveform_Square_62; // idb
PStringBase<char> waveform_Bounce_62; // idb
PStringBase<char> waveform_Perlin_62; // idb
PStringBase<char> waveform_Fractal_62; // idb
PStringBase<char> waveform_FrameLoop_62; // idb
AC1Legacy::PStringBase<char> g_rename_cache; // idb
QIOffset Offsets_10[4]; // idb
int dword_8708D4; // weak
int dword_8708D8; // weak
int dword_8708DC; // weak
int dword_8708E0; // weak
int dword_8708E4; // weak
int dword_8708E8; // weak
int dword_8708EC; // weak
unsigned int _S197_33; // idb
bool fShowFramerate; // idb
struct ClientMiniGameSystem *ClientMiniGameSystem::s_pMiniGameSystem; // weak
const float flt_87091C; // idb
const float flt_870920; // idb
const float flt_870924; // idb
const float flt_870928; // idb
const long double dbl_870930; // idb
const long double dbl_870938; // idb
PixelFormatDesc stru_870940; // idb
const int dword_870978; // idb
const int dword_87097C; // idb
const int dword_870980; // idb
QIOffset Offsets_11[4]; // idb
int dword_870988; // weak
int dword_87098C; // weak
int dword_870990; // weak
int dword_870994; // weak
int dword_870998; // weak
int dword_87099C; // weak
int dword_8709A0; // weak
unsigned int _S124_12; // idb
struct ClientHousingSystem *ClientHousingSystem::s_pHousingSystem; // weak
const float flt_8709CC; // idb
const float flt_8709D0; // idb
const float flt_8709D4; // idb
const float flt_8709D8; // idb
const long double dbl_8709E0; // idb
const long double dbl_8709E8; // idb
PixelFormatDesc stru_8709F0; // idb
const int dword_870A28; // idb
const int dword_870A2C; // idb
const int dword_870A30; // idb
QIOffset Offsets_12[4]; // idb
int dword_870A38; // weak
int dword_870A3C; // weak
int dword_870A40; // weak
int dword_870A44; // weak
int dword_870A48; // weak
int dword_870A4C; // weak
int dword_870A50; // weak
unsigned int _S127_19; // idb
IDClass<_tagDataID,32,0> stru_870A74; // idb
const float flt_870A78; // idb
const float flt_870A7C; // idb
const float flt_870A80; // idb
const float flt_870A84; // idb
const long double dbl_870A88; // idb
const long double dbl_870A90; // idb
PixelFormatDesc stru_870A98; // idb
unsigned int ItemHolder::targetingObject; // idb
double ItemHolder::m_timeLastUsed; // weak
const float flt_870AFC; // idb
const float flt_870B00; // idb
const float flt_870B04; // idb
const float flt_870B08; // idb
const long double dbl_870B10; // idb
const long double dbl_870B18; // idb
PixelFormatDesc stru_870B20; // idb
const int dword_870B58; // idb
const int dword_870B5C; // idb
const int dword_870B60; // idb
const float flt_870BD4; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_4; // idb
const long double dbl_870BE0; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_4; // idb
const long double dbl_870BF0; // idb
PixelFormatDesc stru_870BF8; // idb
const int dword_870C30; // idb
const int dword_870C34; // idb
const float flt_870C38; // idb
const float flt_870C3C; // idb
const float dword_870C44; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_5; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_4; // idb
const int dword_870C58; // idb
const float flt_870C5C; // idb
IDClass<_tagDataID,32,0> did; // idb
const float dword_870C74; // idb
const float flt_870C78; // idb
const float flt_870C7C; // idb
const float flt_870C80; // idb
PixelFormatDesc stru_870CA0; // idb
const float dword_870CD8; // idb
const float flt_870CDC; // idb
const float flt_870CE0; // idb
const float flt_870CE4; // idb
PStringBase<char> Render_TextureFiltering_36; // idb
PStringBase<char> Render_LandscapeDetailTextures_36; // idb
PStringBase<char> Render_BuildingDetailTextures_36; // idb
PStringBase<char> Render_FieldOfView_36; // idb
PStringBase<char> Render_LandscapeTextureDetail_36; // idb
PStringBase<char> Render_EnvironmentTextureDetail_36; // idb
PStringBase<char> Render_SceneryDrawDistance_36; // idb
PStringBase<char> Render_LandscapeDrawDistance_36; // idb
PStringBase<char> Render_ScreenBrightness_36; // idb
PStringBase<char> Render_AspectRatio_36; // idb
PStringBase<char> Render_DisplayAdapter_36; // idb
PStringBase<char> Render_MaxHardwareClass_36; // idb
PStringBase<char> Render_AutomaticDegrades_36; // idb
PStringBase<char> Render_GraphicsPerformance_36; // idb
PStringBase<char> Render_DegradeDistance_36; // idb
PStringBase<char> Render_MultiPassAlpha_36; // idb
PStringBase<char> Render_TextureFiltering_Choices_36[4]; // idb
PStringBase<char> stru_870D30; // idb
PStringBase<char> stru_870D34; // idb
PStringBase<char> stru_870D38; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_36[5]; // idb
PStringBase<char> stru_870D40; // idb
PStringBase<char> stru_870D44; // idb
PStringBase<char> stru_870D48; // idb
PStringBase<char> stru_870D4C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_36[5]; // idb
PStringBase<char> stru_870D54; // idb
PStringBase<char> stru_870D58; // idb
PStringBase<char> stru_870D5C; // idb
PStringBase<char> stru_870D60; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_36[3]; // idb
PStringBase<char> stru_870D68; // idb
PStringBase<char> stru_870D6C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_36[6]; // idb
PStringBase<char> stru_870D74; // idb
PStringBase<char> stru_870D78; // idb
PStringBase<char> stru_870D7C; // idb
PStringBase<char> stru_870D80; // idb
PStringBase<char> stru_870D84; // idb
PStringBase<char> Render_AspectRatio_Choices_36[3]; // idb
PStringBase<char> stru_870D8C; // idb
PStringBase<char> stru_870D90; // idb
PStringBase<char> waveform_None_63; // idb
PStringBase<char> waveform_Speed_63; // idb
PStringBase<char> waveform_Noise_63; // idb
PStringBase<char> waveform_Sine_63; // idb
PStringBase<char> waveform_Square_63; // idb
PStringBase<char> waveform_Bounce_63; // idb
PStringBase<char> waveform_Perlin_63; // idb
PStringBase<char> waveform_Fractal_63; // idb
PStringBase<char> waveform_FrameLoop_63; // idb
const float flt_870DD4; // idb
const float flt_870DD8; // idb
const float flt_870DDC; // idb
const int dword_870DE4; // idb
const int dword_870DE8; // idb
const int dword_870DEC; // idb
const float flt_870DF0; // idb
const long double dbl_870DF8; // idb
const long double dbl_870E00; // idb
PixelFormatDesc stru_870E08; // idb
_Formatted ACCWeenieObject::selectedID; // idb
unsigned int ACCWeenieObject::prevSelectedID; // idb
unsigned __int32 ACCWeenieObject::prevSelectedValidID; // weak
char ACCWeenieObject::nameString[]; // idb
int dword_870E54; // weak
char byte_870E58; // weak
unsigned __int32 ACCWeenieObject::splitStackSize; // weak
double ACCWeenieObject::splitTime; // weak
enum InventoryRequest ACCWeenieObject::prevRequest; // weak
unsigned __int32 ACCWeenieObject::prevRequestObjectID; // weak
double ACCWeenieObject::prevRequestTime; // weak
int dword_870ECC; // weak
int ACCWeenieObject::attackInProgress; // weak
PStringBase<char> Display_Resolution_33; // idb
PStringBase<char> Display_FullScreen_33; // idb
PStringBase<char> Display_RefreshRate_33; // idb
PStringBase<char> Display_SyncToRefresh_33; // idb
IDClass<_tagDataID,32,0> stru_870F0C; // idb
const int dword_870F10; // idb
const int dword_870F14; // idb
const int dword_870F18; // idb
const float dword_870F1C; // idb
const float flt_870F20; // idb
const float flt_870F24; // idb
const float flt_870F28; // idb
const float flt_870F2C; // idb
const long double dbl_870F30; // idb
const long double dbl_870F38; // idb
PixelFormatDesc stru_870F40; // idb
int ACCWeenieObject::splitClassID; // weak
const float flt_870F90; // idb
const float flt_870F94; // idb
const float flt_870F98; // idb
const float flt_870FB0; // idb
const float flt_870FB4; // idb
const float flt_870FB8; // idb
const float flt_870FD0; // idb
const float flt_870FD4; // idb
const float flt_870FD8; // idb
QIOffset Offsets_13[3]; // idb
int dword_870FE0; // weak
int dword_870FE4; // weak
int dword_870FE8; // weak
int dword_870FEC; // weak
int dword_870FF0; // weak
unsigned int _S97_10; // idb
IDClass<_tagDataID,32,0> wcid; // idb
const float flt_87100C; // idb
const float flt_871010; // idb
const float flt_871014; // idb
const float flt_871034; // idb
const float flt_871038; // idb
const float flt_87103C; // idb
const float flt_871054; // idb
const float flt_871058; // idb
const float flt_87105C; // idb
IDClass<_tagDataID,32,0> stru_871070; // idb
const float flt_871074; // idb
const float flt_871078; // idb
const float flt_87107C; // idb
const float flt_87109C; // idb
const float flt_8710A0; // idb
const float flt_8710A4; // idb
const float flt_8710BC; // idb
const float flt_8710C0; // idb
const float flt_8710C4; // idb
const float flt_8710DC; // idb
const float flt_8710E0; // idb
const float flt_8710E4; // idb
const float flt_8710FC; // idb
const float flt_871100; // idb
const float flt_871104; // idb
const float flt_87111C; // idb
const float flt_871120; // idb
const float flt_871124; // idb
IDClass<_tagDataID,32,0> stru_871130; // idb
const float flt_871144; // idb
const float flt_871148; // idb
const float flt_87114C; // idb
const float flt_871164; // idb
const float flt_871168; // idb
const float flt_87116C; // idb
QIOffset Offsets_14[3]; // idb
int dword_871178; // weak
int dword_87117C; // weak
int dword_871180; // weak
int dword_871184; // weak
int dword_871188; // weak
unsigned int _S124_13; // idb
const float flt_8711B0; // idb
const float flt_8711B4; // idb
const float flt_8711B8; // idb
const float flt_8711BC; // idb
const long double dbl_8711C0; // idb
const long double dbl_8711C8; // idb
PixelFormatDesc stru_8711D0; // idb
const int dword_871208; // idb
const int dword_87120C; // idb
const int dword_871210; // idb
void *PrimD3DRender::pD3DSunlight; // idb
PStringBase<char> Display_Resolution_34; // idb
PStringBase<char> Display_FullScreen_34; // idb
PStringBase<char> Display_RefreshRate_34; // idb
PStringBase<char> Display_SyncToRefresh_34; // idb
PixelFormatDesc stru_871248; // idb
const float dword_871284; // idb
const float flt_871288; // idb
const float flt_87128C; // idb
const float flt_871290; // idb
PStringBase<char> Render_TextureFiltering_37; // idb
PStringBase<char> Render_LandscapeDetailTextures_37; // idb
PStringBase<char> Render_BuildingDetailTextures_37; // idb
PStringBase<char> Render_FieldOfView_37; // idb
PStringBase<char> Render_LandscapeTextureDetail_37; // idb
PStringBase<char> Render_EnvironmentTextureDetail_37; // idb
PStringBase<char> Render_SceneryDrawDistance_37; // idb
PStringBase<char> Render_LandscapeDrawDistance_37; // idb
PStringBase<char> Render_ScreenBrightness_37; // idb
PStringBase<char> Render_AspectRatio_37; // idb
PStringBase<char> Render_DisplayAdapter_37; // idb
PStringBase<char> Render_MaxHardwareClass_37; // idb
PStringBase<char> Render_AutomaticDegrades_37; // idb
PStringBase<char> Render_GraphicsPerformance_37; // idb
PStringBase<char> Render_DegradeDistance_37; // idb
PStringBase<char> Render_MultiPassAlpha_37; // idb
PStringBase<char> Render_TextureFiltering_Choices_37[4]; // idb
PStringBase<char> stru_8712D8; // idb
PStringBase<char> stru_8712DC; // idb
PStringBase<char> stru_8712E0; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_37[5]; // idb
PStringBase<char> stru_8712E8; // idb
PStringBase<char> stru_8712EC; // idb
PStringBase<char> stru_8712F0; // idb
PStringBase<char> stru_8712F4; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_37[5]; // idb
PStringBase<char> stru_8712FC; // idb
PStringBase<char> stru_871300; // idb
PStringBase<char> stru_871304; // idb
PStringBase<char> stru_871308; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_37[3]; // idb
PStringBase<char> stru_871310; // idb
PStringBase<char> stru_871314; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_37[6]; // idb
PStringBase<char> stru_87131C; // idb
PStringBase<char> stru_871320; // idb
PStringBase<char> stru_871324; // idb
PStringBase<char> stru_871328; // idb
PStringBase<char> stru_87132C; // idb
PStringBase<char> Render_AspectRatio_Choices_37[3]; // idb
PStringBase<char> stru_871334; // idb
PStringBase<char> stru_871338; // idb
PStringBase<char> waveform_None_64; // idb
PStringBase<char> waveform_Speed_64; // idb
PStringBase<char> waveform_Noise_64; // idb
PStringBase<char> waveform_Sine_64; // idb
PStringBase<char> waveform_Square_64; // idb
PStringBase<char> waveform_Bounce_64; // idb
PStringBase<char> waveform_Perlin_64; // idb
PStringBase<char> waveform_Fractal_64; // idb
PStringBase<char> waveform_FrameLoop_64; // idb
Vec2Dscreen tmpScreenBuffer[100]; // idb
int pt_to_use; // idb
unsigned int _S204_34; // idb
unsigned __int16 D3DPolyRender::alphaedMeshCountClip; // weak
unsigned __int16 D3DPolyRender::alphaedMeshCountAlpha; // weak
unsigned __int16 D3DPolyRender::portalsDrawnCount; // weak
PStringBase<char> Display_Resolution_35; // idb
PStringBase<char> Display_FullScreen_35; // idb
PStringBase<char> Display_RefreshRate_35; // idb
PStringBase<char> Display_SyncToRefresh_35; // idb
const float dword_8719E0; // idb
const float flt_8719E4; // idb
const float flt_8719E8; // idb
const float flt_8719EC; // idb
const float flt_8719F4; // idb
const long double dbl_8719F8; // idb
const long double dbl_871A00; // idb
PixelFormatDesc stru_871A08; // idb
PStringBase<char> Render_TextureFiltering_38; // idb
PStringBase<char> Render_LandscapeDetailTextures_38; // idb
PStringBase<char> Render_BuildingDetailTextures_38; // idb
PStringBase<char> Render_FieldOfView_38; // idb
PStringBase<char> Render_LandscapeTextureDetail_38; // idb
PStringBase<char> Render_EnvironmentTextureDetail_38; // idb
PStringBase<char> Render_SceneryDrawDistance_38; // idb
PStringBase<char> Render_LandscapeDrawDistance_38; // idb
PStringBase<char> Render_ScreenBrightness_38; // idb
PStringBase<char> Render_AspectRatio_38; // idb
PStringBase<char> Render_DisplayAdapter_38; // idb
PStringBase<char> Render_MaxHardwareClass_38; // idb
PStringBase<char> Render_AutomaticDegrades_38; // idb
PStringBase<char> Render_GraphicsPerformance_38; // idb
PStringBase<char> Render_DegradeDistance_38; // idb
PStringBase<char> Render_MultiPassAlpha_38; // idb
PStringBase<char> Render_TextureFiltering_Choices_38[4]; // idb
PStringBase<char> stru_871A84; // idb
PStringBase<char> stru_871A88; // idb
PStringBase<char> stru_871A8C; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_38[5]; // idb
PStringBase<char> stru_871A94; // idb
PStringBase<char> stru_871A98; // idb
PStringBase<char> stru_871A9C; // idb
PStringBase<char> stru_871AA0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_38[5]; // idb
PStringBase<char> stru_871AA8; // idb
PStringBase<char> stru_871AAC; // idb
PStringBase<char> stru_871AB0; // idb
PStringBase<char> stru_871AB4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_38[3]; // idb
PStringBase<char> stru_871ABC; // idb
PStringBase<char> stru_871AC0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_38[6]; // idb
PStringBase<char> stru_871AC8; // idb
PStringBase<char> stru_871ACC; // idb
PStringBase<char> stru_871AD0; // idb
PStringBase<char> stru_871AD4; // idb
PStringBase<char> stru_871AD8; // idb
PStringBase<char> Render_AspectRatio_Choices_38[3]; // idb
PStringBase<char> stru_871AE0; // idb
PStringBase<char> stru_871AE4; // idb
PStringBase<char> waveform_None_65; // idb
PStringBase<char> waveform_Speed_65; // idb
PStringBase<char> waveform_Noise_65; // idb
PStringBase<char> waveform_Sine_65; // idb
PStringBase<char> waveform_Square_65; // idb
PStringBase<char> waveform_Bounce_65; // idb
PStringBase<char> waveform_Perlin_65; // idb
PStringBase<char> waveform_Fractal_65; // idb
PStringBase<char> waveform_FrameLoop_65; // idb
struct AlphaListEntry *D3DPolyRender::alphaedMeshListClip; // weak
int dword_871B14[]; // weak
int dword_871B18[]; // weak
int dword_871B1C[]; // weak
Matrix4 m; // idb
char byte_871B60[]; // weak
char byte_871B61[]; // weak
struct AlphaListEntry *D3DPolyRender::alphaedMeshListAlpha; // weak
int dword_8AF374[]; // weak
int dword_8AF378[]; // weak
int dword_8AF37C[]; // weak
Matrix4 stru_8AF380; // idb
char byte_8AF3C0[]; // weak
char byte_8AF3C1[]; // weak
CUSTOM_D3D_TL_VERTEX v[30]; // idb
int portalColorVal; // idb
Vec2Dscreen *scrBufclipped[30]; // idb
Vec2Dscreen *scrBuf[30]; // idb
int skipChk; // idb
_D3DMATERIAL9 tmpmaterial; // idb
int override_light_state; // idb
int override_cull_state; // idb
int trysinglepass_2; // idb
int maxAlphaMeshCountAlpha; // idb
int maxAlphaMeshCountClip; // idb
CUSTOM_D3D_VERTEX v_0[10]; // idb
CUSTOM_D3D_VERTEX2 v_1[10]; // idb
int override_light_state_0; // idb
int override_cull_state_0; // idb
int skipPolys; // idb
SmartArray<_D3DXATTRIBUTERANGE,0> s_D3DXAttributeRanges; // idb
SmartArray<MeshBatchType,0> s_MeshBatches; // idb
unsigned int _S214_1; // idb
PView *RenderDeviceD3D::indoor_pview; // idb
PView *RenderDeviceD3D::outdoor_pview; // idb
int RenderDeviceD3D::ObjBuildingOrBuildingPart; // weak
CPhysicsPart *RenderDeviceD3D::s_current_physics_part; // idb
Vector3 stru_8ED3D8; // idb
PStringBase<char> Display_Resolution_36; // idb
PStringBase<char> Display_FullScreen_36; // idb
PStringBase<char> Display_RefreshRate_36; // idb
PStringBase<char> Display_SyncToRefresh_36; // idb
const float dword_8ED3F4; // idb
const float flt_8ED3F8; // idb
const float flt_8ED3FC; // idb
const float flt_8ED400; // idb
const int dword_8ED408; // idb
const int dword_8ED40C; // idb
const int dword_8ED410; // idb
const float flt_8ED414; // idb
const long double dbl_8ED418; // idb
const long double dbl_8ED420; // idb
PixelFormatDesc stru_8ED428; // idb
PStringBase<char> Render_TextureFiltering_39; // idb
PStringBase<char> Render_LandscapeDetailTextures_39; // idb
PStringBase<char> Render_BuildingDetailTextures_39; // idb
PStringBase<char> Render_FieldOfView_39; // idb
PStringBase<char> Render_LandscapeTextureDetail_39; // idb
PStringBase<char> Render_EnvironmentTextureDetail_39; // idb
PStringBase<char> Render_SceneryDrawDistance_39; // idb
PStringBase<char> Render_LandscapeDrawDistance_39; // idb
PStringBase<char> Render_ScreenBrightness_39; // idb
PStringBase<char> Render_AspectRatio_39; // idb
PStringBase<char> Render_DisplayAdapter_39; // idb
PStringBase<char> Render_MaxHardwareClass_39; // idb
PStringBase<char> Render_AutomaticDegrades_39; // idb
PStringBase<char> Render_GraphicsPerformance_39; // idb
PStringBase<char> Render_DegradeDistance_39; // idb
PStringBase<char> Render_MultiPassAlpha_39; // idb
PStringBase<char> Render_TextureFiltering_Choices_39[4]; // idb
PStringBase<char> stru_8ED4A4; // idb
PStringBase<char> stru_8ED4A8; // idb
PStringBase<char> stru_8ED4AC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_39[5]; // idb
PStringBase<char> stru_8ED4B4; // idb
PStringBase<char> stru_8ED4B8; // idb
PStringBase<char> stru_8ED4BC; // idb
PStringBase<char> stru_8ED4C0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_39[5]; // idb
PStringBase<char> stru_8ED4C8; // idb
PStringBase<char> stru_8ED4CC; // idb
PStringBase<char> stru_8ED4D0; // idb
PStringBase<char> stru_8ED4D4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_39[3]; // idb
PStringBase<char> stru_8ED4DC; // idb
PStringBase<char> stru_8ED4E0; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_39[6]; // idb
PStringBase<char> stru_8ED4E8; // idb
PStringBase<char> stru_8ED4EC; // idb
PStringBase<char> stru_8ED4F0; // idb
PStringBase<char> stru_8ED4F4; // idb
PStringBase<char> stru_8ED4F8; // idb
PStringBase<char> Render_AspectRatio_Choices_39[3]; // idb
PStringBase<char> stru_8ED500; // idb
PStringBase<char> stru_8ED504; // idb
PStringBase<char> waveform_None_66; // idb
PStringBase<char> waveform_Speed_66; // idb
PStringBase<char> waveform_Noise_66; // idb
PStringBase<char> waveform_Sine_66; // idb
PStringBase<char> waveform_Square_66; // idb
PStringBase<char> waveform_Bounce_66; // idb
PStringBase<char> waveform_Perlin_66; // idb
PStringBase<char> waveform_Fractal_66; // idb
PStringBase<char> waveform_FrameLoop_66; // idb
int skipMinimStep; // idb
MaterialGraphicsStatesType MGStates; // idb
_UNKNOWN unk_8ED531; // weak
_UNKNOWN unk_8ED532; // weak
_UNKNOWN unk_8ED533; // weak
_UNKNOWN unk_8ED534; // weak
bool byte_8ED535[3]; // idb
float flt_8ED538; // idb
float flt_8ED53C; // idb
float flt_8ED540; // idb
float flt_8ED544; // idb
float flt_8ED548; // idb
float flt_8ED54C; // idb
float flt_8ED550; // idb
float flt_8ED554; // idb
_UNKNOWN unk_8ED558; // weak
float flt_8ED55C; // idb
float flt_8ED560; // idb
float flt_8ED564; // idb
float flt_8ED568; // idb
RGBAColor stru_8ED56C; // idb
_UNKNOWN unk_8ED57C; // weak
unsigned int _S225_31; // idb
PixelFormatDesc stru_8ED5A0; // idb
const float dword_8ED5D8; // idb
const float flt_8ED5DC; // idb
const float flt_8ED5E0; // idb
const float flt_8ED5E4; // idb
PStringBase<char> Render_TextureFiltering_40; // idb
PStringBase<char> Render_LandscapeDetailTextures_40; // idb
PStringBase<char> Render_BuildingDetailTextures_40; // idb
PStringBase<char> Render_FieldOfView_40; // idb
PStringBase<char> Render_LandscapeTextureDetail_40; // idb
PStringBase<char> Render_EnvironmentTextureDetail_40; // idb
PStringBase<char> Render_SceneryDrawDistance_40; // idb
PStringBase<char> Render_LandscapeDrawDistance_40; // idb
PStringBase<char> Render_ScreenBrightness_40; // idb
PStringBase<char> Render_AspectRatio_40; // idb
PStringBase<char> Render_DisplayAdapter_40; // idb
PStringBase<char> Render_MaxHardwareClass_40; // idb
PStringBase<char> Render_AutomaticDegrades_40; // idb
PStringBase<char> Render_GraphicsPerformance_40; // idb
PStringBase<char> Render_DegradeDistance_40; // idb
PStringBase<char> Render_MultiPassAlpha_40; // idb
PStringBase<char> Render_TextureFiltering_Choices_40[4]; // idb
PStringBase<char> stru_8ED630; // idb
PStringBase<char> stru_8ED634; // idb
PStringBase<char> stru_8ED638; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_40[5]; // idb
PStringBase<char> stru_8ED640; // idb
PStringBase<char> stru_8ED644; // idb
PStringBase<char> stru_8ED648; // idb
PStringBase<char> stru_8ED64C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_40[5]; // idb
PStringBase<char> stru_8ED654; // idb
PStringBase<char> stru_8ED658; // idb
PStringBase<char> stru_8ED65C; // idb
PStringBase<char> stru_8ED660; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_40[3]; // idb
PStringBase<char> stru_8ED668; // idb
PStringBase<char> stru_8ED66C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_40[6]; // idb
PStringBase<char> stru_8ED674; // idb
PStringBase<char> stru_8ED678; // idb
PStringBase<char> stru_8ED67C; // idb
PStringBase<char> stru_8ED680; // idb
PStringBase<char> stru_8ED684; // idb
PStringBase<char> Render_AspectRatio_Choices_40[3]; // idb
PStringBase<char> stru_8ED68C; // idb
PStringBase<char> stru_8ED690; // idb
PStringBase<char> waveform_None_67; // idb
PStringBase<char> waveform_Speed_67; // idb
PStringBase<char> waveform_Noise_67; // idb
PStringBase<char> waveform_Sine_67; // idb
PStringBase<char> waveform_Square_67; // idb
PStringBase<char> waveform_Bounce_67; // idb
PStringBase<char> waveform_Perlin_67; // idb
PStringBase<char> waveform_Fractal_67; // idb
PStringBase<char> waveform_FrameLoop_67; // idb
unsigned __int32 PView::master_timestamp; // weak
PStringBase<char> Display_Resolution_37; // idb
PStringBase<char> Display_FullScreen_37; // idb
PStringBase<char> Display_RefreshRate_37; // idb
PStringBase<char> Display_SyncToRefresh_37; // idb
const int dword_8ED6E8; // idb
const int dword_8ED6EC; // idb
const int dword_8ED6F0; // idb
const float dword_8ED6F4; // idb
const float flt_8ED6F8; // idb
const float flt_8ED6FC; // idb
const float flt_8ED700; // idb
const float flt_8ED708; // idb
const long double dbl_8ED710; // idb
const long double dbl_8ED718; // idb
PixelFormatDesc stru_8ED720; // idb
PStringBase<char> Render_TextureFiltering_41; // idb
PStringBase<char> Render_LandscapeDetailTextures_41; // idb
PStringBase<char> Render_BuildingDetailTextures_41; // idb
PStringBase<char> Render_FieldOfView_41; // idb
PStringBase<char> Render_LandscapeTextureDetail_41; // idb
PStringBase<char> Render_EnvironmentTextureDetail_41; // idb
PStringBase<char> Render_SceneryDrawDistance_41; // idb
PStringBase<char> Render_LandscapeDrawDistance_41; // idb
PStringBase<char> Render_ScreenBrightness_41; // idb
PStringBase<char> Render_AspectRatio_41; // idb
PStringBase<char> Render_DisplayAdapter_41; // idb
PStringBase<char> Render_MaxHardwareClass_41; // idb
PStringBase<char> Render_AutomaticDegrades_41; // idb
PStringBase<char> Render_GraphicsPerformance_41; // idb
PStringBase<char> Render_DegradeDistance_41; // idb
PStringBase<char> Render_MultiPassAlpha_41; // idb
PStringBase<char> Render_TextureFiltering_Choices_41[4]; // idb
PStringBase<char> stru_8ED79C; // idb
PStringBase<char> stru_8ED7A0; // idb
PStringBase<char> stru_8ED7A4; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_41[5]; // idb
PStringBase<char> stru_8ED7AC; // idb
PStringBase<char> stru_8ED7B0; // idb
PStringBase<char> stru_8ED7B4; // idb
PStringBase<char> stru_8ED7B8; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_41[5]; // idb
PStringBase<char> stru_8ED7C0; // idb
PStringBase<char> stru_8ED7C4; // idb
PStringBase<char> stru_8ED7C8; // idb
PStringBase<char> stru_8ED7CC; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_41[3]; // idb
PStringBase<char> stru_8ED7D4; // idb
PStringBase<char> stru_8ED7D8; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_41[6]; // idb
PStringBase<char> stru_8ED7E0; // idb
PStringBase<char> stru_8ED7E4; // idb
PStringBase<char> stru_8ED7E8; // idb
PStringBase<char> stru_8ED7EC; // idb
PStringBase<char> stru_8ED7F0; // idb
PStringBase<char> Render_AspectRatio_Choices_41[3]; // idb
PStringBase<char> stru_8ED7F8; // idb
PStringBase<char> stru_8ED7FC; // idb
PStringBase<char> waveform_None_68; // idb
PStringBase<char> waveform_Speed_68; // idb
PStringBase<char> waveform_Noise_68; // idb
PStringBase<char> waveform_Sine_68; // idb
PStringBase<char> waveform_Square_68; // idb
PStringBase<char> waveform_Bounce_68; // idb
PStringBase<char> waveform_Perlin_68; // idb
PStringBase<char> waveform_Fractal_68; // idb
PStringBase<char> waveform_FrameLoop_68; // idb
int forceClear; // idb
portal_view_type temp_view; // idb
_UNKNOWN unk_8ED82C; // weak
_UNKNOWN unk_8ED830; // weak
_UNKNOWN unk_8ED834; // weak
view_type unk_8ED838; // idb
void *dword_8ED83C; // idb
_UNKNOWN unk_8ED840; // weak
_UNKNOWN unk_8ED844; // weak
_UNKNOWN unk_8ED848; // weak
DArray<view_vertex> stru_8ED84C; // idb
_UNKNOWN unk_8ED860; // weak
_UNKNOWN unk_8ED868; // weak
unsigned int _S225_32; // idb
Vec2Dscreen *clip_view[32]; // idb
Vec2Dscreen *clip_view_0[32]; // idb
IDClass<_tagDataID,32,0> stru_8ED994; // idb
const float dword_8ED998; // idb
const float flt_8ED99C; // idb
const float flt_8ED9A0; // idb
const float flt_8ED9A4; // idb
double GameTime::global_next_event; // weak
GameTime *GameTime::current_game_time; // idb
const int dword_8ED9BC; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CLOTHING_DEFAULT_0; // idb
IDClass<_tagDataID,32,0> stru_8ED9F4; // idb
IDClass<_tagDataID,32,0> stru_8ED9F8; // idb
IDClass<_tagDataID,32,0> stru_8EDA00; // idb
const float flt_8EDA14; // idb
const float flt_8EDA18; // idb
const float flt_8EDA1C; // idb
float *LandDefs::Land_Height_Table; // weak
float flt_8EDA2C[]; // weak
float flt_8EDA30[]; // weak
float flt_8EDA34[]; // weak
float flt_8EDA38[]; // weak
float flt_8EDA3C[]; // weak
float flt_8EDA40[]; // weak
float flt_8EDA44[]; // weak
const float flt_8EDE40; // idb
const float flt_8EDE44; // idb
const float flt_8EDE48; // idb
float PhysicsGlobals::floor_z; // weak
long double PhysicsTimer::curr_time; // idb
const float flt_8EDE90; // idb
const float flt_8EDE94; // idb
const float flt_8EDE98; // idb
const struct NetError ID_NetError_BadServerAddress; // weak
int dword_8EDEB8; // weak
int dword_8EDEBC; // weak
const struct NetError ID_NetError_CantBind; // weak
int dword_8EDEC4; // weak
int dword_8EDEC8; // weak
const struct NetError ID_NetError_CantSocket; // weak
int dword_8EDED0; // weak
int dword_8EDED4; // weak
const struct NetError ID_NetError_CantCrypto; // weak
int dword_8EDEDC; // weak
int dword_8EDEE0; // weak
NetError ID_NetError_AbortedHandshake; // idb
NetError ID_ConnectionError_RunningSpeedhack; // idb
const struct NetError ID_ConnectionError_NoLogonServer; // weak
int dword_8EDF00; // weak
int dword_8EDF04; // weak
const struct NetError ID_ConnectionError_NetVersionMismatch; // weak
int dword_8EDF0C; // weak
int dword_8EDF10; // weak
const struct NetError ID_ConnectionError_ServerFull; // weak
int dword_8EDF18; // weak
int dword_8EDF1C; // weak
const struct NetError ID_ConnectionError_BadCryptoKey; // weak
int dword_8EDF24; // weak
int dword_8EDF28; // weak
const struct NetError ID_ConnectionError_InsufficientPriveledge; // weak
int dword_8EDF30; // weak
int dword_8EDF34; // weak
const struct NetError ID_ConnectionError_SecondLogon; // weak
int dword_8EDF3C; // weak
int dword_8EDF40; // weak
const struct NetError ID_ConnectionError_ServerClosedConnection; // weak
int dword_8EDF48; // weak
int dword_8EDF4C; // weak
const struct NetError ID_ConnectionError_ServerTimedOutClient; // weak
int dword_8EDF54; // weak
int dword_8EDF58; // weak
NetError ID_ConnectionError_ClientTimedOutServer; // idb
const struct NetError ID_ConnectionError_PlayerAlreadyLoggedOn; // weak
int dword_8EDF6C; // weak
int dword_8EDF70; // weak
const struct NetError ID_ConnectionError_ClientLogOnFailed; // weak
int dword_8EDF78; // weak
int dword_8EDF7C; // weak
const struct NetError ID_ConnectionError_AccountAuthenticationFailed; // weak
int dword_8EDF84; // weak
int dword_8EDF88; // weak
const struct NetError ID_ConnectionError_LogonServerMigrated; // weak
int dword_8EDF90; // weak
int dword_8EDF94; // weak
NetError ID_ConnectionError_Generic; // idb
const int dword_8EDFA4; // idb
const int dword_8EDFA8; // idb
const int dword_8EDFB0; // idb
unsigned __int32 NetInitializer::s_RefCount; // weak
CrashCleaner NetInitializer::S_sockerCleaner; // idb
struct COptionalHeaderFactory::CPlugin *COptionalHeaderFactory::s_FactoryPlugins; // weak
int dword_8EDFCC[]; // weak
int COptionalHeaderFactory::s_nPlugins; // weak
const int dword_8EE0D0; // idb
IDClass<_tagDataID,32,0> stru_8EE0F0; // idb
IDClass<_tagDataID,32,0> stru_8EE0F8; // idb
IDClass<_tagDataID,32,0> stru_8EE100; // idb
int AC1Legacy::PStringBase<char>::s_NullBuffer; // weak
AC1Legacy::PStringBase<char> AC1Legacy::PStringBase<char>::null_string; // idb
AC1Legacy::PStringBase<char> AC1Legacy::PStringBase<char>::whitespace_string; // idb
int AC1Legacy::PStringBase<unsigned short>::s_NullBuffer; // weak
int AC1Legacy::PStringBase<unsigned short>::null_string; // weak
AC1Legacy::PStringBase<unsigned short> AC1Legacy::PStringBase<unsigned short>::whitespace_string; // idb
PStringBase<char> waveform_None_69; // idb
PStringBase<char> waveform_Speed_69; // idb
PStringBase<char> waveform_Noise_69; // idb
PStringBase<char> waveform_Sine_69; // idb
PStringBase<char> waveform_Square_69; // idb
PStringBase<char> waveform_Bounce_69; // idb
PStringBase<char> waveform_Perlin_69; // idb
PStringBase<char> waveform_Fractal_69; // idb
PStringBase<char> waveform_FrameLoop_69; // idb
const struct BBox BBox::s_cZeroAABB; // weak
const float flt_8EE194; // idb
const float flt_8EE198; // idb
const float flt_8EE19C; // idb
PStringBase<char> KW_NULL_2; // idb
PStringBase<char> KW_MIN; // idb
PStringBase<char> KW_MAX; // idb
PStringBase<char> KW_BBOX; // idb
PStringBase<char> KW_TRANSFORM; // idb
PStringBase<char> KW_HALF_BOX_EXTENT; // idb
PStringBase<char> KW_FRAME; // idb
float flt_8EE1CC[]; // weak
float g1[514]; // idb
int p[514]; // idb
long double exponent_array[51]; // idb
long double lastH; // idb
const float flt_8EF3A4; // idb
const float flt_8EF3A8; // idb
const float flt_8EF3AC; // idb
const float flt_8EF3E8; // idb
const float flt_8EF3EC; // idb
const float flt_8EF3F0; // idb
const float flt_8EF408; // idb
const float flt_8EF40C; // idb
const float flt_8EF410; // idb
const float flt_8EF434; // idb
const float flt_8EF438; // idb
const float flt_8EF43C; // idb
const float flt_8EF454; // idb
const float flt_8EF458; // idb
const float flt_8EF45C; // idb
const float flt_8EF474; // idb
const float flt_8EF478; // idb
const float flt_8EF47C; // idb
IDClass<_tagDataID,32,0> stru_8EF488; // idb
const float flt_8EF4A8; // idb
const float flt_8EF4AC; // idb
const float flt_8EF4B0; // idb
const float flt_8EF4C8; // idb
const float flt_8EF4CC; // idb
const float flt_8EF4D0; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_5; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_5; // idb
IDClass<_tagDataID,32,0> stru_8EF540; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_6; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_5; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_6; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_6; // idb
IDClass<_tagDataID,32,0> stru_8EF5C0; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_7; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_6; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_7; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_7; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_8; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_7; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_8; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_8; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_9; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_8; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_9; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_9; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_10; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_9; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_10; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_10; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_11; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_10; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_11; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_11; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_12; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_11; // idb
IDClass<_tagDataID,32,0> stru_8EF864; // idb
const float flt_8EF868; // idb
const float flt_8EF86C; // idb
const float flt_8EF870; // idb
IDClass<_tagDataID,32,0> UNDEAD_MALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> UNDEAD_FEMALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> UMBRAEN_MALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> UMBRAEN_FEMALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_MALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> PENUMBRAEN_FEMALE_CLOTHING_DEFAULT_1; // idb
IDClass<_tagDataID,32,0> stru_8EF8B4; // idb
const float flt_8EF8B8; // idb
const float flt_8EF8BC; // idb
const float flt_8EF8C0; // idb
IDClass<_tagDataID,32,0> stru_8EF8DC; // idb
const float flt_8EF8E0; // idb
const float flt_8EF8E4; // idb
const float flt_8EF8E8; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_12; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_12; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_13; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_12; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_13; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_13; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_14; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_13; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_14; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_14; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_15; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_14; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_15; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_15; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_16; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_15; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_16; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_16; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_17; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_16; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_17; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_17; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_18; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_17; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_18; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_18; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_19; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_18; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_19; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_19; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_20; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_19; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_20; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_20; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_21; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_20; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_21; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_21; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_22; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_21; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_22; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_22; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_23; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_22; // idb
const float flt_8EFE7C; // idb
const float flt_8EFE80; // idb
const float flt_8EFE84; // idb
IDClass<_tagDataID,32,0> stru_8EFEC0; // idb
const float flt_8EFEC4; // idb
const float flt_8EFEC8; // idb
const float flt_8EFECC; // idb
const float flt_8EFEE0; // idb
const float flt_8EFEE4; // idb
const float flt_8EFEE8; // idb
IDClass<_tagDataID,32,0> stru_8EFEEC; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::Allegiance_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::General_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::Trade_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::LFG_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::Roleplay_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::Society_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::SocietyCelHan_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::SocietyEldWeb_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::SocietyRadBlo_GlobalChannelName; // idb
AC1Legacy::PStringBase<unsigned short> ChannelSystem::Olthoi_GlobalChannelName; // idb
const float flt_8EFF2C; // idb
const float flt_8EFF30; // idb
const float flt_8EFF34; // idb
const float flt_8EFF48; // idb
const float flt_8EFF4C; // idb
const float flt_8EFF50; // idb
const float flt_8EFF6C; // idb
const float flt_8EFF70; // idb
const float flt_8EFF74; // idb
IDClass<_tagDataID,32,0> stru_8EFF88; // idb
const float flt_8EFF8C; // idb
const float flt_8EFF90; // idb
const float flt_8EFF94; // idb
IDClass<_tagDataID,32,0> stru_8EFF9C; // idb
const float flt_8EFFB8; // idb
const float flt_8EFFBC; // idb
const float flt_8EFFC0; // idb
IDClass<_tagDataID,32,0> stru_8EFFD4; // idb
IDClass<_tagDataID,32,0> stru_8EFFDC; // idb
Vector3 stru_8EFFFC; // idb
PStringBase<char> PHeader_11; // idb
PStringBase<char> VertexArray_9; // idb
PStringBase<char> BinaryVertexArray_9; // idb
PStringBase<char> VertexType_10; // idb
PStringBase<char> VertexData_9; // idb
PStringBase<char> Vertex_9; // idb
PStringBase<char> Index_19; // idb
PStringBase<char> Origin_19; // idb
PStringBase<char> Normal_9; // idb
PStringBase<char> Diffuse_19; // idb
PStringBase<char> Specular_19; // idb
PStringBase<char> UVS_9; // idb
PStringBase<char> VectorS_9; // idb
PStringBase<char> VectorT_9; // idb
PStringBase<char> VectorSxT_9; // idb
PStringBase<char> Weights_9; // idb
PStringBase<char> Importance_9; // idb
PStringBase<char> PhysMtl_9; // idb
PStringBase<char> Material_42; // idb
PStringBase<char> ID_22; // idb
PStringBase<char> FileName_9; // idb
PStringBase<char> Polygon_19; // idb
PStringBase<char> ID_23; // idb
PStringBase<char> Indices_15; // idb
PStringBase<char> MaterialID_9; // idb
PStringBase<char> PhysMaterialID_9; // idb
PStringBase<char> Markings_9; // idb
PStringBase<char> Material_43; // idb
PStringBase<char> Index_20; // idb
PStringBase<char> Filename_9; // idb
PStringBase<char> Surface_9; // idb
PStringBase<char> CellPoly_9; // idb
PStringBase<char> Sphere_12; // idb
PStringBase<char> Side_9; // idb
PStringBase<char> Positive_9; // idb
PStringBase<char> Negative_9; // idb
PStringBase<char> Polygon_20; // idb
PStringBase<char> OtherCell_19; // idb
PStringBase<char> CellPortal_9; // idb
PStringBase<char> Portal_12; // idb
PStringBase<char> OtherCell_20; // idb
PStringBase<char> OtherPortal_9; // idb
PStringBase<char> ExactMatch_9; // idb
PStringBase<char> StabList_9; // idb
PStringBase<char> Period_9; // idb
PStringBase<char> GrannyAnimation_9; // idb
PStringBase<char> Transform_9; // idb
PStringBase<char> Scale_29; // idb
PStringBase<char> Weight_9; // idb
PStringBase<char> Offset_9; // idb
PStringBase<char> Quaternion_10; // idb
PStringBase<char> Rotation_19; // idb
PStringBase<char> STime_9; // idb
PStringBase<char> PhysicsSplines_9; // idb
PStringBase<char> BoneOpacities_9; // idb
PStringBase<char> LowPt_9; // idb
PStringBase<char> Radius_9; // idb
PStringBase<char> Height_9; // idb
PStringBase<char> Texture2D_9; // idb
PStringBase<char> Texture3D_9; // idb
PStringBase<char> TextureCube_9; // idb
PStringBase<char> TextureMovie2D_9; // idb
PStringBase<char> MovieFileName_9; // idb
PStringBase<char> MovieFramesPerSecond_9; // idb
PStringBase<char> Levels_9; // idb
PStringBase<char> stru_8F010C; // idb
PStringBase<char> Material_44; // idb
PStringBase<char> MaterialType_9; // idb
PStringBase<char> Modifier_9; // idb
PStringBase<char> AllowStencilShadows_9; // idb
PStringBase<char> DiscardGeometry_9; // idb
PStringBase<char> stru_8F0124; // idb
PStringBase<char> SortMode_9; // idb
PStringBase<char> SortMode_None_9; // idb
PStringBase<char> SortMode_Triangle_9; // idb
PStringBase<char> stru_8F0134; // idb
PStringBase<char> stru_8F0138; // idb
PStringBase<char> DataType_DATA_9; // idb
PStringBase<char> DataType_WAVEFORM_9; // idb
PStringBase<char> DataType_COLOR_9; // idb
PStringBase<char> DataType_TEXTURE_9; // idb
PStringBase<char> DataType_BOOL_9; // idb
PStringBase<char> stru_8F0150; // idb
PStringBase<char> modType_UVTranslate_9; // idb
PStringBase<char> modType_UVRotate_9; // idb
PStringBase<char> modType_UVScale_9; // idb
PStringBase<char> modType_UVTransform_9; // idb
PStringBase<char> TrueFlags_9; // idb
PStringBase<char> FalseFlags_9; // idb
PStringBase<char> RenderPass_9; // idb
PStringBase<char> Blend_9; // idb
PStringBase<char> DepthTest_9; // idb
PStringBase<char> DepthWrite_9; // idb
PStringBase<char> CullMode_9; // idb
PStringBase<char> DepthFog_9; // idb
PStringBase<char> AlphaTestMode_9; // idb
PStringBase<char> AlphaTestRef_9; // idb
PStringBase<char> FFUseLighting_9; // idb
PStringBase<char> FFUseDyeColorInTFactor_9; // idb
PStringBase<char> FFUseSpecularLighting_9; // idb
PStringBase<char> FFUseDistanceFog_9; // idb
PStringBase<char> FFUseVertexDiffuse_9; // idb
PStringBase<char> FFUseVertexSpecular_9; // idb
PStringBase<char> ShaderSupportsDynamicLights_9; // idb
PStringBase<char> UsesTransparency_9; // idb
PStringBase<char> Ambient_9; // idb
PStringBase<char> Diffuse_20; // idb
PStringBase<char> Specular_20; // idb
PStringBase<char> SpecularPower_9; // idb
PStringBase<char> Dye_9; // idb
PStringBase<char> Emissive_9; // idb
PStringBase<char> VertexFormat_9; // idb
PStringBase<char> VertexShader_9; // idb
PStringBase<char> PixelShader_9; // idb
PStringBase<char> param_MLF_NONE_9; // idb
PStringBase<char> param_MLF_REFLECTIONS_9; // idb
PStringBase<char> param_MLF_VIDEOPOST_9; // idb
PStringBase<char> param_MLF_HIGHDETAIL_9; // idb
PStringBase<char> param_MLF_SPECULAR_9; // idb
PStringBase<char> param_MLF_CLASS1_9; // idb
PStringBase<char> param_MLF_CLASS2_9; // idb
PStringBase<char> param_MLF_CLASS3_9; // idb
PStringBase<char> param_RenderPass_Default_9; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_9; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_9; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_9; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_9; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_9; // idb
PStringBase<char> param_RenderPass_DistanceFog_9; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_9; // idb
PStringBase<char> param_RenderPass_ShaderGlow_9; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_9; // idb
PStringBase<char> param_RenderPass_AlphaBlend_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_9; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_9; // idb
PStringBase<char> param_BLEND_ZERO_9; // idb
PStringBase<char> param_BLEND_ONE_9; // idb
PStringBase<char> param_BLEND_SRCCOLOR_9; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_9; // idb
PStringBase<char> param_BLEND_SRCALPHA_9; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_9; // idb
PStringBase<char> param_BLEND_DSTALPHA_9; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_9; // idb
PStringBase<char> param_BLEND_DSTCOLOR_9; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_9; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_9; // idb
PStringBase<char> param_DEPTHTEST_LESS_9; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_9; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_9; // idb
PStringBase<char> param_DEPTHTEST_GREATER_9; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_9; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_9; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_9; // idb
PStringBase<char> param_DEPTHWRITE_ON_9; // idb
PStringBase<char> param_DEPTHWRITE_OFF_9; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_9; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_9; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_9; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_9; // idb
PStringBase<char> param_CULLMODE_NONE_9; // idb
PStringBase<char> param_CULLMODE_CW_9; // idb
PStringBase<char> param_CULLMODE_CCW_9; // idb
PStringBase<char> param_LIGHTMODE_NONE_9; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_9; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_9; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_9; // idb
PStringBase<char> param_DEPTHFOG_OFF_9; // idb
PStringBase<char> param_DEPTHFOG_ON_9; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_9; // idb
PStringBase<char> param_ALPHATESTMODE_ON_9; // idb
PStringBase<char> param_VF_ORIGIN_9; // idb
PStringBase<char> param_VF_NORMAL_9; // idb
PStringBase<char> param_VF_POINTSIZE_9; // idb
PStringBase<char> param_VF_DIFFUSE_9; // idb
PStringBase<char> param_VF_SPECULAR_9; // idb
PStringBase<char> param_VF_TCPAIRx1_9; // idb
PStringBase<char> param_VF_TCPAIRx2_9; // idb
PStringBase<char> param_VF_TCPAIRx3_9; // idb
PStringBase<char> param_VF_TCPAIRx4_9; // idb
PStringBase<char> param_VF_TCPAIRx5_9; // idb
PStringBase<char> param_VF_TCPAIRx6_9; // idb
PStringBase<char> param_VF_TCPAIRx7_9; // idb
PStringBase<char> param_VF_TCPAIRx8_9; // idb
PStringBase<char> param_VF_VECTOR_S_9; // idb
PStringBase<char> param_VF_VECTOR_T_9; // idb
PStringBase<char> stru_8F036C; // idb
PStringBase<char> SamplerNodeName_9; // idb
PStringBase<char> SamplerName_9; // idb
PStringBase<char> Texture_9; // idb
PStringBase<char> SpecialTexture_FrameBuffer_9; // idb
PStringBase<char> SpecialTexture_Distortion_9; // idb
PStringBase<char> SpecialTexture_Reflection_9; // idb
PStringBase<char> SpecialTexture_NormalizeCube_9; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_9; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_9; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_9; // idb
PStringBase<char> AddressMode_9; // idb
PStringBase<char> TexFilter_9; // idb
PStringBase<char> ColorOp_9; // idb
PStringBase<char> ColorArg1_9; // idb
PStringBase<char> ColorArg2_9; // idb
PStringBase<char> AlphaOp_9; // idb
PStringBase<char> AlphaArg1_9; // idb
PStringBase<char> AlphaArg2_9; // idb
PStringBase<char> TexCoord_9; // idb
PStringBase<char> UseProjection_9; // idb
PStringBase<char> param_TEXOP_SELECTARG1_9; // idb
PStringBase<char> param_TEXOP_SELECTARG2_9; // idb
PStringBase<char> param_TEXOP_MODULATE_9; // idb
PStringBase<char> param_TEXOP_MODULATE2X_9; // idb
PStringBase<char> param_TEXOP_MODULATE4X_9; // idb
PStringBase<char> param_TEXOP_ADD_9; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_9; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_9; // idb
PStringBase<char> param_TEXOP_SUBTRACT_9; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_9; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_9; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_9; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_9; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_9; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_9; // idb
PStringBase<char> param_TEXOP_PREMODULATE_9; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_9; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_9; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_9; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_9; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_9; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_9; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_9; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_9; // idb
PStringBase<char> param_TEXOP_LERP_9; // idb
PStringBase<char> param_TEXARG_DIFFUSE_9; // idb
PStringBase<char> param_TEXARG_SPECULAR_9; // idb
PStringBase<char> param_TEXARG_CURRENT_9; // idb
PStringBase<char> param_TEXARG_TEXTURE_9; // idb
PStringBase<char> param_TEXARG_TFACTOR_9; // idb
PStringBase<char> param_TEXADDRESS_WRAP_9; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_9; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_9; // idb
PStringBase<char> param_TEXADDRESS_BORDER_9; // idb
PStringBase<char> param_TEXFILTER_NONE_9; // idb
PStringBase<char> param_TEXFILTER_POINT_9; // idb
PStringBase<char> param_TEXFILTER_LINEAR_9; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_9; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_9; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_9; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_9; // idb
PStringBase<char> param_TEXCOORD_SphereMap_9; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_9; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_9; // idb
PStringBase<char> stru_8F0470; // idb
PStringBase<char> ModType_Origin_9; // idb
PStringBase<char> ModType_Normal_9; // idb
PStringBase<char> ModType_Diffuse_9; // idb
PStringBase<char> ModType_UVTranslate_9; // idb
PStringBase<char> ModType_UVRotate_9; // idb
PStringBase<char> ModType_UVScale_9; // idb
PStringBase<char> ModType_UVTransform_9; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_9; // idb
PStringBase<char> Mod_UVTranslate_translate_9; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_9; // idb
PStringBase<char> Mod_UVRotate_rotate_9; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_9; // idb
PStringBase<char> Mod_UVScale_scale_9; // idb
PStringBase<char> stru_8F04A8; // idb
PStringBase<char> PhysicsTimeStep_9; // idb
PStringBase<char> FastForwardTime_9; // idb
PStringBase<char> StartFadeDistance_9; // idb
PStringBase<char> StopFadeDistance_9; // idb
PStringBase<char> PhysicsDuration_9; // idb
PStringBase<char> ScaleType_9; // idb
PStringBase<char> WorldSpace_9; // idb
PStringBase<char> ForceDraw_9; // idb
PStringBase<char> NumEmitters_9; // idb
PStringBase<char> Material_45; // idb
PStringBase<char> Version_9; // idb
PStringBase<char> MaxParticles_9; // idb
PStringBase<char> stru_8F04DC; // idb
PStringBase<char> Origin_20; // idb
PStringBase<char> Shape_9; // idb
PStringBase<char> Shape_Point_9; // idb
PStringBase<char> Shape_Line_9; // idb
PStringBase<char> Shape_Quad_9; // idb
PStringBase<char> Shape_Disc_9; // idb
PStringBase<char> Shape_Sphere_9; // idb
PStringBase<char> ParticleShape_9; // idb
PStringBase<char> ParticleShape_Triangle_9; // idb
PStringBase<char> ParticleShape_Quad_9; // idb
PStringBase<char> Streak_9; // idb
PStringBase<char> Rotation_20; // idb
PStringBase<char> WorldRotation_9; // idb
PStringBase<char> RotateVelocity_9; // idb
PStringBase<char> ParticleScale_9; // idb
PStringBase<char> Scale_30; // idb
PStringBase<char> ExplodingDir_9; // idb
PStringBase<char> BirthRate_9; // idb
PStringBase<char> Lifespan_9; // idb
PStringBase<char> Velocity_9; // idb
PStringBase<char> Direction_9; // idb
PStringBase<char> MinSpread_9; // idb
PStringBase<char> MaxSpread_9; // idb
PStringBase<char> EmissionLimit_9; // idb
PStringBase<char> BlastCount_9; // idb
PStringBase<char> StartTime_9; // idb
PStringBase<char> TimeLimit_9; // idb
PStringBase<char> EmissionDistance_9; // idb
PStringBase<char> ParticleSnap_9; // idb
PStringBase<char> InclusiveShape_9; // idb
PStringBase<char> NumKeyframes_9; // idb
PStringBase<char> IsActive_9; // idb
PStringBase<char> FadeIn_9; // idb
PStringBase<char> FadeOut_9; // idb
PStringBase<char> ConstrainX_9; // idb
PStringBase<char> ConstrainY_9; // idb
PStringBase<char> ConstrainZ_9; // idb
PStringBase<char> stru_8F0574; // idb
PStringBase<char> Time_9; // idb
PStringBase<char> Flags_9; // idb
PStringBase<char> Flags_None_9; // idb
PStringBase<char> Flags_BlendScale_9; // idb
PStringBase<char> Flags_BlendColor_9; // idb
PStringBase<char> Flags_BlendMass_9; // idb
PStringBase<char> Flags_SetScale_9; // idb
PStringBase<char> Flags_SetColor_9; // idb
PStringBase<char> Flags_SetMass_9; // idb
PStringBase<char> Flags_SetPFlags_9; // idb
PStringBase<char> Flags_SetPCType_9; // idb
PStringBase<char> Flags_SetPhysFlags_9; // idb
PStringBase<char> Flags_SetParams_9; // idb
PStringBase<char> Scale_31; // idb
PStringBase<char> ScaleX_9; // idb
PStringBase<char> ScaleY_9; // idb
PStringBase<char> Color_9; // idb
PStringBase<char> Mass_9; // idb
PStringBase<char> PFlags_9; // idb
PStringBase<char> PFlags_None_9; // idb
PStringBase<char> PCType_9; // idb
PStringBase<char> PCType_None_9; // idb
PStringBase<char> PCType_Physics_9; // idb
PStringBase<char> PCType_Parametric_9; // idb
PStringBase<char> PCType_AttractRepulse_9; // idb
PStringBase<char> PCType_PointFile_9; // idb
PStringBase<char> PCType_PointFileLerp_9; // idb
PStringBase<char> PhysFlags_9; // idb
PStringBase<char> PhysFlags_None_9; // idb
PStringBase<char> PhysFlags_Gravity_9; // idb
PStringBase<char> PhysFlags_Wind_9; // idb
PStringBase<char> PhysFlags_Momentum_9; // idb
PStringBase<char> PointfileFlags_RandomPoint_9; // idb
PStringBase<char> Position_10; // idb
PStringBase<char> PointList_9; // idb
PStringBase<char> Point_20; // idb
PStringBase<char> DetailLevels_9; // idb
PStringBase<char> DetailLevel_Low_9; // idb
PStringBase<char> DetailLevel_Medium_9; // idb
PStringBase<char> DetailLevel_High_9; // idb
PStringBase<char> FadeSpeed_9; // idb
PStringBase<char> MaxOpacity_9; // idb
PStringBase<char> Point_21; // idb
PStringBase<char> PointAxisPos_9; // idb
PStringBase<char> PointTexture_9; // idb
PStringBase<char> PointSize_9; // idb
PStringBase<char> UseOcclusion_9; // idb
PixelFormatDesc stru_8F0634; // idb
const float dword_8F066C; // idb
const float flt_8F0670; // idb
const float flt_8F0674; // idb
const float flt_8F0678; // idb
PStringBase<char> Render_TextureFiltering_42; // idb
PStringBase<char> Render_LandscapeDetailTextures_42; // idb
PStringBase<char> Render_BuildingDetailTextures_42; // idb
PStringBase<char> Render_FieldOfView_42; // idb
PStringBase<char> Render_LandscapeTextureDetail_42; // idb
PStringBase<char> Render_EnvironmentTextureDetail_42; // idb
PStringBase<char> Render_SceneryDrawDistance_42; // idb
PStringBase<char> Render_LandscapeDrawDistance_42; // idb
PStringBase<char> Render_ScreenBrightness_42; // idb
PStringBase<char> Render_AspectRatio_42; // idb
PStringBase<char> Render_DisplayAdapter_42; // idb
PStringBase<char> Render_MaxHardwareClass_42; // idb
PStringBase<char> Render_AutomaticDegrades_42; // idb
PStringBase<char> Render_GraphicsPerformance_42; // idb
PStringBase<char> Render_DegradeDistance_42; // idb
PStringBase<char> Render_MultiPassAlpha_42; // idb
PStringBase<char> Render_TextureFiltering_Choices_42[4]; // idb
PStringBase<char> stru_8F06C4; // idb
PStringBase<char> stru_8F06C8; // idb
PStringBase<char> stru_8F06CC; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_42[5]; // idb
PStringBase<char> stru_8F06D4; // idb
PStringBase<char> stru_8F06D8; // idb
PStringBase<char> stru_8F06DC; // idb
PStringBase<char> stru_8F06E0; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_42[5]; // idb
PStringBase<char> stru_8F06E8; // idb
PStringBase<char> stru_8F06EC; // idb
PStringBase<char> stru_8F06F0; // idb
PStringBase<char> stru_8F06F4; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_42[3]; // idb
PStringBase<char> stru_8F06FC; // idb
PStringBase<char> stru_8F0700; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_42[6]; // idb
PStringBase<char> stru_8F0708; // idb
PStringBase<char> stru_8F070C; // idb
PStringBase<char> stru_8F0710; // idb
PStringBase<char> stru_8F0714; // idb
PStringBase<char> stru_8F0718; // idb
PStringBase<char> Render_AspectRatio_Choices_42[3]; // idb
PStringBase<char> stru_8F0720; // idb
PStringBase<char> stru_8F0724; // idb
PStringBase<char> waveform_None_70; // idb
PStringBase<char> waveform_Speed_70; // idb
PStringBase<char> waveform_Noise_70; // idb
PStringBase<char> waveform_Sine_70; // idb
PStringBase<char> waveform_Square_70; // idb
PStringBase<char> waveform_Bounce_70; // idb
PStringBase<char> waveform_Perlin_70; // idb
PStringBase<char> waveform_Fractal_70; // idb
PStringBase<char> waveform_FrameLoop_70; // idb
char txt2[1024]; // idb
char txt1[1024]; // idb
PixelFormatDesc stru_8F0F6C; // idb
const float dword_8F0FA4; // idb
const float flt_8F0FA8; // idb
const float flt_8F0FAC; // idb
const float flt_8F0FB0; // idb
PStringBase<char> Render_TextureFiltering_43; // idb
PStringBase<char> Render_LandscapeDetailTextures_43; // idb
PStringBase<char> Render_BuildingDetailTextures_43; // idb
PStringBase<char> Render_FieldOfView_43; // idb
PStringBase<char> Render_LandscapeTextureDetail_43; // idb
PStringBase<char> Render_EnvironmentTextureDetail_43; // idb
PStringBase<char> Render_SceneryDrawDistance_43; // idb
PStringBase<char> Render_LandscapeDrawDistance_43; // idb
PStringBase<char> Render_ScreenBrightness_43; // idb
PStringBase<char> Render_AspectRatio_43; // idb
PStringBase<char> Render_DisplayAdapter_43; // idb
PStringBase<char> Render_MaxHardwareClass_43; // idb
PStringBase<char> Render_AutomaticDegrades_43; // idb
PStringBase<char> Render_GraphicsPerformance_43; // idb
PStringBase<char> Render_DegradeDistance_43; // idb
PStringBase<char> Render_MultiPassAlpha_43; // idb
PStringBase<char> Render_TextureFiltering_Choices_43[4]; // idb
PStringBase<char> stru_8F0FFC; // idb
PStringBase<char> stru_8F1000; // idb
PStringBase<char> stru_8F1004; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_43[5]; // idb
PStringBase<char> stru_8F100C; // idb
PStringBase<char> stru_8F1010; // idb
PStringBase<char> stru_8F1014; // idb
PStringBase<char> stru_8F1018; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_43[5]; // idb
PStringBase<char> stru_8F1020; // idb
PStringBase<char> stru_8F1024; // idb
PStringBase<char> stru_8F1028; // idb
PStringBase<char> stru_8F102C; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_43[3]; // idb
PStringBase<char> stru_8F1034; // idb
PStringBase<char> stru_8F1038; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_43[6]; // idb
PStringBase<char> stru_8F1040; // idb
PStringBase<char> stru_8F1044; // idb
PStringBase<char> stru_8F1048; // idb
PStringBase<char> stru_8F104C; // idb
PStringBase<char> stru_8F1050; // idb
PStringBase<char> Render_AspectRatio_Choices_43[3]; // idb
PStringBase<char> stru_8F1058; // idb
PStringBase<char> stru_8F105C; // idb
PStringBase<char> waveform_None_71; // idb
PStringBase<char> waveform_Speed_71; // idb
PStringBase<char> waveform_Noise_71; // idb
PStringBase<char> waveform_Sine_71; // idb
PStringBase<char> waveform_Square_71; // idb
PStringBase<char> waveform_Bounce_71; // idb
PStringBase<char> waveform_Perlin_71; // idb
PStringBase<char> waveform_Fractal_71; // idb
PStringBase<char> waveform_FrameLoop_71; // idb
const unsigned int g_BudgetItemColor[6]; // idb
const struct BudgetStatInfo **BudgetStatInfoArray::s_BudgetStatInfo; // weak
int dword_8F10A4; // weak
int dword_8F10A8; // weak
int dword_8F10AC; // weak
int dword_8F10B0; // weak
int dword_8F10B4; // weak
int dword_8F10B8; // weak
_UNKNOWN unk_8F10BC; // weak
enum ProfilerTypes::CategoryType *Profiler::ActiveCategories; // weak
unsigned __int32 Profiler::NumActiveCategories; // weak
_UNKNOWN Profiler::Stats; // weak
_UNKNOWN unk_8F1134; // weak
struct ProfilerStats Profiler::CapturedStats; // weak
int dword_8F13E8; // weak
int dword_8F13EC; // weak
int dword_8F13F0; // weak
int dword_8F13F4; // weak
int dword_8F13F8; // weak
int dword_8F13FC; // weak
int dword_8F1400; // weak
int dword_8F1404; // weak
int dword_8F1408; // weak
int dword_8F140C; // weak
int dword_8F1410; // weak
int dword_8F1414; // weak
int dword_8F1418; // weak
int dword_8F1420; // weak
int dword_8F1424; // weak
int dword_8F142C; // weak
int dword_8F1430; // weak
int dword_8F1434; // weak
int dword_8F1438; // weak
unsigned int i_value; // idb
unsigned int dword_8F1440; // idb
unsigned int dword_8F1444; // idb
int dword_8F1480; // weak
int dword_8F1484; // weak
int dword_8F1488; // weak
int dword_8F148C; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_23; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_23; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_24; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_23; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_24; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_24; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_25; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_24; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_25; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_25; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_26; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_25; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_26; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_26; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_27; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_26; // idb
PStringBase<char> waveform_None_72; // idb
PStringBase<char> waveform_Speed_72; // idb
PStringBase<char> waveform_Noise_72; // idb
PStringBase<char> waveform_Sine_72; // idb
PStringBase<char> waveform_Square_72; // idb
PStringBase<char> waveform_Bounce_72; // idb
PStringBase<char> waveform_Perlin_72; // idb
PStringBase<char> waveform_Fractal_72; // idb
PStringBase<char> waveform_FrameLoop_72; // idb
PStringBase<char> waveform_None_73; // idb
PStringBase<char> waveform_Speed_73; // idb
PStringBase<char> waveform_Noise_73; // idb
PStringBase<char> waveform_Sine_73; // idb
PStringBase<char> waveform_Square_73; // idb
PStringBase<char> waveform_Bounce_73; // idb
PStringBase<char> waveform_Perlin_73; // idb
PStringBase<char> waveform_Fractal_73; // idb
PStringBase<char> waveform_FrameLoop_73; // idb
PStringBase<char> waveform_None_74; // idb
PStringBase<char> waveform_Speed_74; // idb
PStringBase<char> waveform_Noise_74; // idb
PStringBase<char> waveform_Sine_74; // idb
PStringBase<char> waveform_Square_74; // idb
PStringBase<char> waveform_Bounce_74; // idb
PStringBase<char> waveform_Perlin_74; // idb
PStringBase<char> waveform_Fractal_74; // idb
PStringBase<char> waveform_FrameLoop_74; // idb
int _dowildcard; // weak
int _newmode; // weak
int _commode; // weak
int _fmode;
struct IDirect3DDevice9 *D3DXMesh::sm_pD3DDeviceCacheInfo; // weak
unsigned __int32 D3DXMesh::sm_dwCacheSize; // weak
unsigned __int32 D3DXMesh::sm_dwMagicNumber; // weak
int dword_8F1978; // weak
int (__cdecl *dword_8F197C)(_DWORD); // weak
int (__cdecl *dword_8F1980)(_DWORD); // weak
int dword_8F1984; // weak
int dword_8F326C; // weak
unsigned __int64 (__cdecl *__g_rdtsc)(); // weak
void (__cdecl *__g_memzero)(void *, unsigned int); // weak
void (__cdecl *__g_memcpy)(void *, void *, unsigned int); // weak
void (__stdcall *gpfnPostQuitMessage)(int); // weak
int (__stdcall *gpfnPeekMessage)(struct tagMSG *, HWND, unsigned int, unsigned int, unsigned int); // weak
int (__stdcall *gpfnMessageBox)(HWND, const char *, const char *, unsigned int); // weak
int (*gpfnwsprintf)(char *, const char *, ...); // weak
int dword_8F75C0; // weak
int dword_8F75C4; // weak
int dword_8F75C8; // weak
int dword_8F75CC; // weak
int dword_8F75D0; // weak
int dword_8F75D4; // weak
char byte_8F75D8; // weak
char byte_8F75D9; // weak
char byte_8F75DA; // weak
char byte_8F75DB; // weak
char byte_8F75DC; // weak
char byte_8F75DD; // weak
char byte_8F75DE; // weak
char byte_8F75DF; // weak
char byte_8F75E0; // weak
char byte_8F75E1; // weak
char byte_8F75E2; // weak
char byte_8F75E3; // weak
char byte_8F75E4; // weak
const unsigned int LC_IError_CriticalError; // idb
const unsigned int LC_IError_GeneralError; // idb
const unsigned int LC_IError_DataError; // idb
const unsigned int LC_IError_UserError; // idb
PStringBase<char> TRUE_PSTRING; // idb
PStringBase<char> FALSE_PSTRING; // idb
PStringBase<char> ONE_PSTRING; // idb
PStringBase<char> unknown_file; // idb
unsigned int _S76_1; // idb
FallocPool PFileNode::s_fallocPool; // idb
_UNKNOWN Matrix4::NULL_MATRIX4; // weak
IDClass<_tagVersionHandle,32,0> INVALID_VERSIONHANDLE_29; // idb
AsyncContext INVALID_ASYNCCONTEXT_34; // idb
const struct Heading Heading::ZERO; // weak
const struct Heading Heading::EPSILON; // weak
bool s_bUseSSE; // idb
bool s_CheckedForSSE; // idb
BlitPixel g_SourceColor; // idb
IDClass<_tagDataID,32,0> stru_8F76B4; // idb
_UNKNOWN g_DummyCachePack; // weak
SmartBuffer stru_8F76C0; // idb
IDClass<_tagDataID,32,0> stru_8F76D8; // idb
IDClass<_tagDataID,32,0> stru_8F76E0; // idb
IDClass<_tagDataID,32,0> stru_8F76E4; // idb
IDClass<_tagDataID,32,0> stru_8F7700; // idb
IDClass<_tagDataID,32,0> stru_8F7704; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_27; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_27; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_28; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_27; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_28; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_28; // idb
struct StringTableMetaLanguage::RenderErr StringTableMetaLanguage::curError; // weak
int dword_8F77FC; // weak
PStringBase<char> stru_8F7800; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_29; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_28; // idb
StringTableMetaLanguage::Node *StringTableMetaLanguage::g_curNode; // idb
StringTableMetaLanguage::Node *StringTableMetaLanguage::g_Root; // idb
struct Node *StringTableMetaLanguage::g_lastAddedNode; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_29; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_29; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_30; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_29; // idb
int stringmeta_nerrs; // weak
int stringmeta_char; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_30; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_30; // idb
PStringBase<unsigned short> stringmeta_lval; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_31; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_30; // idb
unsigned int g_inputidx; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_31; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_31; // idb
PStringBase<unsigned short> g_input; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_32; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_31; // idb
IDClass<_tagDataID,32,0> stru_8F79AC; // idb
IDClass<_tagDataID,32,0> stru_8F79BC; // idb
PStringBase<char> PHeader_12; // idb
PStringBase<char> KW_PROPERTIES; // idb
IDClass<_tagDataID,32,0> stru_8F79CC; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_32; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_32; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_33; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_32; // idb
PerfMonCounterManager *PerfMonCounterManager::Sm_pPerfMonCounterManager; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_33; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_33; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_34; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_33; // idb
CrashCleaner G_PerfmonCounterManager; // idb
int dword_8F7ACC; // weak
List<PerfMonCounterInfo *> stru_8F7AD0; // idb
char byte_8F7AE0; // weak
IDClass<_tagCellID,16,65535> In_Limbo_CellID_34; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_34; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_35; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_34; // idb
AC1Legacy::PStringBase<char> ignore1_0; // idb
AC1Legacy::PStringBase<char> ignore2_0; // idb
IDClass<_tagDataID,32,0> stru_8F7B88; // idb
PStringBase<char> KW_INPUTMAPCONFLICTS; // idb
PStringBase<char> KW_ACTIONMAPS; // idb
PStringBase<char> KW_TOGGLETYPE; // idb
PStringBase<char> KW_USERBINDING; // idb
PStringBase<char> KW_CATEGORY; // idb
PStringBase<char> KW_DESCRIPTION; // idb
PStringBase<char> KW_NAME; // idb
PStringBase<char> KW_ABOUT; // idb
tagPOINT ptPreviousMousePos; // idb
unsigned int _S139_6; // idb
char prevLeadByte; // idb
PStringBase<char> Misc_TooltipEnable_48; // idb
PStringBase<char> Misc_TooltipDelay_48; // idb
const float dword_8F7BE4; // idb
const float flt_8F7BE8; // idb
const float flt_8F7BEC; // idb
const float flt_8F7BF0; // idb
PixelFormatDesc stru_8F7BF8; // idb
PStringBase<char> Display_Resolution_38; // idb
PStringBase<char> Display_FullScreen_38; // idb
PStringBase<char> Display_RefreshRate_38; // idb
PStringBase<char> Display_SyncToRefresh_38; // idb
const float flt_8F7C40; // idb
const long double dbl_8F7C48; // idb
const long double dbl_8F7C50; // idb
const unsigned int ID_KeyDescDelimiter; // idb
const unsigned int ID_KeyNameWithSubControl; // idb
const unsigned int KEY_0; // idb
const unsigned int SUBCONTROL; // idb
unsigned __int32 CInputManager_WIN32::sm_timeDoubleClick; // weak
unsigned __int32 CInputManager_WIN32::sm_timeTap; // weak
int CInputManager_WIN32::sm_cxDblClick; // idb
int CInputManager_WIN32::sm_cyDblClick; // idb
ControlNameMapper g_ControlNameMapper; // idb
const unsigned int ID_sci_PositiveAxis; // idb
const unsigned int ID_sci_NegativeAxis; // idb
const unsigned int ID_sci_POVUp; // idb
const unsigned int ID_sci_POVRight; // idb
const unsigned int ID_sci_POVDown; // idb
const unsigned int ID_sci_POVLeft; // idb
PStringBase<char> PHeader_13; // idb
PStringBase<char> VertexArray_10; // idb
PStringBase<char> BinaryVertexArray_10; // idb
PStringBase<char> VertexType_11; // idb
PStringBase<char> VertexData_10; // idb
PStringBase<char> Vertex_10; // idb
PStringBase<char> Index_21; // idb
PStringBase<char> Origin_21; // idb
PStringBase<char> Normal_10; // idb
PStringBase<char> Diffuse_21; // idb
PStringBase<char> Specular_21; // idb
PStringBase<char> UVS_10; // idb
PStringBase<char> VectorS_10; // idb
PStringBase<char> VectorT_10; // idb
PStringBase<char> VectorSxT_10; // idb
PStringBase<char> Weights_10; // idb
PStringBase<char> Importance_10; // idb
PStringBase<char> PhysMtl_10; // idb
PStringBase<char> Material_46; // idb
PStringBase<char> ID_24; // idb
PStringBase<char> FileName_10; // idb
PStringBase<char> Polygon_21; // idb
PStringBase<char> ID_25; // idb
PStringBase<char> Indices_16; // idb
PStringBase<char> MaterialID_10; // idb
PStringBase<char> PhysMaterialID_10; // idb
PStringBase<char> Markings_10; // idb
PStringBase<char> Material_47; // idb
PStringBase<char> Index_22; // idb
PStringBase<char> Filename_10; // idb
PStringBase<char> Surface_10; // idb
PStringBase<char> CellPoly_10; // idb
PStringBase<char> Sphere_13; // idb
PStringBase<char> Side_10; // idb
PStringBase<char> Positive_10; // idb
PStringBase<char> Negative_10; // idb
PStringBase<char> Polygon_22; // idb
PStringBase<char> OtherCell_21; // idb
PStringBase<char> CellPortal_10; // idb
PStringBase<char> Portal_13; // idb
PStringBase<char> OtherCell_22; // idb
PStringBase<char> OtherPortal_10; // idb
PStringBase<char> ExactMatch_10; // idb
PStringBase<char> StabList_10; // idb
PStringBase<char> Period_10; // idb
PStringBase<char> GrannyAnimation_10; // idb
PStringBase<char> Transform_10; // idb
PStringBase<char> Scale_32; // idb
PStringBase<char> Weight_10; // idb
PStringBase<char> Offset_10; // idb
PStringBase<char> Quaternion_11; // idb
PStringBase<char> Rotation_21; // idb
PStringBase<char> STime_10; // idb
PStringBase<char> PhysicsSplines_10; // idb
PStringBase<char> BoneOpacities_10; // idb
PStringBase<char> LowPt_10; // idb
PStringBase<char> Radius_10; // idb
PStringBase<char> Height_10; // idb
PStringBase<char> Texture2D_10; // idb
PStringBase<char> Texture3D_10; // idb
PStringBase<char> TextureCube_10; // idb
PStringBase<char> TextureMovie2D_10; // idb
PStringBase<char> MovieFileName_10; // idb
PStringBase<char> MovieFramesPerSecond_10; // idb
PStringBase<char> Levels_10; // idb
PStringBase<char> stru_8F7F70; // idb
PStringBase<char> Material_48; // idb
PStringBase<char> MaterialType_10; // idb
PStringBase<char> Modifier_10; // idb
PStringBase<char> AllowStencilShadows_10; // idb
PStringBase<char> DiscardGeometry_10; // idb
PStringBase<char> stru_8F7F88; // idb
PStringBase<char> SortMode_10; // idb
PStringBase<char> SortMode_None_10; // idb
PStringBase<char> SortMode_Triangle_10; // idb
PStringBase<char> stru_8F7F98; // idb
PStringBase<char> stru_8F7F9C; // idb
PStringBase<char> DataType_DATA_10; // idb
PStringBase<char> DataType_WAVEFORM_10; // idb
PStringBase<char> DataType_COLOR_10; // idb
PStringBase<char> DataType_TEXTURE_10; // idb
PStringBase<char> DataType_BOOL_10; // idb
PStringBase<char> stru_8F7FB4; // idb
PStringBase<char> modType_UVTranslate_10; // idb
PStringBase<char> modType_UVRotate_10; // idb
PStringBase<char> modType_UVScale_10; // idb
PStringBase<char> modType_UVTransform_10; // idb
PStringBase<char> TrueFlags_10; // idb
PStringBase<char> FalseFlags_10; // idb
PStringBase<char> RenderPass_10; // idb
PStringBase<char> Blend_10; // idb
PStringBase<char> DepthTest_10; // idb
PStringBase<char> DepthWrite_10; // idb
PStringBase<char> CullMode_10; // idb
PStringBase<char> DepthFog_10; // idb
PStringBase<char> AlphaTestMode_10; // idb
PStringBase<char> AlphaTestRef_10; // idb
PStringBase<char> FFUseLighting_10; // idb
PStringBase<char> FFUseDyeColorInTFactor_10; // idb
PStringBase<char> FFUseSpecularLighting_10; // idb
PStringBase<char> FFUseDistanceFog_10; // idb
PStringBase<char> FFUseVertexDiffuse_10; // idb
PStringBase<char> FFUseVertexSpecular_10; // idb
PStringBase<char> ShaderSupportsDynamicLights_10; // idb
PStringBase<char> UsesTransparency_10; // idb
PStringBase<char> Ambient_10; // idb
PStringBase<char> Diffuse_22; // idb
PStringBase<char> Specular_22; // idb
PStringBase<char> SpecularPower_10; // idb
PStringBase<char> Dye_10; // idb
PStringBase<char> Emissive_10; // idb
PStringBase<char> VertexFormat_10; // idb
PStringBase<char> VertexShader_10; // idb
PStringBase<char> PixelShader_10; // idb
PStringBase<char> param_MLF_NONE_10; // idb
PStringBase<char> param_MLF_REFLECTIONS_10; // idb
PStringBase<char> param_MLF_VIDEOPOST_10; // idb
PStringBase<char> param_MLF_HIGHDETAIL_10; // idb
PStringBase<char> param_MLF_SPECULAR_10; // idb
PStringBase<char> param_MLF_CLASS1_10; // idb
PStringBase<char> param_MLF_CLASS2_10; // idb
PStringBase<char> param_MLF_CLASS3_10; // idb
PStringBase<char> param_RenderPass_Default_10; // idb
PStringBase<char> param_RenderPass_DirectionalLightDiffuseAndSpecular_10; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecular_10; // idb
PStringBase<char> param_RenderPass_PointLightDiffuseAndSpecularProjector_10; // idb
PStringBase<char> param_RenderPass_AmbientLight_DirectionalLightDiffuseAndSpecular_10; // idb
PStringBase<char> param_RenderPass_AmbientLight_PointLightDiffuseAndSpecular_10; // idb
PStringBase<char> param_RenderPass_DistanceFog_10; // idb
PStringBase<char> param_RenderPass_FixedFunctionGlow_10; // idb
PStringBase<char> param_RenderPass_ShaderGlow_10; // idb
PStringBase<char> param_RenderPass_LandscapeShadowMap_10; // idb
PStringBase<char> param_RenderPass_AlphaBlend_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_0PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_1PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_2PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_3PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_4PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_5PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_6PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_7PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_0DL_8PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_0PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_1PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_2PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_3PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_4PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_5PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_6PL_Fog_10; // idb
PStringBase<char> param_RenderPass_AL_1DL_7PL_Fog_10; // idb
PStringBase<char> param_BLEND_ZERO_10; // idb
PStringBase<char> param_BLEND_ONE_10; // idb
PStringBase<char> param_BLEND_SRCCOLOR_10; // idb
PStringBase<char> param_BLEND_INVSRCCOLOR_10; // idb
PStringBase<char> param_BLEND_SRCALPHA_10; // idb
PStringBase<char> param_BLEND_INVSRCALPHA_10; // idb
PStringBase<char> param_BLEND_DSTALPHA_10; // idb
PStringBase<char> param_BLEND_INVDSTALPHA_10; // idb
PStringBase<char> param_BLEND_DSTCOLOR_10; // idb
PStringBase<char> param_BLEND_INVDSTCOLOR_10; // idb
PStringBase<char> param_BLEND_SRCALPHASAT_10; // idb
PStringBase<char> param_DEPTHTEST_LESS_10; // idb
PStringBase<char> param_DEPTHTEST_EQUAL_10; // idb
PStringBase<char> param_DEPTHTEST_LESSEQUAL_10; // idb
PStringBase<char> param_DEPTHTEST_GREATER_10; // idb
PStringBase<char> param_DEPTHTEST_NOTEQUAL_10; // idb
PStringBase<char> param_DEPTHTEST_GREATEREQUAL_10; // idb
PStringBase<char> param_DEPTHTEST_ALWAYS_10; // idb
PStringBase<char> param_DEPTHWRITE_ON_10; // idb
PStringBase<char> param_DEPTHWRITE_OFF_10; // idb
PStringBase<char> param_COLORSOURCE_LAYERDIFFUSE_10; // idb
PStringBase<char> param_COLORSOURCE_LAYERSPECULAR_10; // idb
PStringBase<char> param_COLORSOURCE_VERTEXDIFFUSE_10; // idb
PStringBase<char> param_COLORSOURCE_VERTEXSPECULAR_10; // idb
PStringBase<char> param_CULLMODE_NONE_10; // idb
PStringBase<char> param_CULLMODE_CW_10; // idb
PStringBase<char> param_CULLMODE_CCW_10; // idb
PStringBase<char> param_LIGHTMODE_NONE_10; // idb
PStringBase<char> param_LIGHTMODE_SIMPLE_10; // idb
PStringBase<char> param_LIGHTMODE_DIFFUSE_10; // idb
PStringBase<char> param_LIGHTMODE_SPECULAR_10; // idb
PStringBase<char> param_DEPTHFOG_OFF_10; // idb
PStringBase<char> param_DEPTHFOG_ON_10; // idb
PStringBase<char> param_ALPHATESTMODE_OFF_10; // idb
PStringBase<char> param_ALPHATESTMODE_ON_10; // idb
PStringBase<char> param_VF_ORIGIN_10; // idb
PStringBase<char> param_VF_NORMAL_10; // idb
PStringBase<char> param_VF_POINTSIZE_10; // idb
PStringBase<char> param_VF_DIFFUSE_10; // idb
PStringBase<char> param_VF_SPECULAR_10; // idb
PStringBase<char> param_VF_TCPAIRx1_10; // idb
PStringBase<char> param_VF_TCPAIRx2_10; // idb
PStringBase<char> param_VF_TCPAIRx3_10; // idb
PStringBase<char> param_VF_TCPAIRx4_10; // idb
PStringBase<char> param_VF_TCPAIRx5_10; // idb
PStringBase<char> param_VF_TCPAIRx6_10; // idb
PStringBase<char> param_VF_TCPAIRx7_10; // idb
PStringBase<char> param_VF_TCPAIRx8_10; // idb
PStringBase<char> param_VF_VECTOR_S_10; // idb
PStringBase<char> param_VF_VECTOR_T_10; // idb
PStringBase<char> stru_8F81D0; // idb
PStringBase<char> SamplerNodeName_10; // idb
PStringBase<char> SamplerName_10; // idb
PStringBase<char> Texture_10; // idb
PStringBase<char> SpecialTexture_FrameBuffer_10; // idb
PStringBase<char> SpecialTexture_Distortion_10; // idb
PStringBase<char> SpecialTexture_Reflection_10; // idb
PStringBase<char> SpecialTexture_NormalizeCube_10; // idb
PStringBase<char> SpecialTexture_LightProjectorCube_10; // idb
PStringBase<char> SpecialTexture_EnvironmentCube_10; // idb
PStringBase<char> SpecialTexture_LandscapeShadows_10; // idb
PStringBase<char> AddressMode_10; // idb
PStringBase<char> TexFilter_10; // idb
PStringBase<char> ColorOp_10; // idb
PStringBase<char> ColorArg1_10; // idb
PStringBase<char> ColorArg2_10; // idb
PStringBase<char> AlphaOp_10; // idb
PStringBase<char> AlphaArg1_10; // idb
PStringBase<char> AlphaArg2_10; // idb
PStringBase<char> TexCoord_10; // idb
PStringBase<char> UseProjection_10; // idb
PStringBase<char> param_TEXOP_SELECTARG1_10; // idb
PStringBase<char> param_TEXOP_SELECTARG2_10; // idb
PStringBase<char> param_TEXOP_MODULATE_10; // idb
PStringBase<char> param_TEXOP_MODULATE2X_10; // idb
PStringBase<char> param_TEXOP_MODULATE4X_10; // idb
PStringBase<char> param_TEXOP_ADD_10; // idb
PStringBase<char> param_TEXOP_ADDSIGNED_10; // idb
PStringBase<char> param_TEXOP_ADDSIGNED2X_10; // idb
PStringBase<char> param_TEXOP_SUBTRACT_10; // idb
PStringBase<char> param_TEXOP_ADDSMOOTH_10; // idb
PStringBase<char> param_TEXOP_BLENDDIFFUSEALPHA_10; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHA_10; // idb
PStringBase<char> param_TEXOP_BLENDFACTORALPHA_10; // idb
PStringBase<char> param_TEXOP_BLENDTEXTUREALPHAPM_10; // idb
PStringBase<char> param_TEXOP_BLENDCURRENTALPHA_10; // idb
PStringBase<char> param_TEXOP_PREMODULATE_10; // idb
PStringBase<char> param_TEXOP_MODULATEALPHA_ADDCOLOR_10; // idb
PStringBase<char> param_TEXOP_MODULATECOLOR_ADDALPHA_10; // idb
PStringBase<char> param_TEXOP_MODULATEINVALPHA_ADDCOLOR_10; // idb
PStringBase<char> param_TEXOP_MODULATEINVCOLOR_ADDALPHA_10; // idb
PStringBase<char> param_TEXOP_BUMPENVMAP_10; // idb
PStringBase<char> param_TEXOP_BUMPENVMAPLUMINANCE_10; // idb
PStringBase<char> param_TEXOP_DOTPRODUCT3_10; // idb
PStringBase<char> param_TEXOP_MULTIPLYADD_10; // idb
PStringBase<char> param_TEXOP_LERP_10; // idb
PStringBase<char> param_TEXARG_DIFFUSE_10; // idb
PStringBase<char> param_TEXARG_SPECULAR_10; // idb
PStringBase<char> param_TEXARG_CURRENT_10; // idb
PStringBase<char> param_TEXARG_TEXTURE_10; // idb
PStringBase<char> param_TEXARG_TFACTOR_10; // idb
PStringBase<char> param_TEXADDRESS_WRAP_10; // idb
PStringBase<char> param_TEXADDRESS_MIRROR_10; // idb
PStringBase<char> param_TEXADDRESS_CLAMP_10; // idb
PStringBase<char> param_TEXADDRESS_BORDER_10; // idb
PStringBase<char> param_TEXFILTER_NONE_10; // idb
PStringBase<char> param_TEXFILTER_POINT_10; // idb
PStringBase<char> param_TEXFILTER_LINEAR_10; // idb
PStringBase<char> param_TEXFILTER_ANISOTROPIC_10; // idb
PStringBase<char> param_TEXCOORD_ReflectionVector_10; // idb
PStringBase<char> param_TEXCOORD_ViewNormal_10; // idb
PStringBase<char> param_TEXCOORD_ViewOrigin_10; // idb
PStringBase<char> param_TEXCOORD_SphereMap_10; // idb
PStringBase<char> param_TEXCOORD_CubeMapReflection_10; // idb
PStringBase<char> param_TEXCOORD_CubeMapFakeLight_10; // idb
PStringBase<char> stru_8F82D4; // idb
PStringBase<char> ModType_Origin_10; // idb
PStringBase<char> ModType_Normal_10; // idb
PStringBase<char> ModType_Diffuse_10; // idb
PStringBase<char> ModType_UVTranslate_10; // idb
PStringBase<char> ModType_UVRotate_10; // idb
PStringBase<char> ModType_UVScale_10; // idb
PStringBase<char> ModType_UVTransform_10; // idb
PStringBase<char> Mod_UVTranslate_texCoordIndex_10; // idb
PStringBase<char> Mod_UVTranslate_translate_10; // idb
PStringBase<char> Mod_UVRotate_texCoordIndex_10; // idb
PStringBase<char> Mod_UVRotate_rotate_10; // idb
PStringBase<char> Mod_UVScale_texCoordIndex_10; // idb
PStringBase<char> Mod_UVScale_scale_10; // idb
PStringBase<char> stru_8F830C; // idb
PStringBase<char> PhysicsTimeStep_10; // idb
PStringBase<char> FastForwardTime_10; // idb
PStringBase<char> StartFadeDistance_10; // idb
PStringBase<char> StopFadeDistance_10; // idb
PStringBase<char> PhysicsDuration_10; // idb
PStringBase<char> ScaleType_10; // idb
PStringBase<char> WorldSpace_10; // idb
PStringBase<char> ForceDraw_10; // idb
PStringBase<char> NumEmitters_10; // idb
PStringBase<char> Material_49; // idb
PStringBase<char> Version_10; // idb
PStringBase<char> MaxParticles_10; // idb
PStringBase<char> stru_8F8340; // idb
PStringBase<char> Origin_22; // idb
PStringBase<char> Shape_10; // idb
PStringBase<char> Shape_Point_10; // idb
PStringBase<char> Shape_Line_10; // idb
PStringBase<char> Shape_Quad_10; // idb
PStringBase<char> Shape_Disc_10; // idb
PStringBase<char> Shape_Sphere_10; // idb
PStringBase<char> ParticleShape_10; // idb
PStringBase<char> ParticleShape_Triangle_10; // idb
PStringBase<char> ParticleShape_Quad_10; // idb
PStringBase<char> Streak_10; // idb
PStringBase<char> Rotation_22; // idb
PStringBase<char> WorldRotation_10; // idb
PStringBase<char> RotateVelocity_10; // idb
PStringBase<char> ParticleScale_10; // idb
PStringBase<char> Scale_33; // idb
PStringBase<char> ExplodingDir_10; // idb
PStringBase<char> BirthRate_10; // idb
PStringBase<char> Lifespan_10; // idb
PStringBase<char> Velocity_10; // idb
PStringBase<char> Direction_10; // idb
PStringBase<char> MinSpread_10; // idb
PStringBase<char> MaxSpread_10; // idb
PStringBase<char> EmissionLimit_10; // idb
PStringBase<char> BlastCount_10; // idb
PStringBase<char> StartTime_10; // idb
PStringBase<char> TimeLimit_10; // idb
PStringBase<char> EmissionDistance_10; // idb
PStringBase<char> ParticleSnap_10; // idb
PStringBase<char> InclusiveShape_10; // idb
PStringBase<char> NumKeyframes_10; // idb
PStringBase<char> IsActive_10; // idb
PStringBase<char> FadeIn_10; // idb
PStringBase<char> FadeOut_10; // idb
PStringBase<char> ConstrainX_10; // idb
PStringBase<char> ConstrainY_10; // idb
PStringBase<char> ConstrainZ_10; // idb
PStringBase<char> stru_8F83D8; // idb
PStringBase<char> Time_10; // idb
PStringBase<char> Flags_10; // idb
PStringBase<char> Flags_None_10; // idb
PStringBase<char> Flags_BlendScale_10; // idb
PStringBase<char> Flags_BlendColor_10; // idb
PStringBase<char> Flags_BlendMass_10; // idb
PStringBase<char> Flags_SetScale_10; // idb
PStringBase<char> Flags_SetColor_10; // idb
PStringBase<char> Flags_SetMass_10; // idb
PStringBase<char> Flags_SetPFlags_10; // idb
PStringBase<char> Flags_SetPCType_10; // idb
PStringBase<char> Flags_SetPhysFlags_10; // idb
PStringBase<char> Flags_SetParams_10; // idb
PStringBase<char> Scale_34; // idb
PStringBase<char> ScaleX_10; // idb
PStringBase<char> ScaleY_10; // idb
PStringBase<char> Color_10; // idb
PStringBase<char> Mass_10; // idb
PStringBase<char> PFlags_10; // idb
PStringBase<char> PFlags_None_10; // idb
PStringBase<char> PCType_10; // idb
PStringBase<char> PCType_None_10; // idb
PStringBase<char> PCType_Physics_10; // idb
PStringBase<char> PCType_Parametric_10; // idb
PStringBase<char> PCType_AttractRepulse_10; // idb
PStringBase<char> PCType_PointFile_10; // idb
PStringBase<char> PCType_PointFileLerp_10; // idb
PStringBase<char> PhysFlags_10; // idb
PStringBase<char> PhysFlags_None_10; // idb
PStringBase<char> PhysFlags_Gravity_10; // idb
PStringBase<char> PhysFlags_Wind_10; // idb
PStringBase<char> PhysFlags_Momentum_10; // idb
PStringBase<char> PointfileFlags_RandomPoint_10; // idb
PStringBase<char> Position_11; // idb
PStringBase<char> PointList_10; // idb
PStringBase<char> Point_22; // idb
PStringBase<char> DetailLevels_10; // idb
PStringBase<char> DetailLevel_Low_10; // idb
PStringBase<char> DetailLevel_Medium_10; // idb
PStringBase<char> DetailLevel_High_10; // idb
PStringBase<char> FadeSpeed_10; // idb
PStringBase<char> MaxOpacity_10; // idb
PStringBase<char> Point_23; // idb
PStringBase<char> PointAxisPos_10; // idb
PStringBase<char> PointTexture_10; // idb
PStringBase<char> PointSize_10; // idb
PStringBase<char> UseOcclusion_10; // idb
IDClass<_tagDataID,32,0> stru_8F8498; // idb
struct DebugConsole *DebugConsole::sm_pCurrentDebugConsole; // weak
PStringBase<char> Display_Resolution_39; // idb
PStringBase<char> Display_FullScreen_39; // idb
PStringBase<char> Display_RefreshRate_39; // idb
PStringBase<char> Display_SyncToRefresh_39; // idb
PixelFormatDesc stru_8F84C0; // idb
const float dword_8F84FC; // idb
const float flt_8F8500; // idb
const float flt_8F8504; // idb
const float flt_8F8508; // idb
PStringBase<char> waveform_None_75; // idb
PStringBase<char> waveform_Speed_75; // idb
PStringBase<char> waveform_Noise_75; // idb
PStringBase<char> waveform_Sine_75; // idb
PStringBase<char> waveform_Square_75; // idb
PStringBase<char> waveform_Bounce_75; // idb
PStringBase<char> waveform_Perlin_75; // idb
PStringBase<char> waveform_Fractal_75; // idb
PStringBase<char> waveform_FrameLoop_75; // idb
SmartArray<Glyph,1> GlyphText; // idb
unsigned int _S138_54; // idb
QualityRegistrar *QualityRegistrar::s_pQR; // idb
const float flt_8F859C; // idb
const float flt_8F85A0; // idb
const float flt_8F85A4; // idb
const float flt_8F85AC; // idb
const long double dbl_8F85B0; // idb
const long double dbl_8F85B8; // idb
PixelFormatDesc stru_8F85C0; // idb
IDClass<_tagDataID,32,0> stru_8F8608; // idb
PixelFormatDesc stru_8F860C; // idb
PixelFormatDesc stru_8F8660; // idb
PStringBase<char> waveform_None_76; // idb
PStringBase<char> waveform_Speed_76; // idb
PStringBase<char> waveform_Noise_76; // idb
PStringBase<char> waveform_Sine_76; // idb
PStringBase<char> waveform_Square_76; // idb
PStringBase<char> waveform_Bounce_76; // idb
PStringBase<char> waveform_Perlin_76; // idb
PStringBase<char> waveform_Fractal_76; // idb
PStringBase<char> waveform_FrameLoop_76; // idb
IDClass<_tagDataID,32,0> stru_8F86BC; // idb
const float dword_8F86C0; // idb
const float flt_8F86C4; // idb
const float flt_8F86C8; // idb
const float flt_8F86CC; // idb
PixelFormatDesc stru_8F86E0; // idb
const float dword_8F871C; // idb
const float flt_8F8720; // idb
const float flt_8F8724; // idb
const float flt_8F8728; // idb
PixelFormatDesc stru_8F874C; // idb
const float dword_8F8788; // idb
const float flt_8F878C; // idb
const float flt_8F8790; // idb
const float flt_8F8794; // idb
const float flt_8F8798; // idb
const long double dbl_8F87A0; // idb
const long double dbl_8F87A8; // idb
const int dword_8F87B0; // idb
const int dword_8F87B4; // idb
const int dword_8F87B8; // idb
PStringBase<char> Render_TextureFiltering_44; // idb
PStringBase<char> Render_LandscapeDetailTextures_44; // idb
PStringBase<char> Render_BuildingDetailTextures_44; // idb
PStringBase<char> Render_FieldOfView_44; // idb
PStringBase<char> Render_LandscapeTextureDetail_44; // idb
PStringBase<char> Render_EnvironmentTextureDetail_44; // idb
PStringBase<char> Render_SceneryDrawDistance_44; // idb
PStringBase<char> Render_LandscapeDrawDistance_44; // idb
PStringBase<char> Render_ScreenBrightness_44; // idb
PStringBase<char> Render_AspectRatio_44; // idb
PStringBase<char> Render_DisplayAdapter_44; // idb
PStringBase<char> Render_MaxHardwareClass_44; // idb
PStringBase<char> Render_AutomaticDegrades_44; // idb
PStringBase<char> Render_GraphicsPerformance_44; // idb
PStringBase<char> Render_DegradeDistance_44; // idb
PStringBase<char> Render_MultiPassAlpha_44; // idb
PStringBase<char> Render_TextureFiltering_Choices_44[4]; // idb
PStringBase<char> stru_8F8800; // idb
PStringBase<char> stru_8F8804; // idb
PStringBase<char> stru_8F8808; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_44[5]; // idb
PStringBase<char> stru_8F8810; // idb
PStringBase<char> stru_8F8814; // idb
PStringBase<char> stru_8F8818; // idb
PStringBase<char> stru_8F881C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_44[5]; // idb
PStringBase<char> stru_8F8824; // idb
PStringBase<char> stru_8F8828; // idb
PStringBase<char> stru_8F882C; // idb
PStringBase<char> stru_8F8830; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_44[3]; // idb
PStringBase<char> stru_8F8838; // idb
PStringBase<char> stru_8F883C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_44[6]; // idb
PStringBase<char> stru_8F8844; // idb
PStringBase<char> stru_8F8848; // idb
PStringBase<char> stru_8F884C; // idb
PStringBase<char> stru_8F8850; // idb
PStringBase<char> stru_8F8854; // idb
PStringBase<char> Render_AspectRatio_Choices_44[3]; // idb
PStringBase<char> stru_8F885C; // idb
PStringBase<char> stru_8F8860; // idb
PStringBase<char> waveform_None_77; // idb
PStringBase<char> waveform_Speed_77; // idb
PStringBase<char> waveform_Noise_77; // idb
PStringBase<char> waveform_Sine_77; // idb
PStringBase<char> waveform_Square_77; // idb
PStringBase<char> waveform_Bounce_77; // idb
PStringBase<char> waveform_Perlin_77; // idb
PStringBase<char> waveform_Fractal_77; // idb
PStringBase<char> waveform_FrameLoop_77; // idb
__int32 g_nTotalTextureRemoteBytes; // weak
PixelFormatDesc stru_8F88A8; // idb
IDClass<_tagDataID,32,0> stru_8F88E0; // idb
const float dword_8F88E4; // idb
const float flt_8F88E8; // idb
const float flt_8F88EC; // idb
const float flt_8F88F0; // idb
PStringBase<char> Render_TextureFiltering_45; // idb
PStringBase<char> Render_LandscapeDetailTextures_45; // idb
PStringBase<char> Render_BuildingDetailTextures_45; // idb
PStringBase<char> Render_FieldOfView_45; // idb
PStringBase<char> Render_LandscapeTextureDetail_45; // idb
PStringBase<char> Render_EnvironmentTextureDetail_45; // idb
PStringBase<char> Render_SceneryDrawDistance_45; // idb
PStringBase<char> Render_LandscapeDrawDistance_45; // idb
PStringBase<char> Render_ScreenBrightness_45; // idb
PStringBase<char> Render_AspectRatio_45; // idb
PStringBase<char> Render_DisplayAdapter_45; // idb
PStringBase<char> Render_MaxHardwareClass_45; // idb
PStringBase<char> Render_AutomaticDegrades_45; // idb
PStringBase<char> Render_GraphicsPerformance_45; // idb
PStringBase<char> Render_DegradeDistance_45; // idb
PStringBase<char> Render_MultiPassAlpha_45; // idb
PStringBase<char> Render_TextureFiltering_Choices_45[4]; // idb
PStringBase<char> stru_8F8938; // idb
PStringBase<char> stru_8F893C; // idb
PStringBase<char> stru_8F8940; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_45[5]; // idb
PStringBase<char> stru_8F8948; // idb
PStringBase<char> stru_8F894C; // idb
PStringBase<char> stru_8F8950; // idb
PStringBase<char> stru_8F8954; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_45[5]; // idb
PStringBase<char> stru_8F895C; // idb
PStringBase<char> stru_8F8960; // idb
PStringBase<char> stru_8F8964; // idb
PStringBase<char> stru_8F8968; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_45[3]; // idb
PStringBase<char> stru_8F8970; // idb
PStringBase<char> stru_8F8974; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_45[6]; // idb
PStringBase<char> stru_8F897C; // idb
PStringBase<char> stru_8F8980; // idb
PStringBase<char> stru_8F8984; // idb
PStringBase<char> stru_8F8988; // idb
PStringBase<char> stru_8F898C; // idb
PStringBase<char> Render_AspectRatio_Choices_45[3]; // idb
PStringBase<char> stru_8F8994; // idb
PStringBase<char> stru_8F8998; // idb
PStringBase<char> waveform_None_78; // idb
PStringBase<char> waveform_Speed_78; // idb
PStringBase<char> waveform_Noise_78; // idb
PStringBase<char> waveform_Sine_78; // idb
PStringBase<char> waveform_Square_78; // idb
PStringBase<char> waveform_Bounce_78; // idb
PStringBase<char> waveform_Perlin_78; // idb
PStringBase<char> waveform_Fractal_78; // idb
PStringBase<char> waveform_FrameLoop_78; // idb
__int32 g_nTotalSurfaceRemoteBytes; // weak
PixelFormatDesc stru_8F89D4; // idb
IDClass<_tagDataID,32,0> stru_8F8A0C; // idb
PixelFormatDesc stru_8F8A20; // idb
IDClass<_tagDataID,32,0> stru_8F8A58; // idb
PStringBase<char> waveform_None_79; // idb
PStringBase<char> waveform_Speed_79; // idb
PStringBase<char> waveform_Noise_79; // idb
PStringBase<char> waveform_Sine_79; // idb
PStringBase<char> waveform_Square_79; // idb
PStringBase<char> waveform_Bounce_79; // idb
PStringBase<char> waveform_Perlin_79; // idb
PStringBase<char> waveform_Fractal_79; // idb
PStringBase<char> waveform_FrameLoop_79; // idb
const float dword_8F8A80; // idb
const float flt_8F8A84; // idb
const float flt_8F8A88; // idb
const float flt_8F8A8C; // idb
SmartArray<ProfilerDBObjStat,1> g_FontVertices; // idb
PixelFormatDesc stru_8F8AB8; // idb
PStringBase<char> waveform_None_80; // idb
PStringBase<char> waveform_Speed_80; // idb
PStringBase<char> waveform_Noise_80; // idb
PStringBase<char> waveform_Sine_80; // idb
PStringBase<char> waveform_Square_80; // idb
PStringBase<char> waveform_Bounce_80; // idb
PStringBase<char> waveform_Perlin_80; // idb
PStringBase<char> waveform_Fractal_80; // idb
PStringBase<char> waveform_FrameLoop_80; // idb
__int32 g_TotalIndexBufferRemoteBytes; // weak
PixelFormatDesc stru_8F8B24; // idb
PixelFormatDesc stru_8F8B78; // idb
const float dword_8F8BB0; // idb
const float flt_8F8BB4; // idb
const float flt_8F8BB8; // idb
const float flt_8F8BBC; // idb
PStringBase<char> Render_TextureFiltering_46; // idb
PStringBase<char> Render_LandscapeDetailTextures_46; // idb
PStringBase<char> Render_BuildingDetailTextures_46; // idb
PStringBase<char> Render_FieldOfView_46; // idb
PStringBase<char> Render_LandscapeTextureDetail_46; // idb
PStringBase<char> Render_EnvironmentTextureDetail_46; // idb
PStringBase<char> Render_SceneryDrawDistance_46; // idb
PStringBase<char> Render_LandscapeDrawDistance_46; // idb
PStringBase<char> Render_ScreenBrightness_46; // idb
PStringBase<char> Render_AspectRatio_46; // idb
PStringBase<char> Render_DisplayAdapter_46; // idb
PStringBase<char> Render_MaxHardwareClass_46; // idb
PStringBase<char> Render_AutomaticDegrades_46; // idb
PStringBase<char> Render_GraphicsPerformance_46; // idb
PStringBase<char> Render_DegradeDistance_46; // idb
PStringBase<char> Render_MultiPassAlpha_46; // idb
PStringBase<char> Render_TextureFiltering_Choices_46[4]; // idb
PStringBase<char> stru_8F8C08; // idb
PStringBase<char> stru_8F8C0C; // idb
PStringBase<char> stru_8F8C10; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_46[5]; // idb
PStringBase<char> stru_8F8C18; // idb
PStringBase<char> stru_8F8C1C; // idb
PStringBase<char> stru_8F8C20; // idb
PStringBase<char> stru_8F8C24; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_46[5]; // idb
PStringBase<char> stru_8F8C2C; // idb
PStringBase<char> stru_8F8C30; // idb
PStringBase<char> stru_8F8C34; // idb
PStringBase<char> stru_8F8C38; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_46[3]; // idb
PStringBase<char> stru_8F8C40; // idb
PStringBase<char> stru_8F8C44; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_46[6]; // idb
PStringBase<char> stru_8F8C4C; // idb
PStringBase<char> stru_8F8C50; // idb
PStringBase<char> stru_8F8C54; // idb
PStringBase<char> stru_8F8C58; // idb
PStringBase<char> stru_8F8C5C; // idb
PStringBase<char> Render_AspectRatio_Choices_46[3]; // idb
PStringBase<char> stru_8F8C64; // idb
PStringBase<char> stru_8F8C68; // idb
PStringBase<char> waveform_None_81; // idb
PStringBase<char> waveform_Speed_81; // idb
PStringBase<char> waveform_Noise_81; // idb
PStringBase<char> waveform_Sine_81; // idb
PStringBase<char> waveform_Square_81; // idb
PStringBase<char> waveform_Bounce_81; // idb
PStringBase<char> waveform_Perlin_81; // idb
PStringBase<char> waveform_Fractal_81; // idb
PStringBase<char> waveform_FrameLoop_81; // idb
PStringBase<char> waveform_None_82; // idb
PStringBase<char> waveform_Speed_82; // idb
PStringBase<char> waveform_Noise_82; // idb
PStringBase<char> waveform_Sine_82; // idb
PStringBase<char> waveform_Square_82; // idb
PStringBase<char> waveform_Bounce_82; // idb
PStringBase<char> waveform_Perlin_82; // idb
PStringBase<char> waveform_Fractal_82; // idb
PStringBase<char> waveform_FrameLoop_82; // idb
PixelFormatDesc stru_8F8CD0; // idb
const float dword_8F8D08; // idb
const float flt_8F8D0C; // idb
const float flt_8F8D10; // idb
const float flt_8F8D14; // idb
PStringBase<char> Render_TextureFiltering_47; // idb
PStringBase<char> Render_LandscapeDetailTextures_47; // idb
PStringBase<char> Render_BuildingDetailTextures_47; // idb
PStringBase<char> Render_FieldOfView_47; // idb
PStringBase<char> Render_LandscapeTextureDetail_47; // idb
PStringBase<char> Render_EnvironmentTextureDetail_47; // idb
PStringBase<char> Render_SceneryDrawDistance_47; // idb
PStringBase<char> Render_LandscapeDrawDistance_47; // idb
PStringBase<char> Render_ScreenBrightness_47; // idb
PStringBase<char> Render_AspectRatio_47; // idb
PStringBase<char> Render_DisplayAdapter_47; // idb
PStringBase<char> Render_MaxHardwareClass_47; // idb
PStringBase<char> Render_AutomaticDegrades_47; // idb
PStringBase<char> Render_GraphicsPerformance_47; // idb
PStringBase<char> Render_DegradeDistance_47; // idb
PStringBase<char> Render_MultiPassAlpha_47; // idb
PStringBase<char> Render_TextureFiltering_Choices_47[4]; // idb
PStringBase<char> stru_8F8D60; // idb
PStringBase<char> stru_8F8D64; // idb
PStringBase<char> stru_8F8D68; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_47[5]; // idb
PStringBase<char> stru_8F8D70; // idb
PStringBase<char> stru_8F8D74; // idb
PStringBase<char> stru_8F8D78; // idb
PStringBase<char> stru_8F8D7C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_47[5]; // idb
PStringBase<char> stru_8F8D84; // idb
PStringBase<char> stru_8F8D88; // idb
PStringBase<char> stru_8F8D8C; // idb
PStringBase<char> stru_8F8D90; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_47[3]; // idb
PStringBase<char> stru_8F8D98; // idb
PStringBase<char> stru_8F8D9C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_47[6]; // idb
PStringBase<char> stru_8F8DA4; // idb
PStringBase<char> stru_8F8DA8; // idb
PStringBase<char> stru_8F8DAC; // idb
PStringBase<char> stru_8F8DB0; // idb
PStringBase<char> stru_8F8DB4; // idb
PStringBase<char> Render_AspectRatio_Choices_47[3]; // idb
PStringBase<char> stru_8F8DBC; // idb
PStringBase<char> stru_8F8DC0; // idb
_UNKNOWN unk_8F8DC4; // weak
PixelFormatDesc stru_8F8DE0; // idb
const float dword_8F8E18; // idb
const float flt_8F8E1C; // idb
const float flt_8F8E20; // idb
const float flt_8F8E24; // idb
PStringBase<char> Render_TextureFiltering_48; // idb
PStringBase<char> Render_LandscapeDetailTextures_48; // idb
PStringBase<char> Render_BuildingDetailTextures_48; // idb
PStringBase<char> Render_FieldOfView_48; // idb
PStringBase<char> Render_LandscapeTextureDetail_48; // idb
PStringBase<char> Render_EnvironmentTextureDetail_48; // idb
PStringBase<char> Render_SceneryDrawDistance_48; // idb
PStringBase<char> Render_LandscapeDrawDistance_48; // idb
PStringBase<char> Render_ScreenBrightness_48; // idb
PStringBase<char> Render_AspectRatio_48; // idb
PStringBase<char> Render_DisplayAdapter_48; // idb
PStringBase<char> Render_MaxHardwareClass_48; // idb
PStringBase<char> Render_AutomaticDegrades_48; // idb
PStringBase<char> Render_GraphicsPerformance_48; // idb
PStringBase<char> Render_DegradeDistance_48; // idb
PStringBase<char> Render_MultiPassAlpha_48; // idb
PStringBase<char> Render_TextureFiltering_Choices_48[4]; // idb
PStringBase<char> stru_8F8E70; // idb
PStringBase<char> stru_8F8E74; // idb
PStringBase<char> stru_8F8E78; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_48[5]; // idb
PStringBase<char> stru_8F8E80; // idb
PStringBase<char> stru_8F8E84; // idb
PStringBase<char> stru_8F8E88; // idb
PStringBase<char> stru_8F8E8C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_48[5]; // idb
PStringBase<char> stru_8F8E94; // idb
PStringBase<char> stru_8F8E98; // idb
PStringBase<char> stru_8F8E9C; // idb
PStringBase<char> stru_8F8EA0; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_48[3]; // idb
PStringBase<char> stru_8F8EA8; // idb
PStringBase<char> stru_8F8EAC; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_48[6]; // idb
PStringBase<char> stru_8F8EB4; // idb
PStringBase<char> stru_8F8EB8; // idb
PStringBase<char> stru_8F8EBC; // idb
PStringBase<char> stru_8F8EC0; // idb
PStringBase<char> stru_8F8EC4; // idb
PStringBase<char> Render_AspectRatio_Choices_48[3]; // idb
PStringBase<char> stru_8F8ECC; // idb
PStringBase<char> stru_8F8ED0; // idb
PStringBase<char> waveform_None_83; // idb
PStringBase<char> waveform_Speed_83; // idb
PStringBase<char> waveform_Noise_83; // idb
PStringBase<char> waveform_Sine_83; // idb
PStringBase<char> waveform_Square_83; // idb
PStringBase<char> waveform_Bounce_83; // idb
PStringBase<char> waveform_Perlin_83; // idb
PStringBase<char> waveform_Fractal_83; // idb
PStringBase<char> waveform_FrameLoop_83; // idb
PixelFormatDesc stru_8F8F04; // idb
PStringBase<char> KW_NULL_3; // idb
PStringBase<char> KW_BASE; // idb
PStringBase<char> KW_BOTTOMEDGE; // idb
PStringBase<char> KW_CHILD; // idb
PStringBase<char> KW_CODE; // idb
PStringBase<char> KW_DEFAULTSTATE; // idb
PStringBase<char> KW_DISPLAYHEIGHT; // idb
PStringBase<char> KW_DISPLAYWIDTH; // idb
PStringBase<char> KW_DRAWMODE; // idb
PStringBase<char> KW_DURATION; // idb
PStringBase<char> KW_ELEMENT; // idb
PStringBase<char> KW_ELEMENTHEADER; // idb
PStringBase<char> KW_ELEMENTWHEADER; // idb
PStringBase<char> KW_ELEMENTID; // idb
PStringBase<char> KW_ENDALPHA; // idb
PStringBase<char> KW_ENGINETYPE; // idb
PStringBase<char> KW_EVENTID; // idb
PStringBase<char> KW_FILE; // idb
PStringBase<char> KW_FRAMES; // idb
PStringBase<char> KW_HEADER; // idb
PStringBase<char> KW_HEIGHT; // idb
PStringBase<char> KW_JUMPITEMINDEX; // idb
PStringBase<char> KW_LEFTEDGE; // idb
PStringBase<char> KW_MAXDURATION; // idb
PStringBase<char> KW_MEDIA; // idb
PStringBase<char> KW_MEDIATYPE; // idb
PStringBase<char> KW_MINDURATION; // idb
PStringBase<char> KW_NO_DB_FILE; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN; // idb
PStringBase<char> KW_PASSTOCHILDREN; // idb
PStringBase<char> KW_PROBABILITY; // idb
PStringBase<char> KW_PROPERTIES_0; // idb
PStringBase<char> KW_REMOVE; // idb
PStringBase<char> KW_RIGHTEDGE; // idb
PStringBase<char> KW_SOUNDNAME; // idb
PStringBase<char> KW_SOUNDTABLE; // idb
PStringBase<char> KW_STARTALPHA; // idb
PStringBase<char> KW_STATE; // idb
PStringBase<char> KW_STATEHEADER; // idb
PStringBase<char> KW_STATEWHEADER; // idb
PStringBase<char> KW_STATEID; // idb
PStringBase<char> KW_TOPEDGE; // idb
PStringBase<char> KW_TYPE; // idb
PStringBase<char> KW_WIDTH; // idb
PStringBase<char> KW_X; // idb
PStringBase<char> KW_XHOTSPOT; // idb
PStringBase<char> KW_Y; // idb
PStringBase<char> KW_YHOTSPOT; // idb
PStringBase<char> KW_ZLEVEL; // idb
PStringBase<char> KW_COMMENTS; // idb
PStringBase<char> KW_HAS_ALPHA; // idb
IDClass<_tagDataID,32,0> stru_8F900C; // idb
PStringBase<char> KW_NULL_4; // idb
PStringBase<char> KW_BASE_0; // idb
PStringBase<char> KW_BOTTOMEDGE_0; // idb
PStringBase<char> KW_CHILD_0; // idb
PStringBase<char> KW_CODE_0; // idb
PStringBase<char> KW_DEFAULTSTATE_0; // idb
PStringBase<char> KW_DISPLAYHEIGHT_0; // idb
PStringBase<char> KW_DISPLAYWIDTH_0; // idb
PStringBase<char> KW_DRAWMODE_0; // idb
PStringBase<char> KW_DURATION_0; // idb
PStringBase<char> KW_ELEMENT_0; // idb
PStringBase<char> KW_ELEMENTHEADER_0; // idb
PStringBase<char> KW_ELEMENTWHEADER_0; // idb
PStringBase<char> KW_ELEMENTID_0; // idb
PStringBase<char> KW_ENDALPHA_0; // idb
PStringBase<char> KW_ENGINETYPE_0; // idb
PStringBase<char> KW_EVENTID_0; // idb
PStringBase<char> KW_FILE_0; // idb
PStringBase<char> KW_FRAMES_0; // idb
PStringBase<char> KW_HEADER_0; // idb
PStringBase<char> KW_HEIGHT_0; // idb
PStringBase<char> KW_JUMPITEMINDEX_0; // idb
PStringBase<char> KW_LEFTEDGE_0; // idb
PStringBase<char> KW_MAXDURATION_0; // idb
PStringBase<char> KW_MEDIA_0; // idb
PStringBase<char> KW_MEDIATYPE_0; // idb
PStringBase<char> KW_MINDURATION_0; // idb
PStringBase<char> KW_NO_DB_FILE_0; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_0; // idb
PStringBase<char> KW_PASSTOCHILDREN_0; // idb
PStringBase<char> KW_PROBABILITY_0; // idb
PStringBase<char> KW_PROPERTIES_1; // idb
PStringBase<char> KW_REMOVE_0; // idb
PStringBase<char> KW_RIGHTEDGE_0; // idb
PStringBase<char> KW_SOUNDNAME_0; // idb
PStringBase<char> KW_SOUNDTABLE_0; // idb
PStringBase<char> KW_STARTALPHA_0; // idb
PStringBase<char> KW_STATE_0; // idb
PStringBase<char> KW_STATEHEADER_0; // idb
PStringBase<char> KW_STATEWHEADER_0; // idb
PStringBase<char> KW_STATEID_0; // idb
PStringBase<char> KW_TOPEDGE_0; // idb
PStringBase<char> KW_TYPE_0; // idb
PStringBase<char> KW_WIDTH_0; // idb
PStringBase<char> KW_X_0; // idb
PStringBase<char> KW_XHOTSPOT_0; // idb
PStringBase<char> KW_Y_0; // idb
PStringBase<char> KW_YHOTSPOT_0; // idb
PStringBase<char> KW_ZLEVEL_0; // idb
PStringBase<char> KW_COMMENTS_0; // idb
PStringBase<char> KW_HAS_ALPHA_0; // idb
IDClass<_tagDataID,32,0> stru_8F90E0; // idb
PStringBase<char> KW_NULL_5; // idb
PStringBase<char> KW_BASE_1; // idb
PStringBase<char> KW_BOTTOMEDGE_1; // idb
PStringBase<char> KW_CHILD_1; // idb
PStringBase<char> KW_CODE_1; // idb
PStringBase<char> KW_DEFAULTSTATE_1; // idb
PStringBase<char> KW_DISPLAYHEIGHT_1; // idb
PStringBase<char> KW_DISPLAYWIDTH_1; // idb
PStringBase<char> KW_DRAWMODE_1; // idb
PStringBase<char> KW_DURATION_1; // idb
PStringBase<char> KW_ELEMENT_1; // idb
PStringBase<char> KW_ELEMENTHEADER_1; // idb
PStringBase<char> KW_ELEMENTWHEADER_1; // idb
PStringBase<char> KW_ELEMENTID_1; // idb
PStringBase<char> KW_ENDALPHA_1; // idb
PStringBase<char> KW_ENGINETYPE_1; // idb
PStringBase<char> KW_EVENTID_1; // idb
PStringBase<char> KW_FILE_1; // idb
PStringBase<char> KW_FRAMES_1; // idb
PStringBase<char> KW_HEADER_1; // idb
PStringBase<char> KW_HEIGHT_1; // idb
PStringBase<char> KW_JUMPITEMINDEX_1; // idb
PStringBase<char> KW_LEFTEDGE_1; // idb
PStringBase<char> KW_MAXDURATION_1; // idb
PStringBase<char> KW_MEDIA_1; // idb
PStringBase<char> KW_MEDIATYPE_1; // idb
PStringBase<char> KW_MINDURATION_1; // idb
PStringBase<char> KW_NO_DB_FILE_1; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_1; // idb
PStringBase<char> KW_PASSTOCHILDREN_1; // idb
PStringBase<char> KW_PROBABILITY_1; // idb
PStringBase<char> KW_PROPERTIES_2; // idb
PStringBase<char> KW_REMOVE_1; // idb
PStringBase<char> KW_RIGHTEDGE_1; // idb
PStringBase<char> KW_SOUNDNAME_1; // idb
PStringBase<char> KW_SOUNDTABLE_1; // idb
PStringBase<char> KW_STARTALPHA_1; // idb
PStringBase<char> KW_STATE_1; // idb
PStringBase<char> KW_STATEHEADER_1; // idb
PStringBase<char> KW_STATEWHEADER_1; // idb
PStringBase<char> KW_STATEID_1; // idb
PStringBase<char> KW_TOPEDGE_1; // idb
PStringBase<char> KW_TYPE_1; // idb
PStringBase<char> KW_WIDTH_1; // idb
PStringBase<char> KW_X_1; // idb
PStringBase<char> KW_XHOTSPOT_1; // idb
PStringBase<char> KW_Y_1; // idb
PStringBase<char> KW_YHOTSPOT_1; // idb
PStringBase<char> KW_ZLEVEL_1; // idb
PStringBase<char> KW_COMMENTS_1; // idb
PStringBase<char> KW_HAS_ALPHA_1; // idb
PStringBase<char> KW_NULL_6; // idb
PStringBase<char> KW_BASE_2; // idb
PStringBase<char> KW_BOTTOMEDGE_2; // idb
PStringBase<char> KW_CHILD_2; // idb
PStringBase<char> KW_CODE_2; // idb
PStringBase<char> KW_DEFAULTSTATE_2; // idb
PStringBase<char> KW_DISPLAYHEIGHT_2; // idb
PStringBase<char> KW_DISPLAYWIDTH_2; // idb
PStringBase<char> KW_DRAWMODE_2; // idb
PStringBase<char> KW_DURATION_2; // idb
PStringBase<char> KW_ELEMENT_2; // idb
PStringBase<char> KW_ELEMENTHEADER_2; // idb
PStringBase<char> KW_ELEMENTWHEADER_2; // idb
PStringBase<char> KW_ELEMENTID_2; // idb
PStringBase<char> KW_ENDALPHA_2; // idb
PStringBase<char> KW_ENGINETYPE_2; // idb
PStringBase<char> KW_EVENTID_2; // idb
PStringBase<char> KW_FILE_2; // idb
PStringBase<char> KW_FRAMES_2; // idb
PStringBase<char> KW_HEADER_2; // idb
PStringBase<char> KW_HEIGHT_2; // idb
PStringBase<char> KW_JUMPITEMINDEX_2; // idb
PStringBase<char> KW_LEFTEDGE_2; // idb
PStringBase<char> KW_MAXDURATION_2; // idb
PStringBase<char> KW_MEDIA_2; // idb
PStringBase<char> KW_MEDIATYPE_2; // idb
PStringBase<char> KW_MINDURATION_2; // idb
PStringBase<char> KW_NO_DB_FILE_2; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_2; // idb
PStringBase<char> KW_PASSTOCHILDREN_2; // idb
PStringBase<char> KW_PROBABILITY_2; // idb
PStringBase<char> KW_PROPERTIES_3; // idb
PStringBase<char> KW_REMOVE_2; // idb
PStringBase<char> KW_RIGHTEDGE_2; // idb
PStringBase<char> KW_SOUNDNAME_2; // idb
PStringBase<char> KW_SOUNDTABLE_2; // idb
PStringBase<char> KW_STARTALPHA_2; // idb
PStringBase<char> KW_STATE_2; // idb
PStringBase<char> KW_STATEHEADER_2; // idb
PStringBase<char> KW_STATEWHEADER_2; // idb
PStringBase<char> KW_STATEID_2; // idb
PStringBase<char> KW_TOPEDGE_2; // idb
PStringBase<char> KW_TYPE_2; // idb
PStringBase<char> KW_WIDTH_2; // idb
PStringBase<char> KW_X_2; // idb
PStringBase<char> KW_XHOTSPOT_2; // idb
PStringBase<char> KW_Y_2; // idb
PStringBase<char> KW_YHOTSPOT_2; // idb
PStringBase<char> KW_ZLEVEL_2; // idb
PStringBase<char> KW_COMMENTS_2; // idb
PStringBase<char> KW_HAS_ALPHA_2; // idb
IDClass<_tagDataID,32,0> stru_8F9284; // idb
PixelFormatDesc stru_8F9298; // idb
PStringBase<char> KW_NULL_7; // idb
PStringBase<char> KW_BASE_3; // idb
PStringBase<char> KW_BOTTOMEDGE_3; // idb
PStringBase<char> KW_CHILD_3; // idb
PStringBase<char> KW_CODE_3; // idb
PStringBase<char> KW_DEFAULTSTATE_3; // idb
PStringBase<char> KW_DISPLAYHEIGHT_3; // idb
PStringBase<char> KW_DISPLAYWIDTH_3; // idb
PStringBase<char> KW_DRAWMODE_3; // idb
PStringBase<char> KW_DURATION_3; // idb
PStringBase<char> KW_ELEMENT_3; // idb
PStringBase<char> KW_ELEMENTHEADER_3; // idb
PStringBase<char> KW_ELEMENTWHEADER_3; // idb
PStringBase<char> KW_ELEMENTID_3; // idb
PStringBase<char> KW_ENDALPHA_3; // idb
PStringBase<char> KW_ENGINETYPE_3; // idb
PStringBase<char> KW_EVENTID_3; // idb
PStringBase<char> KW_FILE_3; // idb
PStringBase<char> KW_FRAMES_3; // idb
PStringBase<char> KW_HEADER_3; // idb
PStringBase<char> KW_HEIGHT_3; // idb
PStringBase<char> KW_JUMPITEMINDEX_3; // idb
PStringBase<char> KW_LEFTEDGE_3; // idb
PStringBase<char> KW_MAXDURATION_3; // idb
PStringBase<char> KW_MEDIA_3; // idb
PStringBase<char> KW_MEDIATYPE_3; // idb
PStringBase<char> KW_MINDURATION_3; // idb
PStringBase<char> KW_NO_DB_FILE_3; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_3; // idb
PStringBase<char> KW_PASSTOCHILDREN_3; // idb
PStringBase<char> KW_PROBABILITY_3; // idb
PStringBase<char> KW_PROPERTIES_4; // idb
PStringBase<char> KW_REMOVE_3; // idb
PStringBase<char> KW_RIGHTEDGE_3; // idb
PStringBase<char> KW_SOUNDNAME_3; // idb
PStringBase<char> KW_SOUNDTABLE_3; // idb
PStringBase<char> KW_STARTALPHA_3; // idb
PStringBase<char> KW_STATE_3; // idb
PStringBase<char> KW_STATEHEADER_3; // idb
PStringBase<char> KW_STATEWHEADER_3; // idb
PStringBase<char> KW_STATEID_3; // idb
PStringBase<char> KW_TOPEDGE_3; // idb
PStringBase<char> KW_TYPE_3; // idb
PStringBase<char> KW_WIDTH_3; // idb
PStringBase<char> KW_X_3; // idb
PStringBase<char> KW_XHOTSPOT_3; // idb
PStringBase<char> KW_Y_3; // idb
PStringBase<char> KW_YHOTSPOT_3; // idb
PStringBase<char> KW_ZLEVEL_3; // idb
PStringBase<char> KW_COMMENTS_3; // idb
PStringBase<char> KW_HAS_ALPHA_3; // idb
PStringBase<char> KW_NULL_8; // idb
PStringBase<char> KW_BASE_4; // idb
PStringBase<char> KW_BOTTOMEDGE_4; // idb
PStringBase<char> KW_CHILD_4; // idb
PStringBase<char> KW_CODE_4; // idb
PStringBase<char> KW_DEFAULTSTATE_4; // idb
PStringBase<char> KW_DISPLAYHEIGHT_4; // idb
PStringBase<char> KW_DISPLAYWIDTH_4; // idb
PStringBase<char> KW_DRAWMODE_4; // idb
PStringBase<char> KW_DURATION_4; // idb
PStringBase<char> KW_ELEMENT_4; // idb
PStringBase<char> KW_ELEMENTHEADER_4; // idb
PStringBase<char> KW_ELEMENTWHEADER_4; // idb
PStringBase<char> KW_ELEMENTID_4; // idb
PStringBase<char> KW_ENDALPHA_4; // idb
PStringBase<char> KW_ENGINETYPE_4; // idb
PStringBase<char> KW_EVENTID_4; // idb
PStringBase<char> KW_FILE_4; // idb
PStringBase<char> KW_FRAMES_4; // idb
PStringBase<char> KW_HEADER_4; // idb
PStringBase<char> KW_HEIGHT_4; // idb
PStringBase<char> KW_JUMPITEMINDEX_4; // idb
PStringBase<char> KW_LEFTEDGE_4; // idb
PStringBase<char> KW_MAXDURATION_4; // idb
PStringBase<char> KW_MEDIA_4; // idb
PStringBase<char> KW_MEDIATYPE_4; // idb
PStringBase<char> KW_MINDURATION_4; // idb
PStringBase<char> KW_NO_DB_FILE_4; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_4; // idb
PStringBase<char> KW_PASSTOCHILDREN_4; // idb
PStringBase<char> KW_PROBABILITY_4; // idb
PStringBase<char> KW_PROPERTIES_5; // idb
PStringBase<char> KW_REMOVE_4; // idb
PStringBase<char> KW_RIGHTEDGE_4; // idb
PStringBase<char> KW_SOUNDNAME_4; // idb
PStringBase<char> KW_SOUNDTABLE_4; // idb
PStringBase<char> KW_STARTALPHA_4; // idb
PStringBase<char> KW_STATE_4; // idb
PStringBase<char> KW_STATEHEADER_4; // idb
PStringBase<char> KW_STATEWHEADER_4; // idb
PStringBase<char> KW_STATEID_4; // idb
PStringBase<char> KW_TOPEDGE_4; // idb
PStringBase<char> KW_TYPE_4; // idb
PStringBase<char> KW_WIDTH_4; // idb
PStringBase<char> KW_X_4; // idb
PStringBase<char> KW_XHOTSPOT_4; // idb
PStringBase<char> KW_Y_4; // idb
PStringBase<char> KW_YHOTSPOT_4; // idb
PStringBase<char> KW_ZLEVEL_4; // idb
PStringBase<char> KW_COMMENTS_4; // idb
PStringBase<char> KW_HAS_ALPHA_4; // idb
PStringBase<char> KW_NULL_9; // idb
PStringBase<char> KW_BASE_5; // idb
PStringBase<char> KW_BOTTOMEDGE_5; // idb
PStringBase<char> KW_CHILD_5; // idb
PStringBase<char> KW_CODE_5; // idb
PStringBase<char> KW_DEFAULTSTATE_5; // idb
PStringBase<char> KW_DISPLAYHEIGHT_5; // idb
PStringBase<char> KW_DISPLAYWIDTH_5; // idb
PStringBase<char> KW_DRAWMODE_5; // idb
PStringBase<char> KW_DURATION_5; // idb
PStringBase<char> KW_ELEMENT_5; // idb
PStringBase<char> KW_ELEMENTHEADER_5; // idb
PStringBase<char> KW_ELEMENTWHEADER_5; // idb
PStringBase<char> KW_ELEMENTID_5; // idb
PStringBase<char> KW_ENDALPHA_5; // idb
PStringBase<char> KW_ENGINETYPE_5; // idb
PStringBase<char> KW_EVENTID_5; // idb
PStringBase<char> KW_FILE_5; // idb
PStringBase<char> KW_FRAMES_5; // idb
PStringBase<char> KW_HEADER_5; // idb
PStringBase<char> KW_HEIGHT_5; // idb
PStringBase<char> KW_JUMPITEMINDEX_5; // idb
PStringBase<char> KW_LEFTEDGE_5; // idb
PStringBase<char> KW_MAXDURATION_5; // idb
PStringBase<char> KW_MEDIA_5; // idb
PStringBase<char> KW_MEDIATYPE_5; // idb
PStringBase<char> KW_MINDURATION_5; // idb
PStringBase<char> KW_NO_DB_FILE_5; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_5; // idb
PStringBase<char> KW_PASSTOCHILDREN_5; // idb
PStringBase<char> KW_PROBABILITY_5; // idb
PStringBase<char> KW_PROPERTIES_6; // idb
PStringBase<char> KW_REMOVE_5; // idb
PStringBase<char> KW_RIGHTEDGE_5; // idb
PStringBase<char> KW_SOUNDNAME_5; // idb
PStringBase<char> KW_SOUNDTABLE_5; // idb
PStringBase<char> KW_STARTALPHA_5; // idb
PStringBase<char> KW_STATE_5; // idb
PStringBase<char> KW_STATEHEADER_5; // idb
PStringBase<char> KW_STATEWHEADER_5; // idb
PStringBase<char> KW_STATEID_5; // idb
PStringBase<char> KW_TOPEDGE_5; // idb
PStringBase<char> KW_TYPE_5; // idb
PStringBase<char> KW_WIDTH_5; // idb
PStringBase<char> KW_X_5; // idb
PStringBase<char> KW_XHOTSPOT_5; // idb
PStringBase<char> KW_Y_5; // idb
PStringBase<char> KW_YHOTSPOT_5; // idb
PStringBase<char> KW_ZLEVEL_5; // idb
PStringBase<char> KW_COMMENTS_5; // idb
PStringBase<char> KW_HAS_ALPHA_5; // idb
IDClass<_tagDataID,32,0> stru_8F9540; // idb
PStringBase<char> KW_NULL_10; // idb
PStringBase<char> KW_BASE_6; // idb
PStringBase<char> KW_BOTTOMEDGE_6; // idb
PStringBase<char> KW_CHILD_6; // idb
PStringBase<char> KW_CODE_6; // idb
PStringBase<char> KW_DEFAULTSTATE_6; // idb
PStringBase<char> KW_DISPLAYHEIGHT_6; // idb
PStringBase<char> KW_DISPLAYWIDTH_6; // idb
PStringBase<char> KW_DRAWMODE_6; // idb
PStringBase<char> KW_DURATION_6; // idb
PStringBase<char> KW_ELEMENT_6; // idb
PStringBase<char> KW_ELEMENTHEADER_6; // idb
PStringBase<char> KW_ELEMENTWHEADER_6; // idb
PStringBase<char> KW_ELEMENTID_6; // idb
PStringBase<char> KW_ENDALPHA_6; // idb
PStringBase<char> KW_ENGINETYPE_6; // idb
PStringBase<char> KW_EVENTID_6; // idb
PStringBase<char> KW_FILE_6; // idb
PStringBase<char> KW_FRAMES_6; // idb
PStringBase<char> KW_HEADER_6; // idb
PStringBase<char> KW_HEIGHT_6; // idb
PStringBase<char> KW_JUMPITEMINDEX_6; // idb
PStringBase<char> KW_LEFTEDGE_6; // idb
PStringBase<char> KW_MAXDURATION_6; // idb
PStringBase<char> KW_MEDIA_6; // idb
PStringBase<char> KW_MEDIATYPE_6; // idb
PStringBase<char> KW_MINDURATION_6; // idb
PStringBase<char> KW_NO_DB_FILE_6; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_6; // idb
PStringBase<char> KW_PASSTOCHILDREN_6; // idb
PStringBase<char> KW_PROBABILITY_6; // idb
PStringBase<char> KW_PROPERTIES_7; // idb
PStringBase<char> KW_REMOVE_6; // idb
PStringBase<char> KW_RIGHTEDGE_6; // idb
PStringBase<char> KW_SOUNDNAME_6; // idb
PStringBase<char> KW_SOUNDTABLE_6; // idb
PStringBase<char> KW_STARTALPHA_6; // idb
PStringBase<char> KW_STATE_6; // idb
PStringBase<char> KW_STATEHEADER_6; // idb
PStringBase<char> KW_STATEWHEADER_6; // idb
PStringBase<char> KW_STATEID_6; // idb
PStringBase<char> KW_TOPEDGE_6; // idb
PStringBase<char> KW_TYPE_6; // idb
PStringBase<char> KW_WIDTH_6; // idb
PStringBase<char> KW_X_6; // idb
PStringBase<char> KW_XHOTSPOT_6; // idb
PStringBase<char> KW_Y_6; // idb
PStringBase<char> KW_YHOTSPOT_6; // idb
PStringBase<char> KW_ZLEVEL_6; // idb
PStringBase<char> KW_COMMENTS_6; // idb
PStringBase<char> KW_HAS_ALPHA_6; // idb
PStringBase<char> KW_NULL_11; // idb
PStringBase<char> KW_BASE_7; // idb
PStringBase<char> KW_BOTTOMEDGE_7; // idb
PStringBase<char> KW_CHILD_7; // idb
PStringBase<char> KW_CODE_7; // idb
PStringBase<char> KW_DEFAULTSTATE_7; // idb
PStringBase<char> KW_DISPLAYHEIGHT_7; // idb
PStringBase<char> KW_DISPLAYWIDTH_7; // idb
PStringBase<char> KW_DRAWMODE_7; // idb
PStringBase<char> KW_DURATION_7; // idb
PStringBase<char> KW_ELEMENT_7; // idb
PStringBase<char> KW_ELEMENTHEADER_7; // idb
PStringBase<char> KW_ELEMENTWHEADER_7; // idb
PStringBase<char> KW_ELEMENTID_7; // idb
PStringBase<char> KW_ENDALPHA_7; // idb
PStringBase<char> KW_ENGINETYPE_7; // idb
PStringBase<char> KW_EVENTID_7; // idb
PStringBase<char> KW_FILE_7; // idb
PStringBase<char> KW_FRAMES_7; // idb
PStringBase<char> KW_HEADER_7; // idb
PStringBase<char> KW_HEIGHT_7; // idb
PStringBase<char> KW_JUMPITEMINDEX_7; // idb
PStringBase<char> KW_LEFTEDGE_7; // idb
PStringBase<char> KW_MAXDURATION_7; // idb
PStringBase<char> KW_MEDIA_7; // idb
PStringBase<char> KW_MEDIATYPE_7; // idb
PStringBase<char> KW_MINDURATION_7; // idb
PStringBase<char> KW_NO_DB_FILE_7; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_7; // idb
PStringBase<char> KW_PASSTOCHILDREN_7; // idb
PStringBase<char> KW_PROBABILITY_7; // idb
PStringBase<char> KW_PROPERTIES_8; // idb
PStringBase<char> KW_REMOVE_7; // idb
PStringBase<char> KW_RIGHTEDGE_7; // idb
PStringBase<char> KW_SOUNDNAME_7; // idb
PStringBase<char> KW_SOUNDTABLE_7; // idb
PStringBase<char> KW_STARTALPHA_7; // idb
PStringBase<char> KW_STATE_7; // idb
PStringBase<char> KW_STATEHEADER_7; // idb
PStringBase<char> KW_STATEWHEADER_7; // idb
PStringBase<char> KW_STATEID_7; // idb
PStringBase<char> KW_TOPEDGE_7; // idb
PStringBase<char> KW_TYPE_7; // idb
PStringBase<char> KW_WIDTH_7; // idb
PStringBase<char> KW_X_7; // idb
PStringBase<char> KW_XHOTSPOT_7; // idb
PStringBase<char> KW_Y_7; // idb
PStringBase<char> KW_YHOTSPOT_7; // idb
PStringBase<char> KW_ZLEVEL_7; // idb
PStringBase<char> KW_COMMENTS_7; // idb
PStringBase<char> KW_HAS_ALPHA_7; // idb
PStringBase<char> KW_NULL_12; // idb
PStringBase<char> KW_BASE_8; // idb
PStringBase<char> KW_BOTTOMEDGE_8; // idb
PStringBase<char> KW_CHILD_8; // idb
PStringBase<char> KW_CODE_8; // idb
PStringBase<char> KW_DEFAULTSTATE_8; // idb
PStringBase<char> KW_DISPLAYHEIGHT_8; // idb
PStringBase<char> KW_DISPLAYWIDTH_8; // idb
PStringBase<char> KW_DRAWMODE_8; // idb
PStringBase<char> KW_DURATION_8; // idb
PStringBase<char> KW_ELEMENT_8; // idb
PStringBase<char> KW_ELEMENTHEADER_8; // idb
PStringBase<char> KW_ELEMENTWHEADER_8; // idb
PStringBase<char> KW_ELEMENTID_8; // idb
PStringBase<char> KW_ENDALPHA_8; // idb
PStringBase<char> KW_ENGINETYPE_8; // idb
PStringBase<char> KW_EVENTID_8; // idb
PStringBase<char> KW_FILE_8; // idb
PStringBase<char> KW_FRAMES_8; // idb
PStringBase<char> KW_HEADER_8; // idb
PStringBase<char> KW_HEIGHT_8; // idb
PStringBase<char> KW_JUMPITEMINDEX_8; // idb
PStringBase<char> KW_LEFTEDGE_8; // idb
PStringBase<char> KW_MAXDURATION_8; // idb
PStringBase<char> KW_MEDIA_8; // idb
PStringBase<char> KW_MEDIATYPE_8; // idb
PStringBase<char> KW_MINDURATION_8; // idb
PStringBase<char> KW_NO_DB_FILE_8; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_8; // idb
PStringBase<char> KW_PASSTOCHILDREN_8; // idb
PStringBase<char> KW_PROBABILITY_8; // idb
PStringBase<char> KW_PROPERTIES_9; // idb
PStringBase<char> KW_REMOVE_8; // idb
PStringBase<char> KW_RIGHTEDGE_8; // idb
PStringBase<char> KW_SOUNDNAME_8; // idb
PStringBase<char> KW_SOUNDTABLE_8; // idb
PStringBase<char> KW_STARTALPHA_8; // idb
PStringBase<char> KW_STATE_8; // idb
PStringBase<char> KW_STATEHEADER_8; // idb
PStringBase<char> KW_STATEWHEADER_8; // idb
PStringBase<char> KW_STATEID_8; // idb
PStringBase<char> KW_TOPEDGE_8; // idb
PStringBase<char> KW_TYPE_8; // idb
PStringBase<char> KW_WIDTH_8; // idb
PStringBase<char> KW_X_8; // idb
PStringBase<char> KW_XHOTSPOT_8; // idb
PStringBase<char> KW_Y_8; // idb
PStringBase<char> KW_YHOTSPOT_8; // idb
PStringBase<char> KW_ZLEVEL_8; // idb
PStringBase<char> KW_COMMENTS_8; // idb
PStringBase<char> KW_HAS_ALPHA_8; // idb
PStringBase<char> KW_NULL_13; // idb
PStringBase<char> KW_BASE_9; // idb
PStringBase<char> KW_BOTTOMEDGE_9; // idb
PStringBase<char> KW_CHILD_9; // idb
PStringBase<char> KW_CODE_9; // idb
PStringBase<char> KW_DEFAULTSTATE_9; // idb
PStringBase<char> KW_DISPLAYHEIGHT_9; // idb
PStringBase<char> KW_DISPLAYWIDTH_9; // idb
PStringBase<char> KW_DRAWMODE_9; // idb
PStringBase<char> KW_DURATION_9; // idb
PStringBase<char> KW_ELEMENT_9; // idb
PStringBase<char> KW_ELEMENTHEADER_9; // idb
PStringBase<char> KW_ELEMENTWHEADER_9; // idb
PStringBase<char> KW_ELEMENTID_9; // idb
PStringBase<char> KW_ENDALPHA_9; // idb
PStringBase<char> KW_ENGINETYPE_9; // idb
PStringBase<char> KW_EVENTID_9; // idb
PStringBase<char> KW_FILE_9; // idb
PStringBase<char> KW_FRAMES_9; // idb
PStringBase<char> KW_HEADER_9; // idb
PStringBase<char> KW_HEIGHT_9; // idb
PStringBase<char> KW_JUMPITEMINDEX_9; // idb
PStringBase<char> KW_LEFTEDGE_9; // idb
PStringBase<char> KW_MAXDURATION_9; // idb
PStringBase<char> KW_MEDIA_9; // idb
PStringBase<char> KW_MEDIATYPE_9; // idb
PStringBase<char> KW_MINDURATION_9; // idb
PStringBase<char> KW_NO_DB_FILE_9; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_9; // idb
PStringBase<char> KW_PASSTOCHILDREN_9; // idb
PStringBase<char> KW_PROBABILITY_9; // idb
PStringBase<char> KW_PROPERTIES_10; // idb
PStringBase<char> KW_REMOVE_9; // idb
PStringBase<char> KW_RIGHTEDGE_9; // idb
PStringBase<char> KW_SOUNDNAME_9; // idb
PStringBase<char> KW_SOUNDTABLE_9; // idb
PStringBase<char> KW_STARTALPHA_9; // idb
PStringBase<char> KW_STATE_9; // idb
PStringBase<char> KW_STATEHEADER_9; // idb
PStringBase<char> KW_STATEWHEADER_9; // idb
PStringBase<char> KW_STATEID_9; // idb
PStringBase<char> KW_TOPEDGE_9; // idb
PStringBase<char> KW_TYPE_9; // idb
PStringBase<char> KW_WIDTH_9; // idb
PStringBase<char> KW_X_9; // idb
PStringBase<char> KW_XHOTSPOT_9; // idb
PStringBase<char> KW_Y_9; // idb
PStringBase<char> KW_YHOTSPOT_9; // idb
PStringBase<char> KW_ZLEVEL_9; // idb
PStringBase<char> KW_COMMENTS_9; // idb
PStringBase<char> KW_HAS_ALPHA_9; // idb
PStringBase<char> KW_NULL_14; // idb
PStringBase<char> KW_BASE_10; // idb
PStringBase<char> KW_BOTTOMEDGE_10; // idb
PStringBase<char> KW_CHILD_10; // idb
PStringBase<char> KW_CODE_10; // idb
PStringBase<char> KW_DEFAULTSTATE_10; // idb
PStringBase<char> KW_DISPLAYHEIGHT_10; // idb
PStringBase<char> KW_DISPLAYWIDTH_10; // idb
PStringBase<char> KW_DRAWMODE_10; // idb
PStringBase<char> KW_DURATION_10; // idb
PStringBase<char> KW_ELEMENT_10; // idb
PStringBase<char> KW_ELEMENTHEADER_10; // idb
PStringBase<char> KW_ELEMENTWHEADER_10; // idb
PStringBase<char> KW_ELEMENTID_10; // idb
PStringBase<char> KW_ENDALPHA_10; // idb
PStringBase<char> KW_ENGINETYPE_10; // idb
PStringBase<char> KW_EVENTID_10; // idb
PStringBase<char> KW_FILE_10; // idb
PStringBase<char> KW_FRAMES_10; // idb
PStringBase<char> KW_HEADER_10; // idb
PStringBase<char> KW_HEIGHT_10; // idb
PStringBase<char> KW_JUMPITEMINDEX_10; // idb
PStringBase<char> KW_LEFTEDGE_10; // idb
PStringBase<char> KW_MAXDURATION_10; // idb
PStringBase<char> KW_MEDIA_10; // idb
PStringBase<char> KW_MEDIATYPE_10; // idb
PStringBase<char> KW_MINDURATION_10; // idb
PStringBase<char> KW_NO_DB_FILE_10; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_10; // idb
PStringBase<char> KW_PASSTOCHILDREN_10; // idb
PStringBase<char> KW_PROBABILITY_10; // idb
PStringBase<char> KW_PROPERTIES_11; // idb
PStringBase<char> KW_REMOVE_10; // idb
PStringBase<char> KW_RIGHTEDGE_10; // idb
PStringBase<char> KW_SOUNDNAME_10; // idb
PStringBase<char> KW_SOUNDTABLE_10; // idb
PStringBase<char> KW_STARTALPHA_10; // idb
PStringBase<char> KW_STATE_10; // idb
PStringBase<char> KW_STATEHEADER_10; // idb
PStringBase<char> KW_STATEWHEADER_10; // idb
PStringBase<char> KW_STATEID_10; // idb
PStringBase<char> KW_TOPEDGE_10; // idb
PStringBase<char> KW_TYPE_10; // idb
PStringBase<char> KW_WIDTH_10; // idb
PStringBase<char> KW_X_10; // idb
PStringBase<char> KW_XHOTSPOT_10; // idb
PStringBase<char> KW_Y_10; // idb
PStringBase<char> KW_YHOTSPOT_10; // idb
PStringBase<char> KW_ZLEVEL_10; // idb
PStringBase<char> KW_COMMENTS_10; // idb
PStringBase<char> KW_HAS_ALPHA_10; // idb
IDClass<_tagDataID,32,0> stru_8F994C; // idb
PStringBase<char> KW_NULL_15; // idb
PStringBase<char> KW_BASE_11; // idb
PStringBase<char> KW_BOTTOMEDGE_11; // idb
PStringBase<char> KW_CHILD_11; // idb
PStringBase<char> KW_CODE_11; // idb
PStringBase<char> KW_DEFAULTSTATE_11; // idb
PStringBase<char> KW_DISPLAYHEIGHT_11; // idb
PStringBase<char> KW_DISPLAYWIDTH_11; // idb
PStringBase<char> KW_DRAWMODE_11; // idb
PStringBase<char> KW_DURATION_11; // idb
PStringBase<char> KW_ELEMENT_11; // idb
PStringBase<char> KW_ELEMENTHEADER_11; // idb
PStringBase<char> KW_ELEMENTWHEADER_11; // idb
PStringBase<char> KW_ELEMENTID_11; // idb
PStringBase<char> KW_ENDALPHA_11; // idb
PStringBase<char> KW_ENGINETYPE_11; // idb
PStringBase<char> KW_EVENTID_11; // idb
PStringBase<char> KW_FILE_11; // idb
PStringBase<char> KW_FRAMES_11; // idb
PStringBase<char> KW_HEADER_11; // idb
PStringBase<char> KW_HEIGHT_11; // idb
PStringBase<char> KW_JUMPITEMINDEX_11; // idb
PStringBase<char> KW_LEFTEDGE_11; // idb
PStringBase<char> KW_MAXDURATION_11; // idb
PStringBase<char> KW_MEDIA_11; // idb
PStringBase<char> KW_MEDIATYPE_11; // idb
PStringBase<char> KW_MINDURATION_11; // idb
PStringBase<char> KW_NO_DB_FILE_11; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_11; // idb
PStringBase<char> KW_PASSTOCHILDREN_11; // idb
PStringBase<char> KW_PROBABILITY_11; // idb
PStringBase<char> KW_PROPERTIES_12; // idb
PStringBase<char> KW_REMOVE_11; // idb
PStringBase<char> KW_RIGHTEDGE_11; // idb
PStringBase<char> KW_SOUNDNAME_11; // idb
PStringBase<char> KW_SOUNDTABLE_11; // idb
PStringBase<char> KW_STARTALPHA_11; // idb
PStringBase<char> KW_STATE_11; // idb
PStringBase<char> KW_STATEHEADER_11; // idb
PStringBase<char> KW_STATEWHEADER_11; // idb
PStringBase<char> KW_STATEID_11; // idb
PStringBase<char> KW_TOPEDGE_11; // idb
PStringBase<char> KW_TYPE_11; // idb
PStringBase<char> KW_WIDTH_11; // idb
PStringBase<char> KW_X_11; // idb
PStringBase<char> KW_XHOTSPOT_11; // idb
PStringBase<char> KW_Y_11; // idb
PStringBase<char> KW_YHOTSPOT_11; // idb
PStringBase<char> KW_ZLEVEL_11; // idb
PStringBase<char> KW_COMMENTS_11; // idb
PStringBase<char> KW_HAS_ALPHA_11; // idb
PStringBase<char> KW_NULL_16; // idb
PStringBase<char> KW_BASE_12; // idb
PStringBase<char> KW_BOTTOMEDGE_12; // idb
PStringBase<char> KW_CHILD_12; // idb
PStringBase<char> KW_CODE_12; // idb
PStringBase<char> KW_DEFAULTSTATE_12; // idb
PStringBase<char> KW_DISPLAYHEIGHT_12; // idb
PStringBase<char> KW_DISPLAYWIDTH_12; // idb
PStringBase<char> KW_DRAWMODE_12; // idb
PStringBase<char> KW_DURATION_12; // idb
PStringBase<char> KW_ELEMENT_12; // idb
PStringBase<char> KW_ELEMENTHEADER_12; // idb
PStringBase<char> KW_ELEMENTWHEADER_12; // idb
PStringBase<char> KW_ELEMENTID_12; // idb
PStringBase<char> KW_ENDALPHA_12; // idb
PStringBase<char> KW_ENGINETYPE_12; // idb
PStringBase<char> KW_EVENTID_12; // idb
PStringBase<char> KW_FILE_12; // idb
PStringBase<char> KW_FRAMES_12; // idb
PStringBase<char> KW_HEADER_12; // idb
PStringBase<char> KW_HEIGHT_12; // idb
PStringBase<char> KW_JUMPITEMINDEX_12; // idb
PStringBase<char> KW_LEFTEDGE_12; // idb
PStringBase<char> KW_MAXDURATION_12; // idb
PStringBase<char> KW_MEDIA_12; // idb
PStringBase<char> KW_MEDIATYPE_12; // idb
PStringBase<char> KW_MINDURATION_12; // idb
PStringBase<char> KW_NO_DB_FILE_12; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_12; // idb
PStringBase<char> KW_PASSTOCHILDREN_12; // idb
PStringBase<char> KW_PROBABILITY_12; // idb
PStringBase<char> KW_PROPERTIES_13; // idb
PStringBase<char> KW_REMOVE_12; // idb
PStringBase<char> KW_RIGHTEDGE_12; // idb
PStringBase<char> KW_SOUNDNAME_12; // idb
PStringBase<char> KW_SOUNDTABLE_12; // idb
PStringBase<char> KW_STARTALPHA_12; // idb
PStringBase<char> KW_STATE_12; // idb
PStringBase<char> KW_STATEHEADER_12; // idb
PStringBase<char> KW_STATEWHEADER_12; // idb
PStringBase<char> KW_STATEID_12; // idb
PStringBase<char> KW_TOPEDGE_12; // idb
PStringBase<char> KW_TYPE_12; // idb
PStringBase<char> KW_WIDTH_12; // idb
PStringBase<char> KW_X_12; // idb
PStringBase<char> KW_XHOTSPOT_12; // idb
PStringBase<char> KW_Y_12; // idb
PStringBase<char> KW_YHOTSPOT_12; // idb
PStringBase<char> KW_ZLEVEL_12; // idb
PStringBase<char> KW_COMMENTS_12; // idb
PStringBase<char> KW_HAS_ALPHA_12; // idb
IDClass<_tagDataID,32,0> stru_8F9AEC; // idb
PStringBase<char> KW_NULL_17; // idb
PStringBase<char> KW_BASE_13; // idb
PStringBase<char> KW_BOTTOMEDGE_13; // idb
PStringBase<char> KW_CHILD_13; // idb
PStringBase<char> KW_CODE_13; // idb
PStringBase<char> KW_DEFAULTSTATE_13; // idb
PStringBase<char> KW_DISPLAYHEIGHT_13; // idb
PStringBase<char> KW_DISPLAYWIDTH_13; // idb
PStringBase<char> KW_DRAWMODE_13; // idb
PStringBase<char> KW_DURATION_13; // idb
PStringBase<char> KW_ELEMENT_13; // idb
PStringBase<char> KW_ELEMENTHEADER_13; // idb
PStringBase<char> KW_ELEMENTWHEADER_13; // idb
PStringBase<char> KW_ELEMENTID_13; // idb
PStringBase<char> KW_ENDALPHA_13; // idb
PStringBase<char> KW_ENGINETYPE_13; // idb
PStringBase<char> KW_EVENTID_13; // idb
PStringBase<char> KW_FILE_13; // idb
PStringBase<char> KW_FRAMES_13; // idb
PStringBase<char> KW_HEADER_13; // idb
PStringBase<char> KW_HEIGHT_13; // idb
PStringBase<char> KW_JUMPITEMINDEX_13; // idb
PStringBase<char> KW_LEFTEDGE_13; // idb
PStringBase<char> KW_MAXDURATION_13; // idb
PStringBase<char> KW_MEDIA_13; // idb
PStringBase<char> KW_MEDIATYPE_13; // idb
PStringBase<char> KW_MINDURATION_13; // idb
PStringBase<char> KW_NO_DB_FILE_13; // idb
PStringBase<char> KW_STRETCH_TO_FULL_SCREEN_13; // idb
PStringBase<char> KW_PASSTOCHILDREN_13; // idb
PStringBase<char> KW_PROBABILITY_13; // idb
PStringBase<char> KW_PROPERTIES_14; // idb
PStringBase<char> KW_REMOVE_13; // idb
PStringBase<char> KW_RIGHTEDGE_13; // idb
PStringBase<char> KW_SOUNDNAME_13; // idb
PStringBase<char> KW_SOUNDTABLE_13; // idb
PStringBase<char> KW_STARTALPHA_13; // idb
PStringBase<char> KW_STATE_13; // idb
PStringBase<char> KW_STATEHEADER_13; // idb
PStringBase<char> KW_STATEWHEADER_13; // idb
PStringBase<char> KW_STATEID_13; // idb
PStringBase<char> KW_TOPEDGE_13; // idb
PStringBase<char> KW_TYPE_13; // idb
PStringBase<char> KW_WIDTH_13; // idb
PStringBase<char> KW_X_13; // idb
PStringBase<char> KW_XHOTSPOT_13; // idb
PStringBase<char> KW_Y_13; // idb
PStringBase<char> KW_YHOTSPOT_13; // idb
PStringBase<char> KW_ZLEVEL_13; // idb
PStringBase<char> KW_COMMENTS_13; // idb
PStringBase<char> KW_HAS_ALPHA_13; // idb
RGBAColor RGBAColor_Null_40; // idb
PixelFormatDesc stru_8F9BE0; // idb
PStringBase<char> waveform_None_84; // idb
PStringBase<char> waveform_Speed_84; // idb
PStringBase<char> waveform_Noise_84; // idb
PStringBase<char> waveform_Sine_84; // idb
PStringBase<char> waveform_Square_84; // idb
PStringBase<char> waveform_Bounce_84; // idb
PStringBase<char> waveform_Perlin_84; // idb
PStringBase<char> waveform_Fractal_84; // idb
PStringBase<char> waveform_FrameLoop_84; // idb
PStringBase<char> Misc_TooltipEnable_49; // idb
PStringBase<char> Misc_TooltipDelay_49; // idb
PStringBase<char> Misc_TooltipEnable_50; // idb
PStringBase<char> Misc_TooltipDelay_50; // idb
PixelFormatDesc stru_8F9C68; // idb
IDClass<_tagDataID,32,0> stru_8F9CA0; // idb
PStringBase<char> waveform_None_85; // idb
PStringBase<char> waveform_Speed_85; // idb
PStringBase<char> waveform_Noise_85; // idb
PStringBase<char> waveform_Sine_85; // idb
PStringBase<char> waveform_Square_85; // idb
PStringBase<char> waveform_Bounce_85; // idb
PStringBase<char> waveform_Perlin_85; // idb
PStringBase<char> waveform_Fractal_85; // idb
PStringBase<char> waveform_FrameLoop_85; // idb
PStringBase<char> Misc_TooltipEnable_51; // idb
PStringBase<char> Misc_TooltipDelay_51; // idb
const float flt_8F9CE0; // idb
const float flt_8F9CE4; // idb
const float flt_8F9CE8; // idb
const float flt_8F9CF0; // idb
const long double dbl_8F9CF8; // idb
const long double dbl_8F9D00; // idb
PixelFormatDesc stru_8F9D08; // idb
const float flt_8F9D60; // idb
const float flt_8F9D64; // idb
const float flt_8F9D68; // idb
const float flt_8F9D6C; // idb
const long double dbl_8F9D70; // idb
const long double dbl_8F9D78; // idb
PixelFormatDesc stru_8F9D80; // idb
const int dword_8F9DB8; // idb
const int dword_8F9DBC; // idb
const int dword_8F9DC0; // idb
const float flt_8F9DE8; // idb
const float flt_8F9DEC; // idb
const float flt_8F9DF0; // idb
const float flt_8F9DF4; // idb
const long double dbl_8F9DF8; // idb
const long double dbl_8F9E00; // idb
PixelFormatDesc stru_8F9E08; // idb
const int dword_8F9E40; // idb
const int dword_8F9E44; // idb
const int dword_8F9E48; // idb
const float flt_8F9E70; // idb
const float flt_8F9E74; // idb
const float flt_8F9E78; // idb
const float flt_8F9E7C; // idb
const long double dbl_8F9E80; // idb
const long double dbl_8F9E88; // idb
PixelFormatDesc stru_8F9E90; // idb
const int dword_8F9EC8; // idb
const int dword_8F9ECC; // idb
const int dword_8F9ED0; // idb
const float flt_8F9EF8; // idb
const float flt_8F9EFC; // idb
const float flt_8F9F00; // idb
const float flt_8F9F04; // idb
const long double dbl_8F9F08; // idb
const long double dbl_8F9F10; // idb
PixelFormatDesc stru_8F9F18; // idb
const int dword_8F9F50; // idb
const int dword_8F9F54; // idb
const int dword_8F9F58; // idb
const float flt_8F9F80; // idb
const float flt_8F9F84; // idb
const float flt_8F9F88; // idb
const float flt_8F9F8C; // idb
const long double dbl_8F9F90; // idb
const long double dbl_8F9F98; // idb
PixelFormatDesc stru_8F9FA0; // idb
const int dword_8F9FD8; // idb
const int dword_8F9FDC; // idb
const int dword_8F9FE0; // idb
const float flt_8FA004; // idb
const float flt_8FA008; // idb
const float flt_8FA00C; // idb
const float flt_8FA014; // idb
const long double dbl_8FA018; // idb
const long double dbl_8FA020; // idb
PixelFormatDesc stru_8FA028; // idb
const int dword_8FA060; // idb
const int dword_8FA064; // idb
const int dword_8FA068; // idb
const float flt_8FA08C; // idb
const float flt_8FA090; // idb
const float flt_8FA094; // idb
const float flt_8FA0A8; // idb
const float flt_8FA0AC; // idb
const float flt_8FA0B0; // idb
const float flt_8FA0D8; // idb
const float flt_8FA0DC; // idb
const float flt_8FA0E0; // idb
const float flt_8FA0E4; // idb
const long double dbl_8FA0E8; // idb
const long double dbl_8FA0F0; // idb
PixelFormatDesc stru_8FA0F8; // idb
const int dword_8FA130; // idb
const int dword_8FA134; // idb
const int dword_8FA138; // idb
const float flt_8FA160; // idb
const float flt_8FA164; // idb
const float flt_8FA168; // idb
const float flt_8FA16C; // idb
const long double dbl_8FA170; // idb
const long double dbl_8FA178; // idb
PixelFormatDesc stru_8FA180; // idb
const int dword_8FA1B8; // idb
const int dword_8FA1BC; // idb
const int dword_8FA1C0; // idb
const float flt_8FA1E4; // idb
const float flt_8FA1E8; // idb
const float flt_8FA1EC; // idb
const float flt_8FA210; // idb
const float flt_8FA214; // idb
const float flt_8FA218; // idb
const float flt_8FA21C; // idb
const long double dbl_8FA220; // idb
const long double dbl_8FA228; // idb
PixelFormatDesc stru_8FA230; // idb
const int dword_8FA268; // idb
const int dword_8FA26C; // idb
const int dword_8FA270; // idb
const float flt_8FA294; // idb
const float flt_8FA298; // idb
const float flt_8FA29C; // idb
const float flt_8FA2BC; // idb
const float flt_8FA2C0; // idb
const float flt_8FA2C4; // idb
const float flt_8FA2CC; // idb
const long double dbl_8FA2D0; // idb
const long double dbl_8FA2D8; // idb
PixelFormatDesc stru_8FA2E0; // idb
const int dword_8FA318; // idb
const int dword_8FA31C; // idb
const int dword_8FA320; // idb
const float flt_8FA348; // idb
const float flt_8FA34C; // idb
const float flt_8FA350; // idb
const float flt_8FA354; // idb
const long double dbl_8FA358; // idb
const long double dbl_8FA360; // idb
PixelFormatDesc stru_8FA368; // idb
const int dword_8FA3A0; // idb
const int dword_8FA3A4; // idb
const int dword_8FA3A8; // idb
const float flt_8FA3C0; // idb
const float flt_8FA3C4; // idb
const float flt_8FA3C8; // idb
const float flt_8FA3D0; // idb
const long double dbl_8FA3D8; // idb
const long double dbl_8FA3E0; // idb
const int dword_8FA3E8; // idb
PixelFormatDesc stru_8FA3EC; // idb
const float flt_8FA448; // idb
const float flt_8FA44C; // idb
const float flt_8FA450; // idb
const float flt_8FA454; // idb
const long double dbl_8FA458; // idb
const long double dbl_8FA460; // idb
PixelFormatDesc stru_8FA468; // idb
const int dword_8FA4A0; // idb
const int dword_8FA4A4; // idb
const int dword_8FA4A8; // idb
const float flt_8FA4D0; // idb
const float flt_8FA4D4; // idb
const float flt_8FA4D8; // idb
const float flt_8FA4DC; // idb
const long double dbl_8FA4E0; // idb
const long double dbl_8FA4E8; // idb
PixelFormatDesc stru_8FA4F0; // idb
const int dword_8FA528; // idb
const int dword_8FA52C; // idb
const int dword_8FA530; // idb
const float flt_8FA558; // idb
const float flt_8FA55C; // idb
const float flt_8FA560; // idb
const float flt_8FA564; // idb
const long double dbl_8FA568; // idb
const long double dbl_8FA570; // idb
PixelFormatDesc stru_8FA578; // idb
const int dword_8FA5B0; // idb
const int dword_8FA5B4; // idb
const int dword_8FA5B8; // idb
const float flt_8FA5E0; // idb
const float flt_8FA5E4; // idb
const float flt_8FA5E8; // idb
const float flt_8FA5EC; // idb
const long double dbl_8FA5F0; // idb
const long double dbl_8FA5F8; // idb
PixelFormatDesc stru_8FA600; // idb
const int dword_8FA638; // idb
const int dword_8FA63C; // idb
const int dword_8FA640; // idb
const float flt_8FA668; // idb
const float flt_8FA66C; // idb
const float flt_8FA670; // idb
const float flt_8FA674; // idb
const long double dbl_8FA678; // idb
const long double dbl_8FA680; // idb
PixelFormatDesc stru_8FA688; // idb
const int dword_8FA6C0; // idb
const int dword_8FA6C4; // idb
const int dword_8FA6C8; // idb
const float flt_8FA6EC; // idb
const float flt_8FA6F0; // idb
const float flt_8FA6F4; // idb
const float dword_8FA718; // idb
const float flt_8FA71C; // idb
const float flt_8FA720; // idb
const float flt_8FA724; // idb
const float flt_8FA738; // idb
const float flt_8FA73C; // idb
const float flt_8FA740; // idb
PStringBase<char> g_strClientRegKeyBasePath; // idb
const float flt_8FA75C; // idb
const float flt_8FA760; // idb
const float flt_8FA764; // idb
unsigned int num_rejects; // idb
const float flt_8FA78C; // idb
const float flt_8FA790; // idb
const float flt_8FA794; // idb
const int dword_8FA79C; // idb
const float flt_8FA7A0; // idb
const long double dbl_8FA7A8; // idb
const long double dbl_8FA7B0; // idb
PixelFormatDesc stru_8FA7B8; // idb
PStringBase<unsigned short> cant_sit_combat_1; // idb
PStringBase<unsigned short> cant_lie_down_combat_1; // idb
PStringBase<unsigned short> cant_crouch_combat_1; // idb
PStringBase<unsigned short> cant_emote_position_1; // idb
PStringBase<unsigned short> cant_emote_combat_1; // idb
PStringBase<unsigned short> cant_jump_position_1; // idb
PStringBase<unsigned short> cant_jump_in_air_1; // idb
PStringBase<unsigned short> cant_jump_load_1; // idb
PStringBase<unsigned short> cant_jump_stamina_1; // idb
PStringBase<unsigned short> cant_jump_recent_1; // idb
PStringBase<unsigned short> too_tired_1; // idb
const int dword_8FA83C; // idb
const float flt_8FA840; // idb
const float flt_8FA844; // idb
const float flt_8FA848; // idb
const float flt_8FA850; // idb
const long double dbl_8FA858; // idb
const long double dbl_8FA860; // idb
PixelFormatDesc stru_8FA884; // idb
const float dword_8FA8BC; // idb
const float flt_8FA8C0; // idb
const float flt_8FA8C4; // idb
const float flt_8FA8C8; // idb
PStringBase<char> Render_TextureFiltering_49; // idb
PStringBase<char> Render_LandscapeDetailTextures_49; // idb
PStringBase<char> Render_BuildingDetailTextures_49; // idb
PStringBase<char> Render_FieldOfView_49; // idb
PStringBase<char> Render_LandscapeTextureDetail_49; // idb
PStringBase<char> Render_EnvironmentTextureDetail_49; // idb
PStringBase<char> Render_SceneryDrawDistance_49; // idb
PStringBase<char> Render_LandscapeDrawDistance_49; // idb
PStringBase<char> Render_ScreenBrightness_49; // idb
PStringBase<char> Render_AspectRatio_49; // idb
PStringBase<char> Render_DisplayAdapter_49; // idb
PStringBase<char> Render_MaxHardwareClass_49; // idb
PStringBase<char> Render_AutomaticDegrades_49; // idb
PStringBase<char> Render_GraphicsPerformance_49; // idb
PStringBase<char> Render_DegradeDistance_49; // idb
PStringBase<char> Render_MultiPassAlpha_49; // idb
PStringBase<char> Render_TextureFiltering_Choices_49[4]; // idb
PStringBase<char> stru_8FA914; // idb
PStringBase<char> stru_8FA918; // idb
PStringBase<char> stru_8FA91C; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_49[5]; // idb
PStringBase<char> stru_8FA924; // idb
PStringBase<char> stru_8FA928; // idb
PStringBase<char> stru_8FA92C; // idb
PStringBase<char> stru_8FA930; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_49[5]; // idb
PStringBase<char> stru_8FA938; // idb
PStringBase<char> stru_8FA93C; // idb
PStringBase<char> stru_8FA940; // idb
PStringBase<char> stru_8FA944; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_49[3]; // idb
PStringBase<char> stru_8FA94C; // idb
PStringBase<char> stru_8FA950; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_49[6]; // idb
PStringBase<char> stru_8FA958; // idb
PStringBase<char> stru_8FA95C; // idb
PStringBase<char> stru_8FA960; // idb
PStringBase<char> stru_8FA964; // idb
PStringBase<char> stru_8FA968; // idb
PStringBase<char> Render_AspectRatio_Choices_49[3]; // idb
PStringBase<char> stru_8FA970; // idb
PStringBase<char> stru_8FA974; // idb
PStringBase<char> waveform_None_86; // idb
PStringBase<char> waveform_Speed_86; // idb
PStringBase<char> waveform_Noise_86; // idb
PStringBase<char> waveform_Sine_86; // idb
PStringBase<char> waveform_Square_86; // idb
PStringBase<char> waveform_Bounce_86; // idb
PStringBase<char> waveform_Perlin_86; // idb
PStringBase<char> waveform_Fractal_86; // idb
PStringBase<char> waveform_FrameLoop_86; // idb
const float flt_8FA99C; // idb
const long double dbl_8FA9A0; // idb
const long double dbl_8FA9A8; // idb
Position *CBuildingObj::curr_pos; // idb
struct CPartCell **CBuildingObj::curr_leaf_cells; // weak
const float flt_8FA9DC; // idb
const float flt_8FA9E0; // idb
const float flt_8FA9E4; // idb
const float flt_8FA9EC; // idb
const long double dbl_8FA9F0; // idb
const long double dbl_8FA9F8; // idb
const int dword_8FAA00; // idb
const float flt_8FAA20; // idb
const float flt_8FAA24; // idb
const float flt_8FAA28; // idb
int S_inDWExecptionHandler; // idb
TurbineDwExceptionFilter::TurnOnDwExceptionHandler TurbineDwExceptionFilter::G_dwHandler; // idb
const float flt_8FB584; // idb
const float flt_8FB588; // idb
const float flt_8FB58C; // idb
const float flt_8FB590; // idb
const long double dbl_8FB598; // idb
const long double dbl_8FB5A0; // idb
PixelFormatDesc stru_8FB5A8; // idb
const int dword_8FB5E0; // idb
const int dword_8FB5E4; // idb
const int dword_8FB5E8; // idb
PStringBase<char> Misc_TooltipEnable_52; // idb
PStringBase<char> Misc_TooltipDelay_52; // idb
struct CMaterial *ACRender::back_curr_material; // weak
struct CSurface **ACRender::back_curr_surfaces; // weak
view_type *ACRender::backup_view; // idb
int ACRender::backup_view_num; // idb
struct portal_view_type *ACRender::BackupList; // weak
struct CSurface *ACRender::backup_detail_surface; // weak
struct RGBColor *ACRender::curLandBlockVertexLighting; // weak
PStringBase<char> Display_Resolution_40; // idb
PStringBase<char> Display_FullScreen_40; // idb
PStringBase<char> Display_RefreshRate_40; // idb
PStringBase<char> Display_SyncToRefresh_40; // idb
const float dword_8FB650; // idb
const float flt_8FB654; // idb
const float flt_8FB658; // idb
const float flt_8FB65C; // idb
const float flt_8FB664; // idb
const long double dbl_8FB668; // idb
const long double dbl_8FB670; // idb
const int dword_8FB678; // idb
const int dword_8FB67C; // idb
const int dword_8FB680; // idb
PixelFormatDesc stru_8FB684; // idb
PStringBase<char> Render_TextureFiltering_50; // idb
PStringBase<char> Render_LandscapeDetailTextures_50; // idb
PStringBase<char> Render_BuildingDetailTextures_50; // idb
PStringBase<char> Render_FieldOfView_50; // idb
PStringBase<char> Render_LandscapeTextureDetail_50; // idb
PStringBase<char> Render_EnvironmentTextureDetail_50; // idb
PStringBase<char> Render_SceneryDrawDistance_50; // idb
PStringBase<char> Render_LandscapeDrawDistance_50; // idb
PStringBase<char> Render_ScreenBrightness_50; // idb
PStringBase<char> Render_AspectRatio_50; // idb
PStringBase<char> Render_DisplayAdapter_50; // idb
PStringBase<char> Render_MaxHardwareClass_50; // idb
PStringBase<char> Render_AutomaticDegrades_50; // idb
PStringBase<char> Render_GraphicsPerformance_50; // idb
PStringBase<char> Render_DegradeDistance_50; // idb
PStringBase<char> Render_MultiPassAlpha_50; // idb
PStringBase<char> Render_TextureFiltering_Choices_50[4]; // idb
PStringBase<char> stru_8FB700; // idb
PStringBase<char> stru_8FB704; // idb
PStringBase<char> stru_8FB708; // idb
PStringBase<char> Render_LandscapeTextureDetail_Choices_50[5]; // idb
PStringBase<char> stru_8FB710; // idb
PStringBase<char> stru_8FB714; // idb
PStringBase<char> stru_8FB718; // idb
PStringBase<char> stru_8FB71C; // idb
PStringBase<char> Render_EnvironmentTextureDetail_Choices_50[5]; // idb
PStringBase<char> stru_8FB724; // idb
PStringBase<char> stru_8FB728; // idb
PStringBase<char> stru_8FB72C; // idb
PStringBase<char> stru_8FB730; // idb
PStringBase<char> Render_SceneryDrawDistance_Choices_50[3]; // idb
PStringBase<char> stru_8FB738; // idb
PStringBase<char> stru_8FB73C; // idb
PStringBase<char> Render_LandscapeDrawDistance_Choices_50[6]; // idb
PStringBase<char> stru_8FB744; // idb
PStringBase<char> stru_8FB748; // idb
PStringBase<char> stru_8FB74C; // idb
PStringBase<char> stru_8FB750; // idb
PStringBase<char> stru_8FB754; // idb
PStringBase<char> Render_AspectRatio_Choices_50[3]; // idb
PStringBase<char> stru_8FB75C; // idb
PStringBase<char> stru_8FB760; // idb
PStringBase<char> waveform_None_87; // idb
PStringBase<char> waveform_Speed_87; // idb
PStringBase<char> waveform_Noise_87; // idb
PStringBase<char> waveform_Sine_87; // idb
PStringBase<char> waveform_Square_87; // idb
PStringBase<char> waveform_Bounce_87; // idb
PStringBase<char> waveform_Perlin_87; // idb
PStringBase<char> waveform_Fractal_87; // idb
PStringBase<char> waveform_FrameLoop_87; // idb
const float cdstW; // idb
const float MY_MAX_MINUS_MIN_OO; // idb
CPolygon PolyOut; // idb
ClipPlaneList ClipPlaneListObj; // idb
CUSTOM_D3D_L_VERTEX v_2[3]; // idb
CUSTOM_D3D_L_VERTEX2 v_3[3]; // idb
CUSTOM_D3D_L_VERTEX v_4[6]; // idb
int dword_902084[]; // weak
float flt_902088[]; // weak
int dword_90208C[]; // weak
float flt_902090[]; // weak
float flt_902094[]; // weak
CUSTOM_D3D_L_VERTEX2 v_5[6]; // idb
int dword_902114[]; // weak
float flt_902118[]; // weak
int dword_90211C[]; // weak
float flt_902120[]; // weak
float flt_902124[]; // weak
float flt_902128[]; // weak
float flt_90212C[]; // weak
Vec2Dscreen tempPtBuf[800]; // idb
Vec2Dscreen *tempPtPBuf[57]; // idb
unsigned int _S235_1; // idb
IDClass<_tagDataID,32,0> stru_9054BC; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_35; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_35; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_36; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_35; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_36; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_36; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_37; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_36; // idb
struct _SECURITY_DESCRIPTOR RpcServer::sm_sid; // weak
int dword_9055C4; // weak
int dword_9055C8; // weak
int dword_9055CC; // weak
int dword_9055D0; // weak
unsigned int g_dwRpcServersListening; // idb
IDClass<_tagCellID,16,65535> In_Limbo_CellID_37; // idb
IDClass<_tagCellID,16,65535> Last_Interior_CellID_37; // idb
IDClass<_tagCellID,16,65535> Outside_CellID_38; // idb
IDClass<_tagCellID,16,65535> First_Interior_CellID_37; // idb
PStringBase<char> indent_string; // idb
PStringBase<char> dummy_string_filename; // idb
PStringBase<char> include_command_string; // idb
PStringBase<char> error_command_string; // idb
PStringBase<char> warning_command_string; // idb
PixelFormatDesc stru_905684; // idb
const float dword_9056C0; // idb
const float flt_9056C4; // idb
const float flt_9056C8; // idb
const float flt_9056CC; // idb
PStringBase<char> waveform_None_88; // idb
PStringBase<char> waveform_Speed_88; // idb
PStringBase<char> waveform_Noise_88; // idb
PStringBase<char> waveform_Sine_88; // idb
PStringBase<char> waveform_Square_88; // idb
PStringBase<char> waveform_Bounce_88; // idb
PStringBase<char> waveform_Perlin_88; // idb
PStringBase<char> waveform_Fractal_88; // idb
PStringBase<char> waveform_FrameLoop_88; // idb
PixelFormatDesc stru_905704; // idb
HMODULE hlibOLEAut32; // idb
volatile LONG CBaseObject::m_cObjects; // idb
UINT uMsgId; // idb
bool fTimeKillSynchronousFlagAvailable; // idb
bool fCheckedVersion; // idb
int (__stdcall *Unicows_lstrcatW)(); // idb
int (__stdcall *Unicows_wsprintfW)(); // idb
int (__stdcall *Unicows_RegCreateKeyExW)(); // idb
int (__stdcall *Unicows_RegEnumValueW)(); // idb
int (__stdcall *Unicows_RegSetValueExW)(); // idb
int (__stdcall *Unicows_ExtTextOutW)(); // idb
int (__stdcall *Unicows_CreateFontIndirectW)(); // idb
int (__stdcall *Unicows_GetTextMetricsW)(); // idb
int (__stdcall *Unicows_GetCharacterPlacementW)(); // idb
int (__stdcall *Unicows_GetObjectW)(); // idb
int (__stdcall *Unicows_GetTempFileNameW)(); // idb
int (__stdcall *Unicows_MoveFileW)(); // idb
int (__stdcall *Unicows_DeleteFileW)(); // idb
int (__stdcall *Unicows_FindResourceW)(); // idb
int (__stdcall *Unicows_CreateFileW)(); // idb
int (__stdcall *Unicows_lstrlenW)(); // idb
int (__stdcall *Unicows_MessageBoxW)(); // idb
int (__stdcall *Unicows_IsClipboardFormatAvailable)(); // idb
int (__stdcall *Unicows_GetClipboardData)(); // idb
int (__stdcall *Unicows_SetWindowLongA)(); // idb
int (__stdcall *Unicows_VerQueryValueW)(); // idb
int (__stdcall *Unicows_GetProcAddress)(); // idb
int (__stdcall *Unicows_RegOpenKeyExW)(); // idb
int (__stdcall *Unicows_RegQueryValueExW)(); // idb
int (__stdcall *Unicows_GetCurrentDirectoryW)(); // idb
int (__stdcall *Unicows_GetEnvironmentVariableW)(); // idb
int (__stdcall *Unicows_CreateDirectoryW)(); // idb
int (__stdcall *Unicows_WideCharToMultiByte)(); // idb
int (*_PfnLoadUnicows)(void); // weak
int (__stdcall *Unicows_MultiByteToWideChar)(); // idb
int _adjust_fdiv; // weak
int __onexitend; // weak
int __onexitbegin; // weak
char aSuccess[8] = "Success"; // weak
char aInterruptSucce[18] = "Interrupt Success"; // weak
char aRoiSuccess[12] = "ROI Success"; // weak
char aUnknownErrorCo[19] = "Unknown error code"; // weak
char aUser32[] = "user32"; // idb
char aMessageboxa[] = "MessageBoxA"; // idb
char aPeekmessagea[] = "PeekMessageA"; // idb
char aPostquitmessag[] = "PostQuitMessage"; // idb
char aWsprintfa[] = "wsprintfA"; // idb
char aAdvapi32[] = "advapi32"; // idb
char aRegopenkeyex_0[] = "RegOpenKeyExA"; // idb
char aRegqueryvalu_1[] = "RegQueryValueExA"; // idb
char aRegclosekey[] = "RegCloseKey"; // idb
_UNKNOWN unk_906C80; // weak
_UNKNOWN unk_906D40; // weak
_UNKNOWN unk_906E00; // weak
_UNKNOWN unk_906E40; // weak
_UNKNOWN unk_906E80; // weak
_UNKNOWN unk_906E90; // weak
_UNKNOWN unk_906E9C; // weak
_UNKNOWN unk_906EAC; // weak
_UNKNOWN unk_906EBC; // weak
_UNKNOWN unk_906EC8; // weak
int izigzag_index[] = { 0 }; // weak
int dword_906EE4[] = { 1 }; // weak
int dword_906EE8[] = { 8 }; // weak
int dword_906EEC[] = { 16 }; // weak
int onlynbits[] = { 0 }; // weak
_WORD lowest_coef[32] =
{
  0,
  0,
  65535,
  65535,
  65533,
  65535,
  65529,
  65535,
  65521,
  65535,
  65505,
  65535,
  65473,
  65535,
  65409,
  65535,
  65281,
  65535,
  65025,
  65535,
  64513,
  65535,
  63489,
  65535,
  61441,
  65535,
  57345,
  65535,
  49153,
  65535,
  32769,
  65535
}; // idb
int twoexpnminusone[] = { 0 }; // weak
int dword_907220[] = { 4096 }; // weak
int dword_907224[] = { 2953 }; // weak
double dbl_907340[] = {  0.125 }; // weak
double dbl_907348[] = {  0.17338 }; // weak
double dbl_907350[] = {  0.17338 }; // weak
double dbl_907358[] = {  0.16332 }; // weak
double dbl_907540 =  32768.0; // weak
double dbl_907548 =  0.0625; // weak
double dbl_907550 =  0.5; // weak
char byte_907560[] = { '\0' }; // weak
char byte_907660[] = { '\0' }; // weak
_DWORD dword_9078E0[4] = { 0, 0, 0, 0 }; // idb
_UNKNOWN unk_9078F0; // weak
_UNKNOWN unk_9078F8; // weak
_UNKNOWN unk_907908; // weak
_UNKNOWN unk_907910; // weak
_UNKNOWN unk_907920; // weak
_UNKNOWN unk_907928; // weak
_UNKNOWN unk_907938; // weak
int dword_907948 = 0; // weak
int dword_90794C = 0; // weak
int dword_907950 = 16; // weak
int dword_907954 = 16; // weak
int dword_907958 = 0; // weak
int dword_90795C = 0; // weak
int dword_907960 = 16; // weak
int dword_907964 = 16; // weak
int dword_907968 = 0; // weak
int dword_90796C = 0; // weak
int dword_907970 = 8; // weak
int dword_907974 = 8; // weak
int dword_907978 = 0; // weak
int dword_90797C = 0; // weak
int dword_907980 = 8; // weak
int dword_907984 = 8; // weak
int dword_907988 = 0; // weak
int dword_90798C = 0; // weak
int dword_907990 = 16; // weak
int dword_907994 = 8; // weak
int dword_907998 = 0; // weak
int dword_90799C = 0; // weak
int dword_9079A0 = 16; // weak
int dword_9079A4 = 8; // weak
int dword_9079A8 = 0; // weak
int dword_9079AC = 0; // weak
int dword_9079B0 = 8; // weak
int dword_9079B4 = 8; // weak
int dword_9079B8 = 0; // weak
int dword_9079BC = 0; // weak
int dword_9079C0 = 16; // weak
int dword_9079C4 = 8; // weak
int dword_9079C8 = 0; // weak
int dword_9079CC = 0; // weak
int dword_9079D0 = 16; // weak
int dword_9079D4 = 16; // weak
int dword_9079D8 = 0; // weak
int dword_9079DC = 0; // weak
int dword_9079E0 = 8; // weak
int dword_9079E4 = 8; // weak
int dword_9079E8 = 0; // weak
int dword_9079EC = 0; // weak
int dword_9079F0 = 16; // weak
int dword_9079F4 = 8; // weak
int dword_9079F8 = 0; // weak
int dword_9079FC = 0; // weak
int dword_907A00 = 16; // weak
int dword_907A04 = 16; // weak
int dword_907A08 = 0; // weak
int dword_907A0C = 0; // weak
int dword_907A10 = 8; // weak
int dword_907A14 = 8; // weak
int dword_907A18 = 0; // weak
int dword_907A1C = 0; // weak
int dword_907A20 = 8; // weak
int dword_907A24 = 8; // weak
int dword_907A28 = 0; // weak
int dword_907A2C = 0; // weak
int dword_907A30 = 8; // weak
int dword_907A34 = 8; // weak
int dword_907A38 = 0; // weak
int dword_907A3C = 0; // weak
int dword_907A40 = 16; // weak
int dword_907A44 = 16; // weak
int dword_907A48 = 0; // weak
int dword_907A4C = 0; // weak
int dword_907A50 = 16; // weak
int dword_907A54 = 8; // weak
int dword_907A58 = 0; // weak
int dword_907A5C = 0; // weak
int dword_907A60 = 16; // weak
int dword_907A64 = 8; // weak
int dword_907A68 = 0; // weak
int dword_907A6C = 0; // weak
int dword_907A70 = 8; // weak
int dword_907A74 = 8; // weak
char aIntelRJpegLibr[34] = "Intel(R) JPEG Library, version %s"; // weak
