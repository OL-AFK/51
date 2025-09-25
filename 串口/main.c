#include <REGX52.H>
#include "Delay.h"

unsigned char Sec;

void UART_Init()
{
	SCON = 0x40;
	PCON &= 0x7f; 
	TMOD &= 0x0f;
	TMOD |= 0x20;
	TL1 = 0xfa;
	TH1 = 0xfa;
	ET1 = 0;
	TR1 = 1;
}

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
	
}

int main()
{
	UART_Init();
	
	while(1)
	{
		UART_SendByte(Sec);
		Sec++;
		Delay(1000);
	}
}