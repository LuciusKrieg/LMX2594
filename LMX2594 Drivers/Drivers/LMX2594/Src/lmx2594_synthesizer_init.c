#include <lmx2594_synthesizer_init.h>

LMX2594_HandleTypeDef LMX2594_Init_Synthesizer(
    SPI_HandleTypeDef* hspi,
    GPIO_TypeDef* cs_port,
    uint16_t cs_n,
    GPIO_TypeDef* led_port,
    uint16_t led_n
) {
    LMX2594_SPI_HandleTypeDef lmx2594_hspi = {
        .hspi = hspi,
        .cs_port = cs_port,
        .cs_n = cs_n
    };
    LMX2594_HandleTypeDef lmx2594 = {
        .lmx2594_hspi = lmx2594_hspi,
        .led_port = led_port,
        .led_n = led_n,
    };
    return lmx2594;
}
