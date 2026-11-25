/* N2KFusionTypes.h
 *
 * Copyright (c) 2024 Andreas Zogg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

/*************************************************************************//**
 * \file  N2KFusionTypes.h
 * \brief Fusion Electronics NMEA 2000 lookup types.
 *
 * Values are based on the Canboat PGN documentation:
 * https://canboat.github.io/canboat/canboat.html
 */

#ifndef _N2KFUSIONTYPES_h
#define _N2KFUSIONTYPES_h

enum tN2kFusionCommand {
    N2kFusionCommandPlay = 1,
    N2kFusionCommandPause = 2,
    N2kFusionCommandNext = 4,
    N2kFusionCommandPrev = 6
};

enum tN2kFusionLowPassFilter {
    N2kFusionLowPassFilter50Hz = 1,
    N2kFusionLowPassFilter80Hz = 2,
    N2kFusionLowPassFilter120Hz = 3,
    N2kFusionLowPassFilter160Hz = 4
};

enum tN2kFusionMenuAction {
    N2kFusionMenuActionOpen = 1,
    N2kFusionMenuActionSelect = 2,
    N2kFusionMenuActionStepBack = 3,
    N2kFusionMenuActionClose = 4,
    N2kFusionMenuActionExit = 5
};

enum tN2kFusionMenuStatus {
    N2kFusionMenuStatusOpenedAtRoot = 1,
    N2kFusionMenuStatusOpened = 2,
    N2kFusionMenuStatusItemUpdated = 3,
    N2kFusionMenuStatusClosed = 4,
    N2kFusionMenuStatusLocked = 5
};

enum tN2kFusionMessageId {
    N2kFusionMessageIdRequestStatus = 1,
    N2kFusionMessageIdSetSource = 2,
    N2kFusionMessageIdMediaCommand = 3,
    N2kFusionMessageIdTunerCommand = 5,
    N2kFusionMessageIdMarineTunerCommand = 6,
    N2kFusionMessageIdSetMarineTunerSquelch = 7,
    N2kFusionMessageIdSetMarineTunerScanMode = 8,
    N2kFusionMessageIdMenuAction = 9,
    N2kFusionMessageIdRequestMenuCount = 10,
    N2kFusionMessageIdRequestMenuItem = 11,
    N2kFusionMessageIdRequestMenuLockID = 12,
    N2kFusionMessageIdSetAuxGain = 13,
    N2kFusionMessageIdSetSettings = 15,
    N2kFusionMessageIdDABUpdateCommand = 16,
    N2kFusionMessageIdSetMute = 17,
    N2kFusionMessageIdSetBalance = 18,
    N2kFusionMessageIdSetLowPassFilter = 19,
    N2kFusionMessageIdSetSublevel = 20,
    N2kFusionMessageIdSetAllSublevels = 21,
    N2kFusionMessageIdSetEqualizer = 22,
    N2kFusionMessageIdSetVolumeLimit = 23,
    N2kFusionMessageIdSetZoneVolume = 24,
    N2kFusionMessageIdSetAllVolumes = 25,
    N2kFusionMessageIdSetLineLevelControl = 27,
    N2kFusionMessageIdPower = 28,
    N2kFusionMessageIdSetDeviceName = 29,
    N2kFusionMessageIdSendSiriusCommand = 30,
    N2kFusionMessageIdSetSiriusParental = 31,
    N2kFusionMessageIdSendFactoryResetCommand = 33,
    N2kFusionMessageIdSetZoneName = 34,
    N2kFusionMessageIdSendDVDCommand = 35,
    N2kFusionMessageIdDVDPressIRKey = 36,
    N2kFusionMessageIdSendSelectSiriusTeam = 39,
    N2kFusionMessageIdSendSelectSiriusArtist = 40,
    N2kFusionMessageIdSendSiriusSportAlertUserAction = 41,
    N2kFusionMessageIdSendSiriusArtistSongUserAction = 45,
    N2kFusionMessageIdSendMultiroomCommand = 50,
    N2kFusionMessageIdGetMultiroomDeviceRecord = 51,
    N2kFusionMessageIdScanMultiroomDevices = 52,
    N2kFusionMessageIdSendFileTransfer = 53,
    N2kFusionMessageIdSetLoud = 54,
    N2kFusionMessageIdSetSourceMultiroomEnabled = 56,
    N2kFusionMessageIdRequestHeadUnitDSPSettings = 57,
    N2kFusionMessageIdSendTransferStatus = 64,
    N2kFusionMessageIdGetServerInfo = 65,
    N2kFusionMessageIdSetSourceEnabled = 69,
    N2kFusionMessageIdSetSourceName = 70,
    N2kFusionMessageIdSendExternalAmpGain = 73,
    N2kFusionMessageIdSendInternalAmpGain = 74,
    N2kFusionMessageIdSendMono = 75
};

enum tN2kFusionMuteCommand {
    N2kFusionMuteCommandMuteOn = 1,
    N2kFusionMuteCommandMuteOff = 2
};

enum tN2kFusionPlayStatus {
    N2kFusionPlayStatusInvalid = 0,
    N2kFusionPlayStatusPlaying = 1,
    N2kFusionPlayStatusPaused = 2,
    N2kFusionPlayStatusStopped = 3,
    N2kFusionPlayStatusSkipForward = 4,
    N2kFusionPlayStatusSkipRewind = 5
};

enum tN2kFusionPowerState {
    N2kFusionPowerStateOn = 1,
    N2kFusionPowerStateOff = 2
};

enum tN2kFusionRadioSource {
    N2kFusionRadioSourceAM = 0,
    N2kFusionRadioSourceFM = 1
};

enum tN2kFusionRepeatStatus {
    N2kFusionRepeatStatusOff = 0,
    N2kFusionRepeatStatusOneTrack = 1,
    N2kFusionRepeatStatusAllAlbum = 2
};

enum tN2kFusionSetting {
    N2kFusionSettingAlphaSearchThreshold = 0,
    N2kFusionSettingIPodSubtitles = 1,
    N2kFusionSettingZone2Linked = 2,
    N2kFusionSettingZone2Enabled = 3,
    N2kFusionSettingZone3Enabled = 4,
    N2kFusionSettingZone4Enabled = 5,
    N2kFusionSettingTelemute = 6,
    N2kFusionSettingTunerRegion = 7,
    N2kFusionSettingMarineZone = 8,
    N2kFusionSettingUSBRepeat = 9,
    N2kFusionSettingUSBShuffle = 10,
    N2kFusionSettingIPodAlbumArtwork = 11,
    N2kFusionSettingIPodRepeat = 12,
    N2kFusionSettingIPodShuffle = 13,
    N2kFusionSettingAMPreset0 = 14,
    N2kFusionSettingAMPreset1 = 15,
    N2kFusionSettingAMPreset2 = 16,
    N2kFusionSettingAMPreset3 = 17,
    N2kFusionSettingAMPreset4 = 18,
    N2kFusionSettingAMPreset5 = 19,
    N2kFusionSettingAMPreset6 = 20,
    N2kFusionSettingAMPreset7 = 21,
    N2kFusionSettingAMPreset8 = 22,
    N2kFusionSettingAMPreset9 = 23,
    N2kFusionSettingAMPreset10 = 24,
    N2kFusionSettingAMPreset11 = 25,
    N2kFusionSettingAMPreset12 = 26,
    N2kFusionSettingAMPreset13 = 27,
    N2kFusionSettingAMPreset14 = 28,
    N2kFusionSettingFMPreset0 = 29,
    N2kFusionSettingFMPreset1 = 30,
    N2kFusionSettingFMPreset2 = 31,
    N2kFusionSettingFMPreset3 = 32,
    N2kFusionSettingFMPreset4 = 33,
    N2kFusionSettingFMPreset5 = 34,
    N2kFusionSettingFMPreset6 = 35,
    N2kFusionSettingFMPreset7 = 36,
    N2kFusionSettingFMPreset8 = 37,
    N2kFusionSettingFMPreset9 = 38,
    N2kFusionSettingFMPreset10 = 39,
    N2kFusionSettingFMPreset11 = 40,
    N2kFusionSettingFMPreset12 = 41,
    N2kFusionSettingFMPreset13 = 42,
    N2kFusionSettingFMPreset14 = 43,
    N2kFusionSettingVHFPreset0 = 44,
    N2kFusionSettingVHFPreset1 = 45,
    N2kFusionSettingVHFPreset2 = 46,
    N2kFusionSettingVHFPreset3 = 47,
    N2kFusionSettingVHFPreset4 = 48,
    N2kFusionSettingVHFPreset5 = 49,
    N2kFusionSettingVHFPreset6 = 50,
    N2kFusionSettingVHFPreset7 = 51,
    N2kFusionSettingVHFPreset8 = 52,
    N2kFusionSettingVHFPreset9 = 53,
    N2kFusionSettingVHFPreset10 = 54,
    N2kFusionSettingVHFPreset11 = 55,
    N2kFusionSettingVHFPreset12 = 56,
    N2kFusionSettingVHFPreset13 = 57,
    N2kFusionSettingVHFPreset14 = 58,
    N2kFusionSettingClockTime = 59,
    N2kFusionSettingClockAlarm = 60,
    N2kFusionSettingIPodVideoSignal = 61,
    N2kFusionSettingIPodMonitorAspect = 62,
    N2kFusionSettingAuxNameIndex = 63,
    N2kFusionSettingAMEnabled = 64,
    N2kFusionSettingVHFEnabled = 65,
    N2kFusionSettingLanguage = 66,
    N2kFusionSettingInternalAmpsOn = 67,
    N2kFusionSettingMTPRepeat = 68,
    N2kFusionSettingMTPShuffle = 69,
    N2kFusionSettingIDAccessorySource = 70,
    N2kFusionSettingNMEAPower = 71,
    N2kFusionSettingLowPowerMode = 72,
    N2kFusionSettingDVDRegion = 73,
    N2kFusionSettingVolumeZoneSync = 74,
    N2kFusionSettingMaxVolumeStart = 76,
    N2kFusionSettingBTAutoConnect = 77,
    N2kFusionSettingTunerAntennasPowerStatus = 79,
    N2kFusionSettingFMAntennaIndex = 80,
    N2kFusionSettingDABAntennaIndex = 81,
    N2kFusionSettingDABServiceFollowing = 82,
    N2kFusionSettingFMFrequencyFollowing = 83,
    N2kFusionSettingDABFMServiceFollowing = 115,
    N2kFusionSettingHDMIVolumeZoneSync = 125,
    N2kFusionSettingARCInputAudioDelay = 126,
    N2kFusionSettingNullSetting = 1000
};

enum tN2kFusionSiriusCommand {
    N2kFusionSiriusCommandNext = 1,
    N2kFusionSiriusCommandPrev = 2
};

enum tN2kFusionSiriusComState {
    N2kFusionSiriusComStateUnknown = 255,
    N2kFusionSiriusComStateOff = 1,
    N2kFusionSiriusComStateInitialising = 2,
    N2kFusionSiriusComStateOn = 3
};

enum tN2kFusionSiriusTuningMode {
    N2kFusionSiriusTuningModeNormal = 1,
    N2kFusionSiriusTuningModeCategory = 2,
    N2kFusionSiriusTuningModePreset = 3
};

enum tN2kFusionSourceType {
    N2kFusionSourceTypeAM = 0,
    N2kFusionSourceTypeFM = 1,
    N2kFusionSourceTypeAux = 2,
    N2kFusionSourceTypeSirius = 3,
    N2kFusionSourceTypeIPod = 4,
    N2kFusionSourceTypeUSB = 5,
    N2kFusionSourceTypeDVD = 6,
    N2kFusionSourceTypeVHF = 7,
    N2kFusionSourceTypeInvalid = 8,
    N2kFusionSourceTypeMTP = 9,
    N2kFusionSourceTypeBluetooth = 10,
    N2kFusionSourceTypeARC = 11,
    N2kFusionSourceTypeAndroid = 12,
    N2kFusionSourceTypePandora = 13,
    N2kFusionSourceTypeDAB = 14,
    N2kFusionSourceTypeAirPlay = 15,
    N2kFusionSourceTypeUPNP = 16,
    N2kFusionSourceTypeUnknown = 17
};

enum tN2kFusionStatusMessageId {
    N2kFusionStatusMessageIdUnknown = 0,
    N2kFusionStatusMessageIdAPIVersion = 32769,
    N2kFusionStatusMessageIdSource = 32770,
    N2kFusionStatusMessageIdSourceCount = 32771,
    N2kFusionStatusMessageIdTrackInfo = 32772,
    N2kFusionStatusMessageIdTrackTitle = 32773,
    N2kFusionStatusMessageIdTrackArtist = 32774,
    N2kFusionStatusMessageIdTrackAlbum = 32775,
    N2kFusionStatusMessageIdCoverArt = 32776,
    N2kFusionStatusMessageIdTrackProgress = 32777,
    N2kFusionStatusMessageIdTunerAlign = 32778,
    N2kFusionStatusMessageIdTuner = 32779,
    N2kFusionStatusMessageIdMarineTuner = 32780,
    N2kFusionStatusMessageIdMarineSquelch = 32781,
    N2kFusionStatusMessageIdMarineScanMode = 32782,
    N2kFusionStatusMessageIdMenuAction = 32783,
    N2kFusionStatusMessageIdMenuCount = 32784,
    N2kFusionStatusMessageIdMenuItem = 32785,
    N2kFusionStatusMessageIdMenuLockID = 32786,
    N2kFusionStatusMessageIdAuxGain = 32787,
    N2kFusionStatusMessageIdSetting = 32788,
    N2kFusionStatusMessageIdSettings = 32789,
    N2kFusionStatusMessageIdUpdateFirmwareResult = 32790,
    N2kFusionStatusMessageIdMute = 32791,
    N2kFusionStatusMessageIdBalance = 32792,
    N2kFusionStatusMessageIdLowPassFilter = 32793,
    N2kFusionStatusMessageIdSublevels = 32794,
    N2kFusionStatusMessageIdTone = 32795,
    N2kFusionStatusMessageIdVolumeLimits = 32796,
    N2kFusionStatusMessageIdVolume = 32797,
    N2kFusionStatusMessageIdCapabilities = 32798,
    N2kFusionStatusMessageIdLineLevelControl = 32799,
    N2kFusionStatusMessageIdPower = 32800,
    N2kFusionStatusMessageIdUnitName = 32801,
    N2kFusionStatusMessageIdSirius = 32802,
    N2kFusionStatusMessageIdSiriusXMPresetEvent = 32803,
    N2kFusionStatusMessageIdSiriusXMChannel = 32804,
    N2kFusionStatusMessageIdSiriusXMTitle = 32805,
    N2kFusionStatusMessageIdSiriusXMArtist = 32806,
    N2kFusionStatusMessageIdSiriusXMGenre = 32807,
    N2kFusionStatusMessageIdSiriusXMCategory = 32808,
    N2kFusionStatusMessageIdSiriusXMSignal = 32809,
    N2kFusionStatusMessageIdSiriusXMParentalRequest = 32810,
    N2kFusionStatusMessageIdSiriusXMDiagnostics = 32811,
    N2kFusionStatusMessageIdSiriusXMPresets = 32812,
    N2kFusionStatusMessageIdZoneName = 32813,
    N2kFusionStatusMessageIdDVDState = 32814,
    N2kFusionStatusMessageIdDVDTrack = 32815,
    N2kFusionStatusMessageIdDVDTrackPosition = 32816,
    N2kFusionStatusMessageIdDVDTrackName = 32817,
    N2kFusionStatusMessageIdDVDArtistName = 32818,
    N2kFusionStatusMessageIdIPSetting = 32819,
    N2kFusionStatusMessageIdMediaLoadingProgress = 32820,
    N2kFusionStatusMessageIdMediaUserNotification = 32821,
    N2kFusionStatusMessageIdSystemAlert = 32822,
    N2kFusionStatusMessageIdMultiroom = 32824,
    N2kFusionStatusMessageIdMultiroomStatus = 32825,
    N2kFusionStatusMessageIdMultiroomDeviceCount = 32826,
    N2kFusionStatusMessageIdMultiroomDeviceRecord = 32827,
    N2kFusionStatusMessageIdSystemCapabilities = 32829,
    N2kFusionStatusMessageIdPartNumber = 32830,
    N2kFusionStatusMessageIdLoudness = 32831,
    N2kFusionStatusMessageIdProcessingBypass = 32832,
    N2kFusionStatusMessageIdReceivedFileCount = 32833,
    N2kFusionStatusMessageIdReceivedFileTransfer = 32834,
    N2kFusionStatusMessageIdSiriusXMReplayIndicator = 32835,
    N2kFusionStatusMessageIdSiriusXMTeamInfo = 32837,
    N2kFusionStatusMessageIdSiriusXMTeamEvent = 32838,
    N2kFusionStatusMessageIdSiriusXMArtistSongInfo = 32839,
    N2kFusionStatusMessageIdSiriusXMArtistSongEvent = 32840,
    N2kFusionStatusMessageIdSiriusXMSportAlert = 32841,
    N2kFusionStatusMessageIdSiriusXMArtistSongAlert = 32842,
    N2kFusionStatusMessageIdSiriusXMTunemixChanged = 32843,
    N2kFusionStatusMessageIdSiriusXMTunemix = 32844,
    N2kFusionStatusMessageIdServerInfo = 32846,
    N2kFusionStatusMessageIdRDSData = 32850,
    N2kFusionStatusMessageIdSourceName = 32854,
    N2kFusionStatusMessageIdRemoteUpgradeStatus = 32855,
    N2kFusionStatusMessageIdBTPairingPopup = 32856,
    N2kFusionStatusMessageIdFileTransferConfiguration = 32858,
    N2kFusionStatusMessageIdIgnitionSwitchState = 32859,
    N2kFusionStatusMessageIdExternalAmpGain = 32860,
    N2kFusionStatusMessageIdInternalAmpGain = 32861,
    N2kFusionStatusMessageIdMono = 32862,
    N2kFusionStatusMessageIdSpeedVolumeCurrentSpeed = 32863,
    N2kFusionStatusMessageIdZoneCapabilitiesExtended = 32865,
    N2kFusionStatusMessageIdBTPairingRequestDone = 32877
};

enum tN2kFusionTunerCommand {
    N2kFusionTunerCommandSeekUp = 1,
    N2kFusionTunerCommandTuneUp = 2,
    N2kFusionTunerCommandSeekDown = 3,
    N2kFusionTunerCommandTuneDown = 4,
    N2kFusionTunerCommandTuneDirect = 5
};

enum tN2kFusionCapabilityBitfield {
    N2kFusionCapabilityBitfieldVolume = (1ULL << 0),
    N2kFusionCapabilityBitfieldVolumeLimit = (1ULL << 1),
    N2kFusionCapabilityBitfieldBalance = (1ULL << 2),
    N2kFusionCapabilityBitfieldSubwoofer = (1ULL << 3),
    N2kFusionCapabilityBitfieldLowPassFilter = (1ULL << 4),
    N2kFusionCapabilityBitfieldHighPassFilter = (1ULL << 5),
    N2kFusionCapabilityBitfieldEQBass = (1ULL << 6),
    N2kFusionCapabilityBitfieldEQMid = (1ULL << 7),
    N2kFusionCapabilityBitfieldEQTreble = (1ULL << 8),
    N2kFusionCapabilityBitfieldLineOut = (1ULL << 9),
    N2kFusionCapabilityBitfieldDSP = (1ULL << 10),
    N2kFusionCapabilityBitfieldInternalAmp = (1ULL << 11),
    N2kFusionCapabilityBitfieldLoudness = (1ULL << 12),
    N2kFusionCapabilityBitfieldTweeter = (1ULL << 13),
    N2kFusionCapabilityBitfieldSubwooferOnAmp = (1ULL << 14),
    N2kFusionCapabilityBitfieldMono = (1ULL << 15)
};

enum tN2kFusionMenuItemFlags {
    N2kFusionMenuItemFlagsSelected = (1ULL << 1)
};

enum tN2kFusionSystemCapabilityBitfield {
    N2kFusionSystemCapabilityBitfieldANT = (1ULL << 0),
    N2kFusionSystemCapabilityBitfieldBluetooth = (1ULL << 1),
    N2kFusionSystemCapabilityBitfieldWiFi = (1ULL << 2),
    N2kFusionSystemCapabilityBitfieldEthernet = (1ULL << 3),
    N2kFusionSystemCapabilityBitfieldNMEA2000 = (1ULL << 4),
    N2kFusionSystemCapabilityBitfieldRVVISPort = (1ULL << 5),
    N2kFusionSystemCapabilityBitfieldLCD = (1ULL << 6),
    N2kFusionSystemCapabilityBitfieldPowerButton = (1ULL << 7),
    N2kFusionSystemCapabilityBitfieldButtonMatrix = (1ULL << 8),
    N2kFusionSystemCapabilityBitfieldTouchPanel = (1ULL << 9),
    N2kFusionSystemCapabilityBitfieldUSBConnector = (1ULL << 10),
    N2kFusionSystemCapabilityBitfieldUSBConnector2 = (1ULL << 11),
    N2kFusionSystemCapabilityBitfieldDSP = (1ULL << 12),
    N2kFusionSystemCapabilityBitfieldAMFMAntenna = (1ULL << 13),
    N2kFusionSystemCapabilityBitfieldDABAntenna = (1ULL << 14),
    N2kFusionSystemCapabilityBitfieldSiriusXMConnector = (1ULL << 15),
    N2kFusionSystemCapabilityBitfieldSPDIF = (1ULL << 16),
    N2kFusionSystemCapabilityBitfieldHDMIARC = (1ULL << 17),
    N2kFusionSystemCapabilityBitfieldHDMI = (1ULL << 18),
    N2kFusionSystemCapabilityBitfieldTelephoneMute = (1ULL << 19),
    N2kFusionSystemCapabilityBitfieldDimmerWire = (1ULL << 20),
    N2kFusionSystemCapabilityBitfieldIgnitionWire = (1ULL << 21),
    N2kFusionSystemCapabilityBitfieldNMEA2000Power = (1ULL << 22),
    N2kFusionSystemCapabilityBitfieldSTM32Coprocessor = (1ULL << 23),
    N2kFusionSystemCapabilityBitfieldStandby = (1ULL << 24),
    N2kFusionSystemCapabilityBitfieldMultiroomSource = (1ULL << 25),
    N2kFusionSystemCapabilityBitfieldMultiroomRenderer = (1ULL << 26),
    N2kFusionSystemCapabilityBitfieldAmplifierAndLineOutIndependent = (1ULL << 33),
    N2kFusionSystemCapabilityBitfieldWakeOnLAN = (1ULL << 34),
    N2kFusionSystemCapabilityBitfieldSiriusXMInstantReplay = (1ULL << 35),
    N2kFusionSystemCapabilityBitfieldSiriusXMTuneMix = (1ULL << 36),
    N2kFusionSystemCapabilityBitfieldArtistAndSongAlert = (1ULL << 37),
    N2kFusionSystemCapabilityBitfieldGameAlert = (1ULL << 38),
    N2kFusionSystemCapabilityBitfieldSportsFlash = (1ULL << 39),
    N2kFusionSystemCapabilityBitfieldZone1Amplifier2OhmStable = (1ULL << 41),
    N2kFusionSystemCapabilityBitfieldZone1Amplifier4OhmStable = (1ULL << 42),
    N2kFusionSystemCapabilityBitfieldZone2Amplifier2OhmStable = (1ULL << 43),
    N2kFusionSystemCapabilityBitfieldZone2Amplifier4OhmStable = (1ULL << 44),
    N2kFusionSystemCapabilityBitfieldAppleAirPlay = (1ULL << 45),
    N2kFusionSystemCapabilityBitfieldVolumeSyncZone = (1ULL << 46),
    N2kFusionSystemCapabilityBitfieldSourceDisable = (1ULL << 47),
    N2kFusionSystemCapabilityBitfieldSourceRename = (1ULL << 48),
    N2kFusionSystemCapabilityBitfieldInternalDABModule = (1ULL << 50)
};

// Values apply to the Tuner Region setting (FUSION_SETTING value 7).
enum tN2kFusionSettingValue {
    N2kFusionSettingValueUSA = 0,
    N2kFusionSettingValueEurope = 1,
    N2kFusionSettingValueJapan = 2,
    N2kFusionSettingValueAustralasia = 3
};

#endif
