#include <WiFi.h>


void setup() {
  Serial.begin(115200);
  
  //set wifi to stattion mode and disconnect from an access point if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup Done");
}

void loop() {
  Serial.println("scan start");

  //Wifi scan for all and return no. networks found
  int n = WiFi.scanNetworks();
  Serial.println("Scan done");
  if (n == 0){
    Serial.println("No Networks found");
  }else{
    Serial.print(n);
    Serial.println("Networks found");
    for (int i = 0; i<n; i++){
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); //signal strength
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " ":"*"); //encryption type
      delay(10);
    }
  }
  Serial.println("");

  //wait before scanning again
  delay(5000);
}