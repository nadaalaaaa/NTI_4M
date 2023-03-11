/*
 * I2C.c
 *
 * Created: 05/03/2023 09:36:06
 *  Author: dell
 */ 
#define F_CPU 8000000UL
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "dio.h"
#include "dio_reg.h"
#include "dio_types.h"
#include "lcd.h"
#include "lcd_config.h"
#include "I2C.h"
#include "I2C_config.h"
#include "I2C_priv.h"
#include "GIE.h"

void I2C_Init(void){
	TWSR = 0x00;
	TWCR = (1<<2);
	
}
void I2C_BITRATE(void){
	 TWBR = BIT_RATE(TWSR=0x00);	
}
void I2C_Startcond(void){
	TWCR = (1<<7)|(1<<5)|(1<<2);
	while(!(TWCR&(1<<7)));
}
void I2C_Stopcond(void){
	TWCR=(1<<4)|(1<<7)|(1<<2);
	while(TWCR&(1<<4));
}
u8 I2C_GetStatus(void){
	u8 s;
	s=TWSR&0xF8;
	return s;
}
u8 I2C_CheckStatus(u8 status){
	if(I2C_GetStatus()==status)
	return 1;
	else
	return 0;
}
void I2C_Write(u8 data){
	TWDR = data;
	TWCR = (1<<7)|(1<<2);
	while(!(TWCR&(1<<7)));
}
u8 I2C_Read_ACK(void){
	TWCR=(1<<2)|(1<<7)|(1<<6); /* Enable TWI, generation of ack */
	while(!(TWCR&(1<<7)));	/* Wait until TWI finish its current job */
	return TWDR;
}
u8 I2C_Read_NACK(void){
	TWCR=(1<<2)|(1<<7);	/* Enable TWI and clear interrupt flag */
	while(!(TWCR&(1<<7)));	/* Wait until TWI finish its current job */
	return TWDR;
}
void I2C_SlaveInit(u8 add){
	TWAR=add;		/* Assign Address in TWI address register */
	TWCR=(1<<2)|(1<<6)|(1<<7);
}
void Clear_Flag(void){
	TWCR|=(1<<7);	/* Clear interrupt flag & return -1 */
}
u8 I2C_Start(u8 add){
	u8 s;
	I2C_Startcond();
	s= I2C_GetStatus();
	if(s!=START_ACK)
	return 0;
	I2C_Write(add);
	s= I2C_GetStatus();
	if(s==SLAVE_ADD_AND_WR_ACK)
	return 1;
	if(s==SLAVE_ADD_AND_WR_NACK)
	return 2;
	else 
	return 3;
}
u8 I2C_Repeated_Start(u8 add){
	u8 s;
	I2C_Startcond();
	s= I2C_GetStatus();
	if(s!=REP_START)
	return 0;
	I2C_Write(add);
	s= I2C_GetStatus();
	if(s==SLAVE_ADD_AND_RD_ACK)
	return 1;
	if(s==SLAVE_ADD_AND_RD_NACK)
	return 2;
	else
	return 3;
}
u8 I2C_Write_M(u8 data){
	u8 s;
	I2C_Write(data);
	s= I2C_GetStatus();
	if(s==WR_BYTE_ACK)
	return 0;
	if(s==WR_BYTE_NACK)
	return 1;
	else
	return 2;
}
u8 I2C_Slave_Listen(void){
	u8 s;
	while(!(TWCR&(1<<7)));
	s= I2C_GetStatus();
	if(s==SLAVE_ADD_RCVD_WR_REQ || s==SLAVE_ADD_RCVD_WR_ACK_SENT)
	return 0;
	if(s==SLAVE_ADD_RCVD_RD_REQ || s==SLAVE_ADD_RCVD_RD_ACK_SENT)
	return 1;
	if(s==SLAVE_ADD_RCVD_GEN_REQ || s==SLAVE_ADD_RCVD_GEN_ACK_SENT)
	return 2;
	//else
	//continue;
}
s8 I2C_Slave_Transmit(u8 data){
	s8 s;
	TWDR=data;			/* Write data to TWDR to be transmitted */
	TWCR=(1<<2)|(1<<7)|(1<<6);/* Enable TWI & clear interrupt flag */
	while(!(TWCR&(1<<7)));
	s= I2C_GetStatus();
	if(s==SLAVE_STOP_OR_REP_START_RCVD){
		Clear_Flag();
		return -1;
	}
	if(s==SLAVE_DATA_TRANS_ACK)
	return 0;
	if(s==SLAVE_DATA_TRANS_NACK){
		Clear_Flag();
		return -2;
	}
	if(s==SLAVE_LAST_BYTE_TRANS_ACK)
	return -3;
	else
	return -4;
}
s8 I2C_Slave_Receive(void){
	s8 s;
	TWCR=(1<<2)|(1<<6)|(1<<7);/* Enable TWI & generation of ack */
	while(!(TWCR&(1<<7)));
	s= I2C_GetStatus();
	if(s==SLAVE_DATA_RECEIVED || s==SLAVE_DATA_RECEIVED_ACK)
	return TWDR;
	if(s==SLAVE_DATA_RECEIVED_N || s==SLAVE_DATA_RECEIVED_NACK)
	return TWDR;
	if(s==SLAVE_STOP_OR_REP_START_RCVD){
		Clear_Flag();
		return -1;
	}
	else
	return -2;
}