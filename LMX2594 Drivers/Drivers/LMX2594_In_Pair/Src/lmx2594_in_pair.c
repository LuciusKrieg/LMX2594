#include "lmx2594_in_pair.h"

void LMX2594_IN_PAIR_Init(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594) {
    LMX2594_CONTROL_CHIP_RESET(pair_of_lmx2594->lmx2594_a);
    LMX2594_CONTROL_CHIP_RESET(pair_of_lmx2594->lmx2594_b);
    LMX2594_CONTROL_CPG_VALUE(pair_of_lmx2594->lmx2594_a, LMX2594_CPG15);
    LMX2594_CONTROL_CPG_VALUE(pair_of_lmx2594->lmx2594_b, LMX2594_CPG3);
    LMX2594_WriteParameter(&pair_of_lmx2594->lmx2594_a->lmx2594_hspi, &LMX2594_CAL_CLK_DIV, 0);
    LMX2594_WriteParameter(&pair_of_lmx2594->lmx2594_b->lmx2594_hspi, &LMX2594_CAL_CLK_DIV, 0);
    LMX2594_CONTROL_MASH_ORDER(pair_of_lmx2594->lmx2594_a, LMX2594_MASH_ORDER_Fractional3);
    LMX2594_CONTROL_MASH_ORDER(pair_of_lmx2594->lmx2594_b, LMX2594_MASH_ORDER_Integer);
    pair_of_lmx2594->lmx2594_a->fosc = 100000000;
    pair_of_lmx2594->lmx2594_b->fosc = 100000000;
    LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(pair_of_lmx2594->lmx2594_a, 96, 0, 1, 96);
    LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(pair_of_lmx2594->lmx2594_b, 96, 0, 1, 96);
}

void LMX2594_IN_PAIR_Chip_Power(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, uint8_t chip_power) {
    LMX2594_CONTROL_CHIP_POWER(pair_of_lmx2594->lmx2594_a, chip_power);
    LMX2594_CONTROL_CHIP_POWER(pair_of_lmx2594->lmx2594_b, chip_power);
}

void LMX2594_IN_PAIR_Out_Power(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, uint8_t out_power) {
	if (out_power == 1) {
		LMX2594_CONTROL_OUTA_POWER(pair_of_lmx2594->lmx2594_b, pair_of_lmx2594->lmx2594_b->fout >= 7500000000);
		LMX2594_CONTROL_OUTB_POWER(pair_of_lmx2594->lmx2594_b, pair_of_lmx2594->lmx2594_b->fout <  7500000000);
	}
	if (out_power == 0) {
		LMX2594_CONTROL_OUTA_POWER(pair_of_lmx2594->lmx2594_b, 0);
		LMX2594_CONTROL_OUTB_POWER(pair_of_lmx2594->lmx2594_b, 0);
	}
}

void LMX2594_IN_PAIR_Out_Level(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, uint8_t out_level) {
	LMX2594_CONTROL_OUTA_LEVEL(pair_of_lmx2594->lmx2594_b, out_level);
	LMX2594_CONTROL_OUTB_LEVEL(pair_of_lmx2594->lmx2594_b, out_level);
}

void LMX2594_IN_PAIR_Set_Freq(PAIR_OF_LMX2594_HandleTypeDef* pair_of_lmx2594, double fout_b) {
    uint32_t ndden_a = 0xFFFFFFFF;
    double fosc_a = 100000000;
    uint32_t ndnum_b = 0;
    uint32_t ndden_b = 1;
    uint16_t cd_a = 96;
    uint16_t cd_b;

    if (fout_b >= 7500000000) cd_b = 1;
    else if (fout_b >= 3750000000) cd_b = 2;
    else if (fout_b >= 1875000000) cd_b = 4;
    else if (fout_b >= 1250000000) cd_b = 6;
    else if (fout_b >= 937500000)  cd_b = 8;
    else if (fout_b >= 625000000)  cd_b = 12;
    else if (fout_b >= 468750000)  cd_b = 16;
    else if (fout_b >= 312500000)  cd_b = 24;
    else if (fout_b >= 234375000)  cd_b = 32;
    else if (fout_b >= 156250000)  cd_b = 48;
    else if (fout_b >= 117187500)  cd_b = 64;
    else if (fout_b >= 78125000)   cd_b = 96;
    else if (fout_b >= 58593750)   cd_b = 128;
    else if (fout_b >= 39062500)   cd_b = 192;
    else if (fout_b >= 29296875)   cd_b = 256;
    else if (fout_b >= 19531250)   cd_b = 384;
    else if (fout_b >= 9765625)    cd_b = 768;
    else                           cd_b = 0;

    double fvco_b = fout_b * cd_b;
    uint32_t ndn_b = round(fvco_b * 12075858607 / 1000000000000000000);
    double fosc_b = fvco_b / ndn_b;
    double fout_a = fosc_b;
    double fvco_a = fout_a * cd_a;
    double nd_a = fvco_a / fosc_a;
    uint32_t ndn_a = floor(nd_a);
    uint32_t ndnum_a = round((nd_a - ndn_a) * ndden_a);

    pair_of_lmx2594->lmx2594_a->fosc = fosc_a;
    pair_of_lmx2594->lmx2594_b->fosc = fosc_b;
    LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(pair_of_lmx2594->lmx2594_a, ndn_a, ndnum_a, ndden_a, cd_a);
    LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(pair_of_lmx2594->lmx2594_b, ndn_b, ndnum_b, ndden_b, cd_b);
	LMX2594_CONTROL_OUTA_POWER(pair_of_lmx2594->lmx2594_b, 0);
	LMX2594_CONTROL_OUTB_POWER(pair_of_lmx2594->lmx2594_b, 0);
}
