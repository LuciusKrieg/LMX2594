#include "lmx2594_synthesizer_control.h"

void LMX2594_CONTROL_CHIP_RESET(LMX2594_HandleTypeDef* synthesizer) {
	LMX2594_WriteRegister(synthesizer->lmx2594_hspi, 0, 0x2412);
	LMX2594_WriteRegister(synthesizer->lmx2594_hspi, 0, 0x2410);
	synthesizer->ndmode    = 0;
	synthesizer->ndcorrect = 0;
	synthesizer->Fosc      = -1;
	synthesizer->NDN       = -1;
	synthesizer->NDNUM     = -1;
	synthesizer->NDDEN     = -1;
	synthesizer->Fvco      = -1;
	synthesizer->CD        = -1;
	synthesizer->Fout      = -1;
}
void LMX2594_CONTROL_CHIP_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_POWERDOWN, ~power);
	synthesizer->power = power;
}

void LMX2594_CONTROL_OUTA_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTA_PD, ~power);
}
void LMX2594_CONTROL_OUTB_POWER(LMX2594_HandleTypeDef* synthesizer, uint8_t power) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTB_PD, ~power);
}

void LMX2594_CONTROL_OUTA_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t level) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTA_PWR, level);
}
void LMX2594_CONTROL_OUTB_LEVEL(LMX2594_HandleTypeDef* synthesizer, uint8_t level) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTB_PWR, level);
}

void LMX2594_CONTROL_OUTA_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t mux) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTA_MUX, mux);
}
void LMX2594_CONTROL_OUTB_MUX(LMX2594_HandleTypeDef* synthesizer, uint8_t mux) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_OUTB_MUX, mux);
}

void LMX2594_CONTROL_ND_MODE(LMX2594_HandleTypeDef* synthesizer, uint8_t ndmode) {
	LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_MASH_ORDER, ndmode);
	synthesizer->ndmode = ndmode;
}

void LMX2594_CONTROL_CPG_VALUE(LMX2594_HandleTypeDef* synthesizer, uint8_t cpgvalue) {
	int8_t cpgvalues[8] = { 0, 6, -1, 12, 3, 9, -1, 15 };
	int8_t cpgnumber = -1;
	for (uint8_t i = 0; i < 8; i++) if (cpgvalue == cpgvalues[i]) cpgnumber = i;
	if (cpgnumber != -1) LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_CPG, cpgnumber);
}

void LMX2594_CONTROL_ND_VALUE(LMX2594_HandleTypeDef* synthesizer, uint32_t ndnvalue, uint32_t ndnumvalue, uint32_t nddenvalue) {
	if ((ndnumvalue < nddenvalue) & (ndnvalue + ndnumvalue * 1.0 / nddenvalue <= 524287)) {
		double Fvco = synthesizer->Fosc * (ndnvalue + ndnumvalue * 1.0 / nddenvalue);
		uint8_t minndvalue;
		uint8_t pfddlysel;
		switch (synthesizer->ndmode) {
			case 0: if (Fvco <= 12500000000) { minndvalue = 28; pfddlysel = 1; }
				                        else { minndvalue = 32; pfddlysel = 2; } break;
			case 1: if (Fvco <= 10000000000) { minndvalue = 28; pfddlysel = 1; }
			   else if (Fvco  > 12500000000) { minndvalue = 36; pfddlysel = 3; }
				                        else { minndvalue = 32; pfddlysel = 2; } break;
			case 2: if (Fvco <= 10000000000) { minndvalue = 32; pfddlysel = 2; }
				                        else { minndvalue = 36; pfddlysel = 3; } break;
			case 3: if (Fvco <= 10000000000) { minndvalue = 36; pfddlysel = 3; }
				                        else { minndvalue = 40; pfddlysel = 4; } break;
			case 4: if (Fvco <= 10000000000) { minndvalue = 44; pfddlysel = 5; }
				                        else { minndvalue = 48; pfddlysel = 6; } break;
		}
		if (ndnvalue + ndnumvalue * 1.0 / nddenvalue >= minndvalue) {
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_PFD_DLY_SEL, pfddlysel);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_PLL_N, ndnvalue);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_PLL_DEN, nddenvalue);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_PLL_NUM, ndnumvalue);
			synthesizer->NDN = ndnvalue;
			synthesizer->NDDEN = nddenvalue;
			synthesizer->NDNUM = ndnumvalue;
			synthesizer->Fvco = Fvco;
			synthesizer->ndcorrect = 1;
		} else {
			synthesizer->ndcorrect = 0;
		}
	}
}

void LMX2594_CONTROL_VCO_RECAL(LMX2594_HandleTypeDef* synthesizer) {
	if ((synthesizer->power) & (synthesizer->ndcorrect)) {
		HAL_GPIO_WritePin(synthesizer->led_port, synthesizer->led_n, 1);

		uint16_t VCO_CORE;
		uint64_t fCoreMin;
		uint64_t fCoreMax;
		uint16_t CCoreMin;
		uint16_t CCoreMax;
		uint16_t ACoreMin;
		uint16_t ACoreMax;
		uint16_t VCO_CAPCTRL_STRT;
		uint16_t VCO_DACISET_STRT;
		
		if ((synthesizer->Fvco >= 11900000000) & (synthesizer->Fvco <= 12100000000)) {
			VCO_CORE = 4;
			VCO_CAPCTRL_STRT = 1;
			VCO_DACISET_STRT = 300;
		} else {		
				   if (synthesizer->Fvco <= 8600000000) {
				VCO_CORE = 1; fCoreMin = 7500000000 ; fCoreMax = 8600000000 ; CCoreMin = 164; CCoreMax = 12; ACoreMin = 299; ACoreMax = 240;
			} else if (synthesizer->Fvco <= 9800000000) {
				VCO_CORE = 2; fCoreMin = 8600000000 ; fCoreMax = 9800000000 ; CCoreMin = 165; CCoreMax = 16; ACoreMin = 356; ACoreMax = 247;
			} else if (synthesizer->Fvco <= 10800000000) {
				VCO_CORE = 3; fCoreMin = 9800000000 ; fCoreMax = 10800000000; CCoreMin = 158; CCoreMax = 19; ACoreMin = 324; ACoreMax = 224;
			} else if (synthesizer->Fvco <= 12000000000) {
				VCO_CORE = 4; fCoreMin = 10800000000; fCoreMax = 12000000000; CCoreMin = 140; CCoreMax = 0 ; ACoreMin = 383; ACoreMax = 244;
			} else if (synthesizer->Fvco <= 12900000000) {
				VCO_CORE = 5; fCoreMin = 12000000000; fCoreMax = 12900000000; CCoreMin = 183; CCoreMax = 36; ACoreMin = 205; ACoreMax = 146;
			} else if (synthesizer->Fvco <= 13900000000) {
				VCO_CORE = 6; fCoreMin = 12900000000; fCoreMax = 13900000000; CCoreMin = 155; CCoreMax = 6 ; ACoreMin = 242; ACoreMax = 163;
			} else if (synthesizer->Fvco <= 15000000000) {
				VCO_CORE = 7; fCoreMin = 13900000000; fCoreMax = 15000000000; CCoreMin = 175; CCoreMax = 19; ACoreMin = 323; ACoreMax = 244;
			}
			VCO_CAPCTRL_STRT = round(CCoreMin - (CCoreMin - CCoreMax) * (synthesizer->Fvco - fCoreMin) / (fCoreMax - fCoreMin));
			VCO_DACISET_STRT = round(ACoreMin + (ACoreMax - ACoreMin) * (synthesizer->Fvco - fCoreMin) / (fCoreMax - fCoreMin));
		}
		
		LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_VCO_SEL         , VCO_CORE        );
		LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_VCO_CAPCTRL_STRT, VCO_CAPCTRL_STRT);
		LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_VCO_DACISET_STRT, VCO_DACISET_STRT);

		LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_FCAL_EN, 1);
		while(LMX2594_ReadParameter(synthesizer->lmx2594_hspi, &LMX2594_rb_LD_VTUNE) != 2);

		HAL_GPIO_WritePin(synthesizer->led_port, synthesizer->led_n, 0);
	}
}

void LMX2594_CONTROL_CD_VALUE(LMX2594_HandleTypeDef* synthesizer, uint16_t cdvalue) {
	if (cdvalue == 1) {
		LMX2594_CONTROL_OUTA_MUX(synthesizer, LMX2594_OUT_MUX_VCO);
		LMX2594_CONTROL_OUTB_MUX(synthesizer, LMX2594_OUT_MUX_VCO);
		LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_SEG1_EN, 0);
		synthesizer->CD = cdvalue;
		synthesizer->Fout = synthesizer->Fvco / synthesizer->CD;
	}
	else {
		uint16_t cdvalues[18] = { 2, 4, 6, 8, 12, 16, 24, 32, 48, 64, 72, 96, 128, 192, 256, 384, 512, 768 };
		int8_t cdnumber = -1;
		for (uint8_t i = 0; i < 18; i++) if (cdvalue == cdvalues[i]) cdnumber = i;
		if (cdnumber == 0) {
			LMX2594_CONTROL_OUTA_MUX(synthesizer, LMX2594_OUT_MUX_ChannelDivider);
			LMX2594_CONTROL_OUTB_MUX(synthesizer, LMX2594_OUT_MUX_ChannelDivider);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_SEG1_EN, 0);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_CHDIV, cdnumber);
			synthesizer->CD = cdvalue;
			synthesizer->Fout = synthesizer->Fvco / synthesizer->CD;
		}
		else if (cdnumber == 1 || cdnumber == 2 || (cdnumber >= 3) & (synthesizer->Fvco <= 11500000000)) {
			LMX2594_CONTROL_OUTA_MUX(synthesizer, LMX2594_OUT_MUX_ChannelDivider);
			LMX2594_CONTROL_OUTB_MUX(synthesizer, LMX2594_OUT_MUX_ChannelDivider);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_SEG1_EN, 1);
			LMX2594_WriteParameter(synthesizer->lmx2594_hspi, &LMX2594_CHDIV, cdnumber);
			synthesizer->CD = cdvalue;
			synthesizer->Fout = synthesizer->Fvco / synthesizer->CD;
		}
	}
}
