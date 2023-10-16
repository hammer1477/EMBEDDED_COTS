/*
 * CLCD_cfg.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Nadim
 */

#ifndef CLCD_CFG_H_
#define CLCD_CFG_H_

#define CLCD_u8CONNECTION_MODE				FOUR_BIT
#define CLCD_u8READ_OPERATION_ENABLE		DISABLED
#define CLCD_u8DATA_PORT					DIO_PORTA
#if 	CLCD_u8CONNECTION_MODE	== 			FOUR_BIT

#define	CLCD_u8D4_PIN						DIO_PIN3
#define	CLCD_u8D5_PIN						DIO_PIN4
#define	CLCD_u8D6_PIN						DIO_PIN5
#define	CLCD_u8D7_PIN						DIO_PIN6

#endif
#define CLCD_u8CTRL_PORT			DIO_PORTA
#define CLCD_u8RS_PIN				DIO_PIN1

#if CLCD_u8READ_OPERATION_ENABLE == ENABLED

#define CLCD_u8RW_PIN				DIO_PIN0

#endif
#define CLCD_u8E_PIN				DIO_PIN2



#endif /* CLCD_CFG_H_ */
