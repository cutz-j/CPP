#include <iostream>
#define LEN 20

typedef struct bank {
	int num;
	char name[LEN];
	int balance;
}Bank;

Bank bank[100];
int bank_num = 0;

void make(void) {
	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> bank[bank_num].num;
	std::cout << "�� ��: ";
	std::cin >> bank[bank_num].name;
	std::cout << "�Աݾ�: ";
	std::cin >> bank[bank_num].balance;
	::bank_num++;

	// ����ü �Է� �� �迭�� ���� //
	
}

void deposit(void) {
	int num, money;
	std::cout << "[��  ��]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> num;
	std::cout << "�Աݾ�: ";
	std::cin >> money;
	for (int i = 0; i < bank_num; i++) {
		if (bank[i].num == num) {
			bank[i].balance += money;
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
		if (bank[i].num == num) {
			bank[i].balance -= money;
		}
	}

	std::cout << "��� �Ϸ�" << std::endl;
}

void info(void) {
	for (int i = 0; i < bank_num; i++) {
		std::cout << "����ID: " << bank[i].num << std::endl;
		std::cout << "��  ��: " << bank[i].name << std::endl;
		std::cout << "��  ��: " << bank[i].balance << std::endl;
	}
}


int main(void) {
	using namespace std;
	while (1) {
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "����: ";
		int num;
		cin >> num;
		switch (num) {
		case 1:
			make();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			info();
			break;
		case 5:
			cout << endl;
			cout << "exit" << endl;
			break;
		}
		if (num == 5)
			break;
	}
	return 0;
}



