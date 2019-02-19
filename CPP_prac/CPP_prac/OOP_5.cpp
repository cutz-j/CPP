//#include <iostream>
//#include <cstring>
//
//const int LEN = 20;
//
//namespace choice {
//	enum {
//		MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
//	};
//}
//
//class Account {
//private:
//	int num;
//	char * name;
//	int balance;
//
//public:
//	Account(int n, int b, const char *cus) : num(n), balance(b) {
//		name = new char[strlen(cus) + 1];
//		strcpy_s(name, strlen(cus) + 1, cus);
//	}
//
//	Account(const Account &ref)
//		: num(ref.num), balance(ref.balance) {
//		name = new char[strlen(ref.name) + 1];
//		strcpy_s(name, strlen(ref.name) + 1, ref.name);
//	}
//
//	int getNum(void) const {
//		return num;
//	}
//
//	void deposit(int money) {
//		balance += money;
//	}
//
//	int withdraw(int money) {
//		if (balance < money)
//			return 0;
//		balance -= money;
//		return money;
//	}
//
//	void ShowAccInfo() const {
//		std::cout << "����ID: " << num << std::endl;
//		std::cout << "�� ��: " << name << std::endl;
//		std::cout << "�� ��: " << balance << std::endl;
//	}
//
//	~Account() {
//		delete[]name;
//	}
//};
//
//class AccountHandler {
//private:
//	Account * acc[100];
//	int bank_num = 0;
//public:
//	void showMenu(void) const {
//		using namespace std;
//		cout << "1. ���°���" << endl;
//		cout << "2. �� ��" << endl;
//		cout << "3. �� ��" << endl;
//		cout << "4. �������� ��ü ���" << endl;
//		cout << "5. ���α׷� ����" << endl;
//		cout << "����: ";
//	}
//
//	void make(void) {
//		int id;
//		char name[LEN];
//		int balance;
//
//		std::cout << "[���°���]" << std::endl;
//		std::cout << "����ID: ";
//		std::cin >> id;
//		std::cout << "�� ��: ";
//		std::cin >> name;
//		std::cout << "�Աݾ�: ";
//		std::cin >> balance;
//		acc[bank_num] = new Account(id, balance, name);
//		bank_num++;
//	}
//
//	void deposit_h(void) {
//		int num, money;
//		std::cout << "[��  ��]" << std::endl;
//		std::cout << "����ID: ";
//		std::cin >> num;
//		std::cout << "�Աݾ�: ";
//		std::cin >> money;
//		for (int i = 0; i < bank_num; i++) {
//			if (acc[i]->getNum() == num) {
//				acc[i]->deposit(money);
//			}
//		}
//
//		std::cout << "�Ա� �Ϸ�" << std::endl;
//	}
//
//	void withdraw_h(void) {
//		int num, money;
//		std::cout << "[��  ��]" << std::endl;
//		std::cout << "����ID: ";
//		std::cin >> num;
//		std::cout << "��ݾ�: ";
//		std::cin >> money;
//		for (int i = 0; i < bank_num; i++) {
//			if (acc[i]->getNum() == num) {
//				acc[i]->withdraw(money);
//			}
//		}
//
//		std::cout << "��� �Ϸ�" << std::endl;
//	}
//
//	void info(void) const {
//		for (int i = 0; i < bank_num; i++) {
//			acc[i]->ShowAccInfo();
//		}
//	}
//
//};
//
//int oop_5(void) {
//	using namespace std;
//	AccountHandler manager;
//	int num;
//	while (1) {
//		manager.showMenu();
//		
//		cin >> num;
//		switch (num) {
//		case choice::MAKE:
//			manager.make();
//			break;
//		case choice::DEPOSIT:
//			manager.deposit_h();
//			break;
//		case choice::WITHDRAW:
//			manager.withdraw_h();
//			break;
//		case choice::INQUIRE:
//			manager.info();
//			break;
//		case choice::EXIT:
//			cout << endl;
//			cout << "exit" << endl;
//			break;
//		}
//		if (num == choice::EXIT)
//			break;
//	}
//	return 0;
//}