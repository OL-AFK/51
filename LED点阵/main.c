#include <REGX52.H>
#include "Delay.h"


sbit RCK = P3^5;
sbit SRCLK = P3^6;
sbit SER = P3^4;

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
	SER = Byte & (0x80>>i);
	SRCLK = 1;
	SRCLK = 0;
	}
	RCK = 1;
	RCK = 0;
}

void MatrixLED_Show(unsigned char Data1,Data2)
{
	_74HC595_WriteByte(Data2);
	P0 = ~(0x80>>Data1);
	Delay(1);
	P0 = 0xff;;
}

int main()
{
	RCK = 0;
	SRCLK = 0;
	while(1)
	{
		MatrixLED_Show(1,0x80);
		MatrixLED_Show(2,0x40);
		MatrixLED_Show(3,0x20);
		MatrixLED_Show(4,0x10);
	}
}