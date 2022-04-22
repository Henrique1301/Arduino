#include <OneWire.h>
#include <DallasTemperature.h>

OneWire onewire(4);
DallasTemperature sensor(&onewire);

float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  sensor.begin();

}

void loop() {
  sensor.requestTemperatures();
  temp = sensor.getTempCByIndex(0);
  Serial.println(temp);
  delay(500);

}
