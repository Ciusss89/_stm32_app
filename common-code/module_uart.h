/*
 * Author (c) 2019 Giuseppe Tipaldi
 *
 */

#ifndef MODULE_UART_H
#define MODULE_UART_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>


/* @uart_init: init the uart on UART2
 *
 */
void uart_init(void);

/* @uart_putmessage: print a message on the console
 *
 */
void uart_putmessage(const char *string);

/* Get file descriptor of the uart
 *
 * How to use:
 *  FILE *fd;
 *  fd = uart_fd();
 *  fprintf(fd,"msg \n", args );
 */
FILE *uart_fd(void);

#endif /* MODULE_UART_H */
