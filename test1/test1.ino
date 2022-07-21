#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  
  servo1.attach(9);
  servo2.attach(10);
  servo1.write(60);
  servo2.write(60);

}

void loop() {

      servo1.write(40);
      delay(200);
      servo1.write(80);
      delay(500);
      servo1.write(70);
      delay(500);

      servo2.write(36);
      delay(200);
      servo2.write(70);
      delay(500);
      servo2.write(60);
      delay(500);

      servo2.write(36);
      delay(200);
      servo2.write(70);
      delay(500);
      servo2.write(60);
      delay(500);
      
      
}
