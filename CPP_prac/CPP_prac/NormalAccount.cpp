#include "NormalAccount.h"
#include "Exception.h"


NormalAccount::NormalAccount(int n, int b, Str cus, int i)
	: Account(n, b, cus), inter(i) {}

void NormalAccount::deposit(int money) {
	if (money < 0)
		throw MinusException(money);
	Account::deposit(money += (money * (inter / 100.0)));
}
