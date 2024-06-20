#ifndef LMX2594_INIT_H_
#define LMX2594_INIT_H_

#include "lmx2594_synthesizer_control.h"

LMX2594_HandleTypeDef LMX2594_Init_Synthesizer(
    SPI_HandleTypeDef* hspi,
    GPIO_TypeDef* cs_port,
    uint16_t cs_n,
    GPIO_TypeDef* led_port,
    uint16_t led_n
);

#endif /* LMX2594_INIT_H_ */
