/*
 * TMU_APP.c
 *
 *  Created on: Oct 12, 2019
 *      Author: alx
 */

#include "TMU.h"

void main(void)
{
	DDRA = 0xFF;

	TMU_init(TMU_init_cnfg_ptr);


	while(1)
	{

	}
}
