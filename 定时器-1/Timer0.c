#include <REGX52.H>


void Timer0_Init()
{
	TMOD &= 0xf0;
	TMOD |= 0x01;
	TF0 = 0;
	TR0 = 1;
	TL0 = 0x66;
	TH0 = 0xfc;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}