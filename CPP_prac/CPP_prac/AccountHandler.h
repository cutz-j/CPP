#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
private:
	BoundCheckAcc acc;
	int bank_num = 0;

public:
	void showMenu(void) const;

	void make_choice(void);

	void normal_make(void);

	void credit_make(void);

	void deposit_h(void);

	void withdraw_h(void);

	void info(void) const;

	~AccountHandler();
};


#endif