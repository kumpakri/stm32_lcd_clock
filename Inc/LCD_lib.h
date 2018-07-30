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

/* Functions */

void lcd_send_cmd(int cmd);

#endif /* __LCD_LIB_H */
