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
	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> bank[bank_num].num;
	std::cout << "이 름: ";
	std::cin >> bank[bank_num].name;
	std::cout << "입금액: ";
	std::cin >> bank[bank_num].balance;
	::bank_num++;

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
		if (bank[i].num == num) {
			bank[i].balance += money;
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
		if (bank[i].num == num) {
			bank[i].balance -= money;
		}
	}

	std::cout << "출금 완료" << std::endl;
}

void info(void) {
	for (int i = 0; i < bank_num; i++) {
		std::cout << "계좌ID: " << bank[i].num << std::endl;
		std::cout << "이  름: " << bank[i].name << std::endl;
		std::cout << "잔  액: " << bank[i].balance << std::endl;
	}
}


int main(void) {
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



