/*
 * command_parser.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "main.h"
#include "software_timer.h"
#include "uart.h"

#define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern int cmdFlag;
extern int cmdState;

#define		RSTFlag					5		//RST
#define		OKFlag					6		//OK

#define 	OK			7
#define 	RST 		8
#define 	checkState	9

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart);
void command_parser_fsm();


#endif /* INC_COMMAND_PARSER_H_ */
