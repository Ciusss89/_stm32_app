#include "module_uart.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

static void _uart_clock_setup(void)
{
	/* Enable clocks for USART2. */
	rcc_periph_clock_enable(RCC_USART2);
}

static void _uart_gpio_setup(void)
{
	/* Setup GPIO pins for USART2 transmit */
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);

	/* Setup USART2 TX pin as alternate function. */
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

static void _uart_setup(void)
{
	/* Setup USART2 parameters. */
	usart_set_baudrate(USART2, 115200);
	usart_set_databits(USART2, 8);
	usart_set_stopbits(USART2, USART_STOPBITS_1);
	usart_set_mode(USART2, USART_MODE_TX);
	usart_set_parity(USART2, USART_PARITY_NONE);
	usart_set_flow_control(USART2, USART_FLOWCONTROL_NONE);

	/* Enable the USART. */
	usart_enable(USART2);

	 /* Optional extra - disable buffering on stdout:
	  * Buffering doesn't save us any syscall overhead on embedded, and
	  * can be the source of what seem like bugs.
	  */
	setbuf(stdout, NULL);
}

static void _uart_puts(const char *string)
{
    while (*string) {
        usart_send_blocking(USART2, *string);
        string++;
    }
}

/* Init of the uart:
 *
 */
void uart_init(void)
{
	_uart_clock_setup();
	_uart_gpio_setup();
	_uart_setup();

	return;
}

/* Print message to uart console
 *
 */
void uart_putmessage(const char *string)
{

    _uart_puts(string);
    _uart_puts("\r\n");

    return;
}

static ssize_t _iord(void *_cookie, char *_buf, size_t _n);
static ssize_t _iowr(void *_cookie, const char *_buf, size_t _n);

static ssize_t _iord(void *_cookie, char *_buf, size_t _n)
{
	/* dont support reading now */
	(void)_cookie;
	(void)_buf;
	(void)_n;
	return 0;
}

static ssize_t _iowr(void *_cookie, const char *_buf, size_t _n)
{
	uint32_t dev = (uint32_t)_cookie;

	int written = 0;
	while (_n-- > 0) {
		usart_send_blocking(dev, *_buf++);
		written++;
	};
	return written;
}

/* Return the fd of console
 *
 */
FILE *uart_fd(void)
{
	_uart_clock_setup();
	_uart_gpio_setup();
	_uart_setup();

	cookie_io_functions_t stub = { _iord, _iowr, NULL, NULL };

	FILE *fd = fopencookie((void *)USART2, "rw+", stub);
	if(fd) {
		/* Do not buffer the serial line */
		setvbuf(fd, NULL, _IONBF, 0);
		return fd;
	}	

	return NULL;
}
