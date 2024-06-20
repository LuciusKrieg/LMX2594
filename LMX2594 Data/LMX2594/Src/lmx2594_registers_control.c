#include "lmx2594_registers_control.h"

void LMX2594_WriteRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t registeraddress, uint16_t data) {
    uint8_t pTxData[3] = { registeraddress & 0x7F, data >> 8, data };
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 0);
    HAL_SPI_Transmit(lmx2594_hspi->hspi, pTxData, 3, 2);
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 1);
}

uint16_t LMX2594_ReadRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t registeraddress) {
    uint8_t pTxData[3] = { 0x80 | (registeraddress & 0x7F), 0, 0 };
    uint8_t pRxData[3];
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 0);
    HAL_SPI_TransmitReceive(lmx2594_hspi->hspi, pTxData, pRxData, 3, 2);
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 1);
    return (pRxData[1] << 8) | pRxData[2];
}
