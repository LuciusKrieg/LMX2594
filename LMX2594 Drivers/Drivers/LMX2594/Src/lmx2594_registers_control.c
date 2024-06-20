#include "lmx2594_registers_control.h"

void LMX2594_WriteRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t reg_n, uint16_t value) {
    uint8_t data[3] = { reg_n & 0x7F, value >> 8, value };
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 0);
    HAL_SPI_Transmit(lmx2594_hspi->hspi, data, 3, 2);
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 1);
}

uint16_t LMX2594_ReadRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t reg_n) {
    uint8_t data[3] = { 0x80 | (reg_n & 0x7F), 0, 0 };
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 0);
    HAL_SPI_TransmitReceive(lmx2594_hspi->hspi, data, data, 3, 2);
    HAL_GPIO_WritePin(lmx2594_hspi->cs_port, lmx2594_hspi->cs_n, 1);
    return data[1] << 8 | data[2];
}
