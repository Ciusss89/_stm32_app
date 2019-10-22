#include "timers.h"
#include "tools.h"

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>

void tim_setup(int timer)
{
	switch (timer) {
		case TIM2:
			rcc_periph_clock_enable(RCC_TIM2);
			nvic_enable_irq(NVIC_TIM2_IRQ);
			nvic_set_priority(NVIC_TIM2_IRQ, 1);
			break;

		case TIM3:
			rcc_periph_clock_enable(RCC_TIM3);
			nvic_enable_irq(NVIC_TIM3_IRQ);
			nvic_set_priority(NVIC_TIM3_IRQ, 1);
			break;

		case TIM4:
			rcc_periph_clock_enable(RCC_TIM4);
			nvic_enable_irq(NVIC_TIM4_IRQ);
			nvic_set_priority(NVIC_TIM4_IRQ, 1);
			break;

		case TIM5:
			rcc_periph_clock_enable(RCC_TIM5);
			nvic_enable_irq(NVIC_TIM5_IRQ);
			nvic_set_priority(NVIC_TIM5_IRQ, 1);
			break;

		default:
			_system_panic();
			break;
	}
}

void tim_set_timing(int timer, uint16_t prescaler,
		    uint32_t autoreload, uint32_t startvalue)
{
	switch (timer) {
		case TIM2:
			/* Set timer start value. */
			TIM_CNT(TIM2) = startvalue;

			/* Set timer prescaler, it directly specified the
			 * division
			 */
			TIM_PSC(TIM2) = prescaler -1;

			/* End timer value. If this is reached an interrupt is
			 * generated.
			 */
			TIM_ARR(TIM2) = autoreload;
			break;

		case TIM3:
			TIM_CNT(TIM3) = startvalue;
			TIM_PSC(TIM3) = prescaler -1;
			TIM_ARR(TIM3) = autoreload;
			break;

		case TIM4:
			TIM_CNT(TIM4) = startvalue;
			TIM_PSC(TIM4) = prescaler -1;
			TIM_ARR(TIM4) = autoreload;
			break;

		case TIM5:
			TIM_CNT(TIM5) = startvalue;
			TIM_PSC(TIM5) = prescaler -1;
			TIM_ARR(TIM5) = autoreload;
			break;

		default:
			_system_panic();
			break;
	}
}

void tim_reset(int timer)
{
	switch (timer) {
		case TIM2:
			TIM_CNT(TIM2) = 0;
			break;

		case TIM3:
			TIM_CNT(TIM3) = 0;
			break;

		case TIM4:
			TIM_CNT(TIM4) = 0;
			break;

		case TIM5:
			TIM_CNT(TIM5) = 0;
			break;

		default:
			_system_panic();
			break;
	}
}

void tim_enable(int timer, bool control)
{
	switch (timer) {
		case TIM2:
			/* Start/Stop the timer */
			TIM_CR1(TIM2) |= control ? TIM_CR1_CEN : (0 << 0);
			break;

		case TIM3:
			TIM_CR1(TIM3) |= control ? TIM_CR1_CEN : (0 << 0);
			break;

		case TIM4:
			TIM_CR1(TIM4) |= control ? TIM_CR1_CEN : (0 << 0);
			break;

		case TIM5:
			TIM_CR1(TIM5) |= control ? TIM_CR1_CEN : (0 << 0);
			break;

		default:
			_system_panic();
			break;
	}
}

void tim_on_off_irq(int timer, bool control)
{
	switch (timer) {
		case TIM2:
			/* Enale/disable irq the TIMER */
			TIM_DIER(TIM2) |= control ? TIM_DIER_UIE : (0 << 0);
			break;

		case TIM3:
			TIM_DIER(TIM3) |= control ? TIM_DIER_UIE : (0 << 0);
			break;

		case TIM4:
			TIM_DIER(TIM4) |= control ? TIM_DIER_UIE : (0 << 0);
			break;

		case TIM5:
			TIM_DIER(TIM5) |= control ? TIM_DIER_UIE : (0 << 0);
			break;

		default:
			_system_panic();
			break;
	}
}

/* !TODO: improve the isr handler */

extern void tim2_isr(void)
{

	/* put here isr_job */

	/* Clear interrrupt flag. */
	TIM_SR(TIM2) &= ~TIM_SR_UIF;
}


extern void tim3_isr(void)
{
	/* put here isr_job */

	/* Clear interrrupt flag. */
	TIM_SR(TIM3) &= ~TIM_SR_UIF;
}

extern void tim4_isr(void)
{
	/* put here isr_job */

	/* Clear interrrupt flag. */
	TIM_SR(TIM4) &= ~TIM_SR_UIF;
}

extern void tim5_isr(void)
{
	/* put here isr_job */

	/* Clear interrrupt flag. */
	TIM_SR(TIM5) &= ~TIM_SR_UIF;
}
