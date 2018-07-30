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
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 1);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 1);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 1);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 1);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(500);
	
	// data 001110 fcn set
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 1);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 1);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 1);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(500);
	
	// data 000000010 return home
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 0);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 1);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(200);
	
	// data 00101010 write *
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 1);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 1);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 1);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 1);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(200);


	int i = 0;
	while( i < 3 )
	{
		// data 00010100 0x14 shift cursor right
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
		
		HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
		HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
		HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
		HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 1);
		HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 0);
		HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 1);
		HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 0);
		HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
		
		HAL_Delay(20);
		
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
		
		HAL_Delay(100);
		
		i = i+1;
	}
	
	
	// Write string
	
	char str[12] = "Hello World!";
	int i_str = 0;
	while( i_str < 12 )
	{
		
			HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
			HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 1);
			
			HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (str[i_str] & 0x80) >> 7 );
			HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (str[i_str] & 0x40) >> 6 );
			HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (str[i_str] & 0x20) >> 5 );
			HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (str[i_str] & 0x10) >> 4 );
			HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (str[i_str] & 0x08) >> 3 );
			HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (str[i_str] & 0x04) >> 2 );
			HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (str[i_str] & 0x02) >> 1 );
			HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (str[i_str] & 0x01) );
			
			HAL_Delay(20);
			
			HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
			
			HAL_Delay(200);
		
		i_str += 1;
	}
	
	i = 0;
	while( i < 3 )
	{
		// data 00010100 0x14 shift cursor right
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
		
		HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
		HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
		HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
		HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 1);
		HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 0);
		HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 1);
		HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 0);
		HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
		
		HAL_Delay(20);
		
		HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
		
		HAL_Delay(100);
		
		i = i+1;
	}
	
	// data 00101010 write *
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 1);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 1);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 1);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 1);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(5000);
	
	// data 00000001 clear display
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 0);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 0);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 1);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
	
	HAL_Delay(20);
	
	// data 00001111 0x0F display off
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 1);
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, 0);
	
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0);
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 1);
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 0);
	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);
	
	HAL_Delay(20);
	
	HAL_GPIO_WritePin(LCD_EN_GPIO_Port, LCD_EN_Pin, 0);
}
