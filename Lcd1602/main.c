#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Key.h"

unsigned char Key_Num;
unsigned int Password;
unsigned char Count;

int main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		Key_Num = Key_Read();
		if(Key_Num)
		{
			if(Key_Num<=10)
			{
				if(Count<4)
				{
					Password *= 10;
					Password += Key_Num%10;
					Count++;
				}	
				LCD_ShowNum(2,1,Password,4);
			}
			if(Key_Num == 11)
			{
				if(Password == 1617)
				{
					LCD_ShowString(1,14,"OK ");
					Password = 0;
					Count = 0;
					LCD_ShowNum(2,1,Password,4);
				}	
				else
				{
					LCD_ShowString(1,14,"ERR");
					Password = 0;
					Count = 0;
					LCD_ShowNum(2,1,Password,4);
				}	
			}
			if(Key_Num == 12)
			{
					LCD_ShowString(1,14,"   ");
					Password = 0;
					Count = 0;
					LCD_ShowNum(2,1,Password,4);
			}
		}
	}
}