#define velmotor 3
#define m1a 4
#define m1b 5
#define m2a 6
#define m2b 7
#define tmp 3000
int vel = 0;

void setup() {
  pinMode(velmotor, OUTPUT);
  //Motor 1
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  //Motor 2
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  analogWrite(velmotor, vel);
 
}

void loop() {
  vel=255;
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, HIGH);
  analogWrite(velmotor, vel);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, HIGH);
  analogWrite(velmotor, vel);
  delay(tmp);

  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  delay(100);

  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  analogWrite(velmotor, vel);
  delay(tmp);
}
