/*
 * sdram.h
 *
 *  Created on: 10 янв. 2017 г.
 *      Author: Администратор
 */

#ifndef SDRAM_H_
#define SDRAM_H_

#include "stm32f4xx_hal.h"
#include "stm32f429xx.h"


// FMC SDRAM BANK adress
#define SDRAM_DEVICE_ADDR	 ((uint32_t)0xD0000000)
#define SDRAM_DEVICE_SIZE	 ((uint32_t)0x00800000)/* SDRAM device size in MBytes */

//  FMC SDRAM Memory Width
/* #define SDRAM_MEMORY_WIDTH   FMC_SDRAM_MEM_BUS_WIDTH_8 */
#define SDRAM_MEMORY_WIDTH 			((uint32_t)0x10U)

//FMC SDRAM CAS LATENCY
#define SDRAM_CAS_LATENCY			((uint32_t)0x0180U)//384

//FMC SDRAM MEMORY clock period
#define SDCLOCK_PERIOD				((uint32_t)0x0800U) /* Default configuration used with LCD *///2048

//FMC SDRAM Memory Read Burst feature
#define SDRAM_READBURST				((uint32_t)0x00U) /* Default configuration used with LCD */


//FMC SDRAM BANK REMAP
/*set the refresh rate counter */
/* (15.62 us x Freq) - 20 */
#define REFRESH_COUNT   			((uint32_t)1386) /*SDRAM refresh counter */
#define SDRAM_TIMEOUT				((uint32_t)0xFFFF)

/*DMA definitions for sdram dma transfer*/
#define __DMAx_CLK_ENABLE 			__DMA2_CLK_ENABLE
#define SDRAM_DMAx_CHANNEL			DMA_CHANNEL_0
#define SDRAM_DMAx_STREAM			DMA2_Stream0
#define SDRAM_DMAx_IRQn				DMA2_Stream0_IRQn
#define SDRAM_DMAx_IRQHandler		DMA2_Stream0_IRQHandler

//FMC SDRAM MODE definition register defines
#define SDRAM_MODEREG_BURST_LENGTH_1			((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2 			((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4			((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8 			((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL		((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED	((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2				((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3				((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


 //STM32F429I_DISCOVERY_SDRAM_Exported_Functions STM32F429I DISCOVERY SDRAM Exported Functions
void BSP_SDRAM_Init(void);
void BSP_SDRAM_Initialization_sequence(uint32_t RefreshCount);
void BSP_SDRAM_ReadData(uint32_t uwStartAddres, uint32_t* pData, uint32_t uwDataSize);
void BSP_SDRAM_ReadData_DMA(uint32_t uwStartAdress, uint32_t* pData, uint32_t uwDataSize);
void BSP_SDRAM_WriteData(uint32_t uwStartAddres, uint32_t* pData, uint32_t uwDataSize);
void BSP_SDRAM_WriteData_DMA(uint32_t uwStartAddres, uint32_t* pData, uint32_t uwDataSize);
HAL_StatusTypeDef BSP_SDRAM_Sendcmd(FMC_SDRAM_CommandTypeDef *SdramCmd);
void BSP_SDRAM_DMA_IRQHandler(void);

#endif /* SDRAM_H_ */
