/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  button.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "button.h"
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
* \Syntax          : void button_init(u8 buttonID)
* \Description     : this service for initiate button
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u8 buttonID
* \Return value:   : None
*******************************************************************************/
void button_init(u8 buttonID){ 
	switch(buttonID)
	{
		case button1:	dio_vidConfigChannel(buttonport,buttonpin1,INPUT);	
		break;
		case button2:	dio_vidConfigChannel(buttonport,buttonpin2,INPUT);	
		break;
		case button3:	dio_vidConfigChannel(buttonport,buttonpin3,INPUT);	
		break;
		case button4:	dio_vidConfigChannel(buttonport,buttonpin4,INPUT);	
		break;
		case button5:	dio_vidConfigChannel(buttonport,buttonpin5,INPUT);	
		break;
		case button6:	dio_vidConfigChannel(buttonport,buttonpin6,INPUT);	
		break;
	
		
	}
	
	if(buttontype==pullup){
	switch(buttonID)
	{
		case button1:	dio_vidEnablePullUp(buttonport,buttonpin1);
		break;
		case button2:	dio_vidEnablePullUp(buttonport,buttonpin2);
		break;
		case button3:	dio_vidEnablePullUp(buttonport,buttonpin3);
		break;
		case button4:	dio_vidEnablePullUp(buttonport,buttonpin4);
		break;
		case button5:	dio_vidEnablePullUp(buttonport,buttonpin5);
		break;
		case button6:	dio_vidEnablePullUp(buttonport,buttonpin6);
		break;
		
	}	
	}
}
/******************************************************************************
* \Syntax          : button_status button_get_status(u8 buttonID)
* \Description     : this service for get button status
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : u8 buttonID
* \Return value:   : button_status
*******************************************************************************/
button_status button_get_status(u8 buttonID){
	#if buttontype==pullup
	button_status state=released;
	switch(buttonID)
	{
		case button1:	state= dio_dioLevelReadChannel(buttonport,buttonpin1);	break;
		case button2:	state= dio_dioLevelReadChannel(buttonport,buttonpin2);	break;
		case button3:	state= dio_dioLevelReadChannel(buttonport,buttonpin3);	break;
		case button4:	state= dio_dioLevelReadChannel(buttonport,buttonpin4);	break;
		case button5:	state= dio_dioLevelReadChannel(buttonport,buttonpin5);	break;
		case button6:	state= dio_dioLevelReadChannel(buttonport,buttonpin6);	break;
		
	}
	if(state==STD_HIGH) return released;
	else return pressed;
	#else
	switch(buttonID)
	{
		case button1:	state= dio_dioLevelReadChannel(buttonport,buttonpin1);	break;
		case button2:	state= dio_dioLevelReadChannel(buttonport,buttonpin2);	break;
		case button3:	state= dio_dioLevelReadChannel(buttonport,buttonpin3);	break;
		case button4:	state= dio_dioLevelReadChannel(buttonport,buttonpin4);	break;
		case button5:	state= dio_dioLevelReadChannel(buttonport,buttonpin5);	break;
		case button6:	state= dio_dioLevelReadChannel(buttonport,buttonpin6);	break;
		
	}
	if(state==STD_HIGH) return pressed;
	else return released;
	#endif
}
/**********************************************************************************************************************
 *  END OF FILE: button.c
 *********************************************************************************************************************/
