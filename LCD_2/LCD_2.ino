#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C LCD 객체 선언

void setup()
{
  lcd.init(); // lcd를 사용을 시작합니다.
  Serial.begin(9600);
  lcd.print("kocoafab.cc"); // lcd 화면에 kocoafab.cc 출력
  lcd.home(); // cursor의 위치를 0,0으로 이동
}

void loop() {


  if (Serial.available()) {  //시리얼 모니터를 통해 들어오는 데이터가 있다면
    char data = Serial.read(); // 데이터를 data 변수에 저장

// baklight 테스트
    if (data == '1') { 
      lcd.noBacklight();
      delay(1000);
      lcd.backlight();
    }

// Display 테스트 (글자 표시)
    if (data == '2') {
      lcd.noDisplay();
      delay(1000);
      lcd.display();
    }

// Cursor Blink 테스트 
    if (data == '3') {
      lcd.blink();
      delay(1000);
      lcd.noBlink();
    }

// Cursor 표시 테스트
    if (data == '4') {
      lcd.cursor();
      delay(1000);
      lcd.noCursor();
    }

// Scroll 테스트
    if (data  == '5') {
      lcd.scrollDisplayRight();
      delay(1000);
      lcd.scrollDisplayLeft();
    }

// Cursor 위치 변경 테스트
    if (data  == '6') {
      lcd.home();
      lcd.cursor();
      for (int i = 0; i < 16; i++) {
        lcd.setCursor(i, 0);
        delay(100);
      }
      lcd.noCursor();
      lcd.home();
    }
  }
}
