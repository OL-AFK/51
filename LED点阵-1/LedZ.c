#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;
sbit SCK = P3^6;
sbit SER = P3^4;


void LedZ_Init()
{
	RCK = 0;
	SCK = 0;
}

void LedZ_Data(unsigned char Data)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		SER = Data & (0x80>>i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}


void LedZ_Show(unsigned char Data1,Data2)
{
	LedZ_Data(Data2);
	P0 = ~(0x80>>Data1);
	Delay(1);
	P0 = 0xff;
}