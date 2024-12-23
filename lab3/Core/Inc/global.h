/*
 * global.h
 *
 *  Created on: Oct 29, 2024
 *      Author: VO HOANG HUY
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
/*
extern int status_system;

#define 	INIT 	0
#define		MODE1	1
#define		MODE2	2
#define		MODE3	3
#define		MODE4	4

extern int time_red_horizontal;
extern int time_green_horizontal;
extern int time_yellow_horizontal;

extern int time_red_horizontal_temp;
extern int time_green_horizontal_temp;
extern int time_yellow_horizontal_temp;

extern int time_red_vertical;
extern int time_green_vertical;
extern int time_yellow_vertical;

extern int time_red_vertical_temp;
extern int time_green_vertical_temp;
extern int time_yellow_vertical_temp;

extern int index_horizontal;
extern int index_vertical;
*/
#include "main.h"
#include "button.h"
#include <stdint.h>
//////////////////////////// RED-AMBER-GREEN PROCESS //////////////////////////////////////////////
#define BLINK_TIME 500
typedef enum{
	INIT,
	RED_GREEN,
	RED_AMBER,
	GREEN_RED,
	AMBER_RED,
	RED_MAN,
	AMBER_MAN,
	GREEN_MAN
} COLOR_STATE;
typedef enum{
	RED,
	AMBER,
	GREEN,
} COLOR;
extern COLOR_STATE state;
extern int RED_TIMER;
extern int AMBER_TIMER;
extern int GREEN_TIMER;
#define BUFFER_SIZE 4
extern int buffer1[BUFFER_SIZE];
extern int buffer2[BUFFER_SIZE];
void setBuffer1(COLOR color, int color_timer);
void setBuffer1_Default();
void setBuffer2();
void setTraffic1(uint8_t red, uint8_t amber, uint8_t green);
void setTraffic2(uint8_t red, uint8_t amber, uint8_t green);

///////////////////////////// 7 SEGMENT LED PROCESS /////////////////////
#define LED_CYCLE 100
extern uint8_t EN;
extern int CD1;
extern int CD2;
void displaySeg(int num);
void displayBCD();
void displaySegProcess(int CD1, int CD2);
#endif /* INC_GLOBAL_H_ */
