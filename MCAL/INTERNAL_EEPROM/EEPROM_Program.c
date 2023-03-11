/*
 * EEPROM_Program.c
 *
 *  Created on: Sep 15, 2021
 *      Author: dell
 */


/****************************************************/
/* Library Directives							    */
/****************************************************/
#define F_CPU 8000000
#include <avr/delay.h>
#include "bit_math.h"
#include "std_types.h"
#include "EEPROM.h"
#include "EEPROM_Reg.h"




void EEPROM_write(u16 uiAddress, u8 ucData)
{
while( EECR_REG & (1<<1)); //CHECK end last write (EEWE bit clear when write end)
EEARL_REG = uiAddress; //write address to address reg
EEDR_REG = ucData; //write data to data reg
EECR_REG = 4; //enable writing (EEMWE set and EEWE still cleared then during 4 clk cycles enable EEWE also)
EECR_REG = 0x06; //start writing (set EEWE bit)
_delay_ms(9);
EECR_REG =0; //end writing (clear EEWE ,EEMWE)

}

u8 EEPROM_read(u16 uiAddress)
{
while( EECR_REG & (1<<1));  //CHECK end last write (EEWE bit clear when write end)
EEARL_REG = uiAddress; //write address to address reg
EECR_REG |= (1<<0); //enable reading (SET EERE)
return EEDR_REG; //return data
}

