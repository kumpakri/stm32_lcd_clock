/**
 ******************************************************************************
 * @file           : LCD_lib.c
 * @brief          : Library for 2004A LCD display (SPLC780 controller)
 * @author 				 : kumpakri
 * @date					 : 30 Jul 2018
 ******************************************************************************
 */
	
#include "LCD_lib.h"

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
	
	HAL_Delay(20);
		
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(20);
		
}
	
void lcd_set_position(uint8_t line, uint8_t pos)
{
	/* line 0 starts at 0x00 ~  0 
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
		lcd_send_cmd( CMD_SET_DDRAM | data );
	}
}


