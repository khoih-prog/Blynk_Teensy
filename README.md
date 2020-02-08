## Blynk_Teensy

[![arduino-library-badge](https://www.ardu-badge.com/badge/Blynk_Teensy.svg?)](https://www.ardu-badge.com/Blynk_Teensy)

To enable Blynk support of Teensy boards, especially latest Teensy 4.0

### Installation

The suggested way to install is to:

1. Navigate to [Blynk_Teensy](https://github.com/khoih-prog/Blynk_Teensy) page.
2. Download the latest release `Blynk_Teensy-master.zip`.
3. Extract the zip file to `Blynk_Teensy-master` directory 
4. Copy whole `Blynk_Teensy-master/src` folder to Arduino libraries' `src` directory such as `~/Arduino/libraries/Blynk/src`.

The file BlynkSimpleShieldEsp8266_Teensy.h must be placed in Blynk libraries `src` directory (normally `~/Arduino/libraries/Blynk/src`), BlynkDetectDevice.h must be placed in Blynk libraries `src/Blynk` and replace the original file.


### How to use

In your code, replace
1. `BlynkSimpleShieldEsp8266.h` with `BlynkSimpleShieldEsp8266_Teensy.h`

That's it.

Also see examples: 
1. [Teensy40_ESP8266Shield](examples/Teensy40_ESP8266Shield)
2. [Teensy40_Serial_USB](examples/Teensy40_Serial_USB)


## Prerequisite
* [`Teensy core 1.49 or later`](https://www.pjrc.com/teensy/td_download.html)
* [`Blynk library 0.6.1 or later`](https://github.com/blynkkk/blynk-library/releases)

## Sample code
```
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

### Releases v1.0.0

***Why this version***

To add support to latest Teensy 4.0 boards. 

## TO DO

1. Same features for other shields such as WiFi, Ethernet, BT/BLE, GSM/GPRS.

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

## Copyright

Copyright 2020- Khoi Hoang
