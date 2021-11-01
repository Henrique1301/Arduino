#include <IRremote.h>

#define receptor 11
#define mot1a 4
#define mot1b 5
#define mot2a 6
#define mot2b 7
float valor;

IRrecv recIR(receptor);
decode_results resultado;

void setup() {
  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  Serial.begin(9600);
  recIR.enableIRIn(); //Inicializa o receptor IR

}

void loop() {
  if(recIR.decode(&resultado)){
    if(resultado.value == 0xFF629D){
      frente();
    }
    if(resultado.value == 0xFFA857){
      tras();
    }
    if(resultado.value == 0xFF02FD){
      parar();
    }
    if(resultado.value == 0xFF22DD){
      esquerda();
    }
    if(resultado.value == 0xFFC23D){
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
