#include <HCSR04.h>

#define mot1a 3
#define mot1b 4
#define mot2a 5
#define mot2b 6

#define p_trigger 10
#define p_echo 11

UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

int dist_cm, dist_m;

void setup () {
  Serial.begin(9600);
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
}

void loop () {
    dist_cm = distanceSensor.measureDistanceCm();
    if(dist_cm > 20){
      tras();
    }
    if(dist_cm < 20){
      direita();
    }
}

void frente(){
  digitalWrite(mot1a, HIGH);
  digitalWrite(mot2a, HIGH);
  digitalWrite(mot1b, LOW);
  digitalWrite(mot2b, LOW);
}

void parar(){
  digitalWrite(mot1a, LOW);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot1b, LOW);
  digitalWrite(mot2b, LOW);
}

void tras(){
  digitalWrite(mot1a, LOW);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot1b, HIGH);
  digitalWrite(mot2b, HIGH);
}
void esquerda(){
  digitalWrite(mot1a, HIGH);
  digitalWrite(mot2a, LOW);
  digitalWrite(mot1b, LOW);
  digitalWrite(mot2b, LOW);
}
void direita(){
  digitalWrite(mot1a, LOW);
  digitalWrite(mot2a, HIGH);
  digitalWrite(mot1b, LOW);
  digitalWrite(mot2b, LOW);
}
