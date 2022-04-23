#include "GPIO.h"
#include "fsl_gpio.h"
#include "fsl_port.h"

static uint8_t volatile counterFlag = 0;
static int volatile counter=0;


void PORTA_IRQHandler(void)
{
    GPIO_PortClearInterruptFlags(GPIOA, 1U << SW3);
        counter--;
        counterFlag = 1;
    SDK_ISR_EXIT_BARRIER;
}


void PORTC_IRQHandler(void)
{
    GPIO_PortClearInterruptFlags(GPIOC, 1U << SW2);
        counter++;
        counterFlag = 1;
    SDK_ISR_EXIT_BARRIER;
}


int counterUpdated(void){
	return counterFlag;
}
void resetCounterFlag(void){
	counterFlag=0;
}

int getCounter(void){
	return counter;
}
int setCounter(int value){
	counter=value;
}



void set_RED_LED_state(uint8_t state){
	 if (state)
		 GPIO_PortClear(GPIOB, 1u << RED_LED);
	 else
		 GPIO_PortSet  (GPIOB, 1u << RED_LED);
}
void set_BLUE_LED_state(uint8_t state){
	 if (state)
		 GPIO_PortClear(GPIOE, 1u << GREEN_LED);
	 else
		 GPIO_PortSet  (GPIOE, 1u << GREEN_LED);
}
void set_GREEN_LED_state(uint8_t state){
	 if (state)
		 GPIO_PortClear(GPIOB, 1u << BLUE_LED);
	 else
		 GPIO_PortSet  (GPIOB, 1u << BLUE_LED);
}






void GPIO_init(void)
{

	 gpio_pin_config_t sw_config = {
	        kGPIO_DigitalInput,
	        0,
	    };

	gpio_pin_config_t led_config = {
	        kGPIO_DigitalOutput,
	        0,
	    };

	const port_pin_config_t port_sw_config = {
	    kPORT_PullUp,                                            /* Internal pull-up resistor is enabled */
	    kPORT_FastSlewRate,                                      /* Fast slew rate is configured */
	    kPORT_PassiveFilterDisable,                              /* Passive filter is disabled */
	    kPORT_OpenDrainDisable,                                  /* Open drain is disabled */
	    kPORT_HighDriveStrength,                                 /* High drive strength is configured */
	    kPORT_MuxAsGpio,                                         /* Pin is configured as PTA4 */
	    kPORT_UnlockRegister                                     /* Pin Control Register fields [15:0] are not locked */
	  };



			//Enable Port Clocks
		CLOCK_EnableClock(kCLOCK_PortA);
		CLOCK_EnableClock(kCLOCK_PortB);
		CLOCK_EnableClock(kCLOCK_PortC);
		CLOCK_EnableClock(kCLOCK_PortE);


	PORT_SetPinConfig(PORTA, SW3, &port_sw_config);
	PORT_SetPinConfig(PORTC, SW2, &port_sw_config);

	PORT_SetPinInterruptConfig(PORTA, SW3, kPORT_InterruptFallingEdge);
 	PORT_SetPinInterruptConfig(PORTC, SW2, kPORT_InterruptFallingEdge);
 		// set Button pins as inputs
	GPIO_PinInit(GPIOC, SW2, &sw_config);
	GPIO_PinInit(GPIOA, SW3, &sw_config);



	//set pins as GPIO
	PORT_SetPinMux(PORTB, RED_LED, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTB, BLUE_LED, kPORT_MuxAsGpio);
	PORT_SetPinMux(PORTE, GREEN_LED, kPORT_MuxAsGpio);
	// set LED pins as outputs
	GPIO_PinInit(GPIOB, RED_LED, &led_config);
	GPIO_PinInit(GPIOB, BLUE_LED, &led_config);
	GPIO_PinInit(GPIOE, GREEN_LED, &led_config);


 NVIC_EnableIRQ(PORTA_IRQn);
 NVIC_SetPriority(PORTA_IRQn, 2); /**It Sets the priority of the IRQ*/
 NVIC_EnableIRQ(PORTC_IRQn);
 NVIC_SetPriority(PORTC_IRQn, 2); /**It Sets the priority of the IRQ*/




}
