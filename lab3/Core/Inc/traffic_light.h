/*
 * traffic.h
 *
 *  Created on: Nov 18, 2024
 *      Author: VO HOANG HUY
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

void setRed_horizontal();
void setGreen_horizontal();
void setYellow_horizontal();

void setRed_vertical();
void setGreen_vertical();
void setYellow_vertical();

void toggleLedRed();
void toggleRed_horizontal();
void toggleGreen_horizontal();
void toggleYellow_horizontal();

void toggleRed_vertical();
void toggleGreen_vertical();
void toggleYellow_vertical();

void offAllLed_horizontal();
void offGreenYellow_horizontal();
void offGreenRed_horizontal();
void offRedYellow_horizontal();

void offAllLed_vertical();
void offGreenYellow_vertical();
void offGreenRed_vertical();
void offRedYellow_vertical();

void display7SEG_horizontal(int num);
void display7SEG_vertical(int num);

#endif /* INC_TRAFFIC_H_ */
