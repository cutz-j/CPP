#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "Str.h"

class CreditAccount : public NormalAccount {
private:
	int level;

public:
	CreditAccount(int n, int b, Str cus, int i, int l);

	virtual void deposit(int money);
};

#endif