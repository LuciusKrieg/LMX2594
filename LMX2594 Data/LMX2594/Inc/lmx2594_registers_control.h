#ifndef LMX2594_REGISTERS_CONTROL_H_
#define LMX2594_REGISTERS_CONTROL_H_

#include <stm32f4xx_hal.h>

typedef struct {
	SPI_HandleTypeDef* hspi;
	GPIO_TypeDef* cs_port;
	uint16_t cs_n;
} LMX2594_SPI_HandleTypeDef;

void LMX2594_WriteRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t registeraddress, uint16_t data);
uint16_t LMX2594_ReadRegister(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, uint8_t registeraddress);

#endif /* LMX2594_REGISTERS_CONTROL_H_ */
