#include <Servo.h>

Servo a, b, c;

void setup() {

  a.attach(8);
  b.attach(9);
  c.attach(10);
  
}

void loop() {

  a.write(0);
  b.write(0);
  c.write(0);

  delay(1000);

  a.write(180);
  b.write(180);
  c.write(180);

  delay(1000);

}
