/*
 * lcd.c
 *
 * Created: 18/02/2023 13:44:52
 *  Author: dell
 */ 
#define F_CPU 8000000
#include <avr/delay.h>
#include "dio.h"
#include "lcd.h"
#include "lcd_config.h"


void lcd_init(void){
	dio_vidConfigChannel(LCD_PORTRS, RS, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORTE, EN, OUTPUT_PIN);
	#if LCD_MODE==8
	#elif LCD_MODE==4
	dio_vidConfigChannel(LCD_PORTD4, D4, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORTD5, D5, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORTD6, D6, OUTPUT_PIN);
	dio_vidConfigChannel(LCD_PORTD7, D7, OUTPUT_PIN);
	
	_delay_ms(40);
	dio_vidWriteChannel(LCD_PORTRS, RS, LOW);
	dio_vidWriteChannel(LCD_PORTD4, D4, LOW);
	dio_vidWriteChannel(LCD_PORTD5, D5, HIGH);
    dio_vidWriteChannel(LCD_PORTD6, D6, LOW);
	dio_vidWriteChannel(LCD_PORTD7, D7, LOW);
	dio_vidWriteChannel(LCD_PORTE, EN, HIGH);
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORTE, EN, LOW);
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
	dio_vidWriteChannel(LCD_PORTRS, RS, LOW);  //CMD MODE
	
    dio_vidWriteChannel(LCD_PORTD4,D4, CHECK_BIT(cmd,4));
	dio_vidWriteChannel(LCD_PORTD4,D5, CHECK_BIT(cmd,5));
	dio_vidWriteChannel(LCD_PORTD4,D6, CHECK_BIT(cmd,6));
	dio_vidWriteChannel(LCD_PORTD4,D7, CHECK_BIT(cmd,7));
	//dio_vidWriteChannelGroup(LCD_PORTD4,cmd>>4,0b01111000,3); //WRITE CMD LAST FOUR BITS
	
	dio_vidWriteChannel(LCD_PORTE, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORTE, EN, LOW); //END ENABLE PULSE
	
	dio_vidWriteChannel(LCD_PORTD4,D4, CHECK_BIT(cmd,0));
	dio_vidWriteChannel(LCD_PORTD4,D5, CHECK_BIT(cmd,1));
	dio_vidWriteChannel(LCD_PORTD4,D6, CHECK_BIT(cmd,2));
	dio_vidWriteChannel(LCD_PORTD4,D7, CHECK_BIT(cmd,3));
	//dio_vidWriteChannelGroup(LCD_PORTD4,cmd,0b01111000,3); //WRITE CMD FIRST FOUR BITS
	dio_vidWriteChannel(LCD_PORTE, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORTE, EN, LOW); //END ENABLE PULSE
	
	#endif
	
}
void lcd_gotoRowColumn(u8 row, u8 column){
	u8 Address=0;
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
	dio_vidWriteChannel(LCD_PORTRS, RS, HIGH);  //DATA MODE
	
	dio_vidWriteChannel(LCD_PORTD4,D4, CHECK_BIT(chr,4));
	dio_vidWriteChannel(LCD_PORTD4,D5, CHECK_BIT(chr,5));
	dio_vidWriteChannel(LCD_PORTD4,D6, CHECK_BIT(chr,6));
	dio_vidWriteChannel(LCD_PORTD4,D7, CHECK_BIT(chr,7));
	//dio_vidWriteChannelGroup(LCD_PORTD4,chr>>4,0b01111000,3); //WRITE DATA LAST FOUR BITS
	
	dio_vidWriteChannel(LCD_PORTE, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORTE, EN, LOW); //END ENABLE PULSE
	
	dio_vidWriteChannel(LCD_PORTD4,D4, CHECK_BIT(chr,0));
	dio_vidWriteChannel(LCD_PORTD4,D5, CHECK_BIT(chr,1));
	dio_vidWriteChannel(LCD_PORTD4,D6, CHECK_BIT(chr,2));
	dio_vidWriteChannel(LCD_PORTD4,D7, CHECK_BIT(chr,3));
	//dio_vidWriteChannelGroup(LCD_PORTD4,chr,0b01111000,3); //WRITE DATA LAST FOUR BITS
	dio_vidWriteChannel(LCD_PORTE, EN, HIGH); //START ENABLE PULSE
	_delay_ms(5);
	dio_vidWriteChannel(LCD_PORTE, EN, LOW); //END ENABLE PULSE
	
	#endif
	
}
void LCDConvertINTtoSTR(u16 val){
	static u8 converted_val[16];
	u8* ptr=&converted_val[15];
	*ptr='\0';
	if(val==0){
		ptr--;
		*ptr='0';
	}
	while(val!=0){
		ptr--;
		*ptr=(val%10)+'0';
		val/=10;
	}
	lcd_displyStr(ptr);
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