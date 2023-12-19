/*
 * uart.c
 *
 *  Created on: Dec 19, 2023
 *      Author: ASUS TUF
 */


#include<uart.h>

int uartState = INIT;
uint32_t ADC_value = 0;

void uart_communication_fsm(){
	switch(uartState){
		case INIT:
			if(cmdFlag == RSTFlag){
				HAL_ADC_Start(&hadc1);
				uartState = TRANSMIT;
				ADC_value = HAL_ADC_GetValue(&hadc1);
			}
			break;
		case TRANSMIT:
			if(cmdFlag == RSTFlag){
				HAL_UART_Transmit(&huart2 , (void*)str , sprintf(str,"!ADC=%ld#\r\n", ADC_value ), 1000);
				HAL_GPIO_TogglePin( LED_RED_GPIO_Port , LED_RED_Pin );
				uartState = LOOP;
				setTimer(300);
			}
			else if(cmdFlag == OKFlag){
				uartState = INIT;
			}
			break;
		case LOOP:
			if(timerFlag){
				ADC_value = HAL_ADC_GetValue(&hadc1);
				HAL_UART_Transmit (& huart2 , ( void *) str , sprintf (str , "!ADC =%ld#\r\n", ADC_value ), 1000) ;
				HAL_GPIO_TogglePin( LED_RED_GPIO_Port , LED_RED_Pin );
				setTimer(300);
			}
			if(cmdFlag == OKFlag){
				uartState = INIT;
			}
			break;
	}
}
