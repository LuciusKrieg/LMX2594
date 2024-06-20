#ifndef COM_H
#define COM_H

#include <Windows.h>
#include <stdint.h>

HANDLE COM_Init(LPCTSTR sPortName, int BaudRate);

void     COM_WriteDigit (HANDLE hSerial, uint64_t writingdata);
void     COM_WriteDouble(HANDLE hSerial, double   writingdata);

uint64_t COM_ReadDigit  (HANDLE hSerial                      );
double   COM_ReadDouble (HANDLE hSerial                      );

#endif // COM_H
