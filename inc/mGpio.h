/*
 * mGpio.h
 *
 *  Created on: 18 янв. 2017 г.
 *      Author: Администратор
 */

#ifndef MGPIO_H_
#define MGPIO_H_

#include "stm32f429xx.h"
#include "stm32f4xx_hal.h"

//***********************************
//          LED
//***********************************
typedef enum
{
	LED3 = 0,
	LED4 = 1,
	LED5 = 2,
	LED6 = 3
}Led_TypeDef;

#define LEDn 						4

#define LED3_PIN					GPIO_PIN_13
#define LED3_GPIO_PORT				GPIOG
#define LED3_GPIO_CLK_ENABLE()		__GPIOG_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()		__GPIOG_CLK_DISABLE()

#define LED4_PIN					GPIO_PIN_14
#define LED4_GPIO_PORT				GPIOG
#define LED4_GPIO_CLK_ENABLE()		__GPIOG_CLK_ENABLE()
#define LED4_GPIO_CLK_DISABLE()		__GPIOG_CLK_DISABLE()

#define LED5_PIN					GPIO_PIN_8
#define LED5_GPIO_PORT				GPIOC
#define LED5_GPIO_CLK_ENABLE()		__GPIOC_CLK_ENABLE()
#define LED5_GPIO_CLK_DISABLE()		__GPIOC_CLK_DISABLE()

#define LED6_PIN					GPIO_PIN_3
#define LED6_GPIO_PORT				GPIOC
#define LED6_GPIO_CLK_ENABLE()		__GPIOC_CLK_ENABLE()
#define LED6_GPIO_CLK_DISABLE()		__GPIOC_CLK_DISABLE()


#define LEDx_GPIO_CLK_ENABLE(__INDEX__)   do{if((__INDEX__) == 0) LED3_GPIO_CLK_ENABLE();  else \
											 if((__INDEX__) == 1) LED4_GPIO_CLK_ENABLE(); \
											 if((__INDEX__) == 2) LED5_GPIO_CLK_ENABLE(); \
											 if((__INDEX__) == 3) LED6_GPIO_CLK_ENABLE(); \
											}while(0)

#define LEDx_GPIO_CLK_DISABLE(__INDEX__)   do{if((__INDEX__) == 0) LED3_GPIO_CLK_DISABLE();  else \
											 if((__INDEX__) == 1) LED4_GPIO_CLK_DISABLE(); \
											 if((__INDEX__) == 2) LED5_GPIO_CLK_DISABLE(); \
											 if((__INDEX__) == 3) LED6_GPIO_CLK_DISABLE(); \
											}while(0)


void ledInit(Led_TypeDef Led);
void ledOn(Led_TypeDef Led);
void ledOff(Led_TypeDef Led);
void ledToggle(Led_TypeDef Led);



//***********************************
//          Button
//***********************************
typedef enum
{
	BUTTON_KEY = 0,
}Button_TypeDef;

typedef enum
{
	BUTTON_MODE_GPIO = 0,
	BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;

#define BUTTONn							1

#define KEY_BUTTON_PIN					GPIO_PIN_0
#define KEY_BUTTON_GPIO_PORT			GPIOA
#define KEY_BUTTON_GPIO_CLK_ENABLE()	__GPIOA_CLK_ENABLE()
#define KEY_BUTTON_GPIO_CLK_DISABLE()	__GPIOA_CLK_DISABLE()
#define KEY_BUTTON_EXTI_IRQn			EXTI0_IRQn

#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)	do{if((__INDEX__) == 0) KEY_BUTTON_GPIO_CLK_ENABLE(); \
												}while(0)
#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)	do{if((__INDEX__) == 0 ) KEY_BUTTON_GPIO_CLK_DISABLE(); \
												}while(0)

void buttonInit(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
uint32_t buttonGetState(Button_TypeDef Button);


	// LCD control pin
#define LCD_NCS_PIN                  GPIO_PIN_2
#define LCD_NCS_GPIO_PORT			 GPIOC
#define LCD_NCS_GPIO_CLK_ENABLE()    __GPIOC_CLK_ENABLE()
#define LCD_NCS_GPIO_CLK_DISABLE() 	 __GPIOC_CLK_DISABLE()

// LCD Command/data pin
#define LCD_WRX_PIN 				GPIO_PIN_13
#define LCD_WRX_GPIO_PORT			GPIOD
#define LCD_WRX_GPIO_CLK_ENABLE()	__GPIOD_CLK_ENABLE()
#define LCD_WRX_GPIO_CLK_DISABLE()  __GPIOD_CLK_DISABLE()

#define LCD_RDX_PIN					GPIO_PIN_12
#define LCD_RDX_GPIO_PORT			GPIOD
#define LCD_RDX_GPIO_CLK_ENABLE() 	__GPIOD_CLK_ENABLE()
#define LCD_RDX_GPIO_CLK_DISABLE()  __GPIOD_CLK_DISABLE()

/* chip select macro definition*/
#define LCD_CS_LOW()   				HAL_GPIO_WritePin(LCD_NCS_GPIO_PORT,LCD_NCS_PIN, GPIO_PIN_RESET)
#define LCD_CS_HIGH() 				HAL_GPIO_WritePin(LCD_NCS_GPIO_PORT, LCD_NCS_PIN, GPIO_PIN_SET)

/*Set Wrx High to send data*/
#define LCD_WRX_LOW()				HAL_GPIO_WritePin(LCD_WRX_GPIO_PORT, LCD_WRX_PIN, GPIO_PIN_RESET)
#define LCD_WRX_HIGH() 				HAL_GPIO_WritePin(LCD_WRX_GPIO_PORT, LCD_WRX_PIN, GPIO_PIN_SET)

/* Set WRX High to send data*/
#define LCD_RDX_LOW() 				HAL_GPIO_WritePin(LCD_RDX_GPIO_PORT, LCD_RDX_PIN, GPIO_PIN_RESET)
#define LCD_RDX_HIGH() 				HAL_GPIO_WritePin(LCD_RDX_GPIO_PORT, LCD_RDX_PIN, GPIO_PIN_SET)
/*############################### SPIx #######################################*/
#define DISCOVERY_SPIx                          SPI5
#define DISCOVERY_SPIx_CLK_ENABLE()             __SPI5_CLK_ENABLE()
#define DISCOVERY_SPIx_GPIO_PORT                GPIOF                      /* GPIOF */
#define DISCOVERY_SPIx_AF                       GPIO_AF5_SPI5
#define DISCOVERY_SPIx_GPIO_CLK_ENABLE()        __GPIOF_CLK_ENABLE()
#define DISCOVERY_SPIx_GPIO_CLK_DISABLE()       __GPIOF_CLK_DISABLE()
#define DISCOVERY_SPIx_SCK_PIN                  GPIO_PIN_7                 /* PF.07 */
#define DISCOVERY_SPIx_MISO_PIN                 GPIO_PIN_8                 /* PF.08 */
#define DISCOVERY_SPIx_MOSI_PIN                 GPIO_PIN_9                 /* PF.09 */
/* Maximum Timeout values for flags waiting loops. These timeouts are not based
   on accurate values, they just guarantee that the application will not remain
   stuck if the SPI communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */
#define SPIx_TIMEOUT_MAX              ((uint32_t)0x1000)

//*********************************************************************************************************************

#endif /* MGPIO_H_ */
