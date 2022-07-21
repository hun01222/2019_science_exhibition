#include <SoftwareSerial.h>
#include "DHT.h"
#include <Servo.h>

SoftwareSerial BTserial(2,3);
DHT dht(4, DHT11);
Servo servo;

void setup() {

  BTserial.begin(9600);
  servo.attach(9);
  servo.write(0);
  
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

  delay(1000);

  if (BTserial.available()){
    
    int data = BTserial.read();
    
     if (data == 'a') {
      servo.write(0);
      delay(500);
      servo.write(180);
      delay(500);
      servo.write(0);
     }
  }
}
