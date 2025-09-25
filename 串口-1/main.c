#include <REGX52.H>
#include "UART.h"
#include "Delay.h"


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
		
	}

}

void UART_Routine() interrupt 4
{
	if(RI = 1)
	{
		P2 = SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
}