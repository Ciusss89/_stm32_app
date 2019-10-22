#include "api.h"

#include "api-asm.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

int main(void)
{
	FILE *fd;
	bool err;

	/* Init system for the LD2 */
	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);
	gpio_set(GPIOA, GPIO5);

	/* Init the uart */
	uart_init();
	fd = uart_fd();

	fprintf(fd, "[*] Welcome to Nucleo STM32F401RE [*]\n\r");

	tim_setup(TIM2);
	tim_set_timing(TIM2, 8400, 8400, 1);
	tim_on_off_irq(TIM2, true);
	tim_enable(TIM2, true);
	
	while (1) {
	}

	return 0;
}
