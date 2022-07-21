#include <SoftwareSerial.h>
#include "DHT.h"
#include <Servo.h>

SoftwareSerial BTserial(2,3);
DHT dht(4, DHT11);
Servo servo1;
Servo servo2;
int count=0;

void servo1f() {
  
  servo1.write(45);
  delay(500);
  servo1.write(70);
  delay(500);
  servo1.write(60);
  delay(500);
      
}

void servo2f() {

  servo2.write(25);
  delay(500);
  servo2.write(70);
  delay(500);
  servo2.write(60);
  delay(500);
  
}

void setup() {
  
  Serial.begin(9600);
  BTserial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(60);
  servo2.write(60);

}

void loop() {
  
  int h = dht.readHumidity(); 
  int t = dht.readTemperature();

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
  
  if (BTserial.available()){
    int data = BTserial.read();
     if (data == 'a')
      servo1f();
  }

  if ((t>0) && (t<25)) {
    servo1f();
    count=0;
    delay(500);
  }

  if ((t>=25) && (t<28)) {
    if(count=0) {
      servo2f();
      delay(500);
    }
    
    if(count=2){
      servo2f();
      delay(500);
      servo2f();
      delay(500);
    }
  }

  if ((t>=28) && (t<31)){
    if(count=1)
      servo2f();
      delay(500);
    if(count=3) {
      servo2f();
      delay(500);
      servo2f();
      delay(500);
    }
  }

  if ((t>=31) && (t<50)){
    servo2f();
    delay(500);
  }

  delay(1000);

}
