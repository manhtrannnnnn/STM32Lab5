/*
 * software_timer.c
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */

#include<software_timer.h>
int counter = 0;
int timerFlag = 0;
void setTimer(int duration){
	counter = duration;
	timerFlag = 0;
}

void timerRun(){
	if(counter > 0){
		counter--;
		if(counter <= 0){
			timerFlag = 1;
		}
	}
}
