/*
 * fsm_traffic_vertical.c
 *
 *  Created on: Nov 18, 2024
 *      Author: VO HOANG HUY
 */
#include "fsm_traffic_vertical.h"
#include "software_timer.h"
#include "traffic_light.h"
#include "fsm_traffic_blink.h"

int status_traffic_vertical = display_traffic_vertical;

void fsm_traffic_vertical_run(){
	switch(status_traffic_vertical){
		case display_traffic_vertical:
			fsm_traffic_blink_vertical_run();
			break;
		case modifying_led_red_vertical:
			offGreenYellow_vertical();
			if(timer7_flag == 1){
				toggleRed_vertical();
				setTimer7(500);
			}
			break;
		case modifying_led_yellow_vertical:
			offGreenRed_vertical();
			if(timer7_flag == 1){
				toggleYellow_vertical();
				setTimer7(500);
			}
			break;
		case modifying_led_green_vertical:
			offRedYellow_vertical();
			if(timer7_flag == 1){
				toggleGreen_vertical();
				setTimer7(500);
			}
			break;
		default:
			break;
	}
}

