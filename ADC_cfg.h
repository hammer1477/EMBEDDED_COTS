/*
 * ADC_cfg.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Nadim
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

#define REFRENCEVOLT		FROM_AVCC		//The Input voltage of ADC	1-FROM_AVCC	2-FROM_AREF 3-INTERNAL_VOLTAGE

#define ADJUSTDIRECTION		_8BIT		//EITHER _8bit	or	_10bit

#define PRESCALERDIVIDENT	DIVITION_128	//2/4/8/16/32/64/128

#define TIMEOUTCOUNT	5000UL
// #define AUTOTRIGGER			ENABLED

#endif /* ADC_CFG_H_ */
