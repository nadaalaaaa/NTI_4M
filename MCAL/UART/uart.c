/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  uart.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

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
* \Syntax          : void UART_Init(u16 baudRate)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : baudRate   UART baudrate                                                                     
* \Return value:   : None                                   
*******************************************************************************/
#include "bit_math.h"
#include "Std_Types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "uart_reg.h"
#include "uart.h"

u8 array[200];
u8 RX_array[200];
u16 byte_index=0;
u16 byte_index_RX=0;

volatile KK QQ;
volatile KK QQQ;
volatile K Q;

void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRL_REG = (u8)baudRate;
	UART_UBRRH_REG = (u8)(baudRate>>8);

	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO) | UART_8_BIT_DATA | UART_EVEN_PARITY;

	SET_BIT(UART_UCSRB_REG,7); /*	Enable Rx Complete Interrupt	*/
	SET_BIT(UART_UCSRB_REG,6); /*	Enable Tx Complete Interrupt	*/
}

/******************************************************************************
* \Syntax          : void UART_TransmitChr(u8 data)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : data   data byte                                                                    
* \Return value:   : None                                   
*******************************************************************************/


void UART_TransmitChr(u8 data)
{while (! (UART_UCSRA_REG & (1<<UDRE_BIT_NO)));
	/* Put data into buffer*/
	UART_UDR_REG = data;
}
void UART_TransmitChrINT(u8 data){
	u8 m=UART_UDR_REG;
	UART_UDR_REG = data;
}
/******************************************************************************
* \Syntax          : u8 UART_ReceiveChr(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                    
* \Return value:   : u8     received data byte                                   
*******************************************************************************/
u8 UART_ReceiveChr(void)
{while ((UART_UCSRA_REG & (1 << RXC_BIT_NO)) == 0);
	return UART_UDR_REG;
}
/******************************************************************************
* \Syntax          : void UART_TransmitStr(u8 *str)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :u8 *str
* \Return value:   : void
*******************************************************************************/
void UART_TransmitStr(u8 *str){
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_TransmitChr(str[j]);
		j++;
	}
	UART_TransmitChr('\0');
}
void UART_TransmitStrINT(u8 *str){
	u8 i=0;
	if(byte_index==0){
		while(str[i]!='\0'){
		array[i]=str[i];
		i++;
	}
	str[i]='\0';
	UART_TransmitChrINT(array[byte_index]);
	}
	
}
void UART_ReceiveStr(u8 *str){
	u8 i=0;
	str[i]=UART_ReceiveChr();
	while(str[i]!='#'){
		i++;
		str[i]=UART_ReceiveChr();
		
	}
	str[i]='\0';
}
u8 Check_Rec_String(void){//////to check that you end your string or still typing
	if(byte_index_RX==0) return 0;
	else if(RX_array[byte_index_RX-1]=='#') return 1; ////////if you end the string
	else return 0;
}
void Receive_str_int(u8 *str){ ///////////to copy entered string to another string in application layer(main)
	u8 i=0;
	while(RX_array[i]!='#'){
		str[i]=RX_array[i];
		i++;
	}
	str[i]='\0'; ///////end the string with null terminator
	byte_index_RX=0; /////////start index from first
	}
void UART_RXCEnable(void){
	SET_BIT(UART_UCSRB_REG,DIO_PIN7);
}
void UART_TXCEnable(void){
	SET_BIT(UART_UCSRB_REG,DIO_PIN6);
}
void UART_EMPTYEnable(void){
	SET_BIT(UART_UCSRB_REG,DIO_PIN5);
}
void UART_RXCDISEnable(void){
	CLEAR_BIT(UART_UCSRB_REG,DIO_PIN7);
}
void UART_TXCDISEnable(void){
	CLEAR_BIT(UART_UCSRB_REG,DIO_PIN6);
}
void UART_EMPTYDISEnable(void){
	CLEAR_BIT(UART_UCSRB_REG,DIO_PIN5);
}
void UART_voidCallBack(K addresscpy){
	if(addresscpy != NULL)
	{
		Q = addresscpy;
	}
}
void UARTTXC_voidCallBack(KK addresscpy){
	if(addresscpy != NULL)
	{
		QQ = addresscpy;
	}
}
void UARTEMPTY_voidCallBack(KK addresscpy){
	if(addresscpy != NULL)
	{
		QQQ = addresscpy;
	}
}
void __vector_13(void) __attribute__(( signal , used ));


void __vector_13(void)
{
	//Q(UART_UDR_REG);
	if(byte_index_RX<200){////////check you didnt exceed the size
	RX_array[byte_index_RX]=UART_UDR_REG; ////////entered data from data reg to your array
	byte_index_RX++;
	}
	
		}

void __vector_14(void) __attribute__(( signal , used ));


void __vector_14(void)
{
	u8 z=QQQ();
	UART_TransmitChrINT(z);
	
}
void __vector_15(void) __attribute__(( signal , used ));


void __vector_15(void)
{/* 
	u8 z=QQ();
	UART_TransmitChrINT(z);*/
byte_index++;
if(array[byte_index]!='\0'){
	UART_TransmitChrINT(array[byte_index]);
}
else{
	byte_index=0;
}
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
