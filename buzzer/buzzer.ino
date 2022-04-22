#define som 9

void setup() {
  pinMode(som, OUTPUT);

}

void loop() {
  //tone(porta, frequencia);
  //notone(porta);

  //tone(porta, frequencia, duração);

  tone(som,300,1000);
  delay(5000);
}
