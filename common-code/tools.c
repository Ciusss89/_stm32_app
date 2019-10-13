#include "tools.h"

void *_malloc(size_t size)
{
	void *pt = malloc(size ? size : 1);
	if (pt == NULL)
		_system_panic();
	return pt;
}

static void _ld2_pulse(void)
{
		gpio_toggle(GPIOA, GPIO5);

		for (int i = 0; i < 200000; i++)
			__asm__("nop");

		gpio_toggle(GPIOA, GPIO5);
}

void _system_panic(void)
{
	/* Instead to inizialize and print en error on the stderr/stdout,
	 * I use the led LD2 of the nuclo board as panic indicator.
	 */

	rcc_periph_clock_enable(RCC_GPIOA);
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5);

	/* Turn off led */
	gpio_clear(GPIOA, GPIO5);

	while (1) {
		_ld2_pulse();

		for (int i = 0; i < 1000000; i++)
			__asm__("nop");

		_ld2_pulse();
		for (int i = 0; i < 8000000; i++)
			__asm__("nop");
	}
}
