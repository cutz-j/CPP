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
		std::cout << "����ID: " << num << std::endl;
		std::cout << "�� ��: " << name << std::endl;
		std::cout << "�� ��: " << balance << std::endl;
	}

	~Account() {
		delete []name;
	}
};


Account * acc[100];
int bank_num = 0;

class AccountHandler {
private:
	Account * accArr[100];
	int accNum;
public:
	AccountHanlder();
	void showMenu(void) const;
	void make(void);
	void deposit();
	void withdraw();
	void info() const;
	~AccountHandler();

	void showMenu() const {
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
	}

	void make(void) {
		int id;
		char name[LEN];
		int balance;

		std::cout << "[���°���]" << std::endl;
		std::cout << "����ID: ";
		std::cin >> id;
		std::cout << "�� ��: ";
		std::cin >> name;
		std::cout << "�Աݾ�: ";
		std::cin >> balance;
		acc[bank_num] = new Account(id, balance, name);
		bank_num++;
		����ü �Է� �� �迭�� ���� //

	}

	void deposit(void) {
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

	void withdraw(void) {
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

	void info(void) const {
		for (int i = 0; i < bank_num; i++) {
			acc[i]->ShowAccInfo();
		}
	}

	~AccountHandler() {
		delete[]accArr;
	}
};

int main(void) {
	using namespace std;
	AccountHandler manager;
	while (1) {
		manager.showMenu();
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