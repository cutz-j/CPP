#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "Exception.h"



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
	while (true) {
		std::cout << "�Աݾ�: ";
		std::cin >> money;
		try {
			for (int i = 0; i < bank_num; i++) {
				if (acc[i]->getNum() == num) {
					acc[i]->deposit(money);
					return;
				}
			std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
			return;
			}
		}
		catch (MinusException& exc) {
			std::cout << "���Է�" << std::endl;
		}
	}

	std::cout << "�Ա� �Ϸ�" << std::endl;
}

void AccountHandler::withdraw_h(void) {
	int num, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> num;
	while (true) {
		std::cout << "��ݾ�: ";
		std::cin >> money;
		try {
			for (int i = 0; i < bank_num; i++) {
				if (acc[i]->getNum() == num) {
					acc[i]->withdraw(money);
					return;
				}
			}
			std::cout << "��ȿ���� ���� ID�Դϴ�." << std::endl << std::endl;
			return;
		}
		catch (OverException& exp) {
			std::cout << "���Է�" << std::endl;
		}
	}

	std::cout << "��� �Ϸ�" << std::endl;
}

void AccountHandler::info(void) const {
	for (int i = 0; i < bank_num; i++) {
		acc[i]->ShowAccInfo();
	}
}