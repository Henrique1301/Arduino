#define sens 4
#define pinrele 7

bool rele;

void setup() {
  pinMode(pinrele, OUTPUT);
  pinMode(sens, INPUT);
  rele = false;
  digitalWrite(pinrele,rele);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sens) == HIGH){
    rele=!rele;
  }
  digitalWrite(pinrele,rele);
  Serial.println(sens);
}
