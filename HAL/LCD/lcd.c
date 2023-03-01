/*
 * lcd.c
 *
 * Created: 18/02/2023 13:44:52
 *  Author: dell
 */ 
#define F_CPU 16000000
#include "dio.h"
#include "lcd.h"
#include "lcd_config.h"
#include <avr/delay.h>

void lcd_init(void){
	dio_vidConfigChannel(LCD_PORT, RS, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORT, EN, OUTPUT_PIN);
	#if LCD_MODE==8
	#elif LCD_MODE==4
	dio_vidConfigChannel(LCD_PORT, D4, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORT, D5, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORT, D6, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORT, D7, OUTPUT_PIN);
	
	_delay_ms(40);
	dio_vidWriteChannel(LCD_PORT, RS, LOW);
	dio_vidWriteChannel(LCD_PORT, D4, LOW);
	dio_vidWriteChannel(LCD_PORT, D5, HIGH);
    dio_vidWriteChannel(LCD_PORT, D6, LOW);
	dio_vidWriteChannel(LCD_PORT, D7, LOW);
	dio_vidWriteChannel(LCD_PORT, EN, HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORT, EN, LOW);
	_delay_ms(5);
	lcd_sendCmd(0b00000010);
	lcd_sendCmd(0b00101000);
	_delay_ms(40);
	lcd_sendCmd(0b00001100);
	_delay_ms(40);
	lcd_sendCmd(0b00000001);
	_delay_ms(40);
	lcd_sendCmd(0b00000110);
	
	#endif
	
}
void lcd_sendData(u8 data){
	
}
void lcd_sendCmd(lcd_Cmd_Type cmd){
	
	
	#if LCD_MODE==8
	#elif LCD_MODE==4
	dio_vidWriteChannel(LCD_PORT, RS, LOW);  //CMD MODE

	dio_vidWriteChannelGroup(LCD_PORT,cmd>>4,0b01111000,3); //WRITE CMD LAST FOUR BITS
	
	dio_vidWriteChannel(LCD_PORT, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORT, EN, LOW); //END ENABLE PULSE
	
	
	dio_vidWriteChannelGroup(LCD_PORT,cmd,0b01111000,3); //WRITE CMD FIRST FOUR BITS
	dio_vidWriteChannel(LCD_PORT, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORT, EN, LOW); //END ENABLE PULSE
	
	#endif
	
}
void lcd_gotoRowColumn(u8 row, u8 column){
	u8 Address;
	switch(row)
	{
		case 0:
		Address=column; //first line
		break;
		case 1:
		Address=column+0x40; //second line
		break;
	}

	lcd_sendCmd(Address | SET_CURSOR_LOCATION);
}
void lcd_displyChar(u8 chr){
	
	
	#if LCD_MODE==8
	#elif LCD_MODE==4
	dio_vidWriteChannel(LCD_PORT, RS, HIGH);  //DATA MODE
	
	dio_vidWriteChannelGroup(LCD_PORT,chr>>4,0b01111000,3); //WRITE DATA LAST FOUR BITS
	
	dio_vidWriteChannel(LCD_PORT, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORT, EN, LOW); //END ENABLE PULSE
	
	
	dio_vidWriteChannelGroup(LCD_PORT,chr,0b01111000,3); //WRITE DATA LAST FOUR BITS
	dio_vidWriteChannel(LCD_PORT, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORT, EN, LOW); //END ENABLE PULSE
	
	#endif
	
}
void lcd_displyStr(u8* str){
	u8 i = 0;
	while(str[i] != '\0')
	{
		lcd_displyChar(str[i]); //DISPLAY EACH CHR BY LOOPING THE STRING
		i++;
	}
}
void lcd_customWrite(u8* custCfg){
	
}