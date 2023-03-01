/*
 * GIE.c
 *
 * Created: 25/02/2023 15:34:46
 *  Author: dell
 */ 
#include "Bit_Math.h"
#include "Std_Types.h"
#include "GIE.h"

void GIE_disable(void){
	CLEAR_BIT(SREG,7);
}
void GIE_enable(void){
	SET_BIT(SREG,7);
}