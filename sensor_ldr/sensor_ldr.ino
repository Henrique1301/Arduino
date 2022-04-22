#define led 8
#define ldr A5
int vldr = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  vldr = analogRead(ldr);
  if(vldr>15){
    digitalWrite(led, LOW);
  }
  else{
    digitalWrite(led, HIGH);
  }
  Serial.println(vldr);
}

//Circuito divisao de tensão
