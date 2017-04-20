/*
 * FontTTF.c
 *
 *  Created on: 20 апр. 2017 г.
 *      Author: Администратор
 */
#include "FontTTF.h"


uint32_t errorFt = 0;
FT_Library library;
FT_Face face;


void initFontTTF()
{
		errorFt =  FT_Init_FreeType(&library);

		if(errorFt){
				  GUI_SetBkColor(GUI_BLACK);
				  GUI_Clear();
				  GUI_SetColor(GUI_WHITE);

				  GUI_SetFont(&GUI_FontTimesNewRoman64);
				  GUI_DispStringAt("error",10, 150);

				  while(1);
		}
		//errorFt = FT_New_Face()

}
