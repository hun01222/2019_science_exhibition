#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

SoftwareSerial BTserial(2,3);
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(4, DHT11);

void setup() {
  BTserial.begin(9600); //블루투스 통신 시작
  for(int i=22; i<46; i++) //LED 핀 선언
    pinMode(i, OUTPUT);
  lcd.init();
  lcd.backlight();
  
}

void loop() {
    
  int h = dht.readHumidity(); //습도값을 h에 저장
  int t = dht.readTemperature(); //온도값을 t에 저장

  BTserial.print("습도: "); //앱 인벤터를 통해 스마트폰에 온습도값 출력
  BTserial.print(h);
  BTserial.print("% ");
  BTserial.print("온도: ");
  BTserial.print(t);
  BTserial.print("C");

  lcd.setCursor(0,0);
  lcd.print("hum: ");
  lcd.print(h);
  lcd.setCursor(0,1);
  lcd.print("tem: ");
  lcd.print(t);

  delay(1000);

// 제습기 리모컨

  if((h>=0) && (h<60)) { //습도가 0~60이면 작동하지 않음
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    delay(1000);
    }

  if((h>=60) && (h<80)) { //습도가 60~80이면 1단계 작동
    digitalWrite(22, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
    delay(1000);
    }

  if((h>=80) && (h<100)) { //습도가 80~100이면 2단계 작동
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    delay(1000);
    }


// 리모컨2 이후 수정 가능하도록 임의로 설정함

  if((h>=0) && (h<70)) {
    digitalWrite(28, HIGH);
    digitalWrite(29, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    delay(1000);
    }
    
  if((h>=70) && (h<80)) {
    digitalWrite(28, LOW);
    digitalWrite(29, HIGH);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    delay(1000);
    }

  if((h>=80) && (h<85)) {
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(31, HIGH);
    digitalWrite(32, LOW);
    digitalWrite(33, HIGH);
    delay(1000);
    }

  if((h>=85) && (h<100)) {
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    delay(1000);
    }


// 리모컨3
  
  if((h>=0) && (h<70)) {
    digitalWrite(34, HIGH);
    digitalWrite(35, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, LOW);
    delay(1000);
    }
  
  if((h>=70) && (h<80)) {
    digitalWrite(34, LOW);
    digitalWrite(35, HIGH);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, HIGH);
    delay(1000);
    }

  if((h>=80) && (h<85)) {
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(37, HIGH);
    digitalWrite(38, LOW);
    digitalWrite(39, HIGH);
    delay(1000);
    }

  if((h>=85) && (h<100)) {
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    delay(1000);
    }

  delay(1000);
}
