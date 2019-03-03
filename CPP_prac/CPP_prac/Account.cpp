#include "BankingCommonDecl.h"
#include "Account.h"
#include <iostream>

Account::Account(int n, int b, Str cus) : num(n), balance(b) {
	name = cus;
	//std::cout << name << std::endl;
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
	std::cout << "����ID: " << num << std::endl;
	std::cout << "�� ��: " << name << std::endl;
	std::cout << "�� ��: " << balance << std::endl;
}
