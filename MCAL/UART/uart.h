/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  uart.h
 *       Module:  uart
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef UART_H_
#define UART_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
typedef void (*K) (u8 va);
typedef u8 (*KK) (void);
#define  NULL 0

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "bit_math.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "uart_reg.h"


#define RX_BUFFER_SIZE				(25)

#define UART_BAUDRATE_1200			(0x340)
#define UART_BAUDRATE_2400			(0x1A0)
#define UART_BAUDRATE_4800			(0xCF)
#define UART_BAUDRATE_9600			(0x33) ////change it to 8MHZ clk and others with 16MHZ clk
#define UART_BAUDRATE_19200			(0x51)
#define UART_BAUDRATE_115200		(0x8)


#define UART_5_BIT_DATA				(0<<UCSZ0_BIT_NO)
#define UART_6_BIT_DATA				(1<<UCSZ0_BIT_NO)
#define UART_7_BIT_DATA				(2<<UCSZ0_BIT_NO)
#define UART_8_BIT_DATA				(3<<UCSZ0_BIT_NO)

#define UART_1_STOP_BIT				(0<<USBS_BIT_NO)
#define UART_2_STOP_BIT				(1<<USBS_BIT_NO)

#define UART_EVEN_PARITY			(2<<UPM0_BIT_NO)
#define UART_ODD_PARITY				(3<<UPM0_BIT_NO)



#define polling 1
#define INT 2

#define flag_type INT
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void UART_Init(u16 baudRate);
void UART_TransmitChr(u8 data);
void UART_TransmitChrINT(u8 data);
void UART_TransmitStr(u8 *str);
void UART_TransmitStrINT(u8 *str);
void UART_ReceiveStr(u8 *str);
u8 Check_Rec_String(void);
void Receive_str_int(u8 * str);
u8 UART_ReceiveChr(void);
void UART_voidCallBack(K addresscpy);
void UARTTXC_voidCallBack(KK addresscpy);
void UARTEMPTY_voidCallBack(KK addresscpy);
void UART_RXCEnable(void);
void UART_TXCEnable(void);
void UART_EMPTYEnable(void);
void UART_RXCDISEnable(void);
void UART_TXCDISEnable(void);
void UART_EMPTYDISEnable(void);

#endif  /* UART_H_ */

/**********************************************************************************************************************
 *  END OF FILE: uart.h
 *********************************************************************************************************************/
