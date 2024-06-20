#include "lmx2594_parameters_control.h"

void LMX2594_WriteParameter(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, paramdata_t* parameter, uint64_t value) {
    for (uint8_t i = 0; i <= 2; i++) {
        if (parameter->data[i].width) {
            uint16_t mask = 0;
            uint8_t valueshift = 0;
            for (uint8_t j = 1; j <= parameter->data[i].width; j++) { mask = (mask << 1) | 1; }
            for (uint8_t j = i + 1; j <= 2; j++) { valueshift = valueshift + parameter->data[j].width; }
            LMX2594_WriteRegister(lmx2594_hspi, parameter->data[i].regnumber,
                (LMX2594_ReadRegister(lmx2594_hspi, parameter->data[i].regnumber) &
                ~(mask << parameter->data[i].shift)) |
                (((value >> valueshift) & mask) << parameter->data[i].shift)
            );
        }
    }
}

uint64_t LMX2594_ReadParameter(LMX2594_SPI_HandleTypeDef* lmx2594_hspi, paramdata_t* parameter) {
    uint16_t valuearray[3] = { 0, 0, 0 };
    for (uint8_t i = 0; i <= 2; i++) {
        if (parameter->data[i].width) {
            uint16_t mask = 0;
            for (uint8_t j = 1; j <= parameter->data[i].width; j++) { mask = (mask << 1) | 1; }
            valuearray[i] = (LMX2594_ReadRegister(lmx2594_hspi,
				parameter->data[i].regnumber) >> parameter->data[i].shift) & mask
			;
        }
    }
    return ((uint64_t)valuearray[0] << 32) | (valuearray[1] << 16) | valuearray[2];
}
