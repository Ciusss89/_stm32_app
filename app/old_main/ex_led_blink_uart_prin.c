#include "api.h"
#include "module_uart.h"

#include "api-asm.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main(void)
{
	/* Init system for the LD2 */
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
	gpio_set(GPIOA, GPIO5);

	/* Init the uart */
	uart_init();

	while (1) {

		uart_putmessage("gpio toggle");
		gpio_toggle(GPIOA, GPIO5);

		for (int i = 0; i < 800000; i++)
			__asm__("nop");


	}

	return 0;
}
