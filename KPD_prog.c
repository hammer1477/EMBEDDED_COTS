/*
 * KPD_prog.c
 *
 *  Created on: Jun 19, 2023
 *      Author: Nadim
 */
#include"std_types.h"
#include"BIT_MATH.h"
#include"Err_Type.h"
#include"DIO_interface.h"
#include"KPD_interface.h"
#include"KPD_cfg.h"
#include"KPD_prv.h"

uint8 KPD_GetPressedKey(void)
{
	uint8 RowCounter=0,CoulmnCounter=0,keyvalue,PressedKey=KPD_NoPressedKey;
	static uint8 colArr[Colnum]={KPD_u8C0_PIN,KPD_u8C1_PIN,KPD_u8C2_PIN,KPD_u8C3_PIN};
	static uint8 RowArr[Rownum]={KPD_u8R0_PIN,KPD_u8R1_PIN,KPD_u8R2_PIN,KPD_u8R3_PIN};
	static uint8 KPDArr[Rownum][Colnum]= KPD_buttonsArr;
	for(CoulmnCounter=0u;CoulmnCounter<Colnum;CoulmnCounter++)
	{
		DIO_u8SetPinValue(KPD_u8COL_Port,colArr[CoulmnCounter],DIO_PIN_LOW);

		for(RowCounter=0u;RowCounter<Rownum;RowCounter++){
		DIO_u8GetPinValue(KPD_u8ROW_Port,RowArr[RowCounter],&keyvalue);
		if(keyvalue==DIO_PIN_LOW)
		{
			while(keyvalue==DIO_PIN_LOW){

				DIO_u8GetPinValue(KPD_u8ROW_Port,RowArr[RowCounter],&keyvalue);
			}
			PressedKey = KPDArr[RowCounter,CoulmnCounter];
			return PressedKey;
		}
	}
		DIO_u8SetPinValue(KPD_u8COL_Port,colArr[CoulmnCounter],DIO_PIN_HIGH);
	}

	return PressedKey;
}
