#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

OneWire onewire(4);
DallasTemperature sensor(&onewire);
LiquidCrystal_I2C lcd(0x27,16,2);

float temp;

void setup() {
  sensor.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();

}

void loop() {
  sensor.requestTemperatures();
  temp = sensor.getTempCByIndex(0);
  lcd.home();
  lcd.print("Temp: ");
  lcd.print(temp);
  Serial.print("Temp:");
  Serial.println(temp);
  delay(500);

}
