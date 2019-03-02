#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Str.h"


void AccountHandler::showMenu(void) const {
	using namespace std;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}

void AccountHandler::make_choice(void) {
	int num;
	std::cout << "[������������]" << std::endl;
	std::cout << "����: ";
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

	std::cout << "[���뿹�ݰ��� ����]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> id;
	std::cout << "�� ��: ";
	std::cin >> name;
	std::cout << "�Աݾ�: ";
	std::cin >> balance;
	std::cout << "������: ";
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

	std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> id;
	std::cout << "�� ��: ";
	std::cin >> name;
	std::cout << "�Աݾ�: ";
	std::cin >> balance;
	std::cout << "������: ";
	std::cin >> interest;
	std::cout << "�ſ���(1toA, 2toB, 3toC): ";
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
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> num;
	std::cout << "�Աݾ�: ";
	std::cin >> money;
	for (int i = 0; i < bank_num; i++) {
		if (acc[i]->getNum() == num) {
			acc[i]->deposit(money);
		}
	}

	std::cout << "�Ա� �Ϸ�" << std::endl;
}

void AccountHandler::withdraw_h(void) {
	int num, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> num;
	std::cout << "��ݾ�: ";
	std::cin >> money;
	for (int i = 0; i < bank_num; i++) {
		if (acc[i]->getNum() == num) {
			acc[i]->withdraw(money);
		}
	}

	std::cout << "��� �Ϸ�" << std::endl;
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