#include "kit_library.h"

void setup(){
use_motor();
use_bluetooth();
}

void loop(){
if ( bluetooth() == 'a' ) {  //블루투스가 a를 전송받았을 때
turn_motor(45);              //서보모터를 45도로 돌려라
}
else if ( bluetooth() == 'b') {  //블루투스가 a를 전송받았을 때
turn_motor(90);                  //서보모터를 90도로 돌려라
}
else if ( bluetooth() == 'c') {  //블루투스가 c를 전송받았을 때
turn_motor(180);                 //서보모터를 180도로 돌려라
}
else {           //블루투스가 a,b,c외 다른값을 전송받았을 떄
turn_motor(0);   //서보모터를 0도로 돌려라
}
}
