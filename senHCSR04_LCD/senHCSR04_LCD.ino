#include <LiquidCrystal_I2C.h>
#include <HCSR04.h>

#define p_trigger 4
#define p_echo 5
LiquidCrystal_I2C lcd(0x27,16,2);

UltraSonicDistanceSensor distanceSensor(p_trigger, p_echo);

int dist_cm, dist_m;

void setup () {
    lcd.begin(16, 2);
    lcd.backlight();
}

void loop () {
    dist_cm = distanceSensor.measureDistanceCm();
    dist_m = dist_cm/100;
    lcd.home();
    lcd.print("Dist_cm: ");
    lcd.print(dist_cm);
    lcd.print("cm");
    lcd.setCursor(0, 1);
    lcd.print("Dist_M: ");
    lcd.print(dist_m);
    lcd.print("M");
    delay(1000);
}
