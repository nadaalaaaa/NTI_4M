/*
 * SPI_priv.h
 *
 * Created: 04/03/2023 13:19:37
 *  Author: dell
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 0

#define lsb 0
#define msb 7

#define rising 1
#define falling 2

#define Master 1
#define Slave 2

#define setup 3
#define sample 4

#define clk_pre_4 1
#define clk_pre_16 1
#define clk_pre_64 1
#define clk_pre_128 1
#define clk_pre_2 1
#define clk_pre_8 1
#define clk_pre_32 1

#define polling 1
#define interupt 2



#define SPCR (*((volatile u8 *)0x2D ))
#define SPSR (*((volatile u8 *)0x2E ))
#define SPDR (*((volatile u8 *)0x2F ))




#endif /* SPI_PRIV_H_ */