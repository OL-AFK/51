#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "Key.h"
#include "LCD1602.h"

unsigned char Second = 55,Minute = 59,Hour = 23;


int main()
{
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1,1,"Time:");
	LCD_ShowString(2,3,":  :");
	while(1)
	{
		
		LCD_ShowNum(2,1,Hour,2);
		LCD_ShowNum(2,4,Minute,2);
		LCD_ShowNum(2,7,Second,2);
	}
}

void Timer0_Rountine() interrupt 1
{
	static unsigned int Count = 0;
	TL0 = 0x66;
	TH0 = 0xfc;
	
	Count++;
	if(Count>=1000)
	{
		Count = 0;
		Second++;
		if(Second>=60)
		{
			Second = 0;
			Minute++;
			if(Minute>=60)
			{
				Minute = 0;
				Hour++;
				if(Hour>=24)
					Hour = 0;
			}
		}
	}
}