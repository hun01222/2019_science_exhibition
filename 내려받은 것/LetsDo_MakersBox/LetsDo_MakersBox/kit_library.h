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

#ifndef KIT_LIBRARY_H
#define KIT_LIBRARY_H
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

  void wait(float second);

  /* BUILTIN LED */
  void use_led();
  void led_on();
  void led_off(); 

  /* Serial Monitor */
  void use_serial();

  /* Green Led */
  void use_greenled();
  void greenled_on();
  void greenled_off();
  
  /* Motor */
  void use_motor();
  void initialize_motor();
  void turn_motor(int degree);


  /* Light Sensor */
  void use_lightsensor();
  int lightsensor();
  void print_lightsensor();
  
  /* Sonar Sensor */
  void use_sonarsensor();
  int sonarsensor();
  void print_sonarsensor();

  /* RGB Led */
  void use_rgb();
  void rgbcolor(int red, int green, int blue);
  void rgb_off();
  void rgb_red_on();
  void rgb_green_on();
  void rgb_blue_on();

  /* Bluetooth */
  void use_bluetooth();
  void bluetooth_setname();
  void print_bluetooth();
  char bluetooth();

  void use_all();

 #endif
