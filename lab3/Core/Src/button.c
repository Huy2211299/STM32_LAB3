/*
 * button.c
 *
 *  Created on: Oct 29, 2024
 *      Author: VO HOANG HUY
 */
#include "button.h"

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress = 300;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}
void getKeyInput(){
	for(int i = 0; i < 3; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if(i == 0)KeyReg2[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		if(i == 1)KeyReg2[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		if(i == 2)KeyReg2[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					//TODO
					if(i == 0)button1_flag = 1;
					if(i == 1)button2_flag = 1;
					if(i == 2)button3_flag = 1;
					TimerForKeyPress = 200;
				}
			}
			else{
				TimerForKeyPress--;
				if(TimerForKeyPress == 0){
					//TODO
					TimerForKeyPress = 200;
					if(KeyReg2[i] == PRESSED_STATE){
						if(i == 0)button1_flag = 1;
						if(i == 1)button2_flag = 1;
						if(i == 2)button3_flag = 1;
					}
				}
			}
		}
	}
}

