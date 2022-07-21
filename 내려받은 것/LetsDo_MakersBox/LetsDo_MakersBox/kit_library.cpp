/*******************************************************
   * Copyright (C) 2019 Huemone Lab Co., Ltd - All Rights Reserved *
   
   This software is provided "AS IS" only for educational purpose using MAKER'S BOX KIT made by Huemone Lab.
   Licensed under Huemone Lab Co., Ltd.
   Unauthorized for copying, modifying, distributing of this code.
   --------------------------------------------------------
   휴몬 라이브러리는 (주)휴몬랩이 제작한 메이커스 박스 키트의 실습을 위해 제작되었고 모든 저작권은 (주)휴몬랩에 있습니다
   메이커스 박스 키트 실습을 위한 교육적 용도로만 사용이 가능하며
   무단으로 복사/수정/재배포하거나 코드 전체 혹은 일부를 다른 용도로 사용할 시 법적인 조치를 취할 수 있습니다
*************************************************/

#ifndef KIT_LIBRARY_CPP
#define KIT_LIBRARY_CPP
  #ifndef PINSETTING
  #define PINSETTING
    #define BlueTooth_TX_Pin 2
    #define BlueTooth_RX_Pin 3
    #define SonarTriggerPin 5
    #define SonarEchoPin 6
    #define ServoMotorSignalPin 7
    #define GreenLedPin 8
    #define RGB_RedPin 9
    #define RGB_GreenPin 10
    #define RGB_BluePin 11
    #define DefaultLED 13
    #define LightSensorPin 14
  #endif
    
#include <Arduino.h>
#include <string.h>
#include <SoftwareSerial.h>
#include "Servo.h"

Servo servo;
SoftwareSerial BTSerial(BlueTooth_TX_Pin, BlueTooth_RX_Pin);


bool SerialIsUsingNow = false;
bool BTSerialIsUsingNow = false;

unsigned int ServoMotor_InitialDegree = 15;
unsigned int BT_Counter=0;

bool SonarSensorIsSet = false;
bool LightSensorIsSet = false;

/* Bulletin Led */
void use_led(){
  pinMode(DefaultLED, OUTPUT);
}

void led_on(){
  digitalWrite(DefaultLED, HIGH);
}

void led_off(){
  digitalWrite(DefaultLED, LOW);
}

/* Serial Monitor */
void use_serial(){
    if ( !SerialIsUsingNow ) Serial.begin(9600);
    SerialIsUsingNow = true;
}

/* Green led */
void use_greenled(){
  pinMode(GreenLedPin, OUTPUT);
}

void greenled_on(){
  digitalWrite(GreenLedPin, HIGH);
}

void greenled_off(){
  digitalWrite(GreenLedPin, LOW);
}

/* RGB Led */
void use_rgb(){
    pinMode(RGB_RedPin, OUTPUT);
    pinMode(RGB_GreenPin, OUTPUT);
    pinMode(RGB_BluePin, OUTPUT);
}

void rgbcolor(int red, int green, int blue){
    analogWrite(RGB_RedPin, red);
    analogWrite(RGB_GreenPin, green);
    analogWrite(RGB_BluePin, blue);
}

void rgb_off(){
    analogWrite(RGB_RedPin, 0);
    analogWrite(RGB_GreenPin, 0);
    analogWrite(RGB_BluePin, 0);
}

void rgb_red_on(){
    analogWrite(RGB_RedPin, 255);
    analogWrite(RGB_GreenPin, 0);
    analogWrite(RGB_BluePin, 0);
}

void rgb_green_on(){
    analogWrite(RGB_RedPin, 0);
    analogWrite(RGB_GreenPin, 255);
    analogWrite(RGB_BluePin, 0);
}

void rgb_blue_on(){
    analogWrite(RGB_RedPin, 0);
    analogWrite(RGB_GreenPin, 0);
    analogWrite(RGB_BluePin, 255);
}


/* Motor */
void use_motor(){
    servo.attach(ServoMotorSignalPin);
    servo.write(ServoMotor_InitialDegree);
}

void initialize_motor(int degree){
  if(degree>0&&degree<180)
    ServoMotor_InitialDegree = degree;
  else return;
}

void turn_motor(int degree){
    if(degree<0||degree>180) return;
    else servo.write(ServoMotor_InitialDegree+(degree*(90-ServoMotor_InitialDegree)/90));
}

/* Light Sensor */
void use_lightsensor(){
    pinMode(LightSensorPin, INPUT);
    LightSensorIsSet = true;
}

int lightsensor(){
    return analogRead(LightSensorPin);
}

void print_lightsensor(){
    if ( LightSensorIsSet ) {
        Serial.println(lightsensor());
    }
}

/* Sonar Sensor */
void use_sonarsensor(){
    pinMode(SonarEchoPin, INPUT);
    pinMode(SonarTriggerPin, OUTPUT);

    SonarSensorIsSet = true;
}

int sonarsensor(){
    digitalWrite(SonarTriggerPin, HIGH);
    delay(1);
    digitalWrite(SonarTriggerPin, LOW);

    float duration = pulseIn(SonarEchoPin, HIGH);
    int value = duration / 29.0 / 2.0;
    return value;
}

void print_sonarsensor(){
    if ( SonarSensorIsSet ) {
        Serial.println(sonarsensor());
    }
}

/* Bluetooth */
void use_bluetooth(){
    if(BTSerialIsUsingNow==false)
      BTSerial.begin(9600);
    BTSerialIsUsingNow = true;
}

void bluetooth_setname(){
    if (SerialIsUsingNow==false) use_serial();
    if (BTSerialIsUsingNow==false) use_bluetooth();
    while(1){
      if(Serial.available())
        BTSerial.write(Serial.read());
      if(BTSerial.available())
        Serial.write(BTSerial.read());
    }
}

bool bluetoothNullData = false;
char bluetoothNow = '\0';

char bluetooth(){
  if ( BTSerial.available() ) {
    char c = BTSerial.read();
    if ( c == '*' ) {
      if ( bluetoothNullData == false ) {
              bluetoothNullData = true;
      } else {
        bluetoothNullData = false;
      }
      bluetoothNow = '\0';
    } else if ( bluetoothNullData == false ) {
      bluetoothNow =  c;
    } else {
      bluetoothNow = '\0';
    }
  }
  return bluetoothNow;
}

void print_bluetooth(){
  if( BTSerial.available() ) {
      if ( bluetooth() != '\0' ) {
        Serial.println(bluetoothNow);
      }
  }

  if (Serial.available()){
    BTSerial.write(Serial.read());
  } 
}

/* Delay */
void wait(float second){
    delay(int(second*1000));
}

void use_all(){
    /* use_serial */
    if ( !SerialIsUsingNow ) Serial.begin(9600);
    SerialIsUsingNow = true;

    /* use_bluetooth */
    if(BTSerialIsUsingNow==false) BTSerial.begin(9600);
    BTSerialIsUsingNow = true;

    /* use_motor */
    servo.attach(ServoMotorSignalPin);
    servo.write(ServoMotor_InitialDegree);

    /* use_sonarsensor */
    pinMode(SonarEchoPin, INPUT);
    pinMode(SonarTriggerPin, OUTPUT);
    SonarSensorIsSet = true;

    /* use_lightsensor */
    pinMode(LightSensorPin, INPUT);
    LightSensorIsSet = true;

    /* use_led */
    pinMode(DefaultLED, OUTPUT);

    /* use_greenled */
    pinMode(GreenLedPin, OUTPUT);

    /* use_rgb */
    pinMode(RGB_RedPin, OUTPUT);
    pinMode(RGB_GreenPin, OUTPUT);
    pinMode(RGB_BluePin, OUTPUT);
}

#endif
