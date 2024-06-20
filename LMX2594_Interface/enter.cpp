#include "enter.h"

int main() {
    cout << "enter com port name: ";
    string s;
    getline(cin, s);
    wstring path_wstr(s.begin(), s.end());
    cout << "\n";
    MainMenu(COM_Init(path_wstr.c_str(), 9600));
	return 0;
}