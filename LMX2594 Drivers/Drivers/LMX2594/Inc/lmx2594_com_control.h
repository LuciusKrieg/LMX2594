#ifndef LMX2594_COM_CONTROL_H_
#define LMX2594_COM_CONTROL_H_

#include <stm32f4xx_hal.h>

void LMX2594_COM_WriteDigit(UART_HandleTypeDef* huart, uint64_t writingdata);
void LMX2594_COM_WriteDouble(UART_HandleTypeDef* huart, double writingdata);

uint64_t LMX2594_COM_ReadDigit(UART_HandleTypeDef* huart);
double LMX2594_COM_ReadDouble(UART_HandleTypeDef* huart);

#endif /* LMX2594_COM_CONTROL_H_ */
