/*
 * Counter.c
 *
 * Created: 11/03/2023 08:41:16
 * Author : dell
 */ 

#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "lcd.h"
#include "lcd_config.h"
#include "TIMR0_config.h"
#include "TIMR00_priv.h"
#include "TIMR0_int.h"


int main(void)
{
    lcd_init();
    lcd_sendCmd(CLEAR_COMMAND);
	dio_vidConfigChannel(DIO_PORTB, 0,INPUT);
    TIMER0_void_Init();
    TIMER0_void_EnableOVInt();
    u8 val=0;
    while (1)
    {
	    val= TIMER0_GetTimerReg();
	    LCDConvertINTtoSTR((u16)val);
	    
    }
}

