/**
 ******************************************************************************
 * @file           : LCD_demo.c
 * @brief          : demo programs for LCD display
 * @author 				 : kumpakri
 * @date					 : 30 Jul 2018
 ******************************************************************************
 */
	
#include "LCD_demo.h"
#include "stm32f4xx_hal.h"
#include "LCD_lib.h"
	
void hello_world_demo(void)
{
	/* Put string to LCD */
	// data 00001111 0x0F display on
	lcd_send_cmd(CMD_CURSOR_BLINK);
	
	// data 001110 fcn set
	lcd_send_cmd(CMD_SET_CURSOR_RIGHT);
	
	// data 000000010 return home
	lcd_send_cmd(CMD_RETURN_HOME);
	
	// data 00101010 write *
	lcd_write_string("*",1);

	for( int i=0; i < 3; i++ )
	{
		// data 00010100 0x14 shift cursor right
		lcd_send_cmd(CMD_MV_CURSOR_RIGHT);
	}
	
	
	// Write string
	lcd_write_string("Hello World!", 12);

	
	for( int i = 0; i < 3 ; i++ )
	{
		// data 00010100 0x14 shift cursor right
		lcd_send_cmd(CMD_MV_CURSOR_RIGHT);
	}
	
	// data 00101010 write *
	lcd_write_string("*",1);
	
	HAL_Delay(5000);
	
	// data 00000001 clear display
	lcd_send_cmd(CMD_CLEAR_DISPLAY);
	
	// data 00001111 0x0F display off
	lcd_send_cmd(CMD_DISPLAY_OFF);
}

void four_line_demo(void)
{
	lcd_send_cmd(CMD_CURSOR_BLINK);
	lcd_send_cmd(CMD_SET_CURSOR_RIGHT);
	
	lcd_send_cmd(CMD_SET_FOUR_LINES);
	
	lcd_set_position(0,0);
	lcd_write_string("Hello World!", 12);
	
	lcd_set_position(1,1);
	lcd_write_string("Hello World!", 12);
	
	lcd_set_position(2,2);
	lcd_write_string("Hello World!", 12);
	
	lcd_set_position(3,3);
	lcd_write_string("Hello World!", 12);

	HAL_Delay(5000);
	lcd_send_cmd(CMD_CLEAR_DISPLAY);
	lcd_send_cmd(CMD_DISPLAY_OFF);
}
