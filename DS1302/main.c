#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"
#include "Ds1302.h"

unsigned char Second,Minute;

int main()
{
	DS1302_Init();
	LCD_Init();
	LCD_ShowString(1,1,"RTC");
	DS1302_WriteByte(0x80,0x55);
	DS1302_WriteByte(0x82,0x03);
	while(1)
	{
		Second = DS1302_Read(0x81);
		Minute = DS1302_Read(0x83);
		LCD_ShowNum(2,1,Minute/16*10+Minute%16,2);
		LCD_ShowNum(2,4,Second/16*10+Second%16,2);
	}
}