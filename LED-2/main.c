#include <REGX52.H>

void Delay(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	while(xms)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}


int main()
{
	while(1)
	{
		P2 = 0xfe;
		Delay(500);
		P2 = 0xfd;
		Delay(500);
		P2 = 0xfb;
		Delay(500);
		P2 = 0xf7;
		Delay(500);
		P2 = 0xef;
		Delay(500);
		P2 = 0xdf;
		Delay(500);
		P2 = 0xbf;
		Delay(500);
		P2 = 0x7f;
		Delay(500);
	}
}