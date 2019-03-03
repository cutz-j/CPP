#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "Str.h"

class Account {
private:
	int num;
	Str name;
	int balance;

public:
	Account(int n, int b, Str cus);

	int getNum(void) const;

	virtual void deposit(int money);

	int withdraw(int money);

	void ShowAccInfo() const;
};

#endif