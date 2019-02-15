#include <iostream>
#include <cstring>

#define LEN 20

namespace choice {
	enum {
		MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
	};
}

class Account {
private:
	int num;
	char * name;
	int balance;

public:
	Account(int n, int b, const char *cus) : num(n), balance(b) {
		name = new char[strlen(cus) + 1];
		strcpy_s(name, strlen(cus) + 1, cus);
	}

	Account(const Account &copy)
		: num(copy.num), balance(copy.balance) {
		name = new char[strlen(copy.name) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
	}

	int getNum(void) const {
		return num;
	}

	void deposit(int money) {
		balance += money;
	}

	int withdraw(int money) {
		if (balance < money)
			return 0;
		balance -= money;
		return money;
	}

	void ShowAccInfo() const {
		std::cout << "계좌ID: " << num << std::endl;
		std::cout << "이 름: " << name << std::endl;
		std::cout << "잔 액: " << balance << std::endl;
	}

	~Account() {
		delete []name;
	}
};


Account * acc[100];
int bank_num = 0;

void make(void) {
	int id;
	char name[LEN];
	int balance;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "이 름: ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> balance;
	acc[bank_num] = new Account(id, balance, name);
	bank_num++;
	// 구조체 입력 후 배열에 저장 //

}

void deposit(void) {
	int num, money;
	std::cout << "[입  금]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> num;
	std::cout << "입금액: ";
	std::cin >> money;
	for (int i = 0; i < bank_num; i++) {
		if (acc[i]->getNum() == num) {
			acc[i]->deposit(money);
		}
	}

	std::cout << "입금 완료" << std::endl;
}

void withdraw(void) {
	int num, money;
	std::cout << "[출  금]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> num;
	std::cout << "출금액: ";
	std::cin >> money;
	for (int i = 0; i < bank_num; i++) {
		if (acc[i]->getNum() == num) {
			acc[i]->withdraw(money);
		}
	}

	std::cout << "출금 완료" << std::endl;
}

void info(void) {
	for (int i = 0; i < bank_num; i++) {
		acc[i]->ShowAccInfo();
	}
}

int oop_3(void) {
	using namespace std;
	while (1) {
		cout << "1. 계좌개설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택: ";
		int num;
		cin >> num;
		switch (num) {
		case choice::MAKE:
			make();
			break;
		case choice::DEPOSIT:
			deposit();
			break;
		case choice::WITHDRAW:
			withdraw();
			break;
		case choice::INQUIRE:
			info();
			break;
		case choice::EXIT:
			cout << endl;
			cout << "exit" << endl;
			break;
		}
		if (num == choice::EXIT)
			break;
	}
	return 0;
}