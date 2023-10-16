/*
 * Timer_prv.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Nadim
 */

#ifndef TIMER_PRV_H_
#define TIMER_PRV_H_

#define NormalMode	0u
#define PWM			1u
#define CTCMode		2u
#define FPWM		3u

#define OC0Disconnected				0u
#define ReservedOrToggle			1u
#define ClearOc0					2u
#define SetOc0						3u

#define PrescalerMask				0b11111000

#define CompareMode				0u
#define OverFlowMode			1u
#endif /* TIMER_PRV_H_ */
