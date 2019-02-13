#include <iostream>
#include <cstring>

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	void info(int num) {
		using namespace std;
		switch (num) {
		case CLERK:
			cout << "CLERK" << endl;
			break;
		case SENIOR:
			cout << "SENIOR" << endl;
			break;
		case ASSIST:
			cout << "ASSIST" << endl;
			break;
		case MANAGER:
			cout << "MANAGER" << endl;
			break;

		}
	}
}

class NameCard {
private:
	char *name;
	char *company;
	char *phone;
	int position;

public:
	NameCard(const char *name_var, const char* company_var, const char* phone_var, const int position_var) : position(position_var) {
		name = new char[strlen(name_var) + 1];
		company = new char[strlen(company_var) + 1];
		phone = new char[strlen(phone_var) + 1];
		strcpy_s(name, strlen(name_var) + 1, name_var);
		strcpy_s(company, strlen(company_var) + 1, company_var);
		strcpy_s(phone, strlen(phone_var) + 1, phone_var);
	}

	NameCard(const NameCard &copy)
		: position(copy.position) {
		name = new char[strlen(copy.name) + 1];
		company = new char[strlen(copy.company) + 1];
		phone = new char[strlen(copy.phone) + 1];
		strcpy_s(name, strlen(copy.name) + 1, copy.name);
		strcpy_s(company, strlen(copy.company) + 1, copy.company);
		strcpy_s(phone, strlen(copy.phone) + 1, copy.phone);
	}

	void ShowNameCardInfo() {
		using namespace std;
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		COMP_POS::info(position);
		cout << endl;

	}


};

int q5_1_1(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-1111-2222", COMP_POS::SENIOR);
	NameCard copy2(manSENIOR);
	NameCard manASSIST("Kim", "SoGoodComp", "010-1111-2222", COMP_POS::ASSIST);
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	return 0;
}

int ch_5_cpp(void) {
	q5_1_1();


	return 0;
}