/*
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

HANDLE COM_Init(LPCTSTR sPortName, int BaudRate) {
    HANDLE hSerial = CreateFile(sPortName, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    DCB dcbSerialParams;
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    GetCommState(hSerial, &dcbSerialParams);
    dcbSerialParams.BaudRate = BaudRate;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = TWOSTOPBITS;
    dcbSerialParams.Parity = NOPARITY;
    SetCommState(hSerial, &dcbSerialParams);
    return hSerial;
}

void     COM_WriteDigit(HANDLE hSerial, uint64_t writingdata) {
    uint8_t* bytePointer = (uint8_t*)&writingdata;
    for (uint8_t i = 0; i < 8; i++) {
        WriteFile(hSerial, &bytePointer[i], 1, NULL, NULL);
    }
}
void     COM_WriteDouble(HANDLE hSerial, double   writingdata) {
    uint8_t* bytePointer = (uint8_t*)&writingdata;
    for (uint8_t i = 0; i < 8; i++) {
        WriteFile(hSerial, &bytePointer[i], 1, NULL, NULL);
    }
}

uint64_t COM_ReadDigit(HANDLE hSerial) {
    uint64_t readingdata = 0;
    uint8_t* bytePointer = (uint8_t*)&readingdata;
    for (uint8_t i = 0; i < 8; i++) {
        ReadFile(hSerial, &bytePointer[i], 1, NULL, NULL);
    }
    return readingdata;
}
double   COM_ReadDouble(HANDLE hSerial) {
    double readingdata = 0;
    uint8_t* bytePointer = (uint8_t*)&readingdata;
    for (uint8_t i = 0; i < 8; i++) {
        ReadFile(hSerial, &bytePointer[i], 1, NULL, NULL);
    }
    return readingdata;
}


void main() {
    /*
    HANDLE hSerial = COM_Init(L"COM3", 9600);
    COM_WriteDigit(hSerial, 5);
    FILE* f = fopen("D://GAMMA//LMX2594//LMX2594 In Pair//GUI//params.txt", "w+");
    fprintf(f, "5 = %ull\n", COM_ReadDigit(hSerial));
    COM_WriteDigit(hSerial, 0);
    //COM_WriteDouble(hSerial, 123456789);
    fprintf(f, "Fosc1    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "NDN1    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "NDNUM1    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "NDDEN1    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "Fvco1    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "CD1    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "Fout1    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "Fosc2    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "NDN2    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "Fvco2    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "CD2    = %ull\n", COM_ReadDigit(hSerial));
    fprintf(f, "Fout2    = %f\n", COM_ReadDouble(hSerial));
    fprintf(f, "time    = %f\n", COM_ReadDouble(hSerial));
    fclose(f);
    COM_ReadDigit(hSerial);
    CloseHandle(hSerial);
    */

    /*
    double fout_b = 123456789;
    double fosc_a = 100000000;
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
    uint16_t cd_a = 96;
    double fvco_a = fout_a * cd_a;
    double nd_a = fvco_a / fosc_a;
    uint32_t ndn_a = floor(nd_a);
    uint32_t ndden_a = 0xFFFFFFFF;
    uint32_t ndnum_a = (nd_a - ndn_a) * ndden_a;

    printf("fosc_a  = %f\n", fosc_a);
    printf("ndn_a   = %u\n", ndn_a);
    printf("ndnum_a = %u\n", ndnum_a);
    printf("ndden_a = %u\n", ndden_a);
    printf("fvco_a  = %f\n", fvco_a);
    printf("cd_a    = %u\n", cd_a);
    printf("fout_a  = %f\n", fout_a);
    printf("fosc_b  = %f\n", fosc_b);
    printf("ndn_b   = %u\n", ndn_b);
    printf("fvco_b  = %f\n", fvco_b);
    printf("cd_b    = %u\n", cd_b);
    printf("fout_b  = %f\n", fout_b);
    printf("time    = %f\n", 0);


    uint8_t reg_n = 1;
    uint8_t a0 = (reg_n & 0x7F) | 0x80;
    uint8_t a1 = 0;
    uint8_t a2 = 0;

    uint8_t a[3] = (uint8_t*)((reg_n & 0x7F) | 0x80);

    uint8_t a[3] = { a0, a1, a2 };
    uint32_t b = a2 << 16 | a1 << 8 | a0 << 0;
    uint8_t c[3] = { ((uint8_t*)&b)[0], ((uint8_t*)&b)[1], ((uint8_t*)&b)[2] };
}
*/

