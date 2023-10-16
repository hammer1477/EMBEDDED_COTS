/*
 * INT_reg.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Nadim
 */

#ifndef INT_REG_H_
#define INT_REG_H_

#define SREG 	*((volatile uint8*)0x5F)
#define GEnablebit	7U

#define MCUCR	*((volatile uint8*)0x55)

#define INTCB00		0U
#define INTCB01		1U
#define INTCB10		2U
#define INTCB11		3U


#define GICR	*((volatile uint8*)0x5B)

#define Int2		5U
#define Int0		6U
#define Int1		7U

#define GIFR	*((volatile uint8*)0x5A)

#define MCUCSR	*((volatile uint8 *)0X54)
#define Int2CB  	6U

#endif /* INT_REG_H_ */
