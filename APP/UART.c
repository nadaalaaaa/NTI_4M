/*
 * UART.c
 *
 * Created: 03/03/2023 09:36:35
 * Author : dell
 */ 

#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "uart_reg.h"
#include "uart.h"
#include "GIE.h"
#include "lcd.h"
#include "lcd_config.h"


u8 val='A';
u8 arr[10]="NADA";
u8 a[200];
void func(u8 vallue){
	val=vallue;
}
u8 func1(void){
	return val;
}


int main(void)
{/*UARTTXC_voidCallBack(func1);
	UART_TXCEnable();
	UART_Init(0x33);
	lcd_init();
	GIE_enable();*/
	
	/*// transmit char by interrupt
	UARTEMPTY_voidCallBack(func1);
	UART_EMPTYEnable();
	UART_Init(0x33);
	lcd_init();
	GIE_enable();*/
	
	/* //RECEIVE CHAR BY INT
	UART_voidCallBack(func);
	UART_RXCEnable();
	UART_Init(0x33);
	lcd_init();
	GIE_enable();*/
	
	/* //transmit string by interrupt
	UART_TXCEnable();
	UART_Init(0x33);
	GIE_enable();
	UART_TransmitStrINT(arr);
	*/
	u8 ch=-1;
	UART_Init(0x33);
	UART_RXCEnable();
	lcd_init();
	GIE_enable();
    while (1) 
    {/*u8 x=UART_ReceiveChr(); /////////////receive code
		UART_TransmitChr(x); /////////////receive code*/
	
	//UART_TransmitChr('A');  /////////////transmit code
	
	//UART_TransmitStr("NADA"); ///////////transmit string
	/*
	u8 arr[10]={0};
	UART_ReceiveStr(arr); ////////////receive string
    UART_TransmitStr(arr);*/
	
	/*// receive char by interrupt
	lcd_sendCmd(CLEAR_COMMAND);
	lcd_displyChar(val);
	_delay_ms(100);*/
	
	/////receive string by interrupt
	/*ch=Check_Rec_String(); ///////check you end the string
	if(Check_Rec_String()==1){
		Receive_str_int(a); //////////save string to a string
		//lcd_sendCmd(CLEAR_COMMAND);
		lcd_displyStr(a); ////////display it
		_delay_ms(500);
	}*/
	
    }
}

