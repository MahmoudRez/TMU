/*
 * TMU_APP.c
 *
 *  Created on: Oct 12, 2019
 *      Author: alx
 */

#include "TMU.h"

uint8 g_count=0;

void toggle_led(void)
{
	PORTA ^= 0x01;
}

void toggle_led2(void)
{
	PORTA ^= 0x02;
}

void toggle_led3(void)
{
	PORTA ^= 0x04;
}

void toggle_led4(void)
{
	PORTA ^= 0x08;
	g_count++;
}

void main(void)
{
	DDRA = 0xFF;

	TMU_init(TMU_init_cnfg_ptr);
	TMU_Start_Timer(10000,toggle_led,ONE_SHOT);
	TMU_Start_Timer(5000,toggle_led2,PERIODIC);
	TMU_Start_Timer(2000,toggle_led3,PERIODIC);
	TMU_Start_Timer(1000,toggle_led4,PERIODIC);
	while(1)
	{
		TMU_Dispatch();
		if(g_count == 10)
		{
			TMU_Stop_Timer(toggle_led4);
		}
	}
}



