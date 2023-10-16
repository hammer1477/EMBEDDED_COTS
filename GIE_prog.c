#include "std_types.h"
#include "BIT_MATH.h"
#include "Err_Type.h"
#include "GIE_prv.h"
#include "GIE_reg.h"
#include "GIE_interface.h"
#include "GIE_cfg.h"

void EXTI_ENABLEGLOBALINT(){
	SET_BIT(SREG,GEnablebit);
}

void EXTI_DISABLEGLOBALINT(){
	CLR_BIT(SREG,GEnablebit);
}
