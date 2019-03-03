#include "AccountHandler.h"
#include "BankingCommonDecl.h"


int main(void) {
	using namespace std;
	AccountHandler manager;
	int num;
	while (1) {
		manager.showMenu();

		cin >> num;
		switch (num) {
		case choice::MAKE:
			manager.make_choice();
			break;
		case choice::DEPOSIT:
			manager.deposit_h();
			break;
		case choice::WITHDRAW:
			manager.withdraw_h();
			break;
		case choice::INQUIRE:
			manager.info();
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