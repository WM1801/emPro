/*
 * fonts.h
 *
 *  Created on: 14 дек. 2016 г.
 *      Author: Администратор
 */

#ifndef FONTS_H_
#define FONTS_H_

#include <stdint.h>


typedef struct _tFont
{
	const uint8_t * table;
	uint16_t Width;
	uint16_t Height;
}sFONT;

extern sFONT Font64;
extern sFONT Font24;
extern sFONT Font20;
extern sFONT Font16;
extern sFONT Font12;
extern sFONT Font8;


#define LINE(x) ((x) *(((sFONT*)BSP_LCD_GetFont())->Height))

#endif /* FONTS_H_ */
