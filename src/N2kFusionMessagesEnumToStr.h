/* N2kFusionMessagesEnumToStr.h
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

/************************************************************************//**
 * \file N2kFusionMessagesEnumToStr.h
 * \brief Converts Fusion enumerations to readable strings.
 *
 * Use the overloaded N2kEnumFusionTypeToStr() functions for string lookup.
 * Unknown values return an empty string; PrintN2kEnumFusionType() prints
 * "unknown" for those values. Bitfield lookups accept one individual flag,
 * not a combination of flags.
 ************************************************************************/

#ifndef _N2KFUSIONMESSAGESENUMTOSTR_h
#define _N2KFUSIONMESSAGESENUMTOSTR_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
#else
    #include "WProgram.h"
#endif

#include "N2KFusionTypes.h"

/**
 * @brief Converts a command value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionCommand value) {
    switch (value) {
        case N2kFusionCommandPlay: return "Play";
        case N2kFusionCommandPause: return "Pause";
        case N2kFusionCommandNext: return "Next";
        case N2kFusionCommandPrev: return "Prev";
        default: return "";
    }
}

/**
 * @brief Converts a low pass filter value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionLowPassFilter value) {
    switch (value) {
        case N2kFusionLowPassFilter50Hz: return "50 Hz";
        case N2kFusionLowPassFilter80Hz: return "80 Hz";
        case N2kFusionLowPassFilter120Hz: return "120 Hz";
        case N2kFusionLowPassFilter160Hz: return "160 Hz";
        default: return "";
    }
}

/**
 * @brief Converts a menu action value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionMenuAction value) {
    switch (value) {
        case N2kFusionMenuActionOpen: return "Open";
        case N2kFusionMenuActionSelect: return "Select";
        case N2kFusionMenuActionStepBack: return "Step Back";
        case N2kFusionMenuActionClose: return "Close";
        case N2kFusionMenuActionExit: return "Exit";
        default: return "";
    }
}

/**
 * @brief Converts a menu status value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionMenuStatus value) {
    switch (value) {
        case N2kFusionMenuStatusOpenedAtRoot: return "Opened At Root";
        case N2kFusionMenuStatusOpened: return "Opened";
        case N2kFusionMenuStatusItemUpdated: return "Item Updated";
        case N2kFusionMenuStatusClosed: return "Closed";
        case N2kFusionMenuStatusLocked: return "Locked";
        default: return "";
    }
}

/**
 * @brief Converts a message id value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionMessageId value) {
    switch (value) {
        case N2kFusionMessageIdRequestStatus: return "Request Status";
        case N2kFusionMessageIdSetSource: return "Set Source";
        case N2kFusionMessageIdMediaCommand: return "Media Command";
        case N2kFusionMessageIdTunerCommand: return "Tuner Command";
        case N2kFusionMessageIdMarineTunerCommand: return "Marine Tuner Command";
        case N2kFusionMessageIdSetMarineTunerSquelch: return "Set Marine Tuner Squelch";
        case N2kFusionMessageIdSetMarineTunerScanMode: return "Set Marine Tuner Scan Mode";
        case N2kFusionMessageIdMenuAction: return "Menu Action";
        case N2kFusionMessageIdRequestMenuCount: return "Request Menu Count";
        case N2kFusionMessageIdRequestMenuItem: return "Request Menu Item";
        case N2kFusionMessageIdRequestMenuLockID: return "Request Menu Lock ID";
        case N2kFusionMessageIdSetAuxGain: return "Set Aux Gain";
        case N2kFusionMessageIdSetSettings: return "Set Settings";
        case N2kFusionMessageIdDABUpdateCommand: return "DAB Update Command";
        case N2kFusionMessageIdSetMute: return "Set Mute";
        case N2kFusionMessageIdSetBalance: return "Set Balance";
        case N2kFusionMessageIdSetLowPassFilter: return "Set Low Pass Filter";
        case N2kFusionMessageIdSetSublevel: return "Set Sublevel";
        case N2kFusionMessageIdSetAllSublevels: return "Set All Sublevels";
        case N2kFusionMessageIdSetEqualizer: return "Set Equalizer";
        case N2kFusionMessageIdSetVolumeLimit: return "Set Volume Limit";
        case N2kFusionMessageIdSetZoneVolume: return "Set Zone Volume";
        case N2kFusionMessageIdSetAllVolumes: return "Set All Volumes";
        case N2kFusionMessageIdSetLineLevelControl: return "Set Line Level Control";
        case N2kFusionMessageIdPower: return "Power";
        case N2kFusionMessageIdSetDeviceName: return "Set Device Name";
        case N2kFusionMessageIdSendSiriusCommand: return "Send Sirius Command";
        case N2kFusionMessageIdSetSiriusParental: return "Set Sirius Parental";
        case N2kFusionMessageIdSendFactoryResetCommand: return "Send Factory Reset Command";
        case N2kFusionMessageIdSetZoneName: return "Set Zone Name";
        case N2kFusionMessageIdSendDVDCommand: return "Send DVD Command";
        case N2kFusionMessageIdDVDPressIRKey: return "DVD Press IR Key";
        case N2kFusionMessageIdSendSelectSiriusTeam: return "Send Select Sirius Team";
        case N2kFusionMessageIdSendSelectSiriusArtist: return "Send Select Sirius Artist";
        case N2kFusionMessageIdSendSiriusSportAlertUserAction: return "Send Sirius Sport Alert User Action";
        case N2kFusionMessageIdSendSiriusArtistSongUserAction: return "Send Sirius Artist Song User Action";
        case N2kFusionMessageIdSendMultiroomCommand: return "Send Multiroom Command";
        case N2kFusionMessageIdGetMultiroomDeviceRecord: return "Get Multiroom Device Record";
        case N2kFusionMessageIdScanMultiroomDevices: return "Scan Multiroom Devices";
        case N2kFusionMessageIdSendFileTransfer: return "Send File Transfer";
        case N2kFusionMessageIdSetLoud: return "Set Loud";
        case N2kFusionMessageIdSetSourceMultiroomEnabled: return "Set Source Multiroom Enabled";
        case N2kFusionMessageIdRequestHeadUnitDSPSettings: return "Request Head Unit DSP Settings";
        case N2kFusionMessageIdSendTransferStatus: return "Send Transfer Status";
        case N2kFusionMessageIdGetServerInfo: return "Get Server Info";
        case N2kFusionMessageIdSetSourceEnabled: return "Set Source Enabled";
        case N2kFusionMessageIdSetSourceName: return "Set Source Name";
        case N2kFusionMessageIdSendExternalAmpGain: return "Send External Amp Gain";
        case N2kFusionMessageIdSendInternalAmpGain: return "Send Internal Amp Gain";
        case N2kFusionMessageIdSendMono: return "Send Mono";
        default: return "";
    }
}

/**
 * @brief Converts a mute command value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionMuteCommand value) {
    switch (value) {
        case N2kFusionMuteCommandMuteOn: return "Mute On";
        case N2kFusionMuteCommandMuteOff: return "Mute Off";
        default: return "";
    }
}

/**
 * @brief Converts a play status value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionPlayStatus value) {
    switch (value) {
        case N2kFusionPlayStatusInvalid: return "Invalid";
        case N2kFusionPlayStatusPlaying: return "Playing";
        case N2kFusionPlayStatusPaused: return "Paused";
        case N2kFusionPlayStatusStopped: return "Stopped";
        case N2kFusionPlayStatusSkipForward: return "Skip Forward";
        case N2kFusionPlayStatusSkipRewind: return "Skip Rewind";
        default: return "";
    }
}

/**
 * @brief Converts a power state value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionPowerState value) {
    switch (value) {
        case N2kFusionPowerStateOn: return "On";
        case N2kFusionPowerStateOff: return "Off";
        default: return "";
    }
}

/**
 * @brief Converts a radio source value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionRadioSource value) {
    switch (value) {
        case N2kFusionRadioSourceAM: return "AM";
        case N2kFusionRadioSourceFM: return "FM";
        default: return "";
    }
}

/**
 * @brief Converts a repeat status value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionRepeatStatus value) {
    switch (value) {
        case N2kFusionRepeatStatusOff: return "Off";
        case N2kFusionRepeatStatusOneTrack: return "One/Track";
        case N2kFusionRepeatStatusAllAlbum: return "All/Album";
        default: return "";
    }
}

/**
 * @brief Converts a setting value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSetting value) {
    switch (value) {
        case N2kFusionSettingAlphaSearchThreshold: return "Alpha Search Threshold";
        case N2kFusionSettingIPodSubtitles: return "iPod Subtitles";
        case N2kFusionSettingZone2Linked: return "Zone 2 Linked";
        case N2kFusionSettingZone2Enabled: return "Zone 2 Enabled";
        case N2kFusionSettingZone3Enabled: return "Zone 3 Enabled";
        case N2kFusionSettingZone4Enabled: return "Zone 4 Enabled";
        case N2kFusionSettingTelemute: return "Telemute";
        case N2kFusionSettingTunerRegion: return "Tuner Region";
        case N2kFusionSettingMarineZone: return "Marine Zone";
        case N2kFusionSettingUSBRepeat: return "USB Repeat";
        case N2kFusionSettingUSBShuffle: return "USB Shuffle";
        case N2kFusionSettingIPodAlbumArtwork: return "iPod Album Artwork";
        case N2kFusionSettingIPodRepeat: return "iPod Repeat";
        case N2kFusionSettingIPodShuffle: return "iPod Shuffle";
        case N2kFusionSettingAMPreset0: return "AM Preset 0";
        case N2kFusionSettingAMPreset1: return "AM Preset 1";
        case N2kFusionSettingAMPreset2: return "AM Preset 2";
        case N2kFusionSettingAMPreset3: return "AM Preset 3";
        case N2kFusionSettingAMPreset4: return "AM Preset 4";
        case N2kFusionSettingAMPreset5: return "AM Preset 5";
        case N2kFusionSettingAMPreset6: return "AM Preset 6";
        case N2kFusionSettingAMPreset7: return "AM Preset 7";
        case N2kFusionSettingAMPreset8: return "AM Preset 8";
        case N2kFusionSettingAMPreset9: return "AM Preset 9";
        case N2kFusionSettingAMPreset10: return "AM Preset 10";
        case N2kFusionSettingAMPreset11: return "AM Preset 11";
        case N2kFusionSettingAMPreset12: return "AM Preset 12";
        case N2kFusionSettingAMPreset13: return "AM Preset 13";
        case N2kFusionSettingAMPreset14: return "AM Preset 14";
        case N2kFusionSettingFMPreset0: return "FM Preset 0";
        case N2kFusionSettingFMPreset1: return "FM Preset 1";
        case N2kFusionSettingFMPreset2: return "FM Preset 2";
        case N2kFusionSettingFMPreset3: return "FM Preset 3";
        case N2kFusionSettingFMPreset4: return "FM Preset 4";
        case N2kFusionSettingFMPreset5: return "FM Preset 5";
        case N2kFusionSettingFMPreset6: return "FM Preset 6";
        case N2kFusionSettingFMPreset7: return "FM Preset 7";
        case N2kFusionSettingFMPreset8: return "FM Preset 8";
        case N2kFusionSettingFMPreset9: return "FM Preset 9";
        case N2kFusionSettingFMPreset10: return "FM Preset 10";
        case N2kFusionSettingFMPreset11: return "FM Preset 11";
        case N2kFusionSettingFMPreset12: return "FM Preset 12";
        case N2kFusionSettingFMPreset13: return "FM Preset 13";
        case N2kFusionSettingFMPreset14: return "FM Preset 14";
        case N2kFusionSettingVHFPreset0: return "VHF Preset 0";
        case N2kFusionSettingVHFPreset1: return "VHF Preset 1";
        case N2kFusionSettingVHFPreset2: return "VHF Preset 2";
        case N2kFusionSettingVHFPreset3: return "VHF Preset 3";
        case N2kFusionSettingVHFPreset4: return "VHF Preset 4";
        case N2kFusionSettingVHFPreset5: return "VHF Preset 5";
        case N2kFusionSettingVHFPreset6: return "VHF Preset 6";
        case N2kFusionSettingVHFPreset7: return "VHF Preset 7";
        case N2kFusionSettingVHFPreset8: return "VHF Preset 8";
        case N2kFusionSettingVHFPreset9: return "VHF Preset 9";
        case N2kFusionSettingVHFPreset10: return "VHF Preset 10";
        case N2kFusionSettingVHFPreset11: return "VHF Preset 11";
        case N2kFusionSettingVHFPreset12: return "VHF Preset 12";
        case N2kFusionSettingVHFPreset13: return "VHF Preset 13";
        case N2kFusionSettingVHFPreset14: return "VHF Preset 14";
        case N2kFusionSettingClockTime: return "Clock Time";
        case N2kFusionSettingClockAlarm: return "Clock Alarm";
        case N2kFusionSettingIPodVideoSignal: return "iPod Video Signal";
        case N2kFusionSettingIPodMonitorAspect: return "iPod Monitor Aspect";
        case N2kFusionSettingAuxNameIndex: return "Aux Name Index";
        case N2kFusionSettingAMEnabled: return "AM Enabled";
        case N2kFusionSettingVHFEnabled: return "VHF Enabled";
        case N2kFusionSettingLanguage: return "Language";
        case N2kFusionSettingInternalAmpsOn: return "Internal Amps On";
        case N2kFusionSettingMTPRepeat: return "MTP Repeat";
        case N2kFusionSettingMTPShuffle: return "MTP Shuffle";
        case N2kFusionSettingIDAccessorySource: return "ID Accessory Source";
        case N2kFusionSettingNMEAPower: return "NMEA Power";
        case N2kFusionSettingLowPowerMode: return "Low Power Mode";
        case N2kFusionSettingDVDRegion: return "DVD Region";
        case N2kFusionSettingVolumeZoneSync: return "Volume Zone Sync";
        case N2kFusionSettingMaxVolumeStart: return "Max Volume Start";
        case N2kFusionSettingBTAutoConnect: return "BT Auto Connect";
        case N2kFusionSettingTunerAntennasPowerStatus: return "Tuner Antennas Power Status";
        case N2kFusionSettingFMAntennaIndex: return "FM Antenna Index";
        case N2kFusionSettingDABAntennaIndex: return "DAB Antenna Index";
        case N2kFusionSettingDABServiceFollowing: return "DAB Service Following";
        case N2kFusionSettingFMFrequencyFollowing: return "FM Frequency Following";
        case N2kFusionSettingDABFMServiceFollowing: return "DAB FM Service Following";
        case N2kFusionSettingHDMIVolumeZoneSync: return "HDMI Volume Zone Sync";
        case N2kFusionSettingARCInputAudioDelay: return "ARC Input Audio Delay";
        case N2kFusionSettingNullSetting: return "Null Setting";
        default: return "";
    }
}

/**
 * @brief Converts a sirius command value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSiriusCommand value) {
    switch (value) {
        case N2kFusionSiriusCommandNext: return "Next";
        case N2kFusionSiriusCommandPrev: return "Prev";
        default: return "";
    }
}

/**
 * @brief Converts a sirius com state value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSiriusComState value) {
    switch (value) {
        case N2kFusionSiriusComStateUnknown: return "Unknown";
        case N2kFusionSiriusComStateOff: return "Off";
        case N2kFusionSiriusComStateInitialising: return "Initialising";
        case N2kFusionSiriusComStateOn: return "On";
        default: return "";
    }
}

/**
 * @brief Converts a sirius tuning mode value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSiriusTuningMode value) {
    switch (value) {
        case N2kFusionSiriusTuningModeNormal: return "Normal";
        case N2kFusionSiriusTuningModeCategory: return "Category";
        case N2kFusionSiriusTuningModePreset: return "Preset";
        default: return "";
    }
}

/**
 * @brief Converts a source type value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSourceType value) {
    switch (value) {
        case N2kFusionSourceTypeAM: return "AM";
        case N2kFusionSourceTypeFM: return "FM";
        case N2kFusionSourceTypeAux: return "Aux";
        case N2kFusionSourceTypeSirius: return "Sirius";
        case N2kFusionSourceTypeIPod: return "iPod";
        case N2kFusionSourceTypeUSB: return "USB";
        case N2kFusionSourceTypeDVD: return "DVD";
        case N2kFusionSourceTypeVHF: return "VHF";
        case N2kFusionSourceTypeInvalid: return "Invalid";
        case N2kFusionSourceTypeMTP: return "MTP";
        case N2kFusionSourceTypeBluetooth: return "Bluetooth";
        case N2kFusionSourceTypeARC: return "ARC";
        case N2kFusionSourceTypeAndroid: return "Android";
        case N2kFusionSourceTypePandora: return "Pandora";
        case N2kFusionSourceTypeDAB: return "DAB";
        case N2kFusionSourceTypeAirPlay: return "AirPlay";
        case N2kFusionSourceTypeUPNP: return "UPNP";
        case N2kFusionSourceTypeUnknown: return "Unknown";
        default: return "";
    }
}

/**
 * @brief Converts a status message id value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionStatusMessageId value) {
    switch (value) {
        case N2kFusionStatusMessageIdUnknown: return "Unknown";
        case N2kFusionStatusMessageIdAPIVersion: return "API Version";
        case N2kFusionStatusMessageIdSource: return "Source";
        case N2kFusionStatusMessageIdSourceCount: return "Source Count";
        case N2kFusionStatusMessageIdTrackInfo: return "Track Info";
        case N2kFusionStatusMessageIdTrackTitle: return "Track Title";
        case N2kFusionStatusMessageIdTrackArtist: return "Track Artist";
        case N2kFusionStatusMessageIdTrackAlbum: return "Track Album";
        case N2kFusionStatusMessageIdCoverArt: return "Cover Art";
        case N2kFusionStatusMessageIdTrackProgress: return "Track Progress";
        case N2kFusionStatusMessageIdTunerAlign: return "Tuner Align";
        case N2kFusionStatusMessageIdTuner: return "Tuner";
        case N2kFusionStatusMessageIdMarineTuner: return "Marine Tuner";
        case N2kFusionStatusMessageIdMarineSquelch: return "Marine Squelch";
        case N2kFusionStatusMessageIdMarineScanMode: return "Marine Scan Mode";
        case N2kFusionStatusMessageIdMenuAction: return "Menu Action";
        case N2kFusionStatusMessageIdMenuCount: return "Menu Count";
        case N2kFusionStatusMessageIdMenuItem: return "Menu Item";
        case N2kFusionStatusMessageIdMenuLockID: return "Menu Lock ID";
        case N2kFusionStatusMessageIdAuxGain: return "Aux Gain";
        case N2kFusionStatusMessageIdSetting: return "Setting";
        case N2kFusionStatusMessageIdSettings: return "Settings";
        case N2kFusionStatusMessageIdUpdateFirmwareResult: return "Update Firmware Result";
        case N2kFusionStatusMessageIdMute: return "Mute";
        case N2kFusionStatusMessageIdBalance: return "Balance";
        case N2kFusionStatusMessageIdLowPassFilter: return "Low Pass Filter";
        case N2kFusionStatusMessageIdSublevels: return "Sublevels";
        case N2kFusionStatusMessageIdTone: return "Tone";
        case N2kFusionStatusMessageIdVolumeLimits: return "Volume Limits";
        case N2kFusionStatusMessageIdVolume: return "Volume";
        case N2kFusionStatusMessageIdCapabilities: return "Capabilities";
        case N2kFusionStatusMessageIdLineLevelControl: return "Line Level Control";
        case N2kFusionStatusMessageIdPower: return "Power";
        case N2kFusionStatusMessageIdUnitName: return "Unit Name";
        case N2kFusionStatusMessageIdSirius: return "Sirius";
        case N2kFusionStatusMessageIdSiriusXMPresetEvent: return "SiriusXM Preset Event";
        case N2kFusionStatusMessageIdSiriusXMChannel: return "SiriusXM Channel";
        case N2kFusionStatusMessageIdSiriusXMTitle: return "SiriusXM Title";
        case N2kFusionStatusMessageIdSiriusXMArtist: return "SiriusXM Artist";
        case N2kFusionStatusMessageIdSiriusXMGenre: return "SiriusXM Genre";
        case N2kFusionStatusMessageIdSiriusXMCategory: return "SiriusXM Category";
        case N2kFusionStatusMessageIdSiriusXMSignal: return "SiriusXM Signal";
        case N2kFusionStatusMessageIdSiriusXMParentalRequest: return "SiriusXM Parental Request";
        case N2kFusionStatusMessageIdSiriusXMDiagnostics: return "SiriusXM Diagnostics";
        case N2kFusionStatusMessageIdSiriusXMPresets: return "SiriusXM Presets";
        case N2kFusionStatusMessageIdZoneName: return "Zone Name";
        case N2kFusionStatusMessageIdDVDState: return "DVD State";
        case N2kFusionStatusMessageIdDVDTrack: return "DVD Track";
        case N2kFusionStatusMessageIdDVDTrackPosition: return "DVD Track Position";
        case N2kFusionStatusMessageIdDVDTrackName: return "DVD Track Name";
        case N2kFusionStatusMessageIdDVDArtistName: return "DVD Artist Name";
        case N2kFusionStatusMessageIdIPSetting: return "IP Setting";
        case N2kFusionStatusMessageIdMediaLoadingProgress: return "Media Loading Progress";
        case N2kFusionStatusMessageIdMediaUserNotification: return "Media User Notification";
        case N2kFusionStatusMessageIdSystemAlert: return "System Alert";
        case N2kFusionStatusMessageIdMultiroom: return "Multiroom";
        case N2kFusionStatusMessageIdMultiroomStatus: return "Multiroom Status";
        case N2kFusionStatusMessageIdMultiroomDeviceCount: return "Multiroom Device Count";
        case N2kFusionStatusMessageIdMultiroomDeviceRecord: return "Multiroom Device Record";
        case N2kFusionStatusMessageIdSystemCapabilities: return "System Capabilities";
        case N2kFusionStatusMessageIdPartNumber: return "Part Number";
        case N2kFusionStatusMessageIdLoudness: return "Loudness";
        case N2kFusionStatusMessageIdProcessingBypass: return "Processing Bypass";
        case N2kFusionStatusMessageIdReceivedFileCount: return "Received File Count";
        case N2kFusionStatusMessageIdReceivedFileTransfer: return "Received File Transfer";
        case N2kFusionStatusMessageIdSiriusXMReplayIndicator: return "SiriusXM Replay Indicator";
        case N2kFusionStatusMessageIdSiriusXMTeamInfo: return "SiriusXM Team Info";
        case N2kFusionStatusMessageIdSiriusXMTeamEvent: return "SiriusXM Team Event";
        case N2kFusionStatusMessageIdSiriusXMArtistSongInfo: return "SiriusXM Artist Song Info";
        case N2kFusionStatusMessageIdSiriusXMArtistSongEvent: return "SiriusXM Artist Song Event";
        case N2kFusionStatusMessageIdSiriusXMSportAlert: return "SiriusXM Sport Alert";
        case N2kFusionStatusMessageIdSiriusXMArtistSongAlert: return "SiriusXM Artist Song Alert";
        case N2kFusionStatusMessageIdSiriusXMTunemixChanged: return "SiriusXM Tunemix Changed";
        case N2kFusionStatusMessageIdSiriusXMTunemix: return "SiriusXM Tunemix";
        case N2kFusionStatusMessageIdServerInfo: return "Server Info";
        case N2kFusionStatusMessageIdRDSData: return "RDS Data";
        case N2kFusionStatusMessageIdSourceName: return "Source Name";
        case N2kFusionStatusMessageIdRemoteUpgradeStatus: return "Remote Upgrade Status";
        case N2kFusionStatusMessageIdBTPairingPopup: return "BT Pairing Popup";
        case N2kFusionStatusMessageIdFileTransferConfiguration: return "File Transfer Configuration";
        case N2kFusionStatusMessageIdIgnitionSwitchState: return "Ignition Switch State";
        case N2kFusionStatusMessageIdExternalAmpGain: return "External Amp Gain";
        case N2kFusionStatusMessageIdInternalAmpGain: return "Internal Amp Gain";
        case N2kFusionStatusMessageIdMono: return "Mono";
        case N2kFusionStatusMessageIdSpeedVolumeCurrentSpeed: return "Speed Volume Current Speed";
        case N2kFusionStatusMessageIdZoneCapabilitiesExtended: return "Zone Capabilities Extended";
        case N2kFusionStatusMessageIdBTPairingRequestDone: return "BT Pairing Request Done";
        default: return "";
    }
}

/**
 * @brief Converts a tuner command value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionTunerCommand value) {
    switch (value) {
        case N2kFusionTunerCommandSeekUp: return "Seek Up";
        case N2kFusionTunerCommandTuneUp: return "Tune Up";
        case N2kFusionTunerCommandSeekDown: return "Seek Down";
        case N2kFusionTunerCommandTuneDown: return "Tune Down";
        case N2kFusionTunerCommandTuneDirect: return "Tune Direct";
        default: return "";
    }
}

/**
 * @brief Converts a capability bitfield value to its Canboat label.
 * @note Pass one individual flag value; combined flags return an empty string.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionCapabilityBitfield value) {
    switch (value) {
        case N2kFusionCapabilityBitfieldVolume: return "Volume";
        case N2kFusionCapabilityBitfieldVolumeLimit: return "Volume Limit";
        case N2kFusionCapabilityBitfieldBalance: return "Balance";
        case N2kFusionCapabilityBitfieldSubwoofer: return "Subwoofer";
        case N2kFusionCapabilityBitfieldLowPassFilter: return "Low Pass Filter";
        case N2kFusionCapabilityBitfieldHighPassFilter: return "High Pass Filter";
        case N2kFusionCapabilityBitfieldEQBass: return "EQ Bass";
        case N2kFusionCapabilityBitfieldEQMid: return "EQ Mid";
        case N2kFusionCapabilityBitfieldEQTreble: return "EQ Treble";
        case N2kFusionCapabilityBitfieldLineOut: return "Line Out";
        case N2kFusionCapabilityBitfieldDSP: return "DSP";
        case N2kFusionCapabilityBitfieldInternalAmp: return "Internal Amp";
        case N2kFusionCapabilityBitfieldLoudness: return "Loudness";
        case N2kFusionCapabilityBitfieldTweeter: return "Tweeter";
        case N2kFusionCapabilityBitfieldSubwooferOnAmp: return "Subwoofer On Amp";
        case N2kFusionCapabilityBitfieldMono: return "Mono";
        default: return "";
    }
}

/**
 * @brief Converts a menu item flags value to its Canboat label.
 * @note Pass one individual flag value; combined flags return an empty string.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionMenuItemFlags value) {
    switch (value) {
        case N2kFusionMenuItemFlagsSelected: return "Selected";
        default: return "";
    }
}

/**
 * @brief Converts a system capability bitfield value to its Canboat label.
 * @note Pass one individual flag value; combined flags return an empty string.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSystemCapabilityBitfield value) {
    switch (value) {
        case N2kFusionSystemCapabilityBitfieldANT: return "ANT";
        case N2kFusionSystemCapabilityBitfieldBluetooth: return "Bluetooth";
        case N2kFusionSystemCapabilityBitfieldWiFi: return "Wi-Fi";
        case N2kFusionSystemCapabilityBitfieldEthernet: return "Ethernet";
        case N2kFusionSystemCapabilityBitfieldNMEA2000: return "NMEA 2000";
        case N2kFusionSystemCapabilityBitfieldRVVISPort: return "RV VIS Port";
        case N2kFusionSystemCapabilityBitfieldLCD: return "LCD";
        case N2kFusionSystemCapabilityBitfieldPowerButton: return "Power Button";
        case N2kFusionSystemCapabilityBitfieldButtonMatrix: return "Button Matrix";
        case N2kFusionSystemCapabilityBitfieldTouchPanel: return "Touch Panel";
        case N2kFusionSystemCapabilityBitfieldUSBConnector: return "USB Connector";
        case N2kFusionSystemCapabilityBitfieldUSBConnector2: return "USB Connector 2";
        case N2kFusionSystemCapabilityBitfieldDSP: return "DSP";
        case N2kFusionSystemCapabilityBitfieldAMFMAntenna: return "AM/FM Antenna";
        case N2kFusionSystemCapabilityBitfieldDABAntenna: return "DAB Antenna";
        case N2kFusionSystemCapabilityBitfieldSiriusXMConnector: return "SiriusXM Connector";
        case N2kFusionSystemCapabilityBitfieldSPDIF: return "S/PDIF";
        case N2kFusionSystemCapabilityBitfieldHDMIARC: return "HDMI ARC";
        case N2kFusionSystemCapabilityBitfieldHDMI: return "HDMI";
        case N2kFusionSystemCapabilityBitfieldTelephoneMute: return "Telephone Mute";
        case N2kFusionSystemCapabilityBitfieldDimmerWire: return "Dimmer Wire";
        case N2kFusionSystemCapabilityBitfieldIgnitionWire: return "Ignition Wire";
        case N2kFusionSystemCapabilityBitfieldNMEA2000Power: return "NMEA 2000 Power";
        case N2kFusionSystemCapabilityBitfieldSTM32Coprocessor: return "STM32 Coprocessor";
        case N2kFusionSystemCapabilityBitfieldStandby: return "Standby";
        case N2kFusionSystemCapabilityBitfieldMultiroomSource: return "Multiroom Source";
        case N2kFusionSystemCapabilityBitfieldMultiroomRenderer: return "Multiroom Renderer";
        case N2kFusionSystemCapabilityBitfieldAmplifierAndLineOutIndependent: return "Amplifier and Line Out Independent";
        case N2kFusionSystemCapabilityBitfieldWakeOnLAN: return "Wake on LAN";
        case N2kFusionSystemCapabilityBitfieldSiriusXMInstantReplay: return "SiriusXM Instant Replay";
        case N2kFusionSystemCapabilityBitfieldSiriusXMTuneMix: return "SiriusXM TuneMix";
        case N2kFusionSystemCapabilityBitfieldArtistAndSongAlert: return "Artist and Song Alert";
        case N2kFusionSystemCapabilityBitfieldGameAlert: return "Game Alert";
        case N2kFusionSystemCapabilityBitfieldSportsFlash: return "Sports Flash";
        case N2kFusionSystemCapabilityBitfieldZone1Amplifier2OhmStable: return "Zone 1 Amplifier 2 Ohm Stable";
        case N2kFusionSystemCapabilityBitfieldZone1Amplifier4OhmStable: return "Zone 1 Amplifier 4 Ohm Stable";
        case N2kFusionSystemCapabilityBitfieldZone2Amplifier2OhmStable: return "Zone 2 Amplifier 2 Ohm Stable";
        case N2kFusionSystemCapabilityBitfieldZone2Amplifier4OhmStable: return "Zone 2 Amplifier 4 Ohm Stable";
        case N2kFusionSystemCapabilityBitfieldAppleAirPlay: return "Apple AirPlay";
        case N2kFusionSystemCapabilityBitfieldVolumeSyncZone: return "Volume Sync Zone";
        case N2kFusionSystemCapabilityBitfieldSourceDisable: return "Source Disable";
        case N2kFusionSystemCapabilityBitfieldSourceRename: return "Source Rename";
        case N2kFusionSystemCapabilityBitfieldInternalDABModule: return "Internal DAB Module";
        default: return "";
    }
}

/**
 * @brief Converts a Fusion setting value to its Canboat label.
 */
static inline const char* N2kEnumFusionTypeToStr(tN2kFusionSettingValue value) {
    switch (value) {
        case N2kFusionSettingValueUSA: return "USA";
        case N2kFusionSettingValueEurope: return "Europe";
        case N2kFusionSettingValueJapan: return "Japan";
        case N2kFusionSettingValueAustralasia: return "Australasia";
        default: return "";
    }
}

/**
 * @brief Prints a Fusion enum label to a stream.
 * @param value Enum value to print.
 * @param outputStream Destination stream.
 * @param addLF If true, append a line feed.
 */
template<typename T>
void PrintN2kEnumFusionType(T value, Stream* outputStream, bool addLF = true) {
    const char* label = N2kEnumFusionTypeToStr(value);
    if (label[0] == 0) {
        outputStream->print(F("unknown"));
    } else {
        outputStream->print(label);
    }
    if (addLF) outputStream->println();
}

#endif
