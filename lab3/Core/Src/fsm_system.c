/*
 * fsm_system.c
 *
 *  Created on: Nov 17, 2024
 *      Author: VO HOANG HUY
 */
#include "fsm_system.h"
#include "global.h"
#include "button.h"
#include "traffic_light.h"
#include "control_7SEG.h"
#include "traffic_buffer.h"
#include "fsm_traffic_blink.h"


void fsm_system_run(){
	switch(status_system){
		case INIT:
			status_system = MODE1;
			break;
		case MODE1:
			status_traffic_horizontal = display_traffic_horizontal;
			status_traffic_vertical = display_traffic_vertical;
			status_7SEG_horizontal = display_countDown_horizontal;
			status_7SEG_vertical = display_countDown_vertical;
			if(isButton1Pressed() == 1){
				status_system = MODE2;
			}
			break;
		case MODE2:
			status_traffic_horizontal = modifying_led_red_horizontal;
			status_traffic_vertical = modifying_led_red_vertical;
			status_7SEG_horizontal = display_mode02;
			status_7SEG_vertical = display_time_value;

			if(isButton2Pressed() == 1){
				time_red_horizontal++;
				time_red_vertical++;
			}

			_7SEG_buffer_vertical[0] = time_red_vertical/10;
			_7SEG_buffer_vertical[1] = time_red_vertical%10;

			if(isButton3Pressed() == 1){
				time_red_horizontal_temp = time_red_horizontal;
				time_red_vertical_temp = time_red_vertical;
			}

			if(isButton1Pressed() == 1){
				status_system = MODE3;
			}
			break;
		case MODE3:
			status_traffic_horizontal = modifying_led_yellow_horizontal;
			status_traffic_vertical = modifying_led_yellow_vertical;
			status_7SEG_horizontal = display_mode03;
			status_7SEG_vertical = display_time_value;

			if(isButton2Pressed() == 1){
				time_yellow_horizontal++;
				time_yellow_vertical++;
			}

			_7SEG_buffer_vertical[0] = time_yellow_vertical/10;
			_7SEG_buffer_vertical[1] = time_yellow_vertical%10;

			if(isButton3Pressed() == 1){
				time_yellow_horizontal_temp = time_yellow_horizontal;
				time_yellow_vertical_temp = time_yellow_vertical;
			}

			if(isButton1Pressed() == 1){
				status_system = MODE4;
			}
			break;
		case MODE4:
			status_traffic_horizontal = modifying_led_green_horizontal;
			status_traffic_vertical = modifying_led_green_vertical;
			status_7SEG_horizontal = display_mode04;
			status_7SEG_vertical = display_time_value;

			if(isButton2Pressed() == 1){
				time_green_horizontal++;
				time_green_vertical++;
			}

			_7SEG_buffer_vertical[0] = time_green_vertical/10;
			_7SEG_buffer_vertical[1] = time_green_vertical%10;

			if(isButton3Pressed() == 1){
				time_green_horizontal_temp = time_green_horizontal;
				time_green_vertical_temp = time_green_vertical;
			}

			if(isButton1Pressed() == 1){
				status_traffic_blink_horizontal = init_horizontal;
				status_traffic_blink_vertical = init_vertical;
				status_system = INIT;
			}
			break;
	}
}
