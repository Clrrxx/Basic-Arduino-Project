#include <WiFi.h>
#include "time.h"

const char *ssid = "SINGTEL-03D8";
const char *password = "bwkpzCu3uD7y";

const char *ntpServer = "pool.ntp.org";
const long gmtoffset = 28800;
const int daylightoffset = 0;

void printLocal(){
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

void setup(){
  Serial.begin(115200);
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED");

  configTime(gmtoffset, daylightoffset, ntpServer);
  printLocal();

  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop(){
  delay(1000);
  printLocal();
}