/*
 * Author (c) 2019 Giuseppe Tipaldi
 *
 */

#ifndef TIMERS_H
#define TIMERS_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

enum timer {
	TIM2,
	TIM3,
	TIM4,
	TIM5,
};

void tim_setup(int timer);
void tim_set_timing(int timer, uint16_t prescaler,
		    uint32_t autoreload, uint32_t startvalue);
void tim_reset(int timer);
void tim_enable(int timer, bool control);
void tim_on_off_irq(int timer, bool control);

#endif
