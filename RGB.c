#include "RGB.h"
#include "GPIO.h"


void set_RGB_off(){
	set_RED_LED_state(0);	 //RED LED
	set_BLUE_LED_state(0);  //GREEN LED
	set_GREEN_LED_state(0);   //BLUE LED
}


void set_RGB_yellow(){
	set_RED_LED_state(1);
	set_BLUE_LED_state(1);
	set_GREEN_LED_state(0);
}


void set_RGB_red(){
	set_RED_LED_state(1);
	set_BLUE_LED_state(0);
	set_GREEN_LED_state(0);
}


void set_RGB_purple(){
	set_RED_LED_state(1);
	set_BLUE_LED_state(0);
	set_GREEN_LED_state(1);
}


void set_RGB_blue(){
	set_RED_LED_state(0);
	set_BLUE_LED_state(0);
	set_GREEN_LED_state(1);
}


void set_RGB_green(){
	set_RED_LED_state(0);
	set_BLUE_LED_state(1);
	set_GREEN_LED_state(0);
}


void set_RGB_white(){
	set_RED_LED_state(1);
	set_BLUE_LED_state(1);
	set_GREEN_LED_state(1);
}








