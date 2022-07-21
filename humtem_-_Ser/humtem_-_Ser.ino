#include <DHT.h>
#include <Servo.h>
DHT dht(4, DHT11);
Servo servo;
int count = 0;

void setup() {

  Serial.begin(9600);
  servo.attach(9);
    
}


void loop() {

  
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  

  Serial.print("humidity:");
  Serial.println(h);
  Serial.print("temperature:");
  Serial.println(t);

  
  if((h>=60) && (h<70) && (count!=1)) {
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
    servo.write(0);

    count = 1;
    }

  if((h>=70) && (h<80) && (count!=2)) {
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
    servo.write(0);

    count = 2;
    }

  if((h>=80) && (h<90) && (count!=3)) {
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
    servo.write(0);

    count = 3;
    }

  if((h>=90) && (h<100) && (count!=4)) {
    servo.write(0);
    delay(1000);
    servo.write(180);
    delay(1000);
    servo.write(0);

    count = 4;
    }
  
  delay(1000);

}
