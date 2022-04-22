#define pinrele 7
#define pinsom 4

bool rele;

void setup() {
  pinMode(pinrele, OUTPUT);
  pinMode(pinsom, INPUT);
  rele = false;
  digitalWrite(pinrele, rele);

}

void loop() {
  if(digitalRead(pinsom) == HIGH){
    rele = !rele;
  }
  digitalWrite(pinrele, rele);
  
}
