/*
 * TMU_Pbconfg.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */
#include "TMU_Pbconfg.h"

TMU_ConfigType TMU_init_cnfg = {TIMER0,200};
TMU_ConfigType *TMU_init_cnfg_ptr = &TMU_init_cnfg;

TMU_SConfg TMU_cnfg_arr [NUM_OF_CONSUMER] =
{
/*	{3,TOOGLE_led,PERIODIC},
	{5,TOOGLE_led,ONE_SHOT},
	{10,TOOGLE_led,PERIODIC}*/
};

