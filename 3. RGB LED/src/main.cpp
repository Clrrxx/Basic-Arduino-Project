#include <Arduino.h>

int redpin = 3;
int bluepin = 5;
int greenpin = 6;

#define delaytime 10

void setup(){
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(redpin, OUTPUT);
}

void setcolour(int redval, int greenval, int blueval){
  analogWrite(redpin, redval);
  analogWrite(greenpin, greenval);
  analogWrite(bluepin, blueval);
}

void loop(){
  //red -> yellow
  for (int i = 0; i<=255; i++){
    setcolour(255, i, 0);
    delay(delaytime);
  }

  //yellow -> green
  for (int i = 0; i<=255; i++){
    setcolour(255-i, 255, 0);
    delay(delaytime);
  }

  //green -> cyan
  for (int i = 0; i<=255; i++){
    setcolour(0, 255, i);
    delay(delaytime);
  }

  //cyan -> blue
  for (int i = 0; i<= 255; i++){
    setcolour(0, 255-i, 255);
    delay(delaytime);
  }

  //blue -> magenta
  for (int i = 0; i<= 255; i++){
    setcolour(i, 0, 255);
    delay(delaytime);
  }

  //magenta -> red;
  for (int i = 0; i<= 255; i++){
    setcolour(255, 0, 255-i);
    delay(delaytime);
  }
}
