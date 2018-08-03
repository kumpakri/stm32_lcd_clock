/**
 ******************************************************************************
 * @file           : LCD_demo.h
 * @brief          : demo programs for LCD display header file.
 * @author 				 : kumpakri
 * @date					 : 30 Jul 2018
 ******************************************************************************
 */
	
#ifndef __LCD_DEMO_H
#define __LCD_DEMO_H

#include "stm32f4xx_hal.h"

extern uint32_t h10;
extern uint32_t h1;
extern uint32_t m10;
extern uint32_t m1; 
extern uint32_t s10;
extern uint32_t s1;

extern uint32_t start_push;
extern uint32_t edit;
extern uint32_t to_be_served;

void hello_world_demo(void);

void four_line_demo(void);

void start_clock(uint32_t h10_s, uint32_t h1_s, uint32_t m10_s, uint32_t m1_s);

#endif /* __LCD_DEMO_H */
