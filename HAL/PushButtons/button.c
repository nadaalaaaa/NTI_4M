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
		case button1:	dio_vidConfigChannel(buttonport1,buttonpin1,INPUT);	
		break;
		case button2:	dio_vidConfigChannel(buttonport2,buttonpin2,INPUT);	
		break;
		case button3:	dio_vidConfigChannel(buttonport3,buttonpin3,INPUT);	
		break;
		case button4:	dio_vidConfigChannel(buttonport4,buttonpin4,INPUT);	
		break;
		case button5:	dio_vidConfigChannel(buttonport5,buttonpin5,INPUT);	
		break;
		case button6:	dio_vidConfigChannel(buttonport6,buttonpin6,INPUT);	
		break;
	
		
	}
	
	if(buttontype==pullup){
	switch(buttonID)
	{
		case button1:	dio_vidEnablePullUp(buttonport1,buttonpin1);
		break;
		case button2:	dio_vidEnablePullUp(buttonport2,buttonpin2);
		break;
		case button3:	dio_vidEnablePullUp(buttonport3,buttonpin3);
		break;
		case button4:	dio_vidEnablePullUp(buttonport4,buttonpin4);
		break;
		case button5:	dio_vidEnablePullUp(buttonport5,buttonpin5);
		break;
		case button6:	dio_vidEnablePullUp(buttonport6,buttonpin6);
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
	button_status state=released;
	#if buttontype==pullup
	
	switch(buttonID)
	{
		case button1:	state= dio_dioLevelReadChannel(buttonport1,buttonpin1);	break;
		case button2:	state= dio_dioLevelReadChannel(buttonport2,buttonpin2);	break;
		case button3:	state= dio_dioLevelReadChannel(buttonport3,buttonpin3);	break;
		case button4:	state= dio_dioLevelReadChannel(buttonport4,buttonpin4);	break;
		case button5:	state= dio_dioLevelReadChannel(buttonport5,buttonpin5);	break;
		case button6:	state= dio_dioLevelReadChannel(buttonport6,buttonpin6);	break;
		
	}
	if(state==STD_HIGH) return released;
	else return pressed;
	#else
	switch(buttonID)
	{
		case button1:	state= dio_dioLevelReadChannel(buttonport1,buttonpin1);	break;
		case button2:	state= dio_dioLevelReadChannel(buttonport2,buttonpin2);	break;
		case button3:	state= dio_dioLevelReadChannel(buttonport3,buttonpin3);	break;
		case button4:	state= dio_dioLevelReadChannel(buttonport4,buttonpin4);	break;
		case button5:	state= dio_dioLevelReadChannel(buttonport5,buttonpin5);	break;
		case button6:	state= dio_dioLevelReadChannel(buttonport6,buttonpin6);	break;
		
	}
	if(state==STD_HIGH) return pressed;
	else return released;
	#endif
}
/**********************************************************************************************************************
 *  END OF FILE: button.c
 *********************************************************************************************************************/
