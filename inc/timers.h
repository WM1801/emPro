/*
 * timers.h
 *
 *  Created on: 03 апр. 2017 г.
 *      Author: Администратор
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"

uint8_t statusTimer3;

#define TIMER_FRAME 				TIM3
#define TIMER_FRAME_CLK_ENABLE() 	__HAL_RCC_TIM3_CLK_ENABLE()
#define TIMER_FRAME_IRQn			TIM3_IRQn
#define TIMER_FRAME_IRQ_HANDLER		TIM3_IRQHandler
#define TIMER_FRAME_MS 				(400) //n/10 = ms

void init_timerFrame();


uint32_t statusTimer2;
#define TIMER_TIME				TIM2
#define TIMER_TIME_CLK_ENABLE() 	__HAL_RCC_TIM3_CLK_ENABLE()
#define TIMER_TIME_IRQn			TIM2_IRQn
#define TIMER_TIME_IRQ_HANDLER		TIM2_IRQHandler
#define TIMER_TIME_MS 				(10) //n/10 = ms

void init_timerTime();



#endif /* TIMERS_H_ */
