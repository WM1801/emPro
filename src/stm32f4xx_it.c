/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @author  Ac6
  * @version V1.0
  * @date    02-Feb-2015
  * @brief   Default Interrupt Service Routines.
  ******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32f4xx_it.h"
#include "GUI.h"

#include "mGpio.h"
#include "timers.h"
extern TIM_HandleTypeDef timFrame;
extern TIM_HandleTypeDef timTime;
extern LTDC_HandleTypeDef hltdc;


//extern DMA2D_HandleTypeDef     Dma2dHandle;

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            	  	    Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles SysTick Handler, but only if no RTOS defines it.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}


void EXTI0_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(KEY_BUTTON_PIN);
}

/*void DMA2D_IRQHandler(void)
{
  HAL_DMA2D_IRQHandler(&Dma2dHandle);
}*/

/**
  * @brief  This function handles LTDC global interrupt request.
  * @param  None
  * @retval None
  */
/**
  * @brief  This function handles LTDC global interrupt request.
  * @param  None
  * @retval None
  */
void LTDC_IRQHandler(void)
{
  HAL_LTDC_IRQHandler(&hltdc);
}


void TIMER_FRAME_IRQ_HANDLER(void)
{
	HAL_TIM_IRQHandler(&timFrame);
}

void TIMER_TIME_IRQ_HANDLER(void)
{
	HAL_TIM_IRQHandler(&timTime);
}

