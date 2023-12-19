/*
 * software_timer.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


extern int counter;
extern int timerFlag;

void setTimer(int duration);
void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
