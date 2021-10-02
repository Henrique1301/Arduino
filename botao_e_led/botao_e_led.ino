#define botao 3
#define led 4

int botaoclicado = 0;
int botaoaberto = 0;

void trocaled(){
  if(digitalRead(led) == HIGH){
    digitalWrite(led, LOW);
  }
   else{
    digitalWrite(led,HIGH);
    }
}


void keyup(){
  if (botaoclicado ==1 and botaoaberto ==1){
    botaoclicado = 0;
    botaoaberto = 0;
    trocaled();
  }
  
}

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
    if(digitalRead(botao)== HIGH){
      botaoclicado = 1;
      botaoaberto = 0;
    }
    else{
      botaoaberto = 1;
      keyup();
      
    }

}
