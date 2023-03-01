/*
 * sevensegment.c
 *
 * Created: 22/02/2023 14:54:51
 *  Author: dell
 */ 
#define F_CPU 16000000
#include <avr/delay.h>
#include "dio.h"
#include "dio_types.h"
#include "dio_reg.h"
#include "sevensegment.h"
#include "sevensegment_config.h"


void SSD_vidInit(void)
{dio_vidConfigChannel(sevenseg_port1, PB0,OUTPUT);
dio_vidConfigChannel(sevenseg_port2, PB1,OUTPUT);
dio_vidConfigChannel(sevenseg_port3, PB2,OUTPUT);
dio_vidConfigChannel(sevenseg_port4, PB4,OUTPUT);
dio_vidConfigChannel(sevenseg_port5, PB5,OUTPUT);
dio_vidConfigChannel(sevenseg_port6, PB6,OUTPUT);
dio_vidConfigChannel(sevenseg_port7, PA2,OUTPUT);
dio_vidConfigChannel(sevenseg_port8, PA3,OUTPUT);
}
void SSD_DisplayNum(u16 num)
{u16 fdigit=0,sdigit=0,tdigit=0,ftdigit=0;
	
		fdigit=num/1000;
		sdigit=(num/100)%10;
		tdigit=(num/10)%10;
		ftdigit=num%10;
	/*
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_HIGH);
	//dio_vidWriteChannelGroup(sevenseg_port1,fdigit,0b00010111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, (ftdigit&1));
	dio_vidWriteChannel(sevenseg_port1, PB1, (ftdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (ftdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4, (ftdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	_delay_ms(100);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_HIGH);
	//dio_vidWriteChannelGroup(sevenseg_port1,sdigit,0b00001111,0);
	 dio_vidWriteChannel(sevenseg_port1, PB0, tdigit&1);
	  dio_vidWriteChannel(sevenseg_port1, PB1, (tdigit>>1)&1);
	   dio_vidWriteChannel(sevenseg_port1, PB2, (tdigit>>2)&1);
	    dio_vidWriteChannel(sevenseg_port1, PB4, (tdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	_delay_ms(100);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_HIGH);
	//dio_vidWriteChannelGroup(sevenseg_port1,tdigit,0b00001111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, sdigit&1);
	dio_vidWriteChannel(sevenseg_port1, PB1, (sdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (sdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4,( sdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	_delay_ms(100);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_HIGH);
	//dio_vidWriteChannelGroup(sevenseg_port1,ftdigit,0b00001111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, fdigit&1);
	dio_vidWriteChannel(sevenseg_port1, PB1, (fdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (fdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4, (fdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	_delay_ms(100);
	*/
	
	
	
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	//dio_vidWriteChannelGroup(sevenseg_port1,fdigit,0b00010111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, (ftdigit&1));
	dio_vidWriteChannel(sevenseg_port1, PB1, (ftdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (ftdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4, (ftdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port8, PA3, STD_LOW);
	_delay_ms(5);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	//dio_vidWriteChannelGroup(sevenseg_port1,sdigit,0b00001111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, tdigit&1);
	dio_vidWriteChannel(sevenseg_port1, PB1, (tdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (tdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4, (tdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port7, PA2, STD_LOW);
	_delay_ms(5);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	//dio_vidWriteChannelGroup(sevenseg_port1,tdigit,0b00001111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, sdigit&1);
	dio_vidWriteChannel(sevenseg_port1, PB1, (sdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (sdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4,( sdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port5, PB5, STD_LOW);
	_delay_ms(5);
	dio_vidWriteChannel(sevenseg_port5, PB5, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port7, PA2, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port8, PA3, STD_HIGH);
	dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	//dio_vidWriteChannelGroup(sevenseg_port1,ftdigit,0b00001111,0);
	dio_vidWriteChannel(sevenseg_port1, PB0, fdigit&1);
	dio_vidWriteChannel(sevenseg_port1, PB1, (fdigit>>1)&1);
	dio_vidWriteChannel(sevenseg_port1, PB2, (fdigit>>2)&1);
	dio_vidWriteChannel(sevenseg_port1, PB4, (fdigit>>3)&1);
	//dio_vidWriteChannel(sevenseg_port6, PB6, STD_LOW);
	_delay_ms(5);
	
}