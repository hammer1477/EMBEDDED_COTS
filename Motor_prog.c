/*
 * prog.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Nadim
 */
#include"std_types.h"
#include"BIT_MATH.h"
#include"Err_Type.h"
#include"DIO_interface.h"
#include"Motor_cfg.h"
#include"Motor_interface.h"


void MOTOR_CW(){
	DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_HIGH);
	DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_LOW);
}
void MOTOR_CCW(){
		DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_LOW);
		DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_HIGH);
}
void MOTOR_Kill(){

		DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_OUTPUT);
		DIO_u8SetPinDirection(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_OUTPUT);
		DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin1,DIO_PIN_HIGH);
		DIO_u8SetPinValue(Motor_ControlPort,Motor_ControlPin2,DIO_PIN_HIGH);
}
