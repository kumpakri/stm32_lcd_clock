
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
  /* USER CODE BEGIN 2 */
	
	/* Put string to LCD */
	//hello_world_demo();
	
	lcd_send_cmd(CMD_CURSOR_BLINK);
	lcd_send_cmd(CMD_SET_DISP_LEFT);
	
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

