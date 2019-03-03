#ifndef __STR_H__
#define __STR_H__

#include "BankingCommonDecl.h"

class Str {
private:
	int len;
	char * str;

public:
	Str();
	Str(const char * st);
	Str(const Str& ref);
	~Str();
	Str& operator= (const Str& st);
	Str& operator+ (const Str& st);
	Str& operator+= (const Str& str);
	bool operator== (const Str& str1);

	friend std::ostream& operator<< (std::ostream& os, const Str& st);
	friend std::istream& operator>> (std::istream& is, const Str& st);

};





#endif