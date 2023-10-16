/*
 * ADC_reg.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Nadim
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

#define	ADMUX		*((volatile uint8*)0x27)
#define	REFSVOLTB0		6u
#define	REFSVOLTB1		7u
#define	ADLAR			5u
#define	MUX0			0u
#define	MUX1			1u
#define	MUX2			2u
#define	MUX3			3u
#define	MUX4			4u

#define	ADCSRA		*((volatile uint8*)0x26)
#define ADCENABLE		7u
#define ADCSTARTCONV	6u
#define ADCAUTOTRIG		5u
#define ADCINTFLAG		4u
#define ADCINTENABLE	3u

#define	ADCH		*((volatile uint8*)0x25)
#define	ADCL		*((volatile uint8*)0x24)
#define	ADC			*((volatile uint16*)0x24)

#endif /* ADC_REG_H_ */
