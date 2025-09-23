#include <REGX52.H>
void Delay(unsigned char xms);
char Led = 0;

void Delay(unsigned char xms)	//@11.0592MHz
{
	unsigned char data i, j;

	while(xms--)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
	
}


int main()
{
	P2 = ~0x01;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			Led++;
			if(Led>=8)
				Led = 0;
			P2 = ~(0x01<<Led);
		}
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			Led--;
			if(Led<0)
				Led = 7;
			P2 = ~(0x01<<Led);
		}
	}
}