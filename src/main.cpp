#include <Arduino.h>
#include "camera.h"
#include "WiFi_func.h"
#include "SD.h"
#include "TimeLaps.h"
#include "HTTPApp.h"
#include "NTP.h"
#include "mDNS.h"

void setup() 
{
  Serial.begin(115200);
  Serial.println();

  SDInitFileSystem();
  CameraInit();

  WiFiInit();
  NTPInit();
  printLocalTime();
  mdnsInit("esp32cam","ESP32-CAM for mailbox");

  HTTPAppStartCameraServer();
}

void loop() 
{
	TimeLapsProcess();
}
