#include "lmx2594_parameters.h"

const paramdata_t LMX2594_RAMP_EN           = { .data[2].regnumber = 0,   .data[2].shift = 15, .data[2].width = 1,  };
const paramdata_t LMX2594_VCO_PHASE_SYNC    = { .data[2].regnumber = 0,   .data[2].shift = 14, .data[2].width = 1,  };
const paramdata_t LMX2594_OUT_MUTE          = { .data[2].regnumber = 0,   .data[2].shift = 9,  .data[2].width = 1,  };
const paramdata_t LMX2594_FCAL_HPFD_ADJ     = { .data[2].regnumber = 0,   .data[2].shift = 7,  .data[2].width = 2,  };
const paramdata_t LMX2594_FCAL_LPFD_ADJ     = { .data[2].regnumber = 0,   .data[2].shift = 5,  .data[2].width = 2,  };
const paramdata_t LMX2594_FCAL_EN           = { .data[2].regnumber = 0,   .data[2].shift = 3,  .data[2].width = 1,  };
const paramdata_t LMX2594_MUXOUT_LD_SEL     = { .data[2].regnumber = 0,   .data[2].shift = 2,  .data[2].width = 1,  };
const paramdata_t LMX2594_RESET             = { .data[2].regnumber = 0,   .data[2].shift = 1,  .data[2].width = 1,  };
const paramdata_t LMX2594_POWERDOWN         = { .data[2].regnumber = 0,   .data[2].shift = 0,  .data[2].width = 1,  };
const paramdata_t LMX2594_CAL_CLK_DIV       = { .data[2].regnumber = 1,   .data[2].shift = 0,  .data[2].width = 3,  };
const paramdata_t LMX2594_OUT_FORCE         = { .data[2].regnumber = 7,   .data[2].shift = 14, .data[2].width = 1,  };
const paramdata_t LMX2594_OSC_2X            = { .data[2].regnumber = 9,   .data[2].shift = 12, .data[2].width = 1,  };
const paramdata_t LMX2594_MULT              = { .data[2].regnumber = 10,  .data[2].shift = 7,  .data[2].width = 5,  };
const paramdata_t LMX2594_PLL_R             = { .data[2].regnumber = 11,  .data[2].shift = 4,  .data[2].width = 8,  };
const paramdata_t LMX2594_PLL_R_PRE         = { .data[2].regnumber = 12,  .data[2].shift = 0,  .data[2].width = 12, };
const paramdata_t LMX2594_CPG               = { .data[2].regnumber = 14,  .data[2].shift = 4,  .data[2].width = 3,  };
const paramdata_t LMX2594_ACAL_CMP_DELAY    = { .data[2].regnumber = 4,   .data[2].shift = 8,  .data[2].width = 8,  };
const paramdata_t LMX2594_VCO_DACISET_FORCE = { .data[2].regnumber = 8,   .data[2].shift = 14, .data[2].width = 1,  };
const paramdata_t LMX2594_VCO_CAPCTRL_FORCE = { .data[2].regnumber = 8,   .data[2].shift = 11, .data[2].width = 1,  };
const paramdata_t LMX2594_VCO_DACISET       = { .data[2].regnumber = 16,  .data[2].shift = 0,  .data[2].width = 9,  };
const paramdata_t LMX2594_VCO_DACISET_STRT  = { .data[2].regnumber = 17,  .data[2].shift = 0,  .data[2].width = 9,  };
const paramdata_t LMX2594_VCO_CAPCTRL       = { .data[2].regnumber = 19,  .data[2].shift = 0,  .data[2].width = 8,  };
const paramdata_t LMX2594_VCO_SEL           = { .data[2].regnumber = 20,  .data[2].shift = 11, .data[2].width = 3,  };
const paramdata_t LMX2594_VCO_SEL_FORCE     = { .data[2].regnumber = 20,  .data[2].shift = 10, .data[2].width = 1,  };
const paramdata_t LMX2594_PLL_N             = { .data[1].regnumber = 34,  .data[1].shift = 0,  .data[1].width = 3,
		                                        .data[2].regnumber = 36,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_MASH_SEED_EN      = { .data[2].regnumber = 37,  .data[2].shift = 15, .data[2].width = 1,  };
const paramdata_t LMX2594_PFD_DLY_SEL       = { .data[2].regnumber = 37,  .data[2].shift = 8,  .data[2].width = 6,  };
const paramdata_t LMX2594_PLL_DEN           = { .data[1].regnumber = 38,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 39,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_MASH_SEED         = { .data[1].regnumber = 40,  .data[1].shift = 0,  .data[1].width = 16,
	                                          	.data[2].regnumber = 41,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_PLL_NUM           = { .data[1].regnumber = 42,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 43,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_OUTA_PWR          = { .data[2].regnumber = 44,  .data[2].shift = 8,  .data[2].width = 6,  };
const paramdata_t LMX2594_OUTB_PD           = { .data[2].regnumber = 44,  .data[2].shift = 7,  .data[2].width = 1,  };
const paramdata_t LMX2594_OUTA_PD           = { .data[2].regnumber = 44,  .data[2].shift = 6,  .data[2].width = 1,  };
const paramdata_t LMX2594_MASH_RESET_N      = { .data[2].regnumber = 44,  .data[2].shift = 5,  .data[2].width = 1,  };
const paramdata_t LMX2594_MASH_ORDER        = { .data[2].regnumber = 44,  .data[2].shift = 0,  .data[2].width = 3,  };
const paramdata_t LMX2594_OUTA_MUX          = { .data[2].regnumber = 45,  .data[2].shift = 11, .data[2].width = 2,  };
const paramdata_t LMX2594_OUT_ISET          = { .data[2].regnumber = 45,  .data[2].shift = 9,  .data[2].width = 2,  };
const paramdata_t LMX2594_OUTB_PWR          = { .data[2].regnumber = 45,  .data[2].shift = 0,  .data[2].width = 6,  };
const paramdata_t LMX2594_OUTB_MUX          = { .data[2].regnumber = 46,  .data[2].shift = 0,  .data[2].width = 2,  };
const paramdata_t LMX2594_INPIN_IGNORE      = { .data[2].regnumber = 58,  .data[2].shift = 15, .data[2].width = 1,  };
const paramdata_t LMX2594_INPIN_HYST        = { .data[2].regnumber = 58,  .data[2].shift = 14, .data[2].width = 1,  };
const paramdata_t LMX2594_INPIN_LVL         = { .data[2].regnumber = 58,  .data[2].shift = 12, .data[2].width = 2,  };
const paramdata_t LMX2594_INPIN_FMT         = { .data[2].regnumber = 58,  .data[2].shift = 9,  .data[2].width = 3,  };
const paramdata_t LMX2594_LD_TYPE           = { .data[2].regnumber = 59,  .data[2].shift = 0,  .data[2].width = 1,  };
const paramdata_t LMX2594_LD_DLY            = { .data[2].regnumber = 60,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_MASH_RST_COUNT    = { .data[1].regnumber = 69,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 70,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_SYSREF_DIV_PRE    = { .data[2].regnumber = 71,  .data[2].shift = 5,  .data[2].width = 3,  };
const paramdata_t LMX2594_SYSREF_PULSE      = { .data[2].regnumber = 71,  .data[2].shift = 4,  .data[2].width = 1,  };
const paramdata_t LMX2594_SYSREF_EN         = { .data[2].regnumber = 71,  .data[2].shift = 3,  .data[2].width = 1,  };
const paramdata_t LMX2594_SYSREF_REPEAT     = { .data[2].regnumber = 71,  .data[2].shift = 2,  .data[2].width = 1,  };
const paramdata_t LMX2594_SYSREF_DIV        = { .data[2].regnumber = 72,  .data[2].shift = 0,  .data[2].width = 11, };
const paramdata_t LMX2594_JESD_DAC1_CTRL    = { .data[2].regnumber = 73,  .data[2].shift = 0,  .data[2].width = 6,  };
const paramdata_t LMX2594_JESD_DAC2_CTRL    = { .data[2].regnumber = 73,  .data[2].shift = 6,  .data[2].width = 6,  };
const paramdata_t LMX2594_JESD_DAC3_CTRL    = { .data[2].regnumber = 74,  .data[2].shift = 0,  .data[2].width = 6,  };
const paramdata_t LMX2594_JESD_DAC4_CTRL    = { .data[2].regnumber = 74,  .data[2].shift = 6,  .data[2].width = 6,  };
const paramdata_t LMX2594_SYSREF_PULSE_CNT  = { .data[2].regnumber = 74,  .data[2].shift = 12, .data[2].width = 4,  };
const paramdata_t LMX2594_SEG1_EN           = { .data[2].regnumber = 31,  .data[2].shift = 14, .data[2].width = 1,  };
const paramdata_t LMX2594_CHDIV             = { .data[2].regnumber = 75,  .data[2].shift = 6,  .data[2].width = 5,  };
const paramdata_t LMX2594_RAMP_THRESH       = { .data[0].regnumber = 78,  .data[0].shift = 11, .data[0].width = 1,
		                                        .data[1].regnumber = 79,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 80,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_QUICK_RECAL_EN    = { .data[2].regnumber = 78,  .data[2].shift = 9,  .data[2].width = 1,  };
const paramdata_t LMX2594_VCO_CAPCTRL_STRT  = { .data[2].regnumber = 78,  .data[2].shift = 1,  .data[2].width = 8,  };
const paramdata_t LMX2594_RAMP_LIMIT_HIGH   = { .data[0].regnumber = 81,  .data[0].shift = 0,  .data[0].width = 1,
		                                        .data[1].regnumber = 82,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 83,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP_LIMIT_LOW    = { .data[0].regnumber = 84,  .data[0].shift = 0,  .data[0].width = 1,
		                                        .data[1].regnumber = 85,  .data[1].shift = 0,  .data[1].width = 16,
		                                        .data[2].regnumber = 86,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP_BURST_EN     = { .data[2].regnumber = 96,  .data[2].shift = 15, .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP_BURST_COUNT  = { .data[2].regnumber = 96,  .data[2].shift = 2,  .data[2].width = 13, };
const paramdata_t LMX2594_RAMP0_RST         = { .data[2].regnumber = 97,  .data[2].shift = 15, .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP_TRIGA        = { .data[2].regnumber = 97,  .data[2].shift = 3,  .data[2].width = 4,  };
const paramdata_t LMX2594_RAMP_TRIGB        = { .data[2].regnumber = 97,  .data[2].shift = 7,  .data[2].width = 4,  };
const paramdata_t LMX2594_RAMP_BURST_TRIG   = { .data[2].regnumber = 97,  .data[2].shift = 0,  .data[2].width = 2,  };
const paramdata_t LMX2594_RAMP0_INC         = { .data[1].regnumber = 98,  .data[1].shift = 2,  .data[1].width = 14,
		                                        .data[2].regnumber = 99,  .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP0_DLY         = { .data[2].regnumber = 98,  .data[2].shift = 0,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP0_LEN         = { .data[2].regnumber = 100, .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP1_DLY         = { .data[2].regnumber = 101, .data[2].shift = 6,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP1_RST         = { .data[2].regnumber = 101, .data[2].shift = 5,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP0_NEXT        = { .data[2].regnumber = 101, .data[2].shift = 4,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP0_NEXT_TRIG   = { .data[2].regnumber = 101, .data[2].shift = 0,  .data[2].width = 2,  };
const paramdata_t LMX2594_RAMP1_INC         = { .data[1].regnumber = 102, .data[1].shift = 0,  .data[1].width = 14,
		                                        .data[2].regnumber = 103, .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP1_LEN         = { .data[2].regnumber = 104, .data[2].shift = 0,  .data[2].width = 16, };
const paramdata_t LMX2594_RAMP_DLY_CNT      = { .data[2].regnumber = 105, .data[2].shift = 6,  .data[2].width = 10, };
const paramdata_t LMX2594_RAMP_MANUAL       = { .data[2].regnumber = 105, .data[2].shift = 5,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP1_NEXT        = { .data[2].regnumber = 105, .data[2].shift = 4,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP1_NEXT_TRIG   = { .data[2].regnumber = 105, .data[2].shift = 0,  .data[2].width = 2,  };
const paramdata_t LMX2594_RAMP_TRIG_CAL     = { .data[2].regnumber = 106, .data[2].shift = 4,  .data[2].width = 1,  };
const paramdata_t LMX2594_RAMP_SCALE_COUNT  = { .data[2].regnumber = 106, .data[2].shift = 0,  .data[2].width = 3,  };
const paramdata_t LMX2594_rb_LD_VTUNE       = { .data[2].regnumber = 110, .data[2].shift = 9,  .data[2].width = 2,  };
const paramdata_t LMX2594_rb_VCO_SEL        = { .data[2].regnumber = 110, .data[2].shift = 5,  .data[2].width = 3,  };
const paramdata_t LMX2594_rb_VCO_CAPCTRL    = { .data[2].regnumber = 111, .data[2].shift = 0,  .data[2].width = 8,  };
const paramdata_t LMX2594_rb_VCO_DACISET    = { .data[2].regnumber = 112, .data[2].shift = 0,  .data[2].width = 9,  };
