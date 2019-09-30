/*
 * Author (c) 201 Giuseppe Tipaldi
 *
 */

#ifndef MODULE_UART_H
#define MODULE_UART_H

/* @uart_init: init the uart on UART2
 *
 */
void uart_init(void);

/* @uart_putmessage: print a message on the console
 *
 */
void uart_putmessage(const char *string);

#endif /* MODULE_UART_H */
