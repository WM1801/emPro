
#include "timers.h"

TIM_HandleTypeDef timFrame;

TIM_HandleTypeDef timTime;

TIM_IC_InitTypeDef     sICConfig3;
uint16_t uwPrescalerValue = 0;



void init_timerFrame()
{
	 /*##-1- Enable peripherals and GPIO Clocks #################################*/
				  /* TIMx Peripheral clock enable */
	TIMER_FRAME_CLK_ENABLE();

	timFrame.Instance = TIMER_FRAME;
	timFrame.Init.Period = TIMER_FRAME_MS;//42000;//8400

	timFrame.Init.Prescaler =  9000;//400;//30-1;//300//ms= n/10
	timFrame.Init.ClockDivision = TIM_CLOCKDIVISION_DIV2;
	timFrame.Init.CounterMode = TIM_COUNTERMODE_UP;
	timFrame.Init.RepetitionCounter = 0;

	if(HAL_TIM_Base_Init(&timFrame) != HAL_OK)
	{
		Error_Handler();
	}


	if(HAL_TIM_Base_Start_IT(&timFrame) != HAL_OK)
	{
		Error_Handler();
	}

		/*##-2- Configure the NVIC for TIMx ########################################*/
					  /* Set the TIMx priority */
	HAL_NVIC_SetPriority(TIMER_FRAME_IRQn, 0 ,1);

		/* Enable the TIMx global Interrupt */
	HAL_NVIC_EnableIRQ(TIMER_FRAME_IRQn);

}
