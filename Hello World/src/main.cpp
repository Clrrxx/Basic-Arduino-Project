#include <Arduino.h>

int val;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  val = Serial.read();
  if (val == 'A'){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.println("Hello World");
  }

}
