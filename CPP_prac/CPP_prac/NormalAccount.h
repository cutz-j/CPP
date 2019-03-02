#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"
#include "Str.h"

class NormalAccount : public Account {
private:
	int inter;

public:
	NormalAccount(int n, int b, Str cus, int i)
		: Account(n, b, cus), inter(i) {}

	virtual void deposit(int money) {
		Account::deposit(money += (money * (inter / 100.0)));
	}
};


#endif