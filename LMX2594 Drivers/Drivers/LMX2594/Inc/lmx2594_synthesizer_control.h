#ifndef LMX2594_SYNTHESIZER_CONTROL_H_
#define LMX2594_SYNTHESIZER_CONTROL_H_

#include <math.h>
#include "lmx2594_parameters_control.h"

#define LMX2594_OUT_MUX_ChannelDivider 0
#define LMX2594_OUT_MUX_VCO            1
#define LMX2594_OUT_MUX_HiZ            3

#define LMX2594_MASH_ORDER_Integer     0
#define LMX2594_MASH_ORDER_Fractional1 1
#define LMX2594_MASH_ORDER_Fractional2 2
#define LMX2594_MASH_ORDER_Fractional3 3
#define LMX2594_MASH_ORDER_Fractional4 4

#define LMX2594_CPG0  0 << 4 | 0
#define LMX2594_CPG6  1 << 4 | 6
#define LMX2594_CPG12 3 << 4 | 12
#define LMX2594_CPG3  4 << 4 | 3
#define LMX2594_CPG9  5 << 4 | 9
#define LMX2594_CPG15 7 << 4 | 15

typedef struct {
    LMX2594_SPI_HandleTypeDef lmx2594_hspi;
    GPIO_TypeDef* led_port;
    uint16_t led_n;

    uint8_t outa_power;
    uint8_t outa_level;
    uint8_t outa_mux;
    uint8_t outb_power;
    uint8_t outb_level;
    uint8_t outb_mux;
    uint8_t mash_order;
    uint8_t cpg_value;

    double   fosc;
    uint32_t ndn;
    uint32_t ndnum;
    uint32_t ndden;
    double   fvco;
    uint16_t cd;
    double   fout;

    uint8_t chip_power;

    double time;
} LMX2594_HandleTypeDef;

void LMX2594_CONTROL_OUTA_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_power);
void LMX2594_CONTROL_OUTA_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_level);
void LMX2594_CONTROL_OUTA_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_mux);
void LMX2594_CONTROL_OUTB_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_power);
void LMX2594_CONTROL_OUTB_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_level);
void LMX2594_CONTROL_OUTB_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_mux);
void LMX2594_CONTROL_MASH_ORDER(LMX2594_HandleTypeDef* synthesizer, uint8_t mash_order);
void LMX2594_CONTROL_CPG_VALUE(LMX2594_HandleTypeDef* synthesizer, uint8_t cpg_value);

void LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(LMX2594_HandleTypeDef* synthesizer, uint32_t ndn, uint32_t ndnum, uint32_t ndden, uint16_t cd);

void LMX2594_CONTROL_CHIP_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t chip_power);
void LMX2594_CONTROL_CHIP_RESET(LMX2594_HandleTypeDef* synthesizer);

#endif /* LMX2594_SYNTHESIZER_CONTROL_H_ */
