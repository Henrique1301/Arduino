#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


#define mot1a 13
#define mot1b 12
#define mot2a 14
#define mot2b 27
#define farol_frente1 26
#define setaL 33
#define setaR 25
int counter;
bool DevoPiscar;

char valorRecebido;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP-32 HENRIQUE"); 
  Serial.println("O dispositivo já pode ser pareado!");

  pinMode(mot1a, OUTPUT);
  pinMode(mot1b, OUTPUT);
  pinMode(mot2a, OUTPUT);
  pinMode(mot2b, OUTPUT);
  pinMode(farol_frente1, OUTPUT);
  pinMode(setaL, OUTPUT);
  pinMode(setaR, OUTPUT);
}

void loop() {
    DevoPiscar = false;
    valorRecebido =(char)SerialBT.read();
    Serial.println(valorRecebido);

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    if(valorRecebido == 'F'){
     SerialBT.println("forward");
     frente();
    }
    
    if(valorRecebido == 'B'){
     SerialBT.println("Back");
     tras();
    }    
    
    if(valorRecebido == 'L'){
     SerialBT.println("Left");
     esquerda();
       
    }
    
    if(valorRecebido == 'R'){
     SerialBT.println("Right");
      direita();
    }

    if(valorRecebido == 'S'){
     SerialBT.println("Stop");
     parar();
    }

    if(valorRecebido == 'W'){
     SerialBT.println("Front lights on");
     farol_frente();
    }
    
    if(valorRecebido == 'w'){
     SerialBT.println("Front lights off");
     farol_frente_off();
    }

    if(valorRecebido == 'X'){
      //DevoPiscar = true;
      SerialBT.println("Pisca pisca");
      while(DevoPiscar) {
      pisca();
      DevoPiscar = false;      
      }
      
    }

    if(valorRecebido == 'V'){
     SerialBT.println("Seta esquerdaa");
     SetaEsquerdaON();
    }

    if(valorRecebido == 'v'){
     SerialBT.println("Seta esquerdaa");
     SetaEsquerdaOff();
    }

    if(valorRecebido == 'U'){
     SerialBT.println("Seta esquerdaa");
     SetaDireitaON();
    }

    if(valorRecebido == 'u'){
     SerialBT.println("Seta esquerdaa");
     SetaDireitaOff();
    }
  
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
void farol_frente(){
  digitalWrite(farol_frente1, HIGH);
}

void farol_frente_off(){
  digitalWrite(farol_frente1, LOW);
}

void SetaEsquerdaON(){
  digitalWrite(setaL, HIGH);
}

void SetaDireitaON(){
  digitalWrite(setaR, HIGH);
  delay(300);
  digitalWrite(setaR, LOW);
  delay(300);
}

void SetaEsquerdaOff(){
  digitalWrite(setaL, LOW);
}

void SetaDireitaOff(){
  digitalWrite(setaR, LOW);
}

void pisca(){
  digitalWrite(setaL, HIGH);
  digitalWrite(setaR, HIGH);
  delay(300);
  digitalWrite(setaL, LOW);
  digitalWrite(setaR, LOW);
  delay(300);
  
  
}

void piscanao(){
  digitalWrite(setaL, LOW);
  digitalWrite(setaR, LOW);
  delay(300);
  
}
