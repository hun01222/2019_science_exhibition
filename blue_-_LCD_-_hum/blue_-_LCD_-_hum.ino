#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

SoftwareSerial BTserial(2,3);
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(4, DHT11);

void setup() {

  BTserial.begin(9600);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
    
  int h = dht.readHumidity(); 
  int t = dht.readTemperature();

  BTserial.print("습도: ");
  BTserial.print(h);
  BTserial.print("% ");
  BTserial.print("온도: ");
  BTserial.print(t);
  BTserial.print(" C");

  lcd.setCursor(0,0);
  lcd.print("hum: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("tem: ");
  lcd.print(t);

  delay(1000);
  
}
