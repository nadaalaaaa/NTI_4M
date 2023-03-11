/*
 * I2C.h
 *
 * Created: 05/03/2023 09:37:10
 *  Author: dell
 */ 


#ifndef I2C_H_
#define I2C_H_

extern double pow(double _x, double __y) __attribute((const_));
#define BIT_RATE(TWSR)	((F_CPU/TWBR)-16)/(2*pow(4,(TWSR&((1<<0)|(1<<1)))))

void I2C_Init(void);
void I2C_BITRATE(void);
void I2C_Startcond(void);
void I2C_Stopcond(void);
u8 I2C_GetStatus(void);
u8 I2C_CheckStatus(u8 status);
void I2C_Write(u8 data);
u8 I2C_Read_ACK(void);
u8 I2C_Read_NACK(void);
void I2C_SlaveInit(u8 add);
s8 I2C_Slave_Receive(void);
s8 I2C_Slave_Transmit(u8 data);
u8 I2C_Slave_Listen(void);
u8 I2C_Write_M(u8 data);
u8 I2C_Repeated_Start(u8 add);
u8 I2C_Start(u8 add);

#endif /* I2C_H_ */