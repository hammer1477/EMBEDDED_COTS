/*
 * Timer_interface.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Nadim
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

typedef enum{
	NOClockSource=0,
	NOPrescaler,
	FromPrescaler8,
	FromPrescaler64,
	FromPrescaler256,
	FromPrescaler1024,
	EXTCLOCKFALLINGEDGE,
	EXTCLOCKRISINGEDGE,
}Timer_Prescaler_CTR;
void Timer0INIT(void);

uint8 Timer0Callbackfn(void (*callBackfn)(void));

#endif /* TIMER_INTERFACE_H_ */
