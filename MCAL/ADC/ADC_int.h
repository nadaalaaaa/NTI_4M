/****************************************************************/
/*   Author             :    Ahmed Atia Atia 				    */
/*	 Date 				:    2 May 2019  						*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:   public Accessing mechanism prototype*/
/*							and Sense Mode Definition [int.h] 	*/
/****************************************************************/



/****************************************************************/
/* Description   : Guard to protect this File from include more */
/*                 than one time .                              */
/****************************************************************/

#ifndef _ADC_INT_H
#define _ADC_INT_H

#include "bit_math.h"
#include "std_types.h"

/****************************************************************/
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/

#define AVCC 					5
#define AREF 					4
#define INTERNAL				2.56

#define RIGHT_ADJUSTMENT 		0
#define LEFT_ADJUSTMENT 		1


#define DIVID_BY_2				1
#define DIVID_BY_4				2
#define DIVID_BY_8				3
#define DIVID_BY_16				4
#define DIVID_BY_32				5
#define DIVID_BY_64				6
#define DIVID_BY_128			7

#define DIO_U8_PIN_1    DIO_PIN0
#define DIO_U8_PIN_2    DIO_PIN1
#define DIO_U8_PIN_3    DIO_PIN2
#define DIO_U8_PIN_4    DIO_PIN3
#define DIO_U8_PIN_5    DIO_PIN4
#define DIO_U8_PIN_6    DIO_PIN5
#define DIO_U8_PIN_7    DIO_PIN6
#define DIO_U8_PIN_8    DIO_PIN7

#define ch0 0
#define ch1 1
#define ch2 2
#define ch3 3
#define ch4 4
#define ch5 5
#define ch6 6
#define ch7 7

#define FREE_RUNNING_MODE 				0
#define ANALOG_COMPARATOR				1
#define EXTERNAL_INTERRPUT_REQUEST_0 	2
#define TIMER_COUNTER_0_COMPARE_MATCH	3
#define TIMER_COUNTER_0_OVERFLOW		4
#define TIMER_COUNTER_COMPARE_MATCH_B	5
#define TIMER_COUNTER_1_OVERFLOW		6
#define TIMER_COUNTER_1_CAPTURE_EVENT	7

typedef void (*pf16) (u16);
#define NULL 0
/****************************************************************/
/* Description    :  This function used to initialize ADC 	    */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/

void ADC_voidInit (void);
void ADC_selectChannel(u8 chanel);
void ADC_ReadALLChannels(void);
//****************************************************************/
/* Description    : This function used to Enable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidEnable();


/****************************************************************/
/* Description    : This function used to Enable ADC Interrput	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidInterrputEnable();


/****************************************************************/
/* Description    : This function used to Disable ADC			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidDisable();


/****************************************************************/
/* Description    : This function used to communicate with the	*/
/*					function in App Layer(The Callback function)*/
/*						[ Layer Architecture Problem Solved ]	*/
/*																*/
/*					Inputs : Pointer to function that points to	*/
/*							 the first line of the function(ISR)*/
/*					Return : void								*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
u8 ADC_u8ReadADC(pf16 addresscpy);

void ADC_voidCallBack(pf16 addresscpy);
void ADC_ReadSpecificChannels(u8 c);

/****************************************************************/
/* Description    : This function used to Start converting		*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

void ADC_voidStartConversion();


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

void ADC_voidAutoTrigger();



/****************************************************************/
/* Description    : This function used to Read ADC and 			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : u16 Digital Converting melli Volt	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after ADC 		*/
/*     				 initialized 							    */
/****************************************************************/

u16 ADC_u16ReadADCInMV();

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


#endif	/** !comment  :  End of guard                          **/