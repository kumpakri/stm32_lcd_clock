
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
	* @date					  : 29 Jul 2018
  ******************************************************************************
  */
	
	
#include "main.h"
#include "stm32f4xx_hal.h"
#include "LCD_demo.h"
#include "LCD_lib.h"

void SystemClock_Config(void);
static void GPIO_Init(void);



/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  GPIO_Init();
	
	/* Initialize LCD display */
	lcd_init();
	lcd_send_cmd(CMD_CURSOR_BLINK);
	
  /* USER CODE BEGIN 2 */
	
	//hello_world_demo();
	//four_line_demo();
	
	
	
	/*
	* Custom Character
	* 1 1 1 1 1 
	* 1 1 1 1 1
	* 1 1 1 1 1
	* 1 1 1 1 1
	* 0 0 0 0 0
	* 0 0 0 0 0
	* 0 0 0 0 0 
	* 0 0 0 0 0 
	*
	* ~ data = {0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00}
	*/
	//int custom_char[8] = {0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00};
	//lcd_save_custom_char(0, custom_char);
	
	
	lcd_load_wooduino_font();
	
	//lcd_write_woodoino_char(1, 2, 5);
	
	//lcd_set_position(1,5);
	//lcd_write_data(0x00);
	//lcd_write_data(0x01);
	//lcd_write_data(0x20);
	//lcd_set_position(2,5);
	//lcd_write_data(0x03);
	//lcd_write_data(0xFF);
	//lcd_write_data(0x03);
	
	lcd_write_woodoino_char(1,2,5);
	lcd_write_woodoino_char(0,2,8);
	lcd_set_position(1,11);
	lcd_write_data(0x2E);
	lcd_set_position(2,11);
	lcd_write_data(0x2E);
	lcd_write_woodoino_char(5,2,12);
	lcd_write_woodoino_char(8,2,15);

	
	HAL_Delay(5000);
	
	lcd_send_cmd(CMD_CLEAR_DISPLAY);
	lcd_send_cmd(CMD_DISPLAY_OFF);
	
	
  while (1)
  {

  }

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /*Configure the main internal regulator output voltage*/
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /*Initializes the CPU, AHB and APB busses clocks*/
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;


    /*Initializes the CPU, AHB and APB busses clocks*/
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;


    /*Configure the Systick interrupt time*/
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /*Configure the Systick*/
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}


static void GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LCD_OUT_Pin|LCD_D0_Pin|LCD_D1_Pin|LCD_D2_Pin 
                          |LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin|LCD_D6_Pin 
                          |LCD_D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LCD_RS_Pin|LCD_RW_Pin|LCD_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LCD_IN_Pin */
  GPIO_InitStruct.Pin = LCD_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(LCD_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_OUT_Pin 
													LCD_D0_Pin 
													LCD_D1_Pin 
													LCD_D2_Pin 
                          LCD_D3_Pin 
													LCD_D4_Pin 
													LCD_D5_Pin 
													LCD_D6_Pin 
                          LCD_D7_Pin */
  GPIO_InitStruct.Pin = LCD_OUT_Pin|LCD_D0_Pin|LCD_D1_Pin|LCD_D2_Pin 
                          |LCD_D3_Pin|LCD_D4_Pin|LCD_D5_Pin|LCD_D6_Pin 
                          |LCD_D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	  /*Configure GPIO pins : LCD_RW_Pin*/
  GPIO_InitStruct.Pin = LCD_RW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_RS_Pin  LCD_EN_Pin */
  GPIO_InitStruct.Pin = LCD_RS_Pin|LCD_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

