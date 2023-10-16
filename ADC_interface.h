/*
 * ADC_interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: Nadim
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
//channels have values like the values in datasheet respectively
typedef enum{
	ADC0_SINGLE=0,
	ADC1_SINGLE,
	ADC2_SINGLE,
	ADC3_SINGLE,
	ADC4_SINGLE,
	ADC5_SINGLE,
	ADC6_SINGLE,
	ADC7_SINGLE,
	ADC0_pos_ADC0_neg_10G,
	ADC1_pos_ADC0_neg_10G,
}ADC_CHANNEL_T;
void ADC_INIT(void);

uint8 ADC_SYNCstartConv(ADC_CHANNEL_T copyCHANNEL,uint16* RESULT);

uint8 ADC_ASYNCstartConv(ADC_CHANNEL_T copyCHANNEL,uint16* RESULT,void (*callBACKFN) (void));

#endif /* ADC_INTERFACE_H_ */
