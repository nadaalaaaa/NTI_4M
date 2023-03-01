/*
 * lcd_config.h
 *
 * Created: 18/02/2023 13:45:21
 *  Author: dell
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_MODE FOUR_BIT_MODE

#define EIGTH_BIT_MODE 8
#define FOUR_BIT_MODE 4

///////////////commands//////////
typedef enum{
	CLEAR_COMMAND = 0x01,
	FOUR_BITS_DATA_MODE = 0x02,
	TWO_LINE_LCD_Four_BIT_MODE = 0x28,
	TWO_LINE_LCD_Eight_BIT_MODE = 0x38,
	CURSOR_OFF = 0x0C,
	CURSOR_ON = 0x0E,
	SET_CURSOR_LOCATION = 0x80
}lcd_Cmd_Type;


#endif /* LCD_CONFIG_H_ */