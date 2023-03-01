/*
 * TIMR1_priv.h
 *
 * Created: 01/03/2023 16:01:30
 *  Author: dell
 */ 


#ifndef TIMR1_PRIV_H_
#define TIMR1_PRIV_H_

#define TIMSK	 (*(volatile u8 * )0x59)
#define TIFR	 (*(volatile u8 * )0x58)
#define SFIOR	 (*(volatile u8 * )0x50)
#define TCCR1A	 (*(volatile u8 * )0x4F)
#define TCCR1B	 (*(volatile u8 * )0x4E)
#define TCNT1H	 (*(volatile u8 * )0x4D)
#define TCNT1L	 (*(volatile u8 * )0x4C)
#define OCR1AH	 (*(volatile u8 * )0x4B)
#define OCR1AL	 (*(volatile u8 * )0x4A)
#define OCR1BH	 (*(volatile u8 * )0x49)
#define OCR1BL	 (*(volatile u8 * )0x48)
#define ICR1H	 (*(volatile u8 * )0x47)
#define ICR1L	 (*(volatile u8 * )0x46)

#define TIMER1_NORMAL 0
#define TIMER1_PWM_8 1
#define TIMER1_PWM_9 2
#define TIMER1_PWM_10 3
#define TIMER1_CTC 4
#define TIMER1_FPWM_8 5
#define TIMER1_FPWM_9 6
#define TIMER1_FPWM_10 7
#define TIMER1_PWM_PF_ICR 8
#define TIMER1_PWM_PF_OCR 9
#define TIMER1_PWM_P_ICR 10
#define TIMER1_PWM_P_OCR 11
#define TIMER1_CTC_ICR 12
#define TIMER1_FPWM_ICR 14
#define TIMER1_FPWM_OCR 15

#define TIMER1_DIV_BY_1			1
#define TIMER1_DIV_BY_8			5
#define TIMER1_DIV_BY_64		8
#define TIMER1_DIV_BY_256		10
#define TIMER1_DIV_BY_1024		15
#define EXT_T1_FALLING_EDGE	    20  //for counter
#define EXT_T1_RISING_EDGE      25

#define TIMER1_COM1A__NORMAL 0
#define TIMER1_COM1A__TOGGLE 1
#define TIMER1_COM1A__CLEAR 2
#define TIMER1_COM1A__SET 3

#define TIMER1_COM1B__NORMAL 0
#define TIMER1_COM1B__TOGGLE 1
#define TIMER1_COM1B__CLEAR 2
#define TIMER1_COM1B__SET 3





#endif /* TIMR1_PRIV_H_ */