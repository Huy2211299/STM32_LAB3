#include "global.h"

//////////////////////////// RED-AMBER-GREEN PROCESS //////////////////////////////////////////////
COLOR_STATE state = INIT;
int RED_TIMER = 5;
int AMBER_TIMER = 2;
int GREEN_TIMER = 3;
int buffer1[BUFFER_SIZE];
void setBuffer1_Default(){
	buffer1[RED] = RED_TIMER;
	buffer1[AMBER] = AMBER_TIMER;
	buffer1[GREEN] = GREEN_TIMER;
}
int buffer2[BUFFER_SIZE];
void setBuffer1(COLOR color, int color_timer){
	buffer1[color] = color_timer;
}
void setBuffer2(){
	buffer2[RED] = buffer1[AMBER] + buffer1[GREEN];
	buffer2[AMBER] = buffer1[AMBER];
	buffer2[GREEN] = buffer1[RED] - buffer1[AMBER];
	//A+B+C = (B + C) + B + (A - B)
}
void setTraffic1(uint8_t red, uint8_t amber, uint8_t green){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, red);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, amber);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, green);
}
void setTraffic2(uint8_t red, uint8_t amber, uint8_t green){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, red);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, amber);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, green);
}
/////////////////////////////////////////////// 7 SEGMENT LED PROCESS /////////////////////////////////////////////////
uint8_t EN = 0;
int CD1 = 0;
int CD2 = 0;
void helpDisplaySeg(int a, int b, int c, int d, int e, int f, int g){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, a);
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, b);
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, c);
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, d);
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, e);
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, f);
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, g);
}
void displaySeg(int num){
	switch(num){
	case 0:
		helpDisplaySeg(0, 0, 0, 0, 0, 0, 1);
		break;
	case 1:
		helpDisplaySeg(1, 0, 0, 1, 1, 1, 1);
		break;
	case 2:
		helpDisplaySeg(0, 0, 1, 0, 0, 1, 0);
		break;
	case 3:
		helpDisplaySeg(0, 0, 0, 0, 1, 1, 0);
		break;
	case 4:
		helpDisplaySeg(1, 0, 0, 1, 1, 0, 0);
		break;
	case 5:
		helpDisplaySeg(0, 1, 0, 0, 1, 0, 0);
		break;
	case 6:
		helpDisplaySeg(0, 1, 0, 0, 0, 0, 0);
		break;
	case 7:
		helpDisplaySeg(0, 0, 0, 1, 1, 1, 1);
		break;
	case 8:
		helpDisplaySeg(0, 0, 0, 0, 0, 0, 0);
		break;
	case 9:
		helpDisplaySeg(0, 0, 0, 0, 1, 0, 0);
		break;
	default: break;
	}
}

void displaySegProcess(int CD1, int CD2){
	switch(EN){
	case 0:
		displaySeg(CD1/10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 1:
		displaySeg(CD1%10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 2:
		displaySeg(CD2/10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		break;
	case 3:
		displaySeg(CD2%10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		break;
	default: break;
	}
	EN = (EN+1) % 4;
}
