#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <Arduino.h>

const char *ssid = "yourAP";
const char *password = "yourPass";


WiFiServer server(80);

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server Begin");
}

void loop(){
  WiFiClient client = server.available();   //listen for incoming clients

  if (client){
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()){
      if (client.available()){
        char c = client.read();
        Serial.write(c);

        if (c == '\n'){

          if (currentLine.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            client.print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");

            client.println();
            break;
          }else{
            currentLine = "";
          }
        }else if (c != '\r'){
          currentLine += c;
        }
        if (currentLine.endsWith("GET /H")){
          digitalWrite(BUILTIN_LED, HIGH);
        }else if (currentLine.endsWith("GET /L")){
          digitalWrite(BUILTIN_LED, LOW);
        }
      }
    }
  }
}