#include "Account.h"
#include <iostream>
#include <cstring>


Account::Account(int n, int b, const char *cus) : num(n), balance(b) {
	name = new char[strlen(cus) + 1];
	strcpy_s(name, strlen(cus) + 1, cus);
}

Account::Account(const Account &ref)
	: num(ref.num), balance(ref.balance) {
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
}

Account& Account::operator=(const Account& ref) {
	num = ref.num;
	balance = ref.balance;

	delete[]name;
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
	return *this;
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

Account::~Account() {
	delete[]name;
}
