#include "lmx2594_com_control.h"

void LMX2594_COM_WriteDigit(UART_HandleTypeDef* huart, uint64_t writingdata) {
    uint8_t* bytePointer = (uint8_t*)&writingdata;
    for (uint8_t i = 0; i < 8; i++) HAL_UART_Transmit(huart, &bytePointer[i], 1, 0xFFFF);
}
void LMX2594_COM_WriteDouble(UART_HandleTypeDef* huart, double writingdata) {
    uint8_t* bytePointer = (uint8_t*)&writingdata;
    for (uint8_t i = 0; i < 8; i++) HAL_UART_Transmit(huart, &bytePointer[i], 1, 0xFFFF);
}

uint64_t LMX2594_COM_ReadDigit(UART_HandleTypeDef* huart) {
    uint64_t readingdata = 0;
    uint8_t* bytePointer = (uint8_t*)&readingdata;
    for (uint8_t i = 0; i < 8; i++) HAL_UART_Receive(huart, &bytePointer[i], 1, 0xFFFF);
    return readingdata;
}
double LMX2594_COM_ReadDouble(UART_HandleTypeDef* huart) {
    double readingdata = 0;
    uint8_t* bytePointer = (uint8_t*)&readingdata;
    for (uint8_t i = 0; i < 8; i++) HAL_UART_Receive(huart, &bytePointer[i], 1, 0xFFFF);
    return readingdata;
}
