/**
 ******************************************************************************
 * @file           : LCD_lib.c
 * @brief          : Library for 2004A LCD display (SPLC780 controller)
 * @author 				 : kumpakri
 * @date					 : 30 Jul 2018
 ******************************************************************************
 */
	
#include "LCD_lib.h"


int wooduino_font_loaded = 0;

/**
 * Initialize LCD in 4-line mode, cursor set to move right,
 * cursor not shown, 8-bit bus mode, 5x8 format
*/
void lcd_init(void)
{
	lcd_send_cmd(CMD_DISPLAY_ON);
	lcd_send_cmd(CMD_SET_FOUR_LINES);
	lcd_send_cmd(CMD_SET_CURSOR_RIGHT);
}

/**
 * Sends instruction to LCD display
 * Defined instructions:
 * 		CMD_CLEAR_DISPLAY 		- clears the display
 * 		CMD_RETURN_HOME				- sets the cursor at (0,0) position
 * 		CMD_DISPLAY_ON				- turns display on, does not show cursor
 * 		CMD_DISPLAY_OFF 			- turns display off  
 *	 	CMD_CURSOR_ON				 	- turns display on, shows cursor
 * 		CMD_CURSOR_BLINK		 	- turns display on, shows blinking cursor
 *	 	CMD_SET_CURSOR_LEFT  	- sets cursor moving direction left
 * 		CMD_SET_CURSOR_RIGHT 	- sets cursor moving direction right
 *	 	CMD_SET_DISP_RIGHT  	- enables moving display, direction right
 * 		CMD_SET_DISP_LEFT 		- enables moving display, direction left
 *	 	CMD_MV_CURSOR_LEFT		- moves cursor left
 * 		CMD_MV_CURSOR_RIGHT		- moves cursor right
 * 		CMD_MV_DISP_LEFT			- moves display left
 * 		CMD_MV_DISP_RIGHT			- moves display right
 * 		CMD_SET_FOUR_LINES		- sets display for 4-line mode, 8-bit bus mode and 5x8 dots font
 * 		CMD_SET_CGRAM_ADDR		- sets D5-D0 as CGRAM address
 * 		CMD_SET_DDRAM_ADDR		- sets D6-D0 as DDRAM address
*/
void lcd_send_cmd(int cmd)
{
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (cmd & 0x80) >> 7 );
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (cmd & 0x40) >> 6 );
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (cmd & 0x20) >> 5 );
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (cmd & 0x10) >> 4 );
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (cmd & 0x08) >> 3 );
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (cmd & 0x04) >> 2 );
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (cmd & 0x02) >> 1 );
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (cmd & 0x01) );
	
	HAL_Delay(4);
		
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(4);
		
}
	

/**
 * Sets the cursor at a specified position
 * @param line 	specifies the line (0, 1, 2 or 3)
 * @param pos 	specifies position on the line
 * 							range from 0 to 19
 */
void lcd_set_position(uint8_t line, uint8_t pos)
{
	/* 
	 * line 0 starts at 0x00 ~  0 
	 * line 1 starts at 0x40 ~ 64 
	 * line 2 starts at 0x14 ~ 20 
	 * line 3 starts at 0x54 ~ 84 
	 */
	
	/* if out of bounds do nothing */
	if( line<4 && pos <20 )
	{
		
		uint8_t line_arr[4] = {0,3,1,4};
		uint8_t data = line_arr[line]*20+pos;
		if( line==1 || line==3 ) data +=4;
		
		lcd_send_cmd( CMD_SET_DDRAM_ADDR | data );
		
	}
}

/**
 * Sets the CGRAM address counter as specified
 * @param addr CGRAM address (max. 0x7F)
 */
void lcd_set_CGRAM_addr(int addr)
{
	
	/* if out of bound do nothing */
	if( addr < 0x40 )
	{
		lcd_send_cmd( CMD_SET_CGRAM_ADDR | addr );
	}
}

/**
 * Writes string ´str´ on the display
 * @param	str string to be written
 * @param	len length of the ´str´ string
 * @note	the DDRAM address must be set
 */
void lcd_write_string(char* str, int len)
{
	for( int i=0; i<len; i++ )
	{
		lcd_write_data(str[i]);
	}
}

/**
 * Writes data into DDRAM/CGRAM (the last set address)
 * @param data	the data to be written (max. 0xFF)
 */
void lcd_write_data(int data)
{
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 1);
		
		HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (data & 0x80) >> 7 );
		HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (data & 0x40) >> 6 );
		HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (data & 0x20) >> 5 );
		HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (data & 0x10) >> 4 );
		HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (data & 0x08) >> 3 );
		HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (data & 0x04) >> 2 );
		HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (data & 0x02) >> 1 );
		HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (data & 0x01) );
		
		HAL_Delay(4);
		
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
		
		HAL_Delay(4);
}

/**
 * Saves a custom character at specified address in CGRAM.
 * 
 * --- EXAMPLE ---------
 *|-------------------------------------|
 *|custom character: | representation:  |
 *|------------------|------------------|
 *|			1 1 1 1 1 	 |	 0x1F						|
 *|			0 1 1 1 1 	 |	 0x0F						|
 *|			0 0 1 1 1 	 |	 0x07						|
 *|			0 0 0 1 0 	 |	 0x02						|
 *|			0 0 1 0 0 	 |	 0x04						|
 *|			0 1 0 0 0 	 |	 0x08						|
 *|			1 1 1 0 0 	 |	 0x1C						|
 *|			1 0 1 0 1 	 |	 0x15						|
 *|-------------------------------------|
 * => 	data = {0x1F, 0x0F, 0x07, 0x02, 0x04, 0x08, 0x1C, 0x15}
 * --- END of EXAMPLE --
 * 
 * @param addr	chosen address (range from 0 to 7)
 * @param data	custom character. Each list element represents
 * 							a line of pixels. (maximum value: 0x1F)
 */
void lcd_save_custom_char(int addr, int data[8])
{
	if ( addr < 8)
	{
		for( int line = 0; line<8; line++ )
		{
			// set CGRAM address
			lcd_set_CGRAM_addr( (addr << 3) | line );
			// write data
			lcd_write_data(data[line]);
		}
	}
		
}

/**
 * Loads 2-line font into CGRAM.
 * source of the font: http://woodsgood.ca/projects/2015/02/17/big-font-lcd-characters/ 
 */
void lcd_load_wooduino_font(void)
{
	/* custom characters */
	int custom_font[8][8] = {  
      { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00 },  
      { 0x18, 0x1C, 0x1E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F },  
      { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x07, 0x03 },  
      { 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F },  
      { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1E, 0x1C, 0x18 },  
      { 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x1F, 0x1F }, 
      { 0x1F, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x1F },  
      { 0x03, 0x07, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F }  
	};
	
	for(int i = 0; i<8; i++)
	{
		lcd_save_custom_char(i,custom_font[i]);
	}
	
	wooduino_font_loaded = 1;
		
}

void lcd_write_woodoino_char(int ch, int line, int pos)
{
	if(wooduino_font_loaded)
	{
		int char_width = 3;
		
		char wooduino_chars[10][6] = { 
      { 0x07, 0x00, 0x01, 0x02, 0x03, 0x04},  // 0
      { 0x00, 0x01, 0x20, 0x03, 0xFF, 0x03 }, // 1
      { 0x05, 0x05, 0x01, 0xFF, 0x06, 0x06 }, // 2
      { 0x00, 0x05, 0x01, 0x03, 0x06, 0x04 }, // 3
      { 0x02, 0x04, 0xFF, 0x20, 0x20, 0xFF }, // 4
      { 0xFF, 0x05, 0x05, 0x06, 0x06, 0x04 }, // 5
      { 0x07, 0x05, 0x05, 0x02, 0x06, 0x04 }, // 6
      { 0x00, 0x00, 0x01, 0x20, 0x07, 0x20 }, // 7
      { 0x02, 0x05, 0x04, 0x07, 0x06, 0x01 }, // 8
      { 0x07, 0x05, 0x01, 0x06, 0x06, 0x04 }, // 9
		};
		
		if( line>0 && line<4 && pos<20 )
		{
			for(int rows=0; rows<2; rows++)
			{
				for(int cols=0;cols<char_width;cols++)
				{
					lcd_set_position(line-1,pos);
					lcd_write_data(wooduino_chars[ch][rows*char_width+cols]);
					pos+=1;
				}
				line += 1;
				pos-=char_width;
			}
		}
		lcd_set_position(line-2,pos+char_width);
	}
}


