/*
 * TMU_Pbconfg.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */

#ifndef TMU_PBCONFG_H_
#define TMU_PBCONFG_H_

#include "STD_Types.h"

#define PERIODIC 1
#define ONE_SHOT 0

#define TMU_TIMER TIMER0
#ifndef TIMER1
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2
#endif
/****************NUM of Consumer**************/
#define NUM_OF_CONSUMER 3


typedef struct
{
	uint8 TIMER_ID;
	uint16 TMU_Res_us;
}TMU_ConfigType;


typedef struct
{
	uint8 TIME_Delay;
	uint8 * EVENT_Consumer;
	uint8 Periodicity;
}TMU_SConfg;

extern TMU_ConfigType *TMU_init_cnfg_ptr;
extern TMU_SConfg TMU_cnfg_arr [NUM_OF_CONSUMER];

#endif /* TMU_PBCONFG_H_ */
