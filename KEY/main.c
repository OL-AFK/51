#include <REGX52.H>


void Delay(unsigned int ms)	//@11.0592MHz
{
	unsigned char data i, j;

	while(ms--)
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
	unsigned char Led = 0;
	while(1)
	{
		if(P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			
			Led++;
			P2 = ~Led;
		}
	}
}