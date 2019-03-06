#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "Str.h"
#include "Exception.h"

class NormalAccount : public Account {
private:
	int inter;

public:
	NormalAccount(int n, int b, Str cus, int i);

	virtual void deposit(int money);
};

#endif