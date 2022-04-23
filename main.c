#include <stdio.h>
#include "GPIO.h"
#include "RGB.h"
#include "fsl_gpio.h"
#include "fsl_common.h"

enum LED_color{  //used to move in RGB_controller array
	COLOR_OFF,
	COLOR_YELLOW,
	COLOR_RED,
	COLOR_PURPLE,
	COLOR_BLUE,
	COLOR_GREEN,
	COLOR_WHITE
};


int main(void) {
	GPIO_init();
	uint8_t colorCounter=COLOR_OFF;

	// RGB contains functions to configure RGB leds,
	void (*RGB_controller[7])();   // definition of function array  with colors in needed order
	RGB_controller[COLOR_OFF]	= set_RGB_off;
	RGB_controller[COLOR_YELLOW]= set_RGB_yellow;
	RGB_controller[COLOR_RED]	= set_RGB_red;
	RGB_controller[COLOR_PURPLE]= set_RGB_purple;
	RGB_controller[COLOR_BLUE]	= set_RGB_blue;
	RGB_controller[COLOR_GREEN] = set_RGB_green;
	RGB_controller[COLOR_WHITE] = set_RGB_white;



	// get_RGB returns an function array of  led switch functions
	RGB_controller[colorCounter]();  // set RGB in "colorCounter"" configuration, it's COLOR_OFF in this case...


	while(1){
		if(counterUpdated()){
			colorCounter=getCounter();

			if(colorCounter>COLOR_GREEN){
				colorCounter=COLOR_YELLOW;
				setCounter(colorCounter);
			}
			else if(colorCounter<COLOR_YELLOW){
				colorCounter=COLOR_GREEN;
				setCounter(colorCounter);
			}

			RGB_controller[colorCounter]();

			resetCounterFlag();
		}
	}



    return 0 ;
}
