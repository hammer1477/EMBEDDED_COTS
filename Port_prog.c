/*
 * Port_prog.c
 *
 *  Created on: Jun 20, 2023
 *      Author: Nadim
 */
#include "std_types.h"
#include "Port_cfg.h"
#include "Port_prv.h"
#include "Port_interface.h"
#include "Port_reg.h"

void PORT_init(void){
DDRA=PORTA_DIR;
DDRB=PORTB_DIR;
DDRC=PORTC_DIR;
DDRD=PORTD_DIR;

PORTA=PORTA_VAL;
PORTB=PORTB_VAL;
PORTC=PORTC_VAL;
PORTD=PORTD_VAL;
}

