





















#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTserial(2,3);
Servo servo;


void setup() {
  
  BTserial.begin(9600);
  servo.attach(9);
  servo.write(60);

}

void loop() {
  if (BTserial.available()){
    
    int data = BTserial.read();
    
     if (data == 'a') {
      servo.write(50);











































































































































































































      
      delay(500);
      servo.write(150);
      delay(500);
      servo.write(60);
     }
  }
}
