/*
 * CLCD_prog.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Nadim
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERR_Type.h"
#include <util/delay.h>
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_prv.h"
#include "CLCD_cfg.h"

#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static voidSetHalfDataPort(copy_u8FourBitData){
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D4_PIN,GET_BIT(copy_u8FourBitData,0));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D5_PIN,GET_BIT(copy_u8FourBitData,1));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D6_PIN,GET_BIT(copy_u8FourBitData,2));
	DIO_u8SetPinValue(CLCD_u8DATA_PORT,CLCD_u8D7_PIN,GET_BIT(copy_u8FourBitData,3));
}
#endif
static SendEnablePulse(){
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8E_PIN,DIO_PIN_LOW);
}
void CLCD_voidSendCommand(uint8 copy_u8Command){
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_LOW);

#if CLCD_u8READ_OPERATION_ENABLE == ENABLED

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_HIGH);

#endif



#if 	CLCD_u8CONNECTION_MODE	== 			EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Command);

	SendEnablePulse();


#elif CLCD_u8CONNECTION_MODE	== 			FOUR_BIT

	voidSetHalfDataPort(copy_u8Command >> 4u);
	SendEnablePulse();//lower bits
	voidSetHalfDataPort(copy_u8Command);
	SendEnablePulse();
#endif
}
void CLCD_voidSendData(uint8 copy_u8Data){
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RS_PIN,DIO_PIN_HIGH);

#if CLCD_u8READ_OPERATION_ENABLE == ENABLED

	DIO_u8SetPinValue(CLCD_u8CTRL_PORT,CLCD_u8RW_PIN,DIO_PIN_HIGH);

#endif

#if 	CLCD_u8CONNECTION_MODE	== 			EIGHT_BIT

	DIO_u8SetPortValue(CLCD_u8DATA_PORT,copy_u8Data);

	SendEnablePulse();


#elif	CLCD_u8CONNECTION_MODE	== 			FOUR_BIT
	voidSetHalfDataPort(copy_u8Data >> 4u);
	SendEnablePulse();
	voidSetHalfDataPort(copy_u8Data);
	SendEnablePulse();
#endif
}

void CLCD_voidSendStringData(uint32 *copy_u32string){
	uint8 i=0;
	for(i=0;*(copy_u32string+i)!='\0';i++){
		CLCD_voidSendData(*(copy_u32string+i));
	}

}

void CLCD_voidSendnum(uint8 copy_u8Num){
	uint8 digit=0;
	while(copy_u8Num != 0){
		digit=copy_u8Num%10;
		CLCD_voidSendData(digit);
		copy_u8Num=copy_u8Num/10;
	}
}

void CLCD_INIT(void){
#if 	CLCD_u8CONNECTION_MODE	== 			EIGHT_BIT
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);

#elif 	CLCD_u8CONNECTION_MODE	== 			FOUR_BIT
	_delay_ms(40);
	voidSetHalfDataPort(0b0010);
	SendEnablePulse();
	voidSetHalfDataPort(0b0010);
	SendEnablePulse();
	voidSetHalfDataPort(0b1000);
	SendEnablePulse();

#endif
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(1);
}
void CLCD_voidGoToXY(uint8 copy_u8Xpos,uint8 copy_u8Ypos){
	uint8 DDRAMaddress;
	if(copy_u8Ypos == 0u){
		DDRAMaddress=copy_u8Xpos;
	}
	else{
		DDRAMaddress=0x40+copy_u8Xpos;
	}
	SET_BIT(DDRAMaddress,7);
	CLCD_voidSendCommand(DDRAMaddress);
}

void CLCD_SetCGRAMAddress(uint8 copy_Patternnum, uint8 copy_Pattern[],uint8 copy_Xpos,uint8 copy_Ypos){

	uint8 LocalErrorState=OK;

	uint8 i = 0;

	if(copy_Pattern!=NULL)
	{
		uint8 CGRAMaddress;

		CGRAMaddress=copy_Patternnum * 8u;

		SET_BIT(CGRAMaddress,6u);

		CLR_BIT(CGRAMaddress,7u);

		CLCD_voidSendCommand(CGRAMaddress);

		for(i = 0u ; i < 8u ; i++){

			CLCD_voidSendData(copy_Pattern[i]);

		}
		CLCD_voidGoToXY(copy_Xpos,copy_Ypos);

		CLCD_voidSendData(copy_Patternnum);
	}
	else
	{
		uint8 LocalErrorState=NULL_PTR;
	}

}
