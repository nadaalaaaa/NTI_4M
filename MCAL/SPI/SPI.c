/*
 * SPI.c
 *
 * Created: 04/03/2023 13:18:43
 *  Author: dell
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "GIE.h"
#include "lcd.h"
#include "lcd_config.h"
#include "SPI.h"
#include "SPI_config.h"
#include "SPI_priv.h"


volatile W L;

void SPI_Master_Init(void){
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN4,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN5,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN6,INPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,OUTPUT);
	SET_BIT(SPCR , MSTR);
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_HIGH);
	
	
	#if INT_POLL == interupt
	SET_BIT(SPCR , SPIE);
	#elif INT_POLL == polling
	CLEAR_BIT(SPCR , SPIE);
	#endif

	

	#if data_order == msb
	CLEAR_BIT(SPCR , DORD);
	#elif data_order == lsb
	SET_BIT(SPCR , DORD);
	#endif
	
	#if clk_polarity == rising
	CLEAR_BIT(SPCR , CPOL);
	#elif clk_polarity == falling
	SET_BIT(SPCR , CPOL);
	#endif
	
	#if clk_phase == sample
	CLEAR_BIT(SPCR , CPHA);
	#elif clk_phase == setup
	SET_BIT(SPCR , CPHA);
	#endif

	#if clk == clk_pre_4
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPSR , SPI2X);
	#elif clk == clk_pre_2
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPSR , SPI2X);

	#endif
	SET_BIT(SPCR , SPE);
}
void SPI_Slave_Init(void){
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN4,INPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN5,INPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN6,OUTPUT);
	dio_vidConfigChannel(DIO_PORTB,DIO_PIN7,INPUT);
	CLEAR_BIT(SPCR , MSTR);
	
	#if INT_POLL == interupt
	SET_BIT(SPCR , SPIE);
	#elif INT_POLL == polling
	CLEAR_BIT(SPCR , SPIE);
	#endif

	

	#if data_order == msb
	CLEAR_BIT(SPCR , DORD);
	#elif data_order == lsb
	SET_BIT(SPCR , DORD);
	#endif
	
	#if clk_polarity == rising
	CLEAR_BIT(SPCR , CPOL);
	#elif clk_polarity == falling
	SET_BIT(SPCR , CPOL);
	#endif
	
	#if clk_phase == sample
	CLEAR_BIT(SPCR , CPHA);
	#elif clk_phase == setup
	SET_BIT(SPCR , CPHA);
	#endif

	#if clk == clk_pre_4
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	CLEAR_BIT(SPSR , SPI2X);
	#elif clk == clk_pre_2
	CLEAR_BIT(SPCR , SPR1);
	CLEAR_BIT(SPCR , SPR0);
	SET_BIT(SPSR , SPI2X);

	#endif
	SET_BIT(SPCR , SPE);
}
void SPI_Msend_Byte(u8 byte){
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
	u8 f;
	SPDR = byte;			/* Write data to SPI data register */
	while(!(SPSR & (1<<SPIF)));	/* Wait till transmission complete */
	f = SPDR;
}
u8 SPI_Mtransev_Byte(u8 byte){
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
	SPDR = byte ;
	while(!(SPSR & (1<<SPIF)));

	return SPDR ;
}
u8 SPI_Sreceive_Byte(void){
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return SPDR;
}
void SPI_Stransmit_Byte(u8 byte){
	while(!(SPSR & (1<<SPIF)));
	SPDR = byte;
}
void SPI_voidSendDataISR(u8 Copy_Data)
{//dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
	SPDR = Copy_Data ;
}

u8 SPI_u8ReadDataISR(void)
{
	return SPDR ;
}
void ISR_voidCallBack(W addresscpy){
	if(addresscpy != NULL)
	{
		L = addresscpy;
	}
}
void __vector_12(void) __attribute__(( signal , used ));


void __vector_12(void){
	#if Mstr_Slav==Slave
	L(SPDR);
	#elif Mstr_Slav==Master
	dio_vidWriteChannel(DIO_PORTB,DIO_PIN4,STD_LOW);
	u8 byte;
	byte=L();
	byte=SPDR;
	#endif

}