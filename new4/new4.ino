#include <SoftwareSerial.h>
#include "DHT.h"
#include <Servo.h>

SoftwareSerial BTserial(2,3);
DHT dht(4, DHT11);
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  BTserial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(0);
  servo2.write(0);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  
}

void loop() {
    
  int h = dht.readHumidity(); 
  int t = dht.readTemperature();
  int data;

  Serial.print("humidity:");
  Serial.println(h);
  Serial.print("temperature:");
  Serial.println(t);

  BTserial.print("습도: ");
  BTserial.print(h);
  BTserial.print("% ");
  BTserial.print("온도: ");
  BTserial.print(t);
  BTserial.print("C");

  delay(50);

// 선풍기 리모컨
  if (BTserial.available()){
    
    data = BTserial.read();
    
     if (data == 'a') {
      servo1.write(0);
      delay(500);
      servo1.write(90);
      delay(500);
      servo1.write(0);
     }
  }
  
// 제습기 리모컨
  if((h>=50) && (h<60)) {
    digitalWrite(22, HIGH);
    digitalWrite(23, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    delay(1000);
    }

  if((h>=60) && (h<80)) {
    digitalWrite(22, LOW);
    digitalWrite(23, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, LOW);
    delay(1000);
    }

  if((h>=80) && (h<100)) {
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    delay(1000);
    }


// 리모컨2
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

  if((h>=85) && (h<90)) {
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    delay(1000);
    }

  if((h>=0) && (h<70)) {
    digitalWrite(28, HIGH);
    digitalWrite(29, LOW);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    delay(1000);
  }

// 리모컨3
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

  if((h>=85) && (h<90)) {
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    delay(1000);
    }

  if((h>=0) && (h<70)) {
    digitalWrite(34, HIGH);
    digitalWrite(35, LOW);
    digitalWrite(37, LOW);
    digitalWrite(38, LOW);
    digitalWrite(39, LOW);
    delay(1000);
  }

// 리모컨4
  if((h>=70) && (h<80)) {
    digitalWrite(40, LOW);
    digitalWrite(41, HIGH);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    delay(1000);
    }

  if((h>=80) && (h<85)) {
    digitalWrite(40, LOW);
    digitalWrite(41, LOW);
    digitalWrite(43, HIGH);
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    delay(1000);
    }

  if((h>=85) && (h<90)) {
    digitalWrite(40, LOW);
    digitalWrite(41, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, HIGH);
    digitalWrite(45, HIGH);
    delay(1000);
    }

  if((h>=0) && (h<70)) {
    digitalWrite(40, HIGH);
    digitalWrite(41, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    delay(1000);
  }

 
  delay(1000);
}
