#include "params.h"

map<string, uint16_t> ParamsMap{
    {"HMC835_chip_ID", ParamInfo(24, 0, 0x00)},
    {"HMC835_Read_Address", ParamInfo(5, 0, 0x00)},
    {"HMC835_Soft_Reset", ParamInfo(1, 5, 0x00)},
    {"HMC835_Chip_Enable_Pin_Select", ParamInfo(1, 0, 0x01)},
    {"HMC835_SPI_Chip_Enable", ParamInfo(1, 1, 0x01)},
    {"HMC835_Keep_Bias_On", ParamInfo(1, 2, 0x01)},
    {"HMC835_Keep_PFD_Pn", ParamInfo(1, 3, 0x01)},
    {"HMC835_Keep_CP_On", ParamInfo(1, 4, 0x01)},
    {"HMC835_Keep_Reference_Buffer_ON", ParamInfo(1, 5, 0x01)},
    {"HMC835_Keep_VCO_Buffer_ON", ParamInfo(1, 6, 0x01)},
    {"HMC835_Keep_GPO_Driver_ON", ParamInfo(1, 7, 0x01)},
    {"HMC835_rdiv", ParamInfo(14, 0, 0x02)},
    {"HMC835_Integer_Setting", ParamInfo(19, 0, 0x03)},
    {"HMC835_Fractional_Setting", ParamInfo(24, 0, 0x04)},
    {"HMC835_DSM_Order", ParamInfo(2, 2, 0x06)},
    {"HMC835_Synchronous_SPI_Mode", ParamInfo(1, 4, 0x06)},
    {"HMC835_Exact_Frequency_Mode_Enable", ParamInfo(1, 5, 0x06)},
    {"HMC835_Fractional_Bypass", ParamInfo(1, 7, 0x06)},
    {"HMC835_Autoseed_EN", ParamInfo(1, 8, 0x06)},
    {"HMC835_Delta_Sigma_Modulator_Enable", ParamInfo(1, 11, 0x06)},
    {"HMC835_lkd_wincnt_max", ParamInfo(3, 0, 0x07)},
    {"HMC835_LD_Timer_Divide_Setting", ParamInfo(3, 5, 0x07)},
    {"HMC835_LD_Timer_Speed", ParamInfo(2, 8, 0x07)},
    {"HMC835_LD_Enable", ParamInfo(1, 11, 0x07)},
    {"HMC835_LD_Mode", ParamInfo(1, 14, 0x07)},
    {"HMC835_CSP_Enable", ParamInfo(1, 15, 0x07)},
    {"HMC835_Lock_Detect_Training", ParamInfo(9, 20, 0x07)},
    {"HMC835_LD_SDO_Driver_Enable", ParamInfo(1, 5, 0x08)},
    {"HMC835_VCO_Buffer_and_Prescaler_Bias_Enable", ParamInfo(1, 10, 0x08)},
    {"HMC835_High_Frequency_Reference", ParamInfo(1, 21, 0x08)},
    {"HMC835_SDO_Output_Level", ParamInfo(1, 22, 0x08)},
    {"HMC835_CP_DN_Gain", ParamInfo(7, 0, 0x09)},
    {"HMC835_CP_UP_Gain", ParamInfo(7, 7, 0x09)},
    {"HMC835_Offset_Magnitude", ParamInfo(7, 14, 0x09)},
    {"HMC835_Offset_UP_enable", ParamInfo(1, 21, 0x09)},
    {"HMC835_Offset_DN_enable", ParamInfo(1, 22, 0x09)},
    {"HMC835_HiK_charge_pump_Mode", ParamInfo(1, 23, 0x09)},
    {"HMC835_Vtune_Resolution", ParamInfo(3, 0, 0x0A)},
    {"HMC835_AutoCal_Disable", ParamInfo(1, 11, 0x0A)},
    {"HMC835_FSM_VSPI_Clock_Select", ParamInfo(2, 13, 0x0A)},
    {"HMC835_PD_Phase_Select", ParamInfo(1, 4, 0x0B)},
    {"HMC835_PD_Up_Output_Enable", ParamInfo(1, 5, 0x0B)},
    {"HMC835_PD_Down_Output_Enable", ParamInfo(1, 6, 0x0B)},
    {"HMC835_Force_CP_UP", ParamInfo(1, 9, 0x0B)},
    {"HMC835_Force_CP_DN", ParamInfo(1, 10, 0x0B)},
    {"HMC835_Force_CP_Mid_Rail", ParamInfo(1, 11, 0x0B)},
    {"HMC835_Number_of_Channels_per_Fpd", ParamInfo(24, 0, 0x0C)},
    {"HMC835_GPO", ParamInfo(5, 0, 0x0F)},
    {"HMC835_GPO_Test_Data", ParamInfo(1, 5, 0x0F)},
    {"HMC835_Prevent_Automux_SDO", ParamInfo(1, 6, 0x0F)},
    {"HMC835_Prevent_Auto_tri_state_SDO", ParamInfo(1, 7, 0x0F)},
    {"HMC835_VCO_Tune_Curve", ParamInfo(8, 0, 0x10)},
    {"HMC835_VCO_Tuning_Busy", ParamInfo(1, 8, 0x10)},
    {"HMC835_SAR_Error_Magnitude_Count", ParamInfo(19, 0, 0x11)},
    {"HMC835_SAR_Error_Sign", ParamInfo(1, 19, 0x11)},
    {"HMC835_GPO_Out", ParamInfo(1, 0, 0x12)},
    {"HMC835_Lock_Detect_Out", ParamInfo(1, 1, 0x12)},
    {"HMC835_Aux_SPI_Mode", ParamInfo(1, 0, 0x14)},
    {"HMC835_Aux_GPO_Values", ParamInfo(3, 1, 0x14)},
    {"HMC835_Aux_GPO_3_3_V", ParamInfo(1, 4, 0x14)},
    {"HMC835_Phase_Sync", ParamInfo(1, 9, 0x14)},
    {"HMC835_Aux_SPI_GPO_Output", ParamInfo(2, 10, 0x14)},
    {"HMC835_Aux_SPI_Outputs", ParamInfo(2, 12, 0x14)},
    {"HMC835_Vtune_Preset_Enable", ParamInfo(1, 0, 0x15)},
    {"HMC835_Capacitor_Switch_Setting", ParamInfo(5, 1, 0x15)},
    {"HMC835_Manual_VCO_Selection", ParamInfo(3, 6, 0x15)},
    {"HMC835_Manual_VCO_Tune_Enable", ParamInfo(1, 9, 0x15)},
    {"HMC835_Enable_Auto_Scale_CP_current", ParamInfo(1, 16, 0x15)},
    {"HMC835_RF_Divide_Ratio", ParamInfo(6, 0, 0x16)},
    {"HMC835_LO_Output_Buffer_Gain_Control", ParamInfo(2, 6, 0x16)},
    {"HMC835_LO2_Output_Buffer_gain_Control", ParamInfo(2, 8, 0x16)},
    {"HMC835_Divider_Output_Stage_Gain_Control", ParamInfo(1, 10, 0x16)},
    {"HMC835_VCO_SubSys_Master_Enable", ParamInfo(1, 0, 0x17)},
    {"HMC835_VCO_Enable", ParamInfo(1, 1, 0x17)},
    {"HMC835_External_VCO_Buffer_Enable", ParamInfo(1, 2, 0x17)},
    {"HMC835_PLL_Buffer_Enable", ParamInfo(1, 3, 0x17)},
    {"HMC835_LO1_Output_Buffer_Enable", ParamInfo(1, 4, 0x17)},
    {"HMC835_LO2_Output_Buffer_Enable", ParamInfo(1, 5, 0x17)},
    {"HMC835_External_Input_Enable", ParamInfo(1, 6, 0x17)},
    {"HMC835_Pre_Lock_Mute_Enable", ParamInfo(1, 7, 0x17)},
    {"HMC835_LO1_Output_Single_Ended_Enable", ParamInfo(1, 8, 0x17)},
    {"HMC835_LO2_Output_Single_Ended_Enable", ParamInfo(1, 9, 0x17)},
    {"HMC835_Charge_Pump_Output_Select", ParamInfo(1, 11, 0x17)},
    {"HMC835_External_Input_Buffer_Bias", ParamInfo(2, 19, 0x18)},
    {"HMC835_Delta_Sigma_Modulator_Seed", ParamInfo(24, 0, 0x1A)},
};

void GetParamsList() {
    cout << "HMC835_chip_ID\n";
    cout << "HMC835_Read_Address\n";
    cout << "HMC835_Soft_Reset\n";
    cout << "HMC835_Chip_Enable_Pin_Select\n";
    cout << "HMC835_SPI_Chip_Enable\n";
    cout << "HMC835_Keep_Bias_On\n";
    cout << "HMC835_Keep_PFD_Pn\n";
    cout << "HMC835_Keep_CP_On\n";
    cout << "HMC835_Keep_Reference_Buffer_ON\n";
    cout << "HMC835_Keep_VCO_Buffer_ON\n";
    cout << "HMC835_Keep_GPO_Driver_ON\n";
    cout << "HMC835_rdiv\n";
    cout << "HMC835_Integer_Setting\n";
    cout << "HMC835_Fractional_Setting\n";
    cout << "HMC835_DSM_Order\n";
    cout << "HMC835_Synchronous_SPI_Mode\n";
    cout << "HMC835_Exact_Frequency_Mode_Enable\n";
    cout << "HMC835_Fractional_Bypass\n";
    cout << "HMC835_Autoseed_EN\n";
    cout << "HMC835_Delta_Sigma_Modulator_Enable\n";
    cout << "HMC835_lkd_wincnt_max\n";
    cout << "HMC835_LD_Timer_Divide_Setting\n";
    cout << "HMC835_LD_Timer_Speed\n";
    cout << "HMC835_LD_Enable\n";
    cout << "HMC835_LD_Mode\n";
    cout << "HMC835_CSP_Enable\n";
    cout << "HMC835_Lock_Detect_Training\n";
    cout << "HMC835_LD_SDO_Driver_Enable\n";
    cout << "HMC835_VCO_Buffer_and_Prescaler_Bias_Enable\n";
    cout << "HMC835_High_Frequency_Reference\n";
    cout << "HMC835_SDO_Output_Level\n";
    cout << "HMC835_CP_DN_Gain\n";
    cout << "HMC835_CP_UP_Gain\n";
    cout << "HMC835_Offset_Magnitude\n";
    cout << "HMC835_Offset_UP_enable\n";
    cout << "HMC835_Offset_DN_enable\n";
    cout << "HMC835_HiK_charge_pump_Mode\n";
    cout << "HMC835_Vtune_Resolution\n";
    cout << "HMC835_AutoCal_Disable\n";
    cout << "HMC835_FSM_VSPI_Clock_Select\n";
    cout << "HMC835_PD_Phase_Select\n";
    cout << "HMC835_PD_Up_Output_Enable\n";
    cout << "HMC835_PD_Down_Output_Enable\n";
    cout << "HMC835_Force_CP_UP\n";
    cout << "HMC835_Force_CP_DN\n";
    cout << "HMC835_Force_CP_Mid_Rail\n";
    cout << "HMC835_Number_of_Channels_per_Fpd\n";
    cout << "HMC835_GPO\n";
    cout << "HMC835_GPO_Test_Data\n";
    cout << "HMC835_Prevent_Automux_SDO\n";
    cout << "HMC835_Prevent_Auto_tri_state_SDO\n";
    cout << "HMC835_VCO_Tune_Curve\n";
    cout << "HMC835_VCO_Tuning_Busy\n";
    cout << "HMC835_SAR_Error_Magnitude_Count\n";
    cout << "HMC835_SAR_Error_Sign\n";
    cout << "HMC835_GPO_Out\n";
    cout << "HMC835_Lock_Detect_Out\n";
    cout << "HMC835_Aux_SPI_Mode\n";
    cout << "HMC835_Aux_GPO_Values\n";
    cout << "HMC835_Aux_GPO_3_3_V\n";
    cout << "HMC835_Phase_Sync\n";
    cout << "HMC835_Aux_SPI_GPO_Output\n";
    cout << "HMC835_Aux_SPI_Outputs\n";
    cout << "HMC835_Vtune_Preset_Enable\n";
    cout << "HMC835_Capacitor_Switch_Setting\n";
    cout << "HMC835_Manual_VCO_Selection\n";
    cout << "HMC835_Manual_VCO_Tune_Enable\n";
    cout << "HMC835_Enable_Auto_Scale_CP_current\n";
    cout << "HMC835_RF_Divide_Ratio\n";
    cout << "HMC835_LO_Output_Buffer_Gain_Control\n";
    cout << "HMC835_LO2_Output_Buffer_gain_Control\n";
    cout << "HMC835_Divider_Output_Stage_Gain_Control\n";
    cout << "HMC835_VCO_SubSys_Master_Enable\n";
    cout << "HMC835_VCO_Enable\n";
    cout << "HMC835_External_VCO_Buffer_Enable\n";
    cout << "HMC835_PLL_Buffer_Enable\n";
    cout << "HMC835_LO1_Output_Buffer_Enable\n";
    cout << "HMC835_LO2_Output_Buffer_Enable\n";
    cout << "HMC835_External_Input_Enable\n";
    cout << "HMC835_Pre_Lock_Mute_Enable\n";
    cout << "HMC835_LO1_Output_Single_Ended_Enable\n";
    cout << "HMC835_LO2_Output_Single_Ended_Enable\n";
    cout << "HMC835_Charge_Pump_Output_Select\n";
    cout << "HMC835_External_Input_Buffer_Bias\n";
    cout << "HMC835_Delta_Sigma_Modulator_Seed\n";
    cout << "\n";
}