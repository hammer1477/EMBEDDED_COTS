/*
 * Timer_prog.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Nadim
 */
#include "std_types.h"
#include "ERR_Type.h"
#include "BIT_MATH.h"
#include "Timer_prv.h"
#include "Timer_cfg.h"
#include "Timer_interface.h"
#include "Timer_Reg.h"

static uint8 TimerStatus;
static void(*CallBackFn)(void) = NULL;
uint8 LocalErrorState=OK;
void Timer0INIT(void){

#if(Timer0WaveFormGeneration ==NormalMode)

	CLR_BIT(TCCR0,WFGM00);
	CLR_BIT(TCCR0,WFGM01);
	TimerStatus=OverFlowMode;
#elif(Timer0WaveFormGeneration ==CTCMode)

	CLR_BIT(TCCR0,WFGM00);
	SET_BIT(TCCR0,WFGM01);
	TimerStatus=CompareMode;
	OCR0=OutputCompareValue;

#elif(Timer0WaveFormGeneration ==PWM)

	CLR_BIT(TCCR0,WFGM01);
	SET_BIT(TCCR0,WFGM00);
	TimerStatus=OverFlowMode;
#elif(Timer0WaveFormGeneration ==FPWM)

	SET_BIT(TCCR0,WFGM01);
	SET_BIT(TCCR0,WFGM00);
	TimerStatus=OverFlowMode;
#error
	LocalErrorState=NOK;
#endif


#if(CompareOutputMode == OC0Disconnected)

	CLR_BIT(TCCR0,COMPARE00);
	CLR_BIT(TCCR0,COMPARE01);

#elif(CompareOutputMode == ReservedOrToggle)

	CLR_BIT(TCCR0,COMPARE01);
	SET_BIT(TCCR0,COMPARE00);

#elif(CompareOutputMode == ClearOc0)

	CLR_BIT(TCCR0,COMPARE00);
	SET_BIT(TCCR0,COMPARE01);

#elif(CompareOutputMode == SetOc0)

	SET_BIT(TCCR0,COMPARE00);
	SET_BIT(TCCR0,COMPARE01);

#error
	LocalErrorState=NOK;
#endif

	TCCR0 &= PrescalerMask;
	TCCR0 |= PrescalerTimeSource;

if(TimerStatus==CompareMode)
{
	SET_BIT(TIMSK,CMP_INTENABLE);
}
else if(TimerStatus==OverFlowMode)
{
	SET_BIT(TIMSK,OVFLOW_INTENABLE);
}
}


uint8 Timer0Callbackfn(void (*callBackfn)(void)){

if(callBackfn!=NULL){
	CallBackFn=callBackfn;
}
else
{
	LocalErrorState =NULL_PTR;
}
return 0;
}

void __vector_10(void)   __attribute((signal));
void __vector_10(void)
{
	if(CallBackFn != NULL){
		CallBackFn();
	}
	else
	{
		LocalErrorState =NULL_PTR;
	}

}

void __vector_9(void)   __attribute((signal));
void __vector_9(void){
	if(CallBackFn != NULL)
	{
		CallBackFn();
	}
	else
	{
		LocalErrorState=NULL_PTR;
	}
}
