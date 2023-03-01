/*
 * wdt.c
 *
 * Created: 01/03/2023 17:36:17
 *  Author: dell
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "wdt_config.h"
#include "wdt_int.h"
#include "wdt_priv.h"

void WDT_init(void){
	#if period == PERIOD1
	   CLEAR_BIT(WDTCR,0);
	   CLEAR_BIT(WDTCR,1);
	   CLEAR_BIT(WDTCR,2);
	   
	#elif period == PERIOD2
	SET_BIT(WDTCR,0);
	CLEAR_BIT(WDTCR,1);
	CLEAR_BIT(WDTCR,2);
	#elif period == PERIOD3
	CLEAR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLEAR_BIT(WDTCR,2);
	#elif period == PERIOD4
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	CLEAR_BIT(WDTCR,2);
	#elif period == PERIOD5
	CLEAR_BIT(WDTCR,0);
	CLEAR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	#elif period == PERIOD6
	SET_BIT(WDTCR,0);
	CLEAR_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	#elif period == PERIOD7
	CLEAR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	#elif period == PERIOD8
	SET_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	#endif
}

void WDT_Enable(void){
	SET_BIT(WDTCR,3);
}

void WDT_Disable(void){
	SET_BIT(WDTCR,3);
	SET_BIT(WDTCR,4);
	WDTCR=0x00;
}

