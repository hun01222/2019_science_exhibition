#include <Servo.h>
#include "DHT.h"

Servo servo1;
Servo servo2;
DHT dht(4, DHT11);

void servo1f() {

  servo1.write(90);
  delay(500);
  servo1.write(0);
  delay(500);
  
}

void servo2f() {
  
  servo2.write(90);
  delay(500);
  servo2.write(0);
  delay(500);
  
}

void setup() {

  Serial.begin(9600);
  servo1.attach(9);
  servo2.attach(10);

}

void loop() {

  int h = dht.readHumidity(); 
  int t = dht.readTemperature();

  Serial.print("humidity:");
  Serial.println(h);
  Serial.print("temperature:");
  Serial.println(t);

  if((h>60)&&(h<=80))
    servo1f();

  if((h>80)&&(h<=100))
    servo2f();
    
  delay(1000);
}
