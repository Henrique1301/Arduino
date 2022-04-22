#define pinrele 7
#define pin 4

bool rele;

void setup() {
  pinMode(pinrele, OUTPUT);
  pinMode(pin, INPUT);
  rele = true;
  digitalWrite(pinrele, rele);

}

void loop() {
  if(digitalRead(pin) == 1){
    rele = !rele;
  }
  digitalWrite(pinrele, rele);
  
}
