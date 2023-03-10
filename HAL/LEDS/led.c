/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  led.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "led.h"
#include "led_config.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void led_init(void)        
* \Description     : this service for initiate leds                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Return value:   : None                            
*******************************************************************************/
void led_init(void){
	dio_vidConfigChannel(ledport1, ledpin1, OUTPUT );
	dio_vidConfigChannel(ledport2, ledpin2, OUTPUT );
	dio_vidConfigChannel(ledport3, ledpin3, OUTPUT );
	
}
/******************************************************************************
* \Syntax          : void led_on(u8 ledID)   
* \Description     : this service for led on                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledID	  -> led id
					
* \Return value:   : None                            
*******************************************************************************/
void led_on(u8 ledID){
	#if led_type==source
	switch(ledID){
		case 1:dio_vidWriteChannel(ledport1, ledpin1, STD_HIGH);
		break;
		case 2:dio_vidWriteChannel(ledport2, ledpin2 ,STD_HIGH);
		break;
		case 3:dio_vidWriteChannel(ledport3, ledpin3 ,STD_HIGH);
		break;
		
	}
	#else
	switch(ledID){
		case 1:dio_vidWriteChannel(ledport1, ledpin1, STD_LOW);
		break;
		case 2:dio_vidWriteChannel(ledport2, ledpin2, STD_LOW);
		break;
		case 3:dio_vidWriteChannel(ledport3, ledpin3, STD_LOW);
		break;
		
	}
	#endif
}
/******************************************************************************
* \Syntax          :void led_off(u8 ledID)
* \Description     : this service for led off                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledID	  -> led id
* \Return value:   : None                            
*******************************************************************************/
void led_off(u8 ledID){
	#if led_type==source
	switch(ledID){
		
		case 1:dio_vidWriteChannel(ledport1, ledpin1, STD_LOW);
		break;
		case 2:dio_vidWriteChannel(ledport2, ledpin2, STD_LOW);
		break;
		case 3:dio_vidWriteChannel(ledport3, ledpin3, STD_LOW);
		break;
	}
	#else
	switch(ledID){
		case 1:dio_vidWriteChannel(ledport1, ledpin1, STD_HIGH);
		break;
		case 2:dio_vidWriteChannel(ledport2, ledpin2, STD_HIGH);
		break;
		case 3:dio_vidWriteChannel(ledport3, ledpin3, STD_HIGH);
		break;
		
	}
	#endif
}



/******************************************************************************
* \Syntax          :void led_toggle(u8 ledID)
* \Description     : this service for toggle led                             
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledID	  -> led id
* \Return value:   : None                            
*******************************************************************************/
void led_toggle(u8 ledID){
	switch(ledID){
		case 1:dio_vidFlipChannel(ledport1, ledpin1);
		break;
		case 2:dio_vidFlipChannel(ledport2, ledpin2);
		break;
		case 3:dio_vidFlipChannel(ledport3, ledpin3);
		break;
		
	}
}
/**********************************************************************************************************************
 *  END OF FILE: led.c
 *********************************************************************************************************************/
