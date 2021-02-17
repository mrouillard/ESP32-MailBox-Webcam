#include <Arduino.h>
#include "camera.h"
#include "WiFi_func.h"
#include "SD.h"
#include "TimeLaps.h"
#include "HTTPApp.h"
#include "NTP.h"
#include "multicastDNS.h"
#include "settings.h"

void setup()
{
  Serial.begin(115200);
  Serial.println();

  SDInitFileSystem();
  CameraInit();

  WiFiInit();
  NTPInit();
  printLocalTime();
  mdnsInit(LOCAL_NAME, "ESP32-CAM for mailbox");

  HTTPAppStartCameraServer();
}

void loop()
{
  TimeLapsProcess();
}
