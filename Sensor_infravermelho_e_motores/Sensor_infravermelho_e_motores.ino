#include <IRremote.h>
 
#define receptor 11
#define mot1a 3
#define mot1b 4
#define mot2a 5
#define mot2b 6


IRrecv recIR(receptor);
decode_results resultado;

void setup(){
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  Serial.begin(9600);
  recIR.enableIRIn(); //Inicializa o receptor IR

}

void loop() {
  if(recIR.decode(&resultado)){
    if(resultado.value == 0x20DF02FD){
      frente();
    }
    if(resultado.value == 0x20DF827D){
      tras();
    }
    if(resultado.value == 0x20DF22DD){
      parar();
    }
    if(resultado.value == 0x20DFE01F){
      esquerda();
    }
    if(resultado.value == 0x20DF609F
){
      direita();
    }
    recIR.resume();
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
