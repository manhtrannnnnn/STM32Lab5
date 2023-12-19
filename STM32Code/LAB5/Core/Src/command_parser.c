/*
 * command_parser.c
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */

#include <command_parser.h>

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE] = {0};
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart){
	if(huart->Instance == USART2 ){
		buffer[index_buffer++]=temp;
		if( index_buffer == 30) index_buffer = 0;
		buffer_flag = 1;
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}

int cmdState = checkState;
int cmdFlag = 0;

void command_parser_fsm(){
	switch(cmdState){
	case checkState:
		if(buffer[index_buffer - 1]=='#' && buffer[index_buffer - 2] == 'T' && buffer[index_buffer - 3] == 'S' && buffer[index_buffer - 4] == 'R' && buffer[index_buffer - 5] == '!'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-5], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-4], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-3], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-2], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			buffer_flag = 1;
			cmdState = RST;
		}
		else if(buffer[index_buffer-1] == '#' && buffer[index_buffer-2] == 'K' && buffer[index_buffer-3] == 'O' && buffer[index_buffer-4] == '!'){
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-4], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-3], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-2], 1, 50);
			HAL_UART_Transmit(&huart2, &buffer[index_buffer-1], 1, 50);
			buffer_flag = 1;
			cmdState = OK;
		}
		break;
	case RST:
		buffer_flag = 0;
		cmdFlag = RSTFlag;
		cmdState = checkState;
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		break;
	case OK:
		buffer_flag = 0;
		cmdFlag = OKFlag;
		cmdState = checkState;
		HAL_UART_Transmit(&huart2, (void *) str, sprintf(str, "\r\n"), 1000);
		break;
	}
}
