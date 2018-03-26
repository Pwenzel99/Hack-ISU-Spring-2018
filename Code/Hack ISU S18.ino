#include <math.h>
#include <Time.h>
#include <Servo.h>

***@author Andrew Holman (the friend)***

const int buttonPinBaseLeft = 2;
const int buttonPinBaseRight = 3;
const int buttonPinSwitch = 4;
int buttonBaseLeftState = 0;
int buttonBaseRightState = 0;
int buttonSwitch = 0;
int count = 0;
boolean onBase = true;

int pos1 = 0;
int posBase = 0;

Servo myservo1;
Servo myservoBase;
void setup() {
  Serial.begin(9600);
    myservo1.attach(9);
    myservoBase.attach(10);
    pinMode(buttonPinBaseLeft, INPUT_PULLUP);
    pinMode(buttonPinBaseRight, INPUT_PULLUP);
    pinMode(buttonPinSwitch, INPUT_PULLUP);
}



void loop() {


  buttonBaseLeftState = digitalRead(buttonPinBaseLeft);
  buttonBaseRightState = digitalRead(buttonPinBaseRight);
  buttonSwitch = digitalRead(buttonPinSwitch);

  if(buttonSwitch == LOW)
  {
    if(onBase)
    {
      onBase = false;
    }
    else
    {
      onBase = true;
    }
    delay(300);
  }
  while(onBase&& (buttonBaseLeftState == LOW && posBase <180))
  {
    posBase++;
    myservoBase.write(posBase);
    delay(10);
    buttonBaseLeftState = digitalRead(buttonPinBaseLeft);
  }
  
  while(onBase&&(buttonBaseRightState == LOW && posBase>0))
  {
    posBase--;
    myservoBase.write(posBase);
    delay(10);
    buttonBaseRightState = digitalRead(buttonPinBaseRight);
  }
  
  while(!onBase&& (buttonBaseLeftState == LOW && pos1 <180))
  {
    pos1++;
    myservo1.write(pos1);
    delay(10);
    buttonBaseLeftState = digitalRead(buttonPinBaseLeft);
  }
  while(!onBase&&(buttonBaseRightState == LOW && pos1>0))
  {
    pos1--;
    myservo1.write(pos1);
    delay(10);
    buttonBaseRightState = digitalRead(buttonPinBaseRight);
  }
//  for(pos1=0; pos1 <= 180; pos1++)
//  {
//    myservo1.write(pos1);
//    myservoBase.write(pos1);
//    delay(15);
//  }
//  for(pos1 = 180; pos1>0; pos1--)
//  {
//    myservo1.write(pos1);
//    myservoBase.write(pos1);
//    delay(15);
//  }
 
}
