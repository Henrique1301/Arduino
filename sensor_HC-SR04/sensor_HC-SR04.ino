#include <HCSR04.h>

#define p_trigger 10
#define p_echo 11

UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

int dist_cm, dist_m;

void setup () {
    Serial.begin(9600);
}

void loop () {
    dist_cm = distanceSensor.measureDistanceCm();
    dist_m = dist_cm/100;
    Serial.print("Distancia ");
    Serial.print(dist_cm);
    Serial.print(" cm ");
    Serial.print(dist_m);
    Serial.println(" m ");
    Serial.println("-------------");
    delay(1000);
}
