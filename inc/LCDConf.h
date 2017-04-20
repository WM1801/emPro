/*
 * LCDConf.h
 *
 *  Created on: 13 апр. 2017 г.
 *      Author: Администратор
 */

#include "main.h"
#include "GUIDRV_Lin.h"

#ifndef LCDCONF_H
#define LCDCONF_H


typedef struct
{
  int32_t      address;
  __IO int32_t pending_buffer;
  int32_t      buffer_index;
  int32_t      xSize;
  int32_t      ySize;
  int32_t      BytesPerPixel;
  LCD_API_COLOR_CONV   *pColorConvAPI;
}
LCD_LayerPropTypedef;

#endif /* LCDCONF_H */

/*************************** End of file ****************************/
