/*
 * ADC_prog.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Nadim
 */
#include "std_types.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "ADC_interface.h"
#include "ADC_cfg.h"
#include "ADC_reg.h"
#include "ADC_PRV.h"

static uint16* ADCRESULT=NULL;
static void (*ADCCALLBACKFn)(void)=NULL;

void ADC_INIT(void){
#if REFRENCEVOLT ==	FROM_AVCC
	SET_BIT(ADMUX,REFSVOLTB0);
	CLR_BIT(ADMUX,REFSVOLTB1);
#elif REFRENCEVOLT == FROM_AREF
	CLR_BIT(ADMUX,REFSVOLTB0);
	CLR_BIT(ADMUX,REFSVOLTB1);
#elif REFRENCEVOLT == INTERNAL_VOLTAGE
	SET_BIT(ADMUX,REFSVOLTB0);
	SET_BIT(ADMUX,REFSVOLTB1);
#endif

#if ADJUSTDIRECTION == _8BIT
	SET_BIT(ADMUX,ADLAR);
#elif	ADJUSTDIRECTION == _10BIT
	CLR_BIT(ADMUX,ADLAR);
#endif
	ADCSRA  &=	PRESCALERMASK;
	ADCSRA	|=	PRESCALERDIVIDENT;

	SET_BIT(ADCSRA,ADCENABLE);
}

uint8 ADC_SYNCstartConv(ADC_CHANNEL_T copyCHANNEL,uint16* RESULT){

	uint8 LocalERRORSTATE = OK;
	uint32 counter=0u;
	uint32 TIMEOUTMAX=TIMEOUTCOUNT;
	if(RESULT!=NULL){
		ADMUX	&=	MUXMASK;
		ADMUX	|=	copyCHANNEL;
		SET_BIT(ADCSRA,ADCSTARTCONV);
		while(GET_BIT(ADCSRA,ADCINTFLAG)==0 && counter<TIMEOUTMAX){
			counter++;
		}
		if(counter!=TIMEOUTMAX){
			SET_BIT(ADCSRA,ADCINTFLAG);
			if(ADJUSTDIRECTION == _8BIT){
				RESULT=(uint16)ADCH;
				return LocalERRORSTATE;
			}
			else if(ADJUSTDIRECTION == _10BIT){
				RESULT=ADC;
				return LocalERRORSTATE;
			}
		}
		else{
			LocalERRORSTATE=TIMEOUTERROR;
			return LocalERRORSTATE;
		}
	}
	else{
		LocalERRORSTATE=NULL_PTR;
		return LocalERRORSTATE;
	}
}
uint8 ADC_ASYNCstartConv(ADC_CHANNEL_T copyCHANNEL,uint16* RESULT, void (*callBACKFN) (void)){
	uint8 LocalERRORSTATE = OK;
	if(RESULT!=NULL && (callBACKFN !=NULL)){
		ADCRESULT=RESULT;
		ADCCALLBACKFn = callBACKFN;

		ADCSRA	&=	MUXMASK;
		ADCSRA	|=	copyCHANNEL;
		SET_BIT(ADCSRA,ADCSTARTCONV);
		SET_BIT(ADCSRA,ADCINTENABLE);

	}
	else{
		LocalERRORSTATE=NULL_PTR;
		return LocalERRORSTATE;
	}
	return LocalERRORSTATE;
}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
#if(ADJUSTDIRECTION == _8BIT)
	{
		*ADCRESULT=(uint16)ADCH;

	}

#elif(ADJUSTDIRECTION == _10BIT)
	*ADCRESULT=ADC;

#endif
	CLR_BIT(ADCSRA,ADCINTENABLE);
	if(ADCCALLBACKFn!=NULL)
	{
		ADCCALLBACKFn();

	}
	else
	{

	}
}
