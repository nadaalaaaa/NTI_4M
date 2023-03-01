/*
 * sevenseg.c
 *
 * Created: 22/02/2023 14:53:02
 * Author : dell
 */ 

#define F_CPU 16000000
#include <avr/delay.h>
#include "dio.h"
#include "dio_types.h"
#include "dio_reg.h"
#include "sevensegment.h"
#include "sevensegment_config.h"
#include "button.h"
#include "button_config.h"

int main(void)
{
    SSD_vidInit();
	button_init(button1);//PORTD.7
	button_init(button2);//PORTD.6
	//SSD_DisplayNum(9898);
	//while(1){SSD_DisplayNum(9898);}
	
	
	u16 key=0,i=2;
	SSD_DisplayNum(0);
    while (1) 
    {if(button_get_status(button1)==pressed){ //if pressed button1
		i=0; //change flag to 0
		while(button_get_status(button1)==pressed); //debouncing
	}
	if(button_get_status(button2)==pressed){ //if pressed button2
		i=1; //change flag to 1
		while(button_get_status(button2)==pressed); //debouncing
	}
	if(i==0){ //if flag 0
		if(key==9999){key=0;} //if count end start it again
			
		key=key+1; //display digit and count up
		
    }
	if(i==1){ //if flag 1
		if(key==0){key=9999;} //if count end start it again
			
		key=key-1; //display digit and count down
		
	}
	for(u8 j=0;j<10;j++){SSD_DisplayNum(key); }
	
	
	}
	
}

