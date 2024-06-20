#ifndef LMX2594_PARAMETERS_CONTROL_H_
#define LMX2594_PARAMETERS_CONTROL_H_

#include "lmx2594_registers_control.h"
#include "lmx2594_parameters.h"

void LMX2594_WriteParameter(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, paramdata_t* parameter, uint64_t value);
uint64_t LMX2594_ReadParameter(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, paramdata_t* parameter);

#endif /* LMX2594_PARAMETERS_CONTROL_H_ */
