#ifndef __PRINTER_H__
#define __PRINTER_H__
#include <iostream>

namespace PRINTER {
	enum {
		len = 100
	};
}

class Printer {
private:
	char save_txt[100];

public:
	void SetString(const char * txt);
	void ShowString();
};
#endif