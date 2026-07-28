# Source Index

795 files, 36,603 functions, reconstructed from `acclient.pdb` module records.

| Layer | Libraries | Files | Functions |
|---|---|---|---|
| `PORTAL` | 61 | 210 | 7,552 |
| `ENGINE` | 51 | 215 | 17,955 |
| `GAME` | 6 | 134 | 5,685 |
| `AC` | 37 | 135 | 3,345 |
| `CORE` | 16 | 45 | 711 |
| `_other` | 1 | 3 | 130 |
| `_runtime` | 4 | 53 | 1,225 |
| **total** | | **795** | **36,603** |

## `PORTAL`

Turbine's portable engine layer — physics, geometry, animation, DAT resources, sound, networking primitives.

### `PORTAL/acrender` — 1 files, 96 functions

| File | Functions | Address range |
|---|---|---|
| [`ACRender.c`](src/PORTAL/acrender/ACRender.c) | 96 | `006B61E0`–`00791910` |

### `PORTAL/acrenderdev` — 3 files, 380 functions

| File | Functions | Address range |
|---|---|---|
| [`ACRenderDevice.c`](src/PORTAL/acrenderdev/ACRenderDevice.c) | 156 | `0059EF70`–`00776200` |
| [`PView.c`](src/PORTAL/acrenderdev/PView.c) | 116 | `005A42E0`–`00776FA0` |
| [`ACRenderDeviceState.c`](src/PORTAL/acrenderdev/ACRenderDeviceState.c) | 108 | `005A2A90`–`00776840` |

### `PORTAL/canim` — 15 files, 543 functions

| File | Functions | Address range |
|---|---|---|
| [`CAnimHook.c`](src/PORTAL/canim/CAnimHook.c) | 116 | `004F70B0`–`007683E0` |
| [`CDegradeInfo.c`](src/PORTAL/canim/CDegradeInfo.c) | 78 | `0051E290`–`007680C0` |
| [`CMotionInterp.c`](src/PORTAL/canim/CMotionInterp.c) | 49 | `005279E0`–`006FDBC0` |
| [`CMoveToManager.c`](src/PORTAL/canim/CMoveToManager.c) | 43 | `00528F60`–`006FDCA0` |
| [`CSequence.c`](src/PORTAL/canim/CSequence.c) | 41 | `005247B0`–`007681F0` |
| [`CMInterpPrim.c`](src/PORTAL/canim/CMInterpPrim.c) | 33 | `0051E6E0`–`006FD4E0` |
| [`CMovementManager.c`](src/PORTAL/canim/CMovementManager.c) | 31 | `00524000`–`006FD760` |
| [`CMTable.c`](src/PORTAL/canim/CMTable.c) | 29 | `00502D80`–`006FD680` |
| [`CSetup.c`](src/PORTAL/canim/CSetup.c) | 25 | `0051FD20`–`006FD620` |
| [`CPhysicsScriptTable.c`](src/PORTAL/canim/CPhysicsScriptTable.c) | 21 | `00500EA0`–`006FD640` |
| [`CAnim.c`](src/PORTAL/canim/CAnim.c) | 19 | `0051F640`–`006FD520` |
| [`CSeqPrim.c`](src/PORTAL/canim/CSeqPrim.c) | 19 | `00525BE0`–`006FD860` |
| [`CMotionPrim.c`](src/PORTAL/canim/CMotionPrim.c) | 17 | `00525FD0`–`00526790` |
| [`CPhysicsScript.c`](src/PORTAL/canim/CPhysicsScript.c) | 12 | `00521600`–`006FD630` |
| [`CMovementDefs.c`](src/PORTAL/canim/CMovementDefs.c) | 10 | `0052A9A0`–`006FDD10` |

### `PORTAL/ccell` — 10 files, 540 functions

| File | Functions | Address range |
|---|---|---|
| [`CEnvCell.c`](src/PORTAL/ccell/CEnvCell.c) | 126 | `0052C0C0`–`00769250` |
| [`CObjCell.c`](src/PORTAL/ccell/CObjCell.c) | 125 | `005138C0`–`00768AA0` |
| [`CLandCell.c`](src/PORTAL/ccell/CLandCell.c) | 97 | `00532C70`–`00769B80` |
| [`CLandBlock.c`](src/PORTAL/ccell/CLandBlock.c) | 66 | `0052F050`–`00769500` |
| [`CLandBlockStruct.c`](src/PORTAL/ccell/CLandBlockStruct.c) | 29 | `00530E30`–`006FF040` |
| [`CCellStruct.c`](src/PORTAL/ccell/CCellStruct.c) | 24 | `00533870`–`006FF7B0` |
| [`CLandBlockInfo.c`](src/PORTAL/ccell/CLandBlockInfo.c) | 24 | `00526AA0`–`006FEC80` |
| [`CSortCell.c`](src/PORTAL/ccell/CSortCell.c) | 20 | `00533FB0`–`006FF890` |
| [`CPartCell.c`](src/PORTAL/ccell/CPartCell.c) | 16 | `0052E510`–`006FEB80` |
| [`CEnvironment.c`](src/PORTAL/ccell/CEnvironment.c) | 13 | `00530BF0`–`006FEF60` |

### `PORTAL/cchat` — 2 files, 32 functions

| File | Functions | Address range |
|---|---|---|
| [`CCommunicationSystem.c`](src/PORTAL/cchat/CCommunicationSystem.c) | 20 | `00556290`–`00707260` |
| [`AC1ClientChatManager.c`](src/PORTAL/cchat/AC1ClientChatManager.c) | 12 | `005567E0`–`007072D0` |

### `PORTAL/cdebug_client_errstrm_crap` — 1 files, 8 functions

| File | Functions | Address range |
|---|---|---|
| [`CErrStrm.c`](src/PORTAL/cdebug_client_errstrm_crap/CErrStrm.c) | 8 | `00554B80`–`007727D0` |

### `PORTAL/cfactory` — 1 files, 25 functions

| File | Functions | Address range |
|---|---|---|
| [`CFactory.c`](src/PORTAL/cfactory/CFactory.c) | 25 | `0054AE80`–`00705880` |

### `PORTAL/cgeometry` — 17 files, 536 functions

| File | Functions | Address range |
|---|---|---|
| [`CBSPNode.c`](src/PORTAL/cgeometry/CBSPNode.c) | 93 | `00487830`–`0076B070` |
| [`CBSPTree.c`](src/PORTAL/cgeometry/CBSPTree.c) | 90 | `005397E0`–`0076A990` |
| [`CBSPLeaf.c`](src/PORTAL/cgeometry/CBSPLeaf.c) | 84 | `0053D3D0`–`0076B6B0` |
| [`CBSPPortal.c`](src/PORTAL/cgeometry/CBSPPortal.c) | 75 | `0053D850`–`0076BCF0` |
| [`CSurface.c`](src/PORTAL/cgeometry/CSurface.c) | 43 | `00527170`–`0076A340` |
| [`CSphere.c`](src/PORTAL/cgeometry/CSphere.c) | 25 | `005368D0`–`00700120` |
| [`CPolygon.c`](src/PORTAL/cgeometry/CPolygon.c) | 24 | `00538060`–`00700190` |
| [`CCylSphere.c`](src/PORTAL/cgeometry/CCylSphere.c) | 20 | `0053A880`–`00700880` |
| [`CFrame.c`](src/PORTAL/cgeometry/CFrame.c) | 20 | `00534D70`–`00535E40` |
| [`CBldPortal.c`](src/PORTAL/cgeometry/CBldPortal.c) | 19 | `0053BB30`–`00700AA0` |
| [`CCellPortal.c`](src/PORTAL/cgeometry/CCellPortal.c) | 15 | `0053BA10`–`00700990` |
| [`CMaterial.c`](src/PORTAL/cgeometry/CMaterial.c) | 9 | `005396A0`–`0069E710` |
| [`CVertexArray.c`](src/PORTAL/cgeometry/CVertexArray.c) | 7 | `0053BE30`–`0053C030` |
| [`CVertex.c`](src/PORTAL/cgeometry/CVertex.c) | 5 | `0053DD30`–`0053DE50` |
| [`ClipPlaneList.c`](src/PORTAL/cgeometry/ClipPlaneList.c) | 3 | `0053B990`–`0053BA00` |
| [`CPortalPoly.c`](src/PORTAL/cgeometry/CPortalPoly.c) | 2 | `0053DF70`–`0053DF80` |
| [`ClipPlane.c`](src/PORTAL/cgeometry/ClipPlane.c) | 2 | `00534D40`–`00534D50` |

### `PORTAL/character` — 2 files, 20 functions

| File | Functions | Address range |
|---|---|---|
| [`CharacterSet.c`](src/PORTAL/character/CharacterSet.c) | 15 | `004FDE50`–`004FE570` |
| [`CharacterIdentity.c`](src/PORTAL/character/CharacterIdentity.c) | 5 | `004FE700`–`004FE880` |

### `PORTAL/chierarchy` — 1 files, 14 functions

| File | Functions | Address range |
|---|---|---|
| [`cWObjHierNode.c`](src/PORTAL/chierarchy/cWObjHierNode.c) | 14 | `004FC610`–`006F9460` |

### `PORTAL/ckeystone` — 2 files, 113 functions

| File | Functions | Address range |
|---|---|---|
| [`ckeystone.c`](src/PORTAL/ckeystone/ckeystone.c) | 99 | `00556B60`–`00772F50` |
| [`GUNXmlParse.c`](src/PORTAL/ckeystone/GUNXmlParse.c) | 14 | `00557200`–`00773010` |

### `PORTAL/clinet` — 16 files, 343 functions

| File | Functions | Address range |
|---|---|---|
| [`ClientNet.c`](src/PORTAL/clinet/ClientNet.c) | 99 | `004011E0`–`007055C0` |
| [`CFlowQueue.c`](src/PORTAL/clinet/CFlowQueue.c) | 51 | `004537C0`–`00705670` |
| [`PacketController.c`](src/PORTAL/clinet/PacketController.c) | 34 | `00540AC0`–`007055A0` |
| [`pUI.c`](src/PORTAL/clinet/pUI.c) | 22 | `00546740`–`00705630` |
| [`CIndicator.c`](src/PORTAL/clinet/CIndicator.c) | 19 | `00549FA0`–`00705730` |
| [`SentPacket.c`](src/PORTAL/clinet/SentPacket.c) | 19 | `004C59B0`–`00705750` |
| [`ReceiverData.c`](src/PORTAL/clinet/ReceiverData.c) | 18 | `00548C60`–`007056B0` |
| [`NetBlob.c`](src/PORTAL/clinet/NetBlob.c) | 15 | `00549A20`–`00705710` |
| [`CNetAuthenticator.c`](src/PORTAL/clinet/CNetAuthenticator.c) | 14 | `00540590`–`00540A10` |
| [`NetPacket.c`](src/PORTAL/clinet/NetPacket.c) | 11 | `005492B0`–`007056D0` |
| [`RecipientData.c`](src/PORTAL/clinet/RecipientData.c) | 10 | `00546DD0`–`00705650` |
| [`LinkStatus.c`](src/PORTAL/clinet/LinkStatus.c) | 9 | `00546440`–`007055E0` |
| [`BlobFrag.c`](src/PORTAL/clinet/BlobFrag.c) | 7 | `005496F0`–`007056F0` |
| [`CNetKeyExch.c`](src/PORTAL/clinet/CNetKeyExch.c) | 6 | `005498E0`–`005499E0` |
| [`ArrivedEphInfo.c`](src/PORTAL/clinet/ArrivedEphInfo.c) | 5 | `0054ADB0`–`00705760` |
| [`CNetInterface.c`](src/PORTAL/clinet/CNetInterface.c) | 4 | `00548C40`–`00705690` |

### `PORTAL/clothing` — 4 files, 137 functions

| File | Functions | Address range |
|---|---|---|
| [`ClothingTable.c`](src/PORTAL/clothing/ClothingTable.c) | 100 | `00526930`–`0070D820` |
| [`ClothingData.c`](src/PORTAL/clothing/ClothingData.c) | 24 | `005A82E0`–`0070D830` |
| [`ClothingBase.c`](src/PORTAL/clothing/ClothingBase.c) | 11 | `005A8CD0`–`0070D840` |
| [`ShadePackage.c`](src/PORTAL/clothing/ShadePackage.c) | 2 | `005A8290`–`005A82C0` |

### `PORTAL/cmdinterp` — 2 files, 82 functions

| File | Functions | Address range |
|---|---|---|
| [`CmdInterp.c`](src/PORTAL/cmdinterp/CmdInterp.c) | 77 | `006B3140`–`00790A40` |
| [`CmdInterpDefs.c`](src/PORTAL/cmdinterp/CmdInterpDefs.c) | 5 | `006B4960`–`006B4B80` |

### `PORTAL/cobject` — 3 files, 65 functions

| File | Functions | Address range |
|---|---|---|
| [`CObjMaint.c`](src/PORTAL/cobject/CObjMaint.c) | 56 | `005077A0`–`007668C0` |
| [`CWeenieObj.c`](src/PORTAL/cobject/CWeenieObj.c) | 6 | `00509430`–`006FB160` |
| [`CObjectInventory.c`](src/PORTAL/cobject/CObjectInventory.c) | 3 | `006B4C80`–`006B4D20` |

### `PORTAL/command` — 1 files, 1 functions

| File | Functions | Address range |
|---|---|---|
| [`String2Command.c`](src/PORTAL/command/String2Command.c) | 1 | `006B4C20`–`006B4C20` |

### `PORTAL/cphysdesc` — 1 files, 20 functions

| File | Functions | Address range |
|---|---|---|
| [`CPhysicsDesc.c`](src/PORTAL/cphysdesc/CPhysicsDesc.c) | 20 | `0051D450`–`006FCE50` |

### `PORTAL/cphysics` — 6 files, 132 functions

| File | Functions | Address range |
|---|---|---|
| [`CTransition.c`](src/PORTAL/cphysics/CTransition.c) | 51 | `00509C50`–`00766A10` |
| [`CPhysics.c`](src/PORTAL/cphysics/CPhysics.c) | 35 | `00509690`–`007669D0` |
| [`CSpherePath.c`](src/PORTAL/cphysics/CSpherePath.c) | 17 | `0050C330`–`006FB4A0` |
| [`CObjectInfo.c`](src/PORTAL/cphysics/CObjectInfo.c) | 14 | `0050CEB0`–`006FB580` |
| [`CCollisionInfo.c`](src/PORTAL/cphysics/CCollisionInfo.c) | 11 | `006B4D40`–`007237C0` |
| [`CCellArray.c`](src/PORTAL/cphysics/CCellArray.c) | 4 | `006B4E80`–`006B4FF0` |

### `PORTAL/cphysobj` — 19 files, 875 functions

| File | Functions | Address range |
|---|---|---|
| [`CPhysicsObj.c`](src/PORTAL/cphysobj/CPhysicsObj.c) | 336 | `0050E7B0`–`00767940` |
| [`CPhysicsPart.c`](src/PORTAL/cphysobj/CPhysicsPart.c) | 115 | `0050D330`–`007670B0` |
| [`CPartArray.c`](src/PORTAL/cphysobj/CPartArray.c) | 90 | `00517C60`–`006FC630` |
| [`CShadowPart.c`](src/PORTAL/cphysobj/CShadowPart.c) | 76 | `006B5050`–`00791090` |
| [`CMTableManager.c`](src/PORTAL/cphysobj/CMTableManager.c) | 28 | `0051BBD0`–`006FCC60` |
| [`CPackClasses.c`](src/PORTAL/cphysobj/CPackClasses.c) | 27 | `004F1030`–`006FC430` |
| [`CParticleEmitter.c`](src/PORTAL/cphysobj/CParticleEmitter.c) | 27 | `0051C190`–`006FCD80` |
| [`CTargetting.c`](src/PORTAL/cphysobj/CTargetting.c) | 25 | `0051A370`–`006FC7F0` |
| [`CParticleEmitterInfo.c`](src/PORTAL/cphysobj/CParticleEmitterInfo.c) | 24 | `005170D0`–`006FC500` |
| [`CBuildingObj.c`](src/PORTAL/cphysobj/CBuildingObj.c) | 22 | `006B51B0`–`00723EE0` |
| [`CDetectionCylsphere.c`](src/PORTAL/cphysobj/CDetectionCylsphere.c) | 21 | `005196D0`–`006FC710` |
| [`CChildList.c`](src/PORTAL/cphysobj/CChildList.c) | 19 | `0051ADD0`–`006FC8D0` |
| [`CCollisionProfile.c`](src/PORTAL/cphysobj/CCollisionProfile.c) | 12 | `0051B900`–`006FC8F0` |
| [`CParticleManager.c`](src/PORTAL/cphysobj/CParticleManager.c) | 12 | `00519740`–`0051B8A0` |
| [`CPhysicsObjHooks.c`](src/PORTAL/cphysobj/CPhysicsObjHooks.c) | 10 | `0051BA50`–`006FC9D0` |
| [`CShadowObj.c`](src/PORTAL/cphysobj/CShadowObj.c) | 9 | `0051BB30`–`006FCAB0` |
| [`CAttackCone.c`](src/PORTAL/cphysobj/CAttackCone.c) | 8 | `0051A040`–`0051A340` |
| [`CScriptManager.c`](src/PORTAL/cphysobj/CScriptManager.c) | 7 | `0051B2F0`–`006FC8E0` |
| [`CSetPositionDefs.c`](src/PORTAL/cphysobj/CSetPositionDefs.c) | 7 | `0051BB40`–`006FCB20` |

### `PORTAL/cpmanager` — 4 files, 71 functions

| File | Functions | Address range |
|---|---|---|
| [`CInterpolationManager.c`](src/PORTAL/cpmanager/CInterpolationManager.c) | 21 | `00509680`–`00707110` |
| [`CPositionManager.c`](src/PORTAL/cpmanager/CPositionManager.c) | 18 | `00555160`–`00706F50` |
| [`CStickyManager.c`](src/PORTAL/cpmanager/CStickyManager.c) | 17 | `00555400`–`00707030` |
| [`CConstraintManager.c`](src/PORTAL/cpmanager/CConstraintManager.c) | 15 | `00556090`–`007071F0` |

### `PORTAL/cregion` — 11 files, 296 functions

| File | Functions | Address range |
|---|---|---|
| [`CRegionDesc.c`](src/PORTAL/cregion/CRegionDesc.c) | 50 | `004FC5E0`–`00765000` |
| [`CTerrainDesc.c`](src/PORTAL/cregion/CTerrainDesc.c) | 38 | `005023E0`–`00765420` |
| [`CSceneDesc.c`](src/PORTAL/cregion/CSceneDesc.c) | 33 | `00502270`–`00765220` |
| [`CSceneType.c`](src/PORTAL/cregion/CSceneType.c) | 33 | `005031C0`–`00765840` |
| [`CSoundDesc.c`](src/PORTAL/cregion/CSoundDesc.c) | 33 | `00502740`–`00765620` |
| [`CTexMerge.c`](src/PORTAL/cregion/CTexMerge.c) | 31 | `005033D0`–`006FA100` |
| [`CSkyDesc.c`](src/PORTAL/cregion/CSkyDesc.c) | 26 | `00500950`–`006F9730` |
| [`CPalShift.c`](src/PORTAL/cregion/CPalShift.c) | 25 | `004FFA40`–`006F9720` |
| [`CLandSurf.c`](src/PORTAL/cregion/CLandSurf.c) | 21 | `00502A20`–`006F9E60` |
| [`CEncounterDesc.c`](src/PORTAL/cregion/CEncounterDesc.c) | 5 | `00502990`–`006F9DE0` |
| [`CFileNameDesc.c`](src/PORTAL/cregion/CFileNameDesc.c) | 1 | `005008D0`–`005008D0` |

### `PORTAL/cryptosystem` — 1 files, 1 functions

| File | Functions | Address range |
|---|---|---|
| [`portaldh.c`](src/PORTAL/cryptosystem/portaldh.c) | 1 | `005B0250`–`005B0250` |

### `PORTAL/ctristrip` — 2 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`CSurfaceTriStrips.c`](src/PORTAL/ctristrip/CSurfaceTriStrips.c) | 1 | `00534CF0`–`00534CF0` |
| [`CTriangleStrip.c`](src/PORTAL/ctristrip/CTriangleStrip.c) | 1 | `00534D30`–`00534D30` |

### `PORTAL/d3dpolyrender` — 1 files, 127 functions

| File | Functions | Address range |
|---|---|---|
| [`D3DPolyRender.c`](src/PORTAL/d3dpolyrender/D3DPolyRender.c) | 127 | `00439CE0`–`00775AE0` |

### `PORTAL/database` — 1 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`CliDatEvents.c`](src/PORTAL/database/CliDatEvents.c) | 5 | `005563B0`–`0070D330` |

### `PORTAL/debug_common` — 1 files, 11 functions

| File | Functions | Address range |
|---|---|---|
| [`DwExceptionHandler.c`](src/PORTAL/debug_common/DwExceptionHandler.c) | 11 | `006B5680`–`00791110` |

### `PORTAL/diskspace` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`DiskSpace.c`](src/PORTAL/diskspace/DiskSpace.c) | 2 | `00509670`–`005D58B0` |

### `PORTAL/emaptodisplay` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`EmapToDisplay.c`](src/PORTAL/emaptodisplay/EmapToDisplay.c) | 2 | `005A91B0`–`005A9260` |

### `PORTAL/engine_house` — 2 files, 56 functions

| File | Functions | Address range |
|---|---|---|
| [`RestrictionDB.c`](src/PORTAL/engine_house/RestrictionDB.c) | 32 | `005AE250`–`005AEFB0` |
| [`HouseAccessRestrictions.c`](src/PORTAL/engine_house/HouseAccessRestrictions.c) | 24 | `005A7C90`–`005AFE30` |

### `PORTAL/gameplay_engine` — 1 files, 7 functions

| File | Functions | Address range |
|---|---|---|
| [`BadData.c`](src/PORTAL/gameplay_engine/BadData.c) | 7 | `004FDBF0`–`006F9480` |

### `PORTAL/gameplay_misc` — 6 files, 52 functions

| File | Functions | Address range |
|---|---|---|
| [`ChatPose.c`](src/PORTAL/gameplay_misc/ChatPose.c) | 30 | `004114F0`–`006F9470` |
| [`MovementSystem.c`](src/PORTAL/gameplay_misc/MovementSystem.c) | 7 | `006B0950`–`00723330` |
| [`ItemUses.c`](src/PORTAL/gameplay_misc/ItemUses.c) | 6 | `004FCCB0`–`004FCD50` |
| [`ContentsList.c`](src/PORTAL/gameplay_misc/ContentsList.c) | 3 | `006AFED0`–`006AFF10` |
| [`EncumbranceSystem.c`](src/PORTAL/gameplay_misc/EncumbranceSystem.c) | 3 | `004FCC00`–`004FCC70` |
| [`LogTextTypeEnumMap.c`](src/PORTAL/gameplay_misc/LogTextTypeEnumMap.c) | 3 | `006AFF40`–`006B0590` |

### `PORTAL/gameplay_net` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`WeenieOrderHdr.c`](src/PORTAL/gameplay_net/WeenieOrderHdr.c) | 2 | `006B0AA0`–`006B0AE0` |

### `PORTAL/gametime` — 1 files, 15 functions

| File | Functions | Address range |
|---|---|---|
| [`GameTime.c`](src/PORTAL/gametime/GameTime.c) | 15 | `00502690`–`005A6EC0` |

### `PORTAL/geometry` — 8 files, 49 functions

| File | Functions | Address range |
|---|---|---|
| [`Position.c`](src/PORTAL/geometry/Position.c) | 21 | `00526850`–`0070D8B0` |
| [`LandDefs.c`](src/PORTAL/geometry/LandDefs.c) | 10 | `005A9980`–`0070D900` |
| [`Plane.c`](src/PORTAL/geometry/Plane.c) | 6 | `005AA0A0`–`0070D9B0` |
| [`AFrame.c`](src/PORTAL/geometry/AFrame.c) | 3 | `005A9E30`–`005A9FB0` |
| [`RGBColor.c`](src/PORTAL/geometry/RGBColor.c) | 3 | `00524810`–`005AA080` |
| [`Vec2D.c`](src/PORTAL/geometry/Vec2D.c) | 3 | `0051F6D0`–`005A9E00` |
| [`GPhysics.c`](src/PORTAL/geometry/GPhysics.c) | 2 | `0070D920`–`0070D930` |
| [`Vector.c`](src/PORTAL/geometry/Vector.c) | 1 | `0068A3A0`–`0068A3A0` |

### `PORTAL/gfxobj` — 1 files, 94 functions

| File | Functions | Address range |
|---|---|---|
| [`CGfxObj.c`](src/PORTAL/gfxobj/CGfxObj.c) | 94 | `00526840`–`0076A230` |

### `PORTAL/http_wininet_async_client` — 4 files, 36 functions

| File | Functions | Address range |
|---|---|---|
| [`ConnectionCache.c`](src/PORTAL/http_wininet_async_client/ConnectionCache.c) | 9 | `007146E0`–`007147A0` |
| [`HttpClient.c`](src/PORTAL/http_wininet_async_client/HttpClient.c) | 9 | `00714540`–`00714600` |
| [`WinInetAsyncHttpClient.c`](src/PORTAL/http_wininet_async_client/WinInetAsyncHttpClient.c) | 9 | `00714470`–`00714530` |
| [`WinInetImplementation.c`](src/PORTAL/http_wininet_async_client/WinInetImplementation.c) | 9 | `00714610`–`007146D0` |

### `PORTAL/image` — 2 files, 957 functions

| File | Functions | Address range |
|---|---|---|
| [`ImgTex.c`](src/PORTAL/image/ImgTex.c) | 929 | `00415200`–`00771040` |
| [`Palette.c`](src/PORTAL/image/Palette.c) | 28 | `00526890`–`0076BDF0` |

### `PORTAL/list` — 1 files, 19 functions

| File | Functions | Address range |
|---|---|---|
| [`IDList.c`](src/PORTAL/list/IDList.c) | 19 | `005ADB50`–`005AE160` |

### `PORTAL/lscape` — 2 files, 234 functions

| File | Functions | Address range |
|---|---|---|
| [`LScape.c`](src/PORTAL/lscape/LScape.c) | 138 | `00504A40`–`00766150` |
| [`Sky.c`](src/PORTAL/lscape/Sky.c) | 96 | `00506DC0`–`00766870` |

### `PORTAL/newnet` — 7 files, 120 functions

| File | Functions | Address range |
|---|---|---|
| [`OptionalHeader.c`](src/PORTAL/newnet/OptionalHeader.c) | 52 | `00542B80`–`0070E1B0` |
| [`ConnectionErrors.c`](src/PORTAL/newnet/ConnectionErrors.c) | 43 | `0070D9C0`–`00777640` |
| [`NetBlobID.c`](src/PORTAL/newnet/NetBlobID.c) | 8 | `005AA300`–`0070DEE0` |
| [`NetInitializer.c`](src/PORTAL/newnet/NetInitializer.c) | 6 | `005AA6F0`–`00777660` |
| [`NetLayerPacket.c`](src/PORTAL/newnet/NetLayerPacket.c) | 6 | `00542C20`–`0070DF10` |
| [`NetUtils.c`](src/PORTAL/newnet/NetUtils.c) | 3 | `005AA450`–`0070DEF0` |
| [`InterfaceEnumerator.c`](src/PORTAL/newnet/InterfaceEnumerator.c) | 2 | `005AB540`–`005AB5E0` |

### `PORTAL/objdesc` — 6 files, 64 functions

| File | Functions | Address range |
|---|---|---|
| [`ObjDesc.c`](src/PORTAL/objdesc/ObjDesc.c) | 24 | `005AB600`–`0070E1C0` |
| [`PublicWeenieDesc.c`](src/PORTAL/objdesc/PublicWeenieDesc.c) | 12 | `005AC7B0`–`0070E1E0` |
| [`AnimChgs.c`](src/PORTAL/objdesc/AnimChgs.c) | 10 | `005AD830`–`0070E1F0` |
| [`PalSet.c`](src/PORTAL/objdesc/PalSet.c) | 9 | `005268F0`–`0070E1D0` |
| [`OldPublicWeenieDesc.c`](src/PORTAL/objdesc/OldPublicWeenieDesc.c) | 7 | `006B3DC0`–`00724860` |
| [`WeenieDesc.c`](src/PORTAL/objdesc/WeenieDesc.c) | 2 | `005ADB30`–`005ADB40` |

### `PORTAL/oldcore_utils` — 1 files, 13 functions

| File | Functions | Address range |
|---|---|---|
| [`PSUtils.c`](src/PORTAL/oldcore_utils/PSUtils.c) | 13 | `00683C30`–`0077F770` |

### `PORTAL/physobj_ethereal` — 1 files, 4 functions

| File | Functions | Address range |
|---|---|---|
| [`LOSParameters.c`](src/PORTAL/physobj_ethereal/LOSParameters.c) | 4 | `00723EF0`–`00723F50` |

### `PORTAL/player` — 2 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`AdminAccountData.c`](src/PORTAL/player/AdminAccountData.c) | 4 | `006B0B30`–`006B0BF0` |
| [`AdminPlayerData.c`](src/PORTAL/player/AdminPlayerData.c) | 1 | `006B0B80`–`006B0B80` |

### `PORTAL/primd3drender` — 1 files, 89 functions

| File | Functions | Address range |
|---|---|---|
| [`PrimD3DRender.c`](src/PORTAL/primd3drender/PrimD3DRender.c) | 89 | `0059AA40`–`00775390` |

### `PORTAL/pstring` — 1 files, 14 functions

| File | Functions | Address range |
|---|---|---|
| [`PStringDecls.c`](src/PORTAL/pstring/PStringDecls.c) | 14 | `0070E200`–`007777B0` |

### `PORTAL/pversion` — 2 files, 9 functions

| File | Functions | Address range |
|---|---|---|
| [`Resource.c`](src/PORTAL/pversion/Resource.c) | 5 | `00554E40`–`005550F0` |
| [`Version.c`](src/PORTAL/pversion/Version.c) | 4 | `00554CD0`–`00554E00` |

### `PORTAL/qualities` — 2 files, 13 functions

| File | Functions | Address range |
|---|---|---|
| [`QualityFilter.c`](src/PORTAL/qualities/QualityFilter.c) | 9 | `006B1EC0`–`006B25C0` |
| [`EventFilter.c`](src/PORTAL/qualities/EventFilter.c) | 4 | `006B1D70`–`006B1E70` |

### `PORTAL/random` — 1 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`Random.c`](src/PORTAL/random/Random.c) | 5 | `0042C450`–`0042C600` |

### `PORTAL/region` — 1 files, 22 functions

| File | Functions | Address range |
|---|---|---|
| [`Scene.c`](src/PORTAL/region/Scene.c) | 22 | `005A5BB0`–`0070D320` |

### `PORTAL/render` — 1 files, 195 functions

| File | Functions | Address range |
|---|---|---|
| [`Render.c`](src/PORTAL/render/Render.c) | 195 | `00439340`–`00771A40` |

### `PORTAL/renderalloc` — 1 files, 79 functions

| File | Functions | Address range |
|---|---|---|
| [`RenderAllocator.c`](src/PORTAL/renderalloc/RenderAllocator.c) | 79 | `005862C0`–`00774940` |

### `PORTAL/renderdev` — 1 files, 38 functions

| File | Functions | Address range |
|---|---|---|
| [`RenderDevice.c`](src/PORTAL/renderdev/RenderDevice.c) | 38 | `0054F0B0`–`00771C10` |

### `PORTAL/smartbox` — 5 files, 496 functions

| File | Functions | Address range |
|---|---|---|
| [`SmartBox.c`](src/PORTAL/smartbox/SmartBox.c) | 223 | `00451A20`–`0075C050` |
| [`CellManager.c`](src/PORTAL/smartbox/CellManager.c) | 102 | `00455710`–`0075C880` |
| [`GraphicsOptions.c`](src/PORTAL/smartbox/GraphicsOptions.c) | 62 | `00455C30`–`0075CDC0` |
| [`CameraManager.c`](src/PORTAL/smartbox/CameraManager.c) | 60 | `00455D70`–`0075D020` |
| [`CameraSet.c`](src/PORTAL/smartbox/CameraSet.c) | 49 | `004573C0`–`0075D0F0` |

### `PORTAL/sound` — 10 files, 291 functions

| File | Functions | Address range |
|---|---|---|
| [`SoundManager.c`](src/PORTAL/sound/SoundManager.c) | 89 | `00507EE0`–`007720C0` |
| [`Ambient.c`](src/PORTAL/sound/Ambient.c) | 64 | `00550CD0`–`007722C0` |
| [`cstable.c`](src/PORTAL/sound/cstable.c) | 50 | `00551CB0`–`007724D0` |
| [`Soundbuf.c`](src/PORTAL/sound/Soundbuf.c) | 38 | `00552670`–`007726D0` |
| [`sounddev.c`](src/PORTAL/sound/sounddev.c) | 12 | `00552E10`–`007727A0` |
| [`mstrconv.c`](src/PORTAL/sound/mstrconv.c) | 10 | `00553E90`–`00554940` |
| [`mstream.c`](src/PORTAL/sound/mstream.c) | 9 | `00552F60`–`00553770` |
| [`DBWave.c`](src/PORTAL/sound/DBWave.c) | 8 | `005268B0`–`00706A00` |
| [`WaveFile.c`](src/PORTAL/sound/WaveFile.c) | 8 | `00553840`–`00553CD0` |
| [`cdirsnd.c`](src/PORTAL/sound/cdirsnd.c) | 3 | `00553D00`–`00553E40` |

### `PORTAL/squelch` — 1 files, 35 functions

| File | Functions | Address range |
|---|---|---|
| [`SquelchPackage.c`](src/PORTAL/squelch/SquelchPackage.c) | 35 | `006B0C20`–`006B1D50` |

### `PORTAL/string` — 1 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`String.c`](src/PORTAL/string/String.c) | 5 | `005AE190`–`0070E320` |

### `PORTAL/timestamper` — 1 files, 7 functions

| File | Functions | Address range |
|---|---|---|
| [`TSRecv.c`](src/PORTAL/timestamper/TSRecv.c) | 7 | `005AFE50`–`005B0220` |

### `PORTAL/ui_misc` — 2 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`GenUI.c`](src/PORTAL/ui_misc/GenUI.c) | 4 | `004FC5B0`–`006F9450` |
| [`GenItems.c`](src/PORTAL/ui_misc/GenItems.c) | 1 | `004FC550`–`004FC550` |

### `PORTAL/vlong` — 1 files, 25 functions

| File | Functions | Address range |
|---|---|---|
| [`vlong.c`](src/PORTAL/vlong/vlong.c) | 25 | `005B0280`–`005B0F10` |

### `PORTAL/weenie_net` — 2 files, 18 functions

| File | Functions | Address range |
|---|---|---|
| [`WTimeStamper.c`](src/PORTAL/weenie_net/WTimeStamper.c) | 16 | `006B2990`–`006B3040` |
| [`OrderHdr.c`](src/PORTAL/weenie_net/OrderHdr.c) | 2 | `006B30D0`–`006B3100` |

## `ENGINE`

Rendering, UI framework, input, database/cache, property system. The largest layer.

### `ENGINE/actionmap` — 1 files, 59 functions

| File | Functions | Address range |
|---|---|---|
| [`ActionMap.c`](src/ENGINE/actionmap/ActionMap.c) | 59 | `006845E0`–`0077F950` |

### `ENGINE/cimelib` — 1 files, 29 functions

| File | Functions | Address range |
|---|---|---|
| [`cime.c`](src/ENGINE/cimelib/cime.c) | 29 | `00430B30`–`00728560` |

### `ENGINE/cinputmap_base` — 3 files, 1,000 functions

| File | Functions | Address range |
|---|---|---|
| [`CKeyMap.c`](src/ENGINE/cinputmap_base/CKeyMap.c) | 872 | `0068C6C0`–`007844C0` |
| [`CInputManager.c`](src/ENGINE/cinputmap_base/CInputManager.c) | 92 | `00430C40`–`00728890` |
| [`InputDefs.c`](src/ENGINE/cinputmap_base/InputDefs.c) | 36 | `0068A020`–`0077FAC0` |

### `ENGINE/cinputmap_win32` — 1 files, 118 functions

| File | Functions | Address range |
|---|---|---|
| [`CInputManager_WIN32.c`](src/ENGINE/cinputmap_win32/CInputManager_WIN32.c) | 118 | `00685F90`–`0077FA80` |

### `ENGINE/cmain` — 1 files, 168 functions

| File | Functions | Address range |
|---|---|---|
| [`Client.c`](src/ENGINE/cmain/Client.c) | 168 | `00411110`–`00726820` |

### `ENGINE/cregistry` — 1 files, 3 functions

| File | Functions | Address range |
|---|---|---|
| [`CliRegKey.c`](src/ENGINE/cregistry/CliRegKey.c) | 3 | `006AFE90`–`00790810` |

### `ENGINE/dataerror` — 1 files, 19 functions

| File | Functions | Address range |
|---|---|---|
| [`DataError.c`](src/ENGINE/dataerror/DataError.c) | 19 | `00413110`–`006C44A0` |

### `ENGINE/datasrc` — 1 files, 5 functions

| File | Functions | Address range |
|---|---|---|
| [`DataSrc.c`](src/ENGINE/datasrc/DataSrc.c) | 5 | `0066FEC0`–`0066FF20` |

### `ENGINE/datcompat` — 1 files, 3 functions

| File | Functions | Address range |
|---|---|---|
| [`DatIDStamp.c`](src/ENGINE/datcompat/DatIDStamp.c) | 3 | `004136B0`–`00413700` |

### `ENGINE/dbfiledb` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`DBFile2IDTable.c`](src/ENGINE/dbfiledb/DBFile2IDTable.c) | 2 | `0067B310`–`00714FC0` |

### `ENGINE/debugconsole` — 1 files, 63 functions

| File | Functions | Address range |
|---|---|---|
| [`DebugConsole.c`](src/ENGINE/debugconsole/DebugConsole.c) | 63 | `00690090`–`00784770` |

### `ENGINE/device` — 2 files, 148 functions

| File | Functions | Address range |
|---|---|---|
| [`Device.c`](src/ENGINE/device/Device.c) | 142 | `00438E40`–`00729AC0` |
| [`SurfaceTools.c`](src/ENGINE/device/SurfaceTools.c) | 6 | `0043BDB0`–`006C6A80` |

### `ENGINE/diskcon` — 9 files, 202 functions

| File | Functions | Address range |
|---|---|---|
| [`BTree.c`](src/ENGINE/diskcon/BTree.c) | 50 | `00671C50`–`00714E10` |
| [`DiskCon.c`](src/ENGINE/diskcon/DiskCon.c) | 42 | `00670330`–`0077EE90` |
| [`LRUList.c`](src/ENGINE/diskcon/LRUList.c) | 36 | `00674A30`–`00714E90` |
| [`DiskTransactInfo.c`](src/ENGINE/diskcon/DiskTransactInfo.c) | 23 | `006761C0`–`00714ED0` |
| [`BlkAlloc.c`](src/ENGINE/diskcon/BlkAlloc.c) | 20 | `00673E80`–`00714E50` |
| [`DiskDev.c`](src/ENGINE/diskcon/DiskDev.c) | 10 | `00676B90`–`00714F10` |
| [`LookFile.c`](src/ENGINE/diskcon/LookFile.c) | 8 | `00671850`–`00714DD0` |
| [`DataHist.c`](src/ENGINE/diskcon/DataHist.c) | 7 | `00671650`–`00714D90` |
| [`IterationList.c`](src/ENGINE/diskcon/IterationList.c) | 6 | `0066FF50`–`006702E0` |

### `ENGINE/emp_bitfield` — 1 files, 7 functions

| File | Functions | Address range |
|---|---|---|
| [`EnumeratedBitfield.c`](src/ENGINE/emp_bitfield/EnumeratedBitfield.c) | 7 | `00676EA0`–`00677430` |

### `ENGINE/engine_cdatabase` — 2 files, 184 functions

| File | Functions | Address range |
|---|---|---|
| [`CLCache.c`](src/ENGINE/engine_cdatabase/CLCache.c) | 181 | `004180E0`–`00764DD0` |
| [`CLOCache.c`](src/ENGINE/engine_cdatabase/CLOCache.c) | 3 | `00417320`–`006F9440` |

### `ENGINE/engine_cevents` — 7 files, 24 functions

| File | Functions | Address range |
|---|---|---|
| [`ECM_UI.c`](src/ENGINE/engine_cevents/ECM_UI.c) | 11 | `00692500`–`00692810` |
| [`ECM_Item.c`](src/ENGINE/engine_cevents/ECM_Item.c) | 4 | `006928C0`–`006929C0` |
| [`ECM_Login.c`](src/ENGINE/engine_cevents/ECM_Login.c) | 3 | `00692A90`–`00692B10` |
| [`ECM_Character.c`](src/ENGINE/engine_cevents/ECM_Character.c) | 2 | `00692B50`–`00692B90` |
| [`ECM_Physics.c`](src/ENGINE/engine_cevents/ECM_Physics.c) | 2 | `00692A10`–`00692A50` |
| [`ECM_DDD.c`](src/ENGINE/engine_cevents/ECM_DDD.c) | 1 | `00692870`–`00692870` |
| [`NoticeHandler.c`](src/ENGINE/engine_cevents/NoticeHandler.c) | 1 | `0043C3D0`–`0043C3D0` |

### `ENGINE/engine_client_geometry` — 2 files, 884 functions

| File | Functions | Address range |
|---|---|---|
| [`VertexArray.c`](src/ENGINE/engine_client_geometry/VertexArray.c) | 883 | `0044E030`–`0077DF00` |
| [`Vertex.c`](src/ENGINE/engine_client_geometry/Vertex.c) | 1 | `005D8670`–`005D8670` |

### `ENGINE/engine_cmessage` — 1 files, 4 functions

| File | Functions | Address range |
|---|---|---|
| [`GlobalEventHandler.c`](src/ENGINE/engine_cmessage/GlobalEventHandler.c) | 4 | `0043C400`–`0043C450` |

### `ENGINE/engine_database` — 8 files, 334 functions

| File | Functions | Address range |
|---|---|---|
| [`DBCache.c`](src/ENGINE/engine_database/DBCache.c) | 132 | `00413720`–`00726E40` |
| [`AsyncCache.c`](src/ENGINE/engine_database/AsyncCache.c) | 81 | `00417350`–`006C4A00` |
| [`DBOCache.c`](src/ENGINE/engine_database/DBOCache.c) | 34 | `004166B0`–`006C49C0` |
| [`EnuIDMap.c`](src/ENGINE/engine_database/EnuIDMap.c) | 27 | `00415590`–`006C4980` |
| [`DBObj.c`](src/ENGINE/engine_database/DBObj.c) | 23 | `00415120`–`00726ED0` |
| [`ThreadedCache.c`](src/ENGINE/engine_database/ThreadedCache.c) | 21 | `00677550`–`00714F50` |
| [`DBObjPackVersion.c`](src/ENGINE/engine_database/DBObjPackVersion.c) | 9 | `0041A2B0`–`00726FE0` |
| [`QDIDArray.c`](src/ENGINE/engine_database/QDIDArray.c) | 7 | `00419FE0`–`006C4A10` |

### `ENGINE/engine_events` — 1 files, 13 functions

| File | Functions | Address range |
|---|---|---|
| [`CliDatEvents.c`](src/ENGINE/engine_events/CliDatEvents.c) | 13 | `00677C70`–`00714F90` |

### `ENGINE/engine_notice` — 2 files, 49 functions

| File | Functions | Address range |
|---|---|---|
| [`QualityRegistrar.c`](src/ENGINE/engine_notice/QualityRegistrar.c) | 34 | `00692C30`–`00719140` |
| [`NoticeRegistrar.c`](src/ENGINE/engine_notice/NoticeRegistrar.c) | 15 | `00431350`–`0043C980` |

### `ENGINE/engine_shared_gameplay` — 2 files, 3 functions

| File | Functions | Address range |
|---|---|---|
| [`UILocationData.c`](src/ENGINE/engine_shared_gameplay/UILocationData.c) | 2 | `00678110`–`00678170` |
| [`UISaveLocations.c`](src/ENGINE/engine_shared_gameplay/UISaveLocations.c) | 1 | `00724AE0`–`00724AE0` |

### `ENGINE/engine_shared_geometry` — 7 files, 70 functions

| File | Functions | Address range |
|---|---|---|
| [`BBox.c`](src/ENGINE/engine_shared_geometry/BBox.c) | 28 | `005B1CA0`–`00777AF0` |
| [`Waveform.c`](src/ENGINE/engine_shared_geometry/Waveform.c) | 28 | `005B0F30`–`00777970` |
| [`Plane.c`](src/ENGINE/engine_shared_geometry/Plane.c) | 6 | `005B2AA0`–`0070E630` |
| [`PerlinNoise.c`](src/ENGINE/engine_shared_geometry/PerlinNoise.c) | 3 | `005B2820`–`005B2960` |
| [`AFrame.c`](src/ENGINE/engine_shared_geometry/AFrame.c) | 2 | `0070E660`–`0070E670` |
| [`Frame.c`](src/ENGINE/engine_shared_geometry/Frame.c) | 2 | `0070E640`–`0070E650` |
| [`SimplePolygon.c`](src/ENGINE/engine_shared_geometry/SimplePolygon.c) | 1 | `005B27D0`–`005B27D0` |

### `ENGINE/engine_utils` — 4 files, 16 functions

| File | Functions | Address range |
|---|---|---|
| [`EnginePackBehaviors.c`](src/ENGINE/engine_utils/EnginePackBehaviors.c) | 5 | `00684480`–`00715800` |
| [`MMapUtil.c`](src/ENGINE/engine_utils/MMapUtil.c) | 5 | `006BC1A0`–`006BC270` |
| [`Utils.c`](src/ENGINE/engine_utils/Utils.c) | 4 | `006843D0`–`00684460` |
| [`TimeUtils.c`](src/ENGINE/engine_utils/TimeUtils.c) | 2 | `00684170`–`007157F0` |

### `ENGINE/enummap` — 1 files, 46 functions

| File | Functions | Address range |
|---|---|---|
| [`EnumMapper.c`](src/ENGINE/enummap/EnumMapper.c) | 46 | `004011B0`–`006C4A40` |

### `ENGINE/filedb_core` — 5 files, 106 functions

| File | Functions | Address range |
|---|---|---|
| [`File2IDTable.c`](src/ENGINE/filedb_core/File2IDTable.c) | 62 | `00678280`–`00714FB0` |
| [`MasterDBMapMain.c`](src/ENGINE/filedb_core/MasterDBMapMain.c) | 26 | `0041BE00`–`00727100` |
| [`MasterDBMap.c`](src/ENGINE/filedb_core/MasterDBMap.c) | 10 | `0041C460`–`006C4AC0` |
| [`FileArray.c`](src/ENGINE/filedb_core/FileArray.c) | 5 | `00678190`–`00714FA0` |
| [`QualifiedDataID.c`](src/ENGINE/filedb_core/QualifiedDataID.c) | 3 | `00421C90`–`006C4AE0` |

### `ENGINE/globalregistry` — 3 files, 216 functions

| File | Functions | Address range |
|---|---|---|
| [`UserPreferences.c`](src/ENGINE/globalregistry/UserPreferences.c) | 106 | `00436DC0`–`00729330` |
| [`GlobalRegistryInstance.c`](src/ENGINE/globalregistry/GlobalRegistryInstance.c) | 61 | `004327F0`–`00728A40` |
| [`GlobalRegistry.c`](src/ENGINE/globalregistry/GlobalRegistry.c) | 49 | `00434FE0`–`00728C20` |

### `ENGINE/imagelib` — 1 files, 15 functions

| File | Functions | Address range |
|---|---|---|
| [`Graphic.c`](src/ENGINE/imagelib/Graphic.c) | 15 | `006939D0`–`00719190` |

### `ENGINE/languagespecific` — 1 files, 22 functions

| File | Functions | Address range |
|---|---|---|
| [`CLanguageInfo.c`](src/ENGINE/languagespecific/CLanguageInfo.c) | 22 | `00421CC0`–`006C4AF0` |

### `ENGINE/metalanguage` — 5 files, 97 functions

| File | Functions | Address range |
|---|---|---|
| [`metalanguage_rules.c`](src/ENGINE/metalanguage/metalanguage_rules.c) | 25 | `0067D690`–`00715250` |
| [`metalanguage_utils.c`](src/ENGINE/metalanguage/metalanguage_utils.c) | 22 | `0067B690`–`00715090` |
| [`metalanguage.c`](src/ENGINE/metalanguage/metalanguage.c) | 20 | `0067C010`–`0077F240` |
| [`metalanguage_tokenizer.c`](src/ENGINE/metalanguage/metalanguage_tokenizer.c) | 18 | `0067E5E0`–`0077F450` |
| [`metalanguage_grammar.c`](src/ENGINE/metalanguage/metalanguage_grammar.c) | 12 | `0067DFE0`–`0077F390` |

### `ENGINE/movie` — 1 files, 15 functions

| File | Functions | Address range |
|---|---|---|
| [`MovieTheatre.c`](src/ENGINE/movie/MovieTheatre.c) | 15 | `006BC440`–`00724C10` |

### `ENGINE/namefilter` — 1 files, 11 functions

| File | Functions | Address range |
|---|---|---|
| [`NameFilterTable.c`](src/ENGINE/namefilter/NameFilterTable.c) | 11 | `0067F2F0`–`00715440` |

### `ENGINE/platformstring` — 1 files, 6 functions

| File | Functions | Address range |
|---|---|---|
| [`PlatformString.c`](src/ENGINE/platformstring/PlatformString.c) | 6 | `0043C9C0`–`00729B00` |

### `ENGINE/pparser` — 2 files, 43 functions

| File | Functions | Address range |
|---|---|---|
| [`NewParser.c`](src/ENGINE/pparser/NewParser.c) | 24 | `006BAB80`–`00791BD0` |
| [`PFileParser.c`](src/ENGINE/pparser/PFileParser.c) | 19 | `006B9C30`–`00791B10` |

### `ENGINE/profiler` — 1 files, 1 functions

| File | Functions | Address range |
|---|---|---|
| [`Profiler.c`](src/ENGINE/profiler/Profiler.c) | 1 | `005DD210`–`005DD210` |

### `ENGINE/profilerui` — 1 files, 127 functions

| File | Functions | Address range |
|---|---|---|
| [`ProfilerUI.c`](src/ENGINE/profilerui/ProfilerUI.c) | 127 | `00417DF0`–`0077E5A0` |

### `ENGINE/projset` — 1 files, 74 functions

| File | Functions | Address range |
|---|---|---|
| [`ProjectSettings.c`](src/ENGINE/projset/ProjectSettings.c) | 74 | `004228E0`–`00727700` |

### `ENGINE/property` — 13 files, 589 functions

| File | Functions | Address range |
|---|---|---|
| [`MasterProperty.c`](src/ENGINE/property/MasterProperty.c) | 362 | `00417340`–`00727980` |
| [`BasePropertyDesc.c`](src/ENGINE/property/BasePropertyDesc.c) | 83 | `0042A260`–`00728100` |
| [`BaseProperty.c`](src/ENGINE/property/BaseProperty.c) | 43 | `00429680`–`00727A40` |
| [`PropertyCollection.c`](src/ENGINE/property/PropertyCollection.c) | 43 | `0067F940`–`00715480` |
| [`DBPropertyCollection.c`](src/ENGINE/property/DBPropertyCollection.c) | 13 | `00681450`–`0077F510` |
| [`EnumPropertyValue.c`](src/ENGINE/property/EnumPropertyValue.c) | 11 | `0042B250`–`006C56D0` |
| [`AvailablePropertySet.c`](src/ENGINE/property/AvailablePropertySet.c) | 8 | `0042BAF0`–`007281C0` |
| [`ArrayPropertyValue.c`](src/ENGINE/property/ArrayPropertyValue.c) | 6 | `0042B700`–`0042B8A0` |
| [`StructPropertyValue.c`](src/ENGINE/property/StructPropertyValue.c) | 6 | `0042BE40`–`0042C0C0` |
| [`Bitfield32PropertyValue.c`](src/ENGINE/property/Bitfield32PropertyValue.c) | 5 | `0042ABB0`–`006C5670` |
| [`Bitfield64PropertyValue.c`](src/ENGINE/property/Bitfield64PropertyValue.c) | 4 | `0042AF00`–`006C5680` |
| [`AvailableProperty.c`](src/ENGINE/property/AvailableProperty.c) | 3 | `0042C430`–`007281F0` |
| [`DataFilePropertyValue.c`](src/ENGINE/property/DataFilePropertyValue.c) | 2 | `0042B1A0`–`006C5690` |

### `ENGINE/render_base` — 48 files, 9,815 functions

| File | Functions | Address range |
|---|---|---|
| [`RenderMesh.c`](src/ENGINE/render_base/RenderMesh.c) | 1063 | `004446A0`–`00730C90` |
| [`MaterialLayer.c`](src/ENGINE/render_base/MaterialLayer.c) | 929 | `0044A200`–`00740BD0` |
| [`RenderTexture.c`](src/ENGINE/render_base/RenderTexture.c) | 894 | `0044B790`–`00745CD0` |
| [`MaterialProperty.c`](src/ENGINE/render_base/MaterialProperty.c) | 876 | `0044F890`–`00751F70` |
| [`LayerStage.c`](src/ENGINE/render_base/LayerStage.c) | 871 | `00447E00`–`00736380` |
| [`LayerModifier.c`](src/ENGINE/render_base/LayerModifier.c) | 834 | `004507A0`–`0075B740` |
| [`RenderMaterial.c`](src/ENGINE/render_base/RenderMaterial.c) | 830 | `004492E0`–`0073B630` |
| [`MaterialInstance.c`](src/ENGINE/render_base/MaterialInstance.c) | 829 | `0044CFB0`–`0074AF50` |
| [`MaterialModifier.c`](src/ENGINE/render_base/MaterialModifier.c) | 822 | `004503B0`–`00756B70` |
| [`RenderMeshFragment.c`](src/ENGINE/render_base/RenderMeshFragment.c) | 199 | `0044D920`–`0074BF20` |
| [`RenderMeshBatch.c`](src/ENGINE/render_base/RenderMeshBatch.c) | 175 | `0044F280`–`0074CEF0` |
| [`SceneTool.c`](src/ENGINE/render_base/SceneTool.c) | 117 | `0043D650`–`0072A140` |
| [`RenderUI.c`](src/ENGINE/render_base/RenderUI.c) | 95 | `00448630`–`007369F0` |
| [`RenderTextureD3D.c`](src/ENGINE/render_base/RenderTextureD3D.c) | 92 | `00695120`–`00785620` |
| [`RenderSurface.c`](src/ENGINE/render_base/RenderSurface.c) | 90 | `00443960`–`0072AE30` |
| [`RenderVertexBuffer.c`](src/ENGINE/render_base/RenderVertexBuffer.c) | 90 | `00447330`–`007312E0` |
| [`renbase.c`](src/ENGINE/render_base/renbase.c) | 86 | `006BCD70`–`006BF140` |
| [`RenderIndexBuffer.c`](src/ENGINE/render_base/RenderIndexBuffer.c) | 82 | `0044C8A0`–`00746320` |
| [`RenderVertexBufferD3D.c`](src/ENGINE/render_base/RenderVertexBufferD3D.c) | 80 | `00698180`–`00786630` |
| [`QuickWindow.c`](src/ENGINE/render_base/QuickWindow.c) | 79 | `006989C0`–`00786C80` |
| [`UISurface.c`](src/ENGINE/render_base/UISurface.c) | 78 | `00440650`–`0072A780` |
| [`UIViewportObject.c`](src/ENGINE/render_base/UIViewportObject.c) | 77 | `00694760`–`00784FA0` |
| [`RenderIndexBufferD3D.c`](src/ENGINE/render_base/RenderIndexBufferD3D.c) | 74 | `00697F40`–`00786000` |
| [`amfilter.c`](src/ENGINE/render_base/amfilter.c) | 68 | `006BF190`–`006C0F00` |
| [`ctlutil.c`](src/ENGINE/render_base/ctlutil.c) | 55 | `006C1780`–`006C2620` |
| [`UISurfaceObject.c`](src/ENGINE/render_base/UISurfaceObject.c) | 46 | `00693F30`–`00784960` |
| [`SurfaceWindow.c`](src/ENGINE/render_base/SurfaceWindow.c) | 41 | `00440DA0`–`0072A7C0` |
| [`TextureBasedFont.c`](src/ENGINE/render_base/TextureBasedFont.c) | 37 | `00696190`–`00785820` |
| [`CTextureRenderer.c`](src/ENGINE/render_base/CTextureRenderer.c) | 32 | `006BC940`–`00791DA0` |
| [`GraphicsResource.c`](src/ENGINE/render_base/GraphicsResource.c) | 32 | `00446A30`–`00730CC0` |
| [`RenderVertexStreamD3D.c`](src/ENGINE/render_base/RenderVertexStreamD3D.c) | 28 | `006976C0`–`007859C0` |
| [`Font.c`](src/ENGINE/render_base/Font.c) | 16 | `004432F0`–`006C7780` |
| [`RenderSurfaceD3D.c`](src/ENGINE/render_base/RenderSurfaceD3D.c) | 16 | `00695C90`–`0071A010` |
| [`RenderIndexStreamD3D.c`](src/ENGINE/render_base/RenderIndexStreamD3D.c) | 10 | `00697B70`–`0071A310` |
| [`UIObject.c`](src/ENGINE/render_base/UIObject.c) | 9 | `006992F0`–`0071B430` |
| [`wxutil.c`](src/ENGINE/render_base/wxutil.c) | 9 | `006C10C0`–`006C16E0` |
| [`FontMapper.c`](src/ENGINE/render_base/FontMapper.c) | 8 | `0044B520`–`00740C20` |
| [`QuickButton.c`](src/ENGINE/render_base/QuickButton.c) | 8 | `00698D80`–`00699240` |
| [`UIRectangleObject.c`](src/ENGINE/render_base/UIRectangleObject.c) | 8 | `00694E60`–`007193D0` |
| [`mtype.c`](src/ENGINE/render_base/mtype.c) | 8 | `006C2800`–`006C2A40` |
| [`combase.c`](src/ENGINE/render_base/combase.c) | 7 | `006C0F60`–`006C1080` |
| [`wxlist.c`](src/ENGINE/render_base/wxlist.c) | 6 | `006C2650`–`006C27D0` |
| [`PixelFormat.c`](src/ENGINE/render_base/PixelFormat.c) | 4 | `0043CFB0`–`006C6AB0` |
| [`ALPDecoder.c`](src/ENGINE/render_base/ALPDecoder.c) | 1 | `006E91E0`–`006E91E0` |
| [`CSIDecoder.c`](src/ENGINE/render_base/CSIDecoder.c) | 1 | `006E91F0`–`006E91F0` |
| [`ILBMDecoder.c`](src/ENGINE/render_base/ILBMDecoder.c) | 1 | `006E9200`–`006E9200` |
| [`ImageDecoder.c`](src/ENGINE/render_base/ImageDecoder.c) | 1 | `006DA710`–`006DA710` |
| [`TGADecoder.c`](src/ENGINE/render_base/TGADecoder.c) | 1 | `006E9210`–`006E9210` |

### `ENGINE/stringtable` — 4 files, 134 functions

| File | Functions | Address range |
|---|---|---|
| [`StringInfo.c`](src/ENGINE/stringtable/StringInfo.c) | 62 | `00415BB0`–`00728350` |
| [`StringInfoData.c`](src/ENGINE/stringtable/StringInfoData.c) | 46 | `0042E820`–`006C5820` |
| [`StringTable.c`](src/ENGINE/stringtable/StringTable.c) | 25 | `0042F940`–`006C5830` |
| [`MasterStringTableGen.c`](src/ENGINE/stringtable/MasterStringTableGen.c) | 1 | `00430A20`–`00430A20` |

### `ENGINE/taboo` — 2 files, 26 functions

| File | Functions | Address range |
|---|---|---|
| [`TabooTable.c`](src/ENGINE/taboo/TabooTable.c) | 25 | `00681570`–`007154E0` |
| [`TabooTableAdaptor.c`](src/ENGINE/taboo/TabooTableAdaptor.c) | 1 | `00682A30`–`00682A30` |

### `ENGINE/ui_prefs` — 3 files, 118 functions

| File | Functions | Address range |
|---|---|---|
| [`UIPreferences.c`](src/ENGINE/ui_prefs/UIPreferences.c) | 80 | `004134D0`–`0077E9A0` |
| [`UIPreferenceItem.c`](src/ENGINE/ui_prefs/UIPreferenceItem.c) | 19 | `005DDE90`–`0077EB70` |
| [`UIPreferenceItemEnum.c`](src/ENGINE/ui_prefs/UIPreferenceItemEnum.c) | 19 | `005DDF60`–`0077ED20` |

### `ENGINE/uielement_desc` — 15 files, 1,665 functions

| File | Functions | Address range |
|---|---|---|
| [`LayoutDesc.c`](src/ENGINE/uielement_desc/LayoutDesc.c) | 129 | `006997F0`–`00787650` |
| [`ElementDesc.c`](src/ENGINE/uielement_desc/ElementDesc.c) | 124 | `00681AF0`–`00788010` |
| [`StateDesc.c`](src/ENGINE/uielement_desc/StateDesc.c) | 123 | `0069BED0`–`007889A0` |
| [`MD_Data_Movie.c`](src/ENGINE/uielement_desc/MD_Data_Movie.c) | 112 | `0069CEE0`–`00789CE0` |
| [`MediaDesc.c`](src/ENGINE/uielement_desc/MediaDesc.c) | 112 | `0069D3C0`–`0078A670` |
| [`MD_Data_Anim.c`](src/ENGINE/uielement_desc/MD_Data_Anim.c) | 109 | `0069EAF0`–`0078FCB0` |
| [`MD_Data_State.c`](src/ENGINE/uielement_desc/MD_Data_State.c) | 108 | `0069CE60`–`0078B9A0` |
| [`MD_Data_Fade.c`](src/ENGINE/uielement_desc/MD_Data_Fade.c) | 107 | `0069D920`–`0078CCC0` |
| [`MD_Data_Sound.c`](src/ENGINE/uielement_desc/MD_Data_Sound.c) | 107 | `0069E5F0`–`0078DFF0` |
| [`MD_Data_Alpha.c`](src/ENGINE/uielement_desc/MD_Data_Alpha.c) | 106 | `0069E9F0`–`0078F320` |
| [`MD_Data_Jump.c`](src/ENGINE/uielement_desc/MD_Data_Jump.c) | 106 | `0069E310`–`0078D650` |
| [`MD_Data_Message.c`](src/ENGINE/uielement_desc/MD_Data_Message.c) | 106 | `0069DCC0`–`0078C330` |
| [`MD_Data_Pause.c`](src/ENGINE/uielement_desc/MD_Data_Pause.c) | 106 | `0069E6E0`–`0078E980` |
| [`MD_Data_Cursor.c`](src/ENGINE/uielement_desc/MD_Data_Cursor.c) | 105 | `0069D8A0`–`0078B010` |
| [`MD_Data_Image.c`](src/ENGINE/uielement_desc/MD_Data_Image.c) | 105 | `0069CDD0`–`00789340` |

### `ENGINE/uielement_prim` — 1 files, 83 functions

| File | Functions | Address range |
|---|---|---|
| [`UIRegion.c`](src/ENGINE/uielement_prim/UIRegion.c) | 83 | `0069ED50`–`0078FED0` |

### `ENGINE/uielement_system` — 4 files, 511 functions

| File | Functions | Address range |
|---|---|---|
| [`UIElementManager.c`](src/ENGINE/uielement_system/UIElementManager.c) | 244 | `00459190`–`0075D850` |
| [`UIElement.c`](src/ENGINE/uielement_system/UIElement.c) | 181 | `0045F860`–`0075DB30` |
| [`MediaMachine.c`](src/ENGINE/uielement_system/MediaMachine.c) | 65 | `00465520`–`0075DED0` |
| [`UIListener.c`](src/ENGINE/uielement_system/UIListener.c) | 21 | `00465E20`–`0075DF50` |

### `ENGINE/uielement_types` — 18 files, 569 functions

| File | Functions | Address range |
|---|---|---|
| [`UIElement_Text.c`](src/ENGINE/uielement_types/UIElement_Text.c) | 119 | `00466390`–`0075E080` |
| [`UIElement_ListBox.c`](src/ENGINE/uielement_types/UIElement_ListBox.c) | 69 | `00401200`–`0075E770` |
| [`UIElement_Menu.c`](src/ENGINE/uielement_types/UIElement_Menu.c) | 52 | `0046C990`–`0075E700` |
| [`UIElement_Scrollbar.c`](src/ENGINE/uielement_types/UIElement_Scrollbar.c) | 52 | `0046FFF0`–`0075E850` |
| [`GlyphList.c`](src/ENGINE/uielement_types/GlyphList.c) | 44 | `00472520`–`006EC130` |
| [`UIElement_ColorPicker.c`](src/ENGINE/uielement_types/UIElement_ColorPicker.c) | 37 | `0046AE30`–`0075E310` |
| [`UIElement_Browser.c`](src/ENGINE/uielement_types/UIElement_Browser.c) | 25 | `0046B2B0`–`0075E3E0` |
| [`UIElement_Button.c`](src/ENGINE/uielement_types/UIElement_Button.c) | 22 | `00471B50`–`0075E8C0` |
| [`UIElement_Viewport.c`](src/ENGINE/uielement_types/UIElement_Viewport.c) | 21 | `0046BA70`–`006EBD60` |
| [`UIElement_Meter.c`](src/ENGINE/uielement_types/UIElement_Meter.c) | 20 | `0046F4C0`–`0075E7E0` |
| [`UIElement_Panel.c`](src/ENGINE/uielement_types/UIElement_Panel.c) | 20 | `00429A00`–`006EBD70` |
| [`UIElement_Scrollable.c`](src/ENGINE/uielement_types/UIElement_Scrollable.c) | 19 | `00473D90`–`006EC140` |
| [`UIElement_Dragbar.c`](src/ENGINE/uielement_types/UIElement_Dragbar.c) | 18 | `0046C6F0`–`0075E4E0` |
| [`UIElement_Field.c`](src/ENGINE/uielement_types/UIElement_Field.c) | 14 | `004722B0`–`0075E930` |
| [`UIElement_GroupBox.c`](src/ENGINE/uielement_types/UIElement_GroupBox.c) | 13 | `0046AC00`–`0075E0F0` |
| [`Glyph.c`](src/ENGINE/uielement_types/Glyph.c) | 11 | `004747D0`–`006EC150` |
| [`UIElement_ResizeBar.c`](src/ENGINE/uielement_types/UIElement_ResizeBar.c) | 9 | `0046B780`–`006EBC50` |
| [`StringDownload.c`](src/ENGINE/uielement_types/StringDownload.c) | 4 | `006EC160`–`006EC190` |

### `ENGINE/uielement_util_context` — 2 files, 27 functions

| File | Functions | Address range |
|---|---|---|
| [`ContextMenu.c`](src/ENGINE/uielement_util_context/ContextMenu.c) | 26 | `00474B70`–`0075EBC0` |
| [`ContextMenuData.c`](src/ENGINE/uielement_util_context/ContextMenuData.c) | 1 | `006EC320`–`006EC320` |

### `ENGINE/uielement_util_dialog` — 9 files, 111 functions

| File | Functions | Address range |
|---|---|---|
| [`DialogFactory.c`](src/ENGINE/uielement_util_dialog/DialogFactory.c) | 43 | `00476D50`–`0075ED50` |
| [`Dialog.c`](src/ENGINE/uielement_util_dialog/Dialog.c) | 10 | `00476830`–`006EC3A0` |
| [`ConfirmationDialog.c`](src/ENGINE/uielement_util_dialog/ConfirmationDialog.c) | 9 | `00476400`–`006EC390` |
| [`TextInputDialog.c`](src/ENGINE/uielement_util_dialog/TextInputDialog.c) | 9 | `00474E60`–`006EC340` |
| [`ConfirmationMenuDialog.c`](src/ENGINE/uielement_util_dialog/ConfirmationMenuDialog.c) | 8 | `00475E10`–`006EC380` |
| [`ConfirmationTextInputDialog.c`](src/ENGINE/uielement_util_dialog/ConfirmationTextInputDialog.c) | 8 | `004759A0`–`006EC370` |
| [`MenuDialog.c`](src/ENGINE/uielement_util_dialog/MenuDialog.c) | 8 | `00475450`–`006EC360` |
| [`MessageDialog.c`](src/ENGINE/uielement_util_dialog/MessageDialog.c) | 8 | `00474D10`–`006EC350` |
| [`WaitDialog.c`](src/ENGINE/uielement_util_dialog/WaitDialog.c) | 8 | `00474C60`–`006EC330` |

### `ENGINE/uielement_util_tag` — 6 files, 28 functions

| File | Functions | Address range |
|---|---|---|
| [`TextTag.c`](src/ENGINE/uielement_util_tag/TextTag.c) | 6 | `00478F80`–`00479230` |
| [`TextTag_DID.c`](src/ENGINE/uielement_util_tag/TextTag_DID.c) | 6 | `00478740`–`006EC430` |
| [`TextTag_IID.c`](src/ENGINE/uielement_util_tag/TextTag_IID.c) | 5 | `00478E60`–`00478F60` |
| [`TextTag_IIDEnum.c`](src/ENGINE/uielement_util_tag/TextTag_IIDEnum.c) | 5 | `00478B20`–`00478C30` |
| [`TextTag_IIDString.c`](src/ENGINE/uielement_util_tag/TextTag_IIDString.c) | 5 | `00478840`–`00478910` |
| [`TextTagFactory.c`](src/ENGINE/uielement_util_tag/TextTagFactory.c) | 1 | `00478480`–`00478480` |

### `ENGINE/uiflow` — 2 files, 36 functions

| File | Functions | Address range |
|---|---|---|
| [`UIFlow.c`](src/ENGINE/uiflow/UIFlow.c) | 29 | `004793C0`–`0075EDF0` |
| [`UIPersistantData.c`](src/ENGINE/uiflow/UIPersistantData.c) | 7 | `00479900`–`006EC580` |

### `ENGINE/uiframework` — 3 files, 57 functions

| File | Functions | Address range |
|---|---|---|
| [`UIMainFramework.c`](src/ENGINE/uiframework/UIMainFramework.c) | 30 | `006A0C00`–`00790160` |
| [`UIFramework.c`](src/ENGINE/uiframework/UIFramework.c) | 16 | `006A0910`–`0078FF40` |
| [`GamePlayUI.c`](src/ENGINE/uiframework/GamePlayUI.c) | 11 | `006A0DA0`–`007218A0` |

## `GAME`

Generic game-client scaffolding and the `gm*` user-interface panels.

### `GAME/acclient` — 3 files, 257 functions

| File | Functions | Address range |
|---|---|---|
| [`gmClient.c`](src/GAME/acclient/gmClient.c) | 203 | `004015D0`–`00725A90` |
| [`main.c`](src/GAME/acclient/main.c) | 37 | `00401000`–`00724ED0` |
| [`BillingMigration.c`](src/GAME/acclient/BillingMigration.c) | 17 | `00404940`–`004050A0` |

### `GAME/game_cdatabase` — 1 files, 23 functions

| File | Functions | Address range |
|---|---|---|
| [`gmCLCache.c`](src/GAME/game_cdatabase/gmCLCache.c) | 23 | `0058A860`–`0070A080` |

### `GAME/game_cevents` — 25 files, 757 functions

| File | Functions | Address range |
|---|---|---|
| [`CM_Character.c`](src/GAME/game_cevents/CM_Character.c) | 63 | `006A0E20`–`007219F0` |
| [`CM_Qualities.c`](src/GAME/game_cevents/CM_Qualities.c) | 59 | `006AE600`–`00722F90` |
| [`CM_Communication.c`](src/GAME/game_cevents/CM_Communication.c) | 52 | `006A3A20`–`00721C90` |
| [`CM_House.c`](src/GAME/game_cevents/CM_House.c) | 51 | `006AA320`–`00722810` |
| [`CM_Allegiance.c`](src/GAME/game_cevents/CM_Allegiance.c) | 49 | `006A6920`–`00722080` |
| [`CM_Magic.c`](src/GAME/game_cevents/CM_Magic.c) | 44 | `006A2F20`–`00721B40` |
| [`CM_Trade.c`](src/GAME/game_cevents/CM_Trade.c) | 42 | `006ACDF0`–`00722BA0` |
| [`CM_Fellowship.c`](src/GAME/game_cevents/CM_Fellowship.c) | 37 | `006A5E80`–`00721F30` |
| [`CM_Admin.c`](src/GAME/game_cevents/CM_Admin.c) | 36 | `006AD910`–`00722E40` |
| [`CM_Social.c`](src/GAME/game_cevents/CM_Social.c) | 36 | `006A54C0`–`00721DE0` |
| [`CM_Game.c`](src/GAME/game_cevents/CM_Game.c) | 35 | `006A88F0`–`00722430` |
| [`CM_UI.c`](src/GAME/game_cevents/CM_UI.c) | 35 | `00479A90`–`006EC620` |
| [`CM_Inventory.c`](src/GAME/game_cevents/CM_Inventory.c) | 30 | `006AB830`–`00722960` |
| [`CM_Item.c`](src/GAME/game_cevents/CM_Item.c) | 26 | `006A84A0`–`007222E0` |
| [`CM_Combat.c`](src/GAME/game_cevents/CM_Combat.c) | 25 | `006A99A0`–`00722620` |
| [`CM_Physics.c`](src/GAME/game_cevents/CM_Physics.c) | 22 | `006AC6A0`–`00722A50` |
| [`CM_Misc.c`](src/GAME/game_cevents/CM_Misc.c) | 21 | `006AF4E0`–`007230E0` |
| [`CM_Login.c`](src/GAME/game_cevents/CM_Login.c) | 17 | `006AD810`–`00722CF0` |
| [`CM_Writing.c`](src/GAME/game_cevents/CM_Writing.c) | 17 | `006A9230`–`007224D0` |
| [`CM_Movement.c`](src/GAME/game_cevents/CM_Movement.c) | 12 | `006AF790`–`007232A0` |
| [`CM_Train.c`](src/GAME/game_cevents/CM_Train.c) | 12 | `006A7F30`–`00722120` |
| [`CM_Vendor.c`](src/GAME/game_cevents/CM_Vendor.c) | 12 | `006AA000`–`007226C0` |
| [`CM_Examine.c`](src/GAME/game_cevents/CM_Examine.c) | 10 | `006AF640`–`00723180` |
| [`CM_CharGen.c`](src/GAME/game_cevents/CM_CharGen.c) | 9 | `006AF740`–`00723230` |
| [`CM_Advocate.c`](src/GAME/game_cevents/CM_Advocate.c) | 5 | `006A83C0`–`00722190` |

### `GAME/game_cmessage` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`gmGlobalEventHandler.c`](src/GAME/game_cmessage/gmGlobalEventHandler.c) | 2 | `0047A3F0`–`0047A420` |

### `GAME/game_database` — 1 files, 6 functions

| File | Functions | Address range |
|---|---|---|
| [`gmMasterDBMap.c`](src/GAME/game_database/gmMasterDBMap.c) | 6 | `005D5980`–`007104D0` |

### `GAME/game_ui_misc` — 103 files, 4,640 functions

| File | Functions | Address range |
|---|---|---|
| [`gmConfigUI.c`](src/GAME/game_ui_misc/gmConfigUI.c) | 161 | `0049E2C0`–`00760BE0` |
| [`PlayerOptionPage.c`](src/GAME/game_ui_misc/PlayerOptionPage.c) | 137 | `004F2680`–`00764790` |
| [`gmSmartBoxUI.c`](src/GAME/game_ui_misc/gmSmartBoxUI.c) | 123 | `004D60C0`–`00762640` |
| [`gmExaminationUI.c`](src/GAME/game_ui_misc/gmExaminationUI.c) | 119 | `004AB1B0`–`00761190` |
| [`gmVendorUI.c`](src/GAME/game_ui_misc/gmVendorUI.c) | 113 | `004C0210`–`007614F0` |
| [`gmBarberUI.c`](src/GAME/game_ui_misc/gmBarberUI.c) | 109 | `004DE140`–`006F60B0` |
| [`gmKeyboardUI.c`](src/GAME/game_ui_misc/gmKeyboardUI.c) | 105 | `00448B90`–`00762AE0` |
| [`gmRadarUI.c`](src/GAME/game_ui_misc/gmRadarUI.c) | 101 | `004D7530`–`007628A0` |
| [`ChatInterface.c`](src/GAME/game_ui_misc/ChatInterface.c) | 92 | `004F2F10`–`00764B40` |
| [`gmChatUI.c`](src/GAME/game_ui_misc/gmChatUI.c) | 90 | `004CCCC0`–`00761980` |
| [`gmMiniGameUI.c`](src/GAME/game_ui_misc/gmMiniGameUI.c) | 89 | `004A7B20`–`006F1560` |
| [`gmJournalUI.c`](src/GAME/game_ui_misc/gmJournalUI.c) | 85 | `004949C0`–`0075FC20` |
| [`UIElement_ItemList.c`](src/GAME/game_ui_misc/UIElement_ItemList.c) | 81 | `004E24A0`–`00763110` |
| [`gmContractsUI.c`](src/GAME/game_ui_misc/gmContractsUI.c) | 81 | `004979A0`–`0075FD10` |
| [`gmGamePlayUI.c`](src/GAME/game_ui_misc/gmGamePlayUI.c) | 80 | `004E9C60`–`00763A00` |
| [`gmFellowshipUI.c`](src/GAME/game_ui_misc/gmFellowshipUI.c) | 79 | `0048E310`–`0075F840` |
| [`UIOption_ActionKeyMap.c`](src/GAME/game_ui_misc/UIOption_ActionKeyMap.c) | 76 | `00431590`–`006EDA40` |
| [`gmAllegianceUI.c`](src/GAME/game_ui_misc/gmAllegianceUI.c) | 74 | `004908B0`–`0075F8F0` |
| [`gmChatOptionsUI.c`](src/GAME/game_ui_misc/gmChatOptionsUI.c) | 74 | `0049ED80`–`006F0800` |
| [`gmToolbarUI.c`](src/GAME/game_ui_misc/gmToolbarUI.c) | 65 | `004BD0C0`–`007613C0` |
| [`gmSpellcastingUI.c`](src/GAME/game_ui_misc/gmSpellcastingUI.c) | 64 | `004C5810`–`007615A0` |
| [`gmSecureTradeUI.c`](src/GAME/game_ui_misc/gmSecureTradeUI.c) | 62 | `004C9650`–`006F2DC0` |
| [`gmCharacterInfoUI.c`](src/GAME/game_ui_misc/gmCharacterInfoUI.c) | 61 | `004B86F0`–`006F1FC0` |
| [`gmPaperDollUI.c`](src/GAME/game_ui_misc/gmPaperDollUI.c) | 59 | `004A3550`–`00760E30` |
| [`gmCGAppearancePage.c`](src/GAME/game_ui_misc/gmCGAppearancePage.c) | 56 | `0047C7D0`–`006ECE80` |
| [`gmSlumlordUI.c`](src/GAME/game_ui_misc/gmSlumlordUI.c) | 55 | `004C7C70`–`006F2C30` |
| [`gmUIFlow.c`](src/GAME/game_ui_misc/gmUIFlow.c) | 54 | `0047A460`–`0075EFD0` |
| [`UIOption_Menu.c`](src/GAME/game_ui_misc/UIOption_Menu.c) | 53 | `00483C60`–`0075F3A0` |
| [`gmSpellbookUI.c`](src/GAME/game_ui_misc/gmSpellbookUI.c) | 52 | `0048AE20`–`0075F630` |
| [`gmSquelchUI.c`](src/GAME/game_ui_misc/gmSquelchUI.c) | 52 | `0048C100`–`0075F6E0` |
| [`UIElement_UIItem.c`](src/GAME/game_ui_misc/UIElement_UIItem.c) | 49 | `004E0F40`–`00763060` |
| [`gmPageListUI.c`](src/GAME/game_ui_misc/gmPageListUI.c) | 48 | `00493140`–`0075F990` |
| [`gmSkillUI.c`](src/GAME/game_ui_misc/gmSkillUI.c) | 48 | `0049ADB0`–`006EF240` |
| [`gmSpellComponentUI.c`](src/GAME/game_ui_misc/gmSpellComponentUI.c) | 48 | `00489B90`–`006EDC70` |
| [`InfoRegion.c`](src/GAME/game_ui_misc/InfoRegion.c) | 47 | `004F0E70`–`006F7E60` |
| [`gmCGSkillsPage.c`](src/GAME/game_ui_misc/gmCGSkillsPage.c) | 47 | `00480360`–`006ECFD0` |
| [`gmEffectsUI.c`](src/GAME/game_ui_misc/gmEffectsUI.c) | 47 | `0044A630`–`006F1AE0` |
| [`gmCharacterManagementUI.c`](src/GAME/game_ui_misc/gmCharacterManagementUI.c) | 46 | `004EBF60`–`006F74C0` |
| [`gmFriendsUI.c`](src/GAME/game_ui_misc/gmFriendsUI.c) | 46 | `0048D060`–`0075F790` |
| [`VividTargetInd.c`](src/GAME/game_ui_misc/VividTargetInd.c) | 45 | `004F5CE0`–`006F91C0` |
| [`gmDataPatchUI.c`](src/GAME/game_ui_misc/gmDataPatchUI.c) | 44 | `004EDE30`–`00763B90` |
| [`gmHouseUI.c`](src/GAME/game_ui_misc/gmHouseUI.c) | 44 | `004A25A0`–`006F0C10` |
| [`gmStatManagementUI.c`](src/GAME/game_ui_misc/gmStatManagementUI.c) | 44 | `004EFBE0`–`006F7D40` |
| [`UIElement_SmartBoxWrapper.c`](src/GAME/game_ui_misc/UIElement_SmartBoxWrapper.c) | 43 | `004E5120`–`007631C0` |
| [`gmBookUI.c`](src/GAME/game_ui_misc/gmBookUI.c) | 42 | `004BAA50`–`006F2110` |
| [`gmCharGenMainUI.c`](src/GAME/game_ui_misc/gmCharGenMainUI.c) | 42 | `004E79F0`–`007634D0` |
| [`gmSalvageUI.c`](src/GAME/game_ui_misc/gmSalvageUI.c) | 41 | `004CAF40`–`006F2F10` |
| [`gmCharacterTitleUI.c`](src/GAME/game_ui_misc/gmCharacterTitleUI.c) | 39 | `0049A500`–`0075FDC0` |
| [`UIOption_CheckboxBitfield64.c`](src/GAME/game_ui_misc/UIOption_CheckboxBitfield64.c) | 36 | `00485660`–`006ED610` |
| [`UIOption_Slider.c`](src/GAME/game_ui_misc/UIOption_Slider.c) | 34 | `00484A50`–`006ED570` |
| [`gmAbuseUI.c`](src/GAME/game_ui_misc/gmAbuseUI.c) | 34 | `004BBEB0`–`006F22E0` |
| [`gmAttributeUI.c`](src/GAME/game_ui_misc/gmAttributeUI.c) | 34 | `0049C9D0`–`006EF440` |
| [`gmCGProfessionPage.c`](src/GAME/game_ui_misc/gmCGProfessionPage.c) | 34 | `00481EA0`–`006ED120` |
| [`gmLinkStatusUI.c`](src/GAME/game_ui_misc/gmLinkStatusUI.c) | 33 | `004AAD10`–`006F1790` |
| [`gmMapUI.c`](src/GAME/game_ui_misc/gmMapUI.c) | 33 | `004A1870`–`00760D30` |
| [`gmExternalContainerUI.c`](src/GAME/game_ui_misc/gmExternalContainerUI.c) | 32 | `004CBA20`–`006F3060` |
| [`gmGameplayOptionsUI.c`](src/GAME/game_ui_misc/gmGameplayOptionsUI.c) | 31 | `0049E030`–`00760030` |
| [`UIOption.c`](src/GAME/game_ui_misc/UIOption.c) | 30 | `004EF1E0`–`006F7B20` |
| [`UIOption_Checkbox.c`](src/GAME/game_ui_misc/UIOption_Checkbox.c) | 30 | `004868A0`–`006ED750` |
| [`gmEnvPanelUI.c`](src/GAME/game_ui_misc/gmEnvPanelUI.c) | 30 | `0044DF70`–`006F3300` |
| [`gmEpilogueUI.c`](src/GAME/game_ui_misc/gmEpilogueUI.c) | 29 | `004E9B00`–`007636E0` |
| [`gmInventoryUI.c`](src/GAME/game_ui_misc/gmInventoryUI.c) | 28 | `004A6670`–`006F0EC0` |
| [`gmSpewBoxUI.c`](src/GAME/game_ui_misc/gmSpewBoxUI.c) | 28 | `004D57C0`–`00761DA0` |
| [`UIOption_CheckBoxSlider.c`](src/GAME/game_ui_misc/UIOption_CheckBoxSlider.c) | 27 | `00484610`–`006ED4D0` |
| [`gmCGSummaryPage.c`](src/GAME/game_ui_misc/gmCGSummaryPage.c) | 27 | `0047AC70`–`006ECC10` |
| [`gmFloatyChatUI.c`](src/GAME/game_ui_misc/gmFloatyChatUI.c) | 26 | `004CE280`–`006F3C80` |
| [`gmFloatyIndicatorsUI.c`](src/GAME/game_ui_misc/gmFloatyIndicatorsUI.c) | 26 | `004D2EB0`–`006F4460` |
| [`gmFloatyPowerBarUI.c`](src/GAME/game_ui_misc/gmFloatyPowerBarUI.c) | 26 | `004D0BC0`–`006F4100` |
| [`gmFloatyToolbarUI.c`](src/GAME/game_ui_misc/gmFloatyToolbarUI.c) | 26 | `004CF380`–`006F3EC0` |
| [`gmFloatyVitalsUI.c`](src/GAME/game_ui_misc/gmFloatyVitalsUI.c) | 26 | `004CEBB0`–`006F3DA0` |
| [`gmPanelUI.c`](src/GAME/game_ui_misc/gmPanelUI.c) | 26 | `004BC670`–`006F2430` |
| [`gmVitaeUI.c`](src/GAME/game_ui_misc/gmVitaeUI.c) | 26 | `004A7240`–`006F12C0` |
| [`gmBackpackUI.c`](src/GAME/game_ui_misc/gmBackpackUI.c) | 25 | `004A6D70`–`00760F20` |
| [`gmCombatUI.c`](src/GAME/game_ui_misc/gmCombatUI.c) | 25 | `004CC000`–`006F31B0` |
| [`gmFloatyExaminationUI.c`](src/GAME/game_ui_misc/gmFloatyExaminationUI.c) | 25 | `004D3BB0`–`006F4580` |
| [`gmUIElement_LinkStatusIndicator.c`](src/GAME/game_ui_misc/gmUIElement_LinkStatusIndicator.c) | 25 | `004E6510`–`006F68A0` |
| [`gmCG3DView.c`](src/GAME/game_ui_misc/gmCG3DView.c) | 24 | `004EE590`–`006F79D0` |
| [`gmCGHeritagePage.c`](src/GAME/game_ui_misc/gmCGHeritagePage.c) | 24 | `004830A0`–`006ED270` |
| [`gmFloatyEnvPanelUI.c`](src/GAME/game_ui_misc/gmFloatyEnvPanelUI.c) | 24 | `004D47D0`–`006F46A0` |
| [`gmFloatyMainChatUI.c`](src/GAME/game_ui_misc/gmFloatyMainChatUI.c) | 24 | `004D22B0`–`006F4340` |
| [`gmCGTownPage.c`](src/GAME/game_ui_misc/gmCGTownPage.c) | 23 | `0047C0D0`–`006ECD30` |
| [`gmCombatPanelUI.c`](src/GAME/game_ui_misc/gmCombatPanelUI.c) | 23 | `004F5900`–`006F8E00` |
| [`gmPowerbarUI.c`](src/GAME/game_ui_misc/gmPowerbarUI.c) | 23 | `004DA3A0`–`006F5770` |
| [`gmCreditsUI.c`](src/GAME/game_ui_misc/gmCreditsUI.c) | 22 | `004E6E10`–`007633C0` |
| [`gmDisconnectedUI.c`](src/GAME/game_ui_misc/gmDisconnectedUI.c) | 22 | `004E9970`–`007635D0` |
| [`gmUrgentAssistanceUI.c`](src/GAME/game_ui_misc/gmUrgentAssistanceUI.c) | 22 | `004A7810`–`006F1410` |
| [`gm3DItemsUI.c`](src/GAME/game_ui_misc/gm3DItemsUI.c) | 21 | `004A70A0`–`00760FC0` |
| [`gmFloatyPanelUI.c`](src/GAME/game_ui_misc/gmFloatyPanelUI.c) | 21 | `004D18C0`–`006F4220` |
| [`gmVitalsUI.c`](src/GAME/game_ui_misc/gmVitalsUI.c) | 21 | `004BFB20`–`006F27C0` |
| [`gmAdminQualitiesUI.c`](src/GAME/game_ui_misc/gmAdminQualitiesUI.c) | 20 | `004CCBE0`–`006F3450` |
| [`gmCharacterSettingsUI.c`](src/GAME/game_ui_misc/gmCharacterSettingsUI.c) | 20 | `004A01A0`–`006F0960` |
| [`gmFloatySideVitalsUI.c`](src/GAME/game_ui_misc/gmFloatySideVitalsUI.c) | 20 | `004D0170`–`006F3FE0` |
| [`gmFloatyCombatPanelUI.c`](src/GAME/game_ui_misc/gmFloatyCombatPanelUI.c) | 19 | `004D5390`–`006F47C0` |
| [`UIOption_CheckboxBitfield.c`](src/GAME/game_ui_misc/UIOption_CheckboxBitfield.c) | 17 | `00486340`–`006ED6B0` |
| [`gmUIElement_PortalStormIndicator.c`](src/GAME/game_ui_misc/gmUIElement_PortalStormIndicator.c) | 17 | `004E6100`–`006F66B0` |
| [`gmIntroUI.c`](src/GAME/game_ui_misc/gmIntroUI.c) | 16 | `004ED9F0`–`006F7560` |
| [`gmUIElement_BurdenIndicator.c`](src/GAME/game_ui_misc/gmUIElement_BurdenIndicator.c) | 16 | `004E6B40`–`006F69E0` |
| [`gmUIElement_EffectsIndicator.c`](src/GAME/game_ui_misc/gmUIElement_EffectsIndicator.c) | 16 | `004E68A0`–`006F6940` |
| [`OptionPage.c`](src/GAME/game_ui_misc/OptionPage.c) | 15 | `004F2C60`–`006F8840` |
| [`gmUIElement_VitaeIndicator.c`](src/GAME/game_ui_misc/gmUIElement_VitaeIndicator.c) | 15 | `004E5E60`–`006F6610` |
| [`gmIndicatorsUI.c`](src/GAME/game_ui_misc/gmIndicatorsUI.c) | 14 | `004BF990`–`006F26C0` |
| [`gmUIElement_MiniGameIndicator.c`](src/GAME/game_ui_misc/gmUIElement_MiniGameIndicator.c) | 14 | `004E6350`–`006F6750` |
| [`UIGlobals.c`](src/GAME/game_ui_misc/UIGlobals.c) | 3 | `004EE470`–`004EE540` |

## `AC`

Asheron's Call specific gameplay — qualities, spells, combat, allegiance, chat, trade, housing.

### `AC/acallegiance` — 5 files, 79 functions

| File | Functions | Address range |
|---|---|---|
| [`AllegianceHierarchy.c`](src/AC/acallegiance/AllegianceHierarchy.c) | 29 | `0041BC20`–`0070E750` |
| [`AllegianceSystem.c`](src/AC/acallegiance/AllegianceSystem.c) | 18 | `005B7BC0`–`005B8DD0` |
| [`AllegianceProfile.c`](src/AC/acallegiance/AllegianceProfile.c) | 16 | `005B6A20`–`0070E6E0` |
| [`AllegianceData.c`](src/AC/acallegiance/AllegianceData.c) | 12 | `005B6530`–`005B6950` |
| [`AllegianceNode.c`](src/AC/acallegiance/AllegianceNode.c) | 4 | `005B8FF0`–`005B9040` |

### `AC/acappraisal` — 5 files, 72 functions

| File | Functions | Address range |
|---|---|---|
| [`AppraisalProfile.c`](src/AC/acappraisal/AppraisalProfile.c) | 41 | `00525C70`–`005B4100` |
| [`AppraisalSystem.c`](src/AC/acappraisal/AppraisalSystem.c) | 15 | `005B4200`–`005B5AE0` |
| [`CreatureAppraisalProfile.c`](src/AC/acappraisal/CreatureAppraisalProfile.c) | 8 | `005B5D20`–`005B6190` |
| [`HookAppraisalProfile.c`](src/AC/acappraisal/HookAppraisalProfile.c) | 5 | `005B64B0`–`005B64F0` |
| [`WeaponProfile.c`](src/AC/acappraisal/WeaponProfile.c) | 3 | `005B62C0`–`005B63C0` |

### `AC/acbody` — 6 files, 24 functions

| File | Functions | Address range |
|---|---|---|
| [`BodyPart.c`](src/AC/acbody/BodyPart.c) | 14 | `00421F50`–`00710480` |
| [`Body.c`](src/AC/acbody/Body.c) | 3 | `005CB130`–`00710410` |
| [`ArmorCache.c`](src/AC/acbody/ArmorCache.c) | 2 | `005D14B0`–`005D1540` |
| [`ArmorProfile.c`](src/AC/acbody/ArmorProfile.c) | 2 | `005D0DC0`–`005D0E40` |
| [`BodyPartSelectionData.c`](src/AC/acbody/BodyPartSelectionData.c) | 2 | `005D15E0`–`005D1690` |
| [`BodyPartIDEnumMap.c`](src/AC/acbody/BodyPartIDEnumMap.c) | 1 | `005D0EC0`–`005D0EC0` |

### `AC/acbook` — 1 files, 20 functions

| File | Functions | Address range |
|---|---|---|
| [`PageData.c`](src/AC/acbook/PageData.c) | 20 | `00426670`–`005D26A0` |

### `AC/accallegiance` — 2 files, 8 functions

| File | Functions | Address range |
|---|---|---|
| [`CAllegianceProfile.c`](src/AC/accallegiance/CAllegianceProfile.c) | 6 | `005990E0`–`0070AEA0` |
| [`CAllegianceData.c`](src/AC/accallegiance/CAllegianceData.c) | 2 | `005990A0`–`005990C0` |

### `AC/accfactory` — 1 files, 28 functions

| File | Functions | Address range |
|---|---|---|
| [`ACCFactory.c`](src/AC/accfactory/ACCFactory.c) | 28 | `00557300`–`00707C00` |

### `AC/accfellowship` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`CFellowship.c`](src/AC/accfellowship/CFellowship.c) | 2 | `0059A570`–`0059A590` |

### `AC/acchannel` — 1 files, 24 functions

| File | Functions | Address range |
|---|---|---|
| [`ChannelSystem.c`](src/AC/acchannel/ChannelSystem.c) | 24 | `005CF1F0`–`00778DF0` |

### `AC/accharacter` — 4 files, 304 functions

| File | Functions | Address range |
|---|---|---|
| [`ACCharGenData.c`](src/AC/accharacter/ACCharGenData.c) | 195 | `004169B0`–`0070F4D0` |
| [`CharGenState.c`](src/AC/accharacter/CharGenState.c) | 77 | `00487880`–`0070F580` |
| [`ACCharGenResult.c`](src/AC/accharacter/ACCharGenResult.c) | 25 | `0049B620`–`0070F630` |
| [`CharacterTitleTable.c`](src/AC/accharacter/CharacterTitleTable.c) | 7 | `005C6E20`–`0070F590` |

### `AC/accmagic` — 2 files, 58 functions

| File | Functions | Address range |
|---|---|---|
| [`CSpellTable.c`](src/AC/accmagic/CSpellTable.c) | 42 | `00427010`–`0070AD50` |
| [`CSpellBase.c`](src/AC/accmagic/CSpellBase.c) | 16 | `00596A50`–`0070AD40` |

### `AC/accmdinterp` — 1 files, 40 functions

| File | Functions | Address range |
|---|---|---|
| [`ACCmdInterp.c`](src/AC/accmdinterp/ACCmdInterp.c) | 40 | `0043C580`–`0070A780` |

### `AC/accobject` — 1 files, 148 functions

| File | Functions | Address range |
|---|---|---|
| [`ACCWeenieObj.c`](src/AC/accobject/ACCWeenieObj.c) | 148 | `004F80B0`–`00774B00` |

### `AC/accobjmaint` — 1 files, 113 functions

| File | Functions | Address range |
|---|---|---|
| [`ACCObjMaint.c`](src/AC/accobjmaint/ACCObjMaint.c) | 113 | `00557660`–`00707D50` |

### `AC/accplayer` — 2 files, 27 functions

| File | Functions | Address range |
|---|---|---|
| [`CPlayerModule.c`](src/AC/accplayer/CPlayerModule.c) | 26 | `005269F0`–`0070B1C0` |
| [`CShortCutData.c`](src/AC/accplayer/CShortCutData.c) | 1 | `0059A5B0`–`0059A5B0` |

### `AC/accqualities` — 9 files, 292 functions

| File | Functions | Address range |
|---|---|---|
| [`CBaseQualitiesStats.c`](src/AC/accqualities/CBaseQualitiesStats.c) | 72 | `005692B0`–`0070AAF0` |
| [`CACQualitiesData.c`](src/AC/accqualities/CACQualitiesData.c) | 45 | `0058EEB0`–`0070AA80` |
| [`CEnchantmentRegistry.c`](src/AC/accqualities/CEnchantmentRegistry.c) | 41 | `00593970`–`0070ABE0` |
| [`CACQualitiesSkills.c`](src/AC/accqualities/CACQualitiesSkills.c) | 39 | `00591960`–`0070AB60` |
| [`CACQualities.c`](src/AC/accqualities/CACQualities.c) | 24 | `00592D10`–`0070ABD0` |
| [`CEmoteTable.c`](src/AC/accqualities/CEmoteTable.c) | 20 | `00594E20`–`0070AC50` |
| [`CEmoteSet.c`](src/AC/accqualities/CEmoteSet.c) | 19 | `005962F0`–`0070AD30` |
| [`CSpellBook.c`](src/AC/accqualities/CSpellBook.c) | 18 | `005954A0`–`00595C10` |
| [`CBaseQualities.c`](src/AC/accqualities/CBaseQualities.c) | 14 | `00569830`–`0070ACC0` |

### `AC/accquest` — 5 files, 60 functions

| File | Functions | Address range |
|---|---|---|
| [`CContractTable.c`](src/AC/accquest/CContractTable.c) | 19 | `004D88D0`–`0070B000` |
| [`CQuestDefDB.c`](src/AC/accquest/CQuestDefDB.c) | 17 | `005992E0`–`0070AF90` |
| [`CContract.c`](src/AC/accquest/CContract.c) | 10 | `00599FE0`–`0070B070` |
| [`CContractTracker.c`](src/AC/accquest/CContractTracker.c) | 9 | `00599120`–`0070AF10` |
| [`CContractTrackerTable.c`](src/AC/accquest/CContractTrackerTable.c) | 5 | `005992B0`–`0070AF80` |

### `AC/accshopsystem` — 1 files, 3 functions

| File | Functions | Address range |
|---|---|---|
| [`CShopSystem.c`](src/AC/accshopsystem/CShopSystem.c) | 3 | `006B6120`–`00724110` |

### `AC/accspells` — 8 files, 58 functions

| File | Functions | Address range |
|---|---|---|
| [`CSpell.c`](src/AC/accspells/CSpell.c) | 19 | `00423E90`–`0070ADC0` |
| [`CEnchantmentSpell.c`](src/AC/accspells/CEnchantmentSpell.c) | 9 | `00598B10`–`00598D60` |
| [`CPortalSendingSpell.c`](src/AC/accspells/CPortalSendingSpell.c) | 8 | `00598A90`–`0070AE30` |
| [`CProjectileSpell.c`](src/AC/accspells/CProjectileSpell.c) | 7 | `00598DE0`–`00598F00` |
| [`CDispelSpell.c`](src/AC/accspells/CDispelSpell.c) | 5 | `005989D0`–`00598A70` |
| [`CPortalSummonSpell.c`](src/AC/accspells/CPortalSummonSpell.c) | 5 | `00598F20`–`00598FD0` |
| [`CBoostSpell.c`](src/AC/accspells/CBoostSpell.c) | 4 | `00598DA0`–`00599060` |
| [`CTransferSpell.c`](src/AC/accspells/CTransferSpell.c) | 1 | `00599080`–`00599080` |

### `AC/accui_gameplay` — 2 files, 71 functions

| File | Functions | Address range |
|---|---|---|
| [`ComponentTracker.c`](src/AC/accui_gameplay/ComponentTracker.c) | 38 | `0042D780`–`00709C50` |
| [`Items.c`](src/AC/accui_gameplay/Items.c) | 33 | `00586E90`–`00709DA0` |

### `AC/accui_misc` — 15 files, 993 functions

| File | Functions | Address range |
|---|---|---|
| [`CommunicationSystem.c`](src/AC/accui_misc/CommunicationSystem.c) | 277 | `0056E290`–`007740B0` |
| [`PlayerSystem.c`](src/AC/accui_misc/PlayerSystem.c) | 127 | `0055D3E0`–`00773460` |
| [`UI.c`](src/AC/accui_misc/UI.c) | 104 | `00563F90`–`00773860` |
| [`CombatSystem.c`](src/AC/accui_misc/CombatSystem.c) | 92 | `0056A400`–`00773BC0` |
| [`APIManager.c`](src/AC/accui_misc/APIManager.c) | 66 | `00526800`–`007731B0` |
| [`MagicSystem.c`](src/AC/accui_misc/MagicSystem.c) | 62 | `00566E60`–`00708B10` |
| [`FellowshipSystem.c`](src/AC/accui_misc/FellowshipSystem.c) | 44 | `00569060`–`00708C60` |
| [`TradeSystem.c`](src/AC/accui_misc/TradeSystem.c) | 44 | `00508970`–`00709310` |
| [`UIQueueManager.c`](src/AC/accui_misc/UIQueueManager.c) | 41 | `00402480`–`00708160` |
| [`HousingSystem.c`](src/AC/accui_misc/HousingSystem.c) | 30 | `005858A0`–`00709B40` |
| [`AllegianceSystem.c`](src/AC/accui_misc/AllegianceSystem.c) | 26 | `00569F90`–`00708DB0` |
| [`MiniGameSystem.c`](src/AC/accui_misc/MiniGameSystem.c) | 26 | `00585650`–`007099F0` |
| [`AdminSystem.c`](src/AC/accui_misc/AdminSystem.c) | 23 | `006B5E60`–`007911D0` |
| [`ClientSystem.c`](src/AC/accui_misc/ClientSystem.c) | 16 | `00563C50`–`00708660` |
| [`CCharGenState.c`](src/AC/accui_misc/CCharGenState.c) | 15 | `005638C0`–`00708510` |

### `AC/acemote` — 1 files, 13 functions

| File | Functions | Address range |
|---|---|---|
| [`Emote.c`](src/AC/acemote/Emote.c) | 13 | `005CDA00`–`007100F0` |

### `AC/acfellowship` — 3 files, 37 functions

| File | Functions | Address range |
|---|---|---|
| [`Fellowship.c`](src/AC/acfellowship/Fellowship.c) | 21 | `005B9070`–`0070E7C0` |
| [`Fellow.c`](src/AC/acfellowship/Fellow.c) | 10 | `005B98A0`–`0070E830` |
| [`FellowshipSystem.c`](src/AC/acfellowship/FellowshipSystem.c) | 6 | `005B9B80`–`0070E8A0` |

### `AC/acfriends` — 1 files, 7 functions

| File | Functions | Address range |
|---|---|---|
| [`FriendData.c`](src/AC/acfriends/FriendData.c) | 7 | `005B9C30`–`005B9E80` |

### `AC/acgameplay_misc` — 13 files, 197 functions

| File | Functions | Address range |
|---|---|---|
| [`ExperienceTable.c`](src/AC/acgameplay_misc/ExperienceTable.c) | 27 | `004BFBF0`–`0070FCB0` |
| [`TinkeringSystem.c`](src/AC/acgameplay_misc/TinkeringSystem.c) | 26 | `00598C30`–`0070FB10` |
| [`ExperienceSystem.c`](src/AC/acgameplay_misc/ExperienceSystem.c) | 24 | `005C8100`–`0070F700` |
| [`SkillSystem.c`](src/AC/acgameplay_misc/SkillSystem.c) | 21 | `005C86E0`–`0070F7D0` |
| [`CombatManeuverTable.c`](src/AC/acgameplay_misc/CombatManeuverTable.c) | 18 | `004CBAC0`–`0070FD80` |
| [`GameMoveData.c`](src/AC/acgameplay_misc/GameMoveData.c) | 12 | `006B7660`–`00724A00` |
| [`CombatManeuver.c`](src/AC/acgameplay_misc/CombatManeuver.c) | 11 | `005CA7B0`–`0070FF20` |
| [`CombatSystem.c`](src/AC/acgameplay_misc/CombatSystem.c) | 11 | `005C9020`–`0070FA40` |
| [`CombatEnumMap.c`](src/AC/acgameplay_misc/CombatEnumMap.c) | 10 | `005C9B80`–`0070FBE0` |
| [`VitaeSystem.c`](src/AC/acgameplay_misc/VitaeSystem.c) | 10 | `005C8FD0`–`0070F8A0` |
| [`Chess.c`](src/AC/acgameplay_misc/Chess.c) | 9 | `0070F8B0`–`0070F970` |
| [`StatIDEnumMap.c`](src/AC/acgameplay_misc/StatIDEnumMap.c) | 9 | `0070FD90`–`0070FE50` |
| [`WClassIDEnumMap.c`](src/AC/acgameplay_misc/WClassIDEnumMap.c) | 9 | `00724870`–`00724930` |

### `AC/acgenerator` — 6 files, 57 functions

| File | Functions | Address range |
|---|---|---|
| [`GeneratorTable.c`](src/AC/acgenerator/GeneratorTable.c) | 14 | `005D0090`–`007102A0` |
| [`GeneratorQueue.c`](src/AC/acgenerator/GeneratorQueue.c) | 13 | `004C0910`–`00710380` |
| [`GeneratorRegistry.c`](src/AC/acgenerator/GeneratorRegistry.c) | 12 | `00497F90`–`00710310` |
| [`GeneratorProfile.c`](src/AC/acgenerator/GeneratorProfile.c) | 8 | `005D08F0`–`007103F0` |
| [`GeneratorQueueNode.c`](src/AC/acgenerator/GeneratorQueueNode.c) | 5 | `005B6490`–`005D0D80` |
| [`GeneratorRegistryNode.c`](src/AC/acgenerator/GeneratorRegistryNode.c) | 5 | `005D0B90`–`00710400` |

### `AC/achouse` — 4 files, 56 functions

| File | Functions | Address range |
|---|---|---|
| [`HousePayment.c`](src/AC/achouse/HousePayment.c) | 21 | `005BA5E0`–`0070E8B0` |
| [`HouseProfile.c`](src/AC/achouse/HouseProfile.c) | 18 | `005BB770`–`0070E9A0` |
| [`HouseData.c`](src/AC/achouse/HouseData.c) | 11 | `005BB460`–`0070E930` |
| [`HouseSystem.c`](src/AC/achouse/HouseSystem.c) | 6 | `005BB1D0`–`0070E8C0` |

### `AC/acmagic` — 7 files, 111 functions

| File | Functions | Address range |
|---|---|---|
| [`SpellComponentTable.c`](src/AC/acmagic/SpellComponentTable.c) | 29 | `004E5E90`–`0070EB40` |
| [`SpellFormula.c`](src/AC/acmagic/SpellFormula.c) | 22 | `005BC880`–`0070EC10` |
| [`SpellSet.c`](src/AC/acmagic/SpellSet.c) | 16 | `005BD0D0`–`0070EE80` |
| [`SpellComponentBase.c`](src/AC/acmagic/SpellComponentBase.c) | 13 | `005BBD20`–`0070EA70` |
| [`MagicSystem.c`](src/AC/acmagic/MagicSystem.c) | 11 | `005BD240`–`0070EF50` |
| [`SpellIDEnumMap.c`](src/AC/acmagic/SpellIDEnumMap.c) | 10 | `00508960`–`0070EDB0` |
| [`StatMod.c`](src/AC/acmagic/StatMod.c) | 10 | `005BD090`–`0070ECE0` |

### `AC/acplayermod` — 3 files, 167 functions

| File | Functions | Address range |
|---|---|---|
| [`PlayerModule.c`](src/AC/acplayermod/PlayerModule.c) | 154 | `00401C80`–`007104C0` |
| [`ShortCutManager.c`](src/AC/acplayermod/ShortCutManager.c) | 8 | `005D5660`–`005D5880` |
| [`ShortCutData.c`](src/AC/acplayermod/ShortCutData.c) | 5 | `005C9830`–`005D5620` |

### `AC/acqualities` — 13 files, 110 functions

| File | Functions | Address range |
|---|---|---|
| [`ACQualityFilter.c`](src/AC/acqualities/ACQualityFilter.c) | 19 | `00450470`–`00710010` |
| [`SkillTable.c`](src/AC/acqualities/SkillTable.c) | 15 | `004E6380`–`00710000` |
| [`AttributeCache.c`](src/AC/acqualities/AttributeCache.c) | 13 | `005CC440`–`005CD4D0` |
| [`Enchantment.c`](src/AC/acqualities/Enchantment.c) | 12 | `005CACE0`–`0070FFD0` |
| [`Skill.c`](src/AC/acqualities/Skill.c) | 12 | `005CA940`–`0070FFC0` |
| [`CreationProfile.c`](src/AC/acqualities/CreationProfile.c) | 9 | `005CC2C0`–`00710080` |
| [`Attribute2ndTable.c`](src/AC/acqualities/Attribute2ndTable.c) | 8 | `004E65A0`–`0070FFF0` |
| [`GenericQualitiesData.c`](src/AC/acqualities/GenericQualitiesData.c) | 8 | `006B7800`–`006B7B90` |
| [`SecondaryAttribute.c`](src/AC/acqualities/SecondaryAttribute.c) | 4 | `005CAC40`–`005CAC90` |
| [`Attribute.c`](src/AC/acqualities/Attribute.c) | 3 | `005CAB90`–`005CABF0` |
| [`SkillBase.c`](src/AC/acqualities/SkillBase.c) | 3 | `005CB190`–`0070FFE0` |
| [`SkillFormula.c`](src/AC/acqualities/SkillFormula.c) | 2 | `005CA870`–`005CA8D0` |
| [`SpellBookPage.c`](src/AC/acqualities/SpellBookPage.c) | 2 | `005CC230`–`005CC260` |

### `AC/acquest` — 2 files, 11 functions

| File | Functions | Address range |
|---|---|---|
| [`QuestDefDB.c`](src/AC/acquest/QuestDefDB.c) | 8 | `004BF9F0`–`007104B0` |
| [`QuestDef.c`](src/AC/acquest/QuestDef.c) | 3 | `005D2740`–`005D2810` |

### `AC/acshop` — 2 files, 21 functions

| File | Functions | Address range |
|---|---|---|
| [`VendorProfile.c`](src/AC/acshop/VendorProfile.c) | 11 | `005D1A90`–`007104A0` |
| [`ItemProfile.c`](src/AC/acshop/ItemProfile.c) | 10 | `005D1750`–`00710490` |

### `AC/acsmartbox` — 1 files, 15 functions

| File | Functions | Address range |
|---|---|---|
| [`ACSmartBox.c`](src/AC/acsmartbox/ACSmartBox.c) | 15 | `00559570`–`00707E60` |

### `AC/actrade` — 1 files, 18 functions

| File | Functions | Address range |
|---|---|---|
| [`Trade.c`](src/AC/actrade/Trade.c) | 18 | `005B9EF0`–`005BA5B0` |

### `AC/actreasure` — 1 files, 1 functions

| File | Functions | Address range |
|---|---|---|
| [`MaterialTypeEnumMap.c`](src/AC/actreasure/MaterialTypeEnumMap.c) | 1 | `005CD500`–`005CD500` |

### `AC/acweenie_net` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`ACWTimeStamper.c`](src/AC/acweenie_net/ACWTimeStamper.c) | 2 | `005BD3A0`–`005BD3C0` |

### `AC/game_cchat` — 1 files, 80 functions

| File | Functions | Address range |
|---|---|---|
| [`gmCCommunicationSystem.c`](src/AC/game_cchat/gmCCommunicationSystem.c) | 80 | `00589000`–`007742E0` |

### `AC/turbinechat` — 2 files, 18 functions

| File | Functions | Address range |
|---|---|---|
| [`ChatRoomTracker.c`](src/AC/turbinechat/ChatRoomTracker.c) | 15 | `00489D70`–`006BC230` |
| [`TurbineChatBlob.c`](src/AC/turbinechat/TurbineChatBlob.c) | 3 | `00502730`–`005CD9E0` |

## `CORE`

Shared Turbine core utilities (serialization, string, containers) from a separate source tree (`d:\core\core_dev`).

### `CORE/core_utils` — 6 files, 89 functions

| File | Functions | Address range |
|---|---|---|
| [`ArgParser.c`](src/CORE/core_utils/ArgParser.c) | 72 | `00407250`–`0065E6C0` |
| [`ColorPrintF.c`](src/CORE/core_utils/ColorPrintF.c) | 7 | `0040FBC0`–`0040FFE0` |
| [`reg_edit.c`](src/CORE/core_utils/reg_edit.c) | 5 | `0040DDC0`–`0040DF80` |
| [`strtoint64.c`](src/CORE/core_utils/strtoint64.c) | 3 | `0065CB80`–`0065CE50` |
| [`Checksum.c`](src/CORE/core_utils/Checksum.c) | 1 | `0065F6A0`–`0065F6A0` |
| [`Resource.c`](src/CORE/core_utils/Resource.c) | 1 | `00410DC0`–`00410DC0` |

### `CORE/cryptosystem` — 1 files, 11 functions

| File | Functions | Address range |
|---|---|---|
| [`CryptoSystem.c`](src/CORE/cryptosystem/CryptoSystem.c) | 11 | `0065F700`–`0065FF40` |

### `CORE/dbghelpwrapper` — 1 files, 10 functions

| File | Functions | Address range |
|---|---|---|
| [`DbgHelpWrapper.c`](src/CORE/dbghelpwrapper/DbgHelpWrapper.c) | 10 | `0040E520`–`006C3B10` |

### `CORE/debug_common` — 4 files, 48 functions

| File | Functions | Address range |
|---|---|---|
| [`Debug.c`](src/CORE/debug_common/Debug.c) | 24 | `00405AE0`–`00725B20` |
| [`DialogBoxGateway.c`](src/CORE/debug_common/DialogBoxGateway.c) | 12 | `0040E200`–`00725DA0` |
| [`CrashCleaners.c`](src/CORE/debug_common/CrashCleaners.c) | 10 | `0040DFE0`–`00725D90` |
| [`ReportContext.c`](src/CORE/debug_common/ReportContext.c) | 2 | `0040E450`–`0040E470` |

### `CORE/debug_instance` — 1 files, 2 functions

| File | Functions | Address range |
|---|---|---|
| [`DebugInstance.c`](src/CORE/debug_instance/DebugInstance.c) | 2 | `006C3B40`–`00725E50` |

### `CORE/error` — 2 files, 55 functions

| File | Functions | Address range |
|---|---|---|
| [`Logger.c`](src/CORE/error/Logger.c) | 47 | `0040E580`–`00725E40` |
| [`IError.c`](src/CORE/error/IError.c) | 8 | `00659EF0`–`00714B90` |

### `CORE/falloc` — 1 files, 4 functions

| File | Functions | Address range |
|---|---|---|
| [`falloc.c`](src/CORE/falloc/falloc.c) | 4 | `0065FFB0`–`00660170` |

### `CORE/mathlib` — 5 files, 19 functions

| File | Functions | Address range |
|---|---|---|
| [`Matrix4.c`](src/CORE/mathlib/Matrix4.c) | 10 | `0065CE70`–`0065D760` |
| [`RGBAColor.c`](src/CORE/mathlib/RGBAColor.c) | 4 | `0065B360`–`0065B4E0` |
| [`Heading.c`](src/CORE/mathlib/Heading.c) | 2 | `00714C40`–`00714CA0` |
| [`Vector3.c`](src/CORE/mathlib/Vector3.c) | 2 | `0065B6E0`–`0065B750` |
| [`Vector2.c`](src/CORE/mathlib/Vector2.c) | 1 | `0065D890`–`0065D890` |

### `CORE/newthread` — 4 files, 16 functions

| File | Functions | Address range |
|---|---|---|
| [`PortalThread.c`](src/CORE/newthread/PortalThread.c) | 6 | `0065D960`–`0065DA90` |
| [`SharedCritSec.c`](src/CORE/newthread/SharedCritSec.c) | 5 | `0065D8B0`–`0065D930` |
| [`PortalEvent.c`](src/CORE/newthread/PortalEvent.c) | 4 | `0065DAE0`–`0065DB30` |
| [`PortalDumpErr.c`](src/CORE/newthread/PortalDumpErr.c) | 1 | `006601F0`–`006601F0` |

### `CORE/perfmon_app` — 4 files, 56 functions

| File | Functions | Address range |
|---|---|---|
| [`PerfMonCounterManager.c`](src/CORE/perfmon_app/PerfMonCounterManager.c) | 26 | `00682F20`–`0077F670` |
| [`PerfMonCounterInfo.c`](src/CORE/perfmon_app/PerfMonCounterInfo.c) | 18 | `00682A80`–`007155B0` |
| [`PerfMonInstaller.c`](src/CORE/perfmon_app/PerfMonInstaller.c) | 9 | `007156E0`–`007157A0` |
| [`PerfMonRpc_s.c`](src/CORE/perfmon_app/PerfMonRpc_s.c) | 3 | `006836E0`–`00683A50` |

### `CORE/pstring` — 2 files, 85 functions

| File | Functions | Address range |
|---|---|---|
| [`PSUtils.c`](src/CORE/pstring/PSUtils.c) | 77 | `0040AD50`–`00725D60` |
| [`PStringDecls.c`](src/CORE/pstring/PStringDecls.c) | 8 | `006C3960`–`00725C10` |

### `CORE/rpcserv` — 2 files, 13 functions

| File | Functions | Address range |
|---|---|---|
| [`rpcserv.c`](src/CORE/rpcserv/rpcserv.c) | 11 | `006B9B20`–`00724AD0` |
| [`rpcutil.c`](src/CORE/rpcserv/rpcutil.c) | 2 | `006B9BF0`–`006B9C10` |

### `CORE/serialize` — 7 files, 208 functions

| File | Functions | Address range |
|---|---|---|
| [`FileNodeName.c`](src/CORE/serialize/FileNodeName.c) | 65 | `00659F90`–`0077EDB0` |
| [`PFileNode.c`](src/CORE/serialize/PFileNode.c) | 55 | `0065B7F0`–`0077EDF0` |
| [`Archive.c`](src/CORE/serialize/Archive.c) | 34 | `0040A570`–`006C39E0` |
| [`SmartBuffer.c`](src/CORE/serialize/SmartBuffer.c) | 23 | `00406A60`–`00725C40` |
| [`ArchiveVersionStack.c`](src/CORE/serialize/ArchiveVersionStack.c) | 19 | `00410560`–`006C3B60` |
| [`ArchiveVersionRow.c`](src/CORE/serialize/ArchiveVersionRow.c) | 9 | `00410050`–`00410430` |
| [`VersionedArchive.c`](src/CORE/serialize/VersionedArchive.c) | 3 | `0065D7D0`–`00714C30` |

### `CORE/statemachine` — 1 files, 56 functions

| File | Functions | Address range |
|---|---|---|
| [`AsyncState.c`](src/CORE/statemachine/AsyncState.c) | 56 | `0065DB50`–`0065F660` |

### `CORE/tcom_interface` — 2 files, 27 functions

| File | Functions | Address range |
|---|---|---|
| [`InterfaceSystem.c`](src/CORE/tcom_interface/InterfaceSystem.c) | 25 | `00406090`–`00725B50` |
| [`Turbine_GUID.c`](src/CORE/tcom_interface/Turbine_GUID.c) | 2 | `0040FA70`–`0040FB20` |

### `CORE/timer` — 2 files, 12 functions

| File | Functions | Address range |
|---|---|---|
| [`Timer.c`](src/CORE/timer/Timer.c) | 8 | `0040F7D0`–`0040FA10` |
| [`TimeSource.c`](src/CORE/timer/TimeSource.c) | 4 | `00410DE0`–`00410F20` |

## `_other`

Modules whose object path did not follow the standard `output\obj\LAYER\lib` shape.

### `_other/misc` — 3 files, 130 functions

| File | Functions | Address range |
|---|---|---|
| [`SoftwareBlit.c`](src/_other/misc/SoftwareBlit.c) | 117 | `00660220`–`0066FEA0` |
| [`PCH_PortalPrecomp.c`](src/_other/misc/PCH_PortalPrecomp.c) | 9 | `006C2B70`–`006C2C30` |
| [`comraise.c`](src/_other/misc/comraise.c) | 4 | `005DE710`–`005DE7C0` |

## `_runtime`

Statically linked third-party code with no module records: **D3DX9**, the MSVC 7.0 CRT, and the Intel JPEG Library. Recovered by public symbol name, not by module.

### `_runtime/d3dx9` — 1 files, 663 functions

| File | Functions | Address range |
|---|---|---|
| [`d3dx9.c`](src/_runtime/d3dx9/d3dx9.c) | 663 | `005DEA1E`–`00611BF9` |

### `_runtime/intel_jpeg` — 11 files, 77 functions

| File | Functions | Address range |
|---|---|---|
| [`intel_jpeg.c`](src/_runtime/intel_jpeg/intel_jpeg.c) | 64 | `00614C60`–`0064C230` |
| [`atonexit.c`](src/_runtime/intel_jpeg/atonexit.c) | 2 | `005DDFF0`–`005DE016` |
| [`ehvecdtr.c`](src/_runtime/intel_jpeg/ehvecdtr.c) | 2 | `005DE4B0`–`005DE50E` |
| [`initsect.c`](src/_runtime/intel_jpeg/initsect.c) | 2 | `005DE600`–`005DE644` |
| [`crtexew.c`](src/_runtime/intel_jpeg/crtexew.c) | 1 | `005DE03A`–`005DE03A` |
| [`fp8.c`](src/_runtime/intel_jpeg/fp8.c) | 1 | `005DE68E`–`005DE68E` |
| [`merr.c`](src/_runtime/intel_jpeg/merr.c) | 1 | `005DE6A0`–`005DE6A0` |
| [`newop_s.c`](src/_runtime/intel_jpeg/newop_s.c) | 1 | `005DDFC5`–`005DDFC5` |
| [`seccinit.c`](src/_runtime/intel_jpeg/seccinit.c) | 1 | `006B7DCC`–`006B7DCC` |
| [`seccook.c`](src/_runtime/intel_jpeg/seccook.c) | 1 | `006B7CC2`–`006B7CC2` |
| [`ti_inst.c`](src/_runtime/intel_jpeg/ti_inst.c) | 1 | `006B7C70`–`006B7C70` |

### `_runtime/msvcrt` — 40 files, 109 functions

| File | Functions | Address range |
|---|---|---|
| [`failure.c`](src/_runtime/msvcrt/failure.c) | 21 | `004058B3`–`00405ACE` |
| [`amdmath.c`](src/_runtime/msvcrt/amdmath.c) | 19 | `00614000`–`00614AC0` |
| [`trees.c`](src/_runtime/msvcrt/trees.c) | 15 | `00611D94`–`00613031` |
| [`resolve.c`](src/_runtime/msvcrt/resolve.c) | 8 | `00405285`–`00405760` |
| [`deflate.c`](src/_runtime/msvcrt/deflate.c) | 6 | `00601CBB`–`00602387` |
| [`d3dxvec2.c`](src/_runtime/msvcrt/d3dxvec2.c) | 3 | `00609000`–`006094C0` |
| [`d3dxvec3.c`](src/_runtime/msvcrt/d3dxvec3.c) | 3 | `0060A000`–`0060A3C0` |
| [`d3dxfloat16.c`](src/_runtime/msvcrt/d3dxfloat16.c) | 2 | `00611000`–`00611140` |
| [`adler32.c`](src/_runtime/msvcrt/adler32.c) | 1 | `00611C77`–`00611C77` |
| [`d3dxplane.c`](src/_runtime/msvcrt/d3dxplane.c) | 1 | `00607000`–`00607000` |
| [`d3dxvec4.c`](src/_runtime/msvcrt/d3dxvec4.c) | 1 | `00608000`–`00608000` |
| [`thunk_advapi32_RegCreateKeyExW.c`](src/_runtime/msvcrt/thunk_advapi32_RegCreateKeyExW.c) | 1 | `006B7FEC`–`006B7FEC` |
| [`thunk_advapi32_RegEnumValueW.c`](src/_runtime/msvcrt/thunk_advapi32_RegEnumValueW.c) | 1 | `006B7FC7`–`006B7FC7` |
| [`thunk_advapi32_RegOpenKeyExW.c`](src/_runtime/msvcrt/thunk_advapi32_RegOpenKeyExW.c) | 1 | `005DE8B9`–`005DE8B9` |
| [`thunk_advapi32_RegQueryValueExW.c`](src/_runtime/msvcrt/thunk_advapi32_RegQueryValueExW.c) | 1 | `005DE894`–`005DE894` |
| [`thunk_advapi32_RegSetValueExW.c`](src/_runtime/msvcrt/thunk_advapi32_RegSetValueExW.c) | 1 | `006B7FA2`–`006B7FA2` |
| [`thunk_gdi32_CreateFontIndirectW.c`](src/_runtime/msvcrt/thunk_gdi32_CreateFontIndirectW.c) | 1 | `006B7F58`–`006B7F58` |
| [`thunk_gdi32_ExtTextOutW.c`](src/_runtime/msvcrt/thunk_gdi32_ExtTextOutW.c) | 1 | `006B7F7D`–`006B7F7D` |
| [`thunk_gdi32_GetCharacterPlacementW.c`](src/_runtime/msvcrt/thunk_gdi32_GetCharacterPlacementW.c) | 1 | `006B7F0E`–`006B7F0E` |
| [`thunk_gdi32_GetObjectW.c`](src/_runtime/msvcrt/thunk_gdi32_GetObjectW.c) | 1 | `006B7EE9`–`006B7EE9` |
| [`thunk_gdi32_GetTextMetricsW.c`](src/_runtime/msvcrt/thunk_gdi32_GetTextMetricsW.c) | 1 | `006B7F33`–`006B7F33` |
| [`thunk_kernel32_CreateDirectoryW.c`](src/_runtime/msvcrt/thunk_kernel32_CreateDirectoryW.c) | 1 | `005DE825`–`005DE825` |
| [`thunk_kernel32_CreateFileW.c`](src/_runtime/msvcrt/thunk_kernel32_CreateFileW.c) | 1 | `006B7E30`–`006B7E30` |
| [`thunk_kernel32_DeleteFileW.c`](src/_runtime/msvcrt/thunk_kernel32_DeleteFileW.c) | 1 | `006B7E7A`–`006B7E7A` |
| [`thunk_kernel32_FindResourceW.c`](src/_runtime/msvcrt/thunk_kernel32_FindResourceW.c) | 1 | `006B7E55`–`006B7E55` |
| [`thunk_kernel32_GetCurrentDirectoryW.c`](src/_runtime/msvcrt/thunk_kernel32_GetCurrentDirectoryW.c) | 1 | `005DE86F`–`005DE86F` |
| [`thunk_kernel32_GetEnvironmentVariableW.c`](src/_runtime/msvcrt/thunk_kernel32_GetEnvironmentVariableW.c) | 1 | `005DE84A`–`005DE84A` |
| [`thunk_kernel32_GetProcAddress.c`](src/_runtime/msvcrt/thunk_kernel32_GetProcAddress.c) | 1 | `005DE8DE`–`005DE8DE` |
| [`thunk_kernel32_GetTempFileNameW.c`](src/_runtime/msvcrt/thunk_kernel32_GetTempFileNameW.c) | 1 | `006B7EC4`–`006B7EC4` |
| [`thunk_kernel32_MoveFileW.c`](src/_runtime/msvcrt/thunk_kernel32_MoveFileW.c) | 1 | `006B7E9F`–`006B7E9F` |
| [`thunk_kernel32_MultiByteToWideChar.c`](src/_runtime/msvcrt/thunk_kernel32_MultiByteToWideChar.c) | 1 | `00405260`–`00405260` |
| [`thunk_kernel32_WideCharToMultiByte.c`](src/_runtime/msvcrt/thunk_kernel32_WideCharToMultiByte.c) | 1 | `005DE800`–`005DE800` |
| [`thunk_kernel32_lstrcatW.c`](src/_runtime/msvcrt/thunk_kernel32_lstrcatW.c) | 1 | `006C2AC5`–`006C2AC5` |
| [`thunk_kernel32_lstrlenW.c`](src/_runtime/msvcrt/thunk_kernel32_lstrlenW.c) | 1 | `005DE9BC`–`005DE9BC` |
| [`thunk_user32_GetClipboardData.c`](src/_runtime/msvcrt/thunk_user32_GetClipboardData.c) | 1 | `005DE94D`–`005DE94D` |
| [`thunk_user32_IsClipboardFormatAvailable.c`](src/_runtime/msvcrt/thunk_user32_IsClipboardFormatAvailable.c) | 1 | `005DE972`–`005DE972` |
| [`thunk_user32_MessageBoxW.c`](src/_runtime/msvcrt/thunk_user32_MessageBoxW.c) | 1 | `005DE997`–`005DE997` |
| [`thunk_user32_SetWindowLongA.c`](src/_runtime/msvcrt/thunk_user32_SetWindowLongA.c) | 1 | `005DE928`–`005DE928` |
| [`thunk_user32_wsprintfW.c`](src/_runtime/msvcrt/thunk_user32_wsprintfW.c) | 1 | `006C2AA0`–`006C2AA0` |
| [`thunk_version_VerQueryValueW.c`](src/_runtime/msvcrt/thunk_version_VerQueryValueW.c) | 1 | `005DE903`–`005DE903` |

### `_runtime/static_libs` — 1 files, 376 functions

| File | Functions | Address range |
|---|---|---|
| [`static_libs.c`](src/_runtime/static_libs/static_libs.c) | 376 | `005DF170`–`006C2B5A` |

