/*
 * CLCD_prv.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Nadim
 */

#ifndef CLCD_PRV_H_
#define CLCD_PRV_H_

#define FOUR_BIT					1u
#define EIGHT_BIT					2u

#define ENABLED						1u
#define DISABLED					0u

#if CLCD_u8CONNECTION_MODE == FOUR_BIT
static  void voidSetHalfDataPort(copy_u8FourBitData);
#endif

static SendEnablePulse();
#endif /* CLCD_PRV_H_ */
