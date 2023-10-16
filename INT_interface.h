/*
 * INT_interface.h
 *
 *  Created on: Aug 3, 2023
 *      Author: Nadim
 */

#ifndef INT_INTERFACE_H_
#define INT_INTERFACE_H_

void EXTI_ENABLEINT(uint8 INT_copy);

void EXTI_DISABLEINT(uint8 INT_copy);

void EXTI_Trigger(uint8 INT_copy,uint8 Trigger_copy);

void EXTI_INIT(void);

#endif /* INT_INTERFACE_H_ */
