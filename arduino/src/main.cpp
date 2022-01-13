#include <Arduino.h>

void OnLed(){
PORTB = PORTB | (1<<5);
}

void OffLed(){
PORTB = PORTB &~(1<<5);
}

void toggle(){
  PINB |= (1 << 5);
}

void ledSetup(){
  DDRB = DDRB | (1<<5);
}

void timerSetup(){
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10);
  OCR1A = 15625;
  TCNT1 = 0;
  TIMSK1 = (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect){
  toggle();
}

void setup() {
  // put your setup code here, to run once:
  ledSetup();
  timerSetup();
}

void loop() {
}