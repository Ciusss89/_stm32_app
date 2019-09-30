#include "api.h"

int my_func(int a)
{
	return a * 3;
}

/* Eample 1: blink the LD2 led
 *
 */
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
void example_1_blink_led(void) {
	/* ResetClockControl Registers
	 *  -Enable Peripheral Clock in running mode
	 */
        rcc_periph_clock_enable(RCC_GPIOA);

        gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

	gpio_set(GPIOA, GPIO5);
	
	while(1) {
		for (int i = 0; i < 800000; i++)
			__asm__("nop");
		
		gpio_toggle(GPIOA, GPIO5);
	}

	return;
}
