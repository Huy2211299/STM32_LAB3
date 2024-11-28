/*
 * fsm_traffic_a.c
 *
 *  Created on: Nov 18, 2024
 *      Author: VO HOANG HUY
 */
#include <fsm_traffic_horizontal.h>
#include "main.h"
#include "control_7SEG.h"
#include "fsm_traffic_blink.h"
#include "software_timer.h"
#include "traffic_light.h"

int status_traffic_horizontal = display_traffic_horizontal;

void fsm_traffic_horizontal_run(){
	switch(status_traffic_horizontal){
		case display_traffic_horizontal:
			fsm_traffic_blink_horizontal_run();
			break;
		case modifying_led_red_horizontal:
			offGreenYellow_horizontal();
			if(timer8_flag == 1){
				toggleRed_horizontal();
				setTimer8(500);
			}
			break;
		case modifying_led_yellow_horizontal:
			offGreenRed_horizontal();
			if(timer8_flag == 1){
				toggleYellow_horizontal();
				setTimer8(500);
			}
			break;
		case modifying_led_green_horizontal:
			offRedYellow_horizontal();
			if(timer8_flag == 1){
				toggleGreen_horizontal();
				setTimer8(500);
			}
			break;
		default:
			break;
	}
}
