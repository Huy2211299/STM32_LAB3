/*
 * software_timer.h
 *
 *  Created on: Oct 29, 2024
 *      Author: VO HOANG HUY
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"
#define TICK 10

//void setFlag(int *timerFlag,int set);
//void setTimer(int *timer,int time);
//void timerRun(int *timer, int *timerFlag);
//int isTimerFlag(int *timerFlag);
////////////////////// RED-AMBER-GREEN PROCESS /////////////////////////
void setFlagCD(int set);
void setTimerCD(int time);
void timerRunCD();
int isTimerFlagCD();
////////////////////// 7 SEGMENT LED PROCESS ///////////////////////////

void setFlagSeg(int set);
void setTimerSeg(int time);
void timerRunSeg();
int isTimerFlagSeg();

#endif /* INC_SOFTWARE_TIMER_H_ */
