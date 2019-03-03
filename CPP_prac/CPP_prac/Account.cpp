#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int n, int b, Str cus) : num(n), balance(b) {
	name = cus;
}

int Account::getNum(void) const {
	return num;
}

void Account::deposit(int money) {
	balance += money;
}

int Account::withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {
	std::cout << "°èÁÂID: " << num << std::endl;
	std::cout << "ÀÌ ¸§: " << name << std::endl;
	std::cout << "ÀÜ ¾×: " << balance << std::endl;
}
