#include "pitches.h"
#include "songs.h"
int led = 13;int MB_PIN9 = 9;char getdata=0; char selctor[3]={'1','1'}; int point = 0;
void setup() {
 pinMode(MB_PIN9, OUTPUT);
  digitalWrite(led,LOW);Serial.begin(9600);  
}
void loop() {
  if(Serial.available() > 0)
  {
    getdata = Serial.read();
    delay(1000); 
    Serial.print(getdata);Serial.print("[Entered]\n");
    if (point==0){
    selctor[0]= getdata; point=1;
    }              
    else{
    selctor[1]= getdata; point=0;
    }
  }

   if (selctor[0]=='1' && selctor[1]=='a' )
    {
      tetris();
      Serial.print("[Tetris]\n");
      delay(1000);   
    }
  else {
    Serial.print(selctor[0]);
    Serial.print(selctor[1]);
    Serial.print("[NO ARRAY]\n");
    noTone(MB_PIN9);
    delay(1000);   
    }
}
