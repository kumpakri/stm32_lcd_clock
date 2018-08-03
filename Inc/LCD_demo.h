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

extern int clock_ok;

void hello_world_demo(void);

void four_line_demo(void);

void start_clock(int h10, int h1, int m10, int m1);

#endif /* __LCD_DEMO_H */
