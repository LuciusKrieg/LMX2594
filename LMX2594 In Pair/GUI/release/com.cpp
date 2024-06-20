#include <com.h>

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
