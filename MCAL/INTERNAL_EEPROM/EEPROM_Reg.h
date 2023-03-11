/*
 * EEPROM_Reg.h
 *
 * Created: 11/03/2023 10:33:41
 *  Author: dell
 */ 


#ifndef EEPROM_REG_H_
#define EEPROM_REG_H_

#define EEARH_REG       *((volatile u8 *)0x3F)
#define EEARL_REG       *((volatile u8 *)0x3E)
#define EEDR_REG        *((volatile u8 *)0x3D)
#define EECR_REG        *((volatile u8 *)0x3C)



#endif /* EEPROM_REG_H_ */