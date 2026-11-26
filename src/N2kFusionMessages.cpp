
#include "N2kFusionMessages.h"
#include <string.h>

static void SetFusionCommand(tN2kMsg& msg, tN2kFusionMessageId messageId) {
    msg.SetPGN(126720L);
    msg.Priority = 7;
    msg.Add2ByteUInt(0x81A3);
    msg.Add2ByteUInt(static_cast<uint16_t>(messageId));
}

static bool IsFusionStringValid(const char* value, size_t prefixLength) {
    if (value == NULL) return false;
    size_t length = strlen(value);
    return length <= 0xff && length + prefixLength + 2 <= tN2kMsg::MaxDataLen;
}

static void AddFusionString(tN2kMsg& msg, const char* value) {
    size_t length = strlen(value);
    msg.AddByte(static_cast<uint8_t>(length));
    msg.AddBuf(value, length);
    msg.AddByte(0);
}

static bool BeginFusionParse(const tN2kMsg& msg, tN2kFusionMessageId messageId,
                             int expectedLength, int& index) {
    if (msg.PGN != 126720L || msg.DataLen < 4 ||
        (expectedLength >= 0 && msg.DataLen != expectedLength)) {
        return false;
    }

    int dataIndex = 0;
    if (msg.Get2ByteUInt(dataIndex) != 0x81A3 ||
        msg.Get2ByteUInt(dataIndex) != static_cast<uint16_t>(messageId)) {
        return false;
    }

    index = dataIndex;
    return true;
}

static bool BeginFusionStatusParse(const tN2kMsg& msg,
                                   tN2kFusionStatusMessageId messageId,
                                   int expectedLength, int& index) {
    if (msg.PGN != 130820L || msg.DataLen < 4 ||
        (expectedLength >= 0 && msg.DataLen != expectedLength)) {
        return false;
    }

    int dataIndex = 0;
    if (msg.Get2ByteUInt(dataIndex) != 0x81A3 ||
        msg.Get2ByteUInt(dataIndex) != static_cast<uint16_t>(messageId)) {
        return false;
    }

    index = dataIndex;
    return true;
}

static bool ParseFusionString(const tN2kMsg& msg, int index, char* value,
                              size_t valueBufSize) {
    if (value == NULL || valueBufSize == 0 ||
        msg.GetRemainingDataLength(index) < 2) {
        return false;
    }

    uint8_t length = msg.GetByte(index);
    if (msg.GetRemainingDataLength(index) != length + 1 ||
        valueBufSize <= length) {
        return false;
    }

    int checkIndex = index;
    for (uint8_t i = 0; i < length; ++i) {
        if (msg.GetByte(checkIndex) == 0) return false;
    }
    if (msg.GetByte(checkIndex) != 0) return false;

    for (uint8_t i = 0; i < length; ++i) {
        value[i] = static_cast<char>(msg.GetByte(index));
    }
    value[length] = '\0';
    return true;
}

void SetFusionMediaControl(tN2kMsg& msg, uint8_t sourceID,
                           tN2kFusionCommand command) {
    SetFusionCommand(msg, N2kFusionMessageIdMediaCommand);
    msg.AddByte(sourceID);
    msg.AddByte(static_cast<uint8_t>(command));
}

void SetFusionSiriusControl(tN2kMsg& msg, uint8_t sourceID,
                            tN2kFusionSiriusCommand command, uint16_t data) {
    SetFusionCommand(msg, N2kFusionMessageIdSendSiriusCommand);
    msg.AddByte(sourceID);
    msg.AddByte(static_cast<uint8_t>(command));
    msg.Add2ByteUInt(data);
}

void SetFusionRequestStatus(tN2kMsg& msg) {
    SetFusionCommand(msg, N2kFusionMessageIdRequestStatus);
}

void SetFusionSource(tN2kMsg& msg, uint8_t sourceID) {
    SetFusionCommand(msg, N2kFusionMessageIdSetSource);
    msg.AddByte(sourceID);
}

void SetFusionMute(tN2kMsg& msg, tN2kFusionMuteCommand command) {
    SetFusionCommand(msg, N2kFusionMessageIdSetMute);
    msg.AddByte(static_cast<uint8_t>(command));
}

void SetFusionZoneVolume(tN2kMsg& msg, uint8_t zone, uint8_t volume) {
    SetFusionCommand(msg, N2kFusionMessageIdSetZoneVolume);
    msg.AddByte(zone);
    msg.AddByte(volume);
}

void SetFusionAllVolumes(tN2kMsg& msg, uint8_t zone1, uint8_t zone2,
                         uint8_t zone3, uint8_t zone4) {
    SetFusionCommand(msg, N2kFusionMessageIdSetAllVolumes);
    msg.AddByte(zone1);
    msg.AddByte(zone2);
    msg.AddByte(zone3);
    msg.AddByte(zone4);
}

void SetFusionPower(tN2kMsg& msg, tN2kFusionPowerState power) {
    SetFusionCommand(msg, N2kFusionMessageIdPower);
    msg.AddByte(static_cast<uint8_t>(power));
}

void SetFusionMenuAction(tN2kMsg& msg, uint8_t sourceID, uint32_t itemIndex,
                         tN2kFusionMenuAction action, uint8_t lockID) {
    SetFusionCommand(msg, N2kFusionMessageIdMenuAction);
    msg.AddByte(sourceID);
    msg.Add4ByteUInt(itemIndex);
    msg.AddByte(static_cast<uint8_t>(action));
    msg.AddByte(lockID);
}

void SetFusionRequestMenuCount(tN2kMsg& msg, uint8_t sourceID, uint8_t lockID) {
    SetFusionCommand(msg, N2kFusionMessageIdRequestMenuCount);
    msg.AddByte(sourceID);
    msg.AddByte(lockID);
}

void SetFusionRequestMenuItems(tN2kMsg& msg, uint8_t sourceID,
                               uint32_t startIndex, uint32_t count,
                               uint8_t lockID) {
    SetFusionCommand(msg, N2kFusionMessageIdRequestMenuItem);
    msg.AddByte(sourceID);
    msg.Add4ByteUInt(startIndex);
    msg.Add4ByteUInt(count);
    msg.AddByte(lockID);
}

void SetFusionRequestMenuLockID(tN2kMsg& msg, uint32_t requestToken) {
    SetFusionCommand(msg, N2kFusionMessageIdRequestMenuLockID);
    msg.Add4ByteUInt(requestToken);
}

void SetFusionSetting(tN2kMsg& msg, tN2kFusionSetting id, uint32_t value) {
    SetFusionCommand(msg, N2kFusionMessageIdSetSettings);
    msg.Add4ByteUInt(static_cast<uint32_t>(id));
    msg.Add4ByteUInt(value);
}

void SetFusionTunerCommand(tN2kMsg& msg, tN2kFusionRadioSource source,
                           tN2kFusionTunerCommand command, uint32_t frequencyHz) {
    SetFusionCommand(msg, N2kFusionMessageIdTunerCommand);
    msg.AddByte(static_cast<uint8_t>(source));
    msg.AddByte(static_cast<uint8_t>(command));
    msg.Add4ByteUInt(frequencyHz);
}

void SetFusionAuxGain(tN2kMsg& msg, uint8_t sourceID, uint8_t gain) {
    SetFusionCommand(msg, N2kFusionMessageIdSetAuxGain);
    msg.AddByte(sourceID);
    msg.AddByte(gain);
}

void SetFusionBalance(tN2kMsg& msg, uint8_t zone, uint8_t value) {
    SetFusionCommand(msg, N2kFusionMessageIdSetBalance);
    msg.AddByte(zone);
    msg.AddByte(value);
}

void SetFusionLowPassFilter(tN2kMsg& msg, uint8_t zone,
                            tN2kFusionLowPassFilter filter) {
    SetFusionCommand(msg, N2kFusionMessageIdSetLowPassFilter);
    msg.AddByte(zone);
    msg.AddByte(static_cast<uint8_t>(filter));
}

void SetFusionSublevel(tN2kMsg& msg, uint8_t zone, uint8_t level) {
    SetFusionCommand(msg, N2kFusionMessageIdSetSublevel);
    msg.AddByte(zone);
    msg.AddByte(level);
}

void SetFusionVolumeLimit(tN2kMsg& msg, uint8_t zone, uint8_t limit) {
    SetFusionCommand(msg, N2kFusionMessageIdSetVolumeLimit);
    msg.AddByte(zone);
    msg.AddByte(limit);
}

bool SetFusionZoneName(tN2kMsg& msg, uint8_t zone, const char* name) {
    if (!IsFusionStringValid(name, 5)) return false;

    SetFusionCommand(msg, N2kFusionMessageIdSetZoneName);
    msg.AddByte(zone);
    AddFusionString(msg, name);
    return true;
}

void SetFusionEqualizer(tN2kMsg& msg, uint8_t zone, uint8_t bass,
                        uint8_t mid, uint8_t treble) {
    SetFusionCommand(msg, N2kFusionMessageIdSetEqualizer);
    msg.AddByte(zone);
    msg.AddByte(bass);
    msg.AddByte(mid);
    msg.AddByte(treble);
}

void SetFusionAllSublevels(tN2kMsg& msg, uint8_t zone1, uint8_t zone2,
                           uint8_t zone3, uint8_t zone4) {
    SetFusionCommand(msg, N2kFusionMessageIdSetAllSublevels);
    msg.AddByte(zone1);
    msg.AddByte(zone2);
    msg.AddByte(zone3);
    msg.AddByte(zone4);
}

bool SetFusionDeviceName(tN2kMsg& msg, const char* name) {
    if (!IsFusionStringValid(name, 4)) return false;

    SetFusionCommand(msg, N2kFusionMessageIdSetDeviceName);
    AddFusionString(msg, name);
    return true;
}

bool ParseFusionMediaControl(const tN2kMsg& msg, uint8_t& sourceID,
                             tN2kFusionCommand& command) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdMediaCommand, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    tN2kFusionCommand parsedCommand =
        static_cast<tN2kFusionCommand>(msg.GetByte(index));
    sourceID = parsedSourceID;
    command = parsedCommand;
    return true;
}

bool ParseFusionSiriusControl(const tN2kMsg& msg, uint8_t& sourceID,
                              tN2kFusionSiriusCommand& command, uint16_t& data) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSendSiriusCommand, 8, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    tN2kFusionSiriusCommand parsedCommand =
        static_cast<tN2kFusionSiriusCommand>(msg.GetByte(index));
    uint16_t parsedData = msg.Get2ByteUInt(index);
    sourceID = parsedSourceID;
    command = parsedCommand;
    data = parsedData;
    return true;
}

bool ParseFusionRequestStatus(const tN2kMsg& msg) {
    int index;
    return BeginFusionParse(msg, N2kFusionMessageIdRequestStatus, 4, index);
}

bool ParseFusionSource(const tN2kMsg& msg, uint8_t& sourceID) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetSource, 5, index)) return false;

    sourceID = msg.GetByte(index);
    return true;
}

bool ParseFusionMute(const tN2kMsg& msg, tN2kFusionMuteCommand& command) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetMute, 5, index)) return false;

    command = static_cast<tN2kFusionMuteCommand>(msg.GetByte(index));
    return true;
}

bool ParseFusionZoneVolume(const tN2kMsg& msg, uint8_t& zone,
                           uint8_t& volume) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetZoneVolume, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedVolume = msg.GetByte(index);
    zone = parsedZone;
    volume = parsedVolume;
    return true;
}

bool ParseFusionAllVolumes(const tN2kMsg& msg, uint8_t& zone1,
                           uint8_t& zone2, uint8_t& zone3, uint8_t& zone4) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetAllVolumes, 8, index)) return false;

    uint8_t parsedZone1 = msg.GetByte(index);
    uint8_t parsedZone2 = msg.GetByte(index);
    uint8_t parsedZone3 = msg.GetByte(index);
    uint8_t parsedZone4 = msg.GetByte(index);
    zone1 = parsedZone1;
    zone2 = parsedZone2;
    zone3 = parsedZone3;
    zone4 = parsedZone4;
    return true;
}

bool ParseFusionPower(const tN2kMsg& msg, tN2kFusionPowerState& power) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdPower, 5, index)) return false;

    power = static_cast<tN2kFusionPowerState>(msg.GetByte(index));
    return true;
}

bool ParseFusionMenuAction(const tN2kMsg& msg, uint8_t& sourceID,
                           uint32_t& itemIndex, tN2kFusionMenuAction& action,
                           uint8_t& lockID) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdMenuAction, 11, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedItemIndex = msg.Get4ByteUInt(index);
    tN2kFusionMenuAction parsedAction =
        static_cast<tN2kFusionMenuAction>(msg.GetByte(index));
    uint8_t parsedLockID = msg.GetByte(index);
    sourceID = parsedSourceID;
    itemIndex = parsedItemIndex;
    action = parsedAction;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionRequestMenuCount(const tN2kMsg& msg, uint8_t& sourceID,
                                 uint8_t& lockID) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdRequestMenuCount, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedLockID = msg.GetByte(index);
    sourceID = parsedSourceID;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionRequestMenuItems(const tN2kMsg& msg, uint8_t& sourceID,
                                 uint32_t& startIndex, uint32_t& count,
                                 uint8_t& lockID) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdRequestMenuItem, 14, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedStartIndex = msg.Get4ByteUInt(index);
    uint32_t parsedCount = msg.Get4ByteUInt(index);
    uint8_t parsedLockID = msg.GetByte(index);
    sourceID = parsedSourceID;
    startIndex = parsedStartIndex;
    count = parsedCount;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionRequestMenuLockID(const tN2kMsg& msg, uint32_t& requestToken) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdRequestMenuLockID, 8, index)) return false;

    requestToken = msg.Get4ByteUInt(index);
    return true;
}

bool ParseFusionSetting(const tN2kMsg& msg, uint32_t& id, uint32_t& value) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetSettings, 12, index)) return false;

    uint32_t parsedID = msg.Get4ByteUInt(index);
    uint32_t parsedValue = msg.Get4ByteUInt(index);
    id = parsedID;
    value = parsedValue;
    return true;
}

bool ParseFusionTunerCommand(const tN2kMsg& msg, tN2kFusionRadioSource& source,
                             tN2kFusionTunerCommand& command,
                             uint32_t& frequencyHz) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdTunerCommand, 10, index)) return false;

    tN2kFusionRadioSource parsedSource =
        static_cast<tN2kFusionRadioSource>(msg.GetByte(index));
    tN2kFusionTunerCommand parsedCommand =
        static_cast<tN2kFusionTunerCommand>(msg.GetByte(index));
    uint32_t parsedFrequencyHz = msg.Get4ByteUInt(index);
    source = parsedSource;
    command = parsedCommand;
    frequencyHz = parsedFrequencyHz;
    return true;
}

bool ParseFusionAuxGain(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& gain) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetAuxGain, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedGain = msg.GetByte(index);
    sourceID = parsedSourceID;
    gain = parsedGain;
    return true;
}

bool ParseFusionBalance(const tN2kMsg& msg, uint8_t& zone, uint8_t& value) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetBalance, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedValue = msg.GetByte(index);
    zone = parsedZone;
    value = parsedValue;
    return true;
}

bool ParseFusionLowPassFilter(const tN2kMsg& msg, uint8_t& zone,
                              tN2kFusionLowPassFilter& filter) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetLowPassFilter, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    tN2kFusionLowPassFilter parsedFilter =
        static_cast<tN2kFusionLowPassFilter>(msg.GetByte(index));
    zone = parsedZone;
    filter = parsedFilter;
    return true;
}

bool ParseFusionSublevel(const tN2kMsg& msg, uint8_t& zone, uint8_t& level) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetSublevel, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedLevel = msg.GetByte(index);
    zone = parsedZone;
    level = parsedLevel;
    return true;
}

bool ParseFusionVolumeLimit(const tN2kMsg& msg, uint8_t& zone, uint8_t& limit) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetVolumeLimit, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedLimit = msg.GetByte(index);
    zone = parsedZone;
    limit = parsedLimit;
    return true;
}

bool ParseFusionZoneName(const tN2kMsg& msg, uint8_t& zone, char* name,
                         size_t nameBufSize) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetZoneName, -1, index) ||
        msg.GetRemainingDataLength(index) < 3) {
        return false;
    }

    uint8_t parsedZone = msg.GetByte(index);
    if (!ParseFusionString(msg, index, name, nameBufSize)) return false;
    zone = parsedZone;
    return true;
}

bool ParseFusionEqualizer(const tN2kMsg& msg, uint8_t& zone, uint8_t& bass,
                          uint8_t& mid, uint8_t& treble) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetEqualizer, 8, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedBass = msg.GetByte(index);
    uint8_t parsedMid = msg.GetByte(index);
    uint8_t parsedTreble = msg.GetByte(index);
    zone = parsedZone;
    bass = parsedBass;
    mid = parsedMid;
    treble = parsedTreble;
    return true;
}

bool ParseFusionAllSublevels(const tN2kMsg& msg, uint8_t& zone1,
                             uint8_t& zone2, uint8_t& zone3, uint8_t& zone4) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetAllSublevels, 8, index)) return false;

    uint8_t parsedZone1 = msg.GetByte(index);
    uint8_t parsedZone2 = msg.GetByte(index);
    uint8_t parsedZone3 = msg.GetByte(index);
    uint8_t parsedZone4 = msg.GetByte(index);
    zone1 = parsedZone1;
    zone2 = parsedZone2;
    zone3 = parsedZone3;
    zone4 = parsedZone4;
    return true;
}

bool ParseFusionDeviceName(const tN2kMsg& msg, char* name,
                           size_t nameBufSize) {
    int index;
    if (!BeginFusionParse(msg, N2kFusionMessageIdSetDeviceName, -1, index)) return false;

    return ParseFusionString(msg, index, name, nameBufSize);
}

bool ParseFusionStatusVersions(const tN2kMsg& msg, uint16_t& hardwareMajor,
                               uint16_t& hardwareMinor, uint8_t& softwareMajor,
                               uint8_t& softwareMinor, uint8_t& buildNumber) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdAPIVersion, 12, index)) return false;

    uint16_t parsedHardwareMajor = msg.Get2ByteUInt(index);
    uint16_t parsedHardwareMinor = msg.Get2ByteUInt(index);
    uint8_t parsedSoftwareMajor = msg.GetByte(index);
    uint8_t parsedSoftwareMinor = msg.GetByte(index);
    uint8_t parsedBuildNumber = msg.GetByte(index);
    msg.GetByte(index);
    hardwareMajor = parsedHardwareMajor;
    hardwareMinor = parsedHardwareMinor;
    softwareMajor = parsedSoftwareMajor;
    softwareMinor = parsedSoftwareMinor;
    buildNumber = parsedBuildNumber;
    return true;
}

bool ParseFusionStatusSource(const tN2kMsg& msg, uint8_t& sourceID,
                             uint8_t& currentSourceID, uint8_t& sourceType,
                             uint8_t& flags, char* source, size_t sourceBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSource, -1, index) ||
        msg.GetRemainingDataLength(index) < 6) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedCurrentSourceID = msg.GetByte(index);
    uint8_t parsedSourceType = msg.GetByte(index);
    uint8_t parsedFlags = msg.GetByte(index);
    if (!ParseFusionString(msg, index, source, sourceBufSize)) return false;
    sourceID = parsedSourceID;
    currentSourceID = parsedCurrentSourceID;
    sourceType = parsedSourceType;
    flags = parsedFlags;
    return true;
}

bool ParseFusionStatusSourceCount(const tN2kMsg& msg, uint8_t& sourceCount) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSourceCount, 5, index)) return false;
    sourceCount = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusMedia(const tN2kMsg& msg, uint8_t& sourceID,
                            uint16_t& flags, uint32_t& trackNumber,
                            uint32_t& trackCount, uint32_t& length,
                            uint32_t& position) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTrackInfo, 23, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedFlags = msg.Get2ByteUInt(index);
    uint32_t parsedTrackNumber = msg.Get4ByteUInt(index);
    uint32_t parsedTrackCount = msg.Get4ByteUInt(index);
    uint32_t parsedLength = msg.Get4ByteUInt(index);
    uint32_t parsedPosition = msg.Get4ByteUInt(index);
    sourceID = parsedSourceID;
    flags = parsedFlags;
    trackNumber = parsedTrackNumber;
    trackCount = parsedTrackCount;
    length = parsedLength;
    position = parsedPosition;
    return true;
}

bool ParseFusionStatusTrackName(const tN2kMsg& msg, uint8_t& sourceID,
                                uint32_t& itemIndex, char* track,
                                size_t trackBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTrackTitle, -1, index) ||
        msg.GetRemainingDataLength(index) < 7) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedIndex = msg.Get4ByteUInt(index);
    if (!ParseFusionString(msg, index, track, trackBufSize)) return false;
    sourceID = parsedSourceID;
    itemIndex = parsedIndex;
    return true;
}

bool ParseFusionStatusArtistName(const tN2kMsg& msg, uint8_t& sourceID,
                                 uint32_t& itemIndex, char* artist,
                                 size_t artistBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTrackArtist, -1, index) ||
        msg.GetRemainingDataLength(index) < 7) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedIndex = msg.Get4ByteUInt(index);
    if (!ParseFusionString(msg, index, artist, artistBufSize)) return false;
    sourceID = parsedSourceID;
    itemIndex = parsedIndex;
    return true;
}

bool ParseFusionStatusAlbumName(const tN2kMsg& msg, uint8_t& sourceID,
                                uint32_t& itemIndex, char* album,
                                size_t albumBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTrackAlbum, -1, index) ||
        msg.GetRemainingDataLength(index) < 7) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedIndex = msg.Get4ByteUInt(index);
    if (!ParseFusionString(msg, index, album, albumBufSize)) return false;
    sourceID = parsedSourceID;
    itemIndex = parsedIndex;
    return true;
}

bool ParseFusionStatusDeviceName(const tN2kMsg& msg, char* name,
                                 size_t nameBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdUnitName, -1, index)) return false;
    return ParseFusionString(msg, index, name, nameBufSize);
}

bool ParseFusionStatusZoneName(const tN2kMsg& msg, uint8_t& zone,
                               char* name, size_t nameBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdZoneName, -1, index) ||
        msg.GetRemainingDataLength(index) < 3) return false;

    uint8_t parsedZone = msg.GetByte(index);
    if (!ParseFusionString(msg, index, name, nameBufSize)) return false;
    zone = parsedZone;
    return true;
}

bool ParseFusionStatusSpeedVolumeCurrentSpeed(const tN2kMsg& msg,
                                              uint8_t& sourceID,
                                              uint16_t& speed,
                                              uint8_t& enabled) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSpeedVolumeCurrentSpeed, 8, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedSpeed = msg.Get2ByteUInt(index);
    uint8_t parsedEnabled = msg.GetByte(index);
    sourceID = parsedSourceID;
    speed = parsedSpeed;
    enabled = parsedEnabled;
    return true;
}

bool ParseFusionStatusIgnitionSwitchState(const tN2kMsg& msg, uint8_t& state) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdIgnitionSwitchState, 5, index)) return false;
    state = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusMenuLockID(const tN2kMsg& msg, uint32_t& requestToken,
                                 uint8_t& lockID) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMenuLockID, 9, index)) return false;

    uint32_t parsedRequestToken = msg.Get4ByteUInt(index);
    uint8_t parsedLockID = msg.GetByte(index);
    requestToken = parsedRequestToken;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionStatusRDSData(const tN2kMsg& msg, uint8_t& sourceID,
                              uint8_t& rdsType, uint8_t& programmeType,
                              char* rds, size_t rdsBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdRDSData, 39, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedRDSType = msg.GetByte(index);
    uint8_t parsedProgrammeType = msg.GetByte(index);
    if (msg.GetRemainingDataLength(index) != 32 ||
        !ParseFusionString(msg, index, rds, rdsBufSize)) return false;
    sourceID = parsedSourceID;
    rdsType = parsedRDSType;
    programmeType = parsedProgrammeType;
    return true;
}

bool ParseFusionStatusMultiroom(const tN2kMsg& msg, uint8_t& enabled,
                                uint8_t ipAddress[4]) {
    int index;
    if (ipAddress == NULL ||
        !BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMultiroom, 9, index)) return false;

    uint8_t parsedEnabled = msg.GetByte(index);
    uint8_t parsedAddress[4];
    for (size_t i = 0; i < 4; ++i) parsedAddress[i] = msg.GetByte(index);
    enabled = parsedEnabled;
    memcpy(ipAddress, parsedAddress, sizeof(parsedAddress));
    return true;
}

bool ParseFusionStatusMultiroomStatus(const tN2kMsg& msg, uint8_t& available) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMultiroomStatus, 5, index)) return false;
    available = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusProcessingBypass(const tN2kMsg& msg, uint8_t& bypass) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdProcessingBypass, 5, index)) return false;
    bypass = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusMono(const tN2kMsg& msg, uint8_t& zone, uint8_t& enabled) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMono, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedEnabled = msg.GetByte(index);
    zone = parsedZone;
    enabled = parsedEnabled;
    return true;
}

bool ParseFusionStatusTrackPosition(const tN2kMsg& msg, uint8_t& sourceID,
                                    uint32_t& progress) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTrackProgress, 9, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedProgress = static_cast<uint32_t>(msg.GetByte(index));
    parsedProgress |= static_cast<uint32_t>(msg.GetByte(index)) << 8;
    parsedProgress |= static_cast<uint32_t>(msg.GetByte(index)) << 16;
    msg.GetByte(index);
    sourceID = parsedSourceID;
    progress = parsedProgress;
    return true;
}

bool ParseFusionStatusTuner(const tN2kMsg& msg, uint8_t& sourceID,
                            uint8_t& scanning, uint32_t& frequency,
                            uint8_t& signalStrength, char* track,
                            size_t trackBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTuner, -1, index) ||
        msg.GetRemainingDataLength(index) < 8) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedScanning = msg.GetByte(index);
    uint32_t parsedFrequency = msg.Get4ByteUInt(index);
    uint8_t parsedSignalStrength = msg.GetByte(index);
    if (!ParseFusionString(msg, index, track, trackBufSize)) return false;
    sourceID = parsedSourceID;
    scanning = parsedScanning;
    frequency = parsedFrequency;
    signalStrength = parsedSignalStrength;
    return true;
}

bool ParseFusionStatusMarineTuner(const tN2kMsg& msg, uint8_t& sourceID,
                                  uint8_t& channel, uint8_t& signalStrength,
                                  char* name, size_t nameBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMarineTuner, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedChannel = msg.GetByte(index);
    uint8_t parsedSignalStrength = msg.GetByte(index);
    if (!ParseFusionString(msg, index, name, nameBufSize)) return false;
    sourceID = parsedSourceID;
    channel = parsedChannel;
    signalStrength = parsedSignalStrength;
    return true;
}

bool ParseFusionStatusMarineSquelch(const tN2kMsg& msg, uint8_t& sourceID,
                                    uint8_t& squelch) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMarineSquelch, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedSquelch = msg.GetByte(index);
    sourceID = parsedSourceID;
    squelch = parsedSquelch;
    return true;
}

bool ParseFusionStatusMarineScanMode(const tN2kMsg& msg, uint8_t& sourceID,
                                     uint8_t& scanMode) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMarineScanMode, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedScanMode = msg.GetByte(index);
    sourceID = parsedSourceID;
    scanMode = parsedScanMode;
    return true;
}

bool ParseFusionStatusMenuItem(const tN2kMsg& msg, uint8_t& sourceID,
                               uint32_t& itemIndex, uint8_t& flags,
                               uint8_t& lockID, char* text,
                               size_t textBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMenuItem, -1, index) ||
        msg.GetRemainingDataLength(index) < 9) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedItemIndex = msg.Get4ByteUInt(index);
    uint8_t parsedFlags = msg.GetByte(index);
    uint8_t parsedLockID = msg.GetByte(index);
    if (!ParseFusionString(msg, index, text, textBufSize)) return false;
    sourceID = parsedSourceID;
    itemIndex = parsedItemIndex;
    flags = parsedFlags;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionStatusAuxGain(const tN2kMsg& msg, uint8_t& sourceID,
                              uint8_t& gain) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdAuxGain, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedGain = msg.GetByte(index);
    sourceID = parsedSourceID;
    gain = parsedGain;
    return true;
}

bool ParseFusionStatusUSBRepeatStatus(const tN2kMsg& msg, uint32_t& status) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSetting, 12, index)) return false;

    uint32_t settingID = msg.Get4ByteUInt(index);
    uint32_t parsedStatus = msg.Get4ByteUInt(index);
    if (settingID != N2kFusionSettingUSBRepeat) return false;
    status = parsedStatus;
    return true;
}

bool ParseFusionStatusSetting(const tN2kMsg& msg, uint32_t& id,
                              uint32_t& value) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSetting, 12, index)) return false;

    uint32_t parsedID = msg.Get4ByteUInt(index);
    uint32_t parsedValue = msg.Get4ByteUInt(index);
    id = parsedID;
    value = parsedValue;
    return true;
}

bool ParseFusionStatusSettings(const tN2kMsg& msg, uint32_t& count,
                               tN2kFusionSettingEntry* entries,
                               size_t entriesCapacity) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSettings, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint32_t parsedCount = msg.Get4ByteUInt(index);
    int remaining = msg.GetRemainingDataLength(index);
    if (remaining < 0 || remaining % 8 != 0 ||
        parsedCount != static_cast<uint32_t>(remaining / 8) ||
        parsedCount > entriesCapacity ||
        (parsedCount > 0 && entries == NULL)) return false;

    for (uint32_t i = 0; i < parsedCount; ++i) {
        entries[i].id = msg.Get4ByteUInt(index);
        entries[i].value = msg.Get4ByteUInt(index);
    }
    count = parsedCount;
    return true;
}

bool ParseFusionStatusMute(const tN2kMsg& msg, uint8_t& mute) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMute, 5, index)) return false;
    mute = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusBalance(const tN2kMsg& msg, uint8_t& zone,
                              uint8_t& value) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdBalance, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedValue = msg.GetByte(index);
    zone = parsedZone;
    value = parsedValue;
    return true;
}

bool ParseFusionStatusLowPassFilter(const tN2kMsg& msg, uint8_t& zone,
                                    uint8_t& filter) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdLowPassFilter, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedFilter = msg.GetByte(index);
    zone = parsedZone;
    filter = parsedFilter;
    return true;
}

bool ParseFusionStatusSublevels(const tN2kMsg& msg, uint8_t& zone1,
                                uint8_t& zone2, uint8_t& zone3, uint8_t& zone4) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSublevels, 8, index)) return false;

    uint8_t parsedZone1 = msg.GetByte(index);
    uint8_t parsedZone2 = msg.GetByte(index);
    uint8_t parsedZone3 = msg.GetByte(index);
    uint8_t parsedZone4 = msg.GetByte(index);
    zone1 = parsedZone1;
    zone2 = parsedZone2;
    zone3 = parsedZone3;
    zone4 = parsedZone4;
    return true;
}

bool ParseFusionStatusEQ(const tN2kMsg& msg, uint8_t& zone, uint8_t& bass,
                         uint8_t& mid, uint8_t& treble) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdTone, 8, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedBass = msg.GetByte(index);
    uint8_t parsedMid = msg.GetByte(index);
    uint8_t parsedTreble = msg.GetByte(index);
    zone = parsedZone;
    bass = parsedBass;
    mid = parsedMid;
    treble = parsedTreble;
    return true;
}

bool ParseFusionStatusVolumeLimits(const tN2kMsg& msg, uint8_t& zone1,
                                   uint8_t& zone2, uint8_t& zone3,
                                   uint8_t& zone4) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdVolumeLimits, 8, index)) return false;

    uint8_t parsedZone1 = msg.GetByte(index);
    uint8_t parsedZone2 = msg.GetByte(index);
    uint8_t parsedZone3 = msg.GetByte(index);
    uint8_t parsedZone4 = msg.GetByte(index);
    zone1 = parsedZone1;
    zone2 = parsedZone2;
    zone3 = parsedZone3;
    zone4 = parsedZone4;
    return true;
}

bool ParseFusionStatusVolumes(const tN2kMsg& msg, uint8_t& zone1,
                              uint8_t& zone2, uint8_t& zone3, uint8_t& zone4) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdVolume, 8, index)) return false;

    uint8_t parsedZone1 = msg.GetByte(index);
    uint8_t parsedZone2 = msg.GetByte(index);
    uint8_t parsedZone3 = msg.GetByte(index);
    uint8_t parsedZone4 = msg.GetByte(index);
    zone1 = parsedZone1;
    zone2 = parsedZone2;
    zone3 = parsedZone3;
    zone4 = parsedZone4;
    return true;
}

bool ParseFusionStatusCapabilities(const tN2kMsg& msg,
                                   tN2kFusionCapabilities& capabilities) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdCapabilities, 14, index)) return false;

    tN2kFusionCapabilities parsed;
    parsed.zone1 = msg.Get2ByteUInt(index);
    parsed.zone2 = msg.Get2ByteUInt(index);
    parsed.zone3 = msg.Get2ByteUInt(index);
    parsed.zone4 = msg.Get2ByteUInt(index);
    parsed.global = msg.Get2ByteUInt(index);
    capabilities = parsed;
    return true;
}

bool ParseFusionStatusLineLevelControl(const tN2kMsg& msg, uint8_t& zone,
                                       uint8_t& control) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdLineLevelControl, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedControl = msg.GetByte(index);
    zone = parsedZone;
    control = parsedControl;
    return true;
}

bool ParseFusionStatusPowerState(const tN2kMsg& msg, uint8_t& state) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdPower, 5, index)) return false;
    state = msg.GetByte(index);
    return true;
}

bool ParseFusionStatusSiriusXM(const tN2kMsg& msg, uint8_t& sourceID,
                               uint8_t& comState, uint8_t& alert,
                               uint16_t& advisoryChannel, uint8_t& tuningMode) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSirius, 10, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedComState = msg.GetByte(index);
    uint8_t parsedAlert = msg.GetByte(index);
    uint16_t parsedAdvisoryChannel = msg.Get2ByteUInt(index);
    uint8_t parsedTuningMode = msg.GetByte(index);
    sourceID = parsedSourceID;
    comState = parsedComState;
    alert = parsedAlert;
    advisoryChannel = parsedAdvisoryChannel;
    tuningMode = parsedTuningMode;
    return true;
}

bool ParseFusionStatusSiriusXMChannel(const tN2kMsg& msg, uint8_t& sourceID,
                                      uint16_t& channelNumber, char* channel,
                                      size_t channelBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMChannel, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedChannelNumber = msg.Get2ByteUInt(index);
    if (!ParseFusionString(msg, index, channel, channelBufSize)) return false;
    sourceID = parsedSourceID;
    channelNumber = parsedChannelNumber;
    return true;
}

bool ParseFusionStatusSiriusXMTitle(const tN2kMsg& msg, uint8_t& sourceID,
                                    uint16_t& channelNumber, char* title,
                                    size_t titleBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMTitle, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedChannelNumber = msg.Get2ByteUInt(index);
    if (!ParseFusionString(msg, index, title, titleBufSize)) return false;
    sourceID = parsedSourceID;
    channelNumber = parsedChannelNumber;
    return true;
}

bool ParseFusionStatusSiriusXMArtist(const tN2kMsg& msg, uint8_t& sourceID,
                                     uint16_t& channelNumber, char* artist,
                                     size_t artistBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMArtist, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedChannelNumber = msg.Get2ByteUInt(index);
    if (!ParseFusionString(msg, index, artist, artistBufSize)) return false;
    sourceID = parsedSourceID;
    channelNumber = parsedChannelNumber;
    return true;
}

bool ParseFusionStatusSiriusXMContentInfo(const tN2kMsg& msg, uint8_t& sourceID,
                                          uint16_t& channelNumber, char* genre,
                                          size_t genreBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMGenre, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedChannelNumber = msg.Get2ByteUInt(index);
    if (!ParseFusionString(msg, index, genre, genreBufSize)) return false;
    sourceID = parsedSourceID;
    channelNumber = parsedChannelNumber;
    return true;
}

bool ParseFusionStatusSiriusXMCategory(const tN2kMsg& msg, uint8_t& sourceID,
                                       uint16_t& channelNumber, char* name,
                                       size_t nameBufSize) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMCategory, -1, index) ||
        msg.GetRemainingDataLength(index) < 4) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint16_t parsedChannelNumber = msg.Get2ByteUInt(index);
    if (!ParseFusionString(msg, index, name, nameBufSize)) return false;
    sourceID = parsedSourceID;
    channelNumber = parsedChannelNumber;
    return true;
}

bool ParseFusionStatusSiriusXMSignal(const tN2kMsg& msg, uint8_t& sourceID,
                                     uint8_t& signal) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMSignal, 6, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedSignal = msg.GetByte(index);
    sourceID = parsedSourceID;
    signal = parsedSignal;
    return true;
}

bool ParseFusionStatusSiriusXMPresets(const tN2kMsg& msg, uint8_t& sourceID,
                                      uint8_t& count, uint8_t* values,
                                      size_t valuesCapacity, size_t& valuesLength) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSiriusXMPresets, -1, index) ||
        msg.GetRemainingDataLength(index) < 2) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint8_t parsedCount = msg.GetByte(index);
    int remaining = msg.GetRemainingDataLength(index);
    if (remaining < 0 || static_cast<size_t>(remaining) > valuesCapacity ||
        (remaining > 0 && values == NULL)) return false;

    for (int i = 0; i < remaining; ++i) values[i] = msg.GetByte(index);
    sourceID = parsedSourceID;
    count = parsedCount;
    valuesLength = static_cast<size_t>(remaining);
    return true;
}

bool ParseFusionStatusMenuActionStatus(const tN2kMsg& msg, uint8_t& sourceID,
                                       uint32_t& itemIndex, uint8_t& action,
                                       uint8_t& lockID) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMenuAction, 11, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedItemIndex = msg.Get4ByteUInt(index);
    uint8_t parsedAction = msg.GetByte(index);
    uint8_t parsedLockID = msg.GetByte(index);
    sourceID = parsedSourceID;
    itemIndex = parsedItemIndex;
    action = parsedAction;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionStatusMenuCount(const tN2kMsg& msg, uint8_t& sourceID,
                                uint32_t& count, uint8_t& lockID) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdMenuCount, 10, index)) return false;

    uint8_t parsedSourceID = msg.GetByte(index);
    uint32_t parsedCount = msg.Get4ByteUInt(index);
    uint8_t parsedLockID = msg.GetByte(index);
    sourceID = parsedSourceID;
    count = parsedCount;
    lockID = parsedLockID;
    return true;
}

bool ParseFusionStatusLoudness(const tN2kMsg& msg, uint8_t& zone,
                               uint8_t& enabled) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdLoudness, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedEnabled = msg.GetByte(index);
    zone = parsedZone;
    enabled = parsedEnabled;
    return true;
}

bool ParseFusionStatusZoneCapabilitiesExtended(
    const tN2kMsg& msg, tN2kFusionExtendedCapabilities& capabilities) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdZoneCapabilitiesExtended, 44, index)) return false;

    tN2kFusionExtendedCapabilities parsed;
    tN2kFusionCapabilityBlock* blocks[5] = {
        &parsed.zone1, &parsed.zone2, &parsed.zone3, &parsed.zone4, &parsed.global
    };
    for (size_t block = 0; block < 5; ++block) {
        blocks[block]->capabilities = msg.Get2ByteUInt(index);
        for (size_t byte = 0; byte < sizeof(blocks[block]->extra); ++byte) {
            blocks[block]->extra[byte] = msg.GetByte(index);
        }
    }
    capabilities = parsed;
    return true;
}

bool ParseFusionStatusExternalAmpGain(const tN2kMsg& msg, uint8_t& zone,
                                      uint8_t& gain) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdExternalAmpGain, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedGain = msg.GetByte(index);
    zone = parsedZone;
    gain = parsedGain;
    return true;
}

bool ParseFusionStatusInternalAmpGain(const tN2kMsg& msg, uint8_t& zone,
                                      uint8_t& gain) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdInternalAmpGain, 6, index)) return false;

    uint8_t parsedZone = msg.GetByte(index);
    uint8_t parsedGain = msg.GetByte(index);
    zone = parsedZone;
    gain = parsedGain;
    return true;
}

bool ParseFusionStatusSystemCapabilities(const tN2kMsg& msg,
                                         uint64_t& capabilities) {
    int index;
    if (!BeginFusionStatusParse(msg, N2kFusionStatusMessageIdSystemCapabilities, 12, index)) return false;

    uint32_t low = msg.Get4ByteUInt(index);
    uint32_t high = msg.Get4ByteUInt(index);
    capabilities = (static_cast<uint64_t>(high) << 32) | low;
    return true;
}