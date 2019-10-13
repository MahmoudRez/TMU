/*
 * TMU_Prog.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */

#include "TMU.h"

uint8 g_timerTick_flag=0;
uint8 g_systemTick_flag=0;
uint8 g_matchingTickCount=0;

void TMU_callback(void)
{
	g_timerTick_flag++;
	if(g_timerTick_flag >= g_matchingTickCount)
	{
		g_systemTick_flag++;
		g_timerTick_flag=0;
		PORTA ^= 0xFF;
	}
}

uint8 TMU_init(const TMU_ConfigType * ConfigPtr)
{
	uint8 timerIndx=0;
	uint32 maxApplicableTickTime;
	uint16 Tick_Time;
	for(timerIndx=0 ; timerIndx < MAX_NUM_OF_TIMERS ; timerIndx++)
	{
		if(TIMER_cnfg_arr[timerIndx].TIMER_ID == ConfigPtr->TIMER_ID)
		{
			/************************************************************************
			 * 				Calculating timer tick based on the prescaler
			 ************************************************************************/
			switch(TIMER_cnfg_arr[timerIndx].Prescaler)
			{
			case F_CPU_1:
				Tick_Time= (1.0*1000000UL/ F_CPU);
				break;
			case F_CPU_8:
				Tick_Time= (8.0*1000000UL/ F_CPU);
				break;
			case F_CPU_32:
				Tick_Time= (32.0*1000000UL/ F_CPU);
				break;
			case F_CPU_64:
				Tick_Time= (64.0*1000000UL/ F_CPU);
				break;
			case F_CPU_128:
				Tick_Time= (128.0*1000000UL/ F_CPU);
				break;
			case F_CPU_256:
				Tick_Time= (256.0*1000000UL/ F_CPU);
				break;
			case F_CPU_1024:
				Tick_Time= (1024.0*1000000UL/ F_CPU);
				break;
				/*			default:
				retval=NOK;
				break;*/
			}

			/************************************************************************
			 * 			Calculating the interrupt time and set the call back
			 ************************************************************************/
			switch(TIMER_cnfg_arr[timerIndx].OC_ChA_Mode)
			{
			case NORMAL_MODE:


				switch(ConfigPtr->TIMER_ID)
				{
				case TIMER0:
					maxApplicableTickTime = Tick_Time*256;
					TIMER0_OVF_setCallBack(TMU_callback);
					break;

				case TIMER1:
					maxApplicableTickTime = Tick_Time*65536;
					TIMER1_OVF_setCallBack(TMU_callback);
					break;

				case TIMER2:
					maxApplicableTickTime = Tick_Time*256;
					TIMER2_OVF_setCallBack(TMU_callback);
					break;
				}

				break;

			case CTC_MODE:

				maxApplicableTickTime = Tick_Time*TIMER_cnfg_arr[timerIndx].OCR_ChA;

				switch(ConfigPtr->TIMER_ID)
				{
				case TIMER0:
					TIMER0_CMP_setCallBack(TMU_callback);
					break;

				case TIMER1:
					TIMER1_CMPA_setCallBack(TMU_callback);
					break;

				case TIMER2:
					TIMER2_CMP_setCallBack(TMU_callback);
					break;
				}

				break;
			}

			timerIndx = MAX_NUM_OF_TIMERS+1;
		}
	}
DDRC = 0xFF;
PORTC = maxApplicableTickTime;
	if(maxApplicableTickTime >= ConfigPtr->TMU_Res_us)
	{
		g_matchingTickCount = 1;
	}
	else
	{
		g_matchingTickCount = ConfigPtr->TMU_Res_us/maxApplicableTickTime;
	}

	TIMER_init();
	TIMER_start(TIMER0);
	/*	uint8 retval = OK;
	return retval;*/

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
uint8 TMU_DeInit(void)
{
	uint8 Status=OK;
	Status=TIMER_stop(TMU_init_cnfg_ptr->TIMER_ID);
	return Status;
}
