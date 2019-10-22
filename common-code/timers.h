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

/* TIMERS NOTES:
 *  - from: (AN4013 Rev 8) STM32 cross-series timer overview - Application note
 *
 *  - The timer can be used as a time base generator. Depending on the clock,
 *    prescaler and auto reload, repetition counter (if present) parameters,
 *    the 16-bit timer can generate an update event from a nanosecond to a 
 *    few minutes. The 32-bit timers provide a wider range.
 *
 *  - Formula update event period = TIM_CLK/((PSC + 1)*(ARR + 1)*(RCR + 1))
 *    TIM_CLK=72MHz
 *    PSC = 16-bit prescaler register
 *    ARR = 16/32-bit Autoreload register
 *    RCR = 16-bit repetition counter
 *
 *  - Eample:
 *    I want an Update event of 4s -> 0.25 T
 *     -> TIM_CLK is 84MHz
 *     -> I set PSC to 32767 ->
 *
 */

void tim_setup(int timer);
void tim_set_timing(int timer, uint16_t prescaler,
		    uint32_t autoreload, uint32_t startvalue);
void tim_reset(int timer);
void tim_enable(int timer, bool control);
void tim_on_off_irq(int timer, bool control);

#endif
