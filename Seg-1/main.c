#include <REGX52.H>

unsigned char Seg_Dei[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

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


void Seg_Proc(unsigned char wei,dei)
{
	switch(wei)
	{
		case 1: P2_4 = 1;P2_3 = 1;P2_2 = 1;break;
		case 2: P2_4 = 1;P2_3 = 1;P2_2 = 0;break;
		case 3: P2_4 = 1;P2_3 = 0;P2_2 = 1;break;
		case 4: P2_4 = 1;P2_3 = 0;P2_2 = 0;break;
		case 5: P2_4 = 0;P2_3 = 1;P2_2 = 1;break;
		case 6: P2_4 = 0;P2_3 = 1;P2_2 = 0;break;
		case 7: P2_4 = 0;P2_3 = 0;P2_2 = 1;break;
		case 8: P2_4 = 0;P2_3 = 0;P2_2 = 0;break;
	}
	P0 = Seg_Dei[dei];
	Delay(1);
	P0 = 0x00;
}

int main()
{
	while(1)
	{
		Seg_Proc(1,1);

		Seg_Proc(2,4);

		Seg_Proc(4,5);

	}
}