## Blynk_Teensy

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_Teensy.svg?)](https://www.ardu-badge.com/Blynk_Teensy)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/Blynk_Teensy.svg)](https://github.com/khoih-prog/Blynk_Teensy/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/Blynk_Teensy/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/Blynk_Teensy.svg)](http://github.com/khoih-prog/Blynk_Teensy/issues)

---
---

## Table of Contents

* [Why do we need this Blynk_Teensy library](#why-do-we-need-this-Blynk_Teensy-library)
  * [Features](#features)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [How to use](#How-to-use)
* [Examples](#examples)
  * [ 1. Teensy40_ESP8266Shield](examples/Teensy40_ESP8266Shield)
  * [ 2. Teensy40_Serial_USB](examples/Teensy40_Serial_USB)
* [Sample code](#Sample-code)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)


  
---
---

### Why do we need this [Blynk_Teensy library](https://github.com/khoih-prog/Blynk_Teensy)

#### Features

To enable Blynk support of Teensy boards, especially latest Teensy 4.1/4.0

---
---

## Prerequisites

 1. [`Arduino IDE 1.8.16+`](https://www.arduino.cc/en/Main/Software)
 2. [`Blynk library 1.0.1+`](https://github.com/blynkkk/blynk-library/releases). [![Latest release](https://img.shields.io/github/release/blynkkk/blynk-library.svg)](https://github.com/blynkkk/blynk-library/releases/latest/). Never use the `Blynk beta` versions.
 3. [`Teensy core v1.55+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards.
 
---

### Installation

The suggested way to install is to:

#### Use Arduino Library Manager

The best way is to use `Arduino Library Manager`. Search for `Blynk_Teensy`, then select / install the latest version. You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_Teensy.svg?)](https://www.ardu-badge.com/Blynk_Teensy) for more detailed instructions.

Then copy [BlynkDetectDevice.h](https://github.com/khoih-prog/Blynk_Esp8266AT_WM/blob/master/src/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`.

#### Manual Install

1. Navigate to [Blynk_Teensy](https://github.com/khoih-prog/Blynk_Teensy) page.
2. Download the latest release `Blynk_Teensy-master.zip`.
3. Extract the zip file to `Blynk_Teensy-master` directory 
4. Copy whole 
  - `Blynk_Teensy-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.
  
The file BlynkSimpleShieldEsp8266_Teensy.h must be placed in Blynk libraries `src` directory (normally `~/Arduino/libraries/Blynk/src`).
  
Then copy [BlynkDetectDevice.h](https://github.com/khoih-prog/Blynk_Esp8266AT_WM/blob/master/src/Blynk/BlynkDetectDevice.h) to folder ~/Arduino/libraries/Blynk/src/Blynk to overwrite the original file `BlynkDetectDevice.h`. By doing this, the correct board type can be displayed correctly along with Blynk logo as follows:

```
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Teensy 4.1/4.0
```

not just unknown Arduino board type:

```
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Arduino
```

#### VS Code & PlatformIO:

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**Blynk_Teensy** library](https://platformio.org/lib/show/7024/Blynk_Teensy) by using [Library Manager](https://platformio.org/lib/show/7024/Blynk_Teensy/installation). Search for **Blynk_Teensy** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### How to use

In your code, just replace

1. `BlynkSimpleShieldEsp8266.h` with `BlynkSimpleShieldEsp8266_Teensy.h`

That's it.

---

### Examples

1. [Teensy40_ESP8266Shield](examples/Teensy40_ESP8266Shield)
2. [Teensy40_Serial_USB](examples/Teensy40_Serial_USB)

---

## Sample code

```cpp
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

// You could use a spare Hardware Serial on boards that have it (like Mega)

#define HWSERIAL        Serial2       // Pin RX2 : 7, TX2 : 8 for Teensy 4.0

#include <ESP8266_Lib.h>

#include <BlynkSimpleShieldEsp8266_Teensy.h>

String cloudBlynkServer = "account.duckdns.org";

#define BLYNK_SERVER_HARDWARE_PORT    8080

char auth[] = "your-token";

#define SSID_MAX_LEN      32
#define PASS_MAX_LEN      64

// Your WiFi credentials.
char ssid[] = "ssid";
char pass[] = "pass";

#define EspSerial Serial2   //Serial2, Pin RX2 : 7, TX2 : 8

// Your Teensy <-> ESP8266 baud rate:
#define ESP8266_BAUD 115200

ESP8266 wifi(&EspSerial);

void setup() 
{
  // Debug console
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStart Teensy 4.0");

  // Set ESP8266 baud rate
  EspSerial.begin(ESP8266_BAUD);
  delay(10);

  Serial.println("Start Blynk");

  Blynk.begin(auth, wifi, ssid, pass, cloudBlynkServer.c_str(), BLYNK_SERVER_HARDWARE_PORT);
}

void loop()
{
  Blynk.run();
}
```

and this is the terminal debug output when running the example

```
Start Teensy 4.0
Start Blynk
[1310] 
    ___  __          __
   / _ )/ /_ _____  / /__
  / _  / / // / _ \/  '_/
 /____/_/\_, /_//_/_/\_\
        /___/ v0.6.1 on Teensy 4.0

[1310] Connecting to HueNet1
[7876] AT version:0.40.0.0(Aug  8 2015 14:45:58)
SDK version:1.3.0
Ai-Thinker Technology Co.,Ltd.
Build:1.3.0.2 Sep 11 2015 11:48:04
OK
[15448] IP = 192.168.2.107
+CIFSR:STAMAC,5c:cf:7f:66:05:d2
[15448] Connected to WiFi
[25601] Ready (ping: 14ms).
```

---
---

### Issues

Submit issues to: [Blynk_Teensy issues](https://github.com/khoih-prog/Blynk_Teensy/issues)


---

## TO DO

1. Same features for other shields such as WiFi, Ethernet, BT/BLE, GSM/GPRS.

---

## DONE

1. Basic support for Teensy

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

---


### Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/Blynk_Teensy/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang
