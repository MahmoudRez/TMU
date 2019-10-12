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

}EnmTMUError_t;



EnmTMUError_t TMU_init(const TMU_ConfigType * ConfigPtr);
uint8 TMU_Start_Timer(uint8 TIME_Delay,uint8 * EVENT_Consumer,uint8 Periodicity);
uint8 TMU_Stop_Timer(uint8 * EVENT_Consumer);
uint8 TMU_Dispatch(void);

#endif /* TMU_H_ */
