#include <REGX52.H>

void UART_Init()
{
	SCON = 0x50;
	PCON &= 0x7f;
	TMOD &= 0x0f;
	TMOD |= 0x20;
	TH1 = 0xfa;
	TL1 = 0xfa;
	ET1 = 0;
	TR1 = 1;
	EA = 1;
	ES = 1;
}