/*
 * myLcd.h
 *
 *  Created on: 10 ���. 2017 �.
 *      Author: �������������
 */

#ifndef LCD_INTERFEIS_H_
#define LCD_INTERFEIS_H_

#include <stdint.h>

typedef struct
{
	void 		(*Init)(void);
	uint16_t 	(*ReadID)(void);
	void 		(*DisplayOn)(void);
	void 		(*DisplayOff)(void);
	void 		(*SetCursor)(uint16_t, uint16_t);
	void 		(*WritePixel)(uint16_t, uint16_t, uint16_t);
	uint16_t	(*ReadPixel)(uint16_t, uint16_t);

	/*Optimized operation*/
	void 		(*SetDisplayWindow)(uint16_t, uint16_t, uint16_t, uint16_t);
	void        (*DrawHLine)(uint16_t, uint16_t, uint16_t, uint16_t);
	void 		(*DrawVLine)(uint16_t, uint16_t, uint16_t, uint16_t);

	uint16_t 	(*GetLcdPixelWidth)(void);
	uint16_t	(*GetLcdPixelHeight)(void);
	void 		(*DrawBitmap)(uint16_t, uint16_t, uint8_t);
	void 		(*DrawRGBImage)(uint16_t, uint16_t, uint16_t, uint16_t, uint8_t);
}LCD_DrvTypeDef;

#endif /* LCD_INTERFEIS_H_ */
