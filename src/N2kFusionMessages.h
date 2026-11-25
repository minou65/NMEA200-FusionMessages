/**
 * @file N2kFusionMessages.h
 * @brief Builders and parsers for Fusion Electronics commands and requests on PGN 126720.
 *
 * Field layouts follow the Fusion-specific PGN descriptions in the
 * Canboat documentation. Parsers reject messages with an unexpected PGN,
 * manufacturer/message identifier, or payload length.
 */

#ifndef _N2KFUSIONMESSAGES_h
#define _N2KFUSIONMESSAGES_h

#include <N2kMessages.h>
#include <stdint.h>
#include <stddef.h>
#include "N2KFusionTypes.h"

/**
 * @brief Builds a Fusion media control command.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Fusion source identifier.
 * @param[in] command Media command to send.
 */
void SetFusionMediaControl(tN2kMsg& msg, uint8_t sourceID, tN2kFusionCommand command);

/**
 * @brief Builds a Fusion Sirius control command.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Fusion source identifier.
 * @param[in] command Sirius command to send.
 * @param[in] data Command-specific 16-bit data.
 */
void SetFusionSiriusControl(tN2kMsg& msg, uint8_t sourceID, tN2kFusionSiriusCommand command, uint16_t data);

/**
 * @brief Builds a request for the current Fusion status.
 * @param[out] msg Message to populate.
 */
void SetFusionRequestStatus(tN2kMsg& msg);

/**
 * @brief Builds a request to change the active Fusion source.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Source to select.
 */
void SetFusionSource(tN2kMsg& msg, uint8_t sourceID);

/**
 * @brief Builds a Fusion mute command.
 * @param[out] msg Message to populate.
 * @param[in] command Mute-on or mute-off command.
 */
void SetFusionMute(tN2kMsg& msg, tN2kFusionMuteCommand command);

/**
 * @brief Builds a command to set the volume of one zone.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] volume Volume value for the zone.
 */
void SetFusionZoneVolume(tN2kMsg& msg, uint8_t zone, uint8_t volume);

/**
 * @brief Builds a command to set all four zone volumes.
 * @param[out] msg Message to populate.
 * @param[in] zone1 Volume for zone 1.
 * @param[in] zone2 Volume for zone 2.
 * @param[in] zone3 Volume for zone 3.
 * @param[in] zone4 Volume for zone 4.
 */
void SetFusionAllVolumes(tN2kMsg& msg, uint8_t zone1, uint8_t zone2, uint8_t zone3, uint8_t zone4);

/**
 * @brief Builds a Fusion power command.
 * @param[out] msg Message to populate.
 * @param[in] power Requested power state.
 */
void SetFusionPower(tN2kMsg& msg, tN2kFusionPowerState power);

/**
 * @brief Builds a command to perform an action on a Fusion menu item.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Menu source identifier.
 * @param[in] itemIndex Index of the menu item.
 * @param[in] action Action to perform.
 * @param[in] lockID Current menu lock identifier.
 */
void SetFusionMenuAction(tN2kMsg& msg, uint8_t sourceID, uint32_t itemIndex, tN2kFusionMenuAction action, uint8_t lockID);

/**
 * @brief Builds a request for the number of items in a Fusion menu.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Menu source identifier.
 * @param[in] lockID Current menu lock identifier.
 */
void SetFusionRequestMenuCount(tN2kMsg& msg, uint8_t sourceID, uint8_t lockID);

/**
 * @brief Builds a request for a range of Fusion menu items.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Menu source identifier.
 * @param[in] startIndex Index of the first requested item.
 * @param[in] count Number of items to request.
 * @param[in] lockID Current menu lock identifier.
 */
void SetFusionRequestMenuItems(tN2kMsg& msg, uint8_t sourceID, uint32_t startIndex, uint32_t count, uint8_t lockID);

/**
 * @brief Builds a request for a Fusion menu lock identifier.
 * @param[out] msg Message to populate.
 * @param[in] requestToken Token identifying this request.
 */
void SetFusionRequestMenuLockID(tN2kMsg& msg, uint32_t requestToken);

/**
 * @brief Builds a command to set a Fusion setting.
 * @param[out] msg Message to populate.
 * @param[in] id Setting identifier.
 * @param[in] value Setting value; its interpretation depends on @p id.
 */
void SetFusionSetting(tN2kMsg& msg, tN2kFusionSetting id, uint32_t value);

/**
 * @brief Builds a Fusion tuner command.
 * @param[out] msg Message to populate.
 * @param[in] source Radio source to control.
 * @param[in] command Tuner operation.
 * @param[in] frequencyHz Frequency in hertz; used by direct-tune commands.
 */
void SetFusionTunerCommand(tN2kMsg& msg, tN2kFusionRadioSource source, tN2kFusionTunerCommand command, uint32_t frequencyHz);

/**
 * @brief Builds a command to set the gain of an auxiliary source.
 * @param[out] msg Message to populate.
 * @param[in] sourceID Auxiliary source identifier.
 * @param[in] gain Gain value.
 */
void SetFusionAuxGain(tN2kMsg& msg, uint8_t sourceID, uint8_t gain);

/**
 * @brief Builds a command to set the balance of a zone.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] value Balance value.
 */
void SetFusionBalance(tN2kMsg& msg, uint8_t zone, uint8_t value);

/**
 * @brief Builds a command to set a zone's low-pass filter.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] filter Low-pass filter selection.
 */
void SetFusionLowPassFilter(tN2kMsg& msg, uint8_t zone, tN2kFusionLowPassFilter filter);

/**
 * @brief Builds a command to set a zone's subwoofer level.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] level Subwoofer level.
 */
void SetFusionSublevel(tN2kMsg& msg, uint8_t zone, uint8_t level);

/**
 * @brief Builds a command to set a zone's volume limit.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] limit Volume limit.
 */
void SetFusionVolumeLimit(tN2kMsg& msg, uint8_t zone, uint8_t limit);

/**
 * @brief Builds a command to set a Fusion zone name.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] name Null-terminated name encoded using Fusion's STRING_LZ format.
 * @return true if the message was built; false if @p name is null or too long.
 */
bool SetFusionZoneName(tN2kMsg& msg, uint8_t zone, const char* name);

/**
 * @brief Builds a command to set a zone's equalizer values.
 * @param[out] msg Message to populate.
 * @param[in] zone Zone identifier.
 * @param[in] bass Bass value.
 * @param[in] mid Midrange value.
 * @param[in] treble Treble value.
 */
void SetFusionEqualizer(tN2kMsg& msg, uint8_t zone, uint8_t bass, uint8_t mid, uint8_t treble);

/**
 * @brief Builds a command to set subwoofer levels for all four zones.
 * @param[out] msg Message to populate.
 * @param[in] zone1 Subwoofer level for zone 1.
 * @param[in] zone2 Subwoofer level for zone 2.
 * @param[in] zone3 Subwoofer level for zone 3.
 * @param[in] zone4 Subwoofer level for zone 4.
 */
void SetFusionAllSublevels(tN2kMsg& msg, uint8_t zone1, uint8_t zone2, uint8_t zone3, uint8_t zone4);

/**
 * @brief Builds a command to set the Fusion device name.
 * @param[out] msg Message to populate.
 * @param[in] name Null-terminated name encoded using Fusion's STRING_LZ format.
 * @return true if the message was built; false if @p name is null or too long.
 */
bool SetFusionDeviceName(tN2kMsg& msg, const char* name);

/**
 * @brief Parses a Fusion media control command.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Fusion source identifier.
 * @param[out] command Media command.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionMediaControl(const tN2kMsg& msg, uint8_t& sourceID, tN2kFusionCommand& command);

/**
 * @brief Parses a Fusion Sirius control command.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Fusion source identifier.
 * @param[out] command Sirius command.
 * @param[out] data Command-specific 16-bit data.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionSiriusControl(const tN2kMsg& msg, uint8_t& sourceID, tN2kFusionSiriusCommand& command, uint16_t& data);

/**
 * @brief Checks whether a message is a Fusion status request.
 * @param[in] msg Incoming message.
 * @return true if the message is a valid status request.
 */
bool ParseFusionRequestStatus(const tN2kMsg& msg);

/**
 * @brief Parses a Fusion source selection command.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Selected source identifier.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionSource(const tN2kMsg& msg, uint8_t& sourceID);

/**
 * @brief Parses a Fusion mute command.
 * @param[in] msg Incoming message.
 * @param[out] command Mute command.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionMute(const tN2kMsg& msg, tN2kFusionMuteCommand& command);

/**
 * @brief Parses a command to set one zone's volume.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] volume Volume value.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionZoneVolume(const tN2kMsg& msg, uint8_t& zone, uint8_t& volume);

/**
 * @brief Parses a command to set all four zone volumes.
 * @param[in] msg Incoming message.
 * @param[out] zone1 Volume for zone 1.
 * @param[out] zone2 Volume for zone 2.
 * @param[out] zone3 Volume for zone 3.
 * @param[out] zone4 Volume for zone 4.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionAllVolumes(const tN2kMsg& msg, uint8_t& zone1, uint8_t& zone2, uint8_t& zone3, uint8_t& zone4);

/**
 * @brief Parses a Fusion power command.
 * @param[in] msg Incoming message.
 * @param[out] power Requested power state.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionPower(const tN2kMsg& msg, tN2kFusionPowerState& power);

/**
 * @brief Parses a command to perform an action on a Fusion menu item.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Menu source identifier.
 * @param[out] itemIndex Menu item index.
 * @param[out] action Action to perform.
 * @param[out] lockID Menu lock identifier.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionMenuAction(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& itemIndex, tN2kFusionMenuAction& action, uint8_t& lockID);

/**
 * @brief Parses a request for the number of items in a Fusion menu.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Menu source identifier.
 * @param[out] lockID Menu lock identifier.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionRequestMenuCount(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& lockID);

/**
 * @brief Parses a request for a range of Fusion menu items.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Menu source identifier.
 * @param[out] startIndex Index of the first requested item.
 * @param[out] count Number of requested items.
 * @param[out] lockID Menu lock identifier.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionRequestMenuItems(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& startIndex, uint32_t& count, uint8_t& lockID);

/**
 * @brief Parses a request for a Fusion menu lock identifier.
 * @param[in] msg Incoming message.
 * @param[out] requestToken Token identifying the request.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionRequestMenuLockID(const tN2kMsg& msg, uint32_t& requestToken);

/**
 * @brief Parses a command to set a Fusion setting.
 * @param[in] msg Incoming message.
 * @param[out] id Raw 32-bit setting identifier; known values map to @ref tN2kFusionSetting.
 * @param[out] value Setting value.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionSetting(const tN2kMsg& msg, uint32_t& id, uint32_t& value);

/**
 * @brief Parses a Fusion tuner command.
 * @param[in] msg Incoming message.
 * @param[out] source Radio source.
 * @param[out] command Tuner operation.
 * @param[out] frequencyHz Frequency in hertz.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionTunerCommand(const tN2kMsg& msg, tN2kFusionRadioSource& source, tN2kFusionTunerCommand& command, uint32_t& frequencyHz);

/**
 * @brief Parses a command to set the gain of an auxiliary source.
 * @param[in] msg Incoming message.
 * @param[out] sourceID Auxiliary source identifier.
 * @param[out] gain Gain value.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionAuxGain(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& gain);

/**
 * @brief Parses a command to set a zone's balance.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] value Balance value.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionBalance(const tN2kMsg& msg, uint8_t& zone, uint8_t& value);

/**
 * @brief Parses a command to set a zone's low-pass filter.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] filter Low-pass filter.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionLowPassFilter(const tN2kMsg& msg, uint8_t& zone, tN2kFusionLowPassFilter& filter);

/**
 * @brief Parses a command to set a zone's subwoofer level.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] level Subwoofer level.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionSublevel(const tN2kMsg& msg, uint8_t& zone, uint8_t& level);

/**
 * @brief Parses a command to set a zone's volume limit.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] limit Volume limit.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionVolumeLimit(const tN2kMsg& msg, uint8_t& zone, uint8_t& limit);

/**
 * @brief Parses a command to set a Fusion zone name.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] name Destination buffer for the null-terminated name.
 * @param[in] nameBufSize Size of @p name in bytes.
 * @return true if the message is valid and the name fits; otherwise false.
 */
bool ParseFusionZoneName(const tN2kMsg& msg, uint8_t& zone, char* name, size_t nameBufSize);

/**
 * @brief Parses a command to set a zone's equalizer values.
 * @param[in] msg Incoming message.
 * @param[out] zone Zone identifier.
 * @param[out] bass Bass value.
 * @param[out] mid Midrange value.
 * @param[out] treble Treble value.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionEqualizer(const tN2kMsg& msg, uint8_t& zone, uint8_t& bass, uint8_t& mid, uint8_t& treble);

/**
 * @brief Parses a command to set subwoofer levels for all four zones.
 * @param[in] msg Incoming message.
 * @param[out] zone1 Subwoofer level for zone 1.
 * @param[out] zone2 Subwoofer level for zone 2.
 * @param[out] zone3 Subwoofer level for zone 3.
 * @param[out] zone4 Subwoofer level for zone 4.
 * @return true if the PGN, message ID, and payload length match.
 */
bool ParseFusionAllSublevels(const tN2kMsg& msg, uint8_t& zone1, uint8_t& zone2, uint8_t& zone3, uint8_t& zone4);

/**
 * @brief Parses a command to set the Fusion device name.
 * @param[in] msg Incoming message.
 * @param[out] name Destination buffer for the null-terminated name.
 * @param[in] nameBufSize Size of @p name in bytes.
 * @return true if the message is valid and the name fits; otherwise false.
 */
bool ParseFusionDeviceName(const tN2kMsg& msg, char* name, size_t nameBufSize);

struct tN2kFusionSettingEntry {
    uint32_t id;
    uint32_t value;
};

struct tN2kFusionCapabilities {
    uint16_t zone1;
    uint16_t zone2;
    uint16_t zone3;
    uint16_t zone4;
    uint16_t global;
};

struct tN2kFusionCapabilityBlock {
    uint16_t capabilities;
    uint8_t extra[6];
};

struct tN2kFusionExtendedCapabilities {
    tN2kFusionCapabilityBlock zone1;
    tN2kFusionCapabilityBlock zone2;
    tN2kFusionCapabilityBlock zone3;
    tN2kFusionCapabilityBlock zone4;
    tN2kFusionCapabilityBlock global;
};

/**
 * @defgroup N2kFusionStatusParsers PGN 130820 status parsers
 * @brief Parsers for the Fusion status messages carried by PGN 130820.
 *
 * Each parser validates the status message ID and fixed payload size where
 * applicable. String outputs use Fusion STRING_LZ encoding and require a
 * caller-provided null-terminated output buffer. Enum-like values are returned
 * as their raw integer representation to preserve unknown future values.
 * The Settings parser expects capacity in entries. The SiriusXM Presets parser
 * expects capacity in bytes and reports the number of binary bytes returned.
 * @{
 */
bool ParseFusionStatusVersions(const tN2kMsg& msg, uint16_t& hardwareMajor, uint16_t& hardwareMinor,
                               uint8_t& softwareMajor, uint8_t& softwareMinor, uint8_t& buildNumber);
bool ParseFusionStatusSource(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& currentSourceID,
                             uint8_t& sourceType, uint8_t& flags, char* source, size_t sourceBufSize);
bool ParseFusionStatusSourceCount(const tN2kMsg& msg, uint8_t& sourceCount);
bool ParseFusionStatusMedia(const tN2kMsg& msg, uint8_t& sourceID, uint16_t& flags,
                            uint32_t& trackNumber, uint32_t& trackCount,
                            uint32_t& length, uint32_t& position);
bool ParseFusionStatusTrackName(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& itemIndex,
                                char* track, size_t trackBufSize);
bool ParseFusionStatusArtistName(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& itemIndex,
                                 char* artist, size_t artistBufSize);
bool ParseFusionStatusAlbumName(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& itemIndex,
                                char* album, size_t albumBufSize);
bool ParseFusionStatusDeviceName(const tN2kMsg& msg, char* name, size_t nameBufSize);
bool ParseFusionStatusZoneName(const tN2kMsg& msg, uint8_t& zone, char* name, size_t nameBufSize);
bool ParseFusionStatusSpeedVolumeCurrentSpeed(const tN2kMsg& msg, uint8_t& sourceID,
                                              uint16_t& speed, uint8_t& enabled);
bool ParseFusionStatusIgnitionSwitchState(const tN2kMsg& msg, uint8_t& state);
bool ParseFusionStatusMenuLockID(const tN2kMsg& msg, uint32_t& requestToken, uint8_t& lockID);
bool ParseFusionStatusRDSData(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& rdsType,
                              uint8_t& programmeType, char* rds, size_t rdsBufSize);
bool ParseFusionStatusMultiroom(const tN2kMsg& msg, uint8_t& enabled, uint8_t ipAddress[4]);
bool ParseFusionStatusMultiroomStatus(const tN2kMsg& msg, uint8_t& available);
bool ParseFusionStatusProcessingBypass(const tN2kMsg& msg, uint8_t& bypass);
bool ParseFusionStatusMono(const tN2kMsg& msg, uint8_t& zone, uint8_t& enabled);
bool ParseFusionStatusTrackPosition(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& progress);
bool ParseFusionStatusTuner(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& scanning,
                            uint32_t& frequency, uint8_t& signalStrength,
                            char* track, size_t trackBufSize);
bool ParseFusionStatusMarineTuner(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& channel,
                                  uint8_t& signalStrength, char* name, size_t nameBufSize);
bool ParseFusionStatusMarineSquelch(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& squelch);
bool ParseFusionStatusMarineScanMode(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& scanMode);
bool ParseFusionStatusMenuItem(const tN2kMsg& msg, uint8_t& sourceID, uint32_t& itemIndex,
                               uint8_t& flags, uint8_t& lockID, char* text, size_t textBufSize);
bool ParseFusionStatusAuxGain(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& gain);
bool ParseFusionStatusUSBRepeatStatus(const tN2kMsg& msg, uint32_t& status);
bool ParseFusionStatusSetting(const tN2kMsg& msg, uint32_t& id, uint32_t& value);
bool ParseFusionStatusSettings(const tN2kMsg& msg, uint32_t& count,
                               tN2kFusionSettingEntry* entries, size_t entriesCapacity);
bool ParseFusionStatusMute(const tN2kMsg& msg, uint8_t& mute);
bool ParseFusionStatusBalance(const tN2kMsg& msg, uint8_t& zone, uint8_t& value);
bool ParseFusionStatusLowPassFilter(const tN2kMsg& msg, uint8_t& zone, uint8_t& filter);
bool ParseFusionStatusSublevels(const tN2kMsg& msg, uint8_t& zone1, uint8_t& zone2,
                                uint8_t& zone3, uint8_t& zone4);
bool ParseFusionStatusEQ(const tN2kMsg& msg, uint8_t& zone, uint8_t& bass,
                         uint8_t& mid, uint8_t& treble);
bool ParseFusionStatusVolumeLimits(const tN2kMsg& msg, uint8_t& zone1, uint8_t& zone2,
                                   uint8_t& zone3, uint8_t& zone4);
bool ParseFusionStatusVolumes(const tN2kMsg& msg, uint8_t& zone1, uint8_t& zone2,
                              uint8_t& zone3, uint8_t& zone4);
bool ParseFusionStatusCapabilities(const tN2kMsg& msg, tN2kFusionCapabilities& capabilities);
bool ParseFusionStatusLineLevelControl(const tN2kMsg& msg, uint8_t& zone, uint8_t& control);
bool ParseFusionStatusPowerState(const tN2kMsg& msg, uint8_t& state);
bool ParseFusionStatusSiriusXM(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& comState,
                               uint8_t& alert, uint16_t& advisoryChannel, uint8_t& tuningMode);
bool ParseFusionStatusSiriusXMChannel(const tN2kMsg& msg, uint8_t& sourceID,
                                      uint16_t& channelNumber, char* channel, size_t channelBufSize);
bool ParseFusionStatusSiriusXMTitle(const tN2kMsg& msg, uint8_t& sourceID,
                                    uint16_t& channelNumber, char* title, size_t titleBufSize);
bool ParseFusionStatusSiriusXMArtist(const tN2kMsg& msg, uint8_t& sourceID,
                                     uint16_t& channelNumber, char* artist, size_t artistBufSize);
bool ParseFusionStatusSiriusXMContentInfo(const tN2kMsg& msg, uint8_t& sourceID,
                                          uint16_t& channelNumber, char* genre, size_t genreBufSize);
bool ParseFusionStatusSiriusXMCategory(const tN2kMsg& msg, uint8_t& sourceID,
                                       uint16_t& channelNumber, char* name, size_t nameBufSize);
bool ParseFusionStatusSiriusXMSignal(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& signal);
bool ParseFusionStatusSiriusXMPresets(const tN2kMsg& msg, uint8_t& sourceID, uint8_t& count,
                                      uint8_t* values, size_t valuesCapacity, size_t& valuesLength);
bool ParseFusionStatusMenuActionStatus(const tN2kMsg& msg, uint8_t& sourceID,
                                       uint32_t& itemIndex, uint8_t& action, uint8_t& lockID);
bool ParseFusionStatusMenuCount(const tN2kMsg& msg, uint8_t& sourceID,
                                uint32_t& count, uint8_t& lockID);
bool ParseFusionStatusLoudness(const tN2kMsg& msg, uint8_t& zone, uint8_t& enabled);
bool ParseFusionStatusZoneCapabilitiesExtended(const tN2kMsg& msg,
                                                tN2kFusionExtendedCapabilities& capabilities);
bool ParseFusionStatusExternalAmpGain(const tN2kMsg& msg, uint8_t& zone, uint8_t& gain);
bool ParseFusionStatusInternalAmpGain(const tN2kMsg& msg, uint8_t& zone, uint8_t& gain);
bool ParseFusionStatusSystemCapabilities(const tN2kMsg& msg, uint64_t& capabilities);

/** @} */

#endif
