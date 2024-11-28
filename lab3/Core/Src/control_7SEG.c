/*
 * control_7SEG.c
 *
 *  Created on: Nov 17, 2024
 *      Author: VO HOANG HUY
 */
#include "control_7SEG.h"
#include "main.h"
#include "traffic_buffer.h"

void update7SEG_horizontal(int index_horizontal){
	switch(index_horizontal){
		case 0:
			display7SEG_horizontal(_7SEG_buffer_horizontal[0]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
			break;
		case 1:
			display7SEG_horizontal(_7SEG_buffer_horizontal[1]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
			break;
	}
}

void update7SEG_vertical(int index_vertical){
	switch(index_vertical){
		case 0:
			display7SEG_vertical(_7SEG_buffer_vertical[0]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
			break;
		case 1:
			display7SEG_vertical(_7SEG_buffer_vertical[1]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
			break;
	}
}
