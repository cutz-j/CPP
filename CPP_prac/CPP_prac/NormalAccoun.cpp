#include "NormalAccount.h"


NormalAccount::NormalAccount(int n, int b, Str cus, int i)
	: Account(n, b, cus), inter(i) {}

void NormalAccount::deposit(int money) {
	Account::deposit(money += (money * (inter / 100.0)));
}
