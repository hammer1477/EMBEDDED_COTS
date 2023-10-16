#include "std_types.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "INT_reg.h"
#include "INT_interface.h"
#include "INT_cfg.h"
#include "INT_prv.h"

void EXTI_ENABLEINT(uint8 INT_copy){
	SET_BIT(GICR,INT_copy);
}

void EXTI_DISABLEINT(uint8 INT_copy){
	CLR_BIT(GICR,INT_copy);
}

void EXTI_Trigger(uint8 INT_copy,uint8 Trigger_copy){
#if(INT_copy == Int0)
	{
		switch(Trigger_copy){
			case FALLING_EDGE 		: CLR_BIT(MCUCR,INTCB00);  SET_BIT(MCUCR,INTCB01); break;
			case RISING_EDGE 		: SET_BIT(MCUCR,INTCB00);  SET_BIT(MCUCR,INTCB01); break;
			case ON_CHANGE 			: SET_BIT(MCUCR,INTCB00);  CLR_BIT(MCUCR,INTCB01); break;
			case LOW 				: CLR_BIT(MCUCR,INTCB00);  CLR_BIT(MCUCR,INTCB01); break;
		}
	}
	#elif(INT_copy == Int1)
			{
		switch(Trigger_copy){
				case FALLING_EDGE 	: CLR_BIT(MCUCR,INTCB10);  SET_BIT(MCUCR,INTCB11); break;
				case RISING_EDGE 	: SET_BIT(MCUCR,INTCB10);  SET_BIT(MCUCR,INTCB11); break;
				case ON_CHANGE 		: SET_BIT(MCUCR,INTCB10);  CLR_BIT(MCUCR,INTCB11); break;
				case LOW			: CLR_BIT(MCUCR,INTCB10);  CLR_BIT(MCUCR,INTCB11); break;
			}

			}
	#elif(INT_copy == Int2)
				{
		switch(Trigger_copy){
						case FALLING_EDGE	:	CLR_BIT(MCUCSR,Int2CB);  break;
						case RISING_EDGE 	:	SET_BIT(MCUCSR,Int2CB);  break;
					}
				}


	#endif
}

void EXTI_INIT(void){

#if(EXTI_INT0_INITVALUE==ENABLED)
	EXTI_ENABLEINT(Int0);
	EXTI_Trigger(Int0,EXTI_INT0_Trigger);
 #elif(EXTI_INT0_INITVALUE==DISABLED)

 EXTI_DISABLEINT(Int0);

#endif

#if(EXTI_INT1_INITVALUE==ENABLED)
	EXTI_ENABLEINT(Int1);
	EXTI_Trigger(Int1,EXTI_INT1_Trigger);
#elif(EXTI_INT1_INITVALUE==DISABLED)
	EXTI_DISABLEINT(Int1);

#endif


#if(EXTI_INT2_INITVALUE==ENABLED)

	EXTI_ENABLEINT(Int2);
	EXTI_Trigger(Int2,EXTI_INT2_Trigger);

#elif(EXTI_INT2_INITVALUE==DISABLED)

	EXTI_DISABLEINT(Int2);

#endif

}
