/****************************************************************************************************************************
 * Teensy40_ESP8266Shield.ino
 * For Teensy 4.0 using ESP8266 WiFi Shield
 *
 * Forked from Blynk library v0.6.1 https://github.com/blynkkk/blynk-library/releases
 * Built by Khoi Hoang https://github.com/khoih-prog/Blynk_Teensy
 * Licensed under MIT license
 *****************************************************************************************************************************/

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

void heartBeatPrint(void)
{
  static int num = 1;

  if (Blynk.connected())
  {
    Serial.print("B");
  }
  else
  {
    Serial.print("F");
  }
  
  if (num == 80) 
  {
    Serial.println();
    num = 1;
  }
  else if (num++ % 10 == 0) 
  {
    Serial.print(" ");
  }
} 

void check_status()
{
  static unsigned long checkstatus_timeout = 0;

#define STATUS_CHECK_INTERVAL     15000L

  // Send status report every STATUS_REPORT_INTERVAL (60) seconds: we don't need to send updates frequently if there is no status change.
  if ((millis() > checkstatus_timeout) || (checkstatus_timeout == 0))
  {
    // report status to Blynk
    heartBeatPrint();

    checkstatus_timeout = millis() + STATUS_CHECK_INTERVAL;
  }
}

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
  check_status();
}
