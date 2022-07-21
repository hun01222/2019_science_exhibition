#include "kit_library.h"

void setup(){
use_motor(7);
use_bluetooth(2,3);
}

void loop(){
if ( bluetooth() == 'a' ) {
turn_motor(45);
}
else if ( bluetooth() == 'b') {
turn_motor(90);
}
else if ( bluetooth() == 'c') {
turn_motor(180);
}
else {
turn_motor(0);
}
}

// https://blog.naver.com/kids_power/221378553716
// https://blog.naver.com/kids_power/221370505179
