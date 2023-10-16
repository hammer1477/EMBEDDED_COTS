/*
 * Timer_Reg.h
 *
 *  Created on: Oct 13, 2023
 *      Author: Nadim
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#define OCR0 *((volatile uint8*)0x5C)
#define OCR1A *((volatile uint16*)0x4A)

#define TCNT0 *((volatile uint8*)0x52)
#define TCNT1 *((volatile uint16*)0x4c)


#define TIMSK *((volatile uint8*)0x59)

#define OVFLOW_INTENABLE 0
#define CMP_INTENABLE 1


#define TCCR0 *((volatile uint8*)0x53)

#define WFGM00 6
#define WFGM01 3
#define COMPARE00 4
#define COMPARE01 5

#define TIFR *((volatile uint8*)0x53)

#define TCCR1A *((volatile uint8*)0x4F)
#define WFGM11 1
#define WFGM10 0
#define COMPARECHB1 6
#define COMPARECHB0 7

#define TCCR1B *((volatile uint8*)0x4E)
#define prescalerbit0	0
#define prescalerbit1	1
#define prescalerbit2	2
#define WFGM12 4
#define WFGM13 3

#define ICR1 *((volatile uint8*)0x46)

#endif /* TIMER_REG_H_ */
