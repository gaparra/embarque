#include <Arduino.h>

void OnLed(){
PORTB = PORTB | (1<<5);
}

void OffLed(){
PORTB = PORTB &~(1<<5);
}

void ledSetup(){
  DDRB = DDRB | (1<<5);
}

void setup() {
  // put your setup code here, to run once:
  ledSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  OnLed();
  delay(1000);
  OffLed();
  delay(1000);
}