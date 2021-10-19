#define ledR 2
#define ledG 3
#define ledB 4
#define botao 7
#define maximo 3

int botaoclicado = 0;
int botaoaberto = 0;
int ciclo = 0;

void vermelho(){
  digitalWrite(ledR,LOW);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledB, HIGH);
}

void verde(){
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB, HIGH);
}

void azul(){
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,HIGH);
  digitalWrite(ledB, LOW);
}

void trocaled(){
  if(ciclo == 0){
    vermelho();
}
  else if(ciclo == 1){
    verde();
}
  else if(ciclo == 2){
    azul();
  }
  
  ciclo = ciclo+1;
  if(ciclo>maximo -1){
    ciclo = 0;
  }
}

void verificabotao(){
  if(digitalRead(botao)== HIGH){
    botaoclicado = 1;
    botaoaberto = 0;
  }
  else{
    botaoaberto = 1;
  }
  if((botaoclicado == 1) and (botaoaberto == 1)){
    botaoclicado = 0;
    botaoaberto = 0;
    trocaled();
  }
  
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT);

}

void loop() {
  verificabotao();

}
