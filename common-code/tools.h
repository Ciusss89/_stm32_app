/*
 * Author (c) 2019 Giuseppe Tipaldi
 *
 */

#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <stddef.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* @_malloc: like malloc but in case of NULL pointer it calls _system_panic.
 */
void *_malloc(size_t size);

/* @_system_panic: blink in a panic mode to indicate by the led LD2 that
 * 		   semething goes bad
 */
void _system_panic(void);
#endif
