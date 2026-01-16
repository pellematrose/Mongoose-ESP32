#include "setup_pins.h"
#include <Arduino.h>
#include "my_globals.h"

// constants
const int unused0Pin = 0; // lo when finished with charging
//const int adc1Pin = 1; // ADC1_CH1 just for reference
//const int adc2Pin = 2; // ADC1_CH2 just for reference
//const int adc3Pin = 3; // ADC1_CH3 just for reference
const int unused4Pin = 4;
const int unused5Pin = 5;
const int unused6Pin = 6; 
const int unused7Pin = 7; 
const int unused8Pin = 8;   
const int unused9Pin = 9;  
const int unused10Pin = 10;
// const int i2c_scl = 20;
// const int i2c_sda = 21;

uint8_t btn_flag = 0; // variable for a button interrupt

// button interrupt
void IRAM_ATTR rstbtn_isr(){
  btn_flag = 1;
}

void setup_pins(){
  // pins
  pinMode(unused0Pin, INPUT);
  pinMode(unused4Pin, OUTPUT);
  pinMode(unused5Pin, OUTPUT);
  pinMode(unused6Pin, OUTPUT);
  pinMode(unused7Pin, OUTPUT);
  pinMode(unused8Pin, OUTPUT);
  pinMode(unused9Pin, INPUT_PULLUP);
  pinMode(unused10Pin, INPUT);

  digitalWrite(unused0Pin, 0);
  digitalWrite(unused4Pin, 0);
  digitalWrite(unused5Pin, 0);
  digitalWrite(unused6Pin, 0);
  digitalWrite(unused7Pin, 0);
  digitalWrite(unused8Pin, 0);
  digitalWrite(unused9Pin, 0);
  digitalWrite(unused10Pin, 0);
  // interrupt
  attachInterrupt(digitalPinToInterrupt(unused0Pin), rstbtn_isr, FALLING);  // button has pull-up resistor
}

