/*
 * ADC_prv.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Nadim
 */

#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define	ENABLED
#define	DISABLED

#define	FROM_AREF			0u
#define	FROM_AVCC			1u
#define	INTERNAL_VOLTAGE	2u

#define	_8BIT			0u
#define	_10BIT			1u

#define	HIGHACC				1u
#define	LOWACC				0u
#define	MEDACC				2u

#define PRESCALERMASK		0b11111000

#define MUXMASK		0b11100000

#define DIVITION_2			1u
#define DIVITION_4			2u
#define DIVITION_8			3u
#define DIVITION_16			4u
#define DIVITION_32			5u
#define DIVITION_64			6u
#define DIVITION_128		7u

#endif /* ADC_PRV_H_ */
