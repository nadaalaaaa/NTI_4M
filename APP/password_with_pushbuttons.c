/*
 * project1.c
 *
 * Created: 20/02/2023 21:35:33
 * Author : dell
 */ 

#define F_CPU 16000000
#include <avr/delay.h>
#include "led.h"
#include "led_config.h"
#include "button.h"
#include "button_config.h"



static u8 arr[]={0,0,1,2,2,2}; //required password
u8 arr1[]={3,3,3,3,3,3}; //entered password from user

int main(void)
{ 
	led_init(led1); //PORTA.5
	button_init(button1);
	button_init(button2);
	button_init(button3);
	dio_vidConfigChannel(DIO_PORTC,DIO_PIN6, OUTPUT);  //buzzer pin as output PORTC.6
	u8 i=0,p=0;

	
	while(1){
		if(button_get_status(button1)==pressed){ //if first button pressed PORTD.7
			arr1[i]=0; //save 0 in the entered array
			p++; //increase number of presses
			i++; //increase index of entered array
		_delay_ms(500);	//delay for debouncing
		}
		
	   if(button_get_status(button2)==pressed){//if second button pressed PORTD.6
		   arr1[i]=1; //save 1 in the entered array
			i++; //increase index of entered array
			p++; //increase number of presses
			_delay_ms(500); //delay for debouncing
		}
		
	   if(button_get_status(button3)==pressed){ //if third button pressed PORTD.5
		   arr1[i]=2; //save 2 in the entered array
			i++; //increase index of entered array
			p++; //increase number of presses
			_delay_ms(500); //delay for debouncing
		}
		
		if((arr[0]==arr1[0])&& (arr[1]==arr1[1])&&(arr[2]==arr1[2])&&(arr[3]==arr1[3])&&(arr[4]==arr1[4])&&(arr[5]==arr1[5])&&p==6){ //if entered all correct in only 6 pressses
			led_on(led1); //on the led
			_delay_ms(250);
			led_off(led1); //off the led
			_delay_ms(250);
		}
		if(( p==6 && ((arr[0]!=arr1[0])||(arr[1]!=arr1[1])||(arr[2]!=arr1[2])||(arr[3]!=arr1[3])||(arr[4]!=arr1[4])||(arr[5]!=arr1[5])))) //if entered any wrong sequence in only 6 presses
		{    led_off(led1); //off the led
			 dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_HIGH); //toggle the buzzer
			 _delay_ms(500); 
			 dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
			 _delay_ms(500);}
	
	   if( p>6 ) //if entered more than 6 presses
	   {led_off(led1); //off the led
		dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_HIGH); //toggle the buzzer
		_delay_ms(500);
		dio_vidWriteChannel(DIO_PORTC, DIO_PIN6, STD_LOW);
	    _delay_ms(500);}
	}
	}


