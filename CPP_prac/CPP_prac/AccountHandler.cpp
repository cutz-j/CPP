#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Str.h"


void AccountHandler::showMenu(void) const {
	using namespace std;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}

void AccountHandler::make_choice(void) {
	int num;
	std::cout << "[계좌종류선택]" << std::endl;
	std::cout << "선택: ";
	std::cin >> num;
	std::cout << std::endl;
	switch (num) {
	case 1:
		normal_make();
		break;
	case 2:
		credit_make();
		break;
	}
}

void AccountHandler::normal_make(void) {
	int id;
	Str name;
	int balance;
	int interest;

	std::cout << "[보통예금계좌 개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "이 름: ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> balance;
	std::cout << "이자율: ";
	std::cin >> interest;
	acc[bank_num] = new NormalAccount(id, balance, name, interest);
	bank_num++;
}

void AccountHandler::credit_make(void) {
	int id;
	Str name;
	int balance;
	int interest;
	int level;

	std::cout << "[신용신뢰계좌 개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> id;
	std::cout << "이 름: ";
	std::cin >> name;
	std::cout << "입금액: ";
	std::cin >> balance;
	std::cout << "이자율: ";
	std::cin >> interest;
	std::cout << "신용등급(1toA, 2toB, 3toC): ";
	std::cin >> level;
	switch (level) {
	case 1:
		acc[bank_num++] = new CreditAccount(id, balance, name, interest, choice::A);
		break;
	case 2:
		acc[bank_num++] = new CreditAccount(id, balance, name, interest, choice::B);
		break;
	case 3:
		acc[bank_num++] = new CreditAccount(id, balance, name, interest, choice::C);
		break;
	}

}

void AccountHandler::deposit_h(void) {
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

void AccountHandler::withdraw_h(void) {
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

void AccountHandler::info(void) const {
	for (int i = 0; i < bank_num; i++) {
		acc[i]->ShowAccInfo();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < bank_num; i++)
		delete acc[i];
}