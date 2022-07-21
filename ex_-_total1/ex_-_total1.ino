#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include <Servo.h>

SoftwareSerial BTserial(2,3);
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(4, DHT11);
Servo myservo;
int angle = 0;
int t = 0;

void setup() {

  BTserial.begin(9600);
  lcd.init();
  lcd.backlight();
  myservo.attach(9);
  
}

void loop() {
  int T = t;
  int h = dht.readHumidity(); 
  delay(1000);
  int t = dht.readTemperature();


  if(T!=t) {
    for (; angle <= 90; angle +=1) {
      myservo.write(angle);
      delay(5);
    }

    for (; angle >= 0; angle -=1) {
      myservo.write(angle);
      delay(5);
    }
  }

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
