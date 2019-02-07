#include <iostream>
#include <cstring>
#include "Printer.h"

void Printer::SetString(const char * txt) {
	strcpy_s(save_txt, txt);
}

void Printer::ShowString(void) {
	using namespace std;
	cout << save_txt << endl;
}