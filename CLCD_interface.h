/*
 * CLCD_interface.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Nadim
 */
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(uint8 copy_u8Command);
void CLCD_voidSendData(uint8 copy_u8Data);
void CLCD_INIT(void);
void CLCD_voidSendnum(uint8 copy_u8Num);
void CLCD_voidSendStringData(uint32 *copy_u32string);
void CLCD_voidGoToXY(uint8 copy_u8Xpos,uint8 copy_u8Ypos);
void CLCD_SetCGRAMAddress(uint8 copy_Patternnum, uint8 copy_Pattern[],uint8 copy_Xpos,uint8 copy_Ypos);
#endif /* CLCD_INTERFACE_H_ */
