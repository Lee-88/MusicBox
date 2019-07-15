#include "pitches.h"
#include "songs.h"
int led = 13;int MB_PIN9 = 9;char getdata=0;
void setup() {
  pinMode(led, OUTPUT);pinMode(MB_PIN9, OUTPUT);
  digitalWrite(led,LOW);Serial.begin(9600);  
}
void loop() {
  if(Serial.available() > 0)
  {
    getdata = Serial.read();
    Serial.print(getdata);
    if(getdata=='1')
    {
        tetris();
    }  
    else
    {
    noTone(MB_PIN9);}
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);   
    }
  }
