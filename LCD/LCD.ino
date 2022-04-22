#include <LiquidCrystal_I2C.h> //Incluir biblioteca

LiquidCrystal_I2C lcd(0x27,16,2); //Obejeto com classe LiquidCrystal

int tmp = 300;

void setup() {
  lcd.begin(16,2); //Tamanho do display
  lcd.backlight(); //Ligar backlight
  

}

void loop() {
  lcd.setCursor(4,0); //home(); == define a posição incial em (0,0)
  lcd.print("Henrique");
  lcd.setCursor(6,1); //Define a posição incial
  lcd.print("Sena");

  for(int pos = 0; pos<4; pos++){
    lcd.scrollDisplayLeft();
    delay(tmp);
  }

  for(int pos = 0; pos<8; pos++){
    lcd.scrollDisplayRight();
    delay(tmp);
  }
  for(int pos = 0; pos<4; pos++){
    lcd.scrollDisplayLeft();
    delay(tmp);
  }
  delay(1000);
  for(int repete=0; repete<3; repete++){
    lcd.noDisplay();
    //lcd.noBacklight();
    delay(tmp);
    lcd.display();
    //lcd.backlight();
    delay(tmp);

  }
}
