#ifndef LMX2594_IN_PAIR_H_
#define LMX2594_IN_PAIR_H_

#include "lmx2594.h"

typedef struct {
    LMX2594_HandleTypeDef* lmx2594_a;
    LMX2594_HandleTypeDef* lmx2594_b;
} PAIR_OF_LMX2594_HandleTypeDef;

void LMX2594_IN_PAIR_Init(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594);

void LMX2594_IN_PAIR_Chip_Power(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, uint8_t chip_power);

void LMX2594_IN_PAIR_Out_Power(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, uint8_t out_power);

void LMX2594_IN_PAIR_Set_Freq(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, double fout_b);

#endif /* LMX2594_IN_PAIR_H_ */
