#include "arduino.h"
#include <Keypad.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 2);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = { 
  {'0','1','2','3'}, 
  {'4','5','6','7'}, 
  {'8','9','A','B'}, 
  {'C','D','E','F'} 
}; 

byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {12, 11, 10, 9};

//const int TPin = 0;
//const int BPin = 1;
const int XPin = 0;    
const int YPin = 1;
const int ZPin = 4;
//const int RPin = 13;

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);  

 
void setup()
{ 
  BTSerial.begin(9600);
  //pinMode(TPin,INPUT);
  //pinMode(BPin,INPUT);
  pinMode(ZPin,INPUT);
  //pinMode(RPin,INPUT);
  digitalWrite(ZPin,HIGH);
  //digitalWrite(RPin,LOW);
} 
   
void loop()
{ 
  int x = analogRead(XPin);
  int y = analogRead(YPin);
  int z = digitalRead(ZPin);
  //int r = digitalRead(RPin);
  //int t = digitalRead(TPin);
  //int b = digitalRead(BPin);
  char customKey = customKeypad.getKey(); 
  //송신  
  //BTSerial.print('/');
  BTSerial.print('x');
  BTSerial.print(x);  
  
  BTSerial.print('y');
  BTSerial.print(y);
  
  BTSerial.print('z');  
  BTSerial.print(z);  

  BTSerial.print('r');  
  BTSerial.print("0");
 
  BTSerial.print('t');  
  BTSerial.print("0");

  BTSerial.print('b');  
  BTSerial.print("0");

  BTSerial.print('n');
  if(customKey == '\0')
  {
    BTSerial.print("Null");
  }
  else
  { 
    BTSerial.print(customKey);
  }
  BTSerial.print('n');

  delay(100);
} 

