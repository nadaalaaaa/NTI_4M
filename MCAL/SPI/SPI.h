/*
 * SPI.h
 *
 * Created: 04/03/2023 13:20:41
 *  Author: dell
 */ 


#ifndef SPI_H_
#define SPI_H_

typedef u8 (*W) (void);
#define NULL 0

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
void SPI_Msend_Byte(u8 byte);
u8 SPI_Mtransev_Byte(u8 byte);
u8 SPI_Sreceive_Byte(void);
void SPI_Stransmit_Byte(u8 byte);
void ISR_voidCallBack(W addresscpy);
void SPI_voidSendDataISR(u8 Copy_Data);
u8 SPI_u8ReadDataISR(void);

#endif /* SPI_H_ */