#include <Arduino.h>
int buttonApin = 9;
int buttonBpin = 8;
int ledpin = 5;

void setup() {
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonApin) == LOW){
    digitalWrite(ledpin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW){
    digitalWrite(ledpin, LOW);
  }
}
