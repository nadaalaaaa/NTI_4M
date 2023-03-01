


/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "ADC_int.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "dio.h"
#include "lcd.h"
/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

volatile pf16 k;

/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void)
{
	dio_vidConfigChannel(DIO_PORTA, ch0, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch1, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch2, INPUT);
    dio_vidConfigChannel(DIO_PORTA, ch3, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch4, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch5, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch6, INPUT);
	dio_vidConfigChannel(DIO_PORTA, ch7, INPUT);
	
	#if VOLTAGE_REFERENCE == AVCC
	SET_BIT( ADMUX , 6 );
	CLEAR_BIT( ADMUX , 7 );
	
	#elif VOLTAGE_REFERENCE == AREF
	CLEAR_BIT( ADMUX , 6 );
	CLEAR_BIT( ADMUX , 7 );
	
	#elif VOLTAGE_REFERENCE == INTERNAL
	SET_BIT( ADMUX , 6 );
	SET_BIT( ADMUX , 7 );
	#endif
	
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	SET_BIT( ADMUX , 5 );
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	CLEAR_BIT( ADMUX , 5 );
	#endif
	ADMUX&=0xE0;
	ADMUX|=ADC_CHANNEL_NUMBER;
	
	
	ADCSRA&=0xF8;
	ADCSRA|= ADC_PRESCALLER;
}
void ADC_selectChannel(u8 chanel){
	switch (chanel)
	{case 0:ADMUX&=0xE0;
		    ADMUX|=chanel;
		break;
	case 1: ADMUX&=0xE0;
	ADMUX|=chanel;
	    break;
	case 2: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	case 3: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	case 4: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	case 5: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	case 6: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	case 7: ADMUX&=0xE0;
	ADMUX|=chanel;
	break;
	}
}
void ADC_ReadALLChannels(void){
	u16 value;
	for(u8 count=0;count<8;count++){
		ADC_selectChannel(count);
		 lcd_displyStr("ADC value");	/* Write string on 1st line of LCD */
		 ADC_voidStartConversion();
		 lcd_sendCmd(0xc4);
		 value=ADC_u16ReadADCInMV();
		 LCDConvertINTtoSTR(value);
		 _delay_us(500);
		 lcd_displyStr("  ");
		 lcd_sendCmd(CLEAR_COMMAND);
	}
}
void ADC_ReadSpecificChannels(u8 channnel){
	u16 value;
	ADC_selectChannel(channnel);
	lcd_displyStr("ADC value");	/* Write string on 1st line of LCD */
	ADC_voidStartConversion();
	lcd_sendCmd(0xc4);
	value=ADC_u16ReadADCInMV();
	LCDConvertINTtoSTR(value);
	_delay_us(500);
	lcd_displyStr("  ");
	lcd_sendCmd(CLEAR_COMMAND);
}
/****************************************************************/
/* Description    : This function used to Enable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable()
{
	
	SET_BIT( ADCSRA , 7 );
	
}

/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable()
{

	
	SET_BIT( ADCSRA , 3 );
	
}


/****************************************************************/
/* Description    : This function used to Disable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable()
{
	
	CLEAR_BIT( ADCSRA , 7 );
	
}


/****************************************************************/
/* Description    : This function used to Start converting		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion()
{
	
	SET_BIT( ADCSRA , 6 );
	
}


/****************************************************************/
/* Description    : This function used to Set lach Interrupt	*/
/*									 happens.					*/
/*																*/
/*					Inputs : Sense Mode				  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidAutoTrigger()
{
	

	
	/****************************************************************/
	/** !comment : From Data Sheet : Starting conversion on positive*/
	/*			   edge when ADATE = 1						    	*/
	/****************************************************************/

	
	/** Enable ADC Auto Trigger	 							   **/
	/** ADATE = 1 =====> 	SET_BIT( ADATE , 5 ); 			   **/

	SET_BIT( ADCSRA , 5 );
	

	/*  ( if / else if ) condition for Macros */
	#if ADC_AUTO_TRIGGER_SOURCE == FREE_RUNNING_MODE
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == ANALOG_COMPARATOR
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == EXTERNAL_INTERRPUT_REQUEST_0
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );
	
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_COMPARE_MATCH
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	CLEAR_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_0_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );
	
	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_COMPARE_MATCH_B
	SET_BIT( SFIOR , 5 );
	CLEAR_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_OVERFLOW
	CLEAR_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );

	#elif ADC_AUTO_TRIGGER_SOURCE == TIMER_COUNTER_1_CAPTURE_EVENT
	SET_BIT( SFIOR , 5 );
	SET_BIT( SFIOR , 6 );
	SET_BIT( SFIOR , 7 );
	
	#endif
	/* End ( if ) condition for Macros */
	
}


/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV()
{
	u16 mv_result=0;
	while(CHECK_BIT(ADCSRA,4) == 0);
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	mv_result|=((u16)(ADCL>>6))|(((u16)(ADCH))<<2);
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
mv_result|=((u16)(ADCL))|(((u16)(ADCH))<<8);
	#endif
	SET_BIT(ADCSRA,4);
	
	return mv_result;
}
void ADC_voidCallBack(pf16 addresscpy)
{
	if(addresscpy != NULL)
	{
		k = addresscpy;
	}
}
void __vector_16(void) __attribute__(( signal , used ));


void __vector_16(void)
{
	u16 mv_result=0;
	while(CHECK_BIT(ADCSRA,4) == 0);
	#if ADJUSTMENT == LEFT_ADJUSTMENT
	mv_result|=((u16)(ADCL>>6))|(((u16)(ADCH))<<2);
	#elif ADJUSTMENT == RIGHT_ADJUSTMENT
	mv_result|=((u16)(ADCL))|(((u16)(ADCH))<<8);
	#endif
	k(mv_result);
	
}

/***********************************************************************************************/
/************************************* END OF PROGRAM ******************************************/
/***********************************************************************************************/