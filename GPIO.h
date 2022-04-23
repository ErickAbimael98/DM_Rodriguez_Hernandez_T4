/*
 * GPIO.h
 *
 *  Created on: 13 abr 2022
 *      Author: jlpe
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define RED_LED		(22u)//PTB22
#define BLUE_LED    (21u)//PTB21
#define GREEN_LED	(26u)//PTE26
#define SW2			(6u) //PTC6
#define SW3			(4u) //PTA4
#define CLOCK_K64   (21000000u)
#define WAIT_FOR_SECOND_BUTTON (200000u)
#define DEBOUNCE (500000u)



void GPIO_init(void);

void set_RED_LED_state(uint8_t state);
void set_BLUE_LED_state(uint8_t state);
void set_GREEN_LED_state(uint8_t state);

int counterUpdated(void);
void resetCounterFlag(void);

int getCounter(void);
int setCounter(int value);



#endif /* GPIO_H_ */
