/**
 ******************************************************************************
 * @file           : LCD_lib.h
 * @brief          : Library for 2004A LCD display (SPLC780 controller) header file
 * @author 				 : kumpakri
 * @date					 : 30 Jul 2018
 ******************************************************************************
 */
 
#ifndef __LCD_LIB_H
#define __LCD_LIB_H

#include "stm32f4xx_hal.h"

/* LCD instructions */
#define CMD_CLEAR_DISPLAY 		0x01
#define CMD_RETURN_HOME				0x02
#define CMD_DISPLAY_ON				0x0C  // no cursor
#define CMD_DISPLAY_OFF 			0x08  
#define CMD_CURSOR_ON				 	0x0E	// turns display on, no blink
#define CMD_CURSOR_BLINK		 	0x0F	// turns display on, shows cursor
#define CMD_SET_CURSOR_LEFT  	0x04	// cursor moves left when moved
#define CMD_SET_CURSOR_RIGHT 	0x06	// cursor moves right when moved
#define CMD_SET_DISP_RIGHT  	0x05	// whole display moves left when cursor moved
#define CMD_SET_DISP_LEFT 		0x07	// whole display moves right when cursor moved
#define CMD_MV_CURSOR_LEFT		0x10
#define CMD_MV_CURSOR_RIGHT		0x14
#define CMD_MV_DISP_LEFT			0x18
#define CMD_MV_DISP_RIGHT			0x1C
#define CMD_SET_FOUR_LINES		0x38  // lines 0, 1, 2 and 3
#define CMD_SET_CGRAM_ADDR		0x40  // D5-D0 are data
#define CMD_SET_DDRAM_ADDR		0x80 	// D6-D0 are data

/*
NOTICE !
Following instructions sets LCD display mode not supported by this library :
					0x20 for 4-bit bus mode, two lines, 5x8 dots format font
					0x28 for 4-bit bus mode, four lines, 5x8 dots format font
					0x34 for 8-bit bus mode, two lines, 5x11 dots format font
					0x24 for 4-bit bus mode, two lines, 5x11 dots format font
					0x30 for 2 line display, lines 0 and 2, DDRAM address starts 0x00 ends 0x4F
*/

/* Functions */

void lcd_init(void);

void lcd_send_cmd(int cmd);

void lcd_set_position(uint8_t line, uint8_t pos);

void lcd_write_string(char* str, int len);

void lcd_write_data(int data);

void lcd_save_custom_char(int addr, int data[8]);

void lcd_load_wooduino_font(void);

void lcd_write_woodoino_char(int ch, int line, int pos);

void lcd_write_3line_char(int ch, int line, int pos);

#endif /* __LCD_LIB_H */
