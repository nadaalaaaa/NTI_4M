/*
 * TIMR1_init.h
 *
 * Created: 01/03/2023 16:01:11
 *  Author: dell
 */ 


#ifndef TIMR1_INIT_H_
#define TIMR1_INIT_H_

void TIMER1_void_Init(void);

u16 TIMER1_GetTimerReg(void);
u16 TIMER1_GetTimerRegICR(void);

void TIMER1_void_SetTimerReg(u16 Copy_uint8Val);


void TIMER1_void_SetCompareValA(u16 Copy_uint8Val);
void TIMER1_void_SetCompareValB(u16 Copy_uint8Val);


void TIMER1_void_EnableOVInt(void);

void TIMER1_void_DisableOVInt(void);

void TIMER1_void_EnableCTCAInt(void);

void TIMER1_void_DisableCTCAInt(void);

void TIMER1_void_EnableCTCBInt(void);

void TIMER1_void_DisableCTCBInt(void);

void TIMER1_void_EnableCAPTInt(void);

void TIMER1_void_DisableCAPTInt(void);

void TIMER1_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCACallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCTCBCallBack(void (*Copy_ptr) (void) ) ;

void TIMER1_void_SetCAPTCallBack(void (*Copy_ptr) (void) ) ;



#endif /* TIMR1_INIT_H_ */