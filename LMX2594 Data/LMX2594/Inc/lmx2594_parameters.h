#ifndef LMX2594_PARAMETERS_H_
#define LMX2594_PARAMETERS_H_

#include <stm32f4xx_hal.h>

typedef union {
    struct {
        uint8_t regnumber : 7;
        uint8_t shift : 4;
        uint8_t width : 5;
    };
} paraminregdata_t;

typedef struct {
    paraminregdata_t data[3];
} paramdata_t;

extern const paramdata_t LMX2594_RAMP_EN;
extern const paramdata_t LMX2594_VCO_PHASE_SYNC;
extern const paramdata_t LMX2594_OUT_MUTE;
extern const paramdata_t LMX2594_FCAL_HPFD_ADJ;
extern const paramdata_t LMX2594_FCAL_LPFD_ADJ;
extern const paramdata_t LMX2594_FCAL_EN;
extern const paramdata_t LMX2594_MUXOUT_LD_SEL;
extern const paramdata_t LMX2594_RESET;
extern const paramdata_t LMX2594_POWERDOWN;
extern const paramdata_t LMX2594_CAL_CLK_DIV;
extern const paramdata_t LMX2594_OUT_FORCE;
extern const paramdata_t LMX2594_OSC_2X;
extern const paramdata_t LMX2594_MULT;
extern const paramdata_t LMX2594_PLL_R;
extern const paramdata_t LMX2594_PLL_R_PRE;
extern const paramdata_t LMX2594_CPG;
extern const paramdata_t LMX2594_ACAL_CMP_DELAY;
extern const paramdata_t LMX2594_VCO_DACISET_FORCE;
extern const paramdata_t LMX2594_VCO_CAPCTRL_FORCE;
extern const paramdata_t LMX2594_VCO_DACISET;
extern const paramdata_t LMX2594_VCO_DACISET_STRT;
extern const paramdata_t LMX2594_VCO_CAPCTRL;
extern const paramdata_t LMX2594_VCO_SEL;
extern const paramdata_t LMX2594_VCO_SEL_FORCE;
extern const paramdata_t LMX2594_PLL_N;
extern const paramdata_t LMX2594_MASH_SEED_EN;
extern const paramdata_t LMX2594_PFD_DLY_SEL;
extern const paramdata_t LMX2594_PLL_DEN;
extern const paramdata_t LMX2594_MASH_SEED;
extern const paramdata_t LMX2594_PLL_NUM;
extern const paramdata_t LMX2594_OUTA_PWR;
extern const paramdata_t LMX2594_OUTB_PD;
extern const paramdata_t LMX2594_OUTA_PD;
extern const paramdata_t LMX2594_MASH_RESET_N;
extern const paramdata_t LMX2594_MASH_ORDER;
extern const paramdata_t LMX2594_OUTA_MUX;
extern const paramdata_t LMX2594_OUT_ISET;
extern const paramdata_t LMX2594_OUTB_PWR;
extern const paramdata_t LMX2594_OUTB_MUX;
extern const paramdata_t LMX2594_INPIN_IGNORE;
extern const paramdata_t LMX2594_INPIN_HYST;
extern const paramdata_t LMX2594_INPIN_LVL;
extern const paramdata_t LMX2594_INPIN_FMT;
extern const paramdata_t LMX2594_LD_TYPE;
extern const paramdata_t LMX2594_LD_DLY;
extern const paramdata_t LMX2594_MASH_RST_COUNT;
extern const paramdata_t LMX2594_SYSREF_DIV_PRE;
extern const paramdata_t LMX2594_SYSREF_PULSE;
extern const paramdata_t LMX2594_SYSREF_EN;
extern const paramdata_t LMX2594_SYSREF_REPEAT;
extern const paramdata_t LMX2594_SYSREF_DIV;
extern const paramdata_t LMX2594_JESD_DAC1_CTRL;
extern const paramdata_t LMX2594_JESD_DAC2_CTRL;
extern const paramdata_t LMX2594_JESD_DAC3_CTRL;
extern const paramdata_t LMX2594_JESD_DAC4_CTRL;
extern const paramdata_t LMX2594_SYSREF_PULSE_CNT;
extern const paramdata_t LMX2594_SEG1_EN;
extern const paramdata_t LMX2594_CHDIV;
extern const paramdata_t LMX2594_RAMP_THRESH;
extern const paramdata_t LMX2594_QUICK_RECAL_EN;
extern const paramdata_t LMX2594_VCO_CAPCTRL_STRT;
extern const paramdata_t LMX2594_RAMP_LIMIT_HIGH;
extern const paramdata_t LMX2594_RAMP_LIMIT_LOW;
extern const paramdata_t LMX2594_RAMP_BURST_EN;
extern const paramdata_t LMX2594_RAMP_BURST_COUNT;
extern const paramdata_t LMX2594_RAMP0_RST;
extern const paramdata_t LMX2594_RAMP_TRIGA;
extern const paramdata_t LMX2594_RAMP_TRIGB;
extern const paramdata_t LMX2594_RAMP_BURST_TRIG;
extern const paramdata_t LMX2594_RAMP0_INC;
extern const paramdata_t LMX2594_RAMP0_DLY;
extern const paramdata_t LMX2594_RAMP0_LEN;
extern const paramdata_t LMX2594_RAMP1_DLY;
extern const paramdata_t LMX2594_RAMP1_RST;
extern const paramdata_t LMX2594_RAMP0_NEXT;
extern const paramdata_t LMX2594_RAMP0_NEXT_TRIG;
extern const paramdata_t LMX2594_RAMP1_INC;
extern const paramdata_t LMX2594_RAMP1_LEN;
extern const paramdata_t LMX2594_RAMP_DLY_CNT;
extern const paramdata_t LMX2594_RAMP_MANUAL;
extern const paramdata_t LMX2594_RAMP1_NEXT;
extern const paramdata_t LMX2594_RAMP1_NEXT_TRIG;
extern const paramdata_t LMX2594_RAMP_TRIG_CAL;
extern const paramdata_t LMX2594_RAMP_SCALE_COUNT;
extern const paramdata_t LMX2594_rb_LD_VTUNE;
extern const paramdata_t LMX2594_rb_VCO_SEL;
extern const paramdata_t LMX2594_rb_VCO_CAPCTRL;
extern const paramdata_t LMX2594_rb_VCO_DACISET;

#endif /* LMX2594_PARAMETERS_H_ */
