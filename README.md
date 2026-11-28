# NMEA2000 Fusion Messages

C++ helpers for building and parsing Fusion-specific messages for NMEA 2000. Field definitions are based on the [Canboat PGN documentation](https://canboat.github.io/canboat/canboat.html).

## Features

- Setters and matching parsers for Fusion commands on PGN **126720**.
- Setters and matching parsers for the supported Fusion status variants on PGN **130820**.
- Fusion enums and bitfields in `src/N2KFusionTypes.h`.
- Enum-to-string conversion in `src/N2kFusionMessagesEnumToStr.h`.

The default transmission intervals for status messages are not known in the Canboat documentation. This library does not assume or define any intervals.

## Requirements and integration

This project requires the NMEA2000 library, which provides `N2kMessages.h` and `tN2kMsg`. Add `src` to your project and compile `N2kFusionMessages.cpp` with your application. A `library.properties` file or a separate build system is not currently included.

Example message creation and parsing:

```cpp
#include <N2kMessages.h>
#include "N2kFusionMessages.h"

void example(tN2kMsg& receivedMessage) {
    tN2kMsg commandMessage;
    SetFusionMediaControl(commandMessage, 1, N2kFusionCommandPlay);

    uint8_t sourceID;
    tN2kFusionCommand command;
    if (ParseFusionMediaControl(receivedMessage, sourceID, command)) {
        // The message contains a valid Fusion media command.
    }
}
```

You can then send `commandMessage` through your NMEA2000 integration like any other `tN2kMsg`.

## Supported commands: PGN 126720

The setters and parsers cover media and Sirius control, status and source requests, tuner commands, settings, audio and zone control, menu actions, and device and zone names. These include:

- `SetFusionMediaControl` / `ParseFusionMediaControl`
- `SetFusionTunerCommand` / `ParseFusionTunerCommand`
- `SetFusionSetting` / `ParseFusionSetting`
- `SetFusionMenuAction` / `ParseFusionMenuAction`
- `SetFusionZoneName` / `ParseFusionZoneName`
- `SetFusionDeviceName` / `ParseFusionDeviceName`

Each available setter has a matching parser. See `src/N2kFusionMessages.h` for parameter and return-value details.

## Status messages: PGN 130820

Status setters and parsers are declared as `SetFusionStatus...` and `ParseFusionStatus...` functions in `src/N2kFusionMessages.h`. They build and decode version information, sources, media and track information, tuner and menu status, settings, zone values, SiriusXM data, and device capabilities.

Example building a status message:

```cpp
tN2kMsg statusMessage;
SetFusionStatusVolumes(statusMessage, 20, 22, 24, 26);
```

Example parsing a string status:

```cpp
char deviceName[64];
if (ParseFusionStatusDeviceName(receivedMessage, deviceName, sizeof(deviceName))) {
    // deviceName contains the null-terminated name.
}
```

Example parsing a settings list:

```cpp
tN2kFusionSettingEntry entries[8];
uint32_t count;
if (ParseFusionStatusSettings(receivedMessage, count, entries, 8)) {
    // The parsed entries are in entries; count is their number.
}
```

The capacity passed to `ParseFusionStatusSettings` is measured in entries. The parser fails if the provided capacity is too small for the message. String parsers require an output buffer with space for the terminating null character; string setters return `false` for null or oversized input. `SetFusionStatusRDSData` also requires exactly 30 characters to match the fixed-size field parsed by `ParseFusionStatusRDSData`. `SetFusionStatusSettings` and `SetFusionStatusSiriusXMPresets` return `false` for invalid pointers or payloads that exceed the NMEA 2000 message capacity. SiriusXM preset data is returned/set as raw bytes because Canboat describes the field as binary data.

The parsers return `false` if the PGN, manufacturer/industry field, message ID, fixed payload length, or output buffer is invalid. Enum-like status values are returned as raw values so that unknown future values are preserved.

## Enum strings

`src/N2kFusionMessagesEnumToStr.h` provides overloaded `N2kEnumFusionTypeToStr` functions:

```cpp
#include "N2kFusionMessagesEnumToStr.h"

const char* commandName = N2kEnumFusionTypeToStr(N2kFusionCommandPlay);
```

Unknown values return an empty string. `PrintN2kEnumFusionType` prints `unknown` for unknown values. For bitfields, the conversion function expects a single flag, not a combined mask.
