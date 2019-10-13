/*
 * TMU.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Mahmoud Rezk Mahmoud
 */

#ifndef TMU_H_
#define TMU_H_

#include "TMU_Pbconfg.h"
#include "TIMER.h"
#include "LED.h"


typedef enum
{
	hamada
}EnmTMUError_t;



EnmTMUError_t TMU_init(const TMU_ConfigType * ConfigPtr);
uint8 TMU_Start_Timer(uint16 TIME_Delay,void (* EVENT_Consumer)(void),uint8 Periodicity);
uint8 TMU_Stop_Timer(void (*EVENT_Consumer)(void));
uint8 TMU_Dispatch(void);
uint8 TMU_DeInit(void);

#endif /* TMU_H_ */
