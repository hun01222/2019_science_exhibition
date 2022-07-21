#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);

void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);
  while(!Serial) {
    ;
  }
    
}


void loop() {

  int h = dht.readHumidity();
  int t = dht.readTemperature();

  Serial.print("humidity:");
  Serial.println(h);
  Serial.print("temperature:");
  Serial.println(t);

  delay(1000);

  if(mySerial.available()) {
    Serial.write(mySerial.read());
  }

  if(Serial.available()) {
    mySerial.write(Serial.read());
  }

}
