#include "menu.h"

extern map<string, uint16_t> ParamsMap;

void V1(HANDLE hSerial, string name, uint8_t bytescount) {
	string s;
	uint8_t n1;
	uint16_t n2;
	uint32_t n4;

	cout << "enter " << name << ": ";
	getline(cin, s);
	switch (bytescount) {
	case 0: n4 = stof(s) * 1000000; COM_WriteDigit(hSerial, n4, 4); break;
	case 1: n1 = stoi(s); COM_WriteDigit(hSerial, n1, 1); break;
	case 2: n2 = stoi(s); COM_WriteDigit(hSerial, n2, 2); break;
	case 4: n4 = stoi(s); COM_WriteDigit(hSerial, n4, 4); break;
	}
	cout << name << " got.\n";
}

void MainMenu(HANDLE hSerial) {	
	string s;
	uint8_t operationsNumbers;
	uint8_t onWork = 1;

	while (onWork) {
		cout << "Operations' numbers:\n";
		cout << "   0 - Show params list\n";
		cout << "   1 - LO1 set ampl\n";
		cout << "   2 - LO2 set ampl\n";
		cout << "   3 - LO set ampl\n";
		cout << "   4 - LO set freq\n";
		cout << "   5 - LO1 set state\n";
		cout << "   6 - LO2 set state\n";
		cout << "   7 - Write parameter\n";
		cout << "   8 - Read parameter\n";
		cout << "   9 - Soft Reset\n";
		cout << "   10 - Close\n";
		cout << "Enter Operation's number: ";
		getline(cin, s);
		cout << "\n";

		operationsNumbers = stoi(s);
		COM_WriteDigit(hSerial, operationsNumbers, 1);

		switch (operationsNumbers) {
			case 0:
				GetParamsList();
				break;
			case 1:
				V1(hSerial, "LO1 ampl (0..3)", 1);
				break;
			case 2:
				V1(hSerial, "LO2 ampl (0..3)", 1);
				break;
			case 3:
				V1(hSerial, "LO ampl (0..3)", 1);
				break;
			case 4: 
				V1(hSerial, "LO freq rdiv (1..16383)", 2);
				V1(hSerial, "LO freq FSMVSPIclockselect (0..3)", 1);
				V1(hSerial, "LO freq setting (any)", 0);
				break;
			case 5:
				V1(hSerial, "LO1 state (0/1)", 1);
				break;
			case 6:
				V1(hSerial, "LO2 state (0/1)", 1);
				break;
			case 7:
				cout << "enter parameter name: ";
				getline(cin, s);
				COM_WriteDigit(hSerial, (uint16_t)ParamsMap[s], 2);
				cout << "enter parameter value: ";
				getline(cin, s);
				COM_WriteDigit(hSerial, (uint32_t)stoi(s), 4);
				break;
			case 8:
				cout << "enter parameter name: ";
				getline(cin, s);
				COM_WriteDigit(hSerial, (uint16_t)ParamsMap[s], 2);
				cout << COM_ReadDigit(hSerial, 4) << "\n";
				break;
			case 9:
				break;
			case 10:
				onWork = 0;
				break;
		}

		COM_ReadDigit(hSerial, 1);
		cout << "done.\n\n";
	}
}