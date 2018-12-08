#include<IRremote.h>

short pinInput = 2;
short pinRed = 10;
short pinGreen = 9;
short pinBlue = 8;
IRrecv irrecv(pinInput);
decode_results signals;

const long int PILOT_CHANNEL_MINUS = 16753245;
const long int PILOT_CHANNEL = 16736925;
const long int PILOT_CHANNEL_PLUS = 16769565;

const long int PILOT_PREVIOUS = 16720605;
const long int PILOT_NEXT = 16712445;
const long int PILOT_PLAY_PAUSE = 16761405;

const long int PILOT_VOL_DOWN = 16769055;
const long int PILOT_VOL_UP = 16754775;
const long int PILOT_EQ = 16748655;

const long int PILOT_0 = 16738455;
const long int PILOT_1 = 16724175;
const long int PILOT_2 = 16718055;
const long int PILOT_3 = 16743045;
const long int PILOT_4 = 16716015;
const long int PILOT_5 = 16726215;
const long int PILOT_6 = 16734885;
const long int PILOT_7 = 16728765;
const long int PILOT_8 = 16730805;
const long int PILOT_9 = 16732845;

const long int PILOT_ADD_100 = 16750695;
const long int PILOT_ADD_200 = 16756815;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();


  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  
  analogWrite(pinRed, LOW);
  analogWrite(pinGreen, LOW);
  analogWrite(pinBlue, LOW);
}

void loop() {
  if(irrecv.decode(&signals)) {
    unsigned long val = signals.value;

    if(val == PILOT_4)        analogWrite(pinRed, 255);
    else if(val == PILOT_7)   analogWrite(pinRed, 0);
    else if(val == PILOT_5)   analogWrite(pinGreen, 255);
    else if(val == PILOT_8)   analogWrite(pinGreen, 0);
    else if(val == PILOT_6)   analogWrite(pinBlue, 255);
    else if(val == PILOT_9)   analogWrite(pinBlue, 0);
    
    irrecv.resume();
  }
}
