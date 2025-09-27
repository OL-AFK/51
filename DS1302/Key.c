#include <REGX52.H>
#include "Delay.h"

unsigned char Key_Read()
{
	unsigned char temp = 0;
	P1 = 0xff;
	P1_3 = 0;
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0);Delay(20);temp = 1;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0);Delay(20);temp = 5;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0);Delay(20);temp = 9;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0);Delay(20);temp = 13;}
	P1 = 0xff;
	P1_2 = 0;
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0);Delay(20);temp = 2;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0);Delay(20);temp = 6;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0);Delay(20);temp = 10;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0);Delay(20);temp = 14;}
	P1 = 0xff;
	P1_1 = 0;
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0);Delay(20);temp = 3;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0);Delay(20);temp = 7;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0);Delay(20);temp = 11;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0);Delay(20);temp = 15;}
	P1 = 0xff;
	P1_0 = 0;
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0);Delay(20);temp = 4;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0);Delay(20);temp = 8;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0);Delay(20);temp = 12;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0);Delay(20);temp = 16;}
	return temp;
}