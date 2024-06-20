#include "lmx2594_synthesizer_control.h"

void LMX2594_CONTROL_OUTA_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_power) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTA_PD, ~outa_power);
    synthesizer->outa_power = outa_power;
}
void LMX2594_CONTROL_OUTA_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_level) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTA_PWR, outa_level);
    synthesizer->outa_level = outa_level;
}
void LMX2594_CONTROL_OUTA_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t outa_mux) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTA_MUX, outa_mux);
    synthesizer->outa_mux = outa_mux;
}
void LMX2594_CONTROL_OUTB_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_power) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTB_PD, ~outb_power);
    synthesizer->outb_power = outb_power;
}
void LMX2594_CONTROL_OUTB_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_level) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTB_PWR, outb_level);
    synthesizer->outb_level = outb_level;
}
void LMX2594_CONTROL_OUTB_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t outb_mux) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_OUTB_MUX, outb_mux);
    synthesizer->outb_mux = outb_mux;
}
void LMX2594_CONTROL_MASH_ORDER(LMX2594_HandleTypeDef* synthesizer, uint8_t mash_order) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_MASH_ORDER, mash_order);
    synthesizer->mash_order = mash_order;
}
void LMX2594_CONTROL_CPG_VALUE(LMX2594_HandleTypeDef* synthesizer, uint8_t cpg_value) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_CPG, cpg_value >> 4);
    synthesizer->cpg_value = cpg_value & 0xF;
}

void LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(LMX2594_HandleTypeDef* synthesizer, uint32_t ndn, uint32_t ndnum, uint32_t ndden, uint16_t cd) {
    uint32_t start = 0;
    uint32_t end = 0;
    uint32_t summary = 0;

    CoreDebug->DEMCR &= ~CoreDebug_DEMCR_TRCENA_Msk;
    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CTRL &= ~DWT_CTRL_CYCCNTENA_Msk;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    __ASM volatile ("NOP");
    __ASM volatile ("NOP");
    __ASM volatile ("NOP");
    DWT->CYCCNT = 0;

    if ((ndnum < ndden) & (ndn + ndnum * 1.0 / ndden <= 524287)) {
        double fvco = synthesizer->fosc * (ndn + ndnum * 1.0 / ndden);
        uint8_t nd_min;
        uint8_t pfd_dly_sel;
        switch (synthesizer->mash_order) {
        case 0: if (fvco <= 12500000000) { nd_min = 28; pfd_dly_sel = 1; }
              else { nd_min = 32; pfd_dly_sel = 2; } break;
        case 1: if (fvco <= 10000000000) { nd_min = 28; pfd_dly_sel = 1; }
              else if (fvco > 12500000000) { nd_min = 36; pfd_dly_sel = 3; }
              else { nd_min = 32; pfd_dly_sel = 2; } break;
        case 2: if (fvco <= 10000000000) { nd_min = 32; pfd_dly_sel = 2; }
              else { nd_min = 36; pfd_dly_sel = 3; } break;
        case 3: if (fvco <= 10000000000) { nd_min = 36; pfd_dly_sel = 3; }
              else { nd_min = 40; pfd_dly_sel = 4; } break;
        case 4: if (fvco <= 10000000000) { nd_min = 44; pfd_dly_sel = 5; }
              else { nd_min = 48; pfd_dly_sel = 6; } break;
        }
        if ((ndn + ndnum * 1.0 / ndden) >= nd_min) {
            uint16_t cds[19] = { 1, 2, 4, 6, 8, 12, 16, 24, 32, 48, 64, 72, 96, 128, 192, 256, 384, 512, 768 };
            int8_t cd_n = -2;
            for (uint8_t i = 0; i < 19; i++) if (cd == cds[i]) cd_n = i - 1;
            if ((cd_n != -2) & ((cd_n < 3) | (fvco <= 11500000000))) {
                start = DWT->CYCCNT;
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_PFD_DLY_SEL, pfd_dly_sel);
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_PLL_N, ndn);
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_PLL_NUM, ndnum);
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_PLL_DEN, ndden);
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_SEG1_EN, cd > 2);
                LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_CHDIV, cd_n);
                LMX2594_CONTROL_OUTA_MUX(synthesizer, cd == 1 ? LMX2594_OUT_MUX_VCO : LMX2594_OUT_MUX_ChannelDivider);
                LMX2594_CONTROL_OUTB_MUX(synthesizer, cd == 1 ? LMX2594_OUT_MUX_VCO : LMX2594_OUT_MUX_ChannelDivider);
                end = DWT->CYCCNT;
                summary = summary + end - start;
                synthesizer->ndn = ndn;
                synthesizer->ndnum = ndnum;
                synthesizer->ndden = ndden;
                synthesizer->fvco = fvco;
                synthesizer->cd = cd;
                synthesizer->fout = fvco / cd;
                if (synthesizer->chip_power) {
                    start = DWT->CYCCNT;
                    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_FCAL_EN, 0);
                    uint16_t VCO_CORE;
                    uint64_t fCoreMin;
                    uint64_t fCoreMax;
                    uint16_t CCoreMin;
                    uint16_t CCoreMax;
                    uint16_t ACoreMin;
                    uint16_t ACoreMax;
                    uint16_t VCO_CAPCTRL_STRT;
                    uint16_t VCO_DACISET_STRT;
                    if ((fvco >= 11900000000) & (fvco <= 12100000000)) {
                        VCO_CORE = 4;
                        VCO_CAPCTRL_STRT = 1;
                        VCO_DACISET_STRT = 300;
                    }
                    else {
                        if (fvco <= 8600000000) {
                            VCO_CORE = 1; fCoreMin = 7500000000; fCoreMax = 8600000000; CCoreMin = 164; CCoreMax = 12; ACoreMin = 299; ACoreMax = 240;
                        }
                        else if (fvco <= 9800000000) {
                            VCO_CORE = 2; fCoreMin = 8600000000; fCoreMax = 9800000000; CCoreMin = 165; CCoreMax = 16; ACoreMin = 356; ACoreMax = 247;
                        }
                        else if (fvco <= 10800000000) {
                            VCO_CORE = 3; fCoreMin = 9800000000; fCoreMax = 10800000000; CCoreMin = 158; CCoreMax = 19; ACoreMin = 324; ACoreMax = 224;
                        }
                        else if (fvco <= 12000000000) {
                            VCO_CORE = 4; fCoreMin = 10800000000; fCoreMax = 12000000000; CCoreMin = 140; CCoreMax = 0; ACoreMin = 383; ACoreMax = 244;
                        }
                        else if (fvco <= 12900000000) {
                            VCO_CORE = 5; fCoreMin = 12000000000; fCoreMax = 12900000000; CCoreMin = 183; CCoreMax = 36; ACoreMin = 205; ACoreMax = 146;
                        }
                        else if (fvco <= 13900000000) {
                            VCO_CORE = 6; fCoreMin = 12900000000; fCoreMax = 13900000000; CCoreMin = 155; CCoreMax = 6; ACoreMin = 242; ACoreMax = 163;
                        }
                        else if (fvco <= 15000000000) {
                            VCO_CORE = 7; fCoreMin = 13900000000; fCoreMax = 15000000000; CCoreMin = 175; CCoreMax = 19; ACoreMin = 323; ACoreMax = 244;
                        }
                        VCO_CAPCTRL_STRT = round(CCoreMin - (CCoreMin - CCoreMax) * (fvco - fCoreMin) / (fCoreMax - fCoreMin));
                        VCO_DACISET_STRT = round(ACoreMin + (ACoreMax - ACoreMin) * (fvco - fCoreMin) / (fCoreMax - fCoreMin));
                    }
                    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_VCO_SEL, VCO_CORE);
                    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_VCO_CAPCTRL_STRT, VCO_CAPCTRL_STRT);
                    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_VCO_DACISET_STRT, VCO_DACISET_STRT);
                    HAL_GPIO_WritePin(synthesizer->led_port, synthesizer->led_n, 1);
                    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_FCAL_EN, 1);
                    while (LMX2594_ReadParameter(&synthesizer->lmx2594_hspi, &LMX2594_rb_LD_VTUNE) != 2);
                    HAL_GPIO_WritePin(synthesizer->led_port, synthesizer->led_n, 0);
                    end = DWT->CYCCNT;
                    summary = summary + end - start;
                }
            }
        }
    }
    synthesizer->time = summary * 1.0 / HAL_RCC_GetHCLKFreq();
}

void LMX2594_CONTROL_CHIP_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t chip_power) {
    LMX2594_WriteParameter(&synthesizer->lmx2594_hspi, &LMX2594_POWERDOWN, ~chip_power);
    synthesizer->chip_power = chip_power;
    if (chip_power) LMX2594_CONTROL_DIVIDERS_AND_CALIBRATION(synthesizer, synthesizer->ndn, synthesizer->ndnum, synthesizer->ndden, synthesizer->cd);
}

void LMX2594_CONTROL_CHIP_RESET(LMX2594_HandleTypeDef* synthesizer) {
    LMX2594_WriteRegister(&synthesizer->lmx2594_hspi, 0, 0x2412);
    LMX2594_WriteRegister(&synthesizer->lmx2594_hspi, 0, 0x2410);
}
