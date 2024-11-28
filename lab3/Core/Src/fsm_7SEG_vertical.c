/*
 * fsm_7SEG.c
 *
 *  Created on: Nov 17, 2024
 *      Author: VO HOANG HUY
 */
#include "fsm_7SEG_vertical.h"
#include "software_timer.h"
#include "global.h"
#include "control_7SEG.h"

int status_7SEG_vertical = display_countDown_vertical;

void fsm_7SEG_vertical_run(){
	switch(status_7SEG_vertical){
		case display_countDown_vertical:
			if(timer6_flag == 1){
				update7SEG_vertical(index_vertical++);
				if(index_vertical == 2) index_vertical = 0;
				setTimer6(200);
			}
			break;
		case display_time_value:
			if(timer6_flag == 1){
				update7SEG_vertical(index_vertical++);
				if(index_vertical == 2) index_vertical = 0;
				setTimer6(200);
			}
			break;
		default:
			break;
	}
}