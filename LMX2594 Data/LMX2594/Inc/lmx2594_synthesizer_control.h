#ifndef LMX2594_SYNTHESIZER_CONTROL_H_
#define LMX2594_SYNTHESIZER_CONTROL_H_

#include <math.h>
#include "lmx2594_parameters_control.h"

typedef struct {
	LMX2594_SPI_HandleTypeDef* lmx2594_hspi;

    GPIO_TypeDef* led_port;
    uint16_t led_n;

    uint8_t power;
	uint8_t ndmode;
	uint8_t ndcorrect;

    double Fosc;
    uint32_t NDN;
    uint32_t NDNUM;
    uint32_t NDDEN;
    double Fvco;
    uint16_t CD;
    double Fout;
} LMX2594_HandleTypeDef;

#define LMX2594_OUT_MUX_ChannelDivider 0
#define LMX2594_OUT_MUX_VCO            1
#define LMX2594_OUT_MUX_HiZ            3
#define LMX2594_ND_MODE_Integer        0
#define LMX2594_ND_MODE_Fractional1    1
#define LMX2594_ND_MODE_Fractional2    2
#define LMX2594_ND_MODE_Fractional3    3
#define LMX2594_ND_MODE_Fractional4    4

void LMX2594_CONTROL_CHIP_RESET(LMX2594_HandleTypeDef* synthesizer);
void LMX2594_CONTROL_CHIP_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power);

void LMX2594_CONTROL_OUTA_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power);
void LMX2594_CONTROL_OUTB_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power);

void LMX2594_CONTROL_OUTA_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t level);
void LMX2594_CONTROL_OUTB_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t level);

void LMX2594_CONTROL_OUTA_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t mux);
void LMX2594_CONTROL_OUTB_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t mux);

void LMX2594_CONTROL_ND_MODE(LMX2594_HandleTypeDef* synthesizer, uint8_t ndmode);

void LMX2594_CONTROL_CPG_VALUE(LMX2594_HandleTypeDef* synthesizer, uint8_t cpgvalue);

void LMX2594_CONTROL_ND_VALUE(LMX2594_HandleTypeDef* synthesizer, uint32_t ndnvalue, uint32_t ndnumvalue, uint32_t nddenvalue);

void LMX2594_CONTROL_VCO_RECAL(LMX2594_HandleTypeDef* synthesizer);

void LMX2594_CONTROL_CD_VALUE(LMX2594_HandleTypeDef* synthesizer, uint16_t cdvalue);

#endif /* LMX2594_SYNTHESIZER_CONTROL_H_ */
