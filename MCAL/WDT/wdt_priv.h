/*
 * wdt_priv.h
 *
 * Created: 01/03/2023 17:36:53
 *  Author: dell
 */ 


#ifndef WDT_PRIV_H_
#define WDT_PRIV_H_

#define MCUCSR	 (*(volatile u8 * )0x54)
#define WDTCR	 (*(volatile u8 * )0x41)

#define PERIOD1 1
#define PERIOD2 2
#define PERIOD3 3
#define PERIOD4 4
#define PERIOD5 5
#define PERIOD6 6
#define PERIOD7 7
#define PERIOD8 8


#endif /* WDT_PRIV_H_ */