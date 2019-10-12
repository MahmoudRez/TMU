/*
 * TMU_Prog.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */

#include "TMU.h"


uint8 TMU_init(const TMU_ConfigType * ConfigPtr)
{
	uint8 timerIndx=0;

	for(timerIndx=0 ; timerIndx < MAX_NUM_OF_TIMERS ; timerIndx++)
	{
		if(TIMER_cnfg_arr[timerIndx].TIMER_ID == ConfigPtr->TIMER_ID)
		{

		}
	}

	uint8 retval = OK;
	return retval;

}
uint8 TMU_Start(uint8 TIME_Delay,uint8 * EVENT_Consumer,uint8 Periodicity)
{
	uint8 retval = OK;
	return retval;

}
uint8 TMU_Stop(uint8 * EVENT_Consumer)
{
	uint8 retval = OK;
	return retval;

}
uint8 TMU_Dispatcher(void)
{
	uint8 retval = OK;
	return retval;

}
