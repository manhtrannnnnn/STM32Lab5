/*
 * uart.h
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */

#ifndef INC_UART_H_
#define INC_UART_H_
#include <command_parser.h>
#include <main.h>
#include <software_timer.h>


#define INIT		5
#define TRANSMIT 	6
#define LOOP		7

void uart_communication_fsm();
#endif /* INC_UART_H_ */
