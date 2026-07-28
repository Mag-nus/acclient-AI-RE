# Networking and the Wire Protocol

Target: acclient.exe 11.4186 (September 2013). Line references are into
`../acclient.c` and `../acclient.h` unless noted.

> **Revision note.** Three passes: an initial survey, an adversarial
> verification pass, and a third pass that re-checked the second pass's own
> corrections. The third pass found one mechanism described backwards (§3, the
> `Indicator` stamp comparison), one badly wrong citation (`CalcChecksum32`), and
> several opcode-range overstatements. All are corrected below. Claims that rest
> on inference rather than direct reading are now labelled as such.

---

## 1. Class map — the naming is misleading

`ClientCommunicationSystem` is **not** the transport. It is the chat and
slash-command subsystem: a hash of `CmdHashData{func, help}`
(acclient.h:40696–40713).

`CCommunicationSystem` and `gmCCommunicationSystem` are the Turbine Chat wrapper.
There is no TCP anywhere; chat tunnels over the game link (§8).

The real UDP stack:

| Layer | Class | Where |
|---|---|---|
| Socket and packet parse | `SharedNet` / `ClientNet` | acclient.h:34372, 35165 |
| Per-peer receive state | `ReceiverData` | acclient.h:34440 |
| Per-peer send state | `RecipientData` + `FlowQueue` / `ClientFlowQueue` | acclient.h:34752, 34720 / 34745 |
| Packet | `CNetLayerPacket : NetPacket` (`m_Data[65484]`) | acclient.h:34532 |
| Header | `ProtoHeader` | acclient.h:34520 |
| Reassembly / dedup | **`Indicator`** | acclient.h:34900 |
| Fragment | `BlobFrag` + `BlobFragHeader_t` | acclient.h:33220, 33210 |
| Message | `NetBlob` | acclient.h:29468 |
| Routing | `PacketController` (12 receive queues) | acclient.h:35522 |
| Per-object ordering | `TSRecv` | acclient.h:30162 |

---

## 2. Transport: the 20-byte `ProtoHeader`

```
seqID_(u32) header_(u32) checksum_(u32) recID_(u16) interval_(u16) datalen_(u16) iteration_(u16)
```

(acclient.h:34520–34528.)

Every datagram is `header || optional-headers || blob-fragments`
(`SharedNet::SendPacket`, acclient.c:369221). Sending is scatter-gather over
**91** `WSABUF`s (acclient.c:369243) = 1 header + `specialFragList_[32]` +
2 × `fragList_[29]` (acclient.h:34502, 34505), flattened and `sendto`'d in
`SharedNet::SendBuff` (acclient.c:369140).

**Wire transport flags**: `header_ & 1` retransmission; `header_ & 2` sequenced
with encrypted checksum — at acclient.c:370662–370663 this requires a nonzero
`seqID_` and must agree with `(flags_ >> 2) & 1`; `header_ & 4` blob fragments
follow (acclient.c:370621).

The enum at acclient.h:4798 (`npfChecksumEncrypted 0x1` …) describes
`NetPacket::flags_`, an **in-memory** field. The values do not correspond to the
wire byte.

### Optional headers

From the `COptionalHeaderAllocatorTemplate<MASK, T>` instantiations. Flag values
decode against `OptionalHeaderFlags` (acclient.h:4807–4817).

| Mask | Header | Notes |
|---|---|---|
| `0x100` | ServerSwitch | `COnePrimHeader<256, 96, CServerSwitchStruct>` |
| `0x200` | LogonServerAddr | `sockaddr_in`, flags 7 |
| `0x400` | *unnamed empty* | `CEmptyHeader<1024,7>` (acclient.h:59679), registered acclient.c:801023–801024, **never sent or handled** |
| `0x800` | **Referral** | `CReferralStruct`, flags `0x40000062` = signed \| countsAsTouch \| highPriority \| exclusive (acclient.h:41949) |
| `0x1000` | NAK list | `CSeqIDListHeader<4096,33>`, `m_IDs[115]`, flags `0x21` |
| `0x2000` | EmptyAck list | `CSeqIDListHeader<8192,33>` |
| `0x4000` | PAK / highest-received | `COnePrimHeader<16384,1,u32>`, flags 1 |
| `0x8000` | *unnamed empty* | `CEmptyHeader<32768,3>` (acclient.h:57896), registered acclient.c:801015–801016, **never sent or handled** |
| `0x10000` | **LogonHeader** | |
| `0x20000` | WorldLoginRequest | `u64` cookie, flags 7 |
| `0x40000` | **ConnectRequest** | `CConnectHeader` |
| `0x80000` | **ConnectResponse** | `u64`, flags `0x20000007` = encrypted \| notConn \| exclusive \| disposable (acclient.h:57907) |
| `0x100000` | NetError | `CPackObjHeader<NetError,…,7>` |
| `0x200000` | NetError-Disconnect | `CPackObjHeader<…,2>` — **this is the actual wire disconnect signal**, handled at acclient.c:370725 and 372714 |
| `0x400000` | ICMD | `CICMDCommandStruct{Cmd, Param}` |
| `0x1000000` | TimeSync | `long double` |
| `0x2000000` / `0x4000000` | EchoRequest / EchoResponse | |
| `0x8000000` | Flow | `CFlowStruct`, flags `ohfShouldPiggyBack` (`0x10`) |

Neither `0x400` nor `0x8000` appears in `SharedNet::ProcessOptionalHeader`
(acclient.c:370711) or `ClientNet::ProcessOptionalHeader` (372696), and neither
has a send site — `CEmptyHeader` occurs only in its two `CreateFromStream` bodies
(468686, 468710) and the two registrations. **Earlier drafts named `0x8000`
"Disconnect"; that name is not supported by anything in the binary.** Both are
simply unnamed payload-less headers.

`CConnectHeader` payload is `{ServerTime, qwCookie, NetID, OutgoingSeed,
IncomingSeed}` (acclient.h:41924–41931).
`COptionalHeaderFactory::AddOptionalHeadersToPacket` is at acclient.c:468137.

### Checksum — the `0xBADD70DD` scheme

`PortalChecksum::CalcChecksum32` is at **acclient.c:629839** (an earlier draft
cited 369852, which is unrelated code inside `CLinkStatusAverages`). It is a
32-bit word sum seeded with `size << 16`, and the trailing-byte loop at
**629856–629857** is:

```c
for ( j = 3; i < &data[size]; v6 += v8 ) v8 = *i++ << 8 * j--;
```

so the first leftover byte shifts `<< 24`, the second `<< 16`, the third `<< 8`.

`SharedNet::ChecksumHeader` (acclient.c:369083) copies the header, substitutes
the magic at acclient.c:369102, and sums 0x14 bytes at 369103:

```c
mutableHeader.checksum_ = -1159892771;   /* 0xBADD70DD */
```

Send adds (`checksum_ += ChecksumHeader`, acclient.c:369247); receive subtracts
(acclient.c:369987), leaving the payload checksum for comparison against
`NetPacket::ComputeChecksum` (acclient.c:376684). Note that function sums the
`specialFragList_` entries — which is where optional headers live — so "sums each
optional header's data" is true but goes through the fragment list, not a
separate array.

### Obfuscation — ISAAC-keyed XOR

`CryptoSystem` (acclient.h:34592) wraps `QTIsaac<8, unsigned long>`, and the
constructor passes **the same 32-bit seed as all three ISAAC init words**
(acclient.c:630174).

**Only the 4-byte checksum is ever encrypted.** `ReceiverData::Encrypt` /
`Decrypt` has exactly three call sites, all with length 4: acclient.c:372062
(receive path decrypt), 374446 (`FlowQueue::EncryptChecksum`), and **375159**
(the send path in `FlowQueue::TransmitData`). No other `CryptoSystem::EncryptData`
caller exists. Payloads are plaintext.

The AVL `m_SeqIDsWeNAKed` stores each packet's **crypto key** alongside its
seqID, so a retransmit decrypts with the original key rather than the next word
of the stream (acclient.c:372090–372100) — that is what keeps the ISAAC streams
synchronized across loss.

A Diffie-Hellman `PortalDH` / `NetKeyExch` (acclient.h:34600) is instantiated per
connection, but the shared secret is not used for bulk encryption.

### Sequencing, NAK, retransmit

`SeqIDSanityCheck` (acclient.c:371343) rejects seqIDs beyond
`highestIDReceived_ + 0x7FFF` (371354) or any at all while
`m_SeqIDsWeNAKed._currNum > 0x9C40` (40000, at 371368).

`EnqueueNaks` (acclient.c:371447) is throttled to more than **0.6 s** (371458);
`EnqueuePak` (371404) to at least **2.0 s** (371414).

`FlowQueue::TransmitAcks` (acclient.c:375785) resends with `header_ = 3` — or `7`
with fragments — reusing the original `seqID_`. The crypto key is *not* a wire
field; the already-encrypted `checksum_` is simply resent as-is.

---

## 3. Fragmentation, reassembly, and dedup

`NetBlob::Fragmentize` (acclient.c:377373) splits into **448-byte (`0x1C0`)**
chunks. Each `BlobFrag` prepends a 16-byte
`BlobFragHeader_t{u64 blobID; u16 numFrags; u16 blobFragSize; u16 blobNum;
u16 queueID}` (acclient.h:33210–33217). Validity is
`0x10 ≤ blobFragSize ≤ 0x1D0` (acclient.c:377029), so the maximum on-wire
fragment is 464 bytes.

`blobID` bit assignments: bit 63 ephemeral (acclient.c:467810); bits 56–60
ordering type, mask `0x1F00000000000000` (467816); bits 32–47 the ordering stamp
(467860–467873); sequence mask `0x00FF0000FFFFFFFF` (467822). The bits-48–55
"server ID" reading follows from the `0x00FF0000` half of that mask —
`MakeInitialSequenceID` (467831) and `MakeNetBlobID` (467837) both decompile
degenerately and do **not** independently establish it. Treat it as inference.

`Proto_UI::SendBlob` (acclient.c:373866, 373868) stamps `0x23000000` or
`0x03000000`, chosen by queue: **queues 4, 5, and 8** get `0x23……` and go to the
logon receiver; everything else gets `0x03……` and goes to the current server
(acclient.c:373859). The field names `logonRecID_` / `currServerRecID_` are
inferred from the `receivers_[452]` / `[454]` offsets against the `ClientNet`
layout (acclient.h:35170–35171); they are not literally in the decompilation.

### The `Indicator` engine

Every `RecipientData` allocates an `Indicator` (acclient.h:34900, allocated
acclient.c:374320). `SharedNet::ProcessBlobFrags` (369136) →
`RecipientData::IndicateReceivedPacket` (374258) → `Indicator::CheckInPacket`
(378133), which walks `fragList_` (378143), filters through
`FragIsObsoleteEmphemeral` (378148), and calls `Indicator::AcceptFrag` (378149).

`AcceptFrag` (acclient.c:378023) keys a `UI64Hash<NetBlob> waitingBlobs_` (128
buckets, `key_shift = 16`, acclient.c:377785–377787) by blobID — or, for
ephemeral blobs, by sequence ID with the stamp masked out. When
`numFragments_ == cMaxFragments_` (378100) the blob goes to
`Indicator::SendBlobToQueue` (377751), which restores `id` from
`savedNetBlobID_` (377756) and pushes into `PacketController::netQueues_[queueID]`.
State 3 is set in `ReceiveBlobReady` (377238).

**A correction, and an open question.** An earlier draft of this report said the
half-assembled blob is destroyed and replaced when a *newer* stamp arrives. The
cited line does not say that. acclient.c:378070 reads:

```c
if ( !NetBlobIDUtils::LHSNewerOrderingStamp(__PAIR__(v13, v12), v11) ) return;
```

where `v12`/`v13` is the **stored** blob's `savedNetBlobID_` (NetBlob offsets
72/76, acclient.h:29478) and `v11` is the **incoming** fragment's blobID.
`LHSNewerOrderingStamp` (467854) returns true iff the left-hand side is newer. So
as decompiled, the replace happens when the **stored** blob is newer and the
function **returns when the incoming stamp is newer** — the opposite of the
intuitive behaviour.

This reading is stable across all three decompilations (6.95 at 374121; the 2015
11.6096 build at 377996). The two neighbouring call sites are argument-order
coherent with it (`FragIsObsoleteEmphemeral` 377925 passes `(stored, incoming)`;
`SentPacketStore::AddSentPacket` 378435 passes `(incoming, stored)`), which argues
the decompilation is faithful and this is a genuine latent inversion in Turbine's
code. **Either way, do not state the intuitive behaviour as fact** — the cited
line does not support it.

`Indicator::FragIsObsoleteEmphemeral` (acclient.c:377897) is the dedup filter for
ephemeral traffic. It keeps an `ArrivedEphInfo : UI64HashData
{m_next; m_latestNetBlobID; m_timeStamp}` (acclient.h:34932) per sequence ID and
drops fragments whose stamp is **older** — an equal stamp falls through to
`ArrivedEphInfo::UpdateNetBlobID` (377927). This is how stale position and vector
updates are discarded before reassembly begins. Entries are collected by
`FlushTimedOutEphInfo`, rate-limited to once every **5.0 s** (acclient.c:377868),
driven from `RecipientData::UseTime` (374277 → 374292).

### Reassembly

`NetBlob::ReceiveAddFragment` (acclient.c:377185–377232) allocates
`448 * numFrags` on first sight — or the exact size if the first fragment seen is
the last — then memcpys later fragments to `buf_ + 448*blobNum`, fixing the final
size to `448*(numFrags−1) + blobFragSize − 16` when the tail arrives.

### Queues

`PacketController::AddReceivedBlobToQueue` (acclient.c:368777) rejects
`queueID >= 0xC` **or `queueID == 0`**.

`Client::AddNetQueue` is called for **2, 10, 9, 4, 5 only**
(acclient.c:77854–77858) and has no other call site in the binary:

| Queue | Purpose |
|---|---|
| 2 | Control |
| 4 | Logon (`m_logonEventQueue`, acclient.c:77860) — also carries Turbine Chat |
| 5 | Database / DAT, i.e. DDD (`CLCache::SetNetQueue`, acclient.c:78802) |
| 9 | UI events (`UIQueueManager`) |
| 10 | SmartBox / physics |

**Queue 3 is outbound only** — `Proto_UI::SendToWeenie` constructs
`NetBlob(buf, size, 3)` (acclient.c:373919), but no receive queue 3 is
registered.

### Per-object ordering

`TSRecv` (acclient.h:30162) is embedded in every `CWeenieObject` as
`blobOrdering` (acclient.h:30256). `TSRecvMode` (acclient.h:3099) is
`TSRECV_BLOCK` (hold out-of-order blobs in a `TSBlockedEntry` chain) or
`TSRECV_LATESTONLY`. The implementation runs acclient.c:474603–474885
(`AddAndCheck` starts at 474865). `CWeenieObject::fIsNextBlob`
(acclient.c:310957) is the call site used by `HandleOrderingForBlob`. **There is
no `TSSend`** anywhere in either decompilation.

---

## 3b. Independent corroboration of the opcode assignments

The opcode identifications in §4 and §8 were derived here from the binary alone.
They have since been checked against the community protocol reference at
`github.com/ACClientLib/ACProtocol`, which is an independent reconstruction. All
of the following agree exactly:

| Opcode | This report | Reference |
|---|---|---|
| `0xF619` | PositionAndMovementEvent | `S2CMessage.Movement_PositionAndMovementEvent` |
| `0xF625` | ObjDescEvent | `S2CMessage.Item_ObjDescEvent` |
| `0xF745` | CreateObject | `S2CMessage.Item_CreateObject` |
| `0xF7DE` | Turbine Chat, tunnelled over the game link | `C2SMessage.Communication_TurbineChat` **and** `S2CMessage.Communication_TurbineChat` |
| `0xF7E0` | TextboxString | `S2CMessage.Communication_TextboxString` |
| `0x2EB` | transient string handler | `GameEvent.Communication_TransientString` |
| `0x04` | pop-up string handler | `GameEvent.Communication_PopUpString` |
| `0x147` | ChannelBroadcast | `GameEvent.Communication_ChannelBroadcast` |
| `0x561` | friend-list-full error | `WeenieError.MaxFriendsExceeded` |

The `0xF7DE` entry is worth singling out. An early draft of this report claimed
Turbine Chat used a separate TCP service; §8 corrected that to a tunnel over the
normal UDP link. The reference listing the same opcode in **both** the
client-to-server and server-to-client message enums is exactly what a tunnelled
bidirectional channel looks like, and settles the point.

> **Caveat when using that reference.** Its `Property*` enums write values with
> an `0x` prefix but **decimal digits** — `value="0x390"` means property 390,
> i.e. `0x186`. Its `Command`, `GameEvent`, `S2CMessage` and `WeenieError` enums
> are genuine hex. The opcodes in the table above are from the hex enums and need
> no conversion.

## 4. Message dispatch

Two switches, both reading a 4-byte opcode at the front of the blob.

### Physics / SmartBox, queue 10

`ACSmartBox::DispatchSmartBoxEvent` (acclient.c:392692). The switch is written as
`v9 = v7 - 63001`, so cases are offsets from `0xF619`:

| Opcode | Message |
|---|---|
| `0xF619` | **PositionAndMovementEvent** — `UnpackPositionEvent` + `CPhysics::SetObjectMovement` (acclient.c:392762) |
| `0xF625` | **ObjDescEvent** — offset 12 (acclient.c:392765–392766) |
| `0xF745`–`0xF74B` | CreateObject, CreatePlayer, DeleteObject, Position, ParentEvent, PickupEvent, SetState |
| `0xF74C` | MovementEvent (raw) |
| `0xF74E` | VectorUpdate |
| `0xF750` | SoundEvent |
| `0xF751` | PlayerTeleport |
| `0xF754` / `0xF755` | PlayScriptID / PlayScriptType |
| `0xF7DB` | UpdateObject |

`IsReadyToDispatchEvent` (acclient.c:392672) gates everything except `0xF746`
until `player_id` is set.

### UI / game, queue 9

`UIQueueManager::ProcessNetBlobData` (acclient.c:394441) — **168 opcodes**.
Envelopes are stripped first: `WOrderHdr::UnPack` (acclient.c:713868) expects
`0xF7B0` plus `iid_` and `stamp_` (12 bytes); `OrderHdr::UnPack` (716801) expects
`0xF7B1` plus `stamp_` (8 bytes). `HandleOrderingForBlob` (395454) routes.

| Opcode | Message |
|---|---|
| `0x03` | AllegianceUpdateAborted |
| `0x04` | PopUpString |
| `0x13` | PlayerDescription — fires `Handle_PlayerDescription`, `CrucialOrderedEventsReceived`, **and** `OnBeginCharacterSession` |
| `0x20` | AllegianceProfile |
| `0x21` | FriendsUpdate |
| `0x22` | ServerSaysMoveItem (falls back to `ServerSaysContainID` when the object isn't resident) |
| `0x23` | wield / equip — `ServerSaysMoveItem(obj, 0, 0, playerID, slot, 1)` |
| `0x24` | Remove |
| `0x29` | CharacterTitleTable |
| `0x2B` | AddOrSetCharacterTitle |
| `0x52` | StopViewingObjectContents |
| `0x62` | VendorInfo |
| `0x75` | StartBarber |
| `0xA0` | ServerSaysAttemptFailed |
| `0xA3` / `0xA4` | Fellowship Quit / Dismiss |
| `0xB4`, `0xB6`, `0xB7`, `0xB8` | book open / add page / delete page / page data |
| `0xC3` | three-string message, parsed and discarded |
| `0xC9` | AppraisalProfile |
| `0x147` / `0x148` / `0x149` | Channel Broadcast / List / Index |
| `0x196` | ContentProfile list |
| `0x197` | UpdateStackSize |
| `0x19A` | ServerSaysMoveItem |
| `0x19E` | PlayerDeath |
| `0x1A7` | AttackDone |
| `0x1A8` | RemoveSpell |
| `0x1AC` / `0x1AD` | VictimNotification |
| `0x1B1` / `0x1B2` | Attacker / Defender Notification |
| `0x1B3` / `0x1B4` | Evasion notifications |
| `0x1B8` | CommenceAttack |
| `0x1C0` | QueryHealthResponse |
| `0x1C3` | QueryAgeResponse |
| `0x1C7` | UseDone |
| `0x1C9` / `0x1CA` | FellowUpdateDone / FellowStatsDone |
| `0x1CB` | AppraiseDone |
| `0x1D1`–`0x1DE` | Remove{Int,Bool,Float,String,DID,IID,Position}; odd codes are the Private variants |
| `0x1E0` / `0x1E2` | HearEmote / HearSoulEmote |
| `0x1EA` | ReturnPing |
| `0x1F4` | SetSquelchDB |
| `0x1FD`, `0x1FE`, `0x1FF`, `0x200`, `0x201`, `0x202`, `0x203`, `0x205`, `0x207`, `0x208` | Trade: Register, Open, Close, AddTo, RemoveFrom, Accept, Decline, Reset, Failure, ClearAcceptance. **`0x204` and `0x206` have no case** |
| `0x21D`, `0x225`–`0x228`, `0x248`, `0x257`, `0x259`, `0x271` | House profile / data / status / rent / restrictions / HAR / transaction / available |
| `0x264` | QueryItemManaResponse |
| `0x274` / `0x276` | Confirmation request / done |
| `0x27A` / `0x27C` | Allegiance login-notify / info-response |
| `0x281`–`0x285`, `0x28C` | MiniGame. **`0x286`–`0x289` do not exist** |
| `0x28A` / `0x28B` | WeenieError / WeenieErrorWithString |
| `0x295` | ChatRoomTracker |
| `0x2AE`, `0x2B1`, `0x2B3` | plugin query |
| `0x2B4` | SalvageResults |
| `0x2B8` / `0x2B9` | RemoveInt64 |
| `0x2BB`–`0x2BD` | HearSpeech / HearRangedSpeech / HearDirectSpeech |
| `0x2BE`–`0x2C0` | Fellowship full-update / disband / update-fellow |
| `0x2C1`–`0x2C8` | enchantment update / remove / purge / dispel |
| `0x2C9`–`0x2CC` | portal storm |
| `0x2CD`–`0x2EA` | Update{Int,Int64,Bool,Float,DID,IID,Position,Skill,Attribute,…} → `CM_Qualities`, **except** `0x2D5` / `0x2D6`, which are Private/Public **string** updates handled by `UIQueueManager::HandleStringUpdateEvents` |
| `0x2D3` / `0x2D4` | Private / Public UpdateFloat |
| `0x2EB` | TransientString |
| `0x312` | PurgeBadEnchantments |
| `0x314` / `0x315` | contract trackers |
| `0xEA60` (60000) | `CM_Admin::DispatchUI_Environs` |

Direct messages: `0xF630` rent, `0xF643` CharGenVerificationResponse, `0xF651`
SubscriptionExpiration, `0xF653` LogOff, `0xF655` CharacterDelete, `0xF658`
CharacterSet, `0xF659` CharacterError, `0xF7C1` AccountBanned, `0xF7CA` /
`0xF7CB` admin data, `0xF7DC` AccountBooted, `0xF7DF` EnterGame_ServerReady,
`0xF7E0` TextboxString, `0xF7E1` WorldInfo.

---

## 5. Outbound messages

Every `CM_*::Event_*` is a GameAction: `OrderHdr::Pack` (acclient.c:716785)
writes `0xF7B1` plus `stamp_ = Proto_UI::GetNextUICounter()`, then the opcode,
then arguments, then `Proto_UI::SendToWeenie` on queue 3. A failed send calls
`Proto_UI::UICounterFailedSend` (373892), which has exactly **157** call sites —
one per event.

**`0xF7B0` is inbound-only.** `WOrderHdr::Pack` exists (713848) but has zero
callers.

All 157 outbound opcodes were extracted mechanically and cross-read in the third
pass; the table below is complete for the groups shown.

| Group | Opcodes |
|---|---|
| Combat | `0x08` TargetedMelee, `0x0A` TargetedMissile, `0x53` ChangeCombatMode, `0x1B7` CancelAttack, `0x1BF` QueryHealth |
| Magic | `0x48` CastUntargeted, `0x4A` CastTargeted, `0x1A8` RemoveSpell |
| Inventory | `0x19` PutItemInContainer, `0x1A` GetAndWield, `0x1B` Drop, `0x35`/`0x36` UseWithTarget/Use, `0x54`–`0x56` stack merge/split, `0xCD` Give, `0x195` NoLongerViewingContents, `0x19B` SplitToWield, `0x27D` CreateTinkeringTool |
| Character | `0xA1` LoginCompleteNotification, `0x05` PlayerOptionChanged, `0x1A1` CharacterOptions, `0x1E9` RequestPing, `0x275` ConfirmationResponse, `0x63`/`0x26`/`0x27`/`0x28D` teleport to lifestone / **PKL arena** / **PK arena** / marketplace, `0x278` TeleToMansion, `0x279` Suicide, `0x311` FinishBarber |
| Communication | `0x15` Talk, `0x32` TalkDirect, `0x5D` TalkDirectByName, `0x1DF`/`0x1E1` Emote/SoulEmote, `0x145`–`0x149` channel ops, `0x58`/`0x59`/`0x5B` squelch |
| Trade | `0x1F6` Open, `0x1F7` Close, `0x1F8` AddTo, `0x1FA` Accept, `0x1FB` Decline, `0x204` Reset |
| House | `0x21C` Buy, `0x21E` Query, `0x21F` Abandon, `0x221` Rent, `0x245`/`0x246` guest add/remove, `0x249` storage permission, `0x24A` boot guest, `0x24D` full guest list, `0x262` teleport, `0x270` ListAvailableHouses |
| Allegiance | `0x1D` Swear, `0x1E` Break, `0x1F` UpdateRequest, `0x33` SetName, `0x3B` officer, `0x3F` lock action, `0x254`–`0x256` MOTD, `0x2A0` ChatBoot, `0x2A1`–`0x2A3` bans, `0x2A6`/`0x2A7` list/clear officers, `0x2AB` RecallHometown |
| Fellowship | `0xA2` Create, `0xA3` Quit, `0xA4` Dismiss, `0xA5` Recruit, `0xA6` UpdateRequest, `0x290` AssignNewLeader, `0x291` ChangeOpenness |
| Item / social / vendor / train | `0xC8` Appraise, `0x263` QueryItemMana, `0xAA`–`0xAE` book ops, `0xBF` SetInscription, `0x17`/`0x18` friend remove/add, `0x2C` SetDisplayTitle, `0x316` AbandonContract, `0x5F`/`0x60` Buy/Sell, `0x44`–`0x47` training |
| Advocate | `0xD6` `CM_Advocate::Event_Teleport` |
| Movement (still `0xF7B1`-wrapped) | `0xF61B` Jump, `0xF61C` MoveToState, `0xF61E` DoMovementCommand, `0xF649` TurnTo, `0xF661` StopMovementCommand, `0xF752` AutonomyLevel, `0xF753` AutonomousPosition, `0xF7C9` Jump_NonAutonomous |

`Proto_UI` direct sends bypass the wrapper and the UI counter entirely
(acclient.c:374042–374250), and all nine were verified for both opcode and queue:
`0xF6EA` ForceObjdesc (q2), `0xF7C8` EnterWorldRequest (q4), `0xF653`
LogOffCharacter (q4), `0xF7CC` AdminGetServerVersion (q2), `0xF656`
SendCharGenResult (q4), `0xF655` DeleteCharacter (q4), `0xF657` EnterWorld (q4),
`0xF7CD` FriendsCommand (q2), `0xF7D9` AdminRestoreCharacter (q2).

---

## 6. Serialization

Everything derives from `PackObj` (acclient.h:26018) with virtual `GetPackSize` /
`Pack` / `UnPack`.

`AC1Legacy::PStringBase<char>::Pack` (acclient.c:296374): `u16` length — or
`0xFFFF` then a `u32` length when ≥ 0xFFFF — then bytes, then `ALIGN_PTR` to 4.

`PackableList<T>::UnPack` (acclient.c:394384) is a `u32` count then N elements.

`PackableHashTable<K,V>::UnPack` (acclient.c:297966–297977) packs the bucket
count in the high 16 bits and the element count in the low 16 of one `u32`. Both
are then checked against `0x10000` — a **dead check**, since a `u32 >> 16` and a
`u16` are ≤ 0xFFFF by construction.

`InArchiveVersionStack` (acclient.h:43833) belongs to the DBObj/DAT layer, not the
packet path.

---

## 7. Login, world entry, timeouts

### Authentication

`NetAuthenticator::m_dwAuthType` takes three values, from exactly three
`SetToAuthType` sites: **1** plain account (acclient.c:77293), **2** account plus
VG password (62594), **`0x40000002`** GLS ticket (62606).

`m_dwAuthFlags` is only ever written as 0 (acclient.c:367957). The read side for
bit `0x2`, which would append `m_AccountToLogonAs`, is at **acclient.c:368108** —
a server or GM feature.

The GLS ticket is read from `HKCU\Software\Turbine\ac1\GLSTicket` and then
deleted (acclient.c:62376–62410).

`CLogonHeader`'s body is `PString ClientVersion || u32 cbAuthData ||
NetAuthenticator`. The version string **"1802"** is a hardcoded stack literal at
acclient.c:371686 — its only occurrence — inside `SendLoginRequest`
(body starts 371662).

### Handshake

The logon packet goes out with seqID 0, recID 0, iteration 0, `header_ = 0x10000`
(acclient.c:371698–371710).

`ClientNet::HandleConnectionRequest` (acclient.c:373221) allocates a `NetKeyExch`
(373271), calls `ReceiverData::Init` with both ISAAC seeds (373287–373297),
registers the recipient (373303), and sets state 4 (373326).
`SendConnectAck` (body 371729) echoes the cookie in a `0x80000` header
(371767–371770) to **port + 1**, computed explicitly at 371756–371757:

```c
v6 = ntohs(sin_port);  v7 = htons(v6 + 1);
```

`ConnectionState` (acclient.h:4877) runs `cs_Disconnected 0` to
`cs_DisconnectSent 7`. There are exactly five `SetConnectionState` sites (370725,
372673, 372875, 372920, 373326). The client only ever sets 0 → 4 → 5 → 6/7;
**states 1, 2, and 3** (`cs_AwaitingWorldAuth`, `cs_AuthSent`,
`cs_ConnectionRequestSent`) are never set client-side. State 6 is reached both
from the 140-second rule and directly from a `0x200000` NetError-Disconnect
header (370725).

`CClientsideLoginStateHandler` (acclient.h:35114) is **not** a multi-state
machine: state number 0 with exactly one handler (acclient.c:373667, 373693). Its
four context slots are `"RecipientID"`, `"ServerAddr"`, `"NetAuthenticator"`,
`"FailureReason"` (372013).

`CharacterSet` (`0xF658`) unpacks at acclient.c:298510; the handler
`Handle_Login__CharacterSet` starts at **397781**. A `numAllowedCharacters_` of
−1 is remapped to **20** (397823–397824); the pre-unpack default is 5 (397805);
`m_accountHasThroneofDestiny` is hardcoded to 1 at **397850**.

### World entry

`0xF7C8` EnterWorldRequest → `0xF7DF` EnterGame_ServerReady → `0xF657`
EnterWorld → `0xF7E1` WorldInfo → `0x13` PlayerDescription → `0xA1`
LoginCompleteNotification.

`CPlayerSystem` applies **a** 110-second watchdog on that sequence
(acclient.c:400549) before raising `ECM_Login::SendNotice_ServerDied` — but it is
not the only path. A second, independent check immediately follows
(400555–400562): sampled every 4 seconds, firing on link-status delay above 40.0
or `!bNetConnected`.

### Timeouts and auto-reconnect

`ClientNet::ProcessConnection` (acclient.c:372842):

- **state 4** — re-sends `SendConnectAck` every **0.333 s**.
- **state 5** — every **2.0 s**, snapshots `CLinkStatusSnapshot`, feeds
  `CLinkStatusAverages`, and fires `NotifyPluginsOfHeartbeat`. Note this block
  additionally requires `pReceiver->m_RecID == currServerRecID_` (372879), **so
  the logon connection never heartbeats.** States 5 and 6 then both fall through
  to the NAK/PAK alternation.
- **state 6** → `cs_DisconnectSent` if the recipient is gone or already at 7.
- **state 7** → `RemoveConnection`.

**The 140-second rule** (acclient.c:372914) requires *both* that the client has
been ticking and that data has stopped:

```c
if ( Timer::cur_time - v2->lastDidUseTime_ < 140.0
  && Timer::local_time - pReceiver->m_LocalTimeLastGotData > 140.0 )
```

Any state below 6 is then forced to `cs_DisconnectReceived`. If the dying state
was 5 **and** `m_qwReferralCookie` is non-zero **and** `logOffSent_` is false, the
client synthesises a `CReferralStruct` from the dead receiver's own address,
`idServer = m_RecID`, and cookie, and re-enqueues it as a `0x800` referral. **A
dropped world link auto-reconnects through the normal referral path.**

Login-side: `ClientNet::LogonUseTime` (acclient.c:372262) resends every 2.0 s,
at most **20** times, ending with `ID_ConnectionError_ClientTimedOutServer`.
`ProcessReferralQueue` (371792) retries at 0.333 s intervals with a cap of
`280.0 / 0.333333333` **attempts** (371830) — roughly 840 tries, equal to 280
seconds only because of the interval.

`ClientNet::ExitWorldDisconnect` (acclient.c:369394) tears down non-logon
receivers. Note the `m_WorldSwitchHistory` reset (369424) and
`Proto_UI::SetEventCounter(0)` (369425) are **inside `if (connectionsHead_)`** —
if no connection survives, neither runs and `logonRecID_` is zeroed instead. So
"the ordered-event stamp restarts on every world entry" holds only on the path
where a connection remains.

`gmDisconnectedUI` (acclient.c:279104) is UI mode `0x10000002`. No
`QueueUIMode(0x10000002)` call exists anywhere; entry appears to go through
`QueueUIModeWithError` (182431). **The exact entry mechanism is unconfirmed.**
The net layer's own outputs are `NetStatus` plugin notifications
(`Net_LoginConnectionError = 4`, `Net_WorldConnectionError = 5`,
acclient.h:3996).

---

## 8. Turbine Chat tunnels over the game link

**There is no TCP anywhere in this binary.** The only `socket()` call is
`socket(2, 2, 0)` — AF_INET, SOCK_DGRAM — at acclient.c:372478, with zero hits
for `connect(`, `listen(`, `accept(`, `WSAConnect`, `WSASocket`, or
`SOCK_STREAM`; only `sendto` (369190) and `recvfrom` (369964). Confirmed
identically in the 6.95 decompilation (368631) and the 2015 11.6096 build
(372510).

(Note the enum `{fe_tcp, be_tcp, fe_udp}` at acclient.h:4871–4873 — a
configuration enum with no TCP code behind it.)

`CCommunicationSystem` (acclient.h:41458) holds
`m_TurbineChatDllName = "chatclient.dll"` (acclient.c:389823).
`AC1ClientChatManager::Init` (390001) does `LoadLibraryA` plus
`GetProcAddress("CreateChatClient")` (390039), handing the DLL a
`ChatInterfaceProvider`.

Egress is `ChatInterfaceProvider::SendData` (acclient.c:389622) →
`CChatEvent::CreateForSend` (389577), which writes `63454` (`0xF7DE`) at offset
0, the data length at offset 4, the payload at +8, and sets `queueID_ = 4`.

Ingress is `Client::ProcessLogonEventQueue` (acclient.c:77662): pop, require
`bufSize_ >= 4`, test `*(u32*)buf == 63454`, then hand `buf + 8` with the length
from `buf + 4` to the `IChatClient`.

So `CChatEvent : CCliDatEvent : NetBlob` — the same wrapper the DAT layer uses on
queue 5, discriminated only by the leading opcode.

The only credential is the account name, enabled by `m_fUseTurbineChat` inside
`CharacterSet`. Room IDs arrive via opcode `0x295` ChatRoomTracker — ten u32s
(acclient.h:40716). Tells, fellowship chat, and local speech are **not** on
Turbine Chat.

---

## 9. The DDD data-patching protocol (queue 5)

`CLCache::UseTime` (acclient.c:295962) pops **one** blob per call from
`netQueues_[5]` and switches on the leading dword (296013):

| Opcode | Message | Direction |
|---|---|---|
| `0xF7E2` | `DDD_DataMessage` | S→C |
| `0xF7E3` | `DDD_RequestDataMessage` | C→S (sent 291479) |
| `0xF7E4` | `DDD_ErrorMessage` | S→C |
| `0xF7E5` | `DDD_InterrogationMessage` | S→C |
| `0xF7E6` | `DDD_InterrogationResponseMessage` | C→S (sent 293802) |
| `0xF7E7` | `DDD_BeginDDDMessage` | S→C |
| `0xF7EA` | `DDD_EndDDDMessage` | both (recv 296074; sent 294091, 294120, 294336) |
| `0xF7EB` | `DDD_PatchPendingMessage` | S→C |

`0xF7E8` and `0xF7E9` have no constant anywhere. Two orphan PDB types
(`DDD_BeginPullDDDMessage`, `DDD_IterationDataMessage`) are the only unassigned
candidates, but the binary does not prove the association.

**Handshake.** `CLCache::OnServerInterrogation` (acclient.c:293755) mounts
highres if `productID & 4`, sets the region, and answers with
`DDD_InterrogationResponseMessage`. **Two of its four fields are populated:
`m_ItersWithKeys` (293818) and `m_ClientLanguage` (293826, from
`DBCache::GetLocalLanguage()`)**; `m_ItersWithoutKeys` is constructed empty and
`m_dwFlags` is hardcoded 0.

`CAllIterationList` (acclient.h:47759, entry struct 47772) is a
`SmartArray<PTaggedIterationList>` of `{u64 idDatFile; CMostlyConsecutiveIntSet}`
— a run-length-compressed set of held iteration numbers per DAT file.

**Transfer.** The server replies `DDD_BeginDDDMessage{cbDataExpected,
SmartArray<MissingIteration>}` (acclient.h:29216). `OnBeginDDD` (293230) queues a
`CAsyncBeginDDDRequest` that purges first. Each `DDD_DataMessage` becomes a
`CAsyncSaveRequest` with `dwDiskControllerSaveFlags = bCompressed ? 12 : 1`, and
`ThreadedCache::WorkerExecuteSaveRequest` (654057) writes it into the real .dat.

The four patchable slots are indexed by `CLCache::DatFileIndex`
(acclient.h:3932): **Portal = 0, Local = 1, Cell = 2, HighRes = 3**
(bounds-checked at 290957; array grown at 293453).

**At runtime**, `CLCache::AsyncGetFromOtherSources` (291467) turns a cache miss
into a `DDD_RequestDataMessage`.

**Progress UI** is `gmDataPatchUI::OnDDDEvent` (282670). The `DDDEvent` enum
(acclient.h:3555) has **eight** members; only `DDD_RegionSet(1)`,
`DDD_PatchtimePending(2)`, `DDD_PatchtimeBegin(3)`, `DDD_PatchtimeEnd(4)`, and
`DDD_DataDownloaded(5)` are ever raised —
`DDD_PatchtimeInterrogation(0)`, `DDD_DynamicDataRequested(6)`, and
`DDD_DataError(7)` exist but are dead.

`Client::OnDDDEvent` (acclient.c:77633) acts only on `PatchtimeEnd`, where it
flushes the language interface, drops the master property list, runs
`DBCache::FlushFreeObjects(0)` three times, then calls
`CLanguageInfoInterface::Startup()` (77651) and `SmartBox::SetRegion(...)`
(77656).

---

## 10. Anti-tamper, and traps

There is **exactly one** client-side check in the binary.
`ClientNet::HandleTimeSynch` (acclient.c:371516–371554) sets local time from the
server; if `srvtime + 60 < cur_time` continuously for 60 seconds it self-reports
a `0x100000` NetError with `ID_ConnectionError_RunningSpeedhack`. Any in-tolerance
sync resets the latch.

Headers carry `ohfEncrypted 0x20000000` and `ohfSigned 0x40000000`
(acclient.h:4816–4817), used for ConnectResponse and Referral, but the client
never verifies them.

### Traps

**Class names mislead.** `ClientCommunicationSystem` is chat.
`CCommunicationSystem` is a DLL shim. The socket lives in `SharedNet`.

**`CCliDatEvent` is shared** between DAT patching (queue 5) and Turbine Chat
(queue 4), discriminated only by the leading opcode.

**Switch bases are offsets.** The SmartBox dispatcher subtracts 63001 before
switching, so a "case 12" is opcode `0xF625`. Read the subtraction first.

**Argument order in `LHSNewerOrderingStamp`** is the trap that produced a wrong
claim in an earlier draft of this document — see §3.

**Citation drift.** `PortalChecksum::CalcChecksum32` is at 629839, not 369852; a
`62`→`36` transposition put an earlier draft's citation on unrelated code.
