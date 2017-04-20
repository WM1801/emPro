/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "main.h"
#include "WM.h"
#include "timers.h"
#include "FontTTF.h"
//#include "dma2d.h"

//extern DMA2D_HandleTypeDef Dma2dHandle;

uint8_t GUI_Initialized = 0;

extern void MainTask(void);



uint16_t tempKoord = 0;

static void SystemClock_Config(void);
void Error_Handler();




void DMA2D_drawPixel(DMA2D_HandleTypeDef* dma2dHandle, int16_t x, int16_t y, int16_t color)
{
	// перенастроить dma2dHandle (режим, цвет)
	//if(HAL_DMA2D_Start_IT(&dma2dHandle, (uint32_t)&symvol, (uint32_t)adressRed, ROW_COUNT, COLUMN_COUNT) != HAL_OK)
	//{
	   /* Initialization Error */
	 //   Error_Handler();
	//}
}








/*static void DMA2D_Config(void)
{

//	updateAdr();

  // Configure the DMA2D Mode, Color Mode and output offset
  Dma2dHandle.Init.Mode         = DMA2D_M2M_PFC;
  Dma2dHandle.Init.ColorMode    = DMA2D_ARGB8888;
  Dma2dHandle.Init.OutputOffset = 0x0;

  // DMA2D Callbacks Configuration
  Dma2dHandle.XferCpltCallback  = TransferComplete;
  Dma2dHandle.XferErrorCallback = TransferError;

  // Foreground Configuration
  Dma2dHandle.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  Dma2dHandle.LayerCfg[1].InputAlpha = 0xFF;
  Dma2dHandle.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  Dma2dHandle.LayerCfg[1].InputOffset = 0x0;

  Dma2dHandle.Instance          = DMA2D;

  // DMA2D Initialization
  if(HAL_DMA2D_Init(&Dma2dHandle) != HAL_OK)
  {
    // Initialization Error
    Error_Handler();
  }

  if(HAL_DMA2D_ConfigLayer(&Dma2dHandle, 1) != HAL_OK)
  {
    // Initialization Error
    Error_Handler();
  }
}*/

void updTempKoord()
{
	tempKoord+=3;
	if(tempKoord>240)
	{
		tempKoord = 0;
	}
}


void testImage()
{



	/*	BSP_LCD_Init();
		BSP_LCD_LayerDefaultInit(0, LCD_LAY1_ADRESS);
		BSP_LCD_LayerDefaultInit(1, LCD_LAY2_ADRESS);
		BSP_LCD_DisplayOn();



		Point p1;
		Point p2;
		Point p3;
		Point p4;
		Point p5;

		BSP_LCD_SelectLayer(0);
		BSP_LCD_Clear(LCD_COLOR_WHITE);//цвет фона
		BSP_LCD_SetBackColor(LCD_COLOR_GREEN); // цвет фона шрифта
		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		BSP_LCD_DisplayStringAtLine(2, "STM32");

		p1.X = 10; p1.Y = 250;
		p2.X = 50; p2.Y = 250;
		BSP_LCD_DrawLine(p1.X, p1.Y, p2.X, p2.Y);

		p1.X = 10; p1.Y = 250;
		p2.X = 10; p2.Y = 200;
		BSP_LCD_DrawLine(p1.X, p1.Y, p2.X, p2.Y);

		BSP_LCD_SelectLayer(1);
		BSP_LCD_Clear(LCD_COLOR_YELLOW);//цвет фона
		BSP_LCD_SetTransparency(1,0);
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_FillTriangle(100, 100, 200, 100, 250,175);
		BSP_LCD_SetTextColor(LCD_COLOR_BLUE);


		p1->X = 50;  p1->Y = 50;
		p2->X = 100; p2->Y = 50;
		p5->X = 125; p5->Y = 75;
		p3->X = 100; p3->Y = 100;
		p4->X = 50; p4->Y = 100;
			p1.X = 50; p1.Y = 50;
			p2.X = 100; p2.Y = 50;
			p5.X = 125; p5.Y = 75;
			p3.X = 100; p3.Y = 100;
			p4.X = 50; p4.Y = 100;
		Point masP[] =  {p1, p2, p5, p3, p4};
		BSP_LCD_FillPolygon(masP, 5);

		Point t1, t2, t3, t4, t5;
		int dx = 55; int dy = 100;
		t1.X = 50+dx; t1.Y = 50+dy;
		t2.X = 100+dx; t2.Y = 50+dy;
		t5.X = 125+dx; t5.Y = 75+dy;
		t3.X = 100+dx; t3.Y = 100+dy;
		t4.X = 50+dx; t4.Y = 100+dy;
		Point masT[] =  {t1, t2, t5, t3, t4};
		BSP_LCD_DrawPolygon(masT, 5);

		BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
		p1.X = 10; p1.Y = 250;
		p2.X = 50; p2.Y = 250;
		BSP_LCD_DrawLine(p1.X, p1.Y, p2.X, p2.Y);

		p1.X = 10; p1.Y = 250;
		p2.X = 10; p2.Y = 200;
		BSP_LCD_DrawLine(p1.X, p1.Y, p2.X, p2.Y);
*/

		//MyDrawChar(100,100,&symm);

}

void testDma2d()
{


}


int main(void)
{
	HAL_Init();
	SystemClock_Config();

	ledInit(LED3);
	ledInit(LED4);
	ledInit(LED5);
	ledInit(LED6);
	buttonInit(BUTTON_KEY, BUTTON_MODE_EXTI);
	  __HAL_RCC_CRC_CLK_ENABLE();
	tempKoord = 0;
	//testImage();
	 BSP_SDRAM_Init();
	//DMA2D_Config();
	 GUI_Init();

	 GUI_Initialized = 1;

	   /* Activate the use of memory device feature */
	   WM_SetCreateFlags(WM_CF_MEMDEV);


	init_timerFrame();
	initFontTTF();


	  // MainTask();
	//GUI_SetOrientation(GUI_SWAP_XY);

	while(1)
	{
		MainTask();
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIMER_FRAME)
	{
		ledToggle(LED5);
		updateDinamicData();

	}
}






void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == KEY_BUTTON_PIN)
	{

			ledToggle(LED4);
			ledOn(LED6);
			updateFrame();

	}
}

static void SystemClock_Config(void)
{
/*	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	//Enable power control clock
	__HAL_RCC_PWR_CLK_ENABLE();
	  The voltage scaling allows optimizing the power consumption when the device is
	     clocked below the maximum system frequency, to update the voltage scaling value
	     regarding system frequency refer to product datasheet.
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		RCC_OscInitStruct.PLL.PLLM = 8;
		RCC_OscInitStruct.PLL.PLLN = 336;
		RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
		RCC_OscInitStruct.PLL.PLLQ = 7;
		HAL_RCC_OscConfig(&RCC_OscInitStruct);

		 Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
		     clocks dividers
		  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
		  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
		  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
		  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
		  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

		  *Configure the Systick interrupt time+

		   HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

		     *Configure the Systick

		   HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

		    SysTick_IRQn interrupt configuration
		   HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);*/
//********
		   RCC_ClkInitTypeDef RCC_ClkInitStruct;
		    RCC_OscInitTypeDef RCC_OscInitStruct;

		    /* Enable Power Control clock */
		    __HAL_RCC_PWR_CLK_ENABLE();

		    /* The voltage scaling allows optimizing the power consumption when the device is
		       clocked below the maximum system frequency, to update the voltage scaling value
		       regarding system frequency refer to product datasheet.  */
		    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

		    /* Enable HSE Oscillator and activate PLL with HSE as source */
		    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		    RCC_OscInitStruct.PLL.PLLM = 8;
		    RCC_OscInitStruct.PLL.PLLN = 360;
		    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
		    RCC_OscInitStruct.PLL.PLLQ = 7;
		    HAL_RCC_OscConfig(&RCC_OscInitStruct);

		    /* Activate the Over-Drive mode */
		    HAL_PWREx_EnableOverDrive();

		    /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
		    clocks dividers */
		    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
		    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
		    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
		    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
		    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);
}


void Error_Handler()
{
	HAL_StatusTypeDef sts;
	sts = HAL_ERROR;

}
