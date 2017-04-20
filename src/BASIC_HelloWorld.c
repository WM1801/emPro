/*********************************************************************
*                SEGGER MICROCONTROLLER SYSTEME GmbH                 *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 1996 - 2015  SEGGER Microcontroller Systeme GmbH        *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

***** emWin - Graphical user interface for embedded applications *****
emWin is protected by international copyright laws.   Knowledge of the
source code may not be used to write a similar product.  This file may
only be used in accordance with a license and should not be re-
distributed in any way. We appreciate your understanding and fairness.
----------------------------------------------------------------------
File        : BASIC_HelloWorld.c
Purpose     : Simple demo drawing "Hello world"
----------------------------------------------------------------------
*/
#include "stm32f429xx.h"
#include "GUI.h"

uint16_t currentFrame = 0;
uint16_t viewFrame = 0;
#define MAX_COUNT_FRAME  6

#define MAX_DINAMIC_DATA 255
uint8_t stopFrame1 = 0;
uint8_t enableUpdateFrame = 0;
uint16_t dinamicData = 0;
uint8_t masDinamic[5] = {'0','0','0','0','\0'};
uint16_t time = 0;
void currentView(uint16_t n);
void updateDinamicData();
void updateFrame();

void frame1();
void frame2();
void frame3();
void frame4();
void frame5();
void frame6();

void frame1()
{


	viewFrame = 1;
	  GUI_SetBkColor(GUI_BLACK);
	  GUI_Clear();
	  GUI_SetColor(GUI_WHITE);

	  GUI_SetFont(&GUI_FontTimesNewRoman64);
	  GUI_DispStringAt("123", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);
	  GUI_FillCircle(10,120,20);
}

void frame2()
{
	  GUI_SetBkColor(GUI_WHITE);
	  GUI_Clear();
	  GUI_SetColor(GUI_RED);
	  GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
	  GUI_FillCircle(120,120,80);
	  GUI_SetDrawMode(GUI_DRAWMODE_XOR);
	  GUI_FillCircle(140,140,80);
	  viewFrame = 2;


}

void frame3()
{
	 GUI_SetBkColor(GUI_YELLOW);
	 GUI_SetDrawMode(GUI_DRAWMODE_NORMAL);
     GUI_Clear();
     GUI_SetColor(GUI_BLUE);
     GUI_SetPenSize(4);
     GUI_AA_DrawLine(30,30,190,60);
     GUI_DrawLine(190,30,30,60);
     GUI_DrawRoundedRect(100,30,200,190,15);

     {
    	 const GUI_POINT aPoints[8] = {
    			 {30,230},{100,240},
				 {110,310}, {120,240},
				 {190,230}, {120,220},
				 {110,150}, {100,220},
    	 };
    	 GUI_AA_FillPolygon(&aPoints, 8,0,0);
     }
     GUI_SetFont(&GUI_Font16B_1);
     GUI_RECT rect = {10,10,40,80};
     GUI_SetTextMode(GUI_TM_XOR);
     GUI_FillRect(rect.x0, rect.y0, rect.y0, rect.y1);
     uint8_t tex[] = "Rotated\ntext";
     GUI_DispStringInRectEx(tex, &rect, GUI_TA_CENTER|GUI_TA_VCENTER, strlen(tex), GUI_ROTATE_CCW);
     GUI_SetTextMode(GUI_TM_NORMAL);
     viewFrame = 3;
}

void frame4()
{
	  GUI_Clear();
	  GUI_SetFont(&GUI_FontTimesNewRoman64);
	  uint8_t masChar[6] = {0x31, 0x44, 0x45, 0x46, 0x32, '\0'};
	  GUI_DispString("Тест Абв");
	  GUI_DispStringAt(masChar, (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);
	  viewFrame = 4;
}

void frame5()
{
	  GUI_SetBkColor(GUI_RED);
	  GUI_Clear();
	  GUI_SetColor(GUI_BLACK);
	  GUI_DrawPie(100,100,50,0,60,0);
	  GUI_DrawPie(100,100,50,120,180,0);
	  GUI_DrawPie(100,100,50,240,300,0);

	  GUI_AA_DrawArc(150,200,40,0,0,180);
	  GUI_AA_DrawArc(150,200,50,0,30,90);
	  GUI_AA_DrawArc(150,200,60,0,30,90);
	  GUI_AA_DrawArc(150,200,70,0,30,90);
	  GUI_SetBkColor(GUI_BLACK);
	  GUI_Clear();
	  GUI_SetColor(GUI_WHITE);
	  viewFrame = 5;
}
void frame6()
{

     itoa(dinamicData, masDinamic, 10);
     GUI_Clear();

     GUI_DispStringAtCEOL(masDinamic, 10, 0);
     GUI_DispStringAtCEOL(masDinamic, 10, 50);
     GUI_DispStringAtCEOL(masDinamic, 10, 100);
     GUI_DispStringAtCEOL(masDinamic, 10, 150);
     GUI_DispStringAtCEOL(masDinamic, 10, 200);
     GUI_DispStringAtCEOL(masDinamic, 10, 250);
     GUI_DispStringAtCEOL(masDinamic, 10, 300);
     GUI_DispStringAtCEOL(masDinamic, 110, 0);
     GUI_DispStringAtCEOL(masDinamic, 110, 50);
     GUI_DispStringAtCEOL(masDinamic, 110, 100);
     GUI_DispStringAtCEOL(masDinamic, 110, 150);
     GUI_DispStringAtCEOL(masDinamic, 110, 200);
     GUI_DispStringAtCEOL(masDinamic, 110, 250);
     GUI_DispStringAtCEOL(masDinamic, 110, 300);
     viewFrame = 6;

}


void updateDinamicData()
{
	if(currentFrame>=(MAX_COUNT_FRAME-1))
	{
		dinamicData++;
		if(dinamicData>MAX_DINAMIC_DATA)
		{
			dinamicData = 0;
		}
		enableUpdateFrame = 0;
		stopFrame1 = 0;
	}
}


void currentView(uint16_t n)
{

	GUI_MULTIBUF_Begin();
	switch(n)
	{
	case 0: { frame1(); break;}
	case 1: { frame2(); break;}
	case 2: { frame3(); break;}
	case 3: { frame4(); break;}
	case 4: { frame5(); break;}
	case 5: { frame6(); break;}
	default: {};
	}
	GUI_MULTIBUF_End();
	enableUpdateFrame = 1;
}
/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  /*GUI_Clear();
  GUI_SetFont(&GUI_FontD64);
  GUI_DispStringAt("123", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);*/
  currentView(currentFrame);

  while(enableUpdateFrame);
}


void updateFrame()
{

		enableUpdateFrame = 0;
		currentFrame++;
		if(currentFrame>=MAX_COUNT_FRAME)
		{
		currentFrame = 0;
		}

}


/*************************** End of file ****************************/
