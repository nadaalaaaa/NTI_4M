/*
 * EXTI1_int.h
 *
 * Created: 24/02/2023 12:00:52
 *  Author: dell
 */ 


#ifndef EXTI1_INT_H_
#define EXTI1_INT_H_

typedef void (*pf) (void);
#define  NULL 0
/****************************************************************/
/** !comment : Sense Mode Definition					   		*/
/****************************************************************/

#define IOC			1
#define FALLING		4
#define RISING		7
#define LOW_LEVEL	10



/****************************************************************/
/* Description    :  This function used to initialize EXT0      */
/*					 Inputs : void 								*/
/*					 return : void		 						*/
/****************************************************************/
void EXT1_voidInit ( void );

void Enable_GIE1 (void);
/****************************************************************/
/* Description    : This function used to Enable EXT0			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidEnable( void );


/****************************************************************/
/* Description    : This function used to Disable EXT0			*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
void EXT1_voidDisable( void );


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

void EXT1_voidCallBack(pf addresscpy);


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
void EXT1_voidSetSignalch(u8 SenseCpy);


/****************************************************************/
/* Description    : This function used to Check if interrupt is */
/*					Executed or Not.							*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : flag Status [ LBTY_OK , LBTY_NOK ]	*/
/****************************************************************/
/* Pre_condition  :  this function must be used after Interrupt */
/*     				 initialized 							    */
/****************************************************************/
/*
flagStatus EXT0_enuIsExecuted( void );
*/



#endif /* EXTI1_INT_H_ */