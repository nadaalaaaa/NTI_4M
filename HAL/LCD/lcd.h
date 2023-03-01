/*
 * lcd.h
 *
 * Created: 18/02/2023 13:45:05
 *  Author: dell
 */ 
#include "dio_reg.h"
#include "dio_types.h"
#include "lcd_config.h"

#ifndef LCD_H_
#define LCD_H_

#define LCD_PORT DIO_PORTA

#define RS 1
#define EN 2
#define D4 3
#define D5 4
#define D6 5
#define D7 6

#define INPUT_PIN 0
#define OUTPUT_PIN 1

#define  HIGH 1
#define  LOW  0

void lcd_init(void);
void lcd_sendData(u8 data);
void lcd_sendCmd(lcd_Cmd_Type cmd);
void lcd_gotoRowColumn(u8 row, u8 column);
void lcd_displyChar(u8 chr);
void lcd_displyStr(u8* str);
void lcd_customWrite(u8* custCfg);


#endif /* LCD_H_ */