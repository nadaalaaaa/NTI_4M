/*
 * EEPROM.h
 *
 * Created: 11/03/2023 10:33:22
 *  Author: dell
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_write(u16 uiAddress, u8 ucData);
u8 EEPROM_read(u16 uiAddress);


#endif /* EEPROM_H_ */