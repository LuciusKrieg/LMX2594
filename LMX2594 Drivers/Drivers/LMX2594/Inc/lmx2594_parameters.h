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

extern paramdata_t LMX2594_RAMP_EN;
extern paramdata_t LMX2594_VCO_PHASE_SYNC;
extern paramdata_t LMX2594_OUT_MUTE;
extern paramdata_t LMX2594_FCAL_HPFD_ADJ;
extern paramdata_t LMX2594_FCAL_LPFD_ADJ;
extern paramdata_t LMX2594_FCAL_EN;
extern paramdata_t LMX2594_MUXOUT_LD_SEL;
extern paramdata_t LMX2594_RESET;
extern paramdata_t LMX2594_POWERDOWN;
extern paramdata_t LMX2594_CAL_CLK_DIV;
extern paramdata_t LMX2594_OUT_FORCE;
extern paramdata_t LMX2594_OSC_2X;
extern paramdata_t LMX2594_MULT;
extern paramdata_t LMX2594_PLL_R;
extern paramdata_t LMX2594_PLL_R_PRE;
extern paramdata_t LMX2594_CPG;
extern paramdata_t LMX2594_ACAL_CMP_DELAY;
extern paramdata_t LMX2594_VCO_DACISET_FORCE;
extern paramdata_t LMX2594_VCO_CAPCTRL_FORCE;
extern paramdata_t LMX2594_VCO_DACISET;
extern paramdata_t LMX2594_VCO_DACISET_STRT;
extern paramdata_t LMX2594_VCO_CAPCTRL;
extern paramdata_t LMX2594_VCO_SEL;
extern paramdata_t LMX2594_VCO_SEL_FORCE;
extern paramdata_t LMX2594_PLL_N;
extern paramdata_t LMX2594_MASH_SEED_EN;
extern paramdata_t LMX2594_PFD_DLY_SEL;
extern paramdata_t LMX2594_PLL_DEN;
extern paramdata_t LMX2594_MASH_SEED;
extern paramdata_t LMX2594_PLL_NUM;
extern paramdata_t LMX2594_OUTA_PWR;
extern paramdata_t LMX2594_OUTB_PD;
extern paramdata_t LMX2594_OUTA_PD;
extern paramdata_t LMX2594_MASH_RESET_N;
extern paramdata_t LMX2594_MASH_ORDER;
extern paramdata_t LMX2594_OUTA_MUX;
extern paramdata_t LMX2594_OUT_ISET;
extern paramdata_t LMX2594_OUTB_PWR;
extern paramdata_t LMX2594_OUTB_MUX;
extern paramdata_t LMX2594_INPIN_IGNORE;
extern paramdata_t LMX2594_INPIN_HYST;
extern paramdata_t LMX2594_INPIN_LVL;
extern paramdata_t LMX2594_INPIN_FMT;
extern paramdata_t LMX2594_LD_TYPE;
extern paramdata_t LMX2594_LD_DLY;
extern paramdata_t LMX2594_MASH_RST_COUNT;
extern paramdata_t LMX2594_SYSREF_DIV_PRE;
extern paramdata_t LMX2594_SYSREF_PULSE;
extern paramdata_t LMX2594_SYSREF_EN;
extern paramdata_t LMX2594_SYSREF_REPEAT;
extern paramdata_t LMX2594_SYSREF_DIV;
extern paramdata_t LMX2594_JESD_DAC1_CTRL;
extern paramdata_t LMX2594_JESD_DAC2_CTRL;
extern paramdata_t LMX2594_JESD_DAC3_CTRL;
extern paramdata_t LMX2594_JESD_DAC4_CTRL;
extern paramdata_t LMX2594_SYSREF_PULSE_CNT;
extern paramdata_t LMX2594_SEG1_EN;
extern paramdata_t LMX2594_CHDIV;
extern paramdata_t LMX2594_RAMP_THRESH;
extern paramdata_t LMX2594_QUICK_RECAL_EN;
extern paramdata_t LMX2594_VCO_CAPCTRL_STRT;
extern paramdata_t LMX2594_RAMP_LIMIT_HIGH;
extern paramdata_t LMX2594_RAMP_LIMIT_LOW;
extern paramdata_t LMX2594_RAMP_BURST_EN;
extern paramdata_t LMX2594_RAMP_BURST_COUNT;
extern paramdata_t LMX2594_RAMP0_RST;
extern paramdata_t LMX2594_RAMP_TRIGA;
extern paramdata_t LMX2594_RAMP_TRIGB;
extern paramdata_t LMX2594_RAMP_BURST_TRIG;
extern paramdata_t LMX2594_RAMP0_INC;
extern paramdata_t LMX2594_RAMP0_DLY;
extern paramdata_t LMX2594_RAMP0_LEN;
extern paramdata_t LMX2594_RAMP1_DLY;
extern paramdata_t LMX2594_RAMP1_RST;
extern paramdata_t LMX2594_RAMP0_NEXT;
extern paramdata_t LMX2594_RAMP0_NEXT_TRIG;
extern paramdata_t LMX2594_RAMP1_INC;
extern paramdata_t LMX2594_RAMP1_LEN;
extern paramdata_t LMX2594_RAMP_DLY_CNT;
extern paramdata_t LMX2594_RAMP_MANUAL;
extern paramdata_t LMX2594_RAMP1_NEXT;
extern paramdata_t LMX2594_RAMP1_NEXT_TRIG;
extern paramdata_t LMX2594_RAMP_TRIG_CAL;
extern paramdata_t LMX2594_RAMP_SCALE_COUNT;
extern paramdata_t LMX2594_rb_LD_VTUNE;
extern paramdata_t LMX2594_rb_VCO_SEL;
extern paramdata_t LMX2594_rb_VCO_CAPCTRL;
extern paramdata_t LMX2594_rb_VCO_DACISET;

#endif /* LMX2594_PARAMETERS_H_ */
