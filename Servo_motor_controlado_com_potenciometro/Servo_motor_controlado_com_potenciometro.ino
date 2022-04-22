#include <Servo.h>

#define pot A0

Servo s1;
Servo s2;

int angS1;
int angS2;

int a;

void setup() {
  s1.attach(2);
  s2.attach(4);
  angS1 = 0;
  angS2 = 0;
  s1.write(angS1);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void AngS2(){
  angS2= 0;
  s2.write(angS2);
 a = s2.read();
  Serial.println(a);
  delay(2000);
  angS2 = 90;
  s2.write(angS2);
  a = s2.read();
  Serial.println(a);
  delay(2000);
  angS2 = 180;
  s2.write(angS2);
  a = s2.read();
  Serial.println(a);
  delay(2000);
  
}

void loop() {
  angS1 = map(analogRead(pot), 0, 1023, 0, 180);
  s1.write(angS1);
  AngS2();
  delay(100);
 
}
