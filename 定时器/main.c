#include <REGX52.H>
#include <INTRINS.H>
#include "Time0.h"
#include "Delay.h"
#include "Key.h"

unsigned char KeyNum = 0;
unsigned char LedMode;

int main()
{
	Timer0_Init();
	P2 = 0xfe;
	while(1)
	{
		KeyNum = Key_read();
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				LedMode++;
				if(LedMode>=2) LedMode = 0;
			}
		}
	}
}


void Timer0_Routine()  interrupt 1
{
	static unsigned int Count;
	TL0 = 0x66;				
	TH0 = 0xFC;
	Count++;
	if(Count>=1000)
	{
		Count = 0;
		if(LedMode == 0)
			P2 =_crol_(P2,1);
		if(LedMode == 1)
			P2 =_cror_(P2,1);
	}
}