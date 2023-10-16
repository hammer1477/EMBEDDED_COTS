/*
 * KPD_cfg.h
 *
 *  Created on: Jun 19, 2023
 *      Author: Nadim
 */

#ifndef KPD_CFG_H
#define KPD_CFG_H


#define KPD_u8ROW_Port		DIO_PORTB
#define KPD_u8R0_PIN		DIO_PIN4
#define KPD_u8R1_PIN		DIO_PIN5
#define KPD_u8R2_PIN		DIO_PIN6
#define KPD_u8R3_PIN		DIO_PIN7

#define KPD_u8COL_Port		DIO_PORTD
#define KPD_u8C0_PIN		DIO_PIN2
#define KPD_u8C1_PIN		DIO_PIN3
#define KPD_u8C2_PIN		DIO_PIN4
#define KPD_u8C3_PIN		DIO_PIN5

#define KPD_buttonsArr		{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define KPD_NoPressedKey    0xff
#endif /* KPD_CFG_H_ */
